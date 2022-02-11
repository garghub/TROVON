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
static int F_11 ( struct V_13 * V_14 , unsigned int V_15 )
{
unsigned int V_3 = V_14 -> V_3 ;
unsigned long V_16 , V_17 , V_11 ;
T_1 V_10 ;
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
V_11 &= ~ V_6 ;
V_11 |= V_16 ;
F_2 ( V_11 ) ;
F_9 ( V_12 , & V_10 ) ;
return 0 ;
}
static int T_2 F_12 ( struct V_13 * V_14 )
{
unsigned int V_3 = V_14 -> V_3 ;
unsigned long V_5 = F_4 ( V_3 ) / 1000 ;
struct V_18 * V_19 =
& V_20 [ V_3 ] . V_19 [ 0 ] ;
V_19 [ 0 ] . V_21 = 0 ;
V_19 [ 0 ] . V_22 = V_5 / 1 ;
V_19 [ 1 ] . V_21 = 1 ;
V_19 [ 1 ] . V_22 = V_5 / 2 ;
V_19 [ 2 ] . V_21 = 2 ;
V_19 [ 2 ] . V_22 = V_5 / 32 ;
V_19 [ 3 ] . V_21 = 0 ;
V_19 [ 3 ] . V_22 = V_23 ;
V_14 -> V_24 . V_25 = 0 ;
V_14 -> V_26 = V_5 ;
return F_13 ( V_14 , V_19 ) ;
}
static int F_14 ( struct V_13 * V_14 )
{
if ( V_27 )
F_11 ( V_14 , 0 ) ;
return 0 ;
}
static int T_2 F_15 ( void )
{
unsigned long V_28 , V_29 , V_30 ;
int V_1 ;
if ( V_31 != V_32 && V_31 != V_33 )
return - V_34 ;
__asm__("rdpr %%ver, %0" : "=r" (ver));
V_28 = ( ( V_30 >> 48 ) & 0xffff ) ;
V_29 = ( ( V_30 >> 32 ) & 0xffff ) ;
if ( V_28 == V_35 &&
( V_29 == V_36 ||
V_29 == V_37 ||
V_29 == V_38 ||
V_29 == V_39 ) ) {
struct V_40 * V_41 ;
V_1 = - V_42 ;
V_41 = F_16 ( sizeof( * V_41 ) , V_43 ) ;
if ( ! V_41 )
goto V_44;
V_20 = F_16 ( ( V_45 * sizeof( * V_20 ) ) ,
V_43 ) ;
if ( ! V_20 )
goto V_44;
V_41 -> V_46 = F_12 ;
V_41 -> V_47 = V_48 ;
V_41 -> V_49 = F_11 ;
V_41 -> V_50 = F_6 ;
V_41 -> exit = F_14 ;
strcpy ( V_41 -> V_51 , L_1 ) ;
V_27 = V_41 ;
V_1 = F_17 ( V_41 ) ;
if ( V_1 )
goto V_44;
return 0 ;
V_44:
if ( V_41 ) {
F_18 ( V_41 ) ;
V_27 = NULL ;
}
F_18 ( V_20 ) ;
V_20 = NULL ;
return V_1 ;
}
return - V_34 ;
}
static void T_3 F_19 ( void )
{
if ( V_27 ) {
F_20 ( V_27 ) ;
F_18 ( V_27 ) ;
V_27 = NULL ;
F_18 ( V_20 ) ;
V_20 = NULL ;
}
}
