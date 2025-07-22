import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import (
    CONF_ID,
    DEVICE_CLASS_POWER,
    DEVICE_CLASS_VOLTAGE,
    DEVICE_CLASS_CURRENT,
    DEVICE_CLASS_FREQUENCY,
    DEVICE_CLASS_TEMPERATURE,
    DEVICE_CLASS_ENERGY,
    STATE_CLASS_MEASUREMENT,
    STATE_CLASS_TOTAL_INCREASING,
    UNIT_WATT,
    UNIT_VOLT,
    UNIT_AMPERE,
    UNIT_HERTZ,
    UNIT_CELSIUS,
    UNIT_KILOWATT_HOURS,
)

# DEPENDENCIES = ['abbaurora']

abbaurora_ns = cg.esphome_ns.namespace('abbaurora')
ABBAuroraSensor = abbaurora_ns.class_('ABBAuroraSensor', sensor.Sensor, cg.PollingComponent)

CONF_POWER = "power"
CONF_VOLTAGE = "voltage"
CONF_CURRENT = "current"
CONF_FREQUENCY = "frequency"
CONF_RISO = "riso"
CONF_ILEAK = "ileak"
CONF_POWER_PEAK = "power_peak"
CONF_POWER_PEAK_TODAY = "power_peak_today"
CONF_TEMP_INVERTER = "temp_inverter"
CONF_TEMP_BOOSTER = "temp_booster"
CONF_POWER_1 = "power_1"
CONF_POWER_2 = "power_2"
CONF_VOLTAGE_1 = "voltage_1"
CONF_VOLTAGE_2 = "voltage_2"
CONF_CURRENT_1 = "current_1"
CONF_CURRENT_2 = "current_2"
CONF_ENERGY_DAILY = "energy_daily"
CONF_ENERGY_TOTAL = "energy_total"

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(ABBAuroraSensor),
    cv.Optional(CONF_POWER): sensor.sensor_schema(
        unit_of_measurement=UNIT_WATT,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_POWER,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_VOLTAGE): sensor.sensor_schema(
        unit_of_measurement=UNIT_VOLT,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_VOLTAGE,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_CURRENT): sensor.sensor_schema(
        unit_of_measurement=UNIT_AMPERE,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_CURRENT,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_FREQUENCY): sensor.sensor_schema(
        unit_of_measurement=UNIT_HERTZ,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_FREQUENCY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_RISO): sensor.sensor_schema(
        accuracy_decimals=2,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_ILEAK): sensor.sensor_schema(
        unit_of_measurement=UNIT_AMPERE,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_CURRENT,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_POWER_PEAK): sensor.sensor_schema(
        unit_of_measurement=UNIT_WATT,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_POWER,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_POWER_PEAK_TODAY): sensor.sensor_schema(
        unit_of_measurement=UNIT_WATT,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_POWER,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_TEMP_INVERTER): sensor.sensor_schema(
        unit_of_measurement=UNIT_CELSIUS,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_TEMPERATURE,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_TEMP_BOOSTER): sensor.sensor_schema(
        unit_of_measurement=UNIT_CELSIUS,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_TEMPERATURE,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_POWER_1): sensor.sensor_schema(
        unit_of_measurement=UNIT_WATT,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_POWER,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_POWER_2): sensor.sensor_schema(
        unit_of_measurement=UNIT_WATT,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_POWER,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_VOLTAGE_1): sensor.sensor_schema(
        unit_of_measurement=UNIT_VOLT,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_VOLTAGE,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_VOLTAGE_2): sensor.sensor_schema(
        unit_of_measurement=UNIT_VOLT,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_VOLTAGE,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_CURRENT_1): sensor.sensor_schema(
        unit_of_measurement=UNIT_AMPERE,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_CURRENT,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_CURRENT_2): sensor.sensor_schema(
        unit_of_measurement=UNIT_AMPERE,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_CURRENT,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_ENERGY_DAILY): sensor.sensor_schema(
        unit_of_measurement=UNIT_KILOWATT_HOURS,
        accuracy_decimals=3,
        device_class=DEVICE_CLASS_ENERGY,
        state_class=STATE_CLASS_TOTAL_INCREASING,
    ),
    cv.Optional(CONF_ENERGY_TOTAL): sensor.sensor_schema(
        unit_of_measurement=UNIT_KILOWATT_HOURS,
        accuracy_decimals=2,
        device_class=DEVICE_CLASS_ENERGY,
        state_class=STATE_CLASS_TOTAL_INCREASING,
    ),
}).extend(cv.polling_component_schema('60s'))

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    
    if CONF_POWER in config:
        sens = await sensor.new_sensor(config[CONF_POWER])
        cg.add(var.set_power_sensor(sens))
    
    if CONF_VOLTAGE in config:
        sens = await sensor.new_sensor(config[CONF_VOLTAGE])
        cg.add(var.set_voltage_sensor(sens))
    
    if CONF_CURRENT in config:
        sens = await sensor.new_sensor(config[CONF_CURRENT])
        cg.add(var.set_current_sensor(sens))
    
    if CONF_FREQUENCY in config:
        sens = await sensor.new_sensor(config[CONF_FREQUENCY])
        cg.add(var.set_frequency_sensor(sens))
    
    if CONF_RISO in config:
        sens = await sensor.new_sensor(config[CONF_RISO])
        cg.add(var.set_riso_sensor(sens))
    
    if CONF_ILEAK in config:
        sens = await sensor.new_sensor(config[CONF_ILEAK])
        cg.add(var.set_ileak_sensor(sens))
    
    if CONF_POWER_PEAK in config:
        sens = await sensor.new_sensor(config[CONF_POWER_PEAK])
        cg.add(var.set_power_peak_sensor(sens))
    
    if CONF_POWER_PEAK_TODAY in config:
        sens = await sensor.new_sensor(config[CONF_POWER_PEAK_TODAY])
        cg.add(var.set_power_peak_today_sensor(sens))
    
    if CONF_TEMP_INVERTER in config:
        sens = await sensor.new_sensor(config[CONF_TEMP_INVERTER])
        cg.add(var.set_temp_inverter_sensor(sens))
    
    if CONF_TEMP_BOOSTER in config:
        sens = await sensor.new_sensor(config[CONF_TEMP_BOOSTER])
        cg.add(var.set_temp_booster_sensor(sens))
    
    if CONF_POWER_1 in config:
        sens = await sensor.new_sensor(config[CONF_POWER_1])
        cg.add(var.set_power_1_sensor(sens))
    
    if CONF_POWER_2 in config:
        sens = await sensor.new_sensor(config[CONF_POWER_2])
        cg.add(var.set_power_2_sensor(sens))
    
    if CONF_VOLTAGE_1 in config:
        sens = await sensor.new_sensor(config[CONF_VOLTAGE_1])
        cg.add(var.set_voltage_1_sensor(sens))
    
    if CONF_VOLTAGE_2 in config:
        sens = await sensor.new_sensor(config[CONF_VOLTAGE_2])
        cg.add(var.set_voltage_2_sensor(sens))
    
    if CONF_CURRENT_1 in config:
        sens = await sensor.new_sensor(config[CONF_CURRENT_1])
        cg.add(var.set_current_1_sensor(sens))
    
    if CONF_CURRENT_2 in config:
        sens = await sensor.new_sensor(config[CONF_CURRENT_2])
        cg.add(var.set_current_2_sensor(sens))
    
    if CONF_ENERGY_DAILY in config:
        sens = await sensor.new_sensor(config[CONF_ENERGY_DAILY])
        cg.add(var.set_energy_daily_sensor(sens))
    
    if CONF_ENERGY_TOTAL in config:
        sens = await sensor.new_sensor(config[CONF_ENERGY_TOTAL])
        cg.add(var.set_energy_total_sensor(sens))