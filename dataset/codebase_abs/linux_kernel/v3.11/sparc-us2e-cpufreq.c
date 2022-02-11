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
unsigned long V_22 ;
F_7 ( V_22 ) ;
V_20 &= ~ V_23 ;
if ( V_11 == 2 && V_12 == 1 ) {
F_4 ( 0 ) ;
F_2 ( V_4 , V_20 | V_21 ) ;
F_5 ( 0 , V_10 , V_11 , V_12 ) ;
} else if ( V_11 == 1 && V_12 == 2 ) {
F_5 ( 1 , V_10 , V_11 , V_12 ) ;
F_2 ( V_4 , V_20 | V_21 ) ;
F_4 ( 1 ) ;
} else if ( V_11 == 1 && V_12 > 2 ) {
F_6 ( V_20 , V_24 , V_10 ,
1 , 2 ) ;
F_6 ( V_20 , V_21 , V_10 ,
2 , V_12 ) ;
} else if ( V_11 > 2 && V_12 == 1 ) {
F_6 ( V_20 , V_24 , V_10 ,
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
F_8 () ;
}
F_9 ( V_22 ) ;
}
static unsigned long F_10 ( unsigned int V_25 )
{
switch ( V_25 ) {
case 0 :
return V_26 ;
case 1 :
return V_24 ;
case 2 :
return V_27 ;
case 3 :
return V_28 ;
case 4 :
return V_29 ;
default:
F_8 () ;
}
}
static unsigned long F_11 ( unsigned int V_25 )
{
switch ( V_25 ) {
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
F_8 () ;
}
}
static unsigned long F_12 ( unsigned long V_20 )
{
unsigned long V_2 ;
switch ( V_20 & V_23 ) {
case V_26 :
V_2 = 1 ;
break;
case V_24 :
V_2 = 2 ;
break;
case V_27 :
V_2 = 4 ;
break;
case V_28 :
V_2 = 6 ;
break;
case V_29 :
V_2 = 8 ;
break;
default:
F_8 () ;
}
return V_2 ;
}
static unsigned int F_13 ( unsigned int V_30 )
{
T_1 V_31 ;
unsigned long V_10 , V_20 ;
F_14 ( & V_31 , F_15 ( V_32 ) ) ;
F_16 ( V_32 , F_17 ( V_30 ) ) ;
V_10 = F_18 ( V_30 ) / 1000 ;
V_20 = F_1 ( V_4 ) ;
F_16 ( V_32 , & V_31 ) ;
return V_10 / F_12 ( V_20 ) ;
}
static void F_19 ( struct V_33 * V_34 ,
unsigned int V_25 )
{
unsigned int V_30 = V_34 -> V_30 ;
unsigned long V_21 , V_35 ;
unsigned long V_10 , V_12 , V_11 , V_20 ;
T_1 V_31 ;
struct V_36 V_37 ;
F_14 ( & V_31 , F_15 ( V_32 ) ) ;
F_16 ( V_32 , F_17 ( V_30 ) ) ;
V_35 = V_10 = F_18 ( V_30 ) / 1000 ;
V_21 = F_10 ( V_25 ) ;
V_12 = F_11 ( V_25 ) ;
V_35 /= V_12 ;
V_20 = F_1 ( V_4 ) ;
V_11 = F_12 ( V_20 ) ;
V_37 . V_38 = V_10 / V_11 ;
V_37 . V_39 = V_35 ;
F_20 ( V_34 , & V_37 , V_40 ) ;
if ( V_11 != V_12 )
F_6 ( V_20 , V_21 , V_10 * 1000 ,
V_11 , V_12 ) ;
F_20 ( V_34 , & V_37 , V_41 ) ;
F_16 ( V_32 , & V_31 ) ;
}
static int F_21 ( struct V_33 * V_34 ,
unsigned int V_42 ,
unsigned int V_43 )
{
unsigned int V_44 = 0 ;
if ( F_22 ( V_34 ,
& V_45 [ V_34 -> V_30 ] . V_46 [ 0 ] ,
V_42 , V_43 , & V_44 ) )
return - V_47 ;
F_19 ( V_34 , V_44 ) ;
return 0 ;
}
static int F_23 ( struct V_33 * V_34 )
{
return F_24 ( V_34 ,
& V_45 [ V_34 -> V_30 ] . V_46 [ 0 ] ) ;
}
static int T_2 F_25 ( struct V_33 * V_34 )
{
unsigned int V_30 = V_34 -> V_30 ;
unsigned long V_10 = F_18 ( V_30 ) / 1000 ;
struct V_48 * V_46 =
& V_45 [ V_30 ] . V_46 [ 0 ] ;
V_46 [ 0 ] . V_49 = 0 ;
V_46 [ 0 ] . V_50 = V_10 / 1 ;
V_46 [ 1 ] . V_49 = 1 ;
V_46 [ 1 ] . V_50 = V_10 / 2 ;
V_46 [ 2 ] . V_49 = 2 ;
V_46 [ 2 ] . V_50 = V_10 / 4 ;
V_46 [ 2 ] . V_49 = 3 ;
V_46 [ 2 ] . V_50 = V_10 / 6 ;
V_46 [ 2 ] . V_49 = 4 ;
V_46 [ 2 ] . V_50 = V_10 / 8 ;
V_46 [ 2 ] . V_49 = 5 ;
V_46 [ 3 ] . V_50 = V_51 ;
V_34 -> V_52 . V_53 = 0 ;
V_34 -> V_54 = V_10 ;
return F_26 ( V_34 , V_46 ) ;
}
static int F_27 ( struct V_33 * V_34 )
{
if ( V_55 )
F_19 ( V_34 , 0 ) ;
return 0 ;
}
static int T_2 F_28 ( void )
{
unsigned long V_56 , V_57 , V_58 ;
int V_2 ;
if ( V_59 != V_60 )
return - V_61 ;
__asm__("rdpr %%ver, %0" : "=r" (ver));
V_56 = ( ( V_58 >> 48 ) & 0xffff ) ;
V_57 = ( ( V_58 >> 32 ) & 0xffff ) ;
if ( V_56 == 0x17 && V_57 == 0x13 ) {
struct V_62 * V_63 ;
V_2 = - V_64 ;
V_63 = F_29 ( sizeof( struct V_62 ) , V_65 ) ;
if ( ! V_63 )
goto V_66;
V_45 = F_29 (
( V_67 * sizeof( struct V_68 ) ) ,
V_65 ) ;
if ( ! V_45 )
goto V_66;
V_63 -> V_69 = F_25 ;
V_63 -> V_70 = F_23 ;
V_63 -> V_71 = F_21 ;
V_63 -> V_72 = F_13 ;
V_63 -> exit = F_27 ;
V_63 -> V_73 = V_74 ,
strcpy ( V_63 -> V_75 , L_1 ) ;
V_55 = V_63 ;
V_2 = F_30 ( V_63 ) ;
if ( V_2 )
goto V_66;
return 0 ;
V_66:
if ( V_63 ) {
F_31 ( V_63 ) ;
V_55 = NULL ;
}
F_31 ( V_45 ) ;
V_45 = NULL ;
return V_2 ;
}
return - V_61 ;
}
static void T_3 F_32 ( void )
{
if ( V_55 ) {
F_33 ( V_55 ) ;
F_31 ( V_55 ) ;
V_55 = NULL ;
F_31 ( V_45 ) ;
V_45 = NULL ;
}
}
