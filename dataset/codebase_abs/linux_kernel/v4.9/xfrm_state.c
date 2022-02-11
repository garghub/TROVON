static inline bool F_1 ( struct V_1 T_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) ;
}
static inline unsigned int F_3 ( struct V_4 * V_4 ,
const T_2 * V_5 ,
const T_2 * V_6 ,
T_3 V_7 ,
unsigned short V_8 )
{
return F_4 ( V_5 , V_6 , V_7 , V_8 , V_4 -> V_9 . V_10 ) ;
}
static inline unsigned int F_5 ( struct V_4 * V_4 ,
const T_2 * V_5 ,
const T_2 * V_6 ,
unsigned short V_8 )
{
return F_6 ( V_5 , V_6 , V_8 , V_4 -> V_9 . V_10 ) ;
}
static inline unsigned int
F_7 ( struct V_4 * V_4 , const T_2 * V_5 ,
T_4 V_11 , T_5 V_12 , unsigned short V_8 )
{
return F_8 ( V_5 , V_11 , V_12 , V_8 , V_4 -> V_9 . V_10 ) ;
}
static void F_9 ( struct V_13 * V_14 ,
struct V_13 * V_15 ,
struct V_13 * V_16 ,
struct V_13 * V_17 ,
unsigned int V_18 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
F_10 (x, tmp, list, bydst) {
unsigned int V_21 ;
V_21 = F_4 ( & V_2 -> V_22 . V_5 , & V_2 -> V_23 . V_6 ,
V_2 -> V_23 . V_7 , V_2 -> V_23 . V_8 ,
V_18 ) ;
F_11 ( & V_2 -> V_24 , V_15 + V_21 ) ;
V_21 = F_6 ( & V_2 -> V_22 . V_5 , & V_2 -> V_23 . V_6 ,
V_2 -> V_23 . V_8 ,
V_18 ) ;
F_11 ( & V_2 -> V_25 , V_16 + V_21 ) ;
if ( V_2 -> V_22 . V_11 ) {
V_21 = F_8 ( & V_2 -> V_22 . V_5 , V_2 -> V_22 . V_11 ,
V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ,
V_18 ) ;
F_11 ( & V_2 -> V_26 , V_17 + V_21 ) ;
}
}
}
static unsigned long F_12 ( unsigned int V_10 )
{
return ( ( V_10 + 1 ) << 1 ) * sizeof( struct V_13 ) ;
}
static void F_13 ( struct V_27 * V_28 )
{
struct V_4 * V_4 = F_14 ( V_28 , struct V_4 , V_9 . V_29 ) ;
struct V_13 * V_30 , * V_31 , * V_32 , * V_33 , * V_34 , * V_35 ;
unsigned long V_36 , V_37 ;
unsigned int V_18 , V_38 ;
int V_39 ;
V_36 = F_12 ( V_4 -> V_9 . V_10 ) ;
V_30 = F_15 ( V_36 ) ;
if ( ! V_30 )
return;
V_31 = F_15 ( V_36 ) ;
if ( ! V_31 ) {
F_16 ( V_30 , V_36 ) ;
return;
}
V_32 = F_15 ( V_36 ) ;
if ( ! V_32 ) {
F_16 ( V_30 , V_36 ) ;
F_16 ( V_31 , V_36 ) ;
return;
}
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_18 ( & V_41 ) ;
V_18 = ( V_36 / sizeof( struct V_13 ) ) - 1U ;
V_33 = F_19 ( V_4 -> V_9 . V_42 , V_4 ) ;
for ( V_39 = V_4 -> V_9 . V_10 ; V_39 >= 0 ; V_39 -- )
F_9 ( V_33 + V_39 , V_30 , V_31 , V_32 , V_18 ) ;
V_34 = F_19 ( V_4 -> V_9 . V_43 , V_4 ) ;
V_35 = F_19 ( V_4 -> V_9 . V_44 , V_4 ) ;
V_38 = V_4 -> V_9 . V_10 ;
F_20 ( V_4 -> V_9 . V_42 , V_30 ) ;
F_20 ( V_4 -> V_9 . V_43 , V_31 ) ;
F_20 ( V_4 -> V_9 . V_44 , V_32 ) ;
V_4 -> V_9 . V_10 = V_18 ;
F_21 ( & V_41 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
V_37 = ( V_38 + 1 ) * sizeof( struct V_13 ) ;
F_23 () ;
F_16 ( V_33 , V_37 ) ;
F_16 ( V_34 , V_37 ) ;
F_16 ( V_35 , V_37 ) ;
}
int F_24 ( const struct V_45 * type , unsigned short V_8 )
{
struct V_46 * V_47 = F_25 ( V_8 ) ;
const struct V_45 * * V_48 ;
int V_49 = 0 ;
if ( F_26 ( V_47 == NULL ) )
return - V_50 ;
V_48 = V_47 -> V_51 ;
F_17 ( & V_52 ) ;
if ( F_27 ( V_48 [ type -> V_12 ] == NULL ) )
V_48 [ type -> V_12 ] = type ;
else
V_49 = - V_53 ;
F_22 ( & V_52 ) ;
F_28 ( V_47 ) ;
return V_49 ;
}
int F_29 ( const struct V_45 * type , unsigned short V_8 )
{
struct V_46 * V_47 = F_25 ( V_8 ) ;
const struct V_45 * * V_48 ;
int V_49 = 0 ;
if ( F_26 ( V_47 == NULL ) )
return - V_50 ;
V_48 = V_47 -> V_51 ;
F_17 ( & V_52 ) ;
if ( F_26 ( V_48 [ type -> V_12 ] != type ) )
V_49 = - V_54 ;
else
V_48 [ type -> V_12 ] = NULL ;
F_22 ( & V_52 ) ;
F_28 ( V_47 ) ;
return V_49 ;
}
static const struct V_45 * F_30 ( T_5 V_12 , unsigned short V_8 )
{
struct V_46 * V_47 ;
const struct V_45 * * V_48 ;
const struct V_45 * type ;
int V_55 = 0 ;
V_56:
V_47 = F_25 ( V_8 ) ;
if ( F_26 ( V_47 == NULL ) )
return NULL ;
V_48 = V_47 -> V_51 ;
type = V_48 [ V_12 ] ;
if ( F_26 ( type && ! F_31 ( type -> V_57 ) ) )
type = NULL ;
if ( ! type && ! V_55 ) {
F_28 ( V_47 ) ;
F_32 ( L_1 , V_8 , V_12 ) ;
V_55 = 1 ;
goto V_56;
}
F_28 ( V_47 ) ;
return type ;
}
static void F_33 ( const struct V_45 * type )
{
F_34 ( type -> V_57 ) ;
}
int F_35 ( struct V_58 * V_59 , int V_8 )
{
struct V_46 * V_47 ;
struct V_58 * * V_60 ;
int V_49 ;
if ( F_26 ( V_59 -> V_61 >= V_62 ) )
return - V_63 ;
V_47 = F_25 ( V_8 ) ;
if ( F_26 ( V_47 == NULL ) )
return - V_50 ;
V_49 = - V_53 ;
V_60 = V_47 -> V_64 ;
F_17 ( & V_65 ) ;
if ( V_60 [ V_59 -> V_61 ] )
goto V_66;
V_49 = - V_54 ;
if ( ! F_31 ( V_47 -> V_57 ) )
goto V_66;
V_59 -> V_47 = V_47 ;
V_60 [ V_59 -> V_61 ] = V_59 ;
V_49 = 0 ;
V_66:
F_22 ( & V_65 ) ;
F_28 ( V_47 ) ;
return V_49 ;
}
int F_36 ( struct V_58 * V_59 , int V_8 )
{
struct V_46 * V_47 ;
struct V_58 * * V_60 ;
int V_49 ;
if ( F_26 ( V_59 -> V_61 >= V_62 ) )
return - V_63 ;
V_47 = F_25 ( V_8 ) ;
if ( F_26 ( V_47 == NULL ) )
return - V_50 ;
V_49 = - V_54 ;
V_60 = V_47 -> V_64 ;
F_17 ( & V_65 ) ;
if ( F_27 ( V_60 [ V_59 -> V_61 ] == V_59 ) ) {
V_60 [ V_59 -> V_61 ] = NULL ;
F_34 ( V_59 -> V_47 -> V_57 ) ;
V_49 = 0 ;
}
F_22 ( & V_65 ) ;
F_28 ( V_47 ) ;
return V_49 ;
}
static struct V_58 * F_37 ( unsigned int V_61 , int V_8 )
{
struct V_46 * V_47 ;
struct V_58 * V_59 ;
int V_55 = 0 ;
if ( F_26 ( V_61 >= V_62 ) )
return NULL ;
V_56:
V_47 = F_25 ( V_8 ) ;
if ( F_26 ( V_47 == NULL ) )
return NULL ;
V_59 = V_47 -> V_64 [ V_61 ] ;
if ( F_26 ( V_59 && ! F_31 ( V_59 -> V_57 ) ) )
V_59 = NULL ;
if ( ! V_59 && ! V_55 ) {
F_28 ( V_47 ) ;
F_32 ( L_2 , V_8 , V_61 ) ;
V_55 = 1 ;
goto V_56;
}
F_28 ( V_47 ) ;
return V_59 ;
}
static void F_38 ( struct V_58 * V_59 )
{
F_34 ( V_59 -> V_57 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_67 ) ;
F_41 ( & V_2 -> V_68 ) ;
F_42 ( V_2 -> V_69 ) ;
F_42 ( V_2 -> V_70 ) ;
F_42 ( V_2 -> V_71 ) ;
F_42 ( V_2 -> V_72 ) ;
F_42 ( V_2 -> V_61 ) ;
F_42 ( V_2 -> V_73 ) ;
F_42 ( V_2 -> V_74 ) ;
F_42 ( V_2 -> V_75 ) ;
if ( V_2 -> V_76 )
F_38 ( V_2 -> V_76 ) ;
if ( V_2 -> V_77 )
F_38 ( V_2 -> V_77 ) ;
if ( V_2 -> V_78 )
F_38 ( V_2 -> V_78 ) ;
if ( V_2 -> type ) {
V_2 -> type -> V_79 ( V_2 ) ;
F_33 ( V_2 -> type ) ;
}
F_43 ( V_2 ) ;
F_42 ( V_2 ) ;
}
static void F_44 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
struct V_13 V_80 ;
F_17 ( & V_81 ) ;
F_45 ( & V_82 , & V_80 ) ;
F_22 ( & V_81 ) ;
F_23 () ;
F_10 (x, tmp, &gc_list, gclist)
F_39 ( V_2 ) ;
}
static inline unsigned long F_46 ( long V_83 )
{
if ( V_83 >= ( V_84 - 1 ) / V_85 )
return V_84 - 1 ;
else
return V_83 * V_85 ;
}
static enum V_86 F_47 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_14 ( V_88 , struct V_89 , V_91 ) ;
struct V_1 * V_2 = F_14 ( V_90 , struct V_1 , V_67 ) ;
unsigned long V_92 = F_48 () ;
long V_93 = V_94 ;
int V_95 = 0 ;
int V_49 = 0 ;
F_49 ( & V_2 -> V_96 ) ;
if ( V_2 -> V_97 . V_98 == V_99 )
goto V_66;
if ( V_2 -> V_97 . V_98 == V_100 )
goto V_101;
if ( V_2 -> V_102 . V_103 ) {
long V_104 = V_2 -> V_102 . V_103 +
V_2 -> V_105 . V_106 - V_92 ;
if ( V_104 <= 0 ) {
if ( V_2 -> V_107 & V_108 ) {
V_2 -> V_105 . V_106 = V_92 - V_2 -> V_109 - 1 ;
V_104 = V_2 -> V_102 . V_103 - V_2 -> V_109 ;
} else
goto V_101;
}
if ( V_104 < V_93 )
V_93 = V_104 ;
}
if ( V_2 -> V_102 . V_110 ) {
long V_104 = V_2 -> V_102 . V_110 +
( V_2 -> V_105 . V_111 ? : V_92 ) - V_92 ;
if ( V_104 <= 0 )
goto V_101;
if ( V_104 < V_93 )
V_93 = V_104 ;
}
if ( V_2 -> V_97 . V_112 )
goto V_113;
if ( V_2 -> V_102 . V_114 ) {
long V_104 = V_2 -> V_102 . V_114 +
V_2 -> V_105 . V_106 - V_92 ;
if ( V_104 <= 0 ) {
V_95 = 1 ;
V_2 -> V_107 &= ~ V_108 ;
} else if ( V_104 < V_93 ) {
V_93 = V_104 ;
V_2 -> V_107 |= V_108 ;
V_2 -> V_109 = V_104 ;
}
}
if ( V_2 -> V_102 . V_115 ) {
long V_104 = V_2 -> V_102 . V_115 +
( V_2 -> V_105 . V_111 ? : V_92 ) - V_92 ;
if ( V_104 <= 0 )
V_95 = 1 ;
else if ( V_104 < V_93 )
V_93 = V_104 ;
}
V_2 -> V_97 . V_112 = V_95 ;
if ( V_95 )
F_50 ( V_2 , 0 , 0 ) ;
V_113:
if ( V_93 != V_94 ) {
F_51 ( & V_2 -> V_67 , F_52 ( V_93 , 0 ) , V_116 ) ;
}
goto V_66;
V_101:
if ( V_2 -> V_97 . V_98 == V_117 && V_2 -> V_22 . V_11 == 0 )
V_2 -> V_97 . V_98 = V_100 ;
V_49 = F_53 ( V_2 ) ;
if ( ! V_49 )
F_50 ( V_2 , 1 , 0 ) ;
F_54 ( V_2 , V_49 ? 0 : 1 , true ) ;
V_66:
F_55 ( & V_2 -> V_96 ) ;
return V_118 ;
}
struct V_1 * F_56 ( struct V_4 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_57 ( sizeof( struct V_1 ) , V_119 ) ;
if ( V_2 ) {
F_58 ( & V_2 -> V_120 , V_4 ) ;
F_59 ( & V_2 -> V_3 , 1 ) ;
F_59 ( & V_2 -> V_121 , 0 ) ;
F_60 ( & V_2 -> V_97 . V_122 ) ;
F_61 ( & V_2 -> V_24 ) ;
F_61 ( & V_2 -> V_25 ) ;
F_61 ( & V_2 -> V_26 ) ;
F_62 ( & V_2 -> V_67 , F_47 ,
V_123 , V_124 ) ;
F_63 ( & V_2 -> V_68 , V_125 ,
( unsigned long ) V_2 ) ;
V_2 -> V_105 . V_106 = F_48 () ;
V_2 -> V_102 . V_126 = V_127 ;
V_2 -> V_102 . V_128 = V_127 ;
V_2 -> V_102 . V_129 = V_127 ;
V_2 -> V_102 . V_130 = V_127 ;
V_2 -> V_131 = 0 ;
V_2 -> V_132 = 0 ;
V_2 -> V_76 = NULL ;
V_2 -> V_77 = NULL ;
F_64 ( & V_2 -> V_96 ) ;
}
return V_2 ;
}
void F_65 ( struct V_1 * V_2 )
{
F_66 ( V_2 -> V_97 . V_98 != V_99 ) ;
F_17 ( & V_81 ) ;
F_67 ( & V_2 -> V_133 , & V_82 ) ;
F_22 ( & V_81 ) ;
F_68 ( & V_134 ) ;
}
int F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_120 ( V_2 ) ;
int V_49 = - V_135 ;
if ( V_2 -> V_97 . V_98 != V_99 ) {
V_2 -> V_97 . V_98 = V_99 ;
F_49 ( & V_4 -> V_9 . V_40 ) ;
F_69 ( & V_2 -> V_97 . V_122 ) ;
F_70 ( & V_2 -> V_24 ) ;
F_70 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_22 . V_11 )
F_70 ( & V_2 -> V_26 ) ;
V_4 -> V_9 . V_136 -- ;
F_55 ( & V_4 -> V_9 . V_40 ) ;
F_71 ( V_2 ) ;
V_49 = 0 ;
}
return V_49 ;
}
int F_72 ( struct V_1 * V_2 )
{
int V_49 ;
F_17 ( & V_2 -> V_96 ) ;
V_49 = F_53 ( V_2 ) ;
F_22 ( & V_2 -> V_96 ) ;
return V_49 ;
}
static inline int
F_73 ( struct V_4 * V_4 , T_5 V_12 , bool V_137 )
{
int V_39 , V_49 = 0 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
F_74 (x, net->xfrm.state_bydst+i, bydst) {
if ( F_75 ( V_2 -> V_22 . V_12 , V_12 ) &&
( V_49 = F_76 ( V_2 ) ) != 0 ) {
F_54 ( V_2 , 0 , V_137 ) ;
return V_49 ;
}
}
}
return V_49 ;
}
static inline int
F_73 ( struct V_4 * V_4 , T_5 V_12 , bool V_137 )
{
return 0 ;
}
int F_77 ( struct V_4 * V_4 , T_5 V_12 , bool V_137 )
{
int V_39 , V_49 = 0 , V_138 = 0 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_49 = F_73 ( V_4 , V_12 , V_137 ) ;
if ( V_49 )
goto V_66;
V_49 = - V_135 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
V_139:
F_74 (x, net->xfrm.state_bydst+i, bydst) {
if ( ! F_78 ( V_2 ) &&
F_75 ( V_2 -> V_22 . V_12 , V_12 ) ) {
F_79 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
V_49 = F_72 ( V_2 ) ;
F_54 ( V_2 , V_49 ? 0 : 1 ,
V_137 ) ;
F_71 ( V_2 ) ;
if ( ! V_49 )
V_138 ++ ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
goto V_139;
}
}
}
if ( V_138 )
V_49 = 0 ;
V_66:
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_49 ;
}
void F_80 ( struct V_4 * V_4 , struct V_140 * V_141 )
{
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_141 -> V_142 = V_4 -> V_9 . V_136 ;
V_141 -> V_143 = V_4 -> V_9 . V_10 ;
V_141 -> V_144 = V_145 ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
}
static int
F_81 ( struct V_1 * V_2 , const struct V_146 * V_147 ,
const struct V_148 * V_149 ,
const T_2 * V_5 , const T_2 * V_6 ,
unsigned short V_8 )
{
struct V_46 * V_47 = F_25 ( V_8 ) ;
if ( ! V_47 )
return - 1 ;
V_47 -> V_150 ( & V_2 -> V_151 , V_147 ) ;
if ( V_8 != V_149 -> V_152 ) {
F_28 ( V_47 ) ;
V_47 = F_25 ( V_149 -> V_152 ) ;
if ( ! V_47 )
return - 1 ;
}
V_47 -> V_153 ( V_2 , V_149 , V_5 , V_6 ) ;
F_28 ( V_47 ) ;
return 0 ;
}
static struct V_1 * F_82 ( struct V_4 * V_4 , T_3 V_154 ,
const T_2 * V_5 ,
T_4 V_11 , T_5 V_12 ,
unsigned short V_8 )
{
unsigned int V_21 = F_7 ( V_4 , V_5 , V_11 , V_12 , V_8 ) ;
struct V_1 * V_2 ;
F_83 (x, net->xfrm.state_byspi + h, byspi) {
if ( V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_22 . V_11 != V_11 ||
V_2 -> V_22 . V_12 != V_12 ||
! F_84 ( & V_2 -> V_22 . V_5 , V_5 , V_8 ) )
continue;
if ( ( V_154 & V_2 -> V_154 . V_155 ) != V_2 -> V_154 . V_156 )
continue;
if ( ! F_1 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_85 ( struct V_4 * V_4 , T_3 V_154 ,
const T_2 * V_5 ,
const T_2 * V_6 ,
T_5 V_12 , unsigned short V_8 )
{
unsigned int V_21 = F_5 ( V_4 , V_5 , V_6 , V_8 ) ;
struct V_1 * V_2 ;
F_83 (x, net->xfrm.state_bysrc + h, bysrc) {
if ( V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_22 . V_12 != V_12 ||
! F_84 ( & V_2 -> V_22 . V_5 , V_5 , V_8 ) ||
! F_84 ( & V_2 -> V_23 . V_6 , V_6 , V_8 ) )
continue;
if ( ( V_154 & V_2 -> V_154 . V_155 ) != V_2 -> V_154 . V_156 )
continue;
if ( ! F_1 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static inline struct V_1 *
F_86 ( struct V_1 * V_2 , int V_157 , int V_8 )
{
struct V_4 * V_4 = V_120 ( V_2 ) ;
T_3 V_154 = V_2 -> V_154 . V_156 & V_2 -> V_154 . V_155 ;
if ( V_157 )
return F_82 ( V_4 , V_154 , & V_2 -> V_22 . V_5 ,
V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 , V_8 ) ;
else
return F_85 ( V_4 , V_154 ,
& V_2 -> V_22 . V_5 ,
& V_2 -> V_23 . V_6 ,
V_2 -> V_22 . V_12 , V_8 ) ;
}
static void F_87 ( struct V_4 * V_4 , int V_158 )
{
if ( V_158 &&
( V_4 -> V_9 . V_10 + 1 ) < V_145 &&
V_4 -> V_9 . V_136 > V_4 -> V_9 . V_10 )
F_68 ( & V_4 -> V_9 . V_29 ) ;
}
static void F_88 ( struct V_159 * V_160 , struct V_1 * V_2 ,
const struct V_146 * V_147 , unsigned short V_8 ,
struct V_1 * * V_161 , int * V_162 ,
int * error )
{
if ( V_2 -> V_97 . V_98 == V_163 ) {
if ( ( V_2 -> V_151 . V_8 &&
! F_89 ( & V_2 -> V_151 , V_147 , V_2 -> V_151 . V_8 ) ) ||
! F_90 ( V_2 , V_160 , V_147 ) )
return;
if ( ! * V_161 ||
( * V_161 ) -> V_97 . V_112 > V_2 -> V_97 . V_112 ||
( ( * V_161 ) -> V_97 . V_112 == V_2 -> V_97 . V_112 &&
( * V_161 ) -> V_105 . V_106 < V_2 -> V_105 . V_106 ) )
* V_161 = V_2 ;
} else if ( V_2 -> V_97 . V_98 == V_117 ) {
* V_162 = 1 ;
} else if ( V_2 -> V_97 . V_98 == V_164 ||
V_2 -> V_97 . V_98 == V_100 ) {
if ( F_89 ( & V_2 -> V_151 , V_147 , V_2 -> V_151 . V_8 ) &&
F_90 ( V_2 , V_160 , V_147 ) )
* error = - V_135 ;
}
}
struct V_1 *
F_91 ( const T_2 * V_5 , const T_2 * V_6 ,
const struct V_146 * V_147 , struct V_148 * V_149 ,
struct V_159 * V_160 , int * V_49 ,
unsigned short V_8 )
{
static T_2 V_165 = { } ;
struct V_4 * V_4 = F_92 ( V_160 ) ;
unsigned int V_21 , V_166 ;
struct V_1 * V_2 , * V_167 , * V_168 ;
int V_169 = 0 ;
int error = 0 ;
struct V_1 * V_161 = NULL ;
T_3 V_154 = V_160 -> V_154 . V_156 & V_160 -> V_154 . V_155 ;
unsigned short V_152 = V_149 -> V_152 ;
unsigned int V_170 ;
struct V_171 V_172 ;
V_168 = NULL ;
V_170 = F_93 ( & V_41 ) ;
F_94 () ;
V_21 = F_3 ( V_4 , V_5 , V_6 , V_149 -> V_7 , V_152 ) ;
F_83 (x, net->xfrm.state_bydst + h, bydst) {
if ( V_2 -> V_23 . V_8 == V_152 &&
V_2 -> V_23 . V_7 == V_149 -> V_7 &&
( V_154 & V_2 -> V_154 . V_155 ) == V_2 -> V_154 . V_156 &&
! ( V_2 -> V_23 . V_173 & V_174 ) &&
F_95 ( V_2 , V_5 , V_6 , V_152 ) &&
V_149 -> V_59 == V_2 -> V_23 . V_59 &&
V_149 -> V_22 . V_12 == V_2 -> V_22 . V_12 &&
( V_149 -> V_22 . V_11 == V_2 -> V_22 . V_11 || ! V_149 -> V_22 . V_11 ) )
F_88 ( V_160 , V_2 , V_147 , V_152 ,
& V_161 , & V_169 , & error ) ;
}
if ( V_161 || V_169 )
goto V_175;
V_166 = F_3 ( V_4 , V_5 , & V_165 , V_149 -> V_7 , V_152 ) ;
F_83 (x, net->xfrm.state_bydst + h_wildcard, bydst) {
if ( V_2 -> V_23 . V_8 == V_152 &&
V_2 -> V_23 . V_7 == V_149 -> V_7 &&
( V_154 & V_2 -> V_154 . V_155 ) == V_2 -> V_154 . V_156 &&
! ( V_2 -> V_23 . V_173 & V_174 ) &&
F_84 ( & V_2 -> V_22 . V_5 , V_5 , V_152 ) &&
V_149 -> V_59 == V_2 -> V_23 . V_59 &&
V_149 -> V_22 . V_12 == V_2 -> V_22 . V_12 &&
( V_149 -> V_22 . V_11 == V_2 -> V_22 . V_11 || ! V_149 -> V_22 . V_11 ) )
F_88 ( V_160 , V_2 , V_147 , V_152 ,
& V_161 , & V_169 , & error ) ;
}
V_175:
V_2 = V_161 ;
if ( ! V_2 && ! error && ! V_169 ) {
if ( V_149 -> V_22 . V_11 &&
( V_167 = F_82 ( V_4 , V_154 , V_5 , V_149 -> V_22 . V_11 ,
V_149 -> V_22 . V_12 , V_152 ) ) != NULL ) {
V_168 = V_167 ;
error = - V_53 ;
goto V_66;
}
V_172 . V_4 = V_4 ;
if ( ! F_96 ( & V_172 ) ) {
error = - V_135 ;
goto V_66;
}
V_2 = F_56 ( V_4 ) ;
if ( V_2 == NULL ) {
error = - V_176 ;
goto V_66;
}
F_81 ( V_2 , V_147 , V_149 , V_5 , V_6 , V_8 ) ;
memcpy ( & V_2 -> V_154 , & V_160 -> V_154 , sizeof( V_2 -> V_154 ) ) ;
error = F_97 ( V_2 , V_160 -> V_177 , V_147 -> V_178 ) ;
if ( error ) {
V_2 -> V_97 . V_98 = V_99 ;
V_168 = V_2 ;
V_2 = NULL ;
goto V_66;
}
if ( F_98 ( V_2 , V_149 , V_160 ) == 0 ) {
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 -> V_97 . V_98 = V_117 ;
F_99 ( & V_2 -> V_97 . V_122 , & V_4 -> V_9 . V_179 ) ;
F_11 ( & V_2 -> V_24 , V_4 -> V_9 . V_42 + V_21 ) ;
V_21 = F_5 ( V_4 , V_5 , V_6 , V_152 ) ;
F_11 ( & V_2 -> V_25 , V_4 -> V_9 . V_43 + V_21 ) ;
if ( V_2 -> V_22 . V_11 ) {
V_21 = F_7 ( V_4 , & V_2 -> V_22 . V_5 , V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 , V_152 ) ;
F_11 ( & V_2 -> V_26 , V_4 -> V_9 . V_44 + V_21 ) ;
}
V_2 -> V_102 . V_103 = V_4 -> V_9 . V_180 ;
F_51 ( & V_2 -> V_67 , F_52 ( V_4 -> V_9 . V_180 , 0 ) , V_116 ) ;
V_4 -> V_9 . V_136 ++ ;
F_87 ( V_4 , V_2 -> V_24 . V_93 != NULL ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
} else {
V_2 -> V_97 . V_98 = V_99 ;
V_168 = V_2 ;
V_2 = NULL ;
error = - V_135 ;
}
}
V_66:
if ( V_2 ) {
if ( ! F_1 ( V_2 ) ) {
* V_49 = - V_181 ;
V_2 = NULL ;
}
} else {
* V_49 = V_169 ? - V_181 : error ;
}
F_100 () ;
if ( V_168 )
F_71 ( V_168 ) ;
if ( F_101 ( & V_41 , V_170 ) ) {
* V_49 = - V_181 ;
if ( V_2 ) {
F_71 ( V_2 ) ;
V_2 = NULL ;
}
}
return V_2 ;
}
struct V_1 *
F_102 ( struct V_4 * V_4 , T_3 V_154 ,
T_2 * V_5 , T_2 * V_6 ,
unsigned short V_8 , T_5 V_59 , T_5 V_12 , T_3 V_7 )
{
unsigned int V_21 ;
struct V_1 * V_182 = NULL , * V_2 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_21 = F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 ) ;
F_74 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_8 == V_8 &&
V_2 -> V_23 . V_7 == V_7 &&
( V_154 & V_2 -> V_154 . V_155 ) == V_2 -> V_154 . V_156 &&
! ( V_2 -> V_23 . V_173 & V_174 ) &&
F_95 ( V_2 , V_5 , V_6 , V_8 ) &&
V_59 == V_2 -> V_23 . V_59 &&
V_12 == V_2 -> V_22 . V_12 &&
V_2 -> V_97 . V_98 == V_163 ) {
V_182 = V_2 ;
break;
}
}
if ( V_182 )
F_79 ( V_182 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_182 ;
}
struct V_1 * F_103 ( struct V_4 * V_4 , T_4 V_11 ,
unsigned short V_8 )
{
struct V_1 * V_2 ;
struct V_183 * V_184 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_104 (w, &net->xfrm.state_all, all) {
V_2 = F_14 ( V_184 , struct V_1 , V_97 ) ;
if ( V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_22 . V_11 != V_11 )
continue;
F_79 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
F_22 ( & V_4 -> V_9 . V_40 ) ;
return NULL ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_120 ( V_2 ) ;
unsigned int V_21 ;
F_99 ( & V_2 -> V_97 . V_122 , & V_4 -> V_9 . V_179 ) ;
V_21 = F_3 ( V_4 , & V_2 -> V_22 . V_5 , & V_2 -> V_23 . V_6 ,
V_2 -> V_23 . V_7 , V_2 -> V_23 . V_8 ) ;
F_11 ( & V_2 -> V_24 , V_4 -> V_9 . V_42 + V_21 ) ;
V_21 = F_5 ( V_4 , & V_2 -> V_22 . V_5 , & V_2 -> V_23 . V_6 , V_2 -> V_23 . V_8 ) ;
F_11 ( & V_2 -> V_25 , V_4 -> V_9 . V_43 + V_21 ) ;
if ( V_2 -> V_22 . V_11 ) {
V_21 = F_7 ( V_4 , & V_2 -> V_22 . V_5 , V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 ,
V_2 -> V_23 . V_8 ) ;
F_11 ( & V_2 -> V_26 , V_4 -> V_9 . V_44 + V_21 ) ;
}
F_51 ( & V_2 -> V_67 , F_52 ( 1 , 0 ) , V_116 ) ;
if ( V_2 -> V_131 )
F_106 ( & V_2 -> V_68 , V_185 + V_2 -> V_131 ) ;
V_4 -> V_9 . V_136 ++ ;
F_87 ( V_4 , V_2 -> V_24 . V_93 != NULL ) ;
}
static void F_107 ( struct V_1 * V_186 )
{
struct V_4 * V_4 = V_120 ( V_186 ) ;
unsigned short V_8 = V_186 -> V_23 . V_8 ;
T_3 V_7 = V_186 -> V_23 . V_7 ;
struct V_1 * V_2 ;
unsigned int V_21 ;
T_3 V_154 = V_186 -> V_154 . V_156 & V_186 -> V_154 . V_155 ;
V_21 = F_3 ( V_4 , & V_186 -> V_22 . V_5 , & V_186 -> V_23 . V_6 , V_7 , V_8 ) ;
F_74 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_8 == V_8 &&
V_2 -> V_23 . V_7 == V_7 &&
( V_154 & V_2 -> V_154 . V_155 ) == V_2 -> V_154 . V_156 &&
F_84 ( & V_2 -> V_22 . V_5 , & V_186 -> V_22 . V_5 , V_8 ) &&
F_84 ( & V_2 -> V_23 . V_6 , & V_186 -> V_23 . V_6 , V_8 ) )
V_2 -> V_187 ++ ;
}
}
void F_108 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_120 ( V_2 ) ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_107 ( V_2 ) ;
F_105 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
}
static struct V_1 * F_109 ( struct V_4 * V_4 ,
const struct V_188 * V_155 ,
unsigned short V_8 , T_5 V_59 ,
T_3 V_7 , T_5 V_12 ,
const T_2 * V_5 ,
const T_2 * V_6 ,
int V_189 )
{
unsigned int V_21 = F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 ) ;
struct V_1 * V_2 ;
T_3 V_154 = V_155 -> V_156 & V_155 -> V_155 ;
F_74 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_7 != V_7 ||
V_2 -> V_23 . V_59 != V_59 ||
V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_97 . V_98 != V_117 ||
V_2 -> V_22 . V_11 != 0 ||
V_2 -> V_22 . V_12 != V_12 ||
( V_154 & V_2 -> V_154 . V_155 ) != V_2 -> V_154 . V_156 ||
! F_84 ( & V_2 -> V_22 . V_5 , V_5 , V_8 ) ||
! F_84 ( & V_2 -> V_23 . V_6 , V_6 , V_8 ) )
continue;
F_79 ( V_2 ) ;
return V_2 ;
}
if ( ! V_189 )
return NULL ;
V_2 = F_56 ( V_4 ) ;
if ( F_27 ( V_2 ) ) {
switch ( V_8 ) {
case V_190 :
V_2 -> V_151 . V_5 . V_191 = V_5 -> V_191 ;
V_2 -> V_151 . V_6 . V_191 = V_6 -> V_191 ;
V_2 -> V_151 . V_192 = 32 ;
V_2 -> V_151 . V_193 = 32 ;
V_2 -> V_23 . V_6 . V_191 = V_6 -> V_191 ;
V_2 -> V_22 . V_5 . V_191 = V_5 -> V_191 ;
break;
case V_194 :
V_2 -> V_151 . V_5 . V_195 = V_5 -> V_195 ;
V_2 -> V_151 . V_6 . V_195 = V_6 -> V_195 ;
V_2 -> V_151 . V_192 = 128 ;
V_2 -> V_151 . V_193 = 128 ;
V_2 -> V_23 . V_6 . V_195 = V_6 -> V_195 ;
V_2 -> V_22 . V_5 . V_195 = V_5 -> V_195 ;
break;
}
V_2 -> V_97 . V_98 = V_117 ;
V_2 -> V_22 . V_12 = V_12 ;
V_2 -> V_23 . V_8 = V_8 ;
V_2 -> V_23 . V_59 = V_59 ;
V_2 -> V_23 . V_7 = V_7 ;
V_2 -> V_154 . V_156 = V_155 -> V_156 ;
V_2 -> V_154 . V_155 = V_155 -> V_155 ;
V_2 -> V_102 . V_103 = V_4 -> V_9 . V_180 ;
F_79 ( V_2 ) ;
F_51 ( & V_2 -> V_67 , F_52 ( V_4 -> V_9 . V_180 , 0 ) , V_116 ) ;
F_99 ( & V_2 -> V_97 . V_122 , & V_4 -> V_9 . V_179 ) ;
F_11 ( & V_2 -> V_24 , V_4 -> V_9 . V_42 + V_21 ) ;
V_21 = F_5 ( V_4 , V_5 , V_6 , V_8 ) ;
F_11 ( & V_2 -> V_25 , V_4 -> V_9 . V_43 + V_21 ) ;
V_4 -> V_9 . V_136 ++ ;
F_87 ( V_4 , V_2 -> V_24 . V_93 != NULL ) ;
}
return V_2 ;
}
int F_110 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_120 ( V_2 ) ;
struct V_1 * V_196 , * V_168 ;
int V_8 ;
int V_49 ;
T_3 V_154 = V_2 -> V_154 . V_156 & V_2 -> V_154 . V_155 ;
int V_157 = F_75 ( V_2 -> V_22 . V_12 , V_197 ) ;
V_8 = V_2 -> V_23 . V_8 ;
V_168 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_196 = F_86 ( V_2 , V_157 , V_8 ) ;
if ( V_196 ) {
V_168 = V_196 ;
V_196 = NULL ;
V_49 = - V_53 ;
goto V_66;
}
if ( V_157 && V_2 -> V_97 . V_198 ) {
V_196 = F_111 ( V_4 , V_154 , V_2 -> V_97 . V_198 ) ;
if ( V_196 && ( ( V_196 -> V_22 . V_12 != V_2 -> V_22 . V_12 ) ||
! F_84 ( & V_196 -> V_22 . V_5 , & V_2 -> V_22 . V_5 , V_8 ) ) ) {
V_168 = V_196 ;
V_196 = NULL ;
}
}
if ( V_157 && ! V_196 )
V_196 = F_109 ( V_4 , & V_2 -> V_154 , V_8 , V_2 -> V_23 . V_59 ,
V_2 -> V_23 . V_7 , V_2 -> V_22 . V_12 ,
& V_2 -> V_22 . V_5 , & V_2 -> V_23 . V_6 , 0 ) ;
F_107 ( V_2 ) ;
F_105 ( V_2 ) ;
V_49 = 0 ;
V_66:
F_22 ( & V_4 -> V_9 . V_40 ) ;
if ( V_196 ) {
F_72 ( V_196 ) ;
F_71 ( V_196 ) ;
}
if ( V_168 )
F_71 ( V_168 ) ;
return V_49 ;
}
static struct V_1 * F_112 ( struct V_1 * V_199 )
{
struct V_4 * V_4 = V_120 ( V_199 ) ;
struct V_1 * V_2 = F_56 ( V_4 ) ;
if ( ! V_2 )
goto V_66;
memcpy ( & V_2 -> V_22 , & V_199 -> V_22 , sizeof( V_2 -> V_22 ) ) ;
memcpy ( & V_2 -> V_151 , & V_199 -> V_151 , sizeof( V_2 -> V_151 ) ) ;
memcpy ( & V_2 -> V_102 , & V_199 -> V_102 , sizeof( V_2 -> V_102 ) ) ;
V_2 -> V_23 . V_59 = V_199 -> V_23 . V_59 ;
V_2 -> V_23 . V_200 = V_199 -> V_23 . V_200 ;
V_2 -> V_23 . V_7 = V_199 -> V_23 . V_7 ;
V_2 -> V_23 . V_8 = V_199 -> V_23 . V_8 ;
V_2 -> V_23 . V_6 = V_199 -> V_23 . V_6 ;
if ( V_199 -> V_70 ) {
V_2 -> V_70 = F_113 ( V_199 -> V_70 ) ;
if ( ! V_2 -> V_70 )
goto error;
}
V_2 -> V_23 . V_201 = V_199 -> V_23 . V_201 ;
if ( V_199 -> V_69 ) {
V_2 -> V_69 = F_114 ( V_199 -> V_69 ) ;
if ( ! V_2 -> V_69 )
goto error;
}
if ( V_199 -> V_71 ) {
V_2 -> V_71 = F_115 ( V_199 -> V_71 ) ;
if ( ! V_2 -> V_71 )
goto error;
}
V_2 -> V_23 . V_202 = V_199 -> V_23 . V_202 ;
if ( V_199 -> V_72 ) {
V_2 -> V_72 = F_115 ( V_199 -> V_72 ) ;
if ( ! V_2 -> V_72 )
goto error;
}
V_2 -> V_23 . V_203 = V_199 -> V_23 . V_203 ;
if ( V_199 -> V_61 ) {
V_2 -> V_61 = F_116 ( V_199 -> V_61 , sizeof( * V_2 -> V_61 ) , V_204 ) ;
if ( ! V_2 -> V_61 )
goto error;
}
if ( V_199 -> V_73 ) {
V_2 -> V_73 = F_116 ( V_199 -> V_73 , sizeof( * V_2 -> V_73 ) ,
V_204 ) ;
if ( ! V_2 -> V_73 )
goto error;
}
if ( V_199 -> V_74 ) {
if ( F_117 ( V_2 , V_199 ) )
goto error;
}
memcpy ( & V_2 -> V_154 , & V_199 -> V_154 , sizeof( V_2 -> V_154 ) ) ;
if ( F_118 ( V_2 ) < 0 )
goto error;
V_2 -> V_23 . V_173 = V_199 -> V_23 . V_173 ;
V_2 -> V_23 . V_205 = V_199 -> V_23 . V_205 ;
V_2 -> V_206 = V_199 -> V_206 ;
V_2 -> V_132 = V_199 -> V_132 ;
V_2 -> V_131 = V_199 -> V_131 ;
V_2 -> V_105 . V_106 = V_199 -> V_105 . V_106 ;
V_2 -> V_97 . V_98 = V_199 -> V_97 . V_98 ;
V_2 -> V_97 . V_198 = V_199 -> V_97 . V_198 ;
return V_2 ;
error:
F_71 ( V_2 ) ;
V_66:
return NULL ;
}
struct V_1 * F_119 ( struct V_207 * V_155 , struct V_4 * V_4 )
{
unsigned int V_21 ;
struct V_1 * V_2 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( V_155 -> V_7 ) {
V_21 = F_3 ( V_4 , & V_155 -> V_208 , & V_155 -> V_209 ,
V_155 -> V_7 , V_155 -> V_210 ) ;
F_74 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_59 != V_155 -> V_59 ||
V_2 -> V_22 . V_12 != V_155 -> V_12 )
continue;
if ( V_155 -> V_7 && V_2 -> V_23 . V_7 != V_155 -> V_7 )
continue;
if ( ! F_84 ( & V_2 -> V_22 . V_5 , & V_155 -> V_208 ,
V_155 -> V_210 ) ||
! F_84 ( & V_2 -> V_23 . V_6 , & V_155 -> V_209 ,
V_155 -> V_210 ) )
continue;
F_79 ( V_2 ) ;
break;
}
} else {
V_21 = F_5 ( V_4 , & V_155 -> V_208 , & V_155 -> V_209 ,
V_155 -> V_210 ) ;
F_74 (x, net->xfrm.state_bysrc+h, bysrc) {
if ( V_2 -> V_23 . V_59 != V_155 -> V_59 ||
V_2 -> V_22 . V_12 != V_155 -> V_12 )
continue;
if ( ! F_84 ( & V_2 -> V_22 . V_5 , & V_155 -> V_208 ,
V_155 -> V_210 ) ||
! F_84 ( & V_2 -> V_23 . V_6 , & V_155 -> V_209 ,
V_155 -> V_210 ) )
continue;
F_79 ( V_2 ) ;
break;
}
}
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
struct V_1 * F_120 ( struct V_1 * V_2 ,
struct V_207 * V_155 )
{
struct V_1 * V_211 ;
V_211 = F_112 ( V_2 ) ;
if ( ! V_211 )
return NULL ;
memcpy ( & V_211 -> V_22 . V_5 , & V_155 -> V_212 , sizeof( V_211 -> V_22 . V_5 ) ) ;
memcpy ( & V_211 -> V_23 . V_6 , & V_155 -> V_213 , sizeof( V_211 -> V_23 . V_6 ) ) ;
if ( F_84 ( & V_2 -> V_22 . V_5 , & V_155 -> V_212 , V_155 -> V_214 ) ) {
F_108 ( V_211 ) ;
} else {
if ( F_110 ( V_211 ) < 0 )
goto error;
}
return V_211 ;
error:
F_71 ( V_211 ) ;
return NULL ;
}
int F_121 ( struct V_1 * V_2 )
{
struct V_1 * V_196 , * V_168 ;
int V_49 ;
int V_157 = F_75 ( V_2 -> V_22 . V_12 , V_197 ) ;
struct V_4 * V_4 = V_120 ( V_2 ) ;
V_168 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_196 = F_86 ( V_2 , V_157 , V_2 -> V_23 . V_8 ) ;
V_49 = - V_135 ;
if ( ! V_196 )
goto V_66;
if ( F_78 ( V_196 ) ) {
V_168 = V_196 ;
V_49 = - V_53 ;
goto V_66;
}
if ( V_196 -> V_97 . V_98 == V_117 ) {
F_105 ( V_2 ) ;
V_2 = NULL ;
}
V_49 = 0 ;
V_66:
F_22 ( & V_4 -> V_9 . V_40 ) ;
if ( V_168 )
F_71 ( V_168 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_2 ) {
F_72 ( V_196 ) ;
F_71 ( V_196 ) ;
return 0 ;
}
V_49 = - V_63 ;
F_17 ( & V_196 -> V_96 ) ;
if ( F_27 ( V_196 -> V_97 . V_98 == V_163 ) ) {
if ( V_2 -> V_61 && V_196 -> V_61 )
memcpy ( V_196 -> V_61 , V_2 -> V_61 , sizeof( * V_196 -> V_61 ) ) ;
if ( V_2 -> V_73 && V_196 -> V_73 ) {
memcpy ( V_196 -> V_73 , V_2 -> V_73 , sizeof( * V_196 -> V_73 ) ) ;
}
if ( ! V_157 && memcmp ( & V_196 -> V_151 , & V_2 -> V_151 , sizeof( V_196 -> V_151 ) ) )
memcpy ( & V_196 -> V_151 , & V_2 -> V_151 , sizeof( V_196 -> V_151 ) ) ;
memcpy ( & V_196 -> V_102 , & V_2 -> V_102 , sizeof( V_196 -> V_102 ) ) ;
V_196 -> V_97 . V_112 = 0 ;
F_51 ( & V_196 -> V_67 , F_52 ( 1 , 0 ) , V_116 ) ;
if ( V_196 -> V_105 . V_111 )
F_122 ( V_196 ) ;
V_49 = 0 ;
V_2 -> V_97 . V_98 = V_99 ;
F_123 ( V_2 ) ;
}
F_22 ( & V_196 -> V_96 ) ;
F_71 ( V_196 ) ;
return V_49 ;
}
int F_122 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_105 . V_111 )
V_2 -> V_105 . V_111 = F_48 () ;
if ( V_2 -> V_105 . V_215 >= V_2 -> V_102 . V_129 ||
V_2 -> V_105 . V_216 >= V_2 -> V_102 . V_130 ) {
V_2 -> V_97 . V_98 = V_100 ;
F_51 ( & V_2 -> V_67 , F_52 ( 0 , 0 ) , V_116 ) ;
return - V_63 ;
}
if ( ! V_2 -> V_97 . V_112 &&
( V_2 -> V_105 . V_215 >= V_2 -> V_102 . V_126 ||
V_2 -> V_105 . V_216 >= V_2 -> V_102 . V_128 ) ) {
V_2 -> V_97 . V_112 = 1 ;
F_50 ( V_2 , 0 , 0 ) ;
}
return 0 ;
}
struct V_1 *
F_124 ( struct V_4 * V_4 , T_3 V_154 , const T_2 * V_5 , T_4 V_11 ,
T_5 V_12 , unsigned short V_8 )
{
struct V_1 * V_2 ;
F_94 () ;
V_2 = F_82 ( V_4 , V_154 , V_5 , V_11 , V_12 , V_8 ) ;
F_100 () ;
return V_2 ;
}
struct V_1 *
F_125 ( struct V_4 * V_4 , T_3 V_154 ,
const T_2 * V_5 , const T_2 * V_6 ,
T_5 V_12 , unsigned short V_8 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 = F_85 ( V_4 , V_154 , V_5 , V_6 , V_12 , V_8 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
struct V_1 *
F_126 ( struct V_4 * V_4 , const struct V_188 * V_154 , T_5 V_59 , T_3 V_7 ,
T_5 V_12 , const T_2 * V_5 ,
const T_2 * V_6 , int V_189 , unsigned short V_8 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 = F_109 ( V_4 , V_154 , V_8 , V_59 , V_7 , V_12 , V_5 , V_6 , V_189 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
int
F_127 ( struct V_148 * * V_217 , struct V_148 * * V_218 , int V_219 ,
unsigned short V_8 , struct V_4 * V_4 )
{
int V_49 = 0 ;
struct V_46 * V_47 = F_25 ( V_8 ) ;
if ( ! V_47 )
return - V_50 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( V_47 -> V_220 )
V_49 = V_47 -> V_220 ( V_217 , V_218 , V_219 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
F_28 ( V_47 ) ;
return V_49 ;
}
int
F_128 ( struct V_1 * * V_217 , struct V_1 * * V_218 , int V_219 ,
unsigned short V_8 )
{
int V_49 = 0 ;
struct V_46 * V_47 = F_25 ( V_8 ) ;
struct V_4 * V_4 = V_120 ( * V_218 ) ;
if ( ! V_47 )
return - V_50 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( V_47 -> V_221 )
V_49 = V_47 -> V_221 ( V_217 , V_218 , V_219 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
F_28 ( V_47 ) ;
return V_49 ;
}
static struct V_1 * F_111 ( struct V_4 * V_4 , T_3 V_154 , T_3 V_198 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
F_74 (x, net->xfrm.state_bydst+i, bydst) {
if ( V_2 -> V_97 . V_198 == V_198 &&
( V_154 & V_2 -> V_154 . V_155 ) == V_2 -> V_154 . V_156 &&
V_2 -> V_97 . V_98 == V_117 ) {
F_79 ( V_2 ) ;
return V_2 ;
}
}
}
return NULL ;
}
struct V_1 * F_129 ( struct V_4 * V_4 , T_3 V_154 , T_3 V_198 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 = F_111 ( V_4 , V_154 , V_198 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
T_3 F_130 ( void )
{
T_3 V_222 ;
static T_6 V_223 ;
do {
V_222 = F_131 ( & V_223 ) ;
} while ( ! V_222 );
return V_222 ;
}
int F_132 ( T_5 V_12 , T_3 V_224 , T_3 V_225 )
{
switch ( V_12 ) {
case V_226 :
case V_227 :
break;
case V_228 :
if ( V_225 >= 0x10000 )
return - V_63 ;
break;
default:
return - V_63 ;
}
if ( V_224 > V_225 )
return - V_63 ;
return 0 ;
}
int F_133 ( struct V_1 * V_2 , T_3 V_229 , T_3 V_230 )
{
struct V_4 * V_4 = V_120 ( V_2 ) ;
unsigned int V_21 ;
struct V_1 * V_167 ;
int V_49 = - V_54 ;
T_4 V_231 = F_134 ( V_229 ) ;
T_4 V_232 = F_134 ( V_230 ) ;
T_3 V_154 = V_2 -> V_154 . V_156 & V_2 -> V_154 . V_155 ;
F_17 ( & V_2 -> V_96 ) ;
if ( V_2 -> V_97 . V_98 == V_99 )
goto V_233;
V_49 = 0 ;
if ( V_2 -> V_22 . V_11 )
goto V_233;
V_49 = - V_54 ;
if ( V_231 == V_232 ) {
V_167 = F_124 ( V_4 , V_154 , & V_2 -> V_22 . V_5 , V_231 , V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ) ;
if ( V_167 ) {
F_71 ( V_167 ) ;
goto V_233;
}
V_2 -> V_22 . V_11 = V_231 ;
} else {
T_3 V_11 = 0 ;
for ( V_21 = 0 ; V_21 < V_230 - V_229 + 1 ; V_21 ++ ) {
V_11 = V_229 + F_135 () % ( V_230 - V_229 + 1 ) ;
V_167 = F_124 ( V_4 , V_154 , & V_2 -> V_22 . V_5 , F_134 ( V_11 ) , V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ) ;
if ( V_167 == NULL ) {
V_2 -> V_22 . V_11 = F_134 ( V_11 ) ;
break;
}
F_71 ( V_167 ) ;
}
}
if ( V_2 -> V_22 . V_11 ) {
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_21 = F_7 ( V_4 , & V_2 -> V_22 . V_5 , V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ) ;
F_11 ( & V_2 -> V_26 , V_4 -> V_9 . V_44 + V_21 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
V_49 = 0 ;
}
V_233:
F_22 ( & V_2 -> V_96 ) ;
return V_49 ;
}
static bool F_136 ( struct V_1 * V_2 ,
struct V_234 * V_235 )
{
if ( V_235 ) {
if ( ( V_235 -> V_8 == V_190 ||
V_235 -> V_8 == V_194 ) &&
V_2 -> V_23 . V_8 != V_235 -> V_8 )
return false ;
return F_137 ( & V_2 -> V_23 . V_6 , & V_235 -> V_6 ,
V_235 -> V_236 ) &&
F_137 ( & V_2 -> V_22 . V_5 , & V_235 -> V_5 ,
V_235 -> V_237 ) ;
}
return true ;
}
int V_183 ( struct V_4 * V_4 , struct V_183 * V_238 ,
int (* F_138)( struct V_1 * , int , void * ) ,
void * V_239 )
{
struct V_1 * V_98 ;
struct V_183 * V_2 ;
int V_49 = 0 ;
if ( V_238 -> V_198 != 0 && F_139 ( & V_238 -> V_122 ) )
return 0 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( F_139 ( & V_238 -> V_122 ) )
V_2 = F_140 ( & V_4 -> V_9 . V_179 , struct V_183 , V_122 ) ;
else
V_2 = F_140 ( & V_238 -> V_122 , struct V_183 , V_122 ) ;
F_141 (x, &net->xfrm.state_all, all) {
if ( V_2 -> V_98 == V_99 )
continue;
V_98 = F_14 ( V_2 , struct V_1 , V_97 ) ;
if ( ! F_75 ( V_98 -> V_22 . V_12 , V_238 -> V_12 ) )
continue;
if ( ! F_136 ( V_98 , V_238 -> V_235 ) )
continue;
V_49 = F_138 ( V_98 , V_238 -> V_198 , V_239 ) ;
if ( V_49 ) {
F_142 ( & V_238 -> V_122 , & V_2 -> V_122 ) ;
goto V_66;
}
V_238 -> V_198 ++ ;
}
if ( V_238 -> V_198 == 0 ) {
V_49 = - V_54 ;
goto V_66;
}
F_143 ( & V_238 -> V_122 ) ;
V_66:
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_49 ;
}
void F_144 ( struct V_183 * V_238 , T_5 V_12 ,
struct V_234 * V_235 )
{
F_60 ( & V_238 -> V_122 ) ;
V_238 -> V_12 = V_12 ;
V_238 -> V_98 = V_99 ;
V_238 -> V_198 = 0 ;
V_238 -> V_235 = V_235 ;
}
void F_145 ( struct V_183 * V_238 , struct V_4 * V_4 )
{
F_42 ( V_238 -> V_235 ) ;
if ( F_139 ( & V_238 -> V_122 ) )
return;
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_69 ( & V_238 -> V_122 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
}
static void V_125 ( unsigned long V_239 )
{
struct V_1 * V_2 = (struct V_1 * ) V_239 ;
F_49 ( & V_2 -> V_96 ) ;
if ( V_2 -> V_97 . V_98 == V_163 ) {
if ( F_146 ( V_120 ( V_2 ) ) )
V_2 -> V_240 -> V_241 ( V_2 , V_242 ) ;
else
V_2 -> V_107 |= V_243 ;
}
F_55 ( & V_2 -> V_96 ) ;
}
void F_147 ( struct V_159 * V_244 , int V_245 , const struct V_171 * V_172 )
{
struct V_246 * V_97 ;
F_94 () ;
F_148 (km, &xfrm_km_list, list)
if ( V_97 -> V_247 )
V_97 -> V_247 ( V_244 , V_245 , V_172 ) ;
F_100 () ;
}
void F_149 ( struct V_1 * V_2 , const struct V_171 * V_172 )
{
struct V_246 * V_97 ;
F_94 () ;
F_148 (km, &xfrm_km_list, list)
if ( V_97 -> V_241 )
V_97 -> V_241 ( V_2 , V_172 ) ;
F_100 () ;
}
void F_50 ( struct V_1 * V_2 , int V_248 , T_3 V_249 )
{
struct V_171 V_172 ;
V_172 . V_239 . V_248 = V_248 ;
V_172 . V_249 = V_249 ;
V_172 . V_250 = V_251 ;
F_149 ( V_2 , & V_172 ) ;
}
int F_98 ( struct V_1 * V_2 , struct V_148 * V_252 , struct V_159 * V_160 )
{
int V_49 = - V_63 , V_253 ;
struct V_246 * V_97 ;
F_94 () ;
F_148 (km, &xfrm_km_list, list) {
V_253 = V_97 -> V_254 ( V_2 , V_252 , V_160 ) ;
if ( ! V_253 )
V_49 = V_253 ;
}
F_100 () ;
return V_49 ;
}
int F_150 ( struct V_1 * V_2 , T_2 * V_255 , T_7 V_256 )
{
int V_49 = - V_63 ;
struct V_246 * V_97 ;
F_94 () ;
F_148 (km, &xfrm_km_list, list) {
if ( V_97 -> V_257 )
V_49 = V_97 -> V_257 ( V_2 , V_255 , V_256 ) ;
if ( ! V_49 )
break;
}
F_100 () ;
return V_49 ;
}
void F_151 ( struct V_159 * V_160 , int V_245 , int V_248 , T_3 V_249 )
{
struct V_171 V_172 ;
V_172 . V_239 . V_248 = V_248 ;
V_172 . V_249 = V_249 ;
V_172 . V_250 = V_258 ;
F_147 ( V_160 , V_245 , & V_172 ) ;
}
int F_152 ( const struct V_259 * V_151 , T_5 V_245 , T_5 type ,
const struct V_207 * V_155 , int V_260 ,
const struct V_261 * V_262 )
{
int V_49 = - V_63 ;
int V_263 ;
struct V_246 * V_97 ;
F_94 () ;
F_148 (km, &xfrm_km_list, list) {
if ( V_97 -> V_264 ) {
V_263 = V_97 -> V_264 ( V_151 , V_245 , type , V_155 , V_260 , V_262 ) ;
if ( ! V_263 )
V_49 = V_263 ;
}
}
F_100 () ;
return V_49 ;
}
int F_153 ( struct V_4 * V_4 , T_5 V_12 , struct V_259 * V_151 , T_2 * V_265 )
{
int V_49 = - V_63 ;
int V_263 ;
struct V_246 * V_97 ;
F_94 () ;
F_148 (km, &xfrm_km_list, list) {
if ( V_97 -> V_266 ) {
V_263 = V_97 -> V_266 ( V_4 , V_12 , V_151 , V_265 ) ;
if ( ! V_263 )
V_49 = V_263 ;
}
}
F_100 () ;
return V_49 ;
}
bool F_96 ( const struct V_171 * V_172 )
{
struct V_246 * V_97 ;
bool V_267 = false ;
F_94 () ;
F_148 (km, &xfrm_km_list, list) {
if ( V_97 -> V_267 && V_97 -> V_267 ( V_172 ) ) {
V_267 = true ;
break;
}
}
F_100 () ;
return V_267 ;
}
int F_154 ( struct V_268 * V_269 , int V_270 , T_5 T_8 * V_271 , int V_272 )
{
int V_49 ;
T_5 * V_239 ;
struct V_246 * V_97 ;
struct V_159 * V_160 = NULL ;
if ( V_272 <= 0 || V_272 > V_273 )
return - V_274 ;
V_239 = F_155 ( V_272 , V_204 ) ;
if ( ! V_239 )
return - V_176 ;
V_49 = - V_275 ;
if ( F_156 ( V_239 , V_271 , V_272 ) )
goto V_66;
V_49 = - V_63 ;
F_94 () ;
F_148 (km, &xfrm_km_list, list) {
V_160 = V_97 -> V_276 ( V_269 , V_270 , V_239 ,
V_272 , & V_49 ) ;
if ( V_49 >= 0 )
break;
}
F_100 () ;
if ( V_49 >= 0 ) {
F_157 ( V_269 , V_49 , V_160 ) ;
F_158 ( V_160 ) ;
V_49 = 0 ;
}
V_66:
F_42 ( V_239 ) ;
return V_49 ;
}
int F_159 ( struct V_246 * V_97 )
{
F_17 ( & V_277 ) ;
F_160 ( & V_97 -> V_14 , & V_278 ) ;
F_22 ( & V_277 ) ;
return 0 ;
}
int F_161 ( struct V_246 * V_97 )
{
F_17 ( & V_277 ) ;
F_162 ( & V_97 -> V_14 ) ;
F_22 ( & V_277 ) ;
F_23 () ;
return 0 ;
}
int F_163 ( struct V_46 * V_47 )
{
int V_49 = 0 ;
if ( F_26 ( V_47 == NULL ) )
return - V_63 ;
if ( F_26 ( V_47 -> V_8 >= V_279 ) )
return - V_50 ;
F_17 ( & V_280 ) ;
if ( F_26 ( V_46 [ V_47 -> V_8 ] != NULL ) )
V_49 = - V_53 ;
else
F_20 ( V_46 [ V_47 -> V_8 ] , V_47 ) ;
F_22 ( & V_280 ) ;
return V_49 ;
}
int F_164 ( struct V_46 * V_47 )
{
int V_49 = 0 ;
if ( F_26 ( V_47 == NULL ) )
return - V_63 ;
if ( F_26 ( V_47 -> V_8 >= V_279 ) )
return - V_50 ;
F_17 ( & V_280 ) ;
if ( F_27 ( V_46 [ V_47 -> V_8 ] != NULL ) ) {
if ( F_26 ( V_46 [ V_47 -> V_8 ] != V_47 ) )
V_49 = - V_63 ;
else
F_165 ( V_46 [ V_47 -> V_8 ] , NULL ) ;
}
F_22 ( & V_280 ) ;
F_23 () ;
return V_49 ;
}
struct V_46 * F_25 ( unsigned int V_8 )
{
struct V_46 * V_47 ;
if ( F_26 ( V_8 >= V_279 ) )
return NULL ;
F_94 () ;
V_47 = F_166 ( V_46 [ V_8 ] ) ;
if ( F_26 ( ! V_47 ) )
F_100 () ;
return V_47 ;
}
void F_28 ( struct V_46 * V_47 )
{
F_100 () ;
}
void F_167 ( struct V_1 * V_2 )
{
if ( V_2 -> V_281 ) {
struct V_1 * V_252 = V_2 -> V_281 ;
if ( F_168 ( & V_252 -> V_121 ) == 2 )
F_72 ( V_252 ) ;
F_169 ( & V_252 -> V_121 ) ;
F_71 ( V_252 ) ;
V_2 -> V_281 = NULL ;
}
}
int F_170 ( struct V_1 * V_2 , int V_282 )
{
int V_222 ;
F_17 ( & V_2 -> V_96 ) ;
if ( V_2 -> V_97 . V_98 == V_163 &&
V_2 -> type && V_2 -> type -> V_283 )
V_222 = V_2 -> type -> V_283 ( V_2 , V_282 ) ;
else
V_222 = V_282 - V_2 -> V_23 . V_284 ;
F_22 ( & V_2 -> V_96 ) ;
return V_222 ;
}
int F_171 ( struct V_1 * V_2 , bool V_285 )
{
struct V_46 * V_47 ;
struct V_58 * V_76 ;
int V_8 = V_2 -> V_23 . V_8 ;
int V_49 ;
V_49 = - V_50 ;
V_47 = F_25 ( V_8 ) ;
if ( ! V_47 )
goto error;
V_49 = 0 ;
if ( V_47 -> V_286 )
V_49 = V_47 -> V_286 ( V_2 ) ;
F_28 ( V_47 ) ;
if ( V_49 )
goto error;
V_49 = - V_287 ;
if ( V_2 -> V_151 . V_8 != V_288 ) {
V_76 = F_37 ( V_2 -> V_23 . V_59 , V_2 -> V_151 . V_8 ) ;
if ( V_76 == NULL )
goto error;
if ( ! ( V_76 -> V_173 & V_289 ) &&
V_8 != V_2 -> V_151 . V_8 ) {
F_38 ( V_76 ) ;
goto error;
}
V_2 -> V_76 = V_76 ;
} else {
struct V_58 * V_77 ;
int V_290 = V_190 ;
V_76 = F_37 ( V_2 -> V_23 . V_59 , V_2 -> V_23 . V_8 ) ;
if ( V_76 == NULL )
goto error;
if ( ! ( V_76 -> V_173 & V_289 ) ) {
F_38 ( V_76 ) ;
goto error;
}
V_2 -> V_76 = V_76 ;
if ( V_2 -> V_23 . V_8 == V_190 )
V_290 = V_194 ;
V_77 = F_37 ( V_2 -> V_23 . V_59 , V_290 ) ;
if ( V_77 ) {
if ( V_77 -> V_173 & V_289 )
V_2 -> V_77 = V_77 ;
else
F_38 ( V_77 ) ;
}
}
V_2 -> type = F_30 ( V_2 -> V_22 . V_12 , V_8 ) ;
if ( V_2 -> type == NULL )
goto error;
V_49 = V_2 -> type -> V_291 ( V_2 ) ;
if ( V_49 )
goto error;
V_2 -> V_78 = F_37 ( V_2 -> V_23 . V_59 , V_8 ) ;
if ( V_2 -> V_78 == NULL ) {
V_49 = - V_287 ;
goto error;
}
if ( V_285 ) {
V_49 = F_172 ( V_2 ) ;
if ( V_49 )
goto error;
}
V_2 -> V_97 . V_98 = V_163 ;
error:
return V_49 ;
}
int F_118 ( struct V_1 * V_2 )
{
return F_171 ( V_2 , true ) ;
}
int T_9 F_173 ( struct V_4 * V_4 )
{
unsigned int V_292 ;
F_60 ( & V_4 -> V_9 . V_179 ) ;
V_292 = sizeof( struct V_13 ) * 8 ;
V_4 -> V_9 . V_42 = F_15 ( V_292 ) ;
if ( ! V_4 -> V_9 . V_42 )
goto V_293;
V_4 -> V_9 . V_43 = F_15 ( V_292 ) ;
if ( ! V_4 -> V_9 . V_43 )
goto V_294;
V_4 -> V_9 . V_44 = F_15 ( V_292 ) ;
if ( ! V_4 -> V_9 . V_44 )
goto V_295;
V_4 -> V_9 . V_10 = ( ( V_292 / sizeof( struct V_13 ) ) - 1 ) ;
V_4 -> V_9 . V_136 = 0 ;
F_174 ( & V_4 -> V_9 . V_29 , F_13 ) ;
F_64 ( & V_4 -> V_9 . V_40 ) ;
return 0 ;
V_295:
F_16 ( V_4 -> V_9 . V_43 , V_292 ) ;
V_294:
F_16 ( V_4 -> V_9 . V_42 , V_292 ) ;
V_293:
return - V_176 ;
}
void F_175 ( struct V_4 * V_4 )
{
unsigned int V_292 ;
F_176 ( & V_4 -> V_9 . V_29 ) ;
F_77 ( V_4 , V_197 , false ) ;
F_176 ( & V_134 ) ;
F_66 ( ! F_139 ( & V_4 -> V_9 . V_179 ) ) ;
V_292 = ( V_4 -> V_9 . V_10 + 1 ) * sizeof( struct V_13 ) ;
F_66 ( ! F_177 ( V_4 -> V_9 . V_44 ) ) ;
F_16 ( V_4 -> V_9 . V_44 , V_292 ) ;
F_66 ( ! F_177 ( V_4 -> V_9 . V_43 ) ) ;
F_16 ( V_4 -> V_9 . V_43 , V_292 ) ;
F_66 ( ! F_177 ( V_4 -> V_9 . V_42 ) ) ;
F_16 ( V_4 -> V_9 . V_42 , V_292 ) ;
}
static void F_178 ( struct V_1 * V_2 ,
struct V_296 * V_297 )
{
struct V_298 * V_299 = V_2 -> V_177 ;
T_3 V_11 = F_179 ( V_2 -> V_22 . V_11 ) ;
if ( V_299 )
F_180 ( V_297 , L_3 ,
V_299 -> V_300 , V_299 -> V_301 , V_299 -> V_302 ) ;
switch ( V_2 -> V_23 . V_8 ) {
case V_190 :
F_180 ( V_297 , L_4 ,
& V_2 -> V_23 . V_6 . V_191 , & V_2 -> V_22 . V_5 . V_191 ) ;
break;
case V_194 :
F_180 ( V_297 , L_5 ,
V_2 -> V_23 . V_6 . V_303 , V_2 -> V_22 . V_5 . V_303 ) ;
break;
}
F_180 ( V_297 , L_6 , V_11 , V_11 ) ;
}
static void F_181 ( struct V_304 * V_305 , T_10 V_8 ,
struct V_296 * V_297 )
{
const struct V_306 * V_307 ;
const struct V_308 * V_309 ;
switch ( V_8 ) {
case V_190 :
V_307 = F_182 ( V_305 ) ;
F_180 ( V_297 , L_4 ,
& V_307 -> V_6 , & V_307 -> V_5 ) ;
break;
case V_194 :
V_309 = F_183 ( V_305 ) ;
F_180 ( V_297 ,
L_7 ,
& V_309 -> V_6 , & V_309 -> V_5 ,
V_309 -> V_310 [ 0 ] & 0x0f ,
V_309 -> V_310 [ 1 ] ,
V_309 -> V_310 [ 2 ] ) ;
break;
}
}
void F_184 ( struct V_1 * V_2 , int V_311 , bool V_137 )
{
struct V_296 * V_297 ;
V_297 = F_185 ( L_8 ) ;
if ( V_297 == NULL )
return;
F_186 ( V_137 , V_297 ) ;
F_178 ( V_2 , V_297 ) ;
F_180 ( V_297 , L_9 , V_311 ) ;
F_187 ( V_297 ) ;
}
void F_54 ( struct V_1 * V_2 , int V_311 , bool V_137 )
{
struct V_296 * V_297 ;
V_297 = F_185 ( L_10 ) ;
if ( V_297 == NULL )
return;
F_186 ( V_137 , V_297 ) ;
F_178 ( V_2 , V_297 ) ;
F_180 ( V_297 , L_9 , V_311 ) ;
F_187 ( V_297 ) ;
}
void F_188 ( struct V_1 * V_2 ,
struct V_304 * V_305 )
{
struct V_296 * V_297 ;
T_3 V_11 ;
V_297 = F_185 ( L_11 ) ;
if ( V_297 == NULL )
return;
F_181 ( V_305 , V_2 -> V_23 . V_8 , V_297 ) ;
V_11 = F_179 ( V_2 -> V_22 . V_11 ) ;
F_180 ( V_297 , L_6 , V_11 , V_11 ) ;
F_187 ( V_297 ) ;
}
void F_189 ( struct V_1 * V_2 ,
struct V_304 * V_305 , T_4 V_312 )
{
struct V_296 * V_297 ;
T_3 V_11 ;
V_297 = F_185 ( L_12 ) ;
if ( V_297 == NULL )
return;
F_181 ( V_305 , V_2 -> V_23 . V_8 , V_297 ) ;
V_11 = F_179 ( V_2 -> V_22 . V_11 ) ;
F_180 ( V_297 , L_13 ,
V_11 , V_11 , F_179 ( V_312 ) ) ;
F_187 ( V_297 ) ;
}
void F_190 ( struct V_304 * V_305 , T_10 V_8 )
{
struct V_296 * V_297 ;
V_297 = F_185 ( L_14 ) ;
if ( V_297 == NULL )
return;
F_181 ( V_305 , V_8 , V_297 ) ;
F_187 ( V_297 ) ;
}
void F_191 ( struct V_304 * V_305 , T_10 V_8 ,
T_4 V_313 , T_4 V_312 )
{
struct V_296 * V_297 ;
T_3 V_11 ;
V_297 = F_185 ( L_14 ) ;
if ( V_297 == NULL )
return;
F_181 ( V_305 , V_8 , V_297 ) ;
V_11 = F_179 ( V_313 ) ;
F_180 ( V_297 , L_13 ,
V_11 , V_11 , F_179 ( V_312 ) ) ;
F_187 ( V_297 ) ;
}
void F_192 ( struct V_1 * V_2 ,
struct V_304 * V_305 , T_5 V_12 )
{
struct V_296 * V_297 ;
T_4 V_313 ;
T_4 V_312 ;
V_297 = F_185 ( L_15 ) ;
if ( V_297 == NULL )
return;
F_181 ( V_305 , V_2 -> V_23 . V_8 , V_297 ) ;
if ( F_193 ( V_305 , V_12 , & V_313 , & V_312 ) == 0 ) {
T_3 V_11 = F_179 ( V_313 ) ;
F_180 ( V_297 , L_13 ,
V_11 , V_11 , F_179 ( V_312 ) ) ;
}
F_187 ( V_297 ) ;
}
