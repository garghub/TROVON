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
struct V_29 * V_22 = V_20 -> V_21 . V_22 ;
struct V_2 * V_3 = F_7 ( V_22 ) ;
struct V_1 * V_4 = V_20 -> V_13 -> V_30 ;
unsigned V_14 = 1 << F_19 ( & V_20 -> V_21 ) ;
if ( F_23 ( V_22 ) -> V_38 < 5 )
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
V_4 -> V_26 . V_39 ( V_3 , V_4 ) ;
V_4 -> V_33 = false ;
V_36:
F_17 ( & V_3 -> V_31 ) ;
}
static struct V_1 *
F_24 ( struct V_19 * V_20 ,
struct V_40 * V_41 ,
enum V_7 V_42 ,
enum V_7 V_43 )
{
struct V_2 * V_3 = F_7 ( V_20 -> V_21 . V_22 ) ;
struct V_1 * V_4 ;
struct V_18 * V_30 ;
enum V_7 V_8 ;
V_30 = F_25 ( V_41 -> V_21 . V_24 ) ;
for ( V_8 = V_42 ; V_8 <= V_43 ; V_8 ++ ) {
V_4 = & V_3 -> V_12 [ V_8 ] ;
if ( V_30 [ V_8 ] . V_14 == 0 )
continue;
if ( memcmp ( & V_41 -> V_6 ,
& V_30 [ V_8 ] . V_15 ,
sizeof( V_41 -> V_6 ) ) == 0 ) {
F_20 ( L_8 ,
V_20 -> V_21 . V_21 . V_16 , V_20 -> V_21 . V_28 , V_4 -> V_28 ,
V_30 [ V_8 ] . V_14 ,
V_4 -> V_32 ) ;
return V_4 ;
}
}
for ( V_8 = V_42 ; V_8 <= V_43 ; V_8 ++ ) {
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
struct V_40 * V_41 )
{
struct V_18 * V_30 ;
struct V_19 * V_20 = F_27 ( V_41 -> V_21 . V_20 ) ;
enum V_7 V_8 = V_4 -> V_16 ;
V_30 = F_25 ( V_41 -> V_21 . V_24 ) ;
if ( V_30 [ V_8 ] . V_14 == 0 )
V_30 [ V_8 ] . V_15 =
V_41 -> V_6 ;
V_41 -> V_30 = V_4 ;
F_15 ( L_10 , V_4 -> V_28 ,
F_28 ( V_20 -> V_23 ) ) ;
F_6 ( V_30 , V_4 , V_20 ) ;
}
void F_29 ( struct V_44 * V_24 )
{
struct V_2 * V_3 = F_7 ( V_24 -> V_22 ) ;
struct V_18 * V_30 ;
struct V_1 * V_4 ;
enum V_7 V_8 ;
if ( ! F_30 ( V_24 ) -> V_45 )
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
T_1 V_46 ;
if ( ! F_32 ( V_3 , V_47 ) )
return false ;
V_46 = F_33 ( F_34 ( V_4 -> V_16 ) ) ;
V_15 -> V_48 = V_46 ;
V_15 -> V_49 = F_33 ( F_35 ( V_4 -> V_16 ) ) ;
V_15 -> V_50 = F_33 ( F_36 ( V_4 -> V_16 ) ) ;
F_37 ( V_3 , V_47 ) ;
return V_46 & V_51 ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_39 ( F_35 ( V_4 -> V_16 ) , V_4 -> V_13 . V_15 . V_49 ) ;
F_39 ( F_36 ( V_4 -> V_16 ) , V_4 -> V_13 . V_15 . V_50 ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
T_2 V_46 ;
bool V_52 ;
F_41 ( ! ( F_42 ( V_3 ) || F_43 ( V_3 ) ) ) ;
V_46 = F_33 ( V_53 ) ;
V_52 = ! ! ( V_46 & ( V_54 | V_55 |
V_56 ) ) ;
F_12 ( ! V_52 , L_11 ) ;
}
static void F_44 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_40 ( V_3 ) ;
F_39 ( F_34 ( V_4 -> V_16 ) , V_4 -> V_13 . V_15 . V_48 ) ;
F_45 ( F_34 ( V_4 -> V_16 ) ) ;
F_46 ( 150 ) ;
F_39 ( F_34 ( V_4 -> V_16 ) , V_4 -> V_13 . V_15 . V_48 ) ;
F_45 ( F_34 ( V_4 -> V_16 ) ) ;
F_46 ( 200 ) ;
}
static void F_47 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_29 * V_22 = & V_3 -> V_57 ;
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
F_50 ( struct V_19 * V_20 , struct V_40 * V_41 ,
struct V_58 * V_59 )
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
V_4 = F_24 ( V_20 , V_41 ,
V_60 ,
V_61 ) ;
}
if ( ! V_4 )
return NULL ;
F_26 ( V_4 , V_41 ) ;
return V_4 ;
}
static void F_51 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_39 ( F_52 ( V_4 -> V_16 ) , V_4 -> V_13 . V_15 . V_62 ) ;
F_45 ( F_52 ( V_4 -> V_16 ) ) ;
F_46 ( 20 ) ;
}
static void F_53 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_39 ( V_63 , V_4 -> V_13 . V_15 . V_64 ) ;
F_45 ( V_63 ) ;
F_46 ( 20 ) ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_46 ;
V_46 = F_33 ( F_52 ( V_4 -> V_16 ) ) ;
F_39 ( F_52 ( V_4 -> V_16 ) , V_46 & ~ V_65 ) ;
F_45 ( F_52 ( V_4 -> V_16 ) ) ;
}
static void F_55 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_46 ;
V_46 = F_33 ( V_63 ) ;
F_39 ( V_63 , V_46 & ~ V_66 ) ;
F_45 ( V_63 ) ;
}
static bool F_56 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_46 ;
if ( ! F_32 ( V_3 , V_47 ) )
return false ;
V_46 = F_33 ( F_52 ( V_4 -> V_16 ) ) ;
V_15 -> V_62 = V_46 ;
F_37 ( V_3 , V_47 ) ;
return V_46 & V_65 ;
}
static bool F_57 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_46 ;
if ( ! F_32 ( V_3 , V_47 ) )
return false ;
V_46 = F_33 ( V_63 ) ;
V_15 -> V_64 = V_46 ;
F_37 ( V_3 , V_47 ) ;
return V_46 & V_66 ;
}
static unsigned F_58 ( int clock )
{
unsigned V_67 ;
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
V_67 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_67 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_67 = 2000 ;
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
V_67 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_67 = 5000 ;
break;
default:
V_67 = 1000 ;
break;
}
return V_67 ;
}
static void F_59 ( T_3 V_68 , unsigned V_67 ,
unsigned V_69 , unsigned V_70 , unsigned V_71 ,
struct V_72 * V_73 )
{
T_3 V_74 , V_75 , V_76 , V_77 , V_78 , V_79 ;
if ( V_73 -> V_71 == 0 ) {
V_73 -> V_71 = V_71 ;
V_73 -> V_70 = V_70 ;
V_73 -> V_69 = V_69 ;
return;
}
V_74 = V_68 * V_67 * V_71 * V_69 ;
V_75 = V_68 * V_67 * V_73 -> V_71 * V_73 -> V_69 ;
V_78 = F_60 ( V_68 * V_71 * V_69 , V_80 * V_70 ) ;
V_79 = F_60 ( V_68 * V_73 -> V_71 * V_73 -> V_69 ,
V_80 * V_73 -> V_70 ) ;
V_76 = 1000000 * V_78 ;
V_77 = 1000000 * V_79 ;
if ( V_74 < V_76 && V_75 < V_77 ) {
if ( V_73 -> V_71 * V_73 -> V_69 * V_78 < V_71 * V_69 * V_79 ) {
V_73 -> V_71 = V_71 ;
V_73 -> V_70 = V_70 ;
V_73 -> V_69 = V_69 ;
}
} else if ( V_74 >= V_76 && V_75 < V_77 ) {
V_73 -> V_71 = V_71 ;
V_73 -> V_70 = V_70 ;
V_73 -> V_69 = V_69 ;
} else if ( V_74 >= V_76 && V_75 >= V_77 ) {
if ( V_70 * V_73 -> V_69 * V_73 -> V_69 > V_73 -> V_70 * V_69 * V_69 ) {
V_73 -> V_71 = V_71 ;
V_73 -> V_70 = V_70 ;
V_73 -> V_69 = V_69 ;
}
}
}
static void
F_61 ( int clock ,
unsigned * V_81 , unsigned * V_82 , unsigned * V_83 )
{
T_3 V_68 ;
unsigned V_71 , V_70 , V_69 ;
struct V_72 V_73 = { 0 , 0 , 0 } ;
unsigned V_67 ;
V_68 = clock / 100 ;
V_67 = F_58 ( clock ) ;
if ( V_68 == 5400000 ) {
* V_82 = 2 ;
* V_83 = 1 ;
* V_81 = 2 ;
return;
}
for ( V_69 = V_84 * 2 / V_85 + 1 ;
V_69 <= V_84 * 2 / V_86 ;
V_69 ++ ) {
for ( V_70 = V_87 * V_69 / V_84 + 1 ;
V_70 <= V_88 * V_69 / V_84 ;
V_70 ++ ) {
for ( V_71 = V_89 ; V_71 <= V_90 ; V_71 += V_91 )
F_59 ( V_68 , V_67 ,
V_69 , V_70 , V_71 , & V_73 ) ;
}
}
* V_82 = V_73 . V_70 ;
* V_83 = V_73 . V_71 ;
* V_81 = V_73 . V_69 ;
}
static struct V_1 * F_62 ( int clock ,
struct V_19 * V_20 ,
struct V_40 * V_41 )
{
struct V_1 * V_4 ;
T_1 V_46 ;
unsigned int V_71 , V_70 , V_69 ;
F_61 ( clock * 1000 , & V_69 , & V_70 , & V_71 ) ;
V_46 = V_65 | V_92 |
F_63 ( V_69 ) | F_64 ( V_70 ) |
F_65 ( V_71 ) ;
V_41 -> V_6 . V_62 = V_46 ;
V_4 = F_24 ( V_20 , V_41 ,
V_93 , V_94 ) ;
if ( ! V_4 )
return NULL ;
return V_4 ;
}
struct V_1 * F_66 ( struct V_58 * V_59 ,
int clock )
{
struct V_2 * V_3 = F_7 ( V_59 -> V_21 . V_22 ) ;
struct V_1 * V_4 ;
enum V_7 V_95 ;
switch ( clock / 2 ) {
case 81000 :
V_95 = V_96 ;
break;
case 135000 :
V_95 = V_97 ;
break;
case 270000 :
V_95 = V_98 ;
break;
default:
F_20 ( L_13 , clock ) ;
return NULL ;
}
V_4 = F_3 ( V_3 , V_95 ) ;
if ( ! V_4 )
return NULL ;
return V_4 ;
}
static struct V_1 *
F_67 ( struct V_19 * V_20 , struct V_40 * V_41 ,
struct V_58 * V_59 )
{
struct V_1 * V_4 ;
int clock = V_41 -> V_99 ;
memset ( & V_41 -> V_6 , 0 ,
sizeof( V_41 -> V_6 ) ) ;
if ( V_59 -> type == V_100 ) {
V_4 = F_62 ( clock , V_20 , V_41 ) ;
} else if ( V_59 -> type == V_101 ||
V_59 -> type == V_102 ||
V_59 -> type == V_103 ) {
V_4 = F_66 ( V_59 , clock ) ;
} else if ( V_59 -> type == V_104 ) {
if ( F_5 ( V_41 -> V_99 / 2 != 135000 ) )
return NULL ;
V_41 -> V_6 . V_64 =
V_66 | V_105 | V_106 ;
V_4 = F_24 ( V_20 , V_41 ,
V_107 , V_107 ) ;
} else {
return NULL ;
}
if ( ! V_4 )
return NULL ;
F_26 ( V_4 , V_41 ) ;
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
T_1 V_46 ;
V_46 = F_33 ( V_108 ) ;
V_46 &= ~ ( F_72 ( V_4 -> V_16 ) | F_73 ( V_4 -> V_16 ) |
F_74 ( V_4 -> V_16 ) ) ;
V_46 |= V_4 -> V_13 . V_15 . V_109 << ( V_4 -> V_16 * 6 ) ;
F_39 ( V_108 , V_46 ) ;
F_45 ( V_108 ) ;
}
static void F_75 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
const struct V_110 * V_111 = V_110 ;
F_71 ( V_3 , V_4 ) ;
F_39 ( V_111 [ V_4 -> V_16 ] . V_112 , V_4 -> V_13 . V_15 . V_112 ) ;
F_39 ( V_111 [ V_4 -> V_16 ] . V_113 , V_4 -> V_13 . V_15 . V_113 ) ;
F_45 ( V_111 [ V_4 -> V_16 ] . V_112 ) ;
F_45 ( V_111 [ V_4 -> V_16 ] . V_113 ) ;
F_39 ( V_111 [ V_4 -> V_16 ] . V_114 ,
F_33 ( V_111 [ V_4 -> V_16 ] . V_114 ) | V_115 ) ;
if ( F_76 ( V_3 ,
V_116 ,
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
const struct V_110 * V_111 = V_110 ;
F_39 ( V_111 [ V_4 -> V_16 ] . V_114 ,
F_33 ( V_111 [ V_4 -> V_16 ] . V_114 ) & ~ V_115 ) ;
F_45 ( V_111 [ V_4 -> V_16 ] . V_114 ) ;
}
static void F_81 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
}
static bool F_82 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_46 ;
const struct V_110 * V_111 = V_110 ;
bool V_117 ;
if ( ! F_32 ( V_3 , V_47 ) )
return false ;
V_117 = false ;
V_46 = F_33 ( V_111 [ V_4 -> V_16 ] . V_114 ) ;
if ( ! ( V_46 & V_115 ) )
goto V_36;
V_46 = F_33 ( V_108 ) ;
V_15 -> V_109 = ( V_46 >> ( V_4 -> V_16 * 6 ) ) & 0x3f ;
if ( V_46 & F_72 ( V_4 -> V_16 ) ) {
V_15 -> V_112 = F_33 ( V_111 [ V_4 -> V_16 ] . V_112 ) ;
V_15 -> V_113 = F_33 ( V_111 [ V_4 -> V_16 ] . V_113 ) ;
}
V_117 = true ;
V_36:
F_37 ( V_3 , V_47 ) ;
return V_117 ;
}
static bool F_83 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
T_1 V_46 ;
const struct V_110 * V_111 = V_110 ;
bool V_117 ;
if ( ! F_32 ( V_3 , V_47 ) )
return false ;
V_117 = false ;
V_46 = F_33 ( V_111 [ V_4 -> V_16 ] . V_114 ) ;
if ( F_5 ( ! ( V_46 & V_115 ) ) )
goto V_36;
V_46 = F_33 ( V_108 ) ;
V_15 -> V_109 = ( V_46 >> ( V_4 -> V_16 * 6 ) ) & 0x3f ;
V_117 = true ;
V_36:
F_37 ( V_3 , V_47 ) ;
return V_117 ;
}
static void F_84 ( struct V_118 * V_119 )
{
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_119 -> V_120 = V_121 ;
}
static void F_85 ( struct V_118 * V_119 ,
T_3 V_122 ,
T_3 V_123 ,
unsigned int V_124 )
{
T_3 V_125 ;
V_125 = F_86 ( 10000 * F_60 ( V_123 , V_122 ) ,
V_122 ) ;
if ( V_123 >= V_122 ) {
if ( V_125 < V_126 &&
V_125 < V_119 -> V_120 ) {
V_119 -> V_120 = V_125 ;
V_119 -> V_122 = V_122 ;
V_119 -> V_123 = V_123 ;
V_119 -> V_71 = V_124 ;
}
} else if ( V_125 < V_127 &&
V_125 < V_119 -> V_120 ) {
V_119 -> V_120 = V_125 ;
V_119 -> V_122 = V_122 ;
V_119 -> V_123 = V_123 ;
V_119 -> V_71 = V_124 ;
}
}
static void F_87 ( unsigned int V_71 ,
unsigned int * V_128 ,
unsigned int * V_129 ,
unsigned int * V_130 )
{
if ( V_71 % 2 == 0 ) {
unsigned int V_131 = V_71 / 2 ;
if ( V_131 == 1 || V_131 == 2 || V_131 == 3 || V_131 == 5 ) {
* V_128 = 2 ;
* V_129 = 1 ;
* V_130 = V_131 ;
} else if ( V_131 % 2 == 0 ) {
* V_128 = 2 ;
* V_129 = V_131 / 2 ;
* V_130 = 2 ;
} else if ( V_131 % 3 == 0 ) {
* V_128 = 3 ;
* V_129 = V_131 / 3 ;
* V_130 = 2 ;
} else if ( V_131 % 7 == 0 ) {
* V_128 = 7 ;
* V_129 = V_131 / 7 ;
* V_130 = 2 ;
}
} else if ( V_71 == 3 || V_71 == 9 ) {
* V_128 = 3 ;
* V_129 = 1 ;
* V_130 = V_71 / 3 ;
} else if ( V_71 == 5 || V_71 == 7 ) {
* V_128 = V_71 ;
* V_129 = 1 ;
* V_130 = 1 ;
} else if ( V_71 == 15 ) {
* V_128 = 3 ;
* V_129 = 1 ;
* V_130 = 5 ;
} else if ( V_71 == 21 ) {
* V_128 = 7 ;
* V_129 = 1 ;
* V_130 = 3 ;
} else if ( V_71 == 35 ) {
* V_128 = 7 ;
* V_129 = 1 ;
* V_130 = 5 ;
}
}
static void F_88 ( struct V_132 * V_133 ,
T_3 V_134 ,
T_3 V_122 ,
T_1 V_128 , T_1 V_129 , T_1 V_130 )
{
T_3 V_123 ;
switch ( V_122 ) {
case 9600000000ULL :
V_133 -> V_122 = 0 ;
break;
case 9000000000ULL :
V_133 -> V_122 = 1 ;
break;
case 8400000000ULL :
V_133 -> V_122 = 3 ;
}
switch ( V_128 ) {
case 1 :
V_133 -> V_135 = 0 ;
break;
case 2 :
V_133 -> V_135 = 1 ;
break;
case 3 :
V_133 -> V_135 = 2 ;
break;
case 7 :
V_133 -> V_135 = 4 ;
break;
default:
F_10 ( 1 , L_15 ) ;
}
switch ( V_130 ) {
case 5 :
V_133 -> V_136 = 0 ;
break;
case 2 :
V_133 -> V_136 = 1 ;
break;
case 3 :
V_133 -> V_136 = 2 ;
break;
case 1 :
V_133 -> V_136 = 3 ;
break;
default:
F_10 ( 1 , L_16 ) ;
}
V_133 -> V_137 = V_129 ;
V_133 -> V_138 = ( V_133 -> V_137 == 1 ) ? 0 : 1 ;
V_123 = V_128 * V_129 * V_130 * V_134 ;
V_133 -> V_139 = F_89 ( V_123 , 24 * F_90 ( 1 ) ) ;
V_133 -> V_140 =
F_89 ( ( F_89 ( V_123 , 24 ) -
V_133 -> V_139 * F_90 ( 1 ) ) * 0x8000 , F_90 ( 1 ) ) ;
}
static bool
F_91 ( int clock ,
struct V_132 * V_141 )
{
T_3 V_134 = clock * 5 ;
T_3 V_142 [ 3 ] = { 8400000000ULL ,
9000000000ULL ,
9600000000ULL } ;
static const int V_143 [] = { 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20 ,
24 , 28 , 30 , 32 , 36 , 40 , 42 , 44 ,
48 , 52 , 54 , 56 , 60 , 64 , 66 , 68 ,
70 , 72 , 76 , 78 , 80 , 84 , 88 , 90 ,
92 , 96 , 98 } ;
static const int V_144 [] = { 3 , 5 , 7 , 9 , 15 , 21 , 35 } ;
static const struct {
const int * V_145 ;
int V_146 ;
} V_147 [] = {
{ V_143 , F_92 (even_dividers) } ,
{ V_144 , F_92 (odd_dividers) } ,
} ;
struct V_118 V_119 ;
unsigned int V_148 , V_77 , V_8 ;
unsigned int V_128 , V_129 , V_130 ;
F_84 ( & V_119 ) ;
for ( V_77 = 0 ; V_77 < F_92 ( V_147 ) ; V_77 ++ ) {
for ( V_148 = 0 ; V_148 < F_92 ( V_142 ) ; V_148 ++ ) {
for ( V_8 = 0 ; V_8 < V_147 [ V_77 ] . V_146 ; V_8 ++ ) {
unsigned int V_71 = V_147 [ V_77 ] . V_145 [ V_8 ] ;
T_3 V_123 = V_71 * V_134 ;
F_85 ( & V_119 ,
V_142 [ V_148 ] ,
V_123 ,
V_71 ) ;
if ( V_119 . V_120 == 0 )
goto V_149;
}
}
V_149:
if ( V_77 == 0 && V_119 . V_71 )
break;
}
if ( ! V_119 . V_71 ) {
F_15 ( L_17 , clock ) ;
return false ;
}
V_128 = V_129 = V_130 = 0 ;
F_87 ( V_119 . V_71 , & V_128 , & V_129 , & V_130 ) ;
F_88 ( V_141 , V_134 , V_119 . V_122 ,
V_128 , V_129 , V_130 ) ;
return true ;
}
static bool F_93 ( struct V_19 * V_20 ,
struct V_40 * V_41 ,
int clock )
{
T_1 V_109 , V_112 , V_113 ;
struct V_132 V_141 = { 0 , } ;
V_109 = F_94 ( 0 ) ;
V_109 |= F_72 ( 0 ) ;
if ( ! F_91 ( clock * 1000 , & V_141 ) )
return false ;
V_112 = V_150 |
F_95 ( V_141 . V_140 ) |
V_141 . V_139 ;
V_113 = F_96 ( V_141 . V_137 ) |
F_97 ( V_141 . V_138 ) |
F_98 ( V_141 . V_136 ) |
F_99 ( V_141 . V_135 ) |
V_141 . V_122 ;
memset ( & V_41 -> V_6 , 0 ,
sizeof( V_41 -> V_6 ) ) ;
V_41 -> V_6 . V_109 = V_109 ;
V_41 -> V_6 . V_112 = V_112 ;
V_41 -> V_6 . V_113 = V_113 ;
return true ;
}
bool F_2 ( int clock ,
struct V_5 * V_6 )
{
T_1 V_109 ;
V_109 = F_94 ( 0 ) ;
switch ( clock / 2 ) {
case 81000 :
V_109 |= F_100 ( V_151 , 0 ) ;
break;
case 135000 :
V_109 |= F_100 ( V_152 , 0 ) ;
break;
case 270000 :
V_109 |= F_100 ( V_153 , 0 ) ;
break;
case 162000 :
V_109 |= F_100 ( V_154 , 0 ) ;
break;
case 108000 :
V_109 |= F_100 ( V_155 , 0 ) ;
break;
case 216000 :
V_109 |= F_100 ( V_156 , 0 ) ;
break;
}
V_6 -> V_109 = V_109 ;
return true ;
}
static struct V_1 *
F_101 ( struct V_19 * V_20 , struct V_40 * V_41 ,
struct V_58 * V_59 )
{
struct V_1 * V_4 ;
int clock = V_41 -> V_99 ;
bool V_157 ;
struct V_5 V_6 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
if ( V_59 -> type == V_100 ) {
V_157 = F_93 ( V_20 , V_41 , clock ) ;
if ( ! V_157 ) {
F_20 ( L_18 ) ;
return NULL ;
}
} else if ( V_59 -> type == V_101 ||
V_59 -> type == V_102 ||
V_59 -> type == V_103 ) {
V_157 = F_2 ( clock , & V_6 ) ;
if ( ! V_157 ) {
F_20 ( L_19 ) ;
return NULL ;
}
V_41 -> V_6 = V_6 ;
} else {
return NULL ;
}
if ( V_59 -> type == V_103 )
V_4 = F_24 ( V_20 , V_41 ,
V_158 ,
V_158 ) ;
else
V_4 = F_24 ( V_20 , V_41 ,
V_10 ,
V_11 ) ;
if ( ! V_4 )
return NULL ;
F_26 ( V_4 , V_41 ) ;
return V_4 ;
}
static void F_102 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_159 ;
enum V_160 V_160 = (enum V_160 ) V_4 -> V_16 ;
V_159 = F_33 ( F_103 ( V_160 ) ) ;
V_159 |= V_161 ;
F_39 ( F_103 ( V_160 ) , V_159 ) ;
V_159 = F_33 ( F_104 ( V_160 ) ) ;
V_159 &= ~ V_162 ;
F_39 ( F_104 ( V_160 ) , V_159 ) ;
V_159 = F_33 ( F_105 ( V_160 ) ) ;
V_159 &= ~ ( V_163 | V_164 ) ;
V_159 |= V_4 -> V_13 . V_15 . V_165 ;
F_39 ( F_105 ( V_160 ) , V_159 ) ;
V_159 = F_33 ( F_106 ( V_160 , 0 ) ) ;
V_159 &= ~ V_166 ;
V_159 |= V_4 -> V_13 . V_15 . V_167 ;
F_39 ( F_106 ( V_160 , 0 ) , V_159 ) ;
V_159 = F_33 ( F_106 ( V_160 , 1 ) ) ;
V_159 &= ~ V_168 ;
V_159 |= V_4 -> V_13 . V_15 . V_169 ;
F_39 ( F_106 ( V_160 , 1 ) , V_159 ) ;
V_159 = F_33 ( F_106 ( V_160 , 2 ) ) ;
V_159 &= ~ V_170 ;
V_159 |= V_4 -> V_13 . V_15 . V_171 ;
F_39 ( F_106 ( V_160 , 2 ) , V_159 ) ;
V_159 = F_33 ( F_106 ( V_160 , 3 ) ) ;
V_159 &= ~ V_172 ;
V_159 |= V_4 -> V_13 . V_15 . V_173 ;
F_39 ( F_106 ( V_160 , 3 ) , V_159 ) ;
V_159 = F_33 ( F_106 ( V_160 , 6 ) ) ;
V_159 &= ~ V_174 ;
V_159 &= ~ V_175 ;
V_159 &= ~ V_176 ;
V_159 |= V_4 -> V_13 . V_15 . V_177 ;
F_39 ( F_106 ( V_160 , 6 ) , V_159 ) ;
V_159 = F_33 ( F_106 ( V_160 , 8 ) ) ;
V_159 &= ~ V_178 ;
V_159 |= V_4 -> V_13 . V_15 . V_179 ;
F_39 ( F_106 ( V_160 , 8 ) , V_159 ) ;
V_159 = F_33 ( F_106 ( V_160 , 9 ) ) ;
V_159 &= ~ V_180 ;
V_159 |= V_4 -> V_13 . V_15 . V_181 ;
F_39 ( F_106 ( V_160 , 9 ) , V_159 ) ;
V_159 = F_33 ( F_106 ( V_160 , 10 ) ) ;
V_159 &= ~ V_182 ;
V_159 &= ~ V_183 ;
V_159 |= V_4 -> V_13 . V_15 . V_184 ;
F_39 ( F_106 ( V_160 , 10 ) , V_159 ) ;
V_159 = F_33 ( F_104 ( V_160 ) ) ;
V_159 |= V_185 ;
F_39 ( F_104 ( V_160 ) , V_159 ) ;
V_159 &= ~ V_162 ;
V_159 |= V_4 -> V_13 . V_15 . V_186 ;
F_39 ( F_104 ( V_160 ) , V_159 ) ;
V_159 = F_33 ( F_103 ( V_160 ) ) ;
V_159 |= V_187 ;
F_39 ( F_103 ( V_160 ) , V_159 ) ;
F_45 ( F_103 ( V_160 ) ) ;
if ( F_107 ( ( F_33 ( F_103 ( V_160 ) ) & V_188 ) ,
200 ) )
F_78 ( L_20 , V_160 ) ;
V_159 = F_33 ( F_108 ( V_160 ) ) ;
V_159 &= ~ V_189 ;
V_159 &= ~ V_190 ;
V_159 |= V_4 -> V_13 . V_15 . V_191 ;
F_39 ( F_109 ( V_160 ) , V_159 ) ;
}
static void F_110 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
enum V_160 V_160 = (enum V_160 ) V_4 -> V_16 ;
T_1 V_159 ;
V_159 = F_33 ( F_103 ( V_160 ) ) ;
V_159 &= ~ V_187 ;
F_39 ( F_103 ( V_160 ) , V_159 ) ;
F_45 ( F_103 ( V_160 ) ) ;
}
static bool F_111 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_5 * V_15 )
{
enum V_160 V_160 = (enum V_160 ) V_4 -> V_16 ;
T_1 V_46 ;
bool V_117 ;
if ( ! F_32 ( V_3 , V_47 ) )
return false ;
V_117 = false ;
V_46 = F_33 ( F_103 ( V_160 ) ) ;
if ( ! ( V_46 & V_187 ) )
goto V_36;
V_15 -> V_165 = F_33 ( F_105 ( V_160 ) ) ;
V_15 -> V_165 &= V_163 | V_164 ;
V_15 -> V_186 = F_33 ( F_104 ( V_160 ) ) ;
V_15 -> V_186 &= V_162 ;
V_15 -> V_167 = F_33 ( F_106 ( V_160 , 0 ) ) ;
V_15 -> V_167 &= V_166 ;
V_15 -> V_169 = F_33 ( F_106 ( V_160 , 1 ) ) ;
V_15 -> V_169 &= V_168 ;
V_15 -> V_171 = F_33 ( F_106 ( V_160 , 2 ) ) ;
V_15 -> V_171 &= V_170 ;
V_15 -> V_173 = F_33 ( F_106 ( V_160 , 3 ) ) ;
V_15 -> V_173 &= V_172 ;
V_15 -> V_177 = F_33 ( F_106 ( V_160 , 6 ) ) ;
V_15 -> V_177 &= V_174 |
V_175 |
V_176 ;
V_15 -> V_179 = F_33 ( F_106 ( V_160 , 8 ) ) ;
V_15 -> V_179 &= V_178 ;
V_15 -> V_181 = F_33 ( F_106 ( V_160 , 9 ) ) ;
V_15 -> V_181 &= V_180 ;
V_15 -> V_184 = F_33 ( F_106 ( V_160 , 10 ) ) ;
V_15 -> V_184 &= V_182 |
V_183 ;
V_15 -> V_191 = F_33 ( F_108 ( V_160 ) ) ;
if ( F_33 ( F_112 ( V_160 ) ) != V_15 -> V_191 )
F_15 ( L_21 ,
V_15 -> V_191 ,
F_33 ( F_112 ( V_160 ) ) ) ;
V_15 -> V_191 &= V_189 | V_190 ;
V_117 = true ;
V_36:
F_37 ( V_3 , V_47 ) ;
return V_117 ;
}
static bool
F_113 ( struct V_19 * V_19 ,
struct V_40 * V_41 , int clock ,
struct V_192 * V_193 )
{
struct V_48 V_194 ;
if ( ! F_114 ( V_41 , clock , & V_194 ) ) {
F_15 ( L_22 ,
clock , F_28 ( V_19 -> V_23 ) ) ;
return false ;
}
V_193 -> V_129 = V_194 . V_129 ;
V_193 -> V_130 = V_194 . V_130 ;
F_5 ( V_194 . V_195 != 2 ) ;
V_193 -> V_196 = V_194 . V_196 ;
V_193 -> V_197 = V_194 . V_198 >> 22 ;
V_193 -> V_199 = V_194 . V_198 & ( ( 1 << 22 ) - 1 ) ;
V_193 -> V_200 = V_193 -> V_199 != 0 ;
V_193 -> V_201 = V_194 . V_201 ;
return true ;
}
static void F_115 ( int clock , struct V_192 * V_193 )
{
int V_8 ;
* V_193 = V_202 [ 0 ] ;
for ( V_8 = 0 ; V_8 < F_92 ( V_202 ) ; ++ V_8 ) {
if ( V_202 [ V_8 ] . clock == clock ) {
* V_193 = V_202 [ V_8 ] ;
break;
}
}
V_193 -> V_201 = clock * 10 / 2 * V_193 -> V_129 * V_193 -> V_130 ;
}
static bool F_116 ( int clock ,
struct V_192 * V_193 ,
struct V_5 * V_6 )
{
int V_201 = V_193 -> V_201 ;
T_1 V_203 , V_204 , V_205 , V_206 ;
T_1 V_207 ;
if ( V_201 >= 6200000 && V_201 <= 6700000 ) {
V_203 = 4 ;
V_204 = 9 ;
V_205 = 3 ;
V_206 = 8 ;
} else if ( ( V_201 > 5400000 && V_201 < 6200000 ) ||
( V_201 >= 4800000 && V_201 < 5400000 ) ) {
V_203 = 5 ;
V_204 = 11 ;
V_205 = 3 ;
V_206 = 9 ;
} else if ( V_201 == 5400000 ) {
V_203 = 3 ;
V_204 = 8 ;
V_205 = 1 ;
V_206 = 9 ;
} else {
F_78 ( L_23 ) ;
return false ;
}
if ( clock > 270000 )
V_207 = 0x18 ;
else if ( clock > 135000 )
V_207 = 0x0d ;
else if ( clock > 67000 )
V_207 = 0x07 ;
else if ( clock > 33000 )
V_207 = 0x04 ;
else
V_207 = 0x02 ;
V_6 -> V_165 = F_117 ( V_193 -> V_129 ) | F_118 ( V_193 -> V_130 ) ;
V_6 -> V_167 = V_193 -> V_197 ;
V_6 -> V_169 = F_119 ( V_193 -> V_196 ) ;
V_6 -> V_171 = V_193 -> V_199 ;
if ( V_193 -> V_200 )
V_6 -> V_173 = V_172 ;
V_6 -> V_177 = V_203 | F_120 ( V_204 ) ;
V_6 -> V_177 |= F_121 ( V_205 ) ;
V_6 -> V_179 = V_206 ;
V_6 -> V_181 = 5 << V_208 ;
V_6 -> V_184 =
F_122 ( V_209 )
| V_182 ;
V_6 -> V_186 = V_162 ;
V_6 -> V_191 = V_190 | V_207 ;
return true ;
}
bool F_123 ( int clock ,
struct V_5 * V_6 )
{
struct V_192 V_193 = { 0 } ;
F_115 ( clock , & V_193 ) ;
return F_116 ( clock , & V_193 , V_6 ) ;
}
static bool
F_124 ( struct V_19 * V_19 ,
struct V_40 * V_41 , int clock ,
struct V_5 * V_6 )
{
struct V_192 V_193 = { } ;
F_113 ( V_19 , V_41 , clock , & V_193 ) ;
return F_116 ( clock , & V_193 , V_6 ) ;
}
static struct V_1 *
F_125 ( struct V_19 * V_20 ,
struct V_40 * V_41 ,
struct V_58 * V_59 )
{
struct V_5 V_6 = { } ;
struct V_2 * V_3 = F_7 ( V_20 -> V_21 . V_22 ) ;
struct V_210 * V_211 ;
struct V_1 * V_4 ;
int V_8 , clock = V_41 -> V_99 ;
if ( V_59 -> type == V_100 &&
! F_124 ( V_20 , V_41 , clock ,
& V_6 ) )
return NULL ;
if ( ( V_59 -> type == V_101 ||
V_59 -> type == V_103 ) &&
! F_123 ( clock , & V_6 ) )
return NULL ;
memset ( & V_41 -> V_6 , 0 ,
sizeof( V_41 -> V_6 ) ) ;
V_41 -> V_6 = V_6 ;
if ( V_59 -> type == V_102 ) {
struct V_212 * V_213 = F_126 ( & V_59 -> V_21 ) ;
V_211 = V_213 -> V_214 ;
} else
V_211 = F_127 ( & V_59 -> V_21 ) ;
V_8 = (enum V_7 ) V_211 -> V_160 ;
V_4 = F_3 ( V_3 , V_8 ) ;
F_20 ( L_12 ,
V_20 -> V_21 . V_21 . V_16 , V_20 -> V_21 . V_28 , V_4 -> V_28 ) ;
F_26 ( V_4 , V_41 ) ;
return V_4 ;
}
static void F_128 ( struct V_29 * V_22 )
{
struct V_2 * V_3 = F_7 ( V_22 ) ;
if ( F_129 ( V_3 ) < 9 ) {
T_1 V_46 = F_33 ( V_215 ) ;
if ( V_46 & V_216 )
F_78 ( L_24 ) ;
if ( V_46 & V_217 )
F_78 ( L_25 ) ;
}
}
void F_130 ( struct V_29 * V_22 )
{
struct V_2 * V_3 = F_7 ( V_22 ) ;
const struct V_218 * V_219 = NULL ;
const struct V_220 * V_220 ;
int V_8 ;
if ( F_131 ( V_22 ) || F_132 ( V_22 ) )
V_219 = & V_221 ;
else if ( F_133 ( V_22 ) )
V_219 = & V_222 ;
else if ( F_134 ( V_22 ) )
V_219 = & V_223 ;
else if ( F_42 ( V_22 ) || F_43 ( V_22 ) )
V_219 = & V_224 ;
if ( ! V_219 ) {
V_3 -> V_17 = 0 ;
return;
}
V_220 = V_219 -> V_220 ;
for ( V_8 = 0 ; V_220 [ V_8 ] . V_16 >= 0 ; V_8 ++ ) {
F_5 ( V_8 != V_220 [ V_8 ] . V_16 ) ;
V_3 -> V_12 [ V_8 ] . V_16 = V_220 [ V_8 ] . V_16 ;
V_3 -> V_12 [ V_8 ] . V_28 = V_220 [ V_8 ] . V_28 ;
V_3 -> V_12 [ V_8 ] . V_26 = * V_220 [ V_8 ] . V_26 ;
V_3 -> V_12 [ V_8 ] . V_225 = V_220 [ V_8 ] . V_225 ;
}
V_3 -> V_219 = V_219 ;
V_3 -> V_17 = V_8 ;
F_135 ( & V_3 -> V_31 ) ;
F_136 ( V_3 -> V_17 > V_226 ) ;
if ( F_134 ( V_22 ) )
F_128 ( V_22 ) ;
}
struct V_1 *
F_137 ( struct V_19 * V_20 ,
struct V_40 * V_41 ,
struct V_58 * V_59 )
{
struct V_2 * V_3 = F_7 ( V_20 -> V_21 . V_22 ) ;
const struct V_218 * V_219 = V_3 -> V_219 ;
if ( F_5 ( ! V_219 ) )
return NULL ;
return V_219 -> V_227 ( V_20 , V_41 , V_59 ) ;
}
