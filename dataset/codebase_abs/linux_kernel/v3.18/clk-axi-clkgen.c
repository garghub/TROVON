static void F_1 ( struct V_1 * V_1 ,
bool V_2 )
{
V_1 -> V_3 -> V_2 ( V_1 , V_2 ) ;
}
static int F_2 ( struct V_1 * V_1 ,
unsigned int V_4 , unsigned int V_5 , unsigned int V_6 )
{
return V_1 -> V_3 -> V_7 ( V_1 , V_4 , V_5 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_1 ,
unsigned int V_4 , unsigned int * V_5 )
{
return V_1 -> V_3 -> V_8 ( V_1 , V_4 , V_5 ) ;
}
static T_1 F_4 ( unsigned int V_9 )
{
switch ( V_9 ) {
case 0 :
return 0x01001990 ;
case 1 :
return 0x01001190 ;
case 2 :
return 0x01009890 ;
case 3 :
return 0x01001890 ;
case 4 :
return 0x01008890 ;
case 5 ... 8 :
return 0x01009090 ;
case 9 ... 11 :
return 0x01000890 ;
case 12 :
return 0x08009090 ;
case 13 ... 22 :
return 0x01001090 ;
case 23 ... 36 :
return 0x01008090 ;
case 37 ... 46 :
return 0x08001090 ;
default:
return 0x08008090 ;
}
}
static T_1 F_5 ( unsigned int V_9 )
{
if ( V_9 < F_6 ( V_10 ) )
return V_10 [ V_9 ] ;
return 0x1f1f00fa ;
}
static void F_7 ( unsigned long V_11 , unsigned long V_12 ,
unsigned int * V_13 , unsigned int * V_14 , unsigned int * V_15 )
{
unsigned long V_16 , V_17 , V_18 , V_19 , V_20 ;
unsigned long V_9 , V_21 , V_22 ;
unsigned long V_23 , V_24 , V_25 , V_26 ;
V_11 /= 1000 ;
V_12 /= 1000 ;
V_25 = V_27 ;
* V_13 = 0 ;
* V_14 = 0 ;
* V_15 = 0 ;
V_17 = F_8 (unsigned long, DIV_ROUND_UP(fin, fpfd_max), 1 ) ;
V_18 = F_9 (unsigned long, fin / fpfd_min, 80 ) ;
V_21 = F_8 (unsigned long, DIV_ROUND_UP(fvco_min, fin) * d_min, 1 ) ;
V_22 = F_9 (unsigned long, fvco_max * d_max / fin, 64 ) ;
for ( V_9 = V_21 ; V_9 <= V_22 ; V_9 ++ ) {
V_19 = F_10 ( V_17 , F_11 ( V_11 * V_9 , V_28 ) ) ;
V_20 = F_12 ( V_18 , V_11 * V_9 / V_29 ) ;
for ( V_16 = V_19 ; V_16 <= V_20 ; V_16 ++ ) {
V_26 = V_11 * V_9 / V_16 ;
V_24 = F_13 ( V_26 , V_12 ) ;
V_24 = F_14 (unsigned long, dout, 1 , 128 ) ;
V_23 = V_26 / V_24 ;
if ( abs ( V_23 - V_12 ) < abs ( V_25 - V_12 ) ) {
V_25 = V_23 ;
* V_13 = V_16 ;
* V_14 = V_9 ;
* V_15 = V_24 ;
if ( V_25 == V_12 )
return;
}
}
}
}
static void F_15 ( unsigned int V_30 , unsigned int * V_31 ,
unsigned int * V_32 , unsigned int * V_33 , unsigned int * V_34 )
{
if ( V_30 == 1 )
* V_34 = 1 ;
else
* V_34 = 0 ;
* V_32 = V_30 / 2 ;
* V_33 = V_30 % 2 ;
* V_31 = V_30 - * V_32 ;
}
static void F_16 ( struct V_1 * V_1 ,
unsigned int V_4 , unsigned int V_5 )
{
F_17 ( V_5 , V_1 -> V_35 + V_4 ) ;
}
static void F_18 ( struct V_1 * V_1 ,
unsigned int V_4 , unsigned int * V_5 )
{
* V_5 = F_19 ( V_1 -> V_35 + V_4 ) ;
}
static unsigned int F_20 ( unsigned int V_4 )
{
switch ( V_4 ) {
case V_36 :
return V_37 ;
case V_38 :
return V_39 ;
case V_40 :
return V_41 ;
case V_42 :
return V_43 ;
case V_44 :
return V_45 ;
case V_46 :
return V_47 ;
case V_48 :
return V_49 ;
case V_50 :
return V_51 ;
case V_52 :
return V_53 ;
case V_54 :
return V_55 ;
default:
return 0 ;
}
}
static int F_21 ( struct V_1 * V_1 ,
unsigned int V_4 , unsigned int V_5 , unsigned int V_6 )
{
V_4 = F_20 ( V_4 ) ;
if ( V_4 == 0 )
return - V_56 ;
F_16 ( V_1 , V_4 , V_5 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 ,
unsigned int V_4 , unsigned int * V_5 )
{
V_4 = F_20 ( V_4 ) ;
if ( V_4 == 0 )
return - V_56 ;
F_18 ( V_1 , V_4 , V_5 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_1 ,
bool V_2 )
{
F_16 ( V_1 , V_57 , V_2 ) ;
}
static int F_24 ( struct V_1 * V_1 )
{
unsigned int V_58 = 10000 ;
unsigned int V_5 ;
do {
F_18 ( V_1 , V_59 , & V_5 ) ;
} while ( ( V_5 & V_60 ) && -- V_58 );
if ( V_5 & V_60 )
return - V_61 ;
return V_5 & 0xffff ;
}
static int F_25 ( struct V_1 * V_1 ,
unsigned int V_4 , unsigned int * V_5 )
{
unsigned int V_62 ;
int V_63 ;
V_63 = F_24 ( V_1 ) ;
if ( V_63 < 0 )
return V_63 ;
V_62 = V_64 | V_65 ;
V_62 |= ( V_4 << 16 ) ;
F_16 ( V_1 , V_66 , V_62 ) ;
V_63 = F_24 ( V_1 ) ;
if ( V_63 < 0 )
return V_63 ;
* V_5 = V_63 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 ,
unsigned int V_4 , unsigned int V_5 , unsigned int V_6 )
{
unsigned int V_62 = 0 ;
int V_63 ;
V_63 = F_24 ( V_1 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( V_6 != 0xffff ) {
F_25 ( V_1 , V_4 , & V_62 ) ;
V_62 &= ~ V_6 ;
}
V_62 |= V_64 | ( V_4 << 16 ) | ( V_5 & V_6 ) ;
F_16 ( V_1 , V_66 , V_62 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_1 ,
bool V_2 )
{
unsigned int V_5 = V_67 ;
if ( V_2 )
V_5 |= V_68 ;
F_16 ( V_1 , V_69 , V_5 ) ;
}
static struct V_1 * F_28 ( struct V_70 * V_70 )
{
return F_29 ( V_70 , struct V_1 , V_70 ) ;
}
static int F_30 ( struct V_70 * V_70 ,
unsigned long V_71 , unsigned long V_72 )
{
struct V_1 * V_1 = F_28 ( V_70 ) ;
unsigned int V_16 , V_9 , V_24 ;
unsigned int V_34 ;
unsigned int V_32 ;
unsigned int V_33 ;
unsigned int V_31 ;
T_1 V_73 ;
T_1 V_74 ;
if ( V_72 == 0 || V_71 == 0 )
return - V_56 ;
F_7 ( V_72 , V_71 , & V_16 , & V_9 , & V_24 ) ;
if ( V_16 == 0 || V_24 == 0 || V_9 == 0 )
return - V_56 ;
V_73 = F_4 ( V_9 - 1 ) ;
V_74 = F_5 ( V_9 - 1 ) ;
F_15 ( V_24 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
F_2 ( V_1 , V_36 ,
( V_32 << 6 ) | V_31 , 0xefff ) ;
F_2 ( V_1 , V_38 ,
( V_33 << 7 ) | ( V_34 << 6 ) , 0x03ff ) ;
F_15 ( V_16 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
F_2 ( V_1 , V_44 ,
( V_33 << 13 ) | ( V_34 << 12 ) | ( V_32 << 6 ) | V_31 , 0x3fff ) ;
F_15 ( V_9 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
F_2 ( V_1 , V_40 ,
( V_32 << 6 ) | V_31 , 0xefff ) ;
F_2 ( V_1 , V_42 ,
( V_33 << 7 ) | ( V_34 << 6 ) , 0x03ff ) ;
F_2 ( V_1 , V_46 , V_74 & 0x3ff , 0x3ff ) ;
F_2 ( V_1 , V_48 ,
( ( ( V_74 >> 16 ) & 0x1f ) << 10 ) | 0x1 , 0x7fff ) ;
F_2 ( V_1 , V_50 ,
( ( ( V_74 >> 24 ) & 0x1f ) << 10 ) | 0x3e9 , 0x7fff ) ;
F_2 ( V_1 , V_52 , V_73 >> 16 , 0x9900 ) ;
F_2 ( V_1 , V_54 , V_73 , 0x9900 ) ;
return 0 ;
}
static long F_31 ( struct V_70 * V_75 , unsigned long V_71 ,
unsigned long * V_72 )
{
unsigned int V_16 , V_9 , V_24 ;
F_7 ( * V_72 , V_71 , & V_16 , & V_9 , & V_24 ) ;
if ( V_16 == 0 || V_24 == 0 || V_9 == 0 )
return - V_56 ;
return * V_72 / V_16 * V_9 / V_24 ;
}
static unsigned long F_32 ( struct V_70 * V_70 ,
unsigned long V_72 )
{
struct V_1 * V_1 = F_28 ( V_70 ) ;
unsigned int V_16 , V_9 , V_24 ;
unsigned int V_4 ;
unsigned long long V_76 ;
F_3 ( V_1 , V_36 , & V_4 ) ;
V_24 = ( V_4 & 0x3f ) + ( ( V_4 >> 6 ) & 0x3f ) ;
F_3 ( V_1 , V_44 , & V_4 ) ;
V_16 = ( V_4 & 0x3f ) + ( ( V_4 >> 6 ) & 0x3f ) ;
F_3 ( V_1 , V_40 , & V_4 ) ;
V_9 = ( V_4 & 0x3f ) + ( ( V_4 >> 6 ) & 0x3f ) ;
if ( V_16 == 0 || V_24 == 0 )
return 0 ;
V_76 = ( unsigned long long ) ( V_72 / V_16 ) * V_9 ;
F_33 ( V_76 , V_24 ) ;
if ( V_76 > V_27 )
return V_27 ;
return V_76 ;
}
static int F_34 ( struct V_70 * V_70 )
{
struct V_1 * V_1 = F_28 ( V_70 ) ;
F_1 ( V_1 , true ) ;
return 0 ;
}
static void F_35 ( struct V_70 * V_70 )
{
struct V_1 * V_1 = F_28 ( V_70 ) ;
F_1 ( V_1 , false ) ;
}
static int F_36 ( struct V_77 * V_78 )
{
const struct V_79 * V_80 ;
struct V_1 * V_1 ;
struct V_81 V_82 ;
const char * V_83 ;
const char * V_84 ;
struct V_85 * V_86 ;
struct V_87 * V_87 ;
if ( ! V_78 -> V_88 . V_89 )
return - V_90 ;
V_80 = F_37 ( V_91 , V_78 -> V_88 . V_89 ) ;
if ( ! V_80 )
return - V_90 ;
V_1 = F_38 ( & V_78 -> V_88 , sizeof( * V_1 ) , V_92 ) ;
if ( ! V_1 )
return - V_93 ;
V_1 -> V_3 = V_80 -> V_94 ;
V_86 = F_39 ( V_78 , V_95 , 0 ) ;
V_1 -> V_35 = F_40 ( & V_78 -> V_88 , V_86 ) ;
if ( F_41 ( V_1 -> V_35 ) )
return F_42 ( V_1 -> V_35 ) ;
V_83 = F_43 ( V_78 -> V_88 . V_89 , 0 ) ;
if ( ! V_83 )
return - V_56 ;
V_84 = V_78 -> V_88 . V_89 -> V_96 ;
F_44 ( V_78 -> V_88 . V_89 , L_1 ,
& V_84 ) ;
V_82 . V_96 = V_84 ;
V_82 . V_97 = & V_98 ;
V_82 . V_99 = V_100 ;
V_82 . V_101 = & V_83 ;
V_82 . V_102 = 1 ;
F_1 ( V_1 , false ) ;
V_1 -> V_70 . V_82 = & V_82 ;
V_87 = F_45 ( & V_78 -> V_88 , & V_1 -> V_70 ) ;
if ( F_41 ( V_87 ) )
return F_42 ( V_87 ) ;
return F_46 ( V_78 -> V_88 . V_89 , V_103 ,
V_87 ) ;
}
static int F_47 ( struct V_77 * V_78 )
{
F_48 ( V_78 -> V_88 . V_89 ) ;
return 0 ;
}
