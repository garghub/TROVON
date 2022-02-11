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
static void F_8 ( struct V_1 * V_2 , unsigned V_28 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_2 V_29 ;
T_1 V_30 ;
V_29 = V_28 >> 2 ;
F_9 ( 0x0c , ( T_1 ) ( ( V_29 >> 8 ) & 0xff ) ) ;
F_9 ( 0x0d , ( T_1 ) ( V_29 & 0xff ) ) ;
F_3 ( V_31 , 0x1b ) ;
V_30 = F_5 ( V_32 ) ;
V_30 &= 0xf2 ;
V_30 |= ( V_29 >> 16 ) & 0x01 ;
V_30 |= ( V_29 >> 15 ) & 0x0c ;
F_9 ( 0x1b , V_30 ) ;
F_3 ( V_31 , 0x1d ) ;
V_30 = F_5 ( V_32 ) ;
V_30 &= 0x7f ;
V_30 |= ( V_29 >> 12 ) & 0x80 ;
F_9 ( 0x1d , V_30 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
int V_35 , int V_36 , int V_37 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
int V_44 ;
T_3 V_45 ;
if ( ! V_37 && V_34 ) {
V_41 = F_11 ( V_34 ) ;
V_39 = V_41 -> V_39 ;
V_43 = F_12 ( V_39 ) ;
V_44 = F_13 ( V_43 , false ) ;
if ( V_44 )
return V_44 ;
F_14 ( V_43 ) ;
F_15 ( V_43 ) ;
}
V_41 = F_11 ( V_2 -> V_46 -> V_34 ) ;
V_39 = V_41 -> V_39 ;
V_43 = F_12 ( V_39 ) ;
V_44 = F_13 ( V_43 , false ) ;
if ( V_44 )
return V_44 ;
V_44 = F_16 ( V_43 , V_47 , & V_45 ) ;
if ( V_44 ) {
F_15 ( V_43 ) ;
return V_44 ;
}
if ( & V_7 -> V_48 . V_49 -> V_50 == V_41 ) {
V_44 = F_17 ( & V_43 -> V_43 , 0 , V_43 -> V_43 . V_51 , & V_43 -> V_52 ) ;
if ( V_44 )
F_18 ( L_1 ) ;
}
F_15 ( V_43 ) ;
F_8 ( V_2 , ( T_2 ) V_45 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_35 , int V_36 ,
struct V_33 * V_53 )
{
return F_10 ( V_2 , V_53 , V_35 , V_36 , 0 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_54 * V_17 ,
struct V_54 * V_55 ,
int V_35 , int V_36 , struct V_33 * V_53 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_33 * V_34 = V_2 -> V_46 -> V_34 ;
int V_56 , V_57 , V_58 , V_59 ;
int V_60 , V_61 ;
int V_30 ;
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
F_9 ( V_68 , 0x20 ) ;
F_9 ( V_69 , V_58 ) ;
F_9 ( V_70 , V_59 ) ;
F_9 ( V_71 , V_56 ) ;
F_9 ( V_72 , V_57 ) ;
F_9 ( V_73 , V_60 & 0xff ) ;
F_9 ( V_74 , V_61 & 0xff ) ;
V_30 = 0x40 ;
if ( ( V_61 + 1 ) & 512 )
V_30 |= 0x20 ;
F_9 ( V_75 , V_30 ) ;
V_30 = 16 ;
if ( V_60 & 256 )
V_30 |= 1 ;
if ( V_61 & 256 )
V_30 |= 2 ;
if ( ( V_61 + 1 ) & 256 )
V_30 |= 8 ;
if ( V_60 & 512 )
V_30 |= 32 ;
if ( V_61 & 512 )
V_30 |= 64 ;
F_9 ( V_76 , V_30 ) ;
V_30 = 0 ;
if ( ( V_58 + 5 ) & 64 )
V_30 |= 16 ;
if ( ( V_58 + 5 ) & 128 )
V_30 |= 32 ;
if ( V_60 & 256 )
V_30 |= 64 ;
if ( V_60 & 512 )
V_30 |= 128 ;
F_9 ( V_77 , V_30 ) ;
F_9 ( V_78 , 0x03 ) ;
F_3 ( V_24 , 0x7 ) ;
V_62 = F_5 ( V_25 ) ;
V_62 &= 0xe0 ;
V_63 = 0 ;
switch ( V_34 -> V_79 -> V_80 [ 0 ] * 8 ) {
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
V_30 = V_34 -> V_81 [ 0 ] / 8 ;
F_9 ( V_82 , V_30 ) ;
V_30 = 0x22 ;
V_30 |= ( V_34 -> V_81 [ 0 ] >> 7 ) & 0x10 ;
V_30 |= ( V_34 -> V_81 [ 0 ] >> 6 ) & 0x40 ;
F_9 ( 0x1b , V_30 ) ;
F_7 ( V_83 , 0x40 ) ;
F_7 ( V_84 , 0x01 ) ;
F_21 ( V_63 ) ;
F_10 ( V_2 , V_53 , V_35 , V_36 , 0 ) ;
F_22 ( 0x20 , 0x3c0 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
}
static void F_24 ( struct V_1 * V_2 )
{
}
static int F_25 ( struct V_1 * V_2 , T_4 * V_85 , T_4 * V_86 ,
T_4 * V_87 , T_5 V_88 ,
struct V_89 * V_90 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_88 ; V_9 ++ ) {
V_3 -> V_14 [ V_9 ] = V_85 [ V_9 ] ;
V_3 -> V_15 [ V_9 ] = V_86 [ V_9 ] ;
V_3 -> V_16 [ V_9 ] = V_87 [ V_9 ] ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_3 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_3 * V_3 ;
int V_9 ;
V_3 = F_30 ( sizeof( struct V_3 ) +
( V_91 * sizeof( struct V_92 * ) ) ,
V_93 ) ;
if ( V_3 == NULL )
return;
F_31 ( V_5 , & V_3 -> V_94 , & V_95 ) ;
F_32 ( & V_3 -> V_94 , V_11 ) ;
V_7 -> V_48 . V_2 = V_3 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
V_3 -> V_14 [ V_9 ] = V_9 ;
V_3 -> V_15 [ V_9 ] = V_9 ;
V_3 -> V_16 [ V_9 ] = V_9 ;
}
F_33 ( & V_3 -> V_94 , & V_96 ) ;
}
void F_34 ( struct V_1 * V_2 , T_4 V_85 , T_4 V_86 ,
T_4 V_87 , int V_97 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_14 [ V_97 ] = V_85 ;
V_3 -> V_15 [ V_97 ] = V_86 ;
V_3 -> V_16 [ V_97 ] = V_87 ;
}
void F_35 ( struct V_1 * V_2 , T_4 * V_85 , T_4 * V_86 ,
T_4 * V_87 , int V_97 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_85 = V_3 -> V_14 [ V_97 ] ;
* V_86 = V_3 -> V_15 [ V_97 ] ;
* V_87 = V_3 -> V_16 [ V_97 ] ;
}
static void F_36 ( struct V_98 * V_99 ,
struct V_54 * V_17 ,
struct V_54 * V_55 )
{
}
static void F_37 ( struct V_98 * V_99 , int V_100 )
{
return;
}
static void F_38 ( struct V_98 * V_99 )
{
}
static void F_39 ( struct V_98 * V_99 )
{
}
static void F_40 ( struct V_98 * V_99 )
{
struct V_101 * V_101 = F_41 ( V_99 ) ;
F_42 ( V_99 ) ;
F_28 ( V_101 ) ;
}
static struct V_98 * F_43 ( struct V_4 * V_5 )
{
struct V_98 * V_99 ;
struct V_101 * V_101 ;
V_101 = F_30 ( sizeof( struct V_101 ) , V_93 ) ;
if ( ! V_101 )
return NULL ;
V_99 = & V_101 -> V_94 ;
V_99 -> V_102 = 0x1 ;
F_44 ( V_5 , V_99 , & V_103 ,
V_104 , NULL ) ;
F_45 ( V_99 , & V_105 ) ;
return V_99 ;
}
static int F_46 ( struct V_92 * V_106 )
{
int V_107 ;
if ( V_108 <= 24 ) {
V_107 = F_47 ( V_106 , 1280 , 1024 ) ;
F_48 ( V_106 , 1024 , 768 ) ;
} else {
V_107 = F_47 ( V_106 , 800 , 600 ) ;
F_48 ( V_106 , 800 , 600 ) ;
}
return V_107 ;
}
static struct V_98 * F_49 ( struct V_92
* V_106 )
{
int V_109 = V_106 -> V_110 [ 0 ] ;
if ( V_109 )
return F_50 ( V_106 -> V_5 , V_109 ) ;
return NULL ;
}
static void F_51 ( struct V_92 * V_106 )
{
F_52 ( V_106 ) ;
F_28 ( V_106 ) ;
}
static struct V_92 * F_53 ( struct V_4 * V_5 )
{
struct V_92 * V_106 ;
struct V_111 * V_111 ;
V_111 = F_30 ( sizeof( struct V_111 ) , V_93 ) ;
if ( ! V_111 )
return NULL ;
V_106 = & V_111 -> V_94 ;
F_54 ( V_5 , V_106 ,
& V_112 , V_113 ) ;
F_55 ( V_106 , & V_114 ) ;
F_56 ( V_106 ) ;
return V_106 ;
}
int F_57 ( struct V_6 * V_7 )
{
struct V_98 * V_99 ;
struct V_92 * V_106 ;
int V_44 ;
F_58 ( V_7 -> V_5 ) ;
V_7 -> V_48 . V_115 = true ;
V_7 -> V_5 -> V_116 . V_117 = V_118 ;
V_7 -> V_5 -> V_116 . V_119 = V_120 ;
V_7 -> V_5 -> V_116 . V_121 = V_7 -> V_122 . V_123 ;
V_7 -> V_5 -> V_116 . V_124 = 24 ;
V_7 -> V_5 -> V_116 . V_125 = 0 ;
F_29 ( V_7 -> V_5 ) ;
V_99 = F_43 ( V_7 -> V_5 ) ;
if ( ! V_99 ) {
F_18 ( L_2 ) ;
return - 1 ;
}
V_106 = F_53 ( V_7 -> V_5 ) ;
if ( ! V_106 ) {
F_18 ( L_3 ) ;
return - 1 ;
}
F_59 ( V_106 , V_99 ) ;
V_44 = F_60 ( V_7 ) ;
if ( V_44 ) {
F_18 ( L_4 ) ;
return V_44 ;
}
return 0 ;
}
void F_61 ( struct V_6 * V_7 )
{
F_62 ( V_7 ) ;
if ( V_7 -> V_48 . V_115 ) {
F_63 ( V_7 -> V_5 ) ;
V_7 -> V_48 . V_115 = false ;
}
}
