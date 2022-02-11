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
const struct V_49 * V_52 ,
unsigned int * V_64 , unsigned int * V_65 ,
unsigned int V_66 [] , void * V_67 [] )
{
struct V_60 * V_61 = F_23 ( V_63 ) ;
struct V_5 * V_6 = V_61 -> V_6 ;
* V_65 = 1 ;
V_66 [ 0 ] = V_61 -> V_50 . V_52 . V_10 . V_21 ;
if ( V_66 [ 0 ] == 0 )
return - V_55 ;
V_67 [ 0 ] = V_6 -> V_68 ;
* V_64 = F_24 ( * V_64 , V_6 -> V_69 / F_25 ( V_66 [ 0 ] ) ) ;
return 0 ;
}
static int F_26 ( struct V_70 * V_71 )
{
struct V_60 * V_61 = F_23 ( V_71 -> V_62 ) ;
struct V_72 * V_73 = F_27 ( V_71 ) ;
struct V_5 * V_6 = V_61 -> V_6 ;
T_2 V_74 ;
if ( F_28 ( V_6 -> error ) )
return - V_75 ;
V_74 = F_29 ( V_71 , 0 ) ;
if ( ! F_30 ( V_74 , 32 ) ) {
F_31 ( V_6 -> V_76 -> V_77 ,
L_1 ) ;
return - V_55 ;
}
F_32 ( & V_73 -> V_78 , 0 , V_61 -> V_50 . V_52 . V_10 . V_21 ) ;
V_73 -> V_79 = V_74 ;
return 0 ;
}
static void F_33 ( struct V_70 * V_71 )
{
struct V_60 * V_61 = F_23 ( V_71 -> V_62 ) ;
struct V_72 * V_73 = F_27 ( V_71 ) ;
struct V_5 * V_6 = V_61 -> V_6 ;
struct V_31 * V_32 = F_34 ( & V_6 -> V_6 . V_28 ) ;
enum V_80 V_81 ;
unsigned long V_82 ;
unsigned int V_83 ;
unsigned int V_84 ;
F_35 ( & V_6 -> V_85 , V_82 ) ;
if ( F_28 ( V_6 -> error ) ) {
F_36 ( & V_73 -> V_78 , V_86 ) ;
F_37 ( & V_6 -> V_85 , V_82 ) ;
return;
}
V_83 = F_38 ( & V_6 -> V_87 ) ;
F_39 ( & V_73 -> V_88 , & V_6 -> V_87 ) ;
F_37 ( & V_6 -> V_85 , V_82 ) ;
if ( V_83 ) {
if ( V_6 -> type == V_45 )
V_81 = V_89 ;
else
V_81 = V_90 ;
F_35 ( & V_32 -> V_91 , V_82 ) ;
V_32 -> V_81 |= V_81 ;
V_6 -> V_92 -> V_63 ( V_6 , V_73 ) ;
V_6 -> V_93 |= V_94 ;
V_84 = F_40 ( V_32 ) ;
if ( V_84 )
V_32 -> V_81 |= V_95 ;
F_37 ( & V_32 -> V_91 , V_82 ) ;
if ( V_84 )
F_41 ( V_32 ,
V_96 ) ;
}
}
struct V_72 * F_42 ( struct V_5 * V_6 )
{
struct V_31 * V_32 = F_34 ( & V_6 -> V_6 . V_28 ) ;
enum V_80 V_81 ;
struct V_72 * V_71 ;
unsigned long V_82 ;
F_35 ( & V_6 -> V_85 , V_82 ) ;
if ( F_4 ( F_38 ( & V_6 -> V_87 ) ) ) {
F_37 ( & V_6 -> V_85 , V_82 ) ;
return NULL ;
}
V_71 = F_43 ( & V_6 -> V_87 , struct V_72 ,
V_88 ) ;
F_44 ( & V_71 -> V_88 ) ;
F_37 ( & V_6 -> V_85 , V_82 ) ;
F_45 ( & V_71 -> V_78 . V_97 . V_98 ) ;
if ( V_6 == V_32 -> V_47 && ! V_32 -> V_99 )
V_71 -> V_78 . V_97 . V_100 =
F_46 ( & V_32 -> V_101 ) ;
else
V_71 -> V_78 . V_97 . V_100 = F_47 ( & V_32 -> V_101 ) ;
if ( V_32 -> V_23 != V_102 )
V_71 -> V_78 . V_97 . V_100 /= 2 ;
V_71 -> V_78 . V_97 . V_23 = V_32 -> V_23 ;
if ( V_6 -> type == V_45 && V_32 -> error ) {
V_81 = V_86 ;
V_32 -> error = false ;
} else {
V_81 = V_103 ;
}
F_36 ( & V_71 -> V_78 , V_81 ) ;
F_35 ( & V_6 -> V_85 , V_82 ) ;
if ( F_38 ( & V_6 -> V_87 ) ) {
F_37 ( & V_6 -> V_85 , V_82 ) ;
if ( V_6 -> type == V_45 )
V_81 = V_89
| V_95 ;
else
V_81 = V_90
| V_95 ;
F_35 ( & V_32 -> V_91 , V_82 ) ;
V_32 -> V_81 &= ~ V_81 ;
if ( V_6 -> V_32 . V_104 == V_105 )
V_6 -> V_93 |= V_106 ;
F_37 ( & V_32 -> V_91 , V_82 ) ;
return NULL ;
}
if ( V_6 -> type == V_45 && V_32 -> V_46 != NULL ) {
F_48 ( & V_32 -> V_91 ) ;
V_32 -> V_81 &= ~ V_95 ;
F_49 ( & V_32 -> V_91 ) ;
}
V_71 = F_43 ( & V_6 -> V_87 , struct V_72 ,
V_88 ) ;
F_37 ( & V_6 -> V_85 , V_82 ) ;
return V_71 ;
}
void F_50 ( struct V_5 * V_6 )
{
unsigned long V_82 ;
F_35 ( & V_6 -> V_85 , V_82 ) ;
while ( ! F_38 ( & V_6 -> V_87 ) ) {
struct V_72 * V_71 ;
V_71 = F_43 ( & V_6 -> V_87 ,
struct V_72 , V_88 ) ;
F_44 ( & V_71 -> V_88 ) ;
F_36 ( & V_71 -> V_78 , V_86 ) ;
}
V_6 -> error = true ;
F_37 ( & V_6 -> V_85 , V_82 ) ;
}
void F_51 ( struct V_5 * V_6 , int V_107 )
{
struct V_72 * V_71 = NULL ;
if ( V_107 && V_6 -> type == V_45 ) {
F_13 ( & V_6 -> V_108 ) ;
F_52 ( V_6 -> V_63 ) ;
F_18 ( & V_6 -> V_108 ) ;
}
if ( ! F_38 ( & V_6 -> V_87 ) ) {
V_71 = F_43 ( & V_6 -> V_87 ,
struct V_72 , V_88 ) ;
V_6 -> V_92 -> V_63 ( V_6 , V_71 ) ;
V_6 -> V_93 |= V_94 ;
} else {
if ( V_107 )
V_6 -> V_93 |= V_106 ;
}
}
static int
F_53 ( struct V_109 * V_109 , void * V_110 , struct V_111 * V_112 )
{
struct V_5 * V_6 = F_54 ( V_109 ) ;
F_55 ( V_112 -> V_113 , V_114 , sizeof( V_112 -> V_113 ) ) ;
F_55 ( V_112 -> V_115 , V_6 -> V_6 . V_116 , sizeof( V_112 -> V_115 ) ) ;
F_55 ( V_112 -> V_117 , L_2 , sizeof( V_112 -> V_117 ) ) ;
V_112 -> V_118 = V_119 | V_120
| V_121 | V_122 ;
if ( V_6 -> type == V_45 )
V_112 -> V_123 = V_119 | V_121 ;
else
V_112 -> V_123 = V_120 | V_121 ;
return 0 ;
}
static int
F_56 ( struct V_109 * V_109 , void * V_110 , struct V_49 * V_50 )
{
struct V_60 * V_61 = F_57 ( V_110 ) ;
struct V_5 * V_6 = F_54 ( V_109 ) ;
if ( V_50 -> type != V_6 -> type )
return - V_55 ;
F_13 ( & V_6 -> V_58 ) ;
* V_50 = V_61 -> V_50 ;
F_18 ( & V_6 -> V_58 ) ;
return 0 ;
}
static int
F_58 ( struct V_109 * V_109 , void * V_110 , struct V_49 * V_50 )
{
struct V_60 * V_61 = F_57 ( V_110 ) ;
struct V_5 * V_6 = F_54 ( V_109 ) ;
struct V_7 V_52 ;
if ( V_50 -> type != V_6 -> type )
return - V_55 ;
switch ( V_50 -> V_52 . V_10 . V_23 ) {
case V_102 :
break;
case V_124 :
if ( V_6 -> type == V_125 )
V_50 -> V_52 . V_10 . V_23 = V_102 ;
break;
case V_126 :
V_50 -> V_52 . V_10 . V_23 = V_127 ;
case V_127 :
case V_128 :
if ( V_6 != & V_6 -> V_76 -> V_129 . V_130 )
V_50 -> V_52 . V_10 . V_23 = V_102 ;
break;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
default:
V_50 -> V_52 . V_10 . V_23 = V_102 ;
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
F_59 ( struct V_109 * V_109 , void * V_110 , struct V_49 * V_50 )
{
struct V_5 * V_6 = F_54 ( V_109 ) ;
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
return V_54 == - V_135 ? - V_136 : V_54 ;
F_3 ( V_6 , & V_52 . V_50 , & V_50 -> V_52 . V_10 ) ;
return 0 ;
}
static int
F_60 ( struct V_109 * V_109 , void * V_110 , struct V_137 * V_138 )
{
struct V_5 * V_6 = F_54 ( V_109 ) ;
struct V_24 * V_53 ;
int V_54 ;
V_53 = F_8 ( V_6 , NULL ) ;
if ( V_53 == NULL )
return - V_55 ;
F_13 ( & V_6 -> V_58 ) ;
V_54 = F_20 ( V_53 , V_6 , V_138 , V_138 ) ;
F_18 ( & V_6 -> V_58 ) ;
return V_54 == - V_135 ? - V_136 : V_54 ;
}
static int
F_61 ( struct V_109 * V_109 , void * V_110 , struct V_139 * V_140 )
{
struct V_5 * V_6 = F_54 ( V_109 ) ;
struct V_51 V_50 ;
struct V_24 * V_53 ;
T_1 V_25 ;
int V_54 ;
V_53 = F_8 ( V_6 , & V_25 ) ;
if ( V_53 == NULL )
return - V_55 ;
V_54 = F_20 ( V_53 , V_6 , V_141 , V_140 ) ;
if ( V_54 != - V_135 )
return V_54 ;
V_50 . V_25 = V_25 ;
V_50 . V_56 = V_57 ;
V_54 = F_20 ( V_53 , V_25 , V_59 , NULL , & V_50 ) ;
if ( V_54 < 0 )
return V_54 == - V_135 ? - V_136 : V_54 ;
V_140 -> V_142 . V_143 = 0 ;
V_140 -> V_142 . V_144 = 0 ;
V_140 -> V_142 . V_14 = V_50 . V_50 . V_14 ;
V_140 -> V_142 . V_15 = V_50 . V_50 . V_15 ;
return 0 ;
}
static int
F_62 ( struct V_109 * V_109 , void * V_110 , const struct V_139 * V_140 )
{
struct V_5 * V_6 = F_54 ( V_109 ) ;
struct V_24 * V_53 ;
int V_54 ;
V_53 = F_8 ( V_6 , NULL ) ;
if ( V_53 == NULL )
return - V_55 ;
F_13 ( & V_6 -> V_58 ) ;
V_54 = F_20 ( V_53 , V_6 , V_145 , V_140 ) ;
F_18 ( & V_6 -> V_58 ) ;
return V_54 == - V_135 ? - V_136 : V_54 ;
}
static int
F_63 ( struct V_109 * V_109 , void * V_110 , struct V_146 * V_147 )
{
struct V_60 * V_61 = F_57 ( V_110 ) ;
struct V_5 * V_6 = F_54 ( V_109 ) ;
if ( V_6 -> type != V_125 ||
V_6 -> type != V_147 -> type )
return - V_55 ;
memset ( V_147 , 0 , sizeof( * V_147 ) ) ;
V_147 -> type = V_125 ;
V_147 -> V_148 . V_47 . V_149 = V_150 ;
V_147 -> V_148 . V_47 . V_151 = V_61 -> V_151 ;
return 0 ;
}
static int
F_64 ( struct V_109 * V_109 , void * V_110 , struct V_146 * V_147 )
{
struct V_60 * V_61 = F_57 ( V_110 ) ;
struct V_5 * V_6 = F_54 ( V_109 ) ;
if ( V_6 -> type != V_125 ||
V_6 -> type != V_147 -> type )
return - V_55 ;
if ( V_147 -> V_148 . V_47 . V_151 . V_152 == 0 )
V_147 -> V_148 . V_47 . V_151 . V_152 = 1 ;
V_61 -> V_151 = V_147 -> V_148 . V_47 . V_151 ;
return 0 ;
}
static int
F_65 ( struct V_109 * V_109 , void * V_110 , struct V_153 * V_154 )
{
struct V_60 * V_61 = F_57 ( V_110 ) ;
struct V_5 * V_6 = F_54 ( V_109 ) ;
int V_54 ;
F_13 ( & V_6 -> V_108 ) ;
V_54 = F_66 ( & V_61 -> V_63 , V_154 ) ;
F_18 ( & V_6 -> V_108 ) ;
return V_54 ;
}
static int
F_67 ( struct V_109 * V_109 , void * V_110 , struct V_155 * V_156 )
{
struct V_60 * V_61 = F_57 ( V_110 ) ;
struct V_5 * V_6 = F_54 ( V_109 ) ;
int V_54 ;
F_13 ( & V_6 -> V_108 ) ;
V_54 = F_68 ( & V_61 -> V_63 , V_156 ) ;
F_18 ( & V_6 -> V_108 ) ;
return V_54 ;
}
static int
F_69 ( struct V_109 * V_109 , void * V_110 , struct V_155 * V_156 )
{
struct V_60 * V_61 = F_57 ( V_110 ) ;
struct V_5 * V_6 = F_54 ( V_109 ) ;
int V_54 ;
F_13 ( & V_6 -> V_108 ) ;
V_54 = F_70 ( & V_61 -> V_63 , V_156 ) ;
F_18 ( & V_6 -> V_108 ) ;
return V_54 ;
}
static int
F_71 ( struct V_109 * V_109 , void * V_110 , struct V_155 * V_156 )
{
struct V_60 * V_61 = F_57 ( V_110 ) ;
struct V_5 * V_6 = F_54 ( V_109 ) ;
int V_54 ;
F_13 ( & V_6 -> V_108 ) ;
V_54 = F_72 ( & V_61 -> V_63 , V_156 , V_109 -> V_157 & V_158 ) ;
F_18 ( & V_6 -> V_108 ) ;
return V_54 ;
}
static int F_73 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
struct V_159 * V_76 = V_6 -> V_76 ;
struct V_35 * V_160 [] = {
& V_76 -> V_161 . V_53 . V_28 ,
& V_76 -> V_162 . V_53 . V_28 ,
& V_76 -> V_163 . V_53 . V_28 ,
& V_76 -> V_129 . V_53 . V_28
} ;
struct V_26 * V_164 ;
struct V_35 * V_165 = NULL ;
struct V_35 * V_166 ;
struct V_51 V_52 ;
struct V_167 V_168 ;
struct V_169 V_170 ;
unsigned int V_3 ;
int V_54 ;
if ( V_32 -> V_46 != NULL )
return 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_160 ) ; V_3 ++ ) {
if ( ! ( V_32 -> V_42 & ( 1 << V_160 [ V_3 ] -> V_43 ) ) )
continue;
V_164 = F_9 ( & V_160 [ V_3 ] -> V_171 [ 0 ] ) ;
if ( V_164 == NULL )
continue;
V_165 = V_164 -> V_28 ;
V_166 = V_160 [ V_3 ] ;
break;
}
if ( ! V_165 ) {
F_74 ( V_76 -> V_77 , L_3 ) ;
return - V_55 ;
}
if ( F_10 ( V_165 ) != V_29 )
return 0 ;
V_32 -> V_172 = F_11 ( V_165 ) ;
V_52 . V_25 = V_164 -> V_30 ;
V_52 . V_56 = V_57 ;
V_54 = F_20 ( F_11 ( V_166 ) ,
V_25 , V_59 , NULL , & V_52 ) ;
if ( F_28 ( V_54 < 0 ) ) {
F_74 ( V_76 -> V_77 , L_4 ) ;
return V_54 ;
}
V_32 -> V_173 =
F_1 ( V_52 . V_50 . V_2 ) -> V_14 ;
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
V_170 . V_43 = V_174 ;
V_168 . V_64 = 1 ;
V_168 . V_175 = & V_170 ;
V_54 = F_75 ( V_32 -> V_172 -> V_176 , & V_168 ) ;
if ( V_54 < 0 ) {
F_74 ( V_76 -> V_77 , L_5 ,
V_32 -> V_172 -> V_116 ) ;
return V_54 ;
}
V_32 -> V_177 = V_170 . V_178 ;
if ( V_32 -> V_42 & ( 1 << V_76 -> V_129 . V_53 . V_28 . V_43 ) ) {
unsigned int V_179 = V_180 ;
F_76 ( & V_76 -> V_129 , & V_179 ) ;
if ( V_32 -> V_177 > V_179 )
return - V_181 ;
}
return 0 ;
}
static int
F_77 ( struct V_109 * V_109 , void * V_110 , enum V_182 type )
{
struct V_60 * V_61 = F_57 ( V_110 ) ;
struct V_5 * V_6 = F_54 ( V_109 ) ;
enum V_80 V_81 ;
struct V_31 * V_32 ;
unsigned long V_82 ;
int V_54 ;
if ( type != V_6 -> type )
return - V_55 ;
F_13 ( & V_6 -> V_183 ) ;
V_32 = V_6 -> V_6 . V_28 . V_32
? F_34 ( & V_6 -> V_6 . V_28 ) : & V_6 -> V_32 ;
V_32 -> V_42 = 0 ;
if ( V_6 -> V_76 -> V_184 && V_6 -> V_76 -> V_184 -> V_185 )
V_6 -> V_76 -> V_184 -> V_185 ( V_6 -> V_76 , true ) ;
V_32 -> V_186 = F_78 ( V_6 -> V_76 -> clock [ V_187 ] ) ;
V_32 -> V_188 = V_32 -> V_186 ;
V_54 = F_79 ( & V_6 -> V_6 . V_28 , & V_32 -> V_32 ) ;
if ( V_54 < 0 )
goto V_189;
V_54 = F_21 ( V_6 , V_61 ) ;
if ( V_54 < 0 )
goto V_190;
V_6 -> V_191 = V_54 ;
V_6 -> V_192 = V_61 -> V_50 . V_52 . V_10 . V_12 ;
V_54 = F_12 ( V_6 , V_32 ) ;
if ( V_54 < 0 )
goto V_190;
if ( V_6 -> type == V_45 )
V_81 = V_193 | V_194 ;
else
V_81 = V_195 | V_196 ;
V_54 = F_73 ( V_6 , V_32 ) ;
if ( V_54 < 0 )
goto V_190;
V_32 -> error = false ;
F_35 ( & V_32 -> V_91 , V_82 ) ;
V_32 -> V_81 &= ~ V_95 ;
V_32 -> V_81 |= V_81 ;
F_37 ( & V_32 -> V_91 , V_82 ) ;
if ( V_6 -> type == V_125 )
V_32 -> V_197 = V_61 -> V_151 ;
V_6 -> V_63 = & V_61 -> V_63 ;
F_80 ( & V_6 -> V_87 ) ;
F_81 ( & V_32 -> V_101 , - 1 ) ;
V_32 -> V_23 = V_61 -> V_50 . V_52 . V_10 . V_23 ;
F_13 ( & V_6 -> V_108 ) ;
V_54 = F_82 ( & V_61 -> V_63 , type ) ;
F_18 ( & V_6 -> V_108 ) ;
if ( V_54 < 0 )
goto V_190;
if ( V_32 -> V_46 == NULL ) {
V_54 = F_41 ( V_32 ,
V_105 ) ;
if ( V_54 < 0 )
goto V_198;
F_35 ( & V_6 -> V_85 , V_82 ) ;
if ( F_38 ( & V_6 -> V_87 ) )
V_6 -> V_93 |= V_106 ;
F_37 ( & V_6 -> V_85 , V_82 ) ;
}
F_18 ( & V_6 -> V_183 ) ;
return 0 ;
V_198:
F_13 ( & V_6 -> V_108 ) ;
F_83 ( & V_61 -> V_63 , type ) ;
F_18 ( & V_6 -> V_108 ) ;
V_190:
F_84 ( & V_6 -> V_6 . V_28 ) ;
V_189:
if ( V_6 -> V_76 -> V_184 && V_6 -> V_76 -> V_184 -> V_185 )
V_6 -> V_76 -> V_184 -> V_185 ( V_6 -> V_76 , false ) ;
F_80 ( & V_6 -> V_87 ) ;
V_6 -> V_63 = NULL ;
F_18 ( & V_6 -> V_183 ) ;
return V_54 ;
}
static int
F_85 ( struct V_109 * V_109 , void * V_110 , enum V_182 type )
{
struct V_60 * V_61 = F_57 ( V_110 ) ;
struct V_5 * V_6 = F_54 ( V_109 ) ;
struct V_31 * V_32 = F_34 ( & V_6 -> V_6 . V_28 ) ;
enum V_80 V_81 ;
unsigned int V_199 ;
unsigned long V_82 ;
if ( type != V_6 -> type )
return - V_55 ;
F_13 ( & V_6 -> V_183 ) ;
F_13 ( & V_6 -> V_108 ) ;
V_199 = F_86 ( & V_61 -> V_63 ) ;
F_18 ( & V_6 -> V_108 ) ;
if ( ! V_199 )
goto V_200;
if ( V_6 -> type == V_45 )
V_81 = V_193
| V_89 ;
else
V_81 = V_195
| V_90 ;
F_35 ( & V_32 -> V_91 , V_82 ) ;
V_32 -> V_81 &= ~ V_81 ;
F_37 ( & V_32 -> V_91 , V_82 ) ;
F_41 ( V_32 , V_201 ) ;
F_50 ( V_6 ) ;
F_13 ( & V_6 -> V_108 ) ;
F_83 ( & V_61 -> V_63 , type ) ;
F_18 ( & V_6 -> V_108 ) ;
V_6 -> V_63 = NULL ;
V_6 -> error = false ;
if ( V_6 -> V_76 -> V_184 && V_6 -> V_76 -> V_184 -> V_185 )
V_6 -> V_76 -> V_184 -> V_185 ( V_6 -> V_76 , false ) ;
F_84 ( & V_6 -> V_6 . V_28 ) ;
V_200:
F_18 ( & V_6 -> V_183 ) ;
return 0 ;
}
static int
F_87 ( struct V_109 * V_109 , void * V_110 , struct V_202 * V_46 )
{
if ( V_46 -> V_30 > 0 )
return - V_55 ;
F_55 ( V_46 -> V_116 , L_6 , sizeof( V_46 -> V_116 ) ) ;
V_46 -> type = V_203 ;
return 0 ;
}
static int
F_88 ( struct V_109 * V_109 , void * V_110 , unsigned int * V_46 )
{
* V_46 = 0 ;
return 0 ;
}
static int
F_89 ( struct V_109 * V_109 , void * V_110 , unsigned int V_46 )
{
return V_46 == 0 ? 0 : - V_55 ;
}
static int F_90 ( struct V_109 * V_109 )
{
struct V_5 * V_6 = F_54 ( V_109 ) ;
struct V_60 * V_204 ;
struct V_62 * V_63 ;
int V_54 = 0 ;
V_204 = F_91 ( sizeof( * V_204 ) , V_205 ) ;
if ( V_204 == NULL )
return - V_206 ;
F_92 ( & V_204 -> V_61 , & V_6 -> V_6 ) ;
F_93 ( & V_204 -> V_61 ) ;
if ( F_94 ( V_6 -> V_76 ) == NULL ) {
V_54 = - V_207 ;
goto V_200;
}
V_54 = F_95 ( & V_6 -> V_6 . V_28 , 1 ) ;
if ( V_54 < 0 ) {
F_96 ( V_6 -> V_76 ) ;
goto V_200;
}
V_63 = & V_204 -> V_63 ;
V_63 -> type = V_6 -> type ;
V_63 -> V_208 = V_209 | V_210 ;
V_63 -> V_211 = V_204 ;
V_63 -> V_92 = & V_212 ;
V_63 -> V_213 = & V_214 ;
V_63 -> V_215 = sizeof( struct V_72 ) ;
V_63 -> V_216 = V_217 ;
V_54 = F_97 ( & V_204 -> V_63 ) ;
if ( V_54 < 0 ) {
F_96 ( V_6 -> V_76 ) ;
goto V_200;
}
memset ( & V_204 -> V_50 , 0 , sizeof( V_204 -> V_50 ) ) ;
V_204 -> V_50 . type = V_6 -> type ;
V_204 -> V_151 . V_152 = 1 ;
V_204 -> V_6 = V_6 ;
V_109 -> V_218 = & V_204 -> V_61 ;
V_200:
if ( V_54 < 0 ) {
F_98 ( & V_204 -> V_61 ) ;
F_99 ( V_204 ) ;
}
return V_54 ;
}
static int F_100 ( struct V_109 * V_109 )
{
struct V_5 * V_6 = F_54 ( V_109 ) ;
struct V_219 * V_61 = V_109 -> V_218 ;
struct V_60 * V_204 = F_57 ( V_61 ) ;
F_85 ( V_109 , V_61 , V_6 -> type ) ;
F_13 ( & V_6 -> V_108 ) ;
F_101 ( & V_204 -> V_63 ) ;
F_18 ( & V_6 -> V_108 ) ;
F_95 ( & V_6 -> V_6 . V_28 , 0 ) ;
F_98 ( V_61 ) ;
F_99 ( V_204 ) ;
V_109 -> V_218 = NULL ;
F_96 ( V_6 -> V_76 ) ;
return 0 ;
}
static unsigned int F_102 ( struct V_109 * V_109 , T_3 * V_220 )
{
struct V_60 * V_61 = F_57 ( V_109 -> V_218 ) ;
struct V_5 * V_6 = F_54 ( V_109 ) ;
int V_54 ;
F_13 ( & V_6 -> V_108 ) ;
V_54 = F_103 ( & V_61 -> V_63 , V_109 , V_220 ) ;
F_18 ( & V_6 -> V_108 ) ;
return V_54 ;
}
static int F_104 ( struct V_109 * V_109 , struct V_221 * V_222 )
{
struct V_60 * V_61 = F_57 ( V_109 -> V_218 ) ;
return F_105 ( & V_61 -> V_63 , V_222 ) ;
}
int F_106 ( struct V_5 * V_6 , const char * V_116 )
{
const char * V_223 ;
int V_54 ;
switch ( V_6 -> type ) {
case V_45 :
V_223 = L_7 ;
V_6 -> V_25 . V_82 = V_224
| V_225 ;
break;
case V_125 :
V_223 = L_8 ;
V_6 -> V_25 . V_82 = V_226
| V_225 ;
V_6 -> V_6 . V_227 = V_228 ;
break;
default:
return - V_55 ;
}
V_6 -> V_68 = F_107 ( V_6 -> V_76 -> V_77 ) ;
if ( F_108 ( V_6 -> V_68 ) )
return F_109 ( V_6 -> V_68 ) ;
V_54 = F_110 ( & V_6 -> V_6 . V_28 , 1 , & V_6 -> V_25 , 0 ) ;
if ( V_54 < 0 ) {
F_111 ( V_6 -> V_68 ) ;
return V_54 ;
}
F_112 ( & V_6 -> V_58 ) ;
F_81 ( & V_6 -> V_229 , 0 ) ;
F_113 ( & V_6 -> V_32 . V_91 ) ;
F_112 ( & V_6 -> V_183 ) ;
F_112 ( & V_6 -> V_108 ) ;
F_113 ( & V_6 -> V_85 ) ;
if ( V_6 -> V_92 == NULL )
V_6 -> V_92 = & V_230 ;
V_6 -> V_6 . V_231 = & V_232 ;
snprintf ( V_6 -> V_6 . V_116 , sizeof( V_6 -> V_6 . V_116 ) ,
L_9 , V_116 , V_223 ) ;
V_6 -> V_6 . V_233 = V_234 ;
V_6 -> V_6 . V_235 = V_236 ;
V_6 -> V_6 . V_237 = & V_238 ;
V_6 -> V_32 . V_104 = V_201 ;
F_114 ( & V_6 -> V_6 , V_6 ) ;
return 0 ;
}
void F_115 ( struct V_5 * V_6 )
{
F_111 ( V_6 -> V_68 ) ;
F_116 ( & V_6 -> V_6 . V_28 ) ;
F_117 ( & V_6 -> V_108 ) ;
F_117 ( & V_6 -> V_183 ) ;
F_117 ( & V_6 -> V_58 ) ;
}
int F_118 ( struct V_5 * V_6 , struct V_239 * V_240 )
{
int V_54 ;
V_6 -> V_6 . V_241 = V_240 ;
V_54 = F_119 ( & V_6 -> V_6 , V_234 , - 1 ) ;
if ( V_54 < 0 )
F_120 ( V_6 -> V_76 -> V_77 ,
L_10 ,
V_242 , V_54 ) ;
return V_54 ;
}
void F_121 ( struct V_5 * V_6 )
{
if ( F_122 ( & V_6 -> V_6 ) )
F_123 ( & V_6 -> V_6 ) ;
}
