static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_9 , V_10 ;
switch ( V_3 ) {
case V_11 :
V_9 = 0x00 ;
V_10 = 0x00 ;
break;
case V_12 :
V_9 = 0x20 ;
V_10 = 0x02 ;
break;
case V_13 :
V_9 = 0x20 ;
V_10 = 0x04 ;
break;
case V_14 :
V_9 = 0x20 ;
V_10 = 0x06 ;
break;
default:
return;
}
F_2 ( V_15 , 0x1 ) ;
V_9 |= F_3 ( V_16 ) & ~ 0x20 ;
F_4 ( 0x1 , V_9 ) ;
F_2 ( V_17 , 0xe ) ;
V_10 |= F_3 ( V_18 ) & ~ 0x06 ;
F_5 ( 0xe , V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_19 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_2 V_20 ;
T_1 V_21 ;
V_20 = V_19 >> 2 ;
F_7 ( 0x0c , ( T_1 ) ( ( V_20 >> 8 ) & 0xff ) ) ;
F_7 ( 0x0d , ( T_1 ) ( V_20 & 0xff ) ) ;
F_2 ( V_22 , 0x1b ) ;
V_21 = F_3 ( V_23 ) ;
V_21 &= 0xf2 ;
V_21 |= ( V_20 >> 16 ) & 0x01 ;
V_21 |= ( V_20 >> 15 ) & 0x0c ;
F_7 ( 0x1b , V_21 ) ;
F_2 ( V_22 , 0x1d ) ;
V_21 = F_3 ( V_23 ) ;
V_21 &= 0x7f ;
V_21 |= ( V_20 >> 12 ) & 0x80 ;
F_7 ( 0x1d , V_21 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
int V_26 , int V_27 , int V_28 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_35 ;
T_3 V_36 ;
if ( ! V_28 && V_25 ) {
V_32 = F_9 ( V_25 ) ;
V_30 = V_32 -> V_30 ;
V_34 = F_10 ( V_30 ) ;
V_35 = F_11 ( V_34 , false ) ;
if ( V_35 )
return V_35 ;
F_12 ( V_34 ) ;
F_13 ( V_34 ) ;
}
V_32 = F_9 ( V_2 -> V_37 -> V_25 ) ;
V_30 = V_32 -> V_30 ;
V_34 = F_10 ( V_30 ) ;
V_35 = F_11 ( V_34 , false ) ;
if ( V_35 )
return V_35 ;
V_35 = F_14 ( V_34 , V_38 , & V_36 ) ;
if ( V_35 ) {
F_13 ( V_34 ) ;
return V_35 ;
}
if ( & V_7 -> V_39 . V_40 -> V_41 == V_32 ) {
V_35 = F_15 ( & V_34 -> V_34 , 0 , V_34 -> V_34 . V_42 , & V_34 -> V_43 ) ;
if ( V_35 )
F_16 ( L_1 ) ;
}
F_13 ( V_34 ) ;
F_6 ( V_2 , ( T_2 ) V_36 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_26 , int V_27 ,
struct V_24 * V_44 )
{
return F_8 ( V_2 , V_44 , V_26 , V_27 , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_45 * V_3 ,
struct V_45 * V_46 ,
int V_26 , int V_27 , struct V_24 * V_44 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_24 * V_25 = V_2 -> V_37 -> V_25 ;
int V_47 , V_48 , V_49 , V_50 ;
int V_51 , V_52 ;
int V_21 ;
int V_53 = 0 , V_54 = 0 ;
V_49 = V_3 -> V_49 / 8 ;
V_48 = V_3 -> V_55 / 8 ;
V_47 = V_3 -> V_56 / 8 ;
V_50 = V_3 -> V_57 / 8 ;
V_51 = V_3 -> V_51 ;
V_52 = V_3 -> V_58 ;
V_52 -= 1 ;
V_51 -= 2 ;
V_49 -= 5 ;
V_50 -= 1 ;
V_47 += 1 ;
V_48 += 1 ;
F_7 ( V_59 , 0x20 ) ;
F_7 ( V_60 , V_49 ) ;
F_7 ( V_61 , V_50 ) ;
F_7 ( V_62 , V_47 ) ;
F_7 ( V_63 , V_48 ) ;
F_7 ( V_64 , V_51 & 0xff ) ;
F_7 ( V_65 , V_52 & 0xff ) ;
V_21 = 0x40 ;
if ( ( V_52 + 1 ) & 512 )
V_21 |= 0x20 ;
F_7 ( V_66 , V_21 ) ;
V_21 = 16 ;
if ( V_51 & 256 )
V_21 |= 1 ;
if ( V_52 & 256 )
V_21 |= 2 ;
if ( ( V_52 + 1 ) & 256 )
V_21 |= 8 ;
if ( V_51 & 512 )
V_21 |= 32 ;
if ( V_52 & 512 )
V_21 |= 64 ;
F_7 ( V_67 , V_21 ) ;
V_21 = 0 ;
if ( ( V_49 + 5 ) & 64 )
V_21 |= 16 ;
if ( ( V_49 + 5 ) & 128 )
V_21 |= 32 ;
if ( V_51 & 256 )
V_21 |= 64 ;
if ( V_51 & 512 )
V_21 |= 128 ;
F_7 ( V_68 , V_21 ) ;
F_7 ( V_69 , 0x03 ) ;
F_2 ( V_15 , 0x7 ) ;
V_53 = F_3 ( V_16 ) ;
V_53 &= 0xe0 ;
V_54 = 0 ;
switch ( V_25 -> V_70 -> V_71 [ 0 ] * 8 ) {
case 8 :
V_53 |= 0x11 ;
break;
case 16 :
V_53 |= 0x17 ;
V_54 = 0xc1 ;
break;
case 24 :
V_53 |= 0x15 ;
V_54 = 0xc5 ;
break;
case 32 :
V_53 |= 0x19 ;
V_54 = 0xc5 ;
break;
default:
return - 1 ;
}
F_4 ( 0x7 , V_53 ) ;
V_21 = V_25 -> V_72 [ 0 ] / 8 ;
F_7 ( V_73 , V_21 ) ;
V_21 = 0x22 ;
V_21 |= ( V_25 -> V_72 [ 0 ] >> 7 ) & 0x10 ;
V_21 |= ( V_25 -> V_72 [ 0 ] >> 6 ) & 0x40 ;
F_7 ( 0x1b , V_21 ) ;
F_5 ( V_74 , 0x40 ) ;
F_5 ( V_75 , 0x01 ) ;
F_19 ( V_54 ) ;
F_8 ( V_2 , V_44 , V_26 , V_27 , 0 ) ;
F_20 ( 0x20 , 0x3c0 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
}
static void F_22 ( struct V_1 * V_2 )
{
}
static int F_23 ( struct V_1 * V_2 , T_4 * V_76 , T_4 * V_77 ,
T_4 * V_78 , T_5 V_79 ,
struct V_80 * V_81 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_4 * V_82 , * V_83 , * V_84 ;
int V_85 ;
if ( ! V_2 -> V_86 )
return 0 ;
V_82 = V_2 -> V_87 ;
V_83 = V_82 + V_2 -> V_88 ;
V_84 = V_83 + V_2 -> V_88 ;
for ( V_85 = 0 ; V_85 < V_89 ; V_85 ++ ) {
F_2 ( V_90 , V_85 ) ;
F_2 ( V_91 , * V_82 ++ >> 8 ) ;
F_2 ( V_91 , * V_83 ++ >> 8 ) ;
F_2 ( V_91 , * V_84 ++ >> 8 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_92 * V_92 = F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_92 ) ;
}
static void F_28 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_92 * V_92 ;
V_92 = F_29 ( sizeof( struct V_92 ) +
( V_93 * sizeof( struct V_94 * ) ) ,
V_95 ) ;
if ( V_92 == NULL )
return;
F_30 ( V_5 , & V_92 -> V_96 , & V_97 ) ;
F_31 ( & V_92 -> V_96 , V_89 ) ;
V_7 -> V_39 . V_2 = V_92 ;
F_32 ( & V_92 -> V_96 , & V_98 ) ;
}
static void F_33 ( struct V_99 * V_100 ,
struct V_45 * V_3 ,
struct V_45 * V_46 )
{
}
static void F_34 ( struct V_99 * V_100 , int V_101 )
{
return;
}
static void F_35 ( struct V_99 * V_100 )
{
}
static void F_36 ( struct V_99 * V_100 )
{
}
static void F_37 ( struct V_99 * V_100 )
{
struct V_102 * V_102 = F_38 ( V_100 ) ;
F_39 ( V_100 ) ;
F_27 ( V_102 ) ;
}
static struct V_99 * F_40 ( struct V_4 * V_5 )
{
struct V_99 * V_100 ;
struct V_102 * V_102 ;
V_102 = F_29 ( sizeof( struct V_102 ) , V_95 ) ;
if ( ! V_102 )
return NULL ;
V_100 = & V_102 -> V_96 ;
V_100 -> V_103 = 0x1 ;
F_41 ( V_5 , V_100 , & V_104 ,
V_105 , NULL ) ;
F_42 ( V_100 , & V_106 ) ;
return V_100 ;
}
static int F_43 ( struct V_94 * V_107 )
{
int V_108 ;
if ( V_109 <= 24 ) {
V_108 = F_44 ( V_107 , 1280 , 1024 ) ;
F_45 ( V_107 , 1024 , 768 ) ;
} else {
V_108 = F_44 ( V_107 , 800 , 600 ) ;
F_45 ( V_107 , 800 , 600 ) ;
}
return V_108 ;
}
static struct V_99 * F_46 ( struct V_94
* V_107 )
{
int V_110 = V_107 -> V_111 [ 0 ] ;
if ( V_110 )
return F_47 ( V_107 -> V_5 , V_110 ) ;
return NULL ;
}
static void F_48 ( struct V_94 * V_107 )
{
F_49 ( V_107 ) ;
F_27 ( V_107 ) ;
}
static struct V_94 * F_50 ( struct V_4 * V_5 )
{
struct V_94 * V_107 ;
struct V_112 * V_112 ;
V_112 = F_29 ( sizeof( struct V_112 ) , V_95 ) ;
if ( ! V_112 )
return NULL ;
V_107 = & V_112 -> V_96 ;
F_51 ( V_5 , V_107 ,
& V_113 , V_114 ) ;
F_52 ( V_107 , & V_115 ) ;
F_53 ( V_107 ) ;
return V_107 ;
}
int F_54 ( struct V_6 * V_7 )
{
struct V_99 * V_100 ;
struct V_94 * V_107 ;
int V_35 ;
F_55 ( V_7 -> V_5 ) ;
V_7 -> V_39 . V_116 = true ;
V_7 -> V_5 -> V_117 . V_118 = V_119 ;
V_7 -> V_5 -> V_117 . V_120 = V_121 ;
V_7 -> V_5 -> V_117 . V_122 = V_7 -> V_123 . V_124 ;
V_7 -> V_5 -> V_117 . V_125 = 24 ;
V_7 -> V_5 -> V_117 . V_126 = 0 ;
F_28 ( V_7 -> V_5 ) ;
V_100 = F_40 ( V_7 -> V_5 ) ;
if ( ! V_100 ) {
F_16 ( L_2 ) ;
return - 1 ;
}
V_107 = F_50 ( V_7 -> V_5 ) ;
if ( ! V_107 ) {
F_16 ( L_3 ) ;
return - 1 ;
}
F_56 ( V_107 , V_100 ) ;
V_35 = F_57 ( V_7 ) ;
if ( V_35 ) {
F_16 ( L_4 ) ;
return V_35 ;
}
return 0 ;
}
void F_58 ( struct V_6 * V_7 )
{
F_59 ( V_7 ) ;
if ( V_7 -> V_39 . V_116 ) {
F_60 ( V_7 -> V_5 ) ;
V_7 -> V_39 . V_116 = false ;
}
}
