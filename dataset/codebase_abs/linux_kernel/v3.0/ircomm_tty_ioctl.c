static void F_1 ( struct V_1 * V_2 )
{
unsigned V_3 , V_4 ;
int V_5 ;
F_2 ( 2 , L_1 , V_6 ) ;
if ( ! V_2 -> V_7 || ! V_2 -> V_7 -> V_8 || ! V_2 -> V_9 )
return;
V_3 = V_2 -> V_7 -> V_8 -> V_10 ;
switch ( V_3 & V_11 ) {
case V_12 : V_4 = V_13 ; break;
case V_14 : V_4 = V_15 ; break;
case V_16 : V_4 = V_17 ; break;
case V_18 : V_4 = V_19 ; break;
default: V_4 = V_13 ; break;
}
if ( V_3 & V_20 )
V_4 |= V_21 ;
if ( V_3 & V_22 )
V_4 |= V_23 ;
if ( ! ( V_3 & V_24 ) )
V_4 |= V_25 ;
V_5 = F_3 ( V_2 -> V_7 ) ;
if ( ! V_5 )
V_5 = 9600 ;
V_2 -> V_26 . V_27 = V_5 ;
F_4 ( V_2 , V_28 , FALSE ) ;
if ( V_3 & V_29 ) {
V_2 -> V_30 |= V_31 ;
V_2 -> V_26 . V_32 |= V_33 ;
if ( V_2 -> V_34 == V_35 )
F_5 ( L_2 , V_6 ) ;
} else {
V_2 -> V_30 &= ~ V_31 ;
V_2 -> V_26 . V_32 &= ~ V_33 ;
}
if ( V_3 & V_36 )
V_2 -> V_30 &= ~ V_37 ;
else
V_2 -> V_30 |= V_37 ;
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
V_2 -> V_26 . V_38 = V_4 ;
F_4 ( V_2 , V_39 , FALSE ) ;
F_4 ( V_2 , V_40 , TRUE ) ;
}
void F_6 ( struct V_41 * V_7 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_44 ;
unsigned int V_3 = V_7 -> V_8 -> V_10 ;
F_2 ( 2 , L_1 , V_6 ) ;
if ( ( V_3 == V_43 -> V_10 ) &&
( F_7 ( V_7 -> V_8 -> V_45 ) ==
F_7 ( V_43 -> V_45 ) ) )
{
return;
}
F_1 ( V_2 ) ;
if ( ( V_43 -> V_10 & V_46 ) &&
! ( V_3 & V_46 ) ) {
V_2 -> V_26 . V_47 &= ~ ( V_48 | V_49 ) ;
F_4 ( V_2 , V_50 , TRUE ) ;
}
if ( ! ( V_43 -> V_10 & V_46 ) &&
( V_3 & V_46 ) ) {
V_2 -> V_26 . V_47 |= V_48 ;
if ( ! ( V_7 -> V_8 -> V_10 & V_29 ) ||
! F_8 ( V_51 , & V_7 -> V_30 ) ) {
V_2 -> V_26 . V_47 |= V_49 ;
}
F_4 ( V_2 , V_50 , TRUE ) ;
}
if ( ( V_43 -> V_10 & V_29 ) &&
! ( V_7 -> V_8 -> V_10 & V_29 ) )
{
V_7 -> V_52 = 0 ;
F_9 ( V_7 ) ;
}
}
int F_10 ( struct V_41 * V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_44 ;
unsigned int V_53 ;
F_2 ( 2 , L_1 , V_6 ) ;
if ( V_7 -> V_30 & ( 1 << V_54 ) )
return - V_55 ;
V_53 = ( ( V_2 -> V_26 . V_47 & V_49 ) ? V_56 : 0 )
| ( ( V_2 -> V_26 . V_47 & V_48 ) ? V_57 : 0 )
| ( ( V_2 -> V_26 . V_58 & V_59 ) ? V_60 : 0 )
| ( ( V_2 -> V_26 . V_58 & V_61 ) ? V_62 : 0 )
| ( ( V_2 -> V_26 . V_58 & V_63 ) ? V_64 : 0 )
| ( ( V_2 -> V_26 . V_58 & V_65 ) ? V_66 : 0 ) ;
return V_53 ;
}
int F_11 ( struct V_41 * V_7 ,
unsigned int V_67 , unsigned int V_68 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_44 ;
F_2 ( 2 , L_1 , V_6 ) ;
if ( V_7 -> V_30 & ( 1 << V_54 ) )
return - V_55 ;
F_12 (self != NULL, return -1;) ;
F_12 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_67 & V_56 )
V_2 -> V_26 . V_47 |= V_49 ;
if ( V_67 & V_57 )
V_2 -> V_26 . V_47 |= V_48 ;
if ( V_68 & V_56 )
V_2 -> V_26 . V_47 &= ~ V_49 ;
if ( V_68 & V_57 )
V_2 -> V_26 . V_47 &= ~ V_48 ;
if ( ( V_67 | V_68 ) & V_56 )
V_2 -> V_26 . V_47 |= V_69 ;
if ( ( V_67 | V_68 ) & V_57 )
V_2 -> V_26 . V_47 |= V_70 ;
F_4 ( V_2 , V_50 , TRUE ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_71 T_1 * V_72 )
{
struct V_71 V_73 ;
if ( ! V_72 )
return - V_74 ;
F_2 ( 2 , L_1 , V_6 ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . line = V_2 -> line ;
V_73 . V_30 = V_2 -> V_30 ;
V_73 . V_75 = V_2 -> V_26 . V_27 ;
V_73 . V_76 = V_2 -> V_76 ;
V_73 . V_77 = V_2 -> V_77 ;
V_73 . type = V_78 ;
V_73 . V_79 = 0 ;
V_73 . V_80 = 0 ;
V_73 . V_81 = 0 ;
V_73 . V_82 = 0 ;
V_73 . V_83 = 0 ;
if ( F_14 ( V_72 , & V_73 , sizeof( * V_72 ) ) )
return - V_74 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_71 T_1 * V_84 )
{
#if 0
struct serial_struct new_serial;
struct ircomm_tty_cb old_state, *state;
IRDA_DEBUG(0, "%s()\n", __func__ );
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
if (self->flags & ASYNC_INITIALIZED) {
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
int F_16 ( struct V_41 * V_7 ,
unsigned int V_85 , unsigned long V_86 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_44 ;
int V_87 = 0 ;
F_2 ( 2 , L_1 , V_6 ) ;
if ( ( V_85 != V_88 ) && ( V_85 != V_89 ) &&
( V_85 != V_90 ) && ( V_85 != V_91 ) &&
( V_85 != V_92 ) && ( V_85 != V_93 ) ) {
if ( V_7 -> V_30 & ( 1 << V_54 ) )
return - V_55 ;
}
switch ( V_85 ) {
case V_88 :
V_87 = F_13 ( V_2 , (struct V_71 T_1 * ) V_86 ) ;
break;
case V_89 :
V_87 = F_15 ( V_2 , (struct V_71 T_1 * ) V_86 ) ;
break;
case V_92 :
F_2 ( 0 , L_3 ) ;
break;
case V_93 :
F_2 ( 0 , L_4 , V_6 ) ;
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
V_87 = - V_94 ;
}
return V_87 ;
}
