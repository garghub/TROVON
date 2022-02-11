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
goto V_47;
}
}
return 0 ;
V_47:
F_20 (ring, dev_priv, j)
F_21 ( F_22 ( V_28 ) ,
F_24 ( V_45 ) ) ;
return V_31 ;
}
static void F_25 ( struct V_48 * V_49 ,
unsigned V_50 ,
unsigned V_51 ,
bool V_52 )
{
struct V_36 * V_37 =
F_26 ( V_49 , struct V_36 , V_53 ) ;
T_1 * V_54 , V_55 ;
unsigned V_56 = V_50 / V_57 ;
unsigned V_58 = V_50 % V_57 ;
unsigned V_59 , V_40 ;
V_55 = F_1 ( V_37 -> V_53 . V_60 . V_1 ,
V_17 , V_52 ) ;
while ( V_51 ) {
struct V_61 * V_62 = & V_37 -> V_63 [ V_56 ] ;
V_59 = V_58 + V_51 ;
if ( V_59 > V_57 )
V_59 = V_57 ;
V_54 = F_27 ( V_62 ) ;
for ( V_40 = V_58 ; V_40 < V_59 ; V_40 ++ )
V_54 [ V_40 ] = V_55 ;
F_28 ( V_54 ) ;
V_51 -= V_59 - V_58 ;
V_58 = 0 ;
V_56 ++ ;
}
}
static void F_29 ( struct V_48 * V_49 ,
struct V_64 * V_65 ,
unsigned V_50 ,
enum V_2 V_66 )
{
struct V_36 * V_37 =
F_26 ( V_49 , struct V_36 , V_53 ) ;
T_1 * V_54 ;
unsigned V_56 = V_50 / V_57 ;
unsigned V_67 = V_50 % V_57 ;
struct V_68 V_69 ;
V_54 = NULL ;
F_30 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_54 == NULL )
V_54 = F_27 ( & V_37 -> V_63 [ V_56 ] ) ;
V_54 [ V_67 ] =
F_1 ( F_31 ( & V_69 ) ,
V_66 , true ) ;
if ( ++ V_67 == V_57 ) {
F_28 ( V_54 ) ;
V_54 = NULL ;
V_56 ++ ;
V_67 = 0 ;
}
}
if ( V_54 )
F_28 ( V_54 ) ;
}
static void F_32 ( struct V_48 * V_49 )
{
struct V_36 * V_37 =
F_26 ( V_49 , struct V_36 , V_53 ) ;
int V_40 , V_41 ;
F_33 ( & V_49 -> V_38 ) ;
for ( V_40 = 0 ; V_40 < V_37 -> V_70 ; V_40 ++ ) {
if ( V_37 -> V_46 [ V_40 ] ) {
F_34 ( V_37 -> V_53 . V_12 -> V_71 ,
V_37 -> V_46 [ V_40 ] ,
V_72 , V_73 ) ;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ ) {
T_2 V_1 = V_37 -> V_74 [ V_40 ] [ V_41 ] ;
if ( V_1 )
F_34 ( V_37 -> V_53 . V_12 -> V_71 ,
V_1 ,
V_72 ,
V_73 ) ;
}
}
F_35 ( V_37 -> V_74 [ V_40 ] ) ;
}
F_36 ( V_37 -> V_63 , F_37 ( V_37 -> V_75 << V_76 ) ) ;
F_36 ( V_37 -> V_77 , F_37 ( V_37 -> V_70 << V_76 ) ) ;
}
static int F_38 ( struct V_36 * V_37 , T_5 V_78 )
{
struct V_61 * V_79 ;
int V_40 , V_41 , V_31 = - V_80 ;
const int V_81 = F_39 ( V_78 , 1 << 30 ) ;
const int V_75 = V_44 * V_81 ;
if ( V_78 % ( 1 << 30 ) )
F_40 ( L_1 , V_78 ) ;
V_37 -> V_77 = F_41 ( V_82 , F_37 ( V_81 << V_76 ) ) ;
if ( ! V_37 -> V_77 )
return - V_80 ;
V_79 = F_41 ( V_82 , F_37 ( V_75 << V_76 ) ) ;
if ( ! V_79 ) {
F_36 ( V_37 -> V_77 , F_37 ( V_81 << V_76 ) ) ;
return - V_80 ;
}
V_37 -> V_63 = V_79 ;
V_37 -> V_70 = 1 << F_37 ( V_81 << V_76 ) ;
V_37 -> V_75 = 1 << F_37 ( V_75 << V_76 ) ;
V_37 -> V_43 = V_81 * V_44 ;
V_37 -> V_83 = F_19 ;
V_37 -> V_53 . V_84 = F_25 ;
V_37 -> V_53 . V_85 = F_29 ;
V_37 -> V_53 . V_86 = F_32 ;
V_37 -> V_53 . V_87 = 0 ;
V_37 -> V_53 . V_88 = V_37 -> V_75 * V_57 * V_72 ;
F_12 ( V_37 -> V_70 > V_89 ) ;
for ( V_40 = 0 ; V_40 < V_81 ; V_40 ++ ) {
T_2 V_90 ;
V_90 = F_42 ( V_37 -> V_53 . V_12 -> V_71 ,
& V_37 -> V_77 [ V_40 ] , 0 ,
V_72 , V_73 ) ;
if ( F_43 ( V_37 -> V_53 . V_12 -> V_71 , V_90 ) )
goto V_47;
V_37 -> V_46 [ V_40 ] = V_90 ;
V_37 -> V_74 [ V_40 ] = F_44 ( sizeof( T_2 ) * V_44 , V_82 ) ;
if ( ! V_37 -> V_74 [ V_40 ] )
goto V_47;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ ) {
struct V_61 * V_91 = & V_79 [ V_40 * V_44 + V_41 ] ;
V_90 = F_42 ( V_37 -> V_53 . V_12 -> V_71 ,
V_91 , 0 , V_72 ,
V_73 ) ;
if ( F_43 ( V_37 -> V_53 . V_12 -> V_71 , V_90 ) )
goto V_47;
V_37 -> V_74 [ V_40 ] [ V_41 ] = V_90 ;
}
}
for ( V_40 = 0 ; V_40 < V_81 ; V_40 ++ ) {
T_3 * V_92 ;
V_92 = F_27 ( & V_37 -> V_77 [ V_40 ] ) ;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ ) {
T_2 V_1 = V_37 -> V_74 [ V_40 ] [ V_41 ] ;
V_92 [ V_41 ] = F_2 ( V_37 -> V_53 . V_12 , V_1 ,
V_17 ) ;
}
F_28 ( V_92 ) ;
}
V_37 -> V_53 . V_84 ( & V_37 -> V_53 , 0 ,
V_37 -> V_43 * V_57 ,
true ) ;
F_45 ( L_2 ,
V_37 -> V_70 , V_37 -> V_70 - V_81 ) ;
F_45 ( L_3 ,
V_37 -> V_75 ,
( V_37 -> V_75 - V_75 ) +
V_78 % ( 1 << 30 ) ) ;
return 0 ;
V_47:
V_37 -> V_53 . V_86 ( & V_37 -> V_53 ) ;
return V_31 ;
}
static void F_46 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = V_37 -> V_53 . V_12 -> V_35 ;
T_4 T_6 * V_93 ;
T_7 V_94 ;
int V_40 ;
F_5 ( V_37 -> V_95 & 0x3f ) ;
V_93 = ( T_4 T_6 * ) V_34 -> V_96 . V_97 +
V_37 -> V_95 / sizeof( T_4 ) ;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ ) {
T_2 V_98 ;
V_98 = V_37 -> V_99 [ V_40 ] ;
V_94 = F_47 ( V_98 ) ;
V_94 |= V_100 ;
F_48 ( V_94 , V_93 + V_40 ) ;
}
F_49 ( V_93 ) ;
}
static int F_50 ( struct V_11 * V_12 )
{
T_8 * V_34 = V_12 -> V_35 ;
T_7 V_95 ;
struct V_27 * V_28 ;
struct V_36 * V_37 = V_34 -> V_38 . V_39 ;
int V_40 ;
F_12 ( V_37 -> V_95 & 0x3f ) ;
F_46 ( V_37 ) ;
V_95 = V_37 -> V_95 ;
V_95 /= 64 ;
V_95 <<= 16 ;
if ( F_51 ( V_12 ) -> V_101 == 6 ) {
T_7 V_102 , V_103 , V_104 ;
V_104 = F_52 ( V_105 ) ;
F_21 ( V_105 , V_104 | V_106 |
V_107 ) ;
V_103 = F_52 ( V_108 ) ;
F_21 ( V_108 , V_103 | V_109 ) ;
V_102 = F_52 ( V_110 ) ;
F_21 ( V_110 , V_102 | V_111 |
V_112 ) ;
F_21 ( V_113 , F_23 ( V_45 ) ) ;
} else if ( F_51 ( V_12 ) -> V_101 >= 7 ) {
T_7 V_102 , V_104 ;
V_104 = F_52 ( V_105 ) ;
F_21 ( V_105 , V_104 | V_107 ) ;
V_102 = F_52 ( V_110 ) ;
if ( F_53 ( V_12 ) ) {
V_102 |= V_114 ;
} else {
V_102 |= V_115 ;
V_102 &= ~ V_116 ;
}
F_21 ( V_110 , V_102 ) ;
}
F_20 (ring, dev_priv, i) {
if ( F_51 ( V_12 ) -> V_101 >= 7 )
F_21 ( F_22 ( V_28 ) ,
F_23 ( V_45 ) ) ;
F_21 ( F_54 ( V_28 ) , V_117 ) ;
F_21 ( F_55 ( V_28 ) , V_95 ) ;
}
return 0 ;
}
static void F_56 ( struct V_48 * V_49 ,
unsigned V_50 ,
unsigned V_51 ,
bool V_52 )
{
struct V_36 * V_37 =
F_26 ( V_49 , struct V_36 , V_53 ) ;
T_4 * V_54 , V_55 ;
unsigned V_56 = V_50 / V_118 ;
unsigned V_58 = V_50 % V_118 ;
unsigned V_59 , V_40 ;
V_55 = V_49 -> V_119 ( V_49 -> V_60 . V_1 , V_17 , true ) ;
while ( V_51 ) {
V_59 = V_58 + V_51 ;
if ( V_59 > V_118 )
V_59 = V_118 ;
V_54 = F_27 ( V_37 -> V_79 [ V_56 ] ) ;
for ( V_40 = V_58 ; V_40 < V_59 ; V_40 ++ )
V_54 [ V_40 ] = V_55 ;
F_28 ( V_54 ) ;
V_51 -= V_59 - V_58 ;
V_58 = 0 ;
V_56 ++ ;
}
}
static void F_57 ( struct V_48 * V_49 ,
struct V_64 * V_65 ,
unsigned V_50 ,
enum V_2 V_66 )
{
struct V_36 * V_37 =
F_26 ( V_49 , struct V_36 , V_53 ) ;
T_4 * V_54 ;
unsigned V_56 = V_50 / V_118 ;
unsigned V_67 = V_50 % V_118 ;
struct V_68 V_69 ;
V_54 = NULL ;
F_30 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_54 == NULL )
V_54 = F_27 ( V_37 -> V_79 [ V_56 ] ) ;
V_54 [ V_67 ] =
V_49 -> V_119 ( F_31 ( & V_69 ) ,
V_66 , true ) ;
if ( ++ V_67 == V_118 ) {
F_28 ( V_54 ) ;
V_54 = NULL ;
V_56 ++ ;
V_67 = 0 ;
}
}
if ( V_54 )
F_28 ( V_54 ) ;
}
static void F_58 ( struct V_48 * V_49 )
{
struct V_36 * V_37 =
F_26 ( V_49 , struct V_36 , V_53 ) ;
int V_40 ;
F_33 ( & V_37 -> V_53 . V_38 ) ;
if ( V_37 -> V_99 ) {
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ )
F_34 ( V_37 -> V_53 . V_12 -> V_71 ,
V_37 -> V_99 [ V_40 ] ,
4096 , V_73 ) ;
}
F_35 ( V_37 -> V_99 ) ;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ )
F_59 ( V_37 -> V_79 [ V_40 ] ) ;
F_35 ( V_37 -> V_79 ) ;
F_35 ( V_37 ) ;
}
static int F_60 ( struct V_36 * V_37 )
{
struct V_11 * V_12 = V_37 -> V_53 . V_12 ;
struct V_33 * V_34 = V_12 -> V_35 ;
unsigned V_120 ;
int V_40 ;
int V_31 = - V_80 ;
V_120 = F_61 ( V_34 -> V_96 ) ;
V_37 -> V_53 . V_119 = V_34 -> V_96 . V_53 . V_119 ;
V_37 -> V_43 = V_121 ;
V_37 -> V_83 = F_50 ;
V_37 -> V_53 . V_84 = F_56 ;
V_37 -> V_53 . V_85 = F_57 ;
V_37 -> V_53 . V_86 = F_58 ;
V_37 -> V_53 . V_60 = V_34 -> V_96 . V_53 . V_60 ;
V_37 -> V_53 . V_87 = 0 ;
V_37 -> V_53 . V_88 = V_121 * V_118 * V_72 ;
V_37 -> V_79 = F_62 ( V_37 -> V_43 , sizeof( struct V_61 * ) ,
V_82 ) ;
if ( ! V_37 -> V_79 )
return - V_80 ;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ ) {
V_37 -> V_79 [ V_40 ] = F_63 ( V_82 ) ;
if ( ! V_37 -> V_79 [ V_40 ] )
goto V_122;
}
V_37 -> V_99 = F_62 ( V_37 -> V_43 , sizeof( T_2 ) ,
V_82 ) ;
if ( ! V_37 -> V_99 )
goto V_122;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ ) {
T_2 V_98 ;
V_98 = F_42 ( V_12 -> V_71 , V_37 -> V_79 [ V_40 ] , 0 , 4096 ,
V_73 ) ;
if ( F_43 ( V_12 -> V_71 , V_98 ) ) {
V_31 = - V_123 ;
goto V_124;
}
V_37 -> V_99 [ V_40 ] = V_98 ;
}
V_37 -> V_53 . V_84 ( & V_37 -> V_53 , 0 ,
V_37 -> V_43 * V_118 , true ) ;
V_37 -> V_95 = V_120 * sizeof( T_4 ) ;
return 0 ;
V_124:
if ( V_37 -> V_99 ) {
for ( V_40 -- ; V_40 >= 0 ; V_40 -- )
F_34 ( V_12 -> V_71 , V_37 -> V_99 [ V_40 ] ,
4096 , V_73 ) ;
}
V_122:
F_35 ( V_37 -> V_99 ) ;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ ) {
if ( V_37 -> V_79 [ V_40 ] )
F_59 ( V_37 -> V_79 [ V_40 ] ) ;
}
F_35 ( V_37 -> V_79 ) ;
return V_31 ;
}
static int F_64 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_36 * V_37 ;
int V_31 ;
V_37 = F_65 ( sizeof( * V_37 ) , V_82 ) ;
if ( ! V_37 )
return - V_80 ;
V_37 -> V_53 . V_12 = V_12 ;
if ( F_51 ( V_12 ) -> V_101 < 8 )
V_31 = F_60 ( V_37 ) ;
else if ( F_66 ( V_12 ) )
V_31 = F_38 ( V_37 , V_34 -> V_96 . V_53 . V_88 ) ;
else
F_67 () ;
if ( V_31 )
F_35 ( V_37 ) ;
else {
V_34 -> V_38 . V_39 = V_37 ;
F_68 ( & V_37 -> V_53 . V_38 , V_37 -> V_53 . V_87 ,
V_37 -> V_53 . V_88 ) ;
}
return V_31 ;
}
void F_69 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_36 * V_37 = V_34 -> V_38 . V_39 ;
if ( ! V_37 )
return;
V_37 -> V_53 . V_86 ( & V_37 -> V_53 ) ;
V_34 -> V_38 . V_39 = NULL ;
}
void F_70 ( struct V_36 * V_37 ,
struct V_125 * V_126 ,
enum V_2 V_66 )
{
V_37 -> V_53 . V_85 ( & V_37 -> V_53 , V_126 -> V_65 ,
F_71 ( V_126 ) >> V_76 ,
V_66 ) ;
}
void F_72 ( struct V_36 * V_37 ,
struct V_125 * V_126 )
{
V_37 -> V_53 . V_84 ( & V_37 -> V_53 ,
F_71 ( V_126 ) >> V_76 ,
V_126 -> V_53 . V_78 >> V_76 ,
true ) ;
}
static inline bool F_73 ( struct V_11 * V_12 )
{
#ifdef F_74
if ( F_75 ( V_12 ) && F_76 ( V_12 ) && V_127 )
return true ;
#endif
return false ;
}
static bool F_77 ( struct V_33 * V_34 )
{
bool V_31 = V_34 -> V_38 . V_128 ;
if ( F_78 ( V_34 -> V_96 . V_129 ) ) {
V_34 -> V_38 . V_128 = false ;
if ( F_79 ( V_34 -> V_12 ) ) {
F_80 ( L_4 ) ;
F_81 ( 10 ) ;
}
}
return V_31 ;
}
static void F_82 ( struct V_33 * V_34 , bool V_128 )
{
if ( F_78 ( V_34 -> V_96 . V_129 ) )
V_34 -> V_38 . V_128 = V_128 ;
}
void F_83 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_27 * V_28 ;
int V_40 ;
if ( F_51 ( V_12 ) -> V_101 < 6 )
return;
F_20 (ring, dev_priv, i) {
V_32 V_130 ;
V_130 = F_52 ( F_84 ( V_28 ) ) ;
if ( V_130 & V_131 ) {
F_45 ( L_5
L_6
L_7
L_8
L_9 ,
V_130 & V_132 ,
V_130 & V_133 ? L_10 : L_11 ,
F_85 ( V_130 ) ,
F_86 ( V_130 ) ) ;
F_21 ( F_84 ( V_28 ) ,
V_130 & ~ V_131 ) ;
}
}
F_87 ( F_84 ( & V_34 -> V_28 [ V_134 ] ) ) ;
}
void F_88 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
if ( F_51 ( V_12 ) -> V_101 < 6 )
return;
F_83 ( V_12 ) ;
V_34 -> V_96 . V_53 . V_84 ( & V_34 -> V_96 . V_53 ,
V_34 -> V_96 . V_53 . V_87 / V_72 ,
V_34 -> V_96 . V_53 . V_88 / V_72 ,
true ) ;
}
void F_89 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_125 * V_126 ;
F_83 ( V_12 ) ;
V_34 -> V_96 . V_53 . V_84 ( & V_34 -> V_96 . V_53 ,
V_34 -> V_96 . V_53 . V_87 / V_72 ,
V_34 -> V_96 . V_53 . V_88 / V_72 ,
true ) ;
F_90 (obj, &dev_priv->mm.bound_list, global_list) {
F_91 ( V_126 , V_126 -> V_135 ) ;
F_92 ( V_126 , V_126 -> V_66 ) ;
}
F_93 ( V_12 ) ;
}
int F_94 ( struct V_125 * V_126 )
{
if ( V_126 -> V_136 )
return 0 ;
if ( ! F_95 ( & V_126 -> V_53 . V_12 -> V_71 -> V_12 ,
V_126 -> V_65 -> V_137 , V_126 -> V_65 -> V_138 ,
V_73 ) )
return - V_139 ;
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
static void F_99 ( struct V_48 * V_49 ,
struct V_64 * V_140 ,
unsigned int V_50 ,
enum V_2 V_3 )
{
struct V_33 * V_34 = V_49 -> V_12 -> V_35 ;
T_1 T_6 * V_141 =
( T_1 T_6 * ) V_34 -> V_96 . V_97 + V_50 ;
int V_40 = 0 ;
struct V_68 V_69 ;
T_2 V_1 ;
F_30 (st->sgl, &sg_iter, st->nents, 0 ) {
V_1 = F_100 ( V_69 . V_142 ) +
( V_69 . V_143 << V_76 ) ;
F_96 ( & V_141 [ V_40 ] ,
F_1 ( V_1 , V_3 , true ) ) ;
V_40 ++ ;
}
if ( V_40 != 0 )
F_5 ( F_101 ( & V_141 [ V_40 - 1 ] )
!= F_1 ( V_1 , V_3 , true ) ) ;
F_21 ( V_144 , V_145 ) ;
F_87 ( V_144 ) ;
}
static void F_102 ( struct V_48 * V_49 ,
struct V_64 * V_140 ,
unsigned int V_50 ,
enum V_2 V_3 )
{
struct V_33 * V_34 = V_49 -> V_12 -> V_35 ;
T_4 T_6 * V_141 =
( T_4 T_6 * ) V_34 -> V_96 . V_97 + V_50 ;
int V_40 = 0 ;
struct V_68 V_69 ;
T_2 V_1 ;
F_30 (st->sgl, &sg_iter, st->nents, 0 ) {
V_1 = F_31 ( & V_69 ) ;
F_98 ( V_49 -> V_119 ( V_1 , V_3 , true ) , & V_141 [ V_40 ] ) ;
V_40 ++ ;
}
if ( V_40 != 0 )
F_5 ( F_49 ( & V_141 [ V_40 - 1 ] ) !=
V_49 -> V_119 ( V_1 , V_3 , true ) ) ;
F_21 ( V_144 , V_145 ) ;
F_87 ( V_144 ) ;
}
static void F_103 ( struct V_48 * V_49 ,
unsigned int V_50 ,
unsigned int V_51 ,
bool V_52 )
{
struct V_33 * V_34 = V_49 -> V_12 -> V_35 ;
T_1 V_55 , T_6 * V_146 =
( T_1 T_6 * ) V_34 -> V_96 . V_97 + V_50 ;
const int V_147 = F_61 ( V_34 -> V_96 ) - V_50 ;
int V_40 ;
if ( F_104 ( V_51 > V_147 ,
L_12 ,
V_50 , V_51 , V_147 ) )
V_51 = V_147 ;
V_55 = F_1 ( V_49 -> V_60 . V_1 ,
V_17 ,
V_52 ) ;
for ( V_40 = 0 ; V_40 < V_51 ; V_40 ++ )
F_96 ( & V_146 [ V_40 ] , V_55 ) ;
F_49 ( V_146 ) ;
}
static void F_105 ( struct V_48 * V_49 ,
unsigned int V_50 ,
unsigned int V_51 ,
bool V_52 )
{
struct V_33 * V_34 = V_49 -> V_12 -> V_35 ;
T_4 V_55 , T_6 * V_146 =
( T_4 T_6 * ) V_34 -> V_96 . V_97 + V_50 ;
const int V_147 = F_61 ( V_34 -> V_96 ) - V_50 ;
int V_40 ;
if ( F_104 ( V_51 > V_147 ,
L_12 ,
V_50 , V_51 , V_147 ) )
V_51 = V_147 ;
V_55 = V_49 -> V_119 ( V_49 -> V_60 . V_1 , V_17 , V_52 ) ;
for ( V_40 = 0 ; V_40 < V_51 ; V_40 ++ )
F_98 ( V_55 , & V_146 [ V_40 ] ) ;
F_49 ( V_146 ) ;
}
static void F_106 ( struct V_48 * V_49 ,
struct V_64 * V_140 ,
unsigned int V_148 ,
enum V_2 V_66 )
{
unsigned int V_149 = ( V_66 == V_8 ) ?
V_150 : V_151 ;
F_107 ( V_140 , V_148 , V_149 ) ;
}
static void F_108 ( struct V_48 * V_49 ,
unsigned int V_50 ,
unsigned int V_51 ,
bool V_152 )
{
F_109 ( V_50 , V_51 ) ;
}
void F_92 ( struct V_125 * V_126 ,
enum V_2 V_66 )
{
struct V_11 * V_12 = V_126 -> V_53 . V_12 ;
struct V_33 * V_34 = V_12 -> V_35 ;
const unsigned long V_29 = F_71 ( V_126 ) >> V_76 ;
V_34 -> V_96 . V_53 . V_85 ( & V_34 -> V_96 . V_53 , V_126 -> V_65 ,
V_29 ,
V_66 ) ;
V_126 -> V_153 = 1 ;
}
void F_110 ( struct V_125 * V_126 )
{
struct V_11 * V_12 = V_126 -> V_53 . V_12 ;
struct V_33 * V_34 = V_12 -> V_35 ;
const unsigned long V_29 = F_71 ( V_126 ) >> V_76 ;
V_34 -> V_96 . V_53 . V_84 ( & V_34 -> V_96 . V_53 ,
V_29 ,
V_126 -> V_53 . V_78 >> V_76 ,
true ) ;
V_126 -> V_153 = 0 ;
}
void F_111 ( struct V_125 * V_126 )
{
struct V_11 * V_12 = V_126 -> V_53 . V_12 ;
struct V_33 * V_34 = V_12 -> V_35 ;
bool V_128 ;
V_128 = F_77 ( V_34 ) ;
if ( ! V_126 -> V_136 )
F_112 ( & V_12 -> V_71 -> V_12 ,
V_126 -> V_65 -> V_137 , V_126 -> V_65 -> V_138 ,
V_73 ) ;
F_82 ( V_34 , V_128 ) ;
}
static void F_113 ( struct V_154 * V_155 ,
unsigned long V_156 ,
unsigned long * V_87 ,
unsigned long * V_157 )
{
if ( V_155 -> V_156 != V_156 )
* V_87 += 4096 ;
if ( ! F_114 ( & V_155 -> V_158 ) ) {
V_155 = F_115 ( V_155 -> V_158 . V_159 ,
struct V_154 ,
V_158 ) ;
if ( V_155 -> V_160 && V_155 -> V_156 != V_156 )
* V_157 -= 4096 ;
}
}
void F_116 ( struct V_11 * V_12 ,
unsigned long V_87 ,
unsigned long V_161 ,
unsigned long V_157 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_48 * V_162 = & V_34 -> V_96 . V_53 ;
struct V_154 * V_29 ;
struct V_125 * V_126 ;
unsigned long V_163 , V_164 ;
F_12 ( V_161 > V_157 ) ;
F_68 ( & V_162 -> V_38 , V_87 , V_157 - V_87 - V_72 ) ;
if ( ! F_117 ( V_12 ) )
V_34 -> V_96 . V_53 . V_38 . V_165 = F_113 ;
F_90 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_166 * V_167 = F_118 ( V_126 , V_162 ) ;
int V_31 ;
F_119 ( L_13 ,
F_71 ( V_126 ) , V_126 -> V_53 . V_78 ) ;
F_5 ( F_120 ( V_126 ) ) ;
V_31 = F_121 ( & V_162 -> V_38 , & V_167 -> V_155 ) ;
if ( V_31 )
F_119 ( L_14 ) ;
V_126 -> V_153 = 1 ;
}
V_34 -> V_96 . V_53 . V_87 = V_87 ;
V_34 -> V_96 . V_53 . V_88 = V_157 - V_87 ;
F_122 (entry, &ggtt_vm->mm, hole_start, hole_end) {
const unsigned long V_168 = ( V_164 - V_163 ) / V_72 ;
F_119 ( L_15 ,
V_163 , V_164 ) ;
V_162 -> V_84 ( V_162 , V_163 / V_72 , V_168 , true ) ;
}
V_162 -> V_84 ( V_162 , V_157 / V_72 - 1 , 1 , true ) ;
}
static bool
F_123 ( struct V_11 * V_12 )
{
if ( V_169 >= 0 )
return V_169 ;
#ifdef F_74
if ( F_51 ( V_12 ) -> V_101 == 6 && V_127 )
return false ;
#endif
return true ;
}
void F_124 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
unsigned long V_170 , V_171 ;
V_170 = V_34 -> V_96 . V_53 . V_88 ;
V_171 = V_34 -> V_96 . V_161 ;
if ( F_123 ( V_12 ) && F_125 ( V_12 ) ) {
int V_31 ;
if ( F_51 ( V_12 ) -> V_101 <= 7 ) {
V_170 -= V_121 * V_72 ;
}
F_116 ( V_12 , 0 , V_171 , V_170 ) ;
V_31 = F_64 ( V_12 ) ;
if ( ! V_31 )
return;
F_80 ( L_16 , V_31 ) ;
F_33 ( & V_34 -> V_96 . V_53 . V_38 ) ;
if ( F_51 ( V_12 ) -> V_101 < 8 )
V_170 += V_121 * V_72 ;
}
F_116 ( V_12 , 0 , V_171 , V_170 ) ;
}
static int F_126 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_61 * V_61 ;
T_2 V_172 ;
V_61 = F_63 ( V_82 | V_173 | V_174 ) ;
if ( V_61 == NULL )
return - V_80 ;
F_127 ( V_61 ) ;
F_128 ( V_61 , 1 ) ;
#ifdef F_74
V_172 = F_42 ( V_12 -> V_71 , V_61 , 0 , V_72 ,
V_73 ) ;
if ( F_43 ( V_12 -> V_71 , V_172 ) )
return - V_175 ;
#else
V_172 = F_129 ( V_61 ) ;
#endif
V_34 -> V_96 . V_53 . V_60 . V_61 = V_61 ;
V_34 -> V_96 . V_53 . V_60 . V_1 = V_172 ;
return 0 ;
}
static void F_130 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_61 * V_61 = V_34 -> V_96 . V_53 . V_60 . V_61 ;
F_131 ( V_61 , 1 ) ;
F_34 ( V_12 -> V_71 , V_34 -> V_96 . V_53 . V_60 . V_1 ,
V_72 , V_73 ) ;
F_132 ( V_61 ) ;
F_59 ( V_61 ) ;
}
static inline unsigned int F_133 ( T_9 V_176 )
{
V_176 >>= V_177 ;
V_176 &= V_178 ;
return V_176 << 20 ;
}
static inline unsigned int F_134 ( T_9 V_179 )
{
V_179 >>= V_180 ;
V_179 &= V_181 ;
if ( V_179 )
V_179 = 1 << V_179 ;
if ( V_179 > 4 ) {
F_5 ( ! V_182 ) ;
return 4 << 20 ;
}
return V_179 << 20 ;
}
static inline T_10 F_135 ( T_9 V_176 )
{
V_176 >>= V_183 ;
V_176 &= V_184 ;
return V_176 << 25 ;
}
static inline T_10 F_136 ( T_9 V_179 )
{
V_179 >>= V_185 ;
V_179 &= V_186 ;
return V_179 << 25 ;
}
static int F_137 ( struct V_11 * V_12 ,
T_10 V_170 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
T_11 V_187 ;
int V_31 ;
V_187 = F_138 ( V_12 -> V_71 , 0 ) +
( F_139 ( V_12 -> V_71 , 0 ) / 2 ) ;
V_34 -> V_96 . V_97 = F_140 ( V_187 , V_170 ) ;
if ( ! V_34 -> V_96 . V_97 ) {
F_80 ( L_17 ) ;
return - V_80 ;
}
V_31 = F_126 ( V_12 ) ;
if ( V_31 ) {
F_80 ( L_18 ) ;
F_141 ( V_34 -> V_96 . V_97 ) ;
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
T_5 V_188 ;
V_188 = F_152 ( 0 , F_146 | F_148 ) |
F_152 ( 1 , F_144 | F_149 ) |
F_152 ( 2 , F_145 | F_149 ) |
F_152 ( 3 , F_143 ) |
F_152 ( 4 , F_146 | F_149 | F_151 ( 0 ) ) |
F_152 ( 5 , F_146 | F_149 | F_151 ( 1 ) ) |
F_152 ( 6 , F_146 | F_149 | F_151 ( 2 ) ) |
F_152 ( 7 , F_146 | F_149 | F_151 ( 3 ) ) ;
F_21 ( V_189 , V_188 ) ;
F_21 ( V_189 + 4 , V_188 >> 32 ) ;
}
static int F_153 ( struct V_11 * V_12 ,
T_10 * V_190 ,
T_10 * V_191 ,
T_11 * V_192 ,
unsigned long * V_161 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
unsigned int V_170 ;
T_9 V_176 ;
int V_31 ;
* V_192 = F_138 ( V_12 -> V_71 , 2 ) ;
* V_161 = F_139 ( V_12 -> V_71 , 2 ) ;
if ( ! F_154 ( V_12 -> V_71 , F_155 ( 39 ) ) )
F_156 ( V_12 -> V_71 , F_155 ( 39 ) ) ;
F_157 ( V_12 -> V_71 , V_193 , & V_176 ) ;
* V_191 = F_136 ( V_176 ) ;
V_170 = F_134 ( V_176 ) ;
* V_190 = ( V_170 / sizeof( T_1 ) ) << V_76 ;
F_142 ( V_34 ) ;
V_31 = F_137 ( V_12 , V_170 ) ;
V_34 -> V_96 . V_53 . V_84 = F_103 ;
V_34 -> V_96 . V_53 . V_85 = F_99 ;
return V_31 ;
}
static int F_158 ( struct V_11 * V_12 ,
T_10 * V_190 ,
T_10 * V_191 ,
T_11 * V_192 ,
unsigned long * V_161 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
unsigned int V_170 ;
T_9 V_176 ;
int V_31 ;
* V_192 = F_138 ( V_12 -> V_71 , 2 ) ;
* V_161 = F_139 ( V_12 -> V_71 , 2 ) ;
if ( ( * V_161 < ( 64 << 20 ) || ( * V_161 > ( 512 << 20 ) ) ) ) {
F_80 ( L_19 ,
V_34 -> V_96 . V_161 ) ;
return - V_194 ;
}
if ( ! F_154 ( V_12 -> V_71 , F_155 ( 40 ) ) )
F_156 ( V_12 -> V_71 , F_155 ( 40 ) ) ;
F_157 ( V_12 -> V_71 , V_193 , & V_176 ) ;
* V_191 = F_135 ( V_176 ) ;
V_170 = F_133 ( V_176 ) ;
* V_190 = ( V_170 / sizeof( T_4 ) ) << V_76 ;
V_31 = F_137 ( V_12 , V_170 ) ;
V_34 -> V_96 . V_53 . V_84 = F_105 ;
V_34 -> V_96 . V_53 . V_85 = F_102 ;
return V_31 ;
}
static void F_159 ( struct V_48 * V_49 )
{
struct V_195 * V_96 = F_26 ( V_49 , struct V_195 , V_53 ) ;
F_33 ( & V_49 -> V_38 ) ;
F_141 ( V_96 -> V_97 ) ;
F_130 ( V_49 -> V_12 ) ;
}
static int F_160 ( struct V_11 * V_12 ,
T_10 * V_190 ,
T_10 * V_191 ,
T_11 * V_192 ,
unsigned long * V_161 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
int V_31 ;
V_31 = F_161 ( V_34 -> V_196 , V_34 -> V_12 -> V_71 , NULL ) ;
if ( ! V_31 ) {
F_80 ( L_20 ) ;
return - V_123 ;
}
F_162 ( V_190 , V_191 , V_192 , V_161 ) ;
V_34 -> V_96 . V_129 = F_73 ( V_34 -> V_12 ) ;
V_34 -> V_96 . V_53 . V_84 = F_108 ;
V_34 -> V_96 . V_53 . V_85 = F_106 ;
if ( F_78 ( V_34 -> V_96 . V_129 ) )
F_40 ( L_21 ) ;
return 0 ;
}
static void F_163 ( struct V_48 * V_49 )
{
F_164 () ;
}
int F_165 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_195 * V_96 = & V_34 -> V_96 ;
int V_31 ;
if ( F_51 ( V_12 ) -> V_101 <= 5 ) {
V_96 -> V_197 = F_160 ;
V_96 -> V_53 . V_86 = F_163 ;
} else if ( F_51 ( V_12 ) -> V_101 < 8 ) {
V_96 -> V_197 = F_158 ;
V_96 -> V_53 . V_86 = F_159 ;
if ( F_53 ( V_12 ) && V_34 -> V_198 )
V_96 -> V_53 . V_119 = F_10 ;
else if ( F_53 ( V_12 ) )
V_96 -> V_53 . V_119 = F_8 ;
else if ( F_166 ( V_12 ) )
V_96 -> V_53 . V_119 = F_7 ;
else if ( F_51 ( V_12 ) -> V_101 >= 7 )
V_96 -> V_53 . V_119 = F_6 ;
else
V_96 -> V_53 . V_119 = F_3 ;
} else {
V_34 -> V_96 . V_197 = F_153 ;
V_34 -> V_96 . V_53 . V_86 = F_159 ;
}
V_31 = V_96 -> V_197 ( V_12 , & V_96 -> V_53 . V_88 , & V_96 -> V_199 ,
& V_96 -> V_192 , & V_96 -> V_161 ) ;
if ( V_31 )
return V_31 ;
V_96 -> V_53 . V_12 = V_12 ;
F_40 ( L_22 ,
V_96 -> V_53 . V_88 >> 20 ) ;
F_45 ( L_23 , V_96 -> V_161 >> 20 ) ;
F_45 ( L_24 , V_96 -> V_199 >> 20 ) ;
return 0 ;
}
