static inline T_1 F_1 ( T_2 V_1 ,
enum V_2 V_3 ,
bool V_4 )
{
T_1 V_5 = V_4 ? V_6 | V_7 : 0 ;
V_5 |= V_1 ;
if ( V_3 != V_8 )
V_5 |= V_9 ;
else
V_5 |= V_10 ;
return V_5 ;
}
static inline T_3 F_2 ( struct V_11 * V_12 ,
T_2 V_1 ,
enum V_2 V_3 )
{
T_3 V_13 = V_6 | V_7 ;
V_13 |= V_1 ;
if ( V_3 != V_8 )
V_13 |= V_14 ;
else
V_13 |= V_10 ;
return V_13 ;
}
static T_4 F_3 ( T_2 V_1 ,
enum V_2 V_3 ,
bool V_4 )
{
T_4 V_5 = V_4 ? V_15 : 0 ;
V_5 |= F_4 ( V_1 ) ;
switch ( V_3 ) {
case V_16 :
case V_17 :
V_5 |= V_18 ;
break;
case V_8 :
V_5 |= V_19 ;
break;
default:
F_5 ( 1 ) ;
}
return V_5 ;
}
static T_4 F_6 ( T_2 V_1 ,
enum V_2 V_3 ,
bool V_4 )
{
T_4 V_5 = V_4 ? V_15 : 0 ;
V_5 |= F_4 ( V_1 ) ;
switch ( V_3 ) {
case V_16 :
V_5 |= V_20 ;
break;
case V_17 :
V_5 |= V_18 ;
break;
case V_8 :
V_5 |= V_19 ;
break;
default:
F_5 ( 1 ) ;
}
return V_5 ;
}
static T_4 F_7 ( T_2 V_1 ,
enum V_2 V_3 ,
bool V_4 )
{
T_4 V_5 = V_4 ? V_15 : 0 ;
V_5 |= F_4 ( V_1 ) ;
V_5 |= V_21 ;
if ( V_3 != V_8 )
V_5 |= V_22 ;
return V_5 ;
}
static T_4 F_8 ( T_2 V_1 ,
enum V_2 V_3 ,
bool V_4 )
{
T_4 V_5 = V_4 ? V_15 : 0 ;
V_5 |= F_9 ( V_1 ) ;
if ( V_3 != V_8 )
V_5 |= V_23 ;
return V_5 ;
}
static T_4 F_10 ( T_2 V_1 ,
enum V_2 V_3 ,
bool V_4 )
{
T_4 V_5 = V_4 ? V_15 : 0 ;
V_5 |= F_9 ( V_1 ) ;
switch ( V_3 ) {
case V_8 :
break;
case V_24 :
V_5 |= V_25 ;
break;
default:
V_5 |= V_26 ;
break;
}
return V_5 ;
}
static int F_11 ( struct V_27 * V_28 , unsigned V_29 ,
T_5 V_30 )
{
int V_31 ;
F_12 ( V_29 >= 4 ) ;
V_31 = F_13 ( V_28 , 6 ) ;
if ( V_31 )
return V_31 ;
F_14 ( V_28 , F_15 ( 1 ) ) ;
F_14 ( V_28 , F_16 ( V_28 , V_29 ) ) ;
F_14 ( V_28 , ( V_32 ) ( V_30 >> 32 ) ) ;
F_14 ( V_28 , F_15 ( 1 ) ) ;
F_14 ( V_28 , F_17 ( V_28 , V_29 ) ) ;
F_14 ( V_28 , ( V_32 ) ( V_30 ) ) ;
F_18 ( V_28 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_27 * V_28 ;
struct V_36 * V_37 = V_34 -> V_38 . V_39 ;
int V_40 , V_41 , V_31 ;
int V_42 = V_37 -> V_43 / V_44 ;
F_20 (ring, dev_priv, j) {
F_21 ( F_22 ( V_28 ) ,
F_23 ( V_45 ) ) ;
}
for ( V_40 = V_42 - 1 ; V_40 >= 0 ; V_40 -- ) {
T_2 V_1 = V_37 -> V_46 [ V_40 ] ;
F_20 (ring, dev_priv, j) {
V_31 = F_11 ( V_28 , V_40 , V_1 ) ;
if ( V_31 )
return V_31 ;
}
}
return 0 ;
}
static void F_24 ( struct V_47 * V_48 ,
unsigned V_49 ,
unsigned V_50 ,
bool V_51 )
{
struct V_36 * V_37 =
F_25 ( V_48 , struct V_36 , V_52 ) ;
T_1 * V_53 , V_54 ;
unsigned V_55 = V_49 / V_56 ;
unsigned V_57 = V_49 % V_56 ;
unsigned V_58 , V_40 ;
V_54 = F_1 ( V_37 -> V_52 . V_59 . V_1 ,
V_17 , V_51 ) ;
while ( V_50 ) {
struct V_60 * V_61 = & V_37 -> V_62 [ V_55 ] ;
V_58 = V_57 + V_50 ;
if ( V_58 > V_56 )
V_58 = V_56 ;
V_53 = F_26 ( V_61 ) ;
for ( V_40 = V_57 ; V_40 < V_58 ; V_40 ++ )
V_53 [ V_40 ] = V_54 ;
F_27 ( V_53 ) ;
V_50 -= V_58 - V_57 ;
V_57 = 0 ;
V_55 ++ ;
}
}
static void F_28 ( struct V_47 * V_48 ,
struct V_63 * V_64 ,
unsigned V_49 ,
enum V_2 V_65 )
{
struct V_36 * V_37 =
F_25 ( V_48 , struct V_36 , V_52 ) ;
T_1 * V_53 ;
unsigned V_55 = V_49 / V_56 ;
unsigned V_66 = V_49 % V_56 ;
struct V_67 V_68 ;
V_53 = F_26 ( & V_37 -> V_62 [ V_55 ] ) ;
F_29 (pages->sgl, &sg_iter, pages->nents, 0 ) {
T_2 V_69 ;
V_69 = F_30 ( V_68 . V_70 ) +
( V_68 . V_71 << V_72 ) ;
V_53 [ V_66 ] = F_1 ( V_69 , V_65 ,
true ) ;
if ( ++ V_66 == V_56 ) {
F_27 ( V_53 ) ;
V_55 ++ ;
V_53 = F_26 ( & V_37 -> V_62 [ V_55 ] ) ;
V_66 = 0 ;
}
}
F_27 ( V_53 ) ;
}
static void F_31 ( struct V_47 * V_48 )
{
struct V_36 * V_37 =
F_25 ( V_48 , struct V_36 , V_52 ) ;
int V_40 , V_41 ;
for ( V_40 = 0 ; V_40 < V_37 -> V_73 ; V_40 ++ ) {
if ( V_37 -> V_46 [ V_40 ] ) {
F_32 ( V_37 -> V_52 . V_12 -> V_74 ,
V_37 -> V_46 [ V_40 ] ,
V_75 , V_76 ) ;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ ) {
T_2 V_1 = V_37 -> V_77 [ V_40 ] [ V_41 ] ;
if ( V_1 )
F_32 ( V_37 -> V_52 . V_12 -> V_74 ,
V_1 ,
V_75 ,
V_76 ) ;
}
}
F_33 ( V_37 -> V_77 [ V_40 ] ) ;
}
F_34 ( V_37 -> V_62 , F_35 ( V_37 -> V_78 << V_72 ) ) ;
F_34 ( V_37 -> V_79 , F_35 ( V_37 -> V_73 << V_72 ) ) ;
}
static int F_36 ( struct V_36 * V_37 , T_5 V_80 )
{
struct V_60 * V_81 ;
int V_40 , V_41 , V_31 = - V_82 ;
const int V_83 = F_37 ( V_80 , 1 << 30 ) ;
const int V_78 = V_44 * V_83 ;
if ( V_80 % ( 1 << 30 ) )
F_38 ( L_1 , V_80 ) ;
V_37 -> V_79 = F_39 ( V_84 , F_35 ( V_83 << V_72 ) ) ;
if ( ! V_37 -> V_79 )
return - V_82 ;
V_81 = F_39 ( V_84 , F_35 ( V_78 << V_72 ) ) ;
if ( ! V_81 ) {
F_34 ( V_37 -> V_79 , F_35 ( V_83 << V_72 ) ) ;
return - V_82 ;
}
V_37 -> V_62 = V_81 ;
V_37 -> V_73 = 1 << F_35 ( V_83 << V_72 ) ;
V_37 -> V_78 = 1 << F_35 ( V_78 << V_72 ) ;
V_37 -> V_43 = V_83 * V_44 ;
V_37 -> V_85 = F_19 ;
V_37 -> V_52 . V_86 = F_24 ;
V_37 -> V_52 . V_87 = F_28 ;
V_37 -> V_52 . V_88 = F_31 ;
F_12 ( V_37 -> V_73 > V_89 ) ;
for ( V_40 = 0 ; V_40 < V_83 ; V_40 ++ ) {
T_2 V_90 ;
V_90 = F_40 ( V_37 -> V_52 . V_12 -> V_74 ,
& V_37 -> V_79 [ V_40 ] , 0 ,
V_75 , V_76 ) ;
if ( F_41 ( V_37 -> V_52 . V_12 -> V_74 , V_90 ) )
goto V_91;
V_37 -> V_46 [ V_40 ] = V_90 ;
V_37 -> V_77 [ V_40 ] = F_42 ( sizeof( T_2 ) * V_44 , V_84 ) ;
if ( ! V_37 -> V_77 [ V_40 ] )
goto V_91;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ ) {
struct V_60 * V_92 = & V_81 [ V_40 * V_44 + V_41 ] ;
V_90 = F_40 ( V_37 -> V_52 . V_12 -> V_74 ,
V_92 , 0 , V_75 ,
V_76 ) ;
if ( F_41 ( V_37 -> V_52 . V_12 -> V_74 , V_90 ) )
goto V_91;
V_37 -> V_77 [ V_40 ] [ V_41 ] = V_90 ;
}
}
for ( V_40 = 0 ; V_40 < V_83 ; V_40 ++ ) {
T_3 * V_93 ;
V_93 = F_26 ( & V_37 -> V_79 [ V_40 ] ) ;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ ) {
T_2 V_1 = V_37 -> V_77 [ V_40 ] [ V_41 ] ;
V_93 [ V_41 ] = F_2 ( V_37 -> V_52 . V_12 , V_1 ,
V_17 ) ;
}
F_27 ( V_93 ) ;
}
V_37 -> V_52 . V_86 ( & V_37 -> V_52 , 0 ,
V_37 -> V_43 * V_56 ,
true ) ;
F_43 ( L_2 ,
V_37 -> V_73 , V_37 -> V_73 - V_83 ) ;
F_43 ( L_3 ,
V_37 -> V_78 ,
( V_37 -> V_78 - V_78 ) +
V_80 % ( 1 << 30 ) ) ;
return 0 ;
V_91:
V_37 -> V_52 . V_88 ( & V_37 -> V_52 ) ;
return V_31 ;
}
static void F_44 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = V_37 -> V_52 . V_12 -> V_35 ;
T_4 T_6 * V_94 ;
T_7 V_95 ;
int V_40 ;
F_5 ( V_37 -> V_96 & 0x3f ) ;
V_94 = ( T_4 T_6 * ) V_34 -> V_97 . V_98 +
V_37 -> V_96 / sizeof( T_4 ) ;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ ) {
T_2 V_99 ;
V_99 = V_37 -> V_100 [ V_40 ] ;
V_95 = F_45 ( V_99 ) ;
V_95 |= V_101 ;
F_46 ( V_95 , V_94 + V_40 ) ;
}
F_47 ( V_94 ) ;
}
static int F_48 ( struct V_11 * V_12 )
{
T_8 * V_34 = V_12 -> V_35 ;
T_7 V_96 ;
struct V_27 * V_28 ;
struct V_36 * V_37 = V_34 -> V_38 . V_39 ;
int V_40 ;
F_12 ( V_37 -> V_96 & 0x3f ) ;
F_44 ( V_37 ) ;
V_96 = V_37 -> V_96 ;
V_96 /= 64 ;
V_96 <<= 16 ;
if ( F_49 ( V_12 ) -> V_102 == 6 ) {
T_7 V_103 , V_104 , V_105 ;
V_105 = F_50 ( V_106 ) ;
F_21 ( V_106 , V_105 | V_107 |
V_108 ) ;
V_104 = F_50 ( V_109 ) ;
F_21 ( V_109 , V_104 | V_110 ) ;
V_103 = F_50 ( V_111 ) ;
F_21 ( V_111 , V_103 | V_112 |
V_113 ) ;
F_21 ( V_114 , F_23 ( V_45 ) ) ;
} else if ( F_49 ( V_12 ) -> V_102 >= 7 ) {
T_7 V_103 , V_105 ;
V_105 = F_50 ( V_106 ) ;
F_21 ( V_106 , V_105 | V_108 ) ;
V_103 = F_50 ( V_111 ) ;
if ( F_51 ( V_12 ) ) {
V_103 |= V_115 ;
} else {
V_103 |= V_116 ;
V_103 &= ~ V_117 ;
}
F_21 ( V_111 , V_103 ) ;
}
F_20 (ring, dev_priv, i) {
if ( F_49 ( V_12 ) -> V_102 >= 7 )
F_21 ( F_22 ( V_28 ) ,
F_23 ( V_45 ) ) ;
F_21 ( F_52 ( V_28 ) , V_118 ) ;
F_21 ( F_53 ( V_28 ) , V_96 ) ;
}
return 0 ;
}
static void F_54 ( struct V_47 * V_48 ,
unsigned V_49 ,
unsigned V_50 ,
bool V_51 )
{
struct V_36 * V_37 =
F_25 ( V_48 , struct V_36 , V_52 ) ;
T_4 * V_53 , V_54 ;
unsigned V_55 = V_49 / V_119 ;
unsigned V_57 = V_49 % V_119 ;
unsigned V_58 , V_40 ;
V_54 = V_48 -> V_120 ( V_48 -> V_59 . V_1 , V_17 , true ) ;
while ( V_50 ) {
V_58 = V_57 + V_50 ;
if ( V_58 > V_119 )
V_58 = V_119 ;
V_53 = F_26 ( V_37 -> V_81 [ V_55 ] ) ;
for ( V_40 = V_57 ; V_40 < V_58 ; V_40 ++ )
V_53 [ V_40 ] = V_54 ;
F_27 ( V_53 ) ;
V_50 -= V_58 - V_57 ;
V_57 = 0 ;
V_55 ++ ;
}
}
static void F_55 ( struct V_47 * V_48 ,
struct V_63 * V_64 ,
unsigned V_49 ,
enum V_2 V_65 )
{
struct V_36 * V_37 =
F_25 ( V_48 , struct V_36 , V_52 ) ;
T_4 * V_53 ;
unsigned V_55 = V_49 / V_119 ;
unsigned V_66 = V_49 % V_119 ;
struct V_67 V_68 ;
V_53 = F_26 ( V_37 -> V_81 [ V_55 ] ) ;
F_29 (pages->sgl, &sg_iter, pages->nents, 0 ) {
T_2 V_69 ;
V_69 = F_56 ( & V_68 ) ;
V_53 [ V_66 ] = V_48 -> V_120 ( V_69 , V_65 , true ) ;
if ( ++ V_66 == V_119 ) {
F_27 ( V_53 ) ;
V_55 ++ ;
V_53 = F_26 ( V_37 -> V_81 [ V_55 ] ) ;
V_66 = 0 ;
}
}
F_27 ( V_53 ) ;
}
static void F_57 ( struct V_47 * V_48 )
{
struct V_36 * V_37 =
F_25 ( V_48 , struct V_36 , V_52 ) ;
int V_40 ;
F_58 ( & V_37 -> V_52 . V_38 ) ;
if ( V_37 -> V_100 ) {
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ )
F_32 ( V_37 -> V_52 . V_12 -> V_74 ,
V_37 -> V_100 [ V_40 ] ,
4096 , V_76 ) ;
}
F_33 ( V_37 -> V_100 ) ;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ )
F_59 ( V_37 -> V_81 [ V_40 ] ) ;
F_33 ( V_37 -> V_81 ) ;
F_33 ( V_37 ) ;
}
static int F_60 ( struct V_36 * V_37 )
{
struct V_11 * V_12 = V_37 -> V_52 . V_12 ;
struct V_33 * V_34 = V_12 -> V_35 ;
unsigned V_121 ;
int V_40 ;
int V_31 = - V_82 ;
V_121 = F_61 ( V_34 -> V_97 ) ;
V_37 -> V_52 . V_120 = V_34 -> V_97 . V_52 . V_120 ;
V_37 -> V_43 = V_122 ;
V_37 -> V_85 = F_48 ;
V_37 -> V_52 . V_86 = F_54 ;
V_37 -> V_52 . V_87 = F_55 ;
V_37 -> V_52 . V_88 = F_57 ;
V_37 -> V_52 . V_59 = V_34 -> V_97 . V_52 . V_59 ;
V_37 -> V_81 = F_62 ( V_37 -> V_43 , sizeof( struct V_60 * ) ,
V_84 ) ;
if ( ! V_37 -> V_81 )
return - V_82 ;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ ) {
V_37 -> V_81 [ V_40 ] = F_63 ( V_84 ) ;
if ( ! V_37 -> V_81 [ V_40 ] )
goto V_123;
}
V_37 -> V_100 = F_62 ( V_37 -> V_43 , sizeof( T_2 ) ,
V_84 ) ;
if ( ! V_37 -> V_100 )
goto V_123;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ ) {
T_2 V_99 ;
V_99 = F_40 ( V_12 -> V_74 , V_37 -> V_81 [ V_40 ] , 0 , 4096 ,
V_76 ) ;
if ( F_41 ( V_12 -> V_74 , V_99 ) ) {
V_31 = - V_124 ;
goto V_125;
}
V_37 -> V_100 [ V_40 ] = V_99 ;
}
V_37 -> V_52 . V_86 ( & V_37 -> V_52 , 0 ,
V_37 -> V_43 * V_119 , true ) ;
V_37 -> V_96 = V_121 * sizeof( T_4 ) ;
return 0 ;
V_125:
if ( V_37 -> V_100 ) {
for ( V_40 -- ; V_40 >= 0 ; V_40 -- )
F_32 ( V_12 -> V_74 , V_37 -> V_100 [ V_40 ] ,
4096 , V_76 ) ;
}
V_123:
F_33 ( V_37 -> V_100 ) ;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ ) {
if ( V_37 -> V_81 [ V_40 ] )
F_59 ( V_37 -> V_81 [ V_40 ] ) ;
}
F_33 ( V_37 -> V_81 ) ;
return V_31 ;
}
static int F_64 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_36 * V_37 ;
int V_31 ;
V_37 = F_65 ( sizeof( * V_37 ) , V_84 ) ;
if ( ! V_37 )
return - V_82 ;
V_37 -> V_52 . V_12 = V_12 ;
if ( F_49 ( V_12 ) -> V_102 < 8 )
V_31 = F_60 ( V_37 ) ;
else if ( F_66 ( V_12 ) )
V_31 = F_36 ( V_37 , V_34 -> V_97 . V_52 . V_126 ) ;
else
F_67 () ;
if ( V_31 )
F_33 ( V_37 ) ;
else {
V_34 -> V_38 . V_39 = V_37 ;
F_68 ( & V_37 -> V_52 . V_38 , V_37 -> V_52 . V_127 ,
V_37 -> V_52 . V_126 ) ;
}
return V_31 ;
}
void F_69 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_36 * V_37 = V_34 -> V_38 . V_39 ;
if ( ! V_37 )
return;
V_37 -> V_52 . V_88 ( & V_37 -> V_52 ) ;
V_34 -> V_38 . V_39 = NULL ;
}
void F_70 ( struct V_36 * V_37 ,
struct V_128 * V_129 ,
enum V_2 V_65 )
{
V_37 -> V_52 . V_87 ( & V_37 -> V_52 , V_129 -> V_64 ,
F_71 ( V_129 ) >> V_72 ,
V_65 ) ;
}
void F_72 ( struct V_36 * V_37 ,
struct V_128 * V_129 )
{
V_37 -> V_52 . V_86 ( & V_37 -> V_52 ,
F_71 ( V_129 ) >> V_72 ,
V_129 -> V_52 . V_80 >> V_72 ,
true ) ;
}
static inline bool F_73 ( struct V_11 * V_12 )
{
#ifdef F_74
if ( F_75 ( V_12 ) && F_76 ( V_12 ) && V_130 )
return true ;
#endif
return false ;
}
static bool F_77 ( struct V_33 * V_34 )
{
bool V_31 = V_34 -> V_38 . V_131 ;
if ( F_78 ( V_34 -> V_97 . V_132 ) ) {
V_34 -> V_38 . V_131 = false ;
if ( F_79 ( V_34 -> V_12 ) ) {
F_80 ( L_4 ) ;
F_81 ( 10 ) ;
}
}
return V_31 ;
}
static void F_82 ( struct V_33 * V_34 , bool V_131 )
{
if ( F_78 ( V_34 -> V_97 . V_132 ) )
V_34 -> V_38 . V_131 = V_131 ;
}
void F_83 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_27 * V_28 ;
int V_40 ;
if ( F_49 ( V_12 ) -> V_102 < 6 )
return;
F_20 (ring, dev_priv, i) {
V_32 V_133 ;
V_133 = F_50 ( F_84 ( V_28 ) ) ;
if ( V_133 & V_134 ) {
F_43 ( L_5
L_6
L_7
L_8
L_9 ,
V_133 & V_135 ,
V_133 & V_136 ? L_10 : L_11 ,
F_85 ( V_133 ) ,
F_86 ( V_133 ) ) ;
F_21 ( F_84 ( V_28 ) ,
V_133 & ~ V_134 ) ;
}
}
F_87 ( F_84 ( & V_34 -> V_28 [ V_137 ] ) ) ;
}
void F_88 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
if ( F_49 ( V_12 ) -> V_102 < 6 )
return;
F_83 ( V_12 ) ;
V_34 -> V_97 . V_52 . V_86 ( & V_34 -> V_97 . V_52 ,
V_34 -> V_97 . V_52 . V_127 / V_75 ,
V_34 -> V_97 . V_52 . V_126 / V_75 ,
false ) ;
}
void F_89 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_128 * V_129 ;
F_83 ( V_12 ) ;
V_34 -> V_97 . V_52 . V_86 ( & V_34 -> V_97 . V_52 ,
V_34 -> V_97 . V_52 . V_127 / V_75 ,
V_34 -> V_97 . V_52 . V_126 / V_75 ,
true ) ;
F_90 (obj, &dev_priv->mm.bound_list, global_list) {
F_91 ( V_129 , V_129 -> V_138 ) ;
F_92 ( V_129 , V_129 -> V_65 ) ;
}
F_93 ( V_12 ) ;
}
int F_94 ( struct V_128 * V_129 )
{
if ( V_129 -> V_139 )
return 0 ;
if ( ! F_95 ( & V_129 -> V_52 . V_12 -> V_74 -> V_12 ,
V_129 -> V_64 -> V_140 , V_129 -> V_64 -> V_141 ,
V_76 ) )
return - V_142 ;
return 0 ;
}
static inline void F_96 ( void T_6 * V_1 , T_1 V_5 )
{
#ifdef F_97
F_97 ( V_5 , V_1 ) ;
#else
F_98 ( ( V_32 ) V_5 , V_1 ) ;
F_98 ( V_5 >> 32 , V_1 + 4 ) ;
#endif
}
static void F_99 ( struct V_47 * V_48 ,
struct V_63 * V_143 ,
unsigned int V_49 ,
enum V_2 V_3 )
{
struct V_33 * V_34 = V_48 -> V_12 -> V_35 ;
T_1 T_6 * V_144 =
( T_1 T_6 * ) V_34 -> V_97 . V_98 + V_49 ;
int V_40 = 0 ;
struct V_67 V_68 ;
T_2 V_1 ;
F_29 (st->sgl, &sg_iter, st->nents, 0 ) {
V_1 = F_30 ( V_68 . V_70 ) +
( V_68 . V_71 << V_72 ) ;
F_96 ( & V_144 [ V_40 ] ,
F_1 ( V_1 , V_3 , true ) ) ;
V_40 ++ ;
}
if ( V_40 != 0 )
F_5 ( F_100 ( & V_144 [ V_40 - 1 ] )
!= F_1 ( V_1 , V_3 , true ) ) ;
F_21 ( V_145 , V_146 ) ;
F_87 ( V_145 ) ;
}
static void F_101 ( struct V_47 * V_48 ,
struct V_63 * V_143 ,
unsigned int V_49 ,
enum V_2 V_3 )
{
struct V_33 * V_34 = V_48 -> V_12 -> V_35 ;
T_4 T_6 * V_144 =
( T_4 T_6 * ) V_34 -> V_97 . V_98 + V_49 ;
int V_40 = 0 ;
struct V_67 V_68 ;
T_2 V_1 ;
F_29 (st->sgl, &sg_iter, st->nents, 0 ) {
V_1 = F_56 ( & V_68 ) ;
F_98 ( V_48 -> V_120 ( V_1 , V_3 , true ) , & V_144 [ V_40 ] ) ;
V_40 ++ ;
}
if ( V_40 != 0 )
F_5 ( F_47 ( & V_144 [ V_40 - 1 ] ) !=
V_48 -> V_120 ( V_1 , V_3 , true ) ) ;
F_21 ( V_145 , V_146 ) ;
F_87 ( V_145 ) ;
}
static void F_102 ( struct V_47 * V_48 ,
unsigned int V_49 ,
unsigned int V_50 ,
bool V_51 )
{
struct V_33 * V_34 = V_48 -> V_12 -> V_35 ;
T_1 V_54 , T_6 * V_147 =
( T_1 T_6 * ) V_34 -> V_97 . V_98 + V_49 ;
const int V_148 = F_61 ( V_34 -> V_97 ) - V_49 ;
int V_40 ;
if ( F_103 ( V_50 > V_148 ,
L_12 ,
V_49 , V_50 , V_148 ) )
V_50 = V_148 ;
V_54 = F_1 ( V_48 -> V_59 . V_1 ,
V_17 ,
V_51 ) ;
for ( V_40 = 0 ; V_40 < V_50 ; V_40 ++ )
F_96 ( & V_147 [ V_40 ] , V_54 ) ;
F_47 ( V_147 ) ;
}
static void F_104 ( struct V_47 * V_48 ,
unsigned int V_49 ,
unsigned int V_50 ,
bool V_51 )
{
struct V_33 * V_34 = V_48 -> V_12 -> V_35 ;
T_4 V_54 , T_6 * V_147 =
( T_4 T_6 * ) V_34 -> V_97 . V_98 + V_49 ;
const int V_148 = F_61 ( V_34 -> V_97 ) - V_49 ;
int V_40 ;
if ( F_103 ( V_50 > V_148 ,
L_12 ,
V_49 , V_50 , V_148 ) )
V_50 = V_148 ;
V_54 = V_48 -> V_120 ( V_48 -> V_59 . V_1 , V_17 , V_51 ) ;
for ( V_40 = 0 ; V_40 < V_50 ; V_40 ++ )
F_98 ( V_54 , & V_147 [ V_40 ] ) ;
F_47 ( V_147 ) ;
}
static void F_105 ( struct V_47 * V_48 ,
struct V_63 * V_143 ,
unsigned int V_149 ,
enum V_2 V_65 )
{
unsigned int V_150 = ( V_65 == V_8 ) ?
V_151 : V_152 ;
F_106 ( V_143 , V_149 , V_150 ) ;
}
static void F_107 ( struct V_47 * V_48 ,
unsigned int V_49 ,
unsigned int V_50 ,
bool V_153 )
{
F_108 ( V_49 , V_50 ) ;
}
void F_92 ( struct V_128 * V_129 ,
enum V_2 V_65 )
{
struct V_11 * V_12 = V_129 -> V_52 . V_12 ;
struct V_33 * V_34 = V_12 -> V_35 ;
const unsigned long V_29 = F_71 ( V_129 ) >> V_72 ;
V_34 -> V_97 . V_52 . V_87 ( & V_34 -> V_97 . V_52 , V_129 -> V_64 ,
V_29 ,
V_65 ) ;
V_129 -> V_154 = 1 ;
}
void F_109 ( struct V_128 * V_129 )
{
struct V_11 * V_12 = V_129 -> V_52 . V_12 ;
struct V_33 * V_34 = V_12 -> V_35 ;
const unsigned long V_29 = F_71 ( V_129 ) >> V_72 ;
V_34 -> V_97 . V_52 . V_86 ( & V_34 -> V_97 . V_52 ,
V_29 ,
V_129 -> V_52 . V_80 >> V_72 ,
true ) ;
V_129 -> V_154 = 0 ;
}
void F_110 ( struct V_128 * V_129 )
{
struct V_11 * V_12 = V_129 -> V_52 . V_12 ;
struct V_33 * V_34 = V_12 -> V_35 ;
bool V_131 ;
V_131 = F_77 ( V_34 ) ;
if ( ! V_129 -> V_139 )
F_111 ( & V_12 -> V_74 -> V_12 ,
V_129 -> V_64 -> V_140 , V_129 -> V_64 -> V_141 ,
V_76 ) ;
F_82 ( V_34 , V_131 ) ;
}
static void F_112 ( struct V_155 * V_156 ,
unsigned long V_157 ,
unsigned long * V_127 ,
unsigned long * V_158 )
{
if ( V_156 -> V_157 != V_157 )
* V_127 += 4096 ;
if ( ! F_113 ( & V_156 -> V_159 ) ) {
V_156 = F_114 ( V_156 -> V_159 . V_160 ,
struct V_155 ,
V_159 ) ;
if ( V_156 -> V_161 && V_156 -> V_157 != V_157 )
* V_158 -= 4096 ;
}
}
void F_115 ( struct V_11 * V_12 ,
unsigned long V_127 ,
unsigned long V_162 ,
unsigned long V_158 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_47 * V_163 = & V_34 -> V_97 . V_52 ;
struct V_155 * V_29 ;
struct V_128 * V_129 ;
unsigned long V_164 , V_165 ;
F_12 ( V_162 > V_158 ) ;
F_68 ( & V_163 -> V_38 , V_127 , V_158 - V_127 - V_75 ) ;
if ( ! F_116 ( V_12 ) )
V_34 -> V_97 . V_52 . V_38 . V_166 = F_112 ;
F_90 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_167 * V_168 = F_117 ( V_129 , V_163 ) ;
int V_31 ;
F_118 ( L_13 ,
F_71 ( V_129 ) , V_129 -> V_52 . V_80 ) ;
F_5 ( F_119 ( V_129 ) ) ;
V_31 = F_120 ( & V_163 -> V_38 , & V_168 -> V_156 ) ;
if ( V_31 )
F_118 ( L_14 ) ;
V_129 -> V_154 = 1 ;
F_121 ( & V_168 -> V_169 , & V_129 -> V_170 ) ;
}
V_34 -> V_97 . V_52 . V_127 = V_127 ;
V_34 -> V_97 . V_52 . V_126 = V_158 - V_127 ;
F_122 (entry, &ggtt_vm->mm, hole_start, hole_end) {
const unsigned long V_171 = ( V_165 - V_164 ) / V_75 ;
F_118 ( L_15 ,
V_164 , V_165 ) ;
V_163 -> V_86 ( V_163 , V_164 / V_75 , V_171 , true ) ;
}
V_163 -> V_86 ( V_163 , V_158 / V_75 - 1 , 1 , true ) ;
}
static bool
F_123 ( struct V_11 * V_12 )
{
if ( V_172 >= 0 )
return V_172 ;
#ifdef F_74
if ( F_49 ( V_12 ) -> V_102 == 6 && V_130 )
return false ;
#endif
return true ;
}
void F_124 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
unsigned long V_173 , V_174 ;
V_173 = V_34 -> V_97 . V_52 . V_126 ;
V_174 = V_34 -> V_97 . V_162 ;
if ( F_123 ( V_12 ) && F_125 ( V_12 ) ) {
int V_31 ;
if ( F_49 ( V_12 ) -> V_102 <= 7 ) {
V_173 -= V_122 * V_75 ;
}
F_115 ( V_12 , 0 , V_174 , V_173 ) ;
V_31 = F_64 ( V_12 ) ;
if ( ! V_31 )
return;
F_80 ( L_16 , V_31 ) ;
F_58 ( & V_34 -> V_97 . V_52 . V_38 ) ;
if ( F_49 ( V_12 ) -> V_102 < 8 )
V_173 += V_122 * V_75 ;
}
F_115 ( V_12 , 0 , V_174 , V_173 ) ;
}
static int F_126 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_60 * V_60 ;
T_2 V_175 ;
V_60 = F_63 ( V_84 | V_176 | V_177 ) ;
if ( V_60 == NULL )
return - V_82 ;
F_127 ( V_60 ) ;
F_128 ( V_60 , 1 ) ;
#ifdef F_74
V_175 = F_40 ( V_12 -> V_74 , V_60 , 0 , V_75 ,
V_76 ) ;
if ( F_41 ( V_12 -> V_74 , V_175 ) )
return - V_178 ;
#else
V_175 = F_129 ( V_60 ) ;
#endif
V_34 -> V_97 . V_52 . V_59 . V_60 = V_60 ;
V_34 -> V_97 . V_52 . V_59 . V_1 = V_175 ;
return 0 ;
}
static void F_130 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_60 * V_60 = V_34 -> V_97 . V_52 . V_59 . V_60 ;
F_131 ( V_60 , 1 ) ;
F_32 ( V_12 -> V_74 , V_34 -> V_97 . V_52 . V_59 . V_1 ,
V_75 , V_76 ) ;
F_132 ( V_60 ) ;
F_59 ( V_60 ) ;
}
static inline unsigned int F_133 ( T_9 V_179 )
{
V_179 >>= V_180 ;
V_179 &= V_181 ;
return V_179 << 20 ;
}
static inline unsigned int F_134 ( T_9 V_182 )
{
V_182 >>= V_183 ;
V_182 &= V_184 ;
if ( V_182 )
V_182 = 1 << V_182 ;
if ( V_182 > 4 ) {
F_5 ( ! V_185 ) ;
return 4 << 20 ;
}
return V_182 << 20 ;
}
static inline T_10 F_135 ( T_9 V_179 )
{
V_179 >>= V_186 ;
V_179 &= V_187 ;
return V_179 << 25 ;
}
static inline T_10 F_136 ( T_9 V_182 )
{
V_182 >>= V_188 ;
V_182 &= V_189 ;
return V_182 << 25 ;
}
static int F_137 ( struct V_11 * V_12 ,
T_10 V_173 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
T_11 V_190 ;
int V_31 ;
V_190 = F_138 ( V_12 -> V_74 , 0 ) +
( F_139 ( V_12 -> V_74 , 0 ) / 2 ) ;
V_34 -> V_97 . V_98 = F_140 ( V_190 , V_173 ) ;
if ( ! V_34 -> V_97 . V_98 ) {
F_80 ( L_17 ) ;
return - V_82 ;
}
V_31 = F_126 ( V_12 ) ;
if ( V_31 ) {
F_80 ( L_18 ) ;
F_141 ( V_34 -> V_97 . V_98 ) ;
}
return V_31 ;
}
static void F_142 ( struct V_33 * V_34 )
{
#define F_143 (0<<0)
#define F_144 (1<<0)
#define F_145 (2<<0)
#define F_146 (3<<0)
#define F_147 (0<<2)
#define F_148 (1<<2)
#define F_149 (2<<2)
#define F_150 (3<<2)
#define F_151 ( T_12 ) (x<<4)
#define F_152 ( V_40 , T_12 ) ((uint64_t) (x) << ((i) * 8))
T_5 V_191 ;
V_191 = F_152 ( 0 , F_146 | F_148 ) |
F_152 ( 1 , F_144 | F_149 ) |
F_152 ( 2 , F_145 | F_149 ) |
F_152 ( 3 , F_143 ) |
F_152 ( 4 , F_146 | F_149 | F_151 ( 0 ) ) |
F_152 ( 5 , F_146 | F_149 | F_151 ( 1 ) ) |
F_152 ( 6 , F_146 | F_149 | F_151 ( 2 ) ) |
F_152 ( 7 , F_146 | F_149 | F_151 ( 3 ) ) ;
F_21 ( V_192 , V_191 ) ;
F_21 ( V_192 + 4 , V_191 >> 32 ) ;
}
static int F_153 ( struct V_11 * V_12 ,
T_10 * V_193 ,
T_10 * V_194 ,
T_11 * V_195 ,
unsigned long * V_162 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
unsigned int V_173 ;
T_9 V_179 ;
int V_31 ;
* V_195 = F_138 ( V_12 -> V_74 , 2 ) ;
* V_162 = F_139 ( V_12 -> V_74 , 2 ) ;
if ( ! F_154 ( V_12 -> V_74 , F_155 ( 39 ) ) )
F_156 ( V_12 -> V_74 , F_155 ( 39 ) ) ;
F_157 ( V_12 -> V_74 , V_196 , & V_179 ) ;
* V_194 = F_136 ( V_179 ) ;
V_173 = F_134 ( V_179 ) ;
* V_193 = ( V_173 / sizeof( T_1 ) ) << V_72 ;
F_142 ( V_34 ) ;
V_31 = F_137 ( V_12 , V_173 ) ;
V_34 -> V_97 . V_52 . V_86 = F_102 ;
V_34 -> V_97 . V_52 . V_87 = F_99 ;
return V_31 ;
}
static int F_158 ( struct V_11 * V_12 ,
T_10 * V_193 ,
T_10 * V_194 ,
T_11 * V_195 ,
unsigned long * V_162 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
unsigned int V_173 ;
T_9 V_179 ;
int V_31 ;
* V_195 = F_138 ( V_12 -> V_74 , 2 ) ;
* V_162 = F_139 ( V_12 -> V_74 , 2 ) ;
if ( ( * V_162 < ( 64 << 20 ) || ( * V_162 > ( 512 << 20 ) ) ) ) {
F_80 ( L_19 ,
V_34 -> V_97 . V_162 ) ;
return - V_197 ;
}
if ( ! F_154 ( V_12 -> V_74 , F_155 ( 40 ) ) )
F_156 ( V_12 -> V_74 , F_155 ( 40 ) ) ;
F_157 ( V_12 -> V_74 , V_196 , & V_179 ) ;
* V_194 = F_135 ( V_179 ) ;
V_173 = F_133 ( V_179 ) ;
* V_193 = ( V_173 / sizeof( T_4 ) ) << V_72 ;
V_31 = F_137 ( V_12 , V_173 ) ;
V_34 -> V_97 . V_52 . V_86 = F_104 ;
V_34 -> V_97 . V_52 . V_87 = F_101 ;
return V_31 ;
}
static void F_159 ( struct V_47 * V_48 )
{
struct V_198 * V_97 = F_25 ( V_48 , struct V_198 , V_52 ) ;
F_141 ( V_97 -> V_98 ) ;
F_130 ( V_48 -> V_12 ) ;
}
static int F_160 ( struct V_11 * V_12 ,
T_10 * V_193 ,
T_10 * V_194 ,
T_11 * V_195 ,
unsigned long * V_162 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
int V_31 ;
V_31 = F_161 ( V_34 -> V_199 , V_34 -> V_12 -> V_74 , NULL ) ;
if ( ! V_31 ) {
F_80 ( L_20 ) ;
return - V_124 ;
}
F_162 ( V_193 , V_194 , V_195 , V_162 ) ;
V_34 -> V_97 . V_132 = F_73 ( V_34 -> V_12 ) ;
V_34 -> V_97 . V_52 . V_86 = F_107 ;
V_34 -> V_97 . V_52 . V_87 = F_105 ;
return 0 ;
}
static void F_163 ( struct V_47 * V_48 )
{
F_164 () ;
}
int F_165 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_198 * V_97 = & V_34 -> V_97 ;
int V_31 ;
if ( F_49 ( V_12 ) -> V_102 <= 5 ) {
V_97 -> V_200 = F_160 ;
V_97 -> V_52 . V_88 = F_163 ;
} else if ( F_49 ( V_12 ) -> V_102 < 8 ) {
V_97 -> V_200 = F_158 ;
V_97 -> V_52 . V_88 = F_159 ;
if ( F_51 ( V_12 ) && V_34 -> V_201 )
V_97 -> V_52 . V_120 = F_10 ;
else if ( F_51 ( V_12 ) )
V_97 -> V_52 . V_120 = F_8 ;
else if ( F_166 ( V_12 ) )
V_97 -> V_52 . V_120 = F_7 ;
else if ( F_49 ( V_12 ) -> V_102 >= 7 )
V_97 -> V_52 . V_120 = F_6 ;
else
V_97 -> V_52 . V_120 = F_3 ;
} else {
V_34 -> V_97 . V_200 = F_153 ;
V_34 -> V_97 . V_52 . V_88 = F_159 ;
}
V_31 = V_97 -> V_200 ( V_12 , & V_97 -> V_52 . V_126 , & V_97 -> V_202 ,
& V_97 -> V_195 , & V_97 -> V_162 ) ;
if ( V_31 )
return V_31 ;
V_97 -> V_52 . V_12 = V_12 ;
F_38 ( L_21 ,
V_97 -> V_52 . V_126 >> 20 ) ;
F_43 ( L_22 , V_97 -> V_162 >> 20 ) ;
F_43 ( L_23 , V_97 -> V_202 >> 20 ) ;
return 0 ;
}
