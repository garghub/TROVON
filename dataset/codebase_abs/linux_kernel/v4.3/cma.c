const char * F_1 ( enum V_1 V_2 )
{
T_1 V_3 = V_2 ;
return ( V_3 < F_2 ( V_4 ) && V_4 [ V_3 ] ) ?
V_4 [ V_3 ] : L_1 ;
}
static struct V_5 * F_3 ( enum V_6 V_7 )
{
switch ( V_7 ) {
case V_8 :
return & V_9 ;
case V_10 :
return & V_11 ;
case V_12 :
return & V_13 ;
case V_14 :
return & V_15 ;
default:
return NULL ;
}
}
static int F_4 ( enum V_6 V_7 ,
struct V_16 * V_17 , int V_18 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
return F_5 ( V_5 , V_17 , V_18 , V_18 + 1 , V_19 ) ;
}
static struct V_16 * F_6 ( enum V_6 V_7 , int V_18 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
return F_7 ( V_5 , V_18 ) ;
}
static void F_8 ( enum V_6 V_7 , int V_18 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
F_9 ( V_5 , V_18 ) ;
}
static int F_10 ( struct V_20 * V_21 , enum V_22 V_23 )
{
unsigned long V_24 ;
int V_25 ;
F_11 ( & V_21 -> V_26 , V_24 ) ;
V_25 = ( V_21 -> V_27 == V_23 ) ;
F_12 ( & V_21 -> V_26 , V_24 ) ;
return V_25 ;
}
static int F_13 ( struct V_20 * V_21 ,
enum V_22 V_23 , enum V_22 V_28 )
{
unsigned long V_24 ;
int V_25 ;
F_11 ( & V_21 -> V_26 , V_24 ) ;
if ( ( V_25 = ( V_21 -> V_27 == V_23 ) ) )
V_21 -> V_27 = V_28 ;
F_12 ( & V_21 -> V_26 , V_24 ) ;
return V_25 ;
}
static enum V_22 F_14 ( struct V_20 * V_21 ,
enum V_22 V_28 )
{
unsigned long V_24 ;
enum V_22 V_29 ;
F_11 ( & V_21 -> V_26 , V_24 ) ;
V_29 = V_21 -> V_27 ;
V_21 -> V_27 = V_28 ;
F_12 ( & V_21 -> V_26 , V_24 ) ;
return V_29 ;
}
static inline T_2 F_15 ( const struct V_30 * V_31 )
{
return V_31 -> V_32 >> 4 ;
}
static inline void F_16 ( struct V_30 * V_31 , T_2 V_33 )
{
V_31 -> V_32 = ( V_33 << 4 ) | ( V_31 -> V_32 & 0xF ) ;
}
static void F_17 ( struct V_20 * V_21 ,
struct V_34 * V_35 )
{
F_18 ( & V_35 -> V_36 ) ;
V_21 -> V_35 = V_35 ;
V_21 -> V_37 . V_38 = V_35 -> V_38 ;
V_21 -> V_37 . V_39 . V_40 . V_41 . V_42 =
F_19 ( V_35 -> V_38 -> V_43 ) ;
F_20 ( & V_21 -> V_44 , & V_35 -> V_45 ) ;
}
static inline void F_21 ( struct V_34 * V_35 )
{
if ( F_22 ( & V_35 -> V_36 ) )
F_23 ( & V_35 -> V_23 ) ;
}
static inline void F_24 ( struct V_46 * V_46 )
{
struct V_47 * V_48 = F_25 ( V_46 , struct V_47 , V_49 ) ;
F_26 ( V_48 -> V_50 . V_51 ) ;
F_26 ( V_48 ) ;
}
static void F_27 ( struct V_20 * V_21 )
{
F_28 ( & V_26 ) ;
F_29 ( & V_21 -> V_44 ) ;
F_21 ( V_21 -> V_35 ) ;
V_21 -> V_35 = NULL ;
F_30 ( & V_26 ) ;
}
static inline struct V_52 * F_31 ( struct V_20 * V_21 )
{
return (struct V_52 * ) & V_21 -> V_37 . V_39 . V_40 . V_53 ;
}
static inline struct V_52 * F_32 ( struct V_20 * V_21 )
{
return (struct V_52 * ) & V_21 -> V_37 . V_39 . V_40 . V_54 ;
}
static inline unsigned short F_33 ( struct V_20 * V_21 )
{
return V_21 -> V_37 . V_39 . V_40 . V_53 . V_55 ;
}
static int F_34 ( struct V_20 * V_21 , T_3 V_56 )
{
struct V_57 V_58 ;
int V_25 = 0 ;
if ( V_21 -> V_56 ) {
if ( V_56 && V_21 -> V_56 != V_56 )
return - V_59 ;
return 0 ;
}
if ( V_56 ) {
V_21 -> V_56 = V_56 ;
return 0 ;
}
switch ( V_21 -> V_37 . V_7 ) {
case V_10 :
case V_14 :
V_21 -> V_56 = V_60 ;
break;
case V_12 :
F_35 ( & V_21 -> V_37 . V_39 . V_40 . V_41 , & V_58 . V_61 ) ;
V_25 = F_36 ( V_21 -> V_37 . V_38 ,
V_21 -> V_37 . V_62 , & V_58 . V_61 ,
& V_58 ) ;
if ( ! V_25 )
V_21 -> V_56 = F_37 ( V_58 . V_56 ) ;
break;
default:
break;
}
return V_25 ;
}
static void F_38 ( struct V_63 * V_64 , struct V_65 * V_41 )
{
V_41 -> V_66 = V_67 ;
F_39 ( V_41 , (union V_68 * ) & V_64 -> V_69 ) ;
F_40 ( V_41 , F_41 ( V_64 -> V_70 ) ) ;
}
static int F_42 ( struct V_52 * V_40 , struct V_65 * V_41 )
{
int V_25 ;
if ( V_40 -> V_71 != V_72 ) {
V_25 = F_43 ( V_40 , V_41 , NULL ) ;
} else {
F_38 ( (struct V_63 * ) V_40 , V_41 ) ;
V_25 = 0 ;
}
return V_25 ;
}
static inline int F_44 ( struct V_73 * V_38 , T_2 V_74 ,
union V_68 * V_75 , int V_66 )
{
T_2 V_76 ;
int V_25 = - V_77 ;
if ( ( V_66 == V_67 ) && ! F_45 ( V_38 , V_74 ) )
return V_25 ;
if ( ( V_66 != V_67 ) && F_45 ( V_38 , V_74 ) )
return V_25 ;
V_25 = F_46 ( V_38 , V_75 , & V_76 , NULL ) ;
if ( V_74 != V_76 )
return - V_77 ;
return V_25 ;
}
static int F_47 ( struct V_20 * V_21 ,
struct V_20 * V_78 )
{
struct V_65 * V_41 = & V_21 -> V_37 . V_39 . V_40 . V_41 ;
struct V_34 * V_35 ;
union V_68 V_75 , V_79 , * V_80 ;
int V_25 = - V_77 ;
T_2 V_74 ;
if ( V_41 -> V_66 != V_67 &&
V_21 -> V_37 . V_7 == V_12 )
return - V_59 ;
F_28 ( & V_26 ) ;
F_48 ( (struct V_52 * ) & V_21 -> V_37 . V_39 . V_40 . V_53 ,
& V_79 ) ;
memcpy ( & V_75 , V_41 -> V_81 +
F_49 ( V_41 ) , sizeof V_75 ) ;
if ( V_78 ) {
V_35 = V_78 -> V_35 ;
V_74 = V_78 -> V_37 . V_62 ;
V_80 = F_50 ( V_35 -> V_38 , V_74 ) ?
& V_79 : & V_75 ;
V_25 = F_44 ( V_35 -> V_38 , V_74 , V_80 ,
V_41 -> V_66 ) ;
if ( ! V_25 ) {
V_21 -> V_37 . V_62 = V_74 ;
goto V_82;
}
}
F_51 (cma_dev, &dev_list, list) {
for ( V_74 = 1 ; V_74 <= V_35 -> V_38 -> V_83 ; ++ V_74 ) {
if ( V_78 &&
V_78 -> V_35 == V_35 &&
V_78 -> V_37 . V_62 == V_74 )
continue;
V_80 = F_50 ( V_35 -> V_38 , V_74 ) ?
& V_79 : & V_75 ;
V_25 = F_44 ( V_35 -> V_38 , V_74 , V_80 ,
V_41 -> V_66 ) ;
if ( ! V_25 ) {
V_21 -> V_37 . V_62 = V_74 ;
goto V_82;
}
}
}
V_82:
if ( ! V_25 )
F_17 ( V_21 , V_35 ) ;
F_30 ( & V_26 ) ;
return V_25 ;
}
static int F_52 ( struct V_20 * V_21 )
{
struct V_34 * V_35 , * V_84 ;
struct V_63 * V_40 ;
union V_68 V_75 , V_85 , * V_86 ;
T_4 V_87 , V_3 ;
T_2 V_88 ;
int V_89 ;
V_35 = NULL ;
V_40 = (struct V_63 * ) F_32 ( V_21 ) ;
V_86 = (union V_68 * ) & V_40 -> V_69 ;
V_87 = F_41 ( V_40 -> V_70 ) ;
F_51 (cur_dev, &dev_list, list) {
for ( V_88 = 1 ; V_88 <= V_84 -> V_38 -> V_83 ; ++ V_88 ) {
if ( ! F_53 ( V_84 -> V_38 , V_88 ) )
continue;
if ( F_54 ( V_84 -> V_38 , V_88 , V_87 , & V_3 ) )
continue;
for ( V_89 = 0 ; ! F_55 ( V_84 -> V_38 , V_88 , V_89 , & V_75 ) ; V_89 ++ ) {
if ( ! memcmp ( & V_75 , V_86 , sizeof( V_75 ) ) ) {
V_35 = V_84 ;
V_85 = V_75 ;
V_21 -> V_37 . V_62 = V_88 ;
goto V_90;
}
if ( ! V_35 && ( V_75 . V_91 . V_92 ==
V_86 -> V_91 . V_92 ) ) {
V_35 = V_84 ;
V_85 = V_75 ;
V_21 -> V_37 . V_62 = V_88 ;
}
}
}
}
if ( ! V_35 )
return - V_77 ;
V_90:
F_17 ( V_21 , V_35 ) ;
V_40 = (struct V_63 * ) F_31 ( V_21 ) ;
memcpy ( & V_40 -> V_69 , & V_85 , sizeof V_85 ) ;
F_38 ( V_40 , & V_21 -> V_37 . V_39 . V_40 . V_41 ) ;
return 0 ;
}
static void F_56 ( struct V_20 * V_21 )
{
if ( F_22 ( & V_21 -> V_36 ) )
F_23 ( & V_21 -> V_23 ) ;
}
static int F_57 ( struct V_20 * V_21 ,
enum V_22 V_27 )
{
F_28 ( & V_21 -> V_93 ) ;
if ( V_21 -> V_27 != V_27 ) {
F_30 ( & V_21 -> V_93 ) ;
return - V_59 ;
}
return 0 ;
}
struct V_94 * F_58 ( T_5 V_95 ,
void * V_96 , enum V_6 V_7 ,
enum V_97 V_98 )
{
struct V_20 * V_21 ;
V_21 = F_59 ( sizeof *V_21 , V_19 ) ;
if ( ! V_21 )
return F_60 ( - V_99 ) ;
V_21 -> V_100 = F_61 ( V_101 ) ;
V_21 -> V_27 = V_102 ;
V_21 -> V_37 . V_96 = V_96 ;
V_21 -> V_37 . V_95 = V_95 ;
V_21 -> V_37 . V_7 = V_7 ;
V_21 -> V_37 . V_98 = V_98 ;
F_62 ( & V_21 -> V_26 ) ;
F_63 ( & V_21 -> V_103 ) ;
F_64 ( & V_21 -> V_23 ) ;
F_65 ( & V_21 -> V_36 , 1 ) ;
F_63 ( & V_21 -> V_93 ) ;
F_66 ( & V_21 -> V_104 ) ;
F_66 ( & V_21 -> V_105 ) ;
F_67 ( & V_21 -> V_106 , sizeof V_21 -> V_106 ) ;
return & V_21 -> V_37 ;
}
static int F_68 ( struct V_20 * V_21 , struct V_107 * V_108 )
{
struct V_109 V_110 ;
int V_111 , V_25 ;
V_110 . V_112 = V_113 ;
V_25 = F_69 ( & V_21 -> V_37 , & V_110 , & V_111 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_70 ( V_108 , & V_110 , V_111 ) ;
if ( V_25 )
return V_25 ;
V_110 . V_112 = V_114 ;
V_25 = F_70 ( V_108 , & V_110 , V_115 ) ;
if ( V_25 )
return V_25 ;
V_110 . V_112 = V_116 ;
V_110 . V_117 = 0 ;
V_25 = F_70 ( V_108 , & V_110 , V_115 | V_118 ) ;
return V_25 ;
}
static int F_71 ( struct V_20 * V_21 , struct V_107 * V_108 )
{
struct V_109 V_110 ;
int V_111 , V_25 ;
V_110 . V_112 = V_113 ;
V_25 = F_69 ( & V_21 -> V_37 , & V_110 , & V_111 ) ;
if ( V_25 )
return V_25 ;
return F_70 ( V_108 , & V_110 , V_111 ) ;
}
int F_72 ( struct V_94 * V_37 , struct V_119 * V_120 ,
struct V_121 * V_122 )
{
struct V_20 * V_21 ;
struct V_107 * V_108 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( V_37 -> V_38 != V_120 -> V_38 )
return - V_59 ;
V_108 = F_73 ( V_120 , V_122 ) ;
if ( F_74 ( V_108 ) )
return F_75 ( V_108 ) ;
if ( V_37 -> V_98 == V_123 )
V_25 = F_68 ( V_21 , V_108 ) ;
else
V_25 = F_71 ( V_21 , V_108 ) ;
if ( V_25 )
goto V_124;
V_37 -> V_108 = V_108 ;
V_21 -> V_125 = V_108 -> V_125 ;
V_21 -> V_126 = ( V_108 -> V_126 != NULL ) ;
return 0 ;
V_124:
F_76 ( V_108 ) ;
return V_25 ;
}
void F_77 ( struct V_94 * V_37 )
{
struct V_20 * V_21 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
F_28 ( & V_21 -> V_103 ) ;
F_76 ( V_21 -> V_37 . V_108 ) ;
V_21 -> V_37 . V_108 = NULL ;
F_30 ( & V_21 -> V_103 ) ;
}
static int F_78 ( struct V_20 * V_21 ,
struct V_127 * V_128 )
{
struct V_109 V_110 ;
int V_111 , V_25 ;
union V_68 V_85 ;
F_28 ( & V_21 -> V_103 ) ;
if ( ! V_21 -> V_37 . V_108 ) {
V_25 = 0 ;
goto V_82;
}
V_110 . V_112 = V_113 ;
V_25 = F_69 ( & V_21 -> V_37 , & V_110 , & V_111 ) ;
if ( V_25 )
goto V_82;
V_25 = F_70 ( V_21 -> V_37 . V_108 , & V_110 , V_111 ) ;
if ( V_25 )
goto V_82;
V_110 . V_112 = V_114 ;
V_25 = F_69 ( & V_21 -> V_37 , & V_110 , & V_111 ) ;
if ( V_25 )
goto V_82;
V_25 = F_79 ( V_21 -> V_37 . V_38 , V_21 -> V_37 . V_62 ,
V_110 . V_129 . V_130 . V_131 , & V_85 ) ;
if ( V_25 )
goto V_82;
F_80 ( V_21 -> V_35 -> V_38 != V_21 -> V_37 . V_38 ) ;
if ( F_50 ( V_21 -> V_37 . V_38 , V_21 -> V_37 . V_62 ) ) {
V_25 = F_81 ( & V_85 , V_110 . V_132 , NULL ) ;
if ( V_25 )
goto V_82;
}
if ( V_128 )
V_110 . V_133 = V_128 -> V_134 ;
V_25 = F_70 ( V_21 -> V_37 . V_108 , & V_110 , V_111 ) ;
V_82:
F_30 ( & V_21 -> V_103 ) ;
return V_25 ;
}
static int F_82 ( struct V_20 * V_21 ,
struct V_127 * V_128 )
{
struct V_109 V_110 ;
int V_111 , V_25 ;
F_28 ( & V_21 -> V_103 ) ;
if ( ! V_21 -> V_37 . V_108 ) {
V_25 = 0 ;
goto V_82;
}
V_110 . V_112 = V_116 ;
V_25 = F_69 ( & V_21 -> V_37 , & V_110 , & V_111 ) ;
if ( V_25 )
goto V_82;
if ( V_128 )
V_110 . V_135 = V_128 -> V_136 ;
V_25 = F_70 ( V_21 -> V_37 . V_108 , & V_110 , V_111 ) ;
V_82:
F_30 ( & V_21 -> V_103 ) ;
return V_25 ;
}
static int F_83 ( struct V_20 * V_21 )
{
struct V_109 V_110 ;
int V_25 ;
F_28 ( & V_21 -> V_103 ) ;
if ( ! V_21 -> V_37 . V_108 ) {
V_25 = 0 ;
goto V_82;
}
V_110 . V_112 = V_137 ;
V_25 = F_70 ( V_21 -> V_37 . V_108 , & V_110 , V_115 ) ;
V_82:
F_30 ( & V_21 -> V_103 ) ;
return V_25 ;
}
static int F_84 ( struct V_20 * V_21 ,
struct V_109 * V_110 , int * V_111 )
{
struct V_65 * V_41 = & V_21 -> V_37 . V_39 . V_40 . V_41 ;
int V_25 ;
T_4 V_87 ;
if ( F_85 ( V_21 -> V_37 . V_38 , V_21 -> V_37 . V_62 ) )
V_87 = 0xffff ;
else
V_87 = F_86 ( V_41 ) ;
V_25 = F_54 ( V_21 -> V_37 . V_38 , V_21 -> V_37 . V_62 ,
V_87 , & V_110 -> V_138 ) ;
if ( V_25 )
return V_25 ;
V_110 -> V_62 = V_21 -> V_37 . V_62 ;
* V_111 = V_115 | V_139 | V_140 ;
if ( V_21 -> V_37 . V_98 == V_123 ) {
V_25 = F_34 ( V_21 , 0 ) ;
if ( V_25 )
return V_25 ;
V_110 -> V_56 = V_21 -> V_56 ;
* V_111 |= V_141 ;
} else {
V_110 -> V_142 = 0 ;
* V_111 |= V_143 ;
}
return 0 ;
}
int F_69 ( struct V_94 * V_37 , struct V_109 * V_110 ,
int * V_111 )
{
struct V_20 * V_21 ;
int V_25 = 0 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( F_87 ( V_37 -> V_38 , V_37 -> V_62 ) ) {
if ( ! V_21 -> V_144 . V_51 || ( V_21 -> V_37 . V_98 == V_123 ) )
V_25 = F_84 ( V_21 , V_110 , V_111 ) ;
else
V_25 = F_88 ( V_21 -> V_144 . V_51 , V_110 ,
V_111 ) ;
if ( V_110 -> V_112 == V_114 )
V_110 -> V_145 = V_21 -> V_106 ;
} else if ( F_89 ( V_37 -> V_38 , V_37 -> V_62 ) ) {
if ( ! V_21 -> V_144 . V_146 ) {
V_110 -> V_142 = 0 ;
* V_111 = V_115 | V_143 ;
} else
V_25 = F_90 ( V_21 -> V_144 . V_146 , V_110 ,
V_111 ) ;
} else
V_25 = - V_147 ;
return V_25 ;
}
static inline int F_91 ( struct V_52 * V_40 )
{
switch ( V_40 -> V_71 ) {
case V_148 :
return F_92 ( ( (struct V_149 * ) V_40 ) -> V_150 . V_151 ) ;
case V_152 :
return F_93 ( & ( (struct V_153 * ) V_40 ) -> V_154 ) ;
case V_72 :
return F_94 ( & ( (struct V_63 * ) V_40 ) -> V_69 ) ;
default:
return 0 ;
}
}
static inline int F_95 ( struct V_52 * V_40 )
{
switch ( V_40 -> V_71 ) {
case V_148 :
return F_96 ( ( (struct V_149 * ) V_40 ) -> V_150 . V_151 ) ;
case V_152 :
return F_97 ( & ( (struct V_153 * ) V_40 ) -> V_154 ) ;
case V_72 :
return F_98 ( & ( (struct V_63 * ) V_40 ) -> V_69 ) ;
default:
return 0 ;
}
}
static inline int F_99 ( struct V_52 * V_40 )
{
return F_91 ( V_40 ) || F_95 ( V_40 ) ;
}
static int F_100 ( struct V_52 * V_155 , struct V_52 * V_156 )
{
if ( V_155 -> V_71 != V_156 -> V_71 )
return - 1 ;
switch ( V_155 -> V_71 ) {
case V_148 :
return ( (struct V_149 * ) V_155 ) -> V_150 . V_151 !=
( (struct V_149 * ) V_156 ) -> V_150 . V_151 ;
case V_152 :
return F_101 ( & ( (struct V_153 * ) V_155 ) -> V_154 ,
& ( (struct V_153 * ) V_156 ) -> V_154 ) ;
default:
return F_102 ( & ( (struct V_63 * ) V_155 ) -> V_69 ,
& ( (struct V_63 * ) V_156 ) -> V_69 ) ;
}
}
static T_6 F_103 ( struct V_52 * V_40 )
{
struct V_63 * V_64 ;
switch ( V_40 -> V_71 ) {
case V_148 :
return ( (struct V_149 * ) V_40 ) -> V_157 ;
case V_152 :
return ( (struct V_153 * ) V_40 ) -> V_158 ;
case V_72 :
V_64 = (struct V_63 * ) V_40 ;
return F_104 ( ( T_4 ) ( F_105 ( V_64 -> V_159 ) &
F_105 ( V_64 -> V_160 ) ) ) ;
default:
return 0 ;
}
}
static inline int F_106 ( struct V_52 * V_40 )
{
return ! F_103 ( V_40 ) ;
}
static void F_107 ( struct V_52 * V_53 ,
struct V_52 * V_54 ,
struct V_94 * V_161 ,
struct V_162 * V_163 )
{
struct V_63 * V_164 , * V_51 ;
V_164 = (struct V_63 * ) & V_161 -> V_39 . V_40 . V_53 ;
if ( V_53 ) {
V_51 = (struct V_63 * ) V_53 ;
V_51 -> V_165 = V_72 ;
if ( V_163 ) {
V_51 -> V_70 = V_163 -> V_87 ;
V_51 -> V_166 = V_163 -> V_167 ;
memcpy ( & V_51 -> V_69 , & V_163 -> V_85 , 16 ) ;
V_51 -> V_159 = V_163 -> V_168 ;
V_51 -> V_169 = 0 ;
} else {
V_51 -> V_70 = V_164 -> V_70 ;
V_51 -> V_166 = V_164 -> V_166 ;
V_51 -> V_69 = V_164 -> V_69 ;
V_51 -> V_159 = V_164 -> V_159 ;
V_51 -> V_169 = V_164 -> V_169 ;
}
V_51 -> V_160 = F_108 ( 0xffffffffffffffffULL ) ;
}
if ( V_54 ) {
V_51 = (struct V_63 * ) V_54 ;
V_51 -> V_165 = V_72 ;
if ( V_163 ) {
V_51 -> V_70 = V_163 -> V_87 ;
V_51 -> V_166 = V_163 -> V_167 ;
memcpy ( & V_51 -> V_69 , & V_163 -> V_86 , 16 ) ;
}
}
}
static void F_109 ( struct V_52 * V_53 ,
struct V_52 * V_54 ,
struct V_30 * V_31 ,
T_6 V_170 )
{
struct V_149 * V_171 ;
if ( V_53 ) {
V_171 = (struct V_149 * ) V_53 ;
V_171 -> V_172 = V_148 ;
V_171 -> V_150 . V_151 = V_31 -> V_54 . V_171 . V_40 ;
V_171 -> V_157 = V_170 ;
}
if ( V_54 ) {
V_171 = (struct V_149 * ) V_54 ;
V_171 -> V_172 = V_148 ;
V_171 -> V_150 . V_151 = V_31 -> V_53 . V_171 . V_40 ;
V_171 -> V_157 = V_31 -> V_74 ;
}
}
static void F_110 ( struct V_52 * V_53 ,
struct V_52 * V_54 ,
struct V_30 * V_31 ,
T_6 V_170 )
{
struct V_153 * V_173 ;
if ( V_53 ) {
V_173 = (struct V_153 * ) V_53 ;
V_173 -> V_174 = V_152 ;
V_173 -> V_154 = V_31 -> V_54 . V_173 ;
V_173 -> V_158 = V_170 ;
}
if ( V_54 ) {
V_173 = (struct V_153 * ) V_54 ;
V_173 -> V_174 = V_152 ;
V_173 -> V_154 = V_31 -> V_53 . V_173 ;
V_173 -> V_158 = V_31 -> V_74 ;
}
}
static T_4 F_111 ( T_7 V_168 )
{
return ( T_4 ) F_105 ( V_168 ) ;
}
static int F_112 ( struct V_52 * V_53 ,
struct V_52 * V_54 ,
struct V_175 * V_176 ,
T_7 V_168 )
{
struct V_30 * V_31 ;
T_6 V_74 ;
V_31 = V_176 -> V_177 ;
if ( V_31 -> V_178 != V_179 )
return - V_59 ;
V_74 = F_104 ( F_111 ( V_168 ) ) ;
switch ( F_15 ( V_31 ) ) {
case 4 :
F_109 ( V_53 , V_54 , V_31 , V_74 ) ;
break;
case 6 :
F_110 ( V_53 , V_54 , V_31 , V_74 ) ;
break;
default:
return - V_180 ;
}
return 0 ;
}
static int F_113 ( struct V_52 * V_53 ,
struct V_52 * V_54 ,
struct V_94 * V_161 ,
struct V_175 * V_176 ,
T_8 V_71 , T_7 V_168 )
{
if ( V_71 == V_72 ) {
if ( V_176 -> V_2 == V_181 )
F_107 ( V_53 , V_54 , V_161 ,
V_176 -> V_182 . V_183 . V_184 ) ;
else if ( V_176 -> V_2 == V_185 )
F_107 ( V_53 , V_54 , V_161 , NULL ) ;
return 0 ;
}
return F_112 ( V_53 , V_54 , V_176 , V_168 ) ;
}
static int F_114 ( const struct V_175 * V_176 ,
struct V_186 * V_187 )
{
const struct V_188 * V_189 =
& V_176 -> V_182 . V_183 ;
const struct V_190 * V_191 =
& V_176 -> V_182 . V_192 ;
switch ( V_176 -> V_2 ) {
case V_181 :
V_187 -> V_38 = V_189 -> V_161 -> V_38 ;
V_187 -> V_74 = V_189 -> V_74 ;
memcpy ( & V_187 -> V_193 , & V_189 -> V_184 -> V_85 ,
sizeof( V_187 -> V_193 ) ) ;
V_187 -> V_194 = true ;
V_187 -> V_168 = V_189 -> V_184 -> V_168 ;
V_187 -> V_87 = F_115 ( V_189 -> V_184 -> V_87 ) ;
break;
case V_185 :
V_187 -> V_38 = V_191 -> V_161 -> V_38 ;
V_187 -> V_74 = V_191 -> V_74 ;
V_187 -> V_194 = false ;
V_187 -> V_168 = V_191 -> V_168 ;
V_187 -> V_87 = V_191 -> V_87 ;
break;
default:
return - V_59 ;
}
return 0 ;
}
static bool F_116 ( struct V_195 * V_196 ,
const struct V_149 * V_54 ,
const struct V_149 * V_53 )
{
T_9 V_197 = V_54 -> V_150 . V_151 ,
V_198 = V_53 -> V_150 . V_151 ;
struct V_199 V_200 ;
struct V_201 V_202 ;
int V_124 ;
bool V_25 ;
if ( F_117 ( V_198 ) || F_118 ( V_198 ) ||
F_118 ( V_197 ) || F_92 ( V_198 ) ||
F_92 ( V_197 ) || F_96 ( V_197 ) ||
F_96 ( V_198 ) )
return false ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_203 = V_196 -> V_204 ;
V_202 . V_197 = V_197 ;
V_202 . V_198 = V_198 ;
F_119 () ;
V_124 = F_120 ( F_121 ( V_196 ) , & V_202 , & V_200 , 0 ) ;
if ( V_124 )
return false ;
V_25 = F_122 ( V_200 ) == V_196 ;
F_123 () ;
return V_25 ;
}
static bool F_124 ( struct V_195 * V_196 ,
const struct V_153 * V_54 ,
const struct V_153 * V_53 )
{
#if F_125 ( V_205 )
const int V_206 = F_126 ( & V_54 -> V_154 ) &
V_207 ;
struct V_208 * V_209 = F_127 ( F_121 ( V_196 ) , & V_54 -> V_154 ,
& V_53 -> V_154 , V_196 -> V_204 ,
V_206 ) ;
bool V_25 ;
if ( ! V_209 )
return false ;
V_25 = V_209 -> V_210 -> V_211 == V_196 ;
F_128 ( V_209 ) ;
return V_25 ;
#else
return false ;
#endif
}
static bool F_129 ( struct V_195 * V_196 ,
const struct V_52 * V_197 ,
const struct V_52 * V_198 )
{
const struct V_149 * V_212 = ( const struct V_149 * ) V_197 ;
const struct V_149 * V_213 = ( const struct V_149 * ) V_198 ;
const struct V_153 * V_214 = ( const struct V_153 * ) V_197 ;
const struct V_153 * V_215 = ( const struct V_153 * ) V_198 ;
switch ( V_197 -> V_71 ) {
case V_148 :
return V_198 -> V_71 == V_148 &&
F_116 ( V_196 , V_212 , V_213 ) ;
case V_152 :
return V_198 -> V_71 == V_152 &&
F_124 ( V_196 , V_214 , V_215 ) ;
default:
return false ;
}
}
static struct V_195 * F_130 ( struct V_175 * V_176 ,
const struct V_186 * V_187 )
{
struct V_216 V_217 , V_218 ;
struct V_52 * V_219 = (struct V_52 * ) & V_217 ,
* V_53 = (struct V_52 * ) & V_218 ;
struct V_195 * V_196 ;
const union V_68 * V_75 = V_187 -> V_194 ? & V_187 -> V_193 : NULL ;
int V_124 ;
V_124 = F_112 ( V_219 , V_53 , V_176 ,
V_187 -> V_168 ) ;
if ( V_124 )
return F_60 ( V_124 ) ;
V_196 = F_131 ( V_187 -> V_38 , V_187 -> V_74 , V_187 -> V_87 ,
V_75 , V_219 ) ;
if ( ! V_196 )
return F_60 ( - V_77 ) ;
if ( ! F_129 ( V_196 , V_219 , V_53 ) ) {
F_132 ( V_196 ) ;
return F_60 ( - V_220 ) ;
}
return V_196 ;
}
static enum V_6 F_133 ( T_7 V_168 )
{
return ( F_105 ( V_168 ) >> 16 ) & 0xffff ;
}
static bool F_134 ( struct V_20 * V_21 ,
const struct V_30 * V_31 )
{
struct V_52 * V_40 = F_31 ( V_21 ) ;
T_9 V_221 ;
struct V_222 V_223 ;
if ( F_99 ( V_40 ) && ! V_21 -> V_224 )
return true ;
switch ( V_40 -> V_71 ) {
case V_148 :
V_221 = ( (struct V_149 * ) V_40 ) -> V_150 . V_151 ;
if ( F_15 ( V_31 ) != 4 )
return false ;
if ( ! F_99 ( V_40 ) &&
V_31 -> V_54 . V_171 . V_40 != V_221 )
return false ;
break;
case V_152 :
V_223 = ( (struct V_153 * ) V_40 ) -> V_154 ;
if ( F_15 ( V_31 ) != 6 )
return false ;
if ( ! F_99 ( V_40 ) &&
memcmp ( & V_31 -> V_54 . V_173 , & V_223 , sizeof( V_223 ) ) )
return false ;
break;
case V_72 :
return true ;
default:
return false ;
}
return true ;
}
static bool F_135 ( struct V_73 * V_38 , int V_62 )
{
enum V_225 V_226 = F_136 ( V_38 , V_62 ) ;
enum V_227 V_42 =
F_19 ( V_38 -> V_43 ) ;
return V_226 == V_228 && V_42 == V_229 ;
}
static bool F_137 ( const struct V_94 * V_37 )
{
struct V_73 * V_38 = V_37 -> V_38 ;
const int V_62 = V_37 -> V_62 ? : F_138 ( V_38 ) ;
return F_135 ( V_38 , V_62 ) ;
}
static bool F_139 ( const struct V_20 * V_21 ,
const struct V_195 * V_196 )
{
const struct V_230 * V_40 = & V_21 -> V_37 . V_39 . V_40 ;
if ( ! V_196 )
return V_40 -> V_53 . V_55 == V_72 ||
F_137 ( & V_21 -> V_37 ) ;
return ! V_40 -> V_41 . V_231 ||
( F_140 ( F_121 ( V_196 ) , & V_232 ) &&
V_40 -> V_41 . V_231 == V_196 -> V_204 ) ;
}
static struct V_20 * F_141 (
const struct V_16 * V_17 ,
const struct V_233 * V_144 ,
const struct V_175 * V_176 ,
const struct V_186 * V_187 ,
const struct V_195 * V_196 )
{
struct V_20 * V_21 , * V_234 ;
if ( ! V_17 )
return F_60 ( - V_59 ) ;
F_142 (id_priv, &bind_list->owners, node) {
if ( F_134 ( V_21 , V_176 -> V_177 ) ) {
if ( V_21 -> V_37 . V_38 == V_144 -> V_38 &&
F_139 ( V_21 , V_196 ) )
return V_21 ;
F_51 (id_priv_dev,
&id_priv->listen_list,
listen_list) {
if ( V_234 -> V_37 . V_38 == V_144 -> V_38 &&
F_139 ( V_234 , V_196 ) )
return V_234 ;
}
}
}
return F_60 ( - V_59 ) ;
}
static struct V_20 * F_143 ( struct V_233 * V_144 ,
struct V_175 * V_176 ,
struct V_195 * * V_196 )
{
struct V_186 V_187 ;
struct V_16 * V_17 ;
struct V_20 * V_21 ;
int V_124 ;
V_124 = F_114 ( V_176 , & V_187 ) ;
if ( V_124 )
return F_60 ( V_124 ) ;
* V_196 = F_130 ( V_176 , & V_187 ) ;
if ( F_74 ( * V_196 ) ) {
if ( F_75 ( * V_196 ) == - V_180 ) {
* V_196 = NULL ;
} else if ( F_135 ( V_187 . V_38 , V_187 . V_74 ) ) {
* V_196 = NULL ;
} else {
return F_144 ( * V_196 ) ;
}
}
V_17 = F_6 ( F_133 ( V_187 . V_168 ) ,
F_111 ( V_187 . V_168 ) ) ;
V_21 = F_141 ( V_17 , V_144 , V_176 , & V_187 , * V_196 ) ;
if ( F_74 ( V_21 ) && * V_196 ) {
F_132 ( * V_196 ) ;
* V_196 = NULL ;
}
return V_21 ;
}
static inline int F_145 ( struct V_20 * V_21 )
{
return F_33 ( V_21 ) == V_72 ? 0 : sizeof( struct V_30 ) ;
}
static void F_146 ( struct V_20 * V_21 )
{
if ( F_147 ( V_21 -> V_37 . V_38 , V_21 -> V_37 . V_62 ) ) {
if ( V_21 -> V_235 )
F_148 ( V_21 -> V_236 , V_21 -> V_235 ) ;
}
}
static void F_149 ( struct V_20 * V_21 )
{
struct V_20 * V_237 ;
F_28 ( & V_26 ) ;
F_29 ( & V_21 -> V_44 ) ;
while ( ! F_150 ( & V_21 -> V_104 ) ) {
V_237 = F_151 ( V_21 -> V_104 . V_238 ,
struct V_20 , V_104 ) ;
F_152 ( & V_237 -> V_44 ) ;
F_29 ( & V_237 -> V_104 ) ;
F_30 ( & V_26 ) ;
F_153 ( & V_237 -> V_37 ) ;
F_28 ( & V_26 ) ;
}
F_30 ( & V_26 ) ;
}
static void F_154 ( struct V_20 * V_21 ,
enum V_22 V_27 )
{
switch ( V_27 ) {
case V_239 :
F_155 ( & V_21 -> V_37 . V_39 . V_40 . V_41 ) ;
break;
case V_240 :
F_146 ( V_21 ) ;
break;
case V_241 :
if ( F_99 ( F_31 ( V_21 ) ) && ! V_21 -> V_35 )
F_149 ( V_21 ) ;
break;
default:
break;
}
}
static void F_156 ( struct V_20 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_17 ;
if ( ! V_17 )
return;
F_28 ( & V_26 ) ;
F_157 ( & V_21 -> V_242 ) ;
if ( F_158 ( & V_17 -> V_243 ) ) {
F_8 ( V_17 -> V_7 , V_17 -> V_74 ) ;
F_26 ( V_17 ) ;
}
F_30 ( & V_26 ) ;
}
static void F_159 ( struct V_20 * V_21 )
{
struct V_47 * V_48 ;
while ( ! F_150 ( & V_21 -> V_105 ) ) {
V_48 = F_25 ( V_21 -> V_105 . V_238 ,
struct V_47 , V_44 ) ;
F_29 ( & V_48 -> V_44 ) ;
if ( F_160 ( V_21 -> V_35 -> V_38 ,
V_21 -> V_37 . V_62 ) ) {
F_161 ( V_48 -> V_50 . V_51 ) ;
F_26 ( V_48 ) ;
} else
F_162 ( & V_48 -> V_49 , F_24 ) ;
}
}
void F_153 ( struct V_94 * V_37 )
{
struct V_20 * V_21 ;
enum V_22 V_27 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
V_27 = F_14 ( V_21 , V_244 ) ;
F_154 ( V_21 , V_27 ) ;
F_28 ( & V_21 -> V_93 ) ;
F_30 ( & V_21 -> V_93 ) ;
if ( V_21 -> V_35 ) {
if ( F_87 ( V_21 -> V_37 . V_38 , 1 ) ) {
if ( V_21 -> V_144 . V_51 )
F_163 ( V_21 -> V_144 . V_51 ) ;
} else if ( F_89 ( V_21 -> V_37 . V_38 , 1 ) ) {
if ( V_21 -> V_144 . V_146 )
F_164 ( V_21 -> V_144 . V_146 ) ;
}
F_159 ( V_21 ) ;
F_27 ( V_21 ) ;
}
F_156 ( V_21 ) ;
F_56 ( V_21 ) ;
F_165 ( & V_21 -> V_23 ) ;
if ( V_21 -> V_245 )
F_56 ( V_21 -> V_37 . V_96 ) ;
F_26 ( V_21 -> V_37 . V_39 . V_246 ) ;
F_26 ( V_21 ) ;
}
static int F_166 ( struct V_20 * V_21 )
{
int V_25 ;
V_25 = F_78 ( V_21 , NULL ) ;
if ( V_25 )
goto V_247;
V_25 = F_82 ( V_21 , NULL ) ;
if ( V_25 )
goto V_247;
V_25 = F_167 ( V_21 -> V_144 . V_51 , NULL , 0 ) ;
if ( V_25 )
goto V_247;
return 0 ;
V_247:
F_83 ( V_21 ) ;
F_168 ( V_21 -> V_144 . V_51 , V_248 ,
NULL , 0 , NULL , 0 ) ;
return V_25 ;
}
static void F_169 ( struct V_249 * V_2 ,
struct V_250 * V_251 ,
void * V_177 )
{
V_2 -> V_182 . V_252 . V_177 = V_177 ;
V_2 -> V_182 . V_252 . V_253 = V_254 ;
V_2 -> V_182 . V_252 . V_134 = V_251 -> V_134 ;
V_2 -> V_182 . V_252 . V_136 = V_251 -> V_136 ;
V_2 -> V_182 . V_252 . V_255 = V_251 -> V_255 ;
V_2 -> V_182 . V_252 . V_256 = V_251 -> V_256 ;
V_2 -> V_182 . V_252 . V_126 = V_251 -> V_126 ;
V_2 -> V_182 . V_252 . V_125 = V_251 -> V_257 ;
}
static int F_170 ( struct V_233 * V_144 , struct V_175 * V_176 )
{
struct V_20 * V_21 = V_144 -> V_96 ;
struct V_249 V_2 ;
int V_25 = 0 ;
if ( ( V_176 -> V_2 != V_258 &&
F_57 ( V_21 , V_259 ) ) ||
( V_176 -> V_2 == V_258 &&
F_57 ( V_21 , V_260 ) ) )
return 0 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_176 -> V_2 ) {
case V_261 :
case V_262 :
V_2 . V_2 = V_263 ;
V_2 . V_264 = - V_265 ;
break;
case V_266 :
if ( V_21 -> V_37 . V_108 ) {
V_2 . V_264 = F_166 ( V_21 ) ;
V_2 . V_2 = V_2 . V_264 ? V_267 :
V_268 ;
} else {
V_2 . V_2 = V_269 ;
}
F_169 ( & V_2 , & V_176 -> V_182 . V_270 ,
V_176 -> V_177 ) ;
break;
case V_271 :
case V_272 :
V_2 . V_2 = V_268 ;
break;
case V_273 :
V_2 . V_264 = - V_265 ;
case V_274 :
case V_275 :
if ( ! F_13 ( V_21 , V_259 ,
V_260 ) )
goto V_82;
V_2 . V_2 = V_276 ;
break;
case V_258 :
V_2 . V_2 = V_277 ;
break;
case V_278 :
goto V_82;
case V_279 :
F_83 ( V_21 ) ;
V_2 . V_264 = V_176 -> V_182 . V_280 . V_281 ;
V_2 . V_2 = V_282 ;
V_2 . V_182 . V_252 . V_177 = V_176 -> V_177 ;
V_2 . V_182 . V_252 . V_253 = V_283 ;
break;
default:
F_171 ( V_284 L_2 ,
V_176 -> V_2 ) ;
goto V_82;
}
V_25 = V_21 -> V_37 . V_95 ( & V_21 -> V_37 , & V_2 ) ;
if ( V_25 ) {
V_21 -> V_144 . V_51 = NULL ;
F_14 ( V_21 , V_244 ) ;
F_30 ( & V_21 -> V_93 ) ;
F_153 ( & V_21 -> V_37 ) ;
return V_25 ;
}
V_82:
F_30 ( & V_21 -> V_93 ) ;
return V_25 ;
}
static struct V_20 * F_172 ( struct V_94 * V_161 ,
struct V_175 * V_176 ,
struct V_195 * V_196 )
{
struct V_20 * V_21 ;
struct V_94 * V_37 ;
struct V_285 * V_209 ;
const T_8 V_55 = V_161 -> V_39 . V_40 . V_53 . V_55 ;
const T_7 V_168 =
V_176 -> V_182 . V_183 . V_184 -> V_168 ;
int V_25 ;
V_37 = F_58 ( V_161 -> V_95 , V_161 -> V_96 ,
V_161 -> V_7 , V_176 -> V_182 . V_183 . V_98 ) ;
if ( F_74 ( V_37 ) )
return NULL ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( F_113 ( (struct V_52 * ) & V_37 -> V_39 . V_40 . V_53 ,
(struct V_52 * ) & V_37 -> V_39 . V_40 . V_54 ,
V_161 , V_176 , V_55 , V_168 ) )
goto V_124;
V_209 = & V_37 -> V_39 ;
V_209 -> V_286 = V_176 -> V_182 . V_183 . V_287 ? 2 : 1 ;
V_209 -> V_246 = F_173 ( sizeof * V_209 -> V_246 * V_209 -> V_286 ,
V_19 ) ;
if ( ! V_209 -> V_246 )
goto V_124;
V_209 -> V_246 [ 0 ] = * V_176 -> V_182 . V_183 . V_184 ;
if ( V_209 -> V_286 == 2 )
V_209 -> V_246 [ 1 ] = * V_176 -> V_182 . V_183 . V_287 ;
if ( V_196 ) {
V_25 = F_174 ( & V_209 -> V_40 . V_41 , V_196 , NULL ) ;
if ( V_25 )
goto V_124;
} else {
if ( ! F_137 ( V_161 ) &&
F_99 ( F_31 ( V_21 ) ) ) {
V_209 -> V_40 . V_41 . V_66 = V_67 ;
F_39 ( & V_209 -> V_40 . V_41 , & V_209 -> V_246 [ 0 ] . V_85 ) ;
F_40 ( & V_209 -> V_40 . V_41 , F_115 ( V_209 -> V_246 [ 0 ] . V_87 ) ) ;
} else if ( ! F_99 ( F_31 ( V_21 ) ) ) {
V_25 = F_42 ( F_31 ( V_21 ) , & V_209 -> V_40 . V_41 ) ;
if ( V_25 )
goto V_124;
}
}
F_175 ( & V_209 -> V_40 . V_41 , & V_209 -> V_246 [ 0 ] . V_86 ) ;
V_21 -> V_27 = V_259 ;
return V_21 ;
V_124:
F_153 ( V_37 ) ;
return NULL ;
}
static struct V_20 * F_176 ( struct V_94 * V_161 ,
struct V_175 * V_176 ,
struct V_195 * V_196 )
{
struct V_20 * V_21 ;
struct V_94 * V_37 ;
const T_8 V_55 = V_161 -> V_39 . V_40 . V_53 . V_55 ;
int V_25 ;
V_37 = F_58 ( V_161 -> V_95 , V_161 -> V_96 ,
V_161 -> V_7 , V_123 ) ;
if ( F_74 ( V_37 ) )
return NULL ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( F_113 ( (struct V_52 * ) & V_37 -> V_39 . V_40 . V_53 ,
(struct V_52 * ) & V_37 -> V_39 . V_40 . V_54 ,
V_161 , V_176 , V_55 ,
V_176 -> V_182 . V_192 . V_168 ) )
goto V_124;
if ( V_196 ) {
V_25 = F_174 ( & V_37 -> V_39 . V_40 . V_41 , V_196 , NULL ) ;
if ( V_25 )
goto V_124;
} else {
if ( ! F_99 ( F_31 ( V_21 ) ) ) {
V_25 = F_42 ( F_31 ( V_21 ) ,
& V_37 -> V_39 . V_40 . V_41 ) ;
if ( V_25 )
goto V_124;
}
}
V_21 -> V_27 = V_259 ;
return V_21 ;
V_124:
F_153 ( V_37 ) ;
return NULL ;
}
static void F_177 ( struct V_249 * V_2 ,
struct V_188 * V_288 ,
void * V_177 , int V_289 )
{
V_2 -> V_182 . V_252 . V_177 = V_177 + V_289 ;
V_2 -> V_182 . V_252 . V_253 = V_290 - V_289 ;
V_2 -> V_182 . V_252 . V_134 = V_288 -> V_134 ;
V_2 -> V_182 . V_252 . V_136 = V_288 -> V_136 ;
V_2 -> V_182 . V_252 . V_255 = V_288 -> V_255 ;
V_2 -> V_182 . V_252 . V_291 = V_288 -> V_291 ;
V_2 -> V_182 . V_252 . V_256 = V_288 -> V_256 ;
V_2 -> V_182 . V_252 . V_126 = V_288 -> V_126 ;
V_2 -> V_182 . V_252 . V_125 = V_288 -> V_257 ;
}
static int F_178 ( struct V_94 * V_37 , struct V_175 * V_176 )
{
return ( ( ( V_176 -> V_2 == V_181 ) &&
( V_176 -> V_182 . V_183 . V_98 == V_37 -> V_98 ) ) ||
( ( V_176 -> V_2 == V_185 ) &&
( V_37 -> V_98 == V_123 ) ) ||
( ! V_37 -> V_98 ) ) ;
}
static int F_179 ( struct V_233 * V_144 , struct V_175 * V_176 )
{
struct V_20 * V_161 , * V_292 ;
struct V_249 V_2 ;
struct V_195 * V_196 ;
int V_289 , V_25 ;
V_161 = F_143 ( V_144 , V_176 , & V_196 ) ;
if ( F_74 ( V_161 ) )
return F_75 ( V_161 ) ;
if ( ! F_178 ( & V_161 -> V_37 , V_176 ) ) {
V_25 = - V_59 ;
goto V_293;
}
if ( F_57 ( V_161 , V_241 ) ) {
V_25 = - V_294 ;
goto V_293;
}
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_289 = F_145 ( V_161 ) ;
V_2 . V_2 = V_295 ;
if ( V_176 -> V_2 == V_185 ) {
V_292 = F_176 ( & V_161 -> V_37 , V_176 , V_196 ) ;
V_2 . V_182 . V_296 . V_177 = V_176 -> V_177 + V_289 ;
V_2 . V_182 . V_296 . V_253 =
V_297 - V_289 ;
} else {
V_292 = F_172 ( & V_161 -> V_37 , V_176 , V_196 ) ;
F_177 ( & V_2 , & V_176 -> V_182 . V_183 ,
V_176 -> V_177 , V_289 ) ;
}
if ( ! V_292 ) {
V_25 = - V_99 ;
goto V_298;
}
F_180 ( & V_292 -> V_93 , V_299 ) ;
V_25 = F_47 ( V_292 , V_161 ) ;
if ( V_25 )
goto V_300;
V_292 -> V_144 . V_51 = V_144 ;
V_144 -> V_96 = V_292 ;
V_144 -> V_301 = F_170 ;
F_18 ( & V_292 -> V_36 ) ;
V_25 = V_292 -> V_37 . V_95 ( & V_292 -> V_37 , & V_2 ) ;
if ( V_25 )
goto V_302;
F_28 ( & V_26 ) ;
if ( F_10 ( V_292 , V_259 ) &&
( V_292 -> V_37 . V_98 != V_123 ) )
F_181 ( V_144 , V_303 , NULL , 0 ) ;
F_30 ( & V_26 ) ;
F_30 ( & V_292 -> V_93 ) ;
F_30 ( & V_161 -> V_93 ) ;
F_56 ( V_292 ) ;
if ( V_196 )
F_132 ( V_196 ) ;
return 0 ;
V_302:
F_56 ( V_292 ) ;
V_292 -> V_144 . V_51 = NULL ;
V_300:
F_14 ( V_292 , V_244 ) ;
F_30 ( & V_292 -> V_93 ) ;
V_298:
F_30 ( & V_161 -> V_93 ) ;
if ( V_292 )
F_153 ( & V_292 -> V_37 ) ;
V_293:
if ( V_196 )
F_132 ( V_196 ) ;
return V_25 ;
}
T_7 F_182 ( struct V_94 * V_37 , struct V_52 * V_40 )
{
if ( V_40 -> V_71 == V_72 )
return ( (struct V_63 * ) V_40 ) -> V_159 ;
return F_108 ( ( ( V_304 ) V_37 -> V_7 << 16 ) + F_115 ( F_103 ( V_40 ) ) ) ;
}
static int F_183 ( struct V_305 * V_306 , struct V_307 * V_308 )
{
struct V_20 * V_21 = V_306 -> V_96 ;
struct V_249 V_2 ;
int V_25 = 0 ;
struct V_52 * V_309 = (struct V_52 * ) & V_308 -> V_310 ;
struct V_52 * V_311 = (struct V_52 * ) & V_308 -> V_312 ;
if ( F_57 ( V_21 , V_259 ) )
return 0 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_308 -> V_2 ) {
case V_313 :
V_2 . V_2 = V_276 ;
break;
case V_314 :
memcpy ( F_31 ( V_21 ) , V_309 ,
F_184 ( V_309 ) ) ;
memcpy ( F_32 ( V_21 ) , V_311 ,
F_184 ( V_311 ) ) ;
switch ( V_308 -> V_264 ) {
case 0 :
V_2 . V_2 = V_268 ;
V_2 . V_182 . V_252 . V_136 = V_308 -> V_315 ;
V_2 . V_182 . V_252 . V_134 = V_308 -> V_316 ;
break;
case - V_317 :
case - V_318 :
V_2 . V_2 = V_282 ;
break;
case - V_265 :
V_2 . V_2 = V_263 ;
break;
default:
V_2 . V_2 = V_267 ;
break;
}
break;
case V_319 :
V_2 . V_2 = V_268 ;
V_2 . V_182 . V_252 . V_136 = V_308 -> V_315 ;
V_2 . V_182 . V_252 . V_134 = V_308 -> V_316 ;
break;
default:
F_80 ( 1 ) ;
}
V_2 . V_264 = V_308 -> V_264 ;
V_2 . V_182 . V_252 . V_177 = V_308 -> V_177 ;
V_2 . V_182 . V_252 . V_253 = V_308 -> V_253 ;
V_25 = V_21 -> V_37 . V_95 ( & V_21 -> V_37 , & V_2 ) ;
if ( V_25 ) {
V_21 -> V_144 . V_146 = NULL ;
F_14 ( V_21 , V_244 ) ;
F_30 ( & V_21 -> V_93 ) ;
F_153 ( & V_21 -> V_37 ) ;
return V_25 ;
}
F_30 ( & V_21 -> V_93 ) ;
return V_25 ;
}
static int F_185 ( struct V_305 * V_144 ,
struct V_307 * V_308 )
{
struct V_94 * V_320 ;
struct V_20 * V_161 , * V_292 ;
struct V_249 V_2 ;
int V_25 ;
struct V_321 V_322 ;
struct V_52 * V_309 = (struct V_52 * ) & V_308 -> V_310 ;
struct V_52 * V_311 = (struct V_52 * ) & V_308 -> V_312 ;
V_161 = V_144 -> V_96 ;
if ( F_57 ( V_161 , V_241 ) )
return - V_294 ;
V_320 = F_58 ( V_161 -> V_37 . V_95 ,
V_161 -> V_37 . V_96 ,
V_8 , V_323 ) ;
if ( F_74 ( V_320 ) ) {
V_25 = - V_99 ;
goto V_82;
}
V_292 = F_25 ( V_320 , struct V_20 , V_37 ) ;
F_180 ( & V_292 -> V_93 , V_299 ) ;
V_292 -> V_27 = V_259 ;
V_25 = F_43 ( V_309 , & V_292 -> V_37 . V_39 . V_40 . V_41 , NULL ) ;
if ( V_25 ) {
F_30 ( & V_292 -> V_93 ) ;
F_153 ( V_320 ) ;
goto V_82;
}
V_25 = F_47 ( V_292 , V_161 ) ;
if ( V_25 ) {
F_30 ( & V_292 -> V_93 ) ;
F_153 ( V_320 ) ;
goto V_82;
}
V_292 -> V_144 . V_146 = V_144 ;
V_144 -> V_96 = V_292 ;
V_144 -> V_301 = F_183 ;
memcpy ( F_31 ( V_292 ) , V_309 , F_184 ( V_309 ) ) ;
memcpy ( F_32 ( V_292 ) , V_311 , F_184 ( V_311 ) ) ;
V_25 = F_186 ( V_292 -> V_37 . V_38 , & V_322 ) ;
if ( V_25 ) {
F_30 ( & V_292 -> V_93 ) ;
F_153 ( V_320 ) ;
goto V_82;
}
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_295 ;
V_2 . V_182 . V_252 . V_177 = V_308 -> V_177 ;
V_2 . V_182 . V_252 . V_253 = V_308 -> V_253 ;
V_2 . V_182 . V_252 . V_136 = V_308 -> V_315 ;
V_2 . V_182 . V_252 . V_134 = V_308 -> V_316 ;
F_18 ( & V_292 -> V_36 ) ;
V_25 = V_292 -> V_37 . V_95 ( & V_292 -> V_37 , & V_2 ) ;
if ( V_25 ) {
V_292 -> V_144 . V_146 = NULL ;
F_14 ( V_292 , V_244 ) ;
F_30 ( & V_292 -> V_93 ) ;
F_56 ( V_292 ) ;
F_153 ( & V_292 -> V_37 ) ;
goto V_82;
}
F_30 ( & V_292 -> V_93 ) ;
F_56 ( V_292 ) ;
V_82:
F_30 ( & V_161 -> V_93 ) ;
return V_25 ;
}
static int F_187 ( struct V_20 * V_21 )
{
struct V_52 * V_40 ;
struct V_233 * V_37 ;
T_7 V_324 ;
V_40 = F_31 ( V_21 ) ;
V_324 = F_182 ( & V_21 -> V_37 , V_40 ) ;
V_37 = F_188 ( V_21 -> V_37 . V_38 , F_179 , V_324 ) ;
if ( F_74 ( V_37 ) )
return F_75 ( V_37 ) ;
V_21 -> V_144 . V_51 = V_37 ;
return 0 ;
}
static int F_189 ( struct V_20 * V_21 , int V_325 )
{
int V_25 ;
struct V_305 * V_37 ;
V_37 = F_190 ( V_21 -> V_37 . V_38 ,
F_185 ,
V_21 ) ;
if ( F_74 ( V_37 ) )
return F_75 ( V_37 ) ;
V_37 -> V_326 = V_21 -> V_326 ;
V_21 -> V_144 . V_146 = V_37 ;
memcpy ( & V_21 -> V_144 . V_146 -> V_310 , F_31 ( V_21 ) ,
F_184 ( F_31 ( V_21 ) ) ) ;
V_25 = F_191 ( V_21 -> V_144 . V_146 , V_325 ) ;
if ( V_25 ) {
F_164 ( V_21 -> V_144 . V_146 ) ;
V_21 -> V_144 . V_146 = NULL ;
}
return V_25 ;
}
static int F_192 ( struct V_94 * V_37 ,
struct V_249 * V_2 )
{
struct V_20 * V_21 = V_37 -> V_96 ;
V_37 -> V_96 = V_21 -> V_37 . V_96 ;
V_37 -> V_95 = V_21 -> V_37 . V_95 ;
return V_21 -> V_37 . V_95 ( V_37 , V_2 ) ;
}
static void F_193 ( struct V_20 * V_21 ,
struct V_34 * V_35 )
{
struct V_20 * V_237 ;
struct V_94 * V_37 ;
int V_25 ;
if ( F_33 ( V_21 ) == V_72 && ! F_87 ( V_35 -> V_38 , 1 ) )
return;
V_37 = F_58 ( F_192 , V_21 , V_21 -> V_37 . V_7 ,
V_21 -> V_37 . V_98 ) ;
if ( F_74 ( V_37 ) )
return;
V_237 = F_25 ( V_37 , struct V_20 , V_37 ) ;
V_237 -> V_27 = V_327 ;
memcpy ( F_31 ( V_237 ) , F_31 ( V_21 ) ,
F_184 ( F_31 ( V_21 ) ) ) ;
F_17 ( V_237 , V_35 ) ;
F_20 ( & V_237 -> V_104 , & V_21 -> V_104 ) ;
F_18 ( & V_21 -> V_36 ) ;
V_237 -> V_245 = 1 ;
V_237 -> V_224 = V_21 -> V_224 ;
V_25 = F_194 ( V_37 , V_21 -> V_325 ) ;
if ( V_25 )
F_171 ( V_328 L_3
L_4 , V_25 , V_35 -> V_38 -> V_329 ) ;
}
static void F_195 ( struct V_20 * V_21 )
{
struct V_34 * V_35 ;
F_28 ( & V_26 ) ;
F_20 ( & V_21 -> V_44 , & V_330 ) ;
F_51 (cma_dev, &dev_list, list)
F_193 ( V_21 , V_35 ) ;
F_30 ( & V_26 ) ;
}
void F_196 ( struct V_94 * V_37 , int V_326 )
{
struct V_20 * V_21 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
V_21 -> V_326 = ( T_2 ) V_326 ;
}
static void F_197 ( int V_264 , struct V_162 * V_246 ,
void * V_96 )
{
struct V_331 * V_332 = V_96 ;
struct V_285 * V_39 ;
V_39 = & V_332 -> V_37 -> V_37 . V_39 ;
if ( ! V_264 ) {
V_39 -> V_286 = 1 ;
* V_39 -> V_246 = * V_246 ;
} else {
V_332 -> V_333 = V_240 ;
V_332 -> V_334 = V_335 ;
V_332 -> V_2 . V_2 = V_336 ;
V_332 -> V_2 . V_264 = V_264 ;
}
F_198 ( V_337 , & V_332 -> V_332 ) ;
}
static int F_199 ( struct V_20 * V_21 , int V_338 ,
struct V_331 * V_332 )
{
struct V_65 * V_41 = & V_21 -> V_37 . V_39 . V_40 . V_41 ;
struct V_162 V_246 ;
T_10 V_339 ;
struct V_153 * V_340 ;
struct V_63 * V_64 ;
memset ( & V_246 , 0 , sizeof V_246 ) ;
F_200 ( V_41 , & V_246 . V_85 ) ;
F_201 ( V_41 , & V_246 . V_86 ) ;
V_246 . V_87 = F_202 ( F_86 ( V_41 ) ) ;
V_246 . V_341 = 1 ;
V_246 . V_342 = 1 ;
V_246 . V_168 = F_182 ( & V_21 -> V_37 , F_32 ( V_21 ) ) ;
V_339 = V_343 | V_344 |
V_345 | V_346 |
V_347 | V_348 ;
switch ( F_33 ( V_21 ) ) {
case V_148 :
V_246 . V_349 = F_202 ( ( T_4 ) V_21 -> V_326 ) ;
V_339 |= V_350 ;
break;
case V_152 :
V_340 = (struct V_153 * ) F_31 ( V_21 ) ;
V_246 . V_351 = ( T_2 ) ( F_37 ( V_340 -> V_352 ) >> 20 ) ;
V_339 |= V_353 ;
break;
case V_72 :
V_64 = (struct V_63 * ) F_31 ( V_21 ) ;
V_246 . V_351 = ( T_2 ) ( F_37 ( V_64 -> V_166 ) >> 20 ) ;
V_339 |= V_353 ;
break;
}
V_21 -> V_236 = F_203 ( & V_354 , V_21 -> V_37 . V_38 ,
V_21 -> V_37 . V_62 , & V_246 ,
V_339 , V_338 ,
V_19 , F_197 ,
V_332 , & V_21 -> V_235 ) ;
return ( V_21 -> V_236 < 0 ) ? V_21 -> V_236 : 0 ;
}
static void F_204 ( struct V_355 * V_356 )
{
struct V_331 * V_332 = F_25 ( V_356 , struct V_331 , V_332 ) ;
struct V_20 * V_21 = V_332 -> V_37 ;
int V_357 = 0 ;
F_28 ( & V_21 -> V_93 ) ;
if ( ! F_13 ( V_21 , V_332 -> V_333 , V_332 -> V_334 ) )
goto V_82;
if ( V_21 -> V_37 . V_95 ( & V_21 -> V_37 , & V_332 -> V_2 ) ) {
F_14 ( V_21 , V_244 ) ;
V_357 = 1 ;
}
V_82:
F_30 ( & V_21 -> V_93 ) ;
F_56 ( V_21 ) ;
if ( V_357 )
F_153 ( & V_21 -> V_37 ) ;
F_26 ( V_332 ) ;
}
static void F_205 ( struct V_355 * V_356 )
{
struct V_358 * V_332 = F_25 ( V_356 , struct V_358 , V_332 ) ;
struct V_20 * V_21 = V_332 -> V_37 ;
int V_357 = 0 ;
F_28 ( & V_21 -> V_93 ) ;
if ( V_21 -> V_27 == V_244 ||
V_21 -> V_27 == V_359 )
goto V_82;
if ( V_21 -> V_37 . V_95 ( & V_21 -> V_37 , & V_332 -> V_2 ) ) {
F_14 ( V_21 , V_244 ) ;
V_357 = 1 ;
}
V_82:
F_30 ( & V_21 -> V_93 ) ;
F_56 ( V_21 ) ;
if ( V_357 )
F_153 ( & V_21 -> V_37 ) ;
F_26 ( V_332 ) ;
}
static int F_206 ( struct V_20 * V_21 , int V_338 )
{
struct V_285 * V_39 = & V_21 -> V_37 . V_39 ;
struct V_331 * V_332 ;
int V_25 ;
V_332 = F_59 ( sizeof *V_332 , V_19 ) ;
if ( ! V_332 )
return - V_99 ;
V_332 -> V_37 = V_21 ;
F_207 ( & V_332 -> V_332 , F_204 ) ;
V_332 -> V_333 = V_240 ;
V_332 -> V_334 = V_360 ;
V_332 -> V_2 . V_2 = V_361 ;
V_39 -> V_246 = F_173 ( sizeof * V_39 -> V_246 , V_19 ) ;
if ( ! V_39 -> V_246 ) {
V_25 = - V_99 ;
goto V_298;
}
V_25 = F_199 ( V_21 , V_338 , V_332 ) ;
if ( V_25 )
goto V_300;
return 0 ;
V_300:
F_26 ( V_39 -> V_246 ) ;
V_39 -> V_246 = NULL ;
V_298:
F_26 ( V_332 ) ;
return V_25 ;
}
int F_208 ( struct V_94 * V_37 ,
struct V_162 * V_246 , int V_286 )
{
struct V_20 * V_21 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( ! F_13 ( V_21 , V_335 ,
V_360 ) )
return - V_59 ;
V_37 -> V_39 . V_246 = F_209 ( V_246 , sizeof *V_246 * V_286 ,
V_19 ) ;
if ( ! V_37 -> V_39 . V_246 ) {
V_25 = - V_99 ;
goto V_124;
}
V_37 -> V_39 . V_286 = V_286 ;
return 0 ;
V_124:
F_13 ( V_21 , V_360 , V_335 ) ;
return V_25 ;
}
static int F_210 ( struct V_20 * V_21 , int V_338 )
{
struct V_331 * V_332 ;
V_332 = F_59 ( sizeof *V_332 , V_19 ) ;
if ( ! V_332 )
return - V_99 ;
V_332 -> V_37 = V_21 ;
F_207 ( & V_332 -> V_332 , F_204 ) ;
V_332 -> V_333 = V_240 ;
V_332 -> V_334 = V_360 ;
V_332 -> V_2 . V_2 = V_361 ;
F_198 ( V_337 , & V_332 -> V_332 ) ;
return 0 ;
}
static int F_211 ( struct V_195 * V_362 , int V_326 )
{
int V_363 ;
struct V_195 * V_211 ;
V_363 = F_212 ( V_326 ) ;
V_211 = V_362 -> V_364 & V_365 ?
F_213 ( V_362 ) : V_362 ;
if ( V_211 -> V_366 )
return F_214 ( V_211 , V_363 ) ;
#if F_125 ( V_367 )
if ( V_362 -> V_364 & V_365 )
return ( F_215 ( V_362 , V_363 ) &
V_368 ) >> V_369 ;
#endif
return 0 ;
}
static int F_216 ( struct V_20 * V_21 )
{
struct V_285 * V_39 = & V_21 -> V_37 . V_39 ;
struct V_230 * V_40 = & V_39 -> V_40 ;
struct V_331 * V_332 ;
int V_25 ;
struct V_195 * V_362 = NULL ;
V_332 = F_59 ( sizeof *V_332 , V_19 ) ;
if ( ! V_332 )
return - V_99 ;
V_332 -> V_37 = V_21 ;
F_207 ( & V_332 -> V_332 , F_204 ) ;
V_39 -> V_246 = F_59 ( sizeof * V_39 -> V_246 , V_19 ) ;
if ( ! V_39 -> V_246 ) {
V_25 = - V_99 ;
goto V_298;
}
V_39 -> V_286 = 1 ;
if ( V_40 -> V_41 . V_231 )
V_362 = F_217 ( & V_232 , V_40 -> V_41 . V_231 ) ;
if ( ! V_362 ) {
V_25 = - V_77 ;
goto V_300;
}
V_39 -> V_246 -> V_370 = F_218 ( V_362 ) ;
memcpy ( V_39 -> V_246 -> V_371 , V_40 -> V_41 . V_372 , V_373 ) ;
memcpy ( V_39 -> V_246 -> V_132 , V_362 -> V_41 , V_362 -> V_374 ) ;
F_48 ( (struct V_52 * ) & V_21 -> V_37 . V_39 . V_40 . V_53 ,
& V_39 -> V_246 -> V_85 ) ;
F_48 ( (struct V_52 * ) & V_21 -> V_37 . V_39 . V_40 . V_54 ,
& V_39 -> V_246 -> V_86 ) ;
V_39 -> V_246 -> V_375 = 1 ;
V_39 -> V_246 -> V_342 = 1 ;
V_39 -> V_246 -> V_87 = F_202 ( 0xffff ) ;
V_39 -> V_246 -> V_376 = V_377 ;
V_39 -> V_246 -> V_378 = F_211 ( V_362 , V_21 -> V_326 ) ;
V_39 -> V_246 -> V_379 = F_219 ( V_362 -> V_379 ) ;
V_39 -> V_246 -> V_380 = V_377 ;
V_39 -> V_246 -> V_381 = F_220 ( V_362 ) ;
F_132 ( V_362 ) ;
V_39 -> V_246 -> V_382 = V_377 ;
V_39 -> V_246 -> V_383 = V_384 ;
if ( ! V_39 -> V_246 -> V_379 ) {
V_25 = - V_59 ;
goto V_300;
}
V_332 -> V_333 = V_240 ;
V_332 -> V_334 = V_360 ;
V_332 -> V_2 . V_2 = V_361 ;
V_332 -> V_2 . V_264 = 0 ;
F_198 ( V_337 , & V_332 -> V_332 ) ;
return 0 ;
V_300:
F_26 ( V_39 -> V_246 ) ;
V_39 -> V_246 = NULL ;
V_298:
F_26 ( V_332 ) ;
return V_25 ;
}
int F_221 ( struct V_94 * V_37 , int V_338 )
{
struct V_20 * V_21 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( ! F_13 ( V_21 , V_335 , V_240 ) )
return - V_59 ;
F_18 ( & V_21 -> V_36 ) ;
if ( F_147 ( V_37 -> V_38 , V_37 -> V_62 ) )
V_25 = F_206 ( V_21 , V_338 ) ;
else if ( F_50 ( V_37 -> V_38 , V_37 -> V_62 ) )
V_25 = F_216 ( V_21 ) ;
else if ( F_222 ( V_37 -> V_38 , V_37 -> V_62 ) )
V_25 = F_210 ( V_21 , V_338 ) ;
else
V_25 = - V_147 ;
if ( V_25 )
goto V_124;
return 0 ;
V_124:
F_13 ( V_21 , V_240 , V_335 ) ;
F_56 ( V_21 ) ;
return V_25 ;
}
static void F_223 ( struct V_52 * V_40 )
{
switch ( V_40 -> V_71 ) {
case V_148 :
( (struct V_149 * ) V_40 ) -> V_150 . V_151 = F_224 ( V_385 ) ;
break;
case V_152 :
F_225 ( & ( (struct V_153 * ) V_40 ) -> V_154 ,
0 , 0 , 0 , F_224 ( 1 ) ) ;
break;
default:
F_226 ( & ( (struct V_63 * ) V_40 ) -> V_69 ,
0 , 0 , 0 , F_224 ( 1 ) ) ;
break;
}
}
static int F_227 ( struct V_20 * V_21 )
{
struct V_34 * V_35 , * V_84 ;
struct V_386 V_387 ;
union V_68 V_75 ;
T_4 V_87 ;
int V_25 ;
T_2 V_88 ;
V_35 = NULL ;
F_28 ( & V_26 ) ;
F_51 (cur_dev, &dev_list, list) {
if ( F_33 ( V_21 ) == V_72 &&
! F_87 ( V_84 -> V_38 , 1 ) )
continue;
if ( ! V_35 )
V_35 = V_84 ;
for ( V_88 = 1 ; V_88 <= V_84 -> V_38 -> V_83 ; ++ V_88 ) {
if ( ! F_228 ( V_84 -> V_38 , V_88 , & V_387 ) &&
V_387 . V_27 == V_388 ) {
V_35 = V_84 ;
goto V_389;
}
}
}
if ( ! V_35 ) {
V_25 = - V_77 ;
goto V_82;
}
V_88 = 1 ;
V_389:
V_25 = F_55 ( V_35 -> V_38 , V_88 , 0 , & V_75 ) ;
if ( V_25 )
goto V_82;
V_25 = F_229 ( V_35 -> V_38 , V_88 , 0 , & V_87 ) ;
if ( V_25 )
goto V_82;
V_21 -> V_37 . V_39 . V_40 . V_41 . V_66 =
( F_45 ( V_35 -> V_38 , V_88 ) ) ?
V_67 : V_390 ;
F_39 ( & V_21 -> V_37 . V_39 . V_40 . V_41 , & V_75 ) ;
F_40 ( & V_21 -> V_37 . V_39 . V_40 . V_41 , V_87 ) ;
V_21 -> V_37 . V_62 = V_88 ;
F_17 ( V_21 , V_35 ) ;
F_223 ( F_31 ( V_21 ) ) ;
V_82:
F_30 ( & V_26 ) ;
return V_25 ;
}
static void F_230 ( int V_264 , struct V_52 * V_53 ,
struct V_65 * V_41 , void * V_96 )
{
struct V_20 * V_21 = V_96 ;
struct V_249 V_2 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
F_28 ( & V_21 -> V_93 ) ;
if ( ! F_13 ( V_21 , V_239 ,
V_335 ) )
goto V_82;
memcpy ( F_31 ( V_21 ) , V_53 , F_184 ( V_53 ) ) ;
if ( ! V_264 && ! V_21 -> V_35 )
V_264 = F_47 ( V_21 , NULL ) ;
if ( V_264 ) {
if ( ! F_13 ( V_21 , V_335 ,
V_327 ) )
goto V_82;
V_2 . V_2 = V_391 ;
V_2 . V_264 = V_264 ;
} else
V_2 . V_2 = V_392 ;
if ( V_21 -> V_37 . V_95 ( & V_21 -> V_37 , & V_2 ) ) {
F_14 ( V_21 , V_244 ) ;
F_30 ( & V_21 -> V_93 ) ;
F_56 ( V_21 ) ;
F_153 ( & V_21 -> V_37 ) ;
return;
}
V_82:
F_30 ( & V_21 -> V_93 ) ;
F_56 ( V_21 ) ;
}
static int F_231 ( struct V_20 * V_21 )
{
struct V_331 * V_332 ;
union V_68 V_75 ;
int V_25 ;
V_332 = F_59 ( sizeof *V_332 , V_19 ) ;
if ( ! V_332 )
return - V_99 ;
if ( ! V_21 -> V_35 ) {
V_25 = F_227 ( V_21 ) ;
if ( V_25 )
goto V_124;
}
F_200 ( & V_21 -> V_37 . V_39 . V_40 . V_41 , & V_75 ) ;
F_175 ( & V_21 -> V_37 . V_39 . V_40 . V_41 , & V_75 ) ;
V_332 -> V_37 = V_21 ;
F_207 ( & V_332 -> V_332 , F_204 ) ;
V_332 -> V_333 = V_239 ;
V_332 -> V_334 = V_335 ;
V_332 -> V_2 . V_2 = V_392 ;
F_198 ( V_337 , & V_332 -> V_332 ) ;
return 0 ;
V_124:
F_26 ( V_332 ) ;
return V_25 ;
}
static int F_232 ( struct V_20 * V_21 )
{
struct V_331 * V_332 ;
int V_25 ;
V_332 = F_59 ( sizeof *V_332 , V_19 ) ;
if ( ! V_332 )
return - V_99 ;
if ( ! V_21 -> V_35 ) {
V_25 = F_52 ( V_21 ) ;
if ( V_25 )
goto V_124;
}
F_175 ( & V_21 -> V_37 . V_39 . V_40 . V_41 , (union V_68 * )
& ( ( (struct V_63 * ) & V_21 -> V_37 . V_39 . V_40 . V_54 ) -> V_69 ) ) ;
V_332 -> V_37 = V_21 ;
F_207 ( & V_332 -> V_332 , F_204 ) ;
V_332 -> V_333 = V_239 ;
V_332 -> V_334 = V_335 ;
V_332 -> V_2 . V_2 = V_392 ;
F_198 ( V_337 , & V_332 -> V_332 ) ;
return 0 ;
V_124:
F_26 ( V_332 ) ;
return V_25 ;
}
static int F_233 ( struct V_94 * V_37 , struct V_52 * V_53 ,
struct V_52 * V_54 )
{
if ( ! V_53 || ! V_53 -> V_71 ) {
V_53 = (struct V_52 * ) & V_37 -> V_39 . V_40 . V_53 ;
V_53 -> V_71 = V_54 -> V_71 ;
if ( V_54 -> V_71 == V_152 ) {
struct V_153 * V_393 = (struct V_153 * ) V_53 ;
struct V_153 * V_394 = (struct V_153 * ) V_54 ;
V_393 -> V_395 = V_394 -> V_395 ;
if ( F_126 ( & V_394 -> V_154 ) & V_207 )
V_37 -> V_39 . V_40 . V_41 . V_231 = V_394 -> V_395 ;
} else if ( V_54 -> V_71 == V_72 ) {
( (struct V_63 * ) V_53 ) -> V_70 =
( (struct V_63 * ) V_54 ) -> V_70 ;
}
}
return F_234 ( V_37 , V_53 ) ;
}
int F_235 ( struct V_94 * V_37 , struct V_52 * V_53 ,
struct V_52 * V_54 , int V_338 )
{
struct V_20 * V_21 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( V_21 -> V_27 == V_102 ) {
V_25 = F_233 ( V_37 , V_53 , V_54 ) ;
if ( V_25 )
return V_25 ;
}
if ( F_33 ( V_21 ) != V_54 -> V_71 )
return - V_59 ;
if ( ! F_13 ( V_21 , V_327 , V_239 ) )
return - V_59 ;
F_18 ( & V_21 -> V_36 ) ;
memcpy ( F_32 ( V_21 ) , V_54 , F_184 ( V_54 ) ) ;
if ( F_99 ( V_54 ) ) {
V_25 = F_231 ( V_21 ) ;
} else {
if ( V_54 -> V_71 == V_72 ) {
V_25 = F_232 ( V_21 ) ;
} else {
V_25 = F_236 ( & V_396 , F_31 ( V_21 ) ,
V_54 , & V_37 -> V_39 . V_40 . V_41 ,
V_338 , F_230 , V_21 ) ;
}
}
if ( V_25 )
goto V_124;
return 0 ;
V_124:
F_13 ( V_21 , V_239 , V_327 ) ;
F_56 ( V_21 ) ;
return V_25 ;
}
int F_237 ( struct V_94 * V_37 , int V_397 )
{
struct V_20 * V_21 ;
unsigned long V_24 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
F_11 ( & V_21 -> V_26 , V_24 ) ;
if ( V_397 || V_21 -> V_27 == V_102 ) {
V_21 -> V_398 = V_397 ;
V_25 = 0 ;
} else {
V_25 = - V_59 ;
}
F_12 ( & V_21 -> V_26 , V_24 ) ;
return V_25 ;
}
int F_238 ( struct V_94 * V_37 , int V_224 )
{
struct V_20 * V_21 ;
unsigned long V_24 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
F_11 ( & V_21 -> V_26 , V_24 ) ;
if ( V_21 -> V_27 == V_102 || V_21 -> V_27 == V_327 ) {
V_21 -> V_399 |= ( 1 << V_400 ) ;
V_21 -> V_224 = V_224 ;
V_25 = 0 ;
} else {
V_25 = - V_59 ;
}
F_12 ( & V_21 -> V_26 , V_24 ) ;
return V_25 ;
}
static void F_239 ( struct V_16 * V_17 ,
struct V_20 * V_21 )
{
struct V_52 * V_40 ;
struct V_63 * V_64 ;
V_304 V_401 , V_402 ;
T_6 V_74 ;
V_40 = F_31 ( V_21 ) ;
V_74 = F_104 ( V_17 -> V_74 ) ;
switch ( V_40 -> V_71 ) {
case V_148 :
( (struct V_149 * ) V_40 ) -> V_157 = V_74 ;
break;
case V_152 :
( (struct V_153 * ) V_40 ) -> V_158 = V_74 ;
break;
case V_72 :
V_64 = (struct V_63 * ) V_40 ;
V_401 = F_105 ( V_64 -> V_159 ) ;
V_402 = F_105 ( V_64 -> V_160 ) ;
V_64 -> V_159 = F_108 ( ( V_401 & V_402 ) | ( V_304 ) F_41 ( V_74 ) ) ;
V_64 -> V_160 = F_108 ( ~ 0ULL ) ;
break;
}
V_21 -> V_17 = V_17 ;
F_240 ( & V_21 -> V_242 , & V_17 -> V_243 ) ;
}
static int F_241 ( enum V_6 V_7 ,
struct V_20 * V_21 , unsigned short V_18 )
{
struct V_16 * V_17 ;
int V_25 ;
V_17 = F_59 ( sizeof *V_17 , V_19 ) ;
if ( ! V_17 )
return - V_99 ;
V_25 = F_4 ( V_7 , V_17 , V_18 ) ;
if ( V_25 < 0 )
goto V_124;
V_17 -> V_7 = V_7 ;
V_17 -> V_74 = ( unsigned short ) V_25 ;
F_239 ( V_17 , V_21 ) ;
return 0 ;
V_124:
F_26 ( V_17 ) ;
return V_25 == - V_403 ? - V_404 : V_25 ;
}
static int F_242 ( enum V_6 V_7 ,
struct V_20 * V_21 )
{
static unsigned int V_405 ;
int V_406 , V_407 , V_408 ;
unsigned int V_409 ;
F_243 ( & V_232 , & V_406 , & V_407 ) ;
V_408 = ( V_407 - V_406 ) + 1 ;
V_409 = F_244 () % V_408 + V_406 ;
V_410:
if ( V_405 != V_409 &&
! F_6 ( V_7 , ( unsigned short ) V_409 ) ) {
int V_25 = F_241 ( V_7 , V_21 , V_409 ) ;
if ( ! V_25 )
V_405 = V_409 ;
if ( V_25 != - V_404 )
return V_25 ;
}
if ( -- V_408 ) {
V_409 ++ ;
if ( ( V_409 < V_406 ) || ( V_409 > V_407 ) )
V_409 = V_406 ;
goto V_410;
}
return - V_404 ;
}
static int F_245 ( struct V_16 * V_17 ,
struct V_20 * V_21 , T_11 V_398 )
{
struct V_20 * V_411 ;
struct V_52 * V_40 , * V_412 ;
V_40 = F_31 ( V_21 ) ;
F_142 (cur_id, &bind_list->owners, node) {
if ( V_21 == V_411 )
continue;
if ( ( V_411 -> V_27 != V_241 ) && V_398 &&
V_411 -> V_398 )
continue;
V_412 = F_31 ( V_411 ) ;
if ( V_21 -> V_224 && V_411 -> V_224 &&
( V_40 -> V_71 != V_412 -> V_71 ) )
continue;
if ( F_99 ( V_40 ) || F_99 ( V_412 ) )
return - V_404 ;
if ( ! F_100 ( V_40 , V_412 ) )
return - V_413 ;
}
return 0 ;
}
static int F_246 ( enum V_6 V_7 ,
struct V_20 * V_21 )
{
struct V_16 * V_17 ;
unsigned short V_18 ;
int V_25 ;
V_18 = F_41 ( F_103 ( F_31 ( V_21 ) ) ) ;
if ( V_18 < V_414 && ! F_247 ( V_415 ) )
return - V_416 ;
V_17 = F_6 ( V_7 , V_18 ) ;
if ( ! V_17 ) {
V_25 = F_241 ( V_7 , V_21 , V_18 ) ;
} else {
V_25 = F_245 ( V_17 , V_21 , V_21 -> V_398 ) ;
if ( ! V_25 )
F_239 ( V_17 , V_21 ) ;
}
return V_25 ;
}
static int F_248 ( struct V_20 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_17 ;
int V_25 = 0 ;
F_28 ( & V_26 ) ;
if ( V_17 -> V_243 . V_417 -> V_238 )
V_25 = F_245 ( V_17 , V_21 , 0 ) ;
F_30 ( & V_26 ) ;
return V_25 ;
}
static enum V_6 F_249 (
struct V_20 * V_21 )
{
switch ( V_21 -> V_37 . V_7 ) {
case V_8 :
case V_10 :
case V_12 :
case V_14 :
return V_21 -> V_37 . V_7 ;
default:
return 0 ;
}
}
static enum V_6 F_250 ( struct V_20 * V_21 )
{
enum V_6 V_7 = 0 ;
struct V_63 * V_64 ;
V_304 V_418 , V_402 , V_401 ;
V_64 = (struct V_63 * ) F_31 ( V_21 ) ;
V_402 = F_105 ( V_64 -> V_160 ) & V_419 ;
V_401 = F_105 ( V_64 -> V_159 ) & V_402 ;
if ( ( V_21 -> V_37 . V_7 == V_14 ) && ( V_401 == ( V_420 & V_402 ) ) ) {
V_418 = V_420 ;
V_7 = V_14 ;
} else if ( ( ( V_21 -> V_37 . V_7 == V_14 ) || ( V_21 -> V_37 . V_7 == V_8 ) ) &&
( V_401 == ( V_421 & V_402 ) ) ) {
V_418 = V_421 ;
V_7 = V_8 ;
} else if ( ( ( V_21 -> V_37 . V_7 == V_14 ) || ( V_21 -> V_37 . V_7 == V_10 ) ) &&
( V_401 == ( V_422 & V_402 ) ) ) {
V_418 = V_422 ;
V_7 = V_10 ;
}
if ( V_7 ) {
V_64 -> V_159 = F_108 ( V_418 | F_41 ( F_103 ( (struct V_52 * ) V_64 ) ) ) ;
V_64 -> V_160 = F_108 ( V_419 |
F_105 ( V_64 -> V_160 ) ) ;
}
return V_7 ;
}
static int F_251 ( struct V_20 * V_21 )
{
enum V_6 V_7 ;
int V_25 ;
if ( F_33 ( V_21 ) != V_72 )
V_7 = F_249 ( V_21 ) ;
else
V_7 = F_250 ( V_21 ) ;
if ( ! V_7 )
return - V_423 ;
F_28 ( & V_26 ) ;
if ( F_106 ( F_31 ( V_21 ) ) )
V_25 = F_242 ( V_7 , V_21 ) ;
else
V_25 = F_246 ( V_7 , V_21 ) ;
F_30 ( & V_26 ) ;
return V_25 ;
}
static int F_252 ( struct V_65 * V_41 ,
struct V_52 * V_40 )
{
#if F_125 ( V_205 )
struct V_153 * V_340 ;
if ( V_40 -> V_71 != V_152 )
return 0 ;
V_340 = (struct V_153 * ) V_40 ;
if ( ! ( F_126 ( & V_340 -> V_154 ) & V_207 ) )
return 0 ;
if ( ! V_340 -> V_395 )
return - V_59 ;
V_41 -> V_231 = V_340 -> V_395 ;
#endif
return 0 ;
}
int F_194 ( struct V_94 * V_37 , int V_325 )
{
struct V_20 * V_21 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( V_21 -> V_27 == V_102 ) {
V_37 -> V_39 . V_40 . V_53 . V_55 = V_148 ;
V_25 = F_234 ( V_37 , F_31 ( V_21 ) ) ;
if ( V_25 )
return V_25 ;
}
if ( ! F_13 ( V_21 , V_327 , V_241 ) )
return - V_59 ;
if ( V_21 -> V_398 ) {
V_25 = F_248 ( V_21 ) ;
if ( V_25 )
goto V_124;
}
V_21 -> V_325 = V_325 ;
if ( V_37 -> V_38 ) {
if ( F_87 ( V_37 -> V_38 , 1 ) ) {
V_25 = F_187 ( V_21 ) ;
if ( V_25 )
goto V_124;
} else if ( F_89 ( V_37 -> V_38 , 1 ) ) {
V_25 = F_189 ( V_21 , V_325 ) ;
if ( V_25 )
goto V_124;
} else {
V_25 = - V_147 ;
goto V_124;
}
} else
F_195 ( V_21 ) ;
return 0 ;
V_124:
V_21 -> V_325 = 0 ;
F_13 ( V_21 , V_241 , V_327 ) ;
return V_25 ;
}
int F_234 ( struct V_94 * V_37 , struct V_52 * V_40 )
{
struct V_20 * V_21 ;
int V_25 ;
if ( V_40 -> V_71 != V_148 && V_40 -> V_71 != V_152 &&
V_40 -> V_71 != V_72 )
return - V_180 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( ! F_13 ( V_21 , V_102 , V_327 ) )
return - V_59 ;
V_25 = F_252 ( & V_37 -> V_39 . V_40 . V_41 , V_40 ) ;
if ( V_25 )
goto V_298;
memcpy ( F_31 ( V_21 ) , V_40 , F_184 ( V_40 ) ) ;
if ( ! F_99 ( V_40 ) ) {
V_25 = F_42 ( V_40 , & V_37 -> V_39 . V_40 . V_41 ) ;
if ( V_25 )
goto V_298;
V_25 = F_47 ( V_21 , NULL ) ;
if ( V_25 )
goto V_298;
}
if ( ! ( V_21 -> V_399 & ( 1 << V_400 ) ) ) {
if ( V_40 -> V_71 == V_148 )
V_21 -> V_224 = 1 ;
#if F_125 ( V_205 )
else if ( V_40 -> V_71 == V_152 )
V_21 -> V_224 = V_232 . V_424 . V_425 . V_426 ;
#endif
}
V_25 = F_251 ( V_21 ) ;
if ( V_25 )
goto V_300;
return 0 ;
V_300:
if ( V_21 -> V_35 )
F_27 ( V_21 ) ;
V_298:
F_13 ( V_21 , V_327 , V_102 ) ;
return V_25 ;
}
static int F_253 ( void * V_31 , struct V_20 * V_21 )
{
struct V_30 * V_30 ;
V_30 = V_31 ;
V_30 -> V_178 = V_179 ;
if ( F_33 ( V_21 ) == V_148 ) {
struct V_149 * V_427 , * V_428 ;
V_427 = (struct V_149 * ) F_31 ( V_21 ) ;
V_428 = (struct V_149 * ) F_32 ( V_21 ) ;
F_16 ( V_30 , 4 ) ;
V_30 -> V_53 . V_171 . V_40 = V_427 -> V_150 . V_151 ;
V_30 -> V_54 . V_171 . V_40 = V_428 -> V_150 . V_151 ;
V_30 -> V_74 = V_427 -> V_157 ;
} else if ( F_33 ( V_21 ) == V_152 ) {
struct V_153 * V_429 , * V_430 ;
V_429 = (struct V_153 * ) F_31 ( V_21 ) ;
V_430 = (struct V_153 * ) F_32 ( V_21 ) ;
F_16 ( V_30 , 6 ) ;
V_30 -> V_53 . V_173 = V_429 -> V_154 ;
V_30 -> V_54 . V_173 = V_430 -> V_154 ;
V_30 -> V_74 = V_429 -> V_158 ;
}
return 0 ;
}
static int F_254 ( struct V_233 * V_144 ,
struct V_175 * V_176 )
{
struct V_20 * V_21 = V_144 -> V_96 ;
struct V_249 V_2 ;
struct V_431 * V_432 = & V_176 -> V_182 . V_433 ;
int V_25 = 0 ;
if ( F_57 ( V_21 , V_259 ) )
return 0 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_176 -> V_2 ) {
case V_434 :
V_2 . V_2 = V_263 ;
V_2 . V_264 = - V_265 ;
break;
case V_435 :
V_2 . V_182 . V_296 . V_177 = V_176 -> V_177 ;
V_2 . V_182 . V_296 . V_253 = V_436 ;
if ( V_432 -> V_264 != V_437 ) {
V_2 . V_2 = V_263 ;
V_2 . V_264 = V_176 -> V_182 . V_433 . V_264 ;
break;
}
V_25 = F_34 ( V_21 , V_432 -> V_56 ) ;
if ( V_25 ) {
V_2 . V_2 = V_391 ;
V_2 . V_264 = V_25 ;
break;
}
F_255 ( V_21 -> V_37 . V_38 , V_21 -> V_37 . V_62 ,
V_21 -> V_37 . V_39 . V_246 ,
& V_2 . V_182 . V_296 . V_129 ) ;
V_2 . V_182 . V_296 . V_125 = V_432 -> V_438 ;
V_2 . V_182 . V_296 . V_56 = V_432 -> V_56 ;
V_2 . V_2 = V_268 ;
V_2 . V_264 = 0 ;
break;
default:
F_171 ( V_284 L_2 ,
V_176 -> V_2 ) ;
goto V_82;
}
V_25 = V_21 -> V_37 . V_95 ( & V_21 -> V_37 , & V_2 ) ;
if ( V_25 ) {
V_21 -> V_144 . V_51 = NULL ;
F_14 ( V_21 , V_244 ) ;
F_30 ( & V_21 -> V_93 ) ;
F_153 ( & V_21 -> V_37 ) ;
return V_25 ;
}
V_82:
F_30 ( & V_21 -> V_93 ) ;
return V_25 ;
}
static int F_256 ( struct V_20 * V_21 ,
struct V_127 * V_128 )
{
struct V_439 V_187 ;
struct V_233 * V_37 ;
void * V_177 ;
int V_289 , V_25 ;
memset ( & V_187 , 0 , sizeof V_187 ) ;
V_289 = F_145 ( V_21 ) ;
V_187 . V_253 = V_289 + V_128 -> V_253 ;
if ( V_187 . V_253 < V_128 -> V_253 )
return - V_59 ;
if ( V_187 . V_253 ) {
V_177 = F_59 ( V_187 . V_253 , V_440 ) ;
if ( ! V_177 )
return - V_99 ;
} else {
V_177 = NULL ;
}
if ( V_128 -> V_177 && V_128 -> V_253 )
memcpy ( V_177 + V_289 , V_128 -> V_177 ,
V_128 -> V_253 ) ;
if ( V_177 ) {
V_25 = F_253 ( V_177 , V_21 ) ;
if ( V_25 )
goto V_82;
V_187 . V_177 = V_177 ;
}
V_37 = F_257 ( V_21 -> V_37 . V_38 , F_254 ,
V_21 ) ;
if ( F_74 ( V_37 ) ) {
V_25 = F_75 ( V_37 ) ;
goto V_82;
}
V_21 -> V_144 . V_51 = V_37 ;
V_187 . V_163 = V_21 -> V_37 . V_39 . V_246 ;
V_187 . V_168 = F_182 ( & V_21 -> V_37 , F_32 ( V_21 ) ) ;
V_187 . V_338 = 1 << ( V_441 - 8 ) ;
V_187 . V_442 = V_443 ;
V_25 = F_258 ( V_21 -> V_144 . V_51 , & V_187 ) ;
if ( V_25 ) {
F_163 ( V_21 -> V_144 . V_51 ) ;
V_21 -> V_144 . V_51 = NULL ;
}
V_82:
F_26 ( V_177 ) ;
return V_25 ;
}
static int F_259 ( struct V_20 * V_21 ,
struct V_127 * V_128 )
{
struct V_444 V_187 ;
struct V_285 * V_39 ;
void * V_177 ;
struct V_233 * V_37 ;
int V_289 , V_25 ;
memset ( & V_187 , 0 , sizeof V_187 ) ;
V_289 = F_145 ( V_21 ) ;
V_187 . V_253 = V_289 + V_128 -> V_253 ;
if ( V_187 . V_253 < V_128 -> V_253 )
return - V_59 ;
if ( V_187 . V_253 ) {
V_177 = F_59 ( V_187 . V_253 , V_440 ) ;
if ( ! V_177 )
return - V_99 ;
} else {
V_177 = NULL ;
}
if ( V_128 -> V_177 && V_128 -> V_253 )
memcpy ( V_177 + V_289 , V_128 -> V_177 ,
V_128 -> V_253 ) ;
V_37 = F_257 ( V_21 -> V_37 . V_38 , F_170 , V_21 ) ;
if ( F_74 ( V_37 ) ) {
V_25 = F_75 ( V_37 ) ;
goto V_82;
}
V_21 -> V_144 . V_51 = V_37 ;
V_39 = & V_21 -> V_37 . V_39 ;
if ( V_177 ) {
V_25 = F_253 ( V_177 , V_21 ) ;
if ( V_25 )
goto V_82;
V_187 . V_177 = V_177 ;
}
V_187 . V_184 = & V_39 -> V_246 [ 0 ] ;
if ( V_39 -> V_286 == 2 )
V_187 . V_287 = & V_39 -> V_246 [ 1 ] ;
V_187 . V_168 = F_182 ( & V_21 -> V_37 , F_32 ( V_21 ) ) ;
V_187 . V_125 = V_21 -> V_125 ;
V_187 . V_98 = V_21 -> V_37 . V_98 ;
V_187 . V_445 = V_21 -> V_106 ;
V_187 . V_134 = V_128 -> V_134 ;
V_187 . V_136 = V_128 -> V_136 ;
V_187 . V_255 = V_128 -> V_255 ;
V_187 . V_291 = F_260 ( T_2 , 7 , V_128 -> V_291 ) ;
V_187 . V_256 = F_260 ( T_2 , 7 , V_128 -> V_256 ) ;
V_187 . V_446 = V_441 ;
V_187 . V_447 = V_441 ;
V_187 . V_442 = V_443 ;
V_187 . V_126 = V_21 -> V_126 ? 1 : 0 ;
V_25 = F_261 ( V_21 -> V_144 . V_51 , & V_187 ) ;
V_82:
if ( V_25 && ! F_74 ( V_37 ) ) {
F_163 ( V_37 ) ;
V_21 -> V_144 . V_51 = NULL ;
}
F_26 ( V_177 ) ;
return V_25 ;
}
static int F_262 ( struct V_20 * V_21 ,
struct V_127 * V_128 )
{
struct V_305 * V_144 ;
int V_25 ;
struct V_448 V_449 ;
V_144 = F_190 ( V_21 -> V_37 . V_38 , F_183 , V_21 ) ;
if ( F_74 ( V_144 ) )
return F_75 ( V_144 ) ;
V_144 -> V_326 = V_21 -> V_326 ;
V_21 -> V_144 . V_146 = V_144 ;
memcpy ( & V_144 -> V_310 , F_31 ( V_21 ) ,
F_184 ( F_31 ( V_21 ) ) ) ;
memcpy ( & V_144 -> V_312 , F_32 ( V_21 ) ,
F_184 ( F_32 ( V_21 ) ) ) ;
V_25 = F_78 ( V_21 , V_128 ) ;
if ( V_25 )
goto V_82;
if ( V_128 ) {
V_449 . V_316 = V_128 -> V_136 ;
V_449 . V_315 = V_128 -> V_134 ;
V_449 . V_177 = V_128 -> V_177 ;
V_449 . V_253 = V_128 -> V_253 ;
V_449 . V_438 = V_21 -> V_37 . V_108 ? V_21 -> V_125 : V_128 -> V_125 ;
} else {
memset ( & V_449 , 0 , sizeof V_449 ) ;
V_449 . V_438 = V_21 -> V_125 ;
}
V_25 = F_263 ( V_144 , & V_449 ) ;
V_82:
if ( V_25 ) {
F_164 ( V_144 ) ;
V_21 -> V_144 . V_146 = NULL ;
}
return V_25 ;
}
int F_264 ( struct V_94 * V_37 , struct V_127 * V_128 )
{
struct V_20 * V_21 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( ! F_13 ( V_21 , V_360 , V_259 ) )
return - V_59 ;
if ( ! V_37 -> V_108 ) {
V_21 -> V_125 = V_128 -> V_125 ;
V_21 -> V_126 = V_128 -> V_126 ;
}
if ( F_87 ( V_37 -> V_38 , V_37 -> V_62 ) ) {
if ( V_37 -> V_98 == V_123 )
V_25 = F_256 ( V_21 , V_128 ) ;
else
V_25 = F_259 ( V_21 , V_128 ) ;
} else if ( F_89 ( V_37 -> V_38 , V_37 -> V_62 ) )
V_25 = F_262 ( V_21 , V_128 ) ;
else
V_25 = - V_147 ;
if ( V_25 )
goto V_124;
return 0 ;
V_124:
F_13 ( V_21 , V_259 , V_360 ) ;
return V_25 ;
}
static int F_265 ( struct V_20 * V_21 ,
struct V_127 * V_128 )
{
struct V_450 V_432 ;
int V_25 ;
V_25 = F_78 ( V_21 , V_128 ) ;
if ( V_25 )
goto V_82;
V_25 = F_82 ( V_21 , V_128 ) ;
if ( V_25 )
goto V_82;
memset ( & V_432 , 0 , sizeof V_432 ) ;
V_432 . V_125 = V_21 -> V_125 ;
V_432 . V_445 = V_21 -> V_106 ;
V_432 . V_177 = V_128 -> V_177 ;
V_432 . V_253 = V_128 -> V_253 ;
V_432 . V_134 = V_128 -> V_134 ;
V_432 . V_136 = V_128 -> V_136 ;
V_432 . V_451 = 0 ;
V_432 . V_255 = V_128 -> V_255 ;
V_432 . V_256 = F_260 ( T_2 , 7 , V_128 -> V_256 ) ;
V_432 . V_126 = V_21 -> V_126 ? 1 : 0 ;
V_25 = F_266 ( V_21 -> V_144 . V_51 , & V_432 ) ;
V_82:
return V_25 ;
}
static int F_267 ( struct V_20 * V_21 ,
struct V_127 * V_128 )
{
struct V_448 V_449 ;
int V_25 ;
V_25 = F_78 ( V_21 , V_128 ) ;
if ( V_25 )
return V_25 ;
V_449 . V_316 = V_128 -> V_136 ;
V_449 . V_315 = V_128 -> V_134 ;
V_449 . V_177 = V_128 -> V_177 ;
V_449 . V_253 = V_128 -> V_253 ;
if ( V_21 -> V_37 . V_108 ) {
V_449 . V_438 = V_21 -> V_125 ;
} else
V_449 . V_438 = V_128 -> V_125 ;
return F_268 ( V_21 -> V_144 . V_146 , & V_449 ) ;
}
static int F_269 ( struct V_20 * V_21 ,
enum V_452 V_264 , T_3 V_56 ,
const void * V_177 , int V_253 )
{
struct V_453 V_432 ;
int V_25 ;
memset ( & V_432 , 0 , sizeof V_432 ) ;
V_432 . V_264 = V_264 ;
if ( V_264 == V_437 ) {
V_25 = F_34 ( V_21 , V_56 ) ;
if ( V_25 )
return V_25 ;
V_432 . V_125 = V_21 -> V_125 ;
V_432 . V_56 = V_21 -> V_56 ;
}
V_432 . V_177 = V_177 ;
V_432 . V_253 = V_253 ;
return F_270 ( V_21 -> V_144 . V_51 , & V_432 ) ;
}
int F_271 ( struct V_94 * V_37 , struct V_127 * V_128 )
{
struct V_20 * V_21 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
V_21 -> V_100 = F_61 ( V_101 ) ;
if ( ! F_10 ( V_21 , V_259 ) )
return - V_59 ;
if ( ! V_37 -> V_108 && V_128 ) {
V_21 -> V_125 = V_128 -> V_125 ;
V_21 -> V_126 = V_128 -> V_126 ;
}
if ( F_87 ( V_37 -> V_38 , V_37 -> V_62 ) ) {
if ( V_37 -> V_98 == V_123 ) {
if ( V_128 )
V_25 = F_269 ( V_21 , V_437 ,
V_128 -> V_56 ,
V_128 -> V_177 ,
V_128 -> V_253 ) ;
else
V_25 = F_269 ( V_21 , V_437 ,
0 , NULL , 0 ) ;
} else {
if ( V_128 )
V_25 = F_265 ( V_21 , V_128 ) ;
else
V_25 = F_166 ( V_21 ) ;
}
} else if ( F_89 ( V_37 -> V_38 , V_37 -> V_62 ) )
V_25 = F_267 ( V_21 , V_128 ) ;
else
V_25 = - V_147 ;
if ( V_25 )
goto V_247;
return 0 ;
V_247:
F_83 ( V_21 ) ;
F_272 ( V_37 , NULL , 0 ) ;
return V_25 ;
}
int F_273 ( struct V_94 * V_37 , enum V_454 V_2 )
{
struct V_20 * V_21 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( ! V_21 -> V_144 . V_51 )
return - V_59 ;
switch ( V_37 -> V_38 -> V_43 ) {
case V_455 :
V_25 = F_274 ( V_21 -> V_144 . V_51 , V_2 ) ;
break;
default:
V_25 = 0 ;
break;
}
return V_25 ;
}
int F_272 ( struct V_94 * V_37 , const void * V_177 ,
T_2 V_253 )
{
struct V_20 * V_21 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( ! V_21 -> V_144 . V_51 )
return - V_59 ;
if ( F_87 ( V_37 -> V_38 , V_37 -> V_62 ) ) {
if ( V_37 -> V_98 == V_123 )
V_25 = F_269 ( V_21 , V_456 , 0 ,
V_177 , V_253 ) ;
else
V_25 = F_168 ( V_21 -> V_144 . V_51 ,
V_248 , NULL ,
0 , V_177 , V_253 ) ;
} else if ( F_89 ( V_37 -> V_38 , V_37 -> V_62 ) ) {
V_25 = F_275 ( V_21 -> V_144 . V_146 ,
V_177 , V_253 ) ;
} else
V_25 = - V_147 ;
return V_25 ;
}
int F_276 ( struct V_94 * V_37 )
{
struct V_20 * V_21 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( ! V_21 -> V_144 . V_51 )
return - V_59 ;
if ( F_87 ( V_37 -> V_38 , V_37 -> V_62 ) ) {
V_25 = F_83 ( V_21 ) ;
if ( V_25 )
goto V_82;
if ( F_277 ( V_21 -> V_144 . V_51 , NULL , 0 ) )
F_278 ( V_21 -> V_144 . V_51 , NULL , 0 ) ;
} else if ( F_89 ( V_37 -> V_38 , V_37 -> V_62 ) ) {
V_25 = F_279 ( V_21 -> V_144 . V_146 , 0 ) ;
} else
V_25 = - V_59 ;
V_82:
return V_25 ;
}
static int F_280 ( int V_264 , struct V_457 * V_50 )
{
struct V_20 * V_21 ;
struct V_47 * V_48 = V_50 -> V_96 ;
struct V_249 V_2 ;
int V_25 ;
V_21 = V_48 -> V_21 ;
if ( F_57 ( V_21 , V_327 ) &&
F_57 ( V_21 , V_335 ) )
return 0 ;
if ( ! V_264 )
V_264 = F_34 ( V_21 , F_37 ( V_50 -> V_58 . V_56 ) ) ;
F_28 ( & V_21 -> V_103 ) ;
if ( ! V_264 && V_21 -> V_37 . V_108 )
V_264 = F_281 ( V_21 -> V_37 . V_108 , & V_50 -> V_58 . V_61 ,
F_115 ( V_50 -> V_58 . V_458 ) ) ;
F_30 ( & V_21 -> V_103 ) ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_264 = V_264 ;
V_2 . V_182 . V_296 . V_177 = V_48 -> V_96 ;
if ( ! V_264 ) {
V_2 . V_2 = V_459 ;
F_282 ( V_21 -> V_37 . V_38 ,
V_21 -> V_37 . V_62 , & V_50 -> V_58 ,
& V_2 . V_182 . V_296 . V_129 ) ;
V_2 . V_182 . V_296 . V_125 = 0xFFFFFF ;
V_2 . V_182 . V_296 . V_56 = F_37 ( V_50 -> V_58 . V_56 ) ;
} else
V_2 . V_2 = V_460 ;
V_25 = V_21 -> V_37 . V_95 ( & V_21 -> V_37 , & V_2 ) ;
if ( V_25 ) {
F_14 ( V_21 , V_244 ) ;
F_30 ( & V_21 -> V_93 ) ;
F_153 ( & V_21 -> V_37 ) ;
return 0 ;
}
F_30 ( & V_21 -> V_93 ) ;
return 0 ;
}
static void F_283 ( struct V_20 * V_21 ,
struct V_52 * V_40 , union V_68 * V_61 )
{
unsigned char V_461 [ V_462 ] ;
struct V_65 * V_41 = & V_21 -> V_37 . V_39 . V_40 . V_41 ;
struct V_149 * sin = (struct V_149 * ) V_40 ;
struct V_153 * V_340 = (struct V_153 * ) V_40 ;
if ( F_99 ( V_40 ) ) {
memset ( V_61 , 0 , sizeof *V_61 ) ;
} else if ( ( V_40 -> V_71 == V_152 ) &&
( ( F_37 ( V_340 -> V_154 . V_463 [ 0 ] ) & 0xFFF0FFFF ) ==
0xFF10A01B ) ) {
memcpy ( V_61 , & V_340 -> V_154 , sizeof *V_61 ) ;
} else if ( V_40 -> V_71 == V_72 ) {
memcpy ( V_61 , & ( (struct V_63 * ) V_40 ) -> V_69 , sizeof *V_61 ) ;
} else if ( ( V_40 -> V_71 == V_152 ) ) {
F_284 ( & V_340 -> V_154 , V_41 -> V_464 , V_461 ) ;
if ( V_21 -> V_37 . V_7 == V_10 )
V_461 [ 7 ] = 0x01 ;
* V_61 = * (union V_68 * ) ( V_461 + 4 ) ;
} else {
F_285 ( sin -> V_150 . V_151 , V_41 -> V_464 , V_461 ) ;
if ( V_21 -> V_37 . V_7 == V_10 )
V_461 [ 7 ] = 0x01 ;
* V_61 = * (union V_68 * ) ( V_461 + 4 ) ;
}
}
static int F_286 ( struct V_20 * V_21 ,
struct V_47 * V_48 )
{
struct V_57 V_58 ;
struct V_65 * V_41 = & V_21 -> V_37 . V_39 . V_40 . V_41 ;
T_10 V_339 ;
int V_25 ;
F_35 ( V_41 , & V_58 . V_61 ) ;
V_25 = F_36 ( V_21 -> V_37 . V_38 , V_21 -> V_37 . V_62 ,
& V_58 . V_61 , & V_58 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_34 ( V_21 , 0 ) ;
if ( V_25 )
return V_25 ;
F_283 ( V_21 , (struct V_52 * ) & V_48 -> V_40 , & V_58 . V_61 ) ;
V_58 . V_56 = F_287 ( V_21 -> V_56 ) ;
F_200 ( V_41 , & V_58 . V_465 ) ;
V_58 . V_87 = F_202 ( F_86 ( V_41 ) ) ;
V_58 . V_466 = 1 ;
V_339 = V_467 | V_468 |
V_469 | V_470 |
V_471 | V_472 |
V_473 |
V_474 ;
if ( V_21 -> V_37 . V_7 == V_12 )
V_339 |= V_475 |
V_476 |
V_477 |
V_478 |
V_479 ;
V_48 -> V_50 . V_51 = F_288 ( & V_354 , V_21 -> V_37 . V_38 ,
V_21 -> V_37 . V_62 , & V_58 ,
V_339 , V_19 ,
F_280 , V_48 ) ;
return F_289 ( V_48 -> V_50 . V_51 ) ;
}
static void F_290 ( struct V_355 * V_332 )
{
struct V_480 * V_481 = F_25 ( V_332 , struct V_480 , V_332 ) ;
struct V_47 * V_48 = V_481 -> V_48 ;
struct V_457 * V_482 = V_48 -> V_50 . V_51 ;
V_48 -> V_50 . V_51 -> V_96 = V_48 ;
F_280 ( 0 , V_482 ) ;
F_162 ( & V_48 -> V_49 , F_24 ) ;
F_26 ( V_481 ) ;
}
static void F_291 ( struct V_52 * V_40 , union V_68 * V_61 )
{
struct V_149 * sin = (struct V_149 * ) V_40 ;
struct V_153 * V_340 = (struct V_153 * ) V_40 ;
if ( F_99 ( V_40 ) ) {
memset ( V_61 , 0 , sizeof *V_61 ) ;
} else if ( V_40 -> V_71 == V_152 ) {
memcpy ( V_61 , & V_340 -> V_154 , sizeof *V_61 ) ;
} else {
V_61 -> V_483 [ 0 ] = 0xff ;
V_61 -> V_483 [ 1 ] = 0x0e ;
V_61 -> V_483 [ 2 ] = 0 ;
V_61 -> V_483 [ 3 ] = 0 ;
V_61 -> V_483 [ 4 ] = 0 ;
V_61 -> V_483 [ 5 ] = 0 ;
V_61 -> V_483 [ 6 ] = 0 ;
V_61 -> V_483 [ 7 ] = 0 ;
V_61 -> V_483 [ 8 ] = 0 ;
V_61 -> V_483 [ 9 ] = 0 ;
V_61 -> V_483 [ 10 ] = 0xff ;
V_61 -> V_483 [ 11 ] = 0xff ;
* ( T_9 * ) ( & V_61 -> V_483 [ 12 ] ) = sin -> V_150 . V_151 ;
}
}
static int F_292 ( struct V_20 * V_21 ,
struct V_47 * V_48 )
{
struct V_480 * V_332 ;
struct V_65 * V_41 = & V_21 -> V_37 . V_39 . V_40 . V_41 ;
int V_124 ;
struct V_52 * V_40 = (struct V_52 * ) & V_48 -> V_40 ;
struct V_195 * V_362 = NULL ;
if ( F_91 ( (struct V_52 * ) & V_48 -> V_40 ) )
return - V_59 ;
V_332 = F_59 ( sizeof *V_332 , V_19 ) ;
if ( ! V_332 )
return - V_99 ;
V_48 -> V_50 . V_51 = F_59 ( sizeof( struct V_457 ) , V_19 ) ;
if ( ! V_48 -> V_50 . V_51 ) {
V_124 = - V_99 ;
goto V_484;
}
F_291 ( V_40 , & V_48 -> V_50 . V_51 -> V_58 . V_61 ) ;
V_48 -> V_50 . V_51 -> V_58 . V_87 = F_202 ( 0xffff ) ;
if ( V_21 -> V_37 . V_7 == V_10 )
V_48 -> V_50 . V_51 -> V_58 . V_56 = F_287 ( V_60 ) ;
if ( V_41 -> V_231 )
V_362 = F_217 ( & V_232 , V_41 -> V_231 ) ;
if ( ! V_362 ) {
V_124 = - V_77 ;
goto V_485;
}
V_48 -> V_50 . V_51 -> V_58 . V_381 = F_220 ( V_362 ) ;
V_48 -> V_50 . V_51 -> V_58 . V_375 = 1 ;
V_48 -> V_50 . V_51 -> V_58 . V_379 = F_219 ( V_362 -> V_379 ) ;
F_132 ( V_362 ) ;
if ( ! V_48 -> V_50 . V_51 -> V_58 . V_379 ) {
V_124 = - V_59 ;
goto V_485;
}
F_48 ( (struct V_52 * ) & V_21 -> V_37 . V_39 . V_40 . V_53 ,
& V_48 -> V_50 . V_51 -> V_58 . V_465 ) ;
V_332 -> V_37 = V_21 ;
V_332 -> V_48 = V_48 ;
F_207 ( & V_332 -> V_332 , F_290 ) ;
F_293 ( & V_48 -> V_49 ) ;
F_198 ( V_337 , & V_332 -> V_332 ) ;
return 0 ;
V_485:
F_26 ( V_48 -> V_50 . V_51 ) ;
V_484:
F_26 ( V_332 ) ;
return V_124 ;
}
int F_294 ( struct V_94 * V_37 , struct V_52 * V_40 ,
void * V_96 )
{
struct V_20 * V_21 ;
struct V_47 * V_48 ;
int V_25 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
if ( ! F_10 ( V_21 , V_327 ) &&
! F_10 ( V_21 , V_335 ) )
return - V_59 ;
V_48 = F_173 ( sizeof *V_48 , V_19 ) ;
if ( ! V_48 )
return - V_99 ;
memcpy ( & V_48 -> V_40 , V_40 , F_184 ( V_40 ) ) ;
V_48 -> V_96 = V_96 ;
V_48 -> V_21 = V_21 ;
F_295 ( & V_21 -> V_26 ) ;
F_296 ( & V_48 -> V_44 , & V_21 -> V_105 ) ;
F_297 ( & V_21 -> V_26 ) ;
if ( F_50 ( V_37 -> V_38 , V_37 -> V_62 ) ) {
F_298 ( & V_48 -> V_49 ) ;
V_25 = F_292 ( V_21 , V_48 ) ;
} else if ( F_160 ( V_37 -> V_38 , V_37 -> V_62 ) )
V_25 = F_286 ( V_21 , V_48 ) ;
else
V_25 = - V_147 ;
if ( V_25 ) {
F_299 ( & V_21 -> V_26 ) ;
F_29 ( & V_48 -> V_44 ) ;
F_300 ( & V_21 -> V_26 ) ;
F_26 ( V_48 ) ;
}
return V_25 ;
}
void F_301 ( struct V_94 * V_37 , struct V_52 * V_40 )
{
struct V_20 * V_21 ;
struct V_47 * V_48 ;
V_21 = F_25 ( V_37 , struct V_20 , V_37 ) ;
F_299 ( & V_21 -> V_26 ) ;
F_51 (mc, &id_priv->mc_list, list) {
if ( ! memcmp ( & V_48 -> V_40 , V_40 , F_184 ( V_40 ) ) ) {
F_29 ( & V_48 -> V_44 ) ;
F_300 ( & V_21 -> V_26 ) ;
if ( V_37 -> V_108 )
F_302 ( V_37 -> V_108 ,
& V_48 -> V_50 . V_51 -> V_58 . V_61 ,
F_115 ( V_48 -> V_50 . V_51 -> V_58 . V_458 ) ) ;
F_80 ( V_21 -> V_35 -> V_38 != V_37 -> V_38 ) ;
if ( F_160 ( V_37 -> V_38 , V_37 -> V_62 ) ) {
F_161 ( V_48 -> V_50 . V_51 ) ;
F_26 ( V_48 ) ;
} else if ( F_50 ( V_37 -> V_38 , V_37 -> V_62 ) )
F_162 ( & V_48 -> V_49 , F_24 ) ;
return;
}
}
F_300 ( & V_21 -> V_26 ) ;
}
static int F_303 ( struct V_195 * V_362 , struct V_20 * V_21 )
{
struct V_65 * V_41 ;
struct V_358 * V_332 ;
V_41 = & V_21 -> V_37 . V_39 . V_40 . V_41 ;
if ( ( V_41 -> V_231 == V_362 -> V_204 ) &&
memcmp ( V_41 -> V_81 , V_362 -> V_41 , V_362 -> V_374 ) ) {
F_171 ( V_486 L_5 ,
V_362 -> V_329 , & V_21 -> V_37 ) ;
V_332 = F_59 ( sizeof *V_332 , V_19 ) ;
if ( ! V_332 )
return - V_99 ;
F_207 ( & V_332 -> V_332 , F_205 ) ;
V_332 -> V_37 = V_21 ;
V_332 -> V_2 . V_2 = V_487 ;
F_18 ( & V_21 -> V_36 ) ;
F_198 ( V_337 , & V_332 -> V_332 ) ;
}
return 0 ;
}
static int F_304 ( struct V_488 * V_489 , unsigned long V_2 ,
void * V_490 )
{
struct V_195 * V_362 = F_305 ( V_490 ) ;
struct V_34 * V_35 ;
struct V_20 * V_21 ;
int V_25 = V_491 ;
if ( F_121 ( V_362 ) != & V_232 )
return V_491 ;
if ( V_2 != V_492 )
return V_491 ;
if ( ! ( V_362 -> V_24 & V_493 ) || ! ( V_362 -> V_364 & V_494 ) )
return V_491 ;
F_28 ( & V_26 ) ;
F_51 (cma_dev, &dev_list, list)
F_51 (id_priv, &cma_dev->id_list, list) {
V_25 = F_303 ( V_362 , V_21 ) ;
if ( V_25 )
goto V_82;
}
V_82:
F_30 ( & V_26 ) ;
return V_25 ;
}
static void F_306 ( struct V_73 * V_38 )
{
struct V_34 * V_35 ;
struct V_20 * V_21 ;
V_35 = F_173 ( sizeof *V_35 , V_19 ) ;
if ( ! V_35 )
return;
V_35 -> V_38 = V_38 ;
F_64 ( & V_35 -> V_23 ) ;
F_65 ( & V_35 -> V_36 , 1 ) ;
F_66 ( & V_35 -> V_45 ) ;
F_307 ( V_38 , & V_495 , V_35 ) ;
F_28 ( & V_26 ) ;
F_20 ( & V_35 -> V_44 , & V_496 ) ;
F_51 (id_priv, &listen_any_list, list)
F_193 ( V_21 , V_35 ) ;
F_30 ( & V_26 ) ;
}
static int F_308 ( struct V_20 * V_21 )
{
struct V_249 V_2 ;
enum V_22 V_27 ;
int V_25 = 0 ;
V_27 = F_14 ( V_21 , V_359 ) ;
if ( V_27 == V_244 )
return 0 ;
F_154 ( V_21 , V_27 ) ;
F_28 ( & V_21 -> V_93 ) ;
if ( ! F_10 ( V_21 , V_359 ) )
goto V_82;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_497 ;
V_25 = V_21 -> V_37 . V_95 ( & V_21 -> V_37 , & V_2 ) ;
V_82:
F_30 ( & V_21 -> V_93 ) ;
return V_25 ;
}
static void F_309 ( struct V_34 * V_35 )
{
struct V_20 * V_21 ;
int V_25 ;
F_28 ( & V_26 ) ;
while ( ! F_150 ( & V_35 -> V_45 ) ) {
V_21 = F_151 ( V_35 -> V_45 . V_238 ,
struct V_20 , V_44 ) ;
F_29 ( & V_21 -> V_104 ) ;
F_152 ( & V_21 -> V_44 ) ;
F_18 ( & V_21 -> V_36 ) ;
F_30 ( & V_26 ) ;
V_25 = V_21 -> V_245 ? 1 : F_308 ( V_21 ) ;
F_56 ( V_21 ) ;
if ( V_25 )
F_153 ( & V_21 -> V_37 ) ;
F_28 ( & V_26 ) ;
}
F_30 ( & V_26 ) ;
F_21 ( V_35 ) ;
F_165 ( & V_35 -> V_23 ) ;
}
static void F_310 ( struct V_73 * V_38 , void * V_498 )
{
struct V_34 * V_35 = V_498 ;
if ( ! V_35 )
return;
F_28 ( & V_26 ) ;
F_29 ( & V_35 -> V_44 ) ;
F_30 ( & V_26 ) ;
F_309 ( V_35 ) ;
F_26 ( V_35 ) ;
}
static int F_311 ( struct V_499 * V_500 , struct V_501 * V_502 )
{
struct V_503 * V_504 ;
struct V_505 * V_506 ;
struct V_20 * V_21 ;
struct V_94 * V_37 = NULL ;
struct V_34 * V_35 ;
int V_507 = 0 , V_508 = 0 ;
F_28 ( & V_26 ) ;
F_51 (cma_dev, &dev_list, list) {
if ( V_507 < V_502 -> args [ 0 ] ) {
V_507 ++ ;
continue;
}
V_508 = 0 ;
F_51 (id_priv, &cma_dev->id_list, list) {
if ( V_508 < V_502 -> args [ 1 ] ) {
V_508 ++ ;
continue;
}
V_506 = F_312 ( V_500 , & V_504 , V_502 -> V_504 -> V_509 ,
sizeof *V_506 , V_510 ,
V_511 ,
V_512 ) ;
if ( ! V_506 )
goto V_82;
memset ( V_506 , 0 , sizeof *V_506 ) ;
V_37 = & V_21 -> V_37 ;
V_506 -> V_43 = V_37 -> V_39 . V_40 . V_41 . V_66 ;
V_506 -> V_62 = V_37 -> V_62 ;
V_506 -> V_231 =
V_37 -> V_39 . V_40 . V_41 . V_231 ;
if ( F_313 ( V_500 , V_504 ,
F_184 ( F_31 ( V_21 ) ) ,
F_31 ( V_21 ) ,
V_513 ) )
goto V_82;
if ( F_313 ( V_500 , V_504 ,
F_184 ( F_31 ( V_21 ) ) ,
F_32 ( V_21 ) ,
V_514 ) )
goto V_82;
V_506 -> V_515 = V_21 -> V_100 ;
V_506 -> V_516 = V_37 -> V_7 ;
V_506 -> V_517 = V_21 -> V_27 ;
V_506 -> V_125 = V_21 -> V_125 ;
V_506 -> V_98 = V_37 -> V_98 ;
V_508 ++ ;
}
V_502 -> args [ 1 ] = 0 ;
V_507 ++ ;
}
V_82:
F_30 ( & V_26 ) ;
V_502 -> args [ 0 ] = V_507 ;
V_502 -> args [ 1 ] = V_508 ;
return V_500 -> V_518 ;
}
static int T_12 F_314 ( void )
{
int V_25 ;
V_337 = F_315 ( L_6 ) ;
if ( ! V_337 )
return - V_99 ;
F_316 ( & V_354 ) ;
F_317 ( & V_396 ) ;
F_318 ( & V_519 ) ;
V_25 = F_319 ( & V_495 ) ;
if ( V_25 )
goto V_124;
if ( F_320 ( V_510 , V_520 , V_521 ) )
F_171 ( V_328 L_7 ) ;
return 0 ;
V_124:
F_321 ( & V_519 ) ;
F_322 ( & V_396 ) ;
F_323 ( & V_354 ) ;
F_324 ( V_337 ) ;
return V_25 ;
}
static void T_13 F_325 ( void )
{
F_326 ( V_510 ) ;
F_327 ( & V_495 ) ;
F_321 ( & V_519 ) ;
F_322 ( & V_396 ) ;
F_323 ( & V_354 ) ;
F_324 ( V_337 ) ;
F_328 ( & V_9 ) ;
F_328 ( & V_11 ) ;
F_328 ( & V_13 ) ;
F_328 ( & V_15 ) ;
}
