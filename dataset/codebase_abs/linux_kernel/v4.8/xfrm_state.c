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
F_35 ( V_19 -> V_70 ) ;
F_35 ( V_19 -> V_59 ) ;
F_35 ( V_19 -> V_71 ) ;
F_35 ( V_19 -> V_72 ) ;
F_35 ( V_19 -> V_73 ) ;
if ( V_19 -> V_74 )
F_31 ( V_19 -> V_74 ) ;
if ( V_19 -> V_75 )
F_31 ( V_19 -> V_75 ) ;
if ( V_19 -> V_76 )
F_31 ( V_19 -> V_76 ) ;
if ( V_19 -> type ) {
V_19 -> type -> V_77 ( V_19 ) ;
F_26 ( V_19 -> type ) ;
}
F_36 ( V_19 ) ;
F_35 ( V_19 ) ;
}
static void F_37 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = F_12 ( V_27 , struct V_1 , V_6 . V_78 ) ;
struct V_18 * V_19 ;
struct V_16 * V_17 ;
struct V_10 V_79 ;
F_15 ( & V_80 ) ;
F_38 ( & V_1 -> V_6 . V_81 , & V_79 ) ;
F_16 ( & V_80 ) ;
F_8 (x, tmp, &gc_list, gclist)
F_32 ( V_19 ) ;
}
static inline unsigned long F_39 ( long V_82 )
{
if ( V_82 >= ( V_83 - 1 ) / V_84 )
return V_83 - 1 ;
else
return V_82 * V_84 ;
}
static enum V_85 F_40 ( struct V_86 * V_87 )
{
struct V_88 * V_89 = F_12 ( V_87 , struct V_88 , V_90 ) ;
struct V_18 * V_19 = F_12 ( V_89 , struct V_18 , V_65 ) ;
unsigned long V_91 = F_41 () ;
long V_92 = V_93 ;
int V_94 = 0 ;
int V_47 = 0 ;
F_42 ( & V_19 -> V_95 ) ;
if ( V_19 -> V_96 . V_97 == V_98 )
goto V_64;
if ( V_19 -> V_96 . V_97 == V_99 )
goto V_100;
if ( V_19 -> V_101 . V_102 ) {
long V_103 = V_19 -> V_101 . V_102 +
V_19 -> V_104 . V_105 - V_91 ;
if ( V_103 <= 0 ) {
if ( V_19 -> V_106 & V_107 ) {
V_19 -> V_104 . V_105 = V_91 - V_19 -> V_108 - 1 ;
V_103 = V_19 -> V_101 . V_102 - V_19 -> V_108 ;
} else
goto V_100;
}
if ( V_103 < V_92 )
V_92 = V_103 ;
}
if ( V_19 -> V_101 . V_109 ) {
long V_103 = V_19 -> V_101 . V_109 +
( V_19 -> V_104 . V_110 ? : V_91 ) - V_91 ;
if ( V_103 <= 0 )
goto V_100;
if ( V_103 < V_92 )
V_92 = V_103 ;
}
if ( V_19 -> V_96 . V_111 )
goto V_112;
if ( V_19 -> V_101 . V_113 ) {
long V_103 = V_19 -> V_101 . V_113 +
V_19 -> V_104 . V_105 - V_91 ;
if ( V_103 <= 0 ) {
V_94 = 1 ;
V_19 -> V_106 &= ~ V_107 ;
} else if ( V_103 < V_92 ) {
V_92 = V_103 ;
V_19 -> V_106 |= V_107 ;
V_19 -> V_108 = V_103 ;
}
}
if ( V_19 -> V_101 . V_114 ) {
long V_103 = V_19 -> V_101 . V_114 +
( V_19 -> V_104 . V_110 ? : V_91 ) - V_91 ;
if ( V_103 <= 0 )
V_94 = 1 ;
else if ( V_103 < V_92 )
V_92 = V_103 ;
}
V_19 -> V_96 . V_111 = V_94 ;
if ( V_94 )
F_43 ( V_19 , 0 , 0 ) ;
V_112:
if ( V_92 != V_93 ) {
F_44 ( & V_19 -> V_65 , F_45 ( V_92 , 0 ) , V_115 ) ;
}
goto V_64;
V_100:
if ( V_19 -> V_96 . V_97 == V_116 && V_19 -> V_21 . V_8 == 0 )
V_19 -> V_96 . V_97 = V_99 ;
V_47 = F_46 ( V_19 ) ;
if ( ! V_47 )
F_43 ( V_19 , 1 , 0 ) ;
F_47 ( V_19 , V_47 ? 0 : 1 , true ) ;
V_64:
F_48 ( & V_19 -> V_95 ) ;
return V_117 ;
}
struct V_18 * F_49 ( struct V_1 * V_1 )
{
struct V_18 * V_19 ;
V_19 = F_50 ( sizeof( struct V_18 ) , V_118 ) ;
if ( V_19 ) {
F_51 ( & V_19 -> V_119 , V_1 ) ;
F_52 ( & V_19 -> V_120 , 1 ) ;
F_52 ( & V_19 -> V_121 , 0 ) ;
F_53 ( & V_19 -> V_96 . V_122 ) ;
F_54 ( & V_19 -> V_23 ) ;
F_54 ( & V_19 -> V_24 ) ;
F_54 ( & V_19 -> V_25 ) ;
F_55 ( & V_19 -> V_65 , F_40 ,
V_123 , V_124 ) ;
F_56 ( & V_19 -> V_66 , V_125 ,
( unsigned long ) V_19 ) ;
V_19 -> V_104 . V_105 = F_41 () ;
V_19 -> V_101 . V_126 = V_127 ;
V_19 -> V_101 . V_128 = V_127 ;
V_19 -> V_101 . V_129 = V_127 ;
V_19 -> V_101 . V_130 = V_127 ;
V_19 -> V_131 = 0 ;
V_19 -> V_132 = 0 ;
V_19 -> V_74 = NULL ;
V_19 -> V_75 = NULL ;
F_57 ( & V_19 -> V_95 ) ;
}
return V_19 ;
}
void F_58 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_119 ( V_19 ) ;
F_59 ( V_19 -> V_96 . V_97 != V_98 ) ;
F_15 ( & V_80 ) ;
F_9 ( & V_19 -> V_133 , & V_1 -> V_6 . V_81 ) ;
F_16 ( & V_80 ) ;
F_60 ( & V_1 -> V_6 . V_78 ) ;
}
int F_46 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_119 ( V_19 ) ;
int V_47 = - V_134 ;
if ( V_19 -> V_96 . V_97 != V_98 ) {
V_19 -> V_96 . V_97 = V_98 ;
F_42 ( & V_1 -> V_6 . V_39 ) ;
F_61 ( & V_19 -> V_96 . V_122 ) ;
F_62 ( & V_19 -> V_23 ) ;
F_62 ( & V_19 -> V_24 ) ;
if ( V_19 -> V_21 . V_8 )
F_62 ( & V_19 -> V_25 ) ;
V_1 -> V_6 . V_135 -- ;
F_48 ( & V_1 -> V_6 . V_39 ) ;
F_63 ( V_19 ) ;
V_47 = 0 ;
}
return V_47 ;
}
int F_64 ( struct V_18 * V_19 )
{
int V_47 ;
F_15 ( & V_19 -> V_95 ) ;
V_47 = F_46 ( V_19 ) ;
F_16 ( & V_19 -> V_95 ) ;
return V_47 ;
}
static inline int
F_65 ( struct V_1 * V_1 , T_4 V_9 , bool V_136 )
{
int V_38 , V_47 = 0 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
F_66 (x, net->xfrm.state_bydst+i, bydst) {
if ( F_67 ( V_19 -> V_21 . V_9 , V_9 ) &&
( V_47 = F_68 ( V_19 ) ) != 0 ) {
F_47 ( V_19 , 0 , V_136 ) ;
return V_47 ;
}
}
}
return V_47 ;
}
static inline int
F_65 ( struct V_1 * V_1 , T_4 V_9 , bool V_136 )
{
return 0 ;
}
int F_69 ( struct V_1 * V_1 , T_4 V_9 , bool V_136 )
{
int V_38 , V_47 = 0 , V_137 = 0 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_47 = F_65 ( V_1 , V_9 , V_136 ) ;
if ( V_47 )
goto V_64;
V_47 = - V_134 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
V_138:
F_66 (x, net->xfrm.state_bydst+i, bydst) {
if ( ! F_70 ( V_19 ) &&
F_67 ( V_19 -> V_21 . V_9 , V_9 ) ) {
F_71 ( V_19 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
V_47 = F_64 ( V_19 ) ;
F_47 ( V_19 , V_47 ? 0 : 1 ,
V_136 ) ;
F_63 ( V_19 ) ;
if ( ! V_47 )
V_137 ++ ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
goto V_138;
}
}
}
if ( V_137 )
V_47 = 0 ;
V_64:
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_47 ;
}
void F_72 ( struct V_1 * V_1 , struct V_139 * V_140 )
{
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_140 -> V_141 = V_1 -> V_6 . V_135 ;
V_140 -> V_142 = V_1 -> V_6 . V_7 ;
V_140 -> V_143 = V_144 ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
}
static int
F_73 ( struct V_18 * V_19 , const struct V_145 * V_146 ,
const struct V_147 * V_148 ,
const T_1 * V_2 , const T_1 * V_3 ,
unsigned short V_5 )
{
struct V_44 * V_45 = F_18 ( V_5 ) ;
if ( ! V_45 )
return - 1 ;
V_45 -> V_149 ( & V_19 -> V_150 , V_146 ) ;
if ( V_5 != V_148 -> V_151 ) {
F_21 ( V_45 ) ;
V_45 = F_18 ( V_148 -> V_151 ) ;
if ( ! V_45 )
return - 1 ;
}
V_45 -> V_152 ( V_19 , V_148 , V_2 , V_3 ) ;
F_21 ( V_45 ) ;
return 0 ;
}
static struct V_18 * F_74 ( struct V_1 * V_1 , T_2 V_153 ,
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
if ( ( V_153 & V_19 -> V_153 . V_154 ) != V_19 -> V_153 . V_155 )
continue;
F_71 ( V_19 ) ;
return V_19 ;
}
return NULL ;
}
static struct V_18 * F_76 ( struct V_1 * V_1 , T_2 V_153 ,
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
if ( ( V_153 & V_19 -> V_153 . V_154 ) != V_19 -> V_153 . V_155 )
continue;
F_71 ( V_19 ) ;
return V_19 ;
}
return NULL ;
}
static inline struct V_18 *
F_77 ( struct V_18 * V_19 , int V_156 , int V_5 )
{
struct V_1 * V_1 = V_119 ( V_19 ) ;
T_2 V_153 = V_19 -> V_153 . V_155 & V_19 -> V_153 . V_154 ;
if ( V_156 )
return F_74 ( V_1 , V_153 , & V_19 -> V_21 . V_2 ,
V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_5 ) ;
else
return F_76 ( V_1 , V_153 ,
& V_19 -> V_21 . V_2 ,
& V_19 -> V_22 . V_3 ,
V_19 -> V_21 . V_9 , V_5 ) ;
}
static void F_78 ( struct V_1 * V_1 , int V_157 )
{
if ( V_157 &&
( V_1 -> V_6 . V_7 + 1 ) < V_144 &&
V_1 -> V_6 . V_135 > V_1 -> V_6 . V_7 )
F_60 ( & V_1 -> V_6 . V_28 ) ;
}
static void F_79 ( struct V_158 * V_159 , struct V_18 * V_19 ,
const struct V_145 * V_146 , unsigned short V_5 ,
struct V_18 * * V_160 , int * V_161 ,
int * error )
{
if ( V_19 -> V_96 . V_97 == V_162 ) {
if ( ( V_19 -> V_150 . V_5 &&
! F_80 ( & V_19 -> V_150 , V_146 , V_19 -> V_150 . V_5 ) ) ||
! F_81 ( V_19 , V_159 , V_146 ) )
return;
if ( ! * V_160 ||
( * V_160 ) -> V_96 . V_111 > V_19 -> V_96 . V_111 ||
( ( * V_160 ) -> V_96 . V_111 == V_19 -> V_96 . V_111 &&
( * V_160 ) -> V_104 . V_105 < V_19 -> V_104 . V_105 ) )
* V_160 = V_19 ;
} else if ( V_19 -> V_96 . V_97 == V_116 ) {
* V_161 = 1 ;
} else if ( V_19 -> V_96 . V_97 == V_163 ||
V_19 -> V_96 . V_97 == V_99 ) {
if ( F_80 ( & V_19 -> V_150 , V_146 , V_19 -> V_150 . V_5 ) &&
F_81 ( V_19 , V_159 , V_146 ) )
* error = - V_134 ;
}
}
struct V_18 *
F_82 ( const T_1 * V_2 , const T_1 * V_3 ,
const struct V_145 * V_146 , struct V_147 * V_148 ,
struct V_158 * V_159 , int * V_47 ,
unsigned short V_5 )
{
static T_1 V_164 = { } ;
struct V_1 * V_1 = F_83 ( V_159 ) ;
unsigned int V_20 , V_165 ;
struct V_18 * V_19 , * V_166 , * V_167 ;
int V_168 = 0 ;
int error = 0 ;
struct V_18 * V_160 = NULL ;
T_2 V_153 = V_159 -> V_153 . V_155 & V_159 -> V_153 . V_154 ;
unsigned short V_151 = V_148 -> V_151 ;
struct V_169 V_170 ;
V_167 = NULL ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_20 = F_1 ( V_1 , V_2 , V_3 , V_148 -> V_4 , V_151 ) ;
F_66 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_151 &&
V_19 -> V_22 . V_4 == V_148 -> V_4 &&
( V_153 & V_19 -> V_153 . V_154 ) == V_19 -> V_153 . V_155 &&
! ( V_19 -> V_22 . V_171 & V_172 ) &&
F_84 ( V_19 , V_2 , V_3 , V_151 ) &&
V_148 -> V_57 == V_19 -> V_22 . V_57 &&
V_148 -> V_21 . V_9 == V_19 -> V_21 . V_9 &&
( V_148 -> V_21 . V_8 == V_19 -> V_21 . V_8 || ! V_148 -> V_21 . V_8 ) )
F_79 ( V_159 , V_19 , V_146 , V_151 ,
& V_160 , & V_168 , & error ) ;
}
if ( V_160 || V_168 )
goto V_173;
V_165 = F_1 ( V_1 , V_2 , & V_164 , V_148 -> V_4 , V_151 ) ;
F_66 (x, net->xfrm.state_bydst+h_wildcard, bydst) {
if ( V_19 -> V_22 . V_5 == V_151 &&
V_19 -> V_22 . V_4 == V_148 -> V_4 &&
( V_153 & V_19 -> V_153 . V_154 ) == V_19 -> V_153 . V_155 &&
! ( V_19 -> V_22 . V_171 & V_172 ) &&
F_75 ( & V_19 -> V_21 . V_2 , V_2 , V_151 ) &&
V_148 -> V_57 == V_19 -> V_22 . V_57 &&
V_148 -> V_21 . V_9 == V_19 -> V_21 . V_9 &&
( V_148 -> V_21 . V_8 == V_19 -> V_21 . V_8 || ! V_148 -> V_21 . V_8 ) )
F_79 ( V_159 , V_19 , V_146 , V_151 ,
& V_160 , & V_168 , & error ) ;
}
V_173:
V_19 = V_160 ;
if ( ! V_19 && ! error && ! V_168 ) {
if ( V_148 -> V_21 . V_8 &&
( V_166 = F_74 ( V_1 , V_153 , V_2 , V_148 -> V_21 . V_8 ,
V_148 -> V_21 . V_9 , V_151 ) ) != NULL ) {
V_167 = V_166 ;
error = - V_51 ;
goto V_64;
}
V_170 . V_1 = V_1 ;
if ( ! F_85 ( & V_170 ) ) {
error = - V_134 ;
goto V_64;
}
V_19 = F_49 ( V_1 ) ;
if ( V_19 == NULL ) {
error = - V_174 ;
goto V_64;
}
F_73 ( V_19 , V_146 , V_148 , V_2 , V_3 , V_5 ) ;
memcpy ( & V_19 -> V_153 , & V_159 -> V_153 , sizeof( V_19 -> V_153 ) ) ;
error = F_86 ( V_19 , V_159 -> V_175 , V_146 -> V_176 ) ;
if ( error ) {
V_19 -> V_96 . V_97 = V_98 ;
V_167 = V_19 ;
V_19 = NULL ;
goto V_64;
}
if ( F_87 ( V_19 , V_148 , V_159 ) == 0 ) {
V_19 -> V_96 . V_97 = V_116 ;
F_88 ( & V_19 -> V_96 . V_122 , & V_1 -> V_6 . V_177 ) ;
F_9 ( & V_19 -> V_23 , V_1 -> V_6 . V_40 + V_20 ) ;
V_20 = F_3 ( V_1 , V_2 , V_3 , V_151 ) ;
F_9 ( & V_19 -> V_24 , V_1 -> V_6 . V_41 + V_20 ) ;
if ( V_19 -> V_21 . V_8 ) {
V_20 = F_5 ( V_1 , & V_19 -> V_21 . V_2 , V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_151 ) ;
F_9 ( & V_19 -> V_25 , V_1 -> V_6 . V_42 + V_20 ) ;
}
V_19 -> V_101 . V_102 = V_1 -> V_6 . V_178 ;
F_44 ( & V_19 -> V_65 , F_45 ( V_1 -> V_6 . V_178 , 0 ) , V_115 ) ;
V_1 -> V_6 . V_135 ++ ;
F_78 ( V_1 , V_19 -> V_23 . V_92 != NULL ) ;
} else {
V_19 -> V_96 . V_97 = V_98 ;
V_167 = V_19 ;
V_19 = NULL ;
error = - V_134 ;
}
}
V_64:
if ( V_19 )
F_71 ( V_19 ) ;
else
* V_47 = V_168 ? - V_179 : error ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
if ( V_167 )
F_63 ( V_167 ) ;
return V_19 ;
}
struct V_18 *
F_89 ( struct V_1 * V_1 , T_2 V_153 ,
T_1 * V_2 , T_1 * V_3 ,
unsigned short V_5 , T_4 V_57 , T_4 V_9 , T_2 V_4 )
{
unsigned int V_20 ;
struct V_18 * V_180 = NULL , * V_19 = NULL ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_20 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_66 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_5 &&
V_19 -> V_22 . V_4 == V_4 &&
( V_153 & V_19 -> V_153 . V_154 ) == V_19 -> V_153 . V_155 &&
! ( V_19 -> V_22 . V_171 & V_172 ) &&
F_84 ( V_19 , V_2 , V_3 , V_5 ) &&
V_57 == V_19 -> V_22 . V_57 &&
V_9 == V_19 -> V_21 . V_9 &&
V_19 -> V_96 . V_97 == V_162 ) {
V_180 = V_19 ;
break;
}
}
if ( V_180 )
F_71 ( V_180 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_180 ;
}
struct V_18 * F_90 ( struct V_1 * V_1 , T_3 V_8 ,
unsigned short V_5 )
{
struct V_18 * V_19 ;
struct V_181 * V_182 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
F_91 (w, &net->xfrm.state_all, all) {
V_19 = F_12 ( V_182 , struct V_18 , V_96 ) ;
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
struct V_1 * V_1 = V_119 ( V_19 ) ;
unsigned int V_20 ;
F_88 ( & V_19 -> V_96 . V_122 , & V_1 -> V_6 . V_177 ) ;
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
F_44 ( & V_19 -> V_65 , F_45 ( 1 , 0 ) , V_115 ) ;
if ( V_19 -> V_131 )
F_93 ( & V_19 -> V_66 , V_183 + V_19 -> V_131 ) ;
V_1 -> V_6 . V_135 ++ ;
F_78 ( V_1 , V_19 -> V_23 . V_92 != NULL ) ;
}
static void F_94 ( struct V_18 * V_184 )
{
struct V_1 * V_1 = V_119 ( V_184 ) ;
unsigned short V_5 = V_184 -> V_22 . V_5 ;
T_2 V_4 = V_184 -> V_22 . V_4 ;
struct V_18 * V_19 ;
unsigned int V_20 ;
T_2 V_153 = V_184 -> V_153 . V_155 & V_184 -> V_153 . V_154 ;
V_20 = F_1 ( V_1 , & V_184 -> V_21 . V_2 , & V_184 -> V_22 . V_3 , V_4 , V_5 ) ;
F_66 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_5 &&
V_19 -> V_22 . V_4 == V_4 &&
( V_153 & V_19 -> V_153 . V_154 ) == V_19 -> V_153 . V_155 &&
F_75 ( & V_19 -> V_21 . V_2 , & V_184 -> V_21 . V_2 , V_5 ) &&
F_75 ( & V_19 -> V_22 . V_3 , & V_184 -> V_22 . V_3 , V_5 ) )
V_19 -> V_185 ++ ;
}
}
void F_95 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_119 ( V_19 ) ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
F_94 ( V_19 ) ;
F_92 ( V_19 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
}
static struct V_18 * F_96 ( struct V_1 * V_1 ,
const struct V_186 * V_154 ,
unsigned short V_5 , T_4 V_57 ,
T_2 V_4 , T_4 V_9 ,
const T_1 * V_2 ,
const T_1 * V_3 ,
int V_187 )
{
unsigned int V_20 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
struct V_18 * V_19 ;
T_2 V_153 = V_154 -> V_155 & V_154 -> V_154 ;
F_66 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_4 != V_4 ||
V_19 -> V_22 . V_57 != V_57 ||
V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_96 . V_97 != V_116 ||
V_19 -> V_21 . V_8 != 0 ||
V_19 -> V_21 . V_9 != V_9 ||
( V_153 & V_19 -> V_153 . V_154 ) != V_19 -> V_153 . V_155 ||
! F_75 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) ||
! F_75 ( & V_19 -> V_22 . V_3 , V_3 , V_5 ) )
continue;
F_71 ( V_19 ) ;
return V_19 ;
}
if ( ! V_187 )
return NULL ;
V_19 = F_49 ( V_1 ) ;
if ( F_20 ( V_19 ) ) {
switch ( V_5 ) {
case V_188 :
V_19 -> V_150 . V_2 . V_189 = V_2 -> V_189 ;
V_19 -> V_150 . V_3 . V_189 = V_3 -> V_189 ;
V_19 -> V_150 . V_190 = 32 ;
V_19 -> V_150 . V_191 = 32 ;
V_19 -> V_22 . V_3 . V_189 = V_3 -> V_189 ;
V_19 -> V_21 . V_2 . V_189 = V_2 -> V_189 ;
break;
case V_192 :
V_19 -> V_150 . V_2 . V_193 = V_2 -> V_193 ;
V_19 -> V_150 . V_3 . V_193 = V_3 -> V_193 ;
V_19 -> V_150 . V_190 = 128 ;
V_19 -> V_150 . V_191 = 128 ;
V_19 -> V_22 . V_3 . V_193 = V_3 -> V_193 ;
V_19 -> V_21 . V_2 . V_193 = V_2 -> V_193 ;
break;
}
V_19 -> V_96 . V_97 = V_116 ;
V_19 -> V_21 . V_9 = V_9 ;
V_19 -> V_22 . V_5 = V_5 ;
V_19 -> V_22 . V_57 = V_57 ;
V_19 -> V_22 . V_4 = V_4 ;
V_19 -> V_153 . V_155 = V_154 -> V_155 ;
V_19 -> V_153 . V_154 = V_154 -> V_154 ;
V_19 -> V_101 . V_102 = V_1 -> V_6 . V_178 ;
F_71 ( V_19 ) ;
F_44 ( & V_19 -> V_65 , F_45 ( V_1 -> V_6 . V_178 , 0 ) , V_115 ) ;
F_88 ( & V_19 -> V_96 . V_122 , & V_1 -> V_6 . V_177 ) ;
F_9 ( & V_19 -> V_23 , V_1 -> V_6 . V_40 + V_20 ) ;
V_20 = F_3 ( V_1 , V_2 , V_3 , V_5 ) ;
F_9 ( & V_19 -> V_24 , V_1 -> V_6 . V_41 + V_20 ) ;
V_1 -> V_6 . V_135 ++ ;
F_78 ( V_1 , V_19 -> V_23 . V_92 != NULL ) ;
}
return V_19 ;
}
int F_97 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_119 ( V_19 ) ;
struct V_18 * V_194 , * V_167 ;
int V_5 ;
int V_47 ;
T_2 V_153 = V_19 -> V_153 . V_155 & V_19 -> V_153 . V_154 ;
int V_156 = F_67 ( V_19 -> V_21 . V_9 , V_195 ) ;
V_5 = V_19 -> V_22 . V_5 ;
V_167 = NULL ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_194 = F_77 ( V_19 , V_156 , V_5 ) ;
if ( V_194 ) {
V_167 = V_194 ;
V_194 = NULL ;
V_47 = - V_51 ;
goto V_64;
}
if ( V_156 && V_19 -> V_96 . V_196 ) {
V_194 = F_98 ( V_1 , V_153 , V_19 -> V_96 . V_196 ) ;
if ( V_194 && ( ( V_194 -> V_21 . V_9 != V_19 -> V_21 . V_9 ) ||
! F_75 ( & V_194 -> V_21 . V_2 , & V_19 -> V_21 . V_2 , V_5 ) ) ) {
V_167 = V_194 ;
V_194 = NULL ;
}
}
if ( V_156 && ! V_194 )
V_194 = F_96 ( V_1 , & V_19 -> V_153 , V_5 , V_19 -> V_22 . V_57 ,
V_19 -> V_22 . V_4 , V_19 -> V_21 . V_9 ,
& V_19 -> V_21 . V_2 , & V_19 -> V_22 . V_3 , 0 ) ;
F_94 ( V_19 ) ;
F_92 ( V_19 ) ;
V_47 = 0 ;
V_64:
F_16 ( & V_1 -> V_6 . V_39 ) ;
if ( V_194 ) {
F_64 ( V_194 ) ;
F_63 ( V_194 ) ;
}
if ( V_167 )
F_63 ( V_167 ) ;
return V_47 ;
}
static struct V_18 * F_99 ( struct V_18 * V_197 )
{
struct V_1 * V_1 = V_119 ( V_197 ) ;
struct V_18 * V_19 = F_49 ( V_1 ) ;
if ( ! V_19 )
goto V_64;
memcpy ( & V_19 -> V_21 , & V_197 -> V_21 , sizeof( V_19 -> V_21 ) ) ;
memcpy ( & V_19 -> V_150 , & V_197 -> V_150 , sizeof( V_19 -> V_150 ) ) ;
memcpy ( & V_19 -> V_101 , & V_197 -> V_101 , sizeof( V_19 -> V_101 ) ) ;
V_19 -> V_22 . V_57 = V_197 -> V_22 . V_57 ;
V_19 -> V_22 . V_198 = V_197 -> V_22 . V_198 ;
V_19 -> V_22 . V_4 = V_197 -> V_22 . V_4 ;
V_19 -> V_22 . V_5 = V_197 -> V_22 . V_5 ;
V_19 -> V_22 . V_3 = V_197 -> V_22 . V_3 ;
if ( V_197 -> V_68 ) {
V_19 -> V_68 = F_100 ( V_197 -> V_68 ) ;
if ( ! V_19 -> V_68 )
goto error;
}
V_19 -> V_22 . V_199 = V_197 -> V_22 . V_199 ;
if ( V_197 -> V_67 ) {
V_19 -> V_67 = F_101 ( V_197 -> V_67 ) ;
if ( ! V_19 -> V_67 )
goto error;
}
if ( V_197 -> V_69 ) {
V_19 -> V_69 = F_102 ( V_197 -> V_69 ) ;
if ( ! V_19 -> V_69 )
goto error;
}
V_19 -> V_22 . V_200 = V_197 -> V_22 . V_200 ;
if ( V_197 -> V_70 ) {
V_19 -> V_70 = F_102 ( V_197 -> V_70 ) ;
if ( ! V_19 -> V_70 )
goto error;
}
V_19 -> V_22 . V_201 = V_197 -> V_22 . V_201 ;
if ( V_197 -> V_59 ) {
V_19 -> V_59 = F_103 ( V_197 -> V_59 , sizeof( * V_19 -> V_59 ) , V_202 ) ;
if ( ! V_19 -> V_59 )
goto error;
}
if ( V_197 -> V_71 ) {
V_19 -> V_71 = F_103 ( V_197 -> V_71 , sizeof( * V_19 -> V_71 ) ,
V_202 ) ;
if ( ! V_19 -> V_71 )
goto error;
}
if ( V_197 -> V_72 ) {
if ( F_104 ( V_19 , V_197 ) )
goto error;
}
memcpy ( & V_19 -> V_153 , & V_197 -> V_153 , sizeof( V_19 -> V_153 ) ) ;
if ( F_105 ( V_19 ) < 0 )
goto error;
V_19 -> V_22 . V_171 = V_197 -> V_22 . V_171 ;
V_19 -> V_22 . V_203 = V_197 -> V_22 . V_203 ;
V_19 -> V_204 = V_197 -> V_204 ;
V_19 -> V_132 = V_197 -> V_132 ;
V_19 -> V_131 = V_197 -> V_131 ;
V_19 -> V_104 . V_105 = V_197 -> V_104 . V_105 ;
V_19 -> V_96 . V_97 = V_197 -> V_96 . V_97 ;
V_19 -> V_96 . V_196 = V_197 -> V_96 . V_196 ;
return V_19 ;
error:
F_63 ( V_19 ) ;
V_64:
return NULL ;
}
struct V_18 * F_106 ( struct V_205 * V_154 , struct V_1 * V_1 )
{
unsigned int V_20 ;
struct V_18 * V_19 = NULL ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
if ( V_154 -> V_4 ) {
V_20 = F_1 ( V_1 , & V_154 -> V_206 , & V_154 -> V_207 ,
V_154 -> V_4 , V_154 -> V_208 ) ;
F_66 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_57 != V_154 -> V_57 ||
V_19 -> V_21 . V_9 != V_154 -> V_9 )
continue;
if ( V_154 -> V_4 && V_19 -> V_22 . V_4 != V_154 -> V_4 )
continue;
if ( ! F_75 ( & V_19 -> V_21 . V_2 , & V_154 -> V_206 ,
V_154 -> V_208 ) ||
! F_75 ( & V_19 -> V_22 . V_3 , & V_154 -> V_207 ,
V_154 -> V_208 ) )
continue;
F_71 ( V_19 ) ;
break;
}
} else {
V_20 = F_3 ( V_1 , & V_154 -> V_206 , & V_154 -> V_207 ,
V_154 -> V_208 ) ;
F_66 (x, net->xfrm.state_bysrc+h, bysrc) {
if ( V_19 -> V_22 . V_57 != V_154 -> V_57 ||
V_19 -> V_21 . V_9 != V_154 -> V_9 )
continue;
if ( ! F_75 ( & V_19 -> V_21 . V_2 , & V_154 -> V_206 ,
V_154 -> V_208 ) ||
! F_75 ( & V_19 -> V_22 . V_3 , & V_154 -> V_207 ,
V_154 -> V_208 ) )
continue;
F_71 ( V_19 ) ;
break;
}
}
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_19 ;
}
struct V_18 * F_107 ( struct V_18 * V_19 ,
struct V_205 * V_154 )
{
struct V_18 * V_209 ;
V_209 = F_99 ( V_19 ) ;
if ( ! V_209 )
return NULL ;
memcpy ( & V_209 -> V_21 . V_2 , & V_154 -> V_210 , sizeof( V_209 -> V_21 . V_2 ) ) ;
memcpy ( & V_209 -> V_22 . V_3 , & V_154 -> V_211 , sizeof( V_209 -> V_22 . V_3 ) ) ;
if ( F_75 ( & V_19 -> V_21 . V_2 , & V_154 -> V_210 , V_154 -> V_212 ) ) {
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
struct V_18 * V_194 , * V_167 ;
int V_47 ;
int V_156 = F_67 ( V_19 -> V_21 . V_9 , V_195 ) ;
struct V_1 * V_1 = V_119 ( V_19 ) ;
V_167 = NULL ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_194 = F_77 ( V_19 , V_156 , V_19 -> V_22 . V_5 ) ;
V_47 = - V_134 ;
if ( ! V_194 )
goto V_64;
if ( F_70 ( V_194 ) ) {
V_167 = V_194 ;
V_47 = - V_51 ;
goto V_64;
}
if ( V_194 -> V_96 . V_97 == V_116 ) {
F_92 ( V_19 ) ;
V_19 = NULL ;
}
V_47 = 0 ;
V_64:
F_16 ( & V_1 -> V_6 . V_39 ) ;
if ( V_167 )
F_63 ( V_167 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_19 ) {
F_64 ( V_194 ) ;
F_63 ( V_194 ) ;
return 0 ;
}
V_47 = - V_61 ;
F_15 ( & V_194 -> V_95 ) ;
if ( F_20 ( V_194 -> V_96 . V_97 == V_162 ) ) {
if ( V_19 -> V_59 && V_194 -> V_59 )
memcpy ( V_194 -> V_59 , V_19 -> V_59 , sizeof( * V_194 -> V_59 ) ) ;
if ( V_19 -> V_71 && V_194 -> V_71 ) {
memcpy ( V_194 -> V_71 , V_19 -> V_71 , sizeof( * V_194 -> V_71 ) ) ;
}
if ( ! V_156 && memcmp ( & V_194 -> V_150 , & V_19 -> V_150 , sizeof( V_194 -> V_150 ) ) )
memcpy ( & V_194 -> V_150 , & V_19 -> V_150 , sizeof( V_194 -> V_150 ) ) ;
memcpy ( & V_194 -> V_101 , & V_19 -> V_101 , sizeof( V_194 -> V_101 ) ) ;
V_194 -> V_96 . V_111 = 0 ;
F_44 ( & V_194 -> V_65 , F_45 ( 1 , 0 ) , V_115 ) ;
if ( V_194 -> V_104 . V_110 )
F_109 ( V_194 ) ;
V_47 = 0 ;
V_19 -> V_96 . V_97 = V_98 ;
F_110 ( V_19 ) ;
}
F_16 ( & V_194 -> V_95 ) ;
F_63 ( V_194 ) ;
return V_47 ;
}
int F_109 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_104 . V_110 )
V_19 -> V_104 . V_110 = F_41 () ;
if ( V_19 -> V_104 . V_213 >= V_19 -> V_101 . V_129 ||
V_19 -> V_104 . V_214 >= V_19 -> V_101 . V_130 ) {
V_19 -> V_96 . V_97 = V_99 ;
F_44 ( & V_19 -> V_65 , F_45 ( 0 , 0 ) , V_115 ) ;
return - V_61 ;
}
if ( ! V_19 -> V_96 . V_111 &&
( V_19 -> V_104 . V_213 >= V_19 -> V_101 . V_126 ||
V_19 -> V_104 . V_214 >= V_19 -> V_101 . V_128 ) ) {
V_19 -> V_96 . V_111 = 1 ;
F_43 ( V_19 , 0 , 0 ) ;
}
return 0 ;
}
struct V_18 *
F_111 ( struct V_1 * V_1 , T_2 V_153 , const T_1 * V_2 , T_3 V_8 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_19 = F_74 ( V_1 , V_153 , V_2 , V_8 , V_9 , V_5 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_19 ;
}
struct V_18 *
F_112 ( struct V_1 * V_1 , T_2 V_153 ,
const T_1 * V_2 , const T_1 * V_3 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_19 = F_76 ( V_1 , V_153 , V_2 , V_3 , V_9 , V_5 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_19 ;
}
struct V_18 *
F_113 ( struct V_1 * V_1 , const struct V_186 * V_153 , T_4 V_57 , T_2 V_4 ,
T_4 V_9 , const T_1 * V_2 ,
const T_1 * V_3 , int V_187 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_19 = F_96 ( V_1 , V_153 , V_5 , V_57 , V_4 , V_9 , V_2 , V_3 , V_187 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_19 ;
}
int
F_114 ( struct V_147 * * V_215 , struct V_147 * * V_216 , int V_217 ,
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
struct V_1 * V_1 = V_119 ( * V_216 ) ;
if ( ! V_45 )
return - V_48 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
if ( V_45 -> V_219 )
V_47 = V_45 -> V_219 ( V_215 , V_216 , V_217 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
F_21 ( V_45 ) ;
return V_47 ;
}
static struct V_18 * F_98 ( struct V_1 * V_1 , T_2 V_153 , T_2 V_196 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
F_66 (x, net->xfrm.state_bydst+i, bydst) {
if ( V_19 -> V_96 . V_196 == V_196 &&
( V_153 & V_19 -> V_153 . V_154 ) == V_19 -> V_153 . V_155 &&
V_19 -> V_96 . V_97 == V_116 ) {
F_71 ( V_19 ) ;
return V_19 ;
}
}
}
return NULL ;
}
struct V_18 * F_116 ( struct V_1 * V_1 , T_2 V_153 , T_2 V_196 )
{
struct V_18 * V_19 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
V_19 = F_98 ( V_1 , V_153 , V_196 ) ;
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
struct V_1 * V_1 = V_119 ( V_19 ) ;
unsigned int V_20 ;
struct V_18 * V_166 ;
int V_47 = - V_52 ;
T_3 V_229 = F_121 ( V_227 ) ;
T_3 V_230 = F_121 ( V_228 ) ;
T_2 V_153 = V_19 -> V_153 . V_155 & V_19 -> V_153 . V_154 ;
F_15 ( & V_19 -> V_95 ) ;
if ( V_19 -> V_96 . V_97 == V_98 )
goto V_231;
V_47 = 0 ;
if ( V_19 -> V_21 . V_8 )
goto V_231;
V_47 = - V_52 ;
if ( V_229 == V_230 ) {
V_166 = F_111 ( V_1 , V_153 , & V_19 -> V_21 . V_2 , V_229 , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
if ( V_166 ) {
F_63 ( V_166 ) ;
goto V_231;
}
V_19 -> V_21 . V_8 = V_229 ;
} else {
T_2 V_8 = 0 ;
for ( V_20 = 0 ; V_20 < V_228 - V_227 + 1 ; V_20 ++ ) {
V_8 = V_227 + F_122 () % ( V_228 - V_227 + 1 ) ;
V_166 = F_111 ( V_1 , V_153 , & V_19 -> V_21 . V_2 , F_121 ( V_8 ) , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
if ( V_166 == NULL ) {
V_19 -> V_21 . V_8 = F_121 ( V_8 ) ;
break;
}
F_63 ( V_166 ) ;
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
F_16 ( & V_19 -> V_95 ) ;
return V_47 ;
}
static bool F_123 ( struct V_18 * V_19 ,
struct V_232 * V_233 )
{
if ( V_233 ) {
if ( ( V_233 -> V_5 == V_188 ||
V_233 -> V_5 == V_192 ) &&
V_19 -> V_22 . V_5 != V_233 -> V_5 )
return false ;
return F_124 ( & V_19 -> V_22 . V_3 , & V_233 -> V_3 ,
V_233 -> V_234 ) &&
F_124 ( & V_19 -> V_21 . V_2 , & V_233 -> V_2 ,
V_233 -> V_235 ) ;
}
return true ;
}
int V_181 ( struct V_1 * V_1 , struct V_181 * V_236 ,
int (* F_125)( struct V_18 * , int , void * ) ,
void * V_237 )
{
struct V_18 * V_97 ;
struct V_181 * V_19 ;
int V_47 = 0 ;
if ( V_236 -> V_196 != 0 && F_126 ( & V_236 -> V_122 ) )
return 0 ;
F_15 ( & V_1 -> V_6 . V_39 ) ;
if ( F_126 ( & V_236 -> V_122 ) )
V_19 = F_127 ( & V_1 -> V_6 . V_177 , struct V_181 , V_122 ) ;
else
V_19 = F_127 ( & V_236 -> V_122 , struct V_181 , V_122 ) ;
F_128 (x, &net->xfrm.state_all, all) {
if ( V_19 -> V_97 == V_98 )
continue;
V_97 = F_12 ( V_19 , struct V_18 , V_96 ) ;
if ( ! F_67 ( V_97 -> V_21 . V_9 , V_236 -> V_9 ) )
continue;
if ( ! F_123 ( V_97 , V_236 -> V_233 ) )
continue;
V_47 = F_125 ( V_97 , V_236 -> V_196 , V_237 ) ;
if ( V_47 ) {
F_129 ( & V_236 -> V_122 , & V_19 -> V_122 ) ;
goto V_64;
}
V_236 -> V_196 ++ ;
}
if ( V_236 -> V_196 == 0 ) {
V_47 = - V_52 ;
goto V_64;
}
F_130 ( & V_236 -> V_122 ) ;
V_64:
F_16 ( & V_1 -> V_6 . V_39 ) ;
return V_47 ;
}
void F_131 ( struct V_181 * V_236 , T_4 V_9 ,
struct V_232 * V_233 )
{
F_53 ( & V_236 -> V_122 ) ;
V_236 -> V_9 = V_9 ;
V_236 -> V_97 = V_98 ;
V_236 -> V_196 = 0 ;
V_236 -> V_233 = V_233 ;
}
void F_132 ( struct V_181 * V_236 , struct V_1 * V_1 )
{
F_35 ( V_236 -> V_233 ) ;
if ( F_126 ( & V_236 -> V_122 ) )
return;
F_15 ( & V_1 -> V_6 . V_39 ) ;
F_61 ( & V_236 -> V_122 ) ;
F_16 ( & V_1 -> V_6 . V_39 ) ;
}
static void V_125 ( unsigned long V_237 )
{
struct V_18 * V_19 = (struct V_18 * ) V_237 ;
F_42 ( & V_19 -> V_95 ) ;
if ( V_19 -> V_96 . V_97 == V_162 ) {
if ( F_133 ( V_119 ( V_19 ) ) )
V_19 -> V_238 -> V_239 ( V_19 , V_240 ) ;
else
V_19 -> V_106 |= V_241 ;
}
F_48 ( & V_19 -> V_95 ) ;
}
void F_134 ( struct V_158 * V_242 , int V_243 , const struct V_169 * V_170 )
{
struct V_244 * V_96 ;
F_135 () ;
F_136 (km, &xfrm_km_list, list)
if ( V_96 -> V_245 )
V_96 -> V_245 ( V_242 , V_243 , V_170 ) ;
F_137 () ;
}
void F_138 ( struct V_18 * V_19 , const struct V_169 * V_170 )
{
struct V_244 * V_96 ;
F_135 () ;
F_136 (km, &xfrm_km_list, list)
if ( V_96 -> V_239 )
V_96 -> V_239 ( V_19 , V_170 ) ;
F_137 () ;
}
void F_43 ( struct V_18 * V_19 , int V_246 , T_2 V_247 )
{
struct V_169 V_170 ;
V_170 . V_237 . V_246 = V_246 ;
V_170 . V_247 = V_247 ;
V_170 . V_248 = V_249 ;
F_138 ( V_19 , & V_170 ) ;
}
int F_87 ( struct V_18 * V_19 , struct V_147 * V_250 , struct V_158 * V_159 )
{
int V_47 = - V_61 , V_251 ;
struct V_244 * V_96 ;
F_135 () ;
F_136 (km, &xfrm_km_list, list) {
V_251 = V_96 -> V_252 ( V_19 , V_250 , V_159 ) ;
if ( ! V_251 )
V_47 = V_251 ;
}
F_137 () ;
return V_47 ;
}
int F_139 ( struct V_18 * V_19 , T_1 * V_253 , T_6 V_254 )
{
int V_47 = - V_61 ;
struct V_244 * V_96 ;
F_135 () ;
F_136 (km, &xfrm_km_list, list) {
if ( V_96 -> V_255 )
V_47 = V_96 -> V_255 ( V_19 , V_253 , V_254 ) ;
if ( ! V_47 )
break;
}
F_137 () ;
return V_47 ;
}
void F_140 ( struct V_158 * V_159 , int V_243 , int V_246 , T_2 V_247 )
{
struct V_169 V_170 ;
V_170 . V_237 . V_246 = V_246 ;
V_170 . V_247 = V_247 ;
V_170 . V_248 = V_256 ;
F_134 ( V_159 , V_243 , & V_170 ) ;
}
int F_141 ( const struct V_257 * V_150 , T_4 V_243 , T_4 type ,
const struct V_205 * V_154 , int V_258 ,
const struct V_259 * V_260 )
{
int V_47 = - V_61 ;
int V_261 ;
struct V_244 * V_96 ;
F_135 () ;
F_136 (km, &xfrm_km_list, list) {
if ( V_96 -> V_262 ) {
V_261 = V_96 -> V_262 ( V_150 , V_243 , type , V_154 , V_258 , V_260 ) ;
if ( ! V_261 )
V_47 = V_261 ;
}
}
F_137 () ;
return V_47 ;
}
int F_142 ( struct V_1 * V_1 , T_4 V_9 , struct V_257 * V_150 , T_1 * V_263 )
{
int V_47 = - V_61 ;
int V_261 ;
struct V_244 * V_96 ;
F_135 () ;
F_136 (km, &xfrm_km_list, list) {
if ( V_96 -> V_264 ) {
V_261 = V_96 -> V_264 ( V_1 , V_9 , V_150 , V_263 ) ;
if ( ! V_261 )
V_47 = V_261 ;
}
}
F_137 () ;
return V_47 ;
}
bool F_85 ( const struct V_169 * V_170 )
{
struct V_244 * V_96 ;
bool V_265 = false ;
F_135 () ;
F_136 (km, &xfrm_km_list, list) {
if ( V_96 -> V_265 && V_96 -> V_265 ( V_170 ) ) {
V_265 = true ;
break;
}
}
F_137 () ;
return V_265 ;
}
int F_143 ( struct V_266 * V_267 , int V_268 , T_4 T_7 * V_269 , int V_270 )
{
int V_47 ;
T_4 * V_237 ;
struct V_244 * V_96 ;
struct V_158 * V_159 = NULL ;
if ( V_270 <= 0 || V_270 > V_271 )
return - V_272 ;
V_237 = F_144 ( V_270 , V_202 ) ;
if ( ! V_237 )
return - V_174 ;
V_47 = - V_273 ;
if ( F_145 ( V_237 , V_269 , V_270 ) )
goto V_64;
V_47 = - V_61 ;
F_135 () ;
F_136 (km, &xfrm_km_list, list) {
V_159 = V_96 -> V_274 ( V_267 , V_268 , V_237 ,
V_270 , & V_47 ) ;
if ( V_47 >= 0 )
break;
}
F_137 () ;
if ( V_47 >= 0 ) {
F_146 ( V_267 , V_47 , V_159 ) ;
F_147 ( V_159 ) ;
V_47 = 0 ;
}
V_64:
F_35 ( V_237 ) ;
return V_47 ;
}
int F_148 ( struct V_244 * V_96 )
{
F_15 ( & V_275 ) ;
F_149 ( & V_96 -> V_11 , & V_276 ) ;
F_16 ( & V_275 ) ;
return 0 ;
}
int F_150 ( struct V_244 * V_96 )
{
F_15 ( & V_275 ) ;
F_151 ( & V_96 -> V_11 ) ;
F_16 ( & V_275 ) ;
F_152 () ;
return 0 ;
}
int F_153 ( struct V_44 * V_45 )
{
int V_47 = 0 ;
if ( F_19 ( V_45 == NULL ) )
return - V_61 ;
if ( F_19 ( V_45 -> V_5 >= V_277 ) )
return - V_48 ;
F_15 ( & V_278 ) ;
if ( F_19 ( V_44 [ V_45 -> V_5 ] != NULL ) )
V_47 = - V_51 ;
else
F_154 ( V_44 [ V_45 -> V_5 ] , V_45 ) ;
F_16 ( & V_278 ) ;
return V_47 ;
}
int F_155 ( struct V_44 * V_45 )
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
F_156 ( V_44 [ V_45 -> V_5 ] , NULL ) ;
}
F_16 ( & V_278 ) ;
F_152 () ;
return V_47 ;
}
struct V_44 * F_18 ( unsigned int V_5 )
{
struct V_44 * V_45 ;
if ( F_19 ( V_5 >= V_277 ) )
return NULL ;
F_135 () ;
V_45 = F_157 ( V_44 [ V_5 ] ) ;
if ( F_19 ( ! V_45 ) )
F_137 () ;
return V_45 ;
}
void F_21 ( struct V_44 * V_45 )
{
F_137 () ;
}
void F_158 ( struct V_18 * V_19 )
{
if ( V_19 -> V_279 ) {
struct V_18 * V_250 = V_19 -> V_279 ;
if ( F_159 ( & V_250 -> V_121 ) == 2 )
F_64 ( V_250 ) ;
F_160 ( & V_250 -> V_121 ) ;
F_63 ( V_250 ) ;
V_19 -> V_279 = NULL ;
}
}
int F_161 ( struct V_18 * V_19 , int V_280 )
{
int V_220 ;
F_15 ( & V_19 -> V_95 ) ;
if ( V_19 -> V_96 . V_97 == V_162 &&
V_19 -> type && V_19 -> type -> V_281 )
V_220 = V_19 -> type -> V_281 ( V_19 , V_280 ) ;
else
V_220 = V_280 - V_19 -> V_22 . V_282 ;
F_16 ( & V_19 -> V_95 ) ;
return V_220 ;
}
int F_162 ( struct V_18 * V_19 , bool V_283 )
{
struct V_44 * V_45 ;
struct V_56 * V_74 ;
int V_5 = V_19 -> V_22 . V_5 ;
int V_47 ;
V_47 = - V_48 ;
V_45 = F_18 ( V_5 ) ;
if ( ! V_45 )
goto error;
V_47 = 0 ;
if ( V_45 -> V_284 )
V_47 = V_45 -> V_284 ( V_19 ) ;
F_21 ( V_45 ) ;
if ( V_47 )
goto error;
V_47 = - V_285 ;
if ( V_19 -> V_150 . V_5 != V_286 ) {
V_74 = F_30 ( V_19 -> V_22 . V_57 , V_19 -> V_150 . V_5 ) ;
if ( V_74 == NULL )
goto error;
if ( ! ( V_74 -> V_171 & V_287 ) &&
V_5 != V_19 -> V_150 . V_5 ) {
F_31 ( V_74 ) ;
goto error;
}
V_19 -> V_74 = V_74 ;
} else {
struct V_56 * V_75 ;
int V_288 = V_188 ;
V_74 = F_30 ( V_19 -> V_22 . V_57 , V_19 -> V_22 . V_5 ) ;
if ( V_74 == NULL )
goto error;
if ( ! ( V_74 -> V_171 & V_287 ) ) {
F_31 ( V_74 ) ;
goto error;
}
V_19 -> V_74 = V_74 ;
if ( V_19 -> V_22 . V_5 == V_188 )
V_288 = V_192 ;
V_75 = F_30 ( V_19 -> V_22 . V_57 , V_288 ) ;
if ( V_75 ) {
if ( V_75 -> V_171 & V_287 )
V_19 -> V_75 = V_75 ;
else
F_31 ( V_75 ) ;
}
}
V_19 -> type = F_23 ( V_19 -> V_21 . V_9 , V_5 ) ;
if ( V_19 -> type == NULL )
goto error;
V_47 = V_19 -> type -> V_289 ( V_19 ) ;
if ( V_47 )
goto error;
V_19 -> V_76 = F_30 ( V_19 -> V_22 . V_57 , V_5 ) ;
if ( V_19 -> V_76 == NULL ) {
V_47 = - V_285 ;
goto error;
}
if ( V_283 ) {
V_47 = F_163 ( V_19 ) ;
if ( V_47 )
goto error;
}
V_19 -> V_96 . V_97 = V_162 ;
error:
return V_47 ;
}
int F_105 ( struct V_18 * V_19 )
{
return F_162 ( V_19 , true ) ;
}
int T_8 F_164 ( struct V_1 * V_1 )
{
unsigned int V_290 ;
F_53 ( & V_1 -> V_6 . V_177 ) ;
V_290 = sizeof( struct V_10 ) * 8 ;
V_1 -> V_6 . V_40 = F_13 ( V_290 ) ;
if ( ! V_1 -> V_6 . V_40 )
goto V_291;
V_1 -> V_6 . V_41 = F_13 ( V_290 ) ;
if ( ! V_1 -> V_6 . V_41 )
goto V_292;
V_1 -> V_6 . V_42 = F_13 ( V_290 ) ;
if ( ! V_1 -> V_6 . V_42 )
goto V_293;
V_1 -> V_6 . V_7 = ( ( V_290 / sizeof( struct V_10 ) ) - 1 ) ;
V_1 -> V_6 . V_135 = 0 ;
F_165 ( & V_1 -> V_6 . V_28 , F_11 ) ;
F_166 ( & V_1 -> V_6 . V_81 ) ;
F_165 ( & V_1 -> V_6 . V_78 , F_37 ) ;
F_57 ( & V_1 -> V_6 . V_39 ) ;
return 0 ;
V_293:
F_14 ( V_1 -> V_6 . V_41 , V_290 ) ;
V_292:
F_14 ( V_1 -> V_6 . V_40 , V_290 ) ;
V_291:
return - V_174 ;
}
void F_167 ( struct V_1 * V_1 )
{
unsigned int V_290 ;
F_168 ( & V_1 -> V_6 . V_28 ) ;
F_69 ( V_1 , V_195 , false ) ;
F_168 ( & V_1 -> V_6 . V_78 ) ;
F_59 ( ! F_126 ( & V_1 -> V_6 . V_177 ) ) ;
V_290 = ( V_1 -> V_6 . V_7 + 1 ) * sizeof( struct V_10 ) ;
F_59 ( ! F_169 ( V_1 -> V_6 . V_42 ) ) ;
F_14 ( V_1 -> V_6 . V_42 , V_290 ) ;
F_59 ( ! F_169 ( V_1 -> V_6 . V_41 ) ) ;
F_14 ( V_1 -> V_6 . V_41 , V_290 ) ;
F_59 ( ! F_169 ( V_1 -> V_6 . V_40 ) ) ;
F_14 ( V_1 -> V_6 . V_40 , V_290 ) ;
}
static void F_170 ( struct V_18 * V_19 ,
struct V_294 * V_295 )
{
struct V_296 * V_297 = V_19 -> V_175 ;
T_2 V_8 = F_171 ( V_19 -> V_21 . V_8 ) ;
if ( V_297 )
F_172 ( V_295 , L_3 ,
V_297 -> V_298 , V_297 -> V_299 , V_297 -> V_300 ) ;
switch ( V_19 -> V_22 . V_5 ) {
case V_188 :
F_172 ( V_295 , L_4 ,
& V_19 -> V_22 . V_3 . V_189 , & V_19 -> V_21 . V_2 . V_189 ) ;
break;
case V_192 :
F_172 ( V_295 , L_5 ,
V_19 -> V_22 . V_3 . V_301 , V_19 -> V_21 . V_2 . V_301 ) ;
break;
}
F_172 ( V_295 , L_6 , V_8 , V_8 ) ;
}
static void F_173 ( struct V_302 * V_303 , T_9 V_5 ,
struct V_294 * V_295 )
{
const struct V_304 * V_305 ;
const struct V_306 * V_307 ;
switch ( V_5 ) {
case V_188 :
V_305 = F_174 ( V_303 ) ;
F_172 ( V_295 , L_4 ,
& V_305 -> V_3 , & V_305 -> V_2 ) ;
break;
case V_192 :
V_307 = F_175 ( V_303 ) ;
F_172 ( V_295 ,
L_7 ,
& V_307 -> V_3 , & V_307 -> V_2 ,
V_307 -> V_308 [ 0 ] & 0x0f ,
V_307 -> V_308 [ 1 ] ,
V_307 -> V_308 [ 2 ] ) ;
break;
}
}
void F_176 ( struct V_18 * V_19 , int V_309 , bool V_136 )
{
struct V_294 * V_295 ;
V_295 = F_177 ( L_8 ) ;
if ( V_295 == NULL )
return;
F_178 ( V_136 , V_295 ) ;
F_170 ( V_19 , V_295 ) ;
F_172 ( V_295 , L_9 , V_309 ) ;
F_179 ( V_295 ) ;
}
void F_47 ( struct V_18 * V_19 , int V_309 , bool V_136 )
{
struct V_294 * V_295 ;
V_295 = F_177 ( L_10 ) ;
if ( V_295 == NULL )
return;
F_178 ( V_136 , V_295 ) ;
F_170 ( V_19 , V_295 ) ;
F_172 ( V_295 , L_9 , V_309 ) ;
F_179 ( V_295 ) ;
}
void F_180 ( struct V_18 * V_19 ,
struct V_302 * V_303 )
{
struct V_294 * V_295 ;
T_2 V_8 ;
V_295 = F_177 ( L_11 ) ;
if ( V_295 == NULL )
return;
F_173 ( V_303 , V_19 -> V_22 . V_5 , V_295 ) ;
V_8 = F_171 ( V_19 -> V_21 . V_8 ) ;
F_172 ( V_295 , L_6 , V_8 , V_8 ) ;
F_179 ( V_295 ) ;
}
void F_181 ( struct V_18 * V_19 ,
struct V_302 * V_303 , T_3 V_310 )
{
struct V_294 * V_295 ;
T_2 V_8 ;
V_295 = F_177 ( L_12 ) ;
if ( V_295 == NULL )
return;
F_173 ( V_303 , V_19 -> V_22 . V_5 , V_295 ) ;
V_8 = F_171 ( V_19 -> V_21 . V_8 ) ;
F_172 ( V_295 , L_13 ,
V_8 , V_8 , F_171 ( V_310 ) ) ;
F_179 ( V_295 ) ;
}
void F_182 ( struct V_302 * V_303 , T_9 V_5 )
{
struct V_294 * V_295 ;
V_295 = F_177 ( L_14 ) ;
if ( V_295 == NULL )
return;
F_173 ( V_303 , V_5 , V_295 ) ;
F_179 ( V_295 ) ;
}
void F_183 ( struct V_302 * V_303 , T_9 V_5 ,
T_3 V_311 , T_3 V_310 )
{
struct V_294 * V_295 ;
T_2 V_8 ;
V_295 = F_177 ( L_14 ) ;
if ( V_295 == NULL )
return;
F_173 ( V_303 , V_5 , V_295 ) ;
V_8 = F_171 ( V_311 ) ;
F_172 ( V_295 , L_13 ,
V_8 , V_8 , F_171 ( V_310 ) ) ;
F_179 ( V_295 ) ;
}
void F_184 ( struct V_18 * V_19 ,
struct V_302 * V_303 , T_4 V_9 )
{
struct V_294 * V_295 ;
T_3 V_311 ;
T_3 V_310 ;
V_295 = F_177 ( L_15 ) ;
if ( V_295 == NULL )
return;
F_173 ( V_303 , V_19 -> V_22 . V_5 , V_295 ) ;
if ( F_185 ( V_303 , V_9 , & V_311 , & V_310 ) == 0 ) {
T_2 V_8 = F_171 ( V_311 ) ;
F_172 ( V_295 , L_13 ,
V_8 , V_8 , F_171 ( V_310 ) ) ;
}
F_179 ( V_295 ) ;
}
