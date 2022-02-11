static unsigned char
F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
if( V_3 < 8 )
return ( F_2 ( V_2 -> V_4 . V_5 . V_6 + 4 * V_3 ) ) ;
else {
F_3 ( V_3 , V_2 -> V_4 . V_5 . V_6 + 4 * V_7 ) ;
return ( F_2 ( V_2 -> V_4 . V_5 . V_6 + 4 * V_8 ) ) ;
}
}
static void
F_4 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_9 )
{
if( V_3 < 8 )
F_3 ( V_9 , V_2 -> V_4 . V_5 . V_6 + 4 * V_3 ) ;
else {
F_3 ( V_3 , V_2 -> V_4 . V_5 . V_6 + 4 * V_7 ) ;
F_3 ( V_9 , V_2 -> V_4 . V_5 . V_6 + 4 * V_8 ) ;
}
}
static void
F_5 ( struct V_1 * V_2 , unsigned char V_10 ) {
if ( ! V_10 )
F_3 ( 0x00 , V_2 -> V_4 . V_5 . V_11 + V_12 ) ;
else
F_3 ( V_13 , V_2 -> V_4 . V_5 . V_11 + V_12 ) ;
}
static unsigned char F_6 ( struct V_1 * V_2 , int V_14 , unsigned char V_15 )
{
return ( 5 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_14 , unsigned char V_15 , unsigned char V_9 )
{
}
static void
F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 & V_17 )
F_9 ( V_2 , L_1 ) ;
V_2 -> V_4 . V_5 . V_18 = 0x07 ;
F_3 ( V_2 -> V_4 . V_5 . V_18 , V_2 -> V_4 . V_5 . V_11 + V_19 ) ;
F_10 ( 20 ) ;
V_2 -> V_4 . V_5 . V_18 = 0x30 ;
F_3 ( V_2 -> V_4 . V_5 . V_18 , V_2 -> V_4 . V_5 . V_11 + V_19 ) ;
F_10 ( 20 ) ;
V_2 -> V_4 . V_5 . V_20 = 0 ;
V_2 -> V_4 . V_5 . V_21 = 0 ;
F_3 ( ~ V_13 , V_2 -> V_4 . V_5 . V_11 + V_22 ) ;
F_3 ( V_13 , V_2 -> V_4 . V_5 . V_11 + V_12 ) ;
F_3 ( V_2 -> V_4 . V_5 . V_20 , V_2 -> V_4 . V_5 . V_23 ) ;
}
static int
F_11 ( struct V_1 * V_2 , int V_24 , void * V_25 )
{
T_1 V_26 ;
unsigned char * V_14 ;
if ( V_2 -> V_16 & V_17 )
F_9 ( V_2 , L_2 , V_24 ) ;
switch ( V_24 ) {
case V_27 :
F_12 ( & V_2 -> V_28 , V_26 ) ;
F_8 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_28 , V_26 ) ;
break;
case V_29 :
F_15 ( V_2 ) ;
break;
case V_30 :
F_8 ( V_2 ) ;
F_16 ( V_2 ) ;
F_13 ( V_2 ) ;
break;
case V_31 :
break;
case V_32 :
V_2 -> V_4 . V_5 . V_20 = V_13 << 1 ;
F_3 ( V_2 -> V_4 . V_5 . V_20 , V_2 -> V_4 . V_5 . V_11 + V_33 ) ;
break;
case V_34 :
V_2 -> V_4 . V_5 . V_20 = 0 ;
F_3 ( 0x00 , V_2 -> V_4 . V_5 . V_11 + V_33 ) ;
break;
case V_35 :
V_14 = ( unsigned char * ) V_25 ;
if ( V_2 -> V_16 & V_17 )
F_9 ( V_2 , L_3 , * V_14 ) ;
V_2 -> V_36 . V_37 . V_38 ( V_2 , ( V_2 -> V_36 . V_37 . V_39 | ( * V_14 + 1 ) ) , L_4 ) ;
V_2 -> V_4 . V_5 . V_20 |= V_13 << 2 ;
F_3 ( V_2 -> V_4 . V_5 . V_20 , V_2 -> V_4 . V_5 . V_11 + V_33 ) ;
break;
case V_40 :
V_14 = ( unsigned char * ) V_25 ;
if ( V_2 -> V_16 & V_17 )
F_9 ( V_2 , L_5 , * V_14 ) ;
V_2 -> V_36 . V_37 . V_38 ( V_2 , ( V_2 -> V_36 . V_37 . V_39 & ~ ( * V_14 + 1 ) ) , L_6 ) ;
if ( ! ( V_2 -> V_36 . V_37 . V_39 & 3 ) ) {
V_2 -> V_4 . V_5 . V_20 &= ~ ( V_13 << 2 ) ;
F_3 ( V_2 -> V_4 . V_5 . V_20 , V_2 -> V_4 . V_5 . V_11 + V_33 ) ;
}
break;
default:
break;
}
return ( 0 ) ;
}
static T_2
F_17 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
unsigned char V_43 , V_44 , V_45 ;
T_1 V_26 ;
F_12 ( & V_2 -> V_28 , V_26 ) ;
V_44 = F_2 ( V_2 -> V_4 . V_5 . V_11 + V_46 ) ;
if ( ! ( V_44 & V_13 ) ) {
V_45 = F_1 ( V_2 , 0x00 ) ;
F_18 ( V_2 , V_45 ) ;
V_44 = 1 ;
} else
V_44 = 0 ;
V_43 = F_2 ( V_2 -> V_4 . V_5 . V_11 + V_47 ) ;
if ( ( V_43 | V_44 ) == 0 ) {
F_14 ( & V_2 -> V_28 , V_26 ) ;
return V_48 ;
}
if ( V_43 )
F_3 ( V_43 , V_2 -> V_4 . V_5 . V_11 + V_47 ) ;
if ( F_19 ( V_2 -> V_4 . V_5 . V_11 + V_49 ) <
F_19 ( V_2 -> V_4 . V_5 . V_11 + V_50 ) )
V_43 = 0x08 ;
else
V_43 = 0x04 ;
if ( F_19 ( V_2 -> V_4 . V_5 . V_11 + V_51 ) <
F_19 ( V_2 -> V_4 . V_5 . V_11 + V_52 ) )
V_43 = V_43 | 0x02 ;
else
V_43 = V_43 | 0x01 ;
if ( V_43 != V_2 -> V_4 . V_5 . V_53 )
{
if ( F_20 ( V_54 , & V_2 -> V_55 ) ) {
F_14 ( & V_2 -> V_28 , V_26 ) ;
return V_56 ;
}
V_2 -> V_4 . V_5 . V_57 = V_43 ;
if ( ( V_2 -> V_4 . V_5 . V_57 & V_58 ) !=
( V_2 -> V_4 . V_5 . V_53 & V_58 ) )
F_21 ( V_2 ) ;
if ( ( V_2 -> V_4 . V_5 . V_57 & V_59 ) !=
( V_2 -> V_4 . V_5 . V_53 & V_59 ) )
F_22 ( V_2 ) ;
F_23 ( V_54 , & V_2 -> V_55 ) ;
}
F_14 ( & V_2 -> V_28 , V_26 ) ;
return V_56 ;
}
static int T_3 F_24 ( struct V_60 * V_61 ,
struct V_1 * V_2 )
{
if ( F_25 ( V_61 ) )
return ( 0 ) ;
V_2 -> V_62 = V_61 -> V_62 ;
if ( ! V_2 -> V_62 ) {
F_26 ( V_63 L_7 ) ;
return ( 0 ) ;
}
V_2 -> V_4 . V_5 . V_11 = F_27 ( V_61 , 0 ) ;
if ( ! V_2 -> V_4 . V_5 . V_11 ) {
F_26 ( V_63 L_8 ) ;
return ( 0 ) ;
}
if ( ( V_61 -> V_64 != 0x55 ) ||
( V_61 -> V_65 != 0x02 ) ) {
F_26 ( V_63 L_9 ) ;
F_26 ( V_63 L_10 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static void T_3 F_28 ( struct V_66 * V_67 ,
struct V_1 * V_2 )
{
V_2 -> V_4 . V_5 . V_23 = V_2 -> V_4 . V_5 . V_11 + V_33 ;
V_2 -> V_4 . V_5 . V_6 = V_2 -> V_4 . V_5 . V_11 + 0xC0 ;
V_2 -> V_4 . V_5 . V_18 = 0x07 ;
F_3 ( V_2 -> V_4 . V_5 . V_18 , V_2 -> V_4 . V_5 . V_11 + V_19 ) ;
F_10 ( 20 ) ;
V_2 -> V_4 . V_5 . V_18 = 0x30 ;
F_3 ( V_2 -> V_4 . V_5 . V_18 , V_2 -> V_4 . V_5 . V_11 + V_19 ) ;
F_10 ( 10 ) ;
V_2 -> V_4 . V_5 . V_20 = 0x00 ;
V_2 -> V_4 . V_5 . V_21 = 0 ;
F_3 ( ~ V_13 , V_2 -> V_4 . V_5 . V_11 + V_22 ) ;
F_3 ( V_13 , V_2 -> V_4 . V_5 . V_11 + V_12 ) ;
F_3 ( V_2 -> V_4 . V_5 . V_20 , V_2 -> V_4 . V_5 . V_23 ) ;
}
static int T_3 F_29 ( struct V_66 * V_67 ,
struct V_1 * V_2 )
{
const int V_68 = 256 ;
F_26 ( V_69
L_11 ,
V_2 -> V_4 . V_5 . V_11 , V_2 -> V_62 ) ;
if ( ! F_30 ( V_2 -> V_4 . V_5 . V_11 , V_68 , L_12 ) ) {
F_26 ( V_63
L_13 ,
V_2 -> V_4 . V_5 . V_11 ,
V_2 -> V_4 . V_5 . V_11 + V_68 ) ;
return ( 0 ) ;
}
F_31 ( V_2 ) ;
V_2 -> V_4 . V_5 . V_53 = 0 ;
V_2 -> V_70 = & F_1 ;
V_2 -> V_71 = & F_4 ;
V_2 -> V_36 . V_37 . V_72 = & F_5 ;
V_2 -> V_73 = & F_6 ;
V_2 -> V_74 = & F_7 ;
V_2 -> V_75 = & V_76 ;
V_2 -> V_77 = & F_11 ;
V_2 -> V_78 = & F_17 ;
V_2 -> V_79 |= V_80 ;
return ( 1 ) ;
}
int T_3
F_32 ( struct V_66 * V_67 )
{
int V_81 ;
struct V_1 * V_2 = V_67 -> V_2 ;
char V_82 [ 64 ] ;
#ifdef F_33
#error "not running on big endian machines now"
#endif
strcpy ( V_82 , V_83 ) ;
F_26 ( V_69 L_14 , F_34 ( V_82 ) ) ;
if ( V_2 -> V_84 != V_85 )
return ( 0 ) ;
F_23 ( V_54 , & V_2 -> V_55 ) ;
for ( ; ; )
{
if ( ( V_61 = F_35 ( V_86 ,
V_87 , V_61 ) ) ) {
V_81 = F_24 ( V_61 , V_2 ) ;
if ( ! V_81 )
return ( 0 ) ;
} else {
F_26 ( V_63 L_15 ) ;
return ( 0 ) ;
}
F_28 ( V_67 , V_2 ) ;
break;
}
return F_29 ( V_67 , V_2 ) ;
}
