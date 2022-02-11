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
F_16 ( & V_1 -> V_6 . V_41 ) ;
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
F_17 ( & V_1 -> V_6 . V_41 ) ;
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
}
static inline unsigned long F_41 ( long V_83 )
{
if ( V_83 >= ( V_84 - 1 ) / V_85 )
return V_84 - 1 ;
else
return V_83 * V_85 ;
}
static enum V_86 F_42 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_12 ( V_88 , struct V_89 , V_91 ) ;
struct V_18 * V_19 = F_12 ( V_90 , struct V_18 , V_67 ) ;
unsigned long V_92 = F_43 () ;
long V_93 = V_94 ;
int V_95 = 0 ;
int V_49 = 0 ;
F_44 ( & V_19 -> V_96 ) ;
if ( V_19 -> V_97 . V_98 == V_99 )
goto V_66;
if ( V_19 -> V_97 . V_98 == V_100 )
goto V_101;
if ( V_19 -> V_102 . V_103 ) {
long V_104 = V_19 -> V_102 . V_103 +
V_19 -> V_105 . V_106 - V_92 ;
if ( V_104 <= 0 ) {
if ( V_19 -> V_107 & V_108 ) {
V_19 -> V_105 . V_106 = V_92 - V_19 -> V_109 - 1 ;
V_104 = V_19 -> V_102 . V_103 - V_19 -> V_109 ;
} else
goto V_101;
}
if ( V_104 < V_93 )
V_93 = V_104 ;
}
if ( V_19 -> V_102 . V_110 ) {
long V_104 = V_19 -> V_102 . V_110 +
( V_19 -> V_105 . V_111 ? : V_92 ) - V_92 ;
if ( V_104 <= 0 )
goto V_101;
if ( V_104 < V_93 )
V_93 = V_104 ;
}
if ( V_19 -> V_97 . V_112 )
goto V_113;
if ( V_19 -> V_102 . V_114 ) {
long V_104 = V_19 -> V_102 . V_114 +
V_19 -> V_105 . V_106 - V_92 ;
if ( V_104 <= 0 ) {
V_95 = 1 ;
V_19 -> V_107 &= ~ V_108 ;
} else if ( V_104 < V_93 ) {
V_93 = V_104 ;
V_19 -> V_107 |= V_108 ;
V_19 -> V_109 = V_104 ;
}
}
if ( V_19 -> V_102 . V_115 ) {
long V_104 = V_19 -> V_102 . V_115 +
( V_19 -> V_105 . V_111 ? : V_92 ) - V_92 ;
if ( V_104 <= 0 )
V_95 = 1 ;
else if ( V_104 < V_93 )
V_93 = V_104 ;
}
V_19 -> V_97 . V_112 = V_95 ;
if ( V_95 )
F_45 ( V_19 , 0 , 0 ) ;
V_113:
if ( V_93 != V_94 ) {
F_46 ( & V_19 -> V_67 , F_47 ( V_93 , 0 ) , V_116 ) ;
}
goto V_66;
V_101:
if ( V_19 -> V_97 . V_98 == V_117 && V_19 -> V_21 . V_8 == 0 )
V_19 -> V_97 . V_98 = V_100 ;
V_49 = F_48 ( V_19 ) ;
if ( ! V_49 )
F_45 ( V_19 , 1 , 0 ) ;
F_49 ( V_19 , V_49 ? 0 : 1 , true ) ;
V_66:
F_50 ( & V_19 -> V_96 ) ;
return V_118 ;
}
struct V_18 * F_51 ( struct V_1 * V_1 )
{
struct V_18 * V_19 ;
V_19 = F_52 ( sizeof( struct V_18 ) , V_119 ) ;
if ( V_19 ) {
F_53 ( & V_19 -> V_120 , V_1 ) ;
F_54 ( & V_19 -> V_121 , 1 ) ;
F_54 ( & V_19 -> V_122 , 0 ) ;
F_55 ( & V_19 -> V_97 . V_123 ) ;
F_56 ( & V_19 -> V_23 ) ;
F_56 ( & V_19 -> V_24 ) ;
F_56 ( & V_19 -> V_25 ) ;
F_57 ( & V_19 -> V_67 , F_42 ,
V_124 , V_125 ) ;
F_58 ( & V_19 -> V_68 , V_126 ,
( unsigned long ) V_19 ) ;
V_19 -> V_105 . V_106 = F_43 () ;
V_19 -> V_102 . V_127 = V_128 ;
V_19 -> V_102 . V_129 = V_128 ;
V_19 -> V_102 . V_130 = V_128 ;
V_19 -> V_102 . V_131 = V_128 ;
V_19 -> V_132 = 0 ;
V_19 -> V_133 = 0 ;
V_19 -> V_75 = NULL ;
V_19 -> V_76 = NULL ;
F_59 ( & V_19 -> V_96 ) ;
}
return V_19 ;
}
void F_60 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_120 ( V_19 ) ;
F_61 ( V_19 -> V_97 . V_98 != V_99 ) ;
F_16 ( & V_81 ) ;
F_9 ( & V_19 -> V_134 , & V_1 -> V_6 . V_82 ) ;
F_17 ( & V_81 ) ;
F_62 ( & V_1 -> V_6 . V_79 ) ;
}
int F_48 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_120 ( V_19 ) ;
int V_49 = - V_135 ;
if ( V_19 -> V_97 . V_98 != V_99 ) {
V_19 -> V_97 . V_98 = V_99 ;
F_44 ( & V_1 -> V_6 . V_41 ) ;
F_63 ( & V_19 -> V_97 . V_123 ) ;
F_64 ( & V_19 -> V_23 ) ;
F_64 ( & V_19 -> V_24 ) ;
if ( V_19 -> V_21 . V_8 )
F_64 ( & V_19 -> V_25 ) ;
V_1 -> V_6 . V_136 -- ;
F_50 ( & V_1 -> V_6 . V_41 ) ;
F_65 ( V_19 ) ;
V_49 = 0 ;
}
return V_49 ;
}
int F_66 ( struct V_18 * V_19 )
{
int V_49 ;
F_16 ( & V_19 -> V_96 ) ;
V_49 = F_48 ( V_19 ) ;
F_17 ( & V_19 -> V_96 ) ;
return V_49 ;
}
static inline int
F_67 ( struct V_1 * V_1 , T_4 V_9 , bool V_137 )
{
int V_38 , V_49 = 0 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
F_68 (x, net->xfrm.state_bydst+i, bydst) {
if ( F_69 ( V_19 -> V_21 . V_9 , V_9 ) &&
( V_49 = F_70 ( V_19 ) ) != 0 ) {
F_49 ( V_19 , 0 , V_137 ) ;
return V_49 ;
}
}
}
return V_49 ;
}
static inline int
F_67 ( struct V_1 * V_1 , T_4 V_9 , bool V_137 )
{
return 0 ;
}
int F_71 ( struct V_1 * V_1 , T_4 V_9 , bool V_137 )
{
int V_38 , V_49 = 0 , V_138 = 0 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_49 = F_67 ( V_1 , V_9 , V_137 ) ;
if ( V_49 )
goto V_66;
V_49 = - V_135 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
V_139:
F_68 (x, net->xfrm.state_bydst+i, bydst) {
if ( ! F_72 ( V_19 ) &&
F_69 ( V_19 -> V_21 . V_9 , V_9 ) ) {
F_73 ( V_19 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
V_49 = F_66 ( V_19 ) ;
F_49 ( V_19 , V_49 ? 0 : 1 ,
V_137 ) ;
F_65 ( V_19 ) ;
if ( ! V_49 )
V_138 ++ ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
goto V_139;
}
}
}
if ( V_138 )
V_49 = 0 ;
V_66:
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_49 ;
}
void F_74 ( struct V_1 * V_1 , struct V_140 * V_141 )
{
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_141 -> V_142 = V_1 -> V_6 . V_136 ;
V_141 -> V_143 = V_1 -> V_6 . V_7 ;
V_141 -> V_144 = V_145 ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
}
static int
F_75 ( struct V_18 * V_19 , const struct V_146 * V_147 ,
const struct V_148 * V_149 ,
const T_1 * V_2 , const T_1 * V_3 ,
unsigned short V_5 )
{
struct V_46 * V_47 = F_20 ( V_5 ) ;
if ( ! V_47 )
return - 1 ;
V_47 -> V_150 ( & V_19 -> V_151 , V_147 ) ;
if ( V_5 != V_149 -> V_152 ) {
F_23 ( V_47 ) ;
V_47 = F_20 ( V_149 -> V_152 ) ;
if ( ! V_47 )
return - 1 ;
}
V_47 -> V_153 ( V_19 , V_149 , V_2 , V_3 ) ;
F_23 ( V_47 ) ;
return 0 ;
}
static struct V_18 * F_76 ( struct V_1 * V_1 , T_2 V_154 ,
const T_1 * V_2 ,
T_3 V_8 , T_4 V_9 ,
unsigned short V_5 )
{
unsigned int V_20 = F_5 ( V_1 , V_2 , V_8 , V_9 , V_5 ) ;
struct V_18 * V_19 ;
F_68 (x, net->xfrm.state_byspi+h, byspi) {
if ( V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_21 . V_8 != V_8 ||
V_19 -> V_21 . V_9 != V_9 ||
! F_77 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) )
continue;
if ( ( V_154 & V_19 -> V_154 . V_155 ) != V_19 -> V_154 . V_156 )
continue;
F_73 ( V_19 ) ;
return V_19 ;
}
return NULL ;
}
static struct V_18 * F_78 ( struct V_1 * V_1 , T_2 V_154 ,
const T_1 * V_2 ,
const T_1 * V_3 ,
T_4 V_9 , unsigned short V_5 )
{
unsigned int V_20 = F_3 ( V_1 , V_2 , V_3 , V_5 ) ;
struct V_18 * V_19 ;
F_68 (x, net->xfrm.state_bysrc+h, bysrc) {
if ( V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_21 . V_9 != V_9 ||
! F_77 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) ||
! F_77 ( & V_19 -> V_22 . V_3 , V_3 , V_5 ) )
continue;
if ( ( V_154 & V_19 -> V_154 . V_155 ) != V_19 -> V_154 . V_156 )
continue;
F_73 ( V_19 ) ;
return V_19 ;
}
return NULL ;
}
static inline struct V_18 *
F_79 ( struct V_18 * V_19 , int V_157 , int V_5 )
{
struct V_1 * V_1 = V_120 ( V_19 ) ;
T_2 V_154 = V_19 -> V_154 . V_156 & V_19 -> V_154 . V_155 ;
if ( V_157 )
return F_76 ( V_1 , V_154 , & V_19 -> V_21 . V_2 ,
V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_5 ) ;
else
return F_78 ( V_1 , V_154 ,
& V_19 -> V_21 . V_2 ,
& V_19 -> V_22 . V_3 ,
V_19 -> V_21 . V_9 , V_5 ) ;
}
static void F_80 ( struct V_1 * V_1 , int V_158 )
{
if ( V_158 &&
( V_1 -> V_6 . V_7 + 1 ) < V_145 &&
V_1 -> V_6 . V_136 > V_1 -> V_6 . V_7 )
F_62 ( & V_1 -> V_6 . V_28 ) ;
}
static void F_81 ( struct V_159 * V_160 , struct V_18 * V_19 ,
const struct V_146 * V_147 , unsigned short V_5 ,
struct V_18 * * V_161 , int * V_162 ,
int * error )
{
if ( V_19 -> V_97 . V_98 == V_163 ) {
if ( ( V_19 -> V_151 . V_5 &&
! F_82 ( & V_19 -> V_151 , V_147 , V_19 -> V_151 . V_5 ) ) ||
! F_83 ( V_19 , V_160 , V_147 ) )
return;
if ( ! * V_161 ||
( * V_161 ) -> V_97 . V_112 > V_19 -> V_97 . V_112 ||
( ( * V_161 ) -> V_97 . V_112 == V_19 -> V_97 . V_112 &&
( * V_161 ) -> V_105 . V_106 < V_19 -> V_105 . V_106 ) )
* V_161 = V_19 ;
} else if ( V_19 -> V_97 . V_98 == V_117 ) {
* V_162 = 1 ;
} else if ( V_19 -> V_97 . V_98 == V_164 ||
V_19 -> V_97 . V_98 == V_100 ) {
if ( F_82 ( & V_19 -> V_151 , V_147 , V_19 -> V_151 . V_5 ) &&
F_83 ( V_19 , V_160 , V_147 ) )
* error = - V_135 ;
}
}
struct V_18 *
F_84 ( const T_1 * V_2 , const T_1 * V_3 ,
const struct V_146 * V_147 , struct V_148 * V_149 ,
struct V_159 * V_160 , int * V_49 ,
unsigned short V_5 )
{
static T_1 V_165 = { } ;
struct V_1 * V_1 = F_85 ( V_160 ) ;
unsigned int V_20 , V_166 ;
struct V_18 * V_19 , * V_167 , * V_168 ;
int V_169 = 0 ;
int error = 0 ;
struct V_18 * V_161 = NULL ;
T_2 V_154 = V_160 -> V_154 . V_156 & V_160 -> V_154 . V_155 ;
unsigned short V_152 = V_149 -> V_152 ;
struct V_170 V_171 ;
V_168 = NULL ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_20 = F_1 ( V_1 , V_2 , V_3 , V_149 -> V_4 , V_152 ) ;
F_68 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_152 &&
V_19 -> V_22 . V_4 == V_149 -> V_4 &&
( V_154 & V_19 -> V_154 . V_155 ) == V_19 -> V_154 . V_156 &&
! ( V_19 -> V_22 . V_172 & V_173 ) &&
F_86 ( V_19 , V_2 , V_3 , V_152 ) &&
V_149 -> V_59 == V_19 -> V_22 . V_59 &&
V_149 -> V_21 . V_9 == V_19 -> V_21 . V_9 &&
( V_149 -> V_21 . V_8 == V_19 -> V_21 . V_8 || ! V_149 -> V_21 . V_8 ) )
F_81 ( V_160 , V_19 , V_147 , V_152 ,
& V_161 , & V_169 , & error ) ;
}
if ( V_161 || V_169 )
goto V_174;
V_166 = F_1 ( V_1 , V_2 , & V_165 , V_149 -> V_4 , V_152 ) ;
F_68 (x, net->xfrm.state_bydst+h_wildcard, bydst) {
if ( V_19 -> V_22 . V_5 == V_152 &&
V_19 -> V_22 . V_4 == V_149 -> V_4 &&
( V_154 & V_19 -> V_154 . V_155 ) == V_19 -> V_154 . V_156 &&
! ( V_19 -> V_22 . V_172 & V_173 ) &&
F_77 ( & V_19 -> V_21 . V_2 , V_2 , V_152 ) &&
V_149 -> V_59 == V_19 -> V_22 . V_59 &&
V_149 -> V_21 . V_9 == V_19 -> V_21 . V_9 &&
( V_149 -> V_21 . V_8 == V_19 -> V_21 . V_8 || ! V_149 -> V_21 . V_8 ) )
F_81 ( V_160 , V_19 , V_147 , V_152 ,
& V_161 , & V_169 , & error ) ;
}
V_174:
V_19 = V_161 ;
if ( ! V_19 && ! error && ! V_169 ) {
if ( V_149 -> V_21 . V_8 &&
( V_167 = F_76 ( V_1 , V_154 , V_2 , V_149 -> V_21 . V_8 ,
V_149 -> V_21 . V_9 , V_152 ) ) != NULL ) {
V_168 = V_167 ;
error = - V_53 ;
goto V_66;
}
V_171 . V_1 = V_1 ;
if ( ! F_87 ( & V_171 ) ) {
error = - V_135 ;
goto V_66;
}
V_19 = F_51 ( V_1 ) ;
if ( V_19 == NULL ) {
error = - V_175 ;
goto V_66;
}
F_75 ( V_19 , V_147 , V_149 , V_2 , V_3 , V_5 ) ;
memcpy ( & V_19 -> V_154 , & V_160 -> V_154 , sizeof( V_19 -> V_154 ) ) ;
error = F_88 ( V_19 , V_160 -> V_176 , V_147 -> V_177 ) ;
if ( error ) {
V_19 -> V_97 . V_98 = V_99 ;
V_168 = V_19 ;
V_19 = NULL ;
goto V_66;
}
if ( F_89 ( V_19 , V_149 , V_160 ) == 0 ) {
V_19 -> V_97 . V_98 = V_117 ;
F_90 ( & V_19 -> V_97 . V_123 , & V_1 -> V_6 . V_178 ) ;
F_9 ( & V_19 -> V_23 , V_1 -> V_6 . V_42 + V_20 ) ;
V_20 = F_3 ( V_1 , V_2 , V_3 , V_152 ) ;
F_9 ( & V_19 -> V_24 , V_1 -> V_6 . V_43 + V_20 ) ;
if ( V_19 -> V_21 . V_8 ) {
V_20 = F_5 ( V_1 , & V_19 -> V_21 . V_2 , V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_152 ) ;
F_9 ( & V_19 -> V_25 , V_1 -> V_6 . V_44 + V_20 ) ;
}
V_19 -> V_102 . V_103 = V_1 -> V_6 . V_179 ;
F_46 ( & V_19 -> V_67 , F_47 ( V_1 -> V_6 . V_179 , 0 ) , V_116 ) ;
V_1 -> V_6 . V_136 ++ ;
F_80 ( V_1 , V_19 -> V_23 . V_93 != NULL ) ;
} else {
V_19 -> V_97 . V_98 = V_99 ;
V_168 = V_19 ;
V_19 = NULL ;
error = - V_135 ;
}
}
V_66:
if ( V_19 )
F_73 ( V_19 ) ;
else
* V_49 = V_169 ? - V_180 : error ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
if ( V_168 )
F_65 ( V_168 ) ;
return V_19 ;
}
struct V_18 *
F_91 ( struct V_1 * V_1 , T_2 V_154 ,
T_1 * V_2 , T_1 * V_3 ,
unsigned short V_5 , T_4 V_59 , T_4 V_9 , T_2 V_4 )
{
unsigned int V_20 ;
struct V_18 * V_181 = NULL , * V_19 = NULL ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_20 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_68 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_5 &&
V_19 -> V_22 . V_4 == V_4 &&
( V_154 & V_19 -> V_154 . V_155 ) == V_19 -> V_154 . V_156 &&
! ( V_19 -> V_22 . V_172 & V_173 ) &&
F_86 ( V_19 , V_2 , V_3 , V_5 ) &&
V_59 == V_19 -> V_22 . V_59 &&
V_9 == V_19 -> V_21 . V_9 &&
V_19 -> V_97 . V_98 == V_163 ) {
V_181 = V_19 ;
break;
}
}
if ( V_181 )
F_73 ( V_181 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_181 ;
}
struct V_18 * F_92 ( struct V_1 * V_1 , T_3 V_8 ,
unsigned short V_5 )
{
struct V_18 * V_19 ;
struct V_182 * V_183 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
F_93 (w, &net->xfrm.state_all, all) {
V_19 = F_12 ( V_183 , struct V_18 , V_97 ) ;
if ( V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_21 . V_8 != V_8 )
continue;
F_17 ( & V_1 -> V_6 . V_41 ) ;
F_73 ( V_19 ) ;
return V_19 ;
}
F_17 ( & V_1 -> V_6 . V_41 ) ;
return NULL ;
}
static void F_94 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_120 ( V_19 ) ;
unsigned int V_20 ;
F_90 ( & V_19 -> V_97 . V_123 , & V_1 -> V_6 . V_178 ) ;
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
F_46 ( & V_19 -> V_67 , F_47 ( 1 , 0 ) , V_116 ) ;
if ( V_19 -> V_132 )
F_95 ( & V_19 -> V_68 , V_184 + V_19 -> V_132 ) ;
V_1 -> V_6 . V_136 ++ ;
F_80 ( V_1 , V_19 -> V_23 . V_93 != NULL ) ;
}
static void F_96 ( struct V_18 * V_185 )
{
struct V_1 * V_1 = V_120 ( V_185 ) ;
unsigned short V_5 = V_185 -> V_22 . V_5 ;
T_2 V_4 = V_185 -> V_22 . V_4 ;
struct V_18 * V_19 ;
unsigned int V_20 ;
T_2 V_154 = V_185 -> V_154 . V_156 & V_185 -> V_154 . V_155 ;
V_20 = F_1 ( V_1 , & V_185 -> V_21 . V_2 , & V_185 -> V_22 . V_3 , V_4 , V_5 ) ;
F_68 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_5 &&
V_19 -> V_22 . V_4 == V_4 &&
( V_154 & V_19 -> V_154 . V_155 ) == V_19 -> V_154 . V_156 &&
F_77 ( & V_19 -> V_21 . V_2 , & V_185 -> V_21 . V_2 , V_5 ) &&
F_77 ( & V_19 -> V_22 . V_3 , & V_185 -> V_22 . V_3 , V_5 ) )
V_19 -> V_186 ++ ;
}
}
void F_97 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_120 ( V_19 ) ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
F_96 ( V_19 ) ;
F_94 ( V_19 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
}
static struct V_18 * F_98 ( struct V_1 * V_1 ,
const struct V_187 * V_155 ,
unsigned short V_5 , T_4 V_59 ,
T_2 V_4 , T_4 V_9 ,
const T_1 * V_2 ,
const T_1 * V_3 ,
int V_188 )
{
unsigned int V_20 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
struct V_18 * V_19 ;
T_2 V_154 = V_155 -> V_156 & V_155 -> V_155 ;
F_68 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_4 != V_4 ||
V_19 -> V_22 . V_59 != V_59 ||
V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_97 . V_98 != V_117 ||
V_19 -> V_21 . V_8 != 0 ||
V_19 -> V_21 . V_9 != V_9 ||
( V_154 & V_19 -> V_154 . V_155 ) != V_19 -> V_154 . V_156 ||
! F_77 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) ||
! F_77 ( & V_19 -> V_22 . V_3 , V_3 , V_5 ) )
continue;
F_73 ( V_19 ) ;
return V_19 ;
}
if ( ! V_188 )
return NULL ;
V_19 = F_51 ( V_1 ) ;
if ( F_22 ( V_19 ) ) {
switch ( V_5 ) {
case V_189 :
V_19 -> V_151 . V_2 . V_190 = V_2 -> V_190 ;
V_19 -> V_151 . V_3 . V_190 = V_3 -> V_190 ;
V_19 -> V_151 . V_191 = 32 ;
V_19 -> V_151 . V_192 = 32 ;
V_19 -> V_22 . V_3 . V_190 = V_3 -> V_190 ;
V_19 -> V_21 . V_2 . V_190 = V_2 -> V_190 ;
break;
case V_193 :
* (struct V_194 * ) V_19 -> V_151 . V_2 . V_195 = * (struct V_194 * ) V_2 ;
* (struct V_194 * ) V_19 -> V_151 . V_3 . V_195 = * (struct V_194 * ) V_3 ;
V_19 -> V_151 . V_191 = 128 ;
V_19 -> V_151 . V_192 = 128 ;
* (struct V_194 * ) V_19 -> V_22 . V_3 . V_195 = * (struct V_194 * ) V_3 ;
* (struct V_194 * ) V_19 -> V_21 . V_2 . V_195 = * (struct V_194 * ) V_2 ;
break;
}
V_19 -> V_97 . V_98 = V_117 ;
V_19 -> V_21 . V_9 = V_9 ;
V_19 -> V_22 . V_5 = V_5 ;
V_19 -> V_22 . V_59 = V_59 ;
V_19 -> V_22 . V_4 = V_4 ;
V_19 -> V_154 . V_156 = V_155 -> V_156 ;
V_19 -> V_154 . V_155 = V_155 -> V_155 ;
V_19 -> V_102 . V_103 = V_1 -> V_6 . V_179 ;
F_73 ( V_19 ) ;
F_46 ( & V_19 -> V_67 , F_47 ( V_1 -> V_6 . V_179 , 0 ) , V_116 ) ;
F_90 ( & V_19 -> V_97 . V_123 , & V_1 -> V_6 . V_178 ) ;
F_9 ( & V_19 -> V_23 , V_1 -> V_6 . V_42 + V_20 ) ;
V_20 = F_3 ( V_1 , V_2 , V_3 , V_5 ) ;
F_9 ( & V_19 -> V_24 , V_1 -> V_6 . V_43 + V_20 ) ;
V_1 -> V_6 . V_136 ++ ;
F_80 ( V_1 , V_19 -> V_23 . V_93 != NULL ) ;
}
return V_19 ;
}
int F_99 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_120 ( V_19 ) ;
struct V_18 * V_196 , * V_168 ;
int V_5 ;
int V_49 ;
T_2 V_154 = V_19 -> V_154 . V_156 & V_19 -> V_154 . V_155 ;
int V_157 = F_69 ( V_19 -> V_21 . V_9 , V_197 ) ;
V_5 = V_19 -> V_22 . V_5 ;
V_168 = NULL ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_196 = F_79 ( V_19 , V_157 , V_5 ) ;
if ( V_196 ) {
V_168 = V_196 ;
V_196 = NULL ;
V_49 = - V_53 ;
goto V_66;
}
if ( V_157 && V_19 -> V_97 . V_198 ) {
V_196 = F_100 ( V_1 , V_154 , V_19 -> V_97 . V_198 ) ;
if ( V_196 && ( ( V_196 -> V_21 . V_9 != V_19 -> V_21 . V_9 ) ||
! F_77 ( & V_196 -> V_21 . V_2 , & V_19 -> V_21 . V_2 , V_5 ) ) ) {
V_168 = V_196 ;
V_196 = NULL ;
}
}
if ( V_157 && ! V_196 )
V_196 = F_98 ( V_1 , & V_19 -> V_154 , V_5 , V_19 -> V_22 . V_59 ,
V_19 -> V_22 . V_4 , V_19 -> V_21 . V_9 ,
& V_19 -> V_21 . V_2 , & V_19 -> V_22 . V_3 , 0 ) ;
F_96 ( V_19 ) ;
F_94 ( V_19 ) ;
V_49 = 0 ;
V_66:
F_17 ( & V_1 -> V_6 . V_41 ) ;
if ( V_196 ) {
F_66 ( V_196 ) ;
F_65 ( V_196 ) ;
}
if ( V_168 )
F_65 ( V_168 ) ;
return V_49 ;
}
static struct V_18 * F_101 ( struct V_18 * V_199 )
{
struct V_1 * V_1 = V_120 ( V_199 ) ;
struct V_18 * V_19 = F_51 ( V_1 ) ;
if ( ! V_19 )
goto V_66;
memcpy ( & V_19 -> V_21 , & V_199 -> V_21 , sizeof( V_19 -> V_21 ) ) ;
memcpy ( & V_19 -> V_151 , & V_199 -> V_151 , sizeof( V_19 -> V_151 ) ) ;
memcpy ( & V_19 -> V_102 , & V_199 -> V_102 , sizeof( V_19 -> V_102 ) ) ;
V_19 -> V_22 . V_59 = V_199 -> V_22 . V_59 ;
V_19 -> V_22 . V_200 = V_199 -> V_22 . V_200 ;
V_19 -> V_22 . V_4 = V_199 -> V_22 . V_4 ;
V_19 -> V_22 . V_5 = V_199 -> V_22 . V_5 ;
V_19 -> V_22 . V_3 = V_199 -> V_22 . V_3 ;
if ( V_199 -> V_69 ) {
V_19 -> V_69 = F_102 ( V_199 -> V_69 ) ;
if ( ! V_19 -> V_69 )
goto error;
}
V_19 -> V_22 . V_201 = V_199 -> V_22 . V_201 ;
if ( V_199 -> V_202 ) {
V_19 -> V_202 = F_103 ( V_199 -> V_202 ) ;
if ( ! V_19 -> V_202 )
goto error;
}
if ( V_199 -> V_70 ) {
V_19 -> V_70 = F_104 ( V_199 -> V_70 ) ;
if ( ! V_19 -> V_70 )
goto error;
}
V_19 -> V_22 . V_203 = V_199 -> V_22 . V_203 ;
if ( V_199 -> V_71 ) {
V_19 -> V_71 = F_104 ( V_199 -> V_71 ) ;
if ( ! V_19 -> V_71 )
goto error;
}
V_19 -> V_22 . V_204 = V_199 -> V_22 . V_204 ;
if ( V_199 -> V_61 ) {
V_19 -> V_61 = F_105 ( V_199 -> V_61 , sizeof( * V_19 -> V_61 ) , V_205 ) ;
if ( ! V_19 -> V_61 )
goto error;
}
if ( V_199 -> V_72 ) {
V_19 -> V_72 = F_105 ( V_199 -> V_72 , sizeof( * V_19 -> V_72 ) ,
V_205 ) ;
if ( ! V_19 -> V_72 )
goto error;
}
if ( V_199 -> V_73 ) {
if ( F_106 ( V_19 , V_199 ) )
goto error;
}
memcpy ( & V_19 -> V_154 , & V_199 -> V_154 , sizeof( V_19 -> V_154 ) ) ;
if ( F_107 ( V_19 ) < 0 )
goto error;
V_19 -> V_22 . V_172 = V_199 -> V_22 . V_172 ;
V_19 -> V_22 . V_206 = V_199 -> V_22 . V_206 ;
V_19 -> V_207 = V_199 -> V_207 ;
V_19 -> V_133 = V_199 -> V_133 ;
V_19 -> V_132 = V_199 -> V_132 ;
V_19 -> V_105 . V_106 = V_199 -> V_105 . V_106 ;
V_19 -> V_97 . V_98 = V_199 -> V_97 . V_98 ;
V_19 -> V_97 . V_198 = V_199 -> V_97 . V_198 ;
return V_19 ;
error:
F_65 ( V_19 ) ;
V_66:
return NULL ;
}
struct V_18 * F_108 ( struct V_208 * V_155 , struct V_1 * V_1 )
{
unsigned int V_20 ;
struct V_18 * V_19 = NULL ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
if ( V_155 -> V_4 ) {
V_20 = F_1 ( V_1 , & V_155 -> V_209 , & V_155 -> V_210 ,
V_155 -> V_4 , V_155 -> V_211 ) ;
F_68 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_59 != V_155 -> V_59 ||
V_19 -> V_21 . V_9 != V_155 -> V_9 )
continue;
if ( V_155 -> V_4 && V_19 -> V_22 . V_4 != V_155 -> V_4 )
continue;
if ( ! F_77 ( & V_19 -> V_21 . V_2 , & V_155 -> V_209 ,
V_155 -> V_211 ) ||
! F_77 ( & V_19 -> V_22 . V_3 , & V_155 -> V_210 ,
V_155 -> V_211 ) )
continue;
F_73 ( V_19 ) ;
break;
}
} else {
V_20 = F_3 ( V_1 , & V_155 -> V_209 , & V_155 -> V_210 ,
V_155 -> V_211 ) ;
F_68 (x, net->xfrm.state_bysrc+h, bysrc) {
if ( V_19 -> V_22 . V_59 != V_155 -> V_59 ||
V_19 -> V_21 . V_9 != V_155 -> V_9 )
continue;
if ( ! F_77 ( & V_19 -> V_21 . V_2 , & V_155 -> V_209 ,
V_155 -> V_211 ) ||
! F_77 ( & V_19 -> V_22 . V_3 , & V_155 -> V_210 ,
V_155 -> V_211 ) )
continue;
F_73 ( V_19 ) ;
break;
}
}
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_19 ;
}
struct V_18 * F_109 ( struct V_18 * V_19 ,
struct V_208 * V_155 )
{
struct V_18 * V_212 ;
V_212 = F_101 ( V_19 ) ;
if ( ! V_212 )
return NULL ;
memcpy ( & V_212 -> V_21 . V_2 , & V_155 -> V_213 , sizeof( V_212 -> V_21 . V_2 ) ) ;
memcpy ( & V_212 -> V_22 . V_3 , & V_155 -> V_214 , sizeof( V_212 -> V_22 . V_3 ) ) ;
if ( F_77 ( & V_19 -> V_21 . V_2 , & V_155 -> V_213 , V_155 -> V_215 ) ) {
F_97 ( V_212 ) ;
} else {
if ( F_99 ( V_212 ) < 0 )
goto error;
}
return V_212 ;
error:
F_65 ( V_212 ) ;
return NULL ;
}
int F_110 ( struct V_18 * V_19 )
{
struct V_18 * V_196 , * V_168 ;
int V_49 ;
int V_157 = F_69 ( V_19 -> V_21 . V_9 , V_197 ) ;
struct V_1 * V_1 = V_120 ( V_19 ) ;
V_168 = NULL ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_196 = F_79 ( V_19 , V_157 , V_19 -> V_22 . V_5 ) ;
V_49 = - V_135 ;
if ( ! V_196 )
goto V_66;
if ( F_72 ( V_196 ) ) {
V_168 = V_196 ;
V_49 = - V_53 ;
goto V_66;
}
if ( V_196 -> V_97 . V_98 == V_117 ) {
F_94 ( V_19 ) ;
V_19 = NULL ;
}
V_49 = 0 ;
V_66:
F_17 ( & V_1 -> V_6 . V_41 ) ;
if ( V_168 )
F_65 ( V_168 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_19 ) {
F_66 ( V_196 ) ;
F_65 ( V_196 ) ;
return 0 ;
}
V_49 = - V_63 ;
F_16 ( & V_196 -> V_96 ) ;
if ( F_22 ( V_196 -> V_97 . V_98 == V_163 ) ) {
if ( V_19 -> V_61 && V_196 -> V_61 )
memcpy ( V_196 -> V_61 , V_19 -> V_61 , sizeof( * V_196 -> V_61 ) ) ;
if ( V_19 -> V_72 && V_196 -> V_72 ) {
memcpy ( V_196 -> V_72 , V_19 -> V_72 , sizeof( * V_196 -> V_72 ) ) ;
}
if ( ! V_157 && memcmp ( & V_196 -> V_151 , & V_19 -> V_151 , sizeof( V_196 -> V_151 ) ) )
memcpy ( & V_196 -> V_151 , & V_19 -> V_151 , sizeof( V_196 -> V_151 ) ) ;
memcpy ( & V_196 -> V_102 , & V_19 -> V_102 , sizeof( V_196 -> V_102 ) ) ;
V_196 -> V_97 . V_112 = 0 ;
F_46 ( & V_196 -> V_67 , F_47 ( 1 , 0 ) , V_116 ) ;
if ( V_196 -> V_105 . V_111 )
F_111 ( V_196 ) ;
V_49 = 0 ;
V_19 -> V_97 . V_98 = V_99 ;
F_112 ( V_19 ) ;
}
F_17 ( & V_196 -> V_96 ) ;
F_65 ( V_196 ) ;
return V_49 ;
}
int F_111 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_105 . V_111 )
V_19 -> V_105 . V_111 = F_43 () ;
if ( V_19 -> V_105 . V_216 >= V_19 -> V_102 . V_130 ||
V_19 -> V_105 . V_217 >= V_19 -> V_102 . V_131 ) {
V_19 -> V_97 . V_98 = V_100 ;
F_46 ( & V_19 -> V_67 , F_47 ( 0 , 0 ) , V_116 ) ;
return - V_63 ;
}
if ( ! V_19 -> V_97 . V_112 &&
( V_19 -> V_105 . V_216 >= V_19 -> V_102 . V_127 ||
V_19 -> V_105 . V_217 >= V_19 -> V_102 . V_129 ) ) {
V_19 -> V_97 . V_112 = 1 ;
F_45 ( V_19 , 0 , 0 ) ;
}
return 0 ;
}
struct V_18 *
F_113 ( struct V_1 * V_1 , T_2 V_154 , const T_1 * V_2 , T_3 V_8 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_19 = F_76 ( V_1 , V_154 , V_2 , V_8 , V_9 , V_5 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_19 ;
}
struct V_18 *
F_114 ( struct V_1 * V_1 , T_2 V_154 ,
const T_1 * V_2 , const T_1 * V_3 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_19 = F_78 ( V_1 , V_154 , V_2 , V_3 , V_9 , V_5 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_19 ;
}
struct V_18 *
F_115 ( struct V_1 * V_1 , const struct V_187 * V_154 , T_4 V_59 , T_2 V_4 ,
T_4 V_9 , const T_1 * V_2 ,
const T_1 * V_3 , int V_188 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_19 = F_98 ( V_1 , V_154 , V_5 , V_59 , V_4 , V_9 , V_2 , V_3 , V_188 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_19 ;
}
int
F_116 ( struct V_148 * * V_218 , struct V_148 * * V_219 , int V_220 ,
unsigned short V_5 , struct V_1 * V_1 )
{
int V_49 = 0 ;
struct V_46 * V_47 = F_20 ( V_5 ) ;
if ( ! V_47 )
return - V_50 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
if ( V_47 -> V_221 )
V_49 = V_47 -> V_221 ( V_218 , V_219 , V_220 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
F_23 ( V_47 ) ;
return V_49 ;
}
int
F_117 ( struct V_18 * * V_218 , struct V_18 * * V_219 , int V_220 ,
unsigned short V_5 )
{
int V_49 = 0 ;
struct V_46 * V_47 = F_20 ( V_5 ) ;
struct V_1 * V_1 = V_120 ( * V_219 ) ;
if ( ! V_47 )
return - V_50 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
if ( V_47 -> V_222 )
V_49 = V_47 -> V_222 ( V_218 , V_219 , V_220 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
F_23 ( V_47 ) ;
return V_49 ;
}
static struct V_18 * F_100 ( struct V_1 * V_1 , T_2 V_154 , T_2 V_198 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
F_68 (x, net->xfrm.state_bydst+i, bydst) {
if ( V_19 -> V_97 . V_198 == V_198 &&
( V_154 & V_19 -> V_154 . V_155 ) == V_19 -> V_154 . V_156 &&
V_19 -> V_97 . V_98 == V_117 ) {
F_73 ( V_19 ) ;
return V_19 ;
}
}
}
return NULL ;
}
struct V_18 * F_118 ( struct V_1 * V_1 , T_2 V_154 , T_2 V_198 )
{
struct V_18 * V_19 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_19 = F_100 ( V_1 , V_154 , V_198 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_19 ;
}
T_2 F_119 ( void )
{
T_2 V_223 ;
static T_5 V_224 ;
do {
V_223 = F_120 ( & V_224 ) ;
} while ( ! V_223 );
return V_223 ;
}
int F_121 ( T_4 V_9 , T_2 V_225 , T_2 V_226 )
{
switch ( V_9 ) {
case V_227 :
case V_228 :
break;
case V_229 :
if ( V_226 >= 0x10000 )
return - V_63 ;
break;
default:
return - V_63 ;
}
if ( V_225 > V_226 )
return - V_63 ;
return 0 ;
}
int F_122 ( struct V_18 * V_19 , T_2 V_230 , T_2 V_231 )
{
struct V_1 * V_1 = V_120 ( V_19 ) ;
unsigned int V_20 ;
struct V_18 * V_167 ;
int V_49 = - V_54 ;
T_3 V_232 = F_123 ( V_230 ) ;
T_3 V_233 = F_123 ( V_231 ) ;
T_2 V_154 = V_19 -> V_154 . V_156 & V_19 -> V_154 . V_155 ;
F_16 ( & V_19 -> V_96 ) ;
if ( V_19 -> V_97 . V_98 == V_99 )
goto V_234;
V_49 = 0 ;
if ( V_19 -> V_21 . V_8 )
goto V_234;
V_49 = - V_54 ;
if ( V_232 == V_233 ) {
V_167 = F_113 ( V_1 , V_154 , & V_19 -> V_21 . V_2 , V_232 , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
if ( V_167 ) {
F_65 ( V_167 ) ;
goto V_234;
}
V_19 -> V_21 . V_8 = V_232 ;
} else {
T_2 V_8 = 0 ;
for ( V_20 = 0 ; V_20 < V_231 - V_230 + 1 ; V_20 ++ ) {
V_8 = V_230 + F_124 () % ( V_231 - V_230 + 1 ) ;
V_167 = F_113 ( V_1 , V_154 , & V_19 -> V_21 . V_2 , F_123 ( V_8 ) , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
if ( V_167 == NULL ) {
V_19 -> V_21 . V_8 = F_123 ( V_8 ) ;
break;
}
F_65 ( V_167 ) ;
}
}
if ( V_19 -> V_21 . V_8 ) {
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_20 = F_5 ( V_1 , & V_19 -> V_21 . V_2 , V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
F_9 ( & V_19 -> V_25 , V_1 -> V_6 . V_44 + V_20 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
V_49 = 0 ;
}
V_234:
F_17 ( & V_19 -> V_96 ) ;
return V_49 ;
}
static bool F_125 ( struct V_18 * V_19 ,
struct V_235 * V_236 )
{
if ( V_236 ) {
if ( ( V_236 -> V_5 == V_189 ||
V_236 -> V_5 == V_193 ) &&
V_19 -> V_22 . V_5 != V_236 -> V_5 )
return false ;
return F_126 ( & V_19 -> V_22 . V_3 , & V_236 -> V_3 ,
V_236 -> V_237 ) &&
F_126 ( & V_19 -> V_21 . V_2 , & V_236 -> V_2 ,
V_236 -> V_238 ) ;
}
return true ;
}
int V_182 ( struct V_1 * V_1 , struct V_182 * V_239 ,
int (* F_127)( struct V_18 * , int , void * ) ,
void * V_240 )
{
struct V_18 * V_98 ;
struct V_182 * V_19 ;
int V_49 = 0 ;
if ( V_239 -> V_198 != 0 && F_128 ( & V_239 -> V_123 ) )
return 0 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
if ( F_128 ( & V_239 -> V_123 ) )
V_19 = F_129 ( & V_1 -> V_6 . V_178 , struct V_182 , V_123 ) ;
else
V_19 = F_130 ( & V_239 -> V_123 , struct V_182 , V_123 ) ;
F_131 (x, &net->xfrm.state_all, all) {
if ( V_19 -> V_98 == V_99 )
continue;
V_98 = F_12 ( V_19 , struct V_18 , V_97 ) ;
if ( ! F_69 ( V_98 -> V_21 . V_9 , V_239 -> V_9 ) )
continue;
if ( ! F_125 ( V_98 , V_239 -> V_236 ) )
continue;
V_49 = F_127 ( V_98 , V_239 -> V_198 , V_240 ) ;
if ( V_49 ) {
F_132 ( & V_239 -> V_123 , & V_19 -> V_123 ) ;
goto V_66;
}
V_239 -> V_198 ++ ;
}
if ( V_239 -> V_198 == 0 ) {
V_49 = - V_54 ;
goto V_66;
}
F_133 ( & V_239 -> V_123 ) ;
V_66:
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_49 ;
}
void F_134 ( struct V_182 * V_239 , T_4 V_9 ,
struct V_235 * V_236 )
{
F_55 ( & V_239 -> V_123 ) ;
V_239 -> V_9 = V_9 ;
V_239 -> V_98 = V_99 ;
V_239 -> V_198 = 0 ;
V_239 -> V_236 = V_236 ;
}
void F_135 ( struct V_182 * V_239 , struct V_1 * V_1 )
{
F_37 ( V_239 -> V_236 ) ;
if ( F_128 ( & V_239 -> V_123 ) )
return;
F_16 ( & V_1 -> V_6 . V_41 ) ;
F_63 ( & V_239 -> V_123 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
}
static void V_126 ( unsigned long V_240 )
{
struct V_18 * V_19 = (struct V_18 * ) V_240 ;
F_44 ( & V_19 -> V_96 ) ;
if ( V_19 -> V_97 . V_98 == V_163 ) {
if ( F_136 ( V_120 ( V_19 ) ) )
V_19 -> V_241 -> V_242 ( V_19 , V_243 ) ;
else
V_19 -> V_107 |= V_244 ;
}
F_50 ( & V_19 -> V_96 ) ;
}
void F_137 ( struct V_159 * V_245 , int V_246 , const struct V_170 * V_171 )
{
struct V_247 * V_97 ;
F_138 () ;
F_139 (km, &xfrm_km_list, list)
if ( V_97 -> V_248 )
V_97 -> V_248 ( V_245 , V_246 , V_171 ) ;
F_140 () ;
}
void F_141 ( struct V_18 * V_19 , const struct V_170 * V_171 )
{
struct V_247 * V_97 ;
F_138 () ;
F_139 (km, &xfrm_km_list, list)
if ( V_97 -> V_242 )
V_97 -> V_242 ( V_19 , V_171 ) ;
F_140 () ;
}
void F_45 ( struct V_18 * V_19 , int V_249 , T_2 V_250 )
{
struct V_170 V_171 ;
V_171 . V_240 . V_249 = V_249 ;
V_171 . V_250 = V_250 ;
V_171 . V_251 = V_252 ;
F_141 ( V_19 , & V_171 ) ;
}
int F_89 ( struct V_18 * V_19 , struct V_148 * V_253 , struct V_159 * V_160 )
{
int V_49 = - V_63 , V_254 ;
struct V_247 * V_97 ;
F_138 () ;
F_139 (km, &xfrm_km_list, list) {
V_254 = V_97 -> V_255 ( V_19 , V_253 , V_160 ) ;
if ( ! V_254 )
V_49 = V_254 ;
}
F_140 () ;
return V_49 ;
}
int F_142 ( struct V_18 * V_19 , T_1 * V_256 , T_6 V_257 )
{
int V_49 = - V_63 ;
struct V_247 * V_97 ;
F_138 () ;
F_139 (km, &xfrm_km_list, list) {
if ( V_97 -> V_258 )
V_49 = V_97 -> V_258 ( V_19 , V_256 , V_257 ) ;
if ( ! V_49 )
break;
}
F_140 () ;
return V_49 ;
}
void F_143 ( struct V_159 * V_160 , int V_246 , int V_249 , T_2 V_250 )
{
struct V_170 V_171 ;
V_171 . V_240 . V_249 = V_249 ;
V_171 . V_250 = V_250 ;
V_171 . V_251 = V_259 ;
F_137 ( V_160 , V_246 , & V_171 ) ;
}
int F_144 ( const struct V_260 * V_151 , T_4 V_246 , T_4 type ,
const struct V_208 * V_155 , int V_261 ,
const struct V_262 * V_263 )
{
int V_49 = - V_63 ;
int V_264 ;
struct V_247 * V_97 ;
F_138 () ;
F_139 (km, &xfrm_km_list, list) {
if ( V_97 -> V_265 ) {
V_264 = V_97 -> V_265 ( V_151 , V_246 , type , V_155 , V_261 , V_263 ) ;
if ( ! V_264 )
V_49 = V_264 ;
}
}
F_140 () ;
return V_49 ;
}
int F_145 ( struct V_1 * V_1 , T_4 V_9 , struct V_260 * V_151 , T_1 * V_266 )
{
int V_49 = - V_63 ;
int V_264 ;
struct V_247 * V_97 ;
F_138 () ;
F_139 (km, &xfrm_km_list, list) {
if ( V_97 -> V_267 ) {
V_264 = V_97 -> V_267 ( V_1 , V_9 , V_151 , V_266 ) ;
if ( ! V_264 )
V_49 = V_264 ;
}
}
F_140 () ;
return V_49 ;
}
bool F_87 ( const struct V_170 * V_171 )
{
struct V_247 * V_97 ;
bool V_268 = false ;
F_138 () ;
F_139 (km, &xfrm_km_list, list) {
if ( V_97 -> V_268 && V_97 -> V_268 ( V_171 ) ) {
V_268 = true ;
break;
}
}
F_140 () ;
return V_268 ;
}
int F_146 ( struct V_269 * V_270 , int V_271 , T_4 T_7 * V_272 , int V_273 )
{
int V_49 ;
T_4 * V_240 ;
struct V_247 * V_97 ;
struct V_159 * V_160 = NULL ;
if ( V_273 <= 0 || V_273 > V_274 )
return - V_275 ;
V_240 = F_147 ( V_273 , V_205 ) ;
if ( ! V_240 )
return - V_175 ;
V_49 = - V_276 ;
if ( F_148 ( V_240 , V_272 , V_273 ) )
goto V_66;
V_49 = - V_63 ;
F_138 () ;
F_139 (km, &xfrm_km_list, list) {
V_160 = V_97 -> V_277 ( V_270 , V_271 , V_240 ,
V_273 , & V_49 ) ;
if ( V_49 >= 0 )
break;
}
F_140 () ;
if ( V_49 >= 0 ) {
F_149 ( V_270 , V_49 , V_160 ) ;
F_150 ( V_160 ) ;
V_49 = 0 ;
}
V_66:
F_37 ( V_240 ) ;
return V_49 ;
}
int F_151 ( struct V_247 * V_97 )
{
F_16 ( & V_278 ) ;
F_152 ( & V_97 -> V_11 , & V_279 ) ;
F_17 ( & V_278 ) ;
return 0 ;
}
int F_153 ( struct V_247 * V_97 )
{
F_16 ( & V_278 ) ;
F_154 ( & V_97 -> V_11 ) ;
F_17 ( & V_278 ) ;
F_155 () ;
return 0 ;
}
int F_156 ( struct V_46 * V_47 )
{
int V_49 = 0 ;
if ( F_21 ( V_47 == NULL ) )
return - V_63 ;
if ( F_21 ( V_47 -> V_5 >= V_280 ) )
return - V_50 ;
F_16 ( & V_281 ) ;
if ( F_21 ( V_46 [ V_47 -> V_5 ] != NULL ) )
V_49 = - V_282 ;
else
F_157 ( V_46 [ V_47 -> V_5 ] , V_47 ) ;
F_17 ( & V_281 ) ;
return V_49 ;
}
int F_158 ( struct V_46 * V_47 )
{
int V_49 = 0 ;
if ( F_21 ( V_47 == NULL ) )
return - V_63 ;
if ( F_21 ( V_47 -> V_5 >= V_280 ) )
return - V_50 ;
F_16 ( & V_281 ) ;
if ( F_22 ( V_46 [ V_47 -> V_5 ] != NULL ) ) {
if ( F_21 ( V_46 [ V_47 -> V_5 ] != V_47 ) )
V_49 = - V_63 ;
else
F_159 ( V_46 [ V_47 -> V_5 ] , NULL ) ;
}
F_17 ( & V_281 ) ;
F_155 () ;
return V_49 ;
}
struct V_46 * F_20 ( unsigned int V_5 )
{
struct V_46 * V_47 ;
if ( F_21 ( V_5 >= V_280 ) )
return NULL ;
F_138 () ;
V_47 = F_160 ( V_46 [ V_5 ] ) ;
if ( F_21 ( ! V_47 ) )
F_140 () ;
return V_47 ;
}
void F_23 ( struct V_46 * V_47 )
{
F_140 () ;
}
void F_161 ( struct V_18 * V_19 )
{
if ( V_19 -> V_283 ) {
struct V_18 * V_253 = V_19 -> V_283 ;
if ( F_162 ( & V_253 -> V_122 ) == 2 )
F_66 ( V_253 ) ;
F_163 ( & V_253 -> V_122 ) ;
F_65 ( V_253 ) ;
V_19 -> V_283 = NULL ;
}
}
int F_164 ( struct V_18 * V_19 , int V_284 )
{
int V_223 ;
F_16 ( & V_19 -> V_96 ) ;
if ( V_19 -> V_97 . V_98 == V_163 &&
V_19 -> type && V_19 -> type -> V_285 )
V_223 = V_19 -> type -> V_285 ( V_19 , V_284 ) ;
else
V_223 = V_284 - V_19 -> V_22 . V_286 ;
F_17 ( & V_19 -> V_96 ) ;
return V_223 ;
}
int F_165 ( struct V_18 * V_19 , bool V_287 )
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
if ( V_47 -> V_288 )
V_49 = V_47 -> V_288 ( V_19 ) ;
F_23 ( V_47 ) ;
if ( V_49 )
goto error;
V_49 = - V_289 ;
if ( V_19 -> V_151 . V_5 != V_290 ) {
V_75 = F_32 ( V_19 -> V_22 . V_59 , V_19 -> V_151 . V_5 ) ;
if ( V_75 == NULL )
goto error;
if ( ! ( V_75 -> V_172 & V_291 ) &&
V_5 != V_19 -> V_151 . V_5 ) {
F_33 ( V_75 ) ;
goto error;
}
V_19 -> V_75 = V_75 ;
} else {
struct V_58 * V_76 ;
int V_292 = V_189 ;
V_75 = F_32 ( V_19 -> V_22 . V_59 , V_19 -> V_22 . V_5 ) ;
if ( V_75 == NULL )
goto error;
if ( ! ( V_75 -> V_172 & V_291 ) ) {
F_33 ( V_75 ) ;
goto error;
}
V_19 -> V_75 = V_75 ;
if ( V_19 -> V_22 . V_5 == V_189 )
V_292 = V_193 ;
V_76 = F_32 ( V_19 -> V_22 . V_59 , V_292 ) ;
if ( V_76 ) {
if ( V_76 -> V_172 & V_291 )
V_19 -> V_76 = V_76 ;
else
F_33 ( V_76 ) ;
}
}
V_19 -> type = F_25 ( V_19 -> V_21 . V_9 , V_5 ) ;
if ( V_19 -> type == NULL )
goto error;
V_49 = V_19 -> type -> V_293 ( V_19 ) ;
if ( V_49 )
goto error;
V_19 -> V_77 = F_32 ( V_19 -> V_22 . V_59 , V_5 ) ;
if ( V_19 -> V_77 == NULL ) {
V_49 = - V_289 ;
goto error;
}
if ( V_287 ) {
V_49 = F_166 ( V_19 ) ;
if ( V_49 )
goto error;
}
V_19 -> V_97 . V_98 = V_163 ;
error:
return V_49 ;
}
int F_107 ( struct V_18 * V_19 )
{
return F_165 ( V_19 , true ) ;
}
int T_8 F_167 ( struct V_1 * V_1 )
{
unsigned int V_294 ;
F_55 ( & V_1 -> V_6 . V_178 ) ;
V_294 = sizeof( struct V_10 ) * 8 ;
V_1 -> V_6 . V_42 = F_14 ( V_294 ) ;
if ( ! V_1 -> V_6 . V_42 )
goto V_295;
V_1 -> V_6 . V_43 = F_14 ( V_294 ) ;
if ( ! V_1 -> V_6 . V_43 )
goto V_296;
V_1 -> V_6 . V_44 = F_14 ( V_294 ) ;
if ( ! V_1 -> V_6 . V_44 )
goto V_297;
V_1 -> V_6 . V_7 = ( ( V_294 / sizeof( struct V_10 ) ) - 1 ) ;
V_1 -> V_6 . V_136 = 0 ;
F_168 ( & V_1 -> V_6 . V_28 , F_11 ) ;
F_169 ( & V_1 -> V_6 . V_82 ) ;
F_168 ( & V_1 -> V_6 . V_79 , F_39 ) ;
F_59 ( & V_1 -> V_6 . V_41 ) ;
return 0 ;
V_297:
F_15 ( V_1 -> V_6 . V_43 , V_294 ) ;
V_296:
F_15 ( V_1 -> V_6 . V_42 , V_294 ) ;
V_295:
return - V_175 ;
}
void F_170 ( struct V_1 * V_1 )
{
unsigned int V_294 ;
F_171 ( & V_1 -> V_6 . V_28 ) ;
F_71 ( V_1 , V_197 , false ) ;
F_171 ( & V_1 -> V_6 . V_79 ) ;
F_61 ( ! F_128 ( & V_1 -> V_6 . V_178 ) ) ;
V_294 = ( V_1 -> V_6 . V_7 + 1 ) * sizeof( struct V_10 ) ;
F_61 ( ! F_172 ( V_1 -> V_6 . V_44 ) ) ;
F_15 ( V_1 -> V_6 . V_44 , V_294 ) ;
F_61 ( ! F_172 ( V_1 -> V_6 . V_43 ) ) ;
F_15 ( V_1 -> V_6 . V_43 , V_294 ) ;
F_61 ( ! F_172 ( V_1 -> V_6 . V_42 ) ) ;
F_15 ( V_1 -> V_6 . V_42 , V_294 ) ;
}
static void F_173 ( struct V_18 * V_19 ,
struct V_298 * V_299 )
{
struct V_300 * V_301 = V_19 -> V_176 ;
T_2 V_8 = F_174 ( V_19 -> V_21 . V_8 ) ;
if ( V_301 )
F_175 ( V_299 , L_3 ,
V_301 -> V_302 , V_301 -> V_303 , V_301 -> V_304 ) ;
switch ( V_19 -> V_22 . V_5 ) {
case V_189 :
F_175 ( V_299 , L_4 ,
& V_19 -> V_22 . V_3 . V_190 , & V_19 -> V_21 . V_2 . V_190 ) ;
break;
case V_193 :
F_175 ( V_299 , L_5 ,
V_19 -> V_22 . V_3 . V_195 , V_19 -> V_21 . V_2 . V_195 ) ;
break;
}
F_175 ( V_299 , L_6 , V_8 , V_8 ) ;
}
static void F_176 ( struct V_305 * V_306 , T_9 V_5 ,
struct V_298 * V_299 )
{
const struct V_307 * V_308 ;
const struct V_309 * V_310 ;
switch ( V_5 ) {
case V_189 :
V_308 = F_177 ( V_306 ) ;
F_175 ( V_299 , L_4 ,
& V_308 -> V_3 , & V_308 -> V_2 ) ;
break;
case V_193 :
V_310 = F_178 ( V_306 ) ;
F_175 ( V_299 ,
L_7 ,
& V_310 -> V_3 , & V_310 -> V_2 ,
V_310 -> V_311 [ 0 ] & 0x0f ,
V_310 -> V_311 [ 1 ] ,
V_310 -> V_311 [ 2 ] ) ;
break;
}
}
void F_179 ( struct V_18 * V_19 , int V_312 , bool V_137 )
{
struct V_298 * V_299 ;
V_299 = F_180 ( L_8 ) ;
if ( V_299 == NULL )
return;
F_181 ( V_137 , V_299 ) ;
F_173 ( V_19 , V_299 ) ;
F_175 ( V_299 , L_9 , V_312 ) ;
F_182 ( V_299 ) ;
}
void F_49 ( struct V_18 * V_19 , int V_312 , bool V_137 )
{
struct V_298 * V_299 ;
V_299 = F_180 ( L_10 ) ;
if ( V_299 == NULL )
return;
F_181 ( V_137 , V_299 ) ;
F_173 ( V_19 , V_299 ) ;
F_175 ( V_299 , L_9 , V_312 ) ;
F_182 ( V_299 ) ;
}
void F_183 ( struct V_18 * V_19 ,
struct V_305 * V_306 )
{
struct V_298 * V_299 ;
T_2 V_8 ;
V_299 = F_180 ( L_11 ) ;
if ( V_299 == NULL )
return;
F_176 ( V_306 , V_19 -> V_22 . V_5 , V_299 ) ;
V_8 = F_174 ( V_19 -> V_21 . V_8 ) ;
F_175 ( V_299 , L_6 , V_8 , V_8 ) ;
F_182 ( V_299 ) ;
}
void F_184 ( struct V_18 * V_19 ,
struct V_305 * V_306 , T_3 V_313 )
{
struct V_298 * V_299 ;
T_2 V_8 ;
V_299 = F_180 ( L_12 ) ;
if ( V_299 == NULL )
return;
F_176 ( V_306 , V_19 -> V_22 . V_5 , V_299 ) ;
V_8 = F_174 ( V_19 -> V_21 . V_8 ) ;
F_175 ( V_299 , L_13 ,
V_8 , V_8 , F_174 ( V_313 ) ) ;
F_182 ( V_299 ) ;
}
void F_185 ( struct V_305 * V_306 , T_9 V_5 )
{
struct V_298 * V_299 ;
V_299 = F_180 ( L_14 ) ;
if ( V_299 == NULL )
return;
F_176 ( V_306 , V_5 , V_299 ) ;
F_182 ( V_299 ) ;
}
void F_186 ( struct V_305 * V_306 , T_9 V_5 ,
T_3 V_314 , T_3 V_313 )
{
struct V_298 * V_299 ;
T_2 V_8 ;
V_299 = F_180 ( L_14 ) ;
if ( V_299 == NULL )
return;
F_176 ( V_306 , V_5 , V_299 ) ;
V_8 = F_174 ( V_314 ) ;
F_175 ( V_299 , L_13 ,
V_8 , V_8 , F_174 ( V_313 ) ) ;
F_182 ( V_299 ) ;
}
void F_187 ( struct V_18 * V_19 ,
struct V_305 * V_306 , T_4 V_9 )
{
struct V_298 * V_299 ;
T_3 V_314 ;
T_3 V_313 ;
V_299 = F_180 ( L_15 ) ;
if ( V_299 == NULL )
return;
F_176 ( V_306 , V_19 -> V_22 . V_5 , V_299 ) ;
if ( F_188 ( V_306 , V_9 , & V_314 , & V_313 ) == 0 ) {
T_2 V_8 = F_174 ( V_314 ) ;
F_175 ( V_299 , L_13 ,
V_8 , V_8 , F_174 ( V_313 ) ) ;
}
F_182 ( V_299 ) ;
}
