static int F_1 ( struct V_1 * V_2 , int V_3 )
{
bool V_4 ;
bool V_5 ;
V_4 = F_2 ( V_2 ) -> V_6 >= 6 ;
V_5 = F_2 ( V_2 ) -> V_6 >= 7 ;
if ( F_3 ( V_2 ) )
V_5 = false ;
if ( F_2 ( V_2 ) -> V_6 < 9 &&
( V_3 == 0 || ! V_4 ) )
return 0 ;
if ( V_3 == 1 )
return 1 ;
if ( V_3 == 2 && V_5 )
return 2 ;
#ifdef F_4
if ( F_2 ( V_2 ) -> V_6 == 6 && V_7 ) {
F_5 ( L_1 ) ;
return 0 ;
}
#endif
if ( F_6 ( V_2 ) && ! F_7 ( V_2 ) &&
V_2 -> V_8 -> V_9 < 0xb ) {
F_8 ( L_2 ) ;
return 0 ;
}
return V_4 ? 1 : 0 ;
}
static inline T_1 F_9 ( T_2 V_10 ,
enum V_11 V_12 ,
bool V_13 )
{
T_1 V_14 = V_13 ? V_15 | V_16 : 0 ;
V_14 |= V_10 ;
switch ( V_12 ) {
case V_17 :
V_14 |= V_18 ;
break;
case V_19 :
V_14 |= V_20 ;
break;
default:
V_14 |= V_21 ;
break;
}
return V_14 ;
}
static inline T_3 F_10 ( struct V_1 * V_2 ,
T_2 V_10 ,
enum V_11 V_12 )
{
T_3 V_22 = V_15 | V_16 ;
V_22 |= V_10 ;
if ( V_12 != V_17 )
V_22 |= V_23 ;
else
V_22 |= V_18 ;
return V_22 ;
}
static T_4 F_11 ( T_2 V_10 ,
enum V_11 V_12 ,
bool V_13 , T_5 V_24 )
{
T_4 V_14 = V_13 ? V_25 : 0 ;
V_14 |= F_12 ( V_10 ) ;
switch ( V_12 ) {
case V_26 :
case V_27 :
V_14 |= V_28 ;
break;
case V_17 :
V_14 |= V_29 ;
break;
default:
F_13 ( 1 ) ;
}
return V_14 ;
}
static T_4 F_14 ( T_2 V_10 ,
enum V_11 V_12 ,
bool V_13 , T_5 V_24 )
{
T_4 V_14 = V_13 ? V_25 : 0 ;
V_14 |= F_12 ( V_10 ) ;
switch ( V_12 ) {
case V_26 :
V_14 |= V_30 ;
break;
case V_27 :
V_14 |= V_28 ;
break;
case V_17 :
V_14 |= V_29 ;
break;
default:
F_13 ( 1 ) ;
}
return V_14 ;
}
static T_4 F_15 ( T_2 V_10 ,
enum V_11 V_12 ,
bool V_13 , T_5 V_31 )
{
T_4 V_14 = V_13 ? V_25 : 0 ;
V_14 |= F_12 ( V_10 ) ;
if ( ! ( V_31 & V_32 ) )
V_14 |= V_33 ;
if ( V_12 != V_17 )
V_14 |= V_34 ;
return V_14 ;
}
static T_4 F_16 ( T_2 V_10 ,
enum V_11 V_12 ,
bool V_13 , T_5 V_24 )
{
T_4 V_14 = V_13 ? V_25 : 0 ;
V_14 |= F_17 ( V_10 ) ;
if ( V_12 != V_17 )
V_14 |= V_35 ;
return V_14 ;
}
static T_4 F_18 ( T_2 V_10 ,
enum V_11 V_12 ,
bool V_13 , T_5 V_24 )
{
T_4 V_14 = V_13 ? V_25 : 0 ;
V_14 |= F_17 ( V_10 ) ;
switch ( V_12 ) {
case V_17 :
break;
case V_19 :
V_14 |= V_36 ;
break;
default:
V_14 |= V_37 ;
break;
}
return V_14 ;
}
static int F_19 ( struct V_38 * V_39 , unsigned V_40 ,
T_6 V_41 )
{
int V_42 ;
F_20 ( V_40 >= 4 ) ;
V_42 = F_21 ( V_39 , 6 ) ;
if ( V_42 )
return V_42 ;
F_22 ( V_39 , F_23 ( 1 ) ) ;
F_22 ( V_39 , F_24 ( V_39 , V_40 ) ) ;
F_22 ( V_39 , ( T_5 ) ( V_41 >> 32 ) ) ;
F_22 ( V_39 , F_23 ( 1 ) ) ;
F_22 ( V_39 , F_25 ( V_39 , V_40 ) ) ;
F_22 ( V_39 , ( T_5 ) ( V_41 ) ) ;
F_26 ( V_39 ) ;
return 0 ;
}
static int F_27 ( struct V_43 * V_44 ,
struct V_38 * V_39 )
{
int V_45 , V_42 ;
int V_46 = V_44 -> V_47 / V_48 ;
for ( V_45 = V_46 - 1 ; V_45 >= 0 ; V_45 -- ) {
T_2 V_10 = V_44 -> V_49 [ V_45 ] ;
V_42 = F_19 ( V_39 , V_45 , V_10 ) ;
if ( V_42 )
return V_42 ;
}
return 0 ;
}
static void F_28 ( struct V_50 * V_51 ,
T_6 V_52 ,
T_6 V_53 ,
bool V_54 )
{
struct V_43 * V_44 =
F_29 ( V_51 , struct V_43 , V_55 ) ;
T_1 * V_56 , V_57 ;
unsigned V_58 = V_52 >> V_59 & V_60 ;
unsigned V_22 = V_52 >> V_61 & V_62 ;
unsigned V_14 = V_52 >> V_63 & V_64 ;
unsigned V_65 = V_53 >> V_66 ;
unsigned V_67 , V_45 ;
V_57 = F_9 ( V_44 -> V_55 . V_68 . V_10 ,
V_27 , V_54 ) ;
while ( V_65 ) {
struct V_69 * V_70 = V_44 -> V_71 [ V_58 ] [ V_22 ] ;
V_67 = V_14 + V_65 ;
if ( V_67 > V_72 )
V_67 = V_72 ;
V_56 = F_30 ( V_70 ) ;
for ( V_45 = V_14 ; V_45 < V_67 ; V_45 ++ ) {
V_56 [ V_45 ] = V_57 ;
V_65 -- ;
}
if ( ! F_31 ( V_44 -> V_55 . V_2 ) )
F_32 ( V_56 , V_73 ) ;
F_33 ( V_56 ) ;
V_14 = 0 ;
if ( ++ V_22 == V_48 ) {
V_58 ++ ;
V_22 = 0 ;
}
}
}
static void F_34 ( struct V_50 * V_51 ,
struct V_74 * V_75 ,
T_6 V_52 ,
enum V_11 V_76 , T_5 V_24 )
{
struct V_43 * V_44 =
F_29 ( V_51 , struct V_43 , V_55 ) ;
T_1 * V_56 ;
unsigned V_58 = V_52 >> V_59 & V_60 ;
unsigned V_22 = V_52 >> V_61 & V_62 ;
unsigned V_14 = V_52 >> V_63 & V_64 ;
struct V_77 V_78 ;
V_56 = NULL ;
F_35 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( F_13 ( V_58 >= V_79 ) )
break;
if ( V_56 == NULL )
V_56 = F_30 ( V_44 -> V_71 [ V_58 ] [ V_22 ] ) ;
V_56 [ V_14 ] =
F_9 ( F_36 ( & V_78 ) ,
V_76 , true ) ;
if ( ++ V_14 == V_72 ) {
if ( ! F_31 ( V_44 -> V_55 . V_2 ) )
F_32 ( V_56 , V_73 ) ;
F_33 ( V_56 ) ;
V_56 = NULL ;
if ( ++ V_22 == V_48 ) {
V_58 ++ ;
V_22 = 0 ;
}
V_14 = 0 ;
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
struct V_84 * V_85 = V_44 -> V_55 . V_2 -> V_8 ;
int V_45 , V_86 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_81 ; V_45 ++ ) {
if ( ! V_44 -> V_49 [ V_45 ] )
continue;
F_43 ( V_85 , V_44 -> V_49 [ V_45 ] , V_73 ,
V_87 ) ;
for ( V_86 = 0 ; V_86 < V_48 ; V_86 ++ ) {
T_2 V_10 = V_44 -> V_82 [ V_45 ] [ V_86 ] ;
if ( V_10 )
F_43 ( V_85 , V_10 , V_73 ,
V_87 ) ;
}
}
}
static void F_44 ( struct V_50 * V_51 )
{
struct V_43 * V_44 =
F_29 ( V_51 , struct V_43 , V_55 ) ;
F_42 ( V_44 ) ;
F_39 ( V_44 ) ;
}
static struct V_69 * * F_45 ( void )
{
struct V_69 * * V_80 ;
int V_45 ;
V_80 = F_46 ( V_48 , sizeof( struct V_69 * ) , V_88 ) ;
if ( ! V_80 )
return F_47 ( - V_89 ) ;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 ++ ) {
V_80 [ V_45 ] = F_48 ( V_88 ) ;
if ( ! V_80 [ V_45 ] )
goto V_90;
}
return V_80 ;
V_90:
F_37 ( V_80 ) ;
F_40 ( V_80 ) ;
return F_47 ( - V_89 ) ;
}
static int F_49 ( struct V_43 * V_44 ,
const int V_91 )
{
struct V_69 * * V_80 [ V_79 ] ;
int V_45 , V_42 ;
for ( V_45 = 0 ; V_45 < V_91 ; V_45 ++ ) {
V_80 [ V_45 ] = F_45 () ;
if ( F_50 ( V_80 [ V_45 ] ) ) {
V_42 = F_51 ( V_80 [ V_45 ] ) ;
goto V_92;
}
}
for ( V_45 = 0 ; V_45 < V_91 ; V_45 ++ )
V_44 -> V_71 [ V_45 ] = V_80 [ V_45 ] ;
return 0 ;
V_92:
while ( V_45 -- ) {
F_37 ( V_80 [ V_45 ] ) ;
F_40 ( V_80 [ V_45 ] ) ;
}
return V_42 ;
}
static int F_52 ( struct V_43 * V_44 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_81 ; V_45 ++ ) {
V_44 -> V_82 [ V_45 ] = F_46 ( V_48 ,
sizeof( T_2 ) ,
V_88 ) ;
if ( ! V_44 -> V_82 [ V_45 ] )
return - V_89 ;
}
return 0 ;
}
static int F_53 ( struct V_43 * V_44 ,
const int V_91 )
{
V_44 -> V_83 = F_54 ( V_88 , F_41 ( V_91 << V_66 ) ) ;
if ( ! V_44 -> V_83 )
return - V_89 ;
V_44 -> V_81 = 1 << F_41 ( V_91 << V_66 ) ;
F_20 ( V_44 -> V_81 > V_79 ) ;
return 0 ;
}
static int F_55 ( struct V_43 * V_44 ,
const int V_91 )
{
int V_42 ;
V_42 = F_53 ( V_44 , V_91 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_49 ( V_44 , V_91 ) ;
if ( V_42 ) {
F_38 ( V_44 -> V_83 , F_41 ( V_91 << V_66 ) ) ;
return V_42 ;
}
V_44 -> V_47 = V_91 * V_48 ;
V_42 = F_52 ( V_44 ) ;
if ( V_42 )
F_39 ( V_44 ) ;
return V_42 ;
}
static int F_56 ( struct V_43 * V_44 ,
const int V_93 )
{
T_2 V_94 ;
int V_42 ;
V_94 = F_57 ( V_44 -> V_55 . V_2 -> V_8 ,
& V_44 -> V_83 [ V_93 ] , 0 ,
V_73 , V_87 ) ;
V_42 = F_58 ( V_44 -> V_55 . V_2 -> V_8 , V_94 ) ;
if ( V_42 )
return V_42 ;
V_44 -> V_49 [ V_93 ] = V_94 ;
return 0 ;
}
static int F_59 ( struct V_43 * V_44 ,
const int V_93 ,
const int V_95 )
{
T_2 V_96 ;
struct V_69 * V_97 ;
int V_42 ;
V_97 = V_44 -> V_71 [ V_93 ] [ V_95 ] ;
V_96 = F_57 ( V_44 -> V_55 . V_2 -> V_8 ,
V_97 , 0 , V_73 , V_87 ) ;
V_42 = F_58 ( V_44 -> V_55 . V_2 -> V_8 , V_96 ) ;
if ( V_42 )
return V_42 ;
V_44 -> V_82 [ V_93 ] [ V_95 ] = V_96 ;
return 0 ;
}
static int F_60 ( struct V_43 * V_44 , T_6 V_98 )
{
const int V_91 = F_61 ( V_98 , 1 << 30 ) ;
const int V_99 = V_48 * V_91 ;
int V_45 , V_86 , V_42 ;
if ( V_98 % ( 1 << 30 ) )
F_5 ( L_3 , V_98 ) ;
V_42 = F_55 ( V_44 , V_91 ) ;
if ( V_42 )
return V_42 ;
for ( V_45 = 0 ; V_45 < V_91 ; V_45 ++ ) {
V_42 = F_56 ( V_44 , V_45 ) ;
if ( V_42 )
goto V_90;
for ( V_86 = 0 ; V_86 < V_48 ; V_86 ++ ) {
V_42 = F_59 ( V_44 , V_45 , V_86 ) ;
if ( V_42 )
goto V_90;
}
}
for ( V_45 = 0 ; V_45 < V_91 ; V_45 ++ ) {
T_3 * V_100 ;
V_100 = F_30 ( & V_44 -> V_83 [ V_45 ] ) ;
for ( V_86 = 0 ; V_86 < V_48 ; V_86 ++ ) {
T_2 V_10 = V_44 -> V_82 [ V_45 ] [ V_86 ] ;
V_100 [ V_86 ] = F_10 ( V_44 -> V_55 . V_2 , V_10 ,
V_27 ) ;
}
if ( ! F_31 ( V_44 -> V_55 . V_2 ) )
F_32 ( V_100 , V_73 ) ;
F_33 ( V_100 ) ;
}
V_44 -> V_101 = F_27 ;
V_44 -> V_55 . V_102 = F_28 ;
V_44 -> V_55 . V_103 = F_34 ;
V_44 -> V_55 . V_104 = F_44 ;
V_44 -> V_55 . V_52 = 0 ;
V_44 -> V_55 . V_105 = V_44 -> V_47 * V_72 * V_73 ;
V_44 -> V_55 . V_102 ( & V_44 -> V_55 , 0 , V_44 -> V_55 . V_105 , true ) ;
F_8 ( L_4 ,
V_44 -> V_81 , V_44 -> V_81 - V_91 ) ;
F_8 ( L_5 ,
V_44 -> V_47 ,
( V_44 -> V_47 - V_99 ) + V_98 % ( 1 << 30 ) ) ;
return 0 ;
V_90:
F_42 ( V_44 ) ;
F_39 ( V_44 ) ;
return V_42 ;
}
static void F_62 ( struct V_43 * V_44 , struct V_106 * V_107 )
{
struct V_108 * V_109 = V_44 -> V_55 . V_2 -> V_110 ;
struct V_50 * V_51 = & V_44 -> V_55 ;
T_4 T_7 * V_94 ;
T_4 V_57 ;
T_8 V_111 ;
int V_14 , V_22 ;
V_57 = V_51 -> V_112 ( V_51 -> V_68 . V_10 , V_27 , true , 0 ) ;
V_94 = ( T_4 T_7 * ) V_109 -> V_113 . V_114 +
V_44 -> V_115 / sizeof( T_4 ) ;
F_63 ( V_107 , L_6 , V_51 ,
V_44 -> V_115 , V_44 -> V_115 + V_44 -> V_47 ) ;
for ( V_22 = 0 ; V_22 < V_44 -> V_47 ; V_22 ++ ) {
T_5 V_116 ;
T_4 * V_56 ;
T_2 V_96 = V_44 -> V_117 [ V_22 ] ;
V_111 = F_64 ( V_94 + V_22 ) ;
V_116 = ( F_65 ( V_96 ) | V_118 ) ;
if ( V_111 != V_116 )
F_63 ( V_107 , L_7 ,
V_22 ,
V_111 ,
V_116 ) ;
F_63 ( V_107 , L_8 , V_111 ) ;
V_56 = F_30 ( V_44 -> V_80 [ V_22 ] ) ;
for ( V_14 = 0 ; V_14 < V_119 ; V_14 += 4 ) {
unsigned long V_120 =
( V_22 * V_73 * V_119 ) +
( V_14 * V_73 ) ;
int V_45 ;
bool V_121 = false ;
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ )
if ( V_56 [ V_14 + V_45 ] != V_57 )
V_121 = true ;
if ( ! V_121 )
continue;
F_63 ( V_107 , L_9 , V_120 , V_22 , V_14 ) ;
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ ) {
if ( V_56 [ V_14 + V_45 ] != V_57 )
F_63 ( V_107 , L_10 , V_56 [ V_14 + V_45 ] ) ;
else
F_66 ( V_107 , L_11 ) ;
}
F_66 ( V_107 , L_12 ) ;
}
F_33 ( V_56 ) ;
}
}
static void F_67 ( struct V_43 * V_44 )
{
struct V_108 * V_109 = V_44 -> V_55 . V_2 -> V_110 ;
T_4 T_7 * V_94 ;
T_8 V_111 ;
int V_45 ;
F_13 ( V_44 -> V_115 & 0x3f ) ;
V_94 = ( T_4 T_7 * ) V_109 -> V_113 . V_114 +
V_44 -> V_115 / sizeof( T_4 ) ;
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ ) {
T_2 V_96 ;
V_96 = V_44 -> V_117 [ V_45 ] ;
V_111 = F_65 ( V_96 ) ;
V_111 |= V_118 ;
F_68 ( V_111 , V_94 + V_45 ) ;
}
F_64 ( V_94 ) ;
}
static T_8 F_69 ( struct V_43 * V_44 )
{
F_20 ( V_44 -> V_115 & 0x3f ) ;
return ( V_44 -> V_115 / 64 ) << 16 ;
}
static int F_70 ( struct V_43 * V_44 ,
struct V_38 * V_39 )
{
int V_42 ;
V_42 = V_39 -> V_122 ( V_39 , V_123 , V_123 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_21 ( V_39 , 6 ) ;
if ( V_42 )
return V_42 ;
F_22 ( V_39 , F_23 ( 2 ) ) ;
F_22 ( V_39 , F_71 ( V_39 ) ) ;
F_22 ( V_39 , V_124 ) ;
F_22 ( V_39 , F_72 ( V_39 ) ) ;
F_22 ( V_39 , F_69 ( V_44 ) ) ;
F_22 ( V_39 , V_125 ) ;
F_26 ( V_39 ) ;
return 0 ;
}
static int F_73 ( struct V_43 * V_44 ,
struct V_38 * V_39 )
{
int V_42 ;
V_42 = V_39 -> V_122 ( V_39 , V_123 , V_123 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_21 ( V_39 , 6 ) ;
if ( V_42 )
return V_42 ;
F_22 ( V_39 , F_23 ( 2 ) ) ;
F_22 ( V_39 , F_71 ( V_39 ) ) ;
F_22 ( V_39 , V_124 ) ;
F_22 ( V_39 , F_72 ( V_39 ) ) ;
F_22 ( V_39 , F_69 ( V_44 ) ) ;
F_22 ( V_39 , V_125 ) ;
F_26 ( V_39 ) ;
if ( V_39 -> V_126 != V_127 ) {
V_42 = V_39 -> V_122 ( V_39 , V_123 , V_123 ) ;
if ( V_42 )
return V_42 ;
}
return 0 ;
}
static int F_74 ( struct V_43 * V_44 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
struct V_108 * V_109 = V_2 -> V_110 ;
F_75 ( F_71 ( V_39 ) , V_124 ) ;
F_75 ( F_72 ( V_39 ) , F_69 ( V_44 ) ) ;
F_76 ( F_71 ( V_39 ) ) ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
struct V_38 * V_39 ;
int V_86 ;
F_78 (ring, dev_priv, j) {
F_75 ( F_79 ( V_39 ) ,
F_80 ( V_128 ) ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
struct V_38 * V_39 ;
T_8 V_129 , V_130 ;
int V_45 ;
V_130 = F_82 ( V_131 ) ;
F_75 ( V_131 , V_130 | V_132 ) ;
V_129 = F_82 ( V_133 ) ;
if ( F_83 ( V_2 ) ) {
V_129 |= V_134 ;
} else {
V_129 |= V_135 ;
V_129 &= ~ V_136 ;
}
F_75 ( V_133 , V_129 ) ;
F_78 (ring, dev_priv, i) {
F_75 ( F_79 ( V_39 ) ,
F_80 ( V_128 ) ) ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
T_8 V_129 , V_137 , V_130 ;
V_130 = F_82 ( V_131 ) ;
F_75 ( V_131 , V_130 | V_138 |
V_132 ) ;
V_137 = F_82 ( V_139 ) ;
F_75 ( V_139 , V_137 | V_140 ) ;
V_129 = F_82 ( V_133 ) ;
F_75 ( V_133 , V_129 | V_141 | V_142 ) ;
F_75 ( V_143 , F_80 ( V_128 ) ) ;
}
static void F_85 ( struct V_50 * V_51 ,
T_6 V_52 ,
T_6 V_53 ,
bool V_54 )
{
struct V_43 * V_44 =
F_29 ( V_51 , struct V_43 , V_55 ) ;
T_4 * V_56 , V_57 ;
unsigned V_144 = V_52 >> V_66 ;
unsigned V_65 = V_53 >> V_66 ;
unsigned V_145 = V_144 / V_119 ;
unsigned V_146 = V_144 % V_119 ;
unsigned V_67 , V_45 ;
V_57 = V_51 -> V_112 ( V_51 -> V_68 . V_10 , V_27 , true , 0 ) ;
while ( V_65 ) {
V_67 = V_146 + V_65 ;
if ( V_67 > V_119 )
V_67 = V_119 ;
V_56 = F_30 ( V_44 -> V_80 [ V_145 ] ) ;
for ( V_45 = V_146 ; V_45 < V_67 ; V_45 ++ )
V_56 [ V_45 ] = V_57 ;
F_33 ( V_56 ) ;
V_65 -= V_67 - V_146 ;
V_146 = 0 ;
V_145 ++ ;
}
}
static void F_86 ( struct V_50 * V_51 ,
struct V_74 * V_75 ,
T_6 V_52 ,
enum V_11 V_76 , T_5 V_31 )
{
struct V_43 * V_44 =
F_29 ( V_51 , struct V_43 , V_55 ) ;
T_4 * V_56 ;
unsigned V_144 = V_52 >> V_66 ;
unsigned V_145 = V_144 / V_119 ;
unsigned V_147 = V_144 % V_119 ;
struct V_77 V_78 ;
V_56 = NULL ;
F_35 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_56 == NULL )
V_56 = F_30 ( V_44 -> V_80 [ V_145 ] ) ;
V_56 [ V_147 ] =
V_51 -> V_112 ( F_36 ( & V_78 ) ,
V_76 , true , V_31 ) ;
if ( ++ V_147 == V_119 ) {
F_33 ( V_56 ) ;
V_56 = NULL ;
V_145 ++ ;
V_147 = 0 ;
}
}
if ( V_56 )
F_33 ( V_56 ) ;
}
static void F_87 ( struct V_43 * V_44 )
{
int V_45 ;
if ( V_44 -> V_117 ) {
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ )
F_43 ( V_44 -> V_55 . V_2 -> V_8 ,
V_44 -> V_117 [ V_45 ] ,
4096 , V_87 ) ;
}
}
static void F_88 ( struct V_43 * V_44 )
{
int V_45 ;
F_40 ( V_44 -> V_117 ) ;
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ )
F_89 ( V_44 -> V_80 [ V_45 ] ) ;
F_40 ( V_44 -> V_80 ) ;
}
static void F_90 ( struct V_50 * V_51 )
{
struct V_43 * V_44 =
F_29 ( V_51 , struct V_43 , V_55 ) ;
F_91 ( & V_44 -> V_148 ) ;
F_87 ( V_44 ) ;
F_88 ( V_44 ) ;
}
static int F_92 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
struct V_108 * V_109 = V_2 -> V_110 ;
bool V_149 = false ;
int V_42 ;
F_20 ( ! F_93 ( & V_109 -> V_113 . V_55 . V_150 ) ) ;
V_151:
V_42 = F_94 ( & V_109 -> V_113 . V_55 . V_150 ,
& V_44 -> V_148 , V_152 ,
V_153 , 0 ,
0 , V_109 -> V_113 . V_55 . V_105 ,
V_154 ) ;
if ( V_42 == - V_155 && ! V_149 ) {
V_42 = F_95 ( V_2 , & V_109 -> V_113 . V_55 ,
V_152 , V_153 ,
V_17 ,
0 , V_109 -> V_113 . V_55 . V_105 ,
0 ) ;
if ( V_42 )
return V_42 ;
V_149 = true ;
goto V_151;
}
if ( V_44 -> V_148 . V_52 < V_109 -> V_113 . V_156 )
F_96 ( L_13 ) ;
V_44 -> V_47 = V_157 ;
return V_42 ;
}
static int F_97 ( struct V_43 * V_44 )
{
int V_45 ;
V_44 -> V_80 = F_46 ( V_44 -> V_47 , sizeof( struct V_69 * ) ,
V_88 ) ;
if ( ! V_44 -> V_80 )
return - V_89 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ ) {
V_44 -> V_80 [ V_45 ] = F_48 ( V_88 ) ;
if ( ! V_44 -> V_80 [ V_45 ] ) {
F_88 ( V_44 ) ;
return - V_89 ;
}
}
return 0 ;
}
static int F_98 ( struct V_43 * V_44 )
{
int V_42 ;
V_42 = F_92 ( V_44 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_97 ( V_44 ) ;
if ( V_42 ) {
F_91 ( & V_44 -> V_148 ) ;
return V_42 ;
}
V_44 -> V_117 = F_46 ( V_44 -> V_47 , sizeof( T_2 ) ,
V_88 ) ;
if ( ! V_44 -> V_117 ) {
F_91 ( & V_44 -> V_148 ) ;
F_88 ( V_44 ) ;
return - V_89 ;
}
return 0 ;
}
static int F_99 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ ) {
T_2 V_96 ;
V_96 = F_57 ( V_2 -> V_8 , V_44 -> V_80 [ V_45 ] , 0 , 4096 ,
V_87 ) ;
if ( F_58 ( V_2 -> V_8 , V_96 ) ) {
F_87 ( V_44 ) ;
return - V_158 ;
}
V_44 -> V_117 [ V_45 ] = V_96 ;
}
return 0 ;
}
static int F_100 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_55 . V_2 ;
struct V_108 * V_109 = V_2 -> V_110 ;
int V_42 ;
V_44 -> V_55 . V_112 = V_109 -> V_113 . V_55 . V_112 ;
if ( F_101 ( V_2 ) ) {
V_44 -> V_101 = F_74 ;
} else if ( F_83 ( V_2 ) ) {
V_44 -> V_101 = F_70 ;
} else if ( F_102 ( V_2 ) ) {
V_44 -> V_101 = F_73 ;
} else
F_103 () ;
V_42 = F_98 ( V_44 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_99 ( V_44 ) ;
if ( V_42 ) {
F_88 ( V_44 ) ;
return V_42 ;
}
V_44 -> V_55 . V_102 = F_85 ;
V_44 -> V_55 . V_103 = F_86 ;
V_44 -> V_55 . V_104 = F_90 ;
V_44 -> V_55 . V_52 = 0 ;
V_44 -> V_55 . V_105 = V_44 -> V_47 * V_119 * V_73 ;
V_44 -> V_159 = F_62 ;
V_44 -> V_115 =
V_44 -> V_148 . V_52 / V_73 * sizeof( T_4 ) ;
V_44 -> V_55 . V_102 ( & V_44 -> V_55 , 0 , V_44 -> V_55 . V_105 , true ) ;
F_8 ( L_14 ,
V_44 -> V_148 . V_98 >> 20 ,
V_44 -> V_148 . V_52 / V_73 ) ;
F_67 ( V_44 ) ;
F_96 ( L_15 ,
V_44 -> V_115 << 10 ) ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
V_44 -> V_55 . V_2 = V_2 ;
V_44 -> V_55 . V_68 = V_109 -> V_113 . V_55 . V_68 ;
if ( F_2 ( V_2 ) -> V_6 < 8 )
return F_100 ( V_44 ) ;
else if ( F_3 ( V_2 ) || F_105 ( V_2 ) )
return F_60 ( V_44 , V_109 -> V_113 . V_55 . V_105 ) ;
else
F_103 () ;
}
int F_106 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
int V_42 = 0 ;
V_42 = F_104 ( V_2 , V_44 ) ;
if ( V_42 == 0 ) {
F_107 ( & V_44 -> V_160 ) ;
F_108 ( & V_44 -> V_55 . V_150 , V_44 -> V_55 . V_52 ,
V_44 -> V_55 . V_105 ) ;
F_109 ( V_109 , & V_44 -> V_55 ) ;
}
return V_42 ;
}
int F_110 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
struct V_38 * V_39 ;
struct V_43 * V_44 = V_109 -> V_150 . V_161 ;
int V_45 , V_42 = 0 ;
if ( V_162 . V_163 )
return 0 ;
if ( ! F_111 ( V_2 ) )
return 0 ;
if ( F_101 ( V_2 ) )
F_84 ( V_2 ) ;
else if ( F_102 ( V_2 ) )
F_81 ( V_2 ) ;
else if ( F_2 ( V_2 ) -> V_6 >= 8 )
F_77 ( V_2 ) ;
else
F_13 ( 1 ) ;
if ( V_44 ) {
F_78 (ring, dev_priv, i) {
V_42 = V_44 -> V_101 ( V_44 , V_39 ) ;
if ( V_42 != 0 )
return V_42 ;
}
}
return V_42 ;
}
struct V_43 *
F_112 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
struct V_43 * V_44 ;
int V_42 ;
V_44 = F_113 ( sizeof( * V_44 ) , V_88 ) ;
if ( ! V_44 )
return F_47 ( - V_89 ) ;
V_42 = F_106 ( V_2 , V_44 ) ;
if ( V_42 ) {
F_40 ( V_44 ) ;
return F_47 ( V_42 ) ;
}
V_44 -> V_166 = V_165 ;
F_114 ( & V_44 -> V_55 ) ;
return V_44 ;
}
void F_115 ( struct V_167 * V_167 )
{
struct V_43 * V_44 =
F_29 ( V_167 , struct V_43 , V_160 ) ;
F_116 ( & V_44 -> V_55 ) ;
F_13 ( ! F_117 ( & V_44 -> V_55 . V_168 ) ) ;
F_13 ( ! F_117 ( & V_44 -> V_55 . V_169 ) ) ;
F_118 ( & V_44 -> V_55 . V_170 ) ;
F_119 ( & V_44 -> V_55 . V_150 ) ;
V_44 -> V_55 . V_104 ( & V_44 -> V_55 ) ;
F_40 ( V_44 ) ;
}
static void
F_120 ( struct V_171 * V_172 ,
enum V_11 V_76 ,
T_5 V_31 )
{
if ( V_172 -> V_173 -> V_174 )
V_31 |= V_32 ;
V_172 -> V_51 -> V_103 ( V_172 -> V_51 , V_172 -> V_173 -> V_75 , V_172 -> V_148 . V_52 ,
V_76 , V_31 ) ;
}
static void F_121 ( struct V_171 * V_172 )
{
V_172 -> V_51 -> V_102 ( V_172 -> V_51 ,
V_172 -> V_148 . V_52 ,
V_172 -> V_173 -> V_55 . V_98 ,
true ) ;
}
static inline bool F_122 ( struct V_1 * V_2 )
{
#ifdef F_4
if ( F_123 ( V_2 ) && F_124 ( V_2 ) && V_7 )
return true ;
#endif
return false ;
}
static bool F_125 ( struct V_108 * V_109 )
{
bool V_42 = V_109 -> V_150 . V_175 ;
if ( F_126 ( V_109 -> V_113 . V_176 ) ) {
V_109 -> V_150 . V_175 = false ;
if ( F_127 ( V_109 -> V_2 ) ) {
F_128 ( L_16 ) ;
F_129 ( 10 ) ;
}
}
return V_42 ;
}
static void F_130 ( struct V_108 * V_109 , bool V_175 )
{
if ( F_126 ( V_109 -> V_113 . V_176 ) )
V_109 -> V_150 . V_175 = V_175 ;
}
void F_131 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
struct V_38 * V_39 ;
int V_45 ;
if ( F_2 ( V_2 ) -> V_6 < 6 )
return;
F_78 (ring, dev_priv, i) {
T_5 V_177 ;
V_177 = F_82 ( F_132 ( V_39 ) ) ;
if ( V_177 & V_178 ) {
F_8 ( L_17
L_18
L_19
L_20
L_21 ,
V_177 & V_179 ,
V_177 & V_180 ? L_22 : L_23 ,
F_133 ( V_177 ) ,
F_134 ( V_177 ) ) ;
F_75 ( F_132 ( V_39 ) ,
V_177 & ~ V_178 ) ;
}
}
F_76 ( F_132 ( & V_109 -> V_39 [ V_127 ] ) ) ;
}
static void F_135 ( struct V_108 * V_109 )
{
if ( F_2 ( V_109 -> V_2 ) -> V_6 < 6 ) {
F_136 () ;
} else {
F_75 ( V_181 , V_182 ) ;
F_76 ( V_181 ) ;
}
}
void F_137 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
if ( F_2 ( V_2 ) -> V_6 < 6 )
return;
F_131 ( V_2 ) ;
V_109 -> V_113 . V_55 . V_102 ( & V_109 -> V_113 . V_55 ,
V_109 -> V_113 . V_55 . V_52 ,
V_109 -> V_113 . V_55 . V_105 ,
true ) ;
F_135 ( V_109 ) ;
}
void F_138 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
struct V_183 * V_173 ;
struct V_50 * V_51 ;
F_131 ( V_2 ) ;
V_109 -> V_113 . V_55 . V_102 ( & V_109 -> V_113 . V_55 ,
V_109 -> V_113 . V_55 . V_52 ,
V_109 -> V_113 . V_55 . V_105 ,
true ) ;
F_139 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_171 * V_172 = F_140 ( V_173 ,
& V_109 -> V_113 . V_55 ) ;
if ( ! V_172 )
continue;
F_141 ( V_173 , V_173 -> V_184 ) ;
V_172 -> V_185 &= ~ V_186 ;
V_172 -> V_187 ( V_172 , V_173 -> V_76 , V_186 ) ;
}
if ( F_2 ( V_2 ) -> V_6 >= 8 ) {
if ( F_7 ( V_2 ) )
F_142 ( V_109 ) ;
else
F_143 ( V_109 ) ;
return;
}
F_139 (vm, &dev_priv->vm_list, global_link) {
if ( F_144 ( V_51 ) ) {
if ( V_109 -> V_150 . V_161 )
F_67 ( V_109 -> V_150 . V_161 ) ;
continue;
}
F_67 ( F_29 ( V_51 , struct V_43 , V_55 ) ) ;
}
F_135 ( V_109 ) ;
}
int F_145 ( struct V_183 * V_173 )
{
if ( V_173 -> V_188 )
return 0 ;
if ( ! F_146 ( & V_173 -> V_55 . V_2 -> V_8 -> V_2 ,
V_173 -> V_75 -> V_189 , V_173 -> V_75 -> V_190 ,
V_87 ) )
return - V_155 ;
return 0 ;
}
static inline void F_147 ( void T_7 * V_10 , T_1 V_14 )
{
#ifdef F_148
F_148 ( V_14 , V_10 ) ;
#else
F_149 ( ( T_5 ) V_14 , V_10 ) ;
F_149 ( V_14 >> 32 , V_10 + 4 ) ;
#endif
}
static void F_150 ( struct V_50 * V_51 ,
struct V_74 * V_191 ,
T_6 V_52 ,
enum V_11 V_12 , T_5 V_24 )
{
struct V_108 * V_109 = V_51 -> V_2 -> V_110 ;
unsigned V_144 = V_52 >> V_66 ;
T_1 T_7 * V_192 =
( T_1 T_7 * ) V_109 -> V_113 . V_114 + V_144 ;
int V_45 = 0 ;
struct V_77 V_78 ;
T_2 V_10 = 0 ;
F_35 (st->sgl, &sg_iter, st->nents, 0 ) {
V_10 = F_151 ( V_78 . V_193 ) +
( V_78 . V_194 << V_66 ) ;
F_147 ( & V_192 [ V_45 ] ,
F_9 ( V_10 , V_12 , true ) ) ;
V_45 ++ ;
}
if ( V_45 != 0 )
F_13 ( F_152 ( & V_192 [ V_45 - 1 ] )
!= F_9 ( V_10 , V_12 , true ) ) ;
F_75 ( V_181 , V_182 ) ;
F_76 ( V_181 ) ;
}
static void F_153 ( struct V_50 * V_51 ,
struct V_74 * V_191 ,
T_6 V_52 ,
enum V_11 V_12 , T_5 V_31 )
{
struct V_108 * V_109 = V_51 -> V_2 -> V_110 ;
unsigned V_144 = V_52 >> V_66 ;
T_4 T_7 * V_192 =
( T_4 T_7 * ) V_109 -> V_113 . V_114 + V_144 ;
int V_45 = 0 ;
struct V_77 V_78 ;
T_2 V_10 = 0 ;
F_35 (st->sgl, &sg_iter, st->nents, 0 ) {
V_10 = F_36 ( & V_78 ) ;
F_149 ( V_51 -> V_112 ( V_10 , V_12 , true , V_31 ) , & V_192 [ V_45 ] ) ;
V_45 ++ ;
}
if ( V_45 != 0 ) {
unsigned long V_113 = F_64 ( & V_192 [ V_45 - 1 ] ) ;
F_13 ( V_113 != V_51 -> V_112 ( V_10 , V_12 , true , V_31 ) ) ;
}
F_75 ( V_181 , V_182 ) ;
F_76 ( V_181 ) ;
}
static void F_154 ( struct V_50 * V_51 ,
T_6 V_52 ,
T_6 V_53 ,
bool V_54 )
{
struct V_108 * V_109 = V_51 -> V_2 -> V_110 ;
unsigned V_144 = V_52 >> V_66 ;
unsigned V_65 = V_53 >> V_66 ;
T_1 V_57 , T_7 * V_195 =
( T_1 T_7 * ) V_109 -> V_113 . V_114 + V_144 ;
const int V_196 = F_155 ( V_109 -> V_113 ) - V_144 ;
int V_45 ;
if ( F_156 ( V_65 > V_196 ,
L_24 ,
V_144 , V_65 , V_196 ) )
V_65 = V_196 ;
V_57 = F_9 ( V_51 -> V_68 . V_10 ,
V_27 ,
V_54 ) ;
for ( V_45 = 0 ; V_45 < V_65 ; V_45 ++ )
F_147 ( & V_195 [ V_45 ] , V_57 ) ;
F_64 ( V_195 ) ;
}
static void F_157 ( struct V_50 * V_51 ,
T_6 V_52 ,
T_6 V_53 ,
bool V_54 )
{
struct V_108 * V_109 = V_51 -> V_2 -> V_110 ;
unsigned V_144 = V_52 >> V_66 ;
unsigned V_65 = V_53 >> V_66 ;
T_4 V_57 , T_7 * V_195 =
( T_4 T_7 * ) V_109 -> V_113 . V_114 + V_144 ;
const int V_196 = F_155 ( V_109 -> V_113 ) - V_144 ;
int V_45 ;
if ( F_156 ( V_65 > V_196 ,
L_24 ,
V_144 , V_65 , V_196 ) )
V_65 = V_196 ;
V_57 = V_51 -> V_112 ( V_51 -> V_68 . V_10 , V_27 , V_54 , 0 ) ;
for ( V_45 = 0 ; V_45 < V_65 ; V_45 ++ )
F_149 ( V_57 , & V_195 [ V_45 ] ) ;
F_64 ( V_195 ) ;
}
static void F_158 ( struct V_171 * V_172 ,
enum V_11 V_76 ,
T_5 V_24 )
{
const unsigned long V_40 = V_172 -> V_148 . V_52 >> V_66 ;
unsigned int V_31 = ( V_76 == V_17 ) ?
V_197 : V_198 ;
F_20 ( ! F_144 ( V_172 -> V_51 ) ) ;
F_159 ( V_172 -> V_173 -> V_75 , V_40 , V_31 ) ;
V_172 -> V_185 = V_186 ;
}
static void F_160 ( struct V_50 * V_51 ,
T_6 V_52 ,
T_6 V_53 ,
bool V_24 )
{
unsigned V_144 = V_52 >> V_66 ;
unsigned V_65 = V_53 >> V_66 ;
F_161 ( V_144 , V_65 ) ;
}
static void F_162 ( struct V_171 * V_172 )
{
const unsigned int V_199 = V_172 -> V_148 . V_52 >> V_66 ;
const unsigned int V_98 = V_172 -> V_173 -> V_55 . V_98 >> V_66 ;
F_20 ( ! F_144 ( V_172 -> V_51 ) ) ;
V_172 -> V_185 = 0 ;
F_161 ( V_199 , V_98 ) ;
}
static void F_163 ( struct V_171 * V_172 ,
enum V_11 V_76 ,
T_5 V_31 )
{
struct V_1 * V_2 = V_172 -> V_51 -> V_2 ;
struct V_108 * V_109 = V_2 -> V_110 ;
struct V_183 * V_173 = V_172 -> V_173 ;
if ( V_173 -> V_174 )
V_31 |= V_32 ;
if ( ! V_109 -> V_150 . V_161 || V_31 & V_186 ) {
if ( ! ( V_172 -> V_185 & V_186 ) ||
( V_76 != V_173 -> V_76 ) ) {
V_172 -> V_51 -> V_103 ( V_172 -> V_51 , V_173 -> V_75 ,
V_172 -> V_148 . V_52 ,
V_76 , V_31 ) ;
V_172 -> V_185 |= V_186 ;
}
}
if ( V_109 -> V_150 . V_161 &&
( ! ( V_172 -> V_185 & V_200 ) ||
( V_76 != V_173 -> V_76 ) ) ) {
struct V_43 * V_201 = V_109 -> V_150 . V_161 ;
V_201 -> V_55 . V_103 ( & V_201 -> V_55 ,
V_172 -> V_173 -> V_75 ,
V_172 -> V_148 . V_52 ,
V_76 , V_31 ) ;
V_172 -> V_185 |= V_200 ;
}
}
static void F_164 ( struct V_171 * V_172 )
{
struct V_1 * V_2 = V_172 -> V_51 -> V_2 ;
struct V_108 * V_109 = V_2 -> V_110 ;
struct V_183 * V_173 = V_172 -> V_173 ;
if ( V_172 -> V_185 & V_186 ) {
V_172 -> V_51 -> V_102 ( V_172 -> V_51 ,
V_172 -> V_148 . V_52 ,
V_173 -> V_55 . V_98 ,
true ) ;
V_172 -> V_185 &= ~ V_186 ;
}
if ( V_172 -> V_185 & V_200 ) {
struct V_43 * V_201 = V_109 -> V_150 . V_161 ;
V_201 -> V_55 . V_102 ( & V_201 -> V_55 ,
V_172 -> V_148 . V_52 ,
V_173 -> V_55 . V_98 ,
true ) ;
V_172 -> V_185 &= ~ V_200 ;
}
}
void F_165 ( struct V_183 * V_173 )
{
struct V_1 * V_2 = V_173 -> V_55 . V_2 ;
struct V_108 * V_109 = V_2 -> V_110 ;
bool V_175 ;
V_175 = F_125 ( V_109 ) ;
if ( ! V_173 -> V_188 )
F_166 ( & V_2 -> V_8 -> V_2 ,
V_173 -> V_75 -> V_189 , V_173 -> V_75 -> V_190 ,
V_87 ) ;
F_130 ( V_109 , V_175 ) ;
}
static void F_167 ( struct V_202 * V_148 ,
unsigned long V_203 ,
unsigned long * V_52 ,
unsigned long * V_204 )
{
if ( V_148 -> V_203 != V_203 )
* V_52 += 4096 ;
if ( ! F_117 ( & V_148 -> V_205 ) ) {
V_148 = F_168 ( V_148 -> V_205 . V_206 ,
struct V_202 ,
V_205 ) ;
if ( V_148 -> V_207 && V_148 -> V_203 != V_203 )
* V_204 -= 4096 ;
}
}
static int F_169 ( struct V_1 * V_2 ,
unsigned long V_52 ,
unsigned long V_156 ,
unsigned long V_204 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
struct V_50 * V_208 = & V_109 -> V_113 . V_55 ;
struct V_202 * V_40 ;
struct V_183 * V_173 ;
unsigned long V_209 , V_210 ;
int V_42 ;
F_20 ( V_156 > V_204 ) ;
F_108 ( & V_208 -> V_150 , V_52 , V_204 - V_52 - V_73 ) ;
if ( ! F_31 ( V_2 ) )
V_109 -> V_113 . V_55 . V_150 . V_211 = F_167 ;
F_139 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_171 * V_172 = F_140 ( V_173 , V_208 ) ;
F_170 ( L_25 ,
F_171 ( V_173 ) , V_173 -> V_55 . V_98 ) ;
F_13 ( F_172 ( V_173 ) ) ;
V_42 = F_173 ( & V_208 -> V_150 , & V_172 -> V_148 ) ;
if ( V_42 ) {
F_170 ( L_26 , V_42 ) ;
return V_42 ;
}
V_172 -> V_185 |= V_186 ;
}
V_109 -> V_113 . V_55 . V_52 = V_52 ;
V_109 -> V_113 . V_55 . V_105 = V_204 - V_52 ;
F_174 (entry, &ggtt_vm->mm, hole_start, hole_end) {
F_170 ( L_27 ,
V_209 , V_210 ) ;
V_208 -> V_102 ( V_208 , V_209 ,
V_210 - V_209 , true ) ;
}
V_208 -> V_102 ( V_208 , V_204 - V_73 , V_73 , true ) ;
if ( F_111 ( V_2 ) && ! F_175 ( V_2 ) ) {
struct V_43 * V_44 ;
V_44 = F_113 ( sizeof( * V_44 ) , V_88 ) ;
if ( ! V_44 )
return - V_89 ;
V_42 = F_104 ( V_2 , V_44 ) ;
if ( V_42 != 0 )
return V_42 ;
V_109 -> V_150 . V_161 = V_44 ;
}
return 0 ;
}
void F_176 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
unsigned long V_212 , V_213 ;
V_212 = V_109 -> V_113 . V_55 . V_105 ;
V_213 = V_109 -> V_113 . V_156 ;
F_169 ( V_2 , 0 , V_213 , V_212 ) ;
}
void F_177 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
struct V_50 * V_51 = & V_109 -> V_113 . V_55 ;
if ( V_109 -> V_150 . V_161 ) {
struct V_43 * V_44 = V_109 -> V_150 . V_161 ;
V_44 -> V_55 . V_104 ( & V_44 -> V_55 ) ;
}
if ( F_93 ( & V_51 -> V_150 ) ) {
F_119 ( & V_51 -> V_150 ) ;
F_118 ( & V_51 -> V_170 ) ;
}
V_51 -> V_104 ( V_51 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
struct V_69 * V_69 ;
T_2 V_214 ;
V_69 = F_48 ( V_88 | V_215 | V_216 ) ;
if ( V_69 == NULL )
return - V_89 ;
F_179 ( V_69 , 1 ) ;
#ifdef F_4
V_214 = F_57 ( V_2 -> V_8 , V_69 , 0 , V_73 ,
V_87 ) ;
if ( F_58 ( V_2 -> V_8 , V_214 ) )
return - V_217 ;
#else
V_214 = F_180 ( V_69 ) ;
#endif
V_109 -> V_113 . V_55 . V_68 . V_69 = V_69 ;
V_109 -> V_113 . V_55 . V_68 . V_10 = V_214 ;
return 0 ;
}
static void F_181 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
struct V_69 * V_69 = V_109 -> V_113 . V_55 . V_68 . V_69 ;
F_182 ( V_69 , 1 ) ;
F_43 ( V_2 -> V_8 , V_109 -> V_113 . V_55 . V_68 . V_10 ,
V_73 , V_87 ) ;
F_89 ( V_69 ) ;
}
static inline unsigned int F_183 ( T_9 V_218 )
{
V_218 >>= V_219 ;
V_218 &= V_220 ;
return V_218 << 20 ;
}
static inline unsigned int F_184 ( T_9 V_221 )
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
static inline unsigned int F_186 ( T_9 V_224 )
{
V_224 >>= V_219 ;
V_224 &= V_220 ;
if ( V_224 )
return 1 << ( 20 + V_224 ) ;
return 0 ;
}
static inline T_10 F_187 ( T_9 V_218 )
{
V_218 >>= V_225 ;
V_218 &= V_226 ;
return V_218 << 25 ;
}
static inline T_10 F_188 ( T_9 V_221 )
{
V_221 >>= V_227 ;
V_221 &= V_228 ;
return V_221 << 25 ;
}
static T_10 F_189 ( T_9 V_224 )
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
static T_10 F_190 ( T_9 V_229 )
{
V_229 >>= V_227 ;
V_229 &= V_228 ;
if ( V_229 < 0xf0 )
return V_229 << 25 ;
else
return ( V_229 - 0xf0 + 1 ) << 22 ;
}
static int F_191 ( struct V_1 * V_2 ,
T_10 V_212 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
T_11 V_230 ;
int V_42 ;
V_230 = F_192 ( V_2 -> V_8 , 0 ) +
( F_193 ( V_2 -> V_8 , 0 ) / 2 ) ;
V_109 -> V_113 . V_114 = F_194 ( V_230 , V_212 ) ;
if ( ! V_109 -> V_113 . V_114 ) {
F_128 ( L_28 ) ;
return - V_89 ;
}
V_42 = F_178 ( V_2 ) ;
if ( V_42 ) {
F_128 ( L_29 ) ;
F_195 ( V_109 -> V_113 . V_114 ) ;
}
return V_42 ;
}
static void F_143 ( struct V_108 * V_109 )
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
if ( ! F_111 ( V_109 -> V_2 ) )
V_231 = F_196 ( 0 , V_237 ) ;
F_75 ( V_238 , V_231 ) ;
F_75 ( V_238 + 4 , V_231 >> 32 ) ;
}
static void F_142 ( struct V_108 * V_109 )
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
T_10 * V_240 ,
T_10 * V_241 ,
T_11 * V_242 ,
unsigned long * V_156 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
unsigned int V_212 ;
T_9 V_218 ;
int V_42 ;
* V_242 = F_192 ( V_2 -> V_8 , 2 ) ;
* V_156 = F_193 ( V_2 -> V_8 , 2 ) ;
if ( ! F_199 ( V_2 -> V_8 , F_200 ( 39 ) ) )
F_201 ( V_2 -> V_8 , F_200 ( 39 ) ) ;
F_202 ( V_2 -> V_8 , V_243 , & V_218 ) ;
if ( F_2 ( V_2 ) -> V_6 >= 9 ) {
* V_241 = F_190 ( V_218 ) ;
V_212 = F_184 ( V_218 ) ;
} else if ( F_7 ( V_2 ) ) {
* V_241 = F_189 ( V_218 ) ;
V_212 = F_186 ( V_218 ) ;
} else {
* V_241 = F_188 ( V_218 ) ;
V_212 = F_184 ( V_218 ) ;
}
* V_240 = ( V_212 / sizeof( T_1 ) ) << V_66 ;
if ( F_7 ( V_2 ) )
F_142 ( V_109 ) ;
else
F_143 ( V_109 ) ;
V_42 = F_191 ( V_2 , V_212 ) ;
V_109 -> V_113 . V_55 . V_102 = F_154 ;
V_109 -> V_113 . V_55 . V_103 = F_150 ;
return V_42 ;
}
static int F_203 ( struct V_1 * V_2 ,
T_10 * V_240 ,
T_10 * V_241 ,
T_11 * V_242 ,
unsigned long * V_156 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
unsigned int V_212 ;
T_9 V_218 ;
int V_42 ;
* V_242 = F_192 ( V_2 -> V_8 , 2 ) ;
* V_156 = F_193 ( V_2 -> V_8 , 2 ) ;
if ( ( * V_156 < ( 64 << 20 ) || ( * V_156 > ( 512 << 20 ) ) ) ) {
F_128 ( L_30 ,
V_109 -> V_113 . V_156 ) ;
return - V_244 ;
}
if ( ! F_199 ( V_2 -> V_8 , F_200 ( 40 ) ) )
F_201 ( V_2 -> V_8 , F_200 ( 40 ) ) ;
F_202 ( V_2 -> V_8 , V_243 , & V_218 ) ;
* V_241 = F_187 ( V_218 ) ;
V_212 = F_183 ( V_218 ) ;
* V_240 = ( V_212 / sizeof( T_4 ) ) << V_66 ;
V_42 = F_191 ( V_2 , V_212 ) ;
V_109 -> V_113 . V_55 . V_102 = F_157 ;
V_109 -> V_113 . V_55 . V_103 = F_153 ;
return V_42 ;
}
static void F_204 ( struct V_50 * V_51 )
{
struct V_245 * V_113 = F_29 ( V_51 , struct V_245 , V_55 ) ;
F_195 ( V_113 -> V_114 ) ;
F_181 ( V_51 -> V_2 ) ;
}
static int F_205 ( struct V_1 * V_2 ,
T_10 * V_240 ,
T_10 * V_241 ,
T_11 * V_242 ,
unsigned long * V_156 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
int V_42 ;
V_42 = F_206 ( V_109 -> V_246 , V_109 -> V_2 -> V_8 , NULL ) ;
if ( ! V_42 ) {
F_128 ( L_31 ) ;
return - V_158 ;
}
F_207 ( V_240 , V_241 , V_242 , V_156 ) ;
V_109 -> V_113 . V_176 = F_122 ( V_109 -> V_2 ) ;
V_109 -> V_113 . V_55 . V_102 = F_160 ;
if ( F_126 ( V_109 -> V_113 . V_176 ) )
F_5 ( L_32 ) ;
return 0 ;
}
static void F_208 ( struct V_50 * V_51 )
{
F_209 () ;
}
int F_210 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = V_2 -> V_110 ;
struct V_245 * V_113 = & V_109 -> V_113 ;
int V_42 ;
if ( F_2 ( V_2 ) -> V_6 <= 5 ) {
V_113 -> V_247 = F_205 ;
V_113 -> V_55 . V_104 = F_208 ;
} else if ( F_2 ( V_2 ) -> V_6 < 8 ) {
V_113 -> V_247 = F_203 ;
V_113 -> V_55 . V_104 = F_204 ;
if ( F_83 ( V_2 ) && V_109 -> V_248 )
V_113 -> V_55 . V_112 = F_18 ;
else if ( F_83 ( V_2 ) )
V_113 -> V_55 . V_112 = F_16 ;
else if ( F_6 ( V_2 ) )
V_113 -> V_55 . V_112 = F_15 ;
else if ( F_2 ( V_2 ) -> V_6 >= 7 )
V_113 -> V_55 . V_112 = F_14 ;
else
V_113 -> V_55 . V_112 = F_11 ;
} else {
V_109 -> V_113 . V_247 = F_198 ;
V_109 -> V_113 . V_55 . V_104 = F_204 ;
}
V_42 = V_113 -> V_247 ( V_2 , & V_113 -> V_55 . V_105 , & V_113 -> V_249 ,
& V_113 -> V_242 , & V_113 -> V_156 ) ;
if ( V_42 )
return V_42 ;
V_113 -> V_55 . V_2 = V_2 ;
F_5 ( L_33 ,
V_113 -> V_55 . V_105 >> 20 ) ;
F_8 ( L_34 , V_113 -> V_156 >> 20 ) ;
F_8 ( L_35 , V_113 -> V_249 >> 20 ) ;
#ifdef F_4
if ( V_7 )
F_5 ( L_36 ) ;
#endif
V_162 . V_3 = F_1 ( V_2 , V_162 . V_3 ) ;
F_8 ( L_37 , V_162 . V_3 ) ;
return 0 ;
}
static struct V_171 * F_211 ( struct V_183 * V_173 ,
struct V_50 * V_51 )
{
struct V_171 * V_172 = F_113 ( sizeof( * V_172 ) , V_88 ) ;
if ( V_172 == NULL )
return F_47 ( - V_89 ) ;
F_212 ( & V_172 -> V_250 ) ;
F_212 ( & V_172 -> V_251 ) ;
F_212 ( & V_172 -> V_252 ) ;
V_172 -> V_51 = V_51 ;
V_172 -> V_173 = V_173 ;
switch ( F_2 ( V_51 -> V_2 ) -> V_6 ) {
case 9 :
case 8 :
case 7 :
case 6 :
if ( F_144 ( V_51 ) ) {
V_172 -> V_253 = F_164 ;
V_172 -> V_187 = F_163 ;
} else {
V_172 -> V_253 = F_121 ;
V_172 -> V_187 = F_120 ;
}
break;
case 5 :
case 4 :
case 3 :
case 2 :
F_20 ( ! F_144 ( V_51 ) ) ;
V_172 -> V_253 = F_162 ;
V_172 -> V_187 = F_158 ;
break;
default:
F_103 () ;
}
if ( F_144 ( V_51 ) )
F_213 ( & V_172 -> V_250 , & V_173 -> V_254 ) ;
else {
F_214 ( & V_172 -> V_250 , & V_173 -> V_254 ) ;
F_215 ( F_216 ( V_51 ) ) ;
}
return V_172 ;
}
struct V_171 *
F_217 ( struct V_183 * V_173 ,
struct V_50 * V_51 )
{
struct V_171 * V_172 ;
V_172 = F_140 ( V_173 , V_51 ) ;
if ( ! V_172 )
V_172 = F_211 ( V_173 , V_51 ) ;
return V_172 ;
}
