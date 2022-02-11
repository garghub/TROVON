static inline unsigned int F_1 ( int V_1 )
{
return V_2 . V_3 == 3 ? V_1 : ( V_1 * 10 ) / 6 ;
}
static inline unsigned int F_2 ( int V_4 )
{
return V_2 . V_3 == 3 ? V_4 : ( V_4 * 6 ) / 10 ;
}
static inline T_1 F_3 ( void )
{
T_1 V_5 ;
switch ( V_2 . V_3 ) {
case 3 :
V_5 = 0x00000010 ;
break;
case 2 :
V_5 = 0x00000020 ;
break;
case 4 :
case 1 :
default:
V_5 = 0x00000002 ;
break;
}
return V_5 ;
}
static void F_4 ( void )
{
T_1 V_6 ;
if ( V_2 . V_3 >= 2 ) {
V_6 = F_5 ( V_2 . V_7 ) ;
V_6 |= F_3 () ;
F_6 ( V_6 , V_2 . V_7 ) ;
} else if ( V_2 . V_3 == 1 ) {
F_7 ( V_2 . V_8 , 0xd4 , & V_6 ) ;
V_6 |= F_3 () ;
F_8 ( V_2 . V_8 , 0xd4 , V_6 ) ;
}
}
static int F_9 ( void )
{
T_1 V_5 = F_3 () ;
T_1 V_6 = 0 ;
if ( V_2 . V_3 >= 2 ) {
V_6 = F_5 ( V_2 . V_7 ) ;
V_6 &= ~ V_5 ;
F_6 ( V_6 , V_2 . V_7 ) ;
V_6 = F_5 ( V_2 . V_7 ) ;
} else if ( V_2 . V_3 == 1 ) {
F_7 ( V_2 . V_8 , 0xd4 , & V_6 ) ;
V_6 &= ~ V_5 ;
F_8 ( V_2 . V_8 , 0xd4 , V_6 ) ;
F_7 ( V_2 . V_8 , 0xd4 , & V_6 ) ;
}
if ( V_6 & V_5 )
return - V_9 ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 )
{
unsigned int V_12 ;
F_11 ( & V_2 . V_13 ) ;
F_12 ( V_2 . V_14 , V_11 -> V_15 ) ;
if ( F_9 () ) {
F_13 ( & V_2 . V_13 ) ;
F_14 ( L_1 ) ;
return - V_9 ;
}
if ( V_2 . V_3 >= 2 )
F_15 ( 0x01 , V_16 ) ;
else if ( V_2 . V_3 == 1 )
F_16 ( 0x01 , V_16 ) ;
V_12 = F_17 ( V_17 ) ;
V_12 &= 0xf7ff ;
F_15 ( V_12 , V_17 ) ;
V_12 = F_17 ( V_17 ) ;
F_13 ( & V_2 . V_13 ) ;
if ( V_12 & 0x0800 )
return - 1 ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 )
{
unsigned int V_12 ;
F_11 ( & V_2 . V_13 ) ;
F_19 ( V_2 . V_14 ) ;
V_12 = F_17 ( V_17 ) ;
V_12 |= 0x0800 ;
F_15 ( V_12 , V_17 ) ;
V_12 = F_17 ( V_17 ) ;
F_4 () ;
F_13 ( & V_2 . V_13 ) ;
if ( ( V_12 & 0x0800 ) == 0 )
return - 1 ;
return 0 ;
}
static int F_20 ( struct V_10 * V_11 )
{
F_11 ( & V_2 . V_13 ) ;
F_21 ( V_2 . V_14 , V_11 -> V_15 ) ;
if ( V_2 . V_3 >= 2 ) {
F_15 ( 0x01 , V_16 ) ;
} else if ( V_2 . V_3 == 1 ) {
F_15 ( 0x0008 , V_18 ) ;
F_16 ( 0x01 , V_16 ) ;
}
F_13 ( & V_2 . V_13 ) ;
return 0 ;
}
static int F_22 ( struct V_10 * V_11 , unsigned int V_19 )
{
unsigned int V_20 ;
unsigned char V_21 ;
unsigned int V_22 ;
V_22 = F_1 ( V_19 ) ;
if ( V_2 . V_3 == 1 )
V_22 /= 2 ;
if ( V_22 < 0x04 )
return - V_23 ;
if ( ( ( V_2 . V_3 >= 2 ) && ( V_22 > 0x3ff ) ) ||
( ( V_2 . V_3 == 1 ) && ( V_22 > 0x03f ) ) )
return - V_23 ;
F_23 ( V_22 ) ;
if ( V_2 . V_3 >= 2 ) {
F_11 ( & V_2 . V_13 ) ;
V_20 = F_17 ( V_24 ) ;
V_20 &= 0xfc00 ;
V_20 |= V_22 ;
F_15 ( V_20 , V_24 ) ;
V_20 = F_17 ( V_24 ) ;
F_13 ( & V_2 . V_13 ) ;
if ( ( V_20 & 0x3ff ) != V_22 )
return - V_23 ;
} else if ( V_2 . V_3 == 1 ) {
F_11 ( & V_2 . V_13 ) ;
V_21 = F_24 ( V_25 ) ;
V_21 &= 0xc0 ;
V_21 |= ( V_22 & 0xff ) ;
F_16 ( V_21 , V_25 ) ;
V_21 = F_24 ( V_25 ) ;
F_13 ( & V_2 . V_13 ) ;
if ( ( V_21 & 0x3f ) != V_22 )
return - V_23 ;
}
V_11 -> V_15 = V_19 ;
return 0 ;
}
static unsigned int F_25 ( struct V_10 * V_11 )
{
unsigned int V_20 ;
unsigned char V_21 ;
unsigned int V_26 = 0 ;
if ( V_2 . V_3 >= 2 ) {
F_11 ( & V_2 . V_13 ) ;
V_20 = F_17 ( V_16 ) ;
V_20 &= 0x3ff ;
F_13 ( & V_2 . V_13 ) ;
V_26 = F_2 ( V_20 ) ;
} else if ( V_2 . V_3 == 1 ) {
F_11 ( & V_2 . V_13 ) ;
V_21 = F_24 ( V_16 ) ;
V_21 &= 0x3f ;
if ( ! ( F_17 ( V_18 ) & 0x0008 ) )
V_21 += ( F_24 ( V_25 ) & 0x3f ) ;
F_13 ( & V_2 . V_13 ) ;
V_26 = F_2 ( V_21 ) ;
}
return V_26 ;
}
static void F_26 ( void )
{
if ( ! V_27 )
F_18 ( & V_28 ) ;
F_27 ( & V_28 ) ;
F_28 ( V_2 . V_29 -> V_30 ,
F_29 ( V_2 . V_29 ) ) ;
F_28 ( V_2 . V_14 -> V_30 ,
F_29 ( V_2 . V_14 ) ) ;
if ( V_2 . V_3 >= 2 ) {
F_30 ( V_2 . V_7 ) ;
F_31 ( V_2 . V_31 -> V_30 ,
F_29 ( V_2 . V_31 ) ) ;
}
V_2 . V_29 = NULL ;
V_2 . V_14 = NULL ;
V_2 . V_31 = NULL ;
V_2 . V_7 = NULL ;
}
static int F_32 ( struct V_32 * V_33 )
{
int V_34 = - V_35 ;
unsigned long V_6 ;
struct V_36 * V_37 = F_33 ( & V_33 -> V_33 ) ;
if ( ! V_37 )
goto V_38;
F_34 ( & V_2 . V_13 ) ;
V_2 . V_29 =
F_35 ( V_33 , V_39 , V_40 ) ;
if ( ! V_2 . V_29 )
goto V_38;
V_2 . V_14 =
F_35 ( V_33 , V_39 , V_41 ) ;
if ( ! V_2 . V_14 )
goto V_38;
V_2 . V_3 = V_37 -> V_42 ;
V_2 . V_33 = V_33 ;
V_2 . V_8 = F_36 ( V_33 -> V_33 . V_43 ) ;
if ( V_2 . V_3 >= 2 ) {
V_2 . V_31 = F_35 ( V_33 ,
V_44 ,
V_45 ) ;
if ( ! V_2 . V_31 )
goto V_38;
if ( ! F_37 ( V_2 . V_31 -> V_30 ,
F_29 ( V_2 . V_31 ) , V_33 -> V_46 ) ) {
V_34 = - V_47 ;
goto V_38;
}
V_2 . V_7 = F_38 ( V_2 . V_31 -> V_30 ,
F_29 ( V_2 . V_31 ) ) ;
if ( ! V_2 . V_7 ) {
V_34 = - V_9 ;
goto V_48;
}
}
if ( F_9 () && F_39 () ) {
F_40 ( L_2 ) ;
V_34 = - V_35 ;
goto V_49;
}
F_4 () ;
if ( ! F_41 ( V_2 . V_14 -> V_30 ,
F_29 ( V_2 . V_14 ) , V_33 -> V_46 ) ) {
F_14 ( L_3 ,
( V_50 ) V_51 ) ;
V_34 = - V_47 ;
goto V_49;
}
if ( V_52 >= V_2 . V_3 ) {
V_6 = F_42 ( V_51 ) ;
V_6 &= 0xffffdfff ;
F_43 ( V_6 , V_51 ) ;
}
if ( ! F_41 ( V_2 . V_29 -> V_30 ,
F_29 ( V_2 . V_29 ) , V_33 -> V_46 ) ) {
F_14 ( L_3 ,
( V_50 ) V_53 ) ;
V_34 = - V_47 ;
goto V_54;
}
F_40 ( L_4 ,
V_37 -> V_46 , V_37 -> V_42 , ( V_50 ) V_53 ) ;
switch ( V_2 . V_3 ) {
case 4 :
F_15 ( 0x0008 , V_18 ) ;
F_15 ( 0x0002 , V_55 ) ;
break;
case 3 :
F_43 ( 0x20008 , V_18 ) ;
break;
case 2 :
case 1 :
default:
F_15 ( 0x0008 , V_18 ) ;
F_15 ( 0x0002 , V_55 ) ;
F_15 ( 0x0004 , V_55 ) ;
break;
}
V_28 . V_56 = 0 ;
V_28 . V_15 = V_57 ;
F_44 ( & V_28 , V_27 ) ;
V_28 . V_43 = & V_33 -> V_33 ;
F_18 ( & V_28 ) ;
if ( F_22 ( & V_28 , V_58 ) ) {
F_22 ( & V_28 , V_57 ) ;
F_40 ( L_5 ,
V_57 ) ;
}
V_34 = F_45 ( & V_28 ) ;
if ( V_34 != 0 ) {
F_14 ( L_6 , V_34 ) ;
goto V_59;
}
F_40 ( L_7 ,
V_58 , V_27 ) ;
return 0 ;
V_59:
F_28 ( V_2 . V_29 -> V_30 ,
F_29 ( V_2 . V_29 ) ) ;
V_54:
F_28 ( V_2 . V_14 -> V_30 ,
F_29 ( V_2 . V_14 ) ) ;
V_49:
if ( V_2 . V_3 >= 2 )
F_30 ( V_2 . V_7 ) ;
V_48:
if ( V_2 . V_3 >= 2 )
F_31 ( V_2 . V_31 -> V_30 ,
F_29 ( V_2 . V_31 ) ) ;
V_38:
V_2 . V_29 = NULL ;
V_2 . V_14 = NULL ;
V_2 . V_31 = NULL ;
V_2 . V_7 = NULL ;
return V_34 ;
}
static int F_46 ( struct V_32 * V_33 )
{
if ( V_2 . V_29 || V_2 . V_14 )
F_26 () ;
return 0 ;
}
static void F_47 ( struct V_32 * V_33 )
{
F_18 ( NULL ) ;
}
static inline bool F_48 ( void )
{
return F_49 () == V_60 ;
}
static inline bool F_48 ( void ) { return true ; }
static int F_50 ( struct V_61 * V_33 )
{
int V_34 = 0 ;
V_2 . V_62 = false ;
if ( F_51 ( & V_28 ) && F_48 () ) {
V_34 = F_18 ( & V_28 ) ;
if ( ! V_34 )
V_2 . V_62 = true ;
}
return V_34 ;
}
static int F_52 ( struct V_61 * V_33 )
{
if ( V_2 . V_62 )
F_10 ( & V_28 ) ;
return 0 ;
}
static int T_2 F_53 ( void )
{
int V_63 ;
F_40 ( L_8 , V_64 ) ;
V_63 = F_54 ( & V_65 ) ;
if ( V_63 )
return V_63 ;
return 0 ;
}
static void T_3 F_55 ( void )
{
F_56 ( & V_65 ) ;
F_40 ( L_9 ) ;
}
