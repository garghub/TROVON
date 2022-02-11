static void F_1 ( int V_1 , T_1 V_2 )
{
switch ( V_1 ) {
case V_3 :
asm volatile("mcr p15, 0, %0, c14, c2, 1" : : "r" (val));
break;
case V_4 :
asm volatile("mcr p15, 0, %0, c14, c2, 0" : : "r" (val));
break;
}
F_2 () ;
}
static T_1 F_3 ( int V_1 )
{
T_1 V_2 ;
switch ( V_1 ) {
case V_3 :
asm volatile("mrc p15, 0, %0, c14, c2, 1" : "=r" (val));
break;
case V_5 :
asm volatile("mrc p15, 0, %0, c14, c0, 0" : "=r" (val));
break;
case V_4 :
asm volatile("mrc p15, 0, %0, c14, c2, 0" : "=r" (val));
break;
default:
F_4 () ;
}
return V_2 ;
}
static T_2 F_5 ( int V_6 , void * V_7 )
{
struct V_8 * V_9 = * (struct V_8 * * ) V_7 ;
unsigned long V_10 ;
V_10 = F_3 ( V_3 ) ;
if ( V_10 & V_11 ) {
V_10 |= V_12 ;
F_1 ( V_3 , V_10 ) ;
V_9 -> V_13 ( V_9 ) ;
return V_14 ;
}
return V_15 ;
}
static void F_6 ( void )
{
unsigned long V_10 ;
V_10 = F_3 ( V_3 ) ;
V_10 &= ~ V_16 ;
F_1 ( V_3 , V_10 ) ;
}
static void F_7 ( enum V_17 V_18 ,
struct V_8 * V_19 )
{
switch ( V_18 ) {
case V_20 :
case V_21 :
F_6 () ;
break;
default:
break;
}
}
static int F_8 ( unsigned long V_9 ,
struct V_8 * V_22 )
{
unsigned long V_10 ;
V_10 = F_3 ( V_3 ) ;
V_10 |= V_16 ;
V_10 &= ~ V_12 ;
F_1 ( V_4 , V_9 ) ;
F_1 ( V_3 , V_10 ) ;
return 0 ;
}
static int T_3 F_9 ( struct V_8 * V_19 )
{
F_6 () ;
V_19 -> V_23 = V_24 | V_25 ;
V_19 -> V_26 = L_1 ;
V_19 -> V_27 = 450 ;
V_19 -> V_28 = F_7 ;
V_19 -> V_29 = F_8 ;
V_19 -> V_6 = V_30 ;
F_10 ( V_19 , V_31 ,
0xf , 0x7fffffff ) ;
* F_11 ( V_32 ) = V_19 ;
F_12 ( V_19 -> V_6 , 0 ) ;
if ( V_33 )
F_12 ( V_33 , 0 ) ;
return 0 ;
}
static int F_13 ( void )
{
return ( F_14 () >= V_34 ) &&
( ( F_15 ( V_35 ) >> 16 ) & 0xf ) == 1 ;
}
static int F_16 ( void )
{
unsigned long V_36 ;
if ( ! F_13 () )
return - V_37 ;
if ( V_31 == 0 ) {
F_1 ( V_3 , 0 ) ;
V_36 = F_3 ( V_5 ) ;
if ( V_36 == 0 ) {
F_17 ( L_2 ) ;
return - V_38 ;
}
V_31 = V_36 ;
}
F_18 ( L_3 ,
V_31 / 1000000 , ( V_31 / 10000 ) % 100 ) ;
return 0 ;
}
static inline T_4 F_19 ( void )
{
T_1 V_39 , V_40 ;
asm volatile("mrrc p15, 0, %0, %1, c14" : "=r" (cvall), "=r" (cvalh));
return ( ( T_4 ) V_40 << 32 ) | V_39 ;
}
static inline T_4 F_20 ( void )
{
T_1 V_39 , V_40 ;
asm volatile("mrrc p15, 1, %0, %1, c14" : "=r" (cvall), "=r" (cvalh));
return ( ( T_4 ) V_40 << 32 ) | V_39 ;
}
static T_1 T_5 F_21 ( void )
{
T_4 V_41 = F_20 () ;
return ( T_1 ) ( V_41 & ( T_1 ) ~ 0 ) ;
}
static T_4 F_22 ( struct V_42 * V_43 )
{
return F_19 () ;
}
int F_23 ( unsigned long * V_44 )
{
if ( ! V_31 )
return - V_37 ;
* V_44 = F_19 () ;
return 0 ;
}
static void T_3 F_24 ( struct V_8 * V_19 )
{
F_25 ( L_4 ,
V_19 -> V_6 , F_26 () ) ;
F_27 ( V_19 -> V_6 ) ;
if ( V_33 )
F_27 ( V_33 ) ;
F_7 ( V_20 , V_19 ) ;
}
static int T_6 F_28 ( void )
{
int V_45 ;
V_45 = F_16 () ;
if ( V_45 )
return V_45 ;
V_32 = F_29 ( struct V_8 * ) ;
if ( ! V_32 )
return - V_46 ;
F_30 ( & V_47 , V_31 ) ;
V_45 = F_31 ( V_30 , F_5 ,
L_5 , V_32 ) ;
if ( V_45 ) {
F_32 ( L_6 ,
V_30 , V_45 ) ;
goto V_48;
}
if ( V_33 ) {
V_45 = F_31 ( V_33 , F_5 ,
L_5 , V_32 ) ;
if ( V_45 ) {
F_32 ( L_6 ,
V_33 , V_45 ) ;
V_33 = 0 ;
goto V_49;
}
}
V_45 = F_33 ( & V_50 ) ;
if ( V_45 ) {
V_51 . V_52 = F_34 ( 0 ) ;
V_45 = F_9 ( & V_51 ) ;
}
if ( V_45 )
goto V_49;
F_35 ( V_31 ) ;
return 0 ;
V_49:
F_36 ( V_30 , V_32 ) ;
if ( V_33 )
F_36 ( V_33 , V_32 ) ;
V_48:
F_37 ( V_32 ) ;
return V_45 ;
}
int T_6 F_38 ( void )
{
struct V_53 * V_54 ;
T_1 V_36 ;
V_54 = F_39 ( NULL , V_55 ) ;
if ( ! V_54 ) {
F_32 ( L_7 ) ;
return - V_56 ;
}
if ( ! F_40 ( V_54 , L_8 , & V_36 ) )
V_31 = V_36 ;
V_30 = F_41 ( V_54 , 0 ) ;
V_33 = F_41 ( V_54 , 1 ) ;
F_42 ( L_9 ,
V_54 -> V_26 , V_30 , V_33 ) ;
return F_28 () ;
}
int T_6 F_43 ( void )
{
int V_45 ;
V_45 = F_16 () ;
if ( V_45 )
return V_45 ;
F_44 ( F_21 , 32 , V_31 ) ;
return 0 ;
}
