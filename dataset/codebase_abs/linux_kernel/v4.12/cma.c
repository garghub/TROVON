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
F_110 ( & V_151 . V_170 ) -> V_171 ,
& V_124 , NULL ) ;
if ( V_59 )
goto V_121;
F_111 ( V_55 -> V_41 -> V_8 != V_55 -> V_6 . V_8 ) ;
if ( V_169 )
V_151 . V_172 = V_169 -> V_173 ;
V_59 = F_100 ( V_55 -> V_6 . V_149 , & V_151 , V_152 ) ;
V_121:
F_24 ( & V_55 -> V_143 ) ;
return V_59 ;
}
static int F_112 ( struct V_54 * V_55 ,
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
V_151 . V_174 = V_169 -> V_175 ;
V_59 = F_100 ( V_55 -> V_6 . V_149 , & V_151 , V_152 ) ;
V_121:
F_24 ( & V_55 -> V_143 ) ;
return V_59 ;
}
static int F_113 ( struct V_54 * V_55 )
{
struct V_150 V_151 ;
int V_59 ;
F_22 ( & V_55 -> V_143 ) ;
if ( ! V_55 -> V_6 . V_149 ) {
V_59 = 0 ;
goto V_121;
}
V_151 . V_153 = V_176 ;
V_59 = F_100 ( V_55 -> V_6 . V_149 , & V_151 , V_156 ) ;
V_121:
F_24 ( & V_55 -> V_143 ) ;
return V_59 ;
}
static int F_114 ( struct V_54 * V_55 ,
struct V_150 * V_151 , int * V_152 )
{
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
int V_59 ;
T_6 V_126 ;
if ( F_115 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ) )
V_126 = 0xffff ;
else
V_126 = F_116 ( V_80 ) ;
V_59 = F_83 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ,
V_126 , & V_151 -> V_177 ) ;
if ( V_59 )
return V_59 ;
V_151 -> V_9 = V_55 -> V_6 . V_9 ;
* V_152 = V_156 | V_178 | V_179 ;
if ( V_55 -> V_6 . V_137 == V_164 ) {
V_59 = F_61 ( V_55 , 0 ) ;
if ( V_59 )
return V_59 ;
V_151 -> V_95 = V_55 -> V_95 ;
* V_152 |= V_180 ;
} else {
V_151 -> V_181 = 0 ;
* V_152 |= V_182 ;
}
return 0 ;
}
int F_99 ( struct V_5 * V_6 , struct V_150 * V_151 ,
int * V_152 )
{
struct V_54 * V_55 ;
int V_59 = 0 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( F_117 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( ! V_55 -> V_183 . V_90 || ( V_55 -> V_6 . V_137 == V_164 ) )
V_59 = F_114 ( V_55 , V_151 , V_152 ) ;
else
V_59 = F_118 ( V_55 -> V_183 . V_90 , V_151 ,
V_152 ) ;
if ( V_151 -> V_153 == V_155 )
V_151 -> V_184 = V_55 -> V_147 ;
} else if ( F_119 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( ! V_55 -> V_183 . V_185 ) {
V_151 -> V_181 = 0 ;
* V_152 = V_156 | V_182 ;
} else
V_59 = F_120 ( V_55 -> V_183 . V_185 , V_151 ,
V_152 ) ;
} else
V_59 = - V_186 ;
return V_59 ;
}
static inline int F_121 ( struct V_91 * V_79 )
{
switch ( V_79 -> V_106 ) {
case V_187 :
return F_122 ( ( (struct V_188 * ) V_79 ) -> V_189 . V_190 ) ;
case V_191 :
return F_123 ( & ( (struct V_192 * ) V_79 ) -> V_193 ) ;
case V_107 :
return F_124 ( & ( (struct V_99 * ) V_79 ) -> V_104 ) ;
default:
return 0 ;
}
}
static inline int F_125 ( struct V_91 * V_79 )
{
switch ( V_79 -> V_106 ) {
case V_187 :
return F_126 ( ( (struct V_188 * ) V_79 ) -> V_189 . V_190 ) ;
case V_191 :
return F_127 ( & ( (struct V_192 * ) V_79 ) -> V_193 ) ;
case V_107 :
return F_128 ( & ( (struct V_99 * ) V_79 ) -> V_104 ) ;
default:
return 0 ;
}
}
static inline int F_129 ( struct V_91 * V_79 )
{
return F_121 ( V_79 ) || F_125 ( V_79 ) ;
}
static int F_130 ( struct V_91 * V_194 , struct V_91 * V_195 )
{
if ( V_194 -> V_106 != V_195 -> V_106 )
return - 1 ;
switch ( V_194 -> V_106 ) {
case V_187 :
return ( (struct V_188 * ) V_194 ) -> V_189 . V_190 !=
( (struct V_188 * ) V_195 ) -> V_189 . V_190 ;
case V_191 :
return F_131 ( & ( (struct V_192 * ) V_194 ) -> V_193 ,
& ( (struct V_192 * ) V_195 ) -> V_193 ) ;
default:
return F_132 ( & ( (struct V_99 * ) V_194 ) -> V_104 ,
& ( (struct V_99 * ) V_195 ) -> V_104 ) ;
}
}
static T_8 F_133 ( struct V_91 * V_79 )
{
struct V_99 * V_100 ;
switch ( V_79 -> V_106 ) {
case V_187 :
return ( (struct V_188 * ) V_79 ) -> V_196 ;
case V_191 :
return ( (struct V_192 * ) V_79 ) -> V_197 ;
case V_107 :
V_100 = (struct V_99 * ) V_79 ;
return F_134 ( ( T_6 ) ( F_135 ( V_100 -> V_198 ) &
F_135 ( V_100 -> V_199 ) ) ) ;
default:
return 0 ;
}
}
static inline int F_136 ( struct V_91 * V_79 )
{
return ! F_133 ( V_79 ) ;
}
static void F_137 ( struct V_91 * V_92 ,
struct V_91 * V_93 ,
struct V_5 * V_200 ,
struct V_201 * V_202 )
{
struct V_99 * V_203 , * V_90 ;
V_203 = (struct V_99 * ) & V_200 -> V_78 . V_79 . V_92 ;
if ( V_92 ) {
V_90 = (struct V_99 * ) V_92 ;
V_90 -> V_204 = V_107 ;
if ( V_202 ) {
V_90 -> V_105 = V_202 -> V_126 ;
V_90 -> V_205 = V_202 -> V_206 ;
memcpy ( & V_90 -> V_104 , & V_202 -> V_124 , 16 ) ;
V_90 -> V_198 = V_202 -> V_207 ;
V_90 -> V_208 = 0 ;
} else {
V_90 -> V_105 = V_203 -> V_105 ;
V_90 -> V_205 = V_203 -> V_205 ;
V_90 -> V_104 = V_203 -> V_104 ;
V_90 -> V_198 = V_203 -> V_198 ;
V_90 -> V_208 = V_203 -> V_208 ;
}
V_90 -> V_199 = F_138 ( 0xffffffffffffffffULL ) ;
}
if ( V_93 ) {
V_90 = (struct V_99 * ) V_93 ;
V_90 -> V_204 = V_107 ;
if ( V_202 ) {
V_90 -> V_105 = V_202 -> V_126 ;
V_90 -> V_205 = V_202 -> V_206 ;
memcpy ( & V_90 -> V_104 , & V_202 -> V_125 , 16 ) ;
}
}
}
static void F_139 ( struct V_188 * V_92 ,
struct V_188 * V_93 ,
struct V_63 * V_64 ,
T_8 V_209 )
{
if ( V_92 ) {
* V_92 = (struct V_188 ) {
. V_210 = V_187 ,
. V_189 . V_190 = V_64 -> V_93 . V_211 . V_79 ,
. V_196 = V_209 ,
} ;
}
if ( V_93 ) {
* V_93 = (struct V_188 ) {
. V_210 = V_187 ,
. V_189 . V_190 = V_64 -> V_92 . V_211 . V_79 ,
. V_196 = V_64 -> V_47 ,
} ;
}
}
static void F_140 ( struct V_192 * V_92 ,
struct V_192 * V_93 ,
struct V_63 * V_64 ,
T_8 V_209 )
{
if ( V_92 ) {
* V_92 = (struct V_192 ) {
. V_212 = V_191 ,
. V_193 = V_64 -> V_93 . V_213 ,
. V_197 = V_209 ,
} ;
}
if ( V_93 ) {
* V_93 = (struct V_192 ) {
. V_212 = V_191 ,
. V_193 = V_64 -> V_92 . V_213 ,
. V_197 = V_64 -> V_47 ,
} ;
}
}
static T_6 F_141 ( T_9 V_207 )
{
return ( T_6 ) F_135 ( V_207 ) ;
}
static int F_142 ( struct V_91 * V_92 ,
struct V_91 * V_93 ,
struct V_214 * V_215 ,
T_9 V_207 )
{
struct V_63 * V_64 ;
T_8 V_47 ;
V_64 = V_215 -> V_20 ;
if ( V_64 -> V_216 != V_217 )
return - V_48 ;
V_47 = F_134 ( F_141 ( V_207 ) ) ;
switch ( F_38 ( V_64 ) ) {
case 4 :
F_139 ( (struct V_188 * ) V_92 ,
(struct V_188 * ) V_93 , V_64 , V_47 ) ;
break;
case 6 :
F_140 ( (struct V_192 * ) V_92 ,
(struct V_192 * ) V_93 , V_64 , V_47 ) ;
break;
default:
return - V_218 ;
}
return 0 ;
}
static int F_143 ( struct V_91 * V_92 ,
struct V_91 * V_93 ,
struct V_5 * V_200 ,
struct V_214 * V_215 ,
T_10 V_106 , T_9 V_207 )
{
if ( V_106 == V_107 ) {
if ( V_215 -> V_2 == V_219 )
F_137 ( V_92 , V_93 , V_200 ,
V_215 -> V_17 . V_220 . V_221 ) ;
else if ( V_215 -> V_2 == V_222 )
F_137 ( V_92 , V_93 , V_200 , NULL ) ;
return 0 ;
}
return F_142 ( V_92 , V_93 , V_215 , V_207 ) ;
}
static int F_144 ( const struct V_214 * V_215 ,
struct V_223 * V_224 )
{
const struct V_225 * V_226 =
& V_215 -> V_17 . V_220 ;
const struct V_227 * V_228 =
& V_215 -> V_17 . V_229 ;
switch ( V_215 -> V_2 ) {
case V_219 :
V_224 -> V_8 = V_226 -> V_200 -> V_8 ;
V_224 -> V_47 = V_226 -> V_47 ;
memcpy ( & V_224 -> V_230 , & V_226 -> V_221 -> V_124 ,
sizeof( V_224 -> V_230 ) ) ;
V_224 -> V_231 = true ;
V_224 -> V_207 = V_226 -> V_221 -> V_207 ;
V_224 -> V_126 = F_145 ( V_226 -> V_221 -> V_126 ) ;
if ( V_224 -> V_126 != V_226 -> V_232 )
F_146 ( L_4
L_5 ,
V_226 -> V_232 , V_224 -> V_126 ) ;
break;
case V_222 :
V_224 -> V_8 = V_228 -> V_200 -> V_8 ;
V_224 -> V_47 = V_228 -> V_47 ;
V_224 -> V_231 = false ;
V_224 -> V_207 = V_228 -> V_207 ;
V_224 -> V_126 = V_228 -> V_126 ;
if ( V_224 -> V_126 != V_228 -> V_232 )
F_146 ( L_6
L_5 ,
V_228 -> V_232 , V_224 -> V_126 ) ;
break;
default:
return - V_48 ;
}
return 0 ;
}
static bool F_147 ( struct V_67 * V_233 ,
const struct V_188 * V_93 ,
const struct V_188 * V_92 )
{
V_74 V_234 = V_93 -> V_189 . V_190 ,
V_235 = V_92 -> V_189 . V_190 ;
struct V_236 V_237 ;
struct V_238 V_239 ;
int V_165 ;
bool V_59 ;
if ( F_148 ( V_235 ) || F_149 ( V_235 ) ||
F_149 ( V_234 ) || F_122 ( V_235 ) ||
F_122 ( V_234 ) || F_126 ( V_234 ) ||
F_126 ( V_235 ) )
return false ;
memset ( & V_239 , 0 , sizeof( V_239 ) ) ;
V_239 . V_240 = V_233 -> V_241 ;
V_239 . V_234 = V_234 ;
V_239 . V_235 = V_235 ;
F_150 () ;
V_165 = F_151 ( F_152 ( V_233 ) , & V_239 , & V_237 , 0 ) ;
V_59 = V_165 == 0 && F_153 ( V_237 ) == V_233 ;
F_154 () ;
return V_59 ;
}
static bool F_155 ( struct V_67 * V_233 ,
const struct V_192 * V_93 ,
const struct V_192 * V_92 )
{
#if F_156 ( V_242 )
const int V_243 = F_157 ( & V_93 -> V_193 ) &
V_244 ;
struct V_245 * V_246 = F_158 ( F_152 ( V_233 ) , & V_93 -> V_193 ,
& V_92 -> V_193 , V_233 -> V_241 ,
V_243 ) ;
bool V_59 ;
if ( ! V_246 )
return false ;
V_59 = V_246 -> V_247 -> V_248 == V_233 ;
F_159 ( V_246 ) ;
return V_59 ;
#else
return false ;
#endif
}
static bool F_160 ( struct V_67 * V_233 ,
const struct V_91 * V_234 ,
const struct V_91 * V_235 )
{
const struct V_188 * V_249 = ( const struct V_188 * ) V_234 ;
const struct V_188 * V_250 = ( const struct V_188 * ) V_235 ;
const struct V_192 * V_251 = ( const struct V_192 * ) V_234 ;
const struct V_192 * V_252 = ( const struct V_192 * ) V_235 ;
switch ( V_234 -> V_106 ) {
case V_187 :
return V_235 -> V_106 == V_187 &&
F_147 ( V_233 , V_249 , V_250 ) ;
case V_191 :
return V_235 -> V_106 == V_191 &&
F_155 ( V_233 , V_251 , V_252 ) ;
default:
return false ;
}
}
static struct V_67 * F_161 ( struct V_214 * V_215 ,
const struct V_223 * V_224 )
{
struct V_253 V_254 , V_255 ;
struct V_91 * V_256 = (struct V_91 * ) & V_254 ,
* V_92 = (struct V_91 * ) & V_255 ;
struct V_67 * V_233 ;
const union V_69 * V_108 = V_224 -> V_231 ? & V_224 -> V_230 : NULL ;
int V_165 ;
V_165 = F_142 ( V_256 , V_92 , V_215 ,
V_224 -> V_207 ) ;
if ( V_165 )
return F_89 ( V_165 ) ;
V_233 = F_162 ( V_224 -> V_8 , V_224 -> V_47 , V_224 -> V_126 ,
V_108 , V_256 ) ;
if ( ! V_233 )
return F_89 ( - V_76 ) ;
if ( ! F_160 ( V_233 , V_256 , V_92 ) ) {
F_76 ( V_233 ) ;
return F_89 ( - V_257 ) ;
}
return V_233 ;
}
static enum V_25 F_163 ( T_9 V_207 )
{
return ( F_135 ( V_207 ) >> 16 ) & 0xffff ;
}
static bool F_164 ( struct V_54 * V_55 ,
const struct V_63 * V_64 )
{
struct V_91 * V_79 = F_58 ( V_55 ) ;
V_74 V_258 ;
struct V_259 V_260 ;
if ( F_129 ( V_79 ) && ! V_55 -> V_261 )
return true ;
switch ( V_79 -> V_106 ) {
case V_187 :
V_258 = ( (struct V_188 * ) V_79 ) -> V_189 . V_190 ;
if ( F_38 ( V_64 ) != 4 )
return false ;
if ( ! F_129 ( V_79 ) &&
V_64 -> V_93 . V_211 . V_79 != V_258 )
return false ;
break;
case V_191 :
V_260 = ( (struct V_192 * ) V_79 ) -> V_193 ;
if ( F_38 ( V_64 ) != 6 )
return false ;
if ( ! F_129 ( V_79 ) &&
memcmp ( & V_64 -> V_93 . V_213 , & V_260 , sizeof( V_260 ) ) )
return false ;
break;
case V_107 :
return true ;
default:
return false ;
}
return true ;
}
static bool F_165 ( struct V_53 * V_8 , int V_9 )
{
enum V_262 V_263 = F_166 ( V_8 , V_9 ) ;
enum V_264 V_81 =
F_47 ( V_8 -> V_82 ) ;
return V_263 == V_265 && V_81 == V_266 ;
}
static bool F_167 ( const struct V_5 * V_6 )
{
struct V_53 * V_8 = V_6 -> V_8 ;
const int V_9 = V_6 -> V_9 ? : F_27 ( V_8 ) ;
return F_165 ( V_8 , V_9 ) ;
}
static bool F_168 ( const struct V_5 * V_6 ,
const struct V_67 * V_233 ,
T_3 V_9 )
{
const struct V_267 * V_79 = & V_6 -> V_78 . V_79 ;
if ( ! V_233 )
return ( ! V_6 -> V_9 || V_6 -> V_9 == V_9 ) &&
( V_79 -> V_92 . V_94 == V_107 ||
F_165 ( V_6 -> V_8 , V_9 ) ) ;
return ! V_79 -> V_80 . V_120 ||
( F_169 ( F_152 ( V_233 ) , V_79 -> V_80 . V_22 ) &&
V_79 -> V_80 . V_120 == V_233 -> V_241 ) ;
}
static struct V_54 * F_170 (
const struct V_36 * V_37 ,
const struct V_268 * V_183 ,
const struct V_214 * V_215 ,
const struct V_223 * V_224 ,
const struct V_67 * V_233 )
{
struct V_54 * V_55 , * V_269 ;
if ( ! V_37 )
return F_89 ( - V_48 ) ;
F_171 (id_priv, &bind_list->owners, node) {
if ( F_164 ( V_55 , V_215 -> V_20 ) ) {
if ( V_55 -> V_6 . V_8 == V_183 -> V_8 &&
F_168 ( & V_55 -> V_6 , V_233 , V_224 -> V_47 ) )
return V_55 ;
F_23 (id_priv_dev,
&id_priv->listen_list,
listen_list) {
if ( V_269 -> V_6 . V_8 == V_183 -> V_8 &&
F_168 ( & V_269 -> V_6 , V_233 , V_224 -> V_47 ) )
return V_269 ;
}
}
}
return F_89 ( - V_48 ) ;
}
static struct V_54 * F_172 ( struct V_268 * V_183 ,
struct V_214 * V_215 ,
struct V_67 * * V_233 )
{
struct V_223 V_224 ;
struct V_36 * V_37 ;
struct V_54 * V_55 ;
int V_165 ;
V_165 = F_144 ( V_215 , & V_224 ) ;
if ( V_165 )
return F_89 ( V_165 ) ;
* V_233 = F_161 ( V_215 , & V_224 ) ;
if ( F_104 ( * V_233 ) ) {
if ( F_105 ( * V_233 ) == - V_218 ) {
* V_233 = NULL ;
} else if ( F_165 ( V_224 . V_8 , V_224 . V_47 ) ) {
* V_233 = NULL ;
} else {
return F_173 ( * V_233 ) ;
}
}
V_37 = F_15 ( * V_233 ? F_152 ( * V_233 ) : & V_111 ,
F_163 ( V_224 . V_207 ) ,
F_141 ( V_224 . V_207 ) ) ;
V_55 = F_170 ( V_37 , V_183 , V_215 , & V_224 , * V_233 ) ;
if ( F_104 ( V_55 ) && * V_233 ) {
F_76 ( * V_233 ) ;
* V_233 = NULL ;
}
return V_55 ;
}
static inline int F_174 ( struct V_54 * V_55 )
{
return F_60 ( V_55 ) == V_107 ? 0 : sizeof( struct V_63 ) ;
}
static void F_175 ( struct V_54 * V_55 )
{
if ( F_176 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ) ) {
if ( V_55 -> V_270 )
F_177 ( V_55 -> V_271 , V_55 -> V_270 ) ;
}
}
static void F_178 ( struct V_54 * V_55 )
{
struct V_54 * V_272 ;
F_22 ( & V_46 ) ;
F_57 ( & V_55 -> V_83 ) ;
while ( ! F_179 ( & V_55 -> V_145 ) ) {
V_272 = F_180 ( V_55 -> V_145 . V_273 ,
struct V_54 , V_145 ) ;
F_181 ( & V_272 -> V_83 ) ;
F_57 ( & V_272 -> V_145 ) ;
F_24 ( & V_46 ) ;
F_182 ( & V_272 -> V_6 ) ;
F_22 ( & V_46 ) ;
}
F_24 ( & V_46 ) ;
}
static void F_183 ( struct V_54 * V_55 ,
enum V_56 V_60 )
{
switch ( V_60 ) {
case V_274 :
F_184 ( & V_55 -> V_6 . V_78 . V_79 . V_80 ) ;
break;
case V_275 :
F_175 ( V_55 ) ;
break;
case V_276 :
if ( F_129 ( F_58 ( V_55 ) ) && ! V_55 -> V_41 )
F_178 ( V_55 ) ;
break;
default:
break;
}
}
static void F_185 ( struct V_54 * V_55 )
{
struct V_36 * V_37 = V_55 -> V_37 ;
struct V_22 * V_22 = V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ;
if ( ! V_37 )
return;
F_22 ( & V_46 ) ;
F_186 ( & V_55 -> V_277 ) ;
if ( F_187 ( & V_37 -> V_278 ) ) {
F_17 ( V_22 , V_37 -> V_26 , V_37 -> V_47 ) ;
F_55 ( V_37 ) ;
}
F_24 ( & V_46 ) ;
}
static void F_188 ( struct V_54 * V_55 )
{
struct V_86 * V_87 ;
while ( ! F_179 ( & V_55 -> V_146 ) ) {
V_87 = F_54 ( V_55 -> V_146 . V_273 ,
struct V_86 , V_83 ) ;
F_57 ( & V_87 -> V_83 ) ;
if ( F_189 ( V_55 -> V_41 -> V_8 ,
V_55 -> V_6 . V_9 ) ) {
F_190 ( V_87 -> V_89 . V_90 ) ;
F_55 ( V_87 ) ;
} else {
if ( V_87 -> V_279 ) {
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
F_191 ( & V_87 -> V_88 , F_53 ) ;
}
}
}
void F_182 ( struct V_5 * V_6 )
{
struct V_54 * V_55 ;
enum V_56 V_60 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
V_60 = F_37 ( V_55 , V_280 ) ;
F_183 ( V_55 , V_60 ) ;
F_22 ( & V_55 -> V_144 ) ;
F_24 ( & V_55 -> V_144 ) ;
if ( V_55 -> V_41 ) {
if ( F_117 ( V_55 -> V_6 . V_8 , 1 ) ) {
if ( V_55 -> V_183 . V_90 )
F_192 ( V_55 -> V_183 . V_90 ) ;
} else if ( F_119 ( V_55 -> V_6 . V_8 , 1 ) ) {
if ( V_55 -> V_183 . V_185 )
F_193 ( V_55 -> V_183 . V_185 ) ;
}
F_188 ( V_55 ) ;
F_56 ( V_55 ) ;
}
F_185 ( V_55 ) ;
F_86 ( V_55 ) ;
F_194 ( & V_55 -> V_57 ) ;
if ( V_55 -> V_281 )
F_86 ( V_55 -> V_6 . V_135 ) ;
F_55 ( V_55 -> V_6 . V_78 . V_282 ) ;
F_195 ( V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ) ;
F_55 ( V_55 ) ;
}
static int F_196 ( struct V_54 * V_55 )
{
int V_59 ;
V_59 = F_108 ( V_55 , NULL ) ;
if ( V_59 )
goto V_283;
V_59 = F_112 ( V_55 , NULL ) ;
if ( V_59 )
goto V_283;
V_59 = F_197 ( V_55 -> V_183 . V_90 , NULL , 0 ) ;
if ( V_59 )
goto V_283;
return 0 ;
V_283:
F_198 ( L_7 , V_59 ) ;
F_113 ( V_55 ) ;
F_199 ( V_55 -> V_183 . V_90 , V_10 ,
NULL , 0 , NULL , 0 ) ;
return V_59 ;
}
static void F_200 ( struct V_12 * V_2 ,
struct V_284 * V_285 ,
void * V_20 )
{
V_2 -> V_17 . V_18 . V_20 = V_20 ;
V_2 -> V_17 . V_18 . V_19 = V_286 ;
V_2 -> V_17 . V_18 . V_173 = V_285 -> V_173 ;
V_2 -> V_17 . V_18 . V_175 = V_285 -> V_175 ;
V_2 -> V_17 . V_18 . V_287 = V_285 -> V_287 ;
V_2 -> V_17 . V_18 . V_288 = V_285 -> V_288 ;
V_2 -> V_17 . V_18 . V_167 = V_285 -> V_167 ;
V_2 -> V_17 . V_18 . V_166 = V_285 -> V_289 ;
}
static int F_201 ( struct V_268 * V_183 , struct V_214 * V_215 )
{
struct V_54 * V_55 = V_183 -> V_135 ;
struct V_12 V_2 ;
int V_59 = 0 ;
F_22 ( & V_55 -> V_144 ) ;
if ( ( V_215 -> V_2 != V_290 &&
V_55 -> V_60 != V_291 ) ||
( V_215 -> V_2 == V_290 &&
V_55 -> V_60 != V_292 ) )
goto V_121;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_215 -> V_2 ) {
case V_293 :
case V_294 :
V_2 . V_2 = V_295 ;
V_2 . V_16 = - V_296 ;
break;
case V_297 :
if ( F_33 ( V_55 , V_291 ) &&
( V_55 -> V_6 . V_137 != V_164 ) )
F_202 ( V_183 , V_298 , NULL , 0 ) ;
if ( V_55 -> V_6 . V_149 ) {
V_2 . V_16 = F_196 ( V_55 ) ;
V_2 . V_2 = V_2 . V_16 ? V_299 :
V_300 ;
} else {
V_2 . V_2 = V_301 ;
}
F_200 ( & V_2 , & V_215 -> V_17 . V_302 ,
V_215 -> V_20 ) ;
break;
case V_303 :
case V_304 :
V_2 . V_2 = V_300 ;
break;
case V_305 :
V_2 . V_16 = - V_296 ;
case V_306 :
case V_307 :
if ( ! F_36 ( V_55 , V_291 ,
V_292 ) )
goto V_121;
V_2 . V_2 = V_308 ;
break;
case V_290 :
V_2 . V_2 = V_309 ;
break;
case V_310 :
goto V_121;
case V_311 :
F_198 ( L_8 , F_3 ( & V_55 -> V_6 ,
V_215 -> V_17 . V_312 . V_7 ) ) ;
F_113 ( V_55 ) ;
V_2 . V_16 = V_215 -> V_17 . V_312 . V_7 ;
V_2 . V_2 = V_313 ;
V_2 . V_17 . V_18 . V_20 = V_215 -> V_20 ;
V_2 . V_17 . V_18 . V_19 = V_314 ;
break;
default:
F_203 ( L_9 ,
V_215 -> V_2 ) ;
goto V_121;
}
V_59 = V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_2 ) ;
if ( V_59 ) {
V_55 -> V_183 . V_90 = NULL ;
F_37 ( V_55 , V_280 ) ;
F_24 ( & V_55 -> V_144 ) ;
F_182 ( & V_55 -> V_6 ) ;
return V_59 ;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
return V_59 ;
}
static struct V_54 * F_204 ( struct V_5 * V_200 ,
struct V_214 * V_215 ,
struct V_67 * V_233 )
{
struct V_54 * V_55 ;
struct V_5 * V_6 ;
struct V_315 * V_246 ;
const T_10 V_94 = V_200 -> V_78 . V_79 . V_92 . V_94 ;
struct V_201 * V_202 = V_215 -> V_17 . V_220 . V_221 ;
const T_9 V_207 =
V_215 -> V_17 . V_220 . V_221 -> V_207 ;
int V_59 ;
V_6 = F_87 ( V_200 -> V_78 . V_79 . V_80 . V_22 ,
V_200 -> V_134 , V_200 -> V_135 ,
V_200 -> V_26 , V_215 -> V_17 . V_220 . V_137 ) ;
if ( F_104 ( V_6 ) )
return NULL ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( F_143 ( (struct V_91 * ) & V_6 -> V_78 . V_79 . V_92 ,
(struct V_91 * ) & V_6 -> V_78 . V_79 . V_93 ,
V_200 , V_215 , V_94 , V_207 ) )
goto V_165;
V_246 = & V_6 -> V_78 ;
V_246 -> V_316 = V_215 -> V_17 . V_220 . V_317 ? 2 : 1 ;
V_246 -> V_282 = F_205 ( sizeof * V_246 -> V_282 * V_246 -> V_316 ,
V_39 ) ;
if ( ! V_246 -> V_282 )
goto V_165;
V_246 -> V_282 [ 0 ] = * V_202 ;
if ( V_246 -> V_316 == 2 )
V_246 -> V_282 [ 1 ] = * V_215 -> V_17 . V_220 . V_317 ;
if ( V_233 ) {
V_59 = F_206 ( & V_246 -> V_79 . V_80 , V_233 , NULL ) ;
if ( V_59 )
goto V_165;
} else {
if ( ! F_167 ( V_200 ) &&
F_129 ( F_58 ( V_55 ) ) ) {
V_246 -> V_79 . V_80 . V_102 = V_103 ;
F_66 ( & V_246 -> V_79 . V_80 , & V_246 -> V_282 [ 0 ] . V_124 ) ;
F_67 ( & V_246 -> V_79 . V_80 , F_145 ( V_246 -> V_282 [ 0 ] . V_126 ) ) ;
} else if ( ! F_129 ( F_58 ( V_55 ) ) ) {
V_59 = F_69 ( F_58 ( V_55 ) , & V_246 -> V_79 . V_80 ) ;
if ( V_59 )
goto V_165;
}
}
F_207 ( & V_246 -> V_79 . V_80 , & V_246 -> V_282 [ 0 ] . V_125 ) ;
V_55 -> V_60 = V_291 ;
return V_55 ;
V_165:
F_182 ( V_6 ) ;
return NULL ;
}
static struct V_54 * F_208 ( struct V_5 * V_200 ,
struct V_214 * V_215 ,
struct V_67 * V_233 )
{
struct V_54 * V_55 ;
struct V_5 * V_6 ;
const T_10 V_94 = V_200 -> V_78 . V_79 . V_92 . V_94 ;
struct V_22 * V_22 = V_200 -> V_78 . V_79 . V_80 . V_22 ;
int V_59 ;
V_6 = F_87 ( V_22 , V_200 -> V_134 , V_200 -> V_135 ,
V_200 -> V_26 , V_164 ) ;
if ( F_104 ( V_6 ) )
return NULL ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( F_143 ( (struct V_91 * ) & V_6 -> V_78 . V_79 . V_92 ,
(struct V_91 * ) & V_6 -> V_78 . V_79 . V_93 ,
V_200 , V_215 , V_94 ,
V_215 -> V_17 . V_229 . V_207 ) )
goto V_165;
if ( V_233 ) {
V_59 = F_206 ( & V_6 -> V_78 . V_79 . V_80 , V_233 , NULL ) ;
if ( V_59 )
goto V_165;
} else {
if ( ! F_129 ( F_58 ( V_55 ) ) ) {
V_59 = F_69 ( F_58 ( V_55 ) ,
& V_6 -> V_78 . V_79 . V_80 ) ;
if ( V_59 )
goto V_165;
}
}
V_55 -> V_60 = V_291 ;
return V_55 ;
V_165:
F_182 ( V_6 ) ;
return NULL ;
}
static void F_209 ( struct V_12 * V_2 ,
struct V_225 * V_318 ,
void * V_20 , int V_319 )
{
V_2 -> V_17 . V_18 . V_20 = V_20 + V_319 ;
V_2 -> V_17 . V_18 . V_19 = V_320 - V_319 ;
V_2 -> V_17 . V_18 . V_173 = V_318 -> V_173 ;
V_2 -> V_17 . V_18 . V_175 = V_318 -> V_175 ;
V_2 -> V_17 . V_18 . V_287 = V_318 -> V_287 ;
V_2 -> V_17 . V_18 . V_321 = V_318 -> V_321 ;
V_2 -> V_17 . V_18 . V_288 = V_318 -> V_288 ;
V_2 -> V_17 . V_18 . V_167 = V_318 -> V_167 ;
V_2 -> V_17 . V_18 . V_166 = V_318 -> V_289 ;
}
static int F_210 ( struct V_5 * V_6 , struct V_214 * V_215 )
{
return ( ( ( V_215 -> V_2 == V_219 ) &&
( V_215 -> V_17 . V_220 . V_137 == V_6 -> V_137 ) ) ||
( ( V_215 -> V_2 == V_222 ) &&
( V_6 -> V_137 == V_164 ) ) ||
( ! V_6 -> V_137 ) ) ;
}
static int F_211 ( struct V_268 * V_183 , struct V_214 * V_215 )
{
struct V_54 * V_200 , * V_322 = NULL ;
struct V_12 V_2 ;
struct V_67 * V_233 ;
int V_319 , V_59 ;
V_200 = F_172 ( V_183 , V_215 , & V_233 ) ;
if ( F_104 ( V_200 ) )
return F_105 ( V_200 ) ;
if ( ! F_210 ( & V_200 -> V_6 , V_215 ) ) {
V_59 = - V_48 ;
goto V_323;
}
F_22 ( & V_200 -> V_144 ) ;
if ( V_200 -> V_60 != V_276 ) {
V_59 = - V_324 ;
goto V_325;
}
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_319 = F_174 ( V_200 ) ;
V_2 . V_2 = V_326 ;
if ( V_215 -> V_2 == V_222 ) {
V_322 = F_208 ( & V_200 -> V_6 , V_215 , V_233 ) ;
V_2 . V_17 . V_327 . V_20 = V_215 -> V_20 + V_319 ;
V_2 . V_17 . V_327 . V_19 =
V_328 - V_319 ;
} else {
V_322 = F_204 ( & V_200 -> V_6 , V_215 , V_233 ) ;
F_209 ( & V_2 , & V_215 -> V_17 . V_220 ,
V_215 -> V_20 , V_319 ) ;
}
if ( ! V_322 ) {
V_59 = - V_138 ;
goto V_325;
}
F_212 ( & V_322 -> V_144 , V_329 ) ;
V_59 = F_78 ( V_322 , V_200 ) ;
if ( V_59 )
goto V_330;
V_322 -> V_183 . V_90 = V_183 ;
V_183 -> V_135 = V_322 ;
V_183 -> V_331 = F_201 ;
F_20 ( & V_322 -> V_42 ) ;
V_59 = V_322 -> V_6 . V_134 ( & V_322 -> V_6 , & V_2 ) ;
if ( V_59 )
goto V_332;
F_22 ( & V_46 ) ;
if ( F_33 ( V_322 , V_291 ) &&
( V_322 -> V_6 . V_137 != V_164 ) )
F_202 ( V_183 , V_298 , NULL , 0 ) ;
F_24 ( & V_46 ) ;
F_24 ( & V_322 -> V_144 ) ;
F_24 ( & V_200 -> V_144 ) ;
F_86 ( V_322 ) ;
if ( V_233 )
F_76 ( V_233 ) ;
return 0 ;
V_332:
F_86 ( V_322 ) ;
V_322 -> V_183 . V_90 = NULL ;
V_330:
F_37 ( V_322 , V_280 ) ;
F_24 ( & V_322 -> V_144 ) ;
V_325:
F_24 ( & V_200 -> V_144 ) ;
if ( V_322 )
F_182 ( & V_322 -> V_6 ) ;
V_323:
if ( V_233 )
F_76 ( V_233 ) ;
return V_59 ;
}
T_9 F_213 ( struct V_5 * V_6 , struct V_91 * V_79 )
{
if ( V_79 -> V_106 == V_107 )
return ( (struct V_99 * ) V_79 ) -> V_198 ;
return F_138 ( ( ( V_333 ) V_6 -> V_26 << 16 ) + F_145 ( F_133 ( V_79 ) ) ) ;
}
static int F_214 ( struct V_334 * V_335 , struct V_336 * V_337 )
{
struct V_54 * V_55 = V_335 -> V_135 ;
struct V_12 V_2 ;
int V_59 = 0 ;
struct V_91 * V_338 = (struct V_91 * ) & V_337 -> V_339 ;
struct V_91 * V_340 = (struct V_91 * ) & V_337 -> V_341 ;
F_22 ( & V_55 -> V_144 ) ;
if ( V_55 -> V_60 != V_291 )
goto V_121;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_337 -> V_2 ) {
case V_342 :
V_2 . V_2 = V_308 ;
break;
case V_343 :
memcpy ( F_58 ( V_55 ) , V_338 ,
F_215 ( V_338 ) ) ;
memcpy ( F_59 ( V_55 ) , V_340 ,
F_215 ( V_340 ) ) ;
switch ( V_337 -> V_16 ) {
case 0 :
V_2 . V_2 = V_300 ;
V_2 . V_17 . V_18 . V_175 = V_337 -> V_344 ;
V_2 . V_17 . V_18 . V_173 = V_337 -> V_345 ;
break;
case - V_346 :
case - V_11 :
V_2 . V_2 = V_313 ;
break;
case - V_296 :
V_2 . V_2 = V_295 ;
break;
default:
V_2 . V_2 = V_299 ;
break;
}
break;
case V_347 :
V_2 . V_2 = V_300 ;
V_2 . V_17 . V_18 . V_175 = V_337 -> V_344 ;
V_2 . V_17 . V_18 . V_173 = V_337 -> V_345 ;
break;
default:
F_111 ( 1 ) ;
}
V_2 . V_16 = V_337 -> V_16 ;
V_2 . V_17 . V_18 . V_20 = V_337 -> V_20 ;
V_2 . V_17 . V_18 . V_19 = V_337 -> V_19 ;
V_59 = V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_2 ) ;
if ( V_59 ) {
V_55 -> V_183 . V_185 = NULL ;
F_37 ( V_55 , V_280 ) ;
F_24 ( & V_55 -> V_144 ) ;
F_182 ( & V_55 -> V_6 ) ;
return V_59 ;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
return V_59 ;
}
static int F_216 ( struct V_334 * V_183 ,
struct V_336 * V_337 )
{
struct V_5 * V_348 ;
struct V_54 * V_200 , * V_322 ;
struct V_12 V_2 ;
int V_59 = - V_324 ;
struct V_91 * V_338 = (struct V_91 * ) & V_337 -> V_339 ;
struct V_91 * V_340 = (struct V_91 * ) & V_337 -> V_341 ;
V_200 = V_183 -> V_135 ;
F_22 ( & V_200 -> V_144 ) ;
if ( V_200 -> V_60 != V_276 )
goto V_121;
V_348 = F_87 ( V_200 -> V_6 . V_78 . V_79 . V_80 . V_22 ,
V_200 -> V_6 . V_134 ,
V_200 -> V_6 . V_135 ,
V_28 , V_349 ) ;
if ( F_104 ( V_348 ) ) {
V_59 = - V_138 ;
goto V_121;
}
V_322 = F_54 ( V_348 , struct V_54 , V_6 ) ;
F_212 ( & V_322 -> V_144 , V_329 ) ;
V_322 -> V_60 = V_291 ;
V_59 = F_70 ( V_338 , & V_322 -> V_6 . V_78 . V_79 . V_80 , NULL ) ;
if ( V_59 ) {
F_24 ( & V_322 -> V_144 ) ;
F_182 ( V_348 ) ;
goto V_121;
}
V_59 = F_78 ( V_322 , V_200 ) ;
if ( V_59 ) {
F_24 ( & V_322 -> V_144 ) ;
F_182 ( V_348 ) ;
goto V_121;
}
V_322 -> V_183 . V_185 = V_183 ;
V_183 -> V_135 = V_322 ;
V_183 -> V_331 = F_214 ;
memcpy ( F_58 ( V_322 ) , V_338 , F_215 ( V_338 ) ) ;
memcpy ( F_59 ( V_322 ) , V_340 , F_215 ( V_340 ) ) ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_326 ;
V_2 . V_17 . V_18 . V_20 = V_337 -> V_20 ;
V_2 . V_17 . V_18 . V_19 = V_337 -> V_19 ;
V_2 . V_17 . V_18 . V_175 = V_337 -> V_344 ;
V_2 . V_17 . V_18 . V_173 = V_337 -> V_345 ;
F_20 ( & V_322 -> V_42 ) ;
V_59 = V_322 -> V_6 . V_134 ( & V_322 -> V_6 , & V_2 ) ;
if ( V_59 ) {
V_322 -> V_183 . V_185 = NULL ;
F_37 ( V_322 , V_280 ) ;
F_24 ( & V_322 -> V_144 ) ;
F_86 ( V_322 ) ;
F_182 ( & V_322 -> V_6 ) ;
goto V_121;
}
F_24 ( & V_322 -> V_144 ) ;
F_86 ( V_322 ) ;
V_121:
F_24 ( & V_200 -> V_144 ) ;
return V_59 ;
}
static int F_217 ( struct V_54 * V_55 )
{
struct V_91 * V_79 ;
struct V_268 * V_6 ;
T_9 V_350 ;
V_79 = F_58 ( V_55 ) ;
V_350 = F_213 ( & V_55 -> V_6 , V_79 ) ;
V_6 = F_218 ( V_55 -> V_6 . V_8 , F_211 , V_350 ) ;
if ( F_104 ( V_6 ) )
return F_105 ( V_6 ) ;
V_55 -> V_183 . V_90 = V_6 ;
return 0 ;
}
static int F_219 ( struct V_54 * V_55 , int V_351 )
{
int V_59 ;
struct V_334 * V_6 ;
V_6 = F_220 ( V_55 -> V_6 . V_8 ,
F_216 ,
V_55 ) ;
if ( F_104 ( V_6 ) )
return F_105 ( V_6 ) ;
V_6 -> V_352 = V_55 -> V_352 ;
V_55 -> V_183 . V_185 = V_6 ;
memcpy ( & V_55 -> V_183 . V_185 -> V_339 , F_58 ( V_55 ) ,
F_215 ( F_58 ( V_55 ) ) ) ;
V_59 = F_221 ( V_55 -> V_183 . V_185 , V_351 ) ;
if ( V_59 ) {
F_193 ( V_55 -> V_183 . V_185 ) ;
V_55 -> V_183 . V_185 = NULL ;
}
return V_59 ;
}
static int F_222 ( struct V_5 * V_6 ,
struct V_12 * V_2 )
{
struct V_54 * V_55 = V_6 -> V_135 ;
V_6 -> V_135 = V_55 -> V_6 . V_135 ;
V_6 -> V_134 = V_55 -> V_6 . V_134 ;
return V_55 -> V_6 . V_134 ( V_6 , V_2 ) ;
}
static void F_223 ( struct V_54 * V_55 ,
struct V_40 * V_41 )
{
struct V_54 * V_272 ;
struct V_5 * V_6 ;
struct V_22 * V_22 = V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ;
int V_59 ;
if ( F_60 ( V_55 ) == V_107 && ! F_117 ( V_41 -> V_8 , 1 ) )
return;
V_6 = F_87 ( V_22 , F_222 , V_55 , V_55 -> V_6 . V_26 ,
V_55 -> V_6 . V_137 ) ;
if ( F_104 ( V_6 ) )
return;
V_272 = F_54 ( V_6 , struct V_54 , V_6 ) ;
V_272 -> V_60 = V_353 ;
memcpy ( F_58 ( V_272 ) , F_58 ( V_55 ) ,
F_215 ( F_58 ( V_55 ) ) ) ;
F_46 ( V_272 , V_41 ) ;
F_48 ( & V_272 -> V_145 , & V_55 -> V_145 ) ;
F_20 ( & V_55 -> V_42 ) ;
V_272 -> V_281 = 1 ;
V_272 -> V_261 = V_55 -> V_261 ;
V_59 = F_224 ( V_6 , V_55 -> V_351 ) ;
if ( V_59 )
F_225 ( L_10 ,
V_59 , V_41 -> V_8 -> V_354 ) ;
}
static void F_226 ( struct V_54 * V_55 )
{
struct V_40 * V_41 ;
F_22 ( & V_46 ) ;
F_48 ( & V_55 -> V_83 , & V_355 ) ;
F_23 (cma_dev, &dev_list, list)
F_223 ( V_55 , V_41 ) ;
F_24 ( & V_46 ) ;
}
void F_227 ( struct V_5 * V_6 , int V_352 )
{
struct V_54 * V_55 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
V_55 -> V_352 = ( T_3 ) V_352 ;
V_55 -> V_142 = true ;
}
static void F_228 ( int V_16 , struct V_201 * V_282 ,
void * V_135 )
{
struct V_356 * V_357 = V_135 ;
struct V_315 * V_78 ;
V_78 = & V_357 -> V_6 -> V_6 . V_78 ;
if ( ! V_16 ) {
V_78 -> V_316 = 1 ;
* V_78 -> V_282 = * V_282 ;
} else {
V_357 -> V_358 = V_275 ;
V_357 -> V_359 = V_360 ;
V_357 -> V_2 . V_2 = V_361 ;
V_357 -> V_2 . V_16 = V_16 ;
F_198 ( L_11 ,
V_16 ) ;
}
F_229 ( V_362 , & V_357 -> V_357 ) ;
}
static int F_230 ( struct V_54 * V_55 , int V_363 ,
struct V_356 * V_357 )
{
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
struct V_201 V_282 ;
T_11 V_364 ;
struct V_192 * V_365 ;
struct V_99 * V_100 ;
memset ( & V_282 , 0 , sizeof V_282 ) ;
if ( F_231 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ) )
V_282 . V_366 = V_367 ;
else
V_282 . V_366 = V_368 ;
F_232 ( V_80 , & V_282 . V_124 ) ;
F_233 ( V_80 , & V_282 . V_125 ) ;
V_282 . V_126 = F_234 ( F_116 ( V_80 ) ) ;
V_282 . V_369 = 1 ;
V_282 . V_370 = 1 ;
V_282 . V_207 = F_213 ( & V_55 -> V_6 ,
F_59 ( V_55 ) ) ;
V_364 = V_371 | V_372 |
V_373 | V_374 |
V_375 | V_376 ;
switch ( F_60 ( V_55 ) ) {
case V_187 :
V_282 . V_377 = F_234 ( ( T_6 ) V_55 -> V_352 ) ;
V_364 |= V_378 ;
break;
case V_191 :
V_365 = (struct V_192 * ) F_58 ( V_55 ) ;
V_282 . V_379 = ( T_3 ) ( F_64 ( V_365 -> V_380 ) >> 20 ) ;
V_364 |= V_381 ;
break;
case V_107 :
V_100 = (struct V_99 * ) F_58 ( V_55 ) ;
V_282 . V_379 = ( T_3 ) ( F_64 ( V_100 -> V_205 ) >> 20 ) ;
V_364 |= V_381 ;
break;
}
V_55 -> V_271 = F_235 ( & V_382 , V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 , & V_282 ,
V_364 , V_363 ,
V_39 , F_228 ,
V_357 , & V_55 -> V_270 ) ;
return ( V_55 -> V_271 < 0 ) ? V_55 -> V_271 : 0 ;
}
static void F_236 ( struct V_383 * V_384 )
{
struct V_356 * V_357 = F_54 ( V_384 , struct V_356 , V_357 ) ;
struct V_54 * V_55 = V_357 -> V_6 ;
int V_385 = 0 ;
F_22 ( & V_55 -> V_144 ) ;
if ( ! F_36 ( V_55 , V_357 -> V_358 , V_357 -> V_359 ) )
goto V_121;
if ( V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_357 -> V_2 ) ) {
F_37 ( V_55 , V_280 ) ;
V_385 = 1 ;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
F_86 ( V_55 ) ;
if ( V_385 )
F_182 ( & V_55 -> V_6 ) ;
F_55 ( V_357 ) ;
}
static void F_237 ( struct V_383 * V_384 )
{
struct V_386 * V_357 = F_54 ( V_384 , struct V_386 , V_357 ) ;
struct V_54 * V_55 = V_357 -> V_6 ;
int V_385 = 0 ;
F_22 ( & V_55 -> V_144 ) ;
if ( V_55 -> V_60 == V_280 ||
V_55 -> V_60 == V_387 )
goto V_121;
if ( V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_357 -> V_2 ) ) {
F_37 ( V_55 , V_280 ) ;
V_385 = 1 ;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
F_86 ( V_55 ) ;
if ( V_385 )
F_182 ( & V_55 -> V_6 ) ;
F_55 ( V_357 ) ;
}
static int F_238 ( struct V_54 * V_55 , int V_363 )
{
struct V_315 * V_78 = & V_55 -> V_6 . V_78 ;
struct V_356 * V_357 ;
int V_59 ;
V_357 = F_88 ( sizeof *V_357 , V_39 ) ;
if ( ! V_357 )
return - V_138 ;
V_357 -> V_6 = V_55 ;
F_239 ( & V_357 -> V_357 , F_236 ) ;
V_357 -> V_358 = V_275 ;
V_357 -> V_359 = V_388 ;
V_357 -> V_2 . V_2 = V_389 ;
V_78 -> V_282 = F_205 ( sizeof * V_78 -> V_282 , V_39 ) ;
if ( ! V_78 -> V_282 ) {
V_59 = - V_138 ;
goto V_325;
}
V_59 = F_230 ( V_55 , V_363 , V_357 ) ;
if ( V_59 )
goto V_330;
return 0 ;
V_330:
F_55 ( V_78 -> V_282 ) ;
V_78 -> V_282 = NULL ;
V_325:
F_55 ( V_357 ) ;
return V_59 ;
}
int F_240 ( struct V_5 * V_6 ,
struct V_201 * V_282 , int V_316 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_36 ( V_55 , V_360 ,
V_388 ) )
return - V_48 ;
V_6 -> V_78 . V_282 = F_241 ( V_282 , sizeof *V_282 * V_316 ,
V_39 ) ;
if ( ! V_6 -> V_78 . V_282 ) {
V_59 = - V_138 ;
goto V_165;
}
V_6 -> V_78 . V_316 = V_316 ;
return 0 ;
V_165:
F_36 ( V_55 , V_388 , V_360 ) ;
return V_59 ;
}
static int F_242 ( struct V_54 * V_55 , int V_363 )
{
struct V_356 * V_357 ;
V_357 = F_88 ( sizeof *V_357 , V_39 ) ;
if ( ! V_357 )
return - V_138 ;
V_357 -> V_6 = V_55 ;
F_239 ( & V_357 -> V_357 , F_236 ) ;
V_357 -> V_358 = V_275 ;
V_357 -> V_359 = V_388 ;
V_357 -> V_2 . V_2 = V_389 ;
F_229 ( V_362 , & V_357 -> V_357 ) ;
return 0 ;
}
static int F_243 ( struct V_67 * V_68 , int V_352 )
{
int V_390 ;
struct V_67 * V_248 ;
V_390 = F_244 ( V_352 ) ;
V_248 = F_245 ( V_68 ) ? F_246 ( V_68 ) : V_68 ;
if ( V_248 -> V_391 )
return F_247 ( V_248 , V_390 ) ;
#if F_156 ( V_392 )
if ( F_245 ( V_68 ) )
return ( F_248 ( V_68 , V_390 ) &
V_393 ) >> V_394 ;
#endif
return 0 ;
}
static enum V_50 F_249 ( enum V_395 V_396 ,
unsigned long V_51 ,
enum V_50 V_397 )
{
if ( ( V_396 == V_398 ||
V_396 == V_399 ) &&
F_250 ( V_400 , & V_51 ) )
return V_400 ;
return V_397 ;
}
static int F_251 ( struct V_54 * V_55 )
{
struct V_315 * V_78 = & V_55 -> V_6 . V_78 ;
struct V_267 * V_79 = & V_78 -> V_79 ;
struct V_356 * V_357 ;
int V_59 ;
struct V_67 * V_68 = NULL ;
enum V_50 V_77 = V_115 ;
T_3 V_52 = V_55 -> V_41 -> V_52 [ V_55 -> V_6 . V_9 -
F_27 ( V_55 -> V_41 -> V_8 ) ] ;
T_3 V_352 = V_55 -> V_142 ? V_55 -> V_352 : V_52 ;
V_357 = F_88 ( sizeof *V_357 , V_39 ) ;
if ( ! V_357 )
return - V_138 ;
V_357 -> V_6 = V_55 ;
F_239 ( & V_357 -> V_357 , F_236 ) ;
V_78 -> V_282 = F_88 ( sizeof * V_78 -> V_282 , V_39 ) ;
if ( ! V_78 -> V_282 ) {
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
V_51 = F_29 ( V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 ) ;
V_77 = F_249 ( V_79 -> V_80 . V_401 ,
V_51 ,
V_55 -> V_77 ) ;
V_78 -> V_282 -> V_366 =
F_252 ( V_77 ) ;
F_253 ( V_78 -> V_282 , & V_111 ) ;
F_254 ( V_78 -> V_282 , V_68 -> V_241 ) ;
}
if ( ! V_68 ) {
V_59 = - V_76 ;
goto V_330;
}
F_255 ( V_78 -> V_282 , V_79 -> V_80 . V_402 ) ;
F_79 ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_92 ,
& V_78 -> V_282 -> V_124 ) ;
F_79 ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_93 ,
& V_78 -> V_282 -> V_125 ) ;
if ( V_77 < F_256 ( V_79 -> V_80 . V_401 ) )
V_77 = F_256 ( V_79 -> V_80 . V_401 ) ;
V_78 -> V_282 -> V_366 = F_252 ( V_77 ) ;
if ( ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_93 ) -> V_106 != V_107 )
V_78 -> V_282 -> V_403 = V_79 -> V_80 . V_404 ;
else
V_78 -> V_282 -> V_403 = 1 ;
V_78 -> V_282 -> V_370 = 1 ;
V_78 -> V_282 -> V_126 = F_234 ( 0xffff ) ;
V_78 -> V_282 -> V_405 = V_406 ;
V_78 -> V_282 -> V_407 = F_243 ( V_68 , V_352 ) ;
V_78 -> V_282 -> V_379 = V_352 ;
V_78 -> V_282 -> V_408 = F_257 ( V_68 -> V_408 ) ;
V_78 -> V_282 -> V_409 = V_406 ;
V_78 -> V_282 -> V_410 = F_258 ( V_68 ) ;
F_76 ( V_68 ) ;
V_78 -> V_282 -> V_411 = V_406 ;
V_78 -> V_282 -> V_412 = V_413 ;
if ( ! V_78 -> V_282 -> V_408 ) {
V_59 = - V_48 ;
goto V_330;
}
V_357 -> V_358 = V_275 ;
V_357 -> V_359 = V_388 ;
V_357 -> V_2 . V_2 = V_389 ;
V_357 -> V_2 . V_16 = 0 ;
F_229 ( V_362 , & V_357 -> V_357 ) ;
return 0 ;
V_330:
F_55 ( V_78 -> V_282 ) ;
V_78 -> V_282 = NULL ;
V_325:
F_55 ( V_357 ) ;
return V_59 ;
}
int F_259 ( struct V_5 * V_6 , int V_363 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_36 ( V_55 , V_360 , V_275 ) )
return - V_48 ;
F_20 ( & V_55 -> V_42 ) ;
if ( F_176 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_238 ( V_55 , V_363 ) ;
else if ( F_73 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_251 ( V_55 ) ;
else if ( F_6 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_242 ( V_55 , V_363 ) ;
else
V_59 = - V_186 ;
if ( V_59 )
goto V_165;
return 0 ;
V_165:
F_36 ( V_55 , V_275 , V_360 ) ;
F_86 ( V_55 ) ;
return V_59 ;
}
static void F_260 ( struct V_91 * V_79 )
{
switch ( V_79 -> V_106 ) {
case V_187 :
( (struct V_188 * ) V_79 ) -> V_189 . V_190 = F_261 ( V_414 ) ;
break;
case V_191 :
F_262 ( & ( (struct V_192 * ) V_79 ) -> V_193 ,
0 , 0 , 0 , F_261 ( 1 ) ) ;
break;
default:
F_263 ( & ( (struct V_99 * ) V_79 ) -> V_104 ,
0 , 0 , 0 , F_261 ( 1 ) ) ;
break;
}
}
static int F_264 ( struct V_54 * V_55 )
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
! F_117 ( V_123 -> V_8 , 1 ) )
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
V_59 = F_265 ( V_41 -> V_8 , V_15 , 0 , & V_126 ) ;
if ( V_59 )
goto V_121;
V_55 -> V_6 . V_78 . V_79 . V_80 . V_102 =
( F_72 ( V_41 -> V_8 , V_15 ) ) ?
V_103 : V_110 ;
F_66 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , & V_108 ) ;
F_67 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , V_126 ) ;
V_55 -> V_6 . V_9 = V_15 ;
F_49 ( V_55 , V_41 ) ;
F_260 ( F_58 ( V_55 ) ) ;
V_121:
F_24 ( & V_46 ) ;
return V_59 ;
}
static void F_266 ( int V_16 , struct V_91 * V_92 ,
struct V_101 * V_80 , void * V_135 )
{
struct V_54 * V_55 = V_135 ;
struct V_12 V_2 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
F_22 ( & V_55 -> V_144 ) ;
if ( ! F_36 ( V_55 , V_274 ,
V_360 ) )
goto V_121;
memcpy ( F_58 ( V_55 ) , V_92 , F_215 ( V_92 ) ) ;
if ( ! V_16 && ! V_55 -> V_41 ) {
V_16 = F_78 ( V_55 , NULL ) ;
if ( V_16 )
F_198 ( L_12 ,
V_16 ) ;
} else {
F_198 ( L_13 , V_16 ) ;
}
if ( V_16 ) {
if ( ! F_36 ( V_55 , V_360 ,
V_353 ) )
goto V_121;
V_2 . V_2 = V_416 ;
V_2 . V_16 = V_16 ;
} else
V_2 . V_2 = V_417 ;
if ( V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_2 ) ) {
F_37 ( V_55 , V_280 ) ;
F_24 ( & V_55 -> V_144 ) ;
F_86 ( V_55 ) ;
F_182 ( & V_55 -> V_6 ) ;
return;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
F_86 ( V_55 ) ;
}
static int F_267 ( struct V_54 * V_55 )
{
struct V_356 * V_357 ;
union V_69 V_108 ;
int V_59 ;
V_357 = F_88 ( sizeof *V_357 , V_39 ) ;
if ( ! V_357 )
return - V_138 ;
if ( ! V_55 -> V_41 ) {
V_59 = F_264 ( V_55 ) ;
if ( V_59 )
goto V_165;
}
F_232 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , & V_108 ) ;
F_207 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , & V_108 ) ;
V_357 -> V_6 = V_55 ;
F_239 ( & V_357 -> V_357 , F_236 ) ;
V_357 -> V_358 = V_274 ;
V_357 -> V_359 = V_360 ;
V_357 -> V_2 . V_2 = V_417 ;
F_229 ( V_362 , & V_357 -> V_357 ) ;
return 0 ;
V_165:
F_55 ( V_357 ) ;
return V_59 ;
}
static int F_268 ( struct V_54 * V_55 )
{
struct V_356 * V_357 ;
int V_59 ;
V_357 = F_88 ( sizeof *V_357 , V_39 ) ;
if ( ! V_357 )
return - V_138 ;
if ( ! V_55 -> V_41 ) {
V_59 = F_81 ( V_55 ) ;
if ( V_59 )
goto V_165;
}
F_207 ( & V_55 -> V_6 . V_78 . V_79 . V_80 , (union V_69 * )
& ( ( (struct V_99 * ) & V_55 -> V_6 . V_78 . V_79 . V_93 ) -> V_104 ) ) ;
V_357 -> V_6 = V_55 ;
F_239 ( & V_357 -> V_357 , F_236 ) ;
V_357 -> V_358 = V_274 ;
V_357 -> V_359 = V_360 ;
V_357 -> V_2 . V_2 = V_417 ;
F_229 ( V_362 , & V_357 -> V_357 ) ;
return 0 ;
V_165:
F_55 ( V_357 ) ;
return V_59 ;
}
static int F_269 ( struct V_5 * V_6 , struct V_91 * V_92 ,
struct V_91 * V_93 )
{
if ( ! V_92 || ! V_92 -> V_106 ) {
V_92 = (struct V_91 * ) & V_6 -> V_78 . V_79 . V_92 ;
V_92 -> V_106 = V_93 -> V_106 ;
if ( F_156 ( V_242 ) &&
V_93 -> V_106 == V_191 ) {
struct V_192 * V_418 = (struct V_192 * ) V_92 ;
struct V_192 * V_419 = (struct V_192 * ) V_93 ;
V_418 -> V_420 = V_419 -> V_420 ;
if ( F_157 ( & V_419 -> V_193 ) & V_244 )
V_6 -> V_78 . V_79 . V_80 . V_120 = V_419 -> V_420 ;
} else if ( V_93 -> V_106 == V_107 ) {
( (struct V_99 * ) V_92 ) -> V_105 =
( (struct V_99 * ) V_93 ) -> V_105 ;
}
}
return F_270 ( V_6 , V_92 ) ;
}
int F_271 ( struct V_5 * V_6 , struct V_91 * V_92 ,
struct V_91 * V_93 , int V_363 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
memcpy ( F_59 ( V_55 ) , V_93 , F_215 ( V_93 ) ) ;
if ( V_55 -> V_60 == V_141 ) {
V_59 = F_269 ( V_6 , V_92 , V_93 ) ;
if ( V_59 ) {
memset ( F_59 ( V_55 ) , 0 , F_215 ( V_93 ) ) ;
return V_59 ;
}
}
if ( F_60 ( V_55 ) != V_93 -> V_106 ) {
memset ( F_59 ( V_55 ) , 0 , F_215 ( V_93 ) ) ;
return - V_48 ;
}
if ( ! F_36 ( V_55 , V_353 , V_274 ) ) {
memset ( F_59 ( V_55 ) , 0 , F_215 ( V_93 ) ) ;
return - V_48 ;
}
F_20 ( & V_55 -> V_42 ) ;
if ( F_129 ( V_93 ) ) {
V_59 = F_267 ( V_55 ) ;
} else {
if ( V_93 -> V_106 == V_107 ) {
V_59 = F_268 ( V_55 ) ;
} else {
V_59 = F_272 ( & V_421 , F_58 ( V_55 ) ,
V_93 , & V_6 -> V_78 . V_79 . V_80 ,
V_363 , F_266 , V_55 ) ;
}
}
if ( V_59 )
goto V_165;
return 0 ;
V_165:
F_36 ( V_55 , V_274 , V_353 ) ;
F_86 ( V_55 ) ;
return V_59 ;
}
int F_273 ( struct V_5 * V_6 , int V_422 )
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
int F_274 ( struct V_5 * V_6 , int V_261 )
{
struct V_54 * V_55 ;
unsigned long V_58 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
F_34 ( & V_55 -> V_46 , V_58 ) ;
if ( V_55 -> V_60 == V_141 || V_55 -> V_60 == V_353 ) {
V_55 -> V_424 |= ( 1 << V_425 ) ;
V_55 -> V_261 = V_261 ;
V_59 = 0 ;
} else {
V_59 = - V_48 ;
}
F_35 ( & V_55 -> V_46 , V_58 ) ;
return V_59 ;
}
static void F_275 ( struct V_36 * V_37 ,
struct V_54 * V_55 )
{
struct V_91 * V_79 ;
struct V_99 * V_100 ;
V_333 V_426 , V_427 ;
T_8 V_47 ;
V_79 = F_58 ( V_55 ) ;
V_47 = F_134 ( V_37 -> V_47 ) ;
switch ( V_79 -> V_106 ) {
case V_187 :
( (struct V_188 * ) V_79 ) -> V_196 = V_47 ;
break;
case V_191 :
( (struct V_192 * ) V_79 ) -> V_197 = V_47 ;
break;
case V_107 :
V_100 = (struct V_99 * ) V_79 ;
V_426 = F_135 ( V_100 -> V_198 ) ;
V_427 = F_135 ( V_100 -> V_199 ) ;
V_100 -> V_198 = F_138 ( ( V_426 & V_427 ) | ( V_333 ) F_68 ( V_47 ) ) ;
V_100 -> V_199 = F_138 ( ~ 0ULL ) ;
break;
}
V_55 -> V_37 = V_37 ;
F_276 ( & V_55 -> V_277 , & V_37 -> V_278 ) ;
}
static int F_277 ( enum V_25 V_26 ,
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
F_275 ( V_37 , V_55 ) ;
return 0 ;
V_165:
F_55 ( V_37 ) ;
return V_59 == - V_428 ? - V_429 : V_59 ;
}
static int F_278 ( struct V_36 * V_37 ,
struct V_54 * V_55 )
{
struct V_54 * V_430 ;
struct V_91 * V_234 = F_59 ( V_55 ) ;
struct V_91 * V_235 = F_58 ( V_55 ) ;
T_8 V_431 = F_133 ( V_234 ) ;
F_171 (cur_id, &bind_list->owners, node) {
struct V_91 * V_432 = F_59 ( V_430 ) ;
struct V_91 * V_433 = F_58 ( V_430 ) ;
T_8 V_434 = F_133 ( V_432 ) ;
if ( V_55 == V_430 )
continue;
if ( ! F_136 ( V_432 ) &&
( V_431 != V_434 ) )
continue;
if ( ! F_129 ( V_235 ) &&
! F_129 ( V_433 ) &&
F_130 ( V_235 , V_433 ) )
continue;
if ( ! F_129 ( V_432 ) &&
F_130 ( V_234 , V_432 ) )
continue;
return - V_429 ;
}
return 0 ;
}
static int F_279 ( enum V_25 V_26 ,
struct V_54 * V_55 )
{
static unsigned int V_435 ;
int V_436 , V_437 , V_438 ;
unsigned int V_439 ;
struct V_22 * V_22 = V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ;
F_280 ( V_22 , & V_436 , & V_437 ) ;
V_438 = ( V_437 - V_436 ) + 1 ;
V_439 = F_281 () % V_438 + V_436 ;
V_440:
if ( V_435 != V_439 ) {
struct V_36 * V_37 ;
int V_59 ;
V_37 = F_15 ( V_22 , V_26 , ( unsigned short ) V_439 ) ;
if ( ! V_37 ) {
V_59 = F_277 ( V_26 , V_55 , V_439 ) ;
} else {
V_59 = F_278 ( V_37 , V_55 ) ;
if ( ! V_59 )
F_275 ( V_37 , V_55 ) ;
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
static int F_282 ( struct V_36 * V_37 ,
struct V_54 * V_55 , T_12 V_423 )
{
struct V_54 * V_430 ;
struct V_91 * V_79 , * V_441 ;
V_79 = F_58 ( V_55 ) ;
F_171 (cur_id, &bind_list->owners, node) {
if ( V_55 == V_430 )
continue;
if ( ( V_430 -> V_60 != V_276 ) && V_423 &&
V_430 -> V_423 )
continue;
V_441 = F_58 ( V_430 ) ;
if ( V_55 -> V_261 && V_430 -> V_261 &&
( V_79 -> V_106 != V_441 -> V_106 ) )
continue;
if ( F_129 ( V_79 ) || F_129 ( V_441 ) )
return - V_429 ;
if ( ! F_130 ( V_79 , V_441 ) )
return - V_442 ;
}
return 0 ;
}
static int F_283 ( enum V_25 V_26 ,
struct V_54 * V_55 )
{
struct V_36 * V_37 ;
unsigned short V_38 ;
int V_59 ;
V_38 = F_68 ( F_133 ( F_58 ( V_55 ) ) ) ;
if ( V_38 < V_443 && ! F_284 ( V_444 ) )
return - V_445 ;
V_37 = F_15 ( V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 , V_26 , V_38 ) ;
if ( ! V_37 ) {
V_59 = F_277 ( V_26 , V_55 , V_38 ) ;
} else {
V_59 = F_282 ( V_37 , V_55 , V_55 -> V_423 ) ;
if ( ! V_59 )
F_275 ( V_37 , V_55 ) ;
}
return V_59 ;
}
static int F_285 ( struct V_54 * V_55 )
{
struct V_36 * V_37 = V_55 -> V_37 ;
int V_59 = 0 ;
F_22 ( & V_46 ) ;
if ( V_37 -> V_278 . V_446 -> V_273 )
V_59 = F_282 ( V_37 , V_55 , 0 ) ;
F_24 ( & V_46 ) ;
return V_59 ;
}
static enum V_25 F_286 (
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
static enum V_25 F_287 ( struct V_54 * V_55 )
{
enum V_25 V_26 = 0 ;
struct V_99 * V_100 ;
V_333 V_447 , V_427 , V_426 ;
V_100 = (struct V_99 * ) F_58 ( V_55 ) ;
V_427 = F_135 ( V_100 -> V_199 ) & V_448 ;
V_426 = F_135 ( V_100 -> V_198 ) & V_427 ;
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
V_100 -> V_198 = F_138 ( V_447 | F_68 ( F_133 ( (struct V_91 * ) V_100 ) ) ) ;
V_100 -> V_199 = F_138 ( V_448 |
F_135 ( V_100 -> V_199 ) ) ;
}
return V_26 ;
}
static int F_288 ( struct V_54 * V_55 )
{
enum V_25 V_26 ;
int V_59 ;
if ( F_60 ( V_55 ) != V_107 )
V_26 = F_286 ( V_55 ) ;
else
V_26 = F_287 ( V_55 ) ;
if ( ! V_26 )
return - V_452 ;
F_22 ( & V_46 ) ;
if ( F_136 ( F_58 ( V_55 ) ) )
V_59 = F_279 ( V_26 , V_55 ) ;
else
V_59 = F_283 ( V_26 , V_55 ) ;
F_24 ( & V_46 ) ;
return V_59 ;
}
static int F_289 ( struct V_101 * V_80 ,
struct V_91 * V_79 )
{
#if F_156 ( V_242 )
struct V_192 * V_365 ;
if ( V_79 -> V_106 != V_191 )
return 0 ;
V_365 = (struct V_192 * ) V_79 ;
if ( ! ( F_157 ( & V_365 -> V_193 ) & V_244 ) )
return 0 ;
if ( ! V_365 -> V_420 )
return - V_48 ;
V_80 -> V_120 = V_365 -> V_420 ;
#endif
return 0 ;
}
int F_224 ( struct V_5 * V_6 , int V_351 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( V_55 -> V_60 == V_141 ) {
V_6 -> V_78 . V_79 . V_92 . V_94 = V_187 ;
V_59 = F_270 ( V_6 , F_58 ( V_55 ) ) ;
if ( V_59 )
return V_59 ;
}
if ( ! F_36 ( V_55 , V_353 , V_276 ) )
return - V_48 ;
if ( V_55 -> V_423 ) {
V_59 = F_285 ( V_55 ) ;
if ( V_59 )
goto V_165;
}
V_55 -> V_351 = V_351 ;
if ( V_6 -> V_8 ) {
if ( F_117 ( V_6 -> V_8 , 1 ) ) {
V_59 = F_217 ( V_55 ) ;
if ( V_59 )
goto V_165;
} else if ( F_119 ( V_6 -> V_8 , 1 ) ) {
V_59 = F_219 ( V_55 , V_351 ) ;
if ( V_59 )
goto V_165;
} else {
V_59 = - V_186 ;
goto V_165;
}
} else
F_226 ( V_55 ) ;
return 0 ;
V_165:
V_55 -> V_351 = 0 ;
F_36 ( V_55 , V_276 , V_353 ) ;
return V_59 ;
}
int F_270 ( struct V_5 * V_6 , struct V_91 * V_79 )
{
struct V_54 * V_55 ;
int V_59 ;
struct V_91 * V_234 ;
if ( V_79 -> V_106 != V_187 && V_79 -> V_106 != V_191 &&
V_79 -> V_106 != V_107 )
return - V_218 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_36 ( V_55 , V_141 , V_353 ) )
return - V_48 ;
V_59 = F_289 ( & V_6 -> V_78 . V_79 . V_80 , V_79 ) ;
if ( V_59 )
goto V_325;
memcpy ( F_58 ( V_55 ) , V_79 , F_215 ( V_79 ) ) ;
if ( ! F_129 ( V_79 ) ) {
V_59 = F_69 ( V_79 , & V_6 -> V_78 . V_79 . V_80 ) ;
if ( V_59 )
goto V_325;
V_59 = F_78 ( V_55 , NULL ) ;
if ( V_59 )
goto V_325;
}
if ( ! ( V_55 -> V_424 & ( 1 << V_425 ) ) ) {
if ( V_79 -> V_106 == V_187 )
V_55 -> V_261 = 1 ;
#if F_156 ( V_242 )
else if ( V_79 -> V_106 == V_191 ) {
struct V_22 * V_22 = V_55 -> V_6 . V_78 . V_79 . V_80 . V_22 ;
V_55 -> V_261 = V_22 -> V_453 . V_454 . V_455 ;
}
#endif
}
V_59 = F_288 ( V_55 ) ;
if ( V_59 )
goto V_330;
V_234 = F_59 ( V_55 ) ;
V_234 -> V_106 = V_79 -> V_106 ;
return 0 ;
V_330:
if ( V_55 -> V_41 )
F_56 ( V_55 ) ;
V_325:
F_36 ( V_55 , V_353 , V_141 ) ;
return V_59 ;
}
static int F_290 ( void * V_64 , struct V_54 * V_55 )
{
struct V_63 * V_63 ;
V_63 = V_64 ;
V_63 -> V_216 = V_217 ;
if ( F_60 ( V_55 ) == V_187 ) {
struct V_188 * V_456 , * V_457 ;
V_456 = (struct V_188 * ) F_58 ( V_55 ) ;
V_457 = (struct V_188 * ) F_59 ( V_55 ) ;
F_39 ( V_63 , 4 ) ;
V_63 -> V_92 . V_211 . V_79 = V_456 -> V_189 . V_190 ;
V_63 -> V_93 . V_211 . V_79 = V_457 -> V_189 . V_190 ;
V_63 -> V_47 = V_456 -> V_196 ;
} else if ( F_60 ( V_55 ) == V_191 ) {
struct V_192 * V_458 , * V_459 ;
V_458 = (struct V_192 * ) F_58 ( V_55 ) ;
V_459 = (struct V_192 * ) F_59 ( V_55 ) ;
F_39 ( V_63 , 6 ) ;
V_63 -> V_92 . V_213 = V_458 -> V_193 ;
V_63 -> V_93 . V_213 = V_459 -> V_193 ;
V_63 -> V_47 = V_458 -> V_197 ;
}
return 0 ;
}
static int F_291 ( struct V_268 * V_183 ,
struct V_214 * V_215 )
{
struct V_54 * V_55 = V_183 -> V_135 ;
struct V_12 V_2 ;
struct V_460 * V_461 = & V_215 -> V_17 . V_462 ;
int V_59 = 0 ;
F_22 ( & V_55 -> V_144 ) ;
if ( V_55 -> V_60 != V_291 )
goto V_121;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_215 -> V_2 ) {
case V_463 :
V_2 . V_2 = V_295 ;
V_2 . V_16 = - V_296 ;
break;
case V_464 :
V_2 . V_17 . V_327 . V_20 = V_215 -> V_20 ;
V_2 . V_17 . V_327 . V_19 = V_465 ;
if ( V_461 -> V_16 != V_466 ) {
V_2 . V_2 = V_295 ;
V_2 . V_16 = V_215 -> V_17 . V_462 . V_16 ;
F_198 ( L_14 ,
V_2 . V_16 ) ;
break;
}
V_59 = F_61 ( V_55 , V_461 -> V_95 ) ;
if ( V_59 ) {
F_198 ( L_15 , V_59 ) ;
V_2 . V_2 = V_416 ;
V_2 . V_16 = V_59 ;
break;
}
F_292 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ,
V_55 -> V_6 . V_78 . V_282 ,
& V_2 . V_17 . V_327 . V_170 ) ;
V_2 . V_17 . V_327 . V_166 = V_461 -> V_467 ;
V_2 . V_17 . V_327 . V_95 = V_461 -> V_95 ;
V_2 . V_2 = V_300 ;
V_2 . V_16 = 0 ;
break;
default:
F_203 ( L_9 ,
V_215 -> V_2 ) ;
goto V_121;
}
V_59 = V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_2 ) ;
if ( V_59 ) {
V_55 -> V_183 . V_90 = NULL ;
F_37 ( V_55 , V_280 ) ;
F_24 ( & V_55 -> V_144 ) ;
F_182 ( & V_55 -> V_6 ) ;
return V_59 ;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
return V_59 ;
}
static int F_293 ( struct V_54 * V_55 ,
struct V_168 * V_169 )
{
struct V_468 V_224 ;
struct V_268 * V_6 ;
void * V_20 ;
int V_319 , V_59 ;
memset ( & V_224 , 0 , sizeof V_224 ) ;
V_319 = F_174 ( V_55 ) ;
V_224 . V_19 = V_319 + V_169 -> V_19 ;
if ( V_224 . V_19 < V_169 -> V_19 )
return - V_48 ;
if ( V_224 . V_19 ) {
V_20 = F_88 ( V_224 . V_19 , V_469 ) ;
if ( ! V_20 )
return - V_138 ;
} else {
V_20 = NULL ;
}
if ( V_169 -> V_20 && V_169 -> V_19 )
memcpy ( V_20 + V_319 , V_169 -> V_20 ,
V_169 -> V_19 ) ;
if ( V_20 ) {
V_59 = F_290 ( V_20 , V_55 ) ;
if ( V_59 )
goto V_121;
V_224 . V_20 = V_20 ;
}
V_6 = F_294 ( V_55 -> V_6 . V_8 , F_291 ,
V_55 ) ;
if ( F_104 ( V_6 ) ) {
V_59 = F_105 ( V_6 ) ;
goto V_121;
}
V_55 -> V_183 . V_90 = V_6 ;
V_224 . V_202 = V_55 -> V_6 . V_78 . V_282 ;
V_224 . V_207 = F_213 ( & V_55 -> V_6 , F_59 ( V_55 ) ) ;
V_224 . V_363 = 1 << ( V_470 - 8 ) ;
V_224 . V_471 = V_472 ;
V_59 = F_295 ( V_55 -> V_183 . V_90 , & V_224 ) ;
if ( V_59 ) {
F_192 ( V_55 -> V_183 . V_90 ) ;
V_55 -> V_183 . V_90 = NULL ;
}
V_121:
F_55 ( V_20 ) ;
return V_59 ;
}
static int F_296 ( struct V_54 * V_55 ,
struct V_168 * V_169 )
{
struct V_473 V_224 ;
struct V_315 * V_78 ;
void * V_20 ;
struct V_268 * V_6 ;
int V_319 , V_59 ;
memset ( & V_224 , 0 , sizeof V_224 ) ;
V_319 = F_174 ( V_55 ) ;
V_224 . V_19 = V_319 + V_169 -> V_19 ;
if ( V_224 . V_19 < V_169 -> V_19 )
return - V_48 ;
if ( V_224 . V_19 ) {
V_20 = F_88 ( V_224 . V_19 , V_469 ) ;
if ( ! V_20 )
return - V_138 ;
} else {
V_20 = NULL ;
}
if ( V_169 -> V_20 && V_169 -> V_19 )
memcpy ( V_20 + V_319 , V_169 -> V_20 ,
V_169 -> V_19 ) ;
V_6 = F_294 ( V_55 -> V_6 . V_8 , F_201 , V_55 ) ;
if ( F_104 ( V_6 ) ) {
V_59 = F_105 ( V_6 ) ;
goto V_121;
}
V_55 -> V_183 . V_90 = V_6 ;
V_78 = & V_55 -> V_6 . V_78 ;
if ( V_20 ) {
V_59 = F_290 ( V_20 , V_55 ) ;
if ( V_59 )
goto V_121;
V_224 . V_20 = V_20 ;
}
V_224 . V_221 = & V_78 -> V_282 [ 0 ] ;
if ( V_78 -> V_316 == 2 )
V_224 . V_317 = & V_78 -> V_282 [ 1 ] ;
V_224 . V_207 = F_213 ( & V_55 -> V_6 , F_59 ( V_55 ) ) ;
V_224 . V_166 = V_55 -> V_166 ;
V_224 . V_137 = V_55 -> V_6 . V_137 ;
V_224 . V_474 = V_55 -> V_147 ;
V_224 . V_173 = V_169 -> V_173 ;
V_224 . V_175 = V_169 -> V_175 ;
V_224 . V_287 = V_169 -> V_287 ;
V_224 . V_321 = F_297 ( T_3 , 7 , V_169 -> V_321 ) ;
V_224 . V_288 = F_297 ( T_3 , 7 , V_169 -> V_288 ) ;
V_224 . V_475 = V_470 ;
V_224 . V_476 = V_470 ;
V_224 . V_471 = V_472 ;
V_224 . V_167 = V_55 -> V_167 ? 1 : 0 ;
V_59 = F_298 ( V_55 -> V_183 . V_90 , & V_224 ) ;
V_121:
if ( V_59 && ! F_104 ( V_6 ) ) {
F_192 ( V_6 ) ;
V_55 -> V_183 . V_90 = NULL ;
}
F_55 ( V_20 ) ;
return V_59 ;
}
static int F_299 ( struct V_54 * V_55 ,
struct V_168 * V_169 )
{
struct V_334 * V_183 ;
int V_59 ;
struct V_477 V_478 ;
V_183 = F_220 ( V_55 -> V_6 . V_8 , F_214 , V_55 ) ;
if ( F_104 ( V_183 ) )
return F_105 ( V_183 ) ;
V_183 -> V_352 = V_55 -> V_352 ;
V_55 -> V_183 . V_185 = V_183 ;
memcpy ( & V_183 -> V_339 , F_58 ( V_55 ) ,
F_215 ( F_58 ( V_55 ) ) ) ;
memcpy ( & V_183 -> V_341 , F_59 ( V_55 ) ,
F_215 ( F_59 ( V_55 ) ) ) ;
V_59 = F_108 ( V_55 , V_169 ) ;
if ( V_59 )
goto V_121;
if ( V_169 ) {
V_478 . V_345 = V_169 -> V_175 ;
V_478 . V_344 = V_169 -> V_173 ;
V_478 . V_20 = V_169 -> V_20 ;
V_478 . V_19 = V_169 -> V_19 ;
V_478 . V_467 = V_55 -> V_6 . V_149 ? V_55 -> V_166 : V_169 -> V_166 ;
} else {
memset ( & V_478 , 0 , sizeof V_478 ) ;
V_478 . V_467 = V_55 -> V_166 ;
}
V_59 = F_300 ( V_183 , & V_478 ) ;
V_121:
if ( V_59 ) {
F_193 ( V_183 ) ;
V_55 -> V_183 . V_185 = NULL ;
}
return V_59 ;
}
int F_301 ( struct V_5 * V_6 , struct V_168 * V_169 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_36 ( V_55 , V_388 , V_291 ) )
return - V_48 ;
if ( ! V_6 -> V_149 ) {
V_55 -> V_166 = V_169 -> V_166 ;
V_55 -> V_167 = V_169 -> V_167 ;
}
if ( F_117 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( V_6 -> V_137 == V_164 )
V_59 = F_293 ( V_55 , V_169 ) ;
else
V_59 = F_296 ( V_55 , V_169 ) ;
} else if ( F_119 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_299 ( V_55 , V_169 ) ;
else
V_59 = - V_186 ;
if ( V_59 )
goto V_165;
return 0 ;
V_165:
F_36 ( V_55 , V_291 , V_388 ) ;
return V_59 ;
}
static int F_302 ( struct V_54 * V_55 ,
struct V_168 * V_169 )
{
struct V_479 V_461 ;
int V_59 ;
V_59 = F_108 ( V_55 , V_169 ) ;
if ( V_59 )
goto V_121;
V_59 = F_112 ( V_55 , V_169 ) ;
if ( V_59 )
goto V_121;
memset ( & V_461 , 0 , sizeof V_461 ) ;
V_461 . V_166 = V_55 -> V_166 ;
V_461 . V_474 = V_55 -> V_147 ;
V_461 . V_20 = V_169 -> V_20 ;
V_461 . V_19 = V_169 -> V_19 ;
V_461 . V_173 = V_169 -> V_173 ;
V_461 . V_175 = V_169 -> V_175 ;
V_461 . V_480 = 0 ;
V_461 . V_287 = V_169 -> V_287 ;
V_461 . V_288 = F_297 ( T_3 , 7 , V_169 -> V_288 ) ;
V_461 . V_167 = V_55 -> V_167 ? 1 : 0 ;
V_59 = F_303 ( V_55 -> V_183 . V_90 , & V_461 ) ;
V_121:
return V_59 ;
}
static int F_304 ( struct V_54 * V_55 ,
struct V_168 * V_169 )
{
struct V_477 V_478 ;
int V_59 ;
if ( ! V_169 )
return - V_48 ;
V_59 = F_108 ( V_55 , V_169 ) ;
if ( V_59 )
return V_59 ;
V_478 . V_345 = V_169 -> V_175 ;
V_478 . V_344 = V_169 -> V_173 ;
V_478 . V_20 = V_169 -> V_20 ;
V_478 . V_19 = V_169 -> V_19 ;
if ( V_55 -> V_6 . V_149 ) {
V_478 . V_467 = V_55 -> V_166 ;
} else
V_478 . V_467 = V_169 -> V_166 ;
return F_305 ( V_55 -> V_183 . V_185 , & V_478 ) ;
}
static int F_306 ( struct V_54 * V_55 ,
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
return F_307 ( V_55 -> V_183 . V_90 , & V_461 ) ;
}
int F_308 ( struct V_5 * V_6 , struct V_168 * V_169 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
V_55 -> V_139 = F_90 ( V_140 ) ;
if ( ! F_33 ( V_55 , V_291 ) )
return - V_48 ;
if ( ! V_6 -> V_149 && V_169 ) {
V_55 -> V_166 = V_169 -> V_166 ;
V_55 -> V_167 = V_169 -> V_167 ;
}
if ( F_117 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( V_6 -> V_137 == V_164 ) {
if ( V_169 )
V_59 = F_306 ( V_55 , V_466 ,
V_169 -> V_95 ,
V_169 -> V_20 ,
V_169 -> V_19 ) ;
else
V_59 = F_306 ( V_55 , V_466 ,
0 , NULL , 0 ) ;
} else {
if ( V_169 )
V_59 = F_302 ( V_55 , V_169 ) ;
else
V_59 = F_196 ( V_55 ) ;
}
} else if ( F_119 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_304 ( V_55 , V_169 ) ;
else
V_59 = - V_186 ;
if ( V_59 )
goto V_283;
return 0 ;
V_283:
F_113 ( V_55 ) ;
F_309 ( V_6 , NULL , 0 ) ;
return V_59 ;
}
int F_310 ( struct V_5 * V_6 , enum V_483 V_2 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! V_55 -> V_183 . V_90 )
return - V_48 ;
switch ( V_6 -> V_8 -> V_82 ) {
case V_484 :
V_59 = F_311 ( V_55 -> V_183 . V_90 , V_2 ) ;
break;
default:
V_59 = 0 ;
break;
}
return V_59 ;
}
int F_309 ( struct V_5 * V_6 , const void * V_20 ,
T_3 V_19 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! V_55 -> V_183 . V_90 )
return - V_48 ;
if ( F_117 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( V_6 -> V_137 == V_164 )
V_59 = F_306 ( V_55 , V_485 , 0 ,
V_20 , V_19 ) ;
else
V_59 = F_199 ( V_55 -> V_183 . V_90 ,
V_10 , NULL ,
0 , V_20 , V_19 ) ;
} else if ( F_119 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
V_59 = F_312 ( V_55 -> V_183 . V_185 ,
V_20 , V_19 ) ;
} else
V_59 = - V_186 ;
return V_59 ;
}
int F_313 ( struct V_5 * V_6 )
{
struct V_54 * V_55 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! V_55 -> V_183 . V_90 )
return - V_48 ;
if ( F_117 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
V_59 = F_113 ( V_55 ) ;
if ( V_59 )
goto V_121;
if ( F_314 ( V_55 -> V_183 . V_90 , NULL , 0 ) )
F_315 ( V_55 -> V_183 . V_90 , NULL , 0 ) ;
} else if ( F_119 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
V_59 = F_316 ( V_55 -> V_183 . V_185 , 0 ) ;
} else
V_59 = - V_48 ;
V_121:
return V_59 ;
}
static int F_317 ( int V_16 , struct V_486 * V_89 )
{
struct V_54 * V_55 ;
struct V_86 * V_87 = V_89 -> V_135 ;
struct V_12 V_2 ;
int V_59 = 0 ;
V_55 = V_87 -> V_55 ;
F_22 ( & V_55 -> V_144 ) ;
if ( V_55 -> V_60 != V_353 &&
V_55 -> V_60 != V_360 )
goto V_121;
if ( ! V_16 )
V_16 = F_61 ( V_55 , F_64 ( V_89 -> V_97 . V_95 ) ) ;
else
F_198 ( L_16 ,
V_16 ) ;
F_22 ( & V_55 -> V_143 ) ;
if ( ! V_16 && V_55 -> V_6 . V_149 ) {
V_16 = F_318 ( V_55 -> V_6 . V_149 , & V_89 -> V_97 . V_70 ,
F_145 ( V_89 -> V_97 . V_487 ) ) ;
if ( V_16 )
F_198 ( L_17 ,
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
F_319 ( V_55 -> V_6 . V_8 ,
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
F_37 ( V_55 , V_280 ) ;
F_24 ( & V_55 -> V_144 ) ;
F_182 ( & V_55 -> V_6 ) ;
return 0 ;
}
V_121:
F_24 ( & V_55 -> V_144 ) ;
return 0 ;
}
static void F_320 ( struct V_54 * V_55 ,
struct V_91 * V_79 , union V_69 * V_70 )
{
unsigned char V_490 [ V_491 ] ;
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
struct V_188 * sin = (struct V_188 * ) V_79 ;
struct V_192 * V_365 = (struct V_192 * ) V_79 ;
if ( F_129 ( V_79 ) ) {
memset ( V_70 , 0 , sizeof *V_70 ) ;
} else if ( ( V_79 -> V_106 == V_191 ) &&
( ( F_64 ( V_365 -> V_193 . V_492 [ 0 ] ) & 0xFFF0FFFF ) ==
0xFF10A01B ) ) {
memcpy ( V_70 , & V_365 -> V_193 , sizeof *V_70 ) ;
} else if ( V_79 -> V_106 == V_107 ) {
memcpy ( V_70 , & ( (struct V_99 * ) V_79 ) -> V_104 , sizeof *V_70 ) ;
} else if ( ( V_79 -> V_106 == V_191 ) ) {
F_321 ( & V_365 -> V_193 , V_80 -> V_493 , V_490 ) ;
if ( V_55 -> V_6 . V_26 == V_30 )
V_490 [ 7 ] = 0x01 ;
* V_70 = * (union V_69 * ) ( V_490 + 4 ) ;
} else {
F_322 ( sin -> V_189 . V_190 , V_80 -> V_493 , V_490 ) ;
if ( V_55 -> V_6 . V_26 == V_30 )
V_490 [ 7 ] = 0x01 ;
* V_70 = * (union V_69 * ) ( V_490 + 4 ) ;
}
}
static int F_323 ( struct V_54 * V_55 ,
struct V_86 * V_87 )
{
struct V_96 V_97 ;
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
T_11 V_364 ;
int V_59 ;
F_62 ( V_80 , & V_97 . V_70 ) ;
V_59 = F_63 ( V_55 -> V_6 . V_8 , V_55 -> V_6 . V_9 ,
& V_97 . V_70 , & V_97 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_61 ( V_55 , 0 ) ;
if ( V_59 )
return V_59 ;
F_320 ( V_55 , (struct V_91 * ) & V_87 -> V_79 , & V_97 . V_70 ) ;
V_97 . V_95 = F_324 ( V_55 -> V_95 ) ;
F_232 ( V_80 , & V_97 . V_494 ) ;
V_97 . V_126 = F_234 ( F_116 ( V_80 ) ) ;
V_97 . V_495 = V_87 -> V_495 ;
if ( ( V_97 . V_495 == F_325 ( V_496 ) ) &&
( ! F_326 ( & V_382 ,
V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 ) ) ) {
F_225 ( L_18
L_19 ,
V_55 -> V_6 . V_8 -> V_354 , V_55 -> V_6 . V_9 ) ;
return - V_114 ;
}
V_364 = V_497 | V_498 |
V_499 | V_500 |
V_501 | V_502 |
V_503 |
V_504 ;
if ( V_55 -> V_6 . V_26 == V_32 )
V_364 |= V_505 |
V_506 |
V_507 |
V_508 |
V_509 ;
V_87 -> V_89 . V_90 = F_327 ( & V_382 , V_55 -> V_6 . V_8 ,
V_55 -> V_6 . V_9 , & V_97 ,
V_364 , V_39 ,
F_317 , V_87 ) ;
return F_328 ( V_87 -> V_89 . V_90 ) ;
}
static void F_329 ( struct V_383 * V_357 )
{
struct V_510 * V_511 = F_54 ( V_357 , struct V_510 , V_357 ) ;
struct V_86 * V_87 = V_511 -> V_87 ;
struct V_486 * V_512 = V_87 -> V_89 . V_90 ;
V_87 -> V_89 . V_90 -> V_135 = V_87 ;
F_317 ( 0 , V_512 ) ;
F_191 ( & V_87 -> V_88 , F_53 ) ;
F_55 ( V_511 ) ;
}
static void F_330 ( struct V_91 * V_79 , union V_69 * V_70 )
{
struct V_188 * sin = (struct V_188 * ) V_79 ;
struct V_192 * V_365 = (struct V_192 * ) V_79 ;
if ( F_129 ( V_79 ) ) {
memset ( V_70 , 0 , sizeof *V_70 ) ;
} else if ( V_79 -> V_106 == V_191 ) {
memcpy ( V_70 , & V_365 -> V_193 , sizeof *V_70 ) ;
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
* ( V_74 * ) ( & V_70 -> V_75 [ 12 ] ) = sin -> V_189 . V_190 ;
}
}
static int F_331 ( struct V_54 * V_55 ,
struct V_86 * V_87 )
{
struct V_510 * V_357 ;
struct V_101 * V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
int V_165 = 0 ;
struct V_91 * V_79 = (struct V_91 * ) & V_87 -> V_79 ;
struct V_67 * V_68 = NULL ;
enum V_50 V_77 ;
bool V_513 ;
V_513 = V_87 -> V_495 == F_325 ( V_496 ) ;
if ( F_121 ( (struct V_91 * ) & V_87 -> V_79 ) )
return - V_48 ;
V_357 = F_88 ( sizeof *V_357 , V_39 ) ;
if ( ! V_357 )
return - V_138 ;
V_87 -> V_89 . V_90 = F_88 ( sizeof( struct V_486 ) , V_39 ) ;
if ( ! V_87 -> V_89 . V_90 ) {
V_165 = - V_138 ;
goto V_514;
}
F_330 ( V_79 , & V_87 -> V_89 . V_90 -> V_97 . V_70 ) ;
V_87 -> V_89 . V_90 -> V_97 . V_126 = F_234 ( 0xffff ) ;
if ( V_55 -> V_6 . V_26 == V_30 )
V_87 -> V_89 . V_90 -> V_97 . V_95 = F_324 ( V_98 ) ;
if ( V_80 -> V_120 )
V_68 = F_74 ( & V_111 , V_80 -> V_120 ) ;
if ( ! V_68 ) {
V_165 = - V_76 ;
goto V_515;
}
V_87 -> V_89 . V_90 -> V_97 . V_410 = F_258 ( V_68 ) ;
V_87 -> V_89 . V_90 -> V_97 . V_403 = 1 ;
V_87 -> V_89 . V_90 -> V_97 . V_408 = F_257 ( V_68 -> V_408 ) ;
V_77 = V_55 -> V_41 -> V_49 [ V_55 -> V_6 . V_9 -
F_27 ( V_55 -> V_41 -> V_8 ) ] ;
if ( V_79 -> V_106 == V_187 ) {
if ( V_77 == V_400 ) {
V_87 -> V_89 . V_90 -> V_97 . V_403 = V_516 ;
if ( ! V_513 ) {
V_165 = F_40 ( V_68 , & V_87 -> V_89 . V_90 -> V_97 . V_70 ,
true ) ;
if ( ! V_165 )
V_87 -> V_279 = true ;
}
}
} else {
if ( V_77 == V_400 )
V_165 = - V_517 ;
}
F_76 ( V_68 ) ;
if ( V_165 || ! V_87 -> V_89 . V_90 -> V_97 . V_408 ) {
if ( ! V_165 )
V_165 = - V_48 ;
goto V_515;
}
F_79 ( (struct V_91 * ) & V_55 -> V_6 . V_78 . V_79 . V_92 ,
& V_87 -> V_89 . V_90 -> V_97 . V_494 ) ;
V_357 -> V_6 = V_55 ;
V_357 -> V_87 = V_87 ;
F_239 ( & V_357 -> V_357 , F_329 ) ;
F_332 ( & V_87 -> V_88 ) ;
F_229 ( V_362 , & V_357 -> V_357 ) ;
return 0 ;
V_515:
F_55 ( V_87 -> V_89 . V_90 ) ;
V_514:
F_55 ( V_357 ) ;
return V_165 ;
}
int F_333 ( struct V_5 * V_6 , struct V_91 * V_79 ,
T_3 V_495 , void * V_135 )
{
struct V_54 * V_55 ;
struct V_86 * V_87 ;
int V_59 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
if ( ! F_33 ( V_55 , V_353 ) &&
! F_33 ( V_55 , V_360 ) )
return - V_48 ;
V_87 = F_205 ( sizeof *V_87 , V_39 ) ;
if ( ! V_87 )
return - V_138 ;
memcpy ( & V_87 -> V_79 , V_79 , F_215 ( V_79 ) ) ;
V_87 -> V_135 = V_135 ;
V_87 -> V_55 = V_55 ;
V_87 -> V_279 = false ;
V_87 -> V_495 = V_495 ;
F_334 ( & V_55 -> V_46 ) ;
F_335 ( & V_87 -> V_83 , & V_55 -> V_146 ) ;
F_336 ( & V_55 -> V_46 ) ;
if ( F_73 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
F_337 ( & V_87 -> V_88 ) ;
V_59 = F_331 ( V_55 , V_87 ) ;
} else if ( F_189 ( V_6 -> V_8 , V_6 -> V_9 ) )
V_59 = F_323 ( V_55 , V_87 ) ;
else
V_59 = - V_186 ;
if ( V_59 ) {
F_338 ( & V_55 -> V_46 ) ;
F_57 ( & V_87 -> V_83 ) ;
F_339 ( & V_55 -> V_46 ) ;
F_55 ( V_87 ) ;
}
return V_59 ;
}
void F_340 ( struct V_5 * V_6 , struct V_91 * V_79 )
{
struct V_54 * V_55 ;
struct V_86 * V_87 ;
V_55 = F_54 ( V_6 , struct V_54 , V_6 ) ;
F_338 ( & V_55 -> V_46 ) ;
F_23 (mc, &id_priv->mc_list, list) {
if ( ! memcmp ( & V_87 -> V_79 , V_79 , F_215 ( V_79 ) ) ) {
F_57 ( & V_87 -> V_83 ) ;
F_339 ( & V_55 -> V_46 ) ;
if ( V_6 -> V_149 )
F_341 ( V_6 -> V_149 ,
& V_87 -> V_89 . V_90 -> V_97 . V_70 ,
F_145 ( V_87 -> V_89 . V_90 -> V_97 . V_487 ) ) ;
F_111 ( V_55 -> V_41 -> V_8 != V_6 -> V_8 ) ;
if ( F_189 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
F_190 ( V_87 -> V_89 . V_90 ) ;
F_55 ( V_87 ) ;
} else if ( F_73 ( V_6 -> V_8 , V_6 -> V_9 ) ) {
if ( V_87 -> V_279 ) {
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
V_87 -> V_279 = false ;
}
F_191 ( & V_87 -> V_88 , F_53 ) ;
}
return;
}
}
F_339 ( & V_55 -> V_46 ) ;
}
static int F_342 ( struct V_67 * V_68 , struct V_54 * V_55 )
{
struct V_101 * V_80 ;
struct V_386 * V_357 ;
V_80 = & V_55 -> V_6 . V_78 . V_79 . V_80 ;
if ( ( V_80 -> V_120 == V_68 -> V_241 ) &&
( F_169 ( F_152 ( V_68 ) , V_80 -> V_22 ) ) &&
memcmp ( V_80 -> V_119 , V_68 -> V_80 , V_68 -> V_518 ) ) {
F_75 ( L_20 ,
V_68 -> V_354 , & V_55 -> V_6 ) ;
V_357 = F_88 ( sizeof *V_357 , V_39 ) ;
if ( ! V_357 )
return - V_138 ;
F_239 ( & V_357 -> V_357 , F_237 ) ;
V_357 -> V_6 = V_55 ;
V_357 -> V_2 . V_2 = V_519 ;
F_20 ( & V_55 -> V_42 ) ;
F_229 ( V_362 , & V_357 -> V_357 ) ;
}
return 0 ;
}
static int F_343 ( struct V_520 * V_521 , unsigned long V_2 ,
void * V_522 )
{
struct V_67 * V_68 = F_344 ( V_522 ) ;
struct V_40 * V_41 ;
struct V_54 * V_55 ;
int V_59 = V_523 ;
if ( V_2 != V_524 )
return V_523 ;
if ( ! ( V_68 -> V_58 & V_525 ) || ! ( V_68 -> V_526 & V_527 ) )
return V_523 ;
F_22 ( & V_46 ) ;
F_23 (cma_dev, &dev_list, list)
F_23 (id_priv, &cma_dev->id_list, list) {
V_59 = F_342 ( V_68 , V_55 ) ;
if ( V_59 )
goto V_121;
}
V_121:
F_24 ( & V_46 ) ;
return V_59 ;
}
static void F_345 ( struct V_53 * V_8 )
{
struct V_40 * V_41 ;
struct V_54 * V_55 ;
unsigned int V_129 ;
unsigned long V_51 = 0 ;
V_41 = F_205 ( sizeof *V_41 , V_39 ) ;
if ( ! V_41 )
return;
V_41 -> V_8 = V_8 ;
V_41 -> V_49 = F_346 ( V_8 -> V_122 ,
sizeof( * V_41 -> V_49 ) ,
V_39 ) ;
if ( ! V_41 -> V_49 )
goto V_528;
V_41 -> V_52 = F_346 ( V_8 -> V_122 ,
sizeof( * V_41 -> V_52 ) ,
V_39 ) ;
if ( ! V_41 -> V_52 )
goto V_529;
for ( V_129 = F_27 ( V_8 ) ; V_129 <= F_347 ( V_8 ) ; V_129 ++ ) {
V_51 = F_29 ( V_8 , V_129 ) ;
F_348 ( ! V_51 ) ;
V_41 -> V_49 [ V_129 - F_27 ( V_8 ) ] =
F_349 ( & V_51 , V_530 ) ;
V_41 -> V_52 [ V_129 - F_27 ( V_8 ) ] = 0 ;
}
F_93 ( & V_41 -> V_57 ) ;
F_94 ( & V_41 -> V_42 , 1 ) ;
F_95 ( & V_41 -> V_84 ) ;
F_350 ( V_8 , & V_531 , V_41 ) ;
F_22 ( & V_46 ) ;
F_48 ( & V_41 -> V_83 , & V_532 ) ;
F_23 (id_priv, &listen_any_list, list)
F_223 ( V_55 , V_41 ) ;
F_24 ( & V_46 ) ;
return;
V_529:
F_55 ( V_41 -> V_49 ) ;
V_528:
F_55 ( V_41 ) ;
return;
}
static int F_351 ( struct V_54 * V_55 )
{
struct V_12 V_2 ;
enum V_56 V_60 ;
int V_59 = 0 ;
V_60 = F_37 ( V_55 , V_387 ) ;
if ( V_60 == V_280 )
return 0 ;
F_183 ( V_55 , V_60 ) ;
F_22 ( & V_55 -> V_144 ) ;
if ( ! F_33 ( V_55 , V_387 ) )
goto V_121;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_533 ;
V_59 = V_55 -> V_6 . V_134 ( & V_55 -> V_6 , & V_2 ) ;
V_121:
F_24 ( & V_55 -> V_144 ) ;
return V_59 ;
}
static void F_352 ( struct V_40 * V_41 )
{
struct V_54 * V_55 ;
int V_59 ;
F_22 ( & V_46 ) ;
while ( ! F_179 ( & V_41 -> V_84 ) ) {
V_55 = F_180 ( V_41 -> V_84 . V_273 ,
struct V_54 , V_83 ) ;
F_57 ( & V_55 -> V_145 ) ;
F_181 ( & V_55 -> V_83 ) ;
F_20 ( & V_55 -> V_42 ) ;
F_24 ( & V_46 ) ;
V_59 = V_55 -> V_281 ? 1 : F_351 ( V_55 ) ;
F_86 ( V_55 ) ;
if ( V_59 )
F_182 ( & V_55 -> V_6 ) ;
F_22 ( & V_46 ) ;
}
F_24 ( & V_46 ) ;
F_50 ( V_41 ) ;
F_194 ( & V_41 -> V_57 ) ;
}
static void F_353 ( struct V_53 * V_8 , void * V_534 )
{
struct V_40 * V_41 = V_534 ;
if ( ! V_41 )
return;
F_22 ( & V_46 ) ;
F_57 ( & V_41 -> V_83 ) ;
F_24 ( & V_46 ) ;
F_352 ( V_41 ) ;
F_55 ( V_41 -> V_52 ) ;
F_55 ( V_41 -> V_49 ) ;
F_55 ( V_41 ) ;
}
static int F_354 ( struct V_535 * V_536 , struct V_537 * V_538 )
{
struct V_539 * V_540 ;
struct V_541 * V_542 ;
struct V_54 * V_55 ;
struct V_5 * V_6 = NULL ;
struct V_40 * V_41 ;
int V_543 = 0 , V_544 = 0 ;
F_22 ( & V_46 ) ;
F_23 (cma_dev, &dev_list, list) {
if ( V_543 < V_538 -> args [ 0 ] ) {
V_543 ++ ;
continue;
}
V_544 = 0 ;
F_23 (id_priv, &cma_dev->id_list, list) {
if ( V_544 < V_538 -> args [ 1 ] ) {
V_544 ++ ;
continue;
}
V_542 = F_355 ( V_536 , & V_540 , V_538 -> V_540 -> V_545 ,
sizeof *V_542 , V_546 ,
V_547 ,
V_548 ) ;
if ( ! V_542 )
goto V_121;
memset ( V_542 , 0 , sizeof *V_542 ) ;
V_6 = & V_55 -> V_6 ;
V_542 -> V_82 = V_6 -> V_78 . V_79 . V_80 . V_102 ;
V_542 -> V_9 = V_6 -> V_9 ;
V_542 -> V_120 =
V_6 -> V_78 . V_79 . V_80 . V_120 ;
if ( F_356 ( V_536 , V_540 ,
F_215 ( F_58 ( V_55 ) ) ,
F_58 ( V_55 ) ,
V_549 ) )
goto V_121;
if ( F_356 ( V_536 , V_540 ,
F_215 ( F_58 ( V_55 ) ) ,
F_59 ( V_55 ) ,
V_550 ) )
goto V_121;
V_542 -> V_551 = V_55 -> V_139 ;
V_542 -> V_552 = V_6 -> V_26 ;
V_542 -> V_553 = V_55 -> V_60 ;
V_542 -> V_166 = V_55 -> V_166 ;
V_542 -> V_137 = V_6 -> V_137 ;
V_544 ++ ;
}
V_538 -> args [ 1 ] = 0 ;
V_543 ++ ;
}
V_121:
F_24 ( & V_46 ) ;
V_538 -> args [ 0 ] = V_543 ;
V_538 -> args [ 1 ] = V_544 ;
return V_536 -> V_554 ;
}
static int F_357 ( struct V_22 * V_22 )
{
struct V_21 * V_27 = V_21 ( V_22 ) ;
F_358 ( & V_27 -> V_29 ) ;
F_358 ( & V_27 -> V_31 ) ;
F_358 ( & V_27 -> V_33 ) ;
F_358 ( & V_27 -> V_35 ) ;
return 0 ;
}
static void F_359 ( struct V_22 * V_22 )
{
struct V_21 * V_27 = V_21 ( V_22 ) ;
F_360 ( & V_27 -> V_29 ) ;
F_360 ( & V_27 -> V_31 ) ;
F_360 ( & V_27 -> V_33 ) ;
F_360 ( & V_27 -> V_35 ) ;
}
static int T_13 F_361 ( void )
{
int V_59 ;
V_362 = F_362 ( L_21 , V_555 ) ;
if ( ! V_362 )
return - V_138 ;
V_59 = F_363 ( & V_556 ) ;
if ( V_59 )
goto V_557;
F_364 ( & V_382 ) ;
F_365 ( & V_421 ) ;
F_366 ( & V_558 ) ;
V_59 = F_367 ( & V_531 ) ;
if ( V_59 )
goto V_165;
if ( F_368 ( V_546 , F_2 ( V_559 ) ,
V_559 ) )
F_225 ( L_22 ) ;
F_369 () ;
return 0 ;
V_165:
F_370 ( & V_558 ) ;
F_371 ( & V_421 ) ;
F_372 ( & V_382 ) ;
V_557:
F_373 ( V_362 ) ;
return V_59 ;
}
static void T_14 F_374 ( void )
{
F_375 () ;
F_376 ( V_546 ) ;
F_377 ( & V_531 ) ;
F_370 ( & V_558 ) ;
F_371 ( & V_421 ) ;
F_372 ( & V_382 ) ;
F_378 ( & V_556 ) ;
F_373 ( V_362 ) ;
}
