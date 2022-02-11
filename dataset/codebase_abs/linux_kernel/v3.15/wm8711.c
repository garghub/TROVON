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
if ( ! F_12 ( V_16 ) ) {
F_13 ( 50 ) ;
F_8 ( V_16 , V_30 , 0x0 ) ;
}
}
static int F_14 ( struct V_13 * V_14 , int V_31 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
T_1 V_32 = F_6 ( V_16 , V_33 ) & 0xfff7 ;
if ( V_31 )
F_8 ( V_16 , V_33 , V_32 | 0x8 ) ;
else
F_8 ( V_16 , V_33 , V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_34 ,
int V_35 , unsigned int V_36 , int V_37 )
{
struct V_15 * V_16 = V_34 -> V_16 ;
struct V_17 * V_18 = F_5 ( V_16 ) ;
switch ( V_36 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_18 -> V_21 = V_36 ;
return 0 ;
}
return - V_38 ;
}
static int F_16 ( struct V_13 * V_34 ,
unsigned int V_39 )
{
struct V_15 * V_16 = V_34 -> V_16 ;
T_1 V_19 = F_6 ( V_16 , V_20 ) & 0x000c ;
switch ( V_39 & V_40 ) {
case V_41 :
V_19 |= 0x0040 ;
break;
case V_42 :
break;
default:
return - V_38 ;
}
switch ( V_39 & V_43 ) {
case V_44 :
V_19 |= 0x0002 ;
break;
case V_45 :
break;
case V_46 :
V_19 |= 0x0001 ;
break;
case V_47 :
V_19 |= 0x0003 ;
break;
case V_48 :
V_19 |= 0x0013 ;
break;
default:
return - V_38 ;
}
switch ( V_39 & V_49 ) {
case V_50 :
break;
case V_51 :
V_19 |= 0x0090 ;
break;
case V_52 :
V_19 |= 0x0080 ;
break;
case V_53 :
V_19 |= 0x0010 ;
break;
default:
return - V_38 ;
}
F_8 ( V_16 , V_20 , V_19 ) ;
return 0 ;
}
static int F_17 ( struct V_15 * V_16 ,
enum V_54 V_55 )
{
struct V_17 * V_18 = F_5 ( V_16 ) ;
T_1 V_3 = F_6 ( V_16 , V_56 ) & 0xff7f ;
switch ( V_55 ) {
case V_57 :
F_8 ( V_16 , V_56 , V_3 ) ;
break;
case V_58 :
break;
case V_59 :
if ( V_16 -> V_60 . V_61 == V_62 )
F_18 ( V_18 -> V_63 ) ;
F_8 ( V_16 , V_56 , V_3 | 0x0040 ) ;
break;
case V_62 :
F_8 ( V_16 , V_30 , 0x0 ) ;
F_8 ( V_16 , V_56 , 0xffff ) ;
break;
}
V_16 -> V_60 . V_61 = V_55 ;
return 0 ;
}
static int F_19 ( struct V_15 * V_16 )
{
F_8 ( V_16 , V_30 , 0x0 ) ;
F_17 ( V_16 , V_62 ) ;
return 0 ;
}
static int F_20 ( struct V_15 * V_16 )
{
F_17 ( V_16 , V_59 ) ;
return 0 ;
}
static int F_21 ( struct V_15 * V_16 )
{
int V_64 ;
V_64 = F_22 ( V_16 ) ;
if ( V_64 < 0 ) {
F_23 ( V_16 -> V_2 , L_1 ) ;
return V_64 ;
}
F_17 ( V_16 , V_59 ) ;
F_24 ( V_16 , V_65 , 0x0100 , 0x0100 ) ;
F_24 ( V_16 , V_66 , 0x0100 , 0x0100 ) ;
return V_64 ;
}
static int F_25 ( struct V_15 * V_16 )
{
F_17 ( V_16 , V_62 ) ;
return 0 ;
}
static int F_26 ( struct V_67 * V_68 )
{
struct V_17 * V_18 ;
int V_64 ;
V_18 = F_27 ( & V_68 -> V_2 , sizeof( struct V_17 ) ,
V_69 ) ;
if ( V_18 == NULL )
return - V_70 ;
V_18 -> V_63 = F_28 ( V_68 , & V_71 ) ;
if ( F_29 ( V_18 -> V_63 ) )
return F_30 ( V_18 -> V_63 ) ;
F_31 ( V_68 , V_18 ) ;
V_64 = F_32 ( & V_68 -> V_2 ,
& V_72 , & V_73 , 1 ) ;
return V_64 ;
}
static int F_33 ( struct V_67 * V_68 )
{
F_34 ( & V_68 -> V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_74 * V_75 ,
const struct V_76 * V_77 )
{
struct V_17 * V_18 ;
int V_64 ;
V_18 = F_27 ( & V_75 -> V_2 , sizeof( struct V_17 ) ,
V_69 ) ;
if ( V_18 == NULL )
return - V_70 ;
V_18 -> V_63 = F_36 ( V_75 , & V_71 ) ;
if ( F_29 ( V_18 -> V_63 ) )
return F_30 ( V_18 -> V_63 ) ;
F_37 ( V_75 , V_18 ) ;
V_64 = F_32 ( & V_75 -> V_2 ,
& V_72 , & V_73 , 1 ) ;
return V_64 ;
}
static int F_38 ( struct V_74 * V_75 )
{
F_34 ( & V_75 -> V_2 ) ;
return 0 ;
}
static int T_2 F_39 ( void )
{
int V_64 ;
#if F_40 ( V_78 )
V_64 = F_41 ( & V_79 ) ;
if ( V_64 != 0 ) {
F_42 ( V_80 L_2 ,
V_64 ) ;
}
#endif
#if F_43 ( V_81 )
V_64 = F_44 ( & V_82 ) ;
if ( V_64 != 0 ) {
F_42 ( V_80 L_3 ,
V_64 ) ;
}
#endif
return 0 ;
}
static void T_3 F_45 ( void )
{
#if F_40 ( V_78 )
F_46 ( & V_79 ) ;
#endif
#if F_43 ( V_81 )
F_47 ( & V_82 ) ;
#endif
}
