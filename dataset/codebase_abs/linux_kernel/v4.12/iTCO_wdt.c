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
static int F_4 ( void * V_7 , bool V_8 )
{
return 0 ;
}
static int F_5 ( void * V_7 , bool V_8 )
{
struct V_1 * V_2 = V_7 ;
T_1 V_9 = 0 , V_10 = 0 ;
F_6 ( V_2 -> V_11 , 0xd4 , & V_9 ) ;
if ( V_8 )
V_9 |= F_3 ( V_2 ) ;
else
V_9 &= ~ F_3 ( V_2 ) ;
F_7 ( V_2 -> V_11 , 0xd4 , V_9 ) ;
F_6 ( V_2 -> V_11 , 0xd4 , & V_10 ) ;
if ( V_9 != V_10 )
return - V_12 ;
return 0 ;
}
static int F_8 ( void * V_7 , bool V_8 )
{
struct V_1 * V_2 = V_7 ;
T_1 V_9 = 0 , V_10 = 0 ;
V_9 = F_9 ( V_2 -> V_13 ) ;
if ( V_8 )
V_9 |= F_3 ( V_2 ) ;
else
V_9 &= ~ F_3 ( V_2 ) ;
F_10 ( V_9 , V_2 -> V_13 ) ;
V_10 = F_9 ( V_2 -> V_13 ) ;
if ( V_9 != V_10 )
return - V_12 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
if ( V_15 -> V_16 ) {
V_2 -> V_16 = V_15 -> V_16 ;
V_2 -> V_17 = V_15 -> V_17 ;
return;
}
if ( V_2 -> V_4 >= 2 )
V_2 -> V_16 = F_8 ;
else if ( V_2 -> V_4 == 1 )
V_2 -> V_16 = F_5 ;
else
V_2 -> V_16 = F_4 ;
V_2 -> V_17 = V_2 ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_13 ( V_19 ) ;
unsigned int V_20 ;
F_14 ( & V_2 -> V_21 ) ;
F_15 ( V_2 -> V_22 , V_19 -> V_23 ) ;
if ( V_2 -> V_16 ( V_2 -> V_17 , false ) ) {
F_16 ( & V_2 -> V_21 ) ;
F_17 ( L_1 ) ;
return - V_12 ;
}
if ( V_2 -> V_4 >= 2 )
F_18 ( 0x01 , F_19 ( V_2 ) ) ;
else if ( V_2 -> V_4 == 1 )
F_20 ( 0x01 , F_19 ( V_2 ) ) ;
V_20 = F_21 ( F_22 ( V_2 ) ) ;
V_20 &= 0xf7ff ;
F_18 ( V_20 , F_22 ( V_2 ) ) ;
V_20 = F_21 ( F_22 ( V_2 ) ) ;
F_16 ( & V_2 -> V_21 ) ;
if ( V_20 & 0x0800 )
return - 1 ;
return 0 ;
}
static int F_23 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_13 ( V_19 ) ;
unsigned int V_20 ;
F_14 ( & V_2 -> V_21 ) ;
F_24 ( V_2 -> V_22 ) ;
V_20 = F_21 ( F_22 ( V_2 ) ) ;
V_20 |= 0x0800 ;
F_18 ( V_20 , F_22 ( V_2 ) ) ;
V_20 = F_21 ( F_22 ( V_2 ) ) ;
V_2 -> V_16 ( V_2 -> V_17 , true ) ;
F_16 ( & V_2 -> V_21 ) ;
if ( ( V_20 & 0x0800 ) == 0 )
return - 1 ;
return 0 ;
}
static int F_25 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_13 ( V_19 ) ;
F_14 ( & V_2 -> V_21 ) ;
F_26 ( V_2 -> V_22 , V_19 -> V_23 ) ;
F_18 ( 0x0008 , F_27 ( V_2 ) ) ;
if ( V_2 -> V_4 >= 2 )
F_18 ( 0x01 , F_19 ( V_2 ) ) ;
else if ( V_2 -> V_4 == 1 )
F_20 ( 0x01 , F_19 ( V_2 ) ) ;
F_16 ( & V_2 -> V_21 ) ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 , unsigned int V_24 )
{
struct V_1 * V_2 = F_13 ( V_19 ) ;
unsigned int V_25 ;
unsigned char V_26 ;
unsigned int V_27 ;
V_27 = F_1 ( V_2 , V_24 ) / 2 ;
if ( V_27 < 0x04 )
return - V_28 ;
if ( ( V_2 -> V_4 >= 2 && V_27 > 0x3ff ) ||
( V_2 -> V_4 == 1 && V_27 > 0x03f ) )
return - V_28 ;
F_29 ( V_27 ) ;
if ( V_2 -> V_4 >= 2 ) {
F_14 ( & V_2 -> V_21 ) ;
V_25 = F_21 ( F_30 ( V_2 ) ) ;
V_25 &= 0xfc00 ;
V_25 |= V_27 ;
F_18 ( V_25 , F_30 ( V_2 ) ) ;
V_25 = F_21 ( F_30 ( V_2 ) ) ;
F_16 ( & V_2 -> V_21 ) ;
if ( ( V_25 & 0x3ff ) != V_27 )
return - V_28 ;
} else if ( V_2 -> V_4 == 1 ) {
F_14 ( & V_2 -> V_21 ) ;
V_26 = F_31 ( F_32 ( V_2 ) ) ;
V_26 &= 0xc0 ;
V_26 |= ( V_27 & 0xff ) ;
F_20 ( V_26 , F_32 ( V_2 ) ) ;
V_26 = F_31 ( F_32 ( V_2 ) ) ;
F_16 ( & V_2 -> V_21 ) ;
if ( ( V_26 & 0x3f ) != V_27 )
return - V_28 ;
}
V_19 -> V_23 = V_24 ;
return 0 ;
}
static unsigned int F_33 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_13 ( V_19 ) ;
unsigned int V_25 ;
unsigned char V_26 ;
unsigned int V_29 = 0 ;
if ( V_2 -> V_4 >= 2 ) {
F_14 ( & V_2 -> V_21 ) ;
V_25 = F_21 ( F_19 ( V_2 ) ) ;
V_25 &= 0x3ff ;
if ( ! ( F_21 ( F_27 ( V_2 ) ) & 0x0008 ) )
V_25 += ( F_21 ( F_30 ( V_2 ) ) & 0x3ff ) ;
F_16 ( & V_2 -> V_21 ) ;
V_29 = F_2 ( V_2 , V_25 ) ;
} else if ( V_2 -> V_4 == 1 ) {
F_14 ( & V_2 -> V_21 ) ;
V_26 = F_31 ( F_19 ( V_2 ) ) ;
V_26 &= 0x3f ;
if ( ! ( F_21 ( F_27 ( V_2 ) ) & 0x0008 ) )
V_26 += ( F_31 ( F_32 ( V_2 ) ) & 0x3f ) ;
F_16 ( & V_2 -> V_21 ) ;
V_29 = F_2 ( V_2 , V_26 ) ;
}
return V_29 ;
}
static int F_34 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = & V_31 -> V_33 ;
struct V_14 * V_15 = F_35 ( V_33 ) ;
struct V_1 * V_2 ;
unsigned long V_9 ;
int V_34 ;
if ( ! V_15 )
return - V_35 ;
V_2 = F_36 ( V_33 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
F_37 ( & V_2 -> V_21 ) ;
V_2 -> V_38 = F_38 ( V_31 , V_39 , V_40 ) ;
if ( ! V_2 -> V_38 )
return - V_35 ;
V_2 -> V_22 = F_38 ( V_31 , V_39 , V_41 ) ;
if ( ! V_2 -> V_22 )
return - V_35 ;
V_2 -> V_4 = V_15 -> V_42 ;
V_2 -> V_11 = F_39 ( V_33 -> V_43 ) ;
F_11 ( V_2 , V_15 ) ;
if ( V_2 -> V_4 >= 2 && ! V_15 -> V_16 ) {
V_2 -> V_44 = F_38 ( V_31 ,
V_45 ,
V_46 ) ;
V_2 -> V_13 = F_40 ( V_33 , V_2 -> V_44 ) ;
if ( F_41 ( V_2 -> V_13 ) )
return F_42 ( V_2 -> V_13 ) ;
}
if ( V_2 -> V_16 ( V_2 -> V_17 , false ) &&
F_43 () ) {
F_44 ( L_2 ) ;
return - V_35 ;
}
V_2 -> V_16 ( V_2 -> V_17 , true ) ;
if ( ! F_45 ( V_33 , V_2 -> V_22 -> V_47 ,
F_46 ( V_2 -> V_22 ) ,
V_31 -> V_48 ) ) {
F_17 ( L_3 ,
( V_49 ) F_47 ( V_2 ) ) ;
return - V_50 ;
}
if ( V_51 >= V_2 -> V_4 ) {
V_9 = F_48 ( F_47 ( V_2 ) ) ;
V_9 &= 0xffffdfff ;
F_49 ( V_9 , F_47 ( V_2 ) ) ;
}
if ( ! F_45 ( V_33 , V_2 -> V_38 -> V_47 ,
F_46 ( V_2 -> V_38 ) ,
V_31 -> V_48 ) ) {
F_17 ( L_3 ,
( V_49 ) F_50 ( V_2 ) ) ;
return - V_50 ;
}
F_44 ( L_4 ,
V_15 -> V_48 , V_15 -> V_42 , ( V_49 ) F_50 ( V_2 ) ) ;
switch ( V_2 -> V_4 ) {
case 5 :
case 4 :
F_18 ( 0x0008 , F_27 ( V_2 ) ) ;
F_18 ( 0x0002 , F_51 ( V_2 ) ) ;
break;
case 3 :
F_49 ( 0x20008 , F_27 ( V_2 ) ) ;
break;
case 2 :
case 1 :
default:
F_18 ( 0x0008 , F_27 ( V_2 ) ) ;
F_18 ( 0x0002 , F_51 ( V_2 ) ) ;
F_18 ( 0x0004 , F_51 ( V_2 ) ) ;
break;
}
V_2 -> V_52 . V_53 = & V_54 ,
V_2 -> V_52 . V_55 = & V_56 ,
V_2 -> V_52 . V_57 = 0 ;
V_2 -> V_52 . V_23 = V_58 ;
F_52 ( & V_2 -> V_52 , V_59 ) ;
V_2 -> V_52 . V_43 = V_33 ;
F_53 ( & V_2 -> V_52 , V_2 ) ;
F_54 ( V_31 , V_2 ) ;
F_23 ( & V_2 -> V_52 ) ;
if ( F_28 ( & V_2 -> V_52 , V_60 ) ) {
F_28 ( & V_2 -> V_52 , V_58 ) ;
F_44 ( L_5 ,
V_58 ) ;
}
F_55 ( & V_2 -> V_52 ) ;
V_34 = F_56 ( V_33 , & V_2 -> V_52 ) ;
if ( V_34 != 0 ) {
F_17 ( L_6 , V_34 ) ;
return V_34 ;
}
F_44 ( L_7 ,
V_60 , V_59 ) ;
return 0 ;
}
static int F_57 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_58 ( V_31 ) ;
if ( ! V_59 )
F_23 ( & V_2 -> V_52 ) ;
return 0 ;
}
static inline bool F_59 ( void )
{
return F_60 () == V_61 ;
}
static inline bool F_59 ( void ) { return true ; }
static int F_61 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_62 ( V_33 ) ;
int V_34 = 0 ;
V_2 -> V_62 = false ;
if ( F_63 ( & V_2 -> V_52 ) && F_59 () ) {
V_34 = F_23 ( & V_2 -> V_52 ) ;
if ( ! V_34 )
V_2 -> V_62 = true ;
}
return V_34 ;
}
static int F_64 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_62 ( V_33 ) ;
if ( V_2 -> V_62 )
F_12 ( & V_2 -> V_52 ) ;
return 0 ;
}
static int T_2 F_65 ( void )
{
F_44 ( L_8 , V_63 ) ;
return F_66 ( & V_64 ) ;
}
static void T_3 F_67 ( void )
{
F_68 ( & V_64 ) ;
F_44 ( L_9 ) ;
}
