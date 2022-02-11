static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == 0 || ! F_2 ( V_2 ) )
return 0 ;
if ( V_3 == 1 )
return 1 ;
if ( V_3 == 2 && F_3 ( V_2 ) )
return 2 ;
#ifdef F_4
if ( F_5 ( V_2 ) -> V_4 == 6 && V_5 ) {
F_6 ( L_1 ) ;
return 0 ;
}
#endif
if ( F_7 ( V_2 ) && ! F_8 ( V_2 ) &&
V_2 -> V_6 -> V_7 < 0xb ) {
F_9 ( L_2 ) ;
return 0 ;
}
return F_2 ( V_2 ) ? 1 : 0 ;
}
static inline T_1 F_10 ( T_2 V_8 ,
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
static inline T_3 F_11 ( struct V_1 * V_2 ,
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
static T_4 F_12 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 , T_5 V_22 )
{
T_4 V_12 = V_11 ? V_23 : 0 ;
V_12 |= F_13 ( V_8 ) ;
switch ( V_10 ) {
case V_24 :
case V_25 :
V_12 |= V_26 ;
break;
case V_15 :
V_12 |= V_27 ;
break;
default:
F_14 ( 1 ) ;
}
return V_12 ;
}
static T_4 F_15 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 , T_5 V_22 )
{
T_4 V_12 = V_11 ? V_23 : 0 ;
V_12 |= F_13 ( V_8 ) ;
switch ( V_10 ) {
case V_24 :
V_12 |= V_28 ;
break;
case V_25 :
V_12 |= V_26 ;
break;
case V_15 :
V_12 |= V_27 ;
break;
default:
F_14 ( 1 ) ;
}
return V_12 ;
}
static T_4 F_16 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 , T_5 V_29 )
{
T_4 V_12 = V_11 ? V_23 : 0 ;
V_12 |= F_13 ( V_8 ) ;
if ( ! ( V_29 & V_30 ) )
V_12 |= V_31 ;
if ( V_10 != V_15 )
V_12 |= V_32 ;
return V_12 ;
}
static T_4 F_17 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 , T_5 V_22 )
{
T_4 V_12 = V_11 ? V_23 : 0 ;
V_12 |= F_18 ( V_8 ) ;
if ( V_10 != V_15 )
V_12 |= V_33 ;
return V_12 ;
}
static T_4 F_19 ( T_2 V_8 ,
enum V_9 V_10 ,
bool V_11 , T_5 V_22 )
{
T_4 V_12 = V_11 ? V_23 : 0 ;
V_12 |= F_18 ( V_8 ) ;
switch ( V_10 ) {
case V_15 :
break;
case V_17 :
V_12 |= V_34 ;
break;
default:
V_12 |= V_35 ;
break;
}
return V_12 ;
}
static int F_20 ( struct V_36 * V_37 , unsigned V_38 ,
T_6 V_39 )
{
int V_40 ;
F_21 ( V_38 >= 4 ) ;
V_40 = F_22 ( V_37 , 6 ) ;
if ( V_40 )
return V_40 ;
F_23 ( V_37 , F_24 ( 1 ) ) ;
F_23 ( V_37 , F_25 ( V_37 , V_38 ) ) ;
F_23 ( V_37 , ( T_5 ) ( V_39 >> 32 ) ) ;
F_23 ( V_37 , F_24 ( 1 ) ) ;
F_23 ( V_37 , F_26 ( V_37 , V_38 ) ) ;
F_23 ( V_37 , ( T_5 ) ( V_39 ) ) ;
F_27 ( V_37 ) ;
return 0 ;
}
static int F_28 ( struct V_41 * V_42 ,
struct V_36 * V_37 )
{
int V_43 , V_40 ;
int V_44 = V_42 -> V_45 / V_46 ;
for ( V_43 = V_44 - 1 ; V_43 >= 0 ; V_43 -- ) {
T_2 V_8 = V_42 -> V_47 [ V_43 ] ;
V_40 = F_20 ( V_37 , V_43 , V_8 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static void F_29 ( struct V_48 * V_49 ,
T_6 V_50 ,
T_6 V_51 ,
bool V_52 )
{
struct V_41 * V_42 =
F_30 ( V_49 , struct V_41 , V_53 ) ;
T_1 * V_54 , V_55 ;
unsigned V_56 = V_50 >> V_57 & V_58 ;
unsigned V_20 = V_50 >> V_59 & V_60 ;
unsigned V_12 = V_50 >> V_61 & V_62 ;
unsigned V_63 = V_51 >> V_64 ;
unsigned V_65 , V_43 ;
V_55 = F_10 ( V_42 -> V_53 . V_66 . V_8 ,
V_25 , V_52 ) ;
while ( V_63 ) {
struct V_67 * V_68 = V_42 -> V_69 [ V_56 ] [ V_20 ] ;
V_65 = V_12 + V_63 ;
if ( V_65 > V_70 )
V_65 = V_70 ;
V_54 = F_31 ( V_68 ) ;
for ( V_43 = V_12 ; V_43 < V_65 ; V_43 ++ ) {
V_54 [ V_43 ] = V_55 ;
V_63 -- ;
}
if ( ! F_32 ( V_42 -> V_53 . V_2 ) )
F_33 ( V_54 , V_71 ) ;
F_34 ( V_54 ) ;
V_12 = 0 ;
if ( ++ V_20 == V_46 ) {
V_56 ++ ;
V_20 = 0 ;
}
}
}
static void F_35 ( struct V_48 * V_49 ,
struct V_72 * V_73 ,
T_6 V_50 ,
enum V_9 V_74 , T_5 V_22 )
{
struct V_41 * V_42 =
F_30 ( V_49 , struct V_41 , V_53 ) ;
T_1 * V_54 ;
unsigned V_56 = V_50 >> V_57 & V_58 ;
unsigned V_20 = V_50 >> V_59 & V_60 ;
unsigned V_12 = V_50 >> V_61 & V_62 ;
struct V_75 V_76 ;
V_54 = NULL ;
F_36 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( F_14 ( V_56 >= V_77 ) )
break;
if ( V_54 == NULL )
V_54 = F_31 ( V_42 -> V_69 [ V_56 ] [ V_20 ] ) ;
V_54 [ V_12 ] =
F_10 ( F_37 ( & V_76 ) ,
V_74 , true ) ;
if ( ++ V_12 == V_70 ) {
if ( ! F_32 ( V_42 -> V_53 . V_2 ) )
F_33 ( V_54 , V_71 ) ;
F_34 ( V_54 ) ;
V_54 = NULL ;
if ( ++ V_20 == V_46 ) {
V_56 ++ ;
V_20 = 0 ;
}
V_12 = 0 ;
}
}
if ( V_54 ) {
if ( ! F_32 ( V_42 -> V_53 . V_2 ) )
F_33 ( V_54 , V_71 ) ;
F_34 ( V_54 ) ;
}
}
static void F_38 ( struct V_67 * * V_78 )
{
int V_43 ;
if ( V_78 == NULL )
return;
for ( V_43 = 0 ; V_43 < V_46 ; V_43 ++ )
if ( V_78 [ V_43 ] )
F_39 ( V_78 [ V_43 ] , 0 ) ;
}
static void F_40 ( const struct V_41 * V_42 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_42 -> V_79 ; V_43 ++ ) {
F_38 ( V_42 -> V_69 [ V_43 ] ) ;
F_41 ( V_42 -> V_69 [ V_43 ] ) ;
F_41 ( V_42 -> V_80 [ V_43 ] ) ;
}
F_39 ( V_42 -> V_81 , F_42 ( V_42 -> V_79 << V_64 ) ) ;
}
static void F_43 ( struct V_41 * V_42 )
{
struct V_82 * V_83 = V_42 -> V_53 . V_2 -> V_6 ;
int V_43 , V_84 ;
for ( V_43 = 0 ; V_43 < V_42 -> V_79 ; V_43 ++ ) {
if ( ! V_42 -> V_47 [ V_43 ] )
continue;
F_44 ( V_83 , V_42 -> V_47 [ V_43 ] , V_71 ,
V_85 ) ;
for ( V_84 = 0 ; V_84 < V_46 ; V_84 ++ ) {
T_2 V_8 = V_42 -> V_80 [ V_43 ] [ V_84 ] ;
if ( V_8 )
F_44 ( V_83 , V_8 , V_71 ,
V_85 ) ;
}
}
}
static void F_45 ( struct V_48 * V_49 )
{
struct V_41 * V_42 =
F_30 ( V_49 , struct V_41 , V_53 ) ;
F_43 ( V_42 ) ;
F_40 ( V_42 ) ;
}
static struct V_67 * * F_46 ( void )
{
struct V_67 * * V_78 ;
int V_43 ;
V_78 = F_47 ( V_46 , sizeof( struct V_67 * ) , V_86 ) ;
if ( ! V_78 )
return F_48 ( - V_87 ) ;
for ( V_43 = 0 ; V_43 < V_46 ; V_43 ++ ) {
V_78 [ V_43 ] = F_49 ( V_86 ) ;
if ( ! V_78 [ V_43 ] )
goto V_88;
}
return V_78 ;
V_88:
F_38 ( V_78 ) ;
F_41 ( V_78 ) ;
return F_48 ( - V_87 ) ;
}
static int F_50 ( struct V_41 * V_42 ,
const int V_89 )
{
struct V_67 * * V_78 [ V_77 ] ;
int V_43 , V_40 ;
for ( V_43 = 0 ; V_43 < V_89 ; V_43 ++ ) {
V_78 [ V_43 ] = F_46 () ;
if ( F_51 ( V_78 [ V_43 ] ) ) {
V_40 = F_52 ( V_78 [ V_43 ] ) ;
goto V_90;
}
}
for ( V_43 = 0 ; V_43 < V_89 ; V_43 ++ )
V_42 -> V_69 [ V_43 ] = V_78 [ V_43 ] ;
return 0 ;
V_90:
while ( V_43 -- ) {
F_38 ( V_78 [ V_43 ] ) ;
F_41 ( V_78 [ V_43 ] ) ;
}
return V_40 ;
}
static int F_53 ( struct V_41 * V_42 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_42 -> V_79 ; V_43 ++ ) {
V_42 -> V_80 [ V_43 ] = F_47 ( V_46 ,
sizeof( T_2 ) ,
V_86 ) ;
if ( ! V_42 -> V_80 [ V_43 ] )
return - V_87 ;
}
return 0 ;
}
static int F_54 ( struct V_41 * V_42 ,
const int V_89 )
{
V_42 -> V_81 = F_55 ( V_86 , F_42 ( V_89 << V_64 ) ) ;
if ( ! V_42 -> V_81 )
return - V_87 ;
V_42 -> V_79 = 1 << F_42 ( V_89 << V_64 ) ;
F_21 ( V_42 -> V_79 > V_77 ) ;
return 0 ;
}
static int F_56 ( struct V_41 * V_42 ,
const int V_89 )
{
int V_40 ;
V_40 = F_54 ( V_42 , V_89 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_50 ( V_42 , V_89 ) ;
if ( V_40 ) {
F_39 ( V_42 -> V_81 , F_42 ( V_89 << V_64 ) ) ;
return V_40 ;
}
V_42 -> V_45 = V_89 * V_46 ;
V_40 = F_53 ( V_42 ) ;
if ( V_40 )
F_40 ( V_42 ) ;
return V_40 ;
}
static int F_57 ( struct V_41 * V_42 ,
const int V_91 )
{
T_2 V_92 ;
int V_40 ;
V_92 = F_58 ( V_42 -> V_53 . V_2 -> V_6 ,
& V_42 -> V_81 [ V_91 ] , 0 ,
V_71 , V_85 ) ;
V_40 = F_59 ( V_42 -> V_53 . V_2 -> V_6 , V_92 ) ;
if ( V_40 )
return V_40 ;
V_42 -> V_47 [ V_91 ] = V_92 ;
return 0 ;
}
static int F_60 ( struct V_41 * V_42 ,
const int V_91 ,
const int V_93 )
{
T_2 V_94 ;
struct V_67 * V_95 ;
int V_40 ;
V_95 = V_42 -> V_69 [ V_91 ] [ V_93 ] ;
V_94 = F_58 ( V_42 -> V_53 . V_2 -> V_6 ,
V_95 , 0 , V_71 , V_85 ) ;
V_40 = F_59 ( V_42 -> V_53 . V_2 -> V_6 , V_94 ) ;
if ( V_40 )
return V_40 ;
V_42 -> V_80 [ V_91 ] [ V_93 ] = V_94 ;
return 0 ;
}
static int F_61 ( struct V_41 * V_42 , T_6 V_96 )
{
const int V_89 = F_62 ( V_96 , 1 << 30 ) ;
const int V_97 = V_46 * V_89 ;
int V_43 , V_84 , V_40 ;
if ( V_96 % ( 1 << 30 ) )
F_6 ( L_3 , V_96 ) ;
V_40 = F_56 ( V_42 , V_89 ) ;
if ( V_40 )
return V_40 ;
for ( V_43 = 0 ; V_43 < V_89 ; V_43 ++ ) {
V_40 = F_57 ( V_42 , V_43 ) ;
if ( V_40 )
goto V_88;
for ( V_84 = 0 ; V_84 < V_46 ; V_84 ++ ) {
V_40 = F_60 ( V_42 , V_43 , V_84 ) ;
if ( V_40 )
goto V_88;
}
}
for ( V_43 = 0 ; V_43 < V_89 ; V_43 ++ ) {
T_3 * V_98 ;
V_98 = F_31 ( & V_42 -> V_81 [ V_43 ] ) ;
for ( V_84 = 0 ; V_84 < V_46 ; V_84 ++ ) {
T_2 V_8 = V_42 -> V_80 [ V_43 ] [ V_84 ] ;
V_98 [ V_84 ] = F_11 ( V_42 -> V_53 . V_2 , V_8 ,
V_25 ) ;
}
if ( ! F_32 ( V_42 -> V_53 . V_2 ) )
F_33 ( V_98 , V_71 ) ;
F_34 ( V_98 ) ;
}
V_42 -> V_99 = F_28 ;
V_42 -> V_53 . V_100 = F_29 ;
V_42 -> V_53 . V_101 = F_35 ;
V_42 -> V_53 . V_102 = F_45 ;
V_42 -> V_53 . V_50 = 0 ;
V_42 -> V_53 . V_103 = V_42 -> V_45 * V_70 * V_71 ;
V_42 -> V_53 . V_100 ( & V_42 -> V_53 , 0 , V_42 -> V_53 . V_103 , true ) ;
F_9 ( L_4 ,
V_42 -> V_79 , V_42 -> V_79 - V_89 ) ;
F_9 ( L_5 ,
V_42 -> V_45 ,
( V_42 -> V_45 - V_97 ) + V_96 % ( 1 << 30 ) ) ;
return 0 ;
V_88:
F_43 ( V_42 ) ;
F_40 ( V_42 ) ;
return V_40 ;
}
static void F_63 ( struct V_41 * V_42 , struct V_104 * V_105 )
{
struct V_106 * V_107 = V_42 -> V_53 . V_2 -> V_108 ;
struct V_48 * V_49 = & V_42 -> V_53 ;
T_4 T_7 * V_92 ;
T_4 V_55 ;
T_8 V_109 ;
int V_12 , V_20 ;
V_55 = V_49 -> V_110 ( V_49 -> V_66 . V_8 , V_25 , true , 0 ) ;
V_92 = ( T_4 T_7 * ) V_107 -> V_111 . V_112 +
V_42 -> V_113 / sizeof( T_4 ) ;
F_64 ( V_105 , L_6 , V_49 ,
V_42 -> V_113 , V_42 -> V_113 + V_42 -> V_45 ) ;
for ( V_20 = 0 ; V_20 < V_42 -> V_45 ; V_20 ++ ) {
T_5 V_114 ;
T_4 * V_54 ;
T_2 V_94 = V_42 -> V_115 [ V_20 ] ;
V_109 = F_65 ( V_92 + V_20 ) ;
V_114 = ( F_66 ( V_94 ) | V_116 ) ;
if ( V_109 != V_114 )
F_64 ( V_105 , L_7 ,
V_20 ,
V_109 ,
V_114 ) ;
F_64 ( V_105 , L_8 , V_109 ) ;
V_54 = F_31 ( V_42 -> V_78 [ V_20 ] ) ;
for ( V_12 = 0 ; V_12 < V_117 ; V_12 += 4 ) {
unsigned long V_118 =
( V_20 * V_71 * V_117 ) +
( V_12 * V_71 ) ;
int V_43 ;
bool V_119 = false ;
for ( V_43 = 0 ; V_43 < 4 ; V_43 ++ )
if ( V_54 [ V_12 + V_43 ] != V_55 )
V_119 = true ;
if ( ! V_119 )
continue;
F_64 ( V_105 , L_9 , V_118 , V_20 , V_12 ) ;
for ( V_43 = 0 ; V_43 < 4 ; V_43 ++ ) {
if ( V_54 [ V_12 + V_43 ] != V_55 )
F_64 ( V_105 , L_10 , V_54 [ V_12 + V_43 ] ) ;
else
F_67 ( V_105 , L_11 ) ;
}
F_67 ( V_105 , L_12 ) ;
}
F_34 ( V_54 ) ;
}
}
static void F_68 ( struct V_41 * V_42 )
{
struct V_106 * V_107 = V_42 -> V_53 . V_2 -> V_108 ;
T_4 T_7 * V_92 ;
T_8 V_109 ;
int V_43 ;
F_14 ( V_42 -> V_113 & 0x3f ) ;
V_92 = ( T_4 T_7 * ) V_107 -> V_111 . V_112 +
V_42 -> V_113 / sizeof( T_4 ) ;
for ( V_43 = 0 ; V_43 < V_42 -> V_45 ; V_43 ++ ) {
T_2 V_94 ;
V_94 = V_42 -> V_115 [ V_43 ] ;
V_109 = F_66 ( V_94 ) ;
V_109 |= V_116 ;
F_69 ( V_109 , V_92 + V_43 ) ;
}
F_65 ( V_92 ) ;
}
static T_8 F_70 ( struct V_41 * V_42 )
{
F_21 ( V_42 -> V_113 & 0x3f ) ;
return ( V_42 -> V_113 / 64 ) << 16 ;
}
static int F_71 ( struct V_41 * V_42 ,
struct V_36 * V_37 )
{
int V_40 ;
V_40 = V_37 -> V_120 ( V_37 , V_121 , V_121 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_22 ( V_37 , 6 ) ;
if ( V_40 )
return V_40 ;
F_23 ( V_37 , F_24 ( 2 ) ) ;
F_23 ( V_37 , F_72 ( V_37 ) ) ;
F_23 ( V_37 , V_122 ) ;
F_23 ( V_37 , F_73 ( V_37 ) ) ;
F_23 ( V_37 , F_70 ( V_42 ) ) ;
F_23 ( V_37 , V_123 ) ;
F_27 ( V_37 ) ;
return 0 ;
}
static int F_74 ( struct V_41 * V_42 ,
struct V_36 * V_37 )
{
int V_40 ;
V_40 = V_37 -> V_120 ( V_37 , V_121 , V_121 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_22 ( V_37 , 6 ) ;
if ( V_40 )
return V_40 ;
F_23 ( V_37 , F_24 ( 2 ) ) ;
F_23 ( V_37 , F_72 ( V_37 ) ) ;
F_23 ( V_37 , V_122 ) ;
F_23 ( V_37 , F_73 ( V_37 ) ) ;
F_23 ( V_37 , F_70 ( V_42 ) ) ;
F_23 ( V_37 , V_123 ) ;
F_27 ( V_37 ) ;
if ( V_37 -> V_124 != V_125 ) {
V_40 = V_37 -> V_120 ( V_37 , V_121 , V_121 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_75 ( struct V_41 * V_42 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 = V_42 -> V_53 . V_2 ;
struct V_106 * V_107 = V_2 -> V_108 ;
F_76 ( F_72 ( V_37 ) , V_122 ) ;
F_76 ( F_73 ( V_37 ) , F_70 ( V_42 ) ) ;
F_77 ( F_72 ( V_37 ) ) ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
struct V_36 * V_37 ;
int V_84 ;
F_79 (ring, dev_priv, j) {
F_76 ( F_80 ( V_37 ) ,
F_81 ( V_126 ) ) ;
}
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
struct V_36 * V_37 ;
T_8 V_127 , V_128 ;
int V_43 ;
V_128 = F_83 ( V_129 ) ;
F_76 ( V_129 , V_128 | V_130 ) ;
V_127 = F_83 ( V_131 ) ;
if ( F_84 ( V_2 ) ) {
V_127 |= V_132 ;
} else {
V_127 |= V_133 ;
V_127 &= ~ V_134 ;
}
F_76 ( V_131 , V_127 ) ;
F_79 (ring, dev_priv, i) {
F_76 ( F_80 ( V_37 ) ,
F_81 ( V_126 ) ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
T_8 V_127 , V_135 , V_128 ;
V_128 = F_83 ( V_129 ) ;
F_76 ( V_129 , V_128 | V_136 |
V_130 ) ;
V_135 = F_83 ( V_137 ) ;
F_76 ( V_137 , V_135 | V_138 ) ;
V_127 = F_83 ( V_131 ) ;
F_76 ( V_131 , V_127 | V_139 | V_140 ) ;
F_76 ( V_141 , F_81 ( V_126 ) ) ;
}
static void F_86 ( struct V_48 * V_49 ,
T_6 V_50 ,
T_6 V_51 ,
bool V_52 )
{
struct V_41 * V_42 =
F_30 ( V_49 , struct V_41 , V_53 ) ;
T_4 * V_54 , V_55 ;
unsigned V_142 = V_50 >> V_64 ;
unsigned V_63 = V_51 >> V_64 ;
unsigned V_143 = V_142 / V_117 ;
unsigned V_144 = V_142 % V_117 ;
unsigned V_65 , V_43 ;
V_55 = V_49 -> V_110 ( V_49 -> V_66 . V_8 , V_25 , true , 0 ) ;
while ( V_63 ) {
V_65 = V_144 + V_63 ;
if ( V_65 > V_117 )
V_65 = V_117 ;
V_54 = F_31 ( V_42 -> V_78 [ V_143 ] ) ;
for ( V_43 = V_144 ; V_43 < V_65 ; V_43 ++ )
V_54 [ V_43 ] = V_55 ;
F_34 ( V_54 ) ;
V_63 -= V_65 - V_144 ;
V_144 = 0 ;
V_143 ++ ;
}
}
static void F_87 ( struct V_48 * V_49 ,
struct V_72 * V_73 ,
T_6 V_50 ,
enum V_9 V_74 , T_5 V_29 )
{
struct V_41 * V_42 =
F_30 ( V_49 , struct V_41 , V_53 ) ;
T_4 * V_54 ;
unsigned V_142 = V_50 >> V_64 ;
unsigned V_143 = V_142 / V_117 ;
unsigned V_145 = V_142 % V_117 ;
struct V_75 V_76 ;
V_54 = NULL ;
F_36 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_54 == NULL )
V_54 = F_31 ( V_42 -> V_78 [ V_143 ] ) ;
V_54 [ V_145 ] =
V_49 -> V_110 ( F_37 ( & V_76 ) ,
V_74 , true , V_29 ) ;
if ( ++ V_145 == V_117 ) {
F_34 ( V_54 ) ;
V_54 = NULL ;
V_143 ++ ;
V_145 = 0 ;
}
}
if ( V_54 )
F_34 ( V_54 ) ;
}
static void F_88 ( struct V_41 * V_42 )
{
int V_43 ;
if ( V_42 -> V_115 ) {
for ( V_43 = 0 ; V_43 < V_42 -> V_45 ; V_43 ++ )
F_44 ( V_42 -> V_53 . V_2 -> V_6 ,
V_42 -> V_115 [ V_43 ] ,
4096 , V_85 ) ;
}
}
static void F_89 ( struct V_41 * V_42 )
{
int V_43 ;
F_41 ( V_42 -> V_115 ) ;
for ( V_43 = 0 ; V_43 < V_42 -> V_45 ; V_43 ++ )
F_90 ( V_42 -> V_78 [ V_43 ] ) ;
F_41 ( V_42 -> V_78 ) ;
}
static void F_91 ( struct V_48 * V_49 )
{
struct V_41 * V_42 =
F_30 ( V_49 , struct V_41 , V_53 ) ;
F_92 ( & V_42 -> V_146 ) ;
F_88 ( V_42 ) ;
F_89 ( V_42 ) ;
}
static int F_93 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_53 . V_2 ;
struct V_106 * V_107 = V_2 -> V_108 ;
bool V_147 = false ;
int V_40 ;
F_21 ( ! F_94 ( & V_107 -> V_111 . V_53 . V_148 ) ) ;
V_149:
V_40 = F_95 ( & V_107 -> V_111 . V_53 . V_148 ,
& V_42 -> V_146 , V_150 ,
V_151 , 0 ,
0 , V_107 -> V_111 . V_53 . V_103 ,
V_152 ) ;
if ( V_40 == - V_153 && ! V_147 ) {
V_40 = F_96 ( V_2 , & V_107 -> V_111 . V_53 ,
V_150 , V_151 ,
V_15 ,
0 , V_107 -> V_111 . V_53 . V_103 ,
0 ) ;
if ( V_40 )
return V_40 ;
V_147 = true ;
goto V_149;
}
if ( V_42 -> V_146 . V_50 < V_107 -> V_111 . V_154 )
F_97 ( L_13 ) ;
V_42 -> V_45 = V_155 ;
return V_40 ;
}
static int F_98 ( struct V_41 * V_42 )
{
int V_43 ;
V_42 -> V_78 = F_47 ( V_42 -> V_45 , sizeof( struct V_67 * ) ,
V_86 ) ;
if ( ! V_42 -> V_78 )
return - V_87 ;
for ( V_43 = 0 ; V_43 < V_42 -> V_45 ; V_43 ++ ) {
V_42 -> V_78 [ V_43 ] = F_49 ( V_86 ) ;
if ( ! V_42 -> V_78 [ V_43 ] ) {
F_89 ( V_42 ) ;
return - V_87 ;
}
}
return 0 ;
}
static int F_99 ( struct V_41 * V_42 )
{
int V_40 ;
V_40 = F_93 ( V_42 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_98 ( V_42 ) ;
if ( V_40 ) {
F_92 ( & V_42 -> V_146 ) ;
return V_40 ;
}
V_42 -> V_115 = F_47 ( V_42 -> V_45 , sizeof( T_2 ) ,
V_86 ) ;
if ( ! V_42 -> V_115 ) {
F_92 ( & V_42 -> V_146 ) ;
F_89 ( V_42 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_100 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_53 . V_2 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_42 -> V_45 ; V_43 ++ ) {
T_2 V_94 ;
V_94 = F_58 ( V_2 -> V_6 , V_42 -> V_78 [ V_43 ] , 0 , 4096 ,
V_85 ) ;
if ( F_59 ( V_2 -> V_6 , V_94 ) ) {
F_88 ( V_42 ) ;
return - V_156 ;
}
V_42 -> V_115 [ V_43 ] = V_94 ;
}
return 0 ;
}
static int F_101 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_53 . V_2 ;
struct V_106 * V_107 = V_2 -> V_108 ;
int V_40 ;
V_42 -> V_53 . V_110 = V_107 -> V_111 . V_53 . V_110 ;
if ( F_102 ( V_2 ) ) {
V_42 -> V_99 = F_75 ;
} else if ( F_84 ( V_2 ) ) {
V_42 -> V_99 = F_71 ;
} else if ( F_103 ( V_2 ) ) {
V_42 -> V_99 = F_74 ;
} else
F_104 () ;
V_40 = F_99 ( V_42 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_100 ( V_42 ) ;
if ( V_40 ) {
F_89 ( V_42 ) ;
return V_40 ;
}
V_42 -> V_53 . V_100 = F_86 ;
V_42 -> V_53 . V_101 = F_87 ;
V_42 -> V_53 . V_102 = F_91 ;
V_42 -> V_53 . V_50 = 0 ;
V_42 -> V_53 . V_103 = V_42 -> V_45 * V_117 * V_71 ;
V_42 -> V_157 = F_63 ;
V_42 -> V_113 =
V_42 -> V_146 . V_50 / V_71 * sizeof( T_4 ) ;
V_42 -> V_53 . V_100 ( & V_42 -> V_53 , 0 , V_42 -> V_53 . V_103 , true ) ;
F_9 ( L_14 ,
V_42 -> V_146 . V_96 >> 20 ,
V_42 -> V_146 . V_50 / V_71 ) ;
F_68 ( V_42 ) ;
F_97 ( L_15 ,
V_42 -> V_113 << 10 ) ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
V_42 -> V_53 . V_2 = V_2 ;
V_42 -> V_53 . V_66 = V_107 -> V_111 . V_53 . V_66 ;
if ( F_5 ( V_2 ) -> V_4 < 8 )
return F_101 ( V_42 ) ;
else if ( F_106 ( V_2 ) )
return F_61 ( V_42 , V_107 -> V_111 . V_53 . V_103 ) ;
else
F_104 () ;
}
int F_107 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
int V_40 = 0 ;
V_40 = F_105 ( V_2 , V_42 ) ;
if ( V_40 == 0 ) {
F_108 ( & V_42 -> V_158 ) ;
F_109 ( & V_42 -> V_53 . V_148 , V_42 -> V_53 . V_50 ,
V_42 -> V_53 . V_103 ) ;
F_110 ( V_107 , & V_42 -> V_53 ) ;
}
return V_40 ;
}
int F_111 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
struct V_36 * V_37 ;
struct V_41 * V_42 = V_107 -> V_148 . V_159 ;
int V_43 , V_40 = 0 ;
if ( V_160 . V_161 )
return 0 ;
if ( ! F_112 ( V_2 ) )
return 0 ;
if ( F_102 ( V_2 ) )
F_85 ( V_2 ) ;
else if ( F_103 ( V_2 ) )
F_82 ( V_2 ) ;
else if ( F_5 ( V_2 ) -> V_4 >= 8 )
F_78 ( V_2 ) ;
else
F_14 ( 1 ) ;
if ( V_42 ) {
F_79 (ring, dev_priv, i) {
V_40 = V_42 -> V_99 ( V_42 , V_37 ) ;
if ( V_40 != 0 )
return V_40 ;
}
}
return V_40 ;
}
struct V_41 *
F_113 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
struct V_41 * V_42 ;
int V_40 ;
V_42 = F_114 ( sizeof( * V_42 ) , V_86 ) ;
if ( ! V_42 )
return F_48 ( - V_87 ) ;
V_40 = F_107 ( V_2 , V_42 ) ;
if ( V_40 ) {
F_41 ( V_42 ) ;
return F_48 ( V_40 ) ;
}
V_42 -> V_164 = V_163 ;
return V_42 ;
}
void F_115 ( struct V_165 * V_165 )
{
struct V_41 * V_42 =
F_30 ( V_165 , struct V_41 , V_158 ) ;
F_14 ( ! F_116 ( & V_42 -> V_53 . V_166 ) ) ;
F_14 ( ! F_116 ( & V_42 -> V_53 . V_167 ) ) ;
F_117 ( & V_42 -> V_53 . V_168 ) ;
F_118 ( & V_42 -> V_53 . V_148 ) ;
V_42 -> V_53 . V_102 ( & V_42 -> V_53 ) ;
F_41 ( V_42 ) ;
}
static void
F_119 ( struct V_169 * V_170 ,
enum V_9 V_74 ,
T_5 V_29 )
{
if ( V_170 -> V_171 -> V_172 )
V_29 |= V_30 ;
V_170 -> V_49 -> V_101 ( V_170 -> V_49 , V_170 -> V_171 -> V_73 , V_170 -> V_146 . V_50 ,
V_74 , V_29 ) ;
}
static void F_120 ( struct V_169 * V_170 )
{
V_170 -> V_49 -> V_100 ( V_170 -> V_49 ,
V_170 -> V_146 . V_50 ,
V_170 -> V_171 -> V_53 . V_96 ,
true ) ;
}
static inline bool F_121 ( struct V_1 * V_2 )
{
#ifdef F_4
if ( F_122 ( V_2 ) && F_123 ( V_2 ) && V_5 )
return true ;
#endif
return false ;
}
static bool F_124 ( struct V_106 * V_107 )
{
bool V_40 = V_107 -> V_148 . V_173 ;
if ( F_125 ( V_107 -> V_111 . V_174 ) ) {
V_107 -> V_148 . V_173 = false ;
if ( F_126 ( V_107 -> V_2 ) ) {
F_127 ( L_16 ) ;
F_128 ( 10 ) ;
}
}
return V_40 ;
}
static void F_129 ( struct V_106 * V_107 , bool V_173 )
{
if ( F_125 ( V_107 -> V_111 . V_174 ) )
V_107 -> V_148 . V_173 = V_173 ;
}
void F_130 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
struct V_36 * V_37 ;
int V_43 ;
if ( F_5 ( V_2 ) -> V_4 < 6 )
return;
F_79 (ring, dev_priv, i) {
T_5 V_175 ;
V_175 = F_83 ( F_131 ( V_37 ) ) ;
if ( V_175 & V_176 ) {
F_9 ( L_17
L_18
L_19
L_20
L_21 ,
V_175 & V_177 ,
V_175 & V_178 ? L_22 : L_23 ,
F_132 ( V_175 ) ,
F_133 ( V_175 ) ) ;
F_76 ( F_131 ( V_37 ) ,
V_175 & ~ V_176 ) ;
}
}
F_77 ( F_131 ( & V_107 -> V_37 [ V_125 ] ) ) ;
}
static void F_134 ( struct V_106 * V_107 )
{
if ( F_5 ( V_107 -> V_2 ) -> V_4 < 6 ) {
F_135 () ;
} else {
F_76 ( V_179 , V_180 ) ;
F_77 ( V_179 ) ;
}
}
void F_136 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
if ( F_5 ( V_2 ) -> V_4 < 6 )
return;
F_130 ( V_2 ) ;
V_107 -> V_111 . V_53 . V_100 ( & V_107 -> V_111 . V_53 ,
V_107 -> V_111 . V_53 . V_50 ,
V_107 -> V_111 . V_53 . V_103 ,
true ) ;
F_134 ( V_107 ) ;
}
void F_137 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
struct V_181 * V_171 ;
struct V_48 * V_49 ;
F_130 ( V_2 ) ;
V_107 -> V_111 . V_53 . V_100 ( & V_107 -> V_111 . V_53 ,
V_107 -> V_111 . V_53 . V_50 ,
V_107 -> V_111 . V_53 . V_103 ,
true ) ;
F_138 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_169 * V_170 = F_139 ( V_171 ,
& V_107 -> V_111 . V_53 ) ;
if ( ! V_170 )
continue;
F_140 ( V_171 , V_171 -> V_182 ) ;
V_171 -> V_183 = 0 ;
V_170 -> V_184 ( V_170 , V_171 -> V_74 , V_185 ) ;
}
if ( F_5 ( V_2 ) -> V_4 >= 8 ) {
if ( F_8 ( V_2 ) )
F_141 ( V_107 ) ;
else
F_142 ( V_107 ) ;
return;
}
F_138 (vm, &dev_priv->vm_list, global_link) {
if ( F_143 ( V_49 ) ) {
if ( V_107 -> V_148 . V_159 )
F_68 ( V_107 -> V_148 . V_159 ) ;
continue;
}
F_68 ( F_30 ( V_49 , struct V_41 , V_53 ) ) ;
}
F_134 ( V_107 ) ;
}
int F_144 ( struct V_181 * V_171 )
{
if ( V_171 -> V_186 )
return 0 ;
if ( ! F_145 ( & V_171 -> V_53 . V_2 -> V_6 -> V_2 ,
V_171 -> V_73 -> V_187 , V_171 -> V_73 -> V_188 ,
V_85 ) )
return - V_153 ;
return 0 ;
}
static inline void F_146 ( void T_7 * V_8 , T_1 V_12 )
{
#ifdef F_147
F_147 ( V_12 , V_8 ) ;
#else
F_148 ( ( T_5 ) V_12 , V_8 ) ;
F_148 ( V_12 >> 32 , V_8 + 4 ) ;
#endif
}
static void F_149 ( struct V_48 * V_49 ,
struct V_72 * V_189 ,
T_6 V_50 ,
enum V_9 V_10 , T_5 V_22 )
{
struct V_106 * V_107 = V_49 -> V_2 -> V_108 ;
unsigned V_142 = V_50 >> V_64 ;
T_1 T_7 * V_190 =
( T_1 T_7 * ) V_107 -> V_111 . V_112 + V_142 ;
int V_43 = 0 ;
struct V_75 V_76 ;
T_2 V_8 = 0 ;
F_36 (st->sgl, &sg_iter, st->nents, 0 ) {
V_8 = F_150 ( V_76 . V_191 ) +
( V_76 . V_192 << V_64 ) ;
F_146 ( & V_190 [ V_43 ] ,
F_10 ( V_8 , V_10 , true ) ) ;
V_43 ++ ;
}
if ( V_43 != 0 )
F_14 ( F_151 ( & V_190 [ V_43 - 1 ] )
!= F_10 ( V_8 , V_10 , true ) ) ;
F_76 ( V_179 , V_180 ) ;
F_77 ( V_179 ) ;
}
static void F_152 ( struct V_48 * V_49 ,
struct V_72 * V_189 ,
T_6 V_50 ,
enum V_9 V_10 , T_5 V_29 )
{
struct V_106 * V_107 = V_49 -> V_2 -> V_108 ;
unsigned V_142 = V_50 >> V_64 ;
T_4 T_7 * V_190 =
( T_4 T_7 * ) V_107 -> V_111 . V_112 + V_142 ;
int V_43 = 0 ;
struct V_75 V_76 ;
T_2 V_8 = 0 ;
F_36 (st->sgl, &sg_iter, st->nents, 0 ) {
V_8 = F_37 ( & V_76 ) ;
F_148 ( V_49 -> V_110 ( V_8 , V_10 , true , V_29 ) , & V_190 [ V_43 ] ) ;
V_43 ++ ;
}
if ( V_43 != 0 ) {
unsigned long V_111 = F_65 ( & V_190 [ V_43 - 1 ] ) ;
F_14 ( V_111 != V_49 -> V_110 ( V_8 , V_10 , true , V_29 ) ) ;
}
F_76 ( V_179 , V_180 ) ;
F_77 ( V_179 ) ;
}
static void F_153 ( struct V_48 * V_49 ,
T_6 V_50 ,
T_6 V_51 ,
bool V_52 )
{
struct V_106 * V_107 = V_49 -> V_2 -> V_108 ;
unsigned V_142 = V_50 >> V_64 ;
unsigned V_63 = V_51 >> V_64 ;
T_1 V_55 , T_7 * V_193 =
( T_1 T_7 * ) V_107 -> V_111 . V_112 + V_142 ;
const int V_194 = F_154 ( V_107 -> V_111 ) - V_142 ;
int V_43 ;
if ( F_155 ( V_63 > V_194 ,
L_24 ,
V_142 , V_63 , V_194 ) )
V_63 = V_194 ;
V_55 = F_10 ( V_49 -> V_66 . V_8 ,
V_25 ,
V_52 ) ;
for ( V_43 = 0 ; V_43 < V_63 ; V_43 ++ )
F_146 ( & V_193 [ V_43 ] , V_55 ) ;
F_65 ( V_193 ) ;
}
static void F_156 ( struct V_48 * V_49 ,
T_6 V_50 ,
T_6 V_51 ,
bool V_52 )
{
struct V_106 * V_107 = V_49 -> V_2 -> V_108 ;
unsigned V_142 = V_50 >> V_64 ;
unsigned V_63 = V_51 >> V_64 ;
T_4 V_55 , T_7 * V_193 =
( T_4 T_7 * ) V_107 -> V_111 . V_112 + V_142 ;
const int V_194 = F_154 ( V_107 -> V_111 ) - V_142 ;
int V_43 ;
if ( F_155 ( V_63 > V_194 ,
L_24 ,
V_142 , V_63 , V_194 ) )
V_63 = V_194 ;
V_55 = V_49 -> V_110 ( V_49 -> V_66 . V_8 , V_25 , V_52 , 0 ) ;
for ( V_43 = 0 ; V_43 < V_63 ; V_43 ++ )
F_148 ( V_55 , & V_193 [ V_43 ] ) ;
F_65 ( V_193 ) ;
}
static void F_157 ( struct V_169 * V_170 ,
enum V_9 V_74 ,
T_5 V_22 )
{
const unsigned long V_38 = V_170 -> V_146 . V_50 >> V_64 ;
unsigned int V_29 = ( V_74 == V_15 ) ?
V_195 : V_196 ;
F_21 ( ! F_143 ( V_170 -> V_49 ) ) ;
F_158 ( V_170 -> V_171 -> V_73 , V_38 , V_29 ) ;
V_170 -> V_171 -> V_183 = 1 ;
}
static void F_159 ( struct V_48 * V_49 ,
T_6 V_50 ,
T_6 V_51 ,
bool V_22 )
{
unsigned V_142 = V_50 >> V_64 ;
unsigned V_63 = V_51 >> V_64 ;
F_160 ( V_142 , V_63 ) ;
}
static void F_161 ( struct V_169 * V_170 )
{
const unsigned int V_197 = V_170 -> V_146 . V_50 >> V_64 ;
const unsigned int V_96 = V_170 -> V_171 -> V_53 . V_96 >> V_64 ;
F_21 ( ! F_143 ( V_170 -> V_49 ) ) ;
V_170 -> V_171 -> V_183 = 0 ;
F_160 ( V_197 , V_96 ) ;
}
static void F_162 ( struct V_169 * V_170 ,
enum V_9 V_74 ,
T_5 V_29 )
{
struct V_1 * V_2 = V_170 -> V_49 -> V_2 ;
struct V_106 * V_107 = V_2 -> V_108 ;
struct V_181 * V_171 = V_170 -> V_171 ;
if ( V_171 -> V_172 )
V_29 |= V_30 ;
if ( ! V_107 -> V_148 . V_159 || V_29 & V_185 ) {
if ( ! V_171 -> V_183 ||
( V_74 != V_171 -> V_74 ) ) {
V_170 -> V_49 -> V_101 ( V_170 -> V_49 , V_171 -> V_73 ,
V_170 -> V_146 . V_50 ,
V_74 , V_29 ) ;
V_171 -> V_183 = 1 ;
}
}
if ( V_107 -> V_148 . V_159 &&
( ! V_171 -> V_198 ||
( V_74 != V_171 -> V_74 ) ) ) {
struct V_41 * V_199 = V_107 -> V_148 . V_159 ;
V_199 -> V_53 . V_101 ( & V_199 -> V_53 ,
V_170 -> V_171 -> V_73 ,
V_170 -> V_146 . V_50 ,
V_74 , V_29 ) ;
V_170 -> V_171 -> V_198 = 1 ;
}
}
static void F_163 ( struct V_169 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_49 -> V_2 ;
struct V_106 * V_107 = V_2 -> V_108 ;
struct V_181 * V_171 = V_170 -> V_171 ;
if ( V_171 -> V_183 ) {
V_170 -> V_49 -> V_100 ( V_170 -> V_49 ,
V_170 -> V_146 . V_50 ,
V_171 -> V_53 . V_96 ,
true ) ;
V_171 -> V_183 = 0 ;
}
if ( V_171 -> V_198 ) {
struct V_41 * V_199 = V_107 -> V_148 . V_159 ;
V_199 -> V_53 . V_100 ( & V_199 -> V_53 ,
V_170 -> V_146 . V_50 ,
V_171 -> V_53 . V_96 ,
true ) ;
V_171 -> V_198 = 0 ;
}
}
void F_164 ( struct V_181 * V_171 )
{
struct V_1 * V_2 = V_171 -> V_53 . V_2 ;
struct V_106 * V_107 = V_2 -> V_108 ;
bool V_173 ;
V_173 = F_124 ( V_107 ) ;
if ( ! V_171 -> V_186 )
F_165 ( & V_2 -> V_6 -> V_2 ,
V_171 -> V_73 -> V_187 , V_171 -> V_73 -> V_188 ,
V_85 ) ;
F_129 ( V_107 , V_173 ) ;
}
static void F_166 ( struct V_200 * V_146 ,
unsigned long V_201 ,
unsigned long * V_50 ,
unsigned long * V_202 )
{
if ( V_146 -> V_201 != V_201 )
* V_50 += 4096 ;
if ( ! F_116 ( & V_146 -> V_203 ) ) {
V_146 = F_167 ( V_146 -> V_203 . V_204 ,
struct V_200 ,
V_203 ) ;
if ( V_146 -> V_205 && V_146 -> V_201 != V_201 )
* V_202 -= 4096 ;
}
}
int F_168 ( struct V_1 * V_2 ,
unsigned long V_50 ,
unsigned long V_154 ,
unsigned long V_202 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
struct V_48 * V_206 = & V_107 -> V_111 . V_53 ;
struct V_200 * V_38 ;
struct V_181 * V_171 ;
unsigned long V_207 , V_208 ;
int V_40 ;
F_21 ( V_154 > V_202 ) ;
F_109 ( & V_206 -> V_148 , V_50 , V_202 - V_50 - V_71 ) ;
if ( ! F_32 ( V_2 ) )
V_107 -> V_111 . V_53 . V_148 . V_209 = F_166 ;
F_138 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_169 * V_170 = F_139 ( V_171 , V_206 ) ;
F_169 ( L_25 ,
F_170 ( V_171 ) , V_171 -> V_53 . V_96 ) ;
F_14 ( F_171 ( V_171 ) ) ;
V_40 = F_172 ( & V_206 -> V_148 , & V_170 -> V_146 ) ;
if ( V_40 ) {
F_169 ( L_26 , V_40 ) ;
return V_40 ;
}
V_171 -> V_183 = 1 ;
}
V_107 -> V_111 . V_53 . V_50 = V_50 ;
V_107 -> V_111 . V_53 . V_103 = V_202 - V_50 ;
F_173 (entry, &ggtt_vm->mm, hole_start, hole_end) {
F_169 ( L_27 ,
V_207 , V_208 ) ;
V_206 -> V_100 ( V_206 , V_207 ,
V_208 - V_207 , true ) ;
}
V_206 -> V_100 ( V_206 , V_202 - V_71 , V_71 , true ) ;
if ( F_112 ( V_2 ) && ! F_174 ( V_2 ) ) {
struct V_41 * V_42 ;
V_42 = F_114 ( sizeof( * V_42 ) , V_86 ) ;
if ( ! V_42 )
return - V_87 ;
V_40 = F_105 ( V_2 , V_42 ) ;
if ( V_40 != 0 )
return V_40 ;
V_107 -> V_148 . V_159 = V_42 ;
}
return 0 ;
}
void F_175 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
unsigned long V_210 , V_211 ;
V_210 = V_107 -> V_111 . V_53 . V_103 ;
V_211 = V_107 -> V_111 . V_154 ;
F_168 ( V_2 , 0 , V_211 , V_210 ) ;
}
void F_176 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
struct V_48 * V_49 = & V_107 -> V_111 . V_53 ;
if ( V_107 -> V_148 . V_159 ) {
struct V_41 * V_42 = V_107 -> V_148 . V_159 ;
V_42 -> V_53 . V_102 ( & V_42 -> V_53 ) ;
}
if ( F_94 ( & V_49 -> V_148 ) ) {
F_118 ( & V_49 -> V_148 ) ;
F_117 ( & V_49 -> V_168 ) ;
}
V_49 -> V_102 ( V_49 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
struct V_67 * V_67 ;
T_2 V_212 ;
V_67 = F_49 ( V_86 | V_213 | V_214 ) ;
if ( V_67 == NULL )
return - V_87 ;
F_178 ( V_67 ) ;
F_179 ( V_67 , 1 ) ;
#ifdef F_4
V_212 = F_58 ( V_2 -> V_6 , V_67 , 0 , V_71 ,
V_85 ) ;
if ( F_59 ( V_2 -> V_6 , V_212 ) )
return - V_215 ;
#else
V_212 = F_180 ( V_67 ) ;
#endif
V_107 -> V_111 . V_53 . V_66 . V_67 = V_67 ;
V_107 -> V_111 . V_53 . V_66 . V_8 = V_212 ;
return 0 ;
}
static void F_181 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
struct V_67 * V_67 = V_107 -> V_111 . V_53 . V_66 . V_67 ;
F_182 ( V_67 , 1 ) ;
F_44 ( V_2 -> V_6 , V_107 -> V_111 . V_53 . V_66 . V_8 ,
V_71 , V_85 ) ;
F_183 ( V_67 ) ;
F_90 ( V_67 ) ;
}
static inline unsigned int F_184 ( T_9 V_216 )
{
V_216 >>= V_217 ;
V_216 &= V_218 ;
return V_216 << 20 ;
}
static inline unsigned int F_185 ( T_9 V_219 )
{
V_219 >>= V_220 ;
V_219 &= V_221 ;
if ( V_219 )
V_219 = 1 << V_219 ;
#ifdef F_186
if ( V_219 > 4 )
V_219 = 4 ;
#endif
return V_219 << 20 ;
}
static inline unsigned int F_187 ( T_9 V_222 )
{
V_222 >>= V_217 ;
V_222 &= V_218 ;
if ( V_222 )
return 1 << ( 20 + V_222 ) ;
return 0 ;
}
static inline T_10 F_188 ( T_9 V_216 )
{
V_216 >>= V_223 ;
V_216 &= V_224 ;
return V_216 << 25 ;
}
static inline T_10 F_189 ( T_9 V_219 )
{
V_219 >>= V_225 ;
V_219 &= V_226 ;
return V_219 << 25 ;
}
static T_10 F_190 ( T_9 V_222 )
{
V_222 >>= V_223 ;
V_222 &= V_224 ;
if ( V_222 < 0x11 )
return V_222 << 25 ;
else if ( V_222 < 0x17 )
return ( V_222 - 0x11 + 2 ) << 22 ;
else
return ( V_222 - 0x17 + 9 ) << 22 ;
}
static int F_191 ( struct V_1 * V_2 ,
T_10 V_210 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
T_11 V_227 ;
int V_40 ;
V_227 = F_192 ( V_2 -> V_6 , 0 ) +
( F_193 ( V_2 -> V_6 , 0 ) / 2 ) ;
V_107 -> V_111 . V_112 = F_194 ( V_227 , V_210 ) ;
if ( ! V_107 -> V_111 . V_112 ) {
F_127 ( L_28 ) ;
return - V_87 ;
}
V_40 = F_177 ( V_2 ) ;
if ( V_40 ) {
F_127 ( L_29 ) ;
F_195 ( V_107 -> V_111 . V_112 ) ;
}
return V_40 ;
}
static void F_142 ( struct V_106 * V_107 )
{
T_6 V_228 ;
V_228 = F_196 ( 0 , V_229 | V_230 ) |
F_196 ( 1 , V_231 | V_232 ) |
F_196 ( 2 , V_233 | V_232 ) |
F_196 ( 3 , V_234 ) |
F_196 ( 4 , V_229 | V_232 | F_197 ( 0 ) ) |
F_196 ( 5 , V_229 | V_232 | F_197 ( 1 ) ) |
F_196 ( 6 , V_229 | V_232 | F_197 ( 2 ) ) |
F_196 ( 7 , V_229 | V_232 | F_197 ( 3 ) ) ;
if ( ! F_112 ( V_107 -> V_2 ) )
V_228 = F_196 ( 0 , V_234 ) ;
F_76 ( V_235 , V_228 ) ;
F_76 ( V_235 + 4 , V_228 >> 32 ) ;
}
static void F_141 ( struct V_106 * V_107 )
{
T_6 V_228 ;
V_228 = F_196 ( 0 , V_236 ) |
F_196 ( 1 , 0 ) |
F_196 ( 2 , 0 ) |
F_196 ( 3 , 0 ) |
F_196 ( 4 , V_236 ) |
F_196 ( 5 , V_236 ) |
F_196 ( 6 , V_236 ) |
F_196 ( 7 , V_236 ) ;
F_76 ( V_235 , V_228 ) ;
F_76 ( V_235 + 4 , V_228 >> 32 ) ;
}
static int F_198 ( struct V_1 * V_2 ,
T_10 * V_237 ,
T_10 * V_238 ,
T_11 * V_239 ,
unsigned long * V_154 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
unsigned int V_210 ;
T_9 V_216 ;
int V_40 ;
* V_239 = F_192 ( V_2 -> V_6 , 2 ) ;
* V_154 = F_193 ( V_2 -> V_6 , 2 ) ;
if ( ! F_199 ( V_2 -> V_6 , F_200 ( 39 ) ) )
F_201 ( V_2 -> V_6 , F_200 ( 39 ) ) ;
F_202 ( V_2 -> V_6 , V_240 , & V_216 ) ;
if ( F_8 ( V_2 ) ) {
* V_238 = F_190 ( V_216 ) ;
V_210 = F_187 ( V_216 ) ;
} else {
* V_238 = F_189 ( V_216 ) ;
V_210 = F_185 ( V_216 ) ;
}
* V_237 = ( V_210 / sizeof( T_1 ) ) << V_64 ;
if ( F_8 ( V_2 ) )
F_141 ( V_107 ) ;
else
F_142 ( V_107 ) ;
V_40 = F_191 ( V_2 , V_210 ) ;
V_107 -> V_111 . V_53 . V_100 = F_153 ;
V_107 -> V_111 . V_53 . V_101 = F_149 ;
return V_40 ;
}
static int F_203 ( struct V_1 * V_2 ,
T_10 * V_237 ,
T_10 * V_238 ,
T_11 * V_239 ,
unsigned long * V_154 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
unsigned int V_210 ;
T_9 V_216 ;
int V_40 ;
* V_239 = F_192 ( V_2 -> V_6 , 2 ) ;
* V_154 = F_193 ( V_2 -> V_6 , 2 ) ;
if ( ( * V_154 < ( 64 << 20 ) || ( * V_154 > ( 512 << 20 ) ) ) ) {
F_127 ( L_30 ,
V_107 -> V_111 . V_154 ) ;
return - V_241 ;
}
if ( ! F_199 ( V_2 -> V_6 , F_200 ( 40 ) ) )
F_201 ( V_2 -> V_6 , F_200 ( 40 ) ) ;
F_202 ( V_2 -> V_6 , V_240 , & V_216 ) ;
* V_238 = F_188 ( V_216 ) ;
V_210 = F_184 ( V_216 ) ;
* V_237 = ( V_210 / sizeof( T_4 ) ) << V_64 ;
V_40 = F_191 ( V_2 , V_210 ) ;
V_107 -> V_111 . V_53 . V_100 = F_156 ;
V_107 -> V_111 . V_53 . V_101 = F_152 ;
return V_40 ;
}
static void F_204 ( struct V_48 * V_49 )
{
struct V_242 * V_111 = F_30 ( V_49 , struct V_242 , V_53 ) ;
F_195 ( V_111 -> V_112 ) ;
F_181 ( V_49 -> V_2 ) ;
}
static int F_205 ( struct V_1 * V_2 ,
T_10 * V_237 ,
T_10 * V_238 ,
T_11 * V_239 ,
unsigned long * V_154 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
int V_40 ;
V_40 = F_206 ( V_107 -> V_243 , V_107 -> V_2 -> V_6 , NULL ) ;
if ( ! V_40 ) {
F_127 ( L_31 ) ;
return - V_156 ;
}
F_207 ( V_237 , V_238 , V_239 , V_154 ) ;
V_107 -> V_111 . V_174 = F_121 ( V_107 -> V_2 ) ;
V_107 -> V_111 . V_53 . V_100 = F_159 ;
if ( F_125 ( V_107 -> V_111 . V_174 ) )
F_6 ( L_32 ) ;
return 0 ;
}
static void F_208 ( struct V_48 * V_49 )
{
F_209 () ;
}
int F_210 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_108 ;
struct V_242 * V_111 = & V_107 -> V_111 ;
int V_40 ;
if ( F_5 ( V_2 ) -> V_4 <= 5 ) {
V_111 -> V_244 = F_205 ;
V_111 -> V_53 . V_102 = F_208 ;
} else if ( F_5 ( V_2 ) -> V_4 < 8 ) {
V_111 -> V_244 = F_203 ;
V_111 -> V_53 . V_102 = F_204 ;
if ( F_84 ( V_2 ) && V_107 -> V_245 )
V_111 -> V_53 . V_110 = F_19 ;
else if ( F_84 ( V_2 ) )
V_111 -> V_53 . V_110 = F_17 ;
else if ( F_7 ( V_2 ) )
V_111 -> V_53 . V_110 = F_16 ;
else if ( F_5 ( V_2 ) -> V_4 >= 7 )
V_111 -> V_53 . V_110 = F_15 ;
else
V_111 -> V_53 . V_110 = F_12 ;
} else {
V_107 -> V_111 . V_244 = F_198 ;
V_107 -> V_111 . V_53 . V_102 = F_204 ;
}
V_40 = V_111 -> V_244 ( V_2 , & V_111 -> V_53 . V_103 , & V_111 -> V_246 ,
& V_111 -> V_239 , & V_111 -> V_154 ) ;
if ( V_40 )
return V_40 ;
V_111 -> V_53 . V_2 = V_2 ;
F_6 ( L_33 ,
V_111 -> V_53 . V_103 >> 20 ) ;
F_9 ( L_34 , V_111 -> V_154 >> 20 ) ;
F_9 ( L_35 , V_111 -> V_246 >> 20 ) ;
#ifdef F_4
if ( V_5 )
F_6 ( L_36 ) ;
#endif
V_160 . V_3 = F_1 ( V_2 , V_160 . V_3 ) ;
F_9 ( L_37 , V_160 . V_3 ) ;
return 0 ;
}
static struct V_169 * F_211 ( struct V_181 * V_171 ,
struct V_48 * V_49 )
{
struct V_169 * V_170 = F_114 ( sizeof( * V_170 ) , V_86 ) ;
if ( V_170 == NULL )
return F_48 ( - V_87 ) ;
F_212 ( & V_170 -> V_247 ) ;
F_212 ( & V_170 -> V_248 ) ;
F_212 ( & V_170 -> V_249 ) ;
V_170 -> V_49 = V_49 ;
V_170 -> V_171 = V_171 ;
switch ( F_5 ( V_49 -> V_2 ) -> V_4 ) {
case 8 :
case 7 :
case 6 :
if ( F_143 ( V_49 ) ) {
V_170 -> V_250 = F_163 ;
V_170 -> V_184 = F_162 ;
} else {
V_170 -> V_250 = F_120 ;
V_170 -> V_184 = F_119 ;
}
break;
case 5 :
case 4 :
case 3 :
case 2 :
F_21 ( ! F_143 ( V_49 ) ) ;
V_170 -> V_250 = F_161 ;
V_170 -> V_184 = F_157 ;
break;
default:
F_104 () ;
}
if ( F_143 ( V_49 ) )
F_213 ( & V_170 -> V_247 , & V_171 -> V_251 ) ;
else {
F_214 ( & V_170 -> V_247 , & V_171 -> V_251 ) ;
F_215 ( F_216 ( V_49 ) ) ;
}
return V_170 ;
}
struct V_169 *
F_217 ( struct V_181 * V_171 ,
struct V_48 * V_49 )
{
struct V_169 * V_170 ;
V_170 = F_139 ( V_171 , V_49 ) ;
if ( ! V_170 )
V_170 = F_211 ( V_171 , V_49 ) ;
return V_170 ;
}
