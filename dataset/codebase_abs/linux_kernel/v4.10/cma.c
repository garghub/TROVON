const char * T_1 F_1 ( enum V_1 V_2 )
{
T_2 V_3 = V_2 ;
return ( V_3 < F_2 ( V_4 ) && V_4 [ V_3 ] ) ?
V_4 [ V_3 ] : L_1 ;
}
const char * T_1 F_3 ( struct V_5 * V_6 ,
int V_7 )
{
if ( F_4 ( V_6 -> V_8 , V_6 -> V_9 ) )
return F_5 ( V_7 ) ;
if ( F_6 ( V_6 -> V_8 , V_6 -> V_9 ) )
return F_7 ( V_7 ) ;
F_8 ( 1 ) ;
return L_2 ;
}
bool F_9 ( struct V_5 * V_6 , int V_7 )
{
if ( F_4 ( V_6 -> V_8 , V_6 -> V_9 ) )
return V_7 == V_10 ;
if ( F_6 ( V_6 -> V_8 , V_6 -> V_9 ) )
return V_7 == - V_11 ;
F_8 ( 1 ) ;
return false ;
}
const void * F_10 ( struct V_5 * V_6 ,
struct V_12 * V_13 , T_3 * V_14 )
{
const void * V_15 ;
if ( F_9 ( V_6 , V_13 -> V_16 ) ) {
* V_14 = V_13 -> V_17 . V_18 . V_19 ;
V_15 = V_13 -> V_17 . V_18 . V_20 ;
} else {
* V_14 = 0 ;
V_15 = NULL ;
}
return V_15 ;
}
static struct V_21 * V_21 ( struct V_22 * V_22 )
{
return F_11 ( V_22 , V_23 ) ;
}
static struct V_24 * F_12 ( struct V_22 * V_22 , enum V_25 V_26 )
{
struct V_21 * V_27 = V_21 ( V_22 ) ;
switch ( V_26 ) {
case V_28 :
return & V_27 -> V_29 ;
case V_30 :
return & V_27 -> V_31 ;
case V_32 :
return & V_27 -> V_33 ;
case V_34 :
return & V_27 -> V_35 ;
default:
return NULL ;
}
}
static int F_13 ( struct V_22 * V_22 , enum V_25 V_26 ,
struct V_36 * V_37 , int V_38 )
{
struct V_24 * V_24 = F_12 ( V_22 , V_26 ) ;
return F_14 ( V_24 , V_37 , V_38 , V_38 + 1 , V_39 ) ;
}
static struct V_36 * F_15 ( struct V_22 * V_22 ,
enum V_25 V_26 , int V_38 )
{
struct V_24 * V_24 = F_12 ( V_22 , V_26 ) ;
return F_16 ( V_24 , V_38 ) ;
}
static void F_17 ( struct V_22 * V_22 , enum V_25 V_26 , int V_38 )
{
struct V_24 * V_24 = F_12 ( V_22 , V_26 ) ;
F_18 ( V_24 , V_38 ) ;
}
void F_19 ( struct V_40 * V_41 )
{
F_20 ( & V_41 -> V_42 ) ;
}
struct V_40 * F_21 ( T_4 V_43 ,
void * V_44 )
{
struct V_40 * V_41 ;
struct V_40 * V_45 = NULL ;
F_22 ( & V_46 ) ;
F_23 (cma_dev, &dev_list, list)
if ( V_43 ( V_41 -> V_8 , V_44 ) ) {
V_45 = V_41 ;
break;
}
if ( V_45 )
F_19 ( V_45 ) ;
F_24 ( & V_46 ) ;
return V_45 ;
}
int F_25 ( struct V_40 * V_41 ,
unsigned int V_47 )
{
if ( V_47 < V_48 ( V_41 -> V_8 ) ||
V_47 > F_26 ( V_41 -> V_8 ) )
return - V_49 ;
return V_41 -> V_50 [ V_47 - V_48 ( V_41 -> V_8 ) ] ;
}
int F_27 ( struct V_40 * V_41 ,
unsigned int V_47 ,
enum V_51 V_50 )
{
unsigned long V_52 ;
if ( V_47 < V_48 ( V_41 -> V_8 ) ||
V_47 > F_26 ( V_41 -> V_8 ) )
return - V_49 ;
V_52 = F_28 ( V_41 -> V_8 , V_47 ) ;
if ( ! ( V_52 & 1 << V_50 ) )
return - V_49 ;
V_41 -> V_50 [ V_47 - V_48 ( V_41 -> V_8 ) ] =
V_50 ;
return 0 ;
}
struct V_53 * F_29 ( struct V_40 * V_41 )
{
return V_41 -> V_8 ;
}
static int F_30 ( struct V_54 * V_55 , enum V_56 V_57 )
{
unsigned long V_58 ;
int V_59 ;
F_31 ( & V_55 -> V_46 , V_58 ) ;
V_59 = ( V_55 -> V_60 == V_57 ) ;
F_32 ( & V_55 -> V_46 , V_58 ) ;
return V_59 ;
}
static int F_33 ( struct V_54 * V_55 ,
enum V_56 V_57 , enum V_56 V_61 )
{
unsigned long V_58 ;
int V_59 ;
F_31 ( & V_55 -> V_46 , V_58 ) ;
if ( ( V_59 = ( V_55 -> V_60 == V_57 ) ) )
V_55 -> V_60 = V_61 ;
F_32 ( & V_55 -> V_46 , V_58 ) ;
return V_59 ;
}
static enum V_56 F_34 ( struct V_54 * V_55 ,
enum V_56 V_61 )
{
unsigned long V_58 ;
enum V_56 V_62 ;
F_31 ( & V_55 -> V_46 , V_58 ) ;
V_62 = V_55 -> V_60 ;
V_55 -> V_60 = V_61 ;
F_32 ( & V_55 -> V_46 , V_58 ) ;
return V_62 ;
}
static inline T_3 F_35 ( const struct V_63 * V_64 )
{
return V_64 -> V_65 >> 4 ;
}
static inline void F_36 ( struct V_63 * V_64 , T_3 V_66 )
{
V_64 -> V_65 = ( V_66 << 4 ) | ( V_64 -> V_65 & 0xF ) ;
}
static int F_37 ( struct V_67 * V_68 , union V_69 * V_70 , bool V_71 )
{
struct V_72 * V_73 = NULL ;
if ( V_68 ) {
F_38 () ;
V_73 = F_39 ( V_68 ) ;
if ( V_73 ) {
if ( V_71 )
F_40 ( V_73 ,
* ( V_74 * ) ( V_70 -> V_75 + 12 ) ) ;
else
F_41 ( V_73 ,
* ( V_74 * ) ( V_70 -> V_75 + 12 ) ) ;
}
F_42 () ;
}
return ( V_73 ) ? 0 : - V_76 ;
}
static void F_43 ( struct V_54 * V_55 ,
struct V_40 * V_41 )
{
F_19 ( V_41 ) ;
V_55 -> V_41 = V_41 ;
V_55 -> V_77 = 0 ;
V_55 -> V_6 . V_8 = V_41 -> V_8 ;
V_55 -> V_6 . V_78 . V_79 . V_80 . V_81 =
F_44 ( V_41 -> V_8 -> V_82 ) ;
F_45 ( & V_55 -> V_83 , & V_41 -> V_84 ) ;
}
static void F_46 ( struct V_54 * V_55 ,
struct V_40 * V_41 )
{
F_43 ( V_55 , V_41 ) ;
V_55 -> V_77 =
V_41 -> V_50 [ V_55 -> V_6 . V_9 -
V_48 ( V_41 -> V_8 ) ] ;
}
void F_47 ( struct V_40 * V_41 )
{
if ( F_48 ( & V_41 -> V_42 ) )
F_49 ( & V_41 -> V_57 ) ;
}
static inline void F_50 ( struct V_85 * V_85 )
{
struct V_86 * V_87 = F_51 ( V_85 , struct V_86 , V_88 ) ;
F_52 ( V_87 -> V_89 . V_90 ) ;
F_52 ( V_87 ) ;
}
static void F_53 ( struct V_54 * V_55 )
{
F_22 ( & V_46 ) ;
F_54 ( & V_55 -> V_83 ) ;
F_47 ( V_55 -> V_41 ) ;
V_55 -> V_41 = NULL ;
F_24 ( & V_46 ) ;
}
static inline struct V_91 * F_55 ( struct V_54 * V_55 )
{
return (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_92 ;
}
static inline struct V_91 * F_56 ( struct V_54 * V_55 )
{
return (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_93 ;
}
static inline unsigned short F_57 ( struct V_54 * V_55 )
{
return V_55 -> V_6 . V_78 . V_79 . V_92 . V_94 ;
}
static int F_58 ( struct V_54 * V_55 , T_5 V_95 )
{
struct V_96 V_97 ;
int V_59 = 0 ;
if ( V_55 -> V_95 ) {
if ( V_95 && V_55 -> V_95 != V_95 )
return - V_49 ;
return 0 ;
}
if ( V_95 ) {
V_55 -> V_95 = V_95 ;
return 0 ;
}
switch ( V_55 -> V_6 . V_26 ) {
case V_30 :
case V_34 :
V_55 -> V_95 = V_98 ;
break;
case V_32 :
F_59 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , & V_97 . V_70 ) ;
V_59 = F_60 ( V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 , & V_97 . V_70 ,
& V_97 ) ;
if ( ! V_59 )
V_55 -> V_95 = F_61 ( V_97 . V_95 ) ;
break;
default:
break;
}
return V_59 ;
}
static void F_62 ( struct V_99 * V_100 , struct V_101 * V_80 )
{
V_80 -> V_102 = V_103 ;
F_63 ( V_80 , (union V_69 * ) & V_100 -> V_104 ) ;
F_64 ( V_80 , F_65 ( V_100 -> V_105 ) ) ;
}
static int F_66 ( struct V_91 * V_79 , struct V_101 * V_80 )
{
int V_59 ;
if ( V_79 -> V_106 != V_107 ) {
V_59 = F_67 ( V_79 , V_80 , NULL ) ;
} else {
F_62 ( (struct V_99 * ) V_79 , V_80 ) ;
V_59 = 0 ;
}
return V_59 ;
}
static inline int F_68 ( struct V_53 * V_8 , T_3 V_47 ,
enum V_51 V_77 ,
union V_69 * V_108 , int V_102 ,
int V_109 )
{
int V_59 = - V_76 ;
struct V_67 * V_68 = NULL ;
if ( ( V_102 == V_103 ) && ! F_69 ( V_8 , V_47 ) )
return V_59 ;
if ( ( V_102 != V_103 ) && F_69 ( V_8 , V_47 ) )
return V_59 ;
if ( V_102 == V_110 && F_70 ( V_8 , V_47 ) ) {
V_68 = F_71 ( & V_111 , V_109 ) ;
if ( V_68 && V_68 -> V_58 & V_112 ) {
F_72 ( L_3 ) ;
F_73 ( V_68 ) ;
if ( ! V_8 -> V_113 )
return - V_114 ;
V_68 = V_8 -> V_113 ( V_8 , V_47 ) ;
if ( ! V_68 )
return - V_76 ;
}
} else {
V_77 = V_115 ;
}
V_59 = F_74 ( V_8 , V_108 , V_77 , V_47 ,
V_68 , NULL ) ;
if ( V_68 )
F_73 ( V_68 ) ;
return V_59 ;
}
static int F_75 ( struct V_54 * V_55 ,
struct V_54 * V_116 )
{
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
struct V_40 * V_41 ;
union V_69 V_108 , V_117 , * V_118 ;
int V_59 = - V_76 ;
T_3 V_47 ;
if ( V_80 -> V_102 != V_103 &&
V_55 -> V_6 . V_26 == V_32 )
return - V_49 ;
F_22 ( & V_46 ) ;
F_76 ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_92 ,
& V_117 ) ;
memcpy ( & V_108 , V_80 -> V_119 +
F_77 ( V_80 ) , sizeof V_108 ) ;
if ( V_116 ) {
V_41 = V_116 -> V_41 ;
V_47 = V_116 -> V_6 . V_9 ;
V_118 = F_70 ( V_41 -> V_8 , V_47 ) ?
& V_117 : & V_108 ;
V_59 = F_68 ( V_41 -> V_8 , V_47 ,
F_69 ( V_41 -> V_8 , V_47 ) ?
V_115 :
V_116 -> V_77 , V_118 ,
V_80 -> V_102 ,
V_80 -> V_120 ) ;
if ( ! V_59 ) {
V_55 -> V_6 . V_9 = V_47 ;
goto V_121;
}
}
F_23 (cma_dev, &dev_list, list) {
for ( V_47 = 1 ; V_47 <= V_41 -> V_8 -> V_122 ; ++ V_47 ) {
if ( V_116 &&
V_116 -> V_41 == V_41 &&
V_116 -> V_6 . V_9 == V_47 )
continue;
V_118 = F_70 ( V_41 -> V_8 , V_47 ) ?
& V_117 : & V_108 ;
V_59 = F_68 ( V_41 -> V_8 , V_47 ,
F_69 ( V_41 -> V_8 , V_47 ) ?
V_115 :
V_41 -> V_50 [ V_47 - 1 ] ,
V_118 , V_80 -> V_102 ,
V_80 -> V_120 ) ;
if ( ! V_59 ) {
V_55 -> V_6 . V_9 = V_47 ;
goto V_121;
}
}
}
V_121:
if ( ! V_59 )
F_46 ( V_55 , V_41 ) ;
F_24 ( & V_46 ) ;
return V_59 ;
}
static int F_78 ( struct V_54 * V_55 )
{
struct V_40 * V_41 , * V_123 ;
struct V_99 * V_79 ;
union V_69 V_108 , V_124 , * V_125 ;
T_6 V_126 , V_3 ;
T_3 V_15 ;
int V_127 ;
V_41 = NULL ;
V_79 = (struct V_99 * ) F_56 ( V_55 ) ;
V_125 = (union V_69 * ) & V_79 -> V_104 ;
V_126 = F_65 ( V_79 -> V_105 ) ;
F_23 (cur_dev, &dev_list, list) {
for ( V_15 = 1 ; V_15 <= V_123 -> V_8 -> V_122 ; ++ V_15 ) {
if ( ! F_79 ( V_123 -> V_8 , V_15 ) )
continue;
if ( F_80 ( V_123 -> V_8 , V_15 , V_126 , & V_3 ) )
continue;
for ( V_127 = 0 ; ! F_81 ( V_123 -> V_8 , V_15 , V_127 ,
& V_108 , NULL ) ;
V_127 ++ ) {
if ( ! memcmp ( & V_108 , V_125 , sizeof( V_108 ) ) ) {
V_41 = V_123 ;
V_124 = V_108 ;
V_55 -> V_6 . V_9 = V_15 ;
goto V_128;
}
if ( ! V_41 && ( V_108 . V_129 . V_130 ==
V_125 -> V_129 . V_130 ) ) {
V_41 = V_123 ;
V_124 = V_108 ;
V_55 -> V_6 . V_9 = V_15 ;
}
}
}
}
if ( ! V_41 )
return - V_76 ;
V_128:
F_46 ( V_55 , V_41 ) ;
V_79 = (struct V_99 * ) F_55 ( V_55 ) ;
memcpy ( & V_79 -> V_104 , & V_124 , sizeof V_124 ) ;
F_62 ( V_79 , & V_55 -> V_6 . V_78 . V_79 . V_80 ) ;
return 0 ;
}
static void F_82 ( struct V_54 * V_55 )
{
if ( F_48 ( & V_55 -> V_42 ) )
F_49 ( & V_55 -> V_57 ) ;
}
struct V_5 * F_83 ( struct V_22 * V_22 ,
T_7 V_131 ,
void * V_132 , enum V_25 V_26 ,
enum V_133 V_134 )
{
struct V_54 * V_55 ;
V_55 = F_84 ( sizeof *V_55 , V_39 ) ;
if ( ! V_55 )
return F_85 ( - V_135 ) ;
V_55 -> V_136 = F_86 ( V_137 ) ;
V_55 -> V_60 = V_138 ;
V_55 -> V_6 . V_132 = V_132 ;
V_55 -> V_6 . V_131 = V_131 ;
V_55 -> V_6 . V_26 = V_26 ;
V_55 -> V_6 . V_134 = V_134 ;
F_87 ( & V_55 -> V_46 ) ;
F_88 ( & V_55 -> V_139 ) ;
F_89 ( & V_55 -> V_57 ) ;
F_90 ( & V_55 -> V_42 , 1 ) ;
F_88 ( & V_55 -> V_140 ) ;
F_91 ( & V_55 -> V_141 ) ;
F_91 ( & V_55 -> V_142 ) ;
F_92 ( & V_55 -> V_143 , sizeof V_55 -> V_143 ) ;
V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 = F_93 ( V_22 ) ;
return & V_55 -> V_6 ;
}
static int F_94 ( struct V_54 * V_55 , struct V_144 * V_145 )
{
struct V_146 V_147 ;
int V_148 , V_59 ;
V_147 . V_149 = V_150 ;
V_59 = F_95 ( & V_55 -> V_6 , & V_147 , & V_148 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_96 ( V_145 , & V_147 , V_148 ) ;
if ( V_59 )
return V_59 ;
V_147 . V_149 = V_151 ;
V_59 = F_96 ( V_145 , & V_147 , V_152 ) ;
if ( V_59 )
return V_59 ;
V_147 . V_149 = V_153 ;
V_147 . V_154 = 0 ;
V_59 = F_96 ( V_145 , & V_147 , V_152 | V_155 ) ;
return V_59 ;
}
static int F_97 ( struct V_54 * V_55 , struct V_144 * V_145 )
{
struct V_146 V_147 ;
int V_148 , V_59 ;
V_147 . V_149 = V_150 ;
V_59 = F_95 ( & V_55 -> V_6 , & V_147 , & V_148 ) ;
if ( V_59 )
return V_59 ;
return F_96 ( V_145 , & V_147 , V_148 ) ;
}
int F_98 ( struct V_5 * V_6 , struct V_156 * V_157 ,
struct V_158 * V_159 )
{
struct V_54 * V_55 ;
struct V_144 * V_145 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( V_6 -> V_8 != V_157 -> V_8 )
return - V_49 ;
V_159 -> V_9 = V_6 -> V_9 ;
V_145 = F_99 ( V_157 , V_159 ) ;
if ( F_100 ( V_145 ) )
return F_101 ( V_145 ) ;
if ( V_6 -> V_134 == V_160 )
V_59 = F_94 ( V_55 , V_145 ) ;
else
V_59 = F_97 ( V_55 , V_145 ) ;
if ( V_59 )
goto V_161;
V_6 -> V_145 = V_145 ;
V_55 -> V_162 = V_145 -> V_162 ;
V_55 -> V_163 = ( V_145 -> V_163 != NULL ) ;
return 0 ;
V_161:
F_102 ( V_145 ) ;
return V_59 ;
}
void F_103 ( struct V_5 * V_6 )
{
struct V_54 * V_55 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
F_22 ( & V_55 -> V_139 ) ;
F_102 ( V_55 -> V_6 . V_145 ) ;
V_55 -> V_6 . V_145 = NULL ;
F_24 ( & V_55 -> V_139 ) ;
}
static int F_104 ( struct V_54 * V_55 ,
struct V_164 * V_165 )
{
struct V_146 V_147 ;
int V_148 , V_59 ;
union V_69 V_124 ;
F_22 ( & V_55 -> V_139 ) ;
if ( ! V_55 -> V_6 . V_145 ) {
V_59 = 0 ;
goto V_121;
}
V_147 . V_149 = V_150 ;
V_59 = F_95 ( & V_55 -> V_6 , & V_147 , & V_148 ) ;
if ( V_59 )
goto V_121;
V_59 = F_96 ( V_55 -> V_6 . V_145 , & V_147 , V_148 ) ;
if ( V_59 )
goto V_121;
V_147 . V_149 = V_151 ;
V_59 = F_95 ( & V_55 -> V_6 , & V_147 , & V_148 ) ;
if ( V_59 )
goto V_121;
V_59 = F_105 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ,
V_147 . V_166 . V_167 . V_168 , & V_124 , NULL ) ;
if ( V_59 )
goto V_121;
F_106 ( V_55 -> V_41 -> V_8 != V_55 -> V_6 . V_8 ) ;
if ( V_165 )
V_147 . V_169 = V_165 -> V_170 ;
V_59 = F_96 ( V_55 -> V_6 . V_145 , & V_147 , V_148 ) ;
V_121:
F_24 ( & V_55 -> V_139 ) ;
return V_59 ;
}
static int F_107 ( struct V_54 * V_55 ,
struct V_164 * V_165 )
{
struct V_146 V_147 ;
int V_148 , V_59 ;
F_22 ( & V_55 -> V_139 ) ;
if ( ! V_55 -> V_6 . V_145 ) {
V_59 = 0 ;
goto V_121;
}
V_147 . V_149 = V_153 ;
V_59 = F_95 ( & V_55 -> V_6 , & V_147 , & V_148 ) ;
if ( V_59 )
goto V_121;
if ( V_165 )
V_147 . V_171 = V_165 -> V_172 ;
V_59 = F_96 ( V_55 -> V_6 . V_145 , & V_147 , V_148 ) ;
V_121:
F_24 ( & V_55 -> V_139 ) ;
return V_59 ;
}
static int F_108 ( struct V_54 * V_55 )
{
struct V_146 V_147 ;
int V_59 ;
F_22 ( & V_55 -> V_139 ) ;
if ( ! V_55 -> V_6 . V_145 ) {
V_59 = 0 ;
goto V_121;
}
V_147 . V_149 = V_173 ;
V_59 = F_96 ( V_55 -> V_6 . V_145 , & V_147 , V_152 ) ;
V_121:
F_24 ( & V_55 -> V_139 ) ;
return V_59 ;
}
static int F_109 ( struct V_54 * V_55 ,
struct V_146 * V_147 , int * V_148 )
{
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
int V_59 ;
T_6 V_126 ;
if ( F_110 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ) )
V_126 = 0xffff ;
else
V_126 = F_111 ( V_80 ) ;
V_59 = F_80 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ,
V_126 , & V_147 -> V_174 ) ;
if ( V_59 )
return V_59 ;
V_147 -> V_9 = V_55 -> V_6 . V_9 ;
* V_148 = V_152 | V_175 | V_176 ;
if ( V_55 -> V_6 . V_134 == V_160 ) {
V_59 = F_58 ( V_55 , 0 ) ;
if ( V_59 )
return V_59 ;
V_147 -> V_95 = V_55 -> V_95 ;
* V_148 |= V_177 ;
} else {
V_147 -> V_178 = 0 ;
* V_148 |= V_179 ;
}
return 0 ;
}
int F_95 ( struct V_5 * V_6 , struct V_146 * V_147 ,
int * V_148 )
{
struct V_54 * V_55 ;
int V_59 = 0 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( F_112 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( ! V_55 -> V_180 . V_90 || ( V_55 -> V_6 . V_134 == V_160 ) )
V_59 = F_109 ( V_55 , V_147 , V_148 ) ;
else
V_59 = F_113 ( V_55 -> V_180 . V_90 , V_147 ,
V_148 ) ;
if ( V_147 -> V_149 == V_151 )
V_147 -> V_181 = V_55 -> V_143 ;
} else if ( F_114 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( ! V_55 -> V_180 . V_182 ) {
V_147 -> V_178 = 0 ;
* V_148 = V_152 | V_179 ;
} else
V_59 = F_115 ( V_55 -> V_180 . V_182 , V_147 ,
V_148 ) ;
} else
V_59 = - V_183 ;
return V_59 ;
}
static inline int F_116 ( struct V_91 * V_79 )
{
switch ( V_79 -> V_106 ) {
case V_184 :
return F_117 ( ( (struct V_185 * ) V_79 ) -> V_186 . V_187 ) ;
case V_188 :
return F_118 ( & ( (struct V_189 * ) V_79 ) -> V_190 ) ;
case V_107 :
return F_119 ( & ( (struct V_99 * ) V_79 ) -> V_104 ) ;
default:
return 0 ;
}
}
static inline int F_120 ( struct V_91 * V_79 )
{
switch ( V_79 -> V_106 ) {
case V_184 :
return F_121 ( ( (struct V_185 * ) V_79 ) -> V_186 . V_187 ) ;
case V_188 :
return F_122 ( & ( (struct V_189 * ) V_79 ) -> V_190 ) ;
case V_107 :
return F_123 ( & ( (struct V_99 * ) V_79 ) -> V_104 ) ;
default:
return 0 ;
}
}
static inline int F_124 ( struct V_91 * V_79 )
{
return F_116 ( V_79 ) || F_120 ( V_79 ) ;
}
static int F_125 ( struct V_91 * V_191 , struct V_91 * V_192 )
{
if ( V_191 -> V_106 != V_192 -> V_106 )
return - 1 ;
switch ( V_191 -> V_106 ) {
case V_184 :
return ( (struct V_185 * ) V_191 ) -> V_186 . V_187 !=
( (struct V_185 * ) V_192 ) -> V_186 . V_187 ;
case V_188 :
return F_126 ( & ( (struct V_189 * ) V_191 ) -> V_190 ,
& ( (struct V_189 * ) V_192 ) -> V_190 ) ;
default:
return F_127 ( & ( (struct V_99 * ) V_191 ) -> V_104 ,
& ( (struct V_99 * ) V_192 ) -> V_104 ) ;
}
}
static T_8 F_128 ( struct V_91 * V_79 )
{
struct V_99 * V_100 ;
switch ( V_79 -> V_106 ) {
case V_184 :
return ( (struct V_185 * ) V_79 ) -> V_193 ;
case V_188 :
return ( (struct V_189 * ) V_79 ) -> V_194 ;
case V_107 :
V_100 = (struct V_99 * ) V_79 ;
return F_129 ( ( T_6 ) ( F_130 ( V_100 -> V_195 ) &
F_130 ( V_100 -> V_196 ) ) ) ;
default:
return 0 ;
}
}
static inline int F_131 ( struct V_91 * V_79 )
{
return ! F_128 ( V_79 ) ;
}
static void F_132 ( struct V_91 * V_92 ,
struct V_91 * V_93 ,
struct V_5 * V_197 ,
struct V_198 * V_199 )
{
struct V_99 * V_200 , * V_90 ;
V_200 = (struct V_99 * ) & V_197 -> V_78 . V_79 . V_92 ;
if ( V_92 ) {
V_90 = (struct V_99 * ) V_92 ;
V_90 -> V_201 = V_107 ;
if ( V_199 ) {
V_90 -> V_105 = V_199 -> V_126 ;
V_90 -> V_202 = V_199 -> V_203 ;
memcpy ( & V_90 -> V_104 , & V_199 -> V_124 , 16 ) ;
V_90 -> V_195 = V_199 -> V_204 ;
V_90 -> V_205 = 0 ;
} else {
V_90 -> V_105 = V_200 -> V_105 ;
V_90 -> V_202 = V_200 -> V_202 ;
V_90 -> V_104 = V_200 -> V_104 ;
V_90 -> V_195 = V_200 -> V_195 ;
V_90 -> V_205 = V_200 -> V_205 ;
}
V_90 -> V_196 = F_133 ( 0xffffffffffffffffULL ) ;
}
if ( V_93 ) {
V_90 = (struct V_99 * ) V_93 ;
V_90 -> V_201 = V_107 ;
if ( V_199 ) {
V_90 -> V_105 = V_199 -> V_126 ;
V_90 -> V_202 = V_199 -> V_203 ;
memcpy ( & V_90 -> V_104 , & V_199 -> V_125 , 16 ) ;
}
}
}
static void F_134 ( struct V_185 * V_92 ,
struct V_185 * V_93 ,
struct V_63 * V_64 ,
T_8 V_206 )
{
if ( V_92 ) {
* V_92 = (struct V_185 ) {
. V_207 = V_184 ,
. V_186 . V_187 = V_64 -> V_93 . V_208 . V_79 ,
. V_193 = V_206 ,
} ;
}
if ( V_93 ) {
* V_93 = (struct V_185 ) {
. V_207 = V_184 ,
. V_186 . V_187 = V_64 -> V_92 . V_208 . V_79 ,
. V_193 = V_64 -> V_47 ,
} ;
}
}
static void F_135 ( struct V_189 * V_92 ,
struct V_189 * V_93 ,
struct V_63 * V_64 ,
T_8 V_206 )
{
if ( V_92 ) {
* V_92 = (struct V_189 ) {
. V_209 = V_188 ,
. V_190 = V_64 -> V_93 . V_210 ,
. V_194 = V_206 ,
} ;
}
if ( V_93 ) {
* V_93 = (struct V_189 ) {
. V_209 = V_188 ,
. V_190 = V_64 -> V_92 . V_210 ,
. V_194 = V_64 -> V_47 ,
} ;
}
}
static T_6 F_136 ( T_9 V_204 )
{
return ( T_6 ) F_130 ( V_204 ) ;
}
static int F_137 ( struct V_91 * V_92 ,
struct V_91 * V_93 ,
struct V_211 * V_212 ,
T_9 V_204 )
{
struct V_63 * V_64 ;
T_8 V_47 ;
V_64 = V_212 -> V_20 ;
if ( V_64 -> V_213 != V_214 )
return - V_49 ;
V_47 = F_129 ( F_136 ( V_204 ) ) ;
switch ( F_35 ( V_64 ) ) {
case 4 :
F_134 ( (struct V_185 * ) V_92 ,
(struct V_185 * ) V_93 , V_64 , V_47 ) ;
break;
case 6 :
F_135 ( (struct V_189 * ) V_92 ,
(struct V_189 * ) V_93 , V_64 , V_47 ) ;
break;
default:
return - V_215 ;
}
return 0 ;
}
static int F_138 ( struct V_91 * V_92 ,
struct V_91 * V_93 ,
struct V_5 * V_197 ,
struct V_211 * V_212 ,
T_10 V_106 , T_9 V_204 )
{
if ( V_106 == V_107 ) {
if ( V_212 -> V_2 == V_216 )
F_132 ( V_92 , V_93 , V_197 ,
V_212 -> V_17 . V_217 . V_218 ) ;
else if ( V_212 -> V_2 == V_219 )
F_132 ( V_92 , V_93 , V_197 , NULL ) ;
return 0 ;
}
return F_137 ( V_92 , V_93 , V_212 , V_204 ) ;
}
static int F_139 ( const struct V_211 * V_212 ,
struct V_220 * V_221 )
{
const struct V_222 * V_223 =
& V_212 -> V_17 . V_217 ;
const struct V_224 * V_225 =
& V_212 -> V_17 . V_226 ;
switch ( V_212 -> V_2 ) {
case V_216 :
V_221 -> V_8 = V_223 -> V_197 -> V_8 ;
V_221 -> V_47 = V_223 -> V_47 ;
memcpy ( & V_221 -> V_227 , & V_223 -> V_218 -> V_124 ,
sizeof( V_221 -> V_227 ) ) ;
V_221 -> V_228 = true ;
V_221 -> V_204 = V_223 -> V_218 -> V_204 ;
V_221 -> V_126 = F_140 ( V_223 -> V_218 -> V_126 ) ;
if ( V_221 -> V_126 != V_223 -> V_229 )
F_141 ( L_4
L_5 ,
V_223 -> V_229 , V_221 -> V_126 ) ;
break;
case V_219 :
V_221 -> V_8 = V_225 -> V_197 -> V_8 ;
V_221 -> V_47 = V_225 -> V_47 ;
V_221 -> V_228 = false ;
V_221 -> V_204 = V_225 -> V_204 ;
V_221 -> V_126 = V_225 -> V_126 ;
if ( V_221 -> V_126 != V_225 -> V_229 )
F_141 ( L_6
L_5 ,
V_225 -> V_229 , V_221 -> V_126 ) ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static bool F_142 ( struct V_67 * V_230 ,
const struct V_185 * V_93 ,
const struct V_185 * V_92 )
{
V_74 V_231 = V_93 -> V_186 . V_187 ,
V_232 = V_92 -> V_186 . V_187 ;
struct V_233 V_234 ;
struct V_235 V_236 ;
int V_161 ;
bool V_59 ;
if ( F_143 ( V_232 ) || F_144 ( V_232 ) ||
F_144 ( V_231 ) || F_117 ( V_232 ) ||
F_117 ( V_231 ) || F_121 ( V_231 ) ||
F_121 ( V_232 ) )
return false ;
memset ( & V_236 , 0 , sizeof( V_236 ) ) ;
V_236 . V_237 = V_230 -> V_238 ;
V_236 . V_231 = V_231 ;
V_236 . V_232 = V_232 ;
F_145 () ;
V_161 = F_146 ( F_147 ( V_230 ) , & V_236 , & V_234 , 0 ) ;
V_59 = V_161 == 0 && F_148 ( V_234 ) == V_230 ;
F_149 () ;
return V_59 ;
}
static bool F_150 ( struct V_67 * V_230 ,
const struct V_189 * V_93 ,
const struct V_189 * V_92 )
{
#if F_151 ( V_239 )
const int V_240 = F_152 ( & V_93 -> V_190 ) &
V_241 ;
struct V_242 * V_243 = F_153 ( F_147 ( V_230 ) , & V_93 -> V_190 ,
& V_92 -> V_190 , V_230 -> V_238 ,
V_240 ) ;
bool V_59 ;
if ( ! V_243 )
return false ;
V_59 = V_243 -> V_244 -> V_245 == V_230 ;
F_154 ( V_243 ) ;
return V_59 ;
#else
return false ;
#endif
}
static bool F_155 ( struct V_67 * V_230 ,
const struct V_91 * V_231 ,
const struct V_91 * V_232 )
{
const struct V_185 * V_246 = ( const struct V_185 * ) V_231 ;
const struct V_185 * V_247 = ( const struct V_185 * ) V_232 ;
const struct V_189 * V_248 = ( const struct V_189 * ) V_231 ;
const struct V_189 * V_249 = ( const struct V_189 * ) V_232 ;
switch ( V_231 -> V_106 ) {
case V_184 :
return V_232 -> V_106 == V_184 &&
F_142 ( V_230 , V_246 , V_247 ) ;
case V_188 :
return V_232 -> V_106 == V_188 &&
F_150 ( V_230 , V_248 , V_249 ) ;
default:
return false ;
}
}
static struct V_67 * F_156 ( struct V_211 * V_212 ,
const struct V_220 * V_221 )
{
struct V_250 V_251 , V_252 ;
struct V_91 * V_253 = (struct V_91 * ) & V_251 ,
* V_92 = (struct V_91 * ) & V_252 ;
struct V_67 * V_230 ;
const union V_69 * V_108 = V_221 -> V_228 ? & V_221 -> V_227 : NULL ;
int V_161 ;
V_161 = F_137 ( V_253 , V_92 , V_212 ,
V_221 -> V_204 ) ;
if ( V_161 )
return F_85 ( V_161 ) ;
V_230 = F_157 ( V_221 -> V_8 , V_221 -> V_47 , V_221 -> V_126 ,
V_108 , V_253 ) ;
if ( ! V_230 )
return F_85 ( - V_76 ) ;
if ( ! F_155 ( V_230 , V_253 , V_92 ) ) {
F_73 ( V_230 ) ;
return F_85 ( - V_254 ) ;
}
return V_230 ;
}
static enum V_25 F_158 ( T_9 V_204 )
{
return ( F_130 ( V_204 ) >> 16 ) & 0xffff ;
}
static bool F_159 ( struct V_54 * V_55 ,
const struct V_63 * V_64 )
{
struct V_91 * V_79 = F_55 ( V_55 ) ;
V_74 V_255 ;
struct V_256 V_257 ;
if ( F_124 ( V_79 ) && ! V_55 -> V_258 )
return true ;
switch ( V_79 -> V_106 ) {
case V_184 :
V_255 = ( (struct V_185 * ) V_79 ) -> V_186 . V_187 ;
if ( F_35 ( V_64 ) != 4 )
return false ;
if ( ! F_124 ( V_79 ) &&
V_64 -> V_93 . V_208 . V_79 != V_255 )
return false ;
break;
case V_188 :
V_257 = ( (struct V_189 * ) V_79 ) -> V_190 ;
if ( F_35 ( V_64 ) != 6 )
return false ;
if ( ! F_124 ( V_79 ) &&
memcmp ( & V_64 -> V_93 . V_210 , & V_257 , sizeof( V_257 ) ) )
return false ;
break;
case V_107 :
return true ;
default:
return false ;
}
return true ;
}
static bool F_160 ( struct V_53 * V_8 , int V_9 )
{
enum V_259 V_260 = F_161 ( V_8 , V_9 ) ;
enum V_261 V_81 =
F_44 ( V_8 -> V_82 ) ;
return V_260 == V_262 && V_81 == V_263 ;
}
static bool F_162 ( const struct V_5 * V_6 )
{
struct V_53 * V_8 = V_6 -> V_8 ;
const int V_9 = V_6 -> V_9 ? : V_48 ( V_8 ) ;
return F_160 ( V_8 , V_9 ) ;
}
static bool F_163 ( const struct V_5 * V_6 ,
const struct V_67 * V_230 ,
T_3 V_9 )
{
const struct V_264 * V_79 = & V_6 -> V_78 . V_79 ;
if ( ! V_230 )
return ( ! V_6 -> V_9 || V_6 -> V_9 == V_9 ) &&
( V_79 -> V_92 . V_94 == V_107 ||
F_160 ( V_6 -> V_8 , V_9 ) ) ;
return ! V_79 -> V_80 . V_120 ||
( F_164 ( F_147 ( V_230 ) , V_79 -> V_80 . V_22 ) &&
V_79 -> V_80 . V_120 == V_230 -> V_238 ) ;
}
static struct V_54 * F_165 (
const struct V_36 * V_37 ,
const struct V_265 * V_180 ,
const struct V_211 * V_212 ,
const struct V_220 * V_221 ,
const struct V_67 * V_230 )
{
struct V_54 * V_55 , * V_266 ;
if ( ! V_37 )
return F_85 ( - V_49 ) ;
F_166 (id_priv, &bind_list->owners, node) {
if ( F_159 ( V_55 , V_212 -> V_20 ) ) {
if ( V_55 -> V_6 . V_8 == V_180 -> V_8 &&
F_163 ( & V_55 -> V_6 , V_230 , V_221 -> V_47 ) )
return V_55 ;
F_23 (id_priv_dev,
&id_priv->listen_list,
listen_list) {
if ( V_266 -> V_6 . V_8 == V_180 -> V_8 &&
F_163 ( & V_266 -> V_6 , V_230 , V_221 -> V_47 ) )
return V_266 ;
}
}
}
return F_85 ( - V_49 ) ;
}
static struct V_54 * F_167 ( struct V_265 * V_180 ,
struct V_211 * V_212 ,
struct V_67 * * V_230 )
{
struct V_220 V_221 ;
struct V_36 * V_37 ;
struct V_54 * V_55 ;
int V_161 ;
V_161 = F_139 ( V_212 , & V_221 ) ;
if ( V_161 )
return F_85 ( V_161 ) ;
* V_230 = F_156 ( V_212 , & V_221 ) ;
if ( F_100 ( * V_230 ) ) {
if ( F_101 ( * V_230 ) == - V_215 ) {
* V_230 = NULL ;
} else if ( F_160 ( V_221 . V_8 , V_221 . V_47 ) ) {
* V_230 = NULL ;
} else {
return F_168 ( * V_230 ) ;
}
}
V_37 = F_15 ( * V_230 ? F_147 ( * V_230 ) : & V_111 ,
F_158 ( V_221 . V_204 ) ,
F_136 ( V_221 . V_204 ) ) ;
V_55 = F_165 ( V_37 , V_180 , V_212 , & V_221 , * V_230 ) ;
if ( F_100 ( V_55 ) && * V_230 ) {
F_73 ( * V_230 ) ;
* V_230 = NULL ;
}
return V_55 ;
}
static inline int F_169 ( struct V_54 * V_55 )
{
return F_57 ( V_55 ) == V_107 ? 0 : sizeof( struct V_63 ) ;
}
static void F_170 ( struct V_54 * V_55 )
{
if ( F_171 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ) ) {
if ( V_55 -> V_267 )
F_172 ( V_55 -> V_268 , V_55 -> V_267 ) ;
}
}
static void F_173 ( struct V_54 * V_55 )
{
struct V_54 * V_269 ;
F_22 ( & V_46 ) ;
F_54 ( & V_55 -> V_83 ) ;
while ( ! F_174 ( & V_55 -> V_141 ) ) {
V_269 = F_175 ( V_55 -> V_141 . V_270 ,
struct V_54 , V_141 ) ;
F_176 ( & V_269 -> V_83 ) ;
F_54 ( & V_269 -> V_141 ) ;
F_24 ( & V_46 ) ;
F_177 ( & V_269 -> V_6 ) ;
F_22 ( & V_46 ) ;
}
F_24 ( & V_46 ) ;
}
static void F_178 ( struct V_54 * V_55 ,
enum V_56 V_60 )
{
switch ( V_60 ) {
case V_271 :
F_179 ( & V_55 -> V_6 . V_78 . V_79 . V_80 ) ;
break;
case V_272 :
F_170 ( V_55 ) ;
break;
case V_273 :
if ( F_124 ( F_55 ( V_55 ) ) && ! V_55 -> V_41 )
F_173 ( V_55 ) ;
break;
default:
break;
}
}
static void F_180 ( struct V_54 * V_55 )
{
struct V_36 * V_37 = V_55 -> V_37 ;
struct V_22 * V_22 = V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ;
if ( ! V_37 )
return;
F_22 ( & V_46 ) ;
F_181 ( & V_55 -> V_274 ) ;
if ( F_182 ( & V_37 -> V_275 ) ) {
F_17 ( V_22 , V_37 -> V_26 , V_37 -> V_47 ) ;
F_52 ( V_37 ) ;
}
F_24 ( & V_46 ) ;
}
static void F_183 ( struct V_54 * V_55 )
{
struct V_86 * V_87 ;
while ( ! F_174 ( & V_55 -> V_142 ) ) {
V_87 = F_51 ( V_55 -> V_142 . V_270 ,
struct V_86 , V_83 ) ;
F_54 ( & V_87 -> V_83 ) ;
if ( F_184 ( V_55 -> V_41 -> V_8 ,
V_55 -> V_6 . V_9 ) ) {
F_185 ( V_87 -> V_89 . V_90 ) ;
F_52 ( V_87 ) ;
} else {
if ( V_87 -> V_276 ) {
struct V_101 * V_80 =
& V_55 -> V_6 . V_78 . V_79 . V_80 ;
struct V_67 * V_68 = NULL ;
if ( V_80 -> V_120 )
V_68 = F_71 ( & V_111 ,
V_80 -> V_120 ) ;
if ( V_68 ) {
F_37 ( V_68 ,
& V_87 -> V_89 . V_90 -> V_97 . V_70 ,
false ) ;
F_73 ( V_68 ) ;
}
}
F_186 ( & V_87 -> V_88 , F_50 ) ;
}
}
}
void F_177 ( struct V_5 * V_6 )
{
struct V_54 * V_55 ;
enum V_56 V_60 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
V_60 = F_34 ( V_55 , V_277 ) ;
F_178 ( V_55 , V_60 ) ;
F_22 ( & V_55 -> V_140 ) ;
F_24 ( & V_55 -> V_140 ) ;
if ( V_55 -> V_41 ) {
if ( F_112 ( V_55 -> V_6 . V_8 , 1 ) ) {
if ( V_55 -> V_180 . V_90 )
F_187 ( V_55 -> V_180 . V_90 ) ;
} else if ( F_114 ( V_55 -> V_6 . V_8 , 1 ) ) {
if ( V_55 -> V_180 . V_182 )
F_188 ( V_55 -> V_180 . V_182 ) ;
}
F_183 ( V_55 ) ;
F_53 ( V_55 ) ;
}
F_180 ( V_55 ) ;
F_82 ( V_55 ) ;
F_189 ( & V_55 -> V_57 ) ;
if ( V_55 -> V_278 )
F_82 ( V_55 -> V_6 . V_132 ) ;
F_52 ( V_55 -> V_6 . V_78 . V_279 ) ;
F_190 ( V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ) ;
F_52 ( V_55 ) ;
}
static int F_191 ( struct V_54 * V_55 )
{
int V_59 ;
V_59 = F_104 ( V_55 , NULL ) ;
if ( V_59 )
goto V_280;
V_59 = F_107 ( V_55 , NULL ) ;
if ( V_59 )
goto V_280;
V_59 = F_192 ( V_55 -> V_180 . V_90 , NULL , 0 ) ;
if ( V_59 )
goto V_280;
return 0 ;
V_280:
F_108 ( V_55 ) ;
F_193 ( V_55 -> V_180 . V_90 , V_10 ,
NULL , 0 , NULL , 0 ) ;
return V_59 ;
}
static void F_194 ( struct V_12 * V_2 ,
struct V_281 * V_282 ,
void * V_20 )
{
V_2 -> V_17 . V_18 . V_20 = V_20 ;
V_2 -> V_17 . V_18 . V_19 = V_283 ;
V_2 -> V_17 . V_18 . V_170 = V_282 -> V_170 ;
V_2 -> V_17 . V_18 . V_172 = V_282 -> V_172 ;
V_2 -> V_17 . V_18 . V_284 = V_282 -> V_284 ;
V_2 -> V_17 . V_18 . V_285 = V_282 -> V_285 ;
V_2 -> V_17 . V_18 . V_163 = V_282 -> V_163 ;
V_2 -> V_17 . V_18 . V_162 = V_282 -> V_286 ;
}
static int F_195 ( struct V_265 * V_180 , struct V_211 * V_212 )
{
struct V_54 * V_55 = V_180 -> V_132 ;
struct V_12 V_2 ;
int V_59 = 0 ;
F_22 ( & V_55 -> V_140 ) ;
if ( ( V_212 -> V_2 != V_287 &&
V_55 -> V_60 != V_288 ) ||
( V_212 -> V_2 == V_287 &&
V_55 -> V_60 != V_289 ) )
goto V_121;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_212 -> V_2 ) {
case V_290 :
case V_291 :
V_2 . V_2 = V_292 ;
V_2 . V_16 = - V_293 ;
break;
case V_294 :
if ( V_55 -> V_6 . V_145 ) {
V_2 . V_16 = F_191 ( V_55 ) ;
V_2 . V_2 = V_2 . V_16 ? V_295 :
V_296 ;
} else {
V_2 . V_2 = V_297 ;
}
F_194 ( & V_2 , & V_212 -> V_17 . V_298 ,
V_212 -> V_20 ) ;
break;
case V_299 :
case V_300 :
V_2 . V_2 = V_296 ;
break;
case V_301 :
V_2 . V_16 = - V_293 ;
case V_302 :
case V_303 :
if ( ! F_33 ( V_55 , V_288 ,
V_289 ) )
goto V_121;
V_2 . V_2 = V_304 ;
break;
case V_287 :
V_2 . V_2 = V_305 ;
break;
case V_306 :
goto V_121;
case V_307 :
F_108 ( V_55 ) ;
V_2 . V_16 = V_212 -> V_17 . V_308 . V_7 ;
V_2 . V_2 = V_309 ;
V_2 . V_17 . V_18 . V_20 = V_212 -> V_20 ;
V_2 . V_17 . V_18 . V_19 = V_310 ;
break;
default:
F_196 ( L_7 ,
V_212 -> V_2 ) ;
goto V_121;
}
V_59 = V_55 -> V_6 . V_131 ( & V_55 -> V_6 , & V_2 ) ;
if ( V_59 ) {
V_55 -> V_180 . V_90 = NULL ;
F_34 ( V_55 , V_277 ) ;
F_24 ( & V_55 -> V_140 ) ;
F_177 ( & V_55 -> V_6 ) ;
return V_59 ;
}
V_121:
F_24 ( & V_55 -> V_140 ) ;
return V_59 ;
}
static struct V_54 * F_197 ( struct V_5 * V_197 ,
struct V_211 * V_212 ,
struct V_67 * V_230 )
{
struct V_54 * V_55 ;
struct V_5 * V_6 ;
struct V_311 * V_243 ;
const T_10 V_94 = V_197 -> V_78 . V_79 . V_92 . V_94 ;
const T_9 V_204 =
V_212 -> V_17 . V_217 . V_218 -> V_204 ;
int V_59 ;
V_6 = F_83 ( V_197 -> V_78 . V_79 . V_80 . V_22 ,
V_197 -> V_131 , V_197 -> V_132 ,
V_197 -> V_26 , V_212 -> V_17 . V_217 . V_134 ) ;
if ( F_100 ( V_6 ) )
return NULL ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( F_138 ( (struct V_91 * ) & V_6 -> V_78 . V_79 . V_92 ,
(struct V_91 * ) & V_6 -> V_78 . V_79 . V_93 ,
V_197 , V_212 , V_94 , V_204 ) )
goto V_161;
V_243 = & V_6 -> V_78 ;
V_243 -> V_312 = V_212 -> V_17 . V_217 . V_313 ? 2 : 1 ;
V_243 -> V_279 = F_198 ( sizeof * V_243 -> V_279 * V_243 -> V_312 ,
V_39 ) ;
if ( ! V_243 -> V_279 )
goto V_161;
V_243 -> V_279 [ 0 ] = * V_212 -> V_17 . V_217 . V_218 ;
if ( V_243 -> V_312 == 2 )
V_243 -> V_279 [ 1 ] = * V_212 -> V_17 . V_217 . V_313 ;
if ( V_230 ) {
V_59 = F_199 ( & V_243 -> V_79 . V_80 , V_230 , NULL ) ;
if ( V_59 )
goto V_161;
} else {
if ( ! F_162 ( V_197 ) &&
F_124 ( F_55 ( V_55 ) ) ) {
V_243 -> V_79 . V_80 . V_102 = V_103 ;
F_63 ( & V_243 -> V_79 . V_80 , & V_243 -> V_279 [ 0 ] . V_124 ) ;
F_64 ( & V_243 -> V_79 . V_80 , F_140 ( V_243 -> V_279 [ 0 ] . V_126 ) ) ;
} else if ( ! F_124 ( F_55 ( V_55 ) ) ) {
V_59 = F_66 ( F_55 ( V_55 ) , & V_243 -> V_79 . V_80 ) ;
if ( V_59 )
goto V_161;
}
}
F_200 ( & V_243 -> V_79 . V_80 , & V_243 -> V_279 [ 0 ] . V_125 ) ;
V_55 -> V_60 = V_288 ;
return V_55 ;
V_161:
F_177 ( V_6 ) ;
return NULL ;
}
static struct V_54 * F_201 ( struct V_5 * V_197 ,
struct V_211 * V_212 ,
struct V_67 * V_230 )
{
struct V_54 * V_55 ;
struct V_5 * V_6 ;
const T_10 V_94 = V_197 -> V_78 . V_79 . V_92 . V_94 ;
struct V_22 * V_22 = V_197 -> V_78 . V_79 . V_80 . V_22 ;
int V_59 ;
V_6 = F_83 ( V_22 , V_197 -> V_131 , V_197 -> V_132 ,
V_197 -> V_26 , V_160 ) ;
if ( F_100 ( V_6 ) )
return NULL ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( F_138 ( (struct V_91 * ) & V_6 -> V_78 . V_79 . V_92 ,
(struct V_91 * ) & V_6 -> V_78 . V_79 . V_93 ,
V_197 , V_212 , V_94 ,
V_212 -> V_17 . V_226 . V_204 ) )
goto V_161;
if ( V_230 ) {
V_59 = F_199 ( & V_6 -> V_78 . V_79 . V_80 , V_230 , NULL ) ;
if ( V_59 )
goto V_161;
} else {
if ( ! F_124 ( F_55 ( V_55 ) ) ) {
V_59 = F_66 ( F_55 ( V_55 ) ,
& V_6 -> V_78 . V_79 . V_80 ) ;
if ( V_59 )
goto V_161;
}
}
V_55 -> V_60 = V_288 ;
return V_55 ;
V_161:
F_177 ( V_6 ) ;
return NULL ;
}
static void F_202 ( struct V_12 * V_2 ,
struct V_222 * V_314 ,
void * V_20 , int V_315 )
{
V_2 -> V_17 . V_18 . V_20 = V_20 + V_315 ;
V_2 -> V_17 . V_18 . V_19 = V_316 - V_315 ;
V_2 -> V_17 . V_18 . V_170 = V_314 -> V_170 ;
V_2 -> V_17 . V_18 . V_172 = V_314 -> V_172 ;
V_2 -> V_17 . V_18 . V_284 = V_314 -> V_284 ;
V_2 -> V_17 . V_18 . V_317 = V_314 -> V_317 ;
V_2 -> V_17 . V_18 . V_285 = V_314 -> V_285 ;
V_2 -> V_17 . V_18 . V_163 = V_314 -> V_163 ;
V_2 -> V_17 . V_18 . V_162 = V_314 -> V_286 ;
}
static int F_203 ( struct V_5 * V_6 , struct V_211 * V_212 )
{
return ( ( ( V_212 -> V_2 == V_216 ) &&
( V_212 -> V_17 . V_217 . V_134 == V_6 -> V_134 ) ) ||
( ( V_212 -> V_2 == V_219 ) &&
( V_6 -> V_134 == V_160 ) ) ||
( ! V_6 -> V_134 ) ) ;
}
static int F_204 ( struct V_265 * V_180 , struct V_211 * V_212 )
{
struct V_54 * V_197 , * V_318 = NULL ;
struct V_12 V_2 ;
struct V_67 * V_230 ;
int V_315 , V_59 ;
V_197 = F_167 ( V_180 , V_212 , & V_230 ) ;
if ( F_100 ( V_197 ) )
return F_101 ( V_197 ) ;
if ( ! F_203 ( & V_197 -> V_6 , V_212 ) ) {
V_59 = - V_49 ;
goto V_319;
}
F_22 ( & V_197 -> V_140 ) ;
if ( V_197 -> V_60 != V_273 ) {
V_59 = - V_320 ;
goto V_321;
}
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_315 = F_169 ( V_197 ) ;
V_2 . V_2 = V_322 ;
if ( V_212 -> V_2 == V_219 ) {
V_318 = F_201 ( & V_197 -> V_6 , V_212 , V_230 ) ;
V_2 . V_17 . V_323 . V_20 = V_212 -> V_20 + V_315 ;
V_2 . V_17 . V_323 . V_19 =
V_324 - V_315 ;
} else {
V_318 = F_197 ( & V_197 -> V_6 , V_212 , V_230 ) ;
F_202 ( & V_2 , & V_212 -> V_17 . V_217 ,
V_212 -> V_20 , V_315 ) ;
}
if ( ! V_318 ) {
V_59 = - V_135 ;
goto V_321;
}
F_205 ( & V_318 -> V_140 , V_325 ) ;
V_59 = F_75 ( V_318 , V_197 ) ;
if ( V_59 )
goto V_326;
V_318 -> V_180 . V_90 = V_180 ;
V_180 -> V_132 = V_318 ;
V_180 -> V_327 = F_195 ;
F_20 ( & V_318 -> V_42 ) ;
V_59 = V_318 -> V_6 . V_131 ( & V_318 -> V_6 , & V_2 ) ;
if ( V_59 )
goto V_328;
F_22 ( & V_46 ) ;
if ( F_30 ( V_318 , V_288 ) &&
( V_318 -> V_6 . V_134 != V_160 ) )
F_206 ( V_180 , V_329 , NULL , 0 ) ;
F_24 ( & V_46 ) ;
F_24 ( & V_318 -> V_140 ) ;
F_24 ( & V_197 -> V_140 ) ;
F_82 ( V_318 ) ;
if ( V_230 )
F_73 ( V_230 ) ;
return 0 ;
V_328:
F_82 ( V_318 ) ;
V_318 -> V_180 . V_90 = NULL ;
V_326:
F_34 ( V_318 , V_277 ) ;
F_24 ( & V_318 -> V_140 ) ;
V_321:
F_24 ( & V_197 -> V_140 ) ;
if ( V_318 )
F_177 ( & V_318 -> V_6 ) ;
V_319:
if ( V_230 )
F_73 ( V_230 ) ;
return V_59 ;
}
T_9 F_207 ( struct V_5 * V_6 , struct V_91 * V_79 )
{
if ( V_79 -> V_106 == V_107 )
return ( (struct V_99 * ) V_79 ) -> V_195 ;
return F_133 ( ( ( V_330 ) V_6 -> V_26 << 16 ) + F_140 ( F_128 ( V_79 ) ) ) ;
}
static int F_208 ( struct V_331 * V_332 , struct V_333 * V_334 )
{
struct V_54 * V_55 = V_332 -> V_132 ;
struct V_12 V_2 ;
int V_59 = 0 ;
struct V_91 * V_335 = (struct V_91 * ) & V_334 -> V_336 ;
struct V_91 * V_337 = (struct V_91 * ) & V_334 -> V_338 ;
F_22 ( & V_55 -> V_140 ) ;
if ( V_55 -> V_60 != V_288 )
goto V_121;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_334 -> V_2 ) {
case V_339 :
V_2 . V_2 = V_304 ;
break;
case V_340 :
memcpy ( F_55 ( V_55 ) , V_335 ,
F_209 ( V_335 ) ) ;
memcpy ( F_56 ( V_55 ) , V_337 ,
F_209 ( V_337 ) ) ;
switch ( V_334 -> V_16 ) {
case 0 :
V_2 . V_2 = V_296 ;
V_2 . V_17 . V_18 . V_172 = V_334 -> V_341 ;
V_2 . V_17 . V_18 . V_170 = V_334 -> V_342 ;
break;
case - V_343 :
case - V_11 :
V_2 . V_2 = V_309 ;
break;
case - V_293 :
V_2 . V_2 = V_292 ;
break;
default:
V_2 . V_2 = V_295 ;
break;
}
break;
case V_344 :
V_2 . V_2 = V_296 ;
V_2 . V_17 . V_18 . V_172 = V_334 -> V_341 ;
V_2 . V_17 . V_18 . V_170 = V_334 -> V_342 ;
break;
default:
F_106 ( 1 ) ;
}
V_2 . V_16 = V_334 -> V_16 ;
V_2 . V_17 . V_18 . V_20 = V_334 -> V_20 ;
V_2 . V_17 . V_18 . V_19 = V_334 -> V_19 ;
V_59 = V_55 -> V_6 . V_131 ( & V_55 -> V_6 , & V_2 ) ;
if ( V_59 ) {
V_55 -> V_180 . V_182 = NULL ;
F_34 ( V_55 , V_277 ) ;
F_24 ( & V_55 -> V_140 ) ;
F_177 ( & V_55 -> V_6 ) ;
return V_59 ;
}
V_121:
F_24 ( & V_55 -> V_140 ) ;
return V_59 ;
}
static int F_210 ( struct V_331 * V_180 ,
struct V_333 * V_334 )
{
struct V_5 * V_345 ;
struct V_54 * V_197 , * V_318 ;
struct V_12 V_2 ;
int V_59 = - V_320 ;
struct V_91 * V_335 = (struct V_91 * ) & V_334 -> V_336 ;
struct V_91 * V_337 = (struct V_91 * ) & V_334 -> V_338 ;
V_197 = V_180 -> V_132 ;
F_22 ( & V_197 -> V_140 ) ;
if ( V_197 -> V_60 != V_273 )
goto V_121;
V_345 = F_83 ( V_197 -> V_6 . V_78 . V_79 . V_80 . V_22 ,
V_197 -> V_6 . V_131 ,
V_197 -> V_6 . V_132 ,
V_28 , V_346 ) ;
if ( F_100 ( V_345 ) ) {
V_59 = - V_135 ;
goto V_121;
}
V_318 = F_51 ( V_345 , struct V_54 , V_6 ) ;
F_205 ( & V_318 -> V_140 , V_325 ) ;
V_318 -> V_60 = V_288 ;
V_59 = F_67 ( V_335 , & V_318 -> V_6 . V_78 . V_79 . V_80 , NULL ) ;
if ( V_59 ) {
F_24 ( & V_318 -> V_140 ) ;
F_177 ( V_345 ) ;
goto V_121;
}
V_59 = F_75 ( V_318 , V_197 ) ;
if ( V_59 ) {
F_24 ( & V_318 -> V_140 ) ;
F_177 ( V_345 ) ;
goto V_121;
}
V_318 -> V_180 . V_182 = V_180 ;
V_180 -> V_132 = V_318 ;
V_180 -> V_327 = F_208 ;
memcpy ( F_55 ( V_318 ) , V_335 , F_209 ( V_335 ) ) ;
memcpy ( F_56 ( V_318 ) , V_337 , F_209 ( V_337 ) ) ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_322 ;
V_2 . V_17 . V_18 . V_20 = V_334 -> V_20 ;
V_2 . V_17 . V_18 . V_19 = V_334 -> V_19 ;
V_2 . V_17 . V_18 . V_172 = V_334 -> V_341 ;
V_2 . V_17 . V_18 . V_170 = V_334 -> V_342 ;
F_20 ( & V_318 -> V_42 ) ;
V_59 = V_318 -> V_6 . V_131 ( & V_318 -> V_6 , & V_2 ) ;
if ( V_59 ) {
V_318 -> V_180 . V_182 = NULL ;
F_34 ( V_318 , V_277 ) ;
F_24 ( & V_318 -> V_140 ) ;
F_82 ( V_318 ) ;
F_177 ( & V_318 -> V_6 ) ;
goto V_121;
}
F_24 ( & V_318 -> V_140 ) ;
F_82 ( V_318 ) ;
V_121:
F_24 ( & V_197 -> V_140 ) ;
return V_59 ;
}
static int F_211 ( struct V_54 * V_55 )
{
struct V_91 * V_79 ;
struct V_265 * V_6 ;
T_9 V_347 ;
V_79 = F_55 ( V_55 ) ;
V_347 = F_207 ( & V_55 -> V_6 , V_79 ) ;
V_6 = F_212 ( V_55 -> V_6 . V_8 , F_204 , V_347 ) ;
if ( F_100 ( V_6 ) )
return F_101 ( V_6 ) ;
V_55 -> V_180 . V_90 = V_6 ;
return 0 ;
}
static int F_213 ( struct V_54 * V_55 , int V_348 )
{
int V_59 ;
struct V_331 * V_6 ;
V_6 = F_214 ( V_55 -> V_6 . V_8 ,
F_210 ,
V_55 ) ;
if ( F_100 ( V_6 ) )
return F_101 ( V_6 ) ;
V_6 -> V_349 = V_55 -> V_349 ;
V_55 -> V_180 . V_182 = V_6 ;
memcpy ( & V_55 -> V_180 . V_182 -> V_336 , F_55 ( V_55 ) ,
F_209 ( F_55 ( V_55 ) ) ) ;
V_59 = F_215 ( V_55 -> V_180 . V_182 , V_348 ) ;
if ( V_59 ) {
F_188 ( V_55 -> V_180 . V_182 ) ;
V_55 -> V_180 . V_182 = NULL ;
}
return V_59 ;
}
static int F_216 ( struct V_5 * V_6 ,
struct V_12 * V_2 )
{
struct V_54 * V_55 = V_6 -> V_132 ;
V_6 -> V_132 = V_55 -> V_6 . V_132 ;
V_6 -> V_131 = V_55 -> V_6 . V_131 ;
return V_55 -> V_6 . V_131 ( V_6 , V_2 ) ;
}
static void F_217 ( struct V_54 * V_55 ,
struct V_40 * V_41 )
{
struct V_54 * V_269 ;
struct V_5 * V_6 ;
struct V_22 * V_22 = V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ;
int V_59 ;
if ( F_57 ( V_55 ) == V_107 && ! F_112 ( V_41 -> V_8 , 1 ) )
return;
V_6 = F_83 ( V_22 , F_216 , V_55 , V_55 -> V_6 . V_26 ,
V_55 -> V_6 . V_134 ) ;
if ( F_100 ( V_6 ) )
return;
V_269 = F_51 ( V_6 , struct V_54 , V_6 ) ;
V_269 -> V_60 = V_350 ;
memcpy ( F_55 ( V_269 ) , F_55 ( V_55 ) ,
F_209 ( F_55 ( V_55 ) ) ) ;
F_43 ( V_269 , V_41 ) ;
F_45 ( & V_269 -> V_141 , & V_55 -> V_141 ) ;
F_20 ( & V_55 -> V_42 ) ;
V_269 -> V_278 = 1 ;
V_269 -> V_258 = V_55 -> V_258 ;
V_59 = F_218 ( V_6 , V_55 -> V_348 ) ;
if ( V_59 )
F_219 ( L_8 ,
V_59 , V_41 -> V_8 -> V_351 ) ;
}
static void F_220 ( struct V_54 * V_55 )
{
struct V_40 * V_41 ;
F_22 ( & V_46 ) ;
F_45 ( & V_55 -> V_83 , & V_352 ) ;
F_23 (cma_dev, &dev_list, list)
F_217 ( V_55 , V_41 ) ;
F_24 ( & V_46 ) ;
}
void F_221 ( struct V_5 * V_6 , int V_349 )
{
struct V_54 * V_55 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
V_55 -> V_349 = ( T_3 ) V_349 ;
}
static void F_222 ( int V_16 , struct V_198 * V_279 ,
void * V_132 )
{
struct V_353 * V_354 = V_132 ;
struct V_311 * V_78 ;
V_78 = & V_354 -> V_6 -> V_6 . V_78 ;
if ( ! V_16 ) {
V_78 -> V_312 = 1 ;
* V_78 -> V_279 = * V_279 ;
} else {
V_354 -> V_355 = V_272 ;
V_354 -> V_356 = V_357 ;
V_354 -> V_2 . V_2 = V_358 ;
V_354 -> V_2 . V_16 = V_16 ;
}
F_223 ( V_359 , & V_354 -> V_354 ) ;
}
static int F_224 ( struct V_54 * V_55 , int V_360 ,
struct V_353 * V_354 )
{
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
struct V_198 V_279 ;
T_11 V_361 ;
struct V_189 * V_362 ;
struct V_99 * V_100 ;
memset ( & V_279 , 0 , sizeof V_279 ) ;
F_225 ( V_80 , & V_279 . V_124 ) ;
F_226 ( V_80 , & V_279 . V_125 ) ;
V_279 . V_126 = F_227 ( F_111 ( V_80 ) ) ;
V_279 . V_363 = 1 ;
V_279 . V_364 = 1 ;
V_279 . V_204 = F_207 ( & V_55 -> V_6 , F_56 ( V_55 ) ) ;
V_361 = V_365 | V_366 |
V_367 | V_368 |
V_369 | V_370 ;
switch ( F_57 ( V_55 ) ) {
case V_184 :
V_279 . V_371 = F_227 ( ( T_6 ) V_55 -> V_349 ) ;
V_361 |= V_372 ;
break;
case V_188 :
V_362 = (struct V_189 * ) F_55 ( V_55 ) ;
V_279 . V_373 = ( T_3 ) ( F_61 ( V_362 -> V_374 ) >> 20 ) ;
V_361 |= V_375 ;
break;
case V_107 :
V_100 = (struct V_99 * ) F_55 ( V_55 ) ;
V_279 . V_373 = ( T_3 ) ( F_61 ( V_100 -> V_202 ) >> 20 ) ;
V_361 |= V_375 ;
break;
}
V_55 -> V_268 = F_228 ( & V_376 , V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 , & V_279 ,
V_361 , V_360 ,
V_39 , F_222 ,
V_354 , & V_55 -> V_267 ) ;
return ( V_55 -> V_268 < 0 ) ? V_55 -> V_268 : 0 ;
}
static void F_229 ( struct V_377 * V_378 )
{
struct V_353 * V_354 = F_51 ( V_378 , struct V_353 , V_354 ) ;
struct V_54 * V_55 = V_354 -> V_6 ;
int V_379 = 0 ;
F_22 ( & V_55 -> V_140 ) ;
if ( ! F_33 ( V_55 , V_354 -> V_355 , V_354 -> V_356 ) )
goto V_121;
if ( V_55 -> V_6 . V_131 ( & V_55 -> V_6 , & V_354 -> V_2 ) ) {
F_34 ( V_55 , V_277 ) ;
V_379 = 1 ;
}
V_121:
F_24 ( & V_55 -> V_140 ) ;
F_82 ( V_55 ) ;
if ( V_379 )
F_177 ( & V_55 -> V_6 ) ;
F_52 ( V_354 ) ;
}
static void F_230 ( struct V_377 * V_378 )
{
struct V_380 * V_354 = F_51 ( V_378 , struct V_380 , V_354 ) ;
struct V_54 * V_55 = V_354 -> V_6 ;
int V_379 = 0 ;
F_22 ( & V_55 -> V_140 ) ;
if ( V_55 -> V_60 == V_277 ||
V_55 -> V_60 == V_381 )
goto V_121;
if ( V_55 -> V_6 . V_131 ( & V_55 -> V_6 , & V_354 -> V_2 ) ) {
F_34 ( V_55 , V_277 ) ;
V_379 = 1 ;
}
V_121:
F_24 ( & V_55 -> V_140 ) ;
F_82 ( V_55 ) ;
if ( V_379 )
F_177 ( & V_55 -> V_6 ) ;
F_52 ( V_354 ) ;
}
static int F_231 ( struct V_54 * V_55 , int V_360 )
{
struct V_311 * V_78 = & V_55 -> V_6 . V_78 ;
struct V_353 * V_354 ;
int V_59 ;
V_354 = F_84 ( sizeof *V_354 , V_39 ) ;
if ( ! V_354 )
return - V_135 ;
V_354 -> V_6 = V_55 ;
F_232 ( & V_354 -> V_354 , F_229 ) ;
V_354 -> V_355 = V_272 ;
V_354 -> V_356 = V_382 ;
V_354 -> V_2 . V_2 = V_383 ;
V_78 -> V_279 = F_198 ( sizeof * V_78 -> V_279 , V_39 ) ;
if ( ! V_78 -> V_279 ) {
V_59 = - V_135 ;
goto V_321;
}
V_59 = F_224 ( V_55 , V_360 , V_354 ) ;
if ( V_59 )
goto V_326;
return 0 ;
V_326:
F_52 ( V_78 -> V_279 ) ;
V_78 -> V_279 = NULL ;
V_321:
F_52 ( V_354 ) ;
return V_59 ;
}
int F_233 ( struct V_5 * V_6 ,
struct V_198 * V_279 , int V_312 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_33 ( V_55 , V_357 ,
V_382 ) )
return - V_49 ;
V_6 -> V_78 . V_279 = F_234 ( V_279 , sizeof *V_279 * V_312 ,
V_39 ) ;
if ( ! V_6 -> V_78 . V_279 ) {
V_59 = - V_135 ;
goto V_161;
}
V_6 -> V_78 . V_312 = V_312 ;
return 0 ;
V_161:
F_33 ( V_55 , V_382 , V_357 ) ;
return V_59 ;
}
static int F_235 ( struct V_54 * V_55 , int V_360 )
{
struct V_353 * V_354 ;
V_354 = F_84 ( sizeof *V_354 , V_39 ) ;
if ( ! V_354 )
return - V_135 ;
V_354 -> V_6 = V_55 ;
F_232 ( & V_354 -> V_354 , F_229 ) ;
V_354 -> V_355 = V_272 ;
V_354 -> V_356 = V_382 ;
V_354 -> V_2 . V_2 = V_383 ;
F_223 ( V_359 , & V_354 -> V_354 ) ;
return 0 ;
}
static int F_236 ( struct V_67 * V_68 , int V_349 )
{
int V_384 ;
struct V_67 * V_245 ;
V_384 = F_237 ( V_349 ) ;
V_245 = V_68 -> V_385 & V_386 ?
F_238 ( V_68 ) : V_68 ;
if ( V_245 -> V_387 )
return F_239 ( V_245 , V_384 ) ;
#if F_151 ( V_388 )
if ( V_68 -> V_385 & V_386 )
return ( F_240 ( V_68 , V_384 ) &
V_389 ) >> V_390 ;
#endif
return 0 ;
}
static enum V_51 F_241 ( enum V_391 V_392 ,
unsigned long V_52 ,
enum V_51 V_393 )
{
if ( ( V_392 == V_394 ||
V_392 == V_395 ) &&
F_242 ( V_396 , & V_52 ) )
return V_396 ;
return V_393 ;
}
static int F_243 ( struct V_54 * V_55 )
{
struct V_311 * V_78 = & V_55 -> V_6 . V_78 ;
struct V_264 * V_79 = & V_78 -> V_79 ;
struct V_353 * V_354 ;
int V_59 ;
struct V_67 * V_68 = NULL ;
V_354 = F_84 ( sizeof *V_354 , V_39 ) ;
if ( ! V_354 )
return - V_135 ;
V_354 -> V_6 = V_55 ;
F_232 ( & V_354 -> V_354 , F_229 ) ;
V_78 -> V_279 = F_84 ( sizeof * V_78 -> V_279 , V_39 ) ;
if ( ! V_78 -> V_279 ) {
V_59 = - V_135 ;
goto V_321;
}
V_78 -> V_312 = 1 ;
if ( V_79 -> V_80 . V_120 ) {
unsigned long V_52 ;
V_68 = F_71 ( & V_111 , V_79 -> V_80 . V_120 ) ;
if ( ! V_68 ) {
V_59 = - V_76 ;
goto V_326;
}
if ( V_68 -> V_58 & V_112 ) {
F_73 ( V_68 ) ;
if ( ! V_55 -> V_6 . V_8 -> V_113 ) {
V_59 = - V_114 ;
goto V_326;
}
V_68 = V_55 -> V_6 . V_8 -> V_113 ( V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 ) ;
if ( ! V_68 ) {
V_59 = - V_76 ;
goto V_326;
}
}
V_78 -> V_279 -> V_22 = & V_111 ;
V_78 -> V_279 -> V_238 = V_68 -> V_238 ;
V_52 = F_28 ( V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 ) ;
V_78 -> V_279 -> V_77 =
F_241 ( V_79 -> V_80 . V_397 ,
V_52 ,
V_55 -> V_77 ) ;
}
if ( ! V_68 ) {
V_59 = - V_76 ;
goto V_326;
}
memcpy ( V_78 -> V_279 -> V_398 , V_79 -> V_80 . V_399 , V_400 ) ;
F_76 ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_92 ,
& V_78 -> V_279 -> V_124 ) ;
F_76 ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_93 ,
& V_78 -> V_279 -> V_125 ) ;
if ( V_78 -> V_279 -> V_77 < F_244 ( V_79 -> V_80 . V_397 ) )
V_78 -> V_279 -> V_77 = F_244 ( V_79 -> V_80 . V_397 ) ;
if ( ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_93 ) -> V_106 != V_107 )
V_78 -> V_279 -> V_401 = V_79 -> V_80 . V_402 ;
else
V_78 -> V_279 -> V_401 = 1 ;
V_78 -> V_279 -> V_364 = 1 ;
V_78 -> V_279 -> V_126 = F_227 ( 0xffff ) ;
V_78 -> V_279 -> V_403 = V_404 ;
V_78 -> V_279 -> V_405 = F_236 ( V_68 , V_55 -> V_349 ) ;
V_78 -> V_279 -> V_406 = F_245 ( V_68 -> V_406 ) ;
V_78 -> V_279 -> V_407 = V_404 ;
V_78 -> V_279 -> V_408 = F_246 ( V_68 ) ;
F_73 ( V_68 ) ;
V_78 -> V_279 -> V_409 = V_404 ;
V_78 -> V_279 -> V_410 = V_411 ;
if ( ! V_78 -> V_279 -> V_406 ) {
V_59 = - V_49 ;
goto V_326;
}
V_354 -> V_355 = V_272 ;
V_354 -> V_356 = V_382 ;
V_354 -> V_2 . V_2 = V_383 ;
V_354 -> V_2 . V_16 = 0 ;
F_223 ( V_359 , & V_354 -> V_354 ) ;
return 0 ;
V_326:
F_52 ( V_78 -> V_279 ) ;
V_78 -> V_279 = NULL ;
V_321:
F_52 ( V_354 ) ;
return V_59 ;
}
int F_247 ( struct V_5 * V_6 , int V_360 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_33 ( V_55 , V_357 , V_272 ) )
return - V_49 ;
F_20 ( & V_55 -> V_42 ) ;
if ( F_171 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_231 ( V_55 , V_360 ) ;
else if ( F_70 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_243 ( V_55 ) ;
else if ( F_6 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_235 ( V_55 , V_360 ) ;
else
V_59 = - V_183 ;
if ( V_59 )
goto V_161;
return 0 ;
V_161:
F_33 ( V_55 , V_272 , V_357 ) ;
F_82 ( V_55 ) ;
return V_59 ;
}
static void F_248 ( struct V_91 * V_79 )
{
switch ( V_79 -> V_106 ) {
case V_184 :
( (struct V_185 * ) V_79 ) -> V_186 . V_187 = F_249 ( V_412 ) ;
break;
case V_188 :
F_250 ( & ( (struct V_189 * ) V_79 ) -> V_190 ,
0 , 0 , 0 , F_249 ( 1 ) ) ;
break;
default:
F_251 ( & ( (struct V_99 * ) V_79 ) -> V_104 ,
0 , 0 , 0 , F_249 ( 1 ) ) ;
break;
}
}
static int F_252 ( struct V_54 * V_55 )
{
struct V_40 * V_41 , * V_123 ;
struct V_413 V_414 ;
union V_69 V_108 ;
T_6 V_126 ;
int V_59 ;
T_3 V_15 ;
V_41 = NULL ;
F_22 ( & V_46 ) ;
F_23 (cur_dev, &dev_list, list) {
if ( F_57 ( V_55 ) == V_107 &&
! F_112 ( V_123 -> V_8 , 1 ) )
continue;
if ( ! V_41 )
V_41 = V_123 ;
for ( V_15 = 1 ; V_15 <= V_123 -> V_8 -> V_122 ; ++ V_15 ) {
if ( ! F_253 ( V_123 -> V_8 , V_15 , & V_414 ) &&
V_414 . V_60 == V_415 ) {
V_41 = V_123 ;
goto V_416;
}
}
}
if ( ! V_41 ) {
V_59 = - V_76 ;
goto V_121;
}
V_15 = 1 ;
V_416:
V_59 = F_81 ( V_41 -> V_8 , V_15 , 0 , & V_108 , NULL ) ;
if ( V_59 )
goto V_121;
V_59 = F_254 ( V_41 -> V_8 , V_15 , 0 , & V_126 ) ;
if ( V_59 )
goto V_121;
V_55 -> V_6 . V_78 . V_79 . V_80 . V_102 =
( F_69 ( V_41 -> V_8 , V_15 ) ) ?
V_103 : V_110 ;
F_63 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , & V_108 ) ;
F_64 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , V_126 ) ;
V_55 -> V_6 . V_9 = V_15 ;
F_46 ( V_55 , V_41 ) ;
F_248 ( F_55 ( V_55 ) ) ;
V_121:
F_24 ( & V_46 ) ;
return V_59 ;
}
static void F_255 ( int V_16 , struct V_91 * V_92 ,
struct V_101 * V_80 , void * V_132 )
{
struct V_54 * V_55 = V_132 ;
struct V_12 V_2 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
F_22 ( & V_55 -> V_140 ) ;
if ( ! F_33 ( V_55 , V_271 ,
V_357 ) )
goto V_121;
memcpy ( F_55 ( V_55 ) , V_92 , F_209 ( V_92 ) ) ;
if ( ! V_16 && ! V_55 -> V_41 )
V_16 = F_75 ( V_55 , NULL ) ;
if ( V_16 ) {
if ( ! F_33 ( V_55 , V_357 ,
V_350 ) )
goto V_121;
V_2 . V_2 = V_417 ;
V_2 . V_16 = V_16 ;
} else
V_2 . V_2 = V_418 ;
if ( V_55 -> V_6 . V_131 ( & V_55 -> V_6 , & V_2 ) ) {
F_34 ( V_55 , V_277 ) ;
F_24 ( & V_55 -> V_140 ) ;
F_82 ( V_55 ) ;
F_177 ( & V_55 -> V_6 ) ;
return;
}
V_121:
F_24 ( & V_55 -> V_140 ) ;
F_82 ( V_55 ) ;
}
static int F_256 ( struct V_54 * V_55 )
{
struct V_353 * V_354 ;
union V_69 V_108 ;
int V_59 ;
V_354 = F_84 ( sizeof *V_354 , V_39 ) ;
if ( ! V_354 )
return - V_135 ;
if ( ! V_55 -> V_41 ) {
V_59 = F_252 ( V_55 ) ;
if ( V_59 )
goto V_161;
}
F_225 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , & V_108 ) ;
F_200 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , & V_108 ) ;
V_354 -> V_6 = V_55 ;
F_232 ( & V_354 -> V_354 , F_229 ) ;
V_354 -> V_355 = V_271 ;
V_354 -> V_356 = V_357 ;
V_354 -> V_2 . V_2 = V_418 ;
F_223 ( V_359 , & V_354 -> V_354 ) ;
return 0 ;
V_161:
F_52 ( V_354 ) ;
return V_59 ;
}
static int F_257 ( struct V_54 * V_55 )
{
struct V_353 * V_354 ;
int V_59 ;
V_354 = F_84 ( sizeof *V_354 , V_39 ) ;
if ( ! V_354 )
return - V_135 ;
if ( ! V_55 -> V_41 ) {
V_59 = F_78 ( V_55 ) ;
if ( V_59 )
goto V_161;
}
F_200 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , (union V_69 * )
& ( ( (struct V_99 * ) & V_55 -> V_6 . V_78 . V_79 . V_93 ) -> V_104 ) ) ;
V_354 -> V_6 = V_55 ;
F_232 ( & V_354 -> V_354 , F_229 ) ;
V_354 -> V_355 = V_271 ;
V_354 -> V_356 = V_357 ;
V_354 -> V_2 . V_2 = V_418 ;
F_223 ( V_359 , & V_354 -> V_354 ) ;
return 0 ;
V_161:
F_52 ( V_354 ) ;
return V_59 ;
}
static int F_258 ( struct V_5 * V_6 , struct V_91 * V_92 ,
struct V_91 * V_93 )
{
if ( ! V_92 || ! V_92 -> V_106 ) {
V_92 = (struct V_91 * ) & V_6 -> V_78 . V_79 . V_92 ;
V_92 -> V_106 = V_93 -> V_106 ;
if ( F_151 ( V_239 ) &&
V_93 -> V_106 == V_188 ) {
struct V_189 * V_419 = (struct V_189 * ) V_92 ;
struct V_189 * V_420 = (struct V_189 * ) V_93 ;
V_419 -> V_421 = V_420 -> V_421 ;
if ( F_152 ( & V_420 -> V_190 ) & V_241 )
V_6 -> V_78 . V_79 . V_80 . V_120 = V_420 -> V_421 ;
} else if ( V_93 -> V_106 == V_107 ) {
( (struct V_99 * ) V_92 ) -> V_105 =
( (struct V_99 * ) V_93 ) -> V_105 ;
}
}
return F_259 ( V_6 , V_92 ) ;
}
int F_260 ( struct V_5 * V_6 , struct V_91 * V_92 ,
struct V_91 * V_93 , int V_360 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( V_55 -> V_60 == V_138 ) {
V_59 = F_258 ( V_6 , V_92 , V_93 ) ;
if ( V_59 )
return V_59 ;
}
if ( F_57 ( V_55 ) != V_93 -> V_106 )
return - V_49 ;
if ( ! F_33 ( V_55 , V_350 , V_271 ) )
return - V_49 ;
F_20 ( & V_55 -> V_42 ) ;
memcpy ( F_56 ( V_55 ) , V_93 , F_209 ( V_93 ) ) ;
if ( F_124 ( V_93 ) ) {
V_59 = F_256 ( V_55 ) ;
} else {
if ( V_93 -> V_106 == V_107 ) {
V_59 = F_257 ( V_55 ) ;
} else {
V_59 = F_261 ( & V_422 , F_55 ( V_55 ) ,
V_93 , & V_6 -> V_78 . V_79 . V_80 ,
V_360 , F_255 , V_55 ) ;
}
}
if ( V_59 )
goto V_161;
return 0 ;
V_161:
F_33 ( V_55 , V_271 , V_350 ) ;
F_82 ( V_55 ) ;
return V_59 ;
}
int F_262 ( struct V_5 * V_6 , int V_423 )
{
struct V_54 * V_55 ;
unsigned long V_58 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
F_31 ( & V_55 -> V_46 , V_58 ) ;
if ( V_423 || V_55 -> V_60 == V_138 ) {
V_55 -> V_424 = V_423 ;
V_59 = 0 ;
} else {
V_59 = - V_49 ;
}
F_32 ( & V_55 -> V_46 , V_58 ) ;
return V_59 ;
}
int F_263 ( struct V_5 * V_6 , int V_258 )
{
struct V_54 * V_55 ;
unsigned long V_58 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
F_31 ( & V_55 -> V_46 , V_58 ) ;
if ( V_55 -> V_60 == V_138 || V_55 -> V_60 == V_350 ) {
V_55 -> V_425 |= ( 1 << V_426 ) ;
V_55 -> V_258 = V_258 ;
V_59 = 0 ;
} else {
V_59 = - V_49 ;
}
F_32 ( & V_55 -> V_46 , V_58 ) ;
return V_59 ;
}
static void F_264 ( struct V_36 * V_37 ,
struct V_54 * V_55 )
{
struct V_91 * V_79 ;
struct V_99 * V_100 ;
V_330 V_427 , V_428 ;
T_8 V_47 ;
V_79 = F_55 ( V_55 ) ;
V_47 = F_129 ( V_37 -> V_47 ) ;
switch ( V_79 -> V_106 ) {
case V_184 :
( (struct V_185 * ) V_79 ) -> V_193 = V_47 ;
break;
case V_188 :
( (struct V_189 * ) V_79 ) -> V_194 = V_47 ;
break;
case V_107 :
V_100 = (struct V_99 * ) V_79 ;
V_427 = F_130 ( V_100 -> V_195 ) ;
V_428 = F_130 ( V_100 -> V_196 ) ;
V_100 -> V_195 = F_133 ( ( V_427 & V_428 ) | ( V_330 ) F_65 ( V_47 ) ) ;
V_100 -> V_196 = F_133 ( ~ 0ULL ) ;
break;
}
V_55 -> V_37 = V_37 ;
F_265 ( & V_55 -> V_274 , & V_37 -> V_275 ) ;
}
static int F_266 ( enum V_25 V_26 ,
struct V_54 * V_55 , unsigned short V_38 )
{
struct V_36 * V_37 ;
int V_59 ;
V_37 = F_84 ( sizeof *V_37 , V_39 ) ;
if ( ! V_37 )
return - V_135 ;
V_59 = F_13 ( V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 , V_26 , V_37 ,
V_38 ) ;
if ( V_59 < 0 )
goto V_161;
V_37 -> V_26 = V_26 ;
V_37 -> V_47 = ( unsigned short ) V_59 ;
F_264 ( V_37 , V_55 ) ;
return 0 ;
V_161:
F_52 ( V_37 ) ;
return V_59 == - V_429 ? - V_430 : V_59 ;
}
static int F_267 ( enum V_25 V_26 ,
struct V_54 * V_55 )
{
static unsigned int V_431 ;
int V_432 , V_433 , V_434 ;
unsigned int V_435 ;
struct V_22 * V_22 = V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ;
F_268 ( V_22 , & V_432 , & V_433 ) ;
V_434 = ( V_433 - V_432 ) + 1 ;
V_435 = F_269 () % V_434 + V_432 ;
V_436:
if ( V_431 != V_435 &&
! F_15 ( V_22 , V_26 , ( unsigned short ) V_435 ) ) {
int V_59 = F_266 ( V_26 , V_55 , V_435 ) ;
if ( ! V_59 )
V_431 = V_435 ;
if ( V_59 != - V_430 )
return V_59 ;
}
if ( -- V_434 ) {
V_435 ++ ;
if ( ( V_435 < V_432 ) || ( V_435 > V_433 ) )
V_435 = V_432 ;
goto V_436;
}
return - V_430 ;
}
static int F_270 ( struct V_36 * V_37 ,
struct V_54 * V_55 , T_12 V_424 )
{
struct V_54 * V_437 ;
struct V_91 * V_79 , * V_438 ;
V_79 = F_55 ( V_55 ) ;
F_166 (cur_id, &bind_list->owners, node) {
if ( V_55 == V_437 )
continue;
if ( ( V_437 -> V_60 != V_273 ) && V_424 &&
V_437 -> V_424 )
continue;
V_438 = F_55 ( V_437 ) ;
if ( V_55 -> V_258 && V_437 -> V_258 &&
( V_79 -> V_106 != V_438 -> V_106 ) )
continue;
if ( F_124 ( V_79 ) || F_124 ( V_438 ) )
return - V_430 ;
if ( ! F_125 ( V_79 , V_438 ) )
return - V_439 ;
}
return 0 ;
}
static int F_271 ( enum V_25 V_26 ,
struct V_54 * V_55 )
{
struct V_36 * V_37 ;
unsigned short V_38 ;
int V_59 ;
V_38 = F_65 ( F_128 ( F_55 ( V_55 ) ) ) ;
if ( V_38 < V_440 && ! F_272 ( V_441 ) )
return - V_442 ;
V_37 = F_15 ( V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 , V_26 , V_38 ) ;
if ( ! V_37 ) {
V_59 = F_266 ( V_26 , V_55 , V_38 ) ;
} else {
V_59 = F_270 ( V_37 , V_55 , V_55 -> V_424 ) ;
if ( ! V_59 )
F_264 ( V_37 , V_55 ) ;
}
return V_59 ;
}
static int F_273 ( struct V_54 * V_55 )
{
struct V_36 * V_37 = V_55 -> V_37 ;
int V_59 = 0 ;
F_22 ( & V_46 ) ;
if ( V_37 -> V_275 . V_443 -> V_270 )
V_59 = F_270 ( V_37 , V_55 , 0 ) ;
F_24 ( & V_46 ) ;
return V_59 ;
}
static enum V_25 F_274 (
struct V_54 * V_55 )
{
switch ( V_55 -> V_6 . V_26 ) {
case V_28 :
case V_30 :
case V_32 :
case V_34 :
return V_55 -> V_6 . V_26 ;
default:
return 0 ;
}
}
static enum V_25 F_275 ( struct V_54 * V_55 )
{
enum V_25 V_26 = 0 ;
struct V_99 * V_100 ;
V_330 V_444 , V_428 , V_427 ;
V_100 = (struct V_99 * ) F_55 ( V_55 ) ;
V_428 = F_130 ( V_100 -> V_196 ) & V_445 ;
V_427 = F_130 ( V_100 -> V_195 ) & V_428 ;
if ( ( V_55 -> V_6 . V_26 == V_34 ) && ( V_427 == ( V_446 & V_428 ) ) ) {
V_444 = V_446 ;
V_26 = V_34 ;
} else if ( ( ( V_55 -> V_6 . V_26 == V_34 ) || ( V_55 -> V_6 . V_26 == V_28 ) ) &&
( V_427 == ( V_447 & V_428 ) ) ) {
V_444 = V_447 ;
V_26 = V_28 ;
} else if ( ( ( V_55 -> V_6 . V_26 == V_34 ) || ( V_55 -> V_6 . V_26 == V_30 ) ) &&
( V_427 == ( V_448 & V_428 ) ) ) {
V_444 = V_448 ;
V_26 = V_30 ;
}
if ( V_26 ) {
V_100 -> V_195 = F_133 ( V_444 | F_65 ( F_128 ( (struct V_91 * ) V_100 ) ) ) ;
V_100 -> V_196 = F_133 ( V_445 |
F_130 ( V_100 -> V_196 ) ) ;
}
return V_26 ;
}
static int F_276 ( struct V_54 * V_55 )
{
enum V_25 V_26 ;
int V_59 ;
if ( F_57 ( V_55 ) != V_107 )
V_26 = F_274 ( V_55 ) ;
else
V_26 = F_275 ( V_55 ) ;
if ( ! V_26 )
return - V_449 ;
F_22 ( & V_46 ) ;
if ( F_131 ( F_55 ( V_55 ) ) )
V_59 = F_267 ( V_26 , V_55 ) ;
else
V_59 = F_271 ( V_26 , V_55 ) ;
F_24 ( & V_46 ) ;
return V_59 ;
}
static int F_277 ( struct V_101 * V_80 ,
struct V_91 * V_79 )
{
#if F_151 ( V_239 )
struct V_189 * V_362 ;
if ( V_79 -> V_106 != V_188 )
return 0 ;
V_362 = (struct V_189 * ) V_79 ;
if ( ! ( F_152 ( & V_362 -> V_190 ) & V_241 ) )
return 0 ;
if ( ! V_362 -> V_421 )
return - V_49 ;
V_80 -> V_120 = V_362 -> V_421 ;
#endif
return 0 ;
}
int F_218 ( struct V_5 * V_6 , int V_348 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( V_55 -> V_60 == V_138 ) {
V_6 -> V_78 . V_79 . V_92 . V_94 = V_184 ;
V_59 = F_259 ( V_6 , F_55 ( V_55 ) ) ;
if ( V_59 )
return V_59 ;
}
if ( ! F_33 ( V_55 , V_350 , V_273 ) )
return - V_49 ;
if ( V_55 -> V_424 ) {
V_59 = F_273 ( V_55 ) ;
if ( V_59 )
goto V_161;
}
V_55 -> V_348 = V_348 ;
if ( V_6 -> V_8 ) {
if ( F_112 ( V_6 -> V_8 , 1 ) ) {
V_59 = F_211 ( V_55 ) ;
if ( V_59 )
goto V_161;
} else if ( F_114 ( V_6 -> V_8 , 1 ) ) {
V_59 = F_213 ( V_55 , V_348 ) ;
if ( V_59 )
goto V_161;
} else {
V_59 = - V_183 ;
goto V_161;
}
} else
F_220 ( V_55 ) ;
return 0 ;
V_161:
V_55 -> V_348 = 0 ;
F_33 ( V_55 , V_273 , V_350 ) ;
return V_59 ;
}
int F_259 ( struct V_5 * V_6 , struct V_91 * V_79 )
{
struct V_54 * V_55 ;
int V_59 ;
if ( V_79 -> V_106 != V_184 && V_79 -> V_106 != V_188 &&
V_79 -> V_106 != V_107 )
return - V_215 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_33 ( V_55 , V_138 , V_350 ) )
return - V_49 ;
V_59 = F_277 ( & V_6 -> V_78 . V_79 . V_80 , V_79 ) ;
if ( V_59 )
goto V_321;
memcpy ( F_55 ( V_55 ) , V_79 , F_209 ( V_79 ) ) ;
if ( ! F_124 ( V_79 ) ) {
V_59 = F_66 ( V_79 , & V_6 -> V_78 . V_79 . V_80 ) ;
if ( V_59 )
goto V_321;
V_59 = F_75 ( V_55 , NULL ) ;
if ( V_59 )
goto V_321;
}
if ( ! ( V_55 -> V_425 & ( 1 << V_426 ) ) ) {
if ( V_79 -> V_106 == V_184 )
V_55 -> V_258 = 1 ;
#if F_151 ( V_239 )
else if ( V_79 -> V_106 == V_188 ) {
struct V_22 * V_22 = V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ;
V_55 -> V_258 = V_22 -> V_450 . V_451 . V_452 ;
}
#endif
}
V_59 = F_276 ( V_55 ) ;
if ( V_59 )
goto V_326;
return 0 ;
V_326:
if ( V_55 -> V_41 )
F_53 ( V_55 ) ;
V_321:
F_33 ( V_55 , V_350 , V_138 ) ;
return V_59 ;
}
static int F_278 ( void * V_64 , struct V_54 * V_55 )
{
struct V_63 * V_63 ;
V_63 = V_64 ;
V_63 -> V_213 = V_214 ;
if ( F_57 ( V_55 ) == V_184 ) {
struct V_185 * V_453 , * V_454 ;
V_453 = (struct V_185 * ) F_55 ( V_55 ) ;
V_454 = (struct V_185 * ) F_56 ( V_55 ) ;
F_36 ( V_63 , 4 ) ;
V_63 -> V_92 . V_208 . V_79 = V_453 -> V_186 . V_187 ;
V_63 -> V_93 . V_208 . V_79 = V_454 -> V_186 . V_187 ;
V_63 -> V_47 = V_453 -> V_193 ;
} else if ( F_57 ( V_55 ) == V_188 ) {
struct V_189 * V_455 , * V_456 ;
V_455 = (struct V_189 * ) F_55 ( V_55 ) ;
V_456 = (struct V_189 * ) F_56 ( V_55 ) ;
F_36 ( V_63 , 6 ) ;
V_63 -> V_92 . V_210 = V_455 -> V_190 ;
V_63 -> V_93 . V_210 = V_456 -> V_190 ;
V_63 -> V_47 = V_455 -> V_194 ;
}
return 0 ;
}
static int F_279 ( struct V_265 * V_180 ,
struct V_211 * V_212 )
{
struct V_54 * V_55 = V_180 -> V_132 ;
struct V_12 V_2 ;
struct V_457 * V_458 = & V_212 -> V_17 . V_459 ;
int V_59 = 0 ;
F_22 ( & V_55 -> V_140 ) ;
if ( V_55 -> V_60 != V_288 )
goto V_121;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_212 -> V_2 ) {
case V_460 :
V_2 . V_2 = V_292 ;
V_2 . V_16 = - V_293 ;
break;
case V_461 :
V_2 . V_17 . V_323 . V_20 = V_212 -> V_20 ;
V_2 . V_17 . V_323 . V_19 = V_462 ;
if ( V_458 -> V_16 != V_463 ) {
V_2 . V_2 = V_292 ;
V_2 . V_16 = V_212 -> V_17 . V_459 . V_16 ;
break;
}
V_59 = F_58 ( V_55 , V_458 -> V_95 ) ;
if ( V_59 ) {
V_2 . V_2 = V_417 ;
V_2 . V_16 = V_59 ;
break;
}
F_280 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ,
V_55 -> V_6 . V_78 . V_279 ,
& V_2 . V_17 . V_323 . V_166 ) ;
V_2 . V_17 . V_323 . V_162 = V_458 -> V_464 ;
V_2 . V_17 . V_323 . V_95 = V_458 -> V_95 ;
V_2 . V_2 = V_296 ;
V_2 . V_16 = 0 ;
break;
default:
F_196 ( L_7 ,
V_212 -> V_2 ) ;
goto V_121;
}
V_59 = V_55 -> V_6 . V_131 ( & V_55 -> V_6 , & V_2 ) ;
if ( V_59 ) {
V_55 -> V_180 . V_90 = NULL ;
F_34 ( V_55 , V_277 ) ;
F_24 ( & V_55 -> V_140 ) ;
F_177 ( & V_55 -> V_6 ) ;
return V_59 ;
}
V_121:
F_24 ( & V_55 -> V_140 ) ;
return V_59 ;
}
static int F_281 ( struct V_54 * V_55 ,
struct V_164 * V_165 )
{
struct V_465 V_221 ;
struct V_265 * V_6 ;
void * V_20 ;
int V_315 , V_59 ;
memset ( & V_221 , 0 , sizeof V_221 ) ;
V_315 = F_169 ( V_55 ) ;
V_221 . V_19 = V_315 + V_165 -> V_19 ;
if ( V_221 . V_19 < V_165 -> V_19 )
return - V_49 ;
if ( V_221 . V_19 ) {
V_20 = F_84 ( V_221 . V_19 , V_466 ) ;
if ( ! V_20 )
return - V_135 ;
} else {
V_20 = NULL ;
}
if ( V_165 -> V_20 && V_165 -> V_19 )
memcpy ( V_20 + V_315 , V_165 -> V_20 ,
V_165 -> V_19 ) ;
if ( V_20 ) {
V_59 = F_278 ( V_20 , V_55 ) ;
if ( V_59 )
goto V_121;
V_221 . V_20 = V_20 ;
}
V_6 = F_282 ( V_55 -> V_6 . V_8 , F_279 ,
V_55 ) ;
if ( F_100 ( V_6 ) ) {
V_59 = F_101 ( V_6 ) ;
goto V_121;
}
V_55 -> V_180 . V_90 = V_6 ;
V_221 . V_199 = V_55 -> V_6 . V_78 . V_279 ;
V_221 . V_204 = F_207 ( & V_55 -> V_6 , F_56 ( V_55 ) ) ;
V_221 . V_360 = 1 << ( V_467 - 8 ) ;
V_221 . V_468 = V_469 ;
V_59 = F_283 ( V_55 -> V_180 . V_90 , & V_221 ) ;
if ( V_59 ) {
F_187 ( V_55 -> V_180 . V_90 ) ;
V_55 -> V_180 . V_90 = NULL ;
}
V_121:
F_52 ( V_20 ) ;
return V_59 ;
}
static int F_284 ( struct V_54 * V_55 ,
struct V_164 * V_165 )
{
struct V_470 V_221 ;
struct V_311 * V_78 ;
void * V_20 ;
struct V_265 * V_6 ;
int V_315 , V_59 ;
memset ( & V_221 , 0 , sizeof V_221 ) ;
V_315 = F_169 ( V_55 ) ;
V_221 . V_19 = V_315 + V_165 -> V_19 ;
if ( V_221 . V_19 < V_165 -> V_19 )
return - V_49 ;
if ( V_221 . V_19 ) {
V_20 = F_84 ( V_221 . V_19 , V_466 ) ;
if ( ! V_20 )
return - V_135 ;
} else {
V_20 = NULL ;
}
if ( V_165 -> V_20 && V_165 -> V_19 )
memcpy ( V_20 + V_315 , V_165 -> V_20 ,
V_165 -> V_19 ) ;
V_6 = F_282 ( V_55 -> V_6 . V_8 , F_195 , V_55 ) ;
if ( F_100 ( V_6 ) ) {
V_59 = F_101 ( V_6 ) ;
goto V_121;
}
V_55 -> V_180 . V_90 = V_6 ;
V_78 = & V_55 -> V_6 . V_78 ;
if ( V_20 ) {
V_59 = F_278 ( V_20 , V_55 ) ;
if ( V_59 )
goto V_121;
V_221 . V_20 = V_20 ;
}
V_221 . V_218 = & V_78 -> V_279 [ 0 ] ;
if ( V_78 -> V_312 == 2 )
V_221 . V_313 = & V_78 -> V_279 [ 1 ] ;
V_221 . V_204 = F_207 ( & V_55 -> V_6 , F_56 ( V_55 ) ) ;
V_221 . V_162 = V_55 -> V_162 ;
V_221 . V_134 = V_55 -> V_6 . V_134 ;
V_221 . V_471 = V_55 -> V_143 ;
V_221 . V_170 = V_165 -> V_170 ;
V_221 . V_172 = V_165 -> V_172 ;
V_221 . V_284 = V_165 -> V_284 ;
V_221 . V_317 = F_285 ( T_3 , 7 , V_165 -> V_317 ) ;
V_221 . V_285 = F_285 ( T_3 , 7 , V_165 -> V_285 ) ;
V_221 . V_472 = V_467 ;
V_221 . V_473 = V_467 ;
V_221 . V_468 = V_469 ;
V_221 . V_163 = V_55 -> V_163 ? 1 : 0 ;
V_59 = F_286 ( V_55 -> V_180 . V_90 , & V_221 ) ;
V_121:
if ( V_59 && ! F_100 ( V_6 ) ) {
F_187 ( V_6 ) ;
V_55 -> V_180 . V_90 = NULL ;
}
F_52 ( V_20 ) ;
return V_59 ;
}
static int F_287 ( struct V_54 * V_55 ,
struct V_164 * V_165 )
{
struct V_331 * V_180 ;
int V_59 ;
struct V_474 V_475 ;
V_180 = F_214 ( V_55 -> V_6 . V_8 , F_208 , V_55 ) ;
if ( F_100 ( V_180 ) )
return F_101 ( V_180 ) ;
V_180 -> V_349 = V_55 -> V_349 ;
V_55 -> V_180 . V_182 = V_180 ;
memcpy ( & V_180 -> V_336 , F_55 ( V_55 ) ,
F_209 ( F_55 ( V_55 ) ) ) ;
memcpy ( & V_180 -> V_338 , F_56 ( V_55 ) ,
F_209 ( F_56 ( V_55 ) ) ) ;
V_59 = F_104 ( V_55 , V_165 ) ;
if ( V_59 )
goto V_121;
if ( V_165 ) {
V_475 . V_342 = V_165 -> V_172 ;
V_475 . V_341 = V_165 -> V_170 ;
V_475 . V_20 = V_165 -> V_20 ;
V_475 . V_19 = V_165 -> V_19 ;
V_475 . V_464 = V_55 -> V_6 . V_145 ? V_55 -> V_162 : V_165 -> V_162 ;
} else {
memset ( & V_475 , 0 , sizeof V_475 ) ;
V_475 . V_464 = V_55 -> V_162 ;
}
V_59 = F_288 ( V_180 , & V_475 ) ;
V_121:
if ( V_59 ) {
F_188 ( V_180 ) ;
V_55 -> V_180 . V_182 = NULL ;
}
return V_59 ;
}
int F_289 ( struct V_5 * V_6 , struct V_164 * V_165 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_33 ( V_55 , V_382 , V_288 ) )
return - V_49 ;
if ( ! V_6 -> V_145 ) {
V_55 -> V_162 = V_165 -> V_162 ;
V_55 -> V_163 = V_165 -> V_163 ;
}
if ( F_112 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( V_6 -> V_134 == V_160 )
V_59 = F_281 ( V_55 , V_165 ) ;
else
V_59 = F_284 ( V_55 , V_165 ) ;
} else if ( F_114 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_287 ( V_55 , V_165 ) ;
else
V_59 = - V_183 ;
if ( V_59 )
goto V_161;
return 0 ;
V_161:
F_33 ( V_55 , V_288 , V_382 ) ;
return V_59 ;
}
static int F_290 ( struct V_54 * V_55 ,
struct V_164 * V_165 )
{
struct V_476 V_458 ;
int V_59 ;
V_59 = F_104 ( V_55 , V_165 ) ;
if ( V_59 )
goto V_121;
V_59 = F_107 ( V_55 , V_165 ) ;
if ( V_59 )
goto V_121;
memset ( & V_458 , 0 , sizeof V_458 ) ;
V_458 . V_162 = V_55 -> V_162 ;
V_458 . V_471 = V_55 -> V_143 ;
V_458 . V_20 = V_165 -> V_20 ;
V_458 . V_19 = V_165 -> V_19 ;
V_458 . V_170 = V_165 -> V_170 ;
V_458 . V_172 = V_165 -> V_172 ;
V_458 . V_477 = 0 ;
V_458 . V_284 = V_165 -> V_284 ;
V_458 . V_285 = F_285 ( T_3 , 7 , V_165 -> V_285 ) ;
V_458 . V_163 = V_55 -> V_163 ? 1 : 0 ;
V_59 = F_291 ( V_55 -> V_180 . V_90 , & V_458 ) ;
V_121:
return V_59 ;
}
static int F_292 ( struct V_54 * V_55 ,
struct V_164 * V_165 )
{
struct V_474 V_475 ;
int V_59 ;
V_59 = F_104 ( V_55 , V_165 ) ;
if ( V_59 )
return V_59 ;
V_475 . V_342 = V_165 -> V_172 ;
V_475 . V_341 = V_165 -> V_170 ;
V_475 . V_20 = V_165 -> V_20 ;
V_475 . V_19 = V_165 -> V_19 ;
if ( V_55 -> V_6 . V_145 ) {
V_475 . V_464 = V_55 -> V_162 ;
} else
V_475 . V_464 = V_165 -> V_162 ;
return F_293 ( V_55 -> V_180 . V_182 , & V_475 ) ;
}
static int F_294 ( struct V_54 * V_55 ,
enum V_478 V_16 , T_5 V_95 ,
const void * V_20 , int V_19 )
{
struct V_479 V_458 ;
int V_59 ;
memset ( & V_458 , 0 , sizeof V_458 ) ;
V_458 . V_16 = V_16 ;
if ( V_16 == V_463 ) {
V_59 = F_58 ( V_55 , V_95 ) ;
if ( V_59 )
return V_59 ;
V_458 . V_162 = V_55 -> V_162 ;
V_458 . V_95 = V_55 -> V_95 ;
}
V_458 . V_20 = V_20 ;
V_458 . V_19 = V_19 ;
return F_295 ( V_55 -> V_180 . V_90 , & V_458 ) ;
}
int F_296 ( struct V_5 * V_6 , struct V_164 * V_165 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
V_55 -> V_136 = F_86 ( V_137 ) ;
if ( ! F_30 ( V_55 , V_288 ) )
return - V_49 ;
if ( ! V_6 -> V_145 && V_165 ) {
V_55 -> V_162 = V_165 -> V_162 ;
V_55 -> V_163 = V_165 -> V_163 ;
}
if ( F_112 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( V_6 -> V_134 == V_160 ) {
if ( V_165 )
V_59 = F_294 ( V_55 , V_463 ,
V_165 -> V_95 ,
V_165 -> V_20 ,
V_165 -> V_19 ) ;
else
V_59 = F_294 ( V_55 , V_463 ,
0 , NULL , 0 ) ;
} else {
if ( V_165 )
V_59 = F_290 ( V_55 , V_165 ) ;
else
V_59 = F_191 ( V_55 ) ;
}
} else if ( F_114 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_292 ( V_55 , V_165 ) ;
else
V_59 = - V_183 ;
if ( V_59 )
goto V_280;
return 0 ;
V_280:
F_108 ( V_55 ) ;
F_297 ( V_6 , NULL , 0 ) ;
return V_59 ;
}
int F_298 ( struct V_5 * V_6 , enum V_480 V_2 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( ! V_55 -> V_180 . V_90 )
return - V_49 ;
switch ( V_6 -> V_8 -> V_82 ) {
case V_481 :
V_59 = F_299 ( V_55 -> V_180 . V_90 , V_2 ) ;
break;
default:
V_59 = 0 ;
break;
}
return V_59 ;
}
int F_297 ( struct V_5 * V_6 , const void * V_20 ,
T_3 V_19 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( ! V_55 -> V_180 . V_90 )
return - V_49 ;
if ( F_112 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( V_6 -> V_134 == V_160 )
V_59 = F_294 ( V_55 , V_482 , 0 ,
V_20 , V_19 ) ;
else
V_59 = F_193 ( V_55 -> V_180 . V_90 ,
V_10 , NULL ,
0 , V_20 , V_19 ) ;
} else if ( F_114 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
V_59 = F_300 ( V_55 -> V_180 . V_182 ,
V_20 , V_19 ) ;
} else
V_59 = - V_183 ;
return V_59 ;
}
int F_301 ( struct V_5 * V_6 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( ! V_55 -> V_180 . V_90 )
return - V_49 ;
if ( F_112 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
V_59 = F_108 ( V_55 ) ;
if ( V_59 )
goto V_121;
if ( F_302 ( V_55 -> V_180 . V_90 , NULL , 0 ) )
F_303 ( V_55 -> V_180 . V_90 , NULL , 0 ) ;
} else if ( F_114 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
V_59 = F_304 ( V_55 -> V_180 . V_182 , 0 ) ;
} else
V_59 = - V_49 ;
V_121:
return V_59 ;
}
static int F_305 ( int V_16 , struct V_483 * V_89 )
{
struct V_54 * V_55 ;
struct V_86 * V_87 = V_89 -> V_132 ;
struct V_12 V_2 ;
int V_59 = 0 ;
V_55 = V_87 -> V_55 ;
F_22 ( & V_55 -> V_140 ) ;
if ( V_55 -> V_60 != V_350 &&
V_55 -> V_60 != V_357 )
goto V_121;
if ( ! V_16 )
V_16 = F_58 ( V_55 , F_61 ( V_89 -> V_97 . V_95 ) ) ;
F_22 ( & V_55 -> V_139 ) ;
if ( ! V_16 && V_55 -> V_6 . V_145 )
V_16 = F_306 ( V_55 -> V_6 . V_145 , & V_89 -> V_97 . V_70 ,
F_140 ( V_89 -> V_97 . V_484 ) ) ;
F_24 ( & V_55 -> V_139 ) ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_16 = V_16 ;
V_2 . V_17 . V_323 . V_20 = V_87 -> V_132 ;
if ( ! V_16 ) {
struct V_101 * V_80 =
& V_55 -> V_6 . V_78 . V_79 . V_80 ;
struct V_67 * V_68 =
F_71 ( & V_111 , V_80 -> V_120 ) ;
enum V_51 V_77 =
V_55 -> V_41 -> V_50 [ V_55 -> V_6 . V_9 -
V_48 ( V_55 -> V_41 -> V_8 ) ] ;
V_2 . V_2 = V_485 ;
F_307 ( V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 , & V_89 -> V_97 ,
V_68 , V_77 ,
& V_2 . V_17 . V_323 . V_166 ) ;
V_2 . V_17 . V_323 . V_162 = 0xFFFFFF ;
V_2 . V_17 . V_323 . V_95 = F_61 ( V_89 -> V_97 . V_95 ) ;
if ( V_68 )
F_73 ( V_68 ) ;
} else
V_2 . V_2 = V_486 ;
V_59 = V_55 -> V_6 . V_131 ( & V_55 -> V_6 , & V_2 ) ;
if ( V_59 ) {
F_34 ( V_55 , V_277 ) ;
F_24 ( & V_55 -> V_140 ) ;
F_177 ( & V_55 -> V_6 ) ;
return 0 ;
}
V_121:
F_24 ( & V_55 -> V_140 ) ;
return 0 ;
}
static void F_308 ( struct V_54 * V_55 ,
struct V_91 * V_79 , union V_69 * V_70 )
{
unsigned char V_487 [ V_488 ] ;
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
struct V_185 * sin = (struct V_185 * ) V_79 ;
struct V_189 * V_362 = (struct V_189 * ) V_79 ;
if ( F_124 ( V_79 ) ) {
memset ( V_70 , 0 , sizeof *V_70 ) ;
} else if ( ( V_79 -> V_106 == V_188 ) &&
( ( F_61 ( V_362 -> V_190 . V_489 [ 0 ] ) & 0xFFF0FFFF ) ==
0xFF10A01B ) ) {
memcpy ( V_70 , & V_362 -> V_190 , sizeof *V_70 ) ;
} else if ( V_79 -> V_106 == V_107 ) {
memcpy ( V_70 , & ( (struct V_99 * ) V_79 ) -> V_104 , sizeof *V_70 ) ;
} else if ( ( V_79 -> V_106 == V_188 ) ) {
F_309 ( & V_362 -> V_190 , V_80 -> V_490 , V_487 ) ;
if ( V_55 -> V_6 . V_26 == V_30 )
V_487 [ 7 ] = 0x01 ;
* V_70 = * (union V_69 * ) ( V_487 + 4 ) ;
} else {
F_310 ( sin -> V_186 . V_187 , V_80 -> V_490 , V_487 ) ;
if ( V_55 -> V_6 . V_26 == V_30 )
V_487 [ 7 ] = 0x01 ;
* V_70 = * (union V_69 * ) ( V_487 + 4 ) ;
}
}
static void F_311 ( int V_16 ,
struct V_491 * V_97 ,
void * V_132 )
{
struct V_492 * V_493 = V_132 ;
F_312 ( ! V_132 ) ;
if ( V_16 || ! V_97 ) {
F_313 ( L_9 ,
V_493 -> V_8 -> V_351 , V_493 -> V_9 , V_16 ) ;
goto V_121;
}
memcpy ( V_493 -> V_494 , V_97 , sizeof( struct V_491 ) ) ;
V_121:
F_49 ( & V_493 -> V_495 ) ;
}
static int F_314 ( struct V_53 * V_8 , T_3 V_9 ,
struct V_491 * V_494 )
{
struct V_492 * V_493 ;
int V_59 ;
V_493 = F_198 ( sizeof( * V_493 ) , V_39 ) ;
if ( ! V_493 )
return - V_135 ;
V_493 -> V_8 = V_8 ;
V_493 -> V_494 = V_494 ;
V_493 -> V_9 = V_9 ;
F_89 ( & V_493 -> V_495 ) ;
V_59 = F_315 ( & V_376 , V_8 , V_9 ,
V_496 ,
V_39 , F_311 ,
V_493 , & V_493 -> V_497 ) ;
if ( V_59 < 0 ) {
F_196 ( L_10 ,
V_8 -> V_351 , V_9 , V_59 ) ;
goto V_121;
}
F_189 ( & V_493 -> V_495 ) ;
V_121:
F_52 ( V_493 ) ;
return V_59 ;
}
static int F_316 ( struct V_54 * V_55 ,
struct V_86 * V_87 )
{
struct V_96 V_97 ;
struct V_491 V_494 ;
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
T_11 V_361 ;
int V_59 ;
F_59 ( V_80 , & V_97 . V_70 ) ;
V_59 = F_60 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ,
& V_97 . V_70 , & V_97 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_58 ( V_55 , 0 ) ;
if ( V_59 )
return V_59 ;
F_308 ( V_55 , (struct V_91 * ) & V_87 -> V_79 , & V_97 . V_70 ) ;
V_97 . V_95 = F_317 ( V_55 -> V_95 ) ;
F_225 ( V_80 , & V_97 . V_498 ) ;
V_97 . V_126 = F_227 ( F_111 ( V_80 ) ) ;
V_97 . V_499 = V_87 -> V_499 ;
if ( V_97 . V_499 == F_318 ( V_500 ) ) {
V_59 = F_314 ( V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 ,
& V_494 ) ;
if ( V_59 )
return V_59 ;
if ( ! ( F_319 ( & V_494 ) &
V_501 ) ) {
F_219 ( L_11
L_12 ,
V_55 -> V_6 . V_8 -> V_351 , V_55 -> V_6 . V_9 ) ;
return - V_114 ;
}
}
V_361 = V_502 | V_503 |
V_504 | V_505 |
V_506 | V_507 |
V_508 |
V_509 ;
if ( V_55 -> V_6 . V_26 == V_32 )
V_361 |= V_510 |
V_511 |
V_512 |
V_513 |
V_514 ;
V_87 -> V_89 . V_90 = F_320 ( & V_376 , V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 , & V_97 ,
V_361 , V_39 ,
F_305 , V_87 ) ;
return F_321 ( V_87 -> V_89 . V_90 ) ;
}
static void F_322 ( struct V_377 * V_354 )
{
struct V_515 * V_516 = F_51 ( V_354 , struct V_515 , V_354 ) ;
struct V_86 * V_87 = V_516 -> V_87 ;
struct V_483 * V_517 = V_87 -> V_89 . V_90 ;
V_87 -> V_89 . V_90 -> V_132 = V_87 ;
F_305 ( 0 , V_517 ) ;
F_186 ( & V_87 -> V_88 , F_50 ) ;
F_52 ( V_516 ) ;
}
static void F_323 ( struct V_91 * V_79 , union V_69 * V_70 )
{
struct V_185 * sin = (struct V_185 * ) V_79 ;
struct V_189 * V_362 = (struct V_189 * ) V_79 ;
if ( F_124 ( V_79 ) ) {
memset ( V_70 , 0 , sizeof *V_70 ) ;
} else if ( V_79 -> V_106 == V_188 ) {
memcpy ( V_70 , & V_362 -> V_190 , sizeof *V_70 ) ;
} else {
V_70 -> V_75 [ 0 ] = 0xff ;
V_70 -> V_75 [ 1 ] = 0x0e ;
V_70 -> V_75 [ 2 ] = 0 ;
V_70 -> V_75 [ 3 ] = 0 ;
V_70 -> V_75 [ 4 ] = 0 ;
V_70 -> V_75 [ 5 ] = 0 ;
V_70 -> V_75 [ 6 ] = 0 ;
V_70 -> V_75 [ 7 ] = 0 ;
V_70 -> V_75 [ 8 ] = 0 ;
V_70 -> V_75 [ 9 ] = 0 ;
V_70 -> V_75 [ 10 ] = 0xff ;
V_70 -> V_75 [ 11 ] = 0xff ;
* ( V_74 * ) ( & V_70 -> V_75 [ 12 ] ) = sin -> V_186 . V_187 ;
}
}
static int F_324 ( struct V_54 * V_55 ,
struct V_86 * V_87 )
{
struct V_515 * V_354 ;
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
int V_161 = 0 ;
struct V_91 * V_79 = (struct V_91 * ) & V_87 -> V_79 ;
struct V_67 * V_68 = NULL ;
enum V_51 V_77 ;
bool V_518 ;
V_518 = V_87 -> V_499 == F_318 ( V_500 ) ;
if ( F_116 ( (struct V_91 * ) & V_87 -> V_79 ) )
return - V_49 ;
V_354 = F_84 ( sizeof *V_354 , V_39 ) ;
if ( ! V_354 )
return - V_135 ;
V_87 -> V_89 . V_90 = F_84 ( sizeof( struct V_483 ) , V_39 ) ;
if ( ! V_87 -> V_89 . V_90 ) {
V_161 = - V_135 ;
goto V_519;
}
F_323 ( V_79 , & V_87 -> V_89 . V_90 -> V_97 . V_70 ) ;
V_87 -> V_89 . V_90 -> V_97 . V_126 = F_227 ( 0xffff ) ;
if ( V_55 -> V_6 . V_26 == V_30 )
V_87 -> V_89 . V_90 -> V_97 . V_95 = F_317 ( V_98 ) ;
if ( V_80 -> V_120 )
V_68 = F_71 ( & V_111 , V_80 -> V_120 ) ;
if ( ! V_68 ) {
V_161 = - V_76 ;
goto V_520;
}
V_87 -> V_89 . V_90 -> V_97 . V_408 = F_246 ( V_68 ) ;
V_87 -> V_89 . V_90 -> V_97 . V_401 = 1 ;
V_87 -> V_89 . V_90 -> V_97 . V_406 = F_245 ( V_68 -> V_406 ) ;
V_77 = V_55 -> V_41 -> V_50 [ V_55 -> V_6 . V_9 -
V_48 ( V_55 -> V_41 -> V_8 ) ] ;
if ( V_79 -> V_106 == V_184 ) {
if ( V_77 == V_396 ) {
V_87 -> V_89 . V_90 -> V_97 . V_401 = V_521 ;
if ( ! V_518 ) {
V_161 = F_37 ( V_68 , & V_87 -> V_89 . V_90 -> V_97 . V_70 ,
true ) ;
if ( ! V_161 )
V_87 -> V_276 = true ;
}
}
} else {
if ( V_77 == V_396 )
V_161 = - V_522 ;
}
F_73 ( V_68 ) ;
if ( V_161 || ! V_87 -> V_89 . V_90 -> V_97 . V_406 ) {
if ( ! V_161 )
V_161 = - V_49 ;
goto V_520;
}
F_76 ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_92 ,
& V_87 -> V_89 . V_90 -> V_97 . V_498 ) ;
V_354 -> V_6 = V_55 ;
V_354 -> V_87 = V_87 ;
F_232 ( & V_354 -> V_354 , F_322 ) ;
F_325 ( & V_87 -> V_88 ) ;
F_223 ( V_359 , & V_354 -> V_354 ) ;
return 0 ;
V_520:
F_52 ( V_87 -> V_89 . V_90 ) ;
V_519:
F_52 ( V_354 ) ;
return V_161 ;
}
int F_326 ( struct V_5 * V_6 , struct V_91 * V_79 ,
T_3 V_499 , void * V_132 )
{
struct V_54 * V_55 ;
struct V_86 * V_87 ;
int V_59 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_30 ( V_55 , V_350 ) &&
! F_30 ( V_55 , V_357 ) )
return - V_49 ;
V_87 = F_198 ( sizeof *V_87 , V_39 ) ;
if ( ! V_87 )
return - V_135 ;
memcpy ( & V_87 -> V_79 , V_79 , F_209 ( V_79 ) ) ;
V_87 -> V_132 = V_132 ;
V_87 -> V_55 = V_55 ;
V_87 -> V_276 = false ;
V_87 -> V_499 = V_499 ;
F_327 ( & V_55 -> V_46 ) ;
F_328 ( & V_87 -> V_83 , & V_55 -> V_142 ) ;
F_329 ( & V_55 -> V_46 ) ;
if ( F_70 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
F_330 ( & V_87 -> V_88 ) ;
V_59 = F_324 ( V_55 , V_87 ) ;
} else if ( F_184 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_316 ( V_55 , V_87 ) ;
else
V_59 = - V_183 ;
if ( V_59 ) {
F_331 ( & V_55 -> V_46 ) ;
F_54 ( & V_87 -> V_83 ) ;
F_332 ( & V_55 -> V_46 ) ;
F_52 ( V_87 ) ;
}
return V_59 ;
}
void F_333 ( struct V_5 * V_6 , struct V_91 * V_79 )
{
struct V_54 * V_55 ;
struct V_86 * V_87 ;
V_55 = F_51 ( V_6 , struct V_54 , V_6 ) ;
F_331 ( & V_55 -> V_46 ) ;
F_23 (mc, &id_priv->mc_list, list) {
if ( ! memcmp ( & V_87 -> V_79 , V_79 , F_209 ( V_79 ) ) ) {
F_54 ( & V_87 -> V_83 ) ;
F_332 ( & V_55 -> V_46 ) ;
if ( V_6 -> V_145 )
F_334 ( V_6 -> V_145 ,
& V_87 -> V_89 . V_90 -> V_97 . V_70 ,
F_140 ( V_87 -> V_89 . V_90 -> V_97 . V_484 ) ) ;
F_106 ( V_55 -> V_41 -> V_8 != V_6 -> V_8 ) ;
if ( F_184 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
F_185 ( V_87 -> V_89 . V_90 ) ;
F_52 ( V_87 ) ;
} else if ( F_70 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( V_87 -> V_276 ) {
struct V_101 * V_80 =
& V_6 -> V_78 . V_79 . V_80 ;
struct V_67 * V_68 = NULL ;
if ( V_80 -> V_120 )
V_68 = F_71 ( & V_111 ,
V_80 -> V_120 ) ;
if ( V_68 ) {
F_37 ( V_68 ,
& V_87 -> V_89 . V_90 -> V_97 . V_70 ,
false ) ;
F_73 ( V_68 ) ;
}
V_87 -> V_276 = false ;
}
F_186 ( & V_87 -> V_88 , F_50 ) ;
}
return;
}
}
F_332 ( & V_55 -> V_46 ) ;
}
static int F_335 ( struct V_67 * V_68 , struct V_54 * V_55 )
{
struct V_101 * V_80 ;
struct V_380 * V_354 ;
V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
if ( ( V_80 -> V_120 == V_68 -> V_238 ) &&
( F_164 ( F_147 ( V_68 ) , V_80 -> V_22 ) ) &&
memcmp ( V_80 -> V_119 , V_68 -> V_80 , V_68 -> V_523 ) ) {
F_72 ( L_13 ,
V_68 -> V_351 , & V_55 -> V_6 ) ;
V_354 = F_84 ( sizeof *V_354 , V_39 ) ;
if ( ! V_354 )
return - V_135 ;
F_232 ( & V_354 -> V_354 , F_230 ) ;
V_354 -> V_6 = V_55 ;
V_354 -> V_2 . V_2 = V_524 ;
F_20 ( & V_55 -> V_42 ) ;
F_223 ( V_359 , & V_354 -> V_354 ) ;
}
return 0 ;
}
static int F_336 ( struct V_525 * V_526 , unsigned long V_2 ,
void * V_527 )
{
struct V_67 * V_68 = F_337 ( V_527 ) ;
struct V_40 * V_41 ;
struct V_54 * V_55 ;
int V_59 = V_528 ;
if ( V_2 != V_529 )
return V_528 ;
if ( ! ( V_68 -> V_58 & V_530 ) || ! ( V_68 -> V_385 & V_531 ) )
return V_528 ;
F_22 ( & V_46 ) ;
F_23 (cma_dev, &dev_list, list)
F_23 (id_priv, &cma_dev->id_list, list) {
V_59 = F_335 ( V_68 , V_55 ) ;
if ( V_59 )
goto V_121;
}
V_121:
F_24 ( & V_46 ) ;
return V_59 ;
}
static void F_338 ( struct V_53 * V_8 )
{
struct V_40 * V_41 ;
struct V_54 * V_55 ;
unsigned int V_127 ;
unsigned long V_52 = 0 ;
V_41 = F_198 ( sizeof *V_41 , V_39 ) ;
if ( ! V_41 )
return;
V_41 -> V_8 = V_8 ;
V_41 -> V_50 = F_339 ( V_8 -> V_122 ,
sizeof( * V_41 -> V_50 ) ,
V_39 ) ;
if ( ! V_41 -> V_50 ) {
F_52 ( V_41 ) ;
return;
}
for ( V_127 = V_48 ( V_8 ) ; V_127 <= F_26 ( V_8 ) ; V_127 ++ ) {
V_52 = F_28 ( V_8 , V_127 ) ;
F_312 ( ! V_52 ) ;
V_41 -> V_50 [ V_127 - V_48 ( V_8 ) ] =
F_340 ( & V_52 , V_532 ) ;
}
F_89 ( & V_41 -> V_57 ) ;
F_90 ( & V_41 -> V_42 , 1 ) ;
F_91 ( & V_41 -> V_84 ) ;
F_341 ( V_8 , & V_533 , V_41 ) ;
F_22 ( & V_46 ) ;
F_45 ( & V_41 -> V_83 , & V_534 ) ;
F_23 (id_priv, &listen_any_list, list)
F_217 ( V_55 , V_41 ) ;
F_24 ( & V_46 ) ;
}
static int F_342 ( struct V_54 * V_55 )
{
struct V_12 V_2 ;
enum V_56 V_60 ;
int V_59 = 0 ;
V_60 = F_34 ( V_55 , V_381 ) ;
if ( V_60 == V_277 )
return 0 ;
F_178 ( V_55 , V_60 ) ;
F_22 ( & V_55 -> V_140 ) ;
if ( ! F_30 ( V_55 , V_381 ) )
goto V_121;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_535 ;
V_59 = V_55 -> V_6 . V_131 ( & V_55 -> V_6 , & V_2 ) ;
V_121:
F_24 ( & V_55 -> V_140 ) ;
return V_59 ;
}
static void F_343 ( struct V_40 * V_41 )
{
struct V_54 * V_55 ;
int V_59 ;
F_22 ( & V_46 ) ;
while ( ! F_174 ( & V_41 -> V_84 ) ) {
V_55 = F_175 ( V_41 -> V_84 . V_270 ,
struct V_54 , V_83 ) ;
F_54 ( & V_55 -> V_141 ) ;
F_176 ( & V_55 -> V_83 ) ;
F_20 ( & V_55 -> V_42 ) ;
F_24 ( & V_46 ) ;
V_59 = V_55 -> V_278 ? 1 : F_342 ( V_55 ) ;
F_82 ( V_55 ) ;
if ( V_59 )
F_177 ( & V_55 -> V_6 ) ;
F_22 ( & V_46 ) ;
}
F_24 ( & V_46 ) ;
F_47 ( V_41 ) ;
F_189 ( & V_41 -> V_57 ) ;
}
static void F_344 ( struct V_53 * V_8 , void * V_536 )
{
struct V_40 * V_41 = V_536 ;
if ( ! V_41 )
return;
F_22 ( & V_46 ) ;
F_54 ( & V_41 -> V_83 ) ;
F_24 ( & V_46 ) ;
F_343 ( V_41 ) ;
F_52 ( V_41 -> V_50 ) ;
F_52 ( V_41 ) ;
}
static int F_345 ( struct V_537 * V_538 , struct V_539 * V_540 )
{
struct V_541 * V_542 ;
struct V_543 * V_544 ;
struct V_54 * V_55 ;
struct V_5 * V_6 = NULL ;
struct V_40 * V_41 ;
int V_545 = 0 , V_546 = 0 ;
F_22 ( & V_46 ) ;
F_23 (cma_dev, &dev_list, list) {
if ( V_545 < V_540 -> args [ 0 ] ) {
V_545 ++ ;
continue;
}
V_546 = 0 ;
F_23 (id_priv, &cma_dev->id_list, list) {
if ( V_546 < V_540 -> args [ 1 ] ) {
V_546 ++ ;
continue;
}
V_544 = F_346 ( V_538 , & V_542 , V_540 -> V_542 -> V_547 ,
sizeof *V_544 , V_548 ,
V_549 ,
V_550 ) ;
if ( ! V_544 )
goto V_121;
memset ( V_544 , 0 , sizeof *V_544 ) ;
V_6 = & V_55 -> V_6 ;
V_544 -> V_82 = V_6 -> V_78 . V_79 . V_80 . V_102 ;
V_544 -> V_9 = V_6 -> V_9 ;
V_544 -> V_120 =
V_6 -> V_78 . V_79 . V_80 . V_120 ;
if ( F_347 ( V_538 , V_542 ,
F_209 ( F_55 ( V_55 ) ) ,
F_55 ( V_55 ) ,
V_551 ) )
goto V_121;
if ( F_347 ( V_538 , V_542 ,
F_209 ( F_55 ( V_55 ) ) ,
F_56 ( V_55 ) ,
V_552 ) )
goto V_121;
V_544 -> V_553 = V_55 -> V_136 ;
V_544 -> V_554 = V_6 -> V_26 ;
V_544 -> V_555 = V_55 -> V_60 ;
V_544 -> V_162 = V_55 -> V_162 ;
V_544 -> V_134 = V_6 -> V_134 ;
V_546 ++ ;
}
V_540 -> args [ 1 ] = 0 ;
V_545 ++ ;
}
V_121:
F_24 ( & V_46 ) ;
V_540 -> args [ 0 ] = V_545 ;
V_540 -> args [ 1 ] = V_546 ;
return V_538 -> V_556 ;
}
static int F_348 ( struct V_22 * V_22 )
{
struct V_21 * V_27 = V_21 ( V_22 ) ;
F_349 ( & V_27 -> V_29 ) ;
F_349 ( & V_27 -> V_31 ) ;
F_349 ( & V_27 -> V_33 ) ;
F_349 ( & V_27 -> V_35 ) ;
return 0 ;
}
static void F_350 ( struct V_22 * V_22 )
{
struct V_21 * V_27 = V_21 ( V_22 ) ;
F_351 ( & V_27 -> V_29 ) ;
F_351 ( & V_27 -> V_31 ) ;
F_351 ( & V_27 -> V_33 ) ;
F_351 ( & V_27 -> V_35 ) ;
}
static int T_13 F_352 ( void )
{
int V_59 ;
V_359 = F_353 ( L_14 , V_557 ) ;
if ( ! V_359 )
return - V_135 ;
V_59 = F_354 ( & V_558 ) ;
if ( V_59 )
goto V_559;
F_355 ( & V_376 ) ;
F_356 ( & V_422 ) ;
F_357 ( & V_560 ) ;
V_59 = F_358 ( & V_533 ) ;
if ( V_59 )
goto V_161;
if ( F_359 ( V_548 , F_2 ( V_561 ) ,
V_561 ) )
F_219 ( L_15 ) ;
F_360 () ;
return 0 ;
V_161:
F_361 ( & V_560 ) ;
F_362 ( & V_422 ) ;
F_363 ( & V_376 ) ;
V_559:
F_364 ( V_359 ) ;
return V_59 ;
}
static void T_14 F_365 ( void )
{
F_366 () ;
F_367 ( V_548 ) ;
F_368 ( & V_533 ) ;
F_361 ( & V_560 ) ;
F_362 ( & V_422 ) ;
F_363 ( & V_376 ) ;
F_369 ( & V_558 ) ;
F_364 ( V_359 ) ;
}
