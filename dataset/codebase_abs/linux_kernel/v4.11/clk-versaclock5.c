static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 <= 0xf )
return false ;
if ( V_3 == 0x14 || V_3 == 0x1c || V_3 == 0x1d )
return false ;
return true ;
}
static unsigned char F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 =
F_3 ( V_5 , struct V_6 , V_8 ) ;
const T_1 V_9 = V_10 | V_11 ;
unsigned int V_12 ;
F_4 ( V_7 -> V_13 , V_14 , & V_12 ) ;
V_12 &= V_9 ;
if ( V_12 == V_10 )
return 0 ;
if ( V_12 == V_11 )
return 1 ;
F_5 ( & V_7 -> V_15 -> V_2 ,
L_1 , V_12 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 , T_1 V_16 )
{
struct V_6 * V_7 =
F_3 ( V_5 , struct V_6 , V_8 ) ;
const T_1 V_9 = V_10 | V_11 ;
T_1 V_12 ;
if ( ( V_16 > 1 ) || ! V_7 -> V_17 )
return - V_18 ;
if ( V_7 -> V_17 == ( V_19 | V_20 ) ) {
if ( V_16 == 0 )
V_12 = V_10 ;
if ( V_16 == 1 )
V_12 = V_11 ;
} else {
if ( V_16 != 0 )
return - V_18 ;
if ( V_7 -> V_17 == V_20 )
V_12 = V_10 ;
if ( V_7 -> V_17 == V_19 )
V_12 = V_11 ;
}
return F_7 ( V_7 -> V_13 , V_14 , V_9 , V_12 ) ;
}
static unsigned long F_8 ( struct V_4 * V_5 ,
unsigned long V_21 )
{
struct V_6 * V_7 =
F_3 ( V_5 , struct V_6 , V_8 ) ;
unsigned int V_22 , div ;
F_4 ( V_7 -> V_13 , V_23 , & V_22 ) ;
if ( V_22 & V_24 )
return V_21 ;
F_4 ( V_7 -> V_13 , V_25 , & div ) ;
if ( div & V_26 )
return V_21 / 2 ;
else
return V_21 / F_9 ( div ) ;
}
static long F_10 ( struct V_4 * V_5 , unsigned long V_27 ,
unsigned long * V_21 )
{
unsigned long V_28 ;
if ( V_27 > 50000000 )
return - V_18 ;
if ( * V_21 <= 50000000 )
return * V_21 ;
V_28 = F_11 ( * V_21 , V_27 ) ;
if ( V_28 > 127 )
return - V_18 ;
return * V_21 / V_28 ;
}
static int F_12 ( struct V_4 * V_5 , unsigned long V_27 ,
unsigned long V_21 )
{
struct V_6 * V_7 =
F_3 ( V_5 , struct V_6 , V_8 ) ;
unsigned long V_28 ;
T_1 div ;
if ( V_21 <= 50000000 ) {
F_7 ( V_7 -> V_13 , V_23 ,
V_24 ,
V_24 ) ;
F_7 ( V_7 -> V_13 , V_25 , 0xff , 0x00 ) ;
return 0 ;
}
V_28 = F_11 ( V_21 , V_27 ) ;
if ( V_28 == 2 )
div = V_26 ;
else
div = F_9 ( V_28 ) ;
F_7 ( V_7 -> V_13 , V_25 , 0xff , div ) ;
F_7 ( V_7 -> V_13 , V_23 ,
V_24 , 0 ) ;
return 0 ;
}
static unsigned long F_13 ( struct V_4 * V_5 ,
unsigned long V_21 )
{
struct V_29 * V_30 = F_3 ( V_5 , struct V_29 , V_5 ) ;
struct V_6 * V_7 = V_30 -> V_7 ;
T_2 V_31 , V_32 ;
T_1 V_33 [ 5 ] ;
F_14 ( V_7 -> V_13 , V_34 , V_33 , 5 ) ;
V_31 = ( V_33 [ 0 ] << 4 ) | ( V_33 [ 1 ] >> 4 ) ;
V_32 = ( V_33 [ 2 ] << 16 ) | ( V_33 [ 3 ] << 8 ) | V_33 [ 4 ] ;
return ( V_21 * V_31 ) + ( ( V_21 * V_32 ) >> 24 ) ;
}
static long F_15 ( struct V_4 * V_5 , unsigned long V_27 ,
unsigned long * V_21 )
{
struct V_29 * V_30 = F_3 ( V_5 , struct V_29 , V_5 ) ;
T_2 V_31 ;
T_3 V_32 ;
if ( V_27 < V_35 )
V_27 = V_35 ;
if ( V_27 > V_36 )
V_27 = V_36 ;
V_31 = V_27 / * V_21 ;
if ( V_31 > 0xfff )
V_27 = * V_21 * 0xfff ;
V_32 = V_27 % * V_21 ;
V_32 *= F_16 ( 24 ) - 1 ;
F_17 ( V_32 , * V_21 ) ;
V_30 -> V_31 = V_31 ;
V_30 -> V_32 = ( T_2 ) V_32 ;
return ( * V_21 * V_31 ) + ( ( * V_21 * V_32 ) >> 24 ) ;
}
static int F_18 ( struct V_4 * V_5 , unsigned long V_27 ,
unsigned long V_21 )
{
struct V_29 * V_30 = F_3 ( V_5 , struct V_29 , V_5 ) ;
struct V_6 * V_7 = V_30 -> V_7 ;
T_1 V_33 [ 5 ] ;
V_33 [ 0 ] = V_30 -> V_31 >> 4 ;
V_33 [ 1 ] = V_30 -> V_31 << 4 ;
V_33 [ 2 ] = V_30 -> V_32 >> 16 ;
V_33 [ 3 ] = V_30 -> V_32 >> 8 ;
V_33 [ 4 ] = V_30 -> V_32 ;
return F_19 ( V_7 -> V_13 , V_34 , V_33 , 5 ) ;
}
static unsigned long F_20 ( struct V_4 * V_5 ,
unsigned long V_21 )
{
struct V_29 * V_30 = F_3 ( V_5 , struct V_29 , V_5 ) ;
struct V_6 * V_7 = V_30 -> V_7 ;
T_2 V_37 = V_21 / 2 ;
T_2 V_31 , V_32 ;
T_1 V_38 [ 2 ] ;
T_1 V_39 [ 4 ] ;
F_14 ( V_7 -> V_13 , F_21 ( V_30 -> V_40 , 0 ) ,
V_38 , 2 ) ;
F_14 ( V_7 -> V_13 , F_22 ( V_30 -> V_40 , 0 ) ,
V_39 , 4 ) ;
V_31 = ( V_38 [ 0 ] << 4 ) | ( V_38 [ 1 ] >> 4 ) ;
V_32 = ( V_39 [ 0 ] << 22 ) | ( V_39 [ 1 ] << 14 ) |
( V_39 [ 2 ] << 6 ) | ( V_39 [ 3 ] >> 2 ) ;
return F_23 ( ( T_3 ) V_37 << 24ULL , ( ( T_3 ) V_31 << 24ULL ) + V_32 ) ;
}
static long F_24 ( struct V_4 * V_5 , unsigned long V_27 ,
unsigned long * V_21 )
{
struct V_29 * V_30 = F_3 ( V_5 , struct V_29 , V_5 ) ;
T_2 V_37 = * V_21 / 2 ;
T_2 V_31 ;
T_3 V_32 ;
V_31 = V_37 / V_27 ;
if ( V_31 > 0xffe ) {
V_31 = 0xffe ;
V_27 = V_37 / V_31 ;
}
V_32 = V_37 % V_27 ;
V_32 <<= 24 ;
F_17 ( V_32 , V_27 ) ;
V_30 -> V_31 = V_31 ;
V_30 -> V_32 = ( T_2 ) V_32 ;
return F_23 ( ( T_3 ) V_37 << 24ULL , ( ( T_3 ) V_31 << 24ULL ) + V_32 ) ;
}
static int F_25 ( struct V_4 * V_5 , unsigned long V_27 ,
unsigned long V_21 )
{
struct V_29 * V_30 = F_3 ( V_5 , struct V_29 , V_5 ) ;
struct V_6 * V_7 = V_30 -> V_7 ;
T_1 V_41 [ 14 ] = {
V_30 -> V_32 >> 22 , V_30 -> V_32 >> 14 ,
V_30 -> V_32 >> 6 , V_30 -> V_32 << 2 ,
0 , 0 , 0 , 0 , 0 ,
0 , 0 ,
V_30 -> V_31 >> 4 , V_30 -> V_31 << 4 ,
0
} ;
F_19 ( V_7 -> V_13 , F_22 ( V_30 -> V_40 , 0 ) ,
V_41 , 14 ) ;
F_7 ( V_7 -> V_13 , V_42 ,
V_43 , 0 ) ;
F_7 ( V_7 -> V_13 , V_42 ,
V_43 ,
V_43 ) ;
return 0 ;
}
static int F_26 ( struct V_4 * V_5 )
{
struct V_29 * V_30 = F_3 ( V_5 , struct V_29 , V_5 ) ;
struct V_6 * V_7 = V_30 -> V_7 ;
F_7 ( V_7 -> V_13 , F_27 ( V_30 -> V_40 , 1 ) ,
V_44 ,
V_44 ) ;
return 0 ;
}
static void F_28 ( struct V_4 * V_5 )
{
struct V_29 * V_30 = F_3 ( V_5 , struct V_29 , V_5 ) ;
struct V_6 * V_7 = V_30 -> V_7 ;
F_7 ( V_7 -> V_13 , F_27 ( V_30 -> V_40 , 1 ) ,
V_44 , 0 ) ;
}
static unsigned char F_29 ( struct V_4 * V_5 )
{
struct V_29 * V_30 = F_3 ( V_5 , struct V_29 , V_5 ) ;
struct V_6 * V_7 = V_30 -> V_7 ;
const T_1 V_9 = V_45 |
V_46 |
V_47 ;
const T_1 V_48 = V_45 |
V_47 ;
const T_1 V_49 = V_45 |
V_46 ;
unsigned int V_12 ;
F_4 ( V_7 -> V_13 , F_30 ( V_30 -> V_40 ) , & V_12 ) ;
V_12 &= V_9 ;
if ( ( V_12 & V_48 ) == V_47 )
return 0 ;
if ( V_12 == V_49 )
return 1 ;
F_5 ( & V_7 -> V_15 -> V_2 ,
L_2 , V_12 ) ;
return 0 ;
}
static int F_31 ( struct V_4 * V_5 , T_1 V_16 )
{
struct V_29 * V_30 = F_3 ( V_5 , struct V_29 , V_5 ) ;
struct V_6 * V_7 = V_30 -> V_7 ;
const T_1 V_9 = V_50 |
V_45 |
V_46 |
V_47 ;
const T_1 V_49 = V_45 |
V_46 ;
T_1 V_12 = V_50 ;
if ( V_16 == 0 )
V_12 |= V_47 ;
else
V_12 |= V_49 ;
return F_7 ( V_7 -> V_13 , F_30 ( V_30 -> V_40 ) ,
V_9 , V_12 ) ;
}
static struct V_4 * F_32 ( struct V_51 * V_52 ,
void * V_41 )
{
struct V_6 * V_7 = V_41 ;
unsigned int V_53 = V_52 -> args [ 0 ] ;
if ( V_53 > 2 )
return F_33 ( - V_18 ) ;
return & V_7 -> V_54 [ V_53 ] . V_5 ;
}
static int F_34 ( const enum V_55 V_56 ,
const unsigned int V_57 )
{
switch ( V_56 ) {
case V_58 :
return ( V_57 == 0 ) ? 0 : 3 ;
case V_59 :
default:
return V_57 ;
}
}
static int F_35 ( struct V_60 * V_15 ,
const struct V_61 * V_62 )
{
const struct V_63 * V_64 =
F_36 ( V_65 , & V_15 -> V_2 ) ;
struct V_6 * V_7 ;
struct V_66 V_67 ;
const char * V_68 [ 2 ] ;
unsigned int V_57 , V_53 ;
int V_69 ;
V_7 = F_37 ( & V_15 -> V_2 , sizeof( * V_7 ) , V_70 ) ;
if ( V_7 == NULL )
return - V_71 ;
F_38 ( V_15 , V_7 ) ;
V_7 -> V_15 = V_15 ;
V_7 -> V_56 = (enum V_55 ) V_64 -> V_41 ;
V_7 -> V_72 = F_39 ( & V_15 -> V_2 , L_3 ) ;
if ( F_40 ( V_7 -> V_72 ) == - V_73 )
return - V_73 ;
V_7 -> V_74 = F_39 ( & V_15 -> V_2 , L_4 ) ;
if ( F_40 ( V_7 -> V_74 ) == - V_73 )
return - V_73 ;
V_7 -> V_13 = F_41 ( V_15 , & V_75 ) ;
if ( F_42 ( V_7 -> V_13 ) ) {
F_43 ( & V_15 -> V_2 , L_5 ) ;
return F_40 ( V_7 -> V_13 ) ;
}
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
if ( ! F_42 ( V_7 -> V_72 ) ) {
V_7 -> V_17 |= V_20 ;
V_68 [ V_67 . V_76 ++ ] = F_44 ( V_7 -> V_72 ) ;
} else if ( V_7 -> V_56 == V_58 ) {
V_7 -> V_72 = F_45 ( & V_15 -> V_2 ,
L_6 , NULL ,
0 , 25000000 ) ;
if ( F_42 ( V_7 -> V_72 ) )
return F_40 ( V_7 -> V_72 ) ;
V_7 -> V_17 |= V_20 ;
V_68 [ V_67 . V_76 ++ ] = F_44 ( V_7 -> V_72 ) ;
}
if ( ! F_42 ( V_7 -> V_74 ) ) {
V_7 -> V_17 |= V_19 ;
V_68 [ V_67 . V_76 ++ ] =
F_44 ( V_7 -> V_74 ) ;
}
if ( ! V_67 . V_76 ) {
F_43 ( & V_15 -> V_2 , L_7 ) ;
return - V_18 ;
}
V_67 . V_77 = V_78 [ 0 ] ;
V_67 . V_79 = & V_80 ;
V_67 . V_81 = 0 ;
V_67 . V_68 = V_68 ;
V_7 -> V_8 . V_67 = & V_67 ;
V_69 = F_46 ( & V_15 -> V_2 , & V_7 -> V_8 ) ;
if ( V_69 ) {
F_43 ( & V_15 -> V_2 , L_8 , V_67 . V_77 ) ;
goto V_82;
}
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_77 = V_83 [ 0 ] ;
V_67 . V_79 = & V_84 ;
V_67 . V_81 = V_85 ;
V_67 . V_68 = V_78 ;
V_67 . V_76 = 1 ;
V_7 -> V_86 . V_40 = 0 ;
V_7 -> V_86 . V_7 = V_7 ;
V_7 -> V_86 . V_5 . V_67 = & V_67 ;
V_69 = F_46 ( & V_15 -> V_2 , & V_7 -> V_86 . V_5 ) ;
if ( V_69 ) {
F_43 ( & V_15 -> V_2 , L_8 , V_67 . V_77 ) ;
goto V_82;
}
for ( V_57 = 0 ; V_57 < 2 ; V_57 ++ ) {
V_53 = F_34 ( V_7 -> V_56 , V_57 ) ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_77 = V_87 [ V_53 ] ;
V_67 . V_79 = & V_88 ;
V_67 . V_81 = V_85 ;
V_67 . V_68 = V_83 ;
V_67 . V_76 = 1 ;
V_7 -> V_89 [ V_57 ] . V_40 = V_53 ;
V_7 -> V_89 [ V_57 ] . V_7 = V_7 ;
V_7 -> V_89 [ V_57 ] . V_5 . V_67 = & V_67 ;
V_69 = F_46 ( & V_15 -> V_2 , & V_7 -> V_89 [ V_57 ] . V_5 ) ;
if ( V_69 ) {
F_43 ( & V_15 -> V_2 , L_8 ,
V_67 . V_77 ) ;
goto V_82;
}
}
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_77 = V_90 [ 0 ] ;
V_67 . V_79 = & V_91 ;
V_67 . V_81 = V_85 ;
V_67 . V_68 = V_78 ;
V_67 . V_76 = 1 ;
V_7 -> V_54 [ 0 ] . V_40 = V_53 ;
V_7 -> V_54 [ 0 ] . V_7 = V_7 ;
V_7 -> V_54 [ 0 ] . V_5 . V_67 = & V_67 ;
V_69 = F_46 ( & V_15 -> V_2 , & V_7 -> V_54 [ 0 ] . V_5 ) ;
if ( V_69 ) {
F_43 ( & V_15 -> V_2 , L_8 ,
V_67 . V_77 ) ;
goto V_82;
}
for ( V_57 = 1 ; V_57 < 3 ; V_57 ++ ) {
V_53 = F_34 ( V_7 -> V_56 , V_57 - 1 ) ;
V_68 [ 0 ] = V_87 [ V_53 ] ;
if ( V_57 == 1 )
V_68 [ 1 ] = V_78 [ 0 ] ;
else
V_68 [ 1 ] = V_90 [ V_57 - 1 ] ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_77 = V_90 [ V_53 + 1 ] ;
V_67 . V_79 = & V_91 ;
V_67 . V_81 = V_85 ;
V_67 . V_68 = V_68 ;
V_67 . V_76 = 2 ;
V_7 -> V_54 [ V_57 ] . V_40 = V_53 ;
V_7 -> V_54 [ V_57 ] . V_7 = V_7 ;
V_7 -> V_54 [ V_57 ] . V_5 . V_67 = & V_67 ;
V_69 = F_46 ( & V_15 -> V_2 ,
& V_7 -> V_54 [ V_57 ] . V_5 ) ;
if ( V_69 ) {
F_43 ( & V_15 -> V_2 , L_8 ,
V_67 . V_77 ) ;
goto V_82;
}
}
V_69 = F_47 ( V_15 -> V_2 . V_92 , F_32 , V_7 ) ;
if ( V_69 ) {
F_43 ( & V_15 -> V_2 , L_9 ) ;
goto V_82;
}
return 0 ;
V_82:
if ( V_7 -> V_56 == V_58 )
F_48 ( V_7 -> V_72 ) ;
return V_69 ;
}
static int F_49 ( struct V_60 * V_15 )
{
struct V_6 * V_7 = F_50 ( V_15 ) ;
F_51 ( V_15 -> V_2 . V_92 ) ;
if ( V_7 -> V_56 == V_58 )
F_48 ( V_7 -> V_72 ) ;
return 0 ;
}
