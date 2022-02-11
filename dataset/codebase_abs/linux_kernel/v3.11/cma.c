static int F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
unsigned long V_5 ;
int V_6 ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
V_6 = ( V_2 -> V_8 == V_4 ) ;
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 , enum V_3 V_9 )
{
unsigned long V_5 ;
int V_6 ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
if ( ( V_6 = ( V_2 -> V_8 == V_4 ) ) )
V_2 -> V_8 = V_9 ;
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
static enum V_3 F_5 ( struct V_1 * V_2 ,
enum V_3 V_9 )
{
unsigned long V_5 ;
enum V_3 V_10 ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
V_10 = V_2 -> V_8 ;
V_2 -> V_8 = V_9 ;
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_10 ;
}
static inline T_1 F_6 ( struct V_11 * V_12 )
{
return V_12 -> V_13 >> 4 ;
}
static inline void F_7 ( struct V_11 * V_12 , T_1 V_14 )
{
V_12 -> V_13 = ( V_14 << 4 ) | ( V_12 -> V_13 & 0xF ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_9 ( & V_16 -> V_17 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_18 . V_19 = V_16 -> V_19 ;
V_2 -> V_18 . V_20 . V_21 . V_22 . V_23 =
F_10 ( V_16 -> V_19 -> V_24 ) ;
F_11 ( & V_2 -> V_25 , & V_16 -> V_26 ) ;
}
static inline void F_12 ( struct V_15 * V_16 )
{
if ( F_13 ( & V_16 -> V_17 ) )
F_14 ( & V_16 -> V_4 ) ;
}
static inline void F_15 ( struct V_27 * V_27 )
{
struct V_28 * V_29 = F_16 ( V_27 , struct V_28 , V_30 ) ;
F_17 ( V_29 -> V_31 . V_32 ) ;
F_17 ( V_29 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_7 ) ;
F_20 ( & V_2 -> V_25 ) ;
F_12 ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
F_21 ( & V_7 ) ;
}
static inline struct V_33 * F_22 ( struct V_1 * V_2 )
{
return (struct V_33 * ) & V_2 -> V_18 . V_20 . V_21 . V_34 ;
}
static inline struct V_33 * F_23 ( struct V_1 * V_2 )
{
return (struct V_33 * ) & V_2 -> V_18 . V_20 . V_21 . V_35 ;
}
static inline unsigned short F_24 ( struct V_1 * V_2 )
{
return V_2 -> V_18 . V_20 . V_21 . V_34 . V_36 ;
}
static int F_25 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_38 V_39 ;
int V_6 = 0 ;
if ( V_2 -> V_37 ) {
if ( V_37 && V_2 -> V_37 != V_37 )
return - V_40 ;
return 0 ;
}
if ( V_37 ) {
V_2 -> V_37 = V_37 ;
return 0 ;
}
switch ( V_2 -> V_18 . V_41 ) {
case V_42 :
case V_43 :
V_2 -> V_37 = V_44 ;
break;
case V_45 :
F_26 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , & V_39 . V_46 ) ;
V_6 = F_27 ( V_2 -> V_18 . V_19 ,
V_2 -> V_18 . V_47 , & V_39 . V_46 ,
& V_39 ) ;
if ( ! V_6 )
V_2 -> V_37 = F_28 ( V_39 . V_37 ) ;
break;
default:
break;
}
return V_6 ;
}
static int F_29 ( struct V_48 * V_19 , union V_49 * V_50 , T_1 V_47 )
{
int V_51 ;
int V_52 ;
struct V_53 V_54 ;
union V_49 V_55 ;
V_52 = F_30 ( V_19 , V_47 , & V_54 ) ;
if ( V_52 )
return V_52 ;
for ( V_51 = 0 ; V_51 < V_54 . V_56 ; ++ V_51 ) {
V_52 = F_31 ( V_19 , V_47 , V_51 , & V_55 ) ;
if ( V_52 )
return V_52 ;
if ( ! memcmp ( & V_55 , V_50 , sizeof V_55 ) )
return 0 ;
}
return - V_57 ;
}
static void F_32 ( struct V_58 * V_59 , struct V_60 * V_22 )
{
V_22 -> V_61 = V_62 ;
F_33 ( V_22 , (union V_49 * ) & V_59 -> V_63 ) ;
F_34 ( V_22 , F_35 ( V_59 -> V_64 ) ) ;
}
static int F_36 ( struct V_33 * V_21 , struct V_60 * V_22 )
{
int V_6 ;
if ( V_21 -> V_65 != V_66 ) {
V_6 = F_37 ( V_21 , V_22 ) ;
} else {
F_32 ( (struct V_58 * ) V_21 , V_22 ) ;
V_6 = 0 ;
}
return V_6 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_60 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
struct V_15 * V_16 ;
union V_49 V_50 , V_67 ;
int V_6 = - V_68 ;
T_1 V_69 ;
enum V_70 V_71 = V_22 -> V_61 == V_62 ?
V_72 : V_73 ;
if ( V_71 != V_72 &&
V_2 -> V_18 . V_41 == V_45 )
return - V_40 ;
F_19 ( & V_7 ) ;
F_39 ( V_22 , & V_67 ) ;
memcpy ( & V_50 , V_22 -> V_74 +
F_40 ( V_22 ) , sizeof V_50 ) ;
F_41 (cma_dev, &dev_list, list) {
for ( V_69 = 1 ; V_69 <= V_16 -> V_19 -> V_75 ; ++ V_69 ) {
if ( F_42 ( V_16 -> V_19 , V_69 ) == V_71 ) {
if ( F_10 ( V_16 -> V_19 -> V_24 ) == V_76 &&
F_42 ( V_16 -> V_19 , V_69 ) == V_73 )
V_6 = F_29 ( V_16 -> V_19 , & V_67 , V_69 ) ;
else
V_6 = F_29 ( V_16 -> V_19 , & V_50 , V_69 ) ;
if ( ! V_6 ) {
V_2 -> V_18 . V_47 = V_69 ;
goto V_77;
}
}
}
}
V_77:
if ( ! V_6 )
F_8 ( V_2 , V_16 ) ;
F_21 ( & V_7 ) ;
return V_6 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_15 * V_16 , * V_78 ;
struct V_58 * V_21 ;
union V_49 V_50 , V_79 , * V_80 ;
T_3 V_81 , V_82 ;
T_1 V_83 ;
int V_51 ;
V_16 = NULL ;
V_21 = (struct V_58 * ) F_23 ( V_2 ) ;
V_80 = (union V_49 * ) & V_21 -> V_63 ;
V_81 = F_35 ( V_21 -> V_64 ) ;
F_41 (cur_dev, &dev_list, list) {
if ( F_10 ( V_78 -> V_19 -> V_24 ) != V_76 )
continue;
for ( V_83 = 1 ; V_83 <= V_78 -> V_19 -> V_75 ; ++ V_83 ) {
if ( F_44 ( V_78 -> V_19 , V_83 , V_81 , & V_82 ) )
continue;
for ( V_51 = 0 ; ! F_45 ( V_78 -> V_19 , V_83 , V_51 , & V_50 ) ; V_51 ++ ) {
if ( ! memcmp ( & V_50 , V_80 , sizeof( V_50 ) ) ) {
V_16 = V_78 ;
V_79 = V_50 ;
V_2 -> V_18 . V_47 = V_83 ;
goto V_84;
}
if ( ! V_16 && ( V_50 . V_85 . V_86 ==
V_80 -> V_85 . V_86 ) ) {
V_16 = V_78 ;
V_79 = V_50 ;
V_2 -> V_18 . V_47 = V_83 ;
}
}
}
}
if ( ! V_16 )
return - V_68 ;
V_84:
F_8 ( V_2 , V_16 ) ;
V_21 = (struct V_58 * ) F_22 ( V_2 ) ;
memcpy ( & V_21 -> V_63 , & V_79 , sizeof V_79 ) ;
F_32 ( V_21 , & V_2 -> V_18 . V_20 . V_21 . V_22 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( F_13 ( & V_2 -> V_17 ) )
F_14 ( & V_2 -> V_4 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
enum V_3 V_8 )
{
F_19 ( & V_2 -> V_87 ) ;
if ( V_2 -> V_8 != V_8 ) {
F_21 ( & V_2 -> V_87 ) ;
return - V_40 ;
}
return 0 ;
}
struct V_88 * F_48 ( T_4 V_89 ,
void * V_90 , enum V_91 V_41 ,
enum V_92 V_93 )
{
struct V_1 * V_2 ;
V_2 = F_49 ( sizeof *V_2 , V_94 ) ;
if ( ! V_2 )
return F_50 ( - V_95 ) ;
V_2 -> V_96 = F_51 ( V_97 ) ;
V_2 -> V_8 = V_98 ;
V_2 -> V_18 . V_90 = V_90 ;
V_2 -> V_18 . V_89 = V_89 ;
V_2 -> V_18 . V_41 = V_41 ;
V_2 -> V_18 . V_93 = V_93 ;
F_52 ( & V_2 -> V_7 ) ;
F_53 ( & V_2 -> V_99 ) ;
F_54 ( & V_2 -> V_4 ) ;
F_55 ( & V_2 -> V_17 , 1 ) ;
F_53 ( & V_2 -> V_87 ) ;
F_56 ( & V_2 -> V_100 ) ;
F_56 ( & V_2 -> V_101 ) ;
F_57 ( & V_2 -> V_102 , sizeof V_2 -> V_102 ) ;
return & V_2 -> V_18 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
struct V_105 V_106 ;
int V_107 , V_6 ;
V_106 . V_108 = V_109 ;
V_6 = F_59 ( & V_2 -> V_18 , & V_106 , & V_107 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_60 ( V_104 , & V_106 , V_107 ) ;
if ( V_6 )
return V_6 ;
V_106 . V_108 = V_110 ;
V_6 = F_60 ( V_104 , & V_106 , V_111 ) ;
if ( V_6 )
return V_6 ;
V_106 . V_108 = V_112 ;
V_106 . V_113 = 0 ;
V_6 = F_60 ( V_104 , & V_106 , V_111 | V_114 ) ;
return V_6 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
struct V_105 V_106 ;
int V_107 , V_6 ;
V_106 . V_108 = V_109 ;
V_6 = F_59 ( & V_2 -> V_18 , & V_106 , & V_107 ) ;
if ( V_6 )
return V_6 ;
return F_60 ( V_104 , & V_106 , V_107 ) ;
}
int F_62 ( struct V_88 * V_18 , struct V_115 * V_116 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 ;
struct V_103 * V_104 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( V_18 -> V_19 != V_116 -> V_19 )
return - V_40 ;
V_104 = F_63 ( V_116 , V_118 ) ;
if ( F_64 ( V_104 ) )
return F_65 ( V_104 ) ;
if ( V_18 -> V_93 == V_119 )
V_6 = F_58 ( V_2 , V_104 ) ;
else
V_6 = F_61 ( V_2 , V_104 ) ;
if ( V_6 )
goto V_52;
V_18 -> V_104 = V_104 ;
V_2 -> V_120 = V_104 -> V_120 ;
V_2 -> V_121 = ( V_104 -> V_121 != NULL ) ;
return 0 ;
V_52:
F_66 ( V_104 ) ;
return V_6 ;
}
void F_67 ( struct V_88 * V_18 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
F_19 ( & V_2 -> V_99 ) ;
F_66 ( V_2 -> V_18 . V_104 ) ;
V_2 -> V_18 . V_104 = NULL ;
F_21 ( & V_2 -> V_99 ) ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_122 * V_123 )
{
struct V_105 V_106 ;
int V_107 , V_6 ;
F_19 ( & V_2 -> V_99 ) ;
if ( ! V_2 -> V_18 . V_104 ) {
V_6 = 0 ;
goto V_77;
}
V_106 . V_108 = V_109 ;
V_6 = F_59 ( & V_2 -> V_18 , & V_106 , & V_107 ) ;
if ( V_6 )
goto V_77;
V_6 = F_60 ( V_2 -> V_18 . V_104 , & V_106 , V_107 ) ;
if ( V_6 )
goto V_77;
V_106 . V_108 = V_110 ;
V_6 = F_59 ( & V_2 -> V_18 , & V_106 , & V_107 ) ;
if ( V_6 )
goto V_77;
if ( V_123 )
V_106 . V_124 = V_123 -> V_125 ;
V_6 = F_60 ( V_2 -> V_18 . V_104 , & V_106 , V_107 ) ;
V_77:
F_21 ( & V_2 -> V_99 ) ;
return V_6 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_122 * V_123 )
{
struct V_105 V_106 ;
int V_107 , V_6 ;
F_19 ( & V_2 -> V_99 ) ;
if ( ! V_2 -> V_18 . V_104 ) {
V_6 = 0 ;
goto V_77;
}
V_106 . V_108 = V_112 ;
V_6 = F_59 ( & V_2 -> V_18 , & V_106 , & V_107 ) ;
if ( V_6 )
goto V_77;
if ( V_123 )
V_106 . V_126 = V_123 -> V_127 ;
V_6 = F_60 ( V_2 -> V_18 . V_104 , & V_106 , V_107 ) ;
V_77:
F_21 ( & V_2 -> V_99 ) ;
return V_6 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_105 V_106 ;
int V_6 ;
F_19 ( & V_2 -> V_99 ) ;
if ( ! V_2 -> V_18 . V_104 ) {
V_6 = 0 ;
goto V_77;
}
V_106 . V_108 = V_128 ;
V_6 = F_60 ( V_2 -> V_18 . V_104 , & V_106 , V_111 ) ;
V_77:
F_21 ( & V_2 -> V_99 ) ;
return V_6 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_105 * V_106 , int * V_107 )
{
struct V_60 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
int V_6 ;
T_3 V_81 ;
if ( F_42 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ) ==
V_72 )
V_81 = F_72 ( V_22 ) ;
else
V_81 = 0xffff ;
V_6 = F_44 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ,
V_81 , & V_106 -> V_129 ) ;
if ( V_6 )
return V_6 ;
V_106 -> V_47 = V_2 -> V_18 . V_47 ;
* V_107 = V_111 | V_130 | V_131 ;
if ( V_2 -> V_18 . V_93 == V_119 ) {
V_6 = F_25 ( V_2 , 0 ) ;
if ( V_6 )
return V_6 ;
V_106 -> V_37 = V_2 -> V_37 ;
* V_107 |= V_132 ;
} else {
V_106 -> V_133 = 0 ;
* V_107 |= V_134 ;
}
return 0 ;
}
int F_59 ( struct V_88 * V_18 , struct V_105 * V_106 ,
int * V_107 )
{
struct V_1 * V_2 ;
int V_6 = 0 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
switch ( F_10 ( V_2 -> V_18 . V_19 -> V_24 ) ) {
case V_76 :
if ( ! V_2 -> V_135 . V_32 || ( V_2 -> V_18 . V_93 == V_119 ) )
V_6 = F_71 ( V_2 , V_106 , V_107 ) ;
else
V_6 = F_73 ( V_2 -> V_135 . V_32 , V_106 ,
V_107 ) ;
if ( V_106 -> V_108 == V_110 )
V_106 -> V_136 = V_2 -> V_102 ;
break;
case V_137 :
if ( ! V_2 -> V_135 . V_138 ) {
V_106 -> V_133 = 0 ;
* V_107 = V_111 | V_134 ;
} else
V_6 = F_74 ( V_2 -> V_135 . V_138 , V_106 ,
V_107 ) ;
break;
default:
V_6 = - V_139 ;
break;
}
return V_6 ;
}
static inline int F_75 ( struct V_33 * V_21 )
{
switch ( V_21 -> V_65 ) {
case V_140 :
return F_76 ( ( (struct V_141 * ) V_21 ) -> V_142 . V_143 ) ;
case V_144 :
return F_77 ( & ( (struct V_145 * ) V_21 ) -> V_146 ) ;
case V_66 :
return F_78 ( & ( (struct V_58 * ) V_21 ) -> V_63 ) ;
default:
return 0 ;
}
}
static inline int F_79 ( struct V_33 * V_21 )
{
switch ( V_21 -> V_65 ) {
case V_140 :
return F_80 ( ( (struct V_141 * ) V_21 ) -> V_142 . V_143 ) ;
case V_144 :
return F_81 ( & ( (struct V_145 * ) V_21 ) -> V_146 ) ;
case V_66 :
return F_82 ( & ( (struct V_58 * ) V_21 ) -> V_63 ) ;
default:
return 0 ;
}
}
static inline int F_83 ( struct V_33 * V_21 )
{
return F_75 ( V_21 ) || F_79 ( V_21 ) ;
}
static int F_84 ( struct V_33 * V_147 , struct V_33 * V_148 )
{
if ( V_147 -> V_65 != V_148 -> V_65 )
return - 1 ;
switch ( V_147 -> V_65 ) {
case V_140 :
return ( (struct V_141 * ) V_147 ) -> V_142 . V_143 !=
( (struct V_141 * ) V_148 ) -> V_142 . V_143 ;
case V_144 :
return F_85 ( & ( (struct V_145 * ) V_147 ) -> V_146 ,
& ( (struct V_145 * ) V_148 ) -> V_146 ) ;
default:
return F_86 ( & ( (struct V_58 * ) V_147 ) -> V_63 ,
& ( (struct V_58 * ) V_148 ) -> V_63 ) ;
}
}
static T_5 F_87 ( struct V_33 * V_21 )
{
struct V_58 * V_59 ;
switch ( V_21 -> V_65 ) {
case V_140 :
return ( (struct V_141 * ) V_21 ) -> V_149 ;
case V_144 :
return ( (struct V_145 * ) V_21 ) -> V_150 ;
case V_66 :
V_59 = (struct V_58 * ) V_21 ;
return F_88 ( ( T_3 ) ( F_89 ( V_59 -> V_151 ) &
F_89 ( V_59 -> V_152 ) ) ) ;
default:
return 0 ;
}
}
static inline int F_90 ( struct V_33 * V_21 )
{
return ! F_87 ( V_21 ) ;
}
static void F_91 ( struct V_88 * V_18 , struct V_88 * V_153 ,
struct V_154 * V_155 )
{
struct V_58 * V_156 , * V_32 ;
V_156 = (struct V_58 * ) & V_153 -> V_20 . V_21 . V_34 ;
V_32 = (struct V_58 * ) & V_18 -> V_20 . V_21 . V_34 ;
V_32 -> V_157 = V_156 -> V_157 ;
V_32 -> V_64 = V_155 -> V_81 ;
V_32 -> V_158 = V_155 -> V_159 ;
memcpy ( & V_32 -> V_63 , & V_155 -> V_79 , 16 ) ;
V_32 -> V_151 = V_156 -> V_151 ;
V_32 -> V_152 = F_92 ( 0xffffffffffffffffULL ) ;
V_32 -> V_160 = V_156 -> V_160 ;
V_32 = (struct V_58 * ) & V_18 -> V_20 . V_21 . V_35 ;
V_32 -> V_157 = V_156 -> V_157 ;
V_32 -> V_64 = V_155 -> V_81 ;
V_32 -> V_158 = V_155 -> V_159 ;
memcpy ( & V_32 -> V_63 , & V_155 -> V_80 , 16 ) ;
}
static void F_93 ( struct V_88 * V_18 , struct V_88 * V_153 ,
struct V_11 * V_12 )
{
struct V_141 * V_161 , * V_162 ;
V_161 = (struct V_141 * ) & V_153 -> V_20 . V_21 . V_34 ;
V_162 = (struct V_141 * ) & V_18 -> V_20 . V_21 . V_34 ;
V_162 -> V_163 = V_161 -> V_163 ;
V_162 -> V_142 . V_143 = V_12 -> V_35 . V_162 . V_21 ;
V_162 -> V_149 = V_161 -> V_149 ;
V_162 = (struct V_141 * ) & V_18 -> V_20 . V_21 . V_35 ;
V_162 -> V_163 = V_161 -> V_163 ;
V_162 -> V_142 . V_143 = V_12 -> V_34 . V_162 . V_21 ;
V_162 -> V_149 = V_12 -> V_69 ;
}
static void F_94 ( struct V_88 * V_18 , struct V_88 * V_153 ,
struct V_11 * V_12 )
{
struct V_145 * V_164 , * V_165 ;
V_164 = (struct V_145 * ) & V_153 -> V_20 . V_21 . V_34 ;
V_165 = (struct V_145 * ) & V_18 -> V_20 . V_21 . V_34 ;
V_165 -> V_166 = V_164 -> V_166 ;
V_165 -> V_146 = V_12 -> V_35 . V_165 ;
V_165 -> V_150 = V_164 -> V_150 ;
V_165 = (struct V_145 * ) & V_18 -> V_20 . V_21 . V_35 ;
V_165 -> V_166 = V_164 -> V_166 ;
V_165 -> V_146 = V_12 -> V_34 . V_165 ;
V_165 -> V_150 = V_12 -> V_69 ;
}
static int F_95 ( struct V_88 * V_18 , struct V_88 * V_153 ,
struct V_167 * V_168 )
{
struct V_11 * V_12 ;
if ( ( V_153 -> V_20 . V_21 . V_34 . V_36 == V_66 ) &&
( V_168 -> V_169 == V_170 ) ) {
F_91 ( V_18 , V_153 , V_168 -> V_171 . V_172 . V_173 ) ;
return 0 ;
}
V_12 = V_168 -> V_174 ;
if ( V_12 -> V_175 != V_176 )
return - V_40 ;
switch ( F_6 ( V_12 ) ) {
case 4 :
F_93 ( V_18 , V_153 , V_12 ) ;
break;
case 6 :
F_94 ( V_18 , V_153 , V_12 ) ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static inline int F_96 ( struct V_1 * V_2 )
{
return F_24 ( V_2 ) == V_66 ? 0 : sizeof( struct V_11 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
switch ( F_42 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ) ) {
case V_72 :
if ( V_2 -> V_177 )
F_98 ( V_2 -> V_178 , V_2 -> V_177 ) ;
break;
default:
break;
}
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_1 * V_179 ;
F_19 ( & V_7 ) ;
F_20 ( & V_2 -> V_25 ) ;
while ( ! F_100 ( & V_2 -> V_100 ) ) {
V_179 = F_101 ( V_2 -> V_100 . V_180 ,
struct V_1 , V_100 ) ;
F_102 ( & V_179 -> V_25 ) ;
F_20 ( & V_179 -> V_100 ) ;
F_21 ( & V_7 ) ;
F_103 ( & V_179 -> V_18 ) ;
F_19 ( & V_7 ) ;
}
F_21 ( & V_7 ) ;
}
static void F_104 ( struct V_1 * V_2 ,
enum V_3 V_8 )
{
switch ( V_8 ) {
case V_181 :
F_105 ( & V_2 -> V_18 . V_20 . V_21 . V_22 ) ;
break;
case V_182 :
F_97 ( V_2 ) ;
break;
case V_183 :
if ( F_83 ( F_22 ( V_2 ) ) && ! V_2 -> V_16 )
F_99 ( V_2 ) ;
break;
default:
break;
}
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_184 * V_185 = V_2 -> V_185 ;
if ( ! V_185 )
return;
F_19 ( & V_7 ) ;
F_107 ( & V_2 -> V_186 ) ;
if ( F_108 ( & V_185 -> V_187 ) ) {
F_109 ( V_185 -> V_41 , V_185 -> V_69 ) ;
F_17 ( V_185 ) ;
}
F_21 ( & V_7 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
while ( ! F_100 ( & V_2 -> V_101 ) ) {
V_29 = F_16 ( V_2 -> V_101 . V_180 ,
struct V_28 , V_25 ) ;
F_20 ( & V_29 -> V_25 ) ;
switch ( F_42 ( V_2 -> V_16 -> V_19 , V_2 -> V_18 . V_47 ) ) {
case V_72 :
F_111 ( V_29 -> V_31 . V_32 ) ;
F_17 ( V_29 ) ;
break;
case V_73 :
F_112 ( & V_29 -> V_30 , F_15 ) ;
break;
default:
break;
}
}
}
void F_103 ( struct V_88 * V_18 )
{
struct V_1 * V_2 ;
enum V_3 V_8 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
V_8 = F_5 ( V_2 , V_188 ) ;
F_104 ( V_2 , V_8 ) ;
F_19 ( & V_2 -> V_87 ) ;
F_21 ( & V_2 -> V_87 ) ;
if ( V_2 -> V_16 ) {
switch ( F_10 ( V_2 -> V_18 . V_19 -> V_24 ) ) {
case V_76 :
if ( V_2 -> V_135 . V_32 )
F_113 ( V_2 -> V_135 . V_32 ) ;
break;
case V_137 :
if ( V_2 -> V_135 . V_138 )
F_114 ( V_2 -> V_135 . V_138 ) ;
break;
default:
break;
}
F_110 ( V_2 ) ;
F_18 ( V_2 ) ;
}
F_106 ( V_2 ) ;
F_46 ( V_2 ) ;
F_115 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_189 )
F_46 ( V_2 -> V_18 . V_90 ) ;
F_17 ( V_2 -> V_18 . V_20 . V_190 ) ;
F_17 ( V_2 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_68 ( V_2 , NULL ) ;
if ( V_6 )
goto V_191;
V_6 = F_69 ( V_2 , NULL ) ;
if ( V_6 )
goto V_191;
V_6 = F_117 ( V_2 -> V_135 . V_32 , NULL , 0 ) ;
if ( V_6 )
goto V_191;
return 0 ;
V_191:
F_70 ( V_2 ) ;
F_118 ( V_2 -> V_135 . V_32 , V_192 ,
NULL , 0 , NULL , 0 ) ;
return V_6 ;
}
static void F_119 ( struct V_193 * V_169 ,
struct V_194 * V_195 ,
void * V_174 )
{
V_169 -> V_171 . V_196 . V_174 = V_174 ;
V_169 -> V_171 . V_196 . V_197 = V_198 ;
V_169 -> V_171 . V_196 . V_125 = V_195 -> V_125 ;
V_169 -> V_171 . V_196 . V_127 = V_195 -> V_127 ;
V_169 -> V_171 . V_196 . V_199 = V_195 -> V_199 ;
V_169 -> V_171 . V_196 . V_200 = V_195 -> V_200 ;
V_169 -> V_171 . V_196 . V_121 = V_195 -> V_121 ;
V_169 -> V_171 . V_196 . V_120 = V_195 -> V_201 ;
}
static int F_120 ( struct V_202 * V_135 , struct V_167 * V_168 )
{
struct V_1 * V_2 = V_135 -> V_90 ;
struct V_193 V_169 ;
int V_6 = 0 ;
if ( ( V_168 -> V_169 != V_203 &&
F_47 ( V_2 , V_204 ) ) ||
( V_168 -> V_169 == V_203 &&
F_47 ( V_2 , V_205 ) ) )
return 0 ;
memset ( & V_169 , 0 , sizeof V_169 ) ;
switch ( V_168 -> V_169 ) {
case V_206 :
case V_207 :
V_169 . V_169 = V_208 ;
V_169 . V_209 = - V_210 ;
break;
case V_211 :
if ( V_2 -> V_18 . V_104 ) {
V_169 . V_209 = F_116 ( V_2 ) ;
V_169 . V_169 = V_169 . V_209 ? V_212 :
V_213 ;
} else {
V_169 . V_169 = V_214 ;
}
F_119 ( & V_169 , & V_168 -> V_171 . V_215 ,
V_168 -> V_174 ) ;
break;
case V_216 :
case V_217 :
V_169 . V_169 = V_213 ;
break;
case V_218 :
V_169 . V_209 = - V_210 ;
case V_219 :
case V_220 :
if ( ! F_4 ( V_2 , V_204 ,
V_205 ) )
goto V_77;
V_169 . V_169 = V_221 ;
break;
case V_203 :
V_169 . V_169 = V_222 ;
break;
case V_223 :
goto V_77;
case V_224 :
F_70 ( V_2 ) ;
V_169 . V_209 = V_168 -> V_171 . V_225 . V_226 ;
V_169 . V_169 = V_227 ;
V_169 . V_171 . V_196 . V_174 = V_168 -> V_174 ;
V_169 . V_171 . V_196 . V_197 = V_228 ;
break;
default:
F_121 ( V_229 L_1 ,
V_168 -> V_169 ) ;
goto V_77;
}
V_6 = V_2 -> V_18 . V_89 ( & V_2 -> V_18 , & V_169 ) ;
if ( V_6 ) {
V_2 -> V_135 . V_32 = NULL ;
F_5 ( V_2 , V_188 ) ;
F_21 ( & V_2 -> V_87 ) ;
F_103 ( & V_2 -> V_18 ) ;
return V_6 ;
}
V_77:
F_21 ( & V_2 -> V_87 ) ;
return V_6 ;
}
static struct V_1 * F_122 ( struct V_88 * V_153 ,
struct V_167 * V_168 )
{
struct V_1 * V_2 ;
struct V_88 * V_18 ;
struct V_230 * V_231 ;
int V_6 ;
V_18 = F_48 ( V_153 -> V_89 , V_153 -> V_90 ,
V_153 -> V_41 , V_168 -> V_171 . V_172 . V_93 ) ;
if ( F_64 ( V_18 ) )
return NULL ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( F_95 ( V_18 , V_153 , V_168 ) )
goto V_52;
V_231 = & V_18 -> V_20 ;
V_231 -> V_232 = V_168 -> V_171 . V_172 . V_233 ? 2 : 1 ;
V_231 -> V_190 = F_123 ( sizeof * V_231 -> V_190 * V_231 -> V_232 ,
V_94 ) ;
if ( ! V_231 -> V_190 )
goto V_52;
V_231 -> V_190 [ 0 ] = * V_168 -> V_171 . V_172 . V_173 ;
if ( V_231 -> V_232 == 2 )
V_231 -> V_190 [ 1 ] = * V_168 -> V_171 . V_172 . V_233 ;
if ( F_83 ( F_22 ( V_2 ) ) ) {
V_231 -> V_21 . V_22 . V_61 = V_62 ;
F_33 ( & V_231 -> V_21 . V_22 , & V_231 -> V_190 [ 0 ] . V_79 ) ;
F_34 ( & V_231 -> V_21 . V_22 , F_124 ( V_231 -> V_190 [ 0 ] . V_81 ) ) ;
} else {
V_6 = F_36 ( F_22 ( V_2 ) , & V_231 -> V_21 . V_22 ) ;
if ( V_6 )
goto V_52;
}
F_125 ( & V_231 -> V_21 . V_22 , & V_231 -> V_190 [ 0 ] . V_80 ) ;
V_2 -> V_8 = V_204 ;
return V_2 ;
V_52:
F_103 ( V_18 ) ;
return NULL ;
}
static struct V_1 * F_126 ( struct V_88 * V_153 ,
struct V_167 * V_168 )
{
struct V_1 * V_2 ;
struct V_88 * V_18 ;
int V_6 ;
V_18 = F_48 ( V_153 -> V_89 , V_153 -> V_90 ,
V_153 -> V_41 , V_119 ) ;
if ( F_64 ( V_18 ) )
return NULL ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( F_95 ( V_18 , V_153 , V_168 ) )
goto V_52;
if ( ! F_83 ( (struct V_33 * ) & V_18 -> V_20 . V_21 . V_34 ) ) {
V_6 = F_36 ( F_22 ( V_2 ) , & V_18 -> V_20 . V_21 . V_22 ) ;
if ( V_6 )
goto V_52;
}
V_2 -> V_8 = V_204 ;
return V_2 ;
V_52:
F_103 ( V_18 ) ;
return NULL ;
}
static void F_127 ( struct V_193 * V_169 ,
struct V_234 * V_235 ,
void * V_174 , int V_236 )
{
V_169 -> V_171 . V_196 . V_174 = V_174 + V_236 ;
V_169 -> V_171 . V_196 . V_197 = V_237 - V_236 ;
V_169 -> V_171 . V_196 . V_125 = V_235 -> V_125 ;
V_169 -> V_171 . V_196 . V_127 = V_235 -> V_127 ;
V_169 -> V_171 . V_196 . V_199 = V_235 -> V_199 ;
V_169 -> V_171 . V_196 . V_238 = V_235 -> V_238 ;
V_169 -> V_171 . V_196 . V_200 = V_235 -> V_200 ;
V_169 -> V_171 . V_196 . V_121 = V_235 -> V_121 ;
V_169 -> V_171 . V_196 . V_120 = V_235 -> V_201 ;
}
static int F_128 ( struct V_88 * V_18 , struct V_167 * V_168 )
{
return ( ( ( V_168 -> V_169 == V_170 ) &&
( V_168 -> V_171 . V_172 . V_93 == V_18 -> V_93 ) ) ||
( ( V_168 -> V_169 == V_239 ) &&
( V_18 -> V_93 == V_119 ) ) ||
( ! V_18 -> V_93 ) ) ;
}
static int F_129 ( struct V_202 * V_135 , struct V_167 * V_168 )
{
struct V_1 * V_153 , * V_240 ;
struct V_193 V_169 ;
int V_236 , V_6 ;
V_153 = V_135 -> V_90 ;
if ( ! F_128 ( & V_153 -> V_18 , V_168 ) )
return - V_40 ;
if ( F_47 ( V_153 , V_183 ) )
return - V_241 ;
memset ( & V_169 , 0 , sizeof V_169 ) ;
V_236 = F_96 ( V_153 ) ;
V_169 . V_169 = V_242 ;
if ( V_168 -> V_169 == V_239 ) {
V_240 = F_126 ( & V_153 -> V_18 , V_168 ) ;
V_169 . V_171 . V_243 . V_174 = V_168 -> V_174 + V_236 ;
V_169 . V_171 . V_243 . V_197 =
V_244 - V_236 ;
} else {
V_240 = F_122 ( & V_153 -> V_18 , V_168 ) ;
F_127 ( & V_169 , & V_168 -> V_171 . V_172 ,
V_168 -> V_174 , V_236 ) ;
}
if ( ! V_240 ) {
V_6 = - V_95 ;
goto V_245;
}
F_130 ( & V_240 -> V_87 , V_246 ) ;
V_6 = F_38 ( V_240 ) ;
if ( V_6 )
goto V_247;
V_240 -> V_135 . V_32 = V_135 ;
V_135 -> V_90 = V_240 ;
V_135 -> V_248 = F_120 ;
F_9 ( & V_240 -> V_17 ) ;
V_6 = V_240 -> V_18 . V_89 ( & V_240 -> V_18 , & V_169 ) ;
if ( V_6 )
goto V_249;
F_19 ( & V_7 ) ;
if ( F_1 ( V_240 , V_204 ) && ( V_240 -> V_18 . V_93 != V_119 ) )
F_131 ( V_135 , V_250 , NULL , 0 ) ;
F_21 ( & V_7 ) ;
F_21 ( & V_240 -> V_87 ) ;
F_21 ( & V_153 -> V_87 ) ;
F_46 ( V_240 ) ;
return 0 ;
V_249:
F_46 ( V_240 ) ;
V_240 -> V_135 . V_32 = NULL ;
V_247:
F_5 ( V_240 , V_188 ) ;
F_21 ( & V_240 -> V_87 ) ;
V_245:
F_21 ( & V_153 -> V_87 ) ;
if ( V_240 )
F_103 ( & V_240 -> V_18 ) ;
return V_6 ;
}
T_6 F_132 ( struct V_88 * V_18 , struct V_33 * V_21 )
{
if ( V_21 -> V_65 == V_66 )
return ( (struct V_58 * ) V_21 ) -> V_151 ;
return F_92 ( ( ( V_251 ) V_18 -> V_41 << 16 ) + F_124 ( F_87 ( V_21 ) ) ) ;
}
static void F_133 ( enum V_91 V_41 , struct V_33 * V_21 ,
struct V_252 * V_253 )
{
struct V_11 * V_254 , * V_255 ;
T_7 V_256 ;
struct V_257 V_258 ;
memset ( V_253 , 0 , sizeof *V_253 ) ;
V_254 = ( void * ) V_253 -> V_259 ;
V_255 = ( void * ) V_253 -> V_260 ;
switch ( V_21 -> V_65 ) {
case V_140 :
V_256 = ( (struct V_141 * ) V_21 ) -> V_142 . V_143 ;
F_7 ( V_254 , 4 ) ;
F_7 ( V_255 , 0xF ) ;
if ( ! F_83 ( V_21 ) ) {
V_254 -> V_35 . V_162 . V_21 = V_256 ;
V_255 -> V_35 . V_162 . V_21 = F_134 ( ~ 0 ) ;
}
break;
case V_144 :
V_258 = ( (struct V_145 * ) V_21 ) -> V_146 ;
F_7 ( V_254 , 6 ) ;
F_7 ( V_255 , 0xF ) ;
if ( ! F_83 ( V_21 ) ) {
V_254 -> V_35 . V_165 = V_258 ;
memset ( & V_255 -> V_35 . V_165 , 0xFF ,
sizeof V_255 -> V_35 . V_165 ) ;
}
break;
default:
break;
}
}
static int F_135 ( struct V_261 * V_262 , struct V_263 * V_264 )
{
struct V_1 * V_2 = V_262 -> V_90 ;
struct V_193 V_169 ;
struct V_141 * sin ;
int V_6 = 0 ;
if ( F_47 ( V_2 , V_204 ) )
return 0 ;
memset ( & V_169 , 0 , sizeof V_169 ) ;
switch ( V_264 -> V_169 ) {
case V_265 :
V_169 . V_169 = V_221 ;
break;
case V_266 :
sin = (struct V_141 * ) F_22 ( V_2 ) ;
* sin = V_264 -> V_267 ;
sin = (struct V_141 * ) F_23 ( V_2 ) ;
* sin = V_264 -> V_268 ;
switch ( V_264 -> V_209 ) {
case 0 :
V_169 . V_169 = V_213 ;
V_169 . V_171 . V_196 . V_127 = V_264 -> V_269 ;
V_169 . V_171 . V_196 . V_125 = V_264 -> V_270 ;
break;
case - V_271 :
case - V_272 :
V_169 . V_169 = V_227 ;
break;
case - V_210 :
V_169 . V_169 = V_208 ;
break;
default:
V_169 . V_169 = V_212 ;
break;
}
break;
case V_273 :
V_169 . V_169 = V_213 ;
V_169 . V_171 . V_196 . V_127 = V_264 -> V_269 ;
V_169 . V_171 . V_196 . V_125 = V_264 -> V_270 ;
break;
default:
F_136 ( 1 ) ;
}
V_169 . V_209 = V_264 -> V_209 ;
V_169 . V_171 . V_196 . V_174 = V_264 -> V_174 ;
V_169 . V_171 . V_196 . V_197 = V_264 -> V_197 ;
V_6 = V_2 -> V_18 . V_89 ( & V_2 -> V_18 , & V_169 ) ;
if ( V_6 ) {
V_2 -> V_135 . V_138 = NULL ;
F_5 ( V_2 , V_188 ) ;
F_21 ( & V_2 -> V_87 ) ;
F_103 ( & V_2 -> V_18 ) ;
return V_6 ;
}
F_21 ( & V_2 -> V_87 ) ;
return V_6 ;
}
static int F_137 ( struct V_261 * V_135 ,
struct V_263 * V_264 )
{
struct V_88 * V_274 ;
struct V_1 * V_153 , * V_240 ;
struct V_141 * sin ;
struct V_275 * V_276 = NULL ;
struct V_193 V_169 ;
int V_6 ;
struct V_277 V_278 ;
V_153 = V_135 -> V_90 ;
if ( F_47 ( V_153 , V_183 ) )
return - V_241 ;
V_274 = F_48 ( V_153 -> V_18 . V_89 ,
V_153 -> V_18 . V_90 ,
V_279 , V_280 ) ;
if ( F_64 ( V_274 ) ) {
V_6 = - V_95 ;
goto V_77;
}
V_240 = F_16 ( V_274 , struct V_1 , V_18 ) ;
F_130 ( & V_240 -> V_87 , V_246 ) ;
V_240 -> V_8 = V_204 ;
V_276 = F_138 ( & V_281 , V_264 -> V_267 . V_142 . V_143 ) ;
if ( ! V_276 ) {
V_6 = - V_57 ;
F_21 ( & V_240 -> V_87 ) ;
F_103 ( V_274 ) ;
goto V_77;
}
V_6 = F_139 ( & V_240 -> V_18 . V_20 . V_21 . V_22 , V_276 , NULL ) ;
if ( V_6 ) {
F_21 ( & V_240 -> V_87 ) ;
F_103 ( V_274 ) ;
goto V_77;
}
V_6 = F_38 ( V_240 ) ;
if ( V_6 ) {
F_21 ( & V_240 -> V_87 ) ;
F_103 ( V_274 ) ;
goto V_77;
}
V_240 -> V_135 . V_138 = V_135 ;
V_135 -> V_90 = V_240 ;
V_135 -> V_248 = F_135 ;
sin = (struct V_141 * ) F_22 ( V_240 ) ;
* sin = V_264 -> V_267 ;
sin = (struct V_141 * ) F_23 ( V_240 ) ;
* sin = V_264 -> V_268 ;
V_6 = F_140 ( V_240 -> V_18 . V_19 , & V_278 ) ;
if ( V_6 ) {
F_21 ( & V_240 -> V_87 ) ;
F_103 ( V_274 ) ;
goto V_77;
}
memset ( & V_169 , 0 , sizeof V_169 ) ;
V_169 . V_169 = V_242 ;
V_169 . V_171 . V_196 . V_174 = V_264 -> V_174 ;
V_169 . V_171 . V_196 . V_197 = V_264 -> V_197 ;
V_169 . V_171 . V_196 . V_127 = V_264 -> V_269 ;
V_169 . V_171 . V_196 . V_125 = V_264 -> V_270 ;
F_9 ( & V_240 -> V_17 ) ;
V_6 = V_240 -> V_18 . V_89 ( & V_240 -> V_18 , & V_169 ) ;
if ( V_6 ) {
V_240 -> V_135 . V_138 = NULL ;
F_5 ( V_240 , V_188 ) ;
F_21 ( & V_240 -> V_87 ) ;
F_46 ( V_240 ) ;
F_103 ( & V_240 -> V_18 ) ;
goto V_77;
}
F_21 ( & V_240 -> V_87 ) ;
F_46 ( V_240 ) ;
V_77:
if ( V_276 )
F_141 ( V_276 ) ;
F_21 ( & V_153 -> V_87 ) ;
return V_6 ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_252 V_282 ;
struct V_33 * V_21 ;
struct V_202 * V_18 ;
T_6 V_283 ;
int V_6 ;
V_18 = F_143 ( V_2 -> V_18 . V_19 , F_129 , V_2 ) ;
if ( F_64 ( V_18 ) )
return F_65 ( V_18 ) ;
V_2 -> V_135 . V_32 = V_18 ;
V_21 = F_22 ( V_2 ) ;
V_283 = F_132 ( & V_2 -> V_18 , V_21 ) ;
if ( F_83 ( V_21 ) && ! V_2 -> V_284 )
V_6 = F_144 ( V_2 -> V_135 . V_32 , V_283 , 0 , NULL ) ;
else {
F_133 ( V_2 -> V_18 . V_41 , V_21 , & V_282 ) ;
V_6 = F_144 ( V_2 -> V_135 . V_32 , V_283 , 0 , & V_282 ) ;
}
if ( V_6 ) {
F_113 ( V_2 -> V_135 . V_32 ) ;
V_2 -> V_135 . V_32 = NULL ;
}
return V_6 ;
}
static int F_145 ( struct V_1 * V_2 , int V_285 )
{
int V_6 ;
struct V_141 * sin ;
struct V_261 * V_18 ;
V_18 = F_146 ( V_2 -> V_18 . V_19 ,
F_137 ,
V_2 ) ;
if ( F_64 ( V_18 ) )
return F_65 ( V_18 ) ;
V_2 -> V_135 . V_138 = V_18 ;
sin = (struct V_141 * ) F_22 ( V_2 ) ;
V_2 -> V_135 . V_138 -> V_267 = * sin ;
V_6 = F_147 ( V_2 -> V_135 . V_138 , V_285 ) ;
if ( V_6 ) {
F_114 ( V_2 -> V_135 . V_138 ) ;
V_2 -> V_135 . V_138 = NULL ;
}
return V_6 ;
}
static int F_148 ( struct V_88 * V_18 ,
struct V_193 * V_169 )
{
struct V_1 * V_2 = V_18 -> V_90 ;
V_18 -> V_90 = V_2 -> V_18 . V_90 ;
V_18 -> V_89 = V_2 -> V_18 . V_89 ;
return V_2 -> V_18 . V_89 ( V_18 , V_169 ) ;
}
static void F_149 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_1 * V_179 ;
struct V_88 * V_18 ;
int V_6 ;
if ( F_24 ( V_2 ) == V_66 &&
F_10 ( V_16 -> V_19 -> V_24 ) != V_76 )
return;
V_18 = F_48 ( F_148 , V_2 , V_2 -> V_18 . V_41 ,
V_2 -> V_18 . V_93 ) ;
if ( F_64 ( V_18 ) )
return;
V_179 = F_16 ( V_18 , struct V_1 , V_18 ) ;
V_179 -> V_8 = V_286 ;
memcpy ( F_22 ( V_179 ) , F_22 ( V_2 ) ,
F_150 ( F_22 ( V_2 ) ) ) ;
F_8 ( V_179 , V_16 ) ;
F_11 ( & V_179 -> V_100 , & V_2 -> V_100 ) ;
F_9 ( & V_2 -> V_17 ) ;
V_179 -> V_189 = 1 ;
V_179 -> V_284 = V_2 -> V_284 ;
V_6 = F_151 ( V_18 , V_2 -> V_285 ) ;
if ( V_6 )
F_121 ( V_287 L_2
L_3 , V_6 , V_16 -> V_19 -> V_288 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
F_19 ( & V_7 ) ;
F_11 ( & V_2 -> V_25 , & V_289 ) ;
F_41 (cma_dev, &dev_list, list)
F_149 ( V_2 , V_16 ) ;
F_21 ( & V_7 ) ;
}
void F_153 ( struct V_88 * V_18 , int V_290 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
V_2 -> V_290 = ( T_1 ) V_290 ;
}
static void F_154 ( int V_209 , struct V_154 * V_190 ,
void * V_90 )
{
struct V_291 * V_292 = V_90 ;
struct V_230 * V_20 ;
V_20 = & V_292 -> V_18 -> V_18 . V_20 ;
if ( ! V_209 ) {
V_20 -> V_232 = 1 ;
* V_20 -> V_190 = * V_190 ;
} else {
V_292 -> V_293 = V_182 ;
V_292 -> V_294 = V_295 ;
V_292 -> V_169 . V_169 = V_296 ;
V_292 -> V_169 . V_209 = V_209 ;
}
F_155 ( V_297 , & V_292 -> V_292 ) ;
}
static int F_156 ( struct V_1 * V_2 , int V_298 ,
struct V_291 * V_292 )
{
struct V_60 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
struct V_154 V_190 ;
T_8 V_299 ;
struct V_145 * V_300 ;
struct V_58 * V_59 ;
memset ( & V_190 , 0 , sizeof V_190 ) ;
F_157 ( V_22 , & V_190 . V_79 ) ;
F_158 ( V_22 , & V_190 . V_80 ) ;
V_190 . V_81 = F_159 ( F_72 ( V_22 ) ) ;
V_190 . V_301 = 1 ;
V_190 . V_302 = 1 ;
V_190 . V_303 = F_132 ( & V_2 -> V_18 , F_23 ( V_2 ) ) ;
V_299 = V_304 | V_305 |
V_306 | V_307 |
V_308 | V_309 ;
switch ( F_24 ( V_2 ) ) {
case V_140 :
V_190 . V_310 = F_159 ( ( T_3 ) V_2 -> V_290 ) ;
V_299 |= V_311 ;
break;
case V_144 :
V_300 = (struct V_145 * ) F_22 ( V_2 ) ;
V_190 . V_312 = ( T_1 ) ( F_28 ( V_300 -> V_313 ) >> 20 ) ;
V_299 |= V_314 ;
break;
case V_66 :
V_59 = (struct V_58 * ) F_22 ( V_2 ) ;
V_190 . V_312 = ( T_1 ) ( F_28 ( V_59 -> V_158 ) >> 20 ) ;
V_299 |= V_314 ;
break;
}
V_2 -> V_178 = F_160 ( & V_315 , V_2 -> V_18 . V_19 ,
V_2 -> V_18 . V_47 , & V_190 ,
V_299 , V_298 ,
V_94 , F_154 ,
V_292 , & V_2 -> V_177 ) ;
return ( V_2 -> V_178 < 0 ) ? V_2 -> V_178 : 0 ;
}
static void F_161 ( struct V_316 * V_317 )
{
struct V_291 * V_292 = F_16 ( V_317 , struct V_291 , V_292 ) ;
struct V_1 * V_2 = V_292 -> V_18 ;
int V_318 = 0 ;
F_19 ( & V_2 -> V_87 ) ;
if ( ! F_4 ( V_2 , V_292 -> V_293 , V_292 -> V_294 ) )
goto V_77;
if ( V_2 -> V_18 . V_89 ( & V_2 -> V_18 , & V_292 -> V_169 ) ) {
F_5 ( V_2 , V_188 ) ;
V_318 = 1 ;
}
V_77:
F_21 ( & V_2 -> V_87 ) ;
F_46 ( V_2 ) ;
if ( V_318 )
F_103 ( & V_2 -> V_18 ) ;
F_17 ( V_292 ) ;
}
static void F_162 ( struct V_316 * V_317 )
{
struct V_319 * V_292 = F_16 ( V_317 , struct V_319 , V_292 ) ;
struct V_1 * V_2 = V_292 -> V_18 ;
int V_318 = 0 ;
F_19 ( & V_2 -> V_87 ) ;
if ( V_2 -> V_8 == V_188 ||
V_2 -> V_8 == V_320 )
goto V_77;
if ( V_2 -> V_18 . V_89 ( & V_2 -> V_18 , & V_292 -> V_169 ) ) {
F_5 ( V_2 , V_188 ) ;
V_318 = 1 ;
}
V_77:
F_21 ( & V_2 -> V_87 ) ;
F_46 ( V_2 ) ;
if ( V_318 )
F_103 ( & V_2 -> V_18 ) ;
F_17 ( V_292 ) ;
}
static int F_163 ( struct V_1 * V_2 , int V_298 )
{
struct V_230 * V_20 = & V_2 -> V_18 . V_20 ;
struct V_291 * V_292 ;
int V_6 ;
V_292 = F_49 ( sizeof *V_292 , V_94 ) ;
if ( ! V_292 )
return - V_95 ;
V_292 -> V_18 = V_2 ;
F_164 ( & V_292 -> V_292 , F_161 ) ;
V_292 -> V_293 = V_182 ;
V_292 -> V_294 = V_321 ;
V_292 -> V_169 . V_169 = V_322 ;
V_20 -> V_190 = F_123 ( sizeof * V_20 -> V_190 , V_94 ) ;
if ( ! V_20 -> V_190 ) {
V_6 = - V_95 ;
goto V_245;
}
V_6 = F_156 ( V_2 , V_298 , V_292 ) ;
if ( V_6 )
goto V_247;
return 0 ;
V_247:
F_17 ( V_20 -> V_190 ) ;
V_20 -> V_190 = NULL ;
V_245:
F_17 ( V_292 ) ;
return V_6 ;
}
int F_165 ( struct V_88 * V_18 ,
struct V_154 * V_190 , int V_232 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_4 ( V_2 , V_295 ,
V_321 ) )
return - V_40 ;
V_18 -> V_20 . V_190 = F_166 ( V_190 , sizeof *V_190 * V_232 ,
V_94 ) ;
if ( ! V_18 -> V_20 . V_190 ) {
V_6 = - V_95 ;
goto V_52;
}
V_18 -> V_20 . V_232 = V_232 ;
return 0 ;
V_52:
F_4 ( V_2 , V_321 , V_295 ) ;
return V_6 ;
}
static int F_167 ( struct V_1 * V_2 , int V_298 )
{
struct V_291 * V_292 ;
V_292 = F_49 ( sizeof *V_292 , V_94 ) ;
if ( ! V_292 )
return - V_95 ;
V_292 -> V_18 = V_2 ;
F_164 ( & V_292 -> V_292 , F_161 ) ;
V_292 -> V_293 = V_182 ;
V_292 -> V_294 = V_321 ;
V_292 -> V_169 . V_169 = V_322 ;
F_155 ( V_297 , & V_292 -> V_292 ) ;
return 0 ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_230 * V_20 = & V_2 -> V_18 . V_20 ;
struct V_323 * V_21 = & V_20 -> V_21 ;
struct V_291 * V_292 ;
int V_6 ;
struct V_275 * V_324 = NULL ;
T_3 V_325 ;
V_292 = F_49 ( sizeof *V_292 , V_94 ) ;
if ( ! V_292 )
return - V_95 ;
V_292 -> V_18 = V_2 ;
F_164 ( & V_292 -> V_292 , F_161 ) ;
V_20 -> V_190 = F_49 ( sizeof * V_20 -> V_190 , V_94 ) ;
if ( ! V_20 -> V_190 ) {
V_6 = - V_95 ;
goto V_245;
}
V_20 -> V_232 = 1 ;
if ( V_21 -> V_22 . V_326 )
V_324 = F_169 ( & V_281 , V_21 -> V_22 . V_326 ) ;
if ( ! V_324 ) {
V_6 = - V_68 ;
goto V_247;
}
V_325 = F_170 ( V_324 ) ;
F_171 ( & V_20 -> V_190 -> V_79 , V_21 -> V_22 . V_74 , V_325 ) ;
F_171 ( & V_20 -> V_190 -> V_80 , V_21 -> V_22 . V_327 , V_325 ) ;
V_20 -> V_190 -> V_328 = 1 ;
V_20 -> V_190 -> V_302 = 1 ;
V_20 -> V_190 -> V_81 = F_159 ( 0xffff ) ;
V_20 -> V_190 -> V_329 = V_330 ;
V_20 -> V_190 -> V_331 = F_172 (
V_324 -> V_332 & V_333 ?
F_173 ( V_324 ) : V_324 ,
F_174 ( V_2 -> V_290 ) ) ;
V_20 -> V_190 -> V_334 = F_175 ( V_324 -> V_334 ) ;
V_20 -> V_190 -> V_335 = V_330 ;
V_20 -> V_190 -> V_336 = F_176 ( V_324 ) ;
F_141 ( V_324 ) ;
V_20 -> V_190 -> V_337 = V_330 ;
V_20 -> V_190 -> V_338 = V_339 ;
if ( ! V_20 -> V_190 -> V_334 ) {
V_6 = - V_40 ;
goto V_247;
}
V_292 -> V_293 = V_182 ;
V_292 -> V_294 = V_321 ;
V_292 -> V_169 . V_169 = V_322 ;
V_292 -> V_169 . V_209 = 0 ;
F_155 ( V_297 , & V_292 -> V_292 ) ;
return 0 ;
V_247:
F_17 ( V_20 -> V_190 ) ;
V_20 -> V_190 = NULL ;
V_245:
F_17 ( V_292 ) ;
return V_6 ;
}
int F_177 ( struct V_88 * V_18 , int V_298 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_4 ( V_2 , V_295 , V_182 ) )
return - V_40 ;
F_9 ( & V_2 -> V_17 ) ;
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_76 :
switch ( F_42 ( V_18 -> V_19 , V_18 -> V_47 ) ) {
case V_72 :
V_6 = F_163 ( V_2 , V_298 ) ;
break;
case V_73 :
V_6 = F_168 ( V_2 ) ;
break;
default:
V_6 = - V_139 ;
}
break;
case V_137 :
V_6 = F_167 ( V_2 , V_298 ) ;
break;
default:
V_6 = - V_139 ;
break;
}
if ( V_6 )
goto V_52;
return 0 ;
V_52:
F_4 ( V_2 , V_182 , V_295 ) ;
F_46 ( V_2 ) ;
return V_6 ;
}
static void F_178 ( struct V_33 * V_21 )
{
switch ( V_21 -> V_65 ) {
case V_140 :
( (struct V_141 * ) V_21 ) -> V_142 . V_143 = F_134 ( V_340 ) ;
break;
case V_144 :
F_179 ( & ( (struct V_145 * ) V_21 ) -> V_146 ,
0 , 0 , 0 , F_134 ( 1 ) ) ;
break;
default:
F_180 ( & ( (struct V_58 * ) V_21 ) -> V_63 ,
0 , 0 , 0 , F_134 ( 1 ) ) ;
break;
}
}
static int F_181 ( struct V_1 * V_2 )
{
struct V_15 * V_16 , * V_78 ;
struct V_53 V_341 ;
union V_49 V_50 ;
T_3 V_81 ;
int V_6 ;
T_1 V_83 ;
V_16 = NULL ;
F_19 ( & V_7 ) ;
F_41 (cur_dev, &dev_list, list) {
if ( F_24 ( V_2 ) == V_66 &&
F_10 ( V_78 -> V_19 -> V_24 ) != V_76 )
continue;
if ( ! V_16 )
V_16 = V_78 ;
for ( V_83 = 1 ; V_83 <= V_78 -> V_19 -> V_75 ; ++ V_83 ) {
if ( ! F_30 ( V_78 -> V_19 , V_83 , & V_341 ) &&
V_341 . V_8 == V_342 ) {
V_16 = V_78 ;
goto V_343;
}
}
}
if ( ! V_16 ) {
V_6 = - V_68 ;
goto V_77;
}
V_83 = 1 ;
V_343:
V_6 = F_45 ( V_16 -> V_19 , V_83 , 0 , & V_50 ) ;
if ( V_6 )
goto V_77;
V_6 = F_182 ( V_16 -> V_19 , V_83 , 0 , & V_81 ) ;
if ( V_6 )
goto V_77;
V_2 -> V_18 . V_20 . V_21 . V_22 . V_61 =
( F_42 ( V_16 -> V_19 , V_83 ) == V_72 ) ?
V_62 : V_344 ;
F_33 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , & V_50 ) ;
F_34 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , V_81 ) ;
V_2 -> V_18 . V_47 = V_83 ;
F_8 ( V_2 , V_16 ) ;
F_178 ( F_22 ( V_2 ) ) ;
V_77:
F_21 ( & V_7 ) ;
return V_6 ;
}
static void F_183 ( int V_209 , struct V_33 * V_34 ,
struct V_60 * V_22 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
struct V_193 V_169 ;
memset ( & V_169 , 0 , sizeof V_169 ) ;
F_19 ( & V_2 -> V_87 ) ;
if ( ! F_4 ( V_2 , V_181 ,
V_295 ) )
goto V_77;
if ( ! V_209 && ! V_2 -> V_16 )
V_209 = F_38 ( V_2 ) ;
if ( V_209 ) {
if ( ! F_4 ( V_2 , V_295 ,
V_286 ) )
goto V_77;
V_169 . V_169 = V_345 ;
V_169 . V_209 = V_209 ;
} else {
memcpy ( F_22 ( V_2 ) , V_34 , F_150 ( V_34 ) ) ;
V_169 . V_169 = V_346 ;
}
if ( V_2 -> V_18 . V_89 ( & V_2 -> V_18 , & V_169 ) ) {
F_5 ( V_2 , V_188 ) ;
F_21 ( & V_2 -> V_87 ) ;
F_46 ( V_2 ) ;
F_103 ( & V_2 -> V_18 ) ;
return;
}
V_77:
F_21 ( & V_2 -> V_87 ) ;
F_46 ( V_2 ) ;
}
static int F_184 ( struct V_1 * V_2 )
{
struct V_291 * V_292 ;
union V_49 V_50 ;
int V_6 ;
V_292 = F_49 ( sizeof *V_292 , V_94 ) ;
if ( ! V_292 )
return - V_95 ;
if ( ! V_2 -> V_16 ) {
V_6 = F_181 ( V_2 ) ;
if ( V_6 )
goto V_52;
}
F_157 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , & V_50 ) ;
F_125 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , & V_50 ) ;
V_292 -> V_18 = V_2 ;
F_164 ( & V_292 -> V_292 , F_161 ) ;
V_292 -> V_293 = V_181 ;
V_292 -> V_294 = V_295 ;
V_292 -> V_169 . V_169 = V_346 ;
F_155 ( V_297 , & V_292 -> V_292 ) ;
return 0 ;
V_52:
F_17 ( V_292 ) ;
return V_6 ;
}
static int F_185 ( struct V_1 * V_2 )
{
struct V_291 * V_292 ;
int V_6 ;
V_292 = F_49 ( sizeof *V_292 , V_94 ) ;
if ( ! V_292 )
return - V_95 ;
if ( ! V_2 -> V_16 ) {
V_6 = F_43 ( V_2 ) ;
if ( V_6 )
goto V_52;
}
F_125 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , (union V_49 * )
& ( ( (struct V_58 * ) & V_2 -> V_18 . V_20 . V_21 . V_35 ) -> V_63 ) ) ;
V_292 -> V_18 = V_2 ;
F_164 ( & V_292 -> V_292 , F_161 ) ;
V_292 -> V_293 = V_181 ;
V_292 -> V_294 = V_295 ;
V_292 -> V_169 . V_169 = V_346 ;
F_155 ( V_297 , & V_292 -> V_292 ) ;
return 0 ;
V_52:
F_17 ( V_292 ) ;
return V_6 ;
}
static int F_186 ( struct V_88 * V_18 , struct V_33 * V_34 ,
struct V_33 * V_35 )
{
if ( ! V_34 || ! V_34 -> V_65 ) {
V_34 = (struct V_33 * ) & V_18 -> V_20 . V_21 . V_34 ;
V_34 -> V_65 = V_35 -> V_65 ;
if ( V_35 -> V_65 == V_144 ) {
( (struct V_145 * ) V_34 ) -> V_347 =
( (struct V_145 * ) V_35 ) -> V_347 ;
} else if ( V_35 -> V_65 == V_66 ) {
( (struct V_58 * ) V_34 ) -> V_64 =
( (struct V_58 * ) V_35 ) -> V_64 ;
}
}
return F_187 ( V_18 , V_34 ) ;
}
int F_188 ( struct V_88 * V_18 , struct V_33 * V_34 ,
struct V_33 * V_35 , int V_298 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( V_2 -> V_8 == V_98 ) {
V_6 = F_186 ( V_18 , V_34 , V_35 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_24 ( V_2 ) != V_35 -> V_65 )
return - V_40 ;
if ( ! F_4 ( V_2 , V_286 , V_181 ) )
return - V_40 ;
F_9 ( & V_2 -> V_17 ) ;
memcpy ( F_23 ( V_2 ) , V_35 , F_150 ( V_35 ) ) ;
if ( F_83 ( V_35 ) ) {
V_6 = F_184 ( V_2 ) ;
} else {
if ( V_35 -> V_65 == V_66 ) {
V_6 = F_185 ( V_2 ) ;
} else {
V_6 = F_189 ( & V_348 , F_22 ( V_2 ) ,
V_35 , & V_18 -> V_20 . V_21 . V_22 ,
V_298 , F_183 , V_2 ) ;
}
}
if ( V_6 )
goto V_52;
return 0 ;
V_52:
F_4 ( V_2 , V_181 , V_286 ) ;
F_46 ( V_2 ) ;
return V_6 ;
}
int F_190 ( struct V_88 * V_18 , int V_349 )
{
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
if ( V_349 || V_2 -> V_8 == V_98 ) {
V_2 -> V_350 = V_349 ;
V_6 = 0 ;
} else {
V_6 = - V_40 ;
}
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
int F_191 ( struct V_88 * V_18 , int V_284 )
{
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
if ( V_2 -> V_8 == V_98 || V_2 -> V_8 == V_286 ) {
V_2 -> V_351 |= ( 1 << V_352 ) ;
V_2 -> V_284 = V_284 ;
V_6 = 0 ;
} else {
V_6 = - V_40 ;
}
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
static void F_192 ( struct V_184 * V_185 ,
struct V_1 * V_2 )
{
struct V_33 * V_21 ;
struct V_58 * V_59 ;
V_251 V_353 , V_260 ;
T_5 V_69 ;
V_21 = F_22 ( V_2 ) ;
V_69 = F_88 ( V_185 -> V_69 ) ;
switch ( V_21 -> V_65 ) {
case V_140 :
( (struct V_141 * ) V_21 ) -> V_149 = V_69 ;
break;
case V_144 :
( (struct V_145 * ) V_21 ) -> V_150 = V_69 ;
break;
case V_66 :
V_59 = (struct V_58 * ) V_21 ;
V_353 = F_89 ( V_59 -> V_151 ) ;
V_260 = F_89 ( V_59 -> V_152 ) ;
V_59 -> V_151 = F_92 ( ( V_353 & V_260 ) | ( V_251 ) F_35 ( V_69 ) ) ;
V_59 -> V_152 = F_92 ( ~ 0ULL ) ;
break;
}
V_2 -> V_185 = V_185 ;
F_193 ( & V_2 -> V_186 , & V_185 -> V_187 ) ;
}
static int F_194 ( struct V_354 * V_41 , struct V_1 * V_2 ,
unsigned short V_355 )
{
struct V_184 * V_185 ;
int V_6 ;
V_185 = F_49 ( sizeof *V_185 , V_94 ) ;
if ( ! V_185 )
return - V_95 ;
V_6 = F_195 ( V_41 , V_185 , V_355 , V_355 + 1 , V_94 ) ;
if ( V_6 < 0 )
goto V_52;
V_185 -> V_41 = V_41 ;
V_185 -> V_69 = ( unsigned short ) V_6 ;
F_192 ( V_185 , V_2 ) ;
return 0 ;
V_52:
F_17 ( V_185 ) ;
return V_6 == - V_356 ? - V_57 : V_6 ;
}
static int F_196 ( struct V_354 * V_41 , struct V_1 * V_2 )
{
static unsigned int V_357 ;
int V_358 , V_359 , V_360 ;
unsigned int V_361 ;
F_197 ( & V_358 , & V_359 ) ;
V_360 = ( V_359 - V_358 ) + 1 ;
V_361 = F_198 () % V_360 + V_358 ;
V_362:
if ( V_357 != V_361 &&
! F_199 ( V_41 , ( unsigned short ) V_361 ) ) {
int V_6 = F_194 ( V_41 , V_2 , V_361 ) ;
if ( ! V_6 )
V_357 = V_361 ;
if ( V_6 != - V_57 )
return V_6 ;
}
if ( -- V_360 ) {
V_361 ++ ;
if ( ( V_361 < V_358 ) || ( V_361 > V_359 ) )
V_361 = V_358 ;
goto V_362;
}
return - V_57 ;
}
static int F_200 ( struct V_184 * V_185 ,
struct V_1 * V_2 , T_9 V_350 )
{
struct V_1 * V_363 ;
struct V_33 * V_21 , * V_364 ;
V_21 = F_22 ( V_2 ) ;
F_201 (cur_id, &bind_list->owners, node) {
if ( V_2 == V_363 )
continue;
if ( ( V_363 -> V_8 != V_183 ) && V_350 &&
V_363 -> V_350 )
continue;
V_364 = F_22 ( V_363 ) ;
if ( V_2 -> V_284 && V_363 -> V_284 &&
( V_21 -> V_65 != V_364 -> V_65 ) )
continue;
if ( F_83 ( V_21 ) || F_83 ( V_364 ) )
return - V_57 ;
if ( ! F_84 ( V_21 , V_364 ) )
return - V_365 ;
}
return 0 ;
}
static int F_202 ( struct V_354 * V_41 , struct V_1 * V_2 )
{
struct V_184 * V_185 ;
unsigned short V_355 ;
int V_6 ;
V_355 = F_35 ( F_87 ( F_22 ( V_2 ) ) ) ;
if ( V_355 < V_366 && ! F_203 ( V_367 ) )
return - V_368 ;
V_185 = F_199 ( V_41 , V_355 ) ;
if ( ! V_185 ) {
V_6 = F_194 ( V_41 , V_2 , V_355 ) ;
} else {
V_6 = F_200 ( V_185 , V_2 , V_2 -> V_350 ) ;
if ( ! V_6 )
F_192 ( V_185 , V_2 ) ;
}
return V_6 ;
}
static int F_204 ( struct V_1 * V_2 )
{
struct V_184 * V_185 = V_2 -> V_185 ;
int V_6 = 0 ;
F_19 ( & V_7 ) ;
if ( V_185 -> V_187 . V_369 -> V_180 )
V_6 = F_200 ( V_185 , V_2 , 0 ) ;
F_21 ( & V_7 ) ;
return V_6 ;
}
static struct V_354 * F_205 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_18 . V_41 ) {
case V_279 :
return & V_370 ;
case V_42 :
return & V_371 ;
case V_45 :
return & V_372 ;
case V_43 :
return & V_373 ;
default:
return NULL ;
}
}
static struct V_354 * F_206 ( struct V_1 * V_2 )
{
struct V_354 * V_41 = NULL ;
struct V_58 * V_59 ;
V_251 V_374 , V_260 , V_353 ;
V_59 = (struct V_58 * ) F_22 ( V_2 ) ;
V_260 = F_89 ( V_59 -> V_152 ) & V_375 ;
V_353 = F_89 ( V_59 -> V_151 ) & V_260 ;
if ( ( V_2 -> V_18 . V_41 == V_43 ) && ( V_353 == ( V_376 & V_260 ) ) ) {
V_374 = V_376 ;
V_41 = & V_373 ;
} else if ( ( ( V_2 -> V_18 . V_41 == V_43 ) || ( V_2 -> V_18 . V_41 == V_279 ) ) &&
( V_353 == ( V_377 & V_260 ) ) ) {
V_374 = V_377 ;
V_41 = & V_370 ;
} else if ( ( ( V_2 -> V_18 . V_41 == V_43 ) || ( V_2 -> V_18 . V_41 == V_42 ) ) &&
( V_353 == ( V_378 & V_260 ) ) ) {
V_374 = V_378 ;
V_41 = & V_371 ;
}
if ( V_41 ) {
V_59 -> V_151 = F_92 ( V_374 | F_35 ( F_87 ( (struct V_33 * ) V_59 ) ) ) ;
V_59 -> V_152 = F_92 ( V_375 |
F_89 ( V_59 -> V_152 ) ) ;
}
return V_41 ;
}
static int F_207 ( struct V_1 * V_2 )
{
struct V_354 * V_41 ;
int V_6 ;
if ( F_24 ( V_2 ) != V_66 )
V_41 = F_205 ( V_2 ) ;
else
V_41 = F_206 ( V_2 ) ;
if ( ! V_41 )
return - V_379 ;
F_19 ( & V_7 ) ;
if ( F_90 ( F_22 ( V_2 ) ) )
V_6 = F_196 ( V_41 , V_2 ) ;
else
V_6 = F_202 ( V_41 , V_2 ) ;
F_21 ( & V_7 ) ;
return V_6 ;
}
static int F_208 ( struct V_60 * V_22 ,
struct V_33 * V_21 )
{
#if F_209 ( V_380 )
struct V_145 * V_300 ;
if ( V_21 -> V_65 != V_144 )
return 0 ;
V_300 = (struct V_145 * ) V_21 ;
if ( ( F_210 ( & V_300 -> V_146 ) & V_381 ) &&
! V_300 -> V_347 )
return - V_40 ;
V_22 -> V_326 = V_300 -> V_347 ;
#endif
return 0 ;
}
int F_151 ( struct V_88 * V_18 , int V_285 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( V_2 -> V_8 == V_98 ) {
V_18 -> V_20 . V_21 . V_34 . V_36 = V_140 ;
V_6 = F_187 ( V_18 , F_22 ( V_2 ) ) ;
if ( V_6 )
return V_6 ;
}
if ( ! F_4 ( V_2 , V_286 , V_183 ) )
return - V_40 ;
if ( V_2 -> V_350 ) {
V_6 = F_204 ( V_2 ) ;
if ( V_6 )
goto V_52;
}
V_2 -> V_285 = V_285 ;
if ( V_18 -> V_19 ) {
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_76 :
V_6 = F_142 ( V_2 ) ;
if ( V_6 )
goto V_52;
break;
case V_137 :
V_6 = F_145 ( V_2 , V_285 ) ;
if ( V_6 )
goto V_52;
break;
default:
V_6 = - V_139 ;
goto V_52;
}
} else
F_152 ( V_2 ) ;
return 0 ;
V_52:
V_2 -> V_285 = 0 ;
F_4 ( V_2 , V_183 , V_286 ) ;
return V_6 ;
}
int F_187 ( struct V_88 * V_18 , struct V_33 * V_21 )
{
struct V_1 * V_2 ;
int V_6 ;
if ( V_21 -> V_65 != V_140 && V_21 -> V_65 != V_144 &&
V_21 -> V_65 != V_66 )
return - V_382 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_4 ( V_2 , V_98 , V_286 ) )
return - V_40 ;
V_6 = F_208 ( & V_18 -> V_20 . V_21 . V_22 , V_21 ) ;
if ( V_6 )
goto V_245;
if ( ! F_83 ( V_21 ) ) {
V_6 = F_36 ( V_21 , & V_18 -> V_20 . V_21 . V_22 ) ;
if ( V_6 )
goto V_245;
V_6 = F_38 ( V_2 ) ;
if ( V_6 )
goto V_245;
}
memcpy ( F_22 ( V_2 ) , V_21 , F_150 ( V_21 ) ) ;
if ( ! ( V_2 -> V_351 & ( 1 << V_352 ) ) ) {
if ( V_21 -> V_65 == V_140 )
V_2 -> V_284 = 1 ;
#if F_209 ( V_380 )
else if ( V_21 -> V_65 == V_144 )
V_2 -> V_284 = V_281 . V_383 . V_384 . V_385 ;
#endif
}
V_6 = F_207 ( V_2 ) ;
if ( V_6 )
goto V_247;
return 0 ;
V_247:
if ( V_2 -> V_16 )
F_18 ( V_2 ) ;
V_245:
F_4 ( V_2 , V_286 , V_98 ) ;
return V_6 ;
}
static int F_211 ( void * V_12 , struct V_1 * V_2 )
{
struct V_11 * V_11 ;
V_11 = V_12 ;
V_11 -> V_175 = V_176 ;
if ( F_24 ( V_2 ) == V_140 ) {
struct V_141 * V_386 , * V_387 ;
V_386 = (struct V_141 * ) F_22 ( V_2 ) ;
V_387 = (struct V_141 * ) F_23 ( V_2 ) ;
F_7 ( V_11 , 4 ) ;
V_11 -> V_34 . V_162 . V_21 = V_386 -> V_142 . V_143 ;
V_11 -> V_35 . V_162 . V_21 = V_387 -> V_142 . V_143 ;
V_11 -> V_69 = V_386 -> V_149 ;
} else if ( F_24 ( V_2 ) == V_144 ) {
struct V_145 * V_388 , * V_389 ;
V_388 = (struct V_145 * ) F_22 ( V_2 ) ;
V_389 = (struct V_145 * ) F_23 ( V_2 ) ;
F_7 ( V_11 , 6 ) ;
V_11 -> V_34 . V_165 = V_388 -> V_146 ;
V_11 -> V_35 . V_165 = V_389 -> V_146 ;
V_11 -> V_69 = V_388 -> V_150 ;
}
return 0 ;
}
static int F_212 ( struct V_202 * V_135 ,
struct V_167 * V_168 )
{
struct V_1 * V_2 = V_135 -> V_90 ;
struct V_193 V_169 ;
struct V_390 * V_391 = & V_168 -> V_171 . V_392 ;
int V_6 = 0 ;
if ( F_47 ( V_2 , V_204 ) )
return 0 ;
memset ( & V_169 , 0 , sizeof V_169 ) ;
switch ( V_168 -> V_169 ) {
case V_393 :
V_169 . V_169 = V_208 ;
V_169 . V_209 = - V_210 ;
break;
case V_394 :
V_169 . V_171 . V_243 . V_174 = V_168 -> V_174 ;
V_169 . V_171 . V_243 . V_197 = V_395 ;
if ( V_391 -> V_209 != V_396 ) {
V_169 . V_169 = V_208 ;
V_169 . V_209 = V_168 -> V_171 . V_392 . V_209 ;
break;
}
V_6 = F_25 ( V_2 , V_391 -> V_37 ) ;
if ( V_6 ) {
V_169 . V_169 = V_345 ;
V_169 . V_209 = V_6 ;
break;
}
F_213 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ,
V_2 -> V_18 . V_20 . V_190 ,
& V_169 . V_171 . V_243 . V_397 ) ;
V_169 . V_171 . V_243 . V_120 = V_391 -> V_398 ;
V_169 . V_171 . V_243 . V_37 = V_391 -> V_37 ;
V_169 . V_169 = V_213 ;
V_169 . V_209 = 0 ;
break;
default:
F_121 ( V_229 L_1 ,
V_168 -> V_169 ) ;
goto V_77;
}
V_6 = V_2 -> V_18 . V_89 ( & V_2 -> V_18 , & V_169 ) ;
if ( V_6 ) {
V_2 -> V_135 . V_32 = NULL ;
F_5 ( V_2 , V_188 ) ;
F_21 ( & V_2 -> V_87 ) ;
F_103 ( & V_2 -> V_18 ) ;
return V_6 ;
}
V_77:
F_21 ( & V_2 -> V_87 ) ;
return V_6 ;
}
static int F_214 ( struct V_1 * V_2 ,
struct V_122 * V_123 )
{
struct V_399 V_400 ;
struct V_202 * V_18 ;
void * V_174 ;
int V_236 , V_6 ;
memset ( & V_400 , 0 , sizeof V_400 ) ;
V_236 = F_96 ( V_2 ) ;
V_400 . V_197 = V_236 + V_123 -> V_197 ;
if ( V_400 . V_197 < V_123 -> V_197 )
return - V_40 ;
if ( V_400 . V_197 ) {
V_174 = F_49 ( V_400 . V_197 , V_401 ) ;
if ( ! V_174 )
return - V_95 ;
} else {
V_174 = NULL ;
}
if ( V_123 -> V_174 && V_123 -> V_197 )
memcpy ( V_174 + V_236 , V_123 -> V_174 ,
V_123 -> V_197 ) ;
if ( V_174 ) {
V_6 = F_211 ( V_174 , V_2 ) ;
if ( V_6 )
goto V_77;
V_400 . V_174 = V_174 ;
}
V_18 = F_143 ( V_2 -> V_18 . V_19 , F_212 ,
V_2 ) ;
if ( F_64 ( V_18 ) ) {
V_6 = F_65 ( V_18 ) ;
goto V_77;
}
V_2 -> V_135 . V_32 = V_18 ;
V_400 . V_155 = V_2 -> V_18 . V_20 . V_190 ;
V_400 . V_303 = F_132 ( & V_2 -> V_18 , F_23 ( V_2 ) ) ;
V_400 . V_298 = 1 << ( V_402 - 8 ) ;
V_400 . V_403 = V_404 ;
V_6 = F_215 ( V_2 -> V_135 . V_32 , & V_400 ) ;
if ( V_6 ) {
F_113 ( V_2 -> V_135 . V_32 ) ;
V_2 -> V_135 . V_32 = NULL ;
}
V_77:
F_17 ( V_174 ) ;
return V_6 ;
}
static int F_216 ( struct V_1 * V_2 ,
struct V_122 * V_123 )
{
struct V_405 V_400 ;
struct V_230 * V_20 ;
void * V_174 ;
struct V_202 * V_18 ;
int V_236 , V_6 ;
memset ( & V_400 , 0 , sizeof V_400 ) ;
V_236 = F_96 ( V_2 ) ;
V_400 . V_197 = V_236 + V_123 -> V_197 ;
if ( V_400 . V_197 < V_123 -> V_197 )
return - V_40 ;
if ( V_400 . V_197 ) {
V_174 = F_49 ( V_400 . V_197 , V_401 ) ;
if ( ! V_174 )
return - V_95 ;
} else {
V_174 = NULL ;
}
if ( V_123 -> V_174 && V_123 -> V_197 )
memcpy ( V_174 + V_236 , V_123 -> V_174 ,
V_123 -> V_197 ) ;
V_18 = F_143 ( V_2 -> V_18 . V_19 , F_120 , V_2 ) ;
if ( F_64 ( V_18 ) ) {
V_6 = F_65 ( V_18 ) ;
goto V_77;
}
V_2 -> V_135 . V_32 = V_18 ;
V_20 = & V_2 -> V_18 . V_20 ;
if ( V_174 ) {
V_6 = F_211 ( V_174 , V_2 ) ;
if ( V_6 )
goto V_77;
V_400 . V_174 = V_174 ;
}
V_400 . V_173 = & V_20 -> V_190 [ 0 ] ;
if ( V_20 -> V_232 == 2 )
V_400 . V_233 = & V_20 -> V_190 [ 1 ] ;
V_400 . V_303 = F_132 ( & V_2 -> V_18 , F_23 ( V_2 ) ) ;
V_400 . V_120 = V_2 -> V_120 ;
V_400 . V_93 = V_2 -> V_18 . V_93 ;
V_400 . V_406 = V_2 -> V_102 ;
V_400 . V_125 = V_123 -> V_125 ;
V_400 . V_127 = V_123 -> V_127 ;
V_400 . V_199 = V_123 -> V_199 ;
V_400 . V_238 = F_217 ( T_1 , 7 , V_123 -> V_238 ) ;
V_400 . V_200 = F_217 ( T_1 , 7 , V_123 -> V_200 ) ;
V_400 . V_407 = V_402 ;
V_400 . V_408 = V_402 ;
V_400 . V_403 = V_404 ;
V_400 . V_121 = V_2 -> V_121 ? 1 : 0 ;
V_6 = F_218 ( V_2 -> V_135 . V_32 , & V_400 ) ;
V_77:
if ( V_6 && ! F_64 ( V_18 ) ) {
F_113 ( V_18 ) ;
V_2 -> V_135 . V_32 = NULL ;
}
F_17 ( V_174 ) ;
return V_6 ;
}
static int F_219 ( struct V_1 * V_2 ,
struct V_122 * V_123 )
{
struct V_261 * V_135 ;
struct V_141 * sin ;
int V_6 ;
struct V_409 V_410 ;
V_135 = F_146 ( V_2 -> V_18 . V_19 , F_135 , V_2 ) ;
if ( F_64 ( V_135 ) )
return F_65 ( V_135 ) ;
V_2 -> V_135 . V_138 = V_135 ;
sin = (struct V_141 * ) F_22 ( V_2 ) ;
V_135 -> V_267 = * sin ;
sin = (struct V_141 * ) F_23 ( V_2 ) ;
V_135 -> V_268 = * sin ;
V_6 = F_68 ( V_2 , V_123 ) ;
if ( V_6 )
goto V_77;
if ( V_123 ) {
V_410 . V_270 = V_123 -> V_127 ;
V_410 . V_269 = V_123 -> V_125 ;
V_410 . V_174 = V_123 -> V_174 ;
V_410 . V_197 = V_123 -> V_197 ;
V_410 . V_398 = V_2 -> V_18 . V_104 ? V_2 -> V_120 : V_123 -> V_120 ;
} else {
memset ( & V_410 , 0 , sizeof V_410 ) ;
V_410 . V_398 = V_2 -> V_120 ;
}
V_6 = F_220 ( V_135 , & V_410 ) ;
V_77:
if ( V_6 ) {
F_114 ( V_135 ) ;
V_2 -> V_135 . V_138 = NULL ;
}
return V_6 ;
}
int F_221 ( struct V_88 * V_18 , struct V_122 * V_123 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_4 ( V_2 , V_321 , V_204 ) )
return - V_40 ;
if ( ! V_18 -> V_104 ) {
V_2 -> V_120 = V_123 -> V_120 ;
V_2 -> V_121 = V_123 -> V_121 ;
}
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_76 :
if ( V_18 -> V_93 == V_119 )
V_6 = F_214 ( V_2 , V_123 ) ;
else
V_6 = F_216 ( V_2 , V_123 ) ;
break;
case V_137 :
V_6 = F_219 ( V_2 , V_123 ) ;
break;
default:
V_6 = - V_139 ;
break;
}
if ( V_6 )
goto V_52;
return 0 ;
V_52:
F_4 ( V_2 , V_204 , V_321 ) ;
return V_6 ;
}
static int F_222 ( struct V_1 * V_2 ,
struct V_122 * V_123 )
{
struct V_411 V_391 ;
int V_6 ;
V_6 = F_68 ( V_2 , V_123 ) ;
if ( V_6 )
goto V_77;
V_6 = F_69 ( V_2 , V_123 ) ;
if ( V_6 )
goto V_77;
memset ( & V_391 , 0 , sizeof V_391 ) ;
V_391 . V_120 = V_2 -> V_120 ;
V_391 . V_406 = V_2 -> V_102 ;
V_391 . V_174 = V_123 -> V_174 ;
V_391 . V_197 = V_123 -> V_197 ;
V_391 . V_125 = V_123 -> V_125 ;
V_391 . V_127 = V_123 -> V_127 ;
V_391 . V_412 = 0 ;
V_391 . V_199 = V_123 -> V_199 ;
V_391 . V_200 = F_217 ( T_1 , 7 , V_123 -> V_200 ) ;
V_391 . V_121 = V_2 -> V_121 ? 1 : 0 ;
V_6 = F_223 ( V_2 -> V_135 . V_32 , & V_391 ) ;
V_77:
return V_6 ;
}
static int F_224 ( struct V_1 * V_2 ,
struct V_122 * V_123 )
{
struct V_409 V_410 ;
int V_6 ;
V_6 = F_68 ( V_2 , V_123 ) ;
if ( V_6 )
return V_6 ;
V_410 . V_270 = V_123 -> V_127 ;
V_410 . V_269 = V_123 -> V_125 ;
V_410 . V_174 = V_123 -> V_174 ;
V_410 . V_197 = V_123 -> V_197 ;
if ( V_2 -> V_18 . V_104 ) {
V_410 . V_398 = V_2 -> V_120 ;
} else
V_410 . V_398 = V_123 -> V_120 ;
return F_225 ( V_2 -> V_135 . V_138 , & V_410 ) ;
}
static int F_226 ( struct V_1 * V_2 ,
enum V_413 V_209 , T_2 V_37 ,
const void * V_174 , int V_197 )
{
struct V_414 V_391 ;
int V_6 ;
memset ( & V_391 , 0 , sizeof V_391 ) ;
V_391 . V_209 = V_209 ;
if ( V_209 == V_396 ) {
V_6 = F_25 ( V_2 , V_37 ) ;
if ( V_6 )
return V_6 ;
V_391 . V_120 = V_2 -> V_120 ;
V_391 . V_37 = V_2 -> V_37 ;
}
V_391 . V_174 = V_174 ;
V_391 . V_197 = V_197 ;
return F_227 ( V_2 -> V_135 . V_32 , & V_391 ) ;
}
int F_228 ( struct V_88 * V_18 , struct V_122 * V_123 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
V_2 -> V_96 = F_51 ( V_97 ) ;
if ( ! F_1 ( V_2 , V_204 ) )
return - V_40 ;
if ( ! V_18 -> V_104 && V_123 ) {
V_2 -> V_120 = V_123 -> V_120 ;
V_2 -> V_121 = V_123 -> V_121 ;
}
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_76 :
if ( V_18 -> V_93 == V_119 ) {
if ( V_123 )
V_6 = F_226 ( V_2 , V_396 ,
V_123 -> V_37 ,
V_123 -> V_174 ,
V_123 -> V_197 ) ;
else
V_6 = F_226 ( V_2 , V_396 ,
0 , NULL , 0 ) ;
} else {
if ( V_123 )
V_6 = F_222 ( V_2 , V_123 ) ;
else
V_6 = F_116 ( V_2 ) ;
}
break;
case V_137 :
V_6 = F_224 ( V_2 , V_123 ) ;
break;
default:
V_6 = - V_139 ;
break;
}
if ( V_6 )
goto V_191;
return 0 ;
V_191:
F_70 ( V_2 ) ;
F_229 ( V_18 , NULL , 0 ) ;
return V_6 ;
}
int F_230 ( struct V_88 * V_18 , enum V_415 V_169 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! V_2 -> V_135 . V_32 )
return - V_40 ;
switch ( V_18 -> V_19 -> V_24 ) {
case V_416 :
V_6 = F_231 ( V_2 -> V_135 . V_32 , V_169 ) ;
break;
default:
V_6 = 0 ;
break;
}
return V_6 ;
}
int F_229 ( struct V_88 * V_18 , const void * V_174 ,
T_1 V_197 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! V_2 -> V_135 . V_32 )
return - V_40 ;
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_76 :
if ( V_18 -> V_93 == V_119 )
V_6 = F_226 ( V_2 , V_417 , 0 ,
V_174 , V_197 ) ;
else
V_6 = F_118 ( V_2 -> V_135 . V_32 ,
V_192 , NULL ,
0 , V_174 , V_197 ) ;
break;
case V_137 :
V_6 = F_232 ( V_2 -> V_135 . V_138 ,
V_174 , V_197 ) ;
break;
default:
V_6 = - V_139 ;
break;
}
return V_6 ;
}
int F_233 ( struct V_88 * V_18 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! V_2 -> V_135 . V_32 )
return - V_40 ;
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_76 :
V_6 = F_70 ( V_2 ) ;
if ( V_6 )
goto V_77;
if ( F_234 ( V_2 -> V_135 . V_32 , NULL , 0 ) )
F_235 ( V_2 -> V_135 . V_32 , NULL , 0 ) ;
break;
case V_137 :
V_6 = F_236 ( V_2 -> V_135 . V_138 , 0 ) ;
break;
default:
V_6 = - V_40 ;
break;
}
V_77:
return V_6 ;
}
static int F_237 ( int V_209 , struct V_418 * V_31 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = V_31 -> V_90 ;
struct V_193 V_169 ;
int V_6 ;
V_2 = V_29 -> V_2 ;
if ( F_47 ( V_2 , V_286 ) &&
F_47 ( V_2 , V_295 ) )
return 0 ;
if ( ! V_209 )
V_209 = F_25 ( V_2 , F_28 ( V_31 -> V_39 . V_37 ) ) ;
F_19 ( & V_2 -> V_99 ) ;
if ( ! V_209 && V_2 -> V_18 . V_104 )
V_209 = F_238 ( V_2 -> V_18 . V_104 , & V_31 -> V_39 . V_46 ,
F_124 ( V_31 -> V_39 . V_419 ) ) ;
F_21 ( & V_2 -> V_99 ) ;
memset ( & V_169 , 0 , sizeof V_169 ) ;
V_169 . V_209 = V_209 ;
V_169 . V_171 . V_243 . V_174 = V_29 -> V_90 ;
if ( ! V_209 ) {
V_169 . V_169 = V_420 ;
F_239 ( V_2 -> V_18 . V_19 ,
V_2 -> V_18 . V_47 , & V_31 -> V_39 ,
& V_169 . V_171 . V_243 . V_397 ) ;
V_169 . V_171 . V_243 . V_120 = 0xFFFFFF ;
V_169 . V_171 . V_243 . V_37 = F_28 ( V_31 -> V_39 . V_37 ) ;
} else
V_169 . V_169 = V_421 ;
V_6 = V_2 -> V_18 . V_89 ( & V_2 -> V_18 , & V_169 ) ;
if ( V_6 ) {
F_5 ( V_2 , V_188 ) ;
F_21 ( & V_2 -> V_87 ) ;
F_103 ( & V_2 -> V_18 ) ;
return 0 ;
}
F_21 ( & V_2 -> V_87 ) ;
return 0 ;
}
static void F_240 ( struct V_1 * V_2 ,
struct V_33 * V_21 , union V_49 * V_46 )
{
unsigned char V_422 [ V_423 ] ;
struct V_60 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
struct V_141 * sin = (struct V_141 * ) V_21 ;
struct V_145 * V_300 = (struct V_145 * ) V_21 ;
if ( F_83 ( V_21 ) ) {
memset ( V_46 , 0 , sizeof *V_46 ) ;
} else if ( ( V_21 -> V_65 == V_144 ) &&
( ( F_28 ( V_300 -> V_146 . V_424 [ 0 ] ) & 0xFFF0FFFF ) ==
0xFF10A01B ) ) {
memcpy ( V_46 , & V_300 -> V_146 , sizeof *V_46 ) ;
} else if ( V_21 -> V_65 == V_66 ) {
memcpy ( V_46 , & ( (struct V_58 * ) V_21 ) -> V_63 , sizeof *V_46 ) ;
} else if ( ( V_21 -> V_65 == V_144 ) ) {
F_241 ( & V_300 -> V_146 , V_22 -> V_425 , V_422 ) ;
if ( V_2 -> V_18 . V_41 == V_42 )
V_422 [ 7 ] = 0x01 ;
* V_46 = * (union V_49 * ) ( V_422 + 4 ) ;
} else {
F_242 ( sin -> V_142 . V_143 , V_22 -> V_425 , V_422 ) ;
if ( V_2 -> V_18 . V_41 == V_42 )
V_422 [ 7 ] = 0x01 ;
* V_46 = * (union V_49 * ) ( V_422 + 4 ) ;
}
}
static int F_243 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_38 V_39 ;
struct V_60 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
T_8 V_299 ;
int V_6 ;
F_26 ( V_22 , & V_39 . V_46 ) ;
V_6 = F_27 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ,
& V_39 . V_46 , & V_39 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_25 ( V_2 , 0 ) ;
if ( V_6 )
return V_6 ;
F_240 ( V_2 , (struct V_33 * ) & V_29 -> V_21 , & V_39 . V_46 ) ;
V_39 . V_37 = F_244 ( V_2 -> V_37 ) ;
F_157 ( V_22 , & V_39 . V_426 ) ;
V_39 . V_81 = F_159 ( F_72 ( V_22 ) ) ;
V_39 . V_427 = 1 ;
V_299 = V_428 | V_429 |
V_430 | V_431 |
V_432 | V_433 |
V_434 |
V_435 ;
if ( V_2 -> V_18 . V_41 == V_45 )
V_299 |= V_436 |
V_437 |
V_438 |
V_439 |
V_440 ;
V_29 -> V_31 . V_32 = F_245 ( & V_315 , V_2 -> V_18 . V_19 ,
V_2 -> V_18 . V_47 , & V_39 ,
V_299 , V_94 ,
F_237 , V_29 ) ;
return F_246 ( V_29 -> V_31 . V_32 ) ;
}
static void F_247 ( struct V_316 * V_292 )
{
struct V_441 * V_442 = F_16 ( V_292 , struct V_441 , V_292 ) ;
struct V_28 * V_29 = V_442 -> V_29 ;
struct V_418 * V_443 = V_29 -> V_31 . V_32 ;
V_29 -> V_31 . V_32 -> V_90 = V_29 ;
F_237 ( 0 , V_443 ) ;
F_112 ( & V_29 -> V_30 , F_15 ) ;
F_17 ( V_442 ) ;
}
static void F_248 ( struct V_33 * V_21 , union V_49 * V_46 )
{
struct V_141 * sin = (struct V_141 * ) V_21 ;
struct V_145 * V_300 = (struct V_145 * ) V_21 ;
if ( F_83 ( V_21 ) ) {
memset ( V_46 , 0 , sizeof *V_46 ) ;
} else if ( V_21 -> V_65 == V_144 ) {
memcpy ( V_46 , & V_300 -> V_146 , sizeof *V_46 ) ;
} else {
V_46 -> V_444 [ 0 ] = 0xff ;
V_46 -> V_444 [ 1 ] = 0x0e ;
V_46 -> V_444 [ 2 ] = 0 ;
V_46 -> V_444 [ 3 ] = 0 ;
V_46 -> V_444 [ 4 ] = 0 ;
V_46 -> V_444 [ 5 ] = 0 ;
V_46 -> V_444 [ 6 ] = 0 ;
V_46 -> V_444 [ 7 ] = 0 ;
V_46 -> V_444 [ 8 ] = 0 ;
V_46 -> V_444 [ 9 ] = 0 ;
V_46 -> V_444 [ 10 ] = 0xff ;
V_46 -> V_444 [ 11 ] = 0xff ;
* ( T_7 * ) ( & V_46 -> V_444 [ 12 ] ) = sin -> V_142 . V_143 ;
}
}
static int F_249 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_441 * V_292 ;
struct V_60 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
int V_52 ;
struct V_33 * V_21 = (struct V_33 * ) & V_29 -> V_21 ;
struct V_275 * V_324 = NULL ;
if ( F_75 ( (struct V_33 * ) & V_29 -> V_21 ) )
return - V_40 ;
V_292 = F_49 ( sizeof *V_292 , V_94 ) ;
if ( ! V_292 )
return - V_95 ;
V_29 -> V_31 . V_32 = F_49 ( sizeof( struct V_418 ) , V_94 ) ;
if ( ! V_29 -> V_31 . V_32 ) {
V_52 = - V_95 ;
goto V_445;
}
F_248 ( V_21 , & V_29 -> V_31 . V_32 -> V_39 . V_46 ) ;
V_29 -> V_31 . V_32 -> V_39 . V_81 = F_159 ( 0xffff ) ;
if ( V_2 -> V_18 . V_41 == V_42 )
V_29 -> V_31 . V_32 -> V_39 . V_37 = F_244 ( V_44 ) ;
if ( V_22 -> V_326 )
V_324 = F_169 ( & V_281 , V_22 -> V_326 ) ;
if ( ! V_324 ) {
V_52 = - V_68 ;
goto V_446;
}
V_29 -> V_31 . V_32 -> V_39 . V_336 = F_176 ( V_324 ) ;
V_29 -> V_31 . V_32 -> V_39 . V_328 = 1 ;
V_29 -> V_31 . V_32 -> V_39 . V_334 = F_175 ( V_324 -> V_334 ) ;
F_141 ( V_324 ) ;
if ( ! V_29 -> V_31 . V_32 -> V_39 . V_334 ) {
V_52 = - V_40 ;
goto V_446;
}
F_39 ( V_22 , & V_29 -> V_31 . V_32 -> V_39 . V_426 ) ;
V_292 -> V_18 = V_2 ;
V_292 -> V_29 = V_29 ;
F_164 ( & V_292 -> V_292 , F_247 ) ;
F_250 ( & V_29 -> V_30 ) ;
F_155 ( V_297 , & V_292 -> V_292 ) ;
return 0 ;
V_446:
F_17 ( V_29 -> V_31 . V_32 ) ;
V_445:
F_17 ( V_292 ) ;
return V_52 ;
}
int F_251 ( struct V_88 * V_18 , struct V_33 * V_21 ,
void * V_90 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_1 ( V_2 , V_286 ) &&
! F_1 ( V_2 , V_295 ) )
return - V_40 ;
V_29 = F_123 ( sizeof *V_29 , V_94 ) ;
if ( ! V_29 )
return - V_95 ;
memcpy ( & V_29 -> V_21 , V_21 , F_150 ( V_21 ) ) ;
V_29 -> V_90 = V_90 ;
V_29 -> V_2 = V_2 ;
F_252 ( & V_2 -> V_7 ) ;
F_253 ( & V_29 -> V_25 , & V_2 -> V_101 ) ;
F_254 ( & V_2 -> V_7 ) ;
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_76 :
switch ( F_42 ( V_18 -> V_19 , V_18 -> V_47 ) ) {
case V_72 :
V_6 = F_243 ( V_2 , V_29 ) ;
break;
case V_73 :
F_255 ( & V_29 -> V_30 ) ;
V_6 = F_249 ( V_2 , V_29 ) ;
break;
default:
V_6 = - V_40 ;
}
break;
default:
V_6 = - V_139 ;
break;
}
if ( V_6 ) {
F_256 ( & V_2 -> V_7 ) ;
F_20 ( & V_29 -> V_25 ) ;
F_257 ( & V_2 -> V_7 ) ;
F_17 ( V_29 ) ;
}
return V_6 ;
}
void F_258 ( struct V_88 * V_18 , struct V_33 * V_21 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
F_256 ( & V_2 -> V_7 ) ;
F_41 (mc, &id_priv->mc_list, list) {
if ( ! memcmp ( & V_29 -> V_21 , V_21 , F_150 ( V_21 ) ) ) {
F_20 ( & V_29 -> V_25 ) ;
F_257 ( & V_2 -> V_7 ) ;
if ( V_18 -> V_104 )
F_259 ( V_18 -> V_104 ,
& V_29 -> V_31 . V_32 -> V_39 . V_46 ,
F_124 ( V_29 -> V_31 . V_32 -> V_39 . V_419 ) ) ;
if ( F_10 ( V_2 -> V_16 -> V_19 -> V_24 ) == V_76 ) {
switch ( F_42 ( V_18 -> V_19 , V_18 -> V_47 ) ) {
case V_72 :
F_111 ( V_29 -> V_31 . V_32 ) ;
F_17 ( V_29 ) ;
break;
case V_73 :
F_112 ( & V_29 -> V_30 , F_15 ) ;
break;
default:
break;
}
}
return;
}
}
F_257 ( & V_2 -> V_7 ) ;
}
static int F_260 ( struct V_275 * V_324 , struct V_1 * V_2 )
{
struct V_60 * V_22 ;
struct V_319 * V_292 ;
V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
if ( ( V_22 -> V_326 == V_324 -> V_447 ) &&
memcmp ( V_22 -> V_74 , V_324 -> V_22 , V_324 -> V_448 ) ) {
F_121 ( V_449 L_4 ,
V_324 -> V_288 , & V_2 -> V_18 ) ;
V_292 = F_49 ( sizeof *V_292 , V_94 ) ;
if ( ! V_292 )
return - V_95 ;
F_164 ( & V_292 -> V_292 , F_162 ) ;
V_292 -> V_18 = V_2 ;
V_292 -> V_169 . V_169 = V_450 ;
F_9 ( & V_2 -> V_17 ) ;
F_155 ( V_297 , & V_292 -> V_292 ) ;
}
return 0 ;
}
static int F_261 ( struct V_451 * V_452 , unsigned long V_169 ,
void * V_453 )
{
struct V_275 * V_324 = F_262 ( V_453 ) ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_6 = V_454 ;
if ( F_263 ( V_324 ) != & V_281 )
return V_454 ;
if ( V_169 != V_455 )
return V_454 ;
if ( ! ( V_324 -> V_5 & V_456 ) || ! ( V_324 -> V_332 & V_457 ) )
return V_454 ;
F_19 ( & V_7 ) ;
F_41 (cma_dev, &dev_list, list)
F_41 (id_priv, &cma_dev->id_list, list) {
V_6 = F_260 ( V_324 , V_2 ) ;
if ( V_6 )
goto V_77;
}
V_77:
F_21 ( & V_7 ) ;
return V_6 ;
}
static void F_264 ( struct V_48 * V_19 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
V_16 = F_123 ( sizeof *V_16 , V_94 ) ;
if ( ! V_16 )
return;
V_16 -> V_19 = V_19 ;
F_54 ( & V_16 -> V_4 ) ;
F_55 ( & V_16 -> V_17 , 1 ) ;
F_56 ( & V_16 -> V_26 ) ;
F_265 ( V_19 , & V_458 , V_16 ) ;
F_19 ( & V_7 ) ;
F_11 ( & V_16 -> V_25 , & V_459 ) ;
F_41 (id_priv, &listen_any_list, list)
F_149 ( V_2 , V_16 ) ;
F_21 ( & V_7 ) ;
}
static int F_266 ( struct V_1 * V_2 )
{
struct V_193 V_169 ;
enum V_3 V_8 ;
int V_6 = 0 ;
V_8 = F_5 ( V_2 , V_320 ) ;
if ( V_8 == V_188 )
return 0 ;
F_104 ( V_2 , V_8 ) ;
F_19 ( & V_2 -> V_87 ) ;
if ( ! F_1 ( V_2 , V_320 ) )
goto V_77;
memset ( & V_169 , 0 , sizeof V_169 ) ;
V_169 . V_169 = V_460 ;
V_6 = V_2 -> V_18 . V_89 ( & V_2 -> V_18 , & V_169 ) ;
V_77:
F_21 ( & V_2 -> V_87 ) ;
return V_6 ;
}
static void F_267 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
int V_6 ;
F_19 ( & V_7 ) ;
while ( ! F_100 ( & V_16 -> V_26 ) ) {
V_2 = F_101 ( V_16 -> V_26 . V_180 ,
struct V_1 , V_25 ) ;
F_20 ( & V_2 -> V_100 ) ;
F_102 ( & V_2 -> V_25 ) ;
F_9 ( & V_2 -> V_17 ) ;
F_21 ( & V_7 ) ;
V_6 = V_2 -> V_189 ? 1 : F_266 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( V_6 )
F_103 ( & V_2 -> V_18 ) ;
F_19 ( & V_7 ) ;
}
F_21 ( & V_7 ) ;
F_12 ( V_16 ) ;
F_115 ( & V_16 -> V_4 ) ;
}
static void F_268 ( struct V_48 * V_19 )
{
struct V_15 * V_16 ;
V_16 = F_269 ( V_19 , & V_458 ) ;
if ( ! V_16 )
return;
F_19 ( & V_7 ) ;
F_20 ( & V_16 -> V_25 ) ;
F_21 ( & V_7 ) ;
F_267 ( V_16 ) ;
F_17 ( V_16 ) ;
}
static int F_270 ( struct V_461 * V_462 , struct V_463 * V_464 )
{
struct V_465 * V_466 ;
struct V_467 * V_468 ;
struct V_1 * V_2 ;
struct V_88 * V_18 = NULL ;
struct V_15 * V_16 ;
int V_469 = 0 , V_470 = 0 ;
F_19 ( & V_7 ) ;
F_41 (cma_dev, &dev_list, list) {
if ( V_469 < V_464 -> args [ 0 ] ) {
V_469 ++ ;
continue;
}
V_470 = 0 ;
F_41 (id_priv, &cma_dev->id_list, list) {
if ( V_470 < V_464 -> args [ 1 ] ) {
V_470 ++ ;
continue;
}
V_468 = F_271 ( V_462 , & V_466 , V_464 -> V_466 -> V_471 ,
sizeof *V_468 , V_472 ,
V_473 ) ;
if ( ! V_468 )
goto V_77;
memset ( V_468 , 0 , sizeof *V_468 ) ;
V_18 = & V_2 -> V_18 ;
V_468 -> V_24 = V_18 -> V_20 . V_21 . V_22 . V_61 ;
V_468 -> V_47 = V_18 -> V_47 ;
V_468 -> V_326 =
V_18 -> V_20 . V_21 . V_22 . V_326 ;
if ( F_272 ( V_462 , V_466 ,
F_150 ( F_22 ( V_2 ) ) ,
F_22 ( V_2 ) ,
V_474 ) )
goto V_77;
if ( F_272 ( V_462 , V_466 ,
F_150 ( F_22 ( V_2 ) ) ,
F_23 ( V_2 ) ,
V_475 ) )
goto V_77;
V_468 -> V_476 = V_2 -> V_96 ;
V_468 -> V_477 = V_18 -> V_41 ;
V_468 -> V_478 = V_2 -> V_8 ;
V_468 -> V_120 = V_2 -> V_120 ;
V_468 -> V_93 = V_18 -> V_93 ;
V_470 ++ ;
}
V_464 -> args [ 1 ] = 0 ;
V_469 ++ ;
}
V_77:
F_21 ( & V_7 ) ;
V_464 -> args [ 0 ] = V_469 ;
V_464 -> args [ 1 ] = V_470 ;
return V_462 -> V_479 ;
}
static int T_10 F_273 ( void )
{
int V_6 ;
V_297 = F_274 ( L_5 ) ;
if ( ! V_297 )
return - V_95 ;
F_275 ( & V_315 ) ;
F_276 ( & V_348 ) ;
F_277 ( & V_480 ) ;
V_6 = F_278 ( & V_458 ) ;
if ( V_6 )
goto V_52;
if ( F_279 ( V_472 , V_481 , V_482 ) )
F_121 ( V_287 L_6 ) ;
return 0 ;
V_52:
F_280 ( & V_480 ) ;
F_281 ( & V_348 ) ;
F_282 ( & V_315 ) ;
F_283 ( V_297 ) ;
return V_6 ;
}
static void T_11 F_284 ( void )
{
F_285 ( V_472 ) ;
F_286 ( & V_458 ) ;
F_280 ( & V_480 ) ;
F_281 ( & V_348 ) ;
F_282 ( & V_315 ) ;
F_283 ( V_297 ) ;
F_287 ( & V_370 ) ;
F_287 ( & V_371 ) ;
F_287 ( & V_372 ) ;
F_287 ( & V_373 ) ;
}
