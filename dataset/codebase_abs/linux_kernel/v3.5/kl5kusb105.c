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
V_38 = F_8 ( sizeof( * V_38 ) , V_27 ) ;
if ( ! V_38 ) {
F_4 ( & V_2 -> V_7 , L_8 ,
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
V_34 -> V_48 . V_49 = V_45 -> V_48 -> V_49 ;
V_34 -> V_48 . V_50 = V_45 -> V_48 -> V_50 ;
V_34 -> V_48 . V_51 = V_45 -> V_48 -> V_51 ;
V_34 -> V_48 . V_52 = V_45 -> V_48 -> V_52 ;
for ( V_35 = 0 ; V_35 < V_53 ; V_35 ++ )
V_34 -> V_48 . V_54 [ V_35 ] = V_45 -> V_48 -> V_54 [ V_35 ] ;
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
V_55 ,
V_9 | V_10 | V_11 ,
V_56 ,
0 ,
NULL ,
0 ,
V_12 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 , L_9 , V_5 ) ;
V_46 = V_5 ;
} else
F_13 ( L_10 , V_28 ) ;
V_5 = F_7 ( V_2 , & V_41 ) ;
if ( V_5 >= 0 ) {
F_20 ( & V_34 -> V_42 , V_47 ) ;
V_34 -> V_41 = V_41 ;
F_21 ( & V_34 -> V_42 , V_47 ) ;
F_13 ( L_11 , V_28 , V_41 ) ;
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
F_24 ( & V_2 -> V_6 -> V_57 ) ;
if ( ! V_2 -> V_6 -> V_58 ) {
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_55 ,
V_9 | V_10 ,
V_59 ,
0 ,
NULL , 0 ,
V_12 ) ;
if ( V_5 < 0 )
F_4 ( & V_2 -> V_7 ,
L_12 , V_5 ) ;
}
F_25 ( & V_2 -> V_6 -> V_57 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 -> V_60 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
void * V_61 , T_3 V_62 )
{
unsigned char * V_63 = V_61 ;
int V_64 ;
V_64 = F_29 ( & V_2 -> V_65 , V_63 + V_66 , V_62 ,
& V_2 -> V_42 ) ;
F_30 ( V_64 , V_63 ) ;
return V_64 + V_66 ;
}
static void F_31 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_68 ;
unsigned char * V_69 = V_67 -> V_70 ;
struct V_44 * V_45 ;
unsigned V_71 ;
if ( ! V_67 -> V_72 )
return;
if ( V_67 -> V_72 <= V_66 ) {
F_13 ( L_13 , V_28 ) ;
return;
}
V_45 = F_32 ( & V_2 -> V_2 ) ;
if ( ! V_45 )
return;
V_71 = F_10 ( V_69 ) ;
if ( V_71 > V_67 -> V_72 - V_66 ) {
F_13 ( L_14 , V_28 ) ;
V_71 = V_67 -> V_72 - V_66 ;
}
F_33 ( V_45 , V_69 + V_66 , V_71 ) ;
F_34 ( V_45 ) ;
F_35 ( V_45 ) ;
}
static void F_36 ( struct V_44 * V_45 ,
struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_33 * V_34 = F_17 ( V_2 ) ;
unsigned int V_75 = V_45 -> V_48 -> V_49 ;
unsigned int V_76 = V_74 -> V_49 ;
unsigned int V_77 = V_45 -> V_48 -> V_51 ;
unsigned int V_78 = V_74 -> V_51 ;
struct V_3 * V_38 ;
unsigned long V_47 ;
T_4 V_79 ;
V_38 = F_8 ( sizeof( * V_38 ) , V_27 ) ;
if ( ! V_38 ) {
F_4 ( & V_2 -> V_7 , L_8 ,
V_28 ) ;
return;
}
F_20 ( & V_34 -> V_42 , V_47 ) ;
V_79 = F_37 ( V_45 ) ;
if ( ( V_77 & V_80 ) != ( V_78 & V_80 ) ) {
if ( ( V_78 & V_80 ) == V_81 ) {
F_13 ( L_15 , V_28 ) ;
#if 0
priv->control_state |= TIOCM_DTR;
if (!(old_cflag & CRTSCTS))
priv->control_state |= TIOCM_RTS;
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
}
switch ( V_79 ) {
case 0 :
break;
case 1200 :
V_34 -> V_38 . V_14 = V_82 ;
break;
case 2400 :
V_34 -> V_38 . V_14 = V_83 ;
break;
case 4800 :
V_34 -> V_38 . V_14 = V_84 ;
break;
case 9600 :
V_34 -> V_38 . V_14 = V_39 ;
break;
case 19200 :
V_34 -> V_38 . V_14 = V_85 ;
break;
case 38400 :
V_34 -> V_38 . V_14 = V_86 ;
break;
case 57600 :
V_34 -> V_38 . V_14 = V_87 ;
break;
case 115200 :
V_34 -> V_38 . V_14 = V_88 ;
break;
default:
F_13 ( L_16
L_17 ) ;
V_34 -> V_38 . V_14 = V_39 ;
V_79 = 9600 ;
break;
}
if ( ( V_77 & V_80 ) == V_81 ) {
F_13 ( L_18 , V_28 ) ;
;
#if 0
priv->control_state &= ~(TIOCM_DTR | TIOCM_RTS);
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
F_38 ( V_45 , V_79 , V_79 ) ;
if ( ( V_77 & V_89 ) != ( V_78 & V_89 ) ) {
switch ( V_77 & V_89 ) {
case V_90 :
F_13 ( L_19 , V_28 ) ;
F_21 ( & V_34 -> V_42 , V_47 ) ;
goto V_91;
case V_92 :
F_13 ( L_20 , V_28 ) ;
F_21 ( & V_34 -> V_42 , V_47 ) ;
goto V_91;
case V_93 :
V_34 -> V_38 . V_15 = V_94 ;
break;
case V_95 :
V_34 -> V_38 . V_15 = V_40 ;
break;
default:
F_4 ( & V_2 -> V_7 ,
L_21 ) ;
V_34 -> V_38 . V_15 = V_40 ;
break;
}
}
if ( ( V_77 & ( V_96 | V_97 ) ) != ( V_78 & ( V_96 | V_97 ) )
|| ( V_77 & V_98 ) != ( V_78 & V_98 ) ) {
V_45 -> V_48 -> V_51 &= ~ ( V_96 | V_97 | V_98 ) ;
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
if ( ( V_75 & V_99 ) != ( V_76 & V_99 )
|| ( V_75 & V_100 ) != ( V_76 & V_100 )
|| ( V_77 & V_101 ) != ( V_78 & V_101 ) ) {
V_45 -> V_48 -> V_51 &= ~ V_101 ;
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
V_91:
F_11 ( V_38 ) ;
}
static int F_39 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_102 ;
struct V_33 * V_34 = F_17 ( V_2 ) ;
unsigned long V_47 ;
int V_5 ;
unsigned long V_41 ;
V_5 = F_7 ( V_2 , & V_41 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 ,
L_22 , V_5 ) ;
return V_5 ;
}
F_20 ( & V_34 -> V_42 , V_47 ) ;
V_34 -> V_41 = V_41 ;
F_21 ( & V_34 -> V_42 , V_47 ) ;
F_13 ( L_11 , V_28 , V_41 ) ;
return ( int ) V_41 ;
}
static int F_40 ( struct V_44 * V_45 ,
unsigned int V_103 , unsigned int V_104 )
{
int V_46 = - V_105 ;
return V_46 ;
}
