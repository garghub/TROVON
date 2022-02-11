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
struct V_1 *
F_3 ( struct V_2 * V_3 ,
enum V_7 V_16 )
{
return & V_3 -> V_12 [ V_16 ] ;
}
enum V_7
F_4 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
if ( F_5 ( V_4 < V_3 -> V_12 ||
V_4 > & V_3 -> V_12 [ V_3 -> V_17 ] ) )
return - 1 ;
return (enum V_7 ) ( V_4 - V_3 -> V_12 ) ;
}
void
F_6 ( struct V_18 * V_13 ,
struct V_1 * V_4 ,
struct V_19 * V_20 )
{
struct V_2 * V_3 = F_7 ( V_20 -> V_21 . V_22 ) ;
enum V_7 V_16 = F_4 ( V_3 , V_4 ) ;
V_13 [ V_16 ] . V_14 |= 1 << V_20 -> V_23 ;
}
void
F_8 ( struct V_18 * V_13 ,
struct V_1 * V_4 ,
struct V_19 * V_20 )
{
struct V_2 * V_3 = F_7 ( V_20 -> V_21 . V_22 ) ;
enum V_7 V_16 = F_4 ( V_3 , V_4 ) ;
V_13 [ V_16 ] . V_14 &= ~ ( 1 << V_20 -> V_23 ) ;
}
void F_9 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
bool V_24 )
{
bool V_25 ;
struct V_5 V_15 ;
if ( F_10 ( ! V_4 , L_1 , F_11 ( V_24 ) ) )
return;
V_25 = V_4 -> V_26 . V_27 ( V_3 , V_4 , & V_15 ) ;
F_12 ( V_25 != V_24 ,
L_2 ,
V_4 -> V_28 , F_11 ( V_24 ) , F_11 ( V_25 ) ) ;
}
void F_13 ( struct V_19 * V_20 )
{
struct V_29 * V_22 = V_20 -> V_21 . V_22 ;
struct V_2 * V_3 = F_7 ( V_22 ) ;
struct V_1 * V_4 = V_20 -> V_13 -> V_30 ;
if ( F_5 ( V_4 == NULL ) )
return;
F_14 ( & V_3 -> V_31 ) ;
F_5 ( ! V_4 -> V_13 . V_14 ) ;
if ( ! V_4 -> V_32 ) {
F_15 ( L_3 , V_4 -> V_28 ) ;
F_5 ( V_4 -> V_33 ) ;
F_16 ( V_3 , V_4 ) ;
V_4 -> V_26 . V_34 ( V_3 , V_4 ) ;
}
F_17 ( & V_3 -> V_31 ) ;
}
void F_18 ( struct V_19 * V_20 )
{
struct V_29 * V_22 = V_20 -> V_21 . V_22 ;
struct V_2 * V_3 = F_7 ( V_22 ) ;
struct V_1 * V_4 = V_20 -> V_13 -> V_30 ;
unsigned V_14 = 1 << F_19 ( & V_20 -> V_21 ) ;
unsigned V_35 ;
if ( F_5 ( V_4 == NULL ) )
return;
F_14 ( & V_3 -> V_31 ) ;
V_35 = V_4 -> V_32 ;
if ( F_5 ( ! ( V_4 -> V_13 . V_14 & V_14 ) ) ||
F_5 ( V_4 -> V_32 & V_14 ) )
goto V_36;
V_4 -> V_32 |= V_14 ;
F_20 ( L_4 ,
V_4 -> V_28 , V_4 -> V_32 , V_4 -> V_33 ,
V_20 -> V_21 . V_21 . V_16 ) ;
if ( V_35 ) {
F_5 ( ! V_4 -> V_33 ) ;
F_21 ( V_3 , V_4 ) ;
goto V_36;
}
F_5 ( V_4 -> V_33 ) ;
F_20 ( L_5 , V_4 -> V_28 ) ;
V_4 -> V_26 . V_37 ( V_3 , V_4 ) ;
V_4 -> V_33 = true ;
V_36:
F_17 ( & V_3 -> V_31 ) ;
}
void F_22 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_7 ( V_20 -> V_21 . V_22 ) ;
struct V_1 * V_4 = V_20 -> V_13 -> V_30 ;
unsigned V_14 = 1 << F_19 ( & V_20 -> V_21 ) ;
if ( F_23 ( V_3 ) < 5 )
return;
if ( V_4 == NULL )
return;
F_14 ( & V_3 -> V_31 ) ;
if ( F_5 ( ! ( V_4 -> V_32 & V_14 ) ) )
goto V_36;
F_20 ( L_6 ,
V_4 -> V_28 , V_4 -> V_32 , V_4 -> V_33 ,
V_20 -> V_21 . V_21 . V_16 ) ;
F_21 ( V_3 , V_4 ) ;
F_5 ( ! V_4 -> V_33 ) ;
V_4 -> V_32 &= ~ V_14 ;
if ( V_4 -> V_32 )
goto V_36;
F_20 ( L_7 , V_4 -> V_28 ) ;
V_4 -> V_26 . V_38 ( V_3 , V_4 ) ;
V_4 -> V_33 = false ;
V_36:
F_17 ( & V_3 -> V_31 ) ;
}
static struct V_1 *
F_24 ( struct V_19 * V_20 ,
struct V_39 * V_40 ,
enum V_7 V_41 ,
enum V_7 V_42 )
{
struct V_2 * V_3 = F_7 ( V_20 -> V_21 . V_22 ) ;
struct V_1 * V_4 ;
struct V_18 * V_30 ;
enum V_7 V_8 ;
V_30 = F_25 ( V_40 -> V_21 . V_24 ) ;
for ( V_8 = V_41 ; V_8 <= V_42 ; V_8 ++ ) {
V_4 = & V_3 -> V_12 [ V_8 ] ;
if ( V_30 [ V_8 ] . V_14 == 0 )
continue;
if ( memcmp ( & V_40 -> V_6 ,
& V_30 [ V_8 ] . V_15 ,
sizeof( V_40 -> V_6 ) ) == 0 ) {
F_20 ( L_8 ,
V_20 -> V_21 . V_21 . V_16 , V_20 -> V_21 . V_28 , V_4 -> V_28 ,
V_30 [ V_8 ] . V_14 ,
V_4 -> V_32 ) ;
return V_4 ;
}
}
for ( V_8 = V_41 ; V_8 <= V_42 ; V_8 ++ ) {
V_4 = & V_3 -> V_12 [ V_8 ] ;
if ( V_30 [ V_8 ] . V_14 == 0 ) {
F_20 ( L_9 ,
V_20 -> V_21 . V_21 . V_16 , V_20 -> V_21 . V_28 , V_4 -> V_28 ) ;
return V_4 ;
}
}
return NULL ;
}
static void
F_26 ( struct V_1 * V_4 ,
struct V_39 * V_40 )
{
struct V_18 * V_30 ;
struct V_19 * V_20 = F_27 ( V_40 -> V_21 . V_20 ) ;
enum V_7 V_8 = V_4 -> V_16 ;
V_30 = F_25 ( V_40 -> V_21 . V_24 ) ;
if ( V_30 [ V_8 ] . V_14 == 0 )
V_30 [ V_8 ] . V_15 =
V_40 -> V_6 ;
V_40 -> V_30 = V_4 ;
F_15 ( L_10 , V_4 -> V_28 ,
F_28 ( V_20 -> V_23 ) ) ;
F_6 ( V_30 , V_4 , V_20 ) ;
}
void F_29 ( struct V_43 * V_24 )
{
struct V_2 * V_3 = F_7 ( V_24 -> V_22 ) ;
struct V_18 * V_30 ;
struct V_1 * V_4 ;
enum V_7 V_8 ;
if ( ! F_30 ( V_24 ) -> V_44 )
return;
V_30 = F_30 ( V_24 ) -> V_30 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_17 ; V_8 ++ ) {
V_4 = & V_3 -> V_12 [ V_8 ] ;
V_4 -> V_13 = V_30 [ V_8 ] ;
}
}
static bool F_31 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_45 ;
if ( ! F_32 ( V_3 , V_46 ) )
return false ;
V_45 = F_33 ( F_34 ( V_4 -> V_16 ) ) ;
V_15 -> V_47 = V_45 ;
V_15 -> V_48 = F_33 ( F_35 ( V_4 -> V_16 ) ) ;
V_15 -> V_49 = F_33 ( F_36 ( V_4 -> V_16 ) ) ;
F_37 ( V_3 , V_46 ) ;
return V_45 & V_50 ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_39 ( F_35 ( V_4 -> V_16 ) , V_4 -> V_13 . V_15 . V_48 ) ;
F_39 ( F_36 ( V_4 -> V_16 ) , V_4 -> V_13 . V_15 . V_49 ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
T_2 V_45 ;
bool V_51 ;
F_41 ( ! ( F_42 ( V_3 ) || F_43 ( V_3 ) ) ) ;
V_45 = F_33 ( V_52 ) ;
V_51 = ! ! ( V_45 & ( V_53 | V_54 |
V_55 ) ) ;
F_12 ( ! V_51 , L_11 ) ;
}
static void F_44 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_40 ( V_3 ) ;
F_39 ( F_34 ( V_4 -> V_16 ) , V_4 -> V_13 . V_15 . V_47 ) ;
F_45 ( F_34 ( V_4 -> V_16 ) ) ;
F_46 ( 150 ) ;
F_39 ( F_34 ( V_4 -> V_16 ) , V_4 -> V_13 . V_15 . V_47 ) ;
F_45 ( F_34 ( V_4 -> V_16 ) ) ;
F_46 ( 200 ) ;
}
static void F_47 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_29 * V_22 = & V_3 -> V_56 ;
struct V_19 * V_20 ;
F_48 (dev, crtc) {
if ( V_20 -> V_13 -> V_30 == V_4 )
F_49 ( V_3 , V_20 -> V_23 ) ;
}
F_39 ( F_34 ( V_4 -> V_16 ) , 0 ) ;
F_45 ( F_34 ( V_4 -> V_16 ) ) ;
F_46 ( 200 ) ;
}
static struct V_1 *
F_50 ( struct V_19 * V_20 , struct V_39 * V_40 ,
struct V_57 * V_58 )
{
struct V_2 * V_3 = F_7 ( V_20 -> V_21 . V_22 ) ;
struct V_1 * V_4 ;
enum V_7 V_8 ;
if ( F_42 ( V_3 ) ) {
V_8 = (enum V_7 ) V_20 -> V_23 ;
V_4 = & V_3 -> V_12 [ V_8 ] ;
F_20 ( L_12 ,
V_20 -> V_21 . V_21 . V_16 , V_20 -> V_21 . V_28 , V_4 -> V_28 ) ;
} else {
V_4 = F_24 ( V_20 , V_40 ,
V_59 ,
V_60 ) ;
}
if ( ! V_4 )
return NULL ;
F_26 ( V_4 , V_40 ) ;
return V_4 ;
}
static void F_51 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_39 ( F_52 ( V_4 -> V_16 ) , V_4 -> V_13 . V_15 . V_61 ) ;
F_45 ( F_52 ( V_4 -> V_16 ) ) ;
F_46 ( 20 ) ;
}
static void F_53 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_39 ( V_62 , V_4 -> V_13 . V_15 . V_63 ) ;
F_45 ( V_62 ) ;
F_46 ( 20 ) ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_45 ;
V_45 = F_33 ( F_52 ( V_4 -> V_16 ) ) ;
F_39 ( F_52 ( V_4 -> V_16 ) , V_45 & ~ V_64 ) ;
F_45 ( F_52 ( V_4 -> V_16 ) ) ;
}
static void F_55 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_45 ;
V_45 = F_33 ( V_62 ) ;
F_39 ( V_62 , V_45 & ~ V_65 ) ;
F_45 ( V_62 ) ;
}
static bool F_56 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_45 ;
if ( ! F_32 ( V_3 , V_46 ) )
return false ;
V_45 = F_33 ( F_52 ( V_4 -> V_16 ) ) ;
V_15 -> V_61 = V_45 ;
F_37 ( V_3 , V_46 ) ;
return V_45 & V_64 ;
}
static bool F_57 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_45 ;
if ( ! F_32 ( V_3 , V_46 ) )
return false ;
V_45 = F_33 ( V_62 ) ;
V_15 -> V_63 = V_45 ;
F_37 ( V_3 , V_46 ) ;
return V_45 & V_65 ;
}
static unsigned F_58 ( int clock )
{
unsigned V_66 ;
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
V_66 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_66 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_66 = 2000 ;
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
V_66 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_66 = 5000 ;
break;
default:
V_66 = 1000 ;
break;
}
return V_66 ;
}
static void F_59 ( T_3 V_67 , unsigned V_66 ,
unsigned V_68 , unsigned V_69 , unsigned V_70 ,
struct V_71 * V_72 )
{
T_3 V_73 , V_74 , V_75 , V_76 , V_77 , V_78 ;
if ( V_72 -> V_70 == 0 ) {
V_72 -> V_70 = V_70 ;
V_72 -> V_69 = V_69 ;
V_72 -> V_68 = V_68 ;
return;
}
V_73 = V_67 * V_66 * V_70 * V_68 ;
V_74 = V_67 * V_66 * V_72 -> V_70 * V_72 -> V_68 ;
V_77 = F_60 ( V_67 * V_70 * V_68 , V_79 * V_69 ) ;
V_78 = F_60 ( V_67 * V_72 -> V_70 * V_72 -> V_68 ,
V_79 * V_72 -> V_69 ) ;
V_75 = 1000000 * V_77 ;
V_76 = 1000000 * V_78 ;
if ( V_73 < V_75 && V_74 < V_76 ) {
if ( V_72 -> V_70 * V_72 -> V_68 * V_77 < V_70 * V_68 * V_78 ) {
V_72 -> V_70 = V_70 ;
V_72 -> V_69 = V_69 ;
V_72 -> V_68 = V_68 ;
}
} else if ( V_73 >= V_75 && V_74 < V_76 ) {
V_72 -> V_70 = V_70 ;
V_72 -> V_69 = V_69 ;
V_72 -> V_68 = V_68 ;
} else if ( V_73 >= V_75 && V_74 >= V_76 ) {
if ( V_69 * V_72 -> V_68 * V_72 -> V_68 > V_72 -> V_69 * V_68 * V_68 ) {
V_72 -> V_70 = V_70 ;
V_72 -> V_69 = V_69 ;
V_72 -> V_68 = V_68 ;
}
}
}
static void
F_61 ( int clock ,
unsigned * V_80 , unsigned * V_81 , unsigned * V_82 )
{
T_3 V_67 ;
unsigned V_70 , V_69 , V_68 ;
struct V_71 V_72 = { 0 , 0 , 0 } ;
unsigned V_66 ;
V_67 = clock / 100 ;
V_66 = F_58 ( clock ) ;
if ( V_67 == 5400000 ) {
* V_81 = 2 ;
* V_82 = 1 ;
* V_80 = 2 ;
return;
}
for ( V_68 = V_83 * 2 / V_84 + 1 ;
V_68 <= V_83 * 2 / V_85 ;
V_68 ++ ) {
for ( V_69 = V_86 * V_68 / V_83 + 1 ;
V_69 <= V_87 * V_68 / V_83 ;
V_69 ++ ) {
for ( V_70 = V_88 ; V_70 <= V_89 ; V_70 += V_90 )
F_59 ( V_67 , V_66 ,
V_68 , V_69 , V_70 , & V_72 ) ;
}
}
* V_81 = V_72 . V_69 ;
* V_82 = V_72 . V_70 ;
* V_80 = V_72 . V_68 ;
}
static struct V_1 * F_62 ( int clock ,
struct V_19 * V_20 ,
struct V_39 * V_40 )
{
struct V_1 * V_4 ;
T_1 V_45 ;
unsigned int V_70 , V_69 , V_68 ;
F_61 ( clock * 1000 , & V_68 , & V_69 , & V_70 ) ;
V_45 = V_64 | V_91 |
F_63 ( V_68 ) | F_64 ( V_69 ) |
F_65 ( V_70 ) ;
V_40 -> V_6 . V_61 = V_45 ;
V_4 = F_24 ( V_20 , V_40 ,
V_92 , V_93 ) ;
if ( ! V_4 )
return NULL ;
return V_4 ;
}
struct V_1 * F_66 ( struct V_57 * V_58 ,
int clock )
{
struct V_2 * V_3 = F_7 ( V_58 -> V_21 . V_22 ) ;
struct V_1 * V_4 ;
enum V_7 V_94 ;
switch ( clock / 2 ) {
case 81000 :
V_94 = V_95 ;
break;
case 135000 :
V_94 = V_96 ;
break;
case 270000 :
V_94 = V_97 ;
break;
default:
F_20 ( L_13 , clock ) ;
return NULL ;
}
V_4 = F_3 ( V_3 , V_94 ) ;
if ( ! V_4 )
return NULL ;
return V_4 ;
}
static struct V_1 *
F_67 ( struct V_19 * V_20 , struct V_39 * V_40 ,
struct V_57 * V_58 )
{
struct V_1 * V_4 ;
int clock = V_40 -> V_98 ;
memset ( & V_40 -> V_6 , 0 ,
sizeof( V_40 -> V_6 ) ) ;
if ( V_58 -> type == V_99 ) {
V_4 = F_62 ( clock , V_20 , V_40 ) ;
} else if ( V_58 -> type == V_100 ||
V_58 -> type == V_101 ||
V_58 -> type == V_102 ) {
V_4 = F_66 ( V_58 , clock ) ;
} else if ( V_58 -> type == V_103 ) {
if ( F_5 ( V_40 -> V_98 / 2 != 135000 ) )
return NULL ;
V_40 -> V_6 . V_63 =
V_65 | V_104 | V_105 ;
V_4 = F_24 ( V_20 , V_40 ,
V_106 , V_106 ) ;
} else {
return NULL ;
}
if ( ! V_4 )
return NULL ;
F_26 ( V_4 , V_40 ) ;
return V_4 ;
}
static void F_68 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
}
static void F_69 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
}
static bool F_70 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
return true ;
}
static void F_71 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_45 ;
V_45 = F_33 ( V_107 ) ;
V_45 &= ~ ( F_72 ( V_4 -> V_16 ) | F_73 ( V_4 -> V_16 ) |
F_74 ( V_4 -> V_16 ) ) ;
V_45 |= V_4 -> V_13 . V_15 . V_108 << ( V_4 -> V_16 * 6 ) ;
F_39 ( V_107 , V_45 ) ;
F_45 ( V_107 ) ;
}
static void F_75 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
const struct V_109 * V_110 = V_109 ;
F_71 ( V_3 , V_4 ) ;
F_39 ( V_110 [ V_4 -> V_16 ] . V_111 , V_4 -> V_13 . V_15 . V_111 ) ;
F_39 ( V_110 [ V_4 -> V_16 ] . V_112 , V_4 -> V_13 . V_15 . V_112 ) ;
F_45 ( V_110 [ V_4 -> V_16 ] . V_111 ) ;
F_45 ( V_110 [ V_4 -> V_16 ] . V_112 ) ;
F_39 ( V_110 [ V_4 -> V_16 ] . V_113 ,
F_33 ( V_110 [ V_4 -> V_16 ] . V_113 ) | V_114 ) ;
if ( F_76 ( V_3 ,
V_115 ,
F_77 ( V_4 -> V_16 ) ,
F_77 ( V_4 -> V_16 ) ,
5 ) )
F_78 ( L_14 , V_4 -> V_16 ) ;
}
static void F_79 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_71 ( V_3 , V_4 ) ;
}
static void F_80 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
const struct V_109 * V_110 = V_109 ;
F_39 ( V_110 [ V_4 -> V_16 ] . V_113 ,
F_33 ( V_110 [ V_4 -> V_16 ] . V_113 ) & ~ V_114 ) ;
F_45 ( V_110 [ V_4 -> V_16 ] . V_113 ) ;
}
static void F_81 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
}
static bool F_82 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_45 ;
const struct V_109 * V_110 = V_109 ;
bool V_116 ;
if ( ! F_32 ( V_3 , V_46 ) )
return false ;
V_116 = false ;
V_45 = F_33 ( V_110 [ V_4 -> V_16 ] . V_113 ) ;
if ( ! ( V_45 & V_114 ) )
goto V_36;
V_45 = F_33 ( V_107 ) ;
V_15 -> V_108 = ( V_45 >> ( V_4 -> V_16 * 6 ) ) & 0x3f ;
if ( V_45 & F_72 ( V_4 -> V_16 ) ) {
V_15 -> V_111 = F_33 ( V_110 [ V_4 -> V_16 ] . V_111 ) ;
V_15 -> V_112 = F_33 ( V_110 [ V_4 -> V_16 ] . V_112 ) ;
}
V_116 = true ;
V_36:
F_37 ( V_3 , V_46 ) ;
return V_116 ;
}
static bool F_83 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_45 ;
const struct V_109 * V_110 = V_109 ;
bool V_116 ;
if ( ! F_32 ( V_3 , V_46 ) )
return false ;
V_116 = false ;
V_45 = F_33 ( V_110 [ V_4 -> V_16 ] . V_113 ) ;
if ( F_5 ( ! ( V_45 & V_114 ) ) )
goto V_36;
V_45 = F_33 ( V_107 ) ;
V_15 -> V_108 = ( V_45 >> ( V_4 -> V_16 * 6 ) ) & 0x3f ;
V_116 = true ;
V_36:
F_37 ( V_3 , V_46 ) ;
return V_116 ;
}
static void F_84 ( struct V_117 * V_118 )
{
memset ( V_118 , 0 , sizeof( * V_118 ) ) ;
V_118 -> V_119 = V_120 ;
}
static void F_85 ( struct V_117 * V_118 ,
T_3 V_121 ,
T_3 V_122 ,
unsigned int V_123 )
{
T_3 V_124 ;
V_124 = F_86 ( 10000 * F_60 ( V_122 , V_121 ) ,
V_121 ) ;
if ( V_122 >= V_121 ) {
if ( V_124 < V_125 &&
V_124 < V_118 -> V_119 ) {
V_118 -> V_119 = V_124 ;
V_118 -> V_121 = V_121 ;
V_118 -> V_122 = V_122 ;
V_118 -> V_70 = V_123 ;
}
} else if ( V_124 < V_126 &&
V_124 < V_118 -> V_119 ) {
V_118 -> V_119 = V_124 ;
V_118 -> V_121 = V_121 ;
V_118 -> V_122 = V_122 ;
V_118 -> V_70 = V_123 ;
}
}
static void F_87 ( unsigned int V_70 ,
unsigned int * V_127 ,
unsigned int * V_128 ,
unsigned int * V_129 )
{
if ( V_70 % 2 == 0 ) {
unsigned int V_130 = V_70 / 2 ;
if ( V_130 == 1 || V_130 == 2 || V_130 == 3 || V_130 == 5 ) {
* V_127 = 2 ;
* V_128 = 1 ;
* V_129 = V_130 ;
} else if ( V_130 % 2 == 0 ) {
* V_127 = 2 ;
* V_128 = V_130 / 2 ;
* V_129 = 2 ;
} else if ( V_130 % 3 == 0 ) {
* V_127 = 3 ;
* V_128 = V_130 / 3 ;
* V_129 = 2 ;
} else if ( V_130 % 7 == 0 ) {
* V_127 = 7 ;
* V_128 = V_130 / 7 ;
* V_129 = 2 ;
}
} else if ( V_70 == 3 || V_70 == 9 ) {
* V_127 = 3 ;
* V_128 = 1 ;
* V_129 = V_70 / 3 ;
} else if ( V_70 == 5 || V_70 == 7 ) {
* V_127 = V_70 ;
* V_128 = 1 ;
* V_129 = 1 ;
} else if ( V_70 == 15 ) {
* V_127 = 3 ;
* V_128 = 1 ;
* V_129 = 5 ;
} else if ( V_70 == 21 ) {
* V_127 = 7 ;
* V_128 = 1 ;
* V_129 = 3 ;
} else if ( V_70 == 35 ) {
* V_127 = 7 ;
* V_128 = 1 ;
* V_129 = 5 ;
}
}
static void F_88 ( struct V_131 * V_132 ,
T_3 V_133 ,
T_3 V_121 ,
T_1 V_127 , T_1 V_128 , T_1 V_129 )
{
T_3 V_122 ;
switch ( V_121 ) {
case 9600000000ULL :
V_132 -> V_121 = 0 ;
break;
case 9000000000ULL :
V_132 -> V_121 = 1 ;
break;
case 8400000000ULL :
V_132 -> V_121 = 3 ;
}
switch ( V_127 ) {
case 1 :
V_132 -> V_134 = 0 ;
break;
case 2 :
V_132 -> V_134 = 1 ;
break;
case 3 :
V_132 -> V_134 = 2 ;
break;
case 7 :
V_132 -> V_134 = 4 ;
break;
default:
F_10 ( 1 , L_15 ) ;
}
switch ( V_129 ) {
case 5 :
V_132 -> V_135 = 0 ;
break;
case 2 :
V_132 -> V_135 = 1 ;
break;
case 3 :
V_132 -> V_135 = 2 ;
break;
case 1 :
V_132 -> V_135 = 3 ;
break;
default:
F_10 ( 1 , L_16 ) ;
}
V_132 -> V_136 = V_128 ;
V_132 -> V_137 = ( V_132 -> V_136 == 1 ) ? 0 : 1 ;
V_122 = V_127 * V_128 * V_129 * V_133 ;
V_132 -> V_138 = F_89 ( V_122 , 24 * F_90 ( 1 ) ) ;
V_132 -> V_139 =
F_89 ( ( F_89 ( V_122 , 24 ) -
V_132 -> V_138 * F_90 ( 1 ) ) * 0x8000 , F_90 ( 1 ) ) ;
}
static bool
F_91 ( int clock ,
struct V_131 * V_140 )
{
T_3 V_133 = clock * 5 ;
T_3 V_141 [ 3 ] = { 8400000000ULL ,
9000000000ULL ,
9600000000ULL } ;
static const int V_142 [] = { 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20 ,
24 , 28 , 30 , 32 , 36 , 40 , 42 , 44 ,
48 , 52 , 54 , 56 , 60 , 64 , 66 , 68 ,
70 , 72 , 76 , 78 , 80 , 84 , 88 , 90 ,
92 , 96 , 98 } ;
static const int V_143 [] = { 3 , 5 , 7 , 9 , 15 , 21 , 35 } ;
static const struct {
const int * V_144 ;
int V_145 ;
} V_146 [] = {
{ V_142 , F_92 (even_dividers) } ,
{ V_143 , F_92 (odd_dividers) } ,
} ;
struct V_117 V_118 ;
unsigned int V_147 , V_76 , V_8 ;
unsigned int V_127 , V_128 , V_129 ;
F_84 ( & V_118 ) ;
for ( V_76 = 0 ; V_76 < F_92 ( V_146 ) ; V_76 ++ ) {
for ( V_147 = 0 ; V_147 < F_92 ( V_141 ) ; V_147 ++ ) {
for ( V_8 = 0 ; V_8 < V_146 [ V_76 ] . V_145 ; V_8 ++ ) {
unsigned int V_70 = V_146 [ V_76 ] . V_144 [ V_8 ] ;
T_3 V_122 = V_70 * V_133 ;
F_85 ( & V_118 ,
V_141 [ V_147 ] ,
V_122 ,
V_70 ) ;
if ( V_118 . V_119 == 0 )
goto V_148;
}
}
V_148:
if ( V_76 == 0 && V_118 . V_70 )
break;
}
if ( ! V_118 . V_70 ) {
F_15 ( L_17 , clock ) ;
return false ;
}
V_127 = V_128 = V_129 = 0 ;
F_87 ( V_118 . V_70 , & V_127 , & V_128 , & V_129 ) ;
F_88 ( V_140 , V_133 , V_118 . V_121 ,
V_127 , V_128 , V_129 ) ;
return true ;
}
static bool F_93 ( struct V_19 * V_20 ,
struct V_39 * V_40 ,
int clock )
{
T_1 V_108 , V_111 , V_112 ;
struct V_131 V_140 = { 0 , } ;
V_108 = F_94 ( 0 ) ;
V_108 |= F_72 ( 0 ) ;
if ( ! F_91 ( clock * 1000 , & V_140 ) )
return false ;
V_111 = V_149 |
F_95 ( V_140 . V_139 ) |
V_140 . V_138 ;
V_112 = F_96 ( V_140 . V_136 ) |
F_97 ( V_140 . V_137 ) |
F_98 ( V_140 . V_135 ) |
F_99 ( V_140 . V_134 ) |
V_140 . V_121 ;
memset ( & V_40 -> V_6 , 0 ,
sizeof( V_40 -> V_6 ) ) ;
V_40 -> V_6 . V_108 = V_108 ;
V_40 -> V_6 . V_111 = V_111 ;
V_40 -> V_6 . V_112 = V_112 ;
return true ;
}
bool F_2 ( int clock ,
struct V_5 * V_6 )
{
T_1 V_108 ;
V_108 = F_94 ( 0 ) ;
switch ( clock / 2 ) {
case 81000 :
V_108 |= F_100 ( V_150 , 0 ) ;
break;
case 135000 :
V_108 |= F_100 ( V_151 , 0 ) ;
break;
case 270000 :
V_108 |= F_100 ( V_152 , 0 ) ;
break;
case 162000 :
V_108 |= F_100 ( V_153 , 0 ) ;
break;
case 108000 :
V_108 |= F_100 ( V_154 , 0 ) ;
break;
case 216000 :
V_108 |= F_100 ( V_155 , 0 ) ;
break;
}
V_6 -> V_108 = V_108 ;
return true ;
}
static struct V_1 *
F_101 ( struct V_19 * V_20 , struct V_39 * V_40 ,
struct V_57 * V_58 )
{
struct V_1 * V_4 ;
int clock = V_40 -> V_98 ;
bool V_156 ;
struct V_5 V_6 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
if ( V_58 -> type == V_99 ) {
V_156 = F_93 ( V_20 , V_40 , clock ) ;
if ( ! V_156 ) {
F_20 ( L_18 ) ;
return NULL ;
}
} else if ( V_58 -> type == V_100 ||
V_58 -> type == V_101 ||
V_58 -> type == V_102 ) {
V_156 = F_2 ( clock , & V_6 ) ;
if ( ! V_156 ) {
F_20 ( L_19 ) ;
return NULL ;
}
V_40 -> V_6 = V_6 ;
} else {
return NULL ;
}
if ( V_58 -> type == V_102 )
V_4 = F_24 ( V_20 , V_40 ,
V_157 ,
V_157 ) ;
else
V_4 = F_24 ( V_20 , V_40 ,
V_10 ,
V_11 ) ;
if ( ! V_4 )
return NULL ;
F_26 ( V_4 , V_40 ) ;
return V_4 ;
}
static void F_102 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_158 ;
enum V_159 V_159 = (enum V_159 ) V_4 -> V_16 ;
enum V_160 V_161 ;
enum V_162 V_163 ;
F_103 ( V_159 , & V_161 , & V_163 ) ;
V_158 = F_33 ( F_104 ( V_159 ) ) ;
V_158 |= V_164 ;
F_39 ( F_104 ( V_159 ) , V_158 ) ;
V_158 = F_33 ( F_105 ( V_161 , V_163 ) ) ;
V_158 &= ~ V_165 ;
F_39 ( F_105 ( V_161 , V_163 ) , V_158 ) ;
V_158 = F_33 ( F_106 ( V_161 , V_163 ) ) ;
V_158 &= ~ ( V_166 | V_167 ) ;
V_158 |= V_4 -> V_13 . V_15 . V_168 ;
F_39 ( F_106 ( V_161 , V_163 ) , V_158 ) ;
V_158 = F_33 ( F_107 ( V_161 , V_163 , 0 ) ) ;
V_158 &= ~ V_169 ;
V_158 |= V_4 -> V_13 . V_15 . V_170 ;
F_39 ( F_107 ( V_161 , V_163 , 0 ) , V_158 ) ;
V_158 = F_33 ( F_107 ( V_161 , V_163 , 1 ) ) ;
V_158 &= ~ V_171 ;
V_158 |= V_4 -> V_13 . V_15 . V_172 ;
F_39 ( F_107 ( V_161 , V_163 , 1 ) , V_158 ) ;
V_158 = F_33 ( F_107 ( V_161 , V_163 , 2 ) ) ;
V_158 &= ~ V_173 ;
V_158 |= V_4 -> V_13 . V_15 . V_174 ;
F_39 ( F_107 ( V_161 , V_163 , 2 ) , V_158 ) ;
V_158 = F_33 ( F_107 ( V_161 , V_163 , 3 ) ) ;
V_158 &= ~ V_175 ;
V_158 |= V_4 -> V_13 . V_15 . V_176 ;
F_39 ( F_107 ( V_161 , V_163 , 3 ) , V_158 ) ;
V_158 = F_33 ( F_107 ( V_161 , V_163 , 6 ) ) ;
V_158 &= ~ V_177 ;
V_158 &= ~ V_178 ;
V_158 &= ~ V_179 ;
V_158 |= V_4 -> V_13 . V_15 . V_180 ;
F_39 ( F_107 ( V_161 , V_163 , 6 ) , V_158 ) ;
V_158 = F_33 ( F_107 ( V_161 , V_163 , 8 ) ) ;
V_158 &= ~ V_181 ;
V_158 |= V_4 -> V_13 . V_15 . V_182 ;
F_39 ( F_107 ( V_161 , V_163 , 8 ) , V_158 ) ;
V_158 = F_33 ( F_107 ( V_161 , V_163 , 9 ) ) ;
V_158 &= ~ V_183 ;
V_158 |= V_4 -> V_13 . V_15 . V_184 ;
F_39 ( F_107 ( V_161 , V_163 , 9 ) , V_158 ) ;
V_158 = F_33 ( F_107 ( V_161 , V_163 , 10 ) ) ;
V_158 &= ~ V_185 ;
V_158 &= ~ V_186 ;
V_158 |= V_4 -> V_13 . V_15 . V_187 ;
F_39 ( F_107 ( V_161 , V_163 , 10 ) , V_158 ) ;
V_158 = F_33 ( F_105 ( V_161 , V_163 ) ) ;
V_158 |= V_188 ;
F_39 ( F_105 ( V_161 , V_163 ) , V_158 ) ;
V_158 &= ~ V_165 ;
V_158 |= V_4 -> V_13 . V_15 . V_189 ;
F_39 ( F_105 ( V_161 , V_163 ) , V_158 ) ;
V_158 = F_33 ( F_104 ( V_159 ) ) ;
V_158 |= V_190 ;
F_39 ( F_104 ( V_159 ) , V_158 ) ;
F_45 ( F_104 ( V_159 ) ) ;
if ( F_108 ( ( F_33 ( F_104 ( V_159 ) ) & V_191 ) ,
200 ) )
F_78 ( L_20 , V_159 ) ;
V_158 = F_33 ( F_109 ( V_161 , V_163 ) ) ;
V_158 &= ~ V_192 ;
V_158 &= ~ V_193 ;
V_158 |= V_4 -> V_13 . V_15 . V_194 ;
F_39 ( F_110 ( V_161 , V_163 ) , V_158 ) ;
}
static void F_111 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
enum V_159 V_159 = (enum V_159 ) V_4 -> V_16 ;
T_1 V_158 ;
V_158 = F_33 ( F_104 ( V_159 ) ) ;
V_158 &= ~ V_190 ;
F_39 ( F_104 ( V_159 ) , V_158 ) ;
F_45 ( F_104 ( V_159 ) ) ;
}
static bool F_112 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
enum V_159 V_159 = (enum V_159 ) V_4 -> V_16 ;
T_1 V_45 ;
bool V_116 ;
enum V_160 V_161 ;
enum V_162 V_163 ;
F_103 ( V_159 , & V_161 , & V_163 ) ;
if ( ! F_32 ( V_3 , V_46 ) )
return false ;
V_116 = false ;
V_45 = F_33 ( F_104 ( V_159 ) ) ;
if ( ! ( V_45 & V_190 ) )
goto V_36;
V_15 -> V_168 = F_33 ( F_106 ( V_161 , V_163 ) ) ;
V_15 -> V_168 &= V_166 | V_167 ;
V_15 -> V_189 = F_33 ( F_105 ( V_161 , V_163 ) ) ;
V_15 -> V_189 &= V_165 ;
V_15 -> V_170 = F_33 ( F_107 ( V_161 , V_163 , 0 ) ) ;
V_15 -> V_170 &= V_169 ;
V_15 -> V_172 = F_33 ( F_107 ( V_161 , V_163 , 1 ) ) ;
V_15 -> V_172 &= V_171 ;
V_15 -> V_174 = F_33 ( F_107 ( V_161 , V_163 , 2 ) ) ;
V_15 -> V_174 &= V_173 ;
V_15 -> V_176 = F_33 ( F_107 ( V_161 , V_163 , 3 ) ) ;
V_15 -> V_176 &= V_175 ;
V_15 -> V_180 = F_33 ( F_107 ( V_161 , V_163 , 6 ) ) ;
V_15 -> V_180 &= V_177 |
V_178 |
V_179 ;
V_15 -> V_182 = F_33 ( F_107 ( V_161 , V_163 , 8 ) ) ;
V_15 -> V_182 &= V_181 ;
V_15 -> V_184 = F_33 ( F_107 ( V_161 , V_163 , 9 ) ) ;
V_15 -> V_184 &= V_183 ;
V_15 -> V_187 = F_33 ( F_107 ( V_161 , V_163 , 10 ) ) ;
V_15 -> V_187 &= V_185 |
V_186 ;
V_15 -> V_194 = F_33 ( F_109 ( V_161 , V_163 ) ) ;
if ( F_33 ( F_113 ( V_161 , V_163 ) ) != V_15 -> V_194 )
F_15 ( L_21 ,
V_15 -> V_194 ,
F_33 ( F_113 ( V_161 , V_163 ) ) ) ;
V_15 -> V_194 &= V_192 | V_193 ;
V_116 = true ;
V_36:
F_37 ( V_3 , V_46 ) ;
return V_116 ;
}
static bool
F_114 ( struct V_19 * V_19 ,
struct V_39 * V_40 , int clock ,
struct V_195 * V_196 )
{
struct V_47 V_197 ;
if ( ! F_115 ( V_40 , clock , & V_197 ) ) {
F_15 ( L_22 ,
clock , F_28 ( V_19 -> V_23 ) ) ;
return false ;
}
V_196 -> V_128 = V_197 . V_128 ;
V_196 -> V_129 = V_197 . V_129 ;
F_5 ( V_197 . V_198 != 2 ) ;
V_196 -> V_199 = V_197 . V_199 ;
V_196 -> V_200 = V_197 . V_201 >> 22 ;
V_196 -> V_202 = V_197 . V_201 & ( ( 1 << 22 ) - 1 ) ;
V_196 -> V_203 = V_196 -> V_202 != 0 ;
V_196 -> V_204 = V_197 . V_204 ;
return true ;
}
static void F_116 ( int clock , struct V_195 * V_196 )
{
int V_8 ;
* V_196 = V_205 [ 0 ] ;
for ( V_8 = 0 ; V_8 < F_92 ( V_205 ) ; ++ V_8 ) {
if ( V_205 [ V_8 ] . clock == clock ) {
* V_196 = V_205 [ V_8 ] ;
break;
}
}
V_196 -> V_204 = clock * 10 / 2 * V_196 -> V_128 * V_196 -> V_129 ;
}
static bool F_117 ( int clock ,
struct V_195 * V_196 ,
struct V_5 * V_6 )
{
int V_204 = V_196 -> V_204 ;
T_1 V_206 , V_207 , V_208 , V_209 ;
T_1 V_210 ;
if ( V_204 >= 6200000 && V_204 <= 6700000 ) {
V_206 = 4 ;
V_207 = 9 ;
V_208 = 3 ;
V_209 = 8 ;
} else if ( ( V_204 > 5400000 && V_204 < 6200000 ) ||
( V_204 >= 4800000 && V_204 < 5400000 ) ) {
V_206 = 5 ;
V_207 = 11 ;
V_208 = 3 ;
V_209 = 9 ;
} else if ( V_204 == 5400000 ) {
V_206 = 3 ;
V_207 = 8 ;
V_208 = 1 ;
V_209 = 9 ;
} else {
F_78 ( L_23 ) ;
return false ;
}
if ( clock > 270000 )
V_210 = 0x18 ;
else if ( clock > 135000 )
V_210 = 0x0d ;
else if ( clock > 67000 )
V_210 = 0x07 ;
else if ( clock > 33000 )
V_210 = 0x04 ;
else
V_210 = 0x02 ;
V_6 -> V_168 = F_118 ( V_196 -> V_128 ) | F_119 ( V_196 -> V_129 ) ;
V_6 -> V_170 = V_196 -> V_200 ;
V_6 -> V_172 = F_120 ( V_196 -> V_199 ) ;
V_6 -> V_174 = V_196 -> V_202 ;
if ( V_196 -> V_203 )
V_6 -> V_176 = V_175 ;
V_6 -> V_180 = V_206 | F_121 ( V_207 ) ;
V_6 -> V_180 |= F_122 ( V_208 ) ;
V_6 -> V_182 = V_209 ;
V_6 -> V_184 = 5 << V_211 ;
V_6 -> V_187 =
F_123 ( V_212 )
| V_185 ;
V_6 -> V_189 = V_165 ;
V_6 -> V_194 = V_193 | V_210 ;
return true ;
}
bool F_124 ( int clock ,
struct V_5 * V_6 )
{
struct V_195 V_196 = { 0 } ;
F_116 ( clock , & V_196 ) ;
return F_117 ( clock , & V_196 , V_6 ) ;
}
static bool
F_125 ( struct V_19 * V_19 ,
struct V_39 * V_40 , int clock ,
struct V_5 * V_6 )
{
struct V_195 V_196 = { } ;
F_114 ( V_19 , V_40 , clock , & V_196 ) ;
return F_117 ( clock , & V_196 , V_6 ) ;
}
static struct V_1 *
F_126 ( struct V_19 * V_20 ,
struct V_39 * V_40 ,
struct V_57 * V_58 )
{
struct V_5 V_6 = { } ;
struct V_2 * V_3 = F_7 ( V_20 -> V_21 . V_22 ) ;
struct V_213 * V_214 ;
struct V_1 * V_4 ;
int V_8 , clock = V_40 -> V_98 ;
if ( V_58 -> type == V_99 &&
! F_125 ( V_20 , V_40 , clock ,
& V_6 ) )
return NULL ;
if ( ( V_58 -> type == V_100 ||
V_58 -> type == V_102 ||
V_58 -> type == V_101 ) &&
! F_124 ( clock , & V_6 ) )
return NULL ;
memset ( & V_40 -> V_6 , 0 ,
sizeof( V_40 -> V_6 ) ) ;
V_40 -> V_6 = V_6 ;
if ( V_58 -> type == V_101 ) {
struct V_215 * V_216 = F_127 ( & V_58 -> V_21 ) ;
V_214 = V_216 -> V_217 ;
} else
V_214 = F_128 ( & V_58 -> V_21 ) ;
V_8 = (enum V_7 ) V_214 -> V_159 ;
V_4 = F_3 ( V_3 , V_8 ) ;
F_20 ( L_12 ,
V_20 -> V_21 . V_21 . V_16 , V_20 -> V_21 . V_28 , V_4 -> V_28 ) ;
F_26 ( V_4 , V_40 ) ;
return V_4 ;
}
static void F_129 ( struct V_29 * V_22 )
{
struct V_2 * V_3 = F_7 ( V_22 ) ;
if ( F_23 ( V_3 ) < 9 ) {
T_1 V_45 = F_33 ( V_218 ) ;
if ( V_45 & V_219 )
F_78 ( L_24 ) ;
if ( V_45 & V_220 )
F_78 ( L_25 ) ;
}
}
void F_130 ( struct V_29 * V_22 )
{
struct V_2 * V_3 = F_7 ( V_22 ) ;
const struct V_221 * V_222 = NULL ;
const struct V_223 * V_223 ;
int V_8 ;
if ( F_131 ( V_3 ) || F_132 ( V_3 ) )
V_222 = & V_224 ;
else if ( F_133 ( V_3 ) )
V_222 = & V_225 ;
else if ( F_134 ( V_3 ) )
V_222 = & V_226 ;
else if ( F_42 ( V_3 ) || F_43 ( V_3 ) )
V_222 = & V_227 ;
if ( ! V_222 ) {
V_3 -> V_17 = 0 ;
return;
}
V_223 = V_222 -> V_223 ;
for ( V_8 = 0 ; V_223 [ V_8 ] . V_16 >= 0 ; V_8 ++ ) {
F_5 ( V_8 != V_223 [ V_8 ] . V_16 ) ;
V_3 -> V_12 [ V_8 ] . V_16 = V_223 [ V_8 ] . V_16 ;
V_3 -> V_12 [ V_8 ] . V_28 = V_223 [ V_8 ] . V_28 ;
V_3 -> V_12 [ V_8 ] . V_26 = * V_223 [ V_8 ] . V_26 ;
V_3 -> V_12 [ V_8 ] . V_228 = V_223 [ V_8 ] . V_228 ;
}
V_3 -> V_222 = V_222 ;
V_3 -> V_17 = V_8 ;
F_135 ( & V_3 -> V_31 ) ;
F_136 ( V_3 -> V_17 > V_229 ) ;
if ( F_134 ( V_3 ) )
F_129 ( V_22 ) ;
}
struct V_1 *
F_137 ( struct V_19 * V_20 ,
struct V_39 * V_40 ,
struct V_57 * V_58 )
{
struct V_2 * V_3 = F_7 ( V_20 -> V_21 . V_22 ) ;
const struct V_221 * V_222 = V_3 -> V_222 ;
if ( F_5 ( ! V_222 ) )
return NULL ;
return V_222 -> V_230 ( V_20 , V_40 , V_58 ) ;
}
