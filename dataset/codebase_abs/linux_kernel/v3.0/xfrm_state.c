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
struct V_16 * V_17 , * V_18 ;
struct V_19 * V_20 ;
F_8 (x, entry, tmp, list, bydst) {
unsigned int V_21 ;
V_21 = F_2 ( & V_20 -> V_22 . V_2 , & V_20 -> V_23 . V_3 ,
V_20 -> V_23 . V_4 , V_20 -> V_23 . V_5 ,
V_15 ) ;
F_9 ( & V_20 -> V_24 , V_12 + V_21 ) ;
V_21 = F_4 ( & V_20 -> V_22 . V_2 , & V_20 -> V_23 . V_3 ,
V_20 -> V_23 . V_5 ,
V_15 ) ;
F_9 ( & V_20 -> V_25 , V_13 + V_21 ) ;
if ( V_20 -> V_22 . V_8 ) {
V_21 = F_6 ( & V_20 -> V_22 . V_2 , V_20 -> V_22 . V_8 ,
V_20 -> V_22 . V_9 , V_20 -> V_23 . V_5 ,
V_15 ) ;
F_9 ( & V_20 -> V_26 , V_14 + V_21 ) ;
}
}
}
static unsigned long F_10 ( unsigned int V_7 )
{
return ( ( V_7 + 1 ) << 1 ) * sizeof( struct V_10 ) ;
}
static void F_11 ( struct V_27 * V_28 )
{
struct V_1 * V_1 = F_12 ( V_28 , struct V_1 , V_6 . V_29 ) ;
struct V_10 * V_30 , * V_31 , * V_32 , * V_33 , * V_34 , * V_35 ;
unsigned long V_36 , V_37 ;
unsigned int V_15 , V_38 ;
int V_39 ;
F_13 ( & V_40 ) ;
V_36 = F_10 ( V_1 -> V_6 . V_7 ) ;
V_30 = F_14 ( V_36 ) ;
if ( ! V_30 )
goto V_41;
V_31 = F_14 ( V_36 ) ;
if ( ! V_31 ) {
F_15 ( V_30 , V_36 ) ;
goto V_41;
}
V_32 = F_14 ( V_36 ) ;
if ( ! V_32 ) {
F_15 ( V_30 , V_36 ) ;
F_15 ( V_31 , V_36 ) ;
goto V_41;
}
F_16 ( & V_42 ) ;
V_15 = ( V_36 / sizeof( struct V_10 ) ) - 1U ;
for ( V_39 = V_1 -> V_6 . V_7 ; V_39 >= 0 ; V_39 -- )
F_7 ( V_1 -> V_6 . V_43 + V_39 , V_30 , V_31 , V_32 ,
V_15 ) ;
V_33 = V_1 -> V_6 . V_43 ;
V_34 = V_1 -> V_6 . V_44 ;
V_35 = V_1 -> V_6 . V_45 ;
V_38 = V_1 -> V_6 . V_7 ;
V_1 -> V_6 . V_43 = V_30 ;
V_1 -> V_6 . V_44 = V_31 ;
V_1 -> V_6 . V_45 = V_32 ;
V_1 -> V_6 . V_7 = V_15 ;
F_17 ( & V_42 ) ;
V_37 = ( V_38 + 1 ) * sizeof( struct V_10 ) ;
F_15 ( V_33 , V_37 ) ;
F_15 ( V_34 , V_37 ) ;
F_15 ( V_35 , V_37 ) ;
V_41:
F_18 ( & V_40 ) ;
}
static struct V_46 * F_19 ( unsigned int V_5 )
{
struct V_46 * V_47 ;
if ( F_20 ( V_5 >= V_48 ) )
return NULL ;
F_21 ( & V_49 ) ;
V_47 = V_46 [ V_5 ] ;
if ( F_20 ( ! V_47 ) )
F_22 ( & V_49 ) ;
return V_47 ;
}
static void F_23 ( struct V_46 * V_47 )
__releases( V_49 )
{
F_22 ( & V_49 ) ;
}
int F_24 ( const struct V_50 * type , unsigned short V_5 )
{
struct V_46 * V_47 = F_19 ( V_5 ) ;
const struct V_50 * * V_51 ;
int V_52 = 0 ;
if ( F_20 ( V_47 == NULL ) )
return - V_53 ;
V_51 = V_47 -> V_54 ;
if ( F_25 ( V_51 [ type -> V_9 ] == NULL ) )
V_51 [ type -> V_9 ] = type ;
else
V_52 = - V_55 ;
F_23 ( V_47 ) ;
return V_52 ;
}
int F_26 ( const struct V_50 * type , unsigned short V_5 )
{
struct V_46 * V_47 = F_19 ( V_5 ) ;
const struct V_50 * * V_51 ;
int V_52 = 0 ;
if ( F_20 ( V_47 == NULL ) )
return - V_53 ;
V_51 = V_47 -> V_54 ;
if ( F_20 ( V_51 [ type -> V_9 ] != type ) )
V_52 = - V_56 ;
else
V_51 [ type -> V_9 ] = NULL ;
F_23 ( V_47 ) ;
return V_52 ;
}
static const struct V_50 * F_27 ( T_4 V_9 , unsigned short V_5 )
{
struct V_46 * V_47 ;
const struct V_50 * * V_51 ;
const struct V_50 * type ;
int V_57 = 0 ;
V_58:
V_47 = F_28 ( V_5 ) ;
if ( F_20 ( V_47 == NULL ) )
return NULL ;
V_51 = V_47 -> V_54 ;
type = V_51 [ V_9 ] ;
if ( F_20 ( type && ! F_29 ( type -> V_59 ) ) )
type = NULL ;
if ( ! type && ! V_57 ) {
F_30 ( V_47 ) ;
F_31 ( L_1 , V_5 , V_9 ) ;
V_57 = 1 ;
goto V_58;
}
F_30 ( V_47 ) ;
return type ;
}
static void F_32 ( const struct V_50 * type )
{
F_33 ( type -> V_59 ) ;
}
int F_34 ( struct V_60 * V_61 , int V_5 )
{
struct V_46 * V_47 ;
struct V_60 * * V_62 ;
int V_52 ;
if ( F_20 ( V_61 -> V_63 >= V_64 ) )
return - V_65 ;
V_47 = F_19 ( V_5 ) ;
if ( F_20 ( V_47 == NULL ) )
return - V_53 ;
V_52 = - V_55 ;
V_62 = V_47 -> V_66 ;
if ( V_62 [ V_61 -> V_63 ] )
goto V_67;
V_52 = - V_56 ;
if ( ! F_29 ( V_47 -> V_59 ) )
goto V_67;
V_61 -> V_47 = V_47 ;
V_62 [ V_61 -> V_63 ] = V_61 ;
V_52 = 0 ;
V_67:
F_23 ( V_47 ) ;
return V_52 ;
}
int F_35 ( struct V_60 * V_61 , int V_5 )
{
struct V_46 * V_47 ;
struct V_60 * * V_62 ;
int V_52 ;
if ( F_20 ( V_61 -> V_63 >= V_64 ) )
return - V_65 ;
V_47 = F_19 ( V_5 ) ;
if ( F_20 ( V_47 == NULL ) )
return - V_53 ;
V_52 = - V_56 ;
V_62 = V_47 -> V_66 ;
if ( F_25 ( V_62 [ V_61 -> V_63 ] == V_61 ) ) {
V_62 [ V_61 -> V_63 ] = NULL ;
F_33 ( V_61 -> V_47 -> V_59 ) ;
V_52 = 0 ;
}
F_23 ( V_47 ) ;
return V_52 ;
}
static struct V_60 * F_36 ( unsigned int V_63 , int V_5 )
{
struct V_46 * V_47 ;
struct V_60 * V_61 ;
int V_57 = 0 ;
if ( F_20 ( V_63 >= V_64 ) )
return NULL ;
V_58:
V_47 = F_28 ( V_5 ) ;
if ( F_20 ( V_47 == NULL ) )
return NULL ;
V_61 = V_47 -> V_66 [ V_63 ] ;
if ( F_20 ( V_61 && ! F_29 ( V_61 -> V_59 ) ) )
V_61 = NULL ;
if ( ! V_61 && ! V_57 ) {
F_30 ( V_47 ) ;
F_31 ( L_2 , V_5 , V_63 ) ;
V_57 = 1 ;
goto V_58;
}
F_30 ( V_47 ) ;
return V_61 ;
}
static void F_37 ( struct V_60 * V_61 )
{
F_33 ( V_61 -> V_59 ) ;
}
static void F_38 ( struct V_19 * V_20 )
{
F_39 ( & V_20 -> V_68 ) ;
F_40 ( & V_20 -> V_69 ) ;
F_41 ( V_20 -> V_70 ) ;
F_41 ( V_20 -> V_71 ) ;
F_41 ( V_20 -> V_72 ) ;
F_41 ( V_20 -> V_63 ) ;
F_41 ( V_20 -> V_73 ) ;
F_41 ( V_20 -> V_74 ) ;
F_41 ( V_20 -> V_75 ) ;
if ( V_20 -> V_76 )
F_37 ( V_20 -> V_76 ) ;
if ( V_20 -> V_77 )
F_37 ( V_20 -> V_77 ) ;
if ( V_20 -> V_78 )
F_37 ( V_20 -> V_78 ) ;
if ( V_20 -> type ) {
V_20 -> type -> V_79 ( V_20 ) ;
F_32 ( V_20 -> type ) ;
}
F_42 ( V_20 ) ;
F_41 ( V_20 ) ;
}
static void F_43 ( struct V_27 * V_28 )
{
struct V_1 * V_1 = F_12 ( V_28 , struct V_1 , V_6 . V_80 ) ;
struct V_19 * V_20 ;
struct V_16 * V_17 , * V_18 ;
struct V_10 V_81 ;
F_16 ( & V_82 ) ;
F_44 ( & V_1 -> V_6 . V_83 , & V_81 ) ;
F_17 ( & V_82 ) ;
F_8 (x, entry, tmp, &gc_list, gclist)
F_38 ( V_20 ) ;
F_45 ( & V_1 -> V_6 . V_84 ) ;
}
static inline unsigned long F_46 ( long V_85 )
{
if ( V_85 >= ( V_86 - 1 ) / V_87 )
return V_86 - 1 ;
else
return V_85 * V_87 ;
}
static enum V_88 F_47 ( struct V_89 * V_90 )
{
struct V_91 * V_92 = F_12 ( V_90 , struct V_91 , V_93 ) ;
struct V_19 * V_20 = F_12 ( V_92 , struct V_19 , V_68 ) ;
struct V_1 * V_1 = F_48 ( V_20 ) ;
unsigned long V_94 = F_49 () ;
long V_95 = V_96 ;
int V_97 = 0 ;
int V_52 = 0 ;
F_50 ( & V_20 -> V_98 ) ;
if ( V_20 -> V_99 . V_100 == V_101 )
goto V_67;
if ( V_20 -> V_99 . V_100 == V_102 )
goto V_103;
if ( V_20 -> V_104 . V_105 ) {
long V_106 = V_20 -> V_104 . V_105 +
V_20 -> V_107 . V_108 - V_94 ;
if ( V_106 <= 0 )
goto V_103;
if ( V_106 < V_95 )
V_95 = V_106 ;
}
if ( V_20 -> V_104 . V_109 ) {
long V_106 = V_20 -> V_104 . V_109 +
( V_20 -> V_107 . V_110 ? : V_94 ) - V_94 ;
if ( V_106 <= 0 )
goto V_103;
if ( V_106 < V_95 )
V_95 = V_106 ;
}
if ( V_20 -> V_99 . V_111 )
goto V_112;
if ( V_20 -> V_104 . V_113 ) {
long V_106 = V_20 -> V_104 . V_113 +
V_20 -> V_107 . V_108 - V_94 ;
if ( V_106 <= 0 )
V_97 = 1 ;
else if ( V_106 < V_95 )
V_95 = V_106 ;
}
if ( V_20 -> V_104 . V_114 ) {
long V_106 = V_20 -> V_104 . V_114 +
( V_20 -> V_107 . V_110 ? : V_94 ) - V_94 ;
if ( V_106 <= 0 )
V_97 = 1 ;
else if ( V_106 < V_95 )
V_95 = V_106 ;
}
V_20 -> V_99 . V_111 = V_97 ;
if ( V_97 )
F_51 ( V_20 , 0 , 0 ) ;
V_112:
if ( V_95 != V_96 ) {
F_52 ( & V_20 -> V_68 , F_53 ( V_95 , 0 ) , V_115 ) ;
}
goto V_67;
V_103:
if ( V_20 -> V_99 . V_100 == V_116 && V_20 -> V_22 . V_8 == 0 ) {
V_20 -> V_99 . V_100 = V_102 ;
F_45 ( & V_1 -> V_6 . V_84 ) ;
V_95 = 2 ;
goto V_112;
}
V_52 = F_54 ( V_20 ) ;
if ( ! V_52 && V_20 -> V_22 . V_8 )
F_51 ( V_20 , 1 , 0 ) ;
F_55 ( V_20 , V_52 ? 0 : 1 ,
F_56 ( V_117 ) ,
F_57 ( V_117 ) , 0 ) ;
V_67:
F_58 ( & V_20 -> V_98 ) ;
return V_118 ;
}
struct V_19 * F_59 ( struct V_1 * V_1 )
{
struct V_19 * V_20 ;
V_20 = F_60 ( sizeof( struct V_19 ) , V_119 ) ;
if ( V_20 ) {
F_61 ( & V_20 -> F_48 , V_1 ) ;
F_62 ( & V_20 -> V_120 , 1 ) ;
F_62 ( & V_20 -> V_121 , 0 ) ;
F_63 ( & V_20 -> V_99 . V_122 ) ;
F_64 ( & V_20 -> V_24 ) ;
F_64 ( & V_20 -> V_25 ) ;
F_64 ( & V_20 -> V_26 ) ;
F_65 ( & V_20 -> V_68 , F_47 , V_123 , V_124 ) ;
F_66 ( & V_20 -> V_69 , V_125 ,
( unsigned long ) V_20 ) ;
V_20 -> V_107 . V_108 = F_49 () ;
V_20 -> V_104 . V_126 = V_127 ;
V_20 -> V_104 . V_128 = V_127 ;
V_20 -> V_104 . V_129 = V_127 ;
V_20 -> V_104 . V_130 = V_127 ;
V_20 -> V_131 = 0 ;
V_20 -> V_132 = 0 ;
V_20 -> V_76 = NULL ;
V_20 -> V_77 = NULL ;
F_67 ( & V_20 -> V_98 ) ;
}
return V_20 ;
}
void F_68 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
F_69 ( V_20 -> V_99 . V_100 != V_101 ) ;
F_16 ( & V_82 ) ;
F_9 ( & V_20 -> V_133 , & V_1 -> V_6 . V_83 ) ;
F_17 ( & V_82 ) ;
F_70 ( & V_1 -> V_6 . V_80 ) ;
}
int F_54 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
int V_52 = - V_134 ;
if ( V_20 -> V_99 . V_100 != V_101 ) {
V_20 -> V_99 . V_100 = V_101 ;
F_50 ( & V_42 ) ;
F_71 ( & V_20 -> V_99 . V_122 ) ;
F_72 ( & V_20 -> V_24 ) ;
F_72 ( & V_20 -> V_25 ) ;
if ( V_20 -> V_22 . V_8 )
F_72 ( & V_20 -> V_26 ) ;
V_1 -> V_6 . V_135 -- ;
F_58 ( & V_42 ) ;
F_73 ( V_20 ) ;
V_52 = 0 ;
}
return V_52 ;
}
int F_74 ( struct V_19 * V_20 )
{
int V_52 ;
F_16 ( & V_20 -> V_98 ) ;
V_52 = F_54 ( V_20 ) ;
F_17 ( & V_20 -> V_98 ) ;
return V_52 ;
}
static inline int
F_75 ( struct V_1 * V_1 , T_4 V_9 , struct V_136 * V_137 )
{
int V_39 , V_52 = 0 ;
for ( V_39 = 0 ; V_39 <= V_1 -> V_6 . V_7 ; V_39 ++ ) {
struct V_16 * V_17 ;
struct V_19 * V_20 ;
F_76 (x, entry, net->xfrm.state_bydst+i, bydst) {
if ( F_77 ( V_20 -> V_22 . V_9 , V_9 ) &&
( V_52 = F_78 ( V_20 ) ) != 0 ) {
F_55 ( V_20 , 0 ,
V_137 -> V_138 ,
V_137 -> V_139 ,
V_137 -> V_140 ) ;
return V_52 ;
}
}
}
return V_52 ;
}
static inline int
F_75 ( struct V_1 * V_1 , T_4 V_9 , struct V_136 * V_137 )
{
return 0 ;
}
int F_79 ( struct V_1 * V_1 , T_4 V_9 , struct V_136 * V_137 )
{
int V_39 , V_52 = 0 , V_141 = 0 ;
F_16 ( & V_42 ) ;
V_52 = F_75 ( V_1 , V_9 , V_137 ) ;
if ( V_52 )
goto V_67;
V_52 = - V_134 ;
for ( V_39 = 0 ; V_39 <= V_1 -> V_6 . V_7 ; V_39 ++ ) {
struct V_16 * V_17 ;
struct V_19 * V_20 ;
V_142:
F_76 (x, entry, net->xfrm.state_bydst+i, bydst) {
if ( ! F_80 ( V_20 ) &&
F_77 ( V_20 -> V_22 . V_9 , V_9 ) ) {
F_81 ( V_20 ) ;
F_17 ( & V_42 ) ;
V_52 = F_74 ( V_20 ) ;
F_55 ( V_20 , V_52 ? 0 : 1 ,
V_137 -> V_138 ,
V_137 -> V_139 ,
V_137 -> V_140 ) ;
F_73 ( V_20 ) ;
if ( ! V_52 )
V_141 ++ ;
F_16 ( & V_42 ) ;
goto V_142;
}
}
}
if ( V_141 )
V_52 = 0 ;
V_67:
F_17 ( & V_42 ) ;
F_45 ( & V_1 -> V_6 . V_84 ) ;
return V_52 ;
}
void F_82 ( struct V_1 * V_1 , struct V_143 * V_144 )
{
F_16 ( & V_42 ) ;
V_144 -> V_145 = V_1 -> V_6 . V_135 ;
V_144 -> V_146 = V_1 -> V_6 . V_7 ;
V_144 -> V_147 = V_148 ;
F_17 ( & V_42 ) ;
}
static int
F_83 ( struct V_19 * V_20 , const struct V_149 * V_150 ,
const struct V_151 * V_152 ,
const T_1 * V_2 , const T_1 * V_3 ,
unsigned short V_5 )
{
struct V_46 * V_47 = F_28 ( V_5 ) ;
if ( ! V_47 )
return - 1 ;
V_47 -> V_153 ( & V_20 -> V_154 , V_150 ) ;
if ( V_5 != V_152 -> V_155 ) {
F_30 ( V_47 ) ;
V_47 = F_28 ( V_152 -> V_155 ) ;
if ( ! V_47 )
return - 1 ;
}
V_47 -> V_156 ( V_20 , V_152 , V_2 , V_3 ) ;
F_30 ( V_47 ) ;
return 0 ;
}
static struct V_19 * F_84 ( struct V_1 * V_1 , T_2 V_157 ,
const T_1 * V_2 ,
T_3 V_8 , T_4 V_9 ,
unsigned short V_5 )
{
unsigned int V_21 = F_5 ( V_1 , V_2 , V_8 , V_9 , V_5 ) ;
struct V_19 * V_20 ;
struct V_16 * V_17 ;
F_76 (x, entry, net->xfrm.state_byspi+h, byspi) {
if ( V_20 -> V_23 . V_5 != V_5 ||
V_20 -> V_22 . V_8 != V_8 ||
V_20 -> V_22 . V_9 != V_9 ||
F_85 ( & V_20 -> V_22 . V_2 , V_2 , V_5 ) )
continue;
if ( ( V_157 & V_20 -> V_157 . V_158 ) != V_20 -> V_157 . V_159 )
continue;
F_81 ( V_20 ) ;
return V_20 ;
}
return NULL ;
}
static struct V_19 * F_86 ( struct V_1 * V_1 , T_2 V_157 ,
const T_1 * V_2 ,
const T_1 * V_3 ,
T_4 V_9 , unsigned short V_5 )
{
unsigned int V_21 = F_3 ( V_1 , V_2 , V_3 , V_5 ) ;
struct V_19 * V_20 ;
struct V_16 * V_17 ;
F_76 (x, entry, net->xfrm.state_bysrc+h, bysrc) {
if ( V_20 -> V_23 . V_5 != V_5 ||
V_20 -> V_22 . V_9 != V_9 ||
F_85 ( & V_20 -> V_22 . V_2 , V_2 , V_5 ) ||
F_85 ( & V_20 -> V_23 . V_3 , V_3 , V_5 ) )
continue;
if ( ( V_157 & V_20 -> V_157 . V_158 ) != V_20 -> V_157 . V_159 )
continue;
F_81 ( V_20 ) ;
return V_20 ;
}
return NULL ;
}
static inline struct V_19 *
F_87 ( struct V_19 * V_20 , int V_160 , int V_5 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
T_2 V_157 = V_20 -> V_157 . V_159 & V_20 -> V_157 . V_158 ;
if ( V_160 )
return F_84 ( V_1 , V_157 , & V_20 -> V_22 . V_2 ,
V_20 -> V_22 . V_8 , V_20 -> V_22 . V_9 , V_5 ) ;
else
return F_86 ( V_1 , V_157 ,
& V_20 -> V_22 . V_2 ,
& V_20 -> V_23 . V_3 ,
V_20 -> V_22 . V_9 , V_5 ) ;
}
static void F_88 ( struct V_1 * V_1 , int V_161 )
{
if ( V_161 &&
( V_1 -> V_6 . V_7 + 1 ) < V_148 &&
V_1 -> V_6 . V_135 > V_1 -> V_6 . V_7 )
F_70 ( & V_1 -> V_6 . V_29 ) ;
}
static void F_89 ( struct V_162 * V_163 , struct V_19 * V_20 ,
const struct V_149 * V_150 , unsigned short V_5 ,
struct V_19 * * V_164 , int * V_165 ,
int * error )
{
if ( V_20 -> V_99 . V_100 == V_166 ) {
if ( ( V_20 -> V_154 . V_5 &&
! F_90 ( & V_20 -> V_154 , V_150 , V_20 -> V_154 . V_5 ) ) ||
! F_91 ( V_20 , V_163 , V_150 ) )
return;
if ( ! * V_164 ||
( * V_164 ) -> V_99 . V_111 > V_20 -> V_99 . V_111 ||
( ( * V_164 ) -> V_99 . V_111 == V_20 -> V_99 . V_111 &&
( * V_164 ) -> V_107 . V_108 < V_20 -> V_107 . V_108 ) )
* V_164 = V_20 ;
} else if ( V_20 -> V_99 . V_100 == V_116 ) {
* V_165 = 1 ;
} else if ( V_20 -> V_99 . V_100 == V_167 ||
V_20 -> V_99 . V_100 == V_102 ) {
if ( F_90 ( & V_20 -> V_154 , V_150 , V_20 -> V_154 . V_5 ) &&
F_91 ( V_20 , V_163 , V_150 ) )
* error = - V_134 ;
}
}
struct V_19 *
F_92 ( const T_1 * V_2 , const T_1 * V_3 ,
const struct V_149 * V_150 , struct V_151 * V_152 ,
struct V_162 * V_163 , int * V_52 ,
unsigned short V_5 )
{
static T_1 V_168 = { } ;
struct V_1 * V_1 = F_93 ( V_163 ) ;
unsigned int V_21 , V_169 ;
struct V_16 * V_17 ;
struct V_19 * V_20 , * V_170 , * V_171 ;
int V_172 = 0 ;
int error = 0 ;
struct V_19 * V_164 = NULL ;
T_2 V_157 = V_163 -> V_157 . V_159 & V_163 -> V_157 . V_158 ;
unsigned short V_155 = V_152 -> V_155 ;
V_171 = NULL ;
F_16 ( & V_42 ) ;
V_21 = F_1 ( V_1 , V_2 , V_3 , V_152 -> V_4 , V_155 ) ;
F_76 (x, entry, net->xfrm.state_bydst+h, bydst) {
if ( V_20 -> V_23 . V_5 == V_155 &&
V_20 -> V_23 . V_4 == V_152 -> V_4 &&
( V_157 & V_20 -> V_157 . V_158 ) == V_20 -> V_157 . V_159 &&
! ( V_20 -> V_23 . V_173 & V_174 ) &&
F_94 ( V_20 , V_2 , V_3 , V_155 ) &&
V_152 -> V_61 == V_20 -> V_23 . V_61 &&
V_152 -> V_22 . V_9 == V_20 -> V_22 . V_9 &&
( V_152 -> V_22 . V_8 == V_20 -> V_22 . V_8 || ! V_152 -> V_22 . V_8 ) )
F_89 ( V_163 , V_20 , V_150 , V_155 ,
& V_164 , & V_172 , & error ) ;
}
if ( V_164 )
goto V_175;
V_169 = F_1 ( V_1 , V_2 , & V_168 , V_152 -> V_4 , V_155 ) ;
F_76 (x, entry, net->xfrm.state_bydst+h_wildcard, bydst) {
if ( V_20 -> V_23 . V_5 == V_155 &&
V_20 -> V_23 . V_4 == V_152 -> V_4 &&
( V_157 & V_20 -> V_157 . V_158 ) == V_20 -> V_157 . V_159 &&
! ( V_20 -> V_23 . V_173 & V_174 ) &&
F_94 ( V_20 , V_2 , V_3 , V_155 ) &&
V_152 -> V_61 == V_20 -> V_23 . V_61 &&
V_152 -> V_22 . V_9 == V_20 -> V_22 . V_9 &&
( V_152 -> V_22 . V_8 == V_20 -> V_22 . V_8 || ! V_152 -> V_22 . V_8 ) )
F_89 ( V_163 , V_20 , V_150 , V_155 ,
& V_164 , & V_172 , & error ) ;
}
V_175:
V_20 = V_164 ;
if ( ! V_20 && ! error && ! V_172 ) {
if ( V_152 -> V_22 . V_8 &&
( V_170 = F_84 ( V_1 , V_157 , V_2 , V_152 -> V_22 . V_8 ,
V_152 -> V_22 . V_9 , V_155 ) ) != NULL ) {
V_171 = V_170 ;
error = - V_55 ;
goto V_67;
}
V_20 = F_59 ( V_1 ) ;
if ( V_20 == NULL ) {
error = - V_176 ;
goto V_67;
}
F_83 ( V_20 , V_150 , V_152 , V_2 , V_3 , V_5 ) ;
memcpy ( & V_20 -> V_157 , & V_163 -> V_157 , sizeof( V_20 -> V_157 ) ) ;
error = F_95 ( V_20 , V_163 -> V_177 , V_150 -> V_178 ) ;
if ( error ) {
V_20 -> V_99 . V_100 = V_101 ;
V_171 = V_20 ;
V_20 = NULL ;
goto V_67;
}
if ( F_96 ( V_20 , V_152 , V_163 ) == 0 ) {
V_20 -> V_99 . V_100 = V_116 ;
F_97 ( & V_20 -> V_99 . V_122 , & V_1 -> V_6 . V_179 ) ;
F_9 ( & V_20 -> V_24 , V_1 -> V_6 . V_43 + V_21 ) ;
V_21 = F_3 ( V_1 , V_2 , V_3 , V_155 ) ;
F_9 ( & V_20 -> V_25 , V_1 -> V_6 . V_44 + V_21 ) ;
if ( V_20 -> V_22 . V_8 ) {
V_21 = F_5 ( V_1 , & V_20 -> V_22 . V_2 , V_20 -> V_22 . V_8 , V_20 -> V_22 . V_9 , V_155 ) ;
F_9 ( & V_20 -> V_26 , V_1 -> V_6 . V_45 + V_21 ) ;
}
V_20 -> V_104 . V_105 = V_1 -> V_6 . V_180 ;
F_52 ( & V_20 -> V_68 , F_53 ( V_1 -> V_6 . V_180 , 0 ) , V_115 ) ;
V_1 -> V_6 . V_135 ++ ;
F_88 ( V_1 , V_20 -> V_24 . V_95 != NULL ) ;
} else {
V_20 -> V_99 . V_100 = V_101 ;
V_171 = V_20 ;
V_20 = NULL ;
error = - V_134 ;
}
}
V_67:
if ( V_20 )
F_81 ( V_20 ) ;
else
* V_52 = V_172 ? - V_181 : error ;
F_17 ( & V_42 ) ;
if ( V_171 )
F_73 ( V_171 ) ;
return V_20 ;
}
struct V_19 *
F_98 ( struct V_1 * V_1 , T_2 V_157 ,
T_1 * V_2 , T_1 * V_3 ,
unsigned short V_5 , T_4 V_61 , T_4 V_9 , T_2 V_4 )
{
unsigned int V_21 ;
struct V_19 * V_182 = NULL , * V_20 = NULL ;
struct V_16 * V_17 ;
F_50 ( & V_42 ) ;
V_21 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_76 (x, entry, net->xfrm.state_bydst+h, bydst) {
if ( V_20 -> V_23 . V_5 == V_5 &&
V_20 -> V_23 . V_4 == V_4 &&
( V_157 & V_20 -> V_157 . V_158 ) == V_20 -> V_157 . V_159 &&
! ( V_20 -> V_23 . V_173 & V_174 ) &&
F_94 ( V_20 , V_2 , V_3 , V_5 ) &&
V_61 == V_20 -> V_23 . V_61 &&
V_9 == V_20 -> V_22 . V_9 &&
V_20 -> V_99 . V_100 == V_166 ) {
V_182 = V_20 ;
break;
}
}
if ( V_182 )
F_81 ( V_182 ) ;
F_58 ( & V_42 ) ;
return V_182 ;
}
static void F_99 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
unsigned int V_21 ;
F_97 ( & V_20 -> V_99 . V_122 , & V_1 -> V_6 . V_179 ) ;
V_21 = F_1 ( V_1 , & V_20 -> V_22 . V_2 , & V_20 -> V_23 . V_3 ,
V_20 -> V_23 . V_4 , V_20 -> V_23 . V_5 ) ;
F_9 ( & V_20 -> V_24 , V_1 -> V_6 . V_43 + V_21 ) ;
V_21 = F_3 ( V_1 , & V_20 -> V_22 . V_2 , & V_20 -> V_23 . V_3 , V_20 -> V_23 . V_5 ) ;
F_9 ( & V_20 -> V_25 , V_1 -> V_6 . V_44 + V_21 ) ;
if ( V_20 -> V_22 . V_8 ) {
V_21 = F_5 ( V_1 , & V_20 -> V_22 . V_2 , V_20 -> V_22 . V_8 , V_20 -> V_22 . V_9 ,
V_20 -> V_23 . V_5 ) ;
F_9 ( & V_20 -> V_26 , V_1 -> V_6 . V_45 + V_21 ) ;
}
F_52 ( & V_20 -> V_68 , F_53 ( 1 , 0 ) , V_115 ) ;
if ( V_20 -> V_131 )
F_100 ( & V_20 -> V_69 , V_183 + V_20 -> V_131 ) ;
F_45 ( & V_1 -> V_6 . V_84 ) ;
V_1 -> V_6 . V_135 ++ ;
F_88 ( V_1 , V_20 -> V_24 . V_95 != NULL ) ;
}
static void F_101 ( struct V_19 * V_184 )
{
struct V_1 * V_1 = F_48 ( V_184 ) ;
unsigned short V_5 = V_184 -> V_23 . V_5 ;
T_2 V_4 = V_184 -> V_23 . V_4 ;
struct V_19 * V_20 ;
struct V_16 * V_17 ;
unsigned int V_21 ;
T_2 V_157 = V_184 -> V_157 . V_159 & V_184 -> V_157 . V_158 ;
V_21 = F_1 ( V_1 , & V_184 -> V_22 . V_2 , & V_184 -> V_23 . V_3 , V_4 , V_5 ) ;
F_76 (x, entry, net->xfrm.state_bydst+h, bydst) {
if ( V_20 -> V_23 . V_5 == V_5 &&
V_20 -> V_23 . V_4 == V_4 &&
( V_157 & V_20 -> V_157 . V_158 ) == V_20 -> V_157 . V_159 &&
! F_85 ( & V_20 -> V_22 . V_2 , & V_184 -> V_22 . V_2 , V_5 ) &&
! F_85 ( & V_20 -> V_23 . V_3 , & V_184 -> V_23 . V_3 , V_5 ) )
V_20 -> V_185 ++ ;
}
}
void F_102 ( struct V_19 * V_20 )
{
F_16 ( & V_42 ) ;
F_101 ( V_20 ) ;
F_99 ( V_20 ) ;
F_17 ( & V_42 ) ;
}
static struct V_19 * F_103 ( struct V_1 * V_1 , struct V_186 * V_158 ,
unsigned short V_5 , T_4 V_61 ,
T_2 V_4 , T_4 V_9 ,
const T_1 * V_2 ,
const T_1 * V_3 , int V_187 )
{
unsigned int V_21 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
struct V_16 * V_17 ;
struct V_19 * V_20 ;
T_2 V_157 = V_158 -> V_159 & V_158 -> V_158 ;
F_76 (x, entry, net->xfrm.state_bydst+h, bydst) {
if ( V_20 -> V_23 . V_4 != V_4 ||
V_20 -> V_23 . V_61 != V_61 ||
V_20 -> V_23 . V_5 != V_5 ||
V_20 -> V_99 . V_100 != V_116 ||
V_20 -> V_22 . V_8 != 0 ||
V_20 -> V_22 . V_9 != V_9 ||
( V_157 & V_20 -> V_157 . V_158 ) != V_20 -> V_157 . V_159 ||
F_85 ( & V_20 -> V_22 . V_2 , V_2 , V_5 ) ||
F_85 ( & V_20 -> V_23 . V_3 , V_3 , V_5 ) )
continue;
F_81 ( V_20 ) ;
return V_20 ;
}
if ( ! V_187 )
return NULL ;
V_20 = F_59 ( V_1 ) ;
if ( F_25 ( V_20 ) ) {
switch ( V_5 ) {
case V_188 :
V_20 -> V_154 . V_2 . V_189 = V_2 -> V_189 ;
V_20 -> V_154 . V_3 . V_189 = V_3 -> V_189 ;
V_20 -> V_154 . V_190 = 32 ;
V_20 -> V_154 . V_191 = 32 ;
V_20 -> V_23 . V_3 . V_189 = V_3 -> V_189 ;
V_20 -> V_22 . V_2 . V_189 = V_2 -> V_189 ;
break;
case V_192 :
F_104 ( (struct V_193 * ) V_20 -> V_154 . V_2 . V_194 ,
( const struct V_193 * ) V_2 ) ;
F_104 ( (struct V_193 * ) V_20 -> V_154 . V_3 . V_194 ,
( const struct V_193 * ) V_3 ) ;
V_20 -> V_154 . V_190 = 128 ;
V_20 -> V_154 . V_191 = 128 ;
F_104 ( (struct V_193 * ) V_20 -> V_23 . V_3 . V_194 ,
( const struct V_193 * ) V_3 ) ;
F_104 ( (struct V_193 * ) V_20 -> V_22 . V_2 . V_194 ,
( const struct V_193 * ) V_2 ) ;
break;
}
V_20 -> V_99 . V_100 = V_116 ;
V_20 -> V_22 . V_9 = V_9 ;
V_20 -> V_23 . V_5 = V_5 ;
V_20 -> V_23 . V_61 = V_61 ;
V_20 -> V_23 . V_4 = V_4 ;
V_20 -> V_157 . V_159 = V_158 -> V_159 ;
V_20 -> V_157 . V_158 = V_158 -> V_158 ;
V_20 -> V_104 . V_105 = V_1 -> V_6 . V_180 ;
F_81 ( V_20 ) ;
F_52 ( & V_20 -> V_68 , F_53 ( V_1 -> V_6 . V_180 , 0 ) , V_115 ) ;
F_97 ( & V_20 -> V_99 . V_122 , & V_1 -> V_6 . V_179 ) ;
F_9 ( & V_20 -> V_24 , V_1 -> V_6 . V_43 + V_21 ) ;
V_21 = F_3 ( V_1 , V_2 , V_3 , V_5 ) ;
F_9 ( & V_20 -> V_25 , V_1 -> V_6 . V_44 + V_21 ) ;
V_1 -> V_6 . V_135 ++ ;
F_88 ( V_1 , V_20 -> V_24 . V_95 != NULL ) ;
}
return V_20 ;
}
int F_105 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
struct V_19 * V_195 , * V_171 ;
int V_5 ;
int V_52 ;
T_2 V_157 = V_20 -> V_157 . V_159 & V_20 -> V_157 . V_158 ;
int V_160 = F_77 ( V_20 -> V_22 . V_9 , V_196 ) ;
V_5 = V_20 -> V_23 . V_5 ;
V_171 = NULL ;
F_16 ( & V_42 ) ;
V_195 = F_87 ( V_20 , V_160 , V_5 ) ;
if ( V_195 ) {
V_171 = V_195 ;
V_195 = NULL ;
V_52 = - V_55 ;
goto V_67;
}
if ( V_160 && V_20 -> V_99 . V_197 ) {
V_195 = F_106 ( V_1 , V_157 , V_20 -> V_99 . V_197 ) ;
if ( V_195 && ( ( V_195 -> V_22 . V_9 != V_20 -> V_22 . V_9 ) ||
F_85 ( & V_195 -> V_22 . V_2 , & V_20 -> V_22 . V_2 , V_5 ) ) ) {
V_171 = V_195 ;
V_195 = NULL ;
}
}
if ( V_160 && ! V_195 )
V_195 = F_103 ( V_1 , & V_20 -> V_157 , V_5 , V_20 -> V_23 . V_61 ,
V_20 -> V_23 . V_4 , V_20 -> V_22 . V_9 ,
& V_20 -> V_22 . V_2 , & V_20 -> V_23 . V_3 , 0 ) ;
F_101 ( V_20 ) ;
F_99 ( V_20 ) ;
V_52 = 0 ;
V_67:
F_17 ( & V_42 ) ;
if ( V_195 ) {
F_74 ( V_195 ) ;
F_73 ( V_195 ) ;
}
if ( V_171 )
F_73 ( V_171 ) ;
return V_52 ;
}
static struct V_19 * F_107 ( struct V_19 * V_198 , int * V_199 )
{
struct V_1 * V_1 = F_48 ( V_198 ) ;
int V_52 = - V_176 ;
struct V_19 * V_20 = F_59 ( V_1 ) ;
if ( ! V_20 )
goto V_67;
memcpy ( & V_20 -> V_22 , & V_198 -> V_22 , sizeof( V_20 -> V_22 ) ) ;
memcpy ( & V_20 -> V_154 , & V_198 -> V_154 , sizeof( V_20 -> V_154 ) ) ;
memcpy ( & V_20 -> V_104 , & V_198 -> V_104 , sizeof( V_20 -> V_104 ) ) ;
V_20 -> V_23 . V_61 = V_198 -> V_23 . V_61 ;
V_20 -> V_23 . V_200 = V_198 -> V_23 . V_200 ;
V_20 -> V_23 . V_4 = V_198 -> V_23 . V_4 ;
V_20 -> V_23 . V_5 = V_198 -> V_23 . V_5 ;
V_20 -> V_23 . V_3 = V_198 -> V_23 . V_3 ;
if ( V_198 -> V_70 ) {
V_20 -> V_70 = F_108 ( V_198 -> V_70 ) ;
if ( ! V_20 -> V_70 )
goto error;
}
V_20 -> V_23 . V_201 = V_198 -> V_23 . V_201 ;
if ( V_198 -> V_71 ) {
V_20 -> V_71 = F_109 ( V_198 -> V_71 ) ;
if ( ! V_20 -> V_71 )
goto error;
}
V_20 -> V_23 . V_202 = V_198 -> V_23 . V_202 ;
if ( V_198 -> V_72 ) {
V_20 -> V_72 = F_109 ( V_198 -> V_72 ) ;
if ( ! V_20 -> V_72 )
goto error;
}
V_20 -> V_23 . V_203 = V_198 -> V_23 . V_203 ;
if ( V_198 -> V_63 ) {
V_20 -> V_63 = F_110 ( V_198 -> V_63 , sizeof( * V_20 -> V_63 ) , V_204 ) ;
if ( ! V_20 -> V_63 )
goto error;
}
if ( V_198 -> V_73 ) {
V_20 -> V_73 = F_110 ( V_198 -> V_73 , sizeof( * V_20 -> V_73 ) ,
V_204 ) ;
if ( ! V_20 -> V_73 )
goto error;
}
if ( V_198 -> V_74 ) {
V_52 = F_111 ( V_20 , V_198 ) ;
if ( V_52 )
goto error;
}
memcpy ( & V_20 -> V_157 , & V_198 -> V_157 , sizeof( V_20 -> V_157 ) ) ;
V_52 = F_112 ( V_20 ) ;
if ( V_52 )
goto error;
V_20 -> V_23 . V_173 = V_198 -> V_23 . V_173 ;
V_20 -> V_107 . V_108 = V_198 -> V_107 . V_108 ;
V_20 -> V_99 . V_100 = V_198 -> V_99 . V_100 ;
V_20 -> V_99 . V_197 = V_198 -> V_99 . V_197 ;
return V_20 ;
error:
F_73 ( V_20 ) ;
V_67:
if ( V_199 )
* V_199 = V_52 ;
return NULL ;
}
struct V_19 * F_113 ( struct V_205 * V_158 )
{
unsigned int V_21 ;
struct V_19 * V_20 ;
struct V_16 * V_17 ;
if ( V_158 -> V_4 ) {
V_21 = F_1 ( & V_206 , & V_158 -> V_207 , & V_158 -> V_208 ,
V_158 -> V_4 , V_158 -> V_209 ) ;
F_76 (x, entry, init_net.xfrm.state_bydst+h, bydst) {
if ( V_20 -> V_23 . V_61 != V_158 -> V_61 ||
V_20 -> V_22 . V_9 != V_158 -> V_9 )
continue;
if ( V_158 -> V_4 && V_20 -> V_23 . V_4 != V_158 -> V_4 )
continue;
if ( F_85 ( & V_20 -> V_22 . V_2 , & V_158 -> V_207 ,
V_158 -> V_209 ) ||
F_85 ( & V_20 -> V_23 . V_3 , & V_158 -> V_208 ,
V_158 -> V_209 ) )
continue;
F_81 ( V_20 ) ;
return V_20 ;
}
} else {
V_21 = F_3 ( & V_206 , & V_158 -> V_207 , & V_158 -> V_208 ,
V_158 -> V_209 ) ;
F_76 (x, entry, init_net.xfrm.state_bysrc+h, bysrc) {
if ( V_20 -> V_23 . V_61 != V_158 -> V_61 ||
V_20 -> V_22 . V_9 != V_158 -> V_9 )
continue;
if ( F_85 ( & V_20 -> V_22 . V_2 , & V_158 -> V_207 ,
V_158 -> V_209 ) ||
F_85 ( & V_20 -> V_23 . V_3 , & V_158 -> V_208 ,
V_158 -> V_209 ) )
continue;
F_81 ( V_20 ) ;
return V_20 ;
}
}
return NULL ;
}
struct V_19 * F_114 ( struct V_19 * V_20 ,
struct V_205 * V_158 )
{
struct V_19 * V_210 ;
int V_52 ;
V_210 = F_107 ( V_20 , & V_52 ) ;
if ( ! V_210 )
return NULL ;
memcpy ( & V_210 -> V_22 . V_2 , & V_158 -> V_211 , sizeof( V_210 -> V_22 . V_2 ) ) ;
memcpy ( & V_210 -> V_23 . V_3 , & V_158 -> V_212 , sizeof( V_210 -> V_23 . V_3 ) ) ;
if ( ! F_85 ( & V_20 -> V_22 . V_2 , & V_158 -> V_211 , V_158 -> V_213 ) ) {
F_102 ( V_210 ) ;
} else {
if ( ( V_52 = F_105 ( V_210 ) ) < 0 )
goto error;
}
return V_210 ;
error:
F_73 ( V_210 ) ;
return NULL ;
}
int F_115 ( struct V_19 * V_20 )
{
struct V_19 * V_195 , * V_171 ;
int V_52 ;
int V_160 = F_77 ( V_20 -> V_22 . V_9 , V_196 ) ;
V_171 = NULL ;
F_16 ( & V_42 ) ;
V_195 = F_87 ( V_20 , V_160 , V_20 -> V_23 . V_5 ) ;
V_52 = - V_134 ;
if ( ! V_195 )
goto V_67;
if ( F_80 ( V_195 ) ) {
V_171 = V_195 ;
V_52 = - V_55 ;
goto V_67;
}
if ( V_195 -> V_99 . V_100 == V_116 ) {
F_99 ( V_20 ) ;
V_20 = NULL ;
}
V_52 = 0 ;
V_67:
F_17 ( & V_42 ) ;
if ( V_171 )
F_73 ( V_171 ) ;
if ( V_52 )
return V_52 ;
if ( ! V_20 ) {
F_74 ( V_195 ) ;
F_73 ( V_195 ) ;
return 0 ;
}
V_52 = - V_65 ;
F_16 ( & V_195 -> V_98 ) ;
if ( F_25 ( V_195 -> V_99 . V_100 == V_166 ) ) {
if ( V_20 -> V_63 && V_195 -> V_63 )
memcpy ( V_195 -> V_63 , V_20 -> V_63 , sizeof( * V_195 -> V_63 ) ) ;
if ( V_20 -> V_73 && V_195 -> V_73 ) {
memcpy ( V_195 -> V_73 , V_20 -> V_73 , sizeof( * V_195 -> V_73 ) ) ;
}
if ( ! V_160 && memcmp ( & V_195 -> V_154 , & V_20 -> V_154 , sizeof( V_195 -> V_154 ) ) )
memcpy ( & V_195 -> V_154 , & V_20 -> V_154 , sizeof( V_195 -> V_154 ) ) ;
memcpy ( & V_195 -> V_104 , & V_20 -> V_104 , sizeof( V_195 -> V_104 ) ) ;
V_195 -> V_99 . V_111 = 0 ;
F_52 ( & V_195 -> V_68 , F_53 ( 1 , 0 ) , V_115 ) ;
if ( V_195 -> V_107 . V_110 )
F_116 ( V_195 ) ;
V_52 = 0 ;
V_20 -> V_99 . V_100 = V_101 ;
F_117 ( V_20 ) ;
}
F_17 ( & V_195 -> V_98 ) ;
F_73 ( V_195 ) ;
return V_52 ;
}
int F_116 ( struct V_19 * V_20 )
{
if ( ! V_20 -> V_107 . V_110 )
V_20 -> V_107 . V_110 = F_49 () ;
if ( V_20 -> V_99 . V_100 != V_166 )
return - V_65 ;
if ( V_20 -> V_107 . V_214 >= V_20 -> V_104 . V_129 ||
V_20 -> V_107 . V_215 >= V_20 -> V_104 . V_130 ) {
V_20 -> V_99 . V_100 = V_102 ;
F_52 ( & V_20 -> V_68 , F_53 ( 0 , 0 ) , V_115 ) ;
return - V_65 ;
}
if ( ! V_20 -> V_99 . V_111 &&
( V_20 -> V_107 . V_214 >= V_20 -> V_104 . V_126 ||
V_20 -> V_107 . V_215 >= V_20 -> V_104 . V_128 ) ) {
V_20 -> V_99 . V_111 = 1 ;
F_51 ( V_20 , 0 , 0 ) ;
}
return 0 ;
}
struct V_19 *
F_118 ( struct V_1 * V_1 , T_2 V_157 , const T_1 * V_2 , T_3 V_8 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_19 * V_20 ;
F_16 ( & V_42 ) ;
V_20 = F_84 ( V_1 , V_157 , V_2 , V_8 , V_9 , V_5 ) ;
F_17 ( & V_42 ) ;
return V_20 ;
}
struct V_19 *
F_119 ( struct V_1 * V_1 , T_2 V_157 ,
const T_1 * V_2 , const T_1 * V_3 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_19 * V_20 ;
F_16 ( & V_42 ) ;
V_20 = F_86 ( V_1 , V_157 , V_2 , V_3 , V_9 , V_5 ) ;
F_17 ( & V_42 ) ;
return V_20 ;
}
struct V_19 *
F_120 ( struct V_1 * V_1 , struct V_186 * V_157 , T_4 V_61 , T_2 V_4 , T_4 V_9 ,
const T_1 * V_2 , const T_1 * V_3 ,
int V_187 , unsigned short V_5 )
{
struct V_19 * V_20 ;
F_16 ( & V_42 ) ;
V_20 = F_103 ( V_1 , V_157 , V_5 , V_61 , V_4 , V_9 , V_2 , V_3 , V_187 ) ;
F_17 ( & V_42 ) ;
return V_20 ;
}
int
F_121 ( struct V_151 * * V_216 , struct V_151 * * V_217 , int V_218 ,
unsigned short V_5 )
{
int V_52 = 0 ;
struct V_46 * V_47 = F_28 ( V_5 ) ;
if ( ! V_47 )
return - V_53 ;
F_16 ( & V_42 ) ;
if ( V_47 -> V_219 )
V_52 = V_47 -> V_219 ( V_216 , V_217 , V_218 ) ;
F_17 ( & V_42 ) ;
F_30 ( V_47 ) ;
return V_52 ;
}
int
F_122 ( struct V_19 * * V_216 , struct V_19 * * V_217 , int V_218 ,
unsigned short V_5 )
{
int V_52 = 0 ;
struct V_46 * V_47 = F_28 ( V_5 ) ;
if ( ! V_47 )
return - V_53 ;
F_16 ( & V_42 ) ;
if ( V_47 -> V_220 )
V_52 = V_47 -> V_220 ( V_216 , V_217 , V_218 ) ;
F_17 ( & V_42 ) ;
F_30 ( V_47 ) ;
return V_52 ;
}
static struct V_19 * F_106 ( struct V_1 * V_1 , T_2 V_157 , T_2 V_197 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 <= V_1 -> V_6 . V_7 ; V_39 ++ ) {
struct V_16 * V_17 ;
struct V_19 * V_20 ;
F_76 (x, entry, net->xfrm.state_bydst+i, bydst) {
if ( V_20 -> V_99 . V_197 == V_197 &&
( V_157 & V_20 -> V_157 . V_158 ) == V_20 -> V_157 . V_159 &&
V_20 -> V_99 . V_100 == V_116 ) {
F_81 ( V_20 ) ;
return V_20 ;
}
}
}
return NULL ;
}
struct V_19 * F_123 ( struct V_1 * V_1 , T_2 V_157 , T_2 V_197 )
{
struct V_19 * V_20 ;
F_16 ( & V_42 ) ;
V_20 = F_106 ( V_1 , V_157 , V_197 ) ;
F_17 ( & V_42 ) ;
return V_20 ;
}
T_2 F_124 ( void )
{
T_2 V_221 ;
static T_5 V_222 ;
do {
V_221 = F_125 ( & V_222 ) ;
} while ( ! V_221 );
return V_221 ;
}
int F_126 ( struct V_19 * V_20 , T_2 V_223 , T_2 V_224 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
unsigned int V_21 ;
struct V_19 * V_170 ;
int V_52 = - V_56 ;
T_3 V_225 = F_127 ( V_223 ) ;
T_3 V_226 = F_127 ( V_224 ) ;
T_2 V_157 = V_20 -> V_157 . V_159 & V_20 -> V_157 . V_158 ;
F_16 ( & V_20 -> V_98 ) ;
if ( V_20 -> V_99 . V_100 == V_101 )
goto V_227;
V_52 = 0 ;
if ( V_20 -> V_22 . V_8 )
goto V_227;
V_52 = - V_56 ;
if ( V_225 == V_226 ) {
V_170 = F_118 ( V_1 , V_157 , & V_20 -> V_22 . V_2 , V_225 , V_20 -> V_22 . V_9 , V_20 -> V_23 . V_5 ) ;
if ( V_170 ) {
F_73 ( V_170 ) ;
goto V_227;
}
V_20 -> V_22 . V_8 = V_225 ;
} else {
T_2 V_8 = 0 ;
for ( V_21 = 0 ; V_21 < V_224 - V_223 + 1 ; V_21 ++ ) {
V_8 = V_223 + F_128 () % ( V_224 - V_223 + 1 ) ;
V_170 = F_118 ( V_1 , V_157 , & V_20 -> V_22 . V_2 , F_127 ( V_8 ) , V_20 -> V_22 . V_9 , V_20 -> V_23 . V_5 ) ;
if ( V_170 == NULL ) {
V_20 -> V_22 . V_8 = F_127 ( V_8 ) ;
break;
}
F_73 ( V_170 ) ;
}
}
if ( V_20 -> V_22 . V_8 ) {
F_16 ( & V_42 ) ;
V_21 = F_5 ( V_1 , & V_20 -> V_22 . V_2 , V_20 -> V_22 . V_8 , V_20 -> V_22 . V_9 , V_20 -> V_23 . V_5 ) ;
F_9 ( & V_20 -> V_26 , V_1 -> V_6 . V_45 + V_21 ) ;
F_17 ( & V_42 ) ;
V_52 = 0 ;
}
V_227:
F_17 ( & V_20 -> V_98 ) ;
return V_52 ;
}
int F_129 ( struct V_1 * V_1 , struct F_129 * V_228 ,
int (* F_130)( struct V_19 * , int , void * ) ,
void * V_229 )
{
struct V_19 * V_100 ;
struct F_129 * V_20 ;
int V_52 = 0 ;
if ( V_228 -> V_197 != 0 && F_131 ( & V_228 -> V_122 ) )
return 0 ;
F_16 ( & V_42 ) ;
if ( F_131 ( & V_228 -> V_122 ) )
V_20 = F_132 ( & V_1 -> V_6 . V_179 , struct F_129 , V_122 ) ;
else
V_20 = F_133 ( & V_228 -> V_122 , struct F_129 , V_122 ) ;
F_134 (x, &net->xfrm.state_all, all) {
if ( V_20 -> V_100 == V_101 )
continue;
V_100 = F_12 ( V_20 , struct V_19 , V_99 ) ;
if ( ! F_77 ( V_100 -> V_22 . V_9 , V_228 -> V_9 ) )
continue;
V_52 = F_130 ( V_100 , V_228 -> V_197 , V_229 ) ;
if ( V_52 ) {
F_135 ( & V_228 -> V_122 , & V_20 -> V_122 ) ;
goto V_67;
}
V_228 -> V_197 ++ ;
}
if ( V_228 -> V_197 == 0 ) {
V_52 = - V_56 ;
goto V_67;
}
F_136 ( & V_228 -> V_122 ) ;
V_67:
F_17 ( & V_42 ) ;
return V_52 ;
}
void F_137 ( struct F_129 * V_228 , T_4 V_9 )
{
F_63 ( & V_228 -> V_122 ) ;
V_228 -> V_9 = V_9 ;
V_228 -> V_100 = V_101 ;
V_228 -> V_197 = 0 ;
}
void F_138 ( struct F_129 * V_228 )
{
if ( F_131 ( & V_228 -> V_122 ) )
return;
F_16 ( & V_42 ) ;
F_71 ( & V_228 -> V_122 ) ;
F_17 ( & V_42 ) ;
}
static void V_125 ( unsigned long V_229 )
{
struct V_19 * V_20 = (struct V_19 * ) V_229 ;
F_50 ( & V_20 -> V_98 ) ;
if ( V_20 -> V_99 . V_100 == V_166 ) {
if ( F_139 ( F_48 ( V_20 ) ) )
V_20 -> V_230 -> V_231 ( V_20 , V_232 ) ;
else
V_20 -> V_233 |= V_234 ;
}
F_58 ( & V_20 -> V_98 ) ;
}
void F_140 ( struct V_162 * V_235 , int V_236 , const struct V_237 * V_238 )
{
struct V_239 * V_99 ;
F_141 ( & V_240 ) ;
F_142 (km, &xfrm_km_list, list)
if ( V_99 -> V_241 )
V_99 -> V_241 ( V_235 , V_236 , V_238 ) ;
F_143 ( & V_240 ) ;
}
void F_144 ( struct V_19 * V_20 , const struct V_237 * V_238 )
{
struct V_239 * V_99 ;
F_141 ( & V_240 ) ;
F_142 (km, &xfrm_km_list, list)
if ( V_99 -> V_231 )
V_99 -> V_231 ( V_20 , V_238 ) ;
F_143 ( & V_240 ) ;
}
void F_51 ( struct V_19 * V_20 , int V_242 , T_2 V_243 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
struct V_237 V_238 ;
V_238 . V_229 . V_242 = V_242 ;
V_238 . V_243 = V_243 ;
V_238 . V_244 = V_245 ;
F_144 ( V_20 , & V_238 ) ;
if ( V_242 )
F_45 ( & V_1 -> V_6 . V_84 ) ;
}
int F_96 ( struct V_19 * V_20 , struct V_151 * V_246 , struct V_162 * V_163 )
{
int V_52 = - V_65 , V_247 ;
struct V_239 * V_99 ;
F_141 ( & V_240 ) ;
F_142 (km, &xfrm_km_list, list) {
V_247 = V_99 -> V_248 ( V_20 , V_246 , V_163 , V_249 ) ;
if ( ! V_247 )
V_52 = V_247 ;
}
F_143 ( & V_240 ) ;
return V_52 ;
}
int F_145 ( struct V_19 * V_20 , T_1 * V_250 , T_6 V_251 )
{
int V_52 = - V_65 ;
struct V_239 * V_99 ;
F_141 ( & V_240 ) ;
F_142 (km, &xfrm_km_list, list) {
if ( V_99 -> V_252 )
V_52 = V_99 -> V_252 ( V_20 , V_250 , V_251 ) ;
if ( ! V_52 )
break;
}
F_143 ( & V_240 ) ;
return V_52 ;
}
void F_146 ( struct V_162 * V_163 , int V_236 , int V_242 , T_2 V_243 )
{
struct V_1 * V_1 = F_93 ( V_163 ) ;
struct V_237 V_238 ;
V_238 . V_229 . V_242 = V_242 ;
V_238 . V_243 = V_243 ;
V_238 . V_244 = V_253 ;
F_140 ( V_163 , V_236 , & V_238 ) ;
if ( V_242 )
F_45 ( & V_1 -> V_6 . V_84 ) ;
}
int F_147 ( const struct V_254 * V_154 , T_4 V_236 , T_4 type ,
const struct V_205 * V_158 , int V_255 ,
const struct V_256 * V_257 )
{
int V_52 = - V_65 ;
int V_258 ;
struct V_239 * V_99 ;
F_141 ( & V_240 ) ;
F_142 (km, &xfrm_km_list, list) {
if ( V_99 -> V_259 ) {
V_258 = V_99 -> V_259 ( V_154 , V_236 , type , V_158 , V_255 , V_257 ) ;
if ( ! V_258 )
V_52 = V_258 ;
}
}
F_143 ( & V_240 ) ;
return V_52 ;
}
int F_148 ( struct V_1 * V_1 , T_4 V_9 , struct V_254 * V_154 , T_1 * V_260 )
{
int V_52 = - V_65 ;
int V_258 ;
struct V_239 * V_99 ;
F_141 ( & V_240 ) ;
F_142 (km, &xfrm_km_list, list) {
if ( V_99 -> V_261 ) {
V_258 = V_99 -> V_261 ( V_1 , V_9 , V_154 , V_260 ) ;
if ( ! V_258 )
V_52 = V_258 ;
}
}
F_143 ( & V_240 ) ;
return V_52 ;
}
int F_149 ( struct V_262 * V_263 , int V_264 , T_4 T_7 * V_265 , int V_266 )
{
int V_52 ;
T_4 * V_229 ;
struct V_239 * V_99 ;
struct V_162 * V_163 = NULL ;
if ( V_266 <= 0 || V_266 > V_267 )
return - V_268 ;
V_229 = F_150 ( V_266 , V_204 ) ;
if ( ! V_229 )
return - V_176 ;
V_52 = - V_269 ;
if ( F_151 ( V_229 , V_265 , V_266 ) )
goto V_67;
V_52 = - V_65 ;
F_141 ( & V_240 ) ;
F_142 (km, &xfrm_km_list, list) {
V_163 = V_99 -> V_270 ( V_263 , V_264 , V_229 ,
V_266 , & V_52 ) ;
if ( V_52 >= 0 )
break;
}
F_143 ( & V_240 ) ;
if ( V_52 >= 0 ) {
F_152 ( V_263 , V_52 , V_163 ) ;
F_153 ( V_163 ) ;
V_52 = 0 ;
}
V_67:
F_41 ( V_229 ) ;
return V_52 ;
}
int F_154 ( struct V_239 * V_99 )
{
F_21 ( & V_240 ) ;
F_155 ( & V_99 -> V_11 , & V_271 ) ;
F_22 ( & V_240 ) ;
return 0 ;
}
int F_156 ( struct V_239 * V_99 )
{
F_21 ( & V_240 ) ;
F_71 ( & V_99 -> V_11 ) ;
F_22 ( & V_240 ) ;
return 0 ;
}
int F_157 ( struct V_46 * V_47 )
{
int V_52 = 0 ;
if ( F_20 ( V_47 == NULL ) )
return - V_65 ;
if ( F_20 ( V_47 -> V_5 >= V_48 ) )
return - V_53 ;
F_21 ( & V_49 ) ;
if ( F_20 ( V_46 [ V_47 -> V_5 ] != NULL ) )
V_52 = - V_272 ;
else
V_46 [ V_47 -> V_5 ] = V_47 ;
F_22 ( & V_49 ) ;
return V_52 ;
}
int F_158 ( struct V_46 * V_47 )
{
int V_52 = 0 ;
if ( F_20 ( V_47 == NULL ) )
return - V_65 ;
if ( F_20 ( V_47 -> V_5 >= V_48 ) )
return - V_53 ;
F_21 ( & V_49 ) ;
if ( F_25 ( V_46 [ V_47 -> V_5 ] != NULL ) ) {
if ( F_20 ( V_46 [ V_47 -> V_5 ] != V_47 ) )
V_52 = - V_65 ;
else
V_46 [ V_47 -> V_5 ] = NULL ;
}
F_22 ( & V_49 ) ;
return V_52 ;
}
static struct V_46 * F_28 ( unsigned int V_5 )
{
struct V_46 * V_47 ;
if ( F_20 ( V_5 >= V_48 ) )
return NULL ;
F_141 ( & V_49 ) ;
V_47 = V_46 [ V_5 ] ;
if ( F_20 ( ! V_47 ) )
F_143 ( & V_49 ) ;
return V_47 ;
}
static void F_30 ( struct V_46 * V_47 )
__releases( V_49 )
{
F_143 ( & V_49 ) ;
}
void F_159 ( struct V_19 * V_20 )
{
if ( V_20 -> V_273 ) {
struct V_19 * V_246 = V_20 -> V_273 ;
if ( F_160 ( & V_246 -> V_121 ) == 2 )
F_74 ( V_246 ) ;
F_161 ( & V_246 -> V_121 ) ;
F_73 ( V_246 ) ;
V_20 -> V_273 = NULL ;
}
}
int F_162 ( struct V_19 * V_20 , int V_274 )
{
int V_221 ;
F_16 ( & V_20 -> V_98 ) ;
if ( V_20 -> V_99 . V_100 == V_166 &&
V_20 -> type && V_20 -> type -> V_275 )
V_221 = V_20 -> type -> V_275 ( V_20 , V_274 ) ;
else
V_221 = V_274 - V_20 -> V_23 . V_276 ;
F_17 ( & V_20 -> V_98 ) ;
return V_221 ;
}
int F_163 ( struct V_19 * V_20 , bool V_277 )
{
struct V_46 * V_47 ;
struct V_60 * V_76 ;
int V_5 = V_20 -> V_23 . V_5 ;
int V_52 ;
V_52 = - V_53 ;
V_47 = F_28 ( V_5 ) ;
if ( ! V_47 )
goto error;
V_52 = 0 ;
if ( V_47 -> V_278 )
V_52 = V_47 -> V_278 ( V_20 ) ;
F_30 ( V_47 ) ;
if ( V_52 )
goto error;
V_52 = - V_279 ;
if ( V_20 -> V_154 . V_5 != V_280 ) {
V_76 = F_36 ( V_20 -> V_23 . V_61 , V_20 -> V_154 . V_5 ) ;
if ( V_76 == NULL )
goto error;
if ( ! ( V_76 -> V_173 & V_281 ) &&
V_5 != V_20 -> V_154 . V_5 ) {
F_37 ( V_76 ) ;
goto error;
}
V_20 -> V_76 = V_76 ;
} else {
struct V_60 * V_77 ;
int V_282 = V_188 ;
V_76 = F_36 ( V_20 -> V_23 . V_61 , V_20 -> V_23 . V_5 ) ;
if ( V_76 == NULL )
goto error;
if ( ! ( V_76 -> V_173 & V_281 ) ) {
F_37 ( V_76 ) ;
goto error;
}
V_20 -> V_76 = V_76 ;
if ( V_20 -> V_23 . V_5 == V_188 )
V_282 = V_192 ;
V_77 = F_36 ( V_20 -> V_23 . V_61 , V_282 ) ;
if ( V_77 ) {
if ( V_77 -> V_173 & V_281 )
V_20 -> V_77 = V_77 ;
else
F_37 ( V_77 ) ;
}
}
V_20 -> type = F_27 ( V_20 -> V_22 . V_9 , V_5 ) ;
if ( V_20 -> type == NULL )
goto error;
V_52 = V_20 -> type -> V_283 ( V_20 ) ;
if ( V_52 )
goto error;
V_20 -> V_78 = F_36 ( V_20 -> V_23 . V_61 , V_5 ) ;
if ( V_20 -> V_78 == NULL )
goto error;
if ( V_277 ) {
V_52 = F_164 ( V_20 ) ;
if ( V_52 )
goto error;
}
V_20 -> V_99 . V_100 = V_166 ;
error:
return V_52 ;
}
int F_112 ( struct V_19 * V_20 )
{
return F_163 ( V_20 , true ) ;
}
int T_8 F_165 ( struct V_1 * V_1 )
{
unsigned int V_284 ;
F_63 ( & V_1 -> V_6 . V_179 ) ;
V_284 = sizeof( struct V_10 ) * 8 ;
V_1 -> V_6 . V_43 = F_14 ( V_284 ) ;
if ( ! V_1 -> V_6 . V_43 )
goto V_285;
V_1 -> V_6 . V_44 = F_14 ( V_284 ) ;
if ( ! V_1 -> V_6 . V_44 )
goto V_286;
V_1 -> V_6 . V_45 = F_14 ( V_284 ) ;
if ( ! V_1 -> V_6 . V_45 )
goto V_287;
V_1 -> V_6 . V_7 = ( ( V_284 / sizeof( struct V_10 ) ) - 1 ) ;
V_1 -> V_6 . V_135 = 0 ;
F_166 ( & V_1 -> V_6 . V_29 , F_11 ) ;
F_167 ( & V_1 -> V_6 . V_83 ) ;
F_166 ( & V_1 -> V_6 . V_80 , F_43 ) ;
F_168 ( & V_1 -> V_6 . V_84 ) ;
return 0 ;
V_287:
F_15 ( V_1 -> V_6 . V_44 , V_284 ) ;
V_286:
F_15 ( V_1 -> V_6 . V_43 , V_284 ) ;
V_285:
return - V_176 ;
}
void F_169 ( struct V_1 * V_1 )
{
struct V_136 V_137 ;
unsigned int V_284 ;
F_170 ( & V_1 -> V_6 . V_29 ) ;
V_137 . V_138 = - 1 ;
V_137 . V_139 = - 1 ;
V_137 . V_140 = 0 ;
F_79 ( V_1 , V_196 , & V_137 ) ;
F_170 ( & V_1 -> V_6 . V_80 ) ;
F_69 ( ! F_131 ( & V_1 -> V_6 . V_179 ) ) ;
V_284 = ( V_1 -> V_6 . V_7 + 1 ) * sizeof( struct V_10 ) ;
F_69 ( ! F_171 ( V_1 -> V_6 . V_45 ) ) ;
F_15 ( V_1 -> V_6 . V_45 , V_284 ) ;
F_69 ( ! F_171 ( V_1 -> V_6 . V_44 ) ) ;
F_15 ( V_1 -> V_6 . V_44 , V_284 ) ;
F_69 ( ! F_171 ( V_1 -> V_6 . V_43 ) ) ;
F_15 ( V_1 -> V_6 . V_43 , V_284 ) ;
}
static void F_172 ( struct V_19 * V_20 ,
struct V_288 * V_289 )
{
struct V_290 * V_291 = V_20 -> V_177 ;
T_2 V_8 = F_173 ( V_20 -> V_22 . V_8 ) ;
if ( V_291 )
F_174 ( V_289 , L_3 ,
V_291 -> V_292 , V_291 -> V_293 , V_291 -> V_294 ) ;
switch( V_20 -> V_23 . V_5 ) {
case V_188 :
F_174 ( V_289 , L_4 ,
& V_20 -> V_23 . V_3 . V_189 , & V_20 -> V_22 . V_2 . V_189 ) ;
break;
case V_192 :
F_174 ( V_289 , L_5 ,
V_20 -> V_23 . V_3 . V_194 , V_20 -> V_22 . V_2 . V_194 ) ;
break;
}
F_174 ( V_289 , L_6 , V_8 , V_8 ) ;
}
static void F_175 ( struct V_295 * V_296 , T_9 V_5 ,
struct V_288 * V_289 )
{
const struct V_297 * V_298 ;
const struct V_299 * V_300 ;
switch ( V_5 ) {
case V_188 :
V_298 = F_176 ( V_296 ) ;
F_174 ( V_289 , L_4 ,
& V_298 -> V_3 , & V_298 -> V_2 ) ;
break;
case V_192 :
V_300 = F_177 ( V_296 ) ;
F_174 ( V_289 ,
L_7 ,
& V_300 -> V_3 , & V_300 -> V_2 ,
V_300 -> V_301 [ 0 ] & 0x0f ,
V_300 -> V_301 [ 1 ] ,
V_300 -> V_301 [ 2 ] ) ;
break;
}
}
void F_178 ( struct V_19 * V_20 , int V_302 ,
T_10 V_303 , T_2 V_139 , T_2 V_140 )
{
struct V_288 * V_289 ;
V_289 = F_179 ( L_8 ) ;
if ( V_289 == NULL )
return;
F_180 ( V_303 , V_139 , V_140 , V_289 ) ;
F_172 ( V_20 , V_289 ) ;
F_174 ( V_289 , L_9 , V_302 ) ;
F_181 ( V_289 ) ;
}
void F_55 ( struct V_19 * V_20 , int V_302 ,
T_10 V_303 , T_2 V_139 , T_2 V_140 )
{
struct V_288 * V_289 ;
V_289 = F_179 ( L_10 ) ;
if ( V_289 == NULL )
return;
F_180 ( V_303 , V_139 , V_140 , V_289 ) ;
F_172 ( V_20 , V_289 ) ;
F_174 ( V_289 , L_9 , V_302 ) ;
F_181 ( V_289 ) ;
}
void F_182 ( struct V_19 * V_20 ,
struct V_295 * V_296 )
{
struct V_288 * V_289 ;
T_2 V_8 ;
V_289 = F_179 ( L_11 ) ;
if ( V_289 == NULL )
return;
F_175 ( V_296 , V_20 -> V_23 . V_5 , V_289 ) ;
V_8 = F_173 ( V_20 -> V_22 . V_8 ) ;
F_174 ( V_289 , L_6 , V_8 , V_8 ) ;
F_181 ( V_289 ) ;
}
void F_183 ( struct V_19 * V_20 ,
struct V_295 * V_296 , T_3 V_304 )
{
struct V_288 * V_289 ;
T_2 V_8 ;
V_289 = F_179 ( L_12 ) ;
if ( V_289 == NULL )
return;
F_175 ( V_296 , V_20 -> V_23 . V_5 , V_289 ) ;
V_8 = F_173 ( V_20 -> V_22 . V_8 ) ;
F_174 ( V_289 , L_13 ,
V_8 , V_8 , F_173 ( V_304 ) ) ;
F_181 ( V_289 ) ;
}
void F_184 ( struct V_295 * V_296 , T_9 V_5 )
{
struct V_288 * V_289 ;
V_289 = F_179 ( L_14 ) ;
if ( V_289 == NULL )
return;
F_175 ( V_296 , V_5 , V_289 ) ;
F_181 ( V_289 ) ;
}
void F_185 ( struct V_295 * V_296 , T_9 V_5 ,
T_3 V_305 , T_3 V_304 )
{
struct V_288 * V_289 ;
T_2 V_8 ;
V_289 = F_179 ( L_14 ) ;
if ( V_289 == NULL )
return;
F_175 ( V_296 , V_5 , V_289 ) ;
V_8 = F_173 ( V_305 ) ;
F_174 ( V_289 , L_13 ,
V_8 , V_8 , F_173 ( V_304 ) ) ;
F_181 ( V_289 ) ;
}
void F_186 ( struct V_19 * V_20 ,
struct V_295 * V_296 , T_4 V_9 )
{
struct V_288 * V_289 ;
T_3 V_305 ;
T_3 V_304 ;
V_289 = F_179 ( L_15 ) ;
if ( V_289 == NULL )
return;
F_175 ( V_296 , V_20 -> V_23 . V_5 , V_289 ) ;
if ( F_187 ( V_296 , V_9 , & V_305 , & V_304 ) == 0 ) {
T_2 V_8 = F_173 ( V_305 ) ;
F_174 ( V_289 , L_13 ,
V_8 , V_8 , F_173 ( V_304 ) ) ;
}
F_181 ( V_289 ) ;
}
