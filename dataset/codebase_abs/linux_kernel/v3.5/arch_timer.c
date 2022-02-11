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
V_19 -> V_23 = V_24 ;
V_19 -> V_25 = L_1 ;
V_19 -> V_26 = 450 ;
V_19 -> V_27 = F_7 ;
V_19 -> V_28 = F_8 ;
V_19 -> V_6 = V_29 ;
F_10 ( V_19 , V_30 ,
0xf , 0x7fffffff ) ;
* F_11 ( V_31 ) = V_19 ;
F_12 ( V_19 -> V_6 , 0 ) ;
if ( V_32 )
F_12 ( V_32 , 0 ) ;
return 0 ;
}
static int F_13 ( void )
{
return ( F_14 () >= V_33 ) &&
( ( F_15 ( V_34 ) >> 16 ) & 0xf ) == 1 ;
}
static int F_16 ( void )
{
unsigned long V_35 ;
if ( ! F_13 () )
return - V_36 ;
if ( V_30 == 0 ) {
F_1 ( V_3 , 0 ) ;
V_35 = F_3 ( V_5 ) ;
if ( V_35 == 0 ) {
F_17 ( L_2 ) ;
return - V_37 ;
}
V_30 = V_35 ;
}
F_18 ( L_3 ,
V_30 / 1000000 , ( V_30 / 10000 ) % 100 ) ;
return 0 ;
}
static inline T_4 F_19 ( void )
{
T_1 V_38 , V_39 ;
asm volatile("mrrc p15, 0, %0, %1, c14" : "=r" (cvall), "=r" (cvalh));
return ( ( T_4 ) V_39 << 32 ) | V_38 ;
}
static inline T_4 F_20 ( void )
{
T_1 V_38 , V_39 ;
asm volatile("mrrc p15, 1, %0, %1, c14" : "=r" (cvall), "=r" (cvalh));
return ( ( T_4 ) V_39 << 32 ) | V_38 ;
}
static T_1 T_5 F_21 ( void )
{
T_4 V_40 = F_20 () ;
return ( T_1 ) ( V_40 & ( T_1 ) ~ 0 ) ;
}
static T_4 F_22 ( struct V_41 * V_42 )
{
return F_19 () ;
}
static void T_3 F_23 ( struct V_8 * V_19 )
{
F_24 ( L_4 ,
V_19 -> V_6 , F_25 () ) ;
F_26 ( V_19 -> V_6 ) ;
if ( V_32 )
F_26 ( V_32 ) ;
F_7 ( V_20 , V_19 ) ;
}
static int T_6 F_27 ( void )
{
int V_43 ;
V_43 = F_16 () ;
if ( V_43 )
return V_43 ;
V_31 = F_28 ( struct V_8 * ) ;
if ( ! V_31 )
return - V_44 ;
F_29 ( & V_45 , V_30 ) ;
V_43 = F_30 ( V_29 , F_5 ,
L_5 , V_31 ) ;
if ( V_43 ) {
F_31 ( L_6 ,
V_29 , V_43 ) ;
goto V_46;
}
if ( V_32 ) {
V_43 = F_30 ( V_32 , F_5 ,
L_5 , V_31 ) ;
if ( V_43 ) {
F_31 ( L_6 ,
V_32 , V_43 ) ;
V_32 = 0 ;
goto V_47;
}
}
V_43 = F_32 ( & V_48 ) ;
if ( V_43 ) {
V_49 . V_50 = F_33 ( 0 ) ;
V_43 = F_9 ( & V_49 ) ;
}
if ( V_43 )
goto V_47;
return 0 ;
V_47:
F_34 ( V_29 , V_31 ) ;
if ( V_32 )
F_34 ( V_32 , V_31 ) ;
V_46:
F_35 ( V_31 ) ;
return V_43 ;
}
int T_6 F_36 ( void )
{
struct V_51 * V_52 ;
T_1 V_35 ;
V_52 = F_37 ( NULL , V_53 ) ;
if ( ! V_52 ) {
F_31 ( L_7 ) ;
return - V_54 ;
}
if ( ! F_38 ( V_52 , L_8 , & V_35 ) )
V_30 = V_35 ;
V_29 = F_39 ( V_52 , 0 ) ;
V_32 = F_39 ( V_52 , 1 ) ;
F_40 ( L_9 ,
V_52 -> V_25 , V_29 , V_32 ) ;
return F_27 () ;
}
int T_6 F_41 ( void )
{
int V_43 ;
V_43 = F_16 () ;
if ( V_43 )
return V_43 ;
F_42 ( F_21 , 32 , V_30 ) ;
return 0 ;
}
