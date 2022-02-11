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
case 16 :
break;
case 20 :
V_19 |= 0x0004 ;
break;
case 24 :
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
F_8 ( V_16 , V_27 , 0x0001 ) ;
return 0 ;
}
static void F_11 ( struct V_9 * V_10 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
if ( ! F_12 ( V_16 ) ) {
F_13 ( 50 ) ;
F_8 ( V_16 , V_27 , 0x0 ) ;
}
}
static int F_14 ( struct V_13 * V_14 , int V_28 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
T_1 V_29 = F_6 ( V_16 , V_30 ) & 0xfff7 ;
if ( V_28 )
F_8 ( V_16 , V_30 , V_29 | 0x8 ) ;
else
F_8 ( V_16 , V_30 , V_29 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_31 ,
int V_32 , unsigned int V_33 , int V_34 )
{
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_17 * V_18 = F_5 ( V_16 ) ;
switch ( V_33 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_18 -> V_21 = V_33 ;
return 0 ;
}
return - V_35 ;
}
static int F_16 ( struct V_13 * V_31 ,
unsigned int V_36 )
{
struct V_15 * V_16 = V_31 -> V_16 ;
T_1 V_19 = F_6 ( V_16 , V_20 ) & 0x000c ;
switch ( V_36 & V_37 ) {
case V_38 :
V_19 |= 0x0040 ;
break;
case V_39 :
break;
default:
return - V_35 ;
}
switch ( V_36 & V_40 ) {
case V_41 :
V_19 |= 0x0002 ;
break;
case V_42 :
break;
case V_43 :
V_19 |= 0x0001 ;
break;
case V_44 :
V_19 |= 0x0003 ;
break;
case V_45 :
V_19 |= 0x0013 ;
break;
default:
return - V_35 ;
}
switch ( V_36 & V_46 ) {
case V_47 :
break;
case V_48 :
V_19 |= 0x0090 ;
break;
case V_49 :
V_19 |= 0x0080 ;
break;
case V_50 :
V_19 |= 0x0010 ;
break;
default:
return - V_35 ;
}
F_8 ( V_16 , V_20 , V_19 ) ;
return 0 ;
}
static int F_17 ( struct V_15 * V_16 ,
enum V_51 V_52 )
{
struct V_17 * V_18 = F_5 ( V_16 ) ;
T_1 V_3 = F_6 ( V_16 , V_53 ) & 0xff7f ;
switch ( V_52 ) {
case V_54 :
F_8 ( V_16 , V_53 , V_3 ) ;
break;
case V_55 :
break;
case V_56 :
if ( V_16 -> V_57 . V_58 == V_59 )
F_18 ( V_18 -> V_60 ) ;
F_8 ( V_16 , V_53 , V_3 | 0x0040 ) ;
break;
case V_59 :
F_8 ( V_16 , V_27 , 0x0 ) ;
F_8 ( V_16 , V_53 , 0xffff ) ;
break;
}
V_16 -> V_57 . V_58 = V_52 ;
return 0 ;
}
static int F_19 ( struct V_15 * V_16 )
{
int V_61 ;
V_61 = F_20 ( V_16 ) ;
if ( V_61 < 0 ) {
F_21 ( V_16 -> V_2 , L_1 ) ;
return V_61 ;
}
F_22 ( V_16 , V_62 , 0x0100 , 0x0100 ) ;
F_22 ( V_16 , V_63 , 0x0100 , 0x0100 ) ;
return V_61 ;
}
static int F_23 ( struct V_64 * V_65 )
{
struct V_17 * V_18 ;
int V_61 ;
V_18 = F_24 ( & V_65 -> V_2 , sizeof( struct V_17 ) ,
V_66 ) ;
if ( V_18 == NULL )
return - V_67 ;
V_18 -> V_60 = F_25 ( V_65 , & V_68 ) ;
if ( F_26 ( V_18 -> V_60 ) )
return F_27 ( V_18 -> V_60 ) ;
F_28 ( V_65 , V_18 ) ;
V_61 = F_29 ( & V_65 -> V_2 ,
& V_69 , & V_70 , 1 ) ;
return V_61 ;
}
static int F_30 ( struct V_64 * V_65 )
{
F_31 ( & V_65 -> V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_71 * V_72 ,
const struct V_73 * V_74 )
{
struct V_17 * V_18 ;
int V_61 ;
V_18 = F_24 ( & V_72 -> V_2 , sizeof( struct V_17 ) ,
V_66 ) ;
if ( V_18 == NULL )
return - V_67 ;
V_18 -> V_60 = F_33 ( V_72 , & V_68 ) ;
if ( F_26 ( V_18 -> V_60 ) )
return F_27 ( V_18 -> V_60 ) ;
F_34 ( V_72 , V_18 ) ;
V_61 = F_29 ( & V_72 -> V_2 ,
& V_69 , & V_70 , 1 ) ;
return V_61 ;
}
static int F_35 ( struct V_71 * V_72 )
{
F_31 ( & V_72 -> V_2 ) ;
return 0 ;
}
static int T_2 F_36 ( void )
{
int V_61 ;
#if F_37 ( V_75 )
V_61 = F_38 ( & V_76 ) ;
if ( V_61 != 0 ) {
F_39 ( V_77 L_2 ,
V_61 ) ;
}
#endif
#if F_40 ( V_78 )
V_61 = F_41 ( & V_79 ) ;
if ( V_61 != 0 ) {
F_39 ( V_77 L_3 ,
V_61 ) ;
}
#endif
return 0 ;
}
static void T_3 F_42 ( void )
{
#if F_37 ( V_75 )
F_43 ( & V_76 ) ;
#endif
#if F_40 ( V_78 )
F_44 ( & V_79 ) ;
#endif
}
