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
F_28 () ;
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
F_28 () ;
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
type = F_31 ( V_48 [ V_12 ] ) ;
if ( F_26 ( type && ! F_32 ( type -> V_57 ) ) )
type = NULL ;
F_28 () ;
if ( ! type && ! V_55 ) {
F_33 ( L_1 , V_8 , V_12 ) ;
V_55 = 1 ;
goto V_56;
}
return type ;
}
static void F_34 ( const struct V_45 * type )
{
F_35 ( type -> V_57 ) ;
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
V_49 = - V_53 ;
V_60 = V_47 -> V_64 ;
F_17 ( & V_65 ) ;
if ( V_60 [ V_59 -> V_61 ] )
goto V_66;
V_49 = - V_54 ;
if ( ! F_32 ( V_47 -> V_57 ) )
goto V_66;
V_59 -> V_47 = V_47 ;
V_60 [ V_59 -> V_61 ] = V_59 ;
V_49 = 0 ;
V_66:
F_22 ( & V_65 ) ;
F_28 () ;
return V_49 ;
}
int F_37 ( struct V_58 * V_59 , int V_8 )
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
F_35 ( V_59 -> V_47 -> V_57 ) ;
V_49 = 0 ;
}
F_22 ( & V_65 ) ;
F_28 () ;
return V_49 ;
}
static struct V_58 * F_38 ( unsigned int V_61 , int V_8 )
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
V_59 = F_31 ( V_47 -> V_64 [ V_61 ] ) ;
if ( F_26 ( V_59 && ! F_32 ( V_59 -> V_57 ) ) )
V_59 = NULL ;
F_28 () ;
if ( ! V_59 && ! V_55 ) {
F_33 ( L_2 , V_8 , V_61 ) ;
V_55 = 1 ;
goto V_56;
}
return V_59 ;
}
static void F_39 ( struct V_58 * V_59 )
{
F_35 ( V_59 -> V_57 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_67 ) ;
F_42 ( & V_2 -> V_68 ) ;
F_43 ( V_2 -> V_69 ) ;
F_43 ( V_2 -> V_70 ) ;
F_43 ( V_2 -> V_71 ) ;
F_43 ( V_2 -> V_72 ) ;
F_43 ( V_2 -> V_61 ) ;
F_43 ( V_2 -> V_73 ) ;
F_43 ( V_2 -> V_74 ) ;
F_43 ( V_2 -> V_75 ) ;
if ( V_2 -> V_76 )
F_39 ( V_2 -> V_76 ) ;
if ( V_2 -> V_77 )
F_39 ( V_2 -> V_77 ) ;
if ( V_2 -> V_78 )
F_39 ( V_2 -> V_78 ) ;
if ( V_2 -> type ) {
V_2 -> type -> V_79 ( V_2 ) ;
F_34 ( V_2 -> type ) ;
}
F_44 ( V_2 ) ;
F_43 ( V_2 ) ;
}
static void F_45 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
struct V_13 V_80 ;
F_17 ( & V_81 ) ;
F_46 ( & V_82 , & V_80 ) ;
F_22 ( & V_81 ) ;
F_23 () ;
F_10 (x, tmp, &gc_list, gclist)
F_40 ( V_2 ) ;
}
static enum V_83 F_47 ( struct V_84 * V_85 )
{
struct V_86 * V_87 = F_14 ( V_85 , struct V_86 , V_88 ) ;
struct V_1 * V_2 = F_14 ( V_87 , struct V_1 , V_67 ) ;
unsigned long V_89 = F_48 () ;
long V_90 = V_91 ;
int V_92 = 0 ;
int V_49 = 0 ;
F_49 ( & V_2 -> V_93 ) ;
if ( V_2 -> V_94 . V_95 == V_96 )
goto V_66;
if ( V_2 -> V_94 . V_95 == V_97 )
goto V_98;
if ( V_2 -> V_99 . V_100 ) {
long V_101 = V_2 -> V_99 . V_100 +
V_2 -> V_102 . V_103 - V_89 ;
if ( V_101 <= 0 ) {
if ( V_2 -> V_104 & V_105 ) {
V_2 -> V_102 . V_103 = V_89 - V_2 -> V_106 - 1 ;
V_101 = V_2 -> V_99 . V_100 - V_2 -> V_106 ;
} else
goto V_98;
}
if ( V_101 < V_90 )
V_90 = V_101 ;
}
if ( V_2 -> V_99 . V_107 ) {
long V_101 = V_2 -> V_99 . V_107 +
( V_2 -> V_102 . V_108 ? : V_89 ) - V_89 ;
if ( V_101 <= 0 )
goto V_98;
if ( V_101 < V_90 )
V_90 = V_101 ;
}
if ( V_2 -> V_94 . V_109 )
goto V_110;
if ( V_2 -> V_99 . V_111 ) {
long V_101 = V_2 -> V_99 . V_111 +
V_2 -> V_102 . V_103 - V_89 ;
if ( V_101 <= 0 ) {
V_92 = 1 ;
V_2 -> V_104 &= ~ V_105 ;
} else if ( V_101 < V_90 ) {
V_90 = V_101 ;
V_2 -> V_104 |= V_105 ;
V_2 -> V_106 = V_101 ;
}
}
if ( V_2 -> V_99 . V_112 ) {
long V_101 = V_2 -> V_99 . V_112 +
( V_2 -> V_102 . V_108 ? : V_89 ) - V_89 ;
if ( V_101 <= 0 )
V_92 = 1 ;
else if ( V_101 < V_90 )
V_90 = V_101 ;
}
V_2 -> V_94 . V_109 = V_92 ;
if ( V_92 )
F_50 ( V_2 , 0 , 0 ) ;
V_110:
if ( V_90 != V_91 ) {
F_51 ( & V_2 -> V_67 , F_52 ( V_90 , 0 ) , V_113 ) ;
}
goto V_66;
V_98:
if ( V_2 -> V_94 . V_95 == V_114 && V_2 -> V_22 . V_11 == 0 )
V_2 -> V_94 . V_95 = V_97 ;
V_49 = F_53 ( V_2 ) ;
if ( ! V_49 )
F_50 ( V_2 , 1 , 0 ) ;
F_54 ( V_2 , V_49 ? 0 : 1 , true ) ;
V_66:
F_55 ( & V_2 -> V_93 ) ;
return V_115 ;
}
struct V_1 * F_56 ( struct V_4 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_57 ( sizeof( struct V_1 ) , V_116 ) ;
if ( V_2 ) {
F_58 ( & V_2 -> V_117 , V_4 ) ;
F_59 ( & V_2 -> V_3 , 1 ) ;
F_59 ( & V_2 -> V_118 , 0 ) ;
F_60 ( & V_2 -> V_94 . V_119 ) ;
F_61 ( & V_2 -> V_24 ) ;
F_61 ( & V_2 -> V_25 ) ;
F_61 ( & V_2 -> V_26 ) ;
F_62 ( & V_2 -> V_67 , F_47 ,
V_120 , V_121 ) ;
F_63 ( & V_2 -> V_68 , V_122 ,
( unsigned long ) V_2 ) ;
V_2 -> V_102 . V_103 = F_48 () ;
V_2 -> V_99 . V_123 = V_124 ;
V_2 -> V_99 . V_125 = V_124 ;
V_2 -> V_99 . V_126 = V_124 ;
V_2 -> V_99 . V_127 = V_124 ;
V_2 -> V_128 = 0 ;
V_2 -> V_129 = 0 ;
V_2 -> V_76 = NULL ;
V_2 -> V_77 = NULL ;
F_64 ( & V_2 -> V_93 ) ;
}
return V_2 ;
}
void F_65 ( struct V_1 * V_2 )
{
F_66 ( V_2 -> V_94 . V_95 != V_96 ) ;
F_17 ( & V_81 ) ;
F_67 ( & V_2 -> V_130 , & V_82 ) ;
F_22 ( & V_81 ) ;
F_68 ( & V_131 ) ;
}
int F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_117 ( V_2 ) ;
int V_49 = - V_132 ;
if ( V_2 -> V_94 . V_95 != V_96 ) {
V_2 -> V_94 . V_95 = V_96 ;
F_49 ( & V_4 -> V_9 . V_40 ) ;
F_69 ( & V_2 -> V_94 . V_119 ) ;
F_70 ( & V_2 -> V_24 ) ;
F_70 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_22 . V_11 )
F_70 ( & V_2 -> V_26 ) ;
V_4 -> V_9 . V_133 -- ;
F_55 ( & V_4 -> V_9 . V_40 ) ;
F_71 ( V_2 ) ;
V_49 = 0 ;
}
return V_49 ;
}
int F_72 ( struct V_1 * V_2 )
{
int V_49 ;
F_17 ( & V_2 -> V_93 ) ;
V_49 = F_53 ( V_2 ) ;
F_22 ( & V_2 -> V_93 ) ;
return V_49 ;
}
static inline int
F_73 ( struct V_4 * V_4 , T_5 V_12 , bool V_134 )
{
int V_39 , V_49 = 0 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
F_74 (x, net->xfrm.state_bydst+i, bydst) {
if ( F_75 ( V_2 -> V_22 . V_12 , V_12 ) &&
( V_49 = F_76 ( V_2 ) ) != 0 ) {
F_54 ( V_2 , 0 , V_134 ) ;
return V_49 ;
}
}
}
return V_49 ;
}
static inline int
F_73 ( struct V_4 * V_4 , T_5 V_12 , bool V_134 )
{
return 0 ;
}
int F_77 ( struct V_4 * V_4 , T_5 V_12 , bool V_134 )
{
int V_39 , V_49 = 0 , V_135 = 0 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_49 = F_73 ( V_4 , V_12 , V_134 ) ;
if ( V_49 )
goto V_66;
V_49 = - V_132 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
V_136:
F_74 (x, net->xfrm.state_bydst+i, bydst) {
if ( ! F_78 ( V_2 ) &&
F_75 ( V_2 -> V_22 . V_12 , V_12 ) ) {
F_79 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
V_49 = F_72 ( V_2 ) ;
F_54 ( V_2 , V_49 ? 0 : 1 ,
V_134 ) ;
F_71 ( V_2 ) ;
if ( ! V_49 )
V_135 ++ ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
goto V_136;
}
}
}
if ( V_135 )
V_49 = 0 ;
V_66:
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_49 ;
}
void F_80 ( struct V_4 * V_4 , struct V_137 * V_138 )
{
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_138 -> V_139 = V_4 -> V_9 . V_133 ;
V_138 -> V_140 = V_4 -> V_9 . V_10 ;
V_138 -> V_141 = V_142 ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
}
static void
F_81 ( struct V_1 * V_2 , const struct V_143 * V_144 ,
const struct V_145 * V_146 ,
const T_2 * V_5 , const T_2 * V_6 ,
unsigned short V_8 )
{
struct V_46 * V_47 = F_82 ( V_8 ) ;
if ( ! V_47 )
return;
V_47 -> V_147 ( & V_2 -> V_148 , V_144 ) ;
if ( V_8 != V_146 -> V_149 ) {
V_47 = F_82 ( V_146 -> V_149 ) ;
if ( ! V_47 )
return;
}
V_47 -> V_150 ( V_2 , V_146 , V_5 , V_6 ) ;
}
static struct V_1 * F_83 ( struct V_4 * V_4 , T_3 V_151 ,
const T_2 * V_5 ,
T_4 V_11 , T_5 V_12 ,
unsigned short V_8 )
{
unsigned int V_21 = F_7 ( V_4 , V_5 , V_11 , V_12 , V_8 ) ;
struct V_1 * V_2 ;
F_84 (x, net->xfrm.state_byspi + h, byspi) {
if ( V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_22 . V_11 != V_11 ||
V_2 -> V_22 . V_12 != V_12 ||
! F_85 ( & V_2 -> V_22 . V_5 , V_5 , V_8 ) )
continue;
if ( ( V_151 & V_2 -> V_151 . V_152 ) != V_2 -> V_151 . V_153 )
continue;
if ( ! F_1 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_86 ( struct V_4 * V_4 , T_3 V_151 ,
const T_2 * V_5 ,
const T_2 * V_6 ,
T_5 V_12 , unsigned short V_8 )
{
unsigned int V_21 = F_5 ( V_4 , V_5 , V_6 , V_8 ) ;
struct V_1 * V_2 ;
F_84 (x, net->xfrm.state_bysrc + h, bysrc) {
if ( V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_22 . V_12 != V_12 ||
! F_85 ( & V_2 -> V_22 . V_5 , V_5 , V_8 ) ||
! F_85 ( & V_2 -> V_23 . V_6 , V_6 , V_8 ) )
continue;
if ( ( V_151 & V_2 -> V_151 . V_152 ) != V_2 -> V_151 . V_153 )
continue;
if ( ! F_1 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static inline struct V_1 *
F_87 ( struct V_1 * V_2 , int V_154 , int V_8 )
{
struct V_4 * V_4 = V_117 ( V_2 ) ;
T_3 V_151 = V_2 -> V_151 . V_153 & V_2 -> V_151 . V_152 ;
if ( V_154 )
return F_83 ( V_4 , V_151 , & V_2 -> V_22 . V_5 ,
V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 , V_8 ) ;
else
return F_86 ( V_4 , V_151 ,
& V_2 -> V_22 . V_5 ,
& V_2 -> V_23 . V_6 ,
V_2 -> V_22 . V_12 , V_8 ) ;
}
static void F_88 ( struct V_4 * V_4 , int V_155 )
{
if ( V_155 &&
( V_4 -> V_9 . V_10 + 1 ) < V_142 &&
V_4 -> V_9 . V_133 > V_4 -> V_9 . V_10 )
F_68 ( & V_4 -> V_9 . V_29 ) ;
}
static void F_89 ( struct V_156 * V_157 , struct V_1 * V_2 ,
const struct V_143 * V_144 , unsigned short V_8 ,
struct V_1 * * V_158 , int * V_159 ,
int * error )
{
if ( V_2 -> V_94 . V_95 == V_160 ) {
if ( ( V_2 -> V_148 . V_8 &&
! F_90 ( & V_2 -> V_148 , V_144 , V_2 -> V_148 . V_8 ) ) ||
! F_91 ( V_2 , V_157 , V_144 ) )
return;
if ( ! * V_158 ||
( * V_158 ) -> V_94 . V_109 > V_2 -> V_94 . V_109 ||
( ( * V_158 ) -> V_94 . V_109 == V_2 -> V_94 . V_109 &&
( * V_158 ) -> V_102 . V_103 < V_2 -> V_102 . V_103 ) )
* V_158 = V_2 ;
} else if ( V_2 -> V_94 . V_95 == V_114 ) {
* V_159 = 1 ;
} else if ( V_2 -> V_94 . V_95 == V_161 ||
V_2 -> V_94 . V_95 == V_97 ) {
if ( F_90 ( & V_2 -> V_148 , V_144 , V_2 -> V_148 . V_8 ) &&
F_91 ( V_2 , V_157 , V_144 ) )
* error = - V_132 ;
}
}
struct V_1 *
F_92 ( const T_2 * V_5 , const T_2 * V_6 ,
const struct V_143 * V_144 , struct V_145 * V_146 ,
struct V_156 * V_157 , int * V_49 ,
unsigned short V_8 )
{
static T_2 V_162 = { } ;
struct V_4 * V_4 = F_93 ( V_157 ) ;
unsigned int V_21 , V_163 ;
struct V_1 * V_2 , * V_164 , * V_165 ;
int V_166 = 0 ;
int error = 0 ;
struct V_1 * V_158 = NULL ;
T_3 V_151 = V_157 -> V_151 . V_153 & V_157 -> V_151 . V_152 ;
unsigned short V_149 = V_146 -> V_149 ;
unsigned int V_167 ;
struct V_168 V_169 ;
V_165 = NULL ;
V_167 = F_94 ( & V_41 ) ;
F_95 () ;
V_21 = F_3 ( V_4 , V_5 , V_6 , V_146 -> V_7 , V_149 ) ;
F_84 (x, net->xfrm.state_bydst + h, bydst) {
if ( V_2 -> V_23 . V_8 == V_149 &&
V_2 -> V_23 . V_7 == V_146 -> V_7 &&
( V_151 & V_2 -> V_151 . V_152 ) == V_2 -> V_151 . V_153 &&
! ( V_2 -> V_23 . V_170 & V_171 ) &&
F_96 ( V_2 , V_5 , V_6 , V_149 ) &&
V_146 -> V_59 == V_2 -> V_23 . V_59 &&
V_146 -> V_22 . V_12 == V_2 -> V_22 . V_12 &&
( V_146 -> V_22 . V_11 == V_2 -> V_22 . V_11 || ! V_146 -> V_22 . V_11 ) )
F_89 ( V_157 , V_2 , V_144 , V_149 ,
& V_158 , & V_166 , & error ) ;
}
if ( V_158 || V_166 )
goto V_172;
V_163 = F_3 ( V_4 , V_5 , & V_162 , V_146 -> V_7 , V_149 ) ;
F_84 (x, net->xfrm.state_bydst + h_wildcard, bydst) {
if ( V_2 -> V_23 . V_8 == V_149 &&
V_2 -> V_23 . V_7 == V_146 -> V_7 &&
( V_151 & V_2 -> V_151 . V_152 ) == V_2 -> V_151 . V_153 &&
! ( V_2 -> V_23 . V_170 & V_171 ) &&
F_85 ( & V_2 -> V_22 . V_5 , V_5 , V_149 ) &&
V_146 -> V_59 == V_2 -> V_23 . V_59 &&
V_146 -> V_22 . V_12 == V_2 -> V_22 . V_12 &&
( V_146 -> V_22 . V_11 == V_2 -> V_22 . V_11 || ! V_146 -> V_22 . V_11 ) )
F_89 ( V_157 , V_2 , V_144 , V_149 ,
& V_158 , & V_166 , & error ) ;
}
V_172:
V_2 = V_158 ;
if ( ! V_2 && ! error && ! V_166 ) {
if ( V_146 -> V_22 . V_11 &&
( V_164 = F_83 ( V_4 , V_151 , V_5 , V_146 -> V_22 . V_11 ,
V_146 -> V_22 . V_12 , V_149 ) ) != NULL ) {
V_165 = V_164 ;
error = - V_53 ;
goto V_66;
}
V_169 . V_4 = V_4 ;
if ( ! F_97 ( & V_169 ) ) {
error = - V_132 ;
goto V_66;
}
V_2 = F_56 ( V_4 ) ;
if ( V_2 == NULL ) {
error = - V_173 ;
goto V_66;
}
F_81 ( V_2 , V_144 , V_146 , V_5 , V_6 , V_8 ) ;
memcpy ( & V_2 -> V_151 , & V_157 -> V_151 , sizeof( V_2 -> V_151 ) ) ;
error = F_98 ( V_2 , V_157 -> V_174 , V_144 -> V_175 ) ;
if ( error ) {
V_2 -> V_94 . V_95 = V_96 ;
V_165 = V_2 ;
V_2 = NULL ;
goto V_66;
}
if ( F_99 ( V_2 , V_146 , V_157 ) == 0 ) {
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 -> V_94 . V_95 = V_114 ;
F_100 ( & V_2 -> V_94 . V_119 , & V_4 -> V_9 . V_176 ) ;
F_11 ( & V_2 -> V_24 , V_4 -> V_9 . V_42 + V_21 ) ;
V_21 = F_5 ( V_4 , V_5 , V_6 , V_149 ) ;
F_11 ( & V_2 -> V_25 , V_4 -> V_9 . V_43 + V_21 ) ;
if ( V_2 -> V_22 . V_11 ) {
V_21 = F_7 ( V_4 , & V_2 -> V_22 . V_5 , V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 , V_149 ) ;
F_11 ( & V_2 -> V_26 , V_4 -> V_9 . V_44 + V_21 ) ;
}
V_2 -> V_99 . V_100 = V_4 -> V_9 . V_177 ;
F_51 ( & V_2 -> V_67 , F_52 ( V_4 -> V_9 . V_177 , 0 ) , V_113 ) ;
V_4 -> V_9 . V_133 ++ ;
F_88 ( V_4 , V_2 -> V_24 . V_90 != NULL ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
} else {
V_2 -> V_94 . V_95 = V_96 ;
V_165 = V_2 ;
V_2 = NULL ;
error = - V_132 ;
}
}
V_66:
if ( V_2 ) {
if ( ! F_1 ( V_2 ) ) {
* V_49 = - V_178 ;
V_2 = NULL ;
}
} else {
* V_49 = V_166 ? - V_178 : error ;
}
F_28 () ;
if ( V_165 )
F_71 ( V_165 ) ;
if ( F_101 ( & V_41 , V_167 ) ) {
* V_49 = - V_178 ;
if ( V_2 ) {
F_71 ( V_2 ) ;
V_2 = NULL ;
}
}
return V_2 ;
}
struct V_1 *
F_102 ( struct V_4 * V_4 , T_3 V_151 ,
T_2 * V_5 , T_2 * V_6 ,
unsigned short V_8 , T_5 V_59 , T_5 V_12 , T_3 V_7 )
{
unsigned int V_21 ;
struct V_1 * V_179 = NULL , * V_2 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_21 = F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 ) ;
F_74 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_8 == V_8 &&
V_2 -> V_23 . V_7 == V_7 &&
( V_151 & V_2 -> V_151 . V_152 ) == V_2 -> V_151 . V_153 &&
! ( V_2 -> V_23 . V_170 & V_171 ) &&
F_96 ( V_2 , V_5 , V_6 , V_8 ) &&
V_59 == V_2 -> V_23 . V_59 &&
V_12 == V_2 -> V_22 . V_12 &&
V_2 -> V_94 . V_95 == V_160 ) {
V_179 = V_2 ;
break;
}
}
if ( V_179 )
F_79 ( V_179 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_179 ;
}
struct V_1 * F_103 ( struct V_4 * V_4 , T_4 V_11 ,
unsigned short V_8 )
{
struct V_1 * V_2 ;
struct V_180 * V_181 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_104 (w, &net->xfrm.state_all, all) {
V_2 = F_14 ( V_181 , struct V_1 , V_94 ) ;
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
struct V_4 * V_4 = V_117 ( V_2 ) ;
unsigned int V_21 ;
F_100 ( & V_2 -> V_94 . V_119 , & V_4 -> V_9 . V_176 ) ;
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
F_51 ( & V_2 -> V_67 , F_52 ( 1 , 0 ) , V_113 ) ;
if ( V_2 -> V_128 )
F_106 ( & V_2 -> V_68 , V_182 + V_2 -> V_128 ) ;
V_4 -> V_9 . V_133 ++ ;
F_88 ( V_4 , V_2 -> V_24 . V_90 != NULL ) ;
}
static void F_107 ( struct V_1 * V_183 )
{
struct V_4 * V_4 = V_117 ( V_183 ) ;
unsigned short V_8 = V_183 -> V_23 . V_8 ;
T_3 V_7 = V_183 -> V_23 . V_7 ;
struct V_1 * V_2 ;
unsigned int V_21 ;
T_3 V_151 = V_183 -> V_151 . V_153 & V_183 -> V_151 . V_152 ;
V_21 = F_3 ( V_4 , & V_183 -> V_22 . V_5 , & V_183 -> V_23 . V_6 , V_7 , V_8 ) ;
F_74 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_8 == V_8 &&
V_2 -> V_23 . V_7 == V_7 &&
( V_151 & V_2 -> V_151 . V_152 ) == V_2 -> V_151 . V_153 &&
F_85 ( & V_2 -> V_22 . V_5 , & V_183 -> V_22 . V_5 , V_8 ) &&
F_85 ( & V_2 -> V_23 . V_6 , & V_183 -> V_23 . V_6 , V_8 ) )
V_2 -> V_184 ++ ;
}
}
void F_108 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_117 ( V_2 ) ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_107 ( V_2 ) ;
F_105 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
}
static struct V_1 * F_109 ( struct V_4 * V_4 ,
const struct V_185 * V_152 ,
unsigned short V_8 , T_5 V_59 ,
T_3 V_7 , T_5 V_12 ,
const T_2 * V_5 ,
const T_2 * V_6 ,
int V_186 )
{
unsigned int V_21 = F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 ) ;
struct V_1 * V_2 ;
T_3 V_151 = V_152 -> V_153 & V_152 -> V_152 ;
F_74 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_7 != V_7 ||
V_2 -> V_23 . V_59 != V_59 ||
V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_94 . V_95 != V_114 ||
V_2 -> V_22 . V_11 != 0 ||
V_2 -> V_22 . V_12 != V_12 ||
( V_151 & V_2 -> V_151 . V_152 ) != V_2 -> V_151 . V_153 ||
! F_85 ( & V_2 -> V_22 . V_5 , V_5 , V_8 ) ||
! F_85 ( & V_2 -> V_23 . V_6 , V_6 , V_8 ) )
continue;
F_79 ( V_2 ) ;
return V_2 ;
}
if ( ! V_186 )
return NULL ;
V_2 = F_56 ( V_4 ) ;
if ( F_27 ( V_2 ) ) {
switch ( V_8 ) {
case V_187 :
V_2 -> V_148 . V_5 . V_188 = V_5 -> V_188 ;
V_2 -> V_148 . V_6 . V_188 = V_6 -> V_188 ;
V_2 -> V_148 . V_189 = 32 ;
V_2 -> V_148 . V_190 = 32 ;
V_2 -> V_23 . V_6 . V_188 = V_6 -> V_188 ;
V_2 -> V_22 . V_5 . V_188 = V_5 -> V_188 ;
break;
case V_191 :
V_2 -> V_148 . V_5 . V_192 = V_5 -> V_192 ;
V_2 -> V_148 . V_6 . V_192 = V_6 -> V_192 ;
V_2 -> V_148 . V_189 = 128 ;
V_2 -> V_148 . V_190 = 128 ;
V_2 -> V_23 . V_6 . V_192 = V_6 -> V_192 ;
V_2 -> V_22 . V_5 . V_192 = V_5 -> V_192 ;
break;
}
V_2 -> V_94 . V_95 = V_114 ;
V_2 -> V_22 . V_12 = V_12 ;
V_2 -> V_23 . V_8 = V_8 ;
V_2 -> V_23 . V_59 = V_59 ;
V_2 -> V_23 . V_7 = V_7 ;
V_2 -> V_151 . V_153 = V_152 -> V_153 ;
V_2 -> V_151 . V_152 = V_152 -> V_152 ;
V_2 -> V_99 . V_100 = V_4 -> V_9 . V_177 ;
F_79 ( V_2 ) ;
F_51 ( & V_2 -> V_67 , F_52 ( V_4 -> V_9 . V_177 , 0 ) , V_113 ) ;
F_100 ( & V_2 -> V_94 . V_119 , & V_4 -> V_9 . V_176 ) ;
F_11 ( & V_2 -> V_24 , V_4 -> V_9 . V_42 + V_21 ) ;
V_21 = F_5 ( V_4 , V_5 , V_6 , V_8 ) ;
F_11 ( & V_2 -> V_25 , V_4 -> V_9 . V_43 + V_21 ) ;
V_4 -> V_9 . V_133 ++ ;
F_88 ( V_4 , V_2 -> V_24 . V_90 != NULL ) ;
}
return V_2 ;
}
int F_110 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_117 ( V_2 ) ;
struct V_1 * V_193 , * V_165 ;
int V_8 ;
int V_49 ;
T_3 V_151 = V_2 -> V_151 . V_153 & V_2 -> V_151 . V_152 ;
int V_154 = F_75 ( V_2 -> V_22 . V_12 , V_194 ) ;
V_8 = V_2 -> V_23 . V_8 ;
V_165 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_193 = F_87 ( V_2 , V_154 , V_8 ) ;
if ( V_193 ) {
V_165 = V_193 ;
V_193 = NULL ;
V_49 = - V_53 ;
goto V_66;
}
if ( V_154 && V_2 -> V_94 . V_195 ) {
V_193 = F_111 ( V_4 , V_151 , V_2 -> V_94 . V_195 ) ;
if ( V_193 && ( ( V_193 -> V_22 . V_12 != V_2 -> V_22 . V_12 ) ||
! F_85 ( & V_193 -> V_22 . V_5 , & V_2 -> V_22 . V_5 , V_8 ) ) ) {
V_165 = V_193 ;
V_193 = NULL ;
}
}
if ( V_154 && ! V_193 )
V_193 = F_109 ( V_4 , & V_2 -> V_151 , V_8 , V_2 -> V_23 . V_59 ,
V_2 -> V_23 . V_7 , V_2 -> V_22 . V_12 ,
& V_2 -> V_22 . V_5 , & V_2 -> V_23 . V_6 , 0 ) ;
F_107 ( V_2 ) ;
F_105 ( V_2 ) ;
V_49 = 0 ;
V_66:
F_22 ( & V_4 -> V_9 . V_40 ) ;
if ( V_193 ) {
F_72 ( V_193 ) ;
F_71 ( V_193 ) ;
}
if ( V_165 )
F_71 ( V_165 ) ;
return V_49 ;
}
static struct V_1 * F_112 ( struct V_1 * V_196 )
{
struct V_4 * V_4 = V_117 ( V_196 ) ;
struct V_1 * V_2 = F_56 ( V_4 ) ;
if ( ! V_2 )
goto V_66;
memcpy ( & V_2 -> V_22 , & V_196 -> V_22 , sizeof( V_2 -> V_22 ) ) ;
memcpy ( & V_2 -> V_148 , & V_196 -> V_148 , sizeof( V_2 -> V_148 ) ) ;
memcpy ( & V_2 -> V_99 , & V_196 -> V_99 , sizeof( V_2 -> V_99 ) ) ;
V_2 -> V_23 . V_59 = V_196 -> V_23 . V_59 ;
V_2 -> V_23 . V_197 = V_196 -> V_23 . V_197 ;
V_2 -> V_23 . V_7 = V_196 -> V_23 . V_7 ;
V_2 -> V_23 . V_8 = V_196 -> V_23 . V_8 ;
V_2 -> V_23 . V_6 = V_196 -> V_23 . V_6 ;
if ( V_196 -> V_70 ) {
V_2 -> V_70 = F_113 ( V_196 -> V_70 ) ;
if ( ! V_2 -> V_70 )
goto error;
}
V_2 -> V_23 . V_198 = V_196 -> V_23 . V_198 ;
if ( V_196 -> V_69 ) {
V_2 -> V_69 = F_114 ( V_196 -> V_69 ) ;
if ( ! V_2 -> V_69 )
goto error;
}
if ( V_196 -> V_71 ) {
V_2 -> V_71 = F_115 ( V_196 -> V_71 ) ;
if ( ! V_2 -> V_71 )
goto error;
}
V_2 -> V_23 . V_199 = V_196 -> V_23 . V_199 ;
if ( V_196 -> V_72 ) {
V_2 -> V_72 = F_115 ( V_196 -> V_72 ) ;
if ( ! V_2 -> V_72 )
goto error;
}
V_2 -> V_23 . V_200 = V_196 -> V_23 . V_200 ;
if ( V_196 -> V_61 ) {
V_2 -> V_61 = F_116 ( V_196 -> V_61 , sizeof( * V_2 -> V_61 ) , V_201 ) ;
if ( ! V_2 -> V_61 )
goto error;
}
if ( V_196 -> V_73 ) {
V_2 -> V_73 = F_116 ( V_196 -> V_73 , sizeof( * V_2 -> V_73 ) ,
V_201 ) ;
if ( ! V_2 -> V_73 )
goto error;
}
if ( V_196 -> V_74 ) {
if ( F_117 ( V_2 , V_196 ) )
goto error;
}
memcpy ( & V_2 -> V_151 , & V_196 -> V_151 , sizeof( V_2 -> V_151 ) ) ;
if ( F_118 ( V_2 ) < 0 )
goto error;
V_2 -> V_23 . V_170 = V_196 -> V_23 . V_170 ;
V_2 -> V_23 . V_202 = V_196 -> V_23 . V_202 ;
V_2 -> V_203 = V_196 -> V_203 ;
V_2 -> V_129 = V_196 -> V_129 ;
V_2 -> V_128 = V_196 -> V_128 ;
V_2 -> V_102 . V_103 = V_196 -> V_102 . V_103 ;
V_2 -> V_94 . V_95 = V_196 -> V_94 . V_95 ;
V_2 -> V_94 . V_195 = V_196 -> V_94 . V_195 ;
return V_2 ;
error:
F_71 ( V_2 ) ;
V_66:
return NULL ;
}
struct V_1 * F_119 ( struct V_204 * V_152 , struct V_4 * V_4 )
{
unsigned int V_21 ;
struct V_1 * V_2 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( V_152 -> V_7 ) {
V_21 = F_3 ( V_4 , & V_152 -> V_205 , & V_152 -> V_206 ,
V_152 -> V_7 , V_152 -> V_207 ) ;
F_74 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_59 != V_152 -> V_59 ||
V_2 -> V_22 . V_12 != V_152 -> V_12 )
continue;
if ( V_152 -> V_7 && V_2 -> V_23 . V_7 != V_152 -> V_7 )
continue;
if ( ! F_85 ( & V_2 -> V_22 . V_5 , & V_152 -> V_205 ,
V_152 -> V_207 ) ||
! F_85 ( & V_2 -> V_23 . V_6 , & V_152 -> V_206 ,
V_152 -> V_207 ) )
continue;
F_79 ( V_2 ) ;
break;
}
} else {
V_21 = F_5 ( V_4 , & V_152 -> V_205 , & V_152 -> V_206 ,
V_152 -> V_207 ) ;
F_74 (x, net->xfrm.state_bysrc+h, bysrc) {
if ( V_2 -> V_23 . V_59 != V_152 -> V_59 ||
V_2 -> V_22 . V_12 != V_152 -> V_12 )
continue;
if ( ! F_85 ( & V_2 -> V_22 . V_5 , & V_152 -> V_205 ,
V_152 -> V_207 ) ||
! F_85 ( & V_2 -> V_23 . V_6 , & V_152 -> V_206 ,
V_152 -> V_207 ) )
continue;
F_79 ( V_2 ) ;
break;
}
}
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
struct V_1 * F_120 ( struct V_1 * V_2 ,
struct V_204 * V_152 )
{
struct V_1 * V_208 ;
V_208 = F_112 ( V_2 ) ;
if ( ! V_208 )
return NULL ;
memcpy ( & V_208 -> V_22 . V_5 , & V_152 -> V_209 , sizeof( V_208 -> V_22 . V_5 ) ) ;
memcpy ( & V_208 -> V_23 . V_6 , & V_152 -> V_210 , sizeof( V_208 -> V_23 . V_6 ) ) ;
if ( F_85 ( & V_2 -> V_22 . V_5 , & V_152 -> V_209 , V_152 -> V_211 ) ) {
F_108 ( V_208 ) ;
} else {
if ( F_110 ( V_208 ) < 0 )
goto error;
}
return V_208 ;
error:
F_71 ( V_208 ) ;
return NULL ;
}
int F_121 ( struct V_1 * V_2 )
{
struct V_1 * V_193 , * V_165 ;
int V_49 ;
int V_154 = F_75 ( V_2 -> V_22 . V_12 , V_194 ) ;
struct V_4 * V_4 = V_117 ( V_2 ) ;
V_165 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_193 = F_87 ( V_2 , V_154 , V_2 -> V_23 . V_8 ) ;
V_49 = - V_132 ;
if ( ! V_193 )
goto V_66;
if ( F_78 ( V_193 ) ) {
V_165 = V_193 ;
V_49 = - V_53 ;
goto V_66;
}
if ( V_193 -> V_94 . V_95 == V_114 ) {
F_105 ( V_2 ) ;
V_2 = NULL ;
}
V_49 = 0 ;
V_66:
F_22 ( & V_4 -> V_9 . V_40 ) ;
if ( V_165 )
F_71 ( V_165 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_2 ) {
F_72 ( V_193 ) ;
F_71 ( V_193 ) ;
return 0 ;
}
V_49 = - V_63 ;
F_17 ( & V_193 -> V_93 ) ;
if ( F_27 ( V_193 -> V_94 . V_95 == V_160 ) ) {
if ( V_2 -> V_61 && V_193 -> V_61 )
memcpy ( V_193 -> V_61 , V_2 -> V_61 , sizeof( * V_193 -> V_61 ) ) ;
if ( V_2 -> V_73 && V_193 -> V_73 ) {
memcpy ( V_193 -> V_73 , V_2 -> V_73 , sizeof( * V_193 -> V_73 ) ) ;
}
if ( ! V_154 && memcmp ( & V_193 -> V_148 , & V_2 -> V_148 , sizeof( V_193 -> V_148 ) ) )
memcpy ( & V_193 -> V_148 , & V_2 -> V_148 , sizeof( V_193 -> V_148 ) ) ;
memcpy ( & V_193 -> V_99 , & V_2 -> V_99 , sizeof( V_193 -> V_99 ) ) ;
V_193 -> V_94 . V_109 = 0 ;
F_51 ( & V_193 -> V_67 , F_52 ( 1 , 0 ) , V_113 ) ;
if ( V_193 -> V_102 . V_108 )
F_122 ( V_193 ) ;
V_49 = 0 ;
V_2 -> V_94 . V_95 = V_96 ;
F_123 ( V_2 ) ;
}
F_22 ( & V_193 -> V_93 ) ;
F_71 ( V_193 ) ;
return V_49 ;
}
int F_122 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_102 . V_108 )
V_2 -> V_102 . V_108 = F_48 () ;
if ( V_2 -> V_102 . V_212 >= V_2 -> V_99 . V_126 ||
V_2 -> V_102 . V_213 >= V_2 -> V_99 . V_127 ) {
V_2 -> V_94 . V_95 = V_97 ;
F_51 ( & V_2 -> V_67 , 0 , V_113 ) ;
return - V_63 ;
}
if ( ! V_2 -> V_94 . V_109 &&
( V_2 -> V_102 . V_212 >= V_2 -> V_99 . V_123 ||
V_2 -> V_102 . V_213 >= V_2 -> V_99 . V_125 ) ) {
V_2 -> V_94 . V_109 = 1 ;
F_50 ( V_2 , 0 , 0 ) ;
}
return 0 ;
}
struct V_1 *
F_124 ( struct V_4 * V_4 , T_3 V_151 , const T_2 * V_5 , T_4 V_11 ,
T_5 V_12 , unsigned short V_8 )
{
struct V_1 * V_2 ;
F_95 () ;
V_2 = F_83 ( V_4 , V_151 , V_5 , V_11 , V_12 , V_8 ) ;
F_28 () ;
return V_2 ;
}
struct V_1 *
F_125 ( struct V_4 * V_4 , T_3 V_151 ,
const T_2 * V_5 , const T_2 * V_6 ,
T_5 V_12 , unsigned short V_8 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 = F_86 ( V_4 , V_151 , V_5 , V_6 , V_12 , V_8 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
struct V_1 *
F_126 ( struct V_4 * V_4 , const struct V_185 * V_151 , T_5 V_59 , T_3 V_7 ,
T_5 V_12 , const T_2 * V_5 ,
const T_2 * V_6 , int V_186 , unsigned short V_8 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 = F_109 ( V_4 , V_151 , V_8 , V_59 , V_7 , V_12 , V_5 , V_6 , V_186 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
int
F_127 ( struct V_145 * * V_214 , struct V_145 * * V_215 , int V_216 ,
unsigned short V_8 , struct V_4 * V_4 )
{
int V_49 = 0 ;
struct V_46 * V_47 = F_25 ( V_8 ) ;
if ( ! V_47 )
return - V_50 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( V_47 -> V_217 )
V_49 = V_47 -> V_217 ( V_214 , V_215 , V_216 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
F_28 () ;
return V_49 ;
}
int
F_128 ( struct V_1 * * V_214 , struct V_1 * * V_215 , int V_216 ,
unsigned short V_8 )
{
int V_49 = 0 ;
struct V_46 * V_47 = F_25 ( V_8 ) ;
struct V_4 * V_4 = V_117 ( * V_215 ) ;
if ( ! V_47 )
return - V_50 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( V_47 -> V_218 )
V_49 = V_47 -> V_218 ( V_214 , V_215 , V_216 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
F_28 () ;
return V_49 ;
}
static struct V_1 * F_111 ( struct V_4 * V_4 , T_3 V_151 , T_3 V_195 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
F_74 (x, net->xfrm.state_bydst+i, bydst) {
if ( V_2 -> V_94 . V_195 == V_195 &&
( V_151 & V_2 -> V_151 . V_152 ) == V_2 -> V_151 . V_153 &&
V_2 -> V_94 . V_95 == V_114 ) {
F_79 ( V_2 ) ;
return V_2 ;
}
}
}
return NULL ;
}
struct V_1 * F_129 ( struct V_4 * V_4 , T_3 V_151 , T_3 V_195 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 = F_111 ( V_4 , V_151 , V_195 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
T_3 F_130 ( void )
{
T_3 V_219 ;
static T_6 V_220 ;
do {
V_219 = F_131 ( & V_220 ) ;
} while ( ! V_219 );
return V_219 ;
}
int F_132 ( T_5 V_12 , T_3 V_221 , T_3 V_222 )
{
switch ( V_12 ) {
case V_223 :
case V_224 :
break;
case V_225 :
if ( V_222 >= 0x10000 )
return - V_63 ;
break;
default:
return - V_63 ;
}
if ( V_221 > V_222 )
return - V_63 ;
return 0 ;
}
int F_133 ( struct V_1 * V_2 , T_3 V_226 , T_3 V_227 )
{
struct V_4 * V_4 = V_117 ( V_2 ) ;
unsigned int V_21 ;
struct V_1 * V_164 ;
int V_49 = - V_54 ;
T_4 V_228 = F_134 ( V_226 ) ;
T_4 V_229 = F_134 ( V_227 ) ;
T_3 V_151 = V_2 -> V_151 . V_153 & V_2 -> V_151 . V_152 ;
F_17 ( & V_2 -> V_93 ) ;
if ( V_2 -> V_94 . V_95 == V_96 )
goto V_230;
V_49 = 0 ;
if ( V_2 -> V_22 . V_11 )
goto V_230;
V_49 = - V_54 ;
if ( V_228 == V_229 ) {
V_164 = F_124 ( V_4 , V_151 , & V_2 -> V_22 . V_5 , V_228 , V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ) ;
if ( V_164 ) {
F_71 ( V_164 ) ;
goto V_230;
}
V_2 -> V_22 . V_11 = V_228 ;
} else {
T_3 V_11 = 0 ;
for ( V_21 = 0 ; V_21 < V_227 - V_226 + 1 ; V_21 ++ ) {
V_11 = V_226 + F_135 () % ( V_227 - V_226 + 1 ) ;
V_164 = F_124 ( V_4 , V_151 , & V_2 -> V_22 . V_5 , F_134 ( V_11 ) , V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ) ;
if ( V_164 == NULL ) {
V_2 -> V_22 . V_11 = F_134 ( V_11 ) ;
break;
}
F_71 ( V_164 ) ;
}
}
if ( V_2 -> V_22 . V_11 ) {
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_21 = F_7 ( V_4 , & V_2 -> V_22 . V_5 , V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ) ;
F_11 ( & V_2 -> V_26 , V_4 -> V_9 . V_44 + V_21 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
V_49 = 0 ;
}
V_230:
F_22 ( & V_2 -> V_93 ) ;
return V_49 ;
}
static bool F_136 ( struct V_1 * V_2 ,
struct V_231 * V_232 )
{
if ( V_232 ) {
if ( ( V_232 -> V_8 == V_187 ||
V_232 -> V_8 == V_191 ) &&
V_2 -> V_23 . V_8 != V_232 -> V_8 )
return false ;
return F_137 ( & V_2 -> V_23 . V_6 , & V_232 -> V_6 ,
V_232 -> V_233 ) &&
F_137 ( & V_2 -> V_22 . V_5 , & V_232 -> V_5 ,
V_232 -> V_234 ) ;
}
return true ;
}
int V_180 ( struct V_4 * V_4 , struct V_180 * V_235 ,
int (* F_138)( struct V_1 * , int , void * ) ,
void * V_236 )
{
struct V_1 * V_95 ;
struct V_180 * V_2 ;
int V_49 = 0 ;
if ( V_235 -> V_195 != 0 && F_139 ( & V_235 -> V_119 ) )
return 0 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( F_139 ( & V_235 -> V_119 ) )
V_2 = F_140 ( & V_4 -> V_9 . V_176 , struct V_180 , V_119 ) ;
else
V_2 = F_140 ( & V_235 -> V_119 , struct V_180 , V_119 ) ;
F_141 (x, &net->xfrm.state_all, all) {
if ( V_2 -> V_95 == V_96 )
continue;
V_95 = F_14 ( V_2 , struct V_1 , V_94 ) ;
if ( ! F_75 ( V_95 -> V_22 . V_12 , V_235 -> V_12 ) )
continue;
if ( ! F_136 ( V_95 , V_235 -> V_232 ) )
continue;
V_49 = F_138 ( V_95 , V_235 -> V_195 , V_236 ) ;
if ( V_49 ) {
F_142 ( & V_235 -> V_119 , & V_2 -> V_119 ) ;
goto V_66;
}
V_235 -> V_195 ++ ;
}
if ( V_235 -> V_195 == 0 ) {
V_49 = - V_54 ;
goto V_66;
}
F_143 ( & V_235 -> V_119 ) ;
V_66:
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_49 ;
}
void F_144 ( struct V_180 * V_235 , T_5 V_12 ,
struct V_231 * V_232 )
{
F_60 ( & V_235 -> V_119 ) ;
V_235 -> V_12 = V_12 ;
V_235 -> V_95 = V_96 ;
V_235 -> V_195 = 0 ;
V_235 -> V_232 = V_232 ;
}
void F_145 ( struct V_180 * V_235 , struct V_4 * V_4 )
{
F_43 ( V_235 -> V_232 ) ;
if ( F_139 ( & V_235 -> V_119 ) )
return;
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_69 ( & V_235 -> V_119 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
}
static void V_122 ( unsigned long V_236 )
{
struct V_1 * V_2 = (struct V_1 * ) V_236 ;
F_49 ( & V_2 -> V_93 ) ;
if ( V_2 -> V_94 . V_95 == V_160 ) {
if ( F_146 ( V_117 ( V_2 ) ) )
V_2 -> V_237 -> V_238 ( V_2 , V_239 ) ;
else
V_2 -> V_104 |= V_240 ;
}
F_55 ( & V_2 -> V_93 ) ;
}
void F_147 ( struct V_156 * V_241 , int V_242 , const struct V_168 * V_169 )
{
struct V_243 * V_94 ;
F_95 () ;
F_148 (km, &xfrm_km_list, list)
if ( V_94 -> V_244 )
V_94 -> V_244 ( V_241 , V_242 , V_169 ) ;
F_28 () ;
}
void F_149 ( struct V_1 * V_2 , const struct V_168 * V_169 )
{
struct V_243 * V_94 ;
F_95 () ;
F_148 (km, &xfrm_km_list, list)
if ( V_94 -> V_238 )
V_94 -> V_238 ( V_2 , V_169 ) ;
F_28 () ;
}
void F_50 ( struct V_1 * V_2 , int V_245 , T_3 V_246 )
{
struct V_168 V_169 ;
V_169 . V_236 . V_245 = V_245 ;
V_169 . V_246 = V_246 ;
V_169 . V_247 = V_248 ;
F_149 ( V_2 , & V_169 ) ;
}
int F_99 ( struct V_1 * V_2 , struct V_145 * V_249 , struct V_156 * V_157 )
{
int V_49 = - V_63 , V_250 ;
struct V_243 * V_94 ;
F_95 () ;
F_148 (km, &xfrm_km_list, list) {
V_250 = V_94 -> V_251 ( V_2 , V_249 , V_157 ) ;
if ( ! V_250 )
V_49 = V_250 ;
}
F_28 () ;
return V_49 ;
}
int F_150 ( struct V_1 * V_2 , T_2 * V_252 , T_7 V_253 )
{
int V_49 = - V_63 ;
struct V_243 * V_94 ;
F_95 () ;
F_148 (km, &xfrm_km_list, list) {
if ( V_94 -> V_254 )
V_49 = V_94 -> V_254 ( V_2 , V_252 , V_253 ) ;
if ( ! V_49 )
break;
}
F_28 () ;
return V_49 ;
}
void F_151 ( struct V_156 * V_157 , int V_242 , int V_245 , T_3 V_246 )
{
struct V_168 V_169 ;
V_169 . V_236 . V_245 = V_245 ;
V_169 . V_246 = V_246 ;
V_169 . V_247 = V_255 ;
F_147 ( V_157 , V_242 , & V_169 ) ;
}
int F_152 ( const struct V_256 * V_148 , T_5 V_242 , T_5 type ,
const struct V_204 * V_152 , int V_257 ,
const struct V_258 * V_259 )
{
int V_49 = - V_63 ;
int V_260 ;
struct V_243 * V_94 ;
F_95 () ;
F_148 (km, &xfrm_km_list, list) {
if ( V_94 -> V_261 ) {
V_260 = V_94 -> V_261 ( V_148 , V_242 , type , V_152 , V_257 , V_259 ) ;
if ( ! V_260 )
V_49 = V_260 ;
}
}
F_28 () ;
return V_49 ;
}
int F_153 ( struct V_4 * V_4 , T_5 V_12 , struct V_256 * V_148 , T_2 * V_262 )
{
int V_49 = - V_63 ;
int V_260 ;
struct V_243 * V_94 ;
F_95 () ;
F_148 (km, &xfrm_km_list, list) {
if ( V_94 -> V_263 ) {
V_260 = V_94 -> V_263 ( V_4 , V_12 , V_148 , V_262 ) ;
if ( ! V_260 )
V_49 = V_260 ;
}
}
F_28 () ;
return V_49 ;
}
bool F_97 ( const struct V_168 * V_169 )
{
struct V_243 * V_94 ;
bool V_264 = false ;
F_95 () ;
F_148 (km, &xfrm_km_list, list) {
if ( V_94 -> V_264 && V_94 -> V_264 ( V_169 ) ) {
V_264 = true ;
break;
}
}
F_28 () ;
return V_264 ;
}
int F_154 ( struct V_265 * V_266 , int V_267 , T_5 T_8 * V_268 , int V_269 )
{
int V_49 ;
T_5 * V_236 ;
struct V_243 * V_94 ;
struct V_156 * V_157 = NULL ;
if ( V_269 <= 0 || V_269 > V_270 )
return - V_271 ;
V_236 = F_155 ( V_269 , V_201 ) ;
if ( ! V_236 )
return - V_173 ;
V_49 = - V_272 ;
if ( F_156 ( V_236 , V_268 , V_269 ) )
goto V_66;
V_49 = - V_63 ;
F_95 () ;
F_148 (km, &xfrm_km_list, list) {
V_157 = V_94 -> V_273 ( V_266 , V_267 , V_236 ,
V_269 , & V_49 ) ;
if ( V_49 >= 0 )
break;
}
F_28 () ;
if ( V_49 >= 0 ) {
F_157 ( V_266 , V_49 , V_157 ) ;
F_158 ( V_157 ) ;
V_49 = 0 ;
}
V_66:
F_43 ( V_236 ) ;
return V_49 ;
}
int F_159 ( struct V_243 * V_94 )
{
F_17 ( & V_274 ) ;
F_160 ( & V_94 -> V_14 , & V_275 ) ;
F_22 ( & V_274 ) ;
return 0 ;
}
int F_161 ( struct V_243 * V_94 )
{
F_17 ( & V_274 ) ;
F_162 ( & V_94 -> V_14 ) ;
F_22 ( & V_274 ) ;
F_23 () ;
return 0 ;
}
int F_163 ( struct V_46 * V_47 )
{
int V_49 = 0 ;
if ( F_66 ( V_47 -> V_8 >= V_276 ) )
return - V_50 ;
F_17 ( & V_277 ) ;
if ( F_26 ( V_46 [ V_47 -> V_8 ] != NULL ) )
V_49 = - V_53 ;
else
F_20 ( V_46 [ V_47 -> V_8 ] , V_47 ) ;
F_22 ( & V_277 ) ;
return V_49 ;
}
int F_164 ( struct V_46 * V_47 )
{
int V_49 = 0 , V_8 = V_47 -> V_8 ;
if ( F_66 ( V_8 >= V_276 ) )
return - V_50 ;
F_17 ( & V_277 ) ;
if ( F_27 ( V_46 [ V_47 -> V_8 ] != NULL ) ) {
if ( F_165 ( V_46 [ V_8 ] ) != V_47 )
V_49 = - V_63 ;
else
F_166 ( V_46 [ V_47 -> V_8 ] , NULL ) ;
}
F_22 ( & V_277 ) ;
F_23 () ;
return V_49 ;
}
struct V_46 * F_82 ( unsigned int V_8 )
{
if ( F_26 ( V_8 >= V_276 ) )
return NULL ;
return F_167 ( V_46 [ V_8 ] ) ;
}
struct V_46 * F_25 ( unsigned int V_8 )
{
struct V_46 * V_47 ;
if ( F_26 ( V_8 >= V_276 ) )
return NULL ;
F_95 () ;
V_47 = F_167 ( V_46 [ V_8 ] ) ;
if ( F_26 ( ! V_47 ) )
F_28 () ;
return V_47 ;
}
void F_168 ( struct V_1 * V_2 )
{
if ( V_2 -> V_278 ) {
struct V_1 * V_249 = V_2 -> V_278 ;
if ( F_169 ( & V_249 -> V_118 ) == 2 )
F_72 ( V_249 ) ;
F_170 ( & V_249 -> V_118 ) ;
F_71 ( V_249 ) ;
V_2 -> V_278 = NULL ;
}
}
int F_171 ( struct V_1 * V_2 , int V_279 )
{
const struct V_45 * type = F_31 ( V_2 -> type ) ;
if ( V_2 -> V_94 . V_95 == V_160 &&
type && type -> V_280 )
return type -> V_280 ( V_2 , V_279 ) ;
return V_279 - V_2 -> V_23 . V_281 ;
}
int F_172 ( struct V_1 * V_2 , bool V_282 )
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
if ( V_47 -> V_283 )
V_49 = V_47 -> V_283 ( V_2 ) ;
F_28 () ;
if ( V_49 )
goto error;
V_49 = - V_284 ;
if ( V_2 -> V_148 . V_8 != V_285 ) {
V_76 = F_38 ( V_2 -> V_23 . V_59 , V_2 -> V_148 . V_8 ) ;
if ( V_76 == NULL )
goto error;
if ( ! ( V_76 -> V_170 & V_286 ) &&
V_8 != V_2 -> V_148 . V_8 ) {
F_39 ( V_76 ) ;
goto error;
}
V_2 -> V_76 = V_76 ;
} else {
struct V_58 * V_77 ;
int V_287 = V_187 ;
V_76 = F_38 ( V_2 -> V_23 . V_59 , V_2 -> V_23 . V_8 ) ;
if ( V_76 == NULL )
goto error;
if ( ! ( V_76 -> V_170 & V_286 ) ) {
F_39 ( V_76 ) ;
goto error;
}
V_2 -> V_76 = V_76 ;
if ( V_2 -> V_23 . V_8 == V_187 )
V_287 = V_191 ;
V_77 = F_38 ( V_2 -> V_23 . V_59 , V_287 ) ;
if ( V_77 ) {
if ( V_77 -> V_170 & V_286 )
V_2 -> V_77 = V_77 ;
else
F_39 ( V_77 ) ;
}
}
V_2 -> type = F_30 ( V_2 -> V_22 . V_12 , V_8 ) ;
if ( V_2 -> type == NULL )
goto error;
V_49 = V_2 -> type -> V_288 ( V_2 ) ;
if ( V_49 )
goto error;
V_2 -> V_78 = F_38 ( V_2 -> V_23 . V_59 , V_8 ) ;
if ( V_2 -> V_78 == NULL ) {
V_49 = - V_284 ;
goto error;
}
if ( V_282 ) {
V_49 = F_173 ( V_2 ) ;
if ( V_49 )
goto error;
}
V_2 -> V_94 . V_95 = V_160 ;
error:
return V_49 ;
}
int F_118 ( struct V_1 * V_2 )
{
return F_172 ( V_2 , true ) ;
}
int T_9 F_174 ( struct V_4 * V_4 )
{
unsigned int V_289 ;
F_60 ( & V_4 -> V_9 . V_176 ) ;
V_289 = sizeof( struct V_13 ) * 8 ;
V_4 -> V_9 . V_42 = F_15 ( V_289 ) ;
if ( ! V_4 -> V_9 . V_42 )
goto V_290;
V_4 -> V_9 . V_43 = F_15 ( V_289 ) ;
if ( ! V_4 -> V_9 . V_43 )
goto V_291;
V_4 -> V_9 . V_44 = F_15 ( V_289 ) ;
if ( ! V_4 -> V_9 . V_44 )
goto V_292;
V_4 -> V_9 . V_10 = ( ( V_289 / sizeof( struct V_13 ) ) - 1 ) ;
V_4 -> V_9 . V_133 = 0 ;
F_175 ( & V_4 -> V_9 . V_29 , F_13 ) ;
F_64 ( & V_4 -> V_9 . V_40 ) ;
return 0 ;
V_292:
F_16 ( V_4 -> V_9 . V_43 , V_289 ) ;
V_291:
F_16 ( V_4 -> V_9 . V_42 , V_289 ) ;
V_290:
return - V_173 ;
}
void F_176 ( struct V_4 * V_4 )
{
unsigned int V_289 ;
F_177 ( & V_4 -> V_9 . V_29 ) ;
F_77 ( V_4 , V_194 , false ) ;
F_177 ( & V_131 ) ;
F_66 ( ! F_139 ( & V_4 -> V_9 . V_176 ) ) ;
V_289 = ( V_4 -> V_9 . V_10 + 1 ) * sizeof( struct V_13 ) ;
F_66 ( ! F_178 ( V_4 -> V_9 . V_44 ) ) ;
F_16 ( V_4 -> V_9 . V_44 , V_289 ) ;
F_66 ( ! F_178 ( V_4 -> V_9 . V_43 ) ) ;
F_16 ( V_4 -> V_9 . V_43 , V_289 ) ;
F_66 ( ! F_178 ( V_4 -> V_9 . V_42 ) ) ;
F_16 ( V_4 -> V_9 . V_42 , V_289 ) ;
}
static void F_179 ( struct V_1 * V_2 ,
struct V_293 * V_294 )
{
struct V_295 * V_296 = V_2 -> V_174 ;
T_3 V_11 = F_180 ( V_2 -> V_22 . V_11 ) ;
if ( V_296 )
F_181 ( V_294 , L_3 ,
V_296 -> V_297 , V_296 -> V_298 , V_296 -> V_299 ) ;
switch ( V_2 -> V_23 . V_8 ) {
case V_187 :
F_181 ( V_294 , L_4 ,
& V_2 -> V_23 . V_6 . V_188 , & V_2 -> V_22 . V_5 . V_188 ) ;
break;
case V_191 :
F_181 ( V_294 , L_5 ,
V_2 -> V_23 . V_6 . V_300 , V_2 -> V_22 . V_5 . V_300 ) ;
break;
}
F_181 ( V_294 , L_6 , V_11 , V_11 ) ;
}
static void F_182 ( struct V_301 * V_302 , T_10 V_8 ,
struct V_293 * V_294 )
{
const struct V_303 * V_304 ;
const struct V_305 * V_306 ;
switch ( V_8 ) {
case V_187 :
V_304 = F_183 ( V_302 ) ;
F_181 ( V_294 , L_4 ,
& V_304 -> V_6 , & V_304 -> V_5 ) ;
break;
case V_191 :
V_306 = F_184 ( V_302 ) ;
F_181 ( V_294 ,
L_7 ,
& V_306 -> V_6 , & V_306 -> V_5 ,
V_306 -> V_307 [ 0 ] & 0x0f ,
V_306 -> V_307 [ 1 ] ,
V_306 -> V_307 [ 2 ] ) ;
break;
}
}
void F_185 ( struct V_1 * V_2 , int V_308 , bool V_134 )
{
struct V_293 * V_294 ;
V_294 = F_186 ( L_8 ) ;
if ( V_294 == NULL )
return;
F_187 ( V_134 , V_294 ) ;
F_179 ( V_2 , V_294 ) ;
F_181 ( V_294 , L_9 , V_308 ) ;
F_188 ( V_294 ) ;
}
void F_54 ( struct V_1 * V_2 , int V_308 , bool V_134 )
{
struct V_293 * V_294 ;
V_294 = F_186 ( L_10 ) ;
if ( V_294 == NULL )
return;
F_187 ( V_134 , V_294 ) ;
F_179 ( V_2 , V_294 ) ;
F_181 ( V_294 , L_9 , V_308 ) ;
F_188 ( V_294 ) ;
}
void F_189 ( struct V_1 * V_2 ,
struct V_301 * V_302 )
{
struct V_293 * V_294 ;
T_3 V_11 ;
V_294 = F_186 ( L_11 ) ;
if ( V_294 == NULL )
return;
F_182 ( V_302 , V_2 -> V_23 . V_8 , V_294 ) ;
V_11 = F_180 ( V_2 -> V_22 . V_11 ) ;
F_181 ( V_294 , L_6 , V_11 , V_11 ) ;
F_188 ( V_294 ) ;
}
void F_190 ( struct V_1 * V_2 ,
struct V_301 * V_302 , T_4 V_309 )
{
struct V_293 * V_294 ;
T_3 V_11 ;
V_294 = F_186 ( L_12 ) ;
if ( V_294 == NULL )
return;
F_182 ( V_302 , V_2 -> V_23 . V_8 , V_294 ) ;
V_11 = F_180 ( V_2 -> V_22 . V_11 ) ;
F_181 ( V_294 , L_13 ,
V_11 , V_11 , F_180 ( V_309 ) ) ;
F_188 ( V_294 ) ;
}
void F_191 ( struct V_301 * V_302 , T_10 V_8 )
{
struct V_293 * V_294 ;
V_294 = F_186 ( L_14 ) ;
if ( V_294 == NULL )
return;
F_182 ( V_302 , V_8 , V_294 ) ;
F_188 ( V_294 ) ;
}
void F_192 ( struct V_301 * V_302 , T_10 V_8 ,
T_4 V_310 , T_4 V_309 )
{
struct V_293 * V_294 ;
T_3 V_11 ;
V_294 = F_186 ( L_14 ) ;
if ( V_294 == NULL )
return;
F_182 ( V_302 , V_8 , V_294 ) ;
V_11 = F_180 ( V_310 ) ;
F_181 ( V_294 , L_13 ,
V_11 , V_11 , F_180 ( V_309 ) ) ;
F_188 ( V_294 ) ;
}
void F_193 ( struct V_1 * V_2 ,
struct V_301 * V_302 , T_5 V_12 )
{
struct V_293 * V_294 ;
T_4 V_310 ;
T_4 V_309 ;
V_294 = F_186 ( L_15 ) ;
if ( V_294 == NULL )
return;
F_182 ( V_302 , V_2 -> V_23 . V_8 , V_294 ) ;
if ( F_194 ( V_302 , V_12 , & V_310 , & V_309 ) == 0 ) {
T_3 V_11 = F_180 ( V_310 ) ;
F_181 ( V_294 , L_13 ,
V_11 , V_11 , F_180 ( V_309 ) ) ;
}
F_188 ( V_294 ) ;
}
