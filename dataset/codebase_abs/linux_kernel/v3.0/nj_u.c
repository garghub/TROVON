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
T_1 V_8 , V_9 ;
T_3 V_10 ;
F_4 ( & V_2 -> V_11 , V_10 ) ;
if ( ! ( ( V_9 = F_5 ( V_2 -> V_12 . V_13 . V_14 + V_15 ) ) &
V_16 ) ) {
V_8 = F_6 ( V_2 , V_17 ) ;
if ( V_2 -> V_18 & V_19 )
F_7 ( V_2 , L_1 , V_9 , V_8 ) ;
if ( V_8 ) {
F_8 ( V_2 , V_8 ) ;
F_9 ( V_2 , V_20 , 0xFF ) ;
F_9 ( V_2 , V_20 , 0x0 ) ;
}
}
if ( F_10 ( V_2 -> V_12 . V_13 . V_14 + V_21 ) <
F_10 ( V_2 -> V_12 . V_13 . V_14 + V_22 ) )
V_9 = 0x08 ;
else
V_9 = 0x04 ;
if ( F_10 ( V_2 -> V_12 . V_13 . V_14 + V_23 ) <
F_10 ( V_2 -> V_12 . V_13 . V_14 + V_24 ) )
V_9 = V_9 | 0x02 ;
else
V_9 = V_9 | 0x01 ;
if ( V_9 != V_2 -> V_12 . V_13 . V_25 )
{
if ( F_11 ( V_26 , & V_2 -> V_27 ) ) {
F_12 ( & V_2 -> V_11 , V_10 ) ;
return V_28 ;
}
V_2 -> V_12 . V_13 . V_29 = V_9 ;
if ( ( V_2 -> V_12 . V_13 . V_29 & V_30 ) !=
( V_2 -> V_12 . V_13 . V_25 & V_30 ) )
F_13 ( V_2 ) ;
if ( ( V_2 -> V_12 . V_13 . V_29 & V_31 ) !=
( V_2 -> V_12 . V_13 . V_25 & V_31 ) )
F_14 ( V_2 ) ;
F_15 ( V_26 , & V_2 -> V_27 ) ;
}
F_12 ( & V_2 -> V_11 , V_10 ) ;
return V_28 ;
}
static void
F_16 ( struct V_1 * V_2 )
{
V_2 -> V_12 . V_13 . V_32 = 0xff ;
F_17 ( V_2 -> V_12 . V_13 . V_14 + V_33 , V_2 -> V_12 . V_13 . V_32 ) ;
F_18 ( 10 ) ;
V_2 -> V_12 . V_13 . V_32 = 0x40 ;
F_17 ( V_2 -> V_12 . V_13 . V_14 + V_33 , V_2 -> V_12 . V_13 . V_32 ) ;
F_18 ( 10 ) ;
V_2 -> V_12 . V_13 . V_34 = 0xC0 ;
V_2 -> V_12 . V_13 . V_35 = 0 ;
F_17 ( V_2 -> V_12 . V_13 . V_36 , 0 ) ;
F_17 ( V_2 -> V_12 . V_13 . V_14 + V_37 , ~ V_16 ) ;
F_17 ( V_2 -> V_12 . V_13 . V_14 + V_38 , V_16 ) ;
F_17 ( V_2 -> V_12 . V_13 . V_36 , V_2 -> V_12 . V_13 . V_34 ) ;
}
static int
F_19 ( struct V_1 * V_2 , int V_39 , void * V_40 )
{
T_3 V_10 ;
switch ( V_39 ) {
case V_41 :
F_4 ( & V_2 -> V_11 , V_10 ) ;
F_16 ( V_2 ) ;
F_12 ( & V_2 -> V_11 , V_10 ) ;
return ( 0 ) ;
case V_42 :
F_20 ( V_2 ) ;
return ( 0 ) ;
case V_43 :
F_4 ( & V_2 -> V_11 , V_10 ) ;
F_21 ( V_2 ) ;
F_16 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
V_2 -> V_44 ( V_2 , V_20 , 0 ) ;
F_12 ( & V_2 -> V_11 , V_10 ) ;
return ( 0 ) ;
case V_45 :
return ( 0 ) ;
}
return ( 0 ) ;
}
static int T_4 F_24 ( struct V_46 * V_47 ,
struct V_1 * V_2 )
{
if ( F_25 ( V_47 ) )
return ( 0 ) ;
F_26 ( V_47 ) ;
V_2 -> V_48 = V_47 -> V_48 ;
if ( ! V_2 -> V_48 ) {
F_27 ( V_49 L_2 ) ;
return ( 0 ) ;
}
V_2 -> V_12 . V_13 . V_14 = F_28 ( V_47 , 0 ) ;
if ( ! V_2 -> V_12 . V_13 . V_14 ) {
F_27 ( V_49 L_3 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int T_4 F_29 ( struct V_50 * V_51 ,
struct V_1 * V_2 )
{
V_2 -> V_12 . V_13 . V_36 = V_2 -> V_12 . V_13 . V_14 + V_52 ;
V_2 -> V_12 . V_13 . V_53 = V_2 -> V_12 . V_13 . V_14 | V_54 ;
F_18 ( 10 ) ;
V_2 -> V_12 . V_13 . V_32 = 0xff ;
F_17 ( V_2 -> V_12 . V_13 . V_14 + V_33 , V_2 -> V_12 . V_13 . V_32 ) ;
F_18 ( 10 ) ;
V_2 -> V_12 . V_13 . V_32 = 0x00 ;
F_17 ( V_2 -> V_12 . V_13 . V_14 + V_33 , V_2 -> V_12 . V_13 . V_32 ) ;
F_18 ( 10 ) ;
V_2 -> V_12 . V_13 . V_34 = 0xC0 ;
V_2 -> V_12 . V_13 . V_35 = 0 ;
F_17 ( V_2 -> V_12 . V_13 . V_36 , 0 ) ;
F_17 ( V_2 -> V_12 . V_13 . V_14 + V_37 , ~ V_16 ) ;
F_17 ( V_2 -> V_12 . V_13 . V_14 + V_38 , V_16 ) ;
F_17 ( V_2 -> V_12 . V_13 . V_36 , V_2 -> V_12 . V_13 . V_34 ) ;
switch ( ( ( F_6 ( V_2 , V_55 ) >> 5 ) & 3 ) )
{
case 3 :
return 1 ;
case 0 :
F_27 ( V_49 L_4 ) ;
return - 1 ;
default :
F_27 ( V_49 L_5 ) ;
return 0 ;
}
return 1 ;
}
static int T_4 F_30 ( struct V_50 * V_51 ,
struct V_1 * V_2 )
{
const int V_56 = 256 ;
F_27 ( V_57
L_6 ,
V_2 -> V_12 . V_13 . V_14 , V_2 -> V_48 ) ;
if ( ! F_31 ( V_2 -> V_12 . V_13 . V_14 , V_56 , L_7 ) ) {
F_27 ( V_49
L_8
L_9 ,
V_2 -> V_12 . V_13 . V_14 ,
V_2 -> V_12 . V_13 . V_14 + V_56 ) ;
return ( 0 ) ;
}
F_32 ( V_2 ) ;
V_2 -> V_58 = & F_6 ;
V_2 -> V_44 = & F_9 ;
V_2 -> V_59 = & V_60 ;
V_2 -> V_61 = & V_62 ;
V_2 -> V_63 = & F_1 ;
V_2 -> V_64 = & F_2 ;
V_2 -> V_65 = & V_66 ;
V_2 -> V_67 = & F_19 ;
V_2 -> V_68 = & F_3 ;
V_2 -> V_69 |= V_70 ;
F_33 ( V_2 , L_10 ) ;
return ( 1 ) ;
}
int T_4
F_34 ( struct V_50 * V_51 )
{
int V_71 ;
struct V_1 * V_2 = V_51 -> V_2 ;
char V_72 [ 64 ] ;
#ifdef F_35
#error "not running on big endian machines now"
#endif
strcpy ( V_72 , V_73 ) ;
F_27 ( V_57 L_11 , F_36 ( V_72 ) ) ;
if ( V_2 -> V_74 != V_75 )
return ( 0 ) ;
F_15 ( V_26 , & V_2 -> V_27 ) ;
for ( ; ; )
{
if ( ( V_47 = F_37 ( V_76 ,
V_77 , V_47 ) ) ) {
V_71 = F_24 ( V_47 , V_2 ) ;
if ( ! V_71 )
return ( 0 ) ;
} else {
F_27 ( V_49 L_5 ) ;
return ( 0 ) ;
}
V_71 = F_29 ( V_51 , V_2 ) ;
if ( ! V_71 )
return ( 0 ) ;
if ( V_71 > 0 )
break;
}
return F_30 ( V_51 , V_2 ) ;
}
