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
T_2 F_2 ( struct V_1 * V_2 , const char * V_10 ,
T_3 V_11 )
{
T_2 V_12 ;
T_1 V_13 , V_3 ;
unsigned long V_14 ;
if ( V_11 > V_15 )
V_11 = V_15 ;
V_13 = F_3 ( * ( ( V_16 * ) ( V_10 + 2 ) ) ) ;
V_3 = F_3 ( * ( ( V_16 * ) ( V_10 + 6 ) ) ) ;
if ( V_13 == 0 )
return - V_17 ;
if ( V_13 > V_11 ) {
F_4 ( & V_2 -> V_18 ,
L_1 , V_13 , V_11 ) ;
return - V_19 ;
}
F_5 ( & V_2 -> V_20 ) ;
V_12 = V_2 -> V_21 -> V_22 ( V_2 , ( V_23 * ) V_10 , V_13 ) ;
if ( V_12 < 0 ) {
F_4 ( & V_2 -> V_18 ,
L_2 , V_12 ) ;
goto V_24;
}
if ( V_2 -> V_25 & V_26 )
goto V_27;
if ( V_2 -> V_25 & V_28 )
V_14 = V_29 + F_6 ( V_2 , V_3 ) ;
else
V_14 = V_29 + F_1 ( V_2 , V_3 ) ;
do {
V_23 V_30 = V_2 -> V_21 -> V_30 ( V_2 ) ;
if ( ( V_30 & V_2 -> V_21 -> V_31 ) ==
V_2 -> V_21 -> V_32 )
goto V_27;
if ( V_2 -> V_21 -> V_33 ( V_2 , V_30 ) ) {
F_4 ( & V_2 -> V_18 , L_3 ) ;
V_12 = - V_34 ;
goto V_24;
}
F_7 ( V_35 ) ;
F_8 () ;
} while ( F_9 ( V_29 , V_14 ) );
V_2 -> V_21 -> V_36 ( V_2 ) ;
F_4 ( & V_2 -> V_18 , L_4 ) ;
V_12 = - V_37 ;
goto V_24;
V_27:
V_12 = V_2 -> V_21 -> V_38 ( V_2 , ( V_23 * ) V_10 , V_11 ) ;
if ( V_12 < 0 )
F_4 ( & V_2 -> V_18 ,
L_5 , V_12 ) ;
V_24:
F_10 ( & V_2 -> V_20 ) ;
return V_12 ;
}
T_2 F_11 ( struct V_1 * V_2 , void * V_39 ,
int V_40 , const char * V_41 )
{
struct V_42 * V_43 ;
int V_44 ;
V_40 = F_2 ( V_2 , ( V_23 * ) V_39 , V_40 ) ;
if ( V_40 < 0 )
return V_40 ;
else if ( V_40 < V_45 )
return - V_46 ;
V_43 = V_39 ;
V_44 = F_3 ( V_43 -> V_47 ) ;
if ( V_44 != 0 && V_41 )
F_4 ( & V_2 -> V_18 , L_6 , V_44 ,
V_41 ) ;
return V_44 ;
}
T_2 F_12 ( struct V_1 * V_2 , V_16 V_48 , T_4 * V_49 ,
const char * V_41 )
{
struct V_50 V_51 ;
int V_12 ;
V_51 . V_43 . V_52 = V_53 ;
if ( V_48 == V_54 || V_48 == V_55 ) {
V_51 . V_56 . V_57 . V_49 = V_48 ;
V_51 . V_56 . V_57 . V_58 = F_13 ( 0 ) ;
V_51 . V_43 . V_52 . V_59 -= F_13 ( sizeof( V_16 ) ) ;
} else {
if ( V_48 == V_60 ||
V_48 == V_61 )
V_51 . V_56 . V_57 . V_49 = V_62 ;
else
V_51 . V_56 . V_57 . V_49 = V_63 ;
V_51 . V_56 . V_57 . V_58 = F_13 ( 4 ) ;
V_51 . V_56 . V_57 . V_64 = V_48 ;
}
V_12 = F_11 ( V_2 , & V_51 , V_65 , V_41 ) ;
if ( ! V_12 )
* V_49 = V_51 . V_56 . V_66 . V_49 ;
return V_12 ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_50 V_51 ;
T_2 V_12 ;
V_51 . V_43 . V_52 = V_53 ;
V_51 . V_56 . V_57 . V_49 = V_63 ;
V_51 . V_56 . V_57 . V_58 = F_13 ( 4 ) ;
V_51 . V_56 . V_57 . V_64 = V_67 ;
V_12 = F_11 ( V_2 , & V_51 , V_65 ,
L_7 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_5 V_68 )
{
struct V_50 V_69 ;
V_69 . V_43 . V_52 = V_70 ;
V_69 . V_56 . V_71 . V_68 = V_68 ;
return F_11 ( V_2 , & V_69 , V_65 ,
L_8 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_50 V_51 ;
unsigned long V_72 [ 4 ] ;
unsigned long V_73 [ 4 ] ;
struct V_74 * V_75 ;
T_2 V_12 ;
if ( V_2 -> V_25 & V_28 ) {
V_2 -> V_76 = F_17 ( V_77 ) ;
V_2 -> V_78 = F_17 ( V_79 ) ;
V_2 -> V_80 = F_17 ( V_81 ) ;
V_2 -> V_82 = F_17 ( V_83 ) ;
V_2 -> V_6 [ V_84 ] =
F_17 ( V_85 ) ;
V_2 -> V_6 [ V_86 ] =
F_17 ( V_87 ) ;
V_2 -> V_6 [ V_88 ] =
F_17 ( V_89 ) ;
return 0 ;
}
V_51 . V_43 . V_52 = V_53 ;
V_51 . V_56 . V_57 . V_49 = V_63 ;
V_51 . V_56 . V_57 . V_58 = F_13 ( 4 ) ;
V_51 . V_56 . V_57 . V_64 = V_67 ;
V_12 = F_11 ( V_2 , & V_51 , V_65 , NULL ) ;
if ( V_12 == V_90 ) {
F_18 ( & V_2 -> V_18 , L_9 ) ;
if ( F_15 ( V_2 , V_91 ) )
return V_12 ;
V_51 . V_43 . V_52 = V_53 ;
V_51 . V_56 . V_57 . V_49 = V_63 ;
V_51 . V_56 . V_57 . V_58 = F_13 ( 4 ) ;
V_51 . V_56 . V_57 . V_64 = V_67 ;
V_12 = F_11 ( V_2 , & V_51 , V_65 ,
NULL ) ;
}
if ( V_12 ) {
F_4 ( & V_2 -> V_18 ,
L_10 ,
V_12 ) ;
goto V_6;
}
if ( F_3 ( V_51 . V_43 . V_24 . V_47 ) != 0 ||
F_3 ( V_51 . V_43 . V_24 . V_59 )
!= sizeof( V_51 . V_43 . V_24 ) + sizeof( T_1 ) + 4 * sizeof( T_1 ) )
return - V_92 ;
V_73 [ 0 ] = F_3 ( V_51 . V_56 . V_66 . V_49 . V_93 . V_94 ) ;
V_73 [ 1 ] = F_3 ( V_51 . V_56 . V_66 . V_49 . V_93 . V_95 ) ;
V_73 [ 2 ] = F_3 ( V_51 . V_56 . V_66 . V_49 . V_93 . V_96 ) ;
V_73 [ 3 ] = F_3 ( V_51 . V_56 . V_66 . V_49 . V_93 . V_97 ) ;
memcpy ( V_72 , V_73 , sizeof( V_72 ) ) ;
if ( V_2 -> V_21 -> V_98 != NULL )
V_2 -> V_99 =
V_2 -> V_21 -> V_98 ( V_2 , V_72 ) ;
if ( ! V_2 -> V_99 ) {
if ( V_72 [ 0 ] != 0 && V_72 [ 0 ] < 1000 ) {
int V_100 ;
for ( V_100 = 0 ; V_100 != F_19 ( V_72 ) ; V_100 ++ )
V_72 [ V_100 ] *= 1000 ;
V_2 -> V_99 = true ;
}
}
if ( V_2 -> V_99 ) {
F_18 ( & V_2 -> V_18 ,
V_101 L_11 ,
V_73 [ 0 ] , V_72 [ 0 ] ,
V_73 [ 1 ] , V_72 [ 1 ] ,
V_73 [ 2 ] , V_72 [ 2 ] ,
V_73 [ 3 ] , V_72 [ 3 ] ) ;
}
V_2 -> V_76 = F_20 ( V_72 [ 0 ] ) ;
V_2 -> V_78 = F_20 ( V_72 [ 1 ] ) ;
V_2 -> V_80 = F_20 ( V_72 [ 2 ] ) ;
V_2 -> V_82 = F_20 ( V_72 [ 3 ] ) ;
V_6:
V_51 . V_43 . V_52 = V_53 ;
V_51 . V_56 . V_57 . V_49 = V_63 ;
V_51 . V_56 . V_57 . V_58 = F_13 ( 4 ) ;
V_51 . V_56 . V_57 . V_64 = V_102 ;
V_12 = F_11 ( V_2 , & V_51 , V_65 ,
L_12 ) ;
if ( V_12 )
return V_12 ;
if ( F_3 ( V_51 . V_43 . V_24 . V_47 ) != 0 ||
F_3 ( V_51 . V_43 . V_24 . V_59 )
!= sizeof( V_51 . V_43 . V_24 ) + sizeof( T_1 ) + 3 * sizeof( T_1 ) )
return - V_92 ;
V_75 = & V_51 . V_56 . V_66 . V_49 . V_6 ;
V_2 -> V_6 [ V_84 ] =
F_20 ( F_3 ( V_75 -> V_103 ) ) ;
V_2 -> V_6 [ V_86 ] =
F_20 ( F_3 ( V_75 -> V_104 ) ) ;
V_2 -> V_6 [ V_88 ] =
F_20 ( F_3 ( V_75 -> V_105 ) ) ;
if ( V_2 -> V_6 [ V_84 ] < ( V_9 / 100 ) ) {
V_2 -> V_6 [ V_84 ] = V_9 ;
V_2 -> V_6 [ V_86 ] *= 1000 ;
V_2 -> V_6 [ V_88 ] *= 1000 ;
V_2 -> V_106 = true ;
F_18 ( & V_2 -> V_18 , L_13 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_50 V_39 ;
V_39 . V_43 . V_52 = V_107 ;
V_12 = F_11 ( V_2 , & V_39 , V_108 ,
L_14 ) ;
return V_12 ;
}
int F_22 ( struct V_1 * V_2 , int V_109 , V_23 * V_110 )
{
int V_12 ;
struct V_50 V_39 ;
V_39 . V_43 . V_52 = V_111 ;
V_39 . V_56 . V_112 . V_109 = F_13 ( V_109 ) ;
V_12 = F_11 ( V_2 , & V_39 , V_113 ,
L_15 ) ;
if ( V_12 == 0 )
memcpy ( V_110 , V_39 . V_56 . V_114 . V_115 ,
V_116 ) ;
return V_12 ;
}
int F_23 ( T_1 V_117 )
{
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_24 ( V_117 ) ;
if ( V_2 == NULL )
return - V_118 ;
V_12 = ( V_2 -> V_25 & V_28 ) != 0 ;
F_25 ( V_2 ) ;
return V_12 ;
}
int F_26 ( T_1 V_117 , int V_109 , V_23 * V_110 )
{
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_24 ( V_117 ) ;
if ( V_2 == NULL )
return - V_118 ;
if ( V_2 -> V_25 & V_28 )
V_12 = F_27 ( V_2 , V_109 , V_110 ) ;
else
V_12 = F_22 ( V_2 , V_109 , V_110 ) ;
F_25 ( V_2 ) ;
return V_12 ;
}
int F_28 ( T_1 V_117 , int V_109 , const V_23 * V_119 )
{
struct V_50 V_39 ;
int V_12 ;
struct V_1 * V_2 ;
V_2 = F_24 ( V_117 ) ;
if ( V_2 == NULL )
return - V_118 ;
if ( V_2 -> V_25 & V_28 ) {
V_12 = F_29 ( V_2 , V_109 , V_119 ) ;
F_25 ( V_2 ) ;
return V_12 ;
}
V_39 . V_43 . V_52 = V_120 ;
V_39 . V_56 . V_121 . V_109 = F_13 ( V_109 ) ;
memcpy ( V_39 . V_56 . V_121 . V_119 , V_119 , V_116 ) ;
V_12 = F_11 ( V_2 , & V_39 , V_122 ,
L_16 ) ;
F_25 ( V_2 ) ;
return V_12 ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_12 ;
unsigned int V_123 ;
unsigned int V_124 = 100 ;
unsigned long V_6 ;
struct V_50 V_39 ;
V_6 = F_1 ( V_2 , V_125 ) ;
V_123 = F_31 ( V_6 ) / V_124 ;
V_12 = F_21 ( V_2 ) ;
if ( V_12 )
return V_12 ;
do {
V_39 . V_43 . V_52 = V_111 ;
V_39 . V_56 . V_112 . V_109 = F_13 ( 0 ) ;
V_12 = F_2 ( V_2 , ( V_23 * ) & V_39 , V_113 ) ;
if ( V_12 == - V_37 ) {
F_18 (
& V_2 -> V_18 , V_101
L_17 ) ;
F_7 ( V_124 ) ;
continue;
}
if ( V_12 < V_45 )
return - V_46 ;
V_12 = F_3 ( V_39 . V_43 . V_24 . V_47 ) ;
if ( V_12 == V_126 || V_12 == V_127 ) {
F_18 ( & V_2 -> V_18 ,
L_18 , V_12 ) ;
return 0 ;
}
if ( V_12 != V_128 )
return V_12 ;
F_7 ( V_124 ) ;
} while ( -- V_123 > 0 );
return V_12 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_16 ( V_2 ) ;
if ( V_12 )
goto V_24;
V_12 = F_30 ( V_2 ) ;
if ( V_12 ) {
F_4 ( & V_2 -> V_18 , L_19 ) ;
goto V_24;
}
return V_12 ;
V_24:
if ( V_12 > 0 )
V_12 = - V_118 ;
return V_12 ;
}
int F_33 ( T_1 V_117 , void * V_39 , T_3 V_129 )
{
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_24 ( V_117 ) ;
if ( V_2 == NULL )
return - V_118 ;
V_12 = F_11 ( V_2 , V_39 , V_129 , L_20 ) ;
F_25 ( V_2 ) ;
return V_12 ;
}
static bool F_34 ( struct V_1 * V_2 , V_23 V_130 ,
bool V_131 , bool * V_132 )
{
V_23 V_30 = V_2 -> V_21 -> V_30 ( V_2 ) ;
* V_132 = false ;
if ( ( V_30 & V_130 ) == V_130 )
return true ;
if ( V_131 && V_2 -> V_21 -> V_33 ( V_2 , V_30 ) ) {
* V_132 = true ;
return true ;
}
return false ;
}
int F_35 ( struct V_1 * V_2 , V_23 V_130 , unsigned long V_93 ,
T_6 * V_133 , bool V_131 )
{
unsigned long V_14 ;
long V_12 ;
V_23 V_30 ;
bool V_132 = false ;
V_30 = V_2 -> V_21 -> V_30 ( V_2 ) ;
if ( ( V_30 & V_130 ) == V_130 )
return 0 ;
V_14 = V_29 + V_93 ;
if ( V_2 -> V_25 & V_26 ) {
V_134:
V_93 = V_14 - V_29 ;
if ( ( long ) V_93 <= 0 )
return - V_37 ;
V_12 = F_36 ( * V_133 ,
F_34 ( V_2 , V_130 , V_131 ,
& V_132 ) ,
V_93 ) ;
if ( V_12 > 0 ) {
if ( V_132 )
return - V_34 ;
return 0 ;
}
if ( V_12 == - V_135 && F_37 ( V_136 ) ) {
F_38 ( V_137 ) ;
goto V_134;
}
} else {
do {
F_7 ( V_35 ) ;
V_30 = V_2 -> V_21 -> V_30 ( V_2 ) ;
if ( ( V_30 & V_130 ) == V_130 )
return 0 ;
} while ( F_9 ( V_29 , V_14 ) );
}
return - V_37 ;
}
int F_39 ( struct V_138 * V_18 )
{
struct V_1 * V_2 = F_40 ( V_18 ) ;
struct V_50 V_39 ;
int V_12 , V_139 ;
V_23 V_140 [ V_116 ] = { 0 } ;
if ( V_2 == NULL )
return - V_118 ;
if ( V_2 -> V_25 & V_28 ) {
F_41 ( V_2 , V_141 ) ;
return 0 ;
}
if ( V_142 ) {
V_39 . V_43 . V_52 = V_120 ;
V_39 . V_56 . V_121 . V_109 = F_13 ( V_142 ) ;
memcpy ( V_39 . V_56 . V_121 . V_119 , V_140 ,
V_116 ) ;
V_12 = F_11 ( V_2 , & V_39 , V_122 ,
L_21 ) ;
}
for ( V_139 = 0 ; V_139 < V_143 ; V_139 ++ ) {
V_39 . V_43 . V_52 = V_144 ;
V_12 = F_11 ( V_2 , & V_39 , V_145 , NULL ) ;
if ( V_12 != V_146 )
break;
F_7 ( V_147 ) ;
}
if ( V_12 )
F_4 ( & V_2 -> V_18 ,
L_22 , V_12 ) ;
else if ( V_139 > 0 )
F_42 ( & V_2 -> V_18 , L_23 ,
V_139 * V_147 ) ;
return V_12 ;
}
int F_43 ( struct V_138 * V_18 )
{
struct V_1 * V_2 = F_40 ( V_18 ) ;
if ( V_2 == NULL )
return - V_118 ;
return 0 ;
}
int F_44 ( T_1 V_117 , V_23 * V_24 , T_3 V_148 )
{
struct V_1 * V_2 ;
struct V_50 V_51 ;
T_1 V_149 , V_150 = F_45 ( T_1 , V_148 , V_151 ) ;
int V_44 , V_152 = 0 , V_153 = 5 ;
V_23 * V_154 = V_24 ;
if ( ! V_24 || ! V_150 || V_148 > V_151 )
return - V_92 ;
V_2 = F_24 ( V_117 ) ;
if ( V_2 == NULL )
return - V_118 ;
if ( V_2 -> V_25 & V_28 ) {
V_44 = F_46 ( V_2 , V_24 , V_148 ) ;
F_25 ( V_2 ) ;
return V_44 ;
}
do {
V_51 . V_43 . V_52 = V_155 ;
V_51 . V_56 . V_156 . V_150 = F_13 ( V_150 ) ;
V_44 = F_11 ( V_2 , & V_51 ,
V_157 + V_150 ,
L_24 ) ;
if ( V_44 )
break;
V_149 = F_3 ( V_51 . V_56 . V_158 . V_159 ) ;
memcpy ( V_154 , V_51 . V_56 . V_158 . V_160 , V_149 ) ;
V_154 += V_149 ;
V_152 += V_149 ;
V_150 -= V_149 ;
} while ( V_153 -- && V_152 < V_148 );
F_25 ( V_2 ) ;
return V_152 ? V_152 : - V_161 ;
}
int F_47 ( T_1 V_117 , struct V_162 * V_163 ,
struct V_164 * V_165 )
{
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_24 ( V_117 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_25 & V_28 ) )
return - V_118 ;
V_12 = F_48 ( V_2 , V_163 , V_165 ) ;
F_25 ( V_2 ) ;
return V_12 ;
}
int F_49 ( T_1 V_117 , struct V_162 * V_163 ,
struct V_164 * V_165 )
{
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_24 ( V_117 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_25 & V_28 ) )
return - V_118 ;
V_12 = F_50 ( V_2 , V_163 , V_165 ) ;
F_25 ( V_2 ) ;
return V_12 ;
}
static int T_7 F_51 ( void )
{
int V_12 ;
V_166 = F_52 ( V_167 , L_25 ) ;
if ( F_53 ( V_166 ) ) {
F_54 ( L_26 ) ;
return F_55 ( V_166 ) ;
}
V_12 = F_56 ( & V_168 , 0 , V_169 , L_25 ) ;
if ( V_12 < 0 ) {
F_54 ( L_27 ) ;
F_57 ( V_166 ) ;
return V_12 ;
}
return 0 ;
}
static void T_8 F_58 ( void )
{
F_59 ( & V_170 ) ;
F_57 ( V_166 ) ;
F_60 ( V_168 , V_169 ) ;
}
