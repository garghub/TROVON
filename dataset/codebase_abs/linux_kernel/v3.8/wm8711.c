static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return true ;
default:
return false ;
}
}
static inline int F_2 ( int V_5 , int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_3 ( V_8 ) ; V_7 ++ ) {
if ( V_8 [ V_7 ] . V_6 == V_6 && V_8 [ V_7 ] . V_5 == V_5 )
return V_7 ;
}
return 0 ;
}
static int F_4 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_17 * V_18 = F_5 ( V_16 ) ;
T_1 V_19 = F_6 ( V_16 , V_20 ) & 0xfff3 ;
int V_7 = F_2 ( V_18 -> V_21 , F_7 ( V_12 ) ) ;
T_1 V_22 = ( V_8 [ V_7 ] . V_23 << 2 ) |
( V_8 [ V_7 ] . V_24 << 1 ) | V_8 [ V_7 ] . V_25 ;
F_8 ( V_16 , V_26 , V_22 ) ;
switch ( F_9 ( V_12 ) ) {
case V_27 :
break;
case V_28 :
V_19 |= 0x0004 ;
break;
case V_29 :
V_19 |= 0x0008 ;
break;
}
F_8 ( V_16 , V_20 , V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
F_8 ( V_16 , V_30 , 0x0001 ) ;
return 0 ;
}
static void F_11 ( struct V_9 * V_10 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
if ( ! V_16 -> V_31 ) {
F_12 ( 50 ) ;
F_8 ( V_16 , V_30 , 0x0 ) ;
}
}
static int F_13 ( struct V_13 * V_14 , int V_32 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
T_1 V_33 = F_6 ( V_16 , V_34 ) & 0xfff7 ;
if ( V_32 )
F_8 ( V_16 , V_34 , V_33 | 0x8 ) ;
else
F_8 ( V_16 , V_34 , V_33 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_35 ,
int V_36 , unsigned int V_37 , int V_38 )
{
struct V_15 * V_16 = V_35 -> V_16 ;
struct V_17 * V_18 = F_5 ( V_16 ) ;
switch ( V_37 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_18 -> V_21 = V_37 ;
return 0 ;
}
return - V_39 ;
}
static int F_15 ( struct V_13 * V_35 ,
unsigned int V_40 )
{
struct V_15 * V_16 = V_35 -> V_16 ;
T_1 V_19 = F_6 ( V_16 , V_20 ) & 0x000c ;
switch ( V_40 & V_41 ) {
case V_42 :
V_19 |= 0x0040 ;
break;
case V_43 :
break;
default:
return - V_39 ;
}
switch ( V_40 & V_44 ) {
case V_45 :
V_19 |= 0x0002 ;
break;
case V_46 :
break;
case V_47 :
V_19 |= 0x0001 ;
break;
case V_48 :
V_19 |= 0x0003 ;
break;
case V_49 :
V_19 |= 0x0013 ;
break;
default:
return - V_39 ;
}
switch ( V_40 & V_50 ) {
case V_51 :
break;
case V_52 :
V_19 |= 0x0090 ;
break;
case V_53 :
V_19 |= 0x0080 ;
break;
case V_54 :
V_19 |= 0x0010 ;
break;
default:
return - V_39 ;
}
F_8 ( V_16 , V_20 , V_19 ) ;
return 0 ;
}
static int F_16 ( struct V_15 * V_16 ,
enum V_55 V_56 )
{
struct V_17 * V_18 = F_5 ( V_16 ) ;
T_1 V_3 = F_6 ( V_16 , V_57 ) & 0xff7f ;
switch ( V_56 ) {
case V_58 :
F_8 ( V_16 , V_57 , V_3 ) ;
break;
case V_59 :
break;
case V_60 :
if ( V_16 -> V_61 . V_62 == V_63 )
F_17 ( V_18 -> V_64 ) ;
F_8 ( V_16 , V_57 , V_3 | 0x0040 ) ;
break;
case V_63 :
F_8 ( V_16 , V_30 , 0x0 ) ;
F_8 ( V_16 , V_57 , 0xffff ) ;
break;
}
V_16 -> V_61 . V_62 = V_56 ;
return 0 ;
}
static int F_18 ( struct V_15 * V_16 )
{
F_8 ( V_16 , V_30 , 0x0 ) ;
F_16 ( V_16 , V_63 ) ;
return 0 ;
}
static int F_19 ( struct V_15 * V_16 )
{
F_16 ( V_16 , V_60 ) ;
return 0 ;
}
static int F_20 ( struct V_15 * V_16 )
{
int V_65 ;
V_65 = F_21 ( V_16 , 7 , 9 , V_66 ) ;
if ( V_65 < 0 ) {
F_22 ( V_16 -> V_2 , L_1 , V_65 ) ;
return V_65 ;
}
V_65 = F_23 ( V_16 ) ;
if ( V_65 < 0 ) {
F_22 ( V_16 -> V_2 , L_2 ) ;
return V_65 ;
}
F_16 ( V_16 , V_60 ) ;
F_24 ( V_16 , V_67 , 0x0100 , 0x0100 ) ;
F_24 ( V_16 , V_68 , 0x0100 , 0x0100 ) ;
return V_65 ;
}
static int F_25 ( struct V_15 * V_16 )
{
F_16 ( V_16 , V_63 ) ;
return 0 ;
}
static int F_26 ( struct V_69 * V_70 )
{
struct V_17 * V_18 ;
int V_65 ;
V_18 = F_27 ( & V_70 -> V_2 , sizeof( struct V_17 ) ,
V_71 ) ;
if ( V_18 == NULL )
return - V_72 ;
V_18 -> V_64 = F_28 ( V_70 , & V_73 ) ;
if ( F_29 ( V_18 -> V_64 ) )
return F_30 ( V_18 -> V_64 ) ;
F_31 ( V_70 , V_18 ) ;
V_65 = F_32 ( & V_70 -> V_2 ,
& V_74 , & V_75 , 1 ) ;
return V_65 ;
}
static int F_33 ( struct V_69 * V_70 )
{
F_34 ( & V_70 -> V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_76 * V_77 ,
const struct V_78 * V_79 )
{
struct V_17 * V_18 ;
int V_65 ;
V_18 = F_27 ( & V_77 -> V_2 , sizeof( struct V_17 ) ,
V_71 ) ;
if ( V_18 == NULL )
return - V_72 ;
V_18 -> V_64 = F_36 ( V_77 , & V_73 ) ;
if ( F_29 ( V_18 -> V_64 ) )
return F_30 ( V_18 -> V_64 ) ;
F_37 ( V_77 , V_18 ) ;
V_65 = F_32 ( & V_77 -> V_2 ,
& V_74 , & V_75 , 1 ) ;
return V_65 ;
}
static int F_38 ( struct V_76 * V_77 )
{
F_34 ( & V_77 -> V_2 ) ;
return 0 ;
}
static int T_2 F_39 ( void )
{
int V_65 ;
#if F_40 ( V_80 ) || F_40 ( V_81 )
V_65 = F_41 ( & V_82 ) ;
if ( V_65 != 0 ) {
F_42 ( V_83 L_3 ,
V_65 ) ;
}
#endif
#if F_40 ( V_84 )
V_65 = F_43 ( & V_85 ) ;
if ( V_65 != 0 ) {
F_42 ( V_83 L_4 ,
V_65 ) ;
}
#endif
return 0 ;
}
static void T_3 F_44 ( void )
{
#if F_40 ( V_80 ) || F_40 ( V_81 )
F_45 ( & V_82 ) ;
#endif
#if F_40 ( V_84 )
F_46 ( & V_85 ) ;
#endif
}
