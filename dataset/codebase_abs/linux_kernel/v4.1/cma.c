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
V_6 = F_34 ( V_21 , V_22 , NULL ) ;
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
F_36 ( (struct V_33 * ) & V_2 -> V_18 . V_20 . V_21 . V_34 ,
& V_60 ) ;
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
union V_53 V_73 ;
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
V_6 = F_67 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ,
V_101 . V_120 . V_121 . V_122 , & V_73 ) ;
if ( V_6 )
goto V_70;
if ( F_10 ( V_2 -> V_16 -> V_19 -> V_24 )
== V_69 &&
F_38 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 )
== V_67 ) {
V_6 = F_68 ( & V_73 , V_101 . V_123 , NULL ) ;
if ( V_6 )
goto V_70;
}
if ( V_119 )
V_101 . V_124 = V_119 -> V_125 ;
V_6 = F_58 ( V_2 -> V_18 . V_99 , & V_101 , V_102 ) ;
V_70:
F_21 ( & V_2 -> V_94 ) ;
return V_6 ;
}
static int F_69 ( struct V_1 * V_2 ,
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
V_101 . V_126 = V_119 -> V_127 ;
V_6 = F_58 ( V_2 -> V_18 . V_99 , & V_101 , V_102 ) ;
V_70:
F_21 ( & V_2 -> V_94 ) ;
return V_6 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_100 V_101 ;
int V_6 ;
F_19 ( & V_2 -> V_94 ) ;
if ( ! V_2 -> V_18 . V_99 ) {
V_6 = 0 ;
goto V_70;
}
V_101 . V_103 = V_128 ;
V_6 = F_58 ( V_2 -> V_18 . V_99 , & V_101 , V_106 ) ;
V_70:
F_21 ( & V_2 -> V_94 ) ;
return V_6 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_100 * V_101 , int * V_102 )
{
struct V_50 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
int V_6 ;
T_3 V_75 ;
if ( F_38 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ) ==
V_66 )
V_75 = F_72 ( V_22 ) ;
else
V_75 = 0xffff ;
V_6 = F_42 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ,
V_75 , & V_101 -> V_129 ) ;
if ( V_6 )
return V_6 ;
V_101 -> V_47 = V_2 -> V_18 . V_47 ;
* V_102 = V_106 | V_130 | V_131 ;
if ( V_2 -> V_18 . V_88 == V_114 ) {
V_6 = F_25 ( V_2 , 0 ) ;
if ( V_6 )
return V_6 ;
V_101 -> V_37 = V_2 -> V_37 ;
* V_102 |= V_132 ;
} else {
V_101 -> V_133 = 0 ;
* V_102 |= V_134 ;
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
if ( ! V_2 -> V_135 . V_32 || ( V_2 -> V_18 . V_88 == V_114 ) )
V_6 = F_71 ( V_2 , V_101 , V_102 ) ;
else
V_6 = F_73 ( V_2 -> V_135 . V_32 , V_101 ,
V_102 ) ;
if ( V_101 -> V_103 == V_105 )
V_101 -> V_136 = V_2 -> V_97 ;
break;
case V_137 :
if ( ! V_2 -> V_135 . V_138 ) {
V_101 -> V_133 = 0 ;
* V_102 = V_106 | V_134 ;
} else
V_6 = F_74 ( V_2 -> V_135 . V_138 , V_101 ,
V_102 ) ;
break;
default:
V_6 = - V_139 ;
break;
}
return V_6 ;
}
static inline int F_75 ( struct V_33 * V_21 )
{
switch ( V_21 -> V_56 ) {
case V_140 :
return F_76 ( ( (struct V_141 * ) V_21 ) -> V_142 . V_143 ) ;
case V_144 :
return F_77 ( & ( (struct V_145 * ) V_21 ) -> V_146 ) ;
case V_57 :
return F_78 ( & ( (struct V_48 * ) V_21 ) -> V_54 ) ;
default:
return 0 ;
}
}
static inline int F_79 ( struct V_33 * V_21 )
{
switch ( V_21 -> V_56 ) {
case V_140 :
return F_80 ( ( (struct V_141 * ) V_21 ) -> V_142 . V_143 ) ;
case V_144 :
return F_81 ( & ( (struct V_145 * ) V_21 ) -> V_146 ) ;
case V_57 :
return F_82 ( & ( (struct V_48 * ) V_21 ) -> V_54 ) ;
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
if ( V_147 -> V_56 != V_148 -> V_56 )
return - 1 ;
switch ( V_147 -> V_56 ) {
case V_140 :
return ( (struct V_141 * ) V_147 ) -> V_142 . V_143 !=
( (struct V_141 * ) V_148 ) -> V_142 . V_143 ;
case V_144 :
return F_85 ( & ( (struct V_145 * ) V_147 ) -> V_146 ,
& ( (struct V_145 * ) V_148 ) -> V_146 ) ;
default:
return F_86 ( & ( (struct V_48 * ) V_147 ) -> V_54 ,
& ( (struct V_48 * ) V_148 ) -> V_54 ) ;
}
}
static T_5 F_87 ( struct V_33 * V_21 )
{
struct V_48 * V_49 ;
switch ( V_21 -> V_56 ) {
case V_140 :
return ( (struct V_141 * ) V_21 ) -> V_149 ;
case V_144 :
return ( (struct V_145 * ) V_21 ) -> V_150 ;
case V_57 :
V_49 = (struct V_48 * ) V_21 ;
return F_88 ( ( T_3 ) ( F_89 ( V_49 -> V_151 ) &
F_89 ( V_49 -> V_152 ) ) ) ;
default:
return 0 ;
}
}
static inline int F_90 ( struct V_33 * V_21 )
{
return ! F_87 ( V_21 ) ;
}
static void F_91 ( struct V_83 * V_18 , struct V_83 * V_153 ,
struct V_154 * V_155 )
{
struct V_48 * V_156 , * V_32 ;
V_156 = (struct V_48 * ) & V_153 -> V_20 . V_21 . V_34 ;
V_32 = (struct V_48 * ) & V_18 -> V_20 . V_21 . V_34 ;
V_32 -> V_157 = V_156 -> V_157 ;
if ( V_155 ) {
V_32 -> V_55 = V_155 -> V_75 ;
V_32 -> V_158 = V_155 -> V_159 ;
memcpy ( & V_32 -> V_54 , & V_155 -> V_73 , 16 ) ;
} else {
V_32 -> V_55 = V_156 -> V_55 ;
V_32 -> V_158 = V_156 -> V_158 ;
V_32 -> V_54 = V_156 -> V_54 ;
}
V_32 -> V_151 = V_156 -> V_151 ;
V_32 -> V_152 = F_92 ( 0xffffffffffffffffULL ) ;
V_32 -> V_160 = V_156 -> V_160 ;
if ( V_155 ) {
V_32 = (struct V_48 * ) & V_18 -> V_20 . V_21 . V_35 ;
V_32 -> V_157 = V_156 -> V_157 ;
V_32 -> V_55 = V_155 -> V_75 ;
V_32 -> V_158 = V_155 -> V_159 ;
memcpy ( & V_32 -> V_54 , & V_155 -> V_74 , 16 ) ;
}
}
static T_5 F_93 ( const struct V_161 * V_162 )
{
if ( V_162 -> V_36 == V_140 )
return ( (struct V_141 * ) V_162 ) -> V_149 ;
else if ( V_162 -> V_36 == V_144 )
return ( (struct V_145 * ) V_162 ) -> V_150 ;
F_94 () ;
}
static void F_95 ( struct V_83 * V_18 , struct V_83 * V_153 ,
struct V_11 * V_12 )
{
struct V_141 * V_163 ;
V_163 = (struct V_141 * ) & V_18 -> V_20 . V_21 . V_34 ;
V_163 -> V_164 = V_140 ;
V_163 -> V_142 . V_143 = V_12 -> V_35 . V_163 . V_21 ;
V_163 -> V_149 = F_93 ( & V_153 -> V_20 . V_21 . V_34 ) ;
V_163 = (struct V_141 * ) & V_18 -> V_20 . V_21 . V_35 ;
V_163 -> V_164 = V_140 ;
V_163 -> V_142 . V_143 = V_12 -> V_34 . V_163 . V_21 ;
V_163 -> V_149 = V_12 -> V_62 ;
}
static void F_96 ( struct V_83 * V_18 , struct V_83 * V_153 ,
struct V_11 * V_12 )
{
struct V_145 * V_165 ;
V_165 = (struct V_145 * ) & V_18 -> V_20 . V_21 . V_34 ;
V_165 -> V_166 = V_144 ;
V_165 -> V_146 = V_12 -> V_35 . V_165 ;
V_165 -> V_150 = F_93 ( & V_153 -> V_20 . V_21 . V_34 ) ;
V_165 = (struct V_145 * ) & V_18 -> V_20 . V_21 . V_35 ;
V_165 -> V_166 = V_144 ;
V_165 -> V_146 = V_12 -> V_34 . V_165 ;
V_165 -> V_150 = V_12 -> V_62 ;
}
static int F_97 ( struct V_83 * V_18 , struct V_83 * V_153 ,
struct V_167 * V_168 )
{
struct V_11 * V_12 ;
if ( V_153 -> V_20 . V_21 . V_34 . V_36 == V_57 ) {
if ( V_168 -> V_169 == V_170 )
F_91 ( V_18 , V_153 , V_168 -> V_171 . V_172 . V_173 ) ;
else if ( V_168 -> V_169 == V_174 )
F_91 ( V_18 , V_153 , NULL ) ;
return 0 ;
}
V_12 = V_168 -> V_175 ;
if ( V_12 -> V_176 != V_177 )
return - V_40 ;
switch ( F_6 ( V_12 ) ) {
case 4 :
F_95 ( V_18 , V_153 , V_12 ) ;
break;
case 6 :
F_96 ( V_18 , V_153 , V_12 ) ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static inline int F_98 ( struct V_1 * V_2 )
{
return F_24 ( V_2 ) == V_57 ? 0 : sizeof( struct V_11 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
switch ( F_38 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ) ) {
case V_66 :
if ( V_2 -> V_178 )
F_100 ( V_2 -> V_179 , V_2 -> V_178 ) ;
break;
default:
break;
}
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_1 * V_180 ;
F_19 ( & V_7 ) ;
F_20 ( & V_2 -> V_25 ) ;
while ( ! F_102 ( & V_2 -> V_95 ) ) {
V_180 = F_103 ( V_2 -> V_95 . V_181 ,
struct V_1 , V_95 ) ;
F_104 ( & V_180 -> V_25 ) ;
F_20 ( & V_180 -> V_95 ) ;
F_21 ( & V_7 ) ;
F_105 ( & V_180 -> V_18 ) ;
F_19 ( & V_7 ) ;
}
F_21 ( & V_7 ) ;
}
static void F_106 ( struct V_1 * V_2 ,
enum V_3 V_8 )
{
switch ( V_8 ) {
case V_182 :
F_107 ( & V_2 -> V_18 . V_20 . V_21 . V_22 ) ;
break;
case V_183 :
F_99 ( V_2 ) ;
break;
case V_184 :
if ( F_83 ( F_22 ( V_2 ) ) && ! V_2 -> V_16 )
F_101 ( V_2 ) ;
break;
default:
break;
}
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_185 * V_186 = V_2 -> V_186 ;
if ( ! V_186 )
return;
F_19 ( & V_7 ) ;
F_109 ( & V_2 -> V_187 ) ;
if ( F_110 ( & V_186 -> V_188 ) ) {
F_111 ( V_186 -> V_41 , V_186 -> V_62 ) ;
F_17 ( V_186 ) ;
}
F_21 ( & V_7 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
while ( ! F_102 ( & V_2 -> V_96 ) ) {
V_29 = F_16 ( V_2 -> V_96 . V_181 ,
struct V_28 , V_25 ) ;
F_20 ( & V_29 -> V_25 ) ;
switch ( F_38 ( V_2 -> V_16 -> V_19 , V_2 -> V_18 . V_47 ) ) {
case V_66 :
F_113 ( V_29 -> V_31 . V_32 ) ;
F_17 ( V_29 ) ;
break;
case V_67 :
F_114 ( & V_29 -> V_30 , F_15 ) ;
break;
default:
break;
}
}
}
void F_105 ( struct V_83 * V_18 )
{
struct V_1 * V_2 ;
enum V_3 V_8 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
V_8 = F_5 ( V_2 , V_189 ) ;
F_106 ( V_2 , V_8 ) ;
F_19 ( & V_2 -> V_82 ) ;
F_21 ( & V_2 -> V_82 ) ;
if ( V_2 -> V_16 ) {
switch ( F_10 ( V_2 -> V_18 . V_19 -> V_24 ) ) {
case V_69 :
if ( V_2 -> V_135 . V_32 )
F_115 ( V_2 -> V_135 . V_32 ) ;
break;
case V_137 :
if ( V_2 -> V_135 . V_138 )
F_116 ( V_2 -> V_135 . V_138 ) ;
break;
default:
break;
}
F_112 ( V_2 ) ;
F_18 ( V_2 ) ;
}
F_108 ( V_2 ) ;
F_44 ( V_2 ) ;
F_117 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_190 )
F_44 ( V_2 -> V_18 . V_85 ) ;
F_17 ( V_2 -> V_18 . V_20 . V_191 ) ;
F_17 ( V_2 ) ;
}
static int F_118 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_66 ( V_2 , NULL ) ;
if ( V_6 )
goto V_192;
V_6 = F_69 ( V_2 , NULL ) ;
if ( V_6 )
goto V_192;
V_6 = F_119 ( V_2 -> V_135 . V_32 , NULL , 0 ) ;
if ( V_6 )
goto V_192;
return 0 ;
V_192:
F_70 ( V_2 ) ;
F_120 ( V_2 -> V_135 . V_32 , V_193 ,
NULL , 0 , NULL , 0 ) ;
return V_6 ;
}
static void F_121 ( struct V_194 * V_169 ,
struct V_195 * V_196 ,
void * V_175 )
{
V_169 -> V_171 . V_197 . V_175 = V_175 ;
V_169 -> V_171 . V_197 . V_198 = V_199 ;
V_169 -> V_171 . V_197 . V_125 = V_196 -> V_125 ;
V_169 -> V_171 . V_197 . V_127 = V_196 -> V_127 ;
V_169 -> V_171 . V_197 . V_200 = V_196 -> V_200 ;
V_169 -> V_171 . V_197 . V_201 = V_196 -> V_201 ;
V_169 -> V_171 . V_197 . V_117 = V_196 -> V_117 ;
V_169 -> V_171 . V_197 . V_116 = V_196 -> V_202 ;
}
static int F_122 ( struct V_203 * V_135 , struct V_167 * V_168 )
{
struct V_1 * V_2 = V_135 -> V_85 ;
struct V_194 V_169 ;
int V_6 = 0 ;
if ( ( V_168 -> V_169 != V_204 &&
F_45 ( V_2 , V_205 ) ) ||
( V_168 -> V_169 == V_204 &&
F_45 ( V_2 , V_206 ) ) )
return 0 ;
memset ( & V_169 , 0 , sizeof V_169 ) ;
switch ( V_168 -> V_169 ) {
case V_207 :
case V_208 :
V_169 . V_169 = V_209 ;
V_169 . V_210 = - V_211 ;
break;
case V_212 :
if ( V_2 -> V_18 . V_99 ) {
V_169 . V_210 = F_118 ( V_2 ) ;
V_169 . V_169 = V_169 . V_210 ? V_213 :
V_214 ;
} else {
V_169 . V_169 = V_215 ;
}
F_121 ( & V_169 , & V_168 -> V_171 . V_216 ,
V_168 -> V_175 ) ;
break;
case V_217 :
case V_218 :
V_169 . V_169 = V_214 ;
break;
case V_219 :
V_169 . V_210 = - V_211 ;
case V_220 :
case V_221 :
if ( ! F_4 ( V_2 , V_205 ,
V_206 ) )
goto V_70;
V_169 . V_169 = V_222 ;
break;
case V_204 :
V_169 . V_169 = V_223 ;
break;
case V_224 :
goto V_70;
case V_225 :
F_70 ( V_2 ) ;
V_169 . V_210 = V_168 -> V_171 . V_226 . V_227 ;
V_169 . V_169 = V_228 ;
V_169 . V_171 . V_197 . V_175 = V_168 -> V_175 ;
V_169 . V_171 . V_197 . V_198 = V_229 ;
break;
default:
F_123 ( V_230 L_1 ,
V_168 -> V_169 ) ;
goto V_70;
}
V_6 = V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_169 ) ;
if ( V_6 ) {
V_2 -> V_135 . V_32 = NULL ;
F_5 ( V_2 , V_189 ) ;
F_21 ( & V_2 -> V_82 ) ;
F_105 ( & V_2 -> V_18 ) ;
return V_6 ;
}
V_70:
F_21 ( & V_2 -> V_82 ) ;
return V_6 ;
}
static struct V_1 * F_124 ( struct V_83 * V_153 ,
struct V_167 * V_168 )
{
struct V_1 * V_2 ;
struct V_83 * V_18 ;
struct V_231 * V_232 ;
int V_6 ;
V_18 = F_46 ( V_153 -> V_84 , V_153 -> V_85 ,
V_153 -> V_41 , V_168 -> V_171 . V_172 . V_88 ) ;
if ( F_62 ( V_18 ) )
return NULL ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( F_97 ( V_18 , V_153 , V_168 ) )
goto V_115;
V_232 = & V_18 -> V_20 ;
V_232 -> V_233 = V_168 -> V_171 . V_172 . V_234 ? 2 : 1 ;
V_232 -> V_191 = F_125 ( sizeof * V_232 -> V_191 * V_232 -> V_233 ,
V_89 ) ;
if ( ! V_232 -> V_191 )
goto V_115;
V_232 -> V_191 [ 0 ] = * V_168 -> V_171 . V_172 . V_173 ;
if ( V_232 -> V_233 == 2 )
V_232 -> V_191 [ 1 ] = * V_168 -> V_171 . V_172 . V_234 ;
if ( F_83 ( F_22 ( V_2 ) ) ) {
V_232 -> V_21 . V_22 . V_51 = V_52 ;
F_30 ( & V_232 -> V_21 . V_22 , & V_232 -> V_191 [ 0 ] . V_73 ) ;
F_31 ( & V_232 -> V_21 . V_22 , F_126 ( V_232 -> V_191 [ 0 ] . V_75 ) ) ;
} else {
V_6 = F_33 ( F_22 ( V_2 ) , & V_232 -> V_21 . V_22 ) ;
if ( V_6 )
goto V_115;
}
F_127 ( & V_232 -> V_21 . V_22 , & V_232 -> V_191 [ 0 ] . V_74 ) ;
V_2 -> V_8 = V_205 ;
return V_2 ;
V_115:
F_105 ( V_18 ) ;
return NULL ;
}
static struct V_1 * F_128 ( struct V_83 * V_153 ,
struct V_167 * V_168 )
{
struct V_1 * V_2 ;
struct V_83 * V_18 ;
int V_6 ;
V_18 = F_46 ( V_153 -> V_84 , V_153 -> V_85 ,
V_153 -> V_41 , V_114 ) ;
if ( F_62 ( V_18 ) )
return NULL ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( F_97 ( V_18 , V_153 , V_168 ) )
goto V_115;
if ( ! F_83 ( (struct V_33 * ) & V_18 -> V_20 . V_21 . V_34 ) ) {
V_6 = F_33 ( F_22 ( V_2 ) , & V_18 -> V_20 . V_21 . V_22 ) ;
if ( V_6 )
goto V_115;
}
V_2 -> V_8 = V_205 ;
return V_2 ;
V_115:
F_105 ( V_18 ) ;
return NULL ;
}
static void F_129 ( struct V_194 * V_169 ,
struct V_235 * V_236 ,
void * V_175 , int V_237 )
{
V_169 -> V_171 . V_197 . V_175 = V_175 + V_237 ;
V_169 -> V_171 . V_197 . V_198 = V_238 - V_237 ;
V_169 -> V_171 . V_197 . V_125 = V_236 -> V_125 ;
V_169 -> V_171 . V_197 . V_127 = V_236 -> V_127 ;
V_169 -> V_171 . V_197 . V_200 = V_236 -> V_200 ;
V_169 -> V_171 . V_197 . V_239 = V_236 -> V_239 ;
V_169 -> V_171 . V_197 . V_201 = V_236 -> V_201 ;
V_169 -> V_171 . V_197 . V_117 = V_236 -> V_117 ;
V_169 -> V_171 . V_197 . V_116 = V_236 -> V_202 ;
}
static int F_130 ( struct V_83 * V_18 , struct V_167 * V_168 )
{
return ( ( ( V_168 -> V_169 == V_170 ) &&
( V_168 -> V_171 . V_172 . V_88 == V_18 -> V_88 ) ) ||
( ( V_168 -> V_169 == V_174 ) &&
( V_18 -> V_88 == V_114 ) ) ||
( ! V_18 -> V_88 ) ) ;
}
static int F_131 ( struct V_203 * V_135 , struct V_167 * V_168 )
{
struct V_1 * V_153 , * V_240 ;
struct V_194 V_169 ;
int V_237 , V_6 ;
V_153 = V_135 -> V_85 ;
if ( ! F_130 ( & V_153 -> V_18 , V_168 ) )
return - V_40 ;
if ( F_45 ( V_153 , V_184 ) )
return - V_241 ;
memset ( & V_169 , 0 , sizeof V_169 ) ;
V_237 = F_98 ( V_153 ) ;
V_169 . V_169 = V_242 ;
if ( V_168 -> V_169 == V_174 ) {
V_240 = F_128 ( & V_153 -> V_18 , V_168 ) ;
V_169 . V_171 . V_243 . V_175 = V_168 -> V_175 + V_237 ;
V_169 . V_171 . V_243 . V_198 =
V_244 - V_237 ;
} else {
V_240 = F_124 ( & V_153 -> V_18 , V_168 ) ;
F_129 ( & V_169 , & V_168 -> V_171 . V_172 ,
V_168 -> V_175 , V_237 ) ;
}
if ( ! V_240 ) {
V_6 = - V_90 ;
goto V_245;
}
F_132 ( & V_240 -> V_82 , V_246 ) ;
V_6 = F_35 ( V_240 , V_153 ) ;
if ( V_6 )
goto V_247;
V_240 -> V_135 . V_32 = V_135 ;
V_135 -> V_85 = V_240 ;
V_135 -> V_248 = F_122 ;
F_9 ( & V_240 -> V_17 ) ;
V_6 = V_240 -> V_18 . V_84 ( & V_240 -> V_18 , & V_169 ) ;
if ( V_6 )
goto V_249;
F_19 ( & V_7 ) ;
if ( F_1 ( V_240 , V_205 ) &&
( V_240 -> V_18 . V_88 != V_114 ) )
F_133 ( V_135 , V_250 , NULL , 0 ) ;
F_21 ( & V_7 ) ;
F_21 ( & V_240 -> V_82 ) ;
F_21 ( & V_153 -> V_82 ) ;
F_44 ( V_240 ) ;
return 0 ;
V_249:
F_44 ( V_240 ) ;
V_240 -> V_135 . V_32 = NULL ;
V_247:
F_5 ( V_240 , V_189 ) ;
F_21 ( & V_240 -> V_82 ) ;
V_245:
F_21 ( & V_153 -> V_82 ) ;
if ( V_240 )
F_105 ( & V_240 -> V_18 ) ;
return V_6 ;
}
T_6 F_134 ( struct V_83 * V_18 , struct V_33 * V_21 )
{
if ( V_21 -> V_56 == V_57 )
return ( (struct V_48 * ) V_21 ) -> V_151 ;
return F_92 ( ( ( V_251 ) V_18 -> V_41 << 16 ) + F_126 ( F_87 ( V_21 ) ) ) ;
}
static void F_135 ( enum V_86 V_41 , struct V_33 * V_21 ,
struct V_252 * V_253 )
{
struct V_11 * V_254 , * V_255 ;
T_7 V_256 ;
struct V_257 V_258 ;
memset ( V_253 , 0 , sizeof *V_253 ) ;
V_254 = ( void * ) V_253 -> V_259 ;
V_255 = ( void * ) V_253 -> V_260 ;
switch ( V_21 -> V_56 ) {
case V_140 :
V_256 = ( (struct V_141 * ) V_21 ) -> V_142 . V_143 ;
F_7 ( V_254 , 4 ) ;
F_7 ( V_255 , 0xF ) ;
if ( ! F_83 ( V_21 ) ) {
V_254 -> V_35 . V_163 . V_21 = V_256 ;
V_255 -> V_35 . V_163 . V_21 = F_136 ( ~ 0 ) ;
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
static int F_137 ( struct V_261 * V_262 , struct V_263 * V_264 )
{
struct V_1 * V_2 = V_262 -> V_85 ;
struct V_194 V_169 ;
int V_6 = 0 ;
struct V_33 * V_265 = (struct V_33 * ) & V_264 -> V_266 ;
struct V_33 * V_267 = (struct V_33 * ) & V_264 -> V_268 ;
if ( F_45 ( V_2 , V_205 ) )
return 0 ;
memset ( & V_169 , 0 , sizeof V_169 ) ;
switch ( V_264 -> V_169 ) {
case V_269 :
V_169 . V_169 = V_222 ;
break;
case V_270 :
memcpy ( F_22 ( V_2 ) , V_265 ,
F_138 ( V_265 ) ) ;
memcpy ( F_23 ( V_2 ) , V_267 ,
F_138 ( V_267 ) ) ;
switch ( V_264 -> V_210 ) {
case 0 :
V_169 . V_169 = V_214 ;
V_169 . V_171 . V_197 . V_127 = V_264 -> V_271 ;
V_169 . V_171 . V_197 . V_125 = V_264 -> V_272 ;
break;
case - V_273 :
case - V_274 :
V_169 . V_169 = V_228 ;
break;
case - V_211 :
V_169 . V_169 = V_209 ;
break;
default:
V_169 . V_169 = V_213 ;
break;
}
break;
case V_275 :
V_169 . V_169 = V_214 ;
V_169 . V_171 . V_197 . V_127 = V_264 -> V_271 ;
V_169 . V_171 . V_197 . V_125 = V_264 -> V_272 ;
break;
default:
F_139 ( 1 ) ;
}
V_169 . V_210 = V_264 -> V_210 ;
V_169 . V_171 . V_197 . V_175 = V_264 -> V_175 ;
V_169 . V_171 . V_197 . V_198 = V_264 -> V_198 ;
V_6 = V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_169 ) ;
if ( V_6 ) {
V_2 -> V_135 . V_138 = NULL ;
F_5 ( V_2 , V_189 ) ;
F_21 ( & V_2 -> V_82 ) ;
F_105 ( & V_2 -> V_18 ) ;
return V_6 ;
}
F_21 ( & V_2 -> V_82 ) ;
return V_6 ;
}
static int F_140 ( struct V_261 * V_135 ,
struct V_263 * V_264 )
{
struct V_83 * V_276 ;
struct V_1 * V_153 , * V_240 ;
struct V_194 V_169 ;
int V_6 ;
struct V_277 V_278 ;
struct V_33 * V_265 = (struct V_33 * ) & V_264 -> V_266 ;
struct V_33 * V_267 = (struct V_33 * ) & V_264 -> V_268 ;
V_153 = V_135 -> V_85 ;
if ( F_45 ( V_153 , V_184 ) )
return - V_241 ;
V_276 = F_46 ( V_153 -> V_18 . V_84 ,
V_153 -> V_18 . V_85 ,
V_279 , V_280 ) ;
if ( F_62 ( V_276 ) ) {
V_6 = - V_90 ;
goto V_70;
}
V_240 = F_16 ( V_276 , struct V_1 , V_18 ) ;
F_132 ( & V_240 -> V_82 , V_246 ) ;
V_240 -> V_8 = V_205 ;
V_6 = F_34 ( V_265 , & V_240 -> V_18 . V_20 . V_21 . V_22 , NULL ) ;
if ( V_6 ) {
F_21 ( & V_240 -> V_82 ) ;
F_105 ( V_276 ) ;
goto V_70;
}
V_6 = F_35 ( V_240 , V_153 ) ;
if ( V_6 ) {
F_21 ( & V_240 -> V_82 ) ;
F_105 ( V_276 ) ;
goto V_70;
}
V_240 -> V_135 . V_138 = V_135 ;
V_135 -> V_85 = V_240 ;
V_135 -> V_248 = F_137 ;
memcpy ( F_22 ( V_240 ) , V_265 , F_138 ( V_265 ) ) ;
memcpy ( F_23 ( V_240 ) , V_267 , F_138 ( V_267 ) ) ;
V_6 = F_141 ( V_240 -> V_18 . V_19 , & V_278 ) ;
if ( V_6 ) {
F_21 ( & V_240 -> V_82 ) ;
F_105 ( V_276 ) ;
goto V_70;
}
memset ( & V_169 , 0 , sizeof V_169 ) ;
V_169 . V_169 = V_242 ;
V_169 . V_171 . V_197 . V_175 = V_264 -> V_175 ;
V_169 . V_171 . V_197 . V_198 = V_264 -> V_198 ;
V_169 . V_171 . V_197 . V_127 = V_264 -> V_271 ;
V_169 . V_171 . V_197 . V_125 = V_264 -> V_272 ;
F_9 ( & V_240 -> V_17 ) ;
V_6 = V_240 -> V_18 . V_84 ( & V_240 -> V_18 , & V_169 ) ;
if ( V_6 ) {
V_240 -> V_135 . V_138 = NULL ;
F_5 ( V_240 , V_189 ) ;
F_21 ( & V_240 -> V_82 ) ;
F_44 ( V_240 ) ;
F_105 ( & V_240 -> V_18 ) ;
goto V_70;
}
F_21 ( & V_240 -> V_82 ) ;
F_44 ( V_240 ) ;
V_70:
F_21 ( & V_153 -> V_82 ) ;
return V_6 ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_252 V_281 ;
struct V_33 * V_21 ;
struct V_203 * V_18 ;
T_6 V_282 ;
int V_6 ;
V_18 = F_143 ( V_2 -> V_18 . V_19 , F_131 , V_2 ) ;
if ( F_62 ( V_18 ) )
return F_63 ( V_18 ) ;
V_2 -> V_135 . V_32 = V_18 ;
V_21 = F_22 ( V_2 ) ;
V_282 = F_134 ( & V_2 -> V_18 , V_21 ) ;
if ( F_83 ( V_21 ) && ! V_2 -> V_283 )
V_6 = F_144 ( V_2 -> V_135 . V_32 , V_282 , 0 , NULL ) ;
else {
F_135 ( V_2 -> V_18 . V_41 , V_21 , & V_281 ) ;
V_6 = F_144 ( V_2 -> V_135 . V_32 , V_282 , 0 , & V_281 ) ;
}
if ( V_6 ) {
F_115 ( V_2 -> V_135 . V_32 ) ;
V_2 -> V_135 . V_32 = NULL ;
}
return V_6 ;
}
static int F_145 ( struct V_1 * V_2 , int V_284 )
{
int V_6 ;
struct V_261 * V_18 ;
V_18 = F_146 ( V_2 -> V_18 . V_19 ,
F_140 ,
V_2 ) ;
if ( F_62 ( V_18 ) )
return F_63 ( V_18 ) ;
V_2 -> V_135 . V_138 = V_18 ;
memcpy ( & V_2 -> V_135 . V_138 -> V_266 , F_22 ( V_2 ) ,
F_138 ( F_22 ( V_2 ) ) ) ;
V_6 = F_147 ( V_2 -> V_135 . V_138 , V_284 ) ;
if ( V_6 ) {
F_116 ( V_2 -> V_135 . V_138 ) ;
V_2 -> V_135 . V_138 = NULL ;
}
return V_6 ;
}
static int F_148 ( struct V_83 * V_18 ,
struct V_194 * V_169 )
{
struct V_1 * V_2 = V_18 -> V_85 ;
V_18 -> V_85 = V_2 -> V_18 . V_85 ;
V_18 -> V_84 = V_2 -> V_18 . V_84 ;
return V_2 -> V_18 . V_84 ( V_18 , V_169 ) ;
}
static void F_149 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_1 * V_180 ;
struct V_83 * V_18 ;
int V_6 ;
if ( F_24 ( V_2 ) == V_57 &&
F_10 ( V_16 -> V_19 -> V_24 ) != V_69 )
return;
V_18 = F_46 ( F_148 , V_2 , V_2 -> V_18 . V_41 ,
V_2 -> V_18 . V_88 ) ;
if ( F_62 ( V_18 ) )
return;
V_180 = F_16 ( V_18 , struct V_1 , V_18 ) ;
V_180 -> V_8 = V_285 ;
memcpy ( F_22 ( V_180 ) , F_22 ( V_2 ) ,
F_138 ( F_22 ( V_2 ) ) ) ;
F_8 ( V_180 , V_16 ) ;
F_11 ( & V_180 -> V_95 , & V_2 -> V_95 ) ;
F_9 ( & V_2 -> V_17 ) ;
V_180 -> V_190 = 1 ;
V_180 -> V_283 = V_2 -> V_283 ;
V_6 = F_150 ( V_18 , V_2 -> V_284 ) ;
if ( V_6 )
F_123 ( V_286 L_2
L_3 , V_6 , V_16 -> V_19 -> V_287 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
F_19 ( & V_7 ) ;
F_11 ( & V_2 -> V_25 , & V_288 ) ;
F_40 (cma_dev, &dev_list, list)
F_149 ( V_2 , V_16 ) ;
F_21 ( & V_7 ) ;
}
void F_152 ( struct V_83 * V_18 , int V_289 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
V_2 -> V_289 = ( T_1 ) V_289 ;
}
static void F_153 ( int V_210 , struct V_154 * V_191 ,
void * V_85 )
{
struct V_290 * V_291 = V_85 ;
struct V_231 * V_20 ;
V_20 = & V_291 -> V_18 -> V_18 . V_20 ;
if ( ! V_210 ) {
V_20 -> V_233 = 1 ;
* V_20 -> V_191 = * V_191 ;
} else {
V_291 -> V_292 = V_183 ;
V_291 -> V_293 = V_294 ;
V_291 -> V_169 . V_169 = V_295 ;
V_291 -> V_169 . V_210 = V_210 ;
}
F_154 ( V_296 , & V_291 -> V_291 ) ;
}
static int F_155 ( struct V_1 * V_2 , int V_297 ,
struct V_290 * V_291 )
{
struct V_50 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
struct V_154 V_191 ;
T_8 V_298 ;
struct V_145 * V_299 ;
struct V_48 * V_49 ;
memset ( & V_191 , 0 , sizeof V_191 ) ;
F_156 ( V_22 , & V_191 . V_73 ) ;
F_157 ( V_22 , & V_191 . V_74 ) ;
V_191 . V_75 = F_158 ( F_72 ( V_22 ) ) ;
V_191 . V_300 = 1 ;
V_191 . V_301 = 1 ;
V_191 . V_302 = F_134 ( & V_2 -> V_18 , F_23 ( V_2 ) ) ;
V_298 = V_303 | V_304 |
V_305 | V_306 |
V_307 | V_308 ;
switch ( F_24 ( V_2 ) ) {
case V_140 :
V_191 . V_309 = F_158 ( ( T_3 ) V_2 -> V_289 ) ;
V_298 |= V_310 ;
break;
case V_144 :
V_299 = (struct V_145 * ) F_22 ( V_2 ) ;
V_191 . V_311 = ( T_1 ) ( F_28 ( V_299 -> V_312 ) >> 20 ) ;
V_298 |= V_313 ;
break;
case V_57 :
V_49 = (struct V_48 * ) F_22 ( V_2 ) ;
V_191 . V_311 = ( T_1 ) ( F_28 ( V_49 -> V_158 ) >> 20 ) ;
V_298 |= V_313 ;
break;
}
V_2 -> V_179 = F_159 ( & V_314 , V_2 -> V_18 . V_19 ,
V_2 -> V_18 . V_47 , & V_191 ,
V_298 , V_297 ,
V_89 , F_153 ,
V_291 , & V_2 -> V_178 ) ;
return ( V_2 -> V_179 < 0 ) ? V_2 -> V_179 : 0 ;
}
static void F_160 ( struct V_315 * V_316 )
{
struct V_290 * V_291 = F_16 ( V_316 , struct V_290 , V_291 ) ;
struct V_1 * V_2 = V_291 -> V_18 ;
int V_317 = 0 ;
F_19 ( & V_2 -> V_82 ) ;
if ( ! F_4 ( V_2 , V_291 -> V_292 , V_291 -> V_293 ) )
goto V_70;
if ( V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_291 -> V_169 ) ) {
F_5 ( V_2 , V_189 ) ;
V_317 = 1 ;
}
V_70:
F_21 ( & V_2 -> V_82 ) ;
F_44 ( V_2 ) ;
if ( V_317 )
F_105 ( & V_2 -> V_18 ) ;
F_17 ( V_291 ) ;
}
static void F_161 ( struct V_315 * V_316 )
{
struct V_318 * V_291 = F_16 ( V_316 , struct V_318 , V_291 ) ;
struct V_1 * V_2 = V_291 -> V_18 ;
int V_317 = 0 ;
F_19 ( & V_2 -> V_82 ) ;
if ( V_2 -> V_8 == V_189 ||
V_2 -> V_8 == V_319 )
goto V_70;
if ( V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_291 -> V_169 ) ) {
F_5 ( V_2 , V_189 ) ;
V_317 = 1 ;
}
V_70:
F_21 ( & V_2 -> V_82 ) ;
F_44 ( V_2 ) ;
if ( V_317 )
F_105 ( & V_2 -> V_18 ) ;
F_17 ( V_291 ) ;
}
static int F_162 ( struct V_1 * V_2 , int V_297 )
{
struct V_231 * V_20 = & V_2 -> V_18 . V_20 ;
struct V_290 * V_291 ;
int V_6 ;
V_291 = F_47 ( sizeof *V_291 , V_89 ) ;
if ( ! V_291 )
return - V_90 ;
V_291 -> V_18 = V_2 ;
F_163 ( & V_291 -> V_291 , F_160 ) ;
V_291 -> V_292 = V_183 ;
V_291 -> V_293 = V_320 ;
V_291 -> V_169 . V_169 = V_321 ;
V_20 -> V_191 = F_125 ( sizeof * V_20 -> V_191 , V_89 ) ;
if ( ! V_20 -> V_191 ) {
V_6 = - V_90 ;
goto V_245;
}
V_6 = F_155 ( V_2 , V_297 , V_291 ) ;
if ( V_6 )
goto V_247;
return 0 ;
V_247:
F_17 ( V_20 -> V_191 ) ;
V_20 -> V_191 = NULL ;
V_245:
F_17 ( V_291 ) ;
return V_6 ;
}
int F_164 ( struct V_83 * V_18 ,
struct V_154 * V_191 , int V_233 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_4 ( V_2 , V_294 ,
V_320 ) )
return - V_40 ;
V_18 -> V_20 . V_191 = F_165 ( V_191 , sizeof *V_191 * V_233 ,
V_89 ) ;
if ( ! V_18 -> V_20 . V_191 ) {
V_6 = - V_90 ;
goto V_115;
}
V_18 -> V_20 . V_233 = V_233 ;
return 0 ;
V_115:
F_4 ( V_2 , V_320 , V_294 ) ;
return V_6 ;
}
static int F_166 ( struct V_1 * V_2 , int V_297 )
{
struct V_290 * V_291 ;
V_291 = F_47 ( sizeof *V_291 , V_89 ) ;
if ( ! V_291 )
return - V_90 ;
V_291 -> V_18 = V_2 ;
F_163 ( & V_291 -> V_291 , F_160 ) ;
V_291 -> V_292 = V_183 ;
V_291 -> V_293 = V_320 ;
V_291 -> V_169 . V_169 = V_321 ;
F_154 ( V_296 , & V_291 -> V_291 ) ;
return 0 ;
}
static int F_167 ( struct V_322 * V_323 , int V_289 )
{
int V_324 ;
struct V_322 * V_325 ;
V_324 = F_168 ( V_289 ) ;
V_325 = V_323 -> V_326 & V_327 ?
F_169 ( V_323 ) : V_323 ;
if ( V_325 -> V_328 )
return F_170 ( V_325 , V_324 ) ;
#if F_171 ( V_329 )
if ( V_323 -> V_326 & V_327 )
return ( F_172 ( V_323 , V_324 ) &
V_330 ) >> V_331 ;
#endif
return 0 ;
}
static int F_173 ( struct V_1 * V_2 )
{
struct V_231 * V_20 = & V_2 -> V_18 . V_20 ;
struct V_332 * V_21 = & V_20 -> V_21 ;
struct V_290 * V_291 ;
int V_6 ;
struct V_322 * V_323 = NULL ;
V_291 = F_47 ( sizeof *V_291 , V_89 ) ;
if ( ! V_291 )
return - V_90 ;
V_291 -> V_18 = V_2 ;
F_163 ( & V_291 -> V_291 , F_160 ) ;
V_20 -> V_191 = F_47 ( sizeof * V_20 -> V_191 , V_89 ) ;
if ( ! V_20 -> V_191 ) {
V_6 = - V_90 ;
goto V_245;
}
V_20 -> V_233 = 1 ;
if ( V_21 -> V_22 . V_333 )
V_323 = F_174 ( & V_334 , V_21 -> V_22 . V_333 ) ;
if ( ! V_323 ) {
V_6 = - V_61 ;
goto V_247;
}
V_20 -> V_191 -> V_335 = F_175 ( V_323 ) ;
memcpy ( V_20 -> V_191 -> V_336 , V_21 -> V_22 . V_337 , V_338 ) ;
memcpy ( V_20 -> V_191 -> V_123 , V_323 -> V_22 , V_323 -> V_339 ) ;
F_36 ( (struct V_33 * ) & V_2 -> V_18 . V_20 . V_21 . V_34 ,
& V_20 -> V_191 -> V_73 ) ;
F_36 ( (struct V_33 * ) & V_2 -> V_18 . V_20 . V_21 . V_35 ,
& V_20 -> V_191 -> V_74 ) ;
V_20 -> V_191 -> V_340 = 1 ;
V_20 -> V_191 -> V_301 = 1 ;
V_20 -> V_191 -> V_75 = F_158 ( 0xffff ) ;
V_20 -> V_191 -> V_341 = V_342 ;
V_20 -> V_191 -> V_343 = F_167 ( V_323 , V_2 -> V_289 ) ;
V_20 -> V_191 -> V_344 = F_176 ( V_323 -> V_344 ) ;
V_20 -> V_191 -> V_345 = V_342 ;
V_20 -> V_191 -> V_346 = F_177 ( V_323 ) ;
F_178 ( V_323 ) ;
V_20 -> V_191 -> V_347 = V_342 ;
V_20 -> V_191 -> V_348 = V_349 ;
if ( ! V_20 -> V_191 -> V_344 ) {
V_6 = - V_40 ;
goto V_247;
}
V_291 -> V_292 = V_183 ;
V_291 -> V_293 = V_320 ;
V_291 -> V_169 . V_169 = V_321 ;
V_291 -> V_169 . V_210 = 0 ;
F_154 ( V_296 , & V_291 -> V_291 ) ;
return 0 ;
V_247:
F_17 ( V_20 -> V_191 ) ;
V_20 -> V_191 = NULL ;
V_245:
F_17 ( V_291 ) ;
return V_6 ;
}
int F_179 ( struct V_83 * V_18 , int V_297 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_4 ( V_2 , V_294 , V_183 ) )
return - V_40 ;
F_9 ( & V_2 -> V_17 ) ;
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
switch ( F_38 ( V_18 -> V_19 , V_18 -> V_47 ) ) {
case V_66 :
V_6 = F_162 ( V_2 , V_297 ) ;
break;
case V_67 :
V_6 = F_173 ( V_2 ) ;
break;
default:
V_6 = - V_139 ;
}
break;
case V_137 :
V_6 = F_166 ( V_2 , V_297 ) ;
break;
default:
V_6 = - V_139 ;
break;
}
if ( V_6 )
goto V_115;
return 0 ;
V_115:
F_4 ( V_2 , V_183 , V_294 ) ;
F_44 ( V_2 ) ;
return V_6 ;
}
static void F_180 ( struct V_33 * V_21 )
{
switch ( V_21 -> V_56 ) {
case V_140 :
( (struct V_141 * ) V_21 ) -> V_142 . V_143 = F_136 ( V_350 ) ;
break;
case V_144 :
F_181 ( & ( (struct V_145 * ) V_21 ) -> V_146 ,
0 , 0 , 0 , F_136 ( 1 ) ) ;
break;
default:
F_182 ( & ( (struct V_48 * ) V_21 ) -> V_54 ,
0 , 0 , 0 , F_136 ( 1 ) ) ;
break;
}
}
static int F_183 ( struct V_1 * V_2 )
{
struct V_15 * V_16 , * V_72 ;
struct V_351 V_352 ;
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
if ( ! F_184 ( V_72 -> V_19 , V_77 , & V_352 ) &&
V_352 . V_8 == V_353 ) {
V_16 = V_72 ;
goto V_354;
}
}
}
if ( ! V_16 ) {
V_6 = - V_61 ;
goto V_70;
}
V_77 = 1 ;
V_354:
V_6 = F_43 ( V_16 -> V_19 , V_77 , 0 , & V_59 ) ;
if ( V_6 )
goto V_70;
V_6 = F_185 ( V_16 -> V_19 , V_77 , 0 , & V_75 ) ;
if ( V_6 )
goto V_70;
V_2 -> V_18 . V_20 . V_21 . V_22 . V_51 =
( F_38 ( V_16 -> V_19 , V_77 ) == V_66 ) ?
V_52 : V_355 ;
F_30 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , & V_59 ) ;
F_31 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , V_75 ) ;
V_2 -> V_18 . V_47 = V_77 ;
F_8 ( V_2 , V_16 ) ;
F_180 ( F_22 ( V_2 ) ) ;
V_70:
F_21 ( & V_7 ) ;
return V_6 ;
}
static void F_186 ( int V_210 , struct V_33 * V_34 ,
struct V_50 * V_22 , void * V_85 )
{
struct V_1 * V_2 = V_85 ;
struct V_194 V_169 ;
memset ( & V_169 , 0 , sizeof V_169 ) ;
F_19 ( & V_2 -> V_82 ) ;
if ( ! F_4 ( V_2 , V_182 ,
V_294 ) )
goto V_70;
memcpy ( F_22 ( V_2 ) , V_34 , F_138 ( V_34 ) ) ;
if ( ! V_210 && ! V_2 -> V_16 )
V_210 = F_35 ( V_2 , NULL ) ;
if ( V_210 ) {
if ( ! F_4 ( V_2 , V_294 ,
V_285 ) )
goto V_70;
V_169 . V_169 = V_356 ;
V_169 . V_210 = V_210 ;
} else
V_169 . V_169 = V_357 ;
if ( V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_169 ) ) {
F_5 ( V_2 , V_189 ) ;
F_21 ( & V_2 -> V_82 ) ;
F_44 ( V_2 ) ;
F_105 ( & V_2 -> V_18 ) ;
return;
}
V_70:
F_21 ( & V_2 -> V_82 ) ;
F_44 ( V_2 ) ;
}
static int F_187 ( struct V_1 * V_2 )
{
struct V_290 * V_291 ;
union V_53 V_59 ;
int V_6 ;
V_291 = F_47 ( sizeof *V_291 , V_89 ) ;
if ( ! V_291 )
return - V_90 ;
if ( ! V_2 -> V_16 ) {
V_6 = F_183 ( V_2 ) ;
if ( V_6 )
goto V_115;
}
F_156 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , & V_59 ) ;
F_127 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , & V_59 ) ;
V_291 -> V_18 = V_2 ;
F_163 ( & V_291 -> V_291 , F_160 ) ;
V_291 -> V_292 = V_182 ;
V_291 -> V_293 = V_294 ;
V_291 -> V_169 . V_169 = V_357 ;
F_154 ( V_296 , & V_291 -> V_291 ) ;
return 0 ;
V_115:
F_17 ( V_291 ) ;
return V_6 ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_290 * V_291 ;
int V_6 ;
V_291 = F_47 ( sizeof *V_291 , V_89 ) ;
if ( ! V_291 )
return - V_90 ;
if ( ! V_2 -> V_16 ) {
V_6 = F_41 ( V_2 ) ;
if ( V_6 )
goto V_115;
}
F_127 ( & V_2 -> V_18 . V_20 . V_21 . V_22 , (union V_53 * )
& ( ( (struct V_48 * ) & V_2 -> V_18 . V_20 . V_21 . V_35 ) -> V_54 ) ) ;
V_291 -> V_18 = V_2 ;
F_163 ( & V_291 -> V_291 , F_160 ) ;
V_291 -> V_292 = V_182 ;
V_291 -> V_293 = V_294 ;
V_291 -> V_169 . V_169 = V_357 ;
F_154 ( V_296 , & V_291 -> V_291 ) ;
return 0 ;
V_115:
F_17 ( V_291 ) ;
return V_6 ;
}
static int F_189 ( struct V_83 * V_18 , struct V_33 * V_34 ,
struct V_33 * V_35 )
{
if ( ! V_34 || ! V_34 -> V_56 ) {
V_34 = (struct V_33 * ) & V_18 -> V_20 . V_21 . V_34 ;
V_34 -> V_56 = V_35 -> V_56 ;
if ( V_35 -> V_56 == V_144 ) {
( (struct V_145 * ) V_34 ) -> V_358 =
( (struct V_145 * ) V_35 ) -> V_358 ;
} else if ( V_35 -> V_56 == V_57 ) {
( (struct V_48 * ) V_34 ) -> V_55 =
( (struct V_48 * ) V_35 ) -> V_55 ;
}
}
return F_190 ( V_18 , V_34 ) ;
}
int F_191 ( struct V_83 * V_18 , struct V_33 * V_34 ,
struct V_33 * V_35 , int V_297 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( V_2 -> V_8 == V_93 ) {
V_6 = F_189 ( V_18 , V_34 , V_35 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_24 ( V_2 ) != V_35 -> V_56 )
return - V_40 ;
if ( ! F_4 ( V_2 , V_285 , V_182 ) )
return - V_40 ;
F_9 ( & V_2 -> V_17 ) ;
memcpy ( F_23 ( V_2 ) , V_35 , F_138 ( V_35 ) ) ;
if ( F_83 ( V_35 ) ) {
V_6 = F_187 ( V_2 ) ;
} else {
if ( V_35 -> V_56 == V_57 ) {
V_6 = F_188 ( V_2 ) ;
} else {
V_6 = F_192 ( & V_359 , F_22 ( V_2 ) ,
V_35 , & V_18 -> V_20 . V_21 . V_22 ,
V_297 , F_186 , V_2 ) ;
}
}
if ( V_6 )
goto V_115;
return 0 ;
V_115:
F_4 ( V_2 , V_182 , V_285 ) ;
F_44 ( V_2 ) ;
return V_6 ;
}
int F_193 ( struct V_83 * V_18 , int V_360 )
{
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
if ( V_360 || V_2 -> V_8 == V_93 ) {
V_2 -> V_361 = V_360 ;
V_6 = 0 ;
} else {
V_6 = - V_40 ;
}
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
int F_194 ( struct V_83 * V_18 , int V_283 )
{
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
if ( V_2 -> V_8 == V_93 || V_2 -> V_8 == V_285 ) {
V_2 -> V_362 |= ( 1 << V_363 ) ;
V_2 -> V_283 = V_283 ;
V_6 = 0 ;
} else {
V_6 = - V_40 ;
}
F_3 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
static void F_195 ( struct V_185 * V_186 ,
struct V_1 * V_2 )
{
struct V_33 * V_21 ;
struct V_48 * V_49 ;
V_251 V_364 , V_260 ;
T_5 V_62 ;
V_21 = F_22 ( V_2 ) ;
V_62 = F_88 ( V_186 -> V_62 ) ;
switch ( V_21 -> V_56 ) {
case V_140 :
( (struct V_141 * ) V_21 ) -> V_149 = V_62 ;
break;
case V_144 :
( (struct V_145 * ) V_21 ) -> V_150 = V_62 ;
break;
case V_57 :
V_49 = (struct V_48 * ) V_21 ;
V_364 = F_89 ( V_49 -> V_151 ) ;
V_260 = F_89 ( V_49 -> V_152 ) ;
V_49 -> V_151 = F_92 ( ( V_364 & V_260 ) | ( V_251 ) F_32 ( V_62 ) ) ;
V_49 -> V_152 = F_92 ( ~ 0ULL ) ;
break;
}
V_2 -> V_186 = V_186 ;
F_196 ( & V_2 -> V_187 , & V_186 -> V_188 ) ;
}
static int F_197 ( struct V_365 * V_41 , struct V_1 * V_2 ,
unsigned short V_366 )
{
struct V_185 * V_186 ;
int V_6 ;
V_186 = F_47 ( sizeof *V_186 , V_89 ) ;
if ( ! V_186 )
return - V_90 ;
V_6 = F_198 ( V_41 , V_186 , V_366 , V_366 + 1 , V_89 ) ;
if ( V_6 < 0 )
goto V_115;
V_186 -> V_41 = V_41 ;
V_186 -> V_62 = ( unsigned short ) V_6 ;
F_195 ( V_186 , V_2 ) ;
return 0 ;
V_115:
F_17 ( V_186 ) ;
return V_6 == - V_367 ? - V_368 : V_6 ;
}
static int F_199 ( struct V_365 * V_41 , struct V_1 * V_2 )
{
static unsigned int V_369 ;
int V_370 , V_371 , V_372 ;
unsigned int V_373 ;
F_200 ( & V_334 , & V_370 , & V_371 ) ;
V_372 = ( V_371 - V_370 ) + 1 ;
V_373 = F_201 () % V_372 + V_370 ;
V_374:
if ( V_369 != V_373 &&
! F_202 ( V_41 , ( unsigned short ) V_373 ) ) {
int V_6 = F_197 ( V_41 , V_2 , V_373 ) ;
if ( ! V_6 )
V_369 = V_373 ;
if ( V_6 != - V_368 )
return V_6 ;
}
if ( -- V_372 ) {
V_373 ++ ;
if ( ( V_373 < V_370 ) || ( V_373 > V_371 ) )
V_373 = V_370 ;
goto V_374;
}
return - V_368 ;
}
static int F_203 ( struct V_185 * V_186 ,
struct V_1 * V_2 , T_9 V_361 )
{
struct V_1 * V_375 ;
struct V_33 * V_21 , * V_376 ;
V_21 = F_22 ( V_2 ) ;
F_204 (cur_id, &bind_list->owners, node) {
if ( V_2 == V_375 )
continue;
if ( ( V_375 -> V_8 != V_184 ) && V_361 &&
V_375 -> V_361 )
continue;
V_376 = F_22 ( V_375 ) ;
if ( V_2 -> V_283 && V_375 -> V_283 &&
( V_21 -> V_56 != V_376 -> V_56 ) )
continue;
if ( F_83 ( V_21 ) || F_83 ( V_376 ) )
return - V_368 ;
if ( ! F_84 ( V_21 , V_376 ) )
return - V_377 ;
}
return 0 ;
}
static int F_205 ( struct V_365 * V_41 , struct V_1 * V_2 )
{
struct V_185 * V_186 ;
unsigned short V_366 ;
int V_6 ;
V_366 = F_32 ( F_87 ( F_22 ( V_2 ) ) ) ;
if ( V_366 < V_378 && ! F_206 ( V_379 ) )
return - V_380 ;
V_186 = F_202 ( V_41 , V_366 ) ;
if ( ! V_186 ) {
V_6 = F_197 ( V_41 , V_2 , V_366 ) ;
} else {
V_6 = F_203 ( V_186 , V_2 , V_2 -> V_361 ) ;
if ( ! V_6 )
F_195 ( V_186 , V_2 ) ;
}
return V_6 ;
}
static int F_207 ( struct V_1 * V_2 )
{
struct V_185 * V_186 = V_2 -> V_186 ;
int V_6 = 0 ;
F_19 ( & V_7 ) ;
if ( V_186 -> V_188 . V_381 -> V_181 )
V_6 = F_203 ( V_186 , V_2 , 0 ) ;
F_21 ( & V_7 ) ;
return V_6 ;
}
static struct V_365 * F_208 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_18 . V_41 ) {
case V_279 :
return & V_382 ;
case V_42 :
return & V_383 ;
case V_45 :
return & V_384 ;
case V_43 :
return & V_385 ;
default:
return NULL ;
}
}
static struct V_365 * F_209 ( struct V_1 * V_2 )
{
struct V_365 * V_41 = NULL ;
struct V_48 * V_49 ;
V_251 V_386 , V_260 , V_364 ;
V_49 = (struct V_48 * ) F_22 ( V_2 ) ;
V_260 = F_89 ( V_49 -> V_152 ) & V_387 ;
V_364 = F_89 ( V_49 -> V_151 ) & V_260 ;
if ( ( V_2 -> V_18 . V_41 == V_43 ) && ( V_364 == ( V_388 & V_260 ) ) ) {
V_386 = V_388 ;
V_41 = & V_385 ;
} else if ( ( ( V_2 -> V_18 . V_41 == V_43 ) || ( V_2 -> V_18 . V_41 == V_279 ) ) &&
( V_364 == ( V_389 & V_260 ) ) ) {
V_386 = V_389 ;
V_41 = & V_382 ;
} else if ( ( ( V_2 -> V_18 . V_41 == V_43 ) || ( V_2 -> V_18 . V_41 == V_42 ) ) &&
( V_364 == ( V_390 & V_260 ) ) ) {
V_386 = V_390 ;
V_41 = & V_383 ;
}
if ( V_41 ) {
V_49 -> V_151 = F_92 ( V_386 | F_32 ( F_87 ( (struct V_33 * ) V_49 ) ) ) ;
V_49 -> V_152 = F_92 ( V_387 |
F_89 ( V_49 -> V_152 ) ) ;
}
return V_41 ;
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_365 * V_41 ;
int V_6 ;
if ( F_24 ( V_2 ) != V_57 )
V_41 = F_208 ( V_2 ) ;
else
V_41 = F_209 ( V_2 ) ;
if ( ! V_41 )
return - V_391 ;
F_19 ( & V_7 ) ;
if ( F_90 ( F_22 ( V_2 ) ) )
V_6 = F_199 ( V_41 , V_2 ) ;
else
V_6 = F_205 ( V_41 , V_2 ) ;
F_21 ( & V_7 ) ;
return V_6 ;
}
static int F_211 ( struct V_50 * V_22 ,
struct V_33 * V_21 )
{
#if F_171 ( V_392 )
struct V_145 * V_299 ;
if ( V_21 -> V_56 != V_144 )
return 0 ;
V_299 = (struct V_145 * ) V_21 ;
if ( ! ( F_212 ( & V_299 -> V_146 ) & V_393 ) )
return 0 ;
if ( ! V_299 -> V_358 )
return - V_40 ;
V_22 -> V_333 = V_299 -> V_358 ;
#endif
return 0 ;
}
int F_150 ( struct V_83 * V_18 , int V_284 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( V_2 -> V_8 == V_93 ) {
V_18 -> V_20 . V_21 . V_34 . V_36 = V_140 ;
V_6 = F_190 ( V_18 , F_22 ( V_2 ) ) ;
if ( V_6 )
return V_6 ;
}
if ( ! F_4 ( V_2 , V_285 , V_184 ) )
return - V_40 ;
if ( V_2 -> V_361 ) {
V_6 = F_207 ( V_2 ) ;
if ( V_6 )
goto V_115;
}
V_2 -> V_284 = V_284 ;
if ( V_18 -> V_19 ) {
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
V_6 = F_142 ( V_2 ) ;
if ( V_6 )
goto V_115;
break;
case V_137 :
V_6 = F_145 ( V_2 , V_284 ) ;
if ( V_6 )
goto V_115;
break;
default:
V_6 = - V_139 ;
goto V_115;
}
} else
F_151 ( V_2 ) ;
return 0 ;
V_115:
V_2 -> V_284 = 0 ;
F_4 ( V_2 , V_184 , V_285 ) ;
return V_6 ;
}
int F_190 ( struct V_83 * V_18 , struct V_33 * V_21 )
{
struct V_1 * V_2 ;
int V_6 ;
if ( V_21 -> V_56 != V_140 && V_21 -> V_56 != V_144 &&
V_21 -> V_56 != V_57 )
return - V_394 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_4 ( V_2 , V_93 , V_285 ) )
return - V_40 ;
V_6 = F_211 ( & V_18 -> V_20 . V_21 . V_22 , V_21 ) ;
if ( V_6 )
goto V_245;
memcpy ( F_22 ( V_2 ) , V_21 , F_138 ( V_21 ) ) ;
if ( ! F_83 ( V_21 ) ) {
V_6 = F_33 ( V_21 , & V_18 -> V_20 . V_21 . V_22 ) ;
if ( V_6 )
goto V_245;
V_6 = F_35 ( V_2 , NULL ) ;
if ( V_6 )
goto V_245;
}
if ( ! ( V_2 -> V_362 & ( 1 << V_363 ) ) ) {
if ( V_21 -> V_56 == V_140 )
V_2 -> V_283 = 1 ;
#if F_171 ( V_392 )
else if ( V_21 -> V_56 == V_144 )
V_2 -> V_283 = V_334 . V_395 . V_396 . V_397 ;
#endif
}
V_6 = F_210 ( V_2 ) ;
if ( V_6 )
goto V_247;
return 0 ;
V_247:
if ( V_2 -> V_16 )
F_18 ( V_2 ) ;
V_245:
F_4 ( V_2 , V_285 , V_93 ) ;
return V_6 ;
}
static int F_213 ( void * V_12 , struct V_1 * V_2 )
{
struct V_11 * V_11 ;
V_11 = V_12 ;
V_11 -> V_176 = V_177 ;
if ( F_24 ( V_2 ) == V_140 ) {
struct V_141 * V_398 , * V_399 ;
V_398 = (struct V_141 * ) F_22 ( V_2 ) ;
V_399 = (struct V_141 * ) F_23 ( V_2 ) ;
F_7 ( V_11 , 4 ) ;
V_11 -> V_34 . V_163 . V_21 = V_398 -> V_142 . V_143 ;
V_11 -> V_35 . V_163 . V_21 = V_399 -> V_142 . V_143 ;
V_11 -> V_62 = V_398 -> V_149 ;
} else if ( F_24 ( V_2 ) == V_144 ) {
struct V_145 * V_400 , * V_401 ;
V_400 = (struct V_145 * ) F_22 ( V_2 ) ;
V_401 = (struct V_145 * ) F_23 ( V_2 ) ;
F_7 ( V_11 , 6 ) ;
V_11 -> V_34 . V_165 = V_400 -> V_146 ;
V_11 -> V_35 . V_165 = V_401 -> V_146 ;
V_11 -> V_62 = V_400 -> V_150 ;
}
return 0 ;
}
static int F_214 ( struct V_203 * V_135 ,
struct V_167 * V_168 )
{
struct V_1 * V_2 = V_135 -> V_85 ;
struct V_194 V_169 ;
struct V_402 * V_403 = & V_168 -> V_171 . V_404 ;
int V_6 = 0 ;
if ( F_45 ( V_2 , V_205 ) )
return 0 ;
memset ( & V_169 , 0 , sizeof V_169 ) ;
switch ( V_168 -> V_169 ) {
case V_405 :
V_169 . V_169 = V_209 ;
V_169 . V_210 = - V_211 ;
break;
case V_406 :
V_169 . V_171 . V_243 . V_175 = V_168 -> V_175 ;
V_169 . V_171 . V_243 . V_198 = V_407 ;
if ( V_403 -> V_210 != V_408 ) {
V_169 . V_169 = V_209 ;
V_169 . V_210 = V_168 -> V_171 . V_404 . V_210 ;
break;
}
V_6 = F_25 ( V_2 , V_403 -> V_37 ) ;
if ( V_6 ) {
V_169 . V_169 = V_356 ;
V_169 . V_210 = V_6 ;
break;
}
F_215 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ,
V_2 -> V_18 . V_20 . V_191 ,
& V_169 . V_171 . V_243 . V_120 ) ;
V_169 . V_171 . V_243 . V_116 = V_403 -> V_409 ;
V_169 . V_171 . V_243 . V_37 = V_403 -> V_37 ;
V_169 . V_169 = V_214 ;
V_169 . V_210 = 0 ;
break;
default:
F_123 ( V_230 L_1 ,
V_168 -> V_169 ) ;
goto V_70;
}
V_6 = V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_169 ) ;
if ( V_6 ) {
V_2 -> V_135 . V_32 = NULL ;
F_5 ( V_2 , V_189 ) ;
F_21 ( & V_2 -> V_82 ) ;
F_105 ( & V_2 -> V_18 ) ;
return V_6 ;
}
V_70:
F_21 ( & V_2 -> V_82 ) ;
return V_6 ;
}
static int F_216 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_410 V_411 ;
struct V_203 * V_18 ;
void * V_175 ;
int V_237 , V_6 ;
memset ( & V_411 , 0 , sizeof V_411 ) ;
V_237 = F_98 ( V_2 ) ;
V_411 . V_198 = V_237 + V_119 -> V_198 ;
if ( V_411 . V_198 < V_119 -> V_198 )
return - V_40 ;
if ( V_411 . V_198 ) {
V_175 = F_47 ( V_411 . V_198 , V_412 ) ;
if ( ! V_175 )
return - V_90 ;
} else {
V_175 = NULL ;
}
if ( V_119 -> V_175 && V_119 -> V_198 )
memcpy ( V_175 + V_237 , V_119 -> V_175 ,
V_119 -> V_198 ) ;
if ( V_175 ) {
V_6 = F_213 ( V_175 , V_2 ) ;
if ( V_6 )
goto V_70;
V_411 . V_175 = V_175 ;
}
V_18 = F_143 ( V_2 -> V_18 . V_19 , F_214 ,
V_2 ) ;
if ( F_62 ( V_18 ) ) {
V_6 = F_63 ( V_18 ) ;
goto V_70;
}
V_2 -> V_135 . V_32 = V_18 ;
V_411 . V_155 = V_2 -> V_18 . V_20 . V_191 ;
V_411 . V_302 = F_134 ( & V_2 -> V_18 , F_23 ( V_2 ) ) ;
V_411 . V_297 = 1 << ( V_413 - 8 ) ;
V_411 . V_414 = V_415 ;
V_6 = F_217 ( V_2 -> V_135 . V_32 , & V_411 ) ;
if ( V_6 ) {
F_115 ( V_2 -> V_135 . V_32 ) ;
V_2 -> V_135 . V_32 = NULL ;
}
V_70:
F_17 ( V_175 ) ;
return V_6 ;
}
static int F_218 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_416 V_411 ;
struct V_231 * V_20 ;
void * V_175 ;
struct V_203 * V_18 ;
int V_237 , V_6 ;
memset ( & V_411 , 0 , sizeof V_411 ) ;
V_237 = F_98 ( V_2 ) ;
V_411 . V_198 = V_237 + V_119 -> V_198 ;
if ( V_411 . V_198 < V_119 -> V_198 )
return - V_40 ;
if ( V_411 . V_198 ) {
V_175 = F_47 ( V_411 . V_198 , V_412 ) ;
if ( ! V_175 )
return - V_90 ;
} else {
V_175 = NULL ;
}
if ( V_119 -> V_175 && V_119 -> V_198 )
memcpy ( V_175 + V_237 , V_119 -> V_175 ,
V_119 -> V_198 ) ;
V_18 = F_143 ( V_2 -> V_18 . V_19 , F_122 , V_2 ) ;
if ( F_62 ( V_18 ) ) {
V_6 = F_63 ( V_18 ) ;
goto V_70;
}
V_2 -> V_135 . V_32 = V_18 ;
V_20 = & V_2 -> V_18 . V_20 ;
if ( V_175 ) {
V_6 = F_213 ( V_175 , V_2 ) ;
if ( V_6 )
goto V_70;
V_411 . V_175 = V_175 ;
}
V_411 . V_173 = & V_20 -> V_191 [ 0 ] ;
if ( V_20 -> V_233 == 2 )
V_411 . V_234 = & V_20 -> V_191 [ 1 ] ;
V_411 . V_302 = F_134 ( & V_2 -> V_18 , F_23 ( V_2 ) ) ;
V_411 . V_116 = V_2 -> V_116 ;
V_411 . V_88 = V_2 -> V_18 . V_88 ;
V_411 . V_417 = V_2 -> V_97 ;
V_411 . V_125 = V_119 -> V_125 ;
V_411 . V_127 = V_119 -> V_127 ;
V_411 . V_200 = V_119 -> V_200 ;
V_411 . V_239 = F_219 ( T_1 , 7 , V_119 -> V_239 ) ;
V_411 . V_201 = F_219 ( T_1 , 7 , V_119 -> V_201 ) ;
V_411 . V_418 = V_413 ;
V_411 . V_419 = V_413 ;
V_411 . V_414 = V_415 ;
V_411 . V_117 = V_2 -> V_117 ? 1 : 0 ;
V_6 = F_220 ( V_2 -> V_135 . V_32 , & V_411 ) ;
V_70:
if ( V_6 && ! F_62 ( V_18 ) ) {
F_115 ( V_18 ) ;
V_2 -> V_135 . V_32 = NULL ;
}
F_17 ( V_175 ) ;
return V_6 ;
}
static int F_221 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_261 * V_135 ;
int V_6 ;
struct V_420 V_421 ;
V_135 = F_146 ( V_2 -> V_18 . V_19 , F_137 , V_2 ) ;
if ( F_62 ( V_135 ) )
return F_63 ( V_135 ) ;
V_2 -> V_135 . V_138 = V_135 ;
memcpy ( & V_135 -> V_266 , F_22 ( V_2 ) ,
F_138 ( F_22 ( V_2 ) ) ) ;
memcpy ( & V_135 -> V_268 , F_23 ( V_2 ) ,
F_138 ( F_23 ( V_2 ) ) ) ;
V_6 = F_66 ( V_2 , V_119 ) ;
if ( V_6 )
goto V_70;
if ( V_119 ) {
V_421 . V_272 = V_119 -> V_127 ;
V_421 . V_271 = V_119 -> V_125 ;
V_421 . V_175 = V_119 -> V_175 ;
V_421 . V_198 = V_119 -> V_198 ;
V_421 . V_409 = V_2 -> V_18 . V_99 ? V_2 -> V_116 : V_119 -> V_116 ;
} else {
memset ( & V_421 , 0 , sizeof V_421 ) ;
V_421 . V_409 = V_2 -> V_116 ;
}
V_6 = F_222 ( V_135 , & V_421 ) ;
V_70:
if ( V_6 ) {
F_116 ( V_135 ) ;
V_2 -> V_135 . V_138 = NULL ;
}
return V_6 ;
}
int F_223 ( struct V_83 * V_18 , struct V_118 * V_119 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_4 ( V_2 , V_320 , V_205 ) )
return - V_40 ;
if ( ! V_18 -> V_99 ) {
V_2 -> V_116 = V_119 -> V_116 ;
V_2 -> V_117 = V_119 -> V_117 ;
}
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
if ( V_18 -> V_88 == V_114 )
V_6 = F_216 ( V_2 , V_119 ) ;
else
V_6 = F_218 ( V_2 , V_119 ) ;
break;
case V_137 :
V_6 = F_221 ( V_2 , V_119 ) ;
break;
default:
V_6 = - V_139 ;
break;
}
if ( V_6 )
goto V_115;
return 0 ;
V_115:
F_4 ( V_2 , V_205 , V_320 ) ;
return V_6 ;
}
static int F_224 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_422 V_403 ;
int V_6 ;
V_6 = F_66 ( V_2 , V_119 ) ;
if ( V_6 )
goto V_70;
V_6 = F_69 ( V_2 , V_119 ) ;
if ( V_6 )
goto V_70;
memset ( & V_403 , 0 , sizeof V_403 ) ;
V_403 . V_116 = V_2 -> V_116 ;
V_403 . V_417 = V_2 -> V_97 ;
V_403 . V_175 = V_119 -> V_175 ;
V_403 . V_198 = V_119 -> V_198 ;
V_403 . V_125 = V_119 -> V_125 ;
V_403 . V_127 = V_119 -> V_127 ;
V_403 . V_423 = 0 ;
V_403 . V_200 = V_119 -> V_200 ;
V_403 . V_201 = F_219 ( T_1 , 7 , V_119 -> V_201 ) ;
V_403 . V_117 = V_2 -> V_117 ? 1 : 0 ;
V_6 = F_225 ( V_2 -> V_135 . V_32 , & V_403 ) ;
V_70:
return V_6 ;
}
static int F_226 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_420 V_421 ;
int V_6 ;
V_6 = F_66 ( V_2 , V_119 ) ;
if ( V_6 )
return V_6 ;
V_421 . V_272 = V_119 -> V_127 ;
V_421 . V_271 = V_119 -> V_125 ;
V_421 . V_175 = V_119 -> V_175 ;
V_421 . V_198 = V_119 -> V_198 ;
if ( V_2 -> V_18 . V_99 ) {
V_421 . V_409 = V_2 -> V_116 ;
} else
V_421 . V_409 = V_119 -> V_116 ;
return F_227 ( V_2 -> V_135 . V_138 , & V_421 ) ;
}
static int F_228 ( struct V_1 * V_2 ,
enum V_424 V_210 , T_2 V_37 ,
const void * V_175 , int V_198 )
{
struct V_425 V_403 ;
int V_6 ;
memset ( & V_403 , 0 , sizeof V_403 ) ;
V_403 . V_210 = V_210 ;
if ( V_210 == V_408 ) {
V_6 = F_25 ( V_2 , V_37 ) ;
if ( V_6 )
return V_6 ;
V_403 . V_116 = V_2 -> V_116 ;
V_403 . V_37 = V_2 -> V_37 ;
}
V_403 . V_175 = V_175 ;
V_403 . V_198 = V_198 ;
return F_229 ( V_2 -> V_135 . V_32 , & V_403 ) ;
}
int F_230 ( struct V_83 * V_18 , struct V_118 * V_119 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
V_2 -> V_91 = F_49 ( V_92 ) ;
if ( ! F_1 ( V_2 , V_205 ) )
return - V_40 ;
if ( ! V_18 -> V_99 && V_119 ) {
V_2 -> V_116 = V_119 -> V_116 ;
V_2 -> V_117 = V_119 -> V_117 ;
}
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
if ( V_18 -> V_88 == V_114 ) {
if ( V_119 )
V_6 = F_228 ( V_2 , V_408 ,
V_119 -> V_37 ,
V_119 -> V_175 ,
V_119 -> V_198 ) ;
else
V_6 = F_228 ( V_2 , V_408 ,
0 , NULL , 0 ) ;
} else {
if ( V_119 )
V_6 = F_224 ( V_2 , V_119 ) ;
else
V_6 = F_118 ( V_2 ) ;
}
break;
case V_137 :
V_6 = F_226 ( V_2 , V_119 ) ;
break;
default:
V_6 = - V_139 ;
break;
}
if ( V_6 )
goto V_192;
return 0 ;
V_192:
F_70 ( V_2 ) ;
F_231 ( V_18 , NULL , 0 ) ;
return V_6 ;
}
int F_232 ( struct V_83 * V_18 , enum V_426 V_169 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! V_2 -> V_135 . V_32 )
return - V_40 ;
switch ( V_18 -> V_19 -> V_24 ) {
case V_427 :
V_6 = F_233 ( V_2 -> V_135 . V_32 , V_169 ) ;
break;
default:
V_6 = 0 ;
break;
}
return V_6 ;
}
int F_231 ( struct V_83 * V_18 , const void * V_175 ,
T_1 V_198 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! V_2 -> V_135 . V_32 )
return - V_40 ;
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
if ( V_18 -> V_88 == V_114 )
V_6 = F_228 ( V_2 , V_428 , 0 ,
V_175 , V_198 ) ;
else
V_6 = F_120 ( V_2 -> V_135 . V_32 ,
V_193 , NULL ,
0 , V_175 , V_198 ) ;
break;
case V_137 :
V_6 = F_234 ( V_2 -> V_135 . V_138 ,
V_175 , V_198 ) ;
break;
default:
V_6 = - V_139 ;
break;
}
return V_6 ;
}
int F_235 ( struct V_83 * V_18 )
{
struct V_1 * V_2 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! V_2 -> V_135 . V_32 )
return - V_40 ;
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
V_6 = F_70 ( V_2 ) ;
if ( V_6 )
goto V_70;
if ( F_236 ( V_2 -> V_135 . V_32 , NULL , 0 ) )
F_237 ( V_2 -> V_135 . V_32 , NULL , 0 ) ;
break;
case V_137 :
V_6 = F_238 ( V_2 -> V_135 . V_138 , 0 ) ;
break;
default:
V_6 = - V_40 ;
break;
}
V_70:
return V_6 ;
}
static int F_239 ( int V_210 , struct V_429 * V_31 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = V_31 -> V_85 ;
struct V_194 V_169 ;
int V_6 ;
V_2 = V_29 -> V_2 ;
if ( F_45 ( V_2 , V_285 ) &&
F_45 ( V_2 , V_294 ) )
return 0 ;
if ( ! V_210 )
V_210 = F_25 ( V_2 , F_28 ( V_31 -> V_39 . V_37 ) ) ;
F_19 ( & V_2 -> V_94 ) ;
if ( ! V_210 && V_2 -> V_18 . V_99 )
V_210 = F_240 ( V_2 -> V_18 . V_99 , & V_31 -> V_39 . V_46 ,
F_126 ( V_31 -> V_39 . V_430 ) ) ;
F_21 ( & V_2 -> V_94 ) ;
memset ( & V_169 , 0 , sizeof V_169 ) ;
V_169 . V_210 = V_210 ;
V_169 . V_171 . V_243 . V_175 = V_29 -> V_85 ;
if ( ! V_210 ) {
V_169 . V_169 = V_431 ;
F_241 ( V_2 -> V_18 . V_19 ,
V_2 -> V_18 . V_47 , & V_31 -> V_39 ,
& V_169 . V_171 . V_243 . V_120 ) ;
V_169 . V_171 . V_243 . V_116 = 0xFFFFFF ;
V_169 . V_171 . V_243 . V_37 = F_28 ( V_31 -> V_39 . V_37 ) ;
} else
V_169 . V_169 = V_432 ;
V_6 = V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_169 ) ;
if ( V_6 ) {
F_5 ( V_2 , V_189 ) ;
F_21 ( & V_2 -> V_82 ) ;
F_105 ( & V_2 -> V_18 ) ;
return 0 ;
}
F_21 ( & V_2 -> V_82 ) ;
return 0 ;
}
static void F_242 ( struct V_1 * V_2 ,
struct V_33 * V_21 , union V_53 * V_46 )
{
unsigned char V_433 [ V_434 ] ;
struct V_50 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
struct V_141 * sin = (struct V_141 * ) V_21 ;
struct V_145 * V_299 = (struct V_145 * ) V_21 ;
if ( F_83 ( V_21 ) ) {
memset ( V_46 , 0 , sizeof *V_46 ) ;
} else if ( ( V_21 -> V_56 == V_144 ) &&
( ( F_28 ( V_299 -> V_146 . V_435 [ 0 ] ) & 0xFFF0FFFF ) ==
0xFF10A01B ) ) {
memcpy ( V_46 , & V_299 -> V_146 , sizeof *V_46 ) ;
} else if ( V_21 -> V_56 == V_57 ) {
memcpy ( V_46 , & ( (struct V_48 * ) V_21 ) -> V_54 , sizeof *V_46 ) ;
} else if ( ( V_21 -> V_56 == V_144 ) ) {
F_243 ( & V_299 -> V_146 , V_22 -> V_436 , V_433 ) ;
if ( V_2 -> V_18 . V_41 == V_42 )
V_433 [ 7 ] = 0x01 ;
* V_46 = * (union V_53 * ) ( V_433 + 4 ) ;
} else {
F_244 ( sin -> V_142 . V_143 , V_22 -> V_436 , V_433 ) ;
if ( V_2 -> V_18 . V_41 == V_42 )
V_433 [ 7 ] = 0x01 ;
* V_46 = * (union V_53 * ) ( V_433 + 4 ) ;
}
}
static int F_245 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_38 V_39 ;
struct V_50 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
T_8 V_298 ;
int V_6 ;
F_26 ( V_22 , & V_39 . V_46 ) ;
V_6 = F_27 ( V_2 -> V_18 . V_19 , V_2 -> V_18 . V_47 ,
& V_39 . V_46 , & V_39 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_25 ( V_2 , 0 ) ;
if ( V_6 )
return V_6 ;
F_242 ( V_2 , (struct V_33 * ) & V_29 -> V_21 , & V_39 . V_46 ) ;
V_39 . V_37 = F_246 ( V_2 -> V_37 ) ;
F_156 ( V_22 , & V_39 . V_437 ) ;
V_39 . V_75 = F_158 ( F_72 ( V_22 ) ) ;
V_39 . V_438 = 1 ;
V_298 = V_439 | V_440 |
V_441 | V_442 |
V_443 | V_444 |
V_445 |
V_446 ;
if ( V_2 -> V_18 . V_41 == V_45 )
V_298 |= V_447 |
V_448 |
V_449 |
V_450 |
V_451 ;
V_29 -> V_31 . V_32 = F_247 ( & V_314 , V_2 -> V_18 . V_19 ,
V_2 -> V_18 . V_47 , & V_39 ,
V_298 , V_89 ,
F_239 , V_29 ) ;
return F_248 ( V_29 -> V_31 . V_32 ) ;
}
static void F_249 ( struct V_315 * V_291 )
{
struct V_452 * V_453 = F_16 ( V_291 , struct V_452 , V_291 ) ;
struct V_28 * V_29 = V_453 -> V_29 ;
struct V_429 * V_454 = V_29 -> V_31 . V_32 ;
V_29 -> V_31 . V_32 -> V_85 = V_29 ;
F_239 ( 0 , V_454 ) ;
F_114 ( & V_29 -> V_30 , F_15 ) ;
F_17 ( V_453 ) ;
}
static void F_250 ( struct V_33 * V_21 , union V_53 * V_46 )
{
struct V_141 * sin = (struct V_141 * ) V_21 ;
struct V_145 * V_299 = (struct V_145 * ) V_21 ;
if ( F_83 ( V_21 ) ) {
memset ( V_46 , 0 , sizeof *V_46 ) ;
} else if ( V_21 -> V_56 == V_144 ) {
memcpy ( V_46 , & V_299 -> V_146 , sizeof *V_46 ) ;
} else {
V_46 -> V_455 [ 0 ] = 0xff ;
V_46 -> V_455 [ 1 ] = 0x0e ;
V_46 -> V_455 [ 2 ] = 0 ;
V_46 -> V_455 [ 3 ] = 0 ;
V_46 -> V_455 [ 4 ] = 0 ;
V_46 -> V_455 [ 5 ] = 0 ;
V_46 -> V_455 [ 6 ] = 0 ;
V_46 -> V_455 [ 7 ] = 0 ;
V_46 -> V_455 [ 8 ] = 0 ;
V_46 -> V_455 [ 9 ] = 0 ;
V_46 -> V_455 [ 10 ] = 0xff ;
V_46 -> V_455 [ 11 ] = 0xff ;
* ( T_7 * ) ( & V_46 -> V_455 [ 12 ] ) = sin -> V_142 . V_143 ;
}
}
static int F_251 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_452 * V_291 ;
struct V_50 * V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
int V_115 ;
struct V_33 * V_21 = (struct V_33 * ) & V_29 -> V_21 ;
struct V_322 * V_323 = NULL ;
if ( F_75 ( (struct V_33 * ) & V_29 -> V_21 ) )
return - V_40 ;
V_291 = F_47 ( sizeof *V_291 , V_89 ) ;
if ( ! V_291 )
return - V_90 ;
V_29 -> V_31 . V_32 = F_47 ( sizeof( struct V_429 ) , V_89 ) ;
if ( ! V_29 -> V_31 . V_32 ) {
V_115 = - V_90 ;
goto V_456;
}
F_250 ( V_21 , & V_29 -> V_31 . V_32 -> V_39 . V_46 ) ;
V_29 -> V_31 . V_32 -> V_39 . V_75 = F_158 ( 0xffff ) ;
if ( V_2 -> V_18 . V_41 == V_42 )
V_29 -> V_31 . V_32 -> V_39 . V_37 = F_246 ( V_44 ) ;
if ( V_22 -> V_333 )
V_323 = F_174 ( & V_334 , V_22 -> V_333 ) ;
if ( ! V_323 ) {
V_115 = - V_61 ;
goto V_457;
}
V_29 -> V_31 . V_32 -> V_39 . V_346 = F_177 ( V_323 ) ;
V_29 -> V_31 . V_32 -> V_39 . V_340 = 1 ;
V_29 -> V_31 . V_32 -> V_39 . V_344 = F_176 ( V_323 -> V_344 ) ;
F_178 ( V_323 ) ;
if ( ! V_29 -> V_31 . V_32 -> V_39 . V_344 ) {
V_115 = - V_40 ;
goto V_457;
}
F_36 ( (struct V_33 * ) & V_2 -> V_18 . V_20 . V_21 . V_34 ,
& V_29 -> V_31 . V_32 -> V_39 . V_437 ) ;
V_291 -> V_18 = V_2 ;
V_291 -> V_29 = V_29 ;
F_163 ( & V_291 -> V_291 , F_249 ) ;
F_252 ( & V_29 -> V_30 ) ;
F_154 ( V_296 , & V_291 -> V_291 ) ;
return 0 ;
V_457:
F_17 ( V_29 -> V_31 . V_32 ) ;
V_456:
F_17 ( V_291 ) ;
return V_115 ;
}
int F_253 ( struct V_83 * V_18 , struct V_33 * V_21 ,
void * V_85 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
int V_6 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
if ( ! F_1 ( V_2 , V_285 ) &&
! F_1 ( V_2 , V_294 ) )
return - V_40 ;
V_29 = F_125 ( sizeof *V_29 , V_89 ) ;
if ( ! V_29 )
return - V_90 ;
memcpy ( & V_29 -> V_21 , V_21 , F_138 ( V_21 ) ) ;
V_29 -> V_85 = V_85 ;
V_29 -> V_2 = V_2 ;
F_254 ( & V_2 -> V_7 ) ;
F_255 ( & V_29 -> V_25 , & V_2 -> V_96 ) ;
F_256 ( & V_2 -> V_7 ) ;
switch ( F_10 ( V_18 -> V_19 -> V_24 ) ) {
case V_69 :
switch ( F_38 ( V_18 -> V_19 , V_18 -> V_47 ) ) {
case V_66 :
V_6 = F_245 ( V_2 , V_29 ) ;
break;
case V_67 :
F_257 ( & V_29 -> V_30 ) ;
V_6 = F_251 ( V_2 , V_29 ) ;
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
F_258 ( & V_2 -> V_7 ) ;
F_20 ( & V_29 -> V_25 ) ;
F_259 ( & V_2 -> V_7 ) ;
F_17 ( V_29 ) ;
}
return V_6 ;
}
void F_260 ( struct V_83 * V_18 , struct V_33 * V_21 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
V_2 = F_16 ( V_18 , struct V_1 , V_18 ) ;
F_258 ( & V_2 -> V_7 ) ;
F_40 (mc, &id_priv->mc_list, list) {
if ( ! memcmp ( & V_29 -> V_21 , V_21 , F_138 ( V_21 ) ) ) {
F_20 ( & V_29 -> V_25 ) ;
F_259 ( & V_2 -> V_7 ) ;
if ( V_18 -> V_99 )
F_261 ( V_18 -> V_99 ,
& V_29 -> V_31 . V_32 -> V_39 . V_46 ,
F_126 ( V_29 -> V_31 . V_32 -> V_39 . V_430 ) ) ;
if ( F_10 ( V_2 -> V_16 -> V_19 -> V_24 ) == V_69 ) {
switch ( F_38 ( V_18 -> V_19 , V_18 -> V_47 ) ) {
case V_66 :
F_113 ( V_29 -> V_31 . V_32 ) ;
F_17 ( V_29 ) ;
break;
case V_67 :
F_114 ( & V_29 -> V_30 , F_15 ) ;
break;
default:
break;
}
}
return;
}
}
F_259 ( & V_2 -> V_7 ) ;
}
static int F_262 ( struct V_322 * V_323 , struct V_1 * V_2 )
{
struct V_50 * V_22 ;
struct V_318 * V_291 ;
V_22 = & V_2 -> V_18 . V_20 . V_21 . V_22 ;
if ( ( V_22 -> V_333 == V_323 -> V_458 ) &&
memcmp ( V_22 -> V_68 , V_323 -> V_22 , V_323 -> V_339 ) ) {
F_123 ( V_459 L_4 ,
V_323 -> V_287 , & V_2 -> V_18 ) ;
V_291 = F_47 ( sizeof *V_291 , V_89 ) ;
if ( ! V_291 )
return - V_90 ;
F_163 ( & V_291 -> V_291 , F_161 ) ;
V_291 -> V_18 = V_2 ;
V_291 -> V_169 . V_169 = V_460 ;
F_9 ( & V_2 -> V_17 ) ;
F_154 ( V_296 , & V_291 -> V_291 ) ;
}
return 0 ;
}
static int F_263 ( struct V_461 * V_462 , unsigned long V_169 ,
void * V_463 )
{
struct V_322 * V_323 = F_264 ( V_463 ) ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_6 = V_464 ;
if ( F_265 ( V_323 ) != & V_334 )
return V_464 ;
if ( V_169 != V_465 )
return V_464 ;
if ( ! ( V_323 -> V_5 & V_466 ) || ! ( V_323 -> V_326 & V_467 ) )
return V_464 ;
F_19 ( & V_7 ) ;
F_40 (cma_dev, &dev_list, list)
F_40 (id_priv, &cma_dev->id_list, list) {
V_6 = F_262 ( V_323 , V_2 ) ;
if ( V_6 )
goto V_70;
}
V_70:
F_21 ( & V_7 ) ;
return V_6 ;
}
static void F_266 ( struct V_468 * V_19 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
V_16 = F_125 ( sizeof *V_16 , V_89 ) ;
if ( ! V_16 )
return;
V_16 -> V_19 = V_19 ;
F_52 ( & V_16 -> V_4 ) ;
F_53 ( & V_16 -> V_17 , 1 ) ;
F_54 ( & V_16 -> V_26 ) ;
F_267 ( V_19 , & V_469 , V_16 ) ;
F_19 ( & V_7 ) ;
F_11 ( & V_16 -> V_25 , & V_470 ) ;
F_40 (id_priv, &listen_any_list, list)
F_149 ( V_2 , V_16 ) ;
F_21 ( & V_7 ) ;
}
static int F_268 ( struct V_1 * V_2 )
{
struct V_194 V_169 ;
enum V_3 V_8 ;
int V_6 = 0 ;
V_8 = F_5 ( V_2 , V_319 ) ;
if ( V_8 == V_189 )
return 0 ;
F_106 ( V_2 , V_8 ) ;
F_19 ( & V_2 -> V_82 ) ;
if ( ! F_1 ( V_2 , V_319 ) )
goto V_70;
memset ( & V_169 , 0 , sizeof V_169 ) ;
V_169 . V_169 = V_471 ;
V_6 = V_2 -> V_18 . V_84 ( & V_2 -> V_18 , & V_169 ) ;
V_70:
F_21 ( & V_2 -> V_82 ) ;
return V_6 ;
}
static void F_269 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
int V_6 ;
F_19 ( & V_7 ) ;
while ( ! F_102 ( & V_16 -> V_26 ) ) {
V_2 = F_103 ( V_16 -> V_26 . V_181 ,
struct V_1 , V_25 ) ;
F_20 ( & V_2 -> V_95 ) ;
F_104 ( & V_2 -> V_25 ) ;
F_9 ( & V_2 -> V_17 ) ;
F_21 ( & V_7 ) ;
V_6 = V_2 -> V_190 ? 1 : F_268 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( V_6 )
F_105 ( & V_2 -> V_18 ) ;
F_19 ( & V_7 ) ;
}
F_21 ( & V_7 ) ;
F_12 ( V_16 ) ;
F_117 ( & V_16 -> V_4 ) ;
}
static void F_270 ( struct V_468 * V_19 )
{
struct V_15 * V_16 ;
V_16 = F_271 ( V_19 , & V_469 ) ;
if ( ! V_16 )
return;
F_19 ( & V_7 ) ;
F_20 ( & V_16 -> V_25 ) ;
F_21 ( & V_7 ) ;
F_269 ( V_16 ) ;
F_17 ( V_16 ) ;
}
static int F_272 ( struct V_472 * V_473 , struct V_474 * V_475 )
{
struct V_476 * V_477 ;
struct V_478 * V_479 ;
struct V_1 * V_2 ;
struct V_83 * V_18 = NULL ;
struct V_15 * V_16 ;
int V_480 = 0 , V_481 = 0 ;
F_19 ( & V_7 ) ;
F_40 (cma_dev, &dev_list, list) {
if ( V_480 < V_475 -> args [ 0 ] ) {
V_480 ++ ;
continue;
}
V_481 = 0 ;
F_40 (id_priv, &cma_dev->id_list, list) {
if ( V_481 < V_475 -> args [ 1 ] ) {
V_481 ++ ;
continue;
}
V_479 = F_273 ( V_473 , & V_477 , V_475 -> V_477 -> V_482 ,
sizeof *V_479 , V_483 ,
V_484 ,
V_485 ) ;
if ( ! V_479 )
goto V_70;
memset ( V_479 , 0 , sizeof *V_479 ) ;
V_18 = & V_2 -> V_18 ;
V_479 -> V_24 = V_18 -> V_20 . V_21 . V_22 . V_51 ;
V_479 -> V_47 = V_18 -> V_47 ;
V_479 -> V_333 =
V_18 -> V_20 . V_21 . V_22 . V_333 ;
if ( F_274 ( V_473 , V_477 ,
F_138 ( F_22 ( V_2 ) ) ,
F_22 ( V_2 ) ,
V_486 ) )
goto V_70;
if ( F_274 ( V_473 , V_477 ,
F_138 ( F_22 ( V_2 ) ) ,
F_23 ( V_2 ) ,
V_487 ) )
goto V_70;
V_479 -> V_488 = V_2 -> V_91 ;
V_479 -> V_489 = V_18 -> V_41 ;
V_479 -> V_490 = V_2 -> V_8 ;
V_479 -> V_116 = V_2 -> V_116 ;
V_479 -> V_88 = V_18 -> V_88 ;
V_481 ++ ;
}
V_475 -> args [ 1 ] = 0 ;
V_480 ++ ;
}
V_70:
F_21 ( & V_7 ) ;
V_475 -> args [ 0 ] = V_480 ;
V_475 -> args [ 1 ] = V_481 ;
return V_473 -> V_491 ;
}
static int T_10 F_275 ( void )
{
int V_6 ;
V_296 = F_276 ( L_5 ) ;
if ( ! V_296 )
return - V_90 ;
F_277 ( & V_314 ) ;
F_278 ( & V_359 ) ;
F_279 ( & V_492 ) ;
V_6 = F_280 ( & V_469 ) ;
if ( V_6 )
goto V_115;
if ( F_281 ( V_483 , V_493 , V_494 ) )
F_123 ( V_286 L_6 ) ;
return 0 ;
V_115:
F_282 ( & V_492 ) ;
F_283 ( & V_359 ) ;
F_284 ( & V_314 ) ;
F_285 ( V_296 ) ;
return V_6 ;
}
static void T_11 F_286 ( void )
{
F_287 ( V_483 ) ;
F_288 ( & V_469 ) ;
F_282 ( & V_492 ) ;
F_283 ( & V_359 ) ;
F_284 ( & V_314 ) ;
F_285 ( V_296 ) ;
F_289 ( & V_382 ) ;
F_289 ( & V_383 ) ;
F_289 ( & V_384 ) ;
F_289 ( & V_385 ) ;
}
