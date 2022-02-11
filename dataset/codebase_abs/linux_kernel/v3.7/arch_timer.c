static inline void F_1 ( const int V_1 , const int V_2 , T_1 V_3 )
{
if ( V_1 == V_4 ) {
switch ( V_2 ) {
case V_5 :
asm volatile("mcr p15, 0, %0, c14, c2, 1" : : "r" (val));
break;
case V_6 :
asm volatile("mcr p15, 0, %0, c14, c2, 0" : : "r" (val));
break;
}
}
if ( V_1 == V_7 ) {
switch ( V_2 ) {
case V_5 :
asm volatile("mcr p15, 0, %0, c14, c3, 1" : : "r" (val));
break;
case V_6 :
asm volatile("mcr p15, 0, %0, c14, c3, 0" : : "r" (val));
break;
}
}
F_2 () ;
}
static inline T_1 F_3 ( const int V_1 , const int V_2 )
{
T_1 V_3 = 0 ;
if ( V_1 == V_4 ) {
switch ( V_2 ) {
case V_5 :
asm volatile("mrc p15, 0, %0, c14, c2, 1" : "=r" (val));
break;
case V_6 :
asm volatile("mrc p15, 0, %0, c14, c2, 0" : "=r" (val));
break;
case V_8 :
asm volatile("mrc p15, 0, %0, c14, c0, 0" : "=r" (val));
break;
}
}
if ( V_1 == V_7 ) {
switch ( V_2 ) {
case V_5 :
asm volatile("mrc p15, 0, %0, c14, c3, 1" : "=r" (val));
break;
case V_6 :
asm volatile("mrc p15, 0, %0, c14, c3, 0" : "=r" (val));
break;
}
}
return V_3 ;
}
static inline T_2 F_4 ( const int V_1 )
{
T_2 V_9 = 0 ;
if ( V_1 == V_4 )
asm volatile("mrrc p15, 0, %Q0, %R0, c14" : "=r" (cval));
if ( V_1 == V_7 )
asm volatile("mrrc p15, 1, %Q0, %R0, c14" : "=r" (cval));
return V_9 ;
}
static inline T_2 F_5 ( void )
{
return F_4 ( V_4 ) ;
}
static inline T_2 F_6 ( void )
{
return F_4 ( V_7 ) ;
}
static T_3 inline F_7 ( const int V_1 ,
struct V_10 * V_11 )
{
unsigned long V_12 ;
V_12 = F_3 ( V_1 , V_5 ) ;
if ( V_12 & V_13 ) {
V_12 |= V_14 ;
F_1 ( V_1 , V_5 , V_12 ) ;
V_11 -> V_15 ( V_11 ) ;
return V_16 ;
}
return V_17 ;
}
static T_3 F_8 ( int V_18 , void * V_19 )
{
struct V_10 * V_11 = * (struct V_10 * * ) V_19 ;
return F_7 ( V_7 , V_11 ) ;
}
static T_3 F_9 ( int V_18 , void * V_19 )
{
struct V_10 * V_11 = * (struct V_10 * * ) V_19 ;
return F_7 ( V_4 , V_11 ) ;
}
static inline void F_10 ( const int V_1 , int V_20 )
{
unsigned long V_12 ;
switch ( V_20 ) {
case V_21 :
case V_22 :
V_12 = F_3 ( V_1 , V_5 ) ;
V_12 &= ~ V_23 ;
F_1 ( V_1 , V_5 , V_12 ) ;
break;
default:
break;
}
}
static void F_11 ( enum V_24 V_20 ,
struct V_10 * V_25 )
{
F_10 ( V_7 , V_20 ) ;
}
static void F_12 ( enum V_24 V_20 ,
struct V_10 * V_25 )
{
F_10 ( V_4 , V_20 ) ;
}
static inline void F_13 ( const int V_1 , unsigned long V_11 )
{
unsigned long V_12 ;
V_12 = F_3 ( V_1 , V_5 ) ;
V_12 |= V_23 ;
V_12 &= ~ V_14 ;
F_1 ( V_1 , V_6 , V_11 ) ;
F_1 ( V_1 , V_5 , V_12 ) ;
}
static int F_14 ( unsigned long V_11 ,
struct V_10 * V_26 )
{
F_13 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_15 ( unsigned long V_11 ,
struct V_10 * V_26 )
{
F_13 ( V_4 , V_11 ) ;
return 0 ;
}
static int T_4 F_16 ( struct V_10 * V_25 )
{
V_25 -> V_27 = V_28 | V_29 ;
V_25 -> V_30 = L_1 ;
V_25 -> V_31 = 450 ;
if ( V_32 ) {
V_25 -> V_18 = V_33 [ V_34 ] ;
V_25 -> V_35 = F_11 ;
V_25 -> F_13 = F_14 ;
} else {
V_25 -> V_18 = V_33 [ V_36 ] ;
V_25 -> V_35 = F_12 ;
V_25 -> F_13 = F_15 ;
}
V_25 -> V_35 ( V_22 , NULL ) ;
F_17 ( V_25 , V_37 ,
0xf , 0x7fffffff ) ;
* F_18 ( V_38 ) = V_25 ;
if ( V_32 )
F_19 ( V_33 [ V_34 ] , 0 ) ;
else {
F_19 ( V_33 [ V_36 ] , 0 ) ;
if ( V_33 [ V_39 ] )
F_19 ( V_33 [ V_39 ] , 0 ) ;
}
return 0 ;
}
static int F_20 ( void )
{
return ( F_21 () >= V_40 ) &&
( ( F_22 ( V_41 ) >> 16 ) & 0xf ) == 1 ;
}
static int F_23 ( void )
{
unsigned long V_42 ;
if ( ! F_20 () )
return - V_43 ;
if ( V_37 == 0 ) {
V_42 = F_3 ( V_4 ,
V_8 ) ;
if ( V_42 == 0 ) {
F_24 ( L_2 ) ;
return - V_44 ;
}
V_37 = V_42 ;
}
F_25 ( L_3 ,
V_37 / 1000000 , ( V_37 / 10000 ) % 100 ,
V_32 ? L_4 : L_5 ) ;
return 0 ;
}
static T_1 T_5 F_26 ( void )
{
T_2 V_45 = F_5 () ;
return ( T_1 ) V_45 ;
}
static T_1 T_5 F_27 ( void )
{
T_2 V_45 = F_6 () ;
return ( T_1 ) V_45 ;
}
static T_2 F_28 ( struct V_46 * V_47 )
{
return F_5 () ;
}
static unsigned long F_29 ( void )
{
return F_5 () ;
}
static T_2 F_30 ( const struct V_48 * V_49 )
{
return F_5 () ;
}
struct V_50 * F_31 ( void )
{
return & V_50 ;
}
static void T_4 F_32 ( struct V_10 * V_25 )
{
F_33 ( L_6 ,
V_25 -> V_18 , F_34 () ) ;
if ( V_32 )
F_35 ( V_33 [ V_34 ] ) ;
else {
F_35 ( V_33 [ V_36 ] ) ;
if ( V_33 [ V_39 ] )
F_35 ( V_33 [ V_39 ] ) ;
}
V_25 -> V_35 ( V_21 , V_25 ) ;
}
static int T_6 F_36 ( void )
{
int V_51 ;
int V_52 ;
V_51 = F_23 () ;
if ( V_51 )
goto V_53;
V_38 = F_37 ( struct V_10 * ) ;
if ( ! V_38 ) {
V_51 = - V_54 ;
goto V_53;
}
F_38 ( & V_55 , V_37 ) ;
V_48 . V_56 = V_55 . V_56 ;
V_48 . V_57 = V_55 . V_57 ;
F_39 ( & V_50 , & V_48 ,
F_5 () ) ;
if ( V_32 ) {
V_52 = V_33 [ V_34 ] ;
V_51 = F_40 ( V_52 , F_8 ,
L_7 , V_38 ) ;
} else {
V_52 = V_33 [ V_36 ] ;
V_51 = F_40 ( V_52 , F_9 ,
L_7 , V_38 ) ;
if ( ! V_51 && V_33 [ V_39 ] ) {
V_52 = V_33 [ V_39 ] ;
V_51 = F_40 ( V_52 , F_9 ,
L_7 , V_38 ) ;
if ( V_51 )
F_41 ( V_33 [ V_36 ] ,
V_38 ) ;
}
}
if ( V_51 ) {
F_42 ( L_8 ,
V_52 , V_51 ) ;
goto V_58;
}
V_51 = F_43 ( & V_59 ) ;
if ( V_51 ) {
V_60 . V_61 = F_44 ( 0 ) ;
V_51 = F_16 ( & V_60 ) ;
}
if ( V_51 )
goto V_62;
V_63 . V_64 = & F_29 ;
V_63 . V_42 = V_37 ;
F_45 ( & V_63 ) ;
return 0 ;
V_62:
if ( V_32 )
F_41 ( V_33 [ V_34 ] , V_38 ) ;
else {
F_41 ( V_33 [ V_36 ] ,
V_38 ) ;
if ( V_33 [ V_39 ] )
F_41 ( V_33 [ V_39 ] ,
V_38 ) ;
}
V_58:
F_46 ( V_38 ) ;
V_53:
return V_51 ;
}
int T_6 F_47 ( void )
{
struct V_65 * V_66 ;
T_1 V_42 ;
int V_67 ;
V_66 = F_48 ( NULL , V_68 ) ;
if ( ! V_66 ) {
F_42 ( L_9 ) ;
return - V_69 ;
}
if ( ! F_49 ( V_66 , L_10 , & V_42 ) )
V_37 = V_42 ;
for ( V_67 = V_36 ; V_67 < V_70 ; V_67 ++ )
V_33 [ V_67 ] = F_50 ( V_66 , V_67 ) ;
if ( ! V_33 [ V_34 ] ) {
V_32 = false ;
if ( ! V_33 [ V_36 ] ||
! V_33 [ V_39 ] ) {
F_24 ( L_11 ) ;
return - V_44 ;
}
}
return F_36 () ;
}
int T_6 F_51 ( void )
{
T_1 (* F_52)( void );
int V_51 ;
V_51 = F_23 () ;
if ( V_51 )
return V_51 ;
if ( V_32 )
F_52 = F_27 ;
else
F_52 = F_26 ;
F_53 ( F_52 , 32 , V_37 ) ;
return 0 ;
}
