unsigned long F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 = V_5 ;
int V_6 = 0 ;
if ( V_3 < V_7 )
V_4 = V_8 [ V_3 ] ;
if ( V_4 != V_5 )
V_6 = V_2 -> V_9 . V_6 [ V_4 ] ;
if ( V_6 <= 0 )
return 2 * 60 * V_10 ;
else
return V_6 ;
}
T_2 F_2 ( struct V_1 * V_2 , const char * V_11 ,
T_3 V_12 )
{
T_2 V_13 ;
T_1 V_14 , V_3 ;
unsigned long V_15 ;
if ( V_12 > V_16 )
V_12 = V_16 ;
V_14 = F_3 ( * ( ( V_17 * ) ( V_11 + 2 ) ) ) ;
V_3 = F_3 ( * ( ( V_17 * ) ( V_11 + 6 ) ) ) ;
if ( V_14 == 0 )
return - V_18 ;
if ( V_14 > V_12 ) {
F_4 ( V_2 -> V_19 ,
L_1 , V_14 , V_12 ) ;
return - V_20 ;
}
F_5 ( & V_2 -> V_21 ) ;
V_13 = V_2 -> V_22 -> V_23 ( V_2 , ( V_24 * ) V_11 , V_14 ) ;
if ( V_13 < 0 ) {
F_4 ( V_2 -> V_19 ,
L_2 , V_13 ) ;
goto V_25;
}
if ( V_2 -> V_9 . V_26 )
goto V_27;
if ( V_2 -> V_28 & V_29 )
V_15 = V_30 + F_6 ( V_2 , V_3 ) ;
else
V_15 = V_30 + F_1 ( V_2 , V_3 ) ;
do {
V_24 V_31 = V_2 -> V_22 -> V_31 ( V_2 ) ;
if ( ( V_31 & V_2 -> V_22 -> V_32 ) ==
V_2 -> V_22 -> V_33 )
goto V_27;
if ( V_2 -> V_22 -> V_34 ( V_2 , V_31 ) ) {
F_4 ( V_2 -> V_19 , L_3 ) ;
V_13 = - V_35 ;
goto V_25;
}
F_7 ( V_36 ) ;
F_8 () ;
} while ( F_9 ( V_30 , V_15 ) );
V_2 -> V_22 -> V_37 ( V_2 ) ;
F_4 ( V_2 -> V_19 , L_4 ) ;
V_13 = - V_38 ;
goto V_25;
V_27:
V_13 = V_2 -> V_22 -> V_39 ( V_2 , ( V_24 * ) V_11 , V_12 ) ;
if ( V_13 < 0 )
F_4 ( V_2 -> V_19 ,
L_5 , V_13 ) ;
V_25:
F_10 ( & V_2 -> V_21 ) ;
return V_13 ;
}
T_2 F_11 ( struct V_1 * V_2 , void * V_40 ,
int V_41 , const char * V_42 )
{
struct V_43 * V_44 ;
int V_45 ;
V_41 = F_2 ( V_2 , ( V_24 * ) V_40 , V_41 ) ;
if ( V_41 < 0 )
return V_41 ;
else if ( V_41 < V_46 )
return - V_47 ;
V_44 = V_40 ;
V_45 = F_3 ( V_44 -> V_48 ) ;
if ( V_45 != 0 && V_42 )
F_4 ( V_2 -> V_19 , L_6 , V_45 ,
V_42 ) ;
return V_45 ;
}
T_2 F_12 ( struct V_49 * V_50 , V_17 V_51 , T_4 * V_52 ,
const char * V_42 )
{
struct V_53 V_54 ;
int V_13 ;
struct V_1 * V_2 = F_13 ( V_50 ) ;
V_54 . V_44 . V_55 = V_56 ;
if ( V_51 == V_57 || V_51 == V_58 ) {
V_54 . V_59 . V_60 . V_52 = V_51 ;
V_54 . V_59 . V_60 . V_61 = F_14 ( 0 ) ;
V_54 . V_44 . V_55 . V_62 -= F_14 ( sizeof( V_17 ) ) ;
} else {
if ( V_51 == V_63 ||
V_51 == V_64 )
V_54 . V_59 . V_60 . V_52 = V_65 ;
else
V_54 . V_59 . V_60 . V_52 = V_66 ;
V_54 . V_59 . V_60 . V_61 = F_14 ( 4 ) ;
V_54 . V_59 . V_60 . V_67 = V_51 ;
}
V_13 = F_11 ( V_2 , & V_54 , V_68 , V_42 ) ;
if ( ! V_13 )
* V_52 = V_54 . V_59 . V_69 . V_52 ;
return V_13 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_53 V_54 ;
T_2 V_13 ;
V_54 . V_44 . V_55 = V_56 ;
V_54 . V_59 . V_60 . V_52 = V_66 ;
V_54 . V_59 . V_60 . V_61 = F_14 ( 4 ) ;
V_54 . V_59 . V_60 . V_67 = V_70 ;
V_13 = F_11 ( V_2 , & V_54 , V_68 ,
L_7 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_5 V_71 )
{
struct V_53 V_72 ;
V_72 . V_44 . V_55 = V_73 ;
V_72 . V_59 . V_74 . V_71 = V_71 ;
return F_11 ( V_2 , & V_72 , V_68 ,
L_8 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_53 V_54 ;
unsigned long V_75 [ 4 ] ;
unsigned long V_76 [ 4 ] ;
struct V_77 * V_78 ;
T_2 V_13 ;
if ( V_2 -> V_28 & V_29 ) {
V_2 -> V_9 . V_79 = F_18 ( V_80 ) ;
V_2 -> V_9 . V_81 = F_18 ( V_82 ) ;
V_2 -> V_9 . V_83 = F_18 ( V_84 ) ;
V_2 -> V_9 . V_85 = F_18 ( V_86 ) ;
V_2 -> V_9 . V_6 [ V_87 ] =
F_18 ( V_88 ) ;
V_2 -> V_9 . V_6 [ V_89 ] =
F_18 ( V_90 ) ;
V_2 -> V_9 . V_6 [ V_91 ] =
F_18 ( V_92 ) ;
return 0 ;
}
V_54 . V_44 . V_55 = V_56 ;
V_54 . V_59 . V_60 . V_52 = V_66 ;
V_54 . V_59 . V_60 . V_61 = F_14 ( 4 ) ;
V_54 . V_59 . V_60 . V_67 = V_70 ;
V_13 = F_11 ( V_2 , & V_54 , V_68 , NULL ) ;
if ( V_13 == V_93 ) {
F_19 ( V_2 -> V_19 , L_9 ) ;
if ( F_16 ( V_2 , V_94 ) )
return V_13 ;
V_54 . V_44 . V_55 = V_56 ;
V_54 . V_59 . V_60 . V_52 = V_66 ;
V_54 . V_59 . V_60 . V_61 = F_14 ( 4 ) ;
V_54 . V_59 . V_60 . V_67 = V_70 ;
V_13 = F_11 ( V_2 , & V_54 , V_68 ,
NULL ) ;
}
if ( V_13 ) {
F_4 ( V_2 -> V_19 ,
L_10 ,
V_13 ) ;
goto V_6;
}
if ( F_3 ( V_54 . V_44 . V_25 . V_48 ) != 0 ||
F_3 ( V_54 . V_44 . V_25 . V_62 )
!= sizeof( V_54 . V_44 . V_25 ) + sizeof( T_1 ) + 4 * sizeof( T_1 ) )
return - V_95 ;
V_76 [ 0 ] = F_3 ( V_54 . V_59 . V_69 . V_52 . V_96 . V_97 ) ;
V_76 [ 1 ] = F_3 ( V_54 . V_59 . V_69 . V_52 . V_96 . V_98 ) ;
V_76 [ 2 ] = F_3 ( V_54 . V_59 . V_69 . V_52 . V_96 . V_99 ) ;
V_76 [ 3 ] = F_3 ( V_54 . V_59 . V_69 . V_52 . V_96 . V_100 ) ;
memcpy ( V_75 , V_76 , sizeof( V_75 ) ) ;
if ( V_2 -> V_22 -> V_101 != NULL )
V_2 -> V_9 . V_102 =
V_2 -> V_22 -> V_101 ( V_2 , V_75 ) ;
if ( ! V_2 -> V_9 . V_102 ) {
if ( V_75 [ 0 ] != 0 && V_75 [ 0 ] < 1000 ) {
int V_103 ;
for ( V_103 = 0 ; V_103 != F_20 ( V_75 ) ; V_103 ++ )
V_75 [ V_103 ] *= 1000 ;
V_2 -> V_9 . V_102 = true ;
}
}
if ( V_2 -> V_9 . V_102 ) {
F_19 ( V_2 -> V_19 ,
V_104 L_11 ,
V_76 [ 0 ] , V_75 [ 0 ] ,
V_76 [ 1 ] , V_75 [ 1 ] ,
V_76 [ 2 ] , V_75 [ 2 ] ,
V_76 [ 3 ] , V_75 [ 3 ] ) ;
}
V_2 -> V_9 . V_79 = F_21 ( V_75 [ 0 ] ) ;
V_2 -> V_9 . V_81 = F_21 ( V_75 [ 1 ] ) ;
V_2 -> V_9 . V_83 = F_21 ( V_75 [ 2 ] ) ;
V_2 -> V_9 . V_85 = F_21 ( V_75 [ 3 ] ) ;
V_6:
V_54 . V_44 . V_55 = V_56 ;
V_54 . V_59 . V_60 . V_52 = V_66 ;
V_54 . V_59 . V_60 . V_61 = F_14 ( 4 ) ;
V_54 . V_59 . V_60 . V_67 = V_105 ;
V_13 = F_11 ( V_2 , & V_54 , V_68 ,
L_12 ) ;
if ( V_13 )
return V_13 ;
if ( F_3 ( V_54 . V_44 . V_25 . V_48 ) != 0 ||
F_3 ( V_54 . V_44 . V_25 . V_62 )
!= sizeof( V_54 . V_44 . V_25 ) + sizeof( T_1 ) + 3 * sizeof( T_1 ) )
return - V_95 ;
V_78 = & V_54 . V_59 . V_69 . V_52 . V_6 ;
V_2 -> V_9 . V_6 [ V_87 ] =
F_21 ( F_3 ( V_78 -> V_106 ) ) ;
V_2 -> V_9 . V_6 [ V_89 ] =
F_21 ( F_3 ( V_78 -> V_107 ) ) ;
V_2 -> V_9 . V_6 [ V_91 ] =
F_21 ( F_3 ( V_78 -> V_108 ) ) ;
if ( V_2 -> V_9 . V_6 [ V_87 ] < ( V_10 / 100 ) ) {
V_2 -> V_9 . V_6 [ V_87 ] = V_10 ;
V_2 -> V_9 . V_6 [ V_89 ] *= 1000 ;
V_2 -> V_9 . V_6 [ V_91 ] *= 1000 ;
V_2 -> V_9 . V_109 = true ;
F_19 ( V_2 -> V_19 , L_13 ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_53 V_40 ;
V_40 . V_44 . V_55 = V_110 ;
V_13 = F_11 ( V_2 , & V_40 , V_111 ,
L_14 ) ;
return V_13 ;
}
int F_23 ( struct V_1 * V_2 , int V_112 , V_24 * V_113 )
{
int V_13 ;
struct V_53 V_40 ;
V_40 . V_44 . V_55 = V_114 ;
V_40 . V_59 . V_115 . V_112 = F_14 ( V_112 ) ;
V_13 = F_11 ( V_2 , & V_40 , V_116 ,
L_15 ) ;
if ( V_13 == 0 )
memcpy ( V_113 , V_40 . V_59 . V_117 . V_118 ,
V_119 ) ;
return V_13 ;
}
int F_24 ( T_1 V_120 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_25 ( V_120 ) ;
if ( V_2 == NULL )
return - V_121 ;
V_13 = ( V_2 -> V_28 & V_29 ) != 0 ;
F_26 ( V_2 ) ;
return V_13 ;
}
int F_27 ( T_1 V_120 , int V_112 , V_24 * V_113 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_25 ( V_120 ) ;
if ( V_2 == NULL )
return - V_121 ;
if ( V_2 -> V_28 & V_29 )
V_13 = F_28 ( V_2 , V_112 , V_113 ) ;
else
V_13 = F_23 ( V_2 , V_112 , V_113 ) ;
F_26 ( V_2 ) ;
return V_13 ;
}
int F_29 ( T_1 V_120 , int V_112 , const V_24 * V_122 )
{
struct V_53 V_40 ;
int V_13 ;
struct V_1 * V_2 ;
V_2 = F_25 ( V_120 ) ;
if ( V_2 == NULL )
return - V_121 ;
if ( V_2 -> V_28 & V_29 ) {
V_13 = F_30 ( V_2 , V_112 , V_122 ) ;
F_26 ( V_2 ) ;
return V_13 ;
}
V_40 . V_44 . V_55 = V_123 ;
V_40 . V_59 . V_124 . V_112 = F_14 ( V_112 ) ;
memcpy ( V_40 . V_59 . V_124 . V_122 , V_122 , V_119 ) ;
V_13 = F_11 ( V_2 , & V_40 , V_125 ,
L_16 ) ;
F_26 ( V_2 ) ;
return V_13 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_13 ;
unsigned int V_126 ;
unsigned int V_127 = 100 ;
unsigned long V_6 ;
struct V_53 V_40 ;
V_6 = F_1 ( V_2 , V_128 ) ;
V_126 = F_32 ( V_6 ) / V_127 ;
V_13 = F_22 ( V_2 ) ;
if ( V_13 )
return V_13 ;
do {
V_40 . V_44 . V_55 = V_114 ;
V_40 . V_59 . V_115 . V_112 = F_14 ( 0 ) ;
V_13 = F_2 ( V_2 , ( V_24 * ) & V_40 , V_116 ) ;
if ( V_13 == - V_38 ) {
F_19 ( V_2 -> V_19 , V_104 L_17 ) ;
F_7 ( V_127 ) ;
continue;
}
if ( V_13 < V_46 )
return - V_47 ;
V_13 = F_3 ( V_40 . V_44 . V_25 . V_48 ) ;
if ( V_13 == V_129 || V_13 == V_130 ) {
F_19 ( V_2 -> V_19 ,
L_18 , V_13 ) ;
return 0 ;
}
if ( V_13 != V_131 )
return V_13 ;
F_7 ( V_127 ) ;
} while ( -- V_126 > 0 );
return V_13 ;
}
int F_33 ( T_1 V_120 , void * V_40 , T_3 V_132 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_25 ( V_120 ) ;
if ( V_2 == NULL )
return - V_121 ;
V_13 = F_11 ( V_2 , V_40 , V_132 , L_19 ) ;
F_26 ( V_2 ) ;
return V_13 ;
}
static bool F_34 ( struct V_1 * V_2 , V_24 V_133 ,
bool V_134 , bool * V_135 )
{
V_24 V_31 = V_2 -> V_22 -> V_31 ( V_2 ) ;
* V_135 = false ;
if ( ( V_31 & V_133 ) == V_133 )
return true ;
if ( V_134 && V_2 -> V_22 -> V_34 ( V_2 , V_31 ) ) {
* V_135 = true ;
return true ;
}
return false ;
}
int F_35 ( struct V_1 * V_2 , V_24 V_133 , unsigned long V_96 ,
T_6 * V_136 , bool V_134 )
{
unsigned long V_15 ;
long V_13 ;
V_24 V_31 ;
bool V_135 = false ;
V_31 = V_2 -> V_22 -> V_31 ( V_2 ) ;
if ( ( V_31 & V_133 ) == V_133 )
return 0 ;
V_15 = V_30 + V_96 ;
if ( V_2 -> V_9 . V_26 ) {
V_137:
V_96 = V_15 - V_30 ;
if ( ( long ) V_96 <= 0 )
return - V_38 ;
V_13 = F_36 ( * V_136 ,
F_34 ( V_2 , V_133 , V_134 ,
& V_135 ) ,
V_96 ) ;
if ( V_13 > 0 ) {
if ( V_135 )
return - V_35 ;
return 0 ;
}
if ( V_13 == - V_138 && F_37 ( V_139 ) ) {
F_38 ( V_140 ) ;
goto V_137;
}
} else {
do {
F_7 ( V_36 ) ;
V_31 = V_2 -> V_22 -> V_31 ( V_2 ) ;
if ( ( V_31 & V_133 ) == V_133 )
return 0 ;
} while ( F_9 ( V_30 , V_15 ) );
}
return - V_38 ;
}
int F_39 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_53 V_40 ;
int V_13 , V_141 ;
V_24 V_142 [ V_119 ] = { 0 } ;
if ( V_2 == NULL )
return - V_121 ;
if ( V_2 -> V_28 & V_29 ) {
F_40 ( V_2 , V_143 ) ;
return 0 ;
}
if ( V_144 ) {
V_40 . V_44 . V_55 = V_123 ;
V_40 . V_59 . V_124 . V_112 = F_14 ( V_144 ) ;
memcpy ( V_40 . V_59 . V_124 . V_122 , V_142 ,
V_119 ) ;
V_13 = F_11 ( V_2 , & V_40 , V_125 ,
L_20 ) ;
}
for ( V_141 = 0 ; V_141 < V_145 ; V_141 ++ ) {
V_40 . V_44 . V_55 = V_146 ;
V_13 = F_11 ( V_2 , & V_40 , V_147 , NULL ) ;
if ( V_13 != V_148 )
break;
F_7 ( V_149 ) ;
}
if ( V_13 )
F_4 ( V_2 -> V_19 ,
L_21 , V_13 ) ;
else if ( V_141 > 0 )
F_41 ( V_2 -> V_19 , L_22 ,
V_141 * V_149 ) ;
return V_13 ;
}
int F_42 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 == NULL )
return - V_121 ;
return 0 ;
}
int F_43 ( T_1 V_120 , V_24 * V_25 , T_3 V_150 )
{
struct V_1 * V_2 ;
struct V_53 V_54 ;
T_1 V_151 , V_152 = F_44 ( T_1 , V_150 , V_153 ) ;
int V_45 , V_154 = 0 , V_155 = 5 ;
V_24 * V_156 = V_25 ;
if ( ! V_25 || ! V_152 || V_150 > V_153 )
return - V_95 ;
V_2 = F_25 ( V_120 ) ;
if ( V_2 == NULL )
return - V_121 ;
if ( V_2 -> V_28 & V_29 ) {
V_45 = F_45 ( V_2 , V_25 , V_150 ) ;
F_26 ( V_2 ) ;
return V_45 ;
}
do {
V_54 . V_44 . V_55 = V_157 ;
V_54 . V_59 . V_158 . V_152 = F_14 ( V_152 ) ;
V_45 = F_11 ( V_2 , & V_54 ,
V_159 + V_152 ,
L_23 ) ;
if ( V_45 )
break;
V_151 = F_3 ( V_54 . V_59 . V_160 . V_161 ) ;
memcpy ( V_156 , V_54 . V_59 . V_160 . V_162 , V_151 ) ;
V_156 += V_151 ;
V_154 += V_151 ;
V_152 -= V_151 ;
} while ( V_155 -- && V_154 < V_150 );
F_26 ( V_2 ) ;
return V_154 ? V_154 : - V_163 ;
}
int F_46 ( T_1 V_120 , struct V_164 * V_165 ,
struct V_166 * V_167 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_25 ( V_120 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_28 & V_29 ) )
return - V_121 ;
V_13 = F_47 ( V_2 , V_165 , V_167 ) ;
F_26 ( V_2 ) ;
return V_13 ;
}
int F_48 ( T_1 V_120 , struct V_164 * V_165 ,
struct V_166 * V_167 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_25 ( V_120 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_28 & V_29 ) )
return - V_121 ;
V_13 = F_49 ( V_2 , V_165 , V_167 ) ;
F_26 ( V_2 ) ;
return V_13 ;
}
static int T_7 F_50 ( void )
{
int V_13 ;
V_168 = F_51 ( V_169 , L_24 ) ;
if ( F_52 ( V_168 ) ) {
F_53 ( L_25 ) ;
return F_54 ( V_168 ) ;
}
V_13 = F_55 ( & V_170 , 0 , V_171 , L_24 ) ;
if ( V_13 < 0 ) {
F_53 ( L_26 ) ;
F_56 ( V_168 ) ;
return V_13 ;
}
return 0 ;
}
static void T_8 F_57 ( void )
{
F_56 ( V_168 ) ;
F_58 ( V_170 , V_171 ) ;
}
