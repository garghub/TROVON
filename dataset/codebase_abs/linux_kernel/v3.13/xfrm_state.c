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
F_13 ( & V_39 ) ;
V_35 = F_10 ( V_1 -> V_6 . V_7 ) ;
V_29 = F_14 ( V_35 ) ;
if ( ! V_29 )
goto V_40;
V_30 = F_14 ( V_35 ) ;
if ( ! V_30 ) {
F_15 ( V_29 , V_35 ) ;
goto V_40;
}
V_31 = F_14 ( V_35 ) ;
if ( ! V_31 ) {
F_15 ( V_29 , V_35 ) ;
F_15 ( V_30 , V_35 ) ;
goto V_40;
}
F_16 ( & V_41 ) ;
V_15 = ( V_35 / sizeof( struct V_10 ) ) - 1U ;
for ( V_38 = V_1 -> V_6 . V_7 ; V_38 >= 0 ; V_38 -- )
F_7 ( V_1 -> V_6 . V_42 + V_38 , V_29 , V_30 , V_31 ,
V_15 ) ;
V_32 = V_1 -> V_6 . V_42 ;
V_33 = V_1 -> V_6 . V_43 ;
V_34 = V_1 -> V_6 . V_44 ;
V_37 = V_1 -> V_6 . V_7 ;
V_1 -> V_6 . V_42 = V_29 ;
V_1 -> V_6 . V_43 = V_30 ;
V_1 -> V_6 . V_44 = V_31 ;
V_1 -> V_6 . V_7 = V_15 ;
F_17 ( & V_41 ) ;
V_36 = ( V_37 + 1 ) * sizeof( struct V_10 ) ;
F_15 ( V_32 , V_36 ) ;
F_15 ( V_33 , V_36 ) ;
F_15 ( V_34 , V_36 ) ;
V_40:
F_18 ( & V_39 ) ;
}
int F_19 ( const struct V_45 * type , unsigned short V_5 )
{
struct V_46 * V_47 = F_20 ( V_5 ) ;
const struct V_45 * * V_48 ;
int V_49 = 0 ;
if ( F_21 ( V_47 == NULL ) )
return - V_50 ;
V_48 = V_47 -> V_51 ;
F_16 ( & V_52 ) ;
if ( F_22 ( V_48 [ type -> V_9 ] == NULL ) )
V_48 [ type -> V_9 ] = type ;
else
V_49 = - V_53 ;
F_17 ( & V_52 ) ;
F_23 ( V_47 ) ;
return V_49 ;
}
int F_24 ( const struct V_45 * type , unsigned short V_5 )
{
struct V_46 * V_47 = F_20 ( V_5 ) ;
const struct V_45 * * V_48 ;
int V_49 = 0 ;
if ( F_21 ( V_47 == NULL ) )
return - V_50 ;
V_48 = V_47 -> V_51 ;
F_16 ( & V_52 ) ;
if ( F_21 ( V_48 [ type -> V_9 ] != type ) )
V_49 = - V_54 ;
else
V_48 [ type -> V_9 ] = NULL ;
F_17 ( & V_52 ) ;
F_23 ( V_47 ) ;
return V_49 ;
}
static const struct V_45 * F_25 ( T_4 V_9 , unsigned short V_5 )
{
struct V_46 * V_47 ;
const struct V_45 * * V_48 ;
const struct V_45 * type ;
int V_55 = 0 ;
V_56:
V_47 = F_20 ( V_5 ) ;
if ( F_21 ( V_47 == NULL ) )
return NULL ;
V_48 = V_47 -> V_51 ;
type = V_48 [ V_9 ] ;
if ( F_21 ( type && ! F_26 ( type -> V_57 ) ) )
type = NULL ;
if ( ! type && ! V_55 ) {
F_23 ( V_47 ) ;
F_27 ( L_1 , V_5 , V_9 ) ;
V_55 = 1 ;
goto V_56;
}
F_23 ( V_47 ) ;
return type ;
}
static void F_28 ( const struct V_45 * type )
{
F_29 ( type -> V_57 ) ;
}
int F_30 ( struct V_58 * V_59 , int V_5 )
{
struct V_46 * V_47 ;
struct V_58 * * V_60 ;
int V_49 ;
if ( F_21 ( V_59 -> V_61 >= V_62 ) )
return - V_63 ;
V_47 = F_20 ( V_5 ) ;
if ( F_21 ( V_47 == NULL ) )
return - V_50 ;
V_49 = - V_53 ;
V_60 = V_47 -> V_64 ;
F_16 ( & V_65 ) ;
if ( V_60 [ V_59 -> V_61 ] )
goto V_66;
V_49 = - V_54 ;
if ( ! F_26 ( V_47 -> V_57 ) )
goto V_66;
V_59 -> V_47 = V_47 ;
V_60 [ V_59 -> V_61 ] = V_59 ;
V_49 = 0 ;
V_66:
F_17 ( & V_65 ) ;
F_23 ( V_47 ) ;
return V_49 ;
}
int F_31 ( struct V_58 * V_59 , int V_5 )
{
struct V_46 * V_47 ;
struct V_58 * * V_60 ;
int V_49 ;
if ( F_21 ( V_59 -> V_61 >= V_62 ) )
return - V_63 ;
V_47 = F_20 ( V_5 ) ;
if ( F_21 ( V_47 == NULL ) )
return - V_50 ;
V_49 = - V_54 ;
V_60 = V_47 -> V_64 ;
F_16 ( & V_65 ) ;
if ( F_22 ( V_60 [ V_59 -> V_61 ] == V_59 ) ) {
V_60 [ V_59 -> V_61 ] = NULL ;
F_29 ( V_59 -> V_47 -> V_57 ) ;
V_49 = 0 ;
}
F_17 ( & V_65 ) ;
F_23 ( V_47 ) ;
return V_49 ;
}
static struct V_58 * F_32 ( unsigned int V_61 , int V_5 )
{
struct V_46 * V_47 ;
struct V_58 * V_59 ;
int V_55 = 0 ;
if ( F_21 ( V_61 >= V_62 ) )
return NULL ;
V_56:
V_47 = F_20 ( V_5 ) ;
if ( F_21 ( V_47 == NULL ) )
return NULL ;
V_59 = V_47 -> V_64 [ V_61 ] ;
if ( F_21 ( V_59 && ! F_26 ( V_59 -> V_57 ) ) )
V_59 = NULL ;
if ( ! V_59 && ! V_55 ) {
F_23 ( V_47 ) ;
F_27 ( L_2 , V_5 , V_61 ) ;
V_55 = 1 ;
goto V_56;
}
F_23 ( V_47 ) ;
return V_59 ;
}
static void F_33 ( struct V_58 * V_59 )
{
F_29 ( V_59 -> V_57 ) ;
}
static void F_34 ( struct V_18 * V_19 )
{
F_35 ( & V_19 -> V_67 ) ;
F_36 ( & V_19 -> V_68 ) ;
F_37 ( V_19 -> V_69 ) ;
F_37 ( V_19 -> V_70 ) ;
F_37 ( V_19 -> V_71 ) ;
F_37 ( V_19 -> V_61 ) ;
F_37 ( V_19 -> V_72 ) ;
F_37 ( V_19 -> V_73 ) ;
F_37 ( V_19 -> V_74 ) ;
if ( V_19 -> V_75 )
F_33 ( V_19 -> V_75 ) ;
if ( V_19 -> V_76 )
F_33 ( V_19 -> V_76 ) ;
if ( V_19 -> V_77 )
F_33 ( V_19 -> V_77 ) ;
if ( V_19 -> type ) {
V_19 -> type -> V_78 ( V_19 ) ;
F_28 ( V_19 -> type ) ;
}
F_38 ( V_19 ) ;
F_37 ( V_19 ) ;
}
static void F_39 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = F_12 ( V_27 , struct V_1 , V_6 . V_79 ) ;
struct V_18 * V_19 ;
struct V_16 * V_17 ;
struct V_10 V_80 ;
F_16 ( & V_81 ) ;
F_40 ( & V_1 -> V_6 . V_82 , & V_80 ) ;
F_17 ( & V_81 ) ;
F_8 (x, tmp, &gc_list, gclist)
F_34 ( V_19 ) ;
F_41 ( & V_1 -> V_6 . V_83 ) ;
}
static inline unsigned long F_42 ( long V_84 )
{
if ( V_84 >= ( V_85 - 1 ) / V_86 )
return V_85 - 1 ;
else
return V_84 * V_86 ;
}
static enum V_87 F_43 ( struct V_88 * V_89 )
{
struct V_90 * V_91 = F_12 ( V_89 , struct V_90 , V_92 ) ;
struct V_18 * V_19 = F_12 ( V_91 , struct V_18 , V_67 ) ;
struct V_1 * V_1 = F_44 ( V_19 ) ;
unsigned long V_93 = F_45 () ;
long V_94 = V_95 ;
int V_96 = 0 ;
int V_49 = 0 ;
F_46 ( & V_19 -> V_97 ) ;
if ( V_19 -> V_98 . V_99 == V_100 )
goto V_66;
if ( V_19 -> V_98 . V_99 == V_101 )
goto V_102;
if ( V_19 -> V_103 . V_104 ) {
long V_105 = V_19 -> V_103 . V_104 +
V_19 -> V_106 . V_107 - V_93 ;
if ( V_105 <= 0 ) {
if ( V_19 -> V_108 & V_109 ) {
V_19 -> V_106 . V_107 = V_93 - V_19 -> V_110 - 1 ;
V_105 = V_19 -> V_103 . V_104 - V_19 -> V_110 ;
} else
goto V_102;
}
if ( V_105 < V_94 )
V_94 = V_105 ;
}
if ( V_19 -> V_103 . V_111 ) {
long V_105 = V_19 -> V_103 . V_111 +
( V_19 -> V_106 . V_112 ? : V_93 ) - V_93 ;
if ( V_105 <= 0 )
goto V_102;
if ( V_105 < V_94 )
V_94 = V_105 ;
}
if ( V_19 -> V_98 . V_113 )
goto V_114;
if ( V_19 -> V_103 . V_115 ) {
long V_105 = V_19 -> V_103 . V_115 +
V_19 -> V_106 . V_107 - V_93 ;
if ( V_105 <= 0 ) {
V_96 = 1 ;
V_19 -> V_108 &= ~ V_109 ;
} else if ( V_105 < V_94 ) {
V_94 = V_105 ;
V_19 -> V_108 |= V_109 ;
V_19 -> V_110 = V_105 ;
}
}
if ( V_19 -> V_103 . V_116 ) {
long V_105 = V_19 -> V_103 . V_116 +
( V_19 -> V_106 . V_112 ? : V_93 ) - V_93 ;
if ( V_105 <= 0 )
V_96 = 1 ;
else if ( V_105 < V_94 )
V_94 = V_105 ;
}
V_19 -> V_98 . V_113 = V_96 ;
if ( V_96 )
F_47 ( V_19 , 0 , 0 ) ;
V_114:
if ( V_94 != V_95 ) {
F_48 ( & V_19 -> V_67 , F_49 ( V_94 , 0 ) , V_117 ) ;
}
goto V_66;
V_102:
if ( V_19 -> V_98 . V_99 == V_118 && V_19 -> V_21 . V_8 == 0 ) {
V_19 -> V_98 . V_99 = V_101 ;
F_41 ( & V_1 -> V_6 . V_83 ) ;
V_94 = 2 ;
goto V_114;
}
V_49 = F_50 ( V_19 ) ;
if ( ! V_49 )
F_47 ( V_19 , 1 , 0 ) ;
F_51 ( V_19 , V_49 ? 0 : 1 ,
F_52 ( V_119 ) ,
F_53 ( V_119 ) , 0 ) ;
V_66:
F_54 ( & V_19 -> V_97 ) ;
return V_120 ;
}
struct V_18 * F_55 ( struct V_1 * V_1 )
{
struct V_18 * V_19 ;
V_19 = F_56 ( sizeof( struct V_18 ) , V_121 ) ;
if ( V_19 ) {
F_57 ( & V_19 -> F_44 , V_1 ) ;
F_58 ( & V_19 -> V_122 , 1 ) ;
F_58 ( & V_19 -> V_123 , 0 ) ;
F_59 ( & V_19 -> V_98 . V_124 ) ;
F_60 ( & V_19 -> V_23 ) ;
F_60 ( & V_19 -> V_24 ) ;
F_60 ( & V_19 -> V_25 ) ;
F_61 ( & V_19 -> V_67 , F_43 ,
V_125 , V_126 ) ;
F_62 ( & V_19 -> V_68 , V_127 ,
( unsigned long ) V_19 ) ;
V_19 -> V_106 . V_107 = F_45 () ;
V_19 -> V_103 . V_128 = V_129 ;
V_19 -> V_103 . V_130 = V_129 ;
V_19 -> V_103 . V_131 = V_129 ;
V_19 -> V_103 . V_132 = V_129 ;
V_19 -> V_133 = 0 ;
V_19 -> V_134 = 0 ;
V_19 -> V_75 = NULL ;
V_19 -> V_76 = NULL ;
F_63 ( & V_19 -> V_97 ) ;
}
return V_19 ;
}
void F_64 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = F_44 ( V_19 ) ;
F_65 ( V_19 -> V_98 . V_99 != V_100 ) ;
F_16 ( & V_81 ) ;
F_9 ( & V_19 -> V_135 , & V_1 -> V_6 . V_82 ) ;
F_17 ( & V_81 ) ;
F_66 ( & V_1 -> V_6 . V_79 ) ;
}
int F_50 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = F_44 ( V_19 ) ;
int V_49 = - V_136 ;
if ( V_19 -> V_98 . V_99 != V_100 ) {
V_19 -> V_98 . V_99 = V_100 ;
F_46 ( & V_41 ) ;
F_67 ( & V_19 -> V_98 . V_124 ) ;
F_68 ( & V_19 -> V_23 ) ;
F_68 ( & V_19 -> V_24 ) ;
if ( V_19 -> V_21 . V_8 )
F_68 ( & V_19 -> V_25 ) ;
V_1 -> V_6 . V_137 -- ;
F_54 ( & V_41 ) ;
F_69 ( V_19 ) ;
V_49 = 0 ;
}
return V_49 ;
}
int F_70 ( struct V_18 * V_19 )
{
int V_49 ;
F_16 ( & V_19 -> V_97 ) ;
V_49 = F_50 ( V_19 ) ;
F_17 ( & V_19 -> V_97 ) ;
return V_49 ;
}
static inline int
F_71 ( struct V_1 * V_1 , T_4 V_9 , struct V_138 * V_139 )
{
int V_38 , V_49 = 0 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
F_72 (x, net->xfrm.state_bydst+i, bydst) {
if ( F_73 ( V_19 -> V_21 . V_9 , V_9 ) &&
( V_49 = F_74 ( V_19 ) ) != 0 ) {
F_51 ( V_19 , 0 ,
V_139 -> V_140 ,
V_139 -> V_141 ,
V_139 -> V_142 ) ;
return V_49 ;
}
}
}
return V_49 ;
}
static inline int
F_71 ( struct V_1 * V_1 , T_4 V_9 , struct V_138 * V_139 )
{
return 0 ;
}
int F_75 ( struct V_1 * V_1 , T_4 V_9 , struct V_138 * V_139 )
{
int V_38 , V_49 = 0 , V_143 = 0 ;
F_16 ( & V_41 ) ;
V_49 = F_71 ( V_1 , V_9 , V_139 ) ;
if ( V_49 )
goto V_66;
V_49 = - V_136 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
V_144:
F_72 (x, net->xfrm.state_bydst+i, bydst) {
if ( ! F_76 ( V_19 ) &&
F_73 ( V_19 -> V_21 . V_9 , V_9 ) ) {
F_77 ( V_19 ) ;
F_17 ( & V_41 ) ;
V_49 = F_70 ( V_19 ) ;
F_51 ( V_19 , V_49 ? 0 : 1 ,
V_139 -> V_140 ,
V_139 -> V_141 ,
V_139 -> V_142 ) ;
F_69 ( V_19 ) ;
if ( ! V_49 )
V_143 ++ ;
F_16 ( & V_41 ) ;
goto V_144;
}
}
}
if ( V_143 )
V_49 = 0 ;
V_66:
F_17 ( & V_41 ) ;
F_41 ( & V_1 -> V_6 . V_83 ) ;
return V_49 ;
}
void F_78 ( struct V_1 * V_1 , struct V_145 * V_146 )
{
F_16 ( & V_41 ) ;
V_146 -> V_147 = V_1 -> V_6 . V_137 ;
V_146 -> V_148 = V_1 -> V_6 . V_7 ;
V_146 -> V_149 = V_150 ;
F_17 ( & V_41 ) ;
}
static int
F_79 ( struct V_18 * V_19 , const struct V_151 * V_152 ,
const struct V_153 * V_154 ,
const T_1 * V_2 , const T_1 * V_3 ,
unsigned short V_5 )
{
struct V_46 * V_47 = F_20 ( V_5 ) ;
if ( ! V_47 )
return - 1 ;
V_47 -> V_155 ( & V_19 -> V_156 , V_152 ) ;
if ( V_5 != V_154 -> V_157 ) {
F_23 ( V_47 ) ;
V_47 = F_20 ( V_154 -> V_157 ) ;
if ( ! V_47 )
return - 1 ;
}
V_47 -> V_158 ( V_19 , V_154 , V_2 , V_3 ) ;
F_23 ( V_47 ) ;
return 0 ;
}
static struct V_18 * F_80 ( struct V_1 * V_1 , T_2 V_159 ,
const T_1 * V_2 ,
T_3 V_8 , T_4 V_9 ,
unsigned short V_5 )
{
unsigned int V_20 = F_5 ( V_1 , V_2 , V_8 , V_9 , V_5 ) ;
struct V_18 * V_19 ;
F_72 (x, net->xfrm.state_byspi+h, byspi) {
if ( V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_21 . V_8 != V_8 ||
V_19 -> V_21 . V_9 != V_9 ||
! F_81 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) )
continue;
if ( ( V_159 & V_19 -> V_159 . V_160 ) != V_19 -> V_159 . V_161 )
continue;
F_77 ( V_19 ) ;
return V_19 ;
}
return NULL ;
}
static struct V_18 * F_82 ( struct V_1 * V_1 , T_2 V_159 ,
const T_1 * V_2 ,
const T_1 * V_3 ,
T_4 V_9 , unsigned short V_5 )
{
unsigned int V_20 = F_3 ( V_1 , V_2 , V_3 , V_5 ) ;
struct V_18 * V_19 ;
F_72 (x, net->xfrm.state_bysrc+h, bysrc) {
if ( V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_21 . V_9 != V_9 ||
! F_81 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) ||
! F_81 ( & V_19 -> V_22 . V_3 , V_3 , V_5 ) )
continue;
if ( ( V_159 & V_19 -> V_159 . V_160 ) != V_19 -> V_159 . V_161 )
continue;
F_77 ( V_19 ) ;
return V_19 ;
}
return NULL ;
}
static inline struct V_18 *
F_83 ( struct V_18 * V_19 , int V_162 , int V_5 )
{
struct V_1 * V_1 = F_44 ( V_19 ) ;
T_2 V_159 = V_19 -> V_159 . V_161 & V_19 -> V_159 . V_160 ;
if ( V_162 )
return F_80 ( V_1 , V_159 , & V_19 -> V_21 . V_2 ,
V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_5 ) ;
else
return F_82 ( V_1 , V_159 ,
& V_19 -> V_21 . V_2 ,
& V_19 -> V_22 . V_3 ,
V_19 -> V_21 . V_9 , V_5 ) ;
}
static void F_84 ( struct V_1 * V_1 , int V_163 )
{
if ( V_163 &&
( V_1 -> V_6 . V_7 + 1 ) < V_150 &&
V_1 -> V_6 . V_137 > V_1 -> V_6 . V_7 )
F_66 ( & V_1 -> V_6 . V_28 ) ;
}
static void F_85 ( struct V_164 * V_165 , struct V_18 * V_19 ,
const struct V_151 * V_152 , unsigned short V_5 ,
struct V_18 * * V_166 , int * V_167 ,
int * error )
{
if ( V_19 -> V_98 . V_99 == V_168 ) {
if ( ( V_19 -> V_156 . V_5 &&
! F_86 ( & V_19 -> V_156 , V_152 , V_19 -> V_156 . V_5 ) ) ||
! F_87 ( V_19 , V_165 , V_152 ) )
return;
if ( ! * V_166 ||
( * V_166 ) -> V_98 . V_113 > V_19 -> V_98 . V_113 ||
( ( * V_166 ) -> V_98 . V_113 == V_19 -> V_98 . V_113 &&
( * V_166 ) -> V_106 . V_107 < V_19 -> V_106 . V_107 ) )
* V_166 = V_19 ;
} else if ( V_19 -> V_98 . V_99 == V_118 ) {
* V_167 = 1 ;
} else if ( V_19 -> V_98 . V_99 == V_169 ||
V_19 -> V_98 . V_99 == V_101 ) {
if ( F_86 ( & V_19 -> V_156 , V_152 , V_19 -> V_156 . V_5 ) &&
F_87 ( V_19 , V_165 , V_152 ) )
* error = - V_136 ;
}
}
struct V_18 *
F_88 ( const T_1 * V_2 , const T_1 * V_3 ,
const struct V_151 * V_152 , struct V_153 * V_154 ,
struct V_164 * V_165 , int * V_49 ,
unsigned short V_5 )
{
static T_1 V_170 = { } ;
struct V_1 * V_1 = F_89 ( V_165 ) ;
unsigned int V_20 , V_171 ;
struct V_18 * V_19 , * V_172 , * V_173 ;
int V_174 = 0 ;
int error = 0 ;
struct V_18 * V_166 = NULL ;
T_2 V_159 = V_165 -> V_159 . V_161 & V_165 -> V_159 . V_160 ;
unsigned short V_157 = V_154 -> V_157 ;
V_173 = NULL ;
F_16 ( & V_41 ) ;
V_20 = F_1 ( V_1 , V_2 , V_3 , V_154 -> V_4 , V_157 ) ;
F_72 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_157 &&
V_19 -> V_22 . V_4 == V_154 -> V_4 &&
( V_159 & V_19 -> V_159 . V_160 ) == V_19 -> V_159 . V_161 &&
! ( V_19 -> V_22 . V_175 & V_176 ) &&
F_90 ( V_19 , V_2 , V_3 , V_157 ) &&
V_154 -> V_59 == V_19 -> V_22 . V_59 &&
V_154 -> V_21 . V_9 == V_19 -> V_21 . V_9 &&
( V_154 -> V_21 . V_8 == V_19 -> V_21 . V_8 || ! V_154 -> V_21 . V_8 ) )
F_85 ( V_165 , V_19 , V_152 , V_157 ,
& V_166 , & V_174 , & error ) ;
}
if ( V_166 || V_174 )
goto V_177;
V_171 = F_1 ( V_1 , V_2 , & V_170 , V_154 -> V_4 , V_157 ) ;
F_72 (x, net->xfrm.state_bydst+h_wildcard, bydst) {
if ( V_19 -> V_22 . V_5 == V_157 &&
V_19 -> V_22 . V_4 == V_154 -> V_4 &&
( V_159 & V_19 -> V_159 . V_160 ) == V_19 -> V_159 . V_161 &&
! ( V_19 -> V_22 . V_175 & V_176 ) &&
F_81 ( & V_19 -> V_21 . V_2 , V_2 , V_157 ) &&
V_154 -> V_59 == V_19 -> V_22 . V_59 &&
V_154 -> V_21 . V_9 == V_19 -> V_21 . V_9 &&
( V_154 -> V_21 . V_8 == V_19 -> V_21 . V_8 || ! V_154 -> V_21 . V_8 ) )
F_85 ( V_165 , V_19 , V_152 , V_157 ,
& V_166 , & V_174 , & error ) ;
}
V_177:
V_19 = V_166 ;
if ( ! V_19 && ! error && ! V_174 ) {
if ( V_154 -> V_21 . V_8 &&
( V_172 = F_80 ( V_1 , V_159 , V_2 , V_154 -> V_21 . V_8 ,
V_154 -> V_21 . V_9 , V_157 ) ) != NULL ) {
V_173 = V_172 ;
error = - V_53 ;
goto V_66;
}
V_19 = F_55 ( V_1 ) ;
if ( V_19 == NULL ) {
error = - V_178 ;
goto V_66;
}
F_79 ( V_19 , V_152 , V_154 , V_2 , V_3 , V_5 ) ;
memcpy ( & V_19 -> V_159 , & V_165 -> V_159 , sizeof( V_19 -> V_159 ) ) ;
error = F_91 ( V_19 , V_165 -> V_179 , V_152 -> V_180 ) ;
if ( error ) {
V_19 -> V_98 . V_99 = V_100 ;
V_173 = V_19 ;
V_19 = NULL ;
goto V_66;
}
if ( F_92 ( V_19 , V_154 , V_165 ) == 0 ) {
V_19 -> V_98 . V_99 = V_118 ;
F_93 ( & V_19 -> V_98 . V_124 , & V_1 -> V_6 . V_181 ) ;
F_9 ( & V_19 -> V_23 , V_1 -> V_6 . V_42 + V_20 ) ;
V_20 = F_3 ( V_1 , V_2 , V_3 , V_157 ) ;
F_9 ( & V_19 -> V_24 , V_1 -> V_6 . V_43 + V_20 ) ;
if ( V_19 -> V_21 . V_8 ) {
V_20 = F_5 ( V_1 , & V_19 -> V_21 . V_2 , V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_157 ) ;
F_9 ( & V_19 -> V_25 , V_1 -> V_6 . V_44 + V_20 ) ;
}
V_19 -> V_103 . V_104 = V_1 -> V_6 . V_182 ;
F_48 ( & V_19 -> V_67 , F_49 ( V_1 -> V_6 . V_182 , 0 ) , V_117 ) ;
V_1 -> V_6 . V_137 ++ ;
F_84 ( V_1 , V_19 -> V_23 . V_94 != NULL ) ;
} else {
V_19 -> V_98 . V_99 = V_100 ;
V_173 = V_19 ;
V_19 = NULL ;
error = - V_136 ;
}
}
V_66:
if ( V_19 )
F_77 ( V_19 ) ;
else
* V_49 = V_174 ? - V_183 : error ;
F_17 ( & V_41 ) ;
if ( V_173 )
F_69 ( V_173 ) ;
return V_19 ;
}
struct V_18 *
F_94 ( struct V_1 * V_1 , T_2 V_159 ,
T_1 * V_2 , T_1 * V_3 ,
unsigned short V_5 , T_4 V_59 , T_4 V_9 , T_2 V_4 )
{
unsigned int V_20 ;
struct V_18 * V_184 = NULL , * V_19 = NULL ;
F_46 ( & V_41 ) ;
V_20 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_72 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_5 &&
V_19 -> V_22 . V_4 == V_4 &&
( V_159 & V_19 -> V_159 . V_160 ) == V_19 -> V_159 . V_161 &&
! ( V_19 -> V_22 . V_175 & V_176 ) &&
F_90 ( V_19 , V_2 , V_3 , V_5 ) &&
V_59 == V_19 -> V_22 . V_59 &&
V_9 == V_19 -> V_21 . V_9 &&
V_19 -> V_98 . V_99 == V_168 ) {
V_184 = V_19 ;
break;
}
}
if ( V_184 )
F_77 ( V_184 ) ;
F_54 ( & V_41 ) ;
return V_184 ;
}
static void F_95 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = F_44 ( V_19 ) ;
unsigned int V_20 ;
F_93 ( & V_19 -> V_98 . V_124 , & V_1 -> V_6 . V_181 ) ;
V_20 = F_1 ( V_1 , & V_19 -> V_21 . V_2 , & V_19 -> V_22 . V_3 ,
V_19 -> V_22 . V_4 , V_19 -> V_22 . V_5 ) ;
F_9 ( & V_19 -> V_23 , V_1 -> V_6 . V_42 + V_20 ) ;
V_20 = F_3 ( V_1 , & V_19 -> V_21 . V_2 , & V_19 -> V_22 . V_3 , V_19 -> V_22 . V_5 ) ;
F_9 ( & V_19 -> V_24 , V_1 -> V_6 . V_43 + V_20 ) ;
if ( V_19 -> V_21 . V_8 ) {
V_20 = F_5 ( V_1 , & V_19 -> V_21 . V_2 , V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 ,
V_19 -> V_22 . V_5 ) ;
F_9 ( & V_19 -> V_25 , V_1 -> V_6 . V_44 + V_20 ) ;
}
F_48 ( & V_19 -> V_67 , F_49 ( 1 , 0 ) , V_117 ) ;
if ( V_19 -> V_133 )
F_96 ( & V_19 -> V_68 , V_185 + V_19 -> V_133 ) ;
F_41 ( & V_1 -> V_6 . V_83 ) ;
V_1 -> V_6 . V_137 ++ ;
F_84 ( V_1 , V_19 -> V_23 . V_94 != NULL ) ;
}
static void F_97 ( struct V_18 * V_186 )
{
struct V_1 * V_1 = F_44 ( V_186 ) ;
unsigned short V_5 = V_186 -> V_22 . V_5 ;
T_2 V_4 = V_186 -> V_22 . V_4 ;
struct V_18 * V_19 ;
unsigned int V_20 ;
T_2 V_159 = V_186 -> V_159 . V_161 & V_186 -> V_159 . V_160 ;
V_20 = F_1 ( V_1 , & V_186 -> V_21 . V_2 , & V_186 -> V_22 . V_3 , V_4 , V_5 ) ;
F_72 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_5 &&
V_19 -> V_22 . V_4 == V_4 &&
( V_159 & V_19 -> V_159 . V_160 ) == V_19 -> V_159 . V_161 &&
F_81 ( & V_19 -> V_21 . V_2 , & V_186 -> V_21 . V_2 , V_5 ) &&
F_81 ( & V_19 -> V_22 . V_3 , & V_186 -> V_22 . V_3 , V_5 ) )
V_19 -> V_187 ++ ;
}
}
void F_98 ( struct V_18 * V_19 )
{
F_16 ( & V_41 ) ;
F_97 ( V_19 ) ;
F_95 ( V_19 ) ;
F_17 ( & V_41 ) ;
}
static struct V_18 * F_99 ( struct V_1 * V_1 ,
const struct V_188 * V_160 ,
unsigned short V_5 , T_4 V_59 ,
T_2 V_4 , T_4 V_9 ,
const T_1 * V_2 ,
const T_1 * V_3 ,
int V_189 )
{
unsigned int V_20 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
struct V_18 * V_19 ;
T_2 V_159 = V_160 -> V_161 & V_160 -> V_160 ;
F_72 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_4 != V_4 ||
V_19 -> V_22 . V_59 != V_59 ||
V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_98 . V_99 != V_118 ||
V_19 -> V_21 . V_8 != 0 ||
V_19 -> V_21 . V_9 != V_9 ||
( V_159 & V_19 -> V_159 . V_160 ) != V_19 -> V_159 . V_161 ||
! F_81 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) ||
! F_81 ( & V_19 -> V_22 . V_3 , V_3 , V_5 ) )
continue;
F_77 ( V_19 ) ;
return V_19 ;
}
if ( ! V_189 )
return NULL ;
V_19 = F_55 ( V_1 ) ;
if ( F_22 ( V_19 ) ) {
switch ( V_5 ) {
case V_190 :
V_19 -> V_156 . V_2 . V_191 = V_2 -> V_191 ;
V_19 -> V_156 . V_3 . V_191 = V_3 -> V_191 ;
V_19 -> V_156 . V_192 = 32 ;
V_19 -> V_156 . V_193 = 32 ;
V_19 -> V_22 . V_3 . V_191 = V_3 -> V_191 ;
V_19 -> V_21 . V_2 . V_191 = V_2 -> V_191 ;
break;
case V_194 :
* (struct V_195 * ) V_19 -> V_156 . V_2 . V_196 = * (struct V_195 * ) V_2 ;
* (struct V_195 * ) V_19 -> V_156 . V_3 . V_196 = * (struct V_195 * ) V_3 ;
V_19 -> V_156 . V_192 = 128 ;
V_19 -> V_156 . V_193 = 128 ;
* (struct V_195 * ) V_19 -> V_22 . V_3 . V_196 = * (struct V_195 * ) V_3 ;
* (struct V_195 * ) V_19 -> V_21 . V_2 . V_196 = * (struct V_195 * ) V_2 ;
break;
}
V_19 -> V_98 . V_99 = V_118 ;
V_19 -> V_21 . V_9 = V_9 ;
V_19 -> V_22 . V_5 = V_5 ;
V_19 -> V_22 . V_59 = V_59 ;
V_19 -> V_22 . V_4 = V_4 ;
V_19 -> V_159 . V_161 = V_160 -> V_161 ;
V_19 -> V_159 . V_160 = V_160 -> V_160 ;
V_19 -> V_103 . V_104 = V_1 -> V_6 . V_182 ;
F_77 ( V_19 ) ;
F_48 ( & V_19 -> V_67 , F_49 ( V_1 -> V_6 . V_182 , 0 ) , V_117 ) ;
F_93 ( & V_19 -> V_98 . V_124 , & V_1 -> V_6 . V_181 ) ;
F_9 ( & V_19 -> V_23 , V_1 -> V_6 . V_42 + V_20 ) ;
V_20 = F_3 ( V_1 , V_2 , V_3 , V_5 ) ;
F_9 ( & V_19 -> V_24 , V_1 -> V_6 . V_43 + V_20 ) ;
V_1 -> V_6 . V_137 ++ ;
F_84 ( V_1 , V_19 -> V_23 . V_94 != NULL ) ;
}
return V_19 ;
}
int F_100 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = F_44 ( V_19 ) ;
struct V_18 * V_197 , * V_173 ;
int V_5 ;
int V_49 ;
T_2 V_159 = V_19 -> V_159 . V_161 & V_19 -> V_159 . V_160 ;
int V_162 = F_73 ( V_19 -> V_21 . V_9 , V_198 ) ;
V_5 = V_19 -> V_22 . V_5 ;
V_173 = NULL ;
F_16 ( & V_41 ) ;
V_197 = F_83 ( V_19 , V_162 , V_5 ) ;
if ( V_197 ) {
V_173 = V_197 ;
V_197 = NULL ;
V_49 = - V_53 ;
goto V_66;
}
if ( V_162 && V_19 -> V_98 . V_199 ) {
V_197 = F_101 ( V_1 , V_159 , V_19 -> V_98 . V_199 ) ;
if ( V_197 && ( ( V_197 -> V_21 . V_9 != V_19 -> V_21 . V_9 ) ||
! F_81 ( & V_197 -> V_21 . V_2 , & V_19 -> V_21 . V_2 , V_5 ) ) ) {
V_173 = V_197 ;
V_197 = NULL ;
}
}
if ( V_162 && ! V_197 )
V_197 = F_99 ( V_1 , & V_19 -> V_159 , V_5 , V_19 -> V_22 . V_59 ,
V_19 -> V_22 . V_4 , V_19 -> V_21 . V_9 ,
& V_19 -> V_21 . V_2 , & V_19 -> V_22 . V_3 , 0 ) ;
F_97 ( V_19 ) ;
F_95 ( V_19 ) ;
V_49 = 0 ;
V_66:
F_17 ( & V_41 ) ;
if ( V_197 ) {
F_70 ( V_197 ) ;
F_69 ( V_197 ) ;
}
if ( V_173 )
F_69 ( V_173 ) ;
return V_49 ;
}
static struct V_18 * F_102 ( struct V_18 * V_200 , int * V_201 )
{
struct V_1 * V_1 = F_44 ( V_200 ) ;
int V_49 = - V_178 ;
struct V_18 * V_19 = F_55 ( V_1 ) ;
if ( ! V_19 )
goto V_66;
memcpy ( & V_19 -> V_21 , & V_200 -> V_21 , sizeof( V_19 -> V_21 ) ) ;
memcpy ( & V_19 -> V_156 , & V_200 -> V_156 , sizeof( V_19 -> V_156 ) ) ;
memcpy ( & V_19 -> V_103 , & V_200 -> V_103 , sizeof( V_19 -> V_103 ) ) ;
V_19 -> V_22 . V_59 = V_200 -> V_22 . V_59 ;
V_19 -> V_22 . V_202 = V_200 -> V_22 . V_202 ;
V_19 -> V_22 . V_4 = V_200 -> V_22 . V_4 ;
V_19 -> V_22 . V_5 = V_200 -> V_22 . V_5 ;
V_19 -> V_22 . V_3 = V_200 -> V_22 . V_3 ;
if ( V_200 -> V_69 ) {
V_19 -> V_69 = F_103 ( V_200 -> V_69 ) ;
if ( ! V_19 -> V_69 )
goto error;
}
V_19 -> V_22 . V_203 = V_200 -> V_22 . V_203 ;
if ( V_200 -> V_70 ) {
V_19 -> V_70 = F_104 ( V_200 -> V_70 ) ;
if ( ! V_19 -> V_70 )
goto error;
}
V_19 -> V_22 . V_204 = V_200 -> V_22 . V_204 ;
if ( V_200 -> V_71 ) {
V_19 -> V_71 = F_104 ( V_200 -> V_71 ) ;
if ( ! V_19 -> V_71 )
goto error;
}
V_19 -> V_22 . V_205 = V_200 -> V_22 . V_205 ;
if ( V_200 -> V_61 ) {
V_19 -> V_61 = F_105 ( V_200 -> V_61 , sizeof( * V_19 -> V_61 ) , V_206 ) ;
if ( ! V_19 -> V_61 )
goto error;
}
if ( V_200 -> V_72 ) {
V_19 -> V_72 = F_105 ( V_200 -> V_72 , sizeof( * V_19 -> V_72 ) ,
V_206 ) ;
if ( ! V_19 -> V_72 )
goto error;
}
if ( V_200 -> V_73 ) {
V_49 = F_106 ( V_19 , V_200 ) ;
if ( V_49 )
goto error;
}
memcpy ( & V_19 -> V_159 , & V_200 -> V_159 , sizeof( V_19 -> V_159 ) ) ;
V_49 = F_107 ( V_19 ) ;
if ( V_49 )
goto error;
V_19 -> V_22 . V_175 = V_200 -> V_22 . V_175 ;
V_19 -> V_22 . V_207 = V_200 -> V_22 . V_207 ;
V_19 -> V_106 . V_107 = V_200 -> V_106 . V_107 ;
V_19 -> V_98 . V_99 = V_200 -> V_98 . V_99 ;
V_19 -> V_98 . V_199 = V_200 -> V_98 . V_199 ;
return V_19 ;
error:
F_69 ( V_19 ) ;
V_66:
if ( V_201 )
* V_201 = V_49 ;
return NULL ;
}
struct V_18 * F_108 ( struct V_208 * V_160 )
{
unsigned int V_20 ;
struct V_18 * V_19 ;
if ( V_160 -> V_4 ) {
V_20 = F_1 ( & V_209 , & V_160 -> V_210 , & V_160 -> V_211 ,
V_160 -> V_4 , V_160 -> V_212 ) ;
F_72 (x, init_net.xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_59 != V_160 -> V_59 ||
V_19 -> V_21 . V_9 != V_160 -> V_9 )
continue;
if ( V_160 -> V_4 && V_19 -> V_22 . V_4 != V_160 -> V_4 )
continue;
if ( ! F_81 ( & V_19 -> V_21 . V_2 , & V_160 -> V_210 ,
V_160 -> V_212 ) ||
! F_81 ( & V_19 -> V_22 . V_3 , & V_160 -> V_211 ,
V_160 -> V_212 ) )
continue;
F_77 ( V_19 ) ;
return V_19 ;
}
} else {
V_20 = F_3 ( & V_209 , & V_160 -> V_210 , & V_160 -> V_211 ,
V_160 -> V_212 ) ;
F_72 (x, init_net.xfrm.state_bysrc+h, bysrc) {
if ( V_19 -> V_22 . V_59 != V_160 -> V_59 ||
V_19 -> V_21 . V_9 != V_160 -> V_9 )
continue;
if ( ! F_81 ( & V_19 -> V_21 . V_2 , & V_160 -> V_210 ,
V_160 -> V_212 ) ||
! F_81 ( & V_19 -> V_22 . V_3 , & V_160 -> V_211 ,
V_160 -> V_212 ) )
continue;
F_77 ( V_19 ) ;
return V_19 ;
}
}
return NULL ;
}
struct V_18 * F_109 ( struct V_18 * V_19 ,
struct V_208 * V_160 )
{
struct V_18 * V_213 ;
int V_49 ;
V_213 = F_102 ( V_19 , & V_49 ) ;
if ( ! V_213 )
return NULL ;
memcpy ( & V_213 -> V_21 . V_2 , & V_160 -> V_214 , sizeof( V_213 -> V_21 . V_2 ) ) ;
memcpy ( & V_213 -> V_22 . V_3 , & V_160 -> V_215 , sizeof( V_213 -> V_22 . V_3 ) ) ;
if ( F_81 ( & V_19 -> V_21 . V_2 , & V_160 -> V_214 , V_160 -> V_216 ) ) {
F_98 ( V_213 ) ;
} else {
if ( ( V_49 = F_100 ( V_213 ) ) < 0 )
goto error;
}
return V_213 ;
error:
F_69 ( V_213 ) ;
return NULL ;
}
int F_110 ( struct V_18 * V_19 )
{
struct V_18 * V_197 , * V_173 ;
int V_49 ;
int V_162 = F_73 ( V_19 -> V_21 . V_9 , V_198 ) ;
V_173 = NULL ;
F_16 ( & V_41 ) ;
V_197 = F_83 ( V_19 , V_162 , V_19 -> V_22 . V_5 ) ;
V_49 = - V_136 ;
if ( ! V_197 )
goto V_66;
if ( F_76 ( V_197 ) ) {
V_173 = V_197 ;
V_49 = - V_53 ;
goto V_66;
}
if ( V_197 -> V_98 . V_99 == V_118 ) {
F_95 ( V_19 ) ;
V_19 = NULL ;
}
V_49 = 0 ;
V_66:
F_17 ( & V_41 ) ;
if ( V_173 )
F_69 ( V_173 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_19 ) {
F_70 ( V_197 ) ;
F_69 ( V_197 ) ;
return 0 ;
}
V_49 = - V_63 ;
F_16 ( & V_197 -> V_97 ) ;
if ( F_22 ( V_197 -> V_98 . V_99 == V_168 ) ) {
if ( V_19 -> V_61 && V_197 -> V_61 )
memcpy ( V_197 -> V_61 , V_19 -> V_61 , sizeof( * V_197 -> V_61 ) ) ;
if ( V_19 -> V_72 && V_197 -> V_72 ) {
memcpy ( V_197 -> V_72 , V_19 -> V_72 , sizeof( * V_197 -> V_72 ) ) ;
}
if ( ! V_162 && memcmp ( & V_197 -> V_156 , & V_19 -> V_156 , sizeof( V_197 -> V_156 ) ) )
memcpy ( & V_197 -> V_156 , & V_19 -> V_156 , sizeof( V_197 -> V_156 ) ) ;
memcpy ( & V_197 -> V_103 , & V_19 -> V_103 , sizeof( V_197 -> V_103 ) ) ;
V_197 -> V_98 . V_113 = 0 ;
F_48 ( & V_197 -> V_67 , F_49 ( 1 , 0 ) , V_117 ) ;
if ( V_197 -> V_106 . V_112 )
F_111 ( V_197 ) ;
V_49 = 0 ;
V_19 -> V_98 . V_99 = V_100 ;
F_112 ( V_19 ) ;
}
F_17 ( & V_197 -> V_97 ) ;
F_69 ( V_197 ) ;
return V_49 ;
}
int F_111 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_106 . V_112 )
V_19 -> V_106 . V_112 = F_45 () ;
if ( V_19 -> V_106 . V_217 >= V_19 -> V_103 . V_131 ||
V_19 -> V_106 . V_218 >= V_19 -> V_103 . V_132 ) {
V_19 -> V_98 . V_99 = V_101 ;
F_48 ( & V_19 -> V_67 , F_49 ( 0 , 0 ) , V_117 ) ;
return - V_63 ;
}
if ( ! V_19 -> V_98 . V_113 &&
( V_19 -> V_106 . V_217 >= V_19 -> V_103 . V_128 ||
V_19 -> V_106 . V_218 >= V_19 -> V_103 . V_130 ) ) {
V_19 -> V_98 . V_113 = 1 ;
F_47 ( V_19 , 0 , 0 ) ;
}
return 0 ;
}
struct V_18 *
F_113 ( struct V_1 * V_1 , T_2 V_159 , const T_1 * V_2 , T_3 V_8 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_16 ( & V_41 ) ;
V_19 = F_80 ( V_1 , V_159 , V_2 , V_8 , V_9 , V_5 ) ;
F_17 ( & V_41 ) ;
return V_19 ;
}
struct V_18 *
F_114 ( struct V_1 * V_1 , T_2 V_159 ,
const T_1 * V_2 , const T_1 * V_3 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_16 ( & V_41 ) ;
V_19 = F_82 ( V_1 , V_159 , V_2 , V_3 , V_9 , V_5 ) ;
F_17 ( & V_41 ) ;
return V_19 ;
}
struct V_18 *
F_115 ( struct V_1 * V_1 , const struct V_188 * V_159 , T_4 V_59 , T_2 V_4 ,
T_4 V_9 , const T_1 * V_2 ,
const T_1 * V_3 , int V_189 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_16 ( & V_41 ) ;
V_19 = F_99 ( V_1 , V_159 , V_5 , V_59 , V_4 , V_9 , V_2 , V_3 , V_189 ) ;
F_17 ( & V_41 ) ;
return V_19 ;
}
int
F_116 ( struct V_153 * * V_219 , struct V_153 * * V_220 , int V_221 ,
unsigned short V_5 )
{
int V_49 = 0 ;
struct V_46 * V_47 = F_20 ( V_5 ) ;
if ( ! V_47 )
return - V_50 ;
F_16 ( & V_41 ) ;
if ( V_47 -> V_222 )
V_49 = V_47 -> V_222 ( V_219 , V_220 , V_221 ) ;
F_17 ( & V_41 ) ;
F_23 ( V_47 ) ;
return V_49 ;
}
int
F_117 ( struct V_18 * * V_219 , struct V_18 * * V_220 , int V_221 ,
unsigned short V_5 )
{
int V_49 = 0 ;
struct V_46 * V_47 = F_20 ( V_5 ) ;
if ( ! V_47 )
return - V_50 ;
F_16 ( & V_41 ) ;
if ( V_47 -> V_223 )
V_49 = V_47 -> V_223 ( V_219 , V_220 , V_221 ) ;
F_17 ( & V_41 ) ;
F_23 ( V_47 ) ;
return V_49 ;
}
static struct V_18 * F_101 ( struct V_1 * V_1 , T_2 V_159 , T_2 V_199 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
F_72 (x, net->xfrm.state_bydst+i, bydst) {
if ( V_19 -> V_98 . V_199 == V_199 &&
( V_159 & V_19 -> V_159 . V_160 ) == V_19 -> V_159 . V_161 &&
V_19 -> V_98 . V_99 == V_118 ) {
F_77 ( V_19 ) ;
return V_19 ;
}
}
}
return NULL ;
}
struct V_18 * F_118 ( struct V_1 * V_1 , T_2 V_159 , T_2 V_199 )
{
struct V_18 * V_19 ;
F_16 ( & V_41 ) ;
V_19 = F_101 ( V_1 , V_159 , V_199 ) ;
F_17 ( & V_41 ) ;
return V_19 ;
}
T_2 F_119 ( void )
{
T_2 V_224 ;
static T_5 V_225 ;
do {
V_224 = F_120 ( & V_225 ) ;
} while ( ! V_224 );
return V_224 ;
}
int F_121 ( struct V_18 * V_19 , T_2 V_226 , T_2 V_227 )
{
struct V_1 * V_1 = F_44 ( V_19 ) ;
unsigned int V_20 ;
struct V_18 * V_172 ;
int V_49 = - V_54 ;
T_3 V_228 = F_122 ( V_226 ) ;
T_3 V_229 = F_122 ( V_227 ) ;
T_2 V_159 = V_19 -> V_159 . V_161 & V_19 -> V_159 . V_160 ;
F_16 ( & V_19 -> V_97 ) ;
if ( V_19 -> V_98 . V_99 == V_100 )
goto V_230;
V_49 = 0 ;
if ( V_19 -> V_21 . V_8 )
goto V_230;
V_49 = - V_54 ;
if ( V_228 == V_229 ) {
V_172 = F_113 ( V_1 , V_159 , & V_19 -> V_21 . V_2 , V_228 , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
if ( V_172 ) {
F_69 ( V_172 ) ;
goto V_230;
}
V_19 -> V_21 . V_8 = V_228 ;
} else {
T_2 V_8 = 0 ;
for ( V_20 = 0 ; V_20 < V_227 - V_226 + 1 ; V_20 ++ ) {
V_8 = V_226 + F_123 () % ( V_227 - V_226 + 1 ) ;
V_172 = F_113 ( V_1 , V_159 , & V_19 -> V_21 . V_2 , F_122 ( V_8 ) , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
if ( V_172 == NULL ) {
V_19 -> V_21 . V_8 = F_122 ( V_8 ) ;
break;
}
F_69 ( V_172 ) ;
}
}
if ( V_19 -> V_21 . V_8 ) {
F_16 ( & V_41 ) ;
V_20 = F_5 ( V_1 , & V_19 -> V_21 . V_2 , V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
F_9 ( & V_19 -> V_25 , V_1 -> V_6 . V_44 + V_20 ) ;
F_17 ( & V_41 ) ;
V_49 = 0 ;
}
V_230:
F_17 ( & V_19 -> V_97 ) ;
return V_49 ;
}
int F_124 ( struct V_1 * V_1 , struct F_124 * V_231 ,
int (* F_125)( struct V_18 * , int , void * ) ,
void * V_232 )
{
struct V_18 * V_99 ;
struct F_124 * V_19 ;
int V_49 = 0 ;
if ( V_231 -> V_199 != 0 && F_126 ( & V_231 -> V_124 ) )
return 0 ;
F_16 ( & V_41 ) ;
if ( F_126 ( & V_231 -> V_124 ) )
V_19 = F_127 ( & V_1 -> V_6 . V_181 , struct F_124 , V_124 ) ;
else
V_19 = F_128 ( & V_231 -> V_124 , struct F_124 , V_124 ) ;
F_129 (x, &net->xfrm.state_all, all) {
if ( V_19 -> V_99 == V_100 )
continue;
V_99 = F_12 ( V_19 , struct V_18 , V_98 ) ;
if ( ! F_73 ( V_99 -> V_21 . V_9 , V_231 -> V_9 ) )
continue;
V_49 = F_125 ( V_99 , V_231 -> V_199 , V_232 ) ;
if ( V_49 ) {
F_130 ( & V_231 -> V_124 , & V_19 -> V_124 ) ;
goto V_66;
}
V_231 -> V_199 ++ ;
}
if ( V_231 -> V_199 == 0 ) {
V_49 = - V_54 ;
goto V_66;
}
F_131 ( & V_231 -> V_124 ) ;
V_66:
F_17 ( & V_41 ) ;
return V_49 ;
}
void F_132 ( struct F_124 * V_231 , T_4 V_9 )
{
F_59 ( & V_231 -> V_124 ) ;
V_231 -> V_9 = V_9 ;
V_231 -> V_99 = V_100 ;
V_231 -> V_199 = 0 ;
}
void F_133 ( struct F_124 * V_231 )
{
if ( F_126 ( & V_231 -> V_124 ) )
return;
F_16 ( & V_41 ) ;
F_67 ( & V_231 -> V_124 ) ;
F_17 ( & V_41 ) ;
}
static void V_127 ( unsigned long V_232 )
{
struct V_18 * V_19 = (struct V_18 * ) V_232 ;
F_46 ( & V_19 -> V_97 ) ;
if ( V_19 -> V_98 . V_99 == V_168 ) {
if ( F_134 ( F_44 ( V_19 ) ) )
V_19 -> V_233 -> V_234 ( V_19 , V_235 ) ;
else
V_19 -> V_108 |= V_236 ;
}
F_54 ( & V_19 -> V_97 ) ;
}
void F_135 ( struct V_164 * V_237 , int V_238 , const struct V_239 * V_240 )
{
struct V_241 * V_98 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list)
if ( V_98 -> V_242 )
V_98 -> V_242 ( V_237 , V_238 , V_240 ) ;
F_138 () ;
}
void F_139 ( struct V_18 * V_19 , const struct V_239 * V_240 )
{
struct V_241 * V_98 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list)
if ( V_98 -> V_234 )
V_98 -> V_234 ( V_19 , V_240 ) ;
F_138 () ;
}
void F_47 ( struct V_18 * V_19 , int V_243 , T_2 V_244 )
{
struct V_1 * V_1 = F_44 ( V_19 ) ;
struct V_239 V_240 ;
V_240 . V_232 . V_243 = V_243 ;
V_240 . V_244 = V_244 ;
V_240 . V_245 = V_246 ;
F_139 ( V_19 , & V_240 ) ;
if ( V_243 )
F_41 ( & V_1 -> V_6 . V_83 ) ;
}
int F_92 ( struct V_18 * V_19 , struct V_153 * V_247 , struct V_164 * V_165 )
{
int V_49 = - V_63 , V_248 ;
struct V_241 * V_98 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list) {
V_248 = V_98 -> V_249 ( V_19 , V_247 , V_165 ) ;
if ( ! V_248 )
V_49 = V_248 ;
}
F_138 () ;
return V_49 ;
}
int F_140 ( struct V_18 * V_19 , T_1 * V_250 , T_6 V_251 )
{
int V_49 = - V_63 ;
struct V_241 * V_98 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list) {
if ( V_98 -> V_252 )
V_49 = V_98 -> V_252 ( V_19 , V_250 , V_251 ) ;
if ( ! V_49 )
break;
}
F_138 () ;
return V_49 ;
}
void F_141 ( struct V_164 * V_165 , int V_238 , int V_243 , T_2 V_244 )
{
struct V_1 * V_1 = F_89 ( V_165 ) ;
struct V_239 V_240 ;
V_240 . V_232 . V_243 = V_243 ;
V_240 . V_244 = V_244 ;
V_240 . V_245 = V_253 ;
F_135 ( V_165 , V_238 , & V_240 ) ;
if ( V_243 )
F_41 ( & V_1 -> V_6 . V_83 ) ;
}
int F_142 ( const struct V_254 * V_156 , T_4 V_238 , T_4 type ,
const struct V_208 * V_160 , int V_255 ,
const struct V_256 * V_257 )
{
int V_49 = - V_63 ;
int V_258 ;
struct V_241 * V_98 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list) {
if ( V_98 -> V_259 ) {
V_258 = V_98 -> V_259 ( V_156 , V_238 , type , V_160 , V_255 , V_257 ) ;
if ( ! V_258 )
V_49 = V_258 ;
}
}
F_138 () ;
return V_49 ;
}
int F_143 ( struct V_1 * V_1 , T_4 V_9 , struct V_254 * V_156 , T_1 * V_260 )
{
int V_49 = - V_63 ;
int V_258 ;
struct V_241 * V_98 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list) {
if ( V_98 -> V_261 ) {
V_258 = V_98 -> V_261 ( V_1 , V_9 , V_156 , V_260 ) ;
if ( ! V_258 )
V_49 = V_258 ;
}
}
F_138 () ;
return V_49 ;
}
int F_144 ( struct V_262 * V_263 , int V_264 , T_4 T_7 * V_265 , int V_266 )
{
int V_49 ;
T_4 * V_232 ;
struct V_241 * V_98 ;
struct V_164 * V_165 = NULL ;
if ( V_266 <= 0 || V_266 > V_267 )
return - V_268 ;
V_232 = F_145 ( V_266 , V_206 ) ;
if ( ! V_232 )
return - V_178 ;
V_49 = - V_269 ;
if ( F_146 ( V_232 , V_265 , V_266 ) )
goto V_66;
V_49 = - V_63 ;
F_136 () ;
F_137 (km, &xfrm_km_list, list) {
V_165 = V_98 -> V_270 ( V_263 , V_264 , V_232 ,
V_266 , & V_49 ) ;
if ( V_49 >= 0 )
break;
}
F_138 () ;
if ( V_49 >= 0 ) {
F_147 ( V_263 , V_49 , V_165 ) ;
F_148 ( V_165 ) ;
V_49 = 0 ;
}
V_66:
F_37 ( V_232 ) ;
return V_49 ;
}
int F_149 ( struct V_241 * V_98 )
{
F_16 ( & V_271 ) ;
F_150 ( & V_98 -> V_11 , & V_272 ) ;
F_17 ( & V_271 ) ;
return 0 ;
}
int F_151 ( struct V_241 * V_98 )
{
F_16 ( & V_271 ) ;
F_152 ( & V_98 -> V_11 ) ;
F_17 ( & V_271 ) ;
F_153 () ;
return 0 ;
}
int F_154 ( struct V_46 * V_47 )
{
int V_49 = 0 ;
if ( F_21 ( V_47 == NULL ) )
return - V_63 ;
if ( F_21 ( V_47 -> V_5 >= V_273 ) )
return - V_50 ;
F_16 ( & V_274 ) ;
if ( F_21 ( V_46 [ V_47 -> V_5 ] != NULL ) )
V_49 = - V_275 ;
else
F_155 ( V_46 [ V_47 -> V_5 ] , V_47 ) ;
F_17 ( & V_274 ) ;
return V_49 ;
}
int F_156 ( struct V_46 * V_47 )
{
int V_49 = 0 ;
if ( F_21 ( V_47 == NULL ) )
return - V_63 ;
if ( F_21 ( V_47 -> V_5 >= V_273 ) )
return - V_50 ;
F_16 ( & V_274 ) ;
if ( F_22 ( V_46 [ V_47 -> V_5 ] != NULL ) ) {
if ( F_21 ( V_46 [ V_47 -> V_5 ] != V_47 ) )
V_49 = - V_63 ;
else
F_157 ( V_46 [ V_47 -> V_5 ] , NULL ) ;
}
F_17 ( & V_274 ) ;
F_153 () ;
return V_49 ;
}
struct V_46 * F_20 ( unsigned int V_5 )
{
struct V_46 * V_47 ;
if ( F_21 ( V_5 >= V_273 ) )
return NULL ;
F_136 () ;
V_47 = F_158 ( V_46 [ V_5 ] ) ;
if ( F_21 ( ! V_47 ) )
F_138 () ;
return V_47 ;
}
void F_23 ( struct V_46 * V_47 )
{
F_138 () ;
}
void F_159 ( struct V_18 * V_19 )
{
if ( V_19 -> V_276 ) {
struct V_18 * V_247 = V_19 -> V_276 ;
if ( F_160 ( & V_247 -> V_123 ) == 2 )
F_70 ( V_247 ) ;
F_161 ( & V_247 -> V_123 ) ;
F_69 ( V_247 ) ;
V_19 -> V_276 = NULL ;
}
}
int F_162 ( struct V_18 * V_19 , int V_277 )
{
int V_224 ;
F_16 ( & V_19 -> V_97 ) ;
if ( V_19 -> V_98 . V_99 == V_168 &&
V_19 -> type && V_19 -> type -> V_278 )
V_224 = V_19 -> type -> V_278 ( V_19 , V_277 ) ;
else
V_224 = V_277 - V_19 -> V_22 . V_279 ;
F_17 ( & V_19 -> V_97 ) ;
return V_224 ;
}
int F_163 ( struct V_18 * V_19 , bool V_280 )
{
struct V_46 * V_47 ;
struct V_58 * V_75 ;
int V_5 = V_19 -> V_22 . V_5 ;
int V_49 ;
V_49 = - V_50 ;
V_47 = F_20 ( V_5 ) ;
if ( ! V_47 )
goto error;
V_49 = 0 ;
if ( V_47 -> V_281 )
V_49 = V_47 -> V_281 ( V_19 ) ;
F_23 ( V_47 ) ;
if ( V_49 )
goto error;
V_49 = - V_282 ;
if ( V_19 -> V_156 . V_5 != V_283 ) {
V_75 = F_32 ( V_19 -> V_22 . V_59 , V_19 -> V_156 . V_5 ) ;
if ( V_75 == NULL )
goto error;
if ( ! ( V_75 -> V_175 & V_284 ) &&
V_5 != V_19 -> V_156 . V_5 ) {
F_33 ( V_75 ) ;
goto error;
}
V_19 -> V_75 = V_75 ;
} else {
struct V_58 * V_76 ;
int V_285 = V_190 ;
V_75 = F_32 ( V_19 -> V_22 . V_59 , V_19 -> V_22 . V_5 ) ;
if ( V_75 == NULL )
goto error;
if ( ! ( V_75 -> V_175 & V_284 ) ) {
F_33 ( V_75 ) ;
goto error;
}
V_19 -> V_75 = V_75 ;
if ( V_19 -> V_22 . V_5 == V_190 )
V_285 = V_194 ;
V_76 = F_32 ( V_19 -> V_22 . V_59 , V_285 ) ;
if ( V_76 ) {
if ( V_76 -> V_175 & V_284 )
V_19 -> V_76 = V_76 ;
else
F_33 ( V_76 ) ;
}
}
V_19 -> type = F_25 ( V_19 -> V_21 . V_9 , V_5 ) ;
if ( V_19 -> type == NULL )
goto error;
V_49 = V_19 -> type -> V_286 ( V_19 ) ;
if ( V_49 )
goto error;
V_19 -> V_77 = F_32 ( V_19 -> V_22 . V_59 , V_5 ) ;
if ( V_19 -> V_77 == NULL ) {
V_49 = - V_282 ;
goto error;
}
if ( V_280 ) {
V_49 = F_164 ( V_19 ) ;
if ( V_49 )
goto error;
}
V_19 -> V_98 . V_99 = V_168 ;
error:
return V_49 ;
}
int F_107 ( struct V_18 * V_19 )
{
return F_163 ( V_19 , true ) ;
}
int T_8 F_165 ( struct V_1 * V_1 )
{
unsigned int V_287 ;
F_59 ( & V_1 -> V_6 . V_181 ) ;
V_287 = sizeof( struct V_10 ) * 8 ;
V_1 -> V_6 . V_42 = F_14 ( V_287 ) ;
if ( ! V_1 -> V_6 . V_42 )
goto V_288;
V_1 -> V_6 . V_43 = F_14 ( V_287 ) ;
if ( ! V_1 -> V_6 . V_43 )
goto V_289;
V_1 -> V_6 . V_44 = F_14 ( V_287 ) ;
if ( ! V_1 -> V_6 . V_44 )
goto V_290;
V_1 -> V_6 . V_7 = ( ( V_287 / sizeof( struct V_10 ) ) - 1 ) ;
V_1 -> V_6 . V_137 = 0 ;
F_166 ( & V_1 -> V_6 . V_28 , F_11 ) ;
F_167 ( & V_1 -> V_6 . V_82 ) ;
F_166 ( & V_1 -> V_6 . V_79 , F_39 ) ;
F_168 ( & V_1 -> V_6 . V_83 ) ;
return 0 ;
V_290:
F_15 ( V_1 -> V_6 . V_43 , V_287 ) ;
V_289:
F_15 ( V_1 -> V_6 . V_42 , V_287 ) ;
V_288:
return - V_178 ;
}
void F_169 ( struct V_1 * V_1 )
{
struct V_138 V_139 ;
unsigned int V_287 ;
F_170 ( & V_1 -> V_6 . V_28 ) ;
V_139 . V_140 = V_291 ;
V_139 . V_141 = - 1 ;
V_139 . V_142 = 0 ;
F_75 ( V_1 , V_198 , & V_139 ) ;
F_170 ( & V_1 -> V_6 . V_79 ) ;
F_65 ( ! F_126 ( & V_1 -> V_6 . V_181 ) ) ;
V_287 = ( V_1 -> V_6 . V_7 + 1 ) * sizeof( struct V_10 ) ;
F_65 ( ! F_171 ( V_1 -> V_6 . V_44 ) ) ;
F_15 ( V_1 -> V_6 . V_44 , V_287 ) ;
F_65 ( ! F_171 ( V_1 -> V_6 . V_43 ) ) ;
F_15 ( V_1 -> V_6 . V_43 , V_287 ) ;
F_65 ( ! F_171 ( V_1 -> V_6 . V_42 ) ) ;
F_15 ( V_1 -> V_6 . V_42 , V_287 ) ;
}
static void F_172 ( struct V_18 * V_19 ,
struct V_292 * V_293 )
{
struct V_294 * V_295 = V_19 -> V_179 ;
T_2 V_8 = F_173 ( V_19 -> V_21 . V_8 ) ;
if ( V_295 )
F_174 ( V_293 , L_3 ,
V_295 -> V_296 , V_295 -> V_297 , V_295 -> V_298 ) ;
switch( V_19 -> V_22 . V_5 ) {
case V_190 :
F_174 ( V_293 , L_4 ,
& V_19 -> V_22 . V_3 . V_191 , & V_19 -> V_21 . V_2 . V_191 ) ;
break;
case V_194 :
F_174 ( V_293 , L_5 ,
V_19 -> V_22 . V_3 . V_196 , V_19 -> V_21 . V_2 . V_196 ) ;
break;
}
F_174 ( V_293 , L_6 , V_8 , V_8 ) ;
}
static void F_175 ( struct V_299 * V_300 , T_9 V_5 ,
struct V_292 * V_293 )
{
const struct V_301 * V_302 ;
const struct V_303 * V_304 ;
switch ( V_5 ) {
case V_190 :
V_302 = F_176 ( V_300 ) ;
F_174 ( V_293 , L_4 ,
& V_302 -> V_3 , & V_302 -> V_2 ) ;
break;
case V_194 :
V_304 = F_177 ( V_300 ) ;
F_174 ( V_293 ,
L_7 ,
& V_304 -> V_3 , & V_304 -> V_2 ,
V_304 -> V_305 [ 0 ] & 0x0f ,
V_304 -> V_305 [ 1 ] ,
V_304 -> V_305 [ 2 ] ) ;
break;
}
}
void F_178 ( struct V_18 * V_19 , int V_306 ,
T_10 V_307 , T_2 V_141 , T_2 V_142 )
{
struct V_292 * V_293 ;
V_293 = F_179 ( L_8 ) ;
if ( V_293 == NULL )
return;
F_180 ( V_307 , V_141 , V_142 , V_293 ) ;
F_172 ( V_19 , V_293 ) ;
F_174 ( V_293 , L_9 , V_306 ) ;
F_181 ( V_293 ) ;
}
void F_51 ( struct V_18 * V_19 , int V_306 ,
T_10 V_307 , T_2 V_141 , T_2 V_142 )
{
struct V_292 * V_293 ;
V_293 = F_179 ( L_10 ) ;
if ( V_293 == NULL )
return;
F_180 ( V_307 , V_141 , V_142 , V_293 ) ;
F_172 ( V_19 , V_293 ) ;
F_174 ( V_293 , L_9 , V_306 ) ;
F_181 ( V_293 ) ;
}
void F_182 ( struct V_18 * V_19 ,
struct V_299 * V_300 )
{
struct V_292 * V_293 ;
T_2 V_8 ;
V_293 = F_179 ( L_11 ) ;
if ( V_293 == NULL )
return;
F_175 ( V_300 , V_19 -> V_22 . V_5 , V_293 ) ;
V_8 = F_173 ( V_19 -> V_21 . V_8 ) ;
F_174 ( V_293 , L_6 , V_8 , V_8 ) ;
F_181 ( V_293 ) ;
}
void F_183 ( struct V_18 * V_19 ,
struct V_299 * V_300 , T_3 V_308 )
{
struct V_292 * V_293 ;
T_2 V_8 ;
V_293 = F_179 ( L_12 ) ;
if ( V_293 == NULL )
return;
F_175 ( V_300 , V_19 -> V_22 . V_5 , V_293 ) ;
V_8 = F_173 ( V_19 -> V_21 . V_8 ) ;
F_174 ( V_293 , L_13 ,
V_8 , V_8 , F_173 ( V_308 ) ) ;
F_181 ( V_293 ) ;
}
void F_184 ( struct V_299 * V_300 , T_9 V_5 )
{
struct V_292 * V_293 ;
V_293 = F_179 ( L_14 ) ;
if ( V_293 == NULL )
return;
F_175 ( V_300 , V_5 , V_293 ) ;
F_181 ( V_293 ) ;
}
void F_185 ( struct V_299 * V_300 , T_9 V_5 ,
T_3 V_309 , T_3 V_308 )
{
struct V_292 * V_293 ;
T_2 V_8 ;
V_293 = F_179 ( L_14 ) ;
if ( V_293 == NULL )
return;
F_175 ( V_300 , V_5 , V_293 ) ;
V_8 = F_173 ( V_309 ) ;
F_174 ( V_293 , L_13 ,
V_8 , V_8 , F_173 ( V_308 ) ) ;
F_181 ( V_293 ) ;
}
void F_186 ( struct V_18 * V_19 ,
struct V_299 * V_300 , T_4 V_9 )
{
struct V_292 * V_293 ;
T_3 V_309 ;
T_3 V_308 ;
V_293 = F_179 ( L_15 ) ;
if ( V_293 == NULL )
return;
F_175 ( V_300 , V_19 -> V_22 . V_5 , V_293 ) ;
if ( F_187 ( V_300 , V_9 , & V_309 , & V_308 ) == 0 ) {
T_2 V_8 = F_173 ( V_309 ) ;
F_174 ( V_293 , L_13 ,
V_8 , V_8 , F_173 ( V_308 ) ) ;
}
F_181 ( V_293 ) ;
}
