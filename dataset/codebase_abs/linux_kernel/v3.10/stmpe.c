static int F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
return V_1 -> V_3 -> V_4 ( V_1 , V_2 , true ) ;
}
static int F_2 ( struct V_1 * V_1 , unsigned int V_2 )
{
return V_1 -> V_3 -> V_4 ( V_1 , V_2 , false ) ;
}
static int F_3 ( struct V_1 * V_1 , T_1 V_5 )
{
int V_6 ;
V_6 = V_1 -> V_7 -> V_8 ( V_1 , V_5 ) ;
if ( V_6 < 0 )
F_4 ( V_1 -> V_9 , L_1 , V_5 , V_6 ) ;
F_5 ( V_1 -> V_9 , L_2 , V_5 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_10 )
{
int V_6 ;
F_5 ( V_1 -> V_9 , L_3 , V_5 , V_10 ) ;
V_6 = V_1 -> V_7 -> V_11 ( V_1 , V_5 , V_10 ) ;
if ( V_6 < 0 )
F_4 ( V_1 -> V_9 , L_4 , V_5 , V_6 ) ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_12 , T_1 V_10 )
{
int V_6 ;
V_6 = F_3 ( V_1 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 &= ~ V_12 ;
V_6 |= V_10 ;
return F_6 ( V_1 , V_5 , V_6 ) ;
}
static int F_8 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_13 ,
T_1 * V_14 )
{
int V_6 ;
V_6 = V_1 -> V_7 -> V_15 ( V_1 , V_5 , V_13 , V_14 ) ;
if ( V_6 < 0 )
F_4 ( V_1 -> V_9 , L_5 , V_5 , V_6 ) ;
F_5 ( V_1 -> V_9 , L_6 , V_5 , V_13 , V_6 ) ;
F_9 ( L_7 , V_14 , V_13 ) ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_13 ,
const T_1 * V_14 )
{
int V_6 ;
F_5 ( V_1 -> V_9 , L_8 , V_5 , V_13 ) ;
F_9 ( L_9 , V_14 , V_13 ) ;
V_6 = V_1 -> V_7 -> V_16 ( V_1 , V_5 , V_13 , V_14 ) ;
if ( V_6 < 0 )
F_4 ( V_1 -> V_9 , L_10 , V_5 , V_6 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_1 , unsigned int V_2 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_1 ( V_1 , V_2 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_14 ( struct V_1 * V_1 , unsigned int V_2 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_2 ( V_1 , V_2 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_15 ( struct V_1 * V_1 , T_1 V_5 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_3 ( V_1 , V_5 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_16 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_10 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_6 ( V_1 , V_5 , V_10 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_17 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_12 , T_1 V_10 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_7 ( V_1 , V_5 , V_12 , V_10 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_18 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_13 , T_1 * V_14 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_8 ( V_1 , V_5 , V_13 , V_14 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_19 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_13 ,
const T_1 * V_14 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_10 ( V_1 , V_5 , V_13 , V_14 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_20 ( struct V_1 * V_1 , T_2 V_18 , enum V_19 V_20 )
{
struct V_21 * V_3 = V_1 -> V_3 ;
T_1 V_22 = V_1 -> V_23 [ V_24 ] ;
int V_25 = V_3 -> V_25 ;
int V_26 = F_21 ( V_1 -> V_27 * V_25 , 8 ) ;
int V_12 = ( 1 << V_25 ) - 1 ;
T_1 V_23 [ V_26 ] ;
int V_28 , V_29 , V_6 ;
if ( ! V_3 -> V_30 )
return 0 ;
V_29 = 8 / V_25 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_1 ( V_1 , V_31 ) ;
if ( V_6 < 0 )
goto V_32;
V_6 = F_8 ( V_1 , V_22 , V_26 , V_23 ) ;
if ( V_6 < 0 )
goto V_32;
V_28 = V_3 -> V_30 ( V_1 , V_20 ) ;
while ( V_18 ) {
int V_33 = F_22 ( V_18 ) ;
int V_34 = V_26 - ( V_33 / V_29 ) - 1 ;
int V_35 = ( V_33 % V_29 ) * ( 8 / V_29 ) ;
V_23 [ V_34 ] &= ~ ( V_12 << V_35 ) ;
V_23 [ V_34 ] |= V_28 << V_35 ;
V_18 &= ~ ( 1 << V_33 ) ;
}
V_6 = F_10 ( V_1 , V_22 , V_26 , V_23 ) ;
V_32:
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
static int F_23 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
if ( V_2 & V_31 )
return 0 ;
else
return - V_36 ;
}
static int F_24 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
unsigned int V_12 = 0 ;
if ( V_2 & V_31 )
V_12 |= V_37 ;
if ( V_2 & V_38 )
V_12 |= V_39 ;
if ( V_2 & V_40 )
V_12 |= V_41 ;
return F_7 ( V_1 , V_42 , V_12 ,
V_4 ? 0 : V_12 ) ;
}
static int F_25 ( struct V_1 * V_1 , enum V_19 V_20 )
{
return V_20 != V_40 ;
}
static int F_26 ( int V_43 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_27 ( V_45 ) ; V_44 ++ ) {
if ( V_45 [ V_44 ] >= V_43 )
return V_44 ;
}
return - V_36 ;
}
static int F_28 ( struct V_1 * V_1 , int V_46 )
{
int V_6 ;
if ( ! V_1 -> V_3 -> V_47 )
return - V_48 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = V_1 -> V_3 -> V_47 ( V_1 , V_46 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
static int F_29 ( struct V_1 * V_1 ,
int V_46 )
{
int V_6 , V_43 ;
V_43 = F_26 ( V_46 ) ;
if ( V_43 < 0 ) {
F_4 ( V_1 -> V_9 , L_11 ) ;
return V_43 ;
}
V_6 = F_7 ( V_1 , V_49 ,
V_50 ,
V_43 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_7 ( V_1 , V_49 ,
V_51 ,
V_51 ) ;
}
static int F_30 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
unsigned int V_12 = 0 ;
if ( V_2 & V_31 )
V_12 |= V_52 ;
if ( V_2 & V_53 )
V_12 |= V_54 ;
return F_7 ( V_1 , V_55 , V_12 ,
V_4 ? V_12 : 0 ) ;
}
static int F_31 ( struct V_1 * V_1 , enum V_19 V_20 )
{
switch ( V_20 ) {
case V_56 :
return 2 ;
case V_53 :
return 1 ;
case V_31 :
default:
return 0 ;
}
}
static int F_32 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
unsigned int V_12 = 0 ;
if ( V_2 & V_31 )
V_12 |= V_57 ;
if ( V_2 & V_53 )
V_12 |= V_58 ;
return F_7 ( V_1 , V_59 , V_12 ,
V_4 ? V_12 : 0 ) ;
}
static int F_33 ( struct V_1 * V_1 )
{
unsigned long V_43 ;
int V_6 = 0 ;
V_6 = F_7 ( V_1 , V_60 ,
V_61 , V_61 ) ;
if ( V_6 < 0 )
return V_6 ;
V_43 = V_62 + F_34 ( 100 ) ;
while ( F_35 ( V_62 , V_43 ) ) {
V_6 = F_3 ( V_1 , V_60 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! ( V_6 & V_61 ) )
return 0 ;
F_36 ( 100 , 200 ) ;
} ;
return - V_63 ;
}
static int F_37 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
unsigned int V_12 = 0 ;
if ( V_2 & V_31 )
V_12 |= V_64 ;
if ( V_2 & V_53 )
V_12 |= V_65 ;
return F_7 ( V_1 , V_66 , V_12 ,
V_4 ? V_12 : 0 ) ;
}
static int F_38 ( struct V_1 * V_1 , enum V_19 V_20 )
{
switch ( V_20 ) {
case V_67 :
return 2 ;
case V_53 :
return 1 ;
case V_31 :
default:
return 0 ;
}
}
static T_3 F_39 ( int V_68 , void * V_69 )
{
struct V_1 * V_1 = V_69 ;
struct V_21 * V_3 = V_1 -> V_3 ;
int V_70 = F_21 ( V_3 -> V_71 , 8 ) ;
T_1 V_72 ;
T_1 V_73 [ V_70 ] ;
int V_6 ;
int V_44 ;
if ( V_3 -> V_74 == V_75 ) {
int V_76 = F_40 ( V_1 -> V_77 , 0 ) ;
F_41 ( V_76 ) ;
return V_78 ;
}
if ( V_3 -> V_74 == V_79 )
V_72 = V_1 -> V_23 [ V_80 ] ;
else
V_72 = V_1 -> V_23 [ V_81 ] ;
V_6 = F_18 ( V_1 , V_72 , V_70 , V_73 ) ;
if ( V_6 < 0 )
return V_82 ;
for ( V_44 = 0 ; V_44 < V_70 ; V_44 ++ ) {
int V_83 = V_70 - V_44 - 1 ;
T_1 V_84 = V_73 [ V_44 ] ;
T_1 V_85 ;
V_84 &= V_1 -> V_86 [ V_83 ] ;
if ( ! V_84 )
continue;
V_85 = V_84 ;
while ( V_84 ) {
int V_87 = F_22 ( V_84 ) ;
int line = V_83 * 8 + V_87 ;
int V_88 = F_40 ( V_1 -> V_77 , line ) ;
F_41 ( V_88 ) ;
V_84 &= ~ ( 1 << V_87 ) ;
}
F_16 ( V_1 , V_72 + V_44 , V_85 ) ;
}
return V_78 ;
}
static void F_42 ( struct V_89 * V_69 )
{
struct V_1 * V_1 = F_43 ( V_69 ) ;
F_12 ( & V_1 -> V_90 ) ;
}
static void F_44 ( struct V_89 * V_69 )
{
struct V_1 * V_1 = F_43 ( V_69 ) ;
struct V_21 * V_3 = V_1 -> V_3 ;
int V_70 = F_21 ( V_3 -> V_71 , 8 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_70 ; V_44 ++ ) {
T_1 V_91 = V_1 -> V_86 [ V_44 ] ;
T_1 V_92 = V_1 -> V_93 [ V_44 ] ;
if ( V_91 == V_92 )
continue;
V_1 -> V_93 [ V_44 ] = V_91 ;
F_16 ( V_1 , V_1 -> V_23 [ V_94 ] - V_44 , V_91 ) ;
}
F_13 ( & V_1 -> V_90 ) ;
}
static void F_45 ( struct V_89 * V_69 )
{
struct V_1 * V_1 = F_43 ( V_69 ) ;
int V_95 = V_69 -> V_96 ;
int V_34 = V_95 / 8 ;
int V_12 = 1 << ( V_95 % 8 ) ;
V_1 -> V_86 [ V_34 ] &= ~ V_12 ;
}
static void F_46 ( struct V_89 * V_69 )
{
struct V_1 * V_1 = F_43 ( V_69 ) ;
int V_95 = V_69 -> V_96 ;
int V_34 = V_95 / 8 ;
int V_12 = 1 << ( V_95 % 8 ) ;
V_1 -> V_86 [ V_34 ] |= V_12 ;
}
static int F_47 ( struct V_97 * V_98 , unsigned int V_99 ,
T_4 V_96 )
{
struct V_1 * V_1 = V_98 -> V_100 ;
struct V_101 * V_102 = NULL ;
if ( V_1 -> V_3 -> V_74 != V_75 )
V_102 = & V_103 ;
F_48 ( V_99 , V_1 ) ;
F_49 ( V_99 , V_102 , V_104 ) ;
F_50 ( V_99 , 1 ) ;
#ifdef F_51
F_52 ( V_99 , V_105 ) ;
#else
F_53 ( V_99 ) ;
#endif
return 0 ;
}
static void F_54 ( struct V_97 * V_98 , unsigned int V_99 )
{
#ifdef F_51
F_52 ( V_99 , 0 ) ;
#endif
F_49 ( V_99 , NULL , NULL ) ;
F_48 ( V_99 , NULL ) ;
}
static int F_55 ( struct V_1 * V_1 , struct V_106 * V_107 )
{
int V_76 = 0 ;
int V_71 = V_1 -> V_3 -> V_71 ;
if ( ! V_107 )
V_76 = V_1 -> V_108 ;
V_1 -> V_77 = F_56 ( V_107 , V_71 , V_76 ,
& V_109 , V_1 ) ;
if ( ! V_1 -> V_77 ) {
F_4 ( V_1 -> V_9 , L_12 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_1 )
{
unsigned int V_110 = V_1 -> V_111 -> V_110 ;
int V_46 = V_1 -> V_111 -> V_46 ;
struct V_21 * V_3 = V_1 -> V_3 ;
T_1 V_112 = 0 ;
unsigned int V_113 ;
T_1 V_69 [ 2 ] ;
int V_6 ;
V_6 = F_18 ( V_1 , V_1 -> V_23 [ V_114 ] ,
F_27 ( V_69 ) , V_69 ) ;
if ( V_6 < 0 )
return V_6 ;
V_113 = ( V_69 [ 0 ] << 8 ) | V_69 [ 1 ] ;
if ( ( V_113 & V_3 -> V_115 ) != V_3 -> V_74 ) {
F_4 ( V_1 -> V_9 , L_13 , V_113 ) ;
return - V_36 ;
}
F_58 ( V_1 -> V_9 , L_14 , V_3 -> V_116 , V_113 ) ;
V_6 = F_14 ( V_1 , ~ 0 ) ;
if ( V_6 )
return V_6 ;
if ( V_113 == V_79 ) {
V_6 = F_33 ( V_1 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( V_1 -> V_68 >= 0 ) {
if ( V_113 == V_75 )
V_112 = V_117 ;
else
V_112 = V_118 ;
if ( V_113 != V_75 ) {
if ( V_110 == V_119 ||
V_110 == V_120 )
V_112 |= V_121 ;
}
if ( V_110 == V_120 ||
V_110 == V_122 ) {
if ( V_113 == V_75 )
V_112 |= V_123 ;
else
V_112 |= V_124 ;
}
}
if ( V_1 -> V_111 -> V_125 ) {
V_6 = F_28 ( V_1 , V_46 ) ;
if ( V_6 )
return V_6 ;
}
return F_16 ( V_1 , V_1 -> V_23 [ V_126 ] , V_112 ) ;
}
static int F_59 ( struct V_1 * V_1 , struct V_127 * V_128 )
{
return F_60 ( V_1 -> V_9 , V_1 -> V_111 -> V_113 , V_128 , 1 ,
NULL , V_1 -> V_108 , V_1 -> V_77 ) ;
}
static int F_61 ( struct V_1 * V_1 )
{
struct V_21 * V_3 = V_1 -> V_3 ;
unsigned int V_129 = V_1 -> V_111 -> V_2 ;
int V_6 = - V_36 ;
int V_44 , V_130 ;
for ( V_44 = 0 ; V_44 < V_3 -> V_131 ; V_44 ++ ) {
struct V_132 * V_20 = & V_3 -> V_2 [ V_44 ] ;
if ( ! ( V_129 & V_20 -> V_20 ) )
continue;
for ( V_130 = 0 ; V_130 < V_20 -> V_128 -> V_133 ; V_130 ++ ) {
struct V_134 * V_135 =
(struct V_134 * ) & V_20 -> V_128 -> V_136 [ V_130 ] ;
if ( V_135 -> V_137 & V_138 )
V_135 -> V_139 = V_135 -> V_140 = V_20 -> V_68 + V_130 ;
}
V_129 &= ~ V_20 -> V_20 ;
V_6 = F_59 ( V_1 , V_20 -> V_128 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_129 )
F_62 ( V_1 -> V_9 ,
L_15 ,
V_129 ) ;
return V_6 ;
}
void F_63 ( struct V_141 * V_111 , struct V_106 * V_107 )
{
struct V_106 * V_142 ;
V_111 -> V_113 = F_64 ( V_107 , L_16 ) ;
if ( V_111 -> V_113 < 0 )
V_111 -> V_113 = - 1 ;
V_111 -> V_110 = V_143 ;
F_65 ( V_107 , L_17 ,
& V_111 -> V_46 ) ;
V_111 -> V_125 = ( V_111 -> V_46 ) ? true : false ;
F_66 (np, child) {
if ( ! strcmp ( V_142 -> V_116 , L_18 ) ) {
V_111 -> V_2 |= V_31 ;
} else if ( ! strcmp ( V_142 -> V_116 , L_19 ) ) {
V_111 -> V_2 |= V_53 ;
} else if ( ! strcmp ( V_142 -> V_116 , L_20 ) ) {
V_111 -> V_2 |= V_40 ;
} else if ( ! strcmp ( V_142 -> V_116 , L_21 ) ) {
V_111 -> V_2 |= V_38 ;
} else if ( ! strcmp ( V_142 -> V_116 , L_22 ) ) {
V_111 -> V_2 |= V_56 ;
} else if ( ! strcmp ( V_142 -> V_116 , L_23 ) ) {
V_111 -> V_2 |= V_67 ;
}
}
}
int F_67 ( struct V_144 * V_7 , int V_145 )
{
struct V_141 * V_111 = F_68 ( V_7 -> V_9 ) ;
struct V_106 * V_107 = V_7 -> V_9 -> V_146 ;
struct V_1 * V_1 ;
int V_6 ;
if ( ! V_111 ) {
if ( ! V_107 )
return - V_36 ;
V_111 = F_69 ( V_7 -> V_9 , sizeof( * V_111 ) , V_147 ) ;
if ( ! V_111 )
return - V_148 ;
F_63 ( V_111 , V_107 ) ;
if ( F_70 ( V_107 , L_24 , NULL ) == NULL )
V_7 -> V_68 = - 1 ;
}
V_1 = F_69 ( V_7 -> V_9 , sizeof( struct V_1 ) , V_147 ) ;
if ( ! V_1 )
return - V_148 ;
F_71 ( & V_1 -> V_90 ) ;
F_71 ( & V_1 -> V_17 ) ;
V_1 -> V_9 = V_7 -> V_9 ;
V_1 -> V_149 = V_7 -> V_149 ;
V_1 -> V_111 = V_111 ;
V_1 -> V_108 = V_111 -> V_108 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_145 = V_145 ;
V_1 -> V_3 = V_21 [ V_145 ] ;
V_1 -> V_23 = V_1 -> V_3 -> V_23 ;
V_1 -> V_27 = V_1 -> V_3 -> V_27 ;
F_72 ( V_1 -> V_9 , V_1 ) ;
if ( V_7 -> V_150 )
V_7 -> V_150 ( V_1 ) ;
if ( V_111 -> V_151 ) {
V_6 = F_73 ( V_7 -> V_9 , V_111 -> V_152 ,
V_153 , L_25 ) ;
if ( V_6 ) {
F_4 ( V_1 -> V_9 , L_26 ,
V_6 ) ;
return V_6 ;
}
V_1 -> V_68 = F_74 ( V_111 -> V_152 ) ;
} else {
V_1 -> V_68 = V_7 -> V_68 ;
}
if ( V_1 -> V_68 < 0 ) {
F_58 ( V_1 -> V_9 ,
L_27 ,
V_1 -> V_3 -> V_116 ) ;
if ( ! V_154 [ V_1 -> V_145 ] ) {
F_4 ( V_1 -> V_9 ,
L_28 ,
V_1 -> V_3 -> V_116 ) ;
return - V_155 ;
}
V_1 -> V_3 = V_154 [ V_1 -> V_145 ] ;
} else if ( V_111 -> V_110 == V_143 ) {
V_111 -> V_110 =
F_75 ( F_76 ( V_1 -> V_68 ) ) ;
}
V_6 = F_57 ( V_1 ) ;
if ( V_6 )
return V_6 ;
if ( V_1 -> V_68 >= 0 ) {
V_6 = F_55 ( V_1 , V_107 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_77 ( V_7 -> V_9 , V_1 -> V_68 , NULL ,
F_39 , V_111 -> V_110 | V_156 ,
L_25 , V_1 ) ;
if ( V_6 ) {
F_4 ( V_1 -> V_9 , L_29 ,
V_6 ) ;
return V_6 ;
}
}
V_6 = F_61 ( V_1 ) ;
if ( ! V_6 )
return 0 ;
F_4 ( V_1 -> V_9 , L_30 ) ;
F_78 ( V_1 -> V_9 ) ;
return V_6 ;
}
int F_79 ( struct V_1 * V_1 )
{
F_78 ( V_1 -> V_9 ) ;
return 0 ;
}
static int F_80 ( struct V_157 * V_9 )
{
struct V_1 * V_1 = F_81 ( V_9 ) ;
if ( V_1 -> V_68 >= 0 && F_82 ( V_9 ) )
F_83 ( V_1 -> V_68 ) ;
return 0 ;
}
static int F_84 ( struct V_157 * V_9 )
{
struct V_1 * V_1 = F_81 ( V_9 ) ;
if ( V_1 -> V_68 >= 0 && F_82 ( V_9 ) )
F_85 ( V_1 -> V_68 ) ;
return 0 ;
}
