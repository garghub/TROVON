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
switch ( V_10 ) {
case V_15 :
V_12 |= V_16 ;
break;
case V_17 :
V_12 |= V_18 ;
break;
default:
V_12 |= V_19 ;
break;
}
return V_12 ;
}
static inline T_3 F_9 ( struct V_1 * V_2 ,
T_2 V_8 ,
enum V_9 V_10 )
{
T_3 V_20 = V_13 | V_14 ;
V_20 |= V_8 ;
if ( V_10 != V_15 )
V_20 |= V_21 ;
else
V_20 |= V_16 ;
return V_20 ;
}
static T_4 F_10 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 )
{
T_4 V_12 = V_11 ? V_22 : 0 ;
V_12 |= F_11 ( V_8 ) ;
switch ( V_10 ) {
case V_23 :
case V_24 :
V_12 |= V_25 ;
break;
case V_15 :
V_12 |= V_26 ;
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
T_4 V_12 = V_11 ? V_22 : 0 ;
V_12 |= F_11 ( V_8 ) ;
switch ( V_10 ) {
case V_23 :
V_12 |= V_27 ;
break;
case V_24 :
V_12 |= V_25 ;
break;
case V_15 :
V_12 |= V_26 ;
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
T_4 V_12 = V_11 ? V_22 : 0 ;
V_12 |= F_11 ( V_8 ) ;
V_12 |= V_28 ;
if ( V_10 != V_15 )
V_12 |= V_29 ;
return V_12 ;
}
static T_4 F_15 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 )
{
T_4 V_12 = V_11 ? V_22 : 0 ;
V_12 |= F_16 ( V_8 ) ;
if ( V_10 != V_15 )
V_12 |= V_30 ;
return V_12 ;
}
static T_4 F_17 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 )
{
T_4 V_12 = V_11 ? V_22 : 0 ;
V_12 |= F_16 ( V_8 ) ;
switch ( V_10 ) {
case V_15 :
break;
case V_17 :
V_12 |= V_31 ;
break;
default:
V_12 |= V_32 ;
break;
}
return V_12 ;
}
static int F_18 ( struct V_33 * V_34 , unsigned V_35 ,
T_5 V_36 , bool V_37 )
{
struct V_38 * V_39 = V_34 -> V_2 -> V_40 ;
int V_41 ;
F_19 ( V_35 >= 4 ) ;
if ( V_37 ) {
F_20 ( F_21 ( V_34 , V_35 ) , V_36 >> 32 ) ;
F_20 ( F_22 ( V_34 , V_35 ) , ( V_42 ) V_36 ) ;
return 0 ;
}
V_41 = F_23 ( V_34 , 6 ) ;
if ( V_41 )
return V_41 ;
F_24 ( V_34 , F_25 ( 1 ) ) ;
F_24 ( V_34 , F_21 ( V_34 , V_35 ) ) ;
F_24 ( V_34 , ( V_42 ) ( V_36 >> 32 ) ) ;
F_24 ( V_34 , F_25 ( 1 ) ) ;
F_24 ( V_34 , F_22 ( V_34 , V_35 ) ) ;
F_24 ( V_34 , ( V_42 ) ( V_36 ) ) ;
F_26 ( V_34 ) ;
return 0 ;
}
static int F_27 ( struct V_43 * V_44 ,
struct V_33 * V_34 ,
bool V_37 )
{
int V_45 , V_41 ;
int V_46 = V_44 -> V_47 / V_48 ;
for ( V_45 = V_46 - 1 ; V_45 >= 0 ; V_45 -- ) {
T_2 V_8 = V_44 -> V_49 [ V_45 ] ;
V_41 = F_18 ( V_34 , V_45 , V_8 , V_37 ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static void F_28 ( struct V_50 * V_51 ,
T_5 V_52 ,
T_5 V_53 ,
bool V_54 )
{
struct V_43 * V_44 =
F_29 ( V_51 , struct V_43 , V_55 ) ;
T_1 * V_56 , V_57 ;
unsigned V_58 = V_52 >> V_59 & V_60 ;
unsigned V_20 = V_52 >> V_61 & V_62 ;
unsigned V_12 = V_52 >> V_63 & V_64 ;
unsigned V_65 = V_53 >> V_66 ;
unsigned V_67 , V_45 ;
V_57 = F_8 ( V_44 -> V_55 . V_68 . V_8 ,
V_24 , V_54 ) ;
while ( V_65 ) {
struct V_69 * V_70 = V_44 -> V_71 [ V_58 ] [ V_20 ] ;
V_67 = V_12 + V_65 ;
if ( V_67 > V_72 )
V_67 = V_72 ;
V_56 = F_30 ( V_70 ) ;
for ( V_45 = V_12 ; V_45 < V_67 ; V_45 ++ ) {
V_56 [ V_45 ] = V_57 ;
V_65 -- ;
}
if ( ! F_31 ( V_44 -> V_55 . V_2 ) )
F_32 ( V_56 , V_73 ) ;
F_33 ( V_56 ) ;
V_12 = 0 ;
if ( ++ V_20 == V_48 ) {
V_58 ++ ;
V_20 = 0 ;
}
}
}
static void F_34 ( struct V_50 * V_51 ,
struct V_74 * V_75 ,
T_5 V_52 ,
enum V_9 V_76 )
{
struct V_43 * V_44 =
F_29 ( V_51 , struct V_43 , V_55 ) ;
T_1 * V_56 ;
unsigned V_58 = V_52 >> V_59 & V_60 ;
unsigned V_20 = V_52 >> V_61 & V_62 ;
unsigned V_12 = V_52 >> V_63 & V_64 ;
struct V_77 V_78 ;
V_56 = NULL ;
F_35 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( F_12 ( V_58 >= V_79 ) )
break;
if ( V_56 == NULL )
V_56 = F_30 ( V_44 -> V_71 [ V_58 ] [ V_20 ] ) ;
V_56 [ V_12 ] =
F_8 ( F_36 ( & V_78 ) ,
V_76 , true ) ;
if ( ++ V_12 == V_72 ) {
if ( ! F_31 ( V_44 -> V_55 . V_2 ) )
F_32 ( V_56 , V_73 ) ;
F_33 ( V_56 ) ;
V_56 = NULL ;
if ( ++ V_20 == V_48 ) {
V_58 ++ ;
V_20 = 0 ;
}
V_12 = 0 ;
}
}
if ( V_56 ) {
if ( ! F_31 ( V_44 -> V_55 . V_2 ) )
F_32 ( V_56 , V_73 ) ;
F_33 ( V_56 ) ;
}
}
static void F_37 ( struct V_69 * * V_80 )
{
int V_45 ;
if ( V_80 == NULL )
return;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 ++ )
if ( V_80 [ V_45 ] )
F_38 ( V_80 [ V_45 ] , 0 ) ;
}
static void F_39 ( const struct V_43 * V_44 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_81 ; V_45 ++ ) {
F_37 ( V_44 -> V_71 [ V_45 ] ) ;
F_40 ( V_44 -> V_71 [ V_45 ] ) ;
F_40 ( V_44 -> V_82 [ V_45 ] ) ;
}
F_38 ( V_44 -> V_83 , F_41 ( V_44 -> V_81 << V_66 ) ) ;
}
static void F_42 ( struct V_43 * V_44 )
{
struct V_84 * V_85 = V_44 -> V_55 . V_2 -> V_86 ;
int V_45 , V_87 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_81 ; V_45 ++ ) {
if ( ! V_44 -> V_49 [ V_45 ] )
continue;
F_43 ( V_85 , V_44 -> V_49 [ V_45 ] , V_73 ,
V_88 ) ;
for ( V_87 = 0 ; V_87 < V_48 ; V_87 ++ ) {
T_2 V_8 = V_44 -> V_82 [ V_45 ] [ V_87 ] ;
if ( V_8 )
F_43 ( V_85 , V_8 , V_73 ,
V_88 ) ;
}
}
}
static void F_44 ( struct V_50 * V_51 )
{
struct V_43 * V_44 =
F_29 ( V_51 , struct V_43 , V_55 ) ;
F_45 ( & V_51 -> V_89 ) ;
F_46 ( & V_51 -> V_90 ) ;
F_42 ( V_44 ) ;
F_39 ( V_44 ) ;
}
static struct V_69 * * F_47 ( void )
{
struct V_69 * * V_80 ;
int V_45 ;
V_80 = F_48 ( V_48 , sizeof( struct V_69 * ) , V_91 ) ;
if ( ! V_80 )
return F_49 ( - V_92 ) ;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 ++ ) {
V_80 [ V_45 ] = F_50 ( V_91 ) ;
if ( ! V_80 [ V_45 ] )
goto V_93;
}
return V_80 ;
V_93:
F_37 ( V_80 ) ;
F_40 ( V_80 ) ;
return F_49 ( - V_92 ) ;
}
static int F_51 ( struct V_43 * V_44 ,
const int V_94 )
{
struct V_69 * * V_80 [ V_79 ] ;
int V_45 , V_41 ;
for ( V_45 = 0 ; V_45 < V_94 ; V_45 ++ ) {
V_80 [ V_45 ] = F_47 () ;
if ( F_52 ( V_80 [ V_45 ] ) ) {
V_41 = F_53 ( V_80 [ V_45 ] ) ;
goto V_95;
}
}
for ( V_45 = 0 ; V_45 < V_94 ; V_45 ++ )
V_44 -> V_71 [ V_45 ] = V_80 [ V_45 ] ;
return 0 ;
V_95:
while ( V_45 -- ) {
F_37 ( V_80 [ V_45 ] ) ;
F_40 ( V_80 [ V_45 ] ) ;
}
return V_41 ;
}
static int F_54 ( struct V_43 * V_44 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_81 ; V_45 ++ ) {
V_44 -> V_82 [ V_45 ] = F_48 ( V_48 ,
sizeof( T_2 ) ,
V_91 ) ;
if ( ! V_44 -> V_82 [ V_45 ] )
return - V_92 ;
}
return 0 ;
}
static int F_55 ( struct V_43 * V_44 ,
const int V_94 )
{
V_44 -> V_83 = F_56 ( V_91 , F_41 ( V_94 << V_66 ) ) ;
if ( ! V_44 -> V_83 )
return - V_92 ;
V_44 -> V_81 = 1 << F_41 ( V_94 << V_66 ) ;
F_19 ( V_44 -> V_81 > V_79 ) ;
return 0 ;
}
static int F_57 ( struct V_43 * V_44 ,
const int V_94 )
{
int V_41 ;
V_41 = F_55 ( V_44 , V_94 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_51 ( V_44 , V_94 ) ;
if ( V_41 ) {
F_38 ( V_44 -> V_83 , F_41 ( V_94 << V_66 ) ) ;
return V_41 ;
}
V_44 -> V_47 = V_94 * V_48 ;
V_41 = F_54 ( V_44 ) ;
if ( V_41 )
F_39 ( V_44 ) ;
return V_41 ;
}
static int F_58 ( struct V_43 * V_44 ,
const int V_96 )
{
T_2 V_97 ;
int V_41 ;
V_97 = F_59 ( V_44 -> V_55 . V_2 -> V_86 ,
& V_44 -> V_83 [ V_96 ] , 0 ,
V_73 , V_88 ) ;
V_41 = F_60 ( V_44 -> V_55 . V_2 -> V_86 , V_97 ) ;
if ( V_41 )
return V_41 ;
V_44 -> V_49 [ V_96 ] = V_97 ;
return 0 ;
}
static int F_61 ( struct V_43 * V_44 ,
const int V_96 ,
const int V_98 )
{
T_2 V_99 ;
struct V_69 * V_100 ;
int V_41 ;
V_100 = V_44 -> V_71 [ V_96 ] [ V_98 ] ;
V_99 = F_59 ( V_44 -> V_55 . V_2 -> V_86 ,
V_100 , 0 , V_73 , V_88 ) ;
V_41 = F_60 ( V_44 -> V_55 . V_2 -> V_86 , V_99 ) ;
if ( V_41 )
return V_41 ;
V_44 -> V_82 [ V_96 ] [ V_98 ] = V_99 ;
return 0 ;
}
static int F_62 ( struct V_43 * V_44 , T_5 V_101 )
{
const int V_94 = F_63 ( V_101 , 1 << 30 ) ;
const int V_102 = V_48 * V_94 ;
int V_45 , V_87 , V_41 ;
if ( V_101 % ( 1 << 30 ) )
F_7 ( L_2 , V_101 ) ;
V_41 = F_57 ( V_44 , V_94 ) ;
if ( V_41 )
return V_41 ;
for ( V_45 = 0 ; V_45 < V_94 ; V_45 ++ ) {
V_41 = F_58 ( V_44 , V_45 ) ;
if ( V_41 )
goto V_93;
for ( V_87 = 0 ; V_87 < V_48 ; V_87 ++ ) {
V_41 = F_61 ( V_44 , V_45 , V_87 ) ;
if ( V_41 )
goto V_93;
}
}
for ( V_45 = 0 ; V_45 < V_94 ; V_45 ++ ) {
T_3 * V_103 ;
V_103 = F_30 ( & V_44 -> V_83 [ V_45 ] ) ;
for ( V_87 = 0 ; V_87 < V_48 ; V_87 ++ ) {
T_2 V_8 = V_44 -> V_82 [ V_45 ] [ V_87 ] ;
V_103 [ V_87 ] = F_9 ( V_44 -> V_55 . V_2 , V_8 ,
V_24 ) ;
}
if ( ! F_31 ( V_44 -> V_55 . V_2 ) )
F_32 ( V_103 , V_73 ) ;
F_33 ( V_103 ) ;
}
V_44 -> V_104 = V_105 ;
V_44 -> V_106 = F_27 ;
V_44 -> V_55 . V_107 = F_28 ;
V_44 -> V_55 . V_108 = F_34 ;
V_44 -> V_55 . V_109 = F_44 ;
V_44 -> V_55 . V_52 = 0 ;
V_44 -> V_55 . V_110 = V_44 -> V_47 * V_72 * V_73 ;
V_44 -> V_55 . V_107 ( & V_44 -> V_55 , 0 , V_44 -> V_55 . V_110 , true ) ;
F_64 ( L_3 ,
V_44 -> V_81 , V_44 -> V_81 - V_94 ) ;
F_64 ( L_4 ,
V_44 -> V_47 ,
( V_44 -> V_47 - V_102 ) + V_101 % ( 1 << 30 ) ) ;
return 0 ;
V_93:
F_42 ( V_44 ) ;
F_39 ( V_44 ) ;
return V_41 ;
}
static void F_65 ( struct V_43 * V_44 , struct V_111 * V_112 )
{
struct V_38 * V_39 = V_44 -> V_55 . V_2 -> V_40 ;
struct V_50 * V_51 = & V_44 -> V_55 ;
T_4 T_6 * V_97 ;
T_4 V_57 ;
T_7 V_113 ;
int V_12 , V_20 ;
V_57 = V_51 -> V_114 ( V_51 -> V_68 . V_8 , V_24 , true ) ;
V_97 = ( T_4 T_6 * ) V_39 -> V_115 . V_116 +
V_44 -> V_117 / sizeof( T_4 ) ;
F_66 ( V_112 , L_5 , V_51 ,
V_44 -> V_117 , V_44 -> V_117 + V_44 -> V_47 ) ;
for ( V_20 = 0 ; V_20 < V_44 -> V_47 ; V_20 ++ ) {
V_42 V_118 ;
T_4 * V_56 ;
T_2 V_99 = V_44 -> V_119 [ V_20 ] ;
V_113 = F_67 ( V_97 + V_20 ) ;
V_118 = ( F_68 ( V_99 ) | V_120 ) ;
if ( V_113 != V_118 )
F_66 ( V_112 , L_6 ,
V_20 ,
V_113 ,
V_118 ) ;
F_66 ( V_112 , L_7 , V_113 ) ;
V_56 = F_30 ( V_44 -> V_80 [ V_20 ] ) ;
for ( V_12 = 0 ; V_12 < V_121 ; V_12 += 4 ) {
unsigned long V_122 =
( V_20 * V_73 * V_121 ) +
( V_12 * V_73 ) ;
int V_45 ;
bool V_123 = false ;
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ )
if ( V_56 [ V_12 + V_45 ] != V_57 )
V_123 = true ;
if ( ! V_123 )
continue;
F_66 ( V_112 , L_8 , V_122 , V_20 , V_12 ) ;
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ ) {
if ( V_56 [ V_12 + V_45 ] != V_57 )
F_66 ( V_112 , L_9 , V_56 [ V_12 + V_45 ] ) ;
else
F_69 ( V_112 , L_10 ) ;
}
F_69 ( V_112 , L_11 ) ;
}
F_33 ( V_56 ) ;
}
}
static void F_70 ( struct V_43 * V_44 )
{
struct V_38 * V_39 = V_44 -> V_55 . V_2 -> V_40 ;
T_4 T_6 * V_97 ;
T_7 V_113 ;
int V_45 ;
F_12 ( V_44 -> V_117 & 0x3f ) ;
V_97 = ( T_4 T_6 * ) V_39 -> V_115 . V_116 +
V_44 -> V_117 / sizeof( T_4 ) ;
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ ) {
T_2 V_99 ;
V_99 = V_44 -> V_119 [ V_45 ] ;
V_113 = F_68 ( V_99 ) ;
V_113 |= V_120 ;
F_71 ( V_113 , V_97 + V_45 ) ;
}
F_67 ( V_97 ) ;
}
static T_7 F_72 ( struct V_43 * V_44 )
{
F_19 ( V_44 -> V_117 & 0x3f ) ;
return ( V_44 -> V_117 / 64 ) << 16 ;
}
static int F_73 ( struct V_43 * V_44 ,
struct V_33 * V_34 ,
bool V_37 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
struct V_38 * V_39 = V_2 -> V_40 ;
int V_41 ;
if ( V_37 ||
F_74 ( & V_39 -> V_124 ) ) {
F_12 ( V_44 != V_39 -> V_90 . V_125 ) ;
F_20 ( F_75 ( V_34 ) , V_126 ) ;
F_20 ( F_76 ( V_34 ) , F_72 ( V_44 ) ) ;
F_77 ( F_76 ( V_34 ) ) ;
return 0 ;
}
V_41 = V_34 -> V_127 ( V_34 , V_128 , V_128 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_23 ( V_34 , 6 ) ;
if ( V_41 )
return V_41 ;
F_24 ( V_34 , F_25 ( 2 ) ) ;
F_24 ( V_34 , F_75 ( V_34 ) ) ;
F_24 ( V_34 , V_126 ) ;
F_24 ( V_34 , F_76 ( V_34 ) ) ;
F_24 ( V_34 , F_72 ( V_44 ) ) ;
F_24 ( V_34 , V_129 ) ;
F_26 ( V_34 ) ;
return 0 ;
}
static int F_78 ( struct V_43 * V_44 ,
struct V_33 * V_34 ,
bool V_37 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
struct V_38 * V_39 = V_2 -> V_40 ;
int V_41 ;
if ( V_37 ||
F_74 ( & V_39 -> V_124 ) ) {
F_12 ( V_44 != V_39 -> V_90 . V_125 ) ;
F_20 ( F_75 ( V_34 ) , V_126 ) ;
F_20 ( F_76 ( V_34 ) , F_72 ( V_44 ) ) ;
F_77 ( F_76 ( V_34 ) ) ;
return 0 ;
}
V_41 = V_34 -> V_127 ( V_34 , V_128 , V_128 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_23 ( V_34 , 6 ) ;
if ( V_41 )
return V_41 ;
F_24 ( V_34 , F_25 ( 2 ) ) ;
F_24 ( V_34 , F_75 ( V_34 ) ) ;
F_24 ( V_34 , V_126 ) ;
F_24 ( V_34 , F_76 ( V_34 ) ) ;
F_24 ( V_34 , F_72 ( V_44 ) ) ;
F_24 ( V_34 , V_129 ) ;
F_26 ( V_34 ) ;
if ( V_34 -> V_130 != V_131 ) {
V_41 = V_34 -> V_127 ( V_34 , V_128 , V_128 ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static int F_79 ( struct V_43 * V_44 ,
struct V_33 * V_34 ,
bool V_37 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
struct V_38 * V_39 = V_2 -> V_40 ;
if ( ! V_37 )
return 0 ;
F_20 ( F_75 ( V_34 ) , V_126 ) ;
F_20 ( F_76 ( V_34 ) , F_72 ( V_44 ) ) ;
F_77 ( F_75 ( V_34 ) ) ;
return 0 ;
}
static int V_105 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_33 * V_34 ;
int V_87 , V_41 ;
F_80 (ring, dev_priv, j) {
F_20 ( F_81 ( V_34 ) ,
F_82 ( V_132 ) ) ;
if ( F_83 ( V_2 ) )
continue;
V_41 = V_44 -> V_106 ( V_44 , V_34 , true ) ;
if ( V_41 )
goto V_133;
}
return 0 ;
V_133:
F_80 (ring, dev_priv, j)
F_20 ( F_81 ( V_34 ) ,
F_84 ( V_132 ) ) ;
return V_41 ;
}
static int F_85 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_33 * V_34 ;
T_7 V_134 , V_135 ;
int V_45 ;
V_135 = F_86 ( V_136 ) ;
F_20 ( V_136 , V_135 | V_137 ) ;
V_134 = F_86 ( V_138 ) ;
if ( F_87 ( V_2 ) ) {
V_134 |= V_139 ;
} else {
V_134 |= V_140 ;
V_134 &= ~ V_141 ;
}
F_20 ( V_138 , V_134 ) ;
F_80 (ring, dev_priv, i) {
int V_41 ;
F_20 ( F_81 ( V_34 ) ,
F_82 ( V_132 ) ) ;
if ( F_83 ( V_2 ) )
continue;
V_41 = V_44 -> V_106 ( V_44 , V_34 , true ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static int F_88 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_33 * V_34 ;
T_7 V_134 , V_142 , V_135 ;
int V_45 ;
V_135 = F_86 ( V_136 ) ;
F_20 ( V_136 , V_135 | V_143 |
V_137 ) ;
V_142 = F_86 ( V_144 ) ;
F_20 ( V_144 , V_142 | V_145 ) ;
V_134 = F_86 ( V_138 ) ;
F_20 ( V_138 , V_134 | V_146 | V_147 ) ;
F_20 ( V_148 , F_82 ( V_132 ) ) ;
F_80 (ring, dev_priv, i) {
int V_41 = V_44 -> V_106 ( V_44 , V_34 , true ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static void F_89 ( struct V_50 * V_51 ,
T_5 V_52 ,
T_5 V_53 ,
bool V_54 )
{
struct V_43 * V_44 =
F_29 ( V_51 , struct V_43 , V_55 ) ;
T_4 * V_56 , V_57 ;
unsigned V_149 = V_52 >> V_66 ;
unsigned V_65 = V_53 >> V_66 ;
unsigned V_150 = V_149 / V_121 ;
unsigned V_151 = V_149 % V_121 ;
unsigned V_67 , V_45 ;
V_57 = V_51 -> V_114 ( V_51 -> V_68 . V_8 , V_24 , true ) ;
while ( V_65 ) {
V_67 = V_151 + V_65 ;
if ( V_67 > V_121 )
V_67 = V_121 ;
V_56 = F_30 ( V_44 -> V_80 [ V_150 ] ) ;
for ( V_45 = V_151 ; V_45 < V_67 ; V_45 ++ )
V_56 [ V_45 ] = V_57 ;
F_33 ( V_56 ) ;
V_65 -= V_67 - V_151 ;
V_151 = 0 ;
V_150 ++ ;
}
}
static void F_90 ( struct V_50 * V_51 ,
struct V_74 * V_75 ,
T_5 V_52 ,
enum V_9 V_76 )
{
struct V_43 * V_44 =
F_29 ( V_51 , struct V_43 , V_55 ) ;
T_4 * V_56 ;
unsigned V_149 = V_52 >> V_66 ;
unsigned V_150 = V_149 / V_121 ;
unsigned V_152 = V_149 % V_121 ;
struct V_77 V_78 ;
V_56 = NULL ;
F_35 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_56 == NULL )
V_56 = F_30 ( V_44 -> V_80 [ V_150 ] ) ;
V_56 [ V_152 ] =
V_51 -> V_114 ( F_36 ( & V_78 ) ,
V_76 , true ) ;
if ( ++ V_152 == V_121 ) {
F_33 ( V_56 ) ;
V_56 = NULL ;
V_150 ++ ;
V_152 = 0 ;
}
}
if ( V_56 )
F_33 ( V_56 ) ;
}
static void F_91 ( struct V_43 * V_44 )
{
int V_45 ;
if ( V_44 -> V_119 ) {
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ )
F_43 ( V_44 -> V_55 . V_2 -> V_86 ,
V_44 -> V_119 [ V_45 ] ,
4096 , V_88 ) ;
}
}
static void F_92 ( struct V_43 * V_44 )
{
int V_45 ;
F_40 ( V_44 -> V_119 ) ;
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ )
F_93 ( V_44 -> V_80 [ V_45 ] ) ;
F_40 ( V_44 -> V_80 ) ;
}
static void F_94 ( struct V_50 * V_51 )
{
struct V_43 * V_44 =
F_29 ( V_51 , struct V_43 , V_55 ) ;
F_45 ( & V_51 -> V_89 ) ;
F_46 ( & V_44 -> V_55 . V_90 ) ;
F_95 ( & V_44 -> V_153 ) ;
F_91 ( V_44 ) ;
F_92 ( V_44 ) ;
}
static int F_96 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
struct V_38 * V_39 = V_2 -> V_40 ;
bool V_154 = false ;
int V_41 ;
F_19 ( ! F_97 ( & V_39 -> V_115 . V_55 . V_90 ) ) ;
V_155:
V_41 = F_98 ( & V_39 -> V_115 . V_55 . V_90 ,
& V_44 -> V_153 , V_156 ,
V_157 , 0 ,
0 , V_39 -> V_115 . V_55 . V_110 ,
V_158 ) ;
if ( V_41 == - V_159 && ! V_154 ) {
V_41 = F_99 ( V_2 , & V_39 -> V_115 . V_55 ,
V_156 , V_157 ,
V_15 ,
0 , V_39 -> V_115 . V_55 . V_110 ,
0 ) ;
if ( V_41 )
return V_41 ;
V_154 = true ;
goto V_155;
}
if ( V_44 -> V_153 . V_52 < V_39 -> V_115 . V_160 )
F_100 ( L_12 ) ;
V_44 -> V_47 = V_161 ;
return V_41 ;
}
static int F_101 ( struct V_43 * V_44 )
{
int V_45 ;
V_44 -> V_80 = F_48 ( V_44 -> V_47 , sizeof( struct V_69 * ) ,
V_91 ) ;
if ( ! V_44 -> V_80 )
return - V_92 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ ) {
V_44 -> V_80 [ V_45 ] = F_50 ( V_91 ) ;
if ( ! V_44 -> V_80 [ V_45 ] ) {
F_92 ( V_44 ) ;
return - V_92 ;
}
}
return 0 ;
}
static int F_102 ( struct V_43 * V_44 )
{
int V_41 ;
V_41 = F_96 ( V_44 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_101 ( V_44 ) ;
if ( V_41 ) {
F_95 ( & V_44 -> V_153 ) ;
return V_41 ;
}
V_44 -> V_119 = F_48 ( V_44 -> V_47 , sizeof( T_2 ) ,
V_91 ) ;
if ( ! V_44 -> V_119 ) {
F_95 ( & V_44 -> V_153 ) ;
F_92 ( V_44 ) ;
return - V_92 ;
}
return 0 ;
}
static int F_103 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ ) {
T_2 V_99 ;
V_99 = F_59 ( V_2 -> V_86 , V_44 -> V_80 [ V_45 ] , 0 , 4096 ,
V_88 ) ;
if ( F_60 ( V_2 -> V_86 , V_99 ) ) {
F_91 ( V_44 ) ;
return - V_162 ;
}
V_44 -> V_119 [ V_45 ] = V_99 ;
}
return 0 ;
}
static int F_104 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
struct V_38 * V_39 = V_2 -> V_40 ;
int V_41 ;
V_44 -> V_55 . V_114 = V_39 -> V_115 . V_55 . V_114 ;
if ( F_105 ( V_2 ) ) {
V_44 -> V_104 = F_88 ;
V_44 -> V_106 = F_79 ;
} else if ( F_87 ( V_2 ) ) {
V_44 -> V_104 = F_85 ;
V_44 -> V_106 = F_73 ;
} else if ( F_106 ( V_2 ) ) {
V_44 -> V_104 = F_85 ;
V_44 -> V_106 = F_78 ;
} else
F_107 () ;
V_41 = F_102 ( V_44 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_103 ( V_44 ) ;
if ( V_41 ) {
F_92 ( V_44 ) ;
return V_41 ;
}
V_44 -> V_55 . V_107 = F_89 ;
V_44 -> V_55 . V_108 = F_90 ;
V_44 -> V_55 . V_109 = F_94 ;
V_44 -> V_55 . V_52 = 0 ;
V_44 -> V_55 . V_110 = V_44 -> V_47 * V_121 * V_73 ;
V_44 -> V_163 = F_65 ;
V_44 -> V_117 =
V_44 -> V_153 . V_52 / V_73 * sizeof( T_4 ) ;
V_44 -> V_55 . V_107 ( & V_44 -> V_55 , 0 , V_44 -> V_55 . V_110 , true ) ;
F_64 ( L_13 ,
V_44 -> V_153 . V_101 >> 20 ,
V_44 -> V_153 . V_52 / V_73 ) ;
return 0 ;
}
int F_108 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
int V_41 = 0 ;
V_44 -> V_55 . V_2 = V_2 ;
V_44 -> V_55 . V_68 = V_39 -> V_115 . V_55 . V_68 ;
if ( F_6 ( V_2 ) -> V_6 < 8 )
V_41 = F_104 ( V_44 ) ;
else if ( F_109 ( V_2 ) )
V_41 = F_62 ( V_44 , V_39 -> V_115 . V_55 . V_110 ) ;
else
F_107 () ;
if ( ! V_41 ) {
struct V_38 * V_39 = V_2 -> V_40 ;
F_110 ( & V_44 -> V_164 ) ;
F_111 ( & V_44 -> V_55 . V_90 , V_44 -> V_55 . V_52 ,
V_44 -> V_55 . V_110 ) ;
F_112 ( V_39 , & V_44 -> V_55 ) ;
if ( F_6 ( V_2 ) -> V_6 < 8 ) {
F_70 ( V_44 ) ;
F_100 ( L_14 ,
V_44 -> V_117 << 10 ) ;
}
}
return V_41 ;
}
static void
F_113 ( struct V_165 * V_166 ,
enum V_9 V_76 ,
V_42 V_167 )
{
V_166 -> V_51 -> V_108 ( V_166 -> V_51 , V_166 -> V_168 -> V_75 , V_166 -> V_153 . V_52 ,
V_76 ) ;
}
static void F_114 ( struct V_165 * V_166 )
{
V_166 -> V_51 -> V_107 ( V_166 -> V_51 ,
V_166 -> V_153 . V_52 ,
V_166 -> V_168 -> V_55 . V_101 ,
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
static bool F_118 ( struct V_38 * V_39 )
{
bool V_41 = V_39 -> V_90 . V_169 ;
if ( F_119 ( V_39 -> V_115 . V_170 ) ) {
V_39 -> V_90 . V_169 = false ;
if ( F_120 ( V_39 -> V_2 ) ) {
F_121 ( L_15 ) ;
F_122 ( 10 ) ;
}
}
return V_41 ;
}
static void F_123 ( struct V_38 * V_39 , bool V_169 )
{
if ( F_119 ( V_39 -> V_115 . V_170 ) )
V_39 -> V_90 . V_169 = V_169 ;
}
void F_124 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_33 * V_34 ;
int V_45 ;
if ( F_6 ( V_2 ) -> V_6 < 6 )
return;
F_80 (ring, dev_priv, i) {
V_42 V_171 ;
V_171 = F_86 ( F_125 ( V_34 ) ) ;
if ( V_171 & V_172 ) {
F_64 ( L_16
L_17
L_18
L_19
L_20 ,
V_171 & V_173 ,
V_171 & V_174 ? L_21 : L_22 ,
F_126 ( V_171 ) ,
F_127 ( V_171 ) ) ;
F_20 ( F_125 ( V_34 ) ,
V_171 & ~ V_172 ) ;
}
}
F_77 ( F_125 ( & V_39 -> V_34 [ V_131 ] ) ) ;
}
void F_128 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
if ( F_6 ( V_2 ) -> V_6 < 6 )
return;
F_124 ( V_2 ) ;
V_39 -> V_115 . V_55 . V_107 ( & V_39 -> V_115 . V_55 ,
V_39 -> V_115 . V_55 . V_52 ,
V_39 -> V_115 . V_55 . V_110 ,
true ) ;
}
void F_129 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_175 * V_168 ;
struct V_50 * V_51 ;
F_124 ( V_2 ) ;
V_39 -> V_115 . V_55 . V_107 ( & V_39 -> V_115 . V_55 ,
V_39 -> V_115 . V_55 . V_52 ,
V_39 -> V_115 . V_55 . V_110 ,
true ) ;
F_130 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_165 * V_166 = F_131 ( V_168 ,
& V_39 -> V_115 . V_55 ) ;
if ( ! V_166 )
continue;
F_132 ( V_168 , V_168 -> V_176 ) ;
V_168 -> V_177 = 0 ;
V_166 -> V_178 ( V_166 , V_168 -> V_76 , V_179 ) ;
}
if ( F_6 ( V_2 ) -> V_6 >= 8 ) {
if ( F_133 ( V_2 ) )
F_134 ( V_39 ) ;
else
F_135 ( V_39 ) ;
return;
}
F_130 (vm, &dev_priv->vm_list, global_link) {
if ( F_136 ( V_51 ) ) {
if ( V_39 -> V_90 . V_125 )
F_70 ( V_39 -> V_90 . V_125 ) ;
continue;
}
F_70 ( F_29 ( V_51 , struct V_43 , V_55 ) ) ;
}
F_137 ( V_2 ) ;
}
int F_138 ( struct V_175 * V_168 )
{
if ( V_168 -> V_180 )
return 0 ;
if ( ! F_139 ( & V_168 -> V_55 . V_2 -> V_86 -> V_2 ,
V_168 -> V_75 -> V_181 , V_168 -> V_75 -> V_182 ,
V_88 ) )
return - V_159 ;
return 0 ;
}
static inline void F_140 ( void T_6 * V_8 , T_1 V_12 )
{
#ifdef F_141
F_141 ( V_12 , V_8 ) ;
#else
F_142 ( ( V_42 ) V_12 , V_8 ) ;
F_142 ( V_12 >> 32 , V_8 + 4 ) ;
#endif
}
static void F_143 ( struct V_50 * V_51 ,
struct V_74 * V_183 ,
T_5 V_52 ,
enum V_9 V_10 )
{
struct V_38 * V_39 = V_51 -> V_2 -> V_40 ;
unsigned V_149 = V_52 >> V_66 ;
T_1 T_6 * V_184 =
( T_1 T_6 * ) V_39 -> V_115 . V_116 + V_149 ;
int V_45 = 0 ;
struct V_77 V_78 ;
T_2 V_8 = 0 ;
F_35 (st->sgl, &sg_iter, st->nents, 0 ) {
V_8 = F_144 ( V_78 . V_185 ) +
( V_78 . V_186 << V_66 ) ;
F_140 ( & V_184 [ V_45 ] ,
F_8 ( V_8 , V_10 , true ) ) ;
V_45 ++ ;
}
if ( V_45 != 0 )
F_12 ( F_145 ( & V_184 [ V_45 - 1 ] )
!= F_8 ( V_8 , V_10 , true ) ) ;
F_20 ( V_187 , V_188 ) ;
F_77 ( V_187 ) ;
}
static void F_146 ( struct V_50 * V_51 ,
struct V_74 * V_183 ,
T_5 V_52 ,
enum V_9 V_10 )
{
struct V_38 * V_39 = V_51 -> V_2 -> V_40 ;
unsigned V_149 = V_52 >> V_66 ;
T_4 T_6 * V_184 =
( T_4 T_6 * ) V_39 -> V_115 . V_116 + V_149 ;
int V_45 = 0 ;
struct V_77 V_78 ;
T_2 V_8 ;
F_35 (st->sgl, &sg_iter, st->nents, 0 ) {
V_8 = F_36 ( & V_78 ) ;
F_142 ( V_51 -> V_114 ( V_8 , V_10 , true ) , & V_184 [ V_45 ] ) ;
V_45 ++ ;
}
if ( V_45 != 0 )
F_12 ( F_67 ( & V_184 [ V_45 - 1 ] ) !=
V_51 -> V_114 ( V_8 , V_10 , true ) ) ;
F_20 ( V_187 , V_188 ) ;
F_77 ( V_187 ) ;
}
static void F_147 ( struct V_50 * V_51 ,
T_5 V_52 ,
T_5 V_53 ,
bool V_54 )
{
struct V_38 * V_39 = V_51 -> V_2 -> V_40 ;
unsigned V_149 = V_52 >> V_66 ;
unsigned V_65 = V_53 >> V_66 ;
T_1 V_57 , T_6 * V_189 =
( T_1 T_6 * ) V_39 -> V_115 . V_116 + V_149 ;
const int V_190 = F_148 ( V_39 -> V_115 ) - V_149 ;
int V_45 ;
if ( F_149 ( V_65 > V_190 ,
L_23 ,
V_149 , V_65 , V_190 ) )
V_65 = V_190 ;
V_57 = F_8 ( V_51 -> V_68 . V_8 ,
V_24 ,
V_54 ) ;
for ( V_45 = 0 ; V_45 < V_65 ; V_45 ++ )
F_140 ( & V_189 [ V_45 ] , V_57 ) ;
F_67 ( V_189 ) ;
}
static void F_150 ( struct V_50 * V_51 ,
T_5 V_52 ,
T_5 V_53 ,
bool V_54 )
{
struct V_38 * V_39 = V_51 -> V_2 -> V_40 ;
unsigned V_149 = V_52 >> V_66 ;
unsigned V_65 = V_53 >> V_66 ;
T_4 V_57 , T_6 * V_189 =
( T_4 T_6 * ) V_39 -> V_115 . V_116 + V_149 ;
const int V_190 = F_148 ( V_39 -> V_115 ) - V_149 ;
int V_45 ;
if ( F_149 ( V_65 > V_190 ,
L_23 ,
V_149 , V_65 , V_190 ) )
V_65 = V_190 ;
V_57 = V_51 -> V_114 ( V_51 -> V_68 . V_8 , V_24 , V_54 ) ;
for ( V_45 = 0 ; V_45 < V_65 ; V_45 ++ )
F_142 ( V_57 , & V_189 [ V_45 ] ) ;
F_67 ( V_189 ) ;
}
static void F_151 ( struct V_165 * V_166 ,
enum V_9 V_76 ,
V_42 V_191 )
{
const unsigned long V_35 = V_166 -> V_153 . V_52 >> V_66 ;
unsigned int V_167 = ( V_76 == V_15 ) ?
V_192 : V_193 ;
F_19 ( ! F_136 ( V_166 -> V_51 ) ) ;
F_152 ( V_166 -> V_168 -> V_75 , V_35 , V_167 ) ;
V_166 -> V_168 -> V_177 = 1 ;
}
static void F_153 ( struct V_50 * V_51 ,
T_5 V_52 ,
T_5 V_53 ,
bool V_191 )
{
unsigned V_149 = V_52 >> V_66 ;
unsigned V_65 = V_53 >> V_66 ;
F_154 ( V_149 , V_65 ) ;
}
static void F_155 ( struct V_165 * V_166 )
{
const unsigned int V_194 = V_166 -> V_153 . V_52 >> V_66 ;
const unsigned int V_101 = V_166 -> V_168 -> V_55 . V_101 >> V_66 ;
F_19 ( ! F_136 ( V_166 -> V_51 ) ) ;
V_166 -> V_168 -> V_177 = 0 ;
F_154 ( V_194 , V_101 ) ;
}
static void F_156 ( struct V_165 * V_166 ,
enum V_9 V_76 ,
V_42 V_167 )
{
struct V_1 * V_2 = V_166 -> V_51 -> V_2 ;
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_175 * V_168 = V_166 -> V_168 ;
if ( ! V_39 -> V_90 . V_125 || V_167 & V_179 ) {
if ( ! V_168 -> V_177 ||
( V_76 != V_168 -> V_76 ) ) {
V_166 -> V_51 -> V_108 ( V_166 -> V_51 , V_168 -> V_75 ,
V_166 -> V_153 . V_52 ,
V_76 ) ;
V_168 -> V_177 = 1 ;
}
}
if ( V_39 -> V_90 . V_125 &&
( ! V_168 -> V_195 ||
( V_76 != V_168 -> V_76 ) ) ) {
struct V_43 * V_196 = V_39 -> V_90 . V_125 ;
V_196 -> V_55 . V_108 ( & V_196 -> V_55 ,
V_166 -> V_168 -> V_75 ,
V_166 -> V_153 . V_52 ,
V_76 ) ;
V_166 -> V_168 -> V_195 = 1 ;
}
}
static void F_157 ( struct V_165 * V_166 )
{
struct V_1 * V_2 = V_166 -> V_51 -> V_2 ;
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_175 * V_168 = V_166 -> V_168 ;
if ( V_168 -> V_177 ) {
V_166 -> V_51 -> V_107 ( V_166 -> V_51 ,
V_166 -> V_153 . V_52 ,
V_168 -> V_55 . V_101 ,
true ) ;
V_168 -> V_177 = 0 ;
}
if ( V_168 -> V_195 ) {
struct V_43 * V_196 = V_39 -> V_90 . V_125 ;
V_196 -> V_55 . V_107 ( & V_196 -> V_55 ,
V_166 -> V_153 . V_52 ,
V_168 -> V_55 . V_101 ,
true ) ;
V_168 -> V_195 = 0 ;
}
}
void F_158 ( struct V_175 * V_168 )
{
struct V_1 * V_2 = V_168 -> V_55 . V_2 ;
struct V_38 * V_39 = V_2 -> V_40 ;
bool V_169 ;
V_169 = F_118 ( V_39 ) ;
if ( ! V_168 -> V_180 )
F_159 ( & V_2 -> V_86 -> V_2 ,
V_168 -> V_75 -> V_181 , V_168 -> V_75 -> V_182 ,
V_88 ) ;
F_123 ( V_39 , V_169 ) ;
}
static void F_160 ( struct V_197 * V_153 ,
unsigned long V_198 ,
unsigned long * V_52 ,
unsigned long * V_199 )
{
if ( V_153 -> V_198 != V_198 )
* V_52 += 4096 ;
if ( ! F_161 ( & V_153 -> V_200 ) ) {
V_153 = F_162 ( V_153 -> V_200 . V_201 ,
struct V_197 ,
V_200 ) ;
if ( V_153 -> V_202 && V_153 -> V_198 != V_198 )
* V_199 -= 4096 ;
}
}
void F_163 ( struct V_1 * V_2 ,
unsigned long V_52 ,
unsigned long V_160 ,
unsigned long V_199 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_50 * V_203 = & V_39 -> V_115 . V_55 ;
struct V_197 * V_35 ;
struct V_175 * V_168 ;
unsigned long V_204 , V_205 ;
F_19 ( V_160 > V_199 ) ;
F_111 ( & V_203 -> V_90 , V_52 , V_199 - V_52 - V_73 ) ;
if ( ! F_31 ( V_2 ) )
V_39 -> V_115 . V_55 . V_90 . V_206 = F_160 ;
F_130 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_165 * V_166 = F_131 ( V_168 , V_203 ) ;
int V_41 ;
F_164 ( L_24 ,
F_165 ( V_168 ) , V_168 -> V_55 . V_101 ) ;
F_12 ( F_166 ( V_168 ) ) ;
V_41 = F_167 ( & V_203 -> V_90 , & V_166 -> V_153 ) ;
if ( V_41 )
F_164 ( L_25 ) ;
V_168 -> V_177 = 1 ;
}
V_39 -> V_115 . V_55 . V_52 = V_52 ;
V_39 -> V_115 . V_55 . V_110 = V_199 - V_52 ;
F_168 (entry, &ggtt_vm->mm, hole_start, hole_end) {
F_164 ( L_26 ,
V_204 , V_205 ) ;
V_203 -> V_107 ( V_203 , V_204 ,
V_205 - V_204 , true ) ;
}
V_203 -> V_107 ( V_203 , V_199 - V_73 , V_73 , true ) ;
}
void F_169 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
unsigned long V_207 , V_208 ;
V_207 = V_39 -> V_115 . V_55 . V_110 ;
V_208 = V_39 -> V_115 . V_160 ;
F_163 ( V_2 , 0 , V_208 , V_207 ) ;
}
static int F_170 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_69 * V_69 ;
T_2 V_209 ;
V_69 = F_50 ( V_91 | V_210 | V_211 ) ;
if ( V_69 == NULL )
return - V_92 ;
F_171 ( V_69 ) ;
F_172 ( V_69 , 1 ) ;
#ifdef F_5
V_209 = F_59 ( V_2 -> V_86 , V_69 , 0 , V_73 ,
V_88 ) ;
if ( F_60 ( V_2 -> V_86 , V_209 ) )
return - V_212 ;
#else
V_209 = F_173 ( V_69 ) ;
#endif
V_39 -> V_115 . V_55 . V_68 . V_69 = V_69 ;
V_39 -> V_115 . V_55 . V_68 . V_8 = V_209 ;
return 0 ;
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_69 * V_69 = V_39 -> V_115 . V_55 . V_68 . V_69 ;
F_175 ( V_69 , 1 ) ;
F_43 ( V_2 -> V_86 , V_39 -> V_115 . V_55 . V_68 . V_8 ,
V_73 , V_88 ) ;
F_176 ( V_69 ) ;
F_93 ( V_69 ) ;
}
static inline unsigned int F_177 ( T_8 V_213 )
{
V_213 >>= V_214 ;
V_213 &= V_215 ;
return V_213 << 20 ;
}
static inline unsigned int F_178 ( T_8 V_216 )
{
V_216 >>= V_217 ;
V_216 &= V_218 ;
if ( V_216 )
V_216 = 1 << V_216 ;
#ifdef F_179
if ( V_216 > 4 )
V_216 = 4 ;
#endif
return V_216 << 20 ;
}
static inline unsigned int F_180 ( T_8 V_219 )
{
V_219 >>= V_214 ;
V_219 &= V_215 ;
if ( V_219 )
return 1 << ( 20 + V_219 ) ;
return 0 ;
}
static inline T_9 F_181 ( T_8 V_213 )
{
V_213 >>= V_220 ;
V_213 &= V_221 ;
return V_213 << 25 ;
}
static inline T_9 F_182 ( T_8 V_216 )
{
V_216 >>= V_222 ;
V_216 &= V_223 ;
return V_216 << 25 ;
}
static T_9 F_183 ( T_8 V_219 )
{
V_219 >>= V_220 ;
V_219 &= V_221 ;
if ( V_219 < 0x11 )
return V_219 << 25 ;
else if ( V_219 < 0x17 )
return ( V_219 - 0x11 + 2 ) << 22 ;
else
return ( V_219 - 0x17 + 9 ) << 22 ;
}
static int F_184 ( struct V_1 * V_2 ,
T_9 V_207 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
T_10 V_224 ;
int V_41 ;
V_224 = F_185 ( V_2 -> V_86 , 0 ) +
( F_186 ( V_2 -> V_86 , 0 ) / 2 ) ;
V_39 -> V_115 . V_116 = F_187 ( V_224 , V_207 ) ;
if ( ! V_39 -> V_115 . V_116 ) {
F_121 ( L_27 ) ;
return - V_92 ;
}
V_41 = F_170 ( V_2 ) ;
if ( V_41 ) {
F_121 ( L_28 ) ;
F_188 ( V_39 -> V_115 . V_116 ) ;
}
return V_41 ;
}
static void F_135 ( struct V_38 * V_39 )
{
T_5 V_225 ;
V_225 = F_189 ( 0 , V_226 | V_227 ) |
F_189 ( 1 , V_228 | V_229 ) |
F_189 ( 2 , V_230 | V_229 ) |
F_189 ( 3 , V_231 ) |
F_189 ( 4 , V_226 | V_229 | F_190 ( 0 ) ) |
F_189 ( 5 , V_226 | V_229 | F_190 ( 1 ) ) |
F_189 ( 6 , V_226 | V_229 | F_190 ( 2 ) ) |
F_189 ( 7 , V_226 | V_229 | F_190 ( 3 ) ) ;
F_20 ( V_232 , V_225 ) ;
F_20 ( V_232 + 4 , V_225 >> 32 ) ;
}
static void F_134 ( struct V_38 * V_39 )
{
T_5 V_225 ;
V_225 = F_189 ( 0 , V_233 ) |
F_189 ( 1 , 0 ) |
F_189 ( 2 , 0 ) |
F_189 ( 3 , 0 ) |
F_189 ( 4 , V_233 ) |
F_189 ( 5 , V_233 ) |
F_189 ( 6 , V_233 ) |
F_189 ( 7 , V_233 ) ;
F_20 ( V_232 , V_225 ) ;
F_20 ( V_232 + 4 , V_225 >> 32 ) ;
}
static int F_191 ( struct V_1 * V_2 ,
T_9 * V_234 ,
T_9 * V_235 ,
T_10 * V_236 ,
unsigned long * V_160 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
unsigned int V_207 ;
T_8 V_213 ;
int V_41 ;
* V_236 = F_185 ( V_2 -> V_86 , 2 ) ;
* V_160 = F_186 ( V_2 -> V_86 , 2 ) ;
if ( ! F_192 ( V_2 -> V_86 , F_193 ( 39 ) ) )
F_194 ( V_2 -> V_86 , F_193 ( 39 ) ) ;
F_195 ( V_2 -> V_86 , V_237 , & V_213 ) ;
if ( F_133 ( V_2 ) ) {
* V_235 = F_183 ( V_213 ) ;
V_207 = F_180 ( V_213 ) ;
} else {
* V_235 = F_182 ( V_213 ) ;
V_207 = F_178 ( V_213 ) ;
}
* V_234 = ( V_207 / sizeof( T_1 ) ) << V_66 ;
if ( F_133 ( V_2 ) )
F_134 ( V_39 ) ;
else
F_135 ( V_39 ) ;
V_41 = F_184 ( V_2 , V_207 ) ;
V_39 -> V_115 . V_55 . V_107 = F_147 ;
V_39 -> V_115 . V_55 . V_108 = F_143 ;
return V_41 ;
}
static int F_196 ( struct V_1 * V_2 ,
T_9 * V_234 ,
T_9 * V_235 ,
T_10 * V_236 ,
unsigned long * V_160 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
unsigned int V_207 ;
T_8 V_213 ;
int V_41 ;
* V_236 = F_185 ( V_2 -> V_86 , 2 ) ;
* V_160 = F_186 ( V_2 -> V_86 , 2 ) ;
if ( ( * V_160 < ( 64 << 20 ) || ( * V_160 > ( 512 << 20 ) ) ) ) {
F_121 ( L_29 ,
V_39 -> V_115 . V_160 ) ;
return - V_238 ;
}
if ( ! F_192 ( V_2 -> V_86 , F_193 ( 40 ) ) )
F_194 ( V_2 -> V_86 , F_193 ( 40 ) ) ;
F_195 ( V_2 -> V_86 , V_237 , & V_213 ) ;
* V_235 = F_181 ( V_213 ) ;
V_207 = F_177 ( V_213 ) ;
* V_234 = ( V_207 / sizeof( T_4 ) ) << V_66 ;
V_41 = F_184 ( V_2 , V_207 ) ;
V_39 -> V_115 . V_55 . V_107 = F_150 ;
V_39 -> V_115 . V_55 . V_108 = F_146 ;
return V_41 ;
}
static void F_197 ( struct V_50 * V_51 )
{
struct V_239 * V_115 = F_29 ( V_51 , struct V_239 , V_55 ) ;
if ( F_97 ( & V_51 -> V_90 ) ) {
F_46 ( & V_51 -> V_90 ) ;
F_45 ( & V_51 -> V_89 ) ;
}
F_188 ( V_115 -> V_116 ) ;
F_174 ( V_51 -> V_2 ) ;
}
static int F_198 ( struct V_1 * V_2 ,
T_9 * V_234 ,
T_9 * V_235 ,
T_10 * V_236 ,
unsigned long * V_160 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
int V_41 ;
V_41 = F_199 ( V_39 -> V_240 , V_39 -> V_2 -> V_86 , NULL ) ;
if ( ! V_41 ) {
F_121 ( L_30 ) ;
return - V_162 ;
}
F_200 ( V_234 , V_235 , V_236 , V_160 ) ;
V_39 -> V_115 . V_170 = F_115 ( V_39 -> V_2 ) ;
V_39 -> V_115 . V_55 . V_107 = F_153 ;
if ( F_119 ( V_39 -> V_115 . V_170 ) )
F_7 ( L_31 ) ;
return 0 ;
}
static void F_201 ( struct V_50 * V_51 )
{
if ( F_97 ( & V_51 -> V_90 ) ) {
F_46 ( & V_51 -> V_90 ) ;
F_45 ( & V_51 -> V_89 ) ;
}
F_202 () ;
}
int F_203 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_239 * V_115 = & V_39 -> V_115 ;
int V_41 ;
if ( F_6 ( V_2 ) -> V_6 <= 5 ) {
V_115 -> V_241 = F_198 ;
V_115 -> V_55 . V_109 = F_201 ;
} else if ( F_6 ( V_2 ) -> V_6 < 8 ) {
V_115 -> V_241 = F_196 ;
V_115 -> V_55 . V_109 = F_197 ;
if ( F_87 ( V_2 ) && V_39 -> V_242 )
V_115 -> V_55 . V_114 = F_17 ;
else if ( F_87 ( V_2 ) )
V_115 -> V_55 . V_114 = F_15 ;
else if ( F_204 ( V_2 ) )
V_115 -> V_55 . V_114 = F_14 ;
else if ( F_6 ( V_2 ) -> V_6 >= 7 )
V_115 -> V_55 . V_114 = F_13 ;
else
V_115 -> V_55 . V_114 = F_10 ;
} else {
V_39 -> V_115 . V_241 = F_191 ;
V_39 -> V_115 . V_55 . V_109 = F_197 ;
}
V_41 = V_115 -> V_241 ( V_2 , & V_115 -> V_55 . V_110 , & V_115 -> V_243 ,
& V_115 -> V_236 , & V_115 -> V_160 ) ;
if ( V_41 )
return V_41 ;
V_115 -> V_55 . V_2 = V_2 ;
F_7 ( L_32 ,
V_115 -> V_55 . V_110 >> 20 ) ;
F_64 ( L_33 , V_115 -> V_160 >> 20 ) ;
F_64 ( L_34 , V_115 -> V_243 >> 20 ) ;
#ifdef F_5
if ( V_7 )
F_7 ( L_35 ) ;
#endif
V_4 . V_5 = F_2 ( V_2 , V_4 . V_5 ) ;
F_64 ( L_36 , V_4 . V_5 ) ;
return 0 ;
}
static struct V_165 * F_205 ( struct V_175 * V_168 ,
struct V_50 * V_51 )
{
struct V_165 * V_166 = F_206 ( sizeof( * V_166 ) , V_91 ) ;
if ( V_166 == NULL )
return F_49 ( - V_92 ) ;
F_207 ( & V_166 -> V_244 ) ;
F_207 ( & V_166 -> V_245 ) ;
F_207 ( & V_166 -> V_246 ) ;
V_166 -> V_51 = V_51 ;
V_166 -> V_168 = V_168 ;
switch ( F_6 ( V_51 -> V_2 ) -> V_6 ) {
case 8 :
case 7 :
case 6 :
if ( F_136 ( V_51 ) ) {
V_166 -> V_247 = F_157 ;
V_166 -> V_178 = F_156 ;
} else {
V_166 -> V_247 = F_114 ;
V_166 -> V_178 = F_113 ;
}
break;
case 5 :
case 4 :
case 3 :
case 2 :
F_19 ( ! F_136 ( V_51 ) ) ;
V_166 -> V_247 = F_155 ;
V_166 -> V_178 = F_151 ;
break;
default:
F_107 () ;
}
if ( F_136 ( V_51 ) )
F_208 ( & V_166 -> V_244 , & V_168 -> V_248 ) ;
else
F_209 ( & V_166 -> V_244 , & V_168 -> V_248 ) ;
return V_166 ;
}
struct V_165 *
F_210 ( struct V_175 * V_168 ,
struct V_50 * V_51 )
{
struct V_165 * V_166 ;
V_166 = F_131 ( V_168 , V_51 ) ;
if ( ! V_166 )
V_166 = F_205 ( V_168 , V_51 ) ;
return V_166 ;
}
