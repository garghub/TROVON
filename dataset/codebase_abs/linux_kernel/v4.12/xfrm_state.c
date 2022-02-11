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
static const struct V_58 * F_38 ( T_5 V_12 , unsigned short V_8 )
{
struct V_46 * V_47 ;
const struct V_58 * * V_48 ;
const struct V_58 * type ;
V_47 = F_25 ( V_8 ) ;
if ( F_26 ( V_47 == NULL ) )
return NULL ;
V_48 = V_47 -> V_59 ;
type = V_48 [ V_12 ] ;
if ( ( type && ! F_32 ( type -> V_57 ) ) )
type = NULL ;
F_28 () ;
return type ;
}
static void F_39 ( const struct V_58 * type )
{
F_35 ( type -> V_57 ) ;
}
int F_40 ( struct V_61 * V_62 , int V_8 )
{
struct V_46 * V_47 ;
struct V_61 * * V_63 ;
int V_49 ;
if ( F_26 ( V_62 -> V_64 >= V_65 ) )
return - V_66 ;
V_47 = F_25 ( V_8 ) ;
if ( F_26 ( V_47 == NULL ) )
return - V_50 ;
V_49 = - V_53 ;
V_63 = V_47 -> V_67 ;
F_17 ( & V_68 ) ;
if ( V_63 [ V_62 -> V_64 ] )
goto V_69;
V_49 = - V_54 ;
if ( ! F_32 ( V_47 -> V_57 ) )
goto V_69;
V_62 -> V_47 = V_47 ;
V_63 [ V_62 -> V_64 ] = V_62 ;
V_49 = 0 ;
V_69:
F_22 ( & V_68 ) ;
F_28 () ;
return V_49 ;
}
int F_41 ( struct V_61 * V_62 , int V_8 )
{
struct V_46 * V_47 ;
struct V_61 * * V_63 ;
int V_49 ;
if ( F_26 ( V_62 -> V_64 >= V_65 ) )
return - V_66 ;
V_47 = F_25 ( V_8 ) ;
if ( F_26 ( V_47 == NULL ) )
return - V_50 ;
V_49 = - V_54 ;
V_63 = V_47 -> V_67 ;
F_17 ( & V_68 ) ;
if ( F_27 ( V_63 [ V_62 -> V_64 ] == V_62 ) ) {
V_63 [ V_62 -> V_64 ] = NULL ;
F_35 ( V_62 -> V_47 -> V_57 ) ;
V_49 = 0 ;
}
F_22 ( & V_68 ) ;
F_28 () ;
return V_49 ;
}
static struct V_61 * F_42 ( unsigned int V_64 , int V_8 )
{
struct V_46 * V_47 ;
struct V_61 * V_62 ;
int V_55 = 0 ;
if ( F_26 ( V_64 >= V_65 ) )
return NULL ;
V_56:
V_47 = F_25 ( V_8 ) ;
if ( F_26 ( V_47 == NULL ) )
return NULL ;
V_62 = F_31 ( V_47 -> V_67 [ V_64 ] ) ;
if ( F_26 ( V_62 && ! F_32 ( V_62 -> V_57 ) ) )
V_62 = NULL ;
F_28 () ;
if ( ! V_62 && ! V_55 ) {
F_33 ( L_2 , V_8 , V_64 ) ;
V_55 = 1 ;
goto V_56;
}
return V_62 ;
}
static void F_43 ( struct V_61 * V_62 )
{
F_35 ( V_62 -> V_57 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_70 ) ;
F_46 ( & V_2 -> V_71 ) ;
F_47 ( V_2 -> V_72 ) ;
F_47 ( V_2 -> V_73 ) ;
F_47 ( V_2 -> V_74 ) ;
F_47 ( V_2 -> V_75 ) ;
F_47 ( V_2 -> V_64 ) ;
F_47 ( V_2 -> V_76 ) ;
F_47 ( V_2 -> V_77 ) ;
F_47 ( V_2 -> V_78 ) ;
if ( V_2 -> V_79 )
F_43 ( V_2 -> V_79 ) ;
if ( V_2 -> V_80 )
F_43 ( V_2 -> V_80 ) ;
if ( V_2 -> V_81 )
F_43 ( V_2 -> V_81 ) ;
if ( V_2 -> V_82 )
F_39 ( V_2 -> V_82 ) ;
if ( V_2 -> type ) {
V_2 -> type -> V_83 ( V_2 ) ;
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
struct V_13 V_84 ;
F_17 ( & V_85 ) ;
F_51 ( & V_86 , & V_84 ) ;
F_22 ( & V_85 ) ;
F_23 () ;
F_10 (x, tmp, &gc_list, gclist)
F_44 ( V_2 ) ;
}
static enum V_87 F_52 ( struct V_88 * V_89 )
{
struct V_90 * V_91 = F_14 ( V_89 , struct V_90 , V_92 ) ;
struct V_1 * V_2 = F_14 ( V_91 , struct V_1 , V_70 ) ;
unsigned long V_93 = F_53 () ;
long V_94 = V_95 ;
int V_96 = 0 ;
int V_49 = 0 ;
F_54 ( & V_2 -> V_97 ) ;
if ( V_2 -> V_98 . V_99 == V_100 )
goto V_69;
if ( V_2 -> V_98 . V_99 == V_101 )
goto V_102;
if ( V_2 -> V_103 . V_104 ) {
long V_105 = V_2 -> V_103 . V_104 +
V_2 -> V_106 . V_107 - V_93 ;
if ( V_105 <= 0 ) {
if ( V_2 -> V_108 & V_109 ) {
V_2 -> V_106 . V_107 = V_93 - V_2 -> V_110 - 1 ;
V_105 = V_2 -> V_103 . V_104 - V_2 -> V_110 ;
} else
goto V_102;
}
if ( V_105 < V_94 )
V_94 = V_105 ;
}
if ( V_2 -> V_103 . V_111 ) {
long V_105 = V_2 -> V_103 . V_111 +
( V_2 -> V_106 . V_112 ? : V_93 ) - V_93 ;
if ( V_105 <= 0 )
goto V_102;
if ( V_105 < V_94 )
V_94 = V_105 ;
}
if ( V_2 -> V_98 . V_113 )
goto V_114;
if ( V_2 -> V_103 . V_115 ) {
long V_105 = V_2 -> V_103 . V_115 +
V_2 -> V_106 . V_107 - V_93 ;
if ( V_105 <= 0 ) {
V_96 = 1 ;
V_2 -> V_108 &= ~ V_109 ;
} else if ( V_105 < V_94 ) {
V_94 = V_105 ;
V_2 -> V_108 |= V_109 ;
V_2 -> V_110 = V_105 ;
}
}
if ( V_2 -> V_103 . V_116 ) {
long V_105 = V_2 -> V_103 . V_116 +
( V_2 -> V_106 . V_112 ? : V_93 ) - V_93 ;
if ( V_105 <= 0 )
V_96 = 1 ;
else if ( V_105 < V_94 )
V_94 = V_105 ;
}
V_2 -> V_98 . V_113 = V_96 ;
if ( V_96 )
F_55 ( V_2 , 0 , 0 ) ;
V_114:
if ( V_94 != V_95 ) {
F_56 ( & V_2 -> V_70 , F_57 ( V_94 , 0 ) , V_117 ) ;
}
goto V_69;
V_102:
if ( V_2 -> V_98 . V_99 == V_118 && V_2 -> V_22 . V_11 == 0 )
V_2 -> V_98 . V_99 = V_101 ;
V_49 = F_58 ( V_2 ) ;
if ( ! V_49 )
F_55 ( V_2 , 1 , 0 ) ;
F_59 ( V_2 , V_49 ? 0 : 1 , true ) ;
V_69:
F_60 ( & V_2 -> V_97 ) ;
return V_119 ;
}
struct V_1 * F_61 ( struct V_4 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_62 ( sizeof( struct V_1 ) , V_120 ) ;
if ( V_2 ) {
F_63 ( & V_2 -> V_121 , V_4 ) ;
F_64 ( & V_2 -> V_3 , 1 ) ;
F_64 ( & V_2 -> V_122 , 0 ) ;
F_65 ( & V_2 -> V_98 . V_123 ) ;
F_66 ( & V_2 -> V_24 ) ;
F_66 ( & V_2 -> V_25 ) ;
F_66 ( & V_2 -> V_26 ) ;
F_67 ( & V_2 -> V_70 , F_52 ,
V_124 , V_125 ) ;
F_68 ( & V_2 -> V_71 , V_126 ,
( unsigned long ) V_2 ) ;
V_2 -> V_106 . V_107 = F_53 () ;
V_2 -> V_103 . V_127 = V_128 ;
V_2 -> V_103 . V_129 = V_128 ;
V_2 -> V_103 . V_130 = V_128 ;
V_2 -> V_103 . V_131 = V_128 ;
V_2 -> V_132 = 0 ;
V_2 -> V_133 = 0 ;
V_2 -> V_79 = NULL ;
V_2 -> V_80 = NULL ;
F_69 ( & V_2 -> V_97 ) ;
}
return V_2 ;
}
void F_70 ( struct V_1 * V_2 )
{
F_71 ( V_2 -> V_98 . V_99 != V_100 ) ;
F_17 ( & V_85 ) ;
F_72 ( & V_2 -> V_134 , & V_86 ) ;
F_22 ( & V_85 ) ;
F_73 ( & V_135 ) ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_121 ( V_2 ) ;
int V_49 = - V_136 ;
if ( V_2 -> V_98 . V_99 != V_100 ) {
V_2 -> V_98 . V_99 = V_100 ;
F_54 ( & V_4 -> V_9 . V_40 ) ;
F_74 ( & V_2 -> V_98 . V_123 ) ;
F_75 ( & V_2 -> V_24 ) ;
F_75 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_22 . V_11 )
F_75 ( & V_2 -> V_26 ) ;
V_4 -> V_9 . V_137 -- ;
F_60 ( & V_4 -> V_9 . V_40 ) ;
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
V_49 = 0 ;
}
return V_49 ;
}
int F_78 ( struct V_1 * V_2 )
{
int V_49 ;
F_17 ( & V_2 -> V_97 ) ;
V_49 = F_58 ( V_2 ) ;
F_22 ( & V_2 -> V_97 ) ;
return V_49 ;
}
static inline int
F_79 ( struct V_4 * V_4 , T_5 V_12 , bool V_138 )
{
int V_39 , V_49 = 0 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
F_80 (x, net->xfrm.state_bydst+i, bydst) {
if ( F_81 ( V_2 -> V_22 . V_12 , V_12 ) &&
( V_49 = F_82 ( V_2 ) ) != 0 ) {
F_59 ( V_2 , 0 , V_138 ) ;
return V_49 ;
}
}
}
return V_49 ;
}
static inline int
F_83 ( struct V_4 * V_4 , struct V_139 * V_140 , bool V_138 )
{
int V_39 , V_49 = 0 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
struct V_141 * V_142 ;
F_80 (x, net->xfrm.state_bydst+i, bydst) {
V_142 = & V_2 -> V_142 ;
if ( V_142 -> V_140 == V_140 &&
( V_49 = F_82 ( V_2 ) ) != 0 ) {
F_59 ( V_2 , 0 , V_138 ) ;
return V_49 ;
}
}
}
return V_49 ;
}
static inline int
F_79 ( struct V_4 * V_4 , T_5 V_12 , bool V_138 )
{
return 0 ;
}
static inline int
F_83 ( struct V_4 * V_4 , struct V_139 * V_140 , bool V_138 )
{
return 0 ;
}
int F_84 ( struct V_4 * V_4 , T_5 V_12 , bool V_138 )
{
int V_39 , V_49 = 0 , V_143 = 0 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_49 = F_79 ( V_4 , V_12 , V_138 ) ;
if ( V_49 )
goto V_69;
V_49 = - V_136 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
V_144:
F_80 (x, net->xfrm.state_bydst+i, bydst) {
if ( ! F_85 ( V_2 ) &&
F_81 ( V_2 -> V_22 . V_12 , V_12 ) ) {
F_86 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
V_49 = F_78 ( V_2 ) ;
F_59 ( V_2 , V_49 ? 0 : 1 ,
V_138 ) ;
F_77 ( V_2 ) ;
if ( ! V_49 )
V_143 ++ ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
goto V_144;
}
}
}
if ( V_143 )
V_49 = 0 ;
V_69:
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_49 ;
}
int F_87 ( struct V_4 * V_4 , struct V_139 * V_140 , bool V_138 )
{
int V_39 , V_49 = 0 , V_143 = 0 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_49 = F_83 ( V_4 , V_140 , V_138 ) ;
if ( V_49 )
goto V_69;
V_49 = - V_136 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
struct V_141 * V_142 ;
V_144:
F_80 (x, net->xfrm.state_bydst+i, bydst) {
V_142 = & V_2 -> V_142 ;
if ( ! F_85 ( V_2 ) && V_142 -> V_140 == V_140 ) {
F_86 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
V_49 = F_78 ( V_2 ) ;
F_59 ( V_2 , V_49 ? 0 : 1 ,
V_138 ) ;
F_77 ( V_2 ) ;
if ( ! V_49 )
V_143 ++ ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
goto V_144;
}
}
}
if ( V_143 )
V_49 = 0 ;
V_69:
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_49 ;
}
void F_88 ( struct V_4 * V_4 , struct V_145 * V_146 )
{
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_146 -> V_147 = V_4 -> V_9 . V_137 ;
V_146 -> V_148 = V_4 -> V_9 . V_10 ;
V_146 -> V_149 = V_150 ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
}
static void
F_89 ( struct V_1 * V_2 , const struct V_151 * V_152 ,
const struct V_153 * V_154 ,
const T_2 * V_5 , const T_2 * V_6 ,
unsigned short V_8 )
{
struct V_46 * V_47 = F_90 ( V_8 ) ;
if ( ! V_47 )
return;
V_47 -> V_155 ( & V_2 -> V_156 , V_152 ) ;
if ( V_8 != V_154 -> V_157 ) {
V_47 = F_90 ( V_154 -> V_157 ) ;
if ( ! V_47 )
return;
}
V_47 -> V_158 ( V_2 , V_154 , V_5 , V_6 ) ;
}
static struct V_1 * F_91 ( struct V_4 * V_4 , T_3 V_159 ,
const T_2 * V_5 ,
T_4 V_11 , T_5 V_12 ,
unsigned short V_8 )
{
unsigned int V_21 = F_7 ( V_4 , V_5 , V_11 , V_12 , V_8 ) ;
struct V_1 * V_2 ;
F_92 (x, net->xfrm.state_byspi + h, byspi) {
if ( V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_22 . V_11 != V_11 ||
V_2 -> V_22 . V_12 != V_12 ||
! F_93 ( & V_2 -> V_22 . V_5 , V_5 , V_8 ) )
continue;
if ( ( V_159 & V_2 -> V_159 . V_160 ) != V_2 -> V_159 . V_161 )
continue;
if ( ! F_1 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_94 ( struct V_4 * V_4 , T_3 V_159 ,
const T_2 * V_5 ,
const T_2 * V_6 ,
T_5 V_12 , unsigned short V_8 )
{
unsigned int V_21 = F_5 ( V_4 , V_5 , V_6 , V_8 ) ;
struct V_1 * V_2 ;
F_92 (x, net->xfrm.state_bysrc + h, bysrc) {
if ( V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_22 . V_12 != V_12 ||
! F_93 ( & V_2 -> V_22 . V_5 , V_5 , V_8 ) ||
! F_93 ( & V_2 -> V_23 . V_6 , V_6 , V_8 ) )
continue;
if ( ( V_159 & V_2 -> V_159 . V_160 ) != V_2 -> V_159 . V_161 )
continue;
if ( ! F_1 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static inline struct V_1 *
F_95 ( struct V_1 * V_2 , int V_162 , int V_8 )
{
struct V_4 * V_4 = V_121 ( V_2 ) ;
T_3 V_159 = V_2 -> V_159 . V_161 & V_2 -> V_159 . V_160 ;
if ( V_162 )
return F_91 ( V_4 , V_159 , & V_2 -> V_22 . V_5 ,
V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 , V_8 ) ;
else
return F_94 ( V_4 , V_159 ,
& V_2 -> V_22 . V_5 ,
& V_2 -> V_23 . V_6 ,
V_2 -> V_22 . V_12 , V_8 ) ;
}
static void F_96 ( struct V_4 * V_4 , int V_163 )
{
if ( V_163 &&
( V_4 -> V_9 . V_10 + 1 ) < V_150 &&
V_4 -> V_9 . V_137 > V_4 -> V_9 . V_10 )
F_73 ( & V_4 -> V_9 . V_29 ) ;
}
static void F_97 ( struct V_164 * V_165 , struct V_1 * V_2 ,
const struct V_151 * V_152 , unsigned short V_8 ,
struct V_1 * * V_166 , int * V_167 ,
int * error )
{
if ( V_2 -> V_98 . V_99 == V_168 ) {
if ( ( V_2 -> V_156 . V_8 &&
! F_98 ( & V_2 -> V_156 , V_152 , V_2 -> V_156 . V_8 ) ) ||
! F_99 ( V_2 , V_165 , V_152 ) )
return;
if ( ! * V_166 ||
( * V_166 ) -> V_98 . V_113 > V_2 -> V_98 . V_113 ||
( ( * V_166 ) -> V_98 . V_113 == V_2 -> V_98 . V_113 &&
( * V_166 ) -> V_106 . V_107 < V_2 -> V_106 . V_107 ) )
* V_166 = V_2 ;
} else if ( V_2 -> V_98 . V_99 == V_118 ) {
* V_167 = 1 ;
} else if ( V_2 -> V_98 . V_99 == V_169 ||
V_2 -> V_98 . V_99 == V_101 ) {
if ( F_98 ( & V_2 -> V_156 , V_152 , V_2 -> V_156 . V_8 ) &&
F_99 ( V_2 , V_165 , V_152 ) )
* error = - V_136 ;
}
}
struct V_1 *
F_100 ( const T_2 * V_5 , const T_2 * V_6 ,
const struct V_151 * V_152 , struct V_153 * V_154 ,
struct V_164 * V_165 , int * V_49 ,
unsigned short V_8 )
{
static T_2 V_170 = { } ;
struct V_4 * V_4 = F_101 ( V_165 ) ;
unsigned int V_21 , V_171 ;
struct V_1 * V_2 , * V_172 , * V_173 ;
int V_174 = 0 ;
int error = 0 ;
struct V_1 * V_166 = NULL ;
T_3 V_159 = V_165 -> V_159 . V_161 & V_165 -> V_159 . V_160 ;
unsigned short V_157 = V_154 -> V_157 ;
unsigned int V_175 ;
struct V_176 V_177 ;
V_173 = NULL ;
V_175 = F_102 ( & V_41 ) ;
F_103 () ;
V_21 = F_3 ( V_4 , V_5 , V_6 , V_154 -> V_7 , V_157 ) ;
F_92 (x, net->xfrm.state_bydst + h, bydst) {
if ( V_2 -> V_23 . V_8 == V_157 &&
V_2 -> V_23 . V_7 == V_154 -> V_7 &&
( V_159 & V_2 -> V_159 . V_160 ) == V_2 -> V_159 . V_161 &&
! ( V_2 -> V_23 . V_178 & V_179 ) &&
F_104 ( V_2 , V_5 , V_6 , V_157 ) &&
V_154 -> V_62 == V_2 -> V_23 . V_62 &&
V_154 -> V_22 . V_12 == V_2 -> V_22 . V_12 &&
( V_154 -> V_22 . V_11 == V_2 -> V_22 . V_11 || ! V_154 -> V_22 . V_11 ) )
F_97 ( V_165 , V_2 , V_152 , V_157 ,
& V_166 , & V_174 , & error ) ;
}
if ( V_166 || V_174 )
goto V_180;
V_171 = F_3 ( V_4 , V_5 , & V_170 , V_154 -> V_7 , V_157 ) ;
F_92 (x, net->xfrm.state_bydst + h_wildcard, bydst) {
if ( V_2 -> V_23 . V_8 == V_157 &&
V_2 -> V_23 . V_7 == V_154 -> V_7 &&
( V_159 & V_2 -> V_159 . V_160 ) == V_2 -> V_159 . V_161 &&
! ( V_2 -> V_23 . V_178 & V_179 ) &&
F_93 ( & V_2 -> V_22 . V_5 , V_5 , V_157 ) &&
V_154 -> V_62 == V_2 -> V_23 . V_62 &&
V_154 -> V_22 . V_12 == V_2 -> V_22 . V_12 &&
( V_154 -> V_22 . V_11 == V_2 -> V_22 . V_11 || ! V_154 -> V_22 . V_11 ) )
F_97 ( V_165 , V_2 , V_152 , V_157 ,
& V_166 , & V_174 , & error ) ;
}
V_180:
V_2 = V_166 ;
if ( ! V_2 && ! error && ! V_174 ) {
if ( V_154 -> V_22 . V_11 &&
( V_172 = F_91 ( V_4 , V_159 , V_5 , V_154 -> V_22 . V_11 ,
V_154 -> V_22 . V_12 , V_157 ) ) != NULL ) {
V_173 = V_172 ;
error = - V_53 ;
goto V_69;
}
V_177 . V_4 = V_4 ;
if ( ! F_105 ( & V_177 ) ) {
error = - V_136 ;
goto V_69;
}
V_2 = F_61 ( V_4 ) ;
if ( V_2 == NULL ) {
error = - V_181 ;
goto V_69;
}
F_89 ( V_2 , V_152 , V_154 , V_5 , V_6 , V_8 ) ;
memcpy ( & V_2 -> V_159 , & V_165 -> V_159 , sizeof( V_2 -> V_159 ) ) ;
error = F_106 ( V_2 , V_165 -> V_182 , V_152 -> V_183 ) ;
if ( error ) {
V_2 -> V_98 . V_99 = V_100 ;
V_173 = V_2 ;
V_2 = NULL ;
goto V_69;
}
if ( F_107 ( V_2 , V_154 , V_165 ) == 0 ) {
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 -> V_98 . V_99 = V_118 ;
F_108 ( & V_2 -> V_98 . V_123 , & V_4 -> V_9 . V_184 ) ;
F_11 ( & V_2 -> V_24 , V_4 -> V_9 . V_42 + V_21 ) ;
V_21 = F_5 ( V_4 , V_5 , V_6 , V_157 ) ;
F_11 ( & V_2 -> V_25 , V_4 -> V_9 . V_43 + V_21 ) ;
if ( V_2 -> V_22 . V_11 ) {
V_21 = F_7 ( V_4 , & V_2 -> V_22 . V_5 , V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 , V_157 ) ;
F_11 ( & V_2 -> V_26 , V_4 -> V_9 . V_44 + V_21 ) ;
}
V_2 -> V_103 . V_104 = V_4 -> V_9 . V_185 ;
F_56 ( & V_2 -> V_70 , F_57 ( V_4 -> V_9 . V_185 , 0 ) , V_117 ) ;
V_4 -> V_9 . V_137 ++ ;
F_96 ( V_4 , V_2 -> V_24 . V_94 != NULL ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
} else {
V_2 -> V_98 . V_99 = V_100 ;
V_173 = V_2 ;
V_2 = NULL ;
error = - V_136 ;
}
}
V_69:
if ( V_2 ) {
if ( ! F_1 ( V_2 ) ) {
* V_49 = - V_186 ;
V_2 = NULL ;
}
} else {
* V_49 = V_174 ? - V_186 : error ;
}
F_28 () ;
if ( V_173 )
F_77 ( V_173 ) ;
if ( F_109 ( & V_41 , V_175 ) ) {
* V_49 = - V_186 ;
if ( V_2 ) {
F_77 ( V_2 ) ;
V_2 = NULL ;
}
}
return V_2 ;
}
struct V_1 *
F_110 ( struct V_4 * V_4 , T_3 V_159 ,
T_2 * V_5 , T_2 * V_6 ,
unsigned short V_8 , T_5 V_62 , T_5 V_12 , T_3 V_7 )
{
unsigned int V_21 ;
struct V_1 * V_187 = NULL , * V_2 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_21 = F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 ) ;
F_80 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_8 == V_8 &&
V_2 -> V_23 . V_7 == V_7 &&
( V_159 & V_2 -> V_159 . V_160 ) == V_2 -> V_159 . V_161 &&
! ( V_2 -> V_23 . V_178 & V_179 ) &&
F_104 ( V_2 , V_5 , V_6 , V_8 ) &&
V_62 == V_2 -> V_23 . V_62 &&
V_12 == V_2 -> V_22 . V_12 &&
V_2 -> V_98 . V_99 == V_168 ) {
V_187 = V_2 ;
break;
}
}
if ( V_187 )
F_86 ( V_187 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_187 ;
}
struct V_1 * F_111 ( struct V_4 * V_4 , T_4 V_11 ,
unsigned short V_8 )
{
struct V_1 * V_2 ;
struct V_188 * V_189 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_112 (w, &net->xfrm.state_all, all) {
V_2 = F_14 ( V_189 , struct V_1 , V_98 ) ;
if ( V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_22 . V_11 != V_11 )
continue;
F_86 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
F_22 ( & V_4 -> V_9 . V_40 ) ;
return NULL ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_121 ( V_2 ) ;
unsigned int V_21 ;
F_108 ( & V_2 -> V_98 . V_123 , & V_4 -> V_9 . V_184 ) ;
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
F_56 ( & V_2 -> V_70 , F_57 ( 1 , 0 ) , V_117 ) ;
if ( V_2 -> V_132 )
F_114 ( & V_2 -> V_71 , V_190 + V_2 -> V_132 ) ;
V_4 -> V_9 . V_137 ++ ;
F_96 ( V_4 , V_2 -> V_24 . V_94 != NULL ) ;
}
static void F_115 ( struct V_1 * V_191 )
{
struct V_4 * V_4 = V_121 ( V_191 ) ;
unsigned short V_8 = V_191 -> V_23 . V_8 ;
T_3 V_7 = V_191 -> V_23 . V_7 ;
struct V_1 * V_2 ;
unsigned int V_21 ;
T_3 V_159 = V_191 -> V_159 . V_161 & V_191 -> V_159 . V_160 ;
V_21 = F_3 ( V_4 , & V_191 -> V_22 . V_5 , & V_191 -> V_23 . V_6 , V_7 , V_8 ) ;
F_80 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_8 == V_8 &&
V_2 -> V_23 . V_7 == V_7 &&
( V_159 & V_2 -> V_159 . V_160 ) == V_2 -> V_159 . V_161 &&
F_93 ( & V_2 -> V_22 . V_5 , & V_191 -> V_22 . V_5 , V_8 ) &&
F_93 ( & V_2 -> V_23 . V_6 , & V_191 -> V_23 . V_6 , V_8 ) )
V_2 -> V_192 ++ ;
}
}
void F_116 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_121 ( V_2 ) ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_115 ( V_2 ) ;
F_113 ( V_2 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
}
static struct V_1 * F_117 ( struct V_4 * V_4 ,
const struct V_193 * V_160 ,
unsigned short V_8 , T_5 V_62 ,
T_3 V_7 , T_5 V_12 ,
const T_2 * V_5 ,
const T_2 * V_6 ,
int V_194 )
{
unsigned int V_21 = F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 ) ;
struct V_1 * V_2 ;
T_3 V_159 = V_160 -> V_161 & V_160 -> V_160 ;
F_80 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_7 != V_7 ||
V_2 -> V_23 . V_62 != V_62 ||
V_2 -> V_23 . V_8 != V_8 ||
V_2 -> V_98 . V_99 != V_118 ||
V_2 -> V_22 . V_11 != 0 ||
V_2 -> V_22 . V_12 != V_12 ||
( V_159 & V_2 -> V_159 . V_160 ) != V_2 -> V_159 . V_161 ||
! F_93 ( & V_2 -> V_22 . V_5 , V_5 , V_8 ) ||
! F_93 ( & V_2 -> V_23 . V_6 , V_6 , V_8 ) )
continue;
F_86 ( V_2 ) ;
return V_2 ;
}
if ( ! V_194 )
return NULL ;
V_2 = F_61 ( V_4 ) ;
if ( F_27 ( V_2 ) ) {
switch ( V_8 ) {
case V_195 :
V_2 -> V_156 . V_5 . V_196 = V_5 -> V_196 ;
V_2 -> V_156 . V_6 . V_196 = V_6 -> V_196 ;
V_2 -> V_156 . V_197 = 32 ;
V_2 -> V_156 . V_198 = 32 ;
V_2 -> V_23 . V_6 . V_196 = V_6 -> V_196 ;
V_2 -> V_22 . V_5 . V_196 = V_5 -> V_196 ;
break;
case V_199 :
V_2 -> V_156 . V_5 . V_200 = V_5 -> V_200 ;
V_2 -> V_156 . V_6 . V_200 = V_6 -> V_200 ;
V_2 -> V_156 . V_197 = 128 ;
V_2 -> V_156 . V_198 = 128 ;
V_2 -> V_23 . V_6 . V_200 = V_6 -> V_200 ;
V_2 -> V_22 . V_5 . V_200 = V_5 -> V_200 ;
break;
}
V_2 -> V_98 . V_99 = V_118 ;
V_2 -> V_22 . V_12 = V_12 ;
V_2 -> V_23 . V_8 = V_8 ;
V_2 -> V_23 . V_62 = V_62 ;
V_2 -> V_23 . V_7 = V_7 ;
V_2 -> V_159 . V_161 = V_160 -> V_161 ;
V_2 -> V_159 . V_160 = V_160 -> V_160 ;
V_2 -> V_103 . V_104 = V_4 -> V_9 . V_185 ;
F_86 ( V_2 ) ;
F_56 ( & V_2 -> V_70 , F_57 ( V_4 -> V_9 . V_185 , 0 ) , V_117 ) ;
F_108 ( & V_2 -> V_98 . V_123 , & V_4 -> V_9 . V_184 ) ;
F_11 ( & V_2 -> V_24 , V_4 -> V_9 . V_42 + V_21 ) ;
V_21 = F_5 ( V_4 , V_5 , V_6 , V_8 ) ;
F_11 ( & V_2 -> V_25 , V_4 -> V_9 . V_43 + V_21 ) ;
V_4 -> V_9 . V_137 ++ ;
F_96 ( V_4 , V_2 -> V_24 . V_94 != NULL ) ;
}
return V_2 ;
}
int F_118 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_121 ( V_2 ) ;
struct V_1 * V_201 , * V_173 ;
int V_8 ;
int V_49 ;
T_3 V_159 = V_2 -> V_159 . V_161 & V_2 -> V_159 . V_160 ;
int V_162 = F_81 ( V_2 -> V_22 . V_12 , V_202 ) ;
V_8 = V_2 -> V_23 . V_8 ;
V_173 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_201 = F_95 ( V_2 , V_162 , V_8 ) ;
if ( V_201 ) {
V_173 = V_201 ;
V_201 = NULL ;
V_49 = - V_53 ;
goto V_69;
}
if ( V_162 && V_2 -> V_98 . V_203 ) {
V_201 = F_119 ( V_4 , V_159 , V_2 -> V_98 . V_203 ) ;
if ( V_201 && ( ( V_201 -> V_22 . V_12 != V_2 -> V_22 . V_12 ) ||
! F_93 ( & V_201 -> V_22 . V_5 , & V_2 -> V_22 . V_5 , V_8 ) ) ) {
V_173 = V_201 ;
V_201 = NULL ;
}
}
if ( V_162 && ! V_201 )
V_201 = F_117 ( V_4 , & V_2 -> V_159 , V_8 , V_2 -> V_23 . V_62 ,
V_2 -> V_23 . V_7 , V_2 -> V_22 . V_12 ,
& V_2 -> V_22 . V_5 , & V_2 -> V_23 . V_6 , 0 ) ;
F_115 ( V_2 ) ;
F_113 ( V_2 ) ;
V_49 = 0 ;
V_69:
F_22 ( & V_4 -> V_9 . V_40 ) ;
if ( V_201 ) {
F_78 ( V_201 ) ;
F_77 ( V_201 ) ;
}
if ( V_173 )
F_77 ( V_173 ) ;
return V_49 ;
}
static struct V_1 * F_120 ( struct V_1 * V_204 )
{
struct V_4 * V_4 = V_121 ( V_204 ) ;
struct V_1 * V_2 = F_61 ( V_4 ) ;
if ( ! V_2 )
goto V_69;
memcpy ( & V_2 -> V_22 , & V_204 -> V_22 , sizeof( V_2 -> V_22 ) ) ;
memcpy ( & V_2 -> V_156 , & V_204 -> V_156 , sizeof( V_2 -> V_156 ) ) ;
memcpy ( & V_2 -> V_103 , & V_204 -> V_103 , sizeof( V_2 -> V_103 ) ) ;
V_2 -> V_23 . V_62 = V_204 -> V_23 . V_62 ;
V_2 -> V_23 . V_205 = V_204 -> V_23 . V_205 ;
V_2 -> V_23 . V_7 = V_204 -> V_23 . V_7 ;
V_2 -> V_23 . V_8 = V_204 -> V_23 . V_8 ;
V_2 -> V_23 . V_6 = V_204 -> V_23 . V_6 ;
if ( V_204 -> V_73 ) {
V_2 -> V_73 = F_121 ( V_204 -> V_73 ) ;
if ( ! V_2 -> V_73 )
goto error;
}
V_2 -> V_23 . V_206 = V_204 -> V_23 . V_206 ;
if ( V_204 -> V_72 ) {
V_2 -> V_72 = F_122 ( V_204 -> V_72 ) ;
if ( ! V_2 -> V_72 )
goto error;
}
if ( V_204 -> V_74 ) {
V_2 -> V_74 = F_123 ( V_204 -> V_74 ) ;
if ( ! V_2 -> V_74 )
goto error;
}
V_2 -> V_23 . V_207 = V_204 -> V_23 . V_207 ;
if ( V_204 -> V_75 ) {
V_2 -> V_75 = F_123 ( V_204 -> V_75 ) ;
if ( ! V_2 -> V_75 )
goto error;
}
V_2 -> V_23 . V_208 = V_204 -> V_23 . V_208 ;
if ( V_204 -> V_64 ) {
V_2 -> V_64 = F_124 ( V_204 -> V_64 , sizeof( * V_2 -> V_64 ) , V_209 ) ;
if ( ! V_2 -> V_64 )
goto error;
}
if ( V_204 -> V_76 ) {
V_2 -> V_76 = F_124 ( V_204 -> V_76 , sizeof( * V_2 -> V_76 ) ,
V_209 ) ;
if ( ! V_2 -> V_76 )
goto error;
}
if ( V_204 -> V_77 ) {
if ( F_125 ( V_2 , V_204 ) )
goto error;
}
memcpy ( & V_2 -> V_159 , & V_204 -> V_159 , sizeof( V_2 -> V_159 ) ) ;
if ( F_126 ( V_2 ) < 0 )
goto error;
V_2 -> V_23 . V_178 = V_204 -> V_23 . V_178 ;
V_2 -> V_23 . V_210 = V_204 -> V_23 . V_210 ;
V_2 -> V_211 = V_204 -> V_211 ;
V_2 -> V_133 = V_204 -> V_133 ;
V_2 -> V_132 = V_204 -> V_132 ;
V_2 -> V_106 . V_107 = V_204 -> V_106 . V_107 ;
V_2 -> V_98 . V_99 = V_204 -> V_98 . V_99 ;
V_2 -> V_98 . V_203 = V_204 -> V_98 . V_203 ;
V_2 -> V_212 = V_204 -> V_212 ;
V_2 -> V_213 = V_204 -> V_213 ;
return V_2 ;
error:
F_77 ( V_2 ) ;
V_69:
return NULL ;
}
struct V_1 * F_127 ( struct V_214 * V_160 , struct V_4 * V_4 )
{
unsigned int V_21 ;
struct V_1 * V_2 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( V_160 -> V_7 ) {
V_21 = F_3 ( V_4 , & V_160 -> V_215 , & V_160 -> V_216 ,
V_160 -> V_7 , V_160 -> V_217 ) ;
F_80 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_2 -> V_23 . V_62 != V_160 -> V_62 ||
V_2 -> V_22 . V_12 != V_160 -> V_12 )
continue;
if ( V_160 -> V_7 && V_2 -> V_23 . V_7 != V_160 -> V_7 )
continue;
if ( ! F_93 ( & V_2 -> V_22 . V_5 , & V_160 -> V_215 ,
V_160 -> V_217 ) ||
! F_93 ( & V_2 -> V_23 . V_6 , & V_160 -> V_216 ,
V_160 -> V_217 ) )
continue;
F_86 ( V_2 ) ;
break;
}
} else {
V_21 = F_5 ( V_4 , & V_160 -> V_215 , & V_160 -> V_216 ,
V_160 -> V_217 ) ;
F_80 (x, net->xfrm.state_bysrc+h, bysrc) {
if ( V_2 -> V_23 . V_62 != V_160 -> V_62 ||
V_2 -> V_22 . V_12 != V_160 -> V_12 )
continue;
if ( ! F_93 ( & V_2 -> V_22 . V_5 , & V_160 -> V_215 ,
V_160 -> V_217 ) ||
! F_93 ( & V_2 -> V_23 . V_6 , & V_160 -> V_216 ,
V_160 -> V_217 ) )
continue;
F_86 ( V_2 ) ;
break;
}
}
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
struct V_1 * F_128 ( struct V_1 * V_2 ,
struct V_214 * V_160 )
{
struct V_1 * V_218 ;
V_218 = F_120 ( V_2 ) ;
if ( ! V_218 )
return NULL ;
memcpy ( & V_218 -> V_22 . V_5 , & V_160 -> V_219 , sizeof( V_218 -> V_22 . V_5 ) ) ;
memcpy ( & V_218 -> V_23 . V_6 , & V_160 -> V_220 , sizeof( V_218 -> V_23 . V_6 ) ) ;
if ( F_93 ( & V_2 -> V_22 . V_5 , & V_160 -> V_219 , V_160 -> V_221 ) ) {
F_116 ( V_218 ) ;
} else {
if ( F_118 ( V_218 ) < 0 )
goto error;
}
return V_218 ;
error:
F_77 ( V_218 ) ;
return NULL ;
}
int F_129 ( struct V_1 * V_2 )
{
struct V_1 * V_201 , * V_173 ;
int V_49 ;
int V_162 = F_81 ( V_2 -> V_22 . V_12 , V_202 ) ;
struct V_4 * V_4 = V_121 ( V_2 ) ;
V_173 = NULL ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_201 = F_95 ( V_2 , V_162 , V_2 -> V_23 . V_8 ) ;
V_49 = - V_136 ;
if ( ! V_201 )
goto V_69;
if ( F_85 ( V_201 ) ) {
V_173 = V_201 ;
V_49 = - V_53 ;
goto V_69;
}
if ( V_201 -> V_98 . V_99 == V_118 ) {
F_113 ( V_2 ) ;
V_2 = NULL ;
}
V_49 = 0 ;
V_69:
F_22 ( & V_4 -> V_9 . V_40 ) ;
if ( V_173 )
F_77 ( V_173 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_2 ) {
F_78 ( V_201 ) ;
F_77 ( V_201 ) ;
return 0 ;
}
V_49 = - V_66 ;
F_17 ( & V_201 -> V_97 ) ;
if ( F_27 ( V_201 -> V_98 . V_99 == V_168 ) ) {
if ( V_2 -> V_64 && V_201 -> V_64 )
memcpy ( V_201 -> V_64 , V_2 -> V_64 , sizeof( * V_201 -> V_64 ) ) ;
if ( V_2 -> V_76 && V_201 -> V_76 ) {
memcpy ( V_201 -> V_76 , V_2 -> V_76 , sizeof( * V_201 -> V_76 ) ) ;
}
if ( ! V_162 && memcmp ( & V_201 -> V_156 , & V_2 -> V_156 , sizeof( V_201 -> V_156 ) ) )
memcpy ( & V_201 -> V_156 , & V_2 -> V_156 , sizeof( V_201 -> V_156 ) ) ;
memcpy ( & V_201 -> V_103 , & V_2 -> V_103 , sizeof( V_201 -> V_103 ) ) ;
V_201 -> V_98 . V_113 = 0 ;
F_56 ( & V_201 -> V_70 , F_57 ( 1 , 0 ) , V_117 ) ;
if ( V_201 -> V_106 . V_112 )
F_130 ( V_201 ) ;
V_49 = 0 ;
V_2 -> V_98 . V_99 = V_100 ;
F_131 ( V_2 ) ;
}
F_22 ( & V_201 -> V_97 ) ;
F_77 ( V_201 ) ;
return V_49 ;
}
int F_130 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_106 . V_112 )
V_2 -> V_106 . V_112 = F_53 () ;
if ( V_2 -> V_106 . V_222 >= V_2 -> V_103 . V_130 ||
V_2 -> V_106 . V_223 >= V_2 -> V_103 . V_131 ) {
V_2 -> V_98 . V_99 = V_101 ;
F_56 ( & V_2 -> V_70 , 0 , V_117 ) ;
return - V_66 ;
}
if ( ! V_2 -> V_98 . V_113 &&
( V_2 -> V_106 . V_222 >= V_2 -> V_103 . V_127 ||
V_2 -> V_106 . V_223 >= V_2 -> V_103 . V_129 ) ) {
V_2 -> V_98 . V_113 = 1 ;
F_55 ( V_2 , 0 , 0 ) ;
}
return 0 ;
}
struct V_1 *
F_132 ( struct V_4 * V_4 , T_3 V_159 , const T_2 * V_5 , T_4 V_11 ,
T_5 V_12 , unsigned short V_8 )
{
struct V_1 * V_2 ;
F_103 () ;
V_2 = F_91 ( V_4 , V_159 , V_5 , V_11 , V_12 , V_8 ) ;
F_28 () ;
return V_2 ;
}
struct V_1 *
F_133 ( struct V_4 * V_4 , T_3 V_159 ,
const T_2 * V_5 , const T_2 * V_6 ,
T_5 V_12 , unsigned short V_8 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 = F_94 ( V_4 , V_159 , V_5 , V_6 , V_12 , V_8 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
struct V_1 *
F_134 ( struct V_4 * V_4 , const struct V_193 * V_159 , T_5 V_62 , T_3 V_7 ,
T_5 V_12 , const T_2 * V_5 ,
const T_2 * V_6 , int V_194 , unsigned short V_8 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 = F_117 ( V_4 , V_159 , V_8 , V_62 , V_7 , V_12 , V_5 , V_6 , V_194 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
int
F_135 ( struct V_153 * * V_224 , struct V_153 * * V_225 , int V_226 ,
unsigned short V_8 , struct V_4 * V_4 )
{
int V_49 = 0 ;
struct V_46 * V_47 = F_25 ( V_8 ) ;
if ( ! V_47 )
return - V_50 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( V_47 -> V_227 )
V_49 = V_47 -> V_227 ( V_224 , V_225 , V_226 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
F_28 () ;
return V_49 ;
}
int
F_136 ( struct V_1 * * V_224 , struct V_1 * * V_225 , int V_226 ,
unsigned short V_8 )
{
int V_49 = 0 ;
struct V_46 * V_47 = F_25 ( V_8 ) ;
struct V_4 * V_4 = V_121 ( * V_225 ) ;
if ( ! V_47 )
return - V_50 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( V_47 -> V_228 )
V_49 = V_47 -> V_228 ( V_224 , V_225 , V_226 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
F_28 () ;
return V_49 ;
}
static struct V_1 * F_119 ( struct V_4 * V_4 , T_3 V_159 , T_3 V_203 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 <= V_4 -> V_9 . V_10 ; V_39 ++ ) {
struct V_1 * V_2 ;
F_80 (x, net->xfrm.state_bydst+i, bydst) {
if ( V_2 -> V_98 . V_203 == V_203 &&
( V_159 & V_2 -> V_159 . V_160 ) == V_2 -> V_159 . V_161 &&
V_2 -> V_98 . V_99 == V_118 ) {
F_86 ( V_2 ) ;
return V_2 ;
}
}
}
return NULL ;
}
struct V_1 * F_137 ( struct V_4 * V_4 , T_3 V_159 , T_3 V_203 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_2 = F_119 ( V_4 , V_159 , V_203 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_2 ;
}
T_3 F_138 ( void )
{
T_3 V_229 ;
static T_6 V_230 ;
do {
V_229 = F_139 ( & V_230 ) ;
} while ( ! V_229 );
return V_229 ;
}
int F_140 ( T_5 V_12 , T_3 V_231 , T_3 V_232 )
{
switch ( V_12 ) {
case V_233 :
case V_234 :
break;
case V_235 :
if ( V_232 >= 0x10000 )
return - V_66 ;
break;
default:
return - V_66 ;
}
if ( V_231 > V_232 )
return - V_66 ;
return 0 ;
}
int F_141 ( struct V_1 * V_2 , T_3 V_236 , T_3 V_237 )
{
struct V_4 * V_4 = V_121 ( V_2 ) ;
unsigned int V_21 ;
struct V_1 * V_172 ;
int V_49 = - V_54 ;
T_4 V_238 = F_142 ( V_236 ) ;
T_4 V_239 = F_142 ( V_237 ) ;
T_3 V_159 = V_2 -> V_159 . V_161 & V_2 -> V_159 . V_160 ;
F_17 ( & V_2 -> V_97 ) ;
if ( V_2 -> V_98 . V_99 == V_100 )
goto V_240;
V_49 = 0 ;
if ( V_2 -> V_22 . V_11 )
goto V_240;
V_49 = - V_54 ;
if ( V_238 == V_239 ) {
V_172 = F_132 ( V_4 , V_159 , & V_2 -> V_22 . V_5 , V_238 , V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ) ;
if ( V_172 ) {
F_77 ( V_172 ) ;
goto V_240;
}
V_2 -> V_22 . V_11 = V_238 ;
} else {
T_3 V_11 = 0 ;
for ( V_21 = 0 ; V_21 < V_237 - V_236 + 1 ; V_21 ++ ) {
V_11 = V_236 + F_143 () % ( V_237 - V_236 + 1 ) ;
V_172 = F_132 ( V_4 , V_159 , & V_2 -> V_22 . V_5 , F_142 ( V_11 ) , V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ) ;
if ( V_172 == NULL ) {
V_2 -> V_22 . V_11 = F_142 ( V_11 ) ;
break;
}
F_77 ( V_172 ) ;
}
}
if ( V_2 -> V_22 . V_11 ) {
F_17 ( & V_4 -> V_9 . V_40 ) ;
V_21 = F_7 ( V_4 , & V_2 -> V_22 . V_5 , V_2 -> V_22 . V_11 , V_2 -> V_22 . V_12 , V_2 -> V_23 . V_8 ) ;
F_11 ( & V_2 -> V_26 , V_4 -> V_9 . V_44 + V_21 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
V_49 = 0 ;
}
V_240:
F_22 ( & V_2 -> V_97 ) ;
return V_49 ;
}
static bool F_144 ( struct V_1 * V_2 ,
struct V_241 * V_242 )
{
if ( V_242 ) {
if ( ( V_242 -> V_8 == V_195 ||
V_242 -> V_8 == V_199 ) &&
V_2 -> V_23 . V_8 != V_242 -> V_8 )
return false ;
return F_145 ( & V_2 -> V_23 . V_6 , & V_242 -> V_6 ,
V_242 -> V_243 ) &&
F_145 ( & V_2 -> V_22 . V_5 , & V_242 -> V_5 ,
V_242 -> V_244 ) ;
}
return true ;
}
int V_188 ( struct V_4 * V_4 , struct V_188 * V_245 ,
int (* F_146)( struct V_1 * , int , void * ) ,
void * V_246 )
{
struct V_1 * V_99 ;
struct V_188 * V_2 ;
int V_49 = 0 ;
if ( V_245 -> V_203 != 0 && F_147 ( & V_245 -> V_123 ) )
return 0 ;
F_17 ( & V_4 -> V_9 . V_40 ) ;
if ( F_147 ( & V_245 -> V_123 ) )
V_2 = F_148 ( & V_4 -> V_9 . V_184 , struct V_188 , V_123 ) ;
else
V_2 = F_148 ( & V_245 -> V_123 , struct V_188 , V_123 ) ;
F_149 (x, &net->xfrm.state_all, all) {
if ( V_2 -> V_99 == V_100 )
continue;
V_99 = F_14 ( V_2 , struct V_1 , V_98 ) ;
if ( ! F_81 ( V_99 -> V_22 . V_12 , V_245 -> V_12 ) )
continue;
if ( ! F_144 ( V_99 , V_245 -> V_242 ) )
continue;
V_49 = F_146 ( V_99 , V_245 -> V_203 , V_246 ) ;
if ( V_49 ) {
F_150 ( & V_245 -> V_123 , & V_2 -> V_123 ) ;
goto V_69;
}
V_245 -> V_203 ++ ;
}
if ( V_245 -> V_203 == 0 ) {
V_49 = - V_54 ;
goto V_69;
}
F_151 ( & V_245 -> V_123 ) ;
V_69:
F_22 ( & V_4 -> V_9 . V_40 ) ;
return V_49 ;
}
void F_152 ( struct V_188 * V_245 , T_5 V_12 ,
struct V_241 * V_242 )
{
F_65 ( & V_245 -> V_123 ) ;
V_245 -> V_12 = V_12 ;
V_245 -> V_99 = V_100 ;
V_245 -> V_203 = 0 ;
V_245 -> V_242 = V_242 ;
}
void F_153 ( struct V_188 * V_245 , struct V_4 * V_4 )
{
F_47 ( V_245 -> V_242 ) ;
if ( F_147 ( & V_245 -> V_123 ) )
return;
F_17 ( & V_4 -> V_9 . V_40 ) ;
F_74 ( & V_245 -> V_123 ) ;
F_22 ( & V_4 -> V_9 . V_40 ) ;
}
static void V_126 ( unsigned long V_246 )
{
struct V_1 * V_2 = (struct V_1 * ) V_246 ;
F_54 ( & V_2 -> V_97 ) ;
if ( V_2 -> V_98 . V_99 == V_168 ) {
if ( F_154 ( V_121 ( V_2 ) ) )
V_2 -> V_247 -> V_248 ( V_2 , V_249 ) ;
else
V_2 -> V_108 |= V_250 ;
}
F_60 ( & V_2 -> V_97 ) ;
}
void F_155 ( struct V_164 * V_251 , int V_252 , const struct V_176 * V_177 )
{
struct V_253 * V_98 ;
F_103 () ;
F_156 (km, &xfrm_km_list, list)
if ( V_98 -> V_254 )
V_98 -> V_254 ( V_251 , V_252 , V_177 ) ;
F_28 () ;
}
void F_157 ( struct V_1 * V_2 , const struct V_176 * V_177 )
{
struct V_253 * V_98 ;
F_103 () ;
F_156 (km, &xfrm_km_list, list)
if ( V_98 -> V_248 )
V_98 -> V_248 ( V_2 , V_177 ) ;
F_28 () ;
}
void F_55 ( struct V_1 * V_2 , int V_255 , T_3 V_256 )
{
struct V_176 V_177 ;
V_177 . V_246 . V_255 = V_255 ;
V_177 . V_256 = V_256 ;
V_177 . V_257 = V_258 ;
F_157 ( V_2 , & V_177 ) ;
}
int F_107 ( struct V_1 * V_2 , struct V_153 * V_259 , struct V_164 * V_165 )
{
int V_49 = - V_66 , V_260 ;
struct V_253 * V_98 ;
F_103 () ;
F_156 (km, &xfrm_km_list, list) {
V_260 = V_98 -> V_261 ( V_2 , V_259 , V_165 ) ;
if ( ! V_260 )
V_49 = V_260 ;
}
F_28 () ;
return V_49 ;
}
int F_158 ( struct V_1 * V_2 , T_2 * V_262 , T_7 V_263 )
{
int V_49 = - V_66 ;
struct V_253 * V_98 ;
F_103 () ;
F_156 (km, &xfrm_km_list, list) {
if ( V_98 -> V_264 )
V_49 = V_98 -> V_264 ( V_2 , V_262 , V_263 ) ;
if ( ! V_49 )
break;
}
F_28 () ;
return V_49 ;
}
void F_159 ( struct V_164 * V_165 , int V_252 , int V_255 , T_3 V_256 )
{
struct V_176 V_177 ;
V_177 . V_246 . V_255 = V_255 ;
V_177 . V_256 = V_256 ;
V_177 . V_257 = V_265 ;
F_155 ( V_165 , V_252 , & V_177 ) ;
}
int F_160 ( const struct V_266 * V_156 , T_5 V_252 , T_5 type ,
const struct V_214 * V_160 , int V_267 ,
const struct V_268 * V_269 )
{
int V_49 = - V_66 ;
int V_270 ;
struct V_253 * V_98 ;
F_103 () ;
F_156 (km, &xfrm_km_list, list) {
if ( V_98 -> V_271 ) {
V_270 = V_98 -> V_271 ( V_156 , V_252 , type , V_160 , V_267 , V_269 ) ;
if ( ! V_270 )
V_49 = V_270 ;
}
}
F_28 () ;
return V_49 ;
}
int F_161 ( struct V_4 * V_4 , T_5 V_12 , struct V_266 * V_156 , T_2 * V_272 )
{
int V_49 = - V_66 ;
int V_270 ;
struct V_253 * V_98 ;
F_103 () ;
F_156 (km, &xfrm_km_list, list) {
if ( V_98 -> V_273 ) {
V_270 = V_98 -> V_273 ( V_4 , V_12 , V_156 , V_272 ) ;
if ( ! V_270 )
V_49 = V_270 ;
}
}
F_28 () ;
return V_49 ;
}
bool F_105 ( const struct V_176 * V_177 )
{
struct V_253 * V_98 ;
bool V_274 = false ;
F_103 () ;
F_156 (km, &xfrm_km_list, list) {
if ( V_98 -> V_274 && V_98 -> V_274 ( V_177 ) ) {
V_274 = true ;
break;
}
}
F_28 () ;
return V_274 ;
}
int F_162 ( struct V_275 * V_276 , int V_277 , T_5 T_8 * V_278 , int V_279 )
{
int V_49 ;
T_5 * V_246 ;
struct V_253 * V_98 ;
struct V_164 * V_165 = NULL ;
if ( V_279 <= 0 || V_279 > V_280 )
return - V_281 ;
V_246 = F_163 ( V_279 , V_209 ) ;
if ( ! V_246 )
return - V_181 ;
V_49 = - V_282 ;
if ( F_164 ( V_246 , V_278 , V_279 ) )
goto V_69;
V_49 = - V_66 ;
F_103 () ;
F_156 (km, &xfrm_km_list, list) {
V_165 = V_98 -> V_283 ( V_276 , V_277 , V_246 ,
V_279 , & V_49 ) ;
if ( V_49 >= 0 )
break;
}
F_28 () ;
if ( V_49 >= 0 ) {
F_165 ( V_276 , V_49 , V_165 ) ;
F_166 ( V_165 ) ;
V_49 = 0 ;
}
V_69:
F_47 ( V_246 ) ;
return V_49 ;
}
int F_167 ( struct V_253 * V_98 )
{
F_17 ( & V_284 ) ;
F_168 ( & V_98 -> V_14 , & V_285 ) ;
F_22 ( & V_284 ) ;
return 0 ;
}
int F_169 ( struct V_253 * V_98 )
{
F_17 ( & V_284 ) ;
F_170 ( & V_98 -> V_14 ) ;
F_22 ( & V_284 ) ;
F_23 () ;
return 0 ;
}
int F_171 ( struct V_46 * V_47 )
{
int V_49 = 0 ;
if ( F_71 ( V_47 -> V_8 >= V_286 ) )
return - V_50 ;
F_17 ( & V_287 ) ;
if ( F_26 ( V_46 [ V_47 -> V_8 ] != NULL ) )
V_49 = - V_53 ;
else
F_20 ( V_46 [ V_47 -> V_8 ] , V_47 ) ;
F_22 ( & V_287 ) ;
return V_49 ;
}
int F_172 ( struct V_46 * V_47 )
{
int V_49 = 0 , V_8 = V_47 -> V_8 ;
if ( F_71 ( V_8 >= V_286 ) )
return - V_50 ;
F_17 ( & V_287 ) ;
if ( F_27 ( V_46 [ V_47 -> V_8 ] != NULL ) ) {
if ( F_173 ( V_46 [ V_8 ] ) != V_47 )
V_49 = - V_66 ;
else
F_174 ( V_46 [ V_47 -> V_8 ] , NULL ) ;
}
F_22 ( & V_287 ) ;
F_23 () ;
return V_49 ;
}
struct V_46 * F_90 ( unsigned int V_8 )
{
if ( F_26 ( V_8 >= V_286 ) )
return NULL ;
return F_175 ( V_46 [ V_8 ] ) ;
}
struct V_46 * F_25 ( unsigned int V_8 )
{
struct V_46 * V_47 ;
if ( F_26 ( V_8 >= V_286 ) )
return NULL ;
F_103 () ;
V_47 = F_175 ( V_46 [ V_8 ] ) ;
if ( F_26 ( ! V_47 ) )
F_28 () ;
return V_47 ;
}
void F_176 ( struct V_1 * V_2 )
{
if ( V_2 -> V_288 ) {
struct V_1 * V_259 = V_2 -> V_288 ;
if ( F_177 ( & V_259 -> V_122 ) == 2 )
F_78 ( V_259 ) ;
F_178 ( & V_259 -> V_122 ) ;
F_77 ( V_259 ) ;
V_2 -> V_288 = NULL ;
}
}
int F_179 ( struct V_1 * V_2 , int V_289 )
{
const struct V_45 * type = F_31 ( V_2 -> type ) ;
if ( V_2 -> V_98 . V_99 == V_168 &&
type && type -> V_290 )
return type -> V_290 ( V_2 , V_289 ) ;
return V_289 - V_2 -> V_23 . V_291 ;
}
int F_180 ( struct V_1 * V_2 , bool V_292 )
{
struct V_46 * V_47 ;
struct V_61 * V_79 ;
int V_8 = V_2 -> V_23 . V_8 ;
int V_49 ;
V_49 = - V_50 ;
V_47 = F_25 ( V_8 ) ;
if ( ! V_47 )
goto error;
V_49 = 0 ;
if ( V_47 -> V_293 )
V_49 = V_47 -> V_293 ( V_2 ) ;
F_28 () ;
if ( V_49 )
goto error;
V_49 = - V_294 ;
if ( V_2 -> V_156 . V_8 != V_295 ) {
V_79 = F_42 ( V_2 -> V_23 . V_62 , V_2 -> V_156 . V_8 ) ;
if ( V_79 == NULL )
goto error;
if ( ! ( V_79 -> V_178 & V_296 ) &&
V_8 != V_2 -> V_156 . V_8 ) {
F_43 ( V_79 ) ;
goto error;
}
V_2 -> V_79 = V_79 ;
} else {
struct V_61 * V_80 ;
int V_297 = V_195 ;
V_79 = F_42 ( V_2 -> V_23 . V_62 , V_2 -> V_23 . V_8 ) ;
if ( V_79 == NULL )
goto error;
if ( ! ( V_79 -> V_178 & V_296 ) ) {
F_43 ( V_79 ) ;
goto error;
}
V_2 -> V_79 = V_79 ;
if ( V_2 -> V_23 . V_8 == V_195 )
V_297 = V_199 ;
V_80 = F_42 ( V_2 -> V_23 . V_62 , V_297 ) ;
if ( V_80 ) {
if ( V_80 -> V_178 & V_296 )
V_2 -> V_80 = V_80 ;
else
F_43 ( V_80 ) ;
}
}
V_2 -> type = F_30 ( V_2 -> V_22 . V_12 , V_8 ) ;
if ( V_2 -> type == NULL )
goto error;
V_2 -> V_82 = F_38 ( V_2 -> V_22 . V_12 , V_8 ) ;
V_49 = V_2 -> type -> V_298 ( V_2 ) ;
if ( V_49 )
goto error;
V_2 -> V_81 = F_42 ( V_2 -> V_23 . V_62 , V_8 ) ;
if ( V_2 -> V_81 == NULL ) {
V_49 = - V_294 ;
goto error;
}
if ( V_292 ) {
V_49 = F_181 ( V_2 ) ;
if ( V_49 )
goto error;
}
V_2 -> V_98 . V_99 = V_168 ;
error:
return V_49 ;
}
int F_126 ( struct V_1 * V_2 )
{
return F_180 ( V_2 , true ) ;
}
int T_9 F_182 ( struct V_4 * V_4 )
{
unsigned int V_299 ;
F_65 ( & V_4 -> V_9 . V_184 ) ;
V_299 = sizeof( struct V_13 ) * 8 ;
V_4 -> V_9 . V_42 = F_15 ( V_299 ) ;
if ( ! V_4 -> V_9 . V_42 )
goto V_300;
V_4 -> V_9 . V_43 = F_15 ( V_299 ) ;
if ( ! V_4 -> V_9 . V_43 )
goto V_301;
V_4 -> V_9 . V_44 = F_15 ( V_299 ) ;
if ( ! V_4 -> V_9 . V_44 )
goto V_302;
V_4 -> V_9 . V_10 = ( ( V_299 / sizeof( struct V_13 ) ) - 1 ) ;
V_4 -> V_9 . V_137 = 0 ;
F_183 ( & V_4 -> V_9 . V_29 , F_13 ) ;
F_69 ( & V_4 -> V_9 . V_40 ) ;
return 0 ;
V_302:
F_16 ( V_4 -> V_9 . V_43 , V_299 ) ;
V_301:
F_16 ( V_4 -> V_9 . V_42 , V_299 ) ;
V_300:
return - V_181 ;
}
void F_184 ( struct V_4 * V_4 )
{
unsigned int V_299 ;
F_185 ( & V_4 -> V_9 . V_29 ) ;
F_84 ( V_4 , V_202 , false ) ;
F_185 ( & V_135 ) ;
F_71 ( ! F_147 ( & V_4 -> V_9 . V_184 ) ) ;
V_299 = ( V_4 -> V_9 . V_10 + 1 ) * sizeof( struct V_13 ) ;
F_71 ( ! F_186 ( V_4 -> V_9 . V_44 ) ) ;
F_16 ( V_4 -> V_9 . V_44 , V_299 ) ;
F_71 ( ! F_186 ( V_4 -> V_9 . V_43 ) ) ;
F_16 ( V_4 -> V_9 . V_43 , V_299 ) ;
F_71 ( ! F_186 ( V_4 -> V_9 . V_42 ) ) ;
F_16 ( V_4 -> V_9 . V_42 , V_299 ) ;
}
static void F_187 ( struct V_1 * V_2 ,
struct V_303 * V_304 )
{
struct V_305 * V_306 = V_2 -> V_182 ;
T_3 V_11 = F_188 ( V_2 -> V_22 . V_11 ) ;
if ( V_306 )
F_189 ( V_304 , L_3 ,
V_306 -> V_307 , V_306 -> V_308 , V_306 -> V_309 ) ;
switch ( V_2 -> V_23 . V_8 ) {
case V_195 :
F_189 ( V_304 , L_4 ,
& V_2 -> V_23 . V_6 . V_196 , & V_2 -> V_22 . V_5 . V_196 ) ;
break;
case V_199 :
F_189 ( V_304 , L_5 ,
V_2 -> V_23 . V_6 . V_310 , V_2 -> V_22 . V_5 . V_310 ) ;
break;
}
F_189 ( V_304 , L_6 , V_11 , V_11 ) ;
}
static void F_190 ( struct V_311 * V_312 , T_10 V_8 ,
struct V_303 * V_304 )
{
const struct V_313 * V_314 ;
const struct V_315 * V_316 ;
switch ( V_8 ) {
case V_195 :
V_314 = F_191 ( V_312 ) ;
F_189 ( V_304 , L_4 ,
& V_314 -> V_6 , & V_314 -> V_5 ) ;
break;
case V_199 :
V_316 = F_192 ( V_312 ) ;
F_189 ( V_304 ,
L_7 ,
& V_316 -> V_6 , & V_316 -> V_5 ,
V_316 -> V_317 [ 0 ] & 0x0f ,
V_316 -> V_317 [ 1 ] ,
V_316 -> V_317 [ 2 ] ) ;
break;
}
}
void F_193 ( struct V_1 * V_2 , int V_318 , bool V_138 )
{
struct V_303 * V_304 ;
V_304 = F_194 ( L_8 ) ;
if ( V_304 == NULL )
return;
F_195 ( V_138 , V_304 ) ;
F_187 ( V_2 , V_304 ) ;
F_189 ( V_304 , L_9 , V_318 ) ;
F_196 ( V_304 ) ;
}
void F_59 ( struct V_1 * V_2 , int V_318 , bool V_138 )
{
struct V_303 * V_304 ;
V_304 = F_194 ( L_10 ) ;
if ( V_304 == NULL )
return;
F_195 ( V_138 , V_304 ) ;
F_187 ( V_2 , V_304 ) ;
F_189 ( V_304 , L_9 , V_318 ) ;
F_196 ( V_304 ) ;
}
void F_197 ( struct V_1 * V_2 ,
struct V_311 * V_312 )
{
struct V_303 * V_304 ;
T_3 V_11 ;
V_304 = F_194 ( L_11 ) ;
if ( V_304 == NULL )
return;
F_190 ( V_312 , V_2 -> V_23 . V_8 , V_304 ) ;
V_11 = F_188 ( V_2 -> V_22 . V_11 ) ;
F_189 ( V_304 , L_6 , V_11 , V_11 ) ;
F_196 ( V_304 ) ;
}
void F_198 ( struct V_1 * V_2 ,
struct V_311 * V_312 , T_4 V_319 )
{
struct V_303 * V_304 ;
T_3 V_11 ;
V_304 = F_194 ( L_12 ) ;
if ( V_304 == NULL )
return;
F_190 ( V_312 , V_2 -> V_23 . V_8 , V_304 ) ;
V_11 = F_188 ( V_2 -> V_22 . V_11 ) ;
F_189 ( V_304 , L_13 ,
V_11 , V_11 , F_188 ( V_319 ) ) ;
F_196 ( V_304 ) ;
}
void F_199 ( struct V_311 * V_312 , T_10 V_8 )
{
struct V_303 * V_304 ;
V_304 = F_194 ( L_14 ) ;
if ( V_304 == NULL )
return;
F_190 ( V_312 , V_8 , V_304 ) ;
F_196 ( V_304 ) ;
}
void F_200 ( struct V_311 * V_312 , T_10 V_8 ,
T_4 V_320 , T_4 V_319 )
{
struct V_303 * V_304 ;
T_3 V_11 ;
V_304 = F_194 ( L_14 ) ;
if ( V_304 == NULL )
return;
F_190 ( V_312 , V_8 , V_304 ) ;
V_11 = F_188 ( V_320 ) ;
F_189 ( V_304 , L_13 ,
V_11 , V_11 , F_188 ( V_319 ) ) ;
F_196 ( V_304 ) ;
}
void F_201 ( struct V_1 * V_2 ,
struct V_311 * V_312 , T_5 V_12 )
{
struct V_303 * V_304 ;
T_4 V_320 ;
T_4 V_319 ;
V_304 = F_194 ( L_15 ) ;
if ( V_304 == NULL )
return;
F_190 ( V_312 , V_2 -> V_23 . V_8 , V_304 ) ;
if ( F_202 ( V_312 , V_12 , & V_320 , & V_319 ) == 0 ) {
T_3 V_11 = F_188 ( V_320 ) ;
F_189 ( V_304 , L_13 ,
V_11 , V_11 , F_188 ( V_319 ) ) ;
}
F_196 ( V_304 ) ;
}
