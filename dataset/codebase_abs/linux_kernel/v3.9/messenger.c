static bool F_1 ( unsigned long V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
return true ;
default:
return false ;
}
}
static void F_2 ( struct V_7 * V_8 , unsigned long V_1 )
{
F_3 ( ! F_1 ( V_1 ) ) ;
F_4 ( V_1 , & V_8 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_8 , unsigned long V_1 )
{
F_3 ( ! F_1 ( V_1 ) ) ;
F_6 ( V_1 , & V_8 -> V_9 ) ;
}
static bool F_7 ( struct V_7 * V_8 , unsigned long V_1 )
{
F_3 ( ! F_1 ( V_1 ) ) ;
return F_8 ( V_1 , & V_8 -> V_9 ) ;
}
static bool F_9 ( struct V_7 * V_8 ,
unsigned long V_1 )
{
F_3 ( ! F_1 ( V_1 ) ) ;
return F_10 ( V_1 , & V_8 -> V_9 ) ;
}
static bool F_11 ( struct V_7 * V_8 ,
unsigned long V_1 )
{
F_3 ( ! F_1 ( V_1 ) ) ;
return F_12 ( V_1 , & V_8 -> V_9 ) ;
}
const char * F_13 ( const struct V_10 * V_11 )
{
int V_12 ;
char * V_13 ;
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
V_12 = F_14 ( & V_18 ) & V_19 ;
V_13 = V_20 [ V_12 ] ;
switch ( V_11 -> V_21 ) {
case V_22 :
snprintf ( V_13 , V_23 , L_1 , & V_15 -> V_24 ,
F_15 ( V_15 -> V_25 ) ) ;
break;
case V_26 :
snprintf ( V_13 , V_23 , L_2 , & V_17 -> V_27 ,
F_15 ( V_17 -> V_28 ) ) ;
break;
default:
snprintf ( V_13 , V_23 , L_3 ,
V_11 -> V_21 ) ;
}
return V_13 ;
}
static void F_16 ( struct V_29 * V_30 )
{
memcpy ( & V_30 -> V_31 , & V_30 -> V_32 . V_33 , sizeof( V_30 -> V_31 ) ) ;
F_17 ( & V_30 -> V_31 ) ;
}
static void F_18 ( void )
{
if ( V_34 ) {
F_19 ( V_34 ) ;
V_34 = NULL ;
}
F_3 ( V_35 == NULL ) ;
F_20 ( V_35 ) ;
F_21 ( V_35 ) ;
V_35 = NULL ;
}
int F_22 ( void )
{
F_3 ( V_35 != NULL ) ;
V_35 = F_23 ( 0 ) ;
F_24 ( V_35 ) ;
V_34 = F_25 ( L_4 , V_36 , 0 ) ;
if ( V_34 )
return 0 ;
F_26 ( L_5 ) ;
F_18 () ;
return - V_37 ;
}
void F_27 ( void )
{
F_3 ( V_34 == NULL ) ;
F_18 () ;
}
void F_28 ( void )
{
F_29 ( V_34 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
int V_38 ;
V_38 = F_31 ( & V_8 -> V_39 , V_40 ) ;
if ( F_32 ( V_38 != V_41 ) )
F_33 ( L_6 , V_42 , V_38 ) ;
F_34 ( L_7 , V_42 , V_8 , V_38 ,
V_40 ) ;
}
static void F_35 ( struct V_7 * V_8 )
{
int V_38 ;
V_38 = F_31 ( & V_8 -> V_39 , V_43 ) ;
if ( F_32 ( V_38 != V_40 ) )
F_33 ( L_6 , V_42 , V_38 ) ;
F_34 ( L_7 , V_42 , V_8 , V_38 ,
V_43 ) ;
}
static void F_36 ( struct V_7 * V_8 )
{
int V_38 ;
V_38 = F_31 ( & V_8 -> V_39 , V_44 ) ;
if ( F_32 ( V_38 != V_43 ) )
F_33 ( L_6 , V_42 , V_38 ) ;
F_34 ( L_7 , V_42 , V_8 , V_38 ,
V_44 ) ;
}
static void F_37 ( struct V_7 * V_8 )
{
int V_38 ;
V_38 = F_31 ( & V_8 -> V_39 , V_45 ) ;
if ( F_32 ( V_38 != V_43 &&
V_38 != V_44 &&
V_38 != V_45 ) )
F_33 ( L_6 , V_42 , V_38 ) ;
F_34 ( L_7 , V_42 , V_8 , V_38 ,
V_45 ) ;
}
static void F_38 ( struct V_7 * V_8 )
{
int V_38 ;
V_38 = F_31 ( & V_8 -> V_39 , V_40 ) ;
if ( F_32 ( V_38 != V_44 &&
V_38 != V_45 &&
V_38 != V_43 &&
V_38 != V_40 ) )
F_33 ( L_6 , V_42 , V_38 ) ;
F_34 ( L_7 , V_42 , V_8 , V_38 ,
V_40 ) ;
}
static void F_39 ( struct V_46 * V_47 , int V_48 )
{
struct V_7 * V_8 = V_47 -> V_49 ;
if ( F_40 ( & V_8 -> V_30 -> V_50 ) ) {
return;
}
if ( V_47 -> V_51 != V_52 ) {
F_34 ( L_8 , V_42 ,
V_8 , V_8 -> V_53 ) ;
F_41 ( V_8 ) ;
}
}
static void F_42 ( struct V_46 * V_47 )
{
struct V_7 * V_8 = V_47 -> V_49 ;
if ( F_7 ( V_8 , V_4 ) ) {
if ( F_43 ( V_47 ) >= F_44 ( V_47 ) ) {
F_34 ( L_9 , V_42 , V_8 ) ;
F_4 ( V_54 , & V_47 -> V_55 -> V_9 ) ;
F_41 ( V_8 ) ;
}
} else {
F_34 ( L_10 , V_42 , V_8 ) ;
}
}
static void F_45 ( struct V_46 * V_47 )
{
struct V_7 * V_8 = V_47 -> V_49 ;
F_34 ( L_11 , V_42 ,
V_8 , V_8 -> V_53 , V_47 -> V_51 ) ;
switch ( V_47 -> V_51 ) {
case V_56 :
F_34 ( L_12 , V_42 ) ;
case V_52 :
F_34 ( L_13 , V_42 ) ;
F_37 ( V_8 ) ;
F_5 ( V_8 , V_5 ) ;
F_41 ( V_8 ) ;
break;
case V_57 :
F_34 ( L_14 , V_42 ) ;
F_36 ( V_8 ) ;
F_41 ( V_8 ) ;
break;
default:
break;
}
}
static void F_46 ( struct V_58 * V_46 ,
struct V_7 * V_8 )
{
struct V_46 * V_47 = V_46 -> V_47 ;
V_47 -> V_49 = V_8 ;
V_47 -> V_59 = F_39 ;
V_47 -> V_60 = F_42 ;
V_47 -> V_61 = F_45 ;
}
static int F_47 ( struct V_7 * V_8 )
{
struct V_10 * V_62 = & V_8 -> V_63 . V_64 ;
struct V_58 * V_46 ;
int V_65 ;
F_3 ( V_8 -> V_46 ) ;
V_65 = F_48 ( V_8 -> V_63 . V_64 . V_21 , V_66 ,
V_67 , & V_46 ) ;
if ( V_65 )
return V_65 ;
V_46 -> V_47 -> V_68 = V_69 ;
#ifdef F_49
F_50 ( & V_46 -> V_47 -> V_70 , & V_71 ) ;
#endif
F_46 ( V_46 , V_8 ) ;
F_34 ( L_15 , F_13 ( & V_8 -> V_63 . V_64 ) ) ;
F_35 ( V_8 ) ;
V_65 = V_46 -> V_72 -> V_73 ( V_46 , (struct V_74 * ) V_62 , sizeof( * V_62 ) ,
V_75 ) ;
if ( V_65 == - V_76 ) {
F_34 ( L_16 ,
F_13 ( & V_8 -> V_63 . V_64 ) ,
V_46 -> V_47 -> V_51 ) ;
} else if ( V_65 < 0 ) {
F_26 ( L_17 ,
F_13 ( & V_8 -> V_63 . V_64 ) , V_65 ) ;
F_51 ( V_46 ) ;
V_8 -> V_77 = L_18 ;
return V_65 ;
}
V_8 -> V_46 = V_46 ;
return 0 ;
}
static int F_52 ( struct V_58 * V_46 , void * V_78 , T_1 V_79 )
{
struct V_80 V_81 = { V_78 , V_79 } ;
struct V_82 V_83 = { . V_84 = V_85 | V_86 } ;
int V_87 ;
V_87 = F_53 ( V_46 , & V_83 , & V_81 , 1 , V_79 , V_83 . V_84 ) ;
if ( V_87 == - V_88 )
V_87 = 0 ;
return V_87 ;
}
static int F_54 ( struct V_58 * V_46 , struct V_80 * V_81 ,
T_1 V_89 , T_1 V_79 , int V_90 )
{
struct V_82 V_83 = { . V_84 = V_85 | V_86 } ;
int V_87 ;
if ( V_90 )
V_83 . V_84 |= V_91 ;
else
V_83 . V_84 |= V_92 ;
V_87 = F_55 ( V_46 , & V_83 , V_81 , V_89 , V_79 ) ;
if ( V_87 == - V_88 )
V_87 = 0 ;
return V_87 ;
}
static int F_56 ( struct V_58 * V_46 , struct V_93 * V_93 ,
int V_94 , T_1 V_95 , int V_90 )
{
int V_9 = V_85 | V_86 | ( V_90 ? V_91 : V_92 ) ;
int V_65 ;
V_65 = F_57 ( V_46 , V_93 , V_94 , V_95 , V_9 ) ;
if ( V_65 == - V_88 )
V_65 = 0 ;
return V_65 ;
}
static int F_58 ( struct V_7 * V_8 )
{
int V_96 = 0 ;
F_34 ( L_19 , V_8 , V_8 -> V_46 ) ;
if ( V_8 -> V_46 ) {
V_96 = V_8 -> V_46 -> V_72 -> V_97 ( V_8 -> V_46 , V_98 ) ;
F_51 ( V_8 -> V_46 ) ;
V_8 -> V_46 = NULL ;
}
F_2 ( V_8 , V_5 ) ;
F_38 ( V_8 ) ;
return V_96 ;
}
static void F_59 ( struct V_99 * V_83 )
{
F_60 ( & V_83 -> V_100 ) ;
F_3 ( V_83 -> V_8 == NULL ) ;
V_83 -> V_8 -> V_72 -> V_101 ( V_83 -> V_8 ) ;
V_83 -> V_8 = NULL ;
F_61 ( V_83 ) ;
}
static void F_62 ( struct V_100 * V_102 )
{
while ( ! F_63 ( V_102 ) ) {
struct V_99 * V_83 = F_64 ( V_102 , struct V_99 ,
V_100 ) ;
F_59 ( V_83 ) ;
}
}
static void F_65 ( struct V_7 * V_8 )
{
F_34 ( L_20 , V_8 ) ;
F_62 ( & V_8 -> V_103 ) ;
F_62 ( & V_8 -> V_104 ) ;
if ( V_8 -> V_105 ) {
F_3 ( V_8 -> V_105 -> V_8 != V_8 ) ;
V_8 -> V_105 -> V_8 = NULL ;
F_61 ( V_8 -> V_105 ) ;
V_8 -> V_105 = NULL ;
V_8 -> V_72 -> V_101 ( V_8 ) ;
}
V_8 -> V_106 = 0 ;
V_8 -> V_107 = 0 ;
if ( V_8 -> V_108 ) {
F_61 ( V_8 -> V_108 ) ;
V_8 -> V_108 = NULL ;
}
V_8 -> V_109 = 0 ;
V_8 -> V_110 = 0 ;
}
void F_66 ( struct V_7 * V_8 )
{
F_67 ( & V_8 -> V_111 ) ;
F_34 ( L_21 , V_8 ,
F_13 ( & V_8 -> V_63 . V_64 ) ) ;
V_8 -> V_53 = V_112 ;
F_2 ( V_8 , V_2 ) ;
F_2 ( V_8 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_2 ( V_8 , V_6 ) ;
F_65 ( V_8 ) ;
V_8 -> V_113 = 0 ;
F_68 ( & V_8 -> V_114 ) ;
F_58 ( V_8 ) ;
F_69 ( & V_8 -> V_111 ) ;
}
void F_70 ( struct V_7 * V_8 ,
T_2 V_115 , T_3 V_116 ,
struct V_117 * V_33 )
{
F_67 ( & V_8 -> V_111 ) ;
F_34 ( L_22 , V_8 , F_13 ( & V_33 -> V_64 ) ) ;
F_32 ( V_8 -> V_53 != V_112 ) ;
V_8 -> V_53 = V_118 ;
V_8 -> V_119 . type = ( T_2 ) V_115 ;
V_8 -> V_119 . V_120 = F_71 ( V_116 ) ;
memcpy ( & V_8 -> V_63 , V_33 , sizeof( * V_33 ) ) ;
V_8 -> V_121 = 0 ;
F_69 ( & V_8 -> V_111 ) ;
F_41 ( V_8 ) ;
}
bool F_72 ( struct V_7 * V_8 )
{
return V_8 -> V_106 > 0 ;
}
void F_73 ( struct V_7 * V_8 , void * V_122 ,
const struct V_123 * V_72 ,
struct V_29 * V_30 )
{
F_34 ( L_23 , V_8 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_122 = V_122 ;
V_8 -> V_72 = V_72 ;
V_8 -> V_30 = V_30 ;
F_30 ( V_8 ) ;
F_74 ( & V_8 -> V_111 ) ;
F_75 ( & V_8 -> V_103 ) ;
F_75 ( & V_8 -> V_104 ) ;
F_76 ( & V_8 -> V_114 , V_124 ) ;
V_8 -> V_53 = V_112 ;
}
static T_4 F_77 ( struct V_29 * V_30 , T_4 V_125 )
{
T_4 V_65 ;
F_78 ( & V_30 -> V_126 ) ;
if ( V_30 -> V_127 < V_125 )
V_30 -> V_127 = V_125 ;
V_65 = ++ V_30 -> V_127 ;
F_79 ( & V_30 -> V_126 ) ;
return V_65 ;
}
static void F_80 ( struct V_7 * V_8 )
{
V_8 -> V_128 = 0 ;
V_8 -> V_129 = 0 ;
V_8 -> V_130 = & V_8 -> V_131 [ 0 ] ;
}
static void F_81 ( struct V_7 * V_8 ,
T_1 V_95 , void * V_132 )
{
int V_133 ;
V_133 = V_8 -> V_128 ;
F_3 ( V_133 >= F_82 ( V_8 -> V_131 ) ) ;
V_8 -> V_131 [ V_133 ] . V_134 = V_95 ;
V_8 -> V_131 [ V_133 ] . V_135 = V_132 ;
V_8 -> V_128 ++ ;
V_8 -> V_129 += V_95 ;
}
static void F_83 ( struct V_136 * V_136 , struct V_136 * * V_137 , int * V_138 )
{
if ( ! V_136 ) {
* V_137 = NULL ;
* V_138 = 0 ;
return;
}
* V_137 = V_136 ;
* V_138 = V_136 -> V_139 ;
}
static void F_84 ( struct V_136 * * V_140 , int * V_138 )
{
if ( * V_140 == NULL )
return;
F_3 ( * V_138 >= ( * V_140 ) -> V_141 ) ;
( * V_138 ) ++ ;
if ( * V_138 == ( * V_140 ) -> V_141 )
F_83 ( ( * V_140 ) -> V_142 , V_140 , V_138 ) ;
}
static void F_85 ( struct V_7 * V_8 )
{
struct V_99 * V_83 = V_8 -> V_108 ;
F_3 ( ! V_83 ) ;
F_3 ( ! V_83 -> V_143 . V_144 ) ;
V_8 -> V_145 . V_93 = 0 ;
if ( V_83 -> V_146 )
V_8 -> V_145 . V_147 = V_83 -> V_148 ;
else
V_8 -> V_145 . V_147 = 0 ;
#ifdef F_86
if ( V_83 -> V_136 )
F_83 ( V_83 -> V_136 , & V_83 -> V_140 , & V_83 -> V_149 ) ;
#endif
V_8 -> V_145 . V_150 = 0 ;
V_8 -> V_145 . V_151 = false ;
V_8 -> V_152 = 1 ;
}
static void F_87 ( struct V_7 * V_8 )
{
struct V_99 * V_153 = V_8 -> V_108 ;
int V_154 = V_8 -> V_128 ;
V_153 -> V_155 . V_9 |= V_156 ;
F_34 ( L_24 , V_8 ) ;
V_8 -> V_157 = true ;
V_8 -> V_131 [ V_154 ] . V_135 = & V_153 -> V_155 ;
V_8 -> V_131 [ V_154 ] . V_134 = sizeof( V_153 -> V_155 ) ;
V_8 -> V_129 += sizeof( V_153 -> V_155 ) ;
V_8 -> V_128 ++ ;
V_8 -> V_152 = V_153 -> V_158 ;
V_8 -> V_159 = true ;
}
static void F_88 ( struct V_7 * V_8 )
{
struct V_99 * V_153 ;
T_4 V_160 ;
F_80 ( V_8 ) ;
V_8 -> V_157 = true ;
V_8 -> V_159 = false ;
if ( V_8 -> V_109 > V_8 -> V_110 ) {
V_8 -> V_110 = V_8 -> V_109 ;
F_81 ( V_8 , sizeof ( V_161 ) , & V_161 ) ;
V_8 -> V_162 = F_71 ( V_8 -> V_110 ) ;
F_81 ( V_8 , sizeof ( V_8 -> V_162 ) ,
& V_8 -> V_162 ) ;
}
F_3 ( F_63 ( & V_8 -> V_103 ) ) ;
V_153 = F_64 ( & V_8 -> V_103 , struct V_99 , V_100 ) ;
V_8 -> V_108 = V_153 ;
F_3 ( V_153 -> V_8 != V_8 ) ;
F_89 ( V_153 ) ;
F_90 ( & V_153 -> V_100 , & V_8 -> V_104 ) ;
if ( V_153 -> V_163 ) {
V_153 -> V_143 . V_164 = F_71 ( ++ V_8 -> V_107 ) ;
V_153 -> V_163 = false ;
}
#ifdef F_86
else
V_153 -> V_140 = NULL ;
#endif
F_34 ( L_25 ,
V_153 , V_8 -> V_107 , F_91 ( V_153 -> V_143 . type ) ,
F_92 ( V_153 -> V_143 . V_165 ) , F_92 ( V_153 -> V_143 . V_166 ) ,
F_92 ( V_153 -> V_143 . V_144 ) ,
V_153 -> V_167 ) ;
F_3 ( F_92 ( V_153 -> V_143 . V_165 ) != V_153 -> V_168 . V_134 ) ;
F_81 ( V_8 , sizeof ( V_169 ) , & V_169 ) ;
F_81 ( V_8 , sizeof ( V_153 -> V_143 ) , & V_153 -> V_143 ) ;
F_81 ( V_8 , V_153 -> V_168 . V_134 , V_153 -> V_168 . V_135 ) ;
if ( V_153 -> V_170 )
F_81 ( V_8 , V_153 -> V_170 -> V_171 . V_134 ,
V_153 -> V_170 -> V_171 . V_135 ) ;
V_160 = F_93 ( 0 , & V_153 -> V_143 , F_94 ( struct V_172 , V_160 ) ) ;
V_8 -> V_108 -> V_143 . V_160 = F_95 ( V_160 ) ;
V_8 -> V_108 -> V_155 . V_9 = 0 ;
V_160 = F_93 ( 0 , V_153 -> V_168 . V_135 , V_153 -> V_168 . V_134 ) ;
V_8 -> V_108 -> V_155 . V_173 = F_95 ( V_160 ) ;
if ( V_153 -> V_170 ) {
V_160 = F_93 ( 0 , V_153 -> V_170 -> V_171 . V_135 ,
V_153 -> V_170 -> V_171 . V_134 ) ;
V_8 -> V_108 -> V_155 . V_174 = F_95 ( V_160 ) ;
} else
V_8 -> V_108 -> V_155 . V_174 = 0 ;
F_34 ( L_26 , V_42 ,
F_92 ( V_8 -> V_108 -> V_155 . V_173 ) ,
F_92 ( V_8 -> V_108 -> V_155 . V_174 ) ) ;
V_8 -> V_108 -> V_155 . V_175 = 0 ;
if ( V_153 -> V_143 . V_144 )
F_85 ( V_8 ) ;
else
F_87 ( V_8 ) ;
F_5 ( V_8 , V_4 ) ;
}
static void F_96 ( struct V_7 * V_8 )
{
F_34 ( L_27 , V_8 ,
V_8 -> V_110 , V_8 -> V_109 ) ;
V_8 -> V_110 = V_8 -> V_109 ;
F_80 ( V_8 ) ;
F_81 ( V_8 , sizeof ( V_161 ) , & V_161 ) ;
V_8 -> V_162 = F_71 ( V_8 -> V_110 ) ;
F_81 ( V_8 , sizeof ( V_8 -> V_162 ) ,
& V_8 -> V_162 ) ;
V_8 -> V_152 = 1 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_97 ( struct V_7 * V_8 )
{
F_34 ( L_28 , V_8 ) ;
F_80 ( V_8 ) ;
F_81 ( V_8 , sizeof ( V_176 ) , & V_176 ) ;
F_5 ( V_8 , V_4 ) ;
}
static struct V_177 * F_98 ( struct V_7 * V_8 ,
int * V_178 )
{
struct V_177 * V_179 ;
if ( ! V_8 -> V_72 -> V_180 ) {
V_8 -> V_181 . V_182 = V_183 ;
V_8 -> V_181 . V_184 = 0 ;
return NULL ;
}
F_69 ( & V_8 -> V_111 ) ;
V_179 = V_8 -> V_72 -> V_180 ( V_8 , V_178 , V_8 -> V_185 ) ;
F_67 ( & V_8 -> V_111 ) ;
if ( F_99 ( V_179 ) )
return V_179 ;
if ( V_8 -> V_53 != V_186 )
return F_100 ( - V_88 ) ;
V_8 -> V_187 = V_179 -> V_188 ;
V_8 -> V_189 = V_179 -> V_190 ;
return V_179 ;
}
static void F_101 ( struct V_7 * V_8 )
{
F_81 ( V_8 , strlen ( V_191 ) , V_191 ) ;
F_81 ( V_8 , sizeof ( V_8 -> V_30 -> V_31 ) ,
& V_8 -> V_30 -> V_31 ) ;
V_8 -> V_152 = 0 ;
F_5 ( V_8 , V_4 ) ;
}
static int F_102 ( struct V_7 * V_8 )
{
unsigned int V_127 = F_77 ( V_8 -> V_30 , 0 ) ;
int V_192 ;
int V_178 ;
struct V_177 * V_179 ;
switch ( V_8 -> V_119 . type ) {
case V_193 :
V_192 = V_194 ;
break;
case V_195 :
V_192 = V_196 ;
break;
case V_197 :
V_192 = V_198 ;
break;
default:
F_103 () ;
}
F_34 ( L_29 , V_8 ,
V_8 -> V_106 , V_127 , V_192 ) ;
V_8 -> V_181 . V_199 = F_71 ( V_8 -> V_30 -> V_200 ) ;
V_8 -> V_181 . V_201 = F_95 ( V_202 ) ;
V_8 -> V_181 . V_106 = F_95 ( V_8 -> V_106 ) ;
V_8 -> V_181 . V_127 = F_95 ( V_127 ) ;
V_8 -> V_181 . V_203 = F_95 ( V_192 ) ;
V_8 -> V_181 . V_9 = 0 ;
V_178 = V_183 ;
V_179 = F_98 ( V_8 , & V_178 ) ;
if ( F_99 ( V_179 ) )
return F_104 ( V_179 ) ;
V_8 -> V_181 . V_182 = F_95 ( V_178 ) ;
V_8 -> V_181 . V_184 = V_179 ?
F_95 ( V_179 -> V_204 ) : 0 ;
F_81 ( V_8 , sizeof ( V_8 -> V_181 ) ,
& V_8 -> V_181 ) ;
if ( V_179 && V_179 -> V_204 )
F_81 ( V_8 , V_179 -> V_204 ,
V_179 -> V_205 ) ;
V_8 -> V_152 = 0 ;
F_5 ( V_8 , V_4 ) ;
return 0 ;
}
static int F_105 ( struct V_7 * V_8 )
{
int V_65 ;
F_34 ( L_30 , V_8 , V_8 -> V_129 ) ;
while ( V_8 -> V_129 > 0 ) {
V_65 = F_54 ( V_8 -> V_46 , V_8 -> V_130 ,
V_8 -> V_128 , V_8 -> V_129 ,
V_8 -> V_152 ) ;
if ( V_65 <= 0 )
goto V_206;
V_8 -> V_129 -= V_65 ;
if ( V_8 -> V_129 == 0 )
break;
while ( V_65 >= V_8 -> V_130 -> V_134 ) {
F_3 ( ! V_8 -> V_128 ) ;
V_65 -= V_8 -> V_130 -> V_134 ;
V_8 -> V_130 ++ ;
V_8 -> V_128 -- ;
}
if ( V_65 ) {
V_8 -> V_130 -> V_134 -= V_65 ;
V_8 -> V_130 -> V_135 += V_65 ;
}
}
V_8 -> V_128 = 0 ;
V_8 -> V_157 = false ;
V_65 = 1 ;
V_206:
F_34 ( L_31 , V_8 ,
V_8 -> V_129 , V_8 -> V_128 , V_65 ) ;
return V_65 ;
}
static void F_106 ( struct V_7 * V_8 , struct V_93 * V_93 ,
T_1 V_79 , T_1 V_207 , bool V_208 )
{
struct V_99 * V_83 = V_8 -> V_108 ;
F_3 ( ! V_83 ) ;
F_3 ( ! V_207 ) ;
V_8 -> V_145 . V_150 += V_207 ;
V_8 -> V_145 . V_147 += V_207 ;
if ( V_207 < V_79 )
return;
F_3 ( V_207 != V_79 ) ;
V_8 -> V_145 . V_147 = 0 ;
V_8 -> V_145 . V_93 ++ ;
V_8 -> V_145 . V_151 = false ;
if ( V_208 )
F_90 ( & V_93 -> V_209 ,
& V_83 -> V_210 -> V_102 ) ;
else if ( V_83 -> V_211 )
F_90 ( & V_93 -> V_209 ,
& V_83 -> V_211 -> V_102 ) ;
#ifdef F_86
else if ( V_83 -> V_136 )
F_84 ( & V_83 -> V_140 , & V_83 -> V_149 ) ;
#endif
}
static int F_107 ( struct V_7 * V_8 )
{
struct V_99 * V_83 = V_8 -> V_108 ;
unsigned int V_144 = F_92 ( V_83 -> V_143 . V_144 ) ;
T_1 V_79 ;
bool V_212 = ! V_8 -> V_30 -> V_213 ;
int V_65 ;
int V_214 ;
bool V_208 = false ;
const T_1 V_215 = ( V_83 -> V_210 ? V_83 -> V_210 -> V_216 : 0 ) ;
const T_1 V_217 = V_144 - V_215 ;
F_34 ( L_32 ,
V_8 , V_83 , V_8 -> V_145 . V_93 , V_83 -> V_167 ,
V_8 -> V_145 . V_147 ) ;
while ( V_144 > V_8 -> V_145 . V_150 ) {
struct V_93 * V_93 = NULL ;
int V_218 = V_219 ;
int V_220 = 0 ;
V_208 = V_208 || V_8 -> V_145 . V_150 >= V_217 ;
if ( ! V_208 )
V_214 = V_217 - V_8 -> V_145 . V_150 ;
if ( V_208 ) {
V_214 = V_144 - V_8 -> V_145 . V_150 ;
V_93 = F_64 ( & V_83 -> V_210 -> V_102 ,
struct V_93 , V_209 ) ;
} else if ( V_83 -> V_146 ) {
V_93 = V_83 -> V_146 [ V_8 -> V_145 . V_93 ] ;
} else if ( V_83 -> V_211 ) {
V_93 = F_64 ( & V_83 -> V_211 -> V_102 ,
struct V_93 , V_209 ) ;
#ifdef F_86
} else if ( V_83 -> V_136 ) {
struct V_221 * V_222 ;
V_222 = F_108 ( V_83 -> V_140 , V_83 -> V_149 ) ;
V_93 = V_222 -> V_223 ;
V_220 = V_222 -> V_224 ;
V_218 = V_222 -> V_225 ;
#endif
} else {
V_93 = V_35 ;
}
V_79 = F_109 ( int , V_218 - V_8 -> V_145 . V_147 ,
V_214 ) ;
if ( V_212 && ! V_8 -> V_145 . V_151 ) {
void * V_226 ;
T_4 V_160 = F_92 ( V_83 -> V_155 . V_175 ) ;
char * V_227 ;
V_227 = F_110 ( V_93 ) ;
F_3 ( V_227 == NULL ) ;
V_226 = V_227 + V_8 -> V_145 . V_147 + V_220 ;
V_160 = F_93 ( V_160 , V_226 , V_79 ) ;
F_20 ( V_93 ) ;
V_83 -> V_155 . V_175 = F_95 ( V_160 ) ;
V_8 -> V_145 . V_151 = true ;
}
V_65 = F_56 ( V_8 -> V_46 , V_93 ,
V_8 -> V_145 . V_147 + V_220 ,
V_79 , 1 ) ;
if ( V_65 <= 0 )
goto V_206;
F_106 ( V_8 , V_93 , V_79 , ( T_1 ) V_65 , V_208 ) ;
}
F_34 ( L_33 , V_8 , V_83 ) ;
if ( ! V_212 )
V_83 -> V_155 . V_9 |= V_228 ;
F_80 ( V_8 ) ;
F_87 ( V_8 ) ;
V_65 = 1 ;
V_206:
return V_65 ;
}
static int F_111 ( struct V_7 * V_8 )
{
int V_65 ;
while ( V_8 -> V_229 > 0 ) {
T_1 V_95 = F_112 ( V_8 -> V_229 , ( int ) V_230 ) ;
V_65 = F_56 ( V_8 -> V_46 , V_35 , 0 , V_95 , 1 ) ;
if ( V_65 <= 0 )
goto V_206;
V_8 -> V_229 -= V_65 ;
}
V_65 = 1 ;
V_206:
return V_65 ;
}
static void F_113 ( struct V_7 * V_8 )
{
F_34 ( L_34 , V_8 ) ;
V_8 -> V_231 = 0 ;
}
static void F_114 ( struct V_7 * V_8 )
{
F_34 ( L_35 , V_8 ) ;
V_8 -> V_231 = 0 ;
}
static void F_115 ( struct V_7 * V_8 )
{
F_34 ( L_36 , V_8 ) ;
V_8 -> V_231 = 0 ;
}
static void F_116 ( struct V_7 * V_8 )
{
F_34 ( L_37 , V_8 ) ;
V_8 -> V_231 = 0 ;
V_8 -> V_232 = V_233 ;
}
static int F_117 ( struct V_7 * V_8 )
{
F_34 ( L_38 , V_8 ) ;
F_3 ( V_8 -> V_105 != NULL ) ;
V_8 -> V_231 = 0 ;
V_8 -> V_234 = V_8 -> V_235 = V_8 -> V_236 = 0 ;
return 0 ;
}
static int F_118 ( struct V_7 * V_8 ,
int V_237 , int V_95 , void * V_238 )
{
while ( V_8 -> V_231 < V_237 ) {
int V_239 = V_237 - V_8 -> V_231 ;
int V_240 = V_95 - V_239 ;
int V_65 = F_52 ( V_8 -> V_46 , V_238 + V_240 , V_239 ) ;
if ( V_65 <= 0 )
return V_65 ;
V_8 -> V_231 += V_65 ;
}
return 1 ;
}
static int F_119 ( struct V_7 * V_8 )
{
int V_95 ;
int V_237 ;
int V_65 ;
F_34 ( L_39 , V_8 , V_8 -> V_231 ) ;
V_95 = strlen ( V_191 ) ;
V_237 = V_95 ;
V_65 = F_118 ( V_8 , V_237 , V_95 , V_8 -> V_241 ) ;
if ( V_65 <= 0 )
goto V_206;
V_95 = sizeof ( V_8 -> V_242 ) ;
V_237 += V_95 ;
V_65 = F_118 ( V_8 , V_237 , V_95 , & V_8 -> V_242 ) ;
if ( V_65 <= 0 )
goto V_206;
V_95 = sizeof ( V_8 -> V_243 ) ;
V_237 += V_95 ;
V_65 = F_118 ( V_8 , V_237 , V_95 , & V_8 -> V_243 ) ;
if ( V_65 <= 0 )
goto V_206;
V_206:
return V_65 ;
}
static int F_120 ( struct V_7 * V_8 )
{
int V_95 ;
int V_237 ;
int V_65 ;
F_34 ( L_40 , V_8 , V_8 -> V_231 ) ;
V_95 = sizeof ( V_8 -> V_244 ) ;
V_237 = V_95 ;
V_65 = F_118 ( V_8 , V_237 , V_95 , & V_8 -> V_244 ) ;
if ( V_65 <= 0 )
goto V_206;
V_95 = F_92 ( V_8 -> V_244 . V_184 ) ;
V_237 += V_95 ;
V_65 = F_118 ( V_8 , V_237 , V_95 , V_8 -> V_187 ) ;
if ( V_65 <= 0 )
goto V_206;
F_34 ( L_41 ,
V_8 , ( int ) V_8 -> V_244 . V_245 ,
F_92 ( V_8 -> V_244 . V_106 ) ,
F_92 ( V_8 -> V_244 . V_127 ) ) ;
V_206:
return V_65 ;
}
static int F_121 ( struct V_7 * V_8 )
{
if ( memcmp ( V_8 -> V_241 , V_191 , strlen ( V_191 ) ) ) {
F_26 ( L_42 ,
F_13 ( & V_8 -> V_63 . V_64 ) ) ;
V_8 -> V_77 = L_43 ;
return - 1 ;
}
return 0 ;
}
static bool F_122 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return ( (struct V_14 * ) V_11 ) -> V_24 . V_246 == 0 ;
case V_26 :
return
( (struct V_16 * ) V_11 ) -> V_27 . V_247 [ 0 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_247 [ 1 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_247 [ 2 ] == 0 &&
( (struct V_16 * ) V_11 ) -> V_27 . V_247 [ 3 ] == 0 ;
}
return false ;
}
static int F_123 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
return F_15 ( ( (struct V_14 * ) V_11 ) -> V_25 ) ;
case V_26 :
return F_15 ( ( (struct V_16 * ) V_11 ) -> V_28 ) ;
}
return 0 ;
}
static void F_124 ( struct V_10 * V_11 , int V_248 )
{
switch ( V_11 -> V_21 ) {
case V_22 :
( (struct V_14 * ) V_11 ) -> V_25 = F_125 ( V_248 ) ;
break;
case V_26 :
( (struct V_16 * ) V_11 ) -> V_28 = F_125 ( V_248 ) ;
break;
}
}
static int F_126 ( const char * V_249 , T_1 V_79 , struct V_10 * V_11 ,
char V_250 , const char * * V_251 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
struct V_16 * V_17 = (struct V_16 * ) V_11 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( F_127 ( V_249 , V_79 , ( V_252 * ) & V_15 -> V_24 . V_246 , V_250 , V_251 ) ) {
V_11 -> V_21 = V_22 ;
return 0 ;
}
if ( F_128 ( V_249 , V_79 , ( V_252 * ) & V_17 -> V_27 . V_253 , V_250 , V_251 ) ) {
V_11 -> V_21 = V_26 ;
return 0 ;
}
return - V_254 ;
}
static int F_129 ( const char * V_255 , T_1 V_256 ,
struct V_10 * V_11 , char V_250 , const char * * V_251 )
{
const char * V_237 , * V_257 ;
char * V_258 , * V_259 = NULL ;
int V_260 , V_65 ;
V_257 = memchr ( V_255 , V_250 , V_256 ) ;
V_258 = memchr ( V_255 , ':' , V_256 ) ;
if ( V_257 && V_258 )
V_237 = V_257 < V_258 ? V_257 : V_258 ;
else if ( ! V_257 && V_258 )
V_237 = V_258 ;
else {
V_237 = V_257 ;
if ( ! V_237 )
V_237 = V_255 + V_256 ;
}
if ( V_237 <= V_255 )
return - V_254 ;
V_260 = F_130 ( NULL , V_255 , V_237 - V_255 , NULL , & V_259 , NULL ) ;
if ( V_260 > 0 )
V_65 = F_126 ( V_259 , V_260 , V_11 , - 1 , NULL ) ;
else
V_65 = - V_261 ;
F_131 ( V_259 ) ;
* V_251 = V_237 ;
F_132 ( L_44 , ( int ) ( V_237 - V_255 ) , V_255 ,
V_65 , V_65 ? L_45 : F_13 ( V_11 ) ) ;
return V_65 ;
}
static inline int F_129 ( const char * V_255 , T_1 V_256 ,
struct V_10 * V_11 , char V_250 , const char * * V_251 )
{
return - V_254 ;
}
static int F_133 ( const char * V_255 , T_1 V_256 ,
struct V_10 * V_11 , char V_250 , const char * * V_251 )
{
int V_65 ;
V_65 = F_126 ( V_255 , V_256 , V_11 , V_250 , V_251 ) ;
if ( V_65 )
V_65 = F_129 ( V_255 , V_256 , V_11 , V_250 , V_251 ) ;
return V_65 ;
}
int F_134 ( const char * V_262 , const char * V_237 ,
struct V_117 * V_33 ,
int V_263 , int * V_264 )
{
int V_12 , V_65 = - V_254 ;
const char * V_248 = V_262 ;
F_34 ( L_46 , ( int ) ( V_237 - V_262 ) , V_262 ) ;
for ( V_12 = 0 ; V_12 < V_263 ; V_12 ++ ) {
const char * V_251 ;
struct V_10 * V_11 = & V_33 [ V_12 ] . V_64 ;
int V_265 ;
char V_250 = ',' ;
if ( * V_248 == '[' ) {
V_250 = ']' ;
V_248 ++ ;
}
V_65 = F_133 ( V_248 , V_237 - V_248 , V_11 , V_250 , & V_251 ) ;
if ( V_65 )
goto V_266;
V_65 = - V_254 ;
V_248 = V_251 ;
if ( V_250 == ']' ) {
if ( * V_248 != ']' ) {
F_34 ( L_47 ) ;
goto V_266;
}
V_248 ++ ;
}
if ( V_248 < V_237 && * V_248 == ':' ) {
V_265 = 0 ;
V_248 ++ ;
while ( V_248 < V_237 && * V_248 >= '0' && * V_248 <= '9' ) {
V_265 = ( V_265 * 10 ) + ( * V_248 - '0' ) ;
V_248 ++ ;
}
if ( V_265 > 65535 || V_265 == 0 )
goto V_266;
} else {
V_265 = V_267 ;
}
F_124 ( V_11 , V_265 ) ;
F_34 ( L_48 , F_13 ( V_11 ) ) ;
if ( V_248 == V_237 )
break;
if ( * V_248 != ',' )
goto V_266;
V_248 ++ ;
}
if ( V_248 != V_237 )
goto V_266;
if ( V_264 )
* V_264 = V_12 + 1 ;
return 0 ;
V_266:
F_26 ( L_49 , ( int ) ( V_237 - V_262 ) , V_262 ) ;
return V_65 ;
}
static int F_135 ( struct V_7 * V_8 )
{
F_34 ( L_50 , V_8 ) ;
if ( F_121 ( V_8 ) < 0 )
return - 1 ;
F_136 ( & V_8 -> V_242 ) ;
F_136 ( & V_8 -> V_243 ) ;
if ( memcmp ( & V_8 -> V_63 , & V_8 -> V_242 ,
sizeof( V_8 -> V_63 ) ) != 0 &&
! ( F_122 ( & V_8 -> V_242 . V_64 ) &&
V_8 -> V_242 . V_268 == V_8 -> V_63 . V_268 ) ) {
F_137 ( L_51 ,
F_13 ( & V_8 -> V_63 . V_64 ) ,
( int ) F_92 ( V_8 -> V_63 . V_268 ) ,
F_13 ( & V_8 -> V_242 . V_64 ) ,
( int ) F_92 ( V_8 -> V_242 . V_268 ) ) ;
V_8 -> V_77 = L_52 ;
return - 1 ;
}
if ( F_122 ( & V_8 -> V_30 -> V_32 . V_33 . V_64 ) ) {
int V_265 = F_123 ( & V_8 -> V_30 -> V_32 . V_33 . V_64 ) ;
memcpy ( & V_8 -> V_30 -> V_32 . V_33 . V_64 ,
& V_8 -> V_243 . V_64 ,
sizeof( V_8 -> V_243 . V_64 ) ) ;
F_124 ( & V_8 -> V_30 -> V_32 . V_33 . V_64 , V_265 ) ;
F_16 ( V_8 -> V_30 ) ;
F_34 ( L_53 ,
F_13 ( & V_8 -> V_30 -> V_32 . V_33 . V_64 ) ) ;
}
return 0 ;
}
static int F_138 ( struct V_7 * V_8 )
{
T_5 V_269 = V_8 -> V_30 -> V_200 ;
T_5 V_270 = V_8 -> V_30 -> V_271 ;
T_5 V_272 = F_139 ( V_8 -> V_244 . V_199 ) ;
int V_65 ;
F_34 ( L_54 , V_8 , ( int ) V_8 -> V_232 ) ;
switch ( V_8 -> V_244 . V_245 ) {
case V_273 :
F_26 ( L_55
L_56 ,
F_140 ( V_8 -> V_119 ) ,
F_13 ( & V_8 -> V_63 . V_64 ) ,
V_269 , V_272 , V_272 & ~ V_269 ) ;
V_8 -> V_77 = L_57 ;
F_65 ( V_8 ) ;
return - 1 ;
case V_274 :
F_26 ( L_58
L_59 ,
F_140 ( V_8 -> V_119 ) ,
F_13 ( & V_8 -> V_63 . V_64 ) ,
F_92 ( V_8 -> V_181 . V_203 ) ,
F_92 ( V_8 -> V_244 . V_203 ) ) ;
V_8 -> V_77 = L_60 ;
F_65 ( V_8 ) ;
return - 1 ;
case V_275 :
V_8 -> V_185 ++ ;
F_34 ( L_61 , V_8 ,
V_8 -> V_185 ) ;
if ( V_8 -> V_185 == 2 ) {
V_8 -> V_77 = L_62 ;
return - 1 ;
}
V_8 -> V_185 = 1 ;
F_80 ( V_8 ) ;
V_65 = F_102 ( V_8 ) ;
if ( V_65 < 0 )
return V_65 ;
F_114 ( V_8 ) ;
break;
case V_276 :
F_34 ( L_63 ,
F_92 ( V_8 -> V_244 . V_106 ) ) ;
F_26 ( L_64 ,
F_140 ( V_8 -> V_119 ) ,
F_13 ( & V_8 -> V_63 . V_64 ) ) ;
F_65 ( V_8 ) ;
F_80 ( V_8 ) ;
V_65 = F_102 ( V_8 ) ;
if ( V_65 < 0 )
return V_65 ;
F_114 ( V_8 ) ;
F_69 ( & V_8 -> V_111 ) ;
F_132 ( L_65 , F_140 ( V_8 -> V_119 ) ) ;
if ( V_8 -> V_72 -> V_277 )
V_8 -> V_72 -> V_277 ( V_8 ) ;
F_67 ( & V_8 -> V_111 ) ;
if ( V_8 -> V_53 != V_186 )
return - V_88 ;
break;
case V_278 :
F_34 ( L_66 ,
F_92 ( V_8 -> V_181 . V_106 ) ,
F_92 ( V_8 -> V_244 . V_106 ) ) ;
V_8 -> V_106 = F_92 ( V_8 -> V_244 . V_106 ) ;
F_80 ( V_8 ) ;
V_65 = F_102 ( V_8 ) ;
if ( V_65 < 0 )
return V_65 ;
F_114 ( V_8 ) ;
break;
case V_279 :
F_34 ( L_67 ,
V_8 -> V_113 ,
F_92 ( V_8 -> V_244 . V_127 ) ) ;
F_77 ( V_8 -> V_30 ,
F_92 ( V_8 -> V_244 . V_127 ) ) ;
F_80 ( V_8 ) ;
V_65 = F_102 ( V_8 ) ;
if ( V_65 < 0 )
return V_65 ;
F_114 ( V_8 ) ;
break;
case V_233 :
if ( V_270 & ~ V_272 ) {
F_26 ( L_68
L_69 ,
F_140 ( V_8 -> V_119 ) ,
F_13 ( & V_8 -> V_63 . V_64 ) ,
V_270 , V_272 , V_270 & ~ V_272 ) ;
V_8 -> V_77 = L_57 ;
F_65 ( V_8 ) ;
return - 1 ;
}
F_32 ( V_8 -> V_53 != V_186 ) ;
V_8 -> V_53 = V_280 ;
V_8 -> V_113 = F_92 ( V_8 -> V_244 . V_127 ) ;
V_8 -> V_106 ++ ;
V_8 -> V_281 = V_272 ;
F_34 ( L_70 ,
V_8 -> V_113 ,
F_92 ( V_8 -> V_244 . V_106 ) ,
V_8 -> V_106 ) ;
F_32 ( V_8 -> V_106 !=
F_92 ( V_8 -> V_244 . V_106 ) ) ;
if ( V_8 -> V_244 . V_9 & V_282 )
F_5 ( V_8 , V_2 ) ;
V_8 -> V_121 = 0 ;
F_116 ( V_8 ) ;
break;
case V_283 :
F_26 ( L_71 ) ;
V_8 -> V_77 = L_72 ;
return - 1 ;
default:
F_26 ( L_73 ) ;
V_8 -> V_77 = L_74 ;
return - 1 ;
}
return 0 ;
}
static int F_141 ( struct V_7 * V_8 )
{
int V_95 = sizeof ( V_8 -> V_284 ) ;
int V_237 = V_95 ;
return F_118 ( V_8 , V_237 , V_95 , & V_8 -> V_284 ) ;
}
static void F_142 ( struct V_7 * V_8 )
{
struct V_99 * V_153 ;
T_5 V_285 = F_139 ( V_8 -> V_284 ) ;
T_5 V_164 ;
while ( ! F_63 ( & V_8 -> V_104 ) ) {
V_153 = F_64 ( & V_8 -> V_104 , struct V_99 ,
V_100 ) ;
V_164 = F_139 ( V_153 -> V_143 . V_164 ) ;
if ( V_164 > V_285 )
break;
F_34 ( L_75 , V_164 ,
F_91 ( V_153 -> V_143 . type ) , V_153 ) ;
V_153 -> V_286 = V_287 ;
F_59 ( V_153 ) ;
}
F_116 ( V_8 ) ;
}
static int F_143 ( struct V_7 * V_8 ,
struct V_80 * V_288 ,
unsigned int V_289 , T_4 * V_160 )
{
int V_65 , V_239 ;
F_3 ( ! V_288 ) ;
while ( V_288 -> V_134 < V_289 ) {
F_3 ( V_288 -> V_135 == NULL ) ;
V_239 = V_289 - V_288 -> V_134 ;
V_65 = F_52 ( V_8 -> V_46 , ( char * ) V_288 -> V_135 +
V_288 -> V_134 , V_239 ) ;
if ( V_65 <= 0 )
return V_65 ;
V_288 -> V_134 += V_65 ;
}
if ( V_288 -> V_134 == V_289 )
* V_160 = F_93 ( 0 , V_288 -> V_135 , V_288 -> V_134 ) ;
return 1 ;
}
static int F_144 ( struct V_7 * V_8 ,
struct V_93 * * V_146 ,
unsigned int V_144 , bool V_212 )
{
void * V_248 ;
int V_65 ;
int V_239 ;
V_239 = F_112 ( ( int ) ( V_144 - V_8 -> V_290 . V_150 ) ,
( int ) ( V_219 - V_8 -> V_290 . V_147 ) ) ;
F_3 ( V_146 == NULL ) ;
V_248 = F_110 ( V_146 [ V_8 -> V_290 . V_93 ] ) ;
V_65 = F_52 ( V_8 -> V_46 , V_248 + V_8 -> V_290 . V_147 ,
V_239 ) ;
if ( V_65 > 0 && V_212 )
V_8 -> V_236 =
F_93 ( V_8 -> V_236 ,
V_248 + V_8 -> V_290 . V_147 , V_65 ) ;
F_20 ( V_146 [ V_8 -> V_290 . V_93 ] ) ;
if ( V_65 <= 0 )
return V_65 ;
V_8 -> V_290 . V_150 += V_65 ;
V_8 -> V_290 . V_147 += V_65 ;
if ( V_8 -> V_290 . V_147 == V_219 ) {
V_8 -> V_290 . V_147 = 0 ;
V_8 -> V_290 . V_93 ++ ;
}
return V_65 ;
}
static int F_145 ( struct V_7 * V_8 ,
struct V_136 * * V_140 , int * V_149 ,
unsigned int V_144 , bool V_212 )
{
struct V_221 * V_222 = F_108 ( * V_140 , * V_149 ) ;
void * V_248 ;
int V_65 , V_239 ;
V_239 = F_112 ( ( int ) ( V_144 - V_8 -> V_290 . V_150 ) ,
( int ) ( V_222 -> V_225 - V_8 -> V_290 . V_147 ) ) ;
V_248 = F_110 ( V_222 -> V_223 ) + V_222 -> V_224 ;
V_65 = F_52 ( V_8 -> V_46 , V_248 + V_8 -> V_290 . V_147 ,
V_239 ) ;
if ( V_65 > 0 && V_212 )
V_8 -> V_236 =
F_93 ( V_8 -> V_236 ,
V_248 + V_8 -> V_290 . V_147 , V_65 ) ;
F_20 ( V_222 -> V_223 ) ;
if ( V_65 <= 0 )
return V_65 ;
V_8 -> V_290 . V_150 += V_65 ;
V_8 -> V_290 . V_147 += V_65 ;
if ( V_8 -> V_290 . V_147 == V_222 -> V_225 ) {
V_8 -> V_290 . V_147 = 0 ;
F_84 ( V_140 , V_149 ) ;
}
return V_65 ;
}
static int F_146 ( struct V_7 * V_8 )
{
struct V_99 * V_153 = V_8 -> V_105 ;
int V_95 ;
int V_237 ;
int V_65 ;
unsigned int V_165 , V_166 , V_144 ;
bool V_212 = ! V_8 -> V_30 -> V_213 ;
T_5 V_164 ;
T_4 V_160 ;
F_34 ( L_76 , V_8 , V_153 ) ;
V_95 = sizeof ( V_8 -> V_291 ) ;
V_237 = V_95 ;
V_65 = F_118 ( V_8 , V_237 , V_95 , & V_8 -> V_291 ) ;
if ( V_65 <= 0 )
return V_65 ;
V_160 = F_93 ( 0 , & V_8 -> V_291 , F_94 ( struct V_172 , V_160 ) ) ;
if ( F_95 ( V_160 ) != V_8 -> V_291 . V_160 ) {
F_26 ( L_77
L_78 ,
V_160 , V_8 -> V_291 . V_160 ) ;
return - V_292 ;
}
V_165 = F_92 ( V_8 -> V_291 . V_165 ) ;
if ( V_165 > V_293 )
return - V_294 ;
V_166 = F_92 ( V_8 -> V_291 . V_166 ) ;
if ( V_166 > V_295 )
return - V_294 ;
V_144 = F_92 ( V_8 -> V_291 . V_144 ) ;
if ( V_144 > V_295 )
return - V_294 ;
V_164 = F_139 ( V_8 -> V_291 . V_164 ) ;
if ( ( V_296 ) V_164 - ( V_296 ) V_8 -> V_109 < 1 ) {
F_132 ( L_79 ,
F_140 ( V_8 -> V_119 ) ,
F_13 ( & V_8 -> V_63 . V_64 ) ,
V_164 , V_8 -> V_109 + 1 ) ;
V_8 -> V_231 = - V_165 - V_166 - V_144 -
sizeof( V_153 -> V_155 ) ;
V_8 -> V_232 = V_233 ;
return 0 ;
} else if ( ( V_296 ) V_164 - ( V_296 ) V_8 -> V_109 > 1 ) {
F_26 ( L_80 ,
V_164 , V_8 -> V_109 + 1 ) ;
V_8 -> V_77 = L_81 ;
return - V_292 ;
}
if ( ! V_8 -> V_105 ) {
int V_297 = 0 ;
F_34 ( L_82 , V_8 -> V_291 . type ,
V_8 -> V_291 . V_165 , V_8 -> V_291 . V_144 ) ;
V_65 = F_147 ( V_8 , & V_297 ) ;
if ( V_65 < 0 )
return V_65 ;
if ( V_297 ) {
F_34 ( L_83 ) ;
F_3 ( V_8 -> V_105 ) ;
V_8 -> V_231 = - V_165 - V_166 - V_144 -
sizeof( V_153 -> V_155 ) ;
V_8 -> V_232 = V_233 ;
V_8 -> V_109 ++ ;
return 0 ;
}
F_3 ( ! V_8 -> V_105 ) ;
F_3 ( V_8 -> V_105 -> V_8 != V_8 ) ;
V_153 = V_8 -> V_105 ;
V_153 -> V_168 . V_134 = 0 ;
if ( V_153 -> V_170 )
V_153 -> V_170 -> V_171 . V_134 = 0 ;
V_8 -> V_290 . V_93 = 0 ;
if ( V_153 -> V_146 )
V_8 -> V_290 . V_147 = V_153 -> V_148 ;
else
V_8 -> V_290 . V_147 = 0 ;
V_8 -> V_290 . V_150 = 0 ;
#ifdef F_86
if ( V_153 -> V_136 )
F_83 ( V_153 -> V_136 , & V_153 -> V_140 , & V_153 -> V_149 ) ;
#endif
}
V_65 = F_143 ( V_8 , & V_153 -> V_168 , V_165 ,
& V_8 -> V_234 ) ;
if ( V_65 <= 0 )
return V_65 ;
if ( V_153 -> V_170 ) {
V_65 = F_143 ( V_8 , & V_153 -> V_170 -> V_171 ,
V_166 ,
& V_8 -> V_235 ) ;
if ( V_65 <= 0 )
return V_65 ;
}
while ( V_8 -> V_290 . V_150 < V_144 ) {
if ( V_153 -> V_146 ) {
V_65 = F_144 ( V_8 , V_153 -> V_146 ,
V_144 , V_212 ) ;
if ( V_65 <= 0 )
return V_65 ;
#ifdef F_86
} else if ( V_153 -> V_136 ) {
F_3 ( ! V_153 -> V_140 ) ;
V_65 = F_145 ( V_8 ,
& V_153 -> V_140 , & V_153 -> V_149 ,
V_144 , V_212 ) ;
if ( V_65 <= 0 )
return V_65 ;
#endif
} else {
F_3 ( 1 ) ;
}
}
V_95 = sizeof ( V_153 -> V_155 ) ;
V_237 += V_95 ;
V_65 = F_118 ( V_8 , V_237 , V_95 , & V_153 -> V_155 ) ;
if ( V_65 <= 0 )
return V_65 ;
F_34 ( L_84 ,
V_153 , V_165 , V_153 -> V_155 . V_173 , V_166 ,
V_153 -> V_155 . V_174 , V_144 , V_153 -> V_155 . V_175 ) ;
if ( V_8 -> V_234 != F_92 ( V_153 -> V_155 . V_173 ) ) {
F_26 ( L_85 ,
V_153 , V_8 -> V_234 , V_153 -> V_155 . V_173 ) ;
return - V_292 ;
}
if ( V_8 -> V_235 != F_92 ( V_153 -> V_155 . V_174 ) ) {
F_26 ( L_86 ,
V_153 , V_8 -> V_235 , V_153 -> V_155 . V_174 ) ;
return - V_292 ;
}
if ( V_212 &&
( V_153 -> V_155 . V_9 & V_228 ) == 0 &&
V_8 -> V_236 != F_92 ( V_153 -> V_155 . V_175 ) ) {
F_26 ( L_87 , V_153 ,
V_8 -> V_236 , F_92 ( V_153 -> V_155 . V_175 ) ) ;
return - V_292 ;
}
return 1 ;
}
static void F_148 ( struct V_7 * V_8 )
{
struct V_99 * V_83 ;
F_3 ( V_8 -> V_105 -> V_8 != V_8 ) ;
V_8 -> V_105 -> V_8 = NULL ;
V_83 = V_8 -> V_105 ;
V_8 -> V_105 = NULL ;
V_8 -> V_72 -> V_101 ( V_8 ) ;
if ( V_8 -> V_119 . type == 0 )
V_8 -> V_119 = V_83 -> V_143 . V_298 ;
V_8 -> V_109 ++ ;
F_69 ( & V_8 -> V_111 ) ;
F_34 ( L_88 ,
V_83 , F_139 ( V_83 -> V_143 . V_164 ) ,
F_140 ( V_83 -> V_143 . V_298 ) ,
F_91 ( V_83 -> V_143 . type ) ,
F_149 ( F_91 ( V_83 -> V_143 . type ) ) ,
F_92 ( V_83 -> V_143 . V_165 ) ,
F_92 ( V_83 -> V_143 . V_144 ) ,
V_8 -> V_234 , V_8 -> V_235 , V_8 -> V_236 ) ;
V_8 -> V_72 -> V_299 ( V_8 , V_83 ) ;
F_67 ( & V_8 -> V_111 ) ;
}
static int F_150 ( struct V_7 * V_8 )
{
int V_65 = 1 ;
F_34 ( L_89 , V_8 , V_8 -> V_53 ) ;
V_90:
F_34 ( L_90 , V_8 -> V_129 ) ;
if ( V_8 -> V_53 == V_118 ) {
F_3 ( V_8 -> V_46 ) ;
V_8 -> V_53 = V_300 ;
F_80 ( V_8 ) ;
F_101 ( V_8 ) ;
F_113 ( V_8 ) ;
F_3 ( V_8 -> V_105 ) ;
V_8 -> V_232 = V_233 ;
F_34 ( L_91 ,
V_8 , V_8 -> V_53 ) ;
V_65 = F_47 ( V_8 ) ;
if ( V_65 < 0 ) {
V_8 -> V_77 = L_18 ;
goto V_206;
}
}
V_301:
if ( V_8 -> V_229 ) {
V_65 = F_111 ( V_8 ) ;
if ( V_65 <= 0 )
goto V_206;
}
if ( V_8 -> V_128 ) {
V_65 = F_105 ( V_8 ) ;
if ( V_65 <= 0 )
goto V_206;
}
if ( V_8 -> V_108 ) {
if ( V_8 -> V_159 ) {
F_61 ( V_8 -> V_108 ) ;
V_8 -> V_108 = NULL ;
goto V_302;
}
V_65 = F_107 ( V_8 ) ;
if ( V_65 == 1 )
goto V_301;
if ( V_65 == 0 )
goto V_206;
if ( V_65 < 0 ) {
F_34 ( L_92 ,
V_65 ) ;
goto V_206;
}
}
V_302:
if ( V_8 -> V_53 == V_280 ) {
if ( ! F_63 ( & V_8 -> V_103 ) ) {
F_88 ( V_8 ) ;
goto V_90;
}
if ( V_8 -> V_109 > V_8 -> V_110 ) {
F_96 ( V_8 ) ;
goto V_90;
}
if ( F_9 ( V_8 , V_3 ) ) {
F_97 ( V_8 ) ;
goto V_90;
}
}
F_2 ( V_8 , V_4 ) ;
F_34 ( L_93 ) ;
V_65 = 0 ;
V_206:
F_34 ( L_94 , V_8 , V_65 ) ;
return V_65 ;
}
static int F_151 ( struct V_7 * V_8 )
{
int V_65 = - 1 ;
V_90:
F_34 ( L_95 , V_8 , V_8 -> V_53 ) ;
if ( V_8 -> V_53 != V_300 &&
V_8 -> V_53 != V_186 &&
V_8 -> V_53 != V_280 )
return 0 ;
F_3 ( ! V_8 -> V_46 ) ;
F_34 ( L_96 , ( int ) V_8 -> V_232 ,
V_8 -> V_231 ) ;
if ( V_8 -> V_53 == V_300 ) {
F_34 ( L_97 ) ;
V_65 = F_119 ( V_8 ) ;
if ( V_65 <= 0 )
goto V_206;
V_65 = F_135 ( V_8 ) ;
if ( V_65 < 0 )
goto V_206;
V_8 -> V_53 = V_186 ;
V_65 = F_102 ( V_8 ) ;
if ( V_65 < 0 )
goto V_206;
F_114 ( V_8 ) ;
goto V_206;
}
if ( V_8 -> V_53 == V_186 ) {
F_34 ( L_98 ) ;
V_65 = F_120 ( V_8 ) ;
if ( V_65 <= 0 )
goto V_206;
V_65 = F_138 ( V_8 ) ;
if ( V_65 < 0 )
goto V_206;
goto V_90;
}
F_32 ( V_8 -> V_53 != V_280 ) ;
if ( V_8 -> V_231 < 0 ) {
static char V_78 [ V_303 ] ;
int V_297 = F_112 ( ( int ) sizeof ( V_78 ) , - V_8 -> V_231 ) ;
F_34 ( L_99 , V_297 , - V_8 -> V_231 ) ;
V_65 = F_52 ( V_8 -> V_46 , V_78 , V_297 ) ;
if ( V_65 <= 0 )
goto V_206;
V_8 -> V_231 += V_65 ;
if ( V_8 -> V_231 )
goto V_90;
}
if ( V_8 -> V_232 == V_233 ) {
V_65 = F_52 ( V_8 -> V_46 , & V_8 -> V_232 , 1 ) ;
if ( V_65 <= 0 )
goto V_206;
F_34 ( L_100 , ( int ) V_8 -> V_232 ) ;
switch ( V_8 -> V_232 ) {
case V_304 :
F_117 ( V_8 ) ;
break;
case V_305 :
F_115 ( V_8 ) ;
break;
case V_306 :
F_58 ( V_8 ) ;
V_8 -> V_53 = V_112 ;
goto V_206;
default:
goto V_307;
}
}
if ( V_8 -> V_232 == V_304 ) {
V_65 = F_146 ( V_8 ) ;
if ( V_65 <= 0 ) {
switch ( V_65 ) {
case - V_292 :
V_8 -> V_77 = L_101 ;
V_65 = - V_294 ;
break;
case - V_294 :
V_8 -> V_77 = L_102 ;
break;
}
goto V_206;
}
if ( V_8 -> V_232 == V_233 )
goto V_90;
F_148 ( V_8 ) ;
if ( V_8 -> V_53 == V_280 )
F_116 ( V_8 ) ;
goto V_90;
}
if ( V_8 -> V_232 == V_305 ) {
V_65 = F_141 ( V_8 ) ;
if ( V_65 <= 0 )
goto V_206;
F_142 ( V_8 ) ;
goto V_90;
}
V_206:
F_34 ( L_103 , V_8 , V_65 ) ;
return V_65 ;
V_307:
F_26 ( L_104 , ( int ) V_8 -> V_232 ) ;
V_8 -> V_77 = L_105 ;
V_65 = - 1 ;
goto V_206;
}
static int F_152 ( struct V_7 * V_8 , unsigned long V_121 )
{
if ( ! V_8 -> V_72 -> V_308 ( V_8 ) ) {
F_34 ( L_106 , V_42 , V_8 ) ;
return - V_309 ;
}
if ( ! F_153 ( V_34 , & V_8 -> V_114 , V_121 ) ) {
F_34 ( L_107 , V_42 , V_8 ) ;
V_8 -> V_72 -> V_101 ( V_8 ) ;
return - V_310 ;
}
F_34 ( L_108 , V_42 , V_8 , V_121 ) ;
return 0 ;
}
static void F_41 ( struct V_7 * V_8 )
{
( void ) F_152 ( V_8 , 0 ) ;
}
static bool F_154 ( struct V_7 * V_8 )
{
if ( ! F_9 ( V_8 , V_5 ) )
return false ;
#define CASE ( T_6 ) \
case CON_STATE_ ## x: \
con->error_msg = "socket closed (con state " #x ")"; \
break;
switch ( V_8 -> V_53 ) {
CASE ( V_311 ) ;
CASE ( V_312 ) ;
CASE ( V_313 ) ;
CASE ( V_314 ) ;
CASE ( V_315 ) ;
CASE ( V_316 ) ;
default:
F_137 ( L_109 ,
V_42 , V_8 , V_8 -> V_53 ) ;
V_8 -> V_77 = L_110 ;
F_103 () ;
break;
}
#undef CASE
return true ;
}
static bool F_155 ( struct V_7 * V_8 )
{
int V_65 ;
if ( ! F_9 ( V_8 , V_6 ) )
return false ;
V_65 = F_152 ( V_8 , F_156 ( V_8 -> V_121 ) ) ;
if ( V_65 ) {
F_34 ( L_111 , V_42 ,
V_8 , V_8 -> V_121 ) ;
F_3 ( V_65 == - V_309 ) ;
F_5 ( V_8 , V_6 ) ;
}
return true ;
}
static void F_157 ( struct V_7 * V_8 )
{
if ( V_8 -> V_185 && V_8 -> V_72 -> V_317 ) {
F_34 ( L_112 ) ;
V_8 -> V_72 -> V_317 ( V_8 ) ;
}
if ( V_8 -> V_72 -> V_318 )
V_8 -> V_72 -> V_318 ( V_8 ) ;
}
static void V_124 ( struct V_319 * V_114 )
{
struct V_7 * V_8 = F_158 ( V_114 , struct V_7 ,
V_114 . V_114 ) ;
bool V_318 ;
F_67 ( & V_8 -> V_111 ) ;
while ( true ) {
int V_65 ;
if ( ( V_318 = F_154 ( V_8 ) ) ) {
F_34 ( L_113 , V_42 , V_8 ) ;
break;
}
if ( F_155 ( V_8 ) ) {
F_34 ( L_114 , V_42 , V_8 ) ;
break;
}
if ( V_8 -> V_53 == V_320 ) {
F_34 ( L_115 , V_42 , V_8 ) ;
break;
}
if ( V_8 -> V_53 == V_112 ) {
F_34 ( L_116 , V_42 , V_8 ) ;
F_3 ( V_8 -> V_46 ) ;
break;
}
if ( V_8 -> V_53 == V_118 ) {
F_34 ( L_117 , V_42 , V_8 ) ;
F_3 ( V_8 -> V_46 ) ;
}
V_65 = F_151 ( V_8 ) ;
if ( V_65 < 0 ) {
if ( V_65 == - V_88 )
continue;
V_8 -> V_77 = L_118 ;
V_318 = true ;
break;
}
V_65 = F_150 ( V_8 ) ;
if ( V_65 < 0 ) {
if ( V_65 == - V_88 )
continue;
V_8 -> V_77 = L_119 ;
V_318 = true ;
}
break;
}
if ( V_318 )
F_159 ( V_8 ) ;
F_69 ( & V_8 -> V_111 ) ;
if ( V_318 )
F_157 ( V_8 ) ;
V_8 -> V_72 -> V_101 ( V_8 ) ;
}
static void F_159 ( struct V_7 * V_8 )
{
F_137 ( L_120 , F_140 ( V_8 -> V_119 ) ,
F_13 ( & V_8 -> V_63 . V_64 ) , V_8 -> V_77 ) ;
F_34 ( L_121 ,
V_8 , V_8 -> V_53 , F_13 ( & V_8 -> V_63 . V_64 ) ) ;
F_32 ( V_8 -> V_53 != V_300 &&
V_8 -> V_53 != V_186 &&
V_8 -> V_53 != V_280 ) ;
F_58 ( V_8 ) ;
if ( F_7 ( V_8 , V_2 ) ) {
F_34 ( L_122 ) ;
V_8 -> V_53 = V_112 ;
return;
}
if ( V_8 -> V_105 ) {
F_3 ( V_8 -> V_105 -> V_8 != V_8 ) ;
V_8 -> V_105 -> V_8 = NULL ;
F_61 ( V_8 -> V_105 ) ;
V_8 -> V_105 = NULL ;
V_8 -> V_72 -> V_101 ( V_8 ) ;
}
F_160 ( & V_8 -> V_104 , & V_8 -> V_103 ) ;
if ( F_63 ( & V_8 -> V_103 ) &&
! F_7 ( V_8 , V_3 ) ) {
F_34 ( L_123 , V_8 ) ;
F_2 ( V_8 , V_4 ) ;
V_8 -> V_53 = V_320 ;
} else {
V_8 -> V_53 = V_118 ;
if ( V_8 -> V_121 == 0 )
V_8 -> V_121 = V_321 ;
else if ( V_8 -> V_121 < V_322 )
V_8 -> V_121 *= 2 ;
F_5 ( V_8 , V_6 ) ;
F_41 ( V_8 ) ;
}
}
void F_161 ( struct V_29 * V_30 ,
struct V_117 * V_323 ,
T_4 V_200 ,
T_4 V_271 ,
bool V_213 )
{
V_30 -> V_200 = V_200 ;
V_30 -> V_271 = V_271 ;
F_162 ( & V_30 -> V_126 ) ;
if ( V_323 )
V_30 -> V_32 . V_33 = * V_323 ;
V_30 -> V_32 . V_33 . type = 0 ;
F_163 ( & V_30 -> V_32 . V_33 . V_268 , sizeof( V_30 -> V_32 . V_33 . V_268 ) ) ;
F_16 ( V_30 ) ;
V_30 -> V_213 = V_213 ;
F_164 ( & V_30 -> V_50 , 0 ) ;
F_34 ( L_124 , V_42 , V_30 ) ;
}
static void F_165 ( struct V_7 * V_8 )
{
if ( V_8 -> V_53 == V_320 ) {
F_34 ( L_125 , V_8 ) ;
V_8 -> V_53 = V_118 ;
V_8 -> V_106 ++ ;
F_32 ( F_7 ( V_8 , V_4 ) ) ;
F_32 ( F_7 ( V_8 , V_3 ) ) ;
}
}
void F_166 ( struct V_7 * V_8 , struct V_99 * V_83 )
{
V_83 -> V_143 . V_298 = V_8 -> V_30 -> V_32 . V_255 ;
F_3 ( V_83 -> V_168 . V_134 != F_92 ( V_83 -> V_143 . V_165 ) ) ;
V_83 -> V_163 = true ;
F_67 ( & V_8 -> V_111 ) ;
if ( V_8 -> V_53 == V_112 ) {
F_34 ( L_126 , V_8 , V_83 ) ;
F_61 ( V_83 ) ;
F_69 ( & V_8 -> V_111 ) ;
return;
}
F_3 ( V_83 -> V_8 != NULL ) ;
V_83 -> V_8 = V_8 -> V_72 -> V_308 ( V_8 ) ;
F_3 ( V_83 -> V_8 == NULL ) ;
F_3 ( ! F_63 ( & V_83 -> V_100 ) ) ;
F_167 ( & V_83 -> V_100 , & V_8 -> V_103 ) ;
F_34 ( L_127 , V_83 ,
F_140 ( V_8 -> V_119 ) , F_91 ( V_83 -> V_143 . type ) ,
F_149 ( F_91 ( V_83 -> V_143 . type ) ) ,
F_92 ( V_83 -> V_143 . V_165 ) ,
F_92 ( V_83 -> V_143 . V_166 ) ,
F_92 ( V_83 -> V_143 . V_144 ) ) ;
F_165 ( V_8 ) ;
F_69 ( & V_8 -> V_111 ) ;
if ( F_11 ( V_8 , V_4 ) == 0 )
F_41 ( V_8 ) ;
}
void F_168 ( struct V_99 * V_83 )
{
struct V_7 * V_8 = V_83 -> V_8 ;
if ( ! V_8 )
return;
F_67 ( & V_8 -> V_111 ) ;
if ( ! F_63 ( & V_83 -> V_100 ) ) {
F_34 ( L_128 , V_42 , V_8 , V_83 ) ;
F_60 ( & V_83 -> V_100 ) ;
F_3 ( V_83 -> V_8 == NULL ) ;
V_83 -> V_8 -> V_72 -> V_101 ( V_83 -> V_8 ) ;
V_83 -> V_8 = NULL ;
V_83 -> V_143 . V_164 = 0 ;
F_61 ( V_83 ) ;
}
if ( V_8 -> V_108 == V_83 ) {
F_34 ( L_129 , V_42 , V_8 , V_83 ) ;
V_8 -> V_108 = NULL ;
if ( V_8 -> V_157 ) {
V_8 -> V_229 = V_8 -> V_129 ;
V_8 -> V_157 = false ;
}
V_83 -> V_143 . V_164 = 0 ;
F_61 ( V_83 ) ;
}
F_69 ( & V_8 -> V_111 ) ;
}
void F_169 ( struct V_99 * V_83 )
{
struct V_7 * V_8 ;
F_3 ( V_83 == NULL ) ;
if ( ! V_83 -> V_8 ) {
F_34 ( L_130 , V_42 , V_83 ) ;
return;
}
V_8 = V_83 -> V_8 ;
F_67 ( & V_8 -> V_111 ) ;
if ( V_8 -> V_105 == V_83 ) {
unsigned int V_165 = F_92 ( V_8 -> V_291 . V_165 ) ;
unsigned int V_166 = F_92 ( V_8 -> V_291 . V_166 ) ;
unsigned int V_144 = F_92 ( V_8 -> V_291 . V_144 ) ;
F_34 ( L_131 , V_42 , V_8 , V_83 ) ;
V_8 -> V_231 = V_8 -> V_231 -
sizeof( struct V_172 ) -
V_165 -
V_166 -
V_144 -
sizeof( struct V_324 ) ;
F_61 ( V_8 -> V_105 ) ;
V_8 -> V_105 = NULL ;
V_8 -> V_232 = V_233 ;
V_8 -> V_109 ++ ;
} else {
F_34 ( L_132 ,
V_42 , V_8 , V_8 -> V_105 , V_83 ) ;
}
F_69 ( & V_8 -> V_111 ) ;
}
void F_170 ( struct V_7 * V_8 )
{
F_34 ( L_133 , V_8 ) ;
F_67 ( & V_8 -> V_111 ) ;
F_165 ( V_8 ) ;
F_69 ( & V_8 -> V_111 ) ;
if ( F_11 ( V_8 , V_3 ) == 0 &&
F_11 ( V_8 , V_4 ) == 0 )
F_41 ( V_8 ) ;
}
struct V_99 * F_171 ( int type , int V_165 , T_7 V_9 ,
bool V_325 )
{
struct V_99 * V_153 ;
V_153 = F_172 ( sizeof( * V_153 ) , V_9 ) ;
if ( V_153 == NULL )
goto V_206;
F_173 ( & V_153 -> V_326 ) ;
V_153 -> V_8 = NULL ;
F_75 ( & V_153 -> V_100 ) ;
V_153 -> V_143 . V_327 = 0 ;
V_153 -> V_143 . type = F_174 ( type ) ;
V_153 -> V_143 . V_328 = F_174 ( V_329 ) ;
V_153 -> V_143 . V_330 = 0 ;
V_153 -> V_143 . V_165 = F_95 ( V_165 ) ;
V_153 -> V_143 . V_166 = 0 ;
V_153 -> V_143 . V_144 = 0 ;
V_153 -> V_143 . V_331 = 0 ;
V_153 -> V_143 . V_332 = 0 ;
V_153 -> V_155 . V_173 = 0 ;
V_153 -> V_155 . V_174 = 0 ;
V_153 -> V_155 . V_175 = 0 ;
V_153 -> V_155 . V_9 = 0 ;
V_153 -> V_333 = V_165 ;
V_153 -> V_334 = false ;
V_153 -> V_158 = false ;
V_153 -> V_286 = 0 ;
V_153 -> V_335 = NULL ;
V_153 -> V_170 = NULL ;
V_153 -> V_167 = 0 ;
V_153 -> V_148 = 0 ;
V_153 -> V_146 = NULL ;
V_153 -> V_211 = NULL ;
#ifdef F_86
V_153 -> V_136 = NULL ;
V_153 -> V_140 = NULL ;
V_153 -> V_149 = 0 ;
#endif
V_153 -> V_210 = NULL ;
if ( V_165 ) {
if ( V_165 > V_230 ) {
V_153 -> V_168 . V_135 = F_175 ( V_165 , V_9 ,
V_336 ) ;
V_153 -> V_334 = true ;
} else {
V_153 -> V_168 . V_135 = F_172 ( V_165 , V_9 ) ;
}
if ( V_153 -> V_168 . V_135 == NULL ) {
F_34 ( L_134 ,
V_165 ) ;
goto V_337;
}
} else {
V_153 -> V_168 . V_135 = NULL ;
}
V_153 -> V_168 . V_134 = V_165 ;
F_34 ( L_135 , V_153 , V_165 ) ;
return V_153 ;
V_337:
F_61 ( V_153 ) ;
V_206:
if ( ! V_325 ) {
F_26 ( L_136 , type ,
V_165 ) ;
F_32 ( 1 ) ;
} else {
F_34 ( L_136 , type ,
V_165 ) ;
}
return NULL ;
}
static int F_176 ( struct V_7 * V_8 , struct V_99 * V_83 )
{
int type = F_91 ( V_83 -> V_143 . type ) ;
int V_166 = F_92 ( V_83 -> V_143 . V_166 ) ;
F_34 ( L_137 , V_83 , type ,
F_149 ( type ) , V_166 ) ;
F_3 ( ! V_166 ) ;
F_3 ( V_83 -> V_170 ) ;
V_83 -> V_170 = F_177 ( V_166 , V_69 ) ;
if ( ! V_83 -> V_170 )
return - V_37 ;
return 0 ;
}
static int F_147 ( struct V_7 * V_8 , int * V_297 )
{
struct V_172 * V_143 = & V_8 -> V_291 ;
int type = F_91 ( V_143 -> type ) ;
int V_165 = F_92 ( V_143 -> V_165 ) ;
int V_166 = F_92 ( V_143 -> V_166 ) ;
int V_65 = 0 ;
F_3 ( V_8 -> V_105 != NULL ) ;
if ( V_8 -> V_72 -> V_338 ) {
struct V_99 * V_83 ;
F_69 ( & V_8 -> V_111 ) ;
V_83 = V_8 -> V_72 -> V_338 ( V_8 , V_143 , V_297 ) ;
F_67 ( & V_8 -> V_111 ) ;
if ( V_8 -> V_53 != V_280 ) {
if ( V_83 )
F_61 ( V_83 ) ;
return - V_88 ;
}
V_8 -> V_105 = V_83 ;
if ( V_8 -> V_105 ) {
V_8 -> V_105 -> V_8 = V_8 -> V_72 -> V_308 ( V_8 ) ;
F_3 ( V_8 -> V_105 -> V_8 == NULL ) ;
}
if ( * V_297 ) {
V_8 -> V_105 = NULL ;
return 0 ;
}
if ( ! V_8 -> V_105 ) {
V_8 -> V_77 =
L_138 ;
return - V_37 ;
}
}
if ( ! V_8 -> V_105 ) {
V_8 -> V_105 = F_171 ( type , V_165 , V_69 , false ) ;
if ( ! V_8 -> V_105 ) {
F_26 ( L_139 ,
type , V_165 ) ;
return - V_37 ;
}
V_8 -> V_105 -> V_8 = V_8 -> V_72 -> V_308 ( V_8 ) ;
F_3 ( V_8 -> V_105 -> V_8 == NULL ) ;
V_8 -> V_105 -> V_148 = F_91 ( V_143 -> V_331 ) ;
}
memcpy ( & V_8 -> V_105 -> V_143 , & V_8 -> V_291 , sizeof( V_8 -> V_291 ) ) ;
if ( V_166 && ! V_8 -> V_105 -> V_170 ) {
V_65 = F_176 ( V_8 , V_8 -> V_105 ) ;
if ( V_65 < 0 ) {
F_61 ( V_8 -> V_105 ) ;
V_8 -> V_105 = NULL ;
}
}
return V_65 ;
}
void F_178 ( struct V_99 * V_153 )
{
F_34 ( L_140 , V_153 ) ;
if ( V_153 -> V_334 )
F_179 ( V_153 -> V_168 . V_135 ) ;
else
F_131 ( V_153 -> V_168 . V_135 ) ;
F_131 ( V_153 ) ;
}
void F_180 ( struct V_326 * V_326 )
{
struct V_99 * V_153 = F_158 ( V_326 , struct V_99 , V_326 ) ;
F_34 ( L_141 , V_153 ) ;
F_32 ( ! F_63 ( & V_153 -> V_100 ) ) ;
if ( V_153 -> V_170 ) {
F_181 ( V_153 -> V_170 ) ;
V_153 -> V_170 = NULL ;
}
V_153 -> V_167 = 0 ;
V_153 -> V_146 = NULL ;
if ( V_153 -> V_211 ) {
F_182 ( V_153 -> V_211 ) ;
F_131 ( V_153 -> V_211 ) ;
V_153 -> V_211 = NULL ;
}
V_153 -> V_210 = NULL ;
if ( V_153 -> V_335 )
F_183 ( V_153 -> V_335 , V_153 ) ;
else
F_178 ( V_153 ) ;
}
void F_184 ( struct V_99 * V_83 )
{
F_185 ( L_142 , V_83 ,
V_83 -> V_333 , V_83 -> V_167 ) ;
F_186 ( V_339 , L_143 ,
V_340 , 16 , 1 ,
& V_83 -> V_143 , sizeof( V_83 -> V_143 ) , true ) ;
F_186 ( V_339 , L_144 ,
V_340 , 16 , 1 ,
V_83 -> V_168 . V_135 , V_83 -> V_168 . V_134 , true ) ;
if ( V_83 -> V_170 )
F_186 ( V_339 , L_145 ,
V_340 , 16 , 1 ,
V_83 -> V_170 -> V_171 . V_135 ,
V_83 -> V_170 -> V_171 . V_134 , true ) ;
F_186 ( V_339 , L_146 ,
V_340 , 16 , 1 ,
& V_83 -> V_155 , sizeof( V_83 -> V_155 ) , true ) ;
}
