static inline unsigned int F_1 ( int V_1 )
{
return ( V_1 * 10 ) / 6 ;
}
static void F_2 ( void )
{
T_1 V_2 ;
if ( V_3 . V_4 == 2 ) {
V_2 = F_3 ( V_3 . V_5 ) ;
V_2 |= 0x00000020 ;
F_4 ( V_2 , V_3 . V_5 ) ;
} else if ( V_3 . V_4 == 1 ) {
F_5 ( V_3 . V_6 , 0xd4 , & V_2 ) ;
V_2 |= 0x00000002 ;
F_6 ( V_3 . V_6 , 0xd4 , V_2 ) ;
}
}
static int F_7 ( void )
{
int V_7 = 0 ;
T_1 V_2 ;
if ( V_3 . V_4 == 2 ) {
V_2 = F_3 ( V_3 . V_5 ) ;
V_2 &= 0xffffffdf ;
F_4 ( V_2 , V_3 . V_5 ) ;
V_2 = F_3 ( V_3 . V_5 ) ;
if ( V_2 & 0x00000020 )
V_7 = - V_8 ;
} else if ( V_3 . V_4 == 1 ) {
F_5 ( V_3 . V_6 , 0xd4 , & V_2 ) ;
V_2 &= 0xfffffffd ;
F_6 ( V_3 . V_6 , 0xd4 , V_2 ) ;
F_5 ( V_3 . V_6 , 0xd4 , & V_2 ) ;
if ( V_2 & 0x00000002 )
V_7 = - V_8 ;
}
return V_7 ;
}
static int F_8 ( struct V_9 * V_10 )
{
unsigned int V_11 ;
F_9 ( & V_3 . V_12 ) ;
F_10 ( V_3 . V_13 , V_10 -> V_14 ) ;
if ( F_7 () ) {
F_11 ( & V_3 . V_12 ) ;
F_12 ( L_1 ) ;
return - V_8 ;
}
if ( V_3 . V_4 == 2 )
F_13 ( 0x01 , V_15 ) ;
else if ( V_3 . V_4 == 1 )
F_14 ( 0x01 , V_15 ) ;
V_11 = F_15 ( V_16 ) ;
V_11 &= 0xf7ff ;
F_13 ( V_11 , V_16 ) ;
V_11 = F_15 ( V_16 ) ;
F_11 ( & V_3 . V_12 ) ;
if ( V_11 & 0x0800 )
return - 1 ;
return 0 ;
}
static int F_16 ( struct V_9 * V_10 )
{
unsigned int V_11 ;
F_9 ( & V_3 . V_12 ) ;
F_17 ( V_3 . V_13 ) ;
V_11 = F_15 ( V_16 ) ;
V_11 |= 0x0800 ;
F_13 ( V_11 , V_16 ) ;
V_11 = F_15 ( V_16 ) ;
F_2 () ;
F_11 ( & V_3 . V_12 ) ;
if ( ( V_11 & 0x0800 ) == 0 )
return - 1 ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 )
{
F_9 ( & V_3 . V_12 ) ;
F_19 ( V_3 . V_13 , V_10 -> V_14 ) ;
if ( V_3 . V_4 == 2 )
F_13 ( 0x01 , V_15 ) ;
else if ( V_3 . V_4 == 1 ) {
F_13 ( 0x0008 , V_17 ) ;
F_14 ( 0x01 , V_15 ) ;
}
F_11 ( & V_3 . V_12 ) ;
return 0 ;
}
static int F_20 ( struct V_9 * V_10 , unsigned int V_18 )
{
unsigned int V_19 ;
unsigned char V_20 ;
unsigned int V_21 ;
V_21 = F_1 ( V_18 ) ;
if ( V_3 . V_4 == 1 )
V_21 /= 2 ;
if ( V_21 < 0x04 )
return - V_22 ;
if ( ( ( V_3 . V_4 == 2 ) && ( V_21 > 0x3ff ) ) ||
( ( V_3 . V_4 == 1 ) && ( V_21 > 0x03f ) ) )
return - V_22 ;
F_21 ( V_21 ) ;
if ( V_3 . V_4 == 2 ) {
F_9 ( & V_3 . V_12 ) ;
V_19 = F_15 ( V_23 ) ;
V_19 &= 0xfc00 ;
V_19 |= V_21 ;
F_13 ( V_19 , V_23 ) ;
V_19 = F_15 ( V_23 ) ;
F_11 ( & V_3 . V_12 ) ;
if ( ( V_19 & 0x3ff ) != V_21 )
return - V_22 ;
} else if ( V_3 . V_4 == 1 ) {
F_9 ( & V_3 . V_12 ) ;
V_20 = F_22 ( V_24 ) ;
V_20 &= 0xc0 ;
V_20 |= ( V_21 & 0xff ) ;
F_14 ( V_20 , V_24 ) ;
V_20 = F_22 ( V_24 ) ;
F_11 ( & V_3 . V_12 ) ;
if ( ( V_20 & 0x3f ) != V_21 )
return - V_22 ;
}
V_10 -> V_14 = V_18 ;
return 0 ;
}
static unsigned int F_23 ( struct V_9 * V_10 )
{
unsigned int V_19 ;
unsigned char V_20 ;
unsigned int V_25 = 0 ;
if ( V_3 . V_4 == 2 ) {
F_9 ( & V_3 . V_12 ) ;
V_19 = F_15 ( V_15 ) ;
V_19 &= 0x3ff ;
F_11 ( & V_3 . V_12 ) ;
V_25 = ( V_19 * 6 ) / 10 ;
} else if ( V_3 . V_4 == 1 ) {
F_9 ( & V_3 . V_12 ) ;
V_20 = F_22 ( V_15 ) ;
V_20 &= 0x3f ;
if ( ! ( F_15 ( V_17 ) & 0x0008 ) )
V_20 += ( F_22 ( V_24 ) & 0x3f ) ;
F_11 ( & V_3 . V_12 ) ;
V_25 = ( V_20 * 6 ) / 10 ;
}
return V_25 ;
}
static void F_24 ( void )
{
if ( ! V_26 )
F_16 ( & V_27 ) ;
F_25 ( & V_27 ) ;
F_26 ( V_3 . V_28 -> V_29 ,
F_27 ( V_3 . V_28 ) ) ;
F_26 ( V_3 . V_13 -> V_29 ,
F_27 ( V_3 . V_13 ) ) ;
if ( V_3 . V_4 == 2 ) {
F_28 ( V_3 . V_5 ) ;
F_29 ( V_3 . V_30 -> V_29 ,
F_27 ( V_3 . V_30 ) ) ;
}
V_3 . V_28 = NULL ;
V_3 . V_13 = NULL ;
V_3 . V_30 = NULL ;
V_3 . V_5 = NULL ;
}
static int F_30 ( struct V_31 * V_32 )
{
int V_7 = - V_33 ;
unsigned long V_2 ;
struct V_34 * V_35 = F_31 ( & V_32 -> V_32 ) ;
if ( ! V_35 )
goto V_36;
F_32 ( & V_3 . V_12 ) ;
V_3 . V_28 =
F_33 ( V_32 , V_37 , V_38 ) ;
if ( ! V_3 . V_28 )
goto V_36;
V_3 . V_13 =
F_33 ( V_32 , V_37 , V_39 ) ;
if ( ! V_3 . V_13 )
goto V_36;
V_3 . V_4 = V_35 -> V_4 ;
V_3 . V_32 = V_32 ;
V_3 . V_6 = F_34 ( V_32 -> V_32 . V_40 ) ;
if ( V_3 . V_4 == 2 ) {
V_3 . V_30 = F_33 ( V_32 ,
V_41 ,
V_42 ) ;
if ( ! V_3 . V_30 )
goto V_36;
if ( ! F_35 ( V_3 . V_30 -> V_29 ,
F_27 ( V_3 . V_30 ) , V_32 -> V_43 ) ) {
V_7 = - V_44 ;
goto V_36;
}
V_3 . V_5 = F_36 ( V_3 . V_30 -> V_29 ,
F_27 ( V_3 . V_30 ) ) ;
if ( ! V_3 . V_5 ) {
V_7 = - V_8 ;
goto V_45;
}
}
if ( F_7 () && F_37 () ) {
F_38 ( L_2 ) ;
V_7 = - V_33 ;
goto V_46;
}
F_2 () ;
if ( ! F_39 ( V_3 . V_13 -> V_29 ,
F_27 ( V_3 . V_13 ) , V_32 -> V_43 ) ) {
F_12 ( L_3 ,
( V_47 ) V_48 ) ;
V_7 = - V_44 ;
goto V_46;
}
if ( V_49 >= V_3 . V_4 ) {
V_2 = F_40 ( V_48 ) ;
V_2 &= 0xffffdfff ;
F_41 ( V_2 , V_48 ) ;
}
if ( ! F_39 ( V_3 . V_28 -> V_29 ,
F_27 ( V_3 . V_28 ) , V_32 -> V_43 ) ) {
F_12 ( L_3 ,
( V_47 ) V_50 ) ;
V_7 = - V_44 ;
goto V_51;
}
F_38 ( L_4 ,
V_35 -> V_43 , V_35 -> V_4 , ( V_47 ) V_50 ) ;
F_13 ( 0x0008 , V_17 ) ;
F_13 ( 0x0002 , V_52 ) ;
F_13 ( 0x0004 , V_52 ) ;
V_27 . V_53 = 0 ;
V_27 . V_14 = V_54 ;
F_42 ( & V_27 , V_26 ) ;
V_27 . V_40 = V_32 -> V_32 . V_40 ;
F_16 ( & V_27 ) ;
if ( F_20 ( & V_27 , V_55 ) ) {
F_20 ( & V_27 , V_54 ) ;
F_38 ( L_5 ,
V_54 ) ;
}
V_7 = F_43 ( & V_27 ) ;
if ( V_7 != 0 ) {
F_12 ( L_6 , V_7 ) ;
goto V_56;
}
F_38 ( L_7 ,
V_55 , V_26 ) ;
return 0 ;
V_56:
F_26 ( V_3 . V_28 -> V_29 ,
F_27 ( V_3 . V_28 ) ) ;
V_51:
F_26 ( V_3 . V_13 -> V_29 ,
F_27 ( V_3 . V_13 ) ) ;
V_46:
if ( V_3 . V_4 == 2 )
F_28 ( V_3 . V_5 ) ;
V_45:
if ( V_3 . V_4 == 2 )
F_29 ( V_3 . V_30 -> V_29 ,
F_27 ( V_3 . V_30 ) ) ;
V_36:
V_3 . V_28 = NULL ;
V_3 . V_13 = NULL ;
V_3 . V_30 = NULL ;
V_3 . V_5 = NULL ;
return V_7 ;
}
static int F_44 ( struct V_31 * V_32 )
{
if ( V_3 . V_28 || V_3 . V_13 )
F_24 () ;
return 0 ;
}
static void F_45 ( struct V_31 * V_32 )
{
F_16 ( NULL ) ;
}
static int T_2 F_46 ( void )
{
int V_57 ;
F_38 ( L_8 , V_58 ) ;
V_57 = F_47 ( & V_59 ) ;
if ( V_57 )
return V_57 ;
return 0 ;
}
static void T_3 F_48 ( void )
{
F_49 ( & V_59 ) ;
F_38 ( L_9 ) ;
}
