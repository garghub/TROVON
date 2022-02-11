static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 & ( 1 << V_3 ) )
return V_6 -> V_9 -> V_10 ( V_6 , V_3 , V_4 ) ;
return 0xffff ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_11 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 & ( 1 << V_3 ) )
return V_6 -> V_9 -> V_12 ( V_6 , V_3 , V_4 , V_11 ) ;
return 0 ;
}
void F_3 ( struct V_5 * V_6 )
{
V_6 -> V_13 -> V_7 = ( void * ) V_6 ;
V_6 -> V_13 -> V_14 = L_1 ;
V_6 -> V_13 -> V_15 = F_1 ;
V_6 -> V_13 -> V_16 = F_2 ;
snprintf ( V_6 -> V_13 -> V_17 , V_18 , L_2 ,
V_6 -> V_19 -> V_20 , V_6 -> V_21 ) ;
V_6 -> V_13 -> V_22 = V_6 -> V_23 ;
V_6 -> V_13 -> V_24 = ~ V_6 -> V_8 ;
}
static int F_4 ( const struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
return F_6 ( V_27 ) -> V_28 ;
}
static int F_7 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_29 * V_30 = V_27 -> V_30 ;
struct V_5 * V_6 = V_30 -> V_6 ;
struct V_25 * V_31 = F_6 ( V_27 ) ;
T_2 V_32 = V_30 -> V_33 ? V_34 : V_35 ;
int V_36 ;
if ( ! ( V_31 -> V_37 & V_38 ) )
return - V_39 ;
if ( ! F_8 ( V_23 -> V_40 , V_31 -> V_40 ) ) {
V_36 = F_9 ( V_31 , V_23 -> V_40 ) ;
if ( V_36 < 0 )
goto V_41;
}
if ( V_23 -> V_37 & V_42 ) {
V_36 = F_10 ( V_31 , 1 ) ;
if ( V_36 < 0 )
goto V_43;
}
if ( V_23 -> V_37 & V_44 ) {
V_36 = F_11 ( V_31 , 1 ) ;
if ( V_36 < 0 )
goto V_45;
}
if ( V_6 -> V_9 -> V_46 ) {
V_36 = V_6 -> V_9 -> V_46 ( V_6 , V_27 -> V_30 -> V_21 , V_27 -> V_47 ) ;
if ( V_36 )
goto V_48;
}
F_12 ( V_27 -> V_30 , V_32 ) ;
if ( V_27 -> V_47 )
F_13 ( V_27 -> V_47 ) ;
return 0 ;
V_48:
if ( V_23 -> V_37 & V_44 )
F_11 ( V_31 , - 1 ) ;
V_45:
if ( V_23 -> V_37 & V_42 )
F_10 ( V_31 , - 1 ) ;
V_43:
if ( ! F_8 ( V_23 -> V_40 , V_31 -> V_40 ) )
F_14 ( V_31 , V_23 -> V_40 ) ;
V_41:
return V_36 ;
}
static int F_15 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = F_6 ( V_27 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_27 -> V_47 )
F_16 ( V_27 -> V_47 ) ;
F_17 ( V_31 , V_23 ) ;
F_18 ( V_31 , V_23 ) ;
if ( V_23 -> V_37 & V_42 )
F_10 ( V_31 , - 1 ) ;
if ( V_23 -> V_37 & V_44 )
F_11 ( V_31 , - 1 ) ;
if ( ! F_8 ( V_23 -> V_40 , V_31 -> V_40 ) )
F_14 ( V_31 , V_23 -> V_40 ) ;
if ( V_6 -> V_9 -> V_49 )
V_6 -> V_9 -> V_49 ( V_6 , V_27 -> V_30 -> V_21 , V_27 -> V_47 ) ;
F_12 ( V_27 -> V_30 , V_50 ) ;
return 0 ;
}
static void F_19 ( struct V_25 * V_23 , int V_51 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = F_6 ( V_27 ) ;
if ( V_51 & V_42 )
F_10 ( V_31 , V_23 -> V_37 & V_42 ? 1 : - 1 ) ;
if ( V_51 & V_44 )
F_11 ( V_31 , V_23 -> V_37 & V_44 ? 1 : - 1 ) ;
}
static void F_20 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = F_6 ( V_27 ) ;
F_21 ( V_31 , V_23 ) ;
F_22 ( V_31 , V_23 ) ;
}
static int F_23 ( struct V_25 * V_23 , void * V_52 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = F_6 ( V_27 ) ;
struct V_53 * V_3 = V_52 ;
int V_36 ;
if ( ! F_24 ( V_3 -> V_54 ) )
return - V_55 ;
if ( ! ( V_23 -> V_37 & V_38 ) )
goto V_41;
if ( ! F_8 ( V_3 -> V_54 , V_31 -> V_40 ) ) {
V_36 = F_9 ( V_31 , V_3 -> V_54 ) ;
if ( V_36 < 0 )
return V_36 ;
}
if ( ! F_8 ( V_23 -> V_40 , V_31 -> V_40 ) )
F_14 ( V_31 , V_23 -> V_40 ) ;
V_41:
F_25 ( V_23 -> V_40 , V_3 -> V_54 ) ;
return 0 ;
}
static int
F_26 ( const unsigned char * V_3 , T_1 V_56 ,
bool V_57 , void * V_58 )
{
struct V_59 * V_60 = V_58 ;
T_3 V_61 = F_27 ( V_60 -> V_62 -> V_63 ) . V_61 ;
T_3 V_64 = V_60 -> V_62 -> V_65 -> V_66 ;
struct V_67 * V_65 ;
struct V_68 * V_69 ;
if ( V_60 -> V_70 < V_60 -> V_62 -> args [ 2 ] )
goto V_71;
V_65 = F_28 ( V_60 -> V_63 , V_61 , V_64 , V_72 ,
sizeof( * V_69 ) , V_73 ) ;
if ( ! V_65 )
return - V_74 ;
V_69 = F_29 ( V_65 ) ;
V_69 -> V_75 = V_76 ;
V_69 -> V_77 = 0 ;
V_69 -> V_78 = 0 ;
V_69 -> V_79 = V_80 ;
V_69 -> V_81 = 0 ;
V_69 -> V_82 = V_60 -> V_23 -> V_28 ;
V_69 -> V_83 = V_57 ? V_84 : V_85 ;
if ( F_30 ( V_60 -> V_63 , V_86 , V_87 , V_3 ) )
goto V_88;
if ( V_56 && F_31 ( V_60 -> V_63 , V_89 , V_56 ) )
goto V_88;
F_32 ( V_60 -> V_63 , V_65 ) ;
V_71:
V_60 -> V_70 ++ ;
return 0 ;
V_88:
F_33 ( V_60 -> V_63 , V_65 ) ;
return - V_74 ;
}
static int
F_34 ( struct V_90 * V_63 , struct V_91 * V_62 ,
struct V_25 * V_23 , struct V_25 * V_92 ,
int * V_70 )
{
struct V_59 V_60 = {
. V_23 = V_23 ,
. V_63 = V_63 ,
. V_62 = V_62 ,
. V_70 = * V_70 ,
} ;
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_29 * V_30 = V_27 -> V_30 ;
struct V_5 * V_6 = V_30 -> V_6 ;
int V_36 ;
if ( ! V_6 -> V_9 -> V_93 )
return - V_94 ;
V_36 = V_6 -> V_9 -> V_93 ( V_6 , V_30 -> V_21 ,
F_26 ,
& V_60 ) ;
* V_70 = V_60 . V_70 ;
return V_36 ;
}
static int F_35 ( struct V_25 * V_23 , struct V_95 * V_96 , int V_97 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_47 != NULL )
return F_36 ( V_27 -> V_47 , V_96 , V_97 ) ;
return - V_94 ;
}
static int F_37 ( struct V_25 * V_23 ,
const struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_29 * V_30 = V_27 -> V_30 ;
int V_102 ;
switch ( V_99 -> V_17 ) {
case V_103 :
V_102 = F_38 ( V_30 , V_99 -> V_104 . V_32 , V_101 ) ;
break;
case V_105 :
V_102 = F_39 ( V_30 , V_99 -> V_104 . V_106 ,
V_101 ) ;
break;
case V_107 :
V_102 = F_40 ( V_30 , V_99 -> V_104 . V_108 , V_101 ) ;
break;
default:
V_102 = - V_94 ;
break;
}
return V_102 ;
}
static int F_41 ( struct V_25 * V_23 ,
const struct V_109 * V_110 ,
struct V_100 * V_101 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_29 * V_30 = V_27 -> V_30 ;
int V_36 ;
switch ( V_110 -> V_17 ) {
case V_111 :
V_36 = F_42 ( V_30 , F_43 ( V_110 ) , V_101 ) ;
break;
case V_112 :
V_36 = F_44 ( V_30 , F_45 ( V_110 ) ,
V_101 ) ;
break;
default:
V_36 = - V_94 ;
break;
}
return V_36 ;
}
static int F_46 ( struct V_25 * V_23 ,
const struct V_109 * V_110 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_29 * V_30 = V_27 -> V_30 ;
int V_36 ;
switch ( V_110 -> V_17 ) {
case V_111 :
V_36 = F_47 ( V_30 , F_43 ( V_110 ) ) ;
break;
case V_112 :
V_36 = F_48 ( V_30 , F_45 ( V_110 ) ) ;
break;
default:
V_36 = - V_94 ;
break;
}
return V_36 ;
}
static int F_49 ( struct V_25 * V_23 ,
struct V_98 * V_99 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
switch ( V_99 -> V_17 ) {
case V_113 :
V_99 -> V_104 . V_114 . V_115 = sizeof( V_6 -> V_21 ) ;
memcpy ( & V_99 -> V_104 . V_114 . V_17 , & V_6 -> V_21 , V_99 -> V_104 . V_114 . V_115 ) ;
break;
case V_116 :
V_99 -> V_104 . V_117 = 0 ;
break;
default:
return - V_94 ;
}
return 0 ;
}
static inline T_4 F_50 ( struct V_26 * V_27 ,
struct V_90 * V_63 )
{
#ifdef F_51
if ( V_27 -> V_118 )
F_52 ( V_27 -> V_118 , V_63 ) ;
#else
F_53 () ;
#endif
return V_119 ;
}
static T_4 F_54 ( struct V_90 * V_63 , struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_120 * V_121 ;
struct V_90 * V_122 ;
V_121 = F_55 ( V_27 -> V_123 ) ;
F_56 ( & V_121 -> V_124 ) ;
V_121 -> V_125 ++ ;
V_121 -> V_126 += V_63 -> V_127 ;
F_57 ( & V_121 -> V_124 ) ;
V_122 = V_27 -> V_128 ( V_63 , V_23 ) ;
if ( ! V_122 ) {
F_58 ( V_63 ) ;
return V_119 ;
}
if ( F_59 ( F_60 ( V_23 ) ) )
return F_50 ( V_27 , V_122 ) ;
V_122 -> V_23 = F_6 ( V_27 ) ;
F_61 ( V_122 ) ;
return V_119 ;
}
static int
F_62 ( struct V_25 * V_23 ,
struct V_129 * V_97 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( ! V_27 -> V_47 )
return - V_94 ;
F_63 ( V_27 -> V_47 , V_97 ) ;
return 0 ;
}
static int
F_64 ( struct V_25 * V_23 ,
const struct V_129 * V_97 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_47 != NULL )
return F_65 ( V_27 -> V_47 , V_97 ) ;
return - V_94 ;
}
static void F_66 ( struct V_25 * V_23 ,
struct V_130 * V_131 )
{
F_67 ( V_131 -> V_132 , L_3 , sizeof( V_131 -> V_132 ) ) ;
F_67 ( V_131 -> V_133 , L_4 , sizeof( V_131 -> V_133 ) ) ;
F_67 ( V_131 -> V_134 , L_5 , sizeof( V_131 -> V_134 ) ) ;
}
static int F_68 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_9 -> V_135 )
return V_6 -> V_9 -> V_135 ( V_6 , V_27 -> V_30 -> V_21 ) ;
return - V_94 ;
}
static void
F_69 ( struct V_25 * V_23 , struct V_136 * V_137 , void * V_138 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_9 -> V_139 )
V_6 -> V_9 -> V_139 ( V_6 , V_27 -> V_30 -> V_21 , V_137 , V_138 ) ;
}
static int F_70 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_47 != NULL )
return F_71 ( V_27 -> V_47 ) ;
return - V_94 ;
}
static T_3 F_72 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_47 != NULL ) {
F_73 ( V_27 -> V_47 ) ;
return V_27 -> V_47 -> V_140 ;
}
return - V_94 ;
}
static int F_74 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_141 && V_6 -> V_141 -> V_142 )
return V_6 -> V_141 -> V_142 ;
if ( V_6 -> V_9 -> V_143 )
return V_6 -> V_9 -> V_143 ( V_6 ) ;
return 0 ;
}
static int F_75 ( struct V_25 * V_23 ,
struct V_144 * V_145 , T_2 * V_58 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_9 -> V_146 )
return V_6 -> V_9 -> V_146 ( V_6 , V_145 , V_58 ) ;
return - V_94 ;
}
static int F_76 ( struct V_25 * V_23 ,
struct V_144 * V_145 , T_2 * V_58 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_9 -> V_147 )
return V_6 -> V_9 -> V_147 ( V_6 , V_145 , V_58 ) ;
return - V_94 ;
}
static void F_77 ( struct V_25 * V_23 ,
T_5 V_148 , T_6 * V_58 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_148 == V_149 ) {
int V_127 = V_150 ;
strncpy ( V_58 , L_6 , V_127 ) ;
strncpy ( V_58 + V_127 , L_7 , V_127 ) ;
strncpy ( V_58 + 2 * V_127 , L_8 , V_127 ) ;
strncpy ( V_58 + 3 * V_127 , L_9 , V_127 ) ;
if ( V_6 -> V_9 -> V_151 )
V_6 -> V_9 -> V_151 ( V_6 , V_27 -> V_30 -> V_21 , V_58 + 4 * V_127 ) ;
}
}
static void F_78 ( struct V_25 * V_23 ,
struct V_152 * V_153 ,
T_7 * V_58 )
{
struct V_154 * V_19 = V_23 -> V_155 ;
struct V_29 * V_156 = F_79 ( V_19 ) ;
struct V_5 * V_6 = V_156 -> V_6 ;
T_8 V_157 = V_156 -> V_21 ;
int V_158 = 0 ;
if ( V_156 -> V_159 . V_160 ) {
V_158 = V_156 -> V_159 . V_160 ( V_23 , V_149 ) ;
V_156 -> V_159 . V_161 ( V_23 , V_153 , V_58 ) ;
}
if ( V_6 -> V_9 -> V_161 )
V_6 -> V_9 -> V_161 ( V_6 , V_157 , V_58 + V_158 ) ;
}
static int F_80 ( struct V_25 * V_23 , int V_162 )
{
struct V_154 * V_19 = V_23 -> V_155 ;
struct V_29 * V_156 = F_79 ( V_19 ) ;
struct V_5 * V_6 = V_156 -> V_6 ;
int V_158 = 0 ;
if ( V_156 -> V_159 . V_160 )
V_158 += V_156 -> V_159 . V_160 ( V_23 , V_162 ) ;
if ( V_162 == V_149 && V_6 -> V_9 -> V_160 )
V_158 += V_6 -> V_9 -> V_160 ( V_6 ) ;
return V_158 ;
}
static void F_81 ( struct V_25 * V_23 ,
T_5 V_148 , T_6 * V_58 )
{
struct V_154 * V_19 = V_23 -> V_155 ;
struct V_29 * V_156 = F_79 ( V_19 ) ;
struct V_5 * V_6 = V_156 -> V_6 ;
T_8 V_157 = V_156 -> V_21 ;
int V_127 = V_150 ;
int V_163 = 0 , V_158 ;
unsigned int V_164 ;
T_6 V_165 [ 4 ] ;
T_6 * V_166 ;
snprintf ( V_165 , sizeof( V_165 ) , L_10 , V_157 ) ;
V_165 [ sizeof( V_165 ) - 1 ] = '_' ;
if ( V_156 -> V_159 . V_160 ) {
V_163 = V_156 -> V_159 . V_160 ( V_23 , V_149 ) ;
V_156 -> V_159 . V_151 ( V_23 , V_148 , V_58 ) ;
}
if ( V_148 == V_149 && V_6 -> V_9 -> V_151 ) {
V_166 = V_58 + V_163 * V_127 ;
V_6 -> V_9 -> V_151 ( V_6 , V_157 , V_166 ) ;
V_158 = V_6 -> V_9 -> V_160 ( V_6 ) ;
for ( V_164 = 0 ; V_164 < V_158 ; V_164 ++ ) {
memmove ( V_166 + ( V_164 * V_127 + sizeof( V_165 ) ) ,
V_166 + V_164 * V_127 , V_127 - sizeof( V_165 ) ) ;
memcpy ( V_166 + V_164 * V_127 , V_165 , sizeof( V_165 ) ) ;
}
}
}
static void F_82 ( struct V_25 * V_23 ,
struct V_152 * V_153 ,
T_7 * V_58 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
struct V_120 * V_121 ;
unsigned int V_167 ;
int V_164 ;
F_83 (i) {
T_9 V_125 , V_126 , V_168 , V_169 ;
V_121 = F_84 ( V_27 -> V_123 , V_164 ) ;
do {
V_167 = F_85 ( & V_121 -> V_124 ) ;
V_125 = V_121 -> V_125 ;
V_126 = V_121 -> V_126 ;
V_168 = V_121 -> V_168 ;
V_169 = V_121 -> V_169 ;
} while ( F_86 ( & V_121 -> V_124 , V_167 ) );
V_58 [ 0 ] += V_125 ;
V_58 [ 1 ] += V_126 ;
V_58 [ 2 ] += V_168 ;
V_58 [ 3 ] += V_169 ;
}
if ( V_6 -> V_9 -> V_161 )
V_6 -> V_9 -> V_161 ( V_6 , V_27 -> V_30 -> V_21 , V_58 + 4 ) ;
}
static int F_87 ( struct V_25 * V_23 , int V_162 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_162 == V_149 ) {
int V_158 ;
V_158 = 4 ;
if ( V_6 -> V_9 -> V_160 )
V_158 += V_6 -> V_9 -> V_160 ( V_6 ) ;
return V_158 ;
}
return - V_94 ;
}
static void F_88 ( struct V_25 * V_23 , struct V_170 * V_171 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_9 -> V_172 )
V_6 -> V_9 -> V_172 ( V_6 , V_27 -> V_30 -> V_21 , V_171 ) ;
}
static int F_89 ( struct V_25 * V_23 , struct V_170 * V_171 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
int V_102 = - V_94 ;
if ( V_6 -> V_9 -> V_173 )
V_102 = V_6 -> V_9 -> V_173 ( V_6 , V_27 -> V_30 -> V_21 , V_171 ) ;
return V_102 ;
}
static int F_90 ( struct V_25 * V_23 , struct V_174 * V_175 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
int V_102 ;
if ( ! V_27 -> V_47 )
return - V_176 ;
if ( ! V_6 -> V_9 -> V_177 )
return - V_94 ;
V_102 = V_6 -> V_9 -> V_177 ( V_6 , V_27 -> V_30 -> V_21 , V_175 ) ;
if ( V_102 )
return V_102 ;
if ( V_175 -> V_178 ) {
V_102 = F_91 ( V_27 -> V_47 , 0 ) ;
if ( V_102 )
return V_102 ;
}
return F_92 ( V_27 -> V_47 , V_175 ) ;
}
static int F_93 ( struct V_25 * V_23 , struct V_174 * V_175 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
int V_102 ;
if ( ! V_27 -> V_47 )
return - V_176 ;
if ( ! V_6 -> V_9 -> V_179 )
return - V_94 ;
V_102 = V_6 -> V_9 -> V_179 ( V_6 , V_27 -> V_30 -> V_21 , V_175 ) ;
if ( V_102 )
return V_102 ;
return F_94 ( V_27 -> V_47 , V_175 ) ;
}
static int F_95 ( struct V_25 * V_23 ,
struct V_180 * V_181 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = F_6 ( V_27 ) ;
struct V_118 * V_118 ;
int V_36 = 0 ;
V_118 = F_96 ( sizeof( * V_118 ) , V_182 ) ;
if ( ! V_118 )
return - V_183 ;
V_36 = F_97 ( V_118 , V_31 ) ;
if ( V_36 ) {
F_98 ( V_118 ) ;
goto V_41;
}
V_27 -> V_118 = V_118 ;
V_41:
return V_36 ;
}
static void F_99 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_118 * V_118 = V_27 -> V_118 ;
if ( ! V_118 )
return;
V_27 -> V_118 = NULL ;
F_100 ( V_118 ) ;
}
static void F_101 ( struct V_25 * V_23 )
{
}
static int F_102 ( struct V_25 * V_23 ,
char * V_14 , T_10 V_127 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( snprintf ( V_14 , V_127 , L_11 , V_27 -> V_30 -> V_21 ) >= V_127 )
return - V_184 ;
return 0 ;
}
static struct V_185 *
F_103 ( struct V_26 * V_27 ,
unsigned long V_186 )
{
struct V_185 * V_187 ;
F_104 (mall_tc_entry, &p->mall_tc_list, list)
if ( V_187 -> V_186 == V_186 )
return V_187 ;
return NULL ;
}
static int F_105 ( struct V_25 * V_23 ,
struct V_188 * V_189 ,
bool V_190 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_185 * V_187 ;
T_11 V_191 = V_189 -> V_192 . V_191 ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
struct V_193 * V_193 = F_106 ( V_23 ) ;
struct V_26 * V_194 ;
struct V_25 * V_195 ;
const struct V_196 * V_52 ;
int V_36 = - V_94 ;
F_107 ( V_197 ) ;
int V_28 ;
if ( ! V_6 -> V_9 -> V_198 )
return V_36 ;
if ( ! F_108 ( V_189 -> V_199 ) )
return V_36 ;
F_109 ( V_189 -> V_199 , & V_197 ) ;
V_52 = F_110 ( & V_197 , struct V_196 , V_200 ) ;
if ( F_111 ( V_52 ) && V_191 == F_112 ( V_201 ) ) {
struct V_202 * V_203 ;
V_28 = F_113 ( V_52 ) ;
V_195 = F_114 ( V_193 , V_28 ) ;
if ( ! V_195 )
return - V_184 ;
if ( ! F_115 ( V_195 ) )
return - V_94 ;
V_187 = F_96 ( sizeof( * V_187 ) , V_182 ) ;
if ( ! V_187 )
return - V_183 ;
V_187 -> V_186 = V_189 -> V_186 ;
V_187 -> type = V_204 ;
V_203 = & V_187 -> V_203 ;
V_194 = F_5 ( V_195 ) ;
V_203 -> V_205 = V_194 -> V_30 -> V_21 ;
V_203 -> V_190 = V_190 ;
V_36 = V_6 -> V_9 -> V_198 ( V_6 , V_27 -> V_30 -> V_21 , V_203 ,
V_190 ) ;
if ( V_36 ) {
F_98 ( V_187 ) ;
return V_36 ;
}
F_116 ( & V_187 -> V_200 , & V_27 -> V_206 ) ;
}
return 0 ;
}
static void F_117 ( struct V_25 * V_23 ,
struct V_188 * V_189 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_185 * V_187 ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( ! V_6 -> V_9 -> V_207 )
return;
V_187 = F_103 ( V_27 , V_189 -> V_186 ) ;
if ( ! V_187 )
return;
F_118 ( & V_187 -> V_200 ) ;
switch ( V_187 -> type ) {
case V_204 :
V_6 -> V_9 -> V_207 ( V_6 , V_27 -> V_30 -> V_21 ,
& V_187 -> V_203 ) ;
break;
default:
F_119 ( 1 ) ;
}
F_98 ( V_187 ) ;
}
static int F_120 ( struct V_25 * V_23 ,
struct V_188 * V_189 )
{
bool V_190 ;
if ( F_121 ( V_189 -> V_192 . V_208 ) )
V_190 = true ;
else if ( F_122 ( V_189 -> V_192 . V_208 ) )
V_190 = false ;
else
return - V_94 ;
if ( V_189 -> V_192 . V_209 )
return - V_94 ;
switch ( V_189 -> V_210 ) {
case V_211 :
return F_105 ( V_23 , V_189 , V_190 ) ;
case V_212 :
F_117 ( V_23 , V_189 ) ;
return 0 ;
default:
return - V_94 ;
}
}
static int F_123 ( struct V_25 * V_23 , enum V_213 type ,
void * V_214 )
{
switch ( type ) {
case V_215 :
return F_120 ( V_23 , V_214 ) ;
default:
return - V_94 ;
}
}
static void F_124 ( struct V_25 * V_23 ,
struct V_216 * V_153 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_120 * V_121 ;
unsigned int V_167 ;
int V_164 ;
F_125 ( V_153 , & V_23 -> V_153 ) ;
F_83 (i) {
T_9 V_125 , V_126 , V_168 , V_169 ;
V_121 = F_84 ( V_27 -> V_123 , V_164 ) ;
do {
V_167 = F_85 ( & V_121 -> V_124 ) ;
V_125 = V_121 -> V_125 ;
V_126 = V_121 -> V_126 ;
V_168 = V_121 -> V_168 ;
V_169 = V_121 -> V_169 ;
} while ( F_86 ( & V_121 -> V_124 , V_167 ) );
V_153 -> V_125 += V_125 ;
V_153 -> V_126 += V_126 ;
V_153 -> V_168 += V_168 ;
V_153 -> V_169 += V_169 ;
}
}
void F_126 ( struct V_159 * V_9 )
{
V_9 -> V_160 = F_80 ;
V_9 -> V_161 = F_78 ;
V_9 -> V_151 = F_81 ;
}
static int F_127 ( struct V_25 * V_23 ,
struct V_217 * V_218 , T_3 * V_219 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( ! V_6 -> V_9 -> V_220 )
return - V_94 ;
return V_6 -> V_9 -> V_220 ( V_6 , V_27 -> V_30 -> V_21 , V_218 , V_219 ) ;
}
static int F_128 ( struct V_25 * V_23 ,
struct V_217 * V_218 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( ! V_6 -> V_9 -> V_221 )
return - V_94 ;
return V_6 -> V_9 -> V_221 ( V_6 , V_27 -> V_30 -> V_21 , V_218 ) ;
}
static void F_129 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
unsigned int V_222 = 0 ;
if ( V_27 -> V_223 != V_27 -> V_47 -> V_140 ) {
V_222 = 1 ;
V_27 -> V_223 = V_27 -> V_47 -> V_140 ;
}
if ( V_27 -> V_224 != V_27 -> V_47 -> V_225 ) {
V_222 = 1 ;
V_27 -> V_224 = V_27 -> V_47 -> V_225 ;
}
if ( V_27 -> V_226 != V_27 -> V_47 -> V_227 ) {
V_222 = 1 ;
V_27 -> V_226 = V_27 -> V_47 -> V_227 ;
}
if ( V_6 -> V_9 -> V_228 && V_222 )
V_6 -> V_9 -> V_228 ( V_6 , V_27 -> V_30 -> V_21 , V_27 -> V_47 ) ;
if ( V_222 )
F_130 ( V_27 -> V_47 ) ;
}
static int F_131 ( struct V_25 * V_23 ,
struct V_229 * V_230 )
{
struct V_26 * V_27 ;
struct V_5 * V_6 ;
if ( V_23 ) {
V_27 = F_5 ( V_23 ) ;
V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_9 -> V_231 )
V_6 -> V_9 -> V_231 ( V_6 , V_27 -> V_30 -> V_21 , V_230 ) ;
}
return 0 ;
}
static int F_132 ( struct V_26 * V_27 ,
struct V_25 * V_232 ,
int V_3 )
{
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
V_27 -> V_47 = F_133 ( V_6 -> V_13 , V_3 ) ;
if ( ! V_27 -> V_47 ) {
F_134 ( V_232 , L_12 , V_3 ) ;
return - V_176 ;
}
if ( V_27 -> V_233 == V_234 )
V_27 -> V_233 = V_27 -> V_47 -> V_235 ;
return F_135 ( V_232 , V_27 -> V_47 , F_129 ,
V_27 -> V_233 ) ;
}
static int F_136 ( struct V_26 * V_27 ,
struct V_25 * V_232 )
{
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
struct V_236 * V_237 , * V_238 ;
bool V_239 = false ;
T_3 V_240 = 0 ;
int V_241 , V_102 ;
V_238 = V_27 -> V_30 -> V_242 ;
V_241 = F_137 ( V_238 ) ;
if ( V_241 < 0 )
V_241 = V_234 ;
V_27 -> V_233 = V_241 ;
V_237 = F_138 ( V_238 , L_13 , 0 ) ;
if ( ! V_237 && F_139 ( V_238 ) ) {
V_102 = F_140 ( V_238 ) ;
if ( V_102 ) {
F_134 ( V_232 , L_14 , V_102 ) ;
return V_102 ;
}
V_239 = true ;
V_237 = F_141 ( V_238 ) ;
}
if ( V_6 -> V_9 -> V_243 )
V_240 = V_6 -> V_9 -> V_243 ( V_6 , V_27 -> V_30 -> V_21 ) ;
if ( V_237 ) {
int V_244 = F_142 ( & V_232 -> V_23 , V_237 ) ;
if ( ! V_239 && V_244 >= 0 &&
( V_6 -> V_8 & ( 1 << V_244 ) ) ) {
V_102 = F_132 ( V_27 , V_232 , V_244 ) ;
if ( V_102 ) {
F_134 ( V_232 , L_15 , V_244 , V_102 ) ;
F_143 ( V_237 ) ;
return V_102 ;
}
} else {
V_27 -> V_47 = F_144 ( V_232 , V_237 ,
F_129 ,
V_240 ,
V_27 -> V_233 ) ;
}
F_143 ( V_237 ) ;
}
if ( V_27 -> V_47 && V_239 )
F_145 ( V_27 -> V_47 , F_131 ) ;
if ( ! V_27 -> V_47 ) {
V_102 = F_132 ( V_27 , V_232 , V_27 -> V_30 -> V_21 ) ;
if ( V_102 ) {
F_134 ( V_232 , L_16 ,
V_27 -> V_30 -> V_21 , V_102 ) ;
if ( V_239 )
F_146 ( V_238 ) ;
return V_102 ;
}
}
F_147 ( V_27 -> V_47 ) ;
return 0 ;
}
static void F_148 ( struct V_25 * V_23 ,
struct V_245 * V_246 ,
void * V_247 )
{
F_149 ( & V_246 -> V_248 ,
& V_249 ) ;
}
int F_150 ( struct V_25 * V_232 )
{
struct V_26 * V_27 = F_5 ( V_232 ) ;
F_151 ( V_232 ) ;
if ( V_27 -> V_47 ) {
F_16 ( V_27 -> V_47 ) ;
V_27 -> V_226 = - 1 ;
V_27 -> V_223 = - 1 ;
V_27 -> V_224 = - 1 ;
F_152 ( V_27 -> V_47 ) ;
}
return 0 ;
}
int F_153 ( struct V_25 * V_232 )
{
struct V_26 * V_27 = F_5 ( V_232 ) ;
F_154 ( V_232 ) ;
if ( V_27 -> V_47 ) {
F_155 ( V_27 -> V_47 ) ;
F_13 ( V_27 -> V_47 ) ;
}
return 0 ;
}
int F_156 ( struct V_29 * V_250 , const char * V_14 )
{
struct V_5 * V_6 = V_250 -> V_6 ;
struct V_154 * V_19 = V_6 -> V_19 ;
struct V_25 * V_31 ;
struct V_25 * V_232 ;
struct V_26 * V_27 ;
struct V_29 * V_156 ;
int V_102 ;
V_156 = V_6 -> V_19 -> V_156 ;
V_31 = V_156 -> V_251 ;
if ( ! V_6 -> V_252 )
V_6 -> V_252 = 1 ;
V_232 = F_157 ( sizeof( struct V_26 ) , V_14 ,
V_253 , V_254 ,
V_6 -> V_252 , 1 ) ;
if ( V_232 == NULL )
return - V_183 ;
V_232 -> V_255 = V_31 -> V_256 | V_257 ;
V_232 -> V_258 |= V_257 ;
V_232 -> V_159 = & V_259 ;
F_158 ( V_232 , V_31 ) ;
V_232 -> V_260 |= V_261 ;
V_232 -> V_262 = & V_263 ;
V_232 -> V_264 = & V_265 ;
V_232 -> V_266 = 0 ;
V_232 -> V_267 = V_268 ;
F_159 ( V_232 , & V_269 ) ;
F_160 ( V_232 , F_148 ,
NULL ) ;
F_161 ( V_232 , V_250 -> V_6 -> V_23 ) ;
V_232 -> V_23 . V_270 = V_250 -> V_242 ;
V_232 -> V_256 = V_31 -> V_256 ;
V_27 = F_5 ( V_232 ) ;
V_27 -> V_123 = F_162 ( struct V_120 ) ;
if ( ! V_27 -> V_123 ) {
F_163 ( V_232 ) ;
return - V_183 ;
}
V_27 -> V_30 = V_250 ;
F_164 ( & V_27 -> V_206 ) ;
V_27 -> V_128 = V_19 -> V_271 -> V_128 ;
V_27 -> V_226 = - 1 ;
V_27 -> V_223 = - 1 ;
V_27 -> V_224 = - 1 ;
V_250 -> V_251 = V_232 ;
F_165 ( V_232 ) ;
V_102 = F_136 ( V_27 , V_232 ) ;
if ( V_102 ) {
F_134 ( V_31 , L_17 , V_102 ) ;
goto V_272;
}
V_102 = F_166 ( V_232 ) ;
if ( V_102 ) {
F_134 ( V_31 , L_18 ,
V_102 , V_232 -> V_14 ) ;
goto V_273;
}
return 0 ;
V_273:
F_167 ( V_27 -> V_47 ) ;
if ( F_139 ( V_27 -> V_30 -> V_242 ) )
F_146 ( V_27 -> V_30 -> V_242 ) ;
V_272:
F_168 ( V_27 -> V_123 ) ;
F_163 ( V_232 ) ;
V_250 -> V_251 = NULL ;
return V_102 ;
}
void F_169 ( struct V_25 * V_232 )
{
struct V_26 * V_27 = F_5 ( V_232 ) ;
struct V_236 * V_238 ;
V_238 = V_27 -> V_30 -> V_242 ;
F_165 ( V_232 ) ;
if ( V_27 -> V_47 ) {
F_167 ( V_27 -> V_47 ) ;
if ( F_139 ( V_238 ) )
F_146 ( V_238 ) ;
}
F_170 ( V_232 ) ;
F_168 ( V_27 -> V_123 ) ;
F_163 ( V_232 ) ;
}
static bool F_115 ( struct V_25 * V_23 )
{
return V_23 -> V_262 == & V_263 ;
}
static int F_171 ( struct V_25 * V_23 ,
struct V_274 * V_275 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_29 * V_30 = V_27 -> V_30 ;
int V_36 = V_276 ;
if ( F_172 ( V_275 -> V_277 ) ) {
if ( V_275 -> V_278 ) {
V_36 = F_173 ( V_30 , V_275 -> V_277 ) ;
V_36 = F_174 ( V_36 ) ;
} else {
F_175 ( V_30 , V_275 -> V_277 ) ;
V_36 = V_279 ;
}
}
return V_36 ;
}
static int F_176 ( struct V_280 * V_281 ,
unsigned long V_282 , void * V_283 )
{
struct V_25 * V_23 = F_177 ( V_283 ) ;
if ( V_23 -> V_262 != & V_263 )
return V_276 ;
if ( V_282 == V_284 )
return F_171 ( V_23 , V_283 ) ;
return V_276 ;
}
static void F_178 ( struct V_285 * V_286 )
{
struct V_287 * V_288 =
F_179 ( V_286 , struct V_287 , V_286 ) ;
struct V_25 * V_23 = V_288 -> V_23 ;
struct V_289 * V_290 ;
struct V_26 * V_27 = F_5 ( V_23 ) ;
int V_36 ;
F_180 () ;
switch ( V_288 -> V_282 ) {
case V_291 :
V_290 = & V_288 -> V_290 ;
V_36 = F_181 ( V_27 -> V_30 , V_290 -> V_3 , V_290 -> V_56 ) ;
if ( V_36 ) {
F_182 ( V_23 , L_19 , V_36 ) ;
break;
}
F_183 ( V_292 , V_23 ,
& V_290 -> V_275 ) ;
break;
case V_293 :
V_290 = & V_288 -> V_290 ;
V_36 = F_184 ( V_27 -> V_30 , V_290 -> V_3 , V_290 -> V_56 ) ;
if ( V_36 ) {
F_182 ( V_23 , L_20 , V_36 ) ;
F_185 ( V_23 ) ;
}
break;
}
F_186 () ;
F_98 ( V_288 -> V_290 . V_3 ) ;
F_98 ( V_288 ) ;
F_187 ( V_23 ) ;
}
static int
F_188 ( struct V_287 *
V_288 ,
const struct V_289 *
V_290 )
{
memcpy ( & V_288 -> V_290 , V_290 ,
sizeof( V_288 -> V_290 ) ) ;
V_288 -> V_290 . V_3 = F_96 ( V_87 , V_294 ) ;
if ( ! V_288 -> V_290 . V_3 )
return - V_183 ;
F_25 ( ( T_2 * ) V_288 -> V_290 . V_3 ,
V_290 -> V_3 ) ;
return 0 ;
}
static int F_189 ( struct V_280 * V_295 ,
unsigned long V_282 , void * V_283 )
{
struct V_25 * V_23 = F_190 ( V_283 ) ;
struct V_287 * V_288 ;
if ( ! F_115 ( V_23 ) )
return V_276 ;
V_288 = F_96 ( sizeof( * V_288 ) , V_294 ) ;
if ( ! V_288 )
return V_296 ;
F_191 ( & V_288 -> V_286 ,
F_178 ) ;
V_288 -> V_23 = V_23 ;
V_288 -> V_282 = V_282 ;
switch ( V_282 ) {
case V_291 :
case V_293 :
if ( F_188 ( V_288 ,
V_283 ) )
goto V_297;
F_192 ( V_23 ) ;
break;
default:
F_98 ( V_288 ) ;
return V_276 ;
}
F_193 ( & V_288 -> V_286 ) ;
return V_279 ;
V_297:
F_98 ( V_288 ) ;
return V_296 ;
}
int F_194 ( void )
{
int V_36 ;
V_36 = F_195 ( & V_298 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_196 ( & V_299 ) ;
if ( V_36 )
goto V_300;
return 0 ;
V_300:
F_197 ( & V_298 ) ;
return V_36 ;
}
void F_198 ( void )
{
int V_36 ;
V_36 = F_199 ( & V_299 ) ;
if ( V_36 )
F_200 ( L_21 , V_36 ) ;
V_36 = F_197 ( & V_298 ) ;
if ( V_36 )
F_200 ( L_22 , V_36 ) ;
}
