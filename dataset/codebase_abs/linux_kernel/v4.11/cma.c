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
if ( ! F_26 ( V_41 -> V_8 , V_47 ) )
return - V_48 ;
return V_41 -> V_49 [ V_47 - F_27 ( V_41 -> V_8 ) ] ;
}
int F_28 ( struct V_40 * V_41 ,
unsigned int V_47 ,
enum V_50 V_49 )
{
unsigned long V_51 ;
if ( ! F_26 ( V_41 -> V_8 , V_47 ) )
return - V_48 ;
V_51 = F_29 ( V_41 -> V_8 , V_47 ) ;
if ( ! ( V_51 & 1 << V_49 ) )
return - V_48 ;
V_41 -> V_49 [ V_47 - F_27 ( V_41 -> V_8 ) ] =
V_49 ;
return 0 ;
}
int F_30 ( struct V_40 * V_41 , unsigned int V_47 )
{
if ( ! F_26 ( V_41 -> V_8 , V_47 ) )
return - V_48 ;
return V_41 -> V_52 [ V_47 - F_27 ( V_41 -> V_8 ) ] ;
}
int F_31 ( struct V_40 * V_41 , unsigned int V_47 ,
T_3 V_52 )
{
if ( ! F_26 ( V_41 -> V_8 , V_47 ) )
return - V_48 ;
V_41 -> V_52 [ V_47 - F_27 ( V_41 -> V_8 ) ] =
V_52 ;
return 0 ;
}
struct V_53 * F_32 ( struct V_40 * V_41 )
{
return V_41 -> V_8 ;
}
static int F_33 ( struct V_54 * V_55 , enum V_56 V_57 )
{
unsigned long V_58 ;
int V_59 ;
F_34 ( & V_55 -> V_46 , V_58 ) ;
V_59 = ( V_55 -> V_60 == V_57 ) ;
F_35 ( & V_55 -> V_46 , V_58 ) ;
return V_59 ;
}
static int F_36 ( struct V_54 * V_55 ,
enum V_56 V_57 , enum V_56 V_61 )
{
unsigned long V_58 ;
int V_59 ;
F_34 ( & V_55 -> V_46 , V_58 ) ;
if ( ( V_59 = ( V_55 -> V_60 == V_57 ) ) )
V_55 -> V_60 = V_61 ;
F_35 ( & V_55 -> V_46 , V_58 ) ;
return V_59 ;
}
static enum V_56 F_37 ( struct V_54 * V_55 ,
enum V_56 V_61 )
{
unsigned long V_58 ;
enum V_56 V_62 ;
F_34 ( & V_55 -> V_46 , V_58 ) ;
V_62 = V_55 -> V_60 ;
V_55 -> V_60 = V_61 ;
F_35 ( & V_55 -> V_46 , V_58 ) ;
return V_62 ;
}
static inline T_3 F_38 ( const struct V_63 * V_64 )
{
return V_64 -> V_65 >> 4 ;
}
static inline void F_39 ( struct V_63 * V_64 , T_3 V_66 )
{
V_64 -> V_65 = ( V_66 << 4 ) | ( V_64 -> V_65 & 0xF ) ;
}
static int F_40 ( struct V_67 * V_68 , union V_69 * V_70 , bool V_71 )
{
struct V_72 * V_73 = NULL ;
if ( V_68 ) {
F_41 () ;
V_73 = F_42 ( V_68 ) ;
if ( V_73 ) {
if ( V_71 )
F_43 ( V_73 ,
* ( V_74 * ) ( V_70 -> V_75 + 12 ) ) ;
else
F_44 ( V_73 ,
* ( V_74 * ) ( V_70 -> V_75 + 12 ) ) ;
}
F_45 () ;
}
return ( V_73 ) ? 0 : - V_76 ;
}
static void F_46 ( struct V_54 * V_55 ,
struct V_40 * V_41 )
{
F_19 ( V_41 ) ;
V_55 -> V_41 = V_41 ;
V_55 -> V_77 = 0 ;
V_55 -> V_6 . V_8 = V_41 -> V_8 ;
V_55 -> V_6 . V_78 . V_79 . V_80 . V_81 =
F_47 ( V_41 -> V_8 -> V_82 ) ;
F_48 ( & V_55 -> V_83 , & V_41 -> V_84 ) ;
}
static void F_49 ( struct V_54 * V_55 ,
struct V_40 * V_41 )
{
F_46 ( V_55 , V_41 ) ;
V_55 -> V_77 =
V_41 -> V_49 [ V_55 -> V_6 . V_9 -
F_27 ( V_41 -> V_8 ) ] ;
}
void F_50 ( struct V_40 * V_41 )
{
if ( F_51 ( & V_41 -> V_42 ) )
F_52 ( & V_41 -> V_57 ) ;
}
static inline void F_53 ( struct V_85 * V_85 )
{
struct V_86 * V_87 = F_54 ( V_85 , struct V_86 , V_88 ) ;
F_55 ( V_87 -> V_89 . V_90 ) ;
F_55 ( V_87 ) ;
}
static void F_56 ( struct V_54 * V_55 )
{
F_22 ( & V_46 ) ;
F_57 ( & V_55 -> V_83 ) ;
F_50 ( V_55 -> V_41 ) ;
V_55 -> V_41 = NULL ;
F_24 ( & V_46 ) ;
}
static inline struct V_91 * F_58 ( struct V_54 * V_55 )
{
return (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_92 ;
}
static inline struct V_91 * F_59 ( struct V_54 * V_55 )
{
return (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_93 ;
}
static inline unsigned short F_60 ( struct V_54 * V_55 )
{
return V_55 -> V_6 . V_78 . V_79 . V_92 . V_94 ;
}
static int F_61 ( struct V_54 * V_55 , T_5 V_95 )
{
struct V_96 V_97 ;
int V_59 = 0 ;
if ( V_55 -> V_95 ) {
if ( V_95 && V_55 -> V_95 != V_95 )
return - V_48 ;
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
F_62 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , & V_97 . V_70 ) ;
V_59 = F_63 ( V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 , & V_97 . V_70 ,
& V_97 ) ;
if ( ! V_59 )
V_55 -> V_95 = F_64 ( V_97 . V_95 ) ;
break;
default:
break;
}
return V_59 ;
}
static void F_65 ( struct V_99 * V_100 , struct V_101 * V_80 )
{
V_80 -> V_102 = V_103 ;
F_66 ( V_80 , (union V_69 * ) & V_100 -> V_104 ) ;
F_67 ( V_80 , F_68 ( V_100 -> V_105 ) ) ;
}
static int F_69 ( struct V_91 * V_79 , struct V_101 * V_80 )
{
int V_59 ;
if ( V_79 -> V_106 != V_107 ) {
V_59 = F_70 ( V_79 , V_80 , NULL ) ;
} else {
F_65 ( (struct V_99 * ) V_79 , V_80 ) ;
V_59 = 0 ;
}
return V_59 ;
}
static inline int F_71 ( struct V_53 * V_8 , T_3 V_47 ,
enum V_50 V_77 ,
union V_69 * V_108 , int V_102 ,
int V_109 )
{
int V_59 = - V_76 ;
struct V_67 * V_68 = NULL ;
if ( ( V_102 == V_103 ) && ! F_72 ( V_8 , V_47 ) )
return V_59 ;
if ( ( V_102 != V_103 ) && F_72 ( V_8 , V_47 ) )
return V_59 ;
if ( V_102 == V_110 && F_73 ( V_8 , V_47 ) ) {
V_68 = F_74 ( & V_111 , V_109 ) ;
if ( V_68 && V_68 -> V_58 & V_112 ) {
F_75 ( L_3 ) ;
F_76 ( V_68 ) ;
if ( ! V_8 -> V_113 )
return - V_114 ;
V_68 = V_8 -> V_113 ( V_8 , V_47 ) ;
if ( ! V_68 )
return - V_76 ;
}
} else {
V_77 = V_115 ;
}
V_59 = F_77 ( V_8 , V_108 , V_77 , V_47 ,
V_68 , NULL ) ;
if ( V_68 )
F_76 ( V_68 ) ;
return V_59 ;
}
static int F_78 ( struct V_54 * V_55 ,
struct V_54 * V_116 )
{
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
struct V_40 * V_41 ;
union V_69 V_108 , V_117 , * V_118 ;
int V_59 = - V_76 ;
T_3 V_47 ;
if ( V_80 -> V_102 != V_103 &&
V_55 -> V_6 . V_26 == V_32 )
return - V_48 ;
F_22 ( & V_46 ) ;
F_79 ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_92 ,
& V_117 ) ;
memcpy ( & V_108 , V_80 -> V_119 +
F_80 ( V_80 ) , sizeof V_108 ) ;
if ( V_116 ) {
V_41 = V_116 -> V_41 ;
V_47 = V_116 -> V_6 . V_9 ;
V_118 = F_73 ( V_41 -> V_8 , V_47 ) ?
& V_117 : & V_108 ;
V_59 = F_71 ( V_41 -> V_8 , V_47 ,
F_72 ( V_41 -> V_8 , V_47 ) ?
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
V_118 = F_73 ( V_41 -> V_8 , V_47 ) ?
& V_117 : & V_108 ;
V_59 = F_71 ( V_41 -> V_8 , V_47 ,
F_72 ( V_41 -> V_8 , V_47 ) ?
V_115 :
V_41 -> V_49 [ V_47 - 1 ] ,
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
F_49 ( V_55 , V_41 ) ;
F_24 ( & V_46 ) ;
return V_59 ;
}
static int F_81 ( struct V_54 * V_55 )
{
struct V_40 * V_41 , * V_123 ;
struct V_99 * V_79 ;
union V_69 V_108 , V_124 , * V_125 ;
T_6 V_126 , V_3 ;
T_3 V_15 ;
enum V_127 V_128 ;
int V_129 ;
V_41 = NULL ;
V_79 = (struct V_99 * ) F_59 ( V_55 ) ;
V_125 = (union V_69 * ) & V_79 -> V_104 ;
V_126 = F_68 ( V_79 -> V_105 ) ;
F_23 (cur_dev, &dev_list, list) {
for ( V_15 = 1 ; V_15 <= V_123 -> V_8 -> V_122 ; ++ V_15 ) {
if ( ! F_82 ( V_123 -> V_8 , V_15 ) )
continue;
if ( F_83 ( V_123 -> V_8 , V_15 , V_126 , & V_3 ) )
continue;
if ( F_84 ( V_123 -> V_8 , V_15 , & V_128 ) )
continue;
for ( V_129 = 0 ; ! F_85 ( V_123 -> V_8 , V_15 , V_129 ,
& V_108 , NULL ) ;
V_129 ++ ) {
if ( ! memcmp ( & V_108 , V_125 , sizeof( V_108 ) ) ) {
V_41 = V_123 ;
V_124 = V_108 ;
V_55 -> V_6 . V_9 = V_15 ;
goto V_130;
}
if ( ! V_41 && ( V_108 . V_131 . V_132 ==
V_125 -> V_131 . V_132 ) &&
V_128 == V_133 ) {
V_41 = V_123 ;
V_124 = V_108 ;
V_55 -> V_6 . V_9 = V_15 ;
}
}
}
}
if ( ! V_41 )
return - V_76 ;
V_130:
F_49 ( V_55 , V_41 ) ;
V_79 = (struct V_99 * ) F_58 ( V_55 ) ;
memcpy ( & V_79 -> V_104 , & V_124 , sizeof V_124 ) ;
F_65 ( V_79 , & V_55 -> V_6 . V_78 . V_79 . V_80 ) ;
return 0 ;
}
static void F_86 ( struct V_54 * V_55 )
{
if ( F_51 ( & V_55 -> V_42 ) )
F_52 ( & V_55 -> V_57 ) ;
}
struct V_5 * F_87 ( struct V_22 * V_22 ,
T_7 V_134 ,
void * V_135 , enum V_25 V_26 ,
enum V_136 V_137 )
{
struct V_54 * V_55 ;
V_55 = F_88 ( sizeof *V_55 , V_39 ) ;
if ( ! V_55 )
return F_89 ( - V_138 ) ;
V_55 -> V_139 = F_90 ( V_140 ) ;
V_55 -> V_60 = V_141 ;
V_55 -> V_6 . V_135 = V_135 ;
V_55 -> V_6 . V_134 = V_134 ;
V_55 -> V_6 . V_26 = V_26 ;
V_55 -> V_6 . V_137 = V_137 ;
V_55 -> V_142 = false ;
F_91 ( & V_55 -> V_46 ) ;
F_92 ( & V_55 -> V_143 ) ;
F_93 ( & V_55 -> V_57 ) ;
F_94 ( & V_55 -> V_42 , 1 ) ;
F_92 ( & V_55 -> V_144 ) ;
F_95 ( & V_55 -> V_145 ) ;
F_95 ( & V_55 -> V_146 ) ;
F_96 ( & V_55 -> V_147 , sizeof V_55 -> V_147 ) ;
V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 = F_97 ( V_22 ) ;
return & V_55 -> V_6 ;
}
static int F_98 ( struct V_54 * V_55 , struct V_148 * V_149 )
{
struct V_150 V_151 ;
int V_152 , V_59 ;
V_151 . V_153 = V_154 ;
V_59 = F_99 ( & V_55 -> V_6 , & V_151 , & V_152 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_100 ( V_149 , & V_151 , V_152 ) ;
if ( V_59 )
return V_59 ;
V_151 . V_153 = V_155 ;
V_59 = F_100 ( V_149 , & V_151 , V_156 ) ;
if ( V_59 )
return V_59 ;
V_151 . V_153 = V_157 ;
V_151 . V_158 = 0 ;
V_59 = F_100 ( V_149 , & V_151 , V_156 | V_159 ) ;
return V_59 ;
}
static int F_101 ( struct V_54 * V_55 , struct V_148 * V_149 )
{
struct V_150 V_151 ;
int V_152 , V_59 ;
V_151 . V_153 = V_154 ;
V_59 = F_99 ( & V_55 -> V_6 , & V_151 , & V_152 ) ;
if ( V_59 )
return V_59 ;
return F_100 ( V_149 , & V_151 , V_152 ) ;
}
int F_102 ( struct V_5 * V_6 , struct V_160 * V_161 ,
struct V_162 * V_163 )
{
struct V_54 * V_55 ;
struct V_148 * V_149 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( V_6 -> V_8 != V_161 -> V_8 )
return - V_48 ;
V_163 -> V_9 = V_6 -> V_9 ;
V_149 = F_103 ( V_161 , V_163 ) ;
if ( F_104 ( V_149 ) )
return F_105 ( V_149 ) ;
if ( V_6 -> V_137 == V_164 )
V_59 = F_98 ( V_55 , V_149 ) ;
else
V_59 = F_101 ( V_55 , V_149 ) ;
if ( V_59 )
goto V_165;
V_6 -> V_149 = V_149 ;
V_55 -> V_166 = V_149 -> V_166 ;
V_55 -> V_167 = ( V_149 -> V_167 != NULL ) ;
return 0 ;
V_165:
F_106 ( V_149 ) ;
return V_59 ;
}
void F_107 ( struct V_5 * V_6 )
{
struct V_54 * V_55 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
F_22 ( & V_55 -> V_143 ) ;
F_106 ( V_55 -> V_6 . V_149 ) ;
V_55 -> V_6 . V_149 = NULL ;
F_24 ( & V_55 -> V_143 ) ;
}
static int F_108 ( struct V_54 * V_55 ,
struct V_168 * V_169 )
{
struct V_150 V_151 ;
int V_152 , V_59 ;
union V_69 V_124 ;
F_22 ( & V_55 -> V_143 ) ;
if ( ! V_55 -> V_6 . V_149 ) {
V_59 = 0 ;
goto V_121;
}
V_151 . V_153 = V_154 ;
V_59 = F_99 ( & V_55 -> V_6 , & V_151 , & V_152 ) ;
if ( V_59 )
goto V_121;
V_59 = F_100 ( V_55 -> V_6 . V_149 , & V_151 , V_152 ) ;
if ( V_59 )
goto V_121;
V_151 . V_153 = V_155 ;
V_59 = F_99 ( & V_55 -> V_6 , & V_151 , & V_152 ) ;
if ( V_59 )
goto V_121;
V_59 = F_109 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ,
V_151 . V_170 . V_171 . V_172 , & V_124 , NULL ) ;
if ( V_59 )
goto V_121;
F_110 ( V_55 -> V_41 -> V_8 != V_55 -> V_6 . V_8 ) ;
if ( V_169 )
V_151 . V_173 = V_169 -> V_174 ;
V_59 = F_100 ( V_55 -> V_6 . V_149 , & V_151 , V_152 ) ;
V_121:
F_24 ( & V_55 -> V_143 ) ;
return V_59 ;
}
static int F_111 ( struct V_54 * V_55 ,
struct V_168 * V_169 )
{
struct V_150 V_151 ;
int V_152 , V_59 ;
F_22 ( & V_55 -> V_143 ) ;
if ( ! V_55 -> V_6 . V_149 ) {
V_59 = 0 ;
goto V_121;
}
V_151 . V_153 = V_157 ;
V_59 = F_99 ( & V_55 -> V_6 , & V_151 , & V_152 ) ;
if ( V_59 )
goto V_121;
if ( V_169 )
V_151 . V_175 = V_169 -> V_176 ;
V_59 = F_100 ( V_55 -> V_6 . V_149 , & V_151 , V_152 ) ;
V_121:
F_24 ( & V_55 -> V_143 ) ;
return V_59 ;
}
static int F_112 ( struct V_54 * V_55 )
{
struct V_150 V_151 ;
int V_59 ;
F_22 ( & V_55 -> V_143 ) ;
if ( ! V_55 -> V_6 . V_149 ) {
V_59 = 0 ;
goto V_121;
}
V_151 . V_153 = V_177 ;
V_59 = F_100 ( V_55 -> V_6 . V_149 , & V_151 , V_156 ) ;
V_121:
F_24 ( & V_55 -> V_143 ) ;
return V_59 ;
}
static int F_113 ( struct V_54 * V_55 ,
struct V_150 * V_151 , int * V_152 )
{
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
int V_59 ;
T_6 V_126 ;
if ( F_114 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ) )
V_126 = 0xffff ;
else
V_126 = F_115 ( V_80 ) ;
V_59 = F_83 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ,
V_126 , & V_151 -> V_178 ) ;
if ( V_59 )
return V_59 ;
V_151 -> V_9 = V_55 -> V_6 . V_9 ;
* V_152 = V_156 | V_179 | V_180 ;
if ( V_55 -> V_6 . V_137 == V_164 ) {
V_59 = F_61 ( V_55 , 0 ) ;
if ( V_59 )
return V_59 ;
V_151 -> V_95 = V_55 -> V_95 ;
* V_152 |= V_181 ;
} else {
V_151 -> V_182 = 0 ;
* V_152 |= V_183 ;
}
return 0 ;
}
int F_99 ( struct V_5 * V_6 , struct V_150 * V_151 ,
int * V_152 )
{
struct V_54 * V_55 ;
int V_59 = 0 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( F_116 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( ! V_55 -> V_184 . V_90 || ( V_55 -> V_6 . V_137 == V_164 ) )
V_59 = F_113 ( V_55 , V_151 , V_152 ) ;
else
V_59 = F_117 ( V_55 -> V_184 . V_90 , V_151 ,
V_152 ) ;
if ( V_151 -> V_153 == V_155 )
V_151 -> V_185 = V_55 -> V_147 ;
} else if ( F_118 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( ! V_55 -> V_184 . V_186 ) {
V_151 -> V_182 = 0 ;
* V_152 = V_156 | V_183 ;
} else
V_59 = F_119 ( V_55 -> V_184 . V_186 , V_151 ,
V_152 ) ;
} else
V_59 = - V_187 ;
return V_59 ;
}
static inline int F_120 ( struct V_91 * V_79 )
{
switch ( V_79 -> V_106 ) {
case V_188 :
return F_121 ( ( (struct V_189 * ) V_79 ) -> V_190 . V_191 ) ;
case V_192 :
return F_122 ( & ( (struct V_193 * ) V_79 ) -> V_194 ) ;
case V_107 :
return F_123 ( & ( (struct V_99 * ) V_79 ) -> V_104 ) ;
default:
return 0 ;
}
}
static inline int F_124 ( struct V_91 * V_79 )
{
switch ( V_79 -> V_106 ) {
case V_188 :
return F_125 ( ( (struct V_189 * ) V_79 ) -> V_190 . V_191 ) ;
case V_192 :
return F_126 ( & ( (struct V_193 * ) V_79 ) -> V_194 ) ;
case V_107 :
return F_127 ( & ( (struct V_99 * ) V_79 ) -> V_104 ) ;
default:
return 0 ;
}
}
static inline int F_128 ( struct V_91 * V_79 )
{
return F_120 ( V_79 ) || F_124 ( V_79 ) ;
}
static int F_129 ( struct V_91 * V_195 , struct V_91 * V_196 )
{
if ( V_195 -> V_106 != V_196 -> V_106 )
return - 1 ;
switch ( V_195 -> V_106 ) {
case V_188 :
return ( (struct V_189 * ) V_195 ) -> V_190 . V_191 !=
( (struct V_189 * ) V_196 ) -> V_190 . V_191 ;
case V_192 :
return F_130 ( & ( (struct V_193 * ) V_195 ) -> V_194 ,
& ( (struct V_193 * ) V_196 ) -> V_194 ) ;
default:
return F_131 ( & ( (struct V_99 * ) V_195 ) -> V_104 ,
& ( (struct V_99 * ) V_196 ) -> V_104 ) ;
}
}
static T_8 F_132 ( struct V_91 * V_79 )
{
struct V_99 * V_100 ;
switch ( V_79 -> V_106 ) {
case V_188 :
return ( (struct V_189 * ) V_79 ) -> V_197 ;
case V_192 :
return ( (struct V_193 * ) V_79 ) -> V_198 ;
case V_107 :
V_100 = (struct V_99 * ) V_79 ;
return F_133 ( ( T_6 ) ( F_134 ( V_100 -> V_199 ) &
F_134 ( V_100 -> V_200 ) ) ) ;
default:
return 0 ;
}
}
static inline int F_135 ( struct V_91 * V_79 )
{
return ! F_132 ( V_79 ) ;
}
static void F_136 ( struct V_91 * V_92 ,
struct V_91 * V_93 ,
struct V_5 * V_201 ,
struct V_202 * V_203 )
{
struct V_99 * V_204 , * V_90 ;
V_204 = (struct V_99 * ) & V_201 -> V_78 . V_79 . V_92 ;
if ( V_92 ) {
V_90 = (struct V_99 * ) V_92 ;
V_90 -> V_205 = V_107 ;
if ( V_203 ) {
V_90 -> V_105 = V_203 -> V_126 ;
V_90 -> V_206 = V_203 -> V_207 ;
memcpy ( & V_90 -> V_104 , & V_203 -> V_124 , 16 ) ;
V_90 -> V_199 = V_203 -> V_208 ;
V_90 -> V_209 = 0 ;
} else {
V_90 -> V_105 = V_204 -> V_105 ;
V_90 -> V_206 = V_204 -> V_206 ;
V_90 -> V_104 = V_204 -> V_104 ;
V_90 -> V_199 = V_204 -> V_199 ;
V_90 -> V_209 = V_204 -> V_209 ;
}
V_90 -> V_200 = F_137 ( 0xffffffffffffffffULL ) ;
}
if ( V_93 ) {
V_90 = (struct V_99 * ) V_93 ;
V_90 -> V_205 = V_107 ;
if ( V_203 ) {
V_90 -> V_105 = V_203 -> V_126 ;
V_90 -> V_206 = V_203 -> V_207 ;
memcpy ( & V_90 -> V_104 , & V_203 -> V_125 , 16 ) ;
}
}
}
static void F_138 ( struct V_189 * V_92 ,
struct V_189 * V_93 ,
struct V_63 * V_64 ,
T_8 V_210 )
{
if ( V_92 ) {
* V_92 = (struct V_189 ) {
. V_211 = V_188 ,
. V_190 . V_191 = V_64 -> V_93 . V_212 . V_79 ,
. V_197 = V_210 ,
} ;
}
if ( V_93 ) {
* V_93 = (struct V_189 ) {
. V_211 = V_188 ,
. V_190 . V_191 = V_64 -> V_92 . V_212 . V_79 ,
. V_197 = V_64 -> V_47 ,
} ;
}
}
static void F_139 ( struct V_193 * V_92 ,
struct V_193 * V_93 ,
struct V_63 * V_64 ,
T_8 V_210 )
{
if ( V_92 ) {
* V_92 = (struct V_193 ) {
. V_213 = V_192 ,
. V_194 = V_64 -> V_93 . V_214 ,
. V_198 = V_210 ,
} ;
}
if ( V_93 ) {
* V_93 = (struct V_193 ) {
. V_213 = V_192 ,
. V_194 = V_64 -> V_92 . V_214 ,
. V_198 = V_64 -> V_47 ,
} ;
}
}
static T_6 F_140 ( T_9 V_208 )
{
return ( T_6 ) F_134 ( V_208 ) ;
}
static int F_141 ( struct V_91 * V_92 ,
struct V_91 * V_93 ,
struct V_215 * V_216 ,
T_9 V_208 )
{
struct V_63 * V_64 ;
T_8 V_47 ;
V_64 = V_216 -> V_20 ;
if ( V_64 -> V_217 != V_218 )
return - V_48 ;
V_47 = F_133 ( F_140 ( V_208 ) ) ;
switch ( F_38 ( V_64 ) ) {
case 4 :
F_138 ( (struct V_189 * ) V_92 ,
(struct V_189 * ) V_93 , V_64 , V_47 ) ;
break;
case 6 :
F_139 ( (struct V_193 * ) V_92 ,
(struct V_193 * ) V_93 , V_64 , V_47 ) ;
break;
default:
return - V_219 ;
}
return 0 ;
}
static int F_142 ( struct V_91 * V_92 ,
struct V_91 * V_93 ,
struct V_5 * V_201 ,
struct V_215 * V_216 ,
T_10 V_106 , T_9 V_208 )
{
if ( V_106 == V_107 ) {
if ( V_216 -> V_2 == V_220 )
F_136 ( V_92 , V_93 , V_201 ,
V_216 -> V_17 . V_221 . V_222 ) ;
else if ( V_216 -> V_2 == V_223 )
F_136 ( V_92 , V_93 , V_201 , NULL ) ;
return 0 ;
}
return F_141 ( V_92 , V_93 , V_216 , V_208 ) ;
}
static int F_143 ( const struct V_215 * V_216 ,
struct V_224 * V_225 )
{
const struct V_226 * V_227 =
& V_216 -> V_17 . V_221 ;
const struct V_228 * V_229 =
& V_216 -> V_17 . V_230 ;
switch ( V_216 -> V_2 ) {
case V_220 :
V_225 -> V_8 = V_227 -> V_201 -> V_8 ;
V_225 -> V_47 = V_227 -> V_47 ;
memcpy ( & V_225 -> V_231 , & V_227 -> V_222 -> V_124 ,
sizeof( V_225 -> V_231 ) ) ;
V_225 -> V_232 = true ;
V_225 -> V_208 = V_227 -> V_222 -> V_208 ;
V_225 -> V_126 = F_144 ( V_227 -> V_222 -> V_126 ) ;
if ( V_225 -> V_126 != V_227 -> V_233 )
F_145 ( L_4
L_5 ,
V_227 -> V_233 , V_225 -> V_126 ) ;
break;
case V_223 :
V_225 -> V_8 = V_229 -> V_201 -> V_8 ;
V_225 -> V_47 = V_229 -> V_47 ;
V_225 -> V_232 = false ;
V_225 -> V_208 = V_229 -> V_208 ;
V_225 -> V_126 = V_229 -> V_126 ;
if ( V_225 -> V_126 != V_229 -> V_233 )
F_145 ( L_6
L_5 ,
V_229 -> V_233 , V_225 -> V_126 ) ;
break;
default:
return - V_48 ;
}
return 0 ;
}
static bool F_146 ( struct V_67 * V_234 ,
const struct V_189 * V_93 ,
const struct V_189 * V_92 )
{
V_74 V_235 = V_93 -> V_190 . V_191 ,
V_236 = V_92 -> V_190 . V_191 ;
struct V_237 V_238 ;
struct V_239 V_240 ;
int V_165 ;
bool V_59 ;
if ( F_147 ( V_236 ) || F_148 ( V_236 ) ||
F_148 ( V_235 ) || F_121 ( V_236 ) ||
F_121 ( V_235 ) || F_125 ( V_235 ) ||
F_125 ( V_236 ) )
return false ;
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
V_240 . V_241 = V_234 -> V_242 ;
V_240 . V_235 = V_235 ;
V_240 . V_236 = V_236 ;
F_149 () ;
V_165 = F_150 ( F_151 ( V_234 ) , & V_240 , & V_238 , 0 ) ;
V_59 = V_165 == 0 && F_152 ( V_238 ) == V_234 ;
F_153 () ;
return V_59 ;
}
static bool F_154 ( struct V_67 * V_234 ,
const struct V_193 * V_93 ,
const struct V_193 * V_92 )
{
#if F_155 ( V_243 )
const int V_244 = F_156 ( & V_93 -> V_194 ) &
V_245 ;
struct V_246 * V_247 = F_157 ( F_151 ( V_234 ) , & V_93 -> V_194 ,
& V_92 -> V_194 , V_234 -> V_242 ,
V_244 ) ;
bool V_59 ;
if ( ! V_247 )
return false ;
V_59 = V_247 -> V_248 -> V_249 == V_234 ;
F_158 ( V_247 ) ;
return V_59 ;
#else
return false ;
#endif
}
static bool F_159 ( struct V_67 * V_234 ,
const struct V_91 * V_235 ,
const struct V_91 * V_236 )
{
const struct V_189 * V_250 = ( const struct V_189 * ) V_235 ;
const struct V_189 * V_251 = ( const struct V_189 * ) V_236 ;
const struct V_193 * V_252 = ( const struct V_193 * ) V_235 ;
const struct V_193 * V_253 = ( const struct V_193 * ) V_236 ;
switch ( V_235 -> V_106 ) {
case V_188 :
return V_236 -> V_106 == V_188 &&
F_146 ( V_234 , V_250 , V_251 ) ;
case V_192 :
return V_236 -> V_106 == V_192 &&
F_154 ( V_234 , V_252 , V_253 ) ;
default:
return false ;
}
}
static struct V_67 * F_160 ( struct V_215 * V_216 ,
const struct V_224 * V_225 )
{
struct V_254 V_255 , V_256 ;
struct V_91 * V_257 = (struct V_91 * ) & V_255 ,
* V_92 = (struct V_91 * ) & V_256 ;
struct V_67 * V_234 ;
const union V_69 * V_108 = V_225 -> V_232 ? & V_225 -> V_231 : NULL ;
int V_165 ;
V_165 = F_141 ( V_257 , V_92 , V_216 ,
V_225 -> V_208 ) ;
if ( V_165 )
return F_89 ( V_165 ) ;
V_234 = F_161 ( V_225 -> V_8 , V_225 -> V_47 , V_225 -> V_126 ,
V_108 , V_257 ) ;
if ( ! V_234 )
return F_89 ( - V_76 ) ;
if ( ! F_159 ( V_234 , V_257 , V_92 ) ) {
F_76 ( V_234 ) ;
return F_89 ( - V_258 ) ;
}
return V_234 ;
}
static enum V_25 F_162 ( T_9 V_208 )
{
return ( F_134 ( V_208 ) >> 16 ) & 0xffff ;
}
static bool F_163 ( struct V_54 * V_55 ,
const struct V_63 * V_64 )
{
struct V_91 * V_79 = F_58 ( V_55 ) ;
V_74 V_259 ;
struct V_260 V_261 ;
if ( F_128 ( V_79 ) && ! V_55 -> V_262 )
return true ;
switch ( V_79 -> V_106 ) {
case V_188 :
V_259 = ( (struct V_189 * ) V_79 ) -> V_190 . V_191 ;
if ( F_38 ( V_64 ) != 4 )
return false ;
if ( ! F_128 ( V_79 ) &&
V_64 -> V_93 . V_212 . V_79 != V_259 )
return false ;
break;
case V_192 :
V_261 = ( (struct V_193 * ) V_79 ) -> V_194 ;
if ( F_38 ( V_64 ) != 6 )
return false ;
if ( ! F_128 ( V_79 ) &&
memcmp ( & V_64 -> V_93 . V_214 , & V_261 , sizeof( V_261 ) ) )
return false ;
break;
case V_107 :
return true ;
default:
return false ;
}
return true ;
}
static bool F_164 ( struct V_53 * V_8 , int V_9 )
{
enum V_263 V_264 = F_165 ( V_8 , V_9 ) ;
enum V_265 V_81 =
F_47 ( V_8 -> V_82 ) ;
return V_264 == V_266 && V_81 == V_267 ;
}
static bool F_166 ( const struct V_5 * V_6 )
{
struct V_53 * V_8 = V_6 -> V_8 ;
const int V_9 = V_6 -> V_9 ? : F_27 ( V_8 ) ;
return F_164 ( V_8 , V_9 ) ;
}
static bool F_167 ( const struct V_5 * V_6 ,
const struct V_67 * V_234 ,
T_3 V_9 )
{
const struct V_268 * V_79 = & V_6 -> V_78 . V_79 ;
if ( ! V_234 )
return ( ! V_6 -> V_9 || V_6 -> V_9 == V_9 ) &&
( V_79 -> V_92 . V_94 == V_107 ||
F_164 ( V_6 -> V_8 , V_9 ) ) ;
return ! V_79 -> V_80 . V_120 ||
( F_168 ( F_151 ( V_234 ) , V_79 -> V_80 . V_22 ) &&
V_79 -> V_80 . V_120 == V_234 -> V_242 ) ;
}
static struct V_54 * F_169 (
const struct V_36 * V_37 ,
const struct V_269 * V_184 ,
const struct V_215 * V_216 ,
const struct V_224 * V_225 ,
const struct V_67 * V_234 )
{
struct V_54 * V_55 , * V_270 ;
if ( ! V_37 )
return F_89 ( - V_48 ) ;
F_170 (id_priv, &bind_list->owners, node) {
if ( F_163 ( V_55 , V_216 -> V_20 ) ) {
if ( V_55 -> V_6 . V_8 == V_184 -> V_8 &&
F_167 ( & V_55 -> V_6 , V_234 , V_225 -> V_47 ) )
return V_55 ;
F_23 (id_priv_dev,
&id_priv->listen_list,
listen_list) {
if ( V_270 -> V_6 . V_8 == V_184 -> V_8 &&
F_167 ( & V_270 -> V_6 , V_234 , V_225 -> V_47 ) )
return V_270 ;
}
}
}
return F_89 ( - V_48 ) ;
}
static struct V_54 * F_171 ( struct V_269 * V_184 ,
struct V_215 * V_216 ,
struct V_67 * * V_234 )
{
struct V_224 V_225 ;
struct V_36 * V_37 ;
struct V_54 * V_55 ;
int V_165 ;
V_165 = F_143 ( V_216 , & V_225 ) ;
if ( V_165 )
return F_89 ( V_165 ) ;
* V_234 = F_160 ( V_216 , & V_225 ) ;
if ( F_104 ( * V_234 ) ) {
if ( F_105 ( * V_234 ) == - V_219 ) {
* V_234 = NULL ;
} else if ( F_164 ( V_225 . V_8 , V_225 . V_47 ) ) {
* V_234 = NULL ;
} else {
return F_172 ( * V_234 ) ;
}
}
V_37 = F_15 ( * V_234 ? F_151 ( * V_234 ) : & V_111 ,
F_162 ( V_225 . V_208 ) ,
F_140 ( V_225 . V_208 ) ) ;
V_55 = F_169 ( V_37 , V_184 , V_216 , & V_225 , * V_234 ) ;
if ( F_104 ( V_55 ) && * V_234 ) {
F_76 ( * V_234 ) ;
* V_234 = NULL ;
}
return V_55 ;
}
static inline int F_173 ( struct V_54 * V_55 )
{
return F_60 ( V_55 ) == V_107 ? 0 : sizeof( struct V_63 ) ;
}
static void F_174 ( struct V_54 * V_55 )
{
if ( F_175 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ) ) {
if ( V_55 -> V_271 )
F_176 ( V_55 -> V_272 , V_55 -> V_271 ) ;
}
}
static void F_177 ( struct V_54 * V_55 )
{
struct V_54 * V_273 ;
F_22 ( & V_46 ) ;
F_57 ( & V_55 -> V_83 ) ;
while ( ! F_178 ( & V_55 -> V_145 ) ) {
V_273 = F_179 ( V_55 -> V_145 . V_274 ,
struct V_54 , V_145 ) ;
F_180 ( & V_273 -> V_83 ) ;
F_57 ( & V_273 -> V_145 ) ;
F_24 ( & V_46 ) ;
F_181 ( & V_273 -> V_6 ) ;
F_22 ( & V_46 ) ;
}
F_24 ( & V_46 ) ;
}
static void F_182 ( struct V_54 * V_55 ,
enum V_56 V_60 )
{
switch ( V_60 ) {
case V_275 :
F_183 ( & V_55 -> V_6 . V_78 . V_79 . V_80 ) ;
break;
case V_276 :
F_174 ( V_55 ) ;
break;
case V_277 :
if ( F_128 ( F_58 ( V_55 ) ) && ! V_55 -> V_41 )
F_177 ( V_55 ) ;
break;
default:
break;
}
}
static void F_184 ( struct V_54 * V_55 )
{
struct V_36 * V_37 = V_55 -> V_37 ;
struct V_22 * V_22 = V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ;
if ( ! V_37 )
return;
F_22 ( & V_46 ) ;
F_185 ( & V_55 -> V_278 ) ;
if ( F_186 ( & V_37 -> V_279 ) ) {
F_17 ( V_22 , V_37 -> V_26 , V_37 -> V_47 ) ;
F_55 ( V_37 ) ;
}
F_24 ( & V_46 ) ;
}
static void F_187 ( struct V_54 * V_55 )
{
struct V_86 * V_87 ;
while ( ! F_178 ( & V_55 -> V_146 ) ) {
V_87 = F_54 ( V_55 -> V_146 . V_274 ,
struct V_86 , V_83 ) ;
F_57 ( & V_87 -> V_83 ) ;
if ( F_188 ( V_55 -> V_41 -> V_8 ,
V_55 -> V_6 . V_9 ) ) {
F_189 ( V_87 -> V_89 . V_90 ) ;
F_55 ( V_87 ) ;
} else {
if ( V_87 -> V_280 ) {
struct V_101 * V_80 =
& V_55 -> V_6 . V_78 . V_79 . V_80 ;
struct V_67 * V_68 = NULL ;
if ( V_80 -> V_120 )
V_68 = F_74 ( & V_111 ,
V_80 -> V_120 ) ;
if ( V_68 ) {
F_40 ( V_68 ,
& V_87 -> V_89 . V_90 -> V_97 . V_70 ,
false ) ;
F_76 ( V_68 ) ;
}
}
F_190 ( & V_87 -> V_88 , F_53 ) ;
}
}
}
void F_181 ( struct V_5 * V_6 )
{
struct V_54 * V_55 ;
enum V_56 V_60 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
V_60 = F_37 ( V_55 , V_281 ) ;
F_182 ( V_55 , V_60 ) ;
F_22 ( & V_55 -> V_144 ) ;
F_24 ( & V_55 -> V_144 ) ;
if ( V_55 -> V_41 ) {
if ( F_116 ( V_55 -> V_6 . V_8 , 1 ) ) {
if ( V_55 -> V_184 . V_90 )
F_191 ( V_55 -> V_184 . V_90 ) ;
} else if ( F_118 ( V_55 -> V_6 . V_8 , 1 ) ) {
if ( V_55 -> V_184 . V_186 )
F_192 ( V_55 -> V_184 . V_186 ) ;
}
F_187 ( V_55 ) ;
F_56 ( V_55 ) ;
}
F_184 ( V_55 ) ;
F_86 ( V_55 ) ;
F_193 ( & V_55 -> V_57 ) ;
if ( V_55 -> V_282 )
F_86 ( V_55 -> V_6 . V_135 ) ;
F_55 ( V_55 -> V_6 . V_78 . V_283 ) ;
F_194 ( V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ) ;
F_55 ( V_55 ) ;
}
static int F_195 ( struct V_54 * V_55 )
{
int V_59 ;
V_59 = F_108 ( V_55 , NULL ) ;
if ( V_59 )
goto V_284;
V_59 = F_111 ( V_55 , NULL ) ;
if ( V_59 )
goto V_284;
V_59 = F_196 ( V_55 -> V_184 . V_90 , NULL , 0 ) ;
if ( V_59 )
goto V_284;
return 0 ;
V_284:
F_197 ( L_7 , V_59 ) ;
F_112 ( V_55 ) ;
F_198 ( V_55 -> V_184 . V_90 , V_10 ,
NULL , 0 , NULL , 0 ) ;
return V_59 ;
}
static void F_199 ( struct V_12 * V_2 ,
struct V_285 * V_286 ,
void * V_20 )
{
V_2 -> V_17 . V_18 . V_20 = V_20 ;
V_2 -> V_17 . V_18 . V_19 = V_287 ;
V_2 -> V_17 . V_18 . V_174 = V_286 -> V_174 ;
V_2 -> V_17 . V_18 . V_176 = V_286 -> V_176 ;
V_2 -> V_17 . V_18 . V_288 = V_286 -> V_288 ;
V_2 -> V_17 . V_18 . V_289 = V_286 -> V_289 ;
V_2 -> V_17 . V_18 . V_167 = V_286 -> V_167 ;
V_2 -> V_17 . V_18 . V_166 = V_286 -> V_290 ;
}
static int F_200 ( struct V_269 * V_184 , struct V_215 * V_216 )
{
struct V_54 * V_55 = V_184 -> V_135 ;
struct V_12 V_2 ;
int V_59 = 0 ;
F_22 ( & V_55 -> V_144 ) ;
if ( ( V_216 -> V_2 != V_291 &&
V_55 -> V_60 != V_292 ) ||
( V_216 -> V_2 == V_291 &&
V_55 -> V_60 != V_293 ) )
goto V_121;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_216 -> V_2 ) {
case V_294 :
case V_295 :
V_2 . V_2 = V_296 ;
V_2 . V_16 = - V_297 ;
break;
case V_298 :
if ( V_55 -> V_6 . V_149 ) {
V_2 . V_16 = F_195 ( V_55 ) ;
V_2 . V_2 = V_2 . V_16 ? V_299 :
V_300 ;
} else {
V_2 . V_2 = V_301 ;
}
F_199 ( & V_2 , & V_216 -> V_17 . V_302 ,
V_216 -> V_20 ) ;
break;
case V_303 :
case V_304 :
V_2 . V_2 = V_300 ;
break;
case V_305 :
V_2 . V_16 = - V_297 ;
case V_306 :
case V_307 :
if ( ! F_36 ( V_55 , V_292 ,
V_293 ) )
goto V_121;
V_2 . V_2 = V_308 ;
break;
case V_291 :
V_2 . V_2 = V_309 ;
break;
case V_310 :
goto V_121;
case V_311 :
F_197 ( L_8 , F_3 ( & V_55 -> V_6 ,
V_216 -> V_17 . V_312 . V_7 ) ) ;
F_112 ( V_55 ) ;
V_2 . V_16 = V_216 -> V_17 . V_312 . V_7 ;
V_2 . V_2 = V_313 ;
V_2 . V_17 . V_18 . V_20 = V_216 -> V_20 ;
V_2 . V_17 . V_18 . V_19 = V_314 ;
break;
default:
F_201 ( L_9 ,
V_216 -> V_2 ) ;
goto V_121;
}
V_59 = V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_2 ) ;
if ( V_59 ) {
V_55 -> V_184 . V_90 = NULL ;
F_37 ( V_55 , V_281 ) ;
F_24 ( & V_55 -> V_144 ) ;
F_181 ( & V_55 -> V_6 ) ;
return V_59 ;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
return V_59 ;
}
static struct V_54 * F_202 ( struct V_5 * V_201 ,
struct V_215 * V_216 ,
struct V_67 * V_234 )
{
struct V_54 * V_55 ;
struct V_5 * V_6 ;
struct V_315 * V_247 ;
const T_10 V_94 = V_201 -> V_78 . V_79 . V_92 . V_94 ;
const T_9 V_208 =
V_216 -> V_17 . V_221 . V_222 -> V_208 ;
int V_59 ;
V_6 = F_87 ( V_201 -> V_78 . V_79 . V_80 . V_22 ,
V_201 -> V_134 , V_201 -> V_135 ,
V_201 -> V_26 , V_216 -> V_17 . V_221 . V_137 ) ;
if ( F_104 ( V_6 ) )
return NULL ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( F_142 ( (struct V_91 * ) & V_6 -> V_78 . V_79 . V_92 ,
(struct V_91 * ) & V_6 -> V_78 . V_79 . V_93 ,
V_201 , V_216 , V_94 , V_208 ) )
goto V_165;
V_247 = & V_6 -> V_78 ;
V_247 -> V_316 = V_216 -> V_17 . V_221 . V_317 ? 2 : 1 ;
V_247 -> V_283 = F_203 ( sizeof * V_247 -> V_283 * V_247 -> V_316 ,
V_39 ) ;
if ( ! V_247 -> V_283 )
goto V_165;
V_247 -> V_283 [ 0 ] = * V_216 -> V_17 . V_221 . V_222 ;
if ( V_247 -> V_316 == 2 )
V_247 -> V_283 [ 1 ] = * V_216 -> V_17 . V_221 . V_317 ;
if ( V_234 ) {
V_59 = F_204 ( & V_247 -> V_79 . V_80 , V_234 , NULL ) ;
if ( V_59 )
goto V_165;
} else {
if ( ! F_166 ( V_201 ) &&
F_128 ( F_58 ( V_55 ) ) ) {
V_247 -> V_79 . V_80 . V_102 = V_103 ;
F_66 ( & V_247 -> V_79 . V_80 , & V_247 -> V_283 [ 0 ] . V_124 ) ;
F_67 ( & V_247 -> V_79 . V_80 , F_144 ( V_247 -> V_283 [ 0 ] . V_126 ) ) ;
} else if ( ! F_128 ( F_58 ( V_55 ) ) ) {
V_59 = F_69 ( F_58 ( V_55 ) , & V_247 -> V_79 . V_80 ) ;
if ( V_59 )
goto V_165;
}
}
F_205 ( & V_247 -> V_79 . V_80 , & V_247 -> V_283 [ 0 ] . V_125 ) ;
V_55 -> V_60 = V_292 ;
return V_55 ;
V_165:
F_181 ( V_6 ) ;
return NULL ;
}
static struct V_54 * F_206 ( struct V_5 * V_201 ,
struct V_215 * V_216 ,
struct V_67 * V_234 )
{
struct V_54 * V_55 ;
struct V_5 * V_6 ;
const T_10 V_94 = V_201 -> V_78 . V_79 . V_92 . V_94 ;
struct V_22 * V_22 = V_201 -> V_78 . V_79 . V_80 . V_22 ;
int V_59 ;
V_6 = F_87 ( V_22 , V_201 -> V_134 , V_201 -> V_135 ,
V_201 -> V_26 , V_164 ) ;
if ( F_104 ( V_6 ) )
return NULL ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( F_142 ( (struct V_91 * ) & V_6 -> V_78 . V_79 . V_92 ,
(struct V_91 * ) & V_6 -> V_78 . V_79 . V_93 ,
V_201 , V_216 , V_94 ,
V_216 -> V_17 . V_230 . V_208 ) )
goto V_165;
if ( V_234 ) {
V_59 = F_204 ( & V_6 -> V_78 . V_79 . V_80 , V_234 , NULL ) ;
if ( V_59 )
goto V_165;
} else {
if ( ! F_128 ( F_58 ( V_55 ) ) ) {
V_59 = F_69 ( F_58 ( V_55 ) ,
& V_6 -> V_78 . V_79 . V_80 ) ;
if ( V_59 )
goto V_165;
}
}
V_55 -> V_60 = V_292 ;
return V_55 ;
V_165:
F_181 ( V_6 ) ;
return NULL ;
}
static void F_207 ( struct V_12 * V_2 ,
struct V_226 * V_318 ,
void * V_20 , int V_319 )
{
V_2 -> V_17 . V_18 . V_20 = V_20 + V_319 ;
V_2 -> V_17 . V_18 . V_19 = V_320 - V_319 ;
V_2 -> V_17 . V_18 . V_174 = V_318 -> V_174 ;
V_2 -> V_17 . V_18 . V_176 = V_318 -> V_176 ;
V_2 -> V_17 . V_18 . V_288 = V_318 -> V_288 ;
V_2 -> V_17 . V_18 . V_321 = V_318 -> V_321 ;
V_2 -> V_17 . V_18 . V_289 = V_318 -> V_289 ;
V_2 -> V_17 . V_18 . V_167 = V_318 -> V_167 ;
V_2 -> V_17 . V_18 . V_166 = V_318 -> V_290 ;
}
static int F_208 ( struct V_5 * V_6 , struct V_215 * V_216 )
{
return ( ( ( V_216 -> V_2 == V_220 ) &&
( V_216 -> V_17 . V_221 . V_137 == V_6 -> V_137 ) ) ||
( ( V_216 -> V_2 == V_223 ) &&
( V_6 -> V_137 == V_164 ) ) ||
( ! V_6 -> V_137 ) ) ;
}
static int F_209 ( struct V_269 * V_184 , struct V_215 * V_216 )
{
struct V_54 * V_201 , * V_322 = NULL ;
struct V_12 V_2 ;
struct V_67 * V_234 ;
int V_319 , V_59 ;
V_201 = F_171 ( V_184 , V_216 , & V_234 ) ;
if ( F_104 ( V_201 ) )
return F_105 ( V_201 ) ;
if ( ! F_208 ( & V_201 -> V_6 , V_216 ) ) {
V_59 = - V_48 ;
goto V_323;
}
F_22 ( & V_201 -> V_144 ) ;
if ( V_201 -> V_60 != V_277 ) {
V_59 = - V_324 ;
goto V_325;
}
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_319 = F_173 ( V_201 ) ;
V_2 . V_2 = V_326 ;
if ( V_216 -> V_2 == V_223 ) {
V_322 = F_206 ( & V_201 -> V_6 , V_216 , V_234 ) ;
V_2 . V_17 . V_327 . V_20 = V_216 -> V_20 + V_319 ;
V_2 . V_17 . V_327 . V_19 =
V_328 - V_319 ;
} else {
V_322 = F_202 ( & V_201 -> V_6 , V_216 , V_234 ) ;
F_207 ( & V_2 , & V_216 -> V_17 . V_221 ,
V_216 -> V_20 , V_319 ) ;
}
if ( ! V_322 ) {
V_59 = - V_138 ;
goto V_325;
}
F_210 ( & V_322 -> V_144 , V_329 ) ;
V_59 = F_78 ( V_322 , V_201 ) ;
if ( V_59 )
goto V_330;
V_322 -> V_184 . V_90 = V_184 ;
V_184 -> V_135 = V_322 ;
V_184 -> V_331 = F_200 ;
F_20 ( & V_322 -> V_42 ) ;
V_59 = V_322 -> V_6 . V_134 ( & V_322 -> V_6 , & V_2 ) ;
if ( V_59 )
goto V_332;
F_22 ( & V_46 ) ;
if ( F_33 ( V_322 , V_292 ) &&
( V_322 -> V_6 . V_137 != V_164 ) )
F_211 ( V_184 , V_333 , NULL , 0 ) ;
F_24 ( & V_46 ) ;
F_24 ( & V_322 -> V_144 ) ;
F_24 ( & V_201 -> V_144 ) ;
F_86 ( V_322 ) ;
if ( V_234 )
F_76 ( V_234 ) ;
return 0 ;
V_332:
F_86 ( V_322 ) ;
V_322 -> V_184 . V_90 = NULL ;
V_330:
F_37 ( V_322 , V_281 ) ;
F_24 ( & V_322 -> V_144 ) ;
V_325:
F_24 ( & V_201 -> V_144 ) ;
if ( V_322 )
F_181 ( & V_322 -> V_6 ) ;
V_323:
if ( V_234 )
F_76 ( V_234 ) ;
return V_59 ;
}
T_9 F_212 ( struct V_5 * V_6 , struct V_91 * V_79 )
{
if ( V_79 -> V_106 == V_107 )
return ( (struct V_99 * ) V_79 ) -> V_199 ;
return F_137 ( ( ( V_334 ) V_6 -> V_26 << 16 ) + F_144 ( F_132 ( V_79 ) ) ) ;
}
static int F_213 ( struct V_335 * V_336 , struct V_337 * V_338 )
{
struct V_54 * V_55 = V_336 -> V_135 ;
struct V_12 V_2 ;
int V_59 = 0 ;
struct V_91 * V_339 = (struct V_91 * ) & V_338 -> V_340 ;
struct V_91 * V_341 = (struct V_91 * ) & V_338 -> V_342 ;
F_22 ( & V_55 -> V_144 ) ;
if ( V_55 -> V_60 != V_292 )
goto V_121;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_338 -> V_2 ) {
case V_343 :
V_2 . V_2 = V_308 ;
break;
case V_344 :
memcpy ( F_58 ( V_55 ) , V_339 ,
F_214 ( V_339 ) ) ;
memcpy ( F_59 ( V_55 ) , V_341 ,
F_214 ( V_341 ) ) ;
switch ( V_338 -> V_16 ) {
case 0 :
V_2 . V_2 = V_300 ;
V_2 . V_17 . V_18 . V_176 = V_338 -> V_345 ;
V_2 . V_17 . V_18 . V_174 = V_338 -> V_346 ;
break;
case - V_347 :
case - V_11 :
V_2 . V_2 = V_313 ;
break;
case - V_297 :
V_2 . V_2 = V_296 ;
break;
default:
V_2 . V_2 = V_299 ;
break;
}
break;
case V_348 :
V_2 . V_2 = V_300 ;
V_2 . V_17 . V_18 . V_176 = V_338 -> V_345 ;
V_2 . V_17 . V_18 . V_174 = V_338 -> V_346 ;
break;
default:
F_110 ( 1 ) ;
}
V_2 . V_16 = V_338 -> V_16 ;
V_2 . V_17 . V_18 . V_20 = V_338 -> V_20 ;
V_2 . V_17 . V_18 . V_19 = V_338 -> V_19 ;
V_59 = V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_2 ) ;
if ( V_59 ) {
V_55 -> V_184 . V_186 = NULL ;
F_37 ( V_55 , V_281 ) ;
F_24 ( & V_55 -> V_144 ) ;
F_181 ( & V_55 -> V_6 ) ;
return V_59 ;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
return V_59 ;
}
static int F_215 ( struct V_335 * V_184 ,
struct V_337 * V_338 )
{
struct V_5 * V_349 ;
struct V_54 * V_201 , * V_322 ;
struct V_12 V_2 ;
int V_59 = - V_324 ;
struct V_91 * V_339 = (struct V_91 * ) & V_338 -> V_340 ;
struct V_91 * V_341 = (struct V_91 * ) & V_338 -> V_342 ;
V_201 = V_184 -> V_135 ;
F_22 ( & V_201 -> V_144 ) ;
if ( V_201 -> V_60 != V_277 )
goto V_121;
V_349 = F_87 ( V_201 -> V_6 . V_78 . V_79 . V_80 . V_22 ,
V_201 -> V_6 . V_134 ,
V_201 -> V_6 . V_135 ,
V_28 , V_350 ) ;
if ( F_104 ( V_349 ) ) {
V_59 = - V_138 ;
goto V_121;
}
V_322 = F_54 ( V_349 , struct V_54 , V_6 ) ;
F_210 ( & V_322 -> V_144 , V_329 ) ;
V_322 -> V_60 = V_292 ;
V_59 = F_70 ( V_339 , & V_322 -> V_6 . V_78 . V_79 . V_80 , NULL ) ;
if ( V_59 ) {
F_24 ( & V_322 -> V_144 ) ;
F_181 ( V_349 ) ;
goto V_121;
}
V_59 = F_78 ( V_322 , V_201 ) ;
if ( V_59 ) {
F_24 ( & V_322 -> V_144 ) ;
F_181 ( V_349 ) ;
goto V_121;
}
V_322 -> V_184 . V_186 = V_184 ;
V_184 -> V_135 = V_322 ;
V_184 -> V_331 = F_213 ;
memcpy ( F_58 ( V_322 ) , V_339 , F_214 ( V_339 ) ) ;
memcpy ( F_59 ( V_322 ) , V_341 , F_214 ( V_341 ) ) ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_326 ;
V_2 . V_17 . V_18 . V_20 = V_338 -> V_20 ;
V_2 . V_17 . V_18 . V_19 = V_338 -> V_19 ;
V_2 . V_17 . V_18 . V_176 = V_338 -> V_345 ;
V_2 . V_17 . V_18 . V_174 = V_338 -> V_346 ;
F_20 ( & V_322 -> V_42 ) ;
V_59 = V_322 -> V_6 . V_134 ( & V_322 -> V_6 , & V_2 ) ;
if ( V_59 ) {
V_322 -> V_184 . V_186 = NULL ;
F_37 ( V_322 , V_281 ) ;
F_24 ( & V_322 -> V_144 ) ;
F_86 ( V_322 ) ;
F_181 ( & V_322 -> V_6 ) ;
goto V_121;
}
F_24 ( & V_322 -> V_144 ) ;
F_86 ( V_322 ) ;
V_121:
F_24 ( & V_201 -> V_144 ) ;
return V_59 ;
}
static int F_216 ( struct V_54 * V_55 )
{
struct V_91 * V_79 ;
struct V_269 * V_6 ;
T_9 V_351 ;
V_79 = F_58 ( V_55 ) ;
V_351 = F_212 ( & V_55 -> V_6 , V_79 ) ;
V_6 = F_217 ( V_55 -> V_6 . V_8 , F_209 , V_351 ) ;
if ( F_104 ( V_6 ) )
return F_105 ( V_6 ) ;
V_55 -> V_184 . V_90 = V_6 ;
return 0 ;
}
static int F_218 ( struct V_54 * V_55 , int V_352 )
{
int V_59 ;
struct V_335 * V_6 ;
V_6 = F_219 ( V_55 -> V_6 . V_8 ,
F_215 ,
V_55 ) ;
if ( F_104 ( V_6 ) )
return F_105 ( V_6 ) ;
V_6 -> V_353 = V_55 -> V_353 ;
V_55 -> V_184 . V_186 = V_6 ;
memcpy ( & V_55 -> V_184 . V_186 -> V_340 , F_58 ( V_55 ) ,
F_214 ( F_58 ( V_55 ) ) ) ;
V_59 = F_220 ( V_55 -> V_184 . V_186 , V_352 ) ;
if ( V_59 ) {
F_192 ( V_55 -> V_184 . V_186 ) ;
V_55 -> V_184 . V_186 = NULL ;
}
return V_59 ;
}
static int F_221 ( struct V_5 * V_6 ,
struct V_12 * V_2 )
{
struct V_54 * V_55 = V_6 -> V_135 ;
V_6 -> V_135 = V_55 -> V_6 . V_135 ;
V_6 -> V_134 = V_55 -> V_6 . V_134 ;
return V_55 -> V_6 . V_134 ( V_6 , V_2 ) ;
}
static void F_222 ( struct V_54 * V_55 ,
struct V_40 * V_41 )
{
struct V_54 * V_273 ;
struct V_5 * V_6 ;
struct V_22 * V_22 = V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ;
int V_59 ;
if ( F_60 ( V_55 ) == V_107 && ! F_116 ( V_41 -> V_8 , 1 ) )
return;
V_6 = F_87 ( V_22 , F_221 , V_55 , V_55 -> V_6 . V_26 ,
V_55 -> V_6 . V_137 ) ;
if ( F_104 ( V_6 ) )
return;
V_273 = F_54 ( V_6 , struct V_54 , V_6 ) ;
V_273 -> V_60 = V_354 ;
memcpy ( F_58 ( V_273 ) , F_58 ( V_55 ) ,
F_214 ( F_58 ( V_55 ) ) ) ;
F_46 ( V_273 , V_41 ) ;
F_48 ( & V_273 -> V_145 , & V_55 -> V_145 ) ;
F_20 ( & V_55 -> V_42 ) ;
V_273 -> V_282 = 1 ;
V_273 -> V_262 = V_55 -> V_262 ;
V_59 = F_223 ( V_6 , V_55 -> V_352 ) ;
if ( V_59 )
F_224 ( L_10 ,
V_59 , V_41 -> V_8 -> V_355 ) ;
}
static void F_225 ( struct V_54 * V_55 )
{
struct V_40 * V_41 ;
F_22 ( & V_46 ) ;
F_48 ( & V_55 -> V_83 , & V_356 ) ;
F_23 (cma_dev, &dev_list, list)
F_222 ( V_55 , V_41 ) ;
F_24 ( & V_46 ) ;
}
void F_226 ( struct V_5 * V_6 , int V_353 )
{
struct V_54 * V_55 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
V_55 -> V_353 = ( T_3 ) V_353 ;
V_55 -> V_142 = true ;
}
static void F_227 ( int V_16 , struct V_202 * V_283 ,
void * V_135 )
{
struct V_357 * V_358 = V_135 ;
struct V_315 * V_78 ;
V_78 = & V_358 -> V_6 -> V_6 . V_78 ;
if ( ! V_16 ) {
V_78 -> V_316 = 1 ;
* V_78 -> V_283 = * V_283 ;
} else {
V_358 -> V_359 = V_276 ;
V_358 -> V_360 = V_361 ;
V_358 -> V_2 . V_2 = V_362 ;
V_358 -> V_2 . V_16 = V_16 ;
F_197 ( L_11 ,
V_16 ) ;
}
F_228 ( V_363 , & V_358 -> V_358 ) ;
}
static int F_229 ( struct V_54 * V_55 , int V_364 ,
struct V_357 * V_358 )
{
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
struct V_202 V_283 ;
T_11 V_365 ;
struct V_193 * V_366 ;
struct V_99 * V_100 ;
memset ( & V_283 , 0 , sizeof V_283 ) ;
F_230 ( V_80 , & V_283 . V_124 ) ;
F_231 ( V_80 , & V_283 . V_125 ) ;
V_283 . V_126 = F_232 ( F_115 ( V_80 ) ) ;
V_283 . V_367 = 1 ;
V_283 . V_368 = 1 ;
V_283 . V_208 = F_212 ( & V_55 -> V_6 , F_59 ( V_55 ) ) ;
V_365 = V_369 | V_370 |
V_371 | V_372 |
V_373 | V_374 ;
switch ( F_60 ( V_55 ) ) {
case V_188 :
V_283 . V_375 = F_232 ( ( T_6 ) V_55 -> V_353 ) ;
V_365 |= V_376 ;
break;
case V_192 :
V_366 = (struct V_193 * ) F_58 ( V_55 ) ;
V_283 . V_377 = ( T_3 ) ( F_64 ( V_366 -> V_378 ) >> 20 ) ;
V_365 |= V_379 ;
break;
case V_107 :
V_100 = (struct V_99 * ) F_58 ( V_55 ) ;
V_283 . V_377 = ( T_3 ) ( F_64 ( V_100 -> V_206 ) >> 20 ) ;
V_365 |= V_379 ;
break;
}
V_55 -> V_272 = F_233 ( & V_380 , V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 , & V_283 ,
V_365 , V_364 ,
V_39 , F_227 ,
V_358 , & V_55 -> V_271 ) ;
return ( V_55 -> V_272 < 0 ) ? V_55 -> V_272 : 0 ;
}
static void F_234 ( struct V_381 * V_382 )
{
struct V_357 * V_358 = F_54 ( V_382 , struct V_357 , V_358 ) ;
struct V_54 * V_55 = V_358 -> V_6 ;
int V_383 = 0 ;
F_22 ( & V_55 -> V_144 ) ;
if ( ! F_36 ( V_55 , V_358 -> V_359 , V_358 -> V_360 ) )
goto V_121;
if ( V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_358 -> V_2 ) ) {
F_37 ( V_55 , V_281 ) ;
V_383 = 1 ;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
F_86 ( V_55 ) ;
if ( V_383 )
F_181 ( & V_55 -> V_6 ) ;
F_55 ( V_358 ) ;
}
static void F_235 ( struct V_381 * V_382 )
{
struct V_384 * V_358 = F_54 ( V_382 , struct V_384 , V_358 ) ;
struct V_54 * V_55 = V_358 -> V_6 ;
int V_383 = 0 ;
F_22 ( & V_55 -> V_144 ) ;
if ( V_55 -> V_60 == V_281 ||
V_55 -> V_60 == V_385 )
goto V_121;
if ( V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_358 -> V_2 ) ) {
F_37 ( V_55 , V_281 ) ;
V_383 = 1 ;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
F_86 ( V_55 ) ;
if ( V_383 )
F_181 ( & V_55 -> V_6 ) ;
F_55 ( V_358 ) ;
}
static int F_236 ( struct V_54 * V_55 , int V_364 )
{
struct V_315 * V_78 = & V_55 -> V_6 . V_78 ;
struct V_357 * V_358 ;
int V_59 ;
V_358 = F_88 ( sizeof *V_358 , V_39 ) ;
if ( ! V_358 )
return - V_138 ;
V_358 -> V_6 = V_55 ;
F_237 ( & V_358 -> V_358 , F_234 ) ;
V_358 -> V_359 = V_276 ;
V_358 -> V_360 = V_386 ;
V_358 -> V_2 . V_2 = V_387 ;
V_78 -> V_283 = F_203 ( sizeof * V_78 -> V_283 , V_39 ) ;
if ( ! V_78 -> V_283 ) {
V_59 = - V_138 ;
goto V_325;
}
V_59 = F_229 ( V_55 , V_364 , V_358 ) ;
if ( V_59 )
goto V_330;
return 0 ;
V_330:
F_55 ( V_78 -> V_283 ) ;
V_78 -> V_283 = NULL ;
V_325:
F_55 ( V_358 ) ;
return V_59 ;
}
int F_238 ( struct V_5 * V_6 ,
struct V_202 * V_283 , int V_316 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_36 ( V_55 , V_361 ,
V_386 ) )
return - V_48 ;
V_6 -> V_78 . V_283 = F_239 ( V_283 , sizeof *V_283 * V_316 ,
V_39 ) ;
if ( ! V_6 -> V_78 . V_283 ) {
V_59 = - V_138 ;
goto V_165;
}
V_6 -> V_78 . V_316 = V_316 ;
return 0 ;
V_165:
F_36 ( V_55 , V_386 , V_361 ) ;
return V_59 ;
}
static int F_240 ( struct V_54 * V_55 , int V_364 )
{
struct V_357 * V_358 ;
V_358 = F_88 ( sizeof *V_358 , V_39 ) ;
if ( ! V_358 )
return - V_138 ;
V_358 -> V_6 = V_55 ;
F_237 ( & V_358 -> V_358 , F_234 ) ;
V_358 -> V_359 = V_276 ;
V_358 -> V_360 = V_386 ;
V_358 -> V_2 . V_2 = V_387 ;
F_228 ( V_363 , & V_358 -> V_358 ) ;
return 0 ;
}
static int F_241 ( struct V_67 * V_68 , int V_353 )
{
int V_388 ;
struct V_67 * V_249 ;
V_388 = F_242 ( V_353 ) ;
V_249 = F_243 ( V_68 ) ? F_244 ( V_68 ) : V_68 ;
if ( V_249 -> V_389 )
return F_245 ( V_249 , V_388 ) ;
#if F_155 ( V_390 )
if ( F_243 ( V_68 ) )
return ( F_246 ( V_68 , V_388 ) &
V_391 ) >> V_392 ;
#endif
return 0 ;
}
static enum V_50 F_247 ( enum V_393 V_394 ,
unsigned long V_51 ,
enum V_50 V_395 )
{
if ( ( V_394 == V_396 ||
V_394 == V_397 ) &&
F_248 ( V_398 , & V_51 ) )
return V_398 ;
return V_395 ;
}
static int F_249 ( struct V_54 * V_55 )
{
struct V_315 * V_78 = & V_55 -> V_6 . V_78 ;
struct V_268 * V_79 = & V_78 -> V_79 ;
struct V_357 * V_358 ;
int V_59 ;
struct V_67 * V_68 = NULL ;
T_3 V_52 = V_55 -> V_41 -> V_52 [ V_55 -> V_6 . V_9 -
F_27 ( V_55 -> V_41 -> V_8 ) ] ;
T_3 V_353 = V_55 -> V_142 ? V_55 -> V_353 : V_52 ;
V_358 = F_88 ( sizeof *V_358 , V_39 ) ;
if ( ! V_358 )
return - V_138 ;
V_358 -> V_6 = V_55 ;
F_237 ( & V_358 -> V_358 , F_234 ) ;
V_78 -> V_283 = F_88 ( sizeof * V_78 -> V_283 , V_39 ) ;
if ( ! V_78 -> V_283 ) {
V_59 = - V_138 ;
goto V_325;
}
V_78 -> V_316 = 1 ;
if ( V_79 -> V_80 . V_120 ) {
unsigned long V_51 ;
V_68 = F_74 ( & V_111 , V_79 -> V_80 . V_120 ) ;
if ( ! V_68 ) {
V_59 = - V_76 ;
goto V_330;
}
if ( V_68 -> V_58 & V_112 ) {
F_76 ( V_68 ) ;
if ( ! V_55 -> V_6 . V_8 -> V_113 ) {
V_59 = - V_114 ;
goto V_330;
}
V_68 = V_55 -> V_6 . V_8 -> V_113 ( V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 ) ;
if ( ! V_68 ) {
V_59 = - V_76 ;
goto V_330;
}
}
V_78 -> V_283 -> V_22 = & V_111 ;
V_78 -> V_283 -> V_242 = V_68 -> V_242 ;
V_51 = F_29 ( V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 ) ;
V_78 -> V_283 -> V_77 =
F_247 ( V_79 -> V_80 . V_399 ,
V_51 ,
V_55 -> V_77 ) ;
}
if ( ! V_68 ) {
V_59 = - V_76 ;
goto V_330;
}
memcpy ( V_78 -> V_283 -> V_400 , V_79 -> V_80 . V_401 , V_402 ) ;
F_79 ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_92 ,
& V_78 -> V_283 -> V_124 ) ;
F_79 ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_93 ,
& V_78 -> V_283 -> V_125 ) ;
if ( V_78 -> V_283 -> V_77 < F_250 ( V_79 -> V_80 . V_399 ) )
V_78 -> V_283 -> V_77 = F_250 ( V_79 -> V_80 . V_399 ) ;
if ( ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_93 ) -> V_106 != V_107 )
V_78 -> V_283 -> V_403 = V_79 -> V_80 . V_404 ;
else
V_78 -> V_283 -> V_403 = 1 ;
V_78 -> V_283 -> V_368 = 1 ;
V_78 -> V_283 -> V_126 = F_232 ( 0xffff ) ;
V_78 -> V_283 -> V_405 = V_406 ;
V_78 -> V_283 -> V_407 = F_241 ( V_68 , V_353 ) ;
V_78 -> V_283 -> V_377 = V_353 ;
V_78 -> V_283 -> V_408 = F_251 ( V_68 -> V_408 ) ;
V_78 -> V_283 -> V_409 = V_406 ;
V_78 -> V_283 -> V_410 = F_252 ( V_68 ) ;
F_76 ( V_68 ) ;
V_78 -> V_283 -> V_411 = V_406 ;
V_78 -> V_283 -> V_412 = V_413 ;
if ( ! V_78 -> V_283 -> V_408 ) {
V_59 = - V_48 ;
goto V_330;
}
V_358 -> V_359 = V_276 ;
V_358 -> V_360 = V_386 ;
V_358 -> V_2 . V_2 = V_387 ;
V_358 -> V_2 . V_16 = 0 ;
F_228 ( V_363 , & V_358 -> V_358 ) ;
return 0 ;
V_330:
F_55 ( V_78 -> V_283 ) ;
V_78 -> V_283 = NULL ;
V_325:
F_55 ( V_358 ) ;
return V_59 ;
}
int F_253 ( struct V_5 * V_6 , int V_364 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_36 ( V_55 , V_361 , V_276 ) )
return - V_48 ;
F_20 ( & V_55 -> V_42 ) ;
if ( F_175 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_236 ( V_55 , V_364 ) ;
else if ( F_73 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_249 ( V_55 ) ;
else if ( F_6 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_240 ( V_55 , V_364 ) ;
else
V_59 = - V_187 ;
if ( V_59 )
goto V_165;
return 0 ;
V_165:
F_36 ( V_55 , V_276 , V_361 ) ;
F_86 ( V_55 ) ;
return V_59 ;
}
static void F_254 ( struct V_91 * V_79 )
{
switch ( V_79 -> V_106 ) {
case V_188 :
( (struct V_189 * ) V_79 ) -> V_190 . V_191 = F_255 ( V_414 ) ;
break;
case V_192 :
F_256 ( & ( (struct V_193 * ) V_79 ) -> V_194 ,
0 , 0 , 0 , F_255 ( 1 ) ) ;
break;
default:
F_257 ( & ( (struct V_99 * ) V_79 ) -> V_104 ,
0 , 0 , 0 , F_255 ( 1 ) ) ;
break;
}
}
static int F_258 ( struct V_54 * V_55 )
{
struct V_40 * V_41 , * V_123 ;
union V_69 V_108 ;
enum V_127 V_128 ;
T_6 V_126 ;
int V_59 ;
T_3 V_15 ;
V_41 = NULL ;
F_22 ( & V_46 ) ;
F_23 (cur_dev, &dev_list, list) {
if ( F_60 ( V_55 ) == V_107 &&
! F_116 ( V_123 -> V_8 , 1 ) )
continue;
if ( ! V_41 )
V_41 = V_123 ;
for ( V_15 = 1 ; V_15 <= V_123 -> V_8 -> V_122 ; ++ V_15 ) {
if ( ! F_84 ( V_123 -> V_8 , V_15 , & V_128 ) &&
V_128 == V_133 ) {
V_41 = V_123 ;
goto V_415;
}
}
}
if ( ! V_41 ) {
V_59 = - V_76 ;
goto V_121;
}
V_15 = 1 ;
V_415:
V_59 = F_85 ( V_41 -> V_8 , V_15 , 0 , & V_108 , NULL ) ;
if ( V_59 )
goto V_121;
V_59 = F_259 ( V_41 -> V_8 , V_15 , 0 , & V_126 ) ;
if ( V_59 )
goto V_121;
V_55 -> V_6 . V_78 . V_79 . V_80 . V_102 =
( F_72 ( V_41 -> V_8 , V_15 ) ) ?
V_103 : V_110 ;
F_66 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , & V_108 ) ;
F_67 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , V_126 ) ;
V_55 -> V_6 . V_9 = V_15 ;
F_49 ( V_55 , V_41 ) ;
F_254 ( F_58 ( V_55 ) ) ;
V_121:
F_24 ( & V_46 ) ;
return V_59 ;
}
static void F_260 ( int V_16 , struct V_91 * V_92 ,
struct V_101 * V_80 , void * V_135 )
{
struct V_54 * V_55 = V_135 ;
struct V_12 V_2 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
F_22 ( & V_55 -> V_144 ) ;
if ( ! F_36 ( V_55 , V_275 ,
V_361 ) )
goto V_121;
memcpy ( F_58 ( V_55 ) , V_92 , F_214 ( V_92 ) ) ;
if ( ! V_16 && ! V_55 -> V_41 ) {
V_16 = F_78 ( V_55 , NULL ) ;
if ( V_16 )
F_197 ( L_12 ,
V_16 ) ;
} else {
F_197 ( L_13 , V_16 ) ;
}
if ( V_16 ) {
if ( ! F_36 ( V_55 , V_361 ,
V_354 ) )
goto V_121;
V_2 . V_2 = V_416 ;
V_2 . V_16 = V_16 ;
} else
V_2 . V_2 = V_417 ;
if ( V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_2 ) ) {
F_37 ( V_55 , V_281 ) ;
F_24 ( & V_55 -> V_144 ) ;
F_86 ( V_55 ) ;
F_181 ( & V_55 -> V_6 ) ;
return;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
F_86 ( V_55 ) ;
}
static int F_261 ( struct V_54 * V_55 )
{
struct V_357 * V_358 ;
union V_69 V_108 ;
int V_59 ;
V_358 = F_88 ( sizeof *V_358 , V_39 ) ;
if ( ! V_358 )
return - V_138 ;
if ( ! V_55 -> V_41 ) {
V_59 = F_258 ( V_55 ) ;
if ( V_59 )
goto V_165;
}
F_230 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , & V_108 ) ;
F_205 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , & V_108 ) ;
V_358 -> V_6 = V_55 ;
F_237 ( & V_358 -> V_358 , F_234 ) ;
V_358 -> V_359 = V_275 ;
V_358 -> V_360 = V_361 ;
V_358 -> V_2 . V_2 = V_417 ;
F_228 ( V_363 , & V_358 -> V_358 ) ;
return 0 ;
V_165:
F_55 ( V_358 ) ;
return V_59 ;
}
static int F_262 ( struct V_54 * V_55 )
{
struct V_357 * V_358 ;
int V_59 ;
V_358 = F_88 ( sizeof *V_358 , V_39 ) ;
if ( ! V_358 )
return - V_138 ;
if ( ! V_55 -> V_41 ) {
V_59 = F_81 ( V_55 ) ;
if ( V_59 )
goto V_165;
}
F_205 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , (union V_69 * )
& ( ( (struct V_99 * ) & V_55 -> V_6 . V_78 . V_79 . V_93 ) -> V_104 ) ) ;
V_358 -> V_6 = V_55 ;
F_237 ( & V_358 -> V_358 , F_234 ) ;
V_358 -> V_359 = V_275 ;
V_358 -> V_360 = V_361 ;
V_358 -> V_2 . V_2 = V_417 ;
F_228 ( V_363 , & V_358 -> V_358 ) ;
return 0 ;
V_165:
F_55 ( V_358 ) ;
return V_59 ;
}
static int F_263 ( struct V_5 * V_6 , struct V_91 * V_92 ,
struct V_91 * V_93 )
{
if ( ! V_92 || ! V_92 -> V_106 ) {
V_92 = (struct V_91 * ) & V_6 -> V_78 . V_79 . V_92 ;
V_92 -> V_106 = V_93 -> V_106 ;
if ( F_155 ( V_243 ) &&
V_93 -> V_106 == V_192 ) {
struct V_193 * V_418 = (struct V_193 * ) V_92 ;
struct V_193 * V_419 = (struct V_193 * ) V_93 ;
V_418 -> V_420 = V_419 -> V_420 ;
if ( F_156 ( & V_419 -> V_194 ) & V_245 )
V_6 -> V_78 . V_79 . V_80 . V_120 = V_419 -> V_420 ;
} else if ( V_93 -> V_106 == V_107 ) {
( (struct V_99 * ) V_92 ) -> V_105 =
( (struct V_99 * ) V_93 ) -> V_105 ;
}
}
return F_264 ( V_6 , V_92 ) ;
}
int F_265 ( struct V_5 * V_6 , struct V_91 * V_92 ,
struct V_91 * V_93 , int V_364 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
memcpy ( F_59 ( V_55 ) , V_93 , F_214 ( V_93 ) ) ;
if ( V_55 -> V_60 == V_141 ) {
V_59 = F_263 ( V_6 , V_92 , V_93 ) ;
if ( V_59 ) {
memset ( F_59 ( V_55 ) , 0 , F_214 ( V_93 ) ) ;
return V_59 ;
}
}
if ( F_60 ( V_55 ) != V_93 -> V_106 ) {
memset ( F_59 ( V_55 ) , 0 , F_214 ( V_93 ) ) ;
return - V_48 ;
}
if ( ! F_36 ( V_55 , V_354 , V_275 ) ) {
memset ( F_59 ( V_55 ) , 0 , F_214 ( V_93 ) ) ;
return - V_48 ;
}
F_20 ( & V_55 -> V_42 ) ;
if ( F_128 ( V_93 ) ) {
V_59 = F_261 ( V_55 ) ;
} else {
if ( V_93 -> V_106 == V_107 ) {
V_59 = F_262 ( V_55 ) ;
} else {
V_59 = F_266 ( & V_421 , F_58 ( V_55 ) ,
V_93 , & V_6 -> V_78 . V_79 . V_80 ,
V_364 , F_260 , V_55 ) ;
}
}
if ( V_59 )
goto V_165;
return 0 ;
V_165:
F_36 ( V_55 , V_275 , V_354 ) ;
F_86 ( V_55 ) ;
return V_59 ;
}
int F_267 ( struct V_5 * V_6 , int V_422 )
{
struct V_54 * V_55 ;
unsigned long V_58 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
F_34 ( & V_55 -> V_46 , V_58 ) ;
if ( V_422 || V_55 -> V_60 == V_141 ) {
V_55 -> V_423 = V_422 ;
V_59 = 0 ;
} else {
V_59 = - V_48 ;
}
F_35 ( & V_55 -> V_46 , V_58 ) ;
return V_59 ;
}
int F_268 ( struct V_5 * V_6 , int V_262 )
{
struct V_54 * V_55 ;
unsigned long V_58 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
F_34 ( & V_55 -> V_46 , V_58 ) ;
if ( V_55 -> V_60 == V_141 || V_55 -> V_60 == V_354 ) {
V_55 -> V_424 |= ( 1 << V_425 ) ;
V_55 -> V_262 = V_262 ;
V_59 = 0 ;
} else {
V_59 = - V_48 ;
}
F_35 ( & V_55 -> V_46 , V_58 ) ;
return V_59 ;
}
static void F_269 ( struct V_36 * V_37 ,
struct V_54 * V_55 )
{
struct V_91 * V_79 ;
struct V_99 * V_100 ;
V_334 V_426 , V_427 ;
T_8 V_47 ;
V_79 = F_58 ( V_55 ) ;
V_47 = F_133 ( V_37 -> V_47 ) ;
switch ( V_79 -> V_106 ) {
case V_188 :
( (struct V_189 * ) V_79 ) -> V_197 = V_47 ;
break;
case V_192 :
( (struct V_193 * ) V_79 ) -> V_198 = V_47 ;
break;
case V_107 :
V_100 = (struct V_99 * ) V_79 ;
V_426 = F_134 ( V_100 -> V_199 ) ;
V_427 = F_134 ( V_100 -> V_200 ) ;
V_100 -> V_199 = F_137 ( ( V_426 & V_427 ) | ( V_334 ) F_68 ( V_47 ) ) ;
V_100 -> V_200 = F_137 ( ~ 0ULL ) ;
break;
}
V_55 -> V_37 = V_37 ;
F_270 ( & V_55 -> V_278 , & V_37 -> V_279 ) ;
}
static int F_271 ( enum V_25 V_26 ,
struct V_54 * V_55 , unsigned short V_38 )
{
struct V_36 * V_37 ;
int V_59 ;
V_37 = F_88 ( sizeof *V_37 , V_39 ) ;
if ( ! V_37 )
return - V_138 ;
V_59 = F_13 ( V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 , V_26 , V_37 ,
V_38 ) ;
if ( V_59 < 0 )
goto V_165;
V_37 -> V_26 = V_26 ;
V_37 -> V_47 = ( unsigned short ) V_59 ;
F_269 ( V_37 , V_55 ) ;
return 0 ;
V_165:
F_55 ( V_37 ) ;
return V_59 == - V_428 ? - V_429 : V_59 ;
}
static int F_272 ( struct V_36 * V_37 ,
struct V_54 * V_55 )
{
struct V_54 * V_430 ;
struct V_91 * V_235 = F_59 ( V_55 ) ;
struct V_91 * V_236 = F_58 ( V_55 ) ;
T_8 V_431 = F_132 ( V_235 ) ;
F_170 (cur_id, &bind_list->owners, node) {
struct V_91 * V_432 = F_59 ( V_430 ) ;
struct V_91 * V_433 = F_58 ( V_430 ) ;
T_8 V_434 = F_132 ( V_432 ) ;
if ( V_55 == V_430 )
continue;
if ( ! F_135 ( V_432 ) &&
( V_431 != V_434 ) )
continue;
if ( ! F_128 ( V_236 ) &&
! F_128 ( V_433 ) &&
F_129 ( V_236 , V_433 ) )
continue;
if ( ! F_128 ( V_432 ) &&
F_129 ( V_235 , V_432 ) )
continue;
return - V_429 ;
}
return 0 ;
}
static int F_273 ( enum V_25 V_26 ,
struct V_54 * V_55 )
{
static unsigned int V_435 ;
int V_436 , V_437 , V_438 ;
unsigned int V_439 ;
struct V_22 * V_22 = V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ;
F_274 ( V_22 , & V_436 , & V_437 ) ;
V_438 = ( V_437 - V_436 ) + 1 ;
V_439 = F_275 () % V_438 + V_436 ;
V_440:
if ( V_435 != V_439 ) {
struct V_36 * V_37 ;
int V_59 ;
V_37 = F_15 ( V_22 , V_26 , ( unsigned short ) V_439 ) ;
if ( ! V_37 ) {
V_59 = F_271 ( V_26 , V_55 , V_439 ) ;
} else {
V_59 = F_272 ( V_37 , V_55 ) ;
if ( ! V_59 )
F_269 ( V_37 , V_55 ) ;
}
if ( ! V_59 )
V_435 = V_439 ;
if ( V_59 != - V_429 )
return V_59 ;
}
if ( -- V_438 ) {
V_439 ++ ;
if ( ( V_439 < V_436 ) || ( V_439 > V_437 ) )
V_439 = V_436 ;
goto V_440;
}
return - V_429 ;
}
static int F_276 ( struct V_36 * V_37 ,
struct V_54 * V_55 , T_12 V_423 )
{
struct V_54 * V_430 ;
struct V_91 * V_79 , * V_441 ;
V_79 = F_58 ( V_55 ) ;
F_170 (cur_id, &bind_list->owners, node) {
if ( V_55 == V_430 )
continue;
if ( ( V_430 -> V_60 != V_277 ) && V_423 &&
V_430 -> V_423 )
continue;
V_441 = F_58 ( V_430 ) ;
if ( V_55 -> V_262 && V_430 -> V_262 &&
( V_79 -> V_106 != V_441 -> V_106 ) )
continue;
if ( F_128 ( V_79 ) || F_128 ( V_441 ) )
return - V_429 ;
if ( ! F_129 ( V_79 , V_441 ) )
return - V_442 ;
}
return 0 ;
}
static int F_277 ( enum V_25 V_26 ,
struct V_54 * V_55 )
{
struct V_36 * V_37 ;
unsigned short V_38 ;
int V_59 ;
V_38 = F_68 ( F_132 ( F_58 ( V_55 ) ) ) ;
if ( V_38 < V_443 && ! F_278 ( V_444 ) )
return - V_445 ;
V_37 = F_15 ( V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 , V_26 , V_38 ) ;
if ( ! V_37 ) {
V_59 = F_271 ( V_26 , V_55 , V_38 ) ;
} else {
V_59 = F_276 ( V_37 , V_55 , V_55 -> V_423 ) ;
if ( ! V_59 )
F_269 ( V_37 , V_55 ) ;
}
return V_59 ;
}
static int F_279 ( struct V_54 * V_55 )
{
struct V_36 * V_37 = V_55 -> V_37 ;
int V_59 = 0 ;
F_22 ( & V_46 ) ;
if ( V_37 -> V_279 . V_446 -> V_274 )
V_59 = F_276 ( V_37 , V_55 , 0 ) ;
F_24 ( & V_46 ) ;
return V_59 ;
}
static enum V_25 F_280 (
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
static enum V_25 F_281 ( struct V_54 * V_55 )
{
enum V_25 V_26 = 0 ;
struct V_99 * V_100 ;
V_334 V_447 , V_427 , V_426 ;
V_100 = (struct V_99 * ) F_58 ( V_55 ) ;
V_427 = F_134 ( V_100 -> V_200 ) & V_448 ;
V_426 = F_134 ( V_100 -> V_199 ) & V_427 ;
if ( ( V_55 -> V_6 . V_26 == V_34 ) && ( V_426 == ( V_449 & V_427 ) ) ) {
V_447 = V_449 ;
V_26 = V_34 ;
} else if ( ( ( V_55 -> V_6 . V_26 == V_34 ) || ( V_55 -> V_6 . V_26 == V_28 ) ) &&
( V_426 == ( V_450 & V_427 ) ) ) {
V_447 = V_450 ;
V_26 = V_28 ;
} else if ( ( ( V_55 -> V_6 . V_26 == V_34 ) || ( V_55 -> V_6 . V_26 == V_30 ) ) &&
( V_426 == ( V_451 & V_427 ) ) ) {
V_447 = V_451 ;
V_26 = V_30 ;
}
if ( V_26 ) {
V_100 -> V_199 = F_137 ( V_447 | F_68 ( F_132 ( (struct V_91 * ) V_100 ) ) ) ;
V_100 -> V_200 = F_137 ( V_448 |
F_134 ( V_100 -> V_200 ) ) ;
}
return V_26 ;
}
static int F_282 ( struct V_54 * V_55 )
{
enum V_25 V_26 ;
int V_59 ;
if ( F_60 ( V_55 ) != V_107 )
V_26 = F_280 ( V_55 ) ;
else
V_26 = F_281 ( V_55 ) ;
if ( ! V_26 )
return - V_452 ;
F_22 ( & V_46 ) ;
if ( F_135 ( F_58 ( V_55 ) ) )
V_59 = F_273 ( V_26 , V_55 ) ;
else
V_59 = F_277 ( V_26 , V_55 ) ;
F_24 ( & V_46 ) ;
return V_59 ;
}
static int F_283 ( struct V_101 * V_80 ,
struct V_91 * V_79 )
{
#if F_155 ( V_243 )
struct V_193 * V_366 ;
if ( V_79 -> V_106 != V_192 )
return 0 ;
V_366 = (struct V_193 * ) V_79 ;
if ( ! ( F_156 ( & V_366 -> V_194 ) & V_245 ) )
return 0 ;
if ( ! V_366 -> V_420 )
return - V_48 ;
V_80 -> V_120 = V_366 -> V_420 ;
#endif
return 0 ;
}
int F_223 ( struct V_5 * V_6 , int V_352 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( V_55 -> V_60 == V_141 ) {
V_6 -> V_78 . V_79 . V_92 . V_94 = V_188 ;
V_59 = F_264 ( V_6 , F_58 ( V_55 ) ) ;
if ( V_59 )
return V_59 ;
}
if ( ! F_36 ( V_55 , V_354 , V_277 ) )
return - V_48 ;
if ( V_55 -> V_423 ) {
V_59 = F_279 ( V_55 ) ;
if ( V_59 )
goto V_165;
}
V_55 -> V_352 = V_352 ;
if ( V_6 -> V_8 ) {
if ( F_116 ( V_6 -> V_8 , 1 ) ) {
V_59 = F_216 ( V_55 ) ;
if ( V_59 )
goto V_165;
} else if ( F_118 ( V_6 -> V_8 , 1 ) ) {
V_59 = F_218 ( V_55 , V_352 ) ;
if ( V_59 )
goto V_165;
} else {
V_59 = - V_187 ;
goto V_165;
}
} else
F_225 ( V_55 ) ;
return 0 ;
V_165:
V_55 -> V_352 = 0 ;
F_36 ( V_55 , V_277 , V_354 ) ;
return V_59 ;
}
int F_264 ( struct V_5 * V_6 , struct V_91 * V_79 )
{
struct V_54 * V_55 ;
int V_59 ;
struct V_91 * V_235 ;
if ( V_79 -> V_106 != V_188 && V_79 -> V_106 != V_192 &&
V_79 -> V_106 != V_107 )
return - V_219 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_36 ( V_55 , V_141 , V_354 ) )
return - V_48 ;
V_59 = F_283 ( & V_6 -> V_78 . V_79 . V_80 , V_79 ) ;
if ( V_59 )
goto V_325;
memcpy ( F_58 ( V_55 ) , V_79 , F_214 ( V_79 ) ) ;
if ( ! F_128 ( V_79 ) ) {
V_59 = F_69 ( V_79 , & V_6 -> V_78 . V_79 . V_80 ) ;
if ( V_59 )
goto V_325;
V_59 = F_78 ( V_55 , NULL ) ;
if ( V_59 )
goto V_325;
}
if ( ! ( V_55 -> V_424 & ( 1 << V_425 ) ) ) {
if ( V_79 -> V_106 == V_188 )
V_55 -> V_262 = 1 ;
#if F_155 ( V_243 )
else if ( V_79 -> V_106 == V_192 ) {
struct V_22 * V_22 = V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ;
V_55 -> V_262 = V_22 -> V_453 . V_454 . V_455 ;
}
#endif
}
V_59 = F_282 ( V_55 ) ;
if ( V_59 )
goto V_330;
V_235 = F_59 ( V_55 ) ;
V_235 -> V_106 = V_79 -> V_106 ;
return 0 ;
V_330:
if ( V_55 -> V_41 )
F_56 ( V_55 ) ;
V_325:
F_36 ( V_55 , V_354 , V_141 ) ;
return V_59 ;
}
static int F_284 ( void * V_64 , struct V_54 * V_55 )
{
struct V_63 * V_63 ;
V_63 = V_64 ;
V_63 -> V_217 = V_218 ;
if ( F_60 ( V_55 ) == V_188 ) {
struct V_189 * V_456 , * V_457 ;
V_456 = (struct V_189 * ) F_58 ( V_55 ) ;
V_457 = (struct V_189 * ) F_59 ( V_55 ) ;
F_39 ( V_63 , 4 ) ;
V_63 -> V_92 . V_212 . V_79 = V_456 -> V_190 . V_191 ;
V_63 -> V_93 . V_212 . V_79 = V_457 -> V_190 . V_191 ;
V_63 -> V_47 = V_456 -> V_197 ;
} else if ( F_60 ( V_55 ) == V_192 ) {
struct V_193 * V_458 , * V_459 ;
V_458 = (struct V_193 * ) F_58 ( V_55 ) ;
V_459 = (struct V_193 * ) F_59 ( V_55 ) ;
F_39 ( V_63 , 6 ) ;
V_63 -> V_92 . V_214 = V_458 -> V_194 ;
V_63 -> V_93 . V_214 = V_459 -> V_194 ;
V_63 -> V_47 = V_458 -> V_198 ;
}
return 0 ;
}
static int F_285 ( struct V_269 * V_184 ,
struct V_215 * V_216 )
{
struct V_54 * V_55 = V_184 -> V_135 ;
struct V_12 V_2 ;
struct V_460 * V_461 = & V_216 -> V_17 . V_462 ;
int V_59 = 0 ;
F_22 ( & V_55 -> V_144 ) ;
if ( V_55 -> V_60 != V_292 )
goto V_121;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_216 -> V_2 ) {
case V_463 :
V_2 . V_2 = V_296 ;
V_2 . V_16 = - V_297 ;
break;
case V_464 :
V_2 . V_17 . V_327 . V_20 = V_216 -> V_20 ;
V_2 . V_17 . V_327 . V_19 = V_465 ;
if ( V_461 -> V_16 != V_466 ) {
V_2 . V_2 = V_296 ;
V_2 . V_16 = V_216 -> V_17 . V_462 . V_16 ;
F_197 ( L_14 ,
V_2 . V_16 ) ;
break;
}
V_59 = F_61 ( V_55 , V_461 -> V_95 ) ;
if ( V_59 ) {
F_197 ( L_15 , V_59 ) ;
V_2 . V_2 = V_416 ;
V_2 . V_16 = V_59 ;
break;
}
F_286 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ,
V_55 -> V_6 . V_78 . V_283 ,
& V_2 . V_17 . V_327 . V_170 ) ;
V_2 . V_17 . V_327 . V_166 = V_461 -> V_467 ;
V_2 . V_17 . V_327 . V_95 = V_461 -> V_95 ;
V_2 . V_2 = V_300 ;
V_2 . V_16 = 0 ;
break;
default:
F_201 ( L_9 ,
V_216 -> V_2 ) ;
goto V_121;
}
V_59 = V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_2 ) ;
if ( V_59 ) {
V_55 -> V_184 . V_90 = NULL ;
F_37 ( V_55 , V_281 ) ;
F_24 ( & V_55 -> V_144 ) ;
F_181 ( & V_55 -> V_6 ) ;
return V_59 ;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
return V_59 ;
}
static int F_287 ( struct V_54 * V_55 ,
struct V_168 * V_169 )
{
struct V_468 V_225 ;
struct V_269 * V_6 ;
void * V_20 ;
int V_319 , V_59 ;
memset ( & V_225 , 0 , sizeof V_225 ) ;
V_319 = F_173 ( V_55 ) ;
V_225 . V_19 = V_319 + V_169 -> V_19 ;
if ( V_225 . V_19 < V_169 -> V_19 )
return - V_48 ;
if ( V_225 . V_19 ) {
V_20 = F_88 ( V_225 . V_19 , V_469 ) ;
if ( ! V_20 )
return - V_138 ;
} else {
V_20 = NULL ;
}
if ( V_169 -> V_20 && V_169 -> V_19 )
memcpy ( V_20 + V_319 , V_169 -> V_20 ,
V_169 -> V_19 ) ;
if ( V_20 ) {
V_59 = F_284 ( V_20 , V_55 ) ;
if ( V_59 )
goto V_121;
V_225 . V_20 = V_20 ;
}
V_6 = F_288 ( V_55 -> V_6 . V_8 , F_285 ,
V_55 ) ;
if ( F_104 ( V_6 ) ) {
V_59 = F_105 ( V_6 ) ;
goto V_121;
}
V_55 -> V_184 . V_90 = V_6 ;
V_225 . V_203 = V_55 -> V_6 . V_78 . V_283 ;
V_225 . V_208 = F_212 ( & V_55 -> V_6 , F_59 ( V_55 ) ) ;
V_225 . V_364 = 1 << ( V_470 - 8 ) ;
V_225 . V_471 = V_472 ;
V_59 = F_289 ( V_55 -> V_184 . V_90 , & V_225 ) ;
if ( V_59 ) {
F_191 ( V_55 -> V_184 . V_90 ) ;
V_55 -> V_184 . V_90 = NULL ;
}
V_121:
F_55 ( V_20 ) ;
return V_59 ;
}
static int F_290 ( struct V_54 * V_55 ,
struct V_168 * V_169 )
{
struct V_473 V_225 ;
struct V_315 * V_78 ;
void * V_20 ;
struct V_269 * V_6 ;
int V_319 , V_59 ;
memset ( & V_225 , 0 , sizeof V_225 ) ;
V_319 = F_173 ( V_55 ) ;
V_225 . V_19 = V_319 + V_169 -> V_19 ;
if ( V_225 . V_19 < V_169 -> V_19 )
return - V_48 ;
if ( V_225 . V_19 ) {
V_20 = F_88 ( V_225 . V_19 , V_469 ) ;
if ( ! V_20 )
return - V_138 ;
} else {
V_20 = NULL ;
}
if ( V_169 -> V_20 && V_169 -> V_19 )
memcpy ( V_20 + V_319 , V_169 -> V_20 ,
V_169 -> V_19 ) ;
V_6 = F_288 ( V_55 -> V_6 . V_8 , F_200 , V_55 ) ;
if ( F_104 ( V_6 ) ) {
V_59 = F_105 ( V_6 ) ;
goto V_121;
}
V_55 -> V_184 . V_90 = V_6 ;
V_78 = & V_55 -> V_6 . V_78 ;
if ( V_20 ) {
V_59 = F_284 ( V_20 , V_55 ) ;
if ( V_59 )
goto V_121;
V_225 . V_20 = V_20 ;
}
V_225 . V_222 = & V_78 -> V_283 [ 0 ] ;
if ( V_78 -> V_316 == 2 )
V_225 . V_317 = & V_78 -> V_283 [ 1 ] ;
V_225 . V_208 = F_212 ( & V_55 -> V_6 , F_59 ( V_55 ) ) ;
V_225 . V_166 = V_55 -> V_166 ;
V_225 . V_137 = V_55 -> V_6 . V_137 ;
V_225 . V_474 = V_55 -> V_147 ;
V_225 . V_174 = V_169 -> V_174 ;
V_225 . V_176 = V_169 -> V_176 ;
V_225 . V_288 = V_169 -> V_288 ;
V_225 . V_321 = F_291 ( T_3 , 7 , V_169 -> V_321 ) ;
V_225 . V_289 = F_291 ( T_3 , 7 , V_169 -> V_289 ) ;
V_225 . V_475 = V_470 ;
V_225 . V_476 = V_470 ;
V_225 . V_471 = V_472 ;
V_225 . V_167 = V_55 -> V_167 ? 1 : 0 ;
V_59 = F_292 ( V_55 -> V_184 . V_90 , & V_225 ) ;
V_121:
if ( V_59 && ! F_104 ( V_6 ) ) {
F_191 ( V_6 ) ;
V_55 -> V_184 . V_90 = NULL ;
}
F_55 ( V_20 ) ;
return V_59 ;
}
static int F_293 ( struct V_54 * V_55 ,
struct V_168 * V_169 )
{
struct V_335 * V_184 ;
int V_59 ;
struct V_477 V_478 ;
V_184 = F_219 ( V_55 -> V_6 . V_8 , F_213 , V_55 ) ;
if ( F_104 ( V_184 ) )
return F_105 ( V_184 ) ;
V_184 -> V_353 = V_55 -> V_353 ;
V_55 -> V_184 . V_186 = V_184 ;
memcpy ( & V_184 -> V_340 , F_58 ( V_55 ) ,
F_214 ( F_58 ( V_55 ) ) ) ;
memcpy ( & V_184 -> V_342 , F_59 ( V_55 ) ,
F_214 ( F_59 ( V_55 ) ) ) ;
V_59 = F_108 ( V_55 , V_169 ) ;
if ( V_59 )
goto V_121;
if ( V_169 ) {
V_478 . V_346 = V_169 -> V_176 ;
V_478 . V_345 = V_169 -> V_174 ;
V_478 . V_20 = V_169 -> V_20 ;
V_478 . V_19 = V_169 -> V_19 ;
V_478 . V_467 = V_55 -> V_6 . V_149 ? V_55 -> V_166 : V_169 -> V_166 ;
} else {
memset ( & V_478 , 0 , sizeof V_478 ) ;
V_478 . V_467 = V_55 -> V_166 ;
}
V_59 = F_294 ( V_184 , & V_478 ) ;
V_121:
if ( V_59 ) {
F_192 ( V_184 ) ;
V_55 -> V_184 . V_186 = NULL ;
}
return V_59 ;
}
int F_295 ( struct V_5 * V_6 , struct V_168 * V_169 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_36 ( V_55 , V_386 , V_292 ) )
return - V_48 ;
if ( ! V_6 -> V_149 ) {
V_55 -> V_166 = V_169 -> V_166 ;
V_55 -> V_167 = V_169 -> V_167 ;
}
if ( F_116 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( V_6 -> V_137 == V_164 )
V_59 = F_287 ( V_55 , V_169 ) ;
else
V_59 = F_290 ( V_55 , V_169 ) ;
} else if ( F_118 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_293 ( V_55 , V_169 ) ;
else
V_59 = - V_187 ;
if ( V_59 )
goto V_165;
return 0 ;
V_165:
F_36 ( V_55 , V_292 , V_386 ) ;
return V_59 ;
}
static int F_296 ( struct V_54 * V_55 ,
struct V_168 * V_169 )
{
struct V_479 V_461 ;
int V_59 ;
V_59 = F_108 ( V_55 , V_169 ) ;
if ( V_59 )
goto V_121;
V_59 = F_111 ( V_55 , V_169 ) ;
if ( V_59 )
goto V_121;
memset ( & V_461 , 0 , sizeof V_461 ) ;
V_461 . V_166 = V_55 -> V_166 ;
V_461 . V_474 = V_55 -> V_147 ;
V_461 . V_20 = V_169 -> V_20 ;
V_461 . V_19 = V_169 -> V_19 ;
V_461 . V_174 = V_169 -> V_174 ;
V_461 . V_176 = V_169 -> V_176 ;
V_461 . V_480 = 0 ;
V_461 . V_288 = V_169 -> V_288 ;
V_461 . V_289 = F_291 ( T_3 , 7 , V_169 -> V_289 ) ;
V_461 . V_167 = V_55 -> V_167 ? 1 : 0 ;
V_59 = F_297 ( V_55 -> V_184 . V_90 , & V_461 ) ;
V_121:
return V_59 ;
}
static int F_298 ( struct V_54 * V_55 ,
struct V_168 * V_169 )
{
struct V_477 V_478 ;
int V_59 ;
if ( ! V_169 )
return - V_48 ;
V_59 = F_108 ( V_55 , V_169 ) ;
if ( V_59 )
return V_59 ;
V_478 . V_346 = V_169 -> V_176 ;
V_478 . V_345 = V_169 -> V_174 ;
V_478 . V_20 = V_169 -> V_20 ;
V_478 . V_19 = V_169 -> V_19 ;
if ( V_55 -> V_6 . V_149 ) {
V_478 . V_467 = V_55 -> V_166 ;
} else
V_478 . V_467 = V_169 -> V_166 ;
return F_299 ( V_55 -> V_184 . V_186 , & V_478 ) ;
}
static int F_300 ( struct V_54 * V_55 ,
enum V_481 V_16 , T_5 V_95 ,
const void * V_20 , int V_19 )
{
struct V_482 V_461 ;
int V_59 ;
memset ( & V_461 , 0 , sizeof V_461 ) ;
V_461 . V_16 = V_16 ;
if ( V_16 == V_466 ) {
V_59 = F_61 ( V_55 , V_95 ) ;
if ( V_59 )
return V_59 ;
V_461 . V_166 = V_55 -> V_166 ;
V_461 . V_95 = V_55 -> V_95 ;
}
V_461 . V_20 = V_20 ;
V_461 . V_19 = V_19 ;
return F_301 ( V_55 -> V_184 . V_90 , & V_461 ) ;
}
int F_302 ( struct V_5 * V_6 , struct V_168 * V_169 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
V_55 -> V_139 = F_90 ( V_140 ) ;
if ( ! F_33 ( V_55 , V_292 ) )
return - V_48 ;
if ( ! V_6 -> V_149 && V_169 ) {
V_55 -> V_166 = V_169 -> V_166 ;
V_55 -> V_167 = V_169 -> V_167 ;
}
if ( F_116 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( V_6 -> V_137 == V_164 ) {
if ( V_169 )
V_59 = F_300 ( V_55 , V_466 ,
V_169 -> V_95 ,
V_169 -> V_20 ,
V_169 -> V_19 ) ;
else
V_59 = F_300 ( V_55 , V_466 ,
0 , NULL , 0 ) ;
} else {
if ( V_169 )
V_59 = F_296 ( V_55 , V_169 ) ;
else
V_59 = F_195 ( V_55 ) ;
}
} else if ( F_118 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_298 ( V_55 , V_169 ) ;
else
V_59 = - V_187 ;
if ( V_59 )
goto V_284;
return 0 ;
V_284:
F_112 ( V_55 ) ;
F_303 ( V_6 , NULL , 0 ) ;
return V_59 ;
}
int F_304 ( struct V_5 * V_6 , enum V_483 V_2 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! V_55 -> V_184 . V_90 )
return - V_48 ;
switch ( V_6 -> V_8 -> V_82 ) {
case V_484 :
V_59 = F_305 ( V_55 -> V_184 . V_90 , V_2 ) ;
break;
default:
V_59 = 0 ;
break;
}
return V_59 ;
}
int F_303 ( struct V_5 * V_6 , const void * V_20 ,
T_3 V_19 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! V_55 -> V_184 . V_90 )
return - V_48 ;
if ( F_116 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( V_6 -> V_137 == V_164 )
V_59 = F_300 ( V_55 , V_485 , 0 ,
V_20 , V_19 ) ;
else
V_59 = F_198 ( V_55 -> V_184 . V_90 ,
V_10 , NULL ,
0 , V_20 , V_19 ) ;
} else if ( F_118 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
V_59 = F_306 ( V_55 -> V_184 . V_186 ,
V_20 , V_19 ) ;
} else
V_59 = - V_187 ;
return V_59 ;
}
int F_307 ( struct V_5 * V_6 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! V_55 -> V_184 . V_90 )
return - V_48 ;
if ( F_116 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
V_59 = F_112 ( V_55 ) ;
if ( V_59 )
goto V_121;
if ( F_308 ( V_55 -> V_184 . V_90 , NULL , 0 ) )
F_309 ( V_55 -> V_184 . V_90 , NULL , 0 ) ;
} else if ( F_118 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
V_59 = F_310 ( V_55 -> V_184 . V_186 , 0 ) ;
} else
V_59 = - V_48 ;
V_121:
return V_59 ;
}
static int F_311 ( int V_16 , struct V_486 * V_89 )
{
struct V_54 * V_55 ;
struct V_86 * V_87 = V_89 -> V_135 ;
struct V_12 V_2 ;
int V_59 = 0 ;
V_55 = V_87 -> V_55 ;
F_22 ( & V_55 -> V_144 ) ;
if ( V_55 -> V_60 != V_354 &&
V_55 -> V_60 != V_361 )
goto V_121;
if ( ! V_16 )
V_16 = F_61 ( V_55 , F_64 ( V_89 -> V_97 . V_95 ) ) ;
else
F_197 ( L_16 ,
V_16 ) ;
F_22 ( & V_55 -> V_143 ) ;
if ( ! V_16 && V_55 -> V_6 . V_149 ) {
V_16 = F_312 ( V_55 -> V_6 . V_149 , & V_89 -> V_97 . V_70 ,
F_144 ( V_89 -> V_97 . V_487 ) ) ;
if ( V_16 )
F_197 ( L_17 ,
V_16 ) ;
}
F_24 ( & V_55 -> V_143 ) ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_16 = V_16 ;
V_2 . V_17 . V_327 . V_20 = V_87 -> V_135 ;
if ( ! V_16 ) {
struct V_101 * V_80 =
& V_55 -> V_6 . V_78 . V_79 . V_80 ;
struct V_67 * V_68 =
F_74 ( & V_111 , V_80 -> V_120 ) ;
enum V_50 V_77 =
V_55 -> V_41 -> V_49 [ V_55 -> V_6 . V_9 -
F_27 ( V_55 -> V_41 -> V_8 ) ] ;
V_2 . V_2 = V_488 ;
F_313 ( V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 , & V_89 -> V_97 ,
V_68 , V_77 ,
& V_2 . V_17 . V_327 . V_170 ) ;
V_2 . V_17 . V_327 . V_166 = 0xFFFFFF ;
V_2 . V_17 . V_327 . V_95 = F_64 ( V_89 -> V_97 . V_95 ) ;
if ( V_68 )
F_76 ( V_68 ) ;
} else
V_2 . V_2 = V_489 ;
V_59 = V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_2 ) ;
if ( V_59 ) {
F_37 ( V_55 , V_281 ) ;
F_24 ( & V_55 -> V_144 ) ;
F_181 ( & V_55 -> V_6 ) ;
return 0 ;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
return 0 ;
}
static void F_314 ( struct V_54 * V_55 ,
struct V_91 * V_79 , union V_69 * V_70 )
{
unsigned char V_490 [ V_491 ] ;
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
struct V_189 * sin = (struct V_189 * ) V_79 ;
struct V_193 * V_366 = (struct V_193 * ) V_79 ;
if ( F_128 ( V_79 ) ) {
memset ( V_70 , 0 , sizeof *V_70 ) ;
} else if ( ( V_79 -> V_106 == V_192 ) &&
( ( F_64 ( V_366 -> V_194 . V_492 [ 0 ] ) & 0xFFF0FFFF ) ==
0xFF10A01B ) ) {
memcpy ( V_70 , & V_366 -> V_194 , sizeof *V_70 ) ;
} else if ( V_79 -> V_106 == V_107 ) {
memcpy ( V_70 , & ( (struct V_99 * ) V_79 ) -> V_104 , sizeof *V_70 ) ;
} else if ( ( V_79 -> V_106 == V_192 ) ) {
F_315 ( & V_366 -> V_194 , V_80 -> V_493 , V_490 ) ;
if ( V_55 -> V_6 . V_26 == V_30 )
V_490 [ 7 ] = 0x01 ;
* V_70 = * (union V_69 * ) ( V_490 + 4 ) ;
} else {
F_316 ( sin -> V_190 . V_191 , V_80 -> V_493 , V_490 ) ;
if ( V_55 -> V_6 . V_26 == V_30 )
V_490 [ 7 ] = 0x01 ;
* V_70 = * (union V_69 * ) ( V_490 + 4 ) ;
}
}
static void F_317 ( int V_16 ,
struct V_494 * V_97 ,
void * V_135 )
{
struct V_495 * V_496 = V_135 ;
F_318 ( ! V_135 ) ;
if ( V_16 || ! V_97 ) {
F_319 ( L_18 ,
V_496 -> V_8 -> V_355 , V_496 -> V_9 , V_16 ) ;
goto V_121;
}
memcpy ( V_496 -> V_497 , V_97 , sizeof( struct V_494 ) ) ;
V_121:
F_52 ( & V_496 -> V_498 ) ;
}
static int F_320 ( struct V_53 * V_8 , T_3 V_9 ,
struct V_494 * V_497 )
{
struct V_495 * V_496 ;
int V_59 ;
V_496 = F_203 ( sizeof( * V_496 ) , V_39 ) ;
if ( ! V_496 )
return - V_138 ;
V_496 -> V_8 = V_8 ;
V_496 -> V_497 = V_497 ;
V_496 -> V_9 = V_9 ;
F_93 ( & V_496 -> V_498 ) ;
V_59 = F_321 ( & V_380 , V_8 , V_9 ,
V_499 ,
V_39 , F_317 ,
V_496 , & V_496 -> V_500 ) ;
if ( V_59 < 0 ) {
F_201 ( L_19 ,
V_8 -> V_355 , V_9 , V_59 ) ;
goto V_121;
}
F_193 ( & V_496 -> V_498 ) ;
V_121:
F_55 ( V_496 ) ;
return V_59 ;
}
static int F_322 ( struct V_54 * V_55 ,
struct V_86 * V_87 )
{
struct V_96 V_97 ;
struct V_494 V_497 ;
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
T_11 V_365 ;
int V_59 ;
F_62 ( V_80 , & V_97 . V_70 ) ;
V_59 = F_63 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ,
& V_97 . V_70 , & V_97 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_61 ( V_55 , 0 ) ;
if ( V_59 )
return V_59 ;
F_314 ( V_55 , (struct V_91 * ) & V_87 -> V_79 , & V_97 . V_70 ) ;
V_97 . V_95 = F_323 ( V_55 -> V_95 ) ;
F_230 ( V_80 , & V_97 . V_501 ) ;
V_97 . V_126 = F_232 ( F_115 ( V_80 ) ) ;
V_97 . V_502 = V_87 -> V_502 ;
if ( V_97 . V_502 == F_324 ( V_503 ) ) {
V_59 = F_320 ( V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 ,
& V_497 ) ;
if ( V_59 )
return V_59 ;
if ( ! ( F_325 ( & V_497 ) &
V_504 ) ) {
F_224 ( L_20
L_21 ,
V_55 -> V_6 . V_8 -> V_355 , V_55 -> V_6 . V_9 ) ;
return - V_114 ;
}
}
V_365 = V_505 | V_506 |
V_507 | V_508 |
V_509 | V_510 |
V_511 |
V_512 ;
if ( V_55 -> V_6 . V_26 == V_32 )
V_365 |= V_513 |
V_514 |
V_515 |
V_516 |
V_517 ;
V_87 -> V_89 . V_90 = F_326 ( & V_380 , V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 , & V_97 ,
V_365 , V_39 ,
F_311 , V_87 ) ;
return F_327 ( V_87 -> V_89 . V_90 ) ;
}
static void F_328 ( struct V_381 * V_358 )
{
struct V_518 * V_519 = F_54 ( V_358 , struct V_518 , V_358 ) ;
struct V_86 * V_87 = V_519 -> V_87 ;
struct V_486 * V_520 = V_87 -> V_89 . V_90 ;
V_87 -> V_89 . V_90 -> V_135 = V_87 ;
F_311 ( 0 , V_520 ) ;
F_190 ( & V_87 -> V_88 , F_53 ) ;
F_55 ( V_519 ) ;
}
static void F_329 ( struct V_91 * V_79 , union V_69 * V_70 )
{
struct V_189 * sin = (struct V_189 * ) V_79 ;
struct V_193 * V_366 = (struct V_193 * ) V_79 ;
if ( F_128 ( V_79 ) ) {
memset ( V_70 , 0 , sizeof *V_70 ) ;
} else if ( V_79 -> V_106 == V_192 ) {
memcpy ( V_70 , & V_366 -> V_194 , sizeof *V_70 ) ;
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
* ( V_74 * ) ( & V_70 -> V_75 [ 12 ] ) = sin -> V_190 . V_191 ;
}
}
static int F_330 ( struct V_54 * V_55 ,
struct V_86 * V_87 )
{
struct V_518 * V_358 ;
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
int V_165 = 0 ;
struct V_91 * V_79 = (struct V_91 * ) & V_87 -> V_79 ;
struct V_67 * V_68 = NULL ;
enum V_50 V_77 ;
bool V_521 ;
V_521 = V_87 -> V_502 == F_324 ( V_503 ) ;
if ( F_120 ( (struct V_91 * ) & V_87 -> V_79 ) )
return - V_48 ;
V_358 = F_88 ( sizeof *V_358 , V_39 ) ;
if ( ! V_358 )
return - V_138 ;
V_87 -> V_89 . V_90 = F_88 ( sizeof( struct V_486 ) , V_39 ) ;
if ( ! V_87 -> V_89 . V_90 ) {
V_165 = - V_138 ;
goto V_522;
}
F_329 ( V_79 , & V_87 -> V_89 . V_90 -> V_97 . V_70 ) ;
V_87 -> V_89 . V_90 -> V_97 . V_126 = F_232 ( 0xffff ) ;
if ( V_55 -> V_6 . V_26 == V_30 )
V_87 -> V_89 . V_90 -> V_97 . V_95 = F_323 ( V_98 ) ;
if ( V_80 -> V_120 )
V_68 = F_74 ( & V_111 , V_80 -> V_120 ) ;
if ( ! V_68 ) {
V_165 = - V_76 ;
goto V_523;
}
V_87 -> V_89 . V_90 -> V_97 . V_410 = F_252 ( V_68 ) ;
V_87 -> V_89 . V_90 -> V_97 . V_403 = 1 ;
V_87 -> V_89 . V_90 -> V_97 . V_408 = F_251 ( V_68 -> V_408 ) ;
V_77 = V_55 -> V_41 -> V_49 [ V_55 -> V_6 . V_9 -
F_27 ( V_55 -> V_41 -> V_8 ) ] ;
if ( V_79 -> V_106 == V_188 ) {
if ( V_77 == V_398 ) {
V_87 -> V_89 . V_90 -> V_97 . V_403 = V_524 ;
if ( ! V_521 ) {
V_165 = F_40 ( V_68 , & V_87 -> V_89 . V_90 -> V_97 . V_70 ,
true ) ;
if ( ! V_165 )
V_87 -> V_280 = true ;
}
}
} else {
if ( V_77 == V_398 )
V_165 = - V_525 ;
}
F_76 ( V_68 ) ;
if ( V_165 || ! V_87 -> V_89 . V_90 -> V_97 . V_408 ) {
if ( ! V_165 )
V_165 = - V_48 ;
goto V_523;
}
F_79 ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_92 ,
& V_87 -> V_89 . V_90 -> V_97 . V_501 ) ;
V_358 -> V_6 = V_55 ;
V_358 -> V_87 = V_87 ;
F_237 ( & V_358 -> V_358 , F_328 ) ;
F_331 ( & V_87 -> V_88 ) ;
F_228 ( V_363 , & V_358 -> V_358 ) ;
return 0 ;
V_523:
F_55 ( V_87 -> V_89 . V_90 ) ;
V_522:
F_55 ( V_358 ) ;
return V_165 ;
}
int F_332 ( struct V_5 * V_6 , struct V_91 * V_79 ,
T_3 V_502 , void * V_135 )
{
struct V_54 * V_55 ;
struct V_86 * V_87 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_33 ( V_55 , V_354 ) &&
! F_33 ( V_55 , V_361 ) )
return - V_48 ;
V_87 = F_203 ( sizeof *V_87 , V_39 ) ;
if ( ! V_87 )
return - V_138 ;
memcpy ( & V_87 -> V_79 , V_79 , F_214 ( V_79 ) ) ;
V_87 -> V_135 = V_135 ;
V_87 -> V_55 = V_55 ;
V_87 -> V_280 = false ;
V_87 -> V_502 = V_502 ;
F_333 ( & V_55 -> V_46 ) ;
F_334 ( & V_87 -> V_83 , & V_55 -> V_146 ) ;
F_335 ( & V_55 -> V_46 ) ;
if ( F_73 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
F_336 ( & V_87 -> V_88 ) ;
V_59 = F_330 ( V_55 , V_87 ) ;
} else if ( F_188 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_322 ( V_55 , V_87 ) ;
else
V_59 = - V_187 ;
if ( V_59 ) {
F_337 ( & V_55 -> V_46 ) ;
F_57 ( & V_87 -> V_83 ) ;
F_338 ( & V_55 -> V_46 ) ;
F_55 ( V_87 ) ;
}
return V_59 ;
}
void F_339 ( struct V_5 * V_6 , struct V_91 * V_79 )
{
struct V_54 * V_55 ;
struct V_86 * V_87 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
F_337 ( & V_55 -> V_46 ) ;
F_23 (mc, &id_priv->mc_list, list) {
if ( ! memcmp ( & V_87 -> V_79 , V_79 , F_214 ( V_79 ) ) ) {
F_57 ( & V_87 -> V_83 ) ;
F_338 ( & V_55 -> V_46 ) ;
if ( V_6 -> V_149 )
F_340 ( V_6 -> V_149 ,
& V_87 -> V_89 . V_90 -> V_97 . V_70 ,
F_144 ( V_87 -> V_89 . V_90 -> V_97 . V_487 ) ) ;
F_110 ( V_55 -> V_41 -> V_8 != V_6 -> V_8 ) ;
if ( F_188 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
F_189 ( V_87 -> V_89 . V_90 ) ;
F_55 ( V_87 ) ;
} else if ( F_73 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( V_87 -> V_280 ) {
struct V_101 * V_80 =
& V_6 -> V_78 . V_79 . V_80 ;
struct V_67 * V_68 = NULL ;
if ( V_80 -> V_120 )
V_68 = F_74 ( & V_111 ,
V_80 -> V_120 ) ;
if ( V_68 ) {
F_40 ( V_68 ,
& V_87 -> V_89 . V_90 -> V_97 . V_70 ,
false ) ;
F_76 ( V_68 ) ;
}
V_87 -> V_280 = false ;
}
F_190 ( & V_87 -> V_88 , F_53 ) ;
}
return;
}
}
F_338 ( & V_55 -> V_46 ) ;
}
static int F_341 ( struct V_67 * V_68 , struct V_54 * V_55 )
{
struct V_101 * V_80 ;
struct V_384 * V_358 ;
V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
if ( ( V_80 -> V_120 == V_68 -> V_242 ) &&
( F_168 ( F_151 ( V_68 ) , V_80 -> V_22 ) ) &&
memcmp ( V_80 -> V_119 , V_68 -> V_80 , V_68 -> V_526 ) ) {
F_75 ( L_22 ,
V_68 -> V_355 , & V_55 -> V_6 ) ;
V_358 = F_88 ( sizeof *V_358 , V_39 ) ;
if ( ! V_358 )
return - V_138 ;
F_237 ( & V_358 -> V_358 , F_235 ) ;
V_358 -> V_6 = V_55 ;
V_358 -> V_2 . V_2 = V_527 ;
F_20 ( & V_55 -> V_42 ) ;
F_228 ( V_363 , & V_358 -> V_358 ) ;
}
return 0 ;
}
static int F_342 ( struct V_528 * V_529 , unsigned long V_2 ,
void * V_530 )
{
struct V_67 * V_68 = F_343 ( V_530 ) ;
struct V_40 * V_41 ;
struct V_54 * V_55 ;
int V_59 = V_531 ;
if ( V_2 != V_532 )
return V_531 ;
if ( ! ( V_68 -> V_58 & V_533 ) || ! ( V_68 -> V_534 & V_535 ) )
return V_531 ;
F_22 ( & V_46 ) ;
F_23 (cma_dev, &dev_list, list)
F_23 (id_priv, &cma_dev->id_list, list) {
V_59 = F_341 ( V_68 , V_55 ) ;
if ( V_59 )
goto V_121;
}
V_121:
F_24 ( & V_46 ) ;
return V_59 ;
}
static void F_344 ( struct V_53 * V_8 )
{
struct V_40 * V_41 ;
struct V_54 * V_55 ;
unsigned int V_129 ;
unsigned long V_51 = 0 ;
V_41 = F_203 ( sizeof *V_41 , V_39 ) ;
if ( ! V_41 )
return;
V_41 -> V_8 = V_8 ;
V_41 -> V_49 = F_345 ( V_8 -> V_122 ,
sizeof( * V_41 -> V_49 ) ,
V_39 ) ;
if ( ! V_41 -> V_49 )
goto V_536;
V_41 -> V_52 = F_345 ( V_8 -> V_122 ,
sizeof( * V_41 -> V_52 ) ,
V_39 ) ;
if ( ! V_41 -> V_52 )
goto V_537;
for ( V_129 = F_27 ( V_8 ) ; V_129 <= F_346 ( V_8 ) ; V_129 ++ ) {
V_51 = F_29 ( V_8 , V_129 ) ;
F_318 ( ! V_51 ) ;
V_41 -> V_49 [ V_129 - F_27 ( V_8 ) ] =
F_347 ( & V_51 , V_538 ) ;
V_41 -> V_52 [ V_129 - F_27 ( V_8 ) ] = 0 ;
}
F_93 ( & V_41 -> V_57 ) ;
F_94 ( & V_41 -> V_42 , 1 ) ;
F_95 ( & V_41 -> V_84 ) ;
F_348 ( V_8 , & V_539 , V_41 ) ;
F_22 ( & V_46 ) ;
F_48 ( & V_41 -> V_83 , & V_540 ) ;
F_23 (id_priv, &listen_any_list, list)
F_222 ( V_55 , V_41 ) ;
F_24 ( & V_46 ) ;
return;
V_537:
F_55 ( V_41 -> V_49 ) ;
V_536:
F_55 ( V_41 ) ;
return;
}
static int F_349 ( struct V_54 * V_55 )
{
struct V_12 V_2 ;
enum V_56 V_60 ;
int V_59 = 0 ;
V_60 = F_37 ( V_55 , V_385 ) ;
if ( V_60 == V_281 )
return 0 ;
F_182 ( V_55 , V_60 ) ;
F_22 ( & V_55 -> V_144 ) ;
if ( ! F_33 ( V_55 , V_385 ) )
goto V_121;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_541 ;
V_59 = V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_2 ) ;
V_121:
F_24 ( & V_55 -> V_144 ) ;
return V_59 ;
}
static void F_350 ( struct V_40 * V_41 )
{
struct V_54 * V_55 ;
int V_59 ;
F_22 ( & V_46 ) ;
while ( ! F_178 ( & V_41 -> V_84 ) ) {
V_55 = F_179 ( V_41 -> V_84 . V_274 ,
struct V_54 , V_83 ) ;
F_57 ( & V_55 -> V_145 ) ;
F_180 ( & V_55 -> V_83 ) ;
F_20 ( & V_55 -> V_42 ) ;
F_24 ( & V_46 ) ;
V_59 = V_55 -> V_282 ? 1 : F_349 ( V_55 ) ;
F_86 ( V_55 ) ;
if ( V_59 )
F_181 ( & V_55 -> V_6 ) ;
F_22 ( & V_46 ) ;
}
F_24 ( & V_46 ) ;
F_50 ( V_41 ) ;
F_193 ( & V_41 -> V_57 ) ;
}
static void F_351 ( struct V_53 * V_8 , void * V_542 )
{
struct V_40 * V_41 = V_542 ;
if ( ! V_41 )
return;
F_22 ( & V_46 ) ;
F_57 ( & V_41 -> V_83 ) ;
F_24 ( & V_46 ) ;
F_350 ( V_41 ) ;
F_55 ( V_41 -> V_52 ) ;
F_55 ( V_41 -> V_49 ) ;
F_55 ( V_41 ) ;
}
static int F_352 ( struct V_543 * V_544 , struct V_545 * V_546 )
{
struct V_547 * V_548 ;
struct V_549 * V_550 ;
struct V_54 * V_55 ;
struct V_5 * V_6 = NULL ;
struct V_40 * V_41 ;
int V_551 = 0 , V_552 = 0 ;
F_22 ( & V_46 ) ;
F_23 (cma_dev, &dev_list, list) {
if ( V_551 < V_546 -> args [ 0 ] ) {
V_551 ++ ;
continue;
}
V_552 = 0 ;
F_23 (id_priv, &cma_dev->id_list, list) {
if ( V_552 < V_546 -> args [ 1 ] ) {
V_552 ++ ;
continue;
}
V_550 = F_353 ( V_544 , & V_548 , V_546 -> V_548 -> V_553 ,
sizeof *V_550 , V_554 ,
V_555 ,
V_556 ) ;
if ( ! V_550 )
goto V_121;
memset ( V_550 , 0 , sizeof *V_550 ) ;
V_6 = & V_55 -> V_6 ;
V_550 -> V_82 = V_6 -> V_78 . V_79 . V_80 . V_102 ;
V_550 -> V_9 = V_6 -> V_9 ;
V_550 -> V_120 =
V_6 -> V_78 . V_79 . V_80 . V_120 ;
if ( F_354 ( V_544 , V_548 ,
F_214 ( F_58 ( V_55 ) ) ,
F_58 ( V_55 ) ,
V_557 ) )
goto V_121;
if ( F_354 ( V_544 , V_548 ,
F_214 ( F_58 ( V_55 ) ) ,
F_59 ( V_55 ) ,
V_558 ) )
goto V_121;
V_550 -> V_559 = V_55 -> V_139 ;
V_550 -> V_560 = V_6 -> V_26 ;
V_550 -> V_561 = V_55 -> V_60 ;
V_550 -> V_166 = V_55 -> V_166 ;
V_550 -> V_137 = V_6 -> V_137 ;
V_552 ++ ;
}
V_546 -> args [ 1 ] = 0 ;
V_551 ++ ;
}
V_121:
F_24 ( & V_46 ) ;
V_546 -> args [ 0 ] = V_551 ;
V_546 -> args [ 1 ] = V_552 ;
return V_544 -> V_562 ;
}
static int F_355 ( struct V_22 * V_22 )
{
struct V_21 * V_27 = V_21 ( V_22 ) ;
F_356 ( & V_27 -> V_29 ) ;
F_356 ( & V_27 -> V_31 ) ;
F_356 ( & V_27 -> V_33 ) ;
F_356 ( & V_27 -> V_35 ) ;
return 0 ;
}
static void F_357 ( struct V_22 * V_22 )
{
struct V_21 * V_27 = V_21 ( V_22 ) ;
F_358 ( & V_27 -> V_29 ) ;
F_358 ( & V_27 -> V_31 ) ;
F_358 ( & V_27 -> V_33 ) ;
F_358 ( & V_27 -> V_35 ) ;
}
static int T_13 F_359 ( void )
{
int V_59 ;
V_363 = F_360 ( L_23 , V_563 ) ;
if ( ! V_363 )
return - V_138 ;
V_59 = F_361 ( & V_564 ) ;
if ( V_59 )
goto V_565;
F_362 ( & V_380 ) ;
F_363 ( & V_421 ) ;
F_364 ( & V_566 ) ;
V_59 = F_365 ( & V_539 ) ;
if ( V_59 )
goto V_165;
if ( F_366 ( V_554 , F_2 ( V_567 ) ,
V_567 ) )
F_224 ( L_24 ) ;
F_367 () ;
return 0 ;
V_165:
F_368 ( & V_566 ) ;
F_369 ( & V_421 ) ;
F_370 ( & V_380 ) ;
V_565:
F_371 ( V_363 ) ;
return V_59 ;
}
static void T_14 F_372 ( void )
{
F_373 () ;
F_374 ( V_554 ) ;
F_375 ( & V_539 ) ;
F_368 ( & V_566 ) ;
F_369 ( & V_421 ) ;
F_370 ( & V_380 ) ;
F_376 ( & V_564 ) ;
F_371 ( V_363 ) ;
}
