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
return 1 ;
for ( V_48 = 0 ; V_48 < V_51 . V_53 ; ++ V_48 ) {
V_49 = F_31 ( V_22 , V_44 , V_48 , & V_52 ) ;
if ( V_49 )
return 1 ;
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
F_22 ( & V_7 ) ;
F_33 ( V_25 , & V_56 ) ;
memcpy ( & V_47 , V_25 -> V_65 +
F_34 ( V_25 ) , sizeof V_47 ) ;
F_35 (cma_dev, &dev_list, list) {
for ( V_58 = 1 ; V_58 <= V_19 -> V_22 -> V_66 ; ++ V_58 ) {
if ( F_36 ( V_19 -> V_22 , V_58 ) == V_60 ) {
if ( F_13 ( V_19 -> V_22 -> V_27 ) == V_67 &&
F_36 ( V_19 -> V_22 , V_58 ) == V_64 )
V_6 = F_29 ( V_19 -> V_22 , & V_56 , V_58 ) ;
else
V_6 = F_29 ( V_19 -> V_22 , & V_47 , V_58 ) ;
if ( ! V_6 ) {
V_2 -> V_21 . V_44 = V_58 ;
goto V_68;
} else if ( V_6 == 1 )
break;
}
}
}
V_68:
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
F_22 ( & V_2 -> V_69 ) ;
if ( V_2 -> V_8 != V_8 ) {
F_24 ( & V_2 -> V_69 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
return ( V_2 -> V_21 . V_22 && V_2 -> V_71 . V_35 ) ;
}
struct V_72 * F_40 ( T_2 V_73 ,
void * V_74 , enum V_75 V_39 ,
enum V_76 V_77 )
{
struct V_1 * V_2 ;
V_2 = F_41 ( sizeof *V_2 , V_78 ) ;
if ( ! V_2 )
return F_42 ( - V_79 ) ;
V_2 -> V_80 = F_43 ( V_81 ) ;
V_2 -> V_8 = V_82 ;
V_2 -> V_21 . V_74 = V_74 ;
V_2 -> V_21 . V_73 = V_73 ;
V_2 -> V_21 . V_39 = V_39 ;
V_2 -> V_21 . V_77 = V_77 ;
F_44 ( & V_2 -> V_7 ) ;
F_45 ( & V_2 -> V_83 ) ;
F_46 ( & V_2 -> V_4 ) ;
F_47 ( & V_2 -> V_20 , 1 ) ;
F_45 ( & V_2 -> V_69 ) ;
F_48 ( & V_2 -> V_84 ) ;
F_48 ( & V_2 -> V_85 ) ;
F_49 ( & V_2 -> V_86 , sizeof V_2 -> V_86 ) ;
return & V_2 -> V_21 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
struct V_89 V_90 ;
int V_91 , V_6 ;
V_90 . V_92 = V_93 ;
V_6 = F_51 ( & V_2 -> V_21 , & V_90 , & V_91 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_52 ( V_88 , & V_90 , V_91 ) ;
if ( V_6 )
return V_6 ;
V_90 . V_92 = V_94 ;
V_6 = F_52 ( V_88 , & V_90 , V_95 ) ;
if ( V_6 )
return V_6 ;
V_90 . V_92 = V_96 ;
V_90 . V_97 = 0 ;
V_6 = F_52 ( V_88 , & V_90 , V_95 | V_98 ) ;
return V_6 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
struct V_89 V_90 ;
int V_91 , V_6 ;
V_90 . V_92 = V_93 ;
V_6 = F_51 ( & V_2 -> V_21 , & V_90 , & V_91 ) ;
if ( V_6 )
return V_6 ;
return F_52 ( V_88 , & V_90 , V_91 ) ;
}
int F_54 ( struct V_72 * V_21 , struct V_99 * V_100 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 ;
struct V_87 * V_88 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( V_21 -> V_22 != V_100 -> V_22 )
return - V_70 ;
V_88 = F_55 ( V_100 , V_102 ) ;
if ( F_56 ( V_88 ) )
return F_57 ( V_88 ) ;
if ( V_21 -> V_77 == V_103 )
V_6 = F_50 ( V_2 , V_88 ) ;
else
V_6 = F_53 ( V_2 , V_88 ) ;
if ( V_6 )
goto V_49;
V_21 -> V_88 = V_88 ;
V_2 -> V_104 = V_88 -> V_104 ;
V_2 -> V_105 = ( V_88 -> V_105 != NULL ) ;
return 0 ;
V_49:
F_58 ( V_88 ) ;
return V_6 ;
}
void F_59 ( struct V_72 * V_21 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
F_22 ( & V_2 -> V_83 ) ;
F_58 ( V_2 -> V_21 . V_88 ) ;
V_2 -> V_21 . V_88 = NULL ;
F_24 ( & V_2 -> V_83 ) ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_89 V_90 ;
int V_91 , V_6 ;
F_22 ( & V_2 -> V_83 ) ;
if ( ! V_2 -> V_21 . V_88 ) {
V_6 = 0 ;
goto V_68;
}
V_90 . V_92 = V_93 ;
V_6 = F_51 ( & V_2 -> V_21 , & V_90 , & V_91 ) ;
if ( V_6 )
goto V_68;
V_6 = F_52 ( V_2 -> V_21 . V_88 , & V_90 , V_91 ) ;
if ( V_6 )
goto V_68;
V_90 . V_92 = V_94 ;
V_6 = F_51 ( & V_2 -> V_21 , & V_90 , & V_91 ) ;
if ( V_6 )
goto V_68;
if ( V_107 )
V_90 . V_108 = V_107 -> V_109 ;
V_6 = F_52 ( V_2 -> V_21 . V_88 , & V_90 , V_91 ) ;
V_68:
F_24 ( & V_2 -> V_83 ) ;
return V_6 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_89 V_90 ;
int V_91 , V_6 ;
F_22 ( & V_2 -> V_83 ) ;
if ( ! V_2 -> V_21 . V_88 ) {
V_6 = 0 ;
goto V_68;
}
V_90 . V_92 = V_96 ;
V_6 = F_51 ( & V_2 -> V_21 , & V_90 , & V_91 ) ;
if ( V_6 )
goto V_68;
if ( V_107 )
V_90 . V_110 = V_107 -> V_111 ;
V_6 = F_52 ( V_2 -> V_21 . V_88 , & V_90 , V_91 ) ;
V_68:
F_24 ( & V_2 -> V_83 ) ;
return V_6 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_89 V_90 ;
int V_6 ;
F_22 ( & V_2 -> V_83 ) ;
if ( ! V_2 -> V_21 . V_88 ) {
V_6 = 0 ;
goto V_68;
}
V_90 . V_92 = V_112 ;
V_6 = F_52 ( V_2 -> V_21 . V_88 , & V_90 , V_95 ) ;
V_68:
F_24 ( & V_2 -> V_83 ) ;
return V_6 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_89 * V_90 , int * V_91 )
{
struct V_55 * V_25 = & V_2 -> V_21 . V_23 . V_24 . V_25 ;
int V_6 ;
T_3 V_113 ;
if ( F_36 ( V_2 -> V_21 . V_22 , V_2 -> V_21 . V_44 ) ==
V_63 )
V_113 = F_64 ( V_25 ) ;
else
V_113 = 0xffff ;
V_6 = F_65 ( V_2 -> V_21 . V_22 , V_2 -> V_21 . V_44 ,
V_113 , & V_90 -> V_114 ) ;
if ( V_6 )
return V_6 ;
V_90 -> V_44 = V_2 -> V_21 . V_44 ;
* V_91 = V_95 | V_115 | V_116 ;
if ( V_2 -> V_21 . V_77 == V_103 ) {
V_6 = F_25 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_90 -> V_38 = V_2 -> V_38 ;
* V_91 |= V_117 ;
} else {
V_90 -> V_118 = 0 ;
* V_91 |= V_119 ;
}
return 0 ;
}
int F_51 ( struct V_72 * V_21 , struct V_89 * V_90 ,
int * V_91 )
{
struct V_1 * V_2 ;
int V_6 = 0 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
switch ( F_13 ( V_2 -> V_21 . V_22 -> V_27 ) ) {
case V_67 :
if ( ! V_2 -> V_71 . V_35 || ( V_2 -> V_21 . V_77 == V_103 ) )
V_6 = F_63 ( V_2 , V_90 , V_91 ) ;
else
V_6 = F_66 ( V_2 -> V_71 . V_35 , V_90 ,
V_91 ) ;
if ( V_90 -> V_92 == V_94 )
V_90 -> V_120 = V_2 -> V_86 ;
break;
case V_121 :
if ( ! V_2 -> V_71 . V_122 ) {
V_90 -> V_118 = 0 ;
* V_91 = V_95 | V_119 ;
} else
V_6 = F_67 ( V_2 -> V_71 . V_122 , V_90 ,
V_91 ) ;
break;
default:
V_6 = - V_123 ;
break;
}
return V_6 ;
}
static inline int F_68 ( struct V_124 * V_24 )
{
struct V_125 * V_126 ;
if ( V_24 -> V_127 == V_128 )
return F_69 (
( (struct V_129 * ) V_24 ) -> V_130 . V_131 ) ;
else {
V_126 = & ( (struct V_132 * ) V_24 ) -> V_133 ;
return ( V_126 -> V_134 [ 0 ] | V_126 -> V_134 [ 1 ] |
V_126 -> V_134 [ 2 ] | V_126 -> V_134 [ 3 ] ) == 0 ;
}
}
static inline int F_70 ( struct V_124 * V_24 )
{
if ( V_24 -> V_127 == V_128 )
return F_71 (
( (struct V_129 * ) V_24 ) -> V_130 . V_131 ) ;
else
return F_72 (
& ( (struct V_132 * ) V_24 ) -> V_133 ) ;
}
static inline int F_73 ( struct V_124 * V_24 )
{
return F_68 ( V_24 ) || F_70 ( V_24 ) ;
}
static int F_74 ( struct V_124 * V_135 , struct V_124 * V_136 )
{
if ( V_135 -> V_127 != V_136 -> V_127 )
return - 1 ;
switch ( V_135 -> V_127 ) {
case V_128 :
return ( (struct V_129 * ) V_135 ) -> V_130 . V_131 !=
( (struct V_129 * ) V_136 ) -> V_130 . V_131 ;
default:
return F_75 ( & ( (struct V_132 * ) V_135 ) -> V_133 ,
& ( (struct V_132 * ) V_136 ) -> V_133 ) ;
}
}
static inline T_4 F_76 ( struct V_124 * V_24 )
{
if ( V_24 -> V_127 == V_128 )
return ( (struct V_129 * ) V_24 ) -> V_137 ;
else
return ( (struct V_132 * ) V_24 ) -> V_138 ;
}
static inline int F_77 ( struct V_124 * V_24 )
{
return ! F_76 ( V_24 ) ;
}
static int F_78 ( void * V_12 , enum V_75 V_39 ,
T_1 * V_14 , T_4 * V_58 ,
union V_139 * * V_135 , union V_139 * * V_136 )
{
switch ( V_39 ) {
case V_140 :
if ( F_8 ( ( (struct V_16 * ) V_12 ) -> V_15 ) !=
V_141 )
return - V_70 ;
* V_14 = F_9 ( V_12 ) ;
* V_58 = ( (struct V_16 * ) V_12 ) -> V_58 ;
* V_135 = & ( (struct V_16 * ) V_12 ) -> V_142 ;
* V_136 = & ( (struct V_16 * ) V_12 ) -> V_143 ;
break;
default:
if ( ( (struct V_11 * ) V_12 ) -> V_144 != V_145 )
return - V_70 ;
* V_14 = F_6 ( V_12 ) ;
* V_58 = ( (struct V_11 * ) V_12 ) -> V_58 ;
* V_135 = & ( (struct V_11 * ) V_12 ) -> V_142 ;
* V_136 = & ( (struct V_11 * ) V_12 ) -> V_143 ;
break;
}
if ( * V_14 != 4 && * V_14 != 6 )
return - V_70 ;
return 0 ;
}
static void F_79 ( struct V_146 * V_24 ,
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
static inline int F_80 ( enum V_75 V_39 )
{
switch ( V_39 ) {
case V_140 :
return 0 ;
default:
return sizeof( struct V_11 ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
switch ( F_36 ( V_2 -> V_21 . V_22 , V_2 -> V_21 . V_44 ) ) {
case V_63 :
if ( V_2 -> V_153 )
F_82 ( V_2 -> V_154 , V_2 -> V_153 ) ;
break;
default:
break;
}
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_1 * V_155 ;
F_22 ( & V_7 ) ;
F_23 ( & V_2 -> V_28 ) ;
while ( ! F_84 ( & V_2 -> V_84 ) ) {
V_155 = F_85 ( V_2 -> V_84 . V_156 ,
struct V_1 , V_84 ) ;
F_86 ( & V_155 -> V_28 ) ;
F_23 ( & V_155 -> V_84 ) ;
F_24 ( & V_7 ) ;
F_87 ( & V_155 -> V_21 ) ;
F_22 ( & V_7 ) ;
}
F_24 ( & V_7 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
enum V_3 V_8 )
{
switch ( V_8 ) {
case V_157 :
F_89 ( & V_2 -> V_21 . V_23 . V_24 . V_25 ) ;
break;
case V_158 :
F_81 ( V_2 ) ;
break;
case V_159 :
if ( F_73 ( (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 )
&& ! V_2 -> V_19 )
F_83 ( V_2 ) ;
break;
default:
break;
}
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_160 * V_161 = V_2 -> V_161 ;
if ( ! V_161 )
return;
F_22 ( & V_7 ) ;
F_91 ( & V_2 -> V_162 ) ;
if ( F_92 ( & V_161 -> V_163 ) ) {
F_93 ( V_161 -> V_39 , V_161 -> V_58 ) ;
F_20 ( V_161 ) ;
}
F_24 ( & V_7 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
while ( ! F_84 ( & V_2 -> V_85 ) ) {
V_32 = F_19 ( V_2 -> V_85 . V_156 ,
struct V_31 , V_28 ) ;
F_23 ( & V_32 -> V_28 ) ;
switch ( F_36 ( V_2 -> V_19 -> V_22 , V_2 -> V_21 . V_44 ) ) {
case V_63 :
F_95 ( V_32 -> V_34 . V_35 ) ;
F_20 ( V_32 ) ;
break;
case V_64 :
F_96 ( & V_32 -> V_33 , F_18 ) ;
break;
default:
break;
}
}
}
void F_87 ( struct V_72 * V_21 )
{
struct V_1 * V_2 ;
enum V_3 V_8 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
V_8 = F_5 ( V_2 , V_164 ) ;
F_88 ( V_2 , V_8 ) ;
F_22 ( & V_2 -> V_69 ) ;
F_24 ( & V_2 -> V_69 ) ;
if ( V_2 -> V_19 ) {
switch ( F_13 ( V_2 -> V_21 . V_22 -> V_27 ) ) {
case V_67 :
if ( V_2 -> V_71 . V_35 && ! F_56 ( V_2 -> V_71 . V_35 ) )
F_97 ( V_2 -> V_71 . V_35 ) ;
break;
case V_121 :
if ( V_2 -> V_71 . V_122 && ! F_56 ( V_2 -> V_71 . V_122 ) )
F_98 ( V_2 -> V_71 . V_122 ) ;
break;
default:
break;
}
F_94 ( V_2 ) ;
F_21 ( V_2 ) ;
}
F_90 ( V_2 ) ;
F_37 ( V_2 ) ;
F_99 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_165 )
F_37 ( V_2 -> V_21 . V_74 ) ;
F_20 ( V_2 -> V_21 . V_23 . V_166 ) ;
F_20 ( V_2 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_60 ( V_2 , NULL ) ;
if ( V_6 )
goto V_167;
V_6 = F_61 ( V_2 , NULL ) ;
if ( V_6 )
goto V_167;
V_6 = F_101 ( V_2 -> V_71 . V_35 , NULL , 0 ) ;
if ( V_6 )
goto V_167;
return 0 ;
V_167:
F_62 ( V_2 ) ;
F_102 ( V_2 -> V_71 . V_35 , V_168 ,
NULL , 0 , NULL , 0 ) ;
return V_6 ;
}
static int F_103 ( struct V_1 * V_2 , void * V_169 )
{
if ( V_2 -> V_21 . V_39 == V_140 &&
F_8 ( ( (struct V_170 * ) V_169 ) -> V_15 ) !=
V_141 )
return - V_70 ;
return 0 ;
}
static void F_104 ( struct V_171 * V_172 ,
struct V_173 * V_174 ,
void * V_175 )
{
V_172 -> V_176 . V_177 . V_175 = V_175 ;
V_172 -> V_176 . V_177 . V_178 = V_179 ;
V_172 -> V_176 . V_177 . V_109 = V_174 -> V_109 ;
V_172 -> V_176 . V_177 . V_111 = V_174 -> V_111 ;
V_172 -> V_176 . V_177 . V_180 = V_174 -> V_180 ;
V_172 -> V_176 . V_177 . V_181 = V_174 -> V_181 ;
V_172 -> V_176 . V_177 . V_105 = V_174 -> V_105 ;
V_172 -> V_176 . V_177 . V_104 = V_174 -> V_182 ;
}
static int F_105 ( struct V_183 * V_71 , struct V_184 * V_185 )
{
struct V_1 * V_2 = V_71 -> V_74 ;
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
V_172 . V_192 = F_103 ( V_2 , V_185 -> V_175 ) ;
if ( V_172 . V_192 )
V_172 . V_172 = V_195 ;
else if ( V_2 -> V_21 . V_88 && V_2 -> V_21 . V_39 != V_140 ) {
V_172 . V_192 = F_100 ( V_2 ) ;
V_172 . V_172 = V_172 . V_192 ? V_195 :
V_196 ;
} else
V_172 . V_172 = V_197 ;
F_104 ( & V_172 , & V_185 -> V_176 . V_198 ,
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
goto V_68;
V_172 . V_172 = V_204 ;
break;
case V_186 :
V_172 . V_172 = V_205 ;
break;
case V_206 :
goto V_68;
case V_207 :
F_62 ( V_2 ) ;
V_172 . V_192 = V_185 -> V_176 . V_208 . V_209 ;
V_172 . V_172 = V_210 ;
V_172 . V_176 . V_177 . V_175 = V_185 -> V_175 ;
V_172 . V_176 . V_177 . V_178 = V_211 ;
break;
default:
F_106 ( V_212 L_1 ,
V_185 -> V_172 ) ;
goto V_68;
}
V_6 = V_2 -> V_21 . V_73 ( & V_2 -> V_21 , & V_172 ) ;
if ( V_6 ) {
V_2 -> V_71 . V_35 = NULL ;
F_5 ( V_2 , V_164 ) ;
F_24 ( & V_2 -> V_69 ) ;
F_87 ( & V_2 -> V_21 ) ;
return V_6 ;
}
V_68:
F_24 ( & V_2 -> V_69 ) ;
return V_6 ;
}
static struct V_1 * F_107 ( struct V_72 * V_213 ,
struct V_184 * V_185 )
{
struct V_1 * V_2 ;
struct V_72 * V_21 ;
struct V_214 * V_215 ;
union V_139 * V_135 , * V_136 ;
T_4 V_58 ;
T_1 V_14 ;
int V_6 ;
if ( F_78 ( V_185 -> V_175 , V_213 -> V_39 ,
& V_14 , & V_58 , & V_135 , & V_136 ) )
goto V_49;
V_21 = F_40 ( V_213 -> V_73 , V_213 -> V_74 ,
V_213 -> V_39 , V_185 -> V_176 . V_216 . V_77 ) ;
if ( F_56 ( V_21 ) )
goto V_49;
F_79 ( & V_21 -> V_23 . V_24 , & V_213 -> V_23 . V_24 ,
V_14 , V_58 , V_135 , V_136 ) ;
V_215 = & V_21 -> V_23 ;
V_215 -> V_217 = V_185 -> V_176 . V_216 . V_218 ? 2 : 1 ;
V_215 -> V_166 = F_108 ( sizeof * V_215 -> V_166 * V_215 -> V_217 ,
V_78 ) ;
if ( ! V_215 -> V_166 )
goto V_219;
V_215 -> V_166 [ 0 ] = * V_185 -> V_176 . V_216 . V_220 ;
if ( V_215 -> V_217 == 2 )
V_215 -> V_166 [ 1 ] = * V_185 -> V_176 . V_216 . V_218 ;
if ( F_73 ( (struct V_124 * ) & V_215 -> V_24 . V_142 ) ) {
V_215 -> V_24 . V_25 . V_61 = V_62 ;
F_109 ( & V_215 -> V_24 . V_25 , & V_215 -> V_166 [ 0 ] . V_221 ) ;
F_110 ( & V_215 -> V_24 . V_25 , V_215 -> V_166 [ 0 ] . V_113 ) ;
} else {
V_6 = F_111 ( (struct V_124 * ) & V_215 -> V_24 . V_142 ,
& V_215 -> V_24 . V_25 ) ;
if ( V_6 )
goto V_219;
}
F_112 ( & V_215 -> V_24 . V_25 , & V_215 -> V_166 [ 0 ] . V_222 ) ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
V_2 -> V_8 = V_187 ;
return V_2 ;
V_219:
F_87 ( V_21 ) ;
V_49:
return NULL ;
}
static struct V_1 * F_113 ( struct V_72 * V_213 ,
struct V_184 * V_185 )
{
struct V_1 * V_2 ;
struct V_72 * V_21 ;
union V_139 * V_135 , * V_136 ;
T_4 V_58 ;
T_1 V_14 ;
int V_6 ;
V_21 = F_40 ( V_213 -> V_73 , V_213 -> V_74 ,
V_213 -> V_39 , V_103 ) ;
if ( F_56 ( V_21 ) )
return NULL ;
if ( F_78 ( V_185 -> V_175 , V_213 -> V_39 ,
& V_14 , & V_58 , & V_135 , & V_136 ) )
goto V_49;
F_79 ( & V_21 -> V_23 . V_24 , & V_213 -> V_23 . V_24 ,
V_14 , V_58 , V_135 , V_136 ) ;
if ( ! F_73 ( (struct V_124 * ) & V_21 -> V_23 . V_24 . V_142 ) ) {
V_6 = F_111 ( (struct V_124 * ) & V_21 -> V_23 . V_24 . V_142 ,
& V_21 -> V_23 . V_24 . V_25 ) ;
if ( V_6 )
goto V_49;
}
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
V_2 -> V_8 = V_187 ;
return V_2 ;
V_49:
F_87 ( V_21 ) ;
return NULL ;
}
static void F_114 ( struct V_171 * V_172 ,
struct V_223 * V_224 ,
void * V_175 , int V_225 )
{
V_172 -> V_176 . V_177 . V_175 = V_175 + V_225 ;
V_172 -> V_176 . V_177 . V_178 = V_226 - V_225 ;
V_172 -> V_176 . V_177 . V_109 = V_224 -> V_109 ;
V_172 -> V_176 . V_177 . V_111 = V_224 -> V_111 ;
V_172 -> V_176 . V_177 . V_180 = V_224 -> V_180 ;
V_172 -> V_176 . V_177 . V_227 = V_224 -> V_227 ;
V_172 -> V_176 . V_177 . V_181 = V_224 -> V_181 ;
V_172 -> V_176 . V_177 . V_105 = V_224 -> V_105 ;
V_172 -> V_176 . V_177 . V_104 = V_224 -> V_182 ;
}
static int F_115 ( struct V_183 * V_71 , struct V_184 * V_185 )
{
struct V_1 * V_213 , * V_228 ;
struct V_171 V_172 ;
int V_225 , V_6 ;
V_213 = V_71 -> V_74 ;
if ( F_38 ( V_213 , V_159 ) )
return - V_229 ;
memset ( & V_172 , 0 , sizeof V_172 ) ;
V_225 = F_80 ( V_213 -> V_21 . V_39 ) ;
V_172 . V_172 = V_230 ;
if ( V_213 -> V_21 . V_77 == V_103 ) {
V_228 = F_113 ( & V_213 -> V_21 , V_185 ) ;
V_172 . V_176 . V_231 . V_175 = V_185 -> V_175 + V_225 ;
V_172 . V_176 . V_231 . V_178 =
V_232 - V_225 ;
} else {
V_228 = F_107 ( & V_213 -> V_21 , V_185 ) ;
F_114 ( & V_172 , & V_185 -> V_176 . V_216 ,
V_185 -> V_175 , V_225 ) ;
}
if ( ! V_228 ) {
V_6 = - V_79 ;
goto V_68;
}
F_116 ( & V_228 -> V_69 , V_233 ) ;
V_6 = F_32 ( V_228 ) ;
if ( V_6 )
goto V_234;
V_228 -> V_71 . V_35 = V_71 ;
V_71 -> V_74 = V_228 ;
V_71 -> V_235 = F_105 ;
F_12 ( & V_228 -> V_20 ) ;
V_6 = V_228 -> V_21 . V_73 ( & V_228 -> V_21 , & V_172 ) ;
if ( ! V_6 ) {
F_22 ( & V_7 ) ;
if ( F_1 ( V_228 , V_187 ) && ( V_228 -> V_21 . V_77 != V_103 ) )
F_117 ( V_71 , V_236 , NULL , 0 ) ;
F_24 ( & V_7 ) ;
F_24 ( & V_228 -> V_69 ) ;
F_37 ( V_228 ) ;
goto V_68;
}
F_37 ( V_228 ) ;
V_228 -> V_71 . V_35 = NULL ;
V_234:
F_5 ( V_228 , V_164 ) ;
F_24 ( & V_228 -> V_69 ) ;
F_87 ( & V_228 -> V_21 ) ;
V_68:
F_24 ( & V_213 -> V_69 ) ;
return V_6 ;
}
static T_5 F_118 ( enum V_75 V_39 , struct V_124 * V_24 )
{
return F_119 ( ( ( V_237 ) V_39 << 16 ) + F_120 ( F_76 ( V_24 ) ) ) ;
}
static void F_121 ( enum V_75 V_39 , struct V_124 * V_24 ,
struct V_238 * V_239 )
{
struct V_11 * V_240 , * V_241 ;
struct V_16 * V_242 , * V_243 ;
T_6 V_244 ;
struct V_125 V_245 ;
memset ( V_239 , 0 , sizeof *V_239 ) ;
V_240 = ( void * ) V_239 -> V_169 ;
V_241 = ( void * ) V_239 -> V_246 ;
V_242 = ( void * ) V_239 -> V_169 ;
V_243 = ( void * ) V_239 -> V_246 ;
switch ( V_24 -> V_127 ) {
case V_128 :
V_244 = ( (struct V_129 * ) V_24 ) -> V_130 . V_131 ;
if ( V_39 == V_140 ) {
F_10 ( V_242 , 4 ) ;
F_10 ( V_243 , 0xF ) ;
V_242 -> V_143 . V_149 . V_24 = V_244 ;
V_243 -> V_143 . V_149 . V_24 = F_122 ( ~ 0 ) ;
} else {
F_7 ( V_240 , 4 ) ;
F_7 ( V_241 , 0xF ) ;
V_240 -> V_143 . V_149 . V_24 = V_244 ;
V_241 -> V_143 . V_149 . V_24 = F_122 ( ~ 0 ) ;
}
break;
case V_247 :
V_245 = ( (struct V_132 * ) V_24 ) -> V_133 ;
if ( V_39 == V_140 ) {
F_10 ( V_242 , 6 ) ;
F_10 ( V_243 , 0xF ) ;
V_242 -> V_143 . V_126 = V_245 ;
memset ( & V_243 -> V_143 . V_126 , 0xFF ,
sizeof V_243 -> V_143 . V_126 ) ;
} else {
F_7 ( V_240 , 6 ) ;
F_7 ( V_241 , 0xF ) ;
V_240 -> V_143 . V_126 = V_245 ;
memset ( & V_241 -> V_143 . V_126 , 0xFF ,
sizeof V_241 -> V_143 . V_126 ) ;
}
break;
default:
break;
}
}
static int F_123 ( struct V_248 * V_249 , struct V_250 * V_251 )
{
struct V_1 * V_2 = V_249 -> V_74 ;
struct V_171 V_172 ;
struct V_129 * sin ;
int V_6 = 0 ;
if ( F_38 ( V_2 , V_187 ) )
return 0 ;
memset ( & V_172 , 0 , sizeof V_172 ) ;
switch ( V_251 -> V_172 ) {
case V_252 :
V_172 . V_172 = V_204 ;
break;
case V_253 :
sin = (struct V_129 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
* sin = V_251 -> V_254 ;
sin = (struct V_129 * ) & V_2 -> V_21 . V_23 . V_24 . V_143 ;
* sin = V_251 -> V_255 ;
switch ( V_251 -> V_192 ) {
case 0 :
V_172 . V_172 = V_196 ;
break;
case - V_256 :
case - V_257 :
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
case V_258 :
V_172 . V_172 = V_196 ;
break;
default:
F_124 ( 1 ) ;
}
V_172 . V_192 = V_251 -> V_192 ;
V_172 . V_176 . V_177 . V_175 = V_251 -> V_175 ;
V_172 . V_176 . V_177 . V_178 = V_251 -> V_178 ;
V_6 = V_2 -> V_21 . V_73 ( & V_2 -> V_21 , & V_172 ) ;
if ( V_6 ) {
V_2 -> V_71 . V_122 = NULL ;
F_5 ( V_2 , V_164 ) ;
F_24 ( & V_2 -> V_69 ) ;
F_87 ( & V_2 -> V_21 ) ;
return V_6 ;
}
F_24 ( & V_2 -> V_69 ) ;
return V_6 ;
}
static int F_125 ( struct V_248 * V_71 ,
struct V_250 * V_251 )
{
struct V_72 * V_259 ;
struct V_1 * V_213 , * V_228 ;
struct V_129 * sin ;
struct V_260 * V_261 = NULL ;
struct V_171 V_172 ;
int V_6 ;
struct V_262 V_263 ;
V_213 = V_71 -> V_74 ;
if ( F_38 ( V_213 , V_159 ) )
return - V_229 ;
V_259 = F_40 ( V_213 -> V_21 . V_73 ,
V_213 -> V_21 . V_74 ,
V_264 , V_265 ) ;
if ( F_56 ( V_259 ) ) {
V_6 = - V_79 ;
goto V_68;
}
V_228 = F_19 ( V_259 , struct V_1 , V_21 ) ;
F_116 ( & V_228 -> V_69 , V_233 ) ;
V_228 -> V_8 = V_187 ;
V_261 = F_126 ( & V_266 , V_251 -> V_254 . V_130 . V_131 ) ;
if ( ! V_261 ) {
V_6 = - V_267 ;
F_24 ( & V_228 -> V_69 ) ;
F_87 ( V_259 ) ;
goto V_68;
}
V_6 = F_127 ( & V_228 -> V_21 . V_23 . V_24 . V_25 , V_261 , NULL ) ;
if ( V_6 ) {
F_24 ( & V_228 -> V_69 ) ;
F_87 ( V_259 ) ;
goto V_68;
}
V_6 = F_32 ( V_228 ) ;
if ( V_6 ) {
F_24 ( & V_228 -> V_69 ) ;
F_87 ( V_259 ) ;
goto V_68;
}
V_228 -> V_71 . V_122 = V_71 ;
V_71 -> V_74 = V_228 ;
V_71 -> V_235 = F_123 ;
sin = (struct V_129 * ) & V_259 -> V_23 . V_24 . V_142 ;
* sin = V_251 -> V_254 ;
sin = (struct V_129 * ) & V_259 -> V_23 . V_24 . V_143 ;
* sin = V_251 -> V_255 ;
V_6 = F_128 ( V_228 -> V_21 . V_22 , & V_263 ) ;
if ( V_6 ) {
F_24 ( & V_228 -> V_69 ) ;
F_87 ( V_259 ) ;
goto V_68;
}
memset ( & V_172 , 0 , sizeof V_172 ) ;
V_172 . V_172 = V_230 ;
V_172 . V_176 . V_177 . V_175 = V_251 -> V_175 ;
V_172 . V_176 . V_177 . V_178 = V_251 -> V_178 ;
V_172 . V_176 . V_177 . V_111 = V_263 . V_268 ;
V_172 . V_176 . V_177 . V_109 = V_263 . V_269 ;
F_12 ( & V_228 -> V_20 ) ;
V_6 = V_228 -> V_21 . V_73 ( & V_228 -> V_21 , & V_172 ) ;
if ( V_6 ) {
V_228 -> V_71 . V_122 = NULL ;
F_5 ( V_228 , V_164 ) ;
F_24 ( & V_228 -> V_69 ) ;
F_37 ( V_228 ) ;
F_87 ( & V_228 -> V_21 ) ;
goto V_68;
}
F_24 ( & V_228 -> V_69 ) ;
F_37 ( V_228 ) ;
V_68:
if ( V_261 )
F_129 ( V_261 ) ;
F_24 ( & V_213 -> V_69 ) ;
return V_6 ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_238 V_270 ;
struct V_124 * V_24 ;
T_5 V_271 ;
int V_6 ;
V_2 -> V_71 . V_35 = F_131 ( V_2 -> V_21 . V_22 , F_115 ,
V_2 ) ;
if ( F_56 ( V_2 -> V_71 . V_35 ) )
return F_57 ( V_2 -> V_71 . V_35 ) ;
V_24 = (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
V_271 = F_118 ( V_2 -> V_21 . V_39 , V_24 ) ;
if ( F_73 ( V_24 ) )
V_6 = F_132 ( V_2 -> V_71 . V_35 , V_271 , 0 , NULL ) ;
else {
F_121 ( V_2 -> V_21 . V_39 , V_24 , & V_270 ) ;
V_6 = F_132 ( V_2 -> V_71 . V_35 , V_271 , 0 , & V_270 ) ;
}
if ( V_6 ) {
F_97 ( V_2 -> V_71 . V_35 ) ;
V_2 -> V_71 . V_35 = NULL ;
}
return V_6 ;
}
static int F_133 ( struct V_1 * V_2 , int V_272 )
{
int V_6 ;
struct V_129 * sin ;
V_2 -> V_71 . V_122 = F_134 ( V_2 -> V_21 . V_22 ,
F_125 ,
V_2 ) ;
if ( F_56 ( V_2 -> V_71 . V_122 ) )
return F_57 ( V_2 -> V_71 . V_122 ) ;
sin = (struct V_129 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
V_2 -> V_71 . V_122 -> V_254 = * sin ;
V_6 = F_135 ( V_2 -> V_71 . V_122 , V_272 ) ;
if ( V_6 ) {
F_98 ( V_2 -> V_71 . V_122 ) ;
V_2 -> V_71 . V_122 = NULL ;
}
return V_6 ;
}
static int F_136 ( struct V_72 * V_21 ,
struct V_171 * V_172 )
{
struct V_1 * V_2 = V_21 -> V_74 ;
V_21 -> V_74 = V_2 -> V_21 . V_74 ;
V_21 -> V_73 = V_2 -> V_21 . V_73 ;
return V_2 -> V_21 . V_73 ( V_21 , V_172 ) ;
}
static void F_137 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_1 * V_155 ;
struct V_72 * V_21 ;
int V_6 ;
V_21 = F_40 ( F_136 , V_2 , V_2 -> V_21 . V_39 ,
V_2 -> V_21 . V_77 ) ;
if ( F_56 ( V_21 ) )
return;
V_155 = F_19 ( V_21 , struct V_1 , V_21 ) ;
V_155 -> V_8 = V_273 ;
memcpy ( & V_21 -> V_23 . V_24 . V_142 , & V_2 -> V_21 . V_23 . V_24 . V_142 ,
F_138 ( (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ) ) ;
F_11 ( V_155 , V_19 ) ;
F_14 ( & V_155 -> V_84 , & V_2 -> V_84 ) ;
F_12 ( & V_2 -> V_20 ) ;
V_155 -> V_165 = 1 ;
V_6 = F_139 ( V_21 , V_2 -> V_272 ) ;
if ( V_6 )
F_106 ( V_274 L_2
L_3 , V_6 , V_19 -> V_22 -> V_275 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
F_22 ( & V_7 ) ;
F_14 ( & V_2 -> V_28 , & V_276 ) ;
F_35 (cma_dev, &dev_list, list)
F_137 ( V_2 , V_19 ) ;
F_24 ( & V_7 ) ;
}
void F_141 ( struct V_72 * V_21 , int V_277 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
V_2 -> V_277 = ( T_1 ) V_277 ;
}
static void F_142 ( int V_192 , struct V_278 * V_166 ,
void * V_74 )
{
struct V_279 * V_280 = V_74 ;
struct V_214 * V_23 ;
V_23 = & V_280 -> V_21 -> V_21 . V_23 ;
if ( ! V_192 ) {
V_23 -> V_217 = 1 ;
* V_23 -> V_166 = * V_166 ;
} else {
V_280 -> V_281 = V_158 ;
V_280 -> V_282 = V_283 ;
V_280 -> V_172 . V_172 = V_284 ;
V_280 -> V_172 . V_192 = V_192 ;
}
F_143 ( V_285 , & V_280 -> V_280 ) ;
}
static int F_144 ( struct V_1 * V_2 , int V_286 ,
struct V_279 * V_280 )
{
struct V_146 * V_24 = & V_2 -> V_21 . V_23 . V_24 ;
struct V_278 V_166 ;
T_7 V_287 ;
struct V_132 * V_288 ;
memset ( & V_166 , 0 , sizeof V_166 ) ;
F_145 ( & V_24 -> V_25 , & V_166 . V_221 ) ;
F_146 ( & V_24 -> V_25 , & V_166 . V_222 ) ;
V_166 . V_113 = F_147 ( F_64 ( & V_24 -> V_25 ) ) ;
V_166 . V_289 = 1 ;
V_166 . V_290 = 1 ;
V_166 . V_291 = F_118 ( V_2 -> V_21 . V_39 ,
(struct V_124 * ) & V_24 -> V_143 ) ;
V_287 = V_292 | V_293 |
V_294 | V_295 |
V_296 | V_297 ;
if ( V_24 -> V_142 . V_298 == V_128 ) {
V_166 . V_299 = F_147 ( ( T_3 ) V_2 -> V_277 ) ;
V_287 |= V_300 ;
} else {
V_288 = (struct V_132 * ) & V_24 -> V_142 ;
V_166 . V_301 = ( T_1 ) ( F_28 ( V_288 -> V_302 ) >> 20 ) ;
V_287 |= V_303 ;
}
V_2 -> V_154 = F_148 ( & V_304 , V_2 -> V_21 . V_22 ,
V_2 -> V_21 . V_44 , & V_166 ,
V_287 , V_286 ,
V_78 , F_142 ,
V_280 , & V_2 -> V_153 ) ;
return ( V_2 -> V_154 < 0 ) ? V_2 -> V_154 : 0 ;
}
static void F_149 ( struct V_305 * V_306 )
{
struct V_279 * V_280 = F_19 ( V_306 , struct V_279 , V_280 ) ;
struct V_1 * V_2 = V_280 -> V_21 ;
int V_307 = 0 ;
F_22 ( & V_2 -> V_69 ) ;
if ( ! F_4 ( V_2 , V_280 -> V_281 , V_280 -> V_282 ) )
goto V_68;
if ( V_2 -> V_21 . V_73 ( & V_2 -> V_21 , & V_280 -> V_172 ) ) {
F_5 ( V_2 , V_164 ) ;
V_307 = 1 ;
}
V_68:
F_24 ( & V_2 -> V_69 ) ;
F_37 ( V_2 ) ;
if ( V_307 )
F_87 ( & V_2 -> V_21 ) ;
F_20 ( V_280 ) ;
}
static void F_150 ( struct V_305 * V_306 )
{
struct V_308 * V_280 = F_19 ( V_306 , struct V_308 , V_280 ) ;
struct V_1 * V_2 = V_280 -> V_21 ;
int V_307 = 0 ;
F_22 ( & V_2 -> V_69 ) ;
if ( V_2 -> V_8 == V_164 ||
V_2 -> V_8 == V_309 )
goto V_68;
if ( V_2 -> V_21 . V_73 ( & V_2 -> V_21 , & V_280 -> V_172 ) ) {
F_5 ( V_2 , V_164 ) ;
V_307 = 1 ;
}
V_68:
F_24 ( & V_2 -> V_69 ) ;
F_37 ( V_2 ) ;
if ( V_307 )
F_87 ( & V_2 -> V_21 ) ;
F_20 ( V_280 ) ;
}
static int F_151 ( struct V_1 * V_2 , int V_286 )
{
struct V_214 * V_23 = & V_2 -> V_21 . V_23 ;
struct V_279 * V_280 ;
int V_6 ;
V_280 = F_41 ( sizeof *V_280 , V_78 ) ;
if ( ! V_280 )
return - V_79 ;
V_280 -> V_21 = V_2 ;
F_152 ( & V_280 -> V_280 , F_149 ) ;
V_280 -> V_281 = V_158 ;
V_280 -> V_282 = V_310 ;
V_280 -> V_172 . V_172 = V_311 ;
V_23 -> V_166 = F_108 ( sizeof * V_23 -> V_166 , V_78 ) ;
if ( ! V_23 -> V_166 ) {
V_6 = - V_79 ;
goto V_312;
}
V_6 = F_144 ( V_2 , V_286 , V_280 ) ;
if ( V_6 )
goto V_313;
return 0 ;
V_313:
F_20 ( V_23 -> V_166 ) ;
V_23 -> V_166 = NULL ;
V_312:
F_20 ( V_280 ) ;
return V_6 ;
}
int F_153 ( struct V_72 * V_21 ,
struct V_278 * V_166 , int V_217 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_4 ( V_2 , V_283 ,
V_310 ) )
return - V_70 ;
V_21 -> V_23 . V_166 = F_154 ( V_166 , sizeof *V_166 * V_217 ,
V_78 ) ;
if ( ! V_21 -> V_23 . V_166 ) {
V_6 = - V_79 ;
goto V_49;
}
V_21 -> V_23 . V_217 = V_217 ;
return 0 ;
V_49:
F_4 ( V_2 , V_310 , V_283 ) ;
return V_6 ;
}
static int F_155 ( struct V_1 * V_2 , int V_286 )
{
struct V_279 * V_280 ;
V_280 = F_41 ( sizeof *V_280 , V_78 ) ;
if ( ! V_280 )
return - V_79 ;
V_280 -> V_21 = V_2 ;
F_152 ( & V_280 -> V_280 , F_149 ) ;
V_280 -> V_281 = V_158 ;
V_280 -> V_282 = V_310 ;
V_280 -> V_172 . V_172 = V_311 ;
F_143 ( V_285 , & V_280 -> V_280 ) ;
return 0 ;
}
static int F_156 ( struct V_1 * V_2 )
{
struct V_214 * V_23 = & V_2 -> V_21 . V_23 ;
struct V_146 * V_24 = & V_23 -> V_24 ;
struct V_279 * V_280 ;
int V_6 ;
struct V_129 * V_142 = (struct V_129 * ) & V_23 -> V_24 . V_142 ;
struct V_129 * V_143 = (struct V_129 * ) & V_23 -> V_24 . V_143 ;
struct V_260 * V_314 = NULL ;
T_3 V_315 ;
if ( V_142 -> V_151 != V_143 -> V_151 )
return - V_70 ;
V_280 = F_41 ( sizeof *V_280 , V_78 ) ;
if ( ! V_280 )
return - V_79 ;
V_280 -> V_21 = V_2 ;
F_152 ( & V_280 -> V_280 , F_149 ) ;
V_23 -> V_166 = F_41 ( sizeof * V_23 -> V_166 , V_78 ) ;
if ( ! V_23 -> V_166 ) {
V_6 = - V_79 ;
goto V_312;
}
V_23 -> V_217 = 1 ;
if ( V_24 -> V_25 . V_316 )
V_314 = F_157 ( & V_266 , V_24 -> V_25 . V_316 ) ;
if ( ! V_314 ) {
V_6 = - V_57 ;
goto V_313;
}
V_315 = F_158 ( V_314 ) ;
F_159 ( & V_23 -> V_166 -> V_221 , V_24 -> V_25 . V_65 , V_315 ) ;
F_159 ( & V_23 -> V_166 -> V_222 , V_24 -> V_25 . V_317 , V_315 ) ;
V_23 -> V_166 -> V_318 = 1 ;
V_23 -> V_166 -> V_290 = 1 ;
V_23 -> V_166 -> V_113 = F_147 ( 0xffff ) ;
V_23 -> V_166 -> V_319 = V_320 ;
V_23 -> V_166 -> V_321 = V_2 -> V_277 >> 5 ;
V_23 -> V_166 -> V_322 = F_160 ( V_314 -> V_322 ) ;
V_23 -> V_166 -> V_323 = V_320 ;
V_23 -> V_166 -> V_324 = F_161 ( V_314 ) ;
F_129 ( V_314 ) ;
V_23 -> V_166 -> V_325 = V_320 ;
V_23 -> V_166 -> V_326 = V_327 ;
if ( ! V_23 -> V_166 -> V_322 ) {
V_6 = - V_70 ;
goto V_313;
}
V_280 -> V_281 = V_158 ;
V_280 -> V_282 = V_310 ;
V_280 -> V_172 . V_172 = V_311 ;
V_280 -> V_172 . V_192 = 0 ;
F_143 ( V_285 , & V_280 -> V_280 ) ;
return 0 ;
V_313:
F_20 ( V_23 -> V_166 ) ;
V_23 -> V_166 = NULL ;
V_312:
F_20 ( V_280 ) ;
return V_6 ;
}
int F_162 ( struct V_72 * V_21 , int V_286 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_4 ( V_2 , V_283 , V_158 ) )
return - V_70 ;
F_12 ( & V_2 -> V_20 ) ;
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_67 :
switch ( F_36 ( V_21 -> V_22 , V_21 -> V_44 ) ) {
case V_63 :
V_6 = F_151 ( V_2 , V_286 ) ;
break;
case V_64 :
V_6 = F_156 ( V_2 ) ;
break;
default:
V_6 = - V_123 ;
}
break;
case V_121 :
V_6 = F_155 ( V_2 , V_286 ) ;
break;
default:
V_6 = - V_123 ;
break;
}
if ( V_6 )
goto V_49;
return 0 ;
V_49:
F_4 ( V_2 , V_158 , V_283 ) ;
F_37 ( V_2 ) ;
return V_6 ;
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_50 V_328 ;
union V_46 V_47 ;
T_3 V_113 ;
int V_6 ;
T_1 V_329 ;
F_22 ( & V_7 ) ;
if ( F_84 ( & V_330 ) ) {
V_6 = - V_57 ;
goto V_68;
}
F_35 (cma_dev, &dev_list, list)
for ( V_329 = 1 ; V_329 <= V_19 -> V_22 -> V_66 ; ++ V_329 )
if ( ! F_30 ( V_19 -> V_22 , V_329 , & V_328 ) &&
V_328 . V_8 == V_331 )
goto V_332;
V_329 = 1 ;
V_19 = F_85 ( V_330 . V_156 , struct V_18 , V_28 ) ;
V_332:
V_6 = F_164 ( V_19 -> V_22 , V_329 , 0 , & V_47 ) ;
if ( V_6 )
goto V_68;
V_6 = F_165 ( V_19 -> V_22 , V_329 , 0 , & V_113 ) ;
if ( V_6 )
goto V_68;
V_2 -> V_21 . V_23 . V_24 . V_25 . V_61 =
( F_36 ( V_19 -> V_22 , V_329 ) == V_63 ) ?
V_62 : V_333 ;
F_109 ( & V_2 -> V_21 . V_23 . V_24 . V_25 , & V_47 ) ;
F_110 ( & V_2 -> V_21 . V_23 . V_24 . V_25 , V_113 ) ;
V_2 -> V_21 . V_44 = V_329 ;
F_11 ( V_2 , V_19 ) ;
V_68:
F_24 ( & V_7 ) ;
return V_6 ;
}
static void F_166 ( int V_192 , struct V_124 * V_142 ,
struct V_55 * V_25 , void * V_74 )
{
struct V_1 * V_2 = V_74 ;
struct V_171 V_172 ;
memset ( & V_172 , 0 , sizeof V_172 ) ;
F_22 ( & V_2 -> V_69 ) ;
if ( ! F_4 ( V_2 , V_157 ,
V_283 ) )
goto V_68;
if ( ! V_192 && ! V_2 -> V_19 )
V_192 = F_32 ( V_2 ) ;
if ( V_192 ) {
if ( ! F_4 ( V_2 , V_283 ,
V_273 ) )
goto V_68;
V_172 . V_172 = V_334 ;
V_172 . V_192 = V_192 ;
} else {
memcpy ( & V_2 -> V_21 . V_23 . V_24 . V_142 , V_142 ,
F_138 ( V_142 ) ) ;
V_172 . V_172 = V_335 ;
}
if ( V_2 -> V_21 . V_73 ( & V_2 -> V_21 , & V_172 ) ) {
F_5 ( V_2 , V_164 ) ;
F_24 ( & V_2 -> V_69 ) ;
F_37 ( V_2 ) ;
F_87 ( & V_2 -> V_21 ) ;
return;
}
V_68:
F_24 ( & V_2 -> V_69 ) ;
F_37 ( V_2 ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
struct V_279 * V_280 ;
struct V_124 * V_135 , * V_136 ;
union V_46 V_47 ;
int V_6 ;
V_280 = F_41 ( sizeof *V_280 , V_78 ) ;
if ( ! V_280 )
return - V_79 ;
if ( ! V_2 -> V_19 ) {
V_6 = F_163 ( V_2 ) ;
if ( V_6 )
goto V_49;
}
F_145 ( & V_2 -> V_21 . V_23 . V_24 . V_25 , & V_47 ) ;
F_112 ( & V_2 -> V_21 . V_23 . V_24 . V_25 , & V_47 ) ;
V_135 = (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
if ( F_68 ( V_135 ) ) {
V_136 = (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_143 ;
if ( ( V_135 -> V_127 = V_136 -> V_127 ) == V_128 ) {
( (struct V_129 * ) V_135 ) -> V_130 . V_131 =
( (struct V_129 * ) V_136 ) -> V_130 . V_131 ;
} else {
F_168 ( & ( (struct V_132 * ) V_135 ) -> V_133 ,
& ( (struct V_132 * ) V_136 ) -> V_133 ) ;
}
}
V_280 -> V_21 = V_2 ;
F_152 ( & V_280 -> V_280 , F_149 ) ;
V_280 -> V_281 = V_157 ;
V_280 -> V_282 = V_283 ;
V_280 -> V_172 . V_172 = V_335 ;
F_143 ( V_285 , & V_280 -> V_280 ) ;
return 0 ;
V_49:
F_20 ( V_280 ) ;
return V_6 ;
}
static int F_169 ( struct V_72 * V_21 , struct V_124 * V_142 ,
struct V_124 * V_143 )
{
if ( ! V_142 || ! V_142 -> V_127 ) {
V_142 = (struct V_124 * ) & V_21 -> V_23 . V_24 . V_142 ;
if ( ( V_142 -> V_127 = V_143 -> V_127 ) == V_247 ) {
( (struct V_132 * ) V_142 ) -> V_336 =
( (struct V_132 * ) V_143 ) -> V_336 ;
}
}
return F_170 ( V_21 , V_142 ) ;
}
int F_171 ( struct V_72 * V_21 , struct V_124 * V_142 ,
struct V_124 * V_143 , int V_286 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( V_2 -> V_8 == V_82 ) {
V_6 = F_169 ( V_21 , V_142 , V_143 ) ;
if ( V_6 )
return V_6 ;
}
if ( ! F_4 ( V_2 , V_273 , V_157 ) )
return - V_70 ;
F_12 ( & V_2 -> V_20 ) ;
memcpy ( & V_21 -> V_23 . V_24 . V_143 , V_143 , F_138 ( V_143 ) ) ;
if ( F_73 ( V_143 ) )
V_6 = F_167 ( V_2 ) ;
else
V_6 = F_172 ( & V_337 , (struct V_124 * ) & V_21 -> V_23 . V_24 . V_142 ,
V_143 , & V_21 -> V_23 . V_24 . V_25 ,
V_286 , F_166 , V_2 ) ;
if ( V_6 )
goto V_49;
return 0 ;
V_49:
F_4 ( V_2 , V_157 , V_273 ) ;
F_37 ( V_2 ) ;
return V_6 ;
}
int F_173 ( struct V_72 * V_21 , int V_338 )
{
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
if ( V_2 -> V_8 == V_82 ) {
V_2 -> V_339 = V_338 ;
V_6 = 0 ;
} else {
V_6 = - V_70 ;
}
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
static void F_174 ( struct V_160 * V_161 ,
struct V_1 * V_2 )
{
struct V_129 * sin ;
sin = (struct V_129 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
sin -> V_137 = F_175 ( V_161 -> V_58 ) ;
V_2 -> V_161 = V_161 ;
F_176 ( & V_2 -> V_162 , & V_161 -> V_163 ) ;
}
static int F_177 ( struct V_340 * V_39 , struct V_1 * V_2 ,
unsigned short V_341 )
{
struct V_160 * V_161 ;
int V_58 , V_6 ;
V_161 = F_41 ( sizeof *V_161 , V_78 ) ;
if ( ! V_161 )
return - V_79 ;
do {
V_6 = F_178 ( V_39 , V_161 , V_341 , & V_58 ) ;
} while ( ( V_6 == - V_54 ) && F_179 ( V_39 , V_78 ) );
if ( V_6 )
goto V_312;
if ( V_58 != V_341 ) {
V_6 = - V_267 ;
goto V_313;
}
V_161 -> V_39 = V_39 ;
V_161 -> V_58 = ( unsigned short ) V_58 ;
F_174 ( V_161 , V_2 ) ;
return 0 ;
V_313:
F_93 ( V_39 , V_58 ) ;
V_312:
F_20 ( V_161 ) ;
return V_6 ;
}
static int F_180 ( struct V_340 * V_39 , struct V_1 * V_2 )
{
static unsigned int V_342 ;
int V_343 , V_344 , V_345 ;
unsigned int V_346 ;
F_181 ( & V_343 , & V_344 ) ;
V_345 = ( V_344 - V_343 ) + 1 ;
V_346 = F_182 () % V_345 + V_343 ;
V_347:
if ( V_342 != V_346 &&
! F_183 ( V_39 , ( unsigned short ) V_346 ) ) {
int V_6 = F_177 ( V_39 , V_2 , V_346 ) ;
if ( ! V_6 )
V_342 = V_346 ;
if ( V_6 != - V_267 )
return V_6 ;
}
if ( -- V_345 ) {
V_346 ++ ;
if ( ( V_346 < V_343 ) || ( V_346 > V_344 ) )
V_346 = V_343 ;
goto V_347;
}
return - V_267 ;
}
static int F_184 ( struct V_160 * V_161 ,
struct V_1 * V_2 , T_8 V_339 )
{
struct V_1 * V_348 ;
struct V_124 * V_24 , * V_349 ;
struct V_350 * V_162 ;
V_24 = (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
if ( F_73 ( V_24 ) && ! V_339 )
return - V_267 ;
F_185 (cur_id, node, &bind_list->owners, node) {
if ( V_2 == V_348 )
continue;
if ( ( V_348 -> V_8 == V_159 ) ||
! V_339 || ! V_348 -> V_339 ) {
V_349 = (struct V_124 * ) & V_348 -> V_21 . V_23 . V_24 . V_142 ;
if ( F_73 ( V_349 ) )
return - V_267 ;
if ( ! F_74 ( V_24 , V_349 ) )
return - V_351 ;
}
}
return 0 ;
}
static int F_186 ( struct V_340 * V_39 , struct V_1 * V_2 )
{
struct V_160 * V_161 ;
unsigned short V_341 ;
int V_6 ;
V_341 = F_187 ( F_76 ( (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ) ) ;
if ( V_341 < V_352 && ! F_188 ( V_353 ) )
return - V_354 ;
V_161 = F_183 ( V_39 , V_341 ) ;
if ( ! V_161 ) {
V_6 = F_177 ( V_39 , V_2 , V_341 ) ;
} else {
V_6 = F_184 ( V_161 , V_2 , V_2 -> V_339 ) ;
if ( ! V_6 )
F_174 ( V_161 , V_2 ) ;
}
return V_6 ;
}
static int F_189 ( struct V_1 * V_2 )
{
struct V_160 * V_161 = V_2 -> V_161 ;
int V_6 = 0 ;
F_22 ( & V_7 ) ;
if ( V_161 -> V_163 . V_355 -> V_156 )
V_6 = F_184 ( V_161 , V_2 , 0 ) ;
F_24 ( & V_7 ) ;
return V_6 ;
}
static int F_190 ( struct V_1 * V_2 )
{
struct V_340 * V_39 ;
int V_6 ;
switch ( V_2 -> V_21 . V_39 ) {
case V_140 :
V_39 = & V_356 ;
break;
case V_264 :
V_39 = & V_357 ;
break;
case V_40 :
V_39 = & V_358 ;
break;
case V_42 :
V_39 = & V_359 ;
break;
default:
return - V_360 ;
}
F_22 ( & V_7 ) ;
if ( F_77 ( (struct V_124 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ) )
V_6 = F_180 ( V_39 , V_2 ) ;
else
V_6 = F_186 ( V_39 , V_2 ) ;
F_24 ( & V_7 ) ;
return V_6 ;
}
static int F_191 ( struct V_55 * V_25 ,
struct V_124 * V_24 )
{
#if F_192 ( V_361 ) || F_192 ( V_362 )
struct V_132 * V_288 ;
if ( V_24 -> V_127 != V_247 )
return 0 ;
V_288 = (struct V_132 * ) V_24 ;
if ( ( F_193 ( & V_288 -> V_133 ) & V_363 ) &&
! V_288 -> V_336 )
return - V_70 ;
V_25 -> V_316 = V_288 -> V_336 ;
#endif
return 0 ;
}
int F_139 ( struct V_72 * V_21 , int V_272 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( V_2 -> V_8 == V_82 ) {
( (struct V_124 * ) & V_21 -> V_23 . V_24 . V_142 ) -> V_127 = V_128 ;
V_6 = F_170 ( V_21 , (struct V_124 * ) & V_21 -> V_23 . V_24 . V_142 ) ;
if ( V_6 )
return V_6 ;
}
if ( ! F_4 ( V_2 , V_273 , V_159 ) )
return - V_70 ;
if ( V_2 -> V_339 ) {
V_6 = F_189 ( V_2 ) ;
if ( V_6 )
goto V_49;
}
V_2 -> V_272 = V_272 ;
if ( V_21 -> V_22 ) {
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_67 :
V_6 = F_130 ( V_2 ) ;
if ( V_6 )
goto V_49;
break;
case V_121 :
V_6 = F_133 ( V_2 , V_272 ) ;
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
V_2 -> V_272 = 0 ;
F_4 ( V_2 , V_159 , V_273 ) ;
return V_6 ;
}
int F_170 ( struct V_72 * V_21 , struct V_124 * V_24 )
{
struct V_1 * V_2 ;
int V_6 ;
if ( V_24 -> V_127 != V_128 && V_24 -> V_127 != V_247 )
return - V_364 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_4 ( V_2 , V_82 , V_273 ) )
return - V_70 ;
V_6 = F_191 ( & V_21 -> V_23 . V_24 . V_25 , V_24 ) ;
if ( V_6 )
goto V_312;
if ( ! F_73 ( V_24 ) ) {
V_6 = F_111 ( V_24 , & V_21 -> V_23 . V_24 . V_25 ) ;
if ( V_6 )
goto V_312;
V_6 = F_32 ( V_2 ) ;
if ( V_6 )
goto V_312;
}
memcpy ( & V_21 -> V_23 . V_24 . V_142 , V_24 , F_138 ( V_24 ) ) ;
V_6 = F_190 ( V_2 ) ;
if ( V_6 )
goto V_313;
return 0 ;
V_313:
if ( V_2 -> V_19 )
F_21 ( V_2 ) ;
V_312:
F_4 ( V_2 , V_273 , V_82 ) ;
return V_6 ;
}
static int F_194 ( void * V_12 , enum V_75 V_39 ,
struct V_214 * V_23 )
{
struct V_11 * V_11 ;
struct V_16 * V_365 ;
if ( V_23 -> V_24 . V_142 . V_298 == V_128 ) {
struct V_129 * V_366 , * V_367 ;
V_366 = (struct V_129 * ) & V_23 -> V_24 . V_142 ;
V_367 = (struct V_129 * ) & V_23 -> V_24 . V_143 ;
switch ( V_39 ) {
case V_140 :
V_365 = V_12 ;
if ( F_8 ( V_365 -> V_15 ) != V_141 )
return - V_70 ;
F_10 ( V_365 , 4 ) ;
V_365 -> V_142 . V_149 . V_24 = V_366 -> V_130 . V_131 ;
V_365 -> V_143 . V_149 . V_24 = V_367 -> V_130 . V_131 ;
V_365 -> V_58 = V_366 -> V_137 ;
break;
default:
V_11 = V_12 ;
V_11 -> V_144 = V_145 ;
F_7 ( V_11 , 4 ) ;
V_11 -> V_142 . V_149 . V_24 = V_366 -> V_130 . V_131 ;
V_11 -> V_143 . V_149 . V_24 = V_367 -> V_130 . V_131 ;
V_11 -> V_58 = V_366 -> V_137 ;
break;
}
} else {
struct V_132 * V_368 , * V_369 ;
V_368 = (struct V_132 * ) & V_23 -> V_24 . V_142 ;
V_369 = (struct V_132 * ) & V_23 -> V_24 . V_143 ;
switch ( V_39 ) {
case V_140 :
V_365 = V_12 ;
if ( F_8 ( V_365 -> V_15 ) != V_141 )
return - V_70 ;
F_10 ( V_365 , 6 ) ;
V_365 -> V_142 . V_126 = V_368 -> V_133 ;
V_365 -> V_143 . V_126 = V_369 -> V_133 ;
V_365 -> V_58 = V_368 -> V_138 ;
break;
default:
V_11 = V_12 ;
V_11 -> V_144 = V_145 ;
F_7 ( V_11 , 6 ) ;
V_11 -> V_142 . V_126 = V_368 -> V_133 ;
V_11 -> V_143 . V_126 = V_369 -> V_133 ;
V_11 -> V_58 = V_368 -> V_138 ;
break;
}
}
return 0 ;
}
static int F_195 ( struct V_183 * V_71 ,
struct V_184 * V_185 )
{
struct V_1 * V_2 = V_71 -> V_74 ;
struct V_171 V_172 ;
struct V_370 * V_371 = & V_185 -> V_176 . V_372 ;
int V_6 = 0 ;
if ( F_38 ( V_2 , V_187 ) )
return 0 ;
memset ( & V_172 , 0 , sizeof V_172 ) ;
switch ( V_185 -> V_172 ) {
case V_373 :
V_172 . V_172 = V_191 ;
V_172 . V_192 = - V_193 ;
break;
case V_374 :
V_172 . V_176 . V_231 . V_175 = V_185 -> V_175 ;
V_172 . V_176 . V_231 . V_178 = V_375 ;
if ( V_371 -> V_192 != V_376 ) {
V_172 . V_172 = V_191 ;
V_172 . V_192 = V_185 -> V_176 . V_372 . V_192 ;
break;
}
V_6 = F_25 ( V_2 ) ;
if ( V_6 ) {
V_172 . V_172 = V_334 ;
V_172 . V_192 = - V_70 ;
break;
}
if ( V_2 -> V_38 != V_371 -> V_38 ) {
V_172 . V_172 = V_191 ;
V_172 . V_192 = - V_70 ;
break;
}
F_196 ( V_2 -> V_21 . V_22 , V_2 -> V_21 . V_44 ,
V_2 -> V_21 . V_23 . V_166 ,
& V_172 . V_176 . V_231 . V_377 ) ;
V_172 . V_176 . V_231 . V_104 = V_371 -> V_378 ;
V_172 . V_176 . V_231 . V_38 = V_371 -> V_38 ;
V_172 . V_172 = V_196 ;
V_172 . V_192 = 0 ;
break;
default:
F_106 ( V_212 L_1 ,
V_185 -> V_172 ) ;
goto V_68;
}
V_6 = V_2 -> V_21 . V_73 ( & V_2 -> V_21 , & V_172 ) ;
if ( V_6 ) {
V_2 -> V_71 . V_35 = NULL ;
F_5 ( V_2 , V_164 ) ;
F_24 ( & V_2 -> V_69 ) ;
F_87 ( & V_2 -> V_21 ) ;
return V_6 ;
}
V_68:
F_24 ( & V_2 -> V_69 ) ;
return V_6 ;
}
static int F_197 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_379 V_380 ;
struct V_214 * V_23 ;
int V_6 ;
V_380 . V_178 = sizeof( struct V_11 ) +
V_107 -> V_178 ;
V_380 . V_175 = F_41 ( V_380 . V_178 , V_381 ) ;
if ( ! V_380 . V_175 )
return - V_79 ;
if ( V_107 -> V_175 && V_107 -> V_178 )
memcpy ( ( void * ) V_380 . V_175 + sizeof( struct V_11 ) ,
V_107 -> V_175 , V_107 -> V_178 ) ;
V_23 = & V_2 -> V_21 . V_23 ;
V_6 = F_194 ( ( void * ) V_380 . V_175 , V_2 -> V_21 . V_39 , V_23 ) ;
if ( V_6 )
goto V_68;
V_2 -> V_71 . V_35 = F_131 ( V_2 -> V_21 . V_22 ,
F_195 , V_2 ) ;
if ( F_56 ( V_2 -> V_71 . V_35 ) ) {
V_6 = F_57 ( V_2 -> V_71 . V_35 ) ;
goto V_68;
}
V_380 . V_382 = V_23 -> V_166 ;
V_380 . V_291 = F_118 ( V_2 -> V_21 . V_39 ,
(struct V_124 * ) & V_23 -> V_24 . V_143 ) ;
V_380 . V_286 = 1 << ( V_383 - 8 ) ;
V_380 . V_384 = V_385 ;
V_6 = F_198 ( V_2 -> V_71 . V_35 , & V_380 ) ;
if ( V_6 ) {
F_97 ( V_2 -> V_71 . V_35 ) ;
V_2 -> V_71 . V_35 = NULL ;
}
V_68:
F_20 ( V_380 . V_175 ) ;
return V_6 ;
}
static int F_199 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_386 V_380 ;
struct V_214 * V_23 ;
void * V_175 ;
int V_225 , V_6 ;
memset ( & V_380 , 0 , sizeof V_380 ) ;
V_225 = F_80 ( V_2 -> V_21 . V_39 ) ;
V_380 . V_178 = V_225 + V_107 -> V_178 ;
V_175 = F_41 ( V_380 . V_178 , V_381 ) ;
if ( ! V_175 )
return - V_79 ;
if ( V_107 -> V_175 && V_107 -> V_178 )
memcpy ( V_175 + V_225 , V_107 -> V_175 ,
V_107 -> V_178 ) ;
V_2 -> V_71 . V_35 = F_131 ( V_2 -> V_21 . V_22 , F_105 ,
V_2 ) ;
if ( F_56 ( V_2 -> V_71 . V_35 ) ) {
V_6 = F_57 ( V_2 -> V_71 . V_35 ) ;
goto V_68;
}
V_23 = & V_2 -> V_21 . V_23 ;
V_6 = F_194 ( V_175 , V_2 -> V_21 . V_39 , V_23 ) ;
if ( V_6 )
goto V_68;
V_380 . V_175 = V_175 ;
V_380 . V_220 = & V_23 -> V_166 [ 0 ] ;
if ( V_23 -> V_217 == 2 )
V_380 . V_218 = & V_23 -> V_166 [ 1 ] ;
V_380 . V_291 = F_118 ( V_2 -> V_21 . V_39 ,
(struct V_124 * ) & V_23 -> V_24 . V_143 ) ;
V_380 . V_104 = V_2 -> V_104 ;
V_380 . V_77 = V_265 ;
V_380 . V_387 = V_2 -> V_86 ;
V_380 . V_109 = V_107 -> V_109 ;
V_380 . V_111 = V_107 -> V_111 ;
V_380 . V_180 = V_107 -> V_180 ;
V_380 . V_227 = V_107 -> V_227 ;
V_380 . V_181 = V_107 -> V_181 ;
V_380 . V_388 = V_383 ;
V_380 . V_389 = V_383 ;
V_380 . V_384 = V_385 ;
V_380 . V_105 = V_2 -> V_105 ? 1 : 0 ;
V_6 = F_200 ( V_2 -> V_71 . V_35 , & V_380 ) ;
V_68:
if ( V_6 && ! F_56 ( V_2 -> V_71 . V_35 ) ) {
F_97 ( V_2 -> V_71 . V_35 ) ;
V_2 -> V_71 . V_35 = NULL ;
}
F_20 ( V_175 ) ;
return V_6 ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_248 * V_71 ;
struct V_129 * sin ;
int V_6 ;
struct V_390 V_391 ;
V_71 = F_134 ( V_2 -> V_21 . V_22 , F_123 , V_2 ) ;
if ( F_56 ( V_71 ) ) {
V_6 = F_57 ( V_71 ) ;
goto V_68;
}
V_2 -> V_71 . V_122 = V_71 ;
sin = (struct V_129 * ) & V_2 -> V_21 . V_23 . V_24 . V_142 ;
V_71 -> V_254 = * sin ;
sin = (struct V_129 * ) & V_2 -> V_21 . V_23 . V_24 . V_143 ;
V_71 -> V_255 = * sin ;
V_6 = F_60 ( V_2 , V_107 ) ;
if ( V_6 )
goto V_68;
V_391 . V_392 = V_107 -> V_111 ;
V_391 . V_393 = V_107 -> V_109 ;
V_391 . V_175 = V_107 -> V_175 ;
V_391 . V_178 = V_107 -> V_178 ;
if ( V_2 -> V_21 . V_88 )
V_391 . V_378 = V_2 -> V_104 ;
else
V_391 . V_378 = V_107 -> V_104 ;
V_6 = F_202 ( V_71 , & V_391 ) ;
V_68:
if ( V_6 && ! F_56 ( V_71 ) ) {
F_98 ( V_71 ) ;
V_2 -> V_71 . V_122 = NULL ;
}
return V_6 ;
}
int F_203 ( struct V_72 * V_21 , struct V_106 * V_107 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_4 ( V_2 , V_310 , V_187 ) )
return - V_70 ;
if ( ! V_21 -> V_88 ) {
V_2 -> V_104 = V_107 -> V_104 ;
V_2 -> V_105 = V_107 -> V_105 ;
}
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_67 :
if ( V_21 -> V_77 == V_103 )
V_6 = F_197 ( V_2 , V_107 ) ;
else
V_6 = F_199 ( V_2 , V_107 ) ;
break;
case V_121 :
V_6 = F_201 ( V_2 , V_107 ) ;
break;
default:
V_6 = - V_123 ;
break;
}
if ( V_6 )
goto V_49;
return 0 ;
V_49:
F_4 ( V_2 , V_187 , V_310 ) ;
return V_6 ;
}
static int F_204 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_394 V_371 ;
int V_6 ;
V_6 = F_60 ( V_2 , V_107 ) ;
if ( V_6 )
goto V_68;
V_6 = F_61 ( V_2 , V_107 ) ;
if ( V_6 )
goto V_68;
memset ( & V_371 , 0 , sizeof V_371 ) ;
V_371 . V_104 = V_2 -> V_104 ;
V_371 . V_387 = V_2 -> V_86 ;
V_371 . V_175 = V_107 -> V_175 ;
V_371 . V_178 = V_107 -> V_178 ;
V_371 . V_109 = V_107 -> V_109 ;
V_371 . V_111 = V_107 -> V_111 ;
V_371 . V_395 = 0 ;
V_371 . V_180 = V_107 -> V_180 ;
V_371 . V_181 = V_107 -> V_181 ;
V_371 . V_105 = V_2 -> V_105 ? 1 : 0 ;
V_6 = F_205 ( V_2 -> V_71 . V_35 , & V_371 ) ;
V_68:
return V_6 ;
}
static int F_206 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_390 V_391 ;
int V_6 ;
V_6 = F_60 ( V_2 , V_107 ) ;
if ( V_6 )
return V_6 ;
V_391 . V_392 = V_107 -> V_111 ;
V_391 . V_393 = V_107 -> V_109 ;
V_391 . V_175 = V_107 -> V_175 ;
V_391 . V_178 = V_107 -> V_178 ;
if ( V_2 -> V_21 . V_88 ) {
V_391 . V_378 = V_2 -> V_104 ;
} else
V_391 . V_378 = V_107 -> V_104 ;
return F_207 ( V_2 -> V_71 . V_122 , & V_391 ) ;
}
static int F_208 ( struct V_1 * V_2 ,
enum V_396 V_192 ,
const void * V_175 , int V_178 )
{
struct V_397 V_371 ;
int V_6 ;
memset ( & V_371 , 0 , sizeof V_371 ) ;
V_371 . V_192 = V_192 ;
if ( V_192 == V_376 ) {
V_6 = F_25 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_371 . V_104 = V_2 -> V_104 ;
V_371 . V_38 = V_2 -> V_38 ;
}
V_371 . V_175 = V_175 ;
V_371 . V_178 = V_178 ;
return F_209 ( V_2 -> V_71 . V_35 , & V_371 ) ;
}
int F_210 ( struct V_72 * V_21 , struct V_106 * V_107 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
V_2 -> V_80 = F_43 ( V_81 ) ;
if ( ! F_1 ( V_2 , V_187 ) )
return - V_70 ;
if ( ! V_21 -> V_88 && V_107 ) {
V_2 -> V_104 = V_107 -> V_104 ;
V_2 -> V_105 = V_107 -> V_105 ;
}
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_67 :
if ( V_21 -> V_77 == V_103 )
V_6 = F_208 ( V_2 , V_376 ,
V_107 -> V_175 ,
V_107 -> V_178 ) ;
else if ( V_107 )
V_6 = F_204 ( V_2 , V_107 ) ;
else
V_6 = F_100 ( V_2 ) ;
break;
case V_121 :
V_6 = F_206 ( V_2 , V_107 ) ;
break;
default:
V_6 = - V_123 ;
break;
}
if ( V_6 )
goto V_167;
return 0 ;
V_167:
F_62 ( V_2 ) ;
F_211 ( V_21 , NULL , 0 ) ;
return V_6 ;
}
int F_212 ( struct V_72 * V_21 , enum V_398 V_172 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_39 ( V_2 ) )
return - V_70 ;
switch ( V_21 -> V_22 -> V_27 ) {
case V_399 :
V_6 = F_213 ( V_2 -> V_71 . V_35 , V_172 ) ;
break;
default:
V_6 = 0 ;
break;
}
return V_6 ;
}
int F_211 ( struct V_72 * V_21 , const void * V_175 ,
T_1 V_178 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_39 ( V_2 ) )
return - V_70 ;
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_67 :
if ( V_21 -> V_77 == V_103 )
V_6 = F_208 ( V_2 , V_400 ,
V_175 , V_178 ) ;
else
V_6 = F_102 ( V_2 -> V_71 . V_35 ,
V_168 , NULL ,
0 , V_175 , V_178 ) ;
break;
case V_121 :
V_6 = F_214 ( V_2 -> V_71 . V_122 ,
V_175 , V_178 ) ;
break;
default:
V_6 = - V_123 ;
break;
}
return V_6 ;
}
int F_215 ( struct V_72 * V_21 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_39 ( V_2 ) )
return - V_70 ;
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_67 :
V_6 = F_62 ( V_2 ) ;
if ( V_6 )
goto V_68;
if ( F_216 ( V_2 -> V_71 . V_35 , NULL , 0 ) )
F_217 ( V_2 -> V_71 . V_35 , NULL , 0 ) ;
break;
case V_121 :
V_6 = F_218 ( V_2 -> V_71 . V_122 , 0 ) ;
break;
default:
V_6 = - V_70 ;
break;
}
V_68:
return V_6 ;
}
static int F_219 ( int V_192 , struct V_401 * V_34 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 = V_34 -> V_74 ;
struct V_171 V_172 ;
int V_6 ;
V_2 = V_32 -> V_2 ;
if ( F_38 ( V_2 , V_273 ) &&
F_38 ( V_2 , V_283 ) )
return 0 ;
F_22 ( & V_2 -> V_83 ) ;
if ( ! V_192 && V_2 -> V_21 . V_88 )
V_192 = F_220 ( V_2 -> V_21 . V_88 , & V_34 -> V_37 . V_43 ,
V_34 -> V_37 . V_402 ) ;
F_24 ( & V_2 -> V_83 ) ;
memset ( & V_172 , 0 , sizeof V_172 ) ;
V_172 . V_192 = V_192 ;
V_172 . V_176 . V_231 . V_175 = V_32 -> V_74 ;
if ( ! V_192 ) {
V_172 . V_172 = V_403 ;
F_221 ( V_2 -> V_21 . V_22 ,
V_2 -> V_21 . V_44 , & V_34 -> V_37 ,
& V_172 . V_176 . V_231 . V_377 ) ;
V_172 . V_176 . V_231 . V_104 = 0xFFFFFF ;
V_172 . V_176 . V_231 . V_38 = F_28 ( V_34 -> V_37 . V_38 ) ;
} else
V_172 . V_172 = V_404 ;
V_6 = V_2 -> V_21 . V_73 ( & V_2 -> V_21 , & V_172 ) ;
if ( V_6 ) {
F_5 ( V_2 , V_164 ) ;
F_24 ( & V_2 -> V_69 ) ;
F_87 ( & V_2 -> V_21 ) ;
return 0 ;
}
F_24 ( & V_2 -> V_69 ) ;
return 0 ;
}
static void F_222 ( struct V_1 * V_2 ,
struct V_124 * V_24 , union V_46 * V_43 )
{
unsigned char V_405 [ V_406 ] ;
struct V_55 * V_25 = & V_2 -> V_21 . V_23 . V_24 . V_25 ;
struct V_129 * sin = (struct V_129 * ) V_24 ;
struct V_132 * V_288 = (struct V_132 * ) V_24 ;
if ( F_73 ( V_24 ) ) {
memset ( V_43 , 0 , sizeof *V_43 ) ;
} else if ( ( V_24 -> V_127 == V_247 ) &&
( ( F_28 ( V_288 -> V_133 . V_134 [ 0 ] ) & 0xFFF0FFFF ) ==
0xFF10A01B ) ) {
memcpy ( V_43 , & V_288 -> V_133 , sizeof *V_43 ) ;
} else if ( ( V_24 -> V_127 == V_247 ) ) {
F_223 ( & V_288 -> V_133 , V_25 -> V_407 , V_405 ) ;
if ( V_2 -> V_21 . V_39 == V_40 )
V_405 [ 7 ] = 0x01 ;
* V_43 = * (union V_46 * ) ( V_405 + 4 ) ;
} else {
F_224 ( sin -> V_130 . V_131 , V_25 -> V_407 , V_405 ) ;
if ( V_2 -> V_21 . V_39 == V_40 )
V_405 [ 7 ] = 0x01 ;
* V_43 = * (union V_46 * ) ( V_405 + 4 ) ;
}
}
static int F_225 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_36 V_37 ;
struct V_55 * V_25 = & V_2 -> V_21 . V_23 . V_24 . V_25 ;
T_7 V_287 ;
int V_6 ;
F_26 ( V_25 , & V_37 . V_43 ) ;
V_6 = F_27 ( V_2 -> V_21 . V_22 , V_2 -> V_21 . V_44 ,
& V_37 . V_43 , & V_37 ) ;
if ( V_6 )
return V_6 ;
F_222 ( V_2 , (struct V_124 * ) & V_32 -> V_24 , & V_37 . V_43 ) ;
if ( V_2 -> V_21 . V_39 == V_40 )
V_37 . V_38 = F_226 ( V_41 ) ;
F_145 ( V_25 , & V_37 . V_408 ) ;
V_37 . V_113 = F_147 ( F_64 ( V_25 ) ) ;
V_37 . V_409 = 1 ;
V_287 = V_410 | V_411 |
V_412 | V_413 |
V_414 | V_415 |
V_416 |
V_417 ;
if ( V_2 -> V_21 . V_39 == V_42 )
V_287 |= V_418 |
V_419 ;
V_32 -> V_34 . V_35 = F_227 ( & V_304 , V_2 -> V_21 . V_22 ,
V_2 -> V_21 . V_44 , & V_37 ,
V_287 , V_78 ,
F_219 , V_32 ) ;
if ( F_56 ( V_32 -> V_34 . V_35 ) )
return F_57 ( V_32 -> V_34 . V_35 ) ;
return 0 ;
}
static void F_228 ( struct V_305 * V_280 )
{
struct V_420 * V_421 = F_19 ( V_280 , struct V_420 , V_280 ) ;
struct V_31 * V_32 = V_421 -> V_32 ;
struct V_401 * V_422 = V_32 -> V_34 . V_35 ;
V_32 -> V_34 . V_35 -> V_74 = V_32 ;
F_219 ( 0 , V_422 ) ;
F_96 ( & V_32 -> V_33 , F_18 ) ;
F_20 ( V_421 ) ;
}
static void F_229 ( struct V_124 * V_24 , union V_46 * V_43 )
{
struct V_129 * sin = (struct V_129 * ) V_24 ;
struct V_132 * V_288 = (struct V_132 * ) V_24 ;
if ( F_73 ( V_24 ) ) {
memset ( V_43 , 0 , sizeof *V_43 ) ;
} else if ( V_24 -> V_127 == V_247 ) {
memcpy ( V_43 , & V_288 -> V_133 , sizeof *V_43 ) ;
} else {
V_43 -> V_423 [ 0 ] = 0xff ;
V_43 -> V_423 [ 1 ] = 0x0e ;
V_43 -> V_423 [ 2 ] = 0 ;
V_43 -> V_423 [ 3 ] = 0 ;
V_43 -> V_423 [ 4 ] = 0 ;
V_43 -> V_423 [ 5 ] = 0 ;
V_43 -> V_423 [ 6 ] = 0 ;
V_43 -> V_423 [ 7 ] = 0 ;
V_43 -> V_423 [ 8 ] = 0 ;
V_43 -> V_423 [ 9 ] = 0 ;
V_43 -> V_423 [ 10 ] = 0xff ;
V_43 -> V_423 [ 11 ] = 0xff ;
* ( T_6 * ) ( & V_43 -> V_423 [ 12 ] ) = sin -> V_130 . V_131 ;
}
}
static int F_230 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_420 * V_280 ;
struct V_55 * V_25 = & V_2 -> V_21 . V_23 . V_24 . V_25 ;
int V_49 ;
struct V_124 * V_24 = (struct V_124 * ) & V_32 -> V_24 ;
struct V_260 * V_314 = NULL ;
if ( F_68 ( (struct V_124 * ) & V_32 -> V_24 ) )
return - V_70 ;
V_280 = F_41 ( sizeof *V_280 , V_78 ) ;
if ( ! V_280 )
return - V_79 ;
V_32 -> V_34 . V_35 = F_41 ( sizeof( struct V_401 ) , V_78 ) ;
if ( ! V_32 -> V_34 . V_35 ) {
V_49 = - V_79 ;
goto V_424;
}
F_229 ( V_24 , & V_32 -> V_34 . V_35 -> V_37 . V_43 ) ;
V_32 -> V_34 . V_35 -> V_37 . V_113 = F_147 ( 0xffff ) ;
if ( V_2 -> V_21 . V_39 == V_40 )
V_32 -> V_34 . V_35 -> V_37 . V_38 = F_226 ( V_41 ) ;
if ( V_25 -> V_316 )
V_314 = F_157 ( & V_266 , V_25 -> V_316 ) ;
if ( ! V_314 ) {
V_49 = - V_57 ;
goto V_425;
}
V_32 -> V_34 . V_35 -> V_37 . V_324 = F_161 ( V_314 ) ;
V_32 -> V_34 . V_35 -> V_37 . V_318 = 1 ;
V_32 -> V_34 . V_35 -> V_37 . V_322 = F_160 ( V_314 -> V_322 ) ;
F_129 ( V_314 ) ;
if ( ! V_32 -> V_34 . V_35 -> V_37 . V_322 ) {
V_49 = - V_70 ;
goto V_425;
}
F_33 ( V_25 , & V_32 -> V_34 . V_35 -> V_37 . V_408 ) ;
V_280 -> V_21 = V_2 ;
V_280 -> V_32 = V_32 ;
F_152 ( & V_280 -> V_280 , F_228 ) ;
F_231 ( & V_32 -> V_33 ) ;
F_143 ( V_285 , & V_280 -> V_280 ) ;
return 0 ;
V_425:
F_20 ( V_32 -> V_34 . V_35 ) ;
V_424:
F_20 ( V_280 ) ;
return V_49 ;
}
int F_232 ( struct V_72 * V_21 , struct V_124 * V_24 ,
void * V_74 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
int V_6 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
if ( ! F_1 ( V_2 , V_273 ) &&
! F_1 ( V_2 , V_283 ) )
return - V_70 ;
V_32 = F_108 ( sizeof *V_32 , V_78 ) ;
if ( ! V_32 )
return - V_79 ;
memcpy ( & V_32 -> V_24 , V_24 , F_138 ( V_24 ) ) ;
V_32 -> V_74 = V_74 ;
V_32 -> V_2 = V_2 ;
F_233 ( & V_2 -> V_7 ) ;
F_234 ( & V_32 -> V_28 , & V_2 -> V_85 ) ;
F_235 ( & V_2 -> V_7 ) ;
switch ( F_13 ( V_21 -> V_22 -> V_27 ) ) {
case V_67 :
switch ( F_36 ( V_21 -> V_22 , V_21 -> V_44 ) ) {
case V_63 :
V_6 = F_225 ( V_2 , V_32 ) ;
break;
case V_64 :
F_236 ( & V_32 -> V_33 ) ;
V_6 = F_230 ( V_2 , V_32 ) ;
break;
default:
V_6 = - V_70 ;
}
break;
default:
V_6 = - V_123 ;
break;
}
if ( V_6 ) {
F_237 ( & V_2 -> V_7 ) ;
F_23 ( & V_32 -> V_28 ) ;
F_238 ( & V_2 -> V_7 ) ;
F_20 ( V_32 ) ;
}
return V_6 ;
}
void F_239 ( struct V_72 * V_21 , struct V_124 * V_24 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
V_2 = F_19 ( V_21 , struct V_1 , V_21 ) ;
F_237 ( & V_2 -> V_7 ) ;
F_35 (mc, &id_priv->mc_list, list) {
if ( ! memcmp ( & V_32 -> V_24 , V_24 , F_138 ( V_24 ) ) ) {
F_23 ( & V_32 -> V_28 ) ;
F_238 ( & V_2 -> V_7 ) ;
if ( V_21 -> V_88 )
F_240 ( V_21 -> V_88 ,
& V_32 -> V_34 . V_35 -> V_37 . V_43 ,
V_32 -> V_34 . V_35 -> V_37 . V_402 ) ;
if ( F_13 ( V_2 -> V_19 -> V_22 -> V_27 ) == V_67 ) {
switch ( F_36 ( V_21 -> V_22 , V_21 -> V_44 ) ) {
case V_63 :
F_95 ( V_32 -> V_34 . V_35 ) ;
F_20 ( V_32 ) ;
break;
case V_64 :
F_96 ( & V_32 -> V_33 , F_18 ) ;
break;
default:
break;
}
}
return;
}
}
F_238 ( & V_2 -> V_7 ) ;
}
static int F_241 ( struct V_260 * V_314 , struct V_1 * V_2 )
{
struct V_55 * V_25 ;
struct V_308 * V_280 ;
V_25 = & V_2 -> V_21 . V_23 . V_24 . V_25 ;
if ( ( V_25 -> V_316 == V_314 -> V_426 ) &&
memcmp ( V_25 -> V_65 , V_314 -> V_25 , V_314 -> V_427 ) ) {
F_106 ( V_428 L_4 ,
V_314 -> V_275 , & V_2 -> V_21 ) ;
V_280 = F_41 ( sizeof *V_280 , V_78 ) ;
if ( ! V_280 )
return - V_79 ;
F_152 ( & V_280 -> V_280 , F_150 ) ;
V_280 -> V_21 = V_2 ;
V_280 -> V_172 . V_172 = V_429 ;
F_12 ( & V_2 -> V_20 ) ;
F_143 ( V_285 , & V_280 -> V_280 ) ;
}
return 0 ;
}
static int F_242 ( struct V_430 * V_431 , unsigned long V_172 ,
void * V_432 )
{
struct V_260 * V_314 = (struct V_260 * ) V_432 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
int V_6 = V_433 ;
if ( F_243 ( V_314 ) != & V_266 )
return V_433 ;
if ( V_172 != V_434 )
return V_433 ;
if ( ! ( V_314 -> V_5 & V_435 ) || ! ( V_314 -> V_436 & V_437 ) )
return V_433 ;
F_22 ( & V_7 ) ;
F_35 (cma_dev, &dev_list, list)
F_35 (id_priv, &cma_dev->id_list, list) {
V_6 = F_241 ( V_314 , V_2 ) ;
if ( V_6 )
goto V_68;
}
V_68:
F_24 ( & V_7 ) ;
return V_6 ;
}
static void F_244 ( struct V_45 * V_22 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 ;
V_19 = F_108 ( sizeof *V_19 , V_78 ) ;
if ( ! V_19 )
return;
V_19 -> V_22 = V_22 ;
F_46 ( & V_19 -> V_4 ) ;
F_47 ( & V_19 -> V_20 , 1 ) ;
F_48 ( & V_19 -> V_29 ) ;
F_245 ( V_22 , & V_438 , V_19 ) ;
F_22 ( & V_7 ) ;
F_14 ( & V_19 -> V_28 , & V_330 ) ;
F_35 (id_priv, &listen_any_list, list)
F_137 ( V_2 , V_19 ) ;
F_24 ( & V_7 ) ;
}
static int F_246 ( struct V_1 * V_2 )
{
struct V_171 V_172 ;
enum V_3 V_8 ;
int V_6 = 0 ;
V_8 = F_5 ( V_2 , V_309 ) ;
if ( V_8 == V_164 )
return 0 ;
F_88 ( V_2 , V_8 ) ;
F_22 ( & V_2 -> V_69 ) ;
if ( ! F_1 ( V_2 , V_309 ) )
goto V_68;
memset ( & V_172 , 0 , sizeof V_172 ) ;
V_172 . V_172 = V_439 ;
V_6 = V_2 -> V_21 . V_73 ( & V_2 -> V_21 , & V_172 ) ;
V_68:
F_24 ( & V_2 -> V_69 ) ;
return V_6 ;
}
static void F_247 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_6 ;
F_22 ( & V_7 ) ;
while ( ! F_84 ( & V_19 -> V_29 ) ) {
V_2 = F_85 ( V_19 -> V_29 . V_156 ,
struct V_1 , V_28 ) ;
F_23 ( & V_2 -> V_84 ) ;
F_86 ( & V_2 -> V_28 ) ;
F_12 ( & V_2 -> V_20 ) ;
F_24 ( & V_7 ) ;
V_6 = V_2 -> V_165 ? 1 : F_246 ( V_2 ) ;
F_37 ( V_2 ) ;
if ( V_6 )
F_87 ( & V_2 -> V_21 ) ;
F_22 ( & V_7 ) ;
}
F_24 ( & V_7 ) ;
F_15 ( V_19 ) ;
F_99 ( & V_19 -> V_4 ) ;
}
static void F_248 ( struct V_45 * V_22 )
{
struct V_18 * V_19 ;
V_19 = F_249 ( V_22 , & V_438 ) ;
if ( ! V_19 )
return;
F_22 ( & V_7 ) ;
F_23 ( & V_19 -> V_28 ) ;
F_24 ( & V_7 ) ;
F_247 ( V_19 ) ;
F_20 ( V_19 ) ;
}
static int F_250 ( struct V_440 * V_441 , struct V_442 * V_443 )
{
struct V_444 * V_445 ;
struct V_446 * V_447 ;
struct V_1 * V_2 ;
struct V_72 * V_21 = NULL ;
struct V_18 * V_19 ;
int V_448 = 0 , V_449 = 0 ;
F_22 ( & V_7 ) ;
F_35 (cma_dev, &dev_list, list) {
if ( V_448 < V_443 -> args [ 0 ] ) {
V_448 ++ ;
continue;
}
V_449 = 0 ;
F_35 (id_priv, &cma_dev->id_list, list) {
if ( V_449 < V_443 -> args [ 1 ] ) {
V_449 ++ ;
continue;
}
V_447 = F_251 ( V_441 , & V_445 , V_443 -> V_445 -> V_450 ,
sizeof *V_447 , V_451 ,
V_452 ) ;
if ( ! V_447 )
goto V_68;
memset ( V_447 , 0 , sizeof *V_447 ) ;
V_21 = & V_2 -> V_21 ;
V_447 -> V_27 = V_21 -> V_23 . V_24 . V_25 . V_61 ;
V_447 -> V_44 = V_21 -> V_44 ;
V_447 -> V_316 =
V_21 -> V_23 . V_24 . V_25 . V_316 ;
if ( V_21 -> V_23 . V_24 . V_142 . V_298 == V_128 ) {
if ( F_252 ( V_441 , V_445 ,
sizeof( struct V_129 ) ,
& V_21 -> V_23 . V_24 . V_142 ,
V_453 ) ) {
goto V_68;
}
if ( F_252 ( V_441 , V_445 ,
sizeof( struct V_129 ) ,
& V_21 -> V_23 . V_24 . V_143 ,
V_454 ) ) {
goto V_68;
}
} else if ( V_21 -> V_23 . V_24 . V_142 . V_298 == V_247 ) {
if ( F_252 ( V_441 , V_445 ,
sizeof( struct V_132 ) ,
& V_21 -> V_23 . V_24 . V_142 ,
V_453 ) ) {
goto V_68;
}
if ( F_252 ( V_441 , V_445 ,
sizeof( struct V_132 ) ,
& V_21 -> V_23 . V_24 . V_143 ,
V_454 ) ) {
goto V_68;
}
}
V_447 -> V_455 = V_2 -> V_80 ;
V_447 -> V_456 = V_21 -> V_39 ;
V_447 -> V_457 = V_2 -> V_8 ;
V_447 -> V_104 = V_2 -> V_104 ;
V_447 -> V_77 = V_21 -> V_77 ;
V_449 ++ ;
}
V_443 -> args [ 1 ] = 0 ;
V_448 ++ ;
}
V_68:
F_24 ( & V_7 ) ;
V_443 -> args [ 0 ] = V_448 ;
V_443 -> args [ 1 ] = V_449 ;
return V_441 -> V_458 ;
}
static int T_9 F_253 ( void )
{
int V_6 ;
V_285 = F_254 ( L_5 ) ;
if ( ! V_285 )
return - V_79 ;
F_255 ( & V_304 ) ;
F_256 ( & V_337 ) ;
F_257 ( & V_459 ) ;
V_6 = F_258 ( & V_438 ) ;
if ( V_6 )
goto V_49;
if ( F_259 ( V_451 , V_460 , V_461 ) )
F_106 ( V_274 L_6 ) ;
return 0 ;
V_49:
F_260 ( & V_459 ) ;
F_261 ( & V_337 ) ;
F_262 ( & V_304 ) ;
F_263 ( V_285 ) ;
return V_6 ;
}
static void T_10 F_264 ( void )
{
F_265 ( V_451 ) ;
F_266 ( & V_438 ) ;
F_260 ( & V_459 ) ;
F_261 ( & V_337 ) ;
F_262 ( & V_304 ) ;
F_263 ( V_285 ) ;
F_267 ( & V_356 ) ;
F_267 ( & V_357 ) ;
F_267 ( & V_358 ) ;
F_267 ( & V_359 ) ;
}
