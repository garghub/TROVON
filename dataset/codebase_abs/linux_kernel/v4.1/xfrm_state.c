static inline unsigned int F_1 ( struct V_1 * V_1 ,
const T_1 * V_2 ,
const T_1 * V_3 ,
T_2 V_4 ,
unsigned short V_5 )
{
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_1 -> V_6 . V_7 ) ;
}
static inline unsigned int F_3 ( struct V_1 * V_1 ,
const T_1 * V_2 ,
const T_1 * V_3 ,
unsigned short V_5 )
{
return F_4 ( V_2 , V_3 , V_5 , V_1 -> V_6 . V_7 ) ;
}
static inline unsigned int
F_5 ( struct V_1 * V_1 , const T_1 * V_2 ,
T_3 V_8 , T_4 V_9 , unsigned short V_5 )
{
return F_6 ( V_2 , V_8 , V_9 , V_5 , V_1 -> V_6 . V_7 ) ;
}
static void F_7 ( struct V_10 * V_11 ,
struct V_10 * V_12 ,
struct V_10 * V_13 ,
struct V_10 * V_14 ,
unsigned int V_15 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 ;
F_8 (x, tmp, list, bydst) {
unsigned int V_20 ;
V_20 = F_2 ( & V_19 -> V_21 . V_2 , & V_19 -> V_22 . V_3 ,
V_19 -> V_22 . V_4 , V_19 -> V_22 . V_5 ,
V_15 ) ;
F_9 ( & V_19 -> V_23 , V_12 + V_20 ) ;
V_20 = F_4 ( & V_19 -> V_21 . V_2 , & V_19 -> V_22 . V_3 ,
V_19 -> V_22 . V_5 ,
V_15 ) ;
F_9 ( & V_19 -> V_24 , V_13 + V_20 ) ;
if ( V_19 -> V_21 . V_8 ) {
V_20 = F_6 ( & V_19 -> V_21 . V_2 , V_19 -> V_21 . V_8 ,
V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ,
V_15 ) ;
F_9 ( & V_19 -> V_25 , V_14 + V_20 ) ;
}
}
}
static unsigned long F_10 ( unsigned int V_7 )
{
return ( ( V_7 + 1 ) << 1 ) * sizeof( struct V_10 ) ;
}
static void F_11 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = F_12 ( V_27 , struct V_1 , V_6 . V_28 ) ;
struct V_10 * V_29 , * V_30 , * V_31 , * V_32 , * V_33 , * V_34 ;
unsigned long V_35 , V_36 ;
unsigned int V_15 , V_37 ;
int V_38 ;
V_35 = F_10 ( V_1 -> V_6 . V_7 ) ;
V_29 = F_13 ( V_35 ) ;
if ( ! V_29 )
return;
V_30 = F_13 ( V_35 ) ;
if ( ! V_30 ) {
F_14 ( V_29 , V_35 ) ;
return;
}
V_31 = F_13 ( V_35 ) ;
if ( ! V_31 ) {
F_14 ( V_29 , V_35 ) ;
F_14 ( V_30 , V_35 ) ;
return;
}
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_15 = ( V_35 / sizeof( struct V_10 ) ) - 1U ;
for ( V_38 = V_1 -> V_6 . V_7 ; V_38 >= 0 ; V_38 -- )
F_7 ( V_1 -> V_6 . V_40 + V_38 , V_29 , V_30 , V_31 ,
V_15 ) ;
V_32 = V_1 -> V_6 . V_40 ;
V_33 = V_1 -> V_6 . V_41 ;
V_34 = V_1 -> V_6 . V_42 ;
V_37 = V_1 -> V_6 . V_7 ;
V_1 -> V_6 . V_40 = V_29 ;
V_1 -> V_6 . V_41 = V_30 ;
V_1 -> V_6 . V_42 = V_31 ;
V_1 -> V_6 . V_7 = V_15 ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
V_36 = ( V_37 + 1 ) * sizeof( struct V_10 ) ;
F_14 ( V_32 , V_36 ) ;
F_14 ( V_33 , V_36 ) ;
F_14 ( V_34 , V_36 ) ;
}
int F_17 ( const struct V_43 * type , unsigned short V_5 )
{
struct V_44 * V_45 = F_18 ( V_5 ) ;
const struct V_43 * * V_46 ;
int V_47 = 0 ;
if ( F_19 ( V_45 == NULL ) )
return - V_48 ;
V_46 = V_45 -> V_49 ;
F_15 ( & V_50 ) ;
if ( F_20 ( V_46 [ type -> V_9 ] == NULL ) )
V_46 [ type -> V_9 ] = type ;
else
V_47 = - V_51 ;
F_16 ( & V_50 ) ;
F_21 ( V_45 ) ;
return V_47 ;
}
int F_22 ( const struct V_43 * type , unsigned short V_5 )
{
struct V_44 * V_45 = F_18 ( V_5 ) ;
const struct V_43 * * V_46 ;
int V_47 = 0 ;
if ( F_19 ( V_45 == NULL ) )
return - V_48 ;
V_46 = V_45 -> V_49 ;
F_15 ( & V_50 ) ;
if ( F_19 ( V_46 [ type -> V_9 ] != type ) )
V_47 = - V_52 ;
else
V_46 [ type -> V_9 ] = NULL ;
F_16 ( & V_50 ) ;
F_21 ( V_45 ) ;
return V_47 ;
}
static const struct V_43 * F_23 ( T_4 V_9 , unsigned short V_5 )
{
struct V_44 * V_45 ;
const struct V_43 * * V_46 ;
const struct V_43 * type ;
int V_53 = 0 ;
V_54:
V_45 = F_18 ( V_5 ) ;
if ( F_19 ( V_45 == NULL ) )
return NULL ;
V_46 = V_45 -> V_49 ;
type = V_46 [ V_9 ] ;
if ( F_19 ( type && ! F_24 ( type -> V_55 ) ) )
type = NULL ;
if ( ! type && ! V_53 ) {
F_21 ( V_45 ) ;
F_25 ( L_1 , V_5 , V_9 ) ;
V_53 = 1 ;
goto V_54;
}
F_21 ( V_45 ) ;
return type ;
}
static void F_26 ( const struct V_43 * type )
{
F_27 ( type -> V_55 ) ;
}
int F_28 ( struct V_56 * V_57 , int V_5 )
{
struct V_44 * V_45 ;
struct V_56 * * V_58 ;
int V_47 ;
if ( F_19 ( V_57 -> V_59 >= V_60 ) )
return - V_61 ;
V_45 = F_18 ( V_5 ) ;
if ( F_19 ( V_45 == NULL ) )
return - V_48 ;
V_47 = - V_51 ;
V_58 = V_45 -> V_62 ;
F_15 ( & V_63 ) ;
if ( V_58 [ V_57 -> V_59 ] )
goto V_64;
V_47 = - V_52 ;
if ( ! F_24 ( V_45 -> V_55 ) )
goto V_64;
V_57 -> V_45 = V_45 ;
V_58 [ V_57 -> V_59 ] = V_57 ;
V_47 = 0 ;
V_64:
F_16 ( & V_63 ) ;
F_21 ( V_45 ) ;
return V_47 ;
}
int F_29 ( struct V_56 * V_57 , int V_5 )
{
struct V_44 * V_45 ;
struct V_56 * * V_58 ;
int V_47 ;
if ( F_19 ( V_57 -> V_59 >= V_60 ) )
return - V_61 ;
V_45 = F_18 ( V_5 ) ;
if ( F_19 ( V_45 == NULL ) )
return - V_48 ;
V_47 = - V_52 ;
V_58 = V_45 -> V_62 ;
F_15 ( & V_63 ) ;
if ( F_20 ( V_58 [ V_57 -> V_59 ] == V_57 ) ) {
V_58 [ V_57 -> V_59 ] = NULL ;
F_27 ( V_57 -> V_45 -> V_55 ) ;
V_47 = 0 ;
}
F_16 ( & V_63 ) ;
F_21 ( V_45 ) ;
return V_47 ;
}
static struct V_56 * F_30 ( unsigned int V_59 , int V_5 )
{
struct V_44 * V_45 ;
struct V_56 * V_57 ;
int V_53 = 0 ;
if ( F_19 ( V_59 >= V_60 ) )
return NULL ;
V_54:
V_45 = F_18 ( V_5 ) ;
if ( F_19 ( V_45 == NULL ) )
return NULL ;
V_57 = V_45 -> V_62 [ V_59 ] ;
if ( F_19 ( V_57 && ! F_24 ( V_57 -> V_55 ) ) )
V_57 = NULL ;
if ( ! V_57 && ! V_53 ) {
F_21 ( V_45 ) ;
F_25 ( L_2 , V_5 , V_59 ) ;
V_53 = 1 ;
goto V_54;
}
F_21 ( V_45 ) ;
return V_57 ;
}
static void F_31 ( struct V_56 * V_57 )
{
F_27 ( V_57 -> V_55 ) ;
}
static void F_32 ( struct V_18 * V_19 )
{
F_33 ( & V_19 -> V_65 ) ;
F_34 ( & V_19 -> V_66 ) ;
F_35 ( V_19 -> V_67 ) ;
F_35 ( V_19 -> V_68 ) ;
F_35 ( V_19 -> V_69 ) ;
F_35 ( V_19 -> V_59 ) ;
F_35 ( V_19 -> V_70 ) ;
F_35 ( V_19 -> V_71 ) ;
F_35 ( V_19 -> V_72 ) ;
if ( V_19 -> V_73 )
F_31 ( V_19 -> V_73 ) ;
if ( V_19 -> V_74 )
F_31 ( V_19 -> V_74 ) ;
if ( V_19 -> V_75 )
F_31 ( V_19 -> V_75 ) ;
if ( V_19 -> type ) {
V_19 -> type -> V_76 ( V_19 ) ;
F_26 ( V_19 -> type ) ;
}
F_36 ( V_19 ) ;
F_35 ( V_19 ) ;
}
static void F_37 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = F_12 ( V_27 , struct V_1 , V_6 . V_77 ) ;
struct V_18 * V_19 ;
struct V_16 * V_17 ;
struct V_10 V_78 ;
F_15 ( & V_79 ) ;
F_38 ( & V_1 -> V_6 . V_80 , & V_78 ) ;
F_16 ( & V_79 ) ;
F_8 (x, tmp, &gc_list, gclist)
F_32 ( V_19 ) ;
}
static inline unsigned long F_39 ( long V_81 )
{
if ( V_81 >= ( V_82 - 1 ) / V_83 )
return V_82 - 1 ;
else
return V_81 * V_83 ;
}
static enum V_84 F_40 ( struct V_85 * V_86 )
{
struct V_87 * V_88 = F_12 ( V_86 , struct V_87 , V_89 ) ;
struct V_18 * V_19 = F_12 ( V_88 , struct V_18 , V_65 ) ;
unsigned long V_90 = F_41 () ;
long V_91 = V_92 ;
int V_93 = 0 ;
int V_47 = 0 ;
F_42 ( & V_19 -> V_94 ) ;
if ( V_19 -> V_95 . V_96 == V_97 )
goto V_64;
if ( V_19 -> V_95 . V_96 == V_98 )
goto V_99;
if ( V_19 -> V_100 . V_101 ) {
long V_102 = V_19 -> V_100 . V_101 +
V_19 -> V_103 . V_104 - V_90 ;
if ( V_102 <= 0 ) {
if ( V_19 -> V_105 & V_106 ) {
V_19 -> V_103 . V_104 = V_90 - V_19 -> V_107 - 1 ;
V_102 = V_19 -> V_100 . V_101 - V_19 -> V_107 ;
} else
goto V_99;
}
if ( V_102 < V_91 )
V_91 = V_102 ;
}
if ( V_19 -> V_100 . V_108 ) {
long V_102 = V_19 -> V_100 . V_108 +
( V_19 -> V_103 . V_109 ? : V_90 ) - V_90 ;
if ( V_102 <= 0 )
goto V_99;
if ( V_102 < V_91 )
V_91 = V_102 ;
}
if ( V_19 -> V_95 . V_110 )
goto V_111;
if ( V_19 -> V_100 . V_112 ) {
long V_102 = V_19 -> V_100 . V_112 +
V_19 -> V_103 . V_104 - V_90 ;
if ( V_102 <= 0 ) {
V_93 = 1 ;
V_19 -> V_105 &= ~ V_106 ;
} else if ( V_102 < V_91 ) {
V_91 = V_102 ;
V_19 -> V_105 |= V_106 ;
V_19 -> V_107 = V_102 ;
}
}
if ( V_19 -> V_100 . V_113 ) {
long V_102 = V_19 -> V_100 . V_113 +
( V_19 -> V_103 . V_109 ? : V_90 ) - V_90 ;
if ( V_102 <= 0 )
V_93 = 1 ;
else if ( V_102 < V_91 )
V_91 = V_102 ;
}
V_19 -> V_95 . V_110 = V_93 ;
if ( V_93 )
F_43 ( V_19 , 0 , 0 ) ;
V_111:
if ( V_91 != V_92 ) {
F_44 ( & V_19 -> V_65 , F_45 ( V_91 , 0 ) , V_114 ) ;
}
goto V_64;
V_99:
if ( V_19 -> V_95 . V_96 == V_115 && V_19 -> V_21 . V_8 == 0 )
V_19 -> V_95 . V_96 = V_98 ;
V_47 = F_46 ( V_19 ) ;
if ( ! V_47 )
F_43 ( V_19 , 1 , 0 ) ;
F_47 ( V_19 , V_47 ? 0 : 1 , true ) ;
V_64:
F_48 ( & V_19 -> V_94 ) ;
return V_116 ;
}
struct V_18 * F_49 ( struct V_1 * V_1 )
{
struct V_18 * V_19 ;
V_19 = F_50 ( sizeof( struct V_18 ) , V_117 ) ;
if ( V_19 ) {
F_51 ( & V_19 -> V_118 , V_1 ) ;
F_52 ( & V_19 -> V_119 , 1 ) ;
F_52 ( & V_19 -> V_120 , 0 ) ;
F_53 ( & V_19 -> V_95 . V_121 ) ;
F_54 ( & V_19 -> V_23 ) ;
F_54 ( & V_19 -> V_24 ) ;
F_54 ( & V_19 -> V_25 ) ;
F_55 ( & V_19 -> V_65 , F_40 ,
V_122 , V_123 ) ;
F_56 ( & V_19 -> V_66 , V_124 ,
( unsigned long ) V_19 ) ;
V_19 -> V_103 . V_104 = F_41 () ;
V_19 -> V_100 . V_125 = V_126 ;
V_19 -> V_100 . V_127 = V_126 ;
V_19 -> V_100 . V_128 = V_126 ;
V_19 -> V_100 . V_129 = V_126 ;
V_19 -> V_130 = 0 ;
V_19 -> V_131 = 0 ;
V_19 -> V_73 = NULL ;
V_19 -> V_74 = NULL ;
F_57 ( & V_19 -> V_94 ) ;
}
return V_19 ;
}
void F_58 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_118 ( V_19 ) ;
F_59 ( V_19 -> V_95 . V_96 != V_97 ) ;
F_15 ( & V_79 ) ;
F_9 ( & V_19 -> V_132 , & V_1 -> V_6 . V_80 ) ;
F_16 ( & V_79 ) ;
F_60 ( & V_1 -> V_6 . V_77 ) ;
}
int F_46 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_118 ( V_19 ) ;
int V_47 = - V_133 ;
if ( V_19 -> V_95 . V_96 != V_97 ) {
V_19 -> V_95 . V_96 = V_97 ;
F_42 ( & V_1 -> V_6 . V_39 ) ;
F_61 ( & V_19 -> V_95 . V_121 ) ;
F_62 ( & V_19 -> V_23 ) ;
F_62 ( & V_19 -> V_24 ) ;
if ( V_19 -> V_21 . V_8 )
F_62 ( & V_19 -> V_25 ) ;
V_1 -> V_6 . V_134 -- ;
F_48 ( & V_1 -> V_6 . V_39 ) ;
F_63 ( V_19 ) ;
V_47 = 0 ;
}
return V_47 ;
}
int F_64 ( struct V_18 * V_19 )
{
int V_47 ;
F_15 ( & V_19 -> V_94 ) ;
V_47 = F_46 ( V_19 ) ;
F_16 ( & V_19 -> V_94 ) ;
return V_47 ;
}
static inline int
F_65 ( struct V_1 * V_1 , T_4 V_9 , bool V_135 )
{
int V_38 , V_47 = 0 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
F_66 (x, net->xfrm.state_bydst+i, bydst) {
if ( F_67 ( V_19 -> V_21 . V_9 , V_9 ) &&
( V_47 = F_68 ( V_19 ) ) != 0 ) {
F_47 ( V_19 , 0 , V_135 ) ;
return V_47 ;
}
}
}
return V_47 ;
}
static inline int
F_65 ( struct V_1 * V_1 , T_4 V_9 , bool V_135 )
{
return 0 ;
}
int F_69 ( struct V_1 * V_1 , T_4 V_9 , bool V_135 )
{
int V_38 , V_47 = 0 , V_136 = 0 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_47 = F_65 ( V_1 , V_9 , V_135 ) ;
if ( V_47 )
goto V_64;
V_47 = - V_133 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
V_137:
F_66 (x, net->xfrm.state_bydst+i, bydst) {
if ( ! F_70 ( V_19 ) &&
F_67 ( V_19 -> V_21 . V_9 , V_9 ) ) {
F_71 ( V_19 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
V_47 = F_64 ( V_19 ) ;
F_47 ( V_19 , V_47 ? 0 : 1 ,
V_135 ) ;
F_63 ( V_19 ) ;
if ( ! V_47 )
V_136 ++ ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
goto V_137;
}
}
}
if ( V_136 )
V_47 = 0 ;
V_64:
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_47 ;
}
void F_72 ( struct V_1 * V_1 , struct V_138 * V_139 )
{
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_139 -> V_140 = V_1 -> V_6 . V_134 ;
V_139 -> V_141 = V_1 -> V_6 . V_7 ;
V_139 -> V_142 = V_143 ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
}
static int
F_73 ( struct V_18 * V_19 , const struct V_144 * V_145 ,
const struct V_146 * V_147 ,
const T_1 * V_2 , const T_1 * V_3 ,
unsigned short V_5 )
{
struct V_44 * V_45 = F_18 ( V_5 ) ;
if ( ! V_45 )
return - 1 ;
V_45 -> V_148 ( & V_19 -> V_149 , V_145 ) ;
if ( V_5 != V_147 -> V_150 ) {
F_21 ( V_45 ) ;
V_45 = F_18 ( V_147 -> V_150 ) ;
if ( ! V_45 )
return - 1 ;
}
V_45 -> V_151 ( V_19 , V_147 , V_2 , V_3 ) ;
F_21 ( V_45 ) ;
return 0 ;
}
static struct V_18 * F_74 ( struct V_1 * V_1 , T_2 V_152 ,
const T_1 * V_2 ,
T_3 V_8 , T_4 V_9 ,
unsigned short V_5 )
{
unsigned int V_20 = F_5 ( V_1 , V_2 , V_8 , V_9 , V_5 ) ;
struct V_18 * V_19 ;
F_66 (x, net->xfrm.state_byspi+h, byspi) {
if ( V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_21 . V_8 != V_8 ||
V_19 -> V_21 . V_9 != V_9 ||
! F_75 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) )
continue;
if ( ( V_152 & V_19 -> V_152 . V_153 ) != V_19 -> V_152 . V_154 )
continue;
F_71 ( V_19 ) ;
return V_19 ;
}
return NULL ;
}
static struct V_18 * F_76 ( struct V_1 * V_1 , T_2 V_152 ,
const T_1 * V_2 ,
const T_1 * V_3 ,
T_4 V_9 , unsigned short V_5 )
{
unsigned int V_20 = F_3 ( V_1 , V_2 , V_3 , V_5 ) ;
struct V_18 * V_19 ;
F_66 (x, net->xfrm.state_bysrc+h, bysrc) {
if ( V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_21 . V_9 != V_9 ||
! F_75 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) ||
! F_75 ( & V_19 -> V_22 . V_3 , V_3 , V_5 ) )
continue;
if ( ( V_152 & V_19 -> V_152 . V_153 ) != V_19 -> V_152 . V_154 )
continue;
F_71 ( V_19 ) ;
return V_19 ;
}
return NULL ;
}
static inline struct V_18 *
F_77 ( struct V_18 * V_19 , int V_155 , int V_5 )
{
struct V_1 * V_1 = V_118 ( V_19 ) ;
T_2 V_152 = V_19 -> V_152 . V_154 & V_19 -> V_152 . V_153 ;
if ( V_155 )
return F_74 ( V_1 , V_152 , & V_19 -> V_21 . V_2 ,
V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_5 ) ;
else
return F_76 ( V_1 , V_152 ,
& V_19 -> V_21 . V_2 ,
& V_19 -> V_22 . V_3 ,
V_19 -> V_21 . V_9 , V_5 ) ;
}
static void F_78 ( struct V_1 * V_1 , int V_156 )
{
if ( V_156 &&
( V_1 -> V_6 . V_7 + 1 ) < V_143 &&
V_1 -> V_6 . V_134 > V_1 -> V_6 . V_7 )
F_60 ( & V_1 -> V_6 . V_28 ) ;
}
static void F_79 ( struct V_157 * V_158 , struct V_18 * V_19 ,
const struct V_144 * V_145 , unsigned short V_5 ,
struct V_18 * * V_159 , int * V_160 ,
int * error )
{
if ( V_19 -> V_95 . V_96 == V_161 ) {
if ( ( V_19 -> V_149 . V_5 &&
! F_80 ( & V_19 -> V_149 , V_145 , V_19 -> V_149 . V_5 ) ) ||
! F_81 ( V_19 , V_158 , V_145 ) )
return;
if ( ! * V_159 ||
( * V_159 ) -> V_95 . V_110 > V_19 -> V_95 . V_110 ||
( ( * V_159 ) -> V_95 . V_110 == V_19 -> V_95 . V_110 &&
( * V_159 ) -> V_103 . V_104 < V_19 -> V_103 . V_104 ) )
* V_159 = V_19 ;
} else if ( V_19 -> V_95 . V_96 == V_115 ) {
* V_160 = 1 ;
} else if ( V_19 -> V_95 . V_96 == V_162 ||
V_19 -> V_95 . V_96 == V_98 ) {
if ( F_80 ( & V_19 -> V_149 , V_145 , V_19 -> V_149 . V_5 ) &&
F_81 ( V_19 , V_158 , V_145 ) )
* error = - V_133 ;
}
}
struct V_18 *
F_82 ( const T_1 * V_2 , const T_1 * V_3 ,
const struct V_144 * V_145 , struct V_146 * V_147 ,
struct V_157 * V_158 , int * V_47 ,
unsigned short V_5 )
{
static T_1 V_163 = { } ;
struct V_1 * V_1 = F_83 ( V_158 ) ;
unsigned int V_20 , V_164 ;
struct V_18 * V_19 , * V_165 , * V_166 ;
int V_167 = 0 ;
int error = 0 ;
struct V_18 * V_159 = NULL ;
T_2 V_152 = V_158 -> V_152 . V_154 & V_158 -> V_152 . V_153 ;
unsigned short V_150 = V_147 -> V_150 ;
struct V_168 V_169 ;
V_166 = NULL ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_20 = F_1 ( V_1 , V_2 , V_3 , V_147 -> V_4 , V_150 ) ;
F_66 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_150 &&
V_19 -> V_22 . V_4 == V_147 -> V_4 &&
( V_152 & V_19 -> V_152 . V_153 ) == V_19 -> V_152 . V_154 &&
! ( V_19 -> V_22 . V_170 & V_171 ) &&
F_84 ( V_19 , V_2 , V_3 , V_150 ) &&
V_147 -> V_57 == V_19 -> V_22 . V_57 &&
V_147 -> V_21 . V_9 == V_19 -> V_21 . V_9 &&
( V_147 -> V_21 . V_8 == V_19 -> V_21 . V_8 || ! V_147 -> V_21 . V_8 ) )
F_79 ( V_158 , V_19 , V_145 , V_150 ,
& V_159 , & V_167 , & error ) ;
}
if ( V_159 || V_167 )
goto V_172;
V_164 = F_1 ( V_1 , V_2 , & V_163 , V_147 -> V_4 , V_150 ) ;
F_66 (x, net->xfrm.state_bydst+h_wildcard, bydst) {
if ( V_19 -> V_22 . V_5 == V_150 &&
V_19 -> V_22 . V_4 == V_147 -> V_4 &&
( V_152 & V_19 -> V_152 . V_153 ) == V_19 -> V_152 . V_154 &&
! ( V_19 -> V_22 . V_170 & V_171 ) &&
F_75 ( & V_19 -> V_21 . V_2 , V_2 , V_150 ) &&
V_147 -> V_57 == V_19 -> V_22 . V_57 &&
V_147 -> V_21 . V_9 == V_19 -> V_21 . V_9 &&
( V_147 -> V_21 . V_8 == V_19 -> V_21 . V_8 || ! V_147 -> V_21 . V_8 ) )
F_79 ( V_158 , V_19 , V_145 , V_150 ,
& V_159 , & V_167 , & error ) ;
}
V_172:
V_19 = V_159 ;
if ( ! V_19 && ! error && ! V_167 ) {
if ( V_147 -> V_21 . V_8 &&
( V_165 = F_74 ( V_1 , V_152 , V_2 , V_147 -> V_21 . V_8 ,
V_147 -> V_21 . V_9 , V_150 ) ) != NULL ) {
V_166 = V_165 ;
error = - V_51 ;
goto V_64;
}
V_169 . V_1 = V_1 ;
if ( ! F_85 ( & V_169 ) ) {
error = - V_133 ;
goto V_64;
}
V_19 = F_49 ( V_1 ) ;
if ( V_19 == NULL ) {
error = - V_173 ;
goto V_64;
}
F_73 ( V_19 , V_145 , V_147 , V_2 , V_3 , V_5 ) ;
memcpy ( & V_19 -> V_152 , & V_158 -> V_152 , sizeof( V_19 -> V_152 ) ) ;
error = F_86 ( V_19 , V_158 -> V_174 , V_145 -> V_175 ) ;
if ( error ) {
V_19 -> V_95 . V_96 = V_97 ;
V_166 = V_19 ;
V_19 = NULL ;
goto V_64;
}
if ( F_87 ( V_19 , V_147 , V_158 ) == 0 ) {
V_19 -> V_95 . V_96 = V_115 ;
F_88 ( & V_19 -> V_95 . V_121 , & V_1 -> V_6 . V_176 ) ;
F_9 ( & V_19 -> V_23 , V_1 -> V_6 . V_40 + V_20 ) ;
V_20 = F_3 ( V_1 , V_2 , V_3 , V_150 ) ;
F_9 ( & V_19 -> V_24 , V_1 -> V_6 . V_41 + V_20 ) ;
if ( V_19 -> V_21 . V_8 ) {
V_20 = F_5 ( V_1 , & V_19 -> V_21 . V_2 , V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_150 ) ;
F_9 ( & V_19 -> V_25 , V_1 -> V_6 . V_42 + V_20 ) ;
}
V_19 -> V_100 . V_101 = V_1 -> V_6 . V_177 ;
F_44 ( & V_19 -> V_65 , F_45 ( V_1 -> V_6 . V_177 , 0 ) , V_114 ) ;
V_1 -> V_6 . V_134 ++ ;
F_78 ( V_1 , V_19 -> V_23 . V_91 != NULL ) ;
} else {
V_19 -> V_95 . V_96 = V_97 ;
V_166 = V_19 ;
V_19 = NULL ;
error = - V_133 ;
}
}
V_64:
if ( V_19 )
F_71 ( V_19 ) ;
else
* V_47 = V_167 ? - V_178 : error ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
if ( V_166 )
F_63 ( V_166 ) ;
return V_19 ;
}
struct V_18 *
F_89 ( struct V_1 * V_1 , T_2 V_152 ,
T_1 * V_2 , T_1 * V_3 ,
unsigned short V_5 , T_4 V_57 , T_4 V_9 , T_2 V_4 )
{
unsigned int V_20 ;
struct V_18 * V_179 = NULL , * V_19 = NULL ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_20 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_66 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_5 &&
V_19 -> V_22 . V_4 == V_4 &&
( V_152 & V_19 -> V_152 . V_153 ) == V_19 -> V_152 . V_154 &&
! ( V_19 -> V_22 . V_170 & V_171 ) &&
F_84 ( V_19 , V_2 , V_3 , V_5 ) &&
V_57 == V_19 -> V_22 . V_57 &&
V_9 == V_19 -> V_21 . V_9 &&
V_19 -> V_95 . V_96 == V_161 ) {
V_179 = V_19 ;
break;
}
}
if ( V_179 )
F_71 ( V_179 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_179 ;
}
struct V_18 * F_90 ( struct V_1 * V_1 , T_3 V_8 ,
unsigned short V_5 )
{
struct V_18 * V_19 ;
struct V_180 * V_181 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
F_91 (w, &net->xfrm.state_all, all) {
V_19 = F_12 ( V_181 , struct V_18 , V_95 ) ;
if ( V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_21 . V_8 != V_8 )
continue;
F_71 ( V_19 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_19 ;
}
F_16 ( & V_1 -> V_6 . V_39 ) ;
return NULL ;
}
static void F_92 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_118 ( V_19 ) ;
unsigned int V_20 ;
F_88 ( & V_19 -> V_95 . V_121 , & V_1 -> V_6 . V_176 ) ;
V_20 = F_1 ( V_1 , & V_19 -> V_21 . V_2 , & V_19 -> V_22 . V_3 ,
V_19 -> V_22 . V_4 , V_19 -> V_22 . V_5 ) ;
F_9 ( & V_19 -> V_23 , V_1 -> V_6 . V_40 + V_20 ) ;
V_20 = F_3 ( V_1 , & V_19 -> V_21 . V_2 , & V_19 -> V_22 . V_3 , V_19 -> V_22 . V_5 ) ;
F_9 ( & V_19 -> V_24 , V_1 -> V_6 . V_41 + V_20 ) ;
if ( V_19 -> V_21 . V_8 ) {
V_20 = F_5 ( V_1 , & V_19 -> V_21 . V_2 , V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 ,
V_19 -> V_22 . V_5 ) ;
F_9 ( & V_19 -> V_25 , V_1 -> V_6 . V_42 + V_20 ) ;
}
F_44 ( & V_19 -> V_65 , F_45 ( 1 , 0 ) , V_114 ) ;
if ( V_19 -> V_130 )
F_93 ( & V_19 -> V_66 , V_182 + V_19 -> V_130 ) ;
V_1 -> V_6 . V_134 ++ ;
F_78 ( V_1 , V_19 -> V_23 . V_91 != NULL ) ;
}
static void F_94 ( struct V_18 * V_183 )
{
struct V_1 * V_1 = V_118 ( V_183 ) ;
unsigned short V_5 = V_183 -> V_22 . V_5 ;
T_2 V_4 = V_183 -> V_22 . V_4 ;
struct V_18 * V_19 ;
unsigned int V_20 ;
T_2 V_152 = V_183 -> V_152 . V_154 & V_183 -> V_152 . V_153 ;
V_20 = F_1 ( V_1 , & V_183 -> V_21 . V_2 , & V_183 -> V_22 . V_3 , V_4 , V_5 ) ;
F_66 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_5 &&
V_19 -> V_22 . V_4 == V_4 &&
( V_152 & V_19 -> V_152 . V_153 ) == V_19 -> V_152 . V_154 &&
F_75 ( & V_19 -> V_21 . V_2 , & V_183 -> V_21 . V_2 , V_5 ) &&
F_75 ( & V_19 -> V_22 . V_3 , & V_183 -> V_22 . V_3 , V_5 ) )
V_19 -> V_184 ++ ;
}
}
void F_95 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_118 ( V_19 ) ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
F_94 ( V_19 ) ;
F_92 ( V_19 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
}
static struct V_18 * F_96 ( struct V_1 * V_1 ,
const struct V_185 * V_153 ,
unsigned short V_5 , T_4 V_57 ,
T_2 V_4 , T_4 V_9 ,
const T_1 * V_2 ,
const T_1 * V_3 ,
int V_186 )
{
unsigned int V_20 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
struct V_18 * V_19 ;
T_2 V_152 = V_153 -> V_154 & V_153 -> V_153 ;
F_66 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_4 != V_4 ||
V_19 -> V_22 . V_57 != V_57 ||
V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_95 . V_96 != V_115 ||
V_19 -> V_21 . V_8 != 0 ||
V_19 -> V_21 . V_9 != V_9 ||
( V_152 & V_19 -> V_152 . V_153 ) != V_19 -> V_152 . V_154 ||
! F_75 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) ||
! F_75 ( & V_19 -> V_22 . V_3 , V_3 , V_5 ) )
continue;
F_71 ( V_19 ) ;
return V_19 ;
}
if ( ! V_186 )
return NULL ;
V_19 = F_49 ( V_1 ) ;
if ( F_20 ( V_19 ) ) {
switch ( V_5 ) {
case V_187 :
V_19 -> V_149 . V_2 . V_188 = V_2 -> V_188 ;
V_19 -> V_149 . V_3 . V_188 = V_3 -> V_188 ;
V_19 -> V_149 . V_189 = 32 ;
V_19 -> V_149 . V_190 = 32 ;
V_19 -> V_22 . V_3 . V_188 = V_3 -> V_188 ;
V_19 -> V_21 . V_2 . V_188 = V_2 -> V_188 ;
break;
case V_191 :
V_19 -> V_149 . V_2 . V_192 = V_2 -> V_192 ;
V_19 -> V_149 . V_3 . V_192 = V_3 -> V_192 ;
V_19 -> V_149 . V_189 = 128 ;
V_19 -> V_149 . V_190 = 128 ;
V_19 -> V_22 . V_3 . V_192 = V_3 -> V_192 ;
V_19 -> V_21 . V_2 . V_192 = V_2 -> V_192 ;
break;
}
V_19 -> V_95 . V_96 = V_115 ;
V_19 -> V_21 . V_9 = V_9 ;
V_19 -> V_22 . V_5 = V_5 ;
V_19 -> V_22 . V_57 = V_57 ;
V_19 -> V_22 . V_4 = V_4 ;
V_19 -> V_152 . V_154 = V_153 -> V_154 ;
V_19 -> V_152 . V_153 = V_153 -> V_153 ;
V_19 -> V_100 . V_101 = V_1 -> V_6 . V_177 ;
F_71 ( V_19 ) ;
F_44 ( & V_19 -> V_65 , F_45 ( V_1 -> V_6 . V_177 , 0 ) , V_114 ) ;
F_88 ( & V_19 -> V_95 . V_121 , & V_1 -> V_6 . V_176 ) ;
F_9 ( & V_19 -> V_23 , V_1 -> V_6 . V_40 + V_20 ) ;
V_20 = F_3 ( V_1 , V_2 , V_3 , V_5 ) ;
F_9 ( & V_19 -> V_24 , V_1 -> V_6 . V_41 + V_20 ) ;
V_1 -> V_6 . V_134 ++ ;
F_78 ( V_1 , V_19 -> V_23 . V_91 != NULL ) ;
}
return V_19 ;
}
int F_97 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_118 ( V_19 ) ;
struct V_18 * V_193 , * V_166 ;
int V_5 ;
int V_47 ;
T_2 V_152 = V_19 -> V_152 . V_154 & V_19 -> V_152 . V_153 ;
int V_155 = F_67 ( V_19 -> V_21 . V_9 , V_194 ) ;
V_5 = V_19 -> V_22 . V_5 ;
V_166 = NULL ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_193 = F_77 ( V_19 , V_155 , V_5 ) ;
if ( V_193 ) {
V_166 = V_193 ;
V_193 = NULL ;
V_47 = - V_51 ;
goto V_64;
}
if ( V_155 && V_19 -> V_95 . V_195 ) {
V_193 = F_98 ( V_1 , V_152 , V_19 -> V_95 . V_195 ) ;
if ( V_193 && ( ( V_193 -> V_21 . V_9 != V_19 -> V_21 . V_9 ) ||
! F_75 ( & V_193 -> V_21 . V_2 , & V_19 -> V_21 . V_2 , V_5 ) ) ) {
V_166 = V_193 ;
V_193 = NULL ;
}
}
if ( V_155 && ! V_193 )
V_193 = F_96 ( V_1 , & V_19 -> V_152 , V_5 , V_19 -> V_22 . V_57 ,
V_19 -> V_22 . V_4 , V_19 -> V_21 . V_9 ,
& V_19 -> V_21 . V_2 , & V_19 -> V_22 . V_3 , 0 ) ;
F_94 ( V_19 ) ;
F_92 ( V_19 ) ;
V_47 = 0 ;
V_64:
F_16 ( & V_1 -> V_6 . V_39 ) ;
if ( V_193 ) {
F_64 ( V_193 ) ;
F_63 ( V_193 ) ;
}
if ( V_166 )
F_63 ( V_166 ) ;
return V_47 ;
}
static struct V_18 * F_99 ( struct V_18 * V_196 )
{
struct V_1 * V_1 = V_118 ( V_196 ) ;
struct V_18 * V_19 = F_49 ( V_1 ) ;
if ( ! V_19 )
goto V_64;
memcpy ( & V_19 -> V_21 , & V_196 -> V_21 , sizeof( V_19 -> V_21 ) ) ;
memcpy ( & V_19 -> V_149 , & V_196 -> V_149 , sizeof( V_19 -> V_149 ) ) ;
memcpy ( & V_19 -> V_100 , & V_196 -> V_100 , sizeof( V_19 -> V_100 ) ) ;
V_19 -> V_22 . V_57 = V_196 -> V_22 . V_57 ;
V_19 -> V_22 . V_197 = V_196 -> V_22 . V_197 ;
V_19 -> V_22 . V_4 = V_196 -> V_22 . V_4 ;
V_19 -> V_22 . V_5 = V_196 -> V_22 . V_5 ;
V_19 -> V_22 . V_3 = V_196 -> V_22 . V_3 ;
if ( V_196 -> V_67 ) {
V_19 -> V_67 = F_100 ( V_196 -> V_67 ) ;
if ( ! V_19 -> V_67 )
goto error;
}
V_19 -> V_22 . V_198 = V_196 -> V_22 . V_198 ;
if ( V_196 -> V_199 ) {
V_19 -> V_199 = F_101 ( V_196 -> V_199 ) ;
if ( ! V_19 -> V_199 )
goto error;
}
if ( V_196 -> V_68 ) {
V_19 -> V_68 = F_102 ( V_196 -> V_68 ) ;
if ( ! V_19 -> V_68 )
goto error;
}
V_19 -> V_22 . V_200 = V_196 -> V_22 . V_200 ;
if ( V_196 -> V_69 ) {
V_19 -> V_69 = F_102 ( V_196 -> V_69 ) ;
if ( ! V_19 -> V_69 )
goto error;
}
V_19 -> V_22 . V_201 = V_196 -> V_22 . V_201 ;
if ( V_196 -> V_59 ) {
V_19 -> V_59 = F_103 ( V_196 -> V_59 , sizeof( * V_19 -> V_59 ) , V_202 ) ;
if ( ! V_19 -> V_59 )
goto error;
}
if ( V_196 -> V_70 ) {
V_19 -> V_70 = F_103 ( V_196 -> V_70 , sizeof( * V_19 -> V_70 ) ,
V_202 ) ;
if ( ! V_19 -> V_70 )
goto error;
}
if ( V_196 -> V_71 ) {
if ( F_104 ( V_19 , V_196 ) )
goto error;
}
memcpy ( & V_19 -> V_152 , & V_196 -> V_152 , sizeof( V_19 -> V_152 ) ) ;
if ( F_105 ( V_19 ) < 0 )
goto error;
V_19 -> V_22 . V_170 = V_196 -> V_22 . V_170 ;
V_19 -> V_22 . V_203 = V_196 -> V_22 . V_203 ;
V_19 -> V_204 = V_196 -> V_204 ;
V_19 -> V_131 = V_196 -> V_131 ;
V_19 -> V_130 = V_196 -> V_130 ;
V_19 -> V_103 . V_104 = V_196 -> V_103 . V_104 ;
V_19 -> V_95 . V_96 = V_196 -> V_95 . V_96 ;
V_19 -> V_95 . V_195 = V_196 -> V_95 . V_195 ;
return V_19 ;
error:
F_63 ( V_19 ) ;
V_64:
return NULL ;
}
struct V_18 * F_106 ( struct V_205 * V_153 , struct V_1 * V_1 )
{
unsigned int V_20 ;
struct V_18 * V_19 = NULL ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
if ( V_153 -> V_4 ) {
V_20 = F_1 ( V_1 , & V_153 -> V_206 , & V_153 -> V_207 ,
V_153 -> V_4 , V_153 -> V_208 ) ;
F_66 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_57 != V_153 -> V_57 ||
V_19 -> V_21 . V_9 != V_153 -> V_9 )
continue;
if ( V_153 -> V_4 && V_19 -> V_22 . V_4 != V_153 -> V_4 )
continue;
if ( ! F_75 ( & V_19 -> V_21 . V_2 , & V_153 -> V_206 ,
V_153 -> V_208 ) ||
! F_75 ( & V_19 -> V_22 . V_3 , & V_153 -> V_207 ,
V_153 -> V_208 ) )
continue;
F_71 ( V_19 ) ;
break;
}
} else {
V_20 = F_3 ( V_1 , & V_153 -> V_206 , & V_153 -> V_207 ,
V_153 -> V_208 ) ;
F_66 (x, net->xfrm.state_bysrc+h, bysrc) {
if ( V_19 -> V_22 . V_57 != V_153 -> V_57 ||
V_19 -> V_21 . V_9 != V_153 -> V_9 )
continue;
if ( ! F_75 ( & V_19 -> V_21 . V_2 , & V_153 -> V_206 ,
V_153 -> V_208 ) ||
! F_75 ( & V_19 -> V_22 . V_3 , & V_153 -> V_207 ,
V_153 -> V_208 ) )
continue;
F_71 ( V_19 ) ;
break;
}
}
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_19 ;
}
struct V_18 * F_107 ( struct V_18 * V_19 ,
struct V_205 * V_153 )
{
struct V_18 * V_209 ;
V_209 = F_99 ( V_19 ) ;
if ( ! V_209 )
return NULL ;
memcpy ( & V_209 -> V_21 . V_2 , & V_153 -> V_210 , sizeof( V_209 -> V_21 . V_2 ) ) ;
memcpy ( & V_209 -> V_22 . V_3 , & V_153 -> V_211 , sizeof( V_209 -> V_22 . V_3 ) ) ;
if ( F_75 ( & V_19 -> V_21 . V_2 , & V_153 -> V_210 , V_153 -> V_212 ) ) {
F_95 ( V_209 ) ;
} else {
if ( F_97 ( V_209 ) < 0 )
goto error;
}
return V_209 ;
error:
F_63 ( V_209 ) ;
return NULL ;
}
int F_108 ( struct V_18 * V_19 )
{
struct V_18 * V_193 , * V_166 ;
int V_47 ;
int V_155 = F_67 ( V_19 -> V_21 . V_9 , V_194 ) ;
struct V_1 * V_1 = V_118 ( V_19 ) ;
V_166 = NULL ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_193 = F_77 ( V_19 , V_155 , V_19 -> V_22 . V_5 ) ;
V_47 = - V_133 ;
if ( ! V_193 )
goto V_64;
if ( F_70 ( V_193 ) ) {
V_166 = V_193 ;
V_47 = - V_51 ;
goto V_64;
}
if ( V_193 -> V_95 . V_96 == V_115 ) {
F_92 ( V_19 ) ;
V_19 = NULL ;
}
V_47 = 0 ;
V_64:
F_16 ( & V_1 -> V_6 . V_39 ) ;
if ( V_166 )
F_63 ( V_166 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_19 ) {
F_64 ( V_193 ) ;
F_63 ( V_193 ) ;
return 0 ;
}
V_47 = - V_61 ;
F_15 ( & V_193 -> V_94 ) ;
if ( F_20 ( V_193 -> V_95 . V_96 == V_161 ) ) {
if ( V_19 -> V_59 && V_193 -> V_59 )
memcpy ( V_193 -> V_59 , V_19 -> V_59 , sizeof( * V_193 -> V_59 ) ) ;
if ( V_19 -> V_70 && V_193 -> V_70 ) {
memcpy ( V_193 -> V_70 , V_19 -> V_70 , sizeof( * V_193 -> V_70 ) ) ;
}
if ( ! V_155 && memcmp ( & V_193 -> V_149 , & V_19 -> V_149 , sizeof( V_193 -> V_149 ) ) )
memcpy ( & V_193 -> V_149 , & V_19 -> V_149 , sizeof( V_193 -> V_149 ) ) ;
memcpy ( & V_193 -> V_100 , & V_19 -> V_100 , sizeof( V_193 -> V_100 ) ) ;
V_193 -> V_95 . V_110 = 0 ;
F_44 ( & V_193 -> V_65 , F_45 ( 1 , 0 ) , V_114 ) ;
if ( V_193 -> V_103 . V_109 )
F_109 ( V_193 ) ;
V_47 = 0 ;
V_19 -> V_95 . V_96 = V_97 ;
F_110 ( V_19 ) ;
}
F_16 ( & V_193 -> V_94 ) ;
F_63 ( V_193 ) ;
return V_47 ;
}
int F_109 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_103 . V_109 )
V_19 -> V_103 . V_109 = F_41 () ;
if ( V_19 -> V_103 . V_213 >= V_19 -> V_100 . V_128 ||
V_19 -> V_103 . V_214 >= V_19 -> V_100 . V_129 ) {
V_19 -> V_95 . V_96 = V_98 ;
F_44 ( & V_19 -> V_65 , F_45 ( 0 , 0 ) , V_114 ) ;
return - V_61 ;
}
if ( ! V_19 -> V_95 . V_110 &&
( V_19 -> V_103 . V_213 >= V_19 -> V_100 . V_125 ||
V_19 -> V_103 . V_214 >= V_19 -> V_100 . V_127 ) ) {
V_19 -> V_95 . V_110 = 1 ;
F_43 ( V_19 , 0 , 0 ) ;
}
return 0 ;
}
struct V_18 *
F_111 ( struct V_1 * V_1 , T_2 V_152 , const T_1 * V_2 , T_3 V_8 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_19 = F_74 ( V_1 , V_152 , V_2 , V_8 , V_9 , V_5 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_19 ;
}
struct V_18 *
F_112 ( struct V_1 * V_1 , T_2 V_152 ,
const T_1 * V_2 , const T_1 * V_3 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_19 = F_76 ( V_1 , V_152 , V_2 , V_3 , V_9 , V_5 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_19 ;
}
struct V_18 *
F_113 ( struct V_1 * V_1 , const struct V_185 * V_152 , T_4 V_57 , T_2 V_4 ,
T_4 V_9 , const T_1 * V_2 ,
const T_1 * V_3 , int V_186 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_19 = F_96 ( V_1 , V_152 , V_5 , V_57 , V_4 , V_9 , V_2 , V_3 , V_186 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_19 ;
}
int
F_114 ( struct V_146 * * V_215 , struct V_146 * * V_216 , int V_217 ,
unsigned short V_5 , struct V_1 * V_1 )
{
int V_47 = 0 ;
struct V_44 * V_45 = F_18 ( V_5 ) ;
if ( ! V_45 )
return - V_48 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
if ( V_45 -> V_218 )
V_47 = V_45 -> V_218 ( V_215 , V_216 , V_217 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
F_21 ( V_45 ) ;
return V_47 ;
}
int
F_115 ( struct V_18 * * V_215 , struct V_18 * * V_216 , int V_217 ,
unsigned short V_5 )
{
int V_47 = 0 ;
struct V_44 * V_45 = F_18 ( V_5 ) ;
struct V_1 * V_1 = V_118 ( * V_216 ) ;
if ( ! V_45 )
return - V_48 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
if ( V_45 -> V_219 )
V_47 = V_45 -> V_219 ( V_215 , V_216 , V_217 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
F_21 ( V_45 ) ;
return V_47 ;
}
static struct V_18 * F_98 ( struct V_1 * V_1 , T_2 V_152 , T_2 V_195 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
F_66 (x, net->xfrm.state_bydst+i, bydst) {
if ( V_19 -> V_95 . V_195 == V_195 &&
( V_152 & V_19 -> V_152 . V_153 ) == V_19 -> V_152 . V_154 &&
V_19 -> V_95 . V_96 == V_115 ) {
F_71 ( V_19 ) ;
return V_19 ;
}
}
}
return NULL ;
}
struct V_18 * F_116 ( struct V_1 * V_1 , T_2 V_152 , T_2 V_195 )
{
struct V_18 * V_19 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_19 = F_98 ( V_1 , V_152 , V_195 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_19 ;
}
T_2 F_117 ( void )
{
T_2 V_220 ;
static T_5 V_221 ;
do {
V_220 = F_118 ( & V_221 ) ;
} while ( ! V_220 );
return V_220 ;
}
int F_119 ( T_4 V_9 , T_2 V_222 , T_2 V_223 )
{
switch ( V_9 ) {
case V_224 :
case V_225 :
break;
case V_226 :
if ( V_223 >= 0x10000 )
return - V_61 ;
break;
default:
return - V_61 ;
}
if ( V_222 > V_223 )
return - V_61 ;
return 0 ;
}
int F_120 ( struct V_18 * V_19 , T_2 V_227 , T_2 V_228 )
{
struct V_1 * V_1 = V_118 ( V_19 ) ;
unsigned int V_20 ;
struct V_18 * V_165 ;
int V_47 = - V_52 ;
T_3 V_229 = F_121 ( V_227 ) ;
T_3 V_230 = F_121 ( V_228 ) ;
T_2 V_152 = V_19 -> V_152 . V_154 & V_19 -> V_152 . V_153 ;
F_15 ( & V_19 -> V_94 ) ;
if ( V_19 -> V_95 . V_96 == V_97 )
goto V_231;
V_47 = 0 ;
if ( V_19 -> V_21 . V_8 )
goto V_231;
V_47 = - V_52 ;
if ( V_229 == V_230 ) {
V_165 = F_111 ( V_1 , V_152 , & V_19 -> V_21 . V_2 , V_229 , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
if ( V_165 ) {
F_63 ( V_165 ) ;
goto V_231;
}
V_19 -> V_21 . V_8 = V_229 ;
} else {
T_2 V_8 = 0 ;
for ( V_20 = 0 ; V_20 < V_228 - V_227 + 1 ; V_20 ++ ) {
V_8 = V_227 + F_122 () % ( V_228 - V_227 + 1 ) ;
V_165 = F_111 ( V_1 , V_152 , & V_19 -> V_21 . V_2 , F_121 ( V_8 ) , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
if ( V_165 == NULL ) {
V_19 -> V_21 . V_8 = F_121 ( V_8 ) ;
break;
}
F_63 ( V_165 ) ;
}
}
if ( V_19 -> V_21 . V_8 ) {
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_20 = F_5 ( V_1 , & V_19 -> V_21 . V_2 , V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
F_9 ( & V_19 -> V_25 , V_1 -> V_6 . V_42 + V_20 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
V_47 = 0 ;
}
V_231:
F_16 ( & V_19 -> V_94 ) ;
return V_47 ;
}
static bool F_123 ( struct V_18 * V_19 ,
struct V_232 * V_233 )
{
if ( V_233 ) {
if ( ( V_233 -> V_5 == V_187 ||
V_233 -> V_5 == V_191 ) &&
V_19 -> V_22 . V_5 != V_233 -> V_5 )
return false ;
return F_124 ( & V_19 -> V_22 . V_3 , & V_233 -> V_3 ,
V_233 -> V_234 ) &&
F_124 ( & V_19 -> V_21 . V_2 , & V_233 -> V_2 ,
V_233 -> V_235 ) ;
}
return true ;
}
int V_180 ( struct V_1 * V_1 , struct V_180 * V_236 ,
int (* F_125)( struct V_18 * , int , void * ) ,
void * V_237 )
{
struct V_18 * V_96 ;
struct V_180 * V_19 ;
int V_47 = 0 ;
if ( V_236 -> V_195 != 0 && F_126 ( & V_236 -> V_121 ) )
return 0 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
if ( F_126 ( & V_236 -> V_121 ) )
V_19 = F_127 ( & V_1 -> V_6 . V_176 , struct V_180 , V_121 ) ;
else
V_19 = F_128 ( & V_236 -> V_121 , struct V_180 , V_121 ) ;
F_129 (x, &net->xfrm.state_all, all) {
if ( V_19 -> V_96 == V_97 )
continue;
V_96 = F_12 ( V_19 , struct V_18 , V_95 ) ;
if ( ! F_67 ( V_96 -> V_21 . V_9 , V_236 -> V_9 ) )
continue;
if ( ! F_123 ( V_96 , V_236 -> V_233 ) )
continue;
V_47 = F_125 ( V_96 , V_236 -> V_195 , V_237 ) ;
if ( V_47 ) {
F_130 ( & V_236 -> V_121 , & V_19 -> V_121 ) ;
goto V_64;
}
V_236 -> V_195 ++ ;
}
if ( V_236 -> V_195 == 0 ) {
V_47 = - V_52 ;
goto V_64;
}
F_131 ( & V_236 -> V_121 ) ;
V_64:
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_47 ;
}
void F_132 ( struct V_180 * V_236 , T_4 V_9 ,
struct V_232 * V_233 )
{
F_53 ( & V_236 -> V_121 ) ;
V_236 -> V_9 = V_9 ;
V_236 -> V_96 = V_97 ;
V_236 -> V_195 = 0 ;
V_236 -> V_233 = V_233 ;
}
void F_133 ( struct V_180 * V_236 , struct V_1 * V_1 )
{
F_35 ( V_236 -> V_233 ) ;
if ( F_126 ( & V_236 -> V_121 ) )
return;
F_15 ( & V_1 -> V_6 . V_39 ) ;
F_61 ( & V_236 -> V_121 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
}
static void V_124 ( unsigned long V_237 )
{
struct V_18 * V_19 = (struct V_18 * ) V_237 ;
F_42 ( & V_19 -> V_94 ) ;
if ( V_19 -> V_95 . V_96 == V_161 ) {
if ( F_134 ( V_118 ( V_19 ) ) )
V_19 -> V_238 -> V_239 ( V_19 , V_240 ) ;
else
V_19 -> V_105 |= V_241 ;
}
F_48 ( & V_19 -> V_94 ) ;
}
void F_135 ( struct V_157 * V_242 , int V_243 , const struct V_168 * V_169 )
{
struct V_244 * V_95 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list)
if ( V_95 -> V_245 )
V_95 -> V_245 ( V_242 , V_243 , V_169 ) ;
F_138 () ;
}
void F_139 ( struct V_18 * V_19 , const struct V_168 * V_169 )
{
struct V_244 * V_95 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list)
if ( V_95 -> V_239 )
V_95 -> V_239 ( V_19 , V_169 ) ;
F_138 () ;
}
void F_43 ( struct V_18 * V_19 , int V_246 , T_2 V_247 )
{
struct V_168 V_169 ;
V_169 . V_237 . V_246 = V_246 ;
V_169 . V_247 = V_247 ;
V_169 . V_248 = V_249 ;
F_139 ( V_19 , & V_169 ) ;
}
int F_87 ( struct V_18 * V_19 , struct V_146 * V_250 , struct V_157 * V_158 )
{
int V_47 = - V_61 , V_251 ;
struct V_244 * V_95 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list) {
V_251 = V_95 -> V_252 ( V_19 , V_250 , V_158 ) ;
if ( ! V_251 )
V_47 = V_251 ;
}
F_138 () ;
return V_47 ;
}
int F_140 ( struct V_18 * V_19 , T_1 * V_253 , T_6 V_254 )
{
int V_47 = - V_61 ;
struct V_244 * V_95 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list) {
if ( V_95 -> V_255 )
V_47 = V_95 -> V_255 ( V_19 , V_253 , V_254 ) ;
if ( ! V_47 )
break;
}
F_138 () ;
return V_47 ;
}
void F_141 ( struct V_157 * V_158 , int V_243 , int V_246 , T_2 V_247 )
{
struct V_168 V_169 ;
V_169 . V_237 . V_246 = V_246 ;
V_169 . V_247 = V_247 ;
V_169 . V_248 = V_256 ;
F_135 ( V_158 , V_243 , & V_169 ) ;
}
int F_142 ( const struct V_257 * V_149 , T_4 V_243 , T_4 type ,
const struct V_205 * V_153 , int V_258 ,
const struct V_259 * V_260 )
{
int V_47 = - V_61 ;
int V_261 ;
struct V_244 * V_95 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list) {
if ( V_95 -> V_262 ) {
V_261 = V_95 -> V_262 ( V_149 , V_243 , type , V_153 , V_258 , V_260 ) ;
if ( ! V_261 )
V_47 = V_261 ;
}
}
F_138 () ;
return V_47 ;
}
int F_143 ( struct V_1 * V_1 , T_4 V_9 , struct V_257 * V_149 , T_1 * V_263 )
{
int V_47 = - V_61 ;
int V_261 ;
struct V_244 * V_95 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list) {
if ( V_95 -> V_264 ) {
V_261 = V_95 -> V_264 ( V_1 , V_9 , V_149 , V_263 ) ;
if ( ! V_261 )
V_47 = V_261 ;
}
}
F_138 () ;
return V_47 ;
}
bool F_85 ( const struct V_168 * V_169 )
{
struct V_244 * V_95 ;
bool V_265 = false ;
F_136 () ;
F_137 (km, &xfrm_km_list, list) {
if ( V_95 -> V_265 && V_95 -> V_265 ( V_169 ) ) {
V_265 = true ;
break;
}
}
F_138 () ;
return V_265 ;
}
int F_144 ( struct V_266 * V_267 , int V_268 , T_4 T_7 * V_269 , int V_270 )
{
int V_47 ;
T_4 * V_237 ;
struct V_244 * V_95 ;
struct V_157 * V_158 = NULL ;
if ( V_270 <= 0 || V_270 > V_271 )
return - V_272 ;
V_237 = F_145 ( V_270 , V_202 ) ;
if ( ! V_237 )
return - V_173 ;
V_47 = - V_273 ;
if ( F_146 ( V_237 , V_269 , V_270 ) )
goto V_64;
V_47 = - V_61 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list) {
V_158 = V_95 -> V_274 ( V_267 , V_268 , V_237 ,
V_270 , & V_47 ) ;
if ( V_47 >= 0 )
break;
}
F_138 () ;
if ( V_47 >= 0 ) {
F_147 ( V_267 , V_47 , V_158 ) ;
F_148 ( V_158 ) ;
V_47 = 0 ;
}
V_64:
F_35 ( V_237 ) ;
return V_47 ;
}
int F_149 ( struct V_244 * V_95 )
{
F_15 ( & V_275 ) ;
F_150 ( & V_95 -> V_11 , & V_276 ) ;
F_16 ( & V_275 ) ;
return 0 ;
}
int F_151 ( struct V_244 * V_95 )
{
F_15 ( & V_275 ) ;
F_152 ( & V_95 -> V_11 ) ;
F_16 ( & V_275 ) ;
F_153 () ;
return 0 ;
}
int F_154 ( struct V_44 * V_45 )
{
int V_47 = 0 ;
if ( F_19 ( V_45 == NULL ) )
return - V_61 ;
if ( F_19 ( V_45 -> V_5 >= V_277 ) )
return - V_48 ;
F_15 ( & V_278 ) ;
if ( F_19 ( V_44 [ V_45 -> V_5 ] != NULL ) )
V_47 = - V_279 ;
else
F_155 ( V_44 [ V_45 -> V_5 ] , V_45 ) ;
F_16 ( & V_278 ) ;
return V_47 ;
}
int F_156 ( struct V_44 * V_45 )
{
int V_47 = 0 ;
if ( F_19 ( V_45 == NULL ) )
return - V_61 ;
if ( F_19 ( V_45 -> V_5 >= V_277 ) )
return - V_48 ;
F_15 ( & V_278 ) ;
if ( F_20 ( V_44 [ V_45 -> V_5 ] != NULL ) ) {
if ( F_19 ( V_44 [ V_45 -> V_5 ] != V_45 ) )
V_47 = - V_61 ;
else
F_157 ( V_44 [ V_45 -> V_5 ] , NULL ) ;
}
F_16 ( & V_278 ) ;
F_153 () ;
return V_47 ;
}
struct V_44 * F_18 ( unsigned int V_5 )
{
struct V_44 * V_45 ;
if ( F_19 ( V_5 >= V_277 ) )
return NULL ;
F_136 () ;
V_45 = F_158 ( V_44 [ V_5 ] ) ;
if ( F_19 ( ! V_45 ) )
F_138 () ;
return V_45 ;
}
void F_21 ( struct V_44 * V_45 )
{
F_138 () ;
}
void F_159 ( struct V_18 * V_19 )
{
if ( V_19 -> V_280 ) {
struct V_18 * V_250 = V_19 -> V_280 ;
if ( F_160 ( & V_250 -> V_120 ) == 2 )
F_64 ( V_250 ) ;
F_161 ( & V_250 -> V_120 ) ;
F_63 ( V_250 ) ;
V_19 -> V_280 = NULL ;
}
}
int F_162 ( struct V_18 * V_19 , int V_281 )
{
int V_220 ;
F_15 ( & V_19 -> V_94 ) ;
if ( V_19 -> V_95 . V_96 == V_161 &&
V_19 -> type && V_19 -> type -> V_282 )
V_220 = V_19 -> type -> V_282 ( V_19 , V_281 ) ;
else
V_220 = V_281 - V_19 -> V_22 . V_283 ;
F_16 ( & V_19 -> V_94 ) ;
return V_220 ;
}
int F_163 ( struct V_18 * V_19 , bool V_284 )
{
struct V_44 * V_45 ;
struct V_56 * V_73 ;
int V_5 = V_19 -> V_22 . V_5 ;
int V_47 ;
V_47 = - V_48 ;
V_45 = F_18 ( V_5 ) ;
if ( ! V_45 )
goto error;
V_47 = 0 ;
if ( V_45 -> V_285 )
V_47 = V_45 -> V_285 ( V_19 ) ;
F_21 ( V_45 ) ;
if ( V_47 )
goto error;
V_47 = - V_286 ;
if ( V_19 -> V_149 . V_5 != V_287 ) {
V_73 = F_30 ( V_19 -> V_22 . V_57 , V_19 -> V_149 . V_5 ) ;
if ( V_73 == NULL )
goto error;
if ( ! ( V_73 -> V_170 & V_288 ) &&
V_5 != V_19 -> V_149 . V_5 ) {
F_31 ( V_73 ) ;
goto error;
}
V_19 -> V_73 = V_73 ;
} else {
struct V_56 * V_74 ;
int V_289 = V_187 ;
V_73 = F_30 ( V_19 -> V_22 . V_57 , V_19 -> V_22 . V_5 ) ;
if ( V_73 == NULL )
goto error;
if ( ! ( V_73 -> V_170 & V_288 ) ) {
F_31 ( V_73 ) ;
goto error;
}
V_19 -> V_73 = V_73 ;
if ( V_19 -> V_22 . V_5 == V_187 )
V_289 = V_191 ;
V_74 = F_30 ( V_19 -> V_22 . V_57 , V_289 ) ;
if ( V_74 ) {
if ( V_74 -> V_170 & V_288 )
V_19 -> V_74 = V_74 ;
else
F_31 ( V_74 ) ;
}
}
V_19 -> type = F_23 ( V_19 -> V_21 . V_9 , V_5 ) ;
if ( V_19 -> type == NULL )
goto error;
V_47 = V_19 -> type -> V_290 ( V_19 ) ;
if ( V_47 )
goto error;
V_19 -> V_75 = F_30 ( V_19 -> V_22 . V_57 , V_5 ) ;
if ( V_19 -> V_75 == NULL ) {
V_47 = - V_286 ;
goto error;
}
if ( V_284 ) {
V_47 = F_164 ( V_19 ) ;
if ( V_47 )
goto error;
}
V_19 -> V_95 . V_96 = V_161 ;
error:
return V_47 ;
}
int F_105 ( struct V_18 * V_19 )
{
return F_163 ( V_19 , true ) ;
}
int T_8 F_165 ( struct V_1 * V_1 )
{
unsigned int V_291 ;
F_53 ( & V_1 -> V_6 . V_176 ) ;
V_291 = sizeof( struct V_10 ) * 8 ;
V_1 -> V_6 . V_40 = F_13 ( V_291 ) ;
if ( ! V_1 -> V_6 . V_40 )
goto V_292;
V_1 -> V_6 . V_41 = F_13 ( V_291 ) ;
if ( ! V_1 -> V_6 . V_41 )
goto V_293;
V_1 -> V_6 . V_42 = F_13 ( V_291 ) ;
if ( ! V_1 -> V_6 . V_42 )
goto V_294;
V_1 -> V_6 . V_7 = ( ( V_291 / sizeof( struct V_10 ) ) - 1 ) ;
V_1 -> V_6 . V_134 = 0 ;
F_166 ( & V_1 -> V_6 . V_28 , F_11 ) ;
F_167 ( & V_1 -> V_6 . V_80 ) ;
F_166 ( & V_1 -> V_6 . V_77 , F_37 ) ;
F_57 ( & V_1 -> V_6 . V_39 ) ;
return 0 ;
V_294:
F_14 ( V_1 -> V_6 . V_41 , V_291 ) ;
V_293:
F_14 ( V_1 -> V_6 . V_40 , V_291 ) ;
V_292:
return - V_173 ;
}
void F_168 ( struct V_1 * V_1 )
{
unsigned int V_291 ;
F_169 ( & V_1 -> V_6 . V_28 ) ;
F_69 ( V_1 , V_194 , false ) ;
F_169 ( & V_1 -> V_6 . V_77 ) ;
F_59 ( ! F_126 ( & V_1 -> V_6 . V_176 ) ) ;
V_291 = ( V_1 -> V_6 . V_7 + 1 ) * sizeof( struct V_10 ) ;
F_59 ( ! F_170 ( V_1 -> V_6 . V_42 ) ) ;
F_14 ( V_1 -> V_6 . V_42 , V_291 ) ;
F_59 ( ! F_170 ( V_1 -> V_6 . V_41 ) ) ;
F_14 ( V_1 -> V_6 . V_41 , V_291 ) ;
F_59 ( ! F_170 ( V_1 -> V_6 . V_40 ) ) ;
F_14 ( V_1 -> V_6 . V_40 , V_291 ) ;
}
static void F_171 ( struct V_18 * V_19 ,
struct V_295 * V_296 )
{
struct V_297 * V_298 = V_19 -> V_174 ;
T_2 V_8 = F_172 ( V_19 -> V_21 . V_8 ) ;
if ( V_298 )
F_173 ( V_296 , L_3 ,
V_298 -> V_299 , V_298 -> V_300 , V_298 -> V_301 ) ;
switch ( V_19 -> V_22 . V_5 ) {
case V_187 :
F_173 ( V_296 , L_4 ,
& V_19 -> V_22 . V_3 . V_188 , & V_19 -> V_21 . V_2 . V_188 ) ;
break;
case V_191 :
F_173 ( V_296 , L_5 ,
V_19 -> V_22 . V_3 . V_302 , V_19 -> V_21 . V_2 . V_302 ) ;
break;
}
F_173 ( V_296 , L_6 , V_8 , V_8 ) ;
}
static void F_174 ( struct V_303 * V_304 , T_9 V_5 ,
struct V_295 * V_296 )
{
const struct V_305 * V_306 ;
const struct V_307 * V_308 ;
switch ( V_5 ) {
case V_187 :
V_306 = F_175 ( V_304 ) ;
F_173 ( V_296 , L_4 ,
& V_306 -> V_3 , & V_306 -> V_2 ) ;
break;
case V_191 :
V_308 = F_176 ( V_304 ) ;
F_173 ( V_296 ,
L_7 ,
& V_308 -> V_3 , & V_308 -> V_2 ,
V_308 -> V_309 [ 0 ] & 0x0f ,
V_308 -> V_309 [ 1 ] ,
V_308 -> V_309 [ 2 ] ) ;
break;
}
}
void F_177 ( struct V_18 * V_19 , int V_310 , bool V_135 )
{
struct V_295 * V_296 ;
V_296 = F_178 ( L_8 ) ;
if ( V_296 == NULL )
return;
F_179 ( V_135 , V_296 ) ;
F_171 ( V_19 , V_296 ) ;
F_173 ( V_296 , L_9 , V_310 ) ;
F_180 ( V_296 ) ;
}
void F_47 ( struct V_18 * V_19 , int V_310 , bool V_135 )
{
struct V_295 * V_296 ;
V_296 = F_178 ( L_10 ) ;
if ( V_296 == NULL )
return;
F_179 ( V_135 , V_296 ) ;
F_171 ( V_19 , V_296 ) ;
F_173 ( V_296 , L_9 , V_310 ) ;
F_180 ( V_296 ) ;
}
void F_181 ( struct V_18 * V_19 ,
struct V_303 * V_304 )
{
struct V_295 * V_296 ;
T_2 V_8 ;
V_296 = F_178 ( L_11 ) ;
if ( V_296 == NULL )
return;
F_174 ( V_304 , V_19 -> V_22 . V_5 , V_296 ) ;
V_8 = F_172 ( V_19 -> V_21 . V_8 ) ;
F_173 ( V_296 , L_6 , V_8 , V_8 ) ;
F_180 ( V_296 ) ;
}
void F_182 ( struct V_18 * V_19 ,
struct V_303 * V_304 , T_3 V_311 )
{
struct V_295 * V_296 ;
T_2 V_8 ;
V_296 = F_178 ( L_12 ) ;
if ( V_296 == NULL )
return;
F_174 ( V_304 , V_19 -> V_22 . V_5 , V_296 ) ;
V_8 = F_172 ( V_19 -> V_21 . V_8 ) ;
F_173 ( V_296 , L_13 ,
V_8 , V_8 , F_172 ( V_311 ) ) ;
F_180 ( V_296 ) ;
}
void F_183 ( struct V_303 * V_304 , T_9 V_5 )
{
struct V_295 * V_296 ;
V_296 = F_178 ( L_14 ) ;
if ( V_296 == NULL )
return;
F_174 ( V_304 , V_5 , V_296 ) ;
F_180 ( V_296 ) ;
}
void F_184 ( struct V_303 * V_304 , T_9 V_5 ,
T_3 V_312 , T_3 V_311 )
{
struct V_295 * V_296 ;
T_2 V_8 ;
V_296 = F_178 ( L_14 ) ;
if ( V_296 == NULL )
return;
F_174 ( V_304 , V_5 , V_296 ) ;
V_8 = F_172 ( V_312 ) ;
F_173 ( V_296 , L_13 ,
V_8 , V_8 , F_172 ( V_311 ) ) ;
F_180 ( V_296 ) ;
}
void F_185 ( struct V_18 * V_19 ,
struct V_303 * V_304 , T_4 V_9 )
{
struct V_295 * V_296 ;
T_3 V_312 ;
T_3 V_311 ;
V_296 = F_178 ( L_15 ) ;
if ( V_296 == NULL )
return;
F_174 ( V_304 , V_19 -> V_22 . V_5 , V_296 ) ;
if ( F_186 ( V_304 , V_9 , & V_312 , & V_311 ) == 0 ) {
T_2 V_8 = F_172 ( V_312 ) ;
F_173 ( V_296 , L_13 ,
V_8 , V_8 , F_172 ( V_311 ) ) ;
}
F_180 ( V_296 ) ;
}
