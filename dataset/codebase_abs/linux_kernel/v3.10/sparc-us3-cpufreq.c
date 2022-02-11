static unsigned long F_1 ( void )
{
unsigned long V_1 ;
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=&r" (ret)
: "i" (ASI_SAFARI_CONFIG));
return V_1 ;
}
static void F_2 ( unsigned long V_2 )
{
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (val), "i" (ASI_SAFARI_CONFIG)
: "memory");
}
static unsigned long F_3 ( unsigned int V_3 , unsigned long V_4 )
{
unsigned long V_5 = F_4 ( V_3 ) / 1000 ;
unsigned long V_1 ;
switch ( V_4 & V_6 ) {
case V_7 :
V_1 = V_5 / 1 ;
break;
case V_8 :
V_1 = V_5 / 2 ;
break;
case V_9 :
V_1 = V_5 / 32 ;
break;
default:
F_5 () ;
}
return V_1 ;
}
static unsigned int F_6 ( unsigned int V_3 )
{
T_1 V_10 ;
unsigned long V_11 ;
unsigned int V_1 ;
F_7 ( & V_10 , F_8 ( V_12 ) ) ;
F_9 ( V_12 , F_10 ( V_3 ) ) ;
V_11 = F_1 () ;
V_1 = F_3 ( V_3 , V_11 ) ;
F_9 ( V_12 , & V_10 ) ;
return V_1 ;
}
static void F_11 ( struct V_13 * V_14 ,
unsigned int V_15 )
{
unsigned int V_3 = V_14 -> V_3 ;
unsigned long V_16 , V_17 , V_11 ;
T_1 V_10 ;
struct V_18 V_19 ;
F_7 ( & V_10 , F_8 ( V_12 ) ) ;
F_9 ( V_12 , F_10 ( V_3 ) ) ;
V_17 = F_4 ( V_3 ) / 1000 ;
switch ( V_15 ) {
case 0 :
V_16 = V_7 ;
V_17 /= 1 ;
break;
case 1 :
V_16 = V_8 ;
V_17 /= 2 ;
break;
case 2 :
V_16 = V_9 ;
V_17 /= 32 ;
break;
default:
F_5 () ;
}
V_11 = F_1 () ;
V_19 . V_20 = F_3 ( V_3 , V_11 ) ;
V_19 . V_21 = V_17 ;
F_12 ( V_14 , & V_19 , V_22 ) ;
V_11 &= ~ V_6 ;
V_11 |= V_16 ;
F_2 ( V_11 ) ;
F_12 ( V_14 , & V_19 , V_23 ) ;
F_9 ( V_12 , & V_10 ) ;
}
static int F_13 ( struct V_13 * V_14 ,
unsigned int V_24 ,
unsigned int V_25 )
{
unsigned int V_26 = 0 ;
if ( F_14 ( V_14 ,
& V_27 [ V_14 -> V_3 ] . V_28 [ 0 ] ,
V_24 ,
V_25 ,
& V_26 ) )
return - V_29 ;
F_11 ( V_14 , V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 )
{
return F_16 ( V_14 ,
& V_27 [ V_14 -> V_3 ] . V_28 [ 0 ] ) ;
}
static int T_2 F_17 ( struct V_13 * V_14 )
{
unsigned int V_3 = V_14 -> V_3 ;
unsigned long V_5 = F_4 ( V_3 ) / 1000 ;
struct V_30 * V_28 =
& V_27 [ V_3 ] . V_28 [ 0 ] ;
V_28 [ 0 ] . V_15 = 0 ;
V_28 [ 0 ] . V_31 = V_5 / 1 ;
V_28 [ 1 ] . V_15 = 1 ;
V_28 [ 1 ] . V_31 = V_5 / 2 ;
V_28 [ 2 ] . V_15 = 2 ;
V_28 [ 2 ] . V_31 = V_5 / 32 ;
V_28 [ 3 ] . V_15 = 0 ;
V_28 [ 3 ] . V_31 = V_32 ;
V_14 -> V_33 . V_34 = 0 ;
V_14 -> V_35 = V_5 ;
return F_18 ( V_14 , V_28 ) ;
}
static int F_19 ( struct V_13 * V_14 )
{
if ( V_36 )
F_11 ( V_14 , 0 ) ;
return 0 ;
}
static int T_2 F_20 ( void )
{
unsigned long V_37 , V_38 , V_39 ;
int V_1 ;
if ( V_40 != V_41 && V_40 != V_42 )
return - V_43 ;
__asm__("rdpr %%ver, %0" : "=r" (ver));
V_37 = ( ( V_39 >> 48 ) & 0xffff ) ;
V_38 = ( ( V_39 >> 32 ) & 0xffff ) ;
if ( V_37 == V_44 &&
( V_38 == V_45 ||
V_38 == V_46 ||
V_38 == V_47 ||
V_38 == V_48 ) ) {
struct V_49 * V_50 ;
V_1 = - V_51 ;
V_50 = F_21 ( sizeof( struct V_49 ) , V_52 ) ;
if ( ! V_50 )
goto V_53;
V_27 = F_21 (
( V_54 * sizeof( struct V_55 ) ) ,
V_52 ) ;
if ( ! V_27 )
goto V_53;
V_50 -> V_56 = F_17 ;
V_50 -> V_57 = F_15 ;
V_50 -> V_58 = F_13 ;
V_50 -> V_59 = F_6 ;
V_50 -> exit = F_19 ;
V_50 -> V_60 = V_61 ,
strcpy ( V_50 -> V_62 , L_1 ) ;
V_36 = V_50 ;
V_1 = F_22 ( V_50 ) ;
if ( V_1 )
goto V_53;
return 0 ;
V_53:
if ( V_50 ) {
F_23 ( V_50 ) ;
V_36 = NULL ;
}
F_23 ( V_27 ) ;
V_27 = NULL ;
return V_1 ;
}
return - V_43 ;
}
static void T_3 F_24 ( void )
{
if ( V_36 ) {
F_25 ( V_36 ) ;
F_23 ( V_36 ) ;
V_36 = NULL ;
F_23 ( V_27 ) ;
V_27 = NULL ;
}
}
