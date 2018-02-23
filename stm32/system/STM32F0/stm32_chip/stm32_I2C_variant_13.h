
const stm32_af_pin_list_type chip_af_i2c_scl [] = {
//I2C1
    { I2C1  , GPIOA, GPIO_PIN_9  , GPIO_AF4_I2C1  }, 
    { I2C1  , GPIOA, GPIO_PIN_11 , GPIO_AF5_I2C1  }, 
    { I2C1  , GPIOB, GPIO_PIN_8  , GPIO_AF1_I2C1  }, 
    { I2C1  , GPIOF, GPIO_PIN_1  , GPIO_AF1_I2C1  }, 
}; 

const stm32_af_pin_list_type chip_af_i2c_sda [] = {
//I2C1
    { I2C1  , GPIOA, GPIO_PIN_10 , GPIO_AF4_I2C1  }, 
    { I2C1  , GPIOF, GPIO_PIN_0  , GPIO_AF1_I2C1  }, 
}; 
