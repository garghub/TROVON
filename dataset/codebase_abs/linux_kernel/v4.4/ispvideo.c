const struct V_1 * F_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
static unsigned int F_3 ( const struct V_5 * V_6 ,
const struct V_7 * V_8 ,
struct V_9 * V_10 )
{
unsigned int V_11 = V_10 -> V_12 ;
unsigned int V_13 ;
unsigned int V_3 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_14 = V_8 -> V_14 ;
V_10 -> V_15 = V_8 -> V_15 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_2 == V_8 -> V_2 )
break;
}
if ( F_4 ( V_3 == F_2 ( V_4 ) ) )
return 0 ;
V_13 = V_10 -> V_14 * V_4 [ V_3 ] . V_16 ;
if ( V_6 -> V_17 )
V_11 = F_5 ( V_11 , V_13 , V_6 -> V_17 ) ;
else
V_11 = V_13 ;
if ( ! V_6 -> V_18 || V_11 != V_13 )
V_11 = F_6 ( V_11 , V_6 -> V_19 ) ;
V_10 -> V_20 = V_4 [ V_3 ] . V_20 ;
V_10 -> V_12 = V_11 ;
V_10 -> V_21 = V_10 -> V_12 * V_10 -> V_15 ;
V_10 -> V_22 = V_8 -> V_22 ;
V_10 -> V_23 = V_8 -> V_23 ;
return V_11 - V_13 ;
}
static void F_7 ( const struct V_9 * V_10 ,
struct V_7 * V_8 )
{
unsigned int V_3 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_14 = V_10 -> V_14 ;
V_8 -> V_15 = V_10 -> V_15 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) - 1 ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_20 == V_10 -> V_20 )
break;
}
V_8 -> V_2 = V_4 [ V_3 ] . V_2 ;
V_8 -> V_22 = V_10 -> V_22 ;
V_8 -> V_23 = V_10 -> V_23 ;
}
static struct V_24 *
F_8 ( struct V_5 * V_6 , T_1 * V_25 )
{
struct V_26 * V_27 ;
V_27 = F_9 ( & V_6 -> V_25 ) ;
if ( V_27 == NULL ||
F_10 ( V_27 -> V_28 ) != V_29 )
return NULL ;
if ( V_25 )
* V_25 = V_27 -> V_30 ;
return F_11 ( V_27 -> V_28 ) ;
}
static int F_12 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
struct V_33 V_34 ;
struct V_35 * V_28 = & V_6 -> V_6 . V_28 ;
struct V_36 * V_37 = V_28 -> V_38 ;
struct V_5 * V_39 = NULL ;
F_13 ( & V_37 -> V_40 ) ;
F_14 ( & V_34 , V_28 ) ;
while ( ( V_28 = F_15 ( & V_34 ) ) ) {
struct V_5 * V_41 ;
V_32 -> V_42 |= 1 << V_28 -> V_43 ;
if ( V_39 != NULL )
continue;
if ( V_28 == & V_6 -> V_6 . V_28 )
continue;
if ( F_10 ( V_28 ) != V_44 )
continue;
V_41 = F_16 ( F_17 ( V_28 ) ) ;
if ( V_41 -> type != V_6 -> type )
V_39 = V_41 ;
}
F_18 ( & V_37 -> V_40 ) ;
if ( V_6 -> type == V_45 ) {
V_32 -> V_46 = V_39 ;
V_32 -> V_47 = V_6 ;
} else {
if ( V_39 == NULL )
return - V_48 ;
V_32 -> V_46 = V_6 ;
V_32 -> V_47 = V_39 ;
}
return 0 ;
}
static int
F_19 ( struct V_5 * V_6 , struct V_49 * V_50 )
{
struct V_51 V_52 ;
struct V_24 * V_53 ;
T_1 V_25 ;
int V_54 ;
V_53 = F_8 ( V_6 , & V_25 ) ;
if ( V_53 == NULL )
return - V_55 ;
V_52 . V_25 = V_25 ;
V_52 . V_56 = V_57 ;
F_13 ( & V_6 -> V_58 ) ;
V_54 = F_20 ( V_53 , V_25 , V_59 , NULL , & V_52 ) ;
F_18 ( & V_6 -> V_58 ) ;
if ( V_54 )
return V_54 ;
V_50 -> type = V_6 -> type ;
return F_3 ( V_6 , & V_52 . V_50 , & V_50 -> V_52 . V_10 ) ;
}
static int
F_21 ( struct V_5 * V_6 , struct V_60 * V_61 )
{
struct V_49 V_50 ;
int V_54 ;
memcpy ( & V_50 , & V_61 -> V_50 , sizeof( V_50 ) ) ;
V_54 = F_19 ( V_6 , & V_50 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_61 -> V_50 . V_52 . V_10 . V_20 != V_50 . V_52 . V_10 . V_20 ||
V_61 -> V_50 . V_52 . V_10 . V_15 != V_50 . V_52 . V_10 . V_15 ||
V_61 -> V_50 . V_52 . V_10 . V_14 != V_50 . V_52 . V_10 . V_14 ||
V_61 -> V_50 . V_52 . V_10 . V_12 != V_50 . V_52 . V_10 . V_12 ||
V_61 -> V_50 . V_52 . V_10 . V_21 != V_50 . V_52 . V_10 . V_21 ||
V_61 -> V_50 . V_52 . V_10 . V_23 != V_50 . V_52 . V_10 . V_23 )
return - V_55 ;
return 0 ;
}
static int F_22 ( struct V_62 * V_63 ,
const void * V_64 ,
unsigned int * V_65 , unsigned int * V_66 ,
unsigned int V_67 [] , void * V_68 [] )
{
struct V_60 * V_61 = F_23 ( V_63 ) ;
struct V_5 * V_6 = V_61 -> V_6 ;
* V_66 = 1 ;
V_67 [ 0 ] = V_61 -> V_50 . V_52 . V_10 . V_21 ;
if ( V_67 [ 0 ] == 0 )
return - V_55 ;
V_68 [ 0 ] = V_6 -> V_69 ;
* V_65 = F_24 ( * V_65 , V_6 -> V_70 / F_25 ( V_67 [ 0 ] ) ) ;
return 0 ;
}
static int F_26 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = F_27 ( V_72 ) ;
struct V_60 * V_61 = F_23 ( V_72 -> V_62 ) ;
struct V_75 * V_76 = F_28 ( V_74 ) ;
struct V_5 * V_6 = V_61 -> V_6 ;
T_2 V_77 ;
if ( F_29 ( V_6 -> error ) )
return - V_78 ;
V_77 = F_30 ( V_72 , 0 ) ;
if ( ! F_31 ( V_77 , 32 ) ) {
F_32 ( V_6 -> V_79 -> V_80 ,
L_1 ) ;
return - V_55 ;
}
F_33 ( & V_76 -> V_81 . V_82 , 0 ,
V_61 -> V_50 . V_52 . V_10 . V_21 ) ;
V_76 -> V_83 = V_77 ;
return 0 ;
}
static void F_34 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = F_27 ( V_72 ) ;
struct V_60 * V_61 = F_23 ( V_72 -> V_62 ) ;
struct V_75 * V_76 = F_28 ( V_74 ) ;
struct V_5 * V_6 = V_61 -> V_6 ;
struct V_31 * V_32 = F_35 ( & V_6 -> V_6 . V_28 ) ;
enum V_84 V_85 ;
unsigned long V_86 ;
unsigned int V_87 ;
unsigned int V_88 ;
F_36 ( & V_6 -> V_89 , V_86 ) ;
if ( F_29 ( V_6 -> error ) ) {
F_37 ( & V_76 -> V_81 . V_82 , V_90 ) ;
F_38 ( & V_6 -> V_89 , V_86 ) ;
return;
}
V_87 = F_39 ( & V_6 -> V_91 ) ;
F_40 ( & V_76 -> V_92 , & V_6 -> V_91 ) ;
F_38 ( & V_6 -> V_89 , V_86 ) ;
if ( V_87 ) {
if ( V_6 -> type == V_45 )
V_85 = V_93 ;
else
V_85 = V_94 ;
F_36 ( & V_32 -> V_95 , V_86 ) ;
V_32 -> V_85 |= V_85 ;
V_6 -> V_96 -> V_63 ( V_6 , V_76 ) ;
V_6 -> V_97 |= V_98 ;
V_88 = F_41 ( V_32 ) ;
if ( V_88 )
V_32 -> V_85 |= V_99 ;
F_38 ( & V_32 -> V_95 , V_86 ) ;
if ( V_88 )
F_42 ( V_32 ,
V_100 ) ;
}
}
struct V_75 * F_43 ( struct V_5 * V_6 )
{
struct V_31 * V_32 = F_35 ( & V_6 -> V_6 . V_28 ) ;
enum V_84 V_85 ;
struct V_75 * V_72 ;
unsigned long V_86 ;
F_36 ( & V_6 -> V_89 , V_86 ) ;
if ( F_4 ( F_39 ( & V_6 -> V_91 ) ) ) {
F_38 ( & V_6 -> V_89 , V_86 ) ;
return NULL ;
}
V_72 = F_44 ( & V_6 -> V_91 , struct V_75 ,
V_92 ) ;
F_45 ( & V_72 -> V_92 ) ;
F_38 ( & V_6 -> V_89 , V_86 ) ;
F_46 ( & V_72 -> V_81 . V_101 ) ;
if ( V_6 == V_32 -> V_47 && ! V_32 -> V_102 )
V_72 -> V_81 . V_103 =
F_47 ( & V_32 -> V_104 ) ;
else
V_72 -> V_81 . V_103 = F_48 ( & V_32 -> V_104 ) ;
if ( V_32 -> V_23 != V_105 )
V_72 -> V_81 . V_103 /= 2 ;
V_72 -> V_81 . V_23 = V_32 -> V_23 ;
if ( V_6 -> type == V_45 && V_32 -> error ) {
V_85 = V_90 ;
V_32 -> error = false ;
} else {
V_85 = V_106 ;
}
F_37 ( & V_72 -> V_81 . V_82 , V_85 ) ;
F_36 ( & V_6 -> V_89 , V_86 ) ;
if ( F_39 ( & V_6 -> V_91 ) ) {
F_38 ( & V_6 -> V_89 , V_86 ) ;
if ( V_6 -> type == V_45 )
V_85 = V_93
| V_99 ;
else
V_85 = V_94
| V_99 ;
F_36 ( & V_32 -> V_95 , V_86 ) ;
V_32 -> V_85 &= ~ V_85 ;
if ( V_6 -> V_32 . V_107 == V_108 )
V_6 -> V_97 |= V_109 ;
F_38 ( & V_32 -> V_95 , V_86 ) ;
return NULL ;
}
if ( V_6 -> type == V_45 && V_32 -> V_46 != NULL ) {
F_49 ( & V_32 -> V_95 ) ;
V_32 -> V_85 &= ~ V_99 ;
F_50 ( & V_32 -> V_95 ) ;
}
V_72 = F_44 ( & V_6 -> V_91 , struct V_75 ,
V_92 ) ;
F_38 ( & V_6 -> V_89 , V_86 ) ;
return V_72 ;
}
void F_51 ( struct V_5 * V_6 )
{
unsigned long V_86 ;
F_36 ( & V_6 -> V_89 , V_86 ) ;
while ( ! F_39 ( & V_6 -> V_91 ) ) {
struct V_75 * V_72 ;
V_72 = F_44 ( & V_6 -> V_91 ,
struct V_75 , V_92 ) ;
F_45 ( & V_72 -> V_92 ) ;
F_37 ( & V_72 -> V_81 . V_82 , V_90 ) ;
}
V_6 -> error = true ;
F_38 ( & V_6 -> V_89 , V_86 ) ;
}
void F_52 ( struct V_5 * V_6 , int V_110 )
{
struct V_75 * V_72 = NULL ;
if ( V_110 && V_6 -> type == V_45 ) {
F_13 ( & V_6 -> V_111 ) ;
F_53 ( V_6 -> V_63 ) ;
F_18 ( & V_6 -> V_111 ) ;
}
if ( ! F_39 ( & V_6 -> V_91 ) ) {
V_72 = F_44 ( & V_6 -> V_91 ,
struct V_75 , V_92 ) ;
V_6 -> V_96 -> V_63 ( V_6 , V_72 ) ;
V_6 -> V_97 |= V_98 ;
} else {
if ( V_110 )
V_6 -> V_97 |= V_109 ;
}
}
static int
F_54 ( struct V_112 * V_112 , void * V_113 , struct V_114 * V_115 )
{
struct V_5 * V_6 = F_55 ( V_112 ) ;
F_56 ( V_115 -> V_116 , V_117 , sizeof( V_115 -> V_116 ) ) ;
F_56 ( V_115 -> V_118 , V_6 -> V_6 . V_119 , sizeof( V_115 -> V_118 ) ) ;
F_56 ( V_115 -> V_120 , L_2 , sizeof( V_115 -> V_120 ) ) ;
V_115 -> V_121 = V_122 | V_123
| V_124 | V_125 ;
if ( V_6 -> type == V_45 )
V_115 -> V_126 = V_122 | V_124 ;
else
V_115 -> V_126 = V_123 | V_124 ;
return 0 ;
}
static int
F_57 ( struct V_112 * V_112 , void * V_113 , struct V_49 * V_50 )
{
struct V_60 * V_61 = F_58 ( V_113 ) ;
struct V_5 * V_6 = F_55 ( V_112 ) ;
if ( V_50 -> type != V_6 -> type )
return - V_55 ;
F_13 ( & V_6 -> V_58 ) ;
* V_50 = V_61 -> V_50 ;
F_18 ( & V_6 -> V_58 ) ;
return 0 ;
}
static int
F_59 ( struct V_112 * V_112 , void * V_113 , struct V_49 * V_50 )
{
struct V_60 * V_61 = F_58 ( V_113 ) ;
struct V_5 * V_6 = F_55 ( V_112 ) ;
struct V_7 V_52 ;
if ( V_50 -> type != V_6 -> type )
return - V_55 ;
switch ( V_50 -> V_52 . V_10 . V_23 ) {
case V_105 :
break;
case V_127 :
if ( V_6 -> type == V_128 )
V_50 -> V_52 . V_10 . V_23 = V_105 ;
break;
case V_129 :
V_50 -> V_52 . V_10 . V_23 = V_130 ;
case V_130 :
case V_131 :
if ( V_6 != & V_6 -> V_79 -> V_132 . V_133 )
V_50 -> V_52 . V_10 . V_23 = V_105 ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
default:
V_50 -> V_52 . V_10 . V_23 = V_105 ;
break;
}
F_7 ( & V_50 -> V_52 . V_10 , & V_52 ) ;
F_3 ( V_6 , & V_52 , & V_50 -> V_52 . V_10 ) ;
F_13 ( & V_6 -> V_58 ) ;
V_61 -> V_50 = * V_50 ;
F_18 ( & V_6 -> V_58 ) ;
return 0 ;
}
static int
F_60 ( struct V_112 * V_112 , void * V_113 , struct V_49 * V_50 )
{
struct V_5 * V_6 = F_55 ( V_112 ) ;
struct V_51 V_52 ;
struct V_24 * V_53 ;
T_1 V_25 ;
int V_54 ;
if ( V_50 -> type != V_6 -> type )
return - V_55 ;
V_53 = F_8 ( V_6 , & V_25 ) ;
if ( V_53 == NULL )
return - V_55 ;
F_7 ( & V_50 -> V_52 . V_10 , & V_52 . V_50 ) ;
V_52 . V_25 = V_25 ;
V_52 . V_56 = V_57 ;
V_54 = F_20 ( V_53 , V_25 , V_59 , NULL , & V_52 ) ;
if ( V_54 )
return V_54 == - V_138 ? - V_139 : V_54 ;
F_3 ( V_6 , & V_52 . V_50 , & V_50 -> V_52 . V_10 ) ;
return 0 ;
}
static int
F_61 ( struct V_112 * V_112 , void * V_113 , struct V_140 * V_141 )
{
struct V_5 * V_6 = F_55 ( V_112 ) ;
struct V_24 * V_53 ;
int V_54 ;
V_53 = F_8 ( V_6 , NULL ) ;
if ( V_53 == NULL )
return - V_55 ;
F_13 ( & V_6 -> V_58 ) ;
V_54 = F_20 ( V_53 , V_6 , V_141 , V_141 ) ;
F_18 ( & V_6 -> V_58 ) ;
return V_54 == - V_138 ? - V_139 : V_54 ;
}
static int
F_62 ( struct V_112 * V_112 , void * V_113 , struct V_142 * V_143 )
{
struct V_5 * V_6 = F_55 ( V_112 ) ;
struct V_51 V_50 ;
struct V_24 * V_53 ;
T_1 V_25 ;
int V_54 ;
V_53 = F_8 ( V_6 , & V_25 ) ;
if ( V_53 == NULL )
return - V_55 ;
V_54 = F_20 ( V_53 , V_6 , V_144 , V_143 ) ;
if ( V_54 != - V_138 )
return V_54 ;
V_50 . V_25 = V_25 ;
V_50 . V_56 = V_57 ;
V_54 = F_20 ( V_53 , V_25 , V_59 , NULL , & V_50 ) ;
if ( V_54 < 0 )
return V_54 == - V_138 ? - V_139 : V_54 ;
V_143 -> V_145 . V_146 = 0 ;
V_143 -> V_145 . V_147 = 0 ;
V_143 -> V_145 . V_14 = V_50 . V_50 . V_14 ;
V_143 -> V_145 . V_15 = V_50 . V_50 . V_15 ;
return 0 ;
}
static int
F_63 ( struct V_112 * V_112 , void * V_113 , const struct V_142 * V_143 )
{
struct V_5 * V_6 = F_55 ( V_112 ) ;
struct V_24 * V_53 ;
int V_54 ;
V_53 = F_8 ( V_6 , NULL ) ;
if ( V_53 == NULL )
return - V_55 ;
F_13 ( & V_6 -> V_58 ) ;
V_54 = F_20 ( V_53 , V_6 , V_148 , V_143 ) ;
F_18 ( & V_6 -> V_58 ) ;
return V_54 == - V_138 ? - V_139 : V_54 ;
}
static int
F_64 ( struct V_112 * V_112 , void * V_113 , struct V_149 * V_150 )
{
struct V_60 * V_61 = F_58 ( V_113 ) ;
struct V_5 * V_6 = F_55 ( V_112 ) ;
if ( V_6 -> type != V_128 ||
V_6 -> type != V_150 -> type )
return - V_55 ;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_150 -> type = V_128 ;
V_150 -> V_151 . V_47 . V_152 = V_153 ;
V_150 -> V_151 . V_47 . V_154 = V_61 -> V_154 ;
return 0 ;
}
static int
F_65 ( struct V_112 * V_112 , void * V_113 , struct V_149 * V_150 )
{
struct V_60 * V_61 = F_58 ( V_113 ) ;
struct V_5 * V_6 = F_55 ( V_112 ) ;
if ( V_6 -> type != V_128 ||
V_6 -> type != V_150 -> type )
return - V_55 ;
if ( V_150 -> V_151 . V_47 . V_154 . V_155 == 0 )
V_150 -> V_151 . V_47 . V_154 . V_155 = 1 ;
V_61 -> V_154 = V_150 -> V_151 . V_47 . V_154 ;
return 0 ;
}
static int
F_66 ( struct V_112 * V_112 , void * V_113 , struct V_156 * V_157 )
{
struct V_60 * V_61 = F_58 ( V_113 ) ;
struct V_5 * V_6 = F_55 ( V_112 ) ;
int V_54 ;
F_13 ( & V_6 -> V_111 ) ;
V_54 = F_67 ( & V_61 -> V_63 , V_157 ) ;
F_18 ( & V_6 -> V_111 ) ;
return V_54 ;
}
static int
F_68 ( struct V_112 * V_112 , void * V_113 , struct V_158 * V_159 )
{
struct V_60 * V_61 = F_58 ( V_113 ) ;
struct V_5 * V_6 = F_55 ( V_112 ) ;
int V_54 ;
F_13 ( & V_6 -> V_111 ) ;
V_54 = F_69 ( & V_61 -> V_63 , V_159 ) ;
F_18 ( & V_6 -> V_111 ) ;
return V_54 ;
}
static int
F_70 ( struct V_112 * V_112 , void * V_113 , struct V_158 * V_159 )
{
struct V_60 * V_61 = F_58 ( V_113 ) ;
struct V_5 * V_6 = F_55 ( V_112 ) ;
int V_54 ;
F_13 ( & V_6 -> V_111 ) ;
V_54 = F_71 ( & V_61 -> V_63 , V_159 ) ;
F_18 ( & V_6 -> V_111 ) ;
return V_54 ;
}
static int
F_72 ( struct V_112 * V_112 , void * V_113 , struct V_158 * V_159 )
{
struct V_60 * V_61 = F_58 ( V_113 ) ;
struct V_5 * V_6 = F_55 ( V_112 ) ;
int V_54 ;
F_13 ( & V_6 -> V_111 ) ;
V_54 = F_73 ( & V_61 -> V_63 , V_159 , V_112 -> V_160 & V_161 ) ;
F_18 ( & V_6 -> V_111 ) ;
return V_54 ;
}
static int F_74 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
struct V_162 * V_79 = V_6 -> V_79 ;
struct V_35 * V_163 [] = {
& V_79 -> V_164 . V_53 . V_28 ,
& V_79 -> V_165 . V_53 . V_28 ,
& V_79 -> V_166 . V_53 . V_28 ,
& V_79 -> V_132 . V_53 . V_28
} ;
struct V_26 * V_167 ;
struct V_35 * V_168 = NULL ;
struct V_35 * V_169 ;
struct V_51 V_52 ;
struct V_170 V_171 ;
struct V_172 V_173 ;
unsigned int V_3 ;
int V_54 ;
if ( V_32 -> V_46 != NULL )
return 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_163 ) ; V_3 ++ ) {
if ( ! ( V_32 -> V_42 & ( 1 << V_163 [ V_3 ] -> V_43 ) ) )
continue;
V_167 = F_9 ( & V_163 [ V_3 ] -> V_174 [ 0 ] ) ;
if ( V_167 == NULL )
continue;
V_168 = V_167 -> V_28 ;
V_169 = V_163 [ V_3 ] ;
break;
}
if ( ! V_168 ) {
F_75 ( V_79 -> V_80 , L_3 ) ;
return - V_55 ;
}
if ( F_10 ( V_168 ) != V_29 )
return 0 ;
V_32 -> V_175 = F_11 ( V_168 ) ;
V_52 . V_25 = V_167 -> V_30 ;
V_52 . V_56 = V_57 ;
V_54 = F_20 ( F_11 ( V_169 ) ,
V_25 , V_59 , NULL , & V_52 ) ;
if ( F_29 ( V_54 < 0 ) ) {
F_75 ( V_79 -> V_80 , L_4 ) ;
return V_54 ;
}
V_32 -> V_176 =
F_1 ( V_52 . V_50 . V_2 ) -> V_14 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_173 . V_43 = V_177 ;
V_171 . V_65 = 1 ;
V_171 . V_178 = & V_173 ;
V_54 = F_76 ( V_32 -> V_175 -> V_179 , & V_171 ) ;
if ( V_54 < 0 ) {
F_75 ( V_79 -> V_80 , L_5 ,
V_32 -> V_175 -> V_119 ) ;
return V_54 ;
}
V_32 -> V_180 = V_173 . V_181 ;
if ( V_32 -> V_42 & ( 1 << V_79 -> V_132 . V_53 . V_28 . V_43 ) ) {
unsigned int V_182 = V_183 ;
F_77 ( & V_79 -> V_132 , & V_182 ) ;
if ( V_32 -> V_180 > V_182 )
return - V_184 ;
}
return 0 ;
}
static int
F_78 ( struct V_112 * V_112 , void * V_113 , enum V_185 type )
{
struct V_60 * V_61 = F_58 ( V_113 ) ;
struct V_5 * V_6 = F_55 ( V_112 ) ;
enum V_84 V_85 ;
struct V_31 * V_32 ;
unsigned long V_86 ;
int V_54 ;
if ( type != V_6 -> type )
return - V_55 ;
F_13 ( & V_6 -> V_186 ) ;
V_32 = V_6 -> V_6 . V_28 . V_32
? F_35 ( & V_6 -> V_6 . V_28 ) : & V_6 -> V_32 ;
V_32 -> V_42 = 0 ;
V_32 -> V_187 = F_79 ( V_6 -> V_79 -> clock [ V_188 ] ) ;
V_32 -> V_189 = V_32 -> V_187 ;
V_54 = F_80 ( & V_6 -> V_6 . V_28 , & V_32 -> V_32 ) ;
if ( V_54 < 0 )
goto V_190;
V_54 = F_21 ( V_6 , V_61 ) ;
if ( V_54 < 0 )
goto V_191;
V_6 -> V_192 = V_54 ;
V_6 -> V_193 = V_61 -> V_50 . V_52 . V_10 . V_12 ;
V_54 = F_12 ( V_6 , V_32 ) ;
if ( V_54 < 0 )
goto V_191;
if ( V_6 -> type == V_45 )
V_85 = V_194 | V_195 ;
else
V_85 = V_196 | V_197 ;
V_54 = F_74 ( V_6 , V_32 ) ;
if ( V_54 < 0 )
goto V_191;
V_32 -> error = false ;
F_36 ( & V_32 -> V_95 , V_86 ) ;
V_32 -> V_85 &= ~ V_99 ;
V_32 -> V_85 |= V_85 ;
F_38 ( & V_32 -> V_95 , V_86 ) ;
if ( V_6 -> type == V_128 )
V_32 -> V_198 = V_61 -> V_154 ;
V_6 -> V_63 = & V_61 -> V_63 ;
F_81 ( & V_6 -> V_91 ) ;
F_82 ( & V_32 -> V_104 , - 1 ) ;
V_32 -> V_23 = V_61 -> V_50 . V_52 . V_10 . V_23 ;
F_13 ( & V_6 -> V_111 ) ;
V_54 = F_83 ( & V_61 -> V_63 , type ) ;
F_18 ( & V_6 -> V_111 ) ;
if ( V_54 < 0 )
goto V_191;
if ( V_32 -> V_46 == NULL ) {
V_54 = F_42 ( V_32 ,
V_108 ) ;
if ( V_54 < 0 )
goto V_199;
F_36 ( & V_6 -> V_89 , V_86 ) ;
if ( F_39 ( & V_6 -> V_91 ) )
V_6 -> V_97 |= V_109 ;
F_38 ( & V_6 -> V_89 , V_86 ) ;
}
F_18 ( & V_6 -> V_186 ) ;
return 0 ;
V_199:
F_13 ( & V_6 -> V_111 ) ;
F_84 ( & V_61 -> V_63 , type ) ;
F_18 ( & V_6 -> V_111 ) ;
V_191:
F_85 ( & V_6 -> V_6 . V_28 ) ;
V_190:
F_81 ( & V_6 -> V_91 ) ;
V_6 -> V_63 = NULL ;
F_18 ( & V_6 -> V_186 ) ;
return V_54 ;
}
static int
F_86 ( struct V_112 * V_112 , void * V_113 , enum V_185 type )
{
struct V_60 * V_61 = F_58 ( V_113 ) ;
struct V_5 * V_6 = F_55 ( V_112 ) ;
struct V_31 * V_32 = F_35 ( & V_6 -> V_6 . V_28 ) ;
enum V_84 V_85 ;
unsigned int V_200 ;
unsigned long V_86 ;
if ( type != V_6 -> type )
return - V_55 ;
F_13 ( & V_6 -> V_186 ) ;
F_13 ( & V_6 -> V_111 ) ;
V_200 = F_87 ( & V_61 -> V_63 ) ;
F_18 ( & V_6 -> V_111 ) ;
if ( ! V_200 )
goto V_201;
if ( V_6 -> type == V_45 )
V_85 = V_194
| V_93 ;
else
V_85 = V_196
| V_94 ;
F_36 ( & V_32 -> V_95 , V_86 ) ;
V_32 -> V_85 &= ~ V_85 ;
F_38 ( & V_32 -> V_95 , V_86 ) ;
F_42 ( V_32 , V_202 ) ;
F_51 ( V_6 ) ;
F_13 ( & V_6 -> V_111 ) ;
F_84 ( & V_61 -> V_63 , type ) ;
F_18 ( & V_6 -> V_111 ) ;
V_6 -> V_63 = NULL ;
V_6 -> error = false ;
F_85 ( & V_6 -> V_6 . V_28 ) ;
V_201:
F_18 ( & V_6 -> V_186 ) ;
return 0 ;
}
static int
F_88 ( struct V_112 * V_112 , void * V_113 , struct V_203 * V_46 )
{
if ( V_46 -> V_30 > 0 )
return - V_55 ;
F_56 ( V_46 -> V_119 , L_6 , sizeof( V_46 -> V_119 ) ) ;
V_46 -> type = V_204 ;
return 0 ;
}
static int
F_89 ( struct V_112 * V_112 , void * V_113 , unsigned int * V_46 )
{
* V_46 = 0 ;
return 0 ;
}
static int
F_90 ( struct V_112 * V_112 , void * V_113 , unsigned int V_46 )
{
return V_46 == 0 ? 0 : - V_55 ;
}
static int F_91 ( struct V_112 * V_112 )
{
struct V_5 * V_6 = F_55 ( V_112 ) ;
struct V_60 * V_205 ;
struct V_62 * V_63 ;
int V_54 = 0 ;
V_205 = F_92 ( sizeof( * V_205 ) , V_206 ) ;
if ( V_205 == NULL )
return - V_207 ;
F_93 ( & V_205 -> V_61 , & V_6 -> V_6 ) ;
F_94 ( & V_205 -> V_61 ) ;
if ( F_95 ( V_6 -> V_79 ) == NULL ) {
V_54 = - V_208 ;
goto V_201;
}
V_54 = F_96 ( & V_6 -> V_6 . V_28 , 1 ) ;
if ( V_54 < 0 ) {
F_97 ( V_6 -> V_79 ) ;
goto V_201;
}
V_63 = & V_205 -> V_63 ;
V_63 -> type = V_6 -> type ;
V_63 -> V_209 = V_210 | V_211 ;
V_63 -> V_212 = V_205 ;
V_63 -> V_96 = & V_213 ;
V_63 -> V_214 = & V_215 ;
V_63 -> V_216 = sizeof( struct V_75 ) ;
V_63 -> V_217 = V_218 ;
V_54 = F_98 ( & V_205 -> V_63 ) ;
if ( V_54 < 0 ) {
F_97 ( V_6 -> V_79 ) ;
goto V_201;
}
memset ( & V_205 -> V_50 , 0 , sizeof( V_205 -> V_50 ) ) ;
V_205 -> V_50 . type = V_6 -> type ;
V_205 -> V_154 . V_155 = 1 ;
V_205 -> V_6 = V_6 ;
V_112 -> V_219 = & V_205 -> V_61 ;
V_201:
if ( V_54 < 0 ) {
F_99 ( & V_205 -> V_61 ) ;
F_100 ( V_205 ) ;
}
return V_54 ;
}
static int F_101 ( struct V_112 * V_112 )
{
struct V_5 * V_6 = F_55 ( V_112 ) ;
struct V_220 * V_61 = V_112 -> V_219 ;
struct V_60 * V_205 = F_58 ( V_61 ) ;
F_86 ( V_112 , V_61 , V_6 -> type ) ;
F_13 ( & V_6 -> V_111 ) ;
F_102 ( & V_205 -> V_63 ) ;
F_18 ( & V_6 -> V_111 ) ;
F_96 ( & V_6 -> V_6 . V_28 , 0 ) ;
F_99 ( V_61 ) ;
F_100 ( V_205 ) ;
V_112 -> V_219 = NULL ;
F_97 ( V_6 -> V_79 ) ;
return 0 ;
}
static unsigned int F_103 ( struct V_112 * V_112 , T_3 * V_221 )
{
struct V_60 * V_61 = F_58 ( V_112 -> V_219 ) ;
struct V_5 * V_6 = F_55 ( V_112 ) ;
int V_54 ;
F_13 ( & V_6 -> V_111 ) ;
V_54 = F_104 ( & V_61 -> V_63 , V_112 , V_221 ) ;
F_18 ( & V_6 -> V_111 ) ;
return V_54 ;
}
static int F_105 ( struct V_112 * V_112 , struct V_222 * V_223 )
{
struct V_60 * V_61 = F_58 ( V_112 -> V_219 ) ;
return F_106 ( & V_61 -> V_63 , V_223 ) ;
}
int F_107 ( struct V_5 * V_6 , const char * V_119 )
{
const char * V_224 ;
int V_54 ;
switch ( V_6 -> type ) {
case V_45 :
V_224 = L_7 ;
V_6 -> V_25 . V_86 = V_225
| V_226 ;
break;
case V_128 :
V_224 = L_8 ;
V_6 -> V_25 . V_86 = V_227
| V_226 ;
V_6 -> V_6 . V_228 = V_229 ;
break;
default:
return - V_55 ;
}
V_6 -> V_69 = F_108 ( V_6 -> V_79 -> V_80 ) ;
if ( F_109 ( V_6 -> V_69 ) )
return F_110 ( V_6 -> V_69 ) ;
V_54 = F_111 ( & V_6 -> V_6 . V_28 , 1 , & V_6 -> V_25 , 0 ) ;
if ( V_54 < 0 ) {
F_112 ( V_6 -> V_69 ) ;
return V_54 ;
}
F_113 ( & V_6 -> V_58 ) ;
F_82 ( & V_6 -> V_230 , 0 ) ;
F_114 ( & V_6 -> V_32 . V_95 ) ;
F_113 ( & V_6 -> V_186 ) ;
F_113 ( & V_6 -> V_111 ) ;
F_114 ( & V_6 -> V_89 ) ;
if ( V_6 -> V_96 == NULL )
V_6 -> V_96 = & V_231 ;
V_6 -> V_6 . V_232 = & V_233 ;
snprintf ( V_6 -> V_6 . V_119 , sizeof( V_6 -> V_6 . V_119 ) ,
L_9 , V_119 , V_224 ) ;
V_6 -> V_6 . V_234 = V_235 ;
V_6 -> V_6 . V_236 = V_237 ;
V_6 -> V_6 . V_238 = & V_239 ;
V_6 -> V_32 . V_107 = V_202 ;
F_115 ( & V_6 -> V_6 , V_6 ) ;
return 0 ;
}
void F_116 ( struct V_5 * V_6 )
{
F_112 ( V_6 -> V_69 ) ;
F_117 ( & V_6 -> V_6 . V_28 ) ;
F_118 ( & V_6 -> V_111 ) ;
F_118 ( & V_6 -> V_186 ) ;
F_118 ( & V_6 -> V_58 ) ;
}
int F_119 ( struct V_5 * V_6 , struct V_240 * V_241 )
{
int V_54 ;
V_6 -> V_6 . V_242 = V_241 ;
V_54 = F_120 ( & V_6 -> V_6 , V_235 , - 1 ) ;
if ( V_54 < 0 )
F_121 ( V_6 -> V_79 -> V_80 ,
L_10 ,
V_243 , V_54 ) ;
return V_54 ;
}
void F_122 ( struct V_5 * V_6 )
{
if ( F_123 ( & V_6 -> V_6 ) )
F_124 ( & V_6 -> V_6 ) ;
}
