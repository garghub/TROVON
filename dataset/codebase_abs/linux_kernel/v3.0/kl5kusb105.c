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
static int F_12 ( struct V_32 * V_6 )
{
struct V_33 * V_34 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_6 -> V_36 ; V_35 ++ ) {
V_34 = F_8 ( sizeof( struct V_33 ) ,
V_27 ) ;
if ( ! V_34 ) {
F_13 ( L_7 , V_28 ) ;
V_35 -- ;
goto V_37;
}
V_34 -> V_38 . V_13 = 5 ;
V_34 -> V_38 . V_14 = V_39 ;
V_34 -> V_38 . V_15 = V_40 ;
V_34 -> V_38 . V_16 = 0 ;
V_34 -> V_38 . V_17 = 1 ;
V_34 -> V_41 = 0 ;
F_14 ( V_6 -> V_2 [ V_35 ] , V_34 ) ;
F_15 ( & V_34 -> V_42 ) ;
F_16 ( & V_6 -> V_2 [ V_35 ] -> V_43 ) ;
}
return 0 ;
V_37:
for (; V_35 >= 0 ; V_35 -- ) {
V_34 = F_17 ( V_6 -> V_2 [ V_35 ] ) ;
F_11 ( V_34 ) ;
F_14 ( V_6 -> V_2 [ V_35 ] , NULL ) ;
}
return - V_29 ;
}
static void F_18 ( struct V_32 * V_6 )
{
int V_35 ;
F_13 ( L_8 , V_28 ) ;
for ( V_35 = 0 ; V_35 < V_6 -> V_36 ; ++ V_35 )
F_11 ( F_17 ( V_6 -> V_2 [ V_35 ] ) ) ;
}
static int F_19 ( struct V_44 * V_45 , struct V_1 * V_2 )
{
struct V_33 * V_34 = F_17 ( V_2 ) ;
int V_46 = 0 ;
int V_5 ;
int V_35 ;
unsigned long V_41 ;
struct V_3 * V_38 ;
unsigned long V_47 ;
F_13 ( L_9 , V_28 , V_2 -> V_48 ) ;
V_38 = F_8 ( sizeof( * V_38 ) , V_27 ) ;
if ( ! V_38 ) {
F_4 ( & V_2 -> V_7 , L_10 ,
V_28 ) ;
return - V_29 ;
}
V_38 -> V_13 = 5 ;
V_38 -> V_14 = V_39 ;
V_38 -> V_15 = V_40 ;
V_38 -> V_16 = 0 ;
V_38 -> V_17 = 1 ;
F_1 ( V_2 , V_38 ) ;
F_20 ( & V_34 -> V_42 , V_47 ) ;
V_34 -> V_49 . V_50 = V_45 -> V_49 -> V_50 ;
V_34 -> V_49 . V_51 = V_45 -> V_49 -> V_51 ;
V_34 -> V_49 . V_52 = V_45 -> V_49 -> V_52 ;
V_34 -> V_49 . V_53 = V_45 -> V_49 -> V_53 ;
for ( V_35 = 0 ; V_35 < V_54 ; V_35 ++ )
V_34 -> V_49 . V_55 [ V_35 ] = V_45 -> V_49 -> V_55 [ V_35 ] ;
V_34 -> V_38 . V_13 = V_38 -> V_13 ;
V_34 -> V_38 . V_14 = V_38 -> V_14 ;
V_34 -> V_38 . V_15 = V_38 -> V_15 ;
V_34 -> V_38 . V_16 = V_38 -> V_16 ;
V_34 -> V_38 . V_17 = V_38 -> V_17 ;
F_21 ( & V_34 -> V_42 , V_47 ) ;
V_5 = F_22 ( V_45 , V_2 ) ;
if ( V_5 ) {
V_46 = V_5 ;
goto exit;
}
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_56 ,
V_9 | V_10 | V_11 ,
V_57 ,
0 ,
NULL ,
0 ,
V_12 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 , L_11 , V_5 ) ;
V_46 = V_5 ;
} else
F_13 ( L_12 , V_28 ) ;
V_5 = F_7 ( V_2 , & V_41 ) ;
if ( V_5 >= 0 ) {
F_20 ( & V_34 -> V_42 , V_47 ) ;
V_34 -> V_41 = V_41 ;
F_21 ( & V_34 -> V_42 , V_47 ) ;
F_13 ( L_13 , V_28 , V_41 ) ;
V_46 = 0 ;
} else
V_46 = V_5 ;
exit:
F_11 ( V_38 ) ;
return V_46 ;
}
static void F_23 ( struct V_1 * V_2 )
{
int V_5 ;
F_13 ( L_9 , V_28 , V_2 -> V_48 ) ;
F_24 ( & V_2 -> V_6 -> V_58 ) ;
if ( ! V_2 -> V_6 -> V_59 ) {
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_56 ,
V_9 | V_10 ,
V_60 ,
0 ,
NULL , 0 ,
V_12 ) ;
if ( V_5 < 0 )
F_4 ( & V_2 -> V_7 ,
L_14 , V_5 ) ;
}
F_25 ( & V_2 -> V_6 -> V_58 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 -> V_61 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
void * V_62 , T_3 V_63 )
{
unsigned char * V_64 = V_62 ;
int V_65 ;
V_65 = F_29 ( & V_2 -> V_66 , V_64 + V_67 , V_63 ,
& V_2 -> V_42 ) ;
F_30 ( V_65 , V_64 ) ;
return V_65 + V_67 ;
}
static void F_31 ( struct V_68 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
unsigned char * V_70 = V_68 -> V_71 ;
struct V_44 * V_45 ;
unsigned V_72 ;
if ( ! V_68 -> V_73 )
return;
if ( V_68 -> V_73 <= V_67 ) {
F_13 ( L_15 , V_28 ) ;
return;
}
V_45 = F_32 ( & V_2 -> V_2 ) ;
if ( ! V_45 )
return;
V_72 = F_10 ( V_70 ) ;
if ( V_72 > V_68 -> V_73 - V_67 ) {
F_13 ( L_16 , V_28 ) ;
V_72 = V_68 -> V_73 - V_67 ;
}
F_33 ( V_45 , V_70 + V_67 , V_72 ) ;
F_34 ( V_45 ) ;
F_35 ( V_45 ) ;
}
static void F_36 ( struct V_44 * V_45 ,
struct V_1 * V_2 ,
struct V_74 * V_75 )
{
struct V_33 * V_34 = F_17 ( V_2 ) ;
unsigned int V_76 = V_45 -> V_49 -> V_50 ;
unsigned int V_77 = V_75 -> V_50 ;
unsigned int V_78 = V_45 -> V_49 -> V_52 ;
unsigned int V_79 = V_75 -> V_52 ;
struct V_3 * V_38 ;
unsigned long V_47 ;
T_4 V_80 ;
V_38 = F_8 ( sizeof( * V_38 ) , V_27 ) ;
if ( ! V_38 ) {
F_4 ( & V_2 -> V_7 , L_10 ,
V_28 ) ;
return;
}
F_20 ( & V_34 -> V_42 , V_47 ) ;
V_80 = F_37 ( V_45 ) ;
if ( ( V_78 & V_81 ) != ( V_79 & V_81 ) ) {
if ( ( V_79 & V_81 ) == V_82 ) {
F_13 ( L_17 , V_28 ) ;
#if 0
priv->control_state |= TIOCM_DTR;
if (!(old_cflag & CRTSCTS))
priv->control_state |= TIOCM_RTS;
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
}
switch ( V_80 ) {
case 0 :
break;
case 1200 :
V_34 -> V_38 . V_14 = V_83 ;
break;
case 2400 :
V_34 -> V_38 . V_14 = V_84 ;
break;
case 4800 :
V_34 -> V_38 . V_14 = V_85 ;
break;
case 9600 :
V_34 -> V_38 . V_14 = V_39 ;
break;
case 19200 :
V_34 -> V_38 . V_14 = V_86 ;
break;
case 38400 :
V_34 -> V_38 . V_14 = V_87 ;
break;
case 57600 :
V_34 -> V_38 . V_14 = V_88 ;
break;
case 115200 :
V_34 -> V_38 . V_14 = V_89 ;
break;
default:
F_13 ( L_18
L_19 ) ;
V_34 -> V_38 . V_14 = V_39 ;
V_80 = 9600 ;
break;
}
if ( ( V_78 & V_81 ) == V_82 ) {
F_13 ( L_20 , V_28 ) ;
;
#if 0
priv->control_state &= ~(TIOCM_DTR | TIOCM_RTS);
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
F_38 ( V_45 , V_80 , V_80 ) ;
if ( ( V_78 & V_90 ) != ( V_79 & V_90 ) ) {
switch ( V_78 & V_90 ) {
case V_91 :
F_13 ( L_21 , V_28 ) ;
F_21 ( & V_34 -> V_42 , V_47 ) ;
goto V_92;
case V_93 :
F_13 ( L_22 , V_28 ) ;
F_21 ( & V_34 -> V_42 , V_47 ) ;
goto V_92;
case V_94 :
V_34 -> V_38 . V_15 = V_95 ;
break;
case V_96 :
V_34 -> V_38 . V_15 = V_40 ;
break;
default:
F_4 ( & V_2 -> V_7 ,
L_23 ) ;
V_34 -> V_38 . V_15 = V_40 ;
break;
}
}
if ( ( V_78 & ( V_97 | V_98 ) ) != ( V_79 & ( V_97 | V_98 ) )
|| ( V_78 & V_99 ) != ( V_79 & V_99 ) ) {
V_45 -> V_49 -> V_52 &= ~ ( V_97 | V_98 | V_99 ) ;
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
if ( ( V_76 & V_100 ) != ( V_77 & V_100 )
|| ( V_76 & V_101 ) != ( V_77 & V_101 )
|| ( V_78 & V_102 ) != ( V_79 & V_102 ) ) {
V_45 -> V_49 -> V_52 &= ~ V_102 ;
#if 0
if ((iflag & IXOFF) || (iflag & IXON) || (cflag & CRTSCTS))
priv->control_state |= TIOCM_DTR | TIOCM_RTS;
else
priv->control_state &= ~(TIOCM_DTR | TIOCM_RTS);
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
;
}
memcpy ( V_38 , & V_34 -> V_38 , sizeof( * V_38 ) ) ;
F_21 ( & V_34 -> V_42 , V_47 ) ;
F_1 ( V_2 , V_38 ) ;
V_92:
F_11 ( V_38 ) ;
}
static int F_39 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_103 ;
struct V_33 * V_34 = F_17 ( V_2 ) ;
unsigned long V_47 ;
int V_5 ;
unsigned long V_41 ;
F_13 ( L_24 , V_28 ) ;
V_5 = F_7 ( V_2 , & V_41 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 ,
L_25 , V_5 ) ;
return V_5 ;
}
F_20 ( & V_34 -> V_42 , V_47 ) ;
V_34 -> V_41 = V_41 ;
F_21 ( & V_34 -> V_42 , V_47 ) ;
F_13 ( L_13 , V_28 , V_41 ) ;
return ( int ) V_41 ;
}
static int F_40 ( struct V_44 * V_45 ,
unsigned int V_104 , unsigned int V_105 )
{
int V_46 = - V_106 ;
F_13 ( L_8 , V_28 ) ;
return V_46 ;
}
static int T_5 F_41 ( void )
{
int V_46 ;
V_46 = F_42 ( & V_107 ) ;
if ( V_46 )
goto V_108;
V_46 = F_43 ( & V_109 ) ;
if ( V_46 )
goto V_110;
F_44 (KERN_INFO KBUILD_MODNAME L_26 DRIVER_VERSION L_27
DRIVER_DESC L_28 ) ;
return 0 ;
V_110:
F_45 ( & V_107 ) ;
V_108:
return V_46 ;
}
static void T_6 F_46 ( void )
{
F_47 ( & V_109 ) ;
F_45 ( & V_107 ) ;
}
