static inline unsigned int F_1 ( int V_1 )
{
return V_2 . V_3 == 3 ? V_1 : ( V_1 * 10 ) / 6 ;
}
static inline unsigned int F_2 ( int V_4 )
{
return V_2 . V_3 == 3 ? V_4 : ( V_4 * 6 ) / 10 ;
}
static void F_3 ( void )
{
T_1 V_5 ;
if ( V_2 . V_3 == 3 ) {
V_5 = F_4 ( V_2 . V_6 ) ;
V_5 |= 0x00000010 ;
F_5 ( V_5 , V_2 . V_6 ) ;
} else if ( V_2 . V_3 == 2 ) {
V_5 = F_4 ( V_2 . V_6 ) ;
V_5 |= 0x00000020 ;
F_5 ( V_5 , V_2 . V_6 ) ;
} else if ( V_2 . V_3 == 1 ) {
F_6 ( V_2 . V_7 , 0xd4 , & V_5 ) ;
V_5 |= 0x00000002 ;
F_7 ( V_2 . V_7 , 0xd4 , V_5 ) ;
}
}
static int F_8 ( void )
{
int V_8 = 0 ;
T_1 V_5 ;
if ( V_2 . V_3 == 3 ) {
V_5 = F_4 ( V_2 . V_6 ) ;
V_5 &= 0xffffffef ;
F_5 ( V_5 , V_2 . V_6 ) ;
V_5 = F_4 ( V_2 . V_6 ) ;
if ( V_5 & 0x00000010 )
V_8 = - V_9 ;
} else if ( V_2 . V_3 == 2 ) {
V_5 = F_4 ( V_2 . V_6 ) ;
V_5 &= 0xffffffdf ;
F_5 ( V_5 , V_2 . V_6 ) ;
V_5 = F_4 ( V_2 . V_6 ) ;
if ( V_5 & 0x00000020 )
V_8 = - V_9 ;
} else if ( V_2 . V_3 == 1 ) {
F_6 ( V_2 . V_7 , 0xd4 , & V_5 ) ;
V_5 &= 0xfffffffd ;
F_7 ( V_2 . V_7 , 0xd4 , V_5 ) ;
F_6 ( V_2 . V_7 , 0xd4 , & V_5 ) ;
if ( V_5 & 0x00000002 )
V_8 = - V_9 ;
}
return V_8 ;
}
static int F_9 ( struct V_10 * V_11 )
{
unsigned int V_12 ;
F_10 ( & V_2 . V_13 ) ;
F_11 ( V_2 . V_14 , V_11 -> V_15 ) ;
if ( F_8 () ) {
F_12 ( & V_2 . V_13 ) ;
F_13 ( L_1 ) ;
return - V_9 ;
}
if ( V_2 . V_3 >= 2 )
F_14 ( 0x01 , V_16 ) ;
else if ( V_2 . V_3 == 1 )
F_15 ( 0x01 , V_16 ) ;
V_12 = F_16 ( V_17 ) ;
V_12 &= 0xf7ff ;
F_14 ( V_12 , V_17 ) ;
V_12 = F_16 ( V_17 ) ;
F_12 ( & V_2 . V_13 ) ;
if ( V_12 & 0x0800 )
return - 1 ;
return 0 ;
}
static int F_17 ( struct V_10 * V_11 )
{
unsigned int V_12 ;
F_10 ( & V_2 . V_13 ) ;
F_18 ( V_2 . V_14 ) ;
V_12 = F_16 ( V_17 ) ;
V_12 |= 0x0800 ;
F_14 ( V_12 , V_17 ) ;
V_12 = F_16 ( V_17 ) ;
F_3 () ;
F_12 ( & V_2 . V_13 ) ;
if ( ( V_12 & 0x0800 ) == 0 )
return - 1 ;
return 0 ;
}
static int F_19 ( struct V_10 * V_11 )
{
F_10 ( & V_2 . V_13 ) ;
F_20 ( V_2 . V_14 , V_11 -> V_15 ) ;
if ( V_2 . V_3 >= 2 ) {
F_14 ( 0x01 , V_16 ) ;
} else if ( V_2 . V_3 == 1 ) {
F_14 ( 0x0008 , V_18 ) ;
F_15 ( 0x01 , V_16 ) ;
}
F_12 ( & V_2 . V_13 ) ;
return 0 ;
}
static int F_21 ( struct V_10 * V_11 , unsigned int V_19 )
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
F_22 ( V_22 ) ;
if ( V_2 . V_3 >= 2 ) {
F_10 ( & V_2 . V_13 ) ;
V_20 = F_16 ( V_24 ) ;
V_20 &= 0xfc00 ;
V_20 |= V_22 ;
F_14 ( V_20 , V_24 ) ;
V_20 = F_16 ( V_24 ) ;
F_12 ( & V_2 . V_13 ) ;
if ( ( V_20 & 0x3ff ) != V_22 )
return - V_23 ;
} else if ( V_2 . V_3 == 1 ) {
F_10 ( & V_2 . V_13 ) ;
V_21 = F_23 ( V_25 ) ;
V_21 &= 0xc0 ;
V_21 |= ( V_22 & 0xff ) ;
F_15 ( V_21 , V_25 ) ;
V_21 = F_23 ( V_25 ) ;
F_12 ( & V_2 . V_13 ) ;
if ( ( V_21 & 0x3f ) != V_22 )
return - V_23 ;
}
V_11 -> V_15 = V_19 ;
return 0 ;
}
static unsigned int F_24 ( struct V_10 * V_11 )
{
unsigned int V_20 ;
unsigned char V_21 ;
unsigned int V_26 = 0 ;
if ( V_2 . V_3 >= 2 ) {
F_10 ( & V_2 . V_13 ) ;
V_20 = F_16 ( V_16 ) ;
V_20 &= 0x3ff ;
F_12 ( & V_2 . V_13 ) ;
V_26 = F_2 ( V_20 ) ;
} else if ( V_2 . V_3 == 1 ) {
F_10 ( & V_2 . V_13 ) ;
V_21 = F_23 ( V_16 ) ;
V_21 &= 0x3f ;
if ( ! ( F_16 ( V_18 ) & 0x0008 ) )
V_21 += ( F_23 ( V_25 ) & 0x3f ) ;
F_12 ( & V_2 . V_13 ) ;
V_26 = F_2 ( V_21 ) ;
}
return V_26 ;
}
static void F_25 ( void )
{
if ( ! V_27 )
F_17 ( & V_28 ) ;
F_26 ( & V_28 ) ;
F_27 ( V_2 . V_29 -> V_30 ,
F_28 ( V_2 . V_29 ) ) ;
F_27 ( V_2 . V_14 -> V_30 ,
F_28 ( V_2 . V_14 ) ) ;
if ( V_2 . V_3 >= 2 ) {
F_29 ( V_2 . V_6 ) ;
F_30 ( V_2 . V_31 -> V_30 ,
F_28 ( V_2 . V_31 ) ) ;
}
V_2 . V_29 = NULL ;
V_2 . V_14 = NULL ;
V_2 . V_31 = NULL ;
V_2 . V_6 = NULL ;
}
static int F_31 ( struct V_32 * V_33 )
{
int V_8 = - V_34 ;
unsigned long V_5 ;
struct V_35 * V_36 = F_32 ( & V_33 -> V_33 ) ;
if ( ! V_36 )
goto V_37;
F_33 ( & V_2 . V_13 ) ;
V_2 . V_29 =
F_34 ( V_33 , V_38 , V_39 ) ;
if ( ! V_2 . V_29 )
goto V_37;
V_2 . V_14 =
F_34 ( V_33 , V_38 , V_40 ) ;
if ( ! V_2 . V_14 )
goto V_37;
V_2 . V_3 = V_36 -> V_3 ;
V_2 . V_33 = V_33 ;
V_2 . V_7 = F_35 ( V_33 -> V_33 . V_41 ) ;
if ( V_2 . V_3 >= 2 ) {
V_2 . V_31 = F_34 ( V_33 ,
V_42 ,
V_43 ) ;
if ( ! V_2 . V_31 )
goto V_37;
if ( ! F_36 ( V_2 . V_31 -> V_30 ,
F_28 ( V_2 . V_31 ) , V_33 -> V_44 ) ) {
V_8 = - V_45 ;
goto V_37;
}
V_2 . V_6 = F_37 ( V_2 . V_31 -> V_30 ,
F_28 ( V_2 . V_31 ) ) ;
if ( ! V_2 . V_6 ) {
V_8 = - V_9 ;
goto V_46;
}
}
if ( F_8 () && F_38 () ) {
F_39 ( L_2 ) ;
V_8 = - V_34 ;
goto V_47;
}
F_3 () ;
if ( ! F_40 ( V_2 . V_14 -> V_30 ,
F_28 ( V_2 . V_14 ) , V_33 -> V_44 ) ) {
F_13 ( L_3 ,
( V_48 ) V_49 ) ;
V_8 = - V_45 ;
goto V_47;
}
if ( V_50 >= V_2 . V_3 ) {
V_5 = F_41 ( V_49 ) ;
V_5 &= 0xffffdfff ;
F_42 ( V_5 , V_49 ) ;
}
if ( ! F_40 ( V_2 . V_29 -> V_30 ,
F_28 ( V_2 . V_29 ) , V_33 -> V_44 ) ) {
F_13 ( L_3 ,
( V_48 ) V_51 ) ;
V_8 = - V_45 ;
goto V_52;
}
F_39 ( L_4 ,
V_36 -> V_44 , V_36 -> V_3 , ( V_48 ) V_51 ) ;
if ( V_2 . V_3 == 3 ) {
F_42 ( 0x20008 , V_18 ) ;
} else {
F_14 ( 0x0008 , V_18 ) ;
F_14 ( 0x0002 , V_53 ) ;
F_14 ( 0x0004 , V_53 ) ;
}
V_28 . V_54 = 0 ;
V_28 . V_15 = V_55 ;
F_43 ( & V_28 , V_27 ) ;
V_28 . V_41 = & V_33 -> V_33 ;
F_17 ( & V_28 ) ;
if ( F_21 ( & V_28 , V_56 ) ) {
F_21 ( & V_28 , V_55 ) ;
F_39 ( L_5 ,
V_55 ) ;
}
V_8 = F_44 ( & V_28 ) ;
if ( V_8 != 0 ) {
F_13 ( L_6 , V_8 ) ;
goto V_57;
}
F_39 ( L_7 ,
V_56 , V_27 ) ;
return 0 ;
V_57:
F_27 ( V_2 . V_29 -> V_30 ,
F_28 ( V_2 . V_29 ) ) ;
V_52:
F_27 ( V_2 . V_14 -> V_30 ,
F_28 ( V_2 . V_14 ) ) ;
V_47:
if ( V_2 . V_3 >= 2 )
F_29 ( V_2 . V_6 ) ;
V_46:
if ( V_2 . V_3 >= 2 )
F_30 ( V_2 . V_31 -> V_30 ,
F_28 ( V_2 . V_31 ) ) ;
V_37:
V_2 . V_29 = NULL ;
V_2 . V_14 = NULL ;
V_2 . V_31 = NULL ;
V_2 . V_6 = NULL ;
return V_8 ;
}
static int F_45 ( struct V_32 * V_33 )
{
if ( V_2 . V_29 || V_2 . V_14 )
F_25 () ;
return 0 ;
}
static void F_46 ( struct V_32 * V_33 )
{
F_17 ( NULL ) ;
}
static int T_2 F_47 ( void )
{
int V_58 ;
F_39 ( L_8 , V_59 ) ;
V_58 = F_48 ( & V_60 ) ;
if ( V_58 )
return V_58 ;
return 0 ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_60 ) ;
F_39 ( L_9 ) ;
}
