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
if ( V_106 <= 0 ) {
if ( V_20 -> V_109 & V_110 ) {
V_20 -> V_107 . V_108 = V_94 - V_20 -> V_111 - 1 ;
V_106 = V_20 -> V_104 . V_105 - V_20 -> V_111 ;
} else
goto V_103;
}
if ( V_106 < V_95 )
V_95 = V_106 ;
}
if ( V_20 -> V_104 . V_112 ) {
long V_106 = V_20 -> V_104 . V_112 +
( V_20 -> V_107 . V_113 ? : V_94 ) - V_94 ;
if ( V_106 <= 0 )
goto V_103;
if ( V_106 < V_95 )
V_95 = V_106 ;
}
if ( V_20 -> V_99 . V_114 )
goto V_115;
if ( V_20 -> V_104 . V_116 ) {
long V_106 = V_20 -> V_104 . V_116 +
V_20 -> V_107 . V_108 - V_94 ;
if ( V_106 <= 0 ) {
V_97 = 1 ;
V_20 -> V_109 &= ~ V_110 ;
} else if ( V_106 < V_95 ) {
V_95 = V_106 ;
V_20 -> V_109 |= V_110 ;
V_20 -> V_111 = V_106 ;
}
}
if ( V_20 -> V_104 . V_117 ) {
long V_106 = V_20 -> V_104 . V_117 +
( V_20 -> V_107 . V_113 ? : V_94 ) - V_94 ;
if ( V_106 <= 0 )
V_97 = 1 ;
else if ( V_106 < V_95 )
V_95 = V_106 ;
}
V_20 -> V_99 . V_114 = V_97 ;
if ( V_97 )
F_51 ( V_20 , 0 , 0 ) ;
V_115:
if ( V_95 != V_96 ) {
F_52 ( & V_20 -> V_68 , F_53 ( V_95 , 0 ) , V_118 ) ;
}
goto V_67;
V_103:
if ( V_20 -> V_99 . V_100 == V_119 && V_20 -> V_22 . V_8 == 0 ) {
V_20 -> V_99 . V_100 = V_102 ;
F_45 ( & V_1 -> V_6 . V_84 ) ;
V_95 = 2 ;
goto V_115;
}
V_52 = F_54 ( V_20 ) ;
if ( ! V_52 && V_20 -> V_22 . V_8 )
F_51 ( V_20 , 1 , 0 ) ;
F_55 ( V_20 , V_52 ? 0 : 1 ,
F_56 ( V_120 ) ,
F_57 ( V_120 ) , 0 ) ;
V_67:
F_58 ( & V_20 -> V_98 ) ;
return V_121 ;
}
struct V_19 * F_59 ( struct V_1 * V_1 )
{
struct V_19 * V_20 ;
V_20 = F_60 ( sizeof( struct V_19 ) , V_122 ) ;
if ( V_20 ) {
F_61 ( & V_20 -> F_48 , V_1 ) ;
F_62 ( & V_20 -> V_123 , 1 ) ;
F_62 ( & V_20 -> V_124 , 0 ) ;
F_63 ( & V_20 -> V_99 . V_125 ) ;
F_64 ( & V_20 -> V_24 ) ;
F_64 ( & V_20 -> V_25 ) ;
F_64 ( & V_20 -> V_26 ) ;
F_65 ( & V_20 -> V_68 , F_47 , V_126 , V_127 ) ;
F_66 ( & V_20 -> V_69 , V_128 ,
( unsigned long ) V_20 ) ;
V_20 -> V_107 . V_108 = F_49 () ;
V_20 -> V_104 . V_129 = V_130 ;
V_20 -> V_104 . V_131 = V_130 ;
V_20 -> V_104 . V_132 = V_130 ;
V_20 -> V_104 . V_133 = V_130 ;
V_20 -> V_134 = 0 ;
V_20 -> V_135 = 0 ;
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
F_9 ( & V_20 -> V_136 , & V_1 -> V_6 . V_83 ) ;
F_17 ( & V_82 ) ;
F_70 ( & V_1 -> V_6 . V_80 ) ;
}
int F_54 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
int V_52 = - V_137 ;
if ( V_20 -> V_99 . V_100 != V_101 ) {
V_20 -> V_99 . V_100 = V_101 ;
F_50 ( & V_42 ) ;
F_71 ( & V_20 -> V_99 . V_125 ) ;
F_72 ( & V_20 -> V_24 ) ;
F_72 ( & V_20 -> V_25 ) ;
if ( V_20 -> V_22 . V_8 )
F_72 ( & V_20 -> V_26 ) ;
V_1 -> V_6 . V_138 -- ;
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
F_75 ( struct V_1 * V_1 , T_4 V_9 , struct V_139 * V_140 )
{
int V_39 , V_52 = 0 ;
for ( V_39 = 0 ; V_39 <= V_1 -> V_6 . V_7 ; V_39 ++ ) {
struct V_16 * V_17 ;
struct V_19 * V_20 ;
F_76 (x, entry, net->xfrm.state_bydst+i, bydst) {
if ( F_77 ( V_20 -> V_22 . V_9 , V_9 ) &&
( V_52 = F_78 ( V_20 ) ) != 0 ) {
F_55 ( V_20 , 0 ,
V_140 -> V_141 ,
V_140 -> V_142 ,
V_140 -> V_143 ) ;
return V_52 ;
}
}
}
return V_52 ;
}
static inline int
F_75 ( struct V_1 * V_1 , T_4 V_9 , struct V_139 * V_140 )
{
return 0 ;
}
int F_79 ( struct V_1 * V_1 , T_4 V_9 , struct V_139 * V_140 )
{
int V_39 , V_52 = 0 , V_144 = 0 ;
F_16 ( & V_42 ) ;
V_52 = F_75 ( V_1 , V_9 , V_140 ) ;
if ( V_52 )
goto V_67;
V_52 = - V_137 ;
for ( V_39 = 0 ; V_39 <= V_1 -> V_6 . V_7 ; V_39 ++ ) {
struct V_16 * V_17 ;
struct V_19 * V_20 ;
V_145:
F_76 (x, entry, net->xfrm.state_bydst+i, bydst) {
if ( ! F_80 ( V_20 ) &&
F_77 ( V_20 -> V_22 . V_9 , V_9 ) ) {
F_81 ( V_20 ) ;
F_17 ( & V_42 ) ;
V_52 = F_74 ( V_20 ) ;
F_55 ( V_20 , V_52 ? 0 : 1 ,
V_140 -> V_141 ,
V_140 -> V_142 ,
V_140 -> V_143 ) ;
F_73 ( V_20 ) ;
if ( ! V_52 )
V_144 ++ ;
F_16 ( & V_42 ) ;
goto V_145;
}
}
}
if ( V_144 )
V_52 = 0 ;
V_67:
F_17 ( & V_42 ) ;
F_45 ( & V_1 -> V_6 . V_84 ) ;
return V_52 ;
}
void F_82 ( struct V_1 * V_1 , struct V_146 * V_147 )
{
F_16 ( & V_42 ) ;
V_147 -> V_148 = V_1 -> V_6 . V_138 ;
V_147 -> V_149 = V_1 -> V_6 . V_7 ;
V_147 -> V_150 = V_151 ;
F_17 ( & V_42 ) ;
}
static int
F_83 ( struct V_19 * V_20 , const struct V_152 * V_153 ,
const struct V_154 * V_155 ,
const T_1 * V_2 , const T_1 * V_3 ,
unsigned short V_5 )
{
struct V_46 * V_47 = F_28 ( V_5 ) ;
if ( ! V_47 )
return - 1 ;
V_47 -> V_156 ( & V_20 -> V_157 , V_153 ) ;
if ( V_5 != V_155 -> V_158 ) {
F_30 ( V_47 ) ;
V_47 = F_28 ( V_155 -> V_158 ) ;
if ( ! V_47 )
return - 1 ;
}
V_47 -> V_159 ( V_20 , V_155 , V_2 , V_3 ) ;
F_30 ( V_47 ) ;
return 0 ;
}
static struct V_19 * F_84 ( struct V_1 * V_1 , T_2 V_160 ,
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
if ( ( V_160 & V_20 -> V_160 . V_161 ) != V_20 -> V_160 . V_162 )
continue;
F_81 ( V_20 ) ;
return V_20 ;
}
return NULL ;
}
static struct V_19 * F_86 ( struct V_1 * V_1 , T_2 V_160 ,
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
if ( ( V_160 & V_20 -> V_160 . V_161 ) != V_20 -> V_160 . V_162 )
continue;
F_81 ( V_20 ) ;
return V_20 ;
}
return NULL ;
}
static inline struct V_19 *
F_87 ( struct V_19 * V_20 , int V_163 , int V_5 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
T_2 V_160 = V_20 -> V_160 . V_162 & V_20 -> V_160 . V_161 ;
if ( V_163 )
return F_84 ( V_1 , V_160 , & V_20 -> V_22 . V_2 ,
V_20 -> V_22 . V_8 , V_20 -> V_22 . V_9 , V_5 ) ;
else
return F_86 ( V_1 , V_160 ,
& V_20 -> V_22 . V_2 ,
& V_20 -> V_23 . V_3 ,
V_20 -> V_22 . V_9 , V_5 ) ;
}
static void F_88 ( struct V_1 * V_1 , int V_164 )
{
if ( V_164 &&
( V_1 -> V_6 . V_7 + 1 ) < V_151 &&
V_1 -> V_6 . V_138 > V_1 -> V_6 . V_7 )
F_70 ( & V_1 -> V_6 . V_29 ) ;
}
static void F_89 ( struct V_165 * V_166 , struct V_19 * V_20 ,
const struct V_152 * V_153 , unsigned short V_5 ,
struct V_19 * * V_167 , int * V_168 ,
int * error )
{
if ( V_20 -> V_99 . V_100 == V_169 ) {
if ( ( V_20 -> V_157 . V_5 &&
! F_90 ( & V_20 -> V_157 , V_153 , V_20 -> V_157 . V_5 ) ) ||
! F_91 ( V_20 , V_166 , V_153 ) )
return;
if ( ! * V_167 ||
( * V_167 ) -> V_99 . V_114 > V_20 -> V_99 . V_114 ||
( ( * V_167 ) -> V_99 . V_114 == V_20 -> V_99 . V_114 &&
( * V_167 ) -> V_107 . V_108 < V_20 -> V_107 . V_108 ) )
* V_167 = V_20 ;
} else if ( V_20 -> V_99 . V_100 == V_119 ) {
* V_168 = 1 ;
} else if ( V_20 -> V_99 . V_100 == V_170 ||
V_20 -> V_99 . V_100 == V_102 ) {
if ( F_90 ( & V_20 -> V_157 , V_153 , V_20 -> V_157 . V_5 ) &&
F_91 ( V_20 , V_166 , V_153 ) )
* error = - V_137 ;
}
}
struct V_19 *
F_92 ( const T_1 * V_2 , const T_1 * V_3 ,
const struct V_152 * V_153 , struct V_154 * V_155 ,
struct V_165 * V_166 , int * V_52 ,
unsigned short V_5 )
{
static T_1 V_171 = { } ;
struct V_1 * V_1 = F_93 ( V_166 ) ;
unsigned int V_21 , V_172 ;
struct V_16 * V_17 ;
struct V_19 * V_20 , * V_173 , * V_174 ;
int V_175 = 0 ;
int error = 0 ;
struct V_19 * V_167 = NULL ;
T_2 V_160 = V_166 -> V_160 . V_162 & V_166 -> V_160 . V_161 ;
unsigned short V_158 = V_155 -> V_158 ;
V_174 = NULL ;
F_16 ( & V_42 ) ;
V_21 = F_1 ( V_1 , V_2 , V_3 , V_155 -> V_4 , V_158 ) ;
F_76 (x, entry, net->xfrm.state_bydst+h, bydst) {
if ( V_20 -> V_23 . V_5 == V_158 &&
V_20 -> V_23 . V_4 == V_155 -> V_4 &&
( V_160 & V_20 -> V_160 . V_161 ) == V_20 -> V_160 . V_162 &&
! ( V_20 -> V_23 . V_176 & V_177 ) &&
F_94 ( V_20 , V_2 , V_3 , V_158 ) &&
V_155 -> V_61 == V_20 -> V_23 . V_61 &&
V_155 -> V_22 . V_9 == V_20 -> V_22 . V_9 &&
( V_155 -> V_22 . V_8 == V_20 -> V_22 . V_8 || ! V_155 -> V_22 . V_8 ) )
F_89 ( V_166 , V_20 , V_153 , V_158 ,
& V_167 , & V_175 , & error ) ;
}
if ( V_167 )
goto V_178;
V_172 = F_1 ( V_1 , V_2 , & V_171 , V_155 -> V_4 , V_158 ) ;
F_76 (x, entry, net->xfrm.state_bydst+h_wildcard, bydst) {
if ( V_20 -> V_23 . V_5 == V_158 &&
V_20 -> V_23 . V_4 == V_155 -> V_4 &&
( V_160 & V_20 -> V_160 . V_161 ) == V_20 -> V_160 . V_162 &&
! ( V_20 -> V_23 . V_176 & V_177 ) &&
F_94 ( V_20 , V_2 , V_3 , V_158 ) &&
V_155 -> V_61 == V_20 -> V_23 . V_61 &&
V_155 -> V_22 . V_9 == V_20 -> V_22 . V_9 &&
( V_155 -> V_22 . V_8 == V_20 -> V_22 . V_8 || ! V_155 -> V_22 . V_8 ) )
F_89 ( V_166 , V_20 , V_153 , V_158 ,
& V_167 , & V_175 , & error ) ;
}
V_178:
V_20 = V_167 ;
if ( ! V_20 && ! error && ! V_175 ) {
if ( V_155 -> V_22 . V_8 &&
( V_173 = F_84 ( V_1 , V_160 , V_2 , V_155 -> V_22 . V_8 ,
V_155 -> V_22 . V_9 , V_158 ) ) != NULL ) {
V_174 = V_173 ;
error = - V_55 ;
goto V_67;
}
V_20 = F_59 ( V_1 ) ;
if ( V_20 == NULL ) {
error = - V_179 ;
goto V_67;
}
F_83 ( V_20 , V_153 , V_155 , V_2 , V_3 , V_5 ) ;
memcpy ( & V_20 -> V_160 , & V_166 -> V_160 , sizeof( V_20 -> V_160 ) ) ;
error = F_95 ( V_20 , V_166 -> V_180 , V_153 -> V_181 ) ;
if ( error ) {
V_20 -> V_99 . V_100 = V_101 ;
V_174 = V_20 ;
V_20 = NULL ;
goto V_67;
}
if ( F_96 ( V_20 , V_155 , V_166 ) == 0 ) {
V_20 -> V_99 . V_100 = V_119 ;
F_97 ( & V_20 -> V_99 . V_125 , & V_1 -> V_6 . V_182 ) ;
F_9 ( & V_20 -> V_24 , V_1 -> V_6 . V_43 + V_21 ) ;
V_21 = F_3 ( V_1 , V_2 , V_3 , V_158 ) ;
F_9 ( & V_20 -> V_25 , V_1 -> V_6 . V_44 + V_21 ) ;
if ( V_20 -> V_22 . V_8 ) {
V_21 = F_5 ( V_1 , & V_20 -> V_22 . V_2 , V_20 -> V_22 . V_8 , V_20 -> V_22 . V_9 , V_158 ) ;
F_9 ( & V_20 -> V_26 , V_1 -> V_6 . V_45 + V_21 ) ;
}
V_20 -> V_104 . V_105 = V_1 -> V_6 . V_183 ;
F_52 ( & V_20 -> V_68 , F_53 ( V_1 -> V_6 . V_183 , 0 ) , V_118 ) ;
V_1 -> V_6 . V_138 ++ ;
F_88 ( V_1 , V_20 -> V_24 . V_95 != NULL ) ;
} else {
V_20 -> V_99 . V_100 = V_101 ;
V_174 = V_20 ;
V_20 = NULL ;
error = - V_137 ;
}
}
V_67:
if ( V_20 )
F_81 ( V_20 ) ;
else
* V_52 = V_175 ? - V_184 : error ;
F_17 ( & V_42 ) ;
if ( V_174 )
F_73 ( V_174 ) ;
return V_20 ;
}
struct V_19 *
F_98 ( struct V_1 * V_1 , T_2 V_160 ,
T_1 * V_2 , T_1 * V_3 ,
unsigned short V_5 , T_4 V_61 , T_4 V_9 , T_2 V_4 )
{
unsigned int V_21 ;
struct V_19 * V_185 = NULL , * V_20 = NULL ;
struct V_16 * V_17 ;
F_50 ( & V_42 ) ;
V_21 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_76 (x, entry, net->xfrm.state_bydst+h, bydst) {
if ( V_20 -> V_23 . V_5 == V_5 &&
V_20 -> V_23 . V_4 == V_4 &&
( V_160 & V_20 -> V_160 . V_161 ) == V_20 -> V_160 . V_162 &&
! ( V_20 -> V_23 . V_176 & V_177 ) &&
F_94 ( V_20 , V_2 , V_3 , V_5 ) &&
V_61 == V_20 -> V_23 . V_61 &&
V_9 == V_20 -> V_22 . V_9 &&
V_20 -> V_99 . V_100 == V_169 ) {
V_185 = V_20 ;
break;
}
}
if ( V_185 )
F_81 ( V_185 ) ;
F_58 ( & V_42 ) ;
return V_185 ;
}
static void F_99 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
unsigned int V_21 ;
F_97 ( & V_20 -> V_99 . V_125 , & V_1 -> V_6 . V_182 ) ;
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
F_52 ( & V_20 -> V_68 , F_53 ( 1 , 0 ) , V_118 ) ;
if ( V_20 -> V_134 )
F_100 ( & V_20 -> V_69 , V_186 + V_20 -> V_134 ) ;
F_45 ( & V_1 -> V_6 . V_84 ) ;
V_1 -> V_6 . V_138 ++ ;
F_88 ( V_1 , V_20 -> V_24 . V_95 != NULL ) ;
}
static void F_101 ( struct V_19 * V_187 )
{
struct V_1 * V_1 = F_48 ( V_187 ) ;
unsigned short V_5 = V_187 -> V_23 . V_5 ;
T_2 V_4 = V_187 -> V_23 . V_4 ;
struct V_19 * V_20 ;
struct V_16 * V_17 ;
unsigned int V_21 ;
T_2 V_160 = V_187 -> V_160 . V_162 & V_187 -> V_160 . V_161 ;
V_21 = F_1 ( V_1 , & V_187 -> V_22 . V_2 , & V_187 -> V_23 . V_3 , V_4 , V_5 ) ;
F_76 (x, entry, net->xfrm.state_bydst+h, bydst) {
if ( V_20 -> V_23 . V_5 == V_5 &&
V_20 -> V_23 . V_4 == V_4 &&
( V_160 & V_20 -> V_160 . V_161 ) == V_20 -> V_160 . V_162 &&
! F_85 ( & V_20 -> V_22 . V_2 , & V_187 -> V_22 . V_2 , V_5 ) &&
! F_85 ( & V_20 -> V_23 . V_3 , & V_187 -> V_23 . V_3 , V_5 ) )
V_20 -> V_188 ++ ;
}
}
void F_102 ( struct V_19 * V_20 )
{
F_16 ( & V_42 ) ;
F_101 ( V_20 ) ;
F_99 ( V_20 ) ;
F_17 ( & V_42 ) ;
}
static struct V_19 * F_103 ( struct V_1 * V_1 , struct V_189 * V_161 ,
unsigned short V_5 , T_4 V_61 ,
T_2 V_4 , T_4 V_9 ,
const T_1 * V_2 ,
const T_1 * V_3 , int V_190 )
{
unsigned int V_21 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
struct V_16 * V_17 ;
struct V_19 * V_20 ;
T_2 V_160 = V_161 -> V_162 & V_161 -> V_161 ;
F_76 (x, entry, net->xfrm.state_bydst+h, bydst) {
if ( V_20 -> V_23 . V_4 != V_4 ||
V_20 -> V_23 . V_61 != V_61 ||
V_20 -> V_23 . V_5 != V_5 ||
V_20 -> V_99 . V_100 != V_119 ||
V_20 -> V_22 . V_8 != 0 ||
V_20 -> V_22 . V_9 != V_9 ||
( V_160 & V_20 -> V_160 . V_161 ) != V_20 -> V_160 . V_162 ||
F_85 ( & V_20 -> V_22 . V_2 , V_2 , V_5 ) ||
F_85 ( & V_20 -> V_23 . V_3 , V_3 , V_5 ) )
continue;
F_81 ( V_20 ) ;
return V_20 ;
}
if ( ! V_190 )
return NULL ;
V_20 = F_59 ( V_1 ) ;
if ( F_25 ( V_20 ) ) {
switch ( V_5 ) {
case V_191 :
V_20 -> V_157 . V_2 . V_192 = V_2 -> V_192 ;
V_20 -> V_157 . V_3 . V_192 = V_3 -> V_192 ;
V_20 -> V_157 . V_193 = 32 ;
V_20 -> V_157 . V_194 = 32 ;
V_20 -> V_23 . V_3 . V_192 = V_3 -> V_192 ;
V_20 -> V_22 . V_2 . V_192 = V_2 -> V_192 ;
break;
case V_195 :
* (struct V_196 * ) V_20 -> V_157 . V_2 . V_197 = * (struct V_196 * ) V_2 ;
* (struct V_196 * ) V_20 -> V_157 . V_3 . V_197 = * (struct V_196 * ) V_3 ;
V_20 -> V_157 . V_193 = 128 ;
V_20 -> V_157 . V_194 = 128 ;
* (struct V_196 * ) V_20 -> V_23 . V_3 . V_197 = * (struct V_196 * ) V_3 ;
* (struct V_196 * ) V_20 -> V_22 . V_2 . V_197 = * (struct V_196 * ) V_2 ;
break;
}
V_20 -> V_99 . V_100 = V_119 ;
V_20 -> V_22 . V_9 = V_9 ;
V_20 -> V_23 . V_5 = V_5 ;
V_20 -> V_23 . V_61 = V_61 ;
V_20 -> V_23 . V_4 = V_4 ;
V_20 -> V_160 . V_162 = V_161 -> V_162 ;
V_20 -> V_160 . V_161 = V_161 -> V_161 ;
V_20 -> V_104 . V_105 = V_1 -> V_6 . V_183 ;
F_81 ( V_20 ) ;
F_52 ( & V_20 -> V_68 , F_53 ( V_1 -> V_6 . V_183 , 0 ) , V_118 ) ;
F_97 ( & V_20 -> V_99 . V_125 , & V_1 -> V_6 . V_182 ) ;
F_9 ( & V_20 -> V_24 , V_1 -> V_6 . V_43 + V_21 ) ;
V_21 = F_3 ( V_1 , V_2 , V_3 , V_5 ) ;
F_9 ( & V_20 -> V_25 , V_1 -> V_6 . V_44 + V_21 ) ;
V_1 -> V_6 . V_138 ++ ;
F_88 ( V_1 , V_20 -> V_24 . V_95 != NULL ) ;
}
return V_20 ;
}
int F_104 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
struct V_19 * V_198 , * V_174 ;
int V_5 ;
int V_52 ;
T_2 V_160 = V_20 -> V_160 . V_162 & V_20 -> V_160 . V_161 ;
int V_163 = F_77 ( V_20 -> V_22 . V_9 , V_199 ) ;
V_5 = V_20 -> V_23 . V_5 ;
V_174 = NULL ;
F_16 ( & V_42 ) ;
V_198 = F_87 ( V_20 , V_163 , V_5 ) ;
if ( V_198 ) {
V_174 = V_198 ;
V_198 = NULL ;
V_52 = - V_55 ;
goto V_67;
}
if ( V_163 && V_20 -> V_99 . V_200 ) {
V_198 = F_105 ( V_1 , V_160 , V_20 -> V_99 . V_200 ) ;
if ( V_198 && ( ( V_198 -> V_22 . V_9 != V_20 -> V_22 . V_9 ) ||
F_85 ( & V_198 -> V_22 . V_2 , & V_20 -> V_22 . V_2 , V_5 ) ) ) {
V_174 = V_198 ;
V_198 = NULL ;
}
}
if ( V_163 && ! V_198 )
V_198 = F_103 ( V_1 , & V_20 -> V_160 , V_5 , V_20 -> V_23 . V_61 ,
V_20 -> V_23 . V_4 , V_20 -> V_22 . V_9 ,
& V_20 -> V_22 . V_2 , & V_20 -> V_23 . V_3 , 0 ) ;
F_101 ( V_20 ) ;
F_99 ( V_20 ) ;
V_52 = 0 ;
V_67:
F_17 ( & V_42 ) ;
if ( V_198 ) {
F_74 ( V_198 ) ;
F_73 ( V_198 ) ;
}
if ( V_174 )
F_73 ( V_174 ) ;
return V_52 ;
}
static struct V_19 * F_106 ( struct V_19 * V_201 , int * V_202 )
{
struct V_1 * V_1 = F_48 ( V_201 ) ;
int V_52 = - V_179 ;
struct V_19 * V_20 = F_59 ( V_1 ) ;
if ( ! V_20 )
goto V_67;
memcpy ( & V_20 -> V_22 , & V_201 -> V_22 , sizeof( V_20 -> V_22 ) ) ;
memcpy ( & V_20 -> V_157 , & V_201 -> V_157 , sizeof( V_20 -> V_157 ) ) ;
memcpy ( & V_20 -> V_104 , & V_201 -> V_104 , sizeof( V_20 -> V_104 ) ) ;
V_20 -> V_23 . V_61 = V_201 -> V_23 . V_61 ;
V_20 -> V_23 . V_203 = V_201 -> V_23 . V_203 ;
V_20 -> V_23 . V_4 = V_201 -> V_23 . V_4 ;
V_20 -> V_23 . V_5 = V_201 -> V_23 . V_5 ;
V_20 -> V_23 . V_3 = V_201 -> V_23 . V_3 ;
if ( V_201 -> V_70 ) {
V_20 -> V_70 = F_107 ( V_201 -> V_70 ) ;
if ( ! V_20 -> V_70 )
goto error;
}
V_20 -> V_23 . V_204 = V_201 -> V_23 . V_204 ;
if ( V_201 -> V_71 ) {
V_20 -> V_71 = F_108 ( V_201 -> V_71 ) ;
if ( ! V_20 -> V_71 )
goto error;
}
V_20 -> V_23 . V_205 = V_201 -> V_23 . V_205 ;
if ( V_201 -> V_72 ) {
V_20 -> V_72 = F_108 ( V_201 -> V_72 ) ;
if ( ! V_20 -> V_72 )
goto error;
}
V_20 -> V_23 . V_206 = V_201 -> V_23 . V_206 ;
if ( V_201 -> V_63 ) {
V_20 -> V_63 = F_109 ( V_201 -> V_63 , sizeof( * V_20 -> V_63 ) , V_207 ) ;
if ( ! V_20 -> V_63 )
goto error;
}
if ( V_201 -> V_73 ) {
V_20 -> V_73 = F_109 ( V_201 -> V_73 , sizeof( * V_20 -> V_73 ) ,
V_207 ) ;
if ( ! V_20 -> V_73 )
goto error;
}
if ( V_201 -> V_74 ) {
V_52 = F_110 ( V_20 , V_201 ) ;
if ( V_52 )
goto error;
}
memcpy ( & V_20 -> V_160 , & V_201 -> V_160 , sizeof( V_20 -> V_160 ) ) ;
V_52 = F_111 ( V_20 ) ;
if ( V_52 )
goto error;
V_20 -> V_23 . V_176 = V_201 -> V_23 . V_176 ;
V_20 -> V_107 . V_108 = V_201 -> V_107 . V_108 ;
V_20 -> V_99 . V_100 = V_201 -> V_99 . V_100 ;
V_20 -> V_99 . V_200 = V_201 -> V_99 . V_200 ;
return V_20 ;
error:
F_73 ( V_20 ) ;
V_67:
if ( V_202 )
* V_202 = V_52 ;
return NULL ;
}
struct V_19 * F_112 ( struct V_208 * V_161 )
{
unsigned int V_21 ;
struct V_19 * V_20 ;
struct V_16 * V_17 ;
if ( V_161 -> V_4 ) {
V_21 = F_1 ( & V_209 , & V_161 -> V_210 , & V_161 -> V_211 ,
V_161 -> V_4 , V_161 -> V_212 ) ;
F_76 (x, entry, init_net.xfrm.state_bydst+h, bydst) {
if ( V_20 -> V_23 . V_61 != V_161 -> V_61 ||
V_20 -> V_22 . V_9 != V_161 -> V_9 )
continue;
if ( V_161 -> V_4 && V_20 -> V_23 . V_4 != V_161 -> V_4 )
continue;
if ( F_85 ( & V_20 -> V_22 . V_2 , & V_161 -> V_210 ,
V_161 -> V_212 ) ||
F_85 ( & V_20 -> V_23 . V_3 , & V_161 -> V_211 ,
V_161 -> V_212 ) )
continue;
F_81 ( V_20 ) ;
return V_20 ;
}
} else {
V_21 = F_3 ( & V_209 , & V_161 -> V_210 , & V_161 -> V_211 ,
V_161 -> V_212 ) ;
F_76 (x, entry, init_net.xfrm.state_bysrc+h, bysrc) {
if ( V_20 -> V_23 . V_61 != V_161 -> V_61 ||
V_20 -> V_22 . V_9 != V_161 -> V_9 )
continue;
if ( F_85 ( & V_20 -> V_22 . V_2 , & V_161 -> V_210 ,
V_161 -> V_212 ) ||
F_85 ( & V_20 -> V_23 . V_3 , & V_161 -> V_211 ,
V_161 -> V_212 ) )
continue;
F_81 ( V_20 ) ;
return V_20 ;
}
}
return NULL ;
}
struct V_19 * F_113 ( struct V_19 * V_20 ,
struct V_208 * V_161 )
{
struct V_19 * V_213 ;
int V_52 ;
V_213 = F_106 ( V_20 , & V_52 ) ;
if ( ! V_213 )
return NULL ;
memcpy ( & V_213 -> V_22 . V_2 , & V_161 -> V_214 , sizeof( V_213 -> V_22 . V_2 ) ) ;
memcpy ( & V_213 -> V_23 . V_3 , & V_161 -> V_215 , sizeof( V_213 -> V_23 . V_3 ) ) ;
if ( ! F_85 ( & V_20 -> V_22 . V_2 , & V_161 -> V_214 , V_161 -> V_216 ) ) {
F_102 ( V_213 ) ;
} else {
if ( ( V_52 = F_104 ( V_213 ) ) < 0 )
goto error;
}
return V_213 ;
error:
F_73 ( V_213 ) ;
return NULL ;
}
int F_114 ( struct V_19 * V_20 )
{
struct V_19 * V_198 , * V_174 ;
int V_52 ;
int V_163 = F_77 ( V_20 -> V_22 . V_9 , V_199 ) ;
V_174 = NULL ;
F_16 ( & V_42 ) ;
V_198 = F_87 ( V_20 , V_163 , V_20 -> V_23 . V_5 ) ;
V_52 = - V_137 ;
if ( ! V_198 )
goto V_67;
if ( F_80 ( V_198 ) ) {
V_174 = V_198 ;
V_52 = - V_55 ;
goto V_67;
}
if ( V_198 -> V_99 . V_100 == V_119 ) {
F_99 ( V_20 ) ;
V_20 = NULL ;
}
V_52 = 0 ;
V_67:
F_17 ( & V_42 ) ;
if ( V_174 )
F_73 ( V_174 ) ;
if ( V_52 )
return V_52 ;
if ( ! V_20 ) {
F_74 ( V_198 ) ;
F_73 ( V_198 ) ;
return 0 ;
}
V_52 = - V_65 ;
F_16 ( & V_198 -> V_98 ) ;
if ( F_25 ( V_198 -> V_99 . V_100 == V_169 ) ) {
if ( V_20 -> V_63 && V_198 -> V_63 )
memcpy ( V_198 -> V_63 , V_20 -> V_63 , sizeof( * V_198 -> V_63 ) ) ;
if ( V_20 -> V_73 && V_198 -> V_73 ) {
memcpy ( V_198 -> V_73 , V_20 -> V_73 , sizeof( * V_198 -> V_73 ) ) ;
}
if ( ! V_163 && memcmp ( & V_198 -> V_157 , & V_20 -> V_157 , sizeof( V_198 -> V_157 ) ) )
memcpy ( & V_198 -> V_157 , & V_20 -> V_157 , sizeof( V_198 -> V_157 ) ) ;
memcpy ( & V_198 -> V_104 , & V_20 -> V_104 , sizeof( V_198 -> V_104 ) ) ;
V_198 -> V_99 . V_114 = 0 ;
F_52 ( & V_198 -> V_68 , F_53 ( 1 , 0 ) , V_118 ) ;
if ( V_198 -> V_107 . V_113 )
F_115 ( V_198 ) ;
V_52 = 0 ;
V_20 -> V_99 . V_100 = V_101 ;
F_116 ( V_20 ) ;
}
F_17 ( & V_198 -> V_98 ) ;
F_73 ( V_198 ) ;
return V_52 ;
}
int F_115 ( struct V_19 * V_20 )
{
if ( ! V_20 -> V_107 . V_113 )
V_20 -> V_107 . V_113 = F_49 () ;
if ( V_20 -> V_99 . V_100 != V_169 )
return - V_65 ;
if ( V_20 -> V_107 . V_217 >= V_20 -> V_104 . V_132 ||
V_20 -> V_107 . V_218 >= V_20 -> V_104 . V_133 ) {
V_20 -> V_99 . V_100 = V_102 ;
F_52 ( & V_20 -> V_68 , F_53 ( 0 , 0 ) , V_118 ) ;
return - V_65 ;
}
if ( ! V_20 -> V_99 . V_114 &&
( V_20 -> V_107 . V_217 >= V_20 -> V_104 . V_129 ||
V_20 -> V_107 . V_218 >= V_20 -> V_104 . V_131 ) ) {
V_20 -> V_99 . V_114 = 1 ;
F_51 ( V_20 , 0 , 0 ) ;
}
return 0 ;
}
struct V_19 *
F_117 ( struct V_1 * V_1 , T_2 V_160 , const T_1 * V_2 , T_3 V_8 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_19 * V_20 ;
F_16 ( & V_42 ) ;
V_20 = F_84 ( V_1 , V_160 , V_2 , V_8 , V_9 , V_5 ) ;
F_17 ( & V_42 ) ;
return V_20 ;
}
struct V_19 *
F_118 ( struct V_1 * V_1 , T_2 V_160 ,
const T_1 * V_2 , const T_1 * V_3 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_19 * V_20 ;
F_16 ( & V_42 ) ;
V_20 = F_86 ( V_1 , V_160 , V_2 , V_3 , V_9 , V_5 ) ;
F_17 ( & V_42 ) ;
return V_20 ;
}
struct V_19 *
F_119 ( struct V_1 * V_1 , struct V_189 * V_160 , T_4 V_61 , T_2 V_4 , T_4 V_9 ,
const T_1 * V_2 , const T_1 * V_3 ,
int V_190 , unsigned short V_5 )
{
struct V_19 * V_20 ;
F_16 ( & V_42 ) ;
V_20 = F_103 ( V_1 , V_160 , V_5 , V_61 , V_4 , V_9 , V_2 , V_3 , V_190 ) ;
F_17 ( & V_42 ) ;
return V_20 ;
}
int
F_120 ( struct V_154 * * V_219 , struct V_154 * * V_220 , int V_221 ,
unsigned short V_5 )
{
int V_52 = 0 ;
struct V_46 * V_47 = F_28 ( V_5 ) ;
if ( ! V_47 )
return - V_53 ;
F_16 ( & V_42 ) ;
if ( V_47 -> V_222 )
V_52 = V_47 -> V_222 ( V_219 , V_220 , V_221 ) ;
F_17 ( & V_42 ) ;
F_30 ( V_47 ) ;
return V_52 ;
}
int
F_121 ( struct V_19 * * V_219 , struct V_19 * * V_220 , int V_221 ,
unsigned short V_5 )
{
int V_52 = 0 ;
struct V_46 * V_47 = F_28 ( V_5 ) ;
if ( ! V_47 )
return - V_53 ;
F_16 ( & V_42 ) ;
if ( V_47 -> V_223 )
V_52 = V_47 -> V_223 ( V_219 , V_220 , V_221 ) ;
F_17 ( & V_42 ) ;
F_30 ( V_47 ) ;
return V_52 ;
}
static struct V_19 * F_105 ( struct V_1 * V_1 , T_2 V_160 , T_2 V_200 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 <= V_1 -> V_6 . V_7 ; V_39 ++ ) {
struct V_16 * V_17 ;
struct V_19 * V_20 ;
F_76 (x, entry, net->xfrm.state_bydst+i, bydst) {
if ( V_20 -> V_99 . V_200 == V_200 &&
( V_160 & V_20 -> V_160 . V_161 ) == V_20 -> V_160 . V_162 &&
V_20 -> V_99 . V_100 == V_119 ) {
F_81 ( V_20 ) ;
return V_20 ;
}
}
}
return NULL ;
}
struct V_19 * F_122 ( struct V_1 * V_1 , T_2 V_160 , T_2 V_200 )
{
struct V_19 * V_20 ;
F_16 ( & V_42 ) ;
V_20 = F_105 ( V_1 , V_160 , V_200 ) ;
F_17 ( & V_42 ) ;
return V_20 ;
}
T_2 F_123 ( void )
{
T_2 V_224 ;
static T_5 V_225 ;
do {
V_224 = F_124 ( & V_225 ) ;
} while ( ! V_224 );
return V_224 ;
}
int F_125 ( struct V_19 * V_20 , T_2 V_226 , T_2 V_227 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
unsigned int V_21 ;
struct V_19 * V_173 ;
int V_52 = - V_56 ;
T_3 V_228 = F_126 ( V_226 ) ;
T_3 V_229 = F_126 ( V_227 ) ;
T_2 V_160 = V_20 -> V_160 . V_162 & V_20 -> V_160 . V_161 ;
F_16 ( & V_20 -> V_98 ) ;
if ( V_20 -> V_99 . V_100 == V_101 )
goto V_230;
V_52 = 0 ;
if ( V_20 -> V_22 . V_8 )
goto V_230;
V_52 = - V_56 ;
if ( V_228 == V_229 ) {
V_173 = F_117 ( V_1 , V_160 , & V_20 -> V_22 . V_2 , V_228 , V_20 -> V_22 . V_9 , V_20 -> V_23 . V_5 ) ;
if ( V_173 ) {
F_73 ( V_173 ) ;
goto V_230;
}
V_20 -> V_22 . V_8 = V_228 ;
} else {
T_2 V_8 = 0 ;
for ( V_21 = 0 ; V_21 < V_227 - V_226 + 1 ; V_21 ++ ) {
V_8 = V_226 + F_127 () % ( V_227 - V_226 + 1 ) ;
V_173 = F_117 ( V_1 , V_160 , & V_20 -> V_22 . V_2 , F_126 ( V_8 ) , V_20 -> V_22 . V_9 , V_20 -> V_23 . V_5 ) ;
if ( V_173 == NULL ) {
V_20 -> V_22 . V_8 = F_126 ( V_8 ) ;
break;
}
F_73 ( V_173 ) ;
}
}
if ( V_20 -> V_22 . V_8 ) {
F_16 ( & V_42 ) ;
V_21 = F_5 ( V_1 , & V_20 -> V_22 . V_2 , V_20 -> V_22 . V_8 , V_20 -> V_22 . V_9 , V_20 -> V_23 . V_5 ) ;
F_9 ( & V_20 -> V_26 , V_1 -> V_6 . V_45 + V_21 ) ;
F_17 ( & V_42 ) ;
V_52 = 0 ;
}
V_230:
F_17 ( & V_20 -> V_98 ) ;
return V_52 ;
}
int F_128 ( struct V_1 * V_1 , struct F_128 * V_231 ,
int (* F_129)( struct V_19 * , int , void * ) ,
void * V_232 )
{
struct V_19 * V_100 ;
struct F_128 * V_20 ;
int V_52 = 0 ;
if ( V_231 -> V_200 != 0 && F_130 ( & V_231 -> V_125 ) )
return 0 ;
F_16 ( & V_42 ) ;
if ( F_130 ( & V_231 -> V_125 ) )
V_20 = F_131 ( & V_1 -> V_6 . V_182 , struct F_128 , V_125 ) ;
else
V_20 = F_132 ( & V_231 -> V_125 , struct F_128 , V_125 ) ;
F_133 (x, &net->xfrm.state_all, all) {
if ( V_20 -> V_100 == V_101 )
continue;
V_100 = F_12 ( V_20 , struct V_19 , V_99 ) ;
if ( ! F_77 ( V_100 -> V_22 . V_9 , V_231 -> V_9 ) )
continue;
V_52 = F_129 ( V_100 , V_231 -> V_200 , V_232 ) ;
if ( V_52 ) {
F_134 ( & V_231 -> V_125 , & V_20 -> V_125 ) ;
goto V_67;
}
V_231 -> V_200 ++ ;
}
if ( V_231 -> V_200 == 0 ) {
V_52 = - V_56 ;
goto V_67;
}
F_135 ( & V_231 -> V_125 ) ;
V_67:
F_17 ( & V_42 ) ;
return V_52 ;
}
void F_136 ( struct F_128 * V_231 , T_4 V_9 )
{
F_63 ( & V_231 -> V_125 ) ;
V_231 -> V_9 = V_9 ;
V_231 -> V_100 = V_101 ;
V_231 -> V_200 = 0 ;
}
void F_137 ( struct F_128 * V_231 )
{
if ( F_130 ( & V_231 -> V_125 ) )
return;
F_16 ( & V_42 ) ;
F_71 ( & V_231 -> V_125 ) ;
F_17 ( & V_42 ) ;
}
static void V_128 ( unsigned long V_232 )
{
struct V_19 * V_20 = (struct V_19 * ) V_232 ;
F_50 ( & V_20 -> V_98 ) ;
if ( V_20 -> V_99 . V_100 == V_169 ) {
if ( F_138 ( F_48 ( V_20 ) ) )
V_20 -> V_233 -> V_234 ( V_20 , V_235 ) ;
else
V_20 -> V_109 |= V_236 ;
}
F_58 ( & V_20 -> V_98 ) ;
}
void F_139 ( struct V_165 * V_237 , int V_238 , const struct V_239 * V_240 )
{
struct V_241 * V_99 ;
F_140 ( & V_242 ) ;
F_141 (km, &xfrm_km_list, list)
if ( V_99 -> V_243 )
V_99 -> V_243 ( V_237 , V_238 , V_240 ) ;
F_142 ( & V_242 ) ;
}
void F_143 ( struct V_19 * V_20 , const struct V_239 * V_240 )
{
struct V_241 * V_99 ;
F_140 ( & V_242 ) ;
F_141 (km, &xfrm_km_list, list)
if ( V_99 -> V_234 )
V_99 -> V_234 ( V_20 , V_240 ) ;
F_142 ( & V_242 ) ;
}
void F_51 ( struct V_19 * V_20 , int V_244 , T_2 V_245 )
{
struct V_1 * V_1 = F_48 ( V_20 ) ;
struct V_239 V_240 ;
V_240 . V_232 . V_244 = V_244 ;
V_240 . V_245 = V_245 ;
V_240 . V_246 = V_247 ;
F_143 ( V_20 , & V_240 ) ;
if ( V_244 )
F_45 ( & V_1 -> V_6 . V_84 ) ;
}
int F_96 ( struct V_19 * V_20 , struct V_154 * V_248 , struct V_165 * V_166 )
{
int V_52 = - V_65 , V_249 ;
struct V_241 * V_99 ;
F_140 ( & V_242 ) ;
F_141 (km, &xfrm_km_list, list) {
V_249 = V_99 -> V_250 ( V_20 , V_248 , V_166 , V_251 ) ;
if ( ! V_249 )
V_52 = V_249 ;
}
F_142 ( & V_242 ) ;
return V_52 ;
}
int F_144 ( struct V_19 * V_20 , T_1 * V_252 , T_6 V_253 )
{
int V_52 = - V_65 ;
struct V_241 * V_99 ;
F_140 ( & V_242 ) ;
F_141 (km, &xfrm_km_list, list) {
if ( V_99 -> V_254 )
V_52 = V_99 -> V_254 ( V_20 , V_252 , V_253 ) ;
if ( ! V_52 )
break;
}
F_142 ( & V_242 ) ;
return V_52 ;
}
void F_145 ( struct V_165 * V_166 , int V_238 , int V_244 , T_2 V_245 )
{
struct V_1 * V_1 = F_93 ( V_166 ) ;
struct V_239 V_240 ;
V_240 . V_232 . V_244 = V_244 ;
V_240 . V_245 = V_245 ;
V_240 . V_246 = V_255 ;
F_139 ( V_166 , V_238 , & V_240 ) ;
if ( V_244 )
F_45 ( & V_1 -> V_6 . V_84 ) ;
}
int F_146 ( const struct V_256 * V_157 , T_4 V_238 , T_4 type ,
const struct V_208 * V_161 , int V_257 ,
const struct V_258 * V_259 )
{
int V_52 = - V_65 ;
int V_260 ;
struct V_241 * V_99 ;
F_140 ( & V_242 ) ;
F_141 (km, &xfrm_km_list, list) {
if ( V_99 -> V_261 ) {
V_260 = V_99 -> V_261 ( V_157 , V_238 , type , V_161 , V_257 , V_259 ) ;
if ( ! V_260 )
V_52 = V_260 ;
}
}
F_142 ( & V_242 ) ;
return V_52 ;
}
int F_147 ( struct V_1 * V_1 , T_4 V_9 , struct V_256 * V_157 , T_1 * V_262 )
{
int V_52 = - V_65 ;
int V_260 ;
struct V_241 * V_99 ;
F_140 ( & V_242 ) ;
F_141 (km, &xfrm_km_list, list) {
if ( V_99 -> V_263 ) {
V_260 = V_99 -> V_263 ( V_1 , V_9 , V_157 , V_262 ) ;
if ( ! V_260 )
V_52 = V_260 ;
}
}
F_142 ( & V_242 ) ;
return V_52 ;
}
int F_148 ( struct V_264 * V_265 , int V_266 , T_4 T_7 * V_267 , int V_268 )
{
int V_52 ;
T_4 * V_232 ;
struct V_241 * V_99 ;
struct V_165 * V_166 = NULL ;
if ( V_268 <= 0 || V_268 > V_269 )
return - V_270 ;
V_232 = F_149 ( V_268 , V_207 ) ;
if ( ! V_232 )
return - V_179 ;
V_52 = - V_271 ;
if ( F_150 ( V_232 , V_267 , V_268 ) )
goto V_67;
V_52 = - V_65 ;
F_140 ( & V_242 ) ;
F_141 (km, &xfrm_km_list, list) {
V_166 = V_99 -> V_272 ( V_265 , V_266 , V_232 ,
V_268 , & V_52 ) ;
if ( V_52 >= 0 )
break;
}
F_142 ( & V_242 ) ;
if ( V_52 >= 0 ) {
F_151 ( V_265 , V_52 , V_166 ) ;
F_152 ( V_166 ) ;
V_52 = 0 ;
}
V_67:
F_41 ( V_232 ) ;
return V_52 ;
}
int F_153 ( struct V_241 * V_99 )
{
F_21 ( & V_242 ) ;
F_154 ( & V_99 -> V_11 , & V_273 ) ;
F_22 ( & V_242 ) ;
return 0 ;
}
int F_155 ( struct V_241 * V_99 )
{
F_21 ( & V_242 ) ;
F_71 ( & V_99 -> V_11 ) ;
F_22 ( & V_242 ) ;
return 0 ;
}
int F_156 ( struct V_46 * V_47 )
{
int V_52 = 0 ;
if ( F_20 ( V_47 == NULL ) )
return - V_65 ;
if ( F_20 ( V_47 -> V_5 >= V_48 ) )
return - V_53 ;
F_21 ( & V_49 ) ;
if ( F_20 ( V_46 [ V_47 -> V_5 ] != NULL ) )
V_52 = - V_274 ;
else
V_46 [ V_47 -> V_5 ] = V_47 ;
F_22 ( & V_49 ) ;
return V_52 ;
}
int F_157 ( struct V_46 * V_47 )
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
F_140 ( & V_49 ) ;
V_47 = V_46 [ V_5 ] ;
if ( F_20 ( ! V_47 ) )
F_142 ( & V_49 ) ;
return V_47 ;
}
static void F_30 ( struct V_46 * V_47 )
__releases( V_49 )
{
F_142 ( & V_49 ) ;
}
void F_158 ( struct V_19 * V_20 )
{
if ( V_20 -> V_275 ) {
struct V_19 * V_248 = V_20 -> V_275 ;
if ( F_159 ( & V_248 -> V_124 ) == 2 )
F_74 ( V_248 ) ;
F_160 ( & V_248 -> V_124 ) ;
F_73 ( V_248 ) ;
V_20 -> V_275 = NULL ;
}
}
int F_161 ( struct V_19 * V_20 , int V_276 )
{
int V_224 ;
F_16 ( & V_20 -> V_98 ) ;
if ( V_20 -> V_99 . V_100 == V_169 &&
V_20 -> type && V_20 -> type -> V_277 )
V_224 = V_20 -> type -> V_277 ( V_20 , V_276 ) ;
else
V_224 = V_276 - V_20 -> V_23 . V_278 ;
F_17 ( & V_20 -> V_98 ) ;
return V_224 ;
}
int F_162 ( struct V_19 * V_20 , bool V_279 )
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
if ( V_47 -> V_280 )
V_52 = V_47 -> V_280 ( V_20 ) ;
F_30 ( V_47 ) ;
if ( V_52 )
goto error;
V_52 = - V_281 ;
if ( V_20 -> V_157 . V_5 != V_282 ) {
V_76 = F_36 ( V_20 -> V_23 . V_61 , V_20 -> V_157 . V_5 ) ;
if ( V_76 == NULL )
goto error;
if ( ! ( V_76 -> V_176 & V_283 ) &&
V_5 != V_20 -> V_157 . V_5 ) {
F_37 ( V_76 ) ;
goto error;
}
V_20 -> V_76 = V_76 ;
} else {
struct V_60 * V_77 ;
int V_284 = V_191 ;
V_76 = F_36 ( V_20 -> V_23 . V_61 , V_20 -> V_23 . V_5 ) ;
if ( V_76 == NULL )
goto error;
if ( ! ( V_76 -> V_176 & V_283 ) ) {
F_37 ( V_76 ) ;
goto error;
}
V_20 -> V_76 = V_76 ;
if ( V_20 -> V_23 . V_5 == V_191 )
V_284 = V_195 ;
V_77 = F_36 ( V_20 -> V_23 . V_61 , V_284 ) ;
if ( V_77 ) {
if ( V_77 -> V_176 & V_283 )
V_20 -> V_77 = V_77 ;
else
F_37 ( V_77 ) ;
}
}
V_20 -> type = F_27 ( V_20 -> V_22 . V_9 , V_5 ) ;
if ( V_20 -> type == NULL )
goto error;
V_52 = V_20 -> type -> V_285 ( V_20 ) ;
if ( V_52 )
goto error;
V_20 -> V_78 = F_36 ( V_20 -> V_23 . V_61 , V_5 ) ;
if ( V_20 -> V_78 == NULL ) {
V_52 = - V_281 ;
goto error;
}
if ( V_279 ) {
V_52 = F_163 ( V_20 ) ;
if ( V_52 )
goto error;
}
V_20 -> V_99 . V_100 = V_169 ;
error:
return V_52 ;
}
int F_111 ( struct V_19 * V_20 )
{
return F_162 ( V_20 , true ) ;
}
int T_8 F_164 ( struct V_1 * V_1 )
{
unsigned int V_286 ;
F_63 ( & V_1 -> V_6 . V_182 ) ;
V_286 = sizeof( struct V_10 ) * 8 ;
V_1 -> V_6 . V_43 = F_14 ( V_286 ) ;
if ( ! V_1 -> V_6 . V_43 )
goto V_287;
V_1 -> V_6 . V_44 = F_14 ( V_286 ) ;
if ( ! V_1 -> V_6 . V_44 )
goto V_288;
V_1 -> V_6 . V_45 = F_14 ( V_286 ) ;
if ( ! V_1 -> V_6 . V_45 )
goto V_289;
V_1 -> V_6 . V_7 = ( ( V_286 / sizeof( struct V_10 ) ) - 1 ) ;
V_1 -> V_6 . V_138 = 0 ;
F_165 ( & V_1 -> V_6 . V_29 , F_11 ) ;
F_166 ( & V_1 -> V_6 . V_83 ) ;
F_165 ( & V_1 -> V_6 . V_80 , F_43 ) ;
F_167 ( & V_1 -> V_6 . V_84 ) ;
return 0 ;
V_289:
F_15 ( V_1 -> V_6 . V_44 , V_286 ) ;
V_288:
F_15 ( V_1 -> V_6 . V_43 , V_286 ) ;
V_287:
return - V_179 ;
}
void F_168 ( struct V_1 * V_1 )
{
struct V_139 V_140 ;
unsigned int V_286 ;
F_169 ( & V_1 -> V_6 . V_29 ) ;
V_140 . V_141 = - 1 ;
V_140 . V_142 = - 1 ;
V_140 . V_143 = 0 ;
F_79 ( V_1 , V_199 , & V_140 ) ;
F_169 ( & V_1 -> V_6 . V_80 ) ;
F_69 ( ! F_130 ( & V_1 -> V_6 . V_182 ) ) ;
V_286 = ( V_1 -> V_6 . V_7 + 1 ) * sizeof( struct V_10 ) ;
F_69 ( ! F_170 ( V_1 -> V_6 . V_45 ) ) ;
F_15 ( V_1 -> V_6 . V_45 , V_286 ) ;
F_69 ( ! F_170 ( V_1 -> V_6 . V_44 ) ) ;
F_15 ( V_1 -> V_6 . V_44 , V_286 ) ;
F_69 ( ! F_170 ( V_1 -> V_6 . V_43 ) ) ;
F_15 ( V_1 -> V_6 . V_43 , V_286 ) ;
}
static void F_171 ( struct V_19 * V_20 ,
struct V_290 * V_291 )
{
struct V_292 * V_293 = V_20 -> V_180 ;
T_2 V_8 = F_172 ( V_20 -> V_22 . V_8 ) ;
if ( V_293 )
F_173 ( V_291 , L_3 ,
V_293 -> V_294 , V_293 -> V_295 , V_293 -> V_296 ) ;
switch( V_20 -> V_23 . V_5 ) {
case V_191 :
F_173 ( V_291 , L_4 ,
& V_20 -> V_23 . V_3 . V_192 , & V_20 -> V_22 . V_2 . V_192 ) ;
break;
case V_195 :
F_173 ( V_291 , L_5 ,
V_20 -> V_23 . V_3 . V_197 , V_20 -> V_22 . V_2 . V_197 ) ;
break;
}
F_173 ( V_291 , L_6 , V_8 , V_8 ) ;
}
static void F_174 ( struct V_297 * V_298 , T_9 V_5 ,
struct V_290 * V_291 )
{
const struct V_299 * V_300 ;
const struct V_301 * V_302 ;
switch ( V_5 ) {
case V_191 :
V_300 = F_175 ( V_298 ) ;
F_173 ( V_291 , L_4 ,
& V_300 -> V_3 , & V_300 -> V_2 ) ;
break;
case V_195 :
V_302 = F_176 ( V_298 ) ;
F_173 ( V_291 ,
L_7 ,
& V_302 -> V_3 , & V_302 -> V_2 ,
V_302 -> V_303 [ 0 ] & 0x0f ,
V_302 -> V_303 [ 1 ] ,
V_302 -> V_303 [ 2 ] ) ;
break;
}
}
void F_177 ( struct V_19 * V_20 , int V_304 ,
T_10 V_305 , T_2 V_142 , T_2 V_143 )
{
struct V_290 * V_291 ;
V_291 = F_178 ( L_8 ) ;
if ( V_291 == NULL )
return;
F_179 ( V_305 , V_142 , V_143 , V_291 ) ;
F_171 ( V_20 , V_291 ) ;
F_173 ( V_291 , L_9 , V_304 ) ;
F_180 ( V_291 ) ;
}
void F_55 ( struct V_19 * V_20 , int V_304 ,
T_10 V_305 , T_2 V_142 , T_2 V_143 )
{
struct V_290 * V_291 ;
V_291 = F_178 ( L_10 ) ;
if ( V_291 == NULL )
return;
F_179 ( V_305 , V_142 , V_143 , V_291 ) ;
F_171 ( V_20 , V_291 ) ;
F_173 ( V_291 , L_9 , V_304 ) ;
F_180 ( V_291 ) ;
}
void F_181 ( struct V_19 * V_20 ,
struct V_297 * V_298 )
{
struct V_290 * V_291 ;
T_2 V_8 ;
V_291 = F_178 ( L_11 ) ;
if ( V_291 == NULL )
return;
F_174 ( V_298 , V_20 -> V_23 . V_5 , V_291 ) ;
V_8 = F_172 ( V_20 -> V_22 . V_8 ) ;
F_173 ( V_291 , L_6 , V_8 , V_8 ) ;
F_180 ( V_291 ) ;
}
void F_182 ( struct V_19 * V_20 ,
struct V_297 * V_298 , T_3 V_306 )
{
struct V_290 * V_291 ;
T_2 V_8 ;
V_291 = F_178 ( L_12 ) ;
if ( V_291 == NULL )
return;
F_174 ( V_298 , V_20 -> V_23 . V_5 , V_291 ) ;
V_8 = F_172 ( V_20 -> V_22 . V_8 ) ;
F_173 ( V_291 , L_13 ,
V_8 , V_8 , F_172 ( V_306 ) ) ;
F_180 ( V_291 ) ;
}
void F_183 ( struct V_297 * V_298 , T_9 V_5 )
{
struct V_290 * V_291 ;
V_291 = F_178 ( L_14 ) ;
if ( V_291 == NULL )
return;
F_174 ( V_298 , V_5 , V_291 ) ;
F_180 ( V_291 ) ;
}
void F_184 ( struct V_297 * V_298 , T_9 V_5 ,
T_3 V_307 , T_3 V_306 )
{
struct V_290 * V_291 ;
T_2 V_8 ;
V_291 = F_178 ( L_14 ) ;
if ( V_291 == NULL )
return;
F_174 ( V_298 , V_5 , V_291 ) ;
V_8 = F_172 ( V_307 ) ;
F_173 ( V_291 , L_13 ,
V_8 , V_8 , F_172 ( V_306 ) ) ;
F_180 ( V_291 ) ;
}
void F_185 ( struct V_19 * V_20 ,
struct V_297 * V_298 , T_4 V_9 )
{
struct V_290 * V_291 ;
T_3 V_307 ;
T_3 V_306 ;
V_291 = F_178 ( L_15 ) ;
if ( V_291 == NULL )
return;
F_174 ( V_298 , V_20 -> V_23 . V_5 , V_291 ) ;
if ( F_186 ( V_298 , V_9 , & V_307 , & V_306 ) == 0 ) {
T_2 V_8 = F_172 ( V_307 ) ;
F_173 ( V_291 , L_13 ,
V_8 , V_8 , F_172 ( V_306 ) ) ;
}
F_180 ( V_291 ) ;
}
