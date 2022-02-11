const char * T_1 F_1 ( enum V_1 V_2 )
{
T_2 V_3 = V_2 ;
return ( V_3 < F_2 ( V_4 ) && V_4 [ V_3 ] ) ?
V_4 [ V_3 ] : L_1 ;
}
static struct V_5 * V_5 ( struct V_6 * V_6 )
{
return F_3 ( V_6 , V_7 ) ;
}
static struct V_8 * F_4 ( struct V_6 * V_6 , enum V_9 V_10 )
{
struct V_5 * V_11 = V_5 ( V_6 ) ;
switch ( V_10 ) {
case V_12 :
return & V_11 -> V_13 ;
case V_14 :
return & V_11 -> V_15 ;
case V_16 :
return & V_11 -> V_17 ;
case V_18 :
return & V_11 -> V_19 ;
default:
return NULL ;
}
}
static int F_5 ( struct V_6 * V_6 , enum V_9 V_10 ,
struct V_20 * V_21 , int V_22 )
{
struct V_8 * V_8 = F_4 ( V_6 , V_10 ) ;
return F_6 ( V_8 , V_21 , V_22 , V_22 + 1 , V_23 ) ;
}
static struct V_20 * F_7 ( struct V_6 * V_6 ,
enum V_9 V_10 , int V_22 )
{
struct V_8 * V_8 = F_4 ( V_6 , V_10 ) ;
return F_8 ( V_8 , V_22 ) ;
}
static void F_9 ( struct V_6 * V_6 , enum V_9 V_10 , int V_22 )
{
struct V_8 * V_8 = F_4 ( V_6 , V_10 ) ;
F_10 ( V_8 , V_22 ) ;
}
void F_11 ( struct V_24 * V_25 )
{
F_12 ( & V_25 -> V_26 ) ;
}
struct V_24 * F_13 ( T_3 V_27 ,
void * V_28 )
{
struct V_24 * V_25 ;
struct V_24 * V_29 = NULL ;
F_14 ( & V_30 ) ;
F_15 (cma_dev, &dev_list, list)
if ( V_27 ( V_25 -> V_31 , V_28 ) ) {
V_29 = V_25 ;
break;
}
if ( V_29 )
F_11 ( V_29 ) ;
F_16 ( & V_30 ) ;
return V_29 ;
}
int F_17 ( struct V_24 * V_25 ,
unsigned int V_32 )
{
if ( V_32 < V_33 ( V_25 -> V_31 ) ||
V_32 > F_18 ( V_25 -> V_31 ) )
return - V_34 ;
return V_25 -> V_35 [ V_32 - V_33 ( V_25 -> V_31 ) ] ;
}
int F_19 ( struct V_24 * V_25 ,
unsigned int V_32 ,
enum V_36 V_35 )
{
unsigned long V_37 ;
if ( V_32 < V_33 ( V_25 -> V_31 ) ||
V_32 > F_18 ( V_25 -> V_31 ) )
return - V_34 ;
V_37 = F_20 ( V_25 -> V_31 , V_32 ) ;
if ( ! ( V_37 & 1 << V_35 ) )
return - V_34 ;
V_25 -> V_35 [ V_32 - V_33 ( V_25 -> V_31 ) ] =
V_35 ;
return 0 ;
}
struct V_38 * F_21 ( struct V_24 * V_25 )
{
return V_25 -> V_31 ;
}
static int F_22 ( struct V_39 * V_40 , enum V_41 V_42 )
{
unsigned long V_43 ;
int V_44 ;
F_23 ( & V_40 -> V_30 , V_43 ) ;
V_44 = ( V_40 -> V_45 == V_42 ) ;
F_24 ( & V_40 -> V_30 , V_43 ) ;
return V_44 ;
}
static int F_25 ( struct V_39 * V_40 ,
enum V_41 V_42 , enum V_41 V_46 )
{
unsigned long V_43 ;
int V_44 ;
F_23 ( & V_40 -> V_30 , V_43 ) ;
if ( ( V_44 = ( V_40 -> V_45 == V_42 ) ) )
V_40 -> V_45 = V_46 ;
F_24 ( & V_40 -> V_30 , V_43 ) ;
return V_44 ;
}
static enum V_41 F_26 ( struct V_39 * V_40 ,
enum V_41 V_46 )
{
unsigned long V_43 ;
enum V_41 V_47 ;
F_23 ( & V_40 -> V_30 , V_43 ) ;
V_47 = V_40 -> V_45 ;
V_40 -> V_45 = V_46 ;
F_24 ( & V_40 -> V_30 , V_43 ) ;
return V_47 ;
}
static inline T_4 F_27 ( const struct V_48 * V_49 )
{
return V_49 -> V_50 >> 4 ;
}
static inline void F_28 ( struct V_48 * V_49 , T_4 V_51 )
{
V_49 -> V_50 = ( V_51 << 4 ) | ( V_49 -> V_50 & 0xF ) ;
}
static int F_29 ( struct V_52 * V_53 , union V_54 * V_55 , bool V_56 )
{
struct V_57 * V_58 = NULL ;
if ( V_53 ) {
F_30 () ;
V_58 = F_31 ( V_53 ) ;
if ( V_58 ) {
if ( V_56 )
F_32 ( V_58 ,
* ( V_59 * ) ( V_55 -> V_60 + 12 ) ) ;
else
F_33 ( V_58 ,
* ( V_59 * ) ( V_55 -> V_60 + 12 ) ) ;
}
F_34 () ;
}
return ( V_58 ) ? 0 : - V_61 ;
}
static void F_35 ( struct V_39 * V_40 ,
struct V_24 * V_25 )
{
F_11 ( V_25 ) ;
V_40 -> V_25 = V_25 ;
V_40 -> V_62 = 0 ;
V_40 -> V_63 . V_31 = V_25 -> V_31 ;
V_40 -> V_63 . V_64 . V_65 . V_66 . V_67 =
F_36 ( V_25 -> V_31 -> V_68 ) ;
F_37 ( & V_40 -> V_69 , & V_25 -> V_70 ) ;
}
static void F_38 ( struct V_39 * V_40 ,
struct V_24 * V_25 )
{
F_35 ( V_40 , V_25 ) ;
V_40 -> V_62 =
V_25 -> V_35 [ V_40 -> V_63 . V_71 -
V_33 ( V_25 -> V_31 ) ] ;
}
void F_39 ( struct V_24 * V_25 )
{
if ( F_40 ( & V_25 -> V_26 ) )
F_41 ( & V_25 -> V_42 ) ;
}
static inline void F_42 ( struct V_72 * V_72 )
{
struct V_73 * V_74 = F_43 ( V_72 , struct V_73 , V_75 ) ;
F_44 ( V_74 -> V_76 . V_77 ) ;
F_44 ( V_74 ) ;
}
static void F_45 ( struct V_39 * V_40 )
{
F_14 ( & V_30 ) ;
F_46 ( & V_40 -> V_69 ) ;
F_39 ( V_40 -> V_25 ) ;
V_40 -> V_25 = NULL ;
F_16 ( & V_30 ) ;
}
static inline struct V_78 * F_47 ( struct V_39 * V_40 )
{
return (struct V_78 * ) & V_40 -> V_63 . V_64 . V_65 . V_79 ;
}
static inline struct V_78 * F_48 ( struct V_39 * V_40 )
{
return (struct V_78 * ) & V_40 -> V_63 . V_64 . V_65 . V_80 ;
}
static inline unsigned short F_49 ( struct V_39 * V_40 )
{
return V_40 -> V_63 . V_64 . V_65 . V_79 . V_81 ;
}
static int F_50 ( struct V_39 * V_40 , T_5 V_82 )
{
struct V_83 V_84 ;
int V_44 = 0 ;
if ( V_40 -> V_82 ) {
if ( V_82 && V_40 -> V_82 != V_82 )
return - V_34 ;
return 0 ;
}
if ( V_82 ) {
V_40 -> V_82 = V_82 ;
return 0 ;
}
switch ( V_40 -> V_63 . V_10 ) {
case V_14 :
case V_18 :
V_40 -> V_82 = V_85 ;
break;
case V_16 :
F_51 ( & V_40 -> V_63 . V_64 . V_65 . V_66 , & V_84 . V_55 ) ;
V_44 = F_52 ( V_40 -> V_63 . V_31 ,
V_40 -> V_63 . V_71 , & V_84 . V_55 ,
& V_84 ) ;
if ( ! V_44 )
V_40 -> V_82 = F_53 ( V_84 . V_82 ) ;
break;
default:
break;
}
return V_44 ;
}
static void F_54 ( struct V_86 * V_87 , struct V_88 * V_66 )
{
V_66 -> V_89 = V_90 ;
F_55 ( V_66 , (union V_54 * ) & V_87 -> V_91 ) ;
F_56 ( V_66 , F_57 ( V_87 -> V_92 ) ) ;
}
static int F_58 ( struct V_78 * V_65 , struct V_88 * V_66 )
{
int V_44 ;
if ( V_65 -> V_93 != V_94 ) {
V_44 = F_59 ( V_65 , V_66 , NULL ) ;
} else {
F_54 ( (struct V_86 * ) V_65 , V_66 ) ;
V_44 = 0 ;
}
return V_44 ;
}
static inline int F_60 ( struct V_38 * V_31 , T_4 V_32 ,
enum V_36 V_62 ,
union V_54 * V_95 , int V_89 ,
int V_96 )
{
int V_44 = - V_61 ;
struct V_52 * V_53 = NULL ;
if ( ( V_89 == V_90 ) && ! F_61 ( V_31 , V_32 ) )
return V_44 ;
if ( ( V_89 != V_90 ) && F_61 ( V_31 , V_32 ) )
return V_44 ;
if ( V_89 == V_97 && F_62 ( V_31 , V_32 ) ) {
V_53 = F_63 ( & V_98 , V_96 ) ;
if ( V_53 && V_53 -> V_43 & V_99 ) {
F_64 ( L_2 ) ;
F_65 ( V_53 ) ;
if ( ! V_31 -> V_100 )
return - V_101 ;
V_53 = V_31 -> V_100 ( V_31 , V_32 ) ;
if ( ! V_53 )
return - V_61 ;
}
} else {
V_62 = V_102 ;
}
V_44 = F_66 ( V_31 , V_95 , V_62 , V_32 ,
V_53 , NULL ) ;
if ( V_53 )
F_65 ( V_53 ) ;
return V_44 ;
}
static int F_67 ( struct V_39 * V_40 ,
struct V_39 * V_103 )
{
struct V_88 * V_66 = & V_40 -> V_63 . V_64 . V_65 . V_66 ;
struct V_24 * V_25 ;
union V_54 V_95 , V_104 , * V_105 ;
int V_44 = - V_61 ;
T_4 V_32 ;
if ( V_66 -> V_89 != V_90 &&
V_40 -> V_63 . V_10 == V_16 )
return - V_34 ;
F_14 ( & V_30 ) ;
F_68 ( (struct V_78 * ) & V_40 -> V_63 . V_64 . V_65 . V_79 ,
& V_104 ) ;
memcpy ( & V_95 , V_66 -> V_106 +
F_69 ( V_66 ) , sizeof V_95 ) ;
if ( V_103 ) {
V_25 = V_103 -> V_25 ;
V_32 = V_103 -> V_63 . V_71 ;
V_105 = F_62 ( V_25 -> V_31 , V_32 ) ?
& V_104 : & V_95 ;
V_44 = F_60 ( V_25 -> V_31 , V_32 ,
F_61 ( V_25 -> V_31 , V_32 ) ?
V_102 :
V_103 -> V_62 , V_105 ,
V_66 -> V_89 ,
V_66 -> V_107 ) ;
if ( ! V_44 ) {
V_40 -> V_63 . V_71 = V_32 ;
goto V_108;
}
}
F_15 (cma_dev, &dev_list, list) {
for ( V_32 = 1 ; V_32 <= V_25 -> V_31 -> V_109 ; ++ V_32 ) {
if ( V_103 &&
V_103 -> V_25 == V_25 &&
V_103 -> V_63 . V_71 == V_32 )
continue;
V_105 = F_62 ( V_25 -> V_31 , V_32 ) ?
& V_104 : & V_95 ;
V_44 = F_60 ( V_25 -> V_31 , V_32 ,
F_61 ( V_25 -> V_31 , V_32 ) ?
V_102 :
V_25 -> V_35 [ V_32 - 1 ] ,
V_105 , V_66 -> V_89 ,
V_66 -> V_107 ) ;
if ( ! V_44 ) {
V_40 -> V_63 . V_71 = V_32 ;
goto V_108;
}
}
}
V_108:
if ( ! V_44 )
F_38 ( V_40 , V_25 ) ;
F_16 ( & V_30 ) ;
return V_44 ;
}
static int F_70 ( struct V_39 * V_40 )
{
struct V_24 * V_25 , * V_110 ;
struct V_86 * V_65 ;
union V_54 V_95 , V_111 , * V_112 ;
T_6 V_113 , V_3 ;
T_4 V_114 ;
int V_115 ;
V_25 = NULL ;
V_65 = (struct V_86 * ) F_48 ( V_40 ) ;
V_112 = (union V_54 * ) & V_65 -> V_91 ;
V_113 = F_57 ( V_65 -> V_92 ) ;
F_15 (cur_dev, &dev_list, list) {
for ( V_114 = 1 ; V_114 <= V_110 -> V_31 -> V_109 ; ++ V_114 ) {
if ( ! F_71 ( V_110 -> V_31 , V_114 ) )
continue;
if ( F_72 ( V_110 -> V_31 , V_114 , V_113 , & V_3 ) )
continue;
for ( V_115 = 0 ; ! F_73 ( V_110 -> V_31 , V_114 , V_115 ,
& V_95 , NULL ) ;
V_115 ++ ) {
if ( ! memcmp ( & V_95 , V_112 , sizeof( V_95 ) ) ) {
V_25 = V_110 ;
V_111 = V_95 ;
V_40 -> V_63 . V_71 = V_114 ;
goto V_116;
}
if ( ! V_25 && ( V_95 . V_117 . V_118 ==
V_112 -> V_117 . V_118 ) ) {
V_25 = V_110 ;
V_111 = V_95 ;
V_40 -> V_63 . V_71 = V_114 ;
}
}
}
}
if ( ! V_25 )
return - V_61 ;
V_116:
F_38 ( V_40 , V_25 ) ;
V_65 = (struct V_86 * ) F_47 ( V_40 ) ;
memcpy ( & V_65 -> V_91 , & V_111 , sizeof V_111 ) ;
F_54 ( V_65 , & V_40 -> V_63 . V_64 . V_65 . V_66 ) ;
return 0 ;
}
static void F_74 ( struct V_39 * V_40 )
{
if ( F_40 ( & V_40 -> V_26 ) )
F_41 ( & V_40 -> V_42 ) ;
}
static int F_75 ( struct V_39 * V_40 ,
enum V_41 V_45 )
{
F_14 ( & V_40 -> V_119 ) ;
if ( V_40 -> V_45 != V_45 ) {
F_16 ( & V_40 -> V_119 ) ;
return - V_34 ;
}
return 0 ;
}
struct V_120 * F_76 ( struct V_6 * V_6 ,
T_7 V_121 ,
void * V_122 , enum V_9 V_10 ,
enum V_123 V_124 )
{
struct V_39 * V_40 ;
V_40 = F_77 ( sizeof *V_40 , V_23 ) ;
if ( ! V_40 )
return F_78 ( - V_125 ) ;
V_40 -> V_126 = F_79 ( V_127 ) ;
V_40 -> V_45 = V_128 ;
V_40 -> V_63 . V_122 = V_122 ;
V_40 -> V_63 . V_121 = V_121 ;
V_40 -> V_63 . V_10 = V_10 ;
V_40 -> V_63 . V_124 = V_124 ;
F_80 ( & V_40 -> V_30 ) ;
F_81 ( & V_40 -> V_129 ) ;
F_82 ( & V_40 -> V_42 ) ;
F_83 ( & V_40 -> V_26 , 1 ) ;
F_81 ( & V_40 -> V_119 ) ;
F_84 ( & V_40 -> V_130 ) ;
F_84 ( & V_40 -> V_131 ) ;
F_85 ( & V_40 -> V_132 , sizeof V_40 -> V_132 ) ;
V_40 -> V_63 . V_64 . V_65 . V_66 . V_6 = F_86 ( V_6 ) ;
return & V_40 -> V_63 ;
}
static int F_87 ( struct V_39 * V_40 , struct V_133 * V_134 )
{
struct V_135 V_136 ;
int V_137 , V_44 ;
V_136 . V_138 = V_139 ;
V_44 = F_88 ( & V_40 -> V_63 , & V_136 , & V_137 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_89 ( V_134 , & V_136 , V_137 ) ;
if ( V_44 )
return V_44 ;
V_136 . V_138 = V_140 ;
V_44 = F_89 ( V_134 , & V_136 , V_141 ) ;
if ( V_44 )
return V_44 ;
V_136 . V_138 = V_142 ;
V_136 . V_143 = 0 ;
V_44 = F_89 ( V_134 , & V_136 , V_141 | V_144 ) ;
return V_44 ;
}
static int F_90 ( struct V_39 * V_40 , struct V_133 * V_134 )
{
struct V_135 V_136 ;
int V_137 , V_44 ;
V_136 . V_138 = V_139 ;
V_44 = F_88 ( & V_40 -> V_63 , & V_136 , & V_137 ) ;
if ( V_44 )
return V_44 ;
return F_89 ( V_134 , & V_136 , V_137 ) ;
}
int F_91 ( struct V_120 * V_63 , struct V_145 * V_146 ,
struct V_147 * V_148 )
{
struct V_39 * V_40 ;
struct V_133 * V_134 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( V_63 -> V_31 != V_146 -> V_31 )
return - V_34 ;
V_134 = F_92 ( V_146 , V_148 ) ;
if ( F_93 ( V_134 ) )
return F_94 ( V_134 ) ;
if ( V_63 -> V_124 == V_149 )
V_44 = F_87 ( V_40 , V_134 ) ;
else
V_44 = F_90 ( V_40 , V_134 ) ;
if ( V_44 )
goto V_150;
V_63 -> V_134 = V_134 ;
V_40 -> V_151 = V_134 -> V_151 ;
V_40 -> V_152 = ( V_134 -> V_152 != NULL ) ;
return 0 ;
V_150:
F_95 ( V_134 ) ;
return V_44 ;
}
void F_96 ( struct V_120 * V_63 )
{
struct V_39 * V_40 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
F_14 ( & V_40 -> V_129 ) ;
F_95 ( V_40 -> V_63 . V_134 ) ;
V_40 -> V_63 . V_134 = NULL ;
F_16 ( & V_40 -> V_129 ) ;
}
static int F_97 ( struct V_39 * V_40 ,
struct V_153 * V_154 )
{
struct V_135 V_136 ;
int V_137 , V_44 ;
union V_54 V_111 ;
F_14 ( & V_40 -> V_129 ) ;
if ( ! V_40 -> V_63 . V_134 ) {
V_44 = 0 ;
goto V_108;
}
V_136 . V_138 = V_139 ;
V_44 = F_88 ( & V_40 -> V_63 , & V_136 , & V_137 ) ;
if ( V_44 )
goto V_108;
V_44 = F_89 ( V_40 -> V_63 . V_134 , & V_136 , V_137 ) ;
if ( V_44 )
goto V_108;
V_136 . V_138 = V_140 ;
V_44 = F_88 ( & V_40 -> V_63 , & V_136 , & V_137 ) ;
if ( V_44 )
goto V_108;
V_44 = F_98 ( V_40 -> V_63 . V_31 , V_40 -> V_63 . V_71 ,
V_136 . V_155 . V_156 . V_157 , & V_111 , NULL ) ;
if ( V_44 )
goto V_108;
F_99 ( V_40 -> V_25 -> V_31 != V_40 -> V_63 . V_31 ) ;
if ( V_154 )
V_136 . V_158 = V_154 -> V_159 ;
V_44 = F_89 ( V_40 -> V_63 . V_134 , & V_136 , V_137 ) ;
V_108:
F_16 ( & V_40 -> V_129 ) ;
return V_44 ;
}
static int F_100 ( struct V_39 * V_40 ,
struct V_153 * V_154 )
{
struct V_135 V_136 ;
int V_137 , V_44 ;
F_14 ( & V_40 -> V_129 ) ;
if ( ! V_40 -> V_63 . V_134 ) {
V_44 = 0 ;
goto V_108;
}
V_136 . V_138 = V_142 ;
V_44 = F_88 ( & V_40 -> V_63 , & V_136 , & V_137 ) ;
if ( V_44 )
goto V_108;
if ( V_154 )
V_136 . V_160 = V_154 -> V_161 ;
V_44 = F_89 ( V_40 -> V_63 . V_134 , & V_136 , V_137 ) ;
V_108:
F_16 ( & V_40 -> V_129 ) ;
return V_44 ;
}
static int F_101 ( struct V_39 * V_40 )
{
struct V_135 V_136 ;
int V_44 ;
F_14 ( & V_40 -> V_129 ) ;
if ( ! V_40 -> V_63 . V_134 ) {
V_44 = 0 ;
goto V_108;
}
V_136 . V_138 = V_162 ;
V_44 = F_89 ( V_40 -> V_63 . V_134 , & V_136 , V_141 ) ;
V_108:
F_16 ( & V_40 -> V_129 ) ;
return V_44 ;
}
static int F_102 ( struct V_39 * V_40 ,
struct V_135 * V_136 , int * V_137 )
{
struct V_88 * V_66 = & V_40 -> V_63 . V_64 . V_65 . V_66 ;
int V_44 ;
T_6 V_113 ;
if ( F_103 ( V_40 -> V_63 . V_31 , V_40 -> V_63 . V_71 ) )
V_113 = 0xffff ;
else
V_113 = F_104 ( V_66 ) ;
V_44 = F_72 ( V_40 -> V_63 . V_31 , V_40 -> V_63 . V_71 ,
V_113 , & V_136 -> V_163 ) ;
if ( V_44 )
return V_44 ;
V_136 -> V_71 = V_40 -> V_63 . V_71 ;
* V_137 = V_141 | V_164 | V_165 ;
if ( V_40 -> V_63 . V_124 == V_149 ) {
V_44 = F_50 ( V_40 , 0 ) ;
if ( V_44 )
return V_44 ;
V_136 -> V_82 = V_40 -> V_82 ;
* V_137 |= V_166 ;
} else {
V_136 -> V_167 = 0 ;
* V_137 |= V_168 ;
}
return 0 ;
}
int F_88 ( struct V_120 * V_63 , struct V_135 * V_136 ,
int * V_137 )
{
struct V_39 * V_40 ;
int V_44 = 0 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( F_105 ( V_63 -> V_31 , V_63 -> V_71 ) ) {
if ( ! V_40 -> V_169 . V_77 || ( V_40 -> V_63 . V_124 == V_149 ) )
V_44 = F_102 ( V_40 , V_136 , V_137 ) ;
else
V_44 = F_106 ( V_40 -> V_169 . V_77 , V_136 ,
V_137 ) ;
if ( V_136 -> V_138 == V_140 )
V_136 -> V_170 = V_40 -> V_132 ;
} else if ( F_107 ( V_63 -> V_31 , V_63 -> V_71 ) ) {
if ( ! V_40 -> V_169 . V_171 ) {
V_136 -> V_167 = 0 ;
* V_137 = V_141 | V_168 ;
} else
V_44 = F_108 ( V_40 -> V_169 . V_171 , V_136 ,
V_137 ) ;
} else
V_44 = - V_172 ;
return V_44 ;
}
static inline int F_109 ( struct V_78 * V_65 )
{
switch ( V_65 -> V_93 ) {
case V_173 :
return F_110 ( ( (struct V_174 * ) V_65 ) -> V_175 . V_176 ) ;
case V_177 :
return F_111 ( & ( (struct V_178 * ) V_65 ) -> V_179 ) ;
case V_94 :
return F_112 ( & ( (struct V_86 * ) V_65 ) -> V_91 ) ;
default:
return 0 ;
}
}
static inline int F_113 ( struct V_78 * V_65 )
{
switch ( V_65 -> V_93 ) {
case V_173 :
return F_114 ( ( (struct V_174 * ) V_65 ) -> V_175 . V_176 ) ;
case V_177 :
return F_115 ( & ( (struct V_178 * ) V_65 ) -> V_179 ) ;
case V_94 :
return F_116 ( & ( (struct V_86 * ) V_65 ) -> V_91 ) ;
default:
return 0 ;
}
}
static inline int F_117 ( struct V_78 * V_65 )
{
return F_109 ( V_65 ) || F_113 ( V_65 ) ;
}
static int F_118 ( struct V_78 * V_180 , struct V_78 * V_181 )
{
if ( V_180 -> V_93 != V_181 -> V_93 )
return - 1 ;
switch ( V_180 -> V_93 ) {
case V_173 :
return ( (struct V_174 * ) V_180 ) -> V_175 . V_176 !=
( (struct V_174 * ) V_181 ) -> V_175 . V_176 ;
case V_177 :
return F_119 ( & ( (struct V_178 * ) V_180 ) -> V_179 ,
& ( (struct V_178 * ) V_181 ) -> V_179 ) ;
default:
return F_120 ( & ( (struct V_86 * ) V_180 ) -> V_91 ,
& ( (struct V_86 * ) V_181 ) -> V_91 ) ;
}
}
static T_8 F_121 ( struct V_78 * V_65 )
{
struct V_86 * V_87 ;
switch ( V_65 -> V_93 ) {
case V_173 :
return ( (struct V_174 * ) V_65 ) -> V_182 ;
case V_177 :
return ( (struct V_178 * ) V_65 ) -> V_183 ;
case V_94 :
V_87 = (struct V_86 * ) V_65 ;
return F_122 ( ( T_6 ) ( F_123 ( V_87 -> V_184 ) &
F_123 ( V_87 -> V_185 ) ) ) ;
default:
return 0 ;
}
}
static inline int F_124 ( struct V_78 * V_65 )
{
return ! F_121 ( V_65 ) ;
}
static void F_125 ( struct V_78 * V_79 ,
struct V_78 * V_80 ,
struct V_120 * V_186 ,
struct V_187 * V_188 )
{
struct V_86 * V_189 , * V_77 ;
V_189 = (struct V_86 * ) & V_186 -> V_64 . V_65 . V_79 ;
if ( V_79 ) {
V_77 = (struct V_86 * ) V_79 ;
V_77 -> V_190 = V_94 ;
if ( V_188 ) {
V_77 -> V_92 = V_188 -> V_113 ;
V_77 -> V_191 = V_188 -> V_192 ;
memcpy ( & V_77 -> V_91 , & V_188 -> V_111 , 16 ) ;
V_77 -> V_184 = V_188 -> V_193 ;
V_77 -> V_194 = 0 ;
} else {
V_77 -> V_92 = V_189 -> V_92 ;
V_77 -> V_191 = V_189 -> V_191 ;
V_77 -> V_91 = V_189 -> V_91 ;
V_77 -> V_184 = V_189 -> V_184 ;
V_77 -> V_194 = V_189 -> V_194 ;
}
V_77 -> V_185 = F_126 ( 0xffffffffffffffffULL ) ;
}
if ( V_80 ) {
V_77 = (struct V_86 * ) V_80 ;
V_77 -> V_190 = V_94 ;
if ( V_188 ) {
V_77 -> V_92 = V_188 -> V_113 ;
V_77 -> V_191 = V_188 -> V_192 ;
memcpy ( & V_77 -> V_91 , & V_188 -> V_112 , 16 ) ;
}
}
}
static void F_127 ( struct V_78 * V_79 ,
struct V_78 * V_80 ,
struct V_48 * V_49 ,
T_8 V_195 )
{
struct V_174 * V_196 ;
if ( V_79 ) {
V_196 = (struct V_174 * ) V_79 ;
V_196 -> V_197 = V_173 ;
V_196 -> V_175 . V_176 = V_49 -> V_80 . V_196 . V_65 ;
V_196 -> V_182 = V_195 ;
}
if ( V_80 ) {
V_196 = (struct V_174 * ) V_80 ;
V_196 -> V_197 = V_173 ;
V_196 -> V_175 . V_176 = V_49 -> V_79 . V_196 . V_65 ;
V_196 -> V_182 = V_49 -> V_32 ;
}
}
static void F_128 ( struct V_78 * V_79 ,
struct V_78 * V_80 ,
struct V_48 * V_49 ,
T_8 V_195 )
{
struct V_178 * V_198 ;
if ( V_79 ) {
V_198 = (struct V_178 * ) V_79 ;
V_198 -> V_199 = V_177 ;
V_198 -> V_179 = V_49 -> V_80 . V_198 ;
V_198 -> V_183 = V_195 ;
}
if ( V_80 ) {
V_198 = (struct V_178 * ) V_80 ;
V_198 -> V_199 = V_177 ;
V_198 -> V_179 = V_49 -> V_79 . V_198 ;
V_198 -> V_183 = V_49 -> V_32 ;
}
}
static T_6 F_129 ( T_9 V_193 )
{
return ( T_6 ) F_123 ( V_193 ) ;
}
static int F_130 ( struct V_78 * V_79 ,
struct V_78 * V_80 ,
struct V_200 * V_201 ,
T_9 V_193 )
{
struct V_48 * V_49 ;
T_8 V_32 ;
V_49 = V_201 -> V_202 ;
if ( V_49 -> V_203 != V_204 )
return - V_34 ;
V_32 = F_122 ( F_129 ( V_193 ) ) ;
switch ( F_27 ( V_49 ) ) {
case 4 :
F_127 ( V_79 , V_80 , V_49 , V_32 ) ;
break;
case 6 :
F_128 ( V_79 , V_80 , V_49 , V_32 ) ;
break;
default:
return - V_205 ;
}
return 0 ;
}
static int F_131 ( struct V_78 * V_79 ,
struct V_78 * V_80 ,
struct V_120 * V_186 ,
struct V_200 * V_201 ,
T_10 V_93 , T_9 V_193 )
{
if ( V_93 == V_94 ) {
if ( V_201 -> V_2 == V_206 )
F_125 ( V_79 , V_80 , V_186 ,
V_201 -> V_207 . V_208 . V_209 ) ;
else if ( V_201 -> V_2 == V_210 )
F_125 ( V_79 , V_80 , V_186 , NULL ) ;
return 0 ;
}
return F_130 ( V_79 , V_80 , V_201 , V_193 ) ;
}
static int F_132 ( const struct V_200 * V_201 ,
struct V_211 * V_212 )
{
const struct V_213 * V_214 =
& V_201 -> V_207 . V_208 ;
const struct V_215 * V_216 =
& V_201 -> V_207 . V_217 ;
switch ( V_201 -> V_2 ) {
case V_206 :
V_212 -> V_31 = V_214 -> V_186 -> V_31 ;
V_212 -> V_32 = V_214 -> V_32 ;
memcpy ( & V_212 -> V_218 , & V_214 -> V_209 -> V_111 ,
sizeof( V_212 -> V_218 ) ) ;
V_212 -> V_219 = true ;
V_212 -> V_193 = V_214 -> V_209 -> V_193 ;
V_212 -> V_113 = F_133 ( V_214 -> V_209 -> V_113 ) ;
break;
case V_210 :
V_212 -> V_31 = V_216 -> V_186 -> V_31 ;
V_212 -> V_32 = V_216 -> V_32 ;
V_212 -> V_219 = false ;
V_212 -> V_193 = V_216 -> V_193 ;
V_212 -> V_113 = V_216 -> V_113 ;
break;
default:
return - V_34 ;
}
return 0 ;
}
static bool F_134 ( struct V_52 * V_220 ,
const struct V_174 * V_80 ,
const struct V_174 * V_79 )
{
V_59 V_221 = V_80 -> V_175 . V_176 ,
V_222 = V_79 -> V_175 . V_176 ;
struct V_223 V_224 ;
struct V_225 V_226 ;
int V_150 ;
bool V_44 ;
if ( F_135 ( V_222 ) || F_136 ( V_222 ) ||
F_136 ( V_221 ) || F_110 ( V_222 ) ||
F_110 ( V_221 ) || F_114 ( V_221 ) ||
F_114 ( V_222 ) )
return false ;
memset ( & V_226 , 0 , sizeof( V_226 ) ) ;
V_226 . V_227 = V_220 -> V_228 ;
V_226 . V_221 = V_221 ;
V_226 . V_222 = V_222 ;
F_137 () ;
V_150 = F_138 ( F_139 ( V_220 ) , & V_226 , & V_224 , 0 ) ;
V_44 = V_150 == 0 && F_140 ( V_224 ) == V_220 ;
F_141 () ;
return V_44 ;
}
static bool F_142 ( struct V_52 * V_220 ,
const struct V_178 * V_80 ,
const struct V_178 * V_79 )
{
#if F_143 ( V_229 )
const int V_230 = F_144 ( & V_80 -> V_179 ) &
V_231 ;
struct V_232 * V_233 = F_145 ( F_139 ( V_220 ) , & V_80 -> V_179 ,
& V_79 -> V_179 , V_220 -> V_228 ,
V_230 ) ;
bool V_44 ;
if ( ! V_233 )
return false ;
V_44 = V_233 -> V_234 -> V_235 == V_220 ;
F_146 ( V_233 ) ;
return V_44 ;
#else
return false ;
#endif
}
static bool F_147 ( struct V_52 * V_220 ,
const struct V_78 * V_221 ,
const struct V_78 * V_222 )
{
const struct V_174 * V_236 = ( const struct V_174 * ) V_221 ;
const struct V_174 * V_237 = ( const struct V_174 * ) V_222 ;
const struct V_178 * V_238 = ( const struct V_178 * ) V_221 ;
const struct V_178 * V_239 = ( const struct V_178 * ) V_222 ;
switch ( V_221 -> V_93 ) {
case V_173 :
return V_222 -> V_93 == V_173 &&
F_134 ( V_220 , V_236 , V_237 ) ;
case V_177 :
return V_222 -> V_93 == V_177 &&
F_142 ( V_220 , V_238 , V_239 ) ;
default:
return false ;
}
}
static struct V_52 * F_148 ( struct V_200 * V_201 ,
const struct V_211 * V_212 )
{
struct V_240 V_241 , V_242 ;
struct V_78 * V_243 = (struct V_78 * ) & V_241 ,
* V_79 = (struct V_78 * ) & V_242 ;
struct V_52 * V_220 ;
const union V_54 * V_95 = V_212 -> V_219 ? & V_212 -> V_218 : NULL ;
int V_150 ;
V_150 = F_130 ( V_243 , V_79 , V_201 ,
V_212 -> V_193 ) ;
if ( V_150 )
return F_78 ( V_150 ) ;
V_220 = F_149 ( V_212 -> V_31 , V_212 -> V_32 , V_212 -> V_113 ,
V_95 , V_243 ) ;
if ( ! V_220 )
return F_78 ( - V_61 ) ;
if ( ! F_147 ( V_220 , V_243 , V_79 ) ) {
F_65 ( V_220 ) ;
return F_78 ( - V_244 ) ;
}
return V_220 ;
}
static enum V_9 F_150 ( T_9 V_193 )
{
return ( F_123 ( V_193 ) >> 16 ) & 0xffff ;
}
static bool F_151 ( struct V_39 * V_40 ,
const struct V_48 * V_49 )
{
struct V_78 * V_65 = F_47 ( V_40 ) ;
V_59 V_245 ;
struct V_246 V_247 ;
if ( F_117 ( V_65 ) && ! V_40 -> V_248 )
return true ;
switch ( V_65 -> V_93 ) {
case V_173 :
V_245 = ( (struct V_174 * ) V_65 ) -> V_175 . V_176 ;
if ( F_27 ( V_49 ) != 4 )
return false ;
if ( ! F_117 ( V_65 ) &&
V_49 -> V_80 . V_196 . V_65 != V_245 )
return false ;
break;
case V_177 :
V_247 = ( (struct V_178 * ) V_65 ) -> V_179 ;
if ( F_27 ( V_49 ) != 6 )
return false ;
if ( ! F_117 ( V_65 ) &&
memcmp ( & V_49 -> V_80 . V_198 , & V_247 , sizeof( V_247 ) ) )
return false ;
break;
case V_94 :
return true ;
default:
return false ;
}
return true ;
}
static bool F_152 ( struct V_38 * V_31 , int V_71 )
{
enum V_249 V_250 = F_153 ( V_31 , V_71 ) ;
enum V_251 V_67 =
F_36 ( V_31 -> V_68 ) ;
return V_250 == V_252 && V_67 == V_253 ;
}
static bool F_154 ( const struct V_120 * V_63 )
{
struct V_38 * V_31 = V_63 -> V_31 ;
const int V_71 = V_63 -> V_71 ? : V_33 ( V_31 ) ;
return F_152 ( V_31 , V_71 ) ;
}
static bool F_155 ( const struct V_120 * V_63 ,
const struct V_52 * V_220 ,
T_4 V_71 )
{
const struct V_254 * V_65 = & V_63 -> V_64 . V_65 ;
if ( ! V_220 )
return ( ! V_63 -> V_71 || V_63 -> V_71 == V_71 ) &&
( V_65 -> V_79 . V_81 == V_94 ||
F_152 ( V_63 -> V_31 , V_71 ) ) ;
return ! V_65 -> V_66 . V_107 ||
( F_156 ( F_139 ( V_220 ) , V_65 -> V_66 . V_6 ) &&
V_65 -> V_66 . V_107 == V_220 -> V_228 ) ;
}
static struct V_39 * F_157 (
const struct V_20 * V_21 ,
const struct V_255 * V_169 ,
const struct V_200 * V_201 ,
const struct V_211 * V_212 ,
const struct V_52 * V_220 )
{
struct V_39 * V_40 , * V_256 ;
if ( ! V_21 )
return F_78 ( - V_34 ) ;
F_158 (id_priv, &bind_list->owners, node) {
if ( F_151 ( V_40 , V_201 -> V_202 ) ) {
if ( V_40 -> V_63 . V_31 == V_169 -> V_31 &&
F_155 ( & V_40 -> V_63 , V_220 , V_212 -> V_32 ) )
return V_40 ;
F_15 (id_priv_dev,
&id_priv->listen_list,
listen_list) {
if ( V_256 -> V_63 . V_31 == V_169 -> V_31 &&
F_155 ( & V_256 -> V_63 , V_220 , V_212 -> V_32 ) )
return V_256 ;
}
}
}
return F_78 ( - V_34 ) ;
}
static struct V_39 * F_159 ( struct V_255 * V_169 ,
struct V_200 * V_201 ,
struct V_52 * * V_220 )
{
struct V_211 V_212 ;
struct V_20 * V_21 ;
struct V_39 * V_40 ;
int V_150 ;
V_150 = F_132 ( V_201 , & V_212 ) ;
if ( V_150 )
return F_78 ( V_150 ) ;
* V_220 = F_148 ( V_201 , & V_212 ) ;
if ( F_93 ( * V_220 ) ) {
if ( F_94 ( * V_220 ) == - V_205 ) {
* V_220 = NULL ;
} else if ( F_152 ( V_212 . V_31 , V_212 . V_32 ) ) {
* V_220 = NULL ;
} else {
return F_160 ( * V_220 ) ;
}
}
V_21 = F_7 ( * V_220 ? F_139 ( * V_220 ) : & V_98 ,
F_150 ( V_212 . V_193 ) ,
F_129 ( V_212 . V_193 ) ) ;
V_40 = F_157 ( V_21 , V_169 , V_201 , & V_212 , * V_220 ) ;
if ( F_93 ( V_40 ) && * V_220 ) {
F_65 ( * V_220 ) ;
* V_220 = NULL ;
}
return V_40 ;
}
static inline int F_161 ( struct V_39 * V_40 )
{
return F_49 ( V_40 ) == V_94 ? 0 : sizeof( struct V_48 ) ;
}
static void F_162 ( struct V_39 * V_40 )
{
if ( F_163 ( V_40 -> V_63 . V_31 , V_40 -> V_63 . V_71 ) ) {
if ( V_40 -> V_257 )
F_164 ( V_40 -> V_258 , V_40 -> V_257 ) ;
}
}
static void F_165 ( struct V_39 * V_40 )
{
struct V_39 * V_259 ;
F_14 ( & V_30 ) ;
F_46 ( & V_40 -> V_69 ) ;
while ( ! F_166 ( & V_40 -> V_130 ) ) {
V_259 = F_167 ( V_40 -> V_130 . V_260 ,
struct V_39 , V_130 ) ;
F_168 ( & V_259 -> V_69 ) ;
F_46 ( & V_259 -> V_130 ) ;
F_16 ( & V_30 ) ;
F_169 ( & V_259 -> V_63 ) ;
F_14 ( & V_30 ) ;
}
F_16 ( & V_30 ) ;
}
static void F_170 ( struct V_39 * V_40 ,
enum V_41 V_45 )
{
switch ( V_45 ) {
case V_261 :
F_171 ( & V_40 -> V_63 . V_64 . V_65 . V_66 ) ;
break;
case V_262 :
F_162 ( V_40 ) ;
break;
case V_263 :
if ( F_117 ( F_47 ( V_40 ) ) && ! V_40 -> V_25 )
F_165 ( V_40 ) ;
break;
default:
break;
}
}
static void F_172 ( struct V_39 * V_40 )
{
struct V_20 * V_21 = V_40 -> V_21 ;
struct V_6 * V_6 = V_40 -> V_63 . V_64 . V_65 . V_66 . V_6 ;
if ( ! V_21 )
return;
F_14 ( & V_30 ) ;
F_173 ( & V_40 -> V_264 ) ;
if ( F_174 ( & V_21 -> V_265 ) ) {
F_9 ( V_6 , V_21 -> V_10 , V_21 -> V_32 ) ;
F_44 ( V_21 ) ;
}
F_16 ( & V_30 ) ;
}
static void F_175 ( struct V_39 * V_40 )
{
struct V_73 * V_74 ;
while ( ! F_166 ( & V_40 -> V_131 ) ) {
V_74 = F_43 ( V_40 -> V_131 . V_260 ,
struct V_73 , V_69 ) ;
F_46 ( & V_74 -> V_69 ) ;
if ( F_176 ( V_40 -> V_25 -> V_31 ,
V_40 -> V_63 . V_71 ) ) {
F_177 ( V_74 -> V_76 . V_77 ) ;
F_44 ( V_74 ) ;
} else {
if ( V_74 -> V_266 ) {
struct V_88 * V_66 =
& V_40 -> V_63 . V_64 . V_65 . V_66 ;
struct V_52 * V_53 = NULL ;
if ( V_66 -> V_107 )
V_53 = F_63 ( & V_98 ,
V_66 -> V_107 ) ;
if ( V_53 ) {
F_29 ( V_53 ,
& V_74 -> V_76 . V_77 -> V_84 . V_55 ,
false ) ;
F_65 ( V_53 ) ;
}
}
F_178 ( & V_74 -> V_75 , F_42 ) ;
}
}
}
void F_169 ( struct V_120 * V_63 )
{
struct V_39 * V_40 ;
enum V_41 V_45 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
V_45 = F_26 ( V_40 , V_267 ) ;
F_170 ( V_40 , V_45 ) ;
F_14 ( & V_40 -> V_119 ) ;
F_16 ( & V_40 -> V_119 ) ;
if ( V_40 -> V_25 ) {
if ( F_105 ( V_40 -> V_63 . V_31 , 1 ) ) {
if ( V_40 -> V_169 . V_77 )
F_179 ( V_40 -> V_169 . V_77 ) ;
} else if ( F_107 ( V_40 -> V_63 . V_31 , 1 ) ) {
if ( V_40 -> V_169 . V_171 )
F_180 ( V_40 -> V_169 . V_171 ) ;
}
F_175 ( V_40 ) ;
F_45 ( V_40 ) ;
}
F_172 ( V_40 ) ;
F_74 ( V_40 ) ;
F_181 ( & V_40 -> V_42 ) ;
if ( V_40 -> V_268 )
F_74 ( V_40 -> V_63 . V_122 ) ;
F_44 ( V_40 -> V_63 . V_64 . V_269 ) ;
F_182 ( V_40 -> V_63 . V_64 . V_65 . V_66 . V_6 ) ;
F_44 ( V_40 ) ;
}
static int F_183 ( struct V_39 * V_40 )
{
int V_44 ;
V_44 = F_97 ( V_40 , NULL ) ;
if ( V_44 )
goto V_270;
V_44 = F_100 ( V_40 , NULL ) ;
if ( V_44 )
goto V_270;
V_44 = F_184 ( V_40 -> V_169 . V_77 , NULL , 0 ) ;
if ( V_44 )
goto V_270;
return 0 ;
V_270:
F_101 ( V_40 ) ;
F_185 ( V_40 -> V_169 . V_77 , V_271 ,
NULL , 0 , NULL , 0 ) ;
return V_44 ;
}
static void F_186 ( struct V_272 * V_2 ,
struct V_273 * V_274 ,
void * V_202 )
{
V_2 -> V_207 . V_275 . V_202 = V_202 ;
V_2 -> V_207 . V_275 . V_276 = V_277 ;
V_2 -> V_207 . V_275 . V_159 = V_274 -> V_159 ;
V_2 -> V_207 . V_275 . V_161 = V_274 -> V_161 ;
V_2 -> V_207 . V_275 . V_278 = V_274 -> V_278 ;
V_2 -> V_207 . V_275 . V_279 = V_274 -> V_279 ;
V_2 -> V_207 . V_275 . V_152 = V_274 -> V_152 ;
V_2 -> V_207 . V_275 . V_151 = V_274 -> V_280 ;
}
static int F_187 ( struct V_255 * V_169 , struct V_200 * V_201 )
{
struct V_39 * V_40 = V_169 -> V_122 ;
struct V_272 V_2 ;
int V_44 = 0 ;
if ( ( V_201 -> V_2 != V_281 &&
F_75 ( V_40 , V_282 ) ) ||
( V_201 -> V_2 == V_281 &&
F_75 ( V_40 , V_283 ) ) )
return 0 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_201 -> V_2 ) {
case V_284 :
case V_285 :
V_2 . V_2 = V_286 ;
V_2 . V_287 = - V_288 ;
break;
case V_289 :
if ( V_40 -> V_63 . V_134 ) {
V_2 . V_287 = F_183 ( V_40 ) ;
V_2 . V_2 = V_2 . V_287 ? V_290 :
V_291 ;
} else {
V_2 . V_2 = V_292 ;
}
F_186 ( & V_2 , & V_201 -> V_207 . V_293 ,
V_201 -> V_202 ) ;
break;
case V_294 :
case V_295 :
V_2 . V_2 = V_291 ;
break;
case V_296 :
V_2 . V_287 = - V_288 ;
case V_297 :
case V_298 :
if ( ! F_25 ( V_40 , V_282 ,
V_283 ) )
goto V_108;
V_2 . V_2 = V_299 ;
break;
case V_281 :
V_2 . V_2 = V_300 ;
break;
case V_301 :
goto V_108;
case V_302 :
F_101 ( V_40 ) ;
V_2 . V_287 = V_201 -> V_207 . V_303 . V_304 ;
V_2 . V_2 = V_305 ;
V_2 . V_207 . V_275 . V_202 = V_201 -> V_202 ;
V_2 . V_207 . V_275 . V_276 = V_306 ;
break;
default:
F_188 ( V_307 L_3 ,
V_201 -> V_2 ) ;
goto V_108;
}
V_44 = V_40 -> V_63 . V_121 ( & V_40 -> V_63 , & V_2 ) ;
if ( V_44 ) {
V_40 -> V_169 . V_77 = NULL ;
F_26 ( V_40 , V_267 ) ;
F_16 ( & V_40 -> V_119 ) ;
F_169 ( & V_40 -> V_63 ) ;
return V_44 ;
}
V_108:
F_16 ( & V_40 -> V_119 ) ;
return V_44 ;
}
static struct V_39 * F_189 ( struct V_120 * V_186 ,
struct V_200 * V_201 ,
struct V_52 * V_220 )
{
struct V_39 * V_40 ;
struct V_120 * V_63 ;
struct V_308 * V_233 ;
const T_10 V_81 = V_186 -> V_64 . V_65 . V_79 . V_81 ;
const T_9 V_193 =
V_201 -> V_207 . V_208 . V_209 -> V_193 ;
int V_44 ;
V_63 = F_76 ( V_186 -> V_64 . V_65 . V_66 . V_6 ,
V_186 -> V_121 , V_186 -> V_122 ,
V_186 -> V_10 , V_201 -> V_207 . V_208 . V_124 ) ;
if ( F_93 ( V_63 ) )
return NULL ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( F_131 ( (struct V_78 * ) & V_63 -> V_64 . V_65 . V_79 ,
(struct V_78 * ) & V_63 -> V_64 . V_65 . V_80 ,
V_186 , V_201 , V_81 , V_193 ) )
goto V_150;
V_233 = & V_63 -> V_64 ;
V_233 -> V_309 = V_201 -> V_207 . V_208 . V_310 ? 2 : 1 ;
V_233 -> V_269 = F_190 ( sizeof * V_233 -> V_269 * V_233 -> V_309 ,
V_23 ) ;
if ( ! V_233 -> V_269 )
goto V_150;
V_233 -> V_269 [ 0 ] = * V_201 -> V_207 . V_208 . V_209 ;
if ( V_233 -> V_309 == 2 )
V_233 -> V_269 [ 1 ] = * V_201 -> V_207 . V_208 . V_310 ;
if ( V_220 ) {
V_44 = F_191 ( & V_233 -> V_65 . V_66 , V_220 , NULL ) ;
if ( V_44 )
goto V_150;
} else {
if ( ! F_154 ( V_186 ) &&
F_117 ( F_47 ( V_40 ) ) ) {
V_233 -> V_65 . V_66 . V_89 = V_90 ;
F_55 ( & V_233 -> V_65 . V_66 , & V_233 -> V_269 [ 0 ] . V_111 ) ;
F_56 ( & V_233 -> V_65 . V_66 , F_133 ( V_233 -> V_269 [ 0 ] . V_113 ) ) ;
} else if ( ! F_117 ( F_47 ( V_40 ) ) ) {
V_44 = F_58 ( F_47 ( V_40 ) , & V_233 -> V_65 . V_66 ) ;
if ( V_44 )
goto V_150;
}
}
F_192 ( & V_233 -> V_65 . V_66 , & V_233 -> V_269 [ 0 ] . V_112 ) ;
V_40 -> V_45 = V_282 ;
return V_40 ;
V_150:
F_169 ( V_63 ) ;
return NULL ;
}
static struct V_39 * F_193 ( struct V_120 * V_186 ,
struct V_200 * V_201 ,
struct V_52 * V_220 )
{
struct V_39 * V_40 ;
struct V_120 * V_63 ;
const T_10 V_81 = V_186 -> V_64 . V_65 . V_79 . V_81 ;
struct V_6 * V_6 = V_186 -> V_64 . V_65 . V_66 . V_6 ;
int V_44 ;
V_63 = F_76 ( V_6 , V_186 -> V_121 , V_186 -> V_122 ,
V_186 -> V_10 , V_149 ) ;
if ( F_93 ( V_63 ) )
return NULL ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( F_131 ( (struct V_78 * ) & V_63 -> V_64 . V_65 . V_79 ,
(struct V_78 * ) & V_63 -> V_64 . V_65 . V_80 ,
V_186 , V_201 , V_81 ,
V_201 -> V_207 . V_217 . V_193 ) )
goto V_150;
if ( V_220 ) {
V_44 = F_191 ( & V_63 -> V_64 . V_65 . V_66 , V_220 , NULL ) ;
if ( V_44 )
goto V_150;
} else {
if ( ! F_117 ( F_47 ( V_40 ) ) ) {
V_44 = F_58 ( F_47 ( V_40 ) ,
& V_63 -> V_64 . V_65 . V_66 ) ;
if ( V_44 )
goto V_150;
}
}
V_40 -> V_45 = V_282 ;
return V_40 ;
V_150:
F_169 ( V_63 ) ;
return NULL ;
}
static void F_194 ( struct V_272 * V_2 ,
struct V_213 * V_311 ,
void * V_202 , int V_312 )
{
V_2 -> V_207 . V_275 . V_202 = V_202 + V_312 ;
V_2 -> V_207 . V_275 . V_276 = V_313 - V_312 ;
V_2 -> V_207 . V_275 . V_159 = V_311 -> V_159 ;
V_2 -> V_207 . V_275 . V_161 = V_311 -> V_161 ;
V_2 -> V_207 . V_275 . V_278 = V_311 -> V_278 ;
V_2 -> V_207 . V_275 . V_314 = V_311 -> V_314 ;
V_2 -> V_207 . V_275 . V_279 = V_311 -> V_279 ;
V_2 -> V_207 . V_275 . V_152 = V_311 -> V_152 ;
V_2 -> V_207 . V_275 . V_151 = V_311 -> V_280 ;
}
static int F_195 ( struct V_120 * V_63 , struct V_200 * V_201 )
{
return ( ( ( V_201 -> V_2 == V_206 ) &&
( V_201 -> V_207 . V_208 . V_124 == V_63 -> V_124 ) ) ||
( ( V_201 -> V_2 == V_210 ) &&
( V_63 -> V_124 == V_149 ) ) ||
( ! V_63 -> V_124 ) ) ;
}
static int F_196 ( struct V_255 * V_169 , struct V_200 * V_201 )
{
struct V_39 * V_186 , * V_315 ;
struct V_272 V_2 ;
struct V_52 * V_220 ;
int V_312 , V_44 ;
V_186 = F_159 ( V_169 , V_201 , & V_220 ) ;
if ( F_93 ( V_186 ) )
return F_94 ( V_186 ) ;
if ( ! F_195 ( & V_186 -> V_63 , V_201 ) ) {
V_44 = - V_34 ;
goto V_316;
}
if ( F_75 ( V_186 , V_263 ) ) {
V_44 = - V_317 ;
goto V_316;
}
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_312 = F_161 ( V_186 ) ;
V_2 . V_2 = V_318 ;
if ( V_201 -> V_2 == V_210 ) {
V_315 = F_193 ( & V_186 -> V_63 , V_201 , V_220 ) ;
V_2 . V_207 . V_319 . V_202 = V_201 -> V_202 + V_312 ;
V_2 . V_207 . V_319 . V_276 =
V_320 - V_312 ;
} else {
V_315 = F_189 ( & V_186 -> V_63 , V_201 , V_220 ) ;
F_194 ( & V_2 , & V_201 -> V_207 . V_208 ,
V_201 -> V_202 , V_312 ) ;
}
if ( ! V_315 ) {
V_44 = - V_125 ;
goto V_321;
}
F_197 ( & V_315 -> V_119 , V_322 ) ;
V_44 = F_67 ( V_315 , V_186 ) ;
if ( V_44 )
goto V_323;
V_315 -> V_169 . V_77 = V_169 ;
V_169 -> V_122 = V_315 ;
V_169 -> V_324 = F_187 ;
F_12 ( & V_315 -> V_26 ) ;
V_44 = V_315 -> V_63 . V_121 ( & V_315 -> V_63 , & V_2 ) ;
if ( V_44 )
goto V_325;
F_14 ( & V_30 ) ;
if ( F_22 ( V_315 , V_282 ) &&
( V_315 -> V_63 . V_124 != V_149 ) )
F_198 ( V_169 , V_326 , NULL , 0 ) ;
F_16 ( & V_30 ) ;
F_16 ( & V_315 -> V_119 ) ;
F_16 ( & V_186 -> V_119 ) ;
F_74 ( V_315 ) ;
if ( V_220 )
F_65 ( V_220 ) ;
return 0 ;
V_325:
F_74 ( V_315 ) ;
V_315 -> V_169 . V_77 = NULL ;
V_323:
F_26 ( V_315 , V_267 ) ;
F_16 ( & V_315 -> V_119 ) ;
V_321:
F_16 ( & V_186 -> V_119 ) ;
if ( V_315 )
F_169 ( & V_315 -> V_63 ) ;
V_316:
if ( V_220 )
F_65 ( V_220 ) ;
return V_44 ;
}
T_9 F_199 ( struct V_120 * V_63 , struct V_78 * V_65 )
{
if ( V_65 -> V_93 == V_94 )
return ( (struct V_86 * ) V_65 ) -> V_184 ;
return F_126 ( ( ( V_327 ) V_63 -> V_10 << 16 ) + F_133 ( F_121 ( V_65 ) ) ) ;
}
static int F_200 ( struct V_328 * V_329 , struct V_330 * V_331 )
{
struct V_39 * V_40 = V_329 -> V_122 ;
struct V_272 V_2 ;
int V_44 = 0 ;
struct V_78 * V_332 = (struct V_78 * ) & V_331 -> V_333 ;
struct V_78 * V_334 = (struct V_78 * ) & V_331 -> V_335 ;
if ( F_75 ( V_40 , V_282 ) )
return 0 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_331 -> V_2 ) {
case V_336 :
V_2 . V_2 = V_299 ;
break;
case V_337 :
memcpy ( F_47 ( V_40 ) , V_332 ,
F_201 ( V_332 ) ) ;
memcpy ( F_48 ( V_40 ) , V_334 ,
F_201 ( V_334 ) ) ;
switch ( V_331 -> V_287 ) {
case 0 :
V_2 . V_2 = V_291 ;
V_2 . V_207 . V_275 . V_161 = V_331 -> V_338 ;
V_2 . V_207 . V_275 . V_159 = V_331 -> V_339 ;
break;
case - V_340 :
case - V_341 :
V_2 . V_2 = V_305 ;
break;
case - V_288 :
V_2 . V_2 = V_286 ;
break;
default:
V_2 . V_2 = V_290 ;
break;
}
break;
case V_342 :
V_2 . V_2 = V_291 ;
V_2 . V_207 . V_275 . V_161 = V_331 -> V_338 ;
V_2 . V_207 . V_275 . V_159 = V_331 -> V_339 ;
break;
default:
F_99 ( 1 ) ;
}
V_2 . V_287 = V_331 -> V_287 ;
V_2 . V_207 . V_275 . V_202 = V_331 -> V_202 ;
V_2 . V_207 . V_275 . V_276 = V_331 -> V_276 ;
V_44 = V_40 -> V_63 . V_121 ( & V_40 -> V_63 , & V_2 ) ;
if ( V_44 ) {
V_40 -> V_169 . V_171 = NULL ;
F_26 ( V_40 , V_267 ) ;
F_16 ( & V_40 -> V_119 ) ;
F_169 ( & V_40 -> V_63 ) ;
return V_44 ;
}
F_16 ( & V_40 -> V_119 ) ;
return V_44 ;
}
static int F_202 ( struct V_328 * V_169 ,
struct V_330 * V_331 )
{
struct V_120 * V_343 ;
struct V_39 * V_186 , * V_315 ;
struct V_272 V_2 ;
int V_44 ;
struct V_78 * V_332 = (struct V_78 * ) & V_331 -> V_333 ;
struct V_78 * V_334 = (struct V_78 * ) & V_331 -> V_335 ;
V_186 = V_169 -> V_122 ;
if ( F_75 ( V_186 , V_263 ) )
return - V_317 ;
V_343 = F_76 ( V_186 -> V_63 . V_64 . V_65 . V_66 . V_6 ,
V_186 -> V_63 . V_121 ,
V_186 -> V_63 . V_122 ,
V_12 , V_344 ) ;
if ( F_93 ( V_343 ) ) {
V_44 = - V_125 ;
goto V_108;
}
V_315 = F_43 ( V_343 , struct V_39 , V_63 ) ;
F_197 ( & V_315 -> V_119 , V_322 ) ;
V_315 -> V_45 = V_282 ;
V_44 = F_59 ( V_332 , & V_315 -> V_63 . V_64 . V_65 . V_66 , NULL ) ;
if ( V_44 ) {
F_16 ( & V_315 -> V_119 ) ;
F_169 ( V_343 ) ;
goto V_108;
}
V_44 = F_67 ( V_315 , V_186 ) ;
if ( V_44 ) {
F_16 ( & V_315 -> V_119 ) ;
F_169 ( V_343 ) ;
goto V_108;
}
V_315 -> V_169 . V_171 = V_169 ;
V_169 -> V_122 = V_315 ;
V_169 -> V_324 = F_200 ;
memcpy ( F_47 ( V_315 ) , V_332 , F_201 ( V_332 ) ) ;
memcpy ( F_48 ( V_315 ) , V_334 , F_201 ( V_334 ) ) ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_318 ;
V_2 . V_207 . V_275 . V_202 = V_331 -> V_202 ;
V_2 . V_207 . V_275 . V_276 = V_331 -> V_276 ;
V_2 . V_207 . V_275 . V_161 = V_331 -> V_338 ;
V_2 . V_207 . V_275 . V_159 = V_331 -> V_339 ;
F_12 ( & V_315 -> V_26 ) ;
V_44 = V_315 -> V_63 . V_121 ( & V_315 -> V_63 , & V_2 ) ;
if ( V_44 ) {
V_315 -> V_169 . V_171 = NULL ;
F_26 ( V_315 , V_267 ) ;
F_16 ( & V_315 -> V_119 ) ;
F_74 ( V_315 ) ;
F_169 ( & V_315 -> V_63 ) ;
goto V_108;
}
F_16 ( & V_315 -> V_119 ) ;
F_74 ( V_315 ) ;
V_108:
F_16 ( & V_186 -> V_119 ) ;
return V_44 ;
}
static int F_203 ( struct V_39 * V_40 )
{
struct V_78 * V_65 ;
struct V_255 * V_63 ;
T_9 V_345 ;
V_65 = F_47 ( V_40 ) ;
V_345 = F_199 ( & V_40 -> V_63 , V_65 ) ;
V_63 = F_204 ( V_40 -> V_63 . V_31 , F_196 , V_345 ) ;
if ( F_93 ( V_63 ) )
return F_94 ( V_63 ) ;
V_40 -> V_169 . V_77 = V_63 ;
return 0 ;
}
static int F_205 ( struct V_39 * V_40 , int V_346 )
{
int V_44 ;
struct V_328 * V_63 ;
V_63 = F_206 ( V_40 -> V_63 . V_31 ,
F_202 ,
V_40 ) ;
if ( F_93 ( V_63 ) )
return F_94 ( V_63 ) ;
V_63 -> V_347 = V_40 -> V_347 ;
V_40 -> V_169 . V_171 = V_63 ;
memcpy ( & V_40 -> V_169 . V_171 -> V_333 , F_47 ( V_40 ) ,
F_201 ( F_47 ( V_40 ) ) ) ;
V_44 = F_207 ( V_40 -> V_169 . V_171 , V_346 ) ;
if ( V_44 ) {
F_180 ( V_40 -> V_169 . V_171 ) ;
V_40 -> V_169 . V_171 = NULL ;
}
return V_44 ;
}
static int F_208 ( struct V_120 * V_63 ,
struct V_272 * V_2 )
{
struct V_39 * V_40 = V_63 -> V_122 ;
V_63 -> V_122 = V_40 -> V_63 . V_122 ;
V_63 -> V_121 = V_40 -> V_63 . V_121 ;
return V_40 -> V_63 . V_121 ( V_63 , V_2 ) ;
}
static void F_209 ( struct V_39 * V_40 ,
struct V_24 * V_25 )
{
struct V_39 * V_259 ;
struct V_120 * V_63 ;
struct V_6 * V_6 = V_40 -> V_63 . V_64 . V_65 . V_66 . V_6 ;
int V_44 ;
if ( F_49 ( V_40 ) == V_94 && ! F_105 ( V_25 -> V_31 , 1 ) )
return;
V_63 = F_76 ( V_6 , F_208 , V_40 , V_40 -> V_63 . V_10 ,
V_40 -> V_63 . V_124 ) ;
if ( F_93 ( V_63 ) )
return;
V_259 = F_43 ( V_63 , struct V_39 , V_63 ) ;
V_259 -> V_45 = V_348 ;
memcpy ( F_47 ( V_259 ) , F_47 ( V_40 ) ,
F_201 ( F_47 ( V_40 ) ) ) ;
F_35 ( V_259 , V_25 ) ;
F_37 ( & V_259 -> V_130 , & V_40 -> V_130 ) ;
F_12 ( & V_40 -> V_26 ) ;
V_259 -> V_268 = 1 ;
V_259 -> V_248 = V_40 -> V_248 ;
V_44 = F_210 ( V_63 , V_40 -> V_346 ) ;
if ( V_44 )
F_188 ( V_349 L_4
L_5 , V_44 , V_25 -> V_31 -> V_350 ) ;
}
static void F_211 ( struct V_39 * V_40 )
{
struct V_24 * V_25 ;
F_14 ( & V_30 ) ;
F_37 ( & V_40 -> V_69 , & V_351 ) ;
F_15 (cma_dev, &dev_list, list)
F_209 ( V_40 , V_25 ) ;
F_16 ( & V_30 ) ;
}
void F_212 ( struct V_120 * V_63 , int V_347 )
{
struct V_39 * V_40 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
V_40 -> V_347 = ( T_4 ) V_347 ;
}
static void F_213 ( int V_287 , struct V_187 * V_269 ,
void * V_122 )
{
struct V_352 * V_353 = V_122 ;
struct V_308 * V_64 ;
V_64 = & V_353 -> V_63 -> V_63 . V_64 ;
if ( ! V_287 ) {
V_64 -> V_309 = 1 ;
* V_64 -> V_269 = * V_269 ;
} else {
V_353 -> V_354 = V_262 ;
V_353 -> V_355 = V_356 ;
V_353 -> V_2 . V_2 = V_357 ;
V_353 -> V_2 . V_287 = V_287 ;
}
F_214 ( V_358 , & V_353 -> V_353 ) ;
}
static int F_215 ( struct V_39 * V_40 , int V_359 ,
struct V_352 * V_353 )
{
struct V_88 * V_66 = & V_40 -> V_63 . V_64 . V_65 . V_66 ;
struct V_187 V_269 ;
T_11 V_360 ;
struct V_178 * V_361 ;
struct V_86 * V_87 ;
memset ( & V_269 , 0 , sizeof V_269 ) ;
F_216 ( V_66 , & V_269 . V_111 ) ;
F_217 ( V_66 , & V_269 . V_112 ) ;
V_269 . V_113 = F_218 ( F_104 ( V_66 ) ) ;
V_269 . V_362 = 1 ;
V_269 . V_363 = 1 ;
V_269 . V_193 = F_199 ( & V_40 -> V_63 , F_48 ( V_40 ) ) ;
V_360 = V_364 | V_365 |
V_366 | V_367 |
V_368 | V_369 ;
switch ( F_49 ( V_40 ) ) {
case V_173 :
V_269 . V_370 = F_218 ( ( T_6 ) V_40 -> V_347 ) ;
V_360 |= V_371 ;
break;
case V_177 :
V_361 = (struct V_178 * ) F_47 ( V_40 ) ;
V_269 . V_372 = ( T_4 ) ( F_53 ( V_361 -> V_373 ) >> 20 ) ;
V_360 |= V_374 ;
break;
case V_94 :
V_87 = (struct V_86 * ) F_47 ( V_40 ) ;
V_269 . V_372 = ( T_4 ) ( F_53 ( V_87 -> V_191 ) >> 20 ) ;
V_360 |= V_374 ;
break;
}
V_40 -> V_258 = F_219 ( & V_375 , V_40 -> V_63 . V_31 ,
V_40 -> V_63 . V_71 , & V_269 ,
V_360 , V_359 ,
V_23 , F_213 ,
V_353 , & V_40 -> V_257 ) ;
return ( V_40 -> V_258 < 0 ) ? V_40 -> V_258 : 0 ;
}
static void F_220 ( struct V_376 * V_377 )
{
struct V_352 * V_353 = F_43 ( V_377 , struct V_352 , V_353 ) ;
struct V_39 * V_40 = V_353 -> V_63 ;
int V_378 = 0 ;
F_14 ( & V_40 -> V_119 ) ;
if ( ! F_25 ( V_40 , V_353 -> V_354 , V_353 -> V_355 ) )
goto V_108;
if ( V_40 -> V_63 . V_121 ( & V_40 -> V_63 , & V_353 -> V_2 ) ) {
F_26 ( V_40 , V_267 ) ;
V_378 = 1 ;
}
V_108:
F_16 ( & V_40 -> V_119 ) ;
F_74 ( V_40 ) ;
if ( V_378 )
F_169 ( & V_40 -> V_63 ) ;
F_44 ( V_353 ) ;
}
static void F_221 ( struct V_376 * V_377 )
{
struct V_379 * V_353 = F_43 ( V_377 , struct V_379 , V_353 ) ;
struct V_39 * V_40 = V_353 -> V_63 ;
int V_378 = 0 ;
F_14 ( & V_40 -> V_119 ) ;
if ( V_40 -> V_45 == V_267 ||
V_40 -> V_45 == V_380 )
goto V_108;
if ( V_40 -> V_63 . V_121 ( & V_40 -> V_63 , & V_353 -> V_2 ) ) {
F_26 ( V_40 , V_267 ) ;
V_378 = 1 ;
}
V_108:
F_16 ( & V_40 -> V_119 ) ;
F_74 ( V_40 ) ;
if ( V_378 )
F_169 ( & V_40 -> V_63 ) ;
F_44 ( V_353 ) ;
}
static int F_222 ( struct V_39 * V_40 , int V_359 )
{
struct V_308 * V_64 = & V_40 -> V_63 . V_64 ;
struct V_352 * V_353 ;
int V_44 ;
V_353 = F_77 ( sizeof *V_353 , V_23 ) ;
if ( ! V_353 )
return - V_125 ;
V_353 -> V_63 = V_40 ;
F_223 ( & V_353 -> V_353 , F_220 ) ;
V_353 -> V_354 = V_262 ;
V_353 -> V_355 = V_381 ;
V_353 -> V_2 . V_2 = V_382 ;
V_64 -> V_269 = F_190 ( sizeof * V_64 -> V_269 , V_23 ) ;
if ( ! V_64 -> V_269 ) {
V_44 = - V_125 ;
goto V_321;
}
V_44 = F_215 ( V_40 , V_359 , V_353 ) ;
if ( V_44 )
goto V_323;
return 0 ;
V_323:
F_44 ( V_64 -> V_269 ) ;
V_64 -> V_269 = NULL ;
V_321:
F_44 ( V_353 ) ;
return V_44 ;
}
int F_224 ( struct V_120 * V_63 ,
struct V_187 * V_269 , int V_309 )
{
struct V_39 * V_40 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( ! F_25 ( V_40 , V_356 ,
V_381 ) )
return - V_34 ;
V_63 -> V_64 . V_269 = F_225 ( V_269 , sizeof *V_269 * V_309 ,
V_23 ) ;
if ( ! V_63 -> V_64 . V_269 ) {
V_44 = - V_125 ;
goto V_150;
}
V_63 -> V_64 . V_309 = V_309 ;
return 0 ;
V_150:
F_25 ( V_40 , V_381 , V_356 ) ;
return V_44 ;
}
static int F_226 ( struct V_39 * V_40 , int V_359 )
{
struct V_352 * V_353 ;
V_353 = F_77 ( sizeof *V_353 , V_23 ) ;
if ( ! V_353 )
return - V_125 ;
V_353 -> V_63 = V_40 ;
F_223 ( & V_353 -> V_353 , F_220 ) ;
V_353 -> V_354 = V_262 ;
V_353 -> V_355 = V_381 ;
V_353 -> V_2 . V_2 = V_382 ;
F_214 ( V_358 , & V_353 -> V_353 ) ;
return 0 ;
}
static int F_227 ( struct V_52 * V_53 , int V_347 )
{
int V_383 ;
struct V_52 * V_235 ;
V_383 = F_228 ( V_347 ) ;
V_235 = V_53 -> V_384 & V_385 ?
F_229 ( V_53 ) : V_53 ;
if ( V_235 -> V_386 )
return F_230 ( V_235 , V_383 ) ;
#if F_143 ( V_387 )
if ( V_53 -> V_384 & V_385 )
return ( F_231 ( V_53 , V_383 ) &
V_388 ) >> V_389 ;
#endif
return 0 ;
}
static int F_232 ( struct V_39 * V_40 )
{
struct V_308 * V_64 = & V_40 -> V_63 . V_64 ;
struct V_254 * V_65 = & V_64 -> V_65 ;
struct V_352 * V_353 ;
int V_44 ;
struct V_52 * V_53 = NULL ;
V_353 = F_77 ( sizeof *V_353 , V_23 ) ;
if ( ! V_353 )
return - V_125 ;
V_353 -> V_63 = V_40 ;
F_223 ( & V_353 -> V_353 , F_220 ) ;
V_64 -> V_269 = F_77 ( sizeof * V_64 -> V_269 , V_23 ) ;
if ( ! V_64 -> V_269 ) {
V_44 = - V_125 ;
goto V_321;
}
V_64 -> V_309 = 1 ;
if ( V_65 -> V_66 . V_107 ) {
V_53 = F_63 ( & V_98 , V_65 -> V_66 . V_107 ) ;
if ( ! V_53 )
return - V_61 ;
if ( V_53 -> V_43 & V_99 ) {
F_65 ( V_53 ) ;
if ( ! V_40 -> V_63 . V_31 -> V_100 )
return - V_101 ;
V_53 = V_40 -> V_63 . V_31 -> V_100 ( V_40 -> V_63 . V_31 ,
V_40 -> V_63 . V_71 ) ;
if ( ! V_53 )
return - V_61 ;
}
V_64 -> V_269 -> V_6 = & V_98 ;
V_64 -> V_269 -> V_228 = V_53 -> V_228 ;
V_64 -> V_269 -> V_62 = V_40 -> V_62 ;
}
if ( ! V_53 ) {
V_44 = - V_61 ;
goto V_323;
}
memcpy ( V_64 -> V_269 -> V_390 , V_65 -> V_66 . V_391 , V_392 ) ;
F_68 ( (struct V_78 * ) & V_40 -> V_63 . V_64 . V_65 . V_79 ,
& V_64 -> V_269 -> V_111 ) ;
F_68 ( (struct V_78 * ) & V_40 -> V_63 . V_64 . V_65 . V_80 ,
& V_64 -> V_269 -> V_112 ) ;
if ( V_64 -> V_269 -> V_62 < F_233 ( V_65 -> V_66 . V_393 ) )
V_64 -> V_269 -> V_62 = F_233 ( V_65 -> V_66 . V_393 ) ;
if ( ( (struct V_78 * ) & V_40 -> V_63 . V_64 . V_65 . V_80 ) -> V_93 != V_94 )
V_64 -> V_269 -> V_394 = V_65 -> V_66 . V_395 ;
else
V_64 -> V_269 -> V_394 = 1 ;
V_64 -> V_269 -> V_363 = 1 ;
V_64 -> V_269 -> V_113 = F_218 ( 0xffff ) ;
V_64 -> V_269 -> V_396 = V_397 ;
V_64 -> V_269 -> V_398 = F_227 ( V_53 , V_40 -> V_347 ) ;
V_64 -> V_269 -> V_399 = F_234 ( V_53 -> V_399 ) ;
V_64 -> V_269 -> V_400 = V_397 ;
V_64 -> V_269 -> V_401 = F_235 ( V_53 ) ;
F_65 ( V_53 ) ;
V_64 -> V_269 -> V_402 = V_397 ;
V_64 -> V_269 -> V_403 = V_404 ;
if ( ! V_64 -> V_269 -> V_399 ) {
V_44 = - V_34 ;
goto V_323;
}
V_353 -> V_354 = V_262 ;
V_353 -> V_355 = V_381 ;
V_353 -> V_2 . V_2 = V_382 ;
V_353 -> V_2 . V_287 = 0 ;
F_214 ( V_358 , & V_353 -> V_353 ) ;
return 0 ;
V_323:
F_44 ( V_64 -> V_269 ) ;
V_64 -> V_269 = NULL ;
V_321:
F_44 ( V_353 ) ;
return V_44 ;
}
int F_236 ( struct V_120 * V_63 , int V_359 )
{
struct V_39 * V_40 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( ! F_25 ( V_40 , V_356 , V_262 ) )
return - V_34 ;
F_12 ( & V_40 -> V_26 ) ;
if ( F_163 ( V_63 -> V_31 , V_63 -> V_71 ) )
V_44 = F_222 ( V_40 , V_359 ) ;
else if ( F_62 ( V_63 -> V_31 , V_63 -> V_71 ) )
V_44 = F_232 ( V_40 ) ;
else if ( F_237 ( V_63 -> V_31 , V_63 -> V_71 ) )
V_44 = F_226 ( V_40 , V_359 ) ;
else
V_44 = - V_172 ;
if ( V_44 )
goto V_150;
return 0 ;
V_150:
F_25 ( V_40 , V_262 , V_356 ) ;
F_74 ( V_40 ) ;
return V_44 ;
}
static void F_238 ( struct V_78 * V_65 )
{
switch ( V_65 -> V_93 ) {
case V_173 :
( (struct V_174 * ) V_65 ) -> V_175 . V_176 = F_239 ( V_405 ) ;
break;
case V_177 :
F_240 ( & ( (struct V_178 * ) V_65 ) -> V_179 ,
0 , 0 , 0 , F_239 ( 1 ) ) ;
break;
default:
F_241 ( & ( (struct V_86 * ) V_65 ) -> V_91 ,
0 , 0 , 0 , F_239 ( 1 ) ) ;
break;
}
}
static int F_242 ( struct V_39 * V_40 )
{
struct V_24 * V_25 , * V_110 ;
struct V_406 V_407 ;
union V_54 V_95 ;
T_6 V_113 ;
int V_44 ;
T_4 V_114 ;
V_25 = NULL ;
F_14 ( & V_30 ) ;
F_15 (cur_dev, &dev_list, list) {
if ( F_49 ( V_40 ) == V_94 &&
! F_105 ( V_110 -> V_31 , 1 ) )
continue;
if ( ! V_25 )
V_25 = V_110 ;
for ( V_114 = 1 ; V_114 <= V_110 -> V_31 -> V_109 ; ++ V_114 ) {
if ( ! F_243 ( V_110 -> V_31 , V_114 , & V_407 ) &&
V_407 . V_45 == V_408 ) {
V_25 = V_110 ;
goto V_409;
}
}
}
if ( ! V_25 ) {
V_44 = - V_61 ;
goto V_108;
}
V_114 = 1 ;
V_409:
V_44 = F_73 ( V_25 -> V_31 , V_114 , 0 , & V_95 , NULL ) ;
if ( V_44 )
goto V_108;
V_44 = F_244 ( V_25 -> V_31 , V_114 , 0 , & V_113 ) ;
if ( V_44 )
goto V_108;
V_40 -> V_63 . V_64 . V_65 . V_66 . V_89 =
( F_61 ( V_25 -> V_31 , V_114 ) ) ?
V_90 : V_97 ;
F_55 ( & V_40 -> V_63 . V_64 . V_65 . V_66 , & V_95 ) ;
F_56 ( & V_40 -> V_63 . V_64 . V_65 . V_66 , V_113 ) ;
V_40 -> V_63 . V_71 = V_114 ;
F_38 ( V_40 , V_25 ) ;
F_238 ( F_47 ( V_40 ) ) ;
V_108:
F_16 ( & V_30 ) ;
return V_44 ;
}
static void F_245 ( int V_287 , struct V_78 * V_79 ,
struct V_88 * V_66 , void * V_122 )
{
struct V_39 * V_40 = V_122 ;
struct V_272 V_2 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
F_14 ( & V_40 -> V_119 ) ;
if ( ! F_25 ( V_40 , V_261 ,
V_356 ) )
goto V_108;
memcpy ( F_47 ( V_40 ) , V_79 , F_201 ( V_79 ) ) ;
if ( ! V_287 && ! V_40 -> V_25 )
V_287 = F_67 ( V_40 , NULL ) ;
if ( V_287 ) {
if ( ! F_25 ( V_40 , V_356 ,
V_348 ) )
goto V_108;
V_2 . V_2 = V_410 ;
V_2 . V_287 = V_287 ;
} else
V_2 . V_2 = V_411 ;
if ( V_40 -> V_63 . V_121 ( & V_40 -> V_63 , & V_2 ) ) {
F_26 ( V_40 , V_267 ) ;
F_16 ( & V_40 -> V_119 ) ;
F_74 ( V_40 ) ;
F_169 ( & V_40 -> V_63 ) ;
return;
}
V_108:
F_16 ( & V_40 -> V_119 ) ;
F_74 ( V_40 ) ;
}
static int F_246 ( struct V_39 * V_40 )
{
struct V_352 * V_353 ;
union V_54 V_95 ;
int V_44 ;
V_353 = F_77 ( sizeof *V_353 , V_23 ) ;
if ( ! V_353 )
return - V_125 ;
if ( ! V_40 -> V_25 ) {
V_44 = F_242 ( V_40 ) ;
if ( V_44 )
goto V_150;
}
F_216 ( & V_40 -> V_63 . V_64 . V_65 . V_66 , & V_95 ) ;
F_192 ( & V_40 -> V_63 . V_64 . V_65 . V_66 , & V_95 ) ;
V_353 -> V_63 = V_40 ;
F_223 ( & V_353 -> V_353 , F_220 ) ;
V_353 -> V_354 = V_261 ;
V_353 -> V_355 = V_356 ;
V_353 -> V_2 . V_2 = V_411 ;
F_214 ( V_358 , & V_353 -> V_353 ) ;
return 0 ;
V_150:
F_44 ( V_353 ) ;
return V_44 ;
}
static int F_247 ( struct V_39 * V_40 )
{
struct V_352 * V_353 ;
int V_44 ;
V_353 = F_77 ( sizeof *V_353 , V_23 ) ;
if ( ! V_353 )
return - V_125 ;
if ( ! V_40 -> V_25 ) {
V_44 = F_70 ( V_40 ) ;
if ( V_44 )
goto V_150;
}
F_192 ( & V_40 -> V_63 . V_64 . V_65 . V_66 , (union V_54 * )
& ( ( (struct V_86 * ) & V_40 -> V_63 . V_64 . V_65 . V_80 ) -> V_91 ) ) ;
V_353 -> V_63 = V_40 ;
F_223 ( & V_353 -> V_353 , F_220 ) ;
V_353 -> V_354 = V_261 ;
V_353 -> V_355 = V_356 ;
V_353 -> V_2 . V_2 = V_411 ;
F_214 ( V_358 , & V_353 -> V_353 ) ;
return 0 ;
V_150:
F_44 ( V_353 ) ;
return V_44 ;
}
static int F_248 ( struct V_120 * V_63 , struct V_78 * V_79 ,
struct V_78 * V_80 )
{
if ( ! V_79 || ! V_79 -> V_93 ) {
V_79 = (struct V_78 * ) & V_63 -> V_64 . V_65 . V_79 ;
V_79 -> V_93 = V_80 -> V_93 ;
if ( V_80 -> V_93 == V_177 ) {
struct V_178 * V_412 = (struct V_178 * ) V_79 ;
struct V_178 * V_413 = (struct V_178 * ) V_80 ;
V_412 -> V_414 = V_413 -> V_414 ;
if ( F_144 ( & V_413 -> V_179 ) & V_231 )
V_63 -> V_64 . V_65 . V_66 . V_107 = V_413 -> V_414 ;
} else if ( V_80 -> V_93 == V_94 ) {
( (struct V_86 * ) V_79 ) -> V_92 =
( (struct V_86 * ) V_80 ) -> V_92 ;
}
}
return F_249 ( V_63 , V_79 ) ;
}
int F_250 ( struct V_120 * V_63 , struct V_78 * V_79 ,
struct V_78 * V_80 , int V_359 )
{
struct V_39 * V_40 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( V_40 -> V_45 == V_128 ) {
V_44 = F_248 ( V_63 , V_79 , V_80 ) ;
if ( V_44 )
return V_44 ;
}
if ( F_49 ( V_40 ) != V_80 -> V_93 )
return - V_34 ;
if ( ! F_25 ( V_40 , V_348 , V_261 ) )
return - V_34 ;
F_12 ( & V_40 -> V_26 ) ;
memcpy ( F_48 ( V_40 ) , V_80 , F_201 ( V_80 ) ) ;
if ( F_117 ( V_80 ) ) {
V_44 = F_246 ( V_40 ) ;
} else {
if ( V_80 -> V_93 == V_94 ) {
V_44 = F_247 ( V_40 ) ;
} else {
V_44 = F_251 ( & V_415 , F_47 ( V_40 ) ,
V_80 , & V_63 -> V_64 . V_65 . V_66 ,
V_359 , F_245 , V_40 ) ;
}
}
if ( V_44 )
goto V_150;
return 0 ;
V_150:
F_25 ( V_40 , V_261 , V_348 ) ;
F_74 ( V_40 ) ;
return V_44 ;
}
int F_252 ( struct V_120 * V_63 , int V_416 )
{
struct V_39 * V_40 ;
unsigned long V_43 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
F_23 ( & V_40 -> V_30 , V_43 ) ;
if ( V_416 || V_40 -> V_45 == V_128 ) {
V_40 -> V_417 = V_416 ;
V_44 = 0 ;
} else {
V_44 = - V_34 ;
}
F_24 ( & V_40 -> V_30 , V_43 ) ;
return V_44 ;
}
int F_253 ( struct V_120 * V_63 , int V_248 )
{
struct V_39 * V_40 ;
unsigned long V_43 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
F_23 ( & V_40 -> V_30 , V_43 ) ;
if ( V_40 -> V_45 == V_128 || V_40 -> V_45 == V_348 ) {
V_40 -> V_418 |= ( 1 << V_419 ) ;
V_40 -> V_248 = V_248 ;
V_44 = 0 ;
} else {
V_44 = - V_34 ;
}
F_24 ( & V_40 -> V_30 , V_43 ) ;
return V_44 ;
}
static void F_254 ( struct V_20 * V_21 ,
struct V_39 * V_40 )
{
struct V_78 * V_65 ;
struct V_86 * V_87 ;
V_327 V_420 , V_421 ;
T_8 V_32 ;
V_65 = F_47 ( V_40 ) ;
V_32 = F_122 ( V_21 -> V_32 ) ;
switch ( V_65 -> V_93 ) {
case V_173 :
( (struct V_174 * ) V_65 ) -> V_182 = V_32 ;
break;
case V_177 :
( (struct V_178 * ) V_65 ) -> V_183 = V_32 ;
break;
case V_94 :
V_87 = (struct V_86 * ) V_65 ;
V_420 = F_123 ( V_87 -> V_184 ) ;
V_421 = F_123 ( V_87 -> V_185 ) ;
V_87 -> V_184 = F_126 ( ( V_420 & V_421 ) | ( V_327 ) F_57 ( V_32 ) ) ;
V_87 -> V_185 = F_126 ( ~ 0ULL ) ;
break;
}
V_40 -> V_21 = V_21 ;
F_255 ( & V_40 -> V_264 , & V_21 -> V_265 ) ;
}
static int F_256 ( enum V_9 V_10 ,
struct V_39 * V_40 , unsigned short V_22 )
{
struct V_20 * V_21 ;
int V_44 ;
V_21 = F_77 ( sizeof *V_21 , V_23 ) ;
if ( ! V_21 )
return - V_125 ;
V_44 = F_5 ( V_40 -> V_63 . V_64 . V_65 . V_66 . V_6 , V_10 , V_21 ,
V_22 ) ;
if ( V_44 < 0 )
goto V_150;
V_21 -> V_10 = V_10 ;
V_21 -> V_32 = ( unsigned short ) V_44 ;
F_254 ( V_21 , V_40 ) ;
return 0 ;
V_150:
F_44 ( V_21 ) ;
return V_44 == - V_422 ? - V_423 : V_44 ;
}
static int F_257 ( enum V_9 V_10 ,
struct V_39 * V_40 )
{
static unsigned int V_424 ;
int V_425 , V_426 , V_427 ;
unsigned int V_428 ;
struct V_6 * V_6 = V_40 -> V_63 . V_64 . V_65 . V_66 . V_6 ;
F_258 ( V_6 , & V_425 , & V_426 ) ;
V_427 = ( V_426 - V_425 ) + 1 ;
V_428 = F_259 () % V_427 + V_425 ;
V_429:
if ( V_424 != V_428 &&
! F_7 ( V_6 , V_10 , ( unsigned short ) V_428 ) ) {
int V_44 = F_256 ( V_10 , V_40 , V_428 ) ;
if ( ! V_44 )
V_424 = V_428 ;
if ( V_44 != - V_423 )
return V_44 ;
}
if ( -- V_427 ) {
V_428 ++ ;
if ( ( V_428 < V_425 ) || ( V_428 > V_426 ) )
V_428 = V_425 ;
goto V_429;
}
return - V_423 ;
}
static int F_260 ( struct V_20 * V_21 ,
struct V_39 * V_40 , T_12 V_417 )
{
struct V_39 * V_430 ;
struct V_78 * V_65 , * V_431 ;
V_65 = F_47 ( V_40 ) ;
F_158 (cur_id, &bind_list->owners, node) {
if ( V_40 == V_430 )
continue;
if ( ( V_430 -> V_45 != V_263 ) && V_417 &&
V_430 -> V_417 )
continue;
V_431 = F_47 ( V_430 ) ;
if ( V_40 -> V_248 && V_430 -> V_248 &&
( V_65 -> V_93 != V_431 -> V_93 ) )
continue;
if ( F_117 ( V_65 ) || F_117 ( V_431 ) )
return - V_423 ;
if ( ! F_118 ( V_65 , V_431 ) )
return - V_432 ;
}
return 0 ;
}
static int F_261 ( enum V_9 V_10 ,
struct V_39 * V_40 )
{
struct V_20 * V_21 ;
unsigned short V_22 ;
int V_44 ;
V_22 = F_57 ( F_121 ( F_47 ( V_40 ) ) ) ;
if ( V_22 < V_433 && ! F_262 ( V_434 ) )
return - V_435 ;
V_21 = F_7 ( V_40 -> V_63 . V_64 . V_65 . V_66 . V_6 , V_10 , V_22 ) ;
if ( ! V_21 ) {
V_44 = F_256 ( V_10 , V_40 , V_22 ) ;
} else {
V_44 = F_260 ( V_21 , V_40 , V_40 -> V_417 ) ;
if ( ! V_44 )
F_254 ( V_21 , V_40 ) ;
}
return V_44 ;
}
static int F_263 ( struct V_39 * V_40 )
{
struct V_20 * V_21 = V_40 -> V_21 ;
int V_44 = 0 ;
F_14 ( & V_30 ) ;
if ( V_21 -> V_265 . V_436 -> V_260 )
V_44 = F_260 ( V_21 , V_40 , 0 ) ;
F_16 ( & V_30 ) ;
return V_44 ;
}
static enum V_9 F_264 (
struct V_39 * V_40 )
{
switch ( V_40 -> V_63 . V_10 ) {
case V_12 :
case V_14 :
case V_16 :
case V_18 :
return V_40 -> V_63 . V_10 ;
default:
return 0 ;
}
}
static enum V_9 F_265 ( struct V_39 * V_40 )
{
enum V_9 V_10 = 0 ;
struct V_86 * V_87 ;
V_327 V_437 , V_421 , V_420 ;
V_87 = (struct V_86 * ) F_47 ( V_40 ) ;
V_421 = F_123 ( V_87 -> V_185 ) & V_438 ;
V_420 = F_123 ( V_87 -> V_184 ) & V_421 ;
if ( ( V_40 -> V_63 . V_10 == V_18 ) && ( V_420 == ( V_439 & V_421 ) ) ) {
V_437 = V_439 ;
V_10 = V_18 ;
} else if ( ( ( V_40 -> V_63 . V_10 == V_18 ) || ( V_40 -> V_63 . V_10 == V_12 ) ) &&
( V_420 == ( V_440 & V_421 ) ) ) {
V_437 = V_440 ;
V_10 = V_12 ;
} else if ( ( ( V_40 -> V_63 . V_10 == V_18 ) || ( V_40 -> V_63 . V_10 == V_14 ) ) &&
( V_420 == ( V_441 & V_421 ) ) ) {
V_437 = V_441 ;
V_10 = V_14 ;
}
if ( V_10 ) {
V_87 -> V_184 = F_126 ( V_437 | F_57 ( F_121 ( (struct V_78 * ) V_87 ) ) ) ;
V_87 -> V_185 = F_126 ( V_438 |
F_123 ( V_87 -> V_185 ) ) ;
}
return V_10 ;
}
static int F_266 ( struct V_39 * V_40 )
{
enum V_9 V_10 ;
int V_44 ;
if ( F_49 ( V_40 ) != V_94 )
V_10 = F_264 ( V_40 ) ;
else
V_10 = F_265 ( V_40 ) ;
if ( ! V_10 )
return - V_442 ;
F_14 ( & V_30 ) ;
if ( F_124 ( F_47 ( V_40 ) ) )
V_44 = F_257 ( V_10 , V_40 ) ;
else
V_44 = F_261 ( V_10 , V_40 ) ;
F_16 ( & V_30 ) ;
return V_44 ;
}
static int F_267 ( struct V_88 * V_66 ,
struct V_78 * V_65 )
{
#if F_143 ( V_229 )
struct V_178 * V_361 ;
if ( V_65 -> V_93 != V_177 )
return 0 ;
V_361 = (struct V_178 * ) V_65 ;
if ( ! ( F_144 ( & V_361 -> V_179 ) & V_231 ) )
return 0 ;
if ( ! V_361 -> V_414 )
return - V_34 ;
V_66 -> V_107 = V_361 -> V_414 ;
#endif
return 0 ;
}
int F_210 ( struct V_120 * V_63 , int V_346 )
{
struct V_39 * V_40 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( V_40 -> V_45 == V_128 ) {
V_63 -> V_64 . V_65 . V_79 . V_81 = V_173 ;
V_44 = F_249 ( V_63 , F_47 ( V_40 ) ) ;
if ( V_44 )
return V_44 ;
}
if ( ! F_25 ( V_40 , V_348 , V_263 ) )
return - V_34 ;
if ( V_40 -> V_417 ) {
V_44 = F_263 ( V_40 ) ;
if ( V_44 )
goto V_150;
}
V_40 -> V_346 = V_346 ;
if ( V_63 -> V_31 ) {
if ( F_105 ( V_63 -> V_31 , 1 ) ) {
V_44 = F_203 ( V_40 ) ;
if ( V_44 )
goto V_150;
} else if ( F_107 ( V_63 -> V_31 , 1 ) ) {
V_44 = F_205 ( V_40 , V_346 ) ;
if ( V_44 )
goto V_150;
} else {
V_44 = - V_172 ;
goto V_150;
}
} else
F_211 ( V_40 ) ;
return 0 ;
V_150:
V_40 -> V_346 = 0 ;
F_25 ( V_40 , V_263 , V_348 ) ;
return V_44 ;
}
int F_249 ( struct V_120 * V_63 , struct V_78 * V_65 )
{
struct V_39 * V_40 ;
int V_44 ;
if ( V_65 -> V_93 != V_173 && V_65 -> V_93 != V_177 &&
V_65 -> V_93 != V_94 )
return - V_205 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( ! F_25 ( V_40 , V_128 , V_348 ) )
return - V_34 ;
V_44 = F_267 ( & V_63 -> V_64 . V_65 . V_66 , V_65 ) ;
if ( V_44 )
goto V_321;
memcpy ( F_47 ( V_40 ) , V_65 , F_201 ( V_65 ) ) ;
if ( ! F_117 ( V_65 ) ) {
V_44 = F_58 ( V_65 , & V_63 -> V_64 . V_65 . V_66 ) ;
if ( V_44 )
goto V_321;
V_44 = F_67 ( V_40 , NULL ) ;
if ( V_44 )
goto V_321;
}
if ( ! ( V_40 -> V_418 & ( 1 << V_419 ) ) ) {
if ( V_65 -> V_93 == V_173 )
V_40 -> V_248 = 1 ;
#if F_143 ( V_229 )
else if ( V_65 -> V_93 == V_177 ) {
struct V_6 * V_6 = V_40 -> V_63 . V_64 . V_65 . V_66 . V_6 ;
V_40 -> V_248 = V_6 -> V_443 . V_444 . V_445 ;
}
#endif
}
V_44 = F_266 ( V_40 ) ;
if ( V_44 )
goto V_323;
return 0 ;
V_323:
if ( V_40 -> V_25 )
F_45 ( V_40 ) ;
V_321:
F_25 ( V_40 , V_348 , V_128 ) ;
return V_44 ;
}
static int F_268 ( void * V_49 , struct V_39 * V_40 )
{
struct V_48 * V_48 ;
V_48 = V_49 ;
V_48 -> V_203 = V_204 ;
if ( F_49 ( V_40 ) == V_173 ) {
struct V_174 * V_446 , * V_447 ;
V_446 = (struct V_174 * ) F_47 ( V_40 ) ;
V_447 = (struct V_174 * ) F_48 ( V_40 ) ;
F_28 ( V_48 , 4 ) ;
V_48 -> V_79 . V_196 . V_65 = V_446 -> V_175 . V_176 ;
V_48 -> V_80 . V_196 . V_65 = V_447 -> V_175 . V_176 ;
V_48 -> V_32 = V_446 -> V_182 ;
} else if ( F_49 ( V_40 ) == V_177 ) {
struct V_178 * V_448 , * V_449 ;
V_448 = (struct V_178 * ) F_47 ( V_40 ) ;
V_449 = (struct V_178 * ) F_48 ( V_40 ) ;
F_28 ( V_48 , 6 ) ;
V_48 -> V_79 . V_198 = V_448 -> V_179 ;
V_48 -> V_80 . V_198 = V_449 -> V_179 ;
V_48 -> V_32 = V_448 -> V_183 ;
}
return 0 ;
}
static int F_269 ( struct V_255 * V_169 ,
struct V_200 * V_201 )
{
struct V_39 * V_40 = V_169 -> V_122 ;
struct V_272 V_2 ;
struct V_450 * V_451 = & V_201 -> V_207 . V_452 ;
int V_44 = 0 ;
if ( F_75 ( V_40 , V_282 ) )
return 0 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_201 -> V_2 ) {
case V_453 :
V_2 . V_2 = V_286 ;
V_2 . V_287 = - V_288 ;
break;
case V_454 :
V_2 . V_207 . V_319 . V_202 = V_201 -> V_202 ;
V_2 . V_207 . V_319 . V_276 = V_455 ;
if ( V_451 -> V_287 != V_456 ) {
V_2 . V_2 = V_286 ;
V_2 . V_287 = V_201 -> V_207 . V_452 . V_287 ;
break;
}
V_44 = F_50 ( V_40 , V_451 -> V_82 ) ;
if ( V_44 ) {
V_2 . V_2 = V_410 ;
V_2 . V_287 = V_44 ;
break;
}
F_270 ( V_40 -> V_63 . V_31 , V_40 -> V_63 . V_71 ,
V_40 -> V_63 . V_64 . V_269 ,
& V_2 . V_207 . V_319 . V_155 ) ;
V_2 . V_207 . V_319 . V_151 = V_451 -> V_457 ;
V_2 . V_207 . V_319 . V_82 = V_451 -> V_82 ;
V_2 . V_2 = V_291 ;
V_2 . V_287 = 0 ;
break;
default:
F_188 ( V_307 L_3 ,
V_201 -> V_2 ) ;
goto V_108;
}
V_44 = V_40 -> V_63 . V_121 ( & V_40 -> V_63 , & V_2 ) ;
if ( V_44 ) {
V_40 -> V_169 . V_77 = NULL ;
F_26 ( V_40 , V_267 ) ;
F_16 ( & V_40 -> V_119 ) ;
F_169 ( & V_40 -> V_63 ) ;
return V_44 ;
}
V_108:
F_16 ( & V_40 -> V_119 ) ;
return V_44 ;
}
static int F_271 ( struct V_39 * V_40 ,
struct V_153 * V_154 )
{
struct V_458 V_212 ;
struct V_255 * V_63 ;
void * V_202 ;
int V_312 , V_44 ;
memset ( & V_212 , 0 , sizeof V_212 ) ;
V_312 = F_161 ( V_40 ) ;
V_212 . V_276 = V_312 + V_154 -> V_276 ;
if ( V_212 . V_276 < V_154 -> V_276 )
return - V_34 ;
if ( V_212 . V_276 ) {
V_202 = F_77 ( V_212 . V_276 , V_459 ) ;
if ( ! V_202 )
return - V_125 ;
} else {
V_202 = NULL ;
}
if ( V_154 -> V_202 && V_154 -> V_276 )
memcpy ( V_202 + V_312 , V_154 -> V_202 ,
V_154 -> V_276 ) ;
if ( V_202 ) {
V_44 = F_268 ( V_202 , V_40 ) ;
if ( V_44 )
goto V_108;
V_212 . V_202 = V_202 ;
}
V_63 = F_272 ( V_40 -> V_63 . V_31 , F_269 ,
V_40 ) ;
if ( F_93 ( V_63 ) ) {
V_44 = F_94 ( V_63 ) ;
goto V_108;
}
V_40 -> V_169 . V_77 = V_63 ;
V_212 . V_188 = V_40 -> V_63 . V_64 . V_269 ;
V_212 . V_193 = F_199 ( & V_40 -> V_63 , F_48 ( V_40 ) ) ;
V_212 . V_359 = 1 << ( V_460 - 8 ) ;
V_212 . V_461 = V_462 ;
V_44 = F_273 ( V_40 -> V_169 . V_77 , & V_212 ) ;
if ( V_44 ) {
F_179 ( V_40 -> V_169 . V_77 ) ;
V_40 -> V_169 . V_77 = NULL ;
}
V_108:
F_44 ( V_202 ) ;
return V_44 ;
}
static int F_274 ( struct V_39 * V_40 ,
struct V_153 * V_154 )
{
struct V_463 V_212 ;
struct V_308 * V_64 ;
void * V_202 ;
struct V_255 * V_63 ;
int V_312 , V_44 ;
memset ( & V_212 , 0 , sizeof V_212 ) ;
V_312 = F_161 ( V_40 ) ;
V_212 . V_276 = V_312 + V_154 -> V_276 ;
if ( V_212 . V_276 < V_154 -> V_276 )
return - V_34 ;
if ( V_212 . V_276 ) {
V_202 = F_77 ( V_212 . V_276 , V_459 ) ;
if ( ! V_202 )
return - V_125 ;
} else {
V_202 = NULL ;
}
if ( V_154 -> V_202 && V_154 -> V_276 )
memcpy ( V_202 + V_312 , V_154 -> V_202 ,
V_154 -> V_276 ) ;
V_63 = F_272 ( V_40 -> V_63 . V_31 , F_187 , V_40 ) ;
if ( F_93 ( V_63 ) ) {
V_44 = F_94 ( V_63 ) ;
goto V_108;
}
V_40 -> V_169 . V_77 = V_63 ;
V_64 = & V_40 -> V_63 . V_64 ;
if ( V_202 ) {
V_44 = F_268 ( V_202 , V_40 ) ;
if ( V_44 )
goto V_108;
V_212 . V_202 = V_202 ;
}
V_212 . V_209 = & V_64 -> V_269 [ 0 ] ;
if ( V_64 -> V_309 == 2 )
V_212 . V_310 = & V_64 -> V_269 [ 1 ] ;
V_212 . V_193 = F_199 ( & V_40 -> V_63 , F_48 ( V_40 ) ) ;
V_212 . V_151 = V_40 -> V_151 ;
V_212 . V_124 = V_40 -> V_63 . V_124 ;
V_212 . V_464 = V_40 -> V_132 ;
V_212 . V_159 = V_154 -> V_159 ;
V_212 . V_161 = V_154 -> V_161 ;
V_212 . V_278 = V_154 -> V_278 ;
V_212 . V_314 = F_275 ( T_4 , 7 , V_154 -> V_314 ) ;
V_212 . V_279 = F_275 ( T_4 , 7 , V_154 -> V_279 ) ;
V_212 . V_465 = V_460 ;
V_212 . V_466 = V_460 ;
V_212 . V_461 = V_462 ;
V_212 . V_152 = V_40 -> V_152 ? 1 : 0 ;
V_44 = F_276 ( V_40 -> V_169 . V_77 , & V_212 ) ;
V_108:
if ( V_44 && ! F_93 ( V_63 ) ) {
F_179 ( V_63 ) ;
V_40 -> V_169 . V_77 = NULL ;
}
F_44 ( V_202 ) ;
return V_44 ;
}
static int F_277 ( struct V_39 * V_40 ,
struct V_153 * V_154 )
{
struct V_328 * V_169 ;
int V_44 ;
struct V_467 V_468 ;
V_169 = F_206 ( V_40 -> V_63 . V_31 , F_200 , V_40 ) ;
if ( F_93 ( V_169 ) )
return F_94 ( V_169 ) ;
V_169 -> V_347 = V_40 -> V_347 ;
V_40 -> V_169 . V_171 = V_169 ;
memcpy ( & V_169 -> V_333 , F_47 ( V_40 ) ,
F_201 ( F_47 ( V_40 ) ) ) ;
memcpy ( & V_169 -> V_335 , F_48 ( V_40 ) ,
F_201 ( F_48 ( V_40 ) ) ) ;
V_44 = F_97 ( V_40 , V_154 ) ;
if ( V_44 )
goto V_108;
if ( V_154 ) {
V_468 . V_339 = V_154 -> V_161 ;
V_468 . V_338 = V_154 -> V_159 ;
V_468 . V_202 = V_154 -> V_202 ;
V_468 . V_276 = V_154 -> V_276 ;
V_468 . V_457 = V_40 -> V_63 . V_134 ? V_40 -> V_151 : V_154 -> V_151 ;
} else {
memset ( & V_468 , 0 , sizeof V_468 ) ;
V_468 . V_457 = V_40 -> V_151 ;
}
V_44 = F_278 ( V_169 , & V_468 ) ;
V_108:
if ( V_44 ) {
F_180 ( V_169 ) ;
V_40 -> V_169 . V_171 = NULL ;
}
return V_44 ;
}
int F_279 ( struct V_120 * V_63 , struct V_153 * V_154 )
{
struct V_39 * V_40 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( ! F_25 ( V_40 , V_381 , V_282 ) )
return - V_34 ;
if ( ! V_63 -> V_134 ) {
V_40 -> V_151 = V_154 -> V_151 ;
V_40 -> V_152 = V_154 -> V_152 ;
}
if ( F_105 ( V_63 -> V_31 , V_63 -> V_71 ) ) {
if ( V_63 -> V_124 == V_149 )
V_44 = F_271 ( V_40 , V_154 ) ;
else
V_44 = F_274 ( V_40 , V_154 ) ;
} else if ( F_107 ( V_63 -> V_31 , V_63 -> V_71 ) )
V_44 = F_277 ( V_40 , V_154 ) ;
else
V_44 = - V_172 ;
if ( V_44 )
goto V_150;
return 0 ;
V_150:
F_25 ( V_40 , V_282 , V_381 ) ;
return V_44 ;
}
static int F_280 ( struct V_39 * V_40 ,
struct V_153 * V_154 )
{
struct V_469 V_451 ;
int V_44 ;
V_44 = F_97 ( V_40 , V_154 ) ;
if ( V_44 )
goto V_108;
V_44 = F_100 ( V_40 , V_154 ) ;
if ( V_44 )
goto V_108;
memset ( & V_451 , 0 , sizeof V_451 ) ;
V_451 . V_151 = V_40 -> V_151 ;
V_451 . V_464 = V_40 -> V_132 ;
V_451 . V_202 = V_154 -> V_202 ;
V_451 . V_276 = V_154 -> V_276 ;
V_451 . V_159 = V_154 -> V_159 ;
V_451 . V_161 = V_154 -> V_161 ;
V_451 . V_470 = 0 ;
V_451 . V_278 = V_154 -> V_278 ;
V_451 . V_279 = F_275 ( T_4 , 7 , V_154 -> V_279 ) ;
V_451 . V_152 = V_40 -> V_152 ? 1 : 0 ;
V_44 = F_281 ( V_40 -> V_169 . V_77 , & V_451 ) ;
V_108:
return V_44 ;
}
static int F_282 ( struct V_39 * V_40 ,
struct V_153 * V_154 )
{
struct V_467 V_468 ;
int V_44 ;
V_44 = F_97 ( V_40 , V_154 ) ;
if ( V_44 )
return V_44 ;
V_468 . V_339 = V_154 -> V_161 ;
V_468 . V_338 = V_154 -> V_159 ;
V_468 . V_202 = V_154 -> V_202 ;
V_468 . V_276 = V_154 -> V_276 ;
if ( V_40 -> V_63 . V_134 ) {
V_468 . V_457 = V_40 -> V_151 ;
} else
V_468 . V_457 = V_154 -> V_151 ;
return F_283 ( V_40 -> V_169 . V_171 , & V_468 ) ;
}
static int F_284 ( struct V_39 * V_40 ,
enum V_471 V_287 , T_5 V_82 ,
const void * V_202 , int V_276 )
{
struct V_472 V_451 ;
int V_44 ;
memset ( & V_451 , 0 , sizeof V_451 ) ;
V_451 . V_287 = V_287 ;
if ( V_287 == V_456 ) {
V_44 = F_50 ( V_40 , V_82 ) ;
if ( V_44 )
return V_44 ;
V_451 . V_151 = V_40 -> V_151 ;
V_451 . V_82 = V_40 -> V_82 ;
}
V_451 . V_202 = V_202 ;
V_451 . V_276 = V_276 ;
return F_285 ( V_40 -> V_169 . V_77 , & V_451 ) ;
}
int F_286 ( struct V_120 * V_63 , struct V_153 * V_154 )
{
struct V_39 * V_40 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
V_40 -> V_126 = F_79 ( V_127 ) ;
if ( ! F_22 ( V_40 , V_282 ) )
return - V_34 ;
if ( ! V_63 -> V_134 && V_154 ) {
V_40 -> V_151 = V_154 -> V_151 ;
V_40 -> V_152 = V_154 -> V_152 ;
}
if ( F_105 ( V_63 -> V_31 , V_63 -> V_71 ) ) {
if ( V_63 -> V_124 == V_149 ) {
if ( V_154 )
V_44 = F_284 ( V_40 , V_456 ,
V_154 -> V_82 ,
V_154 -> V_202 ,
V_154 -> V_276 ) ;
else
V_44 = F_284 ( V_40 , V_456 ,
0 , NULL , 0 ) ;
} else {
if ( V_154 )
V_44 = F_280 ( V_40 , V_154 ) ;
else
V_44 = F_183 ( V_40 ) ;
}
} else if ( F_107 ( V_63 -> V_31 , V_63 -> V_71 ) )
V_44 = F_282 ( V_40 , V_154 ) ;
else
V_44 = - V_172 ;
if ( V_44 )
goto V_270;
return 0 ;
V_270:
F_101 ( V_40 ) ;
F_287 ( V_63 , NULL , 0 ) ;
return V_44 ;
}
int F_288 ( struct V_120 * V_63 , enum V_473 V_2 )
{
struct V_39 * V_40 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( ! V_40 -> V_169 . V_77 )
return - V_34 ;
switch ( V_63 -> V_31 -> V_68 ) {
case V_474 :
V_44 = F_289 ( V_40 -> V_169 . V_77 , V_2 ) ;
break;
default:
V_44 = 0 ;
break;
}
return V_44 ;
}
int F_287 ( struct V_120 * V_63 , const void * V_202 ,
T_4 V_276 )
{
struct V_39 * V_40 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( ! V_40 -> V_169 . V_77 )
return - V_34 ;
if ( F_105 ( V_63 -> V_31 , V_63 -> V_71 ) ) {
if ( V_63 -> V_124 == V_149 )
V_44 = F_284 ( V_40 , V_475 , 0 ,
V_202 , V_276 ) ;
else
V_44 = F_185 ( V_40 -> V_169 . V_77 ,
V_271 , NULL ,
0 , V_202 , V_276 ) ;
} else if ( F_107 ( V_63 -> V_31 , V_63 -> V_71 ) ) {
V_44 = F_290 ( V_40 -> V_169 . V_171 ,
V_202 , V_276 ) ;
} else
V_44 = - V_172 ;
return V_44 ;
}
int F_291 ( struct V_120 * V_63 )
{
struct V_39 * V_40 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( ! V_40 -> V_169 . V_77 )
return - V_34 ;
if ( F_105 ( V_63 -> V_31 , V_63 -> V_71 ) ) {
V_44 = F_101 ( V_40 ) ;
if ( V_44 )
goto V_108;
if ( F_292 ( V_40 -> V_169 . V_77 , NULL , 0 ) )
F_293 ( V_40 -> V_169 . V_77 , NULL , 0 ) ;
} else if ( F_107 ( V_63 -> V_31 , V_63 -> V_71 ) ) {
V_44 = F_294 ( V_40 -> V_169 . V_171 , 0 ) ;
} else
V_44 = - V_34 ;
V_108:
return V_44 ;
}
static int F_295 ( int V_287 , struct V_476 * V_76 )
{
struct V_39 * V_40 ;
struct V_73 * V_74 = V_76 -> V_122 ;
struct V_272 V_2 ;
int V_44 ;
V_40 = V_74 -> V_40 ;
if ( F_75 ( V_40 , V_348 ) &&
F_75 ( V_40 , V_356 ) )
return 0 ;
if ( ! V_287 )
V_287 = F_50 ( V_40 , F_53 ( V_76 -> V_84 . V_82 ) ) ;
F_14 ( & V_40 -> V_129 ) ;
if ( ! V_287 && V_40 -> V_63 . V_134 )
V_287 = F_296 ( V_40 -> V_63 . V_134 , & V_76 -> V_84 . V_55 ,
F_133 ( V_76 -> V_84 . V_477 ) ) ;
F_16 ( & V_40 -> V_129 ) ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_287 = V_287 ;
V_2 . V_207 . V_319 . V_202 = V_74 -> V_122 ;
if ( ! V_287 ) {
struct V_88 * V_66 =
& V_40 -> V_63 . V_64 . V_65 . V_66 ;
struct V_52 * V_53 =
F_63 ( & V_98 , V_66 -> V_107 ) ;
enum V_36 V_62 =
V_40 -> V_25 -> V_35 [ V_40 -> V_63 . V_71 -
V_33 ( V_40 -> V_25 -> V_31 ) ] ;
V_2 . V_2 = V_478 ;
F_297 ( V_40 -> V_63 . V_31 ,
V_40 -> V_63 . V_71 , & V_76 -> V_84 ,
V_53 , V_62 ,
& V_2 . V_207 . V_319 . V_155 ) ;
V_2 . V_207 . V_319 . V_151 = 0xFFFFFF ;
V_2 . V_207 . V_319 . V_82 = F_53 ( V_76 -> V_84 . V_82 ) ;
if ( V_53 )
F_65 ( V_53 ) ;
} else
V_2 . V_2 = V_479 ;
V_44 = V_40 -> V_63 . V_121 ( & V_40 -> V_63 , & V_2 ) ;
if ( V_44 ) {
F_26 ( V_40 , V_267 ) ;
F_16 ( & V_40 -> V_119 ) ;
F_169 ( & V_40 -> V_63 ) ;
return 0 ;
}
F_16 ( & V_40 -> V_119 ) ;
return 0 ;
}
static void F_298 ( struct V_39 * V_40 ,
struct V_78 * V_65 , union V_54 * V_55 )
{
unsigned char V_480 [ V_481 ] ;
struct V_88 * V_66 = & V_40 -> V_63 . V_64 . V_65 . V_66 ;
struct V_174 * sin = (struct V_174 * ) V_65 ;
struct V_178 * V_361 = (struct V_178 * ) V_65 ;
if ( F_117 ( V_65 ) ) {
memset ( V_55 , 0 , sizeof *V_55 ) ;
} else if ( ( V_65 -> V_93 == V_177 ) &&
( ( F_53 ( V_361 -> V_179 . V_482 [ 0 ] ) & 0xFFF0FFFF ) ==
0xFF10A01B ) ) {
memcpy ( V_55 , & V_361 -> V_179 , sizeof *V_55 ) ;
} else if ( V_65 -> V_93 == V_94 ) {
memcpy ( V_55 , & ( (struct V_86 * ) V_65 ) -> V_91 , sizeof *V_55 ) ;
} else if ( ( V_65 -> V_93 == V_177 ) ) {
F_299 ( & V_361 -> V_179 , V_66 -> V_483 , V_480 ) ;
if ( V_40 -> V_63 . V_10 == V_14 )
V_480 [ 7 ] = 0x01 ;
* V_55 = * (union V_54 * ) ( V_480 + 4 ) ;
} else {
F_300 ( sin -> V_175 . V_176 , V_66 -> V_483 , V_480 ) ;
if ( V_40 -> V_63 . V_10 == V_14 )
V_480 [ 7 ] = 0x01 ;
* V_55 = * (union V_54 * ) ( V_480 + 4 ) ;
}
}
static int F_301 ( struct V_39 * V_40 ,
struct V_73 * V_74 )
{
struct V_83 V_84 ;
struct V_88 * V_66 = & V_40 -> V_63 . V_64 . V_65 . V_66 ;
T_11 V_360 ;
int V_44 ;
F_51 ( V_66 , & V_84 . V_55 ) ;
V_44 = F_52 ( V_40 -> V_63 . V_31 , V_40 -> V_63 . V_71 ,
& V_84 . V_55 , & V_84 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_50 ( V_40 , 0 ) ;
if ( V_44 )
return V_44 ;
F_298 ( V_40 , (struct V_78 * ) & V_74 -> V_65 , & V_84 . V_55 ) ;
V_84 . V_82 = F_302 ( V_40 -> V_82 ) ;
F_216 ( V_66 , & V_84 . V_484 ) ;
V_84 . V_113 = F_218 ( F_104 ( V_66 ) ) ;
V_84 . V_485 = 1 ;
V_360 = V_486 | V_487 |
V_488 | V_489 |
V_490 | V_491 |
V_492 |
V_493 ;
if ( V_40 -> V_63 . V_10 == V_16 )
V_360 |= V_494 |
V_495 |
V_496 |
V_497 |
V_498 ;
V_74 -> V_76 . V_77 = F_303 ( & V_375 , V_40 -> V_63 . V_31 ,
V_40 -> V_63 . V_71 , & V_84 ,
V_360 , V_23 ,
F_295 , V_74 ) ;
return F_304 ( V_74 -> V_76 . V_77 ) ;
}
static void F_305 ( struct V_376 * V_353 )
{
struct V_499 * V_500 = F_43 ( V_353 , struct V_499 , V_353 ) ;
struct V_73 * V_74 = V_500 -> V_74 ;
struct V_476 * V_501 = V_74 -> V_76 . V_77 ;
V_74 -> V_76 . V_77 -> V_122 = V_74 ;
F_295 ( 0 , V_501 ) ;
F_178 ( & V_74 -> V_75 , F_42 ) ;
F_44 ( V_500 ) ;
}
static void F_306 ( struct V_78 * V_65 , union V_54 * V_55 )
{
struct V_174 * sin = (struct V_174 * ) V_65 ;
struct V_178 * V_361 = (struct V_178 * ) V_65 ;
if ( F_117 ( V_65 ) ) {
memset ( V_55 , 0 , sizeof *V_55 ) ;
} else if ( V_65 -> V_93 == V_177 ) {
memcpy ( V_55 , & V_361 -> V_179 , sizeof *V_55 ) ;
} else {
V_55 -> V_60 [ 0 ] = 0xff ;
V_55 -> V_60 [ 1 ] = 0x0e ;
V_55 -> V_60 [ 2 ] = 0 ;
V_55 -> V_60 [ 3 ] = 0 ;
V_55 -> V_60 [ 4 ] = 0 ;
V_55 -> V_60 [ 5 ] = 0 ;
V_55 -> V_60 [ 6 ] = 0 ;
V_55 -> V_60 [ 7 ] = 0 ;
V_55 -> V_60 [ 8 ] = 0 ;
V_55 -> V_60 [ 9 ] = 0 ;
V_55 -> V_60 [ 10 ] = 0xff ;
V_55 -> V_60 [ 11 ] = 0xff ;
* ( V_59 * ) ( & V_55 -> V_60 [ 12 ] ) = sin -> V_175 . V_176 ;
}
}
static int F_307 ( struct V_39 * V_40 ,
struct V_73 * V_74 )
{
struct V_499 * V_353 ;
struct V_88 * V_66 = & V_40 -> V_63 . V_64 . V_65 . V_66 ;
int V_150 = 0 ;
struct V_78 * V_65 = (struct V_78 * ) & V_74 -> V_65 ;
struct V_52 * V_53 = NULL ;
enum V_36 V_62 ;
if ( F_109 ( (struct V_78 * ) & V_74 -> V_65 ) )
return - V_34 ;
V_353 = F_77 ( sizeof *V_353 , V_23 ) ;
if ( ! V_353 )
return - V_125 ;
V_74 -> V_76 . V_77 = F_77 ( sizeof( struct V_476 ) , V_23 ) ;
if ( ! V_74 -> V_76 . V_77 ) {
V_150 = - V_125 ;
goto V_502;
}
F_306 ( V_65 , & V_74 -> V_76 . V_77 -> V_84 . V_55 ) ;
V_74 -> V_76 . V_77 -> V_84 . V_113 = F_218 ( 0xffff ) ;
if ( V_40 -> V_63 . V_10 == V_14 )
V_74 -> V_76 . V_77 -> V_84 . V_82 = F_302 ( V_85 ) ;
if ( V_66 -> V_107 )
V_53 = F_63 ( & V_98 , V_66 -> V_107 ) ;
if ( ! V_53 ) {
V_150 = - V_61 ;
goto V_503;
}
V_74 -> V_76 . V_77 -> V_84 . V_401 = F_235 ( V_53 ) ;
V_74 -> V_76 . V_77 -> V_84 . V_394 = 1 ;
V_74 -> V_76 . V_77 -> V_84 . V_399 = F_234 ( V_53 -> V_399 ) ;
V_62 = V_40 -> V_25 -> V_35 [ V_40 -> V_63 . V_71 -
V_33 ( V_40 -> V_25 -> V_31 ) ] ;
if ( V_65 -> V_93 == V_173 ) {
if ( V_62 == V_504 )
V_150 = F_29 ( V_53 , & V_74 -> V_76 . V_77 -> V_84 . V_55 ,
true ) ;
if ( ! V_150 ) {
V_74 -> V_266 = true ;
V_74 -> V_76 . V_77 -> V_84 . V_394 = V_505 ;
}
} else {
if ( V_62 == V_504 )
V_150 = - V_506 ;
}
F_65 ( V_53 ) ;
if ( V_150 || ! V_74 -> V_76 . V_77 -> V_84 . V_399 ) {
if ( ! V_150 )
V_150 = - V_34 ;
goto V_503;
}
F_68 ( (struct V_78 * ) & V_40 -> V_63 . V_64 . V_65 . V_79 ,
& V_74 -> V_76 . V_77 -> V_84 . V_484 ) ;
V_353 -> V_63 = V_40 ;
V_353 -> V_74 = V_74 ;
F_223 ( & V_353 -> V_353 , F_305 ) ;
F_308 ( & V_74 -> V_75 ) ;
F_214 ( V_358 , & V_353 -> V_353 ) ;
return 0 ;
V_503:
F_44 ( V_74 -> V_76 . V_77 ) ;
V_502:
F_44 ( V_353 ) ;
return V_150 ;
}
int F_309 ( struct V_120 * V_63 , struct V_78 * V_65 ,
void * V_122 )
{
struct V_39 * V_40 ;
struct V_73 * V_74 ;
int V_44 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
if ( ! F_22 ( V_40 , V_348 ) &&
! F_22 ( V_40 , V_356 ) )
return - V_34 ;
V_74 = F_190 ( sizeof *V_74 , V_23 ) ;
if ( ! V_74 )
return - V_125 ;
memcpy ( & V_74 -> V_65 , V_65 , F_201 ( V_65 ) ) ;
V_74 -> V_122 = V_122 ;
V_74 -> V_40 = V_40 ;
V_74 -> V_266 = false ;
F_310 ( & V_40 -> V_30 ) ;
F_311 ( & V_74 -> V_69 , & V_40 -> V_131 ) ;
F_312 ( & V_40 -> V_30 ) ;
if ( F_62 ( V_63 -> V_31 , V_63 -> V_71 ) ) {
F_313 ( & V_74 -> V_75 ) ;
V_44 = F_307 ( V_40 , V_74 ) ;
} else if ( F_176 ( V_63 -> V_31 , V_63 -> V_71 ) )
V_44 = F_301 ( V_40 , V_74 ) ;
else
V_44 = - V_172 ;
if ( V_44 ) {
F_314 ( & V_40 -> V_30 ) ;
F_46 ( & V_74 -> V_69 ) ;
F_315 ( & V_40 -> V_30 ) ;
F_44 ( V_74 ) ;
}
return V_44 ;
}
void F_316 ( struct V_120 * V_63 , struct V_78 * V_65 )
{
struct V_39 * V_40 ;
struct V_73 * V_74 ;
V_40 = F_43 ( V_63 , struct V_39 , V_63 ) ;
F_314 ( & V_40 -> V_30 ) ;
F_15 (mc, &id_priv->mc_list, list) {
if ( ! memcmp ( & V_74 -> V_65 , V_65 , F_201 ( V_65 ) ) ) {
F_46 ( & V_74 -> V_69 ) ;
F_315 ( & V_40 -> V_30 ) ;
if ( V_63 -> V_134 )
F_317 ( V_63 -> V_134 ,
& V_74 -> V_76 . V_77 -> V_84 . V_55 ,
F_133 ( V_74 -> V_76 . V_77 -> V_84 . V_477 ) ) ;
F_99 ( V_40 -> V_25 -> V_31 != V_63 -> V_31 ) ;
if ( F_176 ( V_63 -> V_31 , V_63 -> V_71 ) ) {
F_177 ( V_74 -> V_76 . V_77 ) ;
F_44 ( V_74 ) ;
} else if ( F_62 ( V_63 -> V_31 , V_63 -> V_71 ) ) {
if ( V_74 -> V_266 ) {
struct V_88 * V_66 =
& V_63 -> V_64 . V_65 . V_66 ;
struct V_52 * V_53 = NULL ;
if ( V_66 -> V_107 )
V_53 = F_63 ( & V_98 ,
V_66 -> V_107 ) ;
if ( V_53 ) {
F_29 ( V_53 ,
& V_74 -> V_76 . V_77 -> V_84 . V_55 ,
false ) ;
F_65 ( V_53 ) ;
}
V_74 -> V_266 = false ;
}
F_178 ( & V_74 -> V_75 , F_42 ) ;
}
return;
}
}
F_315 ( & V_40 -> V_30 ) ;
}
static int F_318 ( struct V_52 * V_53 , struct V_39 * V_40 )
{
struct V_88 * V_66 ;
struct V_379 * V_353 ;
V_66 = & V_40 -> V_63 . V_64 . V_65 . V_66 ;
if ( ( V_66 -> V_107 == V_53 -> V_228 ) &&
( F_156 ( F_139 ( V_53 ) , V_66 -> V_6 ) ) &&
memcmp ( V_66 -> V_106 , V_53 -> V_66 , V_53 -> V_507 ) ) {
F_188 ( V_508 L_6 ,
V_53 -> V_350 , & V_40 -> V_63 ) ;
V_353 = F_77 ( sizeof *V_353 , V_23 ) ;
if ( ! V_353 )
return - V_125 ;
F_223 ( & V_353 -> V_353 , F_221 ) ;
V_353 -> V_63 = V_40 ;
V_353 -> V_2 . V_2 = V_509 ;
F_12 ( & V_40 -> V_26 ) ;
F_214 ( V_358 , & V_353 -> V_353 ) ;
}
return 0 ;
}
static int F_319 ( struct V_510 * V_511 , unsigned long V_2 ,
void * V_512 )
{
struct V_52 * V_53 = F_320 ( V_512 ) ;
struct V_24 * V_25 ;
struct V_39 * V_40 ;
int V_44 = V_513 ;
if ( V_2 != V_514 )
return V_513 ;
if ( ! ( V_53 -> V_43 & V_515 ) || ! ( V_53 -> V_384 & V_516 ) )
return V_513 ;
F_14 ( & V_30 ) ;
F_15 (cma_dev, &dev_list, list)
F_15 (id_priv, &cma_dev->id_list, list) {
V_44 = F_318 ( V_53 , V_40 ) ;
if ( V_44 )
goto V_108;
}
V_108:
F_16 ( & V_30 ) ;
return V_44 ;
}
static void F_321 ( struct V_38 * V_31 )
{
struct V_24 * V_25 ;
struct V_39 * V_40 ;
unsigned int V_115 ;
unsigned long V_37 = 0 ;
V_25 = F_190 ( sizeof *V_25 , V_23 ) ;
if ( ! V_25 )
return;
V_25 -> V_31 = V_31 ;
V_25 -> V_35 = F_322 ( V_31 -> V_109 ,
sizeof( * V_25 -> V_35 ) ,
V_23 ) ;
if ( ! V_25 -> V_35 ) {
F_44 ( V_25 ) ;
return;
}
for ( V_115 = V_33 ( V_31 ) ; V_115 <= F_18 ( V_31 ) ; V_115 ++ ) {
V_37 = F_20 ( V_31 , V_115 ) ;
F_323 ( ! V_37 ) ;
V_25 -> V_35 [ V_115 - V_33 ( V_31 ) ] =
F_324 ( & V_37 , V_517 ) ;
}
F_82 ( & V_25 -> V_42 ) ;
F_83 ( & V_25 -> V_26 , 1 ) ;
F_84 ( & V_25 -> V_70 ) ;
F_325 ( V_31 , & V_518 , V_25 ) ;
F_14 ( & V_30 ) ;
F_37 ( & V_25 -> V_69 , & V_519 ) ;
F_15 (id_priv, &listen_any_list, list)
F_209 ( V_40 , V_25 ) ;
F_16 ( & V_30 ) ;
}
static int F_326 ( struct V_39 * V_40 )
{
struct V_272 V_2 ;
enum V_41 V_45 ;
int V_44 = 0 ;
V_45 = F_26 ( V_40 , V_380 ) ;
if ( V_45 == V_267 )
return 0 ;
F_170 ( V_40 , V_45 ) ;
F_14 ( & V_40 -> V_119 ) ;
if ( ! F_22 ( V_40 , V_380 ) )
goto V_108;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_520 ;
V_44 = V_40 -> V_63 . V_121 ( & V_40 -> V_63 , & V_2 ) ;
V_108:
F_16 ( & V_40 -> V_119 ) ;
return V_44 ;
}
static void F_327 ( struct V_24 * V_25 )
{
struct V_39 * V_40 ;
int V_44 ;
F_14 ( & V_30 ) ;
while ( ! F_166 ( & V_25 -> V_70 ) ) {
V_40 = F_167 ( V_25 -> V_70 . V_260 ,
struct V_39 , V_69 ) ;
F_46 ( & V_40 -> V_130 ) ;
F_168 ( & V_40 -> V_69 ) ;
F_12 ( & V_40 -> V_26 ) ;
F_16 ( & V_30 ) ;
V_44 = V_40 -> V_268 ? 1 : F_326 ( V_40 ) ;
F_74 ( V_40 ) ;
if ( V_44 )
F_169 ( & V_40 -> V_63 ) ;
F_14 ( & V_30 ) ;
}
F_16 ( & V_30 ) ;
F_39 ( V_25 ) ;
F_181 ( & V_25 -> V_42 ) ;
}
static void F_328 ( struct V_38 * V_31 , void * V_521 )
{
struct V_24 * V_25 = V_521 ;
if ( ! V_25 )
return;
F_14 ( & V_30 ) ;
F_46 ( & V_25 -> V_69 ) ;
F_16 ( & V_30 ) ;
F_327 ( V_25 ) ;
F_44 ( V_25 -> V_35 ) ;
F_44 ( V_25 ) ;
}
static int F_329 ( struct V_522 * V_523 , struct V_524 * V_525 )
{
struct V_526 * V_527 ;
struct V_528 * V_529 ;
struct V_39 * V_40 ;
struct V_120 * V_63 = NULL ;
struct V_24 * V_25 ;
int V_530 = 0 , V_531 = 0 ;
F_14 ( & V_30 ) ;
F_15 (cma_dev, &dev_list, list) {
if ( V_530 < V_525 -> args [ 0 ] ) {
V_530 ++ ;
continue;
}
V_531 = 0 ;
F_15 (id_priv, &cma_dev->id_list, list) {
if ( V_531 < V_525 -> args [ 1 ] ) {
V_531 ++ ;
continue;
}
V_529 = F_330 ( V_523 , & V_527 , V_525 -> V_527 -> V_532 ,
sizeof *V_529 , V_533 ,
V_534 ,
V_535 ) ;
if ( ! V_529 )
goto V_108;
memset ( V_529 , 0 , sizeof *V_529 ) ;
V_63 = & V_40 -> V_63 ;
V_529 -> V_68 = V_63 -> V_64 . V_65 . V_66 . V_89 ;
V_529 -> V_71 = V_63 -> V_71 ;
V_529 -> V_107 =
V_63 -> V_64 . V_65 . V_66 . V_107 ;
if ( F_331 ( V_523 , V_527 ,
F_201 ( F_47 ( V_40 ) ) ,
F_47 ( V_40 ) ,
V_536 ) )
goto V_108;
if ( F_331 ( V_523 , V_527 ,
F_201 ( F_47 ( V_40 ) ) ,
F_48 ( V_40 ) ,
V_537 ) )
goto V_108;
V_529 -> V_538 = V_40 -> V_126 ;
V_529 -> V_539 = V_63 -> V_10 ;
V_529 -> V_540 = V_40 -> V_45 ;
V_529 -> V_151 = V_40 -> V_151 ;
V_529 -> V_124 = V_63 -> V_124 ;
V_531 ++ ;
}
V_525 -> args [ 1 ] = 0 ;
V_530 ++ ;
}
V_108:
F_16 ( & V_30 ) ;
V_525 -> args [ 0 ] = V_530 ;
V_525 -> args [ 1 ] = V_531 ;
return V_523 -> V_541 ;
}
static int F_332 ( struct V_6 * V_6 )
{
struct V_5 * V_11 = V_5 ( V_6 ) ;
F_333 ( & V_11 -> V_13 ) ;
F_333 ( & V_11 -> V_15 ) ;
F_333 ( & V_11 -> V_17 ) ;
F_333 ( & V_11 -> V_19 ) ;
return 0 ;
}
static void F_334 ( struct V_6 * V_6 )
{
struct V_5 * V_11 = V_5 ( V_6 ) ;
F_335 ( & V_11 -> V_13 ) ;
F_335 ( & V_11 -> V_15 ) ;
F_335 ( & V_11 -> V_17 ) ;
F_335 ( & V_11 -> V_19 ) ;
}
static int T_13 F_336 ( void )
{
int V_44 ;
V_358 = F_337 ( L_7 ) ;
if ( ! V_358 )
return - V_125 ;
V_44 = F_338 ( & V_542 ) ;
if ( V_44 )
goto V_543;
F_339 ( & V_375 ) ;
F_340 ( & V_415 ) ;
F_341 ( & V_544 ) ;
V_44 = F_342 ( & V_518 ) ;
if ( V_44 )
goto V_150;
if ( F_343 ( V_533 , V_545 , V_546 ) )
F_188 ( V_349 L_8 ) ;
F_344 () ;
return 0 ;
V_150:
F_345 ( & V_544 ) ;
F_346 ( & V_415 ) ;
F_347 ( & V_375 ) ;
V_543:
F_348 ( V_358 ) ;
return V_44 ;
}
static void T_14 F_349 ( void )
{
F_350 () ;
F_351 ( V_533 ) ;
F_352 ( & V_518 ) ;
F_345 ( & V_544 ) ;
F_346 ( & V_415 ) ;
F_347 ( & V_375 ) ;
F_353 ( & V_542 ) ;
F_348 ( V_358 ) ;
}
