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
if ( V_5 != V_26 ) {
F_4 ( & V_2 -> V_7 , L_4 , V_5 ) ;
if ( V_5 >= 0 )
V_5 = - V_31 ;
} else {
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
struct V_32 * V_33 ;
V_33 = F_8 ( sizeof( * V_33 ) , V_27 ) ;
if ( ! V_33 )
return - V_28 ;
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
if ( ! V_34 )
return - V_28 ;
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
goto V_51;
}
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_52 ,
V_9 | V_10 | V_11 ,
V_53 ,
0 ,
NULL ,
0 ,
V_12 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 , L_6 , V_5 ) ;
V_41 = V_5 ;
goto V_54;
} else
F_21 ( & V_2 -> V_7 , L_7 , V_55 ) ;
V_5 = F_7 ( V_2 , & V_37 ) ;
if ( V_5 < 0 ) {
V_41 = V_5 ;
goto V_56;
}
F_18 ( & V_33 -> V_38 , V_43 ) ;
V_33 -> V_37 = V_37 ;
F_19 ( & V_33 -> V_38 , V_43 ) ;
F_21 ( & V_2 -> V_7 , L_8 , V_55 ,
V_37 ) ;
return 0 ;
V_56:
F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_52 ,
V_9 | V_10 ,
V_57 ,
0 ,
NULL , 0 ,
V_12 ) ;
V_54:
F_22 ( V_2 ) ;
V_51:
F_11 ( V_34 ) ;
return V_41 ;
}
static void F_23 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_52 ,
V_9 | V_10 ,
V_57 ,
0 ,
NULL , 0 ,
V_12 ) ;
if ( V_5 < 0 )
F_4 ( & V_2 -> V_7 , L_9 , V_5 ) ;
F_22 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
void * V_58 , T_3 V_59 )
{
unsigned char * V_60 = V_58 ;
int V_61 ;
V_61 = F_25 ( & V_2 -> V_62 , V_60 + V_63 , V_59 ,
& V_2 -> V_38 ) ;
F_26 ( V_61 , V_60 ) ;
return V_61 + V_63 ;
}
static void F_27 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_65 ;
unsigned char * V_66 = V_64 -> V_67 ;
unsigned V_68 ;
if ( ! V_64 -> V_69 )
return;
if ( V_64 -> V_69 <= V_63 ) {
F_21 ( & V_2 -> V_7 , L_10 , V_55 ) ;
return;
}
V_68 = F_10 ( V_66 ) ;
if ( V_68 > V_64 -> V_69 - V_63 ) {
F_21 ( & V_2 -> V_7 , L_11 , V_55 ) ;
V_68 = V_64 -> V_69 - V_63 ;
}
F_28 ( & V_2 -> V_2 , V_66 + V_63 , V_68 ) ;
F_29 ( & V_2 -> V_2 ) ;
}
static void F_30 ( struct V_39 * V_40 ,
struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_32 * V_33 = F_16 ( V_2 ) ;
struct V_72 * V_7 = & V_2 -> V_7 ;
unsigned int V_73 = V_40 -> V_44 . V_45 ;
unsigned int V_74 = V_71 -> V_45 ;
unsigned int V_75 = V_40 -> V_44 . V_47 ;
unsigned int V_76 = V_71 -> V_47 ;
struct V_3 * V_34 ;
unsigned long V_43 ;
T_4 V_77 ;
V_34 = F_8 ( sizeof( * V_34 ) , V_27 ) ;
if ( ! V_34 )
return;
F_18 ( & V_33 -> V_38 , V_43 ) ;
V_77 = F_31 ( V_40 ) ;
if ( ( V_75 & V_78 ) != ( V_76 & V_78 ) ) {
if ( ( V_76 & V_78 ) == V_79 ) {
F_21 ( V_7 , L_12 , V_55 ) ;
#if 0
priv->control_state |= TIOCM_DTR;
if (!(old_cflag & CRTSCTS))
priv->control_state |= TIOCM_RTS;
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
}
switch ( V_77 ) {
case 0 :
break;
case 1200 :
V_33 -> V_34 . V_14 = V_80 ;
break;
case 2400 :
V_33 -> V_34 . V_14 = V_81 ;
break;
case 4800 :
V_33 -> V_34 . V_14 = V_82 ;
break;
case 9600 :
V_33 -> V_34 . V_14 = V_35 ;
break;
case 19200 :
V_33 -> V_34 . V_14 = V_83 ;
break;
case 38400 :
V_33 -> V_34 . V_14 = V_84 ;
break;
case 57600 :
V_33 -> V_34 . V_14 = V_85 ;
break;
case 115200 :
V_33 -> V_34 . V_14 = V_86 ;
break;
default:
F_21 ( V_7 , L_13 ) ;
V_33 -> V_34 . V_14 = V_35 ;
V_77 = 9600 ;
break;
}
if ( ( V_75 & V_78 ) == V_79 ) {
F_21 ( V_7 , L_14 , V_55 ) ;
#if 0
priv->control_state &= ~(TIOCM_DTR | TIOCM_RTS);
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
F_32 ( V_40 , V_77 , V_77 ) ;
if ( ( V_75 & V_87 ) != ( V_76 & V_87 ) ) {
switch ( V_75 & V_87 ) {
case V_88 :
F_21 ( V_7 , L_15 , V_55 ) ;
F_19 ( & V_33 -> V_38 , V_43 ) ;
goto V_89;
case V_90 :
F_21 ( V_7 , L_16 , V_55 ) ;
F_19 ( & V_33 -> V_38 , V_43 ) ;
goto V_89;
case V_91 :
V_33 -> V_34 . V_15 = V_92 ;
break;
case V_93 :
V_33 -> V_34 . V_15 = V_36 ;
break;
default:
F_4 ( V_7 , L_17 ) ;
V_33 -> V_34 . V_15 = V_36 ;
break;
}
}
if ( ( V_75 & ( V_94 | V_95 ) ) != ( V_76 & ( V_94 | V_95 ) )
|| ( V_75 & V_96 ) != ( V_76 & V_96 ) ) {
V_40 -> V_44 . V_47 &= ~ ( V_94 | V_95 | V_96 ) ;
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
if ( ( V_73 & V_97 ) != ( V_74 & V_97 )
|| ( V_73 & V_98 ) != ( V_74 & V_98 )
|| ( V_75 & V_99 ) != ( V_76 & V_99 ) ) {
V_40 -> V_44 . V_47 &= ~ V_99 ;
#if 0
if ((iflag & IXOFF) || (iflag & IXON) || (cflag & CRTSCTS))
priv->control_state |= TIOCM_DTR | TIOCM_RTS;
else
priv->control_state &= ~(TIOCM_DTR | TIOCM_RTS);
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
memcpy ( V_34 , & V_33 -> V_34 , sizeof( * V_34 ) ) ;
F_19 ( & V_33 -> V_38 , V_43 ) ;
F_1 ( V_2 , V_34 ) ;
V_89:
F_11 ( V_34 ) ;
}
static int F_33 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_100 ;
struct V_32 * V_33 = F_16 ( V_2 ) ;
unsigned long V_43 ;
int V_5 ;
unsigned long V_37 ;
V_5 = F_7 ( V_2 , & V_37 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 ,
L_18 , V_5 ) ;
return V_5 ;
}
F_18 ( & V_33 -> V_38 , V_43 ) ;
V_33 -> V_37 = V_37 ;
F_19 ( & V_33 -> V_38 , V_43 ) ;
F_21 ( & V_2 -> V_7 , L_8 , V_55 , V_37 ) ;
return ( int ) V_37 ;
}
