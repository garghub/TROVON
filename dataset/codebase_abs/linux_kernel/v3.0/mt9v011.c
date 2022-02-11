static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned char V_4 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
T_1 V_7 ;
int V_8 , V_9 ;
V_8 = F_5 ( V_6 , & V_4 , 1 ) ;
if ( V_8 != 1 )
F_6 ( 0 , V_10 , V_3 ,
L_1 , V_8 ) ;
F_7 ( 10 ) ;
V_8 = F_8 ( V_6 , ( char * ) & V_7 , 2 ) ;
if ( V_8 != 2 )
F_6 ( 0 , V_10 , V_3 ,
L_2 , V_8 ) ;
V_9 = F_9 ( V_7 ) ;
F_6 ( 2 , V_10 , V_3 , L_3 , V_4 , V_9 ) ;
return V_9 ;
}
static void F_10 ( struct V_2 * V_3 , unsigned char V_4 ,
T_2 V_11 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
unsigned char V_7 [ 3 ] ;
int V_8 ;
V_7 [ 0 ] = V_4 ;
V_7 [ 1 ] = V_11 >> 8 ;
V_7 [ 2 ] = V_11 & 0xff ;
F_6 ( 2 , V_10 , V_3 ,
L_4 , V_7 [ 0 ] , V_11 ) ;
V_8 = F_5 ( V_6 , V_7 , 3 ) ;
if ( V_8 != 3 )
F_6 ( 0 , V_10 , V_3 ,
L_5 , V_8 ) ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_2 V_13 , V_14 , V_15 , V_16 ;
V_13 = V_12 -> V_17 ;
V_14 = V_12 -> V_17 ;
V_15 = V_12 -> V_17 +
V_12 -> V_17 * V_12 -> V_18 / ( 1 << 9 ) ;
V_16 = V_12 -> V_17 +
V_12 -> V_17 * V_12 -> V_18 / ( 1 << 9 ) ;
F_10 ( V_3 , V_19 , V_13 ) ;
F_10 ( V_3 , V_20 , V_13 ) ;
F_10 ( V_3 , V_21 , V_15 ) ;
F_10 ( V_3 , V_22 , V_16 ) ;
}
static void F_12 ( struct V_2 * V_3 , T_3 * V_23 , T_3 * V_24 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned V_25 , V_26 , V_27 , V_28 , V_29 ;
unsigned V_30 , V_31 ;
T_4 V_32 ;
unsigned V_33 ;
V_25 = F_3 ( V_3 , V_34 ) ;
V_26 = F_3 ( V_3 , V_35 ) ;
V_27 = F_3 ( V_3 , V_36 ) ;
V_28 = F_3 ( V_3 , V_37 ) ;
V_29 = F_3 ( V_3 , V_38 ) ;
V_30 = ( V_26 + 113 + V_27 ) * ( V_29 + 2 ) ;
V_31 = V_30 * ( V_25 + V_28 + 1 ) ;
V_32 = V_12 -> V_39 * 1000l ;
F_13 ( V_32 , V_31 ) ;
V_33 = V_32 ;
F_6 ( 1 , V_10 , V_3 , L_6 ,
V_33 / 1000 , V_33 % 1000 , V_31 ) ;
if ( V_23 && V_24 ) {
* V_23 = 1000 ;
* V_24 = ( T_3 ) V_32 ;
}
}
static T_2 F_14 ( struct V_2 * V_3 , T_3 V_23 , T_3 V_24 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned V_25 , V_26 , V_27 , V_28 ;
unsigned V_30 , V_40 ;
T_4 V_31 , V_29 ;
if ( ! V_23 || ! V_24 )
return 0 ;
V_25 = F_3 ( V_3 , V_34 ) ;
V_26 = F_3 ( V_3 , V_35 ) ;
V_27 = F_3 ( V_3 , V_36 ) ;
V_28 = F_3 ( V_3 , V_37 ) ;
V_30 = V_26 + 113 + V_27 ;
V_40 = V_25 + V_28 + 1 ;
V_31 = V_12 -> V_39 * ( ( T_4 ) V_23 ) ;
V_31 += V_24 / 2 ;
F_13 ( V_31 , V_24 ) ;
V_29 = V_31 ;
F_13 ( V_29 , V_30 * V_40 ) ;
if ( V_29 < 2 )
V_29 = 0 ;
else
V_29 -= 2 ;
if ( V_29 > 15 )
return 15 ;
return ( T_2 ) V_29 ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned V_41 , V_42 ;
V_42 = 14 + ( 640 - V_12 -> V_26 ) / 2 ;
F_10 ( V_3 , V_43 , V_42 ) ;
F_10 ( V_3 , V_35 , V_12 -> V_26 ) ;
F_10 ( V_3 , V_36 , 771 - V_12 -> V_26 ) ;
V_41 = 8 + ( 480 - V_12 -> V_25 ) / 2 ;
F_10 ( V_3 , V_44 , V_41 ) ;
F_10 ( V_3 , V_34 , V_12 -> V_25 ) ;
F_10 ( V_3 , V_37 , 508 - V_12 -> V_25 ) ;
F_12 ( V_3 , NULL , NULL ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned V_45 = 0x1000 ;
if ( V_12 -> V_46 )
V_45 |= 0x4000 ;
if ( V_12 -> V_47 )
V_45 |= 0x8000 ;
F_10 ( V_3 , V_48 , V_45 ) ;
}
static int F_17 ( struct V_2 * V_3 , T_3 V_9 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < F_18 ( V_50 ) ; V_49 ++ )
F_10 ( V_3 , V_50 [ V_49 ] . V_51 ,
V_50 [ V_49 ] . V_11 ) ;
F_11 ( V_3 ) ;
F_15 ( V_3 ) ;
F_16 ( V_3 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_52 * V_53 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_6 ( 1 , V_10 , V_3 , L_7 ) ;
switch ( V_53 -> V_54 ) {
case V_55 :
V_53 -> V_11 = V_12 -> V_17 ;
return 0 ;
case V_56 :
V_53 -> V_11 = V_12 -> V_57 ;
return 0 ;
case V_58 :
V_53 -> V_11 = V_12 -> V_18 ;
return 0 ;
case V_59 :
V_53 -> V_11 = V_12 -> V_46 ? 1 : 0 ;
return 0 ;
case V_60 :
V_53 -> V_11 = V_12 -> V_47 ? 1 : 0 ;
return 0 ;
}
return - V_61 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_62 * V_63 )
{
int V_49 ;
F_6 ( 1 , V_10 , V_3 , L_8 ) ;
for ( V_49 = 0 ; V_49 < F_18 ( V_64 ) ; V_49 ++ )
if ( V_63 -> V_54 && V_63 -> V_54 == V_64 [ V_49 ] . V_54 ) {
memcpy ( V_63 , & ( V_64 [ V_49 ] ) ,
sizeof( * V_63 ) ) ;
return 0 ;
}
return - V_61 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_52 * V_53 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_5 V_49 , V_65 ;
V_65 = F_18 ( V_64 ) ;
for ( V_49 = 0 ; V_49 < V_65 ; V_49 ++ ) {
if ( V_53 -> V_54 != V_64 [ V_49 ] . V_54 )
continue;
if ( V_53 -> V_11 < V_64 [ V_49 ] . V_66 ||
V_53 -> V_11 > V_64 [ V_49 ] . V_67 )
return - V_68 ;
F_6 ( 1 , V_10 , V_3 , L_9 ,
V_53 -> V_54 , V_53 -> V_11 ) ;
break;
}
switch ( V_53 -> V_54 ) {
case V_55 :
V_12 -> V_17 = V_53 -> V_11 ;
break;
case V_56 :
V_12 -> V_57 = V_53 -> V_11 ;
break;
case V_58 :
V_12 -> V_18 = V_53 -> V_11 ;
break;
case V_59 :
V_12 -> V_46 = V_53 -> V_11 ;
F_16 ( V_3 ) ;
return 0 ;
case V_60 :
V_12 -> V_47 = V_53 -> V_11 ;
F_16 ( V_3 ) ;
return 0 ;
default:
return - V_61 ;
}
F_11 ( V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , unsigned V_69 ,
enum V_70 * V_71 )
{
if ( V_69 > 0 )
return - V_61 ;
* V_71 = V_72 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , struct V_73 * V_74 )
{
if ( V_74 -> V_71 != V_72 )
return - V_61 ;
F_24 ( & V_74 -> V_26 , 48 , 639 , 1 ,
& V_74 -> V_25 , 32 , 480 , 1 , 0 ) ;
V_74 -> V_75 = V_76 ;
V_74 -> V_77 = V_78 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_79 * V_80 )
{
struct V_81 * V_82 = & V_80 -> V_83 . V_84 ;
if ( V_80 -> type != V_85 )
return - V_61 ;
memset ( V_82 , 0 , sizeof( struct V_81 ) ) ;
V_82 -> V_86 = V_87 ;
F_12 ( V_3 ,
& V_82 -> V_88 . V_23 ,
& V_82 -> V_88 . V_24 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_79 * V_80 )
{
struct V_81 * V_82 = & V_80 -> V_83 . V_84 ;
struct V_89 * V_90 = & V_82 -> V_88 ;
T_2 V_29 ;
if ( V_80 -> type != V_85 )
return - V_61 ;
if ( V_82 -> V_91 != 0 )
return - V_61 ;
V_29 = F_14 ( V_3 , V_90 -> V_23 , V_90 -> V_24 ) ;
F_10 ( V_3 , V_38 , V_29 ) ;
F_6 ( 1 , V_10 , V_3 , L_10 , V_29 ) ;
F_12 ( V_3 , & V_90 -> V_23 , & V_90 -> V_24 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_73 * V_74 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
int V_8 ;
V_8 = F_23 ( V_3 , V_74 ) ;
if ( V_8 < 0 )
return - V_61 ;
V_12 -> V_26 = V_74 -> V_26 ;
V_12 -> V_25 = V_74 -> V_25 ;
F_15 ( V_3 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_92 * V_51 )
{
struct V_5 * V_93 = F_4 ( V_3 ) ;
if ( ! F_29 ( V_93 , & V_51 -> V_94 ) )
return - V_61 ;
if ( ! F_30 ( V_95 ) )
return - V_96 ;
V_51 -> V_9 = F_3 ( V_3 , V_51 -> V_51 & 0xff ) ;
V_51 -> V_97 = 2 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_92 * V_51 )
{
struct V_5 * V_93 = F_4 ( V_3 ) ;
if ( ! F_29 ( V_93 , & V_51 -> V_94 ) )
return - V_61 ;
if ( ! F_30 ( V_95 ) )
return - V_96 ;
F_10 ( V_3 , V_51 -> V_51 & 0xff , V_51 -> V_9 & 0xffff ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_98 * V_99 )
{
T_2 V_100 ;
struct V_5 * V_93 = F_4 ( V_3 ) ;
V_100 = F_3 ( V_3 , V_101 ) ;
return F_33 ( V_93 , V_99 , V_102 ,
V_100 ) ;
}
static int F_34 ( struct V_5 * V_6 ,
const struct V_103 * V_54 )
{
T_2 V_100 ;
struct V_1 * V_12 ;
struct V_2 * V_3 ;
if ( ! F_35 ( V_6 -> V_104 ,
V_105 | V_106 ) )
return - V_107 ;
V_12 = F_36 ( sizeof( struct V_1 ) , V_108 ) ;
if ( ! V_12 )
return - V_109 ;
V_3 = & V_12 -> V_3 ;
F_37 ( V_3 , V_6 , & V_110 ) ;
V_100 = F_3 ( V_3 , V_101 ) ;
if ( ( V_100 != V_111 ) &&
( V_100 != V_112 ) ) {
F_38 ( V_3 , L_11 ,
V_100 ) ;
F_39 ( V_12 ) ;
return - V_61 ;
}
V_12 -> V_17 = 0x0024 ;
V_12 -> V_26 = 640 ;
V_12 -> V_25 = 480 ;
V_12 -> V_39 = 27000000 ;
if ( V_6 -> V_113 . V_114 ) {
struct V_115 * V_116 = V_6 -> V_113 . V_114 ;
V_12 -> V_39 = V_116 -> V_39 ;
F_6 ( 1 , V_10 , V_3 , L_12 ,
V_12 -> V_39 / 1000000 , ( V_12 -> V_39 / 1000 ) % 1000 ) ;
}
F_40 ( V_6 , L_13 ,
V_6 -> V_4 << 1 , V_6 -> V_104 -> V_117 , V_100 ) ;
return 0 ;
}
static int F_41 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_42 ( V_6 ) ;
F_6 ( 1 , V_10 , V_3 ,
L_14 ,
V_6 -> V_4 << 1 ) ;
F_43 ( V_3 ) ;
F_39 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_6 int F_44 ( void )
{
return F_45 ( & V_118 ) ;
}
static T_7 void F_46 ( void )
{
F_47 ( & V_118 ) ;
}
