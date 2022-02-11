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
static int F_11 ( struct V_24 * V_25 , enum V_26 V_27 )
{
unsigned long V_28 ;
int V_29 ;
F_12 ( & V_25 -> V_30 , V_28 ) ;
V_29 = ( V_25 -> V_31 == V_27 ) ;
F_13 ( & V_25 -> V_30 , V_28 ) ;
return V_29 ;
}
static int F_14 ( struct V_24 * V_25 ,
enum V_26 V_27 , enum V_26 V_32 )
{
unsigned long V_28 ;
int V_29 ;
F_12 ( & V_25 -> V_30 , V_28 ) ;
if ( ( V_29 = ( V_25 -> V_31 == V_27 ) ) )
V_25 -> V_31 = V_32 ;
F_13 ( & V_25 -> V_30 , V_28 ) ;
return V_29 ;
}
static enum V_26 F_15 ( struct V_24 * V_25 ,
enum V_26 V_32 )
{
unsigned long V_28 ;
enum V_26 V_33 ;
F_12 ( & V_25 -> V_30 , V_28 ) ;
V_33 = V_25 -> V_31 ;
V_25 -> V_31 = V_32 ;
F_13 ( & V_25 -> V_30 , V_28 ) ;
return V_33 ;
}
static inline T_3 F_16 ( const struct V_34 * V_35 )
{
return V_35 -> V_36 >> 4 ;
}
static inline void F_17 ( struct V_34 * V_35 , T_3 V_37 )
{
V_35 -> V_36 = ( V_37 << 4 ) | ( V_35 -> V_36 & 0xF ) ;
}
static void F_18 ( struct V_24 * V_25 ,
struct V_38 * V_39 )
{
F_19 ( & V_39 -> V_40 ) ;
V_25 -> V_39 = V_39 ;
V_25 -> V_41 . V_42 = V_39 -> V_42 ;
V_25 -> V_41 . V_43 . V_44 . V_45 . V_46 =
F_20 ( V_39 -> V_42 -> V_47 ) ;
F_21 ( & V_25 -> V_48 , & V_39 -> V_49 ) ;
}
static inline void F_22 ( struct V_38 * V_39 )
{
if ( F_23 ( & V_39 -> V_40 ) )
F_24 ( & V_39 -> V_27 ) ;
}
static inline void F_25 ( struct V_50 * V_50 )
{
struct V_51 * V_52 = F_26 ( V_50 , struct V_51 , V_53 ) ;
F_27 ( V_52 -> V_54 . V_55 ) ;
F_27 ( V_52 ) ;
}
static void F_28 ( struct V_24 * V_25 )
{
F_29 ( & V_30 ) ;
F_30 ( & V_25 -> V_48 ) ;
F_22 ( V_25 -> V_39 ) ;
V_25 -> V_39 = NULL ;
F_31 ( & V_30 ) ;
}
static inline struct V_56 * F_32 ( struct V_24 * V_25 )
{
return (struct V_56 * ) & V_25 -> V_41 . V_43 . V_44 . V_57 ;
}
static inline struct V_56 * F_33 ( struct V_24 * V_25 )
{
return (struct V_56 * ) & V_25 -> V_41 . V_43 . V_44 . V_58 ;
}
static inline unsigned short F_34 ( struct V_24 * V_25 )
{
return V_25 -> V_41 . V_43 . V_44 . V_57 . V_59 ;
}
static int F_35 ( struct V_24 * V_25 , T_4 V_60 )
{
struct V_61 V_62 ;
int V_29 = 0 ;
if ( V_25 -> V_60 ) {
if ( V_60 && V_25 -> V_60 != V_60 )
return - V_63 ;
return 0 ;
}
if ( V_60 ) {
V_25 -> V_60 = V_60 ;
return 0 ;
}
switch ( V_25 -> V_41 . V_10 ) {
case V_14 :
case V_18 :
V_25 -> V_60 = V_64 ;
break;
case V_16 :
F_36 ( & V_25 -> V_41 . V_43 . V_44 . V_45 , & V_62 . V_65 ) ;
V_29 = F_37 ( V_25 -> V_41 . V_42 ,
V_25 -> V_41 . V_66 , & V_62 . V_65 ,
& V_62 ) ;
if ( ! V_29 )
V_25 -> V_60 = F_38 ( V_62 . V_60 ) ;
break;
default:
break;
}
return V_29 ;
}
static void F_39 ( struct V_67 * V_68 , struct V_69 * V_45 )
{
V_45 -> V_70 = V_71 ;
F_40 ( V_45 , (union V_72 * ) & V_68 -> V_73 ) ;
F_41 ( V_45 , F_42 ( V_68 -> V_74 ) ) ;
}
static int F_43 ( struct V_56 * V_44 , struct V_69 * V_45 )
{
int V_29 ;
if ( V_44 -> V_75 != V_76 ) {
V_29 = F_44 ( V_44 , V_45 , NULL ) ;
} else {
F_39 ( (struct V_67 * ) V_44 , V_45 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static inline int F_45 ( struct V_77 * V_42 , T_3 V_78 ,
union V_72 * V_79 , int V_70 ,
int V_80 )
{
int V_29 = - V_81 ;
struct V_82 * V_83 = NULL ;
if ( ( V_70 == V_71 ) && ! F_46 ( V_42 , V_78 ) )
return V_29 ;
if ( ( V_70 != V_71 ) && F_46 ( V_42 , V_78 ) )
return V_29 ;
if ( V_70 == V_84 )
V_83 = F_47 ( & V_85 , V_80 ) ;
V_29 = F_48 ( V_42 , V_79 , V_78 , V_83 , NULL ) ;
if ( V_83 )
F_49 ( V_83 ) ;
return V_29 ;
}
static int F_50 ( struct V_24 * V_25 ,
struct V_24 * V_86 )
{
struct V_69 * V_45 = & V_25 -> V_41 . V_43 . V_44 . V_45 ;
struct V_38 * V_39 ;
union V_72 V_79 , V_87 , * V_88 ;
int V_29 = - V_81 ;
T_3 V_78 ;
if ( V_45 -> V_70 != V_71 &&
V_25 -> V_41 . V_10 == V_16 )
return - V_63 ;
F_29 ( & V_30 ) ;
F_51 ( (struct V_56 * ) & V_25 -> V_41 . V_43 . V_44 . V_57 ,
& V_87 ) ;
memcpy ( & V_79 , V_45 -> V_89 +
F_52 ( V_45 ) , sizeof V_79 ) ;
if ( V_86 ) {
V_39 = V_86 -> V_39 ;
V_78 = V_86 -> V_41 . V_66 ;
V_88 = F_53 ( V_39 -> V_42 , V_78 ) ?
& V_87 : & V_79 ;
V_29 = F_45 ( V_39 -> V_42 , V_78 , V_88 ,
V_45 -> V_70 ,
V_45 -> V_90 ) ;
if ( ! V_29 ) {
V_25 -> V_41 . V_66 = V_78 ;
goto V_91;
}
}
F_54 (cma_dev, &dev_list, list) {
for ( V_78 = 1 ; V_78 <= V_39 -> V_42 -> V_92 ; ++ V_78 ) {
if ( V_86 &&
V_86 -> V_39 == V_39 &&
V_86 -> V_41 . V_66 == V_78 )
continue;
V_88 = F_53 ( V_39 -> V_42 , V_78 ) ?
& V_87 : & V_79 ;
V_29 = F_45 ( V_39 -> V_42 , V_78 , V_88 ,
V_45 -> V_70 ,
V_45 -> V_90 ) ;
if ( ! V_29 ) {
V_25 -> V_41 . V_66 = V_78 ;
goto V_91;
}
}
}
V_91:
if ( ! V_29 )
F_18 ( V_25 , V_39 ) ;
F_31 ( & V_30 ) ;
return V_29 ;
}
static int F_55 ( struct V_24 * V_25 )
{
struct V_38 * V_39 , * V_93 ;
struct V_67 * V_44 ;
union V_72 V_79 , V_94 , * V_95 ;
T_5 V_96 , V_3 ;
T_3 V_97 ;
int V_98 ;
V_39 = NULL ;
V_44 = (struct V_67 * ) F_33 ( V_25 ) ;
V_95 = (union V_72 * ) & V_44 -> V_73 ;
V_96 = F_42 ( V_44 -> V_74 ) ;
F_54 (cur_dev, &dev_list, list) {
for ( V_97 = 1 ; V_97 <= V_93 -> V_42 -> V_92 ; ++ V_97 ) {
if ( ! F_56 ( V_93 -> V_42 , V_97 ) )
continue;
if ( F_57 ( V_93 -> V_42 , V_97 , V_96 , & V_3 ) )
continue;
for ( V_98 = 0 ; ! F_58 ( V_93 -> V_42 , V_97 , V_98 ,
& V_79 , NULL ) ;
V_98 ++ ) {
if ( ! memcmp ( & V_79 , V_95 , sizeof( V_79 ) ) ) {
V_39 = V_93 ;
V_94 = V_79 ;
V_25 -> V_41 . V_66 = V_97 ;
goto V_99;
}
if ( ! V_39 && ( V_79 . V_100 . V_101 ==
V_95 -> V_100 . V_101 ) ) {
V_39 = V_93 ;
V_94 = V_79 ;
V_25 -> V_41 . V_66 = V_97 ;
}
}
}
}
if ( ! V_39 )
return - V_81 ;
V_99:
F_18 ( V_25 , V_39 ) ;
V_44 = (struct V_67 * ) F_32 ( V_25 ) ;
memcpy ( & V_44 -> V_73 , & V_94 , sizeof V_94 ) ;
F_39 ( V_44 , & V_25 -> V_41 . V_43 . V_44 . V_45 ) ;
return 0 ;
}
static void F_59 ( struct V_24 * V_25 )
{
if ( F_23 ( & V_25 -> V_40 ) )
F_24 ( & V_25 -> V_27 ) ;
}
static int F_60 ( struct V_24 * V_25 ,
enum V_26 V_31 )
{
F_29 ( & V_25 -> V_102 ) ;
if ( V_25 -> V_31 != V_31 ) {
F_31 ( & V_25 -> V_102 ) ;
return - V_63 ;
}
return 0 ;
}
struct V_103 * F_61 ( struct V_6 * V_6 ,
T_6 V_104 ,
void * V_105 , enum V_9 V_10 ,
enum V_106 V_107 )
{
struct V_24 * V_25 ;
V_25 = F_62 ( sizeof *V_25 , V_23 ) ;
if ( ! V_25 )
return F_63 ( - V_108 ) ;
V_25 -> V_109 = F_64 ( V_110 ) ;
V_25 -> V_31 = V_111 ;
V_25 -> V_41 . V_105 = V_105 ;
V_25 -> V_41 . V_104 = V_104 ;
V_25 -> V_41 . V_10 = V_10 ;
V_25 -> V_41 . V_107 = V_107 ;
F_65 ( & V_25 -> V_30 ) ;
F_66 ( & V_25 -> V_112 ) ;
F_67 ( & V_25 -> V_27 ) ;
F_68 ( & V_25 -> V_40 , 1 ) ;
F_66 ( & V_25 -> V_102 ) ;
F_69 ( & V_25 -> V_113 ) ;
F_69 ( & V_25 -> V_114 ) ;
F_70 ( & V_25 -> V_115 , sizeof V_25 -> V_115 ) ;
V_25 -> V_41 . V_43 . V_44 . V_45 . V_6 = F_71 ( V_6 ) ;
return & V_25 -> V_41 ;
}
static int F_72 ( struct V_24 * V_25 , struct V_116 * V_117 )
{
struct V_118 V_119 ;
int V_120 , V_29 ;
V_119 . V_121 = V_122 ;
V_29 = F_73 ( & V_25 -> V_41 , & V_119 , & V_120 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_74 ( V_117 , & V_119 , V_120 ) ;
if ( V_29 )
return V_29 ;
V_119 . V_121 = V_123 ;
V_29 = F_74 ( V_117 , & V_119 , V_124 ) ;
if ( V_29 )
return V_29 ;
V_119 . V_121 = V_125 ;
V_119 . V_126 = 0 ;
V_29 = F_74 ( V_117 , & V_119 , V_124 | V_127 ) ;
return V_29 ;
}
static int F_75 ( struct V_24 * V_25 , struct V_116 * V_117 )
{
struct V_118 V_119 ;
int V_120 , V_29 ;
V_119 . V_121 = V_122 ;
V_29 = F_73 ( & V_25 -> V_41 , & V_119 , & V_120 ) ;
if ( V_29 )
return V_29 ;
return F_74 ( V_117 , & V_119 , V_120 ) ;
}
int F_76 ( struct V_103 * V_41 , struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_24 * V_25 ;
struct V_116 * V_117 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( V_41 -> V_42 != V_129 -> V_42 )
return - V_63 ;
V_117 = F_77 ( V_129 , V_131 ) ;
if ( F_78 ( V_117 ) )
return F_79 ( V_117 ) ;
if ( V_41 -> V_107 == V_132 )
V_29 = F_72 ( V_25 , V_117 ) ;
else
V_29 = F_75 ( V_25 , V_117 ) ;
if ( V_29 )
goto V_133;
V_41 -> V_117 = V_117 ;
V_25 -> V_134 = V_117 -> V_134 ;
V_25 -> V_135 = ( V_117 -> V_135 != NULL ) ;
return 0 ;
V_133:
F_80 ( V_117 ) ;
return V_29 ;
}
void F_81 ( struct V_103 * V_41 )
{
struct V_24 * V_25 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
F_29 ( & V_25 -> V_112 ) ;
F_80 ( V_25 -> V_41 . V_117 ) ;
V_25 -> V_41 . V_117 = NULL ;
F_31 ( & V_25 -> V_112 ) ;
}
static int F_82 ( struct V_24 * V_25 ,
struct V_136 * V_137 )
{
struct V_118 V_119 ;
int V_120 , V_29 ;
union V_72 V_94 ;
F_29 ( & V_25 -> V_112 ) ;
if ( ! V_25 -> V_41 . V_117 ) {
V_29 = 0 ;
goto V_91;
}
V_119 . V_121 = V_122 ;
V_29 = F_73 ( & V_25 -> V_41 , & V_119 , & V_120 ) ;
if ( V_29 )
goto V_91;
V_29 = F_74 ( V_25 -> V_41 . V_117 , & V_119 , V_120 ) ;
if ( V_29 )
goto V_91;
V_119 . V_121 = V_123 ;
V_29 = F_73 ( & V_25 -> V_41 , & V_119 , & V_120 ) ;
if ( V_29 )
goto V_91;
V_29 = F_83 ( V_25 -> V_41 . V_42 , V_25 -> V_41 . V_66 ,
V_119 . V_138 . V_139 . V_140 , & V_94 , NULL ) ;
if ( V_29 )
goto V_91;
F_84 ( V_25 -> V_39 -> V_42 != V_25 -> V_41 . V_42 ) ;
if ( V_137 )
V_119 . V_141 = V_137 -> V_142 ;
V_29 = F_74 ( V_25 -> V_41 . V_117 , & V_119 , V_120 ) ;
V_91:
F_31 ( & V_25 -> V_112 ) ;
return V_29 ;
}
static int F_85 ( struct V_24 * V_25 ,
struct V_136 * V_137 )
{
struct V_118 V_119 ;
int V_120 , V_29 ;
F_29 ( & V_25 -> V_112 ) ;
if ( ! V_25 -> V_41 . V_117 ) {
V_29 = 0 ;
goto V_91;
}
V_119 . V_121 = V_125 ;
V_29 = F_73 ( & V_25 -> V_41 , & V_119 , & V_120 ) ;
if ( V_29 )
goto V_91;
if ( V_137 )
V_119 . V_143 = V_137 -> V_144 ;
V_29 = F_74 ( V_25 -> V_41 . V_117 , & V_119 , V_120 ) ;
V_91:
F_31 ( & V_25 -> V_112 ) ;
return V_29 ;
}
static int F_86 ( struct V_24 * V_25 )
{
struct V_118 V_119 ;
int V_29 ;
F_29 ( & V_25 -> V_112 ) ;
if ( ! V_25 -> V_41 . V_117 ) {
V_29 = 0 ;
goto V_91;
}
V_119 . V_121 = V_145 ;
V_29 = F_74 ( V_25 -> V_41 . V_117 , & V_119 , V_124 ) ;
V_91:
F_31 ( & V_25 -> V_112 ) ;
return V_29 ;
}
static int F_87 ( struct V_24 * V_25 ,
struct V_118 * V_119 , int * V_120 )
{
struct V_69 * V_45 = & V_25 -> V_41 . V_43 . V_44 . V_45 ;
int V_29 ;
T_5 V_96 ;
if ( F_88 ( V_25 -> V_41 . V_42 , V_25 -> V_41 . V_66 ) )
V_96 = 0xffff ;
else
V_96 = F_89 ( V_45 ) ;
V_29 = F_57 ( V_25 -> V_41 . V_42 , V_25 -> V_41 . V_66 ,
V_96 , & V_119 -> V_146 ) ;
if ( V_29 )
return V_29 ;
V_119 -> V_66 = V_25 -> V_41 . V_66 ;
* V_120 = V_124 | V_147 | V_148 ;
if ( V_25 -> V_41 . V_107 == V_132 ) {
V_29 = F_35 ( V_25 , 0 ) ;
if ( V_29 )
return V_29 ;
V_119 -> V_60 = V_25 -> V_60 ;
* V_120 |= V_149 ;
} else {
V_119 -> V_150 = 0 ;
* V_120 |= V_151 ;
}
return 0 ;
}
int F_73 ( struct V_103 * V_41 , struct V_118 * V_119 ,
int * V_120 )
{
struct V_24 * V_25 ;
int V_29 = 0 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( F_90 ( V_41 -> V_42 , V_41 -> V_66 ) ) {
if ( ! V_25 -> V_152 . V_55 || ( V_25 -> V_41 . V_107 == V_132 ) )
V_29 = F_87 ( V_25 , V_119 , V_120 ) ;
else
V_29 = F_91 ( V_25 -> V_152 . V_55 , V_119 ,
V_120 ) ;
if ( V_119 -> V_121 == V_123 )
V_119 -> V_153 = V_25 -> V_115 ;
} else if ( F_92 ( V_41 -> V_42 , V_41 -> V_66 ) ) {
if ( ! V_25 -> V_152 . V_154 ) {
V_119 -> V_150 = 0 ;
* V_120 = V_124 | V_151 ;
} else
V_29 = F_93 ( V_25 -> V_152 . V_154 , V_119 ,
V_120 ) ;
} else
V_29 = - V_155 ;
return V_29 ;
}
static inline int F_94 ( struct V_56 * V_44 )
{
switch ( V_44 -> V_75 ) {
case V_156 :
return F_95 ( ( (struct V_157 * ) V_44 ) -> V_158 . V_159 ) ;
case V_160 :
return F_96 ( & ( (struct V_161 * ) V_44 ) -> V_162 ) ;
case V_76 :
return F_97 ( & ( (struct V_67 * ) V_44 ) -> V_73 ) ;
default:
return 0 ;
}
}
static inline int F_98 ( struct V_56 * V_44 )
{
switch ( V_44 -> V_75 ) {
case V_156 :
return F_99 ( ( (struct V_157 * ) V_44 ) -> V_158 . V_159 ) ;
case V_160 :
return F_100 ( & ( (struct V_161 * ) V_44 ) -> V_162 ) ;
case V_76 :
return F_101 ( & ( (struct V_67 * ) V_44 ) -> V_73 ) ;
default:
return 0 ;
}
}
static inline int F_102 ( struct V_56 * V_44 )
{
return F_94 ( V_44 ) || F_98 ( V_44 ) ;
}
static int F_103 ( struct V_56 * V_163 , struct V_56 * V_164 )
{
if ( V_163 -> V_75 != V_164 -> V_75 )
return - 1 ;
switch ( V_163 -> V_75 ) {
case V_156 :
return ( (struct V_157 * ) V_163 ) -> V_158 . V_159 !=
( (struct V_157 * ) V_164 ) -> V_158 . V_159 ;
case V_160 :
return F_104 ( & ( (struct V_161 * ) V_163 ) -> V_162 ,
& ( (struct V_161 * ) V_164 ) -> V_162 ) ;
default:
return F_105 ( & ( (struct V_67 * ) V_163 ) -> V_73 ,
& ( (struct V_67 * ) V_164 ) -> V_73 ) ;
}
}
static T_7 F_106 ( struct V_56 * V_44 )
{
struct V_67 * V_68 ;
switch ( V_44 -> V_75 ) {
case V_156 :
return ( (struct V_157 * ) V_44 ) -> V_165 ;
case V_160 :
return ( (struct V_161 * ) V_44 ) -> V_166 ;
case V_76 :
V_68 = (struct V_67 * ) V_44 ;
return F_107 ( ( T_5 ) ( F_108 ( V_68 -> V_167 ) &
F_108 ( V_68 -> V_168 ) ) ) ;
default:
return 0 ;
}
}
static inline int F_109 ( struct V_56 * V_44 )
{
return ! F_106 ( V_44 ) ;
}
static void F_110 ( struct V_56 * V_57 ,
struct V_56 * V_58 ,
struct V_103 * V_169 ,
struct V_170 * V_171 )
{
struct V_67 * V_172 , * V_55 ;
V_172 = (struct V_67 * ) & V_169 -> V_43 . V_44 . V_57 ;
if ( V_57 ) {
V_55 = (struct V_67 * ) V_57 ;
V_55 -> V_173 = V_76 ;
if ( V_171 ) {
V_55 -> V_74 = V_171 -> V_96 ;
V_55 -> V_174 = V_171 -> V_175 ;
memcpy ( & V_55 -> V_73 , & V_171 -> V_94 , 16 ) ;
V_55 -> V_167 = V_171 -> V_176 ;
V_55 -> V_177 = 0 ;
} else {
V_55 -> V_74 = V_172 -> V_74 ;
V_55 -> V_174 = V_172 -> V_174 ;
V_55 -> V_73 = V_172 -> V_73 ;
V_55 -> V_167 = V_172 -> V_167 ;
V_55 -> V_177 = V_172 -> V_177 ;
}
V_55 -> V_168 = F_111 ( 0xffffffffffffffffULL ) ;
}
if ( V_58 ) {
V_55 = (struct V_67 * ) V_58 ;
V_55 -> V_173 = V_76 ;
if ( V_171 ) {
V_55 -> V_74 = V_171 -> V_96 ;
V_55 -> V_174 = V_171 -> V_175 ;
memcpy ( & V_55 -> V_73 , & V_171 -> V_95 , 16 ) ;
}
}
}
static void F_112 ( struct V_56 * V_57 ,
struct V_56 * V_58 ,
struct V_34 * V_35 ,
T_7 V_178 )
{
struct V_157 * V_179 ;
if ( V_57 ) {
V_179 = (struct V_157 * ) V_57 ;
V_179 -> V_180 = V_156 ;
V_179 -> V_158 . V_159 = V_35 -> V_58 . V_179 . V_44 ;
V_179 -> V_165 = V_178 ;
}
if ( V_58 ) {
V_179 = (struct V_157 * ) V_58 ;
V_179 -> V_180 = V_156 ;
V_179 -> V_158 . V_159 = V_35 -> V_57 . V_179 . V_44 ;
V_179 -> V_165 = V_35 -> V_78 ;
}
}
static void F_113 ( struct V_56 * V_57 ,
struct V_56 * V_58 ,
struct V_34 * V_35 ,
T_7 V_178 )
{
struct V_161 * V_181 ;
if ( V_57 ) {
V_181 = (struct V_161 * ) V_57 ;
V_181 -> V_182 = V_160 ;
V_181 -> V_162 = V_35 -> V_58 . V_181 ;
V_181 -> V_166 = V_178 ;
}
if ( V_58 ) {
V_181 = (struct V_161 * ) V_58 ;
V_181 -> V_182 = V_160 ;
V_181 -> V_162 = V_35 -> V_57 . V_181 ;
V_181 -> V_166 = V_35 -> V_78 ;
}
}
static T_5 F_114 ( T_8 V_176 )
{
return ( T_5 ) F_108 ( V_176 ) ;
}
static int F_115 ( struct V_56 * V_57 ,
struct V_56 * V_58 ,
struct V_183 * V_184 ,
T_8 V_176 )
{
struct V_34 * V_35 ;
T_7 V_78 ;
V_35 = V_184 -> V_185 ;
if ( V_35 -> V_186 != V_187 )
return - V_63 ;
V_78 = F_107 ( F_114 ( V_176 ) ) ;
switch ( F_16 ( V_35 ) ) {
case 4 :
F_112 ( V_57 , V_58 , V_35 , V_78 ) ;
break;
case 6 :
F_113 ( V_57 , V_58 , V_35 , V_78 ) ;
break;
default:
return - V_188 ;
}
return 0 ;
}
static int F_116 ( struct V_56 * V_57 ,
struct V_56 * V_58 ,
struct V_103 * V_169 ,
struct V_183 * V_184 ,
T_9 V_75 , T_8 V_176 )
{
if ( V_75 == V_76 ) {
if ( V_184 -> V_2 == V_189 )
F_110 ( V_57 , V_58 , V_169 ,
V_184 -> V_190 . V_191 . V_192 ) ;
else if ( V_184 -> V_2 == V_193 )
F_110 ( V_57 , V_58 , V_169 , NULL ) ;
return 0 ;
}
return F_115 ( V_57 , V_58 , V_184 , V_176 ) ;
}
static int F_117 ( const struct V_183 * V_184 ,
struct V_194 * V_195 )
{
const struct V_196 * V_197 =
& V_184 -> V_190 . V_191 ;
const struct V_198 * V_199 =
& V_184 -> V_190 . V_200 ;
switch ( V_184 -> V_2 ) {
case V_189 :
V_195 -> V_42 = V_197 -> V_169 -> V_42 ;
V_195 -> V_78 = V_197 -> V_78 ;
memcpy ( & V_195 -> V_201 , & V_197 -> V_192 -> V_94 ,
sizeof( V_195 -> V_201 ) ) ;
V_195 -> V_202 = true ;
V_195 -> V_176 = V_197 -> V_192 -> V_176 ;
V_195 -> V_96 = F_118 ( V_197 -> V_192 -> V_96 ) ;
break;
case V_193 :
V_195 -> V_42 = V_199 -> V_169 -> V_42 ;
V_195 -> V_78 = V_199 -> V_78 ;
V_195 -> V_202 = false ;
V_195 -> V_176 = V_199 -> V_176 ;
V_195 -> V_96 = V_199 -> V_96 ;
break;
default:
return - V_63 ;
}
return 0 ;
}
static bool F_119 ( struct V_82 * V_203 ,
const struct V_157 * V_58 ,
const struct V_157 * V_57 )
{
T_10 V_204 = V_58 -> V_158 . V_159 ,
V_205 = V_57 -> V_158 . V_159 ;
struct V_206 V_207 ;
struct V_208 V_209 ;
int V_133 ;
bool V_29 ;
if ( F_120 ( V_205 ) || F_121 ( V_205 ) ||
F_121 ( V_204 ) || F_95 ( V_205 ) ||
F_95 ( V_204 ) || F_99 ( V_204 ) ||
F_99 ( V_205 ) )
return false ;
memset ( & V_209 , 0 , sizeof( V_209 ) ) ;
V_209 . V_210 = V_203 -> V_211 ;
V_209 . V_204 = V_204 ;
V_209 . V_205 = V_205 ;
F_122 () ;
V_133 = F_123 ( F_124 ( V_203 ) , & V_209 , & V_207 , 0 ) ;
V_29 = V_133 == 0 && F_125 ( V_207 ) == V_203 ;
F_126 () ;
return V_29 ;
}
static bool F_127 ( struct V_82 * V_203 ,
const struct V_161 * V_58 ,
const struct V_161 * V_57 )
{
#if F_128 ( V_212 )
const int V_213 = F_129 ( & V_58 -> V_162 ) &
V_214 ;
struct V_215 * V_216 = F_130 ( F_124 ( V_203 ) , & V_58 -> V_162 ,
& V_57 -> V_162 , V_203 -> V_211 ,
V_213 ) ;
bool V_29 ;
if ( ! V_216 )
return false ;
V_29 = V_216 -> V_217 -> V_218 == V_203 ;
F_131 ( V_216 ) ;
return V_29 ;
#else
return false ;
#endif
}
static bool F_132 ( struct V_82 * V_203 ,
const struct V_56 * V_204 ,
const struct V_56 * V_205 )
{
const struct V_157 * V_219 = ( const struct V_157 * ) V_204 ;
const struct V_157 * V_220 = ( const struct V_157 * ) V_205 ;
const struct V_161 * V_221 = ( const struct V_161 * ) V_204 ;
const struct V_161 * V_222 = ( const struct V_161 * ) V_205 ;
switch ( V_204 -> V_75 ) {
case V_156 :
return V_205 -> V_75 == V_156 &&
F_119 ( V_203 , V_219 , V_220 ) ;
case V_160 :
return V_205 -> V_75 == V_160 &&
F_127 ( V_203 , V_221 , V_222 ) ;
default:
return false ;
}
}
static struct V_82 * F_133 ( struct V_183 * V_184 ,
const struct V_194 * V_195 )
{
struct V_223 V_224 , V_225 ;
struct V_56 * V_226 = (struct V_56 * ) & V_224 ,
* V_57 = (struct V_56 * ) & V_225 ;
struct V_82 * V_203 ;
const union V_72 * V_79 = V_195 -> V_202 ? & V_195 -> V_201 : NULL ;
int V_133 ;
V_133 = F_115 ( V_226 , V_57 , V_184 ,
V_195 -> V_176 ) ;
if ( V_133 )
return F_63 ( V_133 ) ;
V_203 = F_134 ( V_195 -> V_42 , V_195 -> V_78 , V_195 -> V_96 ,
V_79 , V_226 ) ;
if ( ! V_203 )
return F_63 ( - V_81 ) ;
if ( ! F_132 ( V_203 , V_226 , V_57 ) ) {
F_49 ( V_203 ) ;
return F_63 ( - V_227 ) ;
}
return V_203 ;
}
static enum V_9 F_135 ( T_8 V_176 )
{
return ( F_108 ( V_176 ) >> 16 ) & 0xffff ;
}
static bool F_136 ( struct V_24 * V_25 ,
const struct V_34 * V_35 )
{
struct V_56 * V_44 = F_32 ( V_25 ) ;
T_10 V_228 ;
struct V_229 V_230 ;
if ( F_102 ( V_44 ) && ! V_25 -> V_231 )
return true ;
switch ( V_44 -> V_75 ) {
case V_156 :
V_228 = ( (struct V_157 * ) V_44 ) -> V_158 . V_159 ;
if ( F_16 ( V_35 ) != 4 )
return false ;
if ( ! F_102 ( V_44 ) &&
V_35 -> V_58 . V_179 . V_44 != V_228 )
return false ;
break;
case V_160 :
V_230 = ( (struct V_161 * ) V_44 ) -> V_162 ;
if ( F_16 ( V_35 ) != 6 )
return false ;
if ( ! F_102 ( V_44 ) &&
memcmp ( & V_35 -> V_58 . V_181 , & V_230 , sizeof( V_230 ) ) )
return false ;
break;
case V_76 :
return true ;
default:
return false ;
}
return true ;
}
static bool F_137 ( struct V_77 * V_42 , int V_66 )
{
enum V_232 V_233 = F_138 ( V_42 , V_66 ) ;
enum V_234 V_46 =
F_20 ( V_42 -> V_47 ) ;
return V_233 == V_235 && V_46 == V_236 ;
}
static bool F_139 ( const struct V_103 * V_41 )
{
struct V_77 * V_42 = V_41 -> V_42 ;
const int V_66 = V_41 -> V_66 ? : F_140 ( V_42 ) ;
return F_137 ( V_42 , V_66 ) ;
}
static bool F_141 ( const struct V_103 * V_41 ,
const struct V_82 * V_203 ,
T_3 V_66 )
{
const struct V_237 * V_44 = & V_41 -> V_43 . V_44 ;
if ( ! V_203 )
return ( ! V_41 -> V_66 || V_41 -> V_66 == V_66 ) &&
( V_44 -> V_57 . V_59 == V_76 ||
F_137 ( V_41 -> V_42 , V_66 ) ) ;
return ! V_44 -> V_45 . V_90 ||
( F_142 ( F_124 ( V_203 ) , V_44 -> V_45 . V_6 ) &&
V_44 -> V_45 . V_90 == V_203 -> V_211 ) ;
}
static struct V_24 * F_143 (
const struct V_20 * V_21 ,
const struct V_238 * V_152 ,
const struct V_183 * V_184 ,
const struct V_194 * V_195 ,
const struct V_82 * V_203 )
{
struct V_24 * V_25 , * V_239 ;
if ( ! V_21 )
return F_63 ( - V_63 ) ;
F_144 (id_priv, &bind_list->owners, node) {
if ( F_136 ( V_25 , V_184 -> V_185 ) ) {
if ( V_25 -> V_41 . V_42 == V_152 -> V_42 &&
F_141 ( & V_25 -> V_41 , V_203 , V_195 -> V_78 ) )
return V_25 ;
F_54 (id_priv_dev,
&id_priv->listen_list,
listen_list) {
if ( V_239 -> V_41 . V_42 == V_152 -> V_42 &&
F_141 ( & V_239 -> V_41 , V_203 , V_195 -> V_78 ) )
return V_239 ;
}
}
}
return F_63 ( - V_63 ) ;
}
static struct V_24 * F_145 ( struct V_238 * V_152 ,
struct V_183 * V_184 ,
struct V_82 * * V_203 )
{
struct V_194 V_195 ;
struct V_20 * V_21 ;
struct V_24 * V_25 ;
int V_133 ;
V_133 = F_117 ( V_184 , & V_195 ) ;
if ( V_133 )
return F_63 ( V_133 ) ;
* V_203 = F_133 ( V_184 , & V_195 ) ;
if ( F_78 ( * V_203 ) ) {
if ( F_79 ( * V_203 ) == - V_188 ) {
* V_203 = NULL ;
} else if ( F_137 ( V_195 . V_42 , V_195 . V_78 ) ) {
* V_203 = NULL ;
} else {
return F_146 ( * V_203 ) ;
}
}
V_21 = F_7 ( * V_203 ? F_124 ( * V_203 ) : & V_85 ,
F_135 ( V_195 . V_176 ) ,
F_114 ( V_195 . V_176 ) ) ;
V_25 = F_143 ( V_21 , V_152 , V_184 , & V_195 , * V_203 ) ;
if ( F_78 ( V_25 ) && * V_203 ) {
F_49 ( * V_203 ) ;
* V_203 = NULL ;
}
return V_25 ;
}
static inline int F_147 ( struct V_24 * V_25 )
{
return F_34 ( V_25 ) == V_76 ? 0 : sizeof( struct V_34 ) ;
}
static void F_148 ( struct V_24 * V_25 )
{
if ( F_149 ( V_25 -> V_41 . V_42 , V_25 -> V_41 . V_66 ) ) {
if ( V_25 -> V_240 )
F_150 ( V_25 -> V_241 , V_25 -> V_240 ) ;
}
}
static void F_151 ( struct V_24 * V_25 )
{
struct V_24 * V_242 ;
F_29 ( & V_30 ) ;
F_30 ( & V_25 -> V_48 ) ;
while ( ! F_152 ( & V_25 -> V_113 ) ) {
V_242 = F_153 ( V_25 -> V_113 . V_243 ,
struct V_24 , V_113 ) ;
F_154 ( & V_242 -> V_48 ) ;
F_30 ( & V_242 -> V_113 ) ;
F_31 ( & V_30 ) ;
F_155 ( & V_242 -> V_41 ) ;
F_29 ( & V_30 ) ;
}
F_31 ( & V_30 ) ;
}
static void F_156 ( struct V_24 * V_25 ,
enum V_26 V_31 )
{
switch ( V_31 ) {
case V_244 :
F_157 ( & V_25 -> V_41 . V_43 . V_44 . V_45 ) ;
break;
case V_245 :
F_148 ( V_25 ) ;
break;
case V_246 :
if ( F_102 ( F_32 ( V_25 ) ) && ! V_25 -> V_39 )
F_151 ( V_25 ) ;
break;
default:
break;
}
}
static void F_158 ( struct V_24 * V_25 )
{
struct V_20 * V_21 = V_25 -> V_21 ;
struct V_6 * V_6 = V_25 -> V_41 . V_43 . V_44 . V_45 . V_6 ;
if ( ! V_21 )
return;
F_29 ( & V_30 ) ;
F_159 ( & V_25 -> V_247 ) ;
if ( F_160 ( & V_21 -> V_248 ) ) {
F_9 ( V_6 , V_21 -> V_10 , V_21 -> V_78 ) ;
F_27 ( V_21 ) ;
}
F_31 ( & V_30 ) ;
}
static void F_161 ( struct V_24 * V_25 )
{
struct V_51 * V_52 ;
while ( ! F_152 ( & V_25 -> V_114 ) ) {
V_52 = F_26 ( V_25 -> V_114 . V_243 ,
struct V_51 , V_48 ) ;
F_30 ( & V_52 -> V_48 ) ;
if ( F_162 ( V_25 -> V_39 -> V_42 ,
V_25 -> V_41 . V_66 ) ) {
F_163 ( V_52 -> V_54 . V_55 ) ;
F_27 ( V_52 ) ;
} else
F_164 ( & V_52 -> V_53 , F_25 ) ;
}
}
void F_155 ( struct V_103 * V_41 )
{
struct V_24 * V_25 ;
enum V_26 V_31 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
V_31 = F_15 ( V_25 , V_249 ) ;
F_156 ( V_25 , V_31 ) ;
F_29 ( & V_25 -> V_102 ) ;
F_31 ( & V_25 -> V_102 ) ;
if ( V_25 -> V_39 ) {
if ( F_90 ( V_25 -> V_41 . V_42 , 1 ) ) {
if ( V_25 -> V_152 . V_55 )
F_165 ( V_25 -> V_152 . V_55 ) ;
} else if ( F_92 ( V_25 -> V_41 . V_42 , 1 ) ) {
if ( V_25 -> V_152 . V_154 )
F_166 ( V_25 -> V_152 . V_154 ) ;
}
F_161 ( V_25 ) ;
F_28 ( V_25 ) ;
}
F_158 ( V_25 ) ;
F_59 ( V_25 ) ;
F_167 ( & V_25 -> V_27 ) ;
if ( V_25 -> V_250 )
F_59 ( V_25 -> V_41 . V_105 ) ;
F_27 ( V_25 -> V_41 . V_43 . V_251 ) ;
F_168 ( V_25 -> V_41 . V_43 . V_44 . V_45 . V_6 ) ;
F_27 ( V_25 ) ;
}
static int F_169 ( struct V_24 * V_25 )
{
int V_29 ;
V_29 = F_82 ( V_25 , NULL ) ;
if ( V_29 )
goto V_252;
V_29 = F_85 ( V_25 , NULL ) ;
if ( V_29 )
goto V_252;
V_29 = F_170 ( V_25 -> V_152 . V_55 , NULL , 0 ) ;
if ( V_29 )
goto V_252;
return 0 ;
V_252:
F_86 ( V_25 ) ;
F_171 ( V_25 -> V_152 . V_55 , V_253 ,
NULL , 0 , NULL , 0 ) ;
return V_29 ;
}
static void F_172 ( struct V_254 * V_2 ,
struct V_255 * V_256 ,
void * V_185 )
{
V_2 -> V_190 . V_257 . V_185 = V_185 ;
V_2 -> V_190 . V_257 . V_258 = V_259 ;
V_2 -> V_190 . V_257 . V_142 = V_256 -> V_142 ;
V_2 -> V_190 . V_257 . V_144 = V_256 -> V_144 ;
V_2 -> V_190 . V_257 . V_260 = V_256 -> V_260 ;
V_2 -> V_190 . V_257 . V_261 = V_256 -> V_261 ;
V_2 -> V_190 . V_257 . V_135 = V_256 -> V_135 ;
V_2 -> V_190 . V_257 . V_134 = V_256 -> V_262 ;
}
static int F_173 ( struct V_238 * V_152 , struct V_183 * V_184 )
{
struct V_24 * V_25 = V_152 -> V_105 ;
struct V_254 V_2 ;
int V_29 = 0 ;
if ( ( V_184 -> V_2 != V_263 &&
F_60 ( V_25 , V_264 ) ) ||
( V_184 -> V_2 == V_263 &&
F_60 ( V_25 , V_265 ) ) )
return 0 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_184 -> V_2 ) {
case V_266 :
case V_267 :
V_2 . V_2 = V_268 ;
V_2 . V_269 = - V_270 ;
break;
case V_271 :
if ( V_25 -> V_41 . V_117 ) {
V_2 . V_269 = F_169 ( V_25 ) ;
V_2 . V_2 = V_2 . V_269 ? V_272 :
V_273 ;
} else {
V_2 . V_2 = V_274 ;
}
F_172 ( & V_2 , & V_184 -> V_190 . V_275 ,
V_184 -> V_185 ) ;
break;
case V_276 :
case V_277 :
V_2 . V_2 = V_273 ;
break;
case V_278 :
V_2 . V_269 = - V_270 ;
case V_279 :
case V_280 :
if ( ! F_14 ( V_25 , V_264 ,
V_265 ) )
goto V_91;
V_2 . V_2 = V_281 ;
break;
case V_263 :
V_2 . V_2 = V_282 ;
break;
case V_283 :
goto V_91;
case V_284 :
F_86 ( V_25 ) ;
V_2 . V_269 = V_184 -> V_190 . V_285 . V_286 ;
V_2 . V_2 = V_287 ;
V_2 . V_190 . V_257 . V_185 = V_184 -> V_185 ;
V_2 . V_190 . V_257 . V_258 = V_288 ;
break;
default:
F_174 ( V_289 L_2 ,
V_184 -> V_2 ) ;
goto V_91;
}
V_29 = V_25 -> V_41 . V_104 ( & V_25 -> V_41 , & V_2 ) ;
if ( V_29 ) {
V_25 -> V_152 . V_55 = NULL ;
F_15 ( V_25 , V_249 ) ;
F_31 ( & V_25 -> V_102 ) ;
F_155 ( & V_25 -> V_41 ) ;
return V_29 ;
}
V_91:
F_31 ( & V_25 -> V_102 ) ;
return V_29 ;
}
static struct V_24 * F_175 ( struct V_103 * V_169 ,
struct V_183 * V_184 ,
struct V_82 * V_203 )
{
struct V_24 * V_25 ;
struct V_103 * V_41 ;
struct V_290 * V_216 ;
const T_9 V_59 = V_169 -> V_43 . V_44 . V_57 . V_59 ;
const T_8 V_176 =
V_184 -> V_190 . V_191 . V_192 -> V_176 ;
int V_29 ;
V_41 = F_61 ( V_169 -> V_43 . V_44 . V_45 . V_6 ,
V_169 -> V_104 , V_169 -> V_105 ,
V_169 -> V_10 , V_184 -> V_190 . V_191 . V_107 ) ;
if ( F_78 ( V_41 ) )
return NULL ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( F_116 ( (struct V_56 * ) & V_41 -> V_43 . V_44 . V_57 ,
(struct V_56 * ) & V_41 -> V_43 . V_44 . V_58 ,
V_169 , V_184 , V_59 , V_176 ) )
goto V_133;
V_216 = & V_41 -> V_43 ;
V_216 -> V_291 = V_184 -> V_190 . V_191 . V_292 ? 2 : 1 ;
V_216 -> V_251 = F_176 ( sizeof * V_216 -> V_251 * V_216 -> V_291 ,
V_23 ) ;
if ( ! V_216 -> V_251 )
goto V_133;
V_216 -> V_251 [ 0 ] = * V_184 -> V_190 . V_191 . V_192 ;
if ( V_216 -> V_291 == 2 )
V_216 -> V_251 [ 1 ] = * V_184 -> V_190 . V_191 . V_292 ;
if ( V_203 ) {
V_29 = F_177 ( & V_216 -> V_44 . V_45 , V_203 , NULL ) ;
if ( V_29 )
goto V_133;
} else {
if ( ! F_139 ( V_169 ) &&
F_102 ( F_32 ( V_25 ) ) ) {
V_216 -> V_44 . V_45 . V_70 = V_71 ;
F_40 ( & V_216 -> V_44 . V_45 , & V_216 -> V_251 [ 0 ] . V_94 ) ;
F_41 ( & V_216 -> V_44 . V_45 , F_118 ( V_216 -> V_251 [ 0 ] . V_96 ) ) ;
} else if ( ! F_102 ( F_32 ( V_25 ) ) ) {
V_29 = F_43 ( F_32 ( V_25 ) , & V_216 -> V_44 . V_45 ) ;
if ( V_29 )
goto V_133;
}
}
F_178 ( & V_216 -> V_44 . V_45 , & V_216 -> V_251 [ 0 ] . V_95 ) ;
V_25 -> V_31 = V_264 ;
return V_25 ;
V_133:
F_155 ( V_41 ) ;
return NULL ;
}
static struct V_24 * F_179 ( struct V_103 * V_169 ,
struct V_183 * V_184 ,
struct V_82 * V_203 )
{
struct V_24 * V_25 ;
struct V_103 * V_41 ;
const T_9 V_59 = V_169 -> V_43 . V_44 . V_57 . V_59 ;
struct V_6 * V_6 = V_169 -> V_43 . V_44 . V_45 . V_6 ;
int V_29 ;
V_41 = F_61 ( V_6 , V_169 -> V_104 , V_169 -> V_105 ,
V_169 -> V_10 , V_132 ) ;
if ( F_78 ( V_41 ) )
return NULL ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( F_116 ( (struct V_56 * ) & V_41 -> V_43 . V_44 . V_57 ,
(struct V_56 * ) & V_41 -> V_43 . V_44 . V_58 ,
V_169 , V_184 , V_59 ,
V_184 -> V_190 . V_200 . V_176 ) )
goto V_133;
if ( V_203 ) {
V_29 = F_177 ( & V_41 -> V_43 . V_44 . V_45 , V_203 , NULL ) ;
if ( V_29 )
goto V_133;
} else {
if ( ! F_102 ( F_32 ( V_25 ) ) ) {
V_29 = F_43 ( F_32 ( V_25 ) ,
& V_41 -> V_43 . V_44 . V_45 ) ;
if ( V_29 )
goto V_133;
}
}
V_25 -> V_31 = V_264 ;
return V_25 ;
V_133:
F_155 ( V_41 ) ;
return NULL ;
}
static void F_180 ( struct V_254 * V_2 ,
struct V_196 * V_293 ,
void * V_185 , int V_294 )
{
V_2 -> V_190 . V_257 . V_185 = V_185 + V_294 ;
V_2 -> V_190 . V_257 . V_258 = V_295 - V_294 ;
V_2 -> V_190 . V_257 . V_142 = V_293 -> V_142 ;
V_2 -> V_190 . V_257 . V_144 = V_293 -> V_144 ;
V_2 -> V_190 . V_257 . V_260 = V_293 -> V_260 ;
V_2 -> V_190 . V_257 . V_296 = V_293 -> V_296 ;
V_2 -> V_190 . V_257 . V_261 = V_293 -> V_261 ;
V_2 -> V_190 . V_257 . V_135 = V_293 -> V_135 ;
V_2 -> V_190 . V_257 . V_134 = V_293 -> V_262 ;
}
static int F_181 ( struct V_103 * V_41 , struct V_183 * V_184 )
{
return ( ( ( V_184 -> V_2 == V_189 ) &&
( V_184 -> V_190 . V_191 . V_107 == V_41 -> V_107 ) ) ||
( ( V_184 -> V_2 == V_193 ) &&
( V_41 -> V_107 == V_132 ) ) ||
( ! V_41 -> V_107 ) ) ;
}
static int F_182 ( struct V_238 * V_152 , struct V_183 * V_184 )
{
struct V_24 * V_169 , * V_297 ;
struct V_254 V_2 ;
struct V_82 * V_203 ;
int V_294 , V_29 ;
V_169 = F_145 ( V_152 , V_184 , & V_203 ) ;
if ( F_78 ( V_169 ) )
return F_79 ( V_169 ) ;
if ( ! F_181 ( & V_169 -> V_41 , V_184 ) ) {
V_29 = - V_63 ;
goto V_298;
}
if ( F_60 ( V_169 , V_246 ) ) {
V_29 = - V_299 ;
goto V_298;
}
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_294 = F_147 ( V_169 ) ;
V_2 . V_2 = V_300 ;
if ( V_184 -> V_2 == V_193 ) {
V_297 = F_179 ( & V_169 -> V_41 , V_184 , V_203 ) ;
V_2 . V_190 . V_301 . V_185 = V_184 -> V_185 + V_294 ;
V_2 . V_190 . V_301 . V_258 =
V_302 - V_294 ;
} else {
V_297 = F_175 ( & V_169 -> V_41 , V_184 , V_203 ) ;
F_180 ( & V_2 , & V_184 -> V_190 . V_191 ,
V_184 -> V_185 , V_294 ) ;
}
if ( ! V_297 ) {
V_29 = - V_108 ;
goto V_303;
}
F_183 ( & V_297 -> V_102 , V_304 ) ;
V_29 = F_50 ( V_297 , V_169 ) ;
if ( V_29 )
goto V_305;
V_297 -> V_152 . V_55 = V_152 ;
V_152 -> V_105 = V_297 ;
V_152 -> V_306 = F_173 ;
F_19 ( & V_297 -> V_40 ) ;
V_29 = V_297 -> V_41 . V_104 ( & V_297 -> V_41 , & V_2 ) ;
if ( V_29 )
goto V_307;
F_29 ( & V_30 ) ;
if ( F_11 ( V_297 , V_264 ) &&
( V_297 -> V_41 . V_107 != V_132 ) )
F_184 ( V_152 , V_308 , NULL , 0 ) ;
F_31 ( & V_30 ) ;
F_31 ( & V_297 -> V_102 ) ;
F_31 ( & V_169 -> V_102 ) ;
F_59 ( V_297 ) ;
if ( V_203 )
F_49 ( V_203 ) ;
return 0 ;
V_307:
F_59 ( V_297 ) ;
V_297 -> V_152 . V_55 = NULL ;
V_305:
F_15 ( V_297 , V_249 ) ;
F_31 ( & V_297 -> V_102 ) ;
V_303:
F_31 ( & V_169 -> V_102 ) ;
if ( V_297 )
F_155 ( & V_297 -> V_41 ) ;
V_298:
if ( V_203 )
F_49 ( V_203 ) ;
return V_29 ;
}
T_8 F_185 ( struct V_103 * V_41 , struct V_56 * V_44 )
{
if ( V_44 -> V_75 == V_76 )
return ( (struct V_67 * ) V_44 ) -> V_167 ;
return F_111 ( ( ( V_309 ) V_41 -> V_10 << 16 ) + F_118 ( F_106 ( V_44 ) ) ) ;
}
static int F_186 ( struct V_310 * V_311 , struct V_312 * V_313 )
{
struct V_24 * V_25 = V_311 -> V_105 ;
struct V_254 V_2 ;
int V_29 = 0 ;
struct V_56 * V_314 = (struct V_56 * ) & V_313 -> V_315 ;
struct V_56 * V_316 = (struct V_56 * ) & V_313 -> V_317 ;
if ( F_60 ( V_25 , V_264 ) )
return 0 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_313 -> V_2 ) {
case V_318 :
V_2 . V_2 = V_281 ;
break;
case V_319 :
memcpy ( F_32 ( V_25 ) , V_314 ,
F_187 ( V_314 ) ) ;
memcpy ( F_33 ( V_25 ) , V_316 ,
F_187 ( V_316 ) ) ;
switch ( V_313 -> V_269 ) {
case 0 :
V_2 . V_2 = V_273 ;
V_2 . V_190 . V_257 . V_144 = V_313 -> V_320 ;
V_2 . V_190 . V_257 . V_142 = V_313 -> V_321 ;
break;
case - V_322 :
case - V_323 :
V_2 . V_2 = V_287 ;
break;
case - V_270 :
V_2 . V_2 = V_268 ;
break;
default:
V_2 . V_2 = V_272 ;
break;
}
break;
case V_324 :
V_2 . V_2 = V_273 ;
V_2 . V_190 . V_257 . V_144 = V_313 -> V_320 ;
V_2 . V_190 . V_257 . V_142 = V_313 -> V_321 ;
break;
default:
F_84 ( 1 ) ;
}
V_2 . V_269 = V_313 -> V_269 ;
V_2 . V_190 . V_257 . V_185 = V_313 -> V_185 ;
V_2 . V_190 . V_257 . V_258 = V_313 -> V_258 ;
V_29 = V_25 -> V_41 . V_104 ( & V_25 -> V_41 , & V_2 ) ;
if ( V_29 ) {
V_25 -> V_152 . V_154 = NULL ;
F_15 ( V_25 , V_249 ) ;
F_31 ( & V_25 -> V_102 ) ;
F_155 ( & V_25 -> V_41 ) ;
return V_29 ;
}
F_31 ( & V_25 -> V_102 ) ;
return V_29 ;
}
static int F_188 ( struct V_310 * V_152 ,
struct V_312 * V_313 )
{
struct V_103 * V_325 ;
struct V_24 * V_169 , * V_297 ;
struct V_254 V_2 ;
int V_29 ;
struct V_326 V_327 ;
struct V_56 * V_314 = (struct V_56 * ) & V_313 -> V_315 ;
struct V_56 * V_316 = (struct V_56 * ) & V_313 -> V_317 ;
V_169 = V_152 -> V_105 ;
if ( F_60 ( V_169 , V_246 ) )
return - V_299 ;
V_325 = F_61 ( V_169 -> V_41 . V_43 . V_44 . V_45 . V_6 ,
V_169 -> V_41 . V_104 ,
V_169 -> V_41 . V_105 ,
V_12 , V_328 ) ;
if ( F_78 ( V_325 ) ) {
V_29 = - V_108 ;
goto V_91;
}
V_297 = F_26 ( V_325 , struct V_24 , V_41 ) ;
F_183 ( & V_297 -> V_102 , V_304 ) ;
V_297 -> V_31 = V_264 ;
V_29 = F_44 ( V_314 , & V_297 -> V_41 . V_43 . V_44 . V_45 , NULL ) ;
if ( V_29 ) {
F_31 ( & V_297 -> V_102 ) ;
F_155 ( V_325 ) ;
goto V_91;
}
V_29 = F_50 ( V_297 , V_169 ) ;
if ( V_29 ) {
F_31 ( & V_297 -> V_102 ) ;
F_155 ( V_325 ) ;
goto V_91;
}
V_297 -> V_152 . V_154 = V_152 ;
V_152 -> V_105 = V_297 ;
V_152 -> V_306 = F_186 ;
memcpy ( F_32 ( V_297 ) , V_314 , F_187 ( V_314 ) ) ;
memcpy ( F_33 ( V_297 ) , V_316 , F_187 ( V_316 ) ) ;
V_29 = F_189 ( V_297 -> V_41 . V_42 , & V_327 ) ;
if ( V_29 ) {
F_31 ( & V_297 -> V_102 ) ;
F_155 ( V_325 ) ;
goto V_91;
}
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_300 ;
V_2 . V_190 . V_257 . V_185 = V_313 -> V_185 ;
V_2 . V_190 . V_257 . V_258 = V_313 -> V_258 ;
V_2 . V_190 . V_257 . V_144 = V_313 -> V_320 ;
V_2 . V_190 . V_257 . V_142 = V_313 -> V_321 ;
F_19 ( & V_297 -> V_40 ) ;
V_29 = V_297 -> V_41 . V_104 ( & V_297 -> V_41 , & V_2 ) ;
if ( V_29 ) {
V_297 -> V_152 . V_154 = NULL ;
F_15 ( V_297 , V_249 ) ;
F_31 ( & V_297 -> V_102 ) ;
F_59 ( V_297 ) ;
F_155 ( & V_297 -> V_41 ) ;
goto V_91;
}
F_31 ( & V_297 -> V_102 ) ;
F_59 ( V_297 ) ;
V_91:
F_31 ( & V_169 -> V_102 ) ;
return V_29 ;
}
static int F_190 ( struct V_24 * V_25 )
{
struct V_56 * V_44 ;
struct V_238 * V_41 ;
T_8 V_329 ;
V_44 = F_32 ( V_25 ) ;
V_329 = F_185 ( & V_25 -> V_41 , V_44 ) ;
V_41 = F_191 ( V_25 -> V_41 . V_42 , F_182 , V_329 ) ;
if ( F_78 ( V_41 ) )
return F_79 ( V_41 ) ;
V_25 -> V_152 . V_55 = V_41 ;
return 0 ;
}
static int F_192 ( struct V_24 * V_25 , int V_330 )
{
int V_29 ;
struct V_310 * V_41 ;
V_41 = F_193 ( V_25 -> V_41 . V_42 ,
F_188 ,
V_25 ) ;
if ( F_78 ( V_41 ) )
return F_79 ( V_41 ) ;
V_41 -> V_331 = V_25 -> V_331 ;
V_25 -> V_152 . V_154 = V_41 ;
memcpy ( & V_25 -> V_152 . V_154 -> V_315 , F_32 ( V_25 ) ,
F_187 ( F_32 ( V_25 ) ) ) ;
V_29 = F_194 ( V_25 -> V_152 . V_154 , V_330 ) ;
if ( V_29 ) {
F_166 ( V_25 -> V_152 . V_154 ) ;
V_25 -> V_152 . V_154 = NULL ;
}
return V_29 ;
}
static int F_195 ( struct V_103 * V_41 ,
struct V_254 * V_2 )
{
struct V_24 * V_25 = V_41 -> V_105 ;
V_41 -> V_105 = V_25 -> V_41 . V_105 ;
V_41 -> V_104 = V_25 -> V_41 . V_104 ;
return V_25 -> V_41 . V_104 ( V_41 , V_2 ) ;
}
static void F_196 ( struct V_24 * V_25 ,
struct V_38 * V_39 )
{
struct V_24 * V_242 ;
struct V_103 * V_41 ;
struct V_6 * V_6 = V_25 -> V_41 . V_43 . V_44 . V_45 . V_6 ;
int V_29 ;
if ( F_34 ( V_25 ) == V_76 && ! F_90 ( V_39 -> V_42 , 1 ) )
return;
V_41 = F_61 ( V_6 , F_195 , V_25 , V_25 -> V_41 . V_10 ,
V_25 -> V_41 . V_107 ) ;
if ( F_78 ( V_41 ) )
return;
V_242 = F_26 ( V_41 , struct V_24 , V_41 ) ;
V_242 -> V_31 = V_332 ;
memcpy ( F_32 ( V_242 ) , F_32 ( V_25 ) ,
F_187 ( F_32 ( V_25 ) ) ) ;
F_18 ( V_242 , V_39 ) ;
F_21 ( & V_242 -> V_113 , & V_25 -> V_113 ) ;
F_19 ( & V_25 -> V_40 ) ;
V_242 -> V_250 = 1 ;
V_242 -> V_231 = V_25 -> V_231 ;
V_29 = F_197 ( V_41 , V_25 -> V_330 ) ;
if ( V_29 )
F_174 ( V_333 L_3
L_4 , V_29 , V_39 -> V_42 -> V_334 ) ;
}
static void F_198 ( struct V_24 * V_25 )
{
struct V_38 * V_39 ;
F_29 ( & V_30 ) ;
F_21 ( & V_25 -> V_48 , & V_335 ) ;
F_54 (cma_dev, &dev_list, list)
F_196 ( V_25 , V_39 ) ;
F_31 ( & V_30 ) ;
}
void F_199 ( struct V_103 * V_41 , int V_331 )
{
struct V_24 * V_25 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
V_25 -> V_331 = ( T_3 ) V_331 ;
}
static void F_200 ( int V_269 , struct V_170 * V_251 ,
void * V_105 )
{
struct V_336 * V_337 = V_105 ;
struct V_290 * V_43 ;
V_43 = & V_337 -> V_41 -> V_41 . V_43 ;
if ( ! V_269 ) {
V_43 -> V_291 = 1 ;
* V_43 -> V_251 = * V_251 ;
} else {
V_337 -> V_338 = V_245 ;
V_337 -> V_339 = V_340 ;
V_337 -> V_2 . V_2 = V_341 ;
V_337 -> V_2 . V_269 = V_269 ;
}
F_201 ( V_342 , & V_337 -> V_337 ) ;
}
static int F_202 ( struct V_24 * V_25 , int V_343 ,
struct V_336 * V_337 )
{
struct V_69 * V_45 = & V_25 -> V_41 . V_43 . V_44 . V_45 ;
struct V_170 V_251 ;
T_11 V_344 ;
struct V_161 * V_345 ;
struct V_67 * V_68 ;
memset ( & V_251 , 0 , sizeof V_251 ) ;
F_203 ( V_45 , & V_251 . V_94 ) ;
F_204 ( V_45 , & V_251 . V_95 ) ;
V_251 . V_96 = F_205 ( F_89 ( V_45 ) ) ;
V_251 . V_346 = 1 ;
V_251 . V_347 = 1 ;
V_251 . V_176 = F_185 ( & V_25 -> V_41 , F_33 ( V_25 ) ) ;
V_344 = V_348 | V_349 |
V_350 | V_351 |
V_352 | V_353 ;
switch ( F_34 ( V_25 ) ) {
case V_156 :
V_251 . V_354 = F_205 ( ( T_5 ) V_25 -> V_331 ) ;
V_344 |= V_355 ;
break;
case V_160 :
V_345 = (struct V_161 * ) F_32 ( V_25 ) ;
V_251 . V_356 = ( T_3 ) ( F_38 ( V_345 -> V_357 ) >> 20 ) ;
V_344 |= V_358 ;
break;
case V_76 :
V_68 = (struct V_67 * ) F_32 ( V_25 ) ;
V_251 . V_356 = ( T_3 ) ( F_38 ( V_68 -> V_174 ) >> 20 ) ;
V_344 |= V_358 ;
break;
}
V_25 -> V_241 = F_206 ( & V_359 , V_25 -> V_41 . V_42 ,
V_25 -> V_41 . V_66 , & V_251 ,
V_344 , V_343 ,
V_23 , F_200 ,
V_337 , & V_25 -> V_240 ) ;
return ( V_25 -> V_241 < 0 ) ? V_25 -> V_241 : 0 ;
}
static void F_207 ( struct V_360 * V_361 )
{
struct V_336 * V_337 = F_26 ( V_361 , struct V_336 , V_337 ) ;
struct V_24 * V_25 = V_337 -> V_41 ;
int V_362 = 0 ;
F_29 ( & V_25 -> V_102 ) ;
if ( ! F_14 ( V_25 , V_337 -> V_338 , V_337 -> V_339 ) )
goto V_91;
if ( V_25 -> V_41 . V_104 ( & V_25 -> V_41 , & V_337 -> V_2 ) ) {
F_15 ( V_25 , V_249 ) ;
V_362 = 1 ;
}
V_91:
F_31 ( & V_25 -> V_102 ) ;
F_59 ( V_25 ) ;
if ( V_362 )
F_155 ( & V_25 -> V_41 ) ;
F_27 ( V_337 ) ;
}
static void F_208 ( struct V_360 * V_361 )
{
struct V_363 * V_337 = F_26 ( V_361 , struct V_363 , V_337 ) ;
struct V_24 * V_25 = V_337 -> V_41 ;
int V_362 = 0 ;
F_29 ( & V_25 -> V_102 ) ;
if ( V_25 -> V_31 == V_249 ||
V_25 -> V_31 == V_364 )
goto V_91;
if ( V_25 -> V_41 . V_104 ( & V_25 -> V_41 , & V_337 -> V_2 ) ) {
F_15 ( V_25 , V_249 ) ;
V_362 = 1 ;
}
V_91:
F_31 ( & V_25 -> V_102 ) ;
F_59 ( V_25 ) ;
if ( V_362 )
F_155 ( & V_25 -> V_41 ) ;
F_27 ( V_337 ) ;
}
static int F_209 ( struct V_24 * V_25 , int V_343 )
{
struct V_290 * V_43 = & V_25 -> V_41 . V_43 ;
struct V_336 * V_337 ;
int V_29 ;
V_337 = F_62 ( sizeof *V_337 , V_23 ) ;
if ( ! V_337 )
return - V_108 ;
V_337 -> V_41 = V_25 ;
F_210 ( & V_337 -> V_337 , F_207 ) ;
V_337 -> V_338 = V_245 ;
V_337 -> V_339 = V_365 ;
V_337 -> V_2 . V_2 = V_366 ;
V_43 -> V_251 = F_176 ( sizeof * V_43 -> V_251 , V_23 ) ;
if ( ! V_43 -> V_251 ) {
V_29 = - V_108 ;
goto V_303;
}
V_29 = F_202 ( V_25 , V_343 , V_337 ) ;
if ( V_29 )
goto V_305;
return 0 ;
V_305:
F_27 ( V_43 -> V_251 ) ;
V_43 -> V_251 = NULL ;
V_303:
F_27 ( V_337 ) ;
return V_29 ;
}
int F_211 ( struct V_103 * V_41 ,
struct V_170 * V_251 , int V_291 )
{
struct V_24 * V_25 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( ! F_14 ( V_25 , V_340 ,
V_365 ) )
return - V_63 ;
V_41 -> V_43 . V_251 = F_212 ( V_251 , sizeof *V_251 * V_291 ,
V_23 ) ;
if ( ! V_41 -> V_43 . V_251 ) {
V_29 = - V_108 ;
goto V_133;
}
V_41 -> V_43 . V_291 = V_291 ;
return 0 ;
V_133:
F_14 ( V_25 , V_365 , V_340 ) ;
return V_29 ;
}
static int F_213 ( struct V_24 * V_25 , int V_343 )
{
struct V_336 * V_337 ;
V_337 = F_62 ( sizeof *V_337 , V_23 ) ;
if ( ! V_337 )
return - V_108 ;
V_337 -> V_41 = V_25 ;
F_210 ( & V_337 -> V_337 , F_207 ) ;
V_337 -> V_338 = V_245 ;
V_337 -> V_339 = V_365 ;
V_337 -> V_2 . V_2 = V_366 ;
F_201 ( V_342 , & V_337 -> V_337 ) ;
return 0 ;
}
static int F_214 ( struct V_82 * V_83 , int V_331 )
{
int V_367 ;
struct V_82 * V_218 ;
V_367 = F_215 ( V_331 ) ;
V_218 = V_83 -> V_368 & V_369 ?
F_216 ( V_83 ) : V_83 ;
if ( V_218 -> V_370 )
return F_217 ( V_218 , V_367 ) ;
#if F_128 ( V_371 )
if ( V_83 -> V_368 & V_369 )
return ( F_218 ( V_83 , V_367 ) &
V_372 ) >> V_373 ;
#endif
return 0 ;
}
static int F_219 ( struct V_24 * V_25 )
{
struct V_290 * V_43 = & V_25 -> V_41 . V_43 ;
struct V_237 * V_44 = & V_43 -> V_44 ;
struct V_336 * V_337 ;
int V_29 ;
struct V_82 * V_83 = NULL ;
V_337 = F_62 ( sizeof *V_337 , V_23 ) ;
if ( ! V_337 )
return - V_108 ;
V_337 -> V_41 = V_25 ;
F_210 ( & V_337 -> V_337 , F_207 ) ;
V_43 -> V_251 = F_62 ( sizeof * V_43 -> V_251 , V_23 ) ;
if ( ! V_43 -> V_251 ) {
V_29 = - V_108 ;
goto V_303;
}
V_43 -> V_291 = 1 ;
if ( V_44 -> V_45 . V_90 ) {
V_83 = F_47 ( & V_85 , V_44 -> V_45 . V_90 ) ;
V_43 -> V_251 -> V_6 = & V_85 ;
V_43 -> V_251 -> V_211 = V_44 -> V_45 . V_90 ;
}
if ( ! V_83 ) {
V_29 = - V_81 ;
goto V_305;
}
memcpy ( V_43 -> V_251 -> V_374 , V_44 -> V_45 . V_375 , V_376 ) ;
F_51 ( (struct V_56 * ) & V_25 -> V_41 . V_43 . V_44 . V_57 ,
& V_43 -> V_251 -> V_94 ) ;
F_51 ( (struct V_56 * ) & V_25 -> V_41 . V_43 . V_44 . V_58 ,
& V_43 -> V_251 -> V_95 ) ;
V_43 -> V_251 -> V_377 = 1 ;
V_43 -> V_251 -> V_347 = 1 ;
V_43 -> V_251 -> V_96 = F_205 ( 0xffff ) ;
V_43 -> V_251 -> V_378 = V_379 ;
V_43 -> V_251 -> V_380 = F_214 ( V_83 , V_25 -> V_331 ) ;
V_43 -> V_251 -> V_381 = F_220 ( V_83 -> V_381 ) ;
V_43 -> V_251 -> V_382 = V_379 ;
V_43 -> V_251 -> V_383 = F_221 ( V_83 ) ;
F_49 ( V_83 ) ;
V_43 -> V_251 -> V_384 = V_379 ;
V_43 -> V_251 -> V_385 = V_386 ;
if ( ! V_43 -> V_251 -> V_381 ) {
V_29 = - V_63 ;
goto V_305;
}
V_337 -> V_338 = V_245 ;
V_337 -> V_339 = V_365 ;
V_337 -> V_2 . V_2 = V_366 ;
V_337 -> V_2 . V_269 = 0 ;
F_201 ( V_342 , & V_337 -> V_337 ) ;
return 0 ;
V_305:
F_27 ( V_43 -> V_251 ) ;
V_43 -> V_251 = NULL ;
V_303:
F_27 ( V_337 ) ;
return V_29 ;
}
int F_222 ( struct V_103 * V_41 , int V_343 )
{
struct V_24 * V_25 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( ! F_14 ( V_25 , V_340 , V_245 ) )
return - V_63 ;
F_19 ( & V_25 -> V_40 ) ;
if ( F_149 ( V_41 -> V_42 , V_41 -> V_66 ) )
V_29 = F_209 ( V_25 , V_343 ) ;
else if ( F_53 ( V_41 -> V_42 , V_41 -> V_66 ) )
V_29 = F_219 ( V_25 ) ;
else if ( F_223 ( V_41 -> V_42 , V_41 -> V_66 ) )
V_29 = F_213 ( V_25 , V_343 ) ;
else
V_29 = - V_155 ;
if ( V_29 )
goto V_133;
return 0 ;
V_133:
F_14 ( V_25 , V_245 , V_340 ) ;
F_59 ( V_25 ) ;
return V_29 ;
}
static void F_224 ( struct V_56 * V_44 )
{
switch ( V_44 -> V_75 ) {
case V_156 :
( (struct V_157 * ) V_44 ) -> V_158 . V_159 = F_225 ( V_387 ) ;
break;
case V_160 :
F_226 ( & ( (struct V_161 * ) V_44 ) -> V_162 ,
0 , 0 , 0 , F_225 ( 1 ) ) ;
break;
default:
F_227 ( & ( (struct V_67 * ) V_44 ) -> V_73 ,
0 , 0 , 0 , F_225 ( 1 ) ) ;
break;
}
}
static int F_228 ( struct V_24 * V_25 )
{
struct V_38 * V_39 , * V_93 ;
struct V_388 V_389 ;
union V_72 V_79 ;
T_5 V_96 ;
int V_29 ;
T_3 V_97 ;
V_39 = NULL ;
F_29 ( & V_30 ) ;
F_54 (cur_dev, &dev_list, list) {
if ( F_34 ( V_25 ) == V_76 &&
! F_90 ( V_93 -> V_42 , 1 ) )
continue;
if ( ! V_39 )
V_39 = V_93 ;
for ( V_97 = 1 ; V_97 <= V_93 -> V_42 -> V_92 ; ++ V_97 ) {
if ( ! F_229 ( V_93 -> V_42 , V_97 , & V_389 ) &&
V_389 . V_31 == V_390 ) {
V_39 = V_93 ;
goto V_391;
}
}
}
if ( ! V_39 ) {
V_29 = - V_81 ;
goto V_91;
}
V_97 = 1 ;
V_391:
V_29 = F_58 ( V_39 -> V_42 , V_97 , 0 , & V_79 , NULL ) ;
if ( V_29 )
goto V_91;
V_29 = F_230 ( V_39 -> V_42 , V_97 , 0 , & V_96 ) ;
if ( V_29 )
goto V_91;
V_25 -> V_41 . V_43 . V_44 . V_45 . V_70 =
( F_46 ( V_39 -> V_42 , V_97 ) ) ?
V_71 : V_84 ;
F_40 ( & V_25 -> V_41 . V_43 . V_44 . V_45 , & V_79 ) ;
F_41 ( & V_25 -> V_41 . V_43 . V_44 . V_45 , V_96 ) ;
V_25 -> V_41 . V_66 = V_97 ;
F_18 ( V_25 , V_39 ) ;
F_224 ( F_32 ( V_25 ) ) ;
V_91:
F_31 ( & V_30 ) ;
return V_29 ;
}
static void F_231 ( int V_269 , struct V_56 * V_57 ,
struct V_69 * V_45 , void * V_105 )
{
struct V_24 * V_25 = V_105 ;
struct V_254 V_2 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
F_29 ( & V_25 -> V_102 ) ;
if ( ! F_14 ( V_25 , V_244 ,
V_340 ) )
goto V_91;
memcpy ( F_32 ( V_25 ) , V_57 , F_187 ( V_57 ) ) ;
if ( ! V_269 && ! V_25 -> V_39 )
V_269 = F_50 ( V_25 , NULL ) ;
if ( V_269 ) {
if ( ! F_14 ( V_25 , V_340 ,
V_332 ) )
goto V_91;
V_2 . V_2 = V_392 ;
V_2 . V_269 = V_269 ;
} else
V_2 . V_2 = V_393 ;
if ( V_25 -> V_41 . V_104 ( & V_25 -> V_41 , & V_2 ) ) {
F_15 ( V_25 , V_249 ) ;
F_31 ( & V_25 -> V_102 ) ;
F_59 ( V_25 ) ;
F_155 ( & V_25 -> V_41 ) ;
return;
}
V_91:
F_31 ( & V_25 -> V_102 ) ;
F_59 ( V_25 ) ;
}
static int F_232 ( struct V_24 * V_25 )
{
struct V_336 * V_337 ;
union V_72 V_79 ;
int V_29 ;
V_337 = F_62 ( sizeof *V_337 , V_23 ) ;
if ( ! V_337 )
return - V_108 ;
if ( ! V_25 -> V_39 ) {
V_29 = F_228 ( V_25 ) ;
if ( V_29 )
goto V_133;
}
F_203 ( & V_25 -> V_41 . V_43 . V_44 . V_45 , & V_79 ) ;
F_178 ( & V_25 -> V_41 . V_43 . V_44 . V_45 , & V_79 ) ;
V_337 -> V_41 = V_25 ;
F_210 ( & V_337 -> V_337 , F_207 ) ;
V_337 -> V_338 = V_244 ;
V_337 -> V_339 = V_340 ;
V_337 -> V_2 . V_2 = V_393 ;
F_201 ( V_342 , & V_337 -> V_337 ) ;
return 0 ;
V_133:
F_27 ( V_337 ) ;
return V_29 ;
}
static int F_233 ( struct V_24 * V_25 )
{
struct V_336 * V_337 ;
int V_29 ;
V_337 = F_62 ( sizeof *V_337 , V_23 ) ;
if ( ! V_337 )
return - V_108 ;
if ( ! V_25 -> V_39 ) {
V_29 = F_55 ( V_25 ) ;
if ( V_29 )
goto V_133;
}
F_178 ( & V_25 -> V_41 . V_43 . V_44 . V_45 , (union V_72 * )
& ( ( (struct V_67 * ) & V_25 -> V_41 . V_43 . V_44 . V_58 ) -> V_73 ) ) ;
V_337 -> V_41 = V_25 ;
F_210 ( & V_337 -> V_337 , F_207 ) ;
V_337 -> V_338 = V_244 ;
V_337 -> V_339 = V_340 ;
V_337 -> V_2 . V_2 = V_393 ;
F_201 ( V_342 , & V_337 -> V_337 ) ;
return 0 ;
V_133:
F_27 ( V_337 ) ;
return V_29 ;
}
static int F_234 ( struct V_103 * V_41 , struct V_56 * V_57 ,
struct V_56 * V_58 )
{
if ( ! V_57 || ! V_57 -> V_75 ) {
V_57 = (struct V_56 * ) & V_41 -> V_43 . V_44 . V_57 ;
V_57 -> V_75 = V_58 -> V_75 ;
if ( V_58 -> V_75 == V_160 ) {
struct V_161 * V_394 = (struct V_161 * ) V_57 ;
struct V_161 * V_395 = (struct V_161 * ) V_58 ;
V_394 -> V_396 = V_395 -> V_396 ;
if ( F_129 ( & V_395 -> V_162 ) & V_214 )
V_41 -> V_43 . V_44 . V_45 . V_90 = V_395 -> V_396 ;
} else if ( V_58 -> V_75 == V_76 ) {
( (struct V_67 * ) V_57 ) -> V_74 =
( (struct V_67 * ) V_58 ) -> V_74 ;
}
}
return F_235 ( V_41 , V_57 ) ;
}
int F_236 ( struct V_103 * V_41 , struct V_56 * V_57 ,
struct V_56 * V_58 , int V_343 )
{
struct V_24 * V_25 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( V_25 -> V_31 == V_111 ) {
V_29 = F_234 ( V_41 , V_57 , V_58 ) ;
if ( V_29 )
return V_29 ;
}
if ( F_34 ( V_25 ) != V_58 -> V_75 )
return - V_63 ;
if ( ! F_14 ( V_25 , V_332 , V_244 ) )
return - V_63 ;
F_19 ( & V_25 -> V_40 ) ;
memcpy ( F_33 ( V_25 ) , V_58 , F_187 ( V_58 ) ) ;
if ( F_102 ( V_58 ) ) {
V_29 = F_232 ( V_25 ) ;
} else {
if ( V_58 -> V_75 == V_76 ) {
V_29 = F_233 ( V_25 ) ;
} else {
V_29 = F_237 ( & V_397 , F_32 ( V_25 ) ,
V_58 , & V_41 -> V_43 . V_44 . V_45 ,
V_343 , F_231 , V_25 ) ;
}
}
if ( V_29 )
goto V_133;
return 0 ;
V_133:
F_14 ( V_25 , V_244 , V_332 ) ;
F_59 ( V_25 ) ;
return V_29 ;
}
int F_238 ( struct V_103 * V_41 , int V_398 )
{
struct V_24 * V_25 ;
unsigned long V_28 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
F_12 ( & V_25 -> V_30 , V_28 ) ;
if ( V_398 || V_25 -> V_31 == V_111 ) {
V_25 -> V_399 = V_398 ;
V_29 = 0 ;
} else {
V_29 = - V_63 ;
}
F_13 ( & V_25 -> V_30 , V_28 ) ;
return V_29 ;
}
int F_239 ( struct V_103 * V_41 , int V_231 )
{
struct V_24 * V_25 ;
unsigned long V_28 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
F_12 ( & V_25 -> V_30 , V_28 ) ;
if ( V_25 -> V_31 == V_111 || V_25 -> V_31 == V_332 ) {
V_25 -> V_400 |= ( 1 << V_401 ) ;
V_25 -> V_231 = V_231 ;
V_29 = 0 ;
} else {
V_29 = - V_63 ;
}
F_13 ( & V_25 -> V_30 , V_28 ) ;
return V_29 ;
}
static void F_240 ( struct V_20 * V_21 ,
struct V_24 * V_25 )
{
struct V_56 * V_44 ;
struct V_67 * V_68 ;
V_309 V_402 , V_403 ;
T_7 V_78 ;
V_44 = F_32 ( V_25 ) ;
V_78 = F_107 ( V_21 -> V_78 ) ;
switch ( V_44 -> V_75 ) {
case V_156 :
( (struct V_157 * ) V_44 ) -> V_165 = V_78 ;
break;
case V_160 :
( (struct V_161 * ) V_44 ) -> V_166 = V_78 ;
break;
case V_76 :
V_68 = (struct V_67 * ) V_44 ;
V_402 = F_108 ( V_68 -> V_167 ) ;
V_403 = F_108 ( V_68 -> V_168 ) ;
V_68 -> V_167 = F_111 ( ( V_402 & V_403 ) | ( V_309 ) F_42 ( V_78 ) ) ;
V_68 -> V_168 = F_111 ( ~ 0ULL ) ;
break;
}
V_25 -> V_21 = V_21 ;
F_241 ( & V_25 -> V_247 , & V_21 -> V_248 ) ;
}
static int F_242 ( enum V_9 V_10 ,
struct V_24 * V_25 , unsigned short V_22 )
{
struct V_20 * V_21 ;
int V_29 ;
V_21 = F_62 ( sizeof *V_21 , V_23 ) ;
if ( ! V_21 )
return - V_108 ;
V_29 = F_5 ( V_25 -> V_41 . V_43 . V_44 . V_45 . V_6 , V_10 , V_21 ,
V_22 ) ;
if ( V_29 < 0 )
goto V_133;
V_21 -> V_10 = V_10 ;
V_21 -> V_78 = ( unsigned short ) V_29 ;
F_240 ( V_21 , V_25 ) ;
return 0 ;
V_133:
F_27 ( V_21 ) ;
return V_29 == - V_404 ? - V_405 : V_29 ;
}
static int F_243 ( enum V_9 V_10 ,
struct V_24 * V_25 )
{
static unsigned int V_406 ;
int V_407 , V_408 , V_409 ;
unsigned int V_410 ;
struct V_6 * V_6 = V_25 -> V_41 . V_43 . V_44 . V_45 . V_6 ;
F_244 ( V_6 , & V_407 , & V_408 ) ;
V_409 = ( V_408 - V_407 ) + 1 ;
V_410 = F_245 () % V_409 + V_407 ;
V_411:
if ( V_406 != V_410 &&
! F_7 ( V_6 , V_10 , ( unsigned short ) V_410 ) ) {
int V_29 = F_242 ( V_10 , V_25 , V_410 ) ;
if ( ! V_29 )
V_406 = V_410 ;
if ( V_29 != - V_405 )
return V_29 ;
}
if ( -- V_409 ) {
V_410 ++ ;
if ( ( V_410 < V_407 ) || ( V_410 > V_408 ) )
V_410 = V_407 ;
goto V_411;
}
return - V_405 ;
}
static int F_246 ( struct V_20 * V_21 ,
struct V_24 * V_25 , T_12 V_399 )
{
struct V_24 * V_412 ;
struct V_56 * V_44 , * V_413 ;
V_44 = F_32 ( V_25 ) ;
F_144 (cur_id, &bind_list->owners, node) {
if ( V_25 == V_412 )
continue;
if ( ( V_412 -> V_31 != V_246 ) && V_399 &&
V_412 -> V_399 )
continue;
V_413 = F_32 ( V_412 ) ;
if ( V_25 -> V_231 && V_412 -> V_231 &&
( V_44 -> V_75 != V_413 -> V_75 ) )
continue;
if ( F_102 ( V_44 ) || F_102 ( V_413 ) )
return - V_405 ;
if ( ! F_103 ( V_44 , V_413 ) )
return - V_414 ;
}
return 0 ;
}
static int F_247 ( enum V_9 V_10 ,
struct V_24 * V_25 )
{
struct V_20 * V_21 ;
unsigned short V_22 ;
int V_29 ;
V_22 = F_42 ( F_106 ( F_32 ( V_25 ) ) ) ;
if ( V_22 < V_415 && ! F_248 ( V_416 ) )
return - V_417 ;
V_21 = F_7 ( V_25 -> V_41 . V_43 . V_44 . V_45 . V_6 , V_10 , V_22 ) ;
if ( ! V_21 ) {
V_29 = F_242 ( V_10 , V_25 , V_22 ) ;
} else {
V_29 = F_246 ( V_21 , V_25 , V_25 -> V_399 ) ;
if ( ! V_29 )
F_240 ( V_21 , V_25 ) ;
}
return V_29 ;
}
static int F_249 ( struct V_24 * V_25 )
{
struct V_20 * V_21 = V_25 -> V_21 ;
int V_29 = 0 ;
F_29 ( & V_30 ) ;
if ( V_21 -> V_248 . V_418 -> V_243 )
V_29 = F_246 ( V_21 , V_25 , 0 ) ;
F_31 ( & V_30 ) ;
return V_29 ;
}
static enum V_9 F_250 (
struct V_24 * V_25 )
{
switch ( V_25 -> V_41 . V_10 ) {
case V_12 :
case V_14 :
case V_16 :
case V_18 :
return V_25 -> V_41 . V_10 ;
default:
return 0 ;
}
}
static enum V_9 F_251 ( struct V_24 * V_25 )
{
enum V_9 V_10 = 0 ;
struct V_67 * V_68 ;
V_309 V_419 , V_403 , V_402 ;
V_68 = (struct V_67 * ) F_32 ( V_25 ) ;
V_403 = F_108 ( V_68 -> V_168 ) & V_420 ;
V_402 = F_108 ( V_68 -> V_167 ) & V_403 ;
if ( ( V_25 -> V_41 . V_10 == V_18 ) && ( V_402 == ( V_421 & V_403 ) ) ) {
V_419 = V_421 ;
V_10 = V_18 ;
} else if ( ( ( V_25 -> V_41 . V_10 == V_18 ) || ( V_25 -> V_41 . V_10 == V_12 ) ) &&
( V_402 == ( V_422 & V_403 ) ) ) {
V_419 = V_422 ;
V_10 = V_12 ;
} else if ( ( ( V_25 -> V_41 . V_10 == V_18 ) || ( V_25 -> V_41 . V_10 == V_14 ) ) &&
( V_402 == ( V_423 & V_403 ) ) ) {
V_419 = V_423 ;
V_10 = V_14 ;
}
if ( V_10 ) {
V_68 -> V_167 = F_111 ( V_419 | F_42 ( F_106 ( (struct V_56 * ) V_68 ) ) ) ;
V_68 -> V_168 = F_111 ( V_420 |
F_108 ( V_68 -> V_168 ) ) ;
}
return V_10 ;
}
static int F_252 ( struct V_24 * V_25 )
{
enum V_9 V_10 ;
int V_29 ;
if ( F_34 ( V_25 ) != V_76 )
V_10 = F_250 ( V_25 ) ;
else
V_10 = F_251 ( V_25 ) ;
if ( ! V_10 )
return - V_424 ;
F_29 ( & V_30 ) ;
if ( F_109 ( F_32 ( V_25 ) ) )
V_29 = F_243 ( V_10 , V_25 ) ;
else
V_29 = F_247 ( V_10 , V_25 ) ;
F_31 ( & V_30 ) ;
return V_29 ;
}
static int F_253 ( struct V_69 * V_45 ,
struct V_56 * V_44 )
{
#if F_128 ( V_212 )
struct V_161 * V_345 ;
if ( V_44 -> V_75 != V_160 )
return 0 ;
V_345 = (struct V_161 * ) V_44 ;
if ( ! ( F_129 ( & V_345 -> V_162 ) & V_214 ) )
return 0 ;
if ( ! V_345 -> V_396 )
return - V_63 ;
V_45 -> V_90 = V_345 -> V_396 ;
#endif
return 0 ;
}
int F_197 ( struct V_103 * V_41 , int V_330 )
{
struct V_24 * V_25 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( V_25 -> V_31 == V_111 ) {
V_41 -> V_43 . V_44 . V_57 . V_59 = V_156 ;
V_29 = F_235 ( V_41 , F_32 ( V_25 ) ) ;
if ( V_29 )
return V_29 ;
}
if ( ! F_14 ( V_25 , V_332 , V_246 ) )
return - V_63 ;
if ( V_25 -> V_399 ) {
V_29 = F_249 ( V_25 ) ;
if ( V_29 )
goto V_133;
}
V_25 -> V_330 = V_330 ;
if ( V_41 -> V_42 ) {
if ( F_90 ( V_41 -> V_42 , 1 ) ) {
V_29 = F_190 ( V_25 ) ;
if ( V_29 )
goto V_133;
} else if ( F_92 ( V_41 -> V_42 , 1 ) ) {
V_29 = F_192 ( V_25 , V_330 ) ;
if ( V_29 )
goto V_133;
} else {
V_29 = - V_155 ;
goto V_133;
}
} else
F_198 ( V_25 ) ;
return 0 ;
V_133:
V_25 -> V_330 = 0 ;
F_14 ( V_25 , V_246 , V_332 ) ;
return V_29 ;
}
int F_235 ( struct V_103 * V_41 , struct V_56 * V_44 )
{
struct V_24 * V_25 ;
int V_29 ;
if ( V_44 -> V_75 != V_156 && V_44 -> V_75 != V_160 &&
V_44 -> V_75 != V_76 )
return - V_188 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( ! F_14 ( V_25 , V_111 , V_332 ) )
return - V_63 ;
V_29 = F_253 ( & V_41 -> V_43 . V_44 . V_45 , V_44 ) ;
if ( V_29 )
goto V_303;
memcpy ( F_32 ( V_25 ) , V_44 , F_187 ( V_44 ) ) ;
if ( ! F_102 ( V_44 ) ) {
V_29 = F_43 ( V_44 , & V_41 -> V_43 . V_44 . V_45 ) ;
if ( V_29 )
goto V_303;
V_29 = F_50 ( V_25 , NULL ) ;
if ( V_29 )
goto V_303;
}
if ( ! ( V_25 -> V_400 & ( 1 << V_401 ) ) ) {
if ( V_44 -> V_75 == V_156 )
V_25 -> V_231 = 1 ;
#if F_128 ( V_212 )
else if ( V_44 -> V_75 == V_160 ) {
struct V_6 * V_6 = V_25 -> V_41 . V_43 . V_44 . V_45 . V_6 ;
V_25 -> V_231 = V_6 -> V_425 . V_426 . V_427 ;
}
#endif
}
V_29 = F_252 ( V_25 ) ;
if ( V_29 )
goto V_305;
return 0 ;
V_305:
if ( V_25 -> V_39 )
F_28 ( V_25 ) ;
V_303:
F_14 ( V_25 , V_332 , V_111 ) ;
return V_29 ;
}
static int F_254 ( void * V_35 , struct V_24 * V_25 )
{
struct V_34 * V_34 ;
V_34 = V_35 ;
V_34 -> V_186 = V_187 ;
if ( F_34 ( V_25 ) == V_156 ) {
struct V_157 * V_428 , * V_429 ;
V_428 = (struct V_157 * ) F_32 ( V_25 ) ;
V_429 = (struct V_157 * ) F_33 ( V_25 ) ;
F_17 ( V_34 , 4 ) ;
V_34 -> V_57 . V_179 . V_44 = V_428 -> V_158 . V_159 ;
V_34 -> V_58 . V_179 . V_44 = V_429 -> V_158 . V_159 ;
V_34 -> V_78 = V_428 -> V_165 ;
} else if ( F_34 ( V_25 ) == V_160 ) {
struct V_161 * V_430 , * V_431 ;
V_430 = (struct V_161 * ) F_32 ( V_25 ) ;
V_431 = (struct V_161 * ) F_33 ( V_25 ) ;
F_17 ( V_34 , 6 ) ;
V_34 -> V_57 . V_181 = V_430 -> V_162 ;
V_34 -> V_58 . V_181 = V_431 -> V_162 ;
V_34 -> V_78 = V_430 -> V_166 ;
}
return 0 ;
}
static int F_255 ( struct V_238 * V_152 ,
struct V_183 * V_184 )
{
struct V_24 * V_25 = V_152 -> V_105 ;
struct V_254 V_2 ;
struct V_432 * V_433 = & V_184 -> V_190 . V_434 ;
int V_29 = 0 ;
if ( F_60 ( V_25 , V_264 ) )
return 0 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_184 -> V_2 ) {
case V_435 :
V_2 . V_2 = V_268 ;
V_2 . V_269 = - V_270 ;
break;
case V_436 :
V_2 . V_190 . V_301 . V_185 = V_184 -> V_185 ;
V_2 . V_190 . V_301 . V_258 = V_437 ;
if ( V_433 -> V_269 != V_438 ) {
V_2 . V_2 = V_268 ;
V_2 . V_269 = V_184 -> V_190 . V_434 . V_269 ;
break;
}
V_29 = F_35 ( V_25 , V_433 -> V_60 ) ;
if ( V_29 ) {
V_2 . V_2 = V_392 ;
V_2 . V_269 = V_29 ;
break;
}
F_256 ( V_25 -> V_41 . V_42 , V_25 -> V_41 . V_66 ,
V_25 -> V_41 . V_43 . V_251 ,
& V_2 . V_190 . V_301 . V_138 ) ;
V_2 . V_190 . V_301 . V_134 = V_433 -> V_439 ;
V_2 . V_190 . V_301 . V_60 = V_433 -> V_60 ;
V_2 . V_2 = V_273 ;
V_2 . V_269 = 0 ;
break;
default:
F_174 ( V_289 L_2 ,
V_184 -> V_2 ) ;
goto V_91;
}
V_29 = V_25 -> V_41 . V_104 ( & V_25 -> V_41 , & V_2 ) ;
if ( V_29 ) {
V_25 -> V_152 . V_55 = NULL ;
F_15 ( V_25 , V_249 ) ;
F_31 ( & V_25 -> V_102 ) ;
F_155 ( & V_25 -> V_41 ) ;
return V_29 ;
}
V_91:
F_31 ( & V_25 -> V_102 ) ;
return V_29 ;
}
static int F_257 ( struct V_24 * V_25 ,
struct V_136 * V_137 )
{
struct V_440 V_195 ;
struct V_238 * V_41 ;
void * V_185 ;
int V_294 , V_29 ;
memset ( & V_195 , 0 , sizeof V_195 ) ;
V_294 = F_147 ( V_25 ) ;
V_195 . V_258 = V_294 + V_137 -> V_258 ;
if ( V_195 . V_258 < V_137 -> V_258 )
return - V_63 ;
if ( V_195 . V_258 ) {
V_185 = F_62 ( V_195 . V_258 , V_441 ) ;
if ( ! V_185 )
return - V_108 ;
} else {
V_185 = NULL ;
}
if ( V_137 -> V_185 && V_137 -> V_258 )
memcpy ( V_185 + V_294 , V_137 -> V_185 ,
V_137 -> V_258 ) ;
if ( V_185 ) {
V_29 = F_254 ( V_185 , V_25 ) ;
if ( V_29 )
goto V_91;
V_195 . V_185 = V_185 ;
}
V_41 = F_258 ( V_25 -> V_41 . V_42 , F_255 ,
V_25 ) ;
if ( F_78 ( V_41 ) ) {
V_29 = F_79 ( V_41 ) ;
goto V_91;
}
V_25 -> V_152 . V_55 = V_41 ;
V_195 . V_171 = V_25 -> V_41 . V_43 . V_251 ;
V_195 . V_176 = F_185 ( & V_25 -> V_41 , F_33 ( V_25 ) ) ;
V_195 . V_343 = 1 << ( V_442 - 8 ) ;
V_195 . V_443 = V_444 ;
V_29 = F_259 ( V_25 -> V_152 . V_55 , & V_195 ) ;
if ( V_29 ) {
F_165 ( V_25 -> V_152 . V_55 ) ;
V_25 -> V_152 . V_55 = NULL ;
}
V_91:
F_27 ( V_185 ) ;
return V_29 ;
}
static int F_260 ( struct V_24 * V_25 ,
struct V_136 * V_137 )
{
struct V_445 V_195 ;
struct V_290 * V_43 ;
void * V_185 ;
struct V_238 * V_41 ;
int V_294 , V_29 ;
memset ( & V_195 , 0 , sizeof V_195 ) ;
V_294 = F_147 ( V_25 ) ;
V_195 . V_258 = V_294 + V_137 -> V_258 ;
if ( V_195 . V_258 < V_137 -> V_258 )
return - V_63 ;
if ( V_195 . V_258 ) {
V_185 = F_62 ( V_195 . V_258 , V_441 ) ;
if ( ! V_185 )
return - V_108 ;
} else {
V_185 = NULL ;
}
if ( V_137 -> V_185 && V_137 -> V_258 )
memcpy ( V_185 + V_294 , V_137 -> V_185 ,
V_137 -> V_258 ) ;
V_41 = F_258 ( V_25 -> V_41 . V_42 , F_173 , V_25 ) ;
if ( F_78 ( V_41 ) ) {
V_29 = F_79 ( V_41 ) ;
goto V_91;
}
V_25 -> V_152 . V_55 = V_41 ;
V_43 = & V_25 -> V_41 . V_43 ;
if ( V_185 ) {
V_29 = F_254 ( V_185 , V_25 ) ;
if ( V_29 )
goto V_91;
V_195 . V_185 = V_185 ;
}
V_195 . V_192 = & V_43 -> V_251 [ 0 ] ;
if ( V_43 -> V_291 == 2 )
V_195 . V_292 = & V_43 -> V_251 [ 1 ] ;
V_195 . V_176 = F_185 ( & V_25 -> V_41 , F_33 ( V_25 ) ) ;
V_195 . V_134 = V_25 -> V_134 ;
V_195 . V_107 = V_25 -> V_41 . V_107 ;
V_195 . V_446 = V_25 -> V_115 ;
V_195 . V_142 = V_137 -> V_142 ;
V_195 . V_144 = V_137 -> V_144 ;
V_195 . V_260 = V_137 -> V_260 ;
V_195 . V_296 = F_261 ( T_3 , 7 , V_137 -> V_296 ) ;
V_195 . V_261 = F_261 ( T_3 , 7 , V_137 -> V_261 ) ;
V_195 . V_447 = V_442 ;
V_195 . V_448 = V_442 ;
V_195 . V_443 = V_444 ;
V_195 . V_135 = V_25 -> V_135 ? 1 : 0 ;
V_29 = F_262 ( V_25 -> V_152 . V_55 , & V_195 ) ;
V_91:
if ( V_29 && ! F_78 ( V_41 ) ) {
F_165 ( V_41 ) ;
V_25 -> V_152 . V_55 = NULL ;
}
F_27 ( V_185 ) ;
return V_29 ;
}
static int F_263 ( struct V_24 * V_25 ,
struct V_136 * V_137 )
{
struct V_310 * V_152 ;
int V_29 ;
struct V_449 V_450 ;
V_152 = F_193 ( V_25 -> V_41 . V_42 , F_186 , V_25 ) ;
if ( F_78 ( V_152 ) )
return F_79 ( V_152 ) ;
V_152 -> V_331 = V_25 -> V_331 ;
V_25 -> V_152 . V_154 = V_152 ;
memcpy ( & V_152 -> V_315 , F_32 ( V_25 ) ,
F_187 ( F_32 ( V_25 ) ) ) ;
memcpy ( & V_152 -> V_317 , F_33 ( V_25 ) ,
F_187 ( F_33 ( V_25 ) ) ) ;
V_29 = F_82 ( V_25 , V_137 ) ;
if ( V_29 )
goto V_91;
if ( V_137 ) {
V_450 . V_321 = V_137 -> V_144 ;
V_450 . V_320 = V_137 -> V_142 ;
V_450 . V_185 = V_137 -> V_185 ;
V_450 . V_258 = V_137 -> V_258 ;
V_450 . V_439 = V_25 -> V_41 . V_117 ? V_25 -> V_134 : V_137 -> V_134 ;
} else {
memset ( & V_450 , 0 , sizeof V_450 ) ;
V_450 . V_439 = V_25 -> V_134 ;
}
V_29 = F_264 ( V_152 , & V_450 ) ;
V_91:
if ( V_29 ) {
F_166 ( V_152 ) ;
V_25 -> V_152 . V_154 = NULL ;
}
return V_29 ;
}
int F_265 ( struct V_103 * V_41 , struct V_136 * V_137 )
{
struct V_24 * V_25 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( ! F_14 ( V_25 , V_365 , V_264 ) )
return - V_63 ;
if ( ! V_41 -> V_117 ) {
V_25 -> V_134 = V_137 -> V_134 ;
V_25 -> V_135 = V_137 -> V_135 ;
}
if ( F_90 ( V_41 -> V_42 , V_41 -> V_66 ) ) {
if ( V_41 -> V_107 == V_132 )
V_29 = F_257 ( V_25 , V_137 ) ;
else
V_29 = F_260 ( V_25 , V_137 ) ;
} else if ( F_92 ( V_41 -> V_42 , V_41 -> V_66 ) )
V_29 = F_263 ( V_25 , V_137 ) ;
else
V_29 = - V_155 ;
if ( V_29 )
goto V_133;
return 0 ;
V_133:
F_14 ( V_25 , V_264 , V_365 ) ;
return V_29 ;
}
static int F_266 ( struct V_24 * V_25 ,
struct V_136 * V_137 )
{
struct V_451 V_433 ;
int V_29 ;
V_29 = F_82 ( V_25 , V_137 ) ;
if ( V_29 )
goto V_91;
V_29 = F_85 ( V_25 , V_137 ) ;
if ( V_29 )
goto V_91;
memset ( & V_433 , 0 , sizeof V_433 ) ;
V_433 . V_134 = V_25 -> V_134 ;
V_433 . V_446 = V_25 -> V_115 ;
V_433 . V_185 = V_137 -> V_185 ;
V_433 . V_258 = V_137 -> V_258 ;
V_433 . V_142 = V_137 -> V_142 ;
V_433 . V_144 = V_137 -> V_144 ;
V_433 . V_452 = 0 ;
V_433 . V_260 = V_137 -> V_260 ;
V_433 . V_261 = F_261 ( T_3 , 7 , V_137 -> V_261 ) ;
V_433 . V_135 = V_25 -> V_135 ? 1 : 0 ;
V_29 = F_267 ( V_25 -> V_152 . V_55 , & V_433 ) ;
V_91:
return V_29 ;
}
static int F_268 ( struct V_24 * V_25 ,
struct V_136 * V_137 )
{
struct V_449 V_450 ;
int V_29 ;
V_29 = F_82 ( V_25 , V_137 ) ;
if ( V_29 )
return V_29 ;
V_450 . V_321 = V_137 -> V_144 ;
V_450 . V_320 = V_137 -> V_142 ;
V_450 . V_185 = V_137 -> V_185 ;
V_450 . V_258 = V_137 -> V_258 ;
if ( V_25 -> V_41 . V_117 ) {
V_450 . V_439 = V_25 -> V_134 ;
} else
V_450 . V_439 = V_137 -> V_134 ;
return F_269 ( V_25 -> V_152 . V_154 , & V_450 ) ;
}
static int F_270 ( struct V_24 * V_25 ,
enum V_453 V_269 , T_4 V_60 ,
const void * V_185 , int V_258 )
{
struct V_454 V_433 ;
int V_29 ;
memset ( & V_433 , 0 , sizeof V_433 ) ;
V_433 . V_269 = V_269 ;
if ( V_269 == V_438 ) {
V_29 = F_35 ( V_25 , V_60 ) ;
if ( V_29 )
return V_29 ;
V_433 . V_134 = V_25 -> V_134 ;
V_433 . V_60 = V_25 -> V_60 ;
}
V_433 . V_185 = V_185 ;
V_433 . V_258 = V_258 ;
return F_271 ( V_25 -> V_152 . V_55 , & V_433 ) ;
}
int F_272 ( struct V_103 * V_41 , struct V_136 * V_137 )
{
struct V_24 * V_25 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
V_25 -> V_109 = F_64 ( V_110 ) ;
if ( ! F_11 ( V_25 , V_264 ) )
return - V_63 ;
if ( ! V_41 -> V_117 && V_137 ) {
V_25 -> V_134 = V_137 -> V_134 ;
V_25 -> V_135 = V_137 -> V_135 ;
}
if ( F_90 ( V_41 -> V_42 , V_41 -> V_66 ) ) {
if ( V_41 -> V_107 == V_132 ) {
if ( V_137 )
V_29 = F_270 ( V_25 , V_438 ,
V_137 -> V_60 ,
V_137 -> V_185 ,
V_137 -> V_258 ) ;
else
V_29 = F_270 ( V_25 , V_438 ,
0 , NULL , 0 ) ;
} else {
if ( V_137 )
V_29 = F_266 ( V_25 , V_137 ) ;
else
V_29 = F_169 ( V_25 ) ;
}
} else if ( F_92 ( V_41 -> V_42 , V_41 -> V_66 ) )
V_29 = F_268 ( V_25 , V_137 ) ;
else
V_29 = - V_155 ;
if ( V_29 )
goto V_252;
return 0 ;
V_252:
F_86 ( V_25 ) ;
F_273 ( V_41 , NULL , 0 ) ;
return V_29 ;
}
int F_274 ( struct V_103 * V_41 , enum V_455 V_2 )
{
struct V_24 * V_25 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( ! V_25 -> V_152 . V_55 )
return - V_63 ;
switch ( V_41 -> V_42 -> V_47 ) {
case V_456 :
V_29 = F_275 ( V_25 -> V_152 . V_55 , V_2 ) ;
break;
default:
V_29 = 0 ;
break;
}
return V_29 ;
}
int F_273 ( struct V_103 * V_41 , const void * V_185 ,
T_3 V_258 )
{
struct V_24 * V_25 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( ! V_25 -> V_152 . V_55 )
return - V_63 ;
if ( F_90 ( V_41 -> V_42 , V_41 -> V_66 ) ) {
if ( V_41 -> V_107 == V_132 )
V_29 = F_270 ( V_25 , V_457 , 0 ,
V_185 , V_258 ) ;
else
V_29 = F_171 ( V_25 -> V_152 . V_55 ,
V_253 , NULL ,
0 , V_185 , V_258 ) ;
} else if ( F_92 ( V_41 -> V_42 , V_41 -> V_66 ) ) {
V_29 = F_276 ( V_25 -> V_152 . V_154 ,
V_185 , V_258 ) ;
} else
V_29 = - V_155 ;
return V_29 ;
}
int F_277 ( struct V_103 * V_41 )
{
struct V_24 * V_25 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( ! V_25 -> V_152 . V_55 )
return - V_63 ;
if ( F_90 ( V_41 -> V_42 , V_41 -> V_66 ) ) {
V_29 = F_86 ( V_25 ) ;
if ( V_29 )
goto V_91;
if ( F_278 ( V_25 -> V_152 . V_55 , NULL , 0 ) )
F_279 ( V_25 -> V_152 . V_55 , NULL , 0 ) ;
} else if ( F_92 ( V_41 -> V_42 , V_41 -> V_66 ) ) {
V_29 = F_280 ( V_25 -> V_152 . V_154 , 0 ) ;
} else
V_29 = - V_63 ;
V_91:
return V_29 ;
}
static int F_281 ( int V_269 , struct V_458 * V_54 )
{
struct V_24 * V_25 ;
struct V_51 * V_52 = V_54 -> V_105 ;
struct V_254 V_2 ;
int V_29 ;
V_25 = V_52 -> V_25 ;
if ( F_60 ( V_25 , V_332 ) &&
F_60 ( V_25 , V_340 ) )
return 0 ;
if ( ! V_269 )
V_269 = F_35 ( V_25 , F_38 ( V_54 -> V_62 . V_60 ) ) ;
F_29 ( & V_25 -> V_112 ) ;
if ( ! V_269 && V_25 -> V_41 . V_117 )
V_269 = F_282 ( V_25 -> V_41 . V_117 , & V_54 -> V_62 . V_65 ,
F_118 ( V_54 -> V_62 . V_459 ) ) ;
F_31 ( & V_25 -> V_112 ) ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_269 = V_269 ;
V_2 . V_190 . V_301 . V_185 = V_52 -> V_105 ;
if ( ! V_269 ) {
V_2 . V_2 = V_460 ;
F_283 ( V_25 -> V_41 . V_42 ,
V_25 -> V_41 . V_66 , & V_54 -> V_62 ,
& V_2 . V_190 . V_301 . V_138 ) ;
V_2 . V_190 . V_301 . V_134 = 0xFFFFFF ;
V_2 . V_190 . V_301 . V_60 = F_38 ( V_54 -> V_62 . V_60 ) ;
} else
V_2 . V_2 = V_461 ;
V_29 = V_25 -> V_41 . V_104 ( & V_25 -> V_41 , & V_2 ) ;
if ( V_29 ) {
F_15 ( V_25 , V_249 ) ;
F_31 ( & V_25 -> V_102 ) ;
F_155 ( & V_25 -> V_41 ) ;
return 0 ;
}
F_31 ( & V_25 -> V_102 ) ;
return 0 ;
}
static void F_284 ( struct V_24 * V_25 ,
struct V_56 * V_44 , union V_72 * V_65 )
{
unsigned char V_462 [ V_463 ] ;
struct V_69 * V_45 = & V_25 -> V_41 . V_43 . V_44 . V_45 ;
struct V_157 * sin = (struct V_157 * ) V_44 ;
struct V_161 * V_345 = (struct V_161 * ) V_44 ;
if ( F_102 ( V_44 ) ) {
memset ( V_65 , 0 , sizeof *V_65 ) ;
} else if ( ( V_44 -> V_75 == V_160 ) &&
( ( F_38 ( V_345 -> V_162 . V_464 [ 0 ] ) & 0xFFF0FFFF ) ==
0xFF10A01B ) ) {
memcpy ( V_65 , & V_345 -> V_162 , sizeof *V_65 ) ;
} else if ( V_44 -> V_75 == V_76 ) {
memcpy ( V_65 , & ( (struct V_67 * ) V_44 ) -> V_73 , sizeof *V_65 ) ;
} else if ( ( V_44 -> V_75 == V_160 ) ) {
F_285 ( & V_345 -> V_162 , V_45 -> V_465 , V_462 ) ;
if ( V_25 -> V_41 . V_10 == V_14 )
V_462 [ 7 ] = 0x01 ;
* V_65 = * (union V_72 * ) ( V_462 + 4 ) ;
} else {
F_286 ( sin -> V_158 . V_159 , V_45 -> V_465 , V_462 ) ;
if ( V_25 -> V_41 . V_10 == V_14 )
V_462 [ 7 ] = 0x01 ;
* V_65 = * (union V_72 * ) ( V_462 + 4 ) ;
}
}
static int F_287 ( struct V_24 * V_25 ,
struct V_51 * V_52 )
{
struct V_61 V_62 ;
struct V_69 * V_45 = & V_25 -> V_41 . V_43 . V_44 . V_45 ;
T_11 V_344 ;
int V_29 ;
F_36 ( V_45 , & V_62 . V_65 ) ;
V_29 = F_37 ( V_25 -> V_41 . V_42 , V_25 -> V_41 . V_66 ,
& V_62 . V_65 , & V_62 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_35 ( V_25 , 0 ) ;
if ( V_29 )
return V_29 ;
F_284 ( V_25 , (struct V_56 * ) & V_52 -> V_44 , & V_62 . V_65 ) ;
V_62 . V_60 = F_288 ( V_25 -> V_60 ) ;
F_203 ( V_45 , & V_62 . V_466 ) ;
V_62 . V_96 = F_205 ( F_89 ( V_45 ) ) ;
V_62 . V_467 = 1 ;
V_344 = V_468 | V_469 |
V_470 | V_471 |
V_472 | V_473 |
V_474 |
V_475 ;
if ( V_25 -> V_41 . V_10 == V_16 )
V_344 |= V_476 |
V_477 |
V_478 |
V_479 |
V_480 ;
V_52 -> V_54 . V_55 = F_289 ( & V_359 , V_25 -> V_41 . V_42 ,
V_25 -> V_41 . V_66 , & V_62 ,
V_344 , V_23 ,
F_281 , V_52 ) ;
return F_290 ( V_52 -> V_54 . V_55 ) ;
}
static void F_291 ( struct V_360 * V_337 )
{
struct V_481 * V_482 = F_26 ( V_337 , struct V_481 , V_337 ) ;
struct V_51 * V_52 = V_482 -> V_52 ;
struct V_458 * V_483 = V_52 -> V_54 . V_55 ;
V_52 -> V_54 . V_55 -> V_105 = V_52 ;
F_281 ( 0 , V_483 ) ;
F_164 ( & V_52 -> V_53 , F_25 ) ;
F_27 ( V_482 ) ;
}
static void F_292 ( struct V_56 * V_44 , union V_72 * V_65 )
{
struct V_157 * sin = (struct V_157 * ) V_44 ;
struct V_161 * V_345 = (struct V_161 * ) V_44 ;
if ( F_102 ( V_44 ) ) {
memset ( V_65 , 0 , sizeof *V_65 ) ;
} else if ( V_44 -> V_75 == V_160 ) {
memcpy ( V_65 , & V_345 -> V_162 , sizeof *V_65 ) ;
} else {
V_65 -> V_484 [ 0 ] = 0xff ;
V_65 -> V_484 [ 1 ] = 0x0e ;
V_65 -> V_484 [ 2 ] = 0 ;
V_65 -> V_484 [ 3 ] = 0 ;
V_65 -> V_484 [ 4 ] = 0 ;
V_65 -> V_484 [ 5 ] = 0 ;
V_65 -> V_484 [ 6 ] = 0 ;
V_65 -> V_484 [ 7 ] = 0 ;
V_65 -> V_484 [ 8 ] = 0 ;
V_65 -> V_484 [ 9 ] = 0 ;
V_65 -> V_484 [ 10 ] = 0xff ;
V_65 -> V_484 [ 11 ] = 0xff ;
* ( T_10 * ) ( & V_65 -> V_484 [ 12 ] ) = sin -> V_158 . V_159 ;
}
}
static int F_293 ( struct V_24 * V_25 ,
struct V_51 * V_52 )
{
struct V_481 * V_337 ;
struct V_69 * V_45 = & V_25 -> V_41 . V_43 . V_44 . V_45 ;
int V_133 ;
struct V_56 * V_44 = (struct V_56 * ) & V_52 -> V_44 ;
struct V_82 * V_83 = NULL ;
if ( F_94 ( (struct V_56 * ) & V_52 -> V_44 ) )
return - V_63 ;
V_337 = F_62 ( sizeof *V_337 , V_23 ) ;
if ( ! V_337 )
return - V_108 ;
V_52 -> V_54 . V_55 = F_62 ( sizeof( struct V_458 ) , V_23 ) ;
if ( ! V_52 -> V_54 . V_55 ) {
V_133 = - V_108 ;
goto V_485;
}
F_292 ( V_44 , & V_52 -> V_54 . V_55 -> V_62 . V_65 ) ;
V_52 -> V_54 . V_55 -> V_62 . V_96 = F_205 ( 0xffff ) ;
if ( V_25 -> V_41 . V_10 == V_14 )
V_52 -> V_54 . V_55 -> V_62 . V_60 = F_288 ( V_64 ) ;
if ( V_45 -> V_90 )
V_83 = F_47 ( & V_85 , V_45 -> V_90 ) ;
if ( ! V_83 ) {
V_133 = - V_81 ;
goto V_486;
}
V_52 -> V_54 . V_55 -> V_62 . V_383 = F_221 ( V_83 ) ;
V_52 -> V_54 . V_55 -> V_62 . V_377 = 1 ;
V_52 -> V_54 . V_55 -> V_62 . V_381 = F_220 ( V_83 -> V_381 ) ;
F_49 ( V_83 ) ;
if ( ! V_52 -> V_54 . V_55 -> V_62 . V_381 ) {
V_133 = - V_63 ;
goto V_486;
}
F_51 ( (struct V_56 * ) & V_25 -> V_41 . V_43 . V_44 . V_57 ,
& V_52 -> V_54 . V_55 -> V_62 . V_466 ) ;
V_337 -> V_41 = V_25 ;
V_337 -> V_52 = V_52 ;
F_210 ( & V_337 -> V_337 , F_291 ) ;
F_294 ( & V_52 -> V_53 ) ;
F_201 ( V_342 , & V_337 -> V_337 ) ;
return 0 ;
V_486:
F_27 ( V_52 -> V_54 . V_55 ) ;
V_485:
F_27 ( V_337 ) ;
return V_133 ;
}
int F_295 ( struct V_103 * V_41 , struct V_56 * V_44 ,
void * V_105 )
{
struct V_24 * V_25 ;
struct V_51 * V_52 ;
int V_29 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
if ( ! F_11 ( V_25 , V_332 ) &&
! F_11 ( V_25 , V_340 ) )
return - V_63 ;
V_52 = F_176 ( sizeof *V_52 , V_23 ) ;
if ( ! V_52 )
return - V_108 ;
memcpy ( & V_52 -> V_44 , V_44 , F_187 ( V_44 ) ) ;
V_52 -> V_105 = V_105 ;
V_52 -> V_25 = V_25 ;
F_296 ( & V_25 -> V_30 ) ;
F_297 ( & V_52 -> V_48 , & V_25 -> V_114 ) ;
F_298 ( & V_25 -> V_30 ) ;
if ( F_53 ( V_41 -> V_42 , V_41 -> V_66 ) ) {
F_299 ( & V_52 -> V_53 ) ;
V_29 = F_293 ( V_25 , V_52 ) ;
} else if ( F_162 ( V_41 -> V_42 , V_41 -> V_66 ) )
V_29 = F_287 ( V_25 , V_52 ) ;
else
V_29 = - V_155 ;
if ( V_29 ) {
F_300 ( & V_25 -> V_30 ) ;
F_30 ( & V_52 -> V_48 ) ;
F_301 ( & V_25 -> V_30 ) ;
F_27 ( V_52 ) ;
}
return V_29 ;
}
void F_302 ( struct V_103 * V_41 , struct V_56 * V_44 )
{
struct V_24 * V_25 ;
struct V_51 * V_52 ;
V_25 = F_26 ( V_41 , struct V_24 , V_41 ) ;
F_300 ( & V_25 -> V_30 ) ;
F_54 (mc, &id_priv->mc_list, list) {
if ( ! memcmp ( & V_52 -> V_44 , V_44 , F_187 ( V_44 ) ) ) {
F_30 ( & V_52 -> V_48 ) ;
F_301 ( & V_25 -> V_30 ) ;
if ( V_41 -> V_117 )
F_303 ( V_41 -> V_117 ,
& V_52 -> V_54 . V_55 -> V_62 . V_65 ,
F_118 ( V_52 -> V_54 . V_55 -> V_62 . V_459 ) ) ;
F_84 ( V_25 -> V_39 -> V_42 != V_41 -> V_42 ) ;
if ( F_162 ( V_41 -> V_42 , V_41 -> V_66 ) ) {
F_163 ( V_52 -> V_54 . V_55 ) ;
F_27 ( V_52 ) ;
} else if ( F_53 ( V_41 -> V_42 , V_41 -> V_66 ) )
F_164 ( & V_52 -> V_53 , F_25 ) ;
return;
}
}
F_301 ( & V_25 -> V_30 ) ;
}
static int F_304 ( struct V_82 * V_83 , struct V_24 * V_25 )
{
struct V_69 * V_45 ;
struct V_363 * V_337 ;
V_45 = & V_25 -> V_41 . V_43 . V_44 . V_45 ;
if ( ( V_45 -> V_90 == V_83 -> V_211 ) &&
( F_142 ( F_124 ( V_83 ) , V_45 -> V_6 ) ) &&
memcmp ( V_45 -> V_89 , V_83 -> V_45 , V_83 -> V_487 ) ) {
F_174 ( V_488 L_5 ,
V_83 -> V_334 , & V_25 -> V_41 ) ;
V_337 = F_62 ( sizeof *V_337 , V_23 ) ;
if ( ! V_337 )
return - V_108 ;
F_210 ( & V_337 -> V_337 , F_208 ) ;
V_337 -> V_41 = V_25 ;
V_337 -> V_2 . V_2 = V_489 ;
F_19 ( & V_25 -> V_40 ) ;
F_201 ( V_342 , & V_337 -> V_337 ) ;
}
return 0 ;
}
static int F_305 ( struct V_490 * V_491 , unsigned long V_2 ,
void * V_492 )
{
struct V_82 * V_83 = F_306 ( V_492 ) ;
struct V_38 * V_39 ;
struct V_24 * V_25 ;
int V_29 = V_493 ;
if ( V_2 != V_494 )
return V_493 ;
if ( ! ( V_83 -> V_28 & V_495 ) || ! ( V_83 -> V_368 & V_496 ) )
return V_493 ;
F_29 ( & V_30 ) ;
F_54 (cma_dev, &dev_list, list)
F_54 (id_priv, &cma_dev->id_list, list) {
V_29 = F_304 ( V_83 , V_25 ) ;
if ( V_29 )
goto V_91;
}
V_91:
F_31 ( & V_30 ) ;
return V_29 ;
}
static void F_307 ( struct V_77 * V_42 )
{
struct V_38 * V_39 ;
struct V_24 * V_25 ;
V_39 = F_176 ( sizeof *V_39 , V_23 ) ;
if ( ! V_39 )
return;
V_39 -> V_42 = V_42 ;
F_67 ( & V_39 -> V_27 ) ;
F_68 ( & V_39 -> V_40 , 1 ) ;
F_69 ( & V_39 -> V_49 ) ;
F_308 ( V_42 , & V_497 , V_39 ) ;
F_29 ( & V_30 ) ;
F_21 ( & V_39 -> V_48 , & V_498 ) ;
F_54 (id_priv, &listen_any_list, list)
F_196 ( V_25 , V_39 ) ;
F_31 ( & V_30 ) ;
}
static int F_309 ( struct V_24 * V_25 )
{
struct V_254 V_2 ;
enum V_26 V_31 ;
int V_29 = 0 ;
V_31 = F_15 ( V_25 , V_364 ) ;
if ( V_31 == V_249 )
return 0 ;
F_156 ( V_25 , V_31 ) ;
F_29 ( & V_25 -> V_102 ) ;
if ( ! F_11 ( V_25 , V_364 ) )
goto V_91;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_499 ;
V_29 = V_25 -> V_41 . V_104 ( & V_25 -> V_41 , & V_2 ) ;
V_91:
F_31 ( & V_25 -> V_102 ) ;
return V_29 ;
}
static void F_310 ( struct V_38 * V_39 )
{
struct V_24 * V_25 ;
int V_29 ;
F_29 ( & V_30 ) ;
while ( ! F_152 ( & V_39 -> V_49 ) ) {
V_25 = F_153 ( V_39 -> V_49 . V_243 ,
struct V_24 , V_48 ) ;
F_30 ( & V_25 -> V_113 ) ;
F_154 ( & V_25 -> V_48 ) ;
F_19 ( & V_25 -> V_40 ) ;
F_31 ( & V_30 ) ;
V_29 = V_25 -> V_250 ? 1 : F_309 ( V_25 ) ;
F_59 ( V_25 ) ;
if ( V_29 )
F_155 ( & V_25 -> V_41 ) ;
F_29 ( & V_30 ) ;
}
F_31 ( & V_30 ) ;
F_22 ( V_39 ) ;
F_167 ( & V_39 -> V_27 ) ;
}
static void F_311 ( struct V_77 * V_42 , void * V_500 )
{
struct V_38 * V_39 = V_500 ;
if ( ! V_39 )
return;
F_29 ( & V_30 ) ;
F_30 ( & V_39 -> V_48 ) ;
F_31 ( & V_30 ) ;
F_310 ( V_39 ) ;
F_27 ( V_39 ) ;
}
static int F_312 ( struct V_501 * V_502 , struct V_503 * V_504 )
{
struct V_505 * V_506 ;
struct V_507 * V_508 ;
struct V_24 * V_25 ;
struct V_103 * V_41 = NULL ;
struct V_38 * V_39 ;
int V_509 = 0 , V_510 = 0 ;
F_29 ( & V_30 ) ;
F_54 (cma_dev, &dev_list, list) {
if ( V_509 < V_504 -> args [ 0 ] ) {
V_509 ++ ;
continue;
}
V_510 = 0 ;
F_54 (id_priv, &cma_dev->id_list, list) {
if ( V_510 < V_504 -> args [ 1 ] ) {
V_510 ++ ;
continue;
}
V_508 = F_313 ( V_502 , & V_506 , V_504 -> V_506 -> V_511 ,
sizeof *V_508 , V_512 ,
V_513 ,
V_514 ) ;
if ( ! V_508 )
goto V_91;
memset ( V_508 , 0 , sizeof *V_508 ) ;
V_41 = & V_25 -> V_41 ;
V_508 -> V_47 = V_41 -> V_43 . V_44 . V_45 . V_70 ;
V_508 -> V_66 = V_41 -> V_66 ;
V_508 -> V_90 =
V_41 -> V_43 . V_44 . V_45 . V_90 ;
if ( F_314 ( V_502 , V_506 ,
F_187 ( F_32 ( V_25 ) ) ,
F_32 ( V_25 ) ,
V_515 ) )
goto V_91;
if ( F_314 ( V_502 , V_506 ,
F_187 ( F_32 ( V_25 ) ) ,
F_33 ( V_25 ) ,
V_516 ) )
goto V_91;
V_508 -> V_517 = V_25 -> V_109 ;
V_508 -> V_518 = V_41 -> V_10 ;
V_508 -> V_519 = V_25 -> V_31 ;
V_508 -> V_134 = V_25 -> V_134 ;
V_508 -> V_107 = V_41 -> V_107 ;
V_510 ++ ;
}
V_504 -> args [ 1 ] = 0 ;
V_509 ++ ;
}
V_91:
F_31 ( & V_30 ) ;
V_504 -> args [ 0 ] = V_509 ;
V_504 -> args [ 1 ] = V_510 ;
return V_502 -> V_520 ;
}
static int F_315 ( struct V_6 * V_6 )
{
struct V_5 * V_11 = V_5 ( V_6 ) ;
F_316 ( & V_11 -> V_13 ) ;
F_316 ( & V_11 -> V_15 ) ;
F_316 ( & V_11 -> V_17 ) ;
F_316 ( & V_11 -> V_19 ) ;
return 0 ;
}
static void F_317 ( struct V_6 * V_6 )
{
struct V_5 * V_11 = V_5 ( V_6 ) ;
F_318 ( & V_11 -> V_13 ) ;
F_318 ( & V_11 -> V_15 ) ;
F_318 ( & V_11 -> V_17 ) ;
F_318 ( & V_11 -> V_19 ) ;
}
static int T_13 F_319 ( void )
{
int V_29 ;
V_342 = F_320 ( L_6 ) ;
if ( ! V_342 )
return - V_108 ;
V_29 = F_321 ( & V_521 ) ;
if ( V_29 )
goto V_522;
F_322 ( & V_359 ) ;
F_323 ( & V_397 ) ;
F_324 ( & V_523 ) ;
V_29 = F_325 ( & V_497 ) ;
if ( V_29 )
goto V_133;
if ( F_326 ( V_512 , V_524 , V_525 ) )
F_174 ( V_333 L_7 ) ;
return 0 ;
V_133:
F_327 ( & V_523 ) ;
F_328 ( & V_397 ) ;
F_329 ( & V_359 ) ;
V_522:
F_330 ( V_342 ) ;
return V_29 ;
}
static void T_14 F_331 ( void )
{
F_332 ( V_512 ) ;
F_333 ( & V_497 ) ;
F_327 ( & V_523 ) ;
F_328 ( & V_397 ) ;
F_329 ( & V_359 ) ;
F_334 ( & V_521 ) ;
F_330 ( V_342 ) ;
}
