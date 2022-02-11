static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 , V_6 ;
int V_7 ;
F_2 ( 2 , L_1 , V_8 ) ;
if ( ! V_2 -> V_9 )
return;
V_5 = V_4 -> V_10 . V_11 ;
switch ( V_5 & V_12 ) {
case V_13 : V_6 = V_14 ; break;
case V_15 : V_6 = V_16 ; break;
case V_17 : V_6 = V_18 ; break;
case V_19 : V_6 = V_20 ; break;
default: V_6 = V_14 ; break;
}
if ( V_5 & V_21 )
V_6 |= V_22 ;
if ( V_5 & V_23 )
V_6 |= V_24 ;
if ( ! ( V_5 & V_25 ) )
V_6 |= V_26 ;
V_7 = F_3 ( V_4 ) ;
if ( ! V_7 )
V_7 = 9600 ;
V_2 -> V_27 . V_28 = V_7 ;
F_4 ( V_2 , V_29 , FALSE ) ;
if ( V_5 & V_30 ) {
V_2 -> V_31 . V_32 |= V_33 ;
V_2 -> V_27 . V_34 |= V_35 ;
if ( V_2 -> V_36 == V_37 )
F_5 ( L_2 , V_8 ) ;
} else {
V_2 -> V_31 . V_32 &= ~ V_33 ;
V_2 -> V_27 . V_34 &= ~ V_35 ;
}
if ( V_5 & V_38 )
V_2 -> V_31 . V_32 &= ~ V_39 ;
else
V_2 -> V_31 . V_32 |= V_39 ;
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
V_2 -> V_27 . V_40 = V_6 ;
F_4 ( V_2 , V_41 , FALSE ) ;
F_4 ( V_2 , V_42 , TRUE ) ;
}
void F_6 ( struct V_3 * V_4 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_45 ;
unsigned int V_5 = V_4 -> V_10 . V_11 ;
F_2 ( 2 , L_1 , V_8 ) ;
if ( ( V_5 == V_44 -> V_11 ) &&
( F_7 ( V_4 -> V_10 . V_46 ) ==
F_7 ( V_44 -> V_46 ) ) )
{
return;
}
F_1 ( V_2 , V_4 ) ;
if ( ( V_44 -> V_11 & V_47 ) &&
! ( V_5 & V_47 ) ) {
V_2 -> V_27 . V_48 &= ~ ( V_49 | V_50 ) ;
F_4 ( V_2 , V_51 , TRUE ) ;
}
if ( ! ( V_44 -> V_11 & V_47 ) &&
( V_5 & V_47 ) ) {
V_2 -> V_27 . V_48 |= V_49 ;
if ( ! ( V_4 -> V_10 . V_11 & V_30 ) ||
! F_8 ( V_52 , & V_4 -> V_32 ) ) {
V_2 -> V_27 . V_48 |= V_50 ;
}
F_4 ( V_2 , V_51 , TRUE ) ;
}
if ( ( V_44 -> V_11 & V_30 ) &&
! ( V_4 -> V_10 . V_11 & V_30 ) )
{
V_4 -> V_53 = 0 ;
F_9 ( V_4 ) ;
}
}
int F_10 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_45 ;
unsigned int V_54 ;
F_2 ( 2 , L_1 , V_8 ) ;
if ( V_4 -> V_32 & ( 1 << V_55 ) )
return - V_56 ;
V_54 = ( ( V_2 -> V_27 . V_48 & V_50 ) ? V_57 : 0 )
| ( ( V_2 -> V_27 . V_48 & V_49 ) ? V_58 : 0 )
| ( ( V_2 -> V_27 . V_59 & V_60 ) ? V_61 : 0 )
| ( ( V_2 -> V_27 . V_59 & V_62 ) ? V_63 : 0 )
| ( ( V_2 -> V_27 . V_59 & V_64 ) ? V_65 : 0 )
| ( ( V_2 -> V_27 . V_59 & V_66 ) ? V_67 : 0 ) ;
return V_54 ;
}
int F_11 ( struct V_3 * V_4 ,
unsigned int V_68 , unsigned int V_69 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_45 ;
F_2 ( 2 , L_1 , V_8 ) ;
if ( V_4 -> V_32 & ( 1 << V_55 ) )
return - V_56 ;
F_12 (self != NULL, return -1;) ;
F_12 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_68 & V_57 )
V_2 -> V_27 . V_48 |= V_50 ;
if ( V_68 & V_58 )
V_2 -> V_27 . V_48 |= V_49 ;
if ( V_69 & V_57 )
V_2 -> V_27 . V_48 &= ~ V_50 ;
if ( V_69 & V_58 )
V_2 -> V_27 . V_48 &= ~ V_49 ;
if ( ( V_68 | V_69 ) & V_57 )
V_2 -> V_27 . V_48 |= V_70 ;
if ( ( V_68 | V_69 ) & V_58 )
V_2 -> V_27 . V_48 |= V_71 ;
F_4 ( V_2 , V_51 , TRUE ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_72 T_1 * V_73 )
{
struct V_72 V_74 ;
if ( ! V_73 )
return - V_75 ;
F_2 ( 2 , L_1 , V_8 ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . line = V_2 -> line ;
V_74 . V_32 = V_2 -> V_31 . V_32 ;
V_74 . V_76 = V_2 -> V_27 . V_28 ;
V_74 . V_77 = V_2 -> V_31 . V_77 ;
V_74 . V_78 = V_2 -> V_31 . V_78 ;
V_74 . type = V_79 ;
V_74 . V_31 = 0 ;
V_74 . V_80 = 0 ;
V_74 . V_81 = 0 ;
V_74 . V_82 = 0 ;
V_74 . V_83 = 0 ;
if ( F_14 ( V_73 , & V_74 , sizeof( * V_73 ) ) )
return - V_75 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_72 T_1 * V_84 )
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
int F_16 ( struct V_3 * V_4 ,
unsigned int V_85 , unsigned long V_86 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_45 ;
int V_87 = 0 ;
F_2 ( 2 , L_1 , V_8 ) ;
if ( ( V_85 != V_88 ) && ( V_85 != V_89 ) &&
( V_85 != V_90 ) && ( V_85 != V_91 ) &&
( V_85 != V_92 ) && ( V_85 != V_93 ) ) {
if ( V_4 -> V_32 & ( 1 << V_55 ) )
return - V_56 ;
}
switch ( V_85 ) {
case V_88 :
V_87 = F_13 ( V_2 , (struct V_72 T_1 * ) V_86 ) ;
break;
case V_89 :
V_87 = F_15 ( V_2 , (struct V_72 T_1 * ) V_86 ) ;
break;
case V_92 :
F_2 ( 0 , L_3 ) ;
break;
case V_93 :
F_2 ( 0 , L_4 , V_8 ) ;
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
