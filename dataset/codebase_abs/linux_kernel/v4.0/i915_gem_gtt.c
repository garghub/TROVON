static int F_1 ( struct V_1 * V_2 , int V_3 )
{
bool V_4 ;
bool V_5 ;
V_4 = F_2 ( V_2 ) -> V_6 >= 6 ;
V_5 = F_2 ( V_2 ) -> V_6 >= 7 ;
if ( F_2 ( V_2 ) -> V_6 < 9 &&
( V_3 == 0 || ! V_4 ) )
return 0 ;
if ( V_3 == 1 )
return 1 ;
if ( V_3 == 2 && V_5 )
return 2 ;
#ifdef F_3
if ( F_2 ( V_2 ) -> V_6 == 6 && V_7 ) {
F_4 ( L_1 ) ;
return 0 ;
}
#endif
if ( F_5 ( V_2 ) && ! F_6 ( V_2 ) &&
V_2 -> V_8 -> V_9 < 0xb ) {
F_7 ( L_2 ) ;
return 0 ;
}
if ( F_2 ( V_2 ) -> V_6 >= 8 && V_10 . V_11 )
return 2 ;
else
return V_4 ? 1 : 0 ;
}
static inline T_1 F_8 ( T_2 V_12 ,
enum V_13 V_14 ,
bool V_15 )
{
T_1 V_16 = V_15 ? V_17 | V_18 : 0 ;
V_16 |= V_12 ;
switch ( V_14 ) {
case V_19 :
V_16 |= V_20 ;
break;
case V_21 :
V_16 |= V_22 ;
break;
default:
V_16 |= V_23 ;
break;
}
return V_16 ;
}
static inline T_3 F_9 ( struct V_1 * V_2 ,
T_2 V_12 ,
enum V_13 V_14 )
{
T_3 V_24 = V_17 | V_18 ;
V_24 |= V_12 ;
if ( V_14 != V_19 )
V_24 |= V_25 ;
else
V_24 |= V_20 ;
return V_24 ;
}
static T_4 F_10 ( T_2 V_12 ,
enum V_13 V_14 ,
bool V_15 , T_5 V_26 )
{
T_4 V_16 = V_15 ? V_27 : 0 ;
V_16 |= F_11 ( V_12 ) ;
switch ( V_14 ) {
case V_28 :
case V_29 :
V_16 |= V_30 ;
break;
case V_19 :
V_16 |= V_31 ;
break;
default:
F_12 ( V_14 ) ;
}
return V_16 ;
}
static T_4 F_13 ( T_2 V_12 ,
enum V_13 V_14 ,
bool V_15 , T_5 V_26 )
{
T_4 V_16 = V_15 ? V_27 : 0 ;
V_16 |= F_11 ( V_12 ) ;
switch ( V_14 ) {
case V_28 :
V_16 |= V_32 ;
break;
case V_29 :
V_16 |= V_30 ;
break;
case V_19 :
V_16 |= V_31 ;
break;
default:
F_12 ( V_14 ) ;
}
return V_16 ;
}
static T_4 F_14 ( T_2 V_12 ,
enum V_13 V_14 ,
bool V_15 , T_5 V_33 )
{
T_4 V_16 = V_15 ? V_27 : 0 ;
V_16 |= F_11 ( V_12 ) ;
if ( ! ( V_33 & V_34 ) )
V_16 |= V_35 ;
if ( V_14 != V_19 )
V_16 |= V_36 ;
return V_16 ;
}
static T_4 F_15 ( T_2 V_12 ,
enum V_13 V_14 ,
bool V_15 , T_5 V_26 )
{
T_4 V_16 = V_15 ? V_27 : 0 ;
V_16 |= F_16 ( V_12 ) ;
if ( V_14 != V_19 )
V_16 |= V_37 ;
return V_16 ;
}
static T_4 F_17 ( T_2 V_12 ,
enum V_13 V_14 ,
bool V_15 , T_5 V_26 )
{
T_4 V_16 = V_15 ? V_27 : 0 ;
V_16 |= F_16 ( V_12 ) ;
switch ( V_14 ) {
case V_19 :
break;
case V_21 :
V_16 |= V_38 ;
break;
default:
V_16 |= V_39 ;
break;
}
return V_16 ;
}
static int F_18 ( struct V_40 * V_41 , unsigned V_42 ,
T_6 V_43 )
{
int V_44 ;
F_19 ( V_42 >= 4 ) ;
V_44 = F_20 ( V_41 , 6 ) ;
if ( V_44 )
return V_44 ;
F_21 ( V_41 , F_22 ( 1 ) ) ;
F_21 ( V_41 , F_23 ( V_41 , V_42 ) ) ;
F_21 ( V_41 , ( T_5 ) ( V_43 >> 32 ) ) ;
F_21 ( V_41 , F_22 ( 1 ) ) ;
F_21 ( V_41 , F_24 ( V_41 , V_42 ) ) ;
F_21 ( V_41 , ( T_5 ) ( V_43 ) ) ;
F_25 ( V_41 ) ;
return 0 ;
}
static int F_26 ( struct V_45 * V_46 ,
struct V_40 * V_41 )
{
int V_47 , V_44 ;
int V_48 = V_46 -> V_49 / V_50 ;
for ( V_47 = V_48 - 1 ; V_47 >= 0 ; V_47 -- ) {
T_2 V_12 = V_46 -> V_51 [ V_47 ] ;
V_44 = F_18 ( V_41 , V_47 , V_12 ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
static void F_27 ( struct V_52 * V_53 ,
T_6 V_54 ,
T_6 V_55 ,
bool V_56 )
{
struct V_45 * V_46 =
F_28 ( V_53 , struct V_45 , V_57 ) ;
T_1 * V_58 , V_59 ;
unsigned V_60 = V_54 >> V_61 & V_62 ;
unsigned V_24 = V_54 >> V_63 & V_64 ;
unsigned V_16 = V_54 >> V_65 & V_66 ;
unsigned V_67 = V_55 >> V_68 ;
unsigned V_69 , V_47 ;
V_59 = F_8 ( V_46 -> V_57 . V_70 . V_12 ,
V_29 , V_56 ) ;
while ( V_67 ) {
struct V_71 * V_72 = V_46 -> V_73 [ V_60 ] [ V_24 ] ;
V_69 = V_16 + V_67 ;
if ( V_69 > V_74 )
V_69 = V_74 ;
V_58 = F_29 ( V_72 ) ;
for ( V_47 = V_16 ; V_47 < V_69 ; V_47 ++ ) {
V_58 [ V_47 ] = V_59 ;
V_67 -- ;
}
if ( ! F_30 ( V_46 -> V_57 . V_2 ) )
F_31 ( V_58 , V_75 ) ;
F_32 ( V_58 ) ;
V_16 = 0 ;
if ( ++ V_24 == V_50 ) {
V_60 ++ ;
V_24 = 0 ;
}
}
}
static void F_33 ( struct V_52 * V_53 ,
struct V_76 * V_77 ,
T_6 V_54 ,
enum V_13 V_78 , T_5 V_26 )
{
struct V_45 * V_46 =
F_28 ( V_53 , struct V_45 , V_57 ) ;
T_1 * V_58 ;
unsigned V_60 = V_54 >> V_61 & V_62 ;
unsigned V_24 = V_54 >> V_63 & V_64 ;
unsigned V_16 = V_54 >> V_65 & V_66 ;
struct V_79 V_80 ;
V_58 = NULL ;
F_34 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( F_35 ( V_60 >= V_81 ) )
break;
if ( V_58 == NULL )
V_58 = F_29 ( V_46 -> V_73 [ V_60 ] [ V_24 ] ) ;
V_58 [ V_16 ] =
F_8 ( F_36 ( & V_80 ) ,
V_78 , true ) ;
if ( ++ V_16 == V_74 ) {
if ( ! F_30 ( V_46 -> V_57 . V_2 ) )
F_31 ( V_58 , V_75 ) ;
F_32 ( V_58 ) ;
V_58 = NULL ;
if ( ++ V_24 == V_50 ) {
V_60 ++ ;
V_24 = 0 ;
}
V_16 = 0 ;
}
}
if ( V_58 ) {
if ( ! F_30 ( V_46 -> V_57 . V_2 ) )
F_31 ( V_58 , V_75 ) ;
F_32 ( V_58 ) ;
}
}
static void F_37 ( struct V_71 * * V_82 )
{
int V_47 ;
if ( V_82 == NULL )
return;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ )
if ( V_82 [ V_47 ] )
F_38 ( V_82 [ V_47 ] , 0 ) ;
}
static void F_39 ( const struct V_45 * V_46 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_83 ; V_47 ++ ) {
F_37 ( V_46 -> V_73 [ V_47 ] ) ;
F_40 ( V_46 -> V_73 [ V_47 ] ) ;
F_40 ( V_46 -> V_84 [ V_47 ] ) ;
}
F_38 ( V_46 -> V_85 , F_41 ( V_46 -> V_83 << V_68 ) ) ;
}
static void F_42 ( struct V_45 * V_46 )
{
struct V_86 * V_87 = V_46 -> V_57 . V_2 -> V_8 ;
int V_47 , V_88 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_83 ; V_47 ++ ) {
if ( ! V_46 -> V_51 [ V_47 ] )
continue;
F_43 ( V_87 , V_46 -> V_51 [ V_47 ] , V_75 ,
V_89 ) ;
for ( V_88 = 0 ; V_88 < V_50 ; V_88 ++ ) {
T_2 V_12 = V_46 -> V_84 [ V_47 ] [ V_88 ] ;
if ( V_12 )
F_43 ( V_87 , V_12 , V_75 ,
V_89 ) ;
}
}
}
static void F_44 ( struct V_52 * V_53 )
{
struct V_45 * V_46 =
F_28 ( V_53 , struct V_45 , V_57 ) ;
F_42 ( V_46 ) ;
F_39 ( V_46 ) ;
}
static struct V_71 * * F_45 ( void )
{
struct V_71 * * V_82 ;
int V_47 ;
V_82 = F_46 ( V_50 , sizeof( struct V_71 * ) , V_90 ) ;
if ( ! V_82 )
return F_47 ( - V_91 ) ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_82 [ V_47 ] = F_48 ( V_90 ) ;
if ( ! V_82 [ V_47 ] )
goto V_92;
}
return V_82 ;
V_92:
F_37 ( V_82 ) ;
F_40 ( V_82 ) ;
return F_47 ( - V_91 ) ;
}
static int F_49 ( struct V_45 * V_46 ,
const int V_93 )
{
struct V_71 * * V_82 [ V_81 ] ;
int V_47 , V_44 ;
for ( V_47 = 0 ; V_47 < V_93 ; V_47 ++ ) {
V_82 [ V_47 ] = F_45 () ;
if ( F_50 ( V_82 [ V_47 ] ) ) {
V_44 = F_51 ( V_82 [ V_47 ] ) ;
goto V_94;
}
}
for ( V_47 = 0 ; V_47 < V_93 ; V_47 ++ )
V_46 -> V_73 [ V_47 ] = V_82 [ V_47 ] ;
return 0 ;
V_94:
while ( V_47 -- ) {
F_37 ( V_82 [ V_47 ] ) ;
F_40 ( V_82 [ V_47 ] ) ;
}
return V_44 ;
}
static int F_52 ( struct V_45 * V_46 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_83 ; V_47 ++ ) {
V_46 -> V_84 [ V_47 ] = F_46 ( V_50 ,
sizeof( T_2 ) ,
V_90 ) ;
if ( ! V_46 -> V_84 [ V_47 ] )
return - V_91 ;
}
return 0 ;
}
static int F_53 ( struct V_45 * V_46 ,
const int V_93 )
{
V_46 -> V_85 = F_54 ( V_90 , F_41 ( V_93 << V_68 ) ) ;
if ( ! V_46 -> V_85 )
return - V_91 ;
V_46 -> V_83 = 1 << F_41 ( V_93 << V_68 ) ;
F_19 ( V_46 -> V_83 > V_81 ) ;
return 0 ;
}
static int F_55 ( struct V_45 * V_46 ,
const int V_93 )
{
int V_44 ;
V_44 = F_53 ( V_46 , V_93 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_49 ( V_46 , V_93 ) ;
if ( V_44 ) {
F_38 ( V_46 -> V_85 , F_41 ( V_93 << V_68 ) ) ;
return V_44 ;
}
V_46 -> V_49 = V_93 * V_50 ;
V_44 = F_52 ( V_46 ) ;
if ( V_44 )
F_39 ( V_46 ) ;
return V_44 ;
}
static int F_56 ( struct V_45 * V_46 ,
const int V_95 )
{
T_2 V_96 ;
int V_44 ;
V_96 = F_57 ( V_46 -> V_57 . V_2 -> V_8 ,
& V_46 -> V_85 [ V_95 ] , 0 ,
V_75 , V_89 ) ;
V_44 = F_58 ( V_46 -> V_57 . V_2 -> V_8 , V_96 ) ;
if ( V_44 )
return V_44 ;
V_46 -> V_51 [ V_95 ] = V_96 ;
return 0 ;
}
static int F_59 ( struct V_45 * V_46 ,
const int V_95 ,
const int V_97 )
{
T_2 V_98 ;
struct V_71 * V_99 ;
int V_44 ;
V_99 = V_46 -> V_73 [ V_95 ] [ V_97 ] ;
V_98 = F_57 ( V_46 -> V_57 . V_2 -> V_8 ,
V_99 , 0 , V_75 , V_89 ) ;
V_44 = F_58 ( V_46 -> V_57 . V_2 -> V_8 , V_98 ) ;
if ( V_44 )
return V_44 ;
V_46 -> V_84 [ V_95 ] [ V_97 ] = V_98 ;
return 0 ;
}
static int F_60 ( struct V_45 * V_46 , T_6 V_100 )
{
const int V_93 = F_61 ( V_100 , 1 << 30 ) ;
const int V_101 = V_50 * V_93 ;
int V_47 , V_88 , V_44 ;
if ( V_100 % ( 1 << 30 ) )
F_4 ( L_3 , V_100 ) ;
V_44 = F_55 ( V_46 , V_93 ) ;
if ( V_44 )
return V_44 ;
for ( V_47 = 0 ; V_47 < V_93 ; V_47 ++ ) {
V_44 = F_56 ( V_46 , V_47 ) ;
if ( V_44 )
goto V_92;
for ( V_88 = 0 ; V_88 < V_50 ; V_88 ++ ) {
V_44 = F_59 ( V_46 , V_47 , V_88 ) ;
if ( V_44 )
goto V_92;
}
}
for ( V_47 = 0 ; V_47 < V_93 ; V_47 ++ ) {
T_3 * V_102 ;
V_102 = F_29 ( & V_46 -> V_85 [ V_47 ] ) ;
for ( V_88 = 0 ; V_88 < V_50 ; V_88 ++ ) {
T_2 V_12 = V_46 -> V_84 [ V_47 ] [ V_88 ] ;
V_102 [ V_88 ] = F_9 ( V_46 -> V_57 . V_2 , V_12 ,
V_29 ) ;
}
if ( ! F_30 ( V_46 -> V_57 . V_2 ) )
F_31 ( V_102 , V_75 ) ;
F_32 ( V_102 ) ;
}
V_46 -> V_103 = F_26 ;
V_46 -> V_57 . V_104 = F_27 ;
V_46 -> V_57 . V_105 = F_33 ;
V_46 -> V_57 . V_106 = F_44 ;
V_46 -> V_57 . V_54 = 0 ;
V_46 -> V_57 . V_107 = V_46 -> V_49 * V_74 * V_75 ;
V_46 -> V_57 . V_104 ( & V_46 -> V_57 , 0 , V_46 -> V_57 . V_107 , true ) ;
F_7 ( L_4 ,
V_46 -> V_83 , V_46 -> V_83 - V_93 ) ;
F_7 ( L_5 ,
V_46 -> V_49 ,
( V_46 -> V_49 - V_101 ) + V_100 % ( 1 << 30 ) ) ;
return 0 ;
V_92:
F_42 ( V_46 ) ;
F_39 ( V_46 ) ;
return V_44 ;
}
static void F_62 ( struct V_45 * V_46 , struct V_108 * V_109 )
{
struct V_110 * V_111 = V_46 -> V_57 . V_2 -> V_112 ;
struct V_52 * V_53 = & V_46 -> V_57 ;
T_4 T_7 * V_96 ;
T_4 V_59 ;
T_8 V_113 ;
int V_16 , V_24 ;
V_59 = V_53 -> V_114 ( V_53 -> V_70 . V_12 , V_29 , true , 0 ) ;
V_96 = ( T_4 T_7 * ) V_111 -> V_115 . V_116 +
V_46 -> V_117 / sizeof( T_4 ) ;
F_63 ( V_109 , L_6 , V_53 ,
V_46 -> V_117 , V_46 -> V_117 + V_46 -> V_49 ) ;
for ( V_24 = 0 ; V_24 < V_46 -> V_49 ; V_24 ++ ) {
T_5 V_118 ;
T_4 * V_58 ;
T_2 V_98 = V_46 -> V_119 [ V_24 ] ;
V_113 = F_64 ( V_96 + V_24 ) ;
V_118 = ( F_65 ( V_98 ) | V_120 ) ;
if ( V_113 != V_118 )
F_63 ( V_109 , L_7 ,
V_24 ,
V_113 ,
V_118 ) ;
F_63 ( V_109 , L_8 , V_113 ) ;
V_58 = F_29 ( V_46 -> V_82 [ V_24 ] ) ;
for ( V_16 = 0 ; V_16 < V_121 ; V_16 += 4 ) {
unsigned long V_122 =
( V_24 * V_75 * V_121 ) +
( V_16 * V_75 ) ;
int V_47 ;
bool V_123 = false ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ )
if ( V_58 [ V_16 + V_47 ] != V_59 )
V_123 = true ;
if ( ! V_123 )
continue;
F_63 ( V_109 , L_9 , V_122 , V_24 , V_16 ) ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
if ( V_58 [ V_16 + V_47 ] != V_59 )
F_63 ( V_109 , L_10 , V_58 [ V_16 + V_47 ] ) ;
else
F_66 ( V_109 , L_11 ) ;
}
F_66 ( V_109 , L_12 ) ;
}
F_32 ( V_58 ) ;
}
}
static void F_67 ( struct V_45 * V_46 )
{
struct V_110 * V_111 = V_46 -> V_57 . V_2 -> V_112 ;
T_4 T_7 * V_96 ;
T_8 V_113 ;
int V_47 ;
F_35 ( V_46 -> V_117 & 0x3f ) ;
V_96 = ( T_4 T_7 * ) V_111 -> V_115 . V_116 +
V_46 -> V_117 / sizeof( T_4 ) ;
for ( V_47 = 0 ; V_47 < V_46 -> V_49 ; V_47 ++ ) {
T_2 V_98 ;
V_98 = V_46 -> V_119 [ V_47 ] ;
V_113 = F_65 ( V_98 ) ;
V_113 |= V_120 ;
F_68 ( V_113 , V_96 + V_47 ) ;
}
F_64 ( V_96 ) ;
}
static T_8 F_69 ( struct V_45 * V_46 )
{
F_19 ( V_46 -> V_117 & 0x3f ) ;
return ( V_46 -> V_117 / 64 ) << 16 ;
}
static int F_70 ( struct V_45 * V_46 ,
struct V_40 * V_41 )
{
int V_44 ;
V_44 = V_41 -> V_124 ( V_41 , V_125 , V_125 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_20 ( V_41 , 6 ) ;
if ( V_44 )
return V_44 ;
F_21 ( V_41 , F_22 ( 2 ) ) ;
F_21 ( V_41 , F_71 ( V_41 ) ) ;
F_21 ( V_41 , V_126 ) ;
F_21 ( V_41 , F_72 ( V_41 ) ) ;
F_21 ( V_41 , F_69 ( V_46 ) ) ;
F_21 ( V_41 , V_127 ) ;
F_25 ( V_41 ) ;
return 0 ;
}
static int F_73 ( struct V_45 * V_46 ,
struct V_40 * V_41 )
{
int V_44 ;
V_44 = V_41 -> V_124 ( V_41 , V_125 , V_125 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_20 ( V_41 , 6 ) ;
if ( V_44 )
return V_44 ;
F_21 ( V_41 , F_22 ( 2 ) ) ;
F_21 ( V_41 , F_71 ( V_41 ) ) ;
F_21 ( V_41 , V_126 ) ;
F_21 ( V_41 , F_72 ( V_41 ) ) ;
F_21 ( V_41 , F_69 ( V_46 ) ) ;
F_21 ( V_41 , V_127 ) ;
F_25 ( V_41 ) ;
if ( V_41 -> V_128 != V_129 ) {
V_44 = V_41 -> V_124 ( V_41 , V_125 , V_125 ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
static int F_74 ( struct V_45 * V_46 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = V_46 -> V_57 . V_2 ;
struct V_110 * V_111 = V_2 -> V_112 ;
F_75 ( F_71 ( V_41 ) , V_126 ) ;
F_75 ( F_72 ( V_41 ) , F_69 ( V_46 ) ) ;
F_76 ( F_71 ( V_41 ) ) ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
struct V_40 * V_41 ;
int V_88 ;
F_78 (ring, dev_priv, j) {
F_75 ( F_79 ( V_41 ) ,
F_80 ( V_130 ) ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
struct V_40 * V_41 ;
T_8 V_131 , V_132 ;
int V_47 ;
V_132 = F_82 ( V_133 ) ;
F_75 ( V_133 , V_132 | V_134 ) ;
V_131 = F_82 ( V_135 ) ;
if ( F_83 ( V_2 ) ) {
V_131 |= V_136 ;
} else {
V_131 |= V_137 ;
V_131 &= ~ V_138 ;
}
F_75 ( V_135 , V_131 ) ;
F_78 (ring, dev_priv, i) {
F_75 ( F_79 ( V_41 ) ,
F_80 ( V_130 ) ) ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
T_8 V_131 , V_139 , V_132 ;
V_132 = F_82 ( V_133 ) ;
F_75 ( V_133 , V_132 | V_140 |
V_134 ) ;
V_139 = F_82 ( V_141 ) ;
F_75 ( V_141 , V_139 | V_142 ) ;
V_131 = F_82 ( V_135 ) ;
F_75 ( V_135 , V_131 | V_143 | V_144 ) ;
F_75 ( V_145 , F_80 ( V_130 ) ) ;
}
static void F_85 ( struct V_52 * V_53 ,
T_6 V_54 ,
T_6 V_55 ,
bool V_56 )
{
struct V_45 * V_46 =
F_28 ( V_53 , struct V_45 , V_57 ) ;
T_4 * V_58 , V_59 ;
unsigned V_146 = V_54 >> V_68 ;
unsigned V_67 = V_55 >> V_68 ;
unsigned V_147 = V_146 / V_121 ;
unsigned V_148 = V_146 % V_121 ;
unsigned V_69 , V_47 ;
V_59 = V_53 -> V_114 ( V_53 -> V_70 . V_12 , V_29 , true , 0 ) ;
while ( V_67 ) {
V_69 = V_148 + V_67 ;
if ( V_69 > V_121 )
V_69 = V_121 ;
V_58 = F_29 ( V_46 -> V_82 [ V_147 ] ) ;
for ( V_47 = V_148 ; V_47 < V_69 ; V_47 ++ )
V_58 [ V_47 ] = V_59 ;
F_32 ( V_58 ) ;
V_67 -= V_69 - V_148 ;
V_148 = 0 ;
V_147 ++ ;
}
}
static void F_86 ( struct V_52 * V_53 ,
struct V_76 * V_77 ,
T_6 V_54 ,
enum V_13 V_78 , T_5 V_33 )
{
struct V_45 * V_46 =
F_28 ( V_53 , struct V_45 , V_57 ) ;
T_4 * V_58 ;
unsigned V_146 = V_54 >> V_68 ;
unsigned V_147 = V_146 / V_121 ;
unsigned V_149 = V_146 % V_121 ;
struct V_79 V_80 ;
V_58 = NULL ;
F_34 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_58 == NULL )
V_58 = F_29 ( V_46 -> V_82 [ V_147 ] ) ;
V_58 [ V_149 ] =
V_53 -> V_114 ( F_36 ( & V_80 ) ,
V_78 , true , V_33 ) ;
if ( ++ V_149 == V_121 ) {
F_32 ( V_58 ) ;
V_58 = NULL ;
V_147 ++ ;
V_149 = 0 ;
}
}
if ( V_58 )
F_32 ( V_58 ) ;
}
static void F_87 ( struct V_45 * V_46 )
{
int V_47 ;
if ( V_46 -> V_119 ) {
for ( V_47 = 0 ; V_47 < V_46 -> V_49 ; V_47 ++ )
F_43 ( V_46 -> V_57 . V_2 -> V_8 ,
V_46 -> V_119 [ V_47 ] ,
4096 , V_89 ) ;
}
}
static void F_88 ( struct V_45 * V_46 )
{
int V_47 ;
F_40 ( V_46 -> V_119 ) ;
for ( V_47 = 0 ; V_47 < V_46 -> V_49 ; V_47 ++ )
F_89 ( V_46 -> V_82 [ V_47 ] ) ;
F_40 ( V_46 -> V_82 ) ;
}
static void F_90 ( struct V_52 * V_53 )
{
struct V_45 * V_46 =
F_28 ( V_53 , struct V_45 , V_57 ) ;
F_91 ( & V_46 -> V_150 ) ;
F_87 ( V_46 ) ;
F_88 ( V_46 ) ;
}
static int F_92 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_57 . V_2 ;
struct V_110 * V_111 = V_2 -> V_112 ;
bool V_151 = false ;
int V_44 ;
F_19 ( ! F_93 ( & V_111 -> V_115 . V_57 . V_152 ) ) ;
V_153:
V_44 = F_94 ( & V_111 -> V_115 . V_57 . V_152 ,
& V_46 -> V_150 , V_154 ,
V_155 , 0 ,
0 , V_111 -> V_115 . V_57 . V_107 ,
V_156 ) ;
if ( V_44 == - V_157 && ! V_151 ) {
V_44 = F_95 ( V_2 , & V_111 -> V_115 . V_57 ,
V_154 , V_155 ,
V_19 ,
0 , V_111 -> V_115 . V_57 . V_107 ,
0 ) ;
if ( V_44 )
return V_44 ;
V_151 = true ;
goto V_153;
}
if ( V_46 -> V_150 . V_54 < V_111 -> V_115 . V_158 )
F_96 ( L_13 ) ;
V_46 -> V_49 = V_159 ;
return V_44 ;
}
static int F_97 ( struct V_45 * V_46 )
{
int V_47 ;
V_46 -> V_82 = F_46 ( V_46 -> V_49 , sizeof( struct V_71 * ) ,
V_90 ) ;
if ( ! V_46 -> V_82 )
return - V_91 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_49 ; V_47 ++ ) {
V_46 -> V_82 [ V_47 ] = F_48 ( V_90 ) ;
if ( ! V_46 -> V_82 [ V_47 ] ) {
F_88 ( V_46 ) ;
return - V_91 ;
}
}
return 0 ;
}
static int F_98 ( struct V_45 * V_46 )
{
int V_44 ;
V_44 = F_92 ( V_46 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_97 ( V_46 ) ;
if ( V_44 ) {
F_91 ( & V_46 -> V_150 ) ;
return V_44 ;
}
V_46 -> V_119 = F_46 ( V_46 -> V_49 , sizeof( T_2 ) ,
V_90 ) ;
if ( ! V_46 -> V_119 ) {
F_91 ( & V_46 -> V_150 ) ;
F_88 ( V_46 ) ;
return - V_91 ;
}
return 0 ;
}
static int F_99 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_57 . V_2 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_49 ; V_47 ++ ) {
T_2 V_98 ;
V_98 = F_57 ( V_2 -> V_8 , V_46 -> V_82 [ V_47 ] , 0 , 4096 ,
V_89 ) ;
if ( F_58 ( V_2 -> V_8 , V_98 ) ) {
F_87 ( V_46 ) ;
return - V_160 ;
}
V_46 -> V_119 [ V_47 ] = V_98 ;
}
return 0 ;
}
static int F_100 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_57 . V_2 ;
struct V_110 * V_111 = V_2 -> V_112 ;
int V_44 ;
V_46 -> V_57 . V_114 = V_111 -> V_115 . V_57 . V_114 ;
if ( F_101 ( V_2 ) ) {
V_46 -> V_103 = F_74 ;
} else if ( F_83 ( V_2 ) ) {
V_46 -> V_103 = F_70 ;
} else if ( F_102 ( V_2 ) ) {
V_46 -> V_103 = F_73 ;
} else
F_103 () ;
V_44 = F_98 ( V_46 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_99 ( V_46 ) ;
if ( V_44 ) {
F_88 ( V_46 ) ;
return V_44 ;
}
V_46 -> V_57 . V_104 = F_85 ;
V_46 -> V_57 . V_105 = F_86 ;
V_46 -> V_57 . V_106 = F_90 ;
V_46 -> V_57 . V_54 = 0 ;
V_46 -> V_57 . V_107 = V_46 -> V_49 * V_121 * V_75 ;
V_46 -> V_161 = F_62 ;
V_46 -> V_117 =
V_46 -> V_150 . V_54 / V_75 * sizeof( T_4 ) ;
V_46 -> V_57 . V_104 ( & V_46 -> V_57 , 0 , V_46 -> V_57 . V_107 , true ) ;
F_7 ( L_14 ,
V_46 -> V_150 . V_100 >> 20 ,
V_46 -> V_150 . V_54 / V_75 ) ;
F_67 ( V_46 ) ;
F_96 ( L_15 ,
V_46 -> V_117 << 10 ) ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
V_46 -> V_57 . V_2 = V_2 ;
V_46 -> V_57 . V_70 = V_111 -> V_115 . V_57 . V_70 ;
if ( F_2 ( V_2 ) -> V_6 < 8 )
return F_100 ( V_46 ) ;
else
return F_60 ( V_46 , V_111 -> V_115 . V_57 . V_107 ) ;
}
int F_105 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
int V_44 = 0 ;
V_44 = F_104 ( V_2 , V_46 ) ;
if ( V_44 == 0 ) {
F_106 ( & V_46 -> V_162 ) ;
F_107 ( & V_46 -> V_57 . V_152 , V_46 -> V_57 . V_54 ,
V_46 -> V_57 . V_107 ) ;
F_108 ( V_111 , & V_46 -> V_57 ) ;
}
return V_44 ;
}
int F_109 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
struct V_40 * V_41 ;
struct V_45 * V_46 = V_111 -> V_152 . V_163 ;
int V_47 , V_44 = 0 ;
if ( V_10 . V_11 )
return 0 ;
if ( ! F_110 ( V_2 ) )
return 0 ;
if ( F_101 ( V_2 ) )
F_84 ( V_2 ) ;
else if ( F_102 ( V_2 ) )
F_81 ( V_2 ) ;
else if ( F_2 ( V_2 ) -> V_6 >= 8 )
F_77 ( V_2 ) ;
else
F_12 ( F_2 ( V_2 ) -> V_6 ) ;
if ( V_46 ) {
F_78 (ring, dev_priv, i) {
V_44 = V_46 -> V_103 ( V_46 , V_41 ) ;
if ( V_44 != 0 )
return V_44 ;
}
}
return V_44 ;
}
struct V_45 *
F_111 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
struct V_45 * V_46 ;
int V_44 ;
V_46 = F_112 ( sizeof( * V_46 ) , V_90 ) ;
if ( ! V_46 )
return F_47 ( - V_91 ) ;
V_44 = F_105 ( V_2 , V_46 ) ;
if ( V_44 ) {
F_40 ( V_46 ) ;
return F_47 ( V_44 ) ;
}
V_46 -> V_166 = V_165 ;
F_113 ( & V_46 -> V_57 ) ;
return V_46 ;
}
void F_114 ( struct V_167 * V_167 )
{
struct V_45 * V_46 =
F_28 ( V_167 , struct V_45 , V_162 ) ;
F_115 ( & V_46 -> V_57 ) ;
F_35 ( ! F_116 ( & V_46 -> V_57 . V_168 ) ) ;
F_35 ( ! F_116 ( & V_46 -> V_57 . V_169 ) ) ;
F_117 ( & V_46 -> V_57 . V_170 ) ;
F_118 ( & V_46 -> V_57 . V_152 ) ;
V_46 -> V_57 . V_106 ( & V_46 -> V_57 ) ;
F_40 ( V_46 ) ;
}
static void
F_119 ( struct V_171 * V_172 ,
enum V_13 V_78 ,
T_5 V_33 )
{
if ( V_172 -> V_173 -> V_174 )
V_33 |= V_34 ;
V_172 -> V_53 -> V_105 ( V_172 -> V_53 , V_172 -> V_173 -> V_77 , V_172 -> V_150 . V_54 ,
V_78 , V_33 ) ;
}
static void F_120 ( struct V_171 * V_172 )
{
V_172 -> V_53 -> V_104 ( V_172 -> V_53 ,
V_172 -> V_150 . V_54 ,
V_172 -> V_173 -> V_57 . V_100 ,
true ) ;
}
static inline bool F_121 ( struct V_1 * V_2 )
{
#ifdef F_3
if ( F_122 ( V_2 ) && F_123 ( V_2 ) && V_7 )
return true ;
#endif
return false ;
}
static bool F_124 ( struct V_110 * V_111 )
{
bool V_44 = V_111 -> V_152 . V_175 ;
if ( F_125 ( V_111 -> V_115 . V_176 ) ) {
V_111 -> V_152 . V_175 = false ;
if ( F_126 ( V_111 -> V_2 ) ) {
F_127 ( L_16 ) ;
F_128 ( 10 ) ;
}
}
return V_44 ;
}
static void F_129 ( struct V_110 * V_111 , bool V_175 )
{
if ( F_125 ( V_111 -> V_115 . V_176 ) )
V_111 -> V_152 . V_175 = V_175 ;
}
void F_130 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
struct V_40 * V_41 ;
int V_47 ;
if ( F_2 ( V_2 ) -> V_6 < 6 )
return;
F_78 (ring, dev_priv, i) {
T_5 V_177 ;
V_177 = F_82 ( F_131 ( V_41 ) ) ;
if ( V_177 & V_178 ) {
F_7 ( L_17
L_18
L_19
L_20
L_21 ,
V_177 & V_179 ,
V_177 & V_180 ? L_22 : L_23 ,
F_132 ( V_177 ) ,
F_133 ( V_177 ) ) ;
F_75 ( F_131 ( V_41 ) ,
V_177 & ~ V_178 ) ;
}
}
F_76 ( F_131 ( & V_111 -> V_41 [ V_129 ] ) ) ;
}
static void F_134 ( struct V_110 * V_111 )
{
if ( F_2 ( V_111 -> V_2 ) -> V_6 < 6 ) {
F_135 () ;
} else {
F_75 ( V_181 , V_182 ) ;
F_76 ( V_181 ) ;
}
}
void F_136 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
if ( F_2 ( V_2 ) -> V_6 < 6 )
return;
F_130 ( V_2 ) ;
V_111 -> V_115 . V_57 . V_104 ( & V_111 -> V_115 . V_57 ,
V_111 -> V_115 . V_57 . V_54 ,
V_111 -> V_115 . V_57 . V_107 ,
true ) ;
F_134 ( V_111 ) ;
}
void F_137 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
struct V_183 * V_173 ;
struct V_52 * V_53 ;
F_130 ( V_2 ) ;
V_111 -> V_115 . V_57 . V_104 ( & V_111 -> V_115 . V_57 ,
V_111 -> V_115 . V_57 . V_54 ,
V_111 -> V_115 . V_57 . V_107 ,
true ) ;
F_138 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_171 * V_172 = F_139 ( V_173 ,
& V_111 -> V_115 . V_57 ) ;
if ( ! V_172 )
continue;
F_140 ( V_173 , V_173 -> V_184 ) ;
V_172 -> V_185 &= ~ V_186 ;
F_35 ( F_141 ( V_172 , V_173 -> V_78 , V_186 ) ) ;
}
if ( F_2 ( V_2 ) -> V_6 >= 8 ) {
if ( F_6 ( V_2 ) )
F_142 ( V_111 ) ;
else
F_143 ( V_111 ) ;
return;
}
F_138 (vm, &dev_priv->vm_list, global_link) {
if ( F_144 ( V_53 ) ) {
if ( V_111 -> V_152 . V_163 )
F_67 ( V_111 -> V_152 . V_163 ) ;
continue;
}
F_67 ( F_28 ( V_53 , struct V_45 , V_57 ) ) ;
}
F_134 ( V_111 ) ;
}
int F_145 ( struct V_183 * V_173 )
{
if ( V_173 -> V_187 )
return 0 ;
if ( ! F_146 ( & V_173 -> V_57 . V_2 -> V_8 -> V_2 ,
V_173 -> V_77 -> V_188 , V_173 -> V_77 -> V_189 ,
V_89 ) )
return - V_157 ;
return 0 ;
}
static inline void F_147 ( void T_7 * V_12 , T_1 V_16 )
{
#ifdef F_148
F_148 ( V_16 , V_12 ) ;
#else
F_149 ( ( T_5 ) V_16 , V_12 ) ;
F_149 ( V_16 >> 32 , V_12 + 4 ) ;
#endif
}
static void F_150 ( struct V_52 * V_53 ,
struct V_76 * V_190 ,
T_6 V_54 ,
enum V_13 V_14 , T_5 V_26 )
{
struct V_110 * V_111 = V_53 -> V_2 -> V_112 ;
unsigned V_146 = V_54 >> V_68 ;
T_1 T_7 * V_191 =
( T_1 T_7 * ) V_111 -> V_115 . V_116 + V_146 ;
int V_47 = 0 ;
struct V_79 V_80 ;
T_2 V_12 = 0 ;
F_34 (st->sgl, &sg_iter, st->nents, 0 ) {
V_12 = F_151 ( V_80 . V_192 ) +
( V_80 . V_193 << V_68 ) ;
F_147 ( & V_191 [ V_47 ] ,
F_8 ( V_12 , V_14 , true ) ) ;
V_47 ++ ;
}
if ( V_47 != 0 )
F_35 ( F_152 ( & V_191 [ V_47 - 1 ] )
!= F_8 ( V_12 , V_14 , true ) ) ;
F_75 ( V_181 , V_182 ) ;
F_76 ( V_181 ) ;
}
static void F_153 ( struct V_52 * V_53 ,
struct V_76 * V_190 ,
T_6 V_54 ,
enum V_13 V_14 , T_5 V_33 )
{
struct V_110 * V_111 = V_53 -> V_2 -> V_112 ;
unsigned V_146 = V_54 >> V_68 ;
T_4 T_7 * V_191 =
( T_4 T_7 * ) V_111 -> V_115 . V_116 + V_146 ;
int V_47 = 0 ;
struct V_79 V_80 ;
T_2 V_12 = 0 ;
F_34 (st->sgl, &sg_iter, st->nents, 0 ) {
V_12 = F_36 ( & V_80 ) ;
F_149 ( V_53 -> V_114 ( V_12 , V_14 , true , V_33 ) , & V_191 [ V_47 ] ) ;
V_47 ++ ;
}
if ( V_47 != 0 ) {
unsigned long V_115 = F_64 ( & V_191 [ V_47 - 1 ] ) ;
F_35 ( V_115 != V_53 -> V_114 ( V_12 , V_14 , true , V_33 ) ) ;
}
F_75 ( V_181 , V_182 ) ;
F_76 ( V_181 ) ;
}
static void F_154 ( struct V_52 * V_53 ,
T_6 V_54 ,
T_6 V_55 ,
bool V_56 )
{
struct V_110 * V_111 = V_53 -> V_2 -> V_112 ;
unsigned V_146 = V_54 >> V_68 ;
unsigned V_67 = V_55 >> V_68 ;
T_1 V_59 , T_7 * V_194 =
( T_1 T_7 * ) V_111 -> V_115 . V_116 + V_146 ;
const int V_195 = F_155 ( V_111 -> V_115 ) - V_146 ;
int V_47 ;
if ( F_156 ( V_67 > V_195 ,
L_24 ,
V_146 , V_67 , V_195 ) )
V_67 = V_195 ;
V_59 = F_8 ( V_53 -> V_70 . V_12 ,
V_29 ,
V_56 ) ;
for ( V_47 = 0 ; V_47 < V_67 ; V_47 ++ )
F_147 ( & V_194 [ V_47 ] , V_59 ) ;
F_64 ( V_194 ) ;
}
static void F_157 ( struct V_52 * V_53 ,
T_6 V_54 ,
T_6 V_55 ,
bool V_56 )
{
struct V_110 * V_111 = V_53 -> V_2 -> V_112 ;
unsigned V_146 = V_54 >> V_68 ;
unsigned V_67 = V_55 >> V_68 ;
T_4 V_59 , T_7 * V_194 =
( T_4 T_7 * ) V_111 -> V_115 . V_116 + V_146 ;
const int V_195 = F_155 ( V_111 -> V_115 ) - V_146 ;
int V_47 ;
if ( F_156 ( V_67 > V_195 ,
L_24 ,
V_146 , V_67 , V_195 ) )
V_67 = V_195 ;
V_59 = V_53 -> V_114 ( V_53 -> V_70 . V_12 , V_29 , V_56 , 0 ) ;
for ( V_47 = 0 ; V_47 < V_67 ; V_47 ++ )
F_149 ( V_59 , & V_194 [ V_47 ] ) ;
F_64 ( V_194 ) ;
}
static void F_158 ( struct V_171 * V_172 ,
enum V_13 V_78 ,
T_5 V_26 )
{
const unsigned long V_42 = V_172 -> V_150 . V_54 >> V_68 ;
unsigned int V_33 = ( V_78 == V_19 ) ?
V_196 : V_197 ;
F_19 ( ! F_144 ( V_172 -> V_53 ) ) ;
F_159 ( V_172 -> V_198 . V_77 , V_42 , V_33 ) ;
V_172 -> V_185 = V_186 ;
}
static void F_160 ( struct V_52 * V_53 ,
T_6 V_54 ,
T_6 V_55 ,
bool V_26 )
{
unsigned V_146 = V_54 >> V_68 ;
unsigned V_67 = V_55 >> V_68 ;
F_161 ( V_146 , V_67 ) ;
}
static void F_162 ( struct V_171 * V_172 )
{
const unsigned int V_199 = V_172 -> V_150 . V_54 >> V_68 ;
const unsigned int V_100 = V_172 -> V_173 -> V_57 . V_100 >> V_68 ;
F_19 ( ! F_144 ( V_172 -> V_53 ) ) ;
V_172 -> V_185 = 0 ;
F_161 ( V_199 , V_100 ) ;
}
static void F_163 ( struct V_171 * V_172 ,
enum V_13 V_78 ,
T_5 V_33 )
{
struct V_1 * V_2 = V_172 -> V_53 -> V_2 ;
struct V_110 * V_111 = V_2 -> V_112 ;
struct V_183 * V_173 = V_172 -> V_173 ;
if ( V_173 -> V_174 )
V_33 |= V_34 ;
if ( ! V_111 -> V_152 . V_163 || V_33 & V_186 ) {
if ( ! ( V_172 -> V_185 & V_186 ) ||
( V_78 != V_173 -> V_78 ) ) {
V_172 -> V_53 -> V_105 ( V_172 -> V_53 , V_172 -> V_198 . V_77 ,
V_172 -> V_150 . V_54 ,
V_78 , V_33 ) ;
V_172 -> V_185 |= V_186 ;
}
}
if ( V_111 -> V_152 . V_163 &&
( ! ( V_172 -> V_185 & V_200 ) ||
( V_78 != V_173 -> V_78 ) ) ) {
struct V_45 * V_201 = V_111 -> V_152 . V_163 ;
V_201 -> V_57 . V_105 ( & V_201 -> V_57 ,
V_172 -> V_198 . V_77 ,
V_172 -> V_150 . V_54 ,
V_78 , V_33 ) ;
V_172 -> V_185 |= V_200 ;
}
}
static void F_164 ( struct V_171 * V_172 )
{
struct V_1 * V_2 = V_172 -> V_53 -> V_2 ;
struct V_110 * V_111 = V_2 -> V_112 ;
struct V_183 * V_173 = V_172 -> V_173 ;
if ( V_172 -> V_185 & V_186 ) {
V_172 -> V_53 -> V_104 ( V_172 -> V_53 ,
V_172 -> V_150 . V_54 ,
V_173 -> V_57 . V_100 ,
true ) ;
V_172 -> V_185 &= ~ V_186 ;
}
if ( V_172 -> V_185 & V_200 ) {
struct V_45 * V_201 = V_111 -> V_152 . V_163 ;
V_201 -> V_57 . V_104 ( & V_201 -> V_57 ,
V_172 -> V_150 . V_54 ,
V_173 -> V_57 . V_100 ,
true ) ;
V_172 -> V_185 &= ~ V_200 ;
}
}
void F_165 ( struct V_183 * V_173 )
{
struct V_1 * V_2 = V_173 -> V_57 . V_2 ;
struct V_110 * V_111 = V_2 -> V_112 ;
bool V_175 ;
V_175 = F_124 ( V_111 ) ;
if ( ! V_173 -> V_187 )
F_166 ( & V_2 -> V_8 -> V_2 ,
V_173 -> V_77 -> V_188 , V_173 -> V_77 -> V_189 ,
V_89 ) ;
F_129 ( V_111 , V_175 ) ;
}
static void F_167 ( struct V_202 * V_150 ,
unsigned long V_203 ,
T_9 * V_54 ,
T_9 * V_204 )
{
if ( V_150 -> V_203 != V_203 )
* V_54 += 4096 ;
if ( ! F_116 ( & V_150 -> V_205 ) ) {
V_150 = F_168 ( V_150 -> V_205 . V_206 ,
struct V_202 ,
V_205 ) ;
if ( V_150 -> V_207 && V_150 -> V_203 != V_203 )
* V_204 -= 4096 ;
}
}
static int F_169 ( struct V_1 * V_2 ,
unsigned long V_54 ,
unsigned long V_158 ,
unsigned long V_204 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
struct V_52 * V_208 = & V_111 -> V_115 . V_57 ;
struct V_202 * V_42 ;
struct V_183 * V_173 ;
unsigned long V_209 , V_210 ;
int V_44 ;
F_19 ( V_158 > V_204 ) ;
F_107 ( & V_208 -> V_152 , V_54 , V_204 - V_54 - V_75 ) ;
if ( ! F_30 ( V_2 ) )
V_111 -> V_115 . V_57 . V_152 . V_211 = F_167 ;
F_138 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_171 * V_172 = F_139 ( V_173 , V_208 ) ;
F_170 ( L_25 ,
F_171 ( V_173 ) , V_173 -> V_57 . V_100 ) ;
F_35 ( F_172 ( V_173 ) ) ;
V_44 = F_173 ( & V_208 -> V_152 , & V_172 -> V_150 ) ;
if ( V_44 ) {
F_170 ( L_26 , V_44 ) ;
return V_44 ;
}
V_172 -> V_185 |= V_186 ;
}
V_111 -> V_115 . V_57 . V_54 = V_54 ;
V_111 -> V_115 . V_57 . V_107 = V_204 - V_54 ;
F_174 (entry, &ggtt_vm->mm, hole_start, hole_end) {
F_170 ( L_27 ,
V_209 , V_210 ) ;
V_208 -> V_104 ( V_208 , V_209 ,
V_210 - V_209 , true ) ;
}
V_208 -> V_104 ( V_208 , V_204 - V_75 , V_75 , true ) ;
if ( F_110 ( V_2 ) && ! F_175 ( V_2 ) ) {
struct V_45 * V_46 ;
V_46 = F_112 ( sizeof( * V_46 ) , V_90 ) ;
if ( ! V_46 )
return - V_91 ;
V_44 = F_104 ( V_2 , V_46 ) ;
if ( V_44 != 0 )
return V_44 ;
V_111 -> V_152 . V_163 = V_46 ;
}
return 0 ;
}
void F_176 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
unsigned long V_212 , V_213 ;
V_212 = V_111 -> V_115 . V_57 . V_107 ;
V_213 = V_111 -> V_115 . V_158 ;
F_169 ( V_2 , 0 , V_213 , V_212 ) ;
}
void F_177 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
struct V_52 * V_53 = & V_111 -> V_115 . V_57 ;
if ( V_111 -> V_152 . V_163 ) {
struct V_45 * V_46 = V_111 -> V_152 . V_163 ;
V_46 -> V_57 . V_106 ( & V_46 -> V_57 ) ;
}
if ( F_93 ( & V_53 -> V_152 ) ) {
F_118 ( & V_53 -> V_152 ) ;
F_117 ( & V_53 -> V_170 ) ;
}
V_53 -> V_106 ( V_53 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
struct V_71 * V_71 ;
T_2 V_214 ;
V_71 = F_48 ( V_90 | V_215 | V_216 ) ;
if ( V_71 == NULL )
return - V_91 ;
F_179 ( V_71 , 1 ) ;
#ifdef F_3
V_214 = F_57 ( V_2 -> V_8 , V_71 , 0 , V_75 ,
V_89 ) ;
if ( F_58 ( V_2 -> V_8 , V_214 ) )
return - V_217 ;
#else
V_214 = F_180 ( V_71 ) ;
#endif
V_111 -> V_115 . V_57 . V_70 . V_71 = V_71 ;
V_111 -> V_115 . V_57 . V_70 . V_12 = V_214 ;
return 0 ;
}
static void F_181 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
struct V_71 * V_71 = V_111 -> V_115 . V_57 . V_70 . V_71 ;
F_182 ( V_71 , 1 ) ;
F_43 ( V_2 -> V_8 , V_111 -> V_115 . V_57 . V_70 . V_12 ,
V_75 , V_89 ) ;
F_89 ( V_71 ) ;
}
static inline unsigned int F_183 ( T_10 V_218 )
{
V_218 >>= V_219 ;
V_218 &= V_220 ;
return V_218 << 20 ;
}
static inline unsigned int F_184 ( T_10 V_221 )
{
V_221 >>= V_222 ;
V_221 &= V_223 ;
if ( V_221 )
V_221 = 1 << V_221 ;
#ifdef F_185
if ( V_221 > 4 )
V_221 = 4 ;
#endif
return V_221 << 20 ;
}
static inline unsigned int F_186 ( T_10 V_224 )
{
V_224 >>= V_219 ;
V_224 &= V_220 ;
if ( V_224 )
return 1 << ( 20 + V_224 ) ;
return 0 ;
}
static inline T_11 F_187 ( T_10 V_218 )
{
V_218 >>= V_225 ;
V_218 &= V_226 ;
return V_218 << 25 ;
}
static inline T_11 F_188 ( T_10 V_221 )
{
V_221 >>= V_227 ;
V_221 &= V_228 ;
return V_221 << 25 ;
}
static T_11 F_189 ( T_10 V_224 )
{
V_224 >>= V_225 ;
V_224 &= V_226 ;
if ( V_224 < 0x11 )
return V_224 << 25 ;
else if ( V_224 < 0x17 )
return ( V_224 - 0x11 + 2 ) << 22 ;
else
return ( V_224 - 0x17 + 9 ) << 22 ;
}
static T_11 F_190 ( T_10 V_229 )
{
V_229 >>= V_227 ;
V_229 &= V_228 ;
if ( V_229 < 0xf0 )
return V_229 << 25 ;
else
return ( V_229 - 0xf0 + 1 ) << 22 ;
}
static int F_191 ( struct V_1 * V_2 ,
T_11 V_212 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
T_12 V_230 ;
int V_44 ;
V_230 = F_192 ( V_2 -> V_8 , 0 ) +
( F_193 ( V_2 -> V_8 , 0 ) / 2 ) ;
V_111 -> V_115 . V_116 = F_194 ( V_230 , V_212 ) ;
if ( ! V_111 -> V_115 . V_116 ) {
F_127 ( L_28 ) ;
return - V_91 ;
}
V_44 = F_178 ( V_2 ) ;
if ( V_44 ) {
F_127 ( L_29 ) ;
F_195 ( V_111 -> V_115 . V_116 ) ;
}
return V_44 ;
}
static void F_143 ( struct V_110 * V_111 )
{
T_6 V_231 ;
V_231 = F_196 ( 0 , V_232 | V_233 ) |
F_196 ( 1 , V_234 | V_235 ) |
F_196 ( 2 , V_236 | V_235 ) |
F_196 ( 3 , V_237 ) |
F_196 ( 4 , V_232 | V_235 | F_197 ( 0 ) ) |
F_196 ( 5 , V_232 | V_235 | F_197 ( 1 ) ) |
F_196 ( 6 , V_232 | V_235 | F_197 ( 2 ) ) |
F_196 ( 7 , V_232 | V_235 | F_197 ( 3 ) ) ;
if ( ! F_110 ( V_111 -> V_2 ) )
V_231 = F_196 ( 0 , V_237 ) ;
F_75 ( V_238 , V_231 ) ;
F_75 ( V_238 + 4 , V_231 >> 32 ) ;
}
static void F_142 ( struct V_110 * V_111 )
{
T_6 V_231 ;
V_231 = F_196 ( 0 , V_239 ) |
F_196 ( 1 , 0 ) |
F_196 ( 2 , 0 ) |
F_196 ( 3 , 0 ) |
F_196 ( 4 , V_239 ) |
F_196 ( 5 , V_239 ) |
F_196 ( 6 , V_239 ) |
F_196 ( 7 , V_239 ) ;
F_75 ( V_238 , V_231 ) ;
F_75 ( V_238 + 4 , V_231 >> 32 ) ;
}
static int F_198 ( struct V_1 * V_2 ,
T_11 * V_240 ,
T_11 * V_241 ,
T_12 * V_242 ,
unsigned long * V_158 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
unsigned int V_212 ;
T_10 V_218 ;
int V_44 ;
* V_242 = F_192 ( V_2 -> V_8 , 2 ) ;
* V_158 = F_193 ( V_2 -> V_8 , 2 ) ;
if ( ! F_199 ( V_2 -> V_8 , F_200 ( 39 ) ) )
F_201 ( V_2 -> V_8 , F_200 ( 39 ) ) ;
F_202 ( V_2 -> V_8 , V_243 , & V_218 ) ;
if ( F_2 ( V_2 ) -> V_6 >= 9 ) {
* V_241 = F_190 ( V_218 ) ;
V_212 = F_184 ( V_218 ) ;
} else if ( F_6 ( V_2 ) ) {
* V_241 = F_189 ( V_218 ) ;
V_212 = F_186 ( V_218 ) ;
} else {
* V_241 = F_188 ( V_218 ) ;
V_212 = F_184 ( V_218 ) ;
}
* V_240 = ( V_212 / sizeof( T_1 ) ) << V_68 ;
if ( F_6 ( V_2 ) )
F_142 ( V_111 ) ;
else
F_143 ( V_111 ) ;
V_44 = F_191 ( V_2 , V_212 ) ;
V_111 -> V_115 . V_57 . V_104 = F_154 ;
V_111 -> V_115 . V_57 . V_105 = F_150 ;
return V_44 ;
}
static int F_203 ( struct V_1 * V_2 ,
T_11 * V_240 ,
T_11 * V_241 ,
T_12 * V_242 ,
unsigned long * V_158 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
unsigned int V_212 ;
T_10 V_218 ;
int V_44 ;
* V_242 = F_192 ( V_2 -> V_8 , 2 ) ;
* V_158 = F_193 ( V_2 -> V_8 , 2 ) ;
if ( ( * V_158 < ( 64 << 20 ) || ( * V_158 > ( 512 << 20 ) ) ) ) {
F_127 ( L_30 ,
V_111 -> V_115 . V_158 ) ;
return - V_244 ;
}
if ( ! F_199 ( V_2 -> V_8 , F_200 ( 40 ) ) )
F_201 ( V_2 -> V_8 , F_200 ( 40 ) ) ;
F_202 ( V_2 -> V_8 , V_243 , & V_218 ) ;
* V_241 = F_187 ( V_218 ) ;
V_212 = F_183 ( V_218 ) ;
* V_240 = ( V_212 / sizeof( T_4 ) ) << V_68 ;
V_44 = F_191 ( V_2 , V_212 ) ;
V_111 -> V_115 . V_57 . V_104 = F_157 ;
V_111 -> V_115 . V_57 . V_105 = F_153 ;
return V_44 ;
}
static void F_204 ( struct V_52 * V_53 )
{
struct V_245 * V_115 = F_28 ( V_53 , struct V_245 , V_57 ) ;
F_195 ( V_115 -> V_116 ) ;
F_181 ( V_53 -> V_2 ) ;
}
static int F_205 ( struct V_1 * V_2 ,
T_11 * V_240 ,
T_11 * V_241 ,
T_12 * V_242 ,
unsigned long * V_158 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
int V_44 ;
V_44 = F_206 ( V_111 -> V_246 , V_111 -> V_2 -> V_8 , NULL ) ;
if ( ! V_44 ) {
F_127 ( L_31 ) ;
return - V_160 ;
}
F_207 ( V_240 , V_241 , V_242 , V_158 ) ;
V_111 -> V_115 . V_176 = F_121 ( V_111 -> V_2 ) ;
V_111 -> V_115 . V_57 . V_104 = F_160 ;
if ( F_125 ( V_111 -> V_115 . V_176 ) )
F_4 ( L_32 ) ;
return 0 ;
}
static void F_208 ( struct V_52 * V_53 )
{
F_209 () ;
}
int F_210 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
struct V_245 * V_115 = & V_111 -> V_115 ;
int V_44 ;
if ( F_2 ( V_2 ) -> V_6 <= 5 ) {
V_115 -> V_247 = F_205 ;
V_115 -> V_57 . V_106 = F_208 ;
} else if ( F_2 ( V_2 ) -> V_6 < 8 ) {
V_115 -> V_247 = F_203 ;
V_115 -> V_57 . V_106 = F_204 ;
if ( F_83 ( V_2 ) && V_111 -> V_248 )
V_115 -> V_57 . V_114 = F_17 ;
else if ( F_83 ( V_2 ) )
V_115 -> V_57 . V_114 = F_15 ;
else if ( F_5 ( V_2 ) )
V_115 -> V_57 . V_114 = F_14 ;
else if ( F_2 ( V_2 ) -> V_6 >= 7 )
V_115 -> V_57 . V_114 = F_13 ;
else
V_115 -> V_57 . V_114 = F_10 ;
} else {
V_111 -> V_115 . V_247 = F_198 ;
V_111 -> V_115 . V_57 . V_106 = F_204 ;
}
V_44 = V_115 -> V_247 ( V_2 , & V_115 -> V_57 . V_107 , & V_115 -> V_249 ,
& V_115 -> V_242 , & V_115 -> V_158 ) ;
if ( V_44 )
return V_44 ;
V_115 -> V_57 . V_2 = V_2 ;
F_4 ( L_33 ,
V_115 -> V_57 . V_107 >> 20 ) ;
F_7 ( L_34 , V_115 -> V_158 >> 20 ) ;
F_7 ( L_35 , V_115 -> V_249 >> 20 ) ;
#ifdef F_3
if ( V_7 )
F_4 ( L_36 ) ;
#endif
V_10 . V_3 = F_1 ( V_2 , V_10 . V_3 ) ;
F_7 ( L_37 , V_10 . V_3 ) ;
return 0 ;
}
static struct V_171 * F_211 ( struct V_183 * V_173 ,
struct V_52 * V_53 ,
const struct V_250 * V_251 )
{
struct V_171 * V_172 = F_112 ( sizeof( * V_172 ) , V_90 ) ;
if ( V_172 == NULL )
return F_47 ( - V_91 ) ;
F_212 ( & V_172 -> V_252 ) ;
F_212 ( & V_172 -> V_253 ) ;
F_212 ( & V_172 -> V_254 ) ;
V_172 -> V_53 = V_53 ;
V_172 -> V_173 = V_173 ;
V_172 -> V_198 = * V_251 ;
if ( F_2 ( V_53 -> V_2 ) -> V_6 >= 6 ) {
if ( F_144 ( V_53 ) ) {
V_172 -> V_255 = F_164 ;
V_172 -> V_256 = F_163 ;
} else {
V_172 -> V_255 = F_120 ;
V_172 -> V_256 = F_119 ;
}
} else {
F_19 ( ! F_144 ( V_53 ) ) ;
V_172 -> V_255 = F_162 ;
V_172 -> V_256 = F_158 ;
}
F_213 ( & V_172 -> V_252 , & V_173 -> V_257 ) ;
if ( ! F_144 ( V_53 ) )
F_214 ( F_215 ( V_53 ) ) ;
return V_172 ;
}
struct V_171 *
F_216 ( struct V_183 * V_173 ,
struct V_52 * V_53 ,
const struct V_250 * V_251 )
{
struct V_171 * V_172 ;
V_172 = F_217 ( V_173 , V_53 , V_251 ) ;
if ( ! V_172 )
V_172 = F_211 ( V_173 , V_53 , V_251 ) ;
return V_172 ;
}
static inline
int F_218 ( struct V_171 * V_172 )
{
if ( V_172 -> V_198 . V_77 )
return 0 ;
if ( V_172 -> V_198 . type == V_258 )
V_172 -> V_198 . V_77 = V_172 -> V_173 -> V_77 ;
else
F_219 ( 1 , L_38 ,
V_172 -> V_198 . type ) ;
if ( ! V_172 -> V_198 . V_77 ) {
F_127 ( L_39 ,
V_172 -> V_198 . type ) ;
return - V_217 ;
}
return 0 ;
}
int F_141 ( struct V_171 * V_172 , enum V_13 V_78 ,
T_5 V_33 )
{
int V_44 = F_218 ( V_172 ) ;
if ( V_44 )
return V_44 ;
V_172 -> V_256 ( V_172 , V_78 , V_33 ) ;
return 0 ;
}
