void
cy_as_mcu_interrupt_handler(cy_as_device *dev_p)
{
uint16_t v;
v = cy_as_hal_read_register(dev_p->tag, CY_AS_MEM_P0_MCU_STAT);
v = v;
}
void
cy_as_power_management_interrupt_handler(cy_as_device *dev_p)
{
uint16_t v;
v = cy_as_hal_read_register(dev_p->tag, CY_AS_MEM_PWR_MAGT_STAT);
v = v;
}
void
cy_as_pll_lock_loss_interrupt_handler(cy_as_device *dev_p)
{
uint16_t v;
v = cy_as_hal_read_register(dev_p->tag, CY_AS_MEM_PLL_LOCK_LOSS_STAT);
v = v;
}
uint32_t cy_as_intr_start(cy_as_device *dev_p, cy_bool dmaintr)
{
uint16_t v;
cy_as_hal_assert(dev_p->sig == CY_AS_DEVICE_HANDLE_SIGNATURE);
if (cy_as_device_is_intr_running(dev_p) != 0)
return CY_AS_ERROR_ALREADY_RUNNING;
v = CY_AS_MEM_P0_INT_MASK_REG_MMCUINT |
CY_AS_MEM_P0_INT_MASK_REG_MMBINT |
CY_AS_MEM_P0_INT_MASK_REG_MPMINT;
if (dmaintr)
v |= CY_AS_MEM_P0_INT_MASK_REG_MDRQINT;
cy_as_hal_write_register(dev_p->tag, CY_AS_MEM_P0_INT_MASK_REG, v);
cy_as_device_set_intr_running(dev_p);
return CY_AS_ERROR_SUCCESS;
}
uint32_t cy_as_intr_stop(cy_as_device *dev_p)
{
cy_as_hal_assert(dev_p->sig == CY_AS_DEVICE_HANDLE_SIGNATURE);
if (cy_as_device_is_intr_running(dev_p) == 0)
return CY_AS_ERROR_NOT_RUNNING;
cy_as_hal_write_register(dev_p->tag, CY_AS_MEM_P0_INT_MASK_REG, 0);
cy_as_device_set_intr_stopped(dev_p);
return CY_AS_ERROR_SUCCESS;
}
void cy_as_intr_service_interrupt(cy_as_hal_device_tag tag)
{
uint16_t v;
cy_as_device *dev_p;
dev_p = cy_as_device_find_from_tag(tag);
if (dev_p == 0) {
v = cy_as_hal_read_register(tag, CY_AS_MEM_P0_INTR_REG);
if (v == CY_AS_MEM_P0_INTR_REG_PMINT) {
v = cy_as_hal_read_register(tag,
CY_AS_MEM_PWR_MAGT_STAT);
} else
cy_as_hal_print_message("stray antioch "
"interrupt detected"
", tag not associated "
"with any created device.");
return;
}
cy_as_hal_assert(dev_p->sig == CY_AS_DEVICE_HANDLE_SIGNATURE);
v = cy_as_hal_read_register(dev_p->tag, CY_AS_MEM_P0_INTR_REG);
if (v & CY_AS_MEM_P0_INTR_REG_MCUINT)
cy_as_mcu_interrupt_handler(dev_p);
if (v & CY_AS_MEM_P0_INTR_REG_PMINT)
cy_as_power_management_interrupt_handler(dev_p);
if (v & CY_AS_MEM_P0_INTR_REG_PLLLOCKINT)
cy_as_pll_lock_loss_interrupt_handler(dev_p);
if (cy_as_device_is_intr_running(dev_p) == 0)
return;
if (v & CY_AS_MEM_P0_INTR_REG_MBINT)
cy_as_mail_box_interrupt_handler(dev_p);
}
