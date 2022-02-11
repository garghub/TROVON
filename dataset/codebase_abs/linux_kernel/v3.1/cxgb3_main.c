static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
F_3 ( V_3 L_1 , V_2 -> V_4 ) ;
else {
const char * V_5 = L_2 ;
const struct V_6 * V_7 = F_4 ( V_2 ) ;
switch ( V_7 -> V_8 . V_9 ) {
case V_10 :
V_5 = L_3 ;
break;
case V_11 :
V_5 = L_4 ;
break;
case V_12 :
V_5 = L_5 ;
break;
}
F_3 ( V_3 L_6 , V_2 -> V_4 , V_5 ,
V_7 -> V_8 . V_13 == V_14 ? L_7 : L_8 ) ;
}
}
static void F_5 ( struct V_15 * V_15 ,
struct V_6 * V_16 )
{
F_6 ( V_15 , V_17 + V_16 -> V_18 . V_19 , 0 ,
V_20 ) ;
F_7 ( V_15 , V_21 + V_16 -> V_18 . V_19 , 0 ) ;
F_7 ( V_15 , V_22 + V_16 -> V_18 . V_19 , V_23 ) ;
F_7 ( V_15 , V_21 + V_16 -> V_18 . V_19 , V_24 ) ;
}
static void F_8 ( struct V_15 * V_15 ,
struct V_6 * V_16 )
{
F_6 ( V_15 , V_17 + V_16 -> V_18 . V_19 ,
V_20 , 0 ) ;
}
void F_9 ( struct V_15 * V_25 , int V_26 , int V_27 )
{
struct V_1 * V_2 = V_25 -> V_28 [ V_26 ] ;
struct V_6 * V_16 = F_4 ( V_2 ) ;
if ( V_27 == F_2 ( V_2 ) )
return;
if ( V_27 ) {
struct V_29 * V_18 = & V_16 -> V_18 ;
F_10 ( V_2 ) ;
F_8 ( V_25 , V_16 ) ;
F_11 ( V_25 , V_16 -> V_26 ) ;
F_12 ( V_25 , V_30 +
V_16 -> V_18 . V_19 ) ;
F_7 ( V_25 ,
V_31 + V_16 -> V_18 . V_19 ,
V_32 ) ;
F_6 ( V_25 ,
V_33 +
V_16 -> V_18 . V_19 ,
V_32 , V_32 ) ;
F_13 ( V_25 , V_16 -> V_26 ) ;
F_14 ( V_18 , V_34 ) ;
} else {
F_15 ( V_2 ) ;
F_5 ( V_25 , V_16 ) ;
}
F_1 ( V_2 ) ;
}
void F_16 ( struct V_15 * V_15 , int V_26 , int V_35 ,
int V_9 , int V_13 , int V_36 )
{
struct V_1 * V_2 = V_15 -> V_28 [ V_26 ] ;
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_29 * V_18 = & V_16 -> V_18 ;
if ( ! F_17 ( V_2 ) )
return;
if ( V_35 != F_2 ( V_2 ) ) {
if ( V_35 ) {
F_8 ( V_15 , V_16 ) ;
F_14 ( V_18 , V_37 ) ;
F_11 ( V_15 , V_16 -> V_26 ) ;
F_12 ( V_15 , V_30 +
V_16 -> V_18 . V_19 ) ;
F_7 ( V_15 ,
V_31 + V_16 -> V_18 . V_19 ,
V_32 ) ;
F_6 ( V_15 ,
V_33 + V_16 -> V_18 . V_19 ,
V_32 , V_32 ) ;
F_13 ( V_15 , V_16 -> V_26 ) ;
F_10 ( V_2 ) ;
} else {
F_15 ( V_2 ) ;
F_11 ( V_15 , V_16 -> V_26 ) ;
F_12 ( V_15 , V_30 + V_16 -> V_18 . V_19 ) ;
F_6 ( V_15 ,
V_33 + V_16 -> V_18 . V_19 ,
V_32 , 0 ) ;
if ( F_18 ( V_15 ) )
V_16 -> V_38 . V_39 -> V_40 ( & V_16 -> V_38 , 1 ) ;
F_12 ( V_15 , V_30 + V_16 -> V_18 . V_19 ) ;
F_19 ( V_18 , V_37 ) ;
F_20 ( & V_16 -> V_38 , V_18 , & V_16 -> V_8 ) ;
F_5 ( V_15 , V_16 ) ;
}
F_1 ( V_2 ) ;
}
}
void F_21 ( struct V_15 * V_25 , int V_26 )
{
static const char * V_41 [] = {
NULL , L_9 , L_10 , L_11 , L_12 , L_12 , L_13
} ;
const struct V_1 * V_2 = V_25 -> V_28 [ V_26 ] ;
const struct V_6 * V_16 = F_4 ( V_2 ) ;
if ( V_16 -> V_38 . V_42 == V_43 )
F_3 ( V_3 L_14 , V_2 -> V_4 ) ;
else
F_3 ( V_3 L_15 , V_2 -> V_4 ,
V_41 [ V_16 -> V_38 . V_42 ] ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
F_23 ( & V_16 -> V_18 , V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_29 * V_18 = & V_16 -> V_18 ;
F_25 ( V_18 ) ;
F_26 ( V_18 , V_44 ) ;
F_27 ( V_18 , V_2 -> V_45 ) ;
F_28 ( V_18 , V_46 , V_2 -> V_47 ) ;
F_28 ( V_18 , V_48 , V_16 -> V_49 . V_50 ) ;
F_23 ( V_18 , V_2 ) ;
F_20 ( & V_16 -> V_38 , V_18 , & V_16 -> V_8 ) ;
F_14 ( V_18 , V_37 | V_34 ) ;
}
static inline void F_29 ( struct V_15 * V_15 )
{
if ( V_15 -> V_51 & V_52 ) {
F_30 ( V_15 -> V_53 ) ;
V_15 -> V_51 &= ~ V_52 ;
} else if ( V_15 -> V_51 & V_54 ) {
F_31 ( V_15 -> V_53 ) ;
V_15 -> V_51 &= ~ V_54 ;
}
}
static T_1 F_32 ( int V_55 , void * V_56 )
{
F_33 ( V_56 ) ;
return V_57 ;
}
static void F_34 ( struct V_15 * V_25 )
{
int V_58 , V_59 , V_60 = 1 , V_61 = sizeof( V_25 -> V_62 [ 0 ] . V_63 ) - 1 ;
snprintf ( V_25 -> V_62 [ 0 ] . V_63 , V_61 , L_16 , V_25 -> V_4 ) ;
V_25 -> V_62 [ 0 ] . V_63 [ V_61 ] = 0 ;
F_35 (adap, j) {
struct V_1 * V_64 = V_25 -> V_28 [ V_59 ] ;
const struct V_6 * V_16 = F_4 ( V_64 ) ;
for ( V_58 = 0 ; V_58 < V_16 -> V_65 ; V_58 ++ , V_60 ++ ) {
snprintf ( V_25 -> V_62 [ V_60 ] . V_63 , V_61 ,
L_17 , V_64 -> V_4 , V_16 -> V_66 + V_58 ) ;
V_25 -> V_62 [ V_60 ] . V_63 [ V_61 ] = 0 ;
}
}
}
static int F_36 ( struct V_15 * V_25 )
{
int V_58 , V_59 , V_67 , V_68 = 0 ;
F_35 (adap, i) {
int V_65 = F_37 ( V_25 , V_58 ) -> V_65 ;
for ( V_59 = 0 ; V_59 < V_65 ; ++ V_59 ) {
V_67 = F_38 ( V_25 -> V_62 [ V_68 + 1 ] . V_69 ,
F_39 ( V_25 ,
V_25 -> V_70 . V_71 [ V_68 ] .
V_72 . V_73 ) , 0 ,
V_25 -> V_62 [ V_68 + 1 ] . V_63 ,
& V_25 -> V_70 . V_71 [ V_68 ] ) ;
if ( V_67 ) {
while ( -- V_68 >= 0 )
F_40 ( V_25 -> V_62 [ V_68 + 1 ] . V_69 ,
& V_25 -> V_70 . V_71 [ V_68 ] ) ;
return V_67 ;
}
V_68 ++ ;
}
}
return 0 ;
}
static void F_41 ( struct V_15 * V_15 )
{
if ( V_15 -> V_51 & V_52 ) {
int V_58 , V_61 = 0 ;
F_40 ( V_15 -> V_62 [ 0 ] . V_69 , V_15 ) ;
F_35 (adapter, i)
V_61 += F_37 ( V_15 , V_58 ) -> V_65 ;
for ( V_58 = 0 ; V_58 < V_61 ; ++ V_58 )
F_40 ( V_15 -> V_62 [ V_58 + 1 ] . V_69 ,
& V_15 -> V_70 . V_71 [ V_58 ] ) ;
} else
F_40 ( V_15 -> V_53 -> V_55 , V_15 ) ;
}
static int F_42 ( struct V_15 * V_25 , unsigned long V_74 ,
unsigned long V_61 )
{
int V_75 = 10 ;
while ( V_25 -> V_70 . V_71 [ 0 ] . V_72 . V_76 < V_74 + V_61 ) {
if ( ! -- V_75 )
return - V_77 ;
F_43 ( 10 ) ;
}
return 0 ;
}
static int F_44 ( struct V_15 * V_25 )
{
int V_58 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
unsigned long V_82 = V_25 -> V_70 . V_71 [ 0 ] . V_72 . V_76 ;
F_45 ( V_25 , 1 ) ;
for ( V_58 = 0 ; V_58 < 16 ; V_58 ++ ) {
struct V_83 * V_84 ;
V_79 = F_46 ( sizeof( * V_84 ) , V_85 ) ;
if ( ! V_79 )
V_79 = V_25 -> V_86 ;
if ( ! V_79 )
goto V_87;
V_84 = (struct V_83 * ) F_47 ( V_79 , sizeof( * V_84 ) ) ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_88 . V_89 = F_48 ( F_49 ( V_90 ) ) ;
F_50 ( V_84 ) = F_48 ( F_51 ( V_91 , V_58 ) ) ;
V_84 -> V_92 = V_93 - 1 ;
V_84 -> V_94 = V_58 ;
F_52 ( V_25 , V_79 ) ;
if ( V_79 == V_25 -> V_86 ) {
F_42 ( V_25 , V_82 , V_58 + 1 ) ;
V_25 -> V_86 = F_46 ( sizeof( * V_81 ) , V_85 ) ;
if ( ! V_25 -> V_86 )
goto V_87;
}
}
for ( V_58 = 0 ; V_58 < 2048 ; V_58 ++ ) {
struct V_95 * V_84 ;
V_79 = F_46 ( sizeof( * V_84 ) , V_85 ) ;
if ( ! V_79 )
V_79 = V_25 -> V_86 ;
if ( ! V_79 )
goto V_87;
V_84 = (struct V_95 * ) F_47 ( V_79 , sizeof( * V_84 ) ) ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_88 . V_89 = F_48 ( F_49 ( V_90 ) ) ;
F_50 ( V_84 ) = F_48 ( F_51 ( V_96 , V_58 ) ) ;
V_84 -> V_97 = F_48 ( F_53 ( V_58 ) ) ;
F_52 ( V_25 , V_79 ) ;
if ( V_79 == V_25 -> V_86 ) {
F_42 ( V_25 , V_82 , 16 + V_58 + 1 ) ;
V_25 -> V_86 = F_46 ( sizeof( * V_81 ) , V_85 ) ;
if ( ! V_25 -> V_86 )
goto V_87;
}
}
for ( V_58 = 0 ; V_58 < 2048 ; V_58 ++ ) {
struct V_98 * V_84 ;
V_79 = F_46 ( sizeof( * V_84 ) , V_85 ) ;
if ( ! V_79 )
V_79 = V_25 -> V_86 ;
if ( ! V_79 )
goto V_87;
V_84 = (struct V_98 * ) F_47 ( V_79 , sizeof( * V_84 ) ) ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_88 . V_89 = F_48 ( F_49 ( V_90 ) ) ;
F_50 ( V_84 ) = F_48 ( F_51 ( V_99 , V_58 ) ) ;
V_84 -> V_100 = F_48 ( F_53 ( V_58 ) ) ;
F_52 ( V_25 , V_79 ) ;
if ( V_79 == V_25 -> V_86 ) {
F_42 ( V_25 , V_82 , 16 + 2048 + V_58 + 1 ) ;
V_25 -> V_86 = F_46 ( sizeof( * V_81 ) , V_85 ) ;
if ( ! V_25 -> V_86 )
goto V_87;
}
}
V_79 = F_46 ( sizeof( * V_81 ) , V_85 ) ;
if ( ! V_79 )
V_79 = V_25 -> V_86 ;
if ( ! V_79 )
goto V_87;
V_81 = (struct V_80 * ) F_47 ( V_79 , sizeof( * V_81 ) ) ;
memset ( V_81 , 0 , sizeof( * V_81 ) ) ;
V_81 -> V_88 . V_89 = F_48 ( F_49 ( V_90 ) ) ;
F_50 ( V_81 ) = F_48 ( F_51 ( V_101 , 0 ) ) ;
V_81 -> V_102 = F_54 ( 1 ) ;
F_52 ( V_25 , V_79 ) ;
V_58 = F_42 ( V_25 , V_82 , 16 + 2048 + 2048 + 1 ) ;
if ( V_79 == V_25 -> V_86 ) {
V_58 = F_42 ( V_25 , V_82 , 16 + 2048 + 2048 + 1 ) ;
V_25 -> V_86 = F_46 ( sizeof( * V_81 ) , V_85 ) ;
}
F_45 ( V_25 , 0 ) ;
return V_58 ;
V_87:
F_45 ( V_25 , 0 ) ;
return - V_103 ;
}
static void F_55 ( struct V_15 * V_25 )
{
int V_58 ;
unsigned int V_104 = F_37 ( V_25 , 0 ) -> V_65 ;
unsigned int V_105 = V_25 -> V_28 [ 1 ] ? F_37 ( V_25 , 1 ) -> V_65 : 1 ;
T_2 V_106 [ V_107 + 1 ] ;
T_3 V_108 [ V_109 ] ;
for ( V_58 = 0 ; V_58 < V_107 ; ++ V_58 )
V_106 [ V_58 ] = V_58 ;
V_106 [ V_107 ] = 0xff ;
for ( V_58 = 0 ; V_58 < V_109 / 2 ; ++ V_58 ) {
V_108 [ V_58 ] = V_58 % V_104 ;
V_108 [ V_58 + V_109 / 2 ] = ( V_58 % V_105 ) + V_104 ;
}
F_56 ( V_25 , V_110 | V_111 | V_112 |
V_113 | V_114 | V_115 |
F_57 ( 6 ) | V_116 , V_106 , V_108 ) ;
}
static void F_58 ( struct V_15 * V_25 )
{
int V_58 , V_59 ;
for ( V_58 = 0 ; V_58 < V_107 ; V_58 ++ ) {
struct V_117 * V_71 = & V_25 -> V_70 . V_71 [ V_58 ] ;
if ( V_71 -> V_25 )
for ( V_59 = 0 ; V_59 < V_118 ; V_59 ++ )
F_7 ( V_25 , V_119 , V_120 | F_59 ( V_71 -> V_121 [ V_59 ] . V_122 ) ) ;
}
}
static void F_60 ( struct V_15 * V_25 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_107 ; V_58 ++ ) {
struct V_117 * V_71 = & V_25 -> V_70 . V_71 [ V_58 ] ;
if ( V_71 -> V_25 )
F_61 ( V_71 -> V_123 , & V_71 -> V_124 , V_71 -> V_124 . V_125 ,
64 ) ;
}
V_25 -> V_51 |= V_126 ;
}
static void F_62 ( struct V_15 * V_25 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_107 ; V_58 ++ )
if ( V_25 -> V_70 . V_71 [ V_58 ] . V_25 )
F_63 ( & V_25 -> V_70 . V_71 [ V_58 ] . V_124 ) ;
}
static void F_64 ( struct V_15 * V_25 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_107 ; V_58 ++ )
if ( V_25 -> V_70 . V_71 [ V_58 ] . V_25 )
F_65 ( & V_25 -> V_70 . V_71 [ V_58 ] . V_124 ) ;
}
static int F_66 ( struct V_15 * V_25 )
{
int V_58 , V_59 , V_67 , V_127 = 0 , V_128 = 0 ;
unsigned int V_129 = V_118 ;
if ( V_25 -> V_97 . V_130 > 0 && ! ( V_25 -> V_51 & V_54 ) )
V_127 = - 1 ;
F_35 (adap, i) {
struct V_1 * V_2 = V_25 -> V_28 [ V_58 ] ;
struct V_6 * V_16 = F_4 ( V_2 ) ;
V_16 -> V_71 = & V_25 -> V_70 . V_71 [ V_16 -> V_66 ] ;
for ( V_59 = 0 ; V_59 < V_16 -> V_65 ; ++ V_59 , ++ V_128 ) {
V_67 = F_67 ( V_25 , V_128 , 1 ,
( V_25 -> V_51 & V_52 ) ? V_128 + 1 :
V_127 ,
& V_25 -> V_97 . V_70 . V_131 [ V_128 ] , V_129 , V_2 ,
F_68 ( V_2 , V_59 ) ) ;
if ( V_67 ) {
F_69 ( V_25 ) ;
return V_67 ;
}
}
}
return 0 ;
}
static T_4 F_70 ( struct V_132 * V_64 , char * V_133 ,
T_4 (* F_71) ( struct V_1 * , char * ) )
{
T_4 V_134 ;
F_72 () ;
V_134 = (* F_71) ( F_73 ( V_64 ) , V_133 ) ;
F_74 () ;
return V_134 ;
}
static T_4 F_75 ( struct V_132 * V_64 ,
const char * V_133 , T_5 V_134 ,
T_4 (* F_76) ( struct V_1 * , unsigned int ) ,
unsigned int V_135 , unsigned int V_136 )
{
char * V_137 ;
T_4 V_138 ;
unsigned int V_139 ;
if ( ! F_77 ( V_140 ) )
return - V_141 ;
V_139 = F_78 ( V_133 , & V_137 , 0 ) ;
if ( V_137 == V_133 || V_139 < V_135 || V_139 > V_136 )
return - V_142 ;
F_72 () ;
V_138 = (* F_76) ( F_73 ( V_64 ) , V_139 ) ;
if ( ! V_138 )
V_138 = V_134 ;
F_74 () ;
return V_138 ;
}
static T_4 F_79 ( struct V_1 * V_2 , unsigned int V_139 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_25 = V_16 -> V_15 ;
int V_143 = F_80 ( V_25 ) ? V_144 : 0 ;
if ( V_25 -> V_51 & V_145 )
return - V_146 ;
if ( V_139 && V_25 -> V_97 . V_130 == 0 )
return - V_142 ;
if ( V_139 > F_81 ( & V_25 -> V_147 ) - V_25 -> V_97 . V_147 . V_148 -
V_143 )
return - V_142 ;
V_25 -> V_97 . V_147 . V_149 = V_139 ;
return 0 ;
}
static T_4 F_82 ( struct V_132 * V_64 , struct V_150 * V_151 ,
const char * V_133 , T_5 V_134 )
{
return F_75 ( V_64 , V_133 , V_134 , F_79 , 0 , ~ 0 ) ;
}
static T_4 F_83 ( struct V_1 * V_2 , unsigned int V_139 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_25 = V_16 -> V_15 ;
if ( V_25 -> V_51 & V_145 )
return - V_146 ;
if ( V_139 > F_81 ( & V_25 -> V_147 ) - V_25 -> V_97 . V_147 . V_149 -
V_144 )
return - V_142 ;
V_25 -> V_97 . V_147 . V_148 = V_139 ;
return 0 ;
}
static T_4 F_84 ( struct V_132 * V_64 , struct V_150 * V_151 ,
const char * V_133 , T_5 V_134 )
{
return F_75 ( V_64 , V_133 , V_134 , F_83 , 0 , ~ 0 ) ;
}
static T_4 F_85 ( struct V_132 * V_64 ,
char * V_133 , int V_152 )
{
struct V_6 * V_16 = F_4 ( F_73 ( V_64 ) ) ;
struct V_15 * V_25 = V_16 -> V_15 ;
unsigned int V_153 , V_154 , V_155 , V_156 ;
T_4 V_134 ;
V_154 = V_157 - V_152 / 2 ;
F_72 () ;
F_7 ( V_25 , V_158 , V_154 ) ;
V_153 = F_12 ( V_25 , V_159 ) ;
if ( V_152 & 1 )
V_153 >>= 16 ;
V_155 = ( V_153 >> 8 ) & 0xff ;
V_156 = V_153 & 0xff ;
if ( ! V_156 )
V_134 = sprintf ( V_133 , L_18 ) ;
else {
V_153 = ( V_25 -> V_97 . V_160 . V_161 * 1000 ) / V_156 ;
V_134 = sprintf ( V_133 , L_19 , ( V_153 * V_155 ) / 125 ) ;
}
F_74 () ;
return V_134 ;
}
static T_4 F_86 ( struct V_132 * V_64 ,
const char * V_133 , T_5 V_134 , int V_152 )
{
struct V_6 * V_16 = F_4 ( F_73 ( V_64 ) ) ;
struct V_15 * V_25 = V_16 -> V_15 ;
unsigned int V_139 ;
char * V_137 ;
T_4 V_138 ;
if ( ! F_77 ( V_140 ) )
return - V_141 ;
V_139 = F_78 ( V_133 , & V_137 , 0 ) ;
if ( V_137 == V_133 || V_139 > 10000000 )
return - V_142 ;
F_72 () ;
V_138 = F_87 ( V_25 , V_139 , V_152 ) ;
if ( ! V_138 )
V_138 = V_134 ;
F_74 () ;
return V_138 ;
}
static inline int F_88 ( struct V_162 * V_163 , struct V_78 * V_79 )
{
int V_138 ;
F_89 () ;
V_138 = F_90 ( V_163 , V_79 ) ;
F_91 () ;
return V_138 ;
}
static int F_92 ( struct V_15 * V_15 , int V_164 )
{
struct V_83 * V_84 ;
struct V_6 * V_16 = F_4 ( V_15 -> V_28 [ V_164 ] ) ;
struct V_78 * V_79 = F_46 ( sizeof( * V_84 ) , V_85 ) ;
if ( ! V_79 )
return - V_103 ;
V_84 = (struct V_83 * ) F_47 ( V_79 , sizeof( * V_84 ) ) ;
V_84 -> V_88 . V_89 = F_48 ( F_49 ( V_90 ) ) ;
F_50 ( V_84 ) = F_48 ( F_51 ( V_91 , V_164 ) ) ;
V_84 -> V_92 = V_93 - 1 ;
V_84 -> V_94 = V_164 ;
memcpy ( V_84 -> V_165 , V_15 -> V_28 [ V_164 ] -> V_47 , V_166 ) ;
memcpy ( V_84 -> V_167 , V_16 -> V_49 . V_50 , V_166 ) ;
V_79 -> V_168 = 1 ;
F_88 ( & V_15 -> V_163 , V_79 ) ;
return 0 ;
}
static int F_93 ( struct V_15 * V_15 )
{
int V_58 ;
F_35 (adapter, i)
F_92 ( V_15 , V_58 ) ;
return 0 ;
}
static void F_94 ( struct V_15 * V_15 )
{
unsigned int V_169 = V_15 -> V_28 [ 0 ] -> V_45 ;
if ( V_15 -> V_28 [ 1 ] )
V_169 |= V_15 -> V_28 [ 1 ] -> V_45 << 16 ;
F_7 ( V_15 , V_170 , V_169 ) ;
}
static int F_95 ( struct V_15 * V_25 , int V_152 , int V_68 , int V_171 ,
int V_172 , int V_28 )
{
struct V_78 * V_79 ;
struct V_173 * V_84 ;
int V_138 ;
V_79 = F_46 ( sizeof( * V_84 ) , V_85 ) ;
if ( ! V_79 )
V_79 = V_25 -> V_86 ;
if ( ! V_79 )
return - V_103 ;
V_84 = (struct V_173 * ) F_96 ( V_79 , sizeof( * V_84 ) ) ;
V_84 -> V_89 = F_48 ( F_49 ( V_174 ) ) ;
V_84 -> V_175 = V_176 ;
V_84 -> V_152 = V_152 ;
V_84 -> V_164 = V_68 ;
V_84 -> V_177 = V_171 ;
V_84 -> V_178 = V_172 ;
V_84 -> V_179 = V_28 ;
V_138 = F_52 ( V_25 , V_79 ) ;
if ( V_79 == V_25 -> V_86 ) {
V_25 -> V_86 = F_46 ( sizeof( struct V_80 ) ,
V_85 ) ;
if ( ! V_25 -> V_86 )
V_138 = - V_103 ;
}
return V_138 ;
}
static int F_97 ( struct V_15 * V_25 )
{
int V_58 , V_59 , V_67 = 0 ;
F_35 (adap, i) {
const struct V_6 * V_16 = F_37 ( V_25 , V_58 ) ;
for ( V_59 = 0 ; V_59 < V_16 -> V_65 ; ++ V_59 ) {
int V_138 = F_95 ( V_25 , 1 ,
V_16 -> V_66 + V_59 , - 1 ,
- 1 , V_58 ) ;
if ( V_138 )
V_67 = V_138 ;
}
}
return V_67 ;
}
static inline const char * F_98 ( int V_180 )
{
const char * V_181 = NULL ;
switch ( V_180 ) {
case V_182 :
V_181 = V_183 ;
break;
case V_184 :
V_181 = V_185 ;
break;
case V_186 :
V_181 = V_187 ;
break;
}
return V_181 ;
}
int F_99 ( struct V_188 * V_38 , int V_180 , int V_189 )
{
struct V_15 * V_15 = V_38 -> V_15 ;
const struct V_190 * V_191 ;
char V_133 [ 64 ] ;
T_6 V_192 ;
const T_7 * V_7 ;
T_3 * V_193 = V_38 -> V_194 ;
int V_58 , V_138 ;
snprintf ( V_133 , sizeof( V_133 ) , F_98 ( V_180 ) ) ;
V_138 = F_100 ( & V_191 , V_133 , & V_15 -> V_53 -> V_2 ) ;
if ( V_138 < 0 ) {
F_101 ( & V_15 -> V_53 -> V_2 ,
L_20 ,
V_133 ) ;
return V_138 ;
}
if ( V_191 -> V_189 > V_189 + 4 ) {
F_102 ( V_15 , L_21 ,
( unsigned int ) V_191 -> V_189 , V_189 + 4 ) ;
V_138 = - V_142 ;
}
V_7 = ( const T_7 * ) V_191 -> V_195 ;
for ( V_192 = 0 , V_58 = 0 ; V_58 < V_191 -> V_189 / sizeof( V_192 ) ; V_58 ++ )
V_192 += F_103 ( V_7 [ V_58 ] ) ;
if ( V_192 != 0xffffffff ) {
F_102 ( V_15 , L_22 ,
V_192 ) ;
V_138 = - V_142 ;
}
for ( V_58 = 0 ; V_58 < V_189 / 4 ; V_58 ++ ) {
* V_193 ++ = ( F_104 ( V_7 [ V_58 ] ) & 0xffff0000 ) >> 16 ;
* V_193 ++ = F_104 ( V_7 [ V_58 ] ) & 0xffff ;
}
F_105 ( V_191 ) ;
return V_138 ;
}
static int F_106 ( struct V_15 * V_25 )
{
int V_138 ;
const struct V_190 * V_191 ;
struct V_132 * V_2 = & V_25 -> V_53 -> V_2 ;
V_138 = F_100 ( & V_191 , V_196 , V_2 ) ;
if ( V_138 < 0 ) {
F_101 ( V_2 , L_20 ,
V_196 ) ;
return V_138 ;
}
V_138 = F_107 ( V_25 , V_191 -> V_195 , V_191 -> V_189 ) ;
F_105 ( V_191 ) ;
if ( V_138 == 0 )
F_108 ( V_2 , L_23 ,
V_197 , V_198 , V_199 ) ;
else
F_101 ( V_2 , L_24 ,
V_197 , V_198 , V_199 ) ;
return V_138 ;
}
static inline char F_109 ( struct V_15 * V_15 )
{
char V_130 = 0 ;
switch( V_15 -> V_97 . V_130 ) {
case V_200 :
case V_201 :
V_130 = 'b' ;
break;
case V_202 :
V_130 = 'c' ;
break;
}
return V_130 ;
}
static int F_110 ( struct V_15 * V_25 )
{
const struct V_190 * V_203 ;
char V_133 [ 64 ] ;
struct V_132 * V_2 = & V_25 -> V_53 -> V_2 ;
int V_138 ;
char V_130 ;
V_130 = F_109 ( V_25 ) ;
if ( ! V_130 )
return 0 ;
snprintf ( V_133 , sizeof( V_133 ) , V_204 , V_130 ) ;
V_138 = F_100 ( & V_203 , V_133 , V_2 ) ;
if ( V_138 < 0 ) {
F_101 ( V_2 , L_25 ,
V_133 ) ;
return V_138 ;
}
V_138 = F_111 ( V_25 , V_203 -> V_195 , V_203 -> V_189 ) ;
if ( V_138 )
goto V_205;
V_138 = F_112 ( V_25 , V_203 -> V_195 ) ;
if ( V_138 == 0 )
F_108 ( V_2 ,
L_26
L_27 ,
V_206 , V_207 , V_208 ) ;
else
F_101 ( V_2 , L_28 ,
V_206 , V_207 , V_208 ) ;
if ( V_138 )
F_101 ( V_2 , L_29 ) ;
V_205:
F_105 ( V_203 ) ;
return V_138 ;
}
static int F_113 ( struct V_15 * V_25 )
{
int V_67 ;
if ( ! ( V_25 -> V_51 & V_145 ) ) {
V_67 = F_114 ( V_25 ) ;
if ( V_67 == - V_142 ) {
V_67 = F_106 ( V_25 ) ;
F_115 ( V_25 , L_30 ,
V_197 , V_198 ,
V_199 , V_67 ? L_31 : L_32 ) ;
}
V_67 = F_116 ( V_25 ) ;
if ( V_67 == - V_142 ) {
V_67 = F_110 ( V_25 ) ;
F_115 ( V_25 , L_33 ,
V_206 , V_207 ,
V_208 , V_67 ? L_31 : L_32 ) ;
}
F_117 ( V_25 ) ;
V_67 = F_118 ( V_25 , 0 ) ;
if ( V_67 )
goto V_209;
F_6 ( V_25 , V_210 , 0 , V_211 ) ;
F_7 ( V_25 , V_212 , F_119 ( V_213 - 12 ) ) ;
V_67 = F_66 ( V_25 ) ;
if ( V_67 )
goto V_209;
F_55 ( V_25 ) ;
if ( ! ( V_25 -> V_51 & V_126 ) )
F_60 ( V_25 ) ;
F_120 ( V_25 ) ;
V_25 -> V_51 |= V_145 ;
}
F_117 ( V_25 ) ;
if ( V_25 -> V_51 & V_52 ) {
F_34 ( V_25 ) ;
V_67 = F_38 ( V_25 -> V_62 [ 0 ] . V_69 ,
F_32 , 0 ,
V_25 -> V_62 [ 0 ] . V_63 , V_25 ) ;
if ( V_67 )
goto V_214;
V_67 = F_36 ( V_25 ) ;
if ( V_67 ) {
F_40 ( V_25 -> V_62 [ 0 ] . V_69 , V_25 ) ;
goto V_214;
}
} else if ( ( V_67 = F_38 ( V_25 -> V_53 -> V_55 ,
F_39 ( V_25 ,
V_25 -> V_70 . V_71 [ 0 ] . V_72 .
V_73 ) ,
( V_25 -> V_51 & V_54 ) ?
0 : V_215 ,
V_25 -> V_4 , V_25 ) ) )
goto V_214;
F_64 ( V_25 ) ;
F_121 ( V_25 ) ;
F_122 ( V_25 ) ;
if ( V_25 -> V_97 . V_130 >= V_202 && ! ( V_25 -> V_51 & V_216 ) &&
F_80 ( V_25 ) && F_44 ( V_25 ) == 0 )
V_25 -> V_51 |= V_216 ;
if ( V_25 -> V_51 & V_216 ) {
F_7 ( V_25 , V_217 ,
V_218 | V_219 ) ;
F_7 ( V_25 , V_220 , 0x7fbfffff ) ;
}
if ( ! ( V_25 -> V_51 & V_221 ) ) {
int V_138 = F_97 ( V_25 ) ;
if ( V_138 < 0 ) {
F_102 ( V_25 , L_34 , V_138 ) ;
F_123 ( V_25 ) ;
F_41 ( V_25 ) ;
V_67 = V_138 ;
goto V_209;
}
V_25 -> V_51 |= V_221 ;
}
V_209:
return V_67 ;
V_214:
F_102 ( V_25 , L_35 , V_67 ) ;
goto V_209;
}
static void F_124 ( struct V_15 * V_15 , int V_222 )
{
F_125 ( V_15 ) ;
F_126 ( & V_15 -> V_223 ) ;
F_123 ( V_15 ) ;
F_127 ( & V_15 -> V_223 ) ;
F_41 ( V_15 ) ;
F_62 ( V_15 ) ;
F_125 ( V_15 ) ;
if ( ! V_222 )
F_128 ( V_224 ) ;
}
static void F_129 ( struct V_15 * V_25 )
{
unsigned int V_225 ;
V_225 = V_25 -> V_97 . V_226 ?
( V_227 * V_25 -> V_97 . V_226 ) / 10 :
V_25 -> V_97 . V_228 * V_227 ;
if ( V_225 )
F_130 ( V_224 , & V_25 -> V_229 , V_225 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
struct V_162 * V_163 = F_132 ( V_2 ) ;
int V_230 = V_15 -> V_231 & V_232 ;
int V_67 ;
if ( F_133 ( V_233 , & V_15 -> V_231 ) )
return 0 ;
if ( ! V_230 && ( V_67 = F_113 ( V_15 ) ) < 0 )
goto V_209;
F_45 ( V_15 , 1 ) ;
V_163 -> V_234 = V_15 -> V_28 [ 0 ] ;
V_67 = F_134 ( V_15 ) ;
if ( V_67 )
goto V_209;
F_94 ( V_15 ) ;
F_135 ( V_15 , V_15 -> V_97 . V_169 , V_15 -> V_97 . V_235 ,
V_15 -> V_97 . V_236 ,
V_15 -> V_97 . V_130 == 0 ?
V_15 -> V_28 [ 0 ] -> V_45 : 0xffff ) ;
F_93 ( V_15 ) ;
if ( F_136 ( & V_163 -> V_234 -> V_2 . V_237 , & V_238 ) )
F_137 ( & V_2 -> V_2 , L_36 ) ;
F_138 ( V_163 ) ;
V_209:
if ( V_67 ) {
F_45 ( V_15 , 0 ) ;
F_139 ( V_233 , & V_15 -> V_231 ) ;
F_140 ( V_163 ) ;
}
return V_67 ;
}
static int F_141 ( struct V_162 * V_163 )
{
struct V_15 * V_15 = F_142 ( V_163 ) ;
struct V_239 * V_240 = F_143 ( V_163 ) ;
if ( ! F_144 ( V_233 , & V_15 -> V_231 ) )
return 0 ;
F_145 ( V_163 ) ;
F_146 ( & V_163 -> V_234 -> V_2 . V_237 , & V_238 ) ;
F_147 ( & V_240 -> V_241 ) ;
V_163 -> V_234 = NULL ;
F_140 ( V_163 ) ;
F_45 ( V_15 , 0 ) ;
F_139 ( V_233 , & V_15 -> V_231 ) ;
if ( ! V_15 -> V_231 )
F_124 ( V_15 , 0 ) ;
F_148 ( V_15 ) ;
return 0 ;
}
static int F_149 ( struct V_1 * V_2 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
int V_242 = V_15 -> V_231 & V_232 ;
int V_67 ;
if ( ! V_15 -> V_231 && ( V_67 = F_113 ( V_15 ) ) < 0 )
return V_67 ;
F_150 ( V_16 -> V_26 , & V_15 -> V_231 ) ;
if ( F_80 ( V_15 ) && ! V_243 ) {
V_67 = F_131 ( V_2 ) ;
if ( V_67 )
F_3 ( V_244
L_37 ) ;
}
F_151 ( V_2 , V_16 -> V_65 ) ;
V_67 = F_152 ( V_2 , V_16 -> V_65 ) ;
if ( V_67 )
return V_67 ;
F_24 ( V_2 ) ;
F_153 ( V_15 , V_16 -> V_26 ) ;
F_154 ( V_2 ) ;
if ( ! V_242 )
F_129 ( V_15 ) ;
F_155 ( & V_15 -> V_163 , V_245 , V_16 -> V_26 ) ;
return 0 ;
}
static int F_156 ( struct V_1 * V_2 , int V_222 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
if ( ! V_15 -> V_231 )
return 0 ;
F_11 ( V_15 , V_16 -> V_26 ) ;
F_12 ( V_15 , V_30 + V_16 -> V_18 . V_19 ) ;
F_157 ( V_15 , V_16 -> V_26 ) ;
F_158 ( V_2 ) ;
V_16 -> V_38 . V_39 -> V_40 ( & V_16 -> V_38 , 1 ) ;
F_15 ( V_2 ) ;
F_19 ( & V_16 -> V_18 , V_34 | V_37 ) ;
F_126 ( & V_15 -> V_223 ) ;
F_139 ( V_16 -> V_26 , & V_15 -> V_231 ) ;
F_127 ( & V_15 -> V_223 ) ;
if ( ! ( V_15 -> V_231 & V_232 ) )
F_159 ( & V_15 -> V_229 ) ;
if ( ! V_15 -> V_231 )
F_124 ( V_15 , V_222 ) ;
F_155 ( & V_15 -> V_163 , V_246 , V_16 -> V_26 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 )
{
return F_156 ( V_2 , 0 ) ;
}
static struct V_247 * F_161 ( struct V_1 * V_2 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
struct V_247 * V_248 = & V_16 -> V_249 ;
const struct V_250 * V_251 ;
F_162 ( & V_15 -> V_252 ) ;
V_251 = F_163 ( & V_16 -> V_18 ) ;
F_164 ( & V_15 -> V_252 ) ;
V_248 -> V_253 = V_251 -> V_254 ;
V_248 -> V_255 = V_251 -> V_256 ;
V_248 -> V_257 = V_251 -> V_258 ;
V_248 -> V_259 = V_251 -> V_260 ;
V_248 -> V_261 = V_251 -> V_262 ;
V_248 -> V_263 = V_251 -> V_264 ;
V_248 -> V_265 = V_251 -> V_266 + V_251 -> V_267 +
V_251 -> V_268 + V_251 -> V_269 + V_251 -> V_270 +
V_251 -> V_271 ;
V_248 -> V_272 = V_251 -> V_269 + V_251 -> V_268 ;
V_248 -> V_273 = 0 ;
V_248 -> V_274 = V_251 -> V_267 ;
V_248 -> V_275 = V_251 -> V_266 ;
V_248 -> V_276 = V_251 -> V_271 ;
V_248 -> V_277 = V_251 -> V_278 ;
V_248 -> V_279 = 0 ;
V_248 -> V_280 = 0 ;
V_248 -> V_281 = V_251 -> V_264 ;
V_248 -> V_282 = 0 ;
V_248 -> V_283 = 0 ;
return V_248 ;
}
static T_6 F_165 ( struct V_1 * V_2 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
return V_15 -> V_284 ;
}
static void F_166 ( struct V_1 * V_2 , T_6 V_139 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
V_15 -> V_284 = V_139 ;
}
static int F_167 ( struct V_1 * V_2 , int V_285 )
{
switch ( V_285 ) {
case V_286 :
return F_168 ( V_287 ) ;
default:
return - V_288 ;
}
}
static int F_169 ( struct V_1 * V_2 )
{
return V_289 ;
}
static int F_170 ( struct V_1 * V_2 )
{
return V_290 ;
}
static void F_171 ( struct V_1 * V_2 , struct V_291 * V_292 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
T_6 V_293 = 0 ;
T_6 V_294 = 0 ;
F_162 ( & V_15 -> V_252 ) ;
F_172 ( V_15 , & V_293 ) ;
F_173 ( V_15 , & V_294 ) ;
F_164 ( & V_15 -> V_252 ) ;
strcpy ( V_292 -> V_295 , V_296 ) ;
strcpy ( V_292 -> V_297 , V_298 ) ;
strcpy ( V_292 -> V_299 , F_174 ( V_15 -> V_53 ) ) ;
if ( ! V_293 )
strcpy ( V_292 -> V_300 , L_38 ) ;
else {
snprintf ( V_292 -> V_300 , sizeof( V_292 -> V_300 ) ,
L_39 ,
F_175 ( V_293 ) ? L_40 : L_41 ,
F_176 ( V_293 ) ,
F_177 ( V_293 ) ,
F_178 ( V_293 ) ,
F_179 ( V_294 ) ,
F_180 ( V_294 ) ,
F_181 ( V_294 ) ) ;
}
}
static void F_182 ( struct V_1 * V_2 , T_6 V_301 , T_2 * V_195 )
{
if ( V_301 == V_286 )
memcpy ( V_195 , V_287 , sizeof( V_287 ) ) ;
}
static unsigned long F_183 ( struct V_15 * V_15 ,
struct V_6 * V_7 , int V_164 )
{
int V_58 ;
unsigned long V_302 = 0 ;
for ( V_58 = V_7 -> V_66 ; V_58 < V_7 -> V_66 + V_7 -> V_65 ; ++ V_58 )
V_302 += V_15 -> V_70 . V_71 [ V_58 ] . V_303 [ V_164 ] ;
return V_302 ;
}
static void F_184 ( struct V_1 * V_2 , struct V_304 * V_305 ,
T_8 * V_195 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
const struct V_250 * V_5 ;
F_162 ( & V_15 -> V_252 ) ;
V_5 = F_163 ( & V_16 -> V_18 ) ;
F_164 ( & V_15 -> V_252 ) ;
* V_195 ++ = V_5 -> V_254 ;
* V_195 ++ = V_5 -> V_256 ;
* V_195 ++ = V_5 -> V_306 ;
* V_195 ++ = V_5 -> V_307 ;
* V_195 ++ = V_5 -> V_308 ;
* V_195 ++ = V_5 -> V_264 ;
* V_195 ++ = V_5 -> V_309 ;
* V_195 ++ = V_5 -> V_310 ;
* V_195 ++ = V_5 -> V_311 ;
* V_195 ++ = V_5 -> V_312 ;
* V_195 ++ = V_5 -> V_313 ;
* V_195 ++ = V_5 -> V_314 ;
* V_195 ++ = V_5 -> V_315 ;
* V_195 ++ = V_5 -> V_316 ;
* V_195 ++ = V_5 -> V_258 ;
* V_195 ++ = V_5 -> V_260 ;
* V_195 ++ = V_5 -> V_262 ;
* V_195 ++ = V_5 -> V_317 ;
* V_195 ++ = V_5 -> V_318 ;
* V_195 ++ = V_5 -> V_267 ;
* V_195 ++ = V_5 -> V_266 ;
* V_195 ++ = V_5 -> V_270 ;
* V_195 ++ = V_5 -> V_269 ;
* V_195 ++ = V_5 -> V_268 ;
* V_195 ++ = V_5 -> V_271 ;
* V_195 ++ = V_5 -> V_319 ;
* V_195 ++ = V_5 -> V_320 ;
* V_195 ++ = V_5 -> V_321 ;
* V_195 ++ = V_5 -> V_322 ;
* V_195 ++ = V_5 -> V_323 ;
* V_195 ++ = V_5 -> V_324 ;
* V_195 ++ = V_5 -> V_325 ;
* V_195 ++ = V_16 -> V_38 . V_326 ;
* V_195 ++ = F_183 ( V_15 , V_16 , V_327 ) ;
* V_195 ++ = F_183 ( V_15 , V_16 , V_328 ) ;
* V_195 ++ = F_183 ( V_15 , V_16 , V_329 ) ;
* V_195 ++ = F_183 ( V_15 , V_16 , V_330 ) ;
* V_195 ++ = F_183 ( V_15 , V_16 , V_331 ) ;
* V_195 ++ = 0 ;
* V_195 ++ = 0 ;
* V_195 ++ = 0 ;
* V_195 ++ = V_5 -> V_278 ;
* V_195 ++ = V_5 -> V_332 ;
* V_195 ++ = V_5 -> V_333 ;
* V_195 ++ = V_5 -> V_334 ;
}
static inline void F_185 ( struct V_15 * V_335 , void * V_133 ,
unsigned int V_336 , unsigned int V_337 )
{
T_6 * V_7 = V_133 + V_336 ;
for (; V_336 <= V_337 ; V_336 += sizeof( T_6 ) )
* V_7 ++ = F_12 ( V_335 , V_336 ) ;
}
static void F_186 ( struct V_1 * V_2 , struct V_338 * V_339 ,
void * V_133 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_335 = V_16 -> V_15 ;
V_339 -> V_297 = 3 | ( V_335 -> V_97 . V_130 << 10 ) | ( F_187 ( V_335 ) << 31 ) ;
memset ( V_133 , 0 , V_289 ) ;
F_185 ( V_335 , V_133 , 0 , V_340 ) ;
F_185 ( V_335 , V_133 , V_341 , V_342 ) ;
F_185 ( V_335 , V_133 , V_343 , V_344 ) ;
F_185 ( V_335 , V_133 , V_345 , V_346 ) ;
F_185 ( V_335 , V_133 , V_347 , V_348 ) ;
F_185 ( V_335 , V_133 , V_349 ,
F_188 ( V_348 , 1 ) ) ;
F_185 ( V_335 , V_133 , F_188 ( V_349 , 1 ) ,
F_188 ( V_350 , 1 ) ) ;
}
static int F_189 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
if ( ! F_17 ( V_2 ) )
return - V_351 ;
if ( V_7 -> V_8 . V_352 != V_353 )
return - V_142 ;
V_7 -> V_38 . V_39 -> V_354 ( & V_7 -> V_38 ) ;
return 0 ;
}
static int F_190 ( struct V_1 * V_2 ,
enum V_355 V_27 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
switch ( V_27 ) {
case V_356 :
return 1 ;
case V_357 :
F_6 ( V_15 , V_358 , V_359 , 0 ) ;
break;
case V_360 :
case V_361 :
F_6 ( V_15 , V_358 , V_359 ,
V_359 ) ;
}
return 0 ;
}
static int F_191 ( struct V_1 * V_2 , struct V_362 * V_363 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_363 -> V_364 = V_7 -> V_8 . V_364 ;
V_363 -> V_365 = V_7 -> V_8 . V_365 ;
if ( F_2 ( V_2 ) ) {
F_192 ( V_363 , V_7 -> V_8 . V_9 ) ;
V_363 -> V_13 = V_7 -> V_8 . V_13 ;
} else {
F_192 ( V_363 , - 1 ) ;
V_363 -> V_13 = - 1 ;
}
V_363 -> V_28 = ( V_363 -> V_364 & V_366 ) ? V_367 : V_368 ;
V_363 -> V_369 = V_7 -> V_38 . V_370 . V_371 ;
V_363 -> V_372 = V_373 ;
V_363 -> V_352 = V_7 -> V_8 . V_352 ;
V_363 -> V_374 = 0 ;
V_363 -> V_375 = 0 ;
return 0 ;
}
static int F_193 ( int V_9 , int V_13 )
{
int V_376 = 0 ;
switch ( V_9 ) {
case V_377 :
if ( V_13 == V_14 )
V_376 = V_378 ;
else
V_376 = V_379 ;
break;
case V_12 :
if ( V_13 == V_14 )
V_376 = V_380 ;
else
V_376 = V_381 ;
break;
case V_11 :
if ( V_13 == V_14 )
V_376 = V_382 ;
else
V_376 = V_383 ;
break;
case V_10 :
if ( V_13 == V_14 )
V_376 = V_384 ;
}
return V_376 ;
}
static int F_194 ( struct V_1 * V_2 , struct V_362 * V_363 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_8 * V_385 = & V_7 -> V_8 ;
if ( ! ( V_385 -> V_364 & V_386 ) ) {
if ( V_363 -> V_352 == V_387 ) {
T_6 V_9 = F_195 ( V_363 ) ;
int V_376 = F_193 ( V_9 , V_363 -> V_13 ) ;
if ( V_385 -> V_364 & V_376 )
return 0 ;
}
return - V_142 ;
}
if ( V_363 -> V_352 == V_387 ) {
T_6 V_9 = F_195 ( V_363 ) ;
int V_376 = F_193 ( V_9 , V_363 -> V_13 ) ;
if ( ! ( V_385 -> V_364 & V_376 ) || ( V_9 == V_11 ) )
return - V_142 ;
V_385 -> V_388 = V_9 ;
V_385 -> V_389 = V_363 -> V_13 ;
V_385 -> V_365 = 0 ;
} else {
V_363 -> V_365 &= V_390 ;
V_363 -> V_365 &= V_385 -> V_364 ;
if ( ! V_363 -> V_365 )
return - V_142 ;
V_385 -> V_388 = V_391 ;
V_385 -> V_389 = V_392 ;
V_385 -> V_365 = V_363 -> V_365 | V_393 ;
}
V_385 -> V_352 = V_363 -> V_352 ;
if ( F_17 ( V_2 ) )
F_20 ( & V_7 -> V_38 , & V_7 -> V_18 , V_385 ) ;
return 0 ;
}
static void F_196 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_395 -> V_352 = ( V_7 -> V_8 . V_396 & V_397 ) != 0 ;
V_395 -> V_318 = ( V_7 -> V_8 . V_398 & V_399 ) != 0 ;
V_395 -> V_308 = ( V_7 -> V_8 . V_398 & V_400 ) != 0 ;
}
static int F_197 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_8 * V_385 = & V_7 -> V_8 ;
if ( V_395 -> V_352 == V_387 )
V_385 -> V_396 = 0 ;
else if ( V_385 -> V_364 & V_386 )
V_385 -> V_396 = V_397 ;
else
return - V_142 ;
if ( V_395 -> V_318 )
V_385 -> V_396 |= V_399 ;
if ( V_395 -> V_308 )
V_385 -> V_396 |= V_400 ;
if ( V_385 -> V_352 == V_353 ) {
if ( F_17 ( V_2 ) )
F_20 ( & V_7 -> V_38 , & V_7 -> V_18 , V_385 ) ;
} else {
V_385 -> V_398 = V_385 -> V_396 & ( V_399 | V_400 ) ;
if ( F_17 ( V_2 ) )
F_198 ( & V_7 -> V_18 , - 1 , - 1 , V_385 -> V_398 ) ;
}
return 0 ;
}
static void F_199 ( struct V_1 * V_2 , struct V_401 * V_402 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
const struct V_403 * V_404 = & V_15 -> V_97 . V_70 . V_131 [ V_16 -> V_66 ] ;
V_402 -> V_405 = V_406 ;
V_402 -> V_407 = 0 ;
V_402 -> V_408 = V_409 ;
V_402 -> V_410 = V_411 ;
V_402 -> V_412 = V_404 -> V_413 ;
V_402 -> V_414 = V_404 -> V_415 ;
V_402 -> V_416 = V_404 -> V_417 ;
V_402 -> V_418 = V_404 -> V_419 [ 0 ] ;
}
static int F_200 ( struct V_1 * V_2 , struct V_401 * V_402 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
struct V_403 * V_404 ;
int V_58 ;
if ( V_402 -> V_412 > V_406 ||
V_402 -> V_416 > V_409 ||
V_402 -> V_418 > V_411 ||
V_402 -> V_414 > V_420 ||
V_402 -> V_414 < V_421 ||
V_402 -> V_412 < V_422 ||
V_402 -> V_416 < V_422 ||
V_402 -> V_418 < V_15 -> V_97 . V_423 * V_424 )
return - V_142 ;
if ( V_15 -> V_51 & V_145 )
return - V_146 ;
V_404 = & V_15 -> V_97 . V_70 . V_131 [ V_16 -> V_66 ] ;
for ( V_58 = 0 ; V_58 < V_16 -> V_65 ; ++ V_58 , ++ V_404 ) {
V_404 -> V_415 = V_402 -> V_414 ;
V_404 -> V_413 = V_402 -> V_412 ;
V_404 -> V_417 = V_402 -> V_416 ;
V_404 -> V_419 [ 0 ] = V_402 -> V_418 ;
V_404 -> V_419 [ 1 ] = V_402 -> V_418 ;
V_404 -> V_419 [ 2 ] = V_402 -> V_418 ;
}
return 0 ;
}
static int F_201 ( struct V_1 * V_2 , struct V_425 * V_426 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
struct V_403 * V_427 ;
struct V_117 * V_71 ;
int V_58 ;
if ( V_426 -> V_428 * 10 > V_429 )
return - V_142 ;
for ( V_58 = 0 ; V_58 < V_16 -> V_65 ; V_58 ++ ) {
V_427 = & V_15 -> V_97 . V_70 . V_131 [ V_58 ] ;
V_71 = & V_15 -> V_70 . V_71 [ V_58 ] ;
V_427 -> V_430 = V_426 -> V_428 ;
F_202 ( V_71 , V_427 ) ;
}
return 0 ;
}
static int F_203 ( struct V_1 * V_2 , struct V_425 * V_426 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
struct V_403 * V_404 = V_15 -> V_97 . V_70 . V_131 ;
V_426 -> V_428 = V_404 -> V_430 ;
return 0 ;
}
static int F_204 ( struct V_1 * V_2 , struct V_431 * V_402 ,
T_2 * V_195 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
int V_58 , V_67 = 0 ;
T_2 * V_133 = F_205 ( V_290 , V_85 ) ;
if ( ! V_133 )
return - V_103 ;
V_402 -> V_432 = V_433 ;
for ( V_58 = V_402 -> V_19 & ~ 3 ; ! V_67 && V_58 < V_402 -> V_19 + V_402 -> V_134 ; V_58 += 4 )
V_67 = F_206 ( V_15 , V_58 , ( V_434 * ) & V_133 [ V_58 ] ) ;
if ( ! V_67 )
memcpy ( V_195 , V_133 + V_402 -> V_19 , V_402 -> V_134 ) ;
F_207 ( V_133 ) ;
return V_67 ;
}
static int F_208 ( struct V_1 * V_2 , struct V_431 * V_435 ,
T_2 * V_195 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
T_6 V_436 , V_437 ;
V_434 * V_7 ;
T_2 * V_133 ;
int V_67 ;
if ( V_435 -> V_432 != V_433 )
return - V_142 ;
V_436 = V_435 -> V_19 & ~ 3 ;
V_437 = ( V_435 -> V_134 + ( V_435 -> V_19 & 3 ) + 3 ) & ~ 3 ;
if ( V_436 != V_435 -> V_19 || V_437 != V_435 -> V_134 ) {
V_133 = F_205 ( V_437 , V_85 ) ;
if ( ! V_133 )
return - V_103 ;
V_67 = F_206 ( V_15 , V_436 , ( V_434 * ) V_133 ) ;
if ( ! V_67 && V_437 > 4 )
V_67 = F_206 ( V_15 ,
V_436 + V_437 - 4 ,
( V_434 * ) & V_133 [ V_437 - 4 ] ) ;
if ( V_67 )
goto V_209;
memcpy ( V_133 + ( V_435 -> V_19 & 3 ) , V_195 , V_435 -> V_134 ) ;
} else
V_133 = V_195 ;
V_67 = F_209 ( V_15 , 0 ) ;
if ( V_67 )
goto V_209;
for ( V_7 = ( V_434 * ) V_133 ; ! V_67 && V_437 ; V_437 -= 4 , V_7 ++ ) {
V_67 = F_210 ( V_15 , V_436 , * V_7 ) ;
V_436 += 4 ;
}
if ( ! V_67 )
V_67 = F_209 ( V_15 , 1 ) ;
V_209:
if ( V_133 != V_195 )
F_207 ( V_133 ) ;
return V_67 ;
}
static void F_211 ( struct V_1 * V_2 , struct V_438 * V_439 )
{
V_439 -> V_364 = 0 ;
V_439 -> V_440 = 0 ;
memset ( & V_439 -> V_441 , 0 , sizeof( V_439 -> V_441 ) ) ;
}
static int F_212 ( int V_139 , int V_171 , int V_172 )
{
return V_139 < 0 || ( V_139 <= V_172 && V_139 >= V_171 ) ;
}
static int F_213 ( struct V_1 * V_2 , void T_9 * V_442 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
T_6 V_363 ;
int V_138 ;
if ( F_214 ( & V_363 , V_442 , sizeof( V_363 ) ) )
return - V_443 ;
switch ( V_363 ) {
case V_444 : {
int V_58 ;
struct V_403 * V_404 ;
struct V_445 V_446 ;
int V_447 = V_16 -> V_66 ;
int V_65 = V_16 -> V_65 ;
if ( ! F_77 ( V_140 ) )
return - V_141 ;
if ( F_214 ( & V_446 , V_442 , sizeof( V_446 ) ) )
return - V_443 ;
if ( V_446 . V_128 >= V_107 )
return - V_142 ;
if ( ! F_212 ( V_446 . V_448 , 0 , V_429 ) ||
! F_212 ( V_446 . V_449 , 0 , 255 ) ||
! F_212 ( V_446 . V_419 [ 0 ] , V_424 ,
V_411 ) ||
! F_212 ( V_446 . V_419 [ 1 ] , V_424 ,
V_411 ) ||
! F_212 ( V_446 . V_419 [ 2 ] , V_450 ,
V_451 ) ||
! F_212 ( V_446 . V_413 [ 0 ] , V_422 ,
V_406 ) ||
! F_212 ( V_446 . V_413 [ 1 ] , V_422 ,
V_409 ) ||
! F_212 ( V_446 . V_415 , V_421 ,
V_420 ) )
return - V_142 ;
if ( ( V_15 -> V_51 & V_145 ) &&
( V_446 . V_415 >= 0 || V_446 . V_413 [ 0 ] >= 0 ||
V_446 . V_413 [ 1 ] >= 0 || V_446 . V_419 [ 0 ] >= 0 ||
V_446 . V_419 [ 1 ] >= 0 || V_446 . V_419 [ 2 ] >= 0 ||
V_446 . V_73 >= 0 || V_446 . V_449 >= 0 ) )
return - V_146 ;
if ( F_144 ( V_233 , & V_15 -> V_231 ) ) {
V_447 = 0 ;
F_35 (adapter, i) {
V_16 = F_37 ( V_15 , V_58 ) ;
V_65 += V_16 -> V_66 + V_16 -> V_65 ;
}
}
if ( V_446 . V_128 < V_447 )
return - V_142 ;
if ( V_446 . V_128 > V_447 + V_65 - 1 )
return - V_142 ;
V_404 = & V_15 -> V_97 . V_70 . V_131 [ V_446 . V_128 ] ;
if ( V_446 . V_415 >= 0 )
V_404 -> V_415 = V_446 . V_415 ;
if ( V_446 . V_413 [ 0 ] >= 0 )
V_404 -> V_413 = V_446 . V_413 [ 0 ] ;
if ( V_446 . V_413 [ 1 ] >= 0 )
V_404 -> V_417 = V_446 . V_413 [ 1 ] ;
if ( V_446 . V_419 [ 0 ] >= 0 )
V_404 -> V_419 [ 0 ] = V_446 . V_419 [ 0 ] ;
if ( V_446 . V_419 [ 1 ] >= 0 )
V_404 -> V_419 [ 1 ] = V_446 . V_419 [ 1 ] ;
if ( V_446 . V_419 [ 2 ] >= 0 )
V_404 -> V_419 [ 2 ] = V_446 . V_419 [ 2 ] ;
if ( V_446 . V_449 >= 0 )
V_404 -> V_449 = V_446 . V_449 ;
if ( V_446 . V_448 >= 0 ) {
struct V_117 * V_71 =
& V_15 -> V_70 . V_71 [ V_446 . V_128 ] ;
V_404 -> V_430 = V_446 . V_448 ;
F_202 ( V_71 , V_404 ) ;
}
if ( V_446 . V_73 >= 0 ) {
if ( V_15 -> V_51 & V_52 )
V_404 -> V_73 = V_446 . V_73 ;
else {
if ( V_15 -> V_97 . V_130 == 0 &&
! ( V_15 -> V_51 & V_54 ) )
V_446 . V_73 = 0 ;
for ( V_58 = 0 ; V_58 < V_107 ; V_58 ++ ) {
V_404 = & V_15 -> V_97 . V_70 .
V_131 [ V_58 ] ;
V_404 -> V_73 = V_446 . V_73 ;
}
}
}
if ( V_446 . V_452 >= 0 ) {
if ( V_446 . V_452 )
V_2 -> V_453 |= V_454 ;
else
V_2 -> V_453 &= ~ V_454 ;
F_215 ( V_2 ) ;
}
break;
}
case V_455 : {
struct V_403 * V_404 ;
struct V_445 V_446 ;
int V_447 = V_16 -> V_66 ;
int V_65 = V_16 -> V_65 ;
int V_58 ;
if ( F_214 ( & V_446 , V_442 , sizeof( V_446 ) ) )
return - V_443 ;
if ( F_144 ( V_233 , & V_15 -> V_231 ) ) {
V_447 = 0 ;
F_35 (adapter, i) {
V_16 = F_37 ( V_15 , V_58 ) ;
V_65 = V_16 -> V_66 + V_16 -> V_65 ;
}
}
if ( V_446 . V_128 >= V_65 )
return - V_142 ;
V_404 = & V_15 -> V_97 . V_70 . V_131 [ V_447 + V_446 . V_128 ] ;
V_446 . V_415 = V_404 -> V_415 ;
V_446 . V_419 [ 0 ] = V_404 -> V_419 [ 0 ] ;
V_446 . V_419 [ 1 ] = V_404 -> V_419 [ 1 ] ;
V_446 . V_419 [ 2 ] = V_404 -> V_419 [ 2 ] ;
V_446 . V_413 [ 0 ] = V_404 -> V_413 ;
V_446 . V_413 [ 1 ] = V_404 -> V_417 ;
V_446 . V_73 = V_404 -> V_73 ;
V_446 . V_452 = ! ! ( V_2 -> V_456 & V_454 ) ;
V_446 . V_448 = V_404 -> V_430 ;
V_446 . V_449 = V_404 -> V_449 ;
V_446 . V_457 = V_447 ;
if ( V_15 -> V_51 & V_52 )
V_446 . V_458 = V_15 -> V_62 [ V_447 + V_446 . V_128 + 1 ] . V_69 ;
else
V_446 . V_458 = V_15 -> V_53 -> V_55 ;
if ( F_216 ( V_442 , & V_446 , sizeof( V_446 ) ) )
return - V_443 ;
break;
}
case V_459 : {
struct V_460 V_461 ;
unsigned int V_58 , V_66 = 0 , V_462 = 0 ;
if ( ! F_77 ( V_140 ) )
return - V_141 ;
if ( V_15 -> V_51 & V_145 )
return - V_146 ;
if ( F_214 ( & V_461 , V_442 , sizeof( V_461 ) ) )
return - V_443 ;
if ( V_461 . V_139 < 1 ||
( V_461 . V_139 > 1 && ! ( V_15 -> V_51 & V_52 ) ) )
return - V_142 ;
F_35 (adapter, i)
if ( V_15 -> V_28 [ V_58 ] && V_15 -> V_28 [ V_58 ] != V_2 )
V_462 += F_37 ( V_15 , V_58 ) -> V_65 ;
if ( V_461 . V_139 + V_462 > V_107 )
return - V_142 ;
V_16 -> V_65 = V_461 . V_139 ;
F_35 (adapter, i)
if ( V_15 -> V_28 [ V_58 ] ) {
V_16 = F_37 ( V_15 , V_58 ) ;
V_16 -> V_66 = V_66 ;
V_66 += V_16 -> V_65 ;
}
break;
}
case V_463 : {
struct V_460 V_461 ;
memset ( & V_461 , 0 , sizeof( struct V_460 ) ) ;
V_461 . V_363 = V_463 ;
V_461 . V_139 = V_16 -> V_65 ;
if ( F_216 ( V_442 , & V_461 , sizeof( V_461 ) ) )
return - V_443 ;
break;
}
case V_464 : {
T_2 * V_465 ;
struct V_466 V_446 ;
if ( ! F_77 ( V_467 ) )
return - V_141 ;
if ( F_214 ( & V_446 , V_442 , sizeof( V_446 ) ) )
return - V_443 ;
V_465 = F_217 ( V_442 + sizeof( V_446 ) , V_446 . V_134 ) ;
if ( F_218 ( V_465 ) )
return F_219 ( V_465 ) ;
V_138 = F_107 ( V_15 , V_465 , V_446 . V_134 ) ;
F_207 ( V_465 ) ;
if ( V_138 )
return V_138 ;
break;
}
case V_468 : {
struct V_469 V_470 ;
int V_58 ;
if ( ! F_80 ( V_15 ) )
return - V_288 ;
if ( ! F_77 ( V_140 ) )
return - V_141 ;
if ( F_220 ( V_15 ) )
return - V_146 ;
if ( F_214 ( & V_470 , V_442 , sizeof( V_470 ) ) )
return - V_443 ;
if ( V_470 . V_471 != V_93 )
return - V_142 ;
if ( V_470 . V_169 [ 0 ] < 81 )
return - V_142 ;
for ( V_58 = 1 ; V_58 < V_93 ; ++ V_58 )
if ( V_470 . V_169 [ V_58 ] < V_470 . V_169 [ V_58 - 1 ] )
return - V_142 ;
memcpy ( V_15 -> V_97 . V_169 , V_470 . V_169 ,
sizeof( V_15 -> V_97 . V_169 ) ) ;
break;
}
case V_472 : {
struct V_473 * V_7 = & V_15 -> V_97 . V_474 ;
struct V_475 V_470 = { . V_363 = V_472 } ;
if ( ! F_80 ( V_15 ) )
return - V_288 ;
V_470 . V_476 = V_7 -> V_477 ;
V_470 . V_478 = V_7 -> V_479 ;
V_470 . V_480 = V_7 -> V_481 ;
V_470 . V_482 = V_7 -> V_483 ;
V_470 . V_484 = V_7 -> V_485 + V_7 -> V_486 * V_7 -> V_487 ;
if ( F_216 ( V_442 , & V_470 , sizeof( V_470 ) ) )
return - V_443 ;
break;
}
case V_488 : {
struct V_475 V_470 ;
struct V_473 * V_7 = & V_15 -> V_97 . V_474 ;
if ( ! F_80 ( V_15 ) )
return - V_288 ;
if ( ! F_77 ( V_140 ) )
return - V_141 ;
if ( V_15 -> V_51 & V_145 )
return - V_146 ;
if ( F_214 ( & V_470 , V_442 , sizeof( V_470 ) ) )
return - V_443 ;
if ( ! F_221 ( V_470 . V_480 ) ||
! F_221 ( V_470 . V_476 ) )
return - V_142 ;
if ( ! ( V_470 . V_480 & 0x14000 ) )
return - V_142 ;
if ( ! ( V_470 . V_476 & 0x1554000 ) )
return - V_142 ;
if ( V_470 . V_478 == - 1 )
V_470 . V_478 = V_7 -> V_479 ;
if ( V_470 . V_482 == - 1 )
V_470 . V_482 = V_7 -> V_483 ;
if ( V_470 . V_478 % 24 || V_470 . V_482 % 24 )
return - V_142 ;
if ( V_470 . V_482 * V_470 . V_480 > V_7 -> V_486 ||
V_470 . V_478 * V_470 . V_476 > V_7 -> V_489 )
return - V_142 ;
V_7 -> V_481 = V_470 . V_480 ;
V_7 -> V_477 = V_470 . V_476 ;
V_7 -> V_483 = V_470 . V_482 ;
V_7 -> V_479 = V_470 . V_478 ;
break;
}
case V_490 : {
struct V_466 V_446 ;
struct V_491 * V_492 ;
T_8 V_133 [ 32 ] ;
if ( ! F_80 ( V_15 ) )
return - V_288 ;
if ( ! ( V_15 -> V_51 & V_145 ) )
return - V_493 ;
if ( F_214 ( & V_446 , V_442 , sizeof( V_446 ) ) )
return - V_443 ;
if ( ( V_446 . V_154 & 7 ) || ( V_446 . V_134 & 7 ) )
return - V_142 ;
if ( V_446 . V_494 == V_495 )
V_492 = & V_15 -> V_496 ;
else if ( V_446 . V_494 == V_497 )
V_492 = & V_15 -> V_498 ;
else if ( V_446 . V_494 == V_499 )
V_492 = & V_15 -> V_500 ;
else
return - V_142 ;
V_446 . V_297 = 3 | ( V_15 -> V_97 . V_130 << 10 ) ;
if ( F_216 ( V_442 , & V_446 , sizeof( V_446 ) ) )
return - V_443 ;
V_442 += sizeof( V_446 ) ;
while ( V_446 . V_134 ) {
unsigned int V_501 =
F_222 (unsigned int, t.len, sizeof(buf)) ;
V_138 =
F_223 ( V_492 , V_446 . V_154 / 8 , V_501 / 8 ,
V_133 ) ;
if ( V_138 )
return V_138 ;
if ( F_216 ( V_442 , V_133 , V_501 ) )
return - V_443 ;
V_442 += V_501 ;
V_446 . V_154 += V_501 ;
V_446 . V_134 -= V_501 ;
}
break;
}
case V_502 : {
struct V_503 V_446 ;
const struct V_504 * V_474 ;
if ( ! F_77 ( V_140 ) )
return - V_141 ;
if ( ! F_220 ( V_15 ) )
return - V_351 ;
if ( F_214 ( & V_446 , V_442 , sizeof( V_446 ) ) )
return - V_443 ;
V_474 = ( const struct V_504 * ) & V_446 . V_505 ;
if ( V_446 . V_506 )
F_224 ( V_15 , V_474 , 0 ,
V_446 . V_507 ,
V_446 . V_508 ) ;
if ( V_446 . V_509 )
F_224 ( V_15 , V_474 , 1 ,
V_446 . V_507 ,
V_446 . V_510 ) ;
break;
}
default:
return - V_288 ;
}
return 0 ;
}
static int F_225 ( struct V_1 * V_2 , struct V_511 * V_84 , int V_363 )
{
struct V_512 * V_195 = F_226 ( V_84 ) ;
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
switch ( V_363 ) {
case V_513 :
case V_514 :
if ( F_18 ( V_15 ) &&
! F_227 ( V_195 -> V_515 ) &&
( V_195 -> V_515 & 0x1f00 ) &&
! ( V_195 -> V_515 & 0xe0e0 ) )
V_195 -> V_515 = F_228 ( V_195 -> V_515 >> 8 ,
V_195 -> V_515 & 0x1f ) ;
case V_516 :
return F_229 ( & V_16 -> V_38 . V_370 , V_195 , V_363 ) ;
case V_517 :
return F_213 ( V_2 , V_84 -> V_518 ) ;
default:
return - V_288 ;
}
}
static int F_230 ( struct V_1 * V_2 , int V_519 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
int V_138 ;
if ( V_519 < 81 )
return - V_142 ;
if ( ( V_138 = F_27 ( & V_16 -> V_18 , V_519 ) ) )
return V_138 ;
V_2 -> V_45 = V_519 ;
F_94 ( V_15 ) ;
if ( V_15 -> V_97 . V_130 == 0 && F_220 ( V_15 ) )
F_135 ( V_15 , V_15 -> V_97 . V_169 ,
V_15 -> V_97 . V_235 , V_15 -> V_97 . V_236 ,
V_15 -> V_28 [ 0 ] -> V_45 ) ;
return 0 ;
}
static int F_231 ( struct V_1 * V_2 , void * V_7 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
struct V_520 * V_154 = V_7 ;
if ( ! F_232 ( V_154 -> V_521 ) )
return - V_142 ;
memcpy ( V_2 -> V_47 , V_154 -> V_521 , V_2 -> V_522 ) ;
F_28 ( & V_16 -> V_18 , V_46 , V_2 -> V_47 ) ;
if ( F_220 ( V_15 ) )
F_92 ( V_15 , V_16 -> V_26 ) ;
return 0 ;
}
static void F_233 ( struct V_15 * V_25 , const struct V_6 * V_7 )
{
int V_58 ;
for ( V_58 = V_7 -> V_66 ; V_58 < V_7 -> V_66 + V_7 -> V_65 ; V_58 ++ ) {
struct V_523 * V_404 = & V_25 -> V_70 . V_71 [ V_58 ] . V_72 ;
F_126 ( & V_404 -> V_524 ) ;
F_127 ( & V_404 -> V_524 ) ;
}
}
static void F_234 ( struct V_1 * V_2 , T_6 V_456 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
if ( V_15 -> V_97 . V_130 > 0 ) {
F_235 ( V_15 , 1 << V_16 -> V_26 ,
V_456 & V_525 ) ;
} else {
unsigned int V_58 , V_526 = V_456 & V_525 ;
F_35 (adapter, i)
V_526 |=
V_15 -> V_28 [ V_58 ] -> V_456 & V_525 ;
F_235 ( V_15 , 1 , V_526 ) ;
}
F_233 ( V_15 , V_16 ) ;
}
static T_6 F_236 ( struct V_1 * V_2 , T_6 V_456 )
{
if ( V_456 & V_525 )
V_456 |= V_527 ;
else
V_456 &= ~ V_527 ;
return V_456 ;
}
static int F_237 ( struct V_1 * V_2 , T_6 V_456 )
{
T_6 V_528 = V_2 -> V_456 ^ V_456 ;
if ( V_528 & V_525 )
F_234 ( V_2 , V_456 ) ;
return 0 ;
}
static void F_238 ( struct V_1 * V_2 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
struct V_15 * V_15 = V_16 -> V_15 ;
int V_68 ;
for ( V_68 = V_16 -> V_66 ; V_68 < V_16 -> V_66 + V_16 -> V_65 ; V_68 ++ ) {
struct V_117 * V_71 = & V_15 -> V_70 . V_71 [ V_68 ] ;
void * V_529 ;
if ( V_15 -> V_51 & V_52 )
V_529 = V_71 ;
else
V_529 = V_15 ;
F_39 ( V_15 , V_71 -> V_72 . V_73 ) ( 0 , V_529 ) ;
}
}
static void F_239 ( struct V_15 * V_15 )
{
int V_58 ;
F_35 (adapter, i) {
struct V_1 * V_2 = V_15 -> V_28 [ V_58 ] ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
if ( F_17 ( V_2 ) ) {
F_162 ( & V_15 -> V_252 ) ;
F_163 ( & V_7 -> V_18 ) ;
F_164 ( & V_15 -> V_252 ) ;
}
}
}
static void F_240 ( struct V_15 * V_15 )
{
int V_58 ;
F_35 (adapter, i) {
struct V_1 * V_2 = V_15 -> V_28 [ V_58 ] ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_530 ;
F_126 ( & V_15 -> V_223 ) ;
V_530 = V_7 -> V_530 ;
F_127 ( & V_15 -> V_223 ) ;
if ( V_530 ) {
F_241 ( V_15 , V_58 ) ;
continue;
}
if ( ! ( V_7 -> V_38 . V_531 & V_532 ) && F_17 ( V_2 ) ) {
F_11 ( V_15 , V_58 ) ;
F_12 ( V_15 , V_30 + V_7 -> V_18 . V_19 ) ;
F_242 ( V_15 , V_58 ) ;
F_13 ( V_15 , V_58 ) ;
}
}
}
static void F_243 ( struct V_15 * V_15 )
{
int V_58 ;
if ( ! F_244 () )
return;
F_35 (adapter, i) {
struct V_1 * V_2 = V_15 -> V_28 [ V_58 ] ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_533 ;
if ( ! F_17 ( V_2 ) )
continue;
V_533 = 0 ;
if ( F_17 ( V_2 ) && F_2 ( V_2 ) )
V_533 = F_245 ( & V_7 -> V_18 ) ;
if ( V_533 == 1 )
V_7 -> V_18 . V_305 . V_332 ++ ;
else if ( V_533 == 2 ) {
struct V_29 * V_18 = & V_7 -> V_18 ;
F_27 ( V_18 , V_2 -> V_45 ) ;
F_28 ( V_18 , V_46 , V_2 -> V_47 ) ;
F_22 ( V_2 ) ;
F_20 ( & V_7 -> V_38 , V_18 , & V_7 -> V_8 ) ;
F_14 ( V_18 , V_37 | V_34 ) ;
F_153 ( V_15 , V_7 -> V_26 ) ;
V_7 -> V_18 . V_305 . V_333 ++ ;
}
}
F_74 () ;
}
static void F_246 ( struct V_534 * V_535 )
{
struct V_15 * V_15 = F_247 ( V_535 , struct V_15 ,
V_229 . V_535 ) ;
const struct V_536 * V_7 = & V_15 -> V_97 ;
int V_28 ;
unsigned int V_153 , V_533 , V_537 ;
V_15 -> V_538 ++ ;
F_240 ( V_15 ) ;
if ( ! V_7 -> V_226 ||
( V_15 -> V_538 * V_7 -> V_226 ) / 10 >=
V_7 -> V_228 ) {
F_239 ( V_15 ) ;
V_15 -> V_538 = 0 ;
}
if ( V_7 -> V_130 == V_201 )
F_243 ( V_15 ) ;
F_35 (adapter, port) {
struct V_29 * V_18 = & F_37 ( V_15 , V_28 ) -> V_18 ;
T_6 V_539 ;
V_539 = F_12 ( V_15 , V_31 + V_18 -> V_19 ) ;
V_537 = 0 ;
if ( V_539 & V_540 ) {
V_18 -> V_305 . V_271 ++ ;
V_537 |= V_540 ;
}
F_7 ( V_15 , V_31 + V_18 -> V_19 , V_537 ) ;
}
V_533 = F_12 ( V_15 , V_541 ) ;
V_537 = 0 ;
if ( V_533 & V_542 ) {
struct V_117 * V_71 = & V_15 -> V_70 . V_71 [ 0 ] ;
int V_58 = 0 ;
V_537 |= V_542 ;
V_153 = ( F_12 ( V_15 , V_543 ) >> V_544 ) &
0xffff ;
while ( V_153 ) {
V_71 -> V_545 [ V_58 ] . V_546 += ( V_153 & 1 ) ;
if ( V_58 )
V_71 ++ ;
V_58 ^= 1 ;
V_153 >>= 1 ;
}
}
F_7 ( V_15 , V_541 , V_537 ) ;
F_126 ( & V_15 -> V_223 ) ;
if ( V_15 -> V_231 & V_232 )
F_129 ( V_15 ) ;
F_127 ( & V_15 -> V_223 ) ;
}
static void F_248 ( struct V_534 * V_535 )
{
struct V_15 * V_15 = F_247 ( V_535 , struct V_15 ,
F_248 ) ;
F_155 ( & V_15 -> V_163 , V_547 , 0 ) ;
}
static void F_249 ( struct V_534 * V_535 )
{
struct V_15 * V_15 = F_247 ( V_535 , struct V_15 ,
F_249 ) ;
F_155 ( & V_15 -> V_163 , V_548 , 0 ) ;
}
static void F_250 ( struct V_534 * V_535 )
{
struct V_15 * V_15 = F_247 ( V_535 , struct V_15 ,
F_250 ) ;
unsigned long V_549 = 1000 ;
unsigned short V_550 ;
F_155 ( & V_15 -> V_163 , V_551 , 0 ) ;
F_251 ( & V_550 , 2 ) ;
V_549 += V_550 & 1023 ;
F_252 ( V_552 ) ;
F_253 ( F_254 ( V_549 ) ) ;
F_58 ( V_15 ) ;
}
static void F_255 ( struct V_534 * V_535 )
{
struct V_15 * V_15 = F_247 ( V_535 , struct V_15 ,
V_553 ) ;
int V_58 ;
F_35 (adapter, i) {
struct V_1 * V_2 = V_15 -> V_28 [ V_58 ] ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_11 ( V_15 , V_58 ) ;
F_12 ( V_15 , V_30 + V_7 -> V_18 . V_19 ) ;
}
F_256 ( V_15 ) ;
F_35 (adapter, i)
F_13 ( V_15 , V_58 ) ;
F_126 ( & V_15 -> V_223 ) ;
if ( V_15 -> V_554 ) {
V_15 -> V_554 |= V_555 ;
F_7 ( V_15 , V_556 , V_555 ) ;
F_7 ( V_15 , V_557 ,
V_15 -> V_554 ) ;
}
F_127 ( & V_15 -> V_223 ) ;
}
void F_257 ( struct V_15 * V_15 )
{
F_162 ( & V_15 -> V_223 ) ;
if ( V_15 -> V_554 ) {
V_15 -> V_554 &= ~ V_555 ;
F_7 ( V_15 , V_557 ,
V_15 -> V_554 ) ;
F_258 ( V_224 , & V_15 -> V_553 ) ;
}
F_164 ( & V_15 -> V_223 ) ;
}
void F_259 ( struct V_15 * V_15 , int V_26 )
{
struct V_1 * V_123 = V_15 -> V_28 [ V_26 ] ;
struct V_6 * V_16 = F_4 ( V_123 ) ;
F_162 ( & V_15 -> V_223 ) ;
V_16 -> V_530 = 1 ;
F_164 ( & V_15 -> V_223 ) ;
}
static int F_260 ( struct V_15 * V_15 , int V_537 , int V_222 )
{
int V_58 , V_138 = 0 ;
if ( F_80 ( V_15 ) &&
F_144 ( V_233 , & V_15 -> V_231 ) ) {
F_155 ( & V_15 -> V_163 , V_558 , 0 ) ;
F_141 ( & V_15 -> V_163 ) ;
}
F_35 (adapter, i) {
struct V_1 * V_123 = V_15 -> V_28 [ V_58 ] ;
if ( F_17 ( V_123 ) )
F_156 ( V_123 , V_222 ) ;
}
F_261 ( V_15 ) ;
V_15 -> V_51 &= ~ V_145 ;
if ( V_537 )
V_138 = F_262 ( V_15 ) ;
F_263 ( V_15 -> V_53 ) ;
return V_138 ;
}
static int F_264 ( struct V_15 * V_15 )
{
if ( F_265 ( V_15 -> V_53 ) ) {
F_101 ( & V_15 -> V_53 -> V_2 ,
L_42 ) ;
goto V_67;
}
F_266 ( V_15 -> V_53 ) ;
F_267 ( V_15 -> V_53 ) ;
F_268 ( V_15 -> V_53 ) ;
F_69 ( V_15 ) ;
if ( F_269 ( V_15 ) )
goto V_67;
return 0 ;
V_67:
return - 1 ;
}
static void F_270 ( struct V_15 * V_15 )
{
int V_58 ;
F_35 (adapter, i) {
struct V_1 * V_123 = V_15 -> V_28 [ V_58 ] ;
if ( F_17 ( V_123 ) ) {
if ( F_149 ( V_123 ) ) {
F_101 ( & V_15 -> V_53 -> V_2 ,
L_43
L_44 ) ;
continue;
}
}
}
if ( F_80 ( V_15 ) && ! V_243 )
F_155 ( & V_15 -> V_163 , V_559 , 0 ) ;
}
static void F_271 ( struct V_534 * V_535 )
{
struct V_15 * V_15 = F_247 ( V_535 , struct V_15 ,
V_560 ) ;
int V_67 = 0 ;
F_72 () ;
V_67 = F_260 ( V_15 , 1 , 1 ) ;
if ( ! V_67 )
V_67 = F_264 ( V_15 ) ;
if ( ! V_67 )
F_270 ( V_15 ) ;
F_272 ( V_15 , L_45 , V_67 ? L_31 : L_32 ) ;
F_74 () ;
}
void F_273 ( struct V_15 * V_15 )
{
unsigned int V_561 [ 4 ] ;
if ( V_15 -> V_51 & V_145 ) {
F_125 ( V_15 ) ;
F_7 ( V_15 , V_22 , 0 ) ;
F_7 ( V_15 , V_21 , 0 ) ;
F_7 ( V_15 , F_188 ( V_22 , 1 ) , 0 ) ;
F_7 ( V_15 , F_188 ( V_21 , 1 ) , 0 ) ;
F_162 ( & V_15 -> V_223 ) ;
F_123 ( V_15 ) ;
F_258 ( V_224 , & V_15 -> V_560 ) ;
F_164 ( & V_15 -> V_223 ) ;
}
F_272 ( V_15 , L_46 ) ;
if ( ! F_274 ( V_15 , 0xa0 , 4 , V_561 ) )
F_272 ( V_15 , L_47 ,
V_561 [ 0 ] , V_561 [ 1 ] ,
V_561 [ 2 ] , V_561 [ 3 ] ) ;
}
static T_10 F_275 ( struct V_562 * V_53 ,
T_11 V_27 )
{
struct V_15 * V_15 = F_276 ( V_53 ) ;
if ( V_27 == V_563 )
return V_564 ;
F_260 ( V_15 , 0 , 0 ) ;
return V_565 ;
}
static T_10 F_277 ( struct V_562 * V_53 )
{
struct V_15 * V_15 = F_276 ( V_53 ) ;
if ( ! F_264 ( V_15 ) )
return V_566 ;
return V_564 ;
}
static void F_278 ( struct V_562 * V_53 )
{
struct V_15 * V_15 = F_276 ( V_53 ) ;
F_272 ( V_15 , L_48 ,
F_12 ( V_15 , V_567 ) ) ;
F_270 ( V_15 ) ;
}
static void F_279 ( struct V_15 * V_25 )
{
int V_58 , V_59 = 0 ;
int V_568 = F_280 () ;
int V_569 = V_25 -> V_97 . V_423 ;
int V_65 = V_25 -> V_570 - 1 ;
if ( V_25 -> V_97 . V_130 > 0 && V_25 -> V_51 & V_52 ) {
if ( V_569 == 2 &&
( V_569 * V_65 > V_107 ||
V_568 >= V_65 / V_569 ) )
V_65 /= V_569 ;
if ( V_65 > V_568 )
V_65 = V_568 ;
if ( V_65 < 1 || V_569 == 4 )
V_65 = 1 ;
} else
V_65 = 1 ;
F_35 (adap, i) {
struct V_6 * V_16 = F_37 ( V_25 , V_58 ) ;
V_16 -> V_66 = V_59 ;
V_16 -> V_65 = V_65 ;
V_59 = V_16 -> V_66 + V_65 ;
F_108 ( & V_25 -> V_53 -> V_2 ,
L_49 , V_58 , V_65 ) ;
}
}
static int T_12 F_281 ( struct V_15 * V_25 )
{
struct V_571 V_572 [ V_107 + 1 ] ;
int V_573 ;
int V_58 , V_67 ;
V_573 = F_168 ( V_572 ) ;
for ( V_58 = 0 ; V_58 < V_573 ; ++ V_58 )
V_572 [ V_58 ] . V_574 = V_58 ;
while ( ( V_67 = F_282 ( V_25 -> V_53 , V_572 , V_573 ) ) > 0 )
V_573 = V_67 ;
if ( V_67 < 0 )
F_30 ( V_25 -> V_53 ) ;
if ( ! V_67 && V_573 < ( V_25 -> V_97 . V_423 + 1 ) ) {
F_30 ( V_25 -> V_53 ) ;
V_67 = - 1 ;
}
if ( ! V_67 ) {
for ( V_58 = 0 ; V_58 < V_573 ; ++ V_58 )
V_25 -> V_62 [ V_58 ] . V_69 = V_572 [ V_58 ] . V_458 ;
V_25 -> V_570 = V_573 ;
}
return V_67 ;
}
static void T_12 F_283 ( struct V_15 * V_25 ,
const struct V_575 * V_576 )
{
static const char * V_577 [] = {
L_50 , L_51 , L_52 , L_53 , L_54
} ;
int V_58 ;
char V_133 [ 80 ] ;
if ( F_187 ( V_25 ) )
snprintf ( V_133 , sizeof( V_133 ) , L_55 ,
V_577 [ V_25 -> V_97 . V_578 . V_579 ] ,
V_25 -> V_97 . V_578 . V_580 ) ;
else
snprintf ( V_133 , sizeof( V_133 ) , L_56 ,
V_577 [ V_25 -> V_97 . V_578 . V_579 ] ,
V_25 -> V_97 . V_578 . V_9 , V_25 -> V_97 . V_578 . V_580 ) ;
F_35 (adap, i) {
struct V_1 * V_2 = V_25 -> V_28 [ V_58 ] ;
const struct V_6 * V_16 = F_4 ( V_2 ) ;
if ( ! F_144 ( V_58 , & V_25 -> V_581 ) )
continue;
F_3 ( V_3 L_57 ,
V_2 -> V_4 , V_576 -> V_63 , V_16 -> V_38 . V_63 ,
F_80 ( V_25 ) ? L_58 : L_59 , V_25 -> V_97 . V_130 , V_133 ,
( V_25 -> V_51 & V_52 ) ? L_60 :
( V_25 -> V_51 & V_54 ) ? L_61 : L_59 ) ;
if ( V_25 -> V_4 == V_2 -> V_4 && V_25 -> V_97 . V_160 . V_582 )
F_3 ( V_3
L_62 ,
V_25 -> V_4 , F_284 ( & V_25 -> V_496 ) >> 20 ,
F_284 ( & V_25 -> V_500 ) >> 20 ,
F_284 ( & V_25 -> V_498 ) >> 20 ,
V_25 -> V_97 . V_160 . V_583 ) ;
}
}
static void T_12 F_285 ( struct V_1 * V_2 )
{
struct V_6 * V_16 = F_4 ( V_2 ) ;
memcpy ( V_16 -> V_49 . V_50 , V_2 -> V_47 , V_166 ) ;
V_16 -> V_49 . V_50 [ 3 ] |= 0x80 ;
}
static int T_12 F_286 ( struct V_562 * V_53 ,
const struct V_584 * V_585 )
{
static int V_586 ;
int V_58 , V_67 , V_587 = 0 ;
T_13 V_588 , V_589 ;
const struct V_575 * V_576 ;
struct V_15 * V_15 = NULL ;
struct V_6 * V_16 ;
if ( ! V_586 ) {
F_3 ( V_3 L_63 , V_590 , V_298 ) ;
++ V_586 ;
}
if ( ! V_224 ) {
V_224 = F_287 ( V_296 ) ;
if ( ! V_224 ) {
F_3 (KERN_ERR DRV_NAME
L_64 ) ;
return - V_103 ;
}
}
V_67 = F_265 ( V_53 ) ;
if ( V_67 ) {
F_101 ( & V_53 -> V_2 , L_65 ) ;
goto V_209;
}
V_67 = F_288 ( V_53 , V_296 ) ;
if ( V_67 ) {
F_108 ( & V_53 -> V_2 , L_66 ) ;
goto V_591;
}
if ( ! F_289 ( V_53 , F_290 ( 64 ) ) ) {
V_587 = 1 ;
V_67 = F_291 ( V_53 , F_290 ( 64 ) ) ;
if ( V_67 ) {
F_101 ( & V_53 -> V_2 , L_67
L_68 ) ;
goto V_592;
}
} else if ( ( V_67 = F_289 ( V_53 , F_290 ( 32 ) ) ) != 0 ) {
F_101 ( & V_53 -> V_2 , L_69 ) ;
goto V_592;
}
F_266 ( V_53 ) ;
F_268 ( V_53 ) ;
V_588 = F_292 ( V_53 , 0 ) ;
V_589 = F_293 ( V_53 , 0 ) ;
V_576 = F_294 ( V_585 -> V_593 ) ;
V_15 = F_295 ( sizeof( * V_15 ) , V_85 ) ;
if ( ! V_15 ) {
V_67 = - V_103 ;
goto V_592;
}
V_15 -> V_86 =
F_46 ( sizeof( struct V_80 ) , V_85 ) ;
if ( ! V_15 -> V_86 ) {
F_101 ( & V_53 -> V_2 , L_70 ) ;
V_67 = - V_103 ;
goto V_594;
}
V_15 -> V_339 = F_296 ( V_588 , V_589 ) ;
if ( ! V_15 -> V_339 ) {
F_101 ( & V_53 -> V_2 , L_71 ) ;
V_67 = - V_103 ;
goto V_594;
}
V_15 -> V_53 = V_53 ;
V_15 -> V_4 = F_174 ( V_53 ) ;
V_15 -> V_284 = V_595 ;
V_15 -> V_589 = V_589 ;
F_297 ( & V_15 -> V_596 ) ;
F_298 ( & V_15 -> V_223 ) ;
F_298 ( & V_15 -> V_252 ) ;
F_299 ( & V_15 -> V_597 ) ;
F_300 ( & V_15 -> V_553 , F_255 ) ;
F_300 ( & V_15 -> V_560 , F_271 ) ;
F_300 ( & V_15 -> F_248 , F_248 ) ;
F_300 ( & V_15 -> F_249 , F_249 ) ;
F_300 ( & V_15 -> F_250 , F_250 ) ;
F_301 ( & V_15 -> V_229 , F_246 ) ;
for ( V_58 = 0 ; V_58 < V_576 -> V_598 + V_576 -> V_599 ; ++ V_58 ) {
struct V_1 * V_123 ;
V_123 = F_302 ( sizeof( struct V_6 ) , V_107 ) ;
if ( ! V_123 ) {
V_67 = - V_103 ;
goto V_600;
}
F_303 ( V_123 , & V_53 -> V_2 ) ;
V_15 -> V_28 [ V_58 ] = V_123 ;
V_16 = F_4 ( V_123 ) ;
V_16 -> V_15 = V_15 ;
V_16 -> V_26 = V_58 ;
F_15 ( V_123 ) ;
V_123 -> V_55 = V_53 -> V_55 ;
V_123 -> V_601 = V_588 ;
V_123 -> V_602 = V_588 + V_589 - 1 ;
V_123 -> V_603 = V_604 | V_605 |
V_606 | V_607 | V_525 ;
V_123 -> V_456 |= V_123 -> V_603 | V_527 ;
if ( V_587 )
V_123 -> V_456 |= V_608 ;
V_123 -> V_609 = & V_610 ;
F_304 ( V_123 , & V_611 ) ;
}
F_305 ( V_53 , V_15 ) ;
if ( F_306 ( V_15 , V_576 , 1 ) < 0 ) {
V_67 = - V_612 ;
goto V_600;
}
F_35 (adapter, i) {
V_67 = F_307 ( V_15 -> V_28 [ V_58 ] ) ;
if ( V_67 )
F_308 ( & V_53 -> V_2 ,
L_72 ,
V_15 -> V_28 [ V_58 ] -> V_4 ) ;
else {
if ( ! V_15 -> V_581 )
V_15 -> V_4 = V_15 -> V_28 [ V_58 ] -> V_4 ;
F_309 ( V_58 , & V_15 -> V_581 ) ;
}
}
if ( ! V_15 -> V_581 ) {
F_101 ( & V_53 -> V_2 , L_73 ) ;
goto V_600;
}
F_35 (adapter, i)
F_285 ( V_15 -> V_28 [ V_58 ] ) ;
F_310 ( V_15 ) ;
if ( F_80 ( V_15 ) ) {
F_309 ( V_233 , & V_15 -> V_581 ) ;
F_311 ( V_15 ) ;
}
if ( V_613 > 1 && F_281 ( V_15 ) == 0 )
V_15 -> V_51 |= V_52 ;
else if ( V_613 > 0 && F_312 ( V_53 ) == 0 )
V_15 -> V_51 |= V_54 ;
F_279 ( V_15 ) ;
V_67 = F_136 ( & V_15 -> V_28 [ 0 ] -> V_2 . V_237 ,
& V_614 ) ;
F_35 (adapter, i)
F_234 ( V_15 -> V_28 [ V_58 ] , V_15 -> V_28 [ V_58 ] -> V_456 ) ;
F_283 ( V_15 , V_576 ) ;
return 0 ;
V_600:
F_313 ( V_15 -> V_339 ) ;
for ( V_58 = V_576 -> V_598 + V_576 -> V_599 - 1 ; V_58 >= 0 ; -- V_58 )
if ( V_15 -> V_28 [ V_58 ] )
F_314 ( V_15 -> V_28 [ V_58 ] ) ;
V_594:
F_207 ( V_15 ) ;
V_592:
F_315 ( V_53 ) ;
V_591:
F_263 ( V_53 ) ;
F_305 ( V_53 , NULL ) ;
V_209:
return V_67 ;
}
static void T_14 F_316 ( struct V_562 * V_53 )
{
struct V_15 * V_15 = F_276 ( V_53 ) ;
if ( V_15 ) {
int V_58 ;
F_125 ( V_15 ) ;
F_146 ( & V_15 -> V_28 [ 0 ] -> V_2 . V_237 ,
& V_614 ) ;
if ( F_80 ( V_15 ) ) {
F_317 ( V_15 ) ;
if ( F_144 ( V_233 ,
& V_15 -> V_231 ) )
F_141 ( & V_15 -> V_163 ) ;
}
F_35 (adapter, i)
if ( F_144 ( V_58 , & V_15 -> V_581 ) )
F_318 ( V_15 -> V_28 [ V_58 ] ) ;
F_261 ( V_15 ) ;
F_69 ( V_15 ) ;
F_29 ( V_15 ) ;
F_35 (adapter, i)
if ( V_15 -> V_28 [ V_58 ] )
F_314 ( V_15 -> V_28 [ V_58 ] ) ;
F_313 ( V_15 -> V_339 ) ;
if ( V_15 -> V_86 )
F_319 ( V_15 -> V_86 ) ;
F_207 ( V_15 ) ;
F_315 ( V_53 ) ;
F_263 ( V_53 ) ;
F_305 ( V_53 , NULL ) ;
}
}
static int T_15 F_320 ( void )
{
int V_138 ;
F_321 () ;
V_138 = F_322 ( & V_295 ) ;
return V_138 ;
}
static void T_16 F_323 ( void )
{
F_324 ( & V_295 ) ;
if ( V_224 )
F_325 ( V_224 ) ;
}
