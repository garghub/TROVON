const struct V_1 *
F_1 ( enum V_2 V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_3 == V_3 )
return & V_5 [ V_4 ] ;
}
return NULL ;
}
static unsigned int F_3 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_10 * V_11 )
{
unsigned int V_12 = V_11 -> V_13 ;
unsigned int V_14 ;
unsigned int V_4 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_15 = V_9 -> V_15 ;
V_11 -> V_16 = V_9 -> V_16 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_3 == V_9 -> V_3 )
break;
}
if ( F_4 ( V_4 == F_2 ( V_5 ) ) )
return 0 ;
V_14 = V_11 -> V_15 * V_5 [ V_4 ] . V_17 ;
if ( V_7 -> V_18 )
V_12 = F_5 ( V_12 , V_14 , V_7 -> V_18 ) ;
else
V_12 = V_14 ;
if ( ! V_7 -> V_19 || V_12 != V_14 )
V_12 = F_6 ( V_12 , V_7 -> V_20 ) ;
V_11 -> V_21 = V_5 [ V_4 ] . V_21 ;
V_11 -> V_13 = V_12 ;
V_11 -> V_22 = V_11 -> V_13 * V_11 -> V_16 ;
V_11 -> V_23 = V_9 -> V_23 ;
V_11 -> V_24 = V_9 -> V_24 ;
return V_12 - V_14 ;
}
static void F_7 ( const struct V_10 * V_11 ,
struct V_8 * V_9 )
{
unsigned int V_4 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_15 = V_11 -> V_15 ;
V_9 -> V_16 = V_11 -> V_16 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) - 1 ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_21 == V_11 -> V_21 )
break;
}
V_9 -> V_3 = V_5 [ V_4 ] . V_3 ;
V_9 -> V_23 = V_11 -> V_23 ;
V_9 -> V_24 = V_11 -> V_24 ;
}
static struct V_25 *
F_8 ( struct V_6 * V_7 , T_1 * V_26 )
{
struct V_27 * V_28 ;
V_28 = F_9 ( & V_7 -> V_26 ) ;
if ( V_28 == NULL ||
F_10 ( V_28 -> V_29 ) != V_30 )
return NULL ;
if ( V_26 )
* V_26 = V_28 -> V_31 ;
return F_11 ( V_28 -> V_29 ) ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_32 * V_33 )
{
struct V_34 V_35 ;
struct V_36 * V_29 = & V_7 -> V_7 . V_29 ;
struct V_37 * V_38 = V_29 -> V_39 ;
struct V_6 * V_40 = NULL ;
F_13 ( & V_38 -> V_41 ) ;
F_14 ( & V_35 , V_29 ) ;
while ( ( V_29 = F_15 ( & V_35 ) ) ) {
struct V_6 * V_42 ;
V_33 -> V_43 |= 1 << V_29 -> V_44 ;
if ( V_40 != NULL )
continue;
if ( V_29 == & V_7 -> V_7 . V_29 )
continue;
if ( F_10 ( V_29 ) != V_45 )
continue;
V_42 = F_16 ( F_17 ( V_29 ) ) ;
if ( V_42 -> type != V_7 -> type )
V_40 = V_42 ;
}
F_18 ( & V_38 -> V_41 ) ;
if ( V_7 -> type == V_46 ) {
V_33 -> V_47 = V_40 ;
V_33 -> V_48 = V_7 ;
} else {
if ( V_40 == NULL )
return - V_49 ;
V_33 -> V_47 = V_7 ;
V_33 -> V_48 = V_40 ;
}
return 0 ;
}
static int
F_19 ( struct V_6 * V_7 , struct V_50 * V_51 )
{
struct V_52 V_53 ;
struct V_25 * V_54 ;
T_1 V_26 ;
int V_55 ;
V_54 = F_8 ( V_7 , & V_26 ) ;
if ( V_54 == NULL )
return - V_56 ;
V_53 . V_26 = V_26 ;
V_53 . V_57 = V_58 ;
F_13 ( & V_7 -> V_59 ) ;
V_55 = F_20 ( V_54 , V_26 , V_60 , NULL , & V_53 ) ;
F_18 ( & V_7 -> V_59 ) ;
if ( V_55 )
return V_55 ;
V_51 -> type = V_7 -> type ;
return F_3 ( V_7 , & V_53 . V_51 , & V_51 -> V_53 . V_11 ) ;
}
static int
F_21 ( struct V_6 * V_7 , struct V_61 * V_62 )
{
struct V_50 V_51 ;
int V_55 ;
memcpy ( & V_51 , & V_62 -> V_51 , sizeof( V_51 ) ) ;
V_55 = F_19 ( V_7 , & V_51 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_62 -> V_51 . V_53 . V_11 . V_21 != V_51 . V_53 . V_11 . V_21 ||
V_62 -> V_51 . V_53 . V_11 . V_16 != V_51 . V_53 . V_11 . V_16 ||
V_62 -> V_51 . V_53 . V_11 . V_15 != V_51 . V_53 . V_11 . V_15 ||
V_62 -> V_51 . V_53 . V_11 . V_13 != V_51 . V_53 . V_11 . V_13 ||
V_62 -> V_51 . V_53 . V_11 . V_22 != V_51 . V_53 . V_11 . V_22 ||
V_62 -> V_51 . V_53 . V_11 . V_24 != V_51 . V_53 . V_11 . V_24 )
return - V_56 ;
return 0 ;
}
static int F_22 ( struct V_63 * V_64 ,
const struct V_50 * V_53 ,
unsigned int * V_65 , unsigned int * V_66 ,
unsigned int V_67 [] , void * V_68 [] )
{
struct V_61 * V_62 = F_23 ( V_64 ) ;
struct V_6 * V_7 = V_62 -> V_7 ;
* V_66 = 1 ;
V_67 [ 0 ] = V_62 -> V_51 . V_53 . V_11 . V_22 ;
if ( V_67 [ 0 ] == 0 )
return - V_56 ;
V_68 [ 0 ] = V_7 -> V_69 ;
* V_65 = F_24 ( * V_65 , V_7 -> V_70 / F_25 ( V_67 [ 0 ] ) ) ;
return 0 ;
}
static int F_26 ( struct V_71 * V_72 )
{
struct V_61 * V_62 = F_23 ( V_72 -> V_63 ) ;
struct V_73 * V_74 = F_27 ( V_72 ) ;
struct V_6 * V_7 = V_62 -> V_7 ;
T_2 V_75 ;
if ( F_28 ( V_7 -> error ) )
return - V_76 ;
V_75 = F_29 ( V_72 , 0 ) ;
if ( ! F_30 ( V_75 , 32 ) ) {
F_31 ( V_7 -> V_77 -> V_78 ,
L_1 ) ;
return - V_56 ;
}
F_32 ( & V_74 -> V_79 , 0 , V_62 -> V_51 . V_53 . V_11 . V_22 ) ;
V_74 -> V_80 = V_75 ;
return 0 ;
}
static void F_33 ( struct V_71 * V_72 )
{
struct V_61 * V_62 = F_23 ( V_72 -> V_63 ) ;
struct V_73 * V_74 = F_27 ( V_72 ) ;
struct V_6 * V_7 = V_62 -> V_7 ;
struct V_32 * V_33 = F_34 ( & V_7 -> V_7 . V_29 ) ;
enum V_81 V_82 ;
unsigned long V_83 ;
unsigned int V_84 ;
unsigned int V_85 ;
F_35 ( & V_7 -> V_86 , V_83 ) ;
if ( F_28 ( V_7 -> error ) ) {
F_36 ( & V_74 -> V_79 , V_87 ) ;
F_37 ( & V_7 -> V_86 , V_83 ) ;
return;
}
V_84 = F_38 ( & V_7 -> V_88 ) ;
F_39 ( & V_74 -> V_89 , & V_7 -> V_88 ) ;
F_37 ( & V_7 -> V_86 , V_83 ) ;
if ( V_84 ) {
if ( V_7 -> type == V_46 )
V_82 = V_90 ;
else
V_82 = V_91 ;
F_35 ( & V_33 -> V_92 , V_83 ) ;
V_33 -> V_82 |= V_82 ;
V_7 -> V_93 -> V_64 ( V_7 , V_74 ) ;
V_7 -> V_94 |= V_95 ;
V_85 = F_40 ( V_33 ) ;
if ( V_85 )
V_33 -> V_82 |= V_96 ;
F_37 ( & V_33 -> V_92 , V_83 ) ;
if ( V_85 )
F_41 ( V_33 ,
V_97 ) ;
}
}
struct V_73 * F_42 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = F_34 ( & V_7 -> V_7 . V_29 ) ;
enum V_81 V_82 ;
struct V_73 * V_72 ;
unsigned long V_83 ;
struct V_98 V_99 ;
F_35 ( & V_7 -> V_86 , V_83 ) ;
if ( F_4 ( F_38 ( & V_7 -> V_88 ) ) ) {
F_37 ( & V_7 -> V_86 , V_83 ) ;
return NULL ;
}
V_72 = F_43 ( & V_7 -> V_88 , struct V_73 ,
V_89 ) ;
F_44 ( & V_72 -> V_89 ) ;
F_37 ( & V_7 -> V_86 , V_83 ) ;
F_45 ( & V_99 ) ;
V_72 -> V_79 . V_100 . V_101 . V_102 = V_99 . V_102 ;
V_72 -> V_79 . V_100 . V_101 . V_103 = V_99 . V_104 / V_105 ;
if ( V_7 == V_33 -> V_48 && ! V_33 -> V_106 )
V_72 -> V_79 . V_100 . V_107 =
F_46 ( & V_33 -> V_108 ) ;
else
V_72 -> V_79 . V_100 . V_107 = F_47 ( & V_33 -> V_108 ) ;
if ( V_33 -> V_24 != V_109 )
V_72 -> V_79 . V_100 . V_107 /= 2 ;
V_72 -> V_79 . V_100 . V_24 = V_33 -> V_24 ;
if ( V_7 -> type == V_46 && V_33 -> error ) {
V_82 = V_87 ;
V_33 -> error = false ;
} else {
V_82 = V_110 ;
}
F_36 ( & V_72 -> V_79 , V_82 ) ;
F_35 ( & V_7 -> V_86 , V_83 ) ;
if ( F_38 ( & V_7 -> V_88 ) ) {
F_37 ( & V_7 -> V_86 , V_83 ) ;
if ( V_7 -> type == V_46 )
V_82 = V_90
| V_96 ;
else
V_82 = V_91
| V_96 ;
F_35 ( & V_33 -> V_92 , V_83 ) ;
V_33 -> V_82 &= ~ V_82 ;
if ( V_7 -> V_33 . V_111 == V_112 )
V_7 -> V_94 |= V_113 ;
F_37 ( & V_33 -> V_92 , V_83 ) ;
return NULL ;
}
if ( V_7 -> type == V_46 && V_33 -> V_47 != NULL ) {
F_48 ( & V_33 -> V_92 ) ;
V_33 -> V_82 &= ~ V_96 ;
F_49 ( & V_33 -> V_92 ) ;
}
V_72 = F_43 ( & V_7 -> V_88 , struct V_73 ,
V_89 ) ;
V_72 -> V_79 . V_82 = V_114 ;
F_37 ( & V_7 -> V_86 , V_83 ) ;
return V_72 ;
}
void F_50 ( struct V_6 * V_7 )
{
unsigned long V_83 ;
F_35 ( & V_7 -> V_86 , V_83 ) ;
while ( ! F_38 ( & V_7 -> V_88 ) ) {
struct V_73 * V_72 ;
V_72 = F_43 ( & V_7 -> V_88 ,
struct V_73 , V_89 ) ;
F_44 ( & V_72 -> V_89 ) ;
F_36 ( & V_72 -> V_79 , V_87 ) ;
}
V_7 -> error = true ;
F_37 ( & V_7 -> V_86 , V_83 ) ;
}
void F_51 ( struct V_6 * V_7 , int V_115 )
{
struct V_73 * V_72 = NULL ;
if ( V_115 && V_7 -> type == V_46 ) {
F_13 ( & V_7 -> V_116 ) ;
F_52 ( V_7 -> V_64 ) ;
F_18 ( & V_7 -> V_116 ) ;
}
if ( ! F_38 ( & V_7 -> V_88 ) ) {
V_72 = F_43 ( & V_7 -> V_88 ,
struct V_73 , V_89 ) ;
V_7 -> V_93 -> V_64 ( V_7 , V_72 ) ;
V_7 -> V_94 |= V_95 ;
} else {
if ( V_115 )
V_7 -> V_94 |= V_113 ;
}
}
static int
F_53 ( struct V_117 * V_117 , void * V_118 , struct V_119 * V_120 )
{
struct V_6 * V_7 = F_54 ( V_117 ) ;
F_55 ( V_120 -> V_121 , V_122 , sizeof( V_120 -> V_121 ) ) ;
F_55 ( V_120 -> V_123 , V_7 -> V_7 . V_124 , sizeof( V_120 -> V_123 ) ) ;
F_55 ( V_120 -> V_125 , L_2 , sizeof( V_120 -> V_125 ) ) ;
if ( V_7 -> type == V_46 )
V_120 -> V_126 = V_127 | V_128 ;
else
V_120 -> V_126 = V_129 | V_128 ;
return 0 ;
}
static int
F_56 ( struct V_117 * V_117 , void * V_118 , struct V_50 * V_51 )
{
struct V_61 * V_62 = F_57 ( V_118 ) ;
struct V_6 * V_7 = F_54 ( V_117 ) ;
if ( V_51 -> type != V_7 -> type )
return - V_56 ;
F_13 ( & V_7 -> V_59 ) ;
* V_51 = V_62 -> V_51 ;
F_18 ( & V_7 -> V_59 ) ;
return 0 ;
}
static int
F_58 ( struct V_117 * V_117 , void * V_118 , struct V_50 * V_51 )
{
struct V_61 * V_62 = F_57 ( V_118 ) ;
struct V_6 * V_7 = F_54 ( V_117 ) ;
struct V_8 V_53 ;
if ( V_51 -> type != V_7 -> type )
return - V_56 ;
switch ( V_51 -> V_53 . V_11 . V_24 ) {
case V_109 :
break;
case V_130 :
if ( V_7 -> type == V_131 )
V_51 -> V_53 . V_11 . V_24 = V_109 ;
break;
case V_132 :
V_51 -> V_53 . V_11 . V_24 = V_133 ;
case V_133 :
case V_134 :
if ( V_7 != & V_7 -> V_77 -> V_135 . V_136 )
V_51 -> V_53 . V_11 . V_24 = V_109 ;
break;
case V_137 :
case V_138 :
case V_139 :
case V_140 :
default:
V_51 -> V_53 . V_11 . V_24 = V_109 ;
break;
}
F_7 ( & V_51 -> V_53 . V_11 , & V_53 ) ;
F_3 ( V_7 , & V_53 , & V_51 -> V_53 . V_11 ) ;
F_13 ( & V_7 -> V_59 ) ;
V_62 -> V_51 = * V_51 ;
F_18 ( & V_7 -> V_59 ) ;
return 0 ;
}
static int
F_59 ( struct V_117 * V_117 , void * V_118 , struct V_50 * V_51 )
{
struct V_6 * V_7 = F_54 ( V_117 ) ;
struct V_52 V_53 ;
struct V_25 * V_54 ;
T_1 V_26 ;
int V_55 ;
if ( V_51 -> type != V_7 -> type )
return - V_56 ;
V_54 = F_8 ( V_7 , & V_26 ) ;
if ( V_54 == NULL )
return - V_56 ;
F_7 ( & V_51 -> V_53 . V_11 , & V_53 . V_51 ) ;
V_53 . V_26 = V_26 ;
V_53 . V_57 = V_58 ;
V_55 = F_20 ( V_54 , V_26 , V_60 , NULL , & V_53 ) ;
if ( V_55 )
return V_55 == - V_141 ? - V_142 : V_55 ;
F_3 ( V_7 , & V_53 . V_51 , & V_51 -> V_53 . V_11 ) ;
return 0 ;
}
static int
F_60 ( struct V_117 * V_117 , void * V_118 , struct V_143 * V_144 )
{
struct V_6 * V_7 = F_54 ( V_117 ) ;
struct V_25 * V_54 ;
int V_55 ;
V_54 = F_8 ( V_7 , NULL ) ;
if ( V_54 == NULL )
return - V_56 ;
F_13 ( & V_7 -> V_59 ) ;
V_55 = F_20 ( V_54 , V_7 , V_144 , V_144 ) ;
F_18 ( & V_7 -> V_59 ) ;
return V_55 == - V_141 ? - V_142 : V_55 ;
}
static int
F_61 ( struct V_117 * V_117 , void * V_118 , struct V_145 * V_146 )
{
struct V_6 * V_7 = F_54 ( V_117 ) ;
struct V_52 V_51 ;
struct V_25 * V_54 ;
T_1 V_26 ;
int V_55 ;
V_54 = F_8 ( V_7 , & V_26 ) ;
if ( V_54 == NULL )
return - V_56 ;
V_55 = F_20 ( V_54 , V_7 , V_147 , V_146 ) ;
if ( V_55 != - V_141 )
return V_55 ;
V_51 . V_26 = V_26 ;
V_51 . V_57 = V_58 ;
V_55 = F_20 ( V_54 , V_26 , V_60 , NULL , & V_51 ) ;
if ( V_55 < 0 )
return V_55 == - V_141 ? - V_142 : V_55 ;
V_146 -> V_148 . V_149 = 0 ;
V_146 -> V_148 . V_150 = 0 ;
V_146 -> V_148 . V_15 = V_51 . V_51 . V_15 ;
V_146 -> V_148 . V_16 = V_51 . V_51 . V_16 ;
return 0 ;
}
static int
F_62 ( struct V_117 * V_117 , void * V_118 , const struct V_145 * V_146 )
{
struct V_6 * V_7 = F_54 ( V_117 ) ;
struct V_25 * V_54 ;
int V_55 ;
V_54 = F_8 ( V_7 , NULL ) ;
if ( V_54 == NULL )
return - V_56 ;
F_13 ( & V_7 -> V_59 ) ;
V_55 = F_20 ( V_54 , V_7 , V_151 , V_146 ) ;
F_18 ( & V_7 -> V_59 ) ;
return V_55 == - V_141 ? - V_142 : V_55 ;
}
static int
F_63 ( struct V_117 * V_117 , void * V_118 , struct V_152 * V_153 )
{
struct V_61 * V_62 = F_57 ( V_118 ) ;
struct V_6 * V_7 = F_54 ( V_117 ) ;
if ( V_7 -> type != V_131 ||
V_7 -> type != V_153 -> type )
return - V_56 ;
memset ( V_153 , 0 , sizeof( * V_153 ) ) ;
V_153 -> type = V_131 ;
V_153 -> V_154 . V_48 . V_155 = V_156 ;
V_153 -> V_154 . V_48 . V_157 = V_62 -> V_157 ;
return 0 ;
}
static int
F_64 ( struct V_117 * V_117 , void * V_118 , struct V_152 * V_153 )
{
struct V_61 * V_62 = F_57 ( V_118 ) ;
struct V_6 * V_7 = F_54 ( V_117 ) ;
if ( V_7 -> type != V_131 ||
V_7 -> type != V_153 -> type )
return - V_56 ;
if ( V_153 -> V_154 . V_48 . V_157 . V_158 == 0 )
V_153 -> V_154 . V_48 . V_157 . V_158 = 1 ;
V_62 -> V_157 = V_153 -> V_154 . V_48 . V_157 ;
return 0 ;
}
static int
F_65 ( struct V_117 * V_117 , void * V_118 , struct V_159 * V_160 )
{
struct V_61 * V_62 = F_57 ( V_118 ) ;
struct V_6 * V_7 = F_54 ( V_117 ) ;
int V_55 ;
F_13 ( & V_7 -> V_116 ) ;
V_55 = F_66 ( & V_62 -> V_64 , V_160 ) ;
F_18 ( & V_7 -> V_116 ) ;
return V_55 ;
}
static int
F_67 ( struct V_117 * V_117 , void * V_118 , struct V_161 * V_162 )
{
struct V_61 * V_62 = F_57 ( V_118 ) ;
struct V_6 * V_7 = F_54 ( V_117 ) ;
int V_55 ;
F_13 ( & V_7 -> V_116 ) ;
V_55 = F_68 ( & V_62 -> V_64 , V_162 ) ;
F_18 ( & V_7 -> V_116 ) ;
return V_55 ;
}
static int
F_69 ( struct V_117 * V_117 , void * V_118 , struct V_161 * V_162 )
{
struct V_61 * V_62 = F_57 ( V_118 ) ;
struct V_6 * V_7 = F_54 ( V_117 ) ;
int V_55 ;
F_13 ( & V_7 -> V_116 ) ;
V_55 = F_70 ( & V_62 -> V_64 , V_162 ) ;
F_18 ( & V_7 -> V_116 ) ;
return V_55 ;
}
static int
F_71 ( struct V_117 * V_117 , void * V_118 , struct V_161 * V_162 )
{
struct V_61 * V_62 = F_57 ( V_118 ) ;
struct V_6 * V_7 = F_54 ( V_117 ) ;
int V_55 ;
F_13 ( & V_7 -> V_116 ) ;
V_55 = F_72 ( & V_62 -> V_64 , V_162 , V_117 -> V_163 & V_164 ) ;
F_18 ( & V_7 -> V_116 ) ;
return V_55 ;
}
static int F_73 ( struct V_6 * V_7 ,
struct V_32 * V_33 )
{
struct V_165 * V_77 = V_7 -> V_77 ;
struct V_36 * V_166 [] = {
& V_77 -> V_167 . V_54 . V_29 ,
& V_77 -> V_168 . V_54 . V_29 ,
& V_77 -> V_169 . V_54 . V_29 ,
& V_77 -> V_135 . V_54 . V_29
} ;
struct V_27 * V_170 ;
struct V_36 * V_171 = NULL ;
struct V_36 * V_172 ;
struct V_52 V_53 ;
struct V_173 V_174 ;
struct V_175 V_176 ;
unsigned int V_4 ;
int V_55 ;
if ( V_33 -> V_47 != NULL )
return 0 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_166 ) ; V_4 ++ ) {
if ( ! ( V_33 -> V_43 & ( 1 << V_166 [ V_4 ] -> V_44 ) ) )
continue;
V_170 = F_9 ( & V_166 [ V_4 ] -> V_177 [ 0 ] ) ;
if ( V_170 == NULL )
continue;
V_171 = V_170 -> V_29 ;
V_172 = V_166 [ V_4 ] ;
break;
}
if ( ! V_171 ) {
F_74 ( V_77 -> V_78 , L_3 ) ;
return - V_56 ;
}
if ( F_10 ( V_171 ) != V_30 )
return 0 ;
V_33 -> V_178 = F_11 ( V_171 ) ;
V_53 . V_26 = V_170 -> V_31 ;
V_53 . V_57 = V_58 ;
V_55 = F_20 ( F_11 ( V_172 ) ,
V_26 , V_60 , NULL , & V_53 ) ;
if ( F_28 ( V_55 < 0 ) ) {
F_74 ( V_77 -> V_78 , L_4 ) ;
return V_55 ;
}
V_33 -> V_179 =
F_1 ( V_53 . V_51 . V_3 ) -> V_15 ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_44 = V_180 ;
V_174 . V_65 = 1 ;
V_174 . V_181 = & V_176 ;
V_55 = F_75 ( V_33 -> V_178 -> V_182 , & V_174 ) ;
if ( V_55 < 0 ) {
F_74 ( V_77 -> V_78 , L_5 ,
V_33 -> V_178 -> V_124 ) ;
return V_55 ;
}
V_33 -> V_183 = V_176 . V_184 ;
if ( V_33 -> V_43 & ( 1 << V_77 -> V_135 . V_54 . V_29 . V_44 ) ) {
unsigned int V_185 = V_186 ;
F_76 ( & V_77 -> V_135 , & V_185 ) ;
if ( V_33 -> V_183 > V_185 )
return - V_187 ;
}
return 0 ;
}
static int
F_77 ( struct V_117 * V_117 , void * V_118 , enum V_188 type )
{
struct V_61 * V_62 = F_57 ( V_118 ) ;
struct V_6 * V_7 = F_54 ( V_117 ) ;
enum V_81 V_82 ;
struct V_32 * V_33 ;
unsigned long V_83 ;
int V_55 ;
if ( type != V_7 -> type )
return - V_56 ;
F_13 ( & V_7 -> V_189 ) ;
V_33 = V_7 -> V_7 . V_29 . V_33
? F_34 ( & V_7 -> V_7 . V_29 ) : & V_7 -> V_33 ;
V_33 -> V_43 = 0 ;
if ( V_7 -> V_77 -> V_190 -> V_191 )
V_7 -> V_77 -> V_190 -> V_191 ( V_7 -> V_77 , true ) ;
V_33 -> V_192 = F_78 ( V_7 -> V_77 -> clock [ V_193 ] ) ;
V_33 -> V_194 = V_33 -> V_192 ;
V_55 = F_79 ( & V_7 -> V_7 . V_29 , & V_33 -> V_33 ) ;
if ( V_55 < 0 )
goto V_195;
V_55 = F_21 ( V_7 , V_62 ) ;
if ( V_55 < 0 )
goto V_196;
V_7 -> V_197 = V_55 ;
V_7 -> V_198 = V_62 -> V_51 . V_53 . V_11 . V_13 ;
V_55 = F_12 ( V_7 , V_33 ) ;
if ( V_55 < 0 )
goto V_196;
if ( V_7 -> type == V_46 )
V_82 = V_199 | V_200 ;
else
V_82 = V_201 | V_202 ;
V_55 = F_73 ( V_7 , V_33 ) ;
if ( V_55 < 0 )
goto V_196;
V_33 -> error = false ;
F_35 ( & V_33 -> V_92 , V_83 ) ;
V_33 -> V_82 &= ~ V_96 ;
V_33 -> V_82 |= V_82 ;
F_37 ( & V_33 -> V_92 , V_83 ) ;
if ( V_7 -> type == V_131 )
V_33 -> V_203 = V_62 -> V_157 ;
V_7 -> V_64 = & V_62 -> V_64 ;
F_80 ( & V_7 -> V_88 ) ;
F_81 ( & V_33 -> V_108 , - 1 ) ;
V_33 -> V_24 = V_62 -> V_51 . V_53 . V_11 . V_24 ;
F_13 ( & V_7 -> V_116 ) ;
V_55 = F_82 ( & V_62 -> V_64 , type ) ;
F_18 ( & V_7 -> V_116 ) ;
if ( V_55 < 0 )
goto V_196;
if ( V_33 -> V_47 == NULL ) {
V_55 = F_41 ( V_33 ,
V_112 ) ;
if ( V_55 < 0 )
goto V_204;
F_35 ( & V_7 -> V_86 , V_83 ) ;
if ( F_38 ( & V_7 -> V_88 ) )
V_7 -> V_94 |= V_113 ;
F_37 ( & V_7 -> V_86 , V_83 ) ;
}
F_18 ( & V_7 -> V_189 ) ;
return 0 ;
V_204:
F_13 ( & V_7 -> V_116 ) ;
F_83 ( & V_62 -> V_64 , type ) ;
F_18 ( & V_7 -> V_116 ) ;
V_196:
F_84 ( & V_7 -> V_7 . V_29 ) ;
V_195:
if ( V_7 -> V_77 -> V_190 -> V_191 )
V_7 -> V_77 -> V_190 -> V_191 ( V_7 -> V_77 , false ) ;
F_80 ( & V_7 -> V_88 ) ;
V_7 -> V_64 = NULL ;
F_18 ( & V_7 -> V_189 ) ;
return V_55 ;
}
static int
F_85 ( struct V_117 * V_117 , void * V_118 , enum V_188 type )
{
struct V_61 * V_62 = F_57 ( V_118 ) ;
struct V_6 * V_7 = F_54 ( V_117 ) ;
struct V_32 * V_33 = F_34 ( & V_7 -> V_7 . V_29 ) ;
enum V_81 V_82 ;
unsigned int V_205 ;
unsigned long V_83 ;
if ( type != V_7 -> type )
return - V_56 ;
F_13 ( & V_7 -> V_189 ) ;
F_13 ( & V_7 -> V_116 ) ;
V_205 = F_86 ( & V_62 -> V_64 ) ;
F_18 ( & V_7 -> V_116 ) ;
if ( ! V_205 )
goto V_206;
if ( V_7 -> type == V_46 )
V_82 = V_199
| V_90 ;
else
V_82 = V_201
| V_91 ;
F_35 ( & V_33 -> V_92 , V_83 ) ;
V_33 -> V_82 &= ~ V_82 ;
F_37 ( & V_33 -> V_92 , V_83 ) ;
F_41 ( V_33 , V_207 ) ;
F_50 ( V_7 ) ;
F_13 ( & V_7 -> V_116 ) ;
F_83 ( & V_62 -> V_64 , type ) ;
F_18 ( & V_7 -> V_116 ) ;
V_7 -> V_64 = NULL ;
V_7 -> error = false ;
if ( V_7 -> V_77 -> V_190 -> V_191 )
V_7 -> V_77 -> V_190 -> V_191 ( V_7 -> V_77 , false ) ;
F_84 ( & V_7 -> V_7 . V_29 ) ;
V_206:
F_18 ( & V_7 -> V_189 ) ;
return 0 ;
}
static int
F_87 ( struct V_117 * V_117 , void * V_118 , struct V_208 * V_47 )
{
if ( V_47 -> V_31 > 0 )
return - V_56 ;
F_55 ( V_47 -> V_124 , L_6 , sizeof( V_47 -> V_124 ) ) ;
V_47 -> type = V_209 ;
return 0 ;
}
static int
F_88 ( struct V_117 * V_117 , void * V_118 , unsigned int * V_47 )
{
* V_47 = 0 ;
return 0 ;
}
static int
F_89 ( struct V_117 * V_117 , void * V_118 , unsigned int V_47 )
{
return V_47 == 0 ? 0 : - V_56 ;
}
static int F_90 ( struct V_117 * V_117 )
{
struct V_6 * V_7 = F_54 ( V_117 ) ;
struct V_61 * V_210 ;
struct V_63 * V_64 ;
int V_55 = 0 ;
V_210 = F_91 ( sizeof( * V_210 ) , V_211 ) ;
if ( V_210 == NULL )
return - V_212 ;
F_92 ( & V_210 -> V_62 , & V_7 -> V_7 ) ;
F_93 ( & V_210 -> V_62 ) ;
if ( F_94 ( V_7 -> V_77 ) == NULL ) {
V_55 = - V_213 ;
goto V_206;
}
V_55 = F_95 ( & V_7 -> V_7 . V_29 , 1 ) ;
if ( V_55 < 0 ) {
F_96 ( V_7 -> V_77 ) ;
goto V_206;
}
V_64 = & V_210 -> V_64 ;
V_64 -> type = V_7 -> type ;
V_64 -> V_214 = V_215 | V_216 ;
V_64 -> V_217 = V_210 ;
V_64 -> V_93 = & V_218 ;
V_64 -> V_219 = & V_220 ;
V_64 -> V_221 = sizeof( struct V_73 ) ;
V_64 -> V_222 = V_223 ;
V_55 = F_97 ( & V_210 -> V_64 ) ;
if ( V_55 < 0 ) {
F_96 ( V_7 -> V_77 ) ;
goto V_206;
}
memset ( & V_210 -> V_51 , 0 , sizeof( V_210 -> V_51 ) ) ;
V_210 -> V_51 . type = V_7 -> type ;
V_210 -> V_157 . V_158 = 1 ;
V_210 -> V_7 = V_7 ;
V_117 -> V_224 = & V_210 -> V_62 ;
V_206:
if ( V_55 < 0 ) {
F_98 ( & V_210 -> V_62 ) ;
F_99 ( V_210 ) ;
}
return V_55 ;
}
static int F_100 ( struct V_117 * V_117 )
{
struct V_6 * V_7 = F_54 ( V_117 ) ;
struct V_225 * V_62 = V_117 -> V_224 ;
struct V_61 * V_210 = F_57 ( V_62 ) ;
F_85 ( V_117 , V_62 , V_7 -> type ) ;
F_13 ( & V_7 -> V_116 ) ;
F_101 ( & V_210 -> V_64 ) ;
F_18 ( & V_7 -> V_116 ) ;
F_95 ( & V_7 -> V_7 . V_29 , 0 ) ;
F_98 ( V_62 ) ;
F_99 ( V_210 ) ;
V_117 -> V_224 = NULL ;
F_96 ( V_7 -> V_77 ) ;
return 0 ;
}
static unsigned int F_102 ( struct V_117 * V_117 , T_3 * V_226 )
{
struct V_61 * V_62 = F_57 ( V_117 -> V_224 ) ;
struct V_6 * V_7 = F_54 ( V_117 ) ;
int V_55 ;
F_13 ( & V_7 -> V_116 ) ;
V_55 = F_103 ( & V_62 -> V_64 , V_117 , V_226 ) ;
F_18 ( & V_7 -> V_116 ) ;
return V_55 ;
}
static int F_104 ( struct V_117 * V_117 , struct V_227 * V_228 )
{
struct V_61 * V_62 = F_57 ( V_117 -> V_224 ) ;
struct V_6 * V_7 = F_54 ( V_117 ) ;
int V_55 ;
F_13 ( & V_7 -> V_116 ) ;
V_55 = F_105 ( & V_62 -> V_64 , V_228 ) ;
F_18 ( & V_7 -> V_116 ) ;
return V_55 ;
}
int F_106 ( struct V_6 * V_7 , const char * V_124 )
{
const char * V_229 ;
int V_55 ;
switch ( V_7 -> type ) {
case V_46 :
V_229 = L_7 ;
V_7 -> V_26 . V_83 = V_230
| V_231 ;
break;
case V_131 :
V_229 = L_8 ;
V_7 -> V_26 . V_83 = V_232
| V_231 ;
V_7 -> V_7 . V_233 = V_234 ;
break;
default:
return - V_56 ;
}
V_7 -> V_69 = F_107 ( V_7 -> V_77 -> V_78 ) ;
if ( F_108 ( V_7 -> V_69 ) )
return F_109 ( V_7 -> V_69 ) ;
V_55 = F_110 ( & V_7 -> V_7 . V_29 , 1 , & V_7 -> V_26 , 0 ) ;
if ( V_55 < 0 ) {
F_111 ( V_7 -> V_69 ) ;
return V_55 ;
}
F_112 ( & V_7 -> V_59 ) ;
F_81 ( & V_7 -> V_235 , 0 ) ;
F_113 ( & V_7 -> V_33 . V_92 ) ;
F_112 ( & V_7 -> V_189 ) ;
F_112 ( & V_7 -> V_116 ) ;
F_113 ( & V_7 -> V_86 ) ;
if ( V_7 -> V_93 == NULL )
V_7 -> V_93 = & V_236 ;
V_7 -> V_7 . V_237 = & V_238 ;
snprintf ( V_7 -> V_7 . V_124 , sizeof( V_7 -> V_7 . V_124 ) ,
L_9 , V_124 , V_229 ) ;
V_7 -> V_7 . V_239 = V_240 ;
V_7 -> V_7 . V_241 = V_242 ;
V_7 -> V_7 . V_243 = & V_244 ;
V_7 -> V_33 . V_111 = V_207 ;
F_114 ( & V_7 -> V_7 , V_7 ) ;
return 0 ;
}
void F_115 ( struct V_6 * V_7 )
{
F_111 ( V_7 -> V_69 ) ;
F_116 ( & V_7 -> V_7 . V_29 ) ;
F_117 ( & V_7 -> V_116 ) ;
F_117 ( & V_7 -> V_189 ) ;
F_117 ( & V_7 -> V_59 ) ;
}
int F_118 ( struct V_6 * V_7 , struct V_245 * V_246 )
{
int V_55 ;
V_7 -> V_7 . V_247 = V_246 ;
V_55 = F_119 ( & V_7 -> V_7 , V_240 , - 1 ) ;
if ( V_55 < 0 )
F_120 ( V_7 -> V_77 -> V_78 ,
L_10 ,
V_248 , V_55 ) ;
return V_55 ;
}
void F_121 ( struct V_6 * V_7 )
{
if ( F_122 ( & V_7 -> V_7 ) )
F_123 ( & V_7 -> V_7 ) ;
}
