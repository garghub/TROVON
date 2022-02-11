bool F_1 ( struct V_1 * V_2 , bool V_3 )
{
if ( V_4 . V_5 == 0 )
return false ;
if ( V_4 . V_5 == 1 && V_3 )
return false ;
return true ;
}
static int F_2 ( struct V_1 * V_2 , int V_5 )
{
if ( V_5 == 0 || ! F_3 ( V_2 ) )
return 0 ;
if ( V_5 == 1 )
return 1 ;
if ( V_5 == 2 && F_4 ( V_2 ) )
return 2 ;
#ifdef F_5
if ( F_6 ( V_2 ) -> V_6 == 6 && V_7 ) {
F_7 ( L_1 ) ;
return 0 ;
}
#endif
return F_3 ( V_2 ) ? 1 : 0 ;
}
static inline T_1 F_8 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 )
{
T_1 V_12 = V_11 ? V_13 | V_14 : 0 ;
V_12 |= V_8 ;
if ( V_10 != V_15 )
V_12 |= V_16 ;
else
V_12 |= V_17 ;
return V_12 ;
}
static inline T_3 F_9 ( struct V_1 * V_2 ,
T_2 V_8 ,
enum V_9 V_10 )
{
T_3 V_18 = V_13 | V_14 ;
V_18 |= V_8 ;
if ( V_10 != V_15 )
V_18 |= V_19 ;
else
V_18 |= V_17 ;
return V_18 ;
}
static T_4 F_10 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 )
{
T_4 V_12 = V_11 ? V_20 : 0 ;
V_12 |= F_11 ( V_8 ) ;
switch ( V_10 ) {
case V_21 :
case V_22 :
V_12 |= V_23 ;
break;
case V_15 :
V_12 |= V_24 ;
break;
default:
F_12 ( 1 ) ;
}
return V_12 ;
}
static T_4 F_13 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 )
{
T_4 V_12 = V_11 ? V_20 : 0 ;
V_12 |= F_11 ( V_8 ) ;
switch ( V_10 ) {
case V_21 :
V_12 |= V_25 ;
break;
case V_22 :
V_12 |= V_23 ;
break;
case V_15 :
V_12 |= V_24 ;
break;
default:
F_12 ( 1 ) ;
}
return V_12 ;
}
static T_4 F_14 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 )
{
T_4 V_12 = V_11 ? V_20 : 0 ;
V_12 |= F_11 ( V_8 ) ;
V_12 |= V_26 ;
if ( V_10 != V_15 )
V_12 |= V_27 ;
return V_12 ;
}
static T_4 F_15 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 )
{
T_4 V_12 = V_11 ? V_20 : 0 ;
V_12 |= F_16 ( V_8 ) ;
if ( V_10 != V_15 )
V_12 |= V_28 ;
return V_12 ;
}
static T_4 F_17 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 )
{
T_4 V_12 = V_11 ? V_20 : 0 ;
V_12 |= F_16 ( V_8 ) ;
switch ( V_10 ) {
case V_15 :
break;
case V_29 :
V_12 |= V_30 ;
break;
default:
V_12 |= V_31 ;
break;
}
return V_12 ;
}
static int F_18 ( struct V_32 * V_33 , unsigned V_34 ,
T_5 V_35 , bool V_36 )
{
struct V_37 * V_38 = V_33 -> V_2 -> V_39 ;
int V_40 ;
F_19 ( V_34 >= 4 ) ;
if ( V_36 ) {
F_20 ( F_21 ( V_33 , V_34 ) , V_35 >> 32 ) ;
F_20 ( F_22 ( V_33 , V_34 ) , ( V_41 ) V_35 ) ;
return 0 ;
}
V_40 = F_23 ( V_33 , 6 ) ;
if ( V_40 )
return V_40 ;
F_24 ( V_33 , F_25 ( 1 ) ) ;
F_24 ( V_33 , F_21 ( V_33 , V_34 ) ) ;
F_24 ( V_33 , ( V_41 ) ( V_35 >> 32 ) ) ;
F_24 ( V_33 , F_25 ( 1 ) ) ;
F_24 ( V_33 , F_22 ( V_33 , V_34 ) ) ;
F_24 ( V_33 , ( V_41 ) ( V_35 ) ) ;
F_26 ( V_33 ) ;
return 0 ;
}
static int F_27 ( struct V_42 * V_43 ,
struct V_32 * V_33 ,
bool V_36 )
{
int V_44 , V_40 ;
int V_45 = V_43 -> V_46 / V_47 ;
for ( V_44 = V_45 - 1 ; V_44 >= 0 ; V_44 -- ) {
T_2 V_8 = V_43 -> V_48 [ V_44 ] ;
V_40 = F_18 ( V_33 , V_44 , V_8 , V_36 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static void F_28 ( struct V_49 * V_50 ,
T_5 V_51 ,
T_5 V_52 ,
bool V_53 )
{
struct V_42 * V_43 =
F_29 ( V_50 , struct V_42 , V_54 ) ;
T_1 * V_55 , V_56 ;
unsigned V_57 = V_51 >> V_58 & V_59 ;
unsigned V_18 = V_51 >> V_60 & V_61 ;
unsigned V_12 = V_51 >> V_62 & V_63 ;
unsigned V_64 = V_52 >> V_65 ;
unsigned V_66 , V_44 ;
V_56 = F_8 ( V_43 -> V_54 . V_67 . V_8 ,
V_22 , V_53 ) ;
while ( V_64 ) {
struct V_68 * V_69 = V_43 -> V_70 [ V_57 ] [ V_18 ] ;
V_66 = V_12 + V_64 ;
if ( V_66 > V_71 )
V_66 = V_71 ;
V_55 = F_30 ( V_69 ) ;
for ( V_44 = V_12 ; V_44 < V_66 ; V_44 ++ ) {
V_55 [ V_44 ] = V_56 ;
V_64 -- ;
}
F_31 ( V_55 ) ;
V_12 = 0 ;
if ( ++ V_18 == V_47 ) {
V_57 ++ ;
V_18 = 0 ;
}
}
}
static void F_32 ( struct V_49 * V_50 ,
struct V_72 * V_73 ,
T_5 V_51 ,
enum V_9 V_74 )
{
struct V_42 * V_43 =
F_29 ( V_50 , struct V_42 , V_54 ) ;
T_1 * V_55 ;
unsigned V_57 = V_51 >> V_58 & V_59 ;
unsigned V_18 = V_51 >> V_60 & V_61 ;
unsigned V_12 = V_51 >> V_62 & V_63 ;
struct V_75 V_76 ;
V_55 = NULL ;
F_33 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( F_12 ( V_57 >= V_77 ) )
break;
if ( V_55 == NULL )
V_55 = F_30 ( V_43 -> V_70 [ V_57 ] [ V_18 ] ) ;
V_55 [ V_12 ] =
F_8 ( F_34 ( & V_76 ) ,
V_74 , true ) ;
if ( ++ V_12 == V_71 ) {
F_31 ( V_55 ) ;
V_55 = NULL ;
if ( ++ V_18 == V_47 ) {
V_57 ++ ;
V_18 = 0 ;
}
V_12 = 0 ;
}
}
if ( V_55 )
F_31 ( V_55 ) ;
}
static void F_35 ( struct V_68 * * V_78 )
{
int V_44 ;
if ( V_78 == NULL )
return;
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ )
if ( V_78 [ V_44 ] )
F_36 ( V_78 [ V_44 ] , 0 ) ;
}
static void F_37 ( const struct V_42 * V_43 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_43 -> V_79 ; V_44 ++ ) {
F_35 ( V_43 -> V_70 [ V_44 ] ) ;
F_38 ( V_43 -> V_70 [ V_44 ] ) ;
F_38 ( V_43 -> V_80 [ V_44 ] ) ;
}
F_36 ( V_43 -> V_81 , F_39 ( V_43 -> V_79 << V_65 ) ) ;
}
static void F_40 ( struct V_42 * V_43 )
{
struct V_82 * V_83 = V_43 -> V_54 . V_2 -> V_84 ;
int V_44 , V_85 ;
for ( V_44 = 0 ; V_44 < V_43 -> V_79 ; V_44 ++ ) {
if ( ! V_43 -> V_48 [ V_44 ] )
continue;
F_41 ( V_83 , V_43 -> V_48 [ V_44 ] , V_86 ,
V_87 ) ;
for ( V_85 = 0 ; V_85 < V_47 ; V_85 ++ ) {
T_2 V_8 = V_43 -> V_80 [ V_44 ] [ V_85 ] ;
if ( V_8 )
F_41 ( V_83 , V_8 , V_86 ,
V_87 ) ;
}
}
}
static void F_42 ( struct V_49 * V_50 )
{
struct V_42 * V_43 =
F_29 ( V_50 , struct V_42 , V_54 ) ;
F_43 ( & V_50 -> V_88 ) ;
F_44 ( & V_50 -> V_89 ) ;
F_40 ( V_43 ) ;
F_37 ( V_43 ) ;
}
static struct V_68 * * F_45 ( void )
{
struct V_68 * * V_78 ;
int V_44 ;
V_78 = F_46 ( V_47 , sizeof( struct V_68 * ) , V_90 ) ;
if ( ! V_78 )
return F_47 ( - V_91 ) ;
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
V_78 [ V_44 ] = F_48 ( V_90 ) ;
if ( ! V_78 [ V_44 ] )
goto V_92;
}
return V_78 ;
V_92:
F_35 ( V_78 ) ;
F_38 ( V_78 ) ;
return F_47 ( - V_91 ) ;
}
static int F_49 ( struct V_42 * V_43 ,
const int V_93 )
{
struct V_68 * * V_78 [ V_77 ] ;
int V_44 , V_40 ;
for ( V_44 = 0 ; V_44 < V_93 ; V_44 ++ ) {
V_78 [ V_44 ] = F_45 () ;
if ( F_50 ( V_78 [ V_44 ] ) ) {
V_40 = F_51 ( V_78 [ V_44 ] ) ;
goto V_94;
}
}
for ( V_44 = 0 ; V_44 < V_93 ; V_44 ++ )
V_43 -> V_70 [ V_44 ] = V_78 [ V_44 ] ;
return 0 ;
V_94:
while ( V_44 -- ) {
F_35 ( V_78 [ V_44 ] ) ;
F_38 ( V_78 [ V_44 ] ) ;
}
return V_40 ;
}
static int F_52 ( struct V_42 * V_43 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_43 -> V_79 ; V_44 ++ ) {
V_43 -> V_80 [ V_44 ] = F_46 ( V_47 ,
sizeof( T_2 ) ,
V_90 ) ;
if ( ! V_43 -> V_80 [ V_44 ] )
return - V_91 ;
}
return 0 ;
}
static int F_53 ( struct V_42 * V_43 ,
const int V_93 )
{
V_43 -> V_81 = F_54 ( V_90 , F_39 ( V_93 << V_65 ) ) ;
if ( ! V_43 -> V_81 )
return - V_91 ;
V_43 -> V_79 = 1 << F_39 ( V_93 << V_65 ) ;
F_19 ( V_43 -> V_79 > V_77 ) ;
return 0 ;
}
static int F_55 ( struct V_42 * V_43 ,
const int V_93 )
{
int V_40 ;
V_40 = F_53 ( V_43 , V_93 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_49 ( V_43 , V_93 ) ;
if ( V_40 ) {
F_36 ( V_43 -> V_81 , F_39 ( V_93 << V_65 ) ) ;
return V_40 ;
}
V_43 -> V_46 = V_93 * V_47 ;
V_40 = F_52 ( V_43 ) ;
if ( V_40 )
F_37 ( V_43 ) ;
return V_40 ;
}
static int F_56 ( struct V_42 * V_43 ,
const int V_95 )
{
T_2 V_96 ;
int V_40 ;
V_96 = F_57 ( V_43 -> V_54 . V_2 -> V_84 ,
& V_43 -> V_81 [ V_95 ] , 0 ,
V_86 , V_87 ) ;
V_40 = F_58 ( V_43 -> V_54 . V_2 -> V_84 , V_96 ) ;
if ( V_40 )
return V_40 ;
V_43 -> V_48 [ V_95 ] = V_96 ;
return 0 ;
}
static int F_59 ( struct V_42 * V_43 ,
const int V_95 ,
const int V_97 )
{
T_2 V_98 ;
struct V_68 * V_99 ;
int V_40 ;
V_99 = V_43 -> V_70 [ V_95 ] [ V_97 ] ;
V_98 = F_57 ( V_43 -> V_54 . V_2 -> V_84 ,
V_99 , 0 , V_86 , V_87 ) ;
V_40 = F_58 ( V_43 -> V_54 . V_2 -> V_84 , V_98 ) ;
if ( V_40 )
return V_40 ;
V_43 -> V_80 [ V_95 ] [ V_97 ] = V_98 ;
return 0 ;
}
static int F_60 ( struct V_42 * V_43 , T_5 V_100 )
{
const int V_93 = F_61 ( V_100 , 1 << 30 ) ;
const int V_101 = V_47 * V_93 ;
int V_44 , V_85 , V_40 ;
if ( V_100 % ( 1 << 30 ) )
F_7 ( L_2 , V_100 ) ;
V_40 = F_55 ( V_43 , V_93 ) ;
if ( V_40 )
return V_40 ;
for ( V_44 = 0 ; V_44 < V_93 ; V_44 ++ ) {
V_40 = F_56 ( V_43 , V_44 ) ;
if ( V_40 )
goto V_92;
for ( V_85 = 0 ; V_85 < V_47 ; V_85 ++ ) {
V_40 = F_59 ( V_43 , V_44 , V_85 ) ;
if ( V_40 )
goto V_92;
}
}
for ( V_44 = 0 ; V_44 < V_93 ; V_44 ++ ) {
T_3 * V_102 ;
V_102 = F_30 ( & V_43 -> V_81 [ V_44 ] ) ;
for ( V_85 = 0 ; V_85 < V_47 ; V_85 ++ ) {
T_2 V_8 = V_43 -> V_80 [ V_44 ] [ V_85 ] ;
V_102 [ V_85 ] = F_9 ( V_43 -> V_54 . V_2 , V_8 ,
V_22 ) ;
}
F_31 ( V_102 ) ;
}
V_43 -> V_103 = V_104 ;
V_43 -> V_105 = F_27 ;
V_43 -> V_54 . V_106 = F_28 ;
V_43 -> V_54 . V_107 = F_32 ;
V_43 -> V_54 . V_108 = F_42 ;
V_43 -> V_54 . V_51 = 0 ;
V_43 -> V_54 . V_109 = V_43 -> V_46 * V_71 * V_86 ;
V_43 -> V_54 . V_106 ( & V_43 -> V_54 , 0 , V_43 -> V_54 . V_109 , true ) ;
F_62 ( L_3 ,
V_43 -> V_79 , V_43 -> V_79 - V_93 ) ;
F_62 ( L_4 ,
V_43 -> V_46 ,
( V_43 -> V_46 - V_101 ) + V_100 % ( 1 << 30 ) ) ;
return 0 ;
V_92:
F_40 ( V_43 ) ;
F_37 ( V_43 ) ;
return V_40 ;
}
static void F_63 ( struct V_42 * V_43 , struct V_110 * V_111 )
{
struct V_37 * V_38 = V_43 -> V_54 . V_2 -> V_39 ;
struct V_49 * V_50 = & V_43 -> V_54 ;
T_4 T_6 * V_96 ;
T_4 V_56 ;
T_7 V_112 ;
int V_12 , V_18 ;
V_56 = V_50 -> V_113 ( V_50 -> V_67 . V_8 , V_22 , true ) ;
V_96 = ( T_4 T_6 * ) V_38 -> V_114 . V_115 +
V_43 -> V_116 / sizeof( T_4 ) ;
F_64 ( V_111 , L_5 , V_50 ,
V_43 -> V_116 , V_43 -> V_116 + V_43 -> V_46 ) ;
for ( V_18 = 0 ; V_18 < V_43 -> V_46 ; V_18 ++ ) {
V_41 V_117 ;
T_4 * V_55 ;
T_2 V_98 = V_43 -> V_118 [ V_18 ] ;
V_112 = F_65 ( V_96 + V_18 ) ;
V_117 = ( F_66 ( V_98 ) | V_119 ) ;
if ( V_112 != V_117 )
F_64 ( V_111 , L_6 ,
V_18 ,
V_112 ,
V_117 ) ;
F_64 ( V_111 , L_7 , V_112 ) ;
V_55 = F_30 ( V_43 -> V_78 [ V_18 ] ) ;
for ( V_12 = 0 ; V_12 < V_120 ; V_12 += 4 ) {
unsigned long V_121 =
( V_18 * V_86 * V_120 ) +
( V_12 * V_86 ) ;
int V_44 ;
bool V_122 = false ;
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ )
if ( V_55 [ V_12 + V_44 ] != V_56 )
V_122 = true ;
if ( ! V_122 )
continue;
F_64 ( V_111 , L_8 , V_121 , V_18 , V_12 ) ;
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ ) {
if ( V_55 [ V_12 + V_44 ] != V_56 )
F_64 ( V_111 , L_9 , V_55 [ V_12 + V_44 ] ) ;
else
F_67 ( V_111 , L_10 ) ;
}
F_67 ( V_111 , L_11 ) ;
}
F_31 ( V_55 ) ;
}
}
static void F_68 ( struct V_42 * V_43 )
{
struct V_37 * V_38 = V_43 -> V_54 . V_2 -> V_39 ;
T_4 T_6 * V_96 ;
T_7 V_112 ;
int V_44 ;
F_12 ( V_43 -> V_116 & 0x3f ) ;
V_96 = ( T_4 T_6 * ) V_38 -> V_114 . V_115 +
V_43 -> V_116 / sizeof( T_4 ) ;
for ( V_44 = 0 ; V_44 < V_43 -> V_46 ; V_44 ++ ) {
T_2 V_98 ;
V_98 = V_43 -> V_118 [ V_44 ] ;
V_112 = F_66 ( V_98 ) ;
V_112 |= V_119 ;
F_69 ( V_112 , V_96 + V_44 ) ;
}
F_65 ( V_96 ) ;
}
static T_7 F_70 ( struct V_42 * V_43 )
{
F_19 ( V_43 -> V_116 & 0x3f ) ;
return ( V_43 -> V_116 / 64 ) << 16 ;
}
static int F_71 ( struct V_42 * V_43 ,
struct V_32 * V_33 ,
bool V_36 )
{
struct V_1 * V_2 = V_43 -> V_54 . V_2 ;
struct V_37 * V_38 = V_2 -> V_39 ;
int V_40 ;
if ( V_36 ||
F_72 ( & V_38 -> V_123 ) ) {
F_12 ( V_43 != V_38 -> V_89 . V_124 ) ;
F_20 ( F_73 ( V_33 ) , V_125 ) ;
F_20 ( F_74 ( V_33 ) , F_70 ( V_43 ) ) ;
F_75 ( F_74 ( V_33 ) ) ;
return 0 ;
}
V_40 = V_33 -> V_126 ( V_33 , V_127 , V_127 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_23 ( V_33 , 6 ) ;
if ( V_40 )
return V_40 ;
F_24 ( V_33 , F_25 ( 2 ) ) ;
F_24 ( V_33 , F_73 ( V_33 ) ) ;
F_24 ( V_33 , V_125 ) ;
F_24 ( V_33 , F_74 ( V_33 ) ) ;
F_24 ( V_33 , F_70 ( V_43 ) ) ;
F_24 ( V_33 , V_128 ) ;
F_26 ( V_33 ) ;
return 0 ;
}
static int F_76 ( struct V_42 * V_43 ,
struct V_32 * V_33 ,
bool V_36 )
{
struct V_1 * V_2 = V_43 -> V_54 . V_2 ;
struct V_37 * V_38 = V_2 -> V_39 ;
int V_40 ;
if ( V_36 ||
F_72 ( & V_38 -> V_123 ) ) {
F_12 ( V_43 != V_38 -> V_89 . V_124 ) ;
F_20 ( F_73 ( V_33 ) , V_125 ) ;
F_20 ( F_74 ( V_33 ) , F_70 ( V_43 ) ) ;
F_75 ( F_74 ( V_33 ) ) ;
return 0 ;
}
V_40 = V_33 -> V_126 ( V_33 , V_127 , V_127 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_23 ( V_33 , 6 ) ;
if ( V_40 )
return V_40 ;
F_24 ( V_33 , F_25 ( 2 ) ) ;
F_24 ( V_33 , F_73 ( V_33 ) ) ;
F_24 ( V_33 , V_125 ) ;
F_24 ( V_33 , F_74 ( V_33 ) ) ;
F_24 ( V_33 , F_70 ( V_43 ) ) ;
F_24 ( V_33 , V_128 ) ;
F_26 ( V_33 ) ;
if ( V_33 -> V_129 != V_130 ) {
V_40 = V_33 -> V_126 ( V_33 , V_127 , V_127 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_77 ( struct V_42 * V_43 ,
struct V_32 * V_33 ,
bool V_36 )
{
struct V_1 * V_2 = V_43 -> V_54 . V_2 ;
struct V_37 * V_38 = V_2 -> V_39 ;
if ( ! V_36 )
return 0 ;
F_20 ( F_73 ( V_33 ) , V_125 ) ;
F_20 ( F_74 ( V_33 ) , F_70 ( V_43 ) ) ;
F_75 ( F_73 ( V_33 ) ) ;
return 0 ;
}
static int V_104 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_54 . V_2 ;
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_32 * V_33 ;
int V_85 , V_40 ;
F_78 (ring, dev_priv, j) {
F_20 ( F_79 ( V_33 ) ,
F_80 ( V_131 ) ) ;
if ( F_81 ( V_2 ) )
continue;
V_40 = V_43 -> V_105 ( V_43 , V_33 , true ) ;
if ( V_40 )
goto V_132;
}
return 0 ;
V_132:
F_78 (ring, dev_priv, j)
F_20 ( F_79 ( V_33 ) ,
F_82 ( V_131 ) ) ;
return V_40 ;
}
static int F_83 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_54 . V_2 ;
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_32 * V_33 ;
T_7 V_133 , V_134 ;
int V_44 ;
V_134 = F_84 ( V_135 ) ;
F_20 ( V_135 , V_134 | V_136 ) ;
V_133 = F_84 ( V_137 ) ;
if ( F_85 ( V_2 ) ) {
V_133 |= V_138 ;
} else {
V_133 |= V_139 ;
V_133 &= ~ V_140 ;
}
F_20 ( V_137 , V_133 ) ;
F_78 (ring, dev_priv, i) {
int V_40 ;
F_20 ( F_79 ( V_33 ) ,
F_80 ( V_131 ) ) ;
if ( F_81 ( V_2 ) )
continue;
V_40 = V_43 -> V_105 ( V_43 , V_33 , true ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_86 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_54 . V_2 ;
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_32 * V_33 ;
T_7 V_133 , V_141 , V_134 ;
int V_44 ;
V_134 = F_84 ( V_135 ) ;
F_20 ( V_135 , V_134 | V_142 |
V_136 ) ;
V_141 = F_84 ( V_143 ) ;
F_20 ( V_143 , V_141 | V_144 ) ;
V_133 = F_84 ( V_137 ) ;
F_20 ( V_137 , V_133 | V_145 | V_146 ) ;
F_20 ( V_147 , F_80 ( V_131 ) ) ;
F_78 (ring, dev_priv, i) {
int V_40 = V_43 -> V_105 ( V_43 , V_33 , true ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static void F_87 ( struct V_49 * V_50 ,
T_5 V_51 ,
T_5 V_52 ,
bool V_53 )
{
struct V_42 * V_43 =
F_29 ( V_50 , struct V_42 , V_54 ) ;
T_4 * V_55 , V_56 ;
unsigned V_148 = V_51 >> V_65 ;
unsigned V_64 = V_52 >> V_65 ;
unsigned V_149 = V_148 / V_120 ;
unsigned V_150 = V_148 % V_120 ;
unsigned V_66 , V_44 ;
V_56 = V_50 -> V_113 ( V_50 -> V_67 . V_8 , V_22 , true ) ;
while ( V_64 ) {
V_66 = V_150 + V_64 ;
if ( V_66 > V_120 )
V_66 = V_120 ;
V_55 = F_30 ( V_43 -> V_78 [ V_149 ] ) ;
for ( V_44 = V_150 ; V_44 < V_66 ; V_44 ++ )
V_55 [ V_44 ] = V_56 ;
F_31 ( V_55 ) ;
V_64 -= V_66 - V_150 ;
V_150 = 0 ;
V_149 ++ ;
}
}
static void F_88 ( struct V_49 * V_50 ,
struct V_72 * V_73 ,
T_5 V_51 ,
enum V_9 V_74 )
{
struct V_42 * V_43 =
F_29 ( V_50 , struct V_42 , V_54 ) ;
T_4 * V_55 ;
unsigned V_148 = V_51 >> V_65 ;
unsigned V_149 = V_148 / V_120 ;
unsigned V_151 = V_148 % V_120 ;
struct V_75 V_76 ;
V_55 = NULL ;
F_33 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_55 == NULL )
V_55 = F_30 ( V_43 -> V_78 [ V_149 ] ) ;
V_55 [ V_151 ] =
V_50 -> V_113 ( F_34 ( & V_76 ) ,
V_74 , true ) ;
if ( ++ V_151 == V_120 ) {
F_31 ( V_55 ) ;
V_55 = NULL ;
V_149 ++ ;
V_151 = 0 ;
}
}
if ( V_55 )
F_31 ( V_55 ) ;
}
static void F_89 ( struct V_42 * V_43 )
{
int V_44 ;
if ( V_43 -> V_118 ) {
for ( V_44 = 0 ; V_44 < V_43 -> V_46 ; V_44 ++ )
F_41 ( V_43 -> V_54 . V_2 -> V_84 ,
V_43 -> V_118 [ V_44 ] ,
4096 , V_87 ) ;
}
}
static void F_90 ( struct V_42 * V_43 )
{
int V_44 ;
F_38 ( V_43 -> V_118 ) ;
for ( V_44 = 0 ; V_44 < V_43 -> V_46 ; V_44 ++ )
F_91 ( V_43 -> V_78 [ V_44 ] ) ;
F_38 ( V_43 -> V_78 ) ;
}
static void F_92 ( struct V_49 * V_50 )
{
struct V_42 * V_43 =
F_29 ( V_50 , struct V_42 , V_54 ) ;
F_43 ( & V_50 -> V_88 ) ;
F_44 ( & V_43 -> V_54 . V_89 ) ;
F_93 ( & V_43 -> V_152 ) ;
F_89 ( V_43 ) ;
F_90 ( V_43 ) ;
}
static int F_94 ( struct V_42 * V_43 )
{
#define F_95 (PAGE_SIZE * 16)
#define F_96 (GEN6_PPGTT_PD_ENTRIES * PAGE_SIZE)
struct V_1 * V_2 = V_43 -> V_54 . V_2 ;
struct V_37 * V_38 = V_2 -> V_39 ;
bool V_153 = false ;
int V_40 ;
F_19 ( ! F_97 ( & V_38 -> V_114 . V_54 . V_89 ) ) ;
V_154:
V_40 = F_98 ( & V_38 -> V_114 . V_54 . V_89 ,
& V_43 -> V_152 , F_96 ,
F_95 , 0 ,
0 , V_38 -> V_114 . V_54 . V_109 ,
V_155 ,
V_156 ) ;
if ( V_40 == - V_157 && ! V_153 ) {
V_40 = F_99 ( V_2 , & V_38 -> V_114 . V_54 ,
F_96 , F_95 ,
V_15 ,
0 , V_38 -> V_114 . V_54 . V_109 ,
0 ) ;
if ( V_40 )
return V_40 ;
V_153 = true ;
goto V_154;
}
if ( V_43 -> V_152 . V_51 < V_38 -> V_114 . V_158 )
F_100 ( L_12 ) ;
V_43 -> V_46 = V_159 ;
return V_40 ;
}
static int F_101 ( struct V_42 * V_43 )
{
int V_44 ;
V_43 -> V_78 = F_46 ( V_43 -> V_46 , sizeof( struct V_68 * ) ,
V_90 ) ;
if ( ! V_43 -> V_78 )
return - V_91 ;
for ( V_44 = 0 ; V_44 < V_43 -> V_46 ; V_44 ++ ) {
V_43 -> V_78 [ V_44 ] = F_48 ( V_90 ) ;
if ( ! V_43 -> V_78 [ V_44 ] ) {
F_90 ( V_43 ) ;
return - V_91 ;
}
}
return 0 ;
}
static int F_102 ( struct V_42 * V_43 )
{
int V_40 ;
V_40 = F_94 ( V_43 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_101 ( V_43 ) ;
if ( V_40 ) {
F_93 ( & V_43 -> V_152 ) ;
return V_40 ;
}
V_43 -> V_118 = F_46 ( V_43 -> V_46 , sizeof( T_2 ) ,
V_90 ) ;
if ( ! V_43 -> V_118 ) {
F_93 ( & V_43 -> V_152 ) ;
F_90 ( V_43 ) ;
return - V_91 ;
}
return 0 ;
}
static int F_103 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_54 . V_2 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_43 -> V_46 ; V_44 ++ ) {
T_2 V_98 ;
V_98 = F_57 ( V_2 -> V_84 , V_43 -> V_78 [ V_44 ] , 0 , 4096 ,
V_87 ) ;
if ( F_58 ( V_2 -> V_84 , V_98 ) ) {
F_89 ( V_43 ) ;
return - V_160 ;
}
V_43 -> V_118 [ V_44 ] = V_98 ;
}
return 0 ;
}
static int F_104 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_54 . V_2 ;
struct V_37 * V_38 = V_2 -> V_39 ;
int V_40 ;
V_43 -> V_54 . V_113 = V_38 -> V_114 . V_54 . V_113 ;
if ( F_105 ( V_2 ) ) {
V_43 -> V_103 = F_86 ;
V_43 -> V_105 = F_77 ;
} else if ( F_85 ( V_2 ) ) {
V_43 -> V_103 = F_83 ;
V_43 -> V_105 = F_71 ;
} else if ( F_106 ( V_2 ) ) {
V_43 -> V_103 = F_83 ;
V_43 -> V_105 = F_76 ;
} else
F_107 () ;
V_40 = F_102 ( V_43 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_103 ( V_43 ) ;
if ( V_40 ) {
F_90 ( V_43 ) ;
return V_40 ;
}
V_43 -> V_54 . V_106 = F_87 ;
V_43 -> V_54 . V_107 = F_88 ;
V_43 -> V_54 . V_108 = F_92 ;
V_43 -> V_54 . V_51 = 0 ;
V_43 -> V_54 . V_109 = V_43 -> V_46 * V_120 * V_86 ;
V_43 -> V_161 = F_63 ;
V_43 -> V_116 =
V_43 -> V_152 . V_51 / V_86 * sizeof( T_4 ) ;
V_43 -> V_54 . V_106 ( & V_43 -> V_54 , 0 , V_43 -> V_54 . V_109 , true ) ;
F_62 ( L_13 ,
V_43 -> V_152 . V_100 >> 20 ,
V_43 -> V_152 . V_51 / V_86 ) ;
return 0 ;
}
int F_108 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
int V_40 = 0 ;
V_43 -> V_54 . V_2 = V_2 ;
V_43 -> V_54 . V_67 = V_38 -> V_114 . V_54 . V_67 ;
if ( F_6 ( V_2 ) -> V_6 < 8 )
V_40 = F_104 ( V_43 ) ;
else if ( F_109 ( V_2 ) )
V_40 = F_60 ( V_43 , V_38 -> V_114 . V_54 . V_109 ) ;
else
F_107 () ;
if ( ! V_40 ) {
struct V_37 * V_38 = V_2 -> V_39 ;
F_110 ( & V_43 -> V_162 ) ;
F_111 ( & V_43 -> V_54 . V_89 , V_43 -> V_54 . V_51 ,
V_43 -> V_54 . V_109 ) ;
F_112 ( V_38 , & V_43 -> V_54 ) ;
if ( F_6 ( V_2 ) -> V_6 < 8 ) {
F_68 ( V_43 ) ;
F_100 ( L_14 ,
V_43 -> V_116 << 10 ) ;
}
}
return V_40 ;
}
static void
F_113 ( struct V_163 * V_164 ,
enum V_9 V_74 ,
V_41 V_165 )
{
V_164 -> V_50 -> V_107 ( V_164 -> V_50 , V_164 -> V_166 -> V_73 , V_164 -> V_152 . V_51 ,
V_74 ) ;
}
static void F_114 ( struct V_163 * V_164 )
{
V_164 -> V_50 -> V_106 ( V_164 -> V_50 ,
V_164 -> V_152 . V_51 ,
V_164 -> V_166 -> V_54 . V_100 ,
true ) ;
}
static inline bool F_115 ( struct V_1 * V_2 )
{
#ifdef F_5
if ( F_116 ( V_2 ) && F_117 ( V_2 ) && V_7 )
return true ;
#endif
return false ;
}
static bool F_118 ( struct V_37 * V_38 )
{
bool V_40 = V_38 -> V_89 . V_167 ;
if ( F_119 ( V_38 -> V_114 . V_168 ) ) {
V_38 -> V_89 . V_167 = false ;
if ( F_120 ( V_38 -> V_2 ) ) {
F_121 ( L_15 ) ;
F_122 ( 10 ) ;
}
}
return V_40 ;
}
static void F_123 ( struct V_37 * V_38 , bool V_167 )
{
if ( F_119 ( V_38 -> V_114 . V_168 ) )
V_38 -> V_89 . V_167 = V_167 ;
}
void F_124 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_32 * V_33 ;
int V_44 ;
if ( F_6 ( V_2 ) -> V_6 < 6 )
return;
F_78 (ring, dev_priv, i) {
V_41 V_169 ;
V_169 = F_84 ( F_125 ( V_33 ) ) ;
if ( V_169 & V_170 ) {
F_62 ( L_16
L_17
L_18
L_19
L_20 ,
V_169 & V_171 ,
V_169 & V_172 ? L_21 : L_22 ,
F_126 ( V_169 ) ,
F_127 ( V_169 ) ) ;
F_20 ( F_125 ( V_33 ) ,
V_169 & ~ V_170 ) ;
}
}
F_75 ( F_125 ( & V_38 -> V_33 [ V_130 ] ) ) ;
}
void F_128 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
if ( F_6 ( V_2 ) -> V_6 < 6 )
return;
F_124 ( V_2 ) ;
V_38 -> V_114 . V_54 . V_106 ( & V_38 -> V_114 . V_54 ,
V_38 -> V_114 . V_54 . V_51 ,
V_38 -> V_114 . V_54 . V_109 ,
true ) ;
}
void F_129 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_173 * V_166 ;
struct V_49 * V_50 ;
F_124 ( V_2 ) ;
V_38 -> V_114 . V_54 . V_106 ( & V_38 -> V_114 . V_54 ,
V_38 -> V_114 . V_54 . V_51 ,
V_38 -> V_114 . V_54 . V_109 ,
true ) ;
F_130 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_163 * V_164 = F_131 ( V_166 ,
& V_38 -> V_114 . V_54 ) ;
if ( ! V_164 )
continue;
F_132 ( V_166 , V_166 -> V_174 ) ;
V_166 -> V_175 = 0 ;
V_164 -> V_176 ( V_164 , V_166 -> V_74 , V_177 ) ;
}
if ( F_6 ( V_2 ) -> V_6 >= 8 ) {
F_133 ( V_38 ) ;
return;
}
F_130 (vm, &dev_priv->vm_list, global_link) {
if ( F_134 ( V_50 ) ) {
if ( V_38 -> V_89 . V_124 )
F_68 ( V_38 -> V_89 . V_124 ) ;
continue;
}
F_68 ( F_29 ( V_50 , struct V_42 , V_54 ) ) ;
}
F_135 ( V_2 ) ;
}
int F_136 ( struct V_173 * V_166 )
{
if ( V_166 -> V_178 )
return 0 ;
if ( ! F_137 ( & V_166 -> V_54 . V_2 -> V_84 -> V_2 ,
V_166 -> V_73 -> V_179 , V_166 -> V_73 -> V_180 ,
V_87 ) )
return - V_157 ;
return 0 ;
}
static inline void F_138 ( void T_6 * V_8 , T_1 V_12 )
{
#ifdef F_139
F_139 ( V_12 , V_8 ) ;
#else
F_140 ( ( V_41 ) V_12 , V_8 ) ;
F_140 ( V_12 >> 32 , V_8 + 4 ) ;
#endif
}
static void F_141 ( struct V_49 * V_50 ,
struct V_72 * V_181 ,
T_5 V_51 ,
enum V_9 V_10 )
{
struct V_37 * V_38 = V_50 -> V_2 -> V_39 ;
unsigned V_148 = V_51 >> V_65 ;
T_1 T_6 * V_182 =
( T_1 T_6 * ) V_38 -> V_114 . V_115 + V_148 ;
int V_44 = 0 ;
struct V_75 V_76 ;
T_2 V_8 ;
F_33 (st->sgl, &sg_iter, st->nents, 0 ) {
V_8 = F_142 ( V_76 . V_183 ) +
( V_76 . V_184 << V_65 ) ;
F_138 ( & V_182 [ V_44 ] ,
F_8 ( V_8 , V_10 , true ) ) ;
V_44 ++ ;
}
if ( V_44 != 0 )
F_12 ( F_143 ( & V_182 [ V_44 - 1 ] )
!= F_8 ( V_8 , V_10 , true ) ) ;
F_20 ( V_185 , V_186 ) ;
F_75 ( V_185 ) ;
}
static void F_144 ( struct V_49 * V_50 ,
struct V_72 * V_181 ,
T_5 V_51 ,
enum V_9 V_10 )
{
struct V_37 * V_38 = V_50 -> V_2 -> V_39 ;
unsigned V_148 = V_51 >> V_65 ;
T_4 T_6 * V_182 =
( T_4 T_6 * ) V_38 -> V_114 . V_115 + V_148 ;
int V_44 = 0 ;
struct V_75 V_76 ;
T_2 V_8 ;
F_33 (st->sgl, &sg_iter, st->nents, 0 ) {
V_8 = F_34 ( & V_76 ) ;
F_140 ( V_50 -> V_113 ( V_8 , V_10 , true ) , & V_182 [ V_44 ] ) ;
V_44 ++ ;
}
if ( V_44 != 0 )
F_12 ( F_65 ( & V_182 [ V_44 - 1 ] ) !=
V_50 -> V_113 ( V_8 , V_10 , true ) ) ;
F_20 ( V_185 , V_186 ) ;
F_75 ( V_185 ) ;
}
static void F_145 ( struct V_49 * V_50 ,
T_5 V_51 ,
T_5 V_52 ,
bool V_53 )
{
struct V_37 * V_38 = V_50 -> V_2 -> V_39 ;
unsigned V_148 = V_51 >> V_65 ;
unsigned V_64 = V_52 >> V_65 ;
T_1 V_56 , T_6 * V_187 =
( T_1 T_6 * ) V_38 -> V_114 . V_115 + V_148 ;
const int V_188 = F_146 ( V_38 -> V_114 ) - V_148 ;
int V_44 ;
if ( F_147 ( V_64 > V_188 ,
L_23 ,
V_148 , V_64 , V_188 ) )
V_64 = V_188 ;
V_56 = F_8 ( V_50 -> V_67 . V_8 ,
V_22 ,
V_53 ) ;
for ( V_44 = 0 ; V_44 < V_64 ; V_44 ++ )
F_138 ( & V_187 [ V_44 ] , V_56 ) ;
F_65 ( V_187 ) ;
}
static void F_148 ( struct V_49 * V_50 ,
T_5 V_51 ,
T_5 V_52 ,
bool V_53 )
{
struct V_37 * V_38 = V_50 -> V_2 -> V_39 ;
unsigned V_148 = V_51 >> V_65 ;
unsigned V_64 = V_52 >> V_65 ;
T_4 V_56 , T_6 * V_187 =
( T_4 T_6 * ) V_38 -> V_114 . V_115 + V_148 ;
const int V_188 = F_146 ( V_38 -> V_114 ) - V_148 ;
int V_44 ;
if ( F_147 ( V_64 > V_188 ,
L_23 ,
V_148 , V_64 , V_188 ) )
V_64 = V_188 ;
V_56 = V_50 -> V_113 ( V_50 -> V_67 . V_8 , V_22 , V_53 ) ;
for ( V_44 = 0 ; V_44 < V_64 ; V_44 ++ )
F_140 ( V_56 , & V_187 [ V_44 ] ) ;
F_65 ( V_187 ) ;
}
static void F_149 ( struct V_163 * V_164 ,
enum V_9 V_74 ,
V_41 V_189 )
{
const unsigned long V_34 = V_164 -> V_152 . V_51 >> V_65 ;
unsigned int V_165 = ( V_74 == V_15 ) ?
V_190 : V_191 ;
F_19 ( ! F_134 ( V_164 -> V_50 ) ) ;
F_150 ( V_164 -> V_166 -> V_73 , V_34 , V_165 ) ;
V_164 -> V_166 -> V_175 = 1 ;
}
static void F_151 ( struct V_49 * V_50 ,
T_5 V_51 ,
T_5 V_52 ,
bool V_189 )
{
unsigned V_148 = V_51 >> V_65 ;
unsigned V_64 = V_52 >> V_65 ;
F_152 ( V_148 , V_64 ) ;
}
static void F_153 ( struct V_163 * V_164 )
{
const unsigned int V_192 = V_164 -> V_152 . V_51 >> V_65 ;
const unsigned int V_100 = V_164 -> V_166 -> V_54 . V_100 >> V_65 ;
F_19 ( ! F_134 ( V_164 -> V_50 ) ) ;
V_164 -> V_166 -> V_175 = 0 ;
F_152 ( V_192 , V_100 ) ;
}
static void F_154 ( struct V_163 * V_164 ,
enum V_9 V_74 ,
V_41 V_165 )
{
struct V_1 * V_2 = V_164 -> V_50 -> V_2 ;
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_173 * V_166 = V_164 -> V_166 ;
if ( ! V_38 -> V_89 . V_124 || V_165 & V_177 ) {
if ( ! V_166 -> V_175 ||
( V_74 != V_166 -> V_74 ) ) {
V_164 -> V_50 -> V_107 ( V_164 -> V_50 , V_166 -> V_73 ,
V_164 -> V_152 . V_51 ,
V_74 ) ;
V_166 -> V_175 = 1 ;
}
}
if ( V_38 -> V_89 . V_124 &&
( ! V_166 -> V_193 ||
( V_74 != V_166 -> V_74 ) ) ) {
struct V_42 * V_194 = V_38 -> V_89 . V_124 ;
V_194 -> V_54 . V_107 ( & V_194 -> V_54 ,
V_164 -> V_166 -> V_73 ,
V_164 -> V_152 . V_51 ,
V_74 ) ;
V_164 -> V_166 -> V_193 = 1 ;
}
}
static void F_155 ( struct V_163 * V_164 )
{
struct V_1 * V_2 = V_164 -> V_50 -> V_2 ;
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_173 * V_166 = V_164 -> V_166 ;
if ( V_166 -> V_175 ) {
V_164 -> V_50 -> V_106 ( V_164 -> V_50 ,
V_164 -> V_152 . V_51 ,
V_166 -> V_54 . V_100 ,
true ) ;
V_166 -> V_175 = 0 ;
}
if ( V_166 -> V_193 ) {
struct V_42 * V_194 = V_38 -> V_89 . V_124 ;
V_194 -> V_54 . V_106 ( & V_194 -> V_54 ,
V_164 -> V_152 . V_51 ,
V_166 -> V_54 . V_100 ,
true ) ;
V_166 -> V_193 = 0 ;
}
}
void F_156 ( struct V_173 * V_166 )
{
struct V_1 * V_2 = V_166 -> V_54 . V_2 ;
struct V_37 * V_38 = V_2 -> V_39 ;
bool V_167 ;
V_167 = F_118 ( V_38 ) ;
if ( ! V_166 -> V_178 )
F_157 ( & V_2 -> V_84 -> V_2 ,
V_166 -> V_73 -> V_179 , V_166 -> V_73 -> V_180 ,
V_87 ) ;
F_123 ( V_38 , V_167 ) ;
}
static void F_158 ( struct V_195 * V_152 ,
unsigned long V_196 ,
unsigned long * V_51 ,
unsigned long * V_197 )
{
if ( V_152 -> V_196 != V_196 )
* V_51 += 4096 ;
if ( ! F_159 ( & V_152 -> V_198 ) ) {
V_152 = F_160 ( V_152 -> V_198 . V_199 ,
struct V_195 ,
V_198 ) ;
if ( V_152 -> V_200 && V_152 -> V_196 != V_196 )
* V_197 -= 4096 ;
}
}
void F_161 ( struct V_1 * V_2 ,
unsigned long V_51 ,
unsigned long V_158 ,
unsigned long V_197 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_49 * V_201 = & V_38 -> V_114 . V_54 ;
struct V_195 * V_34 ;
struct V_173 * V_166 ;
unsigned long V_202 , V_203 ;
F_19 ( V_158 > V_197 ) ;
F_111 ( & V_201 -> V_89 , V_51 , V_197 - V_51 - V_86 ) ;
if ( ! F_162 ( V_2 ) )
V_38 -> V_114 . V_54 . V_89 . V_204 = F_158 ;
F_130 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_163 * V_164 = F_131 ( V_166 , V_201 ) ;
int V_40 ;
F_163 ( L_24 ,
F_164 ( V_166 ) , V_166 -> V_54 . V_100 ) ;
F_12 ( F_165 ( V_166 ) ) ;
V_40 = F_166 ( & V_201 -> V_89 , & V_164 -> V_152 ) ;
if ( V_40 )
F_163 ( L_25 ) ;
V_166 -> V_175 = 1 ;
}
V_38 -> V_114 . V_54 . V_51 = V_51 ;
V_38 -> V_114 . V_54 . V_109 = V_197 - V_51 ;
F_167 (entry, &ggtt_vm->mm, hole_start, hole_end) {
F_163 ( L_26 ,
V_202 , V_203 ) ;
V_201 -> V_106 ( V_201 , V_202 ,
V_203 - V_202 , true ) ;
}
V_201 -> V_106 ( V_201 , V_197 - V_86 , V_86 , true ) ;
}
void F_168 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
unsigned long V_205 , V_206 ;
V_205 = V_38 -> V_114 . V_54 . V_109 ;
V_206 = V_38 -> V_114 . V_158 ;
F_161 ( V_2 , 0 , V_206 , V_205 ) ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_68 * V_68 ;
T_2 V_207 ;
V_68 = F_48 ( V_90 | V_208 | V_209 ) ;
if ( V_68 == NULL )
return - V_91 ;
F_170 ( V_68 ) ;
F_171 ( V_68 , 1 ) ;
#ifdef F_5
V_207 = F_57 ( V_2 -> V_84 , V_68 , 0 , V_86 ,
V_87 ) ;
if ( F_58 ( V_2 -> V_84 , V_207 ) )
return - V_210 ;
#else
V_207 = F_172 ( V_68 ) ;
#endif
V_38 -> V_114 . V_54 . V_67 . V_68 = V_68 ;
V_38 -> V_114 . V_54 . V_67 . V_8 = V_207 ;
return 0 ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_68 * V_68 = V_38 -> V_114 . V_54 . V_67 . V_68 ;
F_174 ( V_68 , 1 ) ;
F_41 ( V_2 -> V_84 , V_38 -> V_114 . V_54 . V_67 . V_8 ,
V_86 , V_87 ) ;
F_175 ( V_68 ) ;
F_91 ( V_68 ) ;
}
static inline unsigned int F_176 ( T_8 V_211 )
{
V_211 >>= V_212 ;
V_211 &= V_213 ;
return V_211 << 20 ;
}
static inline unsigned int F_177 ( T_8 V_214 )
{
V_214 >>= V_215 ;
V_214 &= V_216 ;
if ( V_214 )
V_214 = 1 << V_214 ;
return V_214 << 20 ;
}
static inline T_9 F_178 ( T_8 V_211 )
{
V_211 >>= V_217 ;
V_211 &= V_218 ;
return V_211 << 25 ;
}
static inline T_9 F_179 ( T_8 V_214 )
{
V_214 >>= V_219 ;
V_214 &= V_220 ;
return V_214 << 25 ;
}
static int F_180 ( struct V_1 * V_2 ,
T_9 V_205 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
T_10 V_221 ;
int V_40 ;
V_221 = F_181 ( V_2 -> V_84 , 0 ) +
( F_182 ( V_2 -> V_84 , 0 ) / 2 ) ;
V_38 -> V_114 . V_115 = F_183 ( V_221 , V_205 ) ;
if ( ! V_38 -> V_114 . V_115 ) {
F_121 ( L_27 ) ;
return - V_91 ;
}
V_40 = F_169 ( V_2 ) ;
if ( V_40 ) {
F_121 ( L_28 ) ;
F_184 ( V_38 -> V_114 . V_115 ) ;
}
return V_40 ;
}
static void F_133 ( struct V_37 * V_38 )
{
#define F_185 (0<<0)
#define F_186 (1<<0)
#define F_187 (2<<0)
#define F_188 (3<<0)
#define F_189 (0<<2)
#define F_190 (1<<2)
#define F_191 (2<<2)
#define F_192 (3<<2)
#define F_193 ( T_11 ) (x<<4)
#define F_194 ( V_44 , T_11 ) ((uint64_t) (x) << ((i) * 8))
T_5 V_222 ;
V_222 = F_194 ( 0 , F_188 | F_190 ) |
F_194 ( 1 , F_186 | F_191 ) |
F_194 ( 2 , F_187 | F_191 ) |
F_194 ( 3 , F_185 ) |
F_194 ( 4 , F_188 | F_191 | F_193 ( 0 ) ) |
F_194 ( 5 , F_188 | F_191 | F_193 ( 1 ) ) |
F_194 ( 6 , F_188 | F_191 | F_193 ( 2 ) ) |
F_194 ( 7 , F_188 | F_191 | F_193 ( 3 ) ) ;
F_20 ( V_223 , V_222 ) ;
F_20 ( V_223 + 4 , V_222 >> 32 ) ;
}
static int F_195 ( struct V_1 * V_2 ,
T_9 * V_224 ,
T_9 * V_225 ,
T_10 * V_226 ,
unsigned long * V_158 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
unsigned int V_205 ;
T_8 V_211 ;
int V_40 ;
* V_226 = F_181 ( V_2 -> V_84 , 2 ) ;
* V_158 = F_182 ( V_2 -> V_84 , 2 ) ;
if ( ! F_196 ( V_2 -> V_84 , F_197 ( 39 ) ) )
F_198 ( V_2 -> V_84 , F_197 ( 39 ) ) ;
F_199 ( V_2 -> V_84 , V_227 , & V_211 ) ;
* V_225 = F_179 ( V_211 ) ;
V_205 = F_177 ( V_211 ) ;
* V_224 = ( V_205 / sizeof( T_1 ) ) << V_65 ;
F_133 ( V_38 ) ;
V_40 = F_180 ( V_2 , V_205 ) ;
V_38 -> V_114 . V_54 . V_106 = F_145 ;
V_38 -> V_114 . V_54 . V_107 = F_141 ;
return V_40 ;
}
static int F_200 ( struct V_1 * V_2 ,
T_9 * V_224 ,
T_9 * V_225 ,
T_10 * V_226 ,
unsigned long * V_158 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
unsigned int V_205 ;
T_8 V_211 ;
int V_40 ;
* V_226 = F_181 ( V_2 -> V_84 , 2 ) ;
* V_158 = F_182 ( V_2 -> V_84 , 2 ) ;
if ( ( * V_158 < ( 64 << 20 ) || ( * V_158 > ( 512 << 20 ) ) ) ) {
F_121 ( L_29 ,
V_38 -> V_114 . V_158 ) ;
return - V_228 ;
}
if ( ! F_196 ( V_2 -> V_84 , F_197 ( 40 ) ) )
F_198 ( V_2 -> V_84 , F_197 ( 40 ) ) ;
F_199 ( V_2 -> V_84 , V_227 , & V_211 ) ;
* V_225 = F_178 ( V_211 ) ;
V_205 = F_176 ( V_211 ) ;
* V_224 = ( V_205 / sizeof( T_4 ) ) << V_65 ;
V_40 = F_180 ( V_2 , V_205 ) ;
V_38 -> V_114 . V_54 . V_106 = F_148 ;
V_38 -> V_114 . V_54 . V_107 = F_144 ;
return V_40 ;
}
static void F_201 ( struct V_49 * V_50 )
{
struct V_229 * V_114 = F_29 ( V_50 , struct V_229 , V_54 ) ;
F_44 ( & V_50 -> V_89 ) ;
F_184 ( V_114 -> V_115 ) ;
F_173 ( V_50 -> V_2 ) ;
}
static int F_202 ( struct V_1 * V_2 ,
T_9 * V_224 ,
T_9 * V_225 ,
T_10 * V_226 ,
unsigned long * V_158 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
int V_40 ;
V_40 = F_203 ( V_38 -> V_230 , V_38 -> V_2 -> V_84 , NULL ) ;
if ( ! V_40 ) {
F_121 ( L_30 ) ;
return - V_160 ;
}
F_204 ( V_224 , V_225 , V_226 , V_158 ) ;
V_38 -> V_114 . V_168 = F_115 ( V_38 -> V_2 ) ;
V_38 -> V_114 . V_54 . V_106 = F_151 ;
if ( F_119 ( V_38 -> V_114 . V_168 ) )
F_7 ( L_31 ) ;
return 0 ;
}
static void F_205 ( struct V_49 * V_50 )
{
F_206 () ;
}
int F_207 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_229 * V_114 = & V_38 -> V_114 ;
int V_40 ;
if ( F_6 ( V_2 ) -> V_6 <= 5 ) {
V_114 -> V_231 = F_202 ;
V_114 -> V_54 . V_108 = F_205 ;
} else if ( F_6 ( V_2 ) -> V_6 < 8 ) {
V_114 -> V_231 = F_200 ;
V_114 -> V_54 . V_108 = F_201 ;
if ( F_85 ( V_2 ) && V_38 -> V_232 )
V_114 -> V_54 . V_113 = F_17 ;
else if ( F_85 ( V_2 ) )
V_114 -> V_54 . V_113 = F_15 ;
else if ( F_208 ( V_2 ) )
V_114 -> V_54 . V_113 = F_14 ;
else if ( F_6 ( V_2 ) -> V_6 >= 7 )
V_114 -> V_54 . V_113 = F_13 ;
else
V_114 -> V_54 . V_113 = F_10 ;
} else {
V_38 -> V_114 . V_231 = F_195 ;
V_38 -> V_114 . V_54 . V_108 = F_201 ;
}
V_40 = V_114 -> V_231 ( V_2 , & V_114 -> V_54 . V_109 , & V_114 -> V_233 ,
& V_114 -> V_226 , & V_114 -> V_158 ) ;
if ( V_40 )
return V_40 ;
V_114 -> V_54 . V_2 = V_2 ;
F_7 ( L_32 ,
V_114 -> V_54 . V_109 >> 20 ) ;
F_62 ( L_33 , V_114 -> V_158 >> 20 ) ;
F_62 ( L_34 , V_114 -> V_233 >> 20 ) ;
V_4 . V_5 = F_2 ( V_2 , V_4 . V_5 ) ;
F_62 ( L_35 , V_4 . V_5 ) ;
return 0 ;
}
static struct V_163 * F_209 ( struct V_173 * V_166 ,
struct V_49 * V_50 )
{
struct V_163 * V_164 = F_210 ( sizeof( * V_164 ) , V_90 ) ;
if ( V_164 == NULL )
return F_47 ( - V_91 ) ;
F_211 ( & V_164 -> V_234 ) ;
F_211 ( & V_164 -> V_235 ) ;
F_211 ( & V_164 -> V_236 ) ;
V_164 -> V_50 = V_50 ;
V_164 -> V_166 = V_166 ;
switch ( F_6 ( V_50 -> V_2 ) -> V_6 ) {
case 8 :
case 7 :
case 6 :
if ( F_134 ( V_50 ) ) {
V_164 -> V_237 = F_155 ;
V_164 -> V_176 = F_154 ;
} else {
V_164 -> V_237 = F_114 ;
V_164 -> V_176 = F_113 ;
}
break;
case 5 :
case 4 :
case 3 :
case 2 :
F_19 ( ! F_134 ( V_50 ) ) ;
V_164 -> V_237 = F_153 ;
V_164 -> V_176 = F_149 ;
break;
default:
F_107 () ;
}
if ( F_134 ( V_50 ) )
F_212 ( & V_164 -> V_234 , & V_166 -> V_238 ) ;
else
F_213 ( & V_164 -> V_234 , & V_166 -> V_238 ) ;
return V_164 ;
}
struct V_163 *
F_214 ( struct V_173 * V_166 ,
struct V_49 * V_50 )
{
struct V_163 * V_164 ;
V_164 = F_131 ( V_166 , V_50 ) ;
if ( ! V_164 )
V_164 = F_209 ( V_166 , V_50 ) ;
return V_164 ;
}
