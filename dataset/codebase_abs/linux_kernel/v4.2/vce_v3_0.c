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
int V_11 , V_12 , V_13 , V_14 ;
F_7 ( & V_4 -> V_15 ) ;
for ( V_11 = 0 ; V_11 < 2 ; ++ V_11 ) {
if ( V_4 -> V_5 . V_16 & ( 1 << V_11 ) )
continue;
if( V_11 == 0 )
F_8 ( V_17 , 0 ,
~ V_18 ) ;
else
F_8 ( V_17 ,
V_18 ,
~ V_18 ) ;
F_9 ( V_4 , V_11 ) ;
F_8 ( V_19 , 1 , ~ 1 ) ;
F_8 ( V_20 , V_21 ,
~ V_21 ) ;
F_8 ( V_22 ,
V_23 ,
~ V_23 ) ;
F_10 ( 100 ) ;
F_8 ( V_22 , 0 ,
~ V_23 ) ;
for ( V_12 = 0 ; V_12 < 10 ; ++ V_12 ) {
T_1 V_24 ;
for ( V_13 = 0 ; V_13 < 100 ; ++ V_13 ) {
V_24 = F_2 ( V_19 ) ;
if ( V_24 & 2 )
break;
F_10 ( 10 ) ;
}
V_14 = 0 ;
if ( V_24 & 2 )
break;
F_11 ( L_1 ) ;
F_8 ( V_22 ,
V_23 ,
~ V_23 ) ;
F_10 ( 10 ) ;
F_8 ( V_22 , 0 ,
~ V_23 ) ;
F_10 ( 10 ) ;
V_14 = - 1 ;
}
F_8 ( V_19 , 0 , ~ 1 ) ;
if ( V_14 ) {
F_11 ( L_2 ) ;
F_12 ( & V_4 -> V_15 ) ;
return V_14 ;
}
}
F_8 ( V_17 , 0 , ~ V_18 ) ;
F_12 ( & V_4 -> V_15 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
F_5 ( V_6 , V_2 -> V_10 ) ;
F_5 ( V_8 , V_2 -> V_10 ) ;
F_5 ( V_25 , V_2 -> V_26 ) ;
F_5 ( V_27 , F_13 ( V_2 -> V_26 ) ) ;
F_5 ( V_28 , V_2 -> V_29 / 4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
F_5 ( V_7 , V_2 -> V_10 ) ;
F_5 ( V_9 , V_2 -> V_10 ) ;
F_5 ( V_30 , V_2 -> V_26 ) ;
F_5 ( V_31 , F_13 ( V_2 -> V_26 ) ) ;
F_5 ( V_32 , V_2 -> V_29 / 4 ) ;
return 0 ;
}
static unsigned F_14 ( struct V_3 * V_4 )
{
T_2 V_33 ;
unsigned V_34 ;
if ( V_4 -> V_35 & V_36 )
V_33 = ( F_15 ( V_37 ) &
V_38 ) >>
V_39 ;
else
V_33 = ( F_15 ( V_40 ) &
V_41 ) >>
V_42 ;
switch ( V_33 ) {
case 1 :
V_34 = V_43 ;
break;
case 2 :
V_34 = V_44 ;
break;
case 3 :
V_34 = V_43 | V_44 ;
break;
default:
V_34 = 0 ;
}
return V_34 ;
}
static int F_16 ( void * V_45 )
{
struct V_3 * V_4 = (struct V_3 * ) V_45 ;
V_4 -> V_5 . V_16 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_5 . V_16 &
( V_43 | V_44 ) ) ==
( V_43 | V_44 ) )
return - V_46 ;
F_17 ( V_4 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
static int F_19 ( void * V_45 )
{
struct V_3 * V_4 = (struct V_3 * ) V_45 ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = F_20 ( V_4 , 167 , & V_4 -> V_5 . V_47 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_21 ( V_4 , V_48 +
( V_49 + V_50 ) * 2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_22 ( V_4 ) ;
if ( V_14 )
return V_14 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
sprintf ( V_2 -> V_51 , L_3 ) ;
V_14 = F_23 ( V_4 , V_2 , 4096 , V_52 , 0xf ,
& V_4 -> V_5 . V_47 , 0 , V_53 ) ;
if ( V_14 )
return V_14 ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
sprintf ( V_2 -> V_51 , L_4 ) ;
V_14 = F_23 ( V_4 , V_2 , 4096 , V_52 , 0xf ,
& V_4 -> V_5 . V_47 , 0 , V_53 ) ;
if ( V_14 )
return V_14 ;
return V_14 ;
}
static int F_24 ( void * V_45 )
{
int V_14 ;
struct V_3 * V_4 = (struct V_3 * ) V_45 ;
V_14 = F_25 ( V_4 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_26 ( V_4 ) ;
if ( V_14 )
return V_14 ;
return V_14 ;
}
static int F_27 ( void * V_45 )
{
struct V_1 * V_2 ;
int V_14 ;
struct V_3 * V_4 = (struct V_3 * ) V_45 ;
V_14 = F_6 ( V_4 ) ;
if ( V_14 )
return V_14 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
V_2 -> V_54 = true ;
V_14 = F_28 ( V_2 ) ;
if ( V_14 ) {
V_2 -> V_54 = false ;
return V_14 ;
}
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
V_2 -> V_54 = true ;
V_14 = F_28 ( V_2 ) ;
if ( V_14 ) {
V_2 -> V_54 = false ;
return V_14 ;
}
F_29 ( L_5 ) ;
return 0 ;
}
static int F_30 ( void * V_45 )
{
return 0 ;
}
static int F_31 ( void * V_45 )
{
int V_14 ;
struct V_3 * V_4 = (struct V_3 * ) V_45 ;
V_14 = F_30 ( V_4 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_25 ( V_4 ) ;
if ( V_14 )
return V_14 ;
return V_14 ;
}
static int F_32 ( void * V_45 )
{
int V_14 ;
struct V_3 * V_4 = (struct V_3 * ) V_45 ;
V_14 = F_22 ( V_4 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_27 ( V_4 ) ;
if ( V_14 )
return V_14 ;
return V_14 ;
}
static void F_9 ( struct V_3 * V_4 , int V_11 )
{
T_1 V_55 , V_56 ;
F_8 ( V_57 , 0 , ~ ( 1 << 16 ) ) ;
F_8 ( V_58 , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_8 ( V_59 , 0x3F , ~ 0x3F ) ;
F_5 ( V_60 , 0xf7 ) ;
F_5 ( V_61 , 0x00398000 ) ;
F_8 ( V_62 , 0x0 , ~ 0x1 ) ;
F_5 ( V_63 , 0 ) ;
F_5 ( V_64 , 0 ) ;
F_5 ( V_65 , 0 ) ;
F_5 ( V_66 , ( V_4 -> V_5 . V_26 >> 8 ) ) ;
V_55 = V_67 ;
V_56 = V_48 ;
F_5 ( V_68 , V_55 & 0x7fffffff ) ;
F_5 ( V_69 , V_56 ) ;
if ( V_11 == 0 ) {
V_55 += V_56 ;
V_56 = V_49 ;
F_5 ( V_70 , V_55 & 0x7fffffff ) ;
F_5 ( V_71 , V_56 ) ;
V_55 += V_56 ;
V_56 = V_50 ;
F_5 ( V_72 , V_55 & 0x7fffffff ) ;
F_5 ( V_73 , V_56 ) ;
} else {
V_55 += V_56 + V_49 + V_50 ;
V_56 = V_49 ;
F_5 ( V_70 , V_55 & 0xfffffff ) ;
F_5 ( V_71 , V_56 ) ;
V_55 += V_56 ;
V_56 = V_50 ;
F_5 ( V_72 , V_55 & 0xfffffff ) ;
F_5 ( V_73 , V_56 ) ;
}
F_8 ( V_74 , 0x0 , ~ 0x100 ) ;
F_8 ( V_75 , V_76 ,
~ V_76 ) ;
}
static bool F_33 ( void * V_45 )
{
struct V_3 * V_4 = (struct V_3 * ) V_45 ;
return ! ( F_2 ( V_77 ) & V_78 ) ;
}
static int F_34 ( void * V_45 )
{
unsigned V_12 ;
struct V_3 * V_4 = (struct V_3 * ) V_45 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_79 ; V_12 ++ ) {
if ( ! ( F_2 ( V_77 ) & V_78 ) )
return 0 ;
}
return - V_80 ;
}
static int F_35 ( void * V_45 )
{
struct V_3 * V_4 = (struct V_3 * ) V_45 ;
F_8 ( V_81 , V_82 ,
~ V_82 ) ;
F_10 ( 5 ) ;
return F_6 ( V_4 ) ;
}
static void F_36 ( void * V_45 )
{
struct V_3 * V_4 = (struct V_3 * ) V_45 ;
F_37 ( V_4 -> V_83 , L_6 ) ;
F_37 ( V_4 -> V_83 , L_7 ,
F_2 ( V_19 ) ) ;
F_37 ( V_4 -> V_83 , L_8 ,
F_2 ( V_20 ) ) ;
F_37 ( V_4 -> V_83 , L_9 ,
F_2 ( V_68 ) ) ;
F_37 ( V_4 -> V_83 , L_10 ,
F_2 ( V_69 ) ) ;
F_37 ( V_4 -> V_83 , L_11 ,
F_2 ( V_70 ) ) ;
F_37 ( V_4 -> V_83 , L_12 ,
F_2 ( V_71 ) ) ;
F_37 ( V_4 -> V_83 , L_13 ,
F_2 ( V_72 ) ) ;
F_37 ( V_4 -> V_83 , L_14 ,
F_2 ( V_73 ) ) ;
F_37 ( V_4 -> V_83 , L_15 ,
F_2 ( V_22 ) ) ;
F_37 ( V_4 -> V_83 , L_16 ,
F_2 ( V_30 ) ) ;
F_37 ( V_4 -> V_83 , L_17 ,
F_2 ( V_31 ) ) ;
F_37 ( V_4 -> V_83 , L_18 ,
F_2 ( V_32 ) ) ;
F_37 ( V_4 -> V_83 , L_19 ,
F_2 ( V_7 ) ) ;
F_37 ( V_4 -> V_83 , L_20 ,
F_2 ( V_9 ) ) ;
F_37 ( V_4 -> V_83 , L_21 ,
F_2 ( V_25 ) ) ;
F_37 ( V_4 -> V_83 , L_22 ,
F_2 ( V_27 ) ) ;
F_37 ( V_4 -> V_83 , L_23 ,
F_2 ( V_28 ) ) ;
F_37 ( V_4 -> V_83 , L_24 ,
F_2 ( V_6 ) ) ;
F_37 ( V_4 -> V_83 , L_25 ,
F_2 ( V_8 ) ) ;
F_37 ( V_4 -> V_83 , L_26 ,
F_2 ( V_57 ) ) ;
F_37 ( V_4 -> V_83 , L_27 ,
F_2 ( V_60 ) ) ;
F_37 ( V_4 -> V_83 , L_28 ,
F_2 ( V_58 ) ) ;
F_37 ( V_4 -> V_83 , L_29 ,
F_2 ( V_59 ) ) ;
F_37 ( V_4 -> V_83 , L_30 ,
F_2 ( V_75 ) ) ;
F_37 ( V_4 -> V_83 , L_31 ,
F_2 ( V_74 ) ) ;
F_37 ( V_4 -> V_83 , L_32 ,
F_2 ( V_61 ) ) ;
F_37 ( V_4 -> V_83 , L_33 ,
F_2 ( V_65 ) ) ;
F_37 ( V_4 -> V_83 , L_34 ,
F_2 ( V_63 ) ) ;
F_37 ( V_4 -> V_83 , L_35 ,
F_2 ( V_64 ) ) ;
F_37 ( V_4 -> V_83 , L_36 ,
F_2 ( V_62 ) ) ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_84 * V_85 ,
unsigned type ,
enum V_86 V_87 )
{
T_1 V_88 = 0 ;
if ( V_87 == V_89 )
V_88 |= V_76 ;
F_8 ( V_75 , V_88 , ~ V_76 ) ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 ,
struct V_84 * V_85 ,
struct V_90 * V_91 )
{
F_40 ( L_37 ) ;
switch ( V_91 -> V_92 ) {
case 0 :
F_41 ( & V_4 -> V_5 . V_2 [ 0 ] ) ;
break;
case 1 :
F_41 ( & V_4 -> V_5 . V_2 [ 1 ] ) ;
break;
default:
F_11 ( L_38 ,
V_91 -> V_93 , V_91 -> V_92 ) ;
break;
}
return 0 ;
}
static int F_42 ( void * V_45 ,
enum V_94 V_87 )
{
return 0 ;
}
static int F_43 ( void * V_45 ,
enum V_95 V_87 )
{
struct V_3 * V_4 = (struct V_3 * ) V_45 ;
if ( V_87 == V_96 )
return 0 ;
else
return F_6 ( V_4 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_2 [ 0 ] . V_97 = & V_98 ;
V_4 -> V_5 . V_2 [ 1 ] . V_97 = & V_98 ;
}
static void F_18 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_47 . V_99 = 1 ;
V_4 -> V_5 . V_47 . V_97 = & V_100 ;
}
