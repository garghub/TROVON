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
T_1 V_15 = F_5 ( V_12 , V_16 ) & 0xfffc ;
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
T_1 V_15 = 0 ;
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
F_7 ( V_12 , V_54 , V_53 | 0x0040 ) ;
break;
case V_58 :
F_7 ( V_12 , V_26 , 0x0 ) ;
F_7 ( V_12 , V_54 , 0xffff ) ;
break;
}
V_12 -> V_59 . V_60 = V_52 ;
return 0 ;
}
static int F_16 ( struct V_11 * V_12 , T_2 V_61 )
{
F_7 ( V_12 , V_26 , 0x0 ) ;
F_15 ( V_12 , V_58 ) ;
return 0 ;
}
static int F_17 ( struct V_11 * V_12 )
{
int V_3 ;
T_3 V_62 [ 2 ] ;
T_1 * V_63 = V_12 -> V_64 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_65 ) ; V_3 ++ ) {
V_62 [ 0 ] = ( V_3 << 1 ) | ( ( V_63 [ V_3 ] >> 8 ) & 0x0001 ) ;
V_62 [ 1 ] = V_63 [ V_3 ] & 0x00ff ;
V_12 -> V_66 ( V_12 -> V_67 , V_62 , 2 ) ;
}
F_15 ( V_12 , V_57 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
int V_68 , V_53 ;
V_68 = F_19 ( V_12 , 7 , 9 , V_14 -> V_69 ) ;
if ( V_68 < 0 ) {
F_20 ( V_12 -> V_70 , L_1 , V_68 ) ;
return V_68 ;
}
V_68 = F_21 ( V_12 ) ;
if ( V_68 < 0 ) {
F_20 ( V_12 -> V_70 , L_2 ) ;
return V_68 ;
}
F_15 ( V_12 , V_57 ) ;
V_53 = F_5 ( V_12 , V_71 ) ;
F_7 ( V_12 , V_71 , V_53 | 0x0100 ) ;
V_53 = F_5 ( V_12 , V_72 ) ;
F_7 ( V_12 , V_72 , V_53 | 0x0100 ) ;
F_22 ( V_12 , V_73 ,
F_2 ( V_73 ) ) ;
return V_68 ;
}
static int F_23 ( struct V_11 * V_12 )
{
F_15 ( V_12 , V_58 ) ;
return 0 ;
}
static int T_4 F_24 ( struct V_74 * V_75 )
{
struct V_13 * V_14 ;
int V_68 ;
V_14 = F_25 ( sizeof( struct V_13 ) , V_76 ) ;
if ( V_14 == NULL )
return - V_77 ;
F_26 ( V_75 , V_14 ) ;
V_14 -> V_69 = V_78 ;
V_68 = F_27 ( & V_75 -> V_70 ,
& V_79 , & V_80 , 1 ) ;
if ( V_68 < 0 )
F_28 ( V_14 ) ;
return V_68 ;
}
static int T_5 F_29 ( struct V_74 * V_75 )
{
F_30 ( & V_75 -> V_70 ) ;
F_28 ( F_31 ( V_75 ) ) ;
return 0 ;
}
static T_4 int F_32 ( struct V_81 * V_82 ,
const struct V_83 * V_84 )
{
struct V_13 * V_14 ;
int V_68 ;
V_14 = F_25 ( sizeof( struct V_13 ) , V_76 ) ;
if ( V_14 == NULL )
return - V_77 ;
F_33 ( V_82 , V_14 ) ;
V_14 -> V_69 = V_85 ;
V_68 = F_27 ( & V_82 -> V_70 ,
& V_79 , & V_80 , 1 ) ;
if ( V_68 < 0 )
F_28 ( V_14 ) ;
return V_68 ;
}
static T_5 int F_34 ( struct V_81 * V_82 )
{
F_30 ( & V_82 -> V_70 ) ;
F_28 ( F_35 ( V_82 ) ) ;
return 0 ;
}
static int T_6 F_36 ( void )
{
int V_68 ;
#if F_37 ( V_86 ) || F_37 ( V_87 )
V_68 = F_38 ( & V_88 ) ;
if ( V_68 != 0 ) {
F_39 ( V_89 L_3 ,
V_68 ) ;
}
#endif
#if F_37 ( V_90 )
V_68 = F_40 ( & V_91 ) ;
if ( V_68 != 0 ) {
F_39 ( V_89 L_4 ,
V_68 ) ;
}
#endif
return 0 ;
}
static void T_7 F_41 ( void )
{
#if F_37 ( V_86 ) || F_37 ( V_87 )
F_42 ( & V_88 ) ;
#endif
#if F_37 ( V_90 )
F_43 ( & V_91 ) ;
#endif
}
