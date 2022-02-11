static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
if ( ! V_2 -> V_10 )
return;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
F_3 ( V_12 , V_9 ) ;
F_3 ( V_13 , V_3 -> V_14 [ V_9 ] ) ;
F_3 ( V_13 , V_3 -> V_15 [ V_9 ] ) ;
F_3 ( V_13 , V_3 -> V_16 [ V_9 ] ) ;
}
}
static void F_4 ( struct V_1 * V_2 , int V_17 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_18 , V_19 ;
switch ( V_17 ) {
case V_20 :
V_18 = 0x00 ;
V_19 = 0x00 ;
break;
case V_21 :
V_18 = 0x20 ;
V_19 = 0x02 ;
break;
case V_22 :
V_18 = 0x20 ;
V_19 = 0x04 ;
break;
case V_23 :
V_18 = 0x20 ;
V_19 = 0x06 ;
break;
default:
return;
}
F_3 ( V_24 , 0x1 ) ;
V_18 |= F_5 ( V_25 ) & ~ 0x20 ;
F_6 ( 0x1 , V_18 ) ;
F_3 ( V_26 , 0xe ) ;
V_19 |= F_5 ( V_27 ) & ~ 0x06 ;
F_7 ( 0xe , V_19 ) ;
}
static bool F_8 ( struct V_1 * V_2 ,
const struct V_28 * V_17 ,
struct V_28 * V_29 )
{
return true ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_30 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_2 V_31 ;
T_1 V_32 ;
V_31 = V_30 >> 2 ;
F_10 ( 0x0c , ( T_1 ) ( ( V_31 >> 8 ) & 0xff ) ) ;
F_10 ( 0x0d , ( T_1 ) ( V_31 & 0xff ) ) ;
F_3 ( V_33 , 0x1b ) ;
V_32 = F_5 ( V_34 ) ;
V_32 &= 0xf2 ;
V_32 |= ( V_31 >> 16 ) & 0x01 ;
V_32 |= ( V_31 >> 15 ) & 0x0c ;
F_10 ( 0x1b , V_32 ) ;
F_3 ( V_33 , 0x1d ) ;
V_32 = F_5 ( V_34 ) ;
V_32 &= 0x7f ;
V_32 |= ( V_31 >> 12 ) & 0x80 ;
F_10 ( 0x1d , V_32 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
int V_37 , int V_38 , int V_39 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
int V_46 ;
T_3 V_47 ;
if ( ! V_39 && V_36 ) {
V_43 = F_12 ( V_36 ) ;
V_41 = V_43 -> V_41 ;
V_45 = F_13 ( V_41 ) ;
V_46 = F_14 ( V_45 , false ) ;
if ( V_46 )
return V_46 ;
F_15 ( V_45 ) ;
F_16 ( V_45 ) ;
}
V_43 = F_12 ( V_2 -> V_48 -> V_36 ) ;
V_41 = V_43 -> V_41 ;
V_45 = F_13 ( V_41 ) ;
V_46 = F_14 ( V_45 , false ) ;
if ( V_46 )
return V_46 ;
V_46 = F_17 ( V_45 , V_49 , & V_47 ) ;
if ( V_46 ) {
F_16 ( V_45 ) ;
return V_46 ;
}
if ( & V_7 -> V_50 . V_51 -> V_52 == V_43 ) {
V_46 = F_18 ( & V_45 -> V_45 , 0 , V_45 -> V_45 . V_53 , & V_45 -> V_54 ) ;
if ( V_46 )
F_19 ( L_1 ) ;
}
F_16 ( V_45 ) ;
F_9 ( V_2 , ( T_2 ) V_47 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_37 , int V_38 ,
struct V_35 * V_55 )
{
return F_11 ( V_2 , V_55 , V_37 , V_38 , 0 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_28 * V_17 ,
struct V_28 * V_29 ,
int V_37 , int V_38 , struct V_35 * V_55 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_56 , V_57 , V_58 , V_59 ;
int V_60 , V_61 ;
int V_32 ;
int V_62 = 0 , V_63 = 0 ;
V_58 = V_17 -> V_58 / 8 ;
V_57 = V_17 -> V_64 / 8 ;
V_56 = V_17 -> V_65 / 8 ;
V_59 = V_17 -> V_66 / 8 ;
V_60 = V_17 -> V_60 ;
V_61 = V_17 -> V_67 ;
V_61 -= 1 ;
V_60 -= 2 ;
V_58 -= 5 ;
V_59 -= 1 ;
V_56 += 1 ;
V_57 += 1 ;
F_10 ( V_68 , 0x20 ) ;
F_10 ( V_69 , V_58 ) ;
F_10 ( V_70 , V_59 ) ;
F_10 ( V_71 , V_56 ) ;
F_10 ( V_72 , V_57 ) ;
F_10 ( V_73 , V_60 & 0xff ) ;
F_10 ( V_74 , V_61 & 0xff ) ;
V_32 = 0x40 ;
if ( ( V_61 + 1 ) & 512 )
V_32 |= 0x20 ;
F_10 ( V_75 , V_32 ) ;
V_32 = 16 ;
if ( V_60 & 256 )
V_32 |= 1 ;
if ( V_61 & 256 )
V_32 |= 2 ;
if ( ( V_61 + 1 ) & 256 )
V_32 |= 8 ;
if ( V_60 & 512 )
V_32 |= 32 ;
if ( V_61 & 512 )
V_32 |= 64 ;
F_10 ( V_76 , V_32 ) ;
V_32 = 0 ;
if ( ( V_58 + 5 ) & 64 )
V_32 |= 16 ;
if ( ( V_58 + 5 ) & 128 )
V_32 |= 32 ;
if ( V_60 & 256 )
V_32 |= 64 ;
if ( V_60 & 512 )
V_32 |= 128 ;
F_10 ( V_77 , V_32 ) ;
F_10 ( V_78 , 0x03 ) ;
F_3 ( V_24 , 0x7 ) ;
V_62 = F_5 ( V_25 ) ;
V_62 &= 0xe0 ;
V_63 = 0 ;
switch ( V_2 -> V_48 -> V_36 -> V_79 ) {
case 8 :
V_62 |= 0x11 ;
break;
case 16 :
V_62 |= 0x17 ;
V_63 = 0xc1 ;
break;
case 24 :
V_62 |= 0x15 ;
V_63 = 0xc5 ;
break;
case 32 :
V_62 |= 0x19 ;
V_63 = 0xc5 ;
break;
default:
return - 1 ;
}
F_6 ( 0x7 , V_62 ) ;
V_32 = V_2 -> V_48 -> V_36 -> V_80 [ 0 ] / 8 ;
F_10 ( V_81 , V_32 ) ;
V_32 = 0x22 ;
V_32 |= ( V_2 -> V_48 -> V_36 -> V_80 [ 0 ] >> 7 ) & 0x10 ;
V_32 |= ( V_2 -> V_48 -> V_36 -> V_80 [ 0 ] >> 6 ) & 0x40 ;
F_10 ( 0x1b , V_32 ) ;
F_7 ( V_82 , 0x40 ) ;
F_7 ( V_83 , 0x01 ) ;
F_22 ( V_63 ) ;
F_11 ( V_2 , V_55 , V_37 , V_38 , 0 ) ;
F_23 ( 0x20 , 0x3c0 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
}
static void F_25 ( struct V_1 * V_2 )
{
}
static void F_26 ( struct V_1 * V_2 , T_4 * V_84 , T_4 * V_85 ,
T_4 * V_86 , T_5 V_87 , T_5 V_88 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_9 ;
if ( V_88 != V_11 )
return;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
V_3 -> V_14 [ V_9 ] = V_84 [ V_9 ] ;
V_3 -> V_15 [ V_9 ] = V_85 [ V_9 ] ;
V_3 -> V_16 [ V_9 ] = V_86 [ V_9 ] ;
}
F_1 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_3 ) ;
}
static void F_30 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_3 * V_3 ;
int V_9 ;
V_3 = F_31 ( sizeof( struct V_3 ) +
( V_89 * sizeof( struct V_90 * ) ) ,
V_91 ) ;
if ( V_3 == NULL )
return;
F_32 ( V_5 , & V_3 -> V_92 , & V_93 ) ;
F_33 ( & V_3 -> V_92 , V_11 ) ;
V_7 -> V_50 . V_2 = V_3 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
V_3 -> V_14 [ V_9 ] = V_9 ;
V_3 -> V_15 [ V_9 ] = V_9 ;
V_3 -> V_16 [ V_9 ] = V_9 ;
}
F_34 ( & V_3 -> V_92 , & V_94 ) ;
}
void F_35 ( struct V_1 * V_2 , T_4 V_84 , T_4 V_85 ,
T_4 V_86 , int V_95 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_14 [ V_95 ] = V_84 ;
V_3 -> V_15 [ V_95 ] = V_85 ;
V_3 -> V_16 [ V_95 ] = V_86 ;
}
void F_36 ( struct V_1 * V_2 , T_4 * V_84 , T_4 * V_85 ,
T_4 * V_86 , int V_95 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_84 = V_3 -> V_14 [ V_95 ] ;
* V_85 = V_3 -> V_15 [ V_95 ] ;
* V_86 = V_3 -> V_16 [ V_95 ] ;
}
static bool F_37 ( struct V_96 * V_97 ,
const struct V_28 * V_17 ,
struct V_28 * V_29 )
{
return true ;
}
static void F_38 ( struct V_96 * V_97 ,
struct V_28 * V_17 ,
struct V_28 * V_29 )
{
}
static void F_39 ( struct V_96 * V_97 , int V_98 )
{
return;
}
static void F_40 ( struct V_96 * V_97 )
{
}
static void F_41 ( struct V_96 * V_97 )
{
}
static void F_42 ( struct V_96 * V_97 )
{
struct V_99 * V_99 = F_43 ( V_97 ) ;
F_44 ( V_97 ) ;
F_29 ( V_99 ) ;
}
static struct V_96 * F_45 ( struct V_4 * V_5 )
{
struct V_96 * V_97 ;
struct V_99 * V_99 ;
V_99 = F_31 ( sizeof( struct V_99 ) , V_91 ) ;
if ( ! V_99 )
return NULL ;
V_97 = & V_99 -> V_92 ;
V_97 -> V_100 = 0x1 ;
F_46 ( V_5 , V_97 , & V_101 ,
V_102 ) ;
F_47 ( V_97 , & V_103 ) ;
return V_97 ;
}
static int F_48 ( struct V_90 * V_104 )
{
int V_105 ;
if ( V_106 <= 24 ) {
V_105 = F_49 ( V_104 , 1280 , 1024 ) ;
F_50 ( V_104 , 1024 , 768 ) ;
} else {
V_105 = F_49 ( V_104 , 800 , 600 ) ;
F_50 ( V_104 , 800 , 600 ) ;
}
return V_105 ;
}
static struct V_96 * F_51 ( struct V_90
* V_104 )
{
int V_107 = V_104 -> V_108 [ 0 ] ;
if ( V_107 )
return F_52 ( V_104 -> V_5 , V_107 ) ;
return NULL ;
}
static enum V_109 F_53 ( struct V_90
* V_104 , bool V_110 )
{
return V_111 ;
}
static void F_54 ( struct V_90 * V_104 )
{
F_55 ( V_104 ) ;
F_29 ( V_104 ) ;
}
static struct V_90 * F_56 ( struct V_4 * V_5 )
{
struct V_90 * V_104 ;
struct V_112 * V_112 ;
V_112 = F_31 ( sizeof( struct V_112 ) , V_91 ) ;
if ( ! V_112 )
return NULL ;
V_104 = & V_112 -> V_92 ;
F_57 ( V_5 , V_104 ,
& V_113 , V_114 ) ;
F_58 ( V_104 , & V_115 ) ;
F_59 ( V_104 ) ;
return V_104 ;
}
int F_60 ( struct V_6 * V_7 )
{
struct V_96 * V_97 ;
struct V_90 * V_104 ;
int V_46 ;
F_61 ( V_7 -> V_5 ) ;
V_7 -> V_50 . V_116 = true ;
V_7 -> V_5 -> V_117 . V_118 = V_119 ;
V_7 -> V_5 -> V_117 . V_120 = V_121 ;
V_7 -> V_5 -> V_117 . V_122 = V_7 -> V_123 . V_124 ;
V_7 -> V_5 -> V_117 . V_125 = 24 ;
V_7 -> V_5 -> V_117 . V_126 = 0 ;
F_30 ( V_7 -> V_5 ) ;
V_97 = F_45 ( V_7 -> V_5 ) ;
if ( ! V_97 ) {
F_19 ( L_2 ) ;
return - 1 ;
}
V_104 = F_56 ( V_7 -> V_5 ) ;
if ( ! V_104 ) {
F_19 ( L_3 ) ;
return - 1 ;
}
F_62 ( V_104 , V_97 ) ;
V_46 = F_63 ( V_7 ) ;
if ( V_46 ) {
F_19 ( L_4 ) ;
return V_46 ;
}
return 0 ;
}
void F_64 ( struct V_6 * V_7 )
{
F_65 ( V_7 ) ;
if ( V_7 -> V_50 . V_116 ) {
F_66 ( V_7 -> V_5 ) ;
V_7 -> V_50 . V_116 = false ;
}
}
