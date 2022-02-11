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
V_39 = F_14 ( & V_33 , V_36 ) ;
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
unsigned int V_63 [] , struct V_64 * V_65 [] )
{
struct V_57 * V_58 = F_27 ( V_60 ) ;
struct V_5 * V_6 = V_58 -> V_6 ;
* V_62 = 1 ;
V_63 [ 0 ] = V_58 -> V_48 . V_50 . V_10 . V_21 ;
if ( V_63 [ 0 ] == 0 )
return - V_52 ;
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
static void F_47 ( struct V_5 * V_6 ,
enum V_97 V_81 )
{
while ( ! F_43 ( & V_6 -> V_87 ) ) {
struct V_71 * V_68 ;
V_68 = F_48 ( & V_6 -> V_87 ,
struct V_71 , V_88 ) ;
F_49 ( & V_68 -> V_88 ) ;
F_41 ( & V_68 -> V_77 . V_78 , V_81 ) ;
}
}
static int F_50 ( struct V_59 * V_60 ,
unsigned int V_61 )
{
struct V_57 * V_58 = F_27 ( V_60 ) ;
struct V_5 * V_6 = V_58 -> V_6 ;
struct V_30 * V_31 = F_39 ( & V_6 -> V_6 . V_28 ) ;
unsigned long V_82 ;
int V_39 ;
if ( V_31 -> V_44 )
return 0 ;
V_39 = F_46 ( V_31 ,
V_98 ) ;
if ( V_39 < 0 ) {
F_40 ( & V_6 -> V_85 , V_82 ) ;
F_47 ( V_6 , V_99 ) ;
F_42 ( & V_6 -> V_85 , V_82 ) ;
return V_39 ;
}
F_40 ( & V_6 -> V_85 , V_82 ) ;
if ( F_43 ( & V_6 -> V_87 ) )
V_6 -> V_93 |= V_100 ;
F_42 ( & V_6 -> V_85 , V_82 ) ;
return 0 ;
}
struct V_71 * F_51 ( struct V_5 * V_6 )
{
struct V_30 * V_31 = F_39 ( & V_6 -> V_6 . V_28 ) ;
enum V_97 V_101 ;
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
V_68 -> V_77 . V_78 . V_102 = F_52 () ;
if ( V_6 == V_31 -> V_45 && ! V_31 -> V_103 )
V_68 -> V_77 . V_104 =
F_53 ( & V_31 -> V_105 ) ;
else
V_68 -> V_77 . V_104 = F_54 ( & V_31 -> V_105 ) ;
if ( V_31 -> V_23 != V_106 )
V_68 -> V_77 . V_104 /= 2 ;
V_68 -> V_77 . V_23 = V_31 -> V_23 ;
if ( V_6 -> type == V_43 && V_31 -> error ) {
V_101 = V_86 ;
V_31 -> error = false ;
} else {
V_101 = V_107 ;
}
F_41 ( & V_68 -> V_77 . V_78 , V_101 ) ;
F_40 ( & V_6 -> V_85 , V_82 ) ;
if ( F_43 ( & V_6 -> V_87 ) ) {
enum V_80 V_81 ;
F_42 ( & V_6 -> V_85 , V_82 ) ;
if ( V_6 -> type == V_43 )
V_81 = V_89
| V_95 ;
else
V_81 = V_90
| V_95 ;
F_40 ( & V_31 -> V_91 , V_82 ) ;
V_31 -> V_81 &= ~ V_81 ;
if ( V_6 -> V_31 . V_108 == V_98 )
V_6 -> V_93 |= V_100 ;
F_42 ( & V_31 -> V_91 , V_82 ) ;
return NULL ;
}
if ( V_6 -> type == V_43 && V_31 -> V_44 != NULL ) {
F_55 ( & V_31 -> V_91 ) ;
V_31 -> V_81 &= ~ V_95 ;
F_56 ( & V_31 -> V_91 ) ;
}
V_68 = F_48 ( & V_6 -> V_87 , struct V_71 ,
V_88 ) ;
F_42 ( & V_6 -> V_85 , V_82 ) ;
return V_68 ;
}
void F_57 ( struct V_5 * V_6 )
{
unsigned long V_82 ;
F_40 ( & V_6 -> V_85 , V_82 ) ;
F_47 ( V_6 , V_86 ) ;
V_6 -> error = true ;
F_42 ( & V_6 -> V_85 , V_82 ) ;
}
void F_58 ( struct V_5 * V_6 , int V_109 )
{
struct V_71 * V_68 = NULL ;
if ( V_109 && V_6 -> type == V_43 ) {
F_13 ( & V_6 -> V_110 ) ;
F_59 ( V_6 -> V_60 ) ;
F_15 ( & V_6 -> V_110 ) ;
}
if ( ! F_43 ( & V_6 -> V_87 ) ) {
V_68 = F_48 ( & V_6 -> V_87 ,
struct V_71 , V_88 ) ;
V_6 -> V_92 -> V_60 ( V_6 , V_68 ) ;
V_6 -> V_93 |= V_94 ;
} else {
if ( V_109 )
V_6 -> V_93 |= V_100 ;
}
}
static int
F_60 ( struct V_111 * V_111 , void * V_112 , struct V_113 * V_114 )
{
struct V_5 * V_6 = F_61 ( V_111 ) ;
F_62 ( V_114 -> V_115 , V_116 , sizeof( V_114 -> V_115 ) ) ;
F_62 ( V_114 -> V_117 , V_6 -> V_6 . V_118 , sizeof( V_114 -> V_117 ) ) ;
F_62 ( V_114 -> V_119 , L_2 , sizeof( V_114 -> V_119 ) ) ;
V_114 -> V_120 = V_121 | V_122
| V_123 | V_124 ;
if ( V_6 -> type == V_43 )
V_114 -> V_125 = V_121 | V_123 ;
else
V_114 -> V_125 = V_122 | V_123 ;
return 0 ;
}
static int
F_63 ( struct V_111 * V_111 , void * V_112 , struct V_47 * V_48 )
{
struct V_57 * V_58 = F_64 ( V_112 ) ;
struct V_5 * V_6 = F_61 ( V_111 ) ;
if ( V_48 -> type != V_6 -> type )
return - V_52 ;
F_13 ( & V_6 -> V_55 ) ;
* V_48 = V_58 -> V_48 ;
F_15 ( & V_6 -> V_55 ) ;
return 0 ;
}
static int
F_65 ( struct V_111 * V_111 , void * V_112 , struct V_47 * V_48 )
{
struct V_57 * V_58 = F_64 ( V_112 ) ;
struct V_5 * V_6 = F_61 ( V_111 ) ;
struct V_7 V_50 ;
if ( V_48 -> type != V_6 -> type )
return - V_52 ;
switch ( V_48 -> V_50 . V_10 . V_23 ) {
case V_106 :
break;
case V_126 :
if ( V_6 -> type == V_127 )
V_48 -> V_50 . V_10 . V_23 = V_106 ;
break;
case V_128 :
V_48 -> V_50 . V_10 . V_23 = V_129 ;
case V_129 :
case V_130 :
if ( V_6 != & V_6 -> V_75 -> V_131 . V_132 )
V_48 -> V_50 . V_10 . V_23 = V_106 ;
break;
case V_133 :
case V_134 :
case V_135 :
case V_136 :
default:
V_48 -> V_50 . V_10 . V_23 = V_106 ;
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
F_66 ( struct V_111 * V_111 , void * V_112 , struct V_47 * V_48 )
{
struct V_5 * V_6 = F_61 ( V_111 ) ;
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
return V_39 == - V_137 ? - V_138 : V_39 ;
F_3 ( V_6 , & V_50 . V_48 , & V_48 -> V_50 . V_10 ) ;
return 0 ;
}
static int
F_67 ( struct V_111 * V_111 , void * V_112 , struct V_139 * V_140 )
{
struct V_5 * V_6 = F_61 ( V_111 ) ;
struct V_49 V_48 ;
struct V_24 * V_51 ;
struct V_141 V_142 = {
. V_53 = V_54 ,
. V_143 = V_140 -> V_143 ,
} ;
T_1 V_25 ;
int V_39 ;
switch ( V_140 -> V_143 ) {
case V_144 :
case V_145 :
case V_146 :
if ( V_6 -> type == V_127 )
return - V_52 ;
break;
case V_147 :
case V_148 :
case V_149 :
if ( V_6 -> type == V_43 )
return - V_52 ;
break;
default:
return - V_52 ;
}
V_51 = F_8 ( V_6 , & V_25 ) ;
if ( V_51 == NULL )
return - V_52 ;
V_142 . V_25 = V_25 ;
V_39 = F_24 ( V_51 , V_25 , V_150 , NULL , & V_142 ) ;
if ( ! V_39 )
V_140 -> V_151 = V_142 . V_151 ;
if ( V_39 != - V_137 )
return V_39 ;
V_48 . V_25 = V_25 ;
V_48 . V_53 = V_54 ;
V_39 = F_24 ( V_51 , V_25 , V_56 , NULL , & V_48 ) ;
if ( V_39 < 0 )
return V_39 == - V_137 ? - V_138 : V_39 ;
V_140 -> V_151 . V_152 = 0 ;
V_140 -> V_151 . V_153 = 0 ;
V_140 -> V_151 . V_14 = V_48 . V_48 . V_14 ;
V_140 -> V_151 . V_15 = V_48 . V_48 . V_15 ;
return 0 ;
}
static int
F_68 ( struct V_111 * V_111 , void * V_112 , struct V_139 * V_140 )
{
struct V_5 * V_6 = F_61 ( V_111 ) ;
struct V_24 * V_51 ;
struct V_141 V_142 = {
. V_53 = V_54 ,
. V_143 = V_140 -> V_143 ,
. V_82 = V_140 -> V_82 ,
. V_151 = V_140 -> V_151 ,
} ;
T_1 V_25 ;
int V_39 ;
switch ( V_140 -> V_143 ) {
case V_144 :
if ( V_6 -> type == V_127 )
return - V_52 ;
break;
case V_147 :
if ( V_6 -> type == V_43 )
return - V_52 ;
break;
default:
return - V_52 ;
}
V_51 = F_8 ( V_6 , & V_25 ) ;
if ( V_51 == NULL )
return - V_52 ;
V_142 . V_25 = V_25 ;
F_13 ( & V_6 -> V_55 ) ;
V_39 = F_24 ( V_51 , V_25 , V_154 , NULL , & V_142 ) ;
F_15 ( & V_6 -> V_55 ) ;
if ( ! V_39 )
V_140 -> V_151 = V_142 . V_151 ;
return V_39 == - V_137 ? - V_138 : V_39 ;
}
static int
F_69 ( struct V_111 * V_111 , void * V_112 , struct V_155 * V_156 )
{
struct V_57 * V_58 = F_64 ( V_112 ) ;
struct V_5 * V_6 = F_61 ( V_111 ) ;
if ( V_6 -> type != V_127 ||
V_6 -> type != V_156 -> type )
return - V_52 ;
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
V_156 -> type = V_127 ;
V_156 -> V_157 . V_45 . V_158 = V_159 ;
V_156 -> V_157 . V_45 . V_160 = V_58 -> V_160 ;
return 0 ;
}
static int
F_70 ( struct V_111 * V_111 , void * V_112 , struct V_155 * V_156 )
{
struct V_57 * V_58 = F_64 ( V_112 ) ;
struct V_5 * V_6 = F_61 ( V_111 ) ;
if ( V_6 -> type != V_127 ||
V_6 -> type != V_156 -> type )
return - V_52 ;
if ( V_156 -> V_157 . V_45 . V_160 . V_161 == 0 )
V_156 -> V_157 . V_45 . V_160 . V_161 = 1 ;
V_58 -> V_160 = V_156 -> V_157 . V_45 . V_160 ;
return 0 ;
}
static int
F_71 ( struct V_111 * V_111 , void * V_112 , struct V_162 * V_163 )
{
struct V_57 * V_58 = F_64 ( V_112 ) ;
struct V_5 * V_6 = F_61 ( V_111 ) ;
int V_39 ;
F_13 ( & V_6 -> V_110 ) ;
V_39 = F_72 ( & V_58 -> V_60 , V_163 ) ;
F_15 ( & V_6 -> V_110 ) ;
return V_39 ;
}
static int
F_73 ( struct V_111 * V_111 , void * V_112 , struct V_164 * V_165 )
{
struct V_57 * V_58 = F_64 ( V_112 ) ;
struct V_5 * V_6 = F_61 ( V_111 ) ;
int V_39 ;
F_13 ( & V_6 -> V_110 ) ;
V_39 = F_74 ( & V_58 -> V_60 , V_165 ) ;
F_15 ( & V_6 -> V_110 ) ;
return V_39 ;
}
static int
F_75 ( struct V_111 * V_111 , void * V_112 , struct V_164 * V_165 )
{
struct V_57 * V_58 = F_64 ( V_112 ) ;
struct V_5 * V_6 = F_61 ( V_111 ) ;
int V_39 ;
F_13 ( & V_6 -> V_110 ) ;
V_39 = F_76 ( & V_58 -> V_60 , V_165 ) ;
F_15 ( & V_6 -> V_110 ) ;
return V_39 ;
}
static int
F_77 ( struct V_111 * V_111 , void * V_112 , struct V_164 * V_165 )
{
struct V_57 * V_58 = F_64 ( V_112 ) ;
struct V_5 * V_6 = F_61 ( V_111 ) ;
int V_39 ;
F_13 ( & V_6 -> V_110 ) ;
V_39 = F_78 ( & V_58 -> V_60 , V_165 , V_111 -> V_166 & V_167 ) ;
F_15 ( & V_6 -> V_110 ) ;
return V_39 ;
}
static int F_79 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
struct V_168 * V_75 = V_6 -> V_75 ;
struct V_34 * V_169 [] = {
& V_75 -> V_170 . V_51 . V_28 ,
& V_75 -> V_171 . V_51 . V_28 ,
& V_75 -> V_172 . V_51 . V_28 ,
& V_75 -> V_131 . V_51 . V_28
} ;
struct V_26 * V_173 ;
struct V_34 * V_174 = NULL ;
struct V_34 * V_175 ;
struct V_49 V_50 ;
struct V_176 V_177 ;
struct V_178 V_179 ;
unsigned int V_3 ;
int V_39 ;
if ( V_31 -> V_44 != NULL )
return 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_169 ) ; V_3 ++ ) {
if ( ! F_80 ( & V_31 -> V_42 , V_169 [ V_3 ] ) )
continue;
V_173 = F_9 ( & V_169 [ V_3 ] -> V_180 [ 0 ] ) ;
if ( V_173 == NULL )
continue;
V_174 = V_173 -> V_28 ;
V_175 = V_169 [ V_3 ] ;
break;
}
if ( ! V_174 ) {
F_81 ( V_75 -> V_76 , L_3 ) ;
return - V_52 ;
}
if ( ! F_10 ( V_174 ) )
return 0 ;
V_31 -> V_181 = F_11 ( V_174 ) ;
V_50 . V_25 = V_173 -> V_29 ;
V_50 . V_53 = V_54 ;
V_39 = F_24 ( F_11 ( V_175 ) ,
V_25 , V_56 , NULL , & V_50 ) ;
if ( F_33 ( V_39 < 0 ) ) {
F_81 ( V_75 -> V_76 , L_4 ) ;
return V_39 ;
}
V_31 -> V_182 =
F_1 ( V_50 . V_48 . V_2 ) -> V_14 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_179 . V_183 = V_184 ;
V_177 . V_61 = 1 ;
V_177 . V_185 = & V_179 ;
V_39 = F_82 ( V_31 -> V_181 -> V_186 , & V_177 ) ;
if ( V_39 < 0 ) {
F_81 ( V_75 -> V_76 , L_5 ,
V_31 -> V_181 -> V_118 ) ;
return V_39 ;
}
V_31 -> V_187 = V_179 . V_188 ;
if ( F_80 ( & V_31 -> V_42 ,
& V_75 -> V_131 . V_51 . V_28 ) ) {
unsigned int V_189 = V_190 ;
F_83 ( & V_75 -> V_131 , & V_189 ) ;
if ( V_31 -> V_187 > V_189 )
return - V_191 ;
}
return 0 ;
}
static int
F_84 ( struct V_111 * V_111 , void * V_112 , enum V_192 type )
{
struct V_57 * V_58 = F_64 ( V_112 ) ;
struct V_5 * V_6 = F_61 ( V_111 ) ;
enum V_80 V_81 ;
struct V_30 * V_31 ;
unsigned long V_82 ;
int V_39 ;
if ( type != V_6 -> type )
return - V_52 ;
F_13 ( & V_6 -> V_193 ) ;
V_31 = V_6 -> V_6 . V_28 . V_31
? F_39 ( & V_6 -> V_6 . V_28 ) : & V_6 -> V_31 ;
V_39 = F_85 ( & V_31 -> V_42 , & V_6 -> V_75 -> V_194 ) ;
if ( V_39 )
goto V_195;
V_31 -> V_196 = F_86 ( V_6 -> V_75 -> clock [ V_197 ] ) ;
V_31 -> V_198 = V_31 -> V_196 ;
V_39 = F_87 ( & V_6 -> V_6 . V_28 , & V_31 -> V_31 ) ;
if ( V_39 < 0 )
goto V_199;
V_39 = F_25 ( V_6 , V_58 ) ;
if ( V_39 < 0 )
goto V_200;
V_6 -> V_201 = V_39 ;
V_6 -> V_202 = V_58 -> V_48 . V_50 . V_10 . V_12 ;
V_39 = F_12 ( V_6 , V_31 ) ;
if ( V_39 < 0 )
goto V_200;
if ( V_6 -> type == V_43 )
V_81 = V_203 | V_204 ;
else
V_81 = V_205 | V_206 ;
V_39 = F_79 ( V_6 , V_31 ) ;
if ( V_39 < 0 )
goto V_200;
V_31 -> error = false ;
F_40 ( & V_31 -> V_91 , V_82 ) ;
V_31 -> V_81 &= ~ V_95 ;
V_31 -> V_81 |= V_81 ;
F_42 ( & V_31 -> V_91 , V_82 ) ;
if ( V_6 -> type == V_127 )
V_31 -> V_207 = V_58 -> V_160 ;
V_6 -> V_60 = & V_58 -> V_60 ;
F_88 ( & V_6 -> V_87 ) ;
F_89 ( & V_31 -> V_105 , - 1 ) ;
V_31 -> V_23 = V_58 -> V_48 . V_50 . V_10 . V_23 ;
F_13 ( & V_6 -> V_110 ) ;
V_39 = F_90 ( & V_58 -> V_60 , type ) ;
F_15 ( & V_6 -> V_110 ) ;
if ( V_39 < 0 )
goto V_200;
F_15 ( & V_6 -> V_193 ) ;
return 0 ;
V_200:
F_91 ( & V_6 -> V_6 . V_28 ) ;
V_199:
F_88 ( & V_6 -> V_87 ) ;
V_6 -> V_60 = NULL ;
F_92 ( & V_31 -> V_42 ) ;
V_195:
F_15 ( & V_6 -> V_193 ) ;
return V_39 ;
}
static int
F_93 ( struct V_111 * V_111 , void * V_112 , enum V_192 type )
{
struct V_57 * V_58 = F_64 ( V_112 ) ;
struct V_5 * V_6 = F_61 ( V_111 ) ;
struct V_30 * V_31 = F_39 ( & V_6 -> V_6 . V_28 ) ;
enum V_80 V_81 ;
unsigned int V_208 ;
unsigned long V_82 ;
if ( type != V_6 -> type )
return - V_52 ;
F_13 ( & V_6 -> V_193 ) ;
F_13 ( & V_6 -> V_110 ) ;
V_208 = F_94 ( & V_58 -> V_60 ) ;
F_15 ( & V_6 -> V_110 ) ;
if ( ! V_208 )
goto V_209;
if ( V_6 -> type == V_43 )
V_81 = V_203
| V_89 ;
else
V_81 = V_205
| V_90 ;
F_40 ( & V_31 -> V_91 , V_82 ) ;
V_31 -> V_81 &= ~ V_81 ;
F_42 ( & V_31 -> V_91 , V_82 ) ;
F_46 ( V_31 , V_210 ) ;
F_57 ( V_6 ) ;
F_13 ( & V_6 -> V_110 ) ;
F_95 ( & V_58 -> V_60 , type ) ;
F_15 ( & V_6 -> V_110 ) ;
V_6 -> V_60 = NULL ;
V_6 -> error = false ;
F_91 ( & V_6 -> V_6 . V_28 ) ;
F_92 ( & V_31 -> V_42 ) ;
V_209:
F_15 ( & V_6 -> V_193 ) ;
return 0 ;
}
static int
F_96 ( struct V_111 * V_111 , void * V_112 , struct V_211 * V_44 )
{
if ( V_44 -> V_29 > 0 )
return - V_52 ;
F_62 ( V_44 -> V_118 , L_6 , sizeof( V_44 -> V_118 ) ) ;
V_44 -> type = V_212 ;
return 0 ;
}
static int
F_97 ( struct V_111 * V_111 , void * V_112 , unsigned int * V_44 )
{
* V_44 = 0 ;
return 0 ;
}
static int
F_98 ( struct V_111 * V_111 , void * V_112 , unsigned int V_44 )
{
return V_44 == 0 ? 0 : - V_52 ;
}
static int F_99 ( struct V_111 * V_111 )
{
struct V_5 * V_6 = F_61 ( V_111 ) ;
struct V_57 * V_213 ;
struct V_59 * V_60 ;
int V_39 = 0 ;
V_213 = F_100 ( sizeof( * V_213 ) , V_214 ) ;
if ( V_213 == NULL )
return - V_215 ;
F_101 ( & V_213 -> V_58 , & V_6 -> V_6 ) ;
F_102 ( & V_213 -> V_58 ) ;
if ( F_103 ( V_6 -> V_75 ) == NULL ) {
V_39 = - V_216 ;
goto V_209;
}
V_39 = F_104 ( & V_6 -> V_6 . V_28 , 1 ) ;
if ( V_39 < 0 ) {
F_105 ( V_6 -> V_75 ) ;
goto V_209;
}
V_60 = & V_213 -> V_60 ;
V_60 -> type = V_6 -> type ;
V_60 -> V_217 = V_218 | V_219 ;
V_60 -> V_220 = V_213 ;
V_60 -> V_92 = & V_221 ;
V_60 -> V_222 = & V_223 ;
V_60 -> V_224 = sizeof( struct V_71 ) ;
V_60 -> V_225 = V_226 ;
V_60 -> V_76 = V_6 -> V_75 -> V_76 ;
V_39 = F_106 ( & V_213 -> V_60 ) ;
if ( V_39 < 0 ) {
F_105 ( V_6 -> V_75 ) ;
goto V_209;
}
memset ( & V_213 -> V_48 , 0 , sizeof( V_213 -> V_48 ) ) ;
V_213 -> V_48 . type = V_6 -> type ;
V_213 -> V_160 . V_161 = 1 ;
V_213 -> V_6 = V_6 ;
V_111 -> V_227 = & V_213 -> V_58 ;
V_209:
if ( V_39 < 0 ) {
F_107 ( & V_213 -> V_58 ) ;
F_108 ( & V_213 -> V_58 ) ;
F_109 ( V_213 ) ;
}
return V_39 ;
}
static int F_110 ( struct V_111 * V_111 )
{
struct V_5 * V_6 = F_61 ( V_111 ) ;
struct V_228 * V_58 = V_111 -> V_227 ;
struct V_57 * V_213 = F_64 ( V_58 ) ;
F_93 ( V_111 , V_58 , V_6 -> type ) ;
F_13 ( & V_6 -> V_110 ) ;
F_111 ( & V_213 -> V_60 ) ;
F_15 ( & V_6 -> V_110 ) ;
F_104 ( & V_6 -> V_6 . V_28 , 0 ) ;
F_107 ( V_58 ) ;
F_108 ( V_58 ) ;
F_109 ( V_213 ) ;
V_111 -> V_227 = NULL ;
F_105 ( V_6 -> V_75 ) ;
return 0 ;
}
static unsigned int F_112 ( struct V_111 * V_111 , T_3 * V_229 )
{
struct V_57 * V_58 = F_64 ( V_111 -> V_227 ) ;
struct V_5 * V_6 = F_61 ( V_111 ) ;
int V_39 ;
F_13 ( & V_6 -> V_110 ) ;
V_39 = F_113 ( & V_58 -> V_60 , V_111 , V_229 ) ;
F_15 ( & V_6 -> V_110 ) ;
return V_39 ;
}
static int F_114 ( struct V_111 * V_111 , struct V_230 * V_231 )
{
struct V_57 * V_58 = F_64 ( V_111 -> V_227 ) ;
return F_115 ( & V_58 -> V_60 , V_231 ) ;
}
int F_116 ( struct V_5 * V_6 , const char * V_118 )
{
const char * V_232 ;
int V_39 ;
switch ( V_6 -> type ) {
case V_43 :
V_232 = L_7 ;
V_6 -> V_25 . V_82 = V_233
| V_234 ;
break;
case V_127 :
V_232 = L_8 ;
V_6 -> V_25 . V_82 = V_235
| V_234 ;
V_6 -> V_6 . V_236 = V_237 ;
break;
default:
return - V_52 ;
}
V_39 = F_117 ( & V_6 -> V_6 . V_28 , 1 , & V_6 -> V_25 ) ;
if ( V_39 < 0 )
return V_39 ;
F_118 ( & V_6 -> V_55 ) ;
F_89 ( & V_6 -> V_238 , 0 ) ;
F_119 ( & V_6 -> V_31 . V_91 ) ;
F_118 ( & V_6 -> V_193 ) ;
F_118 ( & V_6 -> V_110 ) ;
F_119 ( & V_6 -> V_85 ) ;
if ( V_6 -> V_92 == NULL )
V_6 -> V_92 = & V_239 ;
V_6 -> V_6 . V_240 = & V_241 ;
snprintf ( V_6 -> V_6 . V_118 , sizeof( V_6 -> V_6 . V_118 ) ,
L_9 , V_118 , V_232 ) ;
V_6 -> V_6 . V_242 = V_243 ;
V_6 -> V_6 . V_244 = V_245 ;
V_6 -> V_6 . V_246 = & V_247 ;
V_6 -> V_31 . V_108 = V_210 ;
F_120 ( & V_6 -> V_6 , V_6 ) ;
return 0 ;
}
void F_121 ( struct V_5 * V_6 )
{
F_122 ( & V_6 -> V_6 . V_28 ) ;
F_123 ( & V_6 -> V_110 ) ;
F_123 ( & V_6 -> V_193 ) ;
F_123 ( & V_6 -> V_55 ) ;
}
int F_124 ( struct V_5 * V_6 , struct V_248 * V_249 )
{
int V_39 ;
V_6 -> V_6 . V_250 = V_249 ;
V_39 = F_125 ( & V_6 -> V_6 , V_243 , - 1 ) ;
if ( V_39 < 0 )
F_126 ( V_6 -> V_75 -> V_76 ,
L_10 ,
V_251 , V_39 ) ;
return V_39 ;
}
void F_127 ( struct V_5 * V_6 )
{
if ( F_128 ( & V_6 -> V_6 ) )
F_129 ( & V_6 -> V_6 ) ;
}
