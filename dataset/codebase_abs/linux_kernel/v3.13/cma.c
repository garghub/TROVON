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
static void F_29 ( struct V_48 * V_49 , struct V_50 * V_22 )
{
V_22 -> V_51 = V_52 ;
F_30 ( V_22 , (union V_53 * ) & V_49 -> V_54 ) ;
F_31 ( V_22 , F_32 ( V_49 -> V_55 ) ) ;
}
static int F_33 ( struct V_33 * V_21 , struct V_50 * V_22 )
{
int V_6 ;
if ( V_21 -> V_56 != V_57 ) {
V_6 = F_34 ( V_21 , V_22 ) ;
} else {
F_29 ( (struct V_48 * ) V_21 , V_22 ) ;
V_6 = 0 ;
}
return V_6 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_1 * V_58 )
{
struct V_50 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
struct V_15 * V_16 ;
union V_53 V_59 , V_60 ;
int V_6 = - V_61 ;
T_1 V_62 , V_63 ;
enum V_64 V_65 = V_22 -> V_51 == V_52 ?
V_66 : V_67 ;
if ( V_65 != V_66 &&
V_2 -> V_18 . V_41 == V_45 )
return - V_40 ;
F_19 ( & V_7 ) ;
F_36 ( V_22 , & V_60 ) ;
memcpy ( & V_59 , V_22 -> V_68 +
F_37 ( V_22 ) , sizeof V_59 ) ;
if ( V_58 &&
F_38 ( V_58 -> V_18 . V_19 ,
V_58 -> V_18 . V_47 ) == V_65 ) {
V_16 = V_58 -> V_16 ;
V_62 = V_58 -> V_18 . V_47 ;
if ( F_10 ( V_16 -> V_19 -> V_24 ) == V_69 &&
F_38 ( V_16 -> V_19 , V_62 ) == V_67 )
V_6 = F_39 ( V_16 -> V_19 , & V_60 ,
& V_63 , NULL ) ;
else
V_6 = F_39 ( V_16 -> V_19 , & V_59 ,
& V_63 , NULL ) ;
if ( ! V_6 && ( V_62 == V_63 ) ) {
V_2 -> V_18 . V_47 = V_63 ;
goto V_70;
}
}
F_40 (cma_dev, &dev_list, list) {
for ( V_62 = 1 ; V_62 <= V_16 -> V_19 -> V_71 ; ++ V_62 ) {
if ( V_58 &&
V_58 -> V_16 == V_16 &&
V_58 -> V_18 . V_47 == V_62 )
continue;
if ( F_38 ( V_16 -> V_19 , V_62 ) == V_65 ) {
if ( F_10 ( V_16 -> V_19 -> V_24 ) == V_69 &&
F_38 ( V_16 -> V_19 , V_62 ) == V_67 )
V_6 = F_39 ( V_16 -> V_19 , & V_60 , & V_63 , NULL ) ;
else
V_6 = F_39 ( V_16 -> V_19 , & V_59 , & V_63 , NULL ) ;
if ( ! V_6 && ( V_62 == V_63 ) ) {
V_2 -> V_18 . V_47 = V_63 ;
goto V_70;
}
}
}
}
V_70:
if ( ! V_6 )
F_8 ( V_2 , V_16 ) ;
F_21 ( & V_7 ) ;
return V_6 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_15 * V_16 , * V_72 ;
struct V_48 * V_21 ;
union V_53 V_59 , V_73 , * V_74 ;
T_3 V_75 , V_76 ;
T_1 V_77 ;
int V_78 ;
V_16 = NULL ;
V_21 = (struct V_48 * ) F_23 ( V_2 ) ;
V_74 = (union V_53 * ) & V_21 -> V_54 ;
V_75 = F_32 ( V_21 -> V_55 ) ;
F_40 (cur_dev, &dev_list, list) {
if ( F_10 ( V_72 -> V_19 -> V_24 ) != V_69 )
continue;
for ( V_77 = 1 ; V_77 <= V_72 -> V_19 -> V_71 ; ++ V_77 ) {
if ( F_42 ( V_72 -> V_19 , V_77 , V_75 , & V_76 ) )
continue;
for ( V_78 = 0 ; ! F_43 ( V_72 -> V_19 , V_77 , V_78 , & V_59 ) ; V_78 ++ ) {
if ( ! memcmp ( & V_59 , V_74 , sizeof( V_59 ) ) ) {
V_16 = V_72 ;
V_73 = V_59 ;
V_2 -> V_18 . V_47 = V_77 ;
goto V_79;
}
if ( ! V_16 && ( V_59 . V_80 . V_81 ==
V_74 -> V_80 . V_81 ) ) {
V_16 = V_72 ;
V_73 = V_59 ;
V_2 -> V_18 . V_47 = V_77 ;
}
}
}
}
if ( ! V_16 )
return - V_61 ;
V_79:
F_8 ( V_2 , V_16 ) ;
V_21 = (struct V_48 * ) F_22 ( V_2 ) ;
memcpy ( & V_21 -> V_54 , & V_73 , sizeof V_73 ) ;
F_29 ( V_21 , & V_2 -> V_18 . V_20 . V_21 . V_22 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( F_13 ( & V_2 -> V_17 ) )
F_14 ( & V_2 -> V_4 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
enum V_3 V_8 )
{
F_19 ( & V_2 -> V_82 ) ;
if ( V_2 -> V_8 != V_8 ) {
F_21 ( & V_2 -> V_82 ) ;
return - V_40 ;
}
return 0 ;
}
struct V_83 * F_46 ( T_4 V_84 ,
void * V_85 , enum V_86 V_41 ,
enum V_87 V_88 )
{
struct V_1 * V_2 ;
V_2 = F_47 ( sizeof *V_2 , V_89 ) ;
if ( ! V_2 )
return F_48 ( - V_90 ) ;
V_2 -> V_91 = F_49 ( V_92 ) ;
V_2 -> V_8 = V_93 ;
V_2 -> V_18 . V_85 = V_85 ;
V_2 -> V_18 . V_84 = V_84 ;
V_2 -> V_18 . V_41 = V_41 ;
V_2 -> V_18 . V_88 = V_88 ;
F_50 ( & V_2 -> V_7 ) ;
F_51 ( & V_2 -> V_94 ) ;
F_52 ( & V_2 -> V_4 ) ;
F_53 ( & V_2 -> V_17 , 1 ) ;
F_51 ( & V_2 -> V_82 ) ;
F_54 ( & V_2 -> V_95 ) ;
F_54 ( & V_2 -> V_96 ) ;
F_55 ( & V_2 -> V_97 , sizeof V_2 -> V_97 ) ;
return & V_2 -> V_18 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_98 * V_99 )
{
struct V_100 V_101 ;
int V_102 , V_6 ;
V_101 . V_103 = V_104 ;
V_6 = F_57 ( & V_2 -> V_18 , & V_101 , & V_102 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_58 ( V_99 , & V_101 , V_102 ) ;
if ( V_6 )
return V_6 ;
V_101 . V_103 = V_105 ;
V_6 = F_58 ( V_99 , & V_101 , V_106 ) ;
if ( V_6 )
return V_6 ;
V_101 . V_103 = V_107 ;
V_101 . V_108 = 0 ;
V_6 = F_58 ( V_99 , & V_101 , V_106 | V_109 ) ;
return V_6 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_98 * V_99 )
{
struct V_100 V_101 ;
int V_102 , V_6 ;
V_101 . V_103 = V_104 ;
V_6 = F_57 ( & V_2 -> V_18 , & V_101 , & V_102 ) ;
if ( V_6 )
return V_6 ;
return F_58 ( V_99 , & V_101 , V_102 ) ;
}
int F_60 ( struct V_83 * V_18 , struct V_110 * V_111 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
struct V_98 * V_99 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( V_18 -> V_19 != V_111 -> V_19 )
return - V_40 ;
V_99 = F_61 ( V_111 , V_113 ) ;
if ( F_62 ( V_99 ) )
return F_63 ( V_99 ) ;
if ( V_18 -> V_88 == V_114 )
V_6 = F_56 ( V_2 , V_99 ) ;
else
V_6 = F_59 ( V_2 , V_99 ) ;
if ( V_6 )
goto V_115;
V_18 -> V_99 = V_99 ;
V_2 -> V_116 = V_99 -> V_116 ;
V_2 -> V_117 = ( V_99 -> V_117 != NULL ) ;
return 0 ;
V_115:
F_64 ( V_99 ) ;
return V_6 ;
}
void F_65 ( struct V_83 * V_18 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
F_19 ( & V_2 -> V_94 ) ;
F_64 ( V_2 -> V_18 . V_99 ) ;
V_2 -> V_18 . V_99 = NULL ;
F_21 ( & V_2 -> V_94 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_100 V_101 ;
int V_102 , V_6 ;
F_19 ( & V_2 -> V_94 ) ;
if ( ! V_2 -> V_18 . V_99 ) {
V_6 = 0 ;
goto V_70;
}
V_101 . V_103 = V_104 ;
V_6 = F_57 ( & V_2 -> V_18 , & V_101 , & V_102 ) ;
if ( V_6 )
goto V_70;
V_6 = F_58 ( V_2 -> V_18 . V_99 , & V_101 , V_102 ) ;
if ( V_6 )
goto V_70;
V_101 . V_103 = V_105 ;
V_6 = F_57 ( & V_2 -> V_18 , & V_101 , & V_102 ) ;
if ( V_6 )
goto V_70;
if ( V_119 )
V_101 . V_120 = V_119 -> V_121 ;
V_6 = F_58 ( V_2 -> V_18 . V_99 , & V_101 , V_102 ) ;
V_70:
F_21 ( & V_2 -> V_94 ) ;
return V_6 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_100 V_101 ;
int V_102 , V_6 ;
F_19 ( & V_2 -> V_94 ) ;
if ( ! V_2 -> V_18 . V_99 ) {
V_6 = 0 ;
goto V_70;
}
V_101 . V_103 = V_107 ;
V_6 = F_57 ( & V_2 -> V_18 , & V_101 , & V_102 ) ;
if ( V_6 )
goto V_70;
if ( V_119 )
V_101 . V_122 = V_119 -> V_123 ;
V_6 = F_58 ( V_2 -> V_18 . V_99 , & V_101 , V_102 ) ;
V_70:
F_21 ( & V_2 -> V_94 ) ;
return V_6 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_100 V_101 ;
int V_6 ;
F_19 ( & V_2 -> V_94 ) ;
if ( ! V_2 -> V_18 . V_99 ) {
V_6 = 0 ;
goto V_70;
}
V_101 . V_103 = V_124 ;
V_6 = F_58 ( V_2 -> V_18 . V_99 , & V_101 , V_106 ) ;
V_70:
F_21 ( & V_2 -> V_94 ) ;
return V_6 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_100 * V_101 , int * V_102 )
{
struct V_50 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
int V_6 ;
T_3 V_75 ;
if ( F_38 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ) ==
V_66 )
V_75 = F_70 ( V_22 ) ;
else
V_75 = 0xffff ;
V_6 = F_42 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ,
V_75 , & V_101 -> V_125 ) ;
if ( V_6 )
return V_6 ;
V_101 -> V_47 = V_2 -> V_18 . V_47 ;
* V_102 = V_106 | V_126 | V_127 ;
if ( V_2 -> V_18 . V_88 == V_114 ) {
V_6 = F_25 ( V_2 , 0 ) ;
if ( V_6 )
return V_6 ;
V_101 -> V_37 = V_2 -> V_37 ;
* V_102 |= V_128 ;
} else {
V_101 -> V_129 = 0 ;
* V_102 |= V_130 ;
}
return 0 ;
}
int F_57 ( struct V_83 * V_18 , struct V_100 * V_101 ,
int * V_102 )
{
struct V_1 * V_2 ;
int V_6 = 0 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
switch ( F_10 ( V_2 -> V_18 . V_19 -> V_24 ) ) {
case V_69 :
if ( ! V_2 -> V_131 . V_32 || ( V_2 -> V_18 . V_88 == V_114 ) )
V_6 = F_69 ( V_2 , V_101 , V_102 ) ;
else
V_6 = F_71 ( V_2 -> V_131 . V_32 , V_101 ,
V_102 ) ;
if ( V_101 -> V_103 == V_105 )
V_101 -> V_132 = V_2 -> V_97 ;
break;
case V_133 :
if ( ! V_2 -> V_131 . V_134 ) {
V_101 -> V_129 = 0 ;
* V_102 = V_106 | V_130 ;
} else
V_6 = F_72 ( V_2 -> V_131 . V_134 , V_101 ,
V_102 ) ;
break;
default:
V_6 = - V_135 ;
break;
}
return V_6 ;
}
static inline int F_73 ( struct V_33 * V_21 )
{
switch ( V_21 -> V_56 ) {
case V_136 :
return F_74 ( ( (struct V_137 * ) V_21 ) -> V_138 . V_139 ) ;
case V_140 :
return F_75 ( & ( (struct V_141 * ) V_21 ) -> V_142 ) ;
case V_57 :
return F_76 ( & ( (struct V_48 * ) V_21 ) -> V_54 ) ;
default:
return 0 ;
}
}
static inline int F_77 ( struct V_33 * V_21 )
{
switch ( V_21 -> V_56 ) {
case V_136 :
return F_78 ( ( (struct V_137 * ) V_21 ) -> V_138 . V_139 ) ;
case V_140 :
return F_79 ( & ( (struct V_141 * ) V_21 ) -> V_142 ) ;
case V_57 :
return F_80 ( & ( (struct V_48 * ) V_21 ) -> V_54 ) ;
default:
return 0 ;
}
}
static inline int F_81 ( struct V_33 * V_21 )
{
return F_73 ( V_21 ) || F_77 ( V_21 ) ;
}
static int F_82 ( struct V_33 * V_143 , struct V_33 * V_144 )
{
if ( V_143 -> V_56 != V_144 -> V_56 )
return - 1 ;
switch ( V_143 -> V_56 ) {
case V_136 :
return ( (struct V_137 * ) V_143 ) -> V_138 . V_139 !=
( (struct V_137 * ) V_144 ) -> V_138 . V_139 ;
case V_140 :
return F_83 ( & ( (struct V_141 * ) V_143 ) -> V_142 ,
& ( (struct V_141 * ) V_144 ) -> V_142 ) ;
default:
return F_84 ( & ( (struct V_48 * ) V_143 ) -> V_54 ,
& ( (struct V_48 * ) V_144 ) -> V_54 ) ;
}
}
static T_5 F_85 ( struct V_33 * V_21 )
{
struct V_48 * V_49 ;
switch ( V_21 -> V_56 ) {
case V_136 :
return ( (struct V_137 * ) V_21 ) -> V_145 ;
case V_140 :
return ( (struct V_141 * ) V_21 ) -> V_146 ;
case V_57 :
V_49 = (struct V_48 * ) V_21 ;
return F_86 ( ( T_3 ) ( F_87 ( V_49 -> V_147 ) &
F_87 ( V_49 -> V_148 ) ) ) ;
default:
return 0 ;
}
}
static inline int F_88 ( struct V_33 * V_21 )
{
return ! F_85 ( V_21 ) ;
}
static void F_89 ( struct V_83 * V_18 , struct V_83 * V_149 ,
struct V_150 * V_151 )
{
struct V_48 * V_152 , * V_32 ;
V_152 = (struct V_48 * ) & V_149 -> V_20 . V_21 . V_34 ;
V_32 = (struct V_48 * ) & V_18 -> V_20 . V_21 . V_34 ;
V_32 -> V_153 = V_152 -> V_153 ;
V_32 -> V_55 = V_151 -> V_75 ;
V_32 -> V_154 = V_151 -> V_155 ;
memcpy ( & V_32 -> V_54 , & V_151 -> V_73 , 16 ) ;
V_32 -> V_147 = V_152 -> V_147 ;
V_32 -> V_148 = F_90 ( 0xffffffffffffffffULL ) ;
V_32 -> V_156 = V_152 -> V_156 ;
V_32 = (struct V_48 * ) & V_18 -> V_20 . V_21 . V_35 ;
V_32 -> V_153 = V_152 -> V_153 ;
V_32 -> V_55 = V_151 -> V_75 ;
V_32 -> V_154 = V_151 -> V_155 ;
memcpy ( & V_32 -> V_54 , & V_151 -> V_74 , 16 ) ;
}
static void F_91 ( struct V_83 * V_18 , struct V_83 * V_149 ,
struct V_11 * V_12 )
{
struct V_137 * V_157 , * V_158 ;
V_157 = (struct V_137 * ) & V_149 -> V_20 . V_21 . V_34 ;
V_158 = (struct V_137 * ) & V_18 -> V_20 . V_21 . V_34 ;
V_158 -> V_159 = V_157 -> V_159 ;
V_158 -> V_138 . V_139 = V_12 -> V_35 . V_158 . V_21 ;
V_158 -> V_145 = V_157 -> V_145 ;
V_158 = (struct V_137 * ) & V_18 -> V_20 . V_21 . V_35 ;
V_158 -> V_159 = V_157 -> V_159 ;
V_158 -> V_138 . V_139 = V_12 -> V_34 . V_158 . V_21 ;
V_158 -> V_145 = V_12 -> V_62 ;
}
static void F_92 ( struct V_83 * V_18 , struct V_83 * V_149 ,
struct V_11 * V_12 )
{
struct V_141 * V_160 , * V_161 ;
V_160 = (struct V_141 * ) & V_149 -> V_20 . V_21 . V_34 ;
V_161 = (struct V_141 * ) & V_18 -> V_20 . V_21 . V_34 ;
V_161 -> V_162 = V_160 -> V_162 ;
V_161 -> V_142 = V_12 -> V_35 . V_161 ;
V_161 -> V_146 = V_160 -> V_146 ;
V_161 = (struct V_141 * ) & V_18 -> V_20 . V_21 . V_35 ;
V_161 -> V_162 = V_160 -> V_162 ;
V_161 -> V_142 = V_12 -> V_34 . V_161 ;
V_161 -> V_146 = V_12 -> V_62 ;
}
static int F_93 ( struct V_83 * V_18 , struct V_83 * V_149 ,
struct V_163 * V_164 )
{
struct V_11 * V_12 ;
if ( ( V_149 -> V_20 . V_21 . V_34 . V_36 == V_57 ) &&
( V_164 -> V_165 == V_166 ) ) {
F_89 ( V_18 , V_149 , V_164 -> V_167 . V_168 . V_169 ) ;
return 0 ;
}
V_12 = V_164 -> V_170 ;
if ( V_12 -> V_171 != V_172 )
return - V_40 ;
switch ( F_6 ( V_12 ) ) {
case 4 :
F_91 ( V_18 , V_149 , V_12 ) ;
break;
case 6 :
F_92 ( V_18 , V_149 , V_12 ) ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static inline int F_94 ( struct V_1 * V_2 )
{
return F_24 ( V_2 ) == V_57 ? 0 : sizeof( struct V_11 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
switch ( F_38 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ) ) {
case V_66 :
if ( V_2 -> V_173 )
F_96 ( V_2 -> V_174 , V_2 -> V_173 ) ;
break;
default:
break;
}
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_1 * V_175 ;
F_19 ( & V_7 ) ;
F_20 ( & V_2 -> V_25 ) ;
while ( ! F_98 ( & V_2 -> V_95 ) ) {
V_175 = F_99 ( V_2 -> V_95 . V_176 ,
struct V_1 , V_95 ) ;
F_100 ( & V_175 -> V_25 ) ;
F_20 ( & V_175 -> V_95 ) ;
F_21 ( & V_7 ) ;
F_101 ( & V_175 -> V_18 ) ;
F_19 ( & V_7 ) ;
}
F_21 ( & V_7 ) ;
}
static void F_102 ( struct V_1 * V_2 ,
enum V_3 V_8 )
{
switch ( V_8 ) {
case V_177 :
F_103 ( & V_2 -> V_18 . V_20 . V_21 . V_22 ) ;
break;
case V_178 :
F_95 ( V_2 ) ;
break;
case V_179 :
if ( F_81 ( F_22 ( V_2 ) ) && ! V_2 -> V_16 )
F_97 ( V_2 ) ;
break;
default:
break;
}
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_180 * V_181 = V_2 -> V_181 ;
if ( ! V_181 )
return;
F_19 ( & V_7 ) ;
F_105 ( & V_2 -> V_182 ) ;
if ( F_106 ( & V_181 -> V_183 ) ) {
F_107 ( V_181 -> V_41 , V_181 -> V_62 ) ;
F_17 ( V_181 ) ;
}
F_21 ( & V_7 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
while ( ! F_98 ( & V_2 -> V_96 ) ) {
V_29 = F_16 ( V_2 -> V_96 . V_176 ,
struct V_28 , V_25 ) ;
F_20 ( & V_29 -> V_25 ) ;
switch ( F_38 ( V_2 -> V_16 -> V_19 , V_2 -> V_18 . V_47 ) ) {
case V_66 :
F_109 ( V_29 -> V_31 . V_32 ) ;
F_17 ( V_29 ) ;
break;
case V_67 :
F_110 ( & V_29 -> V_30 , F_15 ) ;
break;
default:
break;
}
}
}
void F_101 ( struct V_83 * V_18 )
{
struct V_1 * V_2 ;
enum V_3 V_8 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
V_8 = F_5 ( V_2 , V_184 ) ;
F_102 ( V_2 , V_8 ) ;
F_19 ( & V_2 -> V_82 ) ;
F_21 ( & V_2 -> V_82 ) ;
if ( V_2 -> V_16 ) {
switch ( F_10 ( V_2 -> V_18 . V_19 -> V_24 ) ) {
case V_69 :
if ( V_2 -> V_131 . V_32 )
F_111 ( V_2 -> V_131 . V_32 ) ;
break;
case V_133 :
if ( V_2 -> V_131 . V_134 )
F_112 ( V_2 -> V_131 . V_134 ) ;
break;
default:
break;
}
F_108 ( V_2 ) ;
F_18 ( V_2 ) ;
}
F_104 ( V_2 ) ;
F_44 ( V_2 ) ;
F_113 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_185 )
F_44 ( V_2 -> V_18 . V_85 ) ;
F_17 ( V_2 -> V_18 . V_20 . V_186 ) ;
F_17 ( V_2 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_66 ( V_2 , NULL ) ;
if ( V_6 )
goto V_187;
V_6 = F_67 ( V_2 , NULL ) ;
if ( V_6 )
goto V_187;
V_6 = F_115 ( V_2 -> V_131 . V_32 , NULL , 0 ) ;
if ( V_6 )
goto V_187;
return 0 ;
V_187:
F_68 ( V_2 ) ;
F_116 ( V_2 -> V_131 . V_32 , V_188 ,
NULL , 0 , NULL , 0 ) ;
return V_6 ;
}
static void F_117 ( struct V_189 * V_165 ,
struct V_190 * V_191 ,
void * V_170 )
{
V_165 -> V_167 . V_192 . V_170 = V_170 ;
V_165 -> V_167 . V_192 . V_193 = V_194 ;
V_165 -> V_167 . V_192 . V_121 = V_191 -> V_121 ;
V_165 -> V_167 . V_192 . V_123 = V_191 -> V_123 ;
V_165 -> V_167 . V_192 . V_195 = V_191 -> V_195 ;
V_165 -> V_167 . V_192 . V_196 = V_191 -> V_196 ;
V_165 -> V_167 . V_192 . V_117 = V_191 -> V_117 ;
V_165 -> V_167 . V_192 . V_116 = V_191 -> V_197 ;
}
static int F_118 ( struct V_198 * V_131 , struct V_163 * V_164 )
{
struct V_1 * V_2 = V_131 -> V_85 ;
struct V_189 V_165 ;
int V_6 = 0 ;
if ( ( V_164 -> V_165 != V_199 &&
F_45 ( V_2 , V_200 ) ) ||
( V_164 -> V_165 == V_199 &&
F_45 ( V_2 , V_201 ) ) )
return 0 ;
memset ( & V_165 , 0 , sizeof V_165 ) ;
switch ( V_164 -> V_165 ) {
case V_202 :
case V_203 :
V_165 . V_165 = V_204 ;
V_165 . V_205 = - V_206 ;
break;
case V_207 :
if ( V_2 -> V_18 . V_99 ) {
V_165 . V_205 = F_114 ( V_2 ) ;
V_165 . V_165 = V_165 . V_205 ? V_208 :
V_209 ;
} else {
V_165 . V_165 = V_210 ;
}
F_117 ( & V_165 , & V_164 -> V_167 . V_211 ,
V_164 -> V_170 ) ;
break;
case V_212 :
case V_213 :
V_165 . V_165 = V_209 ;
break;
case V_214 :
V_165 . V_205 = - V_206 ;
case V_215 :
case V_216 :
if ( ! F_4 ( V_2 , V_200 ,
V_201 ) )
goto V_70;
V_165 . V_165 = V_217 ;
break;
case V_199 :
V_165 . V_165 = V_218 ;
break;
case V_219 :
goto V_70;
case V_220 :
F_68 ( V_2 ) ;
V_165 . V_205 = V_164 -> V_167 . V_221 . V_222 ;
V_165 . V_165 = V_223 ;
V_165 . V_167 . V_192 . V_170 = V_164 -> V_170 ;
V_165 . V_167 . V_192 . V_193 = V_224 ;
break;
default:
F_119 ( V_225 L_1 ,
V_164 -> V_165 ) ;
goto V_70;
}
V_6 = V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_165 ) ;
if ( V_6 ) {
V_2 -> V_131 . V_32 = NULL ;
F_5 ( V_2 , V_184 ) ;
F_21 ( & V_2 -> V_82 ) ;
F_101 ( & V_2 -> V_18 ) ;
return V_6 ;
}
V_70:
F_21 ( & V_2 -> V_82 ) ;
return V_6 ;
}
static struct V_1 * F_120 ( struct V_83 * V_149 ,
struct V_163 * V_164 )
{
struct V_1 * V_2 ;
struct V_83 * V_18 ;
struct V_226 * V_227 ;
int V_6 ;
V_18 = F_46 ( V_149 -> V_84 , V_149 -> V_85 ,
V_149 -> V_41 , V_164 -> V_167 . V_168 . V_88 ) ;
if ( F_62 ( V_18 ) )
return NULL ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( F_93 ( V_18 , V_149 , V_164 ) )
goto V_115;
V_227 = & V_18 -> V_20 ;
V_227 -> V_228 = V_164 -> V_167 . V_168 . V_229 ? 2 : 1 ;
V_227 -> V_186 = F_121 ( sizeof * V_227 -> V_186 * V_227 -> V_228 ,
V_89 ) ;
if ( ! V_227 -> V_186 )
goto V_115;
V_227 -> V_186 [ 0 ] = * V_164 -> V_167 . V_168 . V_169 ;
if ( V_227 -> V_228 == 2 )
V_227 -> V_186 [ 1 ] = * V_164 -> V_167 . V_168 . V_229 ;
if ( F_81 ( F_22 ( V_2 ) ) ) {
V_227 -> V_21 . V_22 . V_51 = V_52 ;
F_30 ( & V_227 -> V_21 . V_22 , & V_227 -> V_186 [ 0 ] . V_73 ) ;
F_31 ( & V_227 -> V_21 . V_22 , F_122 ( V_227 -> V_186 [ 0 ] . V_75 ) ) ;
} else {
V_6 = F_33 ( F_22 ( V_2 ) , & V_227 -> V_21 . V_22 ) ;
if ( V_6 )
goto V_115;
}
F_123 ( & V_227 -> V_21 . V_22 , & V_227 -> V_186 [ 0 ] . V_74 ) ;
V_2 -> V_8 = V_200 ;
return V_2 ;
V_115:
F_101 ( V_18 ) ;
return NULL ;
}
static struct V_1 * F_124 ( struct V_83 * V_149 ,
struct V_163 * V_164 )
{
struct V_1 * V_2 ;
struct V_83 * V_18 ;
int V_6 ;
V_18 = F_46 ( V_149 -> V_84 , V_149 -> V_85 ,
V_149 -> V_41 , V_114 ) ;
if ( F_62 ( V_18 ) )
return NULL ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( F_93 ( V_18 , V_149 , V_164 ) )
goto V_115;
if ( ! F_81 ( (struct V_33 * ) & V_18 -> V_20 . V_21 . V_34 ) ) {
V_6 = F_33 ( F_22 ( V_2 ) , & V_18 -> V_20 . V_21 . V_22 ) ;
if ( V_6 )
goto V_115;
}
V_2 -> V_8 = V_200 ;
return V_2 ;
V_115:
F_101 ( V_18 ) ;
return NULL ;
}
static void F_125 ( struct V_189 * V_165 ,
struct V_230 * V_231 ,
void * V_170 , int V_232 )
{
V_165 -> V_167 . V_192 . V_170 = V_170 + V_232 ;
V_165 -> V_167 . V_192 . V_193 = V_233 - V_232 ;
V_165 -> V_167 . V_192 . V_121 = V_231 -> V_121 ;
V_165 -> V_167 . V_192 . V_123 = V_231 -> V_123 ;
V_165 -> V_167 . V_192 . V_195 = V_231 -> V_195 ;
V_165 -> V_167 . V_192 . V_234 = V_231 -> V_234 ;
V_165 -> V_167 . V_192 . V_196 = V_231 -> V_196 ;
V_165 -> V_167 . V_192 . V_117 = V_231 -> V_117 ;
V_165 -> V_167 . V_192 . V_116 = V_231 -> V_197 ;
}
static int F_126 ( struct V_83 * V_18 , struct V_163 * V_164 )
{
return ( ( ( V_164 -> V_165 == V_166 ) &&
( V_164 -> V_167 . V_168 . V_88 == V_18 -> V_88 ) ) ||
( ( V_164 -> V_165 == V_235 ) &&
( V_18 -> V_88 == V_114 ) ) ||
( ! V_18 -> V_88 ) ) ;
}
static int F_127 ( struct V_198 * V_131 , struct V_163 * V_164 )
{
struct V_1 * V_149 , * V_236 ;
struct V_189 V_165 ;
int V_232 , V_6 ;
V_149 = V_131 -> V_85 ;
if ( ! F_126 ( & V_149 -> V_18 , V_164 ) )
return - V_40 ;
if ( F_45 ( V_149 , V_179 ) )
return - V_237 ;
memset ( & V_165 , 0 , sizeof V_165 ) ;
V_232 = F_94 ( V_149 ) ;
V_165 . V_165 = V_238 ;
if ( V_164 -> V_165 == V_235 ) {
V_236 = F_124 ( & V_149 -> V_18 , V_164 ) ;
V_165 . V_167 . V_239 . V_170 = V_164 -> V_170 + V_232 ;
V_165 . V_167 . V_239 . V_193 =
V_240 - V_232 ;
} else {
V_236 = F_120 ( & V_149 -> V_18 , V_164 ) ;
F_125 ( & V_165 , & V_164 -> V_167 . V_168 ,
V_164 -> V_170 , V_232 ) ;
}
if ( ! V_236 ) {
V_6 = - V_90 ;
goto V_241;
}
F_128 ( & V_236 -> V_82 , V_242 ) ;
V_6 = F_35 ( V_236 , V_149 ) ;
if ( V_6 )
goto V_243;
V_236 -> V_131 . V_32 = V_131 ;
V_131 -> V_85 = V_236 ;
V_131 -> V_244 = F_118 ;
F_9 ( & V_236 -> V_17 ) ;
V_6 = V_236 -> V_18 . V_84 ( & V_236 -> V_18 , & V_165 ) ;
if ( V_6 )
goto V_245;
F_19 ( & V_7 ) ;
if ( F_1 ( V_236 , V_200 ) && ( V_236 -> V_18 . V_88 != V_114 ) )
F_129 ( V_131 , V_246 , NULL , 0 ) ;
F_21 ( & V_7 ) ;
F_21 ( & V_236 -> V_82 ) ;
F_21 ( & V_149 -> V_82 ) ;
F_44 ( V_236 ) ;
return 0 ;
V_245:
F_44 ( V_236 ) ;
V_236 -> V_131 . V_32 = NULL ;
V_243:
F_5 ( V_236 , V_184 ) ;
F_21 ( & V_236 -> V_82 ) ;
V_241:
F_21 ( & V_149 -> V_82 ) ;
if ( V_236 )
F_101 ( & V_236 -> V_18 ) ;
return V_6 ;
}
T_6 F_130 ( struct V_83 * V_18 , struct V_33 * V_21 )
{
if ( V_21 -> V_56 == V_57 )
return ( (struct V_48 * ) V_21 ) -> V_147 ;
return F_90 ( ( ( V_247 ) V_18 -> V_41 << 16 ) + F_122 ( F_85 ( V_21 ) ) ) ;
}
static void F_131 ( enum V_86 V_41 , struct V_33 * V_21 ,
struct V_248 * V_249 )
{
struct V_11 * V_250 , * V_251 ;
T_7 V_252 ;
struct V_253 V_254 ;
memset ( V_249 , 0 , sizeof *V_249 ) ;
V_250 = ( void * ) V_249 -> V_255 ;
V_251 = ( void * ) V_249 -> V_256 ;
switch ( V_21 -> V_56 ) {
case V_136 :
V_252 = ( (struct V_137 * ) V_21 ) -> V_138 . V_139 ;
F_7 ( V_250 , 4 ) ;
F_7 ( V_251 , 0xF ) ;
if ( ! F_81 ( V_21 ) ) {
V_250 -> V_35 . V_158 . V_21 = V_252 ;
V_251 -> V_35 . V_158 . V_21 = F_132 ( ~ 0 ) ;
}
break;
case V_140 :
V_254 = ( (struct V_141 * ) V_21 ) -> V_142 ;
F_7 ( V_250 , 6 ) ;
F_7 ( V_251 , 0xF ) ;
if ( ! F_81 ( V_21 ) ) {
V_250 -> V_35 . V_161 = V_254 ;
memset ( & V_251 -> V_35 . V_161 , 0xFF ,
sizeof V_251 -> V_35 . V_161 ) ;
}
break;
default:
break;
}
}
static int F_133 ( struct V_257 * V_258 , struct V_259 * V_260 )
{
struct V_1 * V_2 = V_258 -> V_85 ;
struct V_189 V_165 ;
int V_6 = 0 ;
struct V_33 * V_261 = (struct V_33 * ) & V_260 -> V_262 ;
struct V_33 * V_263 = (struct V_33 * ) & V_260 -> V_264 ;
if ( F_45 ( V_2 , V_200 ) )
return 0 ;
memset ( & V_165 , 0 , sizeof V_165 ) ;
switch ( V_260 -> V_165 ) {
case V_265 :
V_165 . V_165 = V_217 ;
break;
case V_266 :
memcpy ( F_22 ( V_2 ) , V_261 ,
F_134 ( V_261 ) ) ;
memcpy ( F_23 ( V_2 ) , V_263 ,
F_134 ( V_263 ) ) ;
switch ( V_260 -> V_205 ) {
case 0 :
V_165 . V_165 = V_209 ;
V_165 . V_167 . V_192 . V_123 = V_260 -> V_267 ;
V_165 . V_167 . V_192 . V_121 = V_260 -> V_268 ;
break;
case - V_269 :
case - V_270 :
V_165 . V_165 = V_223 ;
break;
case - V_206 :
V_165 . V_165 = V_204 ;
break;
default:
V_165 . V_165 = V_208 ;
break;
}
break;
case V_271 :
V_165 . V_165 = V_209 ;
V_165 . V_167 . V_192 . V_123 = V_260 -> V_267 ;
V_165 . V_167 . V_192 . V_121 = V_260 -> V_268 ;
break;
default:
F_135 ( 1 ) ;
}
V_165 . V_205 = V_260 -> V_205 ;
V_165 . V_167 . V_192 . V_170 = V_260 -> V_170 ;
V_165 . V_167 . V_192 . V_193 = V_260 -> V_193 ;
V_6 = V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_165 ) ;
if ( V_6 ) {
V_2 -> V_131 . V_134 = NULL ;
F_5 ( V_2 , V_184 ) ;
F_21 ( & V_2 -> V_82 ) ;
F_101 ( & V_2 -> V_18 ) ;
return V_6 ;
}
F_21 ( & V_2 -> V_82 ) ;
return V_6 ;
}
static int F_136 ( struct V_257 * V_131 ,
struct V_259 * V_260 )
{
struct V_83 * V_272 ;
struct V_1 * V_149 , * V_236 ;
struct V_189 V_165 ;
int V_6 ;
struct V_273 V_274 ;
struct V_33 * V_261 = (struct V_33 * ) & V_260 -> V_262 ;
struct V_33 * V_263 = (struct V_33 * ) & V_260 -> V_264 ;
V_149 = V_131 -> V_85 ;
if ( F_45 ( V_149 , V_179 ) )
return - V_237 ;
V_272 = F_46 ( V_149 -> V_18 . V_84 ,
V_149 -> V_18 . V_85 ,
V_275 , V_276 ) ;
if ( F_62 ( V_272 ) ) {
V_6 = - V_90 ;
goto V_70;
}
V_236 = F_16 ( V_272 , struct V_1 , V_18 ) ;
F_128 ( & V_236 -> V_82 , V_242 ) ;
V_236 -> V_8 = V_200 ;
V_6 = F_34 ( V_261 , & V_236 -> V_18 . V_20 . V_21 . V_22 ) ;
if ( V_6 ) {
F_21 ( & V_236 -> V_82 ) ;
F_101 ( V_272 ) ;
goto V_70;
}
V_6 = F_35 ( V_236 , V_149 ) ;
if ( V_6 ) {
F_21 ( & V_236 -> V_82 ) ;
F_101 ( V_272 ) ;
goto V_70;
}
V_236 -> V_131 . V_134 = V_131 ;
V_131 -> V_85 = V_236 ;
V_131 -> V_244 = F_133 ;
memcpy ( F_22 ( V_236 ) , V_261 , F_134 ( V_261 ) ) ;
memcpy ( F_23 ( V_236 ) , V_263 , F_134 ( V_263 ) ) ;
V_6 = F_137 ( V_236 -> V_18 . V_19 , & V_274 ) ;
if ( V_6 ) {
F_21 ( & V_236 -> V_82 ) ;
F_101 ( V_272 ) ;
goto V_70;
}
memset ( & V_165 , 0 , sizeof V_165 ) ;
V_165 . V_165 = V_238 ;
V_165 . V_167 . V_192 . V_170 = V_260 -> V_170 ;
V_165 . V_167 . V_192 . V_193 = V_260 -> V_193 ;
V_165 . V_167 . V_192 . V_123 = V_260 -> V_267 ;
V_165 . V_167 . V_192 . V_121 = V_260 -> V_268 ;
F_9 ( & V_236 -> V_17 ) ;
V_6 = V_236 -> V_18 . V_84 ( & V_236 -> V_18 , & V_165 ) ;
if ( V_6 ) {
V_236 -> V_131 . V_134 = NULL ;
F_5 ( V_236 , V_184 ) ;
F_21 ( & V_236 -> V_82 ) ;
F_44 ( V_236 ) ;
F_101 ( & V_236 -> V_18 ) ;
goto V_70;
}
F_21 ( & V_236 -> V_82 ) ;
F_44 ( V_236 ) ;
V_70:
F_21 ( & V_149 -> V_82 ) ;
return V_6 ;
}
static int F_138 ( struct V_1 * V_2 )
{
struct V_248 V_277 ;
struct V_33 * V_21 ;
struct V_198 * V_18 ;
T_6 V_278 ;
int V_6 ;
V_18 = F_139 ( V_2 -> V_18 . V_19 , F_127 , V_2 ) ;
if ( F_62 ( V_18 ) )
return F_63 ( V_18 ) ;
V_2 -> V_131 . V_32 = V_18 ;
V_21 = F_22 ( V_2 ) ;
V_278 = F_130 ( & V_2 -> V_18 , V_21 ) ;
if ( F_81 ( V_21 ) && ! V_2 -> V_279 )
V_6 = F_140 ( V_2 -> V_131 . V_32 , V_278 , 0 , NULL ) ;
else {
F_131 ( V_2 -> V_18 . V_41 , V_21 , & V_277 ) ;
V_6 = F_140 ( V_2 -> V_131 . V_32 , V_278 , 0 , & V_277 ) ;
}
if ( V_6 ) {
F_111 ( V_2 -> V_131 . V_32 ) ;
V_2 -> V_131 . V_32 = NULL ;
}
return V_6 ;
}
static int F_141 ( struct V_1 * V_2 , int V_280 )
{
int V_6 ;
struct V_257 * V_18 ;
V_18 = F_142 ( V_2 -> V_18 . V_19 ,
F_136 ,
V_2 ) ;
if ( F_62 ( V_18 ) )
return F_63 ( V_18 ) ;
V_2 -> V_131 . V_134 = V_18 ;
memcpy ( & V_2 -> V_131 . V_134 -> V_262 , F_22 ( V_2 ) ,
F_134 ( F_22 ( V_2 ) ) ) ;
V_6 = F_143 ( V_2 -> V_131 . V_134 , V_280 ) ;
if ( V_6 ) {
F_112 ( V_2 -> V_131 . V_134 ) ;
V_2 -> V_131 . V_134 = NULL ;
}
return V_6 ;
}
static int F_144 ( struct V_83 * V_18 ,
struct V_189 * V_165 )
{
struct V_1 * V_2 = V_18 -> V_85 ;
V_18 -> V_85 = V_2 -> V_18 . V_85 ;
V_18 -> V_84 = V_2 -> V_18 . V_84 ;
return V_2 -> V_18 . V_84 ( V_18 , V_165 ) ;
}
static void F_145 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_1 * V_175 ;
struct V_83 * V_18 ;
int V_6 ;
if ( F_24 ( V_2 ) == V_57 &&
F_10 ( V_16 -> V_19 -> V_24 ) != V_69 )
return;
V_18 = F_46 ( F_144 , V_2 , V_2 -> V_18 . V_41 ,
V_2 -> V_18 . V_88 ) ;
if ( F_62 ( V_18 ) )
return;
V_175 = F_16 ( V_18 , struct V_1 , V_18 ) ;
V_175 -> V_8 = V_281 ;
memcpy ( F_22 ( V_175 ) , F_22 ( V_2 ) ,
F_134 ( F_22 ( V_2 ) ) ) ;
F_8 ( V_175 , V_16 ) ;
F_11 ( & V_175 -> V_95 , & V_2 -> V_95 ) ;
F_9 ( & V_2 -> V_17 ) ;
V_175 -> V_185 = 1 ;
V_175 -> V_279 = V_2 -> V_279 ;
V_6 = F_146 ( V_18 , V_2 -> V_280 ) ;
if ( V_6 )
F_119 ( V_282 L_2
L_3 , V_6 , V_16 -> V_19 -> V_283 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
F_19 ( & V_7 ) ;
F_11 ( & V_2 -> V_25 , & V_284 ) ;
F_40 (cma_dev, &dev_list, list)
F_145 ( V_2 , V_16 ) ;
F_21 ( & V_7 ) ;
}
void F_148 ( struct V_83 * V_18 , int V_285 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
V_2 -> V_285 = ( T_1 ) V_285 ;
}
static void F_149 ( int V_205 , struct V_150 * V_186 ,
void * V_85 )
{
struct V_286 * V_287 = V_85 ;
struct V_226 * V_20 ;
V_20 = & V_287 -> V_18 -> V_18 . V_20 ;
if ( ! V_205 ) {
V_20 -> V_228 = 1 ;
* V_20 -> V_186 = * V_186 ;
} else {
V_287 -> V_288 = V_178 ;
V_287 -> V_289 = V_290 ;
V_287 -> V_165 . V_165 = V_291 ;
V_287 -> V_165 . V_205 = V_205 ;
}
F_150 ( V_292 , & V_287 -> V_287 ) ;
}
static int F_151 ( struct V_1 * V_2 , int V_293 ,
struct V_286 * V_287 )
{
struct V_50 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
struct V_150 V_186 ;
T_8 V_294 ;
struct V_141 * V_295 ;
struct V_48 * V_49 ;
memset ( & V_186 , 0 , sizeof V_186 ) ;
F_152 ( V_22 , & V_186 . V_73 ) ;
F_153 ( V_22 , & V_186 . V_74 ) ;
V_186 . V_75 = F_154 ( F_70 ( V_22 ) ) ;
V_186 . V_296 = 1 ;
V_186 . V_297 = 1 ;
V_186 . V_298 = F_130 ( & V_2 -> V_18 , F_23 ( V_2 ) ) ;
V_294 = V_299 | V_300 |
V_301 | V_302 |
V_303 | V_304 ;
switch ( F_24 ( V_2 ) ) {
case V_136 :
V_186 . V_305 = F_154 ( ( T_3 ) V_2 -> V_285 ) ;
V_294 |= V_306 ;
break;
case V_140 :
V_295 = (struct V_141 * ) F_22 ( V_2 ) ;
V_186 . V_307 = ( T_1 ) ( F_28 ( V_295 -> V_308 ) >> 20 ) ;
V_294 |= V_309 ;
break;
case V_57 :
V_49 = (struct V_48 * ) F_22 ( V_2 ) ;
V_186 . V_307 = ( T_1 ) ( F_28 ( V_49 -> V_154 ) >> 20 ) ;
V_294 |= V_309 ;
break;
}
V_2 -> V_174 = F_155 ( & V_310 , V_2 -> V_18 . V_19 ,
V_2 -> V_18 . V_47 , & V_186 ,
V_294 , V_293 ,
V_89 , F_149 ,
V_287 , & V_2 -> V_173 ) ;
return ( V_2 -> V_174 < 0 ) ? V_2 -> V_174 : 0 ;
}
static void F_156 ( struct V_311 * V_312 )
{
struct V_286 * V_287 = F_16 ( V_312 , struct V_286 , V_287 ) ;
struct V_1 * V_2 = V_287 -> V_18 ;
int V_313 = 0 ;
F_19 ( & V_2 -> V_82 ) ;
if ( ! F_4 ( V_2 , V_287 -> V_288 , V_287 -> V_289 ) )
goto V_70;
if ( V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_287 -> V_165 ) ) {
F_5 ( V_2 , V_184 ) ;
V_313 = 1 ;
}
V_70:
F_21 ( & V_2 -> V_82 ) ;
F_44 ( V_2 ) ;
if ( V_313 )
F_101 ( & V_2 -> V_18 ) ;
F_17 ( V_287 ) ;
}
static void F_157 ( struct V_311 * V_312 )
{
struct V_314 * V_287 = F_16 ( V_312 , struct V_314 , V_287 ) ;
struct V_1 * V_2 = V_287 -> V_18 ;
int V_313 = 0 ;
F_19 ( & V_2 -> V_82 ) ;
if ( V_2 -> V_8 == V_184 ||
V_2 -> V_8 == V_315 )
goto V_70;
if ( V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_287 -> V_165 ) ) {
F_5 ( V_2 , V_184 ) ;
V_313 = 1 ;
}
V_70:
F_21 ( & V_2 -> V_82 ) ;
F_44 ( V_2 ) ;
if ( V_313 )
F_101 ( & V_2 -> V_18 ) ;
F_17 ( V_287 ) ;
}
static int F_158 ( struct V_1 * V_2 , int V_293 )
{
struct V_226 * V_20 = & V_2 -> V_18 . V_20 ;
struct V_286 * V_287 ;
int V_6 ;
V_287 = F_47 ( sizeof *V_287 , V_89 ) ;
if ( ! V_287 )
return - V_90 ;
V_287 -> V_18 = V_2 ;
F_159 ( & V_287 -> V_287 , F_156 ) ;
V_287 -> V_288 = V_178 ;
V_287 -> V_289 = V_316 ;
V_287 -> V_165 . V_165 = V_317 ;
V_20 -> V_186 = F_121 ( sizeof * V_20 -> V_186 , V_89 ) ;
if ( ! V_20 -> V_186 ) {
V_6 = - V_90 ;
goto V_241;
}
V_6 = F_151 ( V_2 , V_293 , V_287 ) ;
if ( V_6 )
goto V_243;
return 0 ;
V_243:
F_17 ( V_20 -> V_186 ) ;
V_20 -> V_186 = NULL ;
V_241:
F_17 ( V_287 ) ;
return V_6 ;
}
int F_160 ( struct V_83 * V_18 ,
struct V_150 * V_186 , int V_228 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_4 ( V_2 , V_290 ,
V_316 ) )
return - V_40 ;
V_18 -> V_20 . V_186 = F_161 ( V_186 , sizeof *V_186 * V_228 ,
V_89 ) ;
if ( ! V_18 -> V_20 . V_186 ) {
V_6 = - V_90 ;
goto V_115;
}
V_18 -> V_20 . V_228 = V_228 ;
return 0 ;
V_115:
F_4 ( V_2 , V_316 , V_290 ) ;
return V_6 ;
}
static int F_162 ( struct V_1 * V_2 , int V_293 )
{
struct V_286 * V_287 ;
V_287 = F_47 ( sizeof *V_287 , V_89 ) ;
if ( ! V_287 )
return - V_90 ;
V_287 -> V_18 = V_2 ;
F_159 ( & V_287 -> V_287 , F_156 ) ;
V_287 -> V_288 = V_178 ;
V_287 -> V_289 = V_316 ;
V_287 -> V_165 . V_165 = V_317 ;
F_150 ( V_292 , & V_287 -> V_287 ) ;
return 0 ;
}
static int F_163 ( struct V_318 * V_319 , int V_285 )
{
int V_320 ;
struct V_318 * V_321 ;
V_320 = F_164 ( V_285 ) ;
V_321 = V_319 -> V_322 & V_323 ?
F_165 ( V_319 ) : V_319 ;
if ( V_321 -> V_324 )
return F_166 ( V_321 , V_320 ) ;
#if F_167 ( V_325 )
if ( V_319 -> V_322 & V_323 )
return ( F_168 ( V_319 , V_320 ) &
V_326 ) >> V_327 ;
#endif
return 0 ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_226 * V_20 = & V_2 -> V_18 . V_20 ;
struct V_328 * V_21 = & V_20 -> V_21 ;
struct V_286 * V_287 ;
int V_6 ;
struct V_318 * V_319 = NULL ;
T_3 V_329 ;
V_287 = F_47 ( sizeof *V_287 , V_89 ) ;
if ( ! V_287 )
return - V_90 ;
V_287 -> V_18 = V_2 ;
F_159 ( & V_287 -> V_287 , F_156 ) ;
V_20 -> V_186 = F_47 ( sizeof * V_20 -> V_186 , V_89 ) ;
if ( ! V_20 -> V_186 ) {
V_6 = - V_90 ;
goto V_241;
}
V_20 -> V_228 = 1 ;
if ( V_21 -> V_22 . V_330 )
V_319 = F_170 ( & V_331 , V_21 -> V_22 . V_330 ) ;
if ( ! V_319 ) {
V_6 = - V_61 ;
goto V_243;
}
V_329 = F_171 ( V_319 ) ;
F_172 ( & V_20 -> V_186 -> V_73 , V_21 -> V_22 . V_68 , V_329 ) ;
F_172 ( & V_20 -> V_186 -> V_74 , V_21 -> V_22 . V_332 , V_329 ) ;
V_20 -> V_186 -> V_333 = 1 ;
V_20 -> V_186 -> V_297 = 1 ;
V_20 -> V_186 -> V_75 = F_154 ( 0xffff ) ;
V_20 -> V_186 -> V_334 = V_335 ;
V_20 -> V_186 -> V_336 = F_163 ( V_319 , V_2 -> V_285 ) ;
V_20 -> V_186 -> V_337 = F_173 ( V_319 -> V_337 ) ;
V_20 -> V_186 -> V_338 = V_335 ;
V_20 -> V_186 -> V_339 = F_174 ( V_319 ) ;
F_175 ( V_319 ) ;
V_20 -> V_186 -> V_340 = V_335 ;
V_20 -> V_186 -> V_341 = V_342 ;
if ( ! V_20 -> V_186 -> V_337 ) {
V_6 = - V_40 ;
goto V_243;
}
V_287 -> V_288 = V_178 ;
V_287 -> V_289 = V_316 ;
V_287 -> V_165 . V_165 = V_317 ;
V_287 -> V_165 . V_205 = 0 ;
F_150 ( V_292 , & V_287 -> V_287 ) ;
return 0 ;
V_243:
F_17 ( V_20 -> V_186 ) ;
V_20 -> V_186 = NULL ;
V_241:
F_17 ( V_287 ) ;
return V_6 ;
}
int F_176 ( struct V_83 * V_18 , int V_293 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_4 ( V_2 , V_290 , V_178 ) )
return - V_40 ;
F_9 ( & V_2 -> V_17 ) ;
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
switch ( F_38 ( V_18 -> V_19 , V_18 -> V_47 ) ) {
case V_66 :
V_6 = F_158 ( V_2 , V_293 ) ;
break;
case V_67 :
V_6 = F_169 ( V_2 ) ;
break;
default:
V_6 = - V_135 ;
}
break;
case V_133 :
V_6 = F_162 ( V_2 , V_293 ) ;
break;
default:
V_6 = - V_135 ;
break;
}
if ( V_6 )
goto V_115;
return 0 ;
V_115:
F_4 ( V_2 , V_178 , V_290 ) ;
F_44 ( V_2 ) ;
return V_6 ;
}
static void F_177 ( struct V_33 * V_21 )
{
switch ( V_21 -> V_56 ) {
case V_136 :
( (struct V_137 * ) V_21 ) -> V_138 . V_139 = F_132 ( V_343 ) ;
break;
case V_140 :
F_178 ( & ( (struct V_141 * ) V_21 ) -> V_142 ,
0 , 0 , 0 , F_132 ( 1 ) ) ;
break;
default:
F_179 ( & ( (struct V_48 * ) V_21 ) -> V_54 ,
0 , 0 , 0 , F_132 ( 1 ) ) ;
break;
}
}
static int F_180 ( struct V_1 * V_2 )
{
struct V_15 * V_16 , * V_72 ;
struct V_344 V_345 ;
union V_53 V_59 ;
T_3 V_75 ;
int V_6 ;
T_1 V_77 ;
V_16 = NULL ;
F_19 ( & V_7 ) ;
F_40 (cur_dev, &dev_list, list) {
if ( F_24 ( V_2 ) == V_57 &&
F_10 ( V_72 -> V_19 -> V_24 ) != V_69 )
continue;
if ( ! V_16 )
V_16 = V_72 ;
for ( V_77 = 1 ; V_77 <= V_72 -> V_19 -> V_71 ; ++ V_77 ) {
if ( ! F_181 ( V_72 -> V_19 , V_77 , & V_345 ) &&
V_345 . V_8 == V_346 ) {
V_16 = V_72 ;
goto V_347;
}
}
}
if ( ! V_16 ) {
V_6 = - V_61 ;
goto V_70;
}
V_77 = 1 ;
V_347:
V_6 = F_43 ( V_16 -> V_19 , V_77 , 0 , & V_59 ) ;
if ( V_6 )
goto V_70;
V_6 = F_182 ( V_16 -> V_19 , V_77 , 0 , & V_75 ) ;
if ( V_6 )
goto V_70;
V_2 -> V_18 . V_20 . V_21 . V_22 . V_51 =
( F_38 ( V_16 -> V_19 , V_77 ) == V_66 ) ?
V_52 : V_348 ;
F_30 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , & V_59 ) ;
F_31 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , V_75 ) ;
V_2 -> V_18 . V_47 = V_77 ;
F_8 ( V_2 , V_16 ) ;
F_177 ( F_22 ( V_2 ) ) ;
V_70:
F_21 ( & V_7 ) ;
return V_6 ;
}
static void F_183 ( int V_205 , struct V_33 * V_34 ,
struct V_50 * V_22 , void * V_85 )
{
struct V_1 * V_2 = V_85 ;
struct V_189 V_165 ;
memset ( & V_165 , 0 , sizeof V_165 ) ;
F_19 ( & V_2 -> V_82 ) ;
if ( ! F_4 ( V_2 , V_177 ,
V_290 ) )
goto V_70;
if ( ! V_205 && ! V_2 -> V_16 )
V_205 = F_35 ( V_2 , NULL ) ;
if ( V_205 ) {
if ( ! F_4 ( V_2 , V_290 ,
V_281 ) )
goto V_70;
V_165 . V_165 = V_349 ;
V_165 . V_205 = V_205 ;
} else {
memcpy ( F_22 ( V_2 ) , V_34 , F_134 ( V_34 ) ) ;
V_165 . V_165 = V_350 ;
}
if ( V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_165 ) ) {
F_5 ( V_2 , V_184 ) ;
F_21 ( & V_2 -> V_82 ) ;
F_44 ( V_2 ) ;
F_101 ( & V_2 -> V_18 ) ;
return;
}
V_70:
F_21 ( & V_2 -> V_82 ) ;
F_44 ( V_2 ) ;
}
static int F_184 ( struct V_1 * V_2 )
{
struct V_286 * V_287 ;
union V_53 V_59 ;
int V_6 ;
V_287 = F_47 ( sizeof *V_287 , V_89 ) ;
if ( ! V_287 )
return - V_90 ;
if ( ! V_2 -> V_16 ) {
V_6 = F_180 ( V_2 ) ;
if ( V_6 )
goto V_115;
}
F_152 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , & V_59 ) ;
F_123 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , & V_59 ) ;
V_287 -> V_18 = V_2 ;
F_159 ( & V_287 -> V_287 , F_156 ) ;
V_287 -> V_288 = V_177 ;
V_287 -> V_289 = V_290 ;
V_287 -> V_165 . V_165 = V_350 ;
F_150 ( V_292 , & V_287 -> V_287 ) ;
return 0 ;
V_115:
F_17 ( V_287 ) ;
return V_6 ;
}
static int F_185 ( struct V_1 * V_2 )
{
struct V_286 * V_287 ;
int V_6 ;
V_287 = F_47 ( sizeof *V_287 , V_89 ) ;
if ( ! V_287 )
return - V_90 ;
if ( ! V_2 -> V_16 ) {
V_6 = F_41 ( V_2 ) ;
if ( V_6 )
goto V_115;
}
F_123 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , (union V_53 * )
& ( ( (struct V_48 * ) & V_2 -> V_18 . V_20 . V_21 . V_35 ) -> V_54 ) ) ;
V_287 -> V_18 = V_2 ;
F_159 ( & V_287 -> V_287 , F_156 ) ;
V_287 -> V_288 = V_177 ;
V_287 -> V_289 = V_290 ;
V_287 -> V_165 . V_165 = V_350 ;
F_150 ( V_292 , & V_287 -> V_287 ) ;
return 0 ;
V_115:
F_17 ( V_287 ) ;
return V_6 ;
}
static int F_186 ( struct V_83 * V_18 , struct V_33 * V_34 ,
struct V_33 * V_35 )
{
if ( ! V_34 || ! V_34 -> V_56 ) {
V_34 = (struct V_33 * ) & V_18 -> V_20 . V_21 . V_34 ;
V_34 -> V_56 = V_35 -> V_56 ;
if ( V_35 -> V_56 == V_140 ) {
( (struct V_141 * ) V_34 ) -> V_351 =
( (struct V_141 * ) V_35 ) -> V_351 ;
} else if ( V_35 -> V_56 == V_57 ) {
( (struct V_48 * ) V_34 ) -> V_55 =
( (struct V_48 * ) V_35 ) -> V_55 ;
}
}
return F_187 ( V_18 , V_34 ) ;
}
int F_188 ( struct V_83 * V_18 , struct V_33 * V_34 ,
struct V_33 * V_35 , int V_293 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( V_2 -> V_8 == V_93 ) {
V_6 = F_186 ( V_18 , V_34 , V_35 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_24 ( V_2 ) != V_35 -> V_56 )
return - V_40 ;
if ( ! F_4 ( V_2 , V_281 , V_177 ) )
return - V_40 ;
F_9 ( & V_2 -> V_17 ) ;
memcpy ( F_23 ( V_2 ) , V_35 , F_134 ( V_35 ) ) ;
if ( F_81 ( V_35 ) ) {
V_6 = F_184 ( V_2 ) ;
} else {
if ( V_35 -> V_56 == V_57 ) {
V_6 = F_185 ( V_2 ) ;
} else {
V_6 = F_189 ( & V_352 , F_22 ( V_2 ) ,
V_35 , & V_18 -> V_20 . V_21 . V_22 ,
V_293 , F_183 , V_2 ) ;
}
}
if ( V_6 )
goto V_115;
return 0 ;
V_115:
F_4 ( V_2 , V_177 , V_281 ) ;
F_44 ( V_2 ) ;
return V_6 ;
}
int F_190 ( struct V_83 * V_18 , int V_353 )
{
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
if ( V_353 || V_2 -> V_8 == V_93 ) {
V_2 -> V_354 = V_353 ;
V_6 = 0 ;
} else {
V_6 = - V_40 ;
}
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
int F_191 ( struct V_83 * V_18 , int V_279 )
{
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
if ( V_2 -> V_8 == V_93 || V_2 -> V_8 == V_281 ) {
V_2 -> V_355 |= ( 1 << V_356 ) ;
V_2 -> V_279 = V_279 ;
V_6 = 0 ;
} else {
V_6 = - V_40 ;
}
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
static void F_192 ( struct V_180 * V_181 ,
struct V_1 * V_2 )
{
struct V_33 * V_21 ;
struct V_48 * V_49 ;
V_247 V_357 , V_256 ;
T_5 V_62 ;
V_21 = F_22 ( V_2 ) ;
V_62 = F_86 ( V_181 -> V_62 ) ;
switch ( V_21 -> V_56 ) {
case V_136 :
( (struct V_137 * ) V_21 ) -> V_145 = V_62 ;
break;
case V_140 :
( (struct V_141 * ) V_21 ) -> V_146 = V_62 ;
break;
case V_57 :
V_49 = (struct V_48 * ) V_21 ;
V_357 = F_87 ( V_49 -> V_147 ) ;
V_256 = F_87 ( V_49 -> V_148 ) ;
V_49 -> V_147 = F_90 ( ( V_357 & V_256 ) | ( V_247 ) F_32 ( V_62 ) ) ;
V_49 -> V_148 = F_90 ( ~ 0ULL ) ;
break;
}
V_2 -> V_181 = V_181 ;
F_193 ( & V_2 -> V_182 , & V_181 -> V_183 ) ;
}
static int F_194 ( struct V_358 * V_41 , struct V_1 * V_2 ,
unsigned short V_359 )
{
struct V_180 * V_181 ;
int V_6 ;
V_181 = F_47 ( sizeof *V_181 , V_89 ) ;
if ( ! V_181 )
return - V_90 ;
V_6 = F_195 ( V_41 , V_181 , V_359 , V_359 + 1 , V_89 ) ;
if ( V_6 < 0 )
goto V_115;
V_181 -> V_41 = V_41 ;
V_181 -> V_62 = ( unsigned short ) V_6 ;
F_192 ( V_181 , V_2 ) ;
return 0 ;
V_115:
F_17 ( V_181 ) ;
return V_6 == - V_360 ? - V_361 : V_6 ;
}
static int F_196 ( struct V_358 * V_41 , struct V_1 * V_2 )
{
static unsigned int V_362 ;
int V_363 , V_364 , V_365 ;
unsigned int V_366 ;
F_197 ( & V_331 , & V_363 , & V_364 ) ;
V_365 = ( V_364 - V_363 ) + 1 ;
V_366 = F_198 () % V_365 + V_363 ;
V_367:
if ( V_362 != V_366 &&
! F_199 ( V_41 , ( unsigned short ) V_366 ) ) {
int V_6 = F_194 ( V_41 , V_2 , V_366 ) ;
if ( ! V_6 )
V_362 = V_366 ;
if ( V_6 != - V_361 )
return V_6 ;
}
if ( -- V_365 ) {
V_366 ++ ;
if ( ( V_366 < V_363 ) || ( V_366 > V_364 ) )
V_366 = V_363 ;
goto V_367;
}
return - V_361 ;
}
static int F_200 ( struct V_180 * V_181 ,
struct V_1 * V_2 , T_9 V_354 )
{
struct V_1 * V_368 ;
struct V_33 * V_21 , * V_369 ;
V_21 = F_22 ( V_2 ) ;
F_201 (cur_id, &bind_list->owners, node) {
if ( V_2 == V_368 )
continue;
if ( ( V_368 -> V_8 != V_179 ) && V_354 &&
V_368 -> V_354 )
continue;
V_369 = F_22 ( V_368 ) ;
if ( V_2 -> V_279 && V_368 -> V_279 &&
( V_21 -> V_56 != V_369 -> V_56 ) )
continue;
if ( F_81 ( V_21 ) || F_81 ( V_369 ) )
return - V_361 ;
if ( ! F_82 ( V_21 , V_369 ) )
return - V_370 ;
}
return 0 ;
}
static int F_202 ( struct V_358 * V_41 , struct V_1 * V_2 )
{
struct V_180 * V_181 ;
unsigned short V_359 ;
int V_6 ;
V_359 = F_32 ( F_85 ( F_22 ( V_2 ) ) ) ;
if ( V_359 < V_371 && ! F_203 ( V_372 ) )
return - V_373 ;
V_181 = F_199 ( V_41 , V_359 ) ;
if ( ! V_181 ) {
V_6 = F_194 ( V_41 , V_2 , V_359 ) ;
} else {
V_6 = F_200 ( V_181 , V_2 , V_2 -> V_354 ) ;
if ( ! V_6 )
F_192 ( V_181 , V_2 ) ;
}
return V_6 ;
}
static int F_204 ( struct V_1 * V_2 )
{
struct V_180 * V_181 = V_2 -> V_181 ;
int V_6 = 0 ;
F_19 ( & V_7 ) ;
if ( V_181 -> V_183 . V_374 -> V_176 )
V_6 = F_200 ( V_181 , V_2 , 0 ) ;
F_21 ( & V_7 ) ;
return V_6 ;
}
static struct V_358 * F_205 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_18 . V_41 ) {
case V_275 :
return & V_375 ;
case V_42 :
return & V_376 ;
case V_45 :
return & V_377 ;
case V_43 :
return & V_378 ;
default:
return NULL ;
}
}
static struct V_358 * F_206 ( struct V_1 * V_2 )
{
struct V_358 * V_41 = NULL ;
struct V_48 * V_49 ;
V_247 V_379 , V_256 , V_357 ;
V_49 = (struct V_48 * ) F_22 ( V_2 ) ;
V_256 = F_87 ( V_49 -> V_148 ) & V_380 ;
V_357 = F_87 ( V_49 -> V_147 ) & V_256 ;
if ( ( V_2 -> V_18 . V_41 == V_43 ) && ( V_357 == ( V_381 & V_256 ) ) ) {
V_379 = V_381 ;
V_41 = & V_378 ;
} else if ( ( ( V_2 -> V_18 . V_41 == V_43 ) || ( V_2 -> V_18 . V_41 == V_275 ) ) &&
( V_357 == ( V_382 & V_256 ) ) ) {
V_379 = V_382 ;
V_41 = & V_375 ;
} else if ( ( ( V_2 -> V_18 . V_41 == V_43 ) || ( V_2 -> V_18 . V_41 == V_42 ) ) &&
( V_357 == ( V_383 & V_256 ) ) ) {
V_379 = V_383 ;
V_41 = & V_376 ;
}
if ( V_41 ) {
V_49 -> V_147 = F_90 ( V_379 | F_32 ( F_85 ( (struct V_33 * ) V_49 ) ) ) ;
V_49 -> V_148 = F_90 ( V_380 |
F_87 ( V_49 -> V_148 ) ) ;
}
return V_41 ;
}
static int F_207 ( struct V_1 * V_2 )
{
struct V_358 * V_41 ;
int V_6 ;
if ( F_24 ( V_2 ) != V_57 )
V_41 = F_205 ( V_2 ) ;
else
V_41 = F_206 ( V_2 ) ;
if ( ! V_41 )
return - V_384 ;
F_19 ( & V_7 ) ;
if ( F_88 ( F_22 ( V_2 ) ) )
V_6 = F_196 ( V_41 , V_2 ) ;
else
V_6 = F_202 ( V_41 , V_2 ) ;
F_21 ( & V_7 ) ;
return V_6 ;
}
static int F_208 ( struct V_50 * V_22 ,
struct V_33 * V_21 )
{
#if F_167 ( V_385 )
struct V_141 * V_295 ;
if ( V_21 -> V_56 != V_140 )
return 0 ;
V_295 = (struct V_141 * ) V_21 ;
if ( ( F_209 ( & V_295 -> V_142 ) & V_386 ) &&
! V_295 -> V_351 )
return - V_40 ;
V_22 -> V_330 = V_295 -> V_351 ;
#endif
return 0 ;
}
int F_146 ( struct V_83 * V_18 , int V_280 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( V_2 -> V_8 == V_93 ) {
V_18 -> V_20 . V_21 . V_34 . V_36 = V_136 ;
V_6 = F_187 ( V_18 , F_22 ( V_2 ) ) ;
if ( V_6 )
return V_6 ;
}
if ( ! F_4 ( V_2 , V_281 , V_179 ) )
return - V_40 ;
if ( V_2 -> V_354 ) {
V_6 = F_204 ( V_2 ) ;
if ( V_6 )
goto V_115;
}
V_2 -> V_280 = V_280 ;
if ( V_18 -> V_19 ) {
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
V_6 = F_138 ( V_2 ) ;
if ( V_6 )
goto V_115;
break;
case V_133 :
V_6 = F_141 ( V_2 , V_280 ) ;
if ( V_6 )
goto V_115;
break;
default:
V_6 = - V_135 ;
goto V_115;
}
} else
F_147 ( V_2 ) ;
return 0 ;
V_115:
V_2 -> V_280 = 0 ;
F_4 ( V_2 , V_179 , V_281 ) ;
return V_6 ;
}
int F_187 ( struct V_83 * V_18 , struct V_33 * V_21 )
{
struct V_1 * V_2 ;
int V_6 ;
if ( V_21 -> V_56 != V_136 && V_21 -> V_56 != V_140 &&
V_21 -> V_56 != V_57 )
return - V_387 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_4 ( V_2 , V_93 , V_281 ) )
return - V_40 ;
V_6 = F_208 ( & V_18 -> V_20 . V_21 . V_22 , V_21 ) ;
if ( V_6 )
goto V_241;
if ( ! F_81 ( V_21 ) ) {
V_6 = F_33 ( V_21 , & V_18 -> V_20 . V_21 . V_22 ) ;
if ( V_6 )
goto V_241;
V_6 = F_35 ( V_2 , NULL ) ;
if ( V_6 )
goto V_241;
}
memcpy ( F_22 ( V_2 ) , V_21 , F_134 ( V_21 ) ) ;
if ( ! ( V_2 -> V_355 & ( 1 << V_356 ) ) ) {
if ( V_21 -> V_56 == V_136 )
V_2 -> V_279 = 1 ;
#if F_167 ( V_385 )
else if ( V_21 -> V_56 == V_140 )
V_2 -> V_279 = V_331 . V_388 . V_389 . V_390 ;
#endif
}
V_6 = F_207 ( V_2 ) ;
if ( V_6 )
goto V_243;
return 0 ;
V_243:
if ( V_2 -> V_16 )
F_18 ( V_2 ) ;
V_241:
F_4 ( V_2 , V_281 , V_93 ) ;
return V_6 ;
}
static int F_210 ( void * V_12 , struct V_1 * V_2 )
{
struct V_11 * V_11 ;
V_11 = V_12 ;
V_11 -> V_171 = V_172 ;
if ( F_24 ( V_2 ) == V_136 ) {
struct V_137 * V_391 , * V_392 ;
V_391 = (struct V_137 * ) F_22 ( V_2 ) ;
V_392 = (struct V_137 * ) F_23 ( V_2 ) ;
F_7 ( V_11 , 4 ) ;
V_11 -> V_34 . V_158 . V_21 = V_391 -> V_138 . V_139 ;
V_11 -> V_35 . V_158 . V_21 = V_392 -> V_138 . V_139 ;
V_11 -> V_62 = V_391 -> V_145 ;
} else if ( F_24 ( V_2 ) == V_140 ) {
struct V_141 * V_393 , * V_394 ;
V_393 = (struct V_141 * ) F_22 ( V_2 ) ;
V_394 = (struct V_141 * ) F_23 ( V_2 ) ;
F_7 ( V_11 , 6 ) ;
V_11 -> V_34 . V_161 = V_393 -> V_142 ;
V_11 -> V_35 . V_161 = V_394 -> V_142 ;
V_11 -> V_62 = V_393 -> V_146 ;
}
return 0 ;
}
static int F_211 ( struct V_198 * V_131 ,
struct V_163 * V_164 )
{
struct V_1 * V_2 = V_131 -> V_85 ;
struct V_189 V_165 ;
struct V_395 * V_396 = & V_164 -> V_167 . V_397 ;
int V_6 = 0 ;
if ( F_45 ( V_2 , V_200 ) )
return 0 ;
memset ( & V_165 , 0 , sizeof V_165 ) ;
switch ( V_164 -> V_165 ) {
case V_398 :
V_165 . V_165 = V_204 ;
V_165 . V_205 = - V_206 ;
break;
case V_399 :
V_165 . V_167 . V_239 . V_170 = V_164 -> V_170 ;
V_165 . V_167 . V_239 . V_193 = V_400 ;
if ( V_396 -> V_205 != V_401 ) {
V_165 . V_165 = V_204 ;
V_165 . V_205 = V_164 -> V_167 . V_397 . V_205 ;
break;
}
V_6 = F_25 ( V_2 , V_396 -> V_37 ) ;
if ( V_6 ) {
V_165 . V_165 = V_349 ;
V_165 . V_205 = V_6 ;
break;
}
F_212 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ,
V_2 -> V_18 . V_20 . V_186 ,
& V_165 . V_167 . V_239 . V_402 ) ;
V_165 . V_167 . V_239 . V_116 = V_396 -> V_403 ;
V_165 . V_167 . V_239 . V_37 = V_396 -> V_37 ;
V_165 . V_165 = V_209 ;
V_165 . V_205 = 0 ;
break;
default:
F_119 ( V_225 L_1 ,
V_164 -> V_165 ) ;
goto V_70;
}
V_6 = V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_165 ) ;
if ( V_6 ) {
V_2 -> V_131 . V_32 = NULL ;
F_5 ( V_2 , V_184 ) ;
F_21 ( & V_2 -> V_82 ) ;
F_101 ( & V_2 -> V_18 ) ;
return V_6 ;
}
V_70:
F_21 ( & V_2 -> V_82 ) ;
return V_6 ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_404 V_405 ;
struct V_198 * V_18 ;
void * V_170 ;
int V_232 , V_6 ;
memset ( & V_405 , 0 , sizeof V_405 ) ;
V_232 = F_94 ( V_2 ) ;
V_405 . V_193 = V_232 + V_119 -> V_193 ;
if ( V_405 . V_193 < V_119 -> V_193 )
return - V_40 ;
if ( V_405 . V_193 ) {
V_170 = F_47 ( V_405 . V_193 , V_406 ) ;
if ( ! V_170 )
return - V_90 ;
} else {
V_170 = NULL ;
}
if ( V_119 -> V_170 && V_119 -> V_193 )
memcpy ( V_170 + V_232 , V_119 -> V_170 ,
V_119 -> V_193 ) ;
if ( V_170 ) {
V_6 = F_210 ( V_170 , V_2 ) ;
if ( V_6 )
goto V_70;
V_405 . V_170 = V_170 ;
}
V_18 = F_139 ( V_2 -> V_18 . V_19 , F_211 ,
V_2 ) ;
if ( F_62 ( V_18 ) ) {
V_6 = F_63 ( V_18 ) ;
goto V_70;
}
V_2 -> V_131 . V_32 = V_18 ;
V_405 . V_151 = V_2 -> V_18 . V_20 . V_186 ;
V_405 . V_298 = F_130 ( & V_2 -> V_18 , F_23 ( V_2 ) ) ;
V_405 . V_293 = 1 << ( V_407 - 8 ) ;
V_405 . V_408 = V_409 ;
V_6 = F_214 ( V_2 -> V_131 . V_32 , & V_405 ) ;
if ( V_6 ) {
F_111 ( V_2 -> V_131 . V_32 ) ;
V_2 -> V_131 . V_32 = NULL ;
}
V_70:
F_17 ( V_170 ) ;
return V_6 ;
}
static int F_215 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_410 V_405 ;
struct V_226 * V_20 ;
void * V_170 ;
struct V_198 * V_18 ;
int V_232 , V_6 ;
memset ( & V_405 , 0 , sizeof V_405 ) ;
V_232 = F_94 ( V_2 ) ;
V_405 . V_193 = V_232 + V_119 -> V_193 ;
if ( V_405 . V_193 < V_119 -> V_193 )
return - V_40 ;
if ( V_405 . V_193 ) {
V_170 = F_47 ( V_405 . V_193 , V_406 ) ;
if ( ! V_170 )
return - V_90 ;
} else {
V_170 = NULL ;
}
if ( V_119 -> V_170 && V_119 -> V_193 )
memcpy ( V_170 + V_232 , V_119 -> V_170 ,
V_119 -> V_193 ) ;
V_18 = F_139 ( V_2 -> V_18 . V_19 , F_118 , V_2 ) ;
if ( F_62 ( V_18 ) ) {
V_6 = F_63 ( V_18 ) ;
goto V_70;
}
V_2 -> V_131 . V_32 = V_18 ;
V_20 = & V_2 -> V_18 . V_20 ;
if ( V_170 ) {
V_6 = F_210 ( V_170 , V_2 ) ;
if ( V_6 )
goto V_70;
V_405 . V_170 = V_170 ;
}
V_405 . V_169 = & V_20 -> V_186 [ 0 ] ;
if ( V_20 -> V_228 == 2 )
V_405 . V_229 = & V_20 -> V_186 [ 1 ] ;
V_405 . V_298 = F_130 ( & V_2 -> V_18 , F_23 ( V_2 ) ) ;
V_405 . V_116 = V_2 -> V_116 ;
V_405 . V_88 = V_2 -> V_18 . V_88 ;
V_405 . V_411 = V_2 -> V_97 ;
V_405 . V_121 = V_119 -> V_121 ;
V_405 . V_123 = V_119 -> V_123 ;
V_405 . V_195 = V_119 -> V_195 ;
V_405 . V_234 = F_216 ( T_1 , 7 , V_119 -> V_234 ) ;
V_405 . V_196 = F_216 ( T_1 , 7 , V_119 -> V_196 ) ;
V_405 . V_412 = V_407 ;
V_405 . V_413 = V_407 ;
V_405 . V_408 = V_409 ;
V_405 . V_117 = V_2 -> V_117 ? 1 : 0 ;
V_6 = F_217 ( V_2 -> V_131 . V_32 , & V_405 ) ;
V_70:
if ( V_6 && ! F_62 ( V_18 ) ) {
F_111 ( V_18 ) ;
V_2 -> V_131 . V_32 = NULL ;
}
F_17 ( V_170 ) ;
return V_6 ;
}
static int F_218 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_257 * V_131 ;
int V_6 ;
struct V_414 V_415 ;
V_131 = F_142 ( V_2 -> V_18 . V_19 , F_133 , V_2 ) ;
if ( F_62 ( V_131 ) )
return F_63 ( V_131 ) ;
V_2 -> V_131 . V_134 = V_131 ;
memcpy ( & V_131 -> V_262 , F_22 ( V_2 ) ,
F_134 ( F_22 ( V_2 ) ) ) ;
memcpy ( & V_131 -> V_264 , F_23 ( V_2 ) ,
F_134 ( F_23 ( V_2 ) ) ) ;
V_6 = F_66 ( V_2 , V_119 ) ;
if ( V_6 )
goto V_70;
if ( V_119 ) {
V_415 . V_268 = V_119 -> V_123 ;
V_415 . V_267 = V_119 -> V_121 ;
V_415 . V_170 = V_119 -> V_170 ;
V_415 . V_193 = V_119 -> V_193 ;
V_415 . V_403 = V_2 -> V_18 . V_99 ? V_2 -> V_116 : V_119 -> V_116 ;
} else {
memset ( & V_415 , 0 , sizeof V_415 ) ;
V_415 . V_403 = V_2 -> V_116 ;
}
V_6 = F_219 ( V_131 , & V_415 ) ;
V_70:
if ( V_6 ) {
F_112 ( V_131 ) ;
V_2 -> V_131 . V_134 = NULL ;
}
return V_6 ;
}
int F_220 ( struct V_83 * V_18 , struct V_118 * V_119 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_4 ( V_2 , V_316 , V_200 ) )
return - V_40 ;
if ( ! V_18 -> V_99 ) {
V_2 -> V_116 = V_119 -> V_116 ;
V_2 -> V_117 = V_119 -> V_117 ;
}
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
if ( V_18 -> V_88 == V_114 )
V_6 = F_213 ( V_2 , V_119 ) ;
else
V_6 = F_215 ( V_2 , V_119 ) ;
break;
case V_133 :
V_6 = F_218 ( V_2 , V_119 ) ;
break;
default:
V_6 = - V_135 ;
break;
}
if ( V_6 )
goto V_115;
return 0 ;
V_115:
F_4 ( V_2 , V_200 , V_316 ) ;
return V_6 ;
}
static int F_221 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_416 V_396 ;
int V_6 ;
V_6 = F_66 ( V_2 , V_119 ) ;
if ( V_6 )
goto V_70;
V_6 = F_67 ( V_2 , V_119 ) ;
if ( V_6 )
goto V_70;
memset ( & V_396 , 0 , sizeof V_396 ) ;
V_396 . V_116 = V_2 -> V_116 ;
V_396 . V_411 = V_2 -> V_97 ;
V_396 . V_170 = V_119 -> V_170 ;
V_396 . V_193 = V_119 -> V_193 ;
V_396 . V_121 = V_119 -> V_121 ;
V_396 . V_123 = V_119 -> V_123 ;
V_396 . V_417 = 0 ;
V_396 . V_195 = V_119 -> V_195 ;
V_396 . V_196 = F_216 ( T_1 , 7 , V_119 -> V_196 ) ;
V_396 . V_117 = V_2 -> V_117 ? 1 : 0 ;
V_6 = F_222 ( V_2 -> V_131 . V_32 , & V_396 ) ;
V_70:
return V_6 ;
}
static int F_223 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_414 V_415 ;
int V_6 ;
V_6 = F_66 ( V_2 , V_119 ) ;
if ( V_6 )
return V_6 ;
V_415 . V_268 = V_119 -> V_123 ;
V_415 . V_267 = V_119 -> V_121 ;
V_415 . V_170 = V_119 -> V_170 ;
V_415 . V_193 = V_119 -> V_193 ;
if ( V_2 -> V_18 . V_99 ) {
V_415 . V_403 = V_2 -> V_116 ;
} else
V_415 . V_403 = V_119 -> V_116 ;
return F_224 ( V_2 -> V_131 . V_134 , & V_415 ) ;
}
static int F_225 ( struct V_1 * V_2 ,
enum V_418 V_205 , T_2 V_37 ,
const void * V_170 , int V_193 )
{
struct V_419 V_396 ;
int V_6 ;
memset ( & V_396 , 0 , sizeof V_396 ) ;
V_396 . V_205 = V_205 ;
if ( V_205 == V_401 ) {
V_6 = F_25 ( V_2 , V_37 ) ;
if ( V_6 )
return V_6 ;
V_396 . V_116 = V_2 -> V_116 ;
V_396 . V_37 = V_2 -> V_37 ;
}
V_396 . V_170 = V_170 ;
V_396 . V_193 = V_193 ;
return F_226 ( V_2 -> V_131 . V_32 , & V_396 ) ;
}
int F_227 ( struct V_83 * V_18 , struct V_118 * V_119 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
V_2 -> V_91 = F_49 ( V_92 ) ;
if ( ! F_1 ( V_2 , V_200 ) )
return - V_40 ;
if ( ! V_18 -> V_99 && V_119 ) {
V_2 -> V_116 = V_119 -> V_116 ;
V_2 -> V_117 = V_119 -> V_117 ;
}
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
if ( V_18 -> V_88 == V_114 ) {
if ( V_119 )
V_6 = F_225 ( V_2 , V_401 ,
V_119 -> V_37 ,
V_119 -> V_170 ,
V_119 -> V_193 ) ;
else
V_6 = F_225 ( V_2 , V_401 ,
0 , NULL , 0 ) ;
} else {
if ( V_119 )
V_6 = F_221 ( V_2 , V_119 ) ;
else
V_6 = F_114 ( V_2 ) ;
}
break;
case V_133 :
V_6 = F_223 ( V_2 , V_119 ) ;
break;
default:
V_6 = - V_135 ;
break;
}
if ( V_6 )
goto V_187;
return 0 ;
V_187:
F_68 ( V_2 ) ;
F_228 ( V_18 , NULL , 0 ) ;
return V_6 ;
}
int F_229 ( struct V_83 * V_18 , enum V_420 V_165 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! V_2 -> V_131 . V_32 )
return - V_40 ;
switch ( V_18 -> V_19 -> V_24 ) {
case V_421 :
V_6 = F_230 ( V_2 -> V_131 . V_32 , V_165 ) ;
break;
default:
V_6 = 0 ;
break;
}
return V_6 ;
}
int F_228 ( struct V_83 * V_18 , const void * V_170 ,
T_1 V_193 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! V_2 -> V_131 . V_32 )
return - V_40 ;
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
if ( V_18 -> V_88 == V_114 )
V_6 = F_225 ( V_2 , V_422 , 0 ,
V_170 , V_193 ) ;
else
V_6 = F_116 ( V_2 -> V_131 . V_32 ,
V_188 , NULL ,
0 , V_170 , V_193 ) ;
break;
case V_133 :
V_6 = F_231 ( V_2 -> V_131 . V_134 ,
V_170 , V_193 ) ;
break;
default:
V_6 = - V_135 ;
break;
}
return V_6 ;
}
int F_232 ( struct V_83 * V_18 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! V_2 -> V_131 . V_32 )
return - V_40 ;
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
V_6 = F_68 ( V_2 ) ;
if ( V_6 )
goto V_70;
if ( F_233 ( V_2 -> V_131 . V_32 , NULL , 0 ) )
F_234 ( V_2 -> V_131 . V_32 , NULL , 0 ) ;
break;
case V_133 :
V_6 = F_235 ( V_2 -> V_131 . V_134 , 0 ) ;
break;
default:
V_6 = - V_40 ;
break;
}
V_70:
return V_6 ;
}
static int F_236 ( int V_205 , struct V_423 * V_31 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = V_31 -> V_85 ;
struct V_189 V_165 ;
int V_6 ;
V_2 = V_29 -> V_2 ;
if ( F_45 ( V_2 , V_281 ) &&
F_45 ( V_2 , V_290 ) )
return 0 ;
if ( ! V_205 )
V_205 = F_25 ( V_2 , F_28 ( V_31 -> V_39 . V_37 ) ) ;
F_19 ( & V_2 -> V_94 ) ;
if ( ! V_205 && V_2 -> V_18 . V_99 )
V_205 = F_237 ( V_2 -> V_18 . V_99 , & V_31 -> V_39 . V_46 ,
F_122 ( V_31 -> V_39 . V_424 ) ) ;
F_21 ( & V_2 -> V_94 ) ;
memset ( & V_165 , 0 , sizeof V_165 ) ;
V_165 . V_205 = V_205 ;
V_165 . V_167 . V_239 . V_170 = V_29 -> V_85 ;
if ( ! V_205 ) {
V_165 . V_165 = V_425 ;
F_238 ( V_2 -> V_18 . V_19 ,
V_2 -> V_18 . V_47 , & V_31 -> V_39 ,
& V_165 . V_167 . V_239 . V_402 ) ;
V_165 . V_167 . V_239 . V_116 = 0xFFFFFF ;
V_165 . V_167 . V_239 . V_37 = F_28 ( V_31 -> V_39 . V_37 ) ;
} else
V_165 . V_165 = V_426 ;
V_6 = V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_165 ) ;
if ( V_6 ) {
F_5 ( V_2 , V_184 ) ;
F_21 ( & V_2 -> V_82 ) ;
F_101 ( & V_2 -> V_18 ) ;
return 0 ;
}
F_21 ( & V_2 -> V_82 ) ;
return 0 ;
}
static void F_239 ( struct V_1 * V_2 ,
struct V_33 * V_21 , union V_53 * V_46 )
{
unsigned char V_427 [ V_428 ] ;
struct V_50 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
struct V_137 * sin = (struct V_137 * ) V_21 ;
struct V_141 * V_295 = (struct V_141 * ) V_21 ;
if ( F_81 ( V_21 ) ) {
memset ( V_46 , 0 , sizeof *V_46 ) ;
} else if ( ( V_21 -> V_56 == V_140 ) &&
( ( F_28 ( V_295 -> V_142 . V_429 [ 0 ] ) & 0xFFF0FFFF ) ==
0xFF10A01B ) ) {
memcpy ( V_46 , & V_295 -> V_142 , sizeof *V_46 ) ;
} else if ( V_21 -> V_56 == V_57 ) {
memcpy ( V_46 , & ( (struct V_48 * ) V_21 ) -> V_54 , sizeof *V_46 ) ;
} else if ( ( V_21 -> V_56 == V_140 ) ) {
F_240 ( & V_295 -> V_142 , V_22 -> V_430 , V_427 ) ;
if ( V_2 -> V_18 . V_41 == V_42 )
V_427 [ 7 ] = 0x01 ;
* V_46 = * (union V_53 * ) ( V_427 + 4 ) ;
} else {
F_241 ( sin -> V_138 . V_139 , V_22 -> V_430 , V_427 ) ;
if ( V_2 -> V_18 . V_41 == V_42 )
V_427 [ 7 ] = 0x01 ;
* V_46 = * (union V_53 * ) ( V_427 + 4 ) ;
}
}
static int F_242 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_38 V_39 ;
struct V_50 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
T_8 V_294 ;
int V_6 ;
F_26 ( V_22 , & V_39 . V_46 ) ;
V_6 = F_27 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ,
& V_39 . V_46 , & V_39 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_25 ( V_2 , 0 ) ;
if ( V_6 )
return V_6 ;
F_239 ( V_2 , (struct V_33 * ) & V_29 -> V_21 , & V_39 . V_46 ) ;
V_39 . V_37 = F_243 ( V_2 -> V_37 ) ;
F_152 ( V_22 , & V_39 . V_431 ) ;
V_39 . V_75 = F_154 ( F_70 ( V_22 ) ) ;
V_39 . V_432 = 1 ;
V_294 = V_433 | V_434 |
V_435 | V_436 |
V_437 | V_438 |
V_439 |
V_440 ;
if ( V_2 -> V_18 . V_41 == V_45 )
V_294 |= V_441 |
V_442 |
V_443 |
V_444 |
V_445 ;
V_29 -> V_31 . V_32 = F_244 ( & V_310 , V_2 -> V_18 . V_19 ,
V_2 -> V_18 . V_47 , & V_39 ,
V_294 , V_89 ,
F_236 , V_29 ) ;
return F_245 ( V_29 -> V_31 . V_32 ) ;
}
static void F_246 ( struct V_311 * V_287 )
{
struct V_446 * V_447 = F_16 ( V_287 , struct V_446 , V_287 ) ;
struct V_28 * V_29 = V_447 -> V_29 ;
struct V_423 * V_448 = V_29 -> V_31 . V_32 ;
V_29 -> V_31 . V_32 -> V_85 = V_29 ;
F_236 ( 0 , V_448 ) ;
F_110 ( & V_29 -> V_30 , F_15 ) ;
F_17 ( V_447 ) ;
}
static void F_247 ( struct V_33 * V_21 , union V_53 * V_46 )
{
struct V_137 * sin = (struct V_137 * ) V_21 ;
struct V_141 * V_295 = (struct V_141 * ) V_21 ;
if ( F_81 ( V_21 ) ) {
memset ( V_46 , 0 , sizeof *V_46 ) ;
} else if ( V_21 -> V_56 == V_140 ) {
memcpy ( V_46 , & V_295 -> V_142 , sizeof *V_46 ) ;
} else {
V_46 -> V_449 [ 0 ] = 0xff ;
V_46 -> V_449 [ 1 ] = 0x0e ;
V_46 -> V_449 [ 2 ] = 0 ;
V_46 -> V_449 [ 3 ] = 0 ;
V_46 -> V_449 [ 4 ] = 0 ;
V_46 -> V_449 [ 5 ] = 0 ;
V_46 -> V_449 [ 6 ] = 0 ;
V_46 -> V_449 [ 7 ] = 0 ;
V_46 -> V_449 [ 8 ] = 0 ;
V_46 -> V_449 [ 9 ] = 0 ;
V_46 -> V_449 [ 10 ] = 0xff ;
V_46 -> V_449 [ 11 ] = 0xff ;
* ( T_7 * ) ( & V_46 -> V_449 [ 12 ] ) = sin -> V_138 . V_139 ;
}
}
static int F_248 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_446 * V_287 ;
struct V_50 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
int V_115 ;
struct V_33 * V_21 = (struct V_33 * ) & V_29 -> V_21 ;
struct V_318 * V_319 = NULL ;
if ( F_73 ( (struct V_33 * ) & V_29 -> V_21 ) )
return - V_40 ;
V_287 = F_47 ( sizeof *V_287 , V_89 ) ;
if ( ! V_287 )
return - V_90 ;
V_29 -> V_31 . V_32 = F_47 ( sizeof( struct V_423 ) , V_89 ) ;
if ( ! V_29 -> V_31 . V_32 ) {
V_115 = - V_90 ;
goto V_450;
}
F_247 ( V_21 , & V_29 -> V_31 . V_32 -> V_39 . V_46 ) ;
V_29 -> V_31 . V_32 -> V_39 . V_75 = F_154 ( 0xffff ) ;
if ( V_2 -> V_18 . V_41 == V_42 )
V_29 -> V_31 . V_32 -> V_39 . V_37 = F_243 ( V_44 ) ;
if ( V_22 -> V_330 )
V_319 = F_170 ( & V_331 , V_22 -> V_330 ) ;
if ( ! V_319 ) {
V_115 = - V_61 ;
goto V_451;
}
V_29 -> V_31 . V_32 -> V_39 . V_339 = F_174 ( V_319 ) ;
V_29 -> V_31 . V_32 -> V_39 . V_333 = 1 ;
V_29 -> V_31 . V_32 -> V_39 . V_337 = F_173 ( V_319 -> V_337 ) ;
F_175 ( V_319 ) ;
if ( ! V_29 -> V_31 . V_32 -> V_39 . V_337 ) {
V_115 = - V_40 ;
goto V_451;
}
F_36 ( V_22 , & V_29 -> V_31 . V_32 -> V_39 . V_431 ) ;
V_287 -> V_18 = V_2 ;
V_287 -> V_29 = V_29 ;
F_159 ( & V_287 -> V_287 , F_246 ) ;
F_249 ( & V_29 -> V_30 ) ;
F_150 ( V_292 , & V_287 -> V_287 ) ;
return 0 ;
V_451:
F_17 ( V_29 -> V_31 . V_32 ) ;
V_450:
F_17 ( V_287 ) ;
return V_115 ;
}
int F_250 ( struct V_83 * V_18 , struct V_33 * V_21 ,
void * V_85 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_1 ( V_2 , V_281 ) &&
! F_1 ( V_2 , V_290 ) )
return - V_40 ;
V_29 = F_121 ( sizeof *V_29 , V_89 ) ;
if ( ! V_29 )
return - V_90 ;
memcpy ( & V_29 -> V_21 , V_21 , F_134 ( V_21 ) ) ;
V_29 -> V_85 = V_85 ;
V_29 -> V_2 = V_2 ;
F_251 ( & V_2 -> V_7 ) ;
F_252 ( & V_29 -> V_25 , & V_2 -> V_96 ) ;
F_253 ( & V_2 -> V_7 ) ;
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
switch ( F_38 ( V_18 -> V_19 , V_18 -> V_47 ) ) {
case V_66 :
V_6 = F_242 ( V_2 , V_29 ) ;
break;
case V_67 :
F_254 ( & V_29 -> V_30 ) ;
V_6 = F_248 ( V_2 , V_29 ) ;
break;
default:
V_6 = - V_40 ;
}
break;
default:
V_6 = - V_135 ;
break;
}
if ( V_6 ) {
F_255 ( & V_2 -> V_7 ) ;
F_20 ( & V_29 -> V_25 ) ;
F_256 ( & V_2 -> V_7 ) ;
F_17 ( V_29 ) ;
}
return V_6 ;
}
void F_257 ( struct V_83 * V_18 , struct V_33 * V_21 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
F_255 ( & V_2 -> V_7 ) ;
F_40 (mc, &id_priv->mc_list, list) {
if ( ! memcmp ( & V_29 -> V_21 , V_21 , F_134 ( V_21 ) ) ) {
F_20 ( & V_29 -> V_25 ) ;
F_256 ( & V_2 -> V_7 ) ;
if ( V_18 -> V_99 )
F_258 ( V_18 -> V_99 ,
& V_29 -> V_31 . V_32 -> V_39 . V_46 ,
F_122 ( V_29 -> V_31 . V_32 -> V_39 . V_424 ) ) ;
if ( F_10 ( V_2 -> V_16 -> V_19 -> V_24 ) == V_69 ) {
switch ( F_38 ( V_18 -> V_19 , V_18 -> V_47 ) ) {
case V_66 :
F_109 ( V_29 -> V_31 . V_32 ) ;
F_17 ( V_29 ) ;
break;
case V_67 :
F_110 ( & V_29 -> V_30 , F_15 ) ;
break;
default:
break;
}
}
return;
}
}
F_256 ( & V_2 -> V_7 ) ;
}
static int F_259 ( struct V_318 * V_319 , struct V_1 * V_2 )
{
struct V_50 * V_22 ;
struct V_314 * V_287 ;
V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
if ( ( V_22 -> V_330 == V_319 -> V_452 ) &&
memcmp ( V_22 -> V_68 , V_319 -> V_22 , V_319 -> V_453 ) ) {
F_119 ( V_454 L_4 ,
V_319 -> V_283 , & V_2 -> V_18 ) ;
V_287 = F_47 ( sizeof *V_287 , V_89 ) ;
if ( ! V_287 )
return - V_90 ;
F_159 ( & V_287 -> V_287 , F_157 ) ;
V_287 -> V_18 = V_2 ;
V_287 -> V_165 . V_165 = V_455 ;
F_9 ( & V_2 -> V_17 ) ;
F_150 ( V_292 , & V_287 -> V_287 ) ;
}
return 0 ;
}
static int F_260 ( struct V_456 * V_457 , unsigned long V_165 ,
void * V_458 )
{
struct V_318 * V_319 = F_261 ( V_458 ) ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_6 = V_459 ;
if ( F_262 ( V_319 ) != & V_331 )
return V_459 ;
if ( V_165 != V_460 )
return V_459 ;
if ( ! ( V_319 -> V_5 & V_461 ) || ! ( V_319 -> V_322 & V_462 ) )
return V_459 ;
F_19 ( & V_7 ) ;
F_40 (cma_dev, &dev_list, list)
F_40 (id_priv, &cma_dev->id_list, list) {
V_6 = F_259 ( V_319 , V_2 ) ;
if ( V_6 )
goto V_70;
}
V_70:
F_21 ( & V_7 ) ;
return V_6 ;
}
static void F_263 ( struct V_463 * V_19 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
V_16 = F_121 ( sizeof *V_16 , V_89 ) ;
if ( ! V_16 )
return;
V_16 -> V_19 = V_19 ;
F_52 ( & V_16 -> V_4 ) ;
F_53 ( & V_16 -> V_17 , 1 ) ;
F_54 ( & V_16 -> V_26 ) ;
F_264 ( V_19 , & V_464 , V_16 ) ;
F_19 ( & V_7 ) ;
F_11 ( & V_16 -> V_25 , & V_465 ) ;
F_40 (id_priv, &listen_any_list, list)
F_145 ( V_2 , V_16 ) ;
F_21 ( & V_7 ) ;
}
static int F_265 ( struct V_1 * V_2 )
{
struct V_189 V_165 ;
enum V_3 V_8 ;
int V_6 = 0 ;
V_8 = F_5 ( V_2 , V_315 ) ;
if ( V_8 == V_184 )
return 0 ;
F_102 ( V_2 , V_8 ) ;
F_19 ( & V_2 -> V_82 ) ;
if ( ! F_1 ( V_2 , V_315 ) )
goto V_70;
memset ( & V_165 , 0 , sizeof V_165 ) ;
V_165 . V_165 = V_466 ;
V_6 = V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_165 ) ;
V_70:
F_21 ( & V_2 -> V_82 ) ;
return V_6 ;
}
static void F_266 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
int V_6 ;
F_19 ( & V_7 ) ;
while ( ! F_98 ( & V_16 -> V_26 ) ) {
V_2 = F_99 ( V_16 -> V_26 . V_176 ,
struct V_1 , V_25 ) ;
F_20 ( & V_2 -> V_95 ) ;
F_100 ( & V_2 -> V_25 ) ;
F_9 ( & V_2 -> V_17 ) ;
F_21 ( & V_7 ) ;
V_6 = V_2 -> V_185 ? 1 : F_265 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( V_6 )
F_101 ( & V_2 -> V_18 ) ;
F_19 ( & V_7 ) ;
}
F_21 ( & V_7 ) ;
F_12 ( V_16 ) ;
F_113 ( & V_16 -> V_4 ) ;
}
static void F_267 ( struct V_463 * V_19 )
{
struct V_15 * V_16 ;
V_16 = F_268 ( V_19 , & V_464 ) ;
if ( ! V_16 )
return;
F_19 ( & V_7 ) ;
F_20 ( & V_16 -> V_25 ) ;
F_21 ( & V_7 ) ;
F_266 ( V_16 ) ;
F_17 ( V_16 ) ;
}
static int F_269 ( struct V_467 * V_468 , struct V_469 * V_470 )
{
struct V_471 * V_472 ;
struct V_473 * V_474 ;
struct V_1 * V_2 ;
struct V_83 * V_18 = NULL ;
struct V_15 * V_16 ;
int V_475 = 0 , V_476 = 0 ;
F_19 ( & V_7 ) ;
F_40 (cma_dev, &dev_list, list) {
if ( V_475 < V_470 -> args [ 0 ] ) {
V_475 ++ ;
continue;
}
V_476 = 0 ;
F_40 (id_priv, &cma_dev->id_list, list) {
if ( V_476 < V_470 -> args [ 1 ] ) {
V_476 ++ ;
continue;
}
V_474 = F_270 ( V_468 , & V_472 , V_470 -> V_472 -> V_477 ,
sizeof *V_474 , V_478 ,
V_479 ) ;
if ( ! V_474 )
goto V_70;
memset ( V_474 , 0 , sizeof *V_474 ) ;
V_18 = & V_2 -> V_18 ;
V_474 -> V_24 = V_18 -> V_20 . V_21 . V_22 . V_51 ;
V_474 -> V_47 = V_18 -> V_47 ;
V_474 -> V_330 =
V_18 -> V_20 . V_21 . V_22 . V_330 ;
if ( F_271 ( V_468 , V_472 ,
F_134 ( F_22 ( V_2 ) ) ,
F_22 ( V_2 ) ,
V_480 ) )
goto V_70;
if ( F_271 ( V_468 , V_472 ,
F_134 ( F_22 ( V_2 ) ) ,
F_23 ( V_2 ) ,
V_481 ) )
goto V_70;
V_474 -> V_482 = V_2 -> V_91 ;
V_474 -> V_483 = V_18 -> V_41 ;
V_474 -> V_484 = V_2 -> V_8 ;
V_474 -> V_116 = V_2 -> V_116 ;
V_474 -> V_88 = V_18 -> V_88 ;
V_476 ++ ;
}
V_470 -> args [ 1 ] = 0 ;
V_475 ++ ;
}
V_70:
F_21 ( & V_7 ) ;
V_470 -> args [ 0 ] = V_475 ;
V_470 -> args [ 1 ] = V_476 ;
return V_468 -> V_485 ;
}
static int T_10 F_272 ( void )
{
int V_6 ;
V_292 = F_273 ( L_5 ) ;
if ( ! V_292 )
return - V_90 ;
F_274 ( & V_310 ) ;
F_275 ( & V_352 ) ;
F_276 ( & V_486 ) ;
V_6 = F_277 ( & V_464 ) ;
if ( V_6 )
goto V_115;
if ( F_278 ( V_478 , V_487 , V_488 ) )
F_119 ( V_282 L_6 ) ;
return 0 ;
V_115:
F_279 ( & V_486 ) ;
F_280 ( & V_352 ) ;
F_281 ( & V_310 ) ;
F_282 ( V_292 ) ;
return V_6 ;
}
static void T_11 F_283 ( void )
{
F_284 ( V_478 ) ;
F_285 ( & V_464 ) ;
F_279 ( & V_486 ) ;
F_280 ( & V_352 ) ;
F_281 ( & V_310 ) ;
F_282 ( V_292 ) ;
F_286 ( & V_375 ) ;
F_286 ( & V_376 ) ;
F_286 ( & V_377 ) ;
F_286 ( & V_378 ) ;
}
