static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_2 * V_8 ;
int V_9 , V_10 , V_11 ;
V_11 = ( ( ( V_5 - 1 ) | 3 ) + 1 ) / 4 ;
V_8 = F_2 ( V_11 , sizeof( T_2 ) , V_12 ) ;
if ( ! V_8 ) {
F_3 ( & V_2 -> V_13 , L_1 , V_14 ) ;
return - V_15 ;
}
V_9 = F_4 ( V_7 -> V_13 , F_5 ( V_7 -> V_13 , 0 ) ,
V_3 , V_16 , 0x0000 ,
0 , V_8 , V_5 , 300 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
V_4 [ V_10 ] = F_6 ( V_8 [ V_10 ] ) ;
F_7 ( V_8 ) ;
if ( V_9 != V_5 ) {
F_8 ( L_2
L_3 ,
V_14 , V_3 , V_5 , V_9 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_2 * V_8 ;
int V_9 , V_10 , V_11 ;
V_11 = ( ( ( V_5 - 1 ) | 3 ) + 1 ) / 4 ;
V_8 = F_10 ( V_11 * sizeof( T_2 ) , V_12 ) ;
if ( ! V_8 ) {
F_3 ( & V_2 -> V_13 , L_1 ,
V_14 ) ;
return - V_15 ;
}
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
V_8 [ V_10 ] = F_11 ( V_4 [ V_10 ] ) ;
if ( V_5 > 2 ) {
V_9 = F_4 ( V_7 -> V_13 ,
F_12 ( V_7 -> V_13 , 0 ) ,
V_3 , V_18 , 0x0000 ,
0 , V_8 , V_5 , 300 ) ;
} else {
V_9 = F_4 ( V_7 -> V_13 ,
F_12 ( V_7 -> V_13 , 0 ) ,
V_3 , V_18 , V_4 [ 0 ] ,
0 , NULL , 0 , 300 ) ;
}
F_7 ( V_8 ) ;
if ( ( V_5 > 2 && V_9 != V_5 ) || V_9 < 0 ) {
F_8 ( L_4
L_3 ,
V_14 , V_3 , V_5 , V_9 ) ;
return - V_17 ;
}
return 0 ;
}
static inline int F_13 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
return F_9 ( V_2 , V_3 , & V_4 , 2 ) ;
}
static unsigned int F_14 ( unsigned int V_19 ) {
if ( V_19 <= 56 ) V_19 = 0 ;
else if ( V_19 <= 300 ) V_19 = 300 ;
else if ( V_19 <= 600 ) V_19 = 600 ;
else if ( V_19 <= 1200 ) V_19 = 1200 ;
else if ( V_19 <= 1800 ) V_19 = 1800 ;
else if ( V_19 <= 2400 ) V_19 = 2400 ;
else if ( V_19 <= 4000 ) V_19 = 4000 ;
else if ( V_19 <= 4803 ) V_19 = 4800 ;
else if ( V_19 <= 7207 ) V_19 = 7200 ;
else if ( V_19 <= 9612 ) V_19 = 9600 ;
else if ( V_19 <= 14428 ) V_19 = 14400 ;
else if ( V_19 <= 16062 ) V_19 = 16000 ;
else if ( V_19 <= 19250 ) V_19 = 19200 ;
else if ( V_19 <= 28912 ) V_19 = 28800 ;
else if ( V_19 <= 38601 ) V_19 = 38400 ;
else if ( V_19 <= 51558 ) V_19 = 51200 ;
else if ( V_19 <= 56280 ) V_19 = 56000 ;
else if ( V_19 <= 58053 ) V_19 = 57600 ;
else if ( V_19 <= 64111 ) V_19 = 64000 ;
else if ( V_19 <= 77608 ) V_19 = 76800 ;
else if ( V_19 <= 117028 ) V_19 = 115200 ;
else if ( V_19 <= 129347 ) V_19 = 128000 ;
else if ( V_19 <= 156868 ) V_19 = 153600 ;
else if ( V_19 <= 237832 ) V_19 = 230400 ;
else if ( V_19 <= 254234 ) V_19 = 250000 ;
else if ( V_19 <= 273066 ) V_19 = 256000 ;
else if ( V_19 <= 491520 ) V_19 = 460800 ;
else if ( V_19 <= 567138 ) V_19 = 500000 ;
else if ( V_19 <= 670254 ) V_19 = 576000 ;
else if ( V_19 <= 1053257 ) V_19 = 921600 ;
else if ( V_19 <= 1474560 ) V_19 = 1228800 ;
else if ( V_19 <= 2457600 ) V_19 = 1843200 ;
else V_19 = 3686400 ;
return V_19 ;
}
static int F_15 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
int V_9 ;
F_8 ( L_5 , V_14 , V_2 -> V_22 ) ;
if ( F_13 ( V_2 , V_23 , V_24 ) ) {
F_3 ( & V_2 -> V_13 , L_6 ,
V_14 ) ;
return - V_17 ;
}
V_9 = F_16 ( V_21 , V_2 ) ;
if ( V_9 )
return V_9 ;
F_17 ( V_21 , V_2 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_8 ( L_5 , V_14 , V_2 -> V_22 ) ;
F_19 ( V_2 ) ;
F_20 ( & V_2 -> V_7 -> V_25 ) ;
if ( ! V_2 -> V_7 -> V_26 )
F_13 ( V_2 , V_23 , V_27 ) ;
F_21 ( & V_2 -> V_7 -> V_25 ) ;
}
static void F_17 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
unsigned int V_19 ;
if ( V_21 ) {
F_22 ( V_21 -> V_28 ,
& V_21 -> V_29 -> V_30 , & V_19 ) ;
F_23 ( V_21 , V_19 , V_19 ) ;
}
else {
unsigned int V_31 ;
V_31 = 0 ;
F_22 ( V_2 , & V_31 , & V_19 ) ;
}
}
static void F_22 ( struct V_1 * V_2 ,
unsigned int * V_32 , unsigned int * V_33 )
{
unsigned int V_31 , V_34 [ 4 ] ;
unsigned int V_19 ;
unsigned int V_35 ;
F_8 ( L_5 , V_14 , V_2 -> V_22 ) ;
F_1 ( V_2 , V_36 , & V_19 , 2 ) ;
if ( V_19 )
V_19 = F_14 ( ( V_37 + V_19 / 2 ) / V_19 ) ;
F_8 ( L_7 , V_14 , V_19 ) ;
* V_33 = V_19 ;
V_31 = * V_32 ;
F_1 ( V_2 , V_38 , & V_35 , 2 ) ;
V_31 &= ~ V_39 ;
switch ( V_35 & V_40 ) {
case V_41 :
F_8 ( L_8 , V_14 ) ;
V_31 |= V_42 ;
break;
case V_43 :
F_8 ( L_9 , V_14 ) ;
V_31 |= V_44 ;
break;
case V_45 :
F_8 ( L_10 , V_14 ) ;
V_31 |= V_46 ;
break;
case V_47 :
F_8 ( L_11 , V_14 ) ;
V_31 |= V_48 ;
break;
case V_49 :
F_8 ( L_12 ,
V_14 ) ;
V_31 |= V_48 ;
V_35 &= ~ V_40 ;
V_35 |= V_47 ;
F_9 ( V_2 , V_50 , & V_35 , 2 ) ;
break;
default:
F_8 ( L_13 , V_14 ) ;
V_31 |= V_48 ;
V_35 &= ~ V_40 ;
V_35 |= V_47 ;
F_9 ( V_2 , V_50 , & V_35 , 2 ) ;
break;
}
switch ( V_35 & V_51 ) {
case V_52 :
F_8 ( L_14 , V_14 ) ;
V_31 &= ~ V_53 ;
break;
case V_54 :
F_8 ( L_15 , V_14 ) ;
V_31 |= ( V_53 | V_55 ) ;
break;
case V_56 :
F_8 ( L_16 , V_14 ) ;
V_31 &= ~ V_55 ;
V_31 |= V_53 ;
break;
case V_57 :
F_8 ( L_17 ,
V_14 ) ;
V_31 &= ~ V_53 ;
V_35 &= ~ V_51 ;
F_9 ( V_2 , V_50 , & V_35 , 2 ) ;
break;
case V_58 :
F_8 ( L_18 ,
V_14 ) ;
V_31 &= ~ V_53 ;
V_35 &= ~ V_51 ;
F_9 ( V_2 , V_50 , & V_35 , 2 ) ;
break;
default:
F_8 ( L_19 , V_14 ) ;
V_31 &= ~ V_53 ;
V_35 &= ~ V_51 ;
F_9 ( V_2 , V_50 , & V_35 , 2 ) ;
break;
}
V_31 &= ~ V_59 ;
switch ( V_35 & V_60 ) {
case V_61 :
F_8 ( L_20 , V_14 ) ;
break;
case V_62 :
F_8 ( L_21 ,
V_14 ) ;
V_35 &= ~ V_60 ;
F_9 ( V_2 , V_50 , & V_35 , 2 ) ;
break;
case V_63 :
F_8 ( L_22 , V_14 ) ;
V_31 |= V_59 ;
break;
default:
F_8 ( L_23 ,
V_14 ) ;
V_35 &= ~ V_60 ;
F_9 ( V_2 , V_50 , & V_35 , 2 ) ;
break;
}
F_1 ( V_2 , V_64 , V_34 , 16 ) ;
if ( V_34 [ 0 ] & 0x0008 ) {
F_8 ( L_24 , V_14 ) ;
V_31 |= V_65 ;
} else {
F_8 ( L_25 , V_14 ) ;
V_31 &= ~ V_65 ;
}
* V_32 = V_31 ;
}
static void F_24 ( struct V_20 * V_21 ,
struct V_1 * V_2 , struct V_66 * V_67 )
{
unsigned int V_31 , V_68 ;
unsigned int V_19 = 0 , V_35 ;
unsigned int V_34 [ 4 ] ;
F_8 ( L_5 , V_14 , V_2 -> V_22 ) ;
if ( ! V_21 )
return;
V_21 -> V_29 -> V_30 &= ~ V_69 ;
V_31 = V_21 -> V_29 -> V_30 ;
V_68 = V_67 -> V_30 ;
V_19 = F_14 ( F_25 ( V_21 ) ) ;
if ( V_19 != F_26 ( V_67 ) && V_19 != 0 ) {
F_8 ( L_26 , V_14 ,
V_19 ) ;
if ( F_13 ( V_2 , V_70 ,
( ( V_37 + V_19 / 2 ) / V_19 ) ) ) {
F_8 ( L_27 ) ;
V_19 = F_26 ( V_67 ) ;
}
}
F_23 ( V_21 , V_19 , V_19 ) ;
if ( ( V_31 & V_39 ) != ( V_68 & V_39 ) ) {
F_1 ( V_2 , V_38 , & V_35 , 2 ) ;
V_35 &= ~ V_40 ;
switch ( V_31 & V_39 ) {
case V_42 :
V_35 |= V_41 ;
F_8 ( L_8 , V_14 ) ;
break;
case V_44 :
V_35 |= V_43 ;
F_8 ( L_9 , V_14 ) ;
break;
case V_46 :
V_35 |= V_45 ;
F_8 ( L_10 , V_14 ) ;
break;
case V_48 :
V_35 |= V_47 ;
F_8 ( L_11 , V_14 ) ;
break;
default:
F_8 ( L_28
L_29
L_30 ) ;
V_35 |= V_47 ;
break;
}
if ( F_9 ( V_2 , V_50 , & V_35 , 2 ) )
F_8 ( L_31
L_32 ) ;
}
if ( ( V_31 & ( V_53 | V_55 ) ) != ( V_68 & ( V_53 | V_55 ) ) ) {
F_1 ( V_2 , V_38 , & V_35 , 2 ) ;
V_35 &= ~ V_51 ;
if ( V_31 & V_53 ) {
if ( V_31 & V_55 ) {
V_35 |= V_54 ;
F_8 ( L_15 , V_14 ) ;
} else {
V_35 |= V_56 ;
F_8 ( L_16 , V_14 ) ;
}
}
if ( F_9 ( V_2 , V_50 , & V_35 , 2 ) )
F_8 ( L_33
L_34 ) ;
}
if ( ( V_31 & V_59 ) != ( V_68 & V_59 ) ) {
F_1 ( V_2 , V_38 , & V_35 , 2 ) ;
V_35 &= ~ V_60 ;
if ( V_31 & V_59 ) {
V_35 |= V_63 ;
F_8 ( L_22 , V_14 ) ;
} else {
V_35 |= V_61 ;
F_8 ( L_20 , V_14 ) ;
}
if ( F_9 ( V_2 , V_50 , & V_35 , 2 ) )
F_8 ( L_35
L_32 ) ;
}
if ( ( V_31 & V_65 ) != ( V_68 & V_65 ) ) {
F_1 ( V_2 , V_64 , V_34 , 16 ) ;
F_8 ( L_36 ,
V_14 , V_34 [ 0 ] , V_34 [ 1 ] ,
V_34 [ 2 ] , V_34 [ 3 ] ) ;
if ( V_31 & V_65 ) {
V_34 [ 0 ] &= ~ 0x7B ;
V_34 [ 0 ] |= 0x09 ;
V_34 [ 1 ] = 0x80 ;
F_8 ( L_24 , V_14 ) ;
} else {
V_34 [ 0 ] &= ~ 0x7B ;
V_34 [ 0 ] |= 0x01 ;
V_34 [ 1 ] |= 0x40 ;
F_8 ( L_25 , V_14 ) ;
}
F_8 ( L_37 ,
V_14 , V_34 [ 0 ] , V_34 [ 1 ] ,
V_34 [ 2 ] , V_34 [ 3 ] ) ;
F_9 ( V_2 , V_71 , V_34 , 16 ) ;
}
}
static int F_27 ( struct V_20 * V_21 ,
unsigned int V_72 , unsigned int V_73 )
{
struct V_1 * V_2 = V_21 -> V_28 ;
return F_28 ( V_2 , V_72 , V_73 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned int V_72 , unsigned int V_73 )
{
unsigned int V_74 = 0 ;
F_8 ( L_5 , V_14 , V_2 -> V_22 ) ;
if ( V_72 & V_75 ) {
V_74 |= V_76 ;
V_74 |= V_77 ;
}
if ( V_72 & V_78 ) {
V_74 |= V_79 ;
V_74 |= V_80 ;
}
if ( V_73 & V_75 ) {
V_74 &= ~ V_76 ;
V_74 |= V_77 ;
}
if ( V_73 & V_78 ) {
V_74 &= ~ V_79 ;
V_74 |= V_80 ;
}
F_8 ( L_38 , V_14 , V_74 ) ;
return F_9 ( V_2 , V_81 , & V_74 , 2 ) ;
}
static void F_29 ( struct V_1 * V_82 , int V_83 )
{
if ( V_83 )
F_28 ( V_82 , V_78 | V_75 , 0 ) ;
else
F_28 ( V_82 , 0 , V_78 | V_75 ) ;
}
static int F_30 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_28 ;
unsigned int V_74 ;
int V_9 ;
F_8 ( L_5 , V_14 , V_2 -> V_22 ) ;
F_1 ( V_2 , V_84 , & V_74 , 1 ) ;
V_9 = ( ( V_74 & V_79 ) ? V_78 : 0 )
| ( ( V_74 & V_76 ) ? V_75 : 0 )
| ( ( V_74 & V_85 ) ? V_86 : 0 )
| ( ( V_74 & V_87 ) ? V_88 : 0 )
| ( ( V_74 & V_89 ) ? V_90 : 0 )
| ( ( V_74 & V_91 ) ? V_92 : 0 ) ;
F_8 ( L_39 , V_14 , V_74 ) ;
return V_9 ;
}
static void F_31 ( struct V_20 * V_21 , int V_93 )
{
struct V_1 * V_2 = V_21 -> V_28 ;
unsigned int V_94 ;
F_8 ( L_5 , V_14 , V_2 -> V_22 ) ;
if ( V_93 == 0 )
V_94 = V_95 ;
else
V_94 = V_96 ;
F_8 ( L_40 , V_14 ,
V_94 == V_95 ? L_41 : L_42 ) ;
F_9 ( V_2 , V_97 , & V_94 , 2 ) ;
}
static int F_32 ( struct V_6 * V_7 )
{
F_33 ( V_7 -> V_13 ) ;
return 0 ;
}
static int T_3 F_34 ( void )
{
int V_98 ;
V_98 = F_35 ( & V_99 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_36 ( & V_100 ) ;
if ( V_98 ) {
F_37 ( & V_99 ) ;
return V_98 ;
}
F_38 (KERN_INFO KBUILD_MODNAME L_43 DRIVER_VERSION L_44
DRIVER_DESC L_45 ) ;
return 0 ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_100 ) ;
F_37 ( & V_99 ) ;
}
