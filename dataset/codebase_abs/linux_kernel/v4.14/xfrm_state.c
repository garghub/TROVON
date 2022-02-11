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
int F_36 ( const struct V_58 * type ,
unsigned short V_8 )
{
struct V_46 * V_47 = F_25 ( V_8 ) ;
const struct V_58 * * V_48 ;
int V_49 = 0 ;
if ( F_26 ( V_47 == NULL ) )
return - V_50 ;
V_48 = V_47 -> V_59 ;
F_17 ( & V_60 ) ;
if ( F_27 ( V_48 [ type -> V_12 ] == NULL ) )
V_48 [ type -> V_12 ] = type ;
else
V_49 = - V_53 ;
F_22 ( & V_60 ) ;
F_28 () ;
return V_49 ;
}
int F_37 ( const struct V_58 * type ,
unsigned short V_8 )
{
struct V_46 * V_47 = F_25 ( V_8 ) ;
const struct V_58 * * V_48 ;
int V_49 = 0 ;
if ( F_26 ( V_47 == NULL ) )
return - V_50 ;
V_48 = V_47 -> V_59 ;
F_17 ( & V_60 ) ;
if ( F_26 ( V_48 [ type -> V_12 ] != type ) )
V_49 = - V_54 ;
else
V_48 [ type -> V_12 ] = NULL ;
F_22 ( & V_60 ) ;
F_28 () ;
return V_49 ;
}
static const struct V_58 *
F_38 ( T_5 V_12 , unsigned short V_8 , bool V_61 )
{
struct V_46 * V_47 ;
const struct V_58 * * V_48 ;
const struct V_58 * type ;
V_56:
V_47 = F_25 ( V_8 ) ;
if ( F_26 ( V_47 == NULL ) )
return NULL ;
V_48 = V_47 -> V_59 ;
type = V_48 [ V_12 ] ;
if ( ( type && ! F_32 ( type -> V_57 ) ) )
type = NULL ;
if ( ! type && V_61 ) {
F_33 ( L_2 , V_8 , V_12 ) ;
V_61 = 0 ;
goto V_56;
}
F_28 () ;
return type ;
}
static void F_39 ( const struct V_58 * type )
{
F_35 ( type -> V_57 ) ;
}
int F_40 ( struct V_62 * V_63 , int V_8 )
{
struct V_46 * V_47 ;
struct V_62 * * V_64 ;
int V_49 ;
if ( F_26 ( V_63 -> V_65 >= V_66 ) )
return - V_67 ;
V_47 = F_25 ( V_8 ) ;
if ( F_26 ( V_47 == NULL ) )
return - V_50 ;
V_49 = - V_53 ;
V_64 = V_47 -> V_68 ;
F_17 ( & V_69 ) ;
if ( V_64 [ V_63 -> V_65 ] )
goto V_70;
V_49 = - V_54 ;
if ( ! F_32 ( V_47 -> V_57 ) )
goto V_70;
V_63 -> V_47 = V_47 ;
V_64 [ V_63 -> V_65 ] = V_63 ;
V_49 = 0 ;
V_70:
F_22 ( & V_69 ) ;
F_28 () ;
return V_49 ;
}
int F_41 ( struct V_62 * V_63 , int V_8 )
{
struct V_46 * V_47 ;
struct V_62 * * V_64 ;
int V_49 ;
if ( F_26 ( V_63 -> V_65 >= V_66 ) )
return - V_67 ;
V_47 = F_25 ( V_8 ) ;
if ( F_26 ( V_47 == NULL ) )
return - V_50 ;
V_49 = - V_54 ;
V_64 = V_47 -> V_68 ;
F_17 ( & V_69 ) ;
if ( F_27 ( V_64 [ V_63 -> V_65 ] == V_63 ) ) {
V_64 [ V_63 -> V_65 ] = NULL ;
F_35 ( V_63 -> V_47 -> V_57 ) ;
V_49 = 0 ;
}
F_22 ( & V_69 ) ;
F_28 () ;
return V_49 ;
}
static struct V_62 * F_42 ( unsigned int V_65 , int V_8 )
{
struct V_46 * V_47 ;
struct V_62 * V_63 ;
int V_55 = 0 ;
if ( F_26 ( V_65 >= V_66 ) )
return NULL ;
V_56:
V_47 = F_25 ( V_8 ) ;
if ( F_26 ( V_47 == NULL ) )
return NULL ;
V_63 = F_31 ( V_47 -> V_68 [ V_65 ] ) ;
if ( F_26 ( V_63 && ! F_32 ( V_63 -> V_57 ) ) )
V_63 = NULL ;
F_28 () ;
if ( ! V_63 && ! V_55 ) {
F_33 ( L_3 , V_8 , V_65 ) ;
V_55 = 1 ;
goto V_56;
}
return V_63 ;
}
static void F_43 ( struct V_62 * V_63 )
{
F_35 ( V_63 -> V_57 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_71 ) ;
F_46 ( & V_2 -> V_72 ) ;
F_47 ( V_2 -> V_73 ) ;
F_47 ( V_2 -> V_74 ) ;
F_47 ( V_2 -> V_75 ) ;
F_47 ( V_2 -> V_76 ) ;
F_47 ( V_2 -> V_65 ) ;
F_47 ( V_2 -> V_77 ) ;
F_47 ( V_2 -> V_78 ) ;
F_47 ( V_2 -> V_79 ) ;
if ( V_2 -> V_80 )
F_43 ( V_2 -> V_80 ) ;
if ( V_2 -> V_81 )
F_43 ( V_2 -> V_81 ) ;
if ( V_2 -> V_82 )
F_43 ( V_2 -> V_82 ) ;
if ( V_2 -> V_83 )
F_39 ( V_2 -> V_83 ) ;
if ( V_2 -> type ) {
V_2 -> type -> V_84 ( V_2 ) ;
F_34 ( V_2 -> type ) ;
}
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_47 ( V_2 ) ;
}
static void F_50 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
struct V_13 V_85 ;
F_17 ( & V_86 ) ;
F_51 ( & V_87 , & V_85 ) ;
F_22 ( & V_86 ) ;
F_23 () ;
F_10 (x, tmp, &gc_list, gclist)
F_44 ( V_2 ) ;
}
static enum V_88 F_52 ( struct V_89 * V_90 )
{
struct V_91 * V_92 = F_14 ( V_90 , struct V_91 , V_93 ) ;
struct V_1 * V_2 = F_14 ( V_92 , struct V_1 , V_71 ) ;
unsigned long V_94 = F_53 () ;
long V_95 = V_96 ;
int V_97 = 0 ;
int V_49 = 0 ;
F_54 ( & V_2 -> V_98 ) ;
if ( V_2 -> V_99 . V_100 == V_101 )
goto V_70;
if ( V_2 -> V_99 . V_100 == V_102 )
goto V_103;
if ( V_2 -> V_104 . V_105 ) {
long V_106 = V_2 -> V_104 . V_105 +
V_2 -> V_107 . V_108 - V_94 ;
if ( V_106 <= 0 ) {
if ( V_2 -> V_109 & V_110 ) {
V_2 -> V_107 . V_108 = V_94 - V_2 -> V_111 - 1 ;
V_106 = V_2 -> V_104 . V_105 - V_2 -> V_111 ;
} else
goto V_103;
}
if ( V_106 < V_95 )
V_95 = V_106 ;
}
if ( V_2 -> V_104 . V_112 ) {
long V_106 = V_2 -> V_104 . V_112 +
( V_2 -> V_107 . V_113 ? : V_94 ) - V_94 ;
if ( V_106 <= 0 )
goto V_103;
if ( V_106 < V_95 )
V_95 = V_106 ;
}
if ( V_2 -> V_99 . V_114 )
goto V_115;
if ( V_2 -> V_104 . V_116 ) {
long V_106 = V_2 -> V_104 . V_116 +
V_2 -> V_107 . V_108 - V_94 ;
if ( V_106 <= 0 ) {
V_97 = 1 ;
V_2 -> V_109 &= ~ V_110 ;
} else if ( V_106 < V_95 ) {
V_95 = V_106 ;
V_2 -> V_109 |= V_110 ;
V_2 -> V_111 = V_106 ;
}
}
if ( V_2 -> V_104 . V_117 ) {
long V_106 = V_2 -> V_104 . V_117 +
( V_2 -> V_107 . V_113 ? : V_94 ) - V_94 ;
if ( V_106 <= 0 )
V_97 = 1 ;
else if ( V_106 < V_95 )
V_95 = V_106 ;
}
V_2 -> V_99 . V_114 = V_97 ;
if ( V_97 )
F_55 ( V_2 , 0 , 0 ) ;
V_115:
if ( V_95 != V_96 ) {
F_56 ( & V_2 -> V_71 , F_57 ( V_95 , 0 ) , V_118 ) ;
}
goto V_70;
V_103:
if ( V_2 -> V_99 . V_100 == V_119 && V_2 -> V_22 . V_11 == 0 )
V_2 -> V_99 . V_100 = V_102 ;
V_49 = F_58 ( V_2 ) ;
if ( ! V_49 )
F_55 ( V_2 , 1 , 0 ) ;
F_59 ( V_2 , V_49 ? 0 : 1 , true ) ;
V_70:
F_60 ( & V_2 -> V_98 ) ;
return V_120 ;
}
struct V_1 * F_61 ( struct V_4 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_62 ( sizeof( struct V_1 ) , V_121 ) ;
if ( V_2 ) {
F_63 ( & V_2 -> V_122 , V_4 ) ;
F_64 ( & V_2 -> V_3 , 1 ) ;
F_65 ( & V_2 -> V_123 , 0 ) ;
F_66 ( & V_2 -> V_99 . V_124 ) ;
F_67 ( & V_2 -> V_24 ) ;
F_67 ( & V_2 -> V_25 ) ;
F_67 ( & V_2 -> V_26 ) ;
F_68 ( & V_2 -> V_71 , F_52 ,
V_125 , V_126 ) ;
F_69 ( & V_2 -> V_72 , V_127 ,
( unsigned long ) V_2 ) ;
V_2 -> V_107 . V_108 = F_53 () ;
V_2 -> V_104 . V_128 = V_129 ;
V_2 -> V_104 . V_130 = V_129 ;
V_2 -> V_104 . V_131 = V_129 ;
V_2 -> V_104 . V_132 = V_129 ;
V_2 -> V_133 = 0 ;
V_2 -> V_134 = 0 ;
V_2 -> V_80 = NULL ;
V_2 -> V_81 = NULL ;
F_70 ( & V_2 -> V_98 ) ;
}
return V_2 ;
}
void F_71 ( struct V_1 * V_2 )
{
F_72 ( V_2 -> V_99 . V_100 != V_101 ) ;
F_17 ( & V_86 ) ;
F_73 ( & V_2 -> V_135 , & V_87 ) ;
F_22 ( & V_86 ) ;
F_74 ( & V_136 ) ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_122 ( V_2 ) ;
int V_49 = - V_137 ;
if ( V_2 -> V_99 . V_100 != V_101 ) {
V_2 -> V_99 . V_100 = V_101 ;
F_54 ( & V_4 -> V_9 . V_40 ) ;
F_75 ( & V_2 -> V_99 . V_124 ) ;
F_76 ( & V_2 -> V_24 ) ;
F_76 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_22 . V_11 )
F_76 ( & V_2 -> V_26 ) ;
V_4 -> V_9 . V_138 -- ;
F_60 ( & V_4 -> V_9 . V_40 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
V_49 = 0 ;
}
return V_49 ;
}
int F_79 ( struct V_1 * V_2 )
{
int V_49 ;
F_17 ( & V_2 -> V_98 ) ;
V_49 = F_58 ( V_2 ) ;
F_22 ( & V_2 -> V_98 ) ;
return V_49 ;
}
static inline int
F_80 ( struct V_4 * V_4 , T_5 V_12 , bool V_139 )
{
int V_39 , V_49 = 0 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
F_81 (x, net->xfrm.state_bydst+i, bydst) {
if ( F_82 ( V_2 -> V_22 . V_12 , V_12 ) &&
( V_49 = F_83 ( V_2 ) ) != 0 ) {
F_59 ( V_2 , 0 , V_139 ) ;
return V_49 ;
}
}
}
return V_49 ;
}
static inline int
F_84 ( struct V_4 * V_4 , struct V_140 * V_141 , bool V_139 )
{
int V_39 , V_49 = 0 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
struct V_142 * V_143 ;
F_81 (x, net->xfrm.state_bydst+i, bydst) {
V_143 = & V_2 -> V_143 ;
if ( V_143 -> V_141 == V_141 &&
( V_49 = F_83 ( V_2 ) ) != 0 ) {
F_59 ( V_2 , 0 , V_139 ) ;
return V_49 ;
}
}
}
return V_49 ;
}
static inline int
F_80 ( struct V_4 * V_4 , T_5 V_12 , bool V_139 )
{
return 0 ;
}
static inline int
F_84 ( struct V_4 * V_4 , struct V_140 * V_141 , bool V_139 )
{
return 0 ;
}
int F_85 ( struct V_4 * V_4 , T_5 V_12 , bool V_139 )
{
int V_39 , V_49 = 0 , V_144 = 0 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_49 = F_80 ( V_4 , V_12 , V_139 ) ;
if ( V_49 )
goto V_70;
V_49 = - V_137 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
V_145:
F_81 (x, net->xfrm.state_bydst+i, bydst) {
if ( ! F_86 ( V_2 ) &&
F_82 ( V_2 -> V_22 . V_12 , V_12 ) ) {
F_87 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
V_49 = F_79 ( V_2 ) ;
F_59 ( V_2 , V_49 ? 0 : 1 ,
V_139 ) ;
F_78 ( V_2 ) ;
if ( ! V_49 )
V_144 ++ ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
goto V_145;
}
}
}
V_70:
F_22 ( & V_4 -> V_9 . V_40 ) ;
if ( V_144 ) {
V_49 = 0 ;
F_88 () ;
}
return V_49 ;
}
int F_89 ( struct V_4 * V_4 , struct V_140 * V_141 , bool V_139 )
{
int V_39 , V_49 = 0 , V_144 = 0 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_49 = F_84 ( V_4 , V_141 , V_139 ) ;
if ( V_49 )
goto V_70;
V_49 = - V_137 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
struct V_142 * V_143 ;
V_145:
F_81 (x, net->xfrm.state_bydst+i, bydst) {
V_143 = & V_2 -> V_143 ;
if ( ! F_86 ( V_2 ) && V_143 -> V_141 == V_141 ) {
F_87 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
V_49 = F_79 ( V_2 ) ;
F_59 ( V_2 , V_49 ? 0 : 1 ,
V_139 ) ;
F_78 ( V_2 ) ;
if ( ! V_49 )
V_144 ++ ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
goto V_145;
}
}
}
if ( V_144 )
V_49 = 0 ;
V_70:
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_49 ;
}
void F_90 ( struct V_4 * V_4 , struct V_146 * V_147 )
{
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_147 -> V_148 = V_4 -> V_9 . V_138 ;
V_147 -> V_149 = V_4 -> V_9 . V_10 ;
V_147 -> V_150 = V_151 ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
}
static void
F_91 ( struct V_1 * V_2 , const struct V_152 * V_153 ,
const struct V_154 * V_155 ,
const T_2 * V_5 , const T_2 * V_6 ,
unsigned short V_8 )
{
struct V_46 * V_47 = F_92 ( V_8 ) ;
if ( ! V_47 )
return;
V_47 -> V_156 ( & V_2 -> V_157 , V_153 ) ;
if ( V_8 != V_155 -> V_158 ) {
V_47 = F_92 ( V_155 -> V_158 ) ;
if ( ! V_47 )
return;
}
V_47 -> V_159 ( V_2 , V_155 , V_5 , V_6 ) ;
}
static struct V_1 * F_93 ( struct V_4 * V_4 , T_3 V_160 ,
const T_2 * V_5 ,
T_4 V_11 , T_5 V_12 ,
unsigned short V_8 )
{
unsigned int V_21 = F_7 ( V_4 , V_5 , V_11 , V_12 , V_8 ) ;
struct V_1 * V_2 ;
F_94 (x, net->xfrm.state_byspi + h, byspi) {
if ( V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_22 . V_11 != V_11 ||
V_2 -> V_22 . V_12 != V_12 ||
! F_95 ( & V_2 -> V_22 . V_5 , V_5 , V_8 ) )
continue;
if ( ( V_160 & V_2 -> V_160 . V_161 ) != V_2 -> V_160 . V_162 )
continue;
if ( ! F_1 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_96 ( struct V_4 * V_4 , T_3 V_160 ,
const T_2 * V_5 ,
const T_2 * V_6 ,
T_5 V_12 , unsigned short V_8 )
{
unsigned int V_21 = F_5 ( V_4 , V_5 , V_6 , V_8 ) ;
struct V_1 * V_2 ;
F_94 (x, net->xfrm.state_bysrc + h, bysrc) {
if ( V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_22 . V_12 != V_12 ||
! F_95 ( & V_2 -> V_22 . V_5 , V_5 , V_8 ) ||
! F_95 ( & V_2 -> V_23 . V_6 , V_6 , V_8 ) )
continue;
if ( ( V_160 & V_2 -> V_160 . V_161 ) != V_2 -> V_160 . V_162 )
continue;
if ( ! F_1 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static inline struct V_1 *
F_97 ( struct V_1 * V_2 , int V_163 , int V_8 )
{
struct V_4 * V_4 = V_122 ( V_2 ) ;
T_3 V_160 = V_2 -> V_160 . V_162 & V_2 -> V_160 . V_161 ;
if ( V_163 )
return F_93 ( V_4 , V_160 , & V_2 -> V_22 . V_5 ,
V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 , V_8 ) ;
else
return F_96 ( V_4 , V_160 ,
& V_2 -> V_22 . V_5 ,
& V_2 -> V_23 . V_6 ,
V_2 -> V_22 . V_12 , V_8 ) ;
}
static void F_98 ( struct V_4 * V_4 , int V_164 )
{
if ( V_164 &&
( V_4 -> V_9 . V_10 + 1 ) < V_151 &&
V_4 -> V_9 . V_138 > V_4 -> V_9 . V_10 )
F_74 ( & V_4 -> V_9 . V_29 ) ;
}
static void F_99 ( struct V_165 * V_166 , struct V_1 * V_2 ,
const struct V_152 * V_153 , unsigned short V_8 ,
struct V_1 * * V_167 , int * V_168 ,
int * error )
{
if ( V_2 -> V_99 . V_100 == V_169 ) {
if ( ( V_2 -> V_157 . V_8 &&
! F_100 ( & V_2 -> V_157 , V_153 , V_2 -> V_157 . V_8 ) ) ||
! F_101 ( V_2 , V_166 , V_153 ) )
return;
if ( ! * V_167 ||
( * V_167 ) -> V_99 . V_114 > V_2 -> V_99 . V_114 ||
( ( * V_167 ) -> V_99 . V_114 == V_2 -> V_99 . V_114 &&
( * V_167 ) -> V_107 . V_108 < V_2 -> V_107 . V_108 ) )
* V_167 = V_2 ;
} else if ( V_2 -> V_99 . V_100 == V_119 ) {
* V_168 = 1 ;
} else if ( V_2 -> V_99 . V_100 == V_170 ||
V_2 -> V_99 . V_100 == V_102 ) {
if ( F_100 ( & V_2 -> V_157 , V_153 , V_2 -> V_157 . V_8 ) &&
F_101 ( V_2 , V_166 , V_153 ) )
* error = - V_137 ;
}
}
struct V_1 *
F_102 ( const T_2 * V_5 , const T_2 * V_6 ,
const struct V_152 * V_153 , struct V_154 * V_155 ,
struct V_165 * V_166 , int * V_49 ,
unsigned short V_8 )
{
static T_2 V_171 = { } ;
struct V_4 * V_4 = F_103 ( V_166 ) ;
unsigned int V_21 , V_172 ;
struct V_1 * V_2 , * V_173 , * V_174 ;
int V_175 = 0 ;
int error = 0 ;
struct V_1 * V_167 = NULL ;
T_3 V_160 = V_166 -> V_160 . V_162 & V_166 -> V_160 . V_161 ;
unsigned short V_158 = V_155 -> V_158 ;
unsigned int V_176 ;
struct V_177 V_178 ;
V_174 = NULL ;
V_176 = F_104 ( & V_41 ) ;
F_105 () ;
V_21 = F_3 ( V_4 , V_5 , V_6 , V_155 -> V_7 , V_158 ) ;
F_94 (x, net->xfrm.state_bydst + h, bydst) {
if ( V_2 -> V_23 . V_8 == V_158 &&
V_2 -> V_23 . V_7 == V_155 -> V_7 &&
( V_160 & V_2 -> V_160 . V_161 ) == V_2 -> V_160 . V_162 &&
! ( V_2 -> V_23 . V_179 & V_180 ) &&
F_106 ( V_2 , V_5 , V_6 , V_158 ) &&
V_155 -> V_63 == V_2 -> V_23 . V_63 &&
V_155 -> V_22 . V_12 == V_2 -> V_22 . V_12 &&
( V_155 -> V_22 . V_11 == V_2 -> V_22 . V_11 || ! V_155 -> V_22 . V_11 ) )
F_99 ( V_166 , V_2 , V_153 , V_158 ,
& V_167 , & V_175 , & error ) ;
}
if ( V_167 || V_175 )
goto V_181;
V_172 = F_3 ( V_4 , V_5 , & V_171 , V_155 -> V_7 , V_158 ) ;
F_94 (x, net->xfrm.state_bydst + h_wildcard, bydst) {
if ( V_2 -> V_23 . V_8 == V_158 &&
V_2 -> V_23 . V_7 == V_155 -> V_7 &&
( V_160 & V_2 -> V_160 . V_161 ) == V_2 -> V_160 . V_162 &&
! ( V_2 -> V_23 . V_179 & V_180 ) &&
F_95 ( & V_2 -> V_22 . V_5 , V_5 , V_158 ) &&
V_155 -> V_63 == V_2 -> V_23 . V_63 &&
V_155 -> V_22 . V_12 == V_2 -> V_22 . V_12 &&
( V_155 -> V_22 . V_11 == V_2 -> V_22 . V_11 || ! V_155 -> V_22 . V_11 ) )
F_99 ( V_166 , V_2 , V_153 , V_158 ,
& V_167 , & V_175 , & error ) ;
}
V_181:
V_2 = V_167 ;
if ( ! V_2 && ! error && ! V_175 ) {
if ( V_155 -> V_22 . V_11 &&
( V_173 = F_93 ( V_4 , V_160 , V_5 , V_155 -> V_22 . V_11 ,
V_155 -> V_22 . V_12 , V_158 ) ) != NULL ) {
V_174 = V_173 ;
error = - V_53 ;
goto V_70;
}
V_178 . V_4 = V_4 ;
if ( ! F_107 ( & V_178 ) ) {
error = - V_137 ;
goto V_70;
}
V_2 = F_61 ( V_4 ) ;
if ( V_2 == NULL ) {
error = - V_182 ;
goto V_70;
}
F_91 ( V_2 , V_153 , V_155 , V_5 , V_6 , V_8 ) ;
memcpy ( & V_2 -> V_160 , & V_166 -> V_160 , sizeof( V_2 -> V_160 ) ) ;
error = F_108 ( V_2 , V_166 -> V_183 , V_153 -> V_184 ) ;
if ( error ) {
V_2 -> V_99 . V_100 = V_101 ;
V_174 = V_2 ;
V_2 = NULL ;
goto V_70;
}
if ( F_109 ( V_2 , V_155 , V_166 ) == 0 ) {
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 -> V_99 . V_100 = V_119 ;
F_110 ( & V_2 -> V_99 . V_124 , & V_4 -> V_9 . V_185 ) ;
F_11 ( & V_2 -> V_24 , V_4 -> V_9 . V_42 + V_21 ) ;
V_21 = F_5 ( V_4 , V_5 , V_6 , V_158 ) ;
F_11 ( & V_2 -> V_25 , V_4 -> V_9 . V_43 + V_21 ) ;
if ( V_2 -> V_22 . V_11 ) {
V_21 = F_7 ( V_4 , & V_2 -> V_22 . V_5 , V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 , V_158 ) ;
F_11 ( & V_2 -> V_26 , V_4 -> V_9 . V_44 + V_21 ) ;
}
V_2 -> V_104 . V_105 = V_4 -> V_9 . V_186 ;
F_56 ( & V_2 -> V_71 , F_57 ( V_4 -> V_9 . V_186 , 0 ) , V_118 ) ;
V_4 -> V_9 . V_138 ++ ;
F_98 ( V_4 , V_2 -> V_24 . V_95 != NULL ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
} else {
V_2 -> V_99 . V_100 = V_101 ;
V_174 = V_2 ;
V_2 = NULL ;
error = - V_137 ;
}
}
V_70:
if ( V_2 ) {
if ( ! F_1 ( V_2 ) ) {
* V_49 = - V_187 ;
V_2 = NULL ;
}
} else {
* V_49 = V_175 ? - V_187 : error ;
}
F_28 () ;
if ( V_174 )
F_78 ( V_174 ) ;
if ( F_111 ( & V_41 , V_176 ) ) {
* V_49 = - V_187 ;
if ( V_2 ) {
F_78 ( V_2 ) ;
V_2 = NULL ;
}
}
return V_2 ;
}
struct V_1 *
F_112 ( struct V_4 * V_4 , T_3 V_160 ,
T_2 * V_5 , T_2 * V_6 ,
unsigned short V_8 , T_5 V_63 , T_5 V_12 , T_3 V_7 )
{
unsigned int V_21 ;
struct V_1 * V_188 = NULL , * V_2 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_21 = F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 ) ;
F_81 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_8 == V_8 &&
V_2 -> V_23 . V_7 == V_7 &&
( V_160 & V_2 -> V_160 . V_161 ) == V_2 -> V_160 . V_162 &&
! ( V_2 -> V_23 . V_179 & V_180 ) &&
F_106 ( V_2 , V_5 , V_6 , V_8 ) &&
V_63 == V_2 -> V_23 . V_63 &&
V_12 == V_2 -> V_22 . V_12 &&
V_2 -> V_99 . V_100 == V_169 ) {
V_188 = V_2 ;
break;
}
}
if ( V_188 )
F_87 ( V_188 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_188 ;
}
struct V_1 * F_113 ( struct V_4 * V_4 , T_4 V_11 ,
unsigned short V_8 )
{
struct V_1 * V_2 ;
struct V_189 * V_190 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_114 (w, &net->xfrm.state_all, all) {
V_2 = F_14 ( V_190 , struct V_1 , V_99 ) ;
if ( V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_22 . V_11 != V_11 )
continue;
F_87 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
F_22 ( & V_4 -> V_9 . V_40 ) ;
return NULL ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_122 ( V_2 ) ;
unsigned int V_21 ;
F_110 ( & V_2 -> V_99 . V_124 , & V_4 -> V_9 . V_185 ) ;
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
F_56 ( & V_2 -> V_71 , F_57 ( 1 , 0 ) , V_118 ) ;
if ( V_2 -> V_133 )
F_116 ( & V_2 -> V_72 , V_191 + V_2 -> V_133 ) ;
V_4 -> V_9 . V_138 ++ ;
F_98 ( V_4 , V_2 -> V_24 . V_95 != NULL ) ;
}
static void F_117 ( struct V_1 * V_192 )
{
struct V_4 * V_4 = V_122 ( V_192 ) ;
unsigned short V_8 = V_192 -> V_23 . V_8 ;
T_3 V_7 = V_192 -> V_23 . V_7 ;
struct V_1 * V_2 ;
unsigned int V_21 ;
T_3 V_160 = V_192 -> V_160 . V_162 & V_192 -> V_160 . V_161 ;
V_21 = F_3 ( V_4 , & V_192 -> V_22 . V_5 , & V_192 -> V_23 . V_6 , V_7 , V_8 ) ;
F_81 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_8 == V_8 &&
V_2 -> V_23 . V_7 == V_7 &&
( V_160 & V_2 -> V_160 . V_161 ) == V_2 -> V_160 . V_162 &&
F_95 ( & V_2 -> V_22 . V_5 , & V_192 -> V_22 . V_5 , V_8 ) &&
F_95 ( & V_2 -> V_23 . V_6 , & V_192 -> V_23 . V_6 , V_8 ) )
V_2 -> V_193 ++ ;
}
}
void F_118 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_122 ( V_2 ) ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_117 ( V_2 ) ;
F_115 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
}
static struct V_1 * F_119 ( struct V_4 * V_4 ,
const struct V_194 * V_161 ,
unsigned short V_8 , T_5 V_63 ,
T_3 V_7 , T_5 V_12 ,
const T_2 * V_5 ,
const T_2 * V_6 ,
int V_195 )
{
unsigned int V_21 = F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 ) ;
struct V_1 * V_2 ;
T_3 V_160 = V_161 -> V_162 & V_161 -> V_161 ;
F_81 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_7 != V_7 ||
V_2 -> V_23 . V_63 != V_63 ||
V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_99 . V_100 != V_119 ||
V_2 -> V_22 . V_11 != 0 ||
V_2 -> V_22 . V_12 != V_12 ||
( V_160 & V_2 -> V_160 . V_161 ) != V_2 -> V_160 . V_162 ||
! F_95 ( & V_2 -> V_22 . V_5 , V_5 , V_8 ) ||
! F_95 ( & V_2 -> V_23 . V_6 , V_6 , V_8 ) )
continue;
F_87 ( V_2 ) ;
return V_2 ;
}
if ( ! V_195 )
return NULL ;
V_2 = F_61 ( V_4 ) ;
if ( F_27 ( V_2 ) ) {
switch ( V_8 ) {
case V_196 :
V_2 -> V_157 . V_5 . V_197 = V_5 -> V_197 ;
V_2 -> V_157 . V_6 . V_197 = V_6 -> V_197 ;
V_2 -> V_157 . V_198 = 32 ;
V_2 -> V_157 . V_199 = 32 ;
V_2 -> V_23 . V_6 . V_197 = V_6 -> V_197 ;
V_2 -> V_22 . V_5 . V_197 = V_5 -> V_197 ;
break;
case V_200 :
V_2 -> V_157 . V_5 . V_201 = V_5 -> V_201 ;
V_2 -> V_157 . V_6 . V_201 = V_6 -> V_201 ;
V_2 -> V_157 . V_198 = 128 ;
V_2 -> V_157 . V_199 = 128 ;
V_2 -> V_23 . V_6 . V_201 = V_6 -> V_201 ;
V_2 -> V_22 . V_5 . V_201 = V_5 -> V_201 ;
break;
}
V_2 -> V_99 . V_100 = V_119 ;
V_2 -> V_22 . V_12 = V_12 ;
V_2 -> V_23 . V_8 = V_8 ;
V_2 -> V_23 . V_63 = V_63 ;
V_2 -> V_23 . V_7 = V_7 ;
V_2 -> V_160 . V_162 = V_161 -> V_162 ;
V_2 -> V_160 . V_161 = V_161 -> V_161 ;
V_2 -> V_104 . V_105 = V_4 -> V_9 . V_186 ;
F_87 ( V_2 ) ;
F_56 ( & V_2 -> V_71 , F_57 ( V_4 -> V_9 . V_186 , 0 ) , V_118 ) ;
F_110 ( & V_2 -> V_99 . V_124 , & V_4 -> V_9 . V_185 ) ;
F_11 ( & V_2 -> V_24 , V_4 -> V_9 . V_42 + V_21 ) ;
V_21 = F_5 ( V_4 , V_5 , V_6 , V_8 ) ;
F_11 ( & V_2 -> V_25 , V_4 -> V_9 . V_43 + V_21 ) ;
V_4 -> V_9 . V_138 ++ ;
F_98 ( V_4 , V_2 -> V_24 . V_95 != NULL ) ;
}
return V_2 ;
}
int F_120 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_122 ( V_2 ) ;
struct V_1 * V_202 , * V_174 ;
int V_8 ;
int V_49 ;
T_3 V_160 = V_2 -> V_160 . V_162 & V_2 -> V_160 . V_161 ;
int V_163 = F_82 ( V_2 -> V_22 . V_12 , V_203 ) ;
V_8 = V_2 -> V_23 . V_8 ;
V_174 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_202 = F_97 ( V_2 , V_163 , V_8 ) ;
if ( V_202 ) {
V_174 = V_202 ;
V_202 = NULL ;
V_49 = - V_53 ;
goto V_70;
}
if ( V_163 && V_2 -> V_99 . V_204 ) {
V_202 = F_121 ( V_4 , V_160 , V_2 -> V_99 . V_204 ) ;
if ( V_202 && ( ( V_202 -> V_22 . V_12 != V_2 -> V_22 . V_12 ) ||
! F_95 ( & V_202 -> V_22 . V_5 , & V_2 -> V_22 . V_5 , V_8 ) ) ) {
V_174 = V_202 ;
V_202 = NULL ;
}
}
if ( V_163 && ! V_202 )
V_202 = F_119 ( V_4 , & V_2 -> V_160 , V_8 , V_2 -> V_23 . V_63 ,
V_2 -> V_23 . V_7 , V_2 -> V_22 . V_12 ,
& V_2 -> V_22 . V_5 , & V_2 -> V_23 . V_6 , 0 ) ;
F_117 ( V_2 ) ;
F_115 ( V_2 ) ;
V_49 = 0 ;
V_70:
F_22 ( & V_4 -> V_9 . V_40 ) ;
if ( V_202 ) {
F_79 ( V_202 ) ;
F_78 ( V_202 ) ;
}
if ( V_174 )
F_78 ( V_174 ) ;
return V_49 ;
}
static struct V_1 * F_122 ( struct V_1 * V_205 ,
struct V_206 * V_65 )
{
struct V_4 * V_4 = V_122 ( V_205 ) ;
struct V_1 * V_2 = F_61 ( V_4 ) ;
if ( ! V_2 )
goto V_70;
memcpy ( & V_2 -> V_22 , & V_205 -> V_22 , sizeof( V_2 -> V_22 ) ) ;
memcpy ( & V_2 -> V_157 , & V_205 -> V_157 , sizeof( V_2 -> V_157 ) ) ;
memcpy ( & V_2 -> V_104 , & V_205 -> V_104 , sizeof( V_2 -> V_104 ) ) ;
V_2 -> V_23 . V_63 = V_205 -> V_23 . V_63 ;
V_2 -> V_23 . V_207 = V_205 -> V_23 . V_207 ;
V_2 -> V_23 . V_7 = V_205 -> V_23 . V_7 ;
V_2 -> V_23 . V_8 = V_205 -> V_23 . V_8 ;
V_2 -> V_23 . V_6 = V_205 -> V_23 . V_6 ;
if ( V_205 -> V_74 ) {
V_2 -> V_74 = F_123 ( V_205 -> V_74 ) ;
if ( ! V_2 -> V_74 )
goto error;
}
V_2 -> V_23 . V_208 = V_205 -> V_23 . V_208 ;
if ( V_205 -> V_73 ) {
V_2 -> V_73 = F_124 ( V_205 -> V_73 ) ;
if ( ! V_2 -> V_73 )
goto error;
}
if ( V_205 -> V_75 ) {
V_2 -> V_75 = F_125 ( V_205 -> V_75 ) ;
if ( ! V_2 -> V_75 )
goto error;
}
V_2 -> V_23 . V_209 = V_205 -> V_23 . V_209 ;
if ( V_205 -> V_76 ) {
V_2 -> V_76 = F_125 ( V_205 -> V_76 ) ;
if ( ! V_2 -> V_76 )
goto error;
}
V_2 -> V_23 . V_210 = V_205 -> V_23 . V_210 ;
if ( V_65 || V_205 -> V_65 ) {
if ( V_65 )
V_2 -> V_65 = F_126 ( V_65 , sizeof( * V_2 -> V_65 ) ,
V_211 ) ;
else
V_2 -> V_65 = F_126 ( V_205 -> V_65 , sizeof( * V_2 -> V_65 ) ,
V_211 ) ;
if ( ! V_2 -> V_65 )
goto error;
}
if ( V_205 -> V_77 ) {
V_2 -> V_77 = F_126 ( V_205 -> V_77 , sizeof( * V_2 -> V_77 ) ,
V_211 ) ;
if ( ! V_2 -> V_77 )
goto error;
}
if ( V_205 -> V_78 ) {
if ( F_127 ( V_2 , V_205 ) )
goto error;
}
memcpy ( & V_2 -> V_160 , & V_205 -> V_160 , sizeof( V_2 -> V_160 ) ) ;
if ( F_128 ( V_2 ) < 0 )
goto error;
V_2 -> V_23 . V_179 = V_205 -> V_23 . V_179 ;
V_2 -> V_23 . V_212 = V_205 -> V_23 . V_212 ;
V_2 -> V_213 = V_205 -> V_213 ;
V_2 -> V_134 = V_205 -> V_134 ;
V_2 -> V_133 = V_205 -> V_133 ;
V_2 -> V_107 . V_108 = V_205 -> V_107 . V_108 ;
V_2 -> V_99 . V_100 = V_205 -> V_99 . V_100 ;
V_2 -> V_99 . V_204 = V_205 -> V_99 . V_204 ;
V_2 -> V_214 = V_205 -> V_214 ;
V_2 -> V_215 = V_205 -> V_215 ;
return V_2 ;
error:
F_78 ( V_2 ) ;
V_70:
return NULL ;
}
struct V_1 * F_129 ( struct V_216 * V_161 , struct V_4 * V_4 )
{
unsigned int V_21 ;
struct V_1 * V_2 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( V_161 -> V_7 ) {
V_21 = F_3 ( V_4 , & V_161 -> V_217 , & V_161 -> V_218 ,
V_161 -> V_7 , V_161 -> V_219 ) ;
F_81 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_63 != V_161 -> V_63 ||
V_2 -> V_22 . V_12 != V_161 -> V_12 )
continue;
if ( V_161 -> V_7 && V_2 -> V_23 . V_7 != V_161 -> V_7 )
continue;
if ( ! F_95 ( & V_2 -> V_22 . V_5 , & V_161 -> V_217 ,
V_161 -> V_219 ) ||
! F_95 ( & V_2 -> V_23 . V_6 , & V_161 -> V_218 ,
V_161 -> V_219 ) )
continue;
F_87 ( V_2 ) ;
break;
}
} else {
V_21 = F_5 ( V_4 , & V_161 -> V_217 , & V_161 -> V_218 ,
V_161 -> V_219 ) ;
F_81 (x, net->xfrm.state_bysrc+h, bysrc) {
if ( V_2 -> V_23 . V_63 != V_161 -> V_63 ||
V_2 -> V_22 . V_12 != V_161 -> V_12 )
continue;
if ( ! F_95 ( & V_2 -> V_22 . V_5 , & V_161 -> V_217 ,
V_161 -> V_219 ) ||
! F_95 ( & V_2 -> V_23 . V_6 , & V_161 -> V_218 ,
V_161 -> V_219 ) )
continue;
F_87 ( V_2 ) ;
break;
}
}
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
struct V_1 * F_130 ( struct V_1 * V_2 ,
struct V_216 * V_161 ,
struct V_206 * V_65 )
{
struct V_1 * V_220 ;
V_220 = F_122 ( V_2 , V_65 ) ;
if ( ! V_220 )
return NULL ;
memcpy ( & V_220 -> V_22 . V_5 , & V_161 -> V_221 , sizeof( V_220 -> V_22 . V_5 ) ) ;
memcpy ( & V_220 -> V_23 . V_6 , & V_161 -> V_222 , sizeof( V_220 -> V_23 . V_6 ) ) ;
if ( F_95 ( & V_2 -> V_22 . V_5 , & V_161 -> V_221 , V_161 -> V_223 ) ) {
F_118 ( V_220 ) ;
} else {
if ( F_120 ( V_220 ) < 0 )
goto error;
}
return V_220 ;
error:
F_78 ( V_220 ) ;
return NULL ;
}
int F_131 ( struct V_1 * V_2 )
{
struct V_1 * V_202 , * V_174 ;
int V_49 ;
int V_163 = F_82 ( V_2 -> V_22 . V_12 , V_203 ) ;
struct V_4 * V_4 = V_122 ( V_2 ) ;
V_174 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_202 = F_97 ( V_2 , V_163 , V_2 -> V_23 . V_8 ) ;
V_49 = - V_137 ;
if ( ! V_202 )
goto V_70;
if ( F_86 ( V_202 ) ) {
V_174 = V_202 ;
V_49 = - V_53 ;
goto V_70;
}
if ( V_202 -> V_99 . V_100 == V_119 ) {
F_115 ( V_2 ) ;
V_2 = NULL ;
}
V_49 = 0 ;
V_70:
F_22 ( & V_4 -> V_9 . V_40 ) ;
if ( V_174 )
F_78 ( V_174 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_2 ) {
F_79 ( V_202 ) ;
F_78 ( V_202 ) ;
return 0 ;
}
V_49 = - V_67 ;
F_17 ( & V_202 -> V_98 ) ;
if ( F_27 ( V_202 -> V_99 . V_100 == V_169 ) ) {
if ( V_2 -> V_65 && V_202 -> V_65 )
memcpy ( V_202 -> V_65 , V_2 -> V_65 , sizeof( * V_202 -> V_65 ) ) ;
if ( V_2 -> V_77 && V_202 -> V_77 ) {
memcpy ( V_202 -> V_77 , V_2 -> V_77 , sizeof( * V_202 -> V_77 ) ) ;
}
if ( ! V_163 && memcmp ( & V_202 -> V_157 , & V_2 -> V_157 , sizeof( V_202 -> V_157 ) ) )
memcpy ( & V_202 -> V_157 , & V_2 -> V_157 , sizeof( V_202 -> V_157 ) ) ;
memcpy ( & V_202 -> V_104 , & V_2 -> V_104 , sizeof( V_202 -> V_104 ) ) ;
V_202 -> V_99 . V_114 = 0 ;
F_56 ( & V_202 -> V_71 , F_57 ( 1 , 0 ) , V_118 ) ;
if ( V_202 -> V_107 . V_113 )
F_132 ( V_202 ) ;
V_49 = 0 ;
V_2 -> V_99 . V_100 = V_101 ;
F_133 ( V_2 ) ;
}
F_22 ( & V_202 -> V_98 ) ;
F_78 ( V_202 ) ;
return V_49 ;
}
int F_132 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_107 . V_113 )
V_2 -> V_107 . V_113 = F_53 () ;
if ( V_2 -> V_107 . V_224 >= V_2 -> V_104 . V_131 ||
V_2 -> V_107 . V_225 >= V_2 -> V_104 . V_132 ) {
V_2 -> V_99 . V_100 = V_102 ;
F_56 ( & V_2 -> V_71 , 0 , V_118 ) ;
return - V_67 ;
}
if ( ! V_2 -> V_99 . V_114 &&
( V_2 -> V_107 . V_224 >= V_2 -> V_104 . V_128 ||
V_2 -> V_107 . V_225 >= V_2 -> V_104 . V_130 ) ) {
V_2 -> V_99 . V_114 = 1 ;
F_55 ( V_2 , 0 , 0 ) ;
}
return 0 ;
}
struct V_1 *
F_134 ( struct V_4 * V_4 , T_3 V_160 , const T_2 * V_5 , T_4 V_11 ,
T_5 V_12 , unsigned short V_8 )
{
struct V_1 * V_2 ;
F_105 () ;
V_2 = F_93 ( V_4 , V_160 , V_5 , V_11 , V_12 , V_8 ) ;
F_28 () ;
return V_2 ;
}
struct V_1 *
F_135 ( struct V_4 * V_4 , T_3 V_160 ,
const T_2 * V_5 , const T_2 * V_6 ,
T_5 V_12 , unsigned short V_8 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 = F_96 ( V_4 , V_160 , V_5 , V_6 , V_12 , V_8 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
struct V_1 *
F_136 ( struct V_4 * V_4 , const struct V_194 * V_160 , T_5 V_63 , T_3 V_7 ,
T_5 V_12 , const T_2 * V_5 ,
const T_2 * V_6 , int V_195 , unsigned short V_8 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 = F_119 ( V_4 , V_160 , V_8 , V_63 , V_7 , V_12 , V_5 , V_6 , V_195 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
int
F_137 ( struct V_154 * * V_226 , struct V_154 * * V_227 , int V_228 ,
unsigned short V_8 , struct V_4 * V_4 )
{
int V_39 ;
int V_49 = 0 ;
struct V_46 * V_47 = F_25 ( V_8 ) ;
if ( ! V_47 )
return - V_50 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( V_47 -> V_229 )
V_49 = V_47 -> V_229 ( V_226 , V_227 , V_228 ) ;
else
for ( V_39 = 0 ; V_39 < V_228 ; V_39 ++ )
V_226 [ V_39 ] = V_227 [ V_39 ] ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
F_28 () ;
return V_49 ;
}
int
F_138 ( struct V_1 * * V_226 , struct V_1 * * V_227 , int V_228 ,
unsigned short V_8 )
{
int V_39 ;
int V_49 = 0 ;
struct V_46 * V_47 = F_25 ( V_8 ) ;
struct V_4 * V_4 = V_122 ( * V_227 ) ;
if ( ! V_47 )
return - V_50 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( V_47 -> V_230 )
V_49 = V_47 -> V_230 ( V_226 , V_227 , V_228 ) ;
else
for ( V_39 = 0 ; V_39 < V_228 ; V_39 ++ )
V_226 [ V_39 ] = V_227 [ V_39 ] ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
F_28 () ;
return V_49 ;
}
static struct V_1 * F_121 ( struct V_4 * V_4 , T_3 V_160 , T_3 V_204 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
F_81 (x, net->xfrm.state_bydst+i, bydst) {
if ( V_2 -> V_99 . V_204 == V_204 &&
( V_160 & V_2 -> V_160 . V_161 ) == V_2 -> V_160 . V_162 &&
V_2 -> V_99 . V_100 == V_119 ) {
F_87 ( V_2 ) ;
return V_2 ;
}
}
}
return NULL ;
}
struct V_1 * F_139 ( struct V_4 * V_4 , T_3 V_160 , T_3 V_204 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 = F_121 ( V_4 , V_160 , V_204 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
T_3 F_140 ( void )
{
T_3 V_231 ;
static T_6 V_232 ;
do {
V_231 = F_141 ( & V_232 ) ;
} while ( ! V_231 );
return V_231 ;
}
int F_142 ( T_5 V_12 , T_3 V_233 , T_3 V_234 )
{
switch ( V_12 ) {
case V_235 :
case V_236 :
break;
case V_237 :
if ( V_234 >= 0x10000 )
return - V_67 ;
break;
default:
return - V_67 ;
}
if ( V_233 > V_234 )
return - V_67 ;
return 0 ;
}
int F_143 ( struct V_1 * V_2 , T_3 V_238 , T_3 V_239 )
{
struct V_4 * V_4 = V_122 ( V_2 ) ;
unsigned int V_21 ;
struct V_1 * V_173 ;
int V_49 = - V_54 ;
T_4 V_240 = F_144 ( V_238 ) ;
T_4 V_241 = F_144 ( V_239 ) ;
T_3 V_160 = V_2 -> V_160 . V_162 & V_2 -> V_160 . V_161 ;
F_17 ( & V_2 -> V_98 ) ;
if ( V_2 -> V_99 . V_100 == V_101 )
goto V_242;
V_49 = 0 ;
if ( V_2 -> V_22 . V_11 )
goto V_242;
V_49 = - V_54 ;
if ( V_240 == V_241 ) {
V_173 = F_134 ( V_4 , V_160 , & V_2 -> V_22 . V_5 , V_240 , V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ) ;
if ( V_173 ) {
F_78 ( V_173 ) ;
goto V_242;
}
V_2 -> V_22 . V_11 = V_240 ;
} else {
T_3 V_11 = 0 ;
for ( V_21 = 0 ; V_21 < V_239 - V_238 + 1 ; V_21 ++ ) {
V_11 = V_238 + F_145 () % ( V_239 - V_238 + 1 ) ;
V_173 = F_134 ( V_4 , V_160 , & V_2 -> V_22 . V_5 , F_144 ( V_11 ) , V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ) ;
if ( V_173 == NULL ) {
V_2 -> V_22 . V_11 = F_144 ( V_11 ) ;
break;
}
F_78 ( V_173 ) ;
}
}
if ( V_2 -> V_22 . V_11 ) {
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_21 = F_7 ( V_4 , & V_2 -> V_22 . V_5 , V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ) ;
F_11 ( & V_2 -> V_26 , V_4 -> V_9 . V_44 + V_21 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
V_49 = 0 ;
}
V_242:
F_22 ( & V_2 -> V_98 ) ;
return V_49 ;
}
static bool F_146 ( struct V_1 * V_2 ,
struct V_243 * V_244 )
{
if ( V_244 ) {
if ( ( V_244 -> V_8 == V_196 ||
V_244 -> V_8 == V_200 ) &&
V_2 -> V_23 . V_8 != V_244 -> V_8 )
return false ;
return F_147 ( & V_2 -> V_23 . V_6 , & V_244 -> V_6 ,
V_244 -> V_245 ) &&
F_147 ( & V_2 -> V_22 . V_5 , & V_244 -> V_5 ,
V_244 -> V_246 ) ;
}
return true ;
}
int V_189 ( struct V_4 * V_4 , struct V_189 * V_247 ,
int (* F_148)( struct V_1 * , int , void * ) ,
void * V_248 )
{
struct V_1 * V_100 ;
struct V_189 * V_2 ;
int V_49 = 0 ;
if ( V_247 -> V_204 != 0 && F_149 ( & V_247 -> V_124 ) )
return 0 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( F_149 ( & V_247 -> V_124 ) )
V_2 = F_150 ( & V_4 -> V_9 . V_185 , struct V_189 , V_124 ) ;
else
V_2 = F_150 ( & V_247 -> V_124 , struct V_189 , V_124 ) ;
F_151 (x, &net->xfrm.state_all, all) {
if ( V_2 -> V_100 == V_101 )
continue;
V_100 = F_14 ( V_2 , struct V_1 , V_99 ) ;
if ( ! F_82 ( V_100 -> V_22 . V_12 , V_247 -> V_12 ) )
continue;
if ( ! F_146 ( V_100 , V_247 -> V_244 ) )
continue;
V_49 = F_148 ( V_100 , V_247 -> V_204 , V_248 ) ;
if ( V_49 ) {
F_152 ( & V_247 -> V_124 , & V_2 -> V_124 ) ;
goto V_70;
}
V_247 -> V_204 ++ ;
}
if ( V_247 -> V_204 == 0 ) {
V_49 = - V_54 ;
goto V_70;
}
F_153 ( & V_247 -> V_124 ) ;
V_70:
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_49 ;
}
void F_154 ( struct V_189 * V_247 , T_5 V_12 ,
struct V_243 * V_244 )
{
F_66 ( & V_247 -> V_124 ) ;
V_247 -> V_12 = V_12 ;
V_247 -> V_100 = V_101 ;
V_247 -> V_204 = 0 ;
V_247 -> V_244 = V_244 ;
}
void F_155 ( struct V_189 * V_247 , struct V_4 * V_4 )
{
F_47 ( V_247 -> V_244 ) ;
if ( F_149 ( & V_247 -> V_124 ) )
return;
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_75 ( & V_247 -> V_124 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
}
static void V_127 ( unsigned long V_248 )
{
struct V_1 * V_2 = (struct V_1 * ) V_248 ;
F_54 ( & V_2 -> V_98 ) ;
if ( V_2 -> V_99 . V_100 == V_169 ) {
if ( F_156 ( V_122 ( V_2 ) ) )
V_2 -> V_249 -> V_250 ( V_2 , V_251 ) ;
else
V_2 -> V_109 |= V_252 ;
}
F_60 ( & V_2 -> V_98 ) ;
}
void F_157 ( struct V_165 * V_253 , int V_254 , const struct V_177 * V_178 )
{
struct V_255 * V_99 ;
F_105 () ;
F_158 (km, &xfrm_km_list, list)
if ( V_99 -> V_256 )
V_99 -> V_256 ( V_253 , V_254 , V_178 ) ;
F_28 () ;
}
void F_159 ( struct V_1 * V_2 , const struct V_177 * V_178 )
{
struct V_255 * V_99 ;
F_105 () ;
F_158 (km, &xfrm_km_list, list)
if ( V_99 -> V_250 )
V_99 -> V_250 ( V_2 , V_178 ) ;
F_28 () ;
}
void F_55 ( struct V_1 * V_2 , int V_257 , T_3 V_258 )
{
struct V_177 V_178 ;
V_178 . V_248 . V_257 = V_257 ;
V_178 . V_258 = V_258 ;
V_178 . V_259 = V_260 ;
F_159 ( V_2 , & V_178 ) ;
}
int F_109 ( struct V_1 * V_2 , struct V_154 * V_261 , struct V_165 * V_166 )
{
int V_49 = - V_67 , V_262 ;
struct V_255 * V_99 ;
F_105 () ;
F_158 (km, &xfrm_km_list, list) {
V_262 = V_99 -> V_263 ( V_2 , V_261 , V_166 ) ;
if ( ! V_262 )
V_49 = V_262 ;
}
F_28 () ;
return V_49 ;
}
int F_160 ( struct V_1 * V_2 , T_2 * V_264 , T_7 V_265 )
{
int V_49 = - V_67 ;
struct V_255 * V_99 ;
F_105 () ;
F_158 (km, &xfrm_km_list, list) {
if ( V_99 -> V_266 )
V_49 = V_99 -> V_266 ( V_2 , V_264 , V_265 ) ;
if ( ! V_49 )
break;
}
F_28 () ;
return V_49 ;
}
void F_161 ( struct V_165 * V_166 , int V_254 , int V_257 , T_3 V_258 )
{
struct V_177 V_178 ;
V_178 . V_248 . V_257 = V_257 ;
V_178 . V_258 = V_258 ;
V_178 . V_259 = V_267 ;
F_157 ( V_166 , V_254 , & V_178 ) ;
}
int F_162 ( const struct V_268 * V_157 , T_5 V_254 , T_5 type ,
const struct V_216 * V_161 , int V_269 ,
const struct V_270 * V_271 ,
const struct V_206 * V_65 )
{
int V_49 = - V_67 ;
int V_272 ;
struct V_255 * V_99 ;
F_105 () ;
F_158 (km, &xfrm_km_list, list) {
if ( V_99 -> V_273 ) {
V_272 = V_99 -> V_273 ( V_157 , V_254 , type , V_161 , V_269 , V_271 ,
V_65 ) ;
if ( ! V_272 )
V_49 = V_272 ;
}
}
F_28 () ;
return V_49 ;
}
int F_163 ( struct V_4 * V_4 , T_5 V_12 , struct V_268 * V_157 , T_2 * V_274 )
{
int V_49 = - V_67 ;
int V_272 ;
struct V_255 * V_99 ;
F_105 () ;
F_158 (km, &xfrm_km_list, list) {
if ( V_99 -> V_275 ) {
V_272 = V_99 -> V_275 ( V_4 , V_12 , V_157 , V_274 ) ;
if ( ! V_272 )
V_49 = V_272 ;
}
}
F_28 () ;
return V_49 ;
}
bool F_107 ( const struct V_177 * V_178 )
{
struct V_255 * V_99 ;
bool V_276 = false ;
F_105 () ;
F_158 (km, &xfrm_km_list, list) {
if ( V_99 -> V_276 && V_99 -> V_276 ( V_178 ) ) {
V_276 = true ;
break;
}
}
F_28 () ;
return V_276 ;
}
int F_164 ( struct V_277 * V_278 , int V_279 , T_5 T_8 * V_280 , int V_281 )
{
int V_49 ;
T_5 * V_248 ;
struct V_255 * V_99 ;
struct V_165 * V_166 = NULL ;
if ( V_281 <= 0 || V_281 > V_282 )
return - V_283 ;
V_248 = F_165 ( V_280 , V_281 ) ;
if ( F_166 ( V_248 ) )
return F_167 ( V_248 ) ;
V_49 = - V_67 ;
F_105 () ;
F_158 (km, &xfrm_km_list, list) {
V_166 = V_99 -> V_284 ( V_278 , V_279 , V_248 ,
V_281 , & V_49 ) ;
if ( V_49 >= 0 )
break;
}
F_28 () ;
if ( V_49 >= 0 ) {
F_168 ( V_278 , V_49 , V_166 ) ;
F_169 ( V_166 ) ;
F_170 ( V_278 ) ;
V_49 = 0 ;
}
F_47 ( V_248 ) ;
return V_49 ;
}
int F_171 ( struct V_255 * V_99 )
{
F_17 ( & V_285 ) ;
F_172 ( & V_99 -> V_14 , & V_286 ) ;
F_22 ( & V_285 ) ;
return 0 ;
}
int F_173 ( struct V_255 * V_99 )
{
F_17 ( & V_285 ) ;
F_174 ( & V_99 -> V_14 ) ;
F_22 ( & V_285 ) ;
F_23 () ;
return 0 ;
}
int F_175 ( struct V_46 * V_47 )
{
int V_49 = 0 ;
if ( F_72 ( V_47 -> V_8 >= V_287 ) )
return - V_50 ;
F_17 ( & V_288 ) ;
if ( F_26 ( V_46 [ V_47 -> V_8 ] != NULL ) )
V_49 = - V_53 ;
else
F_20 ( V_46 [ V_47 -> V_8 ] , V_47 ) ;
F_22 ( & V_288 ) ;
return V_49 ;
}
int F_176 ( struct V_46 * V_47 )
{
int V_49 = 0 , V_8 = V_47 -> V_8 ;
if ( F_72 ( V_8 >= V_287 ) )
return - V_50 ;
F_17 ( & V_288 ) ;
if ( F_27 ( V_46 [ V_47 -> V_8 ] != NULL ) ) {
if ( F_177 ( V_46 [ V_8 ] ) != V_47 )
V_49 = - V_67 ;
else
F_178 ( V_46 [ V_47 -> V_8 ] , NULL ) ;
}
F_22 ( & V_288 ) ;
F_23 () ;
return V_49 ;
}
struct V_46 * F_92 ( unsigned int V_8 )
{
if ( F_26 ( V_8 >= V_287 ) )
return NULL ;
return F_179 ( V_46 [ V_8 ] ) ;
}
struct V_46 * F_25 ( unsigned int V_8 )
{
struct V_46 * V_47 ;
if ( F_26 ( V_8 >= V_287 ) )
return NULL ;
F_105 () ;
V_47 = F_179 ( V_46 [ V_8 ] ) ;
if ( F_26 ( ! V_47 ) )
F_28 () ;
return V_47 ;
}
void F_180 ( struct V_1 * V_2 )
{
if ( V_2 -> V_289 ) {
struct V_1 * V_261 = V_2 -> V_289 ;
if ( F_181 ( & V_261 -> V_123 ) == 2 )
F_79 ( V_261 ) ;
F_182 ( & V_261 -> V_123 ) ;
F_78 ( V_261 ) ;
V_2 -> V_289 = NULL ;
}
}
int F_183 ( struct V_1 * V_2 , int V_290 )
{
const struct V_45 * type = F_31 ( V_2 -> type ) ;
if ( V_2 -> V_99 . V_100 == V_169 &&
type && type -> V_291 )
return type -> V_291 ( V_2 , V_290 ) ;
return V_290 - V_2 -> V_23 . V_292 ;
}
int F_184 ( struct V_1 * V_2 , bool V_293 , bool V_294 )
{
struct V_46 * V_47 ;
struct V_62 * V_80 ;
int V_8 = V_2 -> V_23 . V_8 ;
int V_49 ;
V_49 = - V_50 ;
V_47 = F_25 ( V_8 ) ;
if ( ! V_47 )
goto error;
V_49 = 0 ;
if ( V_47 -> V_295 )
V_49 = V_47 -> V_295 ( V_2 ) ;
F_28 () ;
if ( V_49 )
goto error;
V_49 = - V_296 ;
if ( V_2 -> V_157 . V_8 != V_297 ) {
V_80 = F_42 ( V_2 -> V_23 . V_63 , V_2 -> V_157 . V_8 ) ;
if ( V_80 == NULL )
goto error;
if ( ! ( V_80 -> V_179 & V_298 ) &&
V_8 != V_2 -> V_157 . V_8 ) {
F_43 ( V_80 ) ;
goto error;
}
V_2 -> V_80 = V_80 ;
} else {
struct V_62 * V_81 ;
int V_299 = V_196 ;
V_80 = F_42 ( V_2 -> V_23 . V_63 , V_2 -> V_23 . V_8 ) ;
if ( V_80 == NULL )
goto error;
if ( ! ( V_80 -> V_179 & V_298 ) ) {
F_43 ( V_80 ) ;
goto error;
}
V_2 -> V_80 = V_80 ;
if ( V_2 -> V_23 . V_8 == V_196 )
V_299 = V_200 ;
V_81 = F_42 ( V_2 -> V_23 . V_63 , V_299 ) ;
if ( V_81 ) {
if ( V_81 -> V_179 & V_298 )
V_2 -> V_81 = V_81 ;
else
F_43 ( V_81 ) ;
}
}
V_2 -> type = F_30 ( V_2 -> V_22 . V_12 , V_8 ) ;
if ( V_2 -> type == NULL )
goto error;
V_2 -> V_83 = F_38 ( V_2 -> V_22 . V_12 , V_8 , V_294 ) ;
V_49 = V_2 -> type -> V_300 ( V_2 ) ;
if ( V_49 )
goto error;
V_2 -> V_82 = F_42 ( V_2 -> V_23 . V_63 , V_8 ) ;
if ( V_2 -> V_82 == NULL ) {
V_49 = - V_296 ;
goto error;
}
if ( V_293 ) {
V_49 = F_185 ( V_2 ) ;
if ( V_49 )
goto error;
}
V_2 -> V_99 . V_100 = V_169 ;
error:
return V_49 ;
}
int F_128 ( struct V_1 * V_2 )
{
return F_184 ( V_2 , true , false ) ;
}
int T_9 F_186 ( struct V_4 * V_4 )
{
unsigned int V_301 ;
F_66 ( & V_4 -> V_9 . V_185 ) ;
V_301 = sizeof( struct V_13 ) * 8 ;
V_4 -> V_9 . V_42 = F_15 ( V_301 ) ;
if ( ! V_4 -> V_9 . V_42 )
goto V_302;
V_4 -> V_9 . V_43 = F_15 ( V_301 ) ;
if ( ! V_4 -> V_9 . V_43 )
goto V_303;
V_4 -> V_9 . V_44 = F_15 ( V_301 ) ;
if ( ! V_4 -> V_9 . V_44 )
goto V_304;
V_4 -> V_9 . V_10 = ( ( V_301 / sizeof( struct V_13 ) ) - 1 ) ;
V_4 -> V_9 . V_138 = 0 ;
F_187 ( & V_4 -> V_9 . V_29 , F_13 ) ;
F_70 ( & V_4 -> V_9 . V_40 ) ;
return 0 ;
V_304:
F_16 ( V_4 -> V_9 . V_43 , V_301 ) ;
V_303:
F_16 ( V_4 -> V_9 . V_42 , V_301 ) ;
V_302:
return - V_182 ;
}
void F_188 ( struct V_4 * V_4 )
{
unsigned int V_301 ;
F_189 ( & V_4 -> V_9 . V_29 ) ;
F_85 ( V_4 , V_203 , false ) ;
F_189 ( & V_136 ) ;
F_72 ( ! F_149 ( & V_4 -> V_9 . V_185 ) ) ;
V_301 = ( V_4 -> V_9 . V_10 + 1 ) * sizeof( struct V_13 ) ;
F_72 ( ! F_190 ( V_4 -> V_9 . V_44 ) ) ;
F_16 ( V_4 -> V_9 . V_44 , V_301 ) ;
F_72 ( ! F_190 ( V_4 -> V_9 . V_43 ) ) ;
F_16 ( V_4 -> V_9 . V_43 , V_301 ) ;
F_72 ( ! F_190 ( V_4 -> V_9 . V_42 ) ) ;
F_16 ( V_4 -> V_9 . V_42 , V_301 ) ;
}
static void F_191 ( struct V_1 * V_2 ,
struct V_305 * V_306 )
{
struct V_307 * V_308 = V_2 -> V_183 ;
T_3 V_11 = F_192 ( V_2 -> V_22 . V_11 ) ;
if ( V_308 )
F_193 ( V_306 , L_4 ,
V_308 -> V_309 , V_308 -> V_310 , V_308 -> V_311 ) ;
switch ( V_2 -> V_23 . V_8 ) {
case V_196 :
F_193 ( V_306 , L_5 ,
& V_2 -> V_23 . V_6 . V_197 , & V_2 -> V_22 . V_5 . V_197 ) ;
break;
case V_200 :
F_193 ( V_306 , L_6 ,
V_2 -> V_23 . V_6 . V_312 , V_2 -> V_22 . V_5 . V_312 ) ;
break;
}
F_193 ( V_306 , L_7 , V_11 , V_11 ) ;
}
static void F_194 ( struct V_313 * V_314 , T_10 V_8 ,
struct V_305 * V_306 )
{
const struct V_315 * V_316 ;
const struct V_317 * V_318 ;
switch ( V_8 ) {
case V_196 :
V_316 = F_195 ( V_314 ) ;
F_193 ( V_306 , L_5 ,
& V_316 -> V_6 , & V_316 -> V_5 ) ;
break;
case V_200 :
V_318 = F_196 ( V_314 ) ;
F_193 ( V_306 ,
L_8 ,
& V_318 -> V_6 , & V_318 -> V_5 ,
V_318 -> V_319 [ 0 ] & 0x0f ,
V_318 -> V_319 [ 1 ] ,
V_318 -> V_319 [ 2 ] ) ;
break;
}
}
void F_197 ( struct V_1 * V_2 , int V_320 , bool V_139 )
{
struct V_305 * V_306 ;
V_306 = F_198 ( L_9 ) ;
if ( V_306 == NULL )
return;
F_199 ( V_139 , V_306 ) ;
F_191 ( V_2 , V_306 ) ;
F_193 ( V_306 , L_10 , V_320 ) ;
F_200 ( V_306 ) ;
}
void F_59 ( struct V_1 * V_2 , int V_320 , bool V_139 )
{
struct V_305 * V_306 ;
V_306 = F_198 ( L_11 ) ;
if ( V_306 == NULL )
return;
F_199 ( V_139 , V_306 ) ;
F_191 ( V_2 , V_306 ) ;
F_193 ( V_306 , L_10 , V_320 ) ;
F_200 ( V_306 ) ;
}
void F_201 ( struct V_1 * V_2 ,
struct V_313 * V_314 )
{
struct V_305 * V_306 ;
T_3 V_11 ;
V_306 = F_198 ( L_12 ) ;
if ( V_306 == NULL )
return;
F_194 ( V_314 , V_2 -> V_23 . V_8 , V_306 ) ;
V_11 = F_192 ( V_2 -> V_22 . V_11 ) ;
F_193 ( V_306 , L_7 , V_11 , V_11 ) ;
F_200 ( V_306 ) ;
}
void F_202 ( struct V_1 * V_2 ,
struct V_313 * V_314 , T_4 V_321 )
{
struct V_305 * V_306 ;
T_3 V_11 ;
V_306 = F_198 ( L_13 ) ;
if ( V_306 == NULL )
return;
F_194 ( V_314 , V_2 -> V_23 . V_8 , V_306 ) ;
V_11 = F_192 ( V_2 -> V_22 . V_11 ) ;
F_193 ( V_306 , L_14 ,
V_11 , V_11 , F_192 ( V_321 ) ) ;
F_200 ( V_306 ) ;
}
void F_203 ( struct V_313 * V_314 , T_10 V_8 )
{
struct V_305 * V_306 ;
V_306 = F_198 ( L_15 ) ;
if ( V_306 == NULL )
return;
F_194 ( V_314 , V_8 , V_306 ) ;
F_200 ( V_306 ) ;
}
void F_204 ( struct V_313 * V_314 , T_10 V_8 ,
T_4 V_322 , T_4 V_321 )
{
struct V_305 * V_306 ;
T_3 V_11 ;
V_306 = F_198 ( L_15 ) ;
if ( V_306 == NULL )
return;
F_194 ( V_314 , V_8 , V_306 ) ;
V_11 = F_192 ( V_322 ) ;
F_193 ( V_306 , L_14 ,
V_11 , V_11 , F_192 ( V_321 ) ) ;
F_200 ( V_306 ) ;
}
void F_205 ( struct V_1 * V_2 ,
struct V_313 * V_314 , T_5 V_12 )
{
struct V_305 * V_306 ;
T_4 V_322 ;
T_4 V_321 ;
V_306 = F_198 ( L_16 ) ;
if ( V_306 == NULL )
return;
F_194 ( V_314 , V_2 -> V_23 . V_8 , V_306 ) ;
if ( F_206 ( V_314 , V_12 , & V_322 , & V_321 ) == 0 ) {
T_3 V_11 = F_192 ( V_322 ) ;
F_193 ( V_306 , L_14 ,
V_11 , V_11 , F_192 ( V_321 ) ) ;
}
F_200 ( V_306 ) ;
}
