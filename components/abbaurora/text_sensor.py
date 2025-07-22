import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor
from esphome.const import CONF_ID

# DEPENDENCIES = ['abbaurora']

abbaurora_ns = cg.esphome_ns.namespace('abbaurora')
ABBAuroraTextSensor = abbaurora_ns.class_('ABBAuroraTextSensor', text_sensor.TextSensor, cg.PollingComponent)

CONF_VERSION = "version"
CONF_INVERTER_STATE = "inverter_state"
CONF_GLOBAL_STATE = "global_state"
CONF_CHANNEL1_STATE = "channel1_state"
CONF_CHANNEL2_STATE = "channel2_state"
CONF_ALARM = "alarm"

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(ABBAuroraTextSensor),
    cv.Optional(CONF_VERSION): text_sensor.text_sensor_schema(),
    cv.Optional(CONF_INVERTER_STATE): text_sensor.text_sensor_schema(),
    cv.Optional(CONF_GLOBAL_STATE): text_sensor.text_sensor_schema(),
    cv.Optional(CONF_CHANNEL1_STATE): text_sensor.text_sensor_schema(),
    cv.Optional(CONF_CHANNEL2_STATE): text_sensor.text_sensor_schema(),
    cv.Optional(CONF_ALARM): text_sensor.text_sensor_schema(),
}).extend(cv.polling_component_schema('120s'))

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    
    if CONF_VERSION in config:
        sens = await text_sensor.new_text_sensor(config[CONF_VERSION])
        cg.add(var.set_version_sensor(sens))
    
    if CONF_INVERTER_STATE in config:
        sens = await text_sensor.new_text_sensor(config[CONF_INVERTER_STATE])
        cg.add(var.set_inverter_state_sensor(sens))
    
    if CONF_GLOBAL_STATE in config:
        sens = await text_sensor.new_text_sensor(config[CONF_GLOBAL_STATE])
        cg.add(var.set_global_state_sensor(sens))
    
    if CONF_CHANNEL1_STATE in config:
        sens = await text_sensor.new_text_sensor(config[CONF_CHANNEL1_STATE])
        cg.add(var.set_channel1_state_sensor(sens))
    
    if CONF_CHANNEL2_STATE in config:
        sens = await text_sensor.new_text_sensor(config[CONF_CHANNEL2_STATE])
        cg.add(var.set_channel2_state_sensor(sens))
    
    if CONF_ALARM in config:
        sens = await text_sensor.new_text_sensor(config[CONF_ALARM])
        cg.add(var.set_alarm_sensor(sens))