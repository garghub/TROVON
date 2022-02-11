static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , unsigned V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
void T_1 * V_10 = V_2 -> V_11 ;
const unsigned V_12 = V_7 -> V_13 >> 3 ;
const unsigned V_14 = V_9 -> V_15 / V_12 ;
int V_16 = ( V_5 >> 16 ) & 0xff ;
int V_17 = ( V_5 >> 8 ) & 0xff ;
int V_18 = ( V_5 >> 0 ) & 0xff ;
if ( V_7 -> V_13 == 16 ) {
T_2 T_1 * V_19 = ( T_2 T_1 * ) V_10 ;
V_19 += V_4 * V_14 + V_3 ;
V_16 = V_16 * 32 / 256 ;
V_17 = V_17 * 64 / 256 ;
V_18 = V_18 * 32 / 256 ;
F_2 ( ( V_16 << 11 ) | ( V_17 << 5 ) | ( V_18 << 0 ) , V_19 ) ;
} else if ( V_7 -> V_13 == 24 ) {
T_3 T_1 * V_19 = ( T_3 T_1 * ) V_10 ;
V_19 += ( V_4 * V_14 + V_3 ) * 3 ;
F_3 ( V_18 , V_19 + 0 ) ;
F_3 ( V_17 , V_19 + 1 ) ;
F_3 ( V_16 , V_19 + 2 ) ;
} else if ( V_7 -> V_13 == 32 ) {
T_4 T_1 * V_19 = ( T_4 T_1 * ) V_10 ;
V_19 += V_4 * V_14 + V_3 ;
F_4 ( V_5 , V_19 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
const short V_20 = V_7 -> V_21 ;
const short V_22 = V_7 -> V_23 ;
void T_1 * V_10 = V_2 -> V_11 ;
int V_4 , V_3 ;
if ( ! V_10 )
return;
F_6 ( L_1 , V_20 , V_22 , V_2 -> V_9 . V_15 ) ;
for ( V_4 = 0 ; V_4 < V_22 ; V_4 ++ ) {
for ( V_3 = 0 ; V_3 < V_20 ; V_3 ++ ) {
if ( V_3 < 20 && V_4 < 20 )
F_1 ( V_2 , V_3 , V_4 , 0xffffff ) ;
else if ( V_3 < 20 && ( V_4 > 20 && V_4 < V_22 - 20 ) )
F_1 ( V_2 , V_3 , V_4 , 0xff ) ;
else if ( V_4 < 20 && ( V_3 > 20 && V_3 < V_20 - 20 ) )
F_1 ( V_2 , V_3 , V_4 , 0xff00 ) ;
else if ( V_3 > V_20 - 20 && ( V_4 > 20 && V_4 < V_22 - 20 ) )
F_1 ( V_2 , V_3 , V_4 , 0xff0000 ) ;
else if ( V_4 > V_22 - 20 && ( V_3 > 20 && V_3 < V_20 - 20 ) )
F_1 ( V_2 , V_3 , V_4 , 0xffff00 ) ;
else if ( V_3 == 20 || V_3 == V_20 - 20 ||
V_4 == 20 || V_4 == V_22 - 20 )
F_1 ( V_2 , V_3 , V_4 , 0xffffff ) ;
else if ( V_3 == V_4 || V_20 - V_3 == V_22 - V_4 )
F_1 ( V_2 , V_3 , V_4 , 0xff00ff ) ;
else if ( V_20 - V_3 == V_4 || V_3 == V_22 - V_4 )
F_1 ( V_2 , V_3 , V_4 , 0x00ffff ) ;
else if ( V_3 > 20 && V_4 > 20 && V_3 < V_20 - 20 && V_4 < V_22 - 20 ) {
int V_24 = V_3 * 3 / V_20 ;
unsigned V_16 = 0 , V_17 = 0 , V_18 = 0 ;
unsigned V_25 ;
if ( V_7 -> V_13 == 16 ) {
if ( V_24 == 0 )
V_18 = ( V_4 % 32 ) * 256 / 32 ;
else if ( V_24 == 1 )
V_17 = ( V_4 % 64 ) * 256 / 64 ;
else if ( V_24 == 2 )
V_16 = ( V_4 % 32 ) * 256 / 32 ;
} else {
if ( V_24 == 0 )
V_18 = ( V_4 % 256 ) ;
else if ( V_24 == 1 )
V_17 = ( V_4 % 256 ) ;
else if ( V_24 == 2 )
V_16 = ( V_4 % 256 ) ;
}
V_25 = ( V_16 << 16 ) | ( V_17 << 8 ) | ( V_18 << 0 ) ;
F_1 ( V_2 , V_3 , V_4 , V_25 ) ;
} else {
F_1 ( V_2 , V_3 , V_4 , 0 ) ;
}
}
}
}
static unsigned F_7 ( const struct V_26 * V_27 , int V_28 )
{
const struct V_29 * V_29 = & V_27 -> V_30 -> V_29 ;
unsigned V_31 ;
switch ( V_28 ) {
case V_32 :
V_31 = 0 ;
break;
case V_33 :
V_31 = V_29 -> V_34 ;
break;
case V_35 :
V_31 = V_29 -> V_34 * V_36 + V_29 -> V_37 ;
break;
case V_38 :
V_31 = V_29 -> V_37 * V_36 ;
break;
default:
F_8 () ;
return 0 ;
}
V_31 *= V_29 -> V_12 ;
return V_31 ;
}
static T_4 F_9 ( const struct V_26 * V_27 , int V_28 )
{
if ( V_27 -> V_39 == V_40 ) {
return V_27 -> V_30 -> V_29 . V_41 [ V_28 ]
+ F_7 ( V_27 , V_28 ) ;
} else {
return V_27 -> V_30 -> V_41 ;
}
}
static T_4 F_10 ( const struct V_26 * V_27 )
{
if ( V_27 -> V_39 == V_40 )
return V_27 -> V_30 -> V_29 . V_41 [ 0 ] ;
else
return V_27 -> V_30 -> V_41 ;
}
static void T_1 * F_11 ( const struct V_26 * V_27 )
{
if ( V_27 -> V_39 == V_40 )
return V_27 -> V_30 -> V_29 . V_42 [ 0 ] ;
else
return V_27 -> V_30 -> V_42 ;
}
bool F_12 ( struct V_43 * V_44 , struct V_43 * V_45 )
{
return V_44 -> V_46 == V_45 -> V_46 &&
V_44 -> V_31 == V_45 -> V_31 &&
V_44 -> V_47 == V_45 -> V_47 ;
}
static void F_13 ( struct V_6 * V_7 ,
struct V_48 * V_5 )
{
V_7 -> V_13 = V_5 -> V_13 ;
V_7 -> V_49 = V_5 -> V_49 ;
V_7 -> V_50 = V_5 -> V_50 ;
V_7 -> V_51 = V_5 -> V_51 ;
V_7 -> V_52 = V_5 -> V_52 ;
V_7 -> V_53 = V_5 -> V_53 ;
}
static int F_14 ( struct V_6 * V_7 ,
enum V_54 * V_55 )
{
enum V_54 V_56 ;
int V_57 ;
if ( V_7 -> V_49 ) {
for ( V_57 = 0 ; V_57 < F_15 ( V_58 ) ; ++ V_57 ) {
struct V_48 * V_59 = & V_58 [ V_57 ] ;
if ( V_7 -> V_49 == V_59 -> V_49 ) {
F_13 ( V_7 , V_59 ) ;
* V_55 = V_59 -> V_56 ;
return 0 ;
}
}
return - V_60 ;
}
for ( V_57 = 0 ; V_57 < F_15 ( V_58 ) ; ++ V_57 ) {
struct V_48 * V_59 = & V_58 [ V_57 ] ;
if ( F_16 ( V_7 , V_59 ) ) {
F_13 ( V_7 , V_59 ) ;
* V_55 = V_59 -> V_56 ;
return 0 ;
}
}
switch ( V_7 -> V_13 ) {
case 1 :
V_56 = V_61 ;
break;
case 2 :
V_56 = V_62 ;
break;
case 4 :
V_56 = V_63 ;
break;
case 8 :
V_56 = V_64 ;
break;
case 12 :
V_56 = V_65 ;
break;
case 16 :
V_56 = V_66 ;
break;
case 24 :
V_56 = V_67 ;
break;
case 32 :
V_56 = V_68 ;
break;
default:
return - V_60 ;
}
for ( V_57 = 0 ; V_57 < F_15 ( V_58 ) ; ++ V_57 ) {
struct V_48 * V_59 = & V_58 [ V_57 ] ;
if ( V_56 == V_59 -> V_56 ) {
F_13 ( V_7 , V_59 ) ;
* V_55 = V_59 -> V_56 ;
return 0 ;
}
}
return - V_60 ;
}
static int F_17 ( struct V_6 * V_7 )
{
int V_69 = V_70 ;
int V_71 = 2048 ;
int V_72 = V_73 ;
int V_74 = 2048 ;
if ( V_7 -> V_21 == 0 )
V_7 -> V_21 = V_7 -> V_75 ;
if ( V_7 -> V_23 == 0 )
V_7 -> V_23 = V_7 -> V_76 ;
if ( V_7 -> V_21 < V_69 || V_7 -> V_23 < V_72 )
return - V_60 ;
if ( V_7 -> V_75 < V_69 )
V_7 -> V_75 = V_69 ;
if ( V_7 -> V_76 < V_72 )
V_7 -> V_76 = V_72 ;
if ( V_7 -> V_75 > V_71 )
V_7 -> V_75 = V_71 ;
if ( V_7 -> V_76 > V_74 )
V_7 -> V_76 = V_74 ;
if ( V_7 -> V_75 > V_7 -> V_21 )
V_7 -> V_75 = V_7 -> V_21 ;
if ( V_7 -> V_76 > V_7 -> V_23 )
V_7 -> V_76 = V_7 -> V_23 ;
return 0 ;
}
static void F_18 ( unsigned long V_77 ,
struct V_6 * V_7 )
{
F_6 ( L_2 ) ;
V_7 -> V_23 = V_77 /
( V_7 -> V_21 * V_7 -> V_13 >> 3 ) ;
if ( V_7 -> V_23 < V_73 )
V_7 -> V_23 = V_73 ;
if ( V_7 -> V_76 > V_7 -> V_23 )
V_7 -> V_76 = V_7 -> V_23 ;
}
static void F_19 ( unsigned long V_77 ,
struct V_6 * V_7 )
{
F_6 ( L_3 ) ;
V_7 -> V_21 = V_77 / V_7 -> V_23 /
( V_7 -> V_13 >> 3 ) ;
if ( V_7 -> V_21 < V_70 )
V_7 -> V_21 = V_70 ;
if ( V_7 -> V_75 > V_7 -> V_21 )
V_7 -> V_75 = V_7 -> V_21 ;
}
static int F_20 ( unsigned long V_78 ,
const struct V_6 * V_7 )
{
unsigned long V_79 = F_21 ( V_7 -> V_21 ,
V_7 -> V_23 , V_7 -> V_13 >> 3 ) ;
return V_79 > V_78 ? - V_60 : 0 ;
}
static int F_22 ( const struct V_26 * V_27 ,
struct V_6 * V_7 )
{
unsigned long V_77 = V_27 -> V_30 -> V_80 ;
int V_12 = V_7 -> V_13 >> 3 ;
unsigned long V_81 = V_7 -> V_21 * V_12 ;
if ( V_27 -> V_39 == V_40 ) {
if ( F_20 ( V_77 , V_7 ) )
F_18 ( F_23 (
V_77 , V_7 -> V_21 , V_12 ) *
V_81 , V_7 ) ;
if ( F_20 ( V_77 , V_7 ) ) {
F_6 ( L_4 ) ;
return - V_60 ;
}
return 0 ;
}
F_6 ( L_5 , V_77 , V_81 ) ;
if ( V_81 * V_7 -> V_23 > V_77 )
F_18 ( V_77 , V_7 ) ;
if ( V_81 * V_7 -> V_23 > V_77 ) {
F_19 ( V_77 , V_7 ) ;
V_81 = V_7 -> V_21 * V_12 ;
}
if ( V_81 * V_7 -> V_23 > V_77 ) {
F_6 ( L_4 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_25 ( V_2 ) ;
struct V_82 * V_83 = V_27 -> V_30 ;
struct V_29 * V_29 = & V_83 -> V_29 ;
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
unsigned V_12 ;
bool V_84 ;
enum V_54 V_55 ;
int V_16 ;
bool V_85 ;
if ( ! V_83 -> V_80 || V_27 -> V_39 != V_40 )
return 0 ;
F_6 ( L_6 ) ;
V_16 = F_14 ( V_7 , & V_55 ) ;
if ( V_16 )
return V_16 ;
V_12 = V_7 -> V_13 >> 3 ;
V_84 = V_55 == V_86 || V_55 == V_87 ;
V_85 = false ;
if ( V_84 != V_29 -> V_84 )
V_85 = true ;
else if ( V_12 != V_29 -> V_12 )
V_85 = true ;
else if ( V_29 -> V_75 != V_7 -> V_21 ||
V_29 -> V_76 != V_7 -> V_23 )
V_85 = true ;
if ( V_29 -> V_42 [ 0 ] && V_85 ) {
V_2 -> V_11 = NULL ;
V_9 -> V_88 = 0 ;
V_9 -> V_89 = 0 ;
F_26 ( V_29 -> V_42 [ 0 ] ) ;
V_29 -> V_42 [ 0 ] = NULL ;
F_6 ( L_7 ) ;
}
if ( V_29 -> V_42 [ 0 ] )
return 0 ;
F_27 ( & V_83 -> V_29 , V_83 -> V_41 ,
V_7 -> V_21 ,
V_7 -> V_23 ,
V_12 , V_84 ) ;
V_16 = F_28 ( V_29 , V_7 -> V_23 , 0 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_11 = V_27 -> V_30 -> V_29 . V_42 [ 0 ] ;
V_9 -> V_88 = V_27 -> V_30 -> V_29 . V_41 [ 0 ] ;
switch ( V_7 -> V_49 ) {
case V_90 :
case V_91 :
V_9 -> V_15 =
( V_36 * V_7 -> V_13 ) >> 2 ;
break;
default:
V_9 -> V_15 =
( V_36 * V_7 -> V_13 ) >> 3 ;
break;
}
V_9 -> V_89 = V_7 -> V_23 * V_9 -> V_15 ;
return 0 ;
}
int F_29 ( enum V_54 V_56 ,
struct V_6 * V_7 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < F_15 ( V_58 ) ; ++ V_57 ) {
struct V_48 * V_55 = & V_58 [ V_57 ] ;
if ( V_56 == V_55 -> V_56 ) {
F_13 ( V_7 , V_55 ) ;
return 0 ;
}
}
return - V_92 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_26 * V_27 = F_25 ( V_2 ) ;
struct V_82 * V_83 = V_27 -> V_30 ;
F_6 ( L_8 ) ;
V_2 -> V_11 = ( char T_1 * ) F_11 ( V_27 ) ;
if ( V_27 -> V_39 == V_40 ) {
switch ( V_7 -> V_49 ) {
case V_90 :
case V_91 :
V_9 -> V_15 =
( V_36 * V_7 -> V_13 ) >> 2 ;
break;
default:
V_9 -> V_15 =
( V_36 * V_7 -> V_13 ) >> 3 ;
break;
}
V_9 -> V_89 = V_7 -> V_23 * V_9 -> V_15 ;
} else {
V_9 -> V_15 =
( V_7 -> V_21 * V_7 -> V_13 ) >> 3 ;
V_9 -> V_89 = V_83 -> V_80 ;
}
V_9 -> V_88 = F_10 ( V_27 ) ;
V_9 -> type = V_93 ;
if ( V_7 -> V_49 )
V_9 -> V_94 = V_95 ;
else {
switch ( V_7 -> V_13 ) {
case 32 :
case 24 :
case 16 :
case 12 :
V_9 -> V_94 = V_96 ;
break;
case 1 :
case 2 :
case 4 :
case 8 :
V_9 -> V_94 = V_95 ;
break;
}
}
V_9 -> V_97 = V_98 ;
V_9 -> V_99 = 1 ;
V_9 -> V_100 = 1 ;
}
int F_31 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_26 * V_27 = F_25 ( V_2 ) ;
struct V_101 * V_102 = F_32 ( V_2 ) ;
enum V_54 V_55 = 0 ;
int V_57 ;
int V_16 ;
F_6 ( L_9 , V_27 -> V_103 ) ;
F_33 ( ! F_34 ( & V_27 -> V_30 -> V_104 ) ) ;
V_16 = F_14 ( V_7 , & V_55 ) ;
if ( V_16 ) {
F_6 ( L_10 ) ;
return V_16 ;
}
for ( V_57 = 0 ; V_57 < V_27 -> V_105 ; ++ V_57 ) {
if ( ( V_27 -> V_106 [ V_57 ] -> V_107 & V_55 ) == 0 ) {
F_6 ( L_11 ) ;
return - V_60 ;
}
}
if ( V_7 -> V_108 > 3 )
return - V_60 ;
if ( F_17 ( V_7 ) )
return - V_60 ;
if ( V_27 -> V_30 -> V_80 != 0 && F_22 ( V_27 , V_7 ) )
return - V_60 ;
if ( V_7 -> V_75 + V_7 -> V_37 > V_7 -> V_21 )
V_7 -> V_37 = V_7 -> V_21 - V_7 -> V_75 ;
if ( V_7 -> V_76 + V_7 -> V_34 > V_7 -> V_23 )
V_7 -> V_34 = V_7 -> V_23 - V_7 -> V_76 ;
F_6 ( L_12 ,
V_7 -> V_75 , V_7 -> V_76 ,
V_7 -> V_21 , V_7 -> V_23 ) ;
if ( V_102 && V_102 -> V_109 -> V_110 ) {
T_4 V_20 , V_22 ;
V_102 -> V_109 -> V_110 ( V_102 , & V_20 , & V_22 ) ;
V_7 -> V_111 = F_35 ( V_20 , 1000 ) ;
V_7 -> V_112 = F_35 ( V_22 , 1000 ) ;
} else {
V_7 -> V_112 = - 1 ;
V_7 -> V_111 = - 1 ;
}
V_7 -> V_113 = 0 ;
if ( V_102 && V_102 -> V_109 -> V_114 ) {
struct V_115 V_116 ;
V_102 -> V_109 -> V_114 ( V_102 , & V_116 ) ;
V_7 -> V_117 = V_116 . V_118 != 0 ?
F_36 ( V_116 . V_118 ) :
0 ;
V_7 -> V_119 = V_116 . V_120 ;
V_7 -> V_121 = V_116 . V_122 ;
V_7 -> V_123 = V_116 . V_124 ;
V_7 -> V_125 = V_116 . V_126 ;
V_7 -> V_127 = V_116 . V_128 ;
V_7 -> V_129 = V_116 . V_130 ;
V_7 -> V_131 |= V_116 . V_132 == V_133 ?
V_134 : 0 ;
V_7 -> V_131 |= V_116 . V_135 == V_133 ?
V_136 : 0 ;
V_7 -> V_137 = V_116 . V_138 ?
V_139 : V_140 ;
} else {
V_7 -> V_117 = 0 ;
V_7 -> V_119 = 0 ;
V_7 -> V_121 = 0 ;
V_7 -> V_123 = 0 ;
V_7 -> V_125 = 0 ;
V_7 -> V_127 = 0 ;
V_7 -> V_129 = 0 ;
V_7 -> V_131 = 0 ;
V_7 -> V_137 = V_140 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , int V_141 )
{
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_141 )
{
return 0 ;
}
static unsigned F_39 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 , int V_142 )
{
unsigned V_31 ;
V_31 = V_7 -> V_34 * V_9 -> V_15 +
V_7 -> V_37 * ( V_7 -> V_13 >> 3 ) ;
return V_31 ;
}
static unsigned F_40 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 , int V_142 )
{
unsigned V_31 ;
if ( V_142 == V_35 )
V_31 = ( V_7 -> V_23 - V_7 -> V_76 ) *
V_9 -> V_15 ;
else if ( V_142 == V_33 )
V_31 = ( V_7 -> V_23 - V_7 -> V_76 ) *
( V_7 -> V_13 >> 3 ) ;
else
V_31 = 0 ;
if ( V_142 == V_32 )
V_31 += V_7 -> V_34 * V_9 -> V_15 +
V_7 -> V_37 * ( V_7 -> V_13 >> 3 ) ;
else if ( V_142 == V_35 )
V_31 -= V_7 -> V_34 * V_9 -> V_15 +
V_7 -> V_37 * ( V_7 -> V_13 >> 3 ) ;
else if ( V_142 == V_33 )
V_31 -= V_7 -> V_37 * V_9 -> V_15 +
V_7 -> V_34 * ( V_7 -> V_13 >> 3 ) ;
else if ( V_142 == V_38 )
V_31 += V_7 -> V_37 * V_9 -> V_15 +
V_7 -> V_34 * ( V_7 -> V_13 >> 3 ) ;
return V_31 ;
}
static void F_41 ( const struct V_26 * V_27 ,
const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
int V_142 , T_4 * V_41 )
{
T_4 V_143 ;
int V_31 ;
if ( V_27 -> V_39 == V_40 )
V_143 = F_9 ( V_27 , V_142 ) ;
else
V_143 = F_10 ( V_27 ) ;
if ( V_27 -> V_39 == V_40 )
V_31 = F_40 ( V_7 , V_9 , V_142 ) ;
else
V_31 = F_39 ( V_7 , V_9 , V_142 ) ;
V_143 += V_31 ;
if ( V_31 )
F_6 ( L_13 ,
V_7 -> V_37 , V_7 -> V_34 , V_31 ) ;
F_6 ( L_14 , V_143 ) ;
* V_41 = V_143 ;
}
int F_42 ( struct V_1 * V_2 , struct V_144 * V_145 ,
T_2 V_146 , T_2 V_147 , T_2 V_148 , T_2 V_149 )
{
int V_16 = 0 ;
struct V_26 * V_27 = F_25 ( V_2 ) ;
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
enum V_54 V_55 = 0 ;
T_4 V_143 = 0 ;
struct V_150 V_151 ;
int V_75 , V_76 ;
int V_152 ;
int V_153 ;
int V_142 = V_7 -> V_108 ;
int V_57 ;
F_33 ( ! F_34 ( & V_27 -> V_30 -> V_104 ) ) ;
for ( V_57 = 0 ; V_57 < V_27 -> V_105 ; V_57 ++ ) {
if ( V_145 != V_27 -> V_106 [ V_57 ] )
continue;
V_142 = ( V_142 + V_27 -> V_142 [ V_57 ] ) % 4 ;
break;
}
F_6 ( L_15 , V_27 -> V_103 ,
V_146 , V_147 , V_148 , V_149 ) ;
if ( V_142 == V_33 || V_142 == V_38 ) {
V_75 = V_7 -> V_76 ;
V_76 = V_7 -> V_75 ;
} else {
V_75 = V_7 -> V_75 ;
V_76 = V_7 -> V_76 ;
}
if ( V_27 -> V_30 -> V_80 )
F_41 ( V_27 , V_7 , V_9 , V_142 , & V_143 ) ;
V_16 = F_14 ( V_7 , & V_55 ) ;
if ( V_16 ) {
F_6 ( L_16 ) ;
goto V_154;
}
switch ( V_7 -> V_49 ) {
case V_90 :
case V_91 :
if ( V_27 -> V_39 == V_40 ) {
V_152 = V_9 -> V_15
/ ( V_7 -> V_13 >> 2 ) ;
break;
}
default:
V_152 = V_9 -> V_15 / ( V_7 -> V_13 >> 3 ) ;
break;
}
V_145 -> V_155 ( V_145 , & V_151 ) ;
if ( V_27 -> V_39 == V_40 )
V_153 = 0 ;
else
V_153 = V_27 -> V_153 ;
V_151 . V_41 = V_143 ;
V_151 . V_152 = V_152 ;
V_151 . V_111 = V_75 ;
V_151 . V_112 = V_76 ;
V_151 . V_156 = V_55 ;
V_151 . V_39 = V_27 -> V_39 ;
V_151 . V_142 = V_142 ;
V_151 . V_153 = V_153 ;
V_151 . V_157 = V_146 ;
V_151 . V_158 = V_147 ;
V_151 . V_159 = V_148 ;
V_151 . V_160 = V_149 ;
V_16 = V_145 -> V_161 ( V_145 , & V_151 ) ;
if ( V_16 ) {
F_6 ( L_17 ) ;
goto V_154;
}
return 0 ;
V_154:
F_6 ( L_18 ) ;
return V_16 ;
}
int F_43 ( struct V_1 * V_2 , int V_162 )
{
int V_16 = 0 ;
struct V_26 * V_27 = F_25 ( V_2 ) ;
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_144 * V_145 ;
T_2 V_146 , V_147 ;
T_2 V_148 , V_149 ;
int V_57 ;
#ifdef F_44
if ( V_163 )
F_5 ( V_2 ) ;
#endif
F_33 ( ! F_34 ( & V_27 -> V_30 -> V_104 ) ) ;
for ( V_57 = 0 ; V_57 < V_27 -> V_105 ; V_57 ++ ) {
V_145 = V_27 -> V_106 [ V_57 ] ;
F_6 ( L_19 , V_27 -> V_103 , V_145 -> V_103 ) ;
if ( V_27 -> V_30 -> V_80 == 0 ) {
F_45 ( V_145 , 0 ) ;
if ( ! V_162 && V_145 -> V_164 )
V_145 -> V_164 -> V_165 ( V_145 -> V_164 ) ;
continue;
}
if ( V_162 || ( V_145 -> V_166 & V_167 ) == 0 ) {
int V_142 = ( V_7 -> V_108 + V_27 -> V_142 [ V_57 ] ) % 4 ;
if ( V_142 == V_33 ||
V_142 == V_38 ) {
V_148 = V_7 -> V_76 ;
V_149 = V_7 -> V_75 ;
} else {
V_148 = V_7 -> V_75 ;
V_149 = V_7 -> V_76 ;
}
} else {
struct V_150 V_151 ;
V_145 -> V_155 ( V_145 , & V_151 ) ;
V_148 = V_151 . V_159 ;
V_149 = V_151 . V_160 ;
}
if ( V_162 ) {
V_146 = 0 ;
V_147 = 0 ;
} else {
struct V_150 V_151 ;
V_145 -> V_155 ( V_145 , & V_151 ) ;
V_146 = V_151 . V_157 ;
V_147 = V_151 . V_158 ;
}
V_16 = F_42 ( V_2 , V_145 , V_146 , V_147 , V_148 , V_149 ) ;
if ( V_16 )
goto V_154;
if ( ! V_162 && V_145 -> V_164 )
V_145 -> V_164 -> V_165 ( V_145 -> V_164 ) ;
}
return 0 ;
V_154:
F_6 ( L_20 ) ;
return V_16 ;
}
static int F_46 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_26 * V_27 = F_25 ( V_2 ) ;
int V_16 ;
F_6 ( L_21 , F_25 ( V_2 ) -> V_103 ) ;
F_47 ( V_27 -> V_30 ) ;
V_16 = F_31 ( V_2 , V_7 ) ;
F_48 ( V_27 -> V_30 ) ;
return V_16 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_25 ( V_2 ) ;
int V_16 ;
F_6 ( L_22 , F_25 ( V_2 ) -> V_103 ) ;
F_47 ( V_27 -> V_30 ) ;
F_30 ( V_2 ) ;
V_16 = F_24 ( V_2 ) ;
if ( V_16 )
goto V_168;
V_16 = F_43 ( V_2 , 0 ) ;
V_168:
F_48 ( V_27 -> V_30 ) ;
return V_16 ;
}
static int F_50 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_26 * V_27 = F_25 ( V_2 ) ;
struct V_6 V_169 ;
int V_16 ;
F_6 ( L_23 , F_25 ( V_2 ) -> V_103 ) ;
if ( V_7 -> V_37 == V_2 -> V_7 . V_37 &&
V_7 -> V_34 == V_2 -> V_7 . V_34 )
return 0 ;
V_169 = V_2 -> V_7 ;
V_169 . V_37 = V_7 -> V_37 ;
V_169 . V_34 = V_7 -> V_34 ;
V_2 -> V_7 = V_169 ;
F_47 ( V_27 -> V_30 ) ;
V_16 = F_43 ( V_2 , 0 ) ;
F_48 ( V_27 -> V_30 ) ;
return V_16 ;
}
static void F_51 ( struct V_170 * V_171 )
{
struct V_82 * V_83 = V_171 -> V_172 ;
F_47 ( V_83 ) ;
F_52 ( & V_83 -> V_173 ) ;
F_48 ( V_83 ) ;
}
static void F_53 ( struct V_170 * V_171 )
{
struct V_82 * V_83 = V_171 -> V_172 ;
F_47 ( V_83 ) ;
F_54 ( & V_83 -> V_173 ) ;
F_48 ( V_83 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_170 * V_171 )
{
struct V_26 * V_27 = F_25 ( V_2 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_82 * V_83 ;
unsigned long V_174 ;
unsigned long V_175 ;
T_4 V_176 ;
int V_16 = - V_60 ;
if ( V_171 -> V_177 - V_171 -> V_178 == 0 )
return 0 ;
if ( V_171 -> V_179 > ( ~ 0UL >> V_180 ) )
return - V_60 ;
V_174 = V_171 -> V_179 << V_180 ;
V_83 = F_47 ( V_27 -> V_30 ) ;
V_175 = F_10 ( V_27 ) ;
V_176 = V_9 -> V_89 ;
if ( V_174 >= V_176 )
goto error;
if ( ( V_171 -> V_177 - V_171 -> V_178 + V_174 ) > V_176 )
goto error;
V_174 += V_175 ;
F_6 ( L_24 , V_175 , V_176 , V_174 ) ;
V_171 -> V_179 = V_174 >> V_180 ;
V_171 -> V_181 |= V_182 | V_183 ;
V_171 -> V_184 = F_56 ( V_171 -> V_184 ) ;
V_171 -> V_185 = & V_186 ;
V_171 -> V_172 = V_83 ;
if ( F_57 ( V_171 , V_171 -> V_178 , V_174 >> V_180 ,
V_171 -> V_177 - V_171 -> V_178 ,
V_171 -> V_184 ) ) {
V_16 = - V_187 ;
goto error;
}
F_52 ( & V_83 -> V_173 ) ;
F_48 ( V_83 ) ;
return 0 ;
error:
F_48 ( V_27 -> V_30 ) ;
return V_16 ;
}
static int F_58 ( struct V_1 * V_2 , T_5 V_188 , T_5 V_50 , T_5 V_51 ,
T_5 V_52 , T_5 V_53 , int V_189 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
int V_16 = 0 ;
enum V_190 V_55 = V_191 ;
switch ( V_55 ) {
case V_90 :
case V_192 :
case V_91 :
V_16 = - V_60 ;
break;
case V_193 :
case V_194 :
case V_195 :
case V_196 :
V_16 = - V_60 ;
break;
case V_197 :
case V_198 :
case V_199 :
case V_191 :
if ( V_16 != 0 )
break;
if ( V_188 < 16 ) {
T_4 V_200 ;
V_200 = ( ( V_50 >> ( 16 - V_7 -> V_50 . V_46 ) ) <<
V_7 -> V_50 . V_31 ) |
( ( V_51 >> ( 16 - V_7 -> V_51 . V_46 ) ) <<
V_7 -> V_51 . V_31 ) |
( V_52 >> ( 16 - V_7 -> V_52 . V_46 ) ) ;
( ( T_4 * ) ( V_2 -> V_201 ) ) [ V_188 ] = V_200 ;
}
break;
default:
F_8 () ;
}
return V_16 ;
}
static int F_59 ( T_5 V_188 , T_5 V_50 , T_5 V_51 , T_5 V_52 ,
T_5 V_53 , struct V_1 * V_151 )
{
F_6 ( L_25 ) ;
return F_58 ( V_151 , V_188 , V_50 , V_51 , V_52 , V_53 , 1 ) ;
}
static int F_60 ( struct V_202 * V_203 , struct V_1 * V_151 )
{
int V_204 , V_205 , V_16 ;
T_2 * V_50 , * V_51 , * V_52 , * V_53 ;
T_2 V_206 = 0xffff ;
F_6 ( L_26 ) ;
V_50 = V_203 -> V_50 ;
V_51 = V_203 -> V_51 ;
V_52 = V_203 -> V_52 ;
V_53 = V_203 -> V_53 ;
V_205 = V_203 -> V_175 ;
for ( V_204 = 0 ; V_204 < V_203 -> V_176 ; V_204 ++ ) {
if ( V_53 )
V_206 = * V_53 ++ ;
V_16 = F_58 ( V_151 , V_205 ++ , * V_50 ++ , * V_51 ++ , * V_52 ++ , V_206 ,
V_204 == V_203 -> V_176 - 1 ) ;
if ( V_16 != 0 )
return V_16 ;
}
return 0 ;
}
static int F_61 ( int V_207 , struct V_1 * V_2 )
{
struct V_26 * V_27 = F_25 ( V_2 ) ;
struct V_208 * V_209 = V_27 -> V_209 ;
struct V_101 * V_102 = F_32 ( V_2 ) ;
struct V_210 * V_211 ;
int V_16 = 0 ;
if ( ! V_102 )
return - V_60 ;
F_62 ( V_209 ) ;
V_211 = F_63 ( V_209 , V_102 ) ;
switch ( V_207 ) {
case V_212 :
if ( V_102 -> V_213 != V_214 )
goto exit;
if ( V_102 -> V_109 -> V_215 )
V_16 = V_102 -> V_109 -> V_215 ( V_102 ) ;
if ( ( V_102 -> V_166 & V_216 ) &&
V_211 -> V_217 == V_218 &&
! V_211 -> V_219 )
F_64 ( V_209 , V_102 ) ;
break;
case V_220 :
case V_221 :
case V_222 :
case V_223 :
if ( V_102 -> V_213 != V_224 )
goto exit;
if ( V_211 -> V_219 )
F_65 ( V_209 , V_102 ) ;
if ( V_102 -> V_109 -> V_225 )
V_16 = V_102 -> V_109 -> V_225 ( V_102 ) ;
break;
default:
V_16 = - V_60 ;
}
exit:
F_66 ( V_209 ) ;
return V_16 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_25 ( V_2 ) ;
struct V_208 * V_209 = V_27 -> V_209 ;
struct V_82 * V_83 ;
V_83 = V_27 -> V_30 ;
F_33 ( F_34 ( & V_83 -> V_173 ) ) ;
if ( V_83 -> V_41 )
if ( F_68 ( V_83 -> V_41 , V_83 -> V_80 ) )
F_69 ( V_209 -> V_226 , L_27 ) ;
if ( V_83 -> V_42 )
F_26 ( V_83 -> V_42 ) ;
if ( V_27 -> V_39 == V_40 ) {
if ( V_83 -> V_29 . V_42 [ 0 ] ) {
F_26 ( V_83 -> V_29 . V_42 [ 0 ] ) ;
F_70 ( & V_83 -> V_29 ) ;
V_83 -> V_29 . V_42 [ 0 ] = NULL ;
}
}
V_83 -> V_42 = NULL ;
V_83 -> V_41 = 0 ;
V_83 -> V_227 = 0 ;
V_83 -> V_80 = 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_7 , 0 , sizeof( V_2 -> V_7 ) ) ;
memset ( & V_2 -> V_9 , 0 , sizeof( V_2 -> V_9 ) ) ;
F_72 ( V_2 -> V_9 . V_103 , V_228 , sizeof( V_2 -> V_9 . V_103 ) ) ;
}
static int F_73 ( struct V_208 * V_209 )
{
int V_57 ;
F_6 ( L_28 ) ;
for ( V_57 = 0 ; V_57 < V_209 -> V_229 ; V_57 ++ ) {
struct V_1 * V_2 = V_209 -> V_230 [ V_57 ] ;
F_67 ( V_2 ) ;
F_71 ( V_2 ) ;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , unsigned long V_80 ,
unsigned long V_41 )
{
struct V_26 * V_27 = F_25 ( V_2 ) ;
struct V_208 * V_209 = V_27 -> V_209 ;
struct V_82 * V_83 ;
void T_1 * V_42 ;
int V_16 ;
V_83 = V_27 -> V_30 ;
V_83 -> V_41 = 0 ;
V_83 -> V_42 = NULL ;
memset ( & V_83 -> V_29 , 0 , sizeof V_83 -> V_29 ) ;
V_83 -> V_80 = 0 ;
V_83 -> type = 0 ;
V_83 -> V_227 = false ;
V_83 -> V_231 = false ;
V_80 = F_75 ( V_80 ) ;
if ( ! V_41 ) {
F_6 ( L_29 , V_80 , V_27 -> V_103 ) ;
V_16 = F_76 ( V_80 , & V_41 ) ;
} else {
F_6 ( L_30 , V_80 , V_41 ,
V_27 -> V_103 ) ;
V_16 = F_77 ( V_41 , V_80 ) ;
}
if ( V_16 ) {
F_69 ( V_209 -> V_226 , L_31 ) ;
return - V_232 ;
}
if ( V_27 -> V_39 != V_40 ) {
V_42 = F_78 ( V_41 , V_80 ) ;
if ( ! V_42 ) {
F_69 ( V_209 -> V_226 , L_32 ) ;
F_68 ( V_41 , V_80 ) ;
return - V_232 ;
}
F_6 ( L_33 , V_41 , V_42 ) ;
} else {
V_16 = F_79 ( & V_83 -> V_29 ) ;
if ( V_16 ) {
F_69 ( V_209 -> V_226 , L_34 ) ;
return V_16 ;
}
V_42 = NULL ;
}
V_83 -> V_41 = V_41 ;
V_83 -> V_42 = V_42 ;
V_83 -> V_80 = V_80 ;
V_83 -> V_227 = 1 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , unsigned long V_80 ,
unsigned long V_41 )
{
struct V_26 * V_27 = F_25 ( V_2 ) ;
struct V_208 * V_209 = V_27 -> V_209 ;
struct V_101 * V_102 ;
int V_12 ;
V_102 = F_32 ( V_2 ) ;
if ( ! V_102 )
return 0 ;
switch ( F_81 ( V_209 , V_102 ) ) {
case 16 :
V_12 = 2 ;
break;
case 24 :
V_12 = 4 ;
break;
default:
V_12 = 4 ;
break;
}
if ( ! V_80 ) {
T_2 V_20 , V_22 ;
V_102 -> V_109 -> V_233 ( V_102 , & V_20 , & V_22 ) ;
if ( V_27 -> V_39 == V_40 ) {
V_80 = F_82 ( F_21 ( V_20 , V_22 , V_12 ) ,
F_21 ( V_22 , V_20 , V_12 ) ) ;
F_6 ( L_35 ,
V_20 * V_22 * V_12 , V_80 ) ;
} else {
V_80 = V_20 * V_22 * V_12 ;
}
}
if ( ! V_80 )
return 0 ;
return F_74 ( V_2 , V_80 , V_41 ) ;
}
static int F_83 ( const char * V_234 , int V_235 ,
unsigned long * V_236 , unsigned long * V_237 )
{
int V_238 ;
unsigned long V_80 ;
unsigned long V_41 = 0 ;
char * V_19 , * V_175 ;
V_175 = ( char * ) V_234 ;
while ( 1 ) {
V_19 = V_175 ;
V_238 = F_84 ( V_19 , & V_19 , 10 ) ;
if ( V_19 == V_175 )
return - V_60 ;
if ( * V_19 != ':' )
return - V_60 ;
if ( V_238 >= V_235 )
return - V_60 ;
V_80 = F_85 ( V_19 + 1 , & V_19 ) ;
if ( ! V_80 )
return - V_60 ;
V_41 = 0 ;
if ( * V_19 == '@' ) {
V_41 = F_84 ( V_19 + 1 , & V_19 , 16 ) ;
if ( ! V_41 )
return - V_60 ;
}
V_237 [ V_238 ] = V_41 ;
V_236 [ V_238 ] = V_80 ;
if ( * V_19 == 0 )
break;
if ( * V_19 != ',' )
return - V_60 ;
++ V_19 ;
V_175 = V_19 ;
}
return 0 ;
}
static int F_86 ( struct V_208 * V_209 )
{
int V_57 , V_16 ;
unsigned long V_239 [ 10 ] ;
unsigned long V_240 [ 10 ] ;
memset ( & V_239 , 0 , sizeof( V_239 ) ) ;
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
if ( V_241 && F_83 ( V_241 , 10 ,
V_239 , V_240 ) ) {
F_69 ( V_209 -> V_226 , L_36 ) ;
memset ( & V_239 , 0 , sizeof( V_239 ) ) ;
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
}
for ( V_57 = 0 ; V_57 < V_209 -> V_229 ; V_57 ++ ) {
if ( V_57 == 0 || V_239 [ V_57 ] != 0 ) {
V_16 = F_80 ( V_209 -> V_230 [ V_57 ] ,
V_239 [ V_57 ] , V_240 [ V_57 ] ) ;
if ( V_16 )
return V_16 ;
}
}
for ( V_57 = 0 ; V_57 < V_209 -> V_229 ; V_57 ++ ) {
struct V_26 * V_27 = F_25 ( V_209 -> V_230 [ V_57 ] ) ;
struct V_82 * V_83 ;
V_83 = V_27 -> V_30 ;
F_6 ( L_37 ,
V_57 ,
V_83 -> V_41 ,
V_83 -> V_42 ,
V_83 -> V_80 ) ;
}
return 0 ;
}
int F_87 ( struct V_1 * V_2 , unsigned long V_80 , int type )
{
struct V_26 * V_27 = F_25 ( V_2 ) ;
struct V_208 * V_209 = V_27 -> V_209 ;
struct V_101 * V_102 = F_32 ( V_2 ) ;
struct V_82 * V_83 = V_27 -> V_30 ;
unsigned long V_242 = V_83 -> V_80 ;
unsigned long V_243 = V_83 -> V_41 ;
int V_244 = V_83 -> type ;
int V_16 ;
if ( type != V_245 )
return - V_60 ;
V_80 = F_75 ( V_80 ) ;
if ( V_242 == V_80 && V_244 == type )
return 0 ;
if ( V_102 && V_102 -> V_109 -> V_131 )
V_102 -> V_109 -> V_131 ( V_102 ) ;
F_67 ( V_2 ) ;
if ( V_80 == 0 ) {
F_71 ( V_2 ) ;
return 0 ;
}
V_16 = F_74 ( V_2 , V_80 , 0 ) ;
if ( V_16 ) {
if ( V_242 )
F_74 ( V_2 , V_242 , V_243 ) ;
if ( V_83 -> V_80 == 0 )
F_71 ( V_2 ) ;
return V_16 ;
}
if ( V_242 == V_80 )
return 0 ;
if ( V_242 == 0 ) {
F_6 ( L_38 , V_27 -> V_103 ) ;
V_16 = F_88 ( V_209 , V_2 ) ;
if ( V_16 ) {
F_6 ( L_39 ) ;
goto V_154;
}
V_16 = F_43 ( V_2 , 1 ) ;
if ( V_16 ) {
F_6 ( L_40 ) ;
goto V_154;
}
} else {
struct V_6 V_169 ;
memcpy ( & V_169 , & V_2 -> V_7 , sizeof( V_169 ) ) ;
V_16 = F_31 ( V_2 , & V_169 ) ;
if ( V_16 )
goto V_154;
memcpy ( & V_2 -> V_7 , & V_169 , sizeof( V_2 -> V_7 ) ) ;
F_30 ( V_2 ) ;
V_16 = F_24 ( V_2 ) ;
if ( V_16 )
goto V_154;
}
return 0 ;
V_154:
F_67 ( V_2 ) ;
F_71 ( V_2 ) ;
return V_16 ;
}
static void F_89 ( struct V_246 * V_247 )
{
struct V_101 * V_248 ;
struct V_249 * V_250 ;
struct V_210 * V_211 ;
T_2 V_20 , V_22 ;
unsigned int V_251 ;
struct V_208 * V_209 ;
V_211 = F_90 ( V_247 , struct V_210 ,
V_252 . V_247 ) ;
V_248 = V_211 -> V_248 ;
V_250 = V_248 -> V_109 ;
V_209 = V_211 -> V_209 ;
if ( ! V_250 || ! V_250 -> V_253 )
return;
if ( V_250 -> V_131 )
V_250 -> V_131 ( V_248 ) ;
V_250 -> V_233 ( V_248 , & V_20 , & V_22 ) ;
V_250 -> V_253 ( V_248 , 0 , 0 , V_20 , V_22 ) ;
V_251 = V_254 ;
if ( V_251 == 0 )
V_251 = 20 ;
F_91 ( V_209 -> V_255 ,
& V_211 -> V_252 , V_256 / V_251 ) ;
}
void F_64 ( struct V_208 * V_209 ,
struct V_101 * V_102 )
{
struct V_210 * V_211 ;
if ( V_209 -> V_255 == NULL ) {
struct V_257 * V_258 ;
V_258 = F_92 ( L_41 ) ;
if ( V_258 == NULL ) {
F_69 ( V_209 -> V_226 , L_42
L_43 ) ;
return;
}
V_209 -> V_255 = V_258 ;
}
V_211 = F_63 ( V_209 , V_102 ) ;
F_93 ( & V_211 -> V_252 , F_89 ) ;
V_211 -> V_219 = true ;
F_89 ( & V_211 -> V_252 . V_247 ) ;
}
void F_65 ( struct V_208 * V_209 ,
struct V_101 * V_102 )
{
struct V_210 * V_211 ;
V_211 = F_63 ( V_209 , V_102 ) ;
F_94 ( & V_211 -> V_252 ) ;
V_211 -> V_219 = false ;
}
static int F_88 ( struct V_208 * V_209 , struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_101 * V_102 = F_32 ( V_2 ) ;
struct V_26 * V_27 = F_25 ( V_2 ) ;
int V_16 = 0 ;
V_2 -> V_259 = & V_260 ;
V_2 -> V_261 = V_262 ;
V_2 -> V_201 = V_209 -> V_201 ;
if ( V_27 -> V_30 -> V_80 == 0 ) {
F_71 ( V_2 ) ;
return 0 ;
}
V_7 -> V_49 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_108 = V_263 ;
if ( V_102 ) {
T_2 V_20 , V_22 ;
int V_142 = ( V_7 -> V_108 + V_27 -> V_142 [ 0 ] ) % 4 ;
V_102 -> V_109 -> V_233 ( V_102 , & V_20 , & V_22 ) ;
if ( V_142 == V_33 ||
V_142 == V_38 ) {
V_7 -> V_75 = V_22 ;
V_7 -> V_76 = V_20 ;
} else {
V_7 -> V_75 = V_20 ;
V_7 -> V_76 = V_22 ;
}
V_7 -> V_21 = V_7 -> V_75 ;
V_7 -> V_23 = V_7 -> V_76 ;
if ( ! V_7 -> V_13 ) {
switch ( F_81 ( V_209 , V_102 ) ) {
case 16 :
V_7 -> V_13 = 16 ;
break;
case 24 :
V_7 -> V_13 = 32 ;
break;
default:
F_69 ( V_209 -> V_226 , L_44
L_45 ) ;
return - V_60 ;
}
}
} else {
V_7 -> V_75 = 320 ;
V_7 -> V_76 = 240 ;
V_7 -> V_21 = V_7 -> V_75 ;
V_7 -> V_23 = V_7 -> V_76 ;
if ( ! V_7 -> V_13 )
V_7 -> V_13 = 16 ;
}
V_16 = F_31 ( V_2 , V_7 ) ;
if ( V_16 )
goto V_154;
F_30 ( V_2 ) ;
V_16 = F_24 ( V_2 ) ;
if ( V_16 )
goto V_154;
V_16 = F_95 ( & V_2 -> V_203 , 256 , 0 ) ;
if ( V_16 )
F_69 ( V_209 -> V_226 , L_46 ) ;
V_154:
return V_16 ;
}
static void F_96 ( struct V_208 * V_209 , struct V_1 * V_2 )
{
F_97 ( & V_2 -> V_203 ) ;
}
static void F_98 ( struct V_208 * V_209 )
{
int V_57 ;
F_6 ( L_47 ) ;
if ( V_209 == NULL )
return;
for ( V_57 = 0 ; V_57 < V_209 -> V_229 ; V_57 ++ )
F_99 ( V_209 -> V_230 [ V_57 ] ) ;
F_73 ( V_209 ) ;
for ( V_57 = 0 ; V_57 < V_209 -> V_229 ; V_57 ++ ) {
F_96 ( V_209 , V_209 -> V_230 [ V_57 ] ) ;
F_100 ( V_209 -> V_230 [ V_57 ] ) ;
}
for ( V_57 = 0 ; V_57 < V_209 -> V_264 ; V_57 ++ ) {
struct V_101 * V_248 = V_209 -> V_265 [ V_57 ] . V_248 ;
if ( V_209 -> V_265 [ V_57 ] . V_219 )
F_65 ( V_209 , V_248 ) ;
if ( V_248 -> V_213 != V_266 )
V_248 -> V_109 -> V_267 ( V_248 ) ;
F_101 ( V_248 ) ;
}
if ( V_209 -> V_255 != NULL ) {
F_102 ( V_209 -> V_255 ) ;
F_103 ( V_209 -> V_255 ) ;
V_209 -> V_255 = NULL ;
}
F_104 ( V_209 -> V_226 , NULL ) ;
F_105 ( V_209 ) ;
}
static int F_106 ( struct V_208 * V_209 )
{
int V_16 , V_57 ;
V_209 -> V_229 = 0 ;
F_6 ( L_48 , V_268 ) ;
for ( V_57 = 0 ; V_57 < V_268 ; V_57 ++ ) {
struct V_1 * V_2 ;
struct V_26 * V_27 ;
V_2 = F_107 ( sizeof( struct V_26 ) ,
V_209 -> V_226 ) ;
if ( V_2 == NULL ) {
F_69 ( V_209 -> V_226 ,
L_49 ) ;
return - V_232 ;
}
F_71 ( V_2 ) ;
V_209 -> V_230 [ V_57 ] = V_2 ;
V_27 = F_25 ( V_2 ) ;
V_27 -> V_209 = V_209 ;
V_27 -> V_103 = V_57 ;
V_27 -> V_30 = & V_209 -> V_269 [ V_57 ] ;
V_27 -> V_30 -> V_103 = V_57 ;
F_108 ( & V_27 -> V_30 -> V_270 ) ;
V_27 -> V_39 = V_271 ? V_40 :
V_272 ;
V_27 -> V_153 = V_273 ;
V_209 -> V_229 ++ ;
}
F_6 ( L_50 ) ;
for ( V_57 = 0 ; V_57 < F_109 ( V_209 -> V_229 , V_209 -> V_105 ) ; V_57 ++ ) {
struct V_26 * V_27 = F_25 ( V_209 -> V_230 [ V_57 ] ) ;
V_27 -> V_106 [ 0 ] = V_209 -> V_106 [ V_57 ] ;
V_27 -> V_105 = 1 ;
}
V_16 = F_86 ( V_209 ) ;
if ( V_16 ) {
F_69 ( V_209 -> V_226 , L_51 ) ;
return V_16 ;
}
F_6 ( L_52 ) ;
for ( V_57 = 0 ; V_57 < V_209 -> V_229 ; V_57 ++ ) {
struct V_1 * V_2 = V_209 -> V_230 [ V_57 ] ;
struct V_26 * V_27 = F_25 ( V_2 ) ;
F_47 ( V_27 -> V_30 ) ;
V_16 = F_88 ( V_209 , V_2 ) ;
F_48 ( V_27 -> V_30 ) ;
if ( V_16 ) {
F_69 ( V_209 -> V_226 , L_53 ) ;
return V_16 ;
}
}
F_6 ( L_54 ) ;
for ( V_57 = 0 ; V_57 < V_209 -> V_229 ; V_57 ++ ) {
V_16 = F_110 ( V_209 -> V_230 [ V_57 ] ) ;
if ( V_16 != 0 ) {
F_69 ( V_209 -> V_226 ,
L_55 , V_57 ) ;
return V_16 ;
}
}
F_6 ( L_56 ) ;
for ( V_57 = 0 ; V_57 < V_209 -> V_229 ; V_57 ++ ) {
struct V_1 * V_2 = V_209 -> V_230 [ V_57 ] ;
struct V_26 * V_27 = F_25 ( V_2 ) ;
F_47 ( V_27 -> V_30 ) ;
V_16 = F_43 ( V_2 , 1 ) ;
F_48 ( V_27 -> V_30 ) ;
if ( V_16 ) {
F_69 ( V_209 -> V_226 , L_57 ) ;
return V_16 ;
}
}
if ( V_209 -> V_229 > 0 ) {
struct V_26 * V_27 = F_25 ( V_209 -> V_230 [ 0 ] ) ;
if ( V_27 -> V_105 > 0 ) {
struct V_144 * V_145 = V_27 -> V_106 [ 0 ] ;
V_145 -> V_164 -> V_165 ( V_145 -> V_164 ) ;
V_16 = F_45 ( V_145 , 1 ) ;
if ( V_16 ) {
F_69 ( V_209 -> V_226 ,
L_58 ) ;
return V_16 ;
}
}
}
F_6 ( L_59 ) ;
return 0 ;
}
static int F_111 ( const char * V_274 ,
struct V_101 * V_102 ,
struct V_115 * V_116 , T_3 * V_275 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_276 * V_259 ;
int V_16 ;
#ifdef F_112
if ( strcmp ( V_274 , L_60 ) == 0 ) {
* V_116 = V_277 ;
* V_275 = 24 ;
return 0 ;
} else if ( strcmp ( V_274 , L_61 ) == 0 ) {
* V_116 = V_278 ;
* V_275 = 24 ;
return 0 ;
}
#endif
* V_275 = 0 ;
V_2 = NULL ;
V_7 = NULL ;
V_259 = NULL ;
V_2 = F_113 ( sizeof( * V_2 ) , V_279 ) ;
if ( V_2 == NULL ) {
V_16 = - V_232 ;
goto V_154;
}
V_7 = F_113 ( sizeof( * V_7 ) , V_279 ) ;
if ( V_7 == NULL ) {
V_16 = - V_232 ;
goto V_154;
}
V_259 = F_113 ( sizeof( * V_259 ) , V_279 ) ;
if ( V_259 == NULL ) {
V_16 = - V_232 ;
goto V_154;
}
V_2 -> V_259 = V_259 ;
V_16 = F_114 ( V_7 , V_2 , V_274 , NULL , 0 , NULL , 24 ) ;
if ( V_16 == 0 ) {
V_16 = - V_60 ;
goto V_154;
}
if ( V_102 -> V_109 -> V_114 ) {
V_102 -> V_109 -> V_114 ( V_102 , V_116 ) ;
} else {
V_116 -> V_280 = V_281 ;
V_116 -> V_282 = V_133 ;
V_116 -> V_283 = V_284 ;
}
V_116 -> V_118 = F_115 ( V_7 -> V_117 ) ;
V_116 -> V_120 = V_7 -> V_119 ;
V_116 -> V_122 = V_7 -> V_121 ;
V_116 -> V_124 = V_7 -> V_123 ;
V_116 -> V_126 = V_7 -> V_125 ;
V_116 -> V_128 = V_7 -> V_127 ;
V_116 -> V_130 = V_7 -> V_129 ;
V_116 -> V_285 = V_7 -> V_75 ;
V_116 -> V_286 = V_7 -> V_76 ;
V_116 -> V_132 = V_7 -> V_131 & V_134 ?
V_133 :
V_287 ;
V_116 -> V_135 = V_7 -> V_131 & V_136 ?
V_133 :
V_287 ;
V_116 -> V_138 = V_7 -> V_137 & V_139 ;
switch ( V_7 -> V_13 ) {
case 16 :
* V_275 = 16 ;
break;
case 24 :
case 32 :
default:
* V_275 = 24 ;
break;
}
V_16 = 0 ;
V_154:
F_105 ( V_2 ) ;
F_105 ( V_7 ) ;
F_105 ( V_259 ) ;
return V_16 ;
}
static int F_116 ( struct V_208 * V_209 ,
struct V_101 * V_102 , char * V_274 )
{
int V_16 ;
T_3 V_275 ;
struct V_115 V_116 , V_288 ;
struct V_210 * V_211 ;
V_16 = F_111 ( V_274 , V_102 , & V_116 , & V_275 ) ;
if ( V_16 )
return V_16 ;
V_211 = F_63 ( V_209 , V_102 ) ;
V_211 -> V_289 = V_275 ;
if ( V_102 -> V_109 -> V_290 ) {
V_16 = V_102 -> V_109 -> V_290 ( V_102 , & V_116 ) ;
if ( V_16 )
return V_16 ;
} else {
if ( V_102 -> V_109 -> V_114 ) {
V_102 -> V_109 -> V_114 ( V_102 , & V_288 ) ;
if ( V_288 . V_285 != V_116 . V_285 ||
V_288 . V_286 != V_116 . V_286 )
return - V_60 ;
}
}
if ( V_102 -> V_109 -> V_291 )
V_102 -> V_109 -> V_291 ( V_102 , & V_116 ) ;
return 0 ;
}
static int F_81 ( struct V_208 * V_209 ,
struct V_101 * V_248 )
{
struct V_210 * V_211 ;
F_117 ( V_248 -> V_109 -> V_292 == NULL ) ;
V_211 = F_63 ( V_209 , V_248 ) ;
if ( V_211 -> V_289 != 0 )
return V_211 -> V_289 ;
return V_248 -> V_109 -> V_292 ( V_248 ) ;
}
static int F_118 ( struct V_208 * V_209 )
{
char * V_293 , * V_294 , * V_295 ;
int V_16 = 0 ;
V_293 = F_119 ( V_296 , V_279 ) ;
if ( ! V_293 )
return - V_232 ;
V_294 = V_293 ;
while ( ! V_16 && ( V_295 = F_120 ( & V_294 , L_62 ) ) != NULL ) {
char * V_19 , * V_297 , * V_274 ;
struct V_101 * V_102 ;
int V_57 ;
V_19 = strchr ( V_295 , ':' ) ;
if ( ! V_19 ) {
V_16 = - V_60 ;
break;
}
* V_19 = 0 ;
V_297 = V_295 ;
V_274 = V_19 + 1 ;
V_102 = NULL ;
for ( V_57 = 0 ; V_57 < V_209 -> V_264 ; ++ V_57 ) {
if ( strcmp ( V_209 -> V_265 [ V_57 ] . V_248 -> V_298 ,
V_297 ) == 0 ) {
V_102 = V_209 -> V_265 [ V_57 ] . V_248 ;
break;
}
}
if ( ! V_102 ) {
V_16 = - V_60 ;
break;
}
V_16 = F_116 ( V_209 , V_102 , V_274 ) ;
if ( V_16 )
break;
}
F_105 ( V_293 ) ;
return V_16 ;
}
static void F_121 ( struct V_299 * V_59 ,
struct V_101 * V_102 ,
struct V_115 * V_24 )
{
if ( V_102 -> V_109 -> V_114 ) {
V_102 -> V_109 -> V_114 ( V_102 , V_24 ) ;
} else {
V_24 -> V_280 = V_281 ;
V_24 -> V_282 = V_133 ;
V_24 -> V_283 = V_284 ;
}
V_24 -> V_285 = V_59 -> V_75 ;
V_24 -> V_286 = V_59 -> V_76 ;
V_24 -> V_118 = F_115 ( V_59 -> V_117 ) ;
V_24 -> V_128 = V_59 -> V_127 ;
V_24 -> V_122 = V_59 -> V_121 ;
V_24 -> V_120 = V_59 -> V_119 ;
V_24 -> V_130 = V_59 -> V_129 ;
V_24 -> V_126 = V_59 -> V_125 ;
V_24 -> V_124 = V_59 -> V_123 ;
V_24 -> V_132 = V_59 -> V_131 & V_134 ?
V_133 :
V_287 ;
V_24 -> V_135 = V_59 -> V_131 & V_136 ?
V_133 :
V_287 ;
V_24 -> V_138 = V_59 -> V_137 & V_139 ;
}
static int F_122 ( struct V_101 * V_102 ,
struct V_115 * V_116 )
{
struct V_300 * V_301 ;
T_3 * V_302 ;
int V_16 , V_57 , V_303 , V_304 , V_176 ;
if ( ! V_102 -> V_109 -> V_305 )
return - V_306 ;
V_176 = 0x80 * 2 ;
V_302 = F_123 ( V_176 , V_279 ) ;
V_16 = V_102 -> V_109 -> V_305 ( V_102 , V_302 , V_176 ) ;
if ( V_16 < 0 )
goto V_307;
V_301 = F_113 ( sizeof( * V_301 ) , V_279 ) ;
F_124 ( V_302 , V_301 ) ;
if ( V_302 [ 126 ] > 0 )
F_125 ( V_302 + 0x80 , V_301 ) ;
V_303 = 0 ;
V_304 = - 1 ;
for ( V_57 = 0 ; V_57 < V_301 -> V_308 ; ++ V_57 ) {
struct V_299 * V_59 ;
struct V_115 V_24 ;
V_59 = & V_301 -> V_309 [ V_57 ] ;
if ( V_59 -> V_117 == 0 )
continue;
if ( V_59 -> V_75 == 2880 || V_59 -> V_75 == 1440 )
continue;
F_121 ( V_59 , V_102 , & V_24 ) ;
V_16 = V_102 -> V_109 -> V_290 ( V_102 , & V_24 ) ;
if ( V_16 == 0 && V_303 < V_59 -> V_75 ) {
V_303 = V_59 -> V_75 ;
V_304 = V_57 ;
}
}
if ( V_303 == 0 ) {
V_16 = - V_92 ;
goto V_310;
}
F_121 ( & V_301 -> V_309 [ V_304 ] , V_102 ,
V_116 ) ;
V_16 = 0 ;
V_310:
F_126 ( V_301 -> V_309 ) ;
F_105 ( V_301 ) ;
V_307:
F_105 ( V_302 ) ;
return V_16 ;
}
static int F_127 ( struct V_208 * V_209 ,
struct V_101 * V_248 )
{
struct V_249 * V_250 = V_248 -> V_109 ;
struct V_210 * V_211 ;
int V_16 ;
V_16 = V_250 -> V_311 ( V_248 ) ;
if ( V_16 ) {
F_128 ( V_209 -> V_226 , L_63 ,
V_248 -> V_298 ) ;
return V_16 ;
}
V_211 = F_63 ( V_209 , V_248 ) ;
V_211 -> V_209 = V_209 ;
if ( V_248 -> V_166 & V_216 ) {
T_2 V_20 , V_22 ;
if ( V_312 ) {
F_64 ( V_209 , V_248 ) ;
V_211 -> V_217 = V_218 ;
} else {
V_211 -> V_217 = V_313 ;
}
if ( V_250 -> V_314 ) {
V_16 = V_250 -> V_314 ( V_248 , 1 ) ;
if ( V_16 ) {
F_69 ( V_209 -> V_226 , L_64 ) ;
return V_16 ;
}
}
V_250 -> V_233 ( V_248 , & V_20 , & V_22 ) ;
V_16 = V_250 -> V_253 ( V_248 , 0 , 0 , V_20 , V_22 ) ;
if ( V_16 ) {
F_69 ( V_209 -> V_226 ,
L_65 ) ;
return V_16 ;
}
} else {
V_211 -> V_217 = V_218 ;
}
return 0 ;
}
static int T_6 F_129 ( struct V_315 * V_316 )
{
struct V_208 * V_209 = NULL ;
int V_16 = 0 ;
int V_57 ;
struct V_144 * V_145 ;
struct V_101 * V_317 ;
struct V_101 * V_248 ;
F_6 ( L_66 ) ;
if ( V_316 -> V_318 != 0 ) {
F_69 ( & V_316 -> V_226 , L_67 ) ;
V_16 = - V_306 ;
goto V_319;
}
V_209 = F_113 ( sizeof( struct V_208 ) , V_279 ) ;
if ( V_209 == NULL ) {
V_16 = - V_232 ;
goto V_319;
}
if ( V_271 && ! F_130 () && ! F_131 () ) {
V_271 = 0 ;
F_128 ( & V_316 -> V_226 , L_68
L_69 ) ;
}
F_132 ( & V_209 -> V_320 ) ;
V_209 -> V_226 = & V_316 -> V_226 ;
F_133 ( V_316 , V_209 ) ;
V_16 = 0 ;
V_209 -> V_264 = 0 ;
V_248 = NULL ;
F_134 (dssdev) {
struct V_210 * V_211 ;
F_135 ( V_248 ) ;
if ( ! V_248 -> V_109 ) {
F_128 ( & V_316 -> V_226 , L_70 ,
V_248 -> V_298 ) ;
F_101 ( V_248 ) ;
continue;
}
V_211 = & V_209 -> V_265 [ V_209 -> V_264 ++ ] ;
V_211 -> V_248 = V_248 ;
if ( V_248 -> V_166 & V_216 )
V_211 -> V_217 = V_313 ;
else
V_211 -> V_217 = V_218 ;
}
if ( V_16 )
goto V_321;
if ( V_209 -> V_264 == 0 ) {
F_69 ( & V_316 -> V_226 , L_71 ) ;
V_16 = - V_60 ;
goto V_321;
}
V_209 -> V_105 = F_136 () ;
for ( V_57 = 0 ; V_57 < V_209 -> V_105 ; V_57 ++ )
V_209 -> V_106 [ V_57 ] = F_137 ( V_57 ) ;
V_209 -> V_322 = F_138 () ;
for ( V_57 = 0 ; V_57 < V_209 -> V_322 ; V_57 ++ )
V_209 -> V_323 [ V_57 ] = F_139 ( V_57 ) ;
V_145 = F_137 ( 0 ) ;
if ( V_145 -> V_164 && V_145 -> V_164 -> V_324 ) {
V_317 = V_145 -> V_164 -> V_324 ;
} else {
F_128 ( & V_316 -> V_226 , L_72 ) ;
V_317 = NULL ;
}
if ( V_296 && strlen ( V_296 ) > 0 ) {
if ( F_118 ( V_209 ) )
F_128 ( & V_316 -> V_226 , L_73 ) ;
} else if ( V_317 && V_317 -> V_109 -> V_291 &&
V_317 -> V_109 -> V_290 ) {
struct V_115 V_24 ;
V_16 = F_122 ( V_317 , & V_24 ) ;
if ( V_16 == 0 )
V_317 -> V_109 -> V_291 ( V_317 , & V_24 ) ;
}
V_16 = F_106 ( V_209 ) ;
if ( V_16 )
goto V_321;
for ( V_57 = 0 ; V_57 < V_209 -> V_322 ; V_57 ++ ) {
struct V_325 * V_326 ;
V_326 = V_209 -> V_323 [ V_57 ] ;
V_16 = V_326 -> V_165 ( V_326 ) ;
if ( V_16 )
F_128 ( V_209 -> V_226 , L_74 ) ;
}
F_6 ( L_75 ) ;
if ( V_317 ) {
V_16 = F_127 ( V_209 , V_317 ) ;
if ( V_16 ) {
F_69 ( V_209 -> V_226 ,
L_76
L_77 ) ;
goto V_321;
}
}
F_6 ( L_78 ) ;
V_16 = F_140 ( V_209 ) ;
if ( V_16 ) {
F_69 ( V_209 -> V_226 , L_79 ) ;
goto V_321;
}
return 0 ;
V_321:
F_98 ( V_209 ) ;
V_319:
F_69 ( & V_316 -> V_226 , L_80 ) ;
return V_16 ;
}
static int T_7 F_141 ( struct V_315 * V_316 )
{
struct V_208 * V_209 = F_142 ( V_316 ) ;
F_143 ( V_209 ) ;
F_98 ( V_209 ) ;
return 0 ;
}
static int T_6 F_144 ( void )
{
F_6 ( L_81 ) ;
if ( F_145 ( & V_327 , F_129 ) ) {
F_146 ( V_328 L_82 ) ;
return - V_306 ;
}
return 0 ;
}
static void T_7 F_147 ( void )
{
F_6 ( L_83 ) ;
F_148 ( & V_327 ) ;
}
