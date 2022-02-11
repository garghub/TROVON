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
if ( V_2 -> V_43 . V_44 != V_45 )
goto V_46;
if ( ! V_2 -> V_47 ) {
F_17 ( & V_2 -> V_25 ) ;
if ( ! F_3 ( V_2 ) ) {
V_11 = F_1 ( V_2 , 1 ) ;
if ( V_11 )
goto V_46;
V_11 = F_5 ( V_2 ) ;
if ( V_11 )
goto V_46;
F_12 ( V_2 ) ;
}
}
while ( V_42 ) {
V_11 = F_18 ( V_5 ,
V_9 | V_48 ) ;
if ( V_11 < 0 )
goto V_46;
V_40 = V_11 ;
V_11 = F_18 ( V_5 ,
V_9 | V_49 ) ;
if ( V_11 < 0 )
goto V_46;
V_41 = V_11 ;
V_42 = F_15 ( V_2 , V_40 ) ;
}
V_2 -> V_50 = F_11 ( V_40 , V_2 -> V_14 -> V_15 ) ;
V_2 -> V_51 = F_11 ( V_41 , V_2 -> V_14 -> V_15 ) ;
if ( ! V_2 -> V_47 )
F_19 ( & V_2 -> V_25 , 5 * V_52 ) ;
V_11 = 0 ;
V_46:
return V_11 ;
}
static inline int F_20 ( T_2 V_53 )
{
return ( int ) ( ( ( V_53 * V_54 ) +
V_55 ) >> V_56 ) ;
}
static inline T_2 F_21 ( int V_57 )
{
return ( ( ( T_2 ) V_57 ) << V_56 ) / V_54 ;
}
static unsigned int F_22 ( T_2 V_40 , T_2 V_41 )
{
const struct V_58 * V_59 = V_60 ;
unsigned long V_61 , V_62 , V_63 = V_40 , V_64 = V_41 ;
V_61 = V_63 ? ( ( V_64 << V_65 ) / V_63 ) : V_66 ;
while ( V_59 -> V_67 < V_61 )
V_59 ++ ;
V_62 = V_63 * V_59 -> V_68 - V_64 * V_59 -> V_69 ;
return ( unsigned int ) ( V_62 >> V_65 ) ;
}
static T_2 F_23 ( T_2 V_36 , T_2 V_53 )
{
unsigned long V_70 = V_36 ;
V_70 *= V_53 ;
V_70 >>= V_56 ;
return ( T_2 ) V_70 ;
}
static int F_24 ( struct V_71 * V_72 ,
struct V_73 const * V_74 ,
int V_75 ,
int V_76 ,
long V_77 )
{
struct V_1 * V_2 = F_25 ( V_72 ) ;
if ( V_74 -> V_78 == 0 )
V_2 -> V_79 = F_21 ( V_75 ) ;
else
V_2 -> V_80 = F_21 ( V_75 ) ;
return 0 ;
}
static int F_26 ( struct V_71 * V_72 ,
struct V_73 const * V_74 ,
int * V_75 ,
int * V_76 ,
long V_81 )
{
int V_11 = - V_82 ;
T_2 V_79 , V_80 ;
struct V_1 * V_2 = F_25 ( V_72 ) ;
F_27 ( & V_2 -> V_83 ) ;
switch ( V_81 ) {
case 0 :
switch ( V_74 -> type ) {
case V_84 :
V_11 = F_16 ( V_2 ) ;
if ( V_11 )
goto V_16;
V_79 = F_23 ( V_2 -> V_50 , V_2 -> V_79 ) *
V_2 -> V_85 ;
V_80 = F_23 ( V_2 -> V_51 , V_2 -> V_80 ) *
V_2 -> V_85 ;
* V_75 = F_22 ( V_79 , V_80 ) ;
V_11 = V_86 ;
break;
case V_87 :
V_11 = F_16 ( V_2 ) ;
if ( V_11 )
goto V_16;
if ( V_74 -> V_78 == 0 )
* V_75 = V_2 -> V_50 ;
else
* V_75 = V_2 -> V_51 ;
V_11 = V_86 ;
break;
default:
break;
}
break;
case ( 1 << V_88 ) :
if ( V_74 -> V_78 == 0 )
* V_75 = F_20 ( V_2 -> V_79 ) ;
else
* V_75 = F_20 ( V_2 -> V_80 ) ;
V_11 = V_86 ;
break;
default:
V_11 = - V_82 ;
goto V_16;
}
V_16:
F_28 ( & V_2 -> V_83 ) ;
return V_11 ;
}
static int F_29 ( struct V_71 * V_72 ,
T_4 V_89 ,
int * V_75 )
{
struct V_1 * V_2 = F_25 ( V_72 ) ;
switch ( F_30 ( V_89 ) ) {
case V_90 :
* V_75 = V_2 -> V_18 ;
break;
case V_91 :
* V_75 = V_2 -> V_21 ;
break;
default:
return - V_82 ;
}
return 0 ;
}
static int F_31 ( struct V_71 * V_72 ,
T_4 V_89 ,
int V_75 )
{
struct V_1 * V_2 = F_25 ( V_72 ) ;
int V_11 ;
T_1 V_92 ;
if ( F_30 ( V_89 ) == V_90 )
V_92 = V_17 ;
else
V_92 = V_20 ;
F_27 ( & V_2 -> V_83 ) ;
V_11 = F_2 ( V_2 -> V_5 , V_9 | V_92 ,
V_75 & 0xFF ) ;
if ( V_11 )
goto V_16;
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | ( V_92 + 1 ) ,
( V_75 >> 8 ) & 0xFF ) ;
if ( F_30 ( V_89 ) == V_90 )
V_2 -> V_18 = V_75 ;
else
V_2 -> V_21 = V_75 ;
V_16:
F_28 ( & V_2 -> V_83 ) ;
return V_11 ;
}
static T_5 F_32 ( int V_93 , void * V_94 )
{
struct V_71 * V_95 = V_94 ;
struct V_1 * V_2 = F_25 ( V_95 ) ;
F_33 ( V_95 ,
F_34 ( V_84 ,
0 ,
V_96 ,
V_97 ) ,
F_35 () ) ;
F_36 ( V_2 -> V_5 , V_9 | V_98 ) ;
return V_99 ;
}
static int F_37 ( struct V_71 * V_72 ,
T_4 V_89 ,
int V_43 )
{
struct V_1 * V_2 = F_25 ( V_72 ) ;
int V_11 = 0 ;
F_27 ( & V_2 -> V_83 ) ;
if ( V_43 && ! ( V_2 -> V_100 & 0x30 ) ) {
V_2 -> V_100 &= ~ 0x30 ;
V_2 -> V_100 |= 0x10 ;
F_17 ( & V_2 -> V_25 ) ;
if ( ! F_3 ( V_2 ) ) {
V_11 = F_1 ( V_2 , 1 ) ;
if ( V_11 )
goto V_46;
V_11 = F_5 ( V_2 ) ;
if ( V_11 )
goto V_46;
}
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | V_101 ,
V_2 -> V_100 ) ;
V_2 -> V_47 = true ;
}
if ( ! V_43 && ( V_2 -> V_100 & 0x30 ) ) {
V_2 -> V_100 |= ~ 0x30 ;
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | V_101 ,
V_2 -> V_100 ) ;
V_2 -> V_47 = false ;
F_19 ( & V_2 -> V_25 , 5 * V_52 ) ;
}
V_46:
F_28 ( & V_2 -> V_83 ) ;
return V_11 ;
}
static int F_38 ( struct V_71 * V_72 ,
T_4 V_89 )
{
struct V_1 * V_2 = F_25 ( V_72 ) ;
int V_11 ;
F_27 ( & V_2 -> V_83 ) ;
V_11 = F_4 ( V_2 -> V_5 ,
V_9 | V_101 ) ;
F_28 ( & V_2 -> V_83 ) ;
if ( V_11 < 0 )
goto V_16;
V_11 = ! ! ( V_11 & 0x30 ) ;
V_16:
return V_11 ;
}
static int T_6 F_39 ( struct V_4 * V_5 ,
const struct V_102 * V_103 )
{
struct V_71 * V_72 ;
struct V_1 * V_2 ;
struct V_104 * V_105 = V_5 -> V_106 . V_107 ;
int V_108 = 0 ;
int V_11 ;
T_1 V_27 = 0 ;
V_72 = F_40 ( sizeof( * V_2 ) ) ;
if ( ! V_72 )
return - V_109 ;
V_2 = F_25 ( V_72 ) ;
F_41 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
V_108 = F_8 ( V_2 ) ;
if ( V_108 ) {
F_42 ( & V_5 -> V_106 , L_1 , - V_108 ) ;
goto V_110;
}
V_108 = F_9 ( V_2 , & V_27 ) ;
if ( V_108 )
goto V_110;
F_43 ( & V_2 -> V_83 ) ;
V_2 -> V_21 = 0x0 ;
V_2 -> V_18 = 0xffff ;
V_2 -> V_14 = V_111 ;
V_2 -> V_100 = F_44 ( 4 ) ;
V_2 -> V_79 = F_21 ( V_54 ) ;
V_2 -> V_80 = F_21 ( V_54 ) ;
if ( V_105 )
V_2 -> V_85 = V_105 -> V_85 ;
else
V_2 -> V_85 = 1 ;
V_95 ( & V_5 -> V_106 , L_2 , V_27 >> 4 , V_27 & 0x0f ) ;
V_72 -> V_112 = V_5 -> V_112 ;
V_72 -> V_113 = V_114 ;
V_72 -> V_115 = F_45 ( V_114 ) ;
V_72 -> V_106 . V_116 = & V_5 -> V_106 ;
V_72 -> V_117 = V_118 ;
if ( V_5 -> V_93 )
V_72 -> V_119 = & V_120 ;
else
V_72 -> V_119 = & V_121 ;
if ( V_5 -> V_93 ) {
V_11 = F_46 ( V_5 -> V_93 ,
NULL ,
& F_32 ,
V_122 | V_123 ,
L_3 ,
V_72 ) ;
if ( V_11 )
goto V_124;
}
V_108 = F_5 ( V_2 ) ;
if ( V_108 )
goto V_125;
F_47 ( & V_2 -> V_25 , F_6 ) ;
F_19 ( & V_2 -> V_25 , 5 * V_52 ) ;
V_11 = F_48 ( V_72 ) ;
if ( V_11 )
goto V_125;
return 0 ;
V_125:
if ( V_5 -> V_93 )
F_49 ( V_5 -> V_93 , V_72 ) ;
V_124:
F_50 ( V_72 ) ;
V_110:
F_51 ( V_2 ) ;
return V_108 ;
}
static int F_52 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_53 ( V_5 ) ;
struct V_71 * V_72 = F_54 ( V_2 ) ;
F_55 ( V_72 ) ;
if ( ! V_2 -> V_47 )
F_17 ( & V_2 -> V_25 ) ;
V_2 -> V_100 |= ~ 0x30 ;
F_2 ( V_2 -> V_5 , V_9 | V_101 ,
V_2 -> V_100 ) ;
F_56 () ;
F_1 ( V_2 , 0 ) ;
if ( V_5 -> V_93 )
F_49 ( V_5 -> V_93 , V_72 ) ;
F_50 ( V_72 ) ;
return 0 ;
}
static int F_57 ( struct V_4 * V_5 , T_7 V_43 )
{
struct V_1 * V_2 = F_53 ( V_5 ) ;
int V_11 ;
F_27 ( & V_2 -> V_83 ) ;
V_11 = F_1 ( V_2 , 0 ) ;
if ( V_11 )
goto V_46;
V_2 -> V_43 = V_43 ;
V_46:
F_28 ( & V_2 -> V_83 ) ;
return V_11 ;
}
static int F_58 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_53 ( V_5 ) ;
int V_11 ;
F_27 ( & V_2 -> V_83 ) ;
V_11 = F_1 ( V_2 , 1 ) ;
if ( V_11 )
goto V_46;
V_11 = F_5 ( V_2 ) ;
if ( V_11 )
goto V_46;
V_2 -> V_43 . V_44 = V_45 ;
V_46:
F_28 ( & V_2 -> V_83 ) ;
return V_11 ;
}
static int T_8 F_59 ( void )
{
return F_60 ( & V_126 ) ;
}
static void T_9 F_61 ( void )
{
F_62 ( & V_126 ) ;
}
