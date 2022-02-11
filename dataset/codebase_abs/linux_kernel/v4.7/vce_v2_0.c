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
struct V_1 * V_2 ;
int V_11 , V_12 , V_13 ;
F_7 ( V_4 ) ;
F_8 ( V_14 , 1 , ~ 1 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
F_5 ( V_6 , V_2 -> V_10 ) ;
F_5 ( V_8 , V_2 -> V_10 ) ;
F_5 ( V_15 , V_2 -> V_16 ) ;
F_5 ( V_17 , F_9 ( V_2 -> V_16 ) ) ;
F_5 ( V_18 , V_2 -> V_19 / 4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
F_5 ( V_7 , V_2 -> V_10 ) ;
F_5 ( V_9 , V_2 -> V_10 ) ;
F_5 ( V_20 , V_2 -> V_16 ) ;
F_5 ( V_21 , F_9 ( V_2 -> V_16 ) ) ;
F_5 ( V_22 , V_2 -> V_19 / 4 ) ;
F_8 ( V_23 , V_24 , ~ V_24 ) ;
F_8 ( V_25 ,
V_26 ,
~ V_26 ) ;
F_10 ( 100 ) ;
F_8 ( V_25 , 0 , ~ V_26 ) ;
for ( V_11 = 0 ; V_11 < 10 ; ++ V_11 ) {
T_1 V_27 ;
for ( V_12 = 0 ; V_12 < 100 ; ++ V_12 ) {
V_27 = F_2 ( V_14 ) ;
if ( V_27 & 2 )
break;
F_10 ( 10 ) ;
}
V_13 = 0 ;
if ( V_27 & 2 )
break;
F_11 ( L_1 ) ;
F_8 ( V_25 , V_26 ,
~ V_26 ) ;
F_10 ( 10 ) ;
F_8 ( V_25 , 0 , ~ V_26 ) ;
F_10 ( 10 ) ;
V_13 = - 1 ;
}
F_8 ( V_14 , 0 , ~ 1 ) ;
if ( V_13 ) {
F_11 ( L_2 ) ;
return V_13 ;
}
return 0 ;
}
static int F_12 ( void * V_28 )
{
struct V_3 * V_4 = (struct V_3 * ) V_28 ;
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
return 0 ;
}
static int F_15 ( void * V_28 )
{
struct V_1 * V_2 ;
int V_13 ;
struct V_3 * V_4 = (struct V_3 * ) V_28 ;
V_13 = F_16 ( V_4 , 167 , & V_4 -> V_5 . V_29 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_17 ( V_4 , V_30 +
V_31 + V_32 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_18 ( V_4 ) ;
if ( V_13 )
return V_13 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
sprintf ( V_2 -> V_33 , L_3 ) ;
V_13 = F_19 ( V_4 , V_2 , 512 , V_34 , 0xf ,
& V_4 -> V_5 . V_29 , 0 , V_35 ) ;
if ( V_13 )
return V_13 ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
sprintf ( V_2 -> V_33 , L_4 ) ;
V_13 = F_19 ( V_4 , V_2 , 512 , V_34 , 0xf ,
& V_4 -> V_5 . V_29 , 0 , V_35 ) ;
if ( V_13 )
return V_13 ;
return V_13 ;
}
static int F_20 ( void * V_28 )
{
int V_13 ;
struct V_3 * V_4 = (struct V_3 * ) V_28 ;
V_13 = F_21 ( V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_22 ( V_4 ) ;
if ( V_13 )
return V_13 ;
return V_13 ;
}
static int F_23 ( void * V_28 )
{
struct V_1 * V_2 ;
int V_13 ;
struct V_3 * V_4 = (struct V_3 * ) V_28 ;
V_13 = F_6 ( V_4 ) ;
if ( V_13 )
return 0 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
V_2 -> V_36 = true ;
V_13 = F_24 ( V_2 ) ;
if ( V_13 ) {
V_2 -> V_36 = false ;
return V_13 ;
}
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
V_2 -> V_36 = true ;
V_13 = F_24 ( V_2 ) ;
if ( V_13 ) {
V_2 -> V_36 = false ;
return V_13 ;
}
F_25 ( L_5 ) ;
return 0 ;
}
static int F_26 ( void * V_28 )
{
return 0 ;
}
static int F_27 ( void * V_28 )
{
int V_13 ;
struct V_3 * V_4 = (struct V_3 * ) V_28 ;
V_13 = F_26 ( V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_21 ( V_4 ) ;
if ( V_13 )
return V_13 ;
return V_13 ;
}
static int F_28 ( void * V_28 )
{
int V_13 ;
struct V_3 * V_4 = (struct V_3 * ) V_28 ;
V_13 = F_18 ( V_4 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_23 ( V_4 ) ;
if ( V_13 )
return V_13 ;
return V_13 ;
}
static void F_29 ( struct V_3 * V_4 , bool V_37 )
{
T_2 V_38 ;
if ( V_37 ) {
V_38 = F_2 ( V_39 ) ;
V_38 |= 0xe70000 ;
F_5 ( V_39 , V_38 ) ;
V_38 = F_2 ( V_40 ) ;
V_38 |= 0xff000000 ;
F_5 ( V_40 , V_38 ) ;
V_38 = F_2 ( V_41 ) ;
V_38 &= ~ 0x3fc ;
F_5 ( V_41 , V_38 ) ;
F_5 ( V_42 , 0 ) ;
} else {
V_38 = F_2 ( V_39 ) ;
V_38 |= 0xe7 ;
V_38 &= ~ 0xe70000 ;
F_5 ( V_39 , V_38 ) ;
V_38 = F_2 ( V_40 ) ;
V_38 |= 0x1fe000 ;
V_38 &= ~ 0xff000000 ;
F_5 ( V_40 , V_38 ) ;
V_38 = F_2 ( V_41 ) ;
V_38 |= 0x3fc ;
F_5 ( V_41 , V_38 ) ;
}
}
static void F_30 ( struct V_3 * V_4 , bool V_37 )
{
T_2 V_43 , V_38 ;
if ( V_37 ) {
if ( F_31 ( V_4 ) ) {
F_25 ( L_6 ) ;
return;
}
F_8 ( V_23 , 0 , ~ V_24 ) ;
F_8 ( V_25 , V_26 , ~ V_26 ) ;
F_10 ( 100 ) ;
F_5 ( V_14 , 0 ) ;
} else {
F_8 ( V_23 , V_24 , ~ V_24 ) ;
F_8 ( V_25 , V_26 , ~ V_26 ) ;
F_10 ( 100 ) ;
}
V_38 = F_2 ( V_39 ) ;
V_38 &= ~ 0x00060006 ;
if ( V_37 ) {
V_38 |= 0xe10000 ;
} else {
V_38 |= 0xe1 ;
V_38 &= ~ 0xe10000 ;
}
F_5 ( V_39 , V_38 ) ;
V_43 = V_38 = F_2 ( V_40 ) ;
V_38 &= ~ 0x1fe000 ;
V_38 &= ~ 0xff000000 ;
if ( V_38 != V_43 )
F_5 ( V_40 , V_38 ) ;
V_43 = V_38 = F_2 ( V_41 ) ;
V_38 &= ~ 0x3fc ;
if ( V_38 != V_43 )
F_5 ( V_41 , V_38 ) ;
if ( V_37 )
F_5 ( V_42 , 0 ) ;
F_8 ( V_25 , 0 , ~ V_26 ) ;
}
static void F_32 ( struct V_3 * V_4 )
{
F_5 ( V_42 , 7 ) ;
}
static void F_33 ( struct V_3 * V_4 , bool V_44 )
{
bool V_45 = false ;
if ( V_44 && ( V_4 -> V_46 & V_47 ) ) {
if ( V_45 )
F_29 ( V_4 , true ) ;
else
F_30 ( V_4 , true ) ;
} else {
F_32 ( V_4 ) ;
if ( V_45 )
F_29 ( V_4 , false ) ;
else
F_30 ( V_4 , false ) ;
}
}
static void F_34 ( struct V_3 * V_4 )
{
T_2 V_38 ;
V_38 = F_2 ( V_48 ) ;
V_38 &= ~ 0xfff ;
V_38 |= ( ( 0 << 0 ) | ( 4 << 4 ) ) ;
V_38 |= 0x40000 ;
F_5 ( V_48 , V_38 ) ;
V_38 = F_2 ( V_40 ) ;
V_38 &= ~ 0xfff ;
V_38 |= ( ( 0 << 0 ) | ( 4 << 4 ) ) ;
F_5 ( V_40 , V_38 ) ;
V_38 = F_2 ( V_39 ) ;
V_38 |= 0x10 ;
V_38 &= ~ 0x100000 ;
F_5 ( V_39 , V_38 ) ;
}
static void F_7 ( struct V_3 * V_4 )
{
T_3 V_49 = V_4 -> V_5 . V_16 ;
T_1 V_50 ;
F_8 ( V_48 , 0 , ~ ( 1 << 16 ) ) ;
F_8 ( V_40 , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_8 ( V_41 , 0x3F , ~ 0x3F ) ;
F_5 ( V_39 , 0xf7 ) ;
F_5 ( V_51 , 0x00398000 ) ;
F_8 ( V_52 , 0x0 , ~ 0x1 ) ;
F_5 ( V_53 , 0 ) ;
F_5 ( V_54 , 0 ) ;
F_5 ( V_55 , 0 ) ;
V_49 += V_56 ;
V_50 = V_30 ;
F_5 ( V_57 , V_49 & 0x7fffffff ) ;
F_5 ( V_58 , V_50 ) ;
V_49 += V_50 ;
V_50 = V_31 ;
F_5 ( V_59 , V_49 & 0x7fffffff ) ;
F_5 ( V_60 , V_50 ) ;
V_49 += V_50 ;
V_50 = V_32 ;
F_5 ( V_61 , V_49 & 0x7fffffff ) ;
F_5 ( V_62 , V_50 ) ;
F_8 ( V_63 , 0x0 , ~ 0x100 ) ;
F_8 ( V_64 , V_65 ,
~ V_65 ) ;
F_34 ( V_4 ) ;
}
static bool F_35 ( void * V_28 )
{
struct V_3 * V_4 = (struct V_3 * ) V_28 ;
return ! ( F_2 ( V_66 ) & V_67 ) ;
}
static int F_31 ( void * V_28 )
{
unsigned V_11 ;
struct V_3 * V_4 = (struct V_3 * ) V_28 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_68 ; V_11 ++ ) {
if ( ! ( F_2 ( V_66 ) & V_67 ) )
return 0 ;
}
return - V_69 ;
}
static int F_36 ( void * V_28 )
{
struct V_3 * V_4 = (struct V_3 * ) V_28 ;
F_8 ( V_70 , V_71 ,
~ V_71 ) ;
F_10 ( 5 ) ;
return F_6 ( V_4 ) ;
}
static int F_37 ( struct V_3 * V_4 ,
struct V_72 * V_73 ,
unsigned type ,
enum V_74 V_75 )
{
T_1 V_76 = 0 ;
if ( V_75 == V_77 )
V_76 |= V_65 ;
F_8 ( V_64 , V_76 , ~ V_65 ) ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_72 * V_73 ,
struct V_78 * V_79 )
{
F_39 ( L_7 ) ;
switch ( V_79 -> V_80 ) {
case 0 :
F_40 ( & V_4 -> V_5 . V_2 [ 0 ] ) ;
break;
case 1 :
F_40 ( & V_4 -> V_5 . V_2 [ 1 ] ) ;
break;
default:
F_11 ( L_8 ,
V_79 -> V_81 , V_79 -> V_80 ) ;
break;
}
return 0 ;
}
static int F_41 ( void * V_28 ,
enum V_82 V_75 )
{
bool V_83 = false ;
struct V_3 * V_4 = (struct V_3 * ) V_28 ;
if ( V_75 == V_84 )
V_83 = true ;
F_33 ( V_4 , V_83 ) ;
return 0 ;
}
static int F_42 ( void * V_28 ,
enum V_85 V_75 )
{
struct V_3 * V_4 = (struct V_3 * ) V_28 ;
if ( ! ( V_4 -> V_86 & V_87 ) )
return 0 ;
if ( V_75 == V_88 )
return 0 ;
else
return F_6 ( V_4 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_2 [ 0 ] . V_89 = & V_90 ;
V_4 -> V_5 . V_2 [ 1 ] . V_89 = & V_90 ;
}
static void F_14 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_29 . V_91 = 1 ;
V_4 -> V_5 . V_29 . V_89 = & V_92 ;
}
