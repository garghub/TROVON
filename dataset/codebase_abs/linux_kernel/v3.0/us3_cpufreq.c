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
if ( ! F_7 ( V_3 ) )
return 0 ;
F_8 ( & V_10 , F_9 ( V_12 ) ) ;
F_10 ( V_12 , F_11 ( V_3 ) ) ;
V_11 = F_1 () ;
V_1 = F_3 ( V_3 , V_11 ) ;
F_10 ( V_12 , & V_10 ) ;
return V_1 ;
}
static void F_12 ( unsigned int V_3 , unsigned int V_13 )
{
unsigned long V_14 , V_15 , V_11 ;
T_1 V_10 ;
struct V_16 V_17 ;
if ( ! F_7 ( V_3 ) )
return;
F_8 ( & V_10 , F_9 ( V_12 ) ) ;
F_10 ( V_12 , F_11 ( V_3 ) ) ;
V_15 = F_4 ( V_3 ) / 1000 ;
switch ( V_13 ) {
case 0 :
V_14 = V_7 ;
V_15 /= 1 ;
break;
case 1 :
V_14 = V_8 ;
V_15 /= 2 ;
break;
case 2 :
V_14 = V_9 ;
V_15 /= 32 ;
break;
default:
F_5 () ;
}
V_11 = F_1 () ;
V_17 . V_18 = F_3 ( V_3 , V_11 ) ;
V_17 . V_19 = V_15 ;
V_17 . V_3 = V_3 ;
F_13 ( & V_17 , V_20 ) ;
V_11 &= ~ V_6 ;
V_11 |= V_14 ;
F_2 ( V_11 ) ;
F_13 ( & V_17 , V_21 ) ;
F_10 ( V_12 , & V_10 ) ;
}
static int F_14 ( struct V_22 * V_23 ,
unsigned int V_24 ,
unsigned int V_25 )
{
unsigned int V_26 = 0 ;
if ( F_15 ( V_23 ,
& V_27 [ V_23 -> V_3 ] . V_28 [ 0 ] ,
V_24 ,
V_25 ,
& V_26 ) )
return - V_29 ;
F_12 ( V_23 -> V_3 , V_26 ) ;
return 0 ;
}
static int F_16 ( struct V_22 * V_23 )
{
return F_17 ( V_23 ,
& V_27 [ V_23 -> V_3 ] . V_28 [ 0 ] ) ;
}
static int T_2 F_18 ( struct V_22 * V_23 )
{
unsigned int V_3 = V_23 -> V_3 ;
unsigned long V_5 = F_4 ( V_3 ) / 1000 ;
struct V_30 * V_28 =
& V_27 [ V_3 ] . V_28 [ 0 ] ;
V_28 [ 0 ] . V_13 = 0 ;
V_28 [ 0 ] . V_31 = V_5 / 1 ;
V_28 [ 1 ] . V_13 = 1 ;
V_28 [ 1 ] . V_31 = V_5 / 2 ;
V_28 [ 2 ] . V_13 = 2 ;
V_28 [ 2 ] . V_31 = V_5 / 32 ;
V_28 [ 3 ] . V_13 = 0 ;
V_28 [ 3 ] . V_31 = V_32 ;
V_23 -> V_33 . V_34 = 0 ;
V_23 -> V_35 = V_5 ;
return F_19 ( V_23 , V_28 ) ;
}
static int F_20 ( struct V_22 * V_23 )
{
if ( V_36 )
F_12 ( V_23 -> V_3 , 0 ) ;
return 0 ;
}
static int T_2 F_21 ( void )
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
V_50 = F_22 ( sizeof( struct V_49 ) , V_52 ) ;
if ( ! V_50 )
goto V_53;
V_27 = F_22 (
( V_54 * sizeof( struct V_55 ) ) ,
V_52 ) ;
if ( ! V_27 )
goto V_53;
V_50 -> V_56 = F_18 ;
V_50 -> V_57 = F_16 ;
V_50 -> V_58 = F_14 ;
V_50 -> V_59 = F_6 ;
V_50 -> exit = F_20 ;
V_50 -> V_60 = V_61 ,
strcpy ( V_50 -> V_62 , L_1 ) ;
V_36 = V_50 ;
V_1 = F_23 ( V_50 ) ;
if ( V_1 )
goto V_53;
return 0 ;
V_53:
if ( V_50 ) {
F_24 ( V_50 ) ;
V_36 = NULL ;
}
F_24 ( V_27 ) ;
V_27 = NULL ;
return V_1 ;
}
return - V_43 ;
}
static void T_3 F_25 ( void )
{
if ( V_36 ) {
F_26 ( V_36 ) ;
F_24 ( V_36 ) ;
V_36 = NULL ;
F_24 ( V_27 ) ;
V_27 = NULL ;
}
}
