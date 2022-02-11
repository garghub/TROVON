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
return F_28 ( V_31 , V_32 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_34 * V_35 = V_3 -> V_35 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_3 -> V_37 ; V_36 ++ )
F_30 ( V_3 -> V_38 [ V_36 ] ) ;
if ( V_35 ) {
V_35 -> V_39 -> V_40 -> V_41 ( V_35 -> V_39 ,
V_42 , F_31 ( V_42 ) ) ;
F_32 ( V_35 ) ;
}
}
static int F_33 ( struct V_43 * V_44 , void * V_45 )
{
struct V_46 * V_47 = (struct V_46 * ) V_44 -> V_48 ;
struct V_49 * V_7 = V_47 -> V_50 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_3 * V_3 = F_2 ( F_3 ( V_15 -> V_2 ) ) ;
struct V_51 V_52 = F_34 ( V_44 ) ;
if ( ! V_3 -> V_26 ) {
F_35 ( & V_52 , L_1 ) ;
return 0 ;
}
F_36 ( V_3 -> V_26 , & V_52 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_53 * V_50 )
{
struct V_49 * V_7 = V_50 -> V_7 ;
int V_20 ;
V_20 = F_38 ( V_54 ,
F_31 ( V_54 ) ,
V_50 -> V_55 , V_50 ) ;
if ( V_20 ) {
F_39 ( V_7 -> V_7 , L_2 ) ;
return V_20 ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_53 * V_50 )
{
F_41 ( V_54 ,
F_31 ( V_54 ) , V_50 ) ;
}
int F_10 ( struct V_3 * V_3 )
{
F_42 ( L_3 ) ;
F_43 ( V_3 -> V_56 ) ;
F_43 ( V_3 -> V_57 ) ;
F_43 ( V_3 -> V_58 ) ;
if ( V_3 -> V_59 )
F_43 ( V_3 -> V_59 ) ;
return 0 ;
}
int F_5 ( struct V_3 * V_3 )
{
F_42 ( L_3 ) ;
F_44 ( V_3 -> V_56 ) ;
F_44 ( V_3 -> V_57 ) ;
F_44 ( V_3 -> V_58 ) ;
if ( V_3 -> V_59 )
F_44 ( V_3 -> V_59 ) ;
return 0 ;
}
static struct V_30 * F_45 ( struct V_3 * V_3 ,
enum V_60 V_61 , int V_62 ,
enum V_63 V_64 , struct V_65 * V_66 )
{
struct V_49 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_30 * V_31 ;
struct V_67 V_68 = {
. V_69 = V_62 ,
. type = V_61 ,
. V_70 = V_64 ,
} ;
if ( ( V_61 == V_71 ) &&
( V_64 == V_72 ) )
V_31 = F_46 ( V_7 , & V_68 , V_66 ) ;
else
V_31 = F_47 ( V_7 , & V_68 , V_66 ) ;
if ( F_48 ( V_31 ) ) {
F_39 ( V_7 -> V_7 , L_4 ) ;
return V_31 ;
}
V_31 -> V_73 = ( 1 << V_15 -> V_74 ) - 1 ;
V_15 -> V_75 [ V_15 -> V_76 ++ ] = V_31 ;
return V_31 ;
}
static int F_49 ( const struct V_77 * V_78 , int V_62 )
{
const enum V_60 * V_79 = V_78 -> V_68 . V_80 ;
const int V_81 = F_31 ( V_78 -> V_68 . V_80 ) ;
int V_82 = 0 , V_36 ;
for ( V_36 = 0 ; V_36 < V_81 ; V_36 ++ ) {
if ( V_79 [ V_36 ] == V_71 ) {
if ( V_62 == V_36 )
return V_82 ;
V_82 ++ ;
}
}
return - V_83 ;
}
static int F_50 ( struct V_3 * V_3 , int V_62 )
{
struct V_49 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_16 ;
const struct V_77 * V_78 =
F_51 ( V_3 -> V_84 ) ;
enum V_60 V_61 = V_78 -> V_68 . V_80 [ V_62 ] ;
struct V_85 * V_10 = V_3 -> V_10 ;
struct V_65 * V_66 ;
struct V_30 * V_31 ;
int V_20 = 0 ;
switch ( V_61 ) {
case V_86 :
break;
case V_87 :
if ( ! V_15 -> V_88 )
break;
V_66 = F_52 ( V_10 , V_62 ) ;
if ( ! V_66 ) {
V_20 = - V_83 ;
break;
}
V_31 = F_45 ( V_3 , V_87 , V_62 ,
V_89 , V_66 ) ;
if ( F_48 ( V_31 ) ) {
V_20 = F_53 ( V_31 ) ;
break;
}
V_20 = F_54 ( V_15 -> V_88 , V_7 , V_31 ) ;
break;
case V_90 :
if ( ! V_15 -> V_91 )
break;
V_66 = F_52 ( V_10 , V_62 ) ;
if ( ! V_66 ) {
V_20 = - V_83 ;
break;
}
V_31 = F_45 ( V_3 , V_90 , V_62 ,
V_89 , V_66 ) ;
if ( F_48 ( V_31 ) ) {
V_20 = F_53 ( V_31 ) ;
break;
}
V_20 = F_55 ( V_15 -> V_91 , V_7 , V_31 ) ;
break;
case V_71 :
{
int V_92 = F_49 ( V_78 , V_62 ) ;
struct V_30 * V_93 [ V_94 ] ;
enum V_63 V_70 ;
int V_36 ;
if ( ( V_92 >= F_31 ( V_15 -> V_95 ) ) || ( V_92 < 0 ) ) {
F_39 ( V_7 -> V_7 , L_5 ,
V_62 ) ;
V_20 = - V_83 ;
break;
}
if ( ! V_15 -> V_95 [ V_92 ] )
break;
V_66 = F_52 ( V_10 , V_62 ) ;
if ( ! V_66 ) {
V_20 = - V_83 ;
break;
}
for ( V_36 = 0 ; V_36 < V_94 ; V_36 ++ ) {
V_70 = ( V_36 == V_96 ) ?
V_72 :
V_97 ;
V_93 [ V_36 ] = F_45 ( V_3 , V_71 ,
V_62 , V_70 , V_66 ) ;
if ( F_48 ( V_93 [ V_36 ] ) ) {
V_20 = F_53 ( V_93 [ V_36 ] ) ;
break;
}
}
V_20 = F_56 ( V_15 -> V_95 [ V_92 ] , V_7 , V_93 ) ;
break;
}
default:
F_39 ( V_7 -> V_7 , L_6 , V_61 ) ;
V_20 = - V_83 ;
break;
}
return V_20 ;
}
static int F_57 ( struct V_3 * V_3 )
{
struct V_49 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_16 ;
const struct V_77 * V_78 ;
int V_36 , V_20 ;
V_78 = F_51 ( V_3 -> V_84 ) ;
for ( V_36 = 0 ; V_36 < V_3 -> V_37 ; V_36 ++ ) {
bool V_98 = V_36 < V_99 -> V_100 . V_101 ;
struct V_102 * V_103 ;
struct V_27 * V_28 ;
V_103 = F_58 ( V_7 , V_98 ) ;
if ( F_48 ( V_103 ) ) {
V_20 = F_53 ( V_103 ) ;
F_39 ( V_7 -> V_7 , L_7 , V_36 , V_20 ) ;
goto V_104;
}
V_15 -> V_105 [ V_15 -> V_106 ++ ] = V_103 ;
if ( ! V_98 )
continue;
V_28 = F_59 ( V_7 , V_103 , V_36 ) ;
if ( F_48 ( V_28 ) ) {
V_20 = F_53 ( V_28 ) ;
F_39 ( V_7 -> V_7 , L_8 , V_36 , V_20 ) ;
goto V_104;
}
V_15 -> V_107 [ V_15 -> V_74 ++ ] = V_28 ;
}
for ( V_36 = 0 ; V_36 < F_31 ( V_78 -> V_68 . V_80 ) ; V_36 ++ ) {
V_20 = F_50 ( V_3 , V_36 ) ;
if ( V_20 )
goto V_104;
}
return 0 ;
V_104:
return V_20 ;
}
static void F_60 ( struct V_3 * V_3 ,
T_1 * V_108 , T_1 * V_50 )
{
T_1 V_109 ;
F_5 ( V_3 ) ;
V_109 = F_61 ( V_3 , V_110 ) ;
F_10 ( V_3 ) ;
* V_108 = F_62 ( V_109 , V_111 ) ;
* V_50 = F_62 ( V_109 , V_112 ) ;
F_42 ( L_9 , * V_108 , * V_50 ) ;
}
static int F_63 ( struct V_4 * V_5 , struct V_113 * * V_114 ,
const char * V_115 , bool V_116 )
{
struct V_117 * V_7 = & V_5 -> V_7 ;
struct V_113 * V_113 = F_64 ( V_7 , V_115 ) ;
if ( F_48 ( V_113 ) && V_116 ) {
F_39 ( V_7 , L_10 , V_115 , F_53 ( V_113 ) ) ;
return F_53 ( V_113 ) ;
}
if ( F_48 ( V_113 ) )
F_42 ( L_11 , V_115 ) ;
else
* V_114 = V_113 ;
return 0 ;
}
static struct V_30 * F_65 ( struct V_27 * V_28 )
{
struct V_49 * V_7 = V_28 -> V_7 ;
struct V_30 * V_31 ;
F_66 (encoder, dev)
if ( V_31 -> V_28 == V_28 )
return V_31 ;
return NULL ;
}
static int F_67 ( struct V_49 * V_7 , unsigned int V_118 ,
unsigned int V_6 , int * V_119 , int * V_120 ,
T_2 * V_121 , T_2 * V_122 ,
const struct V_123 * V_70 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_27 * V_28 ;
struct V_30 * V_31 ;
int line , V_124 , V_125 , V_126 , V_127 , V_128 ;
int V_20 = 0 ;
V_28 = V_15 -> V_107 [ V_118 ] ;
if ( ! V_28 ) {
F_68 ( L_12 , V_118 ) ;
return 0 ;
}
V_31 = F_65 ( V_28 ) ;
if ( ! V_31 ) {
F_68 ( L_13 , V_118 ) ;
return 0 ;
}
V_20 |= V_129 | V_130 ;
V_124 = V_70 -> V_131 - V_70 -> V_132 ;
V_125 = V_70 -> V_133 - V_70 -> V_131 ;
V_126 = V_124 + V_125 + 1 ;
V_127 = V_126 + V_70 -> V_134 ;
V_128 = V_70 -> V_133 ;
if ( V_121 )
* V_121 = F_69 () ;
line = F_70 ( V_31 ) ;
if ( line < V_126 ) {
line -= V_126 ;
V_20 |= V_135 ;
} else if ( line > V_127 ) {
line = line - V_128 - V_126 ;
V_20 |= V_135 ;
} else {
line -= V_126 ;
}
* V_119 = line ;
* V_120 = 0 ;
if ( V_122 )
* V_122 = F_69 () ;
return V_20 ;
}
static int F_71 ( struct V_49 * V_7 , unsigned int V_118 ,
int * V_136 ,
struct V_137 * V_138 ,
unsigned V_6 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_27 * V_28 ;
if ( V_118 < 0 || V_118 >= V_15 -> V_74 ) {
F_68 ( L_12 , V_118 ) ;
return - V_83 ;
}
V_28 = V_15 -> V_107 [ V_118 ] ;
if ( ! V_28 ) {
F_68 ( L_12 , V_118 ) ;
return - V_83 ;
}
return F_72 ( V_7 , V_118 , V_136 ,
V_138 , V_6 ,
& V_28 -> V_70 ) ;
}
static T_1 F_73 ( struct V_49 * V_7 , unsigned int V_118 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_27 * V_28 ;
struct V_30 * V_31 ;
if ( V_118 < 0 || V_118 >= V_15 -> V_74 )
return 0 ;
V_28 = V_15 -> V_107 [ V_118 ] ;
if ( ! V_28 )
return 0 ;
V_31 = F_65 ( V_28 ) ;
if ( ! V_31 )
return 0 ;
return F_74 ( V_31 ) ;
}
struct V_1 * F_75 ( struct V_49 * V_7 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_4 * V_5 ;
struct V_3 * V_3 ;
struct V_99 * V_139 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_140 , V_36 , V_20 ;
V_2 = V_15 -> V_2 ;
if ( ! V_2 )
return NULL ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_76 ( & V_3 -> V_141 , & V_142 ) ;
V_5 = V_3 -> V_5 ;
V_140 = F_77 ( V_5 -> V_7 . V_143 , 0 ) ;
if ( V_140 < 0 ) {
V_20 = V_140 ;
F_39 ( & V_5 -> V_7 , L_14 , V_20 ) ;
goto V_104;
}
V_2 -> V_140 = V_140 ;
V_139 = F_78 ( V_3 -> V_84 ) ;
F_5 ( V_3 ) ;
for ( V_36 = 0 ; V_36 < V_144 ; V_36 ++ ) {
if ( F_79 ( V_139 -> V_145 -> V_68 . V_80 [ V_36 ] ) ||
! V_139 -> V_145 -> V_68 . V_141 [ V_36 ] )
continue;
F_7 ( V_3 , F_80 ( V_36 ) , 0 ) ;
F_7 ( V_3 , F_81 ( V_36 ) , 0x3 ) ;
}
F_10 ( V_3 ) ;
F_82 ( 16 ) ;
if ( V_139 -> V_146 . V_147 ) {
V_35 = F_83 ( & V_5 -> V_7 ,
V_139 -> V_146 . V_147 , L_15 ) ;
if ( F_48 ( V_35 ) ) {
V_20 = F_53 ( V_35 ) ;
goto V_104;
}
V_3 -> V_35 = V_35 ;
V_20 = V_35 -> V_39 -> V_40 -> V_148 ( V_35 -> V_39 , V_42 ,
F_31 ( V_42 ) ) ;
if ( V_20 ) {
F_39 ( & V_5 -> V_7 , L_16 ,
V_20 ) ;
goto V_104;
}
} else {
F_84 ( & V_5 -> V_7 ,
L_17 ) ;
V_35 = NULL ; ;
}
V_3 -> V_82 = F_85 ( V_7 , V_35 ) ;
if ( V_3 -> V_82 < 0 ) {
V_20 = V_3 -> V_82 ;
F_39 ( & V_5 -> V_7 , L_18 , V_20 ) ;
goto V_104;
}
V_20 = F_57 ( V_3 ) ;
if ( V_20 ) {
F_39 ( & V_5 -> V_7 , L_19 , V_20 ) ;
goto V_104;
}
V_7 -> V_149 . V_150 = 0 ;
V_7 -> V_149 . V_151 = 0 ;
V_7 -> V_149 . V_152 = 0xffff ;
V_7 -> V_149 . V_153 = 0xffff ;
V_7 -> V_154 -> V_155 = F_71 ;
V_7 -> V_154 -> V_156 = F_67 ;
V_7 -> V_154 -> V_157 = F_73 ;
V_7 -> V_158 = 0xffffffff ;
V_7 -> V_159 = true ;
return V_2 ;
V_104:
if ( V_2 )
F_29 ( V_2 ) ;
return F_15 ( V_20 ) ;
}
static void F_86 ( struct V_4 * V_5 )
{
struct V_3 * V_3 = F_87 ( V_5 ) ;
if ( V_3 -> V_10 )
F_88 ( V_3 -> V_10 ) ;
if ( V_3 -> V_26 )
F_89 ( V_3 -> V_26 ) ;
if ( V_3 -> V_84 )
F_90 ( V_3 -> V_84 ) ;
if ( V_3 -> V_160 )
F_91 ( & V_5 -> V_7 ) ;
F_92 ( V_3 -> V_18 ) ;
}
static int F_93 ( struct V_3 * V_3 , int V_161 ,
const enum V_162 * V_163 , const T_3 * V_164 ,
T_3 V_165 )
{
struct V_49 * V_7 = V_3 -> V_7 ;
int V_36 , V_20 ;
for ( V_36 = 0 ; V_36 < V_161 ; V_36 ++ ) {
struct V_166 * V_25 ;
V_25 = F_94 ( V_163 [ V_36 ] , V_164 [ V_36 ] , V_165 ) ;
if ( F_48 ( V_25 ) ) {
V_20 = F_53 ( V_25 ) ;
F_39 ( V_7 -> V_7 , L_20 ,
F_95 ( V_163 [ V_36 ] ) , V_20 ) ;
return V_20 ;
}
V_25 -> V_167 = V_3 -> V_37 ;
V_3 -> V_38 [ V_3 -> V_37 ++ ] = V_25 ;
}
return 0 ;
}
static int F_96 ( struct V_3 * V_3 )
{
static const enum V_162 V_168 [] = {
V_169 , V_170 , V_171 , V_172 ,
} ;
static const enum V_162 V_173 [] = {
V_174 , V_175 , V_176 , V_177 ,
} ;
static const enum V_162 V_178 [] = {
V_179 , V_180 ,
} ;
const struct V_77 * V_78 ;
int V_20 ;
V_78 = F_51 ( V_3 -> V_84 ) ;
V_20 = F_93 ( V_3 , V_78 -> V_181 . V_101 , V_168 ,
V_78 -> V_181 . V_141 , V_78 -> V_181 . V_165 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_93 ( V_3 , V_78 -> V_182 . V_101 , V_173 ,
V_78 -> V_182 . V_141 , V_78 -> V_182 . V_165 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_93 ( V_3 , V_78 -> V_183 . V_101 , V_178 ,
V_78 -> V_183 . V_141 , V_78 -> V_183 . V_165 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
static int F_97 ( struct V_4 * V_5 , struct V_49 * V_7 )
{
struct V_14 * V_15 = V_7 -> V_16 ;
struct V_3 * V_3 ;
struct V_99 * V_139 ;
T_1 V_108 , V_50 ;
int V_20 ;
V_3 = F_98 ( & V_5 -> V_7 , sizeof( * V_3 ) , V_23 ) ;
if ( ! V_3 ) {
V_20 = - V_24 ;
goto V_104;
}
F_99 ( V_5 , V_3 ) ;
F_100 ( & V_3 -> V_8 ) ;
V_3 -> V_7 = V_7 ;
V_3 -> V_5 = V_5 ;
F_101 ( & V_3 -> V_21 ) ;
V_3 -> V_18 = F_102 ( sizeof( * V_3 -> V_18 ) , V_23 ) ;
if ( ! V_3 -> V_18 ) {
V_20 = - V_24 ;
goto V_104;
}
V_3 -> V_184 = F_103 ( V_5 , L_21 , L_22 ) ;
if ( F_48 ( V_3 -> V_184 ) ) {
V_20 = F_53 ( V_3 -> V_184 ) ;
goto V_104;
}
V_20 = F_63 ( V_5 , & V_3 -> V_57 , L_23 , true ) ;
if ( V_20 )
goto V_104;
V_20 = F_63 ( V_5 , & V_3 -> V_56 , L_24 , true ) ;
if ( V_20 )
goto V_104;
V_20 = F_63 ( V_5 , & V_3 -> V_58 , L_25 , true ) ;
if ( V_20 )
goto V_104;
V_20 = F_63 ( V_5 , & V_3 -> V_185 , L_26 , true ) ;
if ( V_20 )
goto V_104;
F_63 ( V_5 , & V_3 -> V_59 , L_27 , false ) ;
F_104 ( V_3 -> V_58 , 200000000 ) ;
F_105 ( & V_5 -> V_7 ) ;
V_3 -> V_160 = true ;
F_60 ( V_3 , & V_108 , & V_50 ) ;
V_3 -> V_84 = F_106 ( V_3 , V_108 , V_50 ) ;
if ( F_48 ( V_3 -> V_84 ) ) {
V_20 = F_53 ( V_3 -> V_84 ) ;
V_3 -> V_84 = NULL ;
goto V_104;
}
V_139 = F_78 ( V_3 -> V_84 ) ;
V_3 -> V_165 = V_139 -> V_145 -> V_186 . V_165 ;
F_104 ( V_3 -> V_58 , V_139 -> V_145 -> V_187 ) ;
if ( V_3 -> V_165 & V_188 ) {
V_3 -> V_26 = F_107 ( V_3 , & V_139 -> V_145 -> V_26 ) ;
if ( F_48 ( V_3 -> V_26 ) ) {
V_20 = F_53 ( V_3 -> V_26 ) ;
V_3 -> V_26 = NULL ;
goto V_104;
}
}
V_3 -> V_10 = F_108 ( V_7 , V_3 -> V_184 , V_3 -> V_84 ) ;
if ( F_48 ( V_3 -> V_10 ) ) {
V_20 = F_53 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
goto V_104;
}
V_20 = F_96 ( V_3 ) ;
if ( V_20 )
goto V_104;
V_15 -> V_2 = & V_3 -> V_141 . V_141 ;
return 0 ;
V_104:
F_86 ( V_5 ) ;
return V_20 ;
}
static int F_109 ( struct V_117 * V_7 , struct V_117 * V_189 , void * V_190 )
{
struct V_49 * V_191 = F_110 ( V_189 ) ;
struct V_4 * V_5 = F_111 ( V_7 ) ;
F_42 ( L_3 ) ;
return F_97 ( V_5 , V_191 ) ;
}
static void F_112 ( struct V_117 * V_7 , struct V_117 * V_189 ,
void * V_190 )
{
struct V_4 * V_5 = F_111 ( V_7 ) ;
F_86 ( V_5 ) ;
}
static int F_113 ( struct V_4 * V_5 )
{
F_42 ( L_3 ) ;
return F_114 ( & V_5 -> V_7 , & V_192 ) ;
}
static int F_115 ( struct V_4 * V_5 )
{
F_42 ( L_3 ) ;
F_116 ( & V_5 -> V_7 , & V_192 ) ;
return 0 ;
}
void T_4 F_117 ( void )
{
F_42 ( L_3 ) ;
F_118 ( & V_193 ) ;
}
void T_5 F_119 ( void )
{
F_42 ( L_3 ) ;
F_120 ( & V_193 ) ;
}
