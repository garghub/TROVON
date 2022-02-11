static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_6 , int clock )
{
static const unsigned char V_7 [] = {
6 , 6 , 5 , 4 , 0 , 1 , 1 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 7
} ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_11 ) ;
struct V_3 * V_12 = F_3 ( V_4 ) ;
int V_13 = V_2 -> V_14 * 2 + V_4 -> V_15 ;
struct V_16 V_17 , V_18 ;
int V_19 , V_20 ;
const int V_21 = 33333 ;
T_1 V_22 ;
V_19 = 1000000000 / V_21 ;
V_20 = V_19 ;
if ( clock >= 2 )
V_20 = V_19 / 2 ;
if ( F_4 ( V_4 , V_6 , & V_17 , V_19 , V_20 ) < 0 ) {
F_5 ( V_23 , & V_9 -> V_11 , L_1 , V_6 ) ;
return;
}
if ( V_12 ) {
if ( V_12 -> V_24 ) {
F_4 ( V_12 , V_12 -> V_24 , & V_18 , V_19 , V_20 ) ;
F_6 ( & V_18 , & V_17 , & V_17 , V_25 ) ;
}
F_4 ( V_12 , V_12 -> V_26 , & V_18 , V_19 , V_20 ) ;
F_6 ( & V_18 , & V_17 , & V_17 , V_25 ) ;
}
if ( V_6 == V_27 && V_21 <= 33333 ) V_17 . V_28 = 1 ;
if ( V_6 == V_29 && V_21 <= 33333 ) V_17 . V_28 = 15 ;
F_7 ( V_9 , V_5 + 0x0C , & V_22 ) ;
V_22 = ( V_22 & ~ ( 3 << ( ( 3 - V_13 ) << 1 ) ) ) | ( ( F_8 ( V_17 . V_30 , 1 , 4 ) - 1 ) << ( ( 3 - V_13 ) << 1 ) ) ;
F_9 ( V_9 , V_5 + 0x0C , V_22 ) ;
F_9 ( V_9 , V_5 + 0x0E + ( 1 - ( V_13 >> 1 ) ) ,
( ( F_8 ( V_17 . V_31 , 1 , 16 ) - 1 ) << 4 ) | ( F_8 ( V_17 . V_32 , 1 , 16 ) - 1 ) ) ;
F_9 ( V_9 , V_5 + 0x08 + ( 3 - V_13 ) ,
( ( F_8 ( V_17 . V_33 , 1 , 16 ) - 1 ) << 4 ) | ( F_8 ( V_17 . V_34 , 1 , 16 ) - 1 ) ) ;
switch ( clock ) {
case 1 :
V_22 = V_17 . V_28 ? ( 0xc0 | ( F_8 ( V_17 . V_28 , 2 , 5 ) - 2 ) ) : 0x03 ;
break;
case 2 :
V_22 = V_17 . V_28 ? ( 0xc0 | V_7 [ F_8 ( V_17 . V_28 , 2 , 10 ) ] ) : 0x03 ;
break;
case 3 :
V_22 = V_17 . V_28 ? ( 0xc0 | V_7 [ F_8 ( V_17 . V_28 , 1 , 10 ) ] ) : 0x03 ;
break;
case 4 :
V_22 = V_17 . V_28 ? ( 0xc0 | V_7 [ F_8 ( V_17 . V_28 , 1 , 15 ) ] ) : 0x03 ;
break;
default:
return;
}
if ( V_17 . V_28 )
F_9 ( V_9 , V_5 + 0x10 + ( 3 - V_13 ) , V_22 ) ;
}
static int F_10 ( struct V_35 * V_36 , unsigned long V_37 )
{
static const struct V_38 V_39 [] = {
{ 0x40 , 1 , 0x02 , 0x02 } ,
{ 0x40 , 1 , 0x01 , 0x01 }
} ;
struct V_1 * V_2 = V_36 -> V_2 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_11 ) ;
if ( ! F_11 ( V_9 , & V_39 [ V_2 -> V_14 ] ) )
return - V_40 ;
return F_12 ( V_36 , V_37 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
static const T_2 V_41 [ 2 ] = { 0x03 , 0x0C } ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_11 ) ;
T_1 V_42 ;
F_7 ( V_9 , 0x42 , & V_42 ) ;
if ( V_42 & V_41 [ V_2 -> V_14 ] )
return V_43 ;
return V_44 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_11 ) ;
static const T_1 V_45 [ 2 ] = { 0xC0 , 0x30 } ;
T_1 V_46 = V_45 [ V_2 -> V_14 ] ;
T_1 V_47 ;
F_15 (adev, &ap->link, ENABLED) {
if ( V_4 -> V_48 == V_49 )
V_46 = 0 ;
}
if ( V_9 -> V_50 == V_51 )
V_46 = 0 ;
F_7 ( V_9 , 0x41 , & V_47 ) ;
V_47 &= ~ V_45 [ V_2 -> V_14 ] ;
V_47 |= V_46 ;
F_9 ( V_9 , 0x41 , V_47 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_14 ( V_2 ) ;
F_1 ( V_2 , V_4 , 0x40 , V_4 -> V_26 , 1 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_14 ( V_2 ) ;
F_1 ( V_2 , V_4 , 0x40 , V_4 -> V_26 , 2 ) ;
}
static void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_14 ( V_2 ) ;
F_1 ( V_2 , V_4 , 0x40 , V_4 -> V_26 , 3 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_14 ( V_2 ) ;
F_1 ( V_2 , V_4 , 0x40 , V_4 -> V_26 , 4 ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , 0x40 , V_4 -> V_24 , 1 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , 0x40 , V_4 -> V_24 , 2 ) ;
}
static void F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , 0x40 , V_4 -> V_24 , 3 ) ;
}
static void F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , 0x40 , V_4 -> V_24 , 4 ) ;
}
static unsigned long F_24 ( struct V_3 * V_11 ,
unsigned long V_52 )
{
static const unsigned int V_53 [] =
{ V_54 , V_55 , V_56 , 0 ,
V_57 , V_58 , V_59 , V_60 } ;
struct V_1 * V_2 = V_11 -> V_36 -> V_2 ;
char V_61 [ 32 ] = L_2 ;
T_2 V_62 , V_28 ;
const struct V_63 * V_64 ;
unsigned long V_65 = 0 , V_66 = 0 , V_67 ;
V_28 = V_62 = ( unsigned long ) V_2 -> V_10 -> V_68 ;
if ( V_2 -> V_14 == 0 )
V_28 >>= 16 ;
if ( V_11 -> V_15 == 0 )
V_28 >>= 8 ;
if ( ( V_28 & 0xc0 ) == 0xc0 )
V_65 = F_25 ( 0 , 0 , V_53 [ V_28 & 0x7 ] ) ;
V_64 = F_26 ( V_2 ) ;
if ( V_64 ) {
V_66 = F_27 ( V_11 , V_64 ) ;
snprintf ( V_61 , sizeof( V_61 ) , L_3 ,
V_64 -> V_69 [ 0 ] . V_70 , V_64 -> V_69 [ 1 ] . V_70 , V_64 -> V_71 ) ;
}
V_67 = V_65 | V_66 ;
if ( ! ( V_67 & V_72 ) )
V_67 |= V_72 ;
if ( ! ( V_67 & ( V_73 | V_74 ) ) )
V_67 |= V_73 | V_74 ;
V_67 |= F_25 ( V_75 , V_76 , V_54 ) ;
F_28 ( V_2 , V_77 , L_4
L_5 ,
V_52 , V_67 , V_52 & V_67 , V_65 ,
V_62 , V_66 , V_61 ) ;
return V_52 & V_67 ;
}
static int F_29 ( struct V_35 * V_36 , unsigned long V_37 )
{
static const struct V_38 V_78 [] = {
{ 0x50 , 1 , 0x02 , 0x02 } ,
{ 0x50 , 1 , 0x01 , 0x01 }
} ;
struct V_1 * V_2 = V_36 -> V_2 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_11 ) ;
if ( ! F_11 ( V_9 , & V_78 [ V_2 -> V_14 ] ) )
return - V_40 ;
return F_12 ( V_36 , V_37 ) ;
}
static void F_30 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , 0x50 , V_4 -> V_26 , 3 ) ;
}
static void F_31 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , 0x50 , V_4 -> V_26 , 4 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , 0x50 , V_4 -> V_24 , 3 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , 0x50 , V_4 -> V_24 , 4 ) ;
}
static void F_34 ( struct V_79 * V_10 )
{
T_2 V_28 = ( unsigned long ) V_10 -> V_68 ;
F_35 ( F_2 ( V_10 -> V_11 ) , 0x60 , V_28 ) ;
}
static void F_36 ( struct V_8 * V_9 )
{
T_1 V_46 ;
F_7 ( V_9 , 0x41 , & V_46 ) ;
V_46 &= 0x0F ;
F_9 ( V_9 , 0x41 , V_46 ) ;
}
static int F_37 ( struct V_8 * V_9 , const struct V_80 * V_81 )
{
static const struct V_82 V_83 [ 10 ] = {
{
. V_71 = V_84 ,
. V_85 = V_75 ,
. V_86 = V_76 ,
. V_87 = V_54 ,
. V_88 = & V_89
} ,
{
. V_71 = V_84 ,
. V_85 = V_75 ,
. V_86 = V_76 ,
. V_87 = V_58 ,
. V_88 = & V_90
} ,
{
. V_71 = V_84 ,
. V_85 = V_75 ,
. V_86 = V_76 ,
. V_87 = V_58 ,
. V_88 = & V_90
} ,
{
. V_71 = V_84 ,
. V_85 = V_75 ,
. V_86 = V_76 ,
. V_87 = V_59 ,
. V_88 = & V_91
} ,
{
. V_71 = V_84 ,
. V_85 = V_75 ,
. V_86 = V_76 ,
. V_87 = V_59 ,
. V_88 = & V_91
} ,
{
. V_71 = V_84 ,
. V_85 = V_75 ,
. V_86 = V_76 ,
. V_87 = V_60 ,
. V_88 = & V_92
} ,
{
. V_71 = V_84 ,
. V_85 = V_75 ,
. V_86 = V_76 ,
. V_87 = V_59 ,
. V_88 = & V_92
} ,
{
. V_71 = V_84 ,
. V_85 = V_75 ,
. V_86 = V_76 ,
. V_87 = V_59 ,
. V_88 = & V_93
} ,
{
. V_71 = V_84 ,
. V_85 = V_75 ,
. V_86 = V_76 ,
. V_87 = V_60 ,
. V_88 = & V_94
} ,
{
. V_71 = V_84 ,
. V_85 = V_75 ,
. V_86 = V_76 ,
. V_87 = V_59 ,
. V_88 = & V_91
}
} ;
const struct V_82 * V_95 [] = { NULL , NULL } ;
static int V_96 ;
int type = V_81 -> V_97 ;
void * V_98 = NULL ;
T_1 V_46 ;
int V_99 ;
if ( ! V_96 ++ )
F_5 ( V_77 , & V_9 -> V_11 , L_6 V_100 L_7 ) ;
V_99 = F_38 ( V_9 ) ;
if ( V_99 )
return V_99 ;
F_7 ( V_9 , 0x41 , & V_46 ) ;
if ( type == 1 && V_9 -> V_101 > 0x7 )
type = 2 ;
if ( type == 5 && V_9 -> V_102 == V_103 &&
V_9 -> V_104 == V_105 )
type = 6 ;
V_95 [ 0 ] = & V_83 [ type ] ;
if ( type < 3 )
F_39 ( V_9 ) ;
if ( V_9 -> V_106 == V_103 )
F_36 ( V_9 ) ;
if ( type == 7 || type == 8 ) {
T_2 V_28 ;
F_40 ( V_9 , 0x60 , & V_28 ) ;
V_98 = ( void * ) ( unsigned long ) V_28 ;
}
return F_41 ( V_9 , V_95 , & V_107 , V_98 , 0 ) ;
}
static int F_42 ( struct V_8 * V_9 )
{
struct V_79 * V_10 = F_43 ( & V_9 -> V_11 ) ;
int V_99 ;
V_99 = F_44 ( V_9 ) ;
if ( V_99 )
return V_99 ;
if ( V_9 -> V_106 == V_103 ) {
F_36 ( V_9 ) ;
if ( V_9 -> V_50 == V_108 ||
V_9 -> V_50 == V_109 )
F_39 ( V_9 ) ;
}
F_45 ( V_10 ) ;
return 0 ;
}
static int T_3 F_46 ( void )
{
return F_47 ( & V_110 ) ;
}
static void T_4 F_48 ( void )
{
F_49 ( & V_110 ) ;
}
