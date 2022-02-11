static void F_1 ( void * V_1 )
{
unsigned long V_2 , * V_3 = V_1 ;
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=&r" (ret)
: "i" (ASI_SAFARI_CONFIG));
* V_3 = V_2 ;
}
static void F_2 ( void * V_1 )
{
unsigned long V_4 , * V_5 = V_1 ;
F_1 ( & V_4 ) ;
V_4 &= ~ V_6 ;
V_4 |= * V_5 ;
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (reg), "i" (ASI_SAFARI_CONFIG)
: "memory");
}
static unsigned long F_3 ( unsigned int V_7 , unsigned long V_8 )
{
unsigned long V_9 = F_4 ( V_7 ) / 1000 ;
unsigned long V_2 ;
switch ( V_8 & V_6 ) {
case V_10 :
V_2 = V_9 / 1 ;
break;
case V_11 :
V_2 = V_9 / 2 ;
break;
case V_12 :
V_2 = V_9 / 32 ;
break;
default:
F_5 () ;
}
return V_2 ;
}
static unsigned int F_6 ( unsigned int V_7 )
{
unsigned long V_4 ;
if ( F_7 ( V_7 , F_1 , & V_4 , 1 ) )
return 0 ;
return F_3 ( V_7 , V_4 ) ;
}
static int F_8 ( struct V_13 * V_14 , unsigned int V_15 )
{
unsigned int V_7 = V_14 -> V_7 ;
unsigned long V_5 , V_16 ;
V_16 = F_4 ( V_7 ) / 1000 ;
switch ( V_15 ) {
case 0 :
V_5 = V_10 ;
V_16 /= 1 ;
break;
case 1 :
V_5 = V_11 ;
V_16 /= 2 ;
break;
case 2 :
V_5 = V_12 ;
V_16 /= 32 ;
break;
default:
F_5 () ;
}
return F_7 ( V_7 , F_2 , & V_5 , 1 ) ;
}
static int T_1 F_9 ( struct V_13 * V_14 )
{
unsigned int V_7 = V_14 -> V_7 ;
unsigned long V_9 = F_4 ( V_7 ) / 1000 ;
struct V_17 * V_18 =
& V_19 [ V_7 ] . V_18 [ 0 ] ;
V_18 [ 0 ] . V_20 = 0 ;
V_18 [ 0 ] . V_21 = V_9 / 1 ;
V_18 [ 1 ] . V_20 = 1 ;
V_18 [ 1 ] . V_21 = V_9 / 2 ;
V_18 [ 2 ] . V_20 = 2 ;
V_18 [ 2 ] . V_21 = V_9 / 32 ;
V_18 [ 3 ] . V_20 = 0 ;
V_18 [ 3 ] . V_21 = V_22 ;
V_14 -> V_23 . V_24 = 0 ;
V_14 -> V_25 = V_9 ;
return F_10 ( V_14 , V_18 ) ;
}
static int F_11 ( struct V_13 * V_14 )
{
if ( V_26 )
F_8 ( V_14 , 0 ) ;
return 0 ;
}
static int T_1 F_12 ( void )
{
unsigned long V_27 , V_28 , V_29 ;
int V_2 ;
if ( V_30 != V_31 && V_30 != V_32 )
return - V_33 ;
__asm__("rdpr %%ver, %0" : "=r" (ver));
V_27 = ( ( V_29 >> 48 ) & 0xffff ) ;
V_28 = ( ( V_29 >> 32 ) & 0xffff ) ;
if ( V_27 == V_34 &&
( V_28 == V_35 ||
V_28 == V_36 ||
V_28 == V_37 ||
V_28 == V_38 ) ) {
struct V_39 * V_40 ;
V_2 = - V_41 ;
V_40 = F_13 ( sizeof( * V_40 ) , V_42 ) ;
if ( ! V_40 )
goto V_43;
V_19 = F_13 ( ( V_44 * sizeof( * V_19 ) ) ,
V_42 ) ;
if ( ! V_19 )
goto V_43;
V_40 -> V_45 = F_9 ;
V_40 -> V_46 = V_47 ;
V_40 -> V_48 = F_8 ;
V_40 -> V_49 = F_6 ;
V_40 -> exit = F_11 ;
strcpy ( V_40 -> V_50 , L_1 ) ;
V_26 = V_40 ;
V_2 = F_14 ( V_40 ) ;
if ( V_2 )
goto V_43;
return 0 ;
V_43:
if ( V_40 ) {
F_15 ( V_40 ) ;
V_26 = NULL ;
}
F_15 ( V_19 ) ;
V_19 = NULL ;
return V_2 ;
}
return - V_33 ;
}
static void T_2 F_16 ( void )
{
if ( V_26 ) {
F_17 ( V_26 ) ;
F_15 ( V_26 ) ;
V_26 = NULL ;
F_15 ( V_19 ) ;
V_19 = NULL ;
}
}
