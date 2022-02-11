const struct V_1 *
F_1 ( T_1 V_2 )
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
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) - 1 ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_2 == V_8 -> V_2 )
break;
}
V_13 = V_10 -> V_14 * F_4 ( V_4 [ V_3 ] . V_16 , 8 ) / 8 ;
if ( V_6 -> V_17 )
V_11 = F_5 ( V_11 , V_13 , V_6 -> V_17 ) ;
else
V_11 = V_13 ;
if ( ! V_6 -> V_18 || V_11 != V_13 )
V_11 = F_4 ( V_11 , V_6 -> V_19 ) ;
V_10 -> V_20 = V_4 [ V_3 ] . V_20 ;
V_10 -> V_12 = V_11 ;
V_10 -> V_21 = V_10 -> V_12 * V_10 -> V_15 ;
V_10 -> V_22 = V_8 -> V_22 ;
V_10 -> V_23 = V_8 -> V_23 ;
if ( V_10 -> V_20 == V_24 )
V_10 -> V_21 += ( V_10 -> V_12 * V_10 -> V_15 ) / 2 ;
return V_11 - V_13 ;
}
static void F_6 ( const struct V_9 * V_10 ,
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
static struct V_25 *
F_7 ( struct V_5 * V_6 , T_1 * V_26 )
{
struct V_27 * V_28 ;
V_28 = F_8 ( & V_6 -> V_26 ) ;
if ( ! V_28 || ! F_9 ( V_28 -> V_29 ) )
return NULL ;
if ( V_26 )
* V_26 = V_28 -> V_30 ;
return F_10 ( V_28 -> V_29 ) ;
}
static struct V_5 *
F_11 ( struct V_5 * V_6 )
{
struct V_31 V_32 ;
struct V_33 * V_29 = & V_6 -> V_6 . V_29 ;
struct V_34 * V_35 = V_29 -> V_36 . V_35 ;
struct V_5 * V_37 = NULL ;
F_12 ( & V_35 -> V_38 ) ;
if ( F_13 ( & V_32 , V_35 ) ) {
F_14 ( & V_35 -> V_38 ) ;
return NULL ;
}
F_15 ( & V_32 , V_29 ) ;
while ( ( V_29 = F_16 ( & V_32 ) ) ) {
if ( V_29 == & V_6 -> V_6 . V_29 )
continue;
if ( ! F_17 ( V_29 ) )
continue;
V_37 = F_18 ( F_19 ( V_29 ) ) ;
if ( V_37 -> type != V_6 -> type )
break;
V_37 = NULL ;
}
F_14 ( & V_35 -> V_38 ) ;
F_20 ( & V_32 ) ;
return V_37 ;
}
static int
F_21 ( struct V_5 * V_6 ,
struct V_7 * V_39 )
{
struct V_40 V_41 ;
struct V_25 * V_42 ;
T_1 V_26 ;
int V_43 ;
V_42 = F_7 ( V_6 , & V_26 ) ;
if ( ! V_42 )
return - V_44 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_26 = V_26 ;
V_41 . V_45 = V_46 ;
F_12 ( & V_6 -> V_47 ) ;
V_43 = F_22 ( V_42 , V_26 , V_48 , NULL , & V_41 ) ;
F_14 ( & V_6 -> V_47 ) ;
if ( V_43 )
return V_43 ;
* V_39 = V_41 . V_39 ;
return 0 ;
}
static int
F_23 ( struct V_5 * V_6 , struct V_49 * V_50 )
{
struct V_7 V_39 ;
struct V_9 V_51 ;
int V_43 ;
V_43 = F_21 ( V_6 , & V_39 ) ;
if ( V_43 < 0 )
return V_43 ;
V_51 . V_12 = 0 ;
V_43 = F_3 ( V_6 , & V_39 , & V_51 ) ;
if ( V_50 -> V_39 . V_41 . V_10 . V_20 != V_51 . V_20 ||
V_50 -> V_39 . V_41 . V_10 . V_15 != V_51 . V_15 ||
V_50 -> V_39 . V_41 . V_10 . V_14 != V_51 . V_14 ||
V_50 -> V_39 . V_41 . V_10 . V_12 != V_51 . V_12 ||
V_50 -> V_39 . V_41 . V_10 . V_21 != V_51 . V_21 )
return - V_44 ;
return V_43 ;
}
static int F_24 ( struct V_52 * V_53 ,
unsigned int * V_54 , unsigned int * V_55 ,
unsigned int V_56 [] ,
struct V_57 * V_58 [] )
{
struct V_49 * V_50 = F_25 ( V_53 ) ;
struct V_5 * V_6 = V_50 -> V_6 ;
* V_55 = 1 ;
V_56 [ 0 ] = V_50 -> V_39 . V_41 . V_10 . V_21 ;
if ( V_56 [ 0 ] == 0 )
return - V_44 ;
* V_54 = F_26 ( * V_54 , V_6 -> V_59 / F_27 ( V_56 [ 0 ] ) ) ;
return 0 ;
}
static void F_28 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = F_29 ( V_61 ) ;
struct V_64 * V_65 = F_30 ( V_63 , struct V_64 , V_61 ) ;
if ( V_65 -> V_66 )
V_65 -> V_66 = 0 ;
}
static int F_31 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = F_29 ( V_61 ) ;
struct V_49 * V_50 = F_25 ( V_61 -> V_52 ) ;
struct V_64 * V_65 = F_30 ( V_63 , struct V_64 , V_61 ) ;
struct V_5 * V_6 = V_50 -> V_6 ;
unsigned long V_67 = V_50 -> V_39 . V_41 . V_10 . V_21 ;
T_2 V_68 ;
if ( F_32 ( V_61 , 0 ) < V_67 )
return - V_69 ;
V_68 = F_33 ( V_61 , 0 ) ;
if ( ! F_34 ( V_68 , 32 ) ) {
F_35 ( V_6 -> V_70 -> V_71 ,
L_1 ) ;
return - V_44 ;
}
F_36 ( V_61 , 0 , V_67 ) ;
V_65 -> V_66 = V_68 ;
return 0 ;
}
static void F_37 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = F_29 ( V_61 ) ;
struct V_49 * V_50 = F_25 ( V_61 -> V_52 ) ;
struct V_5 * V_6 = V_50 -> V_6 ;
struct V_64 * V_65 = F_30 ( V_63 , struct V_64 , V_61 ) ;
struct V_72 * V_73 = F_38 ( & V_6 -> V_6 . V_29 ) ;
unsigned long V_74 ;
bool V_75 ;
F_39 ( & V_6 -> V_76 , V_74 ) ;
if ( F_40 ( V_6 -> error ) ) {
F_41 ( V_61 , V_77 ) ;
F_42 ( & V_6 -> V_76 , V_74 ) ;
return;
}
V_75 = F_43 ( & V_6 -> V_78 ) ;
F_44 ( & V_65 -> V_79 , & V_6 -> V_78 ) ;
F_42 ( & V_6 -> V_76 , V_74 ) ;
if ( V_75 ) {
enum V_80 V_81 ;
unsigned int V_82 ;
if ( V_6 -> type == V_83 )
V_81 = V_84 ;
else
V_81 = V_85 ;
F_39 ( & V_73 -> V_86 , V_74 ) ;
V_73 -> V_81 |= V_81 ;
V_6 -> V_87 -> V_88 ( V_6 , V_65 ) ;
V_6 -> V_89 |= V_90 ;
V_82 = F_45 ( V_73 ) ;
if ( V_82 )
V_73 -> V_81 |= V_91 ;
F_42 ( & V_73 -> V_86 , V_74 ) ;
if ( V_82 )
F_46 ( V_73 ,
V_92 ) ;
}
}
struct V_64 * F_47 ( struct V_5 * V_6 )
{
struct V_72 * V_73 = F_38 ( & V_6 -> V_6 . V_29 ) ;
enum V_80 V_81 ;
struct V_64 * V_93 ;
unsigned long V_74 ;
F_39 ( & V_6 -> V_76 , V_74 ) ;
if ( F_48 ( F_43 ( & V_6 -> V_78 ) ) ) {
F_42 ( & V_6 -> V_76 , V_74 ) ;
return NULL ;
}
V_93 = F_49 ( & V_6 -> V_78 , struct V_64 ,
V_79 ) ;
F_50 ( & V_93 -> V_79 ) ;
F_42 ( & V_6 -> V_76 , V_74 ) ;
V_93 -> V_61 . V_94 . V_95 = F_51 () ;
if ( V_6 == V_73 -> V_96 && ! V_73 -> V_97 )
V_93 -> V_61 . V_98 =
F_52 ( & V_73 -> V_99 ) ;
else
V_93 -> V_61 . V_98 = F_53 ( & V_73 -> V_99 ) ;
F_41 ( & V_93 -> V_61 . V_94 , V_73 -> error ?
V_77 : V_100 ) ;
V_73 -> error = false ;
F_39 ( & V_6 -> V_76 , V_74 ) ;
if ( F_43 ( & V_6 -> V_78 ) ) {
F_42 ( & V_6 -> V_76 , V_74 ) ;
if ( V_6 -> type == V_83 )
V_81 = V_84
| V_91 ;
else
V_81 = V_85
| V_91 ;
F_39 ( & V_73 -> V_86 , V_74 ) ;
V_73 -> V_81 &= ~ V_81 ;
if ( V_6 -> V_73 . V_101 == V_102 )
V_6 -> V_89 |= V_103 ;
F_42 ( & V_73 -> V_86 , V_74 ) ;
return NULL ;
}
if ( V_6 -> type == V_83 && V_73 -> V_104 ) {
F_54 ( & V_73 -> V_86 ) ;
V_73 -> V_81 &= ~ V_91 ;
F_55 ( & V_73 -> V_86 ) ;
}
V_93 = F_49 ( & V_6 -> V_78 , struct V_64 ,
V_79 ) ;
F_42 ( & V_6 -> V_76 , V_74 ) ;
V_93 -> V_61 . V_94 . V_81 = V_105 ;
return V_93 ;
}
void F_56 ( struct V_5 * V_6 )
{
unsigned long V_74 ;
F_39 ( & V_6 -> V_76 , V_74 ) ;
while ( ! F_43 ( & V_6 -> V_78 ) ) {
struct V_64 * V_93 ;
V_93 = F_49 ( & V_6 -> V_78 , struct V_64 ,
V_79 ) ;
F_50 ( & V_93 -> V_79 ) ;
F_41 ( & V_93 -> V_61 . V_94 , V_77 ) ;
}
F_57 ( V_6 -> V_88 ) ;
V_6 -> error = true ;
F_42 ( & V_6 -> V_76 , V_74 ) ;
}
static int
F_58 ( struct V_106 * V_106 , void * V_107 , struct V_108 * V_109 )
{
struct V_5 * V_6 = F_59 ( V_106 ) ;
F_60 ( V_109 -> V_110 , V_111 , sizeof( V_109 -> V_110 ) ) ;
F_60 ( V_109 -> V_112 , V_6 -> V_6 . V_113 , sizeof( V_109 -> V_112 ) ) ;
F_60 ( V_109 -> V_114 , L_2 , sizeof( V_109 -> V_114 ) ) ;
if ( V_6 -> type == V_83 )
V_109 -> V_115 = V_116 | V_117 ;
else
V_109 -> V_115 = V_118 | V_117 ;
V_109 -> V_119 = V_120 | V_117
| V_116 | V_118 ;
return 0 ;
}
static int
F_61 ( struct V_106 * V_106 , void * V_107 , struct V_121 * V_122 )
{
struct V_5 * V_6 = F_59 ( V_106 ) ;
struct V_7 V_39 ;
unsigned int V_30 = V_122 -> V_30 ;
unsigned int V_3 ;
int V_43 ;
if ( V_122 -> type != V_6 -> type )
return - V_44 ;
V_43 = F_21 ( V_6 , & V_39 ) ;
if ( V_43 < 0 )
return V_43 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
const struct V_1 * V_123 = & V_4 [ V_3 ] ;
if ( V_39 . V_2 != V_123 -> V_2 )
continue;
if ( V_30 == 0 ) {
V_122 -> V_20 = V_123 -> V_20 ;
F_60 ( V_122 -> V_124 , V_123 -> V_124 ,
sizeof( V_122 -> V_124 ) ) ;
return 0 ;
}
V_30 -- ;
}
return - V_44 ;
}
static int
F_62 ( struct V_106 * V_106 , void * V_107 , struct V_125 * V_39 )
{
struct V_49 * V_50 = F_63 ( V_107 ) ;
struct V_5 * V_6 = F_59 ( V_106 ) ;
if ( V_39 -> type != V_6 -> type )
return - V_44 ;
F_12 ( & V_6 -> V_47 ) ;
* V_39 = V_50 -> V_39 ;
F_14 ( & V_6 -> V_47 ) ;
return 0 ;
}
static int
F_64 ( struct V_106 * V_106 , void * V_107 , struct V_125 * V_39 )
{
struct V_49 * V_50 = F_63 ( V_107 ) ;
struct V_5 * V_6 = F_59 ( V_106 ) ;
struct V_7 V_41 ;
if ( V_39 -> type != V_6 -> type )
return - V_44 ;
F_12 ( & V_6 -> V_47 ) ;
F_6 ( & V_39 -> V_41 . V_10 , & V_41 ) ;
F_3 ( V_6 , & V_41 , & V_39 -> V_41 . V_10 ) ;
V_50 -> V_39 = * V_39 ;
F_14 ( & V_6 -> V_47 ) ;
return 0 ;
}
static int
F_65 ( struct V_106 * V_106 , void * V_107 , struct V_125 * V_39 )
{
struct V_5 * V_6 = F_59 ( V_106 ) ;
struct V_40 V_41 ;
struct V_25 * V_42 ;
T_1 V_26 ;
int V_43 ;
if ( V_39 -> type != V_6 -> type )
return - V_44 ;
V_42 = F_7 ( V_6 , & V_26 ) ;
if ( ! V_42 )
return - V_44 ;
F_6 ( & V_39 -> V_41 . V_10 , & V_41 . V_39 ) ;
V_41 . V_26 = V_26 ;
V_41 . V_45 = V_46 ;
V_43 = F_22 ( V_42 , V_26 , V_48 , NULL , & V_41 ) ;
if ( V_43 )
return V_43 ;
F_3 ( V_6 , & V_41 . V_39 , & V_39 -> V_41 . V_10 ) ;
return 0 ;
}
static int
F_66 ( struct V_106 * V_106 , void * V_107 , struct V_126 * V_127 )
{
struct V_5 * V_6 = F_59 ( V_106 ) ;
struct V_40 V_39 ;
struct V_25 * V_42 ;
struct V_128 V_129 = {
. V_45 = V_46 ,
. V_130 = V_127 -> V_130 ,
} ;
T_1 V_26 ;
int V_43 ;
switch ( V_127 -> V_130 ) {
case V_131 :
case V_132 :
case V_133 :
if ( V_6 -> type == V_134 )
return - V_44 ;
break;
case V_135 :
case V_136 :
case V_137 :
if ( V_6 -> type == V_83 )
return - V_44 ;
break;
default:
return - V_44 ;
}
V_42 = F_7 ( V_6 , & V_26 ) ;
if ( V_42 == NULL )
return - V_44 ;
V_129 . V_26 = V_26 ;
V_43 = F_22 ( V_42 , V_26 , V_138 , NULL , & V_129 ) ;
if ( ! V_43 )
V_127 -> V_139 = V_129 . V_139 ;
if ( V_43 != - V_140 )
return V_43 ;
V_39 . V_26 = V_26 ;
V_39 . V_45 = V_46 ;
V_43 = F_22 ( V_42 , V_26 , V_48 , NULL , & V_39 ) ;
if ( V_43 < 0 )
return V_43 == - V_140 ? - V_141 : V_43 ;
V_127 -> V_139 . V_142 = 0 ;
V_127 -> V_139 . V_143 = 0 ;
V_127 -> V_139 . V_14 = V_39 . V_39 . V_14 ;
V_127 -> V_139 . V_15 = V_39 . V_39 . V_15 ;
return 0 ;
}
static int
F_67 ( struct V_106 * V_106 , void * V_107 , struct V_126 * V_127 )
{
struct V_5 * V_6 = F_59 ( V_106 ) ;
struct V_25 * V_42 ;
struct V_128 V_129 = {
. V_45 = V_46 ,
. V_130 = V_127 -> V_130 ,
. V_74 = V_127 -> V_74 ,
. V_139 = V_127 -> V_139 ,
} ;
T_1 V_26 ;
int V_43 ;
switch ( V_127 -> V_130 ) {
case V_131 :
if ( V_6 -> type == V_134 )
return - V_44 ;
break;
case V_135 :
if ( V_6 -> type == V_83 )
return - V_44 ;
break;
default:
return - V_44 ;
}
V_42 = F_7 ( V_6 , & V_26 ) ;
if ( V_42 == NULL )
return - V_44 ;
V_129 . V_26 = V_26 ;
F_12 ( & V_6 -> V_47 ) ;
V_43 = F_22 ( V_42 , V_26 , V_144 , NULL , & V_129 ) ;
F_14 ( & V_6 -> V_47 ) ;
if ( ! V_43 )
V_127 -> V_139 = V_129 . V_139 ;
return V_43 == - V_140 ? - V_141 : V_43 ;
}
static int
F_68 ( struct V_106 * V_106 , void * V_107 , struct V_145 * V_146 )
{
struct V_49 * V_50 = F_63 ( V_107 ) ;
struct V_5 * V_6 = F_59 ( V_106 ) ;
if ( V_6 -> type != V_134 ||
V_6 -> type != V_146 -> type )
return - V_44 ;
memset ( V_146 , 0 , sizeof( * V_146 ) ) ;
V_146 -> type = V_134 ;
V_146 -> V_147 . V_96 . V_148 = V_149 ;
V_146 -> V_147 . V_96 . V_150 = V_50 -> V_150 ;
return 0 ;
}
static int
F_69 ( struct V_106 * V_106 , void * V_107 , struct V_145 * V_146 )
{
struct V_49 * V_50 = F_63 ( V_107 ) ;
struct V_5 * V_6 = F_59 ( V_106 ) ;
if ( V_6 -> type != V_134 ||
V_6 -> type != V_146 -> type )
return - V_44 ;
if ( V_146 -> V_147 . V_96 . V_150 . V_151 == 0 )
V_146 -> V_147 . V_96 . V_150 . V_151 = 1 ;
V_50 -> V_150 = V_146 -> V_147 . V_96 . V_150 ;
return 0 ;
}
static int
F_70 ( struct V_106 * V_106 , void * V_107 , struct V_152 * V_153 )
{
struct V_49 * V_50 = F_63 ( V_107 ) ;
return F_71 ( & V_50 -> V_88 , V_153 ) ;
}
static int
F_72 ( struct V_106 * V_106 , void * V_107 , struct V_154 * V_155 )
{
struct V_49 * V_50 = F_63 ( V_107 ) ;
return F_73 ( & V_50 -> V_88 , V_155 ) ;
}
static int
F_74 ( struct V_106 * V_106 , void * V_107 , struct V_154 * V_155 )
{
struct V_49 * V_50 = F_63 ( V_107 ) ;
return F_75 ( & V_50 -> V_88 , V_155 ) ;
}
static int
F_76 ( struct V_106 * V_106 , void * V_107 , struct V_156 * V_157 )
{
struct V_49 * V_50 = F_63 ( V_107 ) ;
return F_77 ( & V_50 -> V_88 , V_157 ) ;
}
static int
F_78 ( struct V_106 * V_106 , void * V_107 , struct V_154 * V_155 )
{
struct V_49 * V_50 = F_63 ( V_107 ) ;
return F_79 ( & V_50 -> V_88 , V_155 , V_106 -> V_158 & V_159 ) ;
}
static int
F_80 ( struct V_106 * V_106 , void * V_107 , enum V_160 type )
{
struct V_49 * V_50 = F_63 ( V_107 ) ;
struct V_5 * V_6 = F_59 ( V_106 ) ;
struct V_31 V_32 ;
struct V_33 * V_29 = & V_6 -> V_6 . V_29 ;
enum V_80 V_81 ;
struct V_72 * V_73 ;
struct V_5 * V_37 ;
unsigned long V_74 ;
int V_43 ;
if ( type != V_6 -> type )
return - V_44 ;
F_12 ( & V_6 -> V_161 ) ;
V_73 = V_29 -> V_73
? F_38 ( V_29 ) : & V_6 -> V_73 ;
V_73 -> V_162 = NULL ;
V_73 -> V_163 = 0 ;
V_73 -> V_164 = 0 ;
V_43 = F_81 ( & V_73 -> V_165 , V_29 -> V_36 . V_35 ) ;
if ( V_43 )
goto V_166;
V_43 = F_13 ( & V_32 , V_29 -> V_36 . V_35 ) ;
if ( V_43 )
goto V_166;
if ( V_6 -> V_70 -> V_167 -> V_168 )
V_6 -> V_70 -> V_167 -> V_168 ( V_6 -> V_70 , true ) ;
V_43 = F_82 ( V_29 , & V_73 -> V_73 ) ;
if ( V_43 < 0 )
goto V_169;
F_15 ( & V_32 , V_29 ) ;
while ( ( V_29 = F_16 ( & V_32 ) ) )
F_83 ( & V_73 -> V_165 , V_29 ) ;
V_43 = F_23 ( V_6 , V_50 ) ;
if ( V_43 < 0 )
goto V_170;
V_6 -> V_171 = V_43 ;
V_6 -> V_172 = V_50 -> V_39 . V_41 . V_10 . V_12 ;
V_37 = F_11 ( V_6 ) ;
if ( V_6 -> type == V_83 ) {
V_81 = V_173 | V_174 ;
V_73 -> V_104 = V_37 ;
V_73 -> V_96 = V_6 ;
} else {
if ( ! V_37 ) {
V_43 = - V_175 ;
goto V_170;
}
V_81 = V_176 | V_177 ;
V_73 -> V_104 = V_6 ;
V_73 -> V_96 = V_37 ;
}
F_39 ( & V_73 -> V_86 , V_74 ) ;
V_73 -> V_81 &= ~ V_91 ;
V_73 -> V_81 |= V_81 ;
F_42 ( & V_73 -> V_86 , V_74 ) ;
if ( V_6 -> type == V_134 )
V_73 -> V_178 = V_50 -> V_150 ;
V_6 -> V_88 = & V_50 -> V_88 ;
F_84 ( & V_6 -> V_78 ) ;
V_6 -> error = false ;
F_85 ( & V_73 -> V_99 , - 1 ) ;
V_43 = F_86 ( & V_50 -> V_88 , type ) ;
if ( V_43 < 0 )
goto V_170;
if ( ! V_73 -> V_104 ) {
unsigned long V_74 ;
V_43 = F_46 ( V_73 ,
V_102 ) ;
if ( V_43 < 0 )
goto V_179;
F_39 ( & V_6 -> V_76 , V_74 ) ;
if ( F_43 ( & V_6 -> V_78 ) )
V_6 -> V_89 |= V_103 ;
F_42 ( & V_6 -> V_76 , V_74 ) ;
}
F_20 ( & V_32 ) ;
F_14 ( & V_6 -> V_161 ) ;
return 0 ;
V_179:
F_87 ( & V_50 -> V_88 , type ) ;
V_170:
F_88 ( & V_6 -> V_6 . V_29 ) ;
V_169:
if ( V_6 -> V_70 -> V_167 -> V_168 )
V_6 -> V_70 -> V_167 -> V_168 ( V_6 -> V_70 , false ) ;
V_6 -> V_88 = NULL ;
F_20 ( & V_32 ) ;
V_166:
F_89 ( & V_73 -> V_165 ) ;
F_14 ( & V_6 -> V_161 ) ;
return V_43 ;
}
static int
F_90 ( struct V_106 * V_106 , void * V_107 , enum V_160 type )
{
struct V_49 * V_50 = F_63 ( V_107 ) ;
struct V_5 * V_6 = F_59 ( V_106 ) ;
struct V_72 * V_73 = F_38 ( & V_6 -> V_6 . V_29 ) ;
enum V_80 V_81 ;
unsigned long V_74 ;
if ( type != V_6 -> type )
return - V_44 ;
F_12 ( & V_6 -> V_161 ) ;
if ( ! F_91 ( & V_50 -> V_88 ) )
goto V_180;
if ( V_6 -> type == V_83 )
V_81 = V_173
| V_84 ;
else
V_81 = V_176
| V_85 ;
F_39 ( & V_73 -> V_86 , V_74 ) ;
V_73 -> V_81 &= ~ V_81 ;
F_42 ( & V_73 -> V_86 , V_74 ) ;
F_46 ( V_73 , V_181 ) ;
F_87 ( & V_50 -> V_88 , type ) ;
V_6 -> V_88 = NULL ;
F_89 ( & V_73 -> V_165 ) ;
if ( V_6 -> V_70 -> V_167 -> V_168 )
V_6 -> V_70 -> V_167 -> V_168 ( V_6 -> V_70 , false ) ;
F_88 ( & V_6 -> V_6 . V_29 ) ;
V_180:
F_14 ( & V_6 -> V_161 ) ;
return 0 ;
}
static int
F_92 ( struct V_106 * V_106 , void * V_107 , struct V_182 * V_104 )
{
if ( V_104 -> V_30 > 0 )
return - V_44 ;
F_60 ( V_104 -> V_113 , L_3 , sizeof( V_104 -> V_113 ) ) ;
V_104 -> type = V_183 ;
return 0 ;
}
static int
F_93 ( struct V_106 * V_106 , void * V_107 , unsigned int * V_104 )
{
* V_104 = 0 ;
return 0 ;
}
static int
F_94 ( struct V_106 * V_106 , void * V_107 , unsigned int V_104 )
{
return V_104 == 0 ? 0 : - V_44 ;
}
static int F_95 ( struct V_106 * V_106 )
{
struct V_5 * V_6 = F_59 ( V_106 ) ;
struct V_49 * V_184 ;
struct V_52 * V_185 ;
int V_43 = 0 ;
V_184 = F_96 ( sizeof( * V_184 ) , V_186 ) ;
if ( ! V_184 )
return - V_187 ;
F_97 ( & V_184 -> V_50 , & V_6 -> V_6 ) ;
F_98 ( & V_184 -> V_50 ) ;
if ( ! F_99 ( V_6 -> V_70 ) ) {
V_43 = - V_188 ;
goto V_180;
}
V_43 = F_100 ( & V_6 -> V_6 . V_29 , 1 ) ;
if ( V_43 < 0 ) {
F_101 ( V_6 -> V_70 ) ;
goto V_180;
}
V_185 = & V_184 -> V_88 ;
V_185 -> type = V_6 -> type ;
V_185 -> V_189 = V_190 | V_191 ;
V_185 -> V_192 = V_184 ;
V_185 -> V_87 = & V_193 ;
V_185 -> V_194 = & V_195 ;
V_185 -> V_196 = sizeof( struct V_64 ) ;
V_185 -> V_197 = V_198 ;
V_185 -> V_71 = V_6 -> V_70 -> V_71 ;
V_43 = F_102 ( V_185 ) ;
if ( V_43 ) {
F_101 ( V_6 -> V_70 ) ;
goto V_180;
}
memset ( & V_184 -> V_39 , 0 , sizeof( V_184 -> V_39 ) ) ;
V_184 -> V_39 . type = V_6 -> type ;
V_184 -> V_150 . V_151 = 1 ;
V_184 -> V_6 = V_6 ;
V_106 -> V_199 = & V_184 -> V_50 ;
V_180:
if ( V_43 < 0 ) {
F_103 ( & V_184 -> V_50 ) ;
F_104 ( & V_184 -> V_50 ) ;
F_105 ( V_184 ) ;
}
return V_43 ;
}
static int F_106 ( struct V_106 * V_106 )
{
struct V_5 * V_6 = F_59 ( V_106 ) ;
struct V_200 * V_50 = V_106 -> V_199 ;
struct V_49 * V_184 = F_63 ( V_50 ) ;
F_90 ( V_106 , V_50 , V_6 -> type ) ;
F_100 ( & V_6 -> V_6 . V_29 , 0 ) ;
F_107 ( & V_184 -> V_88 ) ;
F_103 ( V_50 ) ;
F_104 ( V_50 ) ;
F_105 ( V_184 ) ;
V_106 -> V_199 = NULL ;
F_101 ( V_6 -> V_70 ) ;
return 0 ;
}
static unsigned int F_108 ( struct V_106 * V_106 , T_3 * V_201 )
{
struct V_49 * V_50 = F_63 ( V_106 -> V_199 ) ;
return F_109 ( & V_50 -> V_88 , V_106 , V_201 ) ;
}
static int F_110 ( struct V_106 * V_106 , struct V_202 * V_203 )
{
struct V_49 * V_50 = F_63 ( V_106 -> V_199 ) ;
return F_111 ( & V_50 -> V_88 , V_203 ) ;
}
int F_112 ( struct V_5 * V_6 , const char * V_113 )
{
const char * V_204 ;
int V_43 ;
switch ( V_6 -> type ) {
case V_83 :
V_204 = L_4 ;
V_6 -> V_26 . V_74 = V_205 ;
break;
case V_134 :
V_204 = L_5 ;
V_6 -> V_26 . V_74 = V_206 ;
break;
default:
return - V_44 ;
}
V_43 = F_113 ( & V_6 -> V_6 . V_29 , 1 , & V_6 -> V_26 ) ;
if ( V_43 < 0 )
return V_43 ;
F_114 ( & V_6 -> V_76 ) ;
F_115 ( & V_6 -> V_47 ) ;
F_85 ( & V_6 -> V_207 , 0 ) ;
F_114 ( & V_6 -> V_73 . V_86 ) ;
F_115 ( & V_6 -> V_161 ) ;
if ( ! V_6 -> V_87 )
V_6 -> V_87 = & V_208 ;
V_6 -> V_6 . V_209 = & V_210 ;
snprintf ( V_6 -> V_6 . V_113 , sizeof( V_6 -> V_6 . V_113 ) ,
L_6 , V_113 , V_204 ) ;
V_6 -> V_6 . V_211 = V_212 ;
V_6 -> V_6 . V_213 = V_214 ;
V_6 -> V_6 . V_215 = & V_216 ;
V_6 -> V_73 . V_101 = V_181 ;
F_116 ( & V_6 -> V_6 , V_6 ) ;
return 0 ;
}
void F_117 ( struct V_5 * V_6 )
{
F_118 ( & V_6 -> V_6 . V_29 ) ;
F_119 ( & V_6 -> V_161 ) ;
F_119 ( & V_6 -> V_47 ) ;
}
int F_120 ( struct V_5 * V_6 , struct V_217 * V_218 )
{
int V_43 ;
V_6 -> V_6 . V_219 = V_218 ;
V_43 = F_121 ( & V_6 -> V_6 , V_212 , - 1 ) ;
if ( V_43 < 0 )
F_122 ( V_6 -> V_70 -> V_71 ,
L_7 , V_43 ) ;
return V_43 ;
}
void F_123 ( struct V_5 * V_6 )
{
F_124 ( & V_6 -> V_6 ) ;
}
