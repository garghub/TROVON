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
static void F_6 ( struct V_3 * V_4 , bool V_11 )
{
T_2 V_12 , V_13 ;
V_12 = V_13 = F_2 ( V_14 ) ;
if ( V_11 )
V_13 |= V_15 ;
else
V_13 &= ~ V_15 ;
if ( V_12 != V_13 )
F_5 ( V_14 , V_13 ) ;
}
static void F_7 ( struct V_3 * V_4 ,
bool V_16 )
{
T_2 V_12 , V_13 ;
F_6 ( V_4 , true ) ;
if ( ! V_16 ) {
V_12 = V_13 = F_2 ( V_17 ) ;
V_13 |= 0x1ff ;
V_13 &= ~ 0xef0000 ;
if ( V_12 != V_13 )
F_5 ( V_17 , V_13 ) ;
V_12 = V_13 = F_2 ( V_18 ) ;
V_13 |= 0x3ff000 ;
V_13 &= ~ 0xffc00000 ;
if ( V_12 != V_13 )
F_5 ( V_18 , V_13 ) ;
V_12 = V_13 = F_2 ( V_19 ) ;
V_13 |= 0x2 ;
V_13 &= ~ 0x2 ;
if ( V_12 != V_13 )
F_5 ( V_19 , V_13 ) ;
V_12 = V_13 = F_2 ( V_20 ) ;
V_13 |= 0x37f ;
if ( V_12 != V_13 )
F_5 ( V_20 , V_13 ) ;
V_12 = V_13 = F_2 ( V_21 ) ;
V_13 |= V_22 |
V_23 |
V_24 |
0x8 ;
if ( V_12 != V_13 )
F_5 ( V_21 , V_13 ) ;
} else {
V_12 = V_13 = F_2 ( V_17 ) ;
V_13 &= ~ 0x80010 ;
V_13 |= 0xe70008 ;
if ( V_12 != V_13 )
F_5 ( V_17 , V_13 ) ;
V_12 = V_13 = F_2 ( V_18 ) ;
V_13 |= 0xffc00000 ;
if ( V_12 != V_13 )
F_5 ( V_18 , V_13 ) ;
V_12 = V_13 = F_2 ( V_19 ) ;
V_13 |= 0x10000 ;
if ( V_12 != V_13 )
F_5 ( V_19 , V_13 ) ;
V_12 = V_13 = F_2 ( V_20 ) ;
V_13 &= ~ 0xffc00000 ;
if ( V_12 != V_13 )
F_5 ( V_20 , V_13 ) ;
V_12 = V_13 = F_2 ( V_21 ) ;
V_13 &= ~ ( V_22 |
V_23 |
V_24 |
0x8 ) ;
if ( V_12 != V_13 )
F_5 ( V_21 , V_13 ) ;
}
F_6 ( V_4 , false ) ;
}
static int F_8 ( struct V_3 * V_4 )
{
int V_25 , V_26 ;
for ( V_25 = 0 ; V_25 < 10 ; ++ V_25 ) {
for ( V_26 = 0 ; V_26 < 100 ; ++ V_26 ) {
T_1 V_27 = F_2 ( V_28 ) ;
if ( V_27 & V_29 )
return 0 ;
F_9 ( 10 ) ;
}
F_10 ( L_1 ) ;
F_11 ( V_30 ,
V_31 ,
~ V_31 ) ;
F_9 ( 10 ) ;
F_11 ( V_30 , 0 ,
~ V_31 ) ;
F_9 ( 10 ) ;
}
return - V_32 ;
}
static int F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_33 , V_34 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
F_5 ( V_6 , V_2 -> V_10 ) ;
F_5 ( V_8 , V_2 -> V_10 ) ;
F_5 ( V_35 , V_2 -> V_36 ) ;
F_5 ( V_37 , F_13 ( V_2 -> V_36 ) ) ;
F_5 ( V_38 , V_2 -> V_39 / 4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
F_5 ( V_7 , V_2 -> V_10 ) ;
F_5 ( V_9 , V_2 -> V_10 ) ;
F_5 ( V_40 , V_2 -> V_36 ) ;
F_5 ( V_41 , F_13 ( V_2 -> V_36 ) ) ;
F_5 ( V_42 , V_2 -> V_39 / 4 ) ;
F_14 ( & V_4 -> V_43 ) ;
for ( V_33 = 0 ; V_33 < 2 ; ++ V_33 ) {
if ( V_4 -> V_5 . V_44 & ( 1 << V_33 ) )
continue;
if ( V_33 == 0 )
F_11 ( V_45 , 0 ,
~ V_46 ) ;
else
F_11 ( V_45 ,
V_46 ,
~ V_46 ) ;
F_15 ( V_4 , V_33 ) ;
F_11 ( V_28 , V_47 ,
~ V_47 ) ;
if ( V_4 -> V_48 >= V_49 )
F_11 ( V_50 , 1 , ~ 0x200001 ) ;
else
F_11 ( V_50 , V_51 ,
~ V_51 ) ;
F_11 ( V_30 , 0 ,
~ V_31 ) ;
F_9 ( 100 ) ;
V_34 = F_8 ( V_4 ) ;
F_11 ( V_28 , 0 , ~ V_47 ) ;
if ( V_4 -> V_52 & V_53 )
F_7 ( V_4 , false ) ;
if ( V_34 ) {
F_10 ( L_2 ) ;
F_16 ( & V_4 -> V_43 ) ;
return V_34 ;
}
}
F_11 ( V_45 , 0 , ~ V_46 ) ;
F_16 ( & V_4 -> V_43 ) ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
int V_33 ;
F_14 ( & V_4 -> V_43 ) ;
for ( V_33 = 0 ; V_33 < 2 ; ++ V_33 ) {
if ( V_4 -> V_5 . V_44 & ( 1 << V_33 ) )
continue;
if ( V_33 == 0 )
F_11 ( V_45 , 0 ,
~ V_46 ) ;
else
F_11 ( V_45 ,
V_46 ,
~ V_46 ) ;
if ( V_4 -> V_48 >= V_49 )
F_11 ( V_50 , 0 , ~ 0x200001 ) ;
else
F_11 ( V_50 , 0 ,
~ V_51 ) ;
F_11 ( V_30 ,
V_31 ,
~ V_31 ) ;
F_11 ( V_28 , 0 , ~ V_47 ) ;
if ( V_4 -> V_52 & V_53 )
F_7 ( V_4 , false ) ;
}
F_11 ( V_45 , 0 , ~ V_46 ) ;
F_16 ( & V_4 -> V_43 ) ;
return 0 ;
}
static unsigned F_18 ( struct V_3 * V_4 )
{
T_2 V_12 ;
if ( ( V_4 -> V_48 == V_54 ) ||
( V_4 -> V_48 == V_49 ) ||
( V_4 -> V_48 == V_55 ) ||
( V_4 -> V_48 == V_56 ) )
return V_57 ;
if ( V_4 -> V_58 & V_59 )
V_12 = ( F_19 ( V_60 ) &
V_61 ) >>
V_62 ;
else
V_12 = ( F_19 ( V_63 ) &
V_64 ) >>
V_65 ;
switch ( V_12 ) {
case 1 :
return V_66 ;
case 2 :
return V_57 ;
case 3 :
return V_66 | V_57 ;
default:
return 0 ;
}
}
static int F_20 ( void * V_67 )
{
struct V_3 * V_4 = (struct V_3 * ) V_67 ;
V_4 -> V_5 . V_44 = F_18 ( V_4 ) ;
if ( ( V_4 -> V_5 . V_44 &
( V_66 | V_57 ) ) ==
( V_66 | V_57 ) )
return - V_68 ;
F_21 ( V_4 ) ;
F_22 ( V_4 ) ;
return 0 ;
}
static int F_23 ( void * V_67 )
{
struct V_3 * V_4 = (struct V_3 * ) V_67 ;
struct V_1 * V_2 ;
int V_34 ;
V_34 = F_24 ( V_4 , 167 , & V_4 -> V_5 . V_69 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_25 ( V_4 , V_70 +
( V_71 + V_72 ) * 2 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_26 ( V_4 ) ;
if ( V_34 )
return V_34 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
sprintf ( V_2 -> V_73 , L_3 ) ;
V_34 = F_27 ( V_4 , V_2 , 512 , V_74 , 0xf ,
& V_4 -> V_5 . V_69 , 0 , V_75 ) ;
if ( V_34 )
return V_34 ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
sprintf ( V_2 -> V_73 , L_4 ) ;
V_34 = F_27 ( V_4 , V_2 , 512 , V_74 , 0xf ,
& V_4 -> V_5 . V_69 , 0 , V_75 ) ;
if ( V_34 )
return V_34 ;
return V_34 ;
}
static int F_28 ( void * V_67 )
{
int V_34 ;
struct V_3 * V_4 = (struct V_3 * ) V_67 ;
V_34 = F_29 ( V_4 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_30 ( V_4 ) ;
if ( V_34 )
return V_34 ;
return V_34 ;
}
static int F_31 ( void * V_67 )
{
int V_34 , V_25 ;
struct V_3 * V_4 = (struct V_3 * ) V_67 ;
V_34 = F_12 ( V_4 ) ;
if ( V_34 )
return V_34 ;
V_4 -> V_5 . V_2 [ 0 ] . V_76 = false ;
V_4 -> V_5 . V_2 [ 1 ] . V_76 = false ;
for ( V_25 = 0 ; V_25 < 2 ; V_25 ++ ) {
V_34 = F_32 ( & V_4 -> V_5 . V_2 [ V_25 ] ) ;
if ( V_34 )
return V_34 ;
else
V_4 -> V_5 . V_2 [ V_25 ] . V_76 = true ;
}
F_33 ( L_5 ) ;
return 0 ;
}
static int F_34 ( void * V_67 )
{
int V_34 ;
struct V_3 * V_4 = (struct V_3 * ) V_67 ;
V_34 = F_35 ( V_67 ) ;
if ( V_34 )
return V_34 ;
return F_17 ( V_4 ) ;
}
static int F_36 ( void * V_67 )
{
int V_34 ;
struct V_3 * V_4 = (struct V_3 * ) V_67 ;
V_34 = F_34 ( V_4 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_29 ( V_4 ) ;
if ( V_34 )
return V_34 ;
return V_34 ;
}
static int F_37 ( void * V_67 )
{
int V_34 ;
struct V_3 * V_4 = (struct V_3 * ) V_67 ;
V_34 = F_26 ( V_4 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_31 ( V_4 ) ;
if ( V_34 )
return V_34 ;
return V_34 ;
}
static void F_15 ( struct V_3 * V_4 , int V_33 )
{
T_1 V_77 , V_78 ;
F_11 ( V_79 , 0 , ~ ( 1 << 16 ) ) ;
F_11 ( V_18 , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_11 ( V_20 , 0x3F , ~ 0x3F ) ;
F_5 ( V_17 , 0xf7 ) ;
F_5 ( V_80 , 0x00398000 ) ;
F_11 ( V_81 , 0x0 , ~ 0x1 ) ;
F_5 ( V_82 , 0 ) ;
F_5 ( V_83 , 0 ) ;
F_5 ( V_84 , 0 ) ;
if ( V_4 -> V_48 >= V_49 ) {
F_5 ( V_85 , ( V_4 -> V_5 . V_36 >> 8 ) ) ;
F_5 ( V_86 , ( V_4 -> V_5 . V_36 >> 8 ) ) ;
F_5 ( V_87 , ( V_4 -> V_5 . V_36 >> 8 ) ) ;
} else
F_5 ( V_88 , ( V_4 -> V_5 . V_36 >> 8 ) ) ;
V_77 = V_89 ;
V_78 = V_70 ;
F_5 ( V_90 , V_77 & 0x7fffffff ) ;
F_5 ( V_91 , V_78 ) ;
if ( V_33 == 0 ) {
V_77 += V_78 ;
V_78 = V_71 ;
F_5 ( V_92 , V_77 & 0x7fffffff ) ;
F_5 ( V_93 , V_78 ) ;
V_77 += V_78 ;
V_78 = V_72 ;
F_5 ( V_94 , V_77 & 0x7fffffff ) ;
F_5 ( V_95 , V_78 ) ;
} else {
V_77 += V_78 + V_71 + V_72 ;
V_78 = V_71 ;
F_5 ( V_92 , V_77 & 0xfffffff ) ;
F_5 ( V_93 , V_78 ) ;
V_77 += V_78 ;
V_78 = V_72 ;
F_5 ( V_94 , V_77 & 0xfffffff ) ;
F_5 ( V_95 , V_78 ) ;
}
F_11 ( V_96 , 0x0 , ~ 0x100 ) ;
F_11 ( V_97 , V_98 ,
~ V_98 ) ;
}
static bool F_38 ( void * V_67 )
{
struct V_3 * V_4 = (struct V_3 * ) V_67 ;
T_2 V_99 = 0 ;
V_99 |= ( V_4 -> V_5 . V_44 & V_66 ) ? 0 : V_100 ;
V_99 |= ( V_4 -> V_5 . V_44 & V_57 ) ? 0 : V_101 ;
return ! ( F_2 ( V_102 ) & V_99 ) ;
}
static int F_35 ( void * V_67 )
{
unsigned V_25 ;
struct V_3 * V_4 = (struct V_3 * ) V_67 ;
for ( V_25 = 0 ; V_25 < V_4 -> V_103 ; V_25 ++ )
if ( F_38 ( V_67 ) )
return 0 ;
return - V_32 ;
}
static int F_39 ( void * V_67 )
{
struct V_3 * V_4 = (struct V_3 * ) V_67 ;
T_2 V_99 = 0 ;
V_99 |= ( V_4 -> V_5 . V_44 & V_66 ) ? 0 : V_104 ;
V_99 |= ( V_4 -> V_5 . V_44 & V_57 ) ? 0 : V_105 ;
F_11 ( V_106 , V_99 ,
~ ( V_104 |
V_105 ) ) ;
F_9 ( 5 ) ;
return F_12 ( V_4 ) ;
}
static int F_40 ( struct V_3 * V_4 ,
struct V_107 * V_108 ,
unsigned type ,
enum V_109 V_110 )
{
T_1 V_111 = 0 ;
if ( V_110 == V_112 )
V_111 |= V_98 ;
F_11 ( V_97 , V_111 , ~ V_98 ) ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 ,
struct V_107 * V_108 ,
struct V_113 * V_114 )
{
F_42 ( L_6 ) ;
F_11 ( V_115 ,
V_116 ,
~ V_116 ) ;
switch ( V_114 -> V_117 ) {
case 0 :
case 1 :
F_43 ( & V_4 -> V_5 . V_2 [ V_114 -> V_117 ] ) ;
break;
default:
F_10 ( L_7 ,
V_114 -> V_118 , V_114 -> V_117 ) ;
break;
}
return 0 ;
}
static void F_44 ( struct V_3 * V_4 , bool V_119 )
{
T_2 V_12 = F_19 ( V_120 ) ;
if ( V_119 )
V_12 |= V_121 ;
else
V_12 &= ~ V_121 ;
F_45 ( V_120 , V_12 ) ;
}
static int F_46 ( void * V_67 ,
enum V_122 V_110 )
{
struct V_3 * V_4 = (struct V_3 * ) V_67 ;
bool V_119 = ( V_110 == V_123 ) ? true : false ;
int V_25 ;
if ( V_4 -> V_48 == V_55 )
F_44 ( V_4 , V_119 ) ;
if ( ! ( V_4 -> V_52 & V_53 ) )
return 0 ;
F_14 ( & V_4 -> V_43 ) ;
for ( V_25 = 0 ; V_25 < 2 ; V_25 ++ ) {
if ( V_4 -> V_5 . V_44 & ( 1 << V_25 ) )
continue;
if ( V_25 == 0 )
F_11 ( V_45 , 0 ,
~ V_46 ) ;
else
F_11 ( V_45 ,
V_46 ,
~ V_46 ) ;
if ( V_119 ) {
T_1 V_13 = F_2 ( V_79 ) ;
V_13 &= ~ ( 0xf | 0xff0 ) ;
V_13 |= ( ( 0x0 << 0 ) | ( 0x04 << 4 ) ) ;
F_5 ( V_79 , V_13 ) ;
V_13 = F_2 ( V_18 ) ;
V_13 &= ~ ( 0xf | 0xff0 ) ;
V_13 |= ( ( 0x0 << 0 ) | ( 0x04 << 4 ) ) ;
F_5 ( V_18 , V_13 ) ;
}
F_7 ( V_4 , V_119 ) ;
}
F_11 ( V_45 , 0 , ~ V_46 ) ;
F_16 ( & V_4 -> V_43 ) ;
return 0 ;
}
static int F_47 ( void * V_67 ,
enum V_124 V_110 )
{
struct V_3 * V_4 = (struct V_3 * ) V_67 ;
if ( ! ( V_4 -> V_125 & V_126 ) )
return 0 ;
if ( V_110 == V_127 )
return 0 ;
else
return F_12 ( V_4 ) ;
}
static void F_21 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_2 [ 0 ] . V_128 = & V_129 ;
V_4 -> V_5 . V_2 [ 1 ] . V_128 = & V_129 ;
}
static void F_22 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_69 . V_130 = 1 ;
V_4 -> V_5 . V_69 . V_128 = & V_131 ;
}
