static unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
__asm__ __volatile__("ldxa [%1] %2, %0"
: "=&r" (ret)
: "r" (addr), "i" (ASI_PHYS_BYPASS_EC_E));
return V_2 ;
}
static void F_2 ( unsigned long V_1 , unsigned long V_3 )
{
__asm__ __volatile__("stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (val), "r" (addr), "i" (ASI_PHYS_BYPASS_EC_E)
: "memory");
if ( V_1 == V_4 ) {
F_3 ( 1 ) ;
}
}
static void F_4 ( int V_5 )
{
unsigned long V_6 = F_1 ( V_7 ) ;
if ( V_5 )
V_6 |= V_8 ;
else
V_6 &= ~ V_8 ;
F_2 ( V_7 , V_6 ) ;
( void ) F_1 ( V_7 ) ;
}
static void F_5 ( int V_9 ,
unsigned long V_10 ,
unsigned long V_11 , unsigned long V_12 )
{
unsigned long V_13 , V_14 , V_6 ;
V_14 = ( V_10 * V_15 ) ;
V_14 /= ( V_16 * V_12 * 1000000000UL ) ;
V_6 = F_1 ( V_7 ) ;
V_13 = ( V_6 & V_17 )
>> V_18 ;
V_6 &= ~ V_17 ;
V_6 |= V_14 << V_18 ;
F_2 ( V_7 , V_6 ) ;
V_6 = F_1 ( V_7 ) ;
if ( V_9 && ! ( V_6 & V_8 ) ) {
unsigned long V_19 ;
V_19 = ( V_16 *
( V_14 + V_13 ) *
1000000UL *
V_11 ) / V_10 ;
F_3 ( V_19 + 1UL ) ;
}
}
static void F_6 ( unsigned long V_20 , unsigned long V_21 ,
unsigned long V_10 ,
unsigned long V_11 , unsigned long V_12 )
{
V_20 &= ~ V_22 ;
if ( V_11 == 2 && V_12 == 1 ) {
F_4 ( 0 ) ;
F_2 ( V_4 , V_20 | V_21 ) ;
F_5 ( 0 , V_10 , V_11 , V_12 ) ;
} else if ( V_11 == 1 && V_12 == 2 ) {
F_5 ( 1 , V_10 , V_11 , V_12 ) ;
F_2 ( V_4 , V_20 | V_21 ) ;
F_4 ( 1 ) ;
} else if ( V_11 == 1 && V_12 > 2 ) {
F_6 ( V_20 , V_23 , V_10 ,
1 , 2 ) ;
F_6 ( V_20 , V_21 , V_10 ,
2 , V_12 ) ;
} else if ( V_11 > 2 && V_12 == 1 ) {
F_6 ( V_20 , V_23 , V_10 ,
V_11 , 2 ) ;
F_6 ( V_20 , V_21 , V_10 ,
2 , V_12 ) ;
} else if ( V_11 < V_12 ) {
F_5 ( 0 , V_10 , V_11 , V_12 ) ;
F_2 ( V_4 , V_20 | V_21 ) ;
} else if ( V_11 > V_12 ) {
F_2 ( V_4 , V_20 | V_21 ) ;
F_5 ( 1 , V_10 , V_11 , V_12 ) ;
} else {
F_7 () ;
}
}
static unsigned long F_8 ( unsigned int V_24 )
{
switch ( V_24 ) {
case 0 :
return V_25 ;
case 1 :
return V_23 ;
case 2 :
return V_26 ;
case 3 :
return V_27 ;
case 4 :
return V_28 ;
default:
F_7 () ;
}
}
static unsigned long F_9 ( unsigned int V_24 )
{
switch ( V_24 ) {
case 0 :
return 1 ;
case 1 :
return 2 ;
case 2 :
return 4 ;
case 3 :
return 6 ;
case 4 :
return 8 ;
default:
F_7 () ;
}
}
static unsigned long F_10 ( unsigned long V_20 )
{
unsigned long V_2 ;
switch ( V_20 & V_22 ) {
case V_25 :
V_2 = 1 ;
break;
case V_23 :
V_2 = 2 ;
break;
case V_26 :
V_2 = 4 ;
break;
case V_27 :
V_2 = 6 ;
break;
case V_28 :
V_2 = 8 ;
break;
default:
F_7 () ;
}
return V_2 ;
}
static void F_11 ( void * V_29 )
{
unsigned long * V_20 = V_29 ;
* V_20 = F_1 ( V_4 ) ;
}
static unsigned int F_12 ( unsigned int V_30 )
{
unsigned long V_10 , V_20 ;
V_10 = F_13 ( V_30 ) / 1000 ;
if ( F_14 ( V_30 , F_11 , & V_20 , 1 ) )
return 0 ;
return V_10 / F_10 ( V_20 ) ;
}
static void F_15 ( void * V_29 )
{
unsigned int V_30 = F_16 () ;
unsigned int * V_24 = V_29 ;
unsigned long V_21 , V_31 ;
unsigned long V_10 , V_12 , V_11 , V_20 ;
V_31 = V_10 = F_13 ( V_30 ) / 1000 ;
V_21 = F_8 ( * V_24 ) ;
V_12 = F_9 ( * V_24 ) ;
V_31 /= V_12 ;
V_20 = F_1 ( V_4 ) ;
V_11 = F_10 ( V_20 ) ;
if ( V_11 != V_12 ) {
F_6 ( V_20 , V_21 , V_10 * 1000 ,
V_11 , V_12 ) ;
}
}
static int F_17 ( struct V_32 * V_33 , unsigned int V_24 )
{
unsigned int V_30 = V_33 -> V_30 ;
return F_14 ( V_30 , F_15 , & V_24 , 1 ) ;
}
static int T_1 F_18 ( struct V_32 * V_33 )
{
unsigned int V_30 = V_33 -> V_30 ;
unsigned long V_10 = F_13 ( V_30 ) / 1000 ;
struct V_34 * V_35 =
& V_36 [ V_30 ] . V_35 [ 0 ] ;
V_35 [ 0 ] . V_37 = 0 ;
V_35 [ 0 ] . V_38 = V_10 / 1 ;
V_35 [ 1 ] . V_37 = 1 ;
V_35 [ 1 ] . V_38 = V_10 / 2 ;
V_35 [ 2 ] . V_37 = 2 ;
V_35 [ 2 ] . V_38 = V_10 / 4 ;
V_35 [ 2 ] . V_37 = 3 ;
V_35 [ 2 ] . V_38 = V_10 / 6 ;
V_35 [ 2 ] . V_37 = 4 ;
V_35 [ 2 ] . V_38 = V_10 / 8 ;
V_35 [ 2 ] . V_37 = 5 ;
V_35 [ 3 ] . V_38 = V_39 ;
V_33 -> V_40 . V_41 = 0 ;
V_33 -> V_42 = V_10 ;
return F_19 ( V_33 , V_35 ) ;
}
static int F_20 ( struct V_32 * V_33 )
{
if ( V_43 )
F_17 ( V_33 , 0 ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
unsigned long V_44 , V_45 , V_46 ;
int V_2 ;
if ( V_47 != V_48 )
return - V_49 ;
__asm__("rdpr %%ver, %0" : "=r" (ver));
V_44 = ( ( V_46 >> 48 ) & 0xffff ) ;
V_45 = ( ( V_46 >> 32 ) & 0xffff ) ;
if ( V_44 == 0x17 && V_45 == 0x13 ) {
struct V_50 * V_51 ;
V_2 = - V_52 ;
V_51 = F_22 ( sizeof( * V_51 ) , V_53 ) ;
if ( ! V_51 )
goto V_54;
V_36 = F_22 ( ( V_55 * sizeof( * V_36 ) ) ,
V_53 ) ;
if ( ! V_36 )
goto V_54;
V_51 -> V_56 = F_18 ;
V_51 -> V_57 = V_58 ;
V_51 -> V_59 = F_17 ;
V_51 -> V_60 = F_12 ;
V_51 -> exit = F_20 ;
strcpy ( V_51 -> V_61 , L_1 ) ;
V_43 = V_51 ;
V_2 = F_23 ( V_51 ) ;
if ( V_2 )
goto V_54;
return 0 ;
V_54:
if ( V_51 ) {
F_24 ( V_51 ) ;
V_43 = NULL ;
}
F_24 ( V_36 ) ;
V_36 = NULL ;
return V_2 ;
}
return - V_49 ;
}
static void T_2 F_25 ( void )
{
if ( V_43 ) {
F_26 ( V_43 ) ;
F_24 ( V_43 ) ;
V_43 = NULL ;
F_24 ( V_36 ) ;
V_36 = NULL ;
}
}
