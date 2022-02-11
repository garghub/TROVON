unsigned long F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 = V_5 ;
int V_6 = 0 ;
T_2 V_7 = ( V_3 >> 24 ) & 0xFF ;
if ( ( V_7 == V_8 && V_3 < V_9 ) ||
( V_7 == V_10 && V_3 < V_11 ) )
V_4 = V_12 [ V_3 ] ;
if ( V_4 != V_5 )
V_6 = V_2 -> V_13 . V_6 [ V_4 ] ;
if ( V_6 <= 0 )
return 2 * 60 * V_14 ;
else
return V_6 ;
}
T_3 F_2 ( struct V_1 * V_2 , const char * V_15 ,
T_4 V_16 )
{
T_3 V_17 ;
T_1 V_18 , V_3 ;
unsigned long V_19 ;
if ( V_16 > V_20 )
V_16 = V_20 ;
V_18 = F_3 ( * ( ( V_21 * ) ( V_15 + 2 ) ) ) ;
V_3 = F_3 ( * ( ( V_21 * ) ( V_15 + 6 ) ) ) ;
if ( V_18 == 0 )
return - V_22 ;
if ( V_18 > V_16 ) {
F_4 ( V_2 -> V_23 ,
L_1 , V_18 , V_16 ) ;
return - V_24 ;
}
F_5 ( & V_2 -> V_25 ) ;
V_17 = V_2 -> V_26 -> V_27 ( V_2 , ( T_2 * ) V_15 , V_18 ) ;
if ( V_17 < 0 ) {
F_4 ( V_2 -> V_23 ,
L_2 , V_17 ) ;
goto V_28;
}
if ( V_2 -> V_13 . V_29 )
goto V_30;
if ( V_2 -> V_31 & V_32 )
V_19 = V_33 + F_6 ( V_2 , V_3 ) ;
else
V_19 = V_33 + F_1 ( V_2 , V_3 ) ;
do {
T_2 V_34 = V_2 -> V_26 -> V_34 ( V_2 ) ;
if ( ( V_34 & V_2 -> V_26 -> V_35 ) ==
V_2 -> V_26 -> V_36 )
goto V_30;
if ( V_2 -> V_26 -> V_37 ( V_2 , V_34 ) ) {
F_4 ( V_2 -> V_23 , L_3 ) ;
V_17 = - V_38 ;
goto V_28;
}
F_7 ( V_39 ) ;
F_8 () ;
} while ( F_9 ( V_33 , V_19 ) );
V_2 -> V_26 -> V_40 ( V_2 ) ;
F_4 ( V_2 -> V_23 , L_4 ) ;
V_17 = - V_41 ;
goto V_28;
V_30:
V_17 = V_2 -> V_26 -> V_42 ( V_2 , ( T_2 * ) V_15 , V_16 ) ;
if ( V_17 < 0 )
F_4 ( V_2 -> V_23 ,
L_5 , V_17 ) ;
V_28:
F_10 ( & V_2 -> V_25 ) ;
return V_17 ;
}
T_3 F_11 ( struct V_1 * V_2 , void * V_43 ,
int V_44 , const char * V_45 )
{
struct V_46 * V_47 ;
int V_48 ;
V_44 = F_2 ( V_2 , ( T_2 * ) V_43 , V_44 ) ;
if ( V_44 < 0 )
return V_44 ;
else if ( V_44 < V_49 )
return - V_50 ;
V_47 = V_43 ;
V_48 = F_3 ( V_47 -> V_51 ) ;
if ( V_48 != 0 && V_45 )
F_4 ( V_2 -> V_23 , L_6 , V_48 ,
V_45 ) ;
return V_48 ;
}
T_3 F_12 ( struct V_52 * V_53 , V_21 V_54 , T_5 * V_55 ,
const char * V_45 )
{
struct V_56 V_57 ;
int V_17 ;
struct V_1 * V_2 = F_13 ( V_53 ) ;
V_57 . V_47 . V_58 = V_59 ;
if ( V_54 == V_60 || V_54 == V_61 ) {
V_57 . V_62 . V_63 . V_55 = V_54 ;
V_57 . V_62 . V_63 . V_64 = F_14 ( 0 ) ;
V_57 . V_47 . V_58 . V_65 -= F_14 ( sizeof( V_21 ) ) ;
} else {
if ( V_54 == V_66 ||
V_54 == V_67 )
V_57 . V_62 . V_63 . V_55 = V_68 ;
else
V_57 . V_62 . V_63 . V_55 = V_69 ;
V_57 . V_62 . V_63 . V_64 = F_14 ( 4 ) ;
V_57 . V_62 . V_63 . V_70 = V_54 ;
}
V_17 = F_11 ( V_2 , & V_57 , V_71 , V_45 ) ;
if ( ! V_17 )
* V_55 = V_57 . V_62 . V_72 . V_55 ;
return V_17 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_56 V_57 ;
T_3 V_17 ;
V_57 . V_47 . V_58 = V_59 ;
V_57 . V_62 . V_63 . V_55 = V_69 ;
V_57 . V_62 . V_63 . V_64 = F_14 ( 4 ) ;
V_57 . V_62 . V_63 . V_70 = V_73 ;
V_17 = F_11 ( V_2 , & V_57 , V_71 ,
L_7 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_6 V_74 )
{
struct V_56 V_75 ;
V_75 . V_47 . V_58 = V_76 ;
V_75 . V_62 . V_77 . V_74 = V_74 ;
return F_11 ( V_2 , & V_75 , V_71 ,
L_8 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_56 V_57 ;
unsigned long V_78 [ 4 ] ;
unsigned long V_79 [ 4 ] ;
struct V_80 * V_81 ;
T_3 V_17 ;
V_57 . V_47 . V_58 = V_59 ;
V_57 . V_62 . V_63 . V_55 = V_69 ;
V_57 . V_62 . V_63 . V_64 = F_14 ( 4 ) ;
V_57 . V_62 . V_63 . V_70 = V_73 ;
V_17 = F_11 ( V_2 , & V_57 , V_71 , NULL ) ;
if ( V_17 == V_82 ) {
F_18 ( V_2 -> V_23 , L_9 ) ;
if ( F_16 ( V_2 , V_83 ) )
return V_17 ;
V_57 . V_47 . V_58 = V_59 ;
V_57 . V_62 . V_63 . V_55 = V_69 ;
V_57 . V_62 . V_63 . V_64 = F_14 ( 4 ) ;
V_57 . V_62 . V_63 . V_70 = V_73 ;
V_17 = F_11 ( V_2 , & V_57 , V_71 ,
NULL ) ;
}
if ( V_17 ) {
F_4 ( V_2 -> V_23 ,
L_10 ,
V_17 ) ;
goto V_6;
}
if ( F_3 ( V_57 . V_47 . V_28 . V_51 ) != 0 ||
F_3 ( V_57 . V_47 . V_28 . V_65 )
!= sizeof( V_57 . V_47 . V_28 ) + sizeof( T_1 ) + 4 * sizeof( T_1 ) )
return - V_84 ;
V_79 [ 0 ] = F_3 ( V_57 . V_62 . V_72 . V_55 . V_85 . V_86 ) ;
V_79 [ 1 ] = F_3 ( V_57 . V_62 . V_72 . V_55 . V_85 . V_87 ) ;
V_79 [ 2 ] = F_3 ( V_57 . V_62 . V_72 . V_55 . V_85 . V_88 ) ;
V_79 [ 3 ] = F_3 ( V_57 . V_62 . V_72 . V_55 . V_85 . V_89 ) ;
memcpy ( V_78 , V_79 , sizeof( V_78 ) ) ;
if ( V_2 -> V_26 -> V_90 != NULL )
V_2 -> V_13 . V_91 =
V_2 -> V_26 -> V_90 ( V_2 , V_78 ) ;
if ( ! V_2 -> V_13 . V_91 ) {
if ( V_78 [ 0 ] != 0 && V_78 [ 0 ] < 1000 ) {
int V_92 ;
for ( V_92 = 0 ; V_92 != F_19 ( V_78 ) ; V_92 ++ )
V_78 [ V_92 ] *= 1000 ;
V_2 -> V_13 . V_91 = true ;
}
}
if ( V_2 -> V_13 . V_91 ) {
F_18 ( V_2 -> V_23 ,
V_93 L_11 ,
V_79 [ 0 ] , V_78 [ 0 ] ,
V_79 [ 1 ] , V_78 [ 1 ] ,
V_79 [ 2 ] , V_78 [ 2 ] ,
V_79 [ 3 ] , V_78 [ 3 ] ) ;
}
V_2 -> V_13 . V_94 = F_20 ( V_78 [ 0 ] ) ;
V_2 -> V_13 . V_95 = F_20 ( V_78 [ 1 ] ) ;
V_2 -> V_13 . V_96 = F_20 ( V_78 [ 2 ] ) ;
V_2 -> V_13 . V_97 = F_20 ( V_78 [ 3 ] ) ;
V_6:
V_57 . V_47 . V_58 = V_59 ;
V_57 . V_62 . V_63 . V_55 = V_69 ;
V_57 . V_62 . V_63 . V_64 = F_14 ( 4 ) ;
V_57 . V_62 . V_63 . V_70 = V_98 ;
V_17 = F_11 ( V_2 , & V_57 , V_71 ,
L_12 ) ;
if ( V_17 )
return V_17 ;
if ( F_3 ( V_57 . V_47 . V_28 . V_51 ) != 0 ||
F_3 ( V_57 . V_47 . V_28 . V_65 )
!= sizeof( V_57 . V_47 . V_28 ) + sizeof( T_1 ) + 3 * sizeof( T_1 ) )
return - V_84 ;
V_81 = & V_57 . V_62 . V_72 . V_55 . V_6 ;
V_2 -> V_13 . V_6 [ V_99 ] =
F_20 ( F_3 ( V_81 -> V_100 ) ) ;
V_2 -> V_13 . V_6 [ V_101 ] =
F_20 ( F_3 ( V_81 -> V_102 ) ) ;
V_2 -> V_13 . V_6 [ V_103 ] =
F_20 ( F_3 ( V_81 -> V_104 ) ) ;
if ( V_2 -> V_13 . V_6 [ V_99 ] < ( V_14 / 100 ) ) {
V_2 -> V_13 . V_6 [ V_99 ] = V_14 ;
V_2 -> V_13 . V_6 [ V_101 ] *= 1000 ;
V_2 -> V_13 . V_6 [ V_103 ] *= 1000 ;
V_2 -> V_13 . V_105 = true ;
F_18 ( V_2 -> V_23 , L_13 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_56 V_43 ;
V_43 . V_47 . V_58 = V_106 ;
V_17 = F_11 ( V_2 , & V_43 , V_107 ,
L_14 ) ;
return V_17 ;
}
int F_22 ( struct V_1 * V_2 , int V_108 , T_2 * V_109 )
{
int V_17 ;
struct V_56 V_43 ;
V_43 . V_47 . V_58 = V_110 ;
V_43 . V_62 . V_111 . V_108 = F_14 ( V_108 ) ;
V_17 = F_11 ( V_2 , & V_43 , V_112 ,
L_15 ) ;
if ( V_17 == 0 )
memcpy ( V_109 , V_43 . V_62 . V_113 . V_114 ,
V_115 ) ;
return V_17 ;
}
int F_23 ( T_1 V_116 )
{
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_24 ( V_116 ) ;
if ( V_2 == NULL )
return - V_117 ;
V_17 = ( V_2 -> V_31 & V_32 ) != 0 ;
F_25 ( V_2 ) ;
return V_17 ;
}
int F_26 ( T_1 V_116 , int V_108 , T_2 * V_109 )
{
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_24 ( V_116 ) ;
if ( V_2 == NULL )
return - V_117 ;
if ( V_2 -> V_31 & V_32 )
V_17 = F_27 ( V_2 , V_108 , V_109 ) ;
else
V_17 = F_22 ( V_2 , V_108 , V_109 ) ;
F_25 ( V_2 ) ;
return V_17 ;
}
int F_28 ( T_1 V_116 , int V_108 , const T_2 * V_118 )
{
struct V_56 V_43 ;
int V_17 ;
struct V_1 * V_2 ;
V_2 = F_24 ( V_116 ) ;
if ( V_2 == NULL )
return - V_117 ;
if ( V_2 -> V_31 & V_32 ) {
V_17 = F_29 ( V_2 , V_108 , V_118 ) ;
F_25 ( V_2 ) ;
return V_17 ;
}
V_43 . V_47 . V_58 = V_119 ;
V_43 . V_62 . V_120 . V_108 = F_14 ( V_108 ) ;
memcpy ( V_43 . V_62 . V_120 . V_118 , V_118 , V_115 ) ;
V_17 = F_11 ( V_2 , & V_43 , V_121 ,
L_16 ) ;
F_25 ( V_2 ) ;
return V_17 ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_17 ;
unsigned int V_122 ;
unsigned int V_123 = 100 ;
unsigned long V_6 ;
struct V_56 V_43 ;
V_6 = F_1 ( V_2 , V_124 ) ;
V_122 = F_31 ( V_6 ) / V_123 ;
V_17 = F_21 ( V_2 ) ;
if ( V_17 )
return V_17 ;
do {
V_43 . V_47 . V_58 = V_110 ;
V_43 . V_62 . V_111 . V_108 = F_14 ( 0 ) ;
V_17 = F_2 ( V_2 , ( T_2 * ) & V_43 , V_112 ) ;
if ( V_17 == - V_41 ) {
F_18 ( V_2 -> V_23 , V_93 L_17 ) ;
F_7 ( V_123 ) ;
continue;
}
if ( V_17 < V_49 )
return - V_50 ;
V_17 = F_3 ( V_43 . V_47 . V_28 . V_51 ) ;
if ( V_17 == V_125 || V_17 == V_126 ) {
F_18 ( V_2 -> V_23 ,
L_18 , V_17 ) ;
return 0 ;
}
if ( V_17 != V_127 )
return V_17 ;
F_7 ( V_123 ) ;
} while ( -- V_122 > 0 );
return V_17 ;
}
int F_32 ( T_1 V_116 , void * V_43 , T_4 V_128 )
{
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_24 ( V_116 ) ;
if ( V_2 == NULL )
return - V_117 ;
V_17 = F_11 ( V_2 , V_43 , V_128 , L_19 ) ;
F_25 ( V_2 ) ;
return V_17 ;
}
static bool F_33 ( struct V_1 * V_2 , T_2 V_129 ,
bool V_130 , bool * V_131 )
{
T_2 V_34 = V_2 -> V_26 -> V_34 ( V_2 ) ;
* V_131 = false ;
if ( ( V_34 & V_129 ) == V_129 )
return true ;
if ( V_130 && V_2 -> V_26 -> V_37 ( V_2 , V_34 ) ) {
* V_131 = true ;
return true ;
}
return false ;
}
int F_34 ( struct V_1 * V_2 , T_2 V_129 , unsigned long V_85 ,
T_7 * V_132 , bool V_130 )
{
unsigned long V_19 ;
long V_17 ;
T_2 V_34 ;
bool V_131 = false ;
V_34 = V_2 -> V_26 -> V_34 ( V_2 ) ;
if ( ( V_34 & V_129 ) == V_129 )
return 0 ;
V_19 = V_33 + V_85 ;
if ( V_2 -> V_13 . V_29 ) {
V_133:
V_85 = V_19 - V_33 ;
if ( ( long ) V_85 <= 0 )
return - V_41 ;
V_17 = F_35 ( * V_132 ,
F_33 ( V_2 , V_129 , V_130 ,
& V_131 ) ,
V_85 ) ;
if ( V_17 > 0 ) {
if ( V_131 )
return - V_38 ;
return 0 ;
}
if ( V_17 == - V_134 && F_36 ( V_135 ) ) {
F_37 ( V_136 ) ;
goto V_133;
}
} else {
do {
F_7 ( V_39 ) ;
V_34 = V_2 -> V_26 -> V_34 ( V_2 ) ;
if ( ( V_34 & V_129 ) == V_129 )
return 0 ;
} while ( F_9 ( V_33 , V_19 ) );
}
return - V_41 ;
}
int F_38 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_13 ( V_53 ) ;
struct V_56 V_43 ;
int V_17 , V_137 ;
T_2 V_138 [ V_115 ] = { 0 } ;
if ( V_2 == NULL )
return - V_117 ;
if ( V_2 -> V_31 & V_32 ) {
F_39 ( V_2 , V_139 ) ;
return 0 ;
}
if ( V_140 ) {
V_43 . V_47 . V_58 = V_119 ;
V_43 . V_62 . V_120 . V_108 = F_14 ( V_140 ) ;
memcpy ( V_43 . V_62 . V_120 . V_118 , V_138 ,
V_115 ) ;
V_17 = F_11 ( V_2 , & V_43 , V_121 ,
L_20 ) ;
}
for ( V_137 = 0 ; V_137 < V_141 ; V_137 ++ ) {
V_43 . V_47 . V_58 = V_142 ;
V_17 = F_11 ( V_2 , & V_43 , V_143 , NULL ) ;
if ( V_17 != V_144 )
break;
F_7 ( V_145 ) ;
}
if ( V_17 )
F_4 ( V_2 -> V_23 ,
L_21 , V_17 ) ;
else if ( V_137 > 0 )
F_40 ( V_2 -> V_23 , L_22 ,
V_137 * V_145 ) ;
return V_17 ;
}
int F_41 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_13 ( V_53 ) ;
if ( V_2 == NULL )
return - V_117 ;
return 0 ;
}
int F_42 ( T_1 V_116 , T_2 * V_28 , T_4 V_146 )
{
struct V_1 * V_2 ;
struct V_56 V_57 ;
T_1 V_147 , V_148 = F_43 ( T_1 , V_146 , V_149 ) ;
int V_48 , V_150 = 0 , V_151 = 5 ;
T_2 * V_152 = V_28 ;
if ( ! V_28 || ! V_148 || V_146 > V_149 )
return - V_84 ;
V_2 = F_24 ( V_116 ) ;
if ( V_2 == NULL )
return - V_117 ;
if ( V_2 -> V_31 & V_32 ) {
V_48 = F_44 ( V_2 , V_28 , V_146 ) ;
F_25 ( V_2 ) ;
return V_48 ;
}
do {
V_57 . V_47 . V_58 = V_153 ;
V_57 . V_62 . V_154 . V_148 = F_14 ( V_148 ) ;
V_48 = F_11 ( V_2 , & V_57 ,
V_155 + V_148 ,
L_23 ) ;
if ( V_48 )
break;
V_147 = F_3 ( V_57 . V_62 . V_156 . V_157 ) ;
memcpy ( V_152 , V_57 . V_62 . V_156 . V_158 , V_147 ) ;
V_152 += V_147 ;
V_150 += V_147 ;
V_148 -= V_147 ;
} while ( V_151 -- && V_150 < V_146 );
F_25 ( V_2 ) ;
return V_150 ? V_150 : - V_159 ;
}
int F_45 ( T_1 V_116 , struct V_160 * V_161 ,
struct V_162 * V_163 )
{
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_24 ( V_116 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_31 & V_32 ) )
return - V_117 ;
V_17 = F_46 ( V_2 , V_161 , V_163 ) ;
F_25 ( V_2 ) ;
return V_17 ;
}
int F_47 ( T_1 V_116 , struct V_160 * V_161 ,
struct V_162 * V_163 )
{
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_24 ( V_116 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_31 & V_32 ) )
return - V_117 ;
V_17 = F_48 ( V_2 , V_161 , V_163 ) ;
F_25 ( V_2 ) ;
return V_17 ;
}
static int T_8 F_49 ( void )
{
int V_17 ;
V_164 = F_50 ( V_165 , L_24 ) ;
if ( F_51 ( V_164 ) ) {
F_52 ( L_25 ) ;
return F_53 ( V_164 ) ;
}
V_17 = F_54 ( & V_166 , 0 , V_167 , L_24 ) ;
if ( V_17 < 0 ) {
F_52 ( L_26 ) ;
F_55 ( V_164 ) ;
return V_17 ;
}
return 0 ;
}
static void T_9 F_56 ( void )
{
F_55 ( V_164 ) ;
F_57 ( V_166 , V_167 ) ;
}
