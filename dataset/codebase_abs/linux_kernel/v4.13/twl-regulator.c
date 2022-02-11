static inline int
F_1 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_3 ,
& V_5 , V_2 -> V_7 + V_4 ) ;
return ( V_6 < 0 ) ? V_6 : V_5 ;
}
static inline int
F_3 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_4 ,
T_1 V_5 )
{
return F_4 ( V_3 ,
V_5 , V_2 -> V_7 + V_4 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
return F_1 ( F_6 ( V_9 ) , V_10 ,
V_11 ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
int V_12 = F_5 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
return V_12 & V_13 ;
}
static int F_8 ( void )
{
int V_14 ;
int V_15 = 10 ;
T_1 V_16 ;
do {
V_14 = F_2 ( V_17 , & V_16 ,
V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( ! ( V_16 & V_19 ) )
return 0 ;
F_9 ( 1 ) ;
V_15 -- ;
} while ( V_15 );
return - V_20 ;
}
static int F_10 ( unsigned V_21 )
{
T_1 V_16 ;
int V_14 ;
V_14 = F_2 ( V_17 , & V_16 ,
V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_4 ( V_17 , V_16 | V_22 ,
V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_8 () ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_4 ( V_17 , V_21 >> 8 ,
V_23 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_4 ( V_17 , V_21 & 0xff ,
V_24 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_8 () ;
if ( V_14 < 0 )
return V_14 ;
return F_4 ( V_17 , V_16 ,
V_18 ) ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_25 ;
int V_14 ;
V_25 = F_5 ( V_9 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 |= V_13 ;
V_14 = F_3 ( V_2 , V_10 , V_11 , V_25 ) ;
return V_14 ;
}
static int F_12 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_25 ;
int V_14 ;
V_25 = F_5 ( V_9 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 &= ~ ( V_13 | V_26 | V_27 ) ;
V_14 = F_3 ( V_2 , V_10 , V_11 , V_25 ) ;
return V_14 ;
}
static int F_13 ( struct V_8 * V_9 )
{
int V_12 = F_5 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 &= 0x0f ;
if ( ! V_12 )
return V_28 ;
return ( V_12 & F_14 ( 3 ) )
? V_29
: V_30 ;
}
static int F_15 ( struct V_8 * V_9 , unsigned V_31 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned V_32 ;
switch ( V_31 ) {
case V_33 :
V_32 = F_16 ( V_34 , V_2 -> V_35 , V_36 ) ;
break;
case V_37 :
V_32 = F_16 ( V_34 , V_2 -> V_35 , V_38 ) ;
break;
default:
return - V_39 ;
}
return F_10 ( V_32 ) ;
}
static inline unsigned int F_17 ( unsigned int V_31 )
{
switch ( V_31 ) {
case V_36 :
return V_33 ;
case V_38 :
return V_37 ;
default:
return - V_39 ;
}
}
static int F_18 ( struct V_8 * V_9 , unsigned V_40 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_41 = V_2 -> V_42 [ V_40 ] ;
return F_19 ( V_2 , V_41 ) ? 0 : ( F_20 ( V_41 ) * 1000 ) ;
}
static int
F_21 ( struct V_8 * V_9 , unsigned V_43 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_3 ( V_2 , V_10 , V_44 ,
V_43 ) ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_45 = F_1 ( V_2 , V_10 , V_44 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 &= V_2 -> V_46 - 1 ;
return V_45 ;
}
static int
F_23 ( struct V_8 * V_9 , int V_47 , int V_48 ,
unsigned * V_43 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_45 = F_24 ( V_47 - 600000 , 12500 ) ;
F_3 ( V_2 , V_10 , V_49 , V_45 ) ;
return 0 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_45 ;
V_45 = F_1 ( V_2 , V_10 ,
V_49 ) ;
return V_45 * 12500 + 600000 ;
}
static int F_26 ( struct V_50 * V_51 )
{
int V_35 ;
struct V_1 * V_2 ;
const struct V_1 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_8 * V_9 ;
const struct V_57 * V_58 ;
struct V_59 V_60 = { } ;
V_58 = F_27 ( V_61 , & V_51 -> V_62 ) ;
if ( ! V_58 )
return - V_63 ;
V_52 = V_58 -> V_64 ;
if ( ! V_52 )
return - V_63 ;
V_35 = V_52 -> V_65 . V_35 ;
V_54 = F_28 ( & V_51 -> V_62 , V_51 -> V_62 . V_66 ,
& V_52 -> V_65 ) ;
if ( ! V_54 )
return - V_39 ;
V_2 = F_29 ( & V_51 -> V_62 , V_52 , sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return - V_68 ;
V_56 = & V_54 -> V_69 ;
V_56 -> V_70 &= V_33 | V_37 ;
V_56 -> V_71 &= V_72
| V_73
| V_74 ;
switch ( V_35 ) {
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
V_56 -> V_82 = true ;
break;
default:
break;
}
V_60 . V_62 = & V_51 -> V_62 ;
V_60 . V_83 = V_54 ;
V_60 . V_84 = V_2 ;
V_60 . V_66 = V_51 -> V_62 . V_66 ;
V_9 = F_30 ( & V_51 -> V_62 , & V_2 -> V_65 , & V_60 ) ;
if ( F_31 ( V_9 ) ) {
F_32 ( & V_51 -> V_62 , L_1 ,
V_2 -> V_65 . V_85 , F_33 ( V_9 ) ) ;
return F_33 ( V_9 ) ;
}
F_34 ( V_51 , V_9 ) ;
F_3 ( V_2 , V_10 , V_86 , V_2 -> V_87 ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
return F_36 ( & V_88 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_88 ) ;
}
