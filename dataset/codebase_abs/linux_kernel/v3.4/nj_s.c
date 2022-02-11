static T_1 F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
return ( 5 ) ;
}
static void F_2 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_5 )
{
}
static T_2
F_3 ( int V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
T_1 V_8 , V_9 , V_10 ;
T_3 V_11 ;
F_4 ( & V_2 -> V_12 , V_11 ) ;
V_9 = F_5 ( V_2 -> V_13 . V_14 . V_15 + V_16 ) ;
if ( ! ( V_9 & V_17 ) ) {
V_8 = F_6 ( V_2 , V_18 ) ;
if ( V_2 -> V_19 & V_20 )
F_7 ( V_2 , L_1 , V_9 , V_8 ) ;
if ( V_8 ) {
F_8 ( V_2 , V_8 ) ;
F_9 ( V_2 , V_21 , 0xFF ) ;
F_9 ( V_2 , V_21 , 0x0 ) ;
}
V_9 = 1 ;
} else
V_9 = 0 ;
V_10 = F_5 ( V_2 -> V_13 . V_14 . V_15 + V_22 ) ;
if ( ( V_10 | V_9 ) == 0 ) {
F_10 ( & V_2 -> V_12 , V_11 ) ;
return V_23 ;
}
if ( V_10 )
F_11 ( V_2 -> V_13 . V_14 . V_15 + V_22 , V_10 ) ;
if ( F_12 ( V_2 -> V_13 . V_14 . V_15 + V_24 ) <
F_12 ( V_2 -> V_13 . V_14 . V_15 + V_25 ) )
V_10 = 0x08 ;
else
V_10 = 0x04 ;
if ( F_12 ( V_2 -> V_13 . V_14 . V_15 + V_26 ) <
F_12 ( V_2 -> V_13 . V_14 . V_15 + V_27 ) )
V_10 |= 0x02 ;
else
V_10 |= 0x01 ;
if ( V_10 != V_2 -> V_13 . V_14 . V_28 )
{
if ( F_13 ( V_29 , & V_2 -> V_30 ) ) {
F_14 ( V_31 L_2 ,
V_2 -> V_13 . V_14 . V_28 , V_10 ) ;
F_10 ( & V_2 -> V_12 , V_11 ) ;
return V_32 ;
}
V_2 -> V_13 . V_14 . V_33 = V_10 ;
if ( ( V_2 -> V_13 . V_14 . V_33 & V_34 ) !=
( V_2 -> V_13 . V_14 . V_28 & V_34 ) )
F_15 ( V_2 ) ;
if ( ( V_2 -> V_13 . V_14 . V_33 & V_35 ) !=
( V_2 -> V_13 . V_14 . V_28 & V_35 ) )
F_16 ( V_2 ) ;
F_17 ( V_29 , & V_2 -> V_30 ) ;
}
F_10 ( & V_2 -> V_12 , V_11 ) ;
return V_32 ;
}
static void
F_18 ( struct V_1 * V_2 )
{
V_2 -> V_13 . V_14 . V_36 = 0xff ;
F_11 ( V_2 -> V_13 . V_14 . V_15 + V_37 , V_2 -> V_13 . V_14 . V_36 ) ;
F_19 ( 10 ) ;
if ( V_2 -> V_38 )
V_2 -> V_13 . V_14 . V_36 = 0x40 ;
else
V_2 -> V_13 . V_14 . V_36 = 0x00 ;
F_11 ( V_2 -> V_13 . V_14 . V_15 + V_37 , V_2 -> V_13 . V_14 . V_36 ) ;
F_19 ( 10 ) ;
V_2 -> V_13 . V_14 . V_39 = 0 ;
V_2 -> V_13 . V_14 . V_40 = 0 ;
F_11 ( V_2 -> V_13 . V_14 . V_15 + V_41 , ~ V_17 ) ;
F_11 ( V_2 -> V_13 . V_14 . V_15 + V_42 , V_17 ) ;
F_11 ( V_2 -> V_13 . V_14 . V_43 , V_2 -> V_13 . V_14 . V_39 ) ;
}
static int
F_20 ( struct V_1 * V_2 , int V_44 , void * V_45 )
{
T_3 V_11 ;
switch ( V_44 ) {
case V_46 :
F_4 ( & V_2 -> V_12 , V_11 ) ;
F_18 ( V_2 ) ;
F_10 ( & V_2 -> V_12 , V_11 ) ;
return ( 0 ) ;
case V_47 :
F_21 ( V_2 ) ;
return ( 0 ) ;
case V_48 :
F_18 ( V_2 ) ;
F_22 ( V_2 ) ;
F_4 ( & V_2 -> V_12 , V_11 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
V_2 -> V_49 ( V_2 , V_21 , 0 ) ;
F_10 ( & V_2 -> V_12 , V_11 ) ;
return ( 0 ) ;
case V_50 :
return ( 0 ) ;
}
return ( 0 ) ;
}
static int T_4 F_25 ( struct V_51 * V_52 ,
struct V_1 * V_2 )
{
T_5 V_53 ;
if ( F_26 ( V_52 ) )
return ( 0 ) ;
F_27 ( V_52 ) ;
V_2 -> V_54 = V_52 -> V_54 ;
if ( ! V_2 -> V_54 ) {
F_14 ( V_31 L_3 ) ;
return ( 0 ) ;
}
V_2 -> V_13 . V_14 . V_15 = F_28 ( V_52 , 0 ) ;
if ( ! V_2 -> V_13 . V_14 . V_15 ) {
F_14 ( V_31 L_4 ) ;
return ( 0 ) ;
}
F_29 ( V_52 , 0x04 , & V_53 ) ;
if ( V_53 & 0x00100000 )
V_2 -> V_38 = 1 ;
else
V_2 -> V_38 = 0 ;
if ( ( V_52 -> V_55 == 0x55 ) &&
( V_52 -> V_56 == 0x02 ) ) {
F_14 ( V_31 L_5 ) ;
F_14 ( V_31 L_6 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int T_4 F_30 ( struct V_57 * V_58 ,
struct V_1 * V_2 )
{
V_2 -> V_13 . V_14 . V_43 = V_2 -> V_13 . V_14 . V_15 + V_59 ;
V_2 -> V_13 . V_14 . V_60 = V_2 -> V_13 . V_14 . V_15 | V_61 ;
V_2 -> V_13 . V_14 . V_36 = 0xff ;
F_11 ( V_2 -> V_13 . V_14 . V_15 + V_37 , V_2 -> V_13 . V_14 . V_36 ) ;
F_19 ( 10 ) ;
V_2 -> V_13 . V_14 . V_36 = 0x00 ;
F_11 ( V_2 -> V_13 . V_14 . V_15 + V_37 , V_2 -> V_13 . V_14 . V_36 ) ;
F_19 ( 10 ) ;
V_2 -> V_13 . V_14 . V_39 = 0xC0 ;
V_2 -> V_13 . V_14 . V_40 = 0 ;
F_11 ( V_2 -> V_13 . V_14 . V_15 + V_41 , ~ V_17 ) ;
F_11 ( V_2 -> V_13 . V_14 . V_15 + V_42 , V_17 ) ;
F_11 ( V_2 -> V_13 . V_14 . V_43 , V_2 -> V_13 . V_14 . V_39 ) ;
switch ( ( ( F_6 ( V_2 , V_62 ) >> 5 ) & 3 ) )
{
case 0 :
return 1 ;
case 3 :
F_14 ( V_31 L_7 ) ;
return - 1 ;
default:
F_14 ( V_31 L_8 ) ;
return 0 ;
}
return 1 ;
}
static int T_4 F_31 ( struct V_57 * V_58 ,
struct V_1 * V_2 )
{
const int V_63 = 256 ;
F_14 ( V_64
L_9 ,
V_2 -> V_38 ? L_10 : L_11 , V_2 -> V_13 . V_14 . V_15 , V_2 -> V_54 ) ;
if ( ! F_32 ( V_2 -> V_13 . V_14 . V_15 , V_63 , L_12 ) ) {
F_14 ( V_31
L_13 ,
V_2 -> V_13 . V_14 . V_15 ,
V_2 -> V_13 . V_14 . V_15 + V_63 ) ;
return ( 0 ) ;
}
V_2 -> V_65 = & F_6 ;
V_2 -> V_49 = & F_9 ;
V_2 -> V_66 = & V_67 ;
V_2 -> V_68 = & V_69 ;
V_2 -> V_70 = & F_1 ;
V_2 -> V_71 = & F_2 ;
V_2 -> V_72 = & V_73 ;
F_33 ( V_2 ) ;
V_2 -> V_74 = & F_20 ;
V_2 -> V_75 = & F_3 ;
V_2 -> V_76 |= V_77 ;
F_34 ( V_2 , L_14 ) ;
return ( 1 ) ;
}
int T_4
F_35 ( struct V_57 * V_58 )
{
int V_78 ;
struct V_1 * V_2 = V_58 -> V_2 ;
char V_79 [ 64 ] ;
#ifdef F_36
#error "not running on big endian machines now"
#endif
strcpy ( V_79 , V_80 ) ;
F_14 ( V_64 L_15 , F_37 ( V_79 ) ) ;
if ( V_2 -> V_81 != V_82 )
return ( 0 ) ;
F_17 ( V_29 , & V_2 -> V_30 ) ;
for (; ; )
{
if ( ( V_52 = F_38 ( V_83 ,
V_84 , V_52 ) ) ) {
V_78 = F_25 ( V_52 , V_2 ) ;
if ( ! V_78 )
return ( 0 ) ;
} else {
F_14 ( V_31 L_8 ) ;
return ( 0 ) ;
}
V_78 = F_30 ( V_58 , V_2 ) ;
if ( ! V_78 )
return ( 0 ) ;
if ( V_78 > 0 )
break;
}
return F_31 ( V_58 , V_2 ) ;
}
