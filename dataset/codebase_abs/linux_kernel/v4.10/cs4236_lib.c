static void F_1 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + 3 ) ;
F_2 ( V_2 -> V_6 [ V_3 ] = V_4 , V_2 -> V_5 + 4 ) ;
}
static unsigned char F_3 ( struct V_1 * V_2 , unsigned char V_3 )
{
F_2 ( V_3 , V_2 -> V_5 + 3 ) ;
return F_4 ( V_2 -> V_5 + 4 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
return F_6 ( V_8 , 0 , V_9 ,
& V_10 ) ;
}
static unsigned char F_7 ( unsigned int V_11 )
{
switch ( V_11 ) {
case 353 : return 1 ;
case 529 : return 2 ;
case 617 : return 3 ;
case 1058 : return 4 ;
case 1764 : return 5 ;
case 2117 : return 6 ;
case 2558 : return 7 ;
default:
if ( V_11 < 21 || V_11 > 192 ) {
F_8 () ;
return 192 ;
}
return V_11 ;
}
}
static void F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
unsigned char V_14 )
{
unsigned long V_15 ;
unsigned char V_16 = F_7 ( V_13 -> V_17 ) ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
F_11 ( V_2 , V_19 ,
V_2 -> V_20 [ V_19 ] | 0x10 ) ;
F_11 ( V_2 , V_21 , V_14 & 0xf0 ) ;
F_11 ( V_2 , V_19 ,
V_2 -> V_20 [ V_19 ] & ~ 0x10 ) ;
F_12 ( V_2 , V_22 , V_16 ) ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
unsigned char V_23 )
{
unsigned long V_15 ;
unsigned char V_16 = F_7 ( V_13 -> V_17 ) ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
F_11 ( V_2 , V_19 ,
V_2 -> V_20 [ V_19 ] | 0x20 ) ;
F_11 ( V_2 , V_24 , V_23 & 0xf0 ) ;
F_11 ( V_2 , V_19 ,
V_2 -> V_20 [ V_19 ] & ~ 0x20 ) ;
F_12 ( V_2 , V_25 , V_16 ) ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_15 ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 ++ )
V_2 -> V_20 [ V_3 ] = F_16 ( V_2 , V_3 ) ;
for ( V_3 = 0 ; V_3 < 18 ; V_3 ++ )
V_2 -> V_26 [ V_3 ] = F_17 ( V_2 , F_18 ( V_3 ) ) ;
for ( V_3 = 2 ; V_3 < 9 ; V_3 ++ )
V_2 -> V_6 [ V_3 ] = F_3 ( V_2 , V_3 ) ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_15 ;
F_20 ( V_2 ) ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 ++ ) {
switch ( V_3 ) {
case V_27 :
case V_28 :
case 27 :
case 29 :
break;
default:
F_11 ( V_2 , V_3 , V_2 -> V_20 [ V_3 ] ) ;
break;
}
}
for ( V_3 = 0 ; V_3 < 18 ; V_3 ++ )
F_12 ( V_2 , F_18 ( V_3 ) , V_2 -> V_26 [ V_3 ] ) ;
for ( V_3 = 2 ; V_3 < 9 ; V_3 ++ ) {
switch ( V_3 ) {
case 7 :
break;
default:
F_1 ( V_2 , V_3 , V_2 -> V_6 [ V_3 ] ) ;
}
}
F_13 ( & V_2 -> V_18 , V_15 ) ;
F_21 ( V_2 ) ;
}
int F_22 ( struct V_29 * V_30 ,
unsigned long V_31 ,
unsigned long V_5 ,
int V_32 , int V_33 , int V_34 ,
unsigned short V_35 ,
unsigned short V_36 ,
struct V_1 * * V_37 )
{
struct V_1 * V_2 ;
unsigned char V_38 , V_39 ;
unsigned int V_3 ;
int V_40 ;
* V_37 = NULL ;
if ( V_35 == V_41 )
V_35 = V_42 ;
V_40 = F_23 ( V_30 , V_31 , V_5 ,
V_32 , V_33 , V_34 , V_35 , V_36 , & V_2 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( ( V_2 -> V_35 & V_43 ) == 0 ) {
F_24 ( L_1 ,
V_2 -> V_35 ) ;
* V_37 = V_2 ;
return 0 ;
}
#if 0
{
int idx;
for (idx = 0; idx < 8; idx++)
snd_printk(KERN_DEBUG "CD%i = 0x%x\n",
idx, inb(chip->cport + idx));
for (idx = 0; idx < 9; idx++)
snd_printk(KERN_DEBUG "C%i = 0x%x\n",
idx, snd_cs4236_ctrl_in(chip, idx));
}
#endif
if ( V_5 < 0x100 || V_5 == V_44 ) {
F_25 ( V_45 L_2
L_3 ) ;
F_26 ( V_30 , V_2 ) ;
return - V_46 ;
}
V_38 = F_3 ( V_2 , 1 ) ;
V_39 = F_17 ( V_2 , V_47 ) ;
F_27 ( L_4 ,
V_5 , V_38 , V_39 ) ;
if ( V_38 != V_39 ) {
F_25 ( V_45 L_5
L_6 , V_5 ) ;
F_26 ( V_30 , V_2 ) ;
return - V_46 ;
}
F_1 ( V_2 , 0 , 0x00 ) ;
F_1 ( V_2 , 2 , 0xff ) ;
F_1 ( V_2 , 3 , 0x00 ) ;
F_1 ( V_2 , 4 , 0x80 ) ;
V_3 = ( ( V_48 & 3 ) << 6 ) |
V_49 ;
F_1 ( V_2 , 5 , V_3 ) ;
F_1 ( V_2 , 6 , V_48 >> 2 ) ;
F_1 ( V_2 , 7 , 0x00 ) ;
F_1 ( V_2 , 8 , 0x8c ) ;
V_2 -> V_50 = F_5 ;
V_2 -> V_51 = F_9 ;
V_2 -> V_52 = F_14 ;
#ifdef F_28
V_2 -> V_53 = F_15 ;
V_2 -> V_54 = F_19 ;
#endif
for ( V_3 = 0 ; V_3 < sizeof( V_55 ) ; V_3 ++ )
F_12 ( V_2 , F_18 ( V_3 ) ,
V_55 [ V_3 ] ) ;
F_11 ( V_2 , V_56 , 0x40 ) ;
F_11 ( V_2 , V_57 , 0x40 ) ;
F_11 ( V_2 , V_58 , 0xff ) ;
F_11 ( V_2 , V_59 , 0xff ) ;
F_11 ( V_2 , V_60 , 0xdf ) ;
F_11 ( V_2 , V_61 , 0xdf ) ;
F_11 ( V_2 , V_62 , 0xff ) ;
F_11 ( V_2 , V_63 , 0xff ) ;
F_11 ( V_2 , V_62 , 0xff ) ;
switch ( V_2 -> V_35 ) {
case V_64 :
case V_65 :
F_11 ( V_2 , V_66 , 0xff ) ;
F_11 ( V_2 , V_67 , 0xff ) ;
break;
}
* V_37 = V_2 ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , int V_68 )
{
int V_40 ;
V_40 = F_30 ( V_2 , V_68 ) ;
if ( V_40 < 0 )
return V_40 ;
V_2 -> V_69 -> V_70 &= ~ V_71 ;
return 0 ;
}
static int F_31 ( struct V_72 * V_73 , struct V_74 * V_75 )
{
int V_76 = ( V_73 -> V_77 >> 16 ) & 0xff ;
V_75 -> type = V_76 == 1 ? V_78 : V_79 ;
V_75 -> V_80 = 1 ;
V_75 -> V_81 . integer . V_82 = 0 ;
V_75 -> V_81 . integer . V_83 = V_76 ;
return 0 ;
}
static int F_32 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
int V_3 = V_73 -> V_77 & 0xff ;
int V_86 = ( V_73 -> V_77 >> 8 ) & 0xff ;
int V_76 = ( V_73 -> V_77 >> 16 ) & 0xff ;
int V_87 = ( V_73 -> V_77 >> 24 ) & 0xff ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_85 -> V_81 . integer . V_81 [ 0 ] = ( V_2 -> V_26 [ F_34 ( V_3 ) ] >> V_86 ) & V_76 ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
if ( V_87 )
V_85 -> V_81 . integer . V_81 [ 0 ] = V_76 - V_85 -> V_81 . integer . V_81 [ 0 ] ;
return 0 ;
}
static int F_35 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
int V_3 = V_73 -> V_77 & 0xff ;
int V_86 = ( V_73 -> V_77 >> 8 ) & 0xff ;
int V_76 = ( V_73 -> V_77 >> 16 ) & 0xff ;
int V_87 = ( V_73 -> V_77 >> 24 ) & 0xff ;
int V_88 ;
unsigned short V_4 ;
V_4 = ( V_85 -> V_81 . integer . V_81 [ 0 ] & V_76 ) ;
if ( V_87 )
V_4 = V_76 - V_4 ;
V_4 <<= V_86 ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_4 = ( V_2 -> V_26 [ F_34 ( V_3 ) ] & ~ ( V_76 << V_86 ) ) | V_4 ;
V_88 = V_4 != V_2 -> V_26 [ F_34 ( V_3 ) ] ;
F_12 ( V_2 , V_3 , V_4 ) ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
return V_88 ;
}
static int F_36 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
int V_3 = V_73 -> V_77 & 0xff ;
int V_86 = ( V_73 -> V_77 >> 8 ) & 0xff ;
int V_76 = ( V_73 -> V_77 >> 16 ) & 0xff ;
int V_87 = ( V_73 -> V_77 >> 24 ) & 0xff ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_85 -> V_81 . integer . V_81 [ 0 ] = ( V_2 -> V_6 [ V_3 ] >> V_86 ) & V_76 ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
if ( V_87 )
V_85 -> V_81 . integer . V_81 [ 0 ] = V_76 - V_85 -> V_81 . integer . V_81 [ 0 ] ;
return 0 ;
}
static int F_37 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
int V_3 = V_73 -> V_77 & 0xff ;
int V_86 = ( V_73 -> V_77 >> 8 ) & 0xff ;
int V_76 = ( V_73 -> V_77 >> 16 ) & 0xff ;
int V_87 = ( V_73 -> V_77 >> 24 ) & 0xff ;
int V_88 ;
unsigned short V_4 ;
V_4 = ( V_85 -> V_81 . integer . V_81 [ 0 ] & V_76 ) ;
if ( V_87 )
V_4 = V_76 - V_4 ;
V_4 <<= V_86 ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_4 = ( V_2 -> V_6 [ V_3 ] & ~ ( V_76 << V_86 ) ) | V_4 ;
V_88 = V_4 != V_2 -> V_6 [ V_3 ] ;
F_1 ( V_2 , V_3 , V_4 ) ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
return V_88 ;
}
static int F_38 ( struct V_72 * V_73 , struct V_74 * V_75 )
{
int V_76 = ( V_73 -> V_77 >> 24 ) & 0xff ;
V_75 -> type = V_76 == 1 ? V_78 : V_79 ;
V_75 -> V_80 = 2 ;
V_75 -> V_81 . integer . V_82 = 0 ;
V_75 -> V_81 . integer . V_83 = V_76 ;
return 0 ;
}
static int F_39 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
int V_89 = V_73 -> V_77 & 0xff ;
int V_90 = ( V_73 -> V_77 >> 8 ) & 0xff ;
int V_91 = ( V_73 -> V_77 >> 16 ) & 0x07 ;
int V_92 = ( V_73 -> V_77 >> 19 ) & 0x07 ;
int V_76 = ( V_73 -> V_77 >> 24 ) & 0xff ;
int V_87 = ( V_73 -> V_77 >> 22 ) & 1 ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_85 -> V_81 . integer . V_81 [ 0 ] = ( V_2 -> V_26 [ F_34 ( V_89 ) ] >> V_91 ) & V_76 ;
V_85 -> V_81 . integer . V_81 [ 1 ] = ( V_2 -> V_26 [ F_34 ( V_90 ) ] >> V_92 ) & V_76 ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
if ( V_87 ) {
V_85 -> V_81 . integer . V_81 [ 0 ] = V_76 - V_85 -> V_81 . integer . V_81 [ 0 ] ;
V_85 -> V_81 . integer . V_81 [ 1 ] = V_76 - V_85 -> V_81 . integer . V_81 [ 1 ] ;
}
return 0 ;
}
static int F_40 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
int V_89 = V_73 -> V_77 & 0xff ;
int V_90 = ( V_73 -> V_77 >> 8 ) & 0xff ;
int V_91 = ( V_73 -> V_77 >> 16 ) & 0x07 ;
int V_92 = ( V_73 -> V_77 >> 19 ) & 0x07 ;
int V_76 = ( V_73 -> V_77 >> 24 ) & 0xff ;
int V_87 = ( V_73 -> V_77 >> 22 ) & 1 ;
int V_88 ;
unsigned short V_93 , V_94 ;
V_93 = V_85 -> V_81 . integer . V_81 [ 0 ] & V_76 ;
V_94 = V_85 -> V_81 . integer . V_81 [ 1 ] & V_76 ;
if ( V_87 ) {
V_93 = V_76 - V_93 ;
V_94 = V_76 - V_94 ;
}
V_93 <<= V_91 ;
V_94 <<= V_92 ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
if ( V_89 != V_90 ) {
V_93 = ( V_2 -> V_26 [ F_34 ( V_89 ) ] & ~ ( V_76 << V_91 ) ) | V_93 ;
V_94 = ( V_2 -> V_26 [ F_34 ( V_90 ) ] & ~ ( V_76 << V_92 ) ) | V_94 ;
V_88 = V_93 != V_2 -> V_26 [ F_34 ( V_89 ) ] || V_94 != V_2 -> V_26 [ F_34 ( V_90 ) ] ;
F_12 ( V_2 , V_89 , V_93 ) ;
F_12 ( V_2 , V_90 , V_94 ) ;
} else {
V_93 = ( V_2 -> V_26 [ F_34 ( V_89 ) ] & ~ ( ( V_76 << V_91 ) | ( V_76 << V_92 ) ) ) | V_93 | V_94 ;
V_88 = V_93 != V_2 -> V_26 [ F_34 ( V_89 ) ] ;
F_12 ( V_2 , V_89 , V_93 ) ;
}
F_13 ( & V_2 -> V_18 , V_15 ) ;
return V_88 ;
}
static int F_41 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
int V_89 = V_73 -> V_77 & 0xff ;
int V_90 = ( V_73 -> V_77 >> 8 ) & 0xff ;
int V_91 = ( V_73 -> V_77 >> 16 ) & 0x07 ;
int V_92 = ( V_73 -> V_77 >> 19 ) & 0x07 ;
int V_76 = ( V_73 -> V_77 >> 24 ) & 0xff ;
int V_87 = ( V_73 -> V_77 >> 22 ) & 1 ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_85 -> V_81 . integer . V_81 [ 0 ] = ( V_2 -> V_20 [ V_89 ] >> V_91 ) & V_76 ;
V_85 -> V_81 . integer . V_81 [ 1 ] = ( V_2 -> V_26 [ F_34 ( V_90 ) ] >> V_92 ) & V_76 ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
if ( V_87 ) {
V_85 -> V_81 . integer . V_81 [ 0 ] = V_76 - V_85 -> V_81 . integer . V_81 [ 0 ] ;
V_85 -> V_81 . integer . V_81 [ 1 ] = V_76 - V_85 -> V_81 . integer . V_81 [ 1 ] ;
}
return 0 ;
}
static int F_42 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
int V_89 = V_73 -> V_77 & 0xff ;
int V_90 = ( V_73 -> V_77 >> 8 ) & 0xff ;
int V_91 = ( V_73 -> V_77 >> 16 ) & 0x07 ;
int V_92 = ( V_73 -> V_77 >> 19 ) & 0x07 ;
int V_76 = ( V_73 -> V_77 >> 24 ) & 0xff ;
int V_87 = ( V_73 -> V_77 >> 22 ) & 1 ;
int V_88 ;
unsigned short V_93 , V_94 ;
V_93 = V_85 -> V_81 . integer . V_81 [ 0 ] & V_76 ;
V_94 = V_85 -> V_81 . integer . V_81 [ 1 ] & V_76 ;
if ( V_87 ) {
V_93 = V_76 - V_93 ;
V_94 = V_76 - V_94 ;
}
V_93 <<= V_91 ;
V_94 <<= V_92 ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_93 = ( V_2 -> V_20 [ V_89 ] & ~ ( V_76 << V_91 ) ) | V_93 ;
V_94 = ( V_2 -> V_26 [ F_34 ( V_90 ) ] & ~ ( V_76 << V_92 ) ) | V_94 ;
V_88 = V_93 != V_2 -> V_20 [ V_89 ] || V_94 != V_2 -> V_26 [ F_34 ( V_90 ) ] ;
F_11 ( V_2 , V_89 , V_93 ) ;
F_12 ( V_2 , V_90 , V_94 ) ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
return V_88 ;
}
static inline int F_43 ( int V_95 )
{
return ( V_95 < 64 ) ? 63 - V_95 : 64 + ( 71 - V_95 ) ;
}
static int F_44 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_85 -> V_81 . integer . V_81 [ 0 ] = F_43 ( V_2 -> V_26 [ F_34 ( V_96 ) ] & 0x7f ) ;
V_85 -> V_81 . integer . V_81 [ 1 ] = F_43 ( V_2 -> V_26 [ F_34 ( V_97 ) ] & 0x7f ) ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
return 0 ;
}
static int F_45 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
int V_88 ;
unsigned short V_93 , V_94 ;
V_93 = F_43 ( V_85 -> V_81 . integer . V_81 [ 0 ] & 0x7f ) ;
V_94 = F_43 ( V_85 -> V_81 . integer . V_81 [ 1 ] & 0x7f ) ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_93 = ( V_2 -> V_26 [ F_34 ( V_96 ) ] & ~ 0x7f ) | V_93 ;
V_94 = ( V_2 -> V_26 [ F_34 ( V_97 ) ] & ~ 0x7f ) | V_94 ;
V_88 = V_93 != V_2 -> V_26 [ F_34 ( V_96 ) ] || V_94 != V_2 -> V_26 [ F_34 ( V_97 ) ] ;
F_12 ( V_2 , V_96 , V_93 ) ;
F_12 ( V_2 , V_97 , V_94 ) ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
return V_88 ;
}
static inline int F_46 ( int V_95 )
{
switch ( ( V_95 >> 5 ) & 3 ) {
case 0 : return 1 ;
case 1 : return 3 ;
case 2 : return 2 ;
case 3 : return 0 ;
}
return 3 ;
}
static inline int F_47 ( int V_95 )
{
switch ( V_95 & 3 ) {
case 0 : return 3 << 5 ;
case 1 : return 0 << 5 ;
case 2 : return 2 << 5 ;
case 3 : return 1 << 5 ;
}
return 1 << 5 ;
}
static int F_48 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_85 -> V_81 . integer . V_81 [ 0 ] = F_46 ( V_2 -> V_20 [ V_66 ] ) ;
V_85 -> V_81 . integer . V_81 [ 1 ] = F_46 ( V_2 -> V_20 [ V_67 ] ) ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
return 0 ;
}
static int F_49 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
int V_88 ;
unsigned short V_93 , V_94 ;
V_93 = F_47 ( V_85 -> V_81 . integer . V_81 [ 0 ] ) ;
V_94 = F_47 ( V_85 -> V_81 . integer . V_81 [ 1 ] ) ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_93 = ( V_2 -> V_20 [ V_66 ] & ~ ( 3 << 5 ) ) | V_93 ;
V_94 = ( V_2 -> V_20 [ V_67 ] & ~ ( 3 << 5 ) ) | V_94 ;
V_88 = V_93 != V_2 -> V_20 [ V_66 ] || V_94 != V_2 -> V_20 [ V_67 ] ;
F_11 ( V_2 , V_66 , V_93 ) ;
F_11 ( V_2 , V_67 , V_94 ) ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
return V_88 ;
}
static int F_50 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_85 -> V_81 . integer . V_81 [ 0 ] = V_2 -> V_20 [ V_19 ] & 0x02 ? 1 : 0 ;
#if 0
printk(KERN_DEBUG "get valid: ALT = 0x%x, C3 = 0x%x, C4 = 0x%x, "
"C5 = 0x%x, C6 = 0x%x, C8 = 0x%x\n",
snd_wss_in(chip, CS4231_ALT_FEATURE_1),
snd_cs4236_ctrl_in(chip, 3),
snd_cs4236_ctrl_in(chip, 4),
snd_cs4236_ctrl_in(chip, 5),
snd_cs4236_ctrl_in(chip, 6),
snd_cs4236_ctrl_in(chip, 8));
#endif
F_13 ( & V_2 -> V_18 , V_15 ) ;
return 0 ;
}
static int F_51 ( struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_33 ( V_73 ) ;
unsigned long V_15 ;
int V_88 ;
unsigned short V_98 , V_4 ;
V_98 = V_85 -> V_81 . integer . V_81 [ 0 ] & 1 ;
F_52 ( & V_2 -> V_99 ) ;
F_20 ( V_2 ) ;
F_10 ( & V_2 -> V_18 , V_15 ) ;
V_4 = ( V_2 -> V_20 [ V_19 ] & ~ 0x0e ) | ( 0 << 2 ) | ( V_98 << 1 ) ;
V_88 = V_4 != V_2 -> V_20 [ V_19 ] ;
F_11 ( V_2 , V_19 , V_4 ) ;
V_4 = F_3 ( V_2 , 4 ) | 0xc0 ;
F_1 ( V_2 , 4 , V_4 ) ;
F_53 ( 100 ) ;
V_4 &= ~ 0x40 ;
F_1 ( V_2 , 4 , V_4 ) ;
F_13 ( & V_2 -> V_18 , V_15 ) ;
F_21 ( V_2 ) ;
F_54 ( & V_2 -> V_99 ) ;
#if 0
printk(KERN_DEBUG "set valid: ALT = 0x%x, C3 = 0x%x, C4 = 0x%x, "
"C5 = 0x%x, C6 = 0x%x, C8 = 0x%x\n",
snd_wss_in(chip, CS4231_ALT_FEATURE_1),
snd_cs4236_ctrl_in(chip, 3),
snd_cs4236_ctrl_in(chip, 4),
snd_cs4236_ctrl_in(chip, 5),
snd_cs4236_ctrl_in(chip, 6),
snd_cs4236_ctrl_in(chip, 8));
#endif
return V_88 ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
unsigned int V_100 , V_80 ;
int V_40 ;
struct V_101 * V_73 ;
if ( F_56 ( ! V_2 || ! V_2 -> V_30 ) )
return - V_102 ;
V_30 = V_2 -> V_30 ;
strcpy ( V_30 -> V_103 , F_57 ( V_2 ) ) ;
if ( V_2 -> V_35 == V_64 ||
V_2 -> V_35 == V_65 ) {
for ( V_100 = 0 ; V_100 < F_58 ( V_104 ) ; V_100 ++ ) {
if ( ( V_40 = F_59 ( V_30 , F_60 ( & V_104 [ V_100 ] , V_2 ) ) ) < 0 )
return V_40 ;
}
} else {
for ( V_100 = 0 ; V_100 < F_58 ( V_105 ) ; V_100 ++ ) {
if ( ( V_40 = F_59 ( V_30 , F_60 ( & V_105 [ V_100 ] , V_2 ) ) ) < 0 )
return V_40 ;
}
}
switch ( V_2 -> V_35 ) {
case V_64 :
case V_65 :
V_80 = F_58 ( V_106 ) ;
V_73 = V_106 ;
break;
case V_107 :
V_80 = F_58 ( V_108 ) ;
V_73 = V_108 ;
break;
case V_109 :
V_80 = F_58 ( V_110 ) ;
V_73 = V_110 ;
break;
default:
V_80 = 0 ;
V_73 = NULL ;
}
for ( V_100 = 0 ; V_100 < V_80 ; V_100 ++ , V_73 ++ ) {
if ( ( V_40 = F_59 ( V_30 , F_60 ( V_73 , V_2 ) ) ) < 0 )
return V_40 ;
}
if ( V_2 -> V_35 == V_107 ||
V_2 -> V_35 == V_109 ) {
for ( V_100 = 0 ; V_100 < F_58 ( V_111 ) ; V_100 ++ ) {
if ( ( V_40 = F_59 ( V_30 , F_60 ( & V_111 [ V_100 ] , V_2 ) ) ) < 0 )
return V_40 ;
}
}
return 0 ;
}
