struct V_1 *
F_1 ( struct V_2 * V_3 , int clock )
{
struct V_1 * V_4 = NULL ;
struct V_5 V_6 ;
enum V_7 V_8 ;
bool V_9 = false ;
if ( ! F_2 ( clock , & V_6 ) )
return V_4 ;
for ( V_8 = V_10 ; V_8 <= V_11 ; V_8 ++ ) {
V_4 = & V_3 -> V_12 [ V_8 ] ;
if ( V_4 -> V_13 . V_14 == 0 )
continue;
if ( memcmp ( & V_6 , & V_4 -> V_13 . V_15 ,
sizeof( V_4 -> V_13 . V_15 ) ) == 0 ) {
V_9 = true ;
break;
}
}
for ( V_8 = V_10 ;
( ( V_9 == false ) && ( V_8 <= V_11 ) ) ; V_8 ++ ) {
V_4 = & V_3 -> V_12 [ V_8 ] ;
if ( V_4 -> V_13 . V_14 == 0 ) {
V_4 -> V_13 . V_15 = V_6 ;
break;
}
}
return V_4 ;
}
static void
F_3 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
enum V_7 V_8 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_18 ; V_8 ++ ) {
struct V_1 * V_4 = & V_3 -> V_12 [ V_8 ] ;
V_17 [ V_8 ] = V_4 -> V_13 ;
}
}
static struct V_16 *
F_4 ( struct V_19 * V_20 )
{
struct V_21 * V_13 = F_5 ( V_20 ) ;
F_6 ( ! F_7 ( & V_20 -> V_22 -> V_23 . V_24 ) ) ;
if ( ! V_13 -> V_25 ) {
V_13 -> V_25 = true ;
F_3 ( F_8 ( V_20 -> V_22 ) ,
V_13 -> V_17 ) ;
}
return V_13 -> V_17 ;
}
struct V_1 *
F_9 ( struct V_2 * V_3 ,
enum V_7 V_26 )
{
return & V_3 -> V_12 [ V_26 ] ;
}
enum V_7
F_10 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
if ( F_6 ( V_4 < V_3 -> V_12 ||
V_4 > & V_3 -> V_12 [ V_3 -> V_18 ] ) )
return - 1 ;
return (enum V_7 ) ( V_4 - V_3 -> V_12 ) ;
}
void F_11 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
bool V_13 )
{
bool V_27 ;
struct V_5 V_15 ;
if ( F_12 ( ! V_4 , L_1 , F_13 ( V_13 ) ) )
return;
V_27 = V_4 -> V_28 . V_29 ( V_3 , V_4 , & V_15 ) ;
F_14 ( V_27 != V_13 ,
L_2 ,
V_4 -> V_30 , F_13 ( V_13 ) , F_13 ( V_27 ) ) ;
}
void F_15 ( struct V_31 * V_32 )
{
struct V_33 * V_22 = V_32 -> V_34 . V_22 ;
struct V_2 * V_3 = F_8 ( V_22 ) ;
struct V_1 * V_4 = V_32 -> V_35 -> V_17 ;
if ( F_6 ( V_4 == NULL ) )
return;
F_16 ( & V_3 -> V_36 ) ;
F_6 ( ! V_4 -> V_13 . V_14 ) ;
if ( ! V_4 -> V_37 ) {
F_17 ( L_3 , V_4 -> V_30 ) ;
F_6 ( V_4 -> V_38 ) ;
F_18 ( V_3 , V_4 ) ;
V_4 -> V_28 . V_39 ( V_3 , V_4 ) ;
}
F_19 ( & V_3 -> V_36 ) ;
}
void F_20 ( struct V_31 * V_32 )
{
struct V_33 * V_22 = V_32 -> V_34 . V_22 ;
struct V_2 * V_3 = F_8 ( V_22 ) ;
struct V_1 * V_4 = V_32 -> V_35 -> V_17 ;
unsigned V_14 = 1 << F_21 ( & V_32 -> V_34 ) ;
unsigned V_40 ;
if ( F_6 ( V_4 == NULL ) )
return;
F_16 ( & V_3 -> V_36 ) ;
V_40 = V_4 -> V_37 ;
if ( F_6 ( ! ( V_4 -> V_13 . V_14 & V_14 ) ) ||
F_6 ( V_4 -> V_37 & V_14 ) )
goto V_41;
V_4 -> V_37 |= V_14 ;
F_22 ( L_4 ,
V_4 -> V_30 , V_4 -> V_37 , V_4 -> V_38 ,
V_32 -> V_34 . V_34 . V_26 ) ;
if ( V_40 ) {
F_6 ( ! V_4 -> V_38 ) ;
F_23 ( V_3 , V_4 ) ;
goto V_41;
}
F_6 ( V_4 -> V_38 ) ;
F_22 ( L_5 , V_4 -> V_30 ) ;
V_4 -> V_28 . V_42 ( V_3 , V_4 ) ;
V_4 -> V_38 = true ;
V_41:
F_19 ( & V_3 -> V_36 ) ;
}
void F_24 ( struct V_31 * V_32 )
{
struct V_2 * V_3 = F_8 ( V_32 -> V_34 . V_22 ) ;
struct V_1 * V_4 = V_32 -> V_35 -> V_17 ;
unsigned V_14 = 1 << F_21 ( & V_32 -> V_34 ) ;
if ( F_25 ( V_3 ) < 5 )
return;
if ( V_4 == NULL )
return;
F_16 ( & V_3 -> V_36 ) ;
if ( F_6 ( ! ( V_4 -> V_37 & V_14 ) ) )
goto V_41;
F_22 ( L_6 ,
V_4 -> V_30 , V_4 -> V_37 , V_4 -> V_38 ,
V_32 -> V_34 . V_34 . V_26 ) ;
F_23 ( V_3 , V_4 ) ;
F_6 ( ! V_4 -> V_38 ) ;
V_4 -> V_37 &= ~ V_14 ;
if ( V_4 -> V_37 )
goto V_41;
F_22 ( L_7 , V_4 -> V_30 ) ;
V_4 -> V_28 . V_43 ( V_3 , V_4 ) ;
V_4 -> V_38 = false ;
V_41:
F_19 ( & V_3 -> V_36 ) ;
}
static struct V_1 *
F_26 ( struct V_31 * V_32 ,
struct V_44 * V_45 ,
enum V_7 V_46 ,
enum V_7 V_47 )
{
struct V_2 * V_3 = F_8 ( V_32 -> V_34 . V_22 ) ;
struct V_1 * V_4 ;
struct V_16 * V_17 ;
enum V_7 V_8 ;
V_17 = F_4 ( V_45 -> V_34 . V_13 ) ;
for ( V_8 = V_46 ; V_8 <= V_47 ; V_8 ++ ) {
V_4 = & V_3 -> V_12 [ V_8 ] ;
if ( V_17 [ V_8 ] . V_14 == 0 )
continue;
if ( memcmp ( & V_45 -> V_6 ,
& V_17 [ V_8 ] . V_15 ,
sizeof( V_45 -> V_6 ) ) == 0 ) {
F_22 ( L_8 ,
V_32 -> V_34 . V_34 . V_26 , V_32 -> V_34 . V_30 , V_4 -> V_30 ,
V_17 [ V_8 ] . V_14 ,
V_4 -> V_37 ) ;
return V_4 ;
}
}
for ( V_8 = V_46 ; V_8 <= V_47 ; V_8 ++ ) {
V_4 = & V_3 -> V_12 [ V_8 ] ;
if ( V_17 [ V_8 ] . V_14 == 0 ) {
F_22 ( L_9 ,
V_32 -> V_34 . V_34 . V_26 , V_32 -> V_34 . V_30 , V_4 -> V_30 ) ;
return V_4 ;
}
}
return NULL ;
}
static void
F_27 ( struct V_1 * V_4 ,
struct V_44 * V_45 )
{
struct V_16 * V_17 ;
struct V_31 * V_32 = F_28 ( V_45 -> V_34 . V_32 ) ;
enum V_7 V_8 = V_4 -> V_26 ;
V_17 = F_4 ( V_45 -> V_34 . V_13 ) ;
if ( V_17 [ V_8 ] . V_14 == 0 )
V_17 [ V_8 ] . V_15 =
V_45 -> V_6 ;
V_45 -> V_17 = V_4 ;
F_17 ( L_10 , V_4 -> V_30 ,
F_29 ( V_32 -> V_48 ) ) ;
V_17 [ V_4 -> V_26 ] . V_14 |= 1 << V_32 -> V_48 ;
}
void F_30 ( struct V_19 * V_13 )
{
struct V_2 * V_3 = F_8 ( V_13 -> V_22 ) ;
struct V_16 * V_17 ;
struct V_1 * V_4 ;
enum V_7 V_8 ;
if ( ! F_5 ( V_13 ) -> V_25 )
return;
V_17 = F_5 ( V_13 ) -> V_17 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_18 ; V_8 ++ ) {
struct V_16 V_49 ;
V_4 = & V_3 -> V_12 [ V_8 ] ;
V_49 = V_4 -> V_13 ;
V_4 -> V_13 = V_17 [ V_8 ] ;
V_17 [ V_8 ] = V_49 ;
}
}
static bool F_31 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_50 ;
if ( ! F_32 ( V_3 , V_51 ) )
return false ;
V_50 = F_33 ( F_34 ( V_4 -> V_26 ) ) ;
V_15 -> V_52 = V_50 ;
V_15 -> V_53 = F_33 ( F_35 ( V_4 -> V_26 ) ) ;
V_15 -> V_54 = F_33 ( F_36 ( V_4 -> V_26 ) ) ;
F_37 ( V_3 , V_51 ) ;
return V_50 & V_55 ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_39 ( F_35 ( V_4 -> V_26 ) , V_4 -> V_13 . V_15 . V_53 ) ;
F_39 ( F_36 ( V_4 -> V_26 ) , V_4 -> V_13 . V_15 . V_54 ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
T_2 V_50 ;
bool V_56 ;
F_41 ( ! ( F_42 ( V_3 ) || F_43 ( V_3 ) ) ) ;
V_50 = F_33 ( V_57 ) ;
V_56 = ! ! ( V_50 & ( V_58 | V_59 |
V_60 ) ) ;
F_14 ( ! V_56 , L_11 ) ;
}
static void F_44 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_40 ( V_3 ) ;
F_39 ( F_34 ( V_4 -> V_26 ) , V_4 -> V_13 . V_15 . V_52 ) ;
F_45 ( F_34 ( V_4 -> V_26 ) ) ;
F_46 ( 150 ) ;
F_39 ( F_34 ( V_4 -> V_26 ) , V_4 -> V_13 . V_15 . V_52 ) ;
F_45 ( F_34 ( V_4 -> V_26 ) ) ;
F_46 ( 200 ) ;
}
static void F_47 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_33 * V_22 = & V_3 -> V_61 ;
struct V_31 * V_32 ;
F_48 (dev, crtc) {
if ( V_32 -> V_35 -> V_17 == V_4 )
F_49 ( V_3 , V_32 -> V_48 ) ;
}
F_39 ( F_34 ( V_4 -> V_26 ) , 0 ) ;
F_45 ( F_34 ( V_4 -> V_26 ) ) ;
F_46 ( 200 ) ;
}
static struct V_1 *
F_50 ( struct V_31 * V_32 , struct V_44 * V_45 ,
struct V_62 * V_63 )
{
struct V_2 * V_3 = F_8 ( V_32 -> V_34 . V_22 ) ;
struct V_1 * V_4 ;
enum V_7 V_8 ;
if ( F_42 ( V_3 ) ) {
V_8 = (enum V_7 ) V_32 -> V_48 ;
V_4 = & V_3 -> V_12 [ V_8 ] ;
F_22 ( L_12 ,
V_32 -> V_34 . V_34 . V_26 , V_32 -> V_34 . V_30 , V_4 -> V_30 ) ;
} else {
V_4 = F_26 ( V_32 , V_45 ,
V_64 ,
V_65 ) ;
}
if ( ! V_4 )
return NULL ;
F_27 ( V_4 , V_45 ) ;
return V_4 ;
}
static void F_51 ( struct V_2 * V_3 ,
struct V_5 * V_15 )
{
F_22 ( L_13
L_14 ,
V_15 -> V_52 ,
V_15 -> V_66 ,
V_15 -> V_53 ,
V_15 -> V_54 ) ;
}
static void F_52 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_39 ( F_53 ( V_4 -> V_26 ) , V_4 -> V_13 . V_15 . V_67 ) ;
F_45 ( F_53 ( V_4 -> V_26 ) ) ;
F_46 ( 20 ) ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_39 ( V_68 , V_4 -> V_13 . V_15 . V_69 ) ;
F_45 ( V_68 ) ;
F_46 ( 20 ) ;
}
static void F_55 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_50 ;
V_50 = F_33 ( F_53 ( V_4 -> V_26 ) ) ;
F_39 ( F_53 ( V_4 -> V_26 ) , V_50 & ~ V_70 ) ;
F_45 ( F_53 ( V_4 -> V_26 ) ) ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_50 ;
V_50 = F_33 ( V_68 ) ;
F_39 ( V_68 , V_50 & ~ V_71 ) ;
F_45 ( V_68 ) ;
}
static bool F_57 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_50 ;
if ( ! F_32 ( V_3 , V_51 ) )
return false ;
V_50 = F_33 ( F_53 ( V_4 -> V_26 ) ) ;
V_15 -> V_67 = V_50 ;
F_37 ( V_3 , V_51 ) ;
return V_50 & V_70 ;
}
static bool F_58 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_50 ;
if ( ! F_32 ( V_3 , V_51 ) )
return false ;
V_50 = F_33 ( V_68 ) ;
V_15 -> V_69 = V_50 ;
F_37 ( V_3 , V_51 ) ;
return V_50 & V_71 ;
}
static unsigned F_59 ( int clock )
{
unsigned V_72 ;
switch ( clock ) {
case 25175000 :
case 25200000 :
case 27000000 :
case 27027000 :
case 37762500 :
case 37800000 :
case 40500000 :
case 40541000 :
case 54000000 :
case 54054000 :
case 59341000 :
case 59400000 :
case 72000000 :
case 74176000 :
case 74250000 :
case 81000000 :
case 81081000 :
case 89012000 :
case 89100000 :
case 108000000 :
case 108108000 :
case 111264000 :
case 111375000 :
case 148352000 :
case 148500000 :
case 162000000 :
case 162162000 :
case 222525000 :
case 222750000 :
case 296703000 :
case 297000000 :
V_72 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_72 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_72 = 2000 ;
break;
case 256250000 :
case 262500000 :
case 270000000 :
case 272500000 :
case 273750000 :
case 280750000 :
case 281250000 :
case 286000000 :
case 291750000 :
V_72 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_72 = 5000 ;
break;
default:
V_72 = 1000 ;
break;
}
return V_72 ;
}
static void F_60 ( T_3 V_73 , unsigned V_72 ,
unsigned V_74 , unsigned V_75 , unsigned V_76 ,
struct V_77 * V_78 )
{
T_3 V_79 , V_80 , V_81 , V_82 , V_83 , V_84 ;
if ( V_78 -> V_76 == 0 ) {
V_78 -> V_76 = V_76 ;
V_78 -> V_75 = V_75 ;
V_78 -> V_74 = V_74 ;
return;
}
V_79 = V_73 * V_72 * V_76 * V_74 ;
V_80 = V_73 * V_72 * V_78 -> V_76 * V_78 -> V_74 ;
V_83 = F_61 ( V_73 * V_76 * V_74 , V_85 * V_75 ) ;
V_84 = F_61 ( V_73 * V_78 -> V_76 * V_78 -> V_74 ,
V_85 * V_78 -> V_75 ) ;
V_81 = 1000000 * V_83 ;
V_82 = 1000000 * V_84 ;
if ( V_79 < V_81 && V_80 < V_82 ) {
if ( V_78 -> V_76 * V_78 -> V_74 * V_83 < V_76 * V_74 * V_84 ) {
V_78 -> V_76 = V_76 ;
V_78 -> V_75 = V_75 ;
V_78 -> V_74 = V_74 ;
}
} else if ( V_79 >= V_81 && V_80 < V_82 ) {
V_78 -> V_76 = V_76 ;
V_78 -> V_75 = V_75 ;
V_78 -> V_74 = V_74 ;
} else if ( V_79 >= V_81 && V_80 >= V_82 ) {
if ( V_75 * V_78 -> V_74 * V_78 -> V_74 > V_78 -> V_75 * V_74 * V_74 ) {
V_78 -> V_76 = V_76 ;
V_78 -> V_75 = V_75 ;
V_78 -> V_74 = V_74 ;
}
}
}
static void
F_62 ( int clock ,
unsigned * V_86 , unsigned * V_87 , unsigned * V_88 )
{
T_3 V_73 ;
unsigned V_76 , V_75 , V_74 ;
struct V_77 V_78 = { 0 , 0 , 0 } ;
unsigned V_72 ;
V_73 = clock / 100 ;
V_72 = F_59 ( clock ) ;
if ( V_73 == 5400000 ) {
* V_87 = 2 ;
* V_88 = 1 ;
* V_86 = 2 ;
return;
}
for ( V_74 = V_89 * 2 / V_90 + 1 ;
V_74 <= V_89 * 2 / V_91 ;
V_74 ++ ) {
for ( V_75 = V_92 * V_74 / V_89 + 1 ;
V_75 <= V_93 * V_74 / V_89 ;
V_75 ++ ) {
for ( V_76 = V_94 ; V_76 <= V_95 ; V_76 += V_96 )
F_60 ( V_73 , V_72 ,
V_74 , V_75 , V_76 , & V_78 ) ;
}
}
* V_87 = V_78 . V_75 ;
* V_88 = V_78 . V_76 ;
* V_86 = V_78 . V_74 ;
}
static struct V_1 * F_63 ( int clock ,
struct V_31 * V_32 ,
struct V_44 * V_45 )
{
struct V_1 * V_4 ;
T_1 V_50 ;
unsigned int V_76 , V_75 , V_74 ;
F_62 ( clock * 1000 , & V_74 , & V_75 , & V_76 ) ;
V_50 = V_70 | V_97 |
F_64 ( V_74 ) | F_65 ( V_75 ) |
F_66 ( V_76 ) ;
V_45 -> V_6 . V_67 = V_50 ;
V_4 = F_26 ( V_32 , V_45 ,
V_98 , V_99 ) ;
if ( ! V_4 )
return NULL ;
return V_4 ;
}
struct V_1 * F_67 ( struct V_62 * V_63 ,
int clock )
{
struct V_2 * V_3 = F_8 ( V_63 -> V_34 . V_22 ) ;
struct V_1 * V_4 ;
enum V_7 V_100 ;
switch ( clock / 2 ) {
case 81000 :
V_100 = V_101 ;
break;
case 135000 :
V_100 = V_102 ;
break;
case 270000 :
V_100 = V_103 ;
break;
default:
F_22 ( L_15 , clock ) ;
return NULL ;
}
V_4 = F_9 ( V_3 , V_100 ) ;
if ( ! V_4 )
return NULL ;
return V_4 ;
}
static struct V_1 *
F_68 ( struct V_31 * V_32 , struct V_44 * V_45 ,
struct V_62 * V_63 )
{
struct V_1 * V_4 ;
int clock = V_45 -> V_104 ;
memset ( & V_45 -> V_6 , 0 ,
sizeof( V_45 -> V_6 ) ) ;
if ( V_63 -> type == V_105 ) {
V_4 = F_63 ( clock , V_32 , V_45 ) ;
} else if ( V_63 -> type == V_106 ||
V_63 -> type == V_107 ||
V_63 -> type == V_108 ) {
V_4 = F_67 ( V_63 , clock ) ;
} else if ( V_63 -> type == V_109 ) {
if ( F_6 ( V_45 -> V_104 / 2 != 135000 ) )
return NULL ;
V_45 -> V_6 . V_69 =
V_71 | V_110 | V_111 ;
V_4 = F_26 ( V_32 , V_45 ,
V_112 , V_112 ) ;
} else {
return NULL ;
}
if ( ! V_4 )
return NULL ;
F_27 ( V_4 , V_45 ) ;
return V_4 ;
}
static void F_69 ( struct V_2 * V_3 ,
struct V_5 * V_15 )
{
F_22 ( L_16 ,
V_15 -> V_67 , V_15 -> V_69 ) ;
}
static void F_70 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
}
static void F_71 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
}
static bool F_72 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
return true ;
}
static void F_73 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_50 ;
V_50 = F_33 ( V_113 ) ;
V_50 &= ~ ( F_74 ( V_4 -> V_26 ) | F_75 ( V_4 -> V_26 ) |
F_76 ( V_4 -> V_26 ) ) ;
V_50 |= V_4 -> V_13 . V_15 . V_114 << ( V_4 -> V_26 * 6 ) ;
F_39 ( V_113 , V_50 ) ;
F_45 ( V_113 ) ;
}
static void F_77 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
const struct V_115 * V_116 = V_115 ;
F_73 ( V_3 , V_4 ) ;
F_39 ( V_116 [ V_4 -> V_26 ] . V_117 , V_4 -> V_13 . V_15 . V_117 ) ;
F_39 ( V_116 [ V_4 -> V_26 ] . V_118 , V_4 -> V_13 . V_15 . V_118 ) ;
F_45 ( V_116 [ V_4 -> V_26 ] . V_117 ) ;
F_45 ( V_116 [ V_4 -> V_26 ] . V_118 ) ;
F_39 ( V_116 [ V_4 -> V_26 ] . V_119 ,
F_33 ( V_116 [ V_4 -> V_26 ] . V_119 ) | V_120 ) ;
if ( F_78 ( V_3 ,
V_121 ,
F_79 ( V_4 -> V_26 ) ,
F_79 ( V_4 -> V_26 ) ,
5 ) )
F_80 ( L_17 , V_4 -> V_26 ) ;
}
static void F_81 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_73 ( V_3 , V_4 ) ;
}
static void F_82 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
const struct V_115 * V_116 = V_115 ;
F_39 ( V_116 [ V_4 -> V_26 ] . V_119 ,
F_33 ( V_116 [ V_4 -> V_26 ] . V_119 ) & ~ V_120 ) ;
F_45 ( V_116 [ V_4 -> V_26 ] . V_119 ) ;
}
static void F_83 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
}
static bool F_84 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_50 ;
const struct V_115 * V_116 = V_115 ;
bool V_122 ;
if ( ! F_32 ( V_3 , V_51 ) )
return false ;
V_122 = false ;
V_50 = F_33 ( V_116 [ V_4 -> V_26 ] . V_119 ) ;
if ( ! ( V_50 & V_120 ) )
goto V_41;
V_50 = F_33 ( V_113 ) ;
V_15 -> V_114 = ( V_50 >> ( V_4 -> V_26 * 6 ) ) & 0x3f ;
if ( V_50 & F_74 ( V_4 -> V_26 ) ) {
V_15 -> V_117 = F_33 ( V_116 [ V_4 -> V_26 ] . V_117 ) ;
V_15 -> V_118 = F_33 ( V_116 [ V_4 -> V_26 ] . V_118 ) ;
}
V_122 = true ;
V_41:
F_37 ( V_3 , V_51 ) ;
return V_122 ;
}
static bool F_85 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_50 ;
const struct V_115 * V_116 = V_115 ;
bool V_122 ;
if ( ! F_32 ( V_3 , V_51 ) )
return false ;
V_122 = false ;
V_50 = F_33 ( V_116 [ V_4 -> V_26 ] . V_119 ) ;
if ( F_6 ( ! ( V_50 & V_120 ) ) )
goto V_41;
V_50 = F_33 ( V_113 ) ;
V_15 -> V_114 = ( V_50 >> ( V_4 -> V_26 * 6 ) ) & 0x3f ;
V_122 = true ;
V_41:
F_37 ( V_3 , V_51 ) ;
return V_122 ;
}
static void F_86 ( struct V_123 * V_124 )
{
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_125 = V_126 ;
}
static void F_87 ( struct V_123 * V_124 ,
T_3 V_127 ,
T_3 V_128 ,
unsigned int V_129 )
{
T_3 V_130 ;
V_130 = F_88 ( 10000 * F_61 ( V_128 , V_127 ) ,
V_127 ) ;
if ( V_128 >= V_127 ) {
if ( V_130 < V_131 &&
V_130 < V_124 -> V_125 ) {
V_124 -> V_125 = V_130 ;
V_124 -> V_127 = V_127 ;
V_124 -> V_128 = V_128 ;
V_124 -> V_76 = V_129 ;
}
} else if ( V_130 < V_132 &&
V_130 < V_124 -> V_125 ) {
V_124 -> V_125 = V_130 ;
V_124 -> V_127 = V_127 ;
V_124 -> V_128 = V_128 ;
V_124 -> V_76 = V_129 ;
}
}
static void F_89 ( unsigned int V_76 ,
unsigned int * V_133 ,
unsigned int * V_134 ,
unsigned int * V_135 )
{
if ( V_76 % 2 == 0 ) {
unsigned int V_136 = V_76 / 2 ;
if ( V_136 == 1 || V_136 == 2 || V_136 == 3 || V_136 == 5 ) {
* V_133 = 2 ;
* V_134 = 1 ;
* V_135 = V_136 ;
} else if ( V_136 % 2 == 0 ) {
* V_133 = 2 ;
* V_134 = V_136 / 2 ;
* V_135 = 2 ;
} else if ( V_136 % 3 == 0 ) {
* V_133 = 3 ;
* V_134 = V_136 / 3 ;
* V_135 = 2 ;
} else if ( V_136 % 7 == 0 ) {
* V_133 = 7 ;
* V_134 = V_136 / 7 ;
* V_135 = 2 ;
}
} else if ( V_76 == 3 || V_76 == 9 ) {
* V_133 = 3 ;
* V_134 = 1 ;
* V_135 = V_76 / 3 ;
} else if ( V_76 == 5 || V_76 == 7 ) {
* V_133 = V_76 ;
* V_134 = 1 ;
* V_135 = 1 ;
} else if ( V_76 == 15 ) {
* V_133 = 3 ;
* V_134 = 1 ;
* V_135 = 5 ;
} else if ( V_76 == 21 ) {
* V_133 = 7 ;
* V_134 = 1 ;
* V_135 = 3 ;
} else if ( V_76 == 35 ) {
* V_133 = 7 ;
* V_134 = 1 ;
* V_135 = 5 ;
}
}
static void F_90 ( struct V_137 * V_138 ,
T_3 V_139 ,
T_3 V_127 ,
T_1 V_133 , T_1 V_134 , T_1 V_135 )
{
T_3 V_128 ;
switch ( V_127 ) {
case 9600000000ULL :
V_138 -> V_127 = 0 ;
break;
case 9000000000ULL :
V_138 -> V_127 = 1 ;
break;
case 8400000000ULL :
V_138 -> V_127 = 3 ;
}
switch ( V_133 ) {
case 1 :
V_138 -> V_140 = 0 ;
break;
case 2 :
V_138 -> V_140 = 1 ;
break;
case 3 :
V_138 -> V_140 = 2 ;
break;
case 7 :
V_138 -> V_140 = 4 ;
break;
default:
F_12 ( 1 , L_18 ) ;
}
switch ( V_135 ) {
case 5 :
V_138 -> V_141 = 0 ;
break;
case 2 :
V_138 -> V_141 = 1 ;
break;
case 3 :
V_138 -> V_141 = 2 ;
break;
case 1 :
V_138 -> V_141 = 3 ;
break;
default:
F_12 ( 1 , L_19 ) ;
}
V_138 -> V_142 = V_134 ;
V_138 -> V_143 = ( V_138 -> V_142 == 1 ) ? 0 : 1 ;
V_128 = V_133 * V_134 * V_135 * V_139 ;
V_138 -> V_144 = F_91 ( V_128 , 24 * F_92 ( 1 ) ) ;
V_138 -> V_145 =
F_91 ( ( F_91 ( V_128 , 24 ) -
V_138 -> V_144 * F_92 ( 1 ) ) * 0x8000 , F_92 ( 1 ) ) ;
}
static bool
F_93 ( int clock ,
struct V_137 * V_146 )
{
T_3 V_139 = clock * 5 ;
T_3 V_147 [ 3 ] = { 8400000000ULL ,
9000000000ULL ,
9600000000ULL } ;
static const int V_148 [] = { 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20 ,
24 , 28 , 30 , 32 , 36 , 40 , 42 , 44 ,
48 , 52 , 54 , 56 , 60 , 64 , 66 , 68 ,
70 , 72 , 76 , 78 , 80 , 84 , 88 , 90 ,
92 , 96 , 98 } ;
static const int V_149 [] = { 3 , 5 , 7 , 9 , 15 , 21 , 35 } ;
static const struct {
const int * V_150 ;
int V_151 ;
} V_152 [] = {
{ V_148 , F_94 (even_dividers) } ,
{ V_149 , F_94 (odd_dividers) } ,
} ;
struct V_123 V_124 ;
unsigned int V_153 , V_82 , V_8 ;
unsigned int V_133 , V_134 , V_135 ;
F_86 ( & V_124 ) ;
for ( V_82 = 0 ; V_82 < F_94 ( V_152 ) ; V_82 ++ ) {
for ( V_153 = 0 ; V_153 < F_94 ( V_147 ) ; V_153 ++ ) {
for ( V_8 = 0 ; V_8 < V_152 [ V_82 ] . V_151 ; V_8 ++ ) {
unsigned int V_76 = V_152 [ V_82 ] . V_150 [ V_8 ] ;
T_3 V_128 = V_76 * V_139 ;
F_87 ( & V_124 ,
V_147 [ V_153 ] ,
V_128 ,
V_76 ) ;
if ( V_124 . V_125 == 0 )
goto V_154;
}
}
V_154:
if ( V_82 == 0 && V_124 . V_76 )
break;
}
if ( ! V_124 . V_76 ) {
F_17 ( L_20 , clock ) ;
return false ;
}
V_133 = V_134 = V_135 = 0 ;
F_89 ( V_124 . V_76 , & V_133 , & V_134 , & V_135 ) ;
F_90 ( V_146 , V_139 , V_124 . V_127 ,
V_133 , V_134 , V_135 ) ;
return true ;
}
static bool F_95 ( struct V_31 * V_32 ,
struct V_44 * V_45 ,
int clock )
{
T_1 V_114 , V_117 , V_118 ;
struct V_137 V_146 = { 0 , } ;
V_114 = F_96 ( 0 ) ;
V_114 |= F_74 ( 0 ) ;
if ( ! F_93 ( clock * 1000 , & V_146 ) )
return false ;
V_117 = V_155 |
F_97 ( V_146 . V_145 ) |
V_146 . V_144 ;
V_118 = F_98 ( V_146 . V_142 ) |
F_99 ( V_146 . V_143 ) |
F_100 ( V_146 . V_141 ) |
F_101 ( V_146 . V_140 ) |
V_146 . V_127 ;
memset ( & V_45 -> V_6 , 0 ,
sizeof( V_45 -> V_6 ) ) ;
V_45 -> V_6 . V_114 = V_114 ;
V_45 -> V_6 . V_117 = V_117 ;
V_45 -> V_6 . V_118 = V_118 ;
return true ;
}
bool F_2 ( int clock ,
struct V_5 * V_6 )
{
T_1 V_114 ;
V_114 = F_96 ( 0 ) ;
switch ( clock / 2 ) {
case 81000 :
V_114 |= F_102 ( V_156 , 0 ) ;
break;
case 135000 :
V_114 |= F_102 ( V_157 , 0 ) ;
break;
case 270000 :
V_114 |= F_102 ( V_158 , 0 ) ;
break;
case 162000 :
V_114 |= F_102 ( V_159 , 0 ) ;
break;
case 108000 :
V_114 |= F_102 ( V_160 , 0 ) ;
break;
case 216000 :
V_114 |= F_102 ( V_161 , 0 ) ;
break;
}
V_6 -> V_114 = V_114 ;
return true ;
}
static struct V_1 *
F_103 ( struct V_31 * V_32 , struct V_44 * V_45 ,
struct V_62 * V_63 )
{
struct V_1 * V_4 ;
int clock = V_45 -> V_104 ;
bool V_162 ;
struct V_5 V_6 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
if ( V_63 -> type == V_105 ) {
V_162 = F_95 ( V_32 , V_45 , clock ) ;
if ( ! V_162 ) {
F_22 ( L_21 ) ;
return NULL ;
}
} else if ( V_63 -> type == V_106 ||
V_63 -> type == V_107 ||
V_63 -> type == V_108 ) {
V_162 = F_2 ( clock , & V_6 ) ;
if ( ! V_162 ) {
F_22 ( L_22 ) ;
return NULL ;
}
V_45 -> V_6 = V_6 ;
} else {
return NULL ;
}
if ( V_63 -> type == V_108 )
V_4 = F_26 ( V_32 , V_45 ,
V_163 ,
V_163 ) ;
else
V_4 = F_26 ( V_32 , V_45 ,
V_10 ,
V_11 ) ;
if ( ! V_4 )
return NULL ;
F_27 ( V_4 , V_45 ) ;
return V_4 ;
}
static void F_104 ( struct V_2 * V_3 ,
struct V_5 * V_15 )
{
F_22 ( L_23
L_24 ,
V_15 -> V_114 ,
V_15 -> V_117 ,
V_15 -> V_118 ) ;
}
static void F_105 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_164 ;
enum V_165 V_165 = (enum V_165 ) V_4 -> V_26 ;
enum V_166 V_167 ;
enum V_168 V_169 ;
F_106 ( V_3 , V_165 , & V_167 , & V_169 ) ;
V_164 = F_33 ( F_107 ( V_165 ) ) ;
V_164 |= V_170 ;
F_39 ( F_107 ( V_165 ) , V_164 ) ;
if ( F_108 ( V_3 ) ) {
V_164 = F_33 ( F_107 ( V_165 ) ) ;
V_164 |= V_171 ;
F_39 ( F_107 ( V_165 ) , V_164 ) ;
if ( F_109 ( ( F_33 ( F_107 ( V_165 ) ) &
V_172 ) , 200 ) )
F_80 ( L_25 , V_165 ) ;
}
V_164 = F_33 ( F_110 ( V_167 , V_169 ) ) ;
V_164 &= ~ V_173 ;
F_39 ( F_110 ( V_167 , V_169 ) , V_164 ) ;
V_164 = F_33 ( F_111 ( V_167 , V_169 ) ) ;
V_164 &= ~ ( V_174 | V_175 ) ;
V_164 |= V_4 -> V_13 . V_15 . V_176 ;
F_39 ( F_111 ( V_167 , V_169 ) , V_164 ) ;
V_164 = F_33 ( F_112 ( V_167 , V_169 , 0 ) ) ;
V_164 &= ~ V_177 ;
V_164 |= V_4 -> V_13 . V_15 . V_178 ;
F_39 ( F_112 ( V_167 , V_169 , 0 ) , V_164 ) ;
V_164 = F_33 ( F_112 ( V_167 , V_169 , 1 ) ) ;
V_164 &= ~ V_179 ;
V_164 |= V_4 -> V_13 . V_15 . V_180 ;
F_39 ( F_112 ( V_167 , V_169 , 1 ) , V_164 ) ;
V_164 = F_33 ( F_112 ( V_167 , V_169 , 2 ) ) ;
V_164 &= ~ V_181 ;
V_164 |= V_4 -> V_13 . V_15 . V_182 ;
F_39 ( F_112 ( V_167 , V_169 , 2 ) , V_164 ) ;
V_164 = F_33 ( F_112 ( V_167 , V_169 , 3 ) ) ;
V_164 &= ~ V_183 ;
V_164 |= V_4 -> V_13 . V_15 . V_184 ;
F_39 ( F_112 ( V_167 , V_169 , 3 ) , V_164 ) ;
V_164 = F_33 ( F_112 ( V_167 , V_169 , 6 ) ) ;
V_164 &= ~ V_185 ;
V_164 &= ~ V_186 ;
V_164 &= ~ V_187 ;
V_164 |= V_4 -> V_13 . V_15 . V_188 ;
F_39 ( F_112 ( V_167 , V_169 , 6 ) , V_164 ) ;
V_164 = F_33 ( F_112 ( V_167 , V_169 , 8 ) ) ;
V_164 &= ~ V_189 ;
V_164 |= V_4 -> V_13 . V_15 . V_190 ;
F_39 ( F_112 ( V_167 , V_169 , 8 ) , V_164 ) ;
V_164 = F_33 ( F_112 ( V_167 , V_169 , 9 ) ) ;
V_164 &= ~ V_191 ;
V_164 |= V_4 -> V_13 . V_15 . V_192 ;
F_39 ( F_112 ( V_167 , V_169 , 9 ) , V_164 ) ;
V_164 = F_33 ( F_112 ( V_167 , V_169 , 10 ) ) ;
V_164 &= ~ V_193 ;
V_164 &= ~ V_194 ;
V_164 |= V_4 -> V_13 . V_15 . V_195 ;
F_39 ( F_112 ( V_167 , V_169 , 10 ) , V_164 ) ;
V_164 = F_33 ( F_110 ( V_167 , V_169 ) ) ;
V_164 |= V_196 ;
F_39 ( F_110 ( V_167 , V_169 ) , V_164 ) ;
V_164 &= ~ V_173 ;
V_164 |= V_4 -> V_13 . V_15 . V_197 ;
F_39 ( F_110 ( V_167 , V_169 ) , V_164 ) ;
V_164 = F_33 ( F_107 ( V_165 ) ) ;
V_164 |= V_198 ;
F_39 ( F_107 ( V_165 ) , V_164 ) ;
F_45 ( F_107 ( V_165 ) ) ;
if ( F_109 ( ( F_33 ( F_107 ( V_165 ) ) & V_199 ) ,
200 ) )
F_80 ( L_26 , V_165 ) ;
if ( F_108 ( V_3 ) ) {
V_164 = F_33 ( F_113 ( V_167 , V_169 ) ) ;
V_164 |= V_200 ;
F_39 ( F_114 ( V_167 , V_169 ) , V_164 ) ;
}
V_164 = F_33 ( F_115 ( V_167 , V_169 ) ) ;
V_164 &= ~ V_201 ;
V_164 &= ~ V_202 ;
V_164 |= V_4 -> V_13 . V_15 . V_203 ;
F_39 ( F_116 ( V_167 , V_169 ) , V_164 ) ;
}
static void F_117 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
enum V_165 V_165 = (enum V_165 ) V_4 -> V_26 ;
T_1 V_164 ;
V_164 = F_33 ( F_107 ( V_165 ) ) ;
V_164 &= ~ V_198 ;
F_39 ( F_107 ( V_165 ) , V_164 ) ;
F_45 ( F_107 ( V_165 ) ) ;
if ( F_108 ( V_3 ) ) {
V_164 = F_33 ( F_107 ( V_165 ) ) ;
V_164 &= ~ V_171 ;
F_39 ( F_107 ( V_165 ) , V_164 ) ;
if ( F_109 ( ! ( F_33 ( F_107 ( V_165 ) ) &
V_172 ) , 200 ) )
F_80 ( L_27 , V_165 ) ;
}
}
static bool F_118 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
enum V_165 V_165 = (enum V_165 ) V_4 -> V_26 ;
T_1 V_50 ;
bool V_122 ;
enum V_166 V_167 ;
enum V_168 V_169 ;
F_106 ( V_3 , V_165 , & V_167 , & V_169 ) ;
if ( ! F_32 ( V_3 , V_51 ) )
return false ;
V_122 = false ;
V_50 = F_33 ( F_107 ( V_165 ) ) ;
if ( ! ( V_50 & V_198 ) )
goto V_41;
V_15 -> V_176 = F_33 ( F_111 ( V_167 , V_169 ) ) ;
V_15 -> V_176 &= V_174 | V_175 ;
V_15 -> V_197 = F_33 ( F_110 ( V_167 , V_169 ) ) ;
V_15 -> V_197 &= V_173 ;
V_15 -> V_178 = F_33 ( F_112 ( V_167 , V_169 , 0 ) ) ;
V_15 -> V_178 &= V_177 ;
V_15 -> V_180 = F_33 ( F_112 ( V_167 , V_169 , 1 ) ) ;
V_15 -> V_180 &= V_179 ;
V_15 -> V_182 = F_33 ( F_112 ( V_167 , V_169 , 2 ) ) ;
V_15 -> V_182 &= V_181 ;
V_15 -> V_184 = F_33 ( F_112 ( V_167 , V_169 , 3 ) ) ;
V_15 -> V_184 &= V_183 ;
V_15 -> V_188 = F_33 ( F_112 ( V_167 , V_169 , 6 ) ) ;
V_15 -> V_188 &= V_185 |
V_186 |
V_187 ;
V_15 -> V_190 = F_33 ( F_112 ( V_167 , V_169 , 8 ) ) ;
V_15 -> V_190 &= V_189 ;
V_15 -> V_192 = F_33 ( F_112 ( V_167 , V_169 , 9 ) ) ;
V_15 -> V_192 &= V_191 ;
V_15 -> V_195 = F_33 ( F_112 ( V_167 , V_169 , 10 ) ) ;
V_15 -> V_195 &= V_193 |
V_194 ;
V_15 -> V_203 = F_33 ( F_115 ( V_167 , V_169 ) ) ;
if ( F_33 ( F_119 ( V_167 , V_169 ) ) != V_15 -> V_203 )
F_17 ( L_28 ,
V_15 -> V_203 ,
F_33 ( F_119 ( V_167 , V_169 ) ) ) ;
V_15 -> V_203 &= V_201 | V_202 ;
V_122 = true ;
V_41:
F_37 ( V_3 , V_51 ) ;
return V_122 ;
}
static bool
F_120 ( struct V_31 * V_31 ,
struct V_44 * V_45 , int clock ,
struct V_204 * V_205 )
{
struct V_52 V_206 ;
if ( ! F_121 ( V_45 , clock , & V_206 ) ) {
F_17 ( L_29 ,
clock , F_29 ( V_31 -> V_48 ) ) ;
return false ;
}
V_205 -> V_134 = V_206 . V_134 ;
V_205 -> V_135 = V_206 . V_135 ;
F_6 ( V_206 . V_207 != 2 ) ;
V_205 -> V_208 = V_206 . V_208 ;
V_205 -> V_209 = V_206 . V_210 >> 22 ;
V_205 -> V_211 = V_206 . V_210 & ( ( 1 << 22 ) - 1 ) ;
V_205 -> V_212 = V_205 -> V_211 != 0 ;
V_205 -> V_213 = V_206 . V_213 ;
return true ;
}
static void F_122 ( int clock , struct V_204 * V_205 )
{
int V_8 ;
* V_205 = V_214 [ 0 ] ;
for ( V_8 = 0 ; V_8 < F_94 ( V_214 ) ; ++ V_8 ) {
if ( V_214 [ V_8 ] . clock == clock ) {
* V_205 = V_214 [ V_8 ] ;
break;
}
}
V_205 -> V_213 = clock * 10 / 2 * V_205 -> V_134 * V_205 -> V_135 ;
}
static bool F_123 ( int clock ,
struct V_204 * V_205 ,
struct V_5 * V_6 )
{
int V_213 = V_205 -> V_213 ;
T_1 V_215 , V_216 , V_217 , V_218 ;
T_1 V_219 ;
if ( V_213 >= 6200000 && V_213 <= 6700000 ) {
V_215 = 4 ;
V_216 = 9 ;
V_217 = 3 ;
V_218 = 8 ;
} else if ( ( V_213 > 5400000 && V_213 < 6200000 ) ||
( V_213 >= 4800000 && V_213 < 5400000 ) ) {
V_215 = 5 ;
V_216 = 11 ;
V_217 = 3 ;
V_218 = 9 ;
} else if ( V_213 == 5400000 ) {
V_215 = 3 ;
V_216 = 8 ;
V_217 = 1 ;
V_218 = 9 ;
} else {
F_80 ( L_30 ) ;
return false ;
}
if ( clock > 270000 )
V_219 = 0x18 ;
else if ( clock > 135000 )
V_219 = 0x0d ;
else if ( clock > 67000 )
V_219 = 0x07 ;
else if ( clock > 33000 )
V_219 = 0x04 ;
else
V_219 = 0x02 ;
V_6 -> V_176 = F_124 ( V_205 -> V_134 ) | F_125 ( V_205 -> V_135 ) ;
V_6 -> V_178 = V_205 -> V_209 ;
V_6 -> V_180 = F_126 ( V_205 -> V_208 ) ;
V_6 -> V_182 = V_205 -> V_211 ;
if ( V_205 -> V_212 )
V_6 -> V_184 = V_183 ;
V_6 -> V_188 = V_215 | F_127 ( V_216 ) ;
V_6 -> V_188 |= F_128 ( V_217 ) ;
V_6 -> V_190 = V_218 ;
V_6 -> V_192 = 5 << V_220 ;
V_6 -> V_195 =
F_129 ( V_221 )
| V_193 ;
V_6 -> V_197 = V_173 ;
V_6 -> V_203 = V_202 | V_219 ;
return true ;
}
bool F_130 ( int clock ,
struct V_5 * V_6 )
{
struct V_204 V_205 = { 0 } ;
F_122 ( clock , & V_205 ) ;
return F_123 ( clock , & V_205 , V_6 ) ;
}
static bool
F_131 ( struct V_31 * V_31 ,
struct V_44 * V_45 , int clock ,
struct V_5 * V_6 )
{
struct V_204 V_205 = { } ;
F_120 ( V_31 , V_45 , clock , & V_205 ) ;
return F_123 ( clock , & V_205 , V_6 ) ;
}
static struct V_1 *
F_132 ( struct V_31 * V_32 ,
struct V_44 * V_45 ,
struct V_62 * V_63 )
{
struct V_5 V_6 = { } ;
struct V_2 * V_3 = F_8 ( V_32 -> V_34 . V_22 ) ;
struct V_222 * V_223 ;
struct V_1 * V_4 ;
int V_8 , clock = V_45 -> V_104 ;
if ( V_63 -> type == V_105 &&
! F_131 ( V_32 , V_45 , clock ,
& V_6 ) )
return NULL ;
if ( ( V_63 -> type == V_106 ||
V_63 -> type == V_108 ||
V_63 -> type == V_107 ) &&
! F_130 ( clock , & V_6 ) )
return NULL ;
memset ( & V_45 -> V_6 , 0 ,
sizeof( V_45 -> V_6 ) ) ;
V_45 -> V_6 = V_6 ;
if ( V_63 -> type == V_107 ) {
struct V_224 * V_225 = F_133 ( & V_63 -> V_34 ) ;
V_223 = V_225 -> V_226 ;
} else
V_223 = F_134 ( & V_63 -> V_34 ) ;
V_8 = (enum V_7 ) V_223 -> V_165 ;
V_4 = F_9 ( V_3 , V_8 ) ;
F_22 ( L_12 ,
V_32 -> V_34 . V_34 . V_26 , V_32 -> V_34 . V_30 , V_4 -> V_30 ) ;
F_27 ( V_4 , V_45 ) ;
return V_4 ;
}
static void F_135 ( struct V_2 * V_3 ,
struct V_5 * V_15 )
{
F_22 ( L_31
L_32
L_33 ,
V_15 -> V_176 ,
V_15 -> V_197 ,
V_15 -> V_178 ,
V_15 -> V_180 ,
V_15 -> V_182 ,
V_15 -> V_184 ,
V_15 -> V_188 ,
V_15 -> V_190 ,
V_15 -> V_192 ,
V_15 -> V_195 ,
V_15 -> V_203 ) ;
}
static void F_136 ( struct V_33 * V_22 )
{
struct V_2 * V_3 = F_8 ( V_22 ) ;
if ( F_25 ( V_3 ) < 9 ) {
T_1 V_50 = F_33 ( V_227 ) ;
if ( V_50 & V_228 )
F_80 ( L_34 ) ;
if ( V_50 & V_229 )
F_80 ( L_35 ) ;
}
}
void F_137 ( struct V_33 * V_22 )
{
struct V_2 * V_3 = F_8 ( V_22 ) ;
const struct V_230 * V_231 = NULL ;
const struct V_232 * V_232 ;
int V_8 ;
if ( F_138 ( V_3 ) || F_139 ( V_3 ) )
V_231 = & V_233 ;
else if ( F_140 ( V_3 ) )
V_231 = & V_234 ;
else if ( F_141 ( V_3 ) )
V_231 = & V_235 ;
else if ( F_42 ( V_3 ) || F_43 ( V_3 ) )
V_231 = & V_236 ;
if ( ! V_231 ) {
V_3 -> V_18 = 0 ;
return;
}
V_232 = V_231 -> V_232 ;
for ( V_8 = 0 ; V_232 [ V_8 ] . V_26 >= 0 ; V_8 ++ ) {
F_6 ( V_8 != V_232 [ V_8 ] . V_26 ) ;
V_3 -> V_12 [ V_8 ] . V_26 = V_232 [ V_8 ] . V_26 ;
V_3 -> V_12 [ V_8 ] . V_30 = V_232 [ V_8 ] . V_30 ;
V_3 -> V_12 [ V_8 ] . V_28 = * V_232 [ V_8 ] . V_28 ;
V_3 -> V_12 [ V_8 ] . V_237 = V_232 [ V_8 ] . V_237 ;
}
V_3 -> V_231 = V_231 ;
V_3 -> V_18 = V_8 ;
F_142 ( & V_3 -> V_36 ) ;
F_143 ( V_3 -> V_18 > V_238 ) ;
if ( F_141 ( V_3 ) )
F_136 ( V_22 ) ;
}
struct V_1 *
F_144 ( struct V_31 * V_32 ,
struct V_44 * V_45 ,
struct V_62 * V_63 )
{
struct V_2 * V_3 = F_8 ( V_32 -> V_34 . V_22 ) ;
const struct V_230 * V_231 = V_3 -> V_231 ;
if ( F_6 ( ! V_231 ) )
return NULL ;
return V_231 -> V_239 ( V_32 , V_45 , V_63 ) ;
}
void F_145 ( struct V_1 * V_52 ,
struct V_31 * V_32 ,
struct V_19 * V_13 )
{
struct V_16 * V_240 ;
V_240 = F_4 ( V_13 ) ;
V_240 [ V_52 -> V_26 ] . V_14 &= ~ ( 1 << V_32 -> V_48 ) ;
}
void F_146 ( struct V_2 * V_3 ,
struct V_5 * V_15 )
{
if ( V_3 -> V_231 ) {
V_3 -> V_231 -> V_241 ( V_3 , V_15 ) ;
} else {
F_22 ( L_13
L_14 ,
V_15 -> V_52 ,
V_15 -> V_66 ,
V_15 -> V_53 ,
V_15 -> V_54 ) ;
}
}
