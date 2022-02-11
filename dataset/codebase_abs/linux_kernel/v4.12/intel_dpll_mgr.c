static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_5 V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; V_6 ++ ) {
struct V_8 * V_9 = & V_2 -> V_10 [ V_6 ] ;
V_4 [ V_6 ] = V_9 -> V_11 ;
}
}
static struct V_3 *
F_2 ( struct V_12 * V_13 )
{
struct V_14 * V_11 = F_3 ( V_13 ) ;
F_4 ( ! F_5 ( & V_13 -> V_15 -> V_16 . V_17 ) ) ;
if ( ! V_11 -> V_18 ) {
V_11 -> V_18 = true ;
F_1 ( F_6 ( V_13 -> V_15 ) ,
V_11 -> V_4 ) ;
}
return V_11 -> V_4 ;
}
struct V_8 *
F_7 ( struct V_1 * V_2 ,
enum V_5 V_19 )
{
return & V_2 -> V_10 [ V_19 ] ;
}
enum V_5
F_8 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
if ( F_4 ( V_9 < V_2 -> V_10 ||
V_9 > & V_2 -> V_10 [ V_2 -> V_7 ] ) )
return - 1 ;
return (enum V_5 ) ( V_9 - V_2 -> V_10 ) ;
}
void F_9 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
bool V_11 )
{
bool V_20 ;
struct V_21 V_22 ;
if ( F_10 ( ! V_9 , L_1 , F_11 ( V_11 ) ) )
return;
V_20 = V_9 -> V_23 . V_24 ( V_2 , V_9 , & V_22 ) ;
F_12 ( V_20 != V_11 ,
L_2 ,
V_9 -> V_25 , F_11 ( V_11 ) , F_11 ( V_20 ) ) ;
}
void F_13 ( struct V_26 * V_27 )
{
struct V_28 * V_15 = V_27 -> V_29 . V_15 ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
struct V_8 * V_9 = V_27 -> V_30 -> V_4 ;
if ( F_4 ( V_9 == NULL ) )
return;
F_14 ( & V_2 -> V_31 ) ;
F_4 ( ! V_9 -> V_11 . V_32 ) ;
if ( ! V_9 -> V_33 ) {
F_15 ( L_3 , V_9 -> V_25 ) ;
F_4 ( V_9 -> V_34 ) ;
F_16 ( V_2 , V_9 ) ;
V_9 -> V_23 . V_35 ( V_2 , V_9 ) ;
}
F_17 ( & V_2 -> V_31 ) ;
}
void F_18 ( struct V_26 * V_27 )
{
struct V_28 * V_15 = V_27 -> V_29 . V_15 ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
struct V_8 * V_9 = V_27 -> V_30 -> V_4 ;
unsigned V_32 = 1 << F_19 ( & V_27 -> V_29 ) ;
unsigned V_36 ;
if ( F_4 ( V_9 == NULL ) )
return;
F_14 ( & V_2 -> V_31 ) ;
V_36 = V_9 -> V_33 ;
if ( F_4 ( ! ( V_9 -> V_11 . V_32 & V_32 ) ) ||
F_4 ( V_9 -> V_33 & V_32 ) )
goto V_37;
V_9 -> V_33 |= V_32 ;
F_20 ( L_4 ,
V_9 -> V_25 , V_9 -> V_33 , V_9 -> V_34 ,
V_27 -> V_29 . V_29 . V_19 ) ;
if ( V_36 ) {
F_4 ( ! V_9 -> V_34 ) ;
F_21 ( V_2 , V_9 ) ;
goto V_37;
}
F_4 ( V_9 -> V_34 ) ;
F_20 ( L_5 , V_9 -> V_25 ) ;
V_9 -> V_23 . V_38 ( V_2 , V_9 ) ;
V_9 -> V_34 = true ;
V_37:
F_17 ( & V_2 -> V_31 ) ;
}
void F_22 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_6 ( V_27 -> V_29 . V_15 ) ;
struct V_8 * V_9 = V_27 -> V_30 -> V_4 ;
unsigned V_32 = 1 << F_19 ( & V_27 -> V_29 ) ;
if ( F_23 ( V_2 ) < 5 )
return;
if ( V_9 == NULL )
return;
F_14 ( & V_2 -> V_31 ) ;
if ( F_4 ( ! ( V_9 -> V_33 & V_32 ) ) )
goto V_37;
F_20 ( L_6 ,
V_9 -> V_25 , V_9 -> V_33 , V_9 -> V_34 ,
V_27 -> V_29 . V_29 . V_19 ) ;
F_21 ( V_2 , V_9 ) ;
F_4 ( ! V_9 -> V_34 ) ;
V_9 -> V_33 &= ~ V_32 ;
if ( V_9 -> V_33 )
goto V_37;
F_20 ( L_7 , V_9 -> V_25 ) ;
V_9 -> V_23 . V_39 ( V_2 , V_9 ) ;
V_9 -> V_34 = false ;
V_37:
F_17 ( & V_2 -> V_31 ) ;
}
static struct V_8 *
F_24 ( struct V_26 * V_27 ,
struct V_40 * V_41 ,
enum V_5 V_42 ,
enum V_5 V_43 )
{
struct V_1 * V_2 = F_6 ( V_27 -> V_29 . V_15 ) ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
enum V_5 V_6 ;
V_4 = F_2 ( V_41 -> V_29 . V_11 ) ;
for ( V_6 = V_42 ; V_6 <= V_43 ; V_6 ++ ) {
V_9 = & V_2 -> V_10 [ V_6 ] ;
if ( V_4 [ V_6 ] . V_32 == 0 )
continue;
if ( memcmp ( & V_41 -> V_44 ,
& V_4 [ V_6 ] . V_22 ,
sizeof( V_41 -> V_44 ) ) == 0 ) {
F_20 ( L_8 ,
V_27 -> V_29 . V_29 . V_19 , V_27 -> V_29 . V_25 , V_9 -> V_25 ,
V_4 [ V_6 ] . V_32 ,
V_9 -> V_33 ) ;
return V_9 ;
}
}
for ( V_6 = V_42 ; V_6 <= V_43 ; V_6 ++ ) {
V_9 = & V_2 -> V_10 [ V_6 ] ;
if ( V_4 [ V_6 ] . V_32 == 0 ) {
F_20 ( L_9 ,
V_27 -> V_29 . V_29 . V_19 , V_27 -> V_29 . V_25 , V_9 -> V_25 ) ;
return V_9 ;
}
}
return NULL ;
}
static void
F_25 ( struct V_8 * V_9 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 ;
struct V_26 * V_27 = F_26 ( V_41 -> V_29 . V_27 ) ;
enum V_5 V_6 = V_9 -> V_19 ;
V_4 = F_2 ( V_41 -> V_29 . V_11 ) ;
if ( V_4 [ V_6 ] . V_32 == 0 )
V_4 [ V_6 ] . V_22 =
V_41 -> V_44 ;
V_41 -> V_4 = V_9 ;
F_15 ( L_10 , V_9 -> V_25 ,
F_27 ( V_27 -> V_45 ) ) ;
V_4 [ V_9 -> V_19 ] . V_32 |= 1 << V_27 -> V_45 ;
}
void F_28 ( struct V_12 * V_11 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_15 ) ;
struct V_3 * V_4 ;
struct V_8 * V_9 ;
enum V_5 V_6 ;
if ( ! F_3 ( V_11 ) -> V_18 )
return;
V_4 = F_3 ( V_11 ) -> V_4 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; V_6 ++ ) {
struct V_3 V_46 ;
V_9 = & V_2 -> V_10 [ V_6 ] ;
V_46 = V_9 -> V_11 ;
V_9 -> V_11 = V_4 [ V_6 ] ;
V_4 [ V_6 ] = V_46 ;
}
}
static bool F_29 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_21 * V_22 )
{
T_1 V_47 ;
if ( ! F_30 ( V_2 , V_48 ) )
return false ;
V_47 = F_31 ( F_32 ( V_9 -> V_19 ) ) ;
V_22 -> V_49 = V_47 ;
V_22 -> V_50 = F_31 ( F_33 ( V_9 -> V_19 ) ) ;
V_22 -> V_51 = F_31 ( F_34 ( V_9 -> V_19 ) ) ;
F_35 ( V_2 , V_48 ) ;
return V_47 & V_52 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_37 ( F_33 ( V_9 -> V_19 ) , V_9 -> V_11 . V_22 . V_50 ) ;
F_37 ( F_34 ( V_9 -> V_19 ) , V_9 -> V_11 . V_22 . V_51 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_2 V_47 ;
bool V_53 ;
F_39 ( ! ( F_40 ( V_2 ) || F_41 ( V_2 ) ) ) ;
V_47 = F_31 ( V_54 ) ;
V_53 = ! ! ( V_47 & ( V_55 | V_56 |
V_57 ) ) ;
F_12 ( ! V_53 , L_11 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_38 ( V_2 ) ;
F_37 ( F_32 ( V_9 -> V_19 ) , V_9 -> V_11 . V_22 . V_49 ) ;
F_43 ( F_32 ( V_9 -> V_19 ) ) ;
F_44 ( 150 ) ;
F_37 ( F_32 ( V_9 -> V_19 ) , V_9 -> V_11 . V_22 . V_49 ) ;
F_43 ( F_32 ( V_9 -> V_19 ) ) ;
F_44 ( 200 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_28 * V_15 = & V_2 -> V_58 ;
struct V_26 * V_27 ;
F_46 (dev, crtc) {
if ( V_27 -> V_30 -> V_4 == V_9 )
F_47 ( V_2 , V_27 -> V_45 ) ;
}
F_37 ( F_32 ( V_9 -> V_19 ) , 0 ) ;
F_43 ( F_32 ( V_9 -> V_19 ) ) ;
F_44 ( 200 ) ;
}
static struct V_8 *
F_48 ( struct V_26 * V_27 , struct V_40 * V_41 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_6 ( V_27 -> V_29 . V_15 ) ;
struct V_8 * V_9 ;
enum V_5 V_6 ;
if ( F_40 ( V_2 ) ) {
V_6 = (enum V_5 ) V_27 -> V_45 ;
V_9 = & V_2 -> V_10 [ V_6 ] ;
F_20 ( L_12 ,
V_27 -> V_29 . V_29 . V_19 , V_27 -> V_29 . V_25 , V_9 -> V_25 ) ;
} else {
V_9 = F_24 ( V_27 , V_41 ,
V_61 ,
V_62 ) ;
}
if ( ! V_9 )
return NULL ;
F_25 ( V_9 , V_41 ) ;
return V_9 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
F_20 ( L_13
L_14 ,
V_22 -> V_49 ,
V_22 -> V_63 ,
V_22 -> V_50 ,
V_22 -> V_51 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_37 ( F_51 ( V_9 -> V_19 ) , V_9 -> V_11 . V_22 . V_64 ) ;
F_43 ( F_51 ( V_9 -> V_19 ) ) ;
F_44 ( 20 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_37 ( V_65 , V_9 -> V_11 . V_22 . V_66 ) ;
F_43 ( V_65 ) ;
F_44 ( 20 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_1 V_47 ;
V_47 = F_31 ( F_51 ( V_9 -> V_19 ) ) ;
F_37 ( F_51 ( V_9 -> V_19 ) , V_47 & ~ V_67 ) ;
F_43 ( F_51 ( V_9 -> V_19 ) ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_1 V_47 ;
V_47 = F_31 ( V_65 ) ;
F_37 ( V_65 , V_47 & ~ V_68 ) ;
F_43 ( V_65 ) ;
}
static bool F_55 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_21 * V_22 )
{
T_1 V_47 ;
if ( ! F_30 ( V_2 , V_48 ) )
return false ;
V_47 = F_31 ( F_51 ( V_9 -> V_19 ) ) ;
V_22 -> V_64 = V_47 ;
F_35 ( V_2 , V_48 ) ;
return V_47 & V_67 ;
}
static bool F_56 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_21 * V_22 )
{
T_1 V_47 ;
if ( ! F_30 ( V_2 , V_48 ) )
return false ;
V_47 = F_31 ( V_65 ) ;
V_22 -> V_66 = V_47 ;
F_35 ( V_2 , V_48 ) ;
return V_47 & V_68 ;
}
static unsigned F_57 ( int clock )
{
unsigned V_69 ;
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
V_69 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_69 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_69 = 2000 ;
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
V_69 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_69 = 5000 ;
break;
default:
V_69 = 1000 ;
break;
}
return V_69 ;
}
static void F_58 ( T_3 V_70 , unsigned V_69 ,
unsigned V_71 , unsigned V_72 , unsigned V_73 ,
struct V_74 * V_75 )
{
T_3 V_76 , V_77 , V_78 , V_79 , V_80 , V_81 ;
if ( V_75 -> V_73 == 0 ) {
V_75 -> V_73 = V_73 ;
V_75 -> V_72 = V_72 ;
V_75 -> V_71 = V_71 ;
return;
}
V_76 = V_70 * V_69 * V_73 * V_71 ;
V_77 = V_70 * V_69 * V_75 -> V_73 * V_75 -> V_71 ;
V_80 = F_59 ( V_70 * V_73 * V_71 , V_82 * V_72 ) ;
V_81 = F_59 ( V_70 * V_75 -> V_73 * V_75 -> V_71 ,
V_82 * V_75 -> V_72 ) ;
V_78 = 1000000 * V_80 ;
V_79 = 1000000 * V_81 ;
if ( V_76 < V_78 && V_77 < V_79 ) {
if ( V_75 -> V_73 * V_75 -> V_71 * V_80 < V_73 * V_71 * V_81 ) {
V_75 -> V_73 = V_73 ;
V_75 -> V_72 = V_72 ;
V_75 -> V_71 = V_71 ;
}
} else if ( V_76 >= V_78 && V_77 < V_79 ) {
V_75 -> V_73 = V_73 ;
V_75 -> V_72 = V_72 ;
V_75 -> V_71 = V_71 ;
} else if ( V_76 >= V_78 && V_77 >= V_79 ) {
if ( V_72 * V_75 -> V_71 * V_75 -> V_71 > V_75 -> V_72 * V_71 * V_71 ) {
V_75 -> V_73 = V_73 ;
V_75 -> V_72 = V_72 ;
V_75 -> V_71 = V_71 ;
}
}
}
static void
F_60 ( int clock ,
unsigned * V_83 , unsigned * V_84 , unsigned * V_85 )
{
T_3 V_70 ;
unsigned V_73 , V_72 , V_71 ;
struct V_74 V_75 = { 0 , 0 , 0 } ;
unsigned V_69 ;
V_70 = clock / 100 ;
V_69 = F_57 ( clock ) ;
if ( V_70 == 5400000 ) {
* V_84 = 2 ;
* V_85 = 1 ;
* V_83 = 2 ;
return;
}
for ( V_71 = V_86 * 2 / V_87 + 1 ;
V_71 <= V_86 * 2 / V_88 ;
V_71 ++ ) {
for ( V_72 = V_89 * V_71 / V_86 + 1 ;
V_72 <= V_90 * V_71 / V_86 ;
V_72 ++ ) {
for ( V_73 = V_91 ; V_73 <= V_92 ; V_73 += V_93 )
F_58 ( V_70 , V_69 ,
V_71 , V_72 , V_73 , & V_75 ) ;
}
}
* V_84 = V_75 . V_72 ;
* V_85 = V_75 . V_73 ;
* V_83 = V_75 . V_71 ;
}
static struct V_8 * F_61 ( int clock ,
struct V_26 * V_27 ,
struct V_40 * V_41 )
{
struct V_8 * V_9 ;
T_1 V_47 ;
unsigned int V_73 , V_72 , V_71 ;
F_60 ( clock * 1000 , & V_71 , & V_72 , & V_73 ) ;
V_47 = V_67 | V_94 |
F_62 ( V_71 ) | F_63 ( V_72 ) |
F_64 ( V_73 ) ;
V_41 -> V_44 . V_64 = V_47 ;
V_9 = F_24 ( V_27 , V_41 ,
V_95 , V_96 ) ;
if ( ! V_9 )
return NULL ;
return V_9 ;
}
static struct V_8 *
F_65 ( struct V_59 * V_60 , int clock )
{
struct V_1 * V_2 = F_6 ( V_60 -> V_29 . V_15 ) ;
struct V_8 * V_9 ;
enum V_5 V_97 ;
switch ( clock / 2 ) {
case 81000 :
V_97 = V_98 ;
break;
case 135000 :
V_97 = V_99 ;
break;
case 270000 :
V_97 = V_100 ;
break;
default:
F_20 ( L_15 , clock ) ;
return NULL ;
}
V_9 = F_7 ( V_2 , V_97 ) ;
if ( ! V_9 )
return NULL ;
return V_9 ;
}
static struct V_8 *
F_66 ( struct V_26 * V_27 , struct V_40 * V_41 ,
struct V_59 * V_60 )
{
struct V_8 * V_9 ;
int clock = V_41 -> V_101 ;
memset ( & V_41 -> V_44 , 0 ,
sizeof( V_41 -> V_44 ) ) ;
if ( V_60 -> type == V_102 ) {
V_9 = F_61 ( clock , V_27 , V_41 ) ;
} else if ( V_60 -> type == V_103 ||
V_60 -> type == V_104 ||
V_60 -> type == V_105 ) {
V_9 = F_65 ( V_60 , clock ) ;
} else if ( V_60 -> type == V_106 ) {
if ( F_4 ( V_41 -> V_101 / 2 != 135000 ) )
return NULL ;
V_41 -> V_44 . V_66 =
V_68 | V_107 | V_108 ;
V_9 = F_24 ( V_27 , V_41 ,
V_109 , V_109 ) ;
} else {
return NULL ;
}
if ( ! V_9 )
return NULL ;
F_25 ( V_9 , V_41 ) ;
return V_9 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
F_20 ( L_16 ,
V_22 -> V_64 , V_22 -> V_66 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
}
static void F_69 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
}
static bool F_70 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_21 * V_22 )
{
return true ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_1 V_47 ;
V_47 = F_31 ( V_110 ) ;
V_47 &= ~ ( F_72 ( V_9 -> V_19 ) | F_73 ( V_9 -> V_19 ) |
F_74 ( V_9 -> V_19 ) ) ;
V_47 |= V_9 -> V_11 . V_22 . V_111 << ( V_9 -> V_19 * 6 ) ;
F_37 ( V_110 , V_47 ) ;
F_43 ( V_110 ) ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
const struct V_112 * V_113 = V_112 ;
F_71 ( V_2 , V_9 ) ;
F_37 ( V_113 [ V_9 -> V_19 ] . V_114 , V_9 -> V_11 . V_22 . V_114 ) ;
F_37 ( V_113 [ V_9 -> V_19 ] . V_115 , V_9 -> V_11 . V_22 . V_115 ) ;
F_43 ( V_113 [ V_9 -> V_19 ] . V_114 ) ;
F_43 ( V_113 [ V_9 -> V_19 ] . V_115 ) ;
F_37 ( V_113 [ V_9 -> V_19 ] . V_116 ,
F_31 ( V_113 [ V_9 -> V_19 ] . V_116 ) | V_117 ) ;
if ( F_76 ( V_2 ,
V_118 ,
F_77 ( V_9 -> V_19 ) ,
F_77 ( V_9 -> V_19 ) ,
5 ) )
F_78 ( L_17 , V_9 -> V_19 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_71 ( V_2 , V_9 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
const struct V_112 * V_113 = V_112 ;
F_37 ( V_113 [ V_9 -> V_19 ] . V_116 ,
F_31 ( V_113 [ V_9 -> V_19 ] . V_116 ) & ~ V_117 ) ;
F_43 ( V_113 [ V_9 -> V_19 ] . V_116 ) ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
}
static bool F_82 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_21 * V_22 )
{
T_1 V_47 ;
const struct V_112 * V_113 = V_112 ;
bool V_119 ;
if ( ! F_30 ( V_2 , V_48 ) )
return false ;
V_119 = false ;
V_47 = F_31 ( V_113 [ V_9 -> V_19 ] . V_116 ) ;
if ( ! ( V_47 & V_117 ) )
goto V_37;
V_47 = F_31 ( V_110 ) ;
V_22 -> V_111 = ( V_47 >> ( V_9 -> V_19 * 6 ) ) & 0x3f ;
if ( V_47 & F_72 ( V_9 -> V_19 ) ) {
V_22 -> V_114 = F_31 ( V_113 [ V_9 -> V_19 ] . V_114 ) ;
V_22 -> V_115 = F_31 ( V_113 [ V_9 -> V_19 ] . V_115 ) ;
}
V_119 = true ;
V_37:
F_35 ( V_2 , V_48 ) ;
return V_119 ;
}
static bool F_83 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_21 * V_22 )
{
T_1 V_47 ;
const struct V_112 * V_113 = V_112 ;
bool V_119 ;
if ( ! F_30 ( V_2 , V_48 ) )
return false ;
V_119 = false ;
V_47 = F_31 ( V_113 [ V_9 -> V_19 ] . V_116 ) ;
if ( F_4 ( ! ( V_47 & V_117 ) ) )
goto V_37;
V_47 = F_31 ( V_110 ) ;
V_22 -> V_111 = ( V_47 >> ( V_9 -> V_19 * 6 ) ) & 0x3f ;
V_119 = true ;
V_37:
F_35 ( V_2 , V_48 ) ;
return V_119 ;
}
static void F_84 ( struct V_120 * V_121 )
{
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
V_121 -> V_122 = V_123 ;
}
static void F_85 ( struct V_120 * V_121 ,
T_3 V_124 ,
T_3 V_125 ,
unsigned int V_126 )
{
T_3 V_127 ;
V_127 = F_86 ( 10000 * F_59 ( V_125 , V_124 ) ,
V_124 ) ;
if ( V_125 >= V_124 ) {
if ( V_127 < V_128 &&
V_127 < V_121 -> V_122 ) {
V_121 -> V_122 = V_127 ;
V_121 -> V_124 = V_124 ;
V_121 -> V_125 = V_125 ;
V_121 -> V_73 = V_126 ;
}
} else if ( V_127 < V_129 &&
V_127 < V_121 -> V_122 ) {
V_121 -> V_122 = V_127 ;
V_121 -> V_124 = V_124 ;
V_121 -> V_125 = V_125 ;
V_121 -> V_73 = V_126 ;
}
}
static void F_87 ( unsigned int V_73 ,
unsigned int * V_130 ,
unsigned int * V_131 ,
unsigned int * V_132 )
{
if ( V_73 % 2 == 0 ) {
unsigned int V_133 = V_73 / 2 ;
if ( V_133 == 1 || V_133 == 2 || V_133 == 3 || V_133 == 5 ) {
* V_130 = 2 ;
* V_131 = 1 ;
* V_132 = V_133 ;
} else if ( V_133 % 2 == 0 ) {
* V_130 = 2 ;
* V_131 = V_133 / 2 ;
* V_132 = 2 ;
} else if ( V_133 % 3 == 0 ) {
* V_130 = 3 ;
* V_131 = V_133 / 3 ;
* V_132 = 2 ;
} else if ( V_133 % 7 == 0 ) {
* V_130 = 7 ;
* V_131 = V_133 / 7 ;
* V_132 = 2 ;
}
} else if ( V_73 == 3 || V_73 == 9 ) {
* V_130 = 3 ;
* V_131 = 1 ;
* V_132 = V_73 / 3 ;
} else if ( V_73 == 5 || V_73 == 7 ) {
* V_130 = V_73 ;
* V_131 = 1 ;
* V_132 = 1 ;
} else if ( V_73 == 15 ) {
* V_130 = 3 ;
* V_131 = 1 ;
* V_132 = 5 ;
} else if ( V_73 == 21 ) {
* V_130 = 7 ;
* V_131 = 1 ;
* V_132 = 3 ;
} else if ( V_73 == 35 ) {
* V_130 = 7 ;
* V_131 = 1 ;
* V_132 = 5 ;
}
}
static void F_88 ( struct V_134 * V_135 ,
T_3 V_136 ,
T_3 V_124 ,
T_1 V_130 , T_1 V_131 , T_1 V_132 )
{
T_3 V_125 ;
switch ( V_124 ) {
case 9600000000ULL :
V_135 -> V_124 = 0 ;
break;
case 9000000000ULL :
V_135 -> V_124 = 1 ;
break;
case 8400000000ULL :
V_135 -> V_124 = 3 ;
}
switch ( V_130 ) {
case 1 :
V_135 -> V_137 = 0 ;
break;
case 2 :
V_135 -> V_137 = 1 ;
break;
case 3 :
V_135 -> V_137 = 2 ;
break;
case 7 :
V_135 -> V_137 = 4 ;
break;
default:
F_10 ( 1 , L_18 ) ;
}
switch ( V_132 ) {
case 5 :
V_135 -> V_138 = 0 ;
break;
case 2 :
V_135 -> V_138 = 1 ;
break;
case 3 :
V_135 -> V_138 = 2 ;
break;
case 1 :
V_135 -> V_138 = 3 ;
break;
default:
F_10 ( 1 , L_19 ) ;
}
V_135 -> V_139 = V_131 ;
V_135 -> V_140 = ( V_135 -> V_139 == 1 ) ? 0 : 1 ;
V_125 = V_130 * V_131 * V_132 * V_136 ;
V_135 -> V_141 = F_89 ( V_125 , 24 * F_90 ( 1 ) ) ;
V_135 -> V_142 =
F_89 ( ( F_89 ( V_125 , 24 ) -
V_135 -> V_141 * F_90 ( 1 ) ) * 0x8000 , F_90 ( 1 ) ) ;
}
static bool
F_91 ( int clock ,
struct V_134 * V_143 )
{
T_3 V_136 = clock * 5 ;
T_3 V_144 [ 3 ] = { 8400000000ULL ,
9000000000ULL ,
9600000000ULL } ;
static const int V_145 [] = { 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20 ,
24 , 28 , 30 , 32 , 36 , 40 , 42 , 44 ,
48 , 52 , 54 , 56 , 60 , 64 , 66 , 68 ,
70 , 72 , 76 , 78 , 80 , 84 , 88 , 90 ,
92 , 96 , 98 } ;
static const int V_146 [] = { 3 , 5 , 7 , 9 , 15 , 21 , 35 } ;
static const struct {
const int * V_147 ;
int V_148 ;
} V_149 [] = {
{ V_145 , F_92 (even_dividers) } ,
{ V_146 , F_92 (odd_dividers) } ,
} ;
struct V_120 V_121 ;
unsigned int V_150 , V_79 , V_6 ;
unsigned int V_130 , V_131 , V_132 ;
F_84 ( & V_121 ) ;
for ( V_79 = 0 ; V_79 < F_92 ( V_149 ) ; V_79 ++ ) {
for ( V_150 = 0 ; V_150 < F_92 ( V_144 ) ; V_150 ++ ) {
for ( V_6 = 0 ; V_6 < V_149 [ V_79 ] . V_148 ; V_6 ++ ) {
unsigned int V_73 = V_149 [ V_79 ] . V_147 [ V_6 ] ;
T_3 V_125 = V_73 * V_136 ;
F_85 ( & V_121 ,
V_144 [ V_150 ] ,
V_125 ,
V_73 ) ;
if ( V_121 . V_122 == 0 )
goto V_151;
}
}
V_151:
if ( V_79 == 0 && V_121 . V_73 )
break;
}
if ( ! V_121 . V_73 ) {
F_15 ( L_20 , clock ) ;
return false ;
}
V_130 = V_131 = V_132 = 0 ;
F_87 ( V_121 . V_73 , & V_130 , & V_131 , & V_132 ) ;
F_88 ( V_143 , V_136 , V_121 . V_124 ,
V_130 , V_131 , V_132 ) ;
return true ;
}
static bool F_93 ( struct V_26 * V_27 ,
struct V_40 * V_41 ,
int clock )
{
T_1 V_111 , V_114 , V_115 ;
struct V_134 V_143 = { 0 , } ;
V_111 = F_94 ( 0 ) ;
V_111 |= F_72 ( 0 ) ;
if ( ! F_91 ( clock * 1000 , & V_143 ) )
return false ;
V_114 = V_152 |
F_95 ( V_143 . V_142 ) |
V_143 . V_141 ;
V_115 = F_96 ( V_143 . V_139 ) |
F_97 ( V_143 . V_140 ) |
F_98 ( V_143 . V_138 ) |
F_99 ( V_143 . V_137 ) |
V_143 . V_124 ;
memset ( & V_41 -> V_44 , 0 ,
sizeof( V_41 -> V_44 ) ) ;
V_41 -> V_44 . V_111 = V_111 ;
V_41 -> V_44 . V_114 = V_114 ;
V_41 -> V_44 . V_115 = V_115 ;
return true ;
}
static bool
F_100 ( int clock ,
struct V_21 * V_44 )
{
T_1 V_111 ;
V_111 = F_94 ( 0 ) ;
switch ( clock / 2 ) {
case 81000 :
V_111 |= F_101 ( V_153 , 0 ) ;
break;
case 135000 :
V_111 |= F_101 ( V_154 , 0 ) ;
break;
case 270000 :
V_111 |= F_101 ( V_155 , 0 ) ;
break;
case 162000 :
V_111 |= F_101 ( V_156 , 0 ) ;
break;
case 108000 :
V_111 |= F_101 ( V_157 , 0 ) ;
break;
case 216000 :
V_111 |= F_101 ( V_158 , 0 ) ;
break;
}
V_44 -> V_111 = V_111 ;
return true ;
}
static struct V_8 *
F_102 ( struct V_26 * V_27 , struct V_40 * V_41 ,
struct V_59 * V_60 )
{
struct V_8 * V_9 ;
int clock = V_41 -> V_101 ;
bool V_159 ;
struct V_21 V_44 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
if ( V_60 -> type == V_102 ) {
V_159 = F_93 ( V_27 , V_41 , clock ) ;
if ( ! V_159 ) {
F_20 ( L_21 ) ;
return NULL ;
}
} else if ( V_60 -> type == V_103 ||
V_60 -> type == V_104 ||
V_60 -> type == V_105 ) {
V_159 = F_100 ( clock , & V_44 ) ;
if ( ! V_159 ) {
F_20 ( L_22 ) ;
return NULL ;
}
V_41 -> V_44 = V_44 ;
} else {
return NULL ;
}
if ( V_60 -> type == V_105 )
V_9 = F_24 ( V_27 , V_41 ,
V_160 ,
V_160 ) ;
else
V_9 = F_24 ( V_27 , V_41 ,
V_161 ,
V_162 ) ;
if ( ! V_9 )
return NULL ;
F_25 ( V_9 , V_41 ) ;
return V_9 ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
F_20 ( L_23
L_24 ,
V_22 -> V_111 ,
V_22 -> V_114 ,
V_22 -> V_115 ) ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_1 V_163 ;
enum V_164 V_164 = (enum V_164 ) V_9 -> V_19 ;
enum V_165 V_166 ;
enum V_167 V_168 ;
F_105 ( V_2 , V_164 , & V_166 , & V_168 ) ;
V_163 = F_31 ( F_106 ( V_164 ) ) ;
V_163 |= V_169 ;
F_37 ( F_106 ( V_164 ) , V_163 ) ;
if ( F_107 ( V_2 ) ) {
V_163 = F_31 ( F_106 ( V_164 ) ) ;
V_163 |= V_170 ;
F_37 ( F_106 ( V_164 ) , V_163 ) ;
if ( F_108 ( ( F_31 ( F_106 ( V_164 ) ) &
V_171 ) , 200 ) )
F_78 ( L_25 , V_164 ) ;
}
V_163 = F_31 ( F_109 ( V_166 , V_168 ) ) ;
V_163 &= ~ V_172 ;
F_37 ( F_109 ( V_166 , V_168 ) , V_163 ) ;
V_163 = F_31 ( F_110 ( V_166 , V_168 ) ) ;
V_163 &= ~ ( V_173 | V_174 ) ;
V_163 |= V_9 -> V_11 . V_22 . V_175 ;
F_37 ( F_110 ( V_166 , V_168 ) , V_163 ) ;
V_163 = F_31 ( F_111 ( V_166 , V_168 , 0 ) ) ;
V_163 &= ~ V_176 ;
V_163 |= V_9 -> V_11 . V_22 . V_177 ;
F_37 ( F_111 ( V_166 , V_168 , 0 ) , V_163 ) ;
V_163 = F_31 ( F_111 ( V_166 , V_168 , 1 ) ) ;
V_163 &= ~ V_178 ;
V_163 |= V_9 -> V_11 . V_22 . V_179 ;
F_37 ( F_111 ( V_166 , V_168 , 1 ) , V_163 ) ;
V_163 = F_31 ( F_111 ( V_166 , V_168 , 2 ) ) ;
V_163 &= ~ V_180 ;
V_163 |= V_9 -> V_11 . V_22 . V_181 ;
F_37 ( F_111 ( V_166 , V_168 , 2 ) , V_163 ) ;
V_163 = F_31 ( F_111 ( V_166 , V_168 , 3 ) ) ;
V_163 &= ~ V_182 ;
V_163 |= V_9 -> V_11 . V_22 . V_183 ;
F_37 ( F_111 ( V_166 , V_168 , 3 ) , V_163 ) ;
V_163 = F_31 ( F_111 ( V_166 , V_168 , 6 ) ) ;
V_163 &= ~ V_184 ;
V_163 &= ~ V_185 ;
V_163 &= ~ V_186 ;
V_163 |= V_9 -> V_11 . V_22 . V_187 ;
F_37 ( F_111 ( V_166 , V_168 , 6 ) , V_163 ) ;
V_163 = F_31 ( F_111 ( V_166 , V_168 , 8 ) ) ;
V_163 &= ~ V_188 ;
V_163 |= V_9 -> V_11 . V_22 . V_189 ;
F_37 ( F_111 ( V_166 , V_168 , 8 ) , V_163 ) ;
V_163 = F_31 ( F_111 ( V_166 , V_168 , 9 ) ) ;
V_163 &= ~ V_190 ;
V_163 |= V_9 -> V_11 . V_22 . V_191 ;
F_37 ( F_111 ( V_166 , V_168 , 9 ) , V_163 ) ;
V_163 = F_31 ( F_111 ( V_166 , V_168 , 10 ) ) ;
V_163 &= ~ V_192 ;
V_163 &= ~ V_193 ;
V_163 |= V_9 -> V_11 . V_22 . V_194 ;
F_37 ( F_111 ( V_166 , V_168 , 10 ) , V_163 ) ;
V_163 = F_31 ( F_109 ( V_166 , V_168 ) ) ;
V_163 |= V_195 ;
F_37 ( F_109 ( V_166 , V_168 ) , V_163 ) ;
V_163 &= ~ V_172 ;
V_163 |= V_9 -> V_11 . V_22 . V_196 ;
F_37 ( F_109 ( V_166 , V_168 ) , V_163 ) ;
V_163 = F_31 ( F_106 ( V_164 ) ) ;
V_163 |= V_197 ;
F_37 ( F_106 ( V_164 ) , V_163 ) ;
F_43 ( F_106 ( V_164 ) ) ;
if ( F_108 ( ( F_31 ( F_106 ( V_164 ) ) & V_198 ) ,
200 ) )
F_78 ( L_26 , V_164 ) ;
if ( F_107 ( V_2 ) ) {
V_163 = F_31 ( F_112 ( V_166 , V_168 ) ) ;
V_163 |= V_199 ;
F_37 ( F_113 ( V_166 , V_168 ) , V_163 ) ;
}
V_163 = F_31 ( F_114 ( V_166 , V_168 ) ) ;
V_163 &= ~ V_200 ;
V_163 &= ~ V_201 ;
V_163 |= V_9 -> V_11 . V_22 . V_202 ;
F_37 ( F_115 ( V_166 , V_168 ) , V_163 ) ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
enum V_164 V_164 = (enum V_164 ) V_9 -> V_19 ;
T_1 V_163 ;
V_163 = F_31 ( F_106 ( V_164 ) ) ;
V_163 &= ~ V_197 ;
F_37 ( F_106 ( V_164 ) , V_163 ) ;
F_43 ( F_106 ( V_164 ) ) ;
if ( F_107 ( V_2 ) ) {
V_163 = F_31 ( F_106 ( V_164 ) ) ;
V_163 &= ~ V_170 ;
F_37 ( F_106 ( V_164 ) , V_163 ) ;
if ( F_108 ( ! ( F_31 ( F_106 ( V_164 ) ) &
V_171 ) , 200 ) )
F_78 ( L_27 , V_164 ) ;
}
}
static bool F_117 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_21 * V_22 )
{
enum V_164 V_164 = (enum V_164 ) V_9 -> V_19 ;
T_1 V_47 ;
bool V_119 ;
enum V_165 V_166 ;
enum V_167 V_168 ;
F_105 ( V_2 , V_164 , & V_166 , & V_168 ) ;
if ( ! F_30 ( V_2 , V_48 ) )
return false ;
V_119 = false ;
V_47 = F_31 ( F_106 ( V_164 ) ) ;
if ( ! ( V_47 & V_197 ) )
goto V_37;
V_22 -> V_175 = F_31 ( F_110 ( V_166 , V_168 ) ) ;
V_22 -> V_175 &= V_173 | V_174 ;
V_22 -> V_196 = F_31 ( F_109 ( V_166 , V_168 ) ) ;
V_22 -> V_196 &= V_172 ;
V_22 -> V_177 = F_31 ( F_111 ( V_166 , V_168 , 0 ) ) ;
V_22 -> V_177 &= V_176 ;
V_22 -> V_179 = F_31 ( F_111 ( V_166 , V_168 , 1 ) ) ;
V_22 -> V_179 &= V_178 ;
V_22 -> V_181 = F_31 ( F_111 ( V_166 , V_168 , 2 ) ) ;
V_22 -> V_181 &= V_180 ;
V_22 -> V_183 = F_31 ( F_111 ( V_166 , V_168 , 3 ) ) ;
V_22 -> V_183 &= V_182 ;
V_22 -> V_187 = F_31 ( F_111 ( V_166 , V_168 , 6 ) ) ;
V_22 -> V_187 &= V_184 |
V_185 |
V_186 ;
V_22 -> V_189 = F_31 ( F_111 ( V_166 , V_168 , 8 ) ) ;
V_22 -> V_189 &= V_188 ;
V_22 -> V_191 = F_31 ( F_111 ( V_166 , V_168 , 9 ) ) ;
V_22 -> V_191 &= V_190 ;
V_22 -> V_194 = F_31 ( F_111 ( V_166 , V_168 , 10 ) ) ;
V_22 -> V_194 &= V_192 |
V_193 ;
V_22 -> V_202 = F_31 ( F_114 ( V_166 , V_168 ) ) ;
if ( F_31 ( F_118 ( V_166 , V_168 ) ) != V_22 -> V_202 )
F_15 ( L_28 ,
V_22 -> V_202 ,
F_31 ( F_118 ( V_166 , V_168 ) ) ) ;
V_22 -> V_202 &= V_200 | V_201 ;
V_119 = true ;
V_37:
F_35 ( V_2 , V_48 ) ;
return V_119 ;
}
static bool
F_119 ( struct V_26 * V_26 ,
struct V_40 * V_41 , int clock ,
struct V_203 * V_204 )
{
struct V_49 V_205 ;
if ( ! F_120 ( V_41 , clock , & V_205 ) ) {
F_15 ( L_29 ,
clock , F_27 ( V_26 -> V_45 ) ) ;
return false ;
}
V_204 -> V_131 = V_205 . V_131 ;
V_204 -> V_132 = V_205 . V_132 ;
F_4 ( V_205 . V_206 != 2 ) ;
V_204 -> V_207 = V_205 . V_207 ;
V_204 -> V_208 = V_205 . V_209 >> 22 ;
V_204 -> V_210 = V_205 . V_209 & ( ( 1 << 22 ) - 1 ) ;
V_204 -> V_211 = V_204 -> V_210 != 0 ;
V_204 -> V_212 = V_205 . V_212 ;
return true ;
}
static void F_121 ( int clock , struct V_203 * V_204 )
{
int V_6 ;
* V_204 = V_213 [ 0 ] ;
for ( V_6 = 0 ; V_6 < F_92 ( V_213 ) ; ++ V_6 ) {
if ( V_213 [ V_6 ] . clock == clock ) {
* V_204 = V_213 [ V_6 ] ;
break;
}
}
V_204 -> V_212 = clock * 10 / 2 * V_204 -> V_131 * V_204 -> V_132 ;
}
static bool F_122 ( int clock ,
struct V_203 * V_204 ,
struct V_21 * V_44 )
{
int V_212 = V_204 -> V_212 ;
T_1 V_214 , V_215 , V_216 , V_217 ;
T_1 V_218 ;
if ( V_212 >= 6200000 && V_212 <= 6700000 ) {
V_214 = 4 ;
V_215 = 9 ;
V_216 = 3 ;
V_217 = 8 ;
} else if ( ( V_212 > 5400000 && V_212 < 6200000 ) ||
( V_212 >= 4800000 && V_212 < 5400000 ) ) {
V_214 = 5 ;
V_215 = 11 ;
V_216 = 3 ;
V_217 = 9 ;
} else if ( V_212 == 5400000 ) {
V_214 = 3 ;
V_215 = 8 ;
V_216 = 1 ;
V_217 = 9 ;
} else {
F_78 ( L_30 ) ;
return false ;
}
if ( clock > 270000 )
V_218 = 0x18 ;
else if ( clock > 135000 )
V_218 = 0x0d ;
else if ( clock > 67000 )
V_218 = 0x07 ;
else if ( clock > 33000 )
V_218 = 0x04 ;
else
V_218 = 0x02 ;
V_44 -> V_175 = F_123 ( V_204 -> V_131 ) | F_124 ( V_204 -> V_132 ) ;
V_44 -> V_177 = V_204 -> V_208 ;
V_44 -> V_179 = F_125 ( V_204 -> V_207 ) ;
V_44 -> V_181 = V_204 -> V_210 ;
if ( V_204 -> V_211 )
V_44 -> V_183 = V_182 ;
V_44 -> V_187 = V_214 | F_126 ( V_215 ) ;
V_44 -> V_187 |= F_127 ( V_216 ) ;
V_44 -> V_189 = V_217 ;
V_44 -> V_191 = 5 << V_219 ;
V_44 -> V_194 =
F_128 ( V_220 )
| V_192 ;
V_44 -> V_196 = V_172 ;
V_44 -> V_202 = V_201 | V_218 ;
return true ;
}
static bool
F_129 ( int clock ,
struct V_21 * V_44 )
{
struct V_203 V_204 = { 0 } ;
F_121 ( clock , & V_204 ) ;
return F_122 ( clock , & V_204 , V_44 ) ;
}
static bool
F_130 ( struct V_26 * V_26 ,
struct V_40 * V_41 , int clock ,
struct V_21 * V_44 )
{
struct V_203 V_204 = { } ;
F_119 ( V_26 , V_41 , clock , & V_204 ) ;
return F_122 ( clock , & V_204 , V_44 ) ;
}
static struct V_8 *
F_131 ( struct V_26 * V_27 ,
struct V_40 * V_41 ,
struct V_59 * V_60 )
{
struct V_21 V_44 = { } ;
struct V_1 * V_2 = F_6 ( V_27 -> V_29 . V_15 ) ;
struct V_221 * V_222 ;
struct V_8 * V_9 ;
int V_6 , clock = V_41 -> V_101 ;
if ( V_60 -> type == V_102 &&
! F_130 ( V_27 , V_41 , clock ,
& V_44 ) )
return NULL ;
if ( ( V_60 -> type == V_103 ||
V_60 -> type == V_105 ||
V_60 -> type == V_104 ) &&
! F_129 ( clock , & V_44 ) )
return NULL ;
memset ( & V_41 -> V_44 , 0 ,
sizeof( V_41 -> V_44 ) ) ;
V_41 -> V_44 = V_44 ;
if ( V_60 -> type == V_104 ) {
struct V_223 * V_224 = F_132 ( & V_60 -> V_29 ) ;
V_222 = V_224 -> V_225 ;
} else
V_222 = F_133 ( & V_60 -> V_29 ) ;
V_6 = (enum V_5 ) V_222 -> V_164 ;
V_9 = F_7 ( V_2 , V_6 ) ;
F_20 ( L_12 ,
V_27 -> V_29 . V_29 . V_19 , V_27 -> V_29 . V_25 , V_9 -> V_25 ) ;
F_25 ( V_9 , V_41 ) ;
return V_9 ;
}
static void F_134 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
F_20 ( L_31
L_32
L_33 ,
V_22 -> V_175 ,
V_22 -> V_196 ,
V_22 -> V_177 ,
V_22 -> V_179 ,
V_22 -> V_181 ,
V_22 -> V_183 ,
V_22 -> V_187 ,
V_22 -> V_189 ,
V_22 -> V_191 ,
V_22 -> V_194 ,
V_22 -> V_202 ) ;
}
static void F_135 ( struct V_28 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
if ( F_23 ( V_2 ) < 9 ) {
T_1 V_47 = F_31 ( V_226 ) ;
if ( V_47 & V_227 )
F_78 ( L_34 ) ;
if ( V_47 & V_228 )
F_78 ( L_35 ) ;
}
}
void F_136 ( struct V_28 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
const struct V_229 * V_230 = NULL ;
const struct V_231 * V_231 ;
int V_6 ;
if ( F_137 ( V_2 ) )
V_230 = & V_232 ;
else if ( F_138 ( V_2 ) )
V_230 = & V_233 ;
else if ( F_139 ( V_2 ) )
V_230 = & V_234 ;
else if ( F_40 ( V_2 ) || F_41 ( V_2 ) )
V_230 = & V_235 ;
if ( ! V_230 ) {
V_2 -> V_7 = 0 ;
return;
}
V_231 = V_230 -> V_231 ;
for ( V_6 = 0 ; V_231 [ V_6 ] . V_19 >= 0 ; V_6 ++ ) {
F_4 ( V_6 != V_231 [ V_6 ] . V_19 ) ;
V_2 -> V_10 [ V_6 ] . V_19 = V_231 [ V_6 ] . V_19 ;
V_2 -> V_10 [ V_6 ] . V_25 = V_231 [ V_6 ] . V_25 ;
V_2 -> V_10 [ V_6 ] . V_23 = * V_231 [ V_6 ] . V_23 ;
V_2 -> V_10 [ V_6 ] . V_236 = V_231 [ V_6 ] . V_236 ;
}
V_2 -> V_230 = V_230 ;
V_2 -> V_7 = V_6 ;
F_140 ( & V_2 -> V_31 ) ;
F_141 ( V_2 -> V_7 > V_237 ) ;
if ( F_139 ( V_2 ) )
F_135 ( V_15 ) ;
}
struct V_8 *
F_142 ( struct V_26 * V_27 ,
struct V_40 * V_41 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_6 ( V_27 -> V_29 . V_15 ) ;
const struct V_229 * V_230 = V_2 -> V_230 ;
if ( F_4 ( ! V_230 ) )
return NULL ;
return V_230 -> V_238 ( V_27 , V_41 , V_60 ) ;
}
void F_143 ( struct V_8 * V_49 ,
struct V_26 * V_27 ,
struct V_12 * V_11 )
{
struct V_3 * V_239 ;
V_239 = F_2 ( V_11 ) ;
V_239 [ V_49 -> V_19 ] . V_32 &= ~ ( 1 << V_27 -> V_45 ) ;
}
void F_144 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
if ( V_2 -> V_230 ) {
V_2 -> V_230 -> V_240 ( V_2 , V_22 ) ;
} else {
F_20 ( L_13
L_14 ,
V_22 -> V_49 ,
V_22 -> V_63 ,
V_22 -> V_50 ,
V_22 -> V_51 ) ;
}
}
