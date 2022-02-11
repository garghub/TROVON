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
V_19 = V_31 + F_1 ( V_2 , V_3 ) ;
do {
T_2 V_32 = V_2 -> V_26 -> V_32 ( V_2 ) ;
if ( ( V_32 & V_2 -> V_26 -> V_33 ) ==
V_2 -> V_26 -> V_34 )
goto V_30;
if ( V_2 -> V_26 -> V_35 ( V_2 , V_32 ) ) {
F_4 ( V_2 -> V_23 , L_3 ) ;
V_17 = - V_36 ;
goto V_28;
}
F_6 ( V_37 ) ;
F_7 () ;
} while ( F_8 ( V_31 , V_19 ) );
V_2 -> V_26 -> V_38 ( V_2 ) ;
F_4 ( V_2 -> V_23 , L_4 ) ;
V_17 = - V_39 ;
goto V_28;
V_30:
V_17 = V_2 -> V_26 -> V_40 ( V_2 , ( T_2 * ) V_15 , V_16 ) ;
if ( V_17 < 0 )
F_4 ( V_2 -> V_23 ,
L_5 , V_17 ) ;
V_28:
F_9 ( & V_2 -> V_25 ) ;
return V_17 ;
}
static T_3 F_10 ( struct V_1 * V_2 , struct V_41 * V_42 ,
int V_43 , const char * V_44 )
{
int V_45 ;
V_43 = F_2 ( V_2 , ( T_2 * ) V_42 , V_43 ) ;
if ( V_43 < 0 )
return V_43 ;
else if ( V_43 < V_46 )
return - V_47 ;
V_45 = F_3 ( V_42 -> V_48 . V_28 . V_49 ) ;
if ( V_45 != 0 && V_44 )
F_4 ( V_2 -> V_23 , L_6 , V_45 , V_44 ) ;
return V_45 ;
}
T_3 F_11 ( struct V_50 * V_23 , V_21 V_51 , T_5 * V_52 ,
const char * V_44 )
{
struct V_41 V_53 ;
int V_17 ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
V_53 . V_48 . V_54 = V_55 ;
if ( V_51 == V_56 || V_51 == V_57 ) {
V_53 . V_58 . V_59 . V_52 = V_51 ;
V_53 . V_58 . V_59 . V_60 = F_13 ( 0 ) ;
V_53 . V_48 . V_54 . V_61 -= F_13 ( sizeof( V_21 ) ) ;
} else {
if ( V_51 == V_62 ||
V_51 == V_63 )
V_53 . V_58 . V_59 . V_52 = V_64 ;
else
V_53 . V_58 . V_59 . V_52 = V_65 ;
V_53 . V_58 . V_59 . V_60 = F_13 ( 4 ) ;
V_53 . V_58 . V_59 . V_66 = V_51 ;
}
V_17 = F_10 ( V_2 , & V_53 , V_67 , V_44 ) ;
if ( ! V_17 )
* V_52 = V_53 . V_58 . V_68 . V_52 ;
return V_17 ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_41 V_53 ;
T_3 V_17 ;
V_53 . V_48 . V_54 = V_55 ;
V_53 . V_58 . V_59 . V_52 = V_65 ;
V_53 . V_58 . V_59 . V_60 = F_13 ( 4 ) ;
V_53 . V_58 . V_59 . V_66 = V_69 ;
V_17 = F_10 ( V_2 , & V_53 , V_67 ,
L_7 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_6 V_70 )
{
struct V_41 V_71 ;
V_71 . V_48 . V_54 = V_72 ;
V_71 . V_58 . V_73 . V_70 = V_70 ;
return F_10 ( V_2 , & V_71 , V_67 ,
L_8 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_41 V_53 ;
unsigned long V_74 [ 4 ] ;
unsigned long V_75 [ 4 ] ;
struct V_76 * V_77 ;
T_3 V_17 ;
V_53 . V_48 . V_54 = V_55 ;
V_53 . V_58 . V_59 . V_52 = V_65 ;
V_53 . V_58 . V_59 . V_60 = F_13 ( 4 ) ;
V_53 . V_58 . V_59 . V_66 = V_69 ;
V_17 = F_10 ( V_2 , & V_53 , V_67 , NULL ) ;
if ( V_17 == V_78 ) {
F_17 ( V_2 -> V_23 , L_9 ) ;
if ( F_15 ( V_2 , V_79 ) )
return V_17 ;
V_53 . V_48 . V_54 = V_55 ;
V_53 . V_58 . V_59 . V_52 = V_65 ;
V_53 . V_58 . V_59 . V_60 = F_13 ( 4 ) ;
V_53 . V_58 . V_59 . V_66 = V_69 ;
V_17 = F_10 ( V_2 , & V_53 , V_67 ,
NULL ) ;
}
if ( V_17 ) {
F_4 ( V_2 -> V_23 ,
L_10 ,
V_17 ) ;
goto V_6;
}
if ( F_3 ( V_53 . V_48 . V_28 . V_49 ) != 0 ||
F_3 ( V_53 . V_48 . V_28 . V_61 )
!= sizeof( V_53 . V_48 . V_28 ) + sizeof( T_1 ) + 4 * sizeof( T_1 ) )
return - V_80 ;
V_75 [ 0 ] = F_3 ( V_53 . V_58 . V_68 . V_52 . V_81 . V_82 ) ;
V_75 [ 1 ] = F_3 ( V_53 . V_58 . V_68 . V_52 . V_81 . V_83 ) ;
V_75 [ 2 ] = F_3 ( V_53 . V_58 . V_68 . V_52 . V_81 . V_84 ) ;
V_75 [ 3 ] = F_3 ( V_53 . V_58 . V_68 . V_52 . V_81 . V_85 ) ;
memcpy ( V_74 , V_75 , sizeof( V_74 ) ) ;
if ( V_2 -> V_26 -> V_86 != NULL )
V_2 -> V_13 . V_87 =
V_2 -> V_26 -> V_86 ( V_2 , V_74 ) ;
if ( ! V_2 -> V_13 . V_87 ) {
if ( V_74 [ 0 ] != 0 && V_74 [ 0 ] < 1000 ) {
int V_88 ;
for ( V_88 = 0 ; V_88 != F_18 ( V_74 ) ; V_88 ++ )
V_74 [ V_88 ] *= 1000 ;
V_2 -> V_13 . V_87 = true ;
}
}
if ( V_2 -> V_13 . V_87 ) {
F_17 ( V_2 -> V_23 ,
V_89 L_11 ,
V_75 [ 0 ] , V_74 [ 0 ] ,
V_75 [ 1 ] , V_74 [ 1 ] ,
V_75 [ 2 ] , V_74 [ 2 ] ,
V_75 [ 3 ] , V_74 [ 3 ] ) ;
}
V_2 -> V_13 . V_90 = F_19 ( V_74 [ 0 ] ) ;
V_2 -> V_13 . V_91 = F_19 ( V_74 [ 1 ] ) ;
V_2 -> V_13 . V_92 = F_19 ( V_74 [ 2 ] ) ;
V_2 -> V_13 . V_93 = F_19 ( V_74 [ 3 ] ) ;
V_6:
V_53 . V_48 . V_54 = V_55 ;
V_53 . V_58 . V_59 . V_52 = V_65 ;
V_53 . V_58 . V_59 . V_60 = F_13 ( 4 ) ;
V_53 . V_58 . V_59 . V_66 = V_94 ;
V_17 = F_10 ( V_2 , & V_53 , V_67 ,
L_12 ) ;
if ( V_17 )
return V_17 ;
if ( F_3 ( V_53 . V_48 . V_28 . V_49 ) != 0 ||
F_3 ( V_53 . V_48 . V_28 . V_61 )
!= sizeof( V_53 . V_48 . V_28 ) + sizeof( T_1 ) + 3 * sizeof( T_1 ) )
return - V_80 ;
V_77 = & V_53 . V_58 . V_68 . V_52 . V_6 ;
V_2 -> V_13 . V_6 [ V_95 ] =
F_19 ( F_3 ( V_77 -> V_96 ) ) ;
V_2 -> V_13 . V_6 [ V_97 ] =
F_19 ( F_3 ( V_77 -> V_98 ) ) ;
V_2 -> V_13 . V_6 [ V_99 ] =
F_19 ( F_3 ( V_77 -> V_100 ) ) ;
if ( V_2 -> V_13 . V_6 [ V_95 ] < ( V_14 / 100 ) ) {
V_2 -> V_13 . V_6 [ V_95 ] = V_14 ;
V_2 -> V_13 . V_6 [ V_97 ] *= 1000 ;
V_2 -> V_13 . V_6 [ V_99 ] *= 1000 ;
V_2 -> V_13 . V_101 = true ;
F_17 ( V_2 -> V_23 , L_13 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_41 V_42 ;
V_42 . V_48 . V_54 = V_102 ;
V_17 = F_10 ( V_2 , & V_42 , V_103 ,
L_14 ) ;
return V_17 ;
}
static struct V_1 * F_21 ( int V_104 )
{
struct V_1 * V_105 , * V_2 = NULL ;
F_22 () ;
F_23 (pos, &tpm_chip_list, list) {
if ( V_104 != V_106 && V_104 != V_105 -> V_107 )
continue;
if ( F_24 ( V_105 -> V_23 -> V_108 -> V_109 ) ) {
V_2 = V_105 ;
break;
}
}
F_25 () ;
return V_2 ;
}
int F_26 ( struct V_1 * V_2 , int V_110 , T_2 * V_111 )
{
int V_17 ;
struct V_41 V_42 ;
V_42 . V_48 . V_54 = V_112 ;
V_42 . V_58 . V_113 . V_110 = F_13 ( V_110 ) ;
V_17 = F_10 ( V_2 , & V_42 , V_114 ,
L_15 ) ;
if ( V_17 == 0 )
memcpy ( V_111 , V_42 . V_58 . V_115 . V_116 ,
V_117 ) ;
return V_17 ;
}
int F_27 ( T_1 V_104 , int V_110 , T_2 * V_111 )
{
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_21 ( V_104 ) ;
if ( V_2 == NULL )
return - V_118 ;
V_17 = F_26 ( V_2 , V_110 , V_111 ) ;
F_28 ( V_2 ) ;
return V_17 ;
}
int F_29 ( T_1 V_104 , int V_110 , const T_2 * V_119 )
{
struct V_41 V_42 ;
int V_17 ;
struct V_1 * V_2 ;
V_2 = F_21 ( V_104 ) ;
if ( V_2 == NULL )
return - V_118 ;
V_42 . V_48 . V_54 = V_120 ;
V_42 . V_58 . V_121 . V_110 = F_13 ( V_110 ) ;
memcpy ( V_42 . V_58 . V_121 . V_119 , V_119 , V_117 ) ;
V_17 = F_10 ( V_2 , & V_42 , V_122 ,
L_16 ) ;
F_28 ( V_2 ) ;
return V_17 ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_17 ;
unsigned int V_123 ;
unsigned int V_124 = 100 ;
unsigned long V_6 ;
struct V_41 V_42 ;
V_6 = F_1 ( V_2 , V_125 ) ;
V_123 = F_31 ( V_6 ) / V_124 ;
V_17 = F_20 ( V_2 ) ;
if ( V_17 )
return V_17 ;
do {
V_42 . V_48 . V_54 = V_112 ;
V_42 . V_58 . V_113 . V_110 = F_13 ( 0 ) ;
V_17 = F_2 ( V_2 , ( T_2 * ) & V_42 , V_114 ) ;
if ( V_17 == - V_39 ) {
F_17 ( V_2 -> V_23 , V_89 L_17 ) ;
F_6 ( V_124 ) ;
continue;
}
if ( V_17 < V_46 )
return - V_47 ;
V_17 = F_3 ( V_42 . V_48 . V_28 . V_49 ) ;
if ( V_17 == V_126 || V_17 == V_127 ) {
F_17 ( V_2 -> V_23 ,
L_18 , V_17 ) ;
return 0 ;
}
if ( V_17 != V_128 )
return V_17 ;
F_6 ( V_124 ) ;
} while ( -- V_123 > 0 );
return V_17 ;
}
int F_32 ( T_1 V_104 , void * V_42 , T_4 V_129 )
{
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_21 ( V_104 ) ;
if ( V_2 == NULL )
return - V_118 ;
V_17 = F_10 ( V_2 , V_42 , V_129 , L_19 ) ;
F_28 ( V_2 ) ;
return V_17 ;
}
static bool F_33 ( struct V_1 * V_2 , T_2 V_130 ,
bool V_131 , bool * V_132 )
{
T_2 V_32 = V_2 -> V_26 -> V_32 ( V_2 ) ;
* V_132 = false ;
if ( ( V_32 & V_130 ) == V_130 )
return true ;
if ( V_131 && V_2 -> V_26 -> V_35 ( V_2 , V_32 ) ) {
* V_132 = true ;
return true ;
}
return false ;
}
int F_34 ( struct V_1 * V_2 , T_2 V_130 , unsigned long V_81 ,
T_7 * V_133 , bool V_131 )
{
unsigned long V_19 ;
long V_17 ;
T_2 V_32 ;
bool V_132 = false ;
V_32 = V_2 -> V_26 -> V_32 ( V_2 ) ;
if ( ( V_32 & V_130 ) == V_130 )
return 0 ;
V_19 = V_31 + V_81 ;
if ( V_2 -> V_13 . V_29 ) {
V_134:
V_81 = V_19 - V_31 ;
if ( ( long ) V_81 <= 0 )
return - V_39 ;
V_17 = F_35 ( * V_133 ,
F_33 ( V_2 , V_130 , V_131 ,
& V_132 ) ,
V_81 ) ;
if ( V_17 > 0 ) {
if ( V_132 )
return - V_36 ;
return 0 ;
}
if ( V_17 == - V_135 && F_36 ( V_136 ) ) {
F_37 ( V_137 ) ;
goto V_134;
}
} else {
do {
F_6 ( V_37 ) ;
V_32 = V_2 -> V_26 -> V_32 ( V_2 ) ;
if ( ( V_32 & V_130 ) == V_130 )
return 0 ;
} while ( F_8 ( V_31 , V_19 ) );
}
return - V_39 ;
}
void F_38 ( struct V_50 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
if ( V_2 == NULL ) {
F_4 ( V_23 , L_20 ) ;
return;
}
F_39 ( & V_138 ) ;
F_40 ( & V_2 -> V_139 ) ;
F_41 ( & V_138 ) ;
F_42 () ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( & V_23 -> V_140 ) ;
F_46 ( V_2 -> V_141 ) ;
F_47 ( V_2 -> V_23 ) ;
}
int F_48 ( struct V_50 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
struct V_41 V_42 ;
int V_17 , V_142 ;
T_2 V_143 [ V_117 ] = { 0 } ;
if ( V_2 == NULL )
return - V_118 ;
if ( V_144 ) {
V_42 . V_48 . V_54 = V_120 ;
V_42 . V_58 . V_121 . V_110 = F_13 ( V_144 ) ;
memcpy ( V_42 . V_58 . V_121 . V_119 , V_143 ,
V_117 ) ;
V_17 = F_10 ( V_2 , & V_42 , V_122 ,
L_21 ) ;
}
for ( V_142 = 0 ; V_142 < V_145 ; V_142 ++ ) {
V_42 . V_48 . V_54 = V_146 ;
V_17 = F_10 ( V_2 , & V_42 , V_147 , NULL ) ;
if ( V_17 != V_148 )
break;
F_6 ( V_149 ) ;
}
if ( V_17 )
F_4 ( V_2 -> V_23 ,
L_22 , V_17 ) ;
else if ( V_142 > 0 )
F_49 ( V_2 -> V_23 , L_23 ,
V_142 * V_149 ) ;
return V_17 ;
}
int F_50 ( struct V_50 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
if ( V_2 == NULL )
return - V_118 ;
return 0 ;
}
int F_51 ( T_1 V_104 , T_2 * V_28 , T_4 V_150 )
{
struct V_1 * V_2 ;
struct V_41 V_53 ;
T_1 V_151 , V_152 = F_52 ( T_1 , V_150 , V_153 ) ;
int V_45 , V_154 = 0 , V_155 = 5 ;
T_2 * V_156 = V_28 ;
if ( ! V_28 || ! V_152 || V_150 > V_153 )
return - V_80 ;
V_2 = F_21 ( V_104 ) ;
if ( V_2 == NULL )
return - V_118 ;
do {
V_53 . V_48 . V_54 = V_157 ;
V_53 . V_58 . V_158 . V_152 = F_13 ( V_152 ) ;
V_45 = F_10 ( V_2 , & V_53 ,
V_159 + V_152 ,
L_24 ) ;
if ( V_45 )
break;
V_151 = F_3 ( V_53 . V_58 . V_160 . V_161 ) ;
memcpy ( V_156 , V_53 . V_58 . V_160 . V_162 , V_151 ) ;
V_156 += V_151 ;
V_154 += V_151 ;
V_152 -= V_151 ;
} while ( V_155 -- && V_154 < V_150 );
F_28 ( V_2 ) ;
return V_154 ? V_154 : - V_163 ;
}
void F_53 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_54 ( V_2 -> V_107 , V_164 ) ;
}
static void F_55 ( struct V_50 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
if ( ! V_2 )
return;
F_53 ( V_2 ) ;
V_2 -> V_165 ( V_23 ) ;
F_56 ( V_2 ) ;
}
struct V_1 * F_57 ( struct V_50 * V_23 ,
const struct V_166 * V_26 )
{
struct V_1 * V_2 ;
V_2 = F_58 ( sizeof( * V_2 ) , V_167 ) ;
if ( V_2 == NULL )
return NULL ;
F_59 ( & V_2 -> V_25 ) ;
F_60 ( & V_2 -> V_139 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_107 = F_61 ( V_164 , V_168 ) ;
if ( V_2 -> V_107 >= V_168 ) {
F_4 ( V_23 , L_25 ) ;
goto V_169;
}
F_62 ( V_2 -> V_107 , V_164 ) ;
F_63 ( V_2 -> V_170 , sizeof( V_2 -> V_170 ) , L_26 , L_27 ,
V_2 -> V_107 ) ;
V_2 -> V_23 = F_64 ( V_23 ) ;
V_2 -> V_165 = V_23 -> V_165 ;
V_23 -> V_165 = F_55 ;
F_65 ( V_23 , V_2 ) ;
if ( F_66 ( V_2 ) )
goto F_47;
if ( F_67 ( V_2 ) )
goto V_171;
if ( F_68 ( & V_23 -> V_140 ) )
goto V_172;
V_2 -> V_141 = F_69 ( V_2 -> V_170 ) ;
F_39 ( & V_138 ) ;
F_70 ( & V_2 -> V_139 , & V_173 ) ;
F_41 ( & V_138 ) ;
return V_2 ;
V_172:
F_44 ( V_2 ) ;
V_171:
F_43 ( V_2 ) ;
F_47:
F_47 ( V_2 -> V_23 ) ;
V_169:
F_56 ( V_2 ) ;
return NULL ;
}
