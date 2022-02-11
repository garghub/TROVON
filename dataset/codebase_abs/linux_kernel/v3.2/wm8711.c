static inline int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 && V_4 [ V_3 ] . V_1 == V_1 )
return V_3 ;
}
return 0 ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
T_1 V_15 = F_5 ( V_12 , V_16 ) & 0xfff3 ;
int V_3 = F_1 ( V_14 -> V_17 , F_6 ( V_8 ) ) ;
T_1 V_18 = ( V_4 [ V_3 ] . V_19 << 2 ) |
( V_4 [ V_3 ] . V_20 << 1 ) | V_4 [ V_3 ] . V_21 ;
F_7 ( V_12 , V_22 , V_18 ) ;
switch ( F_8 ( V_8 ) ) {
case V_23 :
break;
case V_24 :
V_15 |= 0x0004 ;
break;
case V_25 :
V_15 |= 0x0008 ;
break;
}
F_7 ( V_12 , V_16 , V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
F_7 ( V_12 , V_26 , 0x0001 ) ;
return 0 ;
}
static void F_10 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
if ( ! V_12 -> V_27 ) {
F_11 ( 50 ) ;
F_7 ( V_12 , V_26 , 0x0 ) ;
}
}
static int F_12 ( struct V_9 * V_10 , int V_28 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
T_1 V_29 = F_5 ( V_12 , V_30 ) & 0xfff7 ;
if ( V_28 )
F_7 ( V_12 , V_30 , V_29 | 0x8 ) ;
else
F_7 ( V_12 , V_30 , V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_31 ,
int V_32 , unsigned int V_33 , int V_34 )
{
struct V_11 * V_12 = V_31 -> V_12 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
switch ( V_33 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_14 -> V_17 = V_33 ;
return 0 ;
}
return - V_35 ;
}
static int F_14 ( struct V_9 * V_31 ,
unsigned int V_36 )
{
struct V_11 * V_12 = V_31 -> V_12 ;
T_1 V_15 = F_5 ( V_12 , V_16 ) & 0x000c ;
switch ( V_36 & V_37 ) {
case V_38 :
V_15 |= 0x0040 ;
break;
case V_39 :
break;
default:
return - V_35 ;
}
switch ( V_36 & V_40 ) {
case V_41 :
V_15 |= 0x0002 ;
break;
case V_42 :
break;
case V_43 :
V_15 |= 0x0001 ;
break;
case V_44 :
V_15 |= 0x0003 ;
break;
case V_45 :
V_15 |= 0x0013 ;
break;
default:
return - V_35 ;
}
switch ( V_36 & V_46 ) {
case V_47 :
break;
case V_48 :
V_15 |= 0x0090 ;
break;
case V_49 :
V_15 |= 0x0080 ;
break;
case V_50 :
V_15 |= 0x0010 ;
break;
default:
return - V_35 ;
}
F_7 ( V_12 , V_16 , V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 ,
enum V_51 V_52 )
{
T_1 V_53 = F_5 ( V_12 , V_54 ) & 0xff7f ;
switch ( V_52 ) {
case V_55 :
F_7 ( V_12 , V_54 , V_53 ) ;
break;
case V_56 :
break;
case V_57 :
if ( V_12 -> V_58 . V_59 == V_60 )
F_16 ( V_12 ) ;
F_7 ( V_12 , V_54 , V_53 | 0x0040 ) ;
break;
case V_60 :
F_7 ( V_12 , V_26 , 0x0 ) ;
F_7 ( V_12 , V_54 , 0xffff ) ;
break;
}
V_12 -> V_58 . V_59 = V_52 ;
return 0 ;
}
static int F_17 ( struct V_11 * V_12 , T_2 V_61 )
{
F_7 ( V_12 , V_26 , 0x0 ) ;
F_15 ( V_12 , V_60 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 )
{
F_15 ( V_12 , V_57 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
int V_62 ;
V_62 = F_20 ( V_12 , 7 , 9 , V_14 -> V_63 ) ;
if ( V_62 < 0 ) {
F_21 ( V_12 -> V_64 , L_1 , V_62 ) ;
return V_62 ;
}
V_62 = F_22 ( V_12 ) ;
if ( V_62 < 0 ) {
F_21 ( V_12 -> V_64 , L_2 ) ;
return V_62 ;
}
F_15 ( V_12 , V_57 ) ;
F_23 ( V_12 , V_65 , 0x0100 , 0x0100 ) ;
F_23 ( V_12 , V_66 , 0x0100 , 0x0100 ) ;
F_24 ( V_12 , V_67 ,
F_2 ( V_67 ) ) ;
return V_62 ;
}
static int F_25 ( struct V_11 * V_12 )
{
F_15 ( V_12 , V_60 ) ;
return 0 ;
}
static int T_3 F_26 ( struct V_68 * V_69 )
{
struct V_13 * V_14 ;
int V_62 ;
V_14 = F_27 ( sizeof( struct V_13 ) , V_70 ) ;
if ( V_14 == NULL )
return - V_71 ;
F_28 ( V_69 , V_14 ) ;
V_14 -> V_63 = V_72 ;
V_62 = F_29 ( & V_69 -> V_64 ,
& V_73 , & V_74 , 1 ) ;
if ( V_62 < 0 )
F_30 ( V_14 ) ;
return V_62 ;
}
static int T_4 F_31 ( struct V_68 * V_69 )
{
F_32 ( & V_69 -> V_64 ) ;
F_30 ( F_33 ( V_69 ) ) ;
return 0 ;
}
static T_3 int F_34 ( struct V_75 * V_76 ,
const struct V_77 * V_78 )
{
struct V_13 * V_14 ;
int V_62 ;
V_14 = F_27 ( sizeof( struct V_13 ) , V_70 ) ;
if ( V_14 == NULL )
return - V_71 ;
F_35 ( V_76 , V_14 ) ;
V_14 -> V_63 = V_79 ;
V_62 = F_29 ( & V_76 -> V_64 ,
& V_73 , & V_74 , 1 ) ;
if ( V_62 < 0 )
F_30 ( V_14 ) ;
return V_62 ;
}
static T_4 int F_36 ( struct V_75 * V_76 )
{
F_32 ( & V_76 -> V_64 ) ;
F_30 ( F_37 ( V_76 ) ) ;
return 0 ;
}
static int T_5 F_38 ( void )
{
int V_62 ;
#if F_39 ( V_80 ) || F_39 ( V_81 )
V_62 = F_40 ( & V_82 ) ;
if ( V_62 != 0 ) {
F_41 ( V_83 L_3 ,
V_62 ) ;
}
#endif
#if F_39 ( V_84 )
V_62 = F_42 ( & V_85 ) ;
if ( V_62 != 0 ) {
F_41 ( V_83 L_4 ,
V_62 ) ;
}
#endif
return 0 ;
}
static void T_6 F_43 ( void )
{
#if F_39 ( V_80 ) || F_39 ( V_81 )
F_44 ( & V_82 ) ;
#endif
#if F_39 ( V_84 )
F_45 ( & V_85 ) ;
#endif
}
