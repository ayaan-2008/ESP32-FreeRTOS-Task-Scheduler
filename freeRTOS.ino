#include <Arduino.h>

QueueHandle_t sensorQueue;

// Simulated Sensor Task
void SensorTask(void *pvParameters)
{
    int sensorValue = 0;

    while (true)
    {
        sensorValue = random(20, 41); // Simulated temperature

        xQueueSend(sensorQueue, &sensorValue, portMAX_DELAY);

        Serial.println("[Sensor Task] New Temperature Generated");

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

// Processing Task
void ProcessingTask(void *pvParameters)
{
    int receivedValue;

    while (true)
    {
        if (xQueueReceive(sensorQueue, &receivedValue, portMAX_DELAY))
        {
            Serial.print("[Processing Task] Temperature Received: ");
            Serial.println(receivedValue);

            if (receivedValue > 35)
            {
                Serial.println("[Processing Task] ALERT: High Temperature!");
            }
        }
    }
}

// Heartbeat Task
void HeartbeatTask(void *pvParameters)
{
    while (true)
    {
        Serial.println("[Heartbeat Task] System Running");

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

// Statistics Task
void StatsTask(void *pvParameters)
{
    while (true)
    {
        Serial.println("========== RTOS STATUS ==========");
        Serial.print("Free Heap: ");
        Serial.println(ESP.getFreeHeap());
        Serial.println("=================================");

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

void setup()
{
    Serial.begin(115200);

    delay(1000);

    Serial.println("ESP32 FreeRTOS Simulation Starting...");

    sensorQueue = xQueueCreate(10, sizeof(int));

    xTaskCreate(
        SensorTask,
        "SensorTask",
        2048,
        NULL,
        2,
        NULL);

    xTaskCreate(
        ProcessingTask,
        "ProcessingTask",
        2048,
        NULL,
        3,
        NULL);

    xTaskCreate(
        HeartbeatTask,
        "HeartbeatTask",
        2048,
        NULL,
        1,
        NULL);

    xTaskCreate(
        StatsTask,
        "StatsTask",
        4096,
        NULL,
        1,
        NULL);

    Serial.println("All Tasks Created Successfully");
}

void loop()
{
    // Empty because FreeRTOS tasks do all the work
}
