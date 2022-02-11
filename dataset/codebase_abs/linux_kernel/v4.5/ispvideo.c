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
if ( ! V_27 || ! F_10 ( V_27 -> V_28 ) )
return NULL ;
if ( V_25 )
* V_25 = V_27 -> V_29 ;
return F_11 ( V_27 -> V_28 ) ;
}
static int F_12 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
struct V_32 V_33 ;
struct V_34 * V_28 = & V_6 -> V_6 . V_28 ;
struct V_35 * V_36 = V_28 -> V_37 . V_36 ;
struct V_5 * V_38 = NULL ;
int V_39 ;
F_13 ( & V_36 -> V_40 ) ;
V_39 = F_14 ( & V_33 , V_28 -> V_37 . V_36 ) ;
if ( V_39 ) {
F_15 ( & V_36 -> V_40 ) ;
return V_39 ;
}
F_16 ( & V_33 , V_28 ) ;
while ( ( V_28 = F_17 ( & V_33 ) ) ) {
struct V_5 * V_41 ;
F_18 ( & V_31 -> V_42 , V_28 ) ;
if ( V_38 != NULL )
continue;
if ( V_28 == & V_6 -> V_6 . V_28 )
continue;
if ( ! F_19 ( V_28 ) )
continue;
V_41 = F_20 ( F_21 ( V_28 ) ) ;
if ( V_41 -> type != V_6 -> type )
V_38 = V_41 ;
}
F_15 ( & V_36 -> V_40 ) ;
F_22 ( & V_33 ) ;
if ( V_6 -> type == V_43 ) {
V_31 -> V_44 = V_38 ;
V_31 -> V_45 = V_6 ;
} else {
if ( V_38 == NULL )
return - V_46 ;
V_31 -> V_44 = V_6 ;
V_31 -> V_45 = V_38 ;
}
return 0 ;
}
static int
F_23 ( struct V_5 * V_6 , struct V_47 * V_48 )
{
struct V_49 V_50 ;
struct V_24 * V_51 ;
T_1 V_25 ;
int V_39 ;
V_51 = F_8 ( V_6 , & V_25 ) ;
if ( V_51 == NULL )
return - V_52 ;
V_50 . V_25 = V_25 ;
V_50 . V_53 = V_54 ;
F_13 ( & V_6 -> V_55 ) ;
V_39 = F_24 ( V_51 , V_25 , V_56 , NULL , & V_50 ) ;
F_15 ( & V_6 -> V_55 ) ;
if ( V_39 )
return V_39 ;
V_48 -> type = V_6 -> type ;
return F_3 ( V_6 , & V_50 . V_48 , & V_48 -> V_50 . V_10 ) ;
}
static int
F_25 ( struct V_5 * V_6 , struct V_57 * V_58 )
{
struct V_47 V_48 ;
int V_39 ;
memcpy ( & V_48 , & V_58 -> V_48 , sizeof( V_48 ) ) ;
V_39 = F_23 ( V_6 , & V_48 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_58 -> V_48 . V_50 . V_10 . V_20 != V_48 . V_50 . V_10 . V_20 ||
V_58 -> V_48 . V_50 . V_10 . V_15 != V_48 . V_50 . V_10 . V_15 ||
V_58 -> V_48 . V_50 . V_10 . V_14 != V_48 . V_50 . V_10 . V_14 ||
V_58 -> V_48 . V_50 . V_10 . V_12 != V_48 . V_50 . V_10 . V_12 ||
V_58 -> V_48 . V_50 . V_10 . V_21 != V_48 . V_50 . V_10 . V_21 ||
V_58 -> V_48 . V_50 . V_10 . V_23 != V_48 . V_50 . V_10 . V_23 )
return - V_52 ;
return 0 ;
}
static int F_26 ( struct V_59 * V_60 ,
unsigned int * V_61 , unsigned int * V_62 ,
unsigned int V_63 [] , void * V_64 [] )
{
struct V_57 * V_58 = F_27 ( V_60 ) ;
struct V_5 * V_6 = V_58 -> V_6 ;
* V_62 = 1 ;
V_63 [ 0 ] = V_58 -> V_48 . V_50 . V_10 . V_21 ;
if ( V_63 [ 0 ] == 0 )
return - V_52 ;
V_64 [ 0 ] = V_6 -> V_65 ;
* V_61 = F_28 ( * V_61 , V_6 -> V_66 / F_29 ( V_63 [ 0 ] ) ) ;
return 0 ;
}
static int F_30 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = F_31 ( V_68 ) ;
struct V_57 * V_58 = F_27 ( V_68 -> V_59 ) ;
struct V_71 * V_72 = F_32 ( V_70 ) ;
struct V_5 * V_6 = V_58 -> V_6 ;
T_2 V_73 ;
if ( F_33 ( V_6 -> error ) )
return - V_74 ;
V_73 = F_34 ( V_68 , 0 ) ;
if ( ! F_35 ( V_73 , 32 ) ) {
F_36 ( V_6 -> V_75 -> V_76 ,
L_1 ) ;
return - V_52 ;
}
F_37 ( & V_72 -> V_77 . V_78 , 0 ,
V_58 -> V_48 . V_50 . V_10 . V_21 ) ;
V_72 -> V_79 = V_73 ;
return 0 ;
}
static void F_38 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = F_31 ( V_68 ) ;
struct V_57 * V_58 = F_27 ( V_68 -> V_59 ) ;
struct V_71 * V_72 = F_32 ( V_70 ) ;
struct V_5 * V_6 = V_58 -> V_6 ;
struct V_30 * V_31 = F_39 ( & V_6 -> V_6 . V_28 ) ;
enum V_80 V_81 ;
unsigned long V_82 ;
unsigned int V_83 ;
unsigned int V_84 ;
F_40 ( & V_6 -> V_85 , V_82 ) ;
if ( F_33 ( V_6 -> error ) ) {
F_41 ( & V_72 -> V_77 . V_78 , V_86 ) ;
F_42 ( & V_6 -> V_85 , V_82 ) ;
return;
}
V_83 = F_43 ( & V_6 -> V_87 ) ;
F_44 ( & V_72 -> V_88 , & V_6 -> V_87 ) ;
F_42 ( & V_6 -> V_85 , V_82 ) ;
if ( V_83 ) {
if ( V_6 -> type == V_43 )
V_81 = V_89 ;
else
V_81 = V_90 ;
F_40 ( & V_31 -> V_91 , V_82 ) ;
V_31 -> V_81 |= V_81 ;
V_6 -> V_92 -> V_60 ( V_6 , V_72 ) ;
V_6 -> V_93 |= V_94 ;
V_84 = F_45 ( V_31 ) ;
if ( V_84 )
V_31 -> V_81 |= V_95 ;
F_42 ( & V_31 -> V_91 , V_82 ) ;
if ( V_84 )
F_46 ( V_31 ,
V_96 ) ;
}
}
struct V_71 * F_47 ( struct V_5 * V_6 )
{
struct V_30 * V_31 = F_39 ( & V_6 -> V_6 . V_28 ) ;
enum V_80 V_81 ;
struct V_71 * V_68 ;
unsigned long V_82 ;
F_40 ( & V_6 -> V_85 , V_82 ) ;
if ( F_4 ( F_43 ( & V_6 -> V_87 ) ) ) {
F_42 ( & V_6 -> V_85 , V_82 ) ;
return NULL ;
}
V_68 = F_48 ( & V_6 -> V_87 , struct V_71 ,
V_88 ) ;
F_49 ( & V_68 -> V_88 ) ;
F_42 ( & V_6 -> V_85 , V_82 ) ;
V_68 -> V_77 . V_78 . V_97 = F_50 () ;
if ( V_6 == V_31 -> V_45 && ! V_31 -> V_98 )
V_68 -> V_77 . V_99 =
F_51 ( & V_31 -> V_100 ) ;
else
V_68 -> V_77 . V_99 = F_52 ( & V_31 -> V_100 ) ;
if ( V_31 -> V_23 != V_101 )
V_68 -> V_77 . V_99 /= 2 ;
V_68 -> V_77 . V_23 = V_31 -> V_23 ;
if ( V_6 -> type == V_43 && V_31 -> error ) {
V_81 = V_86 ;
V_31 -> error = false ;
} else {
V_81 = V_102 ;
}
F_41 ( & V_68 -> V_77 . V_78 , V_81 ) ;
F_40 ( & V_6 -> V_85 , V_82 ) ;
if ( F_43 ( & V_6 -> V_87 ) ) {
F_42 ( & V_6 -> V_85 , V_82 ) ;
if ( V_6 -> type == V_43 )
V_81 = V_89
| V_95 ;
else
V_81 = V_90
| V_95 ;
F_40 ( & V_31 -> V_91 , V_82 ) ;
V_31 -> V_81 &= ~ V_81 ;
if ( V_6 -> V_31 . V_103 == V_104 )
V_6 -> V_93 |= V_105 ;
F_42 ( & V_31 -> V_91 , V_82 ) ;
return NULL ;
}
if ( V_6 -> type == V_43 && V_31 -> V_44 != NULL ) {
F_53 ( & V_31 -> V_91 ) ;
V_31 -> V_81 &= ~ V_95 ;
F_54 ( & V_31 -> V_91 ) ;
}
V_68 = F_48 ( & V_6 -> V_87 , struct V_71 ,
V_88 ) ;
F_42 ( & V_6 -> V_85 , V_82 ) ;
return V_68 ;
}
void F_55 ( struct V_5 * V_6 )
{
unsigned long V_82 ;
F_40 ( & V_6 -> V_85 , V_82 ) ;
while ( ! F_43 ( & V_6 -> V_87 ) ) {
struct V_71 * V_68 ;
V_68 = F_48 ( & V_6 -> V_87 ,
struct V_71 , V_88 ) ;
F_49 ( & V_68 -> V_88 ) ;
F_41 ( & V_68 -> V_77 . V_78 , V_86 ) ;
}
V_6 -> error = true ;
F_42 ( & V_6 -> V_85 , V_82 ) ;
}
void F_56 ( struct V_5 * V_6 , int V_106 )
{
struct V_71 * V_68 = NULL ;
if ( V_106 && V_6 -> type == V_43 ) {
F_13 ( & V_6 -> V_107 ) ;
F_57 ( V_6 -> V_60 ) ;
F_15 ( & V_6 -> V_107 ) ;
}
if ( ! F_43 ( & V_6 -> V_87 ) ) {
V_68 = F_48 ( & V_6 -> V_87 ,
struct V_71 , V_88 ) ;
V_6 -> V_92 -> V_60 ( V_6 , V_68 ) ;
V_6 -> V_93 |= V_94 ;
} else {
if ( V_106 )
V_6 -> V_93 |= V_105 ;
}
}
static int
F_58 ( struct V_108 * V_108 , void * V_109 , struct V_110 * V_111 )
{
struct V_5 * V_6 = F_59 ( V_108 ) ;
F_60 ( V_111 -> V_112 , V_113 , sizeof( V_111 -> V_112 ) ) ;
F_60 ( V_111 -> V_114 , V_6 -> V_6 . V_115 , sizeof( V_111 -> V_114 ) ) ;
F_60 ( V_111 -> V_116 , L_2 , sizeof( V_111 -> V_116 ) ) ;
V_111 -> V_117 = V_118 | V_119
| V_120 | V_121 ;
if ( V_6 -> type == V_43 )
V_111 -> V_122 = V_118 | V_120 ;
else
V_111 -> V_122 = V_119 | V_120 ;
return 0 ;
}
static int
F_61 ( struct V_108 * V_108 , void * V_109 , struct V_47 * V_48 )
{
struct V_57 * V_58 = F_62 ( V_109 ) ;
struct V_5 * V_6 = F_59 ( V_108 ) ;
if ( V_48 -> type != V_6 -> type )
return - V_52 ;
F_13 ( & V_6 -> V_55 ) ;
* V_48 = V_58 -> V_48 ;
F_15 ( & V_6 -> V_55 ) ;
return 0 ;
}
static int
F_63 ( struct V_108 * V_108 , void * V_109 , struct V_47 * V_48 )
{
struct V_57 * V_58 = F_62 ( V_109 ) ;
struct V_5 * V_6 = F_59 ( V_108 ) ;
struct V_7 V_50 ;
if ( V_48 -> type != V_6 -> type )
return - V_52 ;
switch ( V_48 -> V_50 . V_10 . V_23 ) {
case V_101 :
break;
case V_123 :
if ( V_6 -> type == V_124 )
V_48 -> V_50 . V_10 . V_23 = V_101 ;
break;
case V_125 :
V_48 -> V_50 . V_10 . V_23 = V_126 ;
case V_126 :
case V_127 :
if ( V_6 != & V_6 -> V_75 -> V_128 . V_129 )
V_48 -> V_50 . V_10 . V_23 = V_101 ;
break;
case V_130 :
case V_131 :
case V_132 :
case V_133 :
default:
V_48 -> V_50 . V_10 . V_23 = V_101 ;
break;
}
F_7 ( & V_48 -> V_50 . V_10 , & V_50 ) ;
F_3 ( V_6 , & V_50 , & V_48 -> V_50 . V_10 ) ;
F_13 ( & V_6 -> V_55 ) ;
V_58 -> V_48 = * V_48 ;
F_15 ( & V_6 -> V_55 ) ;
return 0 ;
}
static int
F_64 ( struct V_108 * V_108 , void * V_109 , struct V_47 * V_48 )
{
struct V_5 * V_6 = F_59 ( V_108 ) ;
struct V_49 V_50 ;
struct V_24 * V_51 ;
T_1 V_25 ;
int V_39 ;
if ( V_48 -> type != V_6 -> type )
return - V_52 ;
V_51 = F_8 ( V_6 , & V_25 ) ;
if ( V_51 == NULL )
return - V_52 ;
F_7 ( & V_48 -> V_50 . V_10 , & V_50 . V_48 ) ;
V_50 . V_25 = V_25 ;
V_50 . V_53 = V_54 ;
V_39 = F_24 ( V_51 , V_25 , V_56 , NULL , & V_50 ) ;
if ( V_39 )
return V_39 == - V_134 ? - V_135 : V_39 ;
F_3 ( V_6 , & V_50 . V_48 , & V_48 -> V_50 . V_10 ) ;
return 0 ;
}
static int
F_65 ( struct V_108 * V_108 , void * V_109 , struct V_136 * V_137 )
{
struct V_5 * V_6 = F_59 ( V_108 ) ;
struct V_24 * V_51 ;
int V_39 ;
V_51 = F_8 ( V_6 , NULL ) ;
if ( V_51 == NULL )
return - V_52 ;
F_13 ( & V_6 -> V_55 ) ;
V_39 = F_24 ( V_51 , V_6 , V_137 , V_137 ) ;
F_15 ( & V_6 -> V_55 ) ;
return V_39 == - V_134 ? - V_135 : V_39 ;
}
static int
F_66 ( struct V_108 * V_108 , void * V_109 , struct V_138 * V_139 )
{
struct V_5 * V_6 = F_59 ( V_108 ) ;
struct V_49 V_48 ;
struct V_24 * V_51 ;
T_1 V_25 ;
int V_39 ;
V_51 = F_8 ( V_6 , & V_25 ) ;
if ( V_51 == NULL )
return - V_52 ;
V_39 = F_24 ( V_51 , V_6 , V_140 , V_139 ) ;
if ( V_39 != - V_134 )
return V_39 ;
V_48 . V_25 = V_25 ;
V_48 . V_53 = V_54 ;
V_39 = F_24 ( V_51 , V_25 , V_56 , NULL , & V_48 ) ;
if ( V_39 < 0 )
return V_39 == - V_134 ? - V_135 : V_39 ;
V_139 -> V_141 . V_142 = 0 ;
V_139 -> V_141 . V_143 = 0 ;
V_139 -> V_141 . V_14 = V_48 . V_48 . V_14 ;
V_139 -> V_141 . V_15 = V_48 . V_48 . V_15 ;
return 0 ;
}
static int
F_67 ( struct V_108 * V_108 , void * V_109 , const struct V_138 * V_139 )
{
struct V_5 * V_6 = F_59 ( V_108 ) ;
struct V_24 * V_51 ;
int V_39 ;
V_51 = F_8 ( V_6 , NULL ) ;
if ( V_51 == NULL )
return - V_52 ;
F_13 ( & V_6 -> V_55 ) ;
V_39 = F_24 ( V_51 , V_6 , V_144 , V_139 ) ;
F_15 ( & V_6 -> V_55 ) ;
return V_39 == - V_134 ? - V_135 : V_39 ;
}
static int
F_68 ( struct V_108 * V_108 , void * V_109 , struct V_145 * V_146 )
{
struct V_57 * V_58 = F_62 ( V_109 ) ;
struct V_5 * V_6 = F_59 ( V_108 ) ;
if ( V_6 -> type != V_124 ||
V_6 -> type != V_146 -> type )
return - V_52 ;
memset ( V_146 , 0 , sizeof( * V_146 ) ) ;
V_146 -> type = V_124 ;
V_146 -> V_147 . V_45 . V_148 = V_149 ;
V_146 -> V_147 . V_45 . V_150 = V_58 -> V_150 ;
return 0 ;
}
static int
F_69 ( struct V_108 * V_108 , void * V_109 , struct V_145 * V_146 )
{
struct V_57 * V_58 = F_62 ( V_109 ) ;
struct V_5 * V_6 = F_59 ( V_108 ) ;
if ( V_6 -> type != V_124 ||
V_6 -> type != V_146 -> type )
return - V_52 ;
if ( V_146 -> V_147 . V_45 . V_150 . V_151 == 0 )
V_146 -> V_147 . V_45 . V_150 . V_151 = 1 ;
V_58 -> V_150 = V_146 -> V_147 . V_45 . V_150 ;
return 0 ;
}
static int
F_70 ( struct V_108 * V_108 , void * V_109 , struct V_152 * V_153 )
{
struct V_57 * V_58 = F_62 ( V_109 ) ;
struct V_5 * V_6 = F_59 ( V_108 ) ;
int V_39 ;
F_13 ( & V_6 -> V_107 ) ;
V_39 = F_71 ( & V_58 -> V_60 , V_153 ) ;
F_15 ( & V_6 -> V_107 ) ;
return V_39 ;
}
static int
F_72 ( struct V_108 * V_108 , void * V_109 , struct V_154 * V_155 )
{
struct V_57 * V_58 = F_62 ( V_109 ) ;
struct V_5 * V_6 = F_59 ( V_108 ) ;
int V_39 ;
F_13 ( & V_6 -> V_107 ) ;
V_39 = F_73 ( & V_58 -> V_60 , V_155 ) ;
F_15 ( & V_6 -> V_107 ) ;
return V_39 ;
}
static int
F_74 ( struct V_108 * V_108 , void * V_109 , struct V_154 * V_155 )
{
struct V_57 * V_58 = F_62 ( V_109 ) ;
struct V_5 * V_6 = F_59 ( V_108 ) ;
int V_39 ;
F_13 ( & V_6 -> V_107 ) ;
V_39 = F_75 ( & V_58 -> V_60 , V_155 ) ;
F_15 ( & V_6 -> V_107 ) ;
return V_39 ;
}
static int
F_76 ( struct V_108 * V_108 , void * V_109 , struct V_154 * V_155 )
{
struct V_57 * V_58 = F_62 ( V_109 ) ;
struct V_5 * V_6 = F_59 ( V_108 ) ;
int V_39 ;
F_13 ( & V_6 -> V_107 ) ;
V_39 = F_77 ( & V_58 -> V_60 , V_155 , V_108 -> V_156 & V_157 ) ;
F_15 ( & V_6 -> V_107 ) ;
return V_39 ;
}
static int F_78 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
struct V_158 * V_75 = V_6 -> V_75 ;
struct V_34 * V_159 [] = {
& V_75 -> V_160 . V_51 . V_28 ,
& V_75 -> V_161 . V_51 . V_28 ,
& V_75 -> V_162 . V_51 . V_28 ,
& V_75 -> V_128 . V_51 . V_28
} ;
struct V_26 * V_163 ;
struct V_34 * V_164 = NULL ;
struct V_34 * V_165 ;
struct V_49 V_50 ;
struct V_166 V_167 ;
struct V_168 V_169 ;
unsigned int V_3 ;
int V_39 ;
if ( V_31 -> V_44 != NULL )
return 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_159 ) ; V_3 ++ ) {
if ( ! F_79 ( & V_31 -> V_42 , V_159 [ V_3 ] ) )
continue;
V_163 = F_9 ( & V_159 [ V_3 ] -> V_170 [ 0 ] ) ;
if ( V_163 == NULL )
continue;
V_164 = V_163 -> V_28 ;
V_165 = V_159 [ V_3 ] ;
break;
}
if ( ! V_164 ) {
F_80 ( V_75 -> V_76 , L_3 ) ;
return - V_52 ;
}
if ( ! F_10 ( V_164 ) )
return 0 ;
V_31 -> V_171 = F_11 ( V_164 ) ;
V_50 . V_25 = V_163 -> V_29 ;
V_50 . V_53 = V_54 ;
V_39 = F_24 ( F_11 ( V_165 ) ,
V_25 , V_56 , NULL , & V_50 ) ;
if ( F_33 ( V_39 < 0 ) ) {
F_80 ( V_75 -> V_76 , L_4 ) ;
return V_39 ;
}
V_31 -> V_172 =
F_1 ( V_50 . V_48 . V_2 ) -> V_14 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
V_169 . V_173 = V_174 ;
V_167 . V_61 = 1 ;
V_167 . V_175 = & V_169 ;
V_39 = F_81 ( V_31 -> V_171 -> V_176 , & V_167 ) ;
if ( V_39 < 0 ) {
F_80 ( V_75 -> V_76 , L_5 ,
V_31 -> V_171 -> V_115 ) ;
return V_39 ;
}
V_31 -> V_177 = V_169 . V_178 ;
if ( F_79 ( & V_31 -> V_42 ,
& V_75 -> V_128 . V_51 . V_28 ) ) {
unsigned int V_179 = V_180 ;
F_82 ( & V_75 -> V_128 , & V_179 ) ;
if ( V_31 -> V_177 > V_179 )
return - V_181 ;
}
return 0 ;
}
static int
F_83 ( struct V_108 * V_108 , void * V_109 , enum V_182 type )
{
struct V_57 * V_58 = F_62 ( V_109 ) ;
struct V_5 * V_6 = F_59 ( V_108 ) ;
enum V_80 V_81 ;
struct V_30 * V_31 ;
unsigned long V_82 ;
int V_39 ;
if ( type != V_6 -> type )
return - V_52 ;
F_13 ( & V_6 -> V_183 ) ;
V_31 = V_6 -> V_6 . V_28 . V_31
? F_39 ( & V_6 -> V_6 . V_28 ) : & V_6 -> V_31 ;
V_39 = F_84 ( & V_31 -> V_42 , & V_6 -> V_75 -> V_184 ) ;
if ( V_39 )
goto V_185;
V_31 -> V_186 = F_85 ( V_6 -> V_75 -> clock [ V_187 ] ) ;
V_31 -> V_188 = V_31 -> V_186 ;
V_39 = F_86 ( & V_6 -> V_6 . V_28 , & V_31 -> V_31 ) ;
if ( V_39 < 0 )
goto V_189;
V_39 = F_25 ( V_6 , V_58 ) ;
if ( V_39 < 0 )
goto V_190;
V_6 -> V_191 = V_39 ;
V_6 -> V_192 = V_58 -> V_48 . V_50 . V_10 . V_12 ;
V_39 = F_12 ( V_6 , V_31 ) ;
if ( V_39 < 0 )
goto V_190;
if ( V_6 -> type == V_43 )
V_81 = V_193 | V_194 ;
else
V_81 = V_195 | V_196 ;
V_39 = F_78 ( V_6 , V_31 ) ;
if ( V_39 < 0 )
goto V_190;
V_31 -> error = false ;
F_40 ( & V_31 -> V_91 , V_82 ) ;
V_31 -> V_81 &= ~ V_95 ;
V_31 -> V_81 |= V_81 ;
F_42 ( & V_31 -> V_91 , V_82 ) ;
if ( V_6 -> type == V_124 )
V_31 -> V_197 = V_58 -> V_150 ;
V_6 -> V_60 = & V_58 -> V_60 ;
F_87 ( & V_6 -> V_87 ) ;
F_88 ( & V_31 -> V_100 , - 1 ) ;
V_31 -> V_23 = V_58 -> V_48 . V_50 . V_10 . V_23 ;
F_13 ( & V_6 -> V_107 ) ;
V_39 = F_89 ( & V_58 -> V_60 , type ) ;
F_15 ( & V_6 -> V_107 ) ;
if ( V_39 < 0 )
goto V_190;
if ( V_31 -> V_44 == NULL ) {
V_39 = F_46 ( V_31 ,
V_104 ) ;
if ( V_39 < 0 )
goto V_198;
F_40 ( & V_6 -> V_85 , V_82 ) ;
if ( F_43 ( & V_6 -> V_87 ) )
V_6 -> V_93 |= V_105 ;
F_42 ( & V_6 -> V_85 , V_82 ) ;
}
F_15 ( & V_6 -> V_183 ) ;
return 0 ;
V_198:
F_13 ( & V_6 -> V_107 ) ;
F_90 ( & V_58 -> V_60 , type ) ;
F_15 ( & V_6 -> V_107 ) ;
V_190:
F_91 ( & V_6 -> V_6 . V_28 ) ;
V_189:
F_87 ( & V_6 -> V_87 ) ;
V_6 -> V_60 = NULL ;
F_92 ( & V_31 -> V_42 ) ;
V_185:
F_15 ( & V_6 -> V_183 ) ;
return V_39 ;
}
static int
F_93 ( struct V_108 * V_108 , void * V_109 , enum V_182 type )
{
struct V_57 * V_58 = F_62 ( V_109 ) ;
struct V_5 * V_6 = F_59 ( V_108 ) ;
struct V_30 * V_31 = F_39 ( & V_6 -> V_6 . V_28 ) ;
enum V_80 V_81 ;
unsigned int V_199 ;
unsigned long V_82 ;
if ( type != V_6 -> type )
return - V_52 ;
F_13 ( & V_6 -> V_183 ) ;
F_13 ( & V_6 -> V_107 ) ;
V_199 = F_94 ( & V_58 -> V_60 ) ;
F_15 ( & V_6 -> V_107 ) ;
if ( ! V_199 )
goto V_200;
if ( V_6 -> type == V_43 )
V_81 = V_193
| V_89 ;
else
V_81 = V_195
| V_90 ;
F_40 ( & V_31 -> V_91 , V_82 ) ;
V_31 -> V_81 &= ~ V_81 ;
F_42 ( & V_31 -> V_91 , V_82 ) ;
F_46 ( V_31 , V_201 ) ;
F_55 ( V_6 ) ;
F_13 ( & V_6 -> V_107 ) ;
F_90 ( & V_58 -> V_60 , type ) ;
F_15 ( & V_6 -> V_107 ) ;
V_6 -> V_60 = NULL ;
V_6 -> error = false ;
F_91 ( & V_6 -> V_6 . V_28 ) ;
F_92 ( & V_31 -> V_42 ) ;
V_200:
F_15 ( & V_6 -> V_183 ) ;
return 0 ;
}
static int
F_95 ( struct V_108 * V_108 , void * V_109 , struct V_202 * V_44 )
{
if ( V_44 -> V_29 > 0 )
return - V_52 ;
F_60 ( V_44 -> V_115 , L_6 , sizeof( V_44 -> V_115 ) ) ;
V_44 -> type = V_203 ;
return 0 ;
}
static int
F_96 ( struct V_108 * V_108 , void * V_109 , unsigned int * V_44 )
{
* V_44 = 0 ;
return 0 ;
}
static int
F_97 ( struct V_108 * V_108 , void * V_109 , unsigned int V_44 )
{
return V_44 == 0 ? 0 : - V_52 ;
}
static int F_98 ( struct V_108 * V_108 )
{
struct V_5 * V_6 = F_59 ( V_108 ) ;
struct V_57 * V_204 ;
struct V_59 * V_60 ;
int V_39 = 0 ;
V_204 = F_99 ( sizeof( * V_204 ) , V_205 ) ;
if ( V_204 == NULL )
return - V_206 ;
F_100 ( & V_204 -> V_58 , & V_6 -> V_6 ) ;
F_101 ( & V_204 -> V_58 ) ;
if ( F_102 ( V_6 -> V_75 ) == NULL ) {
V_39 = - V_207 ;
goto V_200;
}
V_39 = F_14 ( & V_204 -> V_33 ,
& V_6 -> V_75 -> V_184 ) ;
if ( V_39 )
goto V_200;
V_39 = F_103 ( & V_6 -> V_6 . V_28 , 1 , & V_204 -> V_33 ) ;
if ( V_39 < 0 ) {
F_104 ( V_6 -> V_75 ) ;
goto V_200;
}
V_60 = & V_204 -> V_60 ;
V_60 -> type = V_6 -> type ;
V_60 -> V_208 = V_209 | V_210 ;
V_60 -> V_211 = V_204 ;
V_60 -> V_92 = & V_212 ;
V_60 -> V_213 = & V_214 ;
V_60 -> V_215 = sizeof( struct V_71 ) ;
V_60 -> V_216 = V_217 ;
V_39 = F_105 ( & V_204 -> V_60 ) ;
if ( V_39 < 0 ) {
F_104 ( V_6 -> V_75 ) ;
goto V_200;
}
memset ( & V_204 -> V_48 , 0 , sizeof( V_204 -> V_48 ) ) ;
V_204 -> V_48 . type = V_6 -> type ;
V_204 -> V_150 . V_151 = 1 ;
V_204 -> V_6 = V_6 ;
V_108 -> V_218 = & V_204 -> V_58 ;
V_200:
if ( V_39 < 0 ) {
F_106 ( & V_204 -> V_58 ) ;
F_22 ( & V_204 -> V_33 ) ;
F_107 ( V_204 ) ;
}
return V_39 ;
}
static int F_108 ( struct V_108 * V_108 )
{
struct V_5 * V_6 = F_59 ( V_108 ) ;
struct V_219 * V_58 = V_108 -> V_218 ;
struct V_57 * V_204 = F_62 ( V_58 ) ;
F_93 ( V_108 , V_58 , V_6 -> type ) ;
F_13 ( & V_6 -> V_107 ) ;
F_109 ( & V_204 -> V_60 ) ;
F_15 ( & V_6 -> V_107 ) ;
F_103 ( & V_6 -> V_6 . V_28 , 0 , & V_204 -> V_33 ) ;
F_22 ( & V_204 -> V_33 ) ;
F_106 ( V_58 ) ;
F_107 ( V_204 ) ;
V_108 -> V_218 = NULL ;
F_104 ( V_6 -> V_75 ) ;
return 0 ;
}
static unsigned int F_110 ( struct V_108 * V_108 , T_3 * V_220 )
{
struct V_57 * V_58 = F_62 ( V_108 -> V_218 ) ;
struct V_5 * V_6 = F_59 ( V_108 ) ;
int V_39 ;
F_13 ( & V_6 -> V_107 ) ;
V_39 = F_111 ( & V_58 -> V_60 , V_108 , V_220 ) ;
F_15 ( & V_6 -> V_107 ) ;
return V_39 ;
}
static int F_112 ( struct V_108 * V_108 , struct V_221 * V_222 )
{
struct V_57 * V_58 = F_62 ( V_108 -> V_218 ) ;
return F_113 ( & V_58 -> V_60 , V_222 ) ;
}
int F_114 ( struct V_5 * V_6 , const char * V_115 )
{
const char * V_223 ;
int V_39 ;
switch ( V_6 -> type ) {
case V_43 :
V_223 = L_7 ;
V_6 -> V_25 . V_82 = V_224
| V_225 ;
break;
case V_124 :
V_223 = L_8 ;
V_6 -> V_25 . V_82 = V_226
| V_225 ;
V_6 -> V_6 . V_227 = V_228 ;
break;
default:
return - V_52 ;
}
V_6 -> V_65 = F_115 ( V_6 -> V_75 -> V_76 ) ;
if ( F_116 ( V_6 -> V_65 ) )
return F_117 ( V_6 -> V_65 ) ;
V_39 = F_118 ( & V_6 -> V_6 . V_28 , 1 , & V_6 -> V_25 ) ;
if ( V_39 < 0 ) {
F_119 ( V_6 -> V_65 ) ;
return V_39 ;
}
F_120 ( & V_6 -> V_55 ) ;
F_88 ( & V_6 -> V_229 , 0 ) ;
F_121 ( & V_6 -> V_31 . V_91 ) ;
F_120 ( & V_6 -> V_183 ) ;
F_120 ( & V_6 -> V_107 ) ;
F_121 ( & V_6 -> V_85 ) ;
if ( V_6 -> V_92 == NULL )
V_6 -> V_92 = & V_230 ;
V_6 -> V_6 . V_231 = & V_232 ;
snprintf ( V_6 -> V_6 . V_115 , sizeof( V_6 -> V_6 . V_115 ) ,
L_9 , V_115 , V_223 ) ;
V_6 -> V_6 . V_233 = V_234 ;
V_6 -> V_6 . V_235 = V_236 ;
V_6 -> V_6 . V_237 = & V_238 ;
V_6 -> V_31 . V_103 = V_201 ;
F_122 ( & V_6 -> V_6 , V_6 ) ;
return 0 ;
}
void F_123 ( struct V_5 * V_6 )
{
F_119 ( V_6 -> V_65 ) ;
F_124 ( & V_6 -> V_6 . V_28 ) ;
F_125 ( & V_6 -> V_107 ) ;
F_125 ( & V_6 -> V_183 ) ;
F_125 ( & V_6 -> V_55 ) ;
}
int F_126 ( struct V_5 * V_6 , struct V_239 * V_240 )
{
int V_39 ;
V_6 -> V_6 . V_241 = V_240 ;
V_39 = F_127 ( & V_6 -> V_6 , V_234 , - 1 ) ;
if ( V_39 < 0 )
F_128 ( V_6 -> V_75 -> V_76 ,
L_10 ,
V_242 , V_39 ) ;
return V_39 ;
}
void F_129 ( struct V_5 * V_6 )
{
if ( F_130 ( & V_6 -> V_6 ) )
F_131 ( & V_6 -> V_6 ) ;
}
