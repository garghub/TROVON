static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_2 * V_10 ;
int V_11 , V_12 , V_13 ;
V_13 = ( ( ( V_5 - 1 ) | 3 ) + 1 ) / 4 ;
V_10 = F_3 ( V_13 , sizeof( T_2 ) , V_14 ) ;
if ( ! V_10 )
return - V_15 ;
V_11 = F_4 ( V_7 -> V_16 , F_5 ( V_7 -> V_16 , 0 ) ,
V_3 , V_17 , 0x0000 ,
V_9 -> V_18 , V_10 , V_5 ,
V_19 ) ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
V_4 [ V_12 ] = F_6 ( V_10 [ V_12 ] ) ;
F_7 ( V_10 ) ;
if ( V_11 != V_5 ) {
F_8 ( & V_2 -> V_16 , L_1 ,
V_20 , V_3 , V_5 , V_11 ) ;
if ( V_11 > 0 )
V_11 = - V_21 ;
return V_11 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_2 * V_10 ;
int V_11 , V_12 , V_13 ;
V_13 = ( ( ( V_5 - 1 ) | 3 ) + 1 ) / 4 ;
V_10 = F_10 ( V_13 * sizeof( T_2 ) , V_14 ) ;
if ( ! V_10 )
return - V_15 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
V_10 [ V_12 ] = F_11 ( V_4 [ V_12 ] ) ;
if ( V_5 > 2 ) {
V_11 = F_4 ( V_7 -> V_16 ,
F_12 ( V_7 -> V_16 , 0 ) ,
V_3 , V_22 , 0x0000 ,
V_9 -> V_18 , V_10 , V_5 ,
V_23 ) ;
} else {
V_11 = F_4 ( V_7 -> V_16 ,
F_12 ( V_7 -> V_16 , 0 ) ,
V_3 , V_22 , V_4 [ 0 ] ,
V_9 -> V_18 , NULL , 0 ,
V_23 ) ;
}
F_7 ( V_10 ) ;
if ( ( V_5 > 2 && V_11 != V_5 ) || V_11 < 0 ) {
F_8 ( & V_2 -> V_16 , L_2 ,
V_20 , V_3 , V_5 , V_11 ) ;
if ( V_11 > 0 )
V_11 = - V_21 ;
return V_11 ;
}
return 0 ;
}
static inline int F_13 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
return F_9 ( V_2 , V_3 , & V_4 , 2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned int V_24 ;
unsigned int V_25 ;
int V_26 ;
V_26 = F_1 ( V_2 , V_27 , & V_24 , 2 ) ;
if ( V_26 )
return V_26 ;
V_25 = 0x800 ;
V_26 = F_9 ( V_2 , V_28 , & V_25 , 2 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_1 ( V_2 , V_27 , & V_25 , 2 ) ;
if ( V_26 )
return V_26 ;
if ( V_25 == 8 ) {
V_9 -> V_29 = true ;
V_24 = F_15 ( ( V_30 ) V_24 ) ;
}
return F_9 ( V_2 , V_28 , & V_24 , 2 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int * V_31 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_26 ;
V_26 = F_1 ( V_2 , V_27 , V_31 , 2 ) ;
if ( V_26 )
return V_26 ;
if ( V_9 -> V_29 )
* V_31 = F_15 ( ( V_30 ) ( * V_31 ) ) ;
return 0 ;
}
static unsigned int F_17 ( unsigned int V_32 )
{
if ( V_32 <= 300 )
V_32 = 300 ;
else if ( V_32 <= 600 ) V_32 = 600 ;
else if ( V_32 <= 1200 ) V_32 = 1200 ;
else if ( V_32 <= 1800 ) V_32 = 1800 ;
else if ( V_32 <= 2400 ) V_32 = 2400 ;
else if ( V_32 <= 4000 ) V_32 = 4000 ;
else if ( V_32 <= 4803 ) V_32 = 4800 ;
else if ( V_32 <= 7207 ) V_32 = 7200 ;
else if ( V_32 <= 9612 ) V_32 = 9600 ;
else if ( V_32 <= 14428 ) V_32 = 14400 ;
else if ( V_32 <= 16062 ) V_32 = 16000 ;
else if ( V_32 <= 19250 ) V_32 = 19200 ;
else if ( V_32 <= 28912 ) V_32 = 28800 ;
else if ( V_32 <= 38601 ) V_32 = 38400 ;
else if ( V_32 <= 51558 ) V_32 = 51200 ;
else if ( V_32 <= 56280 ) V_32 = 56000 ;
else if ( V_32 <= 58053 ) V_32 = 57600 ;
else if ( V_32 <= 64111 ) V_32 = 64000 ;
else if ( V_32 <= 77608 ) V_32 = 76800 ;
else if ( V_32 <= 117028 ) V_32 = 115200 ;
else if ( V_32 <= 129347 ) V_32 = 128000 ;
else if ( V_32 <= 156868 ) V_32 = 153600 ;
else if ( V_32 <= 237832 ) V_32 = 230400 ;
else if ( V_32 <= 254234 ) V_32 = 250000 ;
else if ( V_32 <= 273066 ) V_32 = 256000 ;
else if ( V_32 <= 491520 ) V_32 = 460800 ;
else if ( V_32 <= 567138 ) V_32 = 500000 ;
else if ( V_32 <= 670254 ) V_32 = 576000 ;
else if ( V_32 < 1000000 )
V_32 = 921600 ;
else if ( V_32 > 2000000 )
V_32 = 2000000 ;
return V_32 ;
}
static int F_18 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_13 ( V_2 , V_35 ,
V_36 ) ;
if ( V_11 ) {
F_19 ( & V_2 -> V_16 , L_3 , V_20 ) ;
return V_11 ;
}
F_20 ( V_34 , V_2 ) ;
if ( V_34 )
F_21 ( V_34 , V_2 , NULL ) ;
return F_22 ( V_34 , V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned int V_37 ;
F_24 ( V_2 ) ;
V_37 = V_38 ;
F_9 ( V_2 , V_39 , & V_37 , 2 ) ;
F_13 ( V_2 , V_35 , V_40 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
T_3 * V_41 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_42 * V_43 ;
int V_11 ;
V_43 = F_10 ( sizeof( * V_43 ) , V_14 ) ;
if ( ! V_43 )
return - V_15 ;
V_11 = F_4 ( V_7 -> V_16 , F_5 ( V_7 -> V_16 , 0 ) ,
V_44 , V_17 ,
0 , V_9 -> V_18 , V_43 , sizeof( * V_43 ) ,
V_19 ) ;
if ( V_11 == sizeof( * V_43 ) ) {
* V_41 = F_6 ( V_43 -> V_45 ) ;
V_11 = 0 ;
} else {
F_19 ( & V_2 -> V_16 , L_4 , V_11 ) ;
if ( V_11 >= 0 )
V_11 = - V_21 ;
}
F_7 ( V_43 ) ;
return V_11 ;
}
static bool F_26 ( struct V_1 * V_2 )
{
int V_26 ;
T_3 V_41 ;
V_26 = F_25 ( V_2 , & V_41 ) ;
if ( V_26 )
return true ;
return ! V_41 ;
}
static void F_20 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
unsigned int V_32 ;
if ( V_34 ) {
F_27 ( V_34 -> V_46 ,
& V_34 -> V_47 . V_48 , & V_32 ) ;
F_28 ( V_34 , V_32 , V_32 ) ;
} else {
unsigned int V_49 ;
V_49 = 0 ;
F_27 ( V_2 , & V_49 , & V_32 ) ;
}
}
static void F_27 ( struct V_1 * V_2 ,
unsigned int * V_50 , unsigned int * V_51 )
{
struct V_52 * V_16 = & V_2 -> V_16 ;
unsigned int V_49 , V_53 [ 4 ] ;
unsigned int V_32 ;
unsigned int V_54 ;
F_1 ( V_2 , V_55 , & V_32 , 4 ) ;
F_8 ( V_16 , L_5 , V_20 , V_32 ) ;
* V_51 = V_32 ;
V_49 = * V_50 ;
F_16 ( V_2 , & V_54 ) ;
V_49 &= ~ V_56 ;
switch ( V_54 & V_57 ) {
case V_58 :
F_8 ( V_16 , L_6 , V_20 ) ;
V_49 |= V_59 ;
break;
case V_60 :
F_8 ( V_16 , L_7 , V_20 ) ;
V_49 |= V_61 ;
break;
case V_62 :
F_8 ( V_16 , L_8 , V_20 ) ;
V_49 |= V_63 ;
break;
case V_64 :
F_8 ( V_16 , L_9 , V_20 ) ;
V_49 |= V_65 ;
break;
case V_66 :
F_8 ( V_16 , L_10 , V_20 ) ;
V_49 |= V_65 ;
V_54 &= ~ V_57 ;
V_54 |= V_64 ;
F_9 ( V_2 , V_28 , & V_54 , 2 ) ;
break;
default:
F_8 ( V_16 , L_11 , V_20 ) ;
V_49 |= V_65 ;
V_54 &= ~ V_57 ;
V_54 |= V_64 ;
F_9 ( V_2 , V_28 , & V_54 , 2 ) ;
break;
}
switch ( V_54 & V_67 ) {
case V_68 :
F_8 ( V_16 , L_12 , V_20 ) ;
V_49 &= ~ V_69 ;
break;
case V_70 :
F_8 ( V_16 , L_13 , V_20 ) ;
V_49 |= ( V_69 | V_71 ) ;
break;
case V_72 :
F_8 ( V_16 , L_14 , V_20 ) ;
V_49 &= ~ V_71 ;
V_49 |= V_69 ;
break;
case V_73 :
F_8 ( V_16 , L_15 , V_20 ) ;
V_49 |= ( V_69 | V_71 | V_74 ) ;
break;
case V_75 :
F_8 ( V_16 , L_16 , V_20 ) ;
V_49 &= ~ V_71 ;
V_49 |= ( V_69 | V_74 ) ;
break;
default:
F_8 ( V_16 , L_17 , V_20 ) ;
V_49 &= ~ V_69 ;
V_54 &= ~ V_67 ;
F_9 ( V_2 , V_28 , & V_54 , 2 ) ;
break;
}
V_49 &= ~ V_76 ;
switch ( V_54 & V_77 ) {
case V_78 :
F_8 ( V_16 , L_18 , V_20 ) ;
break;
case V_79 :
F_8 ( V_16 , L_19 , V_20 ) ;
V_54 &= ~ V_77 ;
F_9 ( V_2 , V_28 , & V_54 , 2 ) ;
break;
case V_80 :
F_8 ( V_16 , L_20 , V_20 ) ;
V_49 |= V_76 ;
break;
default:
F_8 ( V_16 , L_21 , V_20 ) ;
V_54 &= ~ V_77 ;
F_9 ( V_2 , V_28 , & V_54 , 2 ) ;
break;
}
F_1 ( V_2 , V_81 , V_53 , 16 ) ;
if ( V_53 [ 0 ] & 0x0008 ) {
F_8 ( V_16 , L_22 , V_20 ) ;
V_49 |= V_82 ;
} else {
F_8 ( V_16 , L_23 , V_20 ) ;
V_49 &= ~ V_82 ;
}
* V_50 = V_49 ;
}
static void F_21 ( struct V_33 * V_34 ,
struct V_1 * V_2 , struct V_83 * V_84 )
{
T_3 V_32 ;
V_32 = V_34 -> V_47 . V_85 ;
V_32 = F_17 ( V_32 ) ;
F_8 ( & V_2 -> V_16 , L_24 , V_20 , V_32 ) ;
if ( F_9 ( V_2 , V_86 , & V_32 ,
sizeof( V_32 ) ) ) {
F_29 ( & V_2 -> V_16 , L_25 , V_32 ) ;
if ( V_84 )
V_32 = V_84 -> V_85 ;
else
V_32 = 9600 ;
}
F_28 ( V_34 , V_32 , V_32 ) ;
}
static void F_30 ( struct V_33 * V_34 ,
struct V_1 * V_2 , struct V_83 * V_84 )
{
struct V_52 * V_16 = & V_2 -> V_16 ;
unsigned int V_49 , V_87 ;
unsigned int V_54 ;
unsigned int V_53 [ 4 ] ;
V_49 = V_34 -> V_47 . V_48 ;
V_87 = V_84 -> V_48 ;
if ( V_34 -> V_47 . V_85 != V_84 -> V_85 )
F_21 ( V_34 , V_2 , V_84 ) ;
if ( ( V_49 & V_56 ) != ( V_87 & V_56 ) ) {
F_16 ( V_2 , & V_54 ) ;
V_54 &= ~ V_57 ;
switch ( V_49 & V_56 ) {
case V_59 :
V_54 |= V_58 ;
F_8 ( V_16 , L_6 , V_20 ) ;
break;
case V_61 :
V_54 |= V_60 ;
F_8 ( V_16 , L_7 , V_20 ) ;
break;
case V_63 :
V_54 |= V_62 ;
F_8 ( V_16 , L_8 , V_20 ) ;
break;
case V_65 :
V_54 |= V_64 ;
F_8 ( V_16 , L_9 , V_20 ) ;
break;
default:
F_8 ( V_16 , L_26 ) ;
V_54 |= V_64 ;
break;
}
if ( F_9 ( V_2 , V_28 , & V_54 , 2 ) )
F_8 ( V_16 , L_27 ) ;
}
if ( ( V_49 & ( V_69 | V_71 | V_74 ) ) !=
( V_87 & ( V_69 | V_71 | V_74 ) ) ) {
F_16 ( V_2 , & V_54 ) ;
V_54 &= ~ V_67 ;
if ( V_49 & V_69 ) {
if ( V_49 & V_74 ) {
if ( V_49 & V_71 ) {
V_54 |= V_73 ;
F_8 ( V_16 , L_15 , V_20 ) ;
} else {
V_54 |= V_75 ;
F_8 ( V_16 , L_16 , V_20 ) ;
}
} else {
if ( V_49 & V_71 ) {
V_54 |= V_70 ;
F_8 ( V_16 , L_13 , V_20 ) ;
} else {
V_54 |= V_72 ;
F_8 ( V_16 , L_14 , V_20 ) ;
}
}
}
if ( F_9 ( V_2 , V_28 , & V_54 , 2 ) )
F_8 ( V_16 , L_28 ) ;
}
if ( ( V_49 & V_76 ) != ( V_87 & V_76 ) ) {
F_16 ( V_2 , & V_54 ) ;
V_54 &= ~ V_77 ;
if ( V_49 & V_76 ) {
V_54 |= V_80 ;
F_8 ( V_16 , L_20 , V_20 ) ;
} else {
V_54 |= V_78 ;
F_8 ( V_16 , L_18 , V_20 ) ;
}
if ( F_9 ( V_2 , V_28 , & V_54 , 2 ) )
F_8 ( V_16 , L_29 ) ;
}
if ( ( V_49 & V_82 ) != ( V_87 & V_82 ) ) {
F_1 ( V_2 , V_81 , V_53 , 16 ) ;
F_8 ( V_16 , L_30 ,
V_20 , V_53 [ 0 ] , V_53 [ 1 ] ,
V_53 [ 2 ] , V_53 [ 3 ] ) ;
if ( V_49 & V_82 ) {
V_53 [ 0 ] &= ~ 0x7B ;
V_53 [ 0 ] |= 0x09 ;
V_53 [ 1 ] = 0x80 ;
F_8 ( V_16 , L_22 , V_20 ) ;
} else {
V_53 [ 0 ] &= ~ 0x7B ;
V_53 [ 0 ] |= 0x01 ;
V_53 [ 1 ] |= 0x40 ;
F_8 ( V_16 , L_23 , V_20 ) ;
}
F_8 ( V_16 , L_31 ,
V_20 , V_53 [ 0 ] , V_53 [ 1 ] ,
V_53 [ 2 ] , V_53 [ 3 ] ) ;
F_9 ( V_2 , V_88 , V_53 , 16 ) ;
}
}
static int F_31 ( struct V_33 * V_34 ,
unsigned int V_89 , unsigned int V_90 )
{
struct V_1 * V_2 = V_34 -> V_46 ;
return F_32 ( V_2 , V_89 , V_90 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned int V_89 , unsigned int V_90 )
{
unsigned int V_91 = 0 ;
if ( V_89 & V_92 ) {
V_91 |= V_93 ;
V_91 |= V_94 ;
}
if ( V_89 & V_95 ) {
V_91 |= V_96 ;
V_91 |= V_97 ;
}
if ( V_90 & V_92 ) {
V_91 &= ~ V_93 ;
V_91 |= V_94 ;
}
if ( V_90 & V_95 ) {
V_91 &= ~ V_96 ;
V_91 |= V_97 ;
}
F_8 ( & V_2 -> V_16 , L_32 , V_20 , V_91 ) ;
return F_9 ( V_2 , V_98 , & V_91 , 2 ) ;
}
static void F_33 ( struct V_1 * V_99 , int V_100 )
{
if ( V_100 )
F_32 ( V_99 , V_95 | V_92 , 0 ) ;
else
F_32 ( V_99 , 0 , V_95 | V_92 ) ;
}
static int F_34 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_46 ;
unsigned int V_91 ;
int V_11 ;
F_1 ( V_2 , V_101 , & V_91 , 1 ) ;
V_11 = ( ( V_91 & V_96 ) ? V_95 : 0 )
| ( ( V_91 & V_93 ) ? V_92 : 0 )
| ( ( V_91 & V_102 ) ? V_103 : 0 )
| ( ( V_91 & V_104 ) ? V_105 : 0 )
| ( ( V_91 & V_106 ) ? V_107 : 0 )
| ( ( V_91 & V_108 ) ? V_109 : 0 ) ;
F_8 ( & V_2 -> V_16 , L_33 , V_20 , V_91 ) ;
return V_11 ;
}
static void F_35 ( struct V_33 * V_34 , int V_110 )
{
struct V_1 * V_2 = V_34 -> V_46 ;
unsigned int V_111 ;
if ( V_110 == 0 )
V_111 = V_112 ;
else
V_111 = V_113 ;
F_8 ( & V_2 -> V_16 , L_34 , V_20 ,
V_111 == V_112 ? L_35 : L_36 ) ;
F_9 ( V_2 , V_114 , & V_111 , 2 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_115 * V_116 ;
struct V_8 * V_9 ;
int V_117 ;
V_9 = F_37 ( sizeof( * V_9 ) , V_14 ) ;
if ( ! V_9 )
return - V_15 ;
V_116 = V_7 -> V_118 -> V_116 ;
V_9 -> V_18 = V_116 -> V_119 . V_18 ;
F_38 ( V_2 , V_9 ) ;
V_117 = F_14 ( V_2 ) ;
if ( V_117 ) {
F_7 ( V_9 ) ;
return V_117 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 ) ;
F_7 ( V_9 ) ;
return 0 ;
}
