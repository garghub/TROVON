static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_4 * V_5 = & V_3 -> V_6 -> V_5 ;
unsigned long V_7 ;
F_4 ( V_5 ) ;
F_5 ( & V_3 -> V_8 , V_7 ) ;
F_6 ( V_3 , V_9 , 0 ) ;
F_7 ( & V_3 -> V_8 , V_7 ) ;
F_8 ( V_3 -> V_10 ) ;
F_9 ( V_5 ) ;
return 0 ;
}
struct V_11 * F_10 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_5 -> V_16 ;
struct V_3 * V_3 = F_2 ( F_3 ( V_15 -> V_2 ) ) ;
struct V_17 * V_18 = F_11 ( V_13 ) ;
struct V_11 * V_19 ;
int V_20 ;
if ( V_18 -> V_18 )
return V_18 -> V_18 ;
V_20 = F_12 ( & V_3 -> V_21 , V_13 -> V_22 ) ;
if ( V_20 )
return F_13 ( V_20 ) ;
V_19 = F_14 ( sizeof( * V_3 -> V_18 ) , V_23 ) ;
if ( ! V_19 )
return F_13 ( - V_24 ) ;
V_19 -> V_25 = V_3 -> V_18 -> V_25 ;
V_19 -> V_26 = V_3 -> V_18 -> V_26 ;
if ( V_3 -> V_27 )
V_19 -> V_27 = V_3 -> V_18 -> V_27 ;
V_18 -> V_18 = V_19 ;
return V_19 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_12 * V_18 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_16 ( F_11 ( V_18 ) -> V_18 , V_3 -> V_18 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_12 * V_18 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_4 * V_5 = & V_3 -> V_6 -> V_5 ;
F_4 ( V_5 ) ;
if ( V_3 -> V_27 )
F_18 ( V_3 -> V_27 , & V_3 -> V_18 -> V_27 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_12 * V_18 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_4 * V_5 = & V_3 -> V_6 -> V_5 ;
if ( V_3 -> V_27 )
F_20 ( V_3 -> V_27 , & V_3 -> V_18 -> V_27 ) ;
F_21 ( V_5 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
F_23 ( V_29 ) ;
}
static long F_24 ( struct V_1 * V_2 , unsigned long V_30 ,
struct V_31 * V_32 )
{
return V_30 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_31 * V_33 ,
bool V_34 )
{
if ( V_34 )
return F_26 ( V_32 ,
V_33 ) ;
else
return F_27 ( V_32 ,
V_33 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
bool V_35 )
{
F_29 ( V_32 , V_35 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_36 * V_37 = V_2 -> V_37 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_3 -> V_39 ; V_38 ++ )
F_31 ( V_3 -> V_40 [ V_38 ] ) ;
for ( V_38 = 0 ; V_38 < V_3 -> V_41 ; V_38 ++ )
F_32 ( V_3 -> V_42 [ V_38 ] ) ;
if ( V_37 ) {
V_37 -> V_43 -> V_44 -> V_45 ( V_37 -> V_43 ,
V_46 , F_33 ( V_46 ) ) ;
F_34 ( V_37 ) ;
}
}
static int F_35 ( struct V_47 * V_48 , void * V_49 )
{
struct V_50 * V_51 = (struct V_50 * ) V_48 -> V_52 ;
struct V_53 * V_5 = V_51 -> V_54 -> V_5 ;
struct V_14 * V_15 = V_5 -> V_16 ;
struct V_3 * V_3 = F_2 ( F_3 ( V_15 -> V_2 ) ) ;
struct V_55 V_56 = F_36 ( V_48 ) ;
if ( ! V_3 -> V_27 ) {
F_37 ( & V_56 , L_1 ) ;
return 0 ;
}
F_38 ( V_3 -> V_27 , & V_56 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_57 * V_54 )
{
struct V_53 * V_5 = V_54 -> V_5 ;
int V_20 ;
V_20 = F_40 ( V_58 ,
F_33 ( V_58 ) ,
V_54 -> V_59 , V_54 ) ;
if ( V_20 ) {
F_41 ( V_5 -> V_5 , L_2 ) ;
return V_20 ;
}
return 0 ;
}
int F_42 ( struct V_3 * V_3 )
{
F_43 ( L_3 ) ;
V_3 -> V_60 -- ;
F_44 ( V_3 -> V_60 < 0 ) ;
F_45 ( V_3 -> V_61 ) ;
F_45 ( V_3 -> V_62 ) ;
F_45 ( V_3 -> V_63 ) ;
if ( V_3 -> V_64 )
F_45 ( V_3 -> V_64 ) ;
return 0 ;
}
int F_46 ( struct V_3 * V_3 )
{
F_43 ( L_3 ) ;
V_3 -> V_60 ++ ;
F_47 ( V_3 -> V_61 ) ;
F_47 ( V_3 -> V_62 ) ;
F_47 ( V_3 -> V_63 ) ;
if ( V_3 -> V_64 )
F_47 ( V_3 -> V_64 ) ;
return 0 ;
}
static struct V_31 * F_48 ( struct V_3 * V_3 ,
struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_53 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 = V_5 -> V_16 ;
struct V_31 * V_32 ;
V_32 = F_49 ( V_5 , V_66 , V_68 ) ;
if ( F_50 ( V_32 ) ) {
F_41 ( V_5 -> V_5 , L_4 ) ;
return V_32 ;
}
V_15 -> V_69 [ V_15 -> V_70 ++ ] = V_32 ;
return V_32 ;
}
static int F_51 ( const struct V_71 * V_72 , int V_73 )
{
const enum V_74 * V_75 = V_72 -> V_66 . V_76 ;
const int V_77 = F_33 ( V_72 -> V_66 . V_76 ) ;
int V_78 = 0 , V_38 ;
for ( V_38 = 0 ; V_38 < V_77 ; V_38 ++ ) {
if ( V_75 [ V_38 ] == V_79 ) {
if ( V_73 == V_38 )
return V_78 ;
V_78 ++ ;
}
}
return - V_80 ;
}
static int F_52 ( struct V_3 * V_3 ,
struct V_65 * V_66 )
{
struct V_53 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 = V_5 -> V_16 ;
struct V_81 * V_10 = V_3 -> V_10 ;
struct V_67 * V_68 ;
struct V_31 * V_32 ;
int V_20 = 0 ;
switch ( V_66 -> type ) {
case V_82 :
if ( ! V_15 -> V_83 )
break;
V_68 = F_53 ( V_10 , V_66 -> V_84 ) ;
if ( ! V_68 ) {
V_20 = - V_80 ;
break;
}
V_32 = F_48 ( V_3 , V_66 , V_68 ) ;
if ( F_50 ( V_32 ) ) {
V_20 = F_54 ( V_32 ) ;
break;
}
V_20 = F_55 ( V_15 -> V_83 , V_5 , V_32 ) ;
break;
case V_85 :
if ( ! V_15 -> V_86 )
break;
V_68 = F_53 ( V_10 , V_66 -> V_84 ) ;
if ( ! V_68 ) {
V_20 = - V_80 ;
break;
}
V_32 = F_48 ( V_3 , V_66 , V_68 ) ;
if ( F_50 ( V_32 ) ) {
V_20 = F_54 ( V_32 ) ;
break;
}
V_20 = F_56 ( V_15 -> V_86 , V_5 , V_32 ) ;
break;
case V_79 :
{
const struct V_71 * V_72 =
F_57 ( V_3 -> V_87 ) ;
int V_88 = F_51 ( V_72 , V_66 -> V_84 ) ;
if ( ( V_88 >= F_33 ( V_15 -> V_89 ) ) || ( V_88 < 0 ) ) {
F_41 ( V_5 -> V_5 , L_5 ,
V_66 -> V_84 ) ;
V_20 = - V_80 ;
break;
}
if ( ! V_15 -> V_89 [ V_88 ] )
break;
V_68 = F_53 ( V_10 , V_66 -> V_84 ) ;
if ( ! V_68 ) {
V_20 = - V_80 ;
break;
}
V_32 = F_48 ( V_3 , V_66 , V_68 ) ;
if ( F_50 ( V_32 ) ) {
V_20 = F_54 ( V_32 ) ;
break;
}
V_20 = F_58 ( V_15 -> V_89 [ V_88 ] , V_5 , V_32 ) ;
break;
}
default:
F_41 ( V_5 -> V_5 , L_6 , V_66 -> type ) ;
V_20 = - V_80 ;
break;
}
return V_20 ;
}
static int F_59 ( struct V_3 * V_3 )
{
struct V_53 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 = V_5 -> V_16 ;
const struct V_71 * V_72 ;
unsigned int V_90 ;
int V_38 , V_20 , V_91 = 0 , V_92 = 0 ;
struct V_93 * V_94 [ V_95 ] = { NULL } ;
struct V_93 * V_96 [ V_95 ] = { NULL } ;
V_72 = F_57 ( V_3 -> V_87 ) ;
for ( V_38 = 0 ; V_38 < V_3 -> V_97 ; V_38 ++ ) {
V_20 = F_52 ( V_3 , V_3 -> V_75 [ V_38 ] ) ;
if ( V_20 )
goto V_98;
}
V_90 = F_60 ( V_15 -> V_70 , V_3 -> V_39 ) ;
for ( V_38 = 0 ; V_38 < V_3 -> V_41 ; V_38 ++ ) {
struct V_99 * V_25 = V_3 -> V_42 [ V_38 ] ;
struct V_93 * V_100 ;
enum V_101 type ;
if ( V_38 < V_90 )
type = V_102 ;
else if ( V_25 -> V_103 & V_104 )
type = V_105 ;
else
type = V_106 ;
V_100 = F_61 ( V_5 , type ) ;
if ( F_50 ( V_100 ) ) {
V_20 = F_54 ( V_100 ) ;
F_41 ( V_5 -> V_5 , L_7 , V_38 , V_20 ) ;
goto V_98;
}
V_15 -> V_107 [ V_15 -> V_108 ++ ] = V_100 ;
if ( type == V_102 )
V_94 [ V_91 ++ ] = V_100 ;
if ( type == V_105 )
V_96 [ V_92 ++ ] = V_100 ;
}
for ( V_38 = 0 ; V_38 < V_90 ; V_38 ++ ) {
struct V_28 * V_29 ;
V_29 = F_62 ( V_5 , V_94 [ V_38 ] , V_96 [ V_38 ] , V_38 ) ;
if ( F_50 ( V_29 ) ) {
V_20 = F_54 ( V_29 ) ;
F_41 ( V_5 -> V_5 , L_8 , V_38 , V_20 ) ;
goto V_98;
}
V_15 -> V_109 [ V_15 -> V_90 ++ ] = V_29 ;
}
for ( V_38 = 0 ; V_38 < V_15 -> V_70 ; V_38 ++ ) {
struct V_31 * V_32 = V_15 -> V_69 [ V_38 ] ;
V_32 -> V_110 = ( 1 << V_15 -> V_90 ) - 1 ;
}
return 0 ;
V_98:
return V_20 ;
}
static void F_63 ( struct V_3 * V_3 ,
T_1 * V_111 , T_1 * V_54 )
{
struct V_4 * V_5 = & V_3 -> V_6 -> V_5 ;
T_1 V_112 ;
F_4 ( V_5 ) ;
V_112 = F_64 ( V_3 , V_113 ) ;
F_21 ( V_5 ) ;
* V_111 = F_65 ( V_112 , V_114 ) ;
* V_54 = F_65 ( V_112 , V_115 ) ;
F_43 ( L_9 , * V_111 , * V_54 ) ;
}
static int F_66 ( struct V_116 * V_6 , struct V_117 * * V_118 ,
const char * V_119 , bool V_120 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
struct V_117 * V_117 = F_67 ( V_6 , V_119 ) ;
if ( F_50 ( V_117 ) && V_120 ) {
F_41 ( V_5 , L_10 , V_119 , F_54 ( V_117 ) ) ;
return F_54 ( V_117 ) ;
}
if ( F_50 ( V_117 ) )
F_43 ( L_11 , V_119 ) ;
else
* V_118 = V_117 ;
return 0 ;
}
static struct V_31 * F_68 ( struct V_28 * V_29 )
{
struct V_53 * V_5 = V_29 -> V_5 ;
struct V_31 * V_32 ;
F_69 (encoder, dev)
if ( V_32 -> V_29 == V_29 )
return V_32 ;
return NULL ;
}
static bool F_70 ( struct V_53 * V_5 , unsigned int V_121 ,
bool V_122 , int * V_123 , int * V_124 ,
T_2 * V_125 , T_2 * V_126 ,
const struct V_127 * V_128 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
struct V_28 * V_29 ;
struct V_31 * V_32 ;
int line , V_129 , V_130 , V_131 , V_132 , V_133 ;
V_29 = V_15 -> V_109 [ V_121 ] ;
if ( ! V_29 ) {
F_71 ( L_12 , V_121 ) ;
return false ;
}
V_32 = F_68 ( V_29 ) ;
if ( ! V_32 ) {
F_71 ( L_13 , V_121 ) ;
return false ;
}
V_129 = V_128 -> V_134 - V_128 -> V_135 ;
V_130 = V_128 -> V_136 - V_128 -> V_134 ;
V_131 = V_129 + V_130 + 1 ;
V_132 = V_131 + V_128 -> V_137 ;
V_133 = V_128 -> V_136 ;
if ( V_125 )
* V_125 = F_72 () ;
line = F_73 ( V_32 ) ;
if ( line < V_131 ) {
line -= V_131 ;
} else if ( line > V_132 ) {
line = line - V_133 - V_131 ;
} else {
line -= V_131 ;
}
* V_123 = line ;
* V_124 = 0 ;
if ( V_126 )
* V_126 = F_72 () ;
return true ;
}
static T_1 F_74 ( struct V_53 * V_5 , unsigned int V_121 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
struct V_28 * V_29 ;
struct V_31 * V_32 ;
if ( V_121 < 0 || V_121 >= V_15 -> V_90 )
return 0 ;
V_29 = V_15 -> V_109 [ V_121 ] ;
if ( ! V_29 )
return 0 ;
V_32 = F_68 ( V_29 ) ;
if ( ! V_32 )
return 0 ;
return F_75 ( V_32 ) ;
}
struct V_1 * F_76 ( struct V_53 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
struct V_116 * V_6 ;
struct V_3 * V_3 ;
struct V_138 * V_139 ;
struct V_1 * V_2 ;
struct V_36 * V_37 ;
int V_140 , V_38 , V_20 ;
V_2 = V_15 -> V_2 ;
if ( ! V_2 )
return NULL ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_77 ( & V_3 -> V_141 , & V_142 ) ;
V_6 = V_3 -> V_6 ;
V_140 = F_78 ( V_6 -> V_5 . V_143 , 0 ) ;
if ( V_140 < 0 ) {
V_20 = V_140 ;
F_41 ( & V_6 -> V_5 , L_14 , V_20 ) ;
goto V_98;
}
V_2 -> V_140 = V_140 ;
V_139 = F_79 ( V_3 -> V_87 ) ;
F_4 ( & V_6 -> V_5 ) ;
for ( V_38 = 0 ; V_38 < V_144 ; V_38 ++ ) {
if ( F_80 ( V_139 -> V_145 -> V_66 . V_76 [ V_38 ] ) ||
! V_139 -> V_145 -> V_66 . V_141 [ V_38 ] )
continue;
F_6 ( V_3 , F_81 ( V_38 ) , 0 ) ;
F_6 ( V_3 , F_82 ( V_38 ) , 0x3 ) ;
}
F_83 ( 16 ) ;
if ( V_139 -> V_146 . V_147 ) {
V_37 = F_84 ( & V_6 -> V_5 ,
V_139 -> V_146 . V_147 , L_15 ) ;
if ( F_50 ( V_37 ) ) {
V_20 = F_54 ( V_37 ) ;
goto V_98;
}
V_2 -> V_37 = V_37 ;
V_20 = V_37 -> V_43 -> V_44 -> V_148 ( V_37 -> V_43 , V_46 ,
F_33 ( V_46 ) ) ;
if ( V_20 ) {
F_41 ( & V_6 -> V_5 , L_16 ,
V_20 ) ;
goto V_98;
}
} else {
F_85 ( & V_6 -> V_5 ,
L_17 ) ;
V_37 = NULL ; ;
}
F_21 ( & V_6 -> V_5 ) ;
V_20 = F_59 ( V_3 ) ;
if ( V_20 ) {
F_41 ( & V_6 -> V_5 , L_18 , V_20 ) ;
goto V_98;
}
V_5 -> V_149 . V_150 = 0 ;
V_5 -> V_149 . V_151 = 0 ;
V_5 -> V_149 . V_152 = 0xffff ;
V_5 -> V_149 . V_153 = 0xffff ;
V_5 -> V_154 -> V_155 = V_156 ;
V_5 -> V_154 -> V_157 = F_70 ;
V_5 -> V_154 -> V_158 = F_74 ;
V_5 -> V_159 = 0xffffffff ;
V_5 -> V_160 = true ;
return V_2 ;
V_98:
if ( V_2 )
F_30 ( V_2 ) ;
return F_13 ( V_20 ) ;
}
static void F_86 ( struct V_116 * V_6 )
{
struct V_3 * V_3 = F_87 ( V_6 ) ;
int V_38 ;
if ( V_3 -> V_10 )
F_88 ( V_3 -> V_10 ) ;
if ( V_3 -> V_27 )
F_89 ( V_3 -> V_27 ) ;
if ( V_3 -> V_87 )
F_90 ( V_3 -> V_87 ) ;
for ( V_38 = 0 ; V_38 < V_3 -> V_97 ; V_38 ++ )
F_91 ( V_3 -> V_75 [ V_38 ] ) ;
if ( V_3 -> V_161 )
F_92 ( & V_6 -> V_5 ) ;
F_91 ( V_3 -> V_18 ) ;
}
static int F_93 ( struct V_3 * V_3 , int V_162 ,
const enum V_163 * V_164 , const T_3 * V_165 ,
T_3 V_103 )
{
struct V_53 * V_5 = V_3 -> V_5 ;
int V_38 , V_20 ;
for ( V_38 = 0 ; V_38 < V_162 ; V_38 ++ ) {
struct V_99 * V_25 ;
V_25 = F_94 ( V_164 [ V_38 ] , V_165 [ V_38 ] , V_103 ) ;
if ( F_50 ( V_25 ) ) {
V_20 = F_54 ( V_25 ) ;
F_41 ( V_5 -> V_5 , L_19 ,
F_95 ( V_164 [ V_38 ] ) , V_20 ) ;
return V_20 ;
}
V_25 -> V_166 = V_3 -> V_41 ;
V_3 -> V_42 [ V_3 -> V_41 ++ ] = V_25 ;
}
return 0 ;
}
static int F_96 ( struct V_3 * V_3 )
{
static const enum V_163 V_167 [] = {
V_168 , V_169 , V_170 , V_171 ,
} ;
static const enum V_163 V_172 [] = {
V_173 , V_174 , V_175 , V_176 ,
} ;
static const enum V_163 V_177 [] = {
V_178 , V_179 ,
} ;
static const enum V_163 V_180 [] = {
V_181 , V_182 ,
} ;
const struct V_71 * V_72 ;
int V_20 ;
V_72 = F_57 ( V_3 -> V_87 ) ;
V_20 = F_93 ( V_3 , V_72 -> V_183 . V_184 , V_167 ,
V_72 -> V_183 . V_141 , V_72 -> V_183 . V_103 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_93 ( V_3 , V_72 -> V_185 . V_184 , V_172 ,
V_72 -> V_185 . V_141 , V_72 -> V_185 . V_103 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_93 ( V_3 , V_72 -> V_186 . V_184 , V_177 ,
V_72 -> V_186 . V_141 , V_72 -> V_186 . V_103 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_93 ( V_3 , V_72 -> V_187 . V_184 ,
V_180 , V_72 -> V_187 . V_141 ,
V_72 -> V_187 . V_103 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
static int F_97 ( struct V_3 * V_3 )
{
struct V_53 * V_5 = V_3 -> V_5 ;
const struct V_71 * V_72 ;
int V_38 , V_20 ;
V_72 = F_57 ( V_3 -> V_87 ) ;
for ( V_38 = 0 ; V_38 < V_72 -> V_188 . V_184 ; V_38 ++ ) {
struct V_189 * V_190 ;
V_190 = F_98 ( & V_72 -> V_188 . V_191 [ V_38 ] ) ;
if ( F_50 ( V_190 ) ) {
V_20 = F_54 ( V_190 ) ;
F_41 ( V_5 -> V_5 , L_20 ,
V_38 , V_20 ) ;
return V_20 ;
}
V_190 -> V_166 = V_3 -> V_39 ;
V_3 -> V_40 [ V_3 -> V_39 ++ ] = V_190 ;
}
return 0 ;
}
static int F_99 ( struct V_3 * V_3 )
{
struct V_53 * V_5 = V_3 -> V_5 ;
const struct V_71 * V_72 ;
const enum V_74 * V_192 ;
int V_38 ;
V_72 = F_57 ( V_3 -> V_87 ) ;
V_192 = V_72 -> V_66 . V_76 ;
for ( V_38 = 0 ; V_38 < F_33 ( V_72 -> V_66 . V_76 ) ; V_38 ++ ) {
struct V_65 * V_66 ;
if ( V_192 [ V_38 ] == V_193 )
continue;
V_66 = F_100 ( sizeof( * V_66 ) , V_23 ) ;
if ( ! V_66 ) {
F_41 ( V_5 -> V_5 , L_21 , V_38 ) ;
return - V_24 ;
}
V_66 -> V_84 = V_38 ;
V_66 -> type = V_192 [ V_38 ] ;
V_66 -> V_128 = V_194 ;
V_66 -> V_166 = V_3 -> V_97 ;
V_3 -> V_75 [ V_3 -> V_97 ++ ] = V_66 ;
}
return 0 ;
}
static int F_101 ( struct V_116 * V_6 , struct V_53 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
struct V_3 * V_3 ;
struct V_138 * V_139 ;
T_1 V_111 , V_54 ;
int V_20 ;
V_3 = F_102 ( & V_6 -> V_5 , sizeof( * V_3 ) , V_23 ) ;
if ( ! V_3 ) {
V_20 = - V_24 ;
goto V_98;
}
F_103 ( V_6 , V_3 ) ;
F_104 ( & V_3 -> V_8 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_6 = V_6 ;
F_105 ( & V_3 -> V_21 ) ;
V_3 -> V_18 = F_100 ( sizeof( * V_3 -> V_18 ) , V_23 ) ;
if ( ! V_3 -> V_18 ) {
V_20 = - V_24 ;
goto V_98;
}
V_3 -> V_195 = F_106 ( V_6 , L_22 , L_23 ) ;
if ( F_50 ( V_3 -> V_195 ) ) {
V_20 = F_54 ( V_3 -> V_195 ) ;
goto V_98;
}
V_20 = F_66 ( V_6 , & V_3 -> V_62 , L_24 , true ) ;
if ( V_20 )
goto V_98;
V_20 = F_66 ( V_6 , & V_3 -> V_61 , L_25 , true ) ;
if ( V_20 )
goto V_98;
V_20 = F_66 ( V_6 , & V_3 -> V_63 , L_26 , true ) ;
if ( V_20 )
goto V_98;
V_20 = F_66 ( V_6 , & V_3 -> V_196 , L_27 , true ) ;
if ( V_20 )
goto V_98;
F_66 ( V_6 , & V_3 -> V_64 , L_28 , false ) ;
F_107 ( V_3 -> V_63 , 200000000 ) ;
F_108 ( & V_6 -> V_5 ) ;
V_3 -> V_161 = true ;
F_63 ( V_3 , & V_111 , & V_54 ) ;
V_3 -> V_87 = F_109 ( V_3 , V_111 , V_54 ) ;
if ( F_50 ( V_3 -> V_87 ) ) {
V_20 = F_54 ( V_3 -> V_87 ) ;
V_3 -> V_87 = NULL ;
goto V_98;
}
V_139 = F_79 ( V_3 -> V_87 ) ;
V_3 -> V_103 = V_139 -> V_145 -> V_197 . V_103 ;
F_107 ( V_3 -> V_63 , V_139 -> V_145 -> V_198 ) ;
if ( V_3 -> V_103 & V_199 ) {
V_3 -> V_27 = F_110 ( V_3 , & V_139 -> V_145 -> V_27 ) ;
if ( F_50 ( V_3 -> V_27 ) ) {
V_20 = F_54 ( V_3 -> V_27 ) ;
V_3 -> V_27 = NULL ;
goto V_98;
}
}
V_3 -> V_10 = F_111 ( V_5 , V_3 -> V_195 , V_3 -> V_87 ) ;
if ( F_50 ( V_3 -> V_10 ) ) {
V_20 = F_54 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
goto V_98;
}
V_20 = F_96 ( V_3 ) ;
if ( V_20 )
goto V_98;
V_20 = F_97 ( V_3 ) ;
if ( V_20 )
goto V_98;
V_20 = F_99 ( V_3 ) ;
if ( V_20 )
goto V_98;
V_15 -> V_2 = & V_3 -> V_141 . V_141 ;
return 0 ;
V_98:
F_86 ( V_6 ) ;
return V_20 ;
}
static int F_112 ( struct V_4 * V_5 , struct V_4 * V_200 , void * V_201 )
{
struct V_53 * V_202 = F_113 ( V_200 ) ;
struct V_116 * V_6 = F_114 ( V_5 ) ;
F_43 ( L_3 ) ;
return F_101 ( V_6 , V_202 ) ;
}
static void F_115 ( struct V_4 * V_5 , struct V_4 * V_200 ,
void * V_201 )
{
struct V_116 * V_6 = F_114 ( V_5 ) ;
F_86 ( V_6 ) ;
}
static int F_116 ( struct V_116 * V_6 )
{
F_43 ( L_3 ) ;
return F_117 ( & V_6 -> V_5 , & V_203 ) ;
}
static int F_118 ( struct V_116 * V_6 )
{
F_43 ( L_3 ) ;
F_119 ( & V_6 -> V_5 , & V_203 ) ;
return 0 ;
}
static T_4 int F_120 ( struct V_4 * V_5 )
{
struct V_116 * V_6 = F_114 ( V_5 ) ;
struct V_3 * V_3 = F_87 ( V_6 ) ;
F_43 ( L_3 ) ;
return F_42 ( V_3 ) ;
}
static T_4 int F_121 ( struct V_4 * V_5 )
{
struct V_116 * V_6 = F_114 ( V_5 ) ;
struct V_3 * V_3 = F_87 ( V_6 ) ;
F_43 ( L_3 ) ;
return F_46 ( V_3 ) ;
}
void T_5 F_122 ( void )
{
F_43 ( L_3 ) ;
F_123 ( & V_204 ) ;
}
void T_6 F_124 ( void )
{
F_43 ( L_3 ) ;
F_125 ( & V_204 ) ;
}
