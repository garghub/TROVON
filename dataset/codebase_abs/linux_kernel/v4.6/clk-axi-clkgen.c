static T_1 F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
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
static T_1 F_2 ( unsigned int V_1 )
{
if ( V_1 < F_3 ( V_2 ) )
return V_2 [ V_1 ] ;
return 0x1f1f00fa ;
}
static void F_4 ( unsigned long V_3 , unsigned long V_4 ,
unsigned int * V_5 , unsigned int * V_6 , unsigned int * V_7 )
{
unsigned long V_8 , V_9 , V_10 , V_11 , V_12 ;
unsigned long V_1 , V_13 , V_14 ;
unsigned long V_15 , V_16 , V_17 , V_18 ;
V_3 /= 1000 ;
V_4 /= 1000 ;
V_17 = V_19 ;
* V_5 = 0 ;
* V_6 = 0 ;
* V_7 = 0 ;
V_9 = F_5 (unsigned long, DIV_ROUND_UP(fin, fpfd_max), 1 ) ;
V_10 = F_6 (unsigned long, fin / fpfd_min, 80 ) ;
V_13 = F_5 (unsigned long, DIV_ROUND_UP(fvco_min, fin) * d_min, 1 ) ;
V_14 = F_6 (unsigned long, fvco_max * d_max / fin, 64 ) ;
for ( V_1 = V_13 ; V_1 <= V_14 ; V_1 ++ ) {
V_11 = F_7 ( V_9 , F_8 ( V_3 * V_1 , V_20 ) ) ;
V_12 = F_9 ( V_10 , V_3 * V_1 / V_21 ) ;
for ( V_8 = V_11 ; V_8 <= V_12 ; V_8 ++ ) {
V_18 = V_3 * V_1 / V_8 ;
V_16 = F_10 ( V_18 , V_4 ) ;
V_16 = F_11 (unsigned long, dout, 1 , 128 ) ;
V_15 = V_18 / V_16 ;
if ( abs ( V_15 - V_4 ) < abs ( V_17 - V_4 ) ) {
V_17 = V_15 ;
* V_5 = V_8 ;
* V_6 = V_1 ;
* V_7 = V_16 ;
if ( V_17 == V_4 )
return;
}
}
}
}
static void F_12 ( unsigned int V_22 , unsigned int * V_23 ,
unsigned int * V_24 , unsigned int * V_25 , unsigned int * V_26 )
{
if ( V_22 == 1 )
* V_26 = 1 ;
else
* V_26 = 0 ;
* V_24 = V_22 / 2 ;
* V_25 = V_22 % 2 ;
* V_23 = V_22 - * V_24 ;
}
static void F_13 ( struct V_27 * V_27 ,
unsigned int V_28 , unsigned int V_29 )
{
F_14 ( V_29 , V_27 -> V_30 + V_28 ) ;
}
static void F_15 ( struct V_27 * V_27 ,
unsigned int V_28 , unsigned int * V_29 )
{
* V_29 = F_16 ( V_27 -> V_30 + V_28 ) ;
}
static int F_17 ( struct V_27 * V_27 )
{
unsigned int V_31 = 10000 ;
unsigned int V_29 ;
do {
F_15 ( V_27 , V_32 , & V_29 ) ;
} while ( ( V_29 & V_33 ) && -- V_31 );
if ( V_29 & V_33 )
return - V_34 ;
return V_29 & 0xffff ;
}
static int F_18 ( struct V_27 * V_27 ,
unsigned int V_28 , unsigned int * V_29 )
{
unsigned int V_35 ;
int V_36 ;
V_36 = F_17 ( V_27 ) ;
if ( V_36 < 0 )
return V_36 ;
V_35 = V_37 | V_38 ;
V_35 |= ( V_28 << 16 ) ;
F_13 ( V_27 , V_39 , V_35 ) ;
V_36 = F_17 ( V_27 ) ;
if ( V_36 < 0 )
return V_36 ;
* V_29 = V_36 ;
return 0 ;
}
static int F_19 ( struct V_27 * V_27 ,
unsigned int V_28 , unsigned int V_29 , unsigned int V_40 )
{
unsigned int V_35 = 0 ;
int V_36 ;
V_36 = F_17 ( V_27 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_40 != 0xffff ) {
F_18 ( V_27 , V_28 , & V_35 ) ;
V_35 &= ~ V_40 ;
}
V_35 |= V_37 | ( V_28 << 16 ) | ( V_29 & V_40 ) ;
F_13 ( V_27 , V_39 , V_35 ) ;
return 0 ;
}
static void F_20 ( struct V_27 * V_27 ,
bool V_41 )
{
unsigned int V_29 = V_42 ;
if ( V_41 )
V_29 |= V_43 ;
F_13 ( V_27 , V_44 , V_29 ) ;
}
static struct V_27 * F_21 ( struct V_45 * V_45 )
{
return F_22 ( V_45 , struct V_27 , V_45 ) ;
}
static int F_23 ( struct V_45 * V_45 ,
unsigned long V_46 , unsigned long V_47 )
{
struct V_27 * V_27 = F_21 ( V_45 ) ;
unsigned int V_8 , V_1 , V_16 ;
unsigned int V_26 ;
unsigned int V_24 ;
unsigned int V_25 ;
unsigned int V_23 ;
T_1 V_48 ;
T_1 V_49 ;
if ( V_47 == 0 || V_46 == 0 )
return - V_50 ;
F_4 ( V_47 , V_46 , & V_8 , & V_1 , & V_16 ) ;
if ( V_8 == 0 || V_16 == 0 || V_1 == 0 )
return - V_50 ;
V_48 = F_1 ( V_1 - 1 ) ;
V_49 = F_2 ( V_1 - 1 ) ;
F_12 ( V_16 , & V_23 , & V_24 , & V_25 , & V_26 ) ;
F_19 ( V_27 , V_51 ,
( V_24 << 6 ) | V_23 , 0xefff ) ;
F_19 ( V_27 , V_52 ,
( V_25 << 7 ) | ( V_26 << 6 ) , 0x03ff ) ;
F_12 ( V_8 , & V_23 , & V_24 , & V_25 , & V_26 ) ;
F_19 ( V_27 , V_53 ,
( V_25 << 13 ) | ( V_26 << 12 ) | ( V_24 << 6 ) | V_23 , 0x3fff ) ;
F_12 ( V_1 , & V_23 , & V_24 , & V_25 , & V_26 ) ;
F_19 ( V_27 , V_54 ,
( V_24 << 6 ) | V_23 , 0xefff ) ;
F_19 ( V_27 , V_55 ,
( V_25 << 7 ) | ( V_26 << 6 ) , 0x03ff ) ;
F_19 ( V_27 , V_56 , V_49 & 0x3ff , 0x3ff ) ;
F_19 ( V_27 , V_57 ,
( ( ( V_49 >> 16 ) & 0x1f ) << 10 ) | 0x1 , 0x7fff ) ;
F_19 ( V_27 , V_58 ,
( ( ( V_49 >> 24 ) & 0x1f ) << 10 ) | 0x3e9 , 0x7fff ) ;
F_19 ( V_27 , V_59 , V_48 >> 16 , 0x9900 ) ;
F_19 ( V_27 , V_60 , V_48 , 0x9900 ) ;
return 0 ;
}
static long F_24 ( struct V_45 * V_61 , unsigned long V_46 ,
unsigned long * V_47 )
{
unsigned int V_8 , V_1 , V_16 ;
F_4 ( * V_47 , V_46 , & V_8 , & V_1 , & V_16 ) ;
if ( V_8 == 0 || V_16 == 0 || V_1 == 0 )
return - V_50 ;
return * V_47 / V_8 * V_1 / V_16 ;
}
static unsigned long F_25 ( struct V_45 * V_45 ,
unsigned long V_47 )
{
struct V_27 * V_27 = F_21 ( V_45 ) ;
unsigned int V_8 , V_1 , V_16 ;
unsigned int V_28 ;
unsigned long long V_62 ;
F_18 ( V_27 , V_51 , & V_28 ) ;
V_16 = ( V_28 & 0x3f ) + ( ( V_28 >> 6 ) & 0x3f ) ;
F_18 ( V_27 , V_53 , & V_28 ) ;
V_8 = ( V_28 & 0x3f ) + ( ( V_28 >> 6 ) & 0x3f ) ;
F_18 ( V_27 , V_54 , & V_28 ) ;
V_1 = ( V_28 & 0x3f ) + ( ( V_28 >> 6 ) & 0x3f ) ;
if ( V_8 == 0 || V_16 == 0 )
return 0 ;
V_62 = ( unsigned long long ) ( V_47 / V_8 ) * V_1 ;
F_26 ( V_62 , V_16 ) ;
return F_6 (unsigned long long, tmp, ULONG_MAX) ;
}
static int F_27 ( struct V_45 * V_45 )
{
struct V_27 * V_27 = F_21 ( V_45 ) ;
F_20 ( V_27 , true ) ;
return 0 ;
}
static void F_28 ( struct V_45 * V_45 )
{
struct V_27 * V_27 = F_21 ( V_45 ) ;
F_20 ( V_27 , false ) ;
}
static int F_29 ( struct V_45 * V_45 , T_2 V_63 )
{
struct V_27 * V_27 = F_21 ( V_45 ) ;
F_13 ( V_27 , V_64 , V_63 ) ;
return 0 ;
}
static T_2 F_30 ( struct V_45 * V_45 )
{
struct V_27 * V_27 = F_21 ( V_45 ) ;
unsigned int V_65 ;
F_15 ( V_27 , V_64 , & V_65 ) ;
return V_65 ;
}
static int F_31 ( struct V_66 * V_67 )
{
const struct V_68 * V_69 ;
struct V_27 * V_27 ;
struct V_70 V_71 ;
const char * V_72 [ 2 ] ;
const char * V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_76 ;
unsigned int V_77 ;
if ( ! V_67 -> V_78 . V_79 )
return - V_80 ;
V_69 = F_32 ( V_81 , V_67 -> V_78 . V_79 ) ;
if ( ! V_69 )
return - V_80 ;
V_27 = F_33 ( & V_67 -> V_78 , sizeof( * V_27 ) , V_82 ) ;
if ( ! V_27 )
return - V_83 ;
V_75 = F_34 ( V_67 , V_84 , 0 ) ;
V_27 -> V_30 = F_35 ( & V_67 -> V_78 , V_75 ) ;
if ( F_36 ( V_27 -> V_30 ) )
return F_37 ( V_27 -> V_30 ) ;
V_71 . V_85 = F_38 ( V_67 -> V_78 . V_79 ) ;
if ( V_71 . V_85 < 1 || V_71 . V_85 > 2 )
return - V_50 ;
for ( V_77 = 0 ; V_77 < V_71 . V_85 ; V_77 ++ ) {
V_72 [ V_77 ] = F_39 ( V_67 -> V_78 . V_79 , V_77 ) ;
if ( ! V_72 [ V_77 ] )
return - V_50 ;
}
V_73 = V_67 -> V_78 . V_79 -> V_86 ;
F_40 ( V_67 -> V_78 . V_79 , L_1 ,
& V_73 ) ;
V_71 . V_86 = V_73 ;
V_71 . V_87 = & V_88 ;
V_71 . V_89 = V_90 | V_91 ;
V_71 . V_72 = V_72 ;
F_20 ( V_27 , false ) ;
V_27 -> V_45 . V_71 = & V_71 ;
V_76 = F_41 ( & V_67 -> V_78 , & V_27 -> V_45 ) ;
if ( F_36 ( V_76 ) )
return F_37 ( V_76 ) ;
return F_42 ( V_67 -> V_78 . V_79 , V_92 ,
V_76 ) ;
}
static int F_43 ( struct V_66 * V_67 )
{
F_44 ( V_67 -> V_78 . V_79 ) ;
return 0 ;
}
