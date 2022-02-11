static T_1 F_1 ( T_2 V_1 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_1 == V_3 [ V_2 ] . V_1 )
return V_3 [ V_2 ] . V_4 ;
F_3 ( 1 , L_1 ) ;
return V_3 [ 0 ] . V_4 ;
}
static T_3 F_4 ( int V_5 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
T_1 V_2 ;
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ ) {
T_1 V_9 = F_5 ( V_8 -> V_10 +
F_6 ( V_2 ) ) ;
F_7 ( V_9 , V_8 -> V_10 +
F_8 ( V_2 ) ) ;
F_7 ( 0x1 , V_8 -> V_10 + V_11 ) ;
F_7 ( 0x0 , V_8 -> V_10 + V_11 ) ;
F_7 ( 0x0 , V_8 -> V_10 +
F_8 ( V_2 ) ) ;
}
return V_12 ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_13 * V_6 = F_10 ( V_8 , V_8 -> V_14 ) ;
T_2 V_15 ;
int V_2 , V_16 ;
int V_17 ;
V_17 = F_11 ( & V_8 -> V_18 . V_19 , & V_15 ) ;
if ( V_17 )
V_15 = 0 ;
for ( V_2 = 0 ; V_2 < V_8 -> V_20 ; V_2 ++ ) {
struct V_21 * clock = & V_8 -> clock [ V_2 ] ;
if ( ! strcmp ( clock -> V_22 , L_2 ) ||
! strcmp ( clock -> V_22 , L_3 ) ) {
T_1 V_4 = F_1 (
V_8 -> V_23 [ V_24 ] . V_1 ) ;
T_1 V_25 = V_8 -> V_26 . V_27 -> V_28 . V_29 ;
T_4 V_30 = V_15 * V_4 / ( 2 * V_25 * 4 ) ;
long V_31 ;
F_12 ( & V_30 ) ;
for ( V_16 = 0 ; V_16 < clock -> V_32 ; V_16 ++ )
if ( V_30 < clock -> V_33 [ V_16 ] )
break;
if ( V_16 == clock -> V_32 ) {
F_13 ( V_6 ,
L_4 ) ;
return - V_34 ;
}
if ( V_30 == 0 )
V_16 = clock -> V_32 - 1 ;
V_31 = F_14 ( clock -> V_35 , clock -> V_33 [ V_16 ] ) ;
if ( V_31 < 0 ) {
F_13 ( V_6 , L_5 ,
V_31 ) ;
return - V_34 ;
}
V_8 -> V_36 = V_31 ;
V_17 = F_15 ( clock -> V_35 , V_8 -> V_36 ) ;
if ( V_17 < 0 ) {
F_13 ( V_6 , L_6 , V_17 ) ;
return V_17 ;
}
}
}
return 0 ;
}
static void F_16 ( struct V_7 * V_8 )
{
F_7 ( 0x1 , V_8 -> V_10 + V_37 ) ;
F_17 ( 5000 , 8000 ) ;
F_7 ( 0x0 , V_8 -> V_10 + V_37 ) ;
}
static int F_18 ( struct V_38 * V_39 , int V_40 )
{
struct V_7 * V_8 = F_19 ( V_39 ) ;
struct V_13 * V_6 = F_10 ( V_8 , V_8 -> V_14 ) ;
if ( V_40 ) {
T_1 V_41 ;
int V_17 ;
V_17 = F_9 ( V_8 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_20 ( V_8 -> V_20 , V_8 -> clock , V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
F_21 ( V_8 -> V_5 ) ;
F_16 ( V_8 ) ;
V_41 = F_5 ( V_8 -> V_10 +
V_42 ) ;
F_22 ( V_6 , L_7 , V_41 ) ;
} else {
F_23 ( V_8 -> V_5 ) ;
F_24 ( V_8 -> V_20 , V_8 -> clock ) ;
}
return 0 ;
}
static T_1 F_25 ( struct V_43 * V_28 )
{
T_1 V_44 ;
int V_2 ;
V_44 = 1 << V_28 -> V_35 . V_45 ;
for ( V_2 = 0 ; V_2 < V_28 -> V_29 ; V_2 ++ )
V_44 |= 1 << V_28 -> V_46 [ V_2 ] . V_45 ;
return V_44 ;
}
static T_1 F_26 ( struct V_7 * V_8 )
{
T_1 V_4 = F_1 (
V_8 -> V_23 [ V_24 ] . V_1 ) ;
T_1 V_25 = V_8 -> V_26 . V_27 -> V_28 . V_29 ;
T_2 V_15 ;
T_2 V_47 ;
T_2 V_48 ;
T_2 V_49 ;
T_2 V_50 ;
T_2 V_51 ;
T_2 V_52 ;
T_1 V_53 ;
int V_17 ;
V_17 = F_11 ( & V_8 -> V_18 . V_19 , & V_15 ) ;
if ( V_17 ) {
F_13 ( F_10 ( V_8 , V_8 -> V_14 ) ,
L_8 ) ;
return 0 ;
}
if ( ! V_15 ) {
F_13 ( F_10 ( V_8 , V_8 -> V_14 ) ,
L_9 ) ;
return 0 ;
}
V_47 = V_15 * V_4 / ( 2 * V_25 ) ;
V_48 = F_27 ( 1000000000000LL , V_47 ) ;
V_48 /= 2 ;
V_50 = 85000 + 6 * V_48 ;
V_51 = 145000 + 10 * V_48 ;
V_52 = ( V_50 + V_51 ) / 2 ;
V_49 = F_27 ( 1000000000000LL , V_8 -> V_36 ) ;
V_53 = V_52 / V_49 ;
return V_53 ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_54 * V_26 = & V_8 -> V_26 ;
T_1 V_44 = F_25 ( & V_26 -> V_27 -> V_28 ) ;
T_1 V_53 ;
T_1 V_9 ;
int V_2 = 0 ;
V_53 = F_26 ( V_8 ) ;
if ( ! V_53 )
return - V_34 ;
V_9 = F_5 ( V_8 -> V_55 ) ;
if ( V_26 -> V_56 && ( V_44 & 0x18 ) == 0x18 ) {
V_9 &= ~ 0xf0 ;
V_9 |= V_26 -> V_57 << 4 ;
} else {
V_9 &= ~ 0xf ;
V_9 |= V_26 -> V_57 ;
}
F_7 ( V_9 , V_8 -> V_55 ) ;
F_7 ( 0x1 , V_8 -> V_10 +
V_58 ) ;
F_7 ( 0x1 , V_8 -> V_10 +
V_59 ) ;
V_9 = 0x1 ;
V_9 |= V_44 << 1 ;
F_7 ( V_9 , V_8 -> V_10 + V_60 ) ;
V_9 = V_26 -> V_56 << 4 ;
F_7 ( V_9 , V_8 -> V_10 + V_37 ) ;
while ( V_44 ) {
if ( V_44 & 0x1 ) {
F_7 ( 0x10 , V_8 -> V_10 +
F_29 ( V_2 ) ) ;
F_7 ( V_53 , V_8 -> V_10 +
F_30 ( V_2 ) ) ;
F_7 ( 0x3f , V_8 -> V_10 +
F_31 ( V_2 ) ) ;
F_7 ( 0x3f , V_8 -> V_10 +
F_8 ( V_2 ) ) ;
}
V_44 >>= 1 ;
V_2 ++ ;
}
return 0 ;
}
static void F_32 ( struct V_7 * V_8 )
{
T_1 V_44 = F_25 ( & V_8 -> V_26 . V_27 -> V_28 ) ;
int V_2 = 0 ;
while ( V_44 ) {
if ( V_44 & 0x1 )
F_7 ( 0x0 , V_8 -> V_10 +
F_29 ( V_2 ) ) ;
V_44 >>= 1 ;
V_2 ++ ;
}
F_7 ( 0x0 , V_8 -> V_10 + V_60 ) ;
}
static int F_33 ( struct V_38 * V_39 , int V_61 )
{
struct V_7 * V_8 = F_19 ( V_39 ) ;
int V_17 = 0 ;
if ( V_61 )
V_17 = F_28 ( V_8 ) ;
else
F_32 ( V_8 ) ;
return V_17 ;
}
static struct V_62 *
F_34 ( struct V_7 * V_8 ,
struct V_63 * V_26 ,
unsigned int V_64 ,
enum V_65 V_66 )
{
if ( V_66 == V_67 )
return F_35 ( & V_8 -> V_18 , V_26 , V_64 ) ;
return & V_8 -> V_23 [ V_64 ] ;
}
static void F_36 ( struct V_7 * V_8 ,
struct V_63 * V_26 ,
unsigned int V_64 ,
struct V_62 * V_23 ,
enum V_65 V_66 )
{
unsigned int V_2 ;
switch ( V_64 ) {
case V_24 :
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_23 -> V_1 == V_3 [ V_2 ] . V_1 )
break;
if ( V_2 >= F_2 ( V_3 ) )
V_23 -> V_1 = V_68 ;
V_23 -> V_69 = F_37 ( T_2 , V_23 -> V_69 , 1 , 8191 ) ;
V_23 -> V_70 = F_37 ( T_2 , V_23 -> V_70 , 1 , 8191 ) ;
V_23 -> V_71 = V_72 ;
V_23 -> V_73 = V_74 ;
break;
case V_75 :
* V_23 = * F_34 ( V_8 , V_26 , V_76 ,
V_66 ) ;
break;
}
}
static int F_38 ( struct V_38 * V_39 ,
struct V_63 * V_26 ,
struct V_77 * V_1 )
{
struct V_7 * V_8 = F_19 ( V_39 ) ;
struct V_62 * V_78 ;
if ( V_1 -> V_64 == V_24 ) {
if ( V_1 -> V_79 >= F_2 ( V_3 ) )
return - V_34 ;
V_1 -> V_1 = V_3 [ V_1 -> V_79 ] . V_1 ;
} else {
if ( V_1 -> V_79 > 0 )
return - V_34 ;
V_78 = F_34 ( V_8 , V_26 , V_24 ,
V_1 -> V_66 ) ;
V_1 -> V_1 = V_78 -> V_1 ;
}
return 0 ;
}
static int F_39 ( struct V_38 * V_39 ,
struct V_63 * V_26 ,
struct V_80 * V_81 )
{
struct V_7 * V_8 = F_19 ( V_39 ) ;
struct V_62 V_78 ;
if ( V_81 -> V_79 != 0 )
return - V_34 ;
V_78 . V_1 = V_81 -> V_1 ;
V_78 . V_69 = 1 ;
V_78 . V_70 = 1 ;
F_36 ( V_8 , V_26 , V_81 -> V_64 , & V_78 , V_81 -> V_66 ) ;
V_81 -> V_82 = V_78 . V_69 ;
V_81 -> V_83 = V_78 . V_70 ;
if ( V_78 . V_1 != V_81 -> V_1 )
return - V_34 ;
V_78 . V_1 = V_81 -> V_1 ;
V_78 . V_69 = - 1 ;
V_78 . V_70 = - 1 ;
F_36 ( V_8 , V_26 , V_81 -> V_64 , & V_78 , V_81 -> V_66 ) ;
V_81 -> V_84 = V_78 . V_69 ;
V_81 -> V_85 = V_78 . V_70 ;
return 0 ;
}
static int F_40 ( struct V_38 * V_39 ,
struct V_63 * V_26 ,
struct V_86 * V_23 )
{
struct V_7 * V_8 = F_19 ( V_39 ) ;
struct V_62 * V_78 ;
V_78 = F_34 ( V_8 , V_26 , V_23 -> V_64 , V_23 -> V_66 ) ;
if ( V_78 == NULL )
return - V_34 ;
V_23 -> V_78 = * V_78 ;
return 0 ;
}
static int F_41 ( struct V_38 * V_39 ,
struct V_63 * V_26 ,
struct V_86 * V_23 )
{
struct V_7 * V_8 = F_19 ( V_39 ) ;
struct V_62 * V_78 ;
V_78 = F_34 ( V_8 , V_26 , V_23 -> V_64 , V_23 -> V_66 ) ;
if ( V_78 == NULL )
return - V_34 ;
F_36 ( V_8 , V_26 , V_23 -> V_64 , & V_23 -> V_78 , V_23 -> V_66 ) ;
* V_78 = V_23 -> V_78 ;
if ( V_23 -> V_64 == V_24 ) {
V_78 = F_34 ( V_8 , V_26 , V_75 ,
V_23 -> V_66 ) ;
* V_78 = V_23 -> V_78 ;
F_36 ( V_8 , V_26 , V_75 , V_78 ,
V_23 -> V_66 ) ;
}
return 0 ;
}
static int F_42 ( struct V_38 * V_39 ,
struct V_87 * V_88 )
{
struct V_86 V_78 = {
. V_64 = V_24 ,
. V_66 = V_88 ? V_67 :
V_89 ,
. V_78 = {
. V_1 = V_68 ,
. V_69 = 1920 ,
. V_70 = 1080
}
} ;
return F_41 ( V_39 , V_88 ? V_88 -> V_64 : NULL , & V_78 ) ;
}
int F_43 ( struct V_7 * V_8 ,
const struct V_90 * V_91 , T_1 V_14 )
{
struct V_13 * V_6 = F_10 ( V_8 , V_14 ) ;
struct V_92 * V_93 = F_44 ( V_6 ) ;
struct V_94 * V_95 ;
int V_2 , V_16 ;
int V_17 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_26 . V_56 = 0 ;
V_95 = F_45 ( V_93 , V_96 , V_91 -> V_97 [ 0 ] ) ;
V_8 -> V_10 = F_46 ( V_6 , V_95 ) ;
if ( F_47 ( V_8 -> V_10 ) ) {
F_13 ( V_6 , L_10 ) ;
return F_48 ( V_8 -> V_10 ) ;
}
V_95 = F_45 ( V_93 , V_96 , V_91 -> V_97 [ 1 ] ) ;
V_8 -> V_55 = F_46 ( V_6 , V_95 ) ;
if ( F_47 ( V_8 -> V_55 ) ) {
F_13 ( V_6 , L_10 ) ;
return F_48 ( V_8 -> V_55 ) ;
}
V_95 = F_45 ( V_93 , V_98 ,
V_91 -> V_99 [ 0 ] ) ;
if ( ! V_95 ) {
F_13 ( V_6 , L_11 ) ;
return - V_34 ;
}
V_8 -> V_5 = V_95 -> V_100 ;
snprintf ( V_8 -> V_101 , sizeof( V_8 -> V_101 ) , L_12 ,
F_49 ( V_6 ) , V_102 , V_8 -> V_14 ) ;
V_17 = F_50 ( V_6 , V_8 -> V_5 , F_4 ,
V_103 , V_8 -> V_101 , V_8 ) ;
if ( V_17 < 0 ) {
F_13 ( V_6 , L_13 , V_17 ) ;
return V_17 ;
}
F_23 ( V_8 -> V_5 ) ;
V_8 -> V_20 = 0 ;
while ( V_91 -> clock [ V_8 -> V_20 ] )
V_8 -> V_20 ++ ;
V_8 -> clock = F_51 ( V_6 , V_8 -> V_20 *
sizeof( * V_8 -> clock ) , V_104 ) ;
if ( ! V_8 -> clock )
return - V_105 ;
for ( V_2 = 0 ; V_2 < V_8 -> V_20 ; V_2 ++ ) {
struct V_21 * clock = & V_8 -> clock [ V_2 ] ;
clock -> V_35 = F_52 ( V_6 , V_91 -> clock [ V_2 ] ) ;
if ( F_47 ( clock -> V_35 ) )
return F_48 ( clock -> V_35 ) ;
clock -> V_22 = V_91 -> clock [ V_2 ] ;
clock -> V_32 = 0 ;
while ( V_91 -> V_106 [ V_2 ] [ clock -> V_32 ] )
clock -> V_32 ++ ;
if ( ! clock -> V_32 ) {
clock -> V_33 = NULL ;
continue;
}
clock -> V_33 = F_51 ( V_6 , clock -> V_32 *
sizeof( * clock -> V_33 ) , V_104 ) ;
if ( ! clock -> V_33 )
return - V_105 ;
for ( V_16 = 0 ; V_16 < clock -> V_32 ; V_16 ++ )
clock -> V_33 [ V_16 ] = V_91 -> V_106 [ V_2 ] [ V_16 ] ;
}
return 0 ;
}
static int F_53 ( struct V_107 * V_19 ,
const struct V_108 * V_109 ,
const struct V_108 * V_110 , T_2 V_111 )
{
if ( ( V_109 -> V_111 & V_112 ) &&
( V_111 & V_113 ) ) {
struct V_38 * V_39 ;
struct V_7 * V_8 ;
struct V_114 * V_115 ;
if ( F_54 ( V_109 ) )
return - V_116 ;
V_39 = F_55 ( V_19 ) ;
V_8 = F_19 ( V_39 ) ;
V_39 = F_55 ( V_110 -> V_19 ) ;
V_115 = F_19 ( V_39 ) ;
V_8 -> V_26 . V_57 = V_115 -> V_14 ;
}
return 0 ;
}
int F_56 ( struct V_7 * V_8 ,
struct V_117 * V_118 )
{
struct V_38 * V_39 = & V_8 -> V_18 ;
struct V_108 * V_119 = V_8 -> V_119 ;
struct V_13 * V_6 = F_10 ( V_8 , V_8 -> V_14 ) ;
int V_17 ;
F_57 ( V_39 , & V_120 ) ;
V_39 -> V_121 = & V_122 ;
V_39 -> V_111 |= V_123 ;
snprintf ( V_39 -> V_22 , F_2 ( V_39 -> V_22 ) , L_14 ,
V_102 , V_8 -> V_14 ) ;
F_58 ( V_39 , V_8 ) ;
V_17 = F_42 ( V_39 , NULL ) ;
if ( V_17 < 0 ) {
F_13 ( V_6 , L_15 , V_17 ) ;
return V_17 ;
}
V_119 [ V_24 ] . V_111 = V_124 ;
V_119 [ V_75 ] . V_111 = V_112 ;
V_39 -> V_19 . V_125 = V_126 ;
V_39 -> V_19 . V_127 = & V_128 ;
V_17 = F_59 ( & V_39 -> V_19 , V_129 , V_119 ) ;
if ( V_17 < 0 ) {
F_13 ( V_6 , L_16 , V_17 ) ;
return V_17 ;
}
V_17 = F_60 ( V_118 , V_39 ) ;
if ( V_17 < 0 ) {
F_13 ( V_6 , L_17 , V_17 ) ;
F_61 ( & V_39 -> V_19 ) ;
}
return V_17 ;
}
void F_62 ( struct V_7 * V_8 )
{
F_63 ( & V_8 -> V_18 ) ;
F_61 ( & V_8 -> V_18 . V_19 ) ;
}
