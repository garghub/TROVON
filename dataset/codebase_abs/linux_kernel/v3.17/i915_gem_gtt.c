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
if ( F_8 ( V_2 ) && ! F_9 ( V_2 ) &&
V_2 -> V_8 -> V_9 < 0xb ) {
F_10 ( L_2 ) ;
return 0 ;
}
return F_3 ( V_2 ) ? 1 : 0 ;
}
static inline T_1 F_11 ( T_2 V_10 ,
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
static inline T_3 F_12 ( struct V_1 * V_2 ,
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
static T_4 F_13 ( T_2 V_10 ,
enum V_11 V_12 ,
bool V_13 , T_5 V_24 )
{
T_4 V_14 = V_13 ? V_25 : 0 ;
V_14 |= F_14 ( V_10 ) ;
switch ( V_12 ) {
case V_26 :
case V_27 :
V_14 |= V_28 ;
break;
case V_17 :
V_14 |= V_29 ;
break;
default:
F_15 ( 1 ) ;
}
return V_14 ;
}
static T_4 F_16 ( T_2 V_10 ,
enum V_11 V_12 ,
bool V_13 , T_5 V_24 )
{
T_4 V_14 = V_13 ? V_25 : 0 ;
V_14 |= F_14 ( V_10 ) ;
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
F_15 ( 1 ) ;
}
return V_14 ;
}
static T_4 F_17 ( T_2 V_10 ,
enum V_11 V_12 ,
bool V_13 , T_5 V_31 )
{
T_4 V_14 = V_13 ? V_25 : 0 ;
V_14 |= F_14 ( V_10 ) ;
if ( ! ( V_31 & V_32 ) )
V_14 |= V_33 ;
if ( V_12 != V_17 )
V_14 |= V_34 ;
return V_14 ;
}
static T_4 F_18 ( T_2 V_10 ,
enum V_11 V_12 ,
bool V_13 , T_5 V_24 )
{
T_4 V_14 = V_13 ? V_25 : 0 ;
V_14 |= F_19 ( V_10 ) ;
if ( V_12 != V_17 )
V_14 |= V_35 ;
return V_14 ;
}
static T_4 F_20 ( T_2 V_10 ,
enum V_11 V_12 ,
bool V_13 , T_5 V_24 )
{
T_4 V_14 = V_13 ? V_25 : 0 ;
V_14 |= F_19 ( V_10 ) ;
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
static int F_21 ( struct V_38 * V_39 , unsigned V_40 ,
T_6 V_41 , bool V_42 )
{
struct V_43 * V_44 = V_39 -> V_2 -> V_45 ;
int V_46 ;
F_22 ( V_40 >= 4 ) ;
if ( V_42 ) {
F_23 ( F_24 ( V_39 , V_40 ) , V_41 >> 32 ) ;
F_23 ( F_25 ( V_39 , V_40 ) , ( T_5 ) V_41 ) ;
return 0 ;
}
V_46 = F_26 ( V_39 , 6 ) ;
if ( V_46 )
return V_46 ;
F_27 ( V_39 , F_28 ( 1 ) ) ;
F_27 ( V_39 , F_24 ( V_39 , V_40 ) ) ;
F_27 ( V_39 , ( T_5 ) ( V_41 >> 32 ) ) ;
F_27 ( V_39 , F_28 ( 1 ) ) ;
F_27 ( V_39 , F_25 ( V_39 , V_40 ) ) ;
F_27 ( V_39 , ( T_5 ) ( V_41 ) ) ;
F_29 ( V_39 ) ;
return 0 ;
}
static int F_30 ( struct V_47 * V_48 ,
struct V_38 * V_39 ,
bool V_42 )
{
int V_49 , V_46 ;
int V_50 = V_48 -> V_51 / V_52 ;
for ( V_49 = V_50 - 1 ; V_49 >= 0 ; V_49 -- ) {
T_2 V_10 = V_48 -> V_53 [ V_49 ] ;
V_46 = F_21 ( V_39 , V_49 , V_10 , V_42 ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static void F_31 ( struct V_54 * V_55 ,
T_6 V_56 ,
T_6 V_57 ,
bool V_58 )
{
struct V_47 * V_48 =
F_32 ( V_55 , struct V_47 , V_59 ) ;
T_1 * V_60 , V_61 ;
unsigned V_62 = V_56 >> V_63 & V_64 ;
unsigned V_22 = V_56 >> V_65 & V_66 ;
unsigned V_14 = V_56 >> V_67 & V_68 ;
unsigned V_69 = V_57 >> V_70 ;
unsigned V_71 , V_49 ;
V_61 = F_11 ( V_48 -> V_59 . V_72 . V_10 ,
V_27 , V_58 ) ;
while ( V_69 ) {
struct V_73 * V_74 = V_48 -> V_75 [ V_62 ] [ V_22 ] ;
V_71 = V_14 + V_69 ;
if ( V_71 > V_76 )
V_71 = V_76 ;
V_60 = F_33 ( V_74 ) ;
for ( V_49 = V_14 ; V_49 < V_71 ; V_49 ++ ) {
V_60 [ V_49 ] = V_61 ;
V_69 -- ;
}
if ( ! F_34 ( V_48 -> V_59 . V_2 ) )
F_35 ( V_60 , V_77 ) ;
F_36 ( V_60 ) ;
V_14 = 0 ;
if ( ++ V_22 == V_52 ) {
V_62 ++ ;
V_22 = 0 ;
}
}
}
static void F_37 ( struct V_54 * V_55 ,
struct V_78 * V_79 ,
T_6 V_56 ,
enum V_11 V_80 , T_5 V_24 )
{
struct V_47 * V_48 =
F_32 ( V_55 , struct V_47 , V_59 ) ;
T_1 * V_60 ;
unsigned V_62 = V_56 >> V_63 & V_64 ;
unsigned V_22 = V_56 >> V_65 & V_66 ;
unsigned V_14 = V_56 >> V_67 & V_68 ;
struct V_81 V_82 ;
V_60 = NULL ;
F_38 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( F_15 ( V_62 >= V_83 ) )
break;
if ( V_60 == NULL )
V_60 = F_33 ( V_48 -> V_75 [ V_62 ] [ V_22 ] ) ;
V_60 [ V_14 ] =
F_11 ( F_39 ( & V_82 ) ,
V_80 , true ) ;
if ( ++ V_14 == V_76 ) {
if ( ! F_34 ( V_48 -> V_59 . V_2 ) )
F_35 ( V_60 , V_77 ) ;
F_36 ( V_60 ) ;
V_60 = NULL ;
if ( ++ V_22 == V_52 ) {
V_62 ++ ;
V_22 = 0 ;
}
V_14 = 0 ;
}
}
if ( V_60 ) {
if ( ! F_34 ( V_48 -> V_59 . V_2 ) )
F_35 ( V_60 , V_77 ) ;
F_36 ( V_60 ) ;
}
}
static void F_40 ( struct V_73 * * V_84 )
{
int V_49 ;
if ( V_84 == NULL )
return;
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ )
if ( V_84 [ V_49 ] )
F_41 ( V_84 [ V_49 ] , 0 ) ;
}
static void F_42 ( const struct V_47 * V_48 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_48 -> V_85 ; V_49 ++ ) {
F_40 ( V_48 -> V_75 [ V_49 ] ) ;
F_43 ( V_48 -> V_75 [ V_49 ] ) ;
F_43 ( V_48 -> V_86 [ V_49 ] ) ;
}
F_41 ( V_48 -> V_87 , F_44 ( V_48 -> V_85 << V_70 ) ) ;
}
static void F_45 ( struct V_47 * V_48 )
{
struct V_88 * V_89 = V_48 -> V_59 . V_2 -> V_8 ;
int V_49 , V_90 ;
for ( V_49 = 0 ; V_49 < V_48 -> V_85 ; V_49 ++ ) {
if ( ! V_48 -> V_53 [ V_49 ] )
continue;
F_46 ( V_89 , V_48 -> V_53 [ V_49 ] , V_77 ,
V_91 ) ;
for ( V_90 = 0 ; V_90 < V_52 ; V_90 ++ ) {
T_2 V_10 = V_48 -> V_86 [ V_49 ] [ V_90 ] ;
if ( V_10 )
F_46 ( V_89 , V_10 , V_77 ,
V_91 ) ;
}
}
}
static void F_47 ( struct V_54 * V_55 )
{
struct V_47 * V_48 =
F_32 ( V_55 , struct V_47 , V_59 ) ;
F_48 ( & V_55 -> V_92 ) ;
F_49 ( & V_55 -> V_93 ) ;
F_45 ( V_48 ) ;
F_42 ( V_48 ) ;
}
static struct V_73 * * F_50 ( void )
{
struct V_73 * * V_84 ;
int V_49 ;
V_84 = F_51 ( V_52 , sizeof( struct V_73 * ) , V_94 ) ;
if ( ! V_84 )
return F_52 ( - V_95 ) ;
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ ) {
V_84 [ V_49 ] = F_53 ( V_94 ) ;
if ( ! V_84 [ V_49 ] )
goto V_96;
}
return V_84 ;
V_96:
F_40 ( V_84 ) ;
F_43 ( V_84 ) ;
return F_52 ( - V_95 ) ;
}
static int F_54 ( struct V_47 * V_48 ,
const int V_97 )
{
struct V_73 * * V_84 [ V_83 ] ;
int V_49 , V_46 ;
for ( V_49 = 0 ; V_49 < V_97 ; V_49 ++ ) {
V_84 [ V_49 ] = F_50 () ;
if ( F_55 ( V_84 [ V_49 ] ) ) {
V_46 = F_56 ( V_84 [ V_49 ] ) ;
goto V_98;
}
}
for ( V_49 = 0 ; V_49 < V_97 ; V_49 ++ )
V_48 -> V_75 [ V_49 ] = V_84 [ V_49 ] ;
return 0 ;
V_98:
while ( V_49 -- ) {
F_40 ( V_84 [ V_49 ] ) ;
F_43 ( V_84 [ V_49 ] ) ;
}
return V_46 ;
}
static int F_57 ( struct V_47 * V_48 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_48 -> V_85 ; V_49 ++ ) {
V_48 -> V_86 [ V_49 ] = F_51 ( V_52 ,
sizeof( T_2 ) ,
V_94 ) ;
if ( ! V_48 -> V_86 [ V_49 ] )
return - V_95 ;
}
return 0 ;
}
static int F_58 ( struct V_47 * V_48 ,
const int V_97 )
{
V_48 -> V_87 = F_59 ( V_94 , F_44 ( V_97 << V_70 ) ) ;
if ( ! V_48 -> V_87 )
return - V_95 ;
V_48 -> V_85 = 1 << F_44 ( V_97 << V_70 ) ;
F_22 ( V_48 -> V_85 > V_83 ) ;
return 0 ;
}
static int F_60 ( struct V_47 * V_48 ,
const int V_97 )
{
int V_46 ;
V_46 = F_58 ( V_48 , V_97 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_54 ( V_48 , V_97 ) ;
if ( V_46 ) {
F_41 ( V_48 -> V_87 , F_44 ( V_97 << V_70 ) ) ;
return V_46 ;
}
V_48 -> V_51 = V_97 * V_52 ;
V_46 = F_57 ( V_48 ) ;
if ( V_46 )
F_42 ( V_48 ) ;
return V_46 ;
}
static int F_61 ( struct V_47 * V_48 ,
const int V_99 )
{
T_2 V_100 ;
int V_46 ;
V_100 = F_62 ( V_48 -> V_59 . V_2 -> V_8 ,
& V_48 -> V_87 [ V_99 ] , 0 ,
V_77 , V_91 ) ;
V_46 = F_63 ( V_48 -> V_59 . V_2 -> V_8 , V_100 ) ;
if ( V_46 )
return V_46 ;
V_48 -> V_53 [ V_99 ] = V_100 ;
return 0 ;
}
static int F_64 ( struct V_47 * V_48 ,
const int V_99 ,
const int V_101 )
{
T_2 V_102 ;
struct V_73 * V_103 ;
int V_46 ;
V_103 = V_48 -> V_75 [ V_99 ] [ V_101 ] ;
V_102 = F_62 ( V_48 -> V_59 . V_2 -> V_8 ,
V_103 , 0 , V_77 , V_91 ) ;
V_46 = F_63 ( V_48 -> V_59 . V_2 -> V_8 , V_102 ) ;
if ( V_46 )
return V_46 ;
V_48 -> V_86 [ V_99 ] [ V_101 ] = V_102 ;
return 0 ;
}
static int F_65 ( struct V_47 * V_48 , T_6 V_104 )
{
const int V_97 = F_66 ( V_104 , 1 << 30 ) ;
const int V_105 = V_52 * V_97 ;
int V_49 , V_90 , V_46 ;
if ( V_104 % ( 1 << 30 ) )
F_7 ( L_3 , V_104 ) ;
V_46 = F_60 ( V_48 , V_97 ) ;
if ( V_46 )
return V_46 ;
for ( V_49 = 0 ; V_49 < V_97 ; V_49 ++ ) {
V_46 = F_61 ( V_48 , V_49 ) ;
if ( V_46 )
goto V_96;
for ( V_90 = 0 ; V_90 < V_52 ; V_90 ++ ) {
V_46 = F_64 ( V_48 , V_49 , V_90 ) ;
if ( V_46 )
goto V_96;
}
}
for ( V_49 = 0 ; V_49 < V_97 ; V_49 ++ ) {
T_3 * V_106 ;
V_106 = F_33 ( & V_48 -> V_87 [ V_49 ] ) ;
for ( V_90 = 0 ; V_90 < V_52 ; V_90 ++ ) {
T_2 V_10 = V_48 -> V_86 [ V_49 ] [ V_90 ] ;
V_106 [ V_90 ] = F_12 ( V_48 -> V_59 . V_2 , V_10 ,
V_27 ) ;
}
if ( ! F_34 ( V_48 -> V_59 . V_2 ) )
F_35 ( V_106 , V_77 ) ;
F_36 ( V_106 ) ;
}
V_48 -> V_107 = V_108 ;
V_48 -> V_109 = F_30 ;
V_48 -> V_59 . V_110 = F_31 ;
V_48 -> V_59 . V_111 = F_37 ;
V_48 -> V_59 . V_112 = F_47 ;
V_48 -> V_59 . V_56 = 0 ;
V_48 -> V_59 . V_113 = V_48 -> V_51 * V_76 * V_77 ;
V_48 -> V_59 . V_110 ( & V_48 -> V_59 , 0 , V_48 -> V_59 . V_113 , true ) ;
F_10 ( L_4 ,
V_48 -> V_85 , V_48 -> V_85 - V_97 ) ;
F_10 ( L_5 ,
V_48 -> V_51 ,
( V_48 -> V_51 - V_105 ) + V_104 % ( 1 << 30 ) ) ;
return 0 ;
V_96:
F_45 ( V_48 ) ;
F_42 ( V_48 ) ;
return V_46 ;
}
static void F_67 ( struct V_47 * V_48 , struct V_114 * V_115 )
{
struct V_43 * V_44 = V_48 -> V_59 . V_2 -> V_45 ;
struct V_54 * V_55 = & V_48 -> V_59 ;
T_4 T_7 * V_100 ;
T_4 V_61 ;
T_8 V_116 ;
int V_14 , V_22 ;
V_61 = V_55 -> V_117 ( V_55 -> V_72 . V_10 , V_27 , true , 0 ) ;
V_100 = ( T_4 T_7 * ) V_44 -> V_118 . V_119 +
V_48 -> V_120 / sizeof( T_4 ) ;
F_68 ( V_115 , L_6 , V_55 ,
V_48 -> V_120 , V_48 -> V_120 + V_48 -> V_51 ) ;
for ( V_22 = 0 ; V_22 < V_48 -> V_51 ; V_22 ++ ) {
T_5 V_121 ;
T_4 * V_60 ;
T_2 V_102 = V_48 -> V_122 [ V_22 ] ;
V_116 = F_69 ( V_100 + V_22 ) ;
V_121 = ( F_70 ( V_102 ) | V_123 ) ;
if ( V_116 != V_121 )
F_68 ( V_115 , L_7 ,
V_22 ,
V_116 ,
V_121 ) ;
F_68 ( V_115 , L_8 , V_116 ) ;
V_60 = F_33 ( V_48 -> V_84 [ V_22 ] ) ;
for ( V_14 = 0 ; V_14 < V_124 ; V_14 += 4 ) {
unsigned long V_125 =
( V_22 * V_77 * V_124 ) +
( V_14 * V_77 ) ;
int V_49 ;
bool V_126 = false ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ )
if ( V_60 [ V_14 + V_49 ] != V_61 )
V_126 = true ;
if ( ! V_126 )
continue;
F_68 ( V_115 , L_9 , V_125 , V_22 , V_14 ) ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
if ( V_60 [ V_14 + V_49 ] != V_61 )
F_68 ( V_115 , L_10 , V_60 [ V_14 + V_49 ] ) ;
else
F_71 ( V_115 , L_11 ) ;
}
F_71 ( V_115 , L_12 ) ;
}
F_36 ( V_60 ) ;
}
}
static void F_72 ( struct V_47 * V_48 )
{
struct V_43 * V_44 = V_48 -> V_59 . V_2 -> V_45 ;
T_4 T_7 * V_100 ;
T_8 V_116 ;
int V_49 ;
F_15 ( V_48 -> V_120 & 0x3f ) ;
V_100 = ( T_4 T_7 * ) V_44 -> V_118 . V_119 +
V_48 -> V_120 / sizeof( T_4 ) ;
for ( V_49 = 0 ; V_49 < V_48 -> V_51 ; V_49 ++ ) {
T_2 V_102 ;
V_102 = V_48 -> V_122 [ V_49 ] ;
V_116 = F_70 ( V_102 ) ;
V_116 |= V_123 ;
F_73 ( V_116 , V_100 + V_49 ) ;
}
F_69 ( V_100 ) ;
}
static T_8 F_74 ( struct V_47 * V_48 )
{
F_22 ( V_48 -> V_120 & 0x3f ) ;
return ( V_48 -> V_120 / 64 ) << 16 ;
}
static int F_75 ( struct V_47 * V_48 ,
struct V_38 * V_39 ,
bool V_42 )
{
struct V_1 * V_2 = V_48 -> V_59 . V_2 ;
struct V_43 * V_44 = V_2 -> V_45 ;
int V_46 ;
if ( V_42 ||
F_76 ( & V_44 -> V_127 ) ) {
F_15 ( V_48 != V_44 -> V_93 . V_128 ) ;
F_23 ( F_77 ( V_39 ) , V_129 ) ;
F_23 ( F_78 ( V_39 ) , F_74 ( V_48 ) ) ;
F_79 ( F_78 ( V_39 ) ) ;
return 0 ;
}
V_46 = V_39 -> V_130 ( V_39 , V_131 , V_131 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_26 ( V_39 , 6 ) ;
if ( V_46 )
return V_46 ;
F_27 ( V_39 , F_28 ( 2 ) ) ;
F_27 ( V_39 , F_77 ( V_39 ) ) ;
F_27 ( V_39 , V_129 ) ;
F_27 ( V_39 , F_78 ( V_39 ) ) ;
F_27 ( V_39 , F_74 ( V_48 ) ) ;
F_27 ( V_39 , V_132 ) ;
F_29 ( V_39 ) ;
return 0 ;
}
static int F_80 ( struct V_47 * V_48 ,
struct V_38 * V_39 ,
bool V_42 )
{
struct V_1 * V_2 = V_48 -> V_59 . V_2 ;
struct V_43 * V_44 = V_2 -> V_45 ;
int V_46 ;
if ( V_42 ||
F_76 ( & V_44 -> V_127 ) ) {
F_15 ( V_48 != V_44 -> V_93 . V_128 ) ;
F_23 ( F_77 ( V_39 ) , V_129 ) ;
F_23 ( F_78 ( V_39 ) , F_74 ( V_48 ) ) ;
F_79 ( F_78 ( V_39 ) ) ;
return 0 ;
}
V_46 = V_39 -> V_130 ( V_39 , V_131 , V_131 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_26 ( V_39 , 6 ) ;
if ( V_46 )
return V_46 ;
F_27 ( V_39 , F_28 ( 2 ) ) ;
F_27 ( V_39 , F_77 ( V_39 ) ) ;
F_27 ( V_39 , V_129 ) ;
F_27 ( V_39 , F_78 ( V_39 ) ) ;
F_27 ( V_39 , F_74 ( V_48 ) ) ;
F_27 ( V_39 , V_132 ) ;
F_29 ( V_39 ) ;
if ( V_39 -> V_133 != V_134 ) {
V_46 = V_39 -> V_130 ( V_39 , V_131 , V_131 ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static int F_81 ( struct V_47 * V_48 ,
struct V_38 * V_39 ,
bool V_42 )
{
struct V_1 * V_2 = V_48 -> V_59 . V_2 ;
struct V_43 * V_44 = V_2 -> V_45 ;
if ( ! V_42 )
return 0 ;
F_23 ( F_77 ( V_39 ) , V_129 ) ;
F_23 ( F_78 ( V_39 ) , F_74 ( V_48 ) ) ;
F_79 ( F_77 ( V_39 ) ) ;
return 0 ;
}
static int V_108 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_59 . V_2 ;
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_38 * V_39 ;
int V_90 , V_46 ;
F_82 (ring, dev_priv, j) {
F_23 ( F_83 ( V_39 ) ,
F_84 ( V_135 ) ) ;
if ( F_85 ( V_2 ) )
continue;
V_46 = V_48 -> V_109 ( V_48 , V_39 , true ) ;
if ( V_46 )
goto V_136;
}
return 0 ;
V_136:
F_82 (ring, dev_priv, j)
F_23 ( F_83 ( V_39 ) ,
F_86 ( V_135 ) ) ;
return V_46 ;
}
static int F_87 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_59 . V_2 ;
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_38 * V_39 ;
T_8 V_137 , V_138 ;
int V_49 ;
V_138 = F_88 ( V_139 ) ;
F_23 ( V_139 , V_138 | V_140 ) ;
V_137 = F_88 ( V_141 ) ;
if ( F_89 ( V_2 ) ) {
V_137 |= V_142 ;
} else {
V_137 |= V_143 ;
V_137 &= ~ V_144 ;
}
F_23 ( V_141 , V_137 ) ;
F_82 (ring, dev_priv, i) {
int V_46 ;
F_23 ( F_83 ( V_39 ) ,
F_84 ( V_135 ) ) ;
if ( F_85 ( V_2 ) )
continue;
V_46 = V_48 -> V_109 ( V_48 , V_39 , true ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static int F_90 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_59 . V_2 ;
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_38 * V_39 ;
T_8 V_137 , V_145 , V_138 ;
int V_49 ;
V_138 = F_88 ( V_139 ) ;
F_23 ( V_139 , V_138 | V_146 |
V_140 ) ;
V_145 = F_88 ( V_147 ) ;
F_23 ( V_147 , V_145 | V_148 ) ;
V_137 = F_88 ( V_141 ) ;
F_23 ( V_141 , V_137 | V_149 | V_150 ) ;
F_23 ( V_151 , F_84 ( V_135 ) ) ;
F_82 (ring, dev_priv, i) {
int V_46 = V_48 -> V_109 ( V_48 , V_39 , true ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static void F_91 ( struct V_54 * V_55 ,
T_6 V_56 ,
T_6 V_57 ,
bool V_58 )
{
struct V_47 * V_48 =
F_32 ( V_55 , struct V_47 , V_59 ) ;
T_4 * V_60 , V_61 ;
unsigned V_152 = V_56 >> V_70 ;
unsigned V_69 = V_57 >> V_70 ;
unsigned V_153 = V_152 / V_124 ;
unsigned V_154 = V_152 % V_124 ;
unsigned V_71 , V_49 ;
V_61 = V_55 -> V_117 ( V_55 -> V_72 . V_10 , V_27 , true , 0 ) ;
while ( V_69 ) {
V_71 = V_154 + V_69 ;
if ( V_71 > V_124 )
V_71 = V_124 ;
V_60 = F_33 ( V_48 -> V_84 [ V_153 ] ) ;
for ( V_49 = V_154 ; V_49 < V_71 ; V_49 ++ )
V_60 [ V_49 ] = V_61 ;
F_36 ( V_60 ) ;
V_69 -= V_71 - V_154 ;
V_154 = 0 ;
V_153 ++ ;
}
}
static void F_92 ( struct V_54 * V_55 ,
struct V_78 * V_79 ,
T_6 V_56 ,
enum V_11 V_80 , T_5 V_31 )
{
struct V_47 * V_48 =
F_32 ( V_55 , struct V_47 , V_59 ) ;
T_4 * V_60 ;
unsigned V_152 = V_56 >> V_70 ;
unsigned V_153 = V_152 / V_124 ;
unsigned V_155 = V_152 % V_124 ;
struct V_81 V_82 ;
V_60 = NULL ;
F_38 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_60 == NULL )
V_60 = F_33 ( V_48 -> V_84 [ V_153 ] ) ;
V_60 [ V_155 ] =
V_55 -> V_117 ( F_39 ( & V_82 ) ,
V_80 , true , V_31 ) ;
if ( ++ V_155 == V_124 ) {
F_36 ( V_60 ) ;
V_60 = NULL ;
V_153 ++ ;
V_155 = 0 ;
}
}
if ( V_60 )
F_36 ( V_60 ) ;
}
static void F_93 ( struct V_47 * V_48 )
{
int V_49 ;
if ( V_48 -> V_122 ) {
for ( V_49 = 0 ; V_49 < V_48 -> V_51 ; V_49 ++ )
F_46 ( V_48 -> V_59 . V_2 -> V_8 ,
V_48 -> V_122 [ V_49 ] ,
4096 , V_91 ) ;
}
}
static void F_94 ( struct V_47 * V_48 )
{
int V_49 ;
F_43 ( V_48 -> V_122 ) ;
for ( V_49 = 0 ; V_49 < V_48 -> V_51 ; V_49 ++ )
F_95 ( V_48 -> V_84 [ V_49 ] ) ;
F_43 ( V_48 -> V_84 ) ;
}
static void F_96 ( struct V_54 * V_55 )
{
struct V_47 * V_48 =
F_32 ( V_55 , struct V_47 , V_59 ) ;
F_48 ( & V_55 -> V_92 ) ;
F_49 ( & V_48 -> V_59 . V_93 ) ;
F_97 ( & V_48 -> V_156 ) ;
F_93 ( V_48 ) ;
F_94 ( V_48 ) ;
}
static int F_98 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_59 . V_2 ;
struct V_43 * V_44 = V_2 -> V_45 ;
bool V_157 = false ;
int V_46 ;
F_22 ( ! F_99 ( & V_44 -> V_118 . V_59 . V_93 ) ) ;
V_158:
V_46 = F_100 ( & V_44 -> V_118 . V_59 . V_93 ,
& V_48 -> V_156 , V_159 ,
V_160 , 0 ,
0 , V_44 -> V_118 . V_59 . V_113 ,
V_161 ) ;
if ( V_46 == - V_162 && ! V_157 ) {
V_46 = F_101 ( V_2 , & V_44 -> V_118 . V_59 ,
V_159 , V_160 ,
V_17 ,
0 , V_44 -> V_118 . V_59 . V_113 ,
0 ) ;
if ( V_46 )
return V_46 ;
V_157 = true ;
goto V_158;
}
if ( V_48 -> V_156 . V_56 < V_44 -> V_118 . V_163 )
F_102 ( L_13 ) ;
V_48 -> V_51 = V_164 ;
return V_46 ;
}
static int F_103 ( struct V_47 * V_48 )
{
int V_49 ;
V_48 -> V_84 = F_51 ( V_48 -> V_51 , sizeof( struct V_73 * ) ,
V_94 ) ;
if ( ! V_48 -> V_84 )
return - V_95 ;
for ( V_49 = 0 ; V_49 < V_48 -> V_51 ; V_49 ++ ) {
V_48 -> V_84 [ V_49 ] = F_53 ( V_94 ) ;
if ( ! V_48 -> V_84 [ V_49 ] ) {
F_94 ( V_48 ) ;
return - V_95 ;
}
}
return 0 ;
}
static int F_104 ( struct V_47 * V_48 )
{
int V_46 ;
V_46 = F_98 ( V_48 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_103 ( V_48 ) ;
if ( V_46 ) {
F_97 ( & V_48 -> V_156 ) ;
return V_46 ;
}
V_48 -> V_122 = F_51 ( V_48 -> V_51 , sizeof( T_2 ) ,
V_94 ) ;
if ( ! V_48 -> V_122 ) {
F_97 ( & V_48 -> V_156 ) ;
F_94 ( V_48 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_105 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_59 . V_2 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_48 -> V_51 ; V_49 ++ ) {
T_2 V_102 ;
V_102 = F_62 ( V_2 -> V_8 , V_48 -> V_84 [ V_49 ] , 0 , 4096 ,
V_91 ) ;
if ( F_63 ( V_2 -> V_8 , V_102 ) ) {
F_93 ( V_48 ) ;
return - V_165 ;
}
V_48 -> V_122 [ V_49 ] = V_102 ;
}
return 0 ;
}
static int F_106 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_59 . V_2 ;
struct V_43 * V_44 = V_2 -> V_45 ;
int V_46 ;
V_48 -> V_59 . V_117 = V_44 -> V_118 . V_59 . V_117 ;
if ( F_107 ( V_2 ) ) {
V_48 -> V_107 = F_90 ;
V_48 -> V_109 = F_81 ;
} else if ( F_89 ( V_2 ) ) {
V_48 -> V_107 = F_87 ;
V_48 -> V_109 = F_75 ;
} else if ( F_108 ( V_2 ) ) {
V_48 -> V_107 = F_87 ;
V_48 -> V_109 = F_80 ;
} else
F_109 () ;
V_46 = F_104 ( V_48 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_105 ( V_48 ) ;
if ( V_46 ) {
F_94 ( V_48 ) ;
return V_46 ;
}
V_48 -> V_59 . V_110 = F_91 ;
V_48 -> V_59 . V_111 = F_92 ;
V_48 -> V_59 . V_112 = F_96 ;
V_48 -> V_59 . V_56 = 0 ;
V_48 -> V_59 . V_113 = V_48 -> V_51 * V_124 * V_77 ;
V_48 -> V_166 = F_67 ;
V_48 -> V_120 =
V_48 -> V_156 . V_56 / V_77 * sizeof( T_4 ) ;
V_48 -> V_59 . V_110 ( & V_48 -> V_59 , 0 , V_48 -> V_59 . V_113 , true ) ;
F_10 ( L_14 ,
V_48 -> V_156 . V_104 >> 20 ,
V_48 -> V_156 . V_56 / V_77 ) ;
return 0 ;
}
int F_110 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
int V_46 = 0 ;
V_48 -> V_59 . V_2 = V_2 ;
V_48 -> V_59 . V_72 = V_44 -> V_118 . V_59 . V_72 ;
if ( F_6 ( V_2 ) -> V_6 < 8 )
V_46 = F_106 ( V_48 ) ;
else if ( F_111 ( V_2 ) )
V_46 = F_65 ( V_48 , V_44 -> V_118 . V_59 . V_113 ) ;
else
F_109 () ;
if ( ! V_46 ) {
struct V_43 * V_44 = V_2 -> V_45 ;
F_112 ( & V_48 -> V_167 ) ;
F_113 ( & V_48 -> V_59 . V_93 , V_48 -> V_59 . V_56 ,
V_48 -> V_59 . V_113 ) ;
F_114 ( V_44 , & V_48 -> V_59 ) ;
if ( F_6 ( V_2 ) -> V_6 < 8 ) {
F_72 ( V_48 ) ;
F_102 ( L_15 ,
V_48 -> V_120 << 10 ) ;
}
}
return V_46 ;
}
static void
F_115 ( struct V_168 * V_169 ,
enum V_11 V_80 ,
T_5 V_31 )
{
if ( V_169 -> V_170 -> V_171 )
V_31 |= V_32 ;
V_169 -> V_55 -> V_111 ( V_169 -> V_55 , V_169 -> V_170 -> V_79 , V_169 -> V_156 . V_56 ,
V_80 , V_31 ) ;
}
static void F_116 ( struct V_168 * V_169 )
{
V_169 -> V_55 -> V_110 ( V_169 -> V_55 ,
V_169 -> V_156 . V_56 ,
V_169 -> V_170 -> V_59 . V_104 ,
true ) ;
}
static inline bool F_117 ( struct V_1 * V_2 )
{
#ifdef F_5
if ( F_118 ( V_2 ) && F_119 ( V_2 ) && V_7 )
return true ;
#endif
return false ;
}
static bool F_120 ( struct V_43 * V_44 )
{
bool V_46 = V_44 -> V_93 . V_172 ;
if ( F_121 ( V_44 -> V_118 . V_173 ) ) {
V_44 -> V_93 . V_172 = false ;
if ( F_122 ( V_44 -> V_2 ) ) {
F_123 ( L_16 ) ;
F_124 ( 10 ) ;
}
}
return V_46 ;
}
static void F_125 ( struct V_43 * V_44 , bool V_172 )
{
if ( F_121 ( V_44 -> V_118 . V_173 ) )
V_44 -> V_93 . V_172 = V_172 ;
}
void F_126 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_38 * V_39 ;
int V_49 ;
if ( F_6 ( V_2 ) -> V_6 < 6 )
return;
F_82 (ring, dev_priv, i) {
T_5 V_174 ;
V_174 = F_88 ( F_127 ( V_39 ) ) ;
if ( V_174 & V_175 ) {
F_10 ( L_17
L_18
L_19
L_20
L_21 ,
V_174 & V_176 ,
V_174 & V_177 ? L_22 : L_23 ,
F_128 ( V_174 ) ,
F_129 ( V_174 ) ) ;
F_23 ( F_127 ( V_39 ) ,
V_174 & ~ V_175 ) ;
}
}
F_79 ( F_127 ( & V_44 -> V_39 [ V_134 ] ) ) ;
}
static void F_130 ( struct V_43 * V_44 )
{
if ( F_6 ( V_44 -> V_2 ) -> V_6 < 6 ) {
F_131 () ;
} else {
F_23 ( V_178 , V_179 ) ;
F_79 ( V_178 ) ;
}
}
void F_132 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
if ( F_6 ( V_2 ) -> V_6 < 6 )
return;
F_126 ( V_2 ) ;
V_44 -> V_118 . V_59 . V_110 ( & V_44 -> V_118 . V_59 ,
V_44 -> V_118 . V_59 . V_56 ,
V_44 -> V_118 . V_59 . V_113 ,
true ) ;
F_130 ( V_44 ) ;
}
void F_133 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_180 * V_170 ;
struct V_54 * V_55 ;
F_126 ( V_2 ) ;
V_44 -> V_118 . V_59 . V_110 ( & V_44 -> V_118 . V_59 ,
V_44 -> V_118 . V_59 . V_56 ,
V_44 -> V_118 . V_59 . V_113 ,
true ) ;
F_134 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_168 * V_169 = F_135 ( V_170 ,
& V_44 -> V_118 . V_59 ) ;
if ( ! V_169 )
continue;
F_136 ( V_170 , V_170 -> V_181 ) ;
V_170 -> V_182 = 0 ;
V_169 -> V_183 ( V_169 , V_170 -> V_80 , V_184 ) ;
}
if ( F_6 ( V_2 ) -> V_6 >= 8 ) {
if ( F_9 ( V_2 ) )
F_137 ( V_44 ) ;
else
F_138 ( V_44 ) ;
return;
}
F_134 (vm, &dev_priv->vm_list, global_link) {
if ( F_139 ( V_55 ) ) {
if ( V_44 -> V_93 . V_128 )
F_72 ( V_44 -> V_93 . V_128 ) ;
continue;
}
F_72 ( F_32 ( V_55 , struct V_47 , V_59 ) ) ;
}
F_130 ( V_44 ) ;
}
int F_140 ( struct V_180 * V_170 )
{
if ( V_170 -> V_185 )
return 0 ;
if ( ! F_141 ( & V_170 -> V_59 . V_2 -> V_8 -> V_2 ,
V_170 -> V_79 -> V_186 , V_170 -> V_79 -> V_187 ,
V_91 ) )
return - V_162 ;
return 0 ;
}
static inline void F_142 ( void T_7 * V_10 , T_1 V_14 )
{
#ifdef F_143
F_143 ( V_14 , V_10 ) ;
#else
F_144 ( ( T_5 ) V_14 , V_10 ) ;
F_144 ( V_14 >> 32 , V_10 + 4 ) ;
#endif
}
static void F_145 ( struct V_54 * V_55 ,
struct V_78 * V_188 ,
T_6 V_56 ,
enum V_11 V_12 , T_5 V_24 )
{
struct V_43 * V_44 = V_55 -> V_2 -> V_45 ;
unsigned V_152 = V_56 >> V_70 ;
T_1 T_7 * V_189 =
( T_1 T_7 * ) V_44 -> V_118 . V_119 + V_152 ;
int V_49 = 0 ;
struct V_81 V_82 ;
T_2 V_10 = 0 ;
F_38 (st->sgl, &sg_iter, st->nents, 0 ) {
V_10 = F_146 ( V_82 . V_190 ) +
( V_82 . V_191 << V_70 ) ;
F_142 ( & V_189 [ V_49 ] ,
F_11 ( V_10 , V_12 , true ) ) ;
V_49 ++ ;
}
if ( V_49 != 0 )
F_15 ( F_147 ( & V_189 [ V_49 - 1 ] )
!= F_11 ( V_10 , V_12 , true ) ) ;
F_23 ( V_178 , V_179 ) ;
F_79 ( V_178 ) ;
}
static void F_148 ( struct V_54 * V_55 ,
struct V_78 * V_188 ,
T_6 V_56 ,
enum V_11 V_12 , T_5 V_31 )
{
struct V_43 * V_44 = V_55 -> V_2 -> V_45 ;
unsigned V_152 = V_56 >> V_70 ;
T_4 T_7 * V_189 =
( T_4 T_7 * ) V_44 -> V_118 . V_119 + V_152 ;
int V_49 = 0 ;
struct V_81 V_82 ;
T_2 V_10 = 0 ;
F_38 (st->sgl, &sg_iter, st->nents, 0 ) {
V_10 = F_39 ( & V_82 ) ;
F_144 ( V_55 -> V_117 ( V_10 , V_12 , true , V_31 ) , & V_189 [ V_49 ] ) ;
V_49 ++ ;
}
if ( V_49 != 0 ) {
unsigned long V_118 = F_69 ( & V_189 [ V_49 - 1 ] ) ;
F_15 ( V_118 != V_55 -> V_117 ( V_10 , V_12 , true , V_31 ) ) ;
}
F_23 ( V_178 , V_179 ) ;
F_79 ( V_178 ) ;
}
static void F_149 ( struct V_54 * V_55 ,
T_6 V_56 ,
T_6 V_57 ,
bool V_58 )
{
struct V_43 * V_44 = V_55 -> V_2 -> V_45 ;
unsigned V_152 = V_56 >> V_70 ;
unsigned V_69 = V_57 >> V_70 ;
T_1 V_61 , T_7 * V_192 =
( T_1 T_7 * ) V_44 -> V_118 . V_119 + V_152 ;
const int V_193 = F_150 ( V_44 -> V_118 ) - V_152 ;
int V_49 ;
if ( F_151 ( V_69 > V_193 ,
L_24 ,
V_152 , V_69 , V_193 ) )
V_69 = V_193 ;
V_61 = F_11 ( V_55 -> V_72 . V_10 ,
V_27 ,
V_58 ) ;
for ( V_49 = 0 ; V_49 < V_69 ; V_49 ++ )
F_142 ( & V_192 [ V_49 ] , V_61 ) ;
F_69 ( V_192 ) ;
}
static void F_152 ( struct V_54 * V_55 ,
T_6 V_56 ,
T_6 V_57 ,
bool V_58 )
{
struct V_43 * V_44 = V_55 -> V_2 -> V_45 ;
unsigned V_152 = V_56 >> V_70 ;
unsigned V_69 = V_57 >> V_70 ;
T_4 V_61 , T_7 * V_192 =
( T_4 T_7 * ) V_44 -> V_118 . V_119 + V_152 ;
const int V_193 = F_150 ( V_44 -> V_118 ) - V_152 ;
int V_49 ;
if ( F_151 ( V_69 > V_193 ,
L_24 ,
V_152 , V_69 , V_193 ) )
V_69 = V_193 ;
V_61 = V_55 -> V_117 ( V_55 -> V_72 . V_10 , V_27 , V_58 , 0 ) ;
for ( V_49 = 0 ; V_49 < V_69 ; V_49 ++ )
F_144 ( V_61 , & V_192 [ V_49 ] ) ;
F_69 ( V_192 ) ;
}
static void F_153 ( struct V_168 * V_169 ,
enum V_11 V_80 ,
T_5 V_24 )
{
const unsigned long V_40 = V_169 -> V_156 . V_56 >> V_70 ;
unsigned int V_31 = ( V_80 == V_17 ) ?
V_194 : V_195 ;
F_22 ( ! F_139 ( V_169 -> V_55 ) ) ;
F_154 ( V_169 -> V_170 -> V_79 , V_40 , V_31 ) ;
V_169 -> V_170 -> V_182 = 1 ;
}
static void F_155 ( struct V_54 * V_55 ,
T_6 V_56 ,
T_6 V_57 ,
bool V_24 )
{
unsigned V_152 = V_56 >> V_70 ;
unsigned V_69 = V_57 >> V_70 ;
F_156 ( V_152 , V_69 ) ;
}
static void F_157 ( struct V_168 * V_169 )
{
const unsigned int V_196 = V_169 -> V_156 . V_56 >> V_70 ;
const unsigned int V_104 = V_169 -> V_170 -> V_59 . V_104 >> V_70 ;
F_22 ( ! F_139 ( V_169 -> V_55 ) ) ;
V_169 -> V_170 -> V_182 = 0 ;
F_156 ( V_196 , V_104 ) ;
}
static void F_158 ( struct V_168 * V_169 ,
enum V_11 V_80 ,
T_5 V_31 )
{
struct V_1 * V_2 = V_169 -> V_55 -> V_2 ;
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_180 * V_170 = V_169 -> V_170 ;
if ( V_170 -> V_171 )
V_31 |= V_32 ;
if ( ! V_44 -> V_93 . V_128 || V_31 & V_184 ) {
if ( ! V_170 -> V_182 ||
( V_80 != V_170 -> V_80 ) ) {
V_169 -> V_55 -> V_111 ( V_169 -> V_55 , V_170 -> V_79 ,
V_169 -> V_156 . V_56 ,
V_80 , V_31 ) ;
V_170 -> V_182 = 1 ;
}
}
if ( V_44 -> V_93 . V_128 &&
( ! V_170 -> V_197 ||
( V_80 != V_170 -> V_80 ) ) ) {
struct V_47 * V_198 = V_44 -> V_93 . V_128 ;
V_198 -> V_59 . V_111 ( & V_198 -> V_59 ,
V_169 -> V_170 -> V_79 ,
V_169 -> V_156 . V_56 ,
V_80 , V_31 ) ;
V_169 -> V_170 -> V_197 = 1 ;
}
}
static void F_159 ( struct V_168 * V_169 )
{
struct V_1 * V_2 = V_169 -> V_55 -> V_2 ;
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_180 * V_170 = V_169 -> V_170 ;
if ( V_170 -> V_182 ) {
V_169 -> V_55 -> V_110 ( V_169 -> V_55 ,
V_169 -> V_156 . V_56 ,
V_170 -> V_59 . V_104 ,
true ) ;
V_170 -> V_182 = 0 ;
}
if ( V_170 -> V_197 ) {
struct V_47 * V_198 = V_44 -> V_93 . V_128 ;
V_198 -> V_59 . V_110 ( & V_198 -> V_59 ,
V_169 -> V_156 . V_56 ,
V_170 -> V_59 . V_104 ,
true ) ;
V_170 -> V_197 = 0 ;
}
}
void F_160 ( struct V_180 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_59 . V_2 ;
struct V_43 * V_44 = V_2 -> V_45 ;
bool V_172 ;
V_172 = F_120 ( V_44 ) ;
if ( ! V_170 -> V_185 )
F_161 ( & V_2 -> V_8 -> V_2 ,
V_170 -> V_79 -> V_186 , V_170 -> V_79 -> V_187 ,
V_91 ) ;
F_125 ( V_44 , V_172 ) ;
}
static void F_162 ( struct V_199 * V_156 ,
unsigned long V_200 ,
unsigned long * V_56 ,
unsigned long * V_201 )
{
if ( V_156 -> V_200 != V_200 )
* V_56 += 4096 ;
if ( ! F_163 ( & V_156 -> V_202 ) ) {
V_156 = F_164 ( V_156 -> V_202 . V_203 ,
struct V_199 ,
V_202 ) ;
if ( V_156 -> V_204 && V_156 -> V_200 != V_200 )
* V_201 -= 4096 ;
}
}
void F_165 ( struct V_1 * V_2 ,
unsigned long V_56 ,
unsigned long V_163 ,
unsigned long V_201 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_54 * V_205 = & V_44 -> V_118 . V_59 ;
struct V_199 * V_40 ;
struct V_180 * V_170 ;
unsigned long V_206 , V_207 ;
F_22 ( V_163 > V_201 ) ;
F_113 ( & V_205 -> V_93 , V_56 , V_201 - V_56 - V_77 ) ;
if ( ! F_34 ( V_2 ) )
V_44 -> V_118 . V_59 . V_93 . V_208 = F_162 ;
F_134 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_168 * V_169 = F_135 ( V_170 , V_205 ) ;
int V_46 ;
F_166 ( L_25 ,
F_167 ( V_170 ) , V_170 -> V_59 . V_104 ) ;
F_15 ( F_168 ( V_170 ) ) ;
V_46 = F_169 ( & V_205 -> V_93 , & V_169 -> V_156 ) ;
if ( V_46 )
F_166 ( L_26 ) ;
V_170 -> V_182 = 1 ;
}
V_44 -> V_118 . V_59 . V_56 = V_56 ;
V_44 -> V_118 . V_59 . V_113 = V_201 - V_56 ;
F_170 (entry, &ggtt_vm->mm, hole_start, hole_end) {
F_166 ( L_27 ,
V_206 , V_207 ) ;
V_205 -> V_110 ( V_205 , V_206 ,
V_207 - V_206 , true ) ;
}
V_205 -> V_110 ( V_205 , V_201 - V_77 , V_77 , true ) ;
}
void F_171 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
unsigned long V_209 , V_210 ;
V_209 = V_44 -> V_118 . V_59 . V_113 ;
V_210 = V_44 -> V_118 . V_163 ;
F_165 ( V_2 , 0 , V_210 , V_209 ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_73 * V_73 ;
T_2 V_211 ;
V_73 = F_53 ( V_94 | V_212 | V_213 ) ;
if ( V_73 == NULL )
return - V_95 ;
F_173 ( V_73 ) ;
F_174 ( V_73 , 1 ) ;
#ifdef F_5
V_211 = F_62 ( V_2 -> V_8 , V_73 , 0 , V_77 ,
V_91 ) ;
if ( F_63 ( V_2 -> V_8 , V_211 ) )
return - V_214 ;
#else
V_211 = F_175 ( V_73 ) ;
#endif
V_44 -> V_118 . V_59 . V_72 . V_73 = V_73 ;
V_44 -> V_118 . V_59 . V_72 . V_10 = V_211 ;
return 0 ;
}
static void F_176 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_73 * V_73 = V_44 -> V_118 . V_59 . V_72 . V_73 ;
F_177 ( V_73 , 1 ) ;
F_46 ( V_2 -> V_8 , V_44 -> V_118 . V_59 . V_72 . V_10 ,
V_77 , V_91 ) ;
F_178 ( V_73 ) ;
F_95 ( V_73 ) ;
}
static inline unsigned int F_179 ( T_9 V_215 )
{
V_215 >>= V_216 ;
V_215 &= V_217 ;
return V_215 << 20 ;
}
static inline unsigned int F_180 ( T_9 V_218 )
{
V_218 >>= V_219 ;
V_218 &= V_220 ;
if ( V_218 )
V_218 = 1 << V_218 ;
#ifdef F_181
if ( V_218 > 4 )
V_218 = 4 ;
#endif
return V_218 << 20 ;
}
static inline unsigned int F_182 ( T_9 V_221 )
{
V_221 >>= V_216 ;
V_221 &= V_217 ;
if ( V_221 )
return 1 << ( 20 + V_221 ) ;
return 0 ;
}
static inline T_10 F_183 ( T_9 V_215 )
{
V_215 >>= V_222 ;
V_215 &= V_223 ;
return V_215 << 25 ;
}
static inline T_10 F_184 ( T_9 V_218 )
{
V_218 >>= V_224 ;
V_218 &= V_225 ;
return V_218 << 25 ;
}
static T_10 F_185 ( T_9 V_221 )
{
V_221 >>= V_222 ;
V_221 &= V_223 ;
if ( V_221 < 0x11 )
return V_221 << 25 ;
else if ( V_221 < 0x17 )
return ( V_221 - 0x11 + 2 ) << 22 ;
else
return ( V_221 - 0x17 + 9 ) << 22 ;
}
static int F_186 ( struct V_1 * V_2 ,
T_10 V_209 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
T_11 V_226 ;
int V_46 ;
V_226 = F_187 ( V_2 -> V_8 , 0 ) +
( F_188 ( V_2 -> V_8 , 0 ) / 2 ) ;
V_44 -> V_118 . V_119 = F_189 ( V_226 , V_209 ) ;
if ( ! V_44 -> V_118 . V_119 ) {
F_123 ( L_28 ) ;
return - V_95 ;
}
V_46 = F_172 ( V_2 ) ;
if ( V_46 ) {
F_123 ( L_29 ) ;
F_190 ( V_44 -> V_118 . V_119 ) ;
}
return V_46 ;
}
static void F_138 ( struct V_43 * V_44 )
{
T_6 V_227 ;
V_227 = F_191 ( 0 , V_228 | V_229 ) |
F_191 ( 1 , V_230 | V_231 ) |
F_191 ( 2 , V_232 | V_231 ) |
F_191 ( 3 , V_233 ) |
F_191 ( 4 , V_228 | V_231 | F_192 ( 0 ) ) |
F_191 ( 5 , V_228 | V_231 | F_192 ( 1 ) ) |
F_191 ( 6 , V_228 | V_231 | F_192 ( 2 ) ) |
F_191 ( 7 , V_228 | V_231 | F_192 ( 3 ) ) ;
F_23 ( V_234 , V_227 ) ;
F_23 ( V_234 + 4 , V_227 >> 32 ) ;
}
static void F_137 ( struct V_43 * V_44 )
{
T_6 V_227 ;
V_227 = F_191 ( 0 , V_235 ) |
F_191 ( 1 , 0 ) |
F_191 ( 2 , 0 ) |
F_191 ( 3 , 0 ) |
F_191 ( 4 , V_235 ) |
F_191 ( 5 , V_235 ) |
F_191 ( 6 , V_235 ) |
F_191 ( 7 , V_235 ) ;
F_23 ( V_234 , V_227 ) ;
F_23 ( V_234 + 4 , V_227 >> 32 ) ;
}
static int F_193 ( struct V_1 * V_2 ,
T_10 * V_236 ,
T_10 * V_237 ,
T_11 * V_238 ,
unsigned long * V_163 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
unsigned int V_209 ;
T_9 V_215 ;
int V_46 ;
* V_238 = F_187 ( V_2 -> V_8 , 2 ) ;
* V_163 = F_188 ( V_2 -> V_8 , 2 ) ;
if ( ! F_194 ( V_2 -> V_8 , F_195 ( 39 ) ) )
F_196 ( V_2 -> V_8 , F_195 ( 39 ) ) ;
F_197 ( V_2 -> V_8 , V_239 , & V_215 ) ;
if ( F_9 ( V_2 ) ) {
* V_237 = F_185 ( V_215 ) ;
V_209 = F_182 ( V_215 ) ;
} else {
* V_237 = F_184 ( V_215 ) ;
V_209 = F_180 ( V_215 ) ;
}
* V_236 = ( V_209 / sizeof( T_1 ) ) << V_70 ;
if ( F_9 ( V_2 ) )
F_137 ( V_44 ) ;
else
F_138 ( V_44 ) ;
V_46 = F_186 ( V_2 , V_209 ) ;
V_44 -> V_118 . V_59 . V_110 = F_149 ;
V_44 -> V_118 . V_59 . V_111 = F_145 ;
return V_46 ;
}
static int F_198 ( struct V_1 * V_2 ,
T_10 * V_236 ,
T_10 * V_237 ,
T_11 * V_238 ,
unsigned long * V_163 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
unsigned int V_209 ;
T_9 V_215 ;
int V_46 ;
* V_238 = F_187 ( V_2 -> V_8 , 2 ) ;
* V_163 = F_188 ( V_2 -> V_8 , 2 ) ;
if ( ( * V_163 < ( 64 << 20 ) || ( * V_163 > ( 512 << 20 ) ) ) ) {
F_123 ( L_30 ,
V_44 -> V_118 . V_163 ) ;
return - V_240 ;
}
if ( ! F_194 ( V_2 -> V_8 , F_195 ( 40 ) ) )
F_196 ( V_2 -> V_8 , F_195 ( 40 ) ) ;
F_197 ( V_2 -> V_8 , V_239 , & V_215 ) ;
* V_237 = F_183 ( V_215 ) ;
V_209 = F_179 ( V_215 ) ;
* V_236 = ( V_209 / sizeof( T_4 ) ) << V_70 ;
V_46 = F_186 ( V_2 , V_209 ) ;
V_44 -> V_118 . V_59 . V_110 = F_152 ;
V_44 -> V_118 . V_59 . V_111 = F_148 ;
return V_46 ;
}
static void F_199 ( struct V_54 * V_55 )
{
struct V_241 * V_118 = F_32 ( V_55 , struct V_241 , V_59 ) ;
if ( F_99 ( & V_55 -> V_93 ) ) {
F_49 ( & V_55 -> V_93 ) ;
F_48 ( & V_55 -> V_92 ) ;
}
F_190 ( V_118 -> V_119 ) ;
F_176 ( V_55 -> V_2 ) ;
}
static int F_200 ( struct V_1 * V_2 ,
T_10 * V_236 ,
T_10 * V_237 ,
T_11 * V_238 ,
unsigned long * V_163 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
int V_46 ;
V_46 = F_201 ( V_44 -> V_242 , V_44 -> V_2 -> V_8 , NULL ) ;
if ( ! V_46 ) {
F_123 ( L_31 ) ;
return - V_165 ;
}
F_202 ( V_236 , V_237 , V_238 , V_163 ) ;
V_44 -> V_118 . V_173 = F_117 ( V_44 -> V_2 ) ;
V_44 -> V_118 . V_59 . V_110 = F_155 ;
if ( F_121 ( V_44 -> V_118 . V_173 ) )
F_7 ( L_32 ) ;
return 0 ;
}
static void F_203 ( struct V_54 * V_55 )
{
if ( F_99 ( & V_55 -> V_93 ) ) {
F_49 ( & V_55 -> V_93 ) ;
F_48 ( & V_55 -> V_92 ) ;
}
F_204 () ;
}
int F_205 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_241 * V_118 = & V_44 -> V_118 ;
int V_46 ;
if ( F_6 ( V_2 ) -> V_6 <= 5 ) {
V_118 -> V_243 = F_200 ;
V_118 -> V_59 . V_112 = F_203 ;
} else if ( F_6 ( V_2 ) -> V_6 < 8 ) {
V_118 -> V_243 = F_198 ;
V_118 -> V_59 . V_112 = F_199 ;
if ( F_89 ( V_2 ) && V_44 -> V_244 )
V_118 -> V_59 . V_117 = F_20 ;
else if ( F_89 ( V_2 ) )
V_118 -> V_59 . V_117 = F_18 ;
else if ( F_8 ( V_2 ) )
V_118 -> V_59 . V_117 = F_17 ;
else if ( F_6 ( V_2 ) -> V_6 >= 7 )
V_118 -> V_59 . V_117 = F_16 ;
else
V_118 -> V_59 . V_117 = F_13 ;
} else {
V_44 -> V_118 . V_243 = F_193 ;
V_44 -> V_118 . V_59 . V_112 = F_199 ;
}
V_46 = V_118 -> V_243 ( V_2 , & V_118 -> V_59 . V_113 , & V_118 -> V_245 ,
& V_118 -> V_238 , & V_118 -> V_163 ) ;
if ( V_46 )
return V_46 ;
V_118 -> V_59 . V_2 = V_2 ;
F_7 ( L_33 ,
V_118 -> V_59 . V_113 >> 20 ) ;
F_10 ( L_34 , V_118 -> V_163 >> 20 ) ;
F_10 ( L_35 , V_118 -> V_245 >> 20 ) ;
#ifdef F_5
if ( V_7 )
F_7 ( L_36 ) ;
#endif
V_4 . V_5 = F_2 ( V_2 , V_4 . V_5 ) ;
F_10 ( L_37 , V_4 . V_5 ) ;
return 0 ;
}
static struct V_168 * F_206 ( struct V_180 * V_170 ,
struct V_54 * V_55 )
{
struct V_168 * V_169 = F_207 ( sizeof( * V_169 ) , V_94 ) ;
if ( V_169 == NULL )
return F_52 ( - V_95 ) ;
F_208 ( & V_169 -> V_246 ) ;
F_208 ( & V_169 -> V_247 ) ;
F_208 ( & V_169 -> V_248 ) ;
V_169 -> V_55 = V_55 ;
V_169 -> V_170 = V_170 ;
switch ( F_6 ( V_55 -> V_2 ) -> V_6 ) {
case 8 :
case 7 :
case 6 :
if ( F_139 ( V_55 ) ) {
V_169 -> V_249 = F_159 ;
V_169 -> V_183 = F_158 ;
} else {
V_169 -> V_249 = F_116 ;
V_169 -> V_183 = F_115 ;
}
break;
case 5 :
case 4 :
case 3 :
case 2 :
F_22 ( ! F_139 ( V_55 ) ) ;
V_169 -> V_249 = F_157 ;
V_169 -> V_183 = F_153 ;
break;
default:
F_109 () ;
}
if ( F_139 ( V_55 ) )
F_209 ( & V_169 -> V_246 , & V_170 -> V_250 ) ;
else
F_210 ( & V_169 -> V_246 , & V_170 -> V_250 ) ;
return V_169 ;
}
struct V_168 *
F_211 ( struct V_180 * V_170 ,
struct V_54 * V_55 )
{
struct V_168 * V_169 ;
V_169 = F_135 ( V_170 , V_55 ) ;
if ( ! V_169 )
V_169 = F_206 ( V_170 , V_55 ) ;
return V_169 ;
}
