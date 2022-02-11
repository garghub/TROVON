static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 ;
V_6 = V_3 ? V_7 : V_8 ;
return F_2 ( V_5 ,
V_9 | V_10 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_11 ;
V_11 = F_4 ( V_5 , V_9 | V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return ( V_11 & V_12 ) == V_7 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | V_13 ,
V_2 -> V_14 -> V_15 ) ;
if ( V_11 )
goto V_16;
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | V_17 ,
V_2 -> V_18 & 0xFF ) ;
if ( V_11 )
goto V_16;
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | V_19 ,
( V_2 -> V_18 >> 8 ) & 0xFF ) ;
if ( V_11 )
goto V_16;
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | V_20 ,
V_2 -> V_21 & 0xFF ) ;
if ( V_11 )
goto V_16;
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | V_22 ,
( V_2 -> V_21 >> 8 ) & 0xFF ) ;
V_16:
return V_11 ;
}
static void F_6 ( struct V_23 * V_24 )
{
struct V_1 * V_2 =
F_7 ( V_24 , struct V_1 , V_25 . V_24 ) ;
F_1 ( V_2 , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_1 ( V_2 , 1 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_3 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_11 ? 0 : - V_26 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_27 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_11 ;
V_11 = F_4 ( V_5 , V_9 | V_28 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_27 = V_11 ;
return 0 ;
}
static int F_10 ( T_1 V_29 )
{
int V_30 = 0 ;
switch ( V_29 & V_31 ) {
case V_32 :
V_30 += 5 ;
break;
case V_33 :
V_30 += 2 ;
break;
case V_34 :
break;
}
if ( ! ( V_29 & V_35 ) )
V_30 += 4 ;
return V_30 ;
}
static T_2 F_11 ( T_3 V_36 , T_1 V_29 )
{
return V_36 << F_10 ( V_29 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned int V_37 ;
switch ( V_2 -> V_14 -> V_15 & V_31 ) {
case V_32 :
V_37 = 14 ;
break;
case V_33 :
V_37 = 101 ;
break;
default:
V_37 = 402 ;
}
F_13 ( F_14 ( V_37 ) + 2 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_3 V_36 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_36 > V_2 -> V_14 -> V_38 || V_36 < V_2 -> V_14 -> V_39 ) {
( V_36 > V_2 -> V_14 -> V_38 ) ?
V_2 -> V_14 ++ : V_2 -> V_14 -- ;
F_2 ( V_5 ,
V_9 | V_13 ,
V_2 -> V_14 -> V_15 ) ;
F_12 ( V_2 ) ;
F_12 ( V_2 ) ;
return 1 ;
} else
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_3 V_40 , V_41 ;
int V_42 = 1 ;
int V_11 = 0 ;
if ( V_2 -> V_43 )
goto V_44;
if ( ! V_2 -> V_45 ) {
F_17 ( & V_2 -> V_25 ) ;
if ( ! F_3 ( V_2 ) ) {
V_11 = F_1 ( V_2 , 1 ) ;
if ( V_11 )
goto V_44;
V_11 = F_5 ( V_2 ) ;
if ( V_11 )
goto V_44;
F_12 ( V_2 ) ;
}
}
while ( V_42 ) {
V_11 = F_18 ( V_5 ,
V_9 | V_46 ) ;
if ( V_11 < 0 )
goto V_44;
V_40 = V_11 ;
V_11 = F_18 ( V_5 ,
V_9 | V_47 ) ;
if ( V_11 < 0 )
goto V_44;
V_41 = V_11 ;
V_42 = F_15 ( V_2 , V_40 ) ;
}
V_2 -> V_48 = F_11 ( V_40 , V_2 -> V_14 -> V_15 ) ;
V_2 -> V_49 = F_11 ( V_41 , V_2 -> V_14 -> V_15 ) ;
if ( ! V_2 -> V_45 )
F_19 ( & V_2 -> V_25 , 5 * V_50 ) ;
V_11 = 0 ;
V_44:
return V_11 ;
}
static inline int F_20 ( T_2 V_51 )
{
return ( int ) ( ( ( V_51 * V_52 ) +
V_53 ) >> V_54 ) ;
}
static inline T_2 F_21 ( int V_55 )
{
return ( ( ( T_2 ) V_55 ) << V_54 ) / V_52 ;
}
static unsigned int F_22 ( T_2 V_40 , T_2 V_41 )
{
const struct V_56 * V_57 = V_58 ;
unsigned long V_59 , V_60 , V_61 = V_40 , V_62 = V_41 ;
V_59 = V_61 ? ( ( V_62 << V_63 ) / V_61 ) : V_64 ;
while ( V_57 -> V_65 < V_59 )
V_57 ++ ;
V_60 = V_61 * V_57 -> V_66 - V_62 * V_57 -> V_67 ;
return ( unsigned int ) ( V_60 >> V_63 ) ;
}
static T_2 F_23 ( T_2 V_36 , T_2 V_51 )
{
unsigned long V_68 = V_36 ;
V_68 *= V_51 ;
V_68 >>= V_54 ;
return ( T_2 ) V_68 ;
}
static int F_24 ( struct V_69 * V_70 ,
struct V_71 const * V_72 ,
int V_73 ,
int V_74 ,
long V_75 )
{
struct V_1 * V_2 = F_25 ( V_70 ) ;
if ( V_72 -> V_76 == V_77 )
V_2 -> V_78 = F_21 ( V_73 ) ;
else
V_2 -> V_79 = F_21 ( V_73 ) ;
return 0 ;
}
static int F_26 ( struct V_69 * V_70 ,
struct V_71 const * V_72 ,
int * V_73 ,
int * V_74 ,
long V_80 )
{
int V_11 = - V_81 ;
T_2 V_78 , V_79 ;
struct V_1 * V_2 = F_25 ( V_70 ) ;
F_27 ( & V_2 -> V_82 ) ;
switch ( V_80 ) {
case V_83 :
case V_84 :
switch ( V_72 -> type ) {
case V_85 :
V_11 = F_16 ( V_2 ) ;
if ( V_11 )
goto V_16;
V_78 = F_23 ( V_2 -> V_48 , V_2 -> V_78 ) *
V_2 -> V_86 ;
V_79 = F_23 ( V_2 -> V_49 , V_2 -> V_79 ) *
V_2 -> V_86 ;
* V_73 = F_22 ( V_78 , V_79 ) ;
V_11 = V_87 ;
break;
case V_88 :
V_11 = F_16 ( V_2 ) ;
if ( V_11 )
goto V_16;
if ( V_72 -> V_76 == 0 )
* V_73 = V_2 -> V_48 ;
else
* V_73 = V_2 -> V_49 ;
V_11 = V_87 ;
break;
default:
break;
}
break;
case V_89 :
if ( V_72 -> V_76 == 0 )
* V_73 = F_20 ( V_2 -> V_78 ) ;
else
* V_73 = F_20 ( V_2 -> V_79 ) ;
V_11 = V_87 ;
break;
default:
V_11 = - V_81 ;
goto V_16;
}
V_16:
F_28 ( & V_2 -> V_82 ) ;
return V_11 ;
}
static int F_29 ( struct V_69 * V_70 ,
T_4 V_90 ,
int * V_73 )
{
struct V_1 * V_2 = F_25 ( V_70 ) ;
switch ( F_30 ( V_90 ) ) {
case V_91 :
* V_73 = V_2 -> V_18 ;
break;
case V_92 :
* V_73 = V_2 -> V_21 ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static int F_31 ( struct V_69 * V_70 ,
T_4 V_90 ,
int V_73 )
{
struct V_1 * V_2 = F_25 ( V_70 ) ;
int V_11 ;
T_1 V_93 ;
if ( F_30 ( V_90 ) == V_91 )
V_93 = V_17 ;
else
V_93 = V_20 ;
F_27 ( & V_2 -> V_82 ) ;
V_11 = F_2 ( V_2 -> V_5 , V_9 | V_93 ,
V_73 & 0xFF ) ;
if ( V_11 )
goto V_16;
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | ( V_93 + 1 ) ,
( V_73 >> 8 ) & 0xFF ) ;
if ( F_30 ( V_90 ) == V_91 )
V_2 -> V_18 = V_73 ;
else
V_2 -> V_21 = V_73 ;
V_16:
F_28 ( & V_2 -> V_82 ) ;
return V_11 ;
}
static T_5 F_32 ( int V_94 , void * V_95 )
{
struct V_69 * V_96 = V_95 ;
struct V_1 * V_2 = F_25 ( V_96 ) ;
F_33 ( V_96 ,
F_34 ( V_85 ,
0 ,
V_97 ,
V_98 ) ,
F_35 () ) ;
F_36 ( V_2 -> V_5 , V_9 | V_99 ) ;
return V_100 ;
}
static int F_37 ( struct V_69 * V_70 ,
T_4 V_90 ,
int V_101 )
{
struct V_1 * V_2 = F_25 ( V_70 ) ;
int V_11 = 0 ;
F_27 ( & V_2 -> V_82 ) ;
if ( V_101 && ! ( V_2 -> V_102 & 0x30 ) ) {
V_2 -> V_102 &= ~ 0x30 ;
V_2 -> V_102 |= 0x10 ;
F_17 ( & V_2 -> V_25 ) ;
if ( ! F_3 ( V_2 ) ) {
V_11 = F_1 ( V_2 , 1 ) ;
if ( V_11 )
goto V_44;
V_11 = F_5 ( V_2 ) ;
if ( V_11 )
goto V_44;
}
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | V_103 ,
V_2 -> V_102 ) ;
V_2 -> V_45 = true ;
}
if ( ! V_101 && ( V_2 -> V_102 & 0x30 ) ) {
V_2 -> V_102 |= ~ 0x30 ;
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | V_103 ,
V_2 -> V_102 ) ;
V_2 -> V_45 = false ;
F_19 ( & V_2 -> V_25 , 5 * V_50 ) ;
}
V_44:
F_28 ( & V_2 -> V_82 ) ;
return V_11 ;
}
static int F_38 ( struct V_69 * V_70 ,
T_4 V_90 )
{
struct V_1 * V_2 = F_25 ( V_70 ) ;
int V_11 ;
F_27 ( & V_2 -> V_82 ) ;
V_11 = F_4 ( V_2 -> V_5 ,
V_9 | V_103 ) ;
F_28 ( & V_2 -> V_82 ) ;
if ( V_11 < 0 )
goto V_16;
V_11 = ! ! ( V_11 & 0x30 ) ;
V_16:
return V_11 ;
}
static int T_6 F_39 ( struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_69 * V_70 ;
struct V_1 * V_2 ;
struct V_106 * V_107 = V_5 -> V_108 . V_109 ;
int V_110 = 0 ;
T_1 V_27 = 0 ;
V_70 = F_40 ( sizeof( * V_2 ) ) ;
if ( ! V_70 )
return - V_111 ;
V_2 = F_25 ( V_70 ) ;
F_41 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
V_110 = F_8 ( V_2 ) ;
if ( V_110 ) {
F_42 ( & V_5 -> V_108 , L_1 , - V_110 ) ;
goto V_112;
}
V_110 = F_9 ( V_2 , & V_27 ) ;
if ( V_110 ) {
F_42 ( & V_5 -> V_108 , L_2 , - V_110 ) ;
goto V_112;
}
F_43 ( & V_2 -> V_82 ) ;
V_2 -> V_21 = 0x0 ;
V_2 -> V_18 = 0xffff ;
V_2 -> V_14 = V_113 ;
V_2 -> V_102 = F_44 ( 4 ) ;
V_2 -> V_78 = F_21 ( V_52 ) ;
V_2 -> V_79 = F_21 ( V_52 ) ;
if ( V_107 )
V_2 -> V_86 = V_107 -> V_86 ;
else
V_2 -> V_86 = 1 ;
V_96 ( & V_5 -> V_108 , L_3 , V_27 >> 4 , V_27 & 0x0f ) ;
V_70 -> V_114 = V_5 -> V_114 ;
V_70 -> V_115 = V_116 ;
V_70 -> V_117 = F_45 ( V_116 ) ;
V_70 -> V_108 . V_118 = & V_5 -> V_108 ;
V_70 -> V_119 = V_120 ;
if ( V_5 -> V_94 )
V_70 -> V_121 = & V_122 ;
else
V_70 -> V_121 = & V_123 ;
if ( V_5 -> V_94 ) {
V_110 = F_46 ( V_5 -> V_94 ,
NULL ,
& F_32 ,
V_124 | V_125 ,
L_4 ,
V_70 ) ;
if ( V_110 ) {
F_42 ( & V_5 -> V_108 , L_5 , - V_110 ) ;
goto V_112;
}
}
V_110 = F_5 ( V_2 ) ;
if ( V_110 ) {
F_42 ( & V_5 -> V_108 , L_6 , - V_110 ) ;
goto V_126;
}
F_47 ( & V_2 -> V_25 , F_6 ) ;
F_19 ( & V_2 -> V_25 , 5 * V_50 ) ;
V_110 = F_48 ( V_70 ) ;
if ( V_110 ) {
F_42 ( & V_5 -> V_108 , L_7 , - V_110 ) ;
goto V_127;
}
return 0 ;
V_127:
F_17 ( & V_2 -> V_25 ) ;
F_49 () ;
V_126:
if ( V_5 -> V_94 )
F_50 ( V_5 -> V_94 , V_70 ) ;
V_112:
F_51 ( V_70 ) ;
return V_110 ;
}
static int T_7 F_52 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_53 ( V_5 ) ;
struct V_69 * V_70 = F_54 ( V_2 ) ;
F_55 ( V_70 ) ;
if ( ! V_2 -> V_45 )
F_17 ( & V_2 -> V_25 ) ;
V_2 -> V_102 |= ~ 0x30 ;
F_2 ( V_2 -> V_5 , V_9 | V_103 ,
V_2 -> V_102 ) ;
F_49 () ;
F_1 ( V_2 , 0 ) ;
if ( V_5 -> V_94 )
F_50 ( V_5 -> V_94 , V_70 ) ;
F_51 ( V_70 ) ;
return 0 ;
}
static int F_56 ( struct V_128 * V_108 )
{
struct V_1 * V_2 = F_53 ( F_57 ( V_108 ) ) ;
int V_11 ;
F_27 ( & V_2 -> V_82 ) ;
V_11 = F_1 ( V_2 , 0 ) ;
if ( V_11 )
goto V_44;
V_2 -> V_43 = true ;
V_44:
F_28 ( & V_2 -> V_82 ) ;
return V_11 ;
}
static int F_58 ( struct V_128 * V_108 )
{
struct V_1 * V_2 = F_53 ( F_57 ( V_108 ) ) ;
int V_11 ;
F_27 ( & V_2 -> V_82 ) ;
V_11 = F_1 ( V_2 , 1 ) ;
if ( V_11 )
goto V_44;
V_11 = F_5 ( V_2 ) ;
if ( V_11 )
goto V_44;
V_2 -> V_43 = false ;
V_44:
F_28 ( & V_2 -> V_82 ) ;
return V_11 ;
}
