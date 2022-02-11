static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
void * V_10 ;
int V_11 ;
V_10 = F_3 ( V_5 , V_12 ) ;
if ( ! V_10 ) {
memset ( V_4 , 0 , V_5 ) ;
return - V_13 ;
}
V_11 = F_4 ( V_7 -> V_14 , F_5 ( V_7 -> V_14 , 0 ) ,
V_3 , V_15 , 0 ,
V_9 -> V_16 , V_10 , V_5 ,
V_17 ) ;
if ( V_11 == V_5 ) {
memcpy ( V_4 , V_10 , V_5 ) ;
V_11 = 0 ;
} else {
F_6 ( & V_2 -> V_14 , L_1 ,
V_3 , V_5 , V_11 ) ;
if ( V_11 >= 0 )
V_11 = - V_18 ;
memset ( V_4 , 0 , V_5 ) ;
}
F_7 ( V_10 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_19 )
{
T_3 V_20 ;
int V_21 ;
V_21 = F_1 ( V_2 , V_3 , & V_20 , sizeof( V_20 ) ) ;
if ( V_21 ) {
* V_19 = 0 ;
return V_21 ;
}
* V_19 = F_9 ( V_20 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_4 * V_19 )
{
T_5 V_22 ;
int V_21 ;
V_21 = F_1 ( V_2 , V_3 , & V_22 , sizeof( V_22 ) ) ;
if ( V_21 )
return V_21 ;
* V_19 = F_11 ( V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_19 )
{
return F_1 ( V_2 , V_3 , V_19 , sizeof( * V_19 ) ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 , T_4 V_19 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_11 ;
V_11 = F_4 ( V_7 -> V_14 , F_14 ( V_7 -> V_14 , 0 ) ,
V_3 , V_23 , V_19 ,
V_9 -> V_16 , NULL , 0 ,
V_17 ) ;
if ( V_11 < 0 ) {
F_6 ( & V_2 -> V_14 , L_2 ,
V_3 , V_11 ) ;
}
return V_11 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
void * V_10 ;
int V_11 ;
V_10 = F_16 ( V_4 , V_5 , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
V_11 = F_4 ( V_7 -> V_14 , F_14 ( V_7 -> V_14 , 0 ) ,
V_3 , V_23 , 0 ,
V_9 -> V_16 , V_10 , V_5 ,
V_17 ) ;
F_7 ( V_10 ) ;
if ( V_11 == V_5 ) {
V_11 = 0 ;
} else {
F_6 ( & V_2 -> V_14 , L_3 ,
V_3 , V_5 , V_11 ) ;
if ( V_11 >= 0 )
V_11 = - V_18 ;
}
return V_11 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_19 )
{
T_3 V_20 ;
V_20 = F_18 ( V_19 ) ;
return F_15 ( V_2 , V_3 , & V_20 , sizeof( V_20 ) ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_4 V_24 ;
T_4 V_25 ;
int V_21 ;
V_21 = F_10 ( V_2 , V_26 , & V_24 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_13 ( V_2 , V_27 , 0x800 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_10 ( V_2 , V_26 , & V_25 ) ;
if ( V_21 )
return V_21 ;
if ( V_25 == 8 ) {
V_9 -> V_28 = true ;
V_24 = F_20 ( V_24 ) ;
}
return F_13 ( V_2 , V_27 , V_24 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_4 * V_29 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_21 ;
V_21 = F_10 ( V_2 , V_26 , V_29 ) ;
if ( V_21 )
return V_21 ;
if ( V_9 -> V_28 )
* V_29 = F_20 ( * V_29 ) ;
return 0 ;
}
static unsigned int F_22 ( unsigned int V_30 )
{
if ( V_30 <= 300 )
V_30 = 300 ;
else if ( V_30 <= 600 ) V_30 = 600 ;
else if ( V_30 <= 1200 ) V_30 = 1200 ;
else if ( V_30 <= 1800 ) V_30 = 1800 ;
else if ( V_30 <= 2400 ) V_30 = 2400 ;
else if ( V_30 <= 4000 ) V_30 = 4000 ;
else if ( V_30 <= 4803 ) V_30 = 4800 ;
else if ( V_30 <= 7207 ) V_30 = 7200 ;
else if ( V_30 <= 9612 ) V_30 = 9600 ;
else if ( V_30 <= 14428 ) V_30 = 14400 ;
else if ( V_30 <= 16062 ) V_30 = 16000 ;
else if ( V_30 <= 19250 ) V_30 = 19200 ;
else if ( V_30 <= 28912 ) V_30 = 28800 ;
else if ( V_30 <= 38601 ) V_30 = 38400 ;
else if ( V_30 <= 51558 ) V_30 = 51200 ;
else if ( V_30 <= 56280 ) V_30 = 56000 ;
else if ( V_30 <= 58053 ) V_30 = 57600 ;
else if ( V_30 <= 64111 ) V_30 = 64000 ;
else if ( V_30 <= 77608 ) V_30 = 76800 ;
else if ( V_30 <= 117028 ) V_30 = 115200 ;
else if ( V_30 <= 129347 ) V_30 = 128000 ;
else if ( V_30 <= 156868 ) V_30 = 153600 ;
else if ( V_30 <= 237832 ) V_30 = 230400 ;
else if ( V_30 <= 254234 ) V_30 = 250000 ;
else if ( V_30 <= 273066 ) V_30 = 256000 ;
else if ( V_30 <= 491520 ) V_30 = 460800 ;
else if ( V_30 <= 567138 ) V_30 = 500000 ;
else if ( V_30 <= 670254 ) V_30 = 576000 ;
else if ( V_30 < 1000000 )
V_30 = 921600 ;
else if ( V_30 > 2000000 )
V_30 = 2000000 ;
return V_30 ;
}
static int F_23 ( struct V_31 * V_32 , struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_13 ( V_2 , V_33 , V_34 ) ;
if ( V_11 ) {
F_6 ( & V_2 -> V_14 , L_4 , V_35 ) ;
return V_11 ;
}
F_24 ( V_32 , V_2 ) ;
if ( V_32 )
F_25 ( V_32 , V_2 , NULL ) ;
return F_26 ( V_32 , V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
F_13 ( V_2 , V_36 , V_37 ) ;
F_13 ( V_2 , V_33 , V_38 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
T_2 * V_39 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_40 * V_41 ;
int V_11 ;
V_41 = F_3 ( sizeof( * V_41 ) , V_12 ) ;
if ( ! V_41 )
return - V_13 ;
V_11 = F_4 ( V_7 -> V_14 , F_5 ( V_7 -> V_14 , 0 ) ,
V_42 , V_15 ,
0 , V_9 -> V_16 , V_41 , sizeof( * V_41 ) ,
V_43 ) ;
if ( V_11 == sizeof( * V_41 ) ) {
* V_39 = F_9 ( V_41 -> V_44 ) ;
V_11 = 0 ;
} else {
F_6 ( & V_2 -> V_14 , L_5 , V_11 ) ;
if ( V_11 >= 0 )
V_11 = - V_18 ;
}
F_7 ( V_41 ) ;
return V_11 ;
}
static bool F_30 ( struct V_1 * V_2 )
{
int V_21 ;
T_2 V_39 ;
V_21 = F_29 ( V_2 , & V_39 ) ;
if ( V_21 )
return true ;
return ! V_39 ;
}
static void F_24 ( struct V_31 * V_32 ,
struct V_1 * V_2 )
{
unsigned int V_30 ;
if ( V_32 ) {
F_31 ( V_32 -> V_45 ,
& V_32 -> V_46 . V_47 , & V_30 ) ;
F_32 ( V_32 , V_30 , V_30 ) ;
} else {
unsigned int V_48 ;
V_48 = 0 ;
F_31 ( V_2 , & V_48 , & V_30 ) ;
}
}
static void F_31 ( struct V_1 * V_2 ,
unsigned int * V_49 , unsigned int * V_50 )
{
struct V_51 * V_14 = & V_2 -> V_14 ;
unsigned int V_48 ;
struct V_52 V_53 ;
T_2 V_30 ;
T_4 V_54 ;
T_2 V_55 ;
F_8 ( V_2 , V_56 , & V_30 ) ;
F_33 ( V_14 , L_6 , V_35 , V_30 ) ;
* V_50 = V_30 ;
V_48 = * V_49 ;
F_21 ( V_2 , & V_54 ) ;
V_48 &= ~ V_57 ;
switch ( V_54 & V_58 ) {
case V_59 :
F_33 ( V_14 , L_7 , V_35 ) ;
V_48 |= V_60 ;
break;
case V_61 :
F_33 ( V_14 , L_8 , V_35 ) ;
V_48 |= V_62 ;
break;
case V_63 :
F_33 ( V_14 , L_9 , V_35 ) ;
V_48 |= V_64 ;
break;
case V_65 :
F_33 ( V_14 , L_10 , V_35 ) ;
V_48 |= V_66 ;
break;
case V_67 :
F_33 ( V_14 , L_11 , V_35 ) ;
V_48 |= V_66 ;
V_54 &= ~ V_58 ;
V_54 |= V_65 ;
F_13 ( V_2 , V_27 , V_54 ) ;
break;
default:
F_33 ( V_14 , L_12 , V_35 ) ;
V_48 |= V_66 ;
V_54 &= ~ V_58 ;
V_54 |= V_65 ;
F_13 ( V_2 , V_27 , V_54 ) ;
break;
}
switch ( V_54 & V_68 ) {
case V_69 :
F_33 ( V_14 , L_13 , V_35 ) ;
V_48 &= ~ V_70 ;
break;
case V_71 :
F_33 ( V_14 , L_14 , V_35 ) ;
V_48 |= ( V_70 | V_72 ) ;
break;
case V_73 :
F_33 ( V_14 , L_15 , V_35 ) ;
V_48 &= ~ V_72 ;
V_48 |= V_70 ;
break;
case V_74 :
F_33 ( V_14 , L_16 , V_35 ) ;
V_48 |= ( V_70 | V_72 | V_75 ) ;
break;
case V_76 :
F_33 ( V_14 , L_17 , V_35 ) ;
V_48 &= ~ V_72 ;
V_48 |= ( V_70 | V_75 ) ;
break;
default:
F_33 ( V_14 , L_18 , V_35 ) ;
V_48 &= ~ V_70 ;
V_54 &= ~ V_68 ;
F_13 ( V_2 , V_27 , V_54 ) ;
break;
}
V_48 &= ~ V_77 ;
switch ( V_54 & V_78 ) {
case V_79 :
F_33 ( V_14 , L_19 , V_35 ) ;
break;
case V_80 :
F_33 ( V_14 , L_20 , V_35 ) ;
V_54 &= ~ V_78 ;
F_13 ( V_2 , V_27 , V_54 ) ;
break;
case V_81 :
F_33 ( V_14 , L_21 , V_35 ) ;
V_48 |= V_77 ;
break;
default:
F_33 ( V_14 , L_22 , V_35 ) ;
V_54 &= ~ V_78 ;
F_13 ( V_2 , V_27 , V_54 ) ;
break;
}
F_1 ( V_2 , V_82 , & V_53 ,
sizeof( V_53 ) ) ;
V_55 = F_9 ( V_53 . V_83 ) ;
if ( V_55 & V_84 ) {
F_33 ( V_14 , L_23 , V_35 ) ;
V_48 |= V_85 ;
} else {
F_33 ( V_14 , L_24 , V_35 ) ;
V_48 &= ~ V_85 ;
}
* V_49 = V_48 ;
}
static void F_25 ( struct V_31 * V_32 ,
struct V_1 * V_2 , struct V_86 * V_87 )
{
T_2 V_30 ;
V_30 = V_32 -> V_46 . V_88 ;
V_30 = F_22 ( V_30 ) ;
F_33 ( & V_2 -> V_14 , L_25 , V_35 , V_30 ) ;
if ( F_17 ( V_2 , V_89 , V_30 ) ) {
F_34 ( & V_2 -> V_14 , L_26 , V_30 ) ;
if ( V_87 )
V_30 = V_87 -> V_88 ;
else
V_30 = 9600 ;
}
F_32 ( V_32 , V_30 , V_30 ) ;
}
static void F_35 ( struct V_31 * V_32 ,
struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_51 * V_14 = & V_2 -> V_14 ;
unsigned int V_48 , V_90 ;
T_4 V_54 ;
V_48 = V_32 -> V_46 . V_47 ;
V_90 = V_87 -> V_47 ;
if ( V_32 -> V_46 . V_88 != V_87 -> V_88 )
F_25 ( V_32 , V_2 , V_87 ) ;
if ( ( V_48 & V_57 ) != ( V_90 & V_57 ) ) {
F_21 ( V_2 , & V_54 ) ;
V_54 &= ~ V_58 ;
switch ( V_48 & V_57 ) {
case V_60 :
V_54 |= V_59 ;
F_33 ( V_14 , L_7 , V_35 ) ;
break;
case V_62 :
V_54 |= V_61 ;
F_33 ( V_14 , L_8 , V_35 ) ;
break;
case V_64 :
V_54 |= V_63 ;
F_33 ( V_14 , L_9 , V_35 ) ;
break;
case V_66 :
V_54 |= V_65 ;
F_33 ( V_14 , L_10 , V_35 ) ;
break;
default:
F_33 ( V_14 , L_27 ) ;
V_54 |= V_65 ;
break;
}
if ( F_13 ( V_2 , V_27 , V_54 ) )
F_33 ( V_14 , L_28 ) ;
}
if ( ( V_48 & ( V_70 | V_72 | V_75 ) ) !=
( V_90 & ( V_70 | V_72 | V_75 ) ) ) {
F_21 ( V_2 , & V_54 ) ;
V_54 &= ~ V_68 ;
if ( V_48 & V_70 ) {
if ( V_48 & V_75 ) {
if ( V_48 & V_72 ) {
V_54 |= V_74 ;
F_33 ( V_14 , L_16 , V_35 ) ;
} else {
V_54 |= V_76 ;
F_33 ( V_14 , L_17 , V_35 ) ;
}
} else {
if ( V_48 & V_72 ) {
V_54 |= V_71 ;
F_33 ( V_14 , L_14 , V_35 ) ;
} else {
V_54 |= V_73 ;
F_33 ( V_14 , L_15 , V_35 ) ;
}
}
}
if ( F_13 ( V_2 , V_27 , V_54 ) )
F_33 ( V_14 , L_29 ) ;
}
if ( ( V_48 & V_77 ) != ( V_90 & V_77 ) ) {
F_21 ( V_2 , & V_54 ) ;
V_54 &= ~ V_78 ;
if ( V_48 & V_77 ) {
V_54 |= V_81 ;
F_33 ( V_14 , L_21 , V_35 ) ;
} else {
V_54 |= V_79 ;
F_33 ( V_14 , L_19 , V_35 ) ;
}
if ( F_13 ( V_2 , V_27 , V_54 ) )
F_33 ( V_14 , L_30 ) ;
}
if ( ( V_48 & V_85 ) != ( V_90 & V_85 ) ) {
struct V_52 V_53 ;
T_2 V_55 ;
T_2 V_91 ;
F_1 ( V_2 , V_82 , & V_53 ,
sizeof( V_53 ) ) ;
V_55 = F_9 ( V_53 . V_83 ) ;
V_91 = F_9 ( V_53 . V_92 ) ;
F_33 ( V_14 , L_31 ,
V_35 , V_55 , V_91 ) ;
V_55 &= ~ V_93 ;
V_55 &= ~ V_94 ;
V_55 &= ~ V_95 ;
V_55 &= ~ V_96 ;
V_55 |= F_36 ( V_97 ) ;
if ( V_48 & V_85 ) {
V_55 |= V_84 ;
V_91 &= ~ V_98 ;
V_91 |= F_37 (
V_99 ) ;
F_33 ( V_14 , L_23 , V_35 ) ;
} else {
V_55 &= ~ V_84 ;
V_91 &= ~ V_98 ;
V_91 |= F_37 (
V_100 ) ;
F_33 ( V_14 , L_24 , V_35 ) ;
}
F_33 ( V_14 , L_32 ,
V_35 , V_55 , V_91 ) ;
V_53 . V_83 = F_18 ( V_55 ) ;
V_53 . V_92 = F_18 ( V_91 ) ;
F_15 ( V_2 , V_101 , & V_53 ,
sizeof( V_53 ) ) ;
}
}
static int F_38 ( struct V_31 * V_32 ,
unsigned int V_102 , unsigned int V_103 )
{
struct V_1 * V_2 = V_32 -> V_45 ;
return F_39 ( V_2 , V_102 , V_103 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned int V_102 , unsigned int V_103 )
{
T_4 V_104 = 0 ;
if ( V_102 & V_105 ) {
V_104 |= V_106 ;
V_104 |= V_107 ;
}
if ( V_102 & V_108 ) {
V_104 |= V_109 ;
V_104 |= V_110 ;
}
if ( V_103 & V_105 ) {
V_104 &= ~ V_106 ;
V_104 |= V_107 ;
}
if ( V_103 & V_108 ) {
V_104 &= ~ V_109 ;
V_104 |= V_110 ;
}
F_33 ( & V_2 -> V_14 , L_33 , V_35 , V_104 ) ;
return F_13 ( V_2 , V_111 , V_104 ) ;
}
static void F_40 ( struct V_1 * V_112 , int V_113 )
{
if ( V_113 )
F_39 ( V_112 , V_108 | V_105 , 0 ) ;
else
F_39 ( V_112 , 0 , V_108 | V_105 ) ;
}
static int F_41 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_45 ;
T_1 V_104 ;
int V_11 ;
V_11 = F_12 ( V_2 , V_114 , & V_104 ) ;
if ( V_11 )
return V_11 ;
V_11 = ( ( V_104 & V_109 ) ? V_108 : 0 )
| ( ( V_104 & V_106 ) ? V_105 : 0 )
| ( ( V_104 & V_115 ) ? V_116 : 0 )
| ( ( V_104 & V_117 ) ? V_118 : 0 )
| ( ( V_104 & V_119 ) ? V_120 : 0 )
| ( ( V_104 & V_121 ) ? V_122 : 0 ) ;
F_33 ( & V_2 -> V_14 , L_34 , V_35 , V_104 ) ;
return V_11 ;
}
static void F_42 ( struct V_31 * V_32 , int V_123 )
{
struct V_1 * V_2 = V_32 -> V_45 ;
T_4 V_124 ;
if ( V_123 == 0 )
V_124 = V_125 ;
else
V_124 = V_126 ;
F_33 ( & V_2 -> V_14 , L_35 , V_35 ,
V_124 == V_125 ? L_36 : L_37 ) ;
F_13 ( V_2 , V_127 , V_124 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_128 * V_129 ;
struct V_8 * V_9 ;
int V_130 ;
V_9 = F_44 ( sizeof( * V_9 ) , V_12 ) ;
if ( ! V_9 )
return - V_13 ;
V_129 = V_7 -> V_131 -> V_129 ;
V_9 -> V_16 = V_129 -> V_132 . V_16 ;
F_45 ( V_2 , V_9 ) ;
V_130 = F_19 ( V_2 ) ;
if ( V_130 ) {
F_7 ( V_9 ) ;
return V_130 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 ) ;
F_7 ( V_9 ) ;
return 0 ;
}
