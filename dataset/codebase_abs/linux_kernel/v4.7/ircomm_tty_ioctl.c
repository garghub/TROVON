static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 , V_6 ;
int V_7 ;
if ( ! V_2 -> V_8 )
return;
V_5 = V_4 -> V_9 . V_10 ;
switch ( V_5 & V_11 ) {
case V_12 : V_6 = V_13 ; break;
case V_14 : V_6 = V_15 ; break;
case V_16 : V_6 = V_17 ; break;
case V_18 : V_6 = V_19 ; break;
default: V_6 = V_13 ; break;
}
if ( V_5 & V_20 )
V_6 |= V_21 ;
if ( V_5 & V_22 )
V_6 |= V_23 ;
if ( ! ( V_5 & V_24 ) )
V_6 |= V_25 ;
V_7 = F_2 ( V_4 ) ;
if ( ! V_7 )
V_7 = 9600 ;
V_2 -> V_26 . V_27 = V_7 ;
F_3 ( V_2 , V_28 , FALSE ) ;
F_4 ( & V_2 -> V_29 , V_5 & V_30 ) ;
if ( V_5 & V_30 ) {
V_2 -> V_26 . V_31 |= V_32 ;
if ( V_2 -> V_33 == V_34 )
F_5 ( L_1 ,
V_35 ) ;
} else {
V_2 -> V_26 . V_31 &= ~ V_32 ;
}
F_6 ( & V_2 -> V_29 , ~ V_5 & V_36 ) ;
#if 0
if (I_INPCK(self->tty))
driver->read_status_mask |= LSR_FE | LSR_PE;
if (I_BRKINT(driver->tty) || I_PARMRK(driver->tty))
driver->read_status_mask |= LSR_BI;
driver->ignore_status_mask = 0;
if (I_IGNPAR(driver->tty))
driver->ignore_status_mask |= LSR_PE | LSR_FE;
if (I_IGNBRK(self->tty)) {
self->ignore_status_mask |= LSR_BI;
if (I_IGNPAR(self->tty))
self->ignore_status_mask |= LSR_OE;
}
#endif
V_2 -> V_26 . V_37 = V_6 ;
F_3 ( V_2 , V_38 , FALSE ) ;
F_3 ( V_2 , V_39 , TRUE ) ;
}
void F_7 ( struct V_3 * V_4 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_42 ;
unsigned int V_5 = V_4 -> V_9 . V_10 ;
if ( ( V_5 == V_41 -> V_10 ) &&
( F_8 ( V_4 -> V_9 . V_43 ) ==
F_8 ( V_41 -> V_43 ) ) )
{
return;
}
F_1 ( V_2 , V_4 ) ;
if ( ( V_41 -> V_10 & V_44 ) && ! ( V_5 & V_44 ) ) {
V_2 -> V_26 . V_45 &= ~ ( V_46 | V_47 ) ;
F_3 ( V_2 , V_48 , TRUE ) ;
}
if ( ! ( V_41 -> V_10 & V_44 ) && ( V_5 & V_44 ) ) {
V_2 -> V_26 . V_45 |= V_46 ;
if ( ! F_9 ( V_4 ) || ! F_10 ( V_4 ) )
V_2 -> V_26 . V_45 |= V_47 ;
F_3 ( V_2 , V_48 , TRUE ) ;
}
if ( ( V_41 -> V_10 & V_30 ) && ! F_9 ( V_4 ) )
{
V_4 -> V_49 = 0 ;
F_11 ( V_4 ) ;
}
}
int F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_42 ;
unsigned int V_50 ;
if ( F_13 ( V_4 ) )
return - V_51 ;
V_50 = ( ( V_2 -> V_26 . V_45 & V_47 ) ? V_52 : 0 )
| ( ( V_2 -> V_26 . V_45 & V_46 ) ? V_53 : 0 )
| ( ( V_2 -> V_26 . V_54 & V_55 ) ? V_56 : 0 )
| ( ( V_2 -> V_26 . V_54 & V_57 ) ? V_58 : 0 )
| ( ( V_2 -> V_26 . V_54 & V_59 ) ? V_60 : 0 )
| ( ( V_2 -> V_26 . V_54 & V_61 ) ? V_62 : 0 ) ;
return V_50 ;
}
int F_14 ( struct V_3 * V_4 ,
unsigned int V_63 , unsigned int V_64 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_42 ;
if ( F_13 ( V_4 ) )
return - V_51 ;
F_15 (self != NULL, return -1;) ;
F_15 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_63 & V_52 )
V_2 -> V_26 . V_45 |= V_47 ;
if ( V_63 & V_53 )
V_2 -> V_26 . V_45 |= V_46 ;
if ( V_64 & V_52 )
V_2 -> V_26 . V_45 &= ~ V_47 ;
if ( V_64 & V_53 )
V_2 -> V_26 . V_45 &= ~ V_46 ;
if ( ( V_63 | V_64 ) & V_52 )
V_2 -> V_26 . V_45 |= V_65 ;
if ( ( V_63 | V_64 ) & V_53 )
V_2 -> V_26 . V_45 |= V_66 ;
F_3 ( V_2 , V_48 , TRUE ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_67 T_1 * V_68 )
{
struct V_67 V_69 ;
if ( ! V_68 )
return - V_70 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . line = V_2 -> line ;
V_69 . V_71 = V_2 -> V_29 . V_71 ;
V_69 . V_72 = V_2 -> V_26 . V_27 ;
V_69 . V_73 = V_2 -> V_29 . V_73 ;
V_69 . V_74 = V_2 -> V_29 . V_74 ;
V_69 . type = V_75 ;
V_69 . V_29 = 0 ;
V_69 . V_76 = 0 ;
V_69 . V_77 = 0 ;
V_69 . V_78 = 0 ;
V_69 . V_79 = 0 ;
if ( F_17 ( V_68 , & V_69 , sizeof( * V_68 ) ) )
return - V_70 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_67 T_1 * V_80 )
{
#if 0
struct serial_struct new_serial;
struct ircomm_tty_cb old_state, *state;
if (copy_from_user(&new_serial,new_info,sizeof(new_serial)))
return -EFAULT;
state = self
old_state = *self;
if (!capable(CAP_SYS_ADMIN)) {
if ((new_serial.baud_base != state->settings.data_rate) ||
(new_serial.close_delay != state->close_delay) ||
((new_serial.flags & ~ASYNC_USR_MASK) !=
(self->flags & ~ASYNC_USR_MASK)))
return -EPERM;
state->flags = ((state->flags & ~ASYNC_USR_MASK) |
(new_serial.flags & ASYNC_USR_MASK));
self->flags = ((self->flags & ~ASYNC_USR_MASK) |
(new_serial.flags & ASYNC_USR_MASK));
goto check_and_exit;
}
if (self->settings.data_rate != new_serial.baud_base) {
self->settings.data_rate = new_serial.baud_base;
ircomm_param_request(self, IRCOMM_DATA_RATE, TRUE);
}
self->close_delay = new_serial.close_delay * HZ/100;
self->closing_wait = new_serial.closing_wait * HZ/100;
self->flags = ((self->flags & ~ASYNC_FLAGS) |
(new_serial.flags & ASYNC_FLAGS));
self->tty->low_latency = (self->flags & ASYNC_LOW_LATENCY) ? 1 : 0;
check_and_exit:
if (tty_port_initialized(self)) {
if (((old_state.flags & ASYNC_SPD_MASK) !=
(self->flags & ASYNC_SPD_MASK)) ||
(old_driver.custom_divisor != driver->custom_divisor)) {
if ((driver->flags & ASYNC_SPD_MASK) == ASYNC_SPD_HI)
driver->tty->alt_speed = 57600;
if ((driver->flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI)
driver->tty->alt_speed = 115200;
if ((driver->flags & ASYNC_SPD_MASK) == ASYNC_SPD_SHI)
driver->tty->alt_speed = 230400;
if ((driver->flags & ASYNC_SPD_MASK) == ASYNC_SPD_WARP)
driver->tty->alt_speed = 460800;
ircomm_tty_change_speed(driver);
}
}
#endif
return 0 ;
}
int F_19 ( struct V_3 * V_4 ,
unsigned int V_81 , unsigned long V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_42 ;
int V_83 = 0 ;
if ( ( V_81 != V_84 ) && ( V_81 != V_85 ) &&
( V_81 != V_86 ) && ( V_81 != V_87 ) &&
( V_81 != V_88 ) && ( V_81 != V_89 ) ) {
if ( F_13 ( V_4 ) )
return - V_51 ;
}
switch ( V_81 ) {
case V_84 :
V_83 = F_16 ( V_2 , (struct V_67 T_1 * ) V_82 ) ;
break;
case V_85 :
V_83 = F_18 ( V_2 , (struct V_67 T_1 * ) V_82 ) ;
break;
case V_88 :
F_20 ( L_2 ) ;
break;
case V_89 :
F_20 ( L_3 , V_35 ) ;
#if 0
save_flags(flags); cli();
cnow = driver->icount;
restore_flags(flags);
p_cuser = (struct serial_icounter_struct __user *) arg;
if (put_user(cnow.cts, &p_cuser->cts) ||
put_user(cnow.dsr, &p_cuser->dsr) ||
put_user(cnow.rng, &p_cuser->rng) ||
put_user(cnow.dcd, &p_cuser->dcd) ||
put_user(cnow.rx, &p_cuser->rx) ||
put_user(cnow.tx, &p_cuser->tx) ||
put_user(cnow.frame, &p_cuser->frame) ||
put_user(cnow.overrun, &p_cuser->overrun) ||
put_user(cnow.parity, &p_cuser->parity) ||
put_user(cnow.brk, &p_cuser->brk) ||
put_user(cnow.buf_overrun, &p_cuser->buf_overrun))
return -EFAULT;
#endif
return 0 ;
default:
V_83 = - V_90 ;
}
return V_83 ;
}
