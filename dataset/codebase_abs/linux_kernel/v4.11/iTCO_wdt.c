static inline unsigned int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
return V_2 -> V_4 == 3 ? V_3 : ( V_3 * 10 ) / 6 ;
}
static inline unsigned int F_2 ( struct V_1 * V_2 ,
int V_5 )
{
return V_2 -> V_4 == 3 ? V_5 : ( V_5 * 6 ) / 10 ;
}
static inline T_1 F_3 ( struct V_1 * V_2 )
{
T_1 V_6 ;
switch ( V_2 -> V_4 ) {
case 5 :
case 3 :
V_6 = 0x00000010 ;
break;
case 2 :
V_6 = 0x00000020 ;
break;
case 4 :
case 1 :
default:
V_6 = 0x00000002 ;
break;
}
return V_6 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_7 ;
if ( V_2 -> V_4 >= 2 ) {
V_7 = F_5 ( V_2 -> V_8 ) ;
V_7 |= F_3 ( V_2 ) ;
F_6 ( V_7 , V_2 -> V_8 ) ;
} else if ( V_2 -> V_4 == 1 ) {
F_7 ( V_2 -> V_9 , 0xd4 , & V_7 ) ;
V_7 |= F_3 ( V_2 ) ;
F_8 ( V_2 -> V_9 , 0xd4 , V_7 ) ;
}
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_6 = F_3 ( V_2 ) ;
T_1 V_7 = 0 ;
if ( V_2 -> V_4 >= 2 ) {
V_7 = F_5 ( V_2 -> V_8 ) ;
V_7 &= ~ V_6 ;
F_6 ( V_7 , V_2 -> V_8 ) ;
V_7 = F_5 ( V_2 -> V_8 ) ;
} else if ( V_2 -> V_4 == 1 ) {
F_7 ( V_2 -> V_9 , 0xd4 , & V_7 ) ;
V_7 &= ~ V_6 ;
F_8 ( V_2 -> V_9 , 0xd4 , V_7 ) ;
F_7 ( V_2 -> V_9 , 0xd4 , & V_7 ) ;
}
if ( V_7 & V_6 )
return - V_10 ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
unsigned int V_13 ;
F_12 ( & V_2 -> V_14 ) ;
F_13 ( V_2 -> V_15 , V_12 -> V_16 ) ;
if ( F_9 ( V_2 ) ) {
F_14 ( & V_2 -> V_14 ) ;
F_15 ( L_1 ) ;
return - V_10 ;
}
if ( V_2 -> V_4 >= 2 )
F_16 ( 0x01 , F_17 ( V_2 ) ) ;
else if ( V_2 -> V_4 == 1 )
F_18 ( 0x01 , F_17 ( V_2 ) ) ;
V_13 = F_19 ( F_20 ( V_2 ) ) ;
V_13 &= 0xf7ff ;
F_16 ( V_13 , F_20 ( V_2 ) ) ;
V_13 = F_19 ( F_20 ( V_2 ) ) ;
F_14 ( & V_2 -> V_14 ) ;
if ( V_13 & 0x0800 )
return - 1 ;
return 0 ;
}
static int F_21 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
unsigned int V_13 ;
F_12 ( & V_2 -> V_14 ) ;
F_22 ( V_2 -> V_15 ) ;
V_13 = F_19 ( F_20 ( V_2 ) ) ;
V_13 |= 0x0800 ;
F_16 ( V_13 , F_20 ( V_2 ) ) ;
V_13 = F_19 ( F_20 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_14 ( & V_2 -> V_14 ) ;
if ( ( V_13 & 0x0800 ) == 0 )
return - 1 ;
return 0 ;
}
static int F_23 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
F_12 ( & V_2 -> V_14 ) ;
F_24 ( V_2 -> V_15 , V_12 -> V_16 ) ;
if ( V_2 -> V_4 >= 2 ) {
F_16 ( 0x01 , F_17 ( V_2 ) ) ;
} else if ( V_2 -> V_4 == 1 ) {
F_16 ( 0x0008 , F_25 ( V_2 ) ) ;
F_18 ( 0x01 , F_17 ( V_2 ) ) ;
}
F_14 ( & V_2 -> V_14 ) ;
return 0 ;
}
static int F_26 ( struct V_11 * V_12 , unsigned int V_17 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
unsigned int V_18 ;
unsigned char V_19 ;
unsigned int V_20 ;
V_20 = F_1 ( V_2 , V_17 ) ;
if ( V_2 -> V_4 == 1 )
V_20 /= 2 ;
if ( V_20 < 0x04 )
return - V_21 ;
if ( ( V_2 -> V_4 >= 2 && V_20 > 0x3ff ) ||
( V_2 -> V_4 == 1 && V_20 > 0x03f ) )
return - V_21 ;
F_27 ( V_20 ) ;
if ( V_2 -> V_4 >= 2 ) {
F_12 ( & V_2 -> V_14 ) ;
V_18 = F_19 ( F_28 ( V_2 ) ) ;
V_18 &= 0xfc00 ;
V_18 |= V_20 ;
F_16 ( V_18 , F_28 ( V_2 ) ) ;
V_18 = F_19 ( F_28 ( V_2 ) ) ;
F_14 ( & V_2 -> V_14 ) ;
if ( ( V_18 & 0x3ff ) != V_20 )
return - V_21 ;
} else if ( V_2 -> V_4 == 1 ) {
F_12 ( & V_2 -> V_14 ) ;
V_19 = F_29 ( F_30 ( V_2 ) ) ;
V_19 &= 0xc0 ;
V_19 |= ( V_20 & 0xff ) ;
F_18 ( V_19 , F_30 ( V_2 ) ) ;
V_19 = F_29 ( F_30 ( V_2 ) ) ;
F_14 ( & V_2 -> V_14 ) ;
if ( ( V_19 & 0x3f ) != V_20 )
return - V_21 ;
}
V_12 -> V_16 = V_17 ;
return 0 ;
}
static unsigned int F_31 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
unsigned int V_18 ;
unsigned char V_19 ;
unsigned int V_22 = 0 ;
if ( V_2 -> V_4 >= 2 ) {
F_12 ( & V_2 -> V_14 ) ;
V_18 = F_19 ( F_17 ( V_2 ) ) ;
V_18 &= 0x3ff ;
F_14 ( & V_2 -> V_14 ) ;
V_22 = F_2 ( V_2 , V_18 ) ;
} else if ( V_2 -> V_4 == 1 ) {
F_12 ( & V_2 -> V_14 ) ;
V_19 = F_29 ( F_17 ( V_2 ) ) ;
V_19 &= 0x3f ;
if ( ! ( F_19 ( F_25 ( V_2 ) ) & 0x0008 ) )
V_19 += ( F_29 ( F_30 ( V_2 ) ) & 0x3f ) ;
F_14 ( & V_2 -> V_14 ) ;
V_22 = F_2 ( V_2 , V_19 ) ;
}
return V_22 ;
}
static int F_32 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = & V_24 -> V_26 ;
struct V_27 * V_28 = F_33 ( V_26 ) ;
struct V_1 * V_2 ;
unsigned long V_7 ;
int V_29 ;
if ( ! V_28 )
return - V_30 ;
V_2 = F_34 ( V_26 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
return - V_32 ;
F_35 ( & V_2 -> V_14 ) ;
V_2 -> V_33 = F_36 ( V_24 , V_34 , V_35 ) ;
if ( ! V_2 -> V_33 )
return - V_30 ;
V_2 -> V_15 = F_36 ( V_24 , V_34 , V_36 ) ;
if ( ! V_2 -> V_15 )
return - V_30 ;
V_2 -> V_4 = V_28 -> V_37 ;
V_2 -> V_9 = F_37 ( V_26 -> V_38 ) ;
if ( V_2 -> V_4 >= 2 ) {
V_2 -> V_39 = F_36 ( V_24 ,
V_40 ,
V_41 ) ;
V_2 -> V_8 = F_38 ( V_26 , V_2 -> V_39 ) ;
if ( F_39 ( V_2 -> V_8 ) )
return F_40 ( V_2 -> V_8 ) ;
}
if ( F_9 ( V_2 ) &&
F_41 () ) {
F_42 ( L_2 ) ;
return - V_30 ;
}
F_4 ( V_2 ) ;
if ( ! F_43 ( V_26 , V_2 -> V_15 -> V_42 ,
F_44 ( V_2 -> V_15 ) ,
V_24 -> V_43 ) ) {
F_15 ( L_3 ,
( V_44 ) F_45 ( V_2 ) ) ;
return - V_45 ;
}
if ( V_46 >= V_2 -> V_4 ) {
V_7 = F_46 ( F_45 ( V_2 ) ) ;
V_7 &= 0xffffdfff ;
F_47 ( V_7 , F_45 ( V_2 ) ) ;
}
if ( ! F_43 ( V_26 , V_2 -> V_33 -> V_42 ,
F_44 ( V_2 -> V_33 ) ,
V_24 -> V_43 ) ) {
F_15 ( L_3 ,
( V_44 ) F_48 ( V_2 ) ) ;
return - V_45 ;
}
F_42 ( L_4 ,
V_28 -> V_43 , V_28 -> V_37 , ( V_44 ) F_48 ( V_2 ) ) ;
switch ( V_2 -> V_4 ) {
case 5 :
case 4 :
F_16 ( 0x0008 , F_25 ( V_2 ) ) ;
F_16 ( 0x0002 , F_49 ( V_2 ) ) ;
break;
case 3 :
F_47 ( 0x20008 , F_25 ( V_2 ) ) ;
break;
case 2 :
case 1 :
default:
F_16 ( 0x0008 , F_25 ( V_2 ) ) ;
F_16 ( 0x0002 , F_49 ( V_2 ) ) ;
F_16 ( 0x0004 , F_49 ( V_2 ) ) ;
break;
}
V_2 -> V_47 . V_48 = & V_49 ,
V_2 -> V_47 . V_50 = & V_51 ,
V_2 -> V_47 . V_52 = 0 ;
V_2 -> V_47 . V_16 = V_53 ;
F_50 ( & V_2 -> V_47 , V_54 ) ;
V_2 -> V_47 . V_38 = V_26 ;
F_51 ( & V_2 -> V_47 , V_2 ) ;
F_52 ( V_24 , V_2 ) ;
F_21 ( & V_2 -> V_47 ) ;
if ( F_26 ( & V_2 -> V_47 , V_55 ) ) {
F_26 ( & V_2 -> V_47 , V_53 ) ;
F_42 ( L_5 ,
V_53 ) ;
}
F_53 ( & V_2 -> V_47 ) ;
V_29 = F_54 ( V_26 , & V_2 -> V_47 ) ;
if ( V_29 != 0 ) {
F_15 ( L_6 , V_29 ) ;
return V_29 ;
}
F_42 ( L_7 ,
V_55 , V_54 ) ;
return 0 ;
}
static int F_55 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_56 ( V_24 ) ;
if ( ! V_54 )
F_21 ( & V_2 -> V_47 ) ;
return 0 ;
}
static inline bool F_57 ( void )
{
return F_58 () == V_56 ;
}
static inline bool F_57 ( void ) { return true ; }
static int F_59 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_60 ( V_26 ) ;
int V_29 = 0 ;
V_2 -> V_57 = false ;
if ( F_61 ( & V_2 -> V_47 ) && F_57 () ) {
V_29 = F_21 ( & V_2 -> V_47 ) ;
if ( ! V_29 )
V_2 -> V_57 = true ;
}
return V_29 ;
}
static int F_62 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_60 ( V_26 ) ;
if ( V_2 -> V_57 )
F_10 ( & V_2 -> V_47 ) ;
return 0 ;
}
static int T_2 F_63 ( void )
{
F_42 ( L_8 , V_58 ) ;
return F_64 ( & V_59 ) ;
}
static void T_3 F_65 ( void )
{
F_66 ( & V_59 ) ;
F_42 ( L_9 ) ;
}
