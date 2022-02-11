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
if ( V_4 -> V_20 >= V_21 )
F_8 ( V_22 , 1 , ~ 0x200001 ) ;
else
F_8 ( V_22 , V_23 ,
~ V_23 ) ;
F_8 ( V_24 ,
V_25 ,
~ V_25 ) ;
F_10 ( 100 ) ;
F_8 ( V_24 , 0 ,
~ V_25 ) ;
for ( V_12 = 0 ; V_12 < 10 ; ++ V_12 ) {
T_1 V_26 ;
for ( V_13 = 0 ; V_13 < 100 ; ++ V_13 ) {
V_26 = F_2 ( V_19 ) ;
if ( V_26 & 2 )
break;
F_10 ( 10 ) ;
}
V_14 = 0 ;
if ( V_26 & 2 )
break;
F_11 ( L_1 ) ;
F_8 ( V_24 ,
V_25 ,
~ V_25 ) ;
F_10 ( 10 ) ;
F_8 ( V_24 , 0 ,
~ V_25 ) ;
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
F_5 ( V_27 , V_2 -> V_28 ) ;
F_5 ( V_29 , F_13 ( V_2 -> V_28 ) ) ;
F_5 ( V_30 , V_2 -> V_31 / 4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
F_5 ( V_7 , V_2 -> V_10 ) ;
F_5 ( V_9 , V_2 -> V_10 ) ;
F_5 ( V_32 , V_2 -> V_28 ) ;
F_5 ( V_33 , F_13 ( V_2 -> V_28 ) ) ;
F_5 ( V_34 , V_2 -> V_31 / 4 ) ;
return 0 ;
}
static unsigned F_14 ( struct V_3 * V_4 )
{
T_2 V_35 ;
unsigned V_36 ;
if ( ( V_4 -> V_20 == V_37 ) ||
( V_4 -> V_20 == V_21 ) ) {
V_36 = V_38 ;
return V_36 ;
}
if ( V_4 -> V_39 & V_40 )
V_35 = ( F_15 ( V_41 ) &
V_42 ) >>
V_43 ;
else
V_35 = ( F_15 ( V_44 ) &
V_45 ) >>
V_46 ;
switch ( V_35 ) {
case 1 :
V_36 = V_47 ;
break;
case 2 :
V_36 = V_38 ;
break;
case 3 :
V_36 = V_47 | V_38 ;
break;
default:
V_36 = 0 ;
}
return V_36 ;
}
static int F_16 ( void * V_48 )
{
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
V_4 -> V_5 . V_16 = F_14 ( V_4 ) ;
if ( ( V_4 -> V_5 . V_16 &
( V_47 | V_38 ) ) ==
( V_47 | V_38 ) )
return - V_49 ;
F_17 ( V_4 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
static int F_19 ( void * V_48 )
{
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = F_20 ( V_4 , 167 , & V_4 -> V_5 . V_50 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_21 ( V_4 , V_51 +
( V_52 + V_53 ) * 2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_22 ( V_4 ) ;
if ( V_14 )
return V_14 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
sprintf ( V_2 -> V_54 , L_3 ) ;
V_14 = F_23 ( V_4 , V_2 , 4096 , V_55 , 0xf ,
& V_4 -> V_5 . V_50 , 0 , V_56 ) ;
if ( V_14 )
return V_14 ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
sprintf ( V_2 -> V_54 , L_4 ) ;
V_14 = F_23 ( V_4 , V_2 , 4096 , V_55 , 0xf ,
& V_4 -> V_5 . V_50 , 0 , V_56 ) ;
if ( V_14 )
return V_14 ;
return V_14 ;
}
static int F_24 ( void * V_48 )
{
int V_14 ;
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
V_14 = F_25 ( V_4 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_26 ( V_4 ) ;
if ( V_14 )
return V_14 ;
return V_14 ;
}
static int F_27 ( void * V_48 )
{
struct V_1 * V_2 ;
int V_14 ;
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
V_14 = F_6 ( V_4 ) ;
if ( V_14 )
return V_14 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
V_2 -> V_57 = true ;
V_14 = F_28 ( V_2 ) ;
if ( V_14 ) {
V_2 -> V_57 = false ;
return V_14 ;
}
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
V_2 -> V_57 = true ;
V_14 = F_28 ( V_2 ) ;
if ( V_14 ) {
V_2 -> V_57 = false ;
return V_14 ;
}
F_29 ( L_5 ) ;
return 0 ;
}
static int F_30 ( void * V_48 )
{
return 0 ;
}
static int F_31 ( void * V_48 )
{
int V_14 ;
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
V_14 = F_30 ( V_4 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_25 ( V_4 ) ;
if ( V_14 )
return V_14 ;
return V_14 ;
}
static int F_32 ( void * V_48 )
{
int V_14 ;
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
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
T_1 V_58 , V_59 ;
F_8 ( V_60 , 0 , ~ ( 1 << 16 ) ) ;
F_8 ( V_61 , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_8 ( V_62 , 0x3F , ~ 0x3F ) ;
F_5 ( V_63 , 0xf7 ) ;
F_5 ( V_64 , 0x00398000 ) ;
F_8 ( V_65 , 0x0 , ~ 0x1 ) ;
F_5 ( V_66 , 0 ) ;
F_5 ( V_67 , 0 ) ;
F_5 ( V_68 , 0 ) ;
if ( V_4 -> V_20 >= V_21 ) {
F_5 ( V_69 , ( V_4 -> V_5 . V_28 >> 8 ) ) ;
F_5 ( V_70 , ( V_4 -> V_5 . V_28 >> 8 ) ) ;
F_5 ( V_71 , ( V_4 -> V_5 . V_28 >> 8 ) ) ;
} else
F_5 ( V_72 , ( V_4 -> V_5 . V_28 >> 8 ) ) ;
V_58 = V_73 ;
V_59 = V_51 ;
F_5 ( V_74 , V_58 & 0x7fffffff ) ;
F_5 ( V_75 , V_59 ) ;
if ( V_11 == 0 ) {
V_58 += V_59 ;
V_59 = V_52 ;
F_5 ( V_76 , V_58 & 0x7fffffff ) ;
F_5 ( V_77 , V_59 ) ;
V_58 += V_59 ;
V_59 = V_53 ;
F_5 ( V_78 , V_58 & 0x7fffffff ) ;
F_5 ( V_79 , V_59 ) ;
} else {
V_58 += V_59 + V_52 + V_53 ;
V_59 = V_52 ;
F_5 ( V_76 , V_58 & 0xfffffff ) ;
F_5 ( V_77 , V_59 ) ;
V_58 += V_59 ;
V_59 = V_53 ;
F_5 ( V_78 , V_58 & 0xfffffff ) ;
F_5 ( V_79 , V_59 ) ;
}
F_8 ( V_80 , 0x0 , ~ 0x100 ) ;
F_8 ( V_81 , V_82 ,
~ V_82 ) ;
}
static bool F_33 ( void * V_48 )
{
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
T_2 V_83 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 2 ; ++ V_11 ) {
if ( V_4 -> V_5 . V_16 & ( 1 << V_11 ) )
continue;
if ( V_11 == 0 )
V_83 |= V_84 ;
else
V_83 |= V_85 ;
}
return ! ( F_2 ( V_86 ) & V_83 ) ;
}
static int F_34 ( void * V_48 )
{
unsigned V_12 ;
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
T_2 V_83 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 2 ; ++ V_11 ) {
if ( V_4 -> V_5 . V_16 & ( 1 << V_11 ) )
continue;
if ( V_11 == 0 )
V_83 |= V_84 ;
else
V_83 |= V_85 ;
}
for ( V_12 = 0 ; V_12 < V_4 -> V_87 ; V_12 ++ ) {
if ( ! ( F_2 ( V_86 ) & V_83 ) )
return 0 ;
}
return - V_88 ;
}
static int F_35 ( void * V_48 )
{
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
T_2 V_83 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 2 ; ++ V_11 ) {
if ( V_4 -> V_5 . V_16 & ( 1 << V_11 ) )
continue;
if ( V_11 == 0 )
V_83 |= V_89 ;
else
V_83 |= V_90 ;
}
F_8 ( V_91 , V_83 ,
~ ( V_89 |
V_90 ) ) ;
F_10 ( 5 ) ;
return F_6 ( V_4 ) ;
}
static void F_36 ( void * V_48 )
{
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
F_37 ( V_4 -> V_92 , L_6 ) ;
F_37 ( V_4 -> V_92 , L_7 ,
F_2 ( V_19 ) ) ;
F_37 ( V_4 -> V_92 , L_8 ,
F_2 ( V_22 ) ) ;
F_37 ( V_4 -> V_92 , L_9 ,
F_2 ( V_74 ) ) ;
F_37 ( V_4 -> V_92 , L_10 ,
F_2 ( V_75 ) ) ;
F_37 ( V_4 -> V_92 , L_11 ,
F_2 ( V_76 ) ) ;
F_37 ( V_4 -> V_92 , L_12 ,
F_2 ( V_77 ) ) ;
F_37 ( V_4 -> V_92 , L_13 ,
F_2 ( V_78 ) ) ;
F_37 ( V_4 -> V_92 , L_14 ,
F_2 ( V_79 ) ) ;
F_37 ( V_4 -> V_92 , L_15 ,
F_2 ( V_24 ) ) ;
F_37 ( V_4 -> V_92 , L_16 ,
F_2 ( V_32 ) ) ;
F_37 ( V_4 -> V_92 , L_17 ,
F_2 ( V_33 ) ) ;
F_37 ( V_4 -> V_92 , L_18 ,
F_2 ( V_34 ) ) ;
F_37 ( V_4 -> V_92 , L_19 ,
F_2 ( V_7 ) ) ;
F_37 ( V_4 -> V_92 , L_20 ,
F_2 ( V_9 ) ) ;
F_37 ( V_4 -> V_92 , L_21 ,
F_2 ( V_27 ) ) ;
F_37 ( V_4 -> V_92 , L_22 ,
F_2 ( V_29 ) ) ;
F_37 ( V_4 -> V_92 , L_23 ,
F_2 ( V_30 ) ) ;
F_37 ( V_4 -> V_92 , L_24 ,
F_2 ( V_6 ) ) ;
F_37 ( V_4 -> V_92 , L_25 ,
F_2 ( V_8 ) ) ;
F_37 ( V_4 -> V_92 , L_26 ,
F_2 ( V_60 ) ) ;
F_37 ( V_4 -> V_92 , L_27 ,
F_2 ( V_63 ) ) ;
F_37 ( V_4 -> V_92 , L_28 ,
F_2 ( V_61 ) ) ;
F_37 ( V_4 -> V_92 , L_29 ,
F_2 ( V_62 ) ) ;
F_37 ( V_4 -> V_92 , L_30 ,
F_2 ( V_81 ) ) ;
F_37 ( V_4 -> V_92 , L_31 ,
F_2 ( V_80 ) ) ;
F_37 ( V_4 -> V_92 , L_32 ,
F_2 ( V_64 ) ) ;
F_37 ( V_4 -> V_92 , L_33 ,
F_2 ( V_68 ) ) ;
F_37 ( V_4 -> V_92 , L_34 ,
F_2 ( V_66 ) ) ;
F_37 ( V_4 -> V_92 , L_35 ,
F_2 ( V_67 ) ) ;
F_37 ( V_4 -> V_92 , L_36 ,
F_2 ( V_65 ) ) ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_93 * V_94 ,
unsigned type ,
enum V_95 V_96 )
{
T_1 V_97 = 0 ;
if ( V_96 == V_98 )
V_97 |= V_82 ;
F_8 ( V_81 , V_97 , ~ V_82 ) ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 ,
struct V_93 * V_94 ,
struct V_99 * V_100 )
{
F_40 ( L_37 ) ;
F_8 ( V_101 ,
V_102 ,
~ V_102 ) ;
switch ( V_100 -> V_103 ) {
case 0 :
F_41 ( & V_4 -> V_5 . V_2 [ 0 ] ) ;
break;
case 1 :
F_41 ( & V_4 -> V_5 . V_2 [ 1 ] ) ;
break;
default:
F_11 ( L_38 ,
V_100 -> V_104 , V_100 -> V_103 ) ;
break;
}
return 0 ;
}
static int F_42 ( void * V_48 ,
enum V_105 V_96 )
{
return 0 ;
}
static int F_43 ( void * V_48 ,
enum V_106 V_96 )
{
struct V_3 * V_4 = (struct V_3 * ) V_48 ;
if ( V_96 == V_107 )
return 0 ;
else
return F_6 ( V_4 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_2 [ 0 ] . V_108 = & V_109 ;
V_4 -> V_5 . V_2 [ 1 ] . V_108 = & V_109 ;
}
static void F_18 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_50 . V_110 = 1 ;
V_4 -> V_5 . V_50 . V_108 = & V_111 ;
}
