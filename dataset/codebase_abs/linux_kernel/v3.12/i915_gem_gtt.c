static T_1 F_1 ( T_2 V_1 ,
enum V_2 V_3 ,
bool V_4 )
{
T_1 V_5 = V_4 ? V_6 : 0 ;
V_5 |= F_2 ( V_1 ) ;
switch ( V_3 ) {
case V_7 :
case V_8 :
V_5 |= V_9 ;
break;
case V_10 :
V_5 |= V_11 ;
break;
default:
F_3 ( 1 ) ;
}
return V_5 ;
}
static T_1 F_4 ( T_2 V_1 ,
enum V_2 V_3 ,
bool V_4 )
{
T_1 V_5 = V_4 ? V_6 : 0 ;
V_5 |= F_2 ( V_1 ) ;
switch ( V_3 ) {
case V_7 :
V_5 |= V_12 ;
break;
case V_8 :
V_5 |= V_9 ;
break;
case V_10 :
V_5 |= V_11 ;
break;
default:
F_3 ( 1 ) ;
}
return V_5 ;
}
static T_1 F_5 ( T_2 V_1 ,
enum V_2 V_3 ,
bool V_4 )
{
T_1 V_5 = V_4 ? V_6 : 0 ;
V_5 |= F_2 ( V_1 ) ;
V_5 |= V_13 ;
if ( V_3 != V_10 )
V_5 |= V_14 ;
return V_5 ;
}
static T_1 F_6 ( T_2 V_1 ,
enum V_2 V_3 ,
bool V_4 )
{
T_1 V_5 = V_4 ? V_6 : 0 ;
V_5 |= F_7 ( V_1 ) ;
if ( V_3 != V_10 )
V_5 |= V_15 ;
return V_5 ;
}
static T_1 F_8 ( T_2 V_1 ,
enum V_2 V_3 ,
bool V_4 )
{
T_1 V_5 = V_4 ? V_6 : 0 ;
V_5 |= F_7 ( V_1 ) ;
switch ( V_3 ) {
case V_10 :
break;
case V_16 :
V_5 |= V_17 ;
break;
default:
V_5 |= V_18 ;
break;
}
return V_5 ;
}
static void F_9 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 . V_24 -> V_25 ;
T_1 T_3 * V_26 ;
T_4 V_27 ;
int V_28 ;
F_3 ( V_20 -> V_29 & 0x3f ) ;
V_26 = ( T_1 T_3 * ) V_22 -> V_30 . V_31 +
V_20 -> V_29 / sizeof( T_1 ) ;
for ( V_28 = 0 ; V_28 < V_20 -> V_32 ; V_28 ++ ) {
T_2 V_33 ;
V_33 = V_20 -> V_34 [ V_28 ] ;
V_27 = F_10 ( V_33 ) ;
V_27 |= V_35 ;
F_11 ( V_27 , V_26 + V_28 ) ;
}
F_12 ( V_26 ) ;
}
static int F_13 ( struct V_36 * V_24 )
{
T_5 * V_22 = V_24 -> V_25 ;
T_4 V_29 ;
struct V_37 * V_38 ;
struct V_19 * V_20 = V_22 -> V_39 . V_40 ;
int V_28 ;
F_14 ( V_20 -> V_29 & 0x3f ) ;
F_9 ( V_20 ) ;
V_29 = V_20 -> V_29 ;
V_29 /= 64 ;
V_29 <<= 16 ;
if ( F_15 ( V_24 ) -> V_41 == 6 ) {
T_4 V_42 , V_43 , V_44 ;
V_44 = F_16 ( V_45 ) ;
F_17 ( V_45 , V_44 | V_46 |
V_47 ) ;
V_43 = F_16 ( V_48 ) ;
F_17 ( V_48 , V_43 | V_49 ) ;
V_42 = F_16 ( V_50 ) ;
F_17 ( V_50 , V_42 | V_51 |
V_52 ) ;
F_17 ( V_53 , F_18 ( V_54 ) ) ;
} else if ( F_15 ( V_24 ) -> V_41 >= 7 ) {
T_4 V_42 , V_44 ;
V_44 = F_16 ( V_45 ) ;
F_17 ( V_45 , V_44 | V_47 ) ;
V_42 = F_16 ( V_50 ) ;
if ( F_19 ( V_24 ) ) {
V_42 |= V_55 ;
} else {
V_42 |= V_56 ;
V_42 &= ~ V_57 ;
}
F_17 ( V_50 , V_42 ) ;
}
F_20 (ring, dev_priv, i) {
if ( F_15 ( V_24 ) -> V_41 >= 7 )
F_17 ( F_21 ( V_38 ) ,
F_18 ( V_54 ) ) ;
F_17 ( F_22 ( V_38 ) , V_58 ) ;
F_17 ( F_23 ( V_38 ) , V_29 ) ;
}
return 0 ;
}
static void F_24 ( struct V_59 * V_60 ,
unsigned V_61 ,
unsigned V_62 ,
bool V_63 )
{
struct V_19 * V_20 =
F_25 ( V_60 , struct V_19 , V_23 ) ;
T_1 * V_64 , V_65 ;
unsigned V_66 = V_61 / V_67 ;
unsigned V_68 = V_61 % V_67 ;
unsigned V_69 , V_28 ;
V_65 = V_60 -> V_70 ( V_60 -> V_71 . V_1 , V_8 , true ) ;
while ( V_62 ) {
V_69 = V_68 + V_62 ;
if ( V_69 > V_67 )
V_69 = V_67 ;
V_64 = F_26 ( V_20 -> V_72 [ V_66 ] ) ;
for ( V_28 = V_68 ; V_28 < V_69 ; V_28 ++ )
V_64 [ V_28 ] = V_65 ;
F_27 ( V_64 ) ;
V_62 -= V_69 - V_68 ;
V_68 = 0 ;
V_66 ++ ;
}
}
static void F_28 ( struct V_59 * V_60 ,
struct V_73 * V_74 ,
unsigned V_61 ,
enum V_2 V_75 )
{
struct V_19 * V_20 =
F_25 ( V_60 , struct V_19 , V_23 ) ;
T_1 * V_64 ;
unsigned V_66 = V_61 / V_67 ;
unsigned V_76 = V_61 % V_67 ;
struct V_77 V_78 ;
V_64 = F_26 ( V_20 -> V_72 [ V_66 ] ) ;
F_29 (pages->sgl, &sg_iter, pages->nents, 0 ) {
T_2 V_79 ;
V_79 = F_30 ( & V_78 ) ;
V_64 [ V_76 ] = V_60 -> V_70 ( V_79 , V_75 , true ) ;
if ( ++ V_76 == V_67 ) {
F_27 ( V_64 ) ;
V_66 ++ ;
V_64 = F_26 ( V_20 -> V_72 [ V_66 ] ) ;
V_76 = 0 ;
}
}
F_27 ( V_64 ) ;
}
static void F_31 ( struct V_59 * V_60 )
{
struct V_19 * V_20 =
F_25 ( V_60 , struct V_19 , V_23 ) ;
int V_28 ;
F_32 ( & V_20 -> V_23 . V_39 ) ;
if ( V_20 -> V_34 ) {
for ( V_28 = 0 ; V_28 < V_20 -> V_32 ; V_28 ++ )
F_33 ( V_20 -> V_23 . V_24 -> V_80 ,
V_20 -> V_34 [ V_28 ] ,
4096 , V_81 ) ;
}
F_34 ( V_20 -> V_34 ) ;
for ( V_28 = 0 ; V_28 < V_20 -> V_32 ; V_28 ++ )
F_35 ( V_20 -> V_72 [ V_28 ] ) ;
F_34 ( V_20 -> V_72 ) ;
F_34 ( V_20 ) ;
}
static int F_36 ( struct V_19 * V_20 )
{
struct V_36 * V_24 = V_20 -> V_23 . V_24 ;
struct V_21 * V_22 = V_24 -> V_25 ;
unsigned V_82 ;
int V_28 ;
int V_83 = - V_84 ;
V_82 = F_37 ( V_22 -> V_30 ) ;
V_20 -> V_23 . V_70 = V_22 -> V_30 . V_23 . V_70 ;
V_20 -> V_32 = V_85 ;
V_20 -> V_86 = F_13 ;
V_20 -> V_23 . V_87 = F_24 ;
V_20 -> V_23 . V_88 = F_28 ;
V_20 -> V_23 . V_89 = F_31 ;
V_20 -> V_23 . V_71 = V_22 -> V_30 . V_23 . V_71 ;
V_20 -> V_72 = F_38 ( sizeof( struct V_90 * ) * V_20 -> V_32 ,
V_91 ) ;
if ( ! V_20 -> V_72 )
return - V_84 ;
for ( V_28 = 0 ; V_28 < V_20 -> V_32 ; V_28 ++ ) {
V_20 -> V_72 [ V_28 ] = F_39 ( V_91 ) ;
if ( ! V_20 -> V_72 [ V_28 ] )
goto V_92;
}
V_20 -> V_34 = F_38 ( sizeof( T_2 ) * V_20 -> V_32 ,
V_91 ) ;
if ( ! V_20 -> V_34 )
goto V_92;
for ( V_28 = 0 ; V_28 < V_20 -> V_32 ; V_28 ++ ) {
T_2 V_33 ;
V_33 = F_40 ( V_24 -> V_80 , V_20 -> V_72 [ V_28 ] , 0 , 4096 ,
V_81 ) ;
if ( F_41 ( V_24 -> V_80 , V_33 ) ) {
V_83 = - V_93 ;
goto V_94;
}
V_20 -> V_34 [ V_28 ] = V_33 ;
}
V_20 -> V_23 . V_87 ( & V_20 -> V_23 , 0 ,
V_20 -> V_32 * V_67 , true ) ;
V_20 -> V_29 = V_82 * sizeof( T_1 ) ;
return 0 ;
V_94:
if ( V_20 -> V_34 ) {
for ( V_28 -- ; V_28 >= 0 ; V_28 -- )
F_33 ( V_24 -> V_80 , V_20 -> V_34 [ V_28 ] ,
4096 , V_81 ) ;
}
V_92:
F_34 ( V_20 -> V_34 ) ;
for ( V_28 = 0 ; V_28 < V_20 -> V_32 ; V_28 ++ ) {
if ( V_20 -> V_72 [ V_28 ] )
F_35 ( V_20 -> V_72 [ V_28 ] ) ;
}
F_34 ( V_20 -> V_72 ) ;
return V_83 ;
}
static int F_42 ( struct V_36 * V_24 )
{
struct V_21 * V_22 = V_24 -> V_25 ;
struct V_19 * V_20 ;
int V_83 ;
V_20 = F_38 ( sizeof( * V_20 ) , V_91 ) ;
if ( ! V_20 )
return - V_84 ;
V_20 -> V_23 . V_24 = V_24 ;
if ( F_15 ( V_24 ) -> V_41 < 8 )
V_83 = F_36 ( V_20 ) ;
else
F_43 () ;
if ( V_83 )
F_34 ( V_20 ) ;
else {
V_22 -> V_39 . V_40 = V_20 ;
F_44 ( & V_20 -> V_23 . V_39 , V_20 -> V_23 . V_95 ,
V_20 -> V_23 . V_96 ) ;
}
return V_83 ;
}
void F_45 ( struct V_36 * V_24 )
{
struct V_21 * V_22 = V_24 -> V_25 ;
struct V_19 * V_20 = V_22 -> V_39 . V_40 ;
if ( ! V_20 )
return;
V_20 -> V_23 . V_89 ( & V_20 -> V_23 ) ;
V_22 -> V_39 . V_40 = NULL ;
}
void F_46 ( struct V_19 * V_20 ,
struct V_97 * V_98 ,
enum V_2 V_75 )
{
V_20 -> V_23 . V_88 ( & V_20 -> V_23 , V_98 -> V_74 ,
F_47 ( V_98 ) >> V_99 ,
V_75 ) ;
}
void F_48 ( struct V_19 * V_20 ,
struct V_97 * V_98 )
{
V_20 -> V_23 . V_87 ( & V_20 -> V_23 ,
F_47 ( V_98 ) >> V_99 ,
V_98 -> V_23 . V_100 >> V_99 ,
true ) ;
}
static inline bool F_49 ( struct V_36 * V_24 )
{
#ifdef F_50
if ( F_51 ( V_24 ) && F_52 ( V_24 ) && V_101 )
return true ;
#endif
return false ;
}
static bool F_53 ( struct V_21 * V_22 )
{
bool V_83 = V_22 -> V_39 . V_102 ;
if ( F_54 ( V_22 -> V_30 . V_103 ) ) {
V_22 -> V_39 . V_102 = false ;
if ( F_55 ( V_22 -> V_24 ) ) {
F_56 ( L_1 ) ;
F_57 ( 10 ) ;
}
}
return V_83 ;
}
static void F_58 ( struct V_21 * V_22 , bool V_102 )
{
if ( F_54 ( V_22 -> V_30 . V_103 ) )
V_22 -> V_39 . V_102 = V_102 ;
}
void F_59 ( struct V_36 * V_24 )
{
struct V_21 * V_22 = V_24 -> V_25 ;
struct V_37 * V_38 ;
int V_28 ;
if ( F_15 ( V_24 ) -> V_41 < 6 )
return;
F_20 (ring, dev_priv, i) {
T_6 V_104 ;
V_104 = F_16 ( F_60 ( V_38 ) ) ;
if ( V_104 & V_105 ) {
F_61 ( L_2
L_3
L_4
L_5
L_6 ,
V_104 & V_106 ,
V_104 & V_107 ? L_7 : L_8 ,
F_62 ( V_104 ) ,
F_63 ( V_104 ) ) ;
F_17 ( F_60 ( V_38 ) ,
V_104 & ~ V_105 ) ;
}
}
F_64 ( F_60 ( & V_22 -> V_38 [ V_108 ] ) ) ;
}
void F_65 ( struct V_36 * V_24 )
{
struct V_21 * V_22 = V_24 -> V_25 ;
if ( F_15 ( V_24 ) -> V_41 < 6 )
return;
F_59 ( V_24 ) ;
V_22 -> V_30 . V_23 . V_87 ( & V_22 -> V_30 . V_23 ,
V_22 -> V_30 . V_23 . V_95 / V_109 ,
V_22 -> V_30 . V_23 . V_96 / V_109 ,
false ) ;
}
void F_66 ( struct V_36 * V_24 )
{
struct V_21 * V_22 = V_24 -> V_25 ;
struct V_97 * V_98 ;
F_59 ( V_24 ) ;
V_22 -> V_30 . V_23 . V_87 ( & V_22 -> V_30 . V_23 ,
V_22 -> V_30 . V_23 . V_95 / V_109 ,
V_22 -> V_30 . V_23 . V_96 / V_109 ,
true ) ;
F_67 (obj, &dev_priv->mm.bound_list, global_list) {
F_68 ( V_98 , V_98 -> V_110 ) ;
F_69 ( V_98 , V_98 -> V_75 ) ;
}
F_70 ( V_24 ) ;
}
int F_71 ( struct V_97 * V_98 )
{
if ( V_98 -> V_111 )
return 0 ;
if ( ! F_72 ( & V_98 -> V_23 . V_24 -> V_80 -> V_24 ,
V_98 -> V_74 -> V_112 , V_98 -> V_74 -> V_113 ,
V_81 ) )
return - V_114 ;
return 0 ;
}
static void F_73 ( struct V_59 * V_60 ,
struct V_73 * V_115 ,
unsigned int V_61 ,
enum V_2 V_3 )
{
struct V_21 * V_22 = V_60 -> V_24 -> V_25 ;
T_1 T_3 * V_116 =
( T_1 T_3 * ) V_22 -> V_30 . V_31 + V_61 ;
int V_28 = 0 ;
struct V_77 V_78 ;
T_2 V_1 ;
F_29 (st->sgl, &sg_iter, st->nents, 0 ) {
V_1 = F_30 ( & V_78 ) ;
F_74 ( V_60 -> V_70 ( V_1 , V_3 , true ) , & V_116 [ V_28 ] ) ;
V_28 ++ ;
}
if ( V_28 != 0 )
F_3 ( F_12 ( & V_116 [ V_28 - 1 ] ) !=
V_60 -> V_70 ( V_1 , V_3 , true ) ) ;
F_17 ( V_117 , V_118 ) ;
F_64 ( V_117 ) ;
}
static void F_75 ( struct V_59 * V_60 ,
unsigned int V_61 ,
unsigned int V_62 ,
bool V_63 )
{
struct V_21 * V_22 = V_60 -> V_24 -> V_25 ;
T_1 V_65 , T_3 * V_119 =
( T_1 T_3 * ) V_22 -> V_30 . V_31 + V_61 ;
const int V_120 = F_37 ( V_22 -> V_30 ) - V_61 ;
int V_28 ;
if ( F_76 ( V_62 > V_120 ,
L_9 ,
V_61 , V_62 , V_120 ) )
V_62 = V_120 ;
V_65 = V_60 -> V_70 ( V_60 -> V_71 . V_1 , V_8 , V_63 ) ;
for ( V_28 = 0 ; V_28 < V_62 ; V_28 ++ )
F_74 ( V_65 , & V_119 [ V_28 ] ) ;
F_12 ( V_119 ) ;
}
static void F_77 ( struct V_59 * V_60 ,
struct V_73 * V_115 ,
unsigned int V_121 ,
enum V_2 V_75 )
{
unsigned int V_122 = ( V_75 == V_10 ) ?
V_123 : V_124 ;
F_78 ( V_115 , V_121 , V_122 ) ;
}
static void F_79 ( struct V_59 * V_60 ,
unsigned int V_61 ,
unsigned int V_62 ,
bool V_125 )
{
F_80 ( V_61 , V_62 ) ;
}
void F_69 ( struct V_97 * V_98 ,
enum V_2 V_75 )
{
struct V_36 * V_24 = V_98 -> V_23 . V_24 ;
struct V_21 * V_22 = V_24 -> V_25 ;
const unsigned long V_126 = F_47 ( V_98 ) >> V_99 ;
V_22 -> V_30 . V_23 . V_88 ( & V_22 -> V_30 . V_23 , V_98 -> V_74 ,
V_126 ,
V_75 ) ;
V_98 -> V_127 = 1 ;
}
void F_81 ( struct V_97 * V_98 )
{
struct V_36 * V_24 = V_98 -> V_23 . V_24 ;
struct V_21 * V_22 = V_24 -> V_25 ;
const unsigned long V_126 = F_47 ( V_98 ) >> V_99 ;
V_22 -> V_30 . V_23 . V_87 ( & V_22 -> V_30 . V_23 ,
V_126 ,
V_98 -> V_23 . V_100 >> V_99 ,
true ) ;
V_98 -> V_127 = 0 ;
}
void F_82 ( struct V_97 * V_98 )
{
struct V_36 * V_24 = V_98 -> V_23 . V_24 ;
struct V_21 * V_22 = V_24 -> V_25 ;
bool V_102 ;
V_102 = F_53 ( V_22 ) ;
if ( ! V_98 -> V_111 )
F_83 ( & V_24 -> V_80 -> V_24 ,
V_98 -> V_74 -> V_112 , V_98 -> V_74 -> V_113 ,
V_81 ) ;
F_58 ( V_22 , V_102 ) ;
}
static void F_84 ( struct V_128 * V_129 ,
unsigned long V_130 ,
unsigned long * V_95 ,
unsigned long * V_131 )
{
if ( V_129 -> V_130 != V_130 )
* V_95 += 4096 ;
if ( ! F_85 ( & V_129 -> V_132 ) ) {
V_129 = F_86 ( V_129 -> V_132 . V_133 ,
struct V_128 ,
V_132 ) ;
if ( V_129 -> V_134 && V_129 -> V_130 != V_130 )
* V_131 -= 4096 ;
}
}
void F_87 ( struct V_36 * V_24 ,
unsigned long V_95 ,
unsigned long V_135 ,
unsigned long V_131 )
{
struct V_21 * V_22 = V_24 -> V_25 ;
struct V_59 * V_136 = & V_22 -> V_30 . V_23 ;
struct V_128 * V_126 ;
struct V_97 * V_98 ;
unsigned long V_137 , V_138 ;
F_14 ( V_135 > V_131 ) ;
F_44 ( & V_136 -> V_39 , V_95 , V_131 - V_95 - V_109 ) ;
if ( ! F_88 ( V_24 ) )
V_22 -> V_30 . V_23 . V_39 . V_139 = F_84 ;
F_67 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_140 * V_141 = F_89 ( V_98 , V_136 ) ;
int V_83 ;
F_90 ( L_10 ,
F_47 ( V_98 ) , V_98 -> V_23 . V_100 ) ;
F_3 ( F_91 ( V_98 ) ) ;
V_83 = F_92 ( & V_136 -> V_39 , & V_141 -> V_129 ) ;
if ( V_83 )
F_90 ( L_11 ) ;
V_98 -> V_127 = 1 ;
F_93 ( & V_141 -> V_142 , & V_98 -> V_143 ) ;
}
V_22 -> V_30 . V_23 . V_95 = V_95 ;
V_22 -> V_30 . V_23 . V_96 = V_131 - V_95 ;
F_94 (entry, &ggtt_vm->mm, hole_start, hole_end) {
const unsigned long V_144 = ( V_138 - V_137 ) / V_109 ;
F_90 ( L_12 ,
V_137 , V_138 ) ;
V_136 -> V_87 ( V_136 , V_137 / V_109 , V_144 , true ) ;
}
V_136 -> V_87 ( V_136 , V_131 / V_109 - 1 , 1 , true ) ;
}
static bool
F_95 ( struct V_36 * V_24 )
{
if ( V_145 >= 0 )
return V_145 ;
#ifdef F_50
if ( F_15 ( V_24 ) -> V_41 == 6 && V_101 )
return false ;
#endif
return true ;
}
void F_96 ( struct V_36 * V_24 )
{
struct V_21 * V_22 = V_24 -> V_25 ;
unsigned long V_146 , V_147 ;
V_146 = V_22 -> V_30 . V_23 . V_96 ;
V_147 = V_22 -> V_30 . V_135 ;
if ( F_95 ( V_24 ) && F_97 ( V_24 ) ) {
int V_83 ;
if ( F_15 ( V_24 ) -> V_41 <= 7 ) {
V_146 -= V_85 * V_109 ;
}
F_87 ( V_24 , 0 , V_147 , V_146 ) ;
V_83 = F_42 ( V_24 ) ;
if ( ! V_83 )
return;
F_56 ( L_13 , V_83 ) ;
F_32 ( & V_22 -> V_30 . V_23 . V_39 ) ;
V_146 += V_85 * V_109 ;
}
F_87 ( V_24 , 0 , V_147 , V_146 ) ;
}
static int F_98 ( struct V_36 * V_24 )
{
struct V_21 * V_22 = V_24 -> V_25 ;
struct V_90 * V_90 ;
T_2 V_148 ;
V_90 = F_39 ( V_91 | V_149 | V_150 ) ;
if ( V_90 == NULL )
return - V_84 ;
F_99 ( V_90 ) ;
F_100 ( V_90 , 1 ) ;
#ifdef F_50
V_148 = F_40 ( V_24 -> V_80 , V_90 , 0 , V_109 ,
V_81 ) ;
if ( F_41 ( V_24 -> V_80 , V_148 ) )
return - V_151 ;
#else
V_148 = F_101 ( V_90 ) ;
#endif
V_22 -> V_30 . V_23 . V_71 . V_90 = V_90 ;
V_22 -> V_30 . V_23 . V_71 . V_1 = V_148 ;
return 0 ;
}
static void F_102 ( struct V_36 * V_24 )
{
struct V_21 * V_22 = V_24 -> V_25 ;
struct V_90 * V_90 = V_22 -> V_30 . V_23 . V_71 . V_90 ;
F_103 ( V_90 , 1 ) ;
F_33 ( V_24 -> V_80 , V_22 -> V_30 . V_23 . V_71 . V_1 ,
V_109 , V_81 ) ;
F_104 ( V_90 ) ;
F_35 ( V_90 ) ;
}
static inline unsigned int F_105 ( T_7 V_152 )
{
V_152 >>= V_153 ;
V_152 &= V_154 ;
return V_152 << 20 ;
}
static inline T_8 F_106 ( T_7 V_152 )
{
V_152 >>= V_155 ;
V_152 &= V_156 ;
return V_152 << 25 ;
}
static int F_107 ( struct V_36 * V_24 ,
T_8 * V_157 ,
T_8 * V_158 ,
T_9 * V_159 ,
unsigned long * V_135 )
{
struct V_21 * V_22 = V_24 -> V_25 ;
T_9 V_160 ;
unsigned int V_146 ;
T_7 V_152 ;
int V_83 ;
* V_159 = F_108 ( V_24 -> V_80 , 2 ) ;
* V_135 = F_109 ( V_24 -> V_80 , 2 ) ;
if ( ( * V_135 < ( 64 << 20 ) || ( * V_135 > ( 512 << 20 ) ) ) ) {
F_56 ( L_14 ,
V_22 -> V_30 . V_135 ) ;
return - V_161 ;
}
if ( ! F_110 ( V_24 -> V_80 , F_111 ( 40 ) ) )
F_112 ( V_24 -> V_80 , F_111 ( 40 ) ) ;
F_113 ( V_24 -> V_80 , V_162 , & V_152 ) ;
V_146 = F_105 ( V_152 ) ;
* V_158 = F_106 ( V_152 ) ;
* V_157 = ( V_146 / sizeof( T_1 ) ) << V_99 ;
V_160 = F_108 ( V_24 -> V_80 , 0 ) +
( F_109 ( V_24 -> V_80 , 0 ) / 2 ) ;
V_22 -> V_30 . V_31 = F_114 ( V_160 , V_146 ) ;
if ( ! V_22 -> V_30 . V_31 ) {
F_56 ( L_15 ) ;
return - V_84 ;
}
V_83 = F_98 ( V_24 ) ;
if ( V_83 )
F_56 ( L_16 ) ;
V_22 -> V_30 . V_23 . V_87 = F_75 ;
V_22 -> V_30 . V_23 . V_88 = F_73 ;
return V_83 ;
}
static void F_115 ( struct V_59 * V_60 )
{
struct V_163 * V_30 = F_25 ( V_60 , struct V_163 , V_23 ) ;
F_116 ( V_30 -> V_31 ) ;
F_102 ( V_60 -> V_24 ) ;
}
static int F_117 ( struct V_36 * V_24 ,
T_8 * V_157 ,
T_8 * V_158 ,
T_9 * V_159 ,
unsigned long * V_135 )
{
struct V_21 * V_22 = V_24 -> V_25 ;
int V_83 ;
V_83 = F_118 ( V_22 -> V_164 , V_22 -> V_24 -> V_80 , NULL ) ;
if ( ! V_83 ) {
F_56 ( L_17 ) ;
return - V_93 ;
}
F_119 ( V_157 , V_158 , V_159 , V_135 ) ;
V_22 -> V_30 . V_103 = F_49 ( V_22 -> V_24 ) ;
V_22 -> V_30 . V_23 . V_87 = F_79 ;
V_22 -> V_30 . V_23 . V_88 = F_77 ;
return 0 ;
}
static void F_120 ( struct V_59 * V_60 )
{
F_121 () ;
}
int F_122 ( struct V_36 * V_24 )
{
struct V_21 * V_22 = V_24 -> V_25 ;
struct V_163 * V_30 = & V_22 -> V_30 ;
int V_83 ;
if ( F_15 ( V_24 ) -> V_41 <= 5 ) {
V_30 -> V_165 = F_117 ;
V_30 -> V_23 . V_89 = F_120 ;
} else {
V_30 -> V_165 = F_107 ;
V_30 -> V_23 . V_89 = F_115 ;
if ( F_19 ( V_24 ) && V_22 -> V_166 )
V_30 -> V_23 . V_70 = F_8 ;
else if ( F_19 ( V_24 ) )
V_30 -> V_23 . V_70 = F_6 ;
else if ( F_123 ( V_24 ) )
V_30 -> V_23 . V_70 = F_5 ;
else if ( F_15 ( V_24 ) -> V_41 >= 7 )
V_30 -> V_23 . V_70 = F_4 ;
else
V_30 -> V_23 . V_70 = F_1 ;
}
V_83 = V_30 -> V_165 ( V_24 , & V_30 -> V_23 . V_96 , & V_30 -> V_167 ,
& V_30 -> V_159 , & V_30 -> V_135 ) ;
if ( V_83 )
return V_83 ;
V_30 -> V_23 . V_24 = V_24 ;
F_124 ( L_18 ,
V_30 -> V_23 . V_96 >> 20 ) ;
F_61 ( L_19 , V_30 -> V_135 >> 20 ) ;
F_61 ( L_20 , V_30 -> V_167 >> 20 ) ;
return 0 ;
}
