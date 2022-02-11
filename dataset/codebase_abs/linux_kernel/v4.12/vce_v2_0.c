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
F_5 ( V_8 , F_6 ( V_2 -> V_10 ) ) ;
else
F_5 ( V_9 , F_6 ( V_2 -> V_10 ) ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < 10 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < 100 ; ++ V_12 ) {
T_2 V_13 = F_2 ( V_14 ) ;
if ( V_13 & 0x337f )
return 0 ;
F_8 ( 10 ) ;
}
}
return - V_15 ;
}
static int F_9 ( struct V_3 * V_4 )
{
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < 10 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < 100 ; ++ V_12 ) {
T_2 V_13 = F_2 ( V_16 ) ;
if ( V_13 & V_17 )
return 0 ;
F_8 ( 10 ) ;
}
F_10 ( L_1 ) ;
F_11 ( V_18 ,
V_19 ,
~ V_19 ) ;
F_8 ( 10 ) ;
F_11 ( V_18 , 0 ,
~ V_19 ) ;
F_8 ( 10 ) ;
}
return - V_15 ;
}
static void F_12 ( struct V_3 * V_4 )
{
F_5 ( V_20 , 7 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
T_3 V_21 ;
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
static void F_14 ( struct V_3 * V_4 )
{
T_2 V_25 , V_26 ;
F_11 ( V_22 , 0 , ~ ( 1 << 16 ) ) ;
F_11 ( V_23 , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_11 ( V_27 , 0x3F , ~ 0x3F ) ;
F_5 ( V_24 , 0xf7 ) ;
F_5 ( V_28 , 0x00398000 ) ;
F_11 ( V_29 , 0x0 , ~ 0x1 ) ;
F_5 ( V_30 , 0 ) ;
F_5 ( V_31 , 0 ) ;
F_5 ( V_32 , 0 ) ;
F_5 ( V_33 , ( V_4 -> V_5 . V_34 >> 8 ) ) ;
V_26 = V_35 ;
V_25 = V_36 ;
F_5 ( V_37 , V_26 & 0x7fffffff ) ;
F_5 ( V_38 , V_25 ) ;
V_26 += V_25 ;
V_25 = V_39 ;
F_5 ( V_40 , V_26 & 0x7fffffff ) ;
F_5 ( V_41 , V_25 ) ;
V_26 += V_25 ;
V_25 = V_42 ;
F_5 ( V_43 , V_26 & 0x7fffffff ) ;
F_5 ( V_44 , V_25 ) ;
F_11 ( V_45 , 0x0 , ~ 0x100 ) ;
F_15 ( V_46 , V_47 , 1 ) ;
}
static bool F_16 ( void * V_48 )
{
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
return ! ( F_2 ( V_49 ) & V_50 ) ;
}
static int F_17 ( void * V_48 )
{
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_51 ; V_11 ++ ) {
if ( F_16 ( V_48 ) )
return 0 ;
}
return - V_15 ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_52 ;
F_11 ( V_16 , 1 , ~ 1 ) ;
F_13 ( V_4 ) ;
F_12 ( V_4 ) ;
F_14 ( V_4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
F_5 ( V_6 , F_6 ( V_2 -> V_10 ) ) ;
F_5 ( V_8 , F_6 ( V_2 -> V_10 ) ) ;
F_5 ( V_53 , V_2 -> V_34 ) ;
F_5 ( V_54 , F_19 ( V_2 -> V_34 ) ) ;
F_5 ( V_55 , V_2 -> V_56 / 4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
F_5 ( V_7 , F_6 ( V_2 -> V_10 ) ) ;
F_5 ( V_9 , F_6 ( V_2 -> V_10 ) ) ;
F_5 ( V_57 , V_2 -> V_34 ) ;
F_5 ( V_58 , F_19 ( V_2 -> V_34 ) ) ;
F_5 ( V_59 , V_2 -> V_56 / 4 ) ;
F_15 ( V_60 , V_61 , 1 ) ;
F_15 ( V_62 , V_63 , 1 ) ;
F_8 ( 100 ) ;
F_15 ( V_62 , V_63 , 0 ) ;
V_52 = F_9 ( V_4 ) ;
F_11 ( V_16 , 0 , ~ 1 ) ;
if ( V_52 ) {
F_10 ( L_2 ) ;
return V_52 ;
}
return 0 ;
}
static int F_20 ( struct V_3 * V_4 )
{
int V_11 ;
int V_13 ;
if ( F_7 ( V_4 ) ) {
F_21 ( L_3 ) ;
return 0 ;
}
if ( F_17 ( V_4 ) ) {
F_21 ( L_4 ) ;
return 0 ;
}
F_11 ( V_45 , 1 << 8 , ~ ( 1 << 8 ) ) ;
for ( V_11 = 0 ; V_11 < 100 ; ++ V_11 ) {
V_13 = F_2 ( V_14 ) ;
if ( V_13 & 0x240 )
break;
F_8 ( 1 ) ;
}
F_11 ( V_64 , 0 , ~ 0x80001 ) ;
F_11 ( V_18 , 1 , ~ 0x1 ) ;
F_5 ( V_16 , 0 ) ;
return 0 ;
}
static void F_22 ( struct V_3 * V_4 , bool V_65 )
{
T_3 V_21 ;
if ( V_65 ) {
V_21 = F_2 ( V_24 ) ;
V_21 |= 0xe70000 ;
F_5 ( V_24 , V_21 ) ;
V_21 = F_2 ( V_23 ) ;
V_21 |= 0xff000000 ;
F_5 ( V_23 , V_21 ) ;
V_21 = F_2 ( V_27 ) ;
V_21 &= ~ 0x3fc ;
F_5 ( V_27 , V_21 ) ;
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
V_21 = F_2 ( V_27 ) ;
V_21 |= 0x3fc ;
F_5 ( V_27 , V_21 ) ;
}
}
static void F_23 ( struct V_3 * V_4 , bool V_65 )
{
T_3 V_66 , V_21 ;
V_21 = F_2 ( V_24 ) ;
V_21 &= ~ 0x00060006 ;
if ( V_65 ) {
V_21 |= 0xe10000 ;
F_5 ( V_24 , V_21 ) ;
} else {
V_21 |= 0xe1 ;
V_21 &= ~ 0xe10000 ;
F_5 ( V_24 , V_21 ) ;
}
V_66 = V_21 = F_2 ( V_23 ) ;
V_21 &= ~ 0x1fe000 ;
V_21 &= ~ 0xff000000 ;
if ( V_21 != V_66 )
F_5 ( V_23 , V_21 ) ;
V_66 = V_21 = F_2 ( V_27 ) ;
V_21 &= ~ 0x3fc ;
if ( V_21 != V_66 )
F_5 ( V_27 , V_21 ) ;
F_5 ( V_27 , 0x00 ) ;
if( V_65 )
F_5 ( V_20 , 0 ) ;
}
static void F_24 ( struct V_3 * V_4 , bool V_67 ,
bool V_68 )
{
if ( V_67 && ( V_4 -> V_69 & V_70 ) ) {
if ( V_68 )
F_22 ( V_4 , true ) ;
else
F_23 ( V_4 , true ) ;
} else {
F_12 ( V_4 ) ;
if ( V_68 )
F_22 ( V_4 , false ) ;
else
F_23 ( V_4 , false ) ;
}
}
static int F_25 ( void * V_48 )
{
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
V_4 -> V_5 . V_71 = 2 ;
F_26 ( V_4 ) ;
F_27 ( V_4 ) ;
return 0 ;
}
static int F_28 ( void * V_48 )
{
struct V_1 * V_2 ;
int V_52 , V_11 ;
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
V_52 = F_29 ( V_4 , V_72 , 167 , & V_4 -> V_5 . V_73 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_30 ( V_4 , V_36 +
V_39 + V_42 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_31 ( V_4 ) ;
if ( V_52 )
return V_52 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_5 . V_71 ; V_11 ++ ) {
V_2 = & V_4 -> V_5 . V_2 [ V_11 ] ;
sprintf ( V_2 -> V_74 , L_5 , V_11 ) ;
V_52 = F_32 ( V_4 , V_2 , 512 ,
& V_4 -> V_5 . V_73 , 0 ) ;
if ( V_52 )
return V_52 ;
}
return V_52 ;
}
static int F_33 ( void * V_48 )
{
int V_52 ;
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
V_52 = F_34 ( V_4 ) ;
if ( V_52 )
return V_52 ;
return F_35 ( V_4 ) ;
}
static int F_36 ( void * V_48 )
{
int V_52 , V_11 ;
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
F_37 ( V_4 , 10000 , 10000 ) ;
F_24 ( V_4 , true , false ) ;
for ( V_11 = 0 ; V_11 < V_4 -> V_5 . V_71 ; V_11 ++ )
V_4 -> V_5 . V_2 [ V_11 ] . V_75 = false ;
for ( V_11 = 0 ; V_11 < V_4 -> V_5 . V_71 ; V_11 ++ ) {
V_52 = F_38 ( & V_4 -> V_5 . V_2 [ V_11 ] ) ;
if ( V_52 )
return V_52 ;
else
V_4 -> V_5 . V_2 [ V_11 ] . V_75 = true ;
}
F_21 ( L_6 ) ;
return 0 ;
}
static int F_39 ( void * V_48 )
{
return 0 ;
}
static int F_40 ( void * V_48 )
{
int V_52 ;
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
V_52 = F_39 ( V_4 ) ;
if ( V_52 )
return V_52 ;
return F_34 ( V_4 ) ;
}
static int F_41 ( void * V_48 )
{
int V_52 ;
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
V_52 = F_31 ( V_4 ) ;
if ( V_52 )
return V_52 ;
return F_36 ( V_4 ) ;
}
static int F_42 ( void * V_48 )
{
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
F_15 ( V_76 , V_77 , 1 ) ;
F_8 ( 5 ) ;
return F_18 ( V_4 ) ;
}
static int F_43 ( struct V_3 * V_4 ,
struct V_78 * V_79 ,
unsigned type ,
enum V_80 V_81 )
{
T_2 V_82 = 0 ;
if ( V_81 == V_83 )
V_82 |= V_84 ;
F_11 ( V_85 , V_82 , ~ V_84 ) ;
return 0 ;
}
static int F_44 ( struct V_3 * V_4 ,
struct V_78 * V_79 ,
struct V_86 * V_87 )
{
F_45 ( L_7 ) ;
switch ( V_87 -> V_88 [ 0 ] ) {
case 0 :
case 1 :
F_46 ( & V_4 -> V_5 . V_2 [ V_87 -> V_88 [ 0 ] ] ) ;
break;
default:
F_10 ( L_8 ,
V_87 -> V_89 , V_87 -> V_88 [ 0 ] ) ;
break;
}
return 0 ;
}
static int F_47 ( void * V_48 ,
enum V_90 V_81 )
{
bool V_91 = false ;
bool V_68 = false ;
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
if ( V_81 == V_92 ) {
V_91 = true ;
V_68 = true ;
}
F_24 ( V_4 , V_91 , V_68 ) ;
return 0 ;
}
static int F_48 ( void * V_48 ,
enum V_93 V_81 )
{
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
if ( V_81 == V_94 )
return F_20 ( V_4 ) ;
else
return F_18 ( V_4 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_5 . V_71 ; V_11 ++ )
V_4 -> V_5 . V_2 [ V_11 ] . V_95 = & V_96 ;
}
static void F_27 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_73 . V_97 = 1 ;
V_4 -> V_5 . V_73 . V_95 = & V_98 ;
}
