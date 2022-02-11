static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) -> V_7 ;
T_1 V_8 ;
T_1 V_9 ;
int V_10 ;
F_4 ( V_7 , 0x48 , & V_8 ) ;
V_8 = ( V_8 >> 16 ) & 0xF ;
V_10 = V_11 [ V_8 ] * 1000000 ;
for ( V_9 = 0 ; V_9 < V_12 ; ++ V_9 ) {
if ( V_3 >= V_10 >> V_13 [ V_9 ] )
break;
}
if ( V_8 )
V_9 |= 0x8 ;
else if ( V_9 == 0 )
V_9 = 1 ;
F_5 ( V_7 , 0x40 , ~ 0xF0000000 , V_9 << 28 ) ;
F_6 ( F_7 ( V_5 ) ,
L_1 ,
V_10 >> V_13 [ V_9 & 7 ] ,
V_3 , V_8 , V_9 & 7 , V_9 & 8 ) ;
}
static void F_8 ( struct V_4 * V_5 ,
unsigned short V_14 , unsigned short V_15 )
{
V_15 |= V_16 ;
V_14 = ( F_9 ( V_5 , V_17 )
& ~ V_15 ) | V_14 ;
if ( V_14 )
V_14 |= V_16 ;
F_10 ( V_5 , V_17 , V_14 ) ;
}
static void F_11 ( struct V_4 * V_5 ,
unsigned short V_14 , unsigned short V_15 )
{
struct V_18 * V_19 = F_12 ( F_13 ( V_5 ) ) ;
unsigned long V_20 ;
F_14 ( & V_19 -> V_21 , V_20 ) ;
F_8 ( V_5 , V_14 , V_15 ) ;
F_15 ( & V_19 -> V_21 , V_20 ) ;
}
static void F_16 ( struct V_4 * V_5 )
{
F_17 ( V_5 , V_22 , 0xFF ) ;
F_17 ( V_5 , V_23 , 0xFF ) ;
F_17 ( V_5 , V_24 , 0xFF ) ;
}
static void F_18 ( struct V_4 * V_5 , int V_14 )
{
if ( V_14 )
F_19 ( V_5 , V_25 ,
V_26 , 0 ) ;
else
F_19 ( V_5 , V_25 ,
0 , V_26 ) ;
}
static int F_20 ( struct V_4 * V_5 , T_2 V_27 )
{
T_3 V_28 ;
V_28 = F_9 ( V_5 , V_29 ) ;
if ( V_28 & V_30 ) {
F_6 ( F_7 ( V_5 ) ,
L_2 , V_28 ) ;
F_17 ( V_5 , V_22 ,
V_30 ) ;
V_28 &= ~ V_30 ;
}
if ( V_28 & V_31 ) {
F_6 ( F_7 ( V_5 ) ,
L_3 , V_28 ) ;
F_17 ( V_5 , V_22 , V_28 & 0xFF ) ;
F_17 ( V_5 , V_23 ,
V_32 ) ;
return - V_33 ;
}
if ( ( V_28 >> 8 ) & V_27 ) {
F_17 ( V_5 , V_23 , V_27 ) ;
return 1 ;
}
return 0 ;
}
static int F_21 ( struct V_4 * V_5 , T_2 V_27 )
{
int V_34 = 0 ;
unsigned V_35 = 2000000 ;
#ifdef F_22
T_1 V_36 , V_37 ;
V_36 = F_23 ( V_5 , V_29 ) ;
#endif
while ( ! ( V_34 = F_20 ( V_5 , V_27 ) ) ) {
if ( ! -- V_35 ) {
F_24 ( F_3 ( V_5 ) ,
V_38 ) ;
V_34 = - V_39 ;
break;
}
F_25 ( 1 ) ;
}
#ifdef F_22
V_37 = F_23 ( V_5 , V_29 ) ;
V_35 = 2000000 - V_35 ;
if ( V_35 > 100 )
F_6 ( F_7 ( V_5 ) ,
L_4 ,
V_35 , V_27 , V_36 , V_37 ) ;
#endif
return V_34 < 0 ? V_34 : 0 ;
}
static int F_26 ( struct V_4 * V_5 , T_4 V_15 )
{
unsigned V_35 = 500000 ;
int V_34 = 0 ;
#ifdef F_22
T_1 V_36 , V_37 ;
V_36 = F_23 ( V_5 , V_29 ) ;
#endif
while ( F_27 ( V_5 , V_24 ) & V_15 ) {
if ( ! -- V_35 ) {
F_24 ( F_3 ( V_5 ) ,
V_38 ) ;
V_34 = - V_39 ;
break;
}
F_25 ( 1 ) ;
}
#ifdef F_22
V_37 = F_23 ( V_5 , V_29 ) ;
V_35 = 500000 - V_35 ;
if ( V_35 > 100 )
F_6 ( F_7 ( V_5 ) ,
L_5 ,
V_35 , V_15 , V_36 , V_37 ) ;
#endif
return V_34 ;
}
static void F_28 ( struct V_4 * V_5 ,
T_5 V_40 , T_5 V_41 )
{
F_26 ( V_5 , V_42 ) ;
F_29 ( V_5 , V_43 ,
( ( V_40 - 1 ) << 16 ) | ( V_41 - 1 ) ) ;
F_30 ( F_7 ( V_5 ) , L_6 ,
V_40 , V_40 == 1 ? L_7 : L_8 , V_41 ) ;
}
static void F_31 ( struct V_4 * V_5 )
{
T_1 V_44 , V_45 ;
int V_46 = 0 ;
V_44 = F_23 ( V_5 , V_47 ) ;
V_45 = F_23 ( V_5 , V_47 ) ;
if ( F_27 ( V_5 , V_22 )
& V_30 ) {
F_17 ( V_5 , V_22 ,
V_30 ) ;
V_46 = 1 ;
}
F_6 ( F_7 ( V_5 ) ,
L_9 ,
V_46 ? L_10 : L_11 ) ;
F_6 ( F_7 ( V_5 ) ,
L_12 ,
V_44 , V_45 , ( V_44 | V_45 ) ? L_13 : L_14 ) ;
}
static int F_32 ( struct V_4 * V_5 ,
struct V_48 * V_49 , T_5 V_50 )
{
if ( ! ( F_27 ( V_5 , V_24 ) & V_51 ) ) {
int V_34 = F_21 ( V_5 ,
V_52 ) ;
if ( V_34 )
return V_34 ;
}
F_33 ( V_49 ,
V_5 -> V_53 + V_47 , V_50 ) ;
return 0 ;
}
static bool F_34 ( struct V_54 * V_55 )
{
return ! ( V_55 -> V_56 & 15 && ( V_55 -> V_57 != 1 || V_55 -> V_56 != 8 ) ) ;
}
static int F_35 ( struct V_4 * V_5 , struct V_54 * V_55 )
{
struct V_48 V_49 ;
T_5 V_58 , V_57 = V_55 -> V_57 ;
int V_34 = 0 ;
if ( F_36 ( V_55 -> V_56 & 15 && ( V_55 -> V_57 != 1 || V_55 -> V_56 != 8 ) ) )
return - V_59 ;
F_37 ( & V_49 , V_55 -> V_60 , V_55 -> V_61 , V_62 ) ;
F_19 ( V_5 , V_63 ,
15 , V_64 ) ;
F_31 ( V_5 ) ;
while ( V_57 -- > 0 ) {
V_58 = V_55 -> V_56 ;
while ( V_58 >= 16 ) {
V_34 = F_32 ( V_5 , & V_49 , 4 ) ;
if ( V_34 )
goto V_65;
V_58 -= 16 ;
}
if ( ! V_58 )
continue;
F_19 ( V_5 , V_63 ,
V_58 - 1 , V_64 ) ;
V_58 = ( V_58 >= 8 ) ? 4 : 2 ;
V_34 = F_32 ( V_5 , & V_49 , V_58 ) ;
if ( V_34 )
goto V_65;
}
V_65:
F_38 ( & V_49 ) ;
return V_34 ;
}
static int F_39 ( struct V_4 * V_5 , struct V_54 * V_55 )
{
struct V_48 V_49 ;
T_5 V_58 , V_57 = V_55 -> V_57 ;
int V_34 = 0 ;
if ( F_36 ( V_55 -> V_57 > 1 && V_55 -> V_56 & 15 ) )
return - V_59 ;
F_37 ( & V_49 , V_55 -> V_60 , V_55 -> V_61 , V_66 ) ;
F_19 ( V_5 , V_63 ,
0 , V_64 ) ;
while ( V_57 -- > 0 ) {
V_58 = ( V_55 -> V_56 + 15 ) >> 4 ;
do {
if ( ! ( F_27 ( V_5 , V_24 )
& V_67 ) ) {
V_34 = F_21 ( V_5 ,
V_52 ) ;
if ( V_34 )
goto V_65;
}
F_40 ( & V_49 ,
V_5 -> V_53 + V_47 , 4 ) ;
} while ( -- V_58 );
}
V_65:
F_38 ( & V_49 ) ;
return V_34 ;
}
static T_3 F_41 ( struct V_18 * V_19 ,
struct V_68 * V_69 )
{
unsigned int V_20 = V_69 -> V_20 ;
T_3 V_70 = 0 ;
switch ( V_20 & V_71 ) {
case V_72 : V_70 = V_73 ; break;
case V_74 : V_70 = V_75 ; break;
case V_76 : V_70 = V_77 ; break;
case V_78 : V_70 = V_79 ; break;
}
if ( V_20 & V_80 )
V_70 |= V_81 ;
V_70 |= V_69 -> V_82 << V_83 ;
if ( V_69 -> V_55 && ( V_69 -> V_55 -> V_20 & V_84 ) )
V_70 |= V_85 ;
if ( V_20 & V_86 ) {
V_70 |= V_87 ;
if ( V_20 & V_88 )
V_70 |= V_89 ;
if ( ! ( V_20 & V_90 ) )
V_70 |= V_91 ;
}
return V_70 ;
}
static void F_42 ( struct V_4 * V_5 ,
struct V_68 * V_69 )
{
unsigned V_92 , V_93 ;
if ( V_69 -> V_20 & V_88 ) {
T_1 V_94 [ 4 ] ;
V_94 [ 0 ] = F_23 ( V_5 , V_95 ) ;
V_94 [ 1 ] = F_23 ( V_5 , V_96 ) ;
V_94 [ 2 ] = F_23 ( V_5 , V_97 ) ;
V_94 [ 3 ] = F_23 ( V_5 , V_98 ) ;
V_92 = V_94 [ 0 ] >> 24 ;
V_69 -> V_94 [ 0 ] = ( V_94 [ 0 ] << 8 ) | ( V_94 [ 1 ] >> 24 ) ;
V_69 -> V_94 [ 1 ] = ( V_94 [ 1 ] << 8 ) | ( V_94 [ 2 ] >> 24 ) ;
V_69 -> V_94 [ 2 ] = ( V_94 [ 2 ] << 8 ) | ( V_94 [ 3 ] >> 24 ) ;
V_69 -> V_94 [ 3 ] = ( V_94 [ 3 ] << 8 ) ;
} else {
V_92 = F_23 ( V_5 , V_97 ) & 0x3F ;
V_69 -> V_94 [ 0 ] = F_23 ( V_5 , V_98 ) ;
}
V_93 = ( V_69 -> V_20 & V_99 ) ? V_69 -> V_82 : 0x3F ;
if ( V_92 != V_93 )
V_69 -> error = - V_100 ;
}
static int F_43 ( struct V_4 * V_5 ,
struct V_54 * V_55 )
{
int error , V_101 ;
if ( V_55 -> V_20 & V_84 )
error = F_35 ( V_5 , V_55 ) ;
else
error = F_39 ( V_5 , V_55 ) ;
V_101 = F_21 ( V_5 , V_102 ) ;
if ( ! error )
error = V_101 ;
if ( ! error )
V_55 -> V_103 = V_55 -> V_56 * V_55 -> V_57 ;
return error ;
}
static int F_44 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_18 * V_19 = F_12 ( V_2 ) ;
struct V_54 * V_55 = V_69 -> V_55 ;
T_3 V_104 = F_41 ( V_19 , V_69 ) ;
F_6 ( F_7 ( V_5 ) , L_15 , V_104 ) ;
if ( V_55 ) {
if ( ! F_34 ( V_55 ) ) {
V_55 -> error = - V_59 ;
return - 1 ;
}
F_28 ( V_5 , V_55 -> V_57 , V_55 -> V_56 ) ;
}
F_26 ( V_5 , V_42 | V_105 ) ;
F_10 ( V_5 , V_106 , V_104 ) ;
F_26 ( V_5 , V_42 ) ;
F_29 ( V_5 , V_107 , V_69 -> V_108 ) ;
F_16 ( V_5 ) ;
F_26 ( V_5 , V_42 ) ;
F_19 ( V_5 , V_109 , 0x01 , 0 ) ;
V_69 -> error = F_21 ( V_5 , V_110 ) ;
if ( V_69 -> error )
return - 1 ;
if ( V_69 -> V_20 & V_86 ) {
F_42 ( V_5 , V_69 ) ;
if ( V_69 -> error )
return - 1 ;
}
if ( V_55 )
V_55 -> error = F_43 ( V_5 , V_55 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , struct V_111 * V_112 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_18 * V_19 = F_12 ( V_2 ) ;
F_46 ( V_19 -> V_112 != NULL ) ;
V_19 -> V_112 = V_112 ;
F_11 ( V_5 , V_113 , 0 ) ;
if ( ! F_44 ( V_2 , V_112 -> V_69 ) && V_112 -> V_114 )
F_44 ( V_2 , V_112 -> V_114 ) ;
F_47 ( & V_19 -> V_115 ) ;
}
static int F_48 ( struct V_4 * V_5 )
{
#ifdef F_22
struct V_116 * V_117 = F_3 ( V_5 ) ;
#endif
int V_34 ;
F_6 ( F_7 ( V_5 ) , L_16 ) ;
F_24 ( V_117 , V_38 ) ;
V_34 = F_26 ( V_5 , V_42 ) ;
if ( F_36 ( V_34 ) )
return V_34 ;
F_19 ( V_5 , V_25 , 0x80 , 0 ) ;
F_19 ( V_5 , V_118 , 0x80 , 0 ) ;
F_24 ( V_117 , V_38 ) ;
F_49 ( 1 ) ;
F_6 ( F_7 ( V_5 ) , L_17 ) ;
F_24 ( V_117 , V_38 ) ;
V_34 = F_26 ( V_5 , V_42 ) ;
if ( F_36 ( V_34 ) )
return V_34 ;
F_19 ( V_5 , V_25 , 0x09 , 0 ) ;
F_24 ( V_117 , V_38 ) ;
F_49 ( 1 ) ;
F_6 ( F_7 ( V_5 ) , L_18 ) ;
F_24 ( V_117 , V_38 ) ;
V_34 = F_26 ( V_5 , V_42 ) ;
if ( F_36 ( V_34 ) )
return V_34 ;
F_19 ( V_5 , V_25 , 0 , 0x08 ) ;
F_24 ( V_117 , V_38 ) ;
F_49 ( 2 ) ;
F_6 ( F_7 ( V_5 ) , L_19 ) ;
F_24 ( V_117 , V_38 ) ;
F_19 ( V_5 , V_109 , 0x06 , 0 ) ;
F_19 ( V_5 , V_25 , 0x70 , 0 ) ;
F_19 ( V_5 , V_63 , 0x80 , 0 ) ;
F_19 ( V_5 , V_118 , 0x03 , 0 ) ;
F_24 ( V_117 , V_38 ) ;
V_34 = F_26 ( V_5 , V_42 ) ;
if ( F_36 ( V_34 ) )
return V_34 ;
F_10 ( V_5 , V_119 , 0xFFFF ) ;
F_19 ( V_5 , V_109 , 0x06 , 0 ) ;
F_24 ( V_117 , V_38 ) ;
F_6 ( F_7 ( V_5 ) , L_20 ) ;
return F_20 ( V_5 , 0 ) ;
}
static void F_50 ( struct V_4 * V_5 )
{
F_19 ( V_5 , V_25 , 0 , 0x81 ) ;
F_19 ( V_5 , V_118 , 0 , 0x80 ) ;
}
static void F_51 ( struct V_1 * V_2 , struct V_120 * V_121 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_18 * V_19 = F_12 ( V_2 ) ;
int V_34 ;
F_1 ( V_2 , V_121 -> clock ) ;
if ( V_121 -> V_122 != V_19 -> V_123 )
switch ( V_121 -> V_122 ) {
case V_124 :
V_34 = F_48 ( V_5 ) ;
if ( V_34 ) {
F_52 ( F_7 ( V_5 ) ,
L_21 , V_34 ) ;
F_50 ( V_5 ) ;
F_25 ( 1 ) ;
V_34 = F_48 ( V_5 ) ;
if ( V_34 )
F_52 ( F_7 ( V_5 ) ,
L_22 ,
V_34 ) ;
}
V_19 -> V_123 = V_124 ;
break;
case V_125 :
F_50 ( V_5 ) ;
V_19 -> V_123 = V_125 ;
break;
case V_126 :
default:
;
}
F_18 ( V_5 , V_121 -> V_127 != V_128 ) ;
F_11 ( V_5 , V_113 , 0 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_27 ( V_5 , V_129 )
& V_130 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_27 ( V_5 , V_129 )
& V_131 ;
}
static int F_55 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_13 ( V_5 ) ;
struct V_18 * V_19 = F_12 ( V_2 ) ;
T_1 V_28 , V_132 , V_133 , V_134 ;
V_28 = F_23 ( V_5 , V_29 ) ;
V_134 = F_23 ( V_5 , V_17 ) ;
V_133 = F_23 ( V_5 , V_119 ) ;
V_132 = F_23 ( V_5 , V_135 ) ;
F_6 ( F_7 ( V_5 ) , L_23
L_24 ,
V_28 , V_134 , V_133 , V_132 ) ;
if ( V_28 & ( V_136 << 8 ) ) {
F_17 ( V_5 , V_23 ,
V_136 ) ;
if ( ( V_134 & V_137 )
== V_137 )
F_56 ( V_2 , V_138 / 5 ) ;
} else {
F_6 ( F_7 ( V_5 ) , L_25 ) ;
F_57 ( & V_19 -> V_21 ) ;
F_8 ( V_5 , 0 , V_113 ) ;
F_58 ( & V_19 -> V_21 ) ;
}
return 1 ;
}
static void F_59 ( unsigned long V_55 )
{
struct V_1 * V_2 = ( void * ) V_55 ;
struct V_18 * V_19 = F_12 ( V_2 ) ;
struct V_111 * V_112 = V_19 -> V_112 ;
V_19 -> V_112 = NULL ;
F_60 ( V_2 , V_112 ) ;
}
static int F_61 ( struct V_139 * V_7 , T_6 V_140 )
{
struct V_4 * V_5 = F_62 ( V_7 ) ;
struct V_1 * V_2 = F_13 ( V_5 ) ;
int V_34 ;
V_34 = F_63 ( V_2 ) ;
if ( V_34 )
return V_34 ;
F_11 ( V_5 , 0 , ~ 0 ) ;
return 0 ;
}
static int F_64 ( struct V_139 * V_7 )
{
struct V_4 * V_5 = F_62 ( V_7 ) ;
struct V_1 * V_2 = F_13 ( V_5 ) ;
F_11 ( V_5 , 0 , ~ 0 ) ;
return F_65 ( V_2 ) ;
}
static int F_66 ( struct V_139 * V_7 )
{
struct V_4 * V_5 = F_62 ( V_7 ) ;
struct V_116 * V_117 = F_3 ( V_5 ) ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
int V_34 ;
T_1 V_141 ;
V_2 = F_67 ( sizeof( * V_19 ) , F_7 ( V_5 ) ) ;
if ( ! V_2 )
return - V_142 ;
F_68 ( & V_7 -> V_143 , V_2 ) ;
F_4 ( V_117 -> V_7 , 0x48 , & V_141 ) ;
V_141 = V_11 [ ( V_141 >> 16 ) & 0xF ] ;
F_6 ( F_7 ( V_5 ) , L_26 , V_141 ) ;
V_141 *= 1000000 ;
V_2 -> V_144 = & V_145 ;
V_2 -> V_146 = V_141 ;
V_2 -> V_147 = V_141 >> V_13 [ V_12 ] ;
V_2 -> V_148 = V_149 | V_150 ;
V_2 -> V_151 = V_152 ;
V_19 = F_12 ( V_2 ) ;
F_69 ( & V_19 -> V_115 ,
F_59 , ( unsigned long ) V_2 ) ;
F_70 ( & V_19 -> V_21 ) ;
F_24 ( V_117 , V_38 ) ;
F_11 ( V_5 , 0 , ~ 0 ) ;
F_71 ( V_5 , F_55 ) ;
V_34 = F_72 ( V_2 ) ;
if ( F_36 ( V_34 ) )
goto V_153;
F_6 ( F_7 ( V_5 ) , L_27 ,
F_73 ( V_2 ) ) ;
F_11 ( V_5 , V_154 , 0 ) ;
return 0 ;
V_153:
F_6 ( F_7 ( V_5 ) , L_28 , V_34 ) ;
F_71 ( V_5 , NULL ) ;
F_74 ( V_2 ) ;
return V_34 ;
}
static int F_75 ( struct V_139 * V_7 )
{
struct V_4 * V_5 = F_62 ( V_7 ) ;
struct V_1 * V_2 = F_13 ( V_5 ) ;
struct V_18 * V_19 = F_12 ( V_2 ) ;
F_11 ( V_5 , 0 , V_154 ) ;
F_76 ( V_2 ) ;
F_11 ( V_5 , 0 , ~ 0 ) ;
F_71 ( V_5 , NULL ) ;
F_29 ( V_5 , V_135 , 0 ) ;
F_10 ( V_5 , V_119 , 0 ) ;
F_77 ( & V_19 -> V_115 ) ;
F_74 ( V_2 ) ;
return 0 ;
}
