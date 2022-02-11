static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 == & V_4 -> V_5 . V_2 [ 0 ] )
return F_2 ( V_6 ) ;
else
return F_2 ( V_7 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 == & V_4 -> V_5 . V_2 [ 0 ] )
return F_2 ( V_8 ) ;
else
return F_2 ( V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 == & V_4 -> V_5 . V_2 [ 0 ] )
F_5 ( V_8 , V_2 -> V_10 ) ;
else
F_5 ( V_9 , V_2 -> V_10 ) ;
}
static int F_6 ( struct V_3 * V_4 )
{
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < 10 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < 100 ; ++ V_12 ) {
T_1 V_13 = F_2 ( V_14 ) ;
if ( V_13 & 0x337f )
return 0 ;
F_7 ( 10 ) ;
}
}
return - V_15 ;
}
static int F_8 ( struct V_3 * V_4 )
{
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < 10 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < 100 ; ++ V_12 ) {
T_1 V_13 = F_2 ( V_16 ) ;
if ( V_13 & V_17 )
return 0 ;
F_7 ( 10 ) ;
}
F_9 ( L_1 ) ;
F_10 ( V_18 ,
V_19 ,
~ V_19 ) ;
F_7 ( 10 ) ;
F_10 ( V_18 , 0 ,
~ V_19 ) ;
F_7 ( 10 ) ;
}
return - V_15 ;
}
static void F_11 ( struct V_3 * V_4 )
{
F_5 ( V_20 , 7 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
T_2 V_21 ;
V_21 = F_2 ( V_22 ) ;
V_21 &= ~ 0xfff ;
V_21 |= ( ( 0 << 0 ) | ( 4 << 4 ) ) ;
V_21 |= 0x40000 ;
F_5 ( V_22 , V_21 ) ;
V_21 = F_2 ( V_23 ) ;
V_21 &= ~ 0xfff ;
V_21 |= ( ( 0 << 0 ) | ( 4 << 4 ) ) ;
F_5 ( V_23 , V_21 ) ;
V_21 = F_2 ( V_24 ) ;
V_21 |= 0x10 ;
V_21 &= ~ 0x100000 ;
F_5 ( V_24 , V_21 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
T_3 V_25 = V_4 -> V_5 . V_26 ;
T_1 V_27 ;
F_10 ( V_22 , 0 , ~ ( 1 << 16 ) ) ;
F_10 ( V_23 , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_10 ( V_28 , 0x3F , ~ 0x3F ) ;
F_5 ( V_24 , 0xf7 ) ;
F_5 ( V_29 , 0x00398000 ) ;
F_10 ( V_30 , 0x0 , ~ 0x1 ) ;
F_5 ( V_31 , 0 ) ;
F_5 ( V_32 , 0 ) ;
F_5 ( V_33 , 0 ) ;
V_25 += V_34 ;
V_27 = V_35 ;
F_5 ( V_36 , V_25 & 0x7fffffff ) ;
F_5 ( V_37 , V_27 ) ;
V_25 += V_27 ;
V_27 = V_38 ;
F_5 ( V_39 , V_25 & 0x7fffffff ) ;
F_5 ( V_40 , V_27 ) ;
V_25 += V_27 ;
V_27 = V_41 ;
F_5 ( V_42 , V_25 & 0x7fffffff ) ;
F_5 ( V_43 , V_27 ) ;
F_10 ( V_44 , 0x0 , ~ 0x100 ) ;
F_14 ( V_45 , V_46 , 1 ) ;
}
static bool F_15 ( void * V_47 )
{
struct V_3 * V_4 = (struct V_3 * ) V_47 ;
return ! ( F_2 ( V_48 ) & V_49 ) ;
}
static int F_16 ( void * V_47 )
{
struct V_3 * V_4 = (struct V_3 * ) V_47 ;
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_50 ; V_11 ++ ) {
if ( F_15 ( V_47 ) )
return 0 ;
}
return - V_15 ;
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_51 ;
F_10 ( V_16 , 1 , ~ 1 ) ;
F_12 ( V_4 ) ;
F_11 ( V_4 ) ;
F_13 ( V_4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
F_5 ( V_6 , V_2 -> V_10 ) ;
F_5 ( V_8 , V_2 -> V_10 ) ;
F_5 ( V_52 , V_2 -> V_26 ) ;
F_5 ( V_53 , F_18 ( V_2 -> V_26 ) ) ;
F_5 ( V_54 , V_2 -> V_55 / 4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
F_5 ( V_7 , V_2 -> V_10 ) ;
F_5 ( V_9 , V_2 -> V_10 ) ;
F_5 ( V_56 , V_2 -> V_26 ) ;
F_5 ( V_57 , F_18 ( V_2 -> V_26 ) ) ;
F_5 ( V_58 , V_2 -> V_55 / 4 ) ;
F_14 ( V_59 , V_60 , 1 ) ;
F_14 ( V_61 , V_62 , 1 ) ;
F_7 ( 100 ) ;
F_14 ( V_61 , V_62 , 0 ) ;
V_51 = F_8 ( V_4 ) ;
F_10 ( V_16 , 0 , ~ 1 ) ;
if ( V_51 ) {
F_9 ( L_2 ) ;
return V_51 ;
}
return 0 ;
}
static int F_19 ( struct V_3 * V_4 )
{
int V_11 , V_12 ;
int V_13 ;
if ( F_6 ( V_4 ) ) {
F_20 ( L_3 ) ;
return 0 ;
}
if ( F_16 ( V_4 ) ) {
F_20 ( L_4 ) ;
return 0 ;
}
F_10 ( V_44 , 1 << 8 , ~ ( 1 << 8 ) ) ;
for ( V_11 = 0 ; V_11 < 10 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < 100 ; ++ V_12 ) {
V_13 = F_2 ( V_14 ) ;
if ( V_13 & 0x240 )
break;
F_7 ( 1 ) ;
}
break;
}
F_10 ( V_63 , 0 , ~ 0x80001 ) ;
F_10 ( V_18 , 1 , ~ 0x1 ) ;
F_5 ( V_16 , 0 ) ;
return 0 ;
}
static void F_21 ( struct V_3 * V_4 , bool V_64 )
{
T_2 V_21 ;
if ( V_64 ) {
V_21 = F_2 ( V_24 ) ;
V_21 |= 0xe70000 ;
F_5 ( V_24 , V_21 ) ;
V_21 = F_2 ( V_23 ) ;
V_21 |= 0xff000000 ;
F_5 ( V_23 , V_21 ) ;
V_21 = F_2 ( V_28 ) ;
V_21 &= ~ 0x3fc ;
F_5 ( V_28 , V_21 ) ;
F_5 ( V_20 , 0 ) ;
} else {
V_21 = F_2 ( V_24 ) ;
V_21 |= 0xe7 ;
V_21 &= ~ 0xe70000 ;
F_5 ( V_24 , V_21 ) ;
V_21 = F_2 ( V_23 ) ;
V_21 |= 0x1fe000 ;
V_21 &= ~ 0xff000000 ;
F_5 ( V_23 , V_21 ) ;
V_21 = F_2 ( V_28 ) ;
V_21 |= 0x3fc ;
F_5 ( V_28 , V_21 ) ;
}
}
static void F_22 ( struct V_3 * V_4 , bool V_64 )
{
T_2 V_65 , V_21 ;
V_21 = F_2 ( V_24 ) ;
V_21 &= ~ 0x00060006 ;
if ( V_64 ) {
V_21 |= 0xe10000 ;
F_5 ( V_24 , V_21 ) ;
} else {
V_21 |= 0xe1 ;
V_21 &= ~ 0xe10000 ;
F_5 ( V_24 , V_21 ) ;
}
V_65 = V_21 = F_2 ( V_23 ) ;
V_21 &= ~ 0x1fe000 ;
V_21 &= ~ 0xff000000 ;
if ( V_21 != V_65 )
F_5 ( V_23 , V_21 ) ;
V_65 = V_21 = F_2 ( V_28 ) ;
V_21 &= ~ 0x3fc ;
if ( V_21 != V_65 )
F_5 ( V_28 , V_21 ) ;
F_5 ( V_28 , 0x00 ) ;
if( V_64 )
F_5 ( V_20 , 0 ) ;
}
static void F_23 ( struct V_3 * V_4 , bool V_66 ,
bool V_67 )
{
if ( V_66 && ( V_4 -> V_68 & V_69 ) ) {
if ( V_67 )
F_21 ( V_4 , true ) ;
else
F_22 ( V_4 , true ) ;
} else {
F_11 ( V_4 ) ;
if ( V_67 )
F_21 ( V_4 , false ) ;
else
F_22 ( V_4 , false ) ;
}
}
static int F_24 ( void * V_47 )
{
struct V_3 * V_4 = (struct V_3 * ) V_47 ;
V_4 -> V_5 . V_70 = 2 ;
F_25 ( V_4 ) ;
F_26 ( V_4 ) ;
return 0 ;
}
static int F_27 ( void * V_47 )
{
struct V_1 * V_2 ;
int V_51 , V_11 ;
struct V_3 * V_4 = (struct V_3 * ) V_47 ;
V_51 = F_28 ( V_4 , 167 , & V_4 -> V_5 . V_71 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_29 ( V_4 , V_35 +
V_38 + V_41 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_30 ( V_4 ) ;
if ( V_51 )
return V_51 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_5 . V_70 ; V_11 ++ ) {
V_2 = & V_4 -> V_5 . V_2 [ V_11 ] ;
sprintf ( V_2 -> V_72 , L_5 , V_11 ) ;
V_51 = F_31 ( V_4 , V_2 , 512 ,
& V_4 -> V_5 . V_71 , 0 ) ;
if ( V_51 )
return V_51 ;
}
return V_51 ;
}
static int F_32 ( void * V_47 )
{
int V_51 ;
struct V_3 * V_4 = (struct V_3 * ) V_47 ;
V_51 = F_33 ( V_4 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_34 ( V_4 ) ;
if ( V_51 )
return V_51 ;
return V_51 ;
}
static int F_35 ( void * V_47 )
{
int V_51 , V_11 ;
struct V_3 * V_4 = (struct V_3 * ) V_47 ;
F_36 ( V_4 , 10000 , 10000 ) ;
F_23 ( V_4 , true , false ) ;
for ( V_11 = 0 ; V_11 < V_4 -> V_5 . V_70 ; V_11 ++ )
V_4 -> V_5 . V_2 [ V_11 ] . V_73 = false ;
for ( V_11 = 0 ; V_11 < V_4 -> V_5 . V_70 ; V_11 ++ ) {
V_51 = F_37 ( & V_4 -> V_5 . V_2 [ V_11 ] ) ;
if ( V_51 )
return V_51 ;
else
V_4 -> V_5 . V_2 [ V_11 ] . V_73 = true ;
}
F_20 ( L_6 ) ;
return 0 ;
}
static int F_38 ( void * V_47 )
{
return 0 ;
}
static int F_39 ( void * V_47 )
{
int V_51 ;
struct V_3 * V_4 = (struct V_3 * ) V_47 ;
V_51 = F_38 ( V_4 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_33 ( V_4 ) ;
if ( V_51 )
return V_51 ;
return V_51 ;
}
static int F_40 ( void * V_47 )
{
int V_51 ;
struct V_3 * V_4 = (struct V_3 * ) V_47 ;
V_51 = F_30 ( V_4 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_35 ( V_4 ) ;
if ( V_51 )
return V_51 ;
return V_51 ;
}
static int F_41 ( void * V_47 )
{
struct V_3 * V_4 = (struct V_3 * ) V_47 ;
F_14 ( V_74 , V_75 , 1 ) ;
F_7 ( 5 ) ;
return F_17 ( V_4 ) ;
}
static int F_42 ( struct V_3 * V_4 ,
struct V_76 * V_77 ,
unsigned type ,
enum V_78 V_79 )
{
T_1 V_80 = 0 ;
if ( V_79 == V_81 )
V_80 |= V_82 ;
F_10 ( V_83 , V_80 , ~ V_82 ) ;
return 0 ;
}
static int F_43 ( struct V_3 * V_4 ,
struct V_76 * V_77 ,
struct V_84 * V_85 )
{
F_44 ( L_7 ) ;
switch ( V_85 -> V_86 ) {
case 0 :
case 1 :
F_45 ( & V_4 -> V_5 . V_2 [ V_85 -> V_86 ] ) ;
break;
default:
F_9 ( L_8 ,
V_85 -> V_87 , V_85 -> V_86 ) ;
break;
}
return 0 ;
}
static int F_46 ( void * V_47 ,
enum V_88 V_79 )
{
bool V_89 = false ;
bool V_67 = false ;
struct V_3 * V_4 = (struct V_3 * ) V_47 ;
if ( V_79 == V_90 ) {
V_89 = true ;
V_67 = true ;
}
F_23 ( V_4 , V_89 , V_67 ) ;
return 0 ;
}
static int F_47 ( void * V_47 ,
enum V_91 V_79 )
{
struct V_3 * V_4 = (struct V_3 * ) V_47 ;
if ( V_79 == V_92 )
return F_19 ( V_4 ) ;
else
return F_17 ( V_4 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_5 . V_70 ; V_11 ++ )
V_4 -> V_5 . V_2 [ V_11 ] . V_93 = & V_94 ;
}
static void F_26 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_71 . V_95 = 1 ;
V_4 -> V_5 . V_71 . V_93 = & V_96 ;
}
