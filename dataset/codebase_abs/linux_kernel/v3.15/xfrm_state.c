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
F_49 ( V_19 , V_49 ? 0 : 1 ,
F_50 ( V_118 ) ,
F_51 ( V_118 ) , 0 ) ;
V_66:
F_52 ( & V_19 -> V_96 ) ;
return V_119 ;
}
struct V_18 * F_53 ( struct V_1 * V_1 )
{
struct V_18 * V_19 ;
V_19 = F_54 ( sizeof( struct V_18 ) , V_120 ) ;
if ( V_19 ) {
F_55 ( & V_19 -> V_121 , V_1 ) ;
F_56 ( & V_19 -> V_122 , 1 ) ;
F_56 ( & V_19 -> V_123 , 0 ) ;
F_57 ( & V_19 -> V_97 . V_124 ) ;
F_58 ( & V_19 -> V_23 ) ;
F_58 ( & V_19 -> V_24 ) ;
F_58 ( & V_19 -> V_25 ) ;
F_59 ( & V_19 -> V_67 , F_42 ,
V_125 , V_126 ) ;
F_60 ( & V_19 -> V_68 , V_127 ,
( unsigned long ) V_19 ) ;
V_19 -> V_105 . V_106 = F_43 () ;
V_19 -> V_102 . V_128 = V_129 ;
V_19 -> V_102 . V_130 = V_129 ;
V_19 -> V_102 . V_131 = V_129 ;
V_19 -> V_102 . V_132 = V_129 ;
V_19 -> V_133 = 0 ;
V_19 -> V_134 = 0 ;
V_19 -> V_75 = NULL ;
V_19 -> V_76 = NULL ;
F_61 ( & V_19 -> V_96 ) ;
}
return V_19 ;
}
void F_62 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_121 ( V_19 ) ;
F_63 ( V_19 -> V_97 . V_98 != V_99 ) ;
F_16 ( & V_81 ) ;
F_9 ( & V_19 -> V_135 , & V_1 -> V_6 . V_82 ) ;
F_17 ( & V_81 ) ;
F_64 ( & V_1 -> V_6 . V_79 ) ;
}
int F_48 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_121 ( V_19 ) ;
int V_49 = - V_136 ;
if ( V_19 -> V_97 . V_98 != V_99 ) {
V_19 -> V_97 . V_98 = V_99 ;
F_44 ( & V_1 -> V_6 . V_41 ) ;
F_65 ( & V_19 -> V_97 . V_124 ) ;
F_66 ( & V_19 -> V_23 ) ;
F_66 ( & V_19 -> V_24 ) ;
if ( V_19 -> V_21 . V_8 )
F_66 ( & V_19 -> V_25 ) ;
V_1 -> V_6 . V_137 -- ;
F_52 ( & V_1 -> V_6 . V_41 ) ;
F_67 ( V_19 ) ;
V_49 = 0 ;
}
return V_49 ;
}
int F_68 ( struct V_18 * V_19 )
{
int V_49 ;
F_16 ( & V_19 -> V_96 ) ;
V_49 = F_48 ( V_19 ) ;
F_17 ( & V_19 -> V_96 ) ;
return V_49 ;
}
static inline int
F_69 ( struct V_1 * V_1 , T_4 V_9 , struct V_138 * V_139 )
{
int V_38 , V_49 = 0 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
F_70 (x, net->xfrm.state_bydst+i, bydst) {
if ( F_71 ( V_19 -> V_21 . V_9 , V_9 ) &&
( V_49 = F_72 ( V_19 ) ) != 0 ) {
F_49 ( V_19 , 0 ,
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
F_69 ( struct V_1 * V_1 , T_4 V_9 , struct V_138 * V_139 )
{
return 0 ;
}
int F_73 ( struct V_1 * V_1 , T_4 V_9 , struct V_138 * V_139 )
{
int V_38 , V_49 = 0 , V_143 = 0 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_49 = F_69 ( V_1 , V_9 , V_139 ) ;
if ( V_49 )
goto V_66;
V_49 = - V_136 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
V_144:
F_70 (x, net->xfrm.state_bydst+i, bydst) {
if ( ! F_74 ( V_19 ) &&
F_71 ( V_19 -> V_21 . V_9 , V_9 ) ) {
F_75 ( V_19 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
V_49 = F_68 ( V_19 ) ;
F_49 ( V_19 , V_49 ? 0 : 1 ,
V_139 -> V_140 ,
V_139 -> V_141 ,
V_139 -> V_142 ) ;
F_67 ( V_19 ) ;
if ( ! V_49 )
V_143 ++ ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
goto V_144;
}
}
}
if ( V_143 )
V_49 = 0 ;
V_66:
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_49 ;
}
void F_76 ( struct V_1 * V_1 , struct V_145 * V_146 )
{
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_146 -> V_147 = V_1 -> V_6 . V_137 ;
V_146 -> V_148 = V_1 -> V_6 . V_7 ;
V_146 -> V_149 = V_150 ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
}
static int
F_77 ( struct V_18 * V_19 , const struct V_151 * V_152 ,
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
static struct V_18 * F_78 ( struct V_1 * V_1 , T_2 V_159 ,
const T_1 * V_2 ,
T_3 V_8 , T_4 V_9 ,
unsigned short V_5 )
{
unsigned int V_20 = F_5 ( V_1 , V_2 , V_8 , V_9 , V_5 ) ;
struct V_18 * V_19 ;
F_70 (x, net->xfrm.state_byspi+h, byspi) {
if ( V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_21 . V_8 != V_8 ||
V_19 -> V_21 . V_9 != V_9 ||
! F_79 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) )
continue;
if ( ( V_159 & V_19 -> V_159 . V_160 ) != V_19 -> V_159 . V_161 )
continue;
F_75 ( V_19 ) ;
return V_19 ;
}
return NULL ;
}
static struct V_18 * F_80 ( struct V_1 * V_1 , T_2 V_159 ,
const T_1 * V_2 ,
const T_1 * V_3 ,
T_4 V_9 , unsigned short V_5 )
{
unsigned int V_20 = F_3 ( V_1 , V_2 , V_3 , V_5 ) ;
struct V_18 * V_19 ;
F_70 (x, net->xfrm.state_bysrc+h, bysrc) {
if ( V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_21 . V_9 != V_9 ||
! F_79 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) ||
! F_79 ( & V_19 -> V_22 . V_3 , V_3 , V_5 ) )
continue;
if ( ( V_159 & V_19 -> V_159 . V_160 ) != V_19 -> V_159 . V_161 )
continue;
F_75 ( V_19 ) ;
return V_19 ;
}
return NULL ;
}
static inline struct V_18 *
F_81 ( struct V_18 * V_19 , int V_162 , int V_5 )
{
struct V_1 * V_1 = V_121 ( V_19 ) ;
T_2 V_159 = V_19 -> V_159 . V_161 & V_19 -> V_159 . V_160 ;
if ( V_162 )
return F_78 ( V_1 , V_159 , & V_19 -> V_21 . V_2 ,
V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_5 ) ;
else
return F_80 ( V_1 , V_159 ,
& V_19 -> V_21 . V_2 ,
& V_19 -> V_22 . V_3 ,
V_19 -> V_21 . V_9 , V_5 ) ;
}
static void F_82 ( struct V_1 * V_1 , int V_163 )
{
if ( V_163 &&
( V_1 -> V_6 . V_7 + 1 ) < V_150 &&
V_1 -> V_6 . V_137 > V_1 -> V_6 . V_7 )
F_64 ( & V_1 -> V_6 . V_28 ) ;
}
static void F_83 ( struct V_164 * V_165 , struct V_18 * V_19 ,
const struct V_151 * V_152 , unsigned short V_5 ,
struct V_18 * * V_166 , int * V_167 ,
int * error )
{
if ( V_19 -> V_97 . V_98 == V_168 ) {
if ( ( V_19 -> V_156 . V_5 &&
! F_84 ( & V_19 -> V_156 , V_152 , V_19 -> V_156 . V_5 ) ) ||
! F_85 ( V_19 , V_165 , V_152 ) )
return;
if ( ! * V_166 ||
( * V_166 ) -> V_97 . V_112 > V_19 -> V_97 . V_112 ||
( ( * V_166 ) -> V_97 . V_112 == V_19 -> V_97 . V_112 &&
( * V_166 ) -> V_105 . V_106 < V_19 -> V_105 . V_106 ) )
* V_166 = V_19 ;
} else if ( V_19 -> V_97 . V_98 == V_117 ) {
* V_167 = 1 ;
} else if ( V_19 -> V_97 . V_98 == V_169 ||
V_19 -> V_97 . V_98 == V_100 ) {
if ( F_84 ( & V_19 -> V_156 , V_152 , V_19 -> V_156 . V_5 ) &&
F_85 ( V_19 , V_165 , V_152 ) )
* error = - V_136 ;
}
}
struct V_18 *
F_86 ( const T_1 * V_2 , const T_1 * V_3 ,
const struct V_151 * V_152 , struct V_153 * V_154 ,
struct V_164 * V_165 , int * V_49 ,
unsigned short V_5 )
{
static T_1 V_170 = { } ;
struct V_1 * V_1 = F_87 ( V_165 ) ;
unsigned int V_20 , V_171 ;
struct V_18 * V_19 , * V_172 , * V_173 ;
int V_174 = 0 ;
int error = 0 ;
struct V_18 * V_166 = NULL ;
T_2 V_159 = V_165 -> V_159 . V_161 & V_165 -> V_159 . V_160 ;
unsigned short V_157 = V_154 -> V_157 ;
struct V_175 V_176 ;
V_173 = NULL ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_20 = F_1 ( V_1 , V_2 , V_3 , V_154 -> V_4 , V_157 ) ;
F_70 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_157 &&
V_19 -> V_22 . V_4 == V_154 -> V_4 &&
( V_159 & V_19 -> V_159 . V_160 ) == V_19 -> V_159 . V_161 &&
! ( V_19 -> V_22 . V_177 & V_178 ) &&
F_88 ( V_19 , V_2 , V_3 , V_157 ) &&
V_154 -> V_59 == V_19 -> V_22 . V_59 &&
V_154 -> V_21 . V_9 == V_19 -> V_21 . V_9 &&
( V_154 -> V_21 . V_8 == V_19 -> V_21 . V_8 || ! V_154 -> V_21 . V_8 ) )
F_83 ( V_165 , V_19 , V_152 , V_157 ,
& V_166 , & V_174 , & error ) ;
}
if ( V_166 || V_174 )
goto V_179;
V_171 = F_1 ( V_1 , V_2 , & V_170 , V_154 -> V_4 , V_157 ) ;
F_70 (x, net->xfrm.state_bydst+h_wildcard, bydst) {
if ( V_19 -> V_22 . V_5 == V_157 &&
V_19 -> V_22 . V_4 == V_154 -> V_4 &&
( V_159 & V_19 -> V_159 . V_160 ) == V_19 -> V_159 . V_161 &&
! ( V_19 -> V_22 . V_177 & V_178 ) &&
F_79 ( & V_19 -> V_21 . V_2 , V_2 , V_157 ) &&
V_154 -> V_59 == V_19 -> V_22 . V_59 &&
V_154 -> V_21 . V_9 == V_19 -> V_21 . V_9 &&
( V_154 -> V_21 . V_8 == V_19 -> V_21 . V_8 || ! V_154 -> V_21 . V_8 ) )
F_83 ( V_165 , V_19 , V_152 , V_157 ,
& V_166 , & V_174 , & error ) ;
}
V_179:
V_19 = V_166 ;
if ( ! V_19 && ! error && ! V_174 ) {
if ( V_154 -> V_21 . V_8 &&
( V_172 = F_78 ( V_1 , V_159 , V_2 , V_154 -> V_21 . V_8 ,
V_154 -> V_21 . V_9 , V_157 ) ) != NULL ) {
V_173 = V_172 ;
error = - V_53 ;
goto V_66;
}
V_176 . V_1 = V_1 ;
if ( ! F_89 ( & V_176 ) ) {
error = - V_136 ;
goto V_66;
}
V_19 = F_53 ( V_1 ) ;
if ( V_19 == NULL ) {
error = - V_180 ;
goto V_66;
}
F_77 ( V_19 , V_152 , V_154 , V_2 , V_3 , V_5 ) ;
memcpy ( & V_19 -> V_159 , & V_165 -> V_159 , sizeof( V_19 -> V_159 ) ) ;
error = F_90 ( V_19 , V_165 -> V_181 , V_152 -> V_182 ) ;
if ( error ) {
V_19 -> V_97 . V_98 = V_99 ;
V_173 = V_19 ;
V_19 = NULL ;
goto V_66;
}
if ( F_91 ( V_19 , V_154 , V_165 ) == 0 ) {
V_19 -> V_97 . V_98 = V_117 ;
F_92 ( & V_19 -> V_97 . V_124 , & V_1 -> V_6 . V_183 ) ;
F_9 ( & V_19 -> V_23 , V_1 -> V_6 . V_42 + V_20 ) ;
V_20 = F_3 ( V_1 , V_2 , V_3 , V_157 ) ;
F_9 ( & V_19 -> V_24 , V_1 -> V_6 . V_43 + V_20 ) ;
if ( V_19 -> V_21 . V_8 ) {
V_20 = F_5 ( V_1 , & V_19 -> V_21 . V_2 , V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_157 ) ;
F_9 ( & V_19 -> V_25 , V_1 -> V_6 . V_44 + V_20 ) ;
}
V_19 -> V_102 . V_103 = V_1 -> V_6 . V_184 ;
F_46 ( & V_19 -> V_67 , F_47 ( V_1 -> V_6 . V_184 , 0 ) , V_116 ) ;
V_1 -> V_6 . V_137 ++ ;
F_82 ( V_1 , V_19 -> V_23 . V_93 != NULL ) ;
} else {
V_19 -> V_97 . V_98 = V_99 ;
V_173 = V_19 ;
V_19 = NULL ;
error = - V_136 ;
}
}
V_66:
if ( V_19 )
F_75 ( V_19 ) ;
else
* V_49 = V_174 ? - V_185 : error ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
if ( V_173 )
F_67 ( V_173 ) ;
return V_19 ;
}
struct V_18 *
F_93 ( struct V_1 * V_1 , T_2 V_159 ,
T_1 * V_2 , T_1 * V_3 ,
unsigned short V_5 , T_4 V_59 , T_4 V_9 , T_2 V_4 )
{
unsigned int V_20 ;
struct V_18 * V_186 = NULL , * V_19 = NULL ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_20 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_70 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_5 &&
V_19 -> V_22 . V_4 == V_4 &&
( V_159 & V_19 -> V_159 . V_160 ) == V_19 -> V_159 . V_161 &&
! ( V_19 -> V_22 . V_177 & V_178 ) &&
F_88 ( V_19 , V_2 , V_3 , V_5 ) &&
V_59 == V_19 -> V_22 . V_59 &&
V_9 == V_19 -> V_21 . V_9 &&
V_19 -> V_97 . V_98 == V_168 ) {
V_186 = V_19 ;
break;
}
}
if ( V_186 )
F_75 ( V_186 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_186 ;
}
struct V_18 * F_94 ( struct V_1 * V_1 , T_3 V_8 ,
unsigned short V_5 )
{
struct V_18 * V_19 ;
struct V_187 * V_188 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
F_95 (w, &net->xfrm.state_all, all) {
V_19 = F_12 ( V_188 , struct V_18 , V_97 ) ;
if ( V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_21 . V_8 != V_8 )
continue;
F_17 ( & V_1 -> V_6 . V_41 ) ;
F_75 ( V_19 ) ;
return V_19 ;
}
F_17 ( & V_1 -> V_6 . V_41 ) ;
return NULL ;
}
static void F_96 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_121 ( V_19 ) ;
unsigned int V_20 ;
F_92 ( & V_19 -> V_97 . V_124 , & V_1 -> V_6 . V_183 ) ;
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
if ( V_19 -> V_133 )
F_97 ( & V_19 -> V_68 , V_189 + V_19 -> V_133 ) ;
V_1 -> V_6 . V_137 ++ ;
F_82 ( V_1 , V_19 -> V_23 . V_93 != NULL ) ;
}
static void F_98 ( struct V_18 * V_190 )
{
struct V_1 * V_1 = V_121 ( V_190 ) ;
unsigned short V_5 = V_190 -> V_22 . V_5 ;
T_2 V_4 = V_190 -> V_22 . V_4 ;
struct V_18 * V_19 ;
unsigned int V_20 ;
T_2 V_159 = V_190 -> V_159 . V_161 & V_190 -> V_159 . V_160 ;
V_20 = F_1 ( V_1 , & V_190 -> V_21 . V_2 , & V_190 -> V_22 . V_3 , V_4 , V_5 ) ;
F_70 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_5 == V_5 &&
V_19 -> V_22 . V_4 == V_4 &&
( V_159 & V_19 -> V_159 . V_160 ) == V_19 -> V_159 . V_161 &&
F_79 ( & V_19 -> V_21 . V_2 , & V_190 -> V_21 . V_2 , V_5 ) &&
F_79 ( & V_19 -> V_22 . V_3 , & V_190 -> V_22 . V_3 , V_5 ) )
V_19 -> V_191 ++ ;
}
}
void F_99 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_121 ( V_19 ) ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
F_98 ( V_19 ) ;
F_96 ( V_19 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
}
static struct V_18 * F_100 ( struct V_1 * V_1 ,
const struct V_192 * V_160 ,
unsigned short V_5 , T_4 V_59 ,
T_2 V_4 , T_4 V_9 ,
const T_1 * V_2 ,
const T_1 * V_3 ,
int V_193 )
{
unsigned int V_20 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
struct V_18 * V_19 ;
T_2 V_159 = V_160 -> V_161 & V_160 -> V_160 ;
F_70 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_4 != V_4 ||
V_19 -> V_22 . V_59 != V_59 ||
V_19 -> V_22 . V_5 != V_5 ||
V_19 -> V_97 . V_98 != V_117 ||
V_19 -> V_21 . V_8 != 0 ||
V_19 -> V_21 . V_9 != V_9 ||
( V_159 & V_19 -> V_159 . V_160 ) != V_19 -> V_159 . V_161 ||
! F_79 ( & V_19 -> V_21 . V_2 , V_2 , V_5 ) ||
! F_79 ( & V_19 -> V_22 . V_3 , V_3 , V_5 ) )
continue;
F_75 ( V_19 ) ;
return V_19 ;
}
if ( ! V_193 )
return NULL ;
V_19 = F_53 ( V_1 ) ;
if ( F_22 ( V_19 ) ) {
switch ( V_5 ) {
case V_194 :
V_19 -> V_156 . V_2 . V_195 = V_2 -> V_195 ;
V_19 -> V_156 . V_3 . V_195 = V_3 -> V_195 ;
V_19 -> V_156 . V_196 = 32 ;
V_19 -> V_156 . V_197 = 32 ;
V_19 -> V_22 . V_3 . V_195 = V_3 -> V_195 ;
V_19 -> V_21 . V_2 . V_195 = V_2 -> V_195 ;
break;
case V_198 :
* (struct V_199 * ) V_19 -> V_156 . V_2 . V_200 = * (struct V_199 * ) V_2 ;
* (struct V_199 * ) V_19 -> V_156 . V_3 . V_200 = * (struct V_199 * ) V_3 ;
V_19 -> V_156 . V_196 = 128 ;
V_19 -> V_156 . V_197 = 128 ;
* (struct V_199 * ) V_19 -> V_22 . V_3 . V_200 = * (struct V_199 * ) V_3 ;
* (struct V_199 * ) V_19 -> V_21 . V_2 . V_200 = * (struct V_199 * ) V_2 ;
break;
}
V_19 -> V_97 . V_98 = V_117 ;
V_19 -> V_21 . V_9 = V_9 ;
V_19 -> V_22 . V_5 = V_5 ;
V_19 -> V_22 . V_59 = V_59 ;
V_19 -> V_22 . V_4 = V_4 ;
V_19 -> V_159 . V_161 = V_160 -> V_161 ;
V_19 -> V_159 . V_160 = V_160 -> V_160 ;
V_19 -> V_102 . V_103 = V_1 -> V_6 . V_184 ;
F_75 ( V_19 ) ;
F_46 ( & V_19 -> V_67 , F_47 ( V_1 -> V_6 . V_184 , 0 ) , V_116 ) ;
F_92 ( & V_19 -> V_97 . V_124 , & V_1 -> V_6 . V_183 ) ;
F_9 ( & V_19 -> V_23 , V_1 -> V_6 . V_42 + V_20 ) ;
V_20 = F_3 ( V_1 , V_2 , V_3 , V_5 ) ;
F_9 ( & V_19 -> V_24 , V_1 -> V_6 . V_43 + V_20 ) ;
V_1 -> V_6 . V_137 ++ ;
F_82 ( V_1 , V_19 -> V_23 . V_93 != NULL ) ;
}
return V_19 ;
}
int F_101 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_121 ( V_19 ) ;
struct V_18 * V_201 , * V_173 ;
int V_5 ;
int V_49 ;
T_2 V_159 = V_19 -> V_159 . V_161 & V_19 -> V_159 . V_160 ;
int V_162 = F_71 ( V_19 -> V_21 . V_9 , V_202 ) ;
V_5 = V_19 -> V_22 . V_5 ;
V_173 = NULL ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_201 = F_81 ( V_19 , V_162 , V_5 ) ;
if ( V_201 ) {
V_173 = V_201 ;
V_201 = NULL ;
V_49 = - V_53 ;
goto V_66;
}
if ( V_162 && V_19 -> V_97 . V_203 ) {
V_201 = F_102 ( V_1 , V_159 , V_19 -> V_97 . V_203 ) ;
if ( V_201 && ( ( V_201 -> V_21 . V_9 != V_19 -> V_21 . V_9 ) ||
! F_79 ( & V_201 -> V_21 . V_2 , & V_19 -> V_21 . V_2 , V_5 ) ) ) {
V_173 = V_201 ;
V_201 = NULL ;
}
}
if ( V_162 && ! V_201 )
V_201 = F_100 ( V_1 , & V_19 -> V_159 , V_5 , V_19 -> V_22 . V_59 ,
V_19 -> V_22 . V_4 , V_19 -> V_21 . V_9 ,
& V_19 -> V_21 . V_2 , & V_19 -> V_22 . V_3 , 0 ) ;
F_98 ( V_19 ) ;
F_96 ( V_19 ) ;
V_49 = 0 ;
V_66:
F_17 ( & V_1 -> V_6 . V_41 ) ;
if ( V_201 ) {
F_68 ( V_201 ) ;
F_67 ( V_201 ) ;
}
if ( V_173 )
F_67 ( V_173 ) ;
return V_49 ;
}
static struct V_18 * F_103 ( struct V_18 * V_204 )
{
struct V_1 * V_1 = V_121 ( V_204 ) ;
struct V_18 * V_19 = F_53 ( V_1 ) ;
if ( ! V_19 )
goto V_66;
memcpy ( & V_19 -> V_21 , & V_204 -> V_21 , sizeof( V_19 -> V_21 ) ) ;
memcpy ( & V_19 -> V_156 , & V_204 -> V_156 , sizeof( V_19 -> V_156 ) ) ;
memcpy ( & V_19 -> V_102 , & V_204 -> V_102 , sizeof( V_19 -> V_102 ) ) ;
V_19 -> V_22 . V_59 = V_204 -> V_22 . V_59 ;
V_19 -> V_22 . V_205 = V_204 -> V_22 . V_205 ;
V_19 -> V_22 . V_4 = V_204 -> V_22 . V_4 ;
V_19 -> V_22 . V_5 = V_204 -> V_22 . V_5 ;
V_19 -> V_22 . V_3 = V_204 -> V_22 . V_3 ;
if ( V_204 -> V_69 ) {
V_19 -> V_69 = F_104 ( V_204 -> V_69 ) ;
if ( ! V_19 -> V_69 )
goto error;
}
V_19 -> V_22 . V_206 = V_204 -> V_22 . V_206 ;
if ( V_204 -> V_207 ) {
V_19 -> V_207 = F_105 ( V_204 -> V_207 ) ;
if ( ! V_19 -> V_207 )
goto error;
}
if ( V_204 -> V_70 ) {
V_19 -> V_70 = F_106 ( V_204 -> V_70 ) ;
if ( ! V_19 -> V_70 )
goto error;
}
V_19 -> V_22 . V_208 = V_204 -> V_22 . V_208 ;
if ( V_204 -> V_71 ) {
V_19 -> V_71 = F_106 ( V_204 -> V_71 ) ;
if ( ! V_19 -> V_71 )
goto error;
}
V_19 -> V_22 . V_209 = V_204 -> V_22 . V_209 ;
if ( V_204 -> V_61 ) {
V_19 -> V_61 = F_107 ( V_204 -> V_61 , sizeof( * V_19 -> V_61 ) , V_210 ) ;
if ( ! V_19 -> V_61 )
goto error;
}
if ( V_204 -> V_72 ) {
V_19 -> V_72 = F_107 ( V_204 -> V_72 , sizeof( * V_19 -> V_72 ) ,
V_210 ) ;
if ( ! V_19 -> V_72 )
goto error;
}
if ( V_204 -> V_73 ) {
if ( F_108 ( V_19 , V_204 ) )
goto error;
}
memcpy ( & V_19 -> V_159 , & V_204 -> V_159 , sizeof( V_19 -> V_159 ) ) ;
if ( F_109 ( V_19 ) < 0 )
goto error;
V_19 -> V_22 . V_177 = V_204 -> V_22 . V_177 ;
V_19 -> V_22 . V_211 = V_204 -> V_22 . V_211 ;
V_19 -> V_212 = V_204 -> V_212 ;
V_19 -> V_134 = V_204 -> V_134 ;
V_19 -> V_133 = V_204 -> V_133 ;
V_19 -> V_105 . V_106 = V_204 -> V_105 . V_106 ;
V_19 -> V_97 . V_98 = V_204 -> V_97 . V_98 ;
V_19 -> V_97 . V_203 = V_204 -> V_97 . V_203 ;
return V_19 ;
error:
F_67 ( V_19 ) ;
V_66:
return NULL ;
}
struct V_18 * F_110 ( struct V_213 * V_160 , struct V_1 * V_1 )
{
unsigned int V_20 ;
struct V_18 * V_19 = NULL ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
if ( V_160 -> V_4 ) {
V_20 = F_1 ( V_1 , & V_160 -> V_214 , & V_160 -> V_215 ,
V_160 -> V_4 , V_160 -> V_216 ) ;
F_70 (x, net->xfrm.state_bydst+h, bydst) {
if ( V_19 -> V_22 . V_59 != V_160 -> V_59 ||
V_19 -> V_21 . V_9 != V_160 -> V_9 )
continue;
if ( V_160 -> V_4 && V_19 -> V_22 . V_4 != V_160 -> V_4 )
continue;
if ( ! F_79 ( & V_19 -> V_21 . V_2 , & V_160 -> V_214 ,
V_160 -> V_216 ) ||
! F_79 ( & V_19 -> V_22 . V_3 , & V_160 -> V_215 ,
V_160 -> V_216 ) )
continue;
F_75 ( V_19 ) ;
break;
}
} else {
V_20 = F_3 ( V_1 , & V_160 -> V_214 , & V_160 -> V_215 ,
V_160 -> V_216 ) ;
F_70 (x, net->xfrm.state_bysrc+h, bysrc) {
if ( V_19 -> V_22 . V_59 != V_160 -> V_59 ||
V_19 -> V_21 . V_9 != V_160 -> V_9 )
continue;
if ( ! F_79 ( & V_19 -> V_21 . V_2 , & V_160 -> V_214 ,
V_160 -> V_216 ) ||
! F_79 ( & V_19 -> V_22 . V_3 , & V_160 -> V_215 ,
V_160 -> V_216 ) )
continue;
F_75 ( V_19 ) ;
break;
}
}
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_19 ;
}
struct V_18 * F_111 ( struct V_18 * V_19 ,
struct V_213 * V_160 )
{
struct V_18 * V_217 ;
V_217 = F_103 ( V_19 ) ;
if ( ! V_217 )
return NULL ;
memcpy ( & V_217 -> V_21 . V_2 , & V_160 -> V_218 , sizeof( V_217 -> V_21 . V_2 ) ) ;
memcpy ( & V_217 -> V_22 . V_3 , & V_160 -> V_219 , sizeof( V_217 -> V_22 . V_3 ) ) ;
if ( F_79 ( & V_19 -> V_21 . V_2 , & V_160 -> V_218 , V_160 -> V_220 ) ) {
F_99 ( V_217 ) ;
} else {
if ( F_101 ( V_217 ) < 0 )
goto error;
}
return V_217 ;
error:
F_67 ( V_217 ) ;
return NULL ;
}
int F_112 ( struct V_18 * V_19 )
{
struct V_18 * V_201 , * V_173 ;
int V_49 ;
int V_162 = F_71 ( V_19 -> V_21 . V_9 , V_202 ) ;
struct V_1 * V_1 = V_121 ( V_19 ) ;
V_173 = NULL ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_201 = F_81 ( V_19 , V_162 , V_19 -> V_22 . V_5 ) ;
V_49 = - V_136 ;
if ( ! V_201 )
goto V_66;
if ( F_74 ( V_201 ) ) {
V_173 = V_201 ;
V_49 = - V_53 ;
goto V_66;
}
if ( V_201 -> V_97 . V_98 == V_117 ) {
F_96 ( V_19 ) ;
V_19 = NULL ;
}
V_49 = 0 ;
V_66:
F_17 ( & V_1 -> V_6 . V_41 ) ;
if ( V_173 )
F_67 ( V_173 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_19 ) {
F_68 ( V_201 ) ;
F_67 ( V_201 ) ;
return 0 ;
}
V_49 = - V_63 ;
F_16 ( & V_201 -> V_96 ) ;
if ( F_22 ( V_201 -> V_97 . V_98 == V_168 ) ) {
if ( V_19 -> V_61 && V_201 -> V_61 )
memcpy ( V_201 -> V_61 , V_19 -> V_61 , sizeof( * V_201 -> V_61 ) ) ;
if ( V_19 -> V_72 && V_201 -> V_72 ) {
memcpy ( V_201 -> V_72 , V_19 -> V_72 , sizeof( * V_201 -> V_72 ) ) ;
}
if ( ! V_162 && memcmp ( & V_201 -> V_156 , & V_19 -> V_156 , sizeof( V_201 -> V_156 ) ) )
memcpy ( & V_201 -> V_156 , & V_19 -> V_156 , sizeof( V_201 -> V_156 ) ) ;
memcpy ( & V_201 -> V_102 , & V_19 -> V_102 , sizeof( V_201 -> V_102 ) ) ;
V_201 -> V_97 . V_112 = 0 ;
F_46 ( & V_201 -> V_67 , F_47 ( 1 , 0 ) , V_116 ) ;
if ( V_201 -> V_105 . V_111 )
F_113 ( V_201 ) ;
V_49 = 0 ;
V_19 -> V_97 . V_98 = V_99 ;
F_114 ( V_19 ) ;
}
F_17 ( & V_201 -> V_96 ) ;
F_67 ( V_201 ) ;
return V_49 ;
}
int F_113 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_105 . V_111 )
V_19 -> V_105 . V_111 = F_43 () ;
if ( V_19 -> V_105 . V_221 >= V_19 -> V_102 . V_131 ||
V_19 -> V_105 . V_222 >= V_19 -> V_102 . V_132 ) {
V_19 -> V_97 . V_98 = V_100 ;
F_46 ( & V_19 -> V_67 , F_47 ( 0 , 0 ) , V_116 ) ;
return - V_63 ;
}
if ( ! V_19 -> V_97 . V_112 &&
( V_19 -> V_105 . V_221 >= V_19 -> V_102 . V_128 ||
V_19 -> V_105 . V_222 >= V_19 -> V_102 . V_130 ) ) {
V_19 -> V_97 . V_112 = 1 ;
F_45 ( V_19 , 0 , 0 ) ;
}
return 0 ;
}
struct V_18 *
F_115 ( struct V_1 * V_1 , T_2 V_159 , const T_1 * V_2 , T_3 V_8 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_19 = F_78 ( V_1 , V_159 , V_2 , V_8 , V_9 , V_5 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_19 ;
}
struct V_18 *
F_116 ( struct V_1 * V_1 , T_2 V_159 ,
const T_1 * V_2 , const T_1 * V_3 ,
T_4 V_9 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_19 = F_80 ( V_1 , V_159 , V_2 , V_3 , V_9 , V_5 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_19 ;
}
struct V_18 *
F_117 ( struct V_1 * V_1 , const struct V_192 * V_159 , T_4 V_59 , T_2 V_4 ,
T_4 V_9 , const T_1 * V_2 ,
const T_1 * V_3 , int V_193 , unsigned short V_5 )
{
struct V_18 * V_19 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_19 = F_100 ( V_1 , V_159 , V_5 , V_59 , V_4 , V_9 , V_2 , V_3 , V_193 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_19 ;
}
int
F_118 ( struct V_153 * * V_223 , struct V_153 * * V_224 , int V_225 ,
unsigned short V_5 , struct V_1 * V_1 )
{
int V_49 = 0 ;
struct V_46 * V_47 = F_20 ( V_5 ) ;
if ( ! V_47 )
return - V_50 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
if ( V_47 -> V_226 )
V_49 = V_47 -> V_226 ( V_223 , V_224 , V_225 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
F_23 ( V_47 ) ;
return V_49 ;
}
int
F_119 ( struct V_18 * * V_223 , struct V_18 * * V_224 , int V_225 ,
unsigned short V_5 )
{
int V_49 = 0 ;
struct V_46 * V_47 = F_20 ( V_5 ) ;
struct V_1 * V_1 = V_121 ( * V_224 ) ;
if ( ! V_47 )
return - V_50 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
if ( V_47 -> V_227 )
V_49 = V_47 -> V_227 ( V_223 , V_224 , V_225 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
F_23 ( V_47 ) ;
return V_49 ;
}
static struct V_18 * F_102 ( struct V_1 * V_1 , T_2 V_159 , T_2 V_203 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 <= V_1 -> V_6 . V_7 ; V_38 ++ ) {
struct V_18 * V_19 ;
F_70 (x, net->xfrm.state_bydst+i, bydst) {
if ( V_19 -> V_97 . V_203 == V_203 &&
( V_159 & V_19 -> V_159 . V_160 ) == V_19 -> V_159 . V_161 &&
V_19 -> V_97 . V_98 == V_117 ) {
F_75 ( V_19 ) ;
return V_19 ;
}
}
}
return NULL ;
}
struct V_18 * F_120 ( struct V_1 * V_1 , T_2 V_159 , T_2 V_203 )
{
struct V_18 * V_19 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_19 = F_102 ( V_1 , V_159 , V_203 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_19 ;
}
T_2 F_121 ( void )
{
T_2 V_228 ;
static T_5 V_229 ;
do {
V_228 = F_122 ( & V_229 ) ;
} while ( ! V_228 );
return V_228 ;
}
int F_123 ( T_4 V_9 , T_2 V_230 , T_2 V_231 )
{
switch ( V_9 ) {
case V_232 :
case V_233 :
break;
case V_234 :
if ( V_231 >= 0x10000 )
return - V_63 ;
break;
default:
return - V_63 ;
}
if ( V_230 > V_231 )
return - V_63 ;
return 0 ;
}
int F_124 ( struct V_18 * V_19 , T_2 V_235 , T_2 V_236 )
{
struct V_1 * V_1 = V_121 ( V_19 ) ;
unsigned int V_20 ;
struct V_18 * V_172 ;
int V_49 = - V_54 ;
T_3 V_237 = F_125 ( V_235 ) ;
T_3 V_238 = F_125 ( V_236 ) ;
T_2 V_159 = V_19 -> V_159 . V_161 & V_19 -> V_159 . V_160 ;
F_16 ( & V_19 -> V_96 ) ;
if ( V_19 -> V_97 . V_98 == V_99 )
goto V_239;
V_49 = 0 ;
if ( V_19 -> V_21 . V_8 )
goto V_239;
V_49 = - V_54 ;
if ( V_237 == V_238 ) {
V_172 = F_115 ( V_1 , V_159 , & V_19 -> V_21 . V_2 , V_237 , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
if ( V_172 ) {
F_67 ( V_172 ) ;
goto V_239;
}
V_19 -> V_21 . V_8 = V_237 ;
} else {
T_2 V_8 = 0 ;
for ( V_20 = 0 ; V_20 < V_236 - V_235 + 1 ; V_20 ++ ) {
V_8 = V_235 + F_126 () % ( V_236 - V_235 + 1 ) ;
V_172 = F_115 ( V_1 , V_159 , & V_19 -> V_21 . V_2 , F_125 ( V_8 ) , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
if ( V_172 == NULL ) {
V_19 -> V_21 . V_8 = F_125 ( V_8 ) ;
break;
}
F_67 ( V_172 ) ;
}
}
if ( V_19 -> V_21 . V_8 ) {
F_16 ( & V_1 -> V_6 . V_41 ) ;
V_20 = F_5 ( V_1 , & V_19 -> V_21 . V_2 , V_19 -> V_21 . V_8 , V_19 -> V_21 . V_9 , V_19 -> V_22 . V_5 ) ;
F_9 ( & V_19 -> V_25 , V_1 -> V_6 . V_44 + V_20 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
V_49 = 0 ;
}
V_239:
F_17 ( & V_19 -> V_96 ) ;
return V_49 ;
}
static bool F_127 ( struct V_18 * V_19 ,
struct V_240 * V_241 )
{
if ( V_241 ) {
if ( ( V_241 -> V_5 == V_194 ||
V_241 -> V_5 == V_198 ) &&
V_19 -> V_22 . V_5 != V_241 -> V_5 )
return false ;
return F_128 ( & V_19 -> V_22 . V_3 , & V_241 -> V_3 ,
V_241 -> V_242 ) &&
F_128 ( & V_19 -> V_21 . V_2 , & V_241 -> V_2 ,
V_241 -> V_243 ) ;
}
return true ;
}
int V_187 ( struct V_1 * V_1 , struct V_187 * V_244 ,
int (* F_129)( struct V_18 * , int , void * ) ,
void * V_245 )
{
struct V_18 * V_98 ;
struct V_187 * V_19 ;
int V_49 = 0 ;
if ( V_244 -> V_203 != 0 && F_130 ( & V_244 -> V_124 ) )
return 0 ;
F_16 ( & V_1 -> V_6 . V_41 ) ;
if ( F_130 ( & V_244 -> V_124 ) )
V_19 = F_131 ( & V_1 -> V_6 . V_183 , struct V_187 , V_124 ) ;
else
V_19 = F_132 ( & V_244 -> V_124 , struct V_187 , V_124 ) ;
F_133 (x, &net->xfrm.state_all, all) {
if ( V_19 -> V_98 == V_99 )
continue;
V_98 = F_12 ( V_19 , struct V_18 , V_97 ) ;
if ( ! F_71 ( V_98 -> V_21 . V_9 , V_244 -> V_9 ) )
continue;
if ( ! F_127 ( V_98 , V_244 -> V_241 ) )
continue;
V_49 = F_129 ( V_98 , V_244 -> V_203 , V_245 ) ;
if ( V_49 ) {
F_134 ( & V_244 -> V_124 , & V_19 -> V_124 ) ;
goto V_66;
}
V_244 -> V_203 ++ ;
}
if ( V_244 -> V_203 == 0 ) {
V_49 = - V_54 ;
goto V_66;
}
F_135 ( & V_244 -> V_124 ) ;
V_66:
F_17 ( & V_1 -> V_6 . V_41 ) ;
return V_49 ;
}
void F_136 ( struct V_187 * V_244 , T_4 V_9 ,
struct V_240 * V_241 )
{
F_57 ( & V_244 -> V_124 ) ;
V_244 -> V_9 = V_9 ;
V_244 -> V_98 = V_99 ;
V_244 -> V_203 = 0 ;
V_244 -> V_241 = V_241 ;
}
void F_137 ( struct V_187 * V_244 , struct V_1 * V_1 )
{
F_37 ( V_244 -> V_241 ) ;
if ( F_130 ( & V_244 -> V_124 ) )
return;
F_16 ( & V_1 -> V_6 . V_41 ) ;
F_65 ( & V_244 -> V_124 ) ;
F_17 ( & V_1 -> V_6 . V_41 ) ;
}
static void V_127 ( unsigned long V_245 )
{
struct V_18 * V_19 = (struct V_18 * ) V_245 ;
F_44 ( & V_19 -> V_96 ) ;
if ( V_19 -> V_97 . V_98 == V_168 ) {
if ( F_138 ( V_121 ( V_19 ) ) )
V_19 -> V_246 -> V_247 ( V_19 , V_248 ) ;
else
V_19 -> V_107 |= V_249 ;
}
F_52 ( & V_19 -> V_96 ) ;
}
void F_139 ( struct V_164 * V_250 , int V_251 , const struct V_175 * V_176 )
{
struct V_252 * V_97 ;
F_140 () ;
F_141 (km, &xfrm_km_list, list)
if ( V_97 -> V_253 )
V_97 -> V_253 ( V_250 , V_251 , V_176 ) ;
F_142 () ;
}
void F_143 ( struct V_18 * V_19 , const struct V_175 * V_176 )
{
struct V_252 * V_97 ;
F_140 () ;
F_141 (km, &xfrm_km_list, list)
if ( V_97 -> V_247 )
V_97 -> V_247 ( V_19 , V_176 ) ;
F_142 () ;
}
void F_45 ( struct V_18 * V_19 , int V_254 , T_2 V_255 )
{
struct V_175 V_176 ;
V_176 . V_245 . V_254 = V_254 ;
V_176 . V_255 = V_255 ;
V_176 . V_256 = V_257 ;
F_143 ( V_19 , & V_176 ) ;
}
int F_91 ( struct V_18 * V_19 , struct V_153 * V_258 , struct V_164 * V_165 )
{
int V_49 = - V_63 , V_259 ;
struct V_252 * V_97 ;
F_140 () ;
F_141 (km, &xfrm_km_list, list) {
V_259 = V_97 -> V_260 ( V_19 , V_258 , V_165 ) ;
if ( ! V_259 )
V_49 = V_259 ;
}
F_142 () ;
return V_49 ;
}
int F_144 ( struct V_18 * V_19 , T_1 * V_261 , T_6 V_262 )
{
int V_49 = - V_63 ;
struct V_252 * V_97 ;
F_140 () ;
F_141 (km, &xfrm_km_list, list) {
if ( V_97 -> V_263 )
V_49 = V_97 -> V_263 ( V_19 , V_261 , V_262 ) ;
if ( ! V_49 )
break;
}
F_142 () ;
return V_49 ;
}
void F_145 ( struct V_164 * V_165 , int V_251 , int V_254 , T_2 V_255 )
{
struct V_175 V_176 ;
V_176 . V_245 . V_254 = V_254 ;
V_176 . V_255 = V_255 ;
V_176 . V_256 = V_264 ;
F_139 ( V_165 , V_251 , & V_176 ) ;
}
int F_146 ( const struct V_265 * V_156 , T_4 V_251 , T_4 type ,
const struct V_213 * V_160 , int V_266 ,
const struct V_267 * V_268 )
{
int V_49 = - V_63 ;
int V_269 ;
struct V_252 * V_97 ;
F_140 () ;
F_141 (km, &xfrm_km_list, list) {
if ( V_97 -> V_270 ) {
V_269 = V_97 -> V_270 ( V_156 , V_251 , type , V_160 , V_266 , V_268 ) ;
if ( ! V_269 )
V_49 = V_269 ;
}
}
F_142 () ;
return V_49 ;
}
int F_147 ( struct V_1 * V_1 , T_4 V_9 , struct V_265 * V_156 , T_1 * V_271 )
{
int V_49 = - V_63 ;
int V_269 ;
struct V_252 * V_97 ;
F_140 () ;
F_141 (km, &xfrm_km_list, list) {
if ( V_97 -> V_272 ) {
V_269 = V_97 -> V_272 ( V_1 , V_9 , V_156 , V_271 ) ;
if ( ! V_269 )
V_49 = V_269 ;
}
}
F_142 () ;
return V_49 ;
}
bool F_89 ( const struct V_175 * V_176 )
{
struct V_252 * V_97 ;
bool V_273 = false ;
F_140 () ;
F_141 (km, &xfrm_km_list, list) {
if ( V_97 -> V_273 && V_97 -> V_273 ( V_176 ) ) {
V_273 = true ;
break;
}
}
F_142 () ;
return V_273 ;
}
int F_148 ( struct V_274 * V_275 , int V_276 , T_4 T_7 * V_277 , int V_278 )
{
int V_49 ;
T_4 * V_245 ;
struct V_252 * V_97 ;
struct V_164 * V_165 = NULL ;
if ( V_278 <= 0 || V_278 > V_279 )
return - V_280 ;
V_245 = F_149 ( V_278 , V_210 ) ;
if ( ! V_245 )
return - V_180 ;
V_49 = - V_281 ;
if ( F_150 ( V_245 , V_277 , V_278 ) )
goto V_66;
V_49 = - V_63 ;
F_140 () ;
F_141 (km, &xfrm_km_list, list) {
V_165 = V_97 -> V_282 ( V_275 , V_276 , V_245 ,
V_278 , & V_49 ) ;
if ( V_49 >= 0 )
break;
}
F_142 () ;
if ( V_49 >= 0 ) {
F_151 ( V_275 , V_49 , V_165 ) ;
F_152 ( V_165 ) ;
V_49 = 0 ;
}
V_66:
F_37 ( V_245 ) ;
return V_49 ;
}
int F_153 ( struct V_252 * V_97 )
{
F_16 ( & V_283 ) ;
F_154 ( & V_97 -> V_11 , & V_284 ) ;
F_17 ( & V_283 ) ;
return 0 ;
}
int F_155 ( struct V_252 * V_97 )
{
F_16 ( & V_283 ) ;
F_156 ( & V_97 -> V_11 ) ;
F_17 ( & V_283 ) ;
F_157 () ;
return 0 ;
}
int F_158 ( struct V_46 * V_47 )
{
int V_49 = 0 ;
if ( F_21 ( V_47 == NULL ) )
return - V_63 ;
if ( F_21 ( V_47 -> V_5 >= V_285 ) )
return - V_50 ;
F_16 ( & V_286 ) ;
if ( F_21 ( V_46 [ V_47 -> V_5 ] != NULL ) )
V_49 = - V_287 ;
else
F_159 ( V_46 [ V_47 -> V_5 ] , V_47 ) ;
F_17 ( & V_286 ) ;
return V_49 ;
}
int F_160 ( struct V_46 * V_47 )
{
int V_49 = 0 ;
if ( F_21 ( V_47 == NULL ) )
return - V_63 ;
if ( F_21 ( V_47 -> V_5 >= V_285 ) )
return - V_50 ;
F_16 ( & V_286 ) ;
if ( F_22 ( V_46 [ V_47 -> V_5 ] != NULL ) ) {
if ( F_21 ( V_46 [ V_47 -> V_5 ] != V_47 ) )
V_49 = - V_63 ;
else
F_161 ( V_46 [ V_47 -> V_5 ] , NULL ) ;
}
F_17 ( & V_286 ) ;
F_157 () ;
return V_49 ;
}
struct V_46 * F_20 ( unsigned int V_5 )
{
struct V_46 * V_47 ;
if ( F_21 ( V_5 >= V_285 ) )
return NULL ;
F_140 () ;
V_47 = F_162 ( V_46 [ V_5 ] ) ;
if ( F_21 ( ! V_47 ) )
F_142 () ;
return V_47 ;
}
void F_23 ( struct V_46 * V_47 )
{
F_142 () ;
}
void F_163 ( struct V_18 * V_19 )
{
if ( V_19 -> V_288 ) {
struct V_18 * V_258 = V_19 -> V_288 ;
if ( F_164 ( & V_258 -> V_123 ) == 2 )
F_68 ( V_258 ) ;
F_165 ( & V_258 -> V_123 ) ;
F_67 ( V_258 ) ;
V_19 -> V_288 = NULL ;
}
}
int F_166 ( struct V_18 * V_19 , int V_289 )
{
int V_228 ;
F_16 ( & V_19 -> V_96 ) ;
if ( V_19 -> V_97 . V_98 == V_168 &&
V_19 -> type && V_19 -> type -> V_290 )
V_228 = V_19 -> type -> V_290 ( V_19 , V_289 ) ;
else
V_228 = V_289 - V_19 -> V_22 . V_291 ;
F_17 ( & V_19 -> V_96 ) ;
return V_228 ;
}
int F_167 ( struct V_18 * V_19 , bool V_292 )
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
if ( V_47 -> V_293 )
V_49 = V_47 -> V_293 ( V_19 ) ;
F_23 ( V_47 ) ;
if ( V_49 )
goto error;
V_49 = - V_294 ;
if ( V_19 -> V_156 . V_5 != V_295 ) {
V_75 = F_32 ( V_19 -> V_22 . V_59 , V_19 -> V_156 . V_5 ) ;
if ( V_75 == NULL )
goto error;
if ( ! ( V_75 -> V_177 & V_296 ) &&
V_5 != V_19 -> V_156 . V_5 ) {
F_33 ( V_75 ) ;
goto error;
}
V_19 -> V_75 = V_75 ;
} else {
struct V_58 * V_76 ;
int V_297 = V_194 ;
V_75 = F_32 ( V_19 -> V_22 . V_59 , V_19 -> V_22 . V_5 ) ;
if ( V_75 == NULL )
goto error;
if ( ! ( V_75 -> V_177 & V_296 ) ) {
F_33 ( V_75 ) ;
goto error;
}
V_19 -> V_75 = V_75 ;
if ( V_19 -> V_22 . V_5 == V_194 )
V_297 = V_198 ;
V_76 = F_32 ( V_19 -> V_22 . V_59 , V_297 ) ;
if ( V_76 ) {
if ( V_76 -> V_177 & V_296 )
V_19 -> V_76 = V_76 ;
else
F_33 ( V_76 ) ;
}
}
V_19 -> type = F_25 ( V_19 -> V_21 . V_9 , V_5 ) ;
if ( V_19 -> type == NULL )
goto error;
V_49 = V_19 -> type -> V_298 ( V_19 ) ;
if ( V_49 )
goto error;
V_19 -> V_77 = F_32 ( V_19 -> V_22 . V_59 , V_5 ) ;
if ( V_19 -> V_77 == NULL ) {
V_49 = - V_294 ;
goto error;
}
if ( V_292 ) {
V_49 = F_168 ( V_19 ) ;
if ( V_49 )
goto error;
}
V_19 -> V_97 . V_98 = V_168 ;
error:
return V_49 ;
}
int F_109 ( struct V_18 * V_19 )
{
return F_167 ( V_19 , true ) ;
}
int T_8 F_169 ( struct V_1 * V_1 )
{
unsigned int V_299 ;
F_57 ( & V_1 -> V_6 . V_183 ) ;
V_299 = sizeof( struct V_10 ) * 8 ;
V_1 -> V_6 . V_42 = F_14 ( V_299 ) ;
if ( ! V_1 -> V_6 . V_42 )
goto V_300;
V_1 -> V_6 . V_43 = F_14 ( V_299 ) ;
if ( ! V_1 -> V_6 . V_43 )
goto V_301;
V_1 -> V_6 . V_44 = F_14 ( V_299 ) ;
if ( ! V_1 -> V_6 . V_44 )
goto V_302;
V_1 -> V_6 . V_7 = ( ( V_299 / sizeof( struct V_10 ) ) - 1 ) ;
V_1 -> V_6 . V_137 = 0 ;
F_170 ( & V_1 -> V_6 . V_28 , F_11 ) ;
F_171 ( & V_1 -> V_6 . V_82 ) ;
F_170 ( & V_1 -> V_6 . V_79 , F_39 ) ;
F_61 ( & V_1 -> V_6 . V_41 ) ;
return 0 ;
V_302:
F_15 ( V_1 -> V_6 . V_43 , V_299 ) ;
V_301:
F_15 ( V_1 -> V_6 . V_42 , V_299 ) ;
V_300:
return - V_180 ;
}
void F_172 ( struct V_1 * V_1 )
{
struct V_138 V_139 ;
unsigned int V_299 ;
F_173 ( & V_1 -> V_6 . V_28 ) ;
V_139 . V_140 = V_303 ;
V_139 . V_141 = ( unsigned int ) - 1 ;
V_139 . V_142 = 0 ;
F_73 ( V_1 , V_202 , & V_139 ) ;
F_173 ( & V_1 -> V_6 . V_79 ) ;
F_63 ( ! F_130 ( & V_1 -> V_6 . V_183 ) ) ;
V_299 = ( V_1 -> V_6 . V_7 + 1 ) * sizeof( struct V_10 ) ;
F_63 ( ! F_174 ( V_1 -> V_6 . V_44 ) ) ;
F_15 ( V_1 -> V_6 . V_44 , V_299 ) ;
F_63 ( ! F_174 ( V_1 -> V_6 . V_43 ) ) ;
F_15 ( V_1 -> V_6 . V_43 , V_299 ) ;
F_63 ( ! F_174 ( V_1 -> V_6 . V_42 ) ) ;
F_15 ( V_1 -> V_6 . V_42 , V_299 ) ;
}
static void F_175 ( struct V_18 * V_19 ,
struct V_304 * V_305 )
{
struct V_306 * V_307 = V_19 -> V_181 ;
T_2 V_8 = F_176 ( V_19 -> V_21 . V_8 ) ;
if ( V_307 )
F_177 ( V_305 , L_3 ,
V_307 -> V_308 , V_307 -> V_309 , V_307 -> V_310 ) ;
switch ( V_19 -> V_22 . V_5 ) {
case V_194 :
F_177 ( V_305 , L_4 ,
& V_19 -> V_22 . V_3 . V_195 , & V_19 -> V_21 . V_2 . V_195 ) ;
break;
case V_198 :
F_177 ( V_305 , L_5 ,
V_19 -> V_22 . V_3 . V_200 , V_19 -> V_21 . V_2 . V_200 ) ;
break;
}
F_177 ( V_305 , L_6 , V_8 , V_8 ) ;
}
static void F_178 ( struct V_311 * V_312 , T_9 V_5 ,
struct V_304 * V_305 )
{
const struct V_313 * V_314 ;
const struct V_315 * V_316 ;
switch ( V_5 ) {
case V_194 :
V_314 = F_179 ( V_312 ) ;
F_177 ( V_305 , L_4 ,
& V_314 -> V_3 , & V_314 -> V_2 ) ;
break;
case V_198 :
V_316 = F_180 ( V_312 ) ;
F_177 ( V_305 ,
L_7 ,
& V_316 -> V_3 , & V_316 -> V_2 ,
V_316 -> V_317 [ 0 ] & 0x0f ,
V_316 -> V_317 [ 1 ] ,
V_316 -> V_317 [ 2 ] ) ;
break;
}
}
void F_181 ( struct V_18 * V_19 , int V_318 ,
T_10 V_319 , unsigned int V_141 , T_2 V_142 )
{
struct V_304 * V_305 ;
V_305 = F_182 ( L_8 ) ;
if ( V_305 == NULL )
return;
F_183 ( V_319 , V_141 , V_142 , V_305 ) ;
F_175 ( V_19 , V_305 ) ;
F_177 ( V_305 , L_9 , V_318 ) ;
F_184 ( V_305 ) ;
}
void F_49 ( struct V_18 * V_19 , int V_318 ,
T_10 V_319 , unsigned int V_141 , T_2 V_142 )
{
struct V_304 * V_305 ;
V_305 = F_182 ( L_10 ) ;
if ( V_305 == NULL )
return;
F_183 ( V_319 , V_141 , V_142 , V_305 ) ;
F_175 ( V_19 , V_305 ) ;
F_177 ( V_305 , L_9 , V_318 ) ;
F_184 ( V_305 ) ;
}
void F_185 ( struct V_18 * V_19 ,
struct V_311 * V_312 )
{
struct V_304 * V_305 ;
T_2 V_8 ;
V_305 = F_182 ( L_11 ) ;
if ( V_305 == NULL )
return;
F_178 ( V_312 , V_19 -> V_22 . V_5 , V_305 ) ;
V_8 = F_176 ( V_19 -> V_21 . V_8 ) ;
F_177 ( V_305 , L_6 , V_8 , V_8 ) ;
F_184 ( V_305 ) ;
}
void F_186 ( struct V_18 * V_19 ,
struct V_311 * V_312 , T_3 V_320 )
{
struct V_304 * V_305 ;
T_2 V_8 ;
V_305 = F_182 ( L_12 ) ;
if ( V_305 == NULL )
return;
F_178 ( V_312 , V_19 -> V_22 . V_5 , V_305 ) ;
V_8 = F_176 ( V_19 -> V_21 . V_8 ) ;
F_177 ( V_305 , L_13 ,
V_8 , V_8 , F_176 ( V_320 ) ) ;
F_184 ( V_305 ) ;
}
void F_187 ( struct V_311 * V_312 , T_9 V_5 )
{
struct V_304 * V_305 ;
V_305 = F_182 ( L_14 ) ;
if ( V_305 == NULL )
return;
F_178 ( V_312 , V_5 , V_305 ) ;
F_184 ( V_305 ) ;
}
void F_188 ( struct V_311 * V_312 , T_9 V_5 ,
T_3 V_321 , T_3 V_320 )
{
struct V_304 * V_305 ;
T_2 V_8 ;
V_305 = F_182 ( L_14 ) ;
if ( V_305 == NULL )
return;
F_178 ( V_312 , V_5 , V_305 ) ;
V_8 = F_176 ( V_321 ) ;
F_177 ( V_305 , L_13 ,
V_8 , V_8 , F_176 ( V_320 ) ) ;
F_184 ( V_305 ) ;
}
void F_189 ( struct V_18 * V_19 ,
struct V_311 * V_312 , T_4 V_9 )
{
struct V_304 * V_305 ;
T_3 V_321 ;
T_3 V_320 ;
V_305 = F_182 ( L_15 ) ;
if ( V_305 == NULL )
return;
F_178 ( V_312 , V_19 -> V_22 . V_5 , V_305 ) ;
if ( F_190 ( V_312 , V_9 , & V_321 , & V_320 ) == 0 ) {
T_2 V_8 = F_176 ( V_321 ) ;
F_177 ( V_305 , L_13 ,
V_8 , V_8 , F_176 ( V_320 ) ) ;
}
F_184 ( V_305 ) ;
}
