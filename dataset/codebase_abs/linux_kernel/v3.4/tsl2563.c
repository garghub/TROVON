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
if ( V_72 -> V_76 == 0 )
V_2 -> V_77 = F_21 ( V_73 ) ;
else
V_2 -> V_78 = F_21 ( V_73 ) ;
return 0 ;
}
static int F_26 ( struct V_69 * V_70 ,
struct V_71 const * V_72 ,
int * V_73 ,
int * V_74 ,
long V_79 )
{
int V_11 = - V_80 ;
T_2 V_77 , V_78 ;
struct V_1 * V_2 = F_25 ( V_70 ) ;
F_27 ( & V_2 -> V_81 ) ;
switch ( V_79 ) {
case 0 :
switch ( V_72 -> type ) {
case V_82 :
V_11 = F_16 ( V_2 ) ;
if ( V_11 )
goto V_16;
V_77 = F_23 ( V_2 -> V_48 , V_2 -> V_77 ) *
V_2 -> V_83 ;
V_78 = F_23 ( V_2 -> V_49 , V_2 -> V_78 ) *
V_2 -> V_83 ;
* V_73 = F_22 ( V_77 , V_78 ) ;
V_11 = V_84 ;
break;
case V_85 :
V_11 = F_16 ( V_2 ) ;
if ( V_11 )
goto V_16;
if ( V_72 -> V_76 == 0 )
* V_73 = V_2 -> V_48 ;
else
* V_73 = V_2 -> V_49 ;
V_11 = V_84 ;
break;
default:
break;
}
break;
case V_86 :
if ( V_72 -> V_76 == 0 )
* V_73 = F_20 ( V_2 -> V_77 ) ;
else
* V_73 = F_20 ( V_2 -> V_78 ) ;
V_11 = V_84 ;
break;
default:
V_11 = - V_80 ;
goto V_16;
}
V_16:
F_28 ( & V_2 -> V_81 ) ;
return V_11 ;
}
static int F_29 ( struct V_69 * V_70 ,
T_4 V_87 ,
int * V_73 )
{
struct V_1 * V_2 = F_25 ( V_70 ) ;
switch ( F_30 ( V_87 ) ) {
case V_88 :
* V_73 = V_2 -> V_18 ;
break;
case V_89 :
* V_73 = V_2 -> V_21 ;
break;
default:
return - V_80 ;
}
return 0 ;
}
static int F_31 ( struct V_69 * V_70 ,
T_4 V_87 ,
int V_73 )
{
struct V_1 * V_2 = F_25 ( V_70 ) ;
int V_11 ;
T_1 V_90 ;
if ( F_30 ( V_87 ) == V_88 )
V_90 = V_17 ;
else
V_90 = V_20 ;
F_27 ( & V_2 -> V_81 ) ;
V_11 = F_2 ( V_2 -> V_5 , V_9 | V_90 ,
V_73 & 0xFF ) ;
if ( V_11 )
goto V_16;
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | ( V_90 + 1 ) ,
( V_73 >> 8 ) & 0xFF ) ;
if ( F_30 ( V_87 ) == V_88 )
V_2 -> V_18 = V_73 ;
else
V_2 -> V_21 = V_73 ;
V_16:
F_28 ( & V_2 -> V_81 ) ;
return V_11 ;
}
static T_5 F_32 ( int V_91 , void * V_92 )
{
struct V_69 * V_93 = V_92 ;
struct V_1 * V_2 = F_25 ( V_93 ) ;
F_33 ( V_93 ,
F_34 ( V_82 ,
0 ,
V_94 ,
V_95 ) ,
F_35 () ) ;
F_36 ( V_2 -> V_5 , V_9 | V_96 ) ;
return V_97 ;
}
static int F_37 ( struct V_69 * V_70 ,
T_4 V_87 ,
int V_98 )
{
struct V_1 * V_2 = F_25 ( V_70 ) ;
int V_11 = 0 ;
F_27 ( & V_2 -> V_81 ) ;
if ( V_98 && ! ( V_2 -> V_99 & 0x30 ) ) {
V_2 -> V_99 &= ~ 0x30 ;
V_2 -> V_99 |= 0x10 ;
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
V_9 | V_100 ,
V_2 -> V_99 ) ;
V_2 -> V_45 = true ;
}
if ( ! V_98 && ( V_2 -> V_99 & 0x30 ) ) {
V_2 -> V_99 |= ~ 0x30 ;
V_11 = F_2 ( V_2 -> V_5 ,
V_9 | V_100 ,
V_2 -> V_99 ) ;
V_2 -> V_45 = false ;
F_19 ( & V_2 -> V_25 , 5 * V_50 ) ;
}
V_44:
F_28 ( & V_2 -> V_81 ) ;
return V_11 ;
}
static int F_38 ( struct V_69 * V_70 ,
T_4 V_87 )
{
struct V_1 * V_2 = F_25 ( V_70 ) ;
int V_11 ;
F_27 ( & V_2 -> V_81 ) ;
V_11 = F_4 ( V_2 -> V_5 ,
V_9 | V_100 ) ;
F_28 ( & V_2 -> V_81 ) ;
if ( V_11 < 0 )
goto V_16;
V_11 = ! ! ( V_11 & 0x30 ) ;
V_16:
return V_11 ;
}
static int T_6 F_39 ( struct V_4 * V_5 ,
const struct V_101 * V_102 )
{
struct V_69 * V_70 ;
struct V_1 * V_2 ;
struct V_103 * V_104 = V_5 -> V_105 . V_106 ;
int V_107 = 0 ;
T_1 V_27 = 0 ;
V_70 = F_40 ( sizeof( * V_2 ) ) ;
if ( ! V_70 )
return - V_108 ;
V_2 = F_25 ( V_70 ) ;
F_41 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
V_107 = F_8 ( V_2 ) ;
if ( V_107 ) {
F_42 ( & V_5 -> V_105 , L_1 , - V_107 ) ;
goto V_109;
}
V_107 = F_9 ( V_2 , & V_27 ) ;
if ( V_107 ) {
F_42 ( & V_5 -> V_105 , L_2 , - V_107 ) ;
goto V_109;
}
F_43 ( & V_2 -> V_81 ) ;
V_2 -> V_21 = 0x0 ;
V_2 -> V_18 = 0xffff ;
V_2 -> V_14 = V_110 ;
V_2 -> V_99 = F_44 ( 4 ) ;
V_2 -> V_77 = F_21 ( V_52 ) ;
V_2 -> V_78 = F_21 ( V_52 ) ;
if ( V_104 )
V_2 -> V_83 = V_104 -> V_83 ;
else
V_2 -> V_83 = 1 ;
V_93 ( & V_5 -> V_105 , L_3 , V_27 >> 4 , V_27 & 0x0f ) ;
V_70 -> V_111 = V_5 -> V_111 ;
V_70 -> V_112 = V_113 ;
V_70 -> V_114 = F_45 ( V_113 ) ;
V_70 -> V_105 . V_115 = & V_5 -> V_105 ;
V_70 -> V_116 = V_117 ;
if ( V_5 -> V_91 )
V_70 -> V_118 = & V_119 ;
else
V_70 -> V_118 = & V_120 ;
if ( V_5 -> V_91 ) {
V_107 = F_46 ( V_5 -> V_91 ,
NULL ,
& F_32 ,
V_121 | V_122 ,
L_4 ,
V_70 ) ;
if ( V_107 ) {
F_42 ( & V_5 -> V_105 , L_5 , - V_107 ) ;
goto V_109;
}
}
V_107 = F_5 ( V_2 ) ;
if ( V_107 ) {
F_42 ( & V_5 -> V_105 , L_6 , - V_107 ) ;
goto V_123;
}
F_47 ( & V_2 -> V_25 , F_6 ) ;
F_19 ( & V_2 -> V_25 , 5 * V_50 ) ;
V_107 = F_48 ( V_70 ) ;
if ( V_107 ) {
F_42 ( & V_5 -> V_105 , L_7 , - V_107 ) ;
goto V_124;
}
return 0 ;
V_124:
F_17 ( & V_2 -> V_25 ) ;
F_49 () ;
V_123:
if ( V_5 -> V_91 )
F_50 ( V_5 -> V_91 , V_70 ) ;
V_109:
F_51 ( V_70 ) ;
return V_107 ;
}
static int F_52 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_53 ( V_5 ) ;
struct V_69 * V_70 = F_54 ( V_2 ) ;
F_55 ( V_70 ) ;
if ( ! V_2 -> V_45 )
F_17 ( & V_2 -> V_25 ) ;
V_2 -> V_99 |= ~ 0x30 ;
F_2 ( V_2 -> V_5 , V_9 | V_100 ,
V_2 -> V_99 ) ;
F_49 () ;
F_1 ( V_2 , 0 ) ;
if ( V_5 -> V_91 )
F_50 ( V_5 -> V_91 , V_70 ) ;
F_51 ( V_70 ) ;
return 0 ;
}
static int F_56 ( struct V_125 * V_105 )
{
struct V_1 * V_2 = F_53 ( F_57 ( V_105 ) ) ;
int V_11 ;
F_27 ( & V_2 -> V_81 ) ;
V_11 = F_1 ( V_2 , 0 ) ;
if ( V_11 )
goto V_44;
V_2 -> V_43 = true ;
V_44:
F_28 ( & V_2 -> V_81 ) ;
return V_11 ;
}
static int F_58 ( struct V_125 * V_105 )
{
struct V_1 * V_2 = F_53 ( F_57 ( V_105 ) ) ;
int V_11 ;
F_27 ( & V_2 -> V_81 ) ;
V_11 = F_1 ( V_2 , 1 ) ;
if ( V_11 )
goto V_44;
V_11 = F_5 ( V_2 ) ;
if ( V_11 )
goto V_44;
V_2 -> V_43 = false ;
V_44:
F_28 ( & V_2 -> V_81 ) ;
return V_11 ;
}
