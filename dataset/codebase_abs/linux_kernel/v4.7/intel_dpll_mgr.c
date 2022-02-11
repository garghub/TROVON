struct V_1 *
F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
return & V_3 -> V_6 [ V_5 ] ;
}
enum V_4
F_2 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
if ( F_3 ( V_7 < V_3 -> V_6 ||
V_7 > & V_3 -> V_6 [ V_3 -> V_8 ] ) )
return - 1 ;
return (enum V_4 ) ( V_7 - V_3 -> V_6 ) ;
}
void
F_4 ( struct V_9 * V_10 ,
struct V_1 * V_7 ,
struct V_11 * V_12 )
{
struct V_2 * V_3 = F_5 ( V_12 -> V_13 . V_14 ) ;
enum V_4 V_5 = F_2 ( V_3 , V_7 ) ;
V_10 [ V_5 ] . V_15 |= 1 << V_12 -> V_16 ;
}
void
F_6 ( struct V_9 * V_10 ,
struct V_1 * V_7 ,
struct V_11 * V_12 )
{
struct V_2 * V_3 = F_5 ( V_12 -> V_13 . V_14 ) ;
enum V_4 V_5 = F_2 ( V_3 , V_7 ) ;
V_10 [ V_5 ] . V_15 &= ~ ( 1 << V_12 -> V_16 ) ;
}
void F_7 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
bool V_17 )
{
bool V_18 ;
struct V_19 V_20 ;
if ( F_8 ( ! V_7 , L_1 , F_9 ( V_17 ) ) )
return;
V_18 = V_7 -> V_21 . V_22 ( V_3 , V_7 , & V_20 ) ;
F_10 ( V_18 != V_17 ,
L_2 ,
V_7 -> V_23 , F_9 ( V_17 ) , F_9 ( V_18 ) ) ;
}
void F_11 ( struct V_11 * V_12 )
{
struct V_24 * V_14 = V_12 -> V_13 . V_14 ;
struct V_2 * V_3 = V_14 -> V_25 ;
struct V_1 * V_7 = V_12 -> V_10 -> V_26 ;
if ( F_3 ( V_7 == NULL ) )
return;
F_12 ( & V_3 -> V_27 ) ;
F_3 ( ! V_7 -> V_10 . V_15 ) ;
if ( ! V_7 -> V_28 ) {
F_13 ( L_3 , V_7 -> V_23 ) ;
F_3 ( V_7 -> V_29 ) ;
F_14 ( V_3 , V_7 ) ;
V_7 -> V_21 . V_30 ( V_3 , V_7 ) ;
}
F_15 ( & V_3 -> V_27 ) ;
}
void F_16 ( struct V_11 * V_12 )
{
struct V_24 * V_14 = V_12 -> V_13 . V_14 ;
struct V_2 * V_3 = V_14 -> V_25 ;
struct V_1 * V_7 = V_12 -> V_10 -> V_26 ;
unsigned V_15 = 1 << F_17 ( & V_12 -> V_13 ) ;
unsigned V_31 ;
if ( F_3 ( V_7 == NULL ) )
return;
F_12 ( & V_3 -> V_27 ) ;
V_31 = V_7 -> V_28 ;
if ( F_3 ( ! ( V_7 -> V_10 . V_15 & V_15 ) ) ||
F_3 ( V_7 -> V_28 & V_15 ) )
goto V_32;
V_7 -> V_28 |= V_15 ;
F_18 ( L_4 ,
V_7 -> V_23 , V_7 -> V_28 , V_7 -> V_29 ,
V_12 -> V_13 . V_13 . V_5 ) ;
if ( V_31 ) {
F_3 ( ! V_7 -> V_29 ) ;
F_19 ( V_3 , V_7 ) ;
goto V_32;
}
F_3 ( V_7 -> V_29 ) ;
F_18 ( L_5 , V_7 -> V_23 ) ;
V_7 -> V_21 . V_33 ( V_3 , V_7 ) ;
V_7 -> V_29 = true ;
V_32:
F_15 ( & V_3 -> V_27 ) ;
}
void F_20 ( struct V_11 * V_12 )
{
struct V_24 * V_14 = V_12 -> V_13 . V_14 ;
struct V_2 * V_3 = V_14 -> V_25 ;
struct V_1 * V_7 = V_12 -> V_10 -> V_26 ;
unsigned V_15 = 1 << F_17 ( & V_12 -> V_13 ) ;
if ( F_21 ( V_14 ) -> V_34 < 5 )
return;
if ( V_7 == NULL )
return;
F_12 ( & V_3 -> V_27 ) ;
if ( F_3 ( ! ( V_7 -> V_28 & V_15 ) ) )
goto V_32;
F_18 ( L_6 ,
V_7 -> V_23 , V_7 -> V_28 , V_7 -> V_29 ,
V_12 -> V_13 . V_13 . V_5 ) ;
F_19 ( V_3 , V_7 ) ;
F_3 ( ! V_7 -> V_29 ) ;
V_7 -> V_28 &= ~ V_15 ;
if ( V_7 -> V_28 )
goto V_32;
F_18 ( L_7 , V_7 -> V_23 ) ;
V_7 -> V_21 . V_35 ( V_3 , V_7 ) ;
V_7 -> V_29 = false ;
V_32:
F_15 ( & V_3 -> V_27 ) ;
}
static struct V_1 *
F_22 ( struct V_11 * V_12 ,
struct V_36 * V_37 ,
enum V_4 V_38 ,
enum V_4 V_39 )
{
struct V_2 * V_3 = V_12 -> V_13 . V_14 -> V_25 ;
struct V_1 * V_7 ;
struct V_9 * V_26 ;
enum V_4 V_40 ;
V_26 = F_23 ( V_37 -> V_13 . V_17 ) ;
for ( V_40 = V_38 ; V_40 <= V_39 ; V_40 ++ ) {
V_7 = & V_3 -> V_6 [ V_40 ] ;
if ( V_26 [ V_40 ] . V_15 == 0 )
continue;
if ( memcmp ( & V_37 -> V_41 ,
& V_26 [ V_40 ] . V_20 ,
sizeof( V_37 -> V_41 ) ) == 0 ) {
F_18 ( L_8 ,
V_12 -> V_13 . V_13 . V_5 , V_7 -> V_23 ,
V_26 [ V_40 ] . V_15 ,
V_7 -> V_28 ) ;
return V_7 ;
}
}
for ( V_40 = V_38 ; V_40 <= V_39 ; V_40 ++ ) {
V_7 = & V_3 -> V_6 [ V_40 ] ;
if ( V_26 [ V_40 ] . V_15 == 0 ) {
F_18 ( L_9 ,
V_12 -> V_13 . V_13 . V_5 , V_7 -> V_23 ) ;
return V_7 ;
}
}
return NULL ;
}
static void
F_24 ( struct V_1 * V_7 ,
struct V_36 * V_37 )
{
struct V_9 * V_26 ;
struct V_11 * V_12 = F_25 ( V_37 -> V_13 . V_12 ) ;
enum V_4 V_40 = V_7 -> V_5 ;
V_26 = F_23 ( V_37 -> V_13 . V_17 ) ;
if ( V_26 [ V_40 ] . V_15 == 0 )
V_26 [ V_40 ] . V_20 =
V_37 -> V_41 ;
V_37 -> V_26 = V_7 ;
F_13 ( L_10 , V_7 -> V_23 ,
F_26 ( V_12 -> V_16 ) ) ;
F_4 ( V_26 , V_7 , V_12 ) ;
}
void F_27 ( struct V_42 * V_17 )
{
struct V_2 * V_3 = F_5 ( V_17 -> V_14 ) ;
struct V_9 * V_26 ;
struct V_1 * V_7 ;
enum V_4 V_40 ;
if ( ! F_28 ( V_17 ) -> V_43 )
return;
V_26 = F_28 ( V_17 ) -> V_26 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_8 ; V_40 ++ ) {
V_7 = & V_3 -> V_6 [ V_40 ] ;
V_7 -> V_10 = V_26 [ V_40 ] ;
}
}
static bool F_29 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_19 * V_20 )
{
T_1 V_44 ;
if ( ! F_30 ( V_3 , V_45 ) )
return false ;
V_44 = F_31 ( F_32 ( V_7 -> V_5 ) ) ;
V_20 -> V_46 = V_44 ;
V_20 -> V_47 = F_31 ( F_33 ( V_7 -> V_5 ) ) ;
V_20 -> V_48 = F_31 ( F_34 ( V_7 -> V_5 ) ) ;
F_35 ( V_3 , V_45 ) ;
return V_44 & V_49 ;
}
static void F_36 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
F_37 ( F_33 ( V_7 -> V_5 ) , V_7 -> V_10 . V_20 . V_47 ) ;
F_37 ( F_34 ( V_7 -> V_5 ) , V_7 -> V_10 . V_20 . V_48 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
T_2 V_44 ;
bool V_50 ;
F_39 ( ! ( F_40 ( V_3 ) || F_41 ( V_3 ) ) ) ;
V_44 = F_31 ( V_51 ) ;
V_50 = ! ! ( V_44 & ( V_52 | V_53 |
V_54 ) ) ;
F_10 ( ! V_50 , L_11 ) ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
F_38 ( V_3 ) ;
F_37 ( F_32 ( V_7 -> V_5 ) , V_7 -> V_10 . V_20 . V_46 ) ;
F_43 ( F_32 ( V_7 -> V_5 ) ) ;
F_44 ( 150 ) ;
F_37 ( F_32 ( V_7 -> V_5 ) , V_7 -> V_10 . V_20 . V_46 ) ;
F_43 ( F_32 ( V_7 -> V_5 ) ) ;
F_44 ( 200 ) ;
}
static void F_45 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
struct V_24 * V_14 = V_3 -> V_14 ;
struct V_11 * V_12 ;
F_46 (dev, crtc) {
if ( V_12 -> V_10 -> V_26 == V_7 )
F_47 ( V_3 , V_12 -> V_16 ) ;
}
F_37 ( F_32 ( V_7 -> V_5 ) , 0 ) ;
F_43 ( F_32 ( V_7 -> V_5 ) ) ;
F_44 ( 200 ) ;
}
static struct V_1 *
F_48 ( struct V_11 * V_12 , struct V_36 * V_37 ,
struct V_55 * V_56 )
{
struct V_2 * V_3 = F_5 ( V_12 -> V_13 . V_14 ) ;
struct V_1 * V_7 ;
enum V_4 V_40 ;
if ( F_40 ( V_3 ) ) {
V_40 = (enum V_4 ) V_12 -> V_16 ;
V_7 = & V_3 -> V_6 [ V_40 ] ;
F_18 ( L_12 ,
V_12 -> V_13 . V_13 . V_5 , V_7 -> V_23 ) ;
} else {
V_7 = F_22 ( V_12 , V_37 ,
V_57 ,
V_58 ) ;
}
if ( ! V_7 )
return NULL ;
F_24 ( V_7 , V_37 ) ;
return V_7 ;
}
static void F_49 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
F_37 ( F_50 ( V_7 -> V_5 ) , V_7 -> V_10 . V_20 . V_59 ) ;
F_43 ( F_50 ( V_7 -> V_5 ) ) ;
F_44 ( 20 ) ;
}
static void F_51 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
F_37 ( V_60 , V_7 -> V_10 . V_20 . V_61 ) ;
F_43 ( V_60 ) ;
F_44 ( 20 ) ;
}
static void F_52 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
T_1 V_44 ;
V_44 = F_31 ( F_50 ( V_7 -> V_5 ) ) ;
F_37 ( F_50 ( V_7 -> V_5 ) , V_44 & ~ V_62 ) ;
F_43 ( F_50 ( V_7 -> V_5 ) ) ;
}
static void F_53 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
T_1 V_44 ;
V_44 = F_31 ( V_60 ) ;
F_37 ( V_60 , V_44 & ~ V_63 ) ;
F_43 ( V_60 ) ;
}
static bool F_54 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_19 * V_20 )
{
T_1 V_44 ;
if ( ! F_30 ( V_3 , V_45 ) )
return false ;
V_44 = F_31 ( F_50 ( V_7 -> V_5 ) ) ;
V_20 -> V_59 = V_44 ;
F_35 ( V_3 , V_45 ) ;
return V_44 & V_62 ;
}
static bool F_55 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_19 * V_20 )
{
T_1 V_44 ;
if ( ! F_30 ( V_3 , V_45 ) )
return false ;
V_44 = F_31 ( V_60 ) ;
V_20 -> V_61 = V_44 ;
F_35 ( V_3 , V_45 ) ;
return V_44 & V_63 ;
}
static T_1 F_56 ( struct V_1 * V_7 )
{
switch ( V_7 -> V_5 ) {
case V_64 :
return V_65 ;
case V_66 :
return V_67 ;
case V_68 :
return V_69 ;
case V_70 :
return V_71 ;
case V_72 :
return V_73 ;
case V_74 :
return V_75 ;
default:
return V_76 ;
}
}
static unsigned F_57 ( int clock )
{
unsigned V_77 ;
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
V_77 = 0 ;
break;
case 233500000 :
case 245250000 :
case 247750000 :
case 253250000 :
case 298000000 :
V_77 = 1500 ;
break;
case 169128000 :
case 169500000 :
case 179500000 :
case 202000000 :
V_77 = 2000 ;
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
V_77 = 4000 ;
break;
case 267250000 :
case 268500000 :
V_77 = 5000 ;
break;
default:
V_77 = 1000 ;
break;
}
return V_77 ;
}
static void F_58 ( T_3 V_78 , unsigned V_77 ,
unsigned V_79 , unsigned V_80 , unsigned V_81 ,
struct V_82 * V_83 )
{
T_3 V_84 , V_85 , V_86 , V_87 , V_88 , V_89 ;
if ( V_83 -> V_81 == 0 ) {
V_83 -> V_81 = V_81 ;
V_83 -> V_80 = V_80 ;
V_83 -> V_79 = V_79 ;
return;
}
V_84 = V_78 * V_77 * V_81 * V_79 ;
V_85 = V_78 * V_77 * V_83 -> V_81 * V_83 -> V_79 ;
V_88 = F_59 ( V_78 * V_81 * V_79 , V_90 * V_80 ) ;
V_89 = F_59 ( V_78 * V_83 -> V_81 * V_83 -> V_79 ,
V_90 * V_83 -> V_80 ) ;
V_86 = 1000000 * V_88 ;
V_87 = 1000000 * V_89 ;
if ( V_84 < V_86 && V_85 < V_87 ) {
if ( V_83 -> V_81 * V_83 -> V_79 * V_88 < V_81 * V_79 * V_89 ) {
V_83 -> V_81 = V_81 ;
V_83 -> V_80 = V_80 ;
V_83 -> V_79 = V_79 ;
}
} else if ( V_84 >= V_86 && V_85 < V_87 ) {
V_83 -> V_81 = V_81 ;
V_83 -> V_80 = V_80 ;
V_83 -> V_79 = V_79 ;
} else if ( V_84 >= V_86 && V_85 >= V_87 ) {
if ( V_80 * V_83 -> V_79 * V_83 -> V_79 > V_83 -> V_80 * V_79 * V_79 ) {
V_83 -> V_81 = V_81 ;
V_83 -> V_80 = V_80 ;
V_83 -> V_79 = V_79 ;
}
}
}
static void
F_60 ( int clock ,
unsigned * V_91 , unsigned * V_92 , unsigned * V_93 )
{
T_3 V_78 ;
unsigned V_81 , V_80 , V_79 ;
struct V_82 V_83 = { 0 , 0 , 0 } ;
unsigned V_77 ;
V_78 = clock / 100 ;
V_77 = F_57 ( clock ) ;
if ( V_78 == 5400000 ) {
* V_92 = 2 ;
* V_93 = 1 ;
* V_91 = 2 ;
return;
}
for ( V_79 = V_94 * 2 / V_95 + 1 ;
V_79 <= V_94 * 2 / V_96 ;
V_79 ++ ) {
for ( V_80 = V_97 * V_79 / V_94 + 1 ;
V_80 <= V_98 * V_79 / V_94 ;
V_80 ++ ) {
for ( V_81 = V_99 ; V_81 <= V_100 ; V_81 += V_101 )
F_58 ( V_78 , V_77 ,
V_79 , V_80 , V_81 , & V_83 ) ;
}
}
* V_92 = V_83 . V_80 ;
* V_93 = V_83 . V_81 ;
* V_91 = V_83 . V_79 ;
}
static struct V_1 *
F_61 ( struct V_11 * V_12 , struct V_36 * V_37 ,
struct V_55 * V_56 )
{
struct V_2 * V_3 = F_5 ( V_12 -> V_13 . V_14 ) ;
struct V_1 * V_7 ;
int clock = V_37 -> V_102 ;
memset ( & V_37 -> V_41 , 0 ,
sizeof( V_37 -> V_41 ) ) ;
if ( V_56 -> type == V_103 ) {
T_1 V_44 ;
unsigned V_81 , V_80 , V_79 ;
F_60 ( clock * 1000 , & V_79 , & V_80 , & V_81 ) ;
V_44 = V_62 | V_104 |
F_62 ( V_79 ) | F_63 ( V_80 ) |
F_64 ( V_81 ) ;
V_37 -> V_41 . V_59 = V_44 ;
V_7 = F_22 ( V_12 , V_37 ,
V_64 , V_66 ) ;
} else if ( V_56 -> type == V_105 ||
V_56 -> type == V_106 ||
V_56 -> type == V_107 ) {
enum V_4 V_108 ;
switch ( clock / 2 ) {
case 81000 :
V_108 = V_70 ;
break;
case 135000 :
V_108 = V_72 ;
break;
case 270000 :
V_108 = V_74 ;
break;
default:
F_18 ( L_13 , clock ) ;
return NULL ;
}
V_7 = F_1 ( V_3 , V_108 ) ;
} else if ( V_56 -> type == V_109 ) {
if ( F_3 ( V_37 -> V_102 / 2 != 135000 ) )
return NULL ;
V_37 -> V_41 . V_61 =
V_63 | V_110 | V_111 ;
V_7 = F_22 ( V_12 , V_37 ,
V_68 , V_68 ) ;
} else {
return NULL ;
}
if ( ! V_7 )
return NULL ;
V_37 -> V_112 = F_56 ( V_7 ) ;
F_24 ( V_7 , V_37 ) ;
return V_7 ;
}
static void F_65 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
}
static void F_66 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
}
static bool F_67 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_19 * V_20 )
{
return true ;
}
static void F_68 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
T_1 V_44 ;
V_44 = F_31 ( V_113 ) ;
V_44 &= ~ ( F_69 ( V_7 -> V_5 ) | F_70 ( V_7 -> V_5 ) |
F_71 ( V_7 -> V_5 ) ) ;
V_44 |= V_7 -> V_10 . V_20 . V_114 << ( V_7 -> V_5 * 6 ) ;
F_37 ( V_113 , V_44 ) ;
F_43 ( V_113 ) ;
}
static void F_72 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
const struct V_115 * V_116 = V_115 ;
F_68 ( V_3 , V_7 ) ;
F_37 ( V_116 [ V_7 -> V_5 ] . V_117 , V_7 -> V_10 . V_20 . V_117 ) ;
F_37 ( V_116 [ V_7 -> V_5 ] . V_118 , V_7 -> V_10 . V_20 . V_118 ) ;
F_43 ( V_116 [ V_7 -> V_5 ] . V_117 ) ;
F_43 ( V_116 [ V_7 -> V_5 ] . V_118 ) ;
F_37 ( V_116 [ V_7 -> V_5 ] . V_119 ,
F_31 ( V_116 [ V_7 -> V_5 ] . V_119 ) | V_120 ) ;
if ( F_73 ( F_31 ( V_121 ) & F_74 ( V_7 -> V_5 ) , 5 ) )
F_75 ( L_14 , V_7 -> V_5 ) ;
}
static void F_76 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
F_68 ( V_3 , V_7 ) ;
}
static void F_77 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
const struct V_115 * V_116 = V_115 ;
F_37 ( V_116 [ V_7 -> V_5 ] . V_119 ,
F_31 ( V_116 [ V_7 -> V_5 ] . V_119 ) & ~ V_120 ) ;
F_43 ( V_116 [ V_7 -> V_5 ] . V_119 ) ;
}
static void F_78 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
}
static bool F_79 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_19 * V_20 )
{
T_1 V_44 ;
const struct V_115 * V_116 = V_115 ;
bool V_122 ;
if ( ! F_30 ( V_3 , V_45 ) )
return false ;
V_122 = false ;
V_44 = F_31 ( V_116 [ V_7 -> V_5 ] . V_119 ) ;
if ( ! ( V_44 & V_120 ) )
goto V_32;
V_44 = F_31 ( V_113 ) ;
V_20 -> V_114 = ( V_44 >> ( V_7 -> V_5 * 6 ) ) & 0x3f ;
if ( V_44 & F_69 ( V_7 -> V_5 ) ) {
V_20 -> V_117 = F_31 ( V_116 [ V_7 -> V_5 ] . V_117 ) ;
V_20 -> V_118 = F_31 ( V_116 [ V_7 -> V_5 ] . V_118 ) ;
}
V_122 = true ;
V_32:
F_35 ( V_3 , V_45 ) ;
return V_122 ;
}
static bool F_80 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_19 * V_20 )
{
T_1 V_44 ;
const struct V_115 * V_116 = V_115 ;
bool V_122 ;
if ( ! F_30 ( V_3 , V_45 ) )
return false ;
V_122 = false ;
V_44 = F_31 ( V_116 [ V_7 -> V_5 ] . V_119 ) ;
if ( F_3 ( ! ( V_44 & V_120 ) ) )
goto V_32;
V_44 = F_31 ( V_113 ) ;
V_20 -> V_114 = ( V_44 >> ( V_7 -> V_5 * 6 ) ) & 0x3f ;
V_122 = true ;
V_32:
F_35 ( V_3 , V_45 ) ;
return V_122 ;
}
static void F_81 ( struct V_123 * V_124 )
{
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_125 = V_126 ;
}
static void F_82 ( struct V_123 * V_124 ,
T_3 V_127 ,
T_3 V_128 ,
unsigned int V_129 )
{
T_3 V_130 ;
V_130 = F_83 ( 10000 * F_59 ( V_128 , V_127 ) ,
V_127 ) ;
if ( V_128 >= V_127 ) {
if ( V_130 < V_131 &&
V_130 < V_124 -> V_125 ) {
V_124 -> V_125 = V_130 ;
V_124 -> V_127 = V_127 ;
V_124 -> V_128 = V_128 ;
V_124 -> V_81 = V_129 ;
}
} else if ( V_130 < V_132 &&
V_130 < V_124 -> V_125 ) {
V_124 -> V_125 = V_130 ;
V_124 -> V_127 = V_127 ;
V_124 -> V_128 = V_128 ;
V_124 -> V_81 = V_129 ;
}
}
static void F_84 ( unsigned int V_81 ,
unsigned int * V_133 ,
unsigned int * V_134 ,
unsigned int * V_135 )
{
if ( V_81 % 2 == 0 ) {
unsigned int V_136 = V_81 / 2 ;
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
} else if ( V_81 == 3 || V_81 == 9 ) {
* V_133 = 3 ;
* V_134 = 1 ;
* V_135 = V_81 / 3 ;
} else if ( V_81 == 5 || V_81 == 7 ) {
* V_133 = V_81 ;
* V_134 = 1 ;
* V_135 = 1 ;
} else if ( V_81 == 15 ) {
* V_133 = 3 ;
* V_134 = 1 ;
* V_135 = 5 ;
} else if ( V_81 == 21 ) {
* V_133 = 7 ;
* V_134 = 1 ;
* V_135 = 3 ;
} else if ( V_81 == 35 ) {
* V_133 = 7 ;
* V_134 = 1 ;
* V_135 = 5 ;
}
}
static void F_85 ( struct V_137 * V_138 ,
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
F_8 ( 1 , L_15 ) ;
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
F_8 ( 1 , L_16 ) ;
}
V_138 -> V_142 = V_134 ;
V_138 -> V_143 = ( V_138 -> V_142 == 1 ) ? 0 : 1 ;
V_128 = V_133 * V_134 * V_135 * V_139 ;
V_138 -> V_144 = F_86 ( V_128 , 24 * F_87 ( 1 ) ) ;
V_138 -> V_145 =
F_86 ( ( F_86 ( V_128 , 24 ) -
V_138 -> V_144 * F_87 ( 1 ) ) * 0x8000 , F_87 ( 1 ) ) ;
}
static bool
F_88 ( int clock ,
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
{ V_148 , F_89 (even_dividers) } ,
{ V_149 , F_89 (odd_dividers) } ,
} ;
struct V_123 V_124 ;
unsigned int V_153 , V_87 , V_40 ;
unsigned int V_133 , V_134 , V_135 ;
F_81 ( & V_124 ) ;
for ( V_87 = 0 ; V_87 < F_89 ( V_152 ) ; V_87 ++ ) {
for ( V_153 = 0 ; V_153 < F_89 ( V_147 ) ; V_153 ++ ) {
for ( V_40 = 0 ; V_40 < V_152 [ V_87 ] . V_151 ; V_40 ++ ) {
unsigned int V_81 = V_152 [ V_87 ] . V_150 [ V_40 ] ;
T_3 V_128 = V_81 * V_139 ;
F_82 ( & V_124 ,
V_147 [ V_153 ] ,
V_128 ,
V_81 ) ;
if ( V_124 . V_125 == 0 )
goto V_154;
}
}
V_154:
if ( V_87 == 0 && V_124 . V_81 )
break;
}
if ( ! V_124 . V_81 ) {
F_13 ( L_17 , clock ) ;
return false ;
}
V_133 = V_134 = V_135 = 0 ;
F_84 ( V_124 . V_81 , & V_133 , & V_134 , & V_135 ) ;
F_85 ( V_146 , V_139 , V_124 . V_127 ,
V_133 , V_134 , V_135 ) ;
return true ;
}
static struct V_1 *
F_90 ( struct V_11 * V_12 , struct V_36 * V_37 ,
struct V_55 * V_56 )
{
struct V_1 * V_7 ;
T_1 V_114 , V_117 , V_118 ;
int clock = V_37 -> V_102 ;
V_114 = F_91 ( 0 ) ;
if ( V_56 -> type == V_103 ) {
struct V_137 V_146 = { 0 , } ;
V_114 |= F_69 ( 0 ) ;
if ( ! F_88 ( clock * 1000 , & V_146 ) )
return NULL ;
V_117 = V_155 |
F_92 ( V_146 . V_145 ) |
V_146 . V_144 ;
V_118 = F_93 ( V_146 . V_142 ) |
F_94 ( V_146 . V_143 ) |
F_95 ( V_146 . V_141 ) |
F_96 ( V_146 . V_140 ) |
V_146 . V_127 ;
} else if ( V_56 -> type == V_105 ||
V_56 -> type == V_106 ||
V_56 -> type == V_107 ) {
switch ( V_37 -> V_102 / 2 ) {
case 81000 :
V_114 |= F_97 ( V_156 , 0 ) ;
break;
case 135000 :
V_114 |= F_97 ( V_157 , 0 ) ;
break;
case 270000 :
V_114 |= F_97 ( V_158 , 0 ) ;
break;
case 162000 :
V_114 |= F_97 ( V_159 , 0 ) ;
break;
case 108000 :
V_114 |= F_97 ( V_160 , 0 ) ;
break;
case 216000 :
V_114 |= F_97 ( V_161 , 0 ) ;
break;
}
V_117 = V_118 = 0 ;
} else {
return NULL ;
}
memset ( & V_37 -> V_41 , 0 ,
sizeof( V_37 -> V_41 ) ) ;
V_37 -> V_41 . V_114 = V_114 ;
V_37 -> V_41 . V_117 = V_117 ;
V_37 -> V_41 . V_118 = V_118 ;
if ( V_56 -> type == V_107 )
V_7 = F_22 ( V_12 , V_37 ,
V_162 ,
V_162 ) ;
else
V_7 = F_22 ( V_12 , V_37 ,
V_163 ,
V_164 ) ;
if ( ! V_7 )
return NULL ;
V_37 -> V_112 = V_7 -> V_5 ;
F_24 ( V_7 , V_37 ) ;
return V_7 ;
}
static void F_98 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
T_1 V_165 ;
enum V_166 V_166 = (enum V_166 ) V_7 -> V_5 ;
V_165 = F_31 ( F_99 ( V_166 ) ) ;
V_165 |= V_167 ;
F_37 ( F_99 ( V_166 ) , V_165 ) ;
V_165 = F_31 ( F_100 ( V_166 ) ) ;
V_165 &= ~ V_168 ;
F_37 ( F_100 ( V_166 ) , V_165 ) ;
V_165 = F_31 ( F_101 ( V_166 ) ) ;
V_165 &= ~ ( V_169 | V_170 ) ;
V_165 |= V_7 -> V_10 . V_20 . V_171 ;
F_37 ( F_101 ( V_166 ) , V_165 ) ;
V_165 = F_31 ( F_102 ( V_166 , 0 ) ) ;
V_165 &= ~ V_172 ;
V_165 |= V_7 -> V_10 . V_20 . V_173 ;
F_37 ( F_102 ( V_166 , 0 ) , V_165 ) ;
V_165 = F_31 ( F_102 ( V_166 , 1 ) ) ;
V_165 &= ~ V_174 ;
V_165 |= V_7 -> V_10 . V_20 . V_175 ;
F_37 ( F_102 ( V_166 , 1 ) , V_165 ) ;
V_165 = F_31 ( F_102 ( V_166 , 2 ) ) ;
V_165 &= ~ V_176 ;
V_165 |= V_7 -> V_10 . V_20 . V_177 ;
F_37 ( F_102 ( V_166 , 2 ) , V_165 ) ;
V_165 = F_31 ( F_102 ( V_166 , 3 ) ) ;
V_165 &= ~ V_178 ;
V_165 |= V_7 -> V_10 . V_20 . V_179 ;
F_37 ( F_102 ( V_166 , 3 ) , V_165 ) ;
V_165 = F_31 ( F_102 ( V_166 , 6 ) ) ;
V_165 &= ~ V_180 ;
V_165 &= ~ V_181 ;
V_165 &= ~ V_182 ;
V_165 |= V_7 -> V_10 . V_20 . V_183 ;
F_37 ( F_102 ( V_166 , 6 ) , V_165 ) ;
V_165 = F_31 ( F_102 ( V_166 , 8 ) ) ;
V_165 &= ~ V_184 ;
V_165 |= V_7 -> V_10 . V_20 . V_185 ;
F_37 ( F_102 ( V_166 , 8 ) , V_165 ) ;
V_165 = F_31 ( F_102 ( V_166 , 9 ) ) ;
V_165 &= ~ V_186 ;
V_165 |= V_7 -> V_10 . V_20 . V_187 ;
F_37 ( F_102 ( V_166 , 9 ) , V_165 ) ;
V_165 = F_31 ( F_102 ( V_166 , 10 ) ) ;
V_165 &= ~ V_188 ;
V_165 &= ~ V_189 ;
V_165 |= V_7 -> V_10 . V_20 . V_190 ;
F_37 ( F_102 ( V_166 , 10 ) , V_165 ) ;
V_165 = F_31 ( F_100 ( V_166 ) ) ;
V_165 |= V_191 ;
F_37 ( F_100 ( V_166 ) , V_165 ) ;
V_165 &= ~ V_168 ;
V_165 |= V_7 -> V_10 . V_20 . V_192 ;
F_37 ( F_100 ( V_166 ) , V_165 ) ;
V_165 = F_31 ( F_99 ( V_166 ) ) ;
V_165 |= V_193 ;
F_37 ( F_99 ( V_166 ) , V_165 ) ;
F_43 ( F_99 ( V_166 ) ) ;
if ( F_103 ( ( F_31 ( F_99 ( V_166 ) ) & V_194 ) ,
200 ) )
F_75 ( L_18 , V_166 ) ;
V_165 = F_31 ( F_104 ( V_166 ) ) ;
V_165 &= ~ V_195 ;
V_165 &= ~ V_196 ;
V_165 |= V_7 -> V_10 . V_20 . V_197 ;
F_37 ( F_105 ( V_166 ) , V_165 ) ;
}
static void F_106 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
enum V_166 V_166 = (enum V_166 ) V_7 -> V_5 ;
T_1 V_165 ;
V_165 = F_31 ( F_99 ( V_166 ) ) ;
V_165 &= ~ V_193 ;
F_37 ( F_99 ( V_166 ) , V_165 ) ;
F_43 ( F_99 ( V_166 ) ) ;
}
static bool F_107 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_19 * V_20 )
{
enum V_166 V_166 = (enum V_166 ) V_7 -> V_5 ;
T_1 V_44 ;
bool V_122 ;
if ( ! F_30 ( V_3 , V_45 ) )
return false ;
V_122 = false ;
V_44 = F_31 ( F_99 ( V_166 ) ) ;
if ( ! ( V_44 & V_193 ) )
goto V_32;
V_20 -> V_171 = F_31 ( F_101 ( V_166 ) ) ;
V_20 -> V_171 &= V_169 | V_170 ;
V_20 -> V_192 = F_31 ( F_100 ( V_166 ) ) ;
V_20 -> V_192 &= V_168 ;
V_20 -> V_173 = F_31 ( F_102 ( V_166 , 0 ) ) ;
V_20 -> V_173 &= V_172 ;
V_20 -> V_175 = F_31 ( F_102 ( V_166 , 1 ) ) ;
V_20 -> V_175 &= V_174 ;
V_20 -> V_177 = F_31 ( F_102 ( V_166 , 2 ) ) ;
V_20 -> V_177 &= V_176 ;
V_20 -> V_179 = F_31 ( F_102 ( V_166 , 3 ) ) ;
V_20 -> V_179 &= V_178 ;
V_20 -> V_183 = F_31 ( F_102 ( V_166 , 6 ) ) ;
V_20 -> V_183 &= V_180 |
V_181 |
V_182 ;
V_20 -> V_185 = F_31 ( F_102 ( V_166 , 8 ) ) ;
V_20 -> V_185 &= V_184 ;
V_20 -> V_187 = F_31 ( F_102 ( V_166 , 9 ) ) ;
V_20 -> V_187 &= V_186 ;
V_20 -> V_190 = F_31 ( F_102 ( V_166 , 10 ) ) ;
V_20 -> V_190 &= V_188 |
V_189 ;
V_20 -> V_197 = F_31 ( F_104 ( V_166 ) ) ;
if ( F_31 ( F_108 ( V_166 ) ) != V_20 -> V_197 )
F_13 ( L_19 ,
V_20 -> V_197 ,
F_31 ( F_108 ( V_166 ) ) ) ;
V_20 -> V_197 &= V_195 | V_196 ;
V_122 = true ;
V_32:
F_35 ( V_3 , V_45 ) ;
return V_122 ;
}
static struct V_1 *
F_109 ( struct V_11 * V_12 , struct V_36 * V_37 ,
struct V_55 * V_56 )
{
struct V_2 * V_3 = F_5 ( V_12 -> V_13 . V_14 ) ;
struct V_1 * V_7 ;
enum V_4 V_40 ;
struct V_198 * V_199 ;
struct V_200 V_201 = { 0 } ;
int V_202 = 0 ;
T_1 V_203 , V_204 , V_205 , V_206 ;
T_1 V_207 ;
int clock = V_37 -> V_102 ;
if ( V_56 -> type == V_103 ) {
T_4 V_208 ;
if ( ! F_110 ( V_37 , clock , & V_208 ) ) {
F_13 ( L_20 ,
clock , F_26 ( V_12 -> V_16 ) ) ;
return NULL ;
}
V_201 . V_134 = V_208 . V_134 ;
V_201 . V_135 = V_208 . V_135 ;
F_3 ( V_208 . V_209 != 2 ) ;
V_201 . V_210 = V_208 . V_210 ;
V_201 . V_211 = V_208 . V_212 >> 22 ;
V_201 . V_213 = V_208 . V_212 & ( ( 1 << 22 ) - 1 ) ;
V_201 . V_214 = V_201 . V_213 != 0 ;
V_202 = V_208 . V_202 ;
} else if ( V_56 -> type == V_105 ||
V_56 -> type == V_107 ) {
int V_40 ;
V_201 = V_215 [ 0 ] ;
for ( V_40 = 0 ; V_40 < F_89 ( V_215 ) ; ++ V_40 ) {
if ( V_215 [ V_40 ] . clock == clock ) {
V_201 = V_215 [ V_40 ] ;
break;
}
}
V_202 = clock * 10 / 2 * V_201 . V_134 * V_201 . V_135 ;
}
if ( V_202 >= 6200000 && V_202 <= 6700000 ) {
V_203 = 4 ;
V_204 = 9 ;
V_205 = 3 ;
V_206 = 8 ;
} else if ( ( V_202 > 5400000 && V_202 < 6200000 ) ||
( V_202 >= 4800000 && V_202 < 5400000 ) ) {
V_203 = 5 ;
V_204 = 11 ;
V_205 = 3 ;
V_206 = 9 ;
} else if ( V_202 == 5400000 ) {
V_203 = 3 ;
V_204 = 8 ;
V_205 = 1 ;
V_206 = 9 ;
} else {
F_75 ( L_21 ) ;
return NULL ;
}
memset ( & V_37 -> V_41 , 0 ,
sizeof( V_37 -> V_41 ) ) ;
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
V_37 -> V_41 . V_171 =
F_111 ( V_201 . V_134 ) | F_112 ( V_201 . V_135 ) ;
V_37 -> V_41 . V_173 = V_201 . V_211 ;
V_37 -> V_41 . V_175 = F_113 ( V_201 . V_210 ) ;
V_37 -> V_41 . V_177 = V_201 . V_213 ;
if ( V_201 . V_214 )
V_37 -> V_41 . V_179 =
V_178 ;
V_37 -> V_41 . V_183 =
V_203 | F_114 ( V_204 ) ;
V_37 -> V_41 . V_183 |=
F_115 ( V_205 ) ;
V_37 -> V_41 . V_185 = V_206 ;
V_37 -> V_41 . V_187 = 5 << V_216 ;
V_37 -> V_41 . V_190 =
F_116 ( V_217 )
| V_188 ;
V_37 -> V_41 . V_192 = V_168 ;
V_37 -> V_41 . V_197 =
V_196 | V_207 ;
V_199 = F_117 ( & V_56 -> V_13 ) ;
V_40 = (enum V_4 ) V_199 -> V_166 ;
V_7 = F_1 ( V_3 , V_40 ) ;
F_18 ( L_12 ,
V_12 -> V_13 . V_13 . V_5 , V_7 -> V_23 ) ;
F_24 ( V_7 , V_37 ) ;
V_37 -> V_112 = V_7 -> V_5 ;
return V_7 ;
}
static void F_118 ( struct V_24 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_25 ;
T_1 V_44 = F_31 ( V_218 ) ;
if ( F_119 ( V_14 ) || F_120 ( V_14 ) ) {
int V_219 ;
V_219 = V_3 -> V_220 . V_221 ( V_14 ) ;
V_3 -> V_222 = V_219 ;
if ( F_121 ( V_3 ) )
F_18 ( L_22 ) ;
if ( ! ( F_31 ( V_223 ) & V_120 ) )
F_75 ( L_23 ) ;
} else if ( ! F_122 ( V_3 ) ) {
if ( V_44 & V_224 )
F_75 ( L_24 ) ;
if ( V_44 & V_225 )
F_75 ( L_25 ) ;
}
}
void F_123 ( struct V_24 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_25 ;
const struct V_226 * V_227 = NULL ;
const struct V_228 * V_228 ;
int V_40 ;
if ( F_119 ( V_14 ) || F_120 ( V_14 ) )
V_227 = & V_229 ;
else if ( F_122 ( V_14 ) )
V_227 = & V_230 ;
else if ( F_124 ( V_14 ) )
V_227 = & V_231 ;
else if ( F_40 ( V_14 ) || F_41 ( V_14 ) )
V_227 = & V_232 ;
if ( ! V_227 ) {
V_3 -> V_8 = 0 ;
return;
}
V_228 = V_227 -> V_228 ;
for ( V_40 = 0 ; V_228 [ V_40 ] . V_5 >= 0 ; V_40 ++ ) {
F_3 ( V_40 != V_228 [ V_40 ] . V_5 ) ;
V_3 -> V_6 [ V_40 ] . V_5 = V_228 [ V_40 ] . V_5 ;
V_3 -> V_6 [ V_40 ] . V_23 = V_228 [ V_40 ] . V_23 ;
V_3 -> V_6 [ V_40 ] . V_21 = * V_228 [ V_40 ] . V_21 ;
V_3 -> V_6 [ V_40 ] . V_233 = V_228 [ V_40 ] . V_233 ;
}
V_3 -> V_227 = V_227 ;
V_3 -> V_8 = V_40 ;
F_125 ( & V_3 -> V_27 ) ;
F_126 ( V_3 -> V_8 > V_234 ) ;
if ( F_124 ( V_14 ) )
F_118 ( V_14 ) ;
}
struct V_1 *
F_127 ( struct V_11 * V_12 ,
struct V_36 * V_37 ,
struct V_55 * V_56 )
{
struct V_2 * V_3 = F_5 ( V_12 -> V_13 . V_14 ) ;
const struct V_226 * V_227 = V_3 -> V_227 ;
if ( F_3 ( ! V_227 ) )
return NULL ;
return V_227 -> V_235 ( V_12 , V_37 , V_56 ) ;
}
