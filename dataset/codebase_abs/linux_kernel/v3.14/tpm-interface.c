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
struct V_74 * V_75 ;
struct V_76 * V_77 ;
T_3 V_17 ;
T_1 V_78 ;
unsigned int V_79 = 1 ;
V_53 . V_48 . V_54 = V_55 ;
V_53 . V_58 . V_59 . V_52 = V_65 ;
V_53 . V_58 . V_59 . V_60 = F_13 ( 4 ) ;
V_53 . V_58 . V_59 . V_66 = V_69 ;
V_17 = F_10 ( V_2 , & V_53 , V_67 , NULL ) ;
if ( V_17 == V_80 ) {
F_17 ( V_2 -> V_23 , L_9 ) ;
if ( F_15 ( V_2 , V_81 ) )
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
return - V_82 ;
V_75 = & V_53 . V_58 . V_68 . V_52 . V_78 ;
V_78 = F_3 ( V_75 -> V_83 ) ;
if ( V_78 && V_78 < 1000 ) {
V_79 = 1000 ;
V_2 -> V_13 . V_84 = true ;
}
if ( V_78 )
V_2 -> V_13 . V_85 = F_18 ( V_78 * V_79 ) ;
V_78 = F_3 ( V_75 -> V_86 ) ;
if ( V_78 )
V_2 -> V_13 . V_87 = F_18 ( V_78 * V_79 ) ;
V_78 = F_3 ( V_75 -> V_88 ) ;
if ( V_78 )
V_2 -> V_13 . V_89 = F_18 ( V_78 * V_79 ) ;
V_78 = F_3 ( V_75 -> V_90 ) ;
if ( V_78 )
V_2 -> V_13 . V_91 = F_18 ( V_78 * V_79 ) ;
V_6:
V_53 . V_48 . V_54 = V_55 ;
V_53 . V_58 . V_59 . V_52 = V_65 ;
V_53 . V_58 . V_59 . V_60 = F_13 ( 4 ) ;
V_53 . V_58 . V_59 . V_66 = V_92 ;
V_17 = F_10 ( V_2 , & V_53 , V_67 ,
L_11 ) ;
if ( V_17 )
return V_17 ;
if ( F_3 ( V_53 . V_48 . V_28 . V_49 ) != 0 ||
F_3 ( V_53 . V_48 . V_28 . V_61 )
!= sizeof( V_53 . V_48 . V_28 ) + sizeof( T_1 ) + 3 * sizeof( T_1 ) )
return - V_82 ;
V_77 = & V_53 . V_58 . V_68 . V_52 . V_6 ;
V_2 -> V_13 . V_6 [ V_93 ] =
F_18 ( F_3 ( V_77 -> V_94 ) ) ;
V_2 -> V_13 . V_6 [ V_95 ] =
F_18 ( F_3 ( V_77 -> V_96 ) ) ;
V_2 -> V_13 . V_6 [ V_97 ] =
F_18 ( F_3 ( V_77 -> V_98 ) ) ;
if ( V_2 -> V_13 . V_6 [ V_93 ] < ( V_14 / 100 ) ) {
V_2 -> V_13 . V_6 [ V_93 ] = V_14 ;
V_2 -> V_13 . V_6 [ V_95 ] *= 1000 ;
V_2 -> V_13 . V_6 [ V_97 ] *= 1000 ;
V_2 -> V_13 . V_99 = true ;
F_17 ( V_2 -> V_23 , L_12 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_41 V_42 ;
V_42 . V_48 . V_54 = V_100 ;
V_17 = F_10 ( V_2 , & V_42 , V_101 ,
L_13 ) ;
return V_17 ;
}
static struct V_1 * F_20 ( int V_102 )
{
struct V_1 * V_103 , * V_2 = NULL ;
F_21 () ;
F_22 (pos, &tpm_chip_list, list) {
if ( V_102 != V_104 && V_102 != V_103 -> V_105 )
continue;
if ( F_23 ( V_103 -> V_23 -> V_106 -> V_107 ) ) {
V_2 = V_103 ;
break;
}
}
F_24 () ;
return V_2 ;
}
int F_25 ( struct V_1 * V_2 , int V_108 , T_2 * V_109 )
{
int V_17 ;
struct V_41 V_42 ;
V_42 . V_48 . V_54 = V_110 ;
V_42 . V_58 . V_111 . V_108 = F_13 ( V_108 ) ;
V_17 = F_10 ( V_2 , & V_42 , V_112 ,
L_14 ) ;
if ( V_17 == 0 )
memcpy ( V_109 , V_42 . V_58 . V_113 . V_114 ,
V_115 ) ;
return V_17 ;
}
int F_26 ( T_1 V_102 , int V_108 , T_2 * V_109 )
{
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_20 ( V_102 ) ;
if ( V_2 == NULL )
return - V_116 ;
V_17 = F_25 ( V_2 , V_108 , V_109 ) ;
F_27 ( V_2 ) ;
return V_17 ;
}
int F_28 ( T_1 V_102 , int V_108 , const T_2 * V_117 )
{
struct V_41 V_42 ;
int V_17 ;
struct V_1 * V_2 ;
V_2 = F_20 ( V_102 ) ;
if ( V_2 == NULL )
return - V_116 ;
V_42 . V_48 . V_54 = V_118 ;
V_42 . V_58 . V_119 . V_108 = F_13 ( V_108 ) ;
memcpy ( V_42 . V_58 . V_119 . V_117 , V_117 , V_115 ) ;
V_17 = F_10 ( V_2 , & V_42 , V_120 ,
L_15 ) ;
F_27 ( V_2 ) ;
return V_17 ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_17 ;
unsigned int V_121 ;
unsigned int V_122 = 100 ;
unsigned long V_6 ;
struct V_41 V_42 ;
V_6 = F_1 ( V_2 , V_123 ) ;
V_121 = F_30 ( V_6 ) / V_122 ;
V_17 = F_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
do {
V_42 . V_48 . V_54 = V_110 ;
V_42 . V_58 . V_111 . V_108 = F_13 ( 0 ) ;
V_17 = F_2 ( V_2 , ( T_2 * ) & V_42 , V_112 ) ;
if ( V_17 == - V_39 ) {
F_17 ( V_2 -> V_23 , V_124 L_16 ) ;
F_6 ( V_122 ) ;
continue;
}
if ( V_17 < V_46 )
return - V_47 ;
V_17 = F_3 ( V_42 . V_48 . V_28 . V_49 ) ;
if ( V_17 == V_125 || V_17 == V_126 ) {
F_17 ( V_2 -> V_23 ,
L_17 , V_17 ) ;
return 0 ;
}
if ( V_17 != V_127 )
return V_17 ;
F_6 ( V_122 ) ;
} while ( -- V_121 > 0 );
return V_17 ;
}
int F_31 ( T_1 V_102 , void * V_42 , T_4 V_128 )
{
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_20 ( V_102 ) ;
if ( V_2 == NULL )
return - V_116 ;
V_17 = F_10 ( V_2 , V_42 , V_128 , L_18 ) ;
F_27 ( V_2 ) ;
return V_17 ;
}
static bool F_32 ( struct V_1 * V_2 , T_2 V_129 ,
bool V_130 , bool * V_131 )
{
T_2 V_32 = V_2 -> V_26 -> V_32 ( V_2 ) ;
* V_131 = false ;
if ( ( V_32 & V_129 ) == V_129 )
return true ;
if ( V_130 && V_2 -> V_26 -> V_35 ( V_2 , V_32 ) ) {
* V_131 = true ;
return true ;
}
return false ;
}
int F_33 ( struct V_1 * V_2 , T_2 V_129 , unsigned long V_78 ,
T_7 * V_132 , bool V_130 )
{
unsigned long V_19 ;
long V_17 ;
T_2 V_32 ;
bool V_131 = false ;
V_32 = V_2 -> V_26 -> V_32 ( V_2 ) ;
if ( ( V_32 & V_129 ) == V_129 )
return 0 ;
V_19 = V_31 + V_78 ;
if ( V_2 -> V_13 . V_29 ) {
V_133:
V_78 = V_19 - V_31 ;
if ( ( long ) V_78 <= 0 )
return - V_39 ;
V_17 = F_34 ( * V_132 ,
F_32 ( V_2 , V_129 , V_130 ,
& V_131 ) ,
V_78 ) ;
if ( V_17 > 0 ) {
if ( V_131 )
return - V_36 ;
return 0 ;
}
if ( V_17 == - V_134 && F_35 ( V_135 ) ) {
F_36 ( V_136 ) ;
goto V_133;
}
} else {
do {
F_6 ( V_37 ) ;
V_32 = V_2 -> V_26 -> V_32 ( V_2 ) ;
if ( ( V_32 & V_129 ) == V_129 )
return 0 ;
} while ( F_8 ( V_31 , V_19 ) );
}
return - V_39 ;
}
void F_37 ( struct V_50 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
if ( V_2 == NULL ) {
F_4 ( V_23 , L_19 ) ;
return;
}
F_38 ( & V_137 ) ;
F_39 ( & V_2 -> V_138 ) ;
F_40 ( & V_137 ) ;
F_41 () ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_44 ( & V_23 -> V_139 ) ;
F_45 ( V_2 -> V_140 ) ;
F_46 ( V_2 -> V_23 ) ;
}
int F_47 ( struct V_50 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
struct V_41 V_42 ;
int V_17 , V_141 ;
T_2 V_142 [ V_115 ] = { 0 } ;
if ( V_2 == NULL )
return - V_116 ;
if ( V_143 ) {
V_42 . V_48 . V_54 = V_118 ;
V_42 . V_58 . V_119 . V_108 = F_13 ( V_143 ) ;
memcpy ( V_42 . V_58 . V_119 . V_117 , V_142 ,
V_115 ) ;
V_17 = F_10 ( V_2 , & V_42 , V_120 ,
L_20 ) ;
}
for ( V_141 = 0 ; V_141 < V_144 ; V_141 ++ ) {
V_42 . V_48 . V_54 = V_145 ;
V_17 = F_10 ( V_2 , & V_42 , V_146 , NULL ) ;
if ( V_17 != V_147 )
break;
F_6 ( V_148 ) ;
}
if ( V_17 )
F_4 ( V_2 -> V_23 ,
L_21 , V_17 ) ;
else if ( V_141 > 0 )
F_48 ( V_2 -> V_23 , L_22 ,
V_141 * V_148 ) ;
return V_17 ;
}
int F_49 ( struct V_50 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
if ( V_2 == NULL )
return - V_116 ;
return 0 ;
}
int F_50 ( T_1 V_102 , T_2 * V_28 , T_4 V_149 )
{
struct V_1 * V_2 ;
struct V_41 V_53 ;
T_1 V_150 , V_151 = F_51 ( T_1 , V_149 , V_152 ) ;
int V_45 , V_153 = 0 , V_154 = 5 ;
T_2 * V_155 = V_28 ;
V_2 = F_20 ( V_102 ) ;
if ( V_2 == NULL )
return - V_116 ;
if ( ! V_28 || ! V_151 || V_149 > V_152 )
return - V_82 ;
do {
V_53 . V_48 . V_54 = V_156 ;
V_53 . V_58 . V_157 . V_151 = F_13 ( V_151 ) ;
V_45 = F_10 ( V_2 , & V_53 ,
V_158 + V_151 ,
L_23 ) ;
if ( V_45 )
break;
V_150 = F_3 ( V_53 . V_58 . V_159 . V_160 ) ;
memcpy ( V_155 , V_53 . V_58 . V_159 . V_161 , V_150 ) ;
V_155 += V_150 ;
V_153 += V_150 ;
V_151 -= V_150 ;
} while ( V_154 -- && V_153 < V_149 );
return V_153 ? V_153 : - V_162 ;
}
void F_52 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_53 ( V_2 -> V_105 , V_163 ) ;
}
static void F_54 ( struct V_50 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
if ( ! V_2 )
return;
F_52 ( V_2 ) ;
V_2 -> V_164 ( V_23 ) ;
F_55 ( V_2 ) ;
}
struct V_1 * F_56 ( struct V_50 * V_23 ,
const struct V_165 * V_26 )
{
struct V_1 * V_2 ;
V_2 = F_57 ( sizeof( * V_2 ) , V_166 ) ;
if ( V_2 == NULL )
return NULL ;
F_58 ( & V_2 -> V_25 ) ;
F_59 ( & V_2 -> V_138 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_105 = F_60 ( V_163 , V_167 ) ;
if ( V_2 -> V_105 >= V_167 ) {
F_4 ( V_23 , L_24 ) ;
goto V_168;
}
F_61 ( V_2 -> V_105 , V_163 ) ;
F_62 ( V_2 -> V_169 , sizeof( V_2 -> V_169 ) , L_25 , L_26 ,
V_2 -> V_105 ) ;
V_2 -> V_23 = F_63 ( V_23 ) ;
V_2 -> V_164 = V_23 -> V_164 ;
V_23 -> V_164 = F_54 ;
F_64 ( V_23 , V_2 ) ;
if ( F_65 ( V_2 ) )
goto F_46;
if ( F_66 ( V_2 ) )
goto V_170;
if ( F_67 ( & V_23 -> V_139 ) )
goto V_170;
V_2 -> V_140 = F_68 ( V_2 -> V_169 ) ;
F_38 ( & V_137 ) ;
F_69 ( & V_2 -> V_138 , & V_171 ) ;
F_40 ( & V_137 ) ;
return V_2 ;
V_170:
F_42 ( V_2 ) ;
F_46:
F_46 ( V_2 -> V_23 ) ;
V_168:
F_55 ( V_2 ) ;
return NULL ;
}
