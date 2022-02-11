static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_8 ,
V_9 | V_10 | V_11 ,
0 ,
0 ,
V_4 ,
sizeof( struct V_3 ) ,
V_12 ) ;
if ( V_5 < 0 )
F_4 ( & V_2 -> V_7 ,
L_1 , V_5 ) ;
F_5 ( & V_2 -> V_6 -> V_7 -> V_7 ,
L_2 ,
V_4 -> V_13 , V_4 -> V_14 , V_4 -> V_15 ,
V_4 -> V_16 , V_4 -> V_17 ) ;
return V_5 ;
}
static unsigned long F_6 ( const T_1 V_18 )
{
unsigned long V_19 = 0 ;
V_19 = ( ( V_18 & V_20 ) ? V_21 : 0 )
| ( ( V_18 & V_22 ) ? V_23 : 0 )
;
return V_19 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long * V_24 )
{
int V_5 ;
T_2 * V_25 ;
T_1 V_18 ;
F_5 ( & V_2 -> V_6 -> V_7 -> V_7 , L_3 ) ;
V_25 = F_8 ( V_26 , V_27 ) ;
if ( ! V_25 ) {
F_4 ( & V_2 -> V_7 , L_4 ,
V_28 ) ;
return - V_29 ;
}
V_25 [ 0 ] = 0xff ;
V_25 [ 1 ] = 0xff ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_9 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_30 ,
V_9 | V_31 ,
0 ,
0 ,
V_25 , V_26 ,
10000
) ;
if ( V_5 < 0 )
F_4 ( & V_2 -> V_7 , L_5 ,
V_5 ) ;
else {
V_18 = F_10 ( V_25 ) ;
F_5 ( & V_2 -> V_6 -> V_7 -> V_7 , L_6 ,
V_25 [ 0 ] , V_25 [ 1 ] ) ;
* V_24 = F_6 ( V_18 ) ;
}
F_11 ( V_25 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
V_33 = F_8 ( sizeof( * V_33 ) , V_27 ) ;
if ( ! V_33 )
return - V_29 ;
V_33 -> V_34 . V_13 = 5 ;
V_33 -> V_34 . V_14 = V_35 ;
V_33 -> V_34 . V_15 = V_36 ;
V_33 -> V_34 . V_16 = 0 ;
V_33 -> V_34 . V_17 = 1 ;
V_33 -> V_37 = 0 ;
F_13 ( & V_33 -> V_38 ) ;
F_14 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
V_33 = F_16 ( V_2 ) ;
F_11 ( V_33 ) ;
return 0 ;
}
static int F_17 ( struct V_39 * V_40 , struct V_1 * V_2 )
{
struct V_32 * V_33 = F_16 ( V_2 ) ;
int V_41 = 0 ;
int V_5 ;
int V_42 ;
unsigned long V_37 ;
struct V_3 * V_34 ;
unsigned long V_43 ;
V_34 = F_8 ( sizeof( * V_34 ) , V_27 ) ;
if ( ! V_34 ) {
F_4 ( & V_2 -> V_7 , L_7 ,
V_28 ) ;
return - V_29 ;
}
V_34 -> V_13 = 5 ;
V_34 -> V_14 = V_35 ;
V_34 -> V_15 = V_36 ;
V_34 -> V_16 = 0 ;
V_34 -> V_17 = 1 ;
F_1 ( V_2 , V_34 ) ;
F_18 ( & V_33 -> V_38 , V_43 ) ;
V_33 -> V_44 . V_45 = V_40 -> V_44 . V_45 ;
V_33 -> V_44 . V_46 = V_40 -> V_44 . V_46 ;
V_33 -> V_44 . V_47 = V_40 -> V_44 . V_47 ;
V_33 -> V_44 . V_48 = V_40 -> V_44 . V_48 ;
for ( V_42 = 0 ; V_42 < V_49 ; V_42 ++ )
V_33 -> V_44 . V_50 [ V_42 ] = V_40 -> V_44 . V_50 [ V_42 ] ;
V_33 -> V_34 . V_13 = V_34 -> V_13 ;
V_33 -> V_34 . V_14 = V_34 -> V_14 ;
V_33 -> V_34 . V_15 = V_34 -> V_15 ;
V_33 -> V_34 . V_16 = V_34 -> V_16 ;
V_33 -> V_34 . V_17 = V_34 -> V_17 ;
F_19 ( & V_33 -> V_38 , V_43 ) ;
V_5 = F_20 ( V_40 , V_2 ) ;
if ( V_5 ) {
V_41 = V_5 ;
goto exit;
}
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_51 ,
V_9 | V_10 | V_11 ,
V_52 ,
0 ,
NULL ,
0 ,
V_12 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 , L_8 , V_5 ) ;
V_41 = V_5 ;
} else
F_21 ( & V_2 -> V_7 , L_9 , V_28 ) ;
V_5 = F_7 ( V_2 , & V_37 ) ;
if ( V_5 >= 0 ) {
F_18 ( & V_33 -> V_38 , V_43 ) ;
V_33 -> V_37 = V_37 ;
F_19 ( & V_33 -> V_38 , V_43 ) ;
F_21 ( & V_2 -> V_7 , L_10 , V_28 , V_37 ) ;
V_41 = 0 ;
} else
V_41 = V_5 ;
exit:
F_11 ( V_34 ) ;
return V_41 ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_5 ;
F_23 ( & V_2 -> V_6 -> V_53 ) ;
if ( ! V_2 -> V_6 -> V_54 ) {
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_51 ,
V_9 | V_10 ,
V_55 ,
0 ,
NULL , 0 ,
V_12 ) ;
if ( V_5 < 0 )
F_4 ( & V_2 -> V_7 ,
L_11 , V_5 ) ;
}
F_24 ( & V_2 -> V_6 -> V_53 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 -> V_56 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
void * V_57 , T_3 V_58 )
{
unsigned char * V_59 = V_57 ;
int V_60 ;
V_60 = F_28 ( & V_2 -> V_61 , V_59 + V_62 , V_58 ,
& V_2 -> V_38 ) ;
F_29 ( V_60 , V_59 ) ;
return V_60 + V_62 ;
}
static void F_30 ( struct V_63 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_64 ;
unsigned char * V_65 = V_63 -> V_66 ;
struct V_39 * V_40 ;
unsigned V_67 ;
if ( ! V_63 -> V_68 )
return;
if ( V_63 -> V_68 <= V_62 ) {
F_21 ( & V_2 -> V_7 , L_12 , V_28 ) ;
return;
}
V_40 = F_31 ( & V_2 -> V_2 ) ;
if ( ! V_40 )
return;
V_67 = F_10 ( V_65 ) ;
if ( V_67 > V_63 -> V_68 - V_62 ) {
F_21 ( & V_2 -> V_7 , L_13 , V_28 ) ;
V_67 = V_63 -> V_68 - V_62 ;
}
F_32 ( V_40 , V_65 + V_62 , V_67 ) ;
F_33 ( V_40 ) ;
F_34 ( V_40 ) ;
}
static void F_35 ( struct V_39 * V_40 ,
struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_32 * V_33 = F_16 ( V_2 ) ;
struct V_71 * V_7 = & V_2 -> V_7 ;
unsigned int V_72 = V_40 -> V_44 . V_45 ;
unsigned int V_73 = V_70 -> V_45 ;
unsigned int V_74 = V_40 -> V_44 . V_47 ;
unsigned int V_75 = V_70 -> V_47 ;
struct V_3 * V_34 ;
unsigned long V_43 ;
T_4 V_76 ;
V_34 = F_8 ( sizeof( * V_34 ) , V_27 ) ;
if ( ! V_34 ) {
F_4 ( V_7 , L_7 , V_28 ) ;
return;
}
F_18 ( & V_33 -> V_38 , V_43 ) ;
V_76 = F_36 ( V_40 ) ;
if ( ( V_74 & V_77 ) != ( V_75 & V_77 ) ) {
if ( ( V_75 & V_77 ) == V_78 ) {
F_21 ( V_7 , L_14 , V_28 ) ;
#if 0
priv->control_state |= TIOCM_DTR;
if (!(old_cflag & CRTSCTS))
priv->control_state |= TIOCM_RTS;
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
}
switch ( V_76 ) {
case 0 :
break;
case 1200 :
V_33 -> V_34 . V_14 = V_79 ;
break;
case 2400 :
V_33 -> V_34 . V_14 = V_80 ;
break;
case 4800 :
V_33 -> V_34 . V_14 = V_81 ;
break;
case 9600 :
V_33 -> V_34 . V_14 = V_35 ;
break;
case 19200 :
V_33 -> V_34 . V_14 = V_82 ;
break;
case 38400 :
V_33 -> V_34 . V_14 = V_83 ;
break;
case 57600 :
V_33 -> V_34 . V_14 = V_84 ;
break;
case 115200 :
V_33 -> V_34 . V_14 = V_85 ;
break;
default:
F_21 ( V_7 , L_15 ) ;
V_33 -> V_34 . V_14 = V_35 ;
V_76 = 9600 ;
break;
}
if ( ( V_74 & V_77 ) == V_78 ) {
F_21 ( V_7 , L_16 , V_28 ) ;
;
#if 0
priv->control_state &= ~(TIOCM_DTR | TIOCM_RTS);
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
F_37 ( V_40 , V_76 , V_76 ) ;
if ( ( V_74 & V_86 ) != ( V_75 & V_86 ) ) {
switch ( V_74 & V_86 ) {
case V_87 :
F_21 ( V_7 , L_17 , V_28 ) ;
F_19 ( & V_33 -> V_38 , V_43 ) ;
goto V_88;
case V_89 :
F_21 ( V_7 , L_18 , V_28 ) ;
F_19 ( & V_33 -> V_38 , V_43 ) ;
goto V_88;
case V_90 :
V_33 -> V_34 . V_15 = V_91 ;
break;
case V_92 :
V_33 -> V_34 . V_15 = V_36 ;
break;
default:
F_4 ( V_7 , L_19 ) ;
V_33 -> V_34 . V_15 = V_36 ;
break;
}
}
if ( ( V_74 & ( V_93 | V_94 ) ) != ( V_75 & ( V_93 | V_94 ) )
|| ( V_74 & V_95 ) != ( V_75 & V_95 ) ) {
V_40 -> V_44 . V_47 &= ~ ( V_93 | V_94 | V_95 ) ;
#if 0
priv->last_lcr = 0;
if (cflag & PARENB)
priv->last_lcr |= (cflag & PARODD) ?
MCT_U232_PARITY_ODD : MCT_U232_PARITY_EVEN;
else
priv->last_lcr |= MCT_U232_PARITY_NONE;
priv->last_lcr |= (cflag & CSTOPB) ?
MCT_U232_STOP_BITS_2 : MCT_U232_STOP_BITS_1;
mct_u232_set_line_ctrl(serial, priv->last_lcr);
#endif
;
}
if ( ( V_72 & V_96 ) != ( V_73 & V_96 )
|| ( V_72 & V_97 ) != ( V_73 & V_97 )
|| ( V_74 & V_98 ) != ( V_75 & V_98 ) ) {
V_40 -> V_44 . V_47 &= ~ V_98 ;
#if 0
if ((iflag & IXOFF) || (iflag & IXON) || (cflag & CRTSCTS))
priv->control_state |= TIOCM_DTR | TIOCM_RTS;
else
priv->control_state &= ~(TIOCM_DTR | TIOCM_RTS);
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
;
}
memcpy ( V_34 , & V_33 -> V_34 , sizeof( * V_34 ) ) ;
F_19 ( & V_33 -> V_38 , V_43 ) ;
F_1 ( V_2 , V_34 ) ;
V_88:
F_11 ( V_34 ) ;
}
static int F_38 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_99 ;
struct V_32 * V_33 = F_16 ( V_2 ) ;
unsigned long V_43 ;
int V_5 ;
unsigned long V_37 ;
V_5 = F_7 ( V_2 , & V_37 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 ,
L_20 , V_5 ) ;
return V_5 ;
}
F_18 ( & V_33 -> V_38 , V_43 ) ;
V_33 -> V_37 = V_37 ;
F_19 ( & V_33 -> V_38 , V_43 ) ;
F_21 ( & V_2 -> V_7 , L_10 , V_28 , V_37 ) ;
return ( int ) V_37 ;
}
static int F_39 ( struct V_39 * V_40 ,
unsigned int V_100 , unsigned int V_101 )
{
int V_41 = - V_102 ;
return V_41 ;
}
