unsigned long F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 = V_5 ;
int V_6 = 0 ;
if ( V_3 < V_7 )
V_4 = V_8 [ V_3 ] ;
if ( V_4 != V_5 )
V_6 = V_2 -> V_6 [ V_4 ] ;
if ( V_6 <= 0 )
return 2 * 60 * V_9 ;
else
return V_6 ;
}
T_2 F_2 ( struct V_1 * V_2 , const T_3 * V_10 , T_4 V_11 ,
unsigned int V_12 )
{
T_2 V_13 ;
T_1 V_14 , V_3 ;
unsigned long V_15 ;
if ( V_11 < V_16 )
return - V_17 ;
if ( V_11 > V_18 )
V_11 = V_18 ;
V_14 = F_3 ( * ( ( V_19 * ) ( V_10 + 2 ) ) ) ;
V_3 = F_3 ( * ( ( V_19 * ) ( V_10 + 6 ) ) ) ;
if ( V_14 == 0 )
return - V_20 ;
if ( V_14 > V_11 ) {
F_4 ( & V_2 -> V_21 ,
L_1 , V_14 , V_11 ) ;
return - V_22 ;
}
if ( ! ( V_12 & V_23 ) )
F_5 ( & V_2 -> V_24 ) ;
if ( V_2 -> V_21 . V_25 )
F_6 ( V_2 -> V_21 . V_25 ) ;
V_13 = V_2 -> V_26 -> V_27 ( V_2 , ( T_3 * ) V_10 , V_14 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_21 ,
L_2 , V_13 ) ;
goto V_28;
}
if ( V_2 -> V_12 & V_29 )
goto V_30;
if ( V_2 -> V_12 & V_31 )
V_15 = V_32 + F_7 ( V_2 , V_3 ) ;
else
V_15 = V_32 + F_1 ( V_2 , V_3 ) ;
do {
T_3 V_33 = V_2 -> V_26 -> V_33 ( V_2 ) ;
if ( ( V_33 & V_2 -> V_26 -> V_34 ) ==
V_2 -> V_26 -> V_35 )
goto V_30;
if ( V_2 -> V_26 -> V_36 ( V_2 , V_33 ) ) {
F_4 ( & V_2 -> V_21 , L_3 ) ;
V_13 = - V_37 ;
goto V_28;
}
F_8 ( V_38 ) ;
F_9 () ;
} while ( F_10 ( V_32 , V_15 ) );
V_2 -> V_26 -> V_39 ( V_2 ) ;
F_4 ( & V_2 -> V_21 , L_4 ) ;
V_13 = - V_40 ;
goto V_28;
V_30:
V_13 = V_2 -> V_26 -> V_41 ( V_2 , ( T_3 * ) V_10 , V_11 ) ;
if ( V_13 < 0 )
F_4 ( & V_2 -> V_21 ,
L_5 , V_13 ) ;
V_28:
if ( V_2 -> V_21 . V_25 )
F_11 ( V_2 -> V_21 . V_25 ) ;
if ( ! ( V_12 & V_23 ) )
F_12 ( & V_2 -> V_24 ) ;
return V_13 ;
}
T_2 F_13 ( struct V_1 * V_2 , const void * V_42 ,
int V_43 , unsigned int V_12 , const char * V_44 )
{
const struct V_45 * V_46 ;
int V_47 ;
V_43 = F_2 ( V_2 , ( const T_3 * ) V_42 , V_43 , V_12 ) ;
if ( V_43 < 0 )
return V_43 ;
else if ( V_43 < V_16 )
return - V_48 ;
V_46 = V_42 ;
V_47 = F_3 ( V_46 -> V_49 ) ;
if ( V_47 != 0 && V_44 )
F_4 ( & V_2 -> V_21 , L_6 , V_47 ,
V_44 ) ;
return V_47 ;
}
T_2 F_14 ( struct V_1 * V_2 , T_1 V_50 , T_5 * V_51 ,
const char * V_44 )
{
struct V_52 V_53 ;
int V_13 ;
V_53 . V_46 . V_54 = V_55 ;
if ( V_50 == V_56 ||
V_50 == V_57 ) {
V_53 . V_58 . V_59 . V_51 = F_15 ( V_50 ) ;
V_53 . V_58 . V_59 . V_60 = F_15 ( 0 ) ;
V_53 . V_46 . V_54 . V_61 -= F_15 ( sizeof( V_19 ) ) ;
} else {
if ( V_50 == V_62 ||
V_50 == V_63 )
V_53 . V_58 . V_59 . V_51 =
F_15 ( V_64 ) ;
else
V_53 . V_58 . V_59 . V_51 =
F_15 ( V_65 ) ;
V_53 . V_58 . V_59 . V_60 = F_15 ( 4 ) ;
V_53 . V_58 . V_59 . V_66 = F_15 ( V_50 ) ;
}
V_13 = F_13 ( V_2 , & V_53 , V_67 , 0 ,
V_44 ) ;
if ( ! V_13 )
* V_51 = V_53 . V_58 . V_68 . V_51 ;
return V_13 ;
}
static int F_16 ( struct V_1 * V_2 , T_6 V_69 )
{
struct V_52 V_70 ;
V_70 . V_46 . V_54 = V_71 ;
V_70 . V_58 . V_72 . V_69 = V_69 ;
return F_13 ( V_2 , & V_70 , V_67 , 0 ,
L_7 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
T_5 V_51 ;
unsigned long V_73 [ 4 ] ;
unsigned long V_74 [ 4 ] ;
T_2 V_13 ;
if ( V_2 -> V_12 & V_75 )
return 0 ;
if ( V_2 -> V_12 & V_31 ) {
V_2 -> V_76 = F_18 ( V_77 ) ;
V_2 -> V_78 = F_18 ( V_79 ) ;
V_2 -> V_80 = F_18 ( V_81 ) ;
V_2 -> V_82 = F_18 ( V_83 ) ;
V_2 -> V_6 [ V_84 ] =
F_18 ( V_85 ) ;
V_2 -> V_6 [ V_86 ] =
F_18 ( V_87 ) ;
V_2 -> V_6 [ V_88 ] =
F_18 ( V_89 ) ;
V_2 -> V_12 |= V_75 ;
return 0 ;
}
V_13 = F_14 ( V_2 , V_90 , & V_51 ,
L_8 ) ;
if ( V_13 == V_91 ) {
F_19 ( & V_2 -> V_21 , L_9 ) ;
if ( F_16 ( V_2 , V_92 ) )
return V_13 ;
V_13 = F_14 ( V_2 , V_90 , & V_51 ,
L_8 ) ;
}
if ( V_13 )
return V_13 ;
V_74 [ 0 ] = F_3 ( V_51 . V_93 . V_94 ) ;
V_74 [ 1 ] = F_3 ( V_51 . V_93 . V_95 ) ;
V_74 [ 2 ] = F_3 ( V_51 . V_93 . V_96 ) ;
V_74 [ 3 ] = F_3 ( V_51 . V_93 . V_97 ) ;
memcpy ( V_73 , V_74 , sizeof( V_73 ) ) ;
if ( V_2 -> V_26 -> V_98 != NULL )
V_2 -> V_99 =
V_2 -> V_26 -> V_98 ( V_2 , V_73 ) ;
if ( ! V_2 -> V_99 ) {
if ( V_73 [ 0 ] != 0 && V_73 [ 0 ] < 1000 ) {
int V_100 ;
for ( V_100 = 0 ; V_100 != F_20 ( V_73 ) ; V_100 ++ )
V_73 [ V_100 ] *= 1000 ;
V_2 -> V_99 = true ;
}
}
if ( V_2 -> V_99 ) {
F_19 ( & V_2 -> V_21 ,
V_101 L_10 ,
V_74 [ 0 ] , V_73 [ 0 ] ,
V_74 [ 1 ] , V_73 [ 1 ] ,
V_74 [ 2 ] , V_73 [ 2 ] ,
V_74 [ 3 ] , V_73 [ 3 ] ) ;
}
V_2 -> V_76 = F_21 ( V_73 [ 0 ] ) ;
V_2 -> V_78 = F_21 ( V_73 [ 1 ] ) ;
V_2 -> V_80 = F_21 ( V_73 [ 2 ] ) ;
V_2 -> V_82 = F_21 ( V_73 [ 3 ] ) ;
V_13 = F_14 ( V_2 , V_102 , & V_51 ,
L_11 ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_6 [ V_84 ] =
F_21 ( F_3 ( V_51 . V_6 . V_103 ) ) ;
V_2 -> V_6 [ V_86 ] =
F_21 ( F_3 ( V_51 . V_6 . V_104 ) ) ;
V_2 -> V_6 [ V_88 ] =
F_21 ( F_3 ( V_51 . V_6 . V_105 ) ) ;
if ( V_2 -> V_6 [ V_84 ] < ( V_9 / 100 ) ) {
V_2 -> V_6 [ V_84 ] = V_9 ;
V_2 -> V_6 [ V_86 ] *= 1000 ;
V_2 -> V_6 [ V_88 ] *= 1000 ;
V_2 -> V_106 = true ;
F_19 ( & V_2 -> V_21 , L_12 ) ;
}
V_2 -> V_12 |= V_75 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_52 V_42 ;
V_42 . V_46 . V_54 = V_107 ;
V_13 = F_13 ( V_2 , & V_42 , V_108 , 0 ,
L_13 ) ;
return V_13 ;
}
int F_23 ( struct V_1 * V_2 , int V_109 , T_3 * V_110 )
{
int V_13 ;
struct V_52 V_42 ;
V_42 . V_46 . V_54 = V_111 ;
V_42 . V_58 . V_112 . V_109 = F_15 ( V_109 ) ;
V_13 = F_13 ( V_2 , & V_42 , V_113 , 0 ,
L_14 ) ;
if ( V_13 == 0 )
memcpy ( V_110 , V_42 . V_58 . V_114 . V_115 ,
V_116 ) ;
return V_13 ;
}
int F_24 ( T_1 V_117 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_25 ( V_117 ) ;
if ( V_2 == NULL )
return - V_118 ;
V_13 = ( V_2 -> V_12 & V_31 ) != 0 ;
F_26 ( V_2 ) ;
return V_13 ;
}
int F_27 ( T_1 V_117 , int V_109 , T_3 * V_110 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_25 ( V_117 ) ;
if ( V_2 == NULL )
return - V_118 ;
if ( V_2 -> V_12 & V_31 )
V_13 = F_28 ( V_2 , V_109 , V_110 ) ;
else
V_13 = F_23 ( V_2 , V_109 , V_110 ) ;
F_26 ( V_2 ) ;
return V_13 ;
}
int F_29 ( T_1 V_117 , int V_109 , const T_3 * V_119 )
{
struct V_52 V_42 ;
int V_13 ;
struct V_1 * V_2 ;
V_2 = F_25 ( V_117 ) ;
if ( V_2 == NULL )
return - V_118 ;
if ( V_2 -> V_12 & V_31 ) {
V_13 = F_30 ( V_2 , V_109 , V_119 ) ;
F_26 ( V_2 ) ;
return V_13 ;
}
V_42 . V_46 . V_54 = V_120 ;
V_42 . V_58 . V_121 . V_109 = F_15 ( V_109 ) ;
memcpy ( V_42 . V_58 . V_121 . V_119 , V_119 , V_116 ) ;
V_13 = F_13 ( V_2 , & V_42 , V_122 , 0 ,
L_15 ) ;
F_26 ( V_2 ) ;
return V_13 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_13 ;
unsigned int V_123 ;
unsigned int V_124 = 100 ;
unsigned long V_6 ;
T_3 V_125 [ V_116 ] ;
V_6 = F_1 ( V_2 , V_126 ) ;
V_123 = F_32 ( V_6 ) / V_124 ;
V_13 = F_22 ( V_2 ) ;
if ( V_13 )
return V_13 ;
do {
V_13 = F_23 ( V_2 , 0 , V_125 ) ;
if ( V_13 == - V_40 ) {
F_19 (
& V_2 -> V_21 , V_101
L_16 ) ;
F_8 ( V_124 ) ;
continue;
}
if ( V_13 == V_127 || V_13 == V_128 ) {
F_19 ( & V_2 -> V_21 ,
L_17 , V_13 ) ;
return 0 ;
}
if ( V_13 != V_129 )
return V_13 ;
F_8 ( V_124 ) ;
} while ( -- V_123 > 0 );
return V_13 ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_17 ( V_2 ) ;
if ( V_13 )
goto V_28;
V_13 = F_31 ( V_2 ) ;
if ( V_13 ) {
F_4 ( & V_2 -> V_21 , L_18 ) ;
goto V_28;
}
return V_13 ;
V_28:
if ( V_13 > 0 )
V_13 = - V_118 ;
return V_13 ;
}
int F_34 ( T_1 V_117 , void * V_42 , T_4 V_130 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_25 ( V_117 ) ;
if ( V_2 == NULL )
return - V_118 ;
V_13 = F_13 ( V_2 , V_42 , V_130 , 0 , L_19 ) ;
F_26 ( V_2 ) ;
return V_13 ;
}
static bool F_35 ( struct V_1 * V_2 , T_3 V_131 ,
bool V_132 , bool * V_133 )
{
T_3 V_33 = V_2 -> V_26 -> V_33 ( V_2 ) ;
* V_133 = false ;
if ( ( V_33 & V_131 ) == V_131 )
return true ;
if ( V_132 && V_2 -> V_26 -> V_36 ( V_2 , V_33 ) ) {
* V_133 = true ;
return true ;
}
return false ;
}
int F_36 ( struct V_1 * V_2 , T_3 V_131 , unsigned long V_93 ,
T_7 * V_134 , bool V_132 )
{
unsigned long V_15 ;
long V_13 ;
T_3 V_33 ;
bool V_133 = false ;
V_33 = V_2 -> V_26 -> V_33 ( V_2 ) ;
if ( ( V_33 & V_131 ) == V_131 )
return 0 ;
V_15 = V_32 + V_93 ;
if ( V_2 -> V_12 & V_29 ) {
V_135:
V_93 = V_15 - V_32 ;
if ( ( long ) V_93 <= 0 )
return - V_40 ;
V_13 = F_37 ( * V_134 ,
F_35 ( V_2 , V_131 , V_132 ,
& V_133 ) ,
V_93 ) ;
if ( V_13 > 0 ) {
if ( V_133 )
return - V_37 ;
return 0 ;
}
if ( V_13 == - V_136 && F_38 ( V_137 ) ) {
F_39 ( V_138 ) ;
goto V_135;
}
} else {
do {
F_8 ( V_38 ) ;
V_33 = V_2 -> V_26 -> V_33 ( V_2 ) ;
if ( ( V_33 & V_131 ) == V_131 )
return 0 ;
} while ( F_10 ( V_32 , V_15 ) );
}
return - V_40 ;
}
int F_40 ( struct V_139 * V_21 )
{
struct V_1 * V_2 = F_41 ( V_21 ) ;
struct V_52 V_42 ;
int V_13 , V_140 ;
T_3 V_141 [ V_116 ] = { 0 } ;
if ( V_2 == NULL )
return - V_118 ;
if ( V_2 -> V_12 & V_31 ) {
F_42 ( V_2 , V_142 ) ;
return 0 ;
}
if ( V_143 ) {
V_42 . V_46 . V_54 = V_120 ;
V_42 . V_58 . V_121 . V_109 = F_15 ( V_143 ) ;
memcpy ( V_42 . V_58 . V_121 . V_119 , V_141 ,
V_116 ) ;
V_13 = F_13 ( V_2 , & V_42 , V_122 , 0 ,
L_20 ) ;
}
for ( V_140 = 0 ; V_140 < V_144 ; V_140 ++ ) {
V_42 . V_46 . V_54 = V_145 ;
V_13 = F_13 ( V_2 , & V_42 , V_146 , 0 ,
NULL ) ;
if ( V_13 != V_147 )
break;
F_8 ( V_148 ) ;
}
if ( V_13 )
F_4 ( & V_2 -> V_21 ,
L_21 , V_13 ) ;
else if ( V_140 > 0 )
F_43 ( & V_2 -> V_21 , L_22 ,
V_140 * V_148 ) ;
return V_13 ;
}
int F_44 ( struct V_139 * V_21 )
{
struct V_1 * V_2 = F_41 ( V_21 ) ;
if ( V_2 == NULL )
return - V_118 ;
return 0 ;
}
int F_45 ( T_1 V_117 , T_3 * V_28 , T_4 V_149 )
{
struct V_1 * V_2 ;
struct V_52 V_53 ;
T_1 V_150 , V_151 = F_46 ( T_1 , V_149 , V_152 ) ;
int V_47 , V_153 = 0 , V_154 = 5 ;
T_3 * V_155 = V_28 ;
if ( ! V_28 || ! V_151 || V_149 > V_152 )
return - V_17 ;
V_2 = F_25 ( V_117 ) ;
if ( V_2 == NULL )
return - V_118 ;
if ( V_2 -> V_12 & V_31 ) {
V_47 = F_47 ( V_2 , V_28 , V_149 ) ;
F_26 ( V_2 ) ;
return V_47 ;
}
do {
V_53 . V_46 . V_54 = V_156 ;
V_53 . V_58 . V_157 . V_151 = F_15 ( V_151 ) ;
V_47 = F_13 ( V_2 , & V_53 ,
V_158 + V_151 ,
0 , L_23 ) ;
if ( V_47 )
break;
V_150 = F_3 ( V_53 . V_58 . V_159 . V_160 ) ;
memcpy ( V_155 , V_53 . V_58 . V_159 . V_161 , V_150 ) ;
V_155 += V_150 ;
V_153 += V_150 ;
V_151 -= V_150 ;
} while ( V_154 -- && V_153 < V_149 );
F_26 ( V_2 ) ;
return V_153 ? V_153 : - V_162 ;
}
int F_48 ( T_1 V_117 , struct V_163 * V_164 ,
struct V_165 * V_166 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_25 ( V_117 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_12 & V_31 ) )
return - V_118 ;
V_13 = F_49 ( V_2 , V_164 , V_166 ) ;
F_26 ( V_2 ) ;
return V_13 ;
}
int F_50 ( T_1 V_117 , struct V_163 * V_164 ,
struct V_165 * V_166 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_25 ( V_117 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_12 & V_31 ) )
return - V_118 ;
V_13 = F_51 ( V_2 , V_164 , V_166 ) ;
F_26 ( V_2 ) ;
return V_13 ;
}
static int T_8 F_52 ( void )
{
int V_13 ;
V_167 = F_53 ( V_168 , L_24 ) ;
if ( F_54 ( V_167 ) ) {
F_55 ( L_25 ) ;
return F_56 ( V_167 ) ;
}
V_13 = F_57 ( & V_169 , 0 , V_170 , L_24 ) ;
if ( V_13 < 0 ) {
F_55 ( L_26 ) ;
F_58 ( V_167 ) ;
return V_13 ;
}
return 0 ;
}
static void T_9 F_59 ( void )
{
F_60 ( & V_171 ) ;
F_58 ( V_167 ) ;
F_61 ( V_169 , V_170 ) ;
}
