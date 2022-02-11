static unsigned int F_1 ( T_1 * V_1 , T_2 V_2 )
{
struct V_3 * V_4 = F_2 ( V_5 + V_2 ) ;
unsigned int V_6 , V_7 ;
T_2 V_8 = 0 ;
V_6 = ( V_4 -> V_9 + 29 ) / 30 ;
V_7 = ( F_3 ( V_1 , V_2 ) - 30 * V_6 + 29 ) / 30 ;
if ( V_6 == 0 )
V_6 = 1 ;
if ( V_7 == 0 )
V_7 = 1 ;
if ( F_4 ( V_1 , V_2 ) )
V_8 = 0x40 ;
return ( V_6 - 1 ) << 8 | ( V_7 - 1 ) | V_8 ;
}
static void F_5 ( T_3 * V_10 , T_1 * V_1 )
{
struct V_11 * V_12 = F_6 ( V_10 -> V_12 ) ;
unsigned long V_13 = ( unsigned long ) F_7 ( V_1 ) ;
int V_14 = 0x44 + V_1 -> V_15 * 4 ;
T_4 V_16 ;
const T_2 V_2 = V_1 -> V_17 - V_5 ;
V_16 = F_1 ( V_1 , V_2 ) ;
V_13 &= 0xffff0000 ;
V_13 |= V_16 ;
F_8 ( V_1 , ( void * ) V_13 ) ;
F_9 ( V_12 , V_14 , V_16 ) ;
F_10 ( V_12 , V_14 , & V_16 ) ;
F_11 ( V_18 L_1 , V_1 -> V_19 ,
F_12 ( V_2 + V_5 ) ,
F_3 ( V_1 , V_2 ) , V_16 ) ;
}
static void F_13 ( T_3 * V_10 , T_1 * V_1 )
{
static T_4 V_20 [] = { 0x0707 , 0x0201 , 0x0200 } ;
unsigned long V_13 = ( unsigned long ) F_7 ( V_1 ) ;
T_4 V_16 ;
const T_2 V_21 = V_1 -> V_22 ;
V_16 = V_20 [ V_21 - V_23 ] ;
V_13 &= 0x0000ffff ;
V_13 |= ( unsigned long ) V_16 << 16 ;
F_8 ( V_1 , ( void * ) V_13 ) ;
}
static int F_14 ( T_3 * V_10 )
{
struct V_11 * V_12 = F_6 ( V_10 -> V_12 ) ;
T_5 V_24 , V_25 = V_10 -> V_26 ? V_27 : V_28 ;
F_15 ( V_12 , 0x40 , & V_24 ) ;
return ( V_24 & V_25 ) ? 1 : 0 ;
}
static inline void F_16 ( struct V_11 * V_12 )
{
T_4 V_24 ;
F_10 ( V_12 , 0x7e , & V_24 ) ;
F_9 ( V_12 , 0x7e , V_24 | ( 1 << 2 ) ) ;
F_9 ( V_12 , 0x7e , V_24 & ~ ( 1 << 2 ) ) ;
}
static void F_17 ( T_1 * V_1 )
{
T_3 * V_10 = V_1 -> V_10 ;
struct V_11 * V_12 = F_6 ( V_10 -> V_12 ) ;
T_5 V_24 , V_25 = V_10 -> V_26 ? V_27 : V_28 ;
T_2 V_29 ;
F_11 ( V_30 L_2 ) ;
F_15 ( V_12 , 0x40 , & V_24 ) ;
if ( V_24 & V_25 )
F_11 ( V_31 L_3
L_4 ) ;
V_29 = F_18 ( V_10 -> V_32 + V_33 ) ;
if ( V_29 & 1 ) {
F_19 ( V_29 & ~ 1 , V_10 -> V_32 + V_33 ) ;
F_11 ( V_31 L_5 ) ;
}
F_16 ( V_12 ) ;
}
static void F_20 ( T_1 * V_1 )
{
T_3 * V_10 = V_1 -> V_10 ;
struct V_11 * V_12 = F_6 ( V_10 -> V_12 ) ;
int V_14 = 0x44 + V_1 -> V_15 * 4 ;
F_9 ( V_12 , V_14 ,
( unsigned long ) F_7 ( V_1 ) >> 16 ) ;
F_16 ( V_12 ) ;
F_21 ( V_1 ) ;
}
static void F_22 ( T_1 * V_1 )
{
struct V_11 * V_12 = F_6 ( V_1 -> V_10 -> V_12 ) ;
F_16 ( V_12 ) ;
}
static int F_23 ( T_1 * V_1 )
{
struct V_11 * V_12 = F_6 ( V_1 -> V_10 -> V_12 ) ;
int V_14 = 0x44 + V_1 -> V_15 * 4 ;
int V_34 = F_24 ( V_1 ) ;
F_9 ( V_12 , V_14 ,
( unsigned long ) F_7 ( V_1 ) ) ;
return V_34 ;
}
static void F_25 ( T_1 * V_1 )
{
struct V_11 * V_12 = F_6 ( V_1 -> V_10 -> V_12 ) ;
T_5 V_24 ;
F_15 ( V_12 , 0x40 , & V_24 ) ;
V_24 |= ( V_35 | V_36 ) ;
F_26 ( V_12 , 0x40 , V_24 ) ;
}
static T_2 F_27 ( struct V_11 * V_12 )
{
struct V_11 * V_37 ;
V_37 = F_28 ( V_12 -> V_38 -> V_39 ,
F_29 ( F_30 ( V_12 -> V_40 ) , 0 ) ) ;
if ( ! V_37 )
return - 1 ;
if ( V_37 -> V_41 != V_42 ||
V_37 -> V_43 != V_44 ||
V_37 -> V_45 >> 8 != V_46 ) {
F_31 ( V_37 ) ;
return - 1 ;
}
F_31 ( V_37 ) ;
return V_37 -> V_47 ;
}
static int F_32 ( struct V_11 * V_12 )
{
T_5 V_24 ;
F_15 ( V_12 , 0x40 , & V_24 ) ;
V_24 |= V_48 | V_36 | V_35 ;
F_26 ( V_12 , 0x40 , V_24 ) ;
return 0 ;
}
static int F_33 ( struct V_11 * V_12 , const struct V_49 * V_50 )
{
struct V_51 V_52 = V_53 ;
T_2 V_54 = F_27 ( V_12 ) ;
if ( V_54 <= 5 ) {
F_11 (KERN_INFO DRV_NAME L_6
L_7 , rev) ;
V_52 . V_55 = NULL ;
V_52 . V_56 = 0 ;
V_52 . V_57 &= ~ V_58 ;
}
return F_34 ( V_12 , & V_52 , NULL ) ;
}
static int T_6 F_35 ( void )
{
return F_36 ( & V_59 ) ;
}
static void T_7 F_37 ( void )
{
F_38 ( & V_59 ) ;
}
