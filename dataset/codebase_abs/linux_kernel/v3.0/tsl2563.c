static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [ 2 ] ;
V_6 [ 0 ] = V_7 | V_3 ;
V_6 [ 1 ] = V_4 ;
V_5 = F_2 ( V_2 , V_6 , sizeof( V_6 ) ) ;
return ( V_5 == sizeof( V_6 ) ) ? 0 : V_5 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , void * V_6 , int V_8 )
{
int V_5 ;
T_1 V_9 = V_7 | V_3 ;
V_5 = F_2 ( V_2 , & V_9 , sizeof( V_9 ) ) ;
if ( V_5 != sizeof( V_9 ) )
return V_5 ;
return F_4 ( V_2 , V_6 , V_8 ) ;
}
static int F_5 ( struct V_10 * V_11 , int V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_9 ;
V_9 = V_12 ? V_13 : V_14 ;
return F_1 ( V_2 , V_15 , V_9 ) ;
}
static int F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_5 ;
T_1 V_16 ;
V_5 = F_3 ( V_2 , V_15 , & V_16 , sizeof( V_16 ) ) ;
if ( V_5 != sizeof( V_16 ) )
return V_5 ;
return ( V_16 & V_17 ) == V_13 ;
}
static int F_7 ( struct V_10 * V_11 )
{
int V_5 ;
V_5 = F_1 ( V_11 -> V_2 , V_18 ,
V_11 -> V_19 -> V_20 ) ;
if ( V_5 )
goto V_21;
V_5 = F_1 ( V_11 -> V_2 , V_22 ,
V_11 -> V_23 & 0xFF ) ;
if ( V_5 )
goto V_21;
V_5 = F_1 ( V_11 -> V_2 , V_24 ,
( V_11 -> V_23 >> 8 ) & 0xFF ) ;
if ( V_5 )
goto V_21;
V_5 = F_1 ( V_11 -> V_2 , V_25 ,
V_11 -> V_26 & 0xFF ) ;
if ( V_5 )
goto V_21;
V_5 = F_1 ( V_11 -> V_2 , V_27 ,
( V_11 -> V_26 >> 8 ) & 0xFF ) ;
V_21:
return V_5 ;
}
static void F_8 ( struct V_28 * V_29 )
{
struct V_10 * V_11 =
F_9 ( V_29 , struct V_10 , V_30 . V_29 ) ;
F_5 ( V_11 , 0 ) ;
}
static int F_10 ( struct V_10 * V_11 )
{
int V_5 ;
V_5 = F_5 ( V_11 , 1 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_6 ( V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_5 ? 0 : - V_31 ;
}
static int F_11 ( struct V_10 * V_11 , T_1 * V_32 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_5 ;
V_5 = F_3 ( V_2 , V_33 , V_32 , sizeof( * V_32 ) ) ;
if ( V_5 != sizeof( * V_32 ) )
return V_5 ;
return 0 ;
}
static int F_12 ( T_1 V_34 )
{
int V_35 = 0 ;
switch ( V_34 & V_36 ) {
case V_37 :
V_35 += 5 ;
break;
case V_38 :
V_35 += 2 ;
break;
case V_39 :
break;
}
if ( ! ( V_34 & V_40 ) )
V_35 += 4 ;
return V_35 ;
}
static T_2 F_13 ( T_3 V_41 , T_1 V_34 )
{
return V_41 << F_12 ( V_34 ) ;
}
static void F_14 ( struct V_10 * V_11 )
{
unsigned int V_42 ;
switch ( V_11 -> V_19 -> V_20 & V_36 ) {
case V_37 :
V_42 = 14 ;
break;
case V_38 :
V_42 = 101 ;
break;
default:
V_42 = 402 ;
}
F_15 ( F_16 ( V_42 ) + 2 ) ;
}
static int F_17 ( struct V_10 * V_11 , T_3 V_41 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
if ( V_41 > V_11 -> V_19 -> V_43 || V_41 < V_11 -> V_19 -> V_44 ) {
( V_41 > V_11 -> V_19 -> V_43 ) ?
V_11 -> V_19 ++ : V_11 -> V_19 -- ;
F_1 ( V_2 , V_18 ,
V_11 -> V_19 -> V_20 ) ;
F_14 ( V_11 ) ;
F_14 ( V_11 ) ;
return 1 ;
} else
return 0 ;
}
static int F_18 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_45 [ 2 ] , V_46 [ 2 ] ;
T_3 V_47 , V_48 ;
int V_49 = 1 ;
int V_5 = 0 ;
if ( V_11 -> V_50 . V_51 != V_52 )
goto V_53;
if ( ! V_11 -> V_54 ) {
F_19 ( & V_11 -> V_30 ) ;
if ( ! F_6 ( V_11 ) ) {
V_5 = F_5 ( V_11 , 1 ) ;
if ( V_5 )
goto V_53;
V_5 = F_7 ( V_11 ) ;
if ( V_5 )
goto V_53;
F_14 ( V_11 ) ;
}
}
while ( V_49 ) {
V_5 = F_3 ( V_2 ,
V_55 ,
V_45 , sizeof( V_45 ) ) ;
if ( V_5 != sizeof( V_45 ) )
goto V_53;
V_5 = F_3 ( V_2 , V_56 ,
V_46 , sizeof( V_46 ) ) ;
if ( V_5 != sizeof( V_46 ) )
goto V_53;
V_47 = ( V_45 [ 1 ] << 8 ) + V_45 [ 0 ] ;
V_48 = ( V_46 [ 1 ] << 8 ) + V_46 [ 0 ] ;
V_49 = F_17 ( V_11 , V_47 ) ;
}
V_11 -> V_57 = F_13 ( V_47 , V_11 -> V_19 -> V_20 ) ;
V_11 -> V_58 = F_13 ( V_48 , V_11 -> V_19 -> V_20 ) ;
if ( ! V_11 -> V_54 )
F_20 ( & V_11 -> V_30 , 5 * V_59 ) ;
V_5 = 0 ;
V_53:
return V_5 ;
}
static inline int F_21 ( T_2 V_60 )
{
return ( int ) ( ( ( V_60 * V_61 ) +
V_62 ) >> V_63 ) ;
}
static inline T_2 F_22 ( int V_4 )
{
return ( ( ( T_2 ) V_4 ) << V_63 ) / V_61 ;
}
static unsigned int F_23 ( T_2 V_47 , T_2 V_48 )
{
const struct V_64 * V_65 = V_66 ;
unsigned long V_67 , V_68 , V_69 = V_47 , V_70 = V_48 ;
V_67 = V_69 ? ( ( V_70 << V_71 ) / V_69 ) : V_72 ;
while ( V_65 -> V_73 < V_67 )
V_65 ++ ;
V_68 = V_69 * V_65 -> V_74 - V_70 * V_65 -> V_75 ;
return ( unsigned int ) ( V_68 >> V_71 ) ;
}
static T_2 F_24 ( T_2 V_41 , T_2 V_60 )
{
unsigned long V_76 = V_41 ;
V_76 *= V_60 ;
V_76 >>= V_63 ;
return ( T_2 ) V_76 ;
}
static int F_25 ( struct V_77 * V_78 ,
struct V_79 const * V_80 ,
int V_16 ,
int V_81 ,
long V_82 )
{
struct V_10 * V_11 = F_26 ( V_78 ) ;
if ( V_80 -> V_83 == 0 )
V_11 -> V_84 = F_22 ( V_16 ) ;
else
V_11 -> V_85 = F_22 ( V_16 ) ;
return 0 ;
}
static int F_27 ( struct V_77 * V_78 ,
struct V_79 const * V_80 ,
int * V_16 ,
int * V_81 ,
long V_86 )
{
int V_5 = - V_87 ;
T_2 V_84 , V_85 ;
struct V_10 * V_11 = F_26 ( V_78 ) ;
F_28 ( & V_11 -> V_88 ) ;
switch ( V_86 ) {
case 0 :
switch ( V_80 -> type ) {
case V_89 :
V_5 = F_18 ( V_11 ) ;
if ( V_5 )
goto V_21;
V_84 = F_24 ( V_11 -> V_57 , V_11 -> V_84 ) *
V_11 -> V_90 ;
V_85 = F_24 ( V_11 -> V_58 , V_11 -> V_85 ) *
V_11 -> V_90 ;
* V_16 = F_23 ( V_84 , V_85 ) ;
V_5 = V_91 ;
break;
case V_92 :
V_5 = F_18 ( V_11 ) ;
if ( V_5 )
goto V_21;
if ( V_80 -> V_83 == 0 )
* V_16 = V_11 -> V_57 ;
else
* V_16 = V_11 -> V_58 ;
V_5 = V_91 ;
break;
default:
break;
}
break;
case ( 1 << V_93 ) :
if ( V_80 -> V_83 == 0 )
* V_16 = F_21 ( V_11 -> V_84 ) ;
else
* V_16 = F_21 ( V_11 -> V_85 ) ;
V_5 = V_91 ;
break;
default:
return - V_87 ;
}
V_21:
F_29 ( & V_11 -> V_88 ) ;
return V_5 ;
}
static int F_30 ( struct V_77 * V_78 ,
int V_94 ,
int * V_16 )
{
struct V_10 * V_11 = F_26 ( V_78 ) ;
switch ( F_31 ( V_94 ) ) {
case V_95 :
* V_16 = V_11 -> V_23 ;
break;
case V_96 :
* V_16 = V_11 -> V_26 ;
break;
default:
return - V_87 ;
}
return 0 ;
}
static T_4 F_32 ( struct V_77 * V_78 ,
int V_94 ,
int V_16 )
{
struct V_10 * V_11 = F_26 ( V_78 ) ;
int V_5 ;
T_1 V_97 ;
if ( F_31 ( V_94 ) == V_95 )
V_97 = V_22 ;
else
V_97 = V_25 ;
F_28 ( & V_11 -> V_88 ) ;
V_5 = F_1 ( V_11 -> V_2 , V_97 , V_16 & 0xFF ) ;
if ( V_5 )
goto V_21;
V_5 = F_1 ( V_11 -> V_2 , V_97 + 1 ,
( V_16 >> 8 ) & 0xFF ) ;
if ( F_31 ( V_94 ) == V_95 )
V_11 -> V_23 = V_16 ;
else
V_11 -> V_26 = V_16 ;
V_21:
F_29 ( & V_11 -> V_88 ) ;
return V_5 ;
}
static T_5 F_33 ( int V_98 , void * V_99 )
{
struct V_77 * V_100 = V_99 ;
struct V_10 * V_11 = F_26 ( V_100 ) ;
T_1 V_9 = V_7 | V_101 ;
F_34 ( V_100 , 0 ,
F_35 ( V_102 ,
0 ,
V_103 ,
V_104 ) ,
F_36 () ) ;
F_2 ( V_11 -> V_2 , & V_9 , sizeof( V_9 ) ) ;
return V_105 ;
}
static int F_37 ( struct V_77 * V_78 ,
int V_94 ,
int V_50 )
{
struct V_10 * V_11 = F_26 ( V_78 ) ;
int V_5 = 0 ;
F_28 ( & V_11 -> V_88 ) ;
if ( V_50 && ! ( V_11 -> V_106 & 0x30 ) ) {
V_11 -> V_106 &= ~ 0x30 ;
V_11 -> V_106 |= 0x10 ;
F_19 ( & V_11 -> V_30 ) ;
if ( ! F_6 ( V_11 ) ) {
V_5 = F_5 ( V_11 , 1 ) ;
if ( V_5 )
goto V_53;
V_5 = F_7 ( V_11 ) ;
if ( V_5 )
goto V_53;
}
V_5 = F_1 ( V_11 -> V_2 , V_107 , V_11 -> V_106 ) ;
V_11 -> V_54 = true ;
}
if ( ! V_50 && ( V_11 -> V_106 & 0x30 ) ) {
V_11 -> V_106 |= ~ 0x30 ;
V_5 = F_1 ( V_11 -> V_2 , V_107 , V_11 -> V_106 ) ;
V_11 -> V_54 = false ;
F_20 ( & V_11 -> V_30 , 5 * V_59 ) ;
}
V_53:
F_29 ( & V_11 -> V_88 ) ;
return V_5 ;
}
static int F_38 ( struct V_77 * V_78 ,
int V_94 )
{
struct V_10 * V_11 = F_26 ( V_78 ) ;
T_1 V_108 ;
int V_5 ;
F_28 ( & V_11 -> V_88 ) ;
V_5 = F_3 ( V_11 -> V_2 , V_107 ,
& V_108 , sizeof( V_108 ) ) ;
F_29 ( & V_11 -> V_88 ) ;
if ( V_5 < 0 )
goto V_21;
V_5 = ! ! ( V_108 & 0x30 ) ;
V_21:
return V_5 ;
}
static int T_6 F_39 ( struct V_1 * V_2 ,
const struct V_109 * V_110 )
{
struct V_77 * V_78 ;
struct V_10 * V_11 ;
struct V_111 * V_112 = V_2 -> V_113 . V_114 ;
int V_115 = 0 ;
int V_5 ;
T_1 V_32 ;
V_78 = F_40 ( sizeof( * V_11 ) ) ;
if ( ! V_78 )
return - V_116 ;
V_11 = F_26 ( V_78 ) ;
F_41 ( V_2 , V_11 ) ;
V_11 -> V_2 = V_2 ;
V_115 = F_10 ( V_11 ) ;
if ( V_115 ) {
F_42 ( & V_2 -> V_113 , L_1 , - V_115 ) ;
goto V_117;
}
V_115 = F_11 ( V_11 , & V_32 ) ;
if ( V_115 )
goto V_117;
F_43 ( & V_11 -> V_88 ) ;
V_11 -> V_26 = 0x0 ;
V_11 -> V_23 = 0xffff ;
V_11 -> V_19 = V_118 ;
V_11 -> V_106 = F_44 ( 4 ) ;
V_11 -> V_84 = F_22 ( V_61 ) ;
V_11 -> V_85 = F_22 ( V_61 ) ;
if ( V_112 )
V_11 -> V_90 = V_112 -> V_90 ;
else
V_11 -> V_90 = 1 ;
V_100 ( & V_2 -> V_113 , L_2 , V_32 >> 4 , V_32 & 0x0f ) ;
V_78 -> V_119 = V_2 -> V_119 ;
V_78 -> V_120 = V_121 ;
V_78 -> V_122 = F_45 ( V_121 ) ;
V_78 -> V_113 . V_123 = & V_2 -> V_113 ;
V_78 -> V_124 = V_125 ;
if ( V_2 -> V_98 )
V_78 -> V_126 = & V_127 ;
else
V_78 -> V_126 = & V_128 ;
V_5 = F_46 ( V_78 ) ;
if ( V_5 )
goto V_117;
if ( V_2 -> V_98 ) {
V_5 = F_47 ( V_2 -> V_98 ,
NULL ,
& F_33 ,
V_129 | V_130 ,
L_3 ,
V_78 ) ;
if ( V_5 )
goto V_131;
}
V_115 = F_7 ( V_11 ) ;
if ( V_115 )
goto V_132;
F_48 ( & V_11 -> V_30 , F_8 ) ;
F_20 ( & V_11 -> V_30 , 5 * V_59 ) ;
return 0 ;
V_132:
if ( V_2 -> V_98 )
F_49 ( V_2 -> V_98 , V_78 ) ;
V_131:
F_50 ( V_78 ) ;
V_117:
F_51 ( V_11 ) ;
return V_115 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_53 ( V_2 ) ;
struct V_77 * V_78 = F_54 ( V_11 ) ;
if ( ! V_11 -> V_54 )
F_19 ( & V_11 -> V_30 ) ;
V_11 -> V_106 |= ~ 0x30 ;
F_1 ( V_11 -> V_2 , V_107 , V_11 -> V_106 ) ;
F_55 () ;
F_5 ( V_11 , 0 ) ;
if ( V_2 -> V_98 )
F_49 ( V_2 -> V_98 , V_78 ) ;
F_50 ( V_78 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , T_7 V_50 )
{
struct V_10 * V_11 = F_53 ( V_2 ) ;
int V_5 ;
F_28 ( & V_11 -> V_88 ) ;
V_5 = F_5 ( V_11 , 0 ) ;
if ( V_5 )
goto V_53;
V_11 -> V_50 = V_50 ;
V_53:
F_29 ( & V_11 -> V_88 ) ;
return V_5 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_53 ( V_2 ) ;
int V_5 ;
F_28 ( & V_11 -> V_88 ) ;
V_5 = F_5 ( V_11 , 1 ) ;
if ( V_5 )
goto V_53;
V_5 = F_7 ( V_11 ) ;
if ( V_5 )
goto V_53;
V_11 -> V_50 . V_51 = V_52 ;
V_53:
F_29 ( & V_11 -> V_88 ) ;
return V_5 ;
}
static int T_8 F_58 ( void )
{
return F_59 ( & V_133 ) ;
}
static void T_9 F_60 ( void )
{
F_61 ( & V_133 ) ;
}
