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
F_3 ( V_5 , struct V_6 , V_22 ) ;
unsigned int V_23 ;
F_4 ( V_7 -> V_13 , V_14 , & V_23 ) ;
if ( V_23 & V_24 )
V_21 *= 2 ;
return V_21 ;
}
static long F_9 ( struct V_4 * V_5 , unsigned long V_25 ,
unsigned long * V_21 )
{
if ( ( * V_21 == V_25 ) || ( ( * V_21 * 2 ) == V_25 ) )
return V_25 ;
else
return - V_18 ;
}
static int F_10 ( struct V_4 * V_5 , unsigned long V_25 ,
unsigned long V_21 )
{
struct V_6 * V_7 =
F_3 ( V_5 , struct V_6 , V_22 ) ;
T_2 V_9 ;
if ( ( V_21 * 2 ) == V_25 )
V_9 = V_24 ;
else
V_9 = 0 ;
F_7 ( V_7 -> V_13 , V_14 ,
V_24 ,
V_9 ) ;
return 0 ;
}
static unsigned long F_11 ( struct V_4 * V_5 ,
unsigned long V_21 )
{
struct V_6 * V_7 =
F_3 ( V_5 , struct V_6 , V_26 ) ;
unsigned int V_27 , div ;
F_4 ( V_7 -> V_13 , V_28 , & V_27 ) ;
if ( V_27 & V_29 )
return V_21 ;
F_4 ( V_7 -> V_13 , V_30 , & div ) ;
if ( div & V_31 )
return V_21 / 2 ;
else
return V_21 / F_12 ( div ) ;
}
static long F_13 ( struct V_4 * V_5 , unsigned long V_25 ,
unsigned long * V_21 )
{
unsigned long V_32 ;
if ( V_25 > 50000000 )
return - V_18 ;
if ( * V_21 <= 50000000 )
return * V_21 ;
V_32 = F_14 ( * V_21 , V_25 ) ;
if ( V_32 > 127 )
return - V_18 ;
return * V_21 / V_32 ;
}
static int F_15 ( struct V_4 * V_5 , unsigned long V_25 ,
unsigned long V_21 )
{
struct V_6 * V_7 =
F_3 ( V_5 , struct V_6 , V_26 ) ;
unsigned long V_32 ;
T_1 div ;
if ( V_21 <= 50000000 ) {
F_7 ( V_7 -> V_13 , V_28 ,
V_29 ,
V_29 ) ;
F_7 ( V_7 -> V_13 , V_30 , 0xff , 0x00 ) ;
return 0 ;
}
V_32 = F_14 ( V_21 , V_25 ) ;
if ( V_32 == 2 )
div = V_31 ;
else
div = F_12 ( V_32 ) ;
F_7 ( V_7 -> V_13 , V_30 , 0xff , div ) ;
F_7 ( V_7 -> V_13 , V_28 ,
V_29 , 0 ) ;
return 0 ;
}
static unsigned long F_16 ( struct V_4 * V_5 ,
unsigned long V_21 )
{
struct V_33 * V_34 = F_3 ( V_5 , struct V_33 , V_5 ) ;
struct V_6 * V_7 = V_34 -> V_7 ;
T_2 V_35 , V_36 ;
T_1 V_37 [ 5 ] ;
F_17 ( V_7 -> V_13 , V_38 , V_37 , 5 ) ;
V_35 = ( V_37 [ 0 ] << 4 ) | ( V_37 [ 1 ] >> 4 ) ;
V_36 = ( V_37 [ 2 ] << 16 ) | ( V_37 [ 3 ] << 8 ) | V_37 [ 4 ] ;
return ( V_21 * V_35 ) + ( ( V_21 * V_36 ) >> 24 ) ;
}
static long F_18 ( struct V_4 * V_5 , unsigned long V_25 ,
unsigned long * V_21 )
{
struct V_33 * V_34 = F_3 ( V_5 , struct V_33 , V_5 ) ;
T_2 V_35 ;
T_3 V_36 ;
if ( V_25 < V_39 )
V_25 = V_39 ;
if ( V_25 > V_40 )
V_25 = V_40 ;
V_35 = V_25 / * V_21 ;
if ( V_35 > 0xfff )
V_25 = * V_21 * 0xfff ;
V_36 = V_25 % * V_21 ;
V_36 *= F_19 ( 24 ) - 1 ;
F_20 ( V_36 , * V_21 ) ;
V_34 -> V_35 = V_35 ;
V_34 -> V_36 = ( T_2 ) V_36 ;
return ( * V_21 * V_35 ) + ( ( * V_21 * V_36 ) >> 24 ) ;
}
static int F_21 ( struct V_4 * V_5 , unsigned long V_25 ,
unsigned long V_21 )
{
struct V_33 * V_34 = F_3 ( V_5 , struct V_33 , V_5 ) ;
struct V_6 * V_7 = V_34 -> V_7 ;
T_1 V_37 [ 5 ] ;
V_37 [ 0 ] = V_34 -> V_35 >> 4 ;
V_37 [ 1 ] = V_34 -> V_35 << 4 ;
V_37 [ 2 ] = V_34 -> V_36 >> 16 ;
V_37 [ 3 ] = V_34 -> V_36 >> 8 ;
V_37 [ 4 ] = V_34 -> V_36 ;
return F_22 ( V_7 -> V_13 , V_38 , V_37 , 5 ) ;
}
static unsigned long F_23 ( struct V_4 * V_5 ,
unsigned long V_21 )
{
struct V_33 * V_34 = F_3 ( V_5 , struct V_33 , V_5 ) ;
struct V_6 * V_7 = V_34 -> V_7 ;
T_2 V_41 = V_21 / 2 ;
T_2 V_35 , V_36 ;
T_1 V_42 [ 2 ] ;
T_1 V_43 [ 4 ] ;
F_17 ( V_7 -> V_13 , F_24 ( V_34 -> V_44 , 0 ) ,
V_42 , 2 ) ;
F_17 ( V_7 -> V_13 , F_25 ( V_34 -> V_44 , 0 ) ,
V_43 , 4 ) ;
V_35 = ( V_42 [ 0 ] << 4 ) | ( V_42 [ 1 ] >> 4 ) ;
V_36 = ( V_43 [ 0 ] << 22 ) | ( V_43 [ 1 ] << 14 ) |
( V_43 [ 2 ] << 6 ) | ( V_43 [ 3 ] >> 2 ) ;
if ( V_35 == 0 && V_36 == 0 )
return 0 ;
return F_26 ( ( T_3 ) V_41 << 24ULL , ( ( T_3 ) V_35 << 24ULL ) + V_36 ) ;
}
static long F_27 ( struct V_4 * V_5 , unsigned long V_25 ,
unsigned long * V_21 )
{
struct V_33 * V_34 = F_3 ( V_5 , struct V_33 , V_5 ) ;
T_2 V_41 = * V_21 / 2 ;
T_2 V_35 ;
T_3 V_36 ;
V_35 = V_41 / V_25 ;
if ( V_35 > 0xffe ) {
V_35 = 0xffe ;
V_25 = V_41 / V_35 ;
}
V_36 = V_41 % V_25 ;
V_36 <<= 24 ;
F_20 ( V_36 , V_25 ) ;
V_34 -> V_35 = V_35 ;
V_34 -> V_36 = ( T_2 ) V_36 ;
return F_26 ( ( T_3 ) V_41 << 24ULL , ( ( T_3 ) V_35 << 24ULL ) + V_36 ) ;
}
static int F_28 ( struct V_4 * V_5 , unsigned long V_25 ,
unsigned long V_21 )
{
struct V_33 * V_34 = F_3 ( V_5 , struct V_33 , V_5 ) ;
struct V_6 * V_7 = V_34 -> V_7 ;
T_1 V_45 [ 14 ] = {
V_34 -> V_36 >> 22 , V_34 -> V_36 >> 14 ,
V_34 -> V_36 >> 6 , V_34 -> V_36 << 2 ,
0 , 0 , 0 , 0 , 0 ,
0 , 0 ,
V_34 -> V_35 >> 4 , V_34 -> V_35 << 4 ,
0
} ;
F_22 ( V_7 -> V_13 , F_25 ( V_34 -> V_44 , 0 ) ,
V_45 , 14 ) ;
F_7 ( V_7 -> V_13 , V_46 ,
V_47 , 0 ) ;
F_7 ( V_7 -> V_13 , V_46 ,
V_47 ,
V_47 ) ;
return 0 ;
}
static int F_29 ( struct V_4 * V_5 )
{
struct V_33 * V_34 = F_3 ( V_5 , struct V_33 , V_5 ) ;
struct V_6 * V_7 = V_34 -> V_7 ;
const T_1 V_9 = V_48 |
V_49 |
V_50 ;
unsigned int V_12 ;
int V_51 ;
F_4 ( V_7 -> V_13 , F_30 ( V_34 -> V_44 ) , & V_12 ) ;
if ( ( V_12 & V_9 ) == 0 ) {
V_12 = V_52 | V_50 ;
V_51 = F_7 ( V_7 -> V_13 ,
F_30 ( V_34 -> V_44 ) ,
V_9 | V_52 , V_12 ) ;
if ( V_51 )
return V_51 ;
}
F_7 ( V_7 -> V_13 , F_31 ( V_34 -> V_44 , 1 ) ,
V_53 ,
V_53 ) ;
return 0 ;
}
static void F_32 ( struct V_4 * V_5 )
{
struct V_33 * V_34 = F_3 ( V_5 , struct V_33 , V_5 ) ;
struct V_6 * V_7 = V_34 -> V_7 ;
F_7 ( V_7 -> V_13 , F_31 ( V_34 -> V_44 , 1 ) ,
V_53 , 0 ) ;
}
static unsigned char F_33 ( struct V_4 * V_5 )
{
struct V_33 * V_34 = F_3 ( V_5 , struct V_33 , V_5 ) ;
struct V_6 * V_7 = V_34 -> V_7 ;
const T_1 V_9 = V_48 |
V_49 |
V_50 ;
const T_1 V_54 = V_48 |
V_50 ;
const T_1 V_55 = V_48 |
V_49 ;
unsigned int V_12 ;
F_4 ( V_7 -> V_13 , F_30 ( V_34 -> V_44 ) , & V_12 ) ;
V_12 &= V_9 ;
if ( V_12 == 0 )
return 0 ;
if ( ( V_12 & V_54 ) == V_50 )
return 0 ;
if ( V_12 == V_55 )
return 1 ;
F_5 ( & V_7 -> V_15 -> V_2 ,
L_2 , V_12 ) ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 , T_1 V_16 )
{
struct V_33 * V_34 = F_3 ( V_5 , struct V_33 , V_5 ) ;
struct V_6 * V_7 = V_34 -> V_7 ;
const T_1 V_9 = V_52 |
V_48 |
V_49 |
V_50 ;
const T_1 V_55 = V_48 |
V_49 ;
T_1 V_12 = V_52 ;
if ( V_16 == 0 )
V_12 |= V_50 ;
else
V_12 |= V_55 ;
return F_7 ( V_7 -> V_13 , F_30 ( V_34 -> V_44 ) ,
V_9 , V_12 ) ;
}
static struct V_4 * F_35 ( struct V_56 * V_57 ,
void * V_45 )
{
struct V_6 * V_7 = V_45 ;
unsigned int V_58 = V_57 -> args [ 0 ] ;
if ( V_58 >= V_7 -> V_59 -> V_60 )
return F_36 ( - V_18 ) ;
return & V_7 -> V_61 [ V_58 ] . V_5 ;
}
static int F_37 ( const enum V_62 V_63 ,
const unsigned int V_64 )
{
switch ( V_63 ) {
case V_65 :
return ( V_64 == 0 ) ? 0 : 3 ;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
default:
return V_64 ;
}
}
static int F_38 ( struct V_70 * V_15 ,
const struct V_71 * V_72 )
{
struct V_6 * V_7 ;
struct V_73 V_74 ;
const char * V_75 [ 2 ] ;
unsigned int V_64 , V_58 = 0 ;
int V_51 ;
V_7 = F_39 ( & V_15 -> V_2 , sizeof( * V_7 ) , V_76 ) ;
if ( V_7 == NULL )
return - V_77 ;
F_40 ( V_15 , V_7 ) ;
V_7 -> V_15 = V_15 ;
V_7 -> V_59 = F_41 ( & V_15 -> V_2 ) ;
V_7 -> V_78 = F_42 ( & V_15 -> V_2 , L_3 ) ;
if ( F_43 ( V_7 -> V_78 ) == - V_79 )
return - V_79 ;
V_7 -> V_80 = F_42 ( & V_15 -> V_2 , L_4 ) ;
if ( F_43 ( V_7 -> V_80 ) == - V_79 )
return - V_79 ;
V_7 -> V_13 = F_44 ( V_15 , & V_81 ) ;
if ( F_45 ( V_7 -> V_13 ) ) {
F_46 ( & V_15 -> V_2 , L_5 ) ;
return F_43 ( V_7 -> V_13 ) ;
}
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
if ( ! F_45 ( V_7 -> V_78 ) ) {
V_7 -> V_17 |= V_20 ;
V_75 [ V_74 . V_82 ++ ] = F_47 ( V_7 -> V_78 ) ;
} else if ( V_7 -> V_59 -> V_83 & V_84 ) {
V_7 -> V_78 = F_48 ( & V_15 -> V_2 ,
L_6 , NULL ,
0 , 25000000 ) ;
if ( F_45 ( V_7 -> V_78 ) )
return F_43 ( V_7 -> V_78 ) ;
V_7 -> V_17 |= V_20 ;
V_75 [ V_74 . V_82 ++ ] = F_47 ( V_7 -> V_78 ) ;
}
if ( ! F_45 ( V_7 -> V_80 ) ) {
V_7 -> V_17 |= V_19 ;
V_75 [ V_74 . V_82 ++ ] =
F_47 ( V_7 -> V_80 ) ;
}
if ( ! V_74 . V_82 ) {
F_46 ( & V_15 -> V_2 , L_7 ) ;
return - V_18 ;
}
V_74 . V_85 = V_86 [ 0 ] ;
V_74 . V_87 = & V_88 ;
V_74 . V_83 = 0 ;
V_74 . V_75 = V_75 ;
V_7 -> V_8 . V_74 = & V_74 ;
V_51 = F_49 ( & V_15 -> V_2 , & V_7 -> V_8 ) ;
if ( V_51 ) {
F_46 ( & V_15 -> V_2 , L_8 , V_74 . V_85 ) ;
goto V_89;
}
if ( V_7 -> V_59 -> V_83 & V_90 ) {
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_85 = V_91 [ 0 ] ;
V_74 . V_87 = & V_92 ;
V_74 . V_83 = V_93 ;
V_74 . V_75 = V_86 ;
V_74 . V_82 = 1 ;
V_7 -> V_22 . V_74 = & V_74 ;
V_51 = F_49 ( & V_15 -> V_2 , & V_7 -> V_22 ) ;
if ( V_51 ) {
F_46 ( & V_15 -> V_2 , L_8 ,
V_74 . V_85 ) ;
goto V_89;
}
}
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_85 = V_94 [ 0 ] ;
V_74 . V_87 = & V_95 ;
V_74 . V_83 = V_93 ;
if ( V_7 -> V_59 -> V_83 & V_90 )
V_74 . V_75 = V_91 ;
else
V_74 . V_75 = V_86 ;
V_74 . V_82 = 1 ;
V_7 -> V_26 . V_74 = & V_74 ;
V_51 = F_49 ( & V_15 -> V_2 , & V_7 -> V_26 ) ;
if ( V_51 ) {
F_46 ( & V_15 -> V_2 , L_8 , V_74 . V_85 ) ;
goto V_89;
}
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_85 = V_96 [ 0 ] ;
V_74 . V_87 = & V_97 ;
V_74 . V_83 = V_93 ;
V_74 . V_75 = V_94 ;
V_74 . V_82 = 1 ;
V_7 -> V_98 . V_44 = 0 ;
V_7 -> V_98 . V_7 = V_7 ;
V_7 -> V_98 . V_5 . V_74 = & V_74 ;
V_51 = F_49 ( & V_15 -> V_2 , & V_7 -> V_98 . V_5 ) ;
if ( V_51 ) {
F_46 ( & V_15 -> V_2 , L_8 , V_74 . V_85 ) ;
goto V_89;
}
for ( V_64 = 0 ; V_64 < V_7 -> V_59 -> V_99 ; V_64 ++ ) {
V_58 = F_37 ( V_7 -> V_59 -> V_63 , V_64 ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_85 = V_100 [ V_58 ] ;
V_74 . V_87 = & V_101 ;
V_74 . V_83 = V_93 ;
V_74 . V_75 = V_96 ;
V_74 . V_82 = 1 ;
V_7 -> V_102 [ V_64 ] . V_44 = V_58 ;
V_7 -> V_102 [ V_64 ] . V_7 = V_7 ;
V_7 -> V_102 [ V_64 ] . V_5 . V_74 = & V_74 ;
V_51 = F_49 ( & V_15 -> V_2 , & V_7 -> V_102 [ V_64 ] . V_5 ) ;
if ( V_51 ) {
F_46 ( & V_15 -> V_2 , L_8 ,
V_74 . V_85 ) ;
goto V_89;
}
}
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_85 = V_103 [ 0 ] ;
V_74 . V_87 = & V_104 ;
V_74 . V_83 = V_93 ;
V_74 . V_75 = V_86 ;
V_74 . V_82 = 1 ;
V_7 -> V_61 [ 0 ] . V_44 = V_58 ;
V_7 -> V_61 [ 0 ] . V_7 = V_7 ;
V_7 -> V_61 [ 0 ] . V_5 . V_74 = & V_74 ;
V_51 = F_49 ( & V_15 -> V_2 , & V_7 -> V_61 [ 0 ] . V_5 ) ;
if ( V_51 ) {
F_46 ( & V_15 -> V_2 , L_8 ,
V_74 . V_85 ) ;
goto V_89;
}
for ( V_64 = 1 ; V_64 < V_7 -> V_59 -> V_60 ; V_64 ++ ) {
V_58 = F_37 ( V_7 -> V_59 -> V_63 , V_64 - 1 ) ;
V_75 [ 0 ] = V_100 [ V_58 ] ;
if ( V_64 == 1 )
V_75 [ 1 ] = V_86 [ 0 ] ;
else
V_75 [ 1 ] = V_103 [ V_64 - 1 ] ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_85 = V_103 [ V_58 + 1 ] ;
V_74 . V_87 = & V_104 ;
V_74 . V_83 = V_93 ;
V_74 . V_75 = V_75 ;
V_74 . V_82 = 2 ;
V_7 -> V_61 [ V_64 ] . V_44 = V_58 ;
V_7 -> V_61 [ V_64 ] . V_7 = V_7 ;
V_7 -> V_61 [ V_64 ] . V_5 . V_74 = & V_74 ;
V_51 = F_49 ( & V_15 -> V_2 ,
& V_7 -> V_61 [ V_64 ] . V_5 ) ;
if ( V_51 ) {
F_46 ( & V_15 -> V_2 , L_8 ,
V_74 . V_85 ) ;
goto V_89;
}
}
V_51 = F_50 ( V_15 -> V_2 . V_105 , F_35 , V_7 ) ;
if ( V_51 ) {
F_46 ( & V_15 -> V_2 , L_9 ) ;
goto V_89;
}
return 0 ;
V_89:
if ( V_7 -> V_59 -> V_83 & V_84 )
F_51 ( V_7 -> V_78 ) ;
return V_51 ;
}
static int F_52 ( struct V_70 * V_15 )
{
struct V_6 * V_7 = F_53 ( V_15 ) ;
F_54 ( V_15 -> V_2 . V_105 ) ;
if ( V_7 -> V_59 -> V_83 & V_84 )
F_51 ( V_7 -> V_78 ) ;
return 0 ;
}
