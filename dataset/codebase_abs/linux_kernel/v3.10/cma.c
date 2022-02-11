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
static inline T_1 F_8 ( T_1 V_15 )
{
return V_15 >> 4 ;
}
static inline T_1 F_9 ( struct V_16 * V_17 )
{
return V_17 -> V_13 >> 4 ;
}
static inline void F_10 ( struct V_16 * V_17 , T_1 V_14 )
{
V_17 -> V_13 = ( V_14 << 4 ) | ( V_17 -> V_13 & 0xF ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
F_12 ( & V_19 -> V_20 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_21 . V_22 = V_19 -> V_22 ;
V_2 -> V_21 . V_23 . V_24 . V_25 . V_26 =
F_13 ( V_19 -> V_22 -> V_27 ) ;
F_14 ( & V_2 -> V_28 , & V_19 -> V_29 ) ;
}
static inline void F_15 ( struct V_18 * V_19 )
{
if ( F_16 ( & V_19 -> V_20 ) )
F_17 ( & V_19 -> V_4 ) ;
}
static inline void F_18 ( struct V_30 * V_30 )
{
struct V_31 * V_32 = F_19 ( V_30 , struct V_31 , V_33 ) ;
F_20 ( V_32 -> V_34 . V_35 ) ;
F_20 ( V_32 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_7 ) ;
F_23 ( & V_2 -> V_28 ) ;
F_15 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
F_24 ( & V_7 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_36 V_37 ;
int V_6 = 0 ;
if ( V_2 -> V_38 )
return 0 ;
switch ( V_2 -> V_21 . V_39 ) {
case V_40 :
V_2 -> V_38 = V_41 ;
break;
case V_42 :
F_26 ( & V_2 -> V_21 . V_23 . V_24 . V_25 , & V_37 . V_43 ) ;
V_6 = F_27 ( V_2 -> V_21 . V_22 ,
V_2 -> V_21 . V_44 , & V_37 . V_43 ,
& V_37 ) ;
if ( ! V_6 )
V_2 -> V_38 = F_28 ( V_37 . V_38 ) ;
break;
default:
break;
}
return V_6 ;
}
static int F_29 ( struct V_45 * V_22 , union V_46 * V_47 , T_1 V_44 )
{
int V_48 ;
int V_49 ;
struct V_50 V_51 ;
union V_46 V_52 ;
V_49 = F_30 ( V_22 , V_44 , & V_51 ) ;
if ( V_49 )
return V_49 ;
for ( V_48 = 0 ; V_48 < V_51 . V_53 ; ++ V_48 ) {
V_49 = F_31 ( V_22 , V_44 , V_48 , & V_52 ) ;
if ( V_49 )
return V_49 ;
if ( ! memcmp ( & V_52 , V_47 , sizeof V_52 ) )
return 0 ;
}
return - V_54 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_55 * V_25 = & V_2 -> V_21 . V_23 . V_24 . V_25 ;
struct V_18 * V_19 ;
union V_46 V_47 , V_56 ;
int V_6 = - V_57 ;
T_1 V_58 ;
enum V_59 V_60 = V_25 -> V_61 == V_62 ?
V_63 : V_64 ;
if ( V_60 != V_63 &&
V_2 -> V_21 . V_39 == V_42 )
return - V_65 ;
F_22 ( & V_7 ) ;
F_33 ( V_25 , & V_56 ) ;
memcpy ( & V_47 , V_25 -> V_66 +
F_34 ( V_25 ) , sizeof V_47 ) ;
F_35 (cma_dev, &dev_list, list) {
for ( V_58 = 1 ; V_58 <= V_19 -> V_22 -> V_67 ; ++ V_58 ) {
if ( F_36 ( V_19 -> V_22 , V_58 ) == V_60 ) {
if ( F_13 ( V_19 -> V_22 -> V_27 ) == V_68 &&
F_36 ( V_19 -> V_22 , V_58 ) == V_64 )
V_6 = F_29 ( V_19 -> V_22 , & V_56 , V_58 ) ;
else
V_6 = F_29 ( V_19 -> V_22 , & V_47 , V_58 ) ;
if ( ! V_6 ) {
V_2 -> V_21 . V_44 = V_58 ;
goto V_69;
}
}
}
}
V_69:
if ( ! V_6 )
F_11 ( V_2 , V_19 ) ;
F_24 ( & V_7 ) ;
return V_6 ;
}
static void F_37 ( struct V_1 * V_2 )
{
if ( F_16 ( & V_2 -> V_20 ) )
F_17 ( & V_2 -> V_4 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
enum V_3 V_8 )
{
F_22 ( & V_2 -> V_70 ) ;
if ( V_2 -> V_8 != V_8 ) {
F_24 ( & V_2 -> V_70 ) ;
return - V_65 ;
}
return 0 ;
}
struct V_71 * F_39 ( T_2 V_72 ,
void * V_73 , enum V_74 V_39 ,
enum V_75 V_76 )
{
struct V_1 * V_2 ;
V_2 = F_40 ( sizeof *V_2 , V_77 ) ;
if ( ! V_2 )
return F_41 ( - V_78 ) ;
V_2 -> V_79 = F_42 ( V_80 ) ;
V_2 -> V_8 = V_81 ;
V_2 -> V_21 . V_73 = V_73 ;
V_2 -> V_21 . V_72 = V_72 ;
V_2 -> V_21 . V_39 = V_39 ;
V_2 -> V_21 . V_76 = V_76 ;
F_43 ( & V_2 -> V_7 ) ;
F_44 ( & V_2 -> V_82 ) ;
F_45 ( & V_2 -> V_4 ) ;
F_46 ( & V_2 -> V_20 , 1 ) ;
F_44 ( & V_2 -> V_70 ) ;
F_47 ( & V_2 -> V_83 ) ;
F_47 ( & V_2 -> V_84 ) ;
F_48 ( & V_2 -> V_85 , sizeof V_2 -> V_85 ) ;
return & V_2 -> V_21 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_88 V_89 ;
int V_90 , V_6 ;
V_89 . V_91 = V_92 ;
V_6 = F_50 ( & V_2 -> V_21 , & V_89 , & V_90 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_51 ( V_87 , & V_89 , V_90 ) ;
if ( V_6 )
return V_6 ;
V_89 . V_91 = V_93 ;
V_6 = F_51 ( V_87 , & V_89 , V_94 ) ;
if ( V_6 )
return V_6 ;
V_89 . V_91 = V_95 ;
V_89 . V_96 = 0 ;
V_6 = F_51 ( V_87 , & V_89 , V_94 | V_97 ) ;
return V_6 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_88 V_89 ;
int V_90 , V_6 ;
V_89 . V_91 = V_92 ;
V_6 = F_50 ( & V_2 -> V_21 , & V_89 , & V_90 ) ;
if ( V_6 )
return V_6 ;
return F_51 ( V_87 , & V_89 , V_90 ) ;
}
int F_53 ( struct V_71 * V_21 , struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 ;
struct V_86 * V_87 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( V_21 -> V_22 != V_99 -> V_22 )
return - V_65 ;
V_87 = F_54 ( V_99 , V_101 ) ;
if ( F_55 ( V_87 ) )
return F_56 ( V_87 ) ;
if ( V_21 -> V_76 == V_102 )
V_6 = F_49 ( V_2 , V_87 ) ;
else
V_6 = F_52 ( V_2 , V_87 ) ;
if ( V_6 )
goto V_49;
V_21 -> V_87 = V_87 ;
V_2 -> V_103 = V_87 -> V_103 ;
V_2 -> V_104 = ( V_87 -> V_104 != NULL ) ;
return 0 ;
V_49:
F_57 ( V_87 ) ;
return V_6 ;
}
void F_58 ( struct V_71 * V_21 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
F_22 ( & V_2 -> V_82 ) ;
F_57 ( V_2 -> V_21 . V_87 ) ;
V_2 -> V_21 . V_87 = NULL ;
F_24 ( & V_2 -> V_82 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_88 V_89 ;
int V_90 , V_6 ;
F_22 ( & V_2 -> V_82 ) ;
if ( ! V_2 -> V_21 . V_87 ) {
V_6 = 0 ;
goto V_69;
}
V_89 . V_91 = V_92 ;
V_6 = F_50 ( & V_2 -> V_21 , & V_89 , & V_90 ) ;
if ( V_6 )
goto V_69;
V_6 = F_51 ( V_2 -> V_21 . V_87 , & V_89 , V_90 ) ;
if ( V_6 )
goto V_69;
V_89 . V_91 = V_93 ;
V_6 = F_50 ( & V_2 -> V_21 , & V_89 , & V_90 ) ;
if ( V_6 )
goto V_69;
if ( V_106 )
V_89 . V_107 = V_106 -> V_108 ;
V_6 = F_51 ( V_2 -> V_21 . V_87 , & V_89 , V_90 ) ;
V_69:
F_24 ( & V_2 -> V_82 ) ;
return V_6 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_88 V_89 ;
int V_90 , V_6 ;
F_22 ( & V_2 -> V_82 ) ;
if ( ! V_2 -> V_21 . V_87 ) {
V_6 = 0 ;
goto V_69;
}
V_89 . V_91 = V_95 ;
V_6 = F_50 ( & V_2 -> V_21 , & V_89 , & V_90 ) ;
if ( V_6 )
goto V_69;
if ( V_106 )
V_89 . V_109 = V_106 -> V_110 ;
V_6 = F_51 ( V_2 -> V_21 . V_87 , & V_89 , V_90 ) ;
V_69:
F_24 ( & V_2 -> V_82 ) ;
return V_6 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_88 V_89 ;
int V_6 ;
F_22 ( & V_2 -> V_82 ) ;
if ( ! V_2 -> V_21 . V_87 ) {
V_6 = 0 ;
goto V_69;
}
V_89 . V_91 = V_111 ;
V_6 = F_51 ( V_2 -> V_21 . V_87 , & V_89 , V_94 ) ;
V_69:
F_24 ( & V_2 -> V_82 ) ;
return V_6 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_88 * V_89 , int * V_90 )
{
struct V_55 * V_25 = & V_2 -> V_21 . V_23 . V_24 . V_25 ;
int V_6 ;
T_3 V_112 ;
if ( F_36 ( V_2 -> V_21 . V_22 , V_2 -> V_21 . V_44 ) ==
V_63 )
V_112 = F_63 ( V_25 ) ;
else
V_112 = 0xffff ;
V_6 = F_64 ( V_2 -> V_21 . V_22 , V_2 -> V_21 . V_44 ,
V_112 , & V_89 -> V_113 ) ;
if ( V_6 )
return V_6 ;
V_89 -> V_44 = V_2 -> V_21 . V_44 ;
* V_90 = V_94 | V_114 | V_115 ;
if ( V_2 -> V_21 . V_76 == V_102 ) {
V_6 = F_25 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_89 -> V_38 = V_2 -> V_38 ;
* V_90 |= V_116 ;
} else {
V_89 -> V_117 = 0 ;
* V_90 |= V_118 ;
}
return 0 ;
}
int F_50 ( struct V_71 * V_21 , struct V_88 * V_89 ,
int * V_90 )
{
struct V_1 * V_2 ;
int V_6 = 0 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
switch ( F_13 ( V_2 -> V_21 . V_22 -> V_27 ) ) {
case V_68 :
if ( ! V_2 -> V_119 . V_35 || ( V_2 -> V_21 . V_76 == V_102 ) )
V_6 = F_62 ( V_2 , V_89 , V_90 ) ;
else
V_6 = F_65 ( V_2 -> V_119 . V_35 , V_89 ,
V_90 ) ;
if ( V_89 -> V_91 == V_93 )
V_89 -> V_120 = V_2 -> V_85 ;
break;
case V_121 :
if ( ! V_2 -> V_119 . V_122 ) {
V_89 -> V_117 = 0 ;
* V_90 = V_94 | V_118 ;
} else
V_6 = F_66 ( V_2 -> V_119 . V_122 , V_89 ,
V_90 ) ;
break;
default:
V_6 = - V_123 ;
break;
}
return V_6 ;
}
static inline int F_67 ( struct V_124 * V_24 )
{
struct V_125 * V_126 ;
if ( V_24 -> V_127 == V_128 )
return F_68 (
( (struct V_129 * ) V_24 ) -> V_130 . V_131 ) ;
else {
V_126 = & ( (struct V_132 * ) V_24 ) -> V_133 ;
return ( V_126 -> V_134 [ 0 ] | V_126 -> V_134 [ 1 ] |
V_126 -> V_134 [ 2 ] | V_126 -> V_134 [ 3 ] ) == 0 ;
}
}
static inline int F_69 ( struct V_124 * V_24 )
{
if ( V_24 -> V_127 == V_128 )
return F_70 (
( (struct V_129 * ) V_24 ) -> V_130 . V_131 ) ;
else
return F_71 (
& ( (struct V_132 * ) V_24 ) -> V_133 ) ;
}
static inline int F_72 ( struct V_124 * V_24 )
{
return F_67 ( V_24 ) || F_69 ( V_24 ) ;
}
static int F_73 ( struct V_124 * V_135 , struct V_124 * V_136 )
{
if ( V_135 -> V_127 != V_136 -> V_127 )
return - 1 ;
switch ( V_135 -> V_127 ) {
case V_128 :
return ( (struct V_129 * ) V_135 ) -> V_130 . V_131 !=
( (struct V_129 * ) V_136 ) -> V_130 . V_131 ;
default:
return F_74 ( & ( (struct V_132 * ) V_135 ) -> V_133 ,
& ( (struct V_132 * ) V_136 ) -> V_133 ) ;
}
}
static inline T_4 F_75 ( struct V_124 * V_24 )
{
if ( V_24 -> V_127 == V_128 )
return ( (struct V_129 * ) V_24 ) -> V_137 ;
else
return ( (struct V_132 * ) V_24 ) -> V_138 ;
}
static inline int F_76 ( struct V_124 * V_24 )
{
return ! F_75 ( V_24 ) ;
}
static int F_77 ( void * V_12 , enum V_74 V_39 ,
T_1 * V_14 , T_4 * V_58 ,
union V_139 * * V_135 , union V_139 * * V_136 )
{
switch ( V_39 ) {
case V_140 :
if ( F_8 ( ( (struct V_16 * ) V_12 ) -> V_15 ) !=
V_141 )
return - V_65 ;
* V_14 = F_9 ( V_12 ) ;
* V_58 = ( (struct V_16 * ) V_12 ) -> V_58 ;
* V_135 = & ( (struct V_16 * ) V_12 ) -> V_142 ;
* V_136 = & ( (struct V_16 * ) V_12 ) -> V_143 ;
break;
default:
if ( ( (struct V_11 * ) V_12 ) -> V_144 != V_145 )
return - V_65 ;
* V_14 = F_6 ( V_12 ) ;
* V_58 = ( (struct V_11 * ) V_12 ) -> V_58 ;
* V_135 = & ( (struct V_11 * ) V_12 ) -> V_142 ;
* V_136 = & ( (struct V_11 * ) V_12 ) -> V_143 ;
break;
}
if ( * V_14 != 4 && * V_14 != 6 )
return - V_65 ;
return 0 ;
}
static void F_78 ( struct V_146 * V_24 ,
struct V_146 * V_147 ,
T_1 V_14 , T_4 V_58 ,
union V_139 * V_135 , union V_139 * V_136 )
{
struct V_129 * V_148 , * V_149 ;
struct V_132 * V_150 , * V_126 ;
switch ( V_14 ) {
case 4 :
V_148 = (struct V_129 * ) & V_147 -> V_142 ;
V_149 = (struct V_129 * ) & V_24 -> V_142 ;
V_149 -> V_151 = V_148 -> V_151 ;
V_149 -> V_130 . V_131 = V_136 -> V_149 . V_24 ;
V_149 -> V_137 = V_148 -> V_137 ;
V_149 = (struct V_129 * ) & V_24 -> V_143 ;
V_149 -> V_151 = V_148 -> V_151 ;
V_149 -> V_130 . V_131 = V_135 -> V_149 . V_24 ;
V_149 -> V_137 = V_58 ;
break;
case 6 :
V_150 = (struct V_132 * ) & V_147 -> V_142 ;
V_126 = (struct V_132 * ) & V_24 -> V_142 ;
V_126 -> V_152 = V_150 -> V_152 ;
V_126 -> V_133 = V_136 -> V_126 ;
V_126 -> V_138 = V_150 -> V_138 ;
V_126 = (struct V_132 * ) & V_24 -> V_143 ;
V_126 -> V_152 = V_150 -> V_152 ;
V_126 -> V_133 = V_135 -> V_126 ;
V_126 -> V_138 = V_58 ;
break;
default:
break;
}
}
static inline int F_79 ( enum V_74 V_39 )
{
switch ( V_39 ) {
case V_140 :
return 0 ;
default:
return sizeof( struct V_11 ) ;
}
}
static void F_80 ( struct V_1 * V_2 )
{
switch ( F_36 ( V_2 -> V_21 . V_22 , V_2 -> V_21 . V_44 ) ) {
case V_63 :
if ( V_2 -> V_153 )
F_81 ( V_2 -> V_154 , V_2 -> V_153 ) ;
break;
default:
break;
}
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_1 * V_155 ;
F_22 ( & V_7 ) ;
F_23 ( & V_2 -> V_28 ) ;
while ( ! F_83 ( & V_2 -> V_83 ) ) {
V_155 = F_84 ( V_2 -> V_83 . V_156 ,
struct V_1 , V_83 ) ;
F_85 ( & V_155 -> V_28 ) ;
F_23 ( & V_155 -> V_83 ) ;
F_24 ( & V_7 ) ;
F_86 ( & V_155 -> V_21 ) ;
F_22 ( & V_7 ) ;
}
F_24 ( & V_7 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
enum V_3 V_8 )
{
switch ( V_8 ) {
case V_157 :
F_88 ( & V_2 -> V_21 . V_23 . V_24 . V_25 ) ;
break;
case V_158 :
F_80 ( V_2 ) ;
break;
case V_159 :
if ( F_72 ( (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 )
&& ! V_2 -> V_19 )
F_82 ( V_2 ) ;
break;
default:
break;
}
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_160 * V_161 = V_2 -> V_161 ;
if ( ! V_161 )
return;
F_22 ( & V_7 ) ;
F_90 ( & V_2 -> V_162 ) ;
if ( F_91 ( & V_161 -> V_163 ) ) {
F_92 ( V_161 -> V_39 , V_161 -> V_58 ) ;
F_20 ( V_161 ) ;
}
F_24 ( & V_7 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
while ( ! F_83 ( & V_2 -> V_84 ) ) {
V_32 = F_19 ( V_2 -> V_84 . V_156 ,
struct V_31 , V_28 ) ;
F_23 ( & V_32 -> V_28 ) ;
switch ( F_36 ( V_2 -> V_19 -> V_22 , V_2 -> V_21 . V_44 ) ) {
case V_63 :
F_94 ( V_32 -> V_34 . V_35 ) ;
F_20 ( V_32 ) ;
break;
case V_64 :
F_95 ( & V_32 -> V_33 , F_18 ) ;
break;
default:
break;
}
}
}
void F_86 ( struct V_71 * V_21 )
{
struct V_1 * V_2 ;
enum V_3 V_8 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
V_8 = F_5 ( V_2 , V_164 ) ;
F_87 ( V_2 , V_8 ) ;
F_22 ( & V_2 -> V_70 ) ;
F_24 ( & V_2 -> V_70 ) ;
if ( V_2 -> V_19 ) {
switch ( F_13 ( V_2 -> V_21 . V_22 -> V_27 ) ) {
case V_68 :
if ( V_2 -> V_119 . V_35 )
F_96 ( V_2 -> V_119 . V_35 ) ;
break;
case V_121 :
if ( V_2 -> V_119 . V_122 )
F_97 ( V_2 -> V_119 . V_122 ) ;
break;
default:
break;
}
F_93 ( V_2 ) ;
F_21 ( V_2 ) ;
}
F_89 ( V_2 ) ;
F_37 ( V_2 ) ;
F_98 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_165 )
F_37 ( V_2 -> V_21 . V_73 ) ;
F_20 ( V_2 -> V_21 . V_23 . V_166 ) ;
F_20 ( V_2 ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_59 ( V_2 , NULL ) ;
if ( V_6 )
goto V_167;
V_6 = F_60 ( V_2 , NULL ) ;
if ( V_6 )
goto V_167;
V_6 = F_100 ( V_2 -> V_119 . V_35 , NULL , 0 ) ;
if ( V_6 )
goto V_167;
return 0 ;
V_167:
F_61 ( V_2 ) ;
F_101 ( V_2 -> V_119 . V_35 , V_168 ,
NULL , 0 , NULL , 0 ) ;
return V_6 ;
}
static int F_102 ( struct V_1 * V_2 , void * V_169 )
{
if ( V_2 -> V_21 . V_39 == V_140 &&
F_8 ( ( (struct V_170 * ) V_169 ) -> V_15 ) !=
V_141 )
return - V_65 ;
return 0 ;
}
static void F_103 ( struct V_171 * V_172 ,
struct V_173 * V_174 ,
void * V_175 )
{
V_172 -> V_176 . V_177 . V_175 = V_175 ;
V_172 -> V_176 . V_177 . V_178 = V_179 ;
V_172 -> V_176 . V_177 . V_108 = V_174 -> V_108 ;
V_172 -> V_176 . V_177 . V_110 = V_174 -> V_110 ;
V_172 -> V_176 . V_177 . V_180 = V_174 -> V_180 ;
V_172 -> V_176 . V_177 . V_181 = V_174 -> V_181 ;
V_172 -> V_176 . V_177 . V_104 = V_174 -> V_104 ;
V_172 -> V_176 . V_177 . V_103 = V_174 -> V_182 ;
}
static int F_104 ( struct V_183 * V_119 , struct V_184 * V_185 )
{
struct V_1 * V_2 = V_119 -> V_73 ;
struct V_171 V_172 ;
int V_6 = 0 ;
if ( ( V_185 -> V_172 != V_186 &&
F_38 ( V_2 , V_187 ) ) ||
( V_185 -> V_172 == V_186 &&
F_38 ( V_2 , V_188 ) ) )
return 0 ;
memset ( & V_172 , 0 , sizeof V_172 ) ;
switch ( V_185 -> V_172 ) {
case V_189 :
case V_190 :
V_172 . V_172 = V_191 ;
V_172 . V_192 = - V_193 ;
break;
case V_194 :
V_172 . V_192 = F_102 ( V_2 , V_185 -> V_175 ) ;
if ( V_172 . V_192 )
V_172 . V_172 = V_195 ;
else if ( V_2 -> V_21 . V_87 && V_2 -> V_21 . V_39 != V_140 ) {
V_172 . V_192 = F_99 ( V_2 ) ;
V_172 . V_172 = V_172 . V_192 ? V_195 :
V_196 ;
} else
V_172 . V_172 = V_197 ;
F_103 ( & V_172 , & V_185 -> V_176 . V_198 ,
V_185 -> V_175 ) ;
break;
case V_199 :
case V_200 :
V_172 . V_172 = V_196 ;
break;
case V_201 :
V_172 . V_192 = - V_193 ;
case V_202 :
case V_203 :
if ( ! F_4 ( V_2 , V_187 ,
V_188 ) )
goto V_69;
V_172 . V_172 = V_204 ;
break;
case V_186 :
V_172 . V_172 = V_205 ;
break;
case V_206 :
goto V_69;
case V_207 :
F_61 ( V_2 ) ;
V_172 . V_192 = V_185 -> V_176 . V_208 . V_209 ;
V_172 . V_172 = V_210 ;
V_172 . V_176 . V_177 . V_175 = V_185 -> V_175 ;
V_172 . V_176 . V_177 . V_178 = V_211 ;
break;
default:
F_105 ( V_212 L_1 ,
V_185 -> V_172 ) ;
goto V_69;
}
V_6 = V_2 -> V_21 . V_72 ( & V_2 -> V_21 , & V_172 ) ;
if ( V_6 ) {
V_2 -> V_119 . V_35 = NULL ;
F_5 ( V_2 , V_164 ) ;
F_24 ( & V_2 -> V_70 ) ;
F_86 ( & V_2 -> V_21 ) ;
return V_6 ;
}
V_69:
F_24 ( & V_2 -> V_70 ) ;
return V_6 ;
}
static struct V_1 * F_106 ( struct V_71 * V_213 ,
struct V_184 * V_185 )
{
struct V_1 * V_2 ;
struct V_71 * V_21 ;
struct V_214 * V_215 ;
union V_139 * V_135 , * V_136 ;
T_4 V_58 ;
T_1 V_14 ;
int V_6 ;
if ( F_77 ( V_185 -> V_175 , V_213 -> V_39 ,
& V_14 , & V_58 , & V_135 , & V_136 ) )
return NULL ;
V_21 = F_39 ( V_213 -> V_72 , V_213 -> V_73 ,
V_213 -> V_39 , V_185 -> V_176 . V_216 . V_76 ) ;
if ( F_55 ( V_21 ) )
return NULL ;
F_78 ( & V_21 -> V_23 . V_24 , & V_213 -> V_23 . V_24 ,
V_14 , V_58 , V_135 , V_136 ) ;
V_215 = & V_21 -> V_23 ;
V_215 -> V_217 = V_185 -> V_176 . V_216 . V_218 ? 2 : 1 ;
V_215 -> V_166 = F_107 ( sizeof * V_215 -> V_166 * V_215 -> V_217 ,
V_77 ) ;
if ( ! V_215 -> V_166 )
goto V_49;
V_215 -> V_166 [ 0 ] = * V_185 -> V_176 . V_216 . V_219 ;
if ( V_215 -> V_217 == 2 )
V_215 -> V_166 [ 1 ] = * V_185 -> V_176 . V_216 . V_218 ;
if ( F_72 ( (struct V_124 * ) & V_215 -> V_24 . V_142 ) ) {
V_215 -> V_24 . V_25 . V_61 = V_62 ;
F_108 ( & V_215 -> V_24 . V_25 , & V_215 -> V_166 [ 0 ] . V_220 ) ;
F_109 ( & V_215 -> V_24 . V_25 , F_110 ( V_215 -> V_166 [ 0 ] . V_112 ) ) ;
} else {
V_6 = F_111 ( (struct V_124 * ) & V_215 -> V_24 . V_142 ,
& V_215 -> V_24 . V_25 ) ;
if ( V_6 )
goto V_49;
}
F_112 ( & V_215 -> V_24 . V_25 , & V_215 -> V_166 [ 0 ] . V_221 ) ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
V_2 -> V_8 = V_187 ;
return V_2 ;
V_49:
F_86 ( V_21 ) ;
return NULL ;
}
static struct V_1 * F_113 ( struct V_71 * V_213 ,
struct V_184 * V_185 )
{
struct V_1 * V_2 ;
struct V_71 * V_21 ;
union V_139 * V_135 , * V_136 ;
T_4 V_58 ;
T_1 V_14 ;
int V_6 ;
V_21 = F_39 ( V_213 -> V_72 , V_213 -> V_73 ,
V_213 -> V_39 , V_102 ) ;
if ( F_55 ( V_21 ) )
return NULL ;
if ( F_77 ( V_185 -> V_175 , V_213 -> V_39 ,
& V_14 , & V_58 , & V_135 , & V_136 ) )
goto V_49;
F_78 ( & V_21 -> V_23 . V_24 , & V_213 -> V_23 . V_24 ,
V_14 , V_58 , V_135 , V_136 ) ;
if ( ! F_72 ( (struct V_124 * ) & V_21 -> V_23 . V_24 . V_142 ) ) {
V_6 = F_111 ( (struct V_124 * ) & V_21 -> V_23 . V_24 . V_142 ,
& V_21 -> V_23 . V_24 . V_25 ) ;
if ( V_6 )
goto V_49;
}
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
V_2 -> V_8 = V_187 ;
return V_2 ;
V_49:
F_86 ( V_21 ) ;
return NULL ;
}
static void F_114 ( struct V_171 * V_172 ,
struct V_222 * V_223 ,
void * V_175 , int V_224 )
{
V_172 -> V_176 . V_177 . V_175 = V_175 + V_224 ;
V_172 -> V_176 . V_177 . V_178 = V_225 - V_224 ;
V_172 -> V_176 . V_177 . V_108 = V_223 -> V_108 ;
V_172 -> V_176 . V_177 . V_110 = V_223 -> V_110 ;
V_172 -> V_176 . V_177 . V_180 = V_223 -> V_180 ;
V_172 -> V_176 . V_177 . V_226 = V_223 -> V_226 ;
V_172 -> V_176 . V_177 . V_181 = V_223 -> V_181 ;
V_172 -> V_176 . V_177 . V_104 = V_223 -> V_104 ;
V_172 -> V_176 . V_177 . V_103 = V_223 -> V_182 ;
}
static int F_115 ( struct V_71 * V_21 , struct V_184 * V_185 )
{
return ( ( ( V_185 -> V_172 == V_227 ) &&
( V_185 -> V_176 . V_216 . V_76 == V_21 -> V_76 ) ) ||
( ( V_185 -> V_172 == V_228 ) &&
( V_21 -> V_76 == V_102 ) ) ||
( ! V_21 -> V_76 ) ) ;
}
static int F_116 ( struct V_183 * V_119 , struct V_184 * V_185 )
{
struct V_1 * V_213 , * V_229 ;
struct V_171 V_172 ;
int V_224 , V_6 ;
V_213 = V_119 -> V_73 ;
if ( ! F_115 ( & V_213 -> V_21 , V_185 ) )
return - V_65 ;
if ( F_38 ( V_213 , V_159 ) )
return - V_230 ;
memset ( & V_172 , 0 , sizeof V_172 ) ;
V_224 = F_79 ( V_213 -> V_21 . V_39 ) ;
V_172 . V_172 = V_231 ;
if ( V_185 -> V_172 == V_228 ) {
V_229 = F_113 ( & V_213 -> V_21 , V_185 ) ;
V_172 . V_176 . V_232 . V_175 = V_185 -> V_175 + V_224 ;
V_172 . V_176 . V_232 . V_178 =
V_233 - V_224 ;
} else {
V_229 = F_106 ( & V_213 -> V_21 , V_185 ) ;
F_114 ( & V_172 , & V_185 -> V_176 . V_216 ,
V_185 -> V_175 , V_224 ) ;
}
if ( ! V_229 ) {
V_6 = - V_78 ;
goto V_234;
}
F_117 ( & V_229 -> V_70 , V_235 ) ;
V_6 = F_32 ( V_229 ) ;
if ( V_6 )
goto V_236;
V_229 -> V_119 . V_35 = V_119 ;
V_119 -> V_73 = V_229 ;
V_119 -> V_237 = F_104 ;
F_12 ( & V_229 -> V_20 ) ;
V_6 = V_229 -> V_21 . V_72 ( & V_229 -> V_21 , & V_172 ) ;
if ( V_6 )
goto V_238;
F_22 ( & V_7 ) ;
if ( F_1 ( V_229 , V_187 ) && ( V_229 -> V_21 . V_76 != V_102 ) )
F_118 ( V_119 , V_239 , NULL , 0 ) ;
F_24 ( & V_7 ) ;
F_24 ( & V_229 -> V_70 ) ;
F_24 ( & V_213 -> V_70 ) ;
F_37 ( V_229 ) ;
return 0 ;
V_238:
F_37 ( V_229 ) ;
V_229 -> V_119 . V_35 = NULL ;
V_236:
F_5 ( V_229 , V_164 ) ;
F_24 ( & V_229 -> V_70 ) ;
V_234:
F_24 ( & V_213 -> V_70 ) ;
if ( V_229 )
F_86 ( & V_229 -> V_21 ) ;
return V_6 ;
}
static T_5 F_119 ( enum V_74 V_39 , struct V_124 * V_24 )
{
return F_120 ( ( ( V_240 ) V_39 << 16 ) + F_110 ( F_75 ( V_24 ) ) ) ;
}
static void F_121 ( enum V_74 V_39 , struct V_124 * V_24 ,
struct V_241 * V_242 )
{
struct V_11 * V_243 , * V_244 ;
struct V_16 * V_245 , * V_246 ;
T_6 V_247 ;
struct V_125 V_248 ;
memset ( V_242 , 0 , sizeof *V_242 ) ;
V_243 = ( void * ) V_242 -> V_169 ;
V_244 = ( void * ) V_242 -> V_249 ;
V_245 = ( void * ) V_242 -> V_169 ;
V_246 = ( void * ) V_242 -> V_249 ;
switch ( V_24 -> V_127 ) {
case V_128 :
V_247 = ( (struct V_129 * ) V_24 ) -> V_130 . V_131 ;
if ( V_39 == V_140 ) {
F_10 ( V_245 , 4 ) ;
F_10 ( V_246 , 0xF ) ;
V_245 -> V_143 . V_149 . V_24 = V_247 ;
V_246 -> V_143 . V_149 . V_24 = F_122 ( ~ 0 ) ;
} else {
F_7 ( V_243 , 4 ) ;
F_7 ( V_244 , 0xF ) ;
if ( ! F_72 ( V_24 ) ) {
V_243 -> V_143 . V_149 . V_24 = V_247 ;
V_244 -> V_143 . V_149 . V_24 = F_122 ( ~ 0 ) ;
}
}
break;
case V_250 :
V_248 = ( (struct V_132 * ) V_24 ) -> V_133 ;
if ( V_39 == V_140 ) {
F_10 ( V_245 , 6 ) ;
F_10 ( V_246 , 0xF ) ;
V_245 -> V_143 . V_126 = V_248 ;
memset ( & V_246 -> V_143 . V_126 , 0xFF ,
sizeof V_246 -> V_143 . V_126 ) ;
} else {
F_7 ( V_243 , 6 ) ;
F_7 ( V_244 , 0xF ) ;
if ( ! F_72 ( V_24 ) ) {
V_243 -> V_143 . V_126 = V_248 ;
memset ( & V_244 -> V_143 . V_126 , 0xFF ,
sizeof V_244 -> V_143 . V_126 ) ;
}
}
break;
default:
break;
}
}
static int F_123 ( struct V_251 * V_252 , struct V_253 * V_254 )
{
struct V_1 * V_2 = V_252 -> V_73 ;
struct V_171 V_172 ;
struct V_129 * sin ;
int V_6 = 0 ;
if ( F_38 ( V_2 , V_187 ) )
return 0 ;
memset ( & V_172 , 0 , sizeof V_172 ) ;
switch ( V_254 -> V_172 ) {
case V_255 :
V_172 . V_172 = V_204 ;
break;
case V_256 :
sin = (struct V_129 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
* sin = V_254 -> V_257 ;
sin = (struct V_129 * ) & V_2 -> V_21 . V_23 . V_24 . V_143 ;
* sin = V_254 -> V_258 ;
switch ( V_254 -> V_192 ) {
case 0 :
V_172 . V_172 = V_196 ;
V_172 . V_176 . V_177 . V_110 = V_254 -> V_259 ;
V_172 . V_176 . V_177 . V_108 = V_254 -> V_260 ;
break;
case - V_261 :
case - V_262 :
V_172 . V_172 = V_210 ;
break;
case - V_193 :
V_172 . V_172 = V_191 ;
break;
default:
V_172 . V_172 = V_195 ;
break;
}
break;
case V_263 :
V_172 . V_172 = V_196 ;
V_172 . V_176 . V_177 . V_110 = V_254 -> V_259 ;
V_172 . V_176 . V_177 . V_108 = V_254 -> V_260 ;
break;
default:
F_124 ( 1 ) ;
}
V_172 . V_192 = V_254 -> V_192 ;
V_172 . V_176 . V_177 . V_175 = V_254 -> V_175 ;
V_172 . V_176 . V_177 . V_178 = V_254 -> V_178 ;
V_6 = V_2 -> V_21 . V_72 ( & V_2 -> V_21 , & V_172 ) ;
if ( V_6 ) {
V_2 -> V_119 . V_122 = NULL ;
F_5 ( V_2 , V_164 ) ;
F_24 ( & V_2 -> V_70 ) ;
F_86 ( & V_2 -> V_21 ) ;
return V_6 ;
}
F_24 ( & V_2 -> V_70 ) ;
return V_6 ;
}
static int F_125 ( struct V_251 * V_119 ,
struct V_253 * V_254 )
{
struct V_71 * V_264 ;
struct V_1 * V_213 , * V_229 ;
struct V_129 * sin ;
struct V_265 * V_266 = NULL ;
struct V_171 V_172 ;
int V_6 ;
struct V_267 V_268 ;
V_213 = V_119 -> V_73 ;
if ( F_38 ( V_213 , V_159 ) )
return - V_230 ;
V_264 = F_39 ( V_213 -> V_21 . V_72 ,
V_213 -> V_21 . V_73 ,
V_269 , V_270 ) ;
if ( F_55 ( V_264 ) ) {
V_6 = - V_78 ;
goto V_69;
}
V_229 = F_19 ( V_264 , struct V_1 , V_21 ) ;
F_117 ( & V_229 -> V_70 , V_235 ) ;
V_229 -> V_8 = V_187 ;
V_266 = F_126 ( & V_271 , V_254 -> V_257 . V_130 . V_131 ) ;
if ( ! V_266 ) {
V_6 = - V_54 ;
F_24 ( & V_229 -> V_70 ) ;
F_86 ( V_264 ) ;
goto V_69;
}
V_6 = F_127 ( & V_229 -> V_21 . V_23 . V_24 . V_25 , V_266 , NULL ) ;
if ( V_6 ) {
F_24 ( & V_229 -> V_70 ) ;
F_86 ( V_264 ) ;
goto V_69;
}
V_6 = F_32 ( V_229 ) ;
if ( V_6 ) {
F_24 ( & V_229 -> V_70 ) ;
F_86 ( V_264 ) ;
goto V_69;
}
V_229 -> V_119 . V_122 = V_119 ;
V_119 -> V_73 = V_229 ;
V_119 -> V_237 = F_123 ;
sin = (struct V_129 * ) & V_264 -> V_23 . V_24 . V_142 ;
* sin = V_254 -> V_257 ;
sin = (struct V_129 * ) & V_264 -> V_23 . V_24 . V_143 ;
* sin = V_254 -> V_258 ;
V_6 = F_128 ( V_229 -> V_21 . V_22 , & V_268 ) ;
if ( V_6 ) {
F_24 ( & V_229 -> V_70 ) ;
F_86 ( V_264 ) ;
goto V_69;
}
memset ( & V_172 , 0 , sizeof V_172 ) ;
V_172 . V_172 = V_231 ;
V_172 . V_176 . V_177 . V_175 = V_254 -> V_175 ;
V_172 . V_176 . V_177 . V_178 = V_254 -> V_178 ;
V_172 . V_176 . V_177 . V_110 = V_254 -> V_259 ;
V_172 . V_176 . V_177 . V_108 = V_254 -> V_260 ;
F_12 ( & V_229 -> V_20 ) ;
V_6 = V_229 -> V_21 . V_72 ( & V_229 -> V_21 , & V_172 ) ;
if ( V_6 ) {
V_229 -> V_119 . V_122 = NULL ;
F_5 ( V_229 , V_164 ) ;
F_24 ( & V_229 -> V_70 ) ;
F_37 ( V_229 ) ;
F_86 ( & V_229 -> V_21 ) ;
goto V_69;
}
F_24 ( & V_229 -> V_70 ) ;
F_37 ( V_229 ) ;
V_69:
if ( V_266 )
F_129 ( V_266 ) ;
F_24 ( & V_213 -> V_70 ) ;
return V_6 ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_241 V_272 ;
struct V_124 * V_24 ;
struct V_183 * V_21 ;
T_5 V_273 ;
int V_6 ;
V_21 = F_131 ( V_2 -> V_21 . V_22 , F_116 , V_2 ) ;
if ( F_55 ( V_21 ) )
return F_56 ( V_21 ) ;
V_2 -> V_119 . V_35 = V_21 ;
V_24 = (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
V_273 = F_119 ( V_2 -> V_21 . V_39 , V_24 ) ;
if ( F_72 ( V_24 ) && ! V_2 -> V_274 )
V_6 = F_132 ( V_2 -> V_119 . V_35 , V_273 , 0 , NULL ) ;
else {
F_121 ( V_2 -> V_21 . V_39 , V_24 , & V_272 ) ;
V_6 = F_132 ( V_2 -> V_119 . V_35 , V_273 , 0 , & V_272 ) ;
}
if ( V_6 ) {
F_96 ( V_2 -> V_119 . V_35 ) ;
V_2 -> V_119 . V_35 = NULL ;
}
return V_6 ;
}
static int F_133 ( struct V_1 * V_2 , int V_275 )
{
int V_6 ;
struct V_129 * sin ;
struct V_251 * V_21 ;
V_21 = F_134 ( V_2 -> V_21 . V_22 ,
F_125 ,
V_2 ) ;
if ( F_55 ( V_21 ) )
return F_56 ( V_21 ) ;
V_2 -> V_119 . V_122 = V_21 ;
sin = (struct V_129 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
V_2 -> V_119 . V_122 -> V_257 = * sin ;
V_6 = F_135 ( V_2 -> V_119 . V_122 , V_275 ) ;
if ( V_6 ) {
F_97 ( V_2 -> V_119 . V_122 ) ;
V_2 -> V_119 . V_122 = NULL ;
}
return V_6 ;
}
static int F_136 ( struct V_71 * V_21 ,
struct V_171 * V_172 )
{
struct V_1 * V_2 = V_21 -> V_73 ;
V_21 -> V_73 = V_2 -> V_21 . V_73 ;
V_21 -> V_72 = V_2 -> V_21 . V_72 ;
return V_2 -> V_21 . V_72 ( V_21 , V_172 ) ;
}
static void F_137 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_1 * V_155 ;
struct V_71 * V_21 ;
int V_6 ;
V_21 = F_39 ( F_136 , V_2 , V_2 -> V_21 . V_39 ,
V_2 -> V_21 . V_76 ) ;
if ( F_55 ( V_21 ) )
return;
V_155 = F_19 ( V_21 , struct V_1 , V_21 ) ;
V_155 -> V_8 = V_276 ;
memcpy ( & V_21 -> V_23 . V_24 . V_142 , & V_2 -> V_21 . V_23 . V_24 . V_142 ,
F_138 ( (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ) ) ;
F_11 ( V_155 , V_19 ) ;
F_14 ( & V_155 -> V_83 , & V_2 -> V_83 ) ;
F_12 ( & V_2 -> V_20 ) ;
V_155 -> V_165 = 1 ;
V_155 -> V_274 = V_2 -> V_274 ;
V_6 = F_139 ( V_21 , V_2 -> V_275 ) ;
if ( V_6 )
F_105 ( V_277 L_2
L_3 , V_6 , V_19 -> V_22 -> V_278 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
F_22 ( & V_7 ) ;
F_14 ( & V_2 -> V_28 , & V_279 ) ;
F_35 (cma_dev, &dev_list, list)
F_137 ( V_2 , V_19 ) ;
F_24 ( & V_7 ) ;
}
void F_141 ( struct V_71 * V_21 , int V_280 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
V_2 -> V_280 = ( T_1 ) V_280 ;
}
static void F_142 ( int V_192 , struct V_281 * V_166 ,
void * V_73 )
{
struct V_282 * V_283 = V_73 ;
struct V_214 * V_23 ;
V_23 = & V_283 -> V_21 -> V_21 . V_23 ;
if ( ! V_192 ) {
V_23 -> V_217 = 1 ;
* V_23 -> V_166 = * V_166 ;
} else {
V_283 -> V_284 = V_158 ;
V_283 -> V_285 = V_286 ;
V_283 -> V_172 . V_172 = V_287 ;
V_283 -> V_172 . V_192 = V_192 ;
}
F_143 ( V_288 , & V_283 -> V_283 ) ;
}
static int F_144 ( struct V_1 * V_2 , int V_289 ,
struct V_282 * V_283 )
{
struct V_146 * V_24 = & V_2 -> V_21 . V_23 . V_24 ;
struct V_281 V_166 ;
T_7 V_290 ;
struct V_132 * V_291 ;
memset ( & V_166 , 0 , sizeof V_166 ) ;
F_145 ( & V_24 -> V_25 , & V_166 . V_220 ) ;
F_146 ( & V_24 -> V_25 , & V_166 . V_221 ) ;
V_166 . V_112 = F_147 ( F_63 ( & V_24 -> V_25 ) ) ;
V_166 . V_292 = 1 ;
V_166 . V_293 = 1 ;
V_166 . V_294 = F_119 ( V_2 -> V_21 . V_39 ,
(struct V_124 * ) & V_24 -> V_143 ) ;
V_290 = V_295 | V_296 |
V_297 | V_298 |
V_299 | V_300 ;
if ( V_24 -> V_142 . V_301 == V_128 ) {
V_166 . V_302 = F_147 ( ( T_3 ) V_2 -> V_280 ) ;
V_290 |= V_303 ;
} else {
V_291 = (struct V_132 * ) & V_24 -> V_142 ;
V_166 . V_304 = ( T_1 ) ( F_28 ( V_291 -> V_305 ) >> 20 ) ;
V_290 |= V_306 ;
}
V_2 -> V_154 = F_148 ( & V_307 , V_2 -> V_21 . V_22 ,
V_2 -> V_21 . V_44 , & V_166 ,
V_290 , V_289 ,
V_77 , F_142 ,
V_283 , & V_2 -> V_153 ) ;
return ( V_2 -> V_154 < 0 ) ? V_2 -> V_154 : 0 ;
}
static void F_149 ( struct V_308 * V_309 )
{
struct V_282 * V_283 = F_19 ( V_309 , struct V_282 , V_283 ) ;
struct V_1 * V_2 = V_283 -> V_21 ;
int V_310 = 0 ;
F_22 ( & V_2 -> V_70 ) ;
if ( ! F_4 ( V_2 , V_283 -> V_284 , V_283 -> V_285 ) )
goto V_69;
if ( V_2 -> V_21 . V_72 ( & V_2 -> V_21 , & V_283 -> V_172 ) ) {
F_5 ( V_2 , V_164 ) ;
V_310 = 1 ;
}
V_69:
F_24 ( & V_2 -> V_70 ) ;
F_37 ( V_2 ) ;
if ( V_310 )
F_86 ( & V_2 -> V_21 ) ;
F_20 ( V_283 ) ;
}
static void F_150 ( struct V_308 * V_309 )
{
struct V_311 * V_283 = F_19 ( V_309 , struct V_311 , V_283 ) ;
struct V_1 * V_2 = V_283 -> V_21 ;
int V_310 = 0 ;
F_22 ( & V_2 -> V_70 ) ;
if ( V_2 -> V_8 == V_164 ||
V_2 -> V_8 == V_312 )
goto V_69;
if ( V_2 -> V_21 . V_72 ( & V_2 -> V_21 , & V_283 -> V_172 ) ) {
F_5 ( V_2 , V_164 ) ;
V_310 = 1 ;
}
V_69:
F_24 ( & V_2 -> V_70 ) ;
F_37 ( V_2 ) ;
if ( V_310 )
F_86 ( & V_2 -> V_21 ) ;
F_20 ( V_283 ) ;
}
static int F_151 ( struct V_1 * V_2 , int V_289 )
{
struct V_214 * V_23 = & V_2 -> V_21 . V_23 ;
struct V_282 * V_283 ;
int V_6 ;
V_283 = F_40 ( sizeof *V_283 , V_77 ) ;
if ( ! V_283 )
return - V_78 ;
V_283 -> V_21 = V_2 ;
F_152 ( & V_283 -> V_283 , F_149 ) ;
V_283 -> V_284 = V_158 ;
V_283 -> V_285 = V_313 ;
V_283 -> V_172 . V_172 = V_314 ;
V_23 -> V_166 = F_107 ( sizeof * V_23 -> V_166 , V_77 ) ;
if ( ! V_23 -> V_166 ) {
V_6 = - V_78 ;
goto V_234;
}
V_6 = F_144 ( V_2 , V_289 , V_283 ) ;
if ( V_6 )
goto V_236;
return 0 ;
V_236:
F_20 ( V_23 -> V_166 ) ;
V_23 -> V_166 = NULL ;
V_234:
F_20 ( V_283 ) ;
return V_6 ;
}
int F_153 ( struct V_71 * V_21 ,
struct V_281 * V_166 , int V_217 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_4 ( V_2 , V_286 ,
V_313 ) )
return - V_65 ;
V_21 -> V_23 . V_166 = F_154 ( V_166 , sizeof *V_166 * V_217 ,
V_77 ) ;
if ( ! V_21 -> V_23 . V_166 ) {
V_6 = - V_78 ;
goto V_49;
}
V_21 -> V_23 . V_217 = V_217 ;
return 0 ;
V_49:
F_4 ( V_2 , V_313 , V_286 ) ;
return V_6 ;
}
static int F_155 ( struct V_1 * V_2 , int V_289 )
{
struct V_282 * V_283 ;
V_283 = F_40 ( sizeof *V_283 , V_77 ) ;
if ( ! V_283 )
return - V_78 ;
V_283 -> V_21 = V_2 ;
F_152 ( & V_283 -> V_283 , F_149 ) ;
V_283 -> V_284 = V_158 ;
V_283 -> V_285 = V_313 ;
V_283 -> V_172 . V_172 = V_314 ;
F_143 ( V_288 , & V_283 -> V_283 ) ;
return 0 ;
}
static int F_156 ( struct V_1 * V_2 )
{
struct V_214 * V_23 = & V_2 -> V_21 . V_23 ;
struct V_146 * V_24 = & V_23 -> V_24 ;
struct V_282 * V_283 ;
int V_6 ;
struct V_129 * V_142 = (struct V_129 * ) & V_23 -> V_24 . V_142 ;
struct V_129 * V_143 = (struct V_129 * ) & V_23 -> V_24 . V_143 ;
struct V_265 * V_315 = NULL ;
T_3 V_316 ;
if ( V_142 -> V_151 != V_143 -> V_151 )
return - V_65 ;
V_283 = F_40 ( sizeof *V_283 , V_77 ) ;
if ( ! V_283 )
return - V_78 ;
V_283 -> V_21 = V_2 ;
F_152 ( & V_283 -> V_283 , F_149 ) ;
V_23 -> V_166 = F_40 ( sizeof * V_23 -> V_166 , V_77 ) ;
if ( ! V_23 -> V_166 ) {
V_6 = - V_78 ;
goto V_234;
}
V_23 -> V_217 = 1 ;
if ( V_24 -> V_25 . V_317 )
V_315 = F_157 ( & V_271 , V_24 -> V_25 . V_317 ) ;
if ( ! V_315 ) {
V_6 = - V_57 ;
goto V_236;
}
V_316 = F_158 ( V_315 ) ;
F_159 ( & V_23 -> V_166 -> V_220 , V_24 -> V_25 . V_66 , V_316 ) ;
F_159 ( & V_23 -> V_166 -> V_221 , V_24 -> V_25 . V_318 , V_316 ) ;
V_23 -> V_166 -> V_319 = 1 ;
V_23 -> V_166 -> V_293 = 1 ;
V_23 -> V_166 -> V_112 = F_147 ( 0xffff ) ;
V_23 -> V_166 -> V_320 = V_321 ;
V_23 -> V_166 -> V_322 = F_160 (
V_315 -> V_323 & V_324 ?
F_161 ( V_315 ) : V_315 ,
F_162 ( V_2 -> V_280 ) ) ;
V_23 -> V_166 -> V_325 = F_163 ( V_315 -> V_325 ) ;
V_23 -> V_166 -> V_326 = V_321 ;
V_23 -> V_166 -> V_327 = F_164 ( V_315 ) ;
F_129 ( V_315 ) ;
V_23 -> V_166 -> V_328 = V_321 ;
V_23 -> V_166 -> V_329 = V_330 ;
if ( ! V_23 -> V_166 -> V_325 ) {
V_6 = - V_65 ;
goto V_236;
}
V_283 -> V_284 = V_158 ;
V_283 -> V_285 = V_313 ;
V_283 -> V_172 . V_172 = V_314 ;
V_283 -> V_172 . V_192 = 0 ;
F_143 ( V_288 , & V_283 -> V_283 ) ;
return 0 ;
V_236:
F_20 ( V_23 -> V_166 ) ;
V_23 -> V_166 = NULL ;
V_234:
F_20 ( V_283 ) ;
return V_6 ;
}
int F_165 ( struct V_71 * V_21 , int V_289 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_4 ( V_2 , V_286 , V_158 ) )
return - V_65 ;
F_12 ( & V_2 -> V_20 ) ;
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_68 :
switch ( F_36 ( V_21 -> V_22 , V_21 -> V_44 ) ) {
case V_63 :
V_6 = F_151 ( V_2 , V_289 ) ;
break;
case V_64 :
V_6 = F_156 ( V_2 ) ;
break;
default:
V_6 = - V_123 ;
}
break;
case V_121 :
V_6 = F_155 ( V_2 , V_289 ) ;
break;
default:
V_6 = - V_123 ;
break;
}
if ( V_6 )
goto V_49;
return 0 ;
V_49:
F_4 ( V_2 , V_158 , V_286 ) ;
F_37 ( V_2 ) ;
return V_6 ;
}
static int F_166 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_50 V_331 ;
union V_46 V_47 ;
T_3 V_112 ;
int V_6 ;
T_1 V_332 ;
F_22 ( & V_7 ) ;
if ( F_83 ( & V_333 ) ) {
V_6 = - V_57 ;
goto V_69;
}
F_35 (cma_dev, &dev_list, list)
for ( V_332 = 1 ; V_332 <= V_19 -> V_22 -> V_67 ; ++ V_332 )
if ( ! F_30 ( V_19 -> V_22 , V_332 , & V_331 ) &&
V_331 . V_8 == V_334 )
goto V_335;
V_332 = 1 ;
V_19 = F_84 ( V_333 . V_156 , struct V_18 , V_28 ) ;
V_335:
V_6 = F_167 ( V_19 -> V_22 , V_332 , 0 , & V_47 ) ;
if ( V_6 )
goto V_69;
V_6 = F_168 ( V_19 -> V_22 , V_332 , 0 , & V_112 ) ;
if ( V_6 )
goto V_69;
V_2 -> V_21 . V_23 . V_24 . V_25 . V_61 =
( F_36 ( V_19 -> V_22 , V_332 ) == V_63 ) ?
V_62 : V_336 ;
F_108 ( & V_2 -> V_21 . V_23 . V_24 . V_25 , & V_47 ) ;
F_109 ( & V_2 -> V_21 . V_23 . V_24 . V_25 , V_112 ) ;
V_2 -> V_21 . V_44 = V_332 ;
F_11 ( V_2 , V_19 ) ;
V_69:
F_24 ( & V_7 ) ;
return V_6 ;
}
static void F_169 ( int V_192 , struct V_124 * V_142 ,
struct V_55 * V_25 , void * V_73 )
{
struct V_1 * V_2 = V_73 ;
struct V_171 V_172 ;
memset ( & V_172 , 0 , sizeof V_172 ) ;
F_22 ( & V_2 -> V_70 ) ;
if ( ! F_4 ( V_2 , V_157 ,
V_286 ) )
goto V_69;
if ( ! V_192 && ! V_2 -> V_19 )
V_192 = F_32 ( V_2 ) ;
if ( V_192 ) {
if ( ! F_4 ( V_2 , V_286 ,
V_276 ) )
goto V_69;
V_172 . V_172 = V_337 ;
V_172 . V_192 = V_192 ;
} else {
memcpy ( & V_2 -> V_21 . V_23 . V_24 . V_142 , V_142 ,
F_138 ( V_142 ) ) ;
V_172 . V_172 = V_338 ;
}
if ( V_2 -> V_21 . V_72 ( & V_2 -> V_21 , & V_172 ) ) {
F_5 ( V_2 , V_164 ) ;
F_24 ( & V_2 -> V_70 ) ;
F_37 ( V_2 ) ;
F_86 ( & V_2 -> V_21 ) ;
return;
}
V_69:
F_24 ( & V_2 -> V_70 ) ;
F_37 ( V_2 ) ;
}
static int F_170 ( struct V_1 * V_2 )
{
struct V_282 * V_283 ;
struct V_124 * V_135 , * V_136 ;
union V_46 V_47 ;
int V_6 ;
V_283 = F_40 ( sizeof *V_283 , V_77 ) ;
if ( ! V_283 )
return - V_78 ;
if ( ! V_2 -> V_19 ) {
V_6 = F_166 ( V_2 ) ;
if ( V_6 )
goto V_49;
}
F_145 ( & V_2 -> V_21 . V_23 . V_24 . V_25 , & V_47 ) ;
F_112 ( & V_2 -> V_21 . V_23 . V_24 . V_25 , & V_47 ) ;
V_135 = (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
if ( F_67 ( V_135 ) ) {
V_136 = (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_143 ;
if ( ( V_135 -> V_127 = V_136 -> V_127 ) == V_128 ) {
( (struct V_129 * ) V_135 ) -> V_130 =
( (struct V_129 * ) V_136 ) -> V_130 ;
} else {
( (struct V_132 * ) V_135 ) -> V_133 =
( (struct V_132 * ) V_136 ) -> V_133 ;
}
}
V_283 -> V_21 = V_2 ;
F_152 ( & V_283 -> V_283 , F_149 ) ;
V_283 -> V_284 = V_157 ;
V_283 -> V_285 = V_286 ;
V_283 -> V_172 . V_172 = V_338 ;
F_143 ( V_288 , & V_283 -> V_283 ) ;
return 0 ;
V_49:
F_20 ( V_283 ) ;
return V_6 ;
}
static int F_171 ( struct V_71 * V_21 , struct V_124 * V_142 ,
struct V_124 * V_143 )
{
if ( ! V_142 || ! V_142 -> V_127 ) {
V_142 = (struct V_124 * ) & V_21 -> V_23 . V_24 . V_142 ;
if ( ( V_142 -> V_127 = V_143 -> V_127 ) == V_250 ) {
( (struct V_132 * ) V_142 ) -> V_339 =
( (struct V_132 * ) V_143 ) -> V_339 ;
}
}
return F_172 ( V_21 , V_142 ) ;
}
int F_173 ( struct V_71 * V_21 , struct V_124 * V_142 ,
struct V_124 * V_143 , int V_289 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( V_2 -> V_8 == V_81 ) {
V_6 = F_171 ( V_21 , V_142 , V_143 ) ;
if ( V_6 )
return V_6 ;
}
if ( ! F_4 ( V_2 , V_276 , V_157 ) )
return - V_65 ;
F_12 ( & V_2 -> V_20 ) ;
memcpy ( & V_21 -> V_23 . V_24 . V_143 , V_143 , F_138 ( V_143 ) ) ;
if ( F_72 ( V_143 ) )
V_6 = F_170 ( V_2 ) ;
else
V_6 = F_174 ( & V_340 , (struct V_124 * ) & V_21 -> V_23 . V_24 . V_142 ,
V_143 , & V_21 -> V_23 . V_24 . V_25 ,
V_289 , F_169 , V_2 ) ;
if ( V_6 )
goto V_49;
return 0 ;
V_49:
F_4 ( V_2 , V_157 , V_276 ) ;
F_37 ( V_2 ) ;
return V_6 ;
}
int F_175 ( struct V_71 * V_21 , int V_341 )
{
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
if ( V_2 -> V_8 == V_81 ) {
V_2 -> V_342 = V_341 ;
V_6 = 0 ;
} else {
V_6 = - V_65 ;
}
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
int F_176 ( struct V_71 * V_21 , int V_274 )
{
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
if ( V_2 -> V_8 == V_81 || V_2 -> V_8 == V_276 ) {
V_2 -> V_343 |= ( 1 << V_344 ) ;
V_2 -> V_274 = V_274 ;
V_6 = 0 ;
} else {
V_6 = - V_65 ;
}
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
static void F_177 ( struct V_160 * V_161 ,
struct V_1 * V_2 )
{
struct V_129 * sin ;
sin = (struct V_129 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
sin -> V_137 = F_178 ( V_161 -> V_58 ) ;
V_2 -> V_161 = V_161 ;
F_179 ( & V_2 -> V_162 , & V_161 -> V_163 ) ;
}
static int F_180 ( struct V_345 * V_39 , struct V_1 * V_2 ,
unsigned short V_346 )
{
struct V_160 * V_161 ;
int V_6 ;
V_161 = F_40 ( sizeof *V_161 , V_77 ) ;
if ( ! V_161 )
return - V_78 ;
V_6 = F_181 ( V_39 , V_161 , V_346 , V_346 + 1 , V_77 ) ;
if ( V_6 < 0 )
goto V_49;
V_161 -> V_39 = V_39 ;
V_161 -> V_58 = ( unsigned short ) V_6 ;
F_177 ( V_161 , V_2 ) ;
return 0 ;
V_49:
F_20 ( V_161 ) ;
return V_6 == - V_347 ? - V_54 : V_6 ;
}
static int F_182 ( struct V_345 * V_39 , struct V_1 * V_2 )
{
static unsigned int V_348 ;
int V_349 , V_350 , V_351 ;
unsigned int V_352 ;
F_183 ( & V_349 , & V_350 ) ;
V_351 = ( V_350 - V_349 ) + 1 ;
V_352 = F_184 () % V_351 + V_349 ;
V_353:
if ( V_348 != V_352 &&
! F_185 ( V_39 , ( unsigned short ) V_352 ) ) {
int V_6 = F_180 ( V_39 , V_2 , V_352 ) ;
if ( ! V_6 )
V_348 = V_352 ;
if ( V_6 != - V_54 )
return V_6 ;
}
if ( -- V_351 ) {
V_352 ++ ;
if ( ( V_352 < V_349 ) || ( V_352 > V_350 ) )
V_352 = V_349 ;
goto V_353;
}
return - V_54 ;
}
static int F_186 ( struct V_160 * V_161 ,
struct V_1 * V_2 , T_8 V_342 )
{
struct V_1 * V_354 ;
struct V_124 * V_24 , * V_355 ;
V_24 = (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
F_187 (cur_id, &bind_list->owners, node) {
if ( V_2 == V_354 )
continue;
if ( ( V_354 -> V_8 != V_159 ) && V_342 &&
V_354 -> V_342 )
continue;
V_355 = (struct V_124 * ) & V_354 -> V_21 . V_23 . V_24 . V_142 ;
if ( V_2 -> V_274 && V_354 -> V_274 &&
( V_24 -> V_127 != V_355 -> V_127 ) )
continue;
if ( F_72 ( V_24 ) || F_72 ( V_355 ) )
return - V_54 ;
if ( ! F_73 ( V_24 , V_355 ) )
return - V_356 ;
}
return 0 ;
}
static int F_188 ( struct V_345 * V_39 , struct V_1 * V_2 )
{
struct V_160 * V_161 ;
unsigned short V_346 ;
int V_6 ;
V_346 = F_189 ( F_75 ( (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ) ) ;
if ( V_346 < V_357 && ! F_190 ( V_358 ) )
return - V_359 ;
V_161 = F_185 ( V_39 , V_346 ) ;
if ( ! V_161 ) {
V_6 = F_180 ( V_39 , V_2 , V_346 ) ;
} else {
V_6 = F_186 ( V_161 , V_2 , V_2 -> V_342 ) ;
if ( ! V_6 )
F_177 ( V_161 , V_2 ) ;
}
return V_6 ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_160 * V_161 = V_2 -> V_161 ;
int V_6 = 0 ;
F_22 ( & V_7 ) ;
if ( V_161 -> V_163 . V_360 -> V_156 )
V_6 = F_186 ( V_161 , V_2 , 0 ) ;
F_24 ( & V_7 ) ;
return V_6 ;
}
static int F_192 ( struct V_1 * V_2 )
{
struct V_345 * V_39 ;
int V_6 ;
switch ( V_2 -> V_21 . V_39 ) {
case V_140 :
V_39 = & V_361 ;
break;
case V_269 :
V_39 = & V_362 ;
break;
case V_40 :
V_39 = & V_363 ;
break;
case V_42 :
V_39 = & V_364 ;
break;
case V_365 :
V_39 = & V_366 ;
break;
default:
return - V_367 ;
}
F_22 ( & V_7 ) ;
if ( F_76 ( (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ) )
V_6 = F_182 ( V_39 , V_2 ) ;
else
V_6 = F_188 ( V_39 , V_2 ) ;
F_24 ( & V_7 ) ;
return V_6 ;
}
static int F_193 ( struct V_55 * V_25 ,
struct V_124 * V_24 )
{
#if F_194 ( V_368 )
struct V_132 * V_291 ;
if ( V_24 -> V_127 != V_250 )
return 0 ;
V_291 = (struct V_132 * ) V_24 ;
if ( ( F_195 ( & V_291 -> V_133 ) & V_369 ) &&
! V_291 -> V_339 )
return - V_65 ;
V_25 -> V_317 = V_291 -> V_339 ;
#endif
return 0 ;
}
int F_139 ( struct V_71 * V_21 , int V_275 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( V_2 -> V_8 == V_81 ) {
( (struct V_124 * ) & V_21 -> V_23 . V_24 . V_142 ) -> V_127 = V_128 ;
V_6 = F_172 ( V_21 , (struct V_124 * ) & V_21 -> V_23 . V_24 . V_142 ) ;
if ( V_6 )
return V_6 ;
}
if ( ! F_4 ( V_2 , V_276 , V_159 ) )
return - V_65 ;
if ( V_2 -> V_342 ) {
V_6 = F_191 ( V_2 ) ;
if ( V_6 )
goto V_49;
}
V_2 -> V_275 = V_275 ;
if ( V_21 -> V_22 ) {
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_68 :
V_6 = F_130 ( V_2 ) ;
if ( V_6 )
goto V_49;
break;
case V_121 :
V_6 = F_133 ( V_2 , V_275 ) ;
if ( V_6 )
goto V_49;
break;
default:
V_6 = - V_123 ;
goto V_49;
}
} else
F_140 ( V_2 ) ;
return 0 ;
V_49:
V_2 -> V_275 = 0 ;
F_4 ( V_2 , V_159 , V_276 ) ;
return V_6 ;
}
int F_172 ( struct V_71 * V_21 , struct V_124 * V_24 )
{
struct V_1 * V_2 ;
int V_6 ;
if ( V_24 -> V_127 != V_128 && V_24 -> V_127 != V_250 )
return - V_370 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_4 ( V_2 , V_81 , V_276 ) )
return - V_65 ;
V_6 = F_193 ( & V_21 -> V_23 . V_24 . V_25 , V_24 ) ;
if ( V_6 )
goto V_234;
if ( ! F_72 ( V_24 ) ) {
V_6 = F_111 ( V_24 , & V_21 -> V_23 . V_24 . V_25 ) ;
if ( V_6 )
goto V_234;
V_6 = F_32 ( V_2 ) ;
if ( V_6 )
goto V_234;
}
memcpy ( & V_21 -> V_23 . V_24 . V_142 , V_24 , F_138 ( V_24 ) ) ;
if ( ! ( V_2 -> V_343 & ( 1 << V_344 ) ) ) {
if ( V_24 -> V_127 == V_128 )
V_2 -> V_274 = 1 ;
#if F_194 ( V_368 )
else if ( V_24 -> V_127 == V_250 )
V_2 -> V_274 = V_271 . V_371 . V_372 . V_373 ;
#endif
}
V_6 = F_192 ( V_2 ) ;
if ( V_6 )
goto V_236;
return 0 ;
V_236:
if ( V_2 -> V_19 )
F_21 ( V_2 ) ;
V_234:
F_4 ( V_2 , V_276 , V_81 ) ;
return V_6 ;
}
static int F_196 ( void * V_12 , enum V_74 V_39 ,
struct V_214 * V_23 )
{
struct V_11 * V_11 ;
struct V_16 * V_374 ;
if ( V_23 -> V_24 . V_142 . V_301 == V_128 ) {
struct V_129 * V_375 , * V_376 ;
V_375 = (struct V_129 * ) & V_23 -> V_24 . V_142 ;
V_376 = (struct V_129 * ) & V_23 -> V_24 . V_143 ;
switch ( V_39 ) {
case V_140 :
V_374 = V_12 ;
if ( F_8 ( V_374 -> V_15 ) != V_141 )
return - V_65 ;
F_10 ( V_374 , 4 ) ;
V_374 -> V_142 . V_149 . V_24 = V_375 -> V_130 . V_131 ;
V_374 -> V_143 . V_149 . V_24 = V_376 -> V_130 . V_131 ;
V_374 -> V_58 = V_375 -> V_137 ;
break;
default:
V_11 = V_12 ;
V_11 -> V_144 = V_145 ;
F_7 ( V_11 , 4 ) ;
V_11 -> V_142 . V_149 . V_24 = V_375 -> V_130 . V_131 ;
V_11 -> V_143 . V_149 . V_24 = V_376 -> V_130 . V_131 ;
V_11 -> V_58 = V_375 -> V_137 ;
break;
}
} else {
struct V_132 * V_377 , * V_378 ;
V_377 = (struct V_132 * ) & V_23 -> V_24 . V_142 ;
V_378 = (struct V_132 * ) & V_23 -> V_24 . V_143 ;
switch ( V_39 ) {
case V_140 :
V_374 = V_12 ;
if ( F_8 ( V_374 -> V_15 ) != V_141 )
return - V_65 ;
F_10 ( V_374 , 6 ) ;
V_374 -> V_142 . V_126 = V_377 -> V_133 ;
V_374 -> V_143 . V_126 = V_378 -> V_133 ;
V_374 -> V_58 = V_377 -> V_138 ;
break;
default:
V_11 = V_12 ;
V_11 -> V_144 = V_145 ;
F_7 ( V_11 , 6 ) ;
V_11 -> V_142 . V_126 = V_377 -> V_133 ;
V_11 -> V_143 . V_126 = V_378 -> V_133 ;
V_11 -> V_58 = V_377 -> V_138 ;
break;
}
}
return 0 ;
}
static int F_197 ( struct V_183 * V_119 ,
struct V_184 * V_185 )
{
struct V_1 * V_2 = V_119 -> V_73 ;
struct V_171 V_172 ;
struct V_379 * V_380 = & V_185 -> V_176 . V_381 ;
int V_6 = 0 ;
if ( F_38 ( V_2 , V_187 ) )
return 0 ;
memset ( & V_172 , 0 , sizeof V_172 ) ;
switch ( V_185 -> V_172 ) {
case V_382 :
V_172 . V_172 = V_191 ;
V_172 . V_192 = - V_193 ;
break;
case V_383 :
V_172 . V_176 . V_232 . V_175 = V_185 -> V_175 ;
V_172 . V_176 . V_232 . V_178 = V_384 ;
if ( V_380 -> V_192 != V_385 ) {
V_172 . V_172 = V_191 ;
V_172 . V_192 = V_185 -> V_176 . V_381 . V_192 ;
break;
}
V_6 = F_25 ( V_2 ) ;
if ( V_6 ) {
V_172 . V_172 = V_337 ;
V_172 . V_192 = - V_65 ;
break;
}
if ( V_2 -> V_38 != V_380 -> V_38 ) {
V_172 . V_172 = V_191 ;
V_172 . V_192 = - V_65 ;
break;
}
F_198 ( V_2 -> V_21 . V_22 , V_2 -> V_21 . V_44 ,
V_2 -> V_21 . V_23 . V_166 ,
& V_172 . V_176 . V_232 . V_386 ) ;
V_172 . V_176 . V_232 . V_103 = V_380 -> V_387 ;
V_172 . V_176 . V_232 . V_38 = V_380 -> V_38 ;
V_172 . V_172 = V_196 ;
V_172 . V_192 = 0 ;
break;
default:
F_105 ( V_212 L_1 ,
V_185 -> V_172 ) ;
goto V_69;
}
V_6 = V_2 -> V_21 . V_72 ( & V_2 -> V_21 , & V_172 ) ;
if ( V_6 ) {
V_2 -> V_119 . V_35 = NULL ;
F_5 ( V_2 , V_164 ) ;
F_24 ( & V_2 -> V_70 ) ;
F_86 ( & V_2 -> V_21 ) ;
return V_6 ;
}
V_69:
F_24 ( & V_2 -> V_70 ) ;
return V_6 ;
}
static int F_199 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_388 V_389 ;
struct V_214 * V_23 ;
struct V_183 * V_21 ;
int V_6 ;
V_389 . V_178 = sizeof( struct V_11 ) +
V_106 -> V_178 ;
if ( V_389 . V_178 < V_106 -> V_178 )
return - V_65 ;
V_389 . V_175 = F_40 ( V_389 . V_178 , V_390 ) ;
if ( ! V_389 . V_175 )
return - V_78 ;
if ( V_106 -> V_175 && V_106 -> V_178 )
memcpy ( ( void * ) V_389 . V_175 + sizeof( struct V_11 ) ,
V_106 -> V_175 , V_106 -> V_178 ) ;
V_23 = & V_2 -> V_21 . V_23 ;
V_6 = F_196 ( ( void * ) V_389 . V_175 , V_2 -> V_21 . V_39 , V_23 ) ;
if ( V_6 )
goto V_69;
V_21 = F_131 ( V_2 -> V_21 . V_22 , F_197 ,
V_2 ) ;
if ( F_55 ( V_21 ) ) {
V_6 = F_56 ( V_21 ) ;
goto V_69;
}
V_2 -> V_119 . V_35 = V_21 ;
V_389 . V_391 = V_23 -> V_166 ;
V_389 . V_294 = F_119 ( V_2 -> V_21 . V_39 ,
(struct V_124 * ) & V_23 -> V_24 . V_143 ) ;
V_389 . V_289 = 1 << ( V_392 - 8 ) ;
V_389 . V_393 = V_394 ;
V_6 = F_200 ( V_2 -> V_119 . V_35 , & V_389 ) ;
if ( V_6 ) {
F_96 ( V_2 -> V_119 . V_35 ) ;
V_2 -> V_119 . V_35 = NULL ;
}
V_69:
F_20 ( V_389 . V_175 ) ;
return V_6 ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_395 V_389 ;
struct V_214 * V_23 ;
void * V_175 ;
struct V_183 * V_21 ;
int V_224 , V_6 ;
memset ( & V_389 , 0 , sizeof V_389 ) ;
V_224 = F_79 ( V_2 -> V_21 . V_39 ) ;
V_389 . V_178 = V_224 + V_106 -> V_178 ;
if ( V_389 . V_178 < V_106 -> V_178 )
return - V_65 ;
V_175 = F_40 ( V_389 . V_178 , V_390 ) ;
if ( ! V_175 )
return - V_78 ;
if ( V_106 -> V_175 && V_106 -> V_178 )
memcpy ( V_175 + V_224 , V_106 -> V_175 ,
V_106 -> V_178 ) ;
V_21 = F_131 ( V_2 -> V_21 . V_22 , F_104 , V_2 ) ;
if ( F_55 ( V_21 ) ) {
V_6 = F_56 ( V_21 ) ;
goto V_69;
}
V_2 -> V_119 . V_35 = V_21 ;
V_23 = & V_2 -> V_21 . V_23 ;
V_6 = F_196 ( V_175 , V_2 -> V_21 . V_39 , V_23 ) ;
if ( V_6 )
goto V_69;
V_389 . V_175 = V_175 ;
V_389 . V_219 = & V_23 -> V_166 [ 0 ] ;
if ( V_23 -> V_217 == 2 )
V_389 . V_218 = & V_23 -> V_166 [ 1 ] ;
V_389 . V_294 = F_119 ( V_2 -> V_21 . V_39 ,
(struct V_124 * ) & V_23 -> V_24 . V_143 ) ;
V_389 . V_103 = V_2 -> V_103 ;
V_389 . V_76 = V_2 -> V_21 . V_76 ;
V_389 . V_396 = V_2 -> V_85 ;
V_389 . V_108 = V_106 -> V_108 ;
V_389 . V_110 = V_106 -> V_110 ;
V_389 . V_180 = V_106 -> V_180 ;
V_389 . V_226 = F_202 ( T_1 , 7 , V_106 -> V_226 ) ;
V_389 . V_181 = F_202 ( T_1 , 7 , V_106 -> V_181 ) ;
V_389 . V_397 = V_392 ;
V_389 . V_398 = V_392 ;
V_389 . V_393 = V_394 ;
V_389 . V_104 = V_2 -> V_104 ? 1 : 0 ;
V_6 = F_203 ( V_2 -> V_119 . V_35 , & V_389 ) ;
V_69:
if ( V_6 && ! F_55 ( V_21 ) ) {
F_96 ( V_21 ) ;
V_2 -> V_119 . V_35 = NULL ;
}
F_20 ( V_175 ) ;
return V_6 ;
}
static int F_204 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_251 * V_119 ;
struct V_129 * sin ;
int V_6 ;
struct V_399 V_400 ;
V_119 = F_134 ( V_2 -> V_21 . V_22 , F_123 , V_2 ) ;
if ( F_55 ( V_119 ) )
return F_56 ( V_119 ) ;
V_2 -> V_119 . V_122 = V_119 ;
sin = (struct V_129 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
V_119 -> V_257 = * sin ;
sin = (struct V_129 * ) & V_2 -> V_21 . V_23 . V_24 . V_143 ;
V_119 -> V_258 = * sin ;
V_6 = F_59 ( V_2 , V_106 ) ;
if ( V_6 )
goto V_69;
if ( V_106 ) {
V_400 . V_260 = V_106 -> V_110 ;
V_400 . V_259 = V_106 -> V_108 ;
V_400 . V_175 = V_106 -> V_175 ;
V_400 . V_178 = V_106 -> V_178 ;
V_400 . V_387 = V_2 -> V_21 . V_87 ? V_2 -> V_103 : V_106 -> V_103 ;
} else {
memset ( & V_400 , 0 , sizeof V_400 ) ;
V_400 . V_387 = V_2 -> V_103 ;
}
V_6 = F_205 ( V_119 , & V_400 ) ;
V_69:
if ( V_6 ) {
F_97 ( V_119 ) ;
V_2 -> V_119 . V_122 = NULL ;
}
return V_6 ;
}
int F_206 ( struct V_71 * V_21 , struct V_105 * V_106 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_4 ( V_2 , V_313 , V_187 ) )
return - V_65 ;
if ( ! V_21 -> V_87 ) {
V_2 -> V_103 = V_106 -> V_103 ;
V_2 -> V_104 = V_106 -> V_104 ;
}
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_68 :
if ( V_21 -> V_76 == V_102 )
V_6 = F_199 ( V_2 , V_106 ) ;
else
V_6 = F_201 ( V_2 , V_106 ) ;
break;
case V_121 :
V_6 = F_204 ( V_2 , V_106 ) ;
break;
default:
V_6 = - V_123 ;
break;
}
if ( V_6 )
goto V_49;
return 0 ;
V_49:
F_4 ( V_2 , V_187 , V_313 ) ;
return V_6 ;
}
static int F_207 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_401 V_380 ;
int V_6 ;
V_6 = F_59 ( V_2 , V_106 ) ;
if ( V_6 )
goto V_69;
V_6 = F_60 ( V_2 , V_106 ) ;
if ( V_6 )
goto V_69;
memset ( & V_380 , 0 , sizeof V_380 ) ;
V_380 . V_103 = V_2 -> V_103 ;
V_380 . V_396 = V_2 -> V_85 ;
V_380 . V_175 = V_106 -> V_175 ;
V_380 . V_178 = V_106 -> V_178 ;
V_380 . V_108 = V_106 -> V_108 ;
V_380 . V_110 = V_106 -> V_110 ;
V_380 . V_402 = 0 ;
V_380 . V_180 = V_106 -> V_180 ;
V_380 . V_181 = F_202 ( T_1 , 7 , V_106 -> V_181 ) ;
V_380 . V_104 = V_2 -> V_104 ? 1 : 0 ;
V_6 = F_208 ( V_2 -> V_119 . V_35 , & V_380 ) ;
V_69:
return V_6 ;
}
static int F_209 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_399 V_400 ;
int V_6 ;
V_6 = F_59 ( V_2 , V_106 ) ;
if ( V_6 )
return V_6 ;
V_400 . V_260 = V_106 -> V_110 ;
V_400 . V_259 = V_106 -> V_108 ;
V_400 . V_175 = V_106 -> V_175 ;
V_400 . V_178 = V_106 -> V_178 ;
if ( V_2 -> V_21 . V_87 ) {
V_400 . V_387 = V_2 -> V_103 ;
} else
V_400 . V_387 = V_106 -> V_103 ;
return F_210 ( V_2 -> V_119 . V_122 , & V_400 ) ;
}
static int F_211 ( struct V_1 * V_2 ,
enum V_403 V_192 ,
const void * V_175 , int V_178 )
{
struct V_404 V_380 ;
int V_6 ;
memset ( & V_380 , 0 , sizeof V_380 ) ;
V_380 . V_192 = V_192 ;
if ( V_192 == V_385 ) {
V_6 = F_25 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_380 . V_103 = V_2 -> V_103 ;
V_380 . V_38 = V_2 -> V_38 ;
}
V_380 . V_175 = V_175 ;
V_380 . V_178 = V_178 ;
return F_212 ( V_2 -> V_119 . V_35 , & V_380 ) ;
}
int F_213 ( struct V_71 * V_21 , struct V_105 * V_106 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
V_2 -> V_79 = F_42 ( V_80 ) ;
if ( ! F_1 ( V_2 , V_187 ) )
return - V_65 ;
if ( ! V_21 -> V_87 && V_106 ) {
V_2 -> V_103 = V_106 -> V_103 ;
V_2 -> V_104 = V_106 -> V_104 ;
}
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_68 :
if ( V_21 -> V_76 == V_102 ) {
if ( V_106 )
V_6 = F_211 ( V_2 , V_385 ,
V_106 -> V_175 ,
V_106 -> V_178 ) ;
else
V_6 = F_211 ( V_2 , V_385 ,
NULL , 0 ) ;
} else {
if ( V_106 )
V_6 = F_207 ( V_2 , V_106 ) ;
else
V_6 = F_99 ( V_2 ) ;
}
break;
case V_121 :
V_6 = F_209 ( V_2 , V_106 ) ;
break;
default:
V_6 = - V_123 ;
break;
}
if ( V_6 )
goto V_167;
return 0 ;
V_167:
F_61 ( V_2 ) ;
F_214 ( V_21 , NULL , 0 ) ;
return V_6 ;
}
int F_215 ( struct V_71 * V_21 , enum V_405 V_172 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! V_2 -> V_119 . V_35 )
return - V_65 ;
switch ( V_21 -> V_22 -> V_27 ) {
case V_406 :
V_6 = F_216 ( V_2 -> V_119 . V_35 , V_172 ) ;
break;
default:
V_6 = 0 ;
break;
}
return V_6 ;
}
int F_214 ( struct V_71 * V_21 , const void * V_175 ,
T_1 V_178 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! V_2 -> V_119 . V_35 )
return - V_65 ;
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_68 :
if ( V_21 -> V_76 == V_102 )
V_6 = F_211 ( V_2 , V_407 ,
V_175 , V_178 ) ;
else
V_6 = F_101 ( V_2 -> V_119 . V_35 ,
V_168 , NULL ,
0 , V_175 , V_178 ) ;
break;
case V_121 :
V_6 = F_217 ( V_2 -> V_119 . V_122 ,
V_175 , V_178 ) ;
break;
default:
V_6 = - V_123 ;
break;
}
return V_6 ;
}
int F_218 ( struct V_71 * V_21 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! V_2 -> V_119 . V_35 )
return - V_65 ;
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_68 :
V_6 = F_61 ( V_2 ) ;
if ( V_6 )
goto V_69;
if ( F_219 ( V_2 -> V_119 . V_35 , NULL , 0 ) )
F_220 ( V_2 -> V_119 . V_35 , NULL , 0 ) ;
break;
case V_121 :
V_6 = F_221 ( V_2 -> V_119 . V_122 , 0 ) ;
break;
default:
V_6 = - V_65 ;
break;
}
V_69:
return V_6 ;
}
static int F_222 ( int V_192 , struct V_408 * V_34 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 = V_34 -> V_73 ;
struct V_171 V_172 ;
int V_6 ;
V_2 = V_32 -> V_2 ;
if ( F_38 ( V_2 , V_276 ) &&
F_38 ( V_2 , V_286 ) )
return 0 ;
F_22 ( & V_2 -> V_82 ) ;
if ( ! V_192 && V_2 -> V_21 . V_87 )
V_192 = F_223 ( V_2 -> V_21 . V_87 , & V_34 -> V_37 . V_43 ,
F_110 ( V_34 -> V_37 . V_409 ) ) ;
F_24 ( & V_2 -> V_82 ) ;
memset ( & V_172 , 0 , sizeof V_172 ) ;
V_172 . V_192 = V_192 ;
V_172 . V_176 . V_232 . V_175 = V_32 -> V_73 ;
if ( ! V_192 ) {
V_172 . V_172 = V_410 ;
F_224 ( V_2 -> V_21 . V_22 ,
V_2 -> V_21 . V_44 , & V_34 -> V_37 ,
& V_172 . V_176 . V_232 . V_386 ) ;
V_172 . V_176 . V_232 . V_103 = 0xFFFFFF ;
V_172 . V_176 . V_232 . V_38 = F_28 ( V_34 -> V_37 . V_38 ) ;
} else
V_172 . V_172 = V_411 ;
V_6 = V_2 -> V_21 . V_72 ( & V_2 -> V_21 , & V_172 ) ;
if ( V_6 ) {
F_5 ( V_2 , V_164 ) ;
F_24 ( & V_2 -> V_70 ) ;
F_86 ( & V_2 -> V_21 ) ;
return 0 ;
}
F_24 ( & V_2 -> V_70 ) ;
return 0 ;
}
static void F_225 ( struct V_1 * V_2 ,
struct V_124 * V_24 , union V_46 * V_43 )
{
unsigned char V_412 [ V_413 ] ;
struct V_55 * V_25 = & V_2 -> V_21 . V_23 . V_24 . V_25 ;
struct V_129 * sin = (struct V_129 * ) V_24 ;
struct V_132 * V_291 = (struct V_132 * ) V_24 ;
if ( F_72 ( V_24 ) ) {
memset ( V_43 , 0 , sizeof *V_43 ) ;
} else if ( ( V_24 -> V_127 == V_250 ) &&
( ( F_28 ( V_291 -> V_133 . V_134 [ 0 ] ) & 0xFFF0FFFF ) ==
0xFF10A01B ) ) {
memcpy ( V_43 , & V_291 -> V_133 , sizeof *V_43 ) ;
} else if ( ( V_24 -> V_127 == V_250 ) ) {
F_226 ( & V_291 -> V_133 , V_25 -> V_414 , V_412 ) ;
if ( V_2 -> V_21 . V_39 == V_40 )
V_412 [ 7 ] = 0x01 ;
* V_43 = * (union V_46 * ) ( V_412 + 4 ) ;
} else {
F_227 ( sin -> V_130 . V_131 , V_25 -> V_414 , V_412 ) ;
if ( V_2 -> V_21 . V_39 == V_40 )
V_412 [ 7 ] = 0x01 ;
* V_43 = * (union V_46 * ) ( V_412 + 4 ) ;
}
}
static int F_228 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_36 V_37 ;
struct V_55 * V_25 = & V_2 -> V_21 . V_23 . V_24 . V_25 ;
T_7 V_290 ;
int V_6 ;
F_26 ( V_25 , & V_37 . V_43 ) ;
V_6 = F_27 ( V_2 -> V_21 . V_22 , V_2 -> V_21 . V_44 ,
& V_37 . V_43 , & V_37 ) ;
if ( V_6 )
return V_6 ;
F_225 ( V_2 , (struct V_124 * ) & V_32 -> V_24 , & V_37 . V_43 ) ;
if ( V_2 -> V_21 . V_39 == V_40 )
V_37 . V_38 = F_229 ( V_41 ) ;
F_145 ( V_25 , & V_37 . V_415 ) ;
V_37 . V_112 = F_147 ( F_63 ( V_25 ) ) ;
V_37 . V_416 = 1 ;
V_290 = V_417 | V_418 |
V_419 | V_420 |
V_421 | V_422 |
V_423 |
V_424 ;
if ( V_2 -> V_21 . V_39 == V_42 )
V_290 |= V_425 |
V_426 |
V_427 |
V_428 |
V_429 ;
V_32 -> V_34 . V_35 = F_230 ( & V_307 , V_2 -> V_21 . V_22 ,
V_2 -> V_21 . V_44 , & V_37 ,
V_290 , V_77 ,
F_222 , V_32 ) ;
return F_231 ( V_32 -> V_34 . V_35 ) ;
}
static void F_232 ( struct V_308 * V_283 )
{
struct V_430 * V_431 = F_19 ( V_283 , struct V_430 , V_283 ) ;
struct V_31 * V_32 = V_431 -> V_32 ;
struct V_408 * V_432 = V_32 -> V_34 . V_35 ;
V_32 -> V_34 . V_35 -> V_73 = V_32 ;
F_222 ( 0 , V_432 ) ;
F_95 ( & V_32 -> V_33 , F_18 ) ;
F_20 ( V_431 ) ;
}
static void F_233 ( struct V_124 * V_24 , union V_46 * V_43 )
{
struct V_129 * sin = (struct V_129 * ) V_24 ;
struct V_132 * V_291 = (struct V_132 * ) V_24 ;
if ( F_72 ( V_24 ) ) {
memset ( V_43 , 0 , sizeof *V_43 ) ;
} else if ( V_24 -> V_127 == V_250 ) {
memcpy ( V_43 , & V_291 -> V_133 , sizeof *V_43 ) ;
} else {
V_43 -> V_433 [ 0 ] = 0xff ;
V_43 -> V_433 [ 1 ] = 0x0e ;
V_43 -> V_433 [ 2 ] = 0 ;
V_43 -> V_433 [ 3 ] = 0 ;
V_43 -> V_433 [ 4 ] = 0 ;
V_43 -> V_433 [ 5 ] = 0 ;
V_43 -> V_433 [ 6 ] = 0 ;
V_43 -> V_433 [ 7 ] = 0 ;
V_43 -> V_433 [ 8 ] = 0 ;
V_43 -> V_433 [ 9 ] = 0 ;
V_43 -> V_433 [ 10 ] = 0xff ;
V_43 -> V_433 [ 11 ] = 0xff ;
* ( T_6 * ) ( & V_43 -> V_433 [ 12 ] ) = sin -> V_130 . V_131 ;
}
}
static int F_234 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_430 * V_283 ;
struct V_55 * V_25 = & V_2 -> V_21 . V_23 . V_24 . V_25 ;
int V_49 ;
struct V_124 * V_24 = (struct V_124 * ) & V_32 -> V_24 ;
struct V_265 * V_315 = NULL ;
if ( F_67 ( (struct V_124 * ) & V_32 -> V_24 ) )
return - V_65 ;
V_283 = F_40 ( sizeof *V_283 , V_77 ) ;
if ( ! V_283 )
return - V_78 ;
V_32 -> V_34 . V_35 = F_40 ( sizeof( struct V_408 ) , V_77 ) ;
if ( ! V_32 -> V_34 . V_35 ) {
V_49 = - V_78 ;
goto V_434;
}
F_233 ( V_24 , & V_32 -> V_34 . V_35 -> V_37 . V_43 ) ;
V_32 -> V_34 . V_35 -> V_37 . V_112 = F_147 ( 0xffff ) ;
if ( V_2 -> V_21 . V_39 == V_40 )
V_32 -> V_34 . V_35 -> V_37 . V_38 = F_229 ( V_41 ) ;
if ( V_25 -> V_317 )
V_315 = F_157 ( & V_271 , V_25 -> V_317 ) ;
if ( ! V_315 ) {
V_49 = - V_57 ;
goto V_435;
}
V_32 -> V_34 . V_35 -> V_37 . V_327 = F_164 ( V_315 ) ;
V_32 -> V_34 . V_35 -> V_37 . V_319 = 1 ;
V_32 -> V_34 . V_35 -> V_37 . V_325 = F_163 ( V_315 -> V_325 ) ;
F_129 ( V_315 ) ;
if ( ! V_32 -> V_34 . V_35 -> V_37 . V_325 ) {
V_49 = - V_65 ;
goto V_435;
}
F_33 ( V_25 , & V_32 -> V_34 . V_35 -> V_37 . V_415 ) ;
V_283 -> V_21 = V_2 ;
V_283 -> V_32 = V_32 ;
F_152 ( & V_283 -> V_283 , F_232 ) ;
F_235 ( & V_32 -> V_33 ) ;
F_143 ( V_288 , & V_283 -> V_283 ) ;
return 0 ;
V_435:
F_20 ( V_32 -> V_34 . V_35 ) ;
V_434:
F_20 ( V_283 ) ;
return V_49 ;
}
int F_236 ( struct V_71 * V_21 , struct V_124 * V_24 ,
void * V_73 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_1 ( V_2 , V_276 ) &&
! F_1 ( V_2 , V_286 ) )
return - V_65 ;
V_32 = F_107 ( sizeof *V_32 , V_77 ) ;
if ( ! V_32 )
return - V_78 ;
memcpy ( & V_32 -> V_24 , V_24 , F_138 ( V_24 ) ) ;
V_32 -> V_73 = V_73 ;
V_32 -> V_2 = V_2 ;
F_237 ( & V_2 -> V_7 ) ;
F_238 ( & V_32 -> V_28 , & V_2 -> V_84 ) ;
F_239 ( & V_2 -> V_7 ) ;
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_68 :
switch ( F_36 ( V_21 -> V_22 , V_21 -> V_44 ) ) {
case V_63 :
V_6 = F_228 ( V_2 , V_32 ) ;
break;
case V_64 :
F_240 ( & V_32 -> V_33 ) ;
V_6 = F_234 ( V_2 , V_32 ) ;
break;
default:
V_6 = - V_65 ;
}
break;
default:
V_6 = - V_123 ;
break;
}
if ( V_6 ) {
F_241 ( & V_2 -> V_7 ) ;
F_23 ( & V_32 -> V_28 ) ;
F_242 ( & V_2 -> V_7 ) ;
F_20 ( V_32 ) ;
}
return V_6 ;
}
void F_243 ( struct V_71 * V_21 , struct V_124 * V_24 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
F_241 ( & V_2 -> V_7 ) ;
F_35 (mc, &id_priv->mc_list, list) {
if ( ! memcmp ( & V_32 -> V_24 , V_24 , F_138 ( V_24 ) ) ) {
F_23 ( & V_32 -> V_28 ) ;
F_242 ( & V_2 -> V_7 ) ;
if ( V_21 -> V_87 )
F_244 ( V_21 -> V_87 ,
& V_32 -> V_34 . V_35 -> V_37 . V_43 ,
F_110 ( V_32 -> V_34 . V_35 -> V_37 . V_409 ) ) ;
if ( F_13 ( V_2 -> V_19 -> V_22 -> V_27 ) == V_68 ) {
switch ( F_36 ( V_21 -> V_22 , V_21 -> V_44 ) ) {
case V_63 :
F_94 ( V_32 -> V_34 . V_35 ) ;
F_20 ( V_32 ) ;
break;
case V_64 :
F_95 ( & V_32 -> V_33 , F_18 ) ;
break;
default:
break;
}
}
return;
}
}
F_242 ( & V_2 -> V_7 ) ;
}
static int F_245 ( struct V_265 * V_315 , struct V_1 * V_2 )
{
struct V_55 * V_25 ;
struct V_311 * V_283 ;
V_25 = & V_2 -> V_21 . V_23 . V_24 . V_25 ;
if ( ( V_25 -> V_317 == V_315 -> V_436 ) &&
memcmp ( V_25 -> V_66 , V_315 -> V_25 , V_315 -> V_437 ) ) {
F_105 ( V_438 L_4 ,
V_315 -> V_278 , & V_2 -> V_21 ) ;
V_283 = F_40 ( sizeof *V_283 , V_77 ) ;
if ( ! V_283 )
return - V_78 ;
F_152 ( & V_283 -> V_283 , F_150 ) ;
V_283 -> V_21 = V_2 ;
V_283 -> V_172 . V_172 = V_439 ;
F_12 ( & V_2 -> V_20 ) ;
F_143 ( V_288 , & V_283 -> V_283 ) ;
}
return 0 ;
}
static int F_246 ( struct V_440 * V_441 , unsigned long V_172 ,
void * V_442 )
{
struct V_265 * V_315 = (struct V_265 * ) V_442 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
int V_6 = V_443 ;
if ( F_247 ( V_315 ) != & V_271 )
return V_443 ;
if ( V_172 != V_444 )
return V_443 ;
if ( ! ( V_315 -> V_5 & V_445 ) || ! ( V_315 -> V_323 & V_446 ) )
return V_443 ;
F_22 ( & V_7 ) ;
F_35 (cma_dev, &dev_list, list)
F_35 (id_priv, &cma_dev->id_list, list) {
V_6 = F_245 ( V_315 , V_2 ) ;
if ( V_6 )
goto V_69;
}
V_69:
F_24 ( & V_7 ) ;
return V_6 ;
}
static void F_248 ( struct V_45 * V_22 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 ;
V_19 = F_107 ( sizeof *V_19 , V_77 ) ;
if ( ! V_19 )
return;
V_19 -> V_22 = V_22 ;
F_45 ( & V_19 -> V_4 ) ;
F_46 ( & V_19 -> V_20 , 1 ) ;
F_47 ( & V_19 -> V_29 ) ;
F_249 ( V_22 , & V_447 , V_19 ) ;
F_22 ( & V_7 ) ;
F_14 ( & V_19 -> V_28 , & V_333 ) ;
F_35 (id_priv, &listen_any_list, list)
F_137 ( V_2 , V_19 ) ;
F_24 ( & V_7 ) ;
}
static int F_250 ( struct V_1 * V_2 )
{
struct V_171 V_172 ;
enum V_3 V_8 ;
int V_6 = 0 ;
V_8 = F_5 ( V_2 , V_312 ) ;
if ( V_8 == V_164 )
return 0 ;
F_87 ( V_2 , V_8 ) ;
F_22 ( & V_2 -> V_70 ) ;
if ( ! F_1 ( V_2 , V_312 ) )
goto V_69;
memset ( & V_172 , 0 , sizeof V_172 ) ;
V_172 . V_172 = V_448 ;
V_6 = V_2 -> V_21 . V_72 ( & V_2 -> V_21 , & V_172 ) ;
V_69:
F_24 ( & V_2 -> V_70 ) ;
return V_6 ;
}
static void F_251 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_6 ;
F_22 ( & V_7 ) ;
while ( ! F_83 ( & V_19 -> V_29 ) ) {
V_2 = F_84 ( V_19 -> V_29 . V_156 ,
struct V_1 , V_28 ) ;
F_23 ( & V_2 -> V_83 ) ;
F_85 ( & V_2 -> V_28 ) ;
F_12 ( & V_2 -> V_20 ) ;
F_24 ( & V_7 ) ;
V_6 = V_2 -> V_165 ? 1 : F_250 ( V_2 ) ;
F_37 ( V_2 ) ;
if ( V_6 )
F_86 ( & V_2 -> V_21 ) ;
F_22 ( & V_7 ) ;
}
F_24 ( & V_7 ) ;
F_15 ( V_19 ) ;
F_98 ( & V_19 -> V_4 ) ;
}
static void F_252 ( struct V_45 * V_22 )
{
struct V_18 * V_19 ;
V_19 = F_253 ( V_22 , & V_447 ) ;
if ( ! V_19 )
return;
F_22 ( & V_7 ) ;
F_23 ( & V_19 -> V_28 ) ;
F_24 ( & V_7 ) ;
F_251 ( V_19 ) ;
F_20 ( V_19 ) ;
}
static int F_254 ( struct V_449 * V_450 , struct V_451 * V_452 )
{
struct V_453 * V_454 ;
struct V_455 * V_456 ;
struct V_1 * V_2 ;
struct V_71 * V_21 = NULL ;
struct V_18 * V_19 ;
int V_457 = 0 , V_458 = 0 ;
F_22 ( & V_7 ) ;
F_35 (cma_dev, &dev_list, list) {
if ( V_457 < V_452 -> args [ 0 ] ) {
V_457 ++ ;
continue;
}
V_458 = 0 ;
F_35 (id_priv, &cma_dev->id_list, list) {
if ( V_458 < V_452 -> args [ 1 ] ) {
V_458 ++ ;
continue;
}
V_456 = F_255 ( V_450 , & V_454 , V_452 -> V_454 -> V_459 ,
sizeof *V_456 , V_460 ,
V_461 ) ;
if ( ! V_456 )
goto V_69;
memset ( V_456 , 0 , sizeof *V_456 ) ;
V_21 = & V_2 -> V_21 ;
V_456 -> V_27 = V_21 -> V_23 . V_24 . V_25 . V_61 ;
V_456 -> V_44 = V_21 -> V_44 ;
V_456 -> V_317 =
V_21 -> V_23 . V_24 . V_25 . V_317 ;
if ( V_21 -> V_23 . V_24 . V_142 . V_301 == V_128 ) {
if ( F_256 ( V_450 , V_454 ,
sizeof( struct V_129 ) ,
& V_21 -> V_23 . V_24 . V_142 ,
V_462 ) ) {
goto V_69;
}
if ( F_256 ( V_450 , V_454 ,
sizeof( struct V_129 ) ,
& V_21 -> V_23 . V_24 . V_143 ,
V_463 ) ) {
goto V_69;
}
} else if ( V_21 -> V_23 . V_24 . V_142 . V_301 == V_250 ) {
if ( F_256 ( V_450 , V_454 ,
sizeof( struct V_132 ) ,
& V_21 -> V_23 . V_24 . V_142 ,
V_462 ) ) {
goto V_69;
}
if ( F_256 ( V_450 , V_454 ,
sizeof( struct V_132 ) ,
& V_21 -> V_23 . V_24 . V_143 ,
V_463 ) ) {
goto V_69;
}
}
V_456 -> V_464 = V_2 -> V_79 ;
V_456 -> V_465 = V_21 -> V_39 ;
V_456 -> V_466 = V_2 -> V_8 ;
V_456 -> V_103 = V_2 -> V_103 ;
V_456 -> V_76 = V_21 -> V_76 ;
V_458 ++ ;
}
V_452 -> args [ 1 ] = 0 ;
V_457 ++ ;
}
V_69:
F_24 ( & V_7 ) ;
V_452 -> args [ 0 ] = V_457 ;
V_452 -> args [ 1 ] = V_458 ;
return V_450 -> V_467 ;
}
static int T_9 F_257 ( void )
{
int V_6 ;
V_288 = F_258 ( L_5 ) ;
if ( ! V_288 )
return - V_78 ;
F_259 ( & V_307 ) ;
F_260 ( & V_340 ) ;
F_261 ( & V_468 ) ;
V_6 = F_262 ( & V_447 ) ;
if ( V_6 )
goto V_49;
if ( F_263 ( V_460 , V_469 , V_470 ) )
F_105 ( V_277 L_6 ) ;
return 0 ;
V_49:
F_264 ( & V_468 ) ;
F_265 ( & V_340 ) ;
F_266 ( & V_307 ) ;
F_267 ( V_288 ) ;
return V_6 ;
}
static void T_10 F_268 ( void )
{
F_269 ( V_460 ) ;
F_270 ( & V_447 ) ;
F_264 ( & V_468 ) ;
F_265 ( & V_340 ) ;
F_266 ( & V_307 ) ;
F_267 ( V_288 ) ;
F_271 ( & V_361 ) ;
F_271 ( & V_362 ) ;
F_271 ( & V_363 ) ;
F_271 ( & V_364 ) ;
F_271 ( & V_366 ) ;
}
