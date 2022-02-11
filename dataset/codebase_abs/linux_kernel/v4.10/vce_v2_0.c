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
static int F_11 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_20 ;
F_12 ( V_4 ) ;
F_10 ( V_16 , 1 , ~ 1 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
F_5 ( V_6 , V_2 -> V_10 ) ;
F_5 ( V_8 , V_2 -> V_10 ) ;
F_5 ( V_21 , V_2 -> V_22 ) ;
F_5 ( V_23 , F_13 ( V_2 -> V_22 ) ) ;
F_5 ( V_24 , V_2 -> V_25 / 4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
F_5 ( V_7 , V_2 -> V_10 ) ;
F_5 ( V_9 , V_2 -> V_10 ) ;
F_5 ( V_26 , V_2 -> V_22 ) ;
F_5 ( V_27 , F_13 ( V_2 -> V_22 ) ) ;
F_5 ( V_28 , V_2 -> V_25 / 4 ) ;
F_14 ( V_29 , V_30 , 1 ) ;
F_14 ( V_31 , V_32 , 1 ) ;
F_7 ( 100 ) ;
F_14 ( V_31 , V_32 , 0 ) ;
V_20 = F_8 ( V_4 ) ;
F_10 ( V_16 , 0 , ~ 1 ) ;
if ( V_20 ) {
F_9 ( L_2 ) ;
return V_20 ;
}
return 0 ;
}
static int F_15 ( void * V_33 )
{
struct V_3 * V_4 = (struct V_3 * ) V_33 ;
V_4 -> V_5 . V_34 = 2 ;
F_16 ( V_4 ) ;
F_17 ( V_4 ) ;
return 0 ;
}
static int F_18 ( void * V_33 )
{
struct V_1 * V_2 ;
int V_20 , V_11 ;
struct V_3 * V_4 = (struct V_3 * ) V_33 ;
V_20 = F_19 ( V_4 , 167 , & V_4 -> V_5 . V_35 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_20 ( V_4 , V_36 +
V_37 + V_38 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_21 ( V_4 ) ;
if ( V_20 )
return V_20 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_5 . V_34 ; V_11 ++ ) {
V_2 = & V_4 -> V_5 . V_2 [ V_11 ] ;
sprintf ( V_2 -> V_39 , L_3 , V_11 ) ;
V_20 = F_22 ( V_4 , V_2 , 512 ,
& V_4 -> V_5 . V_35 , 0 ) ;
if ( V_20 )
return V_20 ;
}
return V_20 ;
}
static int F_23 ( void * V_33 )
{
int V_20 ;
struct V_3 * V_4 = (struct V_3 * ) V_33 ;
V_20 = F_24 ( V_4 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_25 ( V_4 ) ;
if ( V_20 )
return V_20 ;
return V_20 ;
}
static int F_26 ( void * V_33 )
{
int V_20 , V_11 ;
struct V_3 * V_4 = (struct V_3 * ) V_33 ;
V_20 = F_11 ( V_4 ) ;
if ( V_20 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_5 . V_34 ; V_11 ++ )
V_4 -> V_5 . V_2 [ V_11 ] . V_40 = false ;
for ( V_11 = 0 ; V_11 < V_4 -> V_5 . V_34 ; V_11 ++ ) {
V_20 = F_27 ( & V_4 -> V_5 . V_2 [ V_11 ] ) ;
if ( V_20 )
return V_20 ;
else
V_4 -> V_5 . V_2 [ V_11 ] . V_40 = true ;
}
F_28 ( L_4 ) ;
return 0 ;
}
static int F_29 ( void * V_33 )
{
return 0 ;
}
static int F_30 ( void * V_33 )
{
int V_20 ;
struct V_3 * V_4 = (struct V_3 * ) V_33 ;
V_20 = F_29 ( V_4 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_24 ( V_4 ) ;
if ( V_20 )
return V_20 ;
return V_20 ;
}
static int F_31 ( void * V_33 )
{
int V_20 ;
struct V_3 * V_4 = (struct V_3 * ) V_33 ;
V_20 = F_21 ( V_4 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_26 ( V_4 ) ;
if ( V_20 )
return V_20 ;
return V_20 ;
}
static void F_32 ( struct V_3 * V_4 , bool V_41 )
{
T_2 V_42 ;
if ( V_41 ) {
V_42 = F_2 ( V_43 ) ;
V_42 |= 0xe70000 ;
F_5 ( V_43 , V_42 ) ;
V_42 = F_2 ( V_44 ) ;
V_42 |= 0xff000000 ;
F_5 ( V_44 , V_42 ) ;
V_42 = F_2 ( V_45 ) ;
V_42 &= ~ 0x3fc ;
F_5 ( V_45 , V_42 ) ;
F_5 ( V_46 , 0 ) ;
} else {
V_42 = F_2 ( V_43 ) ;
V_42 |= 0xe7 ;
V_42 &= ~ 0xe70000 ;
F_5 ( V_43 , V_42 ) ;
V_42 = F_2 ( V_44 ) ;
V_42 |= 0x1fe000 ;
V_42 &= ~ 0xff000000 ;
F_5 ( V_44 , V_42 ) ;
V_42 = F_2 ( V_45 ) ;
V_42 |= 0x3fc ;
F_5 ( V_45 , V_42 ) ;
}
}
static void F_33 ( struct V_3 * V_4 , bool V_41 )
{
if ( F_34 ( V_4 ) ) {
F_28 ( L_5 ) ;
return;
}
F_10 ( V_47 , 0x100 , ~ 0x100 ) ;
if ( F_6 ( V_4 ) ) {
F_28 ( L_6 ) ;
return;
}
F_10 ( V_48 , 0 , ~ V_49 ) ;
F_10 ( V_18 ,
V_19 ,
~ V_19 ) ;
F_5 ( V_16 , 0 ) ;
if ( V_41 )
F_5 ( V_46 , 0 ) ;
if ( V_41 ) {
F_5 ( V_43 , 0xe90010 ) ;
} else {
F_5 ( V_43 , 0x800f1 ) ;
}
;
F_5 ( V_44 , 0x40 ) ;
F_5 ( V_45 , 0x00 ) ;
F_10 ( V_47 , 0 , ~ 0x100 ) ;
if( ! V_41 ) {
F_10 ( V_48 , V_49 , ~ V_49 ) ;
F_7 ( 100 ) ;
F_10 ( V_18 , 0 , ~ V_19 ) ;
F_8 ( V_4 ) ;
F_10 ( V_16 , 0 , ~ V_50 ) ;
}
}
static void F_35 ( struct V_3 * V_4 )
{
F_5 ( V_46 , 7 ) ;
}
static void F_36 ( struct V_3 * V_4 , bool V_51 )
{
bool V_52 = false ;
if ( V_51 && ( V_4 -> V_53 & V_54 ) ) {
if ( V_52 )
F_32 ( V_4 , true ) ;
else
F_33 ( V_4 , true ) ;
} else {
F_35 ( V_4 ) ;
if ( V_52 )
F_32 ( V_4 , false ) ;
else
F_33 ( V_4 , false ) ;
}
}
static void F_37 ( struct V_3 * V_4 )
{
T_2 V_42 ;
V_42 = F_2 ( V_55 ) ;
V_42 &= ~ 0xfff ;
V_42 |= ( ( 0 << 0 ) | ( 4 << 4 ) ) ;
V_42 |= 0x40000 ;
F_5 ( V_55 , V_42 ) ;
V_42 = F_2 ( V_44 ) ;
V_42 &= ~ 0xfff ;
V_42 |= ( ( 0 << 0 ) | ( 4 << 4 ) ) ;
F_5 ( V_44 , V_42 ) ;
V_42 = F_2 ( V_43 ) ;
V_42 |= 0x10 ;
V_42 &= ~ 0x100000 ;
F_5 ( V_43 , V_42 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
T_3 V_56 = V_4 -> V_5 . V_22 ;
T_1 V_57 ;
F_10 ( V_55 , 0 , ~ ( 1 << 16 ) ) ;
F_10 ( V_44 , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_10 ( V_45 , 0x3F , ~ 0x3F ) ;
F_5 ( V_43 , 0xf7 ) ;
F_5 ( V_58 , 0x00398000 ) ;
F_10 ( V_59 , 0x0 , ~ 0x1 ) ;
F_5 ( V_60 , 0 ) ;
F_5 ( V_61 , 0 ) ;
F_5 ( V_62 , 0 ) ;
V_56 += V_63 ;
V_57 = V_36 ;
F_5 ( V_64 , V_56 & 0x7fffffff ) ;
F_5 ( V_65 , V_57 ) ;
V_56 += V_57 ;
V_57 = V_37 ;
F_5 ( V_66 , V_56 & 0x7fffffff ) ;
F_5 ( V_67 , V_57 ) ;
V_56 += V_57 ;
V_57 = V_38 ;
F_5 ( V_68 , V_56 & 0x7fffffff ) ;
F_5 ( V_69 , V_57 ) ;
F_10 ( V_47 , 0x0 , ~ 0x100 ) ;
F_14 ( V_70 , V_71 , 1 ) ;
F_37 ( V_4 ) ;
}
static bool F_38 ( void * V_33 )
{
struct V_3 * V_4 = (struct V_3 * ) V_33 ;
return ! ( F_2 ( V_72 ) & V_73 ) ;
}
static int F_34 ( void * V_33 )
{
struct V_3 * V_4 = (struct V_3 * ) V_33 ;
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_74 ; V_11 ++ ) {
if ( F_38 ( V_33 ) )
return 0 ;
}
return - V_15 ;
}
static int F_39 ( void * V_33 )
{
struct V_3 * V_4 = (struct V_3 * ) V_33 ;
F_14 ( V_75 , V_76 , 1 ) ;
F_7 ( 5 ) ;
return F_11 ( V_4 ) ;
}
static int F_40 ( struct V_3 * V_4 ,
struct V_77 * V_78 ,
unsigned type ,
enum V_79 V_80 )
{
T_1 V_81 = 0 ;
if ( V_80 == V_82 )
V_81 |= V_83 ;
F_10 ( V_84 , V_81 , ~ V_83 ) ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 ,
struct V_77 * V_78 ,
struct V_85 * V_86 )
{
F_42 ( L_7 ) ;
switch ( V_86 -> V_87 ) {
case 0 :
case 1 :
F_43 ( & V_4 -> V_5 . V_2 [ V_86 -> V_87 ] ) ;
break;
default:
F_9 ( L_8 ,
V_86 -> V_88 , V_86 -> V_87 ) ;
break;
}
return 0 ;
}
static void F_44 ( struct V_3 * V_4 , bool V_51 )
{
T_2 V_42 = F_45 ( V_89 ) ;
if ( V_51 )
V_42 |= V_90 ;
else
V_42 &= ~ V_90 ;
F_46 ( V_89 , V_42 ) ;
}
static int F_47 ( void * V_33 ,
enum V_91 V_80 )
{
bool V_92 = false ;
struct V_3 * V_4 = (struct V_3 * ) V_33 ;
bool V_51 = ( V_80 == V_93 ) ? true : false ;
F_44 ( V_4 , V_51 ) ;
if ( V_80 == V_93 )
V_92 = true ;
F_36 ( V_4 , V_92 ) ;
return 0 ;
}
static int F_48 ( void * V_33 ,
enum V_94 V_80 )
{
struct V_3 * V_4 = (struct V_3 * ) V_33 ;
if ( ! ( V_4 -> V_95 & V_96 ) )
return 0 ;
if ( V_80 == V_97 )
return 0 ;
else
return F_11 ( V_4 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_5 . V_34 ; V_11 ++ )
V_4 -> V_5 . V_2 [ V_11 ] . V_98 = & V_99 ;
}
static void F_17 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_35 . V_100 = 1 ;
V_4 -> V_5 . V_35 . V_98 = & V_101 ;
}
