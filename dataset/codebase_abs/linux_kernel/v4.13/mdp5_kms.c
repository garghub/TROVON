static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_6 ;
F_4 ( & V_5 -> V_7 ) ;
F_5 ( V_3 ) ;
F_6 ( & V_3 -> V_8 , V_6 ) ;
F_7 ( V_3 , V_9 , 0 ) ;
F_8 ( & V_3 -> V_8 , V_6 ) ;
F_9 ( V_3 -> V_10 ) ;
F_10 ( V_3 ) ;
F_11 ( & V_5 -> V_7 ) ;
return 0 ;
}
struct V_11 * F_12 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_7 -> V_16 ;
struct V_3 * V_3 = F_2 ( F_3 ( V_15 -> V_2 ) ) ;
struct V_17 * V_18 = F_13 ( V_13 ) ;
struct V_11 * V_19 ;
int V_20 ;
if ( V_18 -> V_18 )
return V_18 -> V_18 ;
V_20 = F_14 ( & V_3 -> V_21 , V_13 -> V_22 ) ;
if ( V_20 )
return F_15 ( V_20 ) ;
V_19 = F_16 ( sizeof( * V_3 -> V_18 ) , V_23 ) ;
if ( ! V_19 )
return F_15 ( - V_24 ) ;
V_19 -> V_25 = V_3 -> V_18 -> V_25 ;
V_19 -> V_26 = V_3 -> V_18 -> V_26 ;
if ( V_3 -> V_27 )
V_19 -> V_27 = V_3 -> V_18 -> V_27 ;
V_18 -> V_18 = V_19 ;
return V_19 ;
}
static void F_17 ( struct V_1 * V_2 , struct V_12 * V_18 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_18 ( F_13 ( V_18 ) -> V_18 , V_3 -> V_18 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_12 * V_18 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_5 ( V_3 ) ;
if ( V_3 -> V_27 )
F_20 ( V_3 -> V_27 , & V_3 -> V_18 -> V_27 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_12 * V_18 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_3 -> V_27 )
F_22 ( V_3 -> V_27 , & V_3 -> V_18 -> V_27 ) ;
F_10 ( V_3 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
F_24 ( V_29 ) ;
}
static long F_25 ( struct V_1 * V_2 , unsigned long V_30 ,
struct V_31 * V_32 )
{
return V_30 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_31 * V_33 ,
bool V_34 )
{
if ( V_34 )
return F_27 ( V_32 ,
V_33 ) ;
else
return F_28 ( V_32 ,
V_33 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
bool V_35 )
{
F_30 ( V_32 , V_35 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_36 * V_37 = V_2 -> V_37 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_3 -> V_39 ; V_38 ++ )
F_32 ( V_3 -> V_40 [ V_38 ] ) ;
for ( V_38 = 0 ; V_38 < V_3 -> V_41 ; V_38 ++ )
F_33 ( V_3 -> V_42 [ V_38 ] ) ;
if ( V_37 ) {
V_37 -> V_43 -> V_44 -> V_45 ( V_37 -> V_43 ,
V_46 , F_34 ( V_46 ) ) ;
F_35 ( V_37 ) ;
}
}
static int F_36 ( struct V_47 * V_48 , void * V_49 )
{
struct V_50 * V_51 = (struct V_50 * ) V_48 -> V_52 ;
struct V_53 * V_7 = V_51 -> V_54 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_3 * V_3 = F_2 ( F_3 ( V_15 -> V_2 ) ) ;
struct V_55 V_56 = F_37 ( V_48 ) ;
if ( ! V_3 -> V_27 ) {
F_38 ( & V_56 , L_1 ) ;
return 0 ;
}
F_39 ( V_3 -> V_27 , & V_56 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_57 * V_54 )
{
struct V_53 * V_7 = V_54 -> V_7 ;
int V_20 ;
V_20 = F_41 ( V_58 ,
F_34 ( V_58 ) ,
V_54 -> V_59 , V_54 ) ;
if ( V_20 ) {
F_42 ( V_7 -> V_7 , L_2 ) ;
return V_20 ;
}
return 0 ;
}
int F_10 ( struct V_3 * V_3 )
{
F_43 ( L_3 ) ;
F_44 ( V_3 -> V_60 ) ;
F_44 ( V_3 -> V_61 ) ;
F_44 ( V_3 -> V_62 ) ;
if ( V_3 -> V_63 )
F_44 ( V_3 -> V_63 ) ;
return 0 ;
}
int F_5 ( struct V_3 * V_3 )
{
F_43 ( L_3 ) ;
F_45 ( V_3 -> V_60 ) ;
F_45 ( V_3 -> V_61 ) ;
F_45 ( V_3 -> V_62 ) ;
if ( V_3 -> V_63 )
F_45 ( V_3 -> V_63 ) ;
return 0 ;
}
static struct V_31 * F_46 ( struct V_3 * V_3 ,
struct V_64 * V_65 ,
struct V_66 * V_67 )
{
struct V_53 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_31 * V_32 ;
V_32 = F_47 ( V_7 , V_65 , V_67 ) ;
if ( F_48 ( V_32 ) ) {
F_42 ( V_7 -> V_7 , L_4 ) ;
return V_32 ;
}
V_15 -> V_68 [ V_15 -> V_69 ++ ] = V_32 ;
return V_32 ;
}
static int F_49 ( const struct V_70 * V_71 , int V_72 )
{
const enum V_73 * V_74 = V_71 -> V_65 . V_75 ;
const int V_76 = F_34 ( V_71 -> V_65 . V_75 ) ;
int V_77 = 0 , V_38 ;
for ( V_38 = 0 ; V_38 < V_76 ; V_38 ++ ) {
if ( V_74 [ V_38 ] == V_78 ) {
if ( V_72 == V_38 )
return V_77 ;
V_77 ++ ;
}
}
return - V_79 ;
}
static int F_50 ( struct V_3 * V_3 ,
struct V_64 * V_65 )
{
struct V_53 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_80 * V_10 = V_3 -> V_10 ;
struct V_66 * V_67 ;
struct V_31 * V_32 ;
int V_20 = 0 ;
switch ( V_65 -> type ) {
case V_81 :
if ( ! V_15 -> V_82 )
break;
V_67 = F_51 ( V_10 , V_65 -> V_83 ) ;
if ( ! V_67 ) {
V_20 = - V_79 ;
break;
}
V_32 = F_46 ( V_3 , V_65 , V_67 ) ;
if ( F_48 ( V_32 ) ) {
V_20 = F_52 ( V_32 ) ;
break;
}
V_20 = F_53 ( V_15 -> V_82 , V_7 , V_32 ) ;
break;
case V_84 :
if ( ! V_15 -> V_85 )
break;
V_67 = F_51 ( V_10 , V_65 -> V_83 ) ;
if ( ! V_67 ) {
V_20 = - V_79 ;
break;
}
V_32 = F_46 ( V_3 , V_65 , V_67 ) ;
if ( F_48 ( V_32 ) ) {
V_20 = F_52 ( V_32 ) ;
break;
}
V_20 = F_54 ( V_15 -> V_85 , V_7 , V_32 ) ;
break;
case V_78 :
{
const struct V_70 * V_71 =
F_55 ( V_3 -> V_86 ) ;
int V_87 = F_49 ( V_71 , V_65 -> V_83 ) ;
if ( ( V_87 >= F_34 ( V_15 -> V_88 ) ) || ( V_87 < 0 ) ) {
F_42 ( V_7 -> V_7 , L_5 ,
V_65 -> V_83 ) ;
V_20 = - V_79 ;
break;
}
if ( ! V_15 -> V_88 [ V_87 ] )
break;
V_67 = F_51 ( V_10 , V_65 -> V_83 ) ;
if ( ! V_67 ) {
V_20 = - V_79 ;
break;
}
V_32 = F_46 ( V_3 , V_65 , V_67 ) ;
if ( F_48 ( V_32 ) ) {
V_20 = F_52 ( V_32 ) ;
break;
}
V_20 = F_56 ( V_15 -> V_88 [ V_87 ] , V_7 , V_32 ) ;
break;
}
default:
F_42 ( V_7 -> V_7 , L_6 , V_65 -> type ) ;
V_20 = - V_79 ;
break;
}
return V_20 ;
}
static int F_57 ( struct V_3 * V_3 )
{
struct V_53 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_16 ;
const struct V_70 * V_71 ;
unsigned int V_89 ;
int V_38 , V_20 , V_90 = 0 , V_91 = 0 ;
struct V_92 * V_93 [ V_94 ] = { NULL } ;
struct V_92 * V_95 [ V_94 ] = { NULL } ;
V_71 = F_55 ( V_3 -> V_86 ) ;
for ( V_38 = 0 ; V_38 < V_3 -> V_96 ; V_38 ++ ) {
V_20 = F_50 ( V_3 , V_3 -> V_74 [ V_38 ] ) ;
if ( V_20 )
goto V_97;
}
V_89 = F_58 ( V_15 -> V_69 , V_3 -> V_39 ) ;
for ( V_38 = 0 ; V_38 < V_3 -> V_41 ; V_38 ++ ) {
struct V_98 * V_25 = V_3 -> V_42 [ V_38 ] ;
struct V_92 * V_99 ;
enum V_100 type ;
if ( V_38 < V_89 )
type = V_101 ;
else if ( V_25 -> V_102 & V_103 )
type = V_104 ;
else
type = V_105 ;
V_99 = F_59 ( V_7 , type ) ;
if ( F_48 ( V_99 ) ) {
V_20 = F_52 ( V_99 ) ;
F_42 ( V_7 -> V_7 , L_7 , V_38 , V_20 ) ;
goto V_97;
}
V_15 -> V_106 [ V_15 -> V_107 ++ ] = V_99 ;
if ( type == V_101 )
V_93 [ V_90 ++ ] = V_99 ;
if ( type == V_104 )
V_95 [ V_91 ++ ] = V_99 ;
}
for ( V_38 = 0 ; V_38 < V_89 ; V_38 ++ ) {
struct V_28 * V_29 ;
V_29 = F_60 ( V_7 , V_93 [ V_38 ] , V_95 [ V_38 ] , V_38 ) ;
if ( F_48 ( V_29 ) ) {
V_20 = F_52 ( V_29 ) ;
F_42 ( V_7 -> V_7 , L_8 , V_38 , V_20 ) ;
goto V_97;
}
V_15 -> V_108 [ V_15 -> V_89 ++ ] = V_29 ;
}
for ( V_38 = 0 ; V_38 < V_15 -> V_69 ; V_38 ++ ) {
struct V_31 * V_32 = V_15 -> V_68 [ V_38 ] ;
V_32 -> V_109 = ( 1 << V_15 -> V_89 ) - 1 ;
}
return 0 ;
V_97:
return V_20 ;
}
static void F_61 ( struct V_3 * V_3 ,
T_1 * V_110 , T_1 * V_54 )
{
T_1 V_111 ;
F_5 ( V_3 ) ;
V_111 = F_62 ( V_3 , V_112 ) ;
F_10 ( V_3 ) ;
* V_110 = F_63 ( V_111 , V_113 ) ;
* V_54 = F_63 ( V_111 , V_114 ) ;
F_43 ( L_9 , * V_110 , * V_54 ) ;
}
static int F_64 ( struct V_4 * V_5 , struct V_115 * * V_116 ,
const char * V_117 , bool V_118 )
{
struct V_119 * V_7 = & V_5 -> V_7 ;
struct V_115 * V_115 = F_65 ( V_5 , V_117 ) ;
if ( F_48 ( V_115 ) && V_118 ) {
F_42 ( V_7 , L_10 , V_117 , F_52 ( V_115 ) ) ;
return F_52 ( V_115 ) ;
}
if ( F_48 ( V_115 ) )
F_43 ( L_11 , V_117 ) ;
else
* V_116 = V_115 ;
return 0 ;
}
static struct V_31 * F_66 ( struct V_28 * V_29 )
{
struct V_53 * V_7 = V_29 -> V_7 ;
struct V_31 * V_32 ;
F_67 (encoder, dev)
if ( V_32 -> V_29 == V_29 )
return V_32 ;
return NULL ;
}
static bool F_68 ( struct V_53 * V_7 , unsigned int V_120 ,
bool V_121 , int * V_122 , int * V_123 ,
T_2 * V_124 , T_2 * V_125 ,
const struct V_126 * V_127 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_28 * V_29 ;
struct V_31 * V_32 ;
int line , V_128 , V_129 , V_130 , V_131 , V_132 ;
V_29 = V_15 -> V_108 [ V_120 ] ;
if ( ! V_29 ) {
F_69 ( L_12 , V_120 ) ;
return false ;
}
V_32 = F_66 ( V_29 ) ;
if ( ! V_32 ) {
F_69 ( L_13 , V_120 ) ;
return false ;
}
V_128 = V_127 -> V_133 - V_127 -> V_134 ;
V_129 = V_127 -> V_135 - V_127 -> V_133 ;
V_130 = V_128 + V_129 + 1 ;
V_131 = V_130 + V_127 -> V_136 ;
V_132 = V_127 -> V_135 ;
if ( V_124 )
* V_124 = F_70 () ;
line = F_71 ( V_32 ) ;
if ( line < V_130 ) {
line -= V_130 ;
} else if ( line > V_131 ) {
line = line - V_132 - V_130 ;
} else {
line -= V_130 ;
}
* V_122 = line ;
* V_123 = 0 ;
if ( V_125 )
* V_125 = F_70 () ;
return true ;
}
static T_1 F_72 ( struct V_53 * V_7 , unsigned int V_120 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_28 * V_29 ;
struct V_31 * V_32 ;
if ( V_120 < 0 || V_120 >= V_15 -> V_89 )
return 0 ;
V_29 = V_15 -> V_108 [ V_120 ] ;
if ( ! V_29 )
return 0 ;
V_32 = F_66 ( V_29 ) ;
if ( ! V_32 )
return 0 ;
return F_73 ( V_32 ) ;
}
struct V_1 * F_74 ( struct V_53 * V_7 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_4 * V_5 ;
struct V_3 * V_3 ;
struct V_137 * V_138 ;
struct V_1 * V_2 ;
struct V_36 * V_37 ;
int V_139 , V_38 , V_20 ;
V_2 = V_15 -> V_2 ;
if ( ! V_2 )
return NULL ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_75 ( & V_3 -> V_140 , & V_141 ) ;
V_5 = V_3 -> V_5 ;
V_139 = F_76 ( V_5 -> V_7 . V_142 , 0 ) ;
if ( V_139 < 0 ) {
V_20 = V_139 ;
F_42 ( & V_5 -> V_7 , L_14 , V_20 ) ;
goto V_97;
}
V_2 -> V_139 = V_139 ;
V_138 = F_77 ( V_3 -> V_86 ) ;
F_5 ( V_3 ) ;
for ( V_38 = 0 ; V_38 < V_143 ; V_38 ++ ) {
if ( F_78 ( V_138 -> V_144 -> V_65 . V_75 [ V_38 ] ) ||
! V_138 -> V_144 -> V_65 . V_140 [ V_38 ] )
continue;
F_7 ( V_3 , F_79 ( V_38 ) , 0 ) ;
F_7 ( V_3 , F_80 ( V_38 ) , 0x3 ) ;
}
F_10 ( V_3 ) ;
F_81 ( 16 ) ;
if ( V_138 -> V_145 . V_146 ) {
V_37 = F_82 ( & V_5 -> V_7 ,
V_138 -> V_145 . V_146 , L_15 ) ;
if ( F_48 ( V_37 ) ) {
V_20 = F_52 ( V_37 ) ;
goto V_97;
}
V_2 -> V_37 = V_37 ;
V_20 = V_37 -> V_43 -> V_44 -> V_147 ( V_37 -> V_43 , V_46 ,
F_34 ( V_46 ) ) ;
if ( V_20 ) {
F_42 ( & V_5 -> V_7 , L_16 ,
V_20 ) ;
goto V_97;
}
} else {
F_83 ( & V_5 -> V_7 ,
L_17 ) ;
V_37 = NULL ; ;
}
V_20 = F_57 ( V_3 ) ;
if ( V_20 ) {
F_42 ( & V_5 -> V_7 , L_18 , V_20 ) ;
goto V_97;
}
V_7 -> V_148 . V_149 = 0 ;
V_7 -> V_148 . V_150 = 0 ;
V_7 -> V_148 . V_151 = 0xffff ;
V_7 -> V_148 . V_152 = 0xffff ;
V_7 -> V_153 -> V_154 = V_155 ;
V_7 -> V_153 -> V_156 = F_68 ;
V_7 -> V_153 -> V_157 = F_72 ;
V_7 -> V_158 = 0xffffffff ;
V_7 -> V_159 = true ;
return V_2 ;
V_97:
if ( V_2 )
F_31 ( V_2 ) ;
return F_15 ( V_20 ) ;
}
static void F_84 ( struct V_4 * V_5 )
{
struct V_3 * V_3 = F_85 ( V_5 ) ;
int V_38 ;
if ( V_3 -> V_10 )
F_86 ( V_3 -> V_10 ) ;
if ( V_3 -> V_27 )
F_87 ( V_3 -> V_27 ) ;
if ( V_3 -> V_86 )
F_88 ( V_3 -> V_86 ) ;
for ( V_38 = 0 ; V_38 < V_3 -> V_96 ; V_38 ++ )
F_89 ( V_3 -> V_74 [ V_38 ] ) ;
if ( V_3 -> V_160 )
F_90 ( & V_5 -> V_7 ) ;
F_89 ( V_3 -> V_18 ) ;
}
static int F_91 ( struct V_3 * V_3 , int V_161 ,
const enum V_162 * V_163 , const T_3 * V_164 ,
T_3 V_102 )
{
struct V_53 * V_7 = V_3 -> V_7 ;
int V_38 , V_20 ;
for ( V_38 = 0 ; V_38 < V_161 ; V_38 ++ ) {
struct V_98 * V_25 ;
V_25 = F_92 ( V_163 [ V_38 ] , V_164 [ V_38 ] , V_102 ) ;
if ( F_48 ( V_25 ) ) {
V_20 = F_52 ( V_25 ) ;
F_42 ( V_7 -> V_7 , L_19 ,
F_93 ( V_163 [ V_38 ] ) , V_20 ) ;
return V_20 ;
}
V_25 -> V_165 = V_3 -> V_41 ;
V_3 -> V_42 [ V_3 -> V_41 ++ ] = V_25 ;
}
return 0 ;
}
static int F_94 ( struct V_3 * V_3 )
{
static const enum V_162 V_166 [] = {
V_167 , V_168 , V_169 , V_170 ,
} ;
static const enum V_162 V_171 [] = {
V_172 , V_173 , V_174 , V_175 ,
} ;
static const enum V_162 V_176 [] = {
V_177 , V_178 ,
} ;
static const enum V_162 V_179 [] = {
V_180 , V_181 ,
} ;
const struct V_70 * V_71 ;
int V_20 ;
V_71 = F_55 ( V_3 -> V_86 ) ;
V_20 = F_91 ( V_3 , V_71 -> V_182 . V_183 , V_166 ,
V_71 -> V_182 . V_140 , V_71 -> V_182 . V_102 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_91 ( V_3 , V_71 -> V_184 . V_183 , V_171 ,
V_71 -> V_184 . V_140 , V_71 -> V_184 . V_102 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_91 ( V_3 , V_71 -> V_185 . V_183 , V_176 ,
V_71 -> V_185 . V_140 , V_71 -> V_185 . V_102 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_91 ( V_3 , V_71 -> V_186 . V_183 ,
V_179 , V_71 -> V_186 . V_140 ,
V_71 -> V_186 . V_102 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
static int F_95 ( struct V_3 * V_3 )
{
struct V_53 * V_7 = V_3 -> V_7 ;
const struct V_70 * V_71 ;
int V_38 , V_20 ;
V_71 = F_55 ( V_3 -> V_86 ) ;
for ( V_38 = 0 ; V_38 < V_71 -> V_187 . V_183 ; V_38 ++ ) {
struct V_188 * V_189 ;
V_189 = F_96 ( & V_71 -> V_187 . V_190 [ V_38 ] ) ;
if ( F_48 ( V_189 ) ) {
V_20 = F_52 ( V_189 ) ;
F_42 ( V_7 -> V_7 , L_20 ,
V_38 , V_20 ) ;
return V_20 ;
}
V_189 -> V_165 = V_3 -> V_39 ;
V_3 -> V_40 [ V_3 -> V_39 ++ ] = V_189 ;
}
return 0 ;
}
static int F_97 ( struct V_3 * V_3 )
{
struct V_53 * V_7 = V_3 -> V_7 ;
const struct V_70 * V_71 ;
const enum V_73 * V_191 ;
int V_38 ;
V_71 = F_55 ( V_3 -> V_86 ) ;
V_191 = V_71 -> V_65 . V_75 ;
for ( V_38 = 0 ; V_38 < F_34 ( V_71 -> V_65 . V_75 ) ; V_38 ++ ) {
struct V_64 * V_65 ;
if ( V_191 [ V_38 ] == V_192 )
continue;
V_65 = F_98 ( sizeof( * V_65 ) , V_23 ) ;
if ( ! V_65 ) {
F_42 ( V_7 -> V_7 , L_21 , V_38 ) ;
return - V_24 ;
}
V_65 -> V_83 = V_38 ;
V_65 -> type = V_191 [ V_38 ] ;
V_65 -> V_127 = V_193 ;
V_65 -> V_165 = V_3 -> V_96 ;
V_3 -> V_74 [ V_3 -> V_96 ++ ] = V_65 ;
}
return 0 ;
}
static int F_99 ( struct V_4 * V_5 , struct V_53 * V_7 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_3 * V_3 ;
struct V_137 * V_138 ;
T_1 V_110 , V_54 ;
int V_20 ;
V_3 = F_100 ( & V_5 -> V_7 , sizeof( * V_3 ) , V_23 ) ;
if ( ! V_3 ) {
V_20 = - V_24 ;
goto V_97;
}
F_101 ( V_5 , V_3 ) ;
F_102 ( & V_3 -> V_8 ) ;
V_3 -> V_7 = V_7 ;
V_3 -> V_5 = V_5 ;
F_103 ( & V_3 -> V_21 ) ;
V_3 -> V_18 = F_98 ( sizeof( * V_3 -> V_18 ) , V_23 ) ;
if ( ! V_3 -> V_18 ) {
V_20 = - V_24 ;
goto V_97;
}
V_3 -> V_194 = F_104 ( V_5 , L_22 , L_23 ) ;
if ( F_48 ( V_3 -> V_194 ) ) {
V_20 = F_52 ( V_3 -> V_194 ) ;
goto V_97;
}
V_20 = F_64 ( V_5 , & V_3 -> V_61 , L_24 , true ) ;
if ( V_20 )
goto V_97;
V_20 = F_64 ( V_5 , & V_3 -> V_60 , L_25 , true ) ;
if ( V_20 )
goto V_97;
V_20 = F_64 ( V_5 , & V_3 -> V_62 , L_26 , true ) ;
if ( V_20 )
goto V_97;
V_20 = F_64 ( V_5 , & V_3 -> V_195 , L_27 , true ) ;
if ( V_20 )
goto V_97;
F_64 ( V_5 , & V_3 -> V_63 , L_28 , false ) ;
F_105 ( V_3 -> V_62 , 200000000 ) ;
F_106 ( & V_5 -> V_7 ) ;
V_3 -> V_160 = true ;
F_61 ( V_3 , & V_110 , & V_54 ) ;
V_3 -> V_86 = F_107 ( V_3 , V_110 , V_54 ) ;
if ( F_48 ( V_3 -> V_86 ) ) {
V_20 = F_52 ( V_3 -> V_86 ) ;
V_3 -> V_86 = NULL ;
goto V_97;
}
V_138 = F_77 ( V_3 -> V_86 ) ;
V_3 -> V_102 = V_138 -> V_144 -> V_196 . V_102 ;
F_105 ( V_3 -> V_62 , V_138 -> V_144 -> V_197 ) ;
if ( V_3 -> V_102 & V_198 ) {
V_3 -> V_27 = F_108 ( V_3 , & V_138 -> V_144 -> V_27 ) ;
if ( F_48 ( V_3 -> V_27 ) ) {
V_20 = F_52 ( V_3 -> V_27 ) ;
V_3 -> V_27 = NULL ;
goto V_97;
}
}
V_3 -> V_10 = F_109 ( V_7 , V_3 -> V_194 , V_3 -> V_86 ) ;
if ( F_48 ( V_3 -> V_10 ) ) {
V_20 = F_52 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
goto V_97;
}
V_20 = F_94 ( V_3 ) ;
if ( V_20 )
goto V_97;
V_20 = F_95 ( V_3 ) ;
if ( V_20 )
goto V_97;
V_20 = F_97 ( V_3 ) ;
if ( V_20 )
goto V_97;
V_15 -> V_2 = & V_3 -> V_140 . V_140 ;
return 0 ;
V_97:
F_84 ( V_5 ) ;
return V_20 ;
}
static int F_110 ( struct V_119 * V_7 , struct V_119 * V_199 , void * V_200 )
{
struct V_53 * V_201 = F_111 ( V_199 ) ;
struct V_4 * V_5 = F_112 ( V_7 ) ;
F_43 ( L_3 ) ;
return F_99 ( V_5 , V_201 ) ;
}
static void F_113 ( struct V_119 * V_7 , struct V_119 * V_199 ,
void * V_200 )
{
struct V_4 * V_5 = F_112 ( V_7 ) ;
F_84 ( V_5 ) ;
}
static int F_114 ( struct V_4 * V_5 )
{
F_43 ( L_3 ) ;
return F_115 ( & V_5 -> V_7 , & V_202 ) ;
}
static int F_116 ( struct V_4 * V_5 )
{
F_43 ( L_3 ) ;
F_117 ( & V_5 -> V_7 , & V_202 ) ;
return 0 ;
}
void T_4 F_118 ( void )
{
F_43 ( L_3 ) ;
F_119 ( & V_203 ) ;
}
void T_5 F_120 ( void )
{
F_43 ( L_3 ) ;
F_121 ( & V_203 ) ;
}
