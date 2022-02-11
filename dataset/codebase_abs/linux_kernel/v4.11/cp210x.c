static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = V_2 -> V_5 -> V_4 ;
return V_4 -> V_6 . V_7 ;
}
static int F_2 ( struct V_8 * V_9 , T_1 V_10 ,
void * V_11 , int V_12 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_13 * V_14 = F_3 ( V_9 ) ;
void * V_15 ;
int V_16 ;
V_15 = F_4 ( V_12 , V_17 ) ;
if ( ! V_15 ) {
memset ( V_11 , 0 , V_12 ) ;
return - V_18 ;
}
V_16 = F_5 ( V_2 -> V_19 , F_6 ( V_2 -> V_19 , 0 ) ,
V_10 , V_20 , 0 ,
V_14 -> V_7 , V_15 , V_12 ,
V_21 ) ;
if ( V_16 == V_12 ) {
memcpy ( V_11 , V_15 , V_12 ) ;
V_16 = 0 ;
} else {
F_7 ( & V_9 -> V_19 , L_1 ,
V_10 , V_12 , V_16 ) ;
if ( V_16 >= 0 )
V_16 = - V_22 ;
memset ( V_11 , 0 , V_12 ) ;
}
F_8 ( V_15 ) ;
return V_16 ;
}
static int F_9 ( struct V_8 * V_9 , T_1 V_10 , T_2 * V_23 )
{
T_3 V_24 ;
int V_25 ;
V_25 = F_2 ( V_9 , V_10 , & V_24 , sizeof( V_24 ) ) ;
if ( V_25 ) {
* V_23 = 0 ;
return V_25 ;
}
* V_23 = F_10 ( V_24 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 , T_1 V_10 , T_4 * V_23 )
{
T_5 V_26 ;
int V_25 ;
V_25 = F_2 ( V_9 , V_10 , & V_26 , sizeof( V_26 ) ) ;
if ( V_25 )
return V_25 ;
* V_23 = F_12 ( V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 , T_1 V_10 , T_1 * V_23 )
{
return F_2 ( V_9 , V_10 , V_23 , sizeof( * V_23 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 type , T_4 V_23 ,
void * V_11 , int V_12 )
{
void * V_15 ;
int V_16 ;
V_15 = F_4 ( V_12 , V_17 ) ;
if ( ! V_15 )
return - V_18 ;
V_16 = F_5 ( V_2 -> V_19 , F_6 ( V_2 -> V_19 , 0 ) ,
V_27 , type , V_23 ,
F_1 ( V_2 ) , V_15 , V_12 ,
V_28 ) ;
if ( V_16 == V_12 ) {
memcpy ( V_11 , V_15 , V_12 ) ;
V_16 = 0 ;
} else {
F_7 ( & V_2 -> V_5 -> V_19 ,
L_2 , V_23 ,
V_12 , V_16 ) ;
if ( V_16 >= 0 )
V_16 = - V_22 ;
}
F_8 ( V_15 ) ;
return V_16 ;
}
static int F_15 ( struct V_8 * V_9 , T_1 V_10 , T_4 V_23 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_13 * V_14 = F_3 ( V_9 ) ;
int V_16 ;
V_16 = F_5 ( V_2 -> V_19 , F_16 ( V_2 -> V_19 , 0 ) ,
V_10 , V_29 , V_23 ,
V_14 -> V_7 , NULL , 0 ,
V_21 ) ;
if ( V_16 < 0 ) {
F_7 ( & V_9 -> V_19 , L_3 ,
V_10 , V_16 ) ;
}
return V_16 ;
}
static int F_17 ( struct V_8 * V_9 , T_1 V_10 ,
void * V_11 , int V_12 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_13 * V_14 = F_3 ( V_9 ) ;
void * V_15 ;
int V_16 ;
V_15 = F_18 ( V_11 , V_12 , V_17 ) ;
if ( ! V_15 )
return - V_18 ;
V_16 = F_5 ( V_2 -> V_19 , F_16 ( V_2 -> V_19 , 0 ) ,
V_10 , V_29 , 0 ,
V_14 -> V_7 , V_15 , V_12 ,
V_21 ) ;
F_8 ( V_15 ) ;
if ( V_16 == V_12 ) {
V_16 = 0 ;
} else {
F_7 ( & V_9 -> V_19 , L_4 ,
V_10 , V_12 , V_16 ) ;
if ( V_16 >= 0 )
V_16 = - V_22 ;
}
return V_16 ;
}
static int F_19 ( struct V_8 * V_9 , T_1 V_10 , T_2 V_23 )
{
T_3 V_24 ;
V_24 = F_20 ( V_23 ) ;
return F_17 ( V_9 , V_10 , & V_24 , sizeof( V_24 ) ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 type ,
T_4 V_23 , void * V_11 , int V_12 )
{
void * V_15 ;
int V_16 ;
V_15 = F_18 ( V_11 , V_12 , V_17 ) ;
if ( ! V_15 )
return - V_18 ;
V_16 = F_5 ( V_2 -> V_19 , F_16 ( V_2 -> V_19 , 0 ) ,
V_27 , type , V_23 ,
F_1 ( V_2 ) , V_15 , V_12 ,
V_21 ) ;
F_8 ( V_15 ) ;
if ( V_16 == V_12 ) {
V_16 = 0 ;
} else {
F_7 ( & V_2 -> V_5 -> V_19 ,
L_5 , V_23 ,
V_12 , V_16 ) ;
if ( V_16 >= 0 )
V_16 = - V_22 ;
}
return V_16 ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_3 ( V_9 ) ;
T_4 V_30 ;
T_4 V_31 ;
int V_25 ;
V_25 = F_11 ( V_9 , V_32 , & V_30 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_15 ( V_9 , V_33 , 0x800 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_11 ( V_9 , V_32 , & V_31 ) ;
if ( V_25 )
return V_25 ;
if ( V_31 == 8 ) {
V_14 -> V_34 = true ;
V_30 = F_23 ( V_30 ) ;
}
return F_15 ( V_9 , V_33 , V_30 ) ;
}
static int F_24 ( struct V_8 * V_9 , T_4 * V_35 )
{
struct V_13 * V_14 = F_3 ( V_9 ) ;
int V_25 ;
V_25 = F_11 ( V_9 , V_32 , V_35 ) ;
if ( V_25 )
return V_25 ;
if ( V_14 -> V_34 )
* V_35 = F_23 ( * V_35 ) ;
return 0 ;
}
static unsigned int F_25 ( unsigned int V_36 )
{
if ( V_36 <= 300 )
V_36 = 300 ;
else if ( V_36 <= 600 ) V_36 = 600 ;
else if ( V_36 <= 1200 ) V_36 = 1200 ;
else if ( V_36 <= 1800 ) V_36 = 1800 ;
else if ( V_36 <= 2400 ) V_36 = 2400 ;
else if ( V_36 <= 4000 ) V_36 = 4000 ;
else if ( V_36 <= 4803 ) V_36 = 4800 ;
else if ( V_36 <= 7207 ) V_36 = 7200 ;
else if ( V_36 <= 9612 ) V_36 = 9600 ;
else if ( V_36 <= 14428 ) V_36 = 14400 ;
else if ( V_36 <= 16062 ) V_36 = 16000 ;
else if ( V_36 <= 19250 ) V_36 = 19200 ;
else if ( V_36 <= 28912 ) V_36 = 28800 ;
else if ( V_36 <= 38601 ) V_36 = 38400 ;
else if ( V_36 <= 51558 ) V_36 = 51200 ;
else if ( V_36 <= 56280 ) V_36 = 56000 ;
else if ( V_36 <= 58053 ) V_36 = 57600 ;
else if ( V_36 <= 64111 ) V_36 = 64000 ;
else if ( V_36 <= 77608 ) V_36 = 76800 ;
else if ( V_36 <= 117028 ) V_36 = 115200 ;
else if ( V_36 <= 129347 ) V_36 = 128000 ;
else if ( V_36 <= 156868 ) V_36 = 153600 ;
else if ( V_36 <= 237832 ) V_36 = 230400 ;
else if ( V_36 <= 254234 ) V_36 = 250000 ;
else if ( V_36 <= 273066 ) V_36 = 256000 ;
else if ( V_36 <= 491520 ) V_36 = 460800 ;
else if ( V_36 <= 567138 ) V_36 = 500000 ;
else if ( V_36 <= 670254 ) V_36 = 576000 ;
else if ( V_36 < 1000000 )
V_36 = 921600 ;
else if ( V_36 > 2000000 )
V_36 = 2000000 ;
return V_36 ;
}
static int F_26 ( struct V_37 * V_38 , struct V_8 * V_9 )
{
int V_16 ;
V_16 = F_15 ( V_9 , V_39 , V_40 ) ;
if ( V_16 ) {
F_7 ( & V_9 -> V_19 , L_6 , V_41 ) ;
return V_16 ;
}
F_27 ( V_38 , V_9 ) ;
if ( V_38 )
F_28 ( V_38 , V_9 , NULL ) ;
return F_29 ( V_38 , V_9 ) ;
}
static void F_30 ( struct V_8 * V_9 )
{
F_31 ( V_9 ) ;
F_15 ( V_9 , V_42 , V_43 ) ;
F_15 ( V_9 , V_39 , V_44 ) ;
}
static int F_32 ( struct V_8 * V_9 ,
T_2 * V_45 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_13 * V_14 = F_3 ( V_9 ) ;
struct V_46 * V_47 ;
int V_16 ;
V_47 = F_4 ( sizeof( * V_47 ) , V_17 ) ;
if ( ! V_47 )
return - V_18 ;
V_16 = F_5 ( V_2 -> V_19 , F_6 ( V_2 -> V_19 , 0 ) ,
V_48 , V_20 ,
0 , V_14 -> V_7 , V_47 , sizeof( * V_47 ) ,
V_28 ) ;
if ( V_16 == sizeof( * V_47 ) ) {
* V_45 = F_10 ( V_47 -> V_49 ) ;
V_16 = 0 ;
} else {
F_7 ( & V_9 -> V_19 , L_7 , V_16 ) ;
if ( V_16 >= 0 )
V_16 = - V_22 ;
}
F_8 ( V_47 ) ;
return V_16 ;
}
static bool F_33 ( struct V_8 * V_9 )
{
int V_25 ;
T_2 V_45 ;
V_25 = F_32 ( V_9 , & V_45 ) ;
if ( V_25 )
return true ;
return ! V_45 ;
}
static void F_27 ( struct V_37 * V_38 ,
struct V_8 * V_9 )
{
unsigned int V_36 ;
if ( V_38 ) {
F_34 ( V_38 -> V_50 ,
& V_38 -> V_51 . V_52 , & V_36 ) ;
F_35 ( V_38 , V_36 , V_36 ) ;
} else {
T_6 V_53 ;
V_53 = 0 ;
F_34 ( V_9 , & V_53 , & V_36 ) ;
}
}
static void F_34 ( struct V_8 * V_9 ,
T_6 * V_54 , unsigned int * V_55 )
{
struct V_56 * V_19 = & V_9 -> V_19 ;
T_6 V_53 ;
struct V_57 V_58 ;
T_2 V_36 ;
T_4 V_59 ;
T_2 V_60 ;
F_9 ( V_9 , V_61 , & V_36 ) ;
F_36 ( V_19 , L_8 , V_41 , V_36 ) ;
* V_55 = V_36 ;
V_53 = * V_54 ;
F_24 ( V_9 , & V_59 ) ;
V_53 &= ~ V_62 ;
switch ( V_59 & V_63 ) {
case V_64 :
F_36 ( V_19 , L_9 , V_41 ) ;
V_53 |= V_65 ;
break;
case V_66 :
F_36 ( V_19 , L_10 , V_41 ) ;
V_53 |= V_67 ;
break;
case V_68 :
F_36 ( V_19 , L_11 , V_41 ) ;
V_53 |= V_69 ;
break;
case V_70 :
F_36 ( V_19 , L_12 , V_41 ) ;
V_53 |= V_71 ;
break;
case V_72 :
F_36 ( V_19 , L_13 , V_41 ) ;
V_53 |= V_71 ;
V_59 &= ~ V_63 ;
V_59 |= V_70 ;
F_15 ( V_9 , V_33 , V_59 ) ;
break;
default:
F_36 ( V_19 , L_14 , V_41 ) ;
V_53 |= V_71 ;
V_59 &= ~ V_63 ;
V_59 |= V_70 ;
F_15 ( V_9 , V_33 , V_59 ) ;
break;
}
switch ( V_59 & V_73 ) {
case V_74 :
F_36 ( V_19 , L_15 , V_41 ) ;
V_53 &= ~ V_75 ;
break;
case V_76 :
F_36 ( V_19 , L_16 , V_41 ) ;
V_53 |= ( V_75 | V_77 ) ;
break;
case V_78 :
F_36 ( V_19 , L_17 , V_41 ) ;
V_53 &= ~ V_77 ;
V_53 |= V_75 ;
break;
case V_79 :
F_36 ( V_19 , L_18 , V_41 ) ;
V_53 |= ( V_75 | V_77 | V_80 ) ;
break;
case V_81 :
F_36 ( V_19 , L_19 , V_41 ) ;
V_53 &= ~ V_77 ;
V_53 |= ( V_75 | V_80 ) ;
break;
default:
F_36 ( V_19 , L_20 , V_41 ) ;
V_53 &= ~ V_75 ;
V_59 &= ~ V_73 ;
F_15 ( V_9 , V_33 , V_59 ) ;
break;
}
V_53 &= ~ V_82 ;
switch ( V_59 & V_83 ) {
case V_84 :
F_36 ( V_19 , L_21 , V_41 ) ;
break;
case V_85 :
F_36 ( V_19 , L_22 , V_41 ) ;
V_59 &= ~ V_83 ;
F_15 ( V_9 , V_33 , V_59 ) ;
break;
case V_86 :
F_36 ( V_19 , L_23 , V_41 ) ;
V_53 |= V_82 ;
break;
default:
F_36 ( V_19 , L_24 , V_41 ) ;
V_59 &= ~ V_83 ;
F_15 ( V_9 , V_33 , V_59 ) ;
break;
}
F_2 ( V_9 , V_87 , & V_58 ,
sizeof( V_58 ) ) ;
V_60 = F_10 ( V_58 . V_88 ) ;
if ( V_60 & V_89 ) {
F_36 ( V_19 , L_25 , V_41 ) ;
V_53 |= V_90 ;
} else {
F_36 ( V_19 , L_26 , V_41 ) ;
V_53 &= ~ V_90 ;
}
* V_54 = V_53 ;
}
static void F_28 ( struct V_37 * V_38 ,
struct V_8 * V_9 , struct V_91 * V_92 )
{
T_2 V_36 ;
V_36 = V_38 -> V_51 . V_93 ;
V_36 = F_25 ( V_36 ) ;
F_36 ( & V_9 -> V_19 , L_27 , V_41 , V_36 ) ;
if ( F_19 ( V_9 , V_94 , V_36 ) ) {
F_37 ( & V_9 -> V_19 , L_28 , V_36 ) ;
if ( V_92 )
V_36 = V_92 -> V_93 ;
else
V_36 = 9600 ;
}
F_35 ( V_38 , V_36 , V_36 ) ;
}
static void F_38 ( struct V_37 * V_38 ,
struct V_8 * V_9 , struct V_91 * V_92 )
{
struct V_56 * V_19 = & V_9 -> V_19 ;
unsigned int V_53 , V_95 ;
T_4 V_59 ;
V_53 = V_38 -> V_51 . V_52 ;
V_95 = V_92 -> V_52 ;
if ( V_38 -> V_51 . V_93 != V_92 -> V_93 )
F_28 ( V_38 , V_9 , V_92 ) ;
if ( ( V_53 & V_62 ) != ( V_95 & V_62 ) ) {
F_24 ( V_9 , & V_59 ) ;
V_59 &= ~ V_63 ;
switch ( V_53 & V_62 ) {
case V_65 :
V_59 |= V_64 ;
F_36 ( V_19 , L_9 , V_41 ) ;
break;
case V_67 :
V_59 |= V_66 ;
F_36 ( V_19 , L_10 , V_41 ) ;
break;
case V_69 :
V_59 |= V_68 ;
F_36 ( V_19 , L_11 , V_41 ) ;
break;
case V_71 :
default:
V_59 |= V_70 ;
F_36 ( V_19 , L_12 , V_41 ) ;
break;
}
if ( F_15 ( V_9 , V_33 , V_59 ) )
F_36 ( V_19 , L_29 ) ;
}
if ( ( V_53 & ( V_75 | V_77 | V_80 ) ) !=
( V_95 & ( V_75 | V_77 | V_80 ) ) ) {
F_24 ( V_9 , & V_59 ) ;
V_59 &= ~ V_73 ;
if ( V_53 & V_75 ) {
if ( V_53 & V_80 ) {
if ( V_53 & V_77 ) {
V_59 |= V_79 ;
F_36 ( V_19 , L_18 , V_41 ) ;
} else {
V_59 |= V_81 ;
F_36 ( V_19 , L_19 , V_41 ) ;
}
} else {
if ( V_53 & V_77 ) {
V_59 |= V_76 ;
F_36 ( V_19 , L_16 , V_41 ) ;
} else {
V_59 |= V_78 ;
F_36 ( V_19 , L_17 , V_41 ) ;
}
}
}
if ( F_15 ( V_9 , V_33 , V_59 ) )
F_36 ( V_19 , L_30 ) ;
}
if ( ( V_53 & V_82 ) != ( V_95 & V_82 ) ) {
F_24 ( V_9 , & V_59 ) ;
V_59 &= ~ V_83 ;
if ( V_53 & V_82 ) {
V_59 |= V_86 ;
F_36 ( V_19 , L_23 , V_41 ) ;
} else {
V_59 |= V_84 ;
F_36 ( V_19 , L_21 , V_41 ) ;
}
if ( F_15 ( V_9 , V_33 , V_59 ) )
F_36 ( V_19 , L_31 ) ;
}
if ( ( V_53 & V_90 ) != ( V_95 & V_90 ) ) {
struct V_57 V_58 ;
T_2 V_60 ;
T_2 V_96 ;
F_2 ( V_9 , V_87 , & V_58 ,
sizeof( V_58 ) ) ;
V_60 = F_10 ( V_58 . V_88 ) ;
V_96 = F_10 ( V_58 . V_97 ) ;
F_36 ( V_19 , L_32 ,
V_41 , V_60 , V_96 ) ;
V_60 &= ~ V_98 ;
V_60 &= ~ V_99 ;
V_60 &= ~ V_100 ;
V_60 &= ~ V_101 ;
V_60 |= F_39 ( V_102 ) ;
if ( V_53 & V_90 ) {
V_60 |= V_89 ;
V_96 &= ~ V_103 ;
V_96 |= F_40 (
V_104 ) ;
F_36 ( V_19 , L_25 , V_41 ) ;
} else {
V_60 &= ~ V_89 ;
V_96 &= ~ V_103 ;
V_96 |= F_40 (
V_105 ) ;
F_36 ( V_19 , L_26 , V_41 ) ;
}
F_36 ( V_19 , L_33 ,
V_41 , V_60 , V_96 ) ;
V_58 . V_88 = F_20 ( V_60 ) ;
V_58 . V_97 = F_20 ( V_96 ) ;
F_17 ( V_9 , V_106 , & V_58 ,
sizeof( V_58 ) ) ;
}
}
static int F_41 ( struct V_37 * V_38 ,
unsigned int V_107 , unsigned int V_108 )
{
struct V_8 * V_9 = V_38 -> V_50 ;
return F_42 ( V_9 , V_107 , V_108 ) ;
}
static int F_42 ( struct V_8 * V_9 ,
unsigned int V_107 , unsigned int V_108 )
{
T_4 V_109 = 0 ;
if ( V_107 & V_110 ) {
V_109 |= V_111 ;
V_109 |= V_112 ;
}
if ( V_107 & V_113 ) {
V_109 |= V_114 ;
V_109 |= V_115 ;
}
if ( V_108 & V_110 ) {
V_109 &= ~ V_111 ;
V_109 |= V_112 ;
}
if ( V_108 & V_113 ) {
V_109 &= ~ V_114 ;
V_109 |= V_115 ;
}
F_36 ( & V_9 -> V_19 , L_34 , V_41 , V_109 ) ;
return F_15 ( V_9 , V_116 , V_109 ) ;
}
static void F_43 ( struct V_8 * V_117 , int V_118 )
{
if ( V_118 )
F_42 ( V_117 , V_113 | V_110 , 0 ) ;
else
F_42 ( V_117 , 0 , V_113 | V_110 ) ;
}
static int F_44 ( struct V_37 * V_38 )
{
struct V_8 * V_9 = V_38 -> V_50 ;
T_1 V_109 ;
int V_16 ;
V_16 = F_13 ( V_9 , V_119 , & V_109 ) ;
if ( V_16 )
return V_16 ;
V_16 = ( ( V_109 & V_114 ) ? V_113 : 0 )
| ( ( V_109 & V_111 ) ? V_110 : 0 )
| ( ( V_109 & V_120 ) ? V_121 : 0 )
| ( ( V_109 & V_122 ) ? V_123 : 0 )
| ( ( V_109 & V_124 ) ? V_125 : 0 )
| ( ( V_109 & V_126 ) ? V_127 : 0 ) ;
F_36 ( & V_9 -> V_19 , L_35 , V_41 , V_109 ) ;
return V_16 ;
}
static void F_45 ( struct V_37 * V_38 , int V_128 )
{
struct V_8 * V_9 = V_38 -> V_50 ;
T_4 V_129 ;
if ( V_128 == 0 )
V_129 = V_130 ;
else
V_129 = V_131 ;
F_36 ( & V_9 -> V_19 , L_36 , V_41 ,
V_129 == V_130 ? L_37 : L_38 ) ;
F_15 ( V_9 , V_132 , V_129 ) ;
}
static int F_46 ( struct V_133 * V_134 , unsigned int V_135 )
{
struct V_1 * V_2 = F_47 ( V_134 ) ;
struct V_136 * V_137 = F_48 ( V_2 ) ;
switch ( V_135 ) {
case 0 :
if ( V_137 -> V_138 & V_139 )
return - V_140 ;
break;
case 1 :
if ( V_137 -> V_138 & ( V_141 |
V_142 ) )
return - V_140 ;
break;
}
return 0 ;
}
static int F_49 ( struct V_133 * V_134 , unsigned int V_143 )
{
struct V_1 * V_2 = F_47 ( V_134 ) ;
int V_16 ;
T_1 V_11 ;
V_16 = F_14 ( V_2 , V_20 ,
V_144 , & V_11 , sizeof( V_11 ) ) ;
if ( V_16 < 0 )
return V_16 ;
return ! ! ( V_11 & F_50 ( V_143 ) ) ;
}
static void F_51 ( struct V_133 * V_134 , unsigned int V_143 , int V_145 )
{
struct V_1 * V_2 = F_47 ( V_134 ) ;
struct V_146 V_11 ;
if ( V_145 == 1 )
V_11 . V_129 = F_50 ( V_143 ) ;
else
V_11 . V_129 = 0 ;
V_11 . V_147 = F_50 ( V_143 ) ;
F_21 ( V_2 , V_29 ,
V_148 , & V_11 , sizeof( V_11 ) ) ;
}
static int F_52 ( struct V_133 * V_134 , unsigned int V_143 )
{
return 0 ;
}
static int F_53 ( struct V_133 * V_134 , unsigned int V_143 )
{
return - V_149 ;
}
static int F_54 ( struct V_133 * V_134 , unsigned int V_143 ,
int V_145 )
{
return 0 ;
}
static int F_55 ( struct V_133 * V_134 , unsigned int V_143 ,
unsigned long V_138 )
{
struct V_1 * V_2 = F_47 ( V_134 ) ;
struct V_136 * V_137 = F_48 ( V_2 ) ;
enum V_150 V_151 = F_56 ( V_138 ) ;
if ( ( V_151 == V_152 ) &&
( V_137 -> V_153 & F_50 ( V_143 ) ) )
return 0 ;
if ( ( V_151 == V_154 ) &&
! ( V_137 -> V_153 & F_50 ( V_143 ) ) )
return 0 ;
return - V_149 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_136 * V_137 = F_48 ( V_2 ) ;
struct V_155 V_156 ;
struct V_157 V_138 ;
T_1 V_158 = F_1 ( V_2 ) ;
int V_16 ;
V_16 = F_14 ( V_2 , V_159 ,
V_160 , & V_156 ,
sizeof( V_156 ) ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_14 ( V_2 , V_159 ,
V_161 , & V_138 ,
sizeof( V_138 ) ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_158 == 0 ) {
if ( V_156 . V_162 == V_163 )
return 0 ;
V_137 -> V_138 = V_138 . V_164 ;
V_137 -> V_153 = ( T_1 ) ( ( F_12 ( V_138 . V_153 ) &
V_165 ) >>
V_166 ) ;
V_137 -> V_134 . V_167 = 2 ;
} else if ( V_158 == 1 ) {
if ( V_156 . V_168 == V_163 )
return 0 ;
V_137 -> V_138 = V_138 . V_169 ;
V_137 -> V_153 = ( T_1 ) ( ( F_12 ( V_138 . V_153 ) &
V_170 ) >>
V_171 ) ;
V_137 -> V_134 . V_167 = 3 ;
} else {
return - V_140 ;
}
V_137 -> V_134 . V_172 = L_39 ;
V_137 -> V_134 . V_173 = F_46 ;
V_137 -> V_134 . V_174 = F_52 ;
V_137 -> V_134 . V_175 = F_53 ;
V_137 -> V_134 . V_176 = F_54 ;
V_137 -> V_134 . V_177 = F_49 ;
V_137 -> V_134 . V_107 = F_51 ;
V_137 -> V_134 . V_178 = F_55 ;
V_137 -> V_134 . V_179 = V_180 ;
V_137 -> V_134 . V_181 = & V_2 -> V_5 -> V_19 ;
V_137 -> V_134 . V_182 = - 1 ;
V_137 -> V_134 . V_183 = true ;
V_16 = F_58 ( & V_137 -> V_134 , V_2 ) ;
if ( ! V_16 )
V_137 -> V_184 = true ;
return V_16 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_136 * V_137 = F_48 ( V_2 ) ;
if ( V_137 -> V_184 ) {
F_60 ( & V_137 -> V_134 ) ;
V_137 -> V_184 = false ;
}
}
static int F_57 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
}
static int F_61 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_13 * V_14 ;
int V_185 ;
V_14 = F_62 ( sizeof( * V_14 ) , V_17 ) ;
if ( ! V_14 )
return - V_18 ;
V_14 -> V_7 = F_1 ( V_2 ) ;
F_63 ( V_9 , V_14 ) ;
V_185 = F_22 ( V_9 ) ;
if ( V_185 ) {
F_8 ( V_14 ) ;
return V_185 ;
}
return 0 ;
}
static int F_64 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
V_14 = F_3 ( V_9 ) ;
F_8 ( V_14 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_16 ;
struct V_136 * V_137 ;
V_137 = F_62 ( sizeof( * V_137 ) , V_17 ) ;
if ( ! V_137 )
return - V_18 ;
V_16 = F_14 ( V_2 , V_159 ,
V_186 , & V_137 -> V_187 ,
sizeof( V_137 -> V_187 ) ) ;
if ( V_16 < 0 )
goto V_188;
F_66 ( V_2 , V_137 ) ;
if ( V_137 -> V_187 == V_189 ) {
V_16 = F_57 ( V_2 ) ;
if ( V_16 < 0 ) {
F_7 ( & V_2 -> V_5 -> V_19 ,
L_40 ) ;
}
}
return 0 ;
V_188:
F_8 ( V_137 ) ;
return V_16 ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_136 * V_137 = F_48 ( V_2 ) ;
F_59 ( V_2 ) ;
F_8 ( V_137 ) ;
}
