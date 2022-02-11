const char * F_1 ( enum V_1 V_2 )
{
T_1 V_3 = V_2 ;
return ( V_3 < F_2 ( V_4 ) && V_4 [ V_3 ] ) ?
V_4 [ V_3 ] : L_1 ;
}
static int F_3 ( struct V_5 * V_6 , enum V_7 V_8 )
{
unsigned long V_9 ;
int V_10 ;
F_4 ( & V_6 -> V_11 , V_9 ) ;
V_10 = ( V_6 -> V_12 == V_8 ) ;
F_5 ( & V_6 -> V_11 , V_9 ) ;
return V_10 ;
}
static int F_6 ( struct V_5 * V_6 ,
enum V_7 V_8 , enum V_7 V_13 )
{
unsigned long V_9 ;
int V_10 ;
F_4 ( & V_6 -> V_11 , V_9 ) ;
if ( ( V_10 = ( V_6 -> V_12 == V_8 ) ) )
V_6 -> V_12 = V_13 ;
F_5 ( & V_6 -> V_11 , V_9 ) ;
return V_10 ;
}
static enum V_7 F_7 ( struct V_5 * V_6 ,
enum V_7 V_13 )
{
unsigned long V_9 ;
enum V_7 V_14 ;
F_4 ( & V_6 -> V_11 , V_9 ) ;
V_14 = V_6 -> V_12 ;
V_6 -> V_12 = V_13 ;
F_5 ( & V_6 -> V_11 , V_9 ) ;
return V_14 ;
}
static inline T_2 F_8 ( struct V_15 * V_16 )
{
return V_16 -> V_17 >> 4 ;
}
static inline void F_9 ( struct V_15 * V_16 , T_2 V_18 )
{
V_16 -> V_17 = ( V_18 << 4 ) | ( V_16 -> V_17 & 0xF ) ;
}
static void F_10 ( struct V_5 * V_6 ,
struct V_19 * V_20 )
{
F_11 ( & V_20 -> V_21 ) ;
V_6 -> V_20 = V_20 ;
V_6 -> V_22 . V_23 = V_20 -> V_23 ;
V_6 -> V_22 . V_24 . V_25 . V_26 . V_27 =
F_12 ( V_20 -> V_23 -> V_28 ) ;
F_13 ( & V_6 -> V_29 , & V_20 -> V_30 ) ;
}
static inline void F_14 ( struct V_19 * V_20 )
{
if ( F_15 ( & V_20 -> V_21 ) )
F_16 ( & V_20 -> V_8 ) ;
}
static inline void F_17 ( struct V_31 * V_31 )
{
struct V_32 * V_33 = F_18 ( V_31 , struct V_32 , V_34 ) ;
F_19 ( V_33 -> V_35 . V_36 ) ;
F_19 ( V_33 ) ;
}
static void F_20 ( struct V_5 * V_6 )
{
F_21 ( & V_11 ) ;
F_22 ( & V_6 -> V_29 ) ;
F_14 ( V_6 -> V_20 ) ;
V_6 -> V_20 = NULL ;
F_23 ( & V_11 ) ;
}
static inline struct V_37 * F_24 ( struct V_5 * V_6 )
{
return (struct V_37 * ) & V_6 -> V_22 . V_24 . V_25 . V_38 ;
}
static inline struct V_37 * F_25 ( struct V_5 * V_6 )
{
return (struct V_37 * ) & V_6 -> V_22 . V_24 . V_25 . V_39 ;
}
static inline unsigned short F_26 ( struct V_5 * V_6 )
{
return V_6 -> V_22 . V_24 . V_25 . V_38 . V_40 ;
}
static int F_27 ( struct V_5 * V_6 , T_3 V_41 )
{
struct V_42 V_43 ;
int V_10 = 0 ;
if ( V_6 -> V_41 ) {
if ( V_41 && V_6 -> V_41 != V_41 )
return - V_44 ;
return 0 ;
}
if ( V_41 ) {
V_6 -> V_41 = V_41 ;
return 0 ;
}
switch ( V_6 -> V_22 . V_45 ) {
case V_46 :
case V_47 :
V_6 -> V_41 = V_48 ;
break;
case V_49 :
F_28 ( & V_6 -> V_22 . V_24 . V_25 . V_26 , & V_43 . V_50 ) ;
V_10 = F_29 ( V_6 -> V_22 . V_23 ,
V_6 -> V_22 . V_51 , & V_43 . V_50 ,
& V_43 ) ;
if ( ! V_10 )
V_6 -> V_41 = F_30 ( V_43 . V_41 ) ;
break;
default:
break;
}
return V_10 ;
}
static void F_31 ( struct V_52 * V_53 , struct V_54 * V_26 )
{
V_26 -> V_55 = V_56 ;
F_32 ( V_26 , (union V_57 * ) & V_53 -> V_58 ) ;
F_33 ( V_26 , F_34 ( V_53 -> V_59 ) ) ;
}
static int F_35 ( struct V_37 * V_25 , struct V_54 * V_26 )
{
int V_10 ;
if ( V_25 -> V_60 != V_61 ) {
V_10 = F_36 ( V_25 , V_26 , NULL ) ;
} else {
F_31 ( (struct V_52 * ) V_25 , V_26 ) ;
V_10 = 0 ;
}
return V_10 ;
}
static inline int F_37 ( struct V_62 * V_23 , T_2 V_63 ,
union V_57 * V_64 , int V_55 )
{
T_2 V_65 ;
int V_10 = - V_66 ;
if ( ( V_55 == V_56 ) && ! F_38 ( V_23 , V_63 ) )
return V_10 ;
if ( ( V_55 != V_56 ) && F_38 ( V_23 , V_63 ) )
return V_10 ;
V_10 = F_39 ( V_23 , V_64 , & V_65 , NULL ) ;
if ( V_63 != V_65 )
return - V_66 ;
return V_10 ;
}
static int F_40 ( struct V_5 * V_6 ,
struct V_5 * V_67 )
{
struct V_54 * V_26 = & V_6 -> V_22 . V_24 . V_25 . V_26 ;
struct V_19 * V_20 ;
union V_57 V_64 , V_68 , * V_69 ;
int V_10 = - V_66 ;
T_2 V_63 ;
if ( V_26 -> V_55 != V_56 &&
V_6 -> V_22 . V_45 == V_49 )
return - V_44 ;
F_21 ( & V_11 ) ;
F_41 ( (struct V_37 * ) & V_6 -> V_22 . V_24 . V_25 . V_38 ,
& V_68 ) ;
memcpy ( & V_64 , V_26 -> V_70 +
F_42 ( V_26 ) , sizeof V_64 ) ;
if ( V_67 ) {
V_20 = V_67 -> V_20 ;
V_63 = V_67 -> V_22 . V_51 ;
V_69 = F_43 ( V_20 -> V_23 , V_63 ) ?
& V_68 : & V_64 ;
V_10 = F_37 ( V_20 -> V_23 , V_63 , V_69 ,
V_26 -> V_55 ) ;
if ( ! V_10 ) {
V_6 -> V_22 . V_51 = V_63 ;
goto V_71;
}
}
F_44 (cma_dev, &dev_list, list) {
for ( V_63 = 1 ; V_63 <= V_20 -> V_23 -> V_72 ; ++ V_63 ) {
if ( V_67 &&
V_67 -> V_20 == V_20 &&
V_67 -> V_22 . V_51 == V_63 )
continue;
V_69 = F_43 ( V_20 -> V_23 , V_63 ) ?
& V_68 : & V_64 ;
V_10 = F_37 ( V_20 -> V_23 , V_63 , V_69 ,
V_26 -> V_55 ) ;
if ( ! V_10 ) {
V_6 -> V_22 . V_51 = V_63 ;
goto V_71;
}
}
}
V_71:
if ( ! V_10 )
F_10 ( V_6 , V_20 ) ;
F_23 ( & V_11 ) ;
return V_10 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_19 * V_20 , * V_73 ;
struct V_52 * V_25 ;
union V_57 V_64 , V_74 , * V_75 ;
T_4 V_76 , V_3 ;
T_2 V_77 ;
int V_78 ;
V_20 = NULL ;
V_25 = (struct V_52 * ) F_25 ( V_6 ) ;
V_75 = (union V_57 * ) & V_25 -> V_58 ;
V_76 = F_34 ( V_25 -> V_59 ) ;
F_44 (cur_dev, &dev_list, list) {
for ( V_77 = 1 ; V_77 <= V_73 -> V_23 -> V_72 ; ++ V_77 ) {
if ( ! F_46 ( V_73 -> V_23 , V_77 ) )
continue;
if ( F_47 ( V_73 -> V_23 , V_77 , V_76 , & V_3 ) )
continue;
for ( V_78 = 0 ; ! F_48 ( V_73 -> V_23 , V_77 , V_78 , & V_64 ) ; V_78 ++ ) {
if ( ! memcmp ( & V_64 , V_75 , sizeof( V_64 ) ) ) {
V_20 = V_73 ;
V_74 = V_64 ;
V_6 -> V_22 . V_51 = V_77 ;
goto V_79;
}
if ( ! V_20 && ( V_64 . V_80 . V_81 ==
V_75 -> V_80 . V_81 ) ) {
V_20 = V_73 ;
V_74 = V_64 ;
V_6 -> V_22 . V_51 = V_77 ;
}
}
}
}
if ( ! V_20 )
return - V_66 ;
V_79:
F_10 ( V_6 , V_20 ) ;
V_25 = (struct V_52 * ) F_24 ( V_6 ) ;
memcpy ( & V_25 -> V_58 , & V_74 , sizeof V_74 ) ;
F_31 ( V_25 , & V_6 -> V_22 . V_24 . V_25 . V_26 ) ;
return 0 ;
}
static void F_49 ( struct V_5 * V_6 )
{
if ( F_15 ( & V_6 -> V_21 ) )
F_16 ( & V_6 -> V_8 ) ;
}
static int F_50 ( struct V_5 * V_6 ,
enum V_7 V_12 )
{
F_21 ( & V_6 -> V_82 ) ;
if ( V_6 -> V_12 != V_12 ) {
F_23 ( & V_6 -> V_82 ) ;
return - V_44 ;
}
return 0 ;
}
struct V_83 * F_51 ( T_5 V_84 ,
void * V_85 , enum V_86 V_45 ,
enum V_87 V_88 )
{
struct V_5 * V_6 ;
V_6 = F_52 ( sizeof *V_6 , V_89 ) ;
if ( ! V_6 )
return F_53 ( - V_90 ) ;
V_6 -> V_91 = F_54 ( V_92 ) ;
V_6 -> V_12 = V_93 ;
V_6 -> V_22 . V_85 = V_85 ;
V_6 -> V_22 . V_84 = V_84 ;
V_6 -> V_22 . V_45 = V_45 ;
V_6 -> V_22 . V_88 = V_88 ;
F_55 ( & V_6 -> V_11 ) ;
F_56 ( & V_6 -> V_94 ) ;
F_57 ( & V_6 -> V_8 ) ;
F_58 ( & V_6 -> V_21 , 1 ) ;
F_56 ( & V_6 -> V_82 ) ;
F_59 ( & V_6 -> V_95 ) ;
F_59 ( & V_6 -> V_96 ) ;
F_60 ( & V_6 -> V_97 , sizeof V_6 -> V_97 ) ;
return & V_6 -> V_22 ;
}
static int F_61 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
struct V_100 V_101 ;
int V_102 , V_10 ;
V_101 . V_103 = V_104 ;
V_10 = F_62 ( & V_6 -> V_22 , & V_101 , & V_102 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_63 ( V_99 , & V_101 , V_102 ) ;
if ( V_10 )
return V_10 ;
V_101 . V_103 = V_105 ;
V_10 = F_63 ( V_99 , & V_101 , V_106 ) ;
if ( V_10 )
return V_10 ;
V_101 . V_103 = V_107 ;
V_101 . V_108 = 0 ;
V_10 = F_63 ( V_99 , & V_101 , V_106 | V_109 ) ;
return V_10 ;
}
static int F_64 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
struct V_100 V_101 ;
int V_102 , V_10 ;
V_101 . V_103 = V_104 ;
V_10 = F_62 ( & V_6 -> V_22 , & V_101 , & V_102 ) ;
if ( V_10 )
return V_10 ;
return F_63 ( V_99 , & V_101 , V_102 ) ;
}
int F_65 ( struct V_83 * V_22 , struct V_110 * V_111 ,
struct V_112 * V_113 )
{
struct V_5 * V_6 ;
struct V_98 * V_99 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( V_22 -> V_23 != V_111 -> V_23 )
return - V_44 ;
V_99 = F_66 ( V_111 , V_113 ) ;
if ( F_67 ( V_99 ) )
return F_68 ( V_99 ) ;
if ( V_22 -> V_88 == V_114 )
V_10 = F_61 ( V_6 , V_99 ) ;
else
V_10 = F_64 ( V_6 , V_99 ) ;
if ( V_10 )
goto V_115;
V_22 -> V_99 = V_99 ;
V_6 -> V_116 = V_99 -> V_116 ;
V_6 -> V_117 = ( V_99 -> V_117 != NULL ) ;
return 0 ;
V_115:
F_69 ( V_99 ) ;
return V_10 ;
}
void F_70 ( struct V_83 * V_22 )
{
struct V_5 * V_6 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
F_21 ( & V_6 -> V_94 ) ;
F_69 ( V_6 -> V_22 . V_99 ) ;
V_6 -> V_22 . V_99 = NULL ;
F_23 ( & V_6 -> V_94 ) ;
}
static int F_71 ( struct V_5 * V_6 ,
struct V_118 * V_119 )
{
struct V_100 V_101 ;
int V_102 , V_10 ;
union V_57 V_74 ;
F_21 ( & V_6 -> V_94 ) ;
if ( ! V_6 -> V_22 . V_99 ) {
V_10 = 0 ;
goto V_71;
}
V_101 . V_103 = V_104 ;
V_10 = F_62 ( & V_6 -> V_22 , & V_101 , & V_102 ) ;
if ( V_10 )
goto V_71;
V_10 = F_63 ( V_6 -> V_22 . V_99 , & V_101 , V_102 ) ;
if ( V_10 )
goto V_71;
V_101 . V_103 = V_105 ;
V_10 = F_62 ( & V_6 -> V_22 , & V_101 , & V_102 ) ;
if ( V_10 )
goto V_71;
V_10 = F_72 ( V_6 -> V_22 . V_23 , V_6 -> V_22 . V_51 ,
V_101 . V_120 . V_121 . V_122 , & V_74 ) ;
if ( V_10 )
goto V_71;
F_73 ( V_6 -> V_20 -> V_23 != V_6 -> V_22 . V_23 ) ;
if ( F_43 ( V_6 -> V_22 . V_23 , V_6 -> V_22 . V_51 ) ) {
V_10 = F_74 ( & V_74 , V_101 . V_123 , NULL ) ;
if ( V_10 )
goto V_71;
}
if ( V_119 )
V_101 . V_124 = V_119 -> V_125 ;
V_10 = F_63 ( V_6 -> V_22 . V_99 , & V_101 , V_102 ) ;
V_71:
F_23 ( & V_6 -> V_94 ) ;
return V_10 ;
}
static int F_75 ( struct V_5 * V_6 ,
struct V_118 * V_119 )
{
struct V_100 V_101 ;
int V_102 , V_10 ;
F_21 ( & V_6 -> V_94 ) ;
if ( ! V_6 -> V_22 . V_99 ) {
V_10 = 0 ;
goto V_71;
}
V_101 . V_103 = V_107 ;
V_10 = F_62 ( & V_6 -> V_22 , & V_101 , & V_102 ) ;
if ( V_10 )
goto V_71;
if ( V_119 )
V_101 . V_126 = V_119 -> V_127 ;
V_10 = F_63 ( V_6 -> V_22 . V_99 , & V_101 , V_102 ) ;
V_71:
F_23 ( & V_6 -> V_94 ) ;
return V_10 ;
}
static int F_76 ( struct V_5 * V_6 )
{
struct V_100 V_101 ;
int V_10 ;
F_21 ( & V_6 -> V_94 ) ;
if ( ! V_6 -> V_22 . V_99 ) {
V_10 = 0 ;
goto V_71;
}
V_101 . V_103 = V_128 ;
V_10 = F_63 ( V_6 -> V_22 . V_99 , & V_101 , V_106 ) ;
V_71:
F_23 ( & V_6 -> V_94 ) ;
return V_10 ;
}
static int F_77 ( struct V_5 * V_6 ,
struct V_100 * V_101 , int * V_102 )
{
struct V_54 * V_26 = & V_6 -> V_22 . V_24 . V_25 . V_26 ;
int V_10 ;
T_4 V_76 ;
if ( F_78 ( V_6 -> V_22 . V_23 , V_6 -> V_22 . V_51 ) )
V_76 = 0xffff ;
else
V_76 = F_79 ( V_26 ) ;
V_10 = F_47 ( V_6 -> V_22 . V_23 , V_6 -> V_22 . V_51 ,
V_76 , & V_101 -> V_129 ) ;
if ( V_10 )
return V_10 ;
V_101 -> V_51 = V_6 -> V_22 . V_51 ;
* V_102 = V_106 | V_130 | V_131 ;
if ( V_6 -> V_22 . V_88 == V_114 ) {
V_10 = F_27 ( V_6 , 0 ) ;
if ( V_10 )
return V_10 ;
V_101 -> V_41 = V_6 -> V_41 ;
* V_102 |= V_132 ;
} else {
V_101 -> V_133 = 0 ;
* V_102 |= V_134 ;
}
return 0 ;
}
int F_62 ( struct V_83 * V_22 , struct V_100 * V_101 ,
int * V_102 )
{
struct V_5 * V_6 ;
int V_10 = 0 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( F_80 ( V_22 -> V_23 , V_22 -> V_51 ) ) {
if ( ! V_6 -> V_135 . V_36 || ( V_6 -> V_22 . V_88 == V_114 ) )
V_10 = F_77 ( V_6 , V_101 , V_102 ) ;
else
V_10 = F_81 ( V_6 -> V_135 . V_36 , V_101 ,
V_102 ) ;
if ( V_101 -> V_103 == V_105 )
V_101 -> V_136 = V_6 -> V_97 ;
} else if ( F_82 ( V_22 -> V_23 , V_22 -> V_51 ) ) {
if ( ! V_6 -> V_135 . V_137 ) {
V_101 -> V_133 = 0 ;
* V_102 = V_106 | V_134 ;
} else
V_10 = F_83 ( V_6 -> V_135 . V_137 , V_101 ,
V_102 ) ;
} else
V_10 = - V_138 ;
return V_10 ;
}
static inline int F_84 ( struct V_37 * V_25 )
{
switch ( V_25 -> V_60 ) {
case V_139 :
return F_85 ( ( (struct V_140 * ) V_25 ) -> V_141 . V_142 ) ;
case V_143 :
return F_86 ( & ( (struct V_144 * ) V_25 ) -> V_145 ) ;
case V_61 :
return F_87 ( & ( (struct V_52 * ) V_25 ) -> V_58 ) ;
default:
return 0 ;
}
}
static inline int F_88 ( struct V_37 * V_25 )
{
switch ( V_25 -> V_60 ) {
case V_139 :
return F_89 ( ( (struct V_140 * ) V_25 ) -> V_141 . V_142 ) ;
case V_143 :
return F_90 ( & ( (struct V_144 * ) V_25 ) -> V_145 ) ;
case V_61 :
return F_91 ( & ( (struct V_52 * ) V_25 ) -> V_58 ) ;
default:
return 0 ;
}
}
static inline int F_92 ( struct V_37 * V_25 )
{
return F_84 ( V_25 ) || F_88 ( V_25 ) ;
}
static int F_93 ( struct V_37 * V_146 , struct V_37 * V_147 )
{
if ( V_146 -> V_60 != V_147 -> V_60 )
return - 1 ;
switch ( V_146 -> V_60 ) {
case V_139 :
return ( (struct V_140 * ) V_146 ) -> V_141 . V_142 !=
( (struct V_140 * ) V_147 ) -> V_141 . V_142 ;
case V_143 :
return F_94 ( & ( (struct V_144 * ) V_146 ) -> V_145 ,
& ( (struct V_144 * ) V_147 ) -> V_145 ) ;
default:
return F_95 ( & ( (struct V_52 * ) V_146 ) -> V_58 ,
& ( (struct V_52 * ) V_147 ) -> V_58 ) ;
}
}
static T_6 F_96 ( struct V_37 * V_25 )
{
struct V_52 * V_53 ;
switch ( V_25 -> V_60 ) {
case V_139 :
return ( (struct V_140 * ) V_25 ) -> V_148 ;
case V_143 :
return ( (struct V_144 * ) V_25 ) -> V_149 ;
case V_61 :
V_53 = (struct V_52 * ) V_25 ;
return F_97 ( ( T_4 ) ( F_98 ( V_53 -> V_150 ) &
F_98 ( V_53 -> V_151 ) ) ) ;
default:
return 0 ;
}
}
static inline int F_99 ( struct V_37 * V_25 )
{
return ! F_96 ( V_25 ) ;
}
static void F_100 ( struct V_83 * V_22 , struct V_83 * V_152 ,
struct V_153 * V_154 )
{
struct V_52 * V_155 , * V_36 ;
V_155 = (struct V_52 * ) & V_152 -> V_24 . V_25 . V_38 ;
V_36 = (struct V_52 * ) & V_22 -> V_24 . V_25 . V_38 ;
V_36 -> V_156 = V_155 -> V_156 ;
if ( V_154 ) {
V_36 -> V_59 = V_154 -> V_76 ;
V_36 -> V_157 = V_154 -> V_158 ;
memcpy ( & V_36 -> V_58 , & V_154 -> V_74 , 16 ) ;
} else {
V_36 -> V_59 = V_155 -> V_59 ;
V_36 -> V_157 = V_155 -> V_157 ;
V_36 -> V_58 = V_155 -> V_58 ;
}
V_36 -> V_150 = V_155 -> V_150 ;
V_36 -> V_151 = F_101 ( 0xffffffffffffffffULL ) ;
V_36 -> V_159 = V_155 -> V_159 ;
if ( V_154 ) {
V_36 = (struct V_52 * ) & V_22 -> V_24 . V_25 . V_39 ;
V_36 -> V_156 = V_155 -> V_156 ;
V_36 -> V_59 = V_154 -> V_76 ;
V_36 -> V_157 = V_154 -> V_158 ;
memcpy ( & V_36 -> V_58 , & V_154 -> V_75 , 16 ) ;
}
}
static T_6 F_102 ( const struct V_160 * V_161 )
{
if ( V_161 -> V_40 == V_139 )
return ( (struct V_140 * ) V_161 ) -> V_148 ;
else if ( V_161 -> V_40 == V_143 )
return ( (struct V_144 * ) V_161 ) -> V_149 ;
F_103 () ;
}
static void F_104 ( struct V_83 * V_22 , struct V_83 * V_152 ,
struct V_15 * V_16 )
{
struct V_140 * V_162 ;
V_162 = (struct V_140 * ) & V_22 -> V_24 . V_25 . V_38 ;
V_162 -> V_163 = V_139 ;
V_162 -> V_141 . V_142 = V_16 -> V_39 . V_162 . V_25 ;
V_162 -> V_148 = F_102 ( & V_152 -> V_24 . V_25 . V_38 ) ;
V_162 = (struct V_140 * ) & V_22 -> V_24 . V_25 . V_39 ;
V_162 -> V_163 = V_139 ;
V_162 -> V_141 . V_142 = V_16 -> V_38 . V_162 . V_25 ;
V_162 -> V_148 = V_16 -> V_63 ;
}
static void F_105 ( struct V_83 * V_22 , struct V_83 * V_152 ,
struct V_15 * V_16 )
{
struct V_144 * V_164 ;
V_164 = (struct V_144 * ) & V_22 -> V_24 . V_25 . V_38 ;
V_164 -> V_165 = V_143 ;
V_164 -> V_145 = V_16 -> V_39 . V_164 ;
V_164 -> V_149 = F_102 ( & V_152 -> V_24 . V_25 . V_38 ) ;
V_164 = (struct V_144 * ) & V_22 -> V_24 . V_25 . V_39 ;
V_164 -> V_165 = V_143 ;
V_164 -> V_145 = V_16 -> V_38 . V_164 ;
V_164 -> V_149 = V_16 -> V_63 ;
}
static int F_106 ( struct V_83 * V_22 , struct V_83 * V_152 ,
struct V_166 * V_167 )
{
struct V_15 * V_16 ;
if ( V_152 -> V_24 . V_25 . V_38 . V_40 == V_61 ) {
if ( V_167 -> V_2 == V_168 )
F_100 ( V_22 , V_152 , V_167 -> V_169 . V_170 . V_171 ) ;
else if ( V_167 -> V_2 == V_172 )
F_100 ( V_22 , V_152 , NULL ) ;
return 0 ;
}
V_16 = V_167 -> V_173 ;
if ( V_16 -> V_174 != V_175 )
return - V_44 ;
switch ( F_8 ( V_16 ) ) {
case 4 :
F_104 ( V_22 , V_152 , V_16 ) ;
break;
case 6 :
F_105 ( V_22 , V_152 , V_16 ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static inline int F_107 ( struct V_5 * V_6 )
{
return F_26 ( V_6 ) == V_61 ? 0 : sizeof( struct V_15 ) ;
}
static void F_108 ( struct V_5 * V_6 )
{
if ( F_109 ( V_6 -> V_22 . V_23 , V_6 -> V_22 . V_51 ) ) {
if ( V_6 -> V_176 )
F_110 ( V_6 -> V_177 , V_6 -> V_176 ) ;
}
}
static void F_111 ( struct V_5 * V_6 )
{
struct V_5 * V_178 ;
F_21 ( & V_11 ) ;
F_22 ( & V_6 -> V_29 ) ;
while ( ! F_112 ( & V_6 -> V_95 ) ) {
V_178 = F_113 ( V_6 -> V_95 . V_179 ,
struct V_5 , V_95 ) ;
F_114 ( & V_178 -> V_29 ) ;
F_22 ( & V_178 -> V_95 ) ;
F_23 ( & V_11 ) ;
F_115 ( & V_178 -> V_22 ) ;
F_21 ( & V_11 ) ;
}
F_23 ( & V_11 ) ;
}
static void F_116 ( struct V_5 * V_6 ,
enum V_7 V_12 )
{
switch ( V_12 ) {
case V_180 :
F_117 ( & V_6 -> V_22 . V_24 . V_25 . V_26 ) ;
break;
case V_181 :
F_108 ( V_6 ) ;
break;
case V_182 :
if ( F_92 ( F_24 ( V_6 ) ) && ! V_6 -> V_20 )
F_111 ( V_6 ) ;
break;
default:
break;
}
}
static void F_118 ( struct V_5 * V_6 )
{
struct V_183 * V_184 = V_6 -> V_184 ;
if ( ! V_184 )
return;
F_21 ( & V_11 ) ;
F_119 ( & V_6 -> V_185 ) ;
if ( F_120 ( & V_184 -> V_186 ) ) {
F_121 ( V_184 -> V_45 , V_184 -> V_63 ) ;
F_19 ( V_184 ) ;
}
F_23 ( & V_11 ) ;
}
static void F_122 ( struct V_5 * V_6 )
{
struct V_32 * V_33 ;
while ( ! F_112 ( & V_6 -> V_96 ) ) {
V_33 = F_18 ( V_6 -> V_96 . V_179 ,
struct V_32 , V_29 ) ;
F_22 ( & V_33 -> V_29 ) ;
if ( F_123 ( V_6 -> V_20 -> V_23 ,
V_6 -> V_22 . V_51 ) ) {
F_124 ( V_33 -> V_35 . V_36 ) ;
F_19 ( V_33 ) ;
} else
F_125 ( & V_33 -> V_34 , F_17 ) ;
}
}
void F_115 ( struct V_83 * V_22 )
{
struct V_5 * V_6 ;
enum V_7 V_12 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
V_12 = F_7 ( V_6 , V_187 ) ;
F_116 ( V_6 , V_12 ) ;
F_21 ( & V_6 -> V_82 ) ;
F_23 ( & V_6 -> V_82 ) ;
if ( V_6 -> V_20 ) {
if ( F_80 ( V_6 -> V_22 . V_23 , 1 ) ) {
if ( V_6 -> V_135 . V_36 )
F_126 ( V_6 -> V_135 . V_36 ) ;
} else if ( F_82 ( V_6 -> V_22 . V_23 , 1 ) ) {
if ( V_6 -> V_135 . V_137 )
F_127 ( V_6 -> V_135 . V_137 ) ;
}
F_122 ( V_6 ) ;
F_20 ( V_6 ) ;
}
F_118 ( V_6 ) ;
F_49 ( V_6 ) ;
F_128 ( & V_6 -> V_8 ) ;
if ( V_6 -> V_188 )
F_49 ( V_6 -> V_22 . V_85 ) ;
F_19 ( V_6 -> V_22 . V_24 . V_189 ) ;
F_19 ( V_6 ) ;
}
static int F_129 ( struct V_5 * V_6 )
{
int V_10 ;
V_10 = F_71 ( V_6 , NULL ) ;
if ( V_10 )
goto V_190;
V_10 = F_75 ( V_6 , NULL ) ;
if ( V_10 )
goto V_190;
V_10 = F_130 ( V_6 -> V_135 . V_36 , NULL , 0 ) ;
if ( V_10 )
goto V_190;
return 0 ;
V_190:
F_76 ( V_6 ) ;
F_131 ( V_6 -> V_135 . V_36 , V_191 ,
NULL , 0 , NULL , 0 ) ;
return V_10 ;
}
static void F_132 ( struct V_192 * V_2 ,
struct V_193 * V_194 ,
void * V_173 )
{
V_2 -> V_169 . V_195 . V_173 = V_173 ;
V_2 -> V_169 . V_195 . V_196 = V_197 ;
V_2 -> V_169 . V_195 . V_125 = V_194 -> V_125 ;
V_2 -> V_169 . V_195 . V_127 = V_194 -> V_127 ;
V_2 -> V_169 . V_195 . V_198 = V_194 -> V_198 ;
V_2 -> V_169 . V_195 . V_199 = V_194 -> V_199 ;
V_2 -> V_169 . V_195 . V_117 = V_194 -> V_117 ;
V_2 -> V_169 . V_195 . V_116 = V_194 -> V_200 ;
}
static int F_133 ( struct V_201 * V_135 , struct V_166 * V_167 )
{
struct V_5 * V_6 = V_135 -> V_85 ;
struct V_192 V_2 ;
int V_10 = 0 ;
if ( ( V_167 -> V_2 != V_202 &&
F_50 ( V_6 , V_203 ) ) ||
( V_167 -> V_2 == V_202 &&
F_50 ( V_6 , V_204 ) ) )
return 0 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_167 -> V_2 ) {
case V_205 :
case V_206 :
V_2 . V_2 = V_207 ;
V_2 . V_208 = - V_209 ;
break;
case V_210 :
if ( V_6 -> V_22 . V_99 ) {
V_2 . V_208 = F_129 ( V_6 ) ;
V_2 . V_2 = V_2 . V_208 ? V_211 :
V_212 ;
} else {
V_2 . V_2 = V_213 ;
}
F_132 ( & V_2 , & V_167 -> V_169 . V_214 ,
V_167 -> V_173 ) ;
break;
case V_215 :
case V_216 :
V_2 . V_2 = V_212 ;
break;
case V_217 :
V_2 . V_208 = - V_209 ;
case V_218 :
case V_219 :
if ( ! F_6 ( V_6 , V_203 ,
V_204 ) )
goto V_71;
V_2 . V_2 = V_220 ;
break;
case V_202 :
V_2 . V_2 = V_221 ;
break;
case V_222 :
goto V_71;
case V_223 :
F_76 ( V_6 ) ;
V_2 . V_208 = V_167 -> V_169 . V_224 . V_225 ;
V_2 . V_2 = V_226 ;
V_2 . V_169 . V_195 . V_173 = V_167 -> V_173 ;
V_2 . V_169 . V_195 . V_196 = V_227 ;
break;
default:
F_134 ( V_228 L_2 ,
V_167 -> V_2 ) ;
goto V_71;
}
V_10 = V_6 -> V_22 . V_84 ( & V_6 -> V_22 , & V_2 ) ;
if ( V_10 ) {
V_6 -> V_135 . V_36 = NULL ;
F_7 ( V_6 , V_187 ) ;
F_23 ( & V_6 -> V_82 ) ;
F_115 ( & V_6 -> V_22 ) ;
return V_10 ;
}
V_71:
F_23 ( & V_6 -> V_82 ) ;
return V_10 ;
}
static struct V_5 * F_135 ( struct V_83 * V_152 ,
struct V_166 * V_167 )
{
struct V_5 * V_6 ;
struct V_83 * V_22 ;
struct V_229 * V_230 ;
int V_10 ;
V_22 = F_51 ( V_152 -> V_84 , V_152 -> V_85 ,
V_152 -> V_45 , V_167 -> V_169 . V_170 . V_88 ) ;
if ( F_67 ( V_22 ) )
return NULL ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( F_106 ( V_22 , V_152 , V_167 ) )
goto V_115;
V_230 = & V_22 -> V_24 ;
V_230 -> V_231 = V_167 -> V_169 . V_170 . V_232 ? 2 : 1 ;
V_230 -> V_189 = F_136 ( sizeof * V_230 -> V_189 * V_230 -> V_231 ,
V_89 ) ;
if ( ! V_230 -> V_189 )
goto V_115;
V_230 -> V_189 [ 0 ] = * V_167 -> V_169 . V_170 . V_171 ;
if ( V_230 -> V_231 == 2 )
V_230 -> V_189 [ 1 ] = * V_167 -> V_169 . V_170 . V_232 ;
if ( F_92 ( F_24 ( V_6 ) ) ) {
V_230 -> V_25 . V_26 . V_55 = V_56 ;
F_32 ( & V_230 -> V_25 . V_26 , & V_230 -> V_189 [ 0 ] . V_74 ) ;
F_33 ( & V_230 -> V_25 . V_26 , F_137 ( V_230 -> V_189 [ 0 ] . V_76 ) ) ;
} else {
V_10 = F_35 ( F_24 ( V_6 ) , & V_230 -> V_25 . V_26 ) ;
if ( V_10 )
goto V_115;
}
F_138 ( & V_230 -> V_25 . V_26 , & V_230 -> V_189 [ 0 ] . V_75 ) ;
V_6 -> V_12 = V_203 ;
return V_6 ;
V_115:
F_115 ( V_22 ) ;
return NULL ;
}
static struct V_5 * F_139 ( struct V_83 * V_152 ,
struct V_166 * V_167 )
{
struct V_5 * V_6 ;
struct V_83 * V_22 ;
int V_10 ;
V_22 = F_51 ( V_152 -> V_84 , V_152 -> V_85 ,
V_152 -> V_45 , V_114 ) ;
if ( F_67 ( V_22 ) )
return NULL ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( F_106 ( V_22 , V_152 , V_167 ) )
goto V_115;
if ( ! F_92 ( (struct V_37 * ) & V_22 -> V_24 . V_25 . V_38 ) ) {
V_10 = F_35 ( F_24 ( V_6 ) , & V_22 -> V_24 . V_25 . V_26 ) ;
if ( V_10 )
goto V_115;
}
V_6 -> V_12 = V_203 ;
return V_6 ;
V_115:
F_115 ( V_22 ) ;
return NULL ;
}
static void F_140 ( struct V_192 * V_2 ,
struct V_233 * V_234 ,
void * V_173 , int V_235 )
{
V_2 -> V_169 . V_195 . V_173 = V_173 + V_235 ;
V_2 -> V_169 . V_195 . V_196 = V_236 - V_235 ;
V_2 -> V_169 . V_195 . V_125 = V_234 -> V_125 ;
V_2 -> V_169 . V_195 . V_127 = V_234 -> V_127 ;
V_2 -> V_169 . V_195 . V_198 = V_234 -> V_198 ;
V_2 -> V_169 . V_195 . V_237 = V_234 -> V_237 ;
V_2 -> V_169 . V_195 . V_199 = V_234 -> V_199 ;
V_2 -> V_169 . V_195 . V_117 = V_234 -> V_117 ;
V_2 -> V_169 . V_195 . V_116 = V_234 -> V_200 ;
}
static int F_141 ( struct V_83 * V_22 , struct V_166 * V_167 )
{
return ( ( ( V_167 -> V_2 == V_168 ) &&
( V_167 -> V_169 . V_170 . V_88 == V_22 -> V_88 ) ) ||
( ( V_167 -> V_2 == V_172 ) &&
( V_22 -> V_88 == V_114 ) ) ||
( ! V_22 -> V_88 ) ) ;
}
static int F_142 ( struct V_201 * V_135 , struct V_166 * V_167 )
{
struct V_5 * V_152 , * V_238 ;
struct V_192 V_2 ;
int V_235 , V_10 ;
V_152 = V_135 -> V_85 ;
if ( ! F_141 ( & V_152 -> V_22 , V_167 ) )
return - V_44 ;
if ( F_50 ( V_152 , V_182 ) )
return - V_239 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_235 = F_107 ( V_152 ) ;
V_2 . V_2 = V_240 ;
if ( V_167 -> V_2 == V_172 ) {
V_238 = F_139 ( & V_152 -> V_22 , V_167 ) ;
V_2 . V_169 . V_241 . V_173 = V_167 -> V_173 + V_235 ;
V_2 . V_169 . V_241 . V_196 =
V_242 - V_235 ;
} else {
V_238 = F_135 ( & V_152 -> V_22 , V_167 ) ;
F_140 ( & V_2 , & V_167 -> V_169 . V_170 ,
V_167 -> V_173 , V_235 ) ;
}
if ( ! V_238 ) {
V_10 = - V_90 ;
goto V_243;
}
F_143 ( & V_238 -> V_82 , V_244 ) ;
V_10 = F_40 ( V_238 , V_152 ) ;
if ( V_10 )
goto V_245;
V_238 -> V_135 . V_36 = V_135 ;
V_135 -> V_85 = V_238 ;
V_135 -> V_246 = F_133 ;
F_11 ( & V_238 -> V_21 ) ;
V_10 = V_238 -> V_22 . V_84 ( & V_238 -> V_22 , & V_2 ) ;
if ( V_10 )
goto V_247;
F_21 ( & V_11 ) ;
if ( F_3 ( V_238 , V_203 ) &&
( V_238 -> V_22 . V_88 != V_114 ) )
F_144 ( V_135 , V_248 , NULL , 0 ) ;
F_23 ( & V_11 ) ;
F_23 ( & V_238 -> V_82 ) ;
F_23 ( & V_152 -> V_82 ) ;
F_49 ( V_238 ) ;
return 0 ;
V_247:
F_49 ( V_238 ) ;
V_238 -> V_135 . V_36 = NULL ;
V_245:
F_7 ( V_238 , V_187 ) ;
F_23 ( & V_238 -> V_82 ) ;
V_243:
F_23 ( & V_152 -> V_82 ) ;
if ( V_238 )
F_115 ( & V_238 -> V_22 ) ;
return V_10 ;
}
T_7 F_145 ( struct V_83 * V_22 , struct V_37 * V_25 )
{
if ( V_25 -> V_60 == V_61 )
return ( (struct V_52 * ) V_25 ) -> V_150 ;
return F_101 ( ( ( V_249 ) V_22 -> V_45 << 16 ) + F_137 ( F_96 ( V_25 ) ) ) ;
}
static void F_146 ( enum V_86 V_45 , struct V_37 * V_25 ,
struct V_250 * V_251 )
{
struct V_15 * V_252 , * V_253 ;
T_8 V_254 ;
struct V_255 V_256 ;
memset ( V_251 , 0 , sizeof *V_251 ) ;
V_252 = ( void * ) V_251 -> V_257 ;
V_253 = ( void * ) V_251 -> V_258 ;
switch ( V_25 -> V_60 ) {
case V_139 :
V_254 = ( (struct V_140 * ) V_25 ) -> V_141 . V_142 ;
F_9 ( V_252 , 4 ) ;
F_9 ( V_253 , 0xF ) ;
if ( ! F_92 ( V_25 ) ) {
V_252 -> V_39 . V_162 . V_25 = V_254 ;
V_253 -> V_39 . V_162 . V_25 = F_147 ( ~ 0 ) ;
}
break;
case V_143 :
V_256 = ( (struct V_144 * ) V_25 ) -> V_145 ;
F_9 ( V_252 , 6 ) ;
F_9 ( V_253 , 0xF ) ;
if ( ! F_92 ( V_25 ) ) {
V_252 -> V_39 . V_164 = V_256 ;
memset ( & V_253 -> V_39 . V_164 , 0xFF ,
sizeof V_253 -> V_39 . V_164 ) ;
}
break;
default:
break;
}
}
static int F_148 ( struct V_259 * V_260 , struct V_261 * V_262 )
{
struct V_5 * V_6 = V_260 -> V_85 ;
struct V_192 V_2 ;
int V_10 = 0 ;
struct V_37 * V_263 = (struct V_37 * ) & V_262 -> V_264 ;
struct V_37 * V_265 = (struct V_37 * ) & V_262 -> V_266 ;
if ( F_50 ( V_6 , V_203 ) )
return 0 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_262 -> V_2 ) {
case V_267 :
V_2 . V_2 = V_220 ;
break;
case V_268 :
memcpy ( F_24 ( V_6 ) , V_263 ,
F_149 ( V_263 ) ) ;
memcpy ( F_25 ( V_6 ) , V_265 ,
F_149 ( V_265 ) ) ;
switch ( V_262 -> V_208 ) {
case 0 :
V_2 . V_2 = V_212 ;
V_2 . V_169 . V_195 . V_127 = V_262 -> V_269 ;
V_2 . V_169 . V_195 . V_125 = V_262 -> V_270 ;
break;
case - V_271 :
case - V_272 :
V_2 . V_2 = V_226 ;
break;
case - V_209 :
V_2 . V_2 = V_207 ;
break;
default:
V_2 . V_2 = V_211 ;
break;
}
break;
case V_273 :
V_2 . V_2 = V_212 ;
V_2 . V_169 . V_195 . V_127 = V_262 -> V_269 ;
V_2 . V_169 . V_195 . V_125 = V_262 -> V_270 ;
break;
default:
F_73 ( 1 ) ;
}
V_2 . V_208 = V_262 -> V_208 ;
V_2 . V_169 . V_195 . V_173 = V_262 -> V_173 ;
V_2 . V_169 . V_195 . V_196 = V_262 -> V_196 ;
V_10 = V_6 -> V_22 . V_84 ( & V_6 -> V_22 , & V_2 ) ;
if ( V_10 ) {
V_6 -> V_135 . V_137 = NULL ;
F_7 ( V_6 , V_187 ) ;
F_23 ( & V_6 -> V_82 ) ;
F_115 ( & V_6 -> V_22 ) ;
return V_10 ;
}
F_23 ( & V_6 -> V_82 ) ;
return V_10 ;
}
static int F_150 ( struct V_259 * V_135 ,
struct V_261 * V_262 )
{
struct V_83 * V_274 ;
struct V_5 * V_152 , * V_238 ;
struct V_192 V_2 ;
int V_10 ;
struct V_275 V_276 ;
struct V_37 * V_263 = (struct V_37 * ) & V_262 -> V_264 ;
struct V_37 * V_265 = (struct V_37 * ) & V_262 -> V_266 ;
V_152 = V_135 -> V_85 ;
if ( F_50 ( V_152 , V_182 ) )
return - V_239 ;
V_274 = F_51 ( V_152 -> V_22 . V_84 ,
V_152 -> V_22 . V_85 ,
V_277 , V_278 ) ;
if ( F_67 ( V_274 ) ) {
V_10 = - V_90 ;
goto V_71;
}
V_238 = F_18 ( V_274 , struct V_5 , V_22 ) ;
F_143 ( & V_238 -> V_82 , V_244 ) ;
V_238 -> V_12 = V_203 ;
V_10 = F_36 ( V_263 , & V_238 -> V_22 . V_24 . V_25 . V_26 , NULL ) ;
if ( V_10 ) {
F_23 ( & V_238 -> V_82 ) ;
F_115 ( V_274 ) ;
goto V_71;
}
V_10 = F_40 ( V_238 , V_152 ) ;
if ( V_10 ) {
F_23 ( & V_238 -> V_82 ) ;
F_115 ( V_274 ) ;
goto V_71;
}
V_238 -> V_135 . V_137 = V_135 ;
V_135 -> V_85 = V_238 ;
V_135 -> V_246 = F_148 ;
memcpy ( F_24 ( V_238 ) , V_263 , F_149 ( V_263 ) ) ;
memcpy ( F_25 ( V_238 ) , V_265 , F_149 ( V_265 ) ) ;
V_10 = F_151 ( V_238 -> V_22 . V_23 , & V_276 ) ;
if ( V_10 ) {
F_23 ( & V_238 -> V_82 ) ;
F_115 ( V_274 ) ;
goto V_71;
}
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_240 ;
V_2 . V_169 . V_195 . V_173 = V_262 -> V_173 ;
V_2 . V_169 . V_195 . V_196 = V_262 -> V_196 ;
V_2 . V_169 . V_195 . V_127 = V_262 -> V_269 ;
V_2 . V_169 . V_195 . V_125 = V_262 -> V_270 ;
F_11 ( & V_238 -> V_21 ) ;
V_10 = V_238 -> V_22 . V_84 ( & V_238 -> V_22 , & V_2 ) ;
if ( V_10 ) {
V_238 -> V_135 . V_137 = NULL ;
F_7 ( V_238 , V_187 ) ;
F_23 ( & V_238 -> V_82 ) ;
F_49 ( V_238 ) ;
F_115 ( & V_238 -> V_22 ) ;
goto V_71;
}
F_23 ( & V_238 -> V_82 ) ;
F_49 ( V_238 ) ;
V_71:
F_23 ( & V_152 -> V_82 ) ;
return V_10 ;
}
static int F_152 ( struct V_5 * V_6 )
{
struct V_250 V_279 ;
struct V_37 * V_25 ;
struct V_201 * V_22 ;
T_7 V_280 ;
int V_10 ;
V_22 = F_153 ( V_6 -> V_22 . V_23 , F_142 , V_6 ) ;
if ( F_67 ( V_22 ) )
return F_68 ( V_22 ) ;
V_6 -> V_135 . V_36 = V_22 ;
V_25 = F_24 ( V_6 ) ;
V_280 = F_145 ( & V_6 -> V_22 , V_25 ) ;
if ( F_92 ( V_25 ) && ! V_6 -> V_281 )
V_10 = F_154 ( V_6 -> V_135 . V_36 , V_280 , 0 , NULL ) ;
else {
F_146 ( V_6 -> V_22 . V_45 , V_25 , & V_279 ) ;
V_10 = F_154 ( V_6 -> V_135 . V_36 , V_280 , 0 , & V_279 ) ;
}
if ( V_10 ) {
F_126 ( V_6 -> V_135 . V_36 ) ;
V_6 -> V_135 . V_36 = NULL ;
}
return V_10 ;
}
static int F_155 ( struct V_5 * V_6 , int V_282 )
{
int V_10 ;
struct V_259 * V_22 ;
V_22 = F_156 ( V_6 -> V_22 . V_23 ,
F_150 ,
V_6 ) ;
if ( F_67 ( V_22 ) )
return F_68 ( V_22 ) ;
V_22 -> V_283 = V_6 -> V_283 ;
V_6 -> V_135 . V_137 = V_22 ;
memcpy ( & V_6 -> V_135 . V_137 -> V_264 , F_24 ( V_6 ) ,
F_149 ( F_24 ( V_6 ) ) ) ;
V_10 = F_157 ( V_6 -> V_135 . V_137 , V_282 ) ;
if ( V_10 ) {
F_127 ( V_6 -> V_135 . V_137 ) ;
V_6 -> V_135 . V_137 = NULL ;
}
return V_10 ;
}
static int F_158 ( struct V_83 * V_22 ,
struct V_192 * V_2 )
{
struct V_5 * V_6 = V_22 -> V_85 ;
V_22 -> V_85 = V_6 -> V_22 . V_85 ;
V_22 -> V_84 = V_6 -> V_22 . V_84 ;
return V_6 -> V_22 . V_84 ( V_22 , V_2 ) ;
}
static void F_159 ( struct V_5 * V_6 ,
struct V_19 * V_20 )
{
struct V_5 * V_178 ;
struct V_83 * V_22 ;
int V_10 ;
if ( F_26 ( V_6 ) == V_61 && ! F_80 ( V_20 -> V_23 , 1 ) )
return;
V_22 = F_51 ( F_158 , V_6 , V_6 -> V_22 . V_45 ,
V_6 -> V_22 . V_88 ) ;
if ( F_67 ( V_22 ) )
return;
V_178 = F_18 ( V_22 , struct V_5 , V_22 ) ;
V_178 -> V_12 = V_284 ;
memcpy ( F_24 ( V_178 ) , F_24 ( V_6 ) ,
F_149 ( F_24 ( V_6 ) ) ) ;
F_10 ( V_178 , V_20 ) ;
F_13 ( & V_178 -> V_95 , & V_6 -> V_95 ) ;
F_11 ( & V_6 -> V_21 ) ;
V_178 -> V_188 = 1 ;
V_178 -> V_281 = V_6 -> V_281 ;
V_10 = F_160 ( V_22 , V_6 -> V_282 ) ;
if ( V_10 )
F_134 ( V_285 L_3
L_4 , V_10 , V_20 -> V_23 -> V_286 ) ;
}
static void F_161 ( struct V_5 * V_6 )
{
struct V_19 * V_20 ;
F_21 ( & V_11 ) ;
F_13 ( & V_6 -> V_29 , & V_287 ) ;
F_44 (cma_dev, &dev_list, list)
F_159 ( V_6 , V_20 ) ;
F_23 ( & V_11 ) ;
}
void F_162 ( struct V_83 * V_22 , int V_283 )
{
struct V_5 * V_6 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
V_6 -> V_283 = ( T_2 ) V_283 ;
}
static void F_163 ( int V_208 , struct V_153 * V_189 ,
void * V_85 )
{
struct V_288 * V_289 = V_85 ;
struct V_229 * V_24 ;
V_24 = & V_289 -> V_22 -> V_22 . V_24 ;
if ( ! V_208 ) {
V_24 -> V_231 = 1 ;
* V_24 -> V_189 = * V_189 ;
} else {
V_289 -> V_290 = V_181 ;
V_289 -> V_291 = V_292 ;
V_289 -> V_2 . V_2 = V_293 ;
V_289 -> V_2 . V_208 = V_208 ;
}
F_164 ( V_294 , & V_289 -> V_289 ) ;
}
static int F_165 ( struct V_5 * V_6 , int V_295 ,
struct V_288 * V_289 )
{
struct V_54 * V_26 = & V_6 -> V_22 . V_24 . V_25 . V_26 ;
struct V_153 V_189 ;
T_9 V_296 ;
struct V_144 * V_297 ;
struct V_52 * V_53 ;
memset ( & V_189 , 0 , sizeof V_189 ) ;
F_166 ( V_26 , & V_189 . V_74 ) ;
F_167 ( V_26 , & V_189 . V_75 ) ;
V_189 . V_76 = F_168 ( F_79 ( V_26 ) ) ;
V_189 . V_298 = 1 ;
V_189 . V_299 = 1 ;
V_189 . V_300 = F_145 ( & V_6 -> V_22 , F_25 ( V_6 ) ) ;
V_296 = V_301 | V_302 |
V_303 | V_304 |
V_305 | V_306 ;
switch ( F_26 ( V_6 ) ) {
case V_139 :
V_189 . V_307 = F_168 ( ( T_4 ) V_6 -> V_283 ) ;
V_296 |= V_308 ;
break;
case V_143 :
V_297 = (struct V_144 * ) F_24 ( V_6 ) ;
V_189 . V_309 = ( T_2 ) ( F_30 ( V_297 -> V_310 ) >> 20 ) ;
V_296 |= V_311 ;
break;
case V_61 :
V_53 = (struct V_52 * ) F_24 ( V_6 ) ;
V_189 . V_309 = ( T_2 ) ( F_30 ( V_53 -> V_157 ) >> 20 ) ;
V_296 |= V_311 ;
break;
}
V_6 -> V_177 = F_169 ( & V_312 , V_6 -> V_22 . V_23 ,
V_6 -> V_22 . V_51 , & V_189 ,
V_296 , V_295 ,
V_89 , F_163 ,
V_289 , & V_6 -> V_176 ) ;
return ( V_6 -> V_177 < 0 ) ? V_6 -> V_177 : 0 ;
}
static void F_170 ( struct V_313 * V_314 )
{
struct V_288 * V_289 = F_18 ( V_314 , struct V_288 , V_289 ) ;
struct V_5 * V_6 = V_289 -> V_22 ;
int V_315 = 0 ;
F_21 ( & V_6 -> V_82 ) ;
if ( ! F_6 ( V_6 , V_289 -> V_290 , V_289 -> V_291 ) )
goto V_71;
if ( V_6 -> V_22 . V_84 ( & V_6 -> V_22 , & V_289 -> V_2 ) ) {
F_7 ( V_6 , V_187 ) ;
V_315 = 1 ;
}
V_71:
F_23 ( & V_6 -> V_82 ) ;
F_49 ( V_6 ) ;
if ( V_315 )
F_115 ( & V_6 -> V_22 ) ;
F_19 ( V_289 ) ;
}
static void F_171 ( struct V_313 * V_314 )
{
struct V_316 * V_289 = F_18 ( V_314 , struct V_316 , V_289 ) ;
struct V_5 * V_6 = V_289 -> V_22 ;
int V_315 = 0 ;
F_21 ( & V_6 -> V_82 ) ;
if ( V_6 -> V_12 == V_187 ||
V_6 -> V_12 == V_317 )
goto V_71;
if ( V_6 -> V_22 . V_84 ( & V_6 -> V_22 , & V_289 -> V_2 ) ) {
F_7 ( V_6 , V_187 ) ;
V_315 = 1 ;
}
V_71:
F_23 ( & V_6 -> V_82 ) ;
F_49 ( V_6 ) ;
if ( V_315 )
F_115 ( & V_6 -> V_22 ) ;
F_19 ( V_289 ) ;
}
static int F_172 ( struct V_5 * V_6 , int V_295 )
{
struct V_229 * V_24 = & V_6 -> V_22 . V_24 ;
struct V_288 * V_289 ;
int V_10 ;
V_289 = F_52 ( sizeof *V_289 , V_89 ) ;
if ( ! V_289 )
return - V_90 ;
V_289 -> V_22 = V_6 ;
F_173 ( & V_289 -> V_289 , F_170 ) ;
V_289 -> V_290 = V_181 ;
V_289 -> V_291 = V_318 ;
V_289 -> V_2 . V_2 = V_319 ;
V_24 -> V_189 = F_136 ( sizeof * V_24 -> V_189 , V_89 ) ;
if ( ! V_24 -> V_189 ) {
V_10 = - V_90 ;
goto V_243;
}
V_10 = F_165 ( V_6 , V_295 , V_289 ) ;
if ( V_10 )
goto V_245;
return 0 ;
V_245:
F_19 ( V_24 -> V_189 ) ;
V_24 -> V_189 = NULL ;
V_243:
F_19 ( V_289 ) ;
return V_10 ;
}
int F_174 ( struct V_83 * V_22 ,
struct V_153 * V_189 , int V_231 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( ! F_6 ( V_6 , V_292 ,
V_318 ) )
return - V_44 ;
V_22 -> V_24 . V_189 = F_175 ( V_189 , sizeof *V_189 * V_231 ,
V_89 ) ;
if ( ! V_22 -> V_24 . V_189 ) {
V_10 = - V_90 ;
goto V_115;
}
V_22 -> V_24 . V_231 = V_231 ;
return 0 ;
V_115:
F_6 ( V_6 , V_318 , V_292 ) ;
return V_10 ;
}
static int F_176 ( struct V_5 * V_6 , int V_295 )
{
struct V_288 * V_289 ;
V_289 = F_52 ( sizeof *V_289 , V_89 ) ;
if ( ! V_289 )
return - V_90 ;
V_289 -> V_22 = V_6 ;
F_173 ( & V_289 -> V_289 , F_170 ) ;
V_289 -> V_290 = V_181 ;
V_289 -> V_291 = V_318 ;
V_289 -> V_2 . V_2 = V_319 ;
F_164 ( V_294 , & V_289 -> V_289 ) ;
return 0 ;
}
static int F_177 ( struct V_320 * V_321 , int V_283 )
{
int V_322 ;
struct V_320 * V_323 ;
V_322 = F_178 ( V_283 ) ;
V_323 = V_321 -> V_324 & V_325 ?
F_179 ( V_321 ) : V_321 ;
if ( V_323 -> V_326 )
return F_180 ( V_323 , V_322 ) ;
#if F_181 ( V_327 )
if ( V_321 -> V_324 & V_325 )
return ( F_182 ( V_321 , V_322 ) &
V_328 ) >> V_329 ;
#endif
return 0 ;
}
static int F_183 ( struct V_5 * V_6 )
{
struct V_229 * V_24 = & V_6 -> V_22 . V_24 ;
struct V_330 * V_25 = & V_24 -> V_25 ;
struct V_288 * V_289 ;
int V_10 ;
struct V_320 * V_321 = NULL ;
V_289 = F_52 ( sizeof *V_289 , V_89 ) ;
if ( ! V_289 )
return - V_90 ;
V_289 -> V_22 = V_6 ;
F_173 ( & V_289 -> V_289 , F_170 ) ;
V_24 -> V_189 = F_52 ( sizeof * V_24 -> V_189 , V_89 ) ;
if ( ! V_24 -> V_189 ) {
V_10 = - V_90 ;
goto V_243;
}
V_24 -> V_231 = 1 ;
if ( V_25 -> V_26 . V_331 )
V_321 = F_184 ( & V_332 , V_25 -> V_26 . V_331 ) ;
if ( ! V_321 ) {
V_10 = - V_66 ;
goto V_245;
}
V_24 -> V_189 -> V_333 = F_185 ( V_321 ) ;
memcpy ( V_24 -> V_189 -> V_334 , V_25 -> V_26 . V_335 , V_336 ) ;
memcpy ( V_24 -> V_189 -> V_123 , V_321 -> V_26 , V_321 -> V_337 ) ;
F_41 ( (struct V_37 * ) & V_6 -> V_22 . V_24 . V_25 . V_38 ,
& V_24 -> V_189 -> V_74 ) ;
F_41 ( (struct V_37 * ) & V_6 -> V_22 . V_24 . V_25 . V_39 ,
& V_24 -> V_189 -> V_75 ) ;
V_24 -> V_189 -> V_338 = 1 ;
V_24 -> V_189 -> V_299 = 1 ;
V_24 -> V_189 -> V_76 = F_168 ( 0xffff ) ;
V_24 -> V_189 -> V_339 = V_340 ;
V_24 -> V_189 -> V_341 = F_177 ( V_321 , V_6 -> V_283 ) ;
V_24 -> V_189 -> V_342 = F_186 ( V_321 -> V_342 ) ;
V_24 -> V_189 -> V_343 = V_340 ;
V_24 -> V_189 -> V_344 = F_187 ( V_321 ) ;
F_188 ( V_321 ) ;
V_24 -> V_189 -> V_345 = V_340 ;
V_24 -> V_189 -> V_346 = V_347 ;
if ( ! V_24 -> V_189 -> V_342 ) {
V_10 = - V_44 ;
goto V_245;
}
V_289 -> V_290 = V_181 ;
V_289 -> V_291 = V_318 ;
V_289 -> V_2 . V_2 = V_319 ;
V_289 -> V_2 . V_208 = 0 ;
F_164 ( V_294 , & V_289 -> V_289 ) ;
return 0 ;
V_245:
F_19 ( V_24 -> V_189 ) ;
V_24 -> V_189 = NULL ;
V_243:
F_19 ( V_289 ) ;
return V_10 ;
}
int F_189 ( struct V_83 * V_22 , int V_295 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( ! F_6 ( V_6 , V_292 , V_181 ) )
return - V_44 ;
F_11 ( & V_6 -> V_21 ) ;
if ( F_109 ( V_22 -> V_23 , V_22 -> V_51 ) )
V_10 = F_172 ( V_6 , V_295 ) ;
else if ( F_43 ( V_22 -> V_23 , V_22 -> V_51 ) )
V_10 = F_183 ( V_6 ) ;
else if ( F_190 ( V_22 -> V_23 , V_22 -> V_51 ) )
V_10 = F_176 ( V_6 , V_295 ) ;
else
V_10 = - V_138 ;
if ( V_10 )
goto V_115;
return 0 ;
V_115:
F_6 ( V_6 , V_181 , V_292 ) ;
F_49 ( V_6 ) ;
return V_10 ;
}
static void F_191 ( struct V_37 * V_25 )
{
switch ( V_25 -> V_60 ) {
case V_139 :
( (struct V_140 * ) V_25 ) -> V_141 . V_142 = F_147 ( V_348 ) ;
break;
case V_143 :
F_192 ( & ( (struct V_144 * ) V_25 ) -> V_145 ,
0 , 0 , 0 , F_147 ( 1 ) ) ;
break;
default:
F_193 ( & ( (struct V_52 * ) V_25 ) -> V_58 ,
0 , 0 , 0 , F_147 ( 1 ) ) ;
break;
}
}
static int F_194 ( struct V_5 * V_6 )
{
struct V_19 * V_20 , * V_73 ;
struct V_349 V_350 ;
union V_57 V_64 ;
T_4 V_76 ;
int V_10 ;
T_2 V_77 ;
V_20 = NULL ;
F_21 ( & V_11 ) ;
F_44 (cur_dev, &dev_list, list) {
if ( F_26 ( V_6 ) == V_61 &&
! F_80 ( V_73 -> V_23 , 1 ) )
continue;
if ( ! V_20 )
V_20 = V_73 ;
for ( V_77 = 1 ; V_77 <= V_73 -> V_23 -> V_72 ; ++ V_77 ) {
if ( ! F_195 ( V_73 -> V_23 , V_77 , & V_350 ) &&
V_350 . V_12 == V_351 ) {
V_20 = V_73 ;
goto V_352;
}
}
}
if ( ! V_20 ) {
V_10 = - V_66 ;
goto V_71;
}
V_77 = 1 ;
V_352:
V_10 = F_48 ( V_20 -> V_23 , V_77 , 0 , & V_64 ) ;
if ( V_10 )
goto V_71;
V_10 = F_196 ( V_20 -> V_23 , V_77 , 0 , & V_76 ) ;
if ( V_10 )
goto V_71;
V_6 -> V_22 . V_24 . V_25 . V_26 . V_55 =
( F_38 ( V_20 -> V_23 , V_77 ) ) ?
V_56 : V_353 ;
F_32 ( & V_6 -> V_22 . V_24 . V_25 . V_26 , & V_64 ) ;
F_33 ( & V_6 -> V_22 . V_24 . V_25 . V_26 , V_76 ) ;
V_6 -> V_22 . V_51 = V_77 ;
F_10 ( V_6 , V_20 ) ;
F_191 ( F_24 ( V_6 ) ) ;
V_71:
F_23 ( & V_11 ) ;
return V_10 ;
}
static void F_197 ( int V_208 , struct V_37 * V_38 ,
struct V_54 * V_26 , void * V_85 )
{
struct V_5 * V_6 = V_85 ;
struct V_192 V_2 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
F_21 ( & V_6 -> V_82 ) ;
if ( ! F_6 ( V_6 , V_180 ,
V_292 ) )
goto V_71;
memcpy ( F_24 ( V_6 ) , V_38 , F_149 ( V_38 ) ) ;
if ( ! V_208 && ! V_6 -> V_20 )
V_208 = F_40 ( V_6 , NULL ) ;
if ( V_208 ) {
if ( ! F_6 ( V_6 , V_292 ,
V_284 ) )
goto V_71;
V_2 . V_2 = V_354 ;
V_2 . V_208 = V_208 ;
} else
V_2 . V_2 = V_355 ;
if ( V_6 -> V_22 . V_84 ( & V_6 -> V_22 , & V_2 ) ) {
F_7 ( V_6 , V_187 ) ;
F_23 ( & V_6 -> V_82 ) ;
F_49 ( V_6 ) ;
F_115 ( & V_6 -> V_22 ) ;
return;
}
V_71:
F_23 ( & V_6 -> V_82 ) ;
F_49 ( V_6 ) ;
}
static int F_198 ( struct V_5 * V_6 )
{
struct V_288 * V_289 ;
union V_57 V_64 ;
int V_10 ;
V_289 = F_52 ( sizeof *V_289 , V_89 ) ;
if ( ! V_289 )
return - V_90 ;
if ( ! V_6 -> V_20 ) {
V_10 = F_194 ( V_6 ) ;
if ( V_10 )
goto V_115;
}
F_166 ( & V_6 -> V_22 . V_24 . V_25 . V_26 , & V_64 ) ;
F_138 ( & V_6 -> V_22 . V_24 . V_25 . V_26 , & V_64 ) ;
V_289 -> V_22 = V_6 ;
F_173 ( & V_289 -> V_289 , F_170 ) ;
V_289 -> V_290 = V_180 ;
V_289 -> V_291 = V_292 ;
V_289 -> V_2 . V_2 = V_355 ;
F_164 ( V_294 , & V_289 -> V_289 ) ;
return 0 ;
V_115:
F_19 ( V_289 ) ;
return V_10 ;
}
static int F_199 ( struct V_5 * V_6 )
{
struct V_288 * V_289 ;
int V_10 ;
V_289 = F_52 ( sizeof *V_289 , V_89 ) ;
if ( ! V_289 )
return - V_90 ;
if ( ! V_6 -> V_20 ) {
V_10 = F_45 ( V_6 ) ;
if ( V_10 )
goto V_115;
}
F_138 ( & V_6 -> V_22 . V_24 . V_25 . V_26 , (union V_57 * )
& ( ( (struct V_52 * ) & V_6 -> V_22 . V_24 . V_25 . V_39 ) -> V_58 ) ) ;
V_289 -> V_22 = V_6 ;
F_173 ( & V_289 -> V_289 , F_170 ) ;
V_289 -> V_290 = V_180 ;
V_289 -> V_291 = V_292 ;
V_289 -> V_2 . V_2 = V_355 ;
F_164 ( V_294 , & V_289 -> V_289 ) ;
return 0 ;
V_115:
F_19 ( V_289 ) ;
return V_10 ;
}
static int F_200 ( struct V_83 * V_22 , struct V_37 * V_38 ,
struct V_37 * V_39 )
{
if ( ! V_38 || ! V_38 -> V_60 ) {
V_38 = (struct V_37 * ) & V_22 -> V_24 . V_25 . V_38 ;
V_38 -> V_60 = V_39 -> V_60 ;
if ( V_39 -> V_60 == V_143 ) {
( (struct V_144 * ) V_38 ) -> V_356 =
( (struct V_144 * ) V_39 ) -> V_356 ;
} else if ( V_39 -> V_60 == V_61 ) {
( (struct V_52 * ) V_38 ) -> V_59 =
( (struct V_52 * ) V_39 ) -> V_59 ;
}
}
return F_201 ( V_22 , V_38 ) ;
}
int F_202 ( struct V_83 * V_22 , struct V_37 * V_38 ,
struct V_37 * V_39 , int V_295 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( V_6 -> V_12 == V_93 ) {
V_10 = F_200 ( V_22 , V_38 , V_39 ) ;
if ( V_10 )
return V_10 ;
}
if ( F_26 ( V_6 ) != V_39 -> V_60 )
return - V_44 ;
if ( ! F_6 ( V_6 , V_284 , V_180 ) )
return - V_44 ;
F_11 ( & V_6 -> V_21 ) ;
memcpy ( F_25 ( V_6 ) , V_39 , F_149 ( V_39 ) ) ;
if ( F_92 ( V_39 ) ) {
V_10 = F_198 ( V_6 ) ;
} else {
if ( V_39 -> V_60 == V_61 ) {
V_10 = F_199 ( V_6 ) ;
} else {
V_10 = F_203 ( & V_357 , F_24 ( V_6 ) ,
V_39 , & V_22 -> V_24 . V_25 . V_26 ,
V_295 , F_197 , V_6 ) ;
}
}
if ( V_10 )
goto V_115;
return 0 ;
V_115:
F_6 ( V_6 , V_180 , V_284 ) ;
F_49 ( V_6 ) ;
return V_10 ;
}
int F_204 ( struct V_83 * V_22 , int V_358 )
{
struct V_5 * V_6 ;
unsigned long V_9 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
F_4 ( & V_6 -> V_11 , V_9 ) ;
if ( V_358 || V_6 -> V_12 == V_93 ) {
V_6 -> V_359 = V_358 ;
V_10 = 0 ;
} else {
V_10 = - V_44 ;
}
F_5 ( & V_6 -> V_11 , V_9 ) ;
return V_10 ;
}
int F_205 ( struct V_83 * V_22 , int V_281 )
{
struct V_5 * V_6 ;
unsigned long V_9 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
F_4 ( & V_6 -> V_11 , V_9 ) ;
if ( V_6 -> V_12 == V_93 || V_6 -> V_12 == V_284 ) {
V_6 -> V_360 |= ( 1 << V_361 ) ;
V_6 -> V_281 = V_281 ;
V_10 = 0 ;
} else {
V_10 = - V_44 ;
}
F_5 ( & V_6 -> V_11 , V_9 ) ;
return V_10 ;
}
static void F_206 ( struct V_183 * V_184 ,
struct V_5 * V_6 )
{
struct V_37 * V_25 ;
struct V_52 * V_53 ;
V_249 V_362 , V_258 ;
T_6 V_63 ;
V_25 = F_24 ( V_6 ) ;
V_63 = F_97 ( V_184 -> V_63 ) ;
switch ( V_25 -> V_60 ) {
case V_139 :
( (struct V_140 * ) V_25 ) -> V_148 = V_63 ;
break;
case V_143 :
( (struct V_144 * ) V_25 ) -> V_149 = V_63 ;
break;
case V_61 :
V_53 = (struct V_52 * ) V_25 ;
V_362 = F_98 ( V_53 -> V_150 ) ;
V_258 = F_98 ( V_53 -> V_151 ) ;
V_53 -> V_150 = F_101 ( ( V_362 & V_258 ) | ( V_249 ) F_34 ( V_63 ) ) ;
V_53 -> V_151 = F_101 ( ~ 0ULL ) ;
break;
}
V_6 -> V_184 = V_184 ;
F_207 ( & V_6 -> V_185 , & V_184 -> V_186 ) ;
}
static int F_208 ( struct V_363 * V_45 , struct V_5 * V_6 ,
unsigned short V_364 )
{
struct V_183 * V_184 ;
int V_10 ;
V_184 = F_52 ( sizeof *V_184 , V_89 ) ;
if ( ! V_184 )
return - V_90 ;
V_10 = F_209 ( V_45 , V_184 , V_364 , V_364 + 1 , V_89 ) ;
if ( V_10 < 0 )
goto V_115;
V_184 -> V_45 = V_45 ;
V_184 -> V_63 = ( unsigned short ) V_10 ;
F_206 ( V_184 , V_6 ) ;
return 0 ;
V_115:
F_19 ( V_184 ) ;
return V_10 == - V_365 ? - V_366 : V_10 ;
}
static int F_210 ( struct V_363 * V_45 , struct V_5 * V_6 )
{
static unsigned int V_367 ;
int V_368 , V_369 , V_370 ;
unsigned int V_371 ;
F_211 ( & V_332 , & V_368 , & V_369 ) ;
V_370 = ( V_369 - V_368 ) + 1 ;
V_371 = F_212 () % V_370 + V_368 ;
V_372:
if ( V_367 != V_371 &&
! F_213 ( V_45 , ( unsigned short ) V_371 ) ) {
int V_10 = F_208 ( V_45 , V_6 , V_371 ) ;
if ( ! V_10 )
V_367 = V_371 ;
if ( V_10 != - V_366 )
return V_10 ;
}
if ( -- V_370 ) {
V_371 ++ ;
if ( ( V_371 < V_368 ) || ( V_371 > V_369 ) )
V_371 = V_368 ;
goto V_372;
}
return - V_366 ;
}
static int F_214 ( struct V_183 * V_184 ,
struct V_5 * V_6 , T_10 V_359 )
{
struct V_5 * V_373 ;
struct V_37 * V_25 , * V_374 ;
V_25 = F_24 ( V_6 ) ;
F_215 (cur_id, &bind_list->owners, node) {
if ( V_6 == V_373 )
continue;
if ( ( V_373 -> V_12 != V_182 ) && V_359 &&
V_373 -> V_359 )
continue;
V_374 = F_24 ( V_373 ) ;
if ( V_6 -> V_281 && V_373 -> V_281 &&
( V_25 -> V_60 != V_374 -> V_60 ) )
continue;
if ( F_92 ( V_25 ) || F_92 ( V_374 ) )
return - V_366 ;
if ( ! F_93 ( V_25 , V_374 ) )
return - V_375 ;
}
return 0 ;
}
static int F_216 ( struct V_363 * V_45 , struct V_5 * V_6 )
{
struct V_183 * V_184 ;
unsigned short V_364 ;
int V_10 ;
V_364 = F_34 ( F_96 ( F_24 ( V_6 ) ) ) ;
if ( V_364 < V_376 && ! F_217 ( V_377 ) )
return - V_378 ;
V_184 = F_213 ( V_45 , V_364 ) ;
if ( ! V_184 ) {
V_10 = F_208 ( V_45 , V_6 , V_364 ) ;
} else {
V_10 = F_214 ( V_184 , V_6 , V_6 -> V_359 ) ;
if ( ! V_10 )
F_206 ( V_184 , V_6 ) ;
}
return V_10 ;
}
static int F_218 ( struct V_5 * V_6 )
{
struct V_183 * V_184 = V_6 -> V_184 ;
int V_10 = 0 ;
F_21 ( & V_11 ) ;
if ( V_184 -> V_186 . V_379 -> V_179 )
V_10 = F_214 ( V_184 , V_6 , 0 ) ;
F_23 ( & V_11 ) ;
return V_10 ;
}
static struct V_363 * F_219 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_22 . V_45 ) {
case V_277 :
return & V_380 ;
case V_46 :
return & V_381 ;
case V_49 :
return & V_382 ;
case V_47 :
return & V_383 ;
default:
return NULL ;
}
}
static struct V_363 * F_220 ( struct V_5 * V_6 )
{
struct V_363 * V_45 = NULL ;
struct V_52 * V_53 ;
V_249 V_384 , V_258 , V_362 ;
V_53 = (struct V_52 * ) F_24 ( V_6 ) ;
V_258 = F_98 ( V_53 -> V_151 ) & V_385 ;
V_362 = F_98 ( V_53 -> V_150 ) & V_258 ;
if ( ( V_6 -> V_22 . V_45 == V_47 ) && ( V_362 == ( V_386 & V_258 ) ) ) {
V_384 = V_386 ;
V_45 = & V_383 ;
} else if ( ( ( V_6 -> V_22 . V_45 == V_47 ) || ( V_6 -> V_22 . V_45 == V_277 ) ) &&
( V_362 == ( V_387 & V_258 ) ) ) {
V_384 = V_387 ;
V_45 = & V_380 ;
} else if ( ( ( V_6 -> V_22 . V_45 == V_47 ) || ( V_6 -> V_22 . V_45 == V_46 ) ) &&
( V_362 == ( V_388 & V_258 ) ) ) {
V_384 = V_388 ;
V_45 = & V_381 ;
}
if ( V_45 ) {
V_53 -> V_150 = F_101 ( V_384 | F_34 ( F_96 ( (struct V_37 * ) V_53 ) ) ) ;
V_53 -> V_151 = F_101 ( V_385 |
F_98 ( V_53 -> V_151 ) ) ;
}
return V_45 ;
}
static int F_221 ( struct V_5 * V_6 )
{
struct V_363 * V_45 ;
int V_10 ;
if ( F_26 ( V_6 ) != V_61 )
V_45 = F_219 ( V_6 ) ;
else
V_45 = F_220 ( V_6 ) ;
if ( ! V_45 )
return - V_389 ;
F_21 ( & V_11 ) ;
if ( F_99 ( F_24 ( V_6 ) ) )
V_10 = F_210 ( V_45 , V_6 ) ;
else
V_10 = F_216 ( V_45 , V_6 ) ;
F_23 ( & V_11 ) ;
return V_10 ;
}
static int F_222 ( struct V_54 * V_26 ,
struct V_37 * V_25 )
{
#if F_181 ( V_390 )
struct V_144 * V_297 ;
if ( V_25 -> V_60 != V_143 )
return 0 ;
V_297 = (struct V_144 * ) V_25 ;
if ( ! ( F_223 ( & V_297 -> V_145 ) & V_391 ) )
return 0 ;
if ( ! V_297 -> V_356 )
return - V_44 ;
V_26 -> V_331 = V_297 -> V_356 ;
#endif
return 0 ;
}
int F_160 ( struct V_83 * V_22 , int V_282 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( V_6 -> V_12 == V_93 ) {
V_22 -> V_24 . V_25 . V_38 . V_40 = V_139 ;
V_10 = F_201 ( V_22 , F_24 ( V_6 ) ) ;
if ( V_10 )
return V_10 ;
}
if ( ! F_6 ( V_6 , V_284 , V_182 ) )
return - V_44 ;
if ( V_6 -> V_359 ) {
V_10 = F_218 ( V_6 ) ;
if ( V_10 )
goto V_115;
}
V_6 -> V_282 = V_282 ;
if ( V_22 -> V_23 ) {
if ( F_80 ( V_22 -> V_23 , 1 ) ) {
V_10 = F_152 ( V_6 ) ;
if ( V_10 )
goto V_115;
} else if ( F_82 ( V_22 -> V_23 , 1 ) ) {
V_10 = F_155 ( V_6 , V_282 ) ;
if ( V_10 )
goto V_115;
} else {
V_10 = - V_138 ;
goto V_115;
}
} else
F_161 ( V_6 ) ;
return 0 ;
V_115:
V_6 -> V_282 = 0 ;
F_6 ( V_6 , V_182 , V_284 ) ;
return V_10 ;
}
int F_201 ( struct V_83 * V_22 , struct V_37 * V_25 )
{
struct V_5 * V_6 ;
int V_10 ;
if ( V_25 -> V_60 != V_139 && V_25 -> V_60 != V_143 &&
V_25 -> V_60 != V_61 )
return - V_392 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( ! F_6 ( V_6 , V_93 , V_284 ) )
return - V_44 ;
V_10 = F_222 ( & V_22 -> V_24 . V_25 . V_26 , V_25 ) ;
if ( V_10 )
goto V_243;
memcpy ( F_24 ( V_6 ) , V_25 , F_149 ( V_25 ) ) ;
if ( ! F_92 ( V_25 ) ) {
V_10 = F_35 ( V_25 , & V_22 -> V_24 . V_25 . V_26 ) ;
if ( V_10 )
goto V_243;
V_10 = F_40 ( V_6 , NULL ) ;
if ( V_10 )
goto V_243;
}
if ( ! ( V_6 -> V_360 & ( 1 << V_361 ) ) ) {
if ( V_25 -> V_60 == V_139 )
V_6 -> V_281 = 1 ;
#if F_181 ( V_390 )
else if ( V_25 -> V_60 == V_143 )
V_6 -> V_281 = V_332 . V_393 . V_394 . V_395 ;
#endif
}
V_10 = F_221 ( V_6 ) ;
if ( V_10 )
goto V_245;
return 0 ;
V_245:
if ( V_6 -> V_20 )
F_20 ( V_6 ) ;
V_243:
F_6 ( V_6 , V_284 , V_93 ) ;
return V_10 ;
}
static int F_224 ( void * V_16 , struct V_5 * V_6 )
{
struct V_15 * V_15 ;
V_15 = V_16 ;
V_15 -> V_174 = V_175 ;
if ( F_26 ( V_6 ) == V_139 ) {
struct V_140 * V_396 , * V_397 ;
V_396 = (struct V_140 * ) F_24 ( V_6 ) ;
V_397 = (struct V_140 * ) F_25 ( V_6 ) ;
F_9 ( V_15 , 4 ) ;
V_15 -> V_38 . V_162 . V_25 = V_396 -> V_141 . V_142 ;
V_15 -> V_39 . V_162 . V_25 = V_397 -> V_141 . V_142 ;
V_15 -> V_63 = V_396 -> V_148 ;
} else if ( F_26 ( V_6 ) == V_143 ) {
struct V_144 * V_398 , * V_399 ;
V_398 = (struct V_144 * ) F_24 ( V_6 ) ;
V_399 = (struct V_144 * ) F_25 ( V_6 ) ;
F_9 ( V_15 , 6 ) ;
V_15 -> V_38 . V_164 = V_398 -> V_145 ;
V_15 -> V_39 . V_164 = V_399 -> V_145 ;
V_15 -> V_63 = V_398 -> V_149 ;
}
return 0 ;
}
static int F_225 ( struct V_201 * V_135 ,
struct V_166 * V_167 )
{
struct V_5 * V_6 = V_135 -> V_85 ;
struct V_192 V_2 ;
struct V_400 * V_401 = & V_167 -> V_169 . V_402 ;
int V_10 = 0 ;
if ( F_50 ( V_6 , V_203 ) )
return 0 ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
switch ( V_167 -> V_2 ) {
case V_403 :
V_2 . V_2 = V_207 ;
V_2 . V_208 = - V_209 ;
break;
case V_404 :
V_2 . V_169 . V_241 . V_173 = V_167 -> V_173 ;
V_2 . V_169 . V_241 . V_196 = V_405 ;
if ( V_401 -> V_208 != V_406 ) {
V_2 . V_2 = V_207 ;
V_2 . V_208 = V_167 -> V_169 . V_402 . V_208 ;
break;
}
V_10 = F_27 ( V_6 , V_401 -> V_41 ) ;
if ( V_10 ) {
V_2 . V_2 = V_354 ;
V_2 . V_208 = V_10 ;
break;
}
F_226 ( V_6 -> V_22 . V_23 , V_6 -> V_22 . V_51 ,
V_6 -> V_22 . V_24 . V_189 ,
& V_2 . V_169 . V_241 . V_120 ) ;
V_2 . V_169 . V_241 . V_116 = V_401 -> V_407 ;
V_2 . V_169 . V_241 . V_41 = V_401 -> V_41 ;
V_2 . V_2 = V_212 ;
V_2 . V_208 = 0 ;
break;
default:
F_134 ( V_228 L_2 ,
V_167 -> V_2 ) ;
goto V_71;
}
V_10 = V_6 -> V_22 . V_84 ( & V_6 -> V_22 , & V_2 ) ;
if ( V_10 ) {
V_6 -> V_135 . V_36 = NULL ;
F_7 ( V_6 , V_187 ) ;
F_23 ( & V_6 -> V_82 ) ;
F_115 ( & V_6 -> V_22 ) ;
return V_10 ;
}
V_71:
F_23 ( & V_6 -> V_82 ) ;
return V_10 ;
}
static int F_227 ( struct V_5 * V_6 ,
struct V_118 * V_119 )
{
struct V_408 V_409 ;
struct V_201 * V_22 ;
void * V_173 ;
int V_235 , V_10 ;
memset ( & V_409 , 0 , sizeof V_409 ) ;
V_235 = F_107 ( V_6 ) ;
V_409 . V_196 = V_235 + V_119 -> V_196 ;
if ( V_409 . V_196 < V_119 -> V_196 )
return - V_44 ;
if ( V_409 . V_196 ) {
V_173 = F_52 ( V_409 . V_196 , V_410 ) ;
if ( ! V_173 )
return - V_90 ;
} else {
V_173 = NULL ;
}
if ( V_119 -> V_173 && V_119 -> V_196 )
memcpy ( V_173 + V_235 , V_119 -> V_173 ,
V_119 -> V_196 ) ;
if ( V_173 ) {
V_10 = F_224 ( V_173 , V_6 ) ;
if ( V_10 )
goto V_71;
V_409 . V_173 = V_173 ;
}
V_22 = F_153 ( V_6 -> V_22 . V_23 , F_225 ,
V_6 ) ;
if ( F_67 ( V_22 ) ) {
V_10 = F_68 ( V_22 ) ;
goto V_71;
}
V_6 -> V_135 . V_36 = V_22 ;
V_409 . V_154 = V_6 -> V_22 . V_24 . V_189 ;
V_409 . V_300 = F_145 ( & V_6 -> V_22 , F_25 ( V_6 ) ) ;
V_409 . V_295 = 1 << ( V_411 - 8 ) ;
V_409 . V_412 = V_413 ;
V_10 = F_228 ( V_6 -> V_135 . V_36 , & V_409 ) ;
if ( V_10 ) {
F_126 ( V_6 -> V_135 . V_36 ) ;
V_6 -> V_135 . V_36 = NULL ;
}
V_71:
F_19 ( V_173 ) ;
return V_10 ;
}
static int F_229 ( struct V_5 * V_6 ,
struct V_118 * V_119 )
{
struct V_414 V_409 ;
struct V_229 * V_24 ;
void * V_173 ;
struct V_201 * V_22 ;
int V_235 , V_10 ;
memset ( & V_409 , 0 , sizeof V_409 ) ;
V_235 = F_107 ( V_6 ) ;
V_409 . V_196 = V_235 + V_119 -> V_196 ;
if ( V_409 . V_196 < V_119 -> V_196 )
return - V_44 ;
if ( V_409 . V_196 ) {
V_173 = F_52 ( V_409 . V_196 , V_410 ) ;
if ( ! V_173 )
return - V_90 ;
} else {
V_173 = NULL ;
}
if ( V_119 -> V_173 && V_119 -> V_196 )
memcpy ( V_173 + V_235 , V_119 -> V_173 ,
V_119 -> V_196 ) ;
V_22 = F_153 ( V_6 -> V_22 . V_23 , F_133 , V_6 ) ;
if ( F_67 ( V_22 ) ) {
V_10 = F_68 ( V_22 ) ;
goto V_71;
}
V_6 -> V_135 . V_36 = V_22 ;
V_24 = & V_6 -> V_22 . V_24 ;
if ( V_173 ) {
V_10 = F_224 ( V_173 , V_6 ) ;
if ( V_10 )
goto V_71;
V_409 . V_173 = V_173 ;
}
V_409 . V_171 = & V_24 -> V_189 [ 0 ] ;
if ( V_24 -> V_231 == 2 )
V_409 . V_232 = & V_24 -> V_189 [ 1 ] ;
V_409 . V_300 = F_145 ( & V_6 -> V_22 , F_25 ( V_6 ) ) ;
V_409 . V_116 = V_6 -> V_116 ;
V_409 . V_88 = V_6 -> V_22 . V_88 ;
V_409 . V_415 = V_6 -> V_97 ;
V_409 . V_125 = V_119 -> V_125 ;
V_409 . V_127 = V_119 -> V_127 ;
V_409 . V_198 = V_119 -> V_198 ;
V_409 . V_237 = F_230 ( T_2 , 7 , V_119 -> V_237 ) ;
V_409 . V_199 = F_230 ( T_2 , 7 , V_119 -> V_199 ) ;
V_409 . V_416 = V_411 ;
V_409 . V_417 = V_411 ;
V_409 . V_412 = V_413 ;
V_409 . V_117 = V_6 -> V_117 ? 1 : 0 ;
V_10 = F_231 ( V_6 -> V_135 . V_36 , & V_409 ) ;
V_71:
if ( V_10 && ! F_67 ( V_22 ) ) {
F_126 ( V_22 ) ;
V_6 -> V_135 . V_36 = NULL ;
}
F_19 ( V_173 ) ;
return V_10 ;
}
static int F_232 ( struct V_5 * V_6 ,
struct V_118 * V_119 )
{
struct V_259 * V_135 ;
int V_10 ;
struct V_418 V_419 ;
V_135 = F_156 ( V_6 -> V_22 . V_23 , F_148 , V_6 ) ;
if ( F_67 ( V_135 ) )
return F_68 ( V_135 ) ;
V_135 -> V_283 = V_6 -> V_283 ;
V_6 -> V_135 . V_137 = V_135 ;
memcpy ( & V_135 -> V_264 , F_24 ( V_6 ) ,
F_149 ( F_24 ( V_6 ) ) ) ;
memcpy ( & V_135 -> V_266 , F_25 ( V_6 ) ,
F_149 ( F_25 ( V_6 ) ) ) ;
V_10 = F_71 ( V_6 , V_119 ) ;
if ( V_10 )
goto V_71;
if ( V_119 ) {
V_419 . V_270 = V_119 -> V_127 ;
V_419 . V_269 = V_119 -> V_125 ;
V_419 . V_173 = V_119 -> V_173 ;
V_419 . V_196 = V_119 -> V_196 ;
V_419 . V_407 = V_6 -> V_22 . V_99 ? V_6 -> V_116 : V_119 -> V_116 ;
} else {
memset ( & V_419 , 0 , sizeof V_419 ) ;
V_419 . V_407 = V_6 -> V_116 ;
}
V_10 = F_233 ( V_135 , & V_419 ) ;
V_71:
if ( V_10 ) {
F_127 ( V_135 ) ;
V_6 -> V_135 . V_137 = NULL ;
}
return V_10 ;
}
int F_234 ( struct V_83 * V_22 , struct V_118 * V_119 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( ! F_6 ( V_6 , V_318 , V_203 ) )
return - V_44 ;
if ( ! V_22 -> V_99 ) {
V_6 -> V_116 = V_119 -> V_116 ;
V_6 -> V_117 = V_119 -> V_117 ;
}
if ( F_80 ( V_22 -> V_23 , V_22 -> V_51 ) ) {
if ( V_22 -> V_88 == V_114 )
V_10 = F_227 ( V_6 , V_119 ) ;
else
V_10 = F_229 ( V_6 , V_119 ) ;
} else if ( F_82 ( V_22 -> V_23 , V_22 -> V_51 ) )
V_10 = F_232 ( V_6 , V_119 ) ;
else
V_10 = - V_138 ;
if ( V_10 )
goto V_115;
return 0 ;
V_115:
F_6 ( V_6 , V_203 , V_318 ) ;
return V_10 ;
}
static int F_235 ( struct V_5 * V_6 ,
struct V_118 * V_119 )
{
struct V_420 V_401 ;
int V_10 ;
V_10 = F_71 ( V_6 , V_119 ) ;
if ( V_10 )
goto V_71;
V_10 = F_75 ( V_6 , V_119 ) ;
if ( V_10 )
goto V_71;
memset ( & V_401 , 0 , sizeof V_401 ) ;
V_401 . V_116 = V_6 -> V_116 ;
V_401 . V_415 = V_6 -> V_97 ;
V_401 . V_173 = V_119 -> V_173 ;
V_401 . V_196 = V_119 -> V_196 ;
V_401 . V_125 = V_119 -> V_125 ;
V_401 . V_127 = V_119 -> V_127 ;
V_401 . V_421 = 0 ;
V_401 . V_198 = V_119 -> V_198 ;
V_401 . V_199 = F_230 ( T_2 , 7 , V_119 -> V_199 ) ;
V_401 . V_117 = V_6 -> V_117 ? 1 : 0 ;
V_10 = F_236 ( V_6 -> V_135 . V_36 , & V_401 ) ;
V_71:
return V_10 ;
}
static int F_237 ( struct V_5 * V_6 ,
struct V_118 * V_119 )
{
struct V_418 V_419 ;
int V_10 ;
V_10 = F_71 ( V_6 , V_119 ) ;
if ( V_10 )
return V_10 ;
V_419 . V_270 = V_119 -> V_127 ;
V_419 . V_269 = V_119 -> V_125 ;
V_419 . V_173 = V_119 -> V_173 ;
V_419 . V_196 = V_119 -> V_196 ;
if ( V_6 -> V_22 . V_99 ) {
V_419 . V_407 = V_6 -> V_116 ;
} else
V_419 . V_407 = V_119 -> V_116 ;
return F_238 ( V_6 -> V_135 . V_137 , & V_419 ) ;
}
static int F_239 ( struct V_5 * V_6 ,
enum V_422 V_208 , T_3 V_41 ,
const void * V_173 , int V_196 )
{
struct V_423 V_401 ;
int V_10 ;
memset ( & V_401 , 0 , sizeof V_401 ) ;
V_401 . V_208 = V_208 ;
if ( V_208 == V_406 ) {
V_10 = F_27 ( V_6 , V_41 ) ;
if ( V_10 )
return V_10 ;
V_401 . V_116 = V_6 -> V_116 ;
V_401 . V_41 = V_6 -> V_41 ;
}
V_401 . V_173 = V_173 ;
V_401 . V_196 = V_196 ;
return F_240 ( V_6 -> V_135 . V_36 , & V_401 ) ;
}
int F_241 ( struct V_83 * V_22 , struct V_118 * V_119 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
V_6 -> V_91 = F_54 ( V_92 ) ;
if ( ! F_3 ( V_6 , V_203 ) )
return - V_44 ;
if ( ! V_22 -> V_99 && V_119 ) {
V_6 -> V_116 = V_119 -> V_116 ;
V_6 -> V_117 = V_119 -> V_117 ;
}
if ( F_80 ( V_22 -> V_23 , V_22 -> V_51 ) ) {
if ( V_22 -> V_88 == V_114 ) {
if ( V_119 )
V_10 = F_239 ( V_6 , V_406 ,
V_119 -> V_41 ,
V_119 -> V_173 ,
V_119 -> V_196 ) ;
else
V_10 = F_239 ( V_6 , V_406 ,
0 , NULL , 0 ) ;
} else {
if ( V_119 )
V_10 = F_235 ( V_6 , V_119 ) ;
else
V_10 = F_129 ( V_6 ) ;
}
} else if ( F_82 ( V_22 -> V_23 , V_22 -> V_51 ) )
V_10 = F_237 ( V_6 , V_119 ) ;
else
V_10 = - V_138 ;
if ( V_10 )
goto V_190;
return 0 ;
V_190:
F_76 ( V_6 ) ;
F_242 ( V_22 , NULL , 0 ) ;
return V_10 ;
}
int F_243 ( struct V_83 * V_22 , enum V_424 V_2 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( ! V_6 -> V_135 . V_36 )
return - V_44 ;
switch ( V_22 -> V_23 -> V_28 ) {
case V_425 :
V_10 = F_244 ( V_6 -> V_135 . V_36 , V_2 ) ;
break;
default:
V_10 = 0 ;
break;
}
return V_10 ;
}
int F_242 ( struct V_83 * V_22 , const void * V_173 ,
T_2 V_196 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( ! V_6 -> V_135 . V_36 )
return - V_44 ;
if ( F_80 ( V_22 -> V_23 , V_22 -> V_51 ) ) {
if ( V_22 -> V_88 == V_114 )
V_10 = F_239 ( V_6 , V_426 , 0 ,
V_173 , V_196 ) ;
else
V_10 = F_131 ( V_6 -> V_135 . V_36 ,
V_191 , NULL ,
0 , V_173 , V_196 ) ;
} else if ( F_82 ( V_22 -> V_23 , V_22 -> V_51 ) ) {
V_10 = F_245 ( V_6 -> V_135 . V_137 ,
V_173 , V_196 ) ;
} else
V_10 = - V_138 ;
return V_10 ;
}
int F_246 ( struct V_83 * V_22 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( ! V_6 -> V_135 . V_36 )
return - V_44 ;
if ( F_80 ( V_22 -> V_23 , V_22 -> V_51 ) ) {
V_10 = F_76 ( V_6 ) ;
if ( V_10 )
goto V_71;
if ( F_247 ( V_6 -> V_135 . V_36 , NULL , 0 ) )
F_248 ( V_6 -> V_135 . V_36 , NULL , 0 ) ;
} else if ( F_82 ( V_22 -> V_23 , V_22 -> V_51 ) ) {
V_10 = F_249 ( V_6 -> V_135 . V_137 , 0 ) ;
} else
V_10 = - V_44 ;
V_71:
return V_10 ;
}
static int F_250 ( int V_208 , struct V_427 * V_35 )
{
struct V_5 * V_6 ;
struct V_32 * V_33 = V_35 -> V_85 ;
struct V_192 V_2 ;
int V_10 ;
V_6 = V_33 -> V_6 ;
if ( F_50 ( V_6 , V_284 ) &&
F_50 ( V_6 , V_292 ) )
return 0 ;
if ( ! V_208 )
V_208 = F_27 ( V_6 , F_30 ( V_35 -> V_43 . V_41 ) ) ;
F_21 ( & V_6 -> V_94 ) ;
if ( ! V_208 && V_6 -> V_22 . V_99 )
V_208 = F_251 ( V_6 -> V_22 . V_99 , & V_35 -> V_43 . V_50 ,
F_137 ( V_35 -> V_43 . V_428 ) ) ;
F_23 ( & V_6 -> V_94 ) ;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_208 = V_208 ;
V_2 . V_169 . V_241 . V_173 = V_33 -> V_85 ;
if ( ! V_208 ) {
V_2 . V_2 = V_429 ;
F_252 ( V_6 -> V_22 . V_23 ,
V_6 -> V_22 . V_51 , & V_35 -> V_43 ,
& V_2 . V_169 . V_241 . V_120 ) ;
V_2 . V_169 . V_241 . V_116 = 0xFFFFFF ;
V_2 . V_169 . V_241 . V_41 = F_30 ( V_35 -> V_43 . V_41 ) ;
} else
V_2 . V_2 = V_430 ;
V_10 = V_6 -> V_22 . V_84 ( & V_6 -> V_22 , & V_2 ) ;
if ( V_10 ) {
F_7 ( V_6 , V_187 ) ;
F_23 ( & V_6 -> V_82 ) ;
F_115 ( & V_6 -> V_22 ) ;
return 0 ;
}
F_23 ( & V_6 -> V_82 ) ;
return 0 ;
}
static void F_253 ( struct V_5 * V_6 ,
struct V_37 * V_25 , union V_57 * V_50 )
{
unsigned char V_431 [ V_432 ] ;
struct V_54 * V_26 = & V_6 -> V_22 . V_24 . V_25 . V_26 ;
struct V_140 * sin = (struct V_140 * ) V_25 ;
struct V_144 * V_297 = (struct V_144 * ) V_25 ;
if ( F_92 ( V_25 ) ) {
memset ( V_50 , 0 , sizeof *V_50 ) ;
} else if ( ( V_25 -> V_60 == V_143 ) &&
( ( F_30 ( V_297 -> V_145 . V_433 [ 0 ] ) & 0xFFF0FFFF ) ==
0xFF10A01B ) ) {
memcpy ( V_50 , & V_297 -> V_145 , sizeof *V_50 ) ;
} else if ( V_25 -> V_60 == V_61 ) {
memcpy ( V_50 , & ( (struct V_52 * ) V_25 ) -> V_58 , sizeof *V_50 ) ;
} else if ( ( V_25 -> V_60 == V_143 ) ) {
F_254 ( & V_297 -> V_145 , V_26 -> V_434 , V_431 ) ;
if ( V_6 -> V_22 . V_45 == V_46 )
V_431 [ 7 ] = 0x01 ;
* V_50 = * (union V_57 * ) ( V_431 + 4 ) ;
} else {
F_255 ( sin -> V_141 . V_142 , V_26 -> V_434 , V_431 ) ;
if ( V_6 -> V_22 . V_45 == V_46 )
V_431 [ 7 ] = 0x01 ;
* V_50 = * (union V_57 * ) ( V_431 + 4 ) ;
}
}
static int F_256 ( struct V_5 * V_6 ,
struct V_32 * V_33 )
{
struct V_42 V_43 ;
struct V_54 * V_26 = & V_6 -> V_22 . V_24 . V_25 . V_26 ;
T_9 V_296 ;
int V_10 ;
F_28 ( V_26 , & V_43 . V_50 ) ;
V_10 = F_29 ( V_6 -> V_22 . V_23 , V_6 -> V_22 . V_51 ,
& V_43 . V_50 , & V_43 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_27 ( V_6 , 0 ) ;
if ( V_10 )
return V_10 ;
F_253 ( V_6 , (struct V_37 * ) & V_33 -> V_25 , & V_43 . V_50 ) ;
V_43 . V_41 = F_257 ( V_6 -> V_41 ) ;
F_166 ( V_26 , & V_43 . V_435 ) ;
V_43 . V_76 = F_168 ( F_79 ( V_26 ) ) ;
V_43 . V_436 = 1 ;
V_296 = V_437 | V_438 |
V_439 | V_440 |
V_441 | V_442 |
V_443 |
V_444 ;
if ( V_6 -> V_22 . V_45 == V_49 )
V_296 |= V_445 |
V_446 |
V_447 |
V_448 |
V_449 ;
V_33 -> V_35 . V_36 = F_258 ( & V_312 , V_6 -> V_22 . V_23 ,
V_6 -> V_22 . V_51 , & V_43 ,
V_296 , V_89 ,
F_250 , V_33 ) ;
return F_259 ( V_33 -> V_35 . V_36 ) ;
}
static void F_260 ( struct V_313 * V_289 )
{
struct V_450 * V_451 = F_18 ( V_289 , struct V_450 , V_289 ) ;
struct V_32 * V_33 = V_451 -> V_33 ;
struct V_427 * V_452 = V_33 -> V_35 . V_36 ;
V_33 -> V_35 . V_36 -> V_85 = V_33 ;
F_250 ( 0 , V_452 ) ;
F_125 ( & V_33 -> V_34 , F_17 ) ;
F_19 ( V_451 ) ;
}
static void F_261 ( struct V_37 * V_25 , union V_57 * V_50 )
{
struct V_140 * sin = (struct V_140 * ) V_25 ;
struct V_144 * V_297 = (struct V_144 * ) V_25 ;
if ( F_92 ( V_25 ) ) {
memset ( V_50 , 0 , sizeof *V_50 ) ;
} else if ( V_25 -> V_60 == V_143 ) {
memcpy ( V_50 , & V_297 -> V_145 , sizeof *V_50 ) ;
} else {
V_50 -> V_453 [ 0 ] = 0xff ;
V_50 -> V_453 [ 1 ] = 0x0e ;
V_50 -> V_453 [ 2 ] = 0 ;
V_50 -> V_453 [ 3 ] = 0 ;
V_50 -> V_453 [ 4 ] = 0 ;
V_50 -> V_453 [ 5 ] = 0 ;
V_50 -> V_453 [ 6 ] = 0 ;
V_50 -> V_453 [ 7 ] = 0 ;
V_50 -> V_453 [ 8 ] = 0 ;
V_50 -> V_453 [ 9 ] = 0 ;
V_50 -> V_453 [ 10 ] = 0xff ;
V_50 -> V_453 [ 11 ] = 0xff ;
* ( T_8 * ) ( & V_50 -> V_453 [ 12 ] ) = sin -> V_141 . V_142 ;
}
}
static int F_262 ( struct V_5 * V_6 ,
struct V_32 * V_33 )
{
struct V_450 * V_289 ;
struct V_54 * V_26 = & V_6 -> V_22 . V_24 . V_25 . V_26 ;
int V_115 ;
struct V_37 * V_25 = (struct V_37 * ) & V_33 -> V_25 ;
struct V_320 * V_321 = NULL ;
if ( F_84 ( (struct V_37 * ) & V_33 -> V_25 ) )
return - V_44 ;
V_289 = F_52 ( sizeof *V_289 , V_89 ) ;
if ( ! V_289 )
return - V_90 ;
V_33 -> V_35 . V_36 = F_52 ( sizeof( struct V_427 ) , V_89 ) ;
if ( ! V_33 -> V_35 . V_36 ) {
V_115 = - V_90 ;
goto V_454;
}
F_261 ( V_25 , & V_33 -> V_35 . V_36 -> V_43 . V_50 ) ;
V_33 -> V_35 . V_36 -> V_43 . V_76 = F_168 ( 0xffff ) ;
if ( V_6 -> V_22 . V_45 == V_46 )
V_33 -> V_35 . V_36 -> V_43 . V_41 = F_257 ( V_48 ) ;
if ( V_26 -> V_331 )
V_321 = F_184 ( & V_332 , V_26 -> V_331 ) ;
if ( ! V_321 ) {
V_115 = - V_66 ;
goto V_455;
}
V_33 -> V_35 . V_36 -> V_43 . V_344 = F_187 ( V_321 ) ;
V_33 -> V_35 . V_36 -> V_43 . V_338 = 1 ;
V_33 -> V_35 . V_36 -> V_43 . V_342 = F_186 ( V_321 -> V_342 ) ;
F_188 ( V_321 ) ;
if ( ! V_33 -> V_35 . V_36 -> V_43 . V_342 ) {
V_115 = - V_44 ;
goto V_455;
}
F_41 ( (struct V_37 * ) & V_6 -> V_22 . V_24 . V_25 . V_38 ,
& V_33 -> V_35 . V_36 -> V_43 . V_435 ) ;
V_289 -> V_22 = V_6 ;
V_289 -> V_33 = V_33 ;
F_173 ( & V_289 -> V_289 , F_260 ) ;
F_263 ( & V_33 -> V_34 ) ;
F_164 ( V_294 , & V_289 -> V_289 ) ;
return 0 ;
V_455:
F_19 ( V_33 -> V_35 . V_36 ) ;
V_454:
F_19 ( V_289 ) ;
return V_115 ;
}
int F_264 ( struct V_83 * V_22 , struct V_37 * V_25 ,
void * V_85 )
{
struct V_5 * V_6 ;
struct V_32 * V_33 ;
int V_10 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
if ( ! F_3 ( V_6 , V_284 ) &&
! F_3 ( V_6 , V_292 ) )
return - V_44 ;
V_33 = F_136 ( sizeof *V_33 , V_89 ) ;
if ( ! V_33 )
return - V_90 ;
memcpy ( & V_33 -> V_25 , V_25 , F_149 ( V_25 ) ) ;
V_33 -> V_85 = V_85 ;
V_33 -> V_6 = V_6 ;
F_265 ( & V_6 -> V_11 ) ;
F_266 ( & V_33 -> V_29 , & V_6 -> V_96 ) ;
F_267 ( & V_6 -> V_11 ) ;
if ( F_43 ( V_22 -> V_23 , V_22 -> V_51 ) ) {
F_268 ( & V_33 -> V_34 ) ;
V_10 = F_262 ( V_6 , V_33 ) ;
} else if ( F_123 ( V_22 -> V_23 , V_22 -> V_51 ) )
V_10 = F_256 ( V_6 , V_33 ) ;
else
V_10 = - V_138 ;
if ( V_10 ) {
F_269 ( & V_6 -> V_11 ) ;
F_22 ( & V_33 -> V_29 ) ;
F_270 ( & V_6 -> V_11 ) ;
F_19 ( V_33 ) ;
}
return V_10 ;
}
void F_271 ( struct V_83 * V_22 , struct V_37 * V_25 )
{
struct V_5 * V_6 ;
struct V_32 * V_33 ;
V_6 = F_18 ( V_22 , struct V_5 , V_22 ) ;
F_269 ( & V_6 -> V_11 ) ;
F_44 (mc, &id_priv->mc_list, list) {
if ( ! memcmp ( & V_33 -> V_25 , V_25 , F_149 ( V_25 ) ) ) {
F_22 ( & V_33 -> V_29 ) ;
F_270 ( & V_6 -> V_11 ) ;
if ( V_22 -> V_99 )
F_272 ( V_22 -> V_99 ,
& V_33 -> V_35 . V_36 -> V_43 . V_50 ,
F_137 ( V_33 -> V_35 . V_36 -> V_43 . V_428 ) ) ;
F_73 ( V_6 -> V_20 -> V_23 != V_22 -> V_23 ) ;
if ( F_123 ( V_22 -> V_23 , V_22 -> V_51 ) ) {
F_124 ( V_33 -> V_35 . V_36 ) ;
F_19 ( V_33 ) ;
} else if ( F_43 ( V_22 -> V_23 , V_22 -> V_51 ) )
F_125 ( & V_33 -> V_34 , F_17 ) ;
return;
}
}
F_270 ( & V_6 -> V_11 ) ;
}
static int F_273 ( struct V_320 * V_321 , struct V_5 * V_6 )
{
struct V_54 * V_26 ;
struct V_316 * V_289 ;
V_26 = & V_6 -> V_22 . V_24 . V_25 . V_26 ;
if ( ( V_26 -> V_331 == V_321 -> V_456 ) &&
memcmp ( V_26 -> V_70 , V_321 -> V_26 , V_321 -> V_337 ) ) {
F_134 ( V_457 L_5 ,
V_321 -> V_286 , & V_6 -> V_22 ) ;
V_289 = F_52 ( sizeof *V_289 , V_89 ) ;
if ( ! V_289 )
return - V_90 ;
F_173 ( & V_289 -> V_289 , F_171 ) ;
V_289 -> V_22 = V_6 ;
V_289 -> V_2 . V_2 = V_458 ;
F_11 ( & V_6 -> V_21 ) ;
F_164 ( V_294 , & V_289 -> V_289 ) ;
}
return 0 ;
}
static int F_274 ( struct V_459 * V_460 , unsigned long V_2 ,
void * V_461 )
{
struct V_320 * V_321 = F_275 ( V_461 ) ;
struct V_19 * V_20 ;
struct V_5 * V_6 ;
int V_10 = V_462 ;
if ( F_276 ( V_321 ) != & V_332 )
return V_462 ;
if ( V_2 != V_463 )
return V_462 ;
if ( ! ( V_321 -> V_9 & V_464 ) || ! ( V_321 -> V_324 & V_465 ) )
return V_462 ;
F_21 ( & V_11 ) ;
F_44 (cma_dev, &dev_list, list)
F_44 (id_priv, &cma_dev->id_list, list) {
V_10 = F_273 ( V_321 , V_6 ) ;
if ( V_10 )
goto V_71;
}
V_71:
F_23 ( & V_11 ) ;
return V_10 ;
}
static void F_277 ( struct V_62 * V_23 )
{
struct V_19 * V_20 ;
struct V_5 * V_6 ;
V_20 = F_136 ( sizeof *V_20 , V_89 ) ;
if ( ! V_20 )
return;
V_20 -> V_23 = V_23 ;
F_57 ( & V_20 -> V_8 ) ;
F_58 ( & V_20 -> V_21 , 1 ) ;
F_59 ( & V_20 -> V_30 ) ;
F_278 ( V_23 , & V_466 , V_20 ) ;
F_21 ( & V_11 ) ;
F_13 ( & V_20 -> V_29 , & V_467 ) ;
F_44 (id_priv, &listen_any_list, list)
F_159 ( V_6 , V_20 ) ;
F_23 ( & V_11 ) ;
}
static int F_279 ( struct V_5 * V_6 )
{
struct V_192 V_2 ;
enum V_7 V_12 ;
int V_10 = 0 ;
V_12 = F_7 ( V_6 , V_317 ) ;
if ( V_12 == V_187 )
return 0 ;
F_116 ( V_6 , V_12 ) ;
F_21 ( & V_6 -> V_82 ) ;
if ( ! F_3 ( V_6 , V_317 ) )
goto V_71;
memset ( & V_2 , 0 , sizeof V_2 ) ;
V_2 . V_2 = V_468 ;
V_10 = V_6 -> V_22 . V_84 ( & V_6 -> V_22 , & V_2 ) ;
V_71:
F_23 ( & V_6 -> V_82 ) ;
return V_10 ;
}
static void F_280 ( struct V_19 * V_20 )
{
struct V_5 * V_6 ;
int V_10 ;
F_21 ( & V_11 ) ;
while ( ! F_112 ( & V_20 -> V_30 ) ) {
V_6 = F_113 ( V_20 -> V_30 . V_179 ,
struct V_5 , V_29 ) ;
F_22 ( & V_6 -> V_95 ) ;
F_114 ( & V_6 -> V_29 ) ;
F_11 ( & V_6 -> V_21 ) ;
F_23 ( & V_11 ) ;
V_10 = V_6 -> V_188 ? 1 : F_279 ( V_6 ) ;
F_49 ( V_6 ) ;
if ( V_10 )
F_115 ( & V_6 -> V_22 ) ;
F_21 ( & V_11 ) ;
}
F_23 ( & V_11 ) ;
F_14 ( V_20 ) ;
F_128 ( & V_20 -> V_8 ) ;
}
static void F_281 ( struct V_62 * V_23 )
{
struct V_19 * V_20 ;
V_20 = F_282 ( V_23 , & V_466 ) ;
if ( ! V_20 )
return;
F_21 ( & V_11 ) ;
F_22 ( & V_20 -> V_29 ) ;
F_23 ( & V_11 ) ;
F_280 ( V_20 ) ;
F_19 ( V_20 ) ;
}
static int F_283 ( struct V_469 * V_470 , struct V_471 * V_472 )
{
struct V_473 * V_474 ;
struct V_475 * V_476 ;
struct V_5 * V_6 ;
struct V_83 * V_22 = NULL ;
struct V_19 * V_20 ;
int V_477 = 0 , V_478 = 0 ;
F_21 ( & V_11 ) ;
F_44 (cma_dev, &dev_list, list) {
if ( V_477 < V_472 -> args [ 0 ] ) {
V_477 ++ ;
continue;
}
V_478 = 0 ;
F_44 (id_priv, &cma_dev->id_list, list) {
if ( V_478 < V_472 -> args [ 1 ] ) {
V_478 ++ ;
continue;
}
V_476 = F_284 ( V_470 , & V_474 , V_472 -> V_474 -> V_479 ,
sizeof *V_476 , V_480 ,
V_481 ,
V_482 ) ;
if ( ! V_476 )
goto V_71;
memset ( V_476 , 0 , sizeof *V_476 ) ;
V_22 = & V_6 -> V_22 ;
V_476 -> V_28 = V_22 -> V_24 . V_25 . V_26 . V_55 ;
V_476 -> V_51 = V_22 -> V_51 ;
V_476 -> V_331 =
V_22 -> V_24 . V_25 . V_26 . V_331 ;
if ( F_285 ( V_470 , V_474 ,
F_149 ( F_24 ( V_6 ) ) ,
F_24 ( V_6 ) ,
V_483 ) )
goto V_71;
if ( F_285 ( V_470 , V_474 ,
F_149 ( F_24 ( V_6 ) ) ,
F_25 ( V_6 ) ,
V_484 ) )
goto V_71;
V_476 -> V_485 = V_6 -> V_91 ;
V_476 -> V_486 = V_22 -> V_45 ;
V_476 -> V_487 = V_6 -> V_12 ;
V_476 -> V_116 = V_6 -> V_116 ;
V_476 -> V_88 = V_22 -> V_88 ;
V_478 ++ ;
}
V_472 -> args [ 1 ] = 0 ;
V_477 ++ ;
}
V_71:
F_23 ( & V_11 ) ;
V_472 -> args [ 0 ] = V_477 ;
V_472 -> args [ 1 ] = V_478 ;
return V_470 -> V_488 ;
}
static int T_11 F_286 ( void )
{
int V_10 ;
V_294 = F_287 ( L_6 ) ;
if ( ! V_294 )
return - V_90 ;
F_288 ( & V_312 ) ;
F_289 ( & V_357 ) ;
F_290 ( & V_489 ) ;
V_10 = F_291 ( & V_466 ) ;
if ( V_10 )
goto V_115;
if ( F_292 ( V_480 , V_490 , V_491 ) )
F_134 ( V_285 L_7 ) ;
return 0 ;
V_115:
F_293 ( & V_489 ) ;
F_294 ( & V_357 ) ;
F_295 ( & V_312 ) ;
F_296 ( V_294 ) ;
return V_10 ;
}
static void T_12 F_297 ( void )
{
F_298 ( V_480 ) ;
F_299 ( & V_466 ) ;
F_293 ( & V_489 ) ;
F_294 ( & V_357 ) ;
F_295 ( & V_312 ) ;
F_296 ( V_294 ) ;
F_300 ( & V_380 ) ;
F_300 ( & V_381 ) ;
F_300 ( & V_382 ) ;
F_300 ( & V_383 ) ;
}
