void
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 = V_5 ;
}
static void
F_2 ( struct V_6 * V_7 )
{
int V_8 ;
struct V_1 * V_2 ;
V_2 = V_7 -> V_2 ;
V_8 = 0x8000 | ( unsigned char ) V_7 -> V_9 . V_10 . V_11 ;
F_3 ( V_2 , V_7 -> V_12 , V_8 ) ;
V_8 = 0x8000 | ( unsigned char ) V_7 -> V_9 . V_10 . V_13 ;
F_4 ( V_2 , V_7 -> V_12 , V_8 ) ;
}
static void
F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
V_2 = V_7 -> V_2 ;
F_4 ( V_2 , V_7 -> V_12 , 0x807F ) ;
}
static void
F_6 ( struct V_6 * V_7 , int V_14 )
{
struct V_1 * V_2 ;
V_2 = V_7 -> V_2 ;
if ( V_14 & V_15 )
F_7 ( V_2 , V_7 ) ;
if ( V_14 & V_16 )
F_8 ( V_2 , V_7 ) ;
if ( ( V_14 & V_17 ) &&
V_7 -> V_18 -> V_19 [ V_20 ] )
F_9 ( V_2 , V_7 ) ;
if ( V_14 & V_21 )
F_10 ( V_2 , V_7 ) ;
if ( V_14 & V_22 )
F_11 ( V_2 , V_7 ) ;
if ( V_14 & V_23 )
F_12 ( V_2 , V_7 ) ;
if ( V_14 & V_24 )
F_13 ( V_2 , V_7 ) ;
}
static struct V_6 *
F_14 ( struct V_25 * V_3 , struct V_26 * V_18 )
{
int V_27 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
enum {
V_28 = 0 , V_29 , V_30 , V_31
};
struct V_32 {
unsigned int time ;
int V_33 ;
} V_32 [ V_31 ] ;
struct V_32 * V_34 ;
V_2 = V_3 -> V_2 ;
for ( V_27 = 0 ; V_27 < V_31 ; V_27 ++ ) {
V_32 [ V_27 ] . time = ( unsigned int ) ( - 1 ) ; ;
V_32 [ V_27 ] . V_33 = - 1 ;
}
for ( V_27 = 0 ; V_27 < V_3 -> V_35 ; V_27 ++ ) {
int V_36 , V_37 ;
V_7 = & V_3 -> V_38 [ V_27 ] ;
V_36 = V_7 -> V_36 ;
if ( V_36 == V_39 )
V_34 = V_32 + V_28 ;
else if ( V_36 == V_40 ||
V_36 == V_41 ) {
V_34 = V_32 + V_29 ;
V_37 = ( F_15 ( V_2 , V_7 -> V_12 ) >> 16 ) & 0xffff ;
if ( ! V_37 )
V_34 = V_32 + V_28 ;
}
else if ( V_36 & V_42 )
V_34 = V_32 + V_30 ;
else
continue;
if ( V_36 != V_39 &&
( V_7 -> V_9 . V_43 & V_44 ) ) {
V_37 = F_16 ( V_2 , V_7 -> V_12 ) & 0xffffff ;
if ( V_37 >= V_7 -> V_9 . V_45 )
V_34 = V_32 + V_28 ;
}
if ( V_7 -> time < V_34 -> time ) {
V_34 -> time = V_7 -> time ;
V_34 -> V_33 = V_27 ;
}
}
for ( V_27 = 0 ; V_27 < V_31 ; V_27 ++ ) {
if ( V_32 [ V_27 ] . V_33 >= 0 ) {
V_7 = & V_3 -> V_38 [ V_32 [ V_27 ] . V_33 ] ;
V_7 -> V_12 = V_32 [ V_27 ] . V_33 ;
return V_7 ;
}
}
return NULL ;
}
static int
F_17 ( struct V_6 * V_7 )
{
unsigned int V_46 ;
int V_12 ;
int V_47 ;
struct V_48 * V_49 ;
struct V_1 * V_2 ;
V_2 = V_7 -> V_2 ;
V_12 = V_7 -> V_12 ;
V_49 = V_7 -> V_49 ;
F_4 ( V_2 , V_12 , 0x0080 ) ;
F_18 ( V_2 , V_12 , 0x0000FFFF ) ;
F_19 ( V_2 , V_12 , 0x0000FFFF ) ;
F_20 ( V_2 , V_12 , 0 ) ;
F_21 ( V_2 , V_12 , 0 ) ;
F_8 ( V_2 , V_7 ) ;
F_22 ( V_2 , V_12 , V_7 -> V_9 . V_10 . V_50 ) ;
F_23 ( V_2 , V_12 , V_7 -> V_9 . V_10 . V_51 ) ;
F_3 ( V_2 , V_12 , V_7 -> V_9 . V_10 . V_52 ) ;
F_24 ( V_2 , V_12 , V_7 -> V_9 . V_10 . V_53 ) ;
F_25 ( V_2 , V_12 , V_7 -> V_9 . V_10 . V_54 ) ;
F_7 ( V_2 , V_7 ) ;
F_26 ( V_2 , V_12 , V_7 -> V_9 . V_10 . V_55 ) ;
F_27 ( V_2 , V_12 , V_7 -> V_9 . V_10 . V_56 ) ;
F_28 ( V_2 , V_12 , V_7 -> V_9 . V_10 . V_57 ) ;
F_10 ( V_2 , V_7 ) ;
F_11 ( V_2 , V_7 ) ;
F_12 ( V_2 , V_7 ) ;
F_9 ( V_2 , V_7 ) ;
V_47 = V_7 -> V_9 . V_58 - 1 ;
V_46 = V_7 -> V_9 . V_10 . V_59 ;
V_46 += ( int ) V_49 -> V_60 [ V_61 ] * 9 / 10 ;
F_29 ( V_46 , 255 ) ;
V_46 = ( V_46 << 24 ) | ( unsigned int ) V_47 ;
F_30 ( V_2 , V_12 , V_46 ) ;
V_47 = V_7 -> V_9 . V_62 - 1 ;
V_46 = V_7 -> V_9 . V_10 . V_63 ;
V_46 = ( V_46 << 28 ) | ( unsigned int ) V_47 ;
F_31 ( V_2 , V_12 , V_46 ) ;
F_32 ( V_2 , V_12 , 0 ) ;
F_33 ( V_2 , V_12 , 0 ) ;
V_46 = V_7 -> V_64 << 16 ;
F_18 ( V_2 , V_12 , V_46 | V_7 -> V_65 ) ;
F_19 ( V_2 , V_12 , V_46 | 0xff00 ) ;
return 0 ;
}
static void
F_34 ( struct V_6 * V_7 )
{
int V_12 = V_7 -> V_12 ;
unsigned int V_46 ;
struct V_1 * V_2 ;
V_2 = V_7 -> V_2 ;
V_46 = V_7 -> V_9 . V_10 . V_66 ;
V_46 += ( int ) V_7 -> V_49 -> V_60 [ V_67 ] * 9 / 10 ;
F_29 ( V_46 , 255 ) ;
V_46 = ( V_46 << 8 ) | ( V_7 -> V_68 << 16 ) | V_7 -> V_69 ;
F_20 ( V_2 , V_12 , V_46 ) ;
F_21 ( V_2 , V_12 , V_7 -> V_68 << 16 ) ;
F_4 ( V_2 , V_12 , V_7 -> V_9 . V_10 . V_70 ) ;
}
static void
F_35 ( struct V_25 * V_3 , int V_12 )
{
struct V_1 * V_2 ;
V_2 = V_3 -> V_2 ;
F_4 ( V_2 , V_12 , 0x807F ) ;
F_36 ( V_2 , V_12 ) ;
}
static void
F_8 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_37 ( V_2 , V_7 -> V_12 , V_7 -> V_71 ) ;
}
static void
F_7 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_72 ;
V_72 = ( unsigned char ) V_7 -> V_73 ;
V_72 = ( V_72 << 8 ) ;
V_72 |= ( unsigned char ) V_7 -> V_74 ;
F_38 ( V_2 , V_7 -> V_12 , V_72 ) ;
}
static void
F_9 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned int V_46 ;
V_46 = ( ( unsigned int ) V_7 -> V_75 << 24 ) | ( ( unsigned int ) V_7 -> V_9 . V_45 - 1 ) ;
F_39 ( V_2 , V_7 -> V_12 , V_46 ) ;
}
static void
F_10 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned short V_76 ;
short V_77 ;
unsigned char V_78 ;
int V_79 ;
V_77 = ( char ) ( V_7 -> V_9 . V_10 . V_76 >> 8 ) ;
V_78 = ( V_7 -> V_9 . V_10 . V_76 & 0xff ) ;
V_79 = V_7 -> V_49 -> V_80 + V_7 -> V_49 -> V_81 ;
V_77 += ( V_82 * V_79 ) / 1200 ;
F_40 ( V_77 , - 128 , 127 ) ;
V_76 = ( ( unsigned char ) V_77 << 8 ) | V_78 ;
F_41 ( V_2 , V_7 -> V_12 , V_76 ) ;
}
static void
F_11 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_42 ( V_2 , V_7 -> V_12 , V_7 -> V_9 . V_10 . V_83 ) ;
}
static void
F_12 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned short V_84 ;
short V_77 ;
unsigned char V_85 ;
int V_79 ;
V_77 = ( char ) ( V_7 -> V_9 . V_10 . V_84 >> 8 ) ;
V_85 = V_7 -> V_9 . V_10 . V_84 & 0xff ;
V_79 = V_7 -> V_49 -> V_80 + V_7 -> V_49 -> V_81 ;
V_77 += ( V_82 * V_79 ) / 1200 ;
F_40 ( V_77 , - 128 , 127 ) ;
V_84 = ( ( unsigned char ) V_77 << 8 ) | V_85 ;
F_43 ( V_2 , V_7 -> V_12 , V_84 ) ;
}
static void
F_13 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned int V_47 ;
V_47 = F_16 ( V_2 , V_7 -> V_12 ) & 0xffffff ;
V_47 |= ( V_7 -> V_9 . V_10 . V_63 << 28 ) ;
F_31 ( V_2 , V_7 -> V_12 , V_47 ) ;
}
static void
F_36 ( struct V_1 * V_3 , int V_27 )
{
F_24 ( V_3 , V_27 , 0x8000 ) ;
F_22 ( V_3 , V_27 , 0x8000 ) ;
F_3 ( V_3 , V_27 , 0x7F7F ) ;
F_25 ( V_3 , V_27 , 0x7F7F ) ;
F_23 ( V_3 , V_27 , 0x7F7F ) ;
F_26 ( V_3 , V_27 , 0 ) ;
F_27 ( V_3 , V_27 , 0x8000 ) ;
F_28 ( V_3 , V_27 , 0x8000 ) ;
F_37 ( V_3 , V_27 , 0xE000 ) ;
F_38 ( V_3 , V_27 , 0xFF00 ) ;
F_41 ( V_3 , V_27 , 0 ) ;
F_42 ( V_3 , V_27 , 0 ) ;
F_43 ( V_3 , V_27 , 0 ) ;
}
static void
F_44 ( struct V_25 * V_3 , char * V_86 , int V_87 , int V_88 , struct V_89 * V_90 )
{
struct V_1 * V_2 ;
V_2 = V_3 -> V_2 ;
switch ( V_88 ) {
case V_91 :
V_2 -> V_92 = V_90 -> V_93 ;
F_45 ( V_2 ) ;
break;
case V_94 :
V_2 -> V_95 = V_90 -> V_96 ;
F_46 ( V_2 ) ;
break;
}
}
static int
F_47 ( struct V_25 * V_3 , int V_97 , int V_98 , int V_99 )
{
struct V_1 * V_2 ;
V_2 = V_3 -> V_2 ;
switch ( V_97 ) {
case V_100 :
V_2 -> V_95 = V_98 ;
F_46 ( V_2 ) ;
break;
case V_101 :
V_2 -> V_92 = V_98 ;
F_45 ( V_2 ) ;
break;
case V_102 :
break;
case V_103 :
V_2 -> V_104 = V_98 ;
V_2 -> V_105 = V_99 ;
F_48 ( V_2 ) ;
break;
}
return 0 ;
}
static int
F_49 ( struct V_25 * V_3 , int type , int V_106 , const void T_1 * V_86 , long V_87 )
{
struct V_1 * V_2 ;
V_2 = V_3 -> V_2 ;
V_86 += 16 ;
V_87 -= 16 ;
switch ( type ) {
case V_107 :
return F_50 ( V_2 , V_106 , V_86 , V_87 ) ;
case V_108 :
return F_51 ( V_2 , V_106 , V_86 , V_87 ) ;
}
return - V_109 ;
}
