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
if ( V_3 -> V_26 )
V_19 -> V_26 = V_3 -> V_18 -> V_26 ;
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
if ( V_3 -> V_26 )
F_20 ( V_3 -> V_26 , & V_3 -> V_18 -> V_26 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_12 * V_18 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_3 -> V_26 )
F_22 ( V_3 -> V_26 , & V_3 -> V_18 -> V_26 ) ;
F_10 ( V_3 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_24 ( V_28 ) ;
}
static long F_25 ( struct V_1 * V_2 , unsigned long V_29 ,
struct V_30 * V_31 )
{
return V_29 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_30 * V_32 ,
bool V_33 )
{
if ( V_33 )
return F_27 ( V_31 ,
V_32 ) ;
else
return F_28 ( V_31 ,
V_32 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
bool V_34 )
{
F_30 ( V_31 , V_34 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_35 * V_36 = V_3 -> V_36 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_3 -> V_38 ; V_37 ++ )
F_32 ( V_3 -> V_39 [ V_37 ] ) ;
if ( V_36 ) {
V_36 -> V_40 -> V_41 -> V_42 ( V_36 -> V_40 ,
V_43 , F_33 ( V_43 ) ) ;
F_34 ( V_36 ) ;
}
}
static int F_35 ( struct V_44 * V_45 , void * V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_45 -> V_49 ;
struct V_50 * V_7 = V_48 -> V_51 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_3 * V_3 = F_2 ( F_3 ( V_15 -> V_2 ) ) ;
struct V_52 V_53 = F_36 ( V_45 ) ;
if ( ! V_3 -> V_26 ) {
F_37 ( & V_53 , L_1 ) ;
return 0 ;
}
F_38 ( V_3 -> V_26 , & V_53 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_54 * V_51 )
{
struct V_50 * V_7 = V_51 -> V_7 ;
int V_20 ;
V_20 = F_40 ( V_55 ,
F_33 ( V_55 ) ,
V_51 -> V_56 , V_51 ) ;
if ( V_20 ) {
F_41 ( V_7 -> V_7 , L_2 ) ;
return V_20 ;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_54 * V_51 )
{
F_43 ( V_55 ,
F_33 ( V_55 ) , V_51 ) ;
}
int F_10 ( struct V_3 * V_3 )
{
F_44 ( L_3 ) ;
F_45 ( V_3 -> V_57 ) ;
F_45 ( V_3 -> V_58 ) ;
F_45 ( V_3 -> V_59 ) ;
if ( V_3 -> V_60 )
F_45 ( V_3 -> V_60 ) ;
return 0 ;
}
int F_5 ( struct V_3 * V_3 )
{
F_44 ( L_3 ) ;
F_46 ( V_3 -> V_57 ) ;
F_46 ( V_3 -> V_58 ) ;
F_46 ( V_3 -> V_59 ) ;
if ( V_3 -> V_60 )
F_46 ( V_3 -> V_60 ) ;
return 0 ;
}
static struct V_30 * F_47 ( struct V_3 * V_3 ,
enum V_61 V_62 , int V_63 ,
struct V_64 * V_65 )
{
struct V_50 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_30 * V_31 ;
struct V_66 V_67 = {
. V_68 = V_63 ,
. type = V_62 ,
. V_69 = V_70 ,
} ;
V_31 = F_48 ( V_7 , & V_67 , V_65 ) ;
if ( F_49 ( V_31 ) ) {
F_41 ( V_7 -> V_7 , L_4 ) ;
return V_31 ;
}
V_15 -> V_71 [ V_15 -> V_72 ++ ] = V_31 ;
return V_31 ;
}
static int F_50 ( const struct V_73 * V_74 , int V_63 )
{
const enum V_61 * V_75 = V_74 -> V_67 . V_76 ;
const int V_77 = F_33 ( V_74 -> V_67 . V_76 ) ;
int V_78 = 0 , V_37 ;
for ( V_37 = 0 ; V_37 < V_77 ; V_37 ++ ) {
if ( V_75 [ V_37 ] == V_79 ) {
if ( V_63 == V_37 )
return V_78 ;
V_78 ++ ;
}
}
return - V_80 ;
}
static int F_51 ( struct V_3 * V_3 , int V_63 )
{
struct V_50 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_16 ;
const struct V_73 * V_74 =
F_52 ( V_3 -> V_81 ) ;
enum V_61 V_62 = V_74 -> V_67 . V_76 [ V_63 ] ;
struct V_82 * V_10 = V_3 -> V_10 ;
struct V_64 * V_65 ;
struct V_30 * V_31 ;
int V_20 = 0 ;
switch ( V_62 ) {
case V_83 :
break;
case V_84 :
if ( ! V_15 -> V_85 )
break;
V_65 = F_53 ( V_10 , V_63 ) ;
if ( ! V_65 ) {
V_20 = - V_80 ;
break;
}
V_31 = F_47 ( V_3 , V_84 , V_63 , V_65 ) ;
if ( F_49 ( V_31 ) ) {
V_20 = F_54 ( V_31 ) ;
break;
}
V_20 = F_55 ( V_15 -> V_85 , V_7 , V_31 ) ;
break;
case V_86 :
if ( ! V_15 -> V_87 )
break;
V_65 = F_53 ( V_10 , V_63 ) ;
if ( ! V_65 ) {
V_20 = - V_80 ;
break;
}
V_31 = F_47 ( V_3 , V_86 , V_63 , V_65 ) ;
if ( F_49 ( V_31 ) ) {
V_20 = F_54 ( V_31 ) ;
break;
}
V_20 = F_56 ( V_15 -> V_87 , V_7 , V_31 ) ;
break;
case V_79 :
{
int V_88 = F_50 ( V_74 , V_63 ) ;
if ( ( V_88 >= F_33 ( V_15 -> V_89 ) ) || ( V_88 < 0 ) ) {
F_41 ( V_7 -> V_7 , L_5 ,
V_63 ) ;
V_20 = - V_80 ;
break;
}
if ( ! V_15 -> V_89 [ V_88 ] )
break;
V_65 = F_53 ( V_10 , V_63 ) ;
if ( ! V_65 ) {
V_20 = - V_80 ;
break;
}
V_31 = F_47 ( V_3 , V_79 , V_63 , V_65 ) ;
if ( F_49 ( V_31 ) ) {
V_20 = F_54 ( V_31 ) ;
break;
}
V_20 = F_57 ( V_15 -> V_89 [ V_88 ] , V_7 , V_31 ) ;
break;
}
default:
F_41 ( V_7 -> V_7 , L_6 , V_62 ) ;
V_20 = - V_80 ;
break;
}
return V_20 ;
}
static int F_58 ( struct V_3 * V_3 )
{
struct V_50 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_16 ;
const struct V_73 * V_74 ;
unsigned int V_90 ;
int V_37 , V_20 , V_91 = 0 , V_92 = 0 ;
struct V_93 * V_94 [ V_95 ] = { NULL } ;
struct V_93 * V_96 [ V_95 ] = { NULL } ;
V_74 = F_52 ( V_3 -> V_81 ) ;
for ( V_37 = 0 ; V_37 < F_33 ( V_74 -> V_67 . V_76 ) ; V_37 ++ ) {
V_20 = F_51 ( V_3 , V_37 ) ;
if ( V_20 )
goto V_97;
}
V_90 = F_59 ( V_15 -> V_72 , V_98 -> V_99 . V_100 ) ;
for ( V_37 = 0 ; V_37 < V_3 -> V_38 ; V_37 ++ ) {
struct V_101 * V_25 = V_3 -> V_39 [ V_37 ] ;
struct V_93 * V_102 ;
enum V_103 type ;
if ( V_37 < V_90 )
type = V_104 ;
else if ( V_25 -> V_105 & V_106 )
type = V_107 ;
else
type = V_108 ;
V_102 = F_60 ( V_7 , type ) ;
if ( F_49 ( V_102 ) ) {
V_20 = F_54 ( V_102 ) ;
F_41 ( V_7 -> V_7 , L_7 , V_37 , V_20 ) ;
goto V_97;
}
V_15 -> V_109 [ V_15 -> V_110 ++ ] = V_102 ;
if ( type == V_104 )
V_94 [ V_91 ++ ] = V_102 ;
if ( type == V_107 )
V_96 [ V_92 ++ ] = V_102 ;
}
for ( V_37 = 0 ; V_37 < V_90 ; V_37 ++ ) {
struct V_27 * V_28 ;
V_28 = F_61 ( V_7 , V_94 [ V_37 ] , V_96 [ V_37 ] , V_37 ) ;
if ( F_49 ( V_28 ) ) {
V_20 = F_54 ( V_28 ) ;
F_41 ( V_7 -> V_7 , L_8 , V_37 , V_20 ) ;
goto V_97;
}
V_15 -> V_111 [ V_15 -> V_90 ++ ] = V_28 ;
}
for ( V_37 = 0 ; V_37 < V_15 -> V_72 ; V_37 ++ ) {
struct V_30 * V_31 = V_15 -> V_71 [ V_37 ] ;
V_31 -> V_112 = ( 1 << V_15 -> V_90 ) - 1 ;
}
return 0 ;
V_97:
return V_20 ;
}
static void F_62 ( struct V_3 * V_3 ,
T_1 * V_113 , T_1 * V_51 )
{
T_1 V_114 ;
F_5 ( V_3 ) ;
V_114 = F_63 ( V_3 , V_115 ) ;
F_10 ( V_3 ) ;
* V_113 = F_64 ( V_114 , V_116 ) ;
* V_51 = F_64 ( V_114 , V_117 ) ;
F_44 ( L_9 , * V_113 , * V_51 ) ;
}
static int F_65 ( struct V_4 * V_5 , struct V_118 * * V_119 ,
const char * V_120 , bool V_121 )
{
struct V_122 * V_7 = & V_5 -> V_7 ;
struct V_118 * V_118 = F_66 ( V_7 , V_120 ) ;
if ( F_49 ( V_118 ) && V_121 ) {
F_41 ( V_7 , L_10 , V_120 , F_54 ( V_118 ) ) ;
return F_54 ( V_118 ) ;
}
if ( F_49 ( V_118 ) )
F_44 ( L_11 , V_120 ) ;
else
* V_119 = V_118 ;
return 0 ;
}
static struct V_30 * F_67 ( struct V_27 * V_28 )
{
struct V_50 * V_7 = V_28 -> V_7 ;
struct V_30 * V_31 ;
F_68 (encoder, dev)
if ( V_31 -> V_28 == V_28 )
return V_31 ;
return NULL ;
}
static int F_69 ( struct V_50 * V_7 , unsigned int V_123 ,
unsigned int V_6 , int * V_124 , int * V_125 ,
T_2 * V_126 , T_2 * V_127 ,
const struct V_128 * V_69 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_27 * V_28 ;
struct V_30 * V_31 ;
int line , V_129 , V_130 , V_131 , V_132 , V_133 ;
int V_20 = 0 ;
V_28 = V_15 -> V_111 [ V_123 ] ;
if ( ! V_28 ) {
F_70 ( L_12 , V_123 ) ;
return 0 ;
}
V_31 = F_67 ( V_28 ) ;
if ( ! V_31 ) {
F_70 ( L_13 , V_123 ) ;
return 0 ;
}
V_20 |= V_134 | V_135 ;
V_129 = V_69 -> V_136 - V_69 -> V_137 ;
V_130 = V_69 -> V_138 - V_69 -> V_136 ;
V_131 = V_129 + V_130 + 1 ;
V_132 = V_131 + V_69 -> V_139 ;
V_133 = V_69 -> V_138 ;
if ( V_126 )
* V_126 = F_71 () ;
line = F_72 ( V_31 ) ;
if ( line < V_131 ) {
line -= V_131 ;
V_20 |= V_140 ;
} else if ( line > V_132 ) {
line = line - V_133 - V_131 ;
V_20 |= V_140 ;
} else {
line -= V_131 ;
}
* V_124 = line ;
* V_125 = 0 ;
if ( V_127 )
* V_127 = F_71 () ;
return V_20 ;
}
static int F_73 ( struct V_50 * V_7 , unsigned int V_123 ,
int * V_141 ,
struct V_142 * V_143 ,
unsigned V_6 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_27 * V_28 ;
if ( V_123 < 0 || V_123 >= V_15 -> V_90 ) {
F_70 ( L_12 , V_123 ) ;
return - V_80 ;
}
V_28 = V_15 -> V_111 [ V_123 ] ;
if ( ! V_28 ) {
F_70 ( L_12 , V_123 ) ;
return - V_80 ;
}
return F_74 ( V_7 , V_123 , V_141 ,
V_143 , V_6 ,
& V_28 -> V_69 ) ;
}
static T_1 F_75 ( struct V_50 * V_7 , unsigned int V_123 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_27 * V_28 ;
struct V_30 * V_31 ;
if ( V_123 < 0 || V_123 >= V_15 -> V_90 )
return 0 ;
V_28 = V_15 -> V_111 [ V_123 ] ;
if ( ! V_28 )
return 0 ;
V_31 = F_67 ( V_28 ) ;
if ( ! V_31 )
return 0 ;
return F_76 ( V_31 ) ;
}
struct V_1 * F_77 ( struct V_50 * V_7 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_4 * V_5 ;
struct V_3 * V_3 ;
struct V_98 * V_144 ;
struct V_1 * V_2 ;
struct V_35 * V_36 ;
int V_145 , V_37 , V_20 ;
V_2 = V_15 -> V_2 ;
if ( ! V_2 )
return NULL ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_78 ( & V_3 -> V_146 , & V_147 ) ;
V_5 = V_3 -> V_5 ;
V_145 = F_79 ( V_5 -> V_7 . V_148 , 0 ) ;
if ( V_145 < 0 ) {
V_20 = V_145 ;
F_41 ( & V_5 -> V_7 , L_14 , V_20 ) ;
goto V_97;
}
V_2 -> V_145 = V_145 ;
V_144 = F_80 ( V_3 -> V_81 ) ;
F_5 ( V_3 ) ;
for ( V_37 = 0 ; V_37 < V_149 ; V_37 ++ ) {
if ( F_81 ( V_144 -> V_150 -> V_67 . V_76 [ V_37 ] ) ||
! V_144 -> V_150 -> V_67 . V_146 [ V_37 ] )
continue;
F_7 ( V_3 , F_82 ( V_37 ) , 0 ) ;
F_7 ( V_3 , F_83 ( V_37 ) , 0x3 ) ;
}
F_10 ( V_3 ) ;
F_84 ( 16 ) ;
if ( V_144 -> V_151 . V_152 ) {
V_36 = F_85 ( & V_5 -> V_7 ,
V_144 -> V_151 . V_152 , L_15 ) ;
if ( F_49 ( V_36 ) ) {
V_20 = F_54 ( V_36 ) ;
goto V_97;
}
V_3 -> V_36 = V_36 ;
V_20 = V_36 -> V_40 -> V_41 -> V_153 ( V_36 -> V_40 , V_43 ,
F_33 ( V_43 ) ) ;
if ( V_20 ) {
F_41 ( & V_5 -> V_7 , L_16 ,
V_20 ) ;
goto V_97;
}
} else {
F_86 ( & V_5 -> V_7 ,
L_17 ) ;
V_36 = NULL ; ;
}
V_3 -> V_78 = F_87 ( V_7 , V_36 ) ;
if ( V_3 -> V_78 < 0 ) {
V_20 = V_3 -> V_78 ;
F_41 ( & V_5 -> V_7 , L_18 , V_20 ) ;
goto V_97;
}
V_20 = F_58 ( V_3 ) ;
if ( V_20 ) {
F_41 ( & V_5 -> V_7 , L_19 , V_20 ) ;
goto V_97;
}
V_7 -> V_154 . V_155 = 0 ;
V_7 -> V_154 . V_156 = 0 ;
V_7 -> V_154 . V_157 = 0xffff ;
V_7 -> V_154 . V_158 = 0xffff ;
V_7 -> V_159 -> V_160 = F_73 ;
V_7 -> V_159 -> V_161 = F_69 ;
V_7 -> V_159 -> V_162 = F_75 ;
V_7 -> V_163 = 0xffffffff ;
V_7 -> V_164 = true ;
return V_2 ;
V_97:
if ( V_2 )
F_31 ( V_2 ) ;
return F_15 ( V_20 ) ;
}
static void F_88 ( struct V_4 * V_5 )
{
struct V_3 * V_3 = F_89 ( V_5 ) ;
if ( V_3 -> V_10 )
F_90 ( V_3 -> V_10 ) ;
if ( V_3 -> V_26 )
F_91 ( V_3 -> V_26 ) ;
if ( V_3 -> V_81 )
F_92 ( V_3 -> V_81 ) ;
if ( V_3 -> V_165 )
F_93 ( & V_5 -> V_7 ) ;
F_94 ( V_3 -> V_18 ) ;
}
static int F_95 ( struct V_3 * V_3 , int V_166 ,
const enum V_167 * V_168 , const T_3 * V_169 ,
T_3 V_105 )
{
struct V_50 * V_7 = V_3 -> V_7 ;
int V_37 , V_20 ;
for ( V_37 = 0 ; V_37 < V_166 ; V_37 ++ ) {
struct V_101 * V_25 ;
V_25 = F_96 ( V_168 [ V_37 ] , V_169 [ V_37 ] , V_105 ) ;
if ( F_49 ( V_25 ) ) {
V_20 = F_54 ( V_25 ) ;
F_41 ( V_7 -> V_7 , L_20 ,
F_97 ( V_168 [ V_37 ] ) , V_20 ) ;
return V_20 ;
}
V_25 -> V_170 = V_3 -> V_38 ;
V_3 -> V_39 [ V_3 -> V_38 ++ ] = V_25 ;
}
return 0 ;
}
static int F_98 ( struct V_3 * V_3 )
{
static const enum V_167 V_171 [] = {
V_172 , V_173 , V_174 , V_175 ,
} ;
static const enum V_167 V_176 [] = {
V_177 , V_178 , V_179 , V_180 ,
} ;
static const enum V_167 V_181 [] = {
V_182 , V_183 ,
} ;
static const enum V_167 V_184 [] = {
V_185 , V_186 ,
} ;
const struct V_73 * V_74 ;
int V_20 ;
V_74 = F_52 ( V_3 -> V_81 ) ;
V_20 = F_95 ( V_3 , V_74 -> V_187 . V_100 , V_171 ,
V_74 -> V_187 . V_146 , V_74 -> V_187 . V_105 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_95 ( V_3 , V_74 -> V_188 . V_100 , V_176 ,
V_74 -> V_188 . V_146 , V_74 -> V_188 . V_105 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_95 ( V_3 , V_74 -> V_189 . V_100 , V_181 ,
V_74 -> V_189 . V_146 , V_74 -> V_189 . V_105 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_95 ( V_3 , V_74 -> V_190 . V_100 ,
V_184 , V_74 -> V_190 . V_146 ,
V_74 -> V_190 . V_105 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
static int F_99 ( struct V_4 * V_5 , struct V_50 * V_7 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_3 * V_3 ;
struct V_98 * V_144 ;
T_1 V_113 , V_51 ;
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
V_3 -> V_18 = F_104 ( sizeof( * V_3 -> V_18 ) , V_23 ) ;
if ( ! V_3 -> V_18 ) {
V_20 = - V_24 ;
goto V_97;
}
V_3 -> V_191 = F_105 ( V_5 , L_21 , L_22 ) ;
if ( F_49 ( V_3 -> V_191 ) ) {
V_20 = F_54 ( V_3 -> V_191 ) ;
goto V_97;
}
V_20 = F_65 ( V_5 , & V_3 -> V_58 , L_23 , true ) ;
if ( V_20 )
goto V_97;
V_20 = F_65 ( V_5 , & V_3 -> V_57 , L_24 , true ) ;
if ( V_20 )
goto V_97;
V_20 = F_65 ( V_5 , & V_3 -> V_59 , L_25 , true ) ;
if ( V_20 )
goto V_97;
V_20 = F_65 ( V_5 , & V_3 -> V_192 , L_26 , true ) ;
if ( V_20 )
goto V_97;
F_65 ( V_5 , & V_3 -> V_60 , L_27 , false ) ;
F_106 ( V_3 -> V_59 , 200000000 ) ;
F_107 ( & V_5 -> V_7 ) ;
V_3 -> V_165 = true ;
F_62 ( V_3 , & V_113 , & V_51 ) ;
V_3 -> V_81 = F_108 ( V_3 , V_113 , V_51 ) ;
if ( F_49 ( V_3 -> V_81 ) ) {
V_20 = F_54 ( V_3 -> V_81 ) ;
V_3 -> V_81 = NULL ;
goto V_97;
}
V_144 = F_80 ( V_3 -> V_81 ) ;
V_3 -> V_105 = V_144 -> V_150 -> V_193 . V_105 ;
F_106 ( V_3 -> V_59 , V_144 -> V_150 -> V_194 ) ;
if ( V_3 -> V_105 & V_195 ) {
V_3 -> V_26 = F_109 ( V_3 , & V_144 -> V_150 -> V_26 ) ;
if ( F_49 ( V_3 -> V_26 ) ) {
V_20 = F_54 ( V_3 -> V_26 ) ;
V_3 -> V_26 = NULL ;
goto V_97;
}
}
V_3 -> V_10 = F_110 ( V_7 , V_3 -> V_191 , V_3 -> V_81 ) ;
if ( F_49 ( V_3 -> V_10 ) ) {
V_20 = F_54 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
goto V_97;
}
V_20 = F_98 ( V_3 ) ;
if ( V_20 )
goto V_97;
V_15 -> V_2 = & V_3 -> V_146 . V_146 ;
return 0 ;
V_97:
F_88 ( V_5 ) ;
return V_20 ;
}
static int F_111 ( struct V_122 * V_7 , struct V_122 * V_196 , void * V_197 )
{
struct V_50 * V_198 = F_112 ( V_196 ) ;
struct V_4 * V_5 = F_113 ( V_7 ) ;
F_44 ( L_3 ) ;
return F_99 ( V_5 , V_198 ) ;
}
static void F_114 ( struct V_122 * V_7 , struct V_122 * V_196 ,
void * V_197 )
{
struct V_4 * V_5 = F_113 ( V_7 ) ;
F_88 ( V_5 ) ;
}
static int F_115 ( struct V_4 * V_5 )
{
F_44 ( L_3 ) ;
return F_116 ( & V_5 -> V_7 , & V_199 ) ;
}
static int F_117 ( struct V_4 * V_5 )
{
F_44 ( L_3 ) ;
F_118 ( & V_5 -> V_7 , & V_199 ) ;
return 0 ;
}
void T_4 F_119 ( void )
{
F_44 ( L_3 ) ;
F_120 ( & V_200 ) ;
}
void T_5 F_121 ( void )
{
F_44 ( L_3 ) ;
F_122 ( & V_200 ) ;
}
