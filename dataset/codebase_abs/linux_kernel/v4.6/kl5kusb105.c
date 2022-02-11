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
if ( ! V_25 )
return - V_28 ;
V_25 [ 0 ] = 0xff ;
V_25 [ 1 ] = 0xff ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_9 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_29 ,
V_9 | V_30 ,
0 ,
0 ,
V_25 , V_26 ,
10000
) ;
if ( V_5 < 0 )
F_4 ( & V_2 -> V_7 , L_4 ,
V_5 ) ;
else {
V_18 = F_10 ( V_25 ) ;
F_5 ( & V_2 -> V_6 -> V_7 -> V_7 , L_5 ,
V_25 [ 0 ] , V_25 [ 1 ] ) ;
* V_24 = F_6 ( V_18 ) ;
}
F_11 ( V_25 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
V_32 = F_8 ( sizeof( * V_32 ) , V_27 ) ;
if ( ! V_32 )
return - V_28 ;
V_32 -> V_33 . V_13 = 5 ;
V_32 -> V_33 . V_14 = V_34 ;
V_32 -> V_33 . V_15 = V_35 ;
V_32 -> V_33 . V_16 = 0 ;
V_32 -> V_33 . V_17 = 1 ;
V_32 -> V_36 = 0 ;
F_13 ( & V_32 -> V_37 ) ;
F_14 ( V_2 , V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
V_32 = F_16 ( V_2 ) ;
F_11 ( V_32 ) ;
return 0 ;
}
static int F_17 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_31 * V_32 = F_16 ( V_2 ) ;
int V_40 = 0 ;
int V_5 ;
int V_41 ;
unsigned long V_36 ;
struct V_3 * V_33 ;
unsigned long V_42 ;
V_33 = F_8 ( sizeof( * V_33 ) , V_27 ) ;
if ( ! V_33 )
return - V_28 ;
V_33 -> V_13 = 5 ;
V_33 -> V_14 = V_34 ;
V_33 -> V_15 = V_35 ;
V_33 -> V_16 = 0 ;
V_33 -> V_17 = 1 ;
F_1 ( V_2 , V_33 ) ;
F_18 ( & V_32 -> V_37 , V_42 ) ;
V_32 -> V_43 . V_44 = V_39 -> V_43 . V_44 ;
V_32 -> V_43 . V_45 = V_39 -> V_43 . V_45 ;
V_32 -> V_43 . V_46 = V_39 -> V_43 . V_46 ;
V_32 -> V_43 . V_47 = V_39 -> V_43 . V_47 ;
for ( V_41 = 0 ; V_41 < V_48 ; V_41 ++ )
V_32 -> V_43 . V_49 [ V_41 ] = V_39 -> V_43 . V_49 [ V_41 ] ;
V_32 -> V_33 . V_13 = V_33 -> V_13 ;
V_32 -> V_33 . V_14 = V_33 -> V_14 ;
V_32 -> V_33 . V_15 = V_33 -> V_15 ;
V_32 -> V_33 . V_16 = V_33 -> V_16 ;
V_32 -> V_33 . V_17 = V_33 -> V_17 ;
F_19 ( & V_32 -> V_37 , V_42 ) ;
V_5 = F_20 ( V_39 , V_2 ) ;
if ( V_5 ) {
V_40 = V_5 ;
goto exit;
}
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_50 ,
V_9 | V_10 | V_11 ,
V_51 ,
0 ,
NULL ,
0 ,
V_12 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 , L_6 , V_5 ) ;
V_40 = V_5 ;
} else
F_21 ( & V_2 -> V_7 , L_7 , V_52 ) ;
V_5 = F_7 ( V_2 , & V_36 ) ;
if ( V_5 >= 0 ) {
F_18 ( & V_32 -> V_37 , V_42 ) ;
V_32 -> V_36 = V_36 ;
F_19 ( & V_32 -> V_37 , V_42 ) ;
F_21 ( & V_2 -> V_7 , L_8 , V_52 , V_36 ) ;
V_40 = 0 ;
} else
V_40 = V_5 ;
exit:
F_11 ( V_33 ) ;
return V_40 ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_50 ,
V_9 | V_10 ,
V_53 ,
0 ,
NULL , 0 ,
V_12 ) ;
if ( V_5 < 0 )
F_4 ( & V_2 -> V_7 , L_9 , V_5 ) ;
F_23 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
void * V_54 , T_3 V_55 )
{
unsigned char * V_56 = V_54 ;
int V_57 ;
V_57 = F_25 ( & V_2 -> V_58 , V_56 + V_59 , V_55 ,
& V_2 -> V_37 ) ;
F_26 ( V_57 , V_56 ) ;
return V_57 + V_59 ;
}
static void F_27 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
unsigned char * V_62 = V_60 -> V_63 ;
unsigned V_64 ;
if ( ! V_60 -> V_65 )
return;
if ( V_60 -> V_65 <= V_59 ) {
F_21 ( & V_2 -> V_7 , L_10 , V_52 ) ;
return;
}
V_64 = F_10 ( V_62 ) ;
if ( V_64 > V_60 -> V_65 - V_59 ) {
F_21 ( & V_2 -> V_7 , L_11 , V_52 ) ;
V_64 = V_60 -> V_65 - V_59 ;
}
F_28 ( & V_2 -> V_2 , V_62 + V_59 , V_64 ) ;
F_29 ( & V_2 -> V_2 ) ;
}
static void F_30 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_31 * V_32 = F_16 ( V_2 ) ;
struct V_68 * V_7 = & V_2 -> V_7 ;
unsigned int V_69 = V_39 -> V_43 . V_44 ;
unsigned int V_70 = V_67 -> V_44 ;
unsigned int V_71 = V_39 -> V_43 . V_46 ;
unsigned int V_72 = V_67 -> V_46 ;
struct V_3 * V_33 ;
unsigned long V_42 ;
T_4 V_73 ;
V_33 = F_8 ( sizeof( * V_33 ) , V_27 ) ;
if ( ! V_33 )
return;
F_18 ( & V_32 -> V_37 , V_42 ) ;
V_73 = F_31 ( V_39 ) ;
if ( ( V_71 & V_74 ) != ( V_72 & V_74 ) ) {
if ( ( V_72 & V_74 ) == V_75 ) {
F_21 ( V_7 , L_12 , V_52 ) ;
#if 0
priv->control_state |= TIOCM_DTR;
if (!(old_cflag & CRTSCTS))
priv->control_state |= TIOCM_RTS;
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
}
switch ( V_73 ) {
case 0 :
break;
case 1200 :
V_32 -> V_33 . V_14 = V_76 ;
break;
case 2400 :
V_32 -> V_33 . V_14 = V_77 ;
break;
case 4800 :
V_32 -> V_33 . V_14 = V_78 ;
break;
case 9600 :
V_32 -> V_33 . V_14 = V_34 ;
break;
case 19200 :
V_32 -> V_33 . V_14 = V_79 ;
break;
case 38400 :
V_32 -> V_33 . V_14 = V_80 ;
break;
case 57600 :
V_32 -> V_33 . V_14 = V_81 ;
break;
case 115200 :
V_32 -> V_33 . V_14 = V_82 ;
break;
default:
F_21 ( V_7 , L_13 ) ;
V_32 -> V_33 . V_14 = V_34 ;
V_73 = 9600 ;
break;
}
if ( ( V_71 & V_74 ) == V_75 ) {
F_21 ( V_7 , L_14 , V_52 ) ;
#if 0
priv->control_state &= ~(TIOCM_DTR | TIOCM_RTS);
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
F_32 ( V_39 , V_73 , V_73 ) ;
if ( ( V_71 & V_83 ) != ( V_72 & V_83 ) ) {
switch ( V_71 & V_83 ) {
case V_84 :
F_21 ( V_7 , L_15 , V_52 ) ;
F_19 ( & V_32 -> V_37 , V_42 ) ;
goto V_85;
case V_86 :
F_21 ( V_7 , L_16 , V_52 ) ;
F_19 ( & V_32 -> V_37 , V_42 ) ;
goto V_85;
case V_87 :
V_32 -> V_33 . V_15 = V_88 ;
break;
case V_89 :
V_32 -> V_33 . V_15 = V_35 ;
break;
default:
F_4 ( V_7 , L_17 ) ;
V_32 -> V_33 . V_15 = V_35 ;
break;
}
}
if ( ( V_71 & ( V_90 | V_91 ) ) != ( V_72 & ( V_90 | V_91 ) )
|| ( V_71 & V_92 ) != ( V_72 & V_92 ) ) {
V_39 -> V_43 . V_46 &= ~ ( V_90 | V_91 | V_92 ) ;
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
}
if ( ( V_69 & V_93 ) != ( V_70 & V_93 )
|| ( V_69 & V_94 ) != ( V_70 & V_94 )
|| ( V_71 & V_95 ) != ( V_72 & V_95 ) ) {
V_39 -> V_43 . V_46 &= ~ V_95 ;
#if 0
if ((iflag & IXOFF) || (iflag & IXON) || (cflag & CRTSCTS))
priv->control_state |= TIOCM_DTR | TIOCM_RTS;
else
priv->control_state &= ~(TIOCM_DTR | TIOCM_RTS);
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
memcpy ( V_33 , & V_32 -> V_33 , sizeof( * V_33 ) ) ;
F_19 ( & V_32 -> V_37 , V_42 ) ;
F_1 ( V_2 , V_33 ) ;
V_85:
F_11 ( V_33 ) ;
}
static int F_33 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_96 ;
struct V_31 * V_32 = F_16 ( V_2 ) ;
unsigned long V_42 ;
int V_5 ;
unsigned long V_36 ;
V_5 = F_7 ( V_2 , & V_36 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 ,
L_18 , V_5 ) ;
return V_5 ;
}
F_18 ( & V_32 -> V_37 , V_42 ) ;
V_32 -> V_36 = V_36 ;
F_19 ( & V_32 -> V_37 , V_42 ) ;
F_21 ( & V_2 -> V_7 , L_8 , V_52 , V_36 ) ;
return ( int ) V_36 ;
}
