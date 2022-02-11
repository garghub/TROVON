static inline T_1 T_2 F_1 ( void )
{
T_1 V_1 ;
__asm__("rdhwr %0, $1" : "=r" (res));
return V_1 ;
}
static void T_2 F_2 ( void * V_2 , unsigned long V_3 )
{
void * V_4 = V_2 + V_3 ;
T_1 V_5 = F_1 () ;
do {
__asm__ __volatile__(
"synci 0(%0)"
:
: "r" (kbase));
V_2 += V_5 ;
} while ( V_2 < V_4 );
F_3 () ;
}
static int T_2 F_4 ( T_1 * V_6 , T_1 * V_7 , long V_8 )
{
* ( V_9 * ) V_7 += V_8 ;
return 0 ;
}
static int T_2 F_5 ( T_1 * V_6 , T_1 * V_7 , long V_8 )
{
* V_7 += V_8 ;
return 0 ;
}
static int T_2 F_6 ( T_1 * V_6 , T_1 * V_7 , long V_8 )
{
unsigned long V_10 = ( * V_6 ) & 0x03ffffff ;
if ( V_8 % 4 ) {
F_7 ( L_1 ) ;
return - V_11 ;
}
V_10 <<= 2 ;
V_10 += ( unsigned long ) V_6 & ~ 0x03ffffff ;
V_10 += V_8 ;
if ( ( V_10 & 0xf0000000 ) != ( ( unsigned long ) V_7 & 0xf0000000 ) ) {
F_7 ( L_2 ) ;
return - V_11 ;
}
V_10 -= ( unsigned long ) V_7 & ~ 0x03ffffff ;
V_10 >>= 2 ;
* V_7 = ( * V_7 & ~ 0x03ffffff ) | ( V_10 & 0x03ffffff ) ;
return 0 ;
}
static int T_2 F_8 ( T_1 * V_6 , T_1 * V_7 , long V_8 )
{
unsigned long V_12 = * V_6 ;
unsigned long V_13 = ( V_12 & 0xffff ) << 16 ;
V_13 += V_8 ;
* V_7 = ( V_12 & ~ 0xffff ) | ( ( V_13 >> 16 ) & 0xffff ) ;
return 0 ;
}
int T_2 F_9 ( void * V_14 , void * V_15 , long V_8 )
{
T_1 * V_16 ;
T_1 * V_6 ;
T_1 * V_7 ;
int type ;
int V_1 ;
for ( V_16 = V_17 ; V_16 < V_18 ; V_16 ++ ) {
if ( * V_16 == 0 )
break;
type = ( * V_16 >> 24 ) & 0xff ;
V_6 = ( void * ) ( V_14 + ( ( * V_16 & 0x00ffffff ) << 2 ) ) ;
V_7 = F_10 ( V_6 ) ;
if ( V_19 [ type ] == NULL ) {
F_7 ( L_3 ,
type , V_6 ) ;
return - V_11 ;
}
V_1 = V_19 [ type ] ( V_6 , V_7 , V_8 ) ;
if ( V_1 )
return V_1 ;
}
return 0 ;
}
static int T_2 F_11 ( long V_8 )
{
unsigned long * V_20 , * V_21 , * V_22 ;
V_20 = F_10 ( & V_23 ) ;
V_21 = F_10 ( & V_24 ) ;
for ( V_22 = V_20 ; V_22 < V_21 ; V_22 ++ )
* V_22 += V_8 ;
return 0 ;
}
static inline T_2 unsigned long F_12 ( unsigned long V_25 ,
const void * V_26 , T_3 V_27 )
{
T_3 V_28 ;
unsigned long * V_29 = ( unsigned long * ) V_26 ;
for ( V_28 = 0 ; V_28 < V_27 / sizeof( V_25 ) ; V_28 ++ ) {
V_25 = ( V_25 << ( ( sizeof( V_25 ) * 8 ) - 7 ) ) | ( V_25 >> 7 ) ;
V_25 ^= V_29 [ V_28 ] ;
}
return V_25 ;
}
static inline T_2 unsigned long F_13 ( void )
{
unsigned long V_30 = F_14 () ;
unsigned long V_25 = 0 ;
V_25 = F_12 ( V_25 , V_31 , strlen ( V_31 ) ) ;
V_25 = F_12 ( V_25 , & V_30 , sizeof( V_30 ) ) ;
#if F_15 ( V_32 )
if ( V_33 ) {
int V_34 , V_35 ;
V_9 * V_36 ;
V_34 = F_16 ( V_33 , L_4 ) ;
if ( V_34 >= 0 ) {
V_36 = F_17 ( V_33 , V_34 ,
L_5 , & V_35 ) ;
if ( V_36 && ( V_35 == sizeof( V_9 ) ) )
V_25 = F_12 ( V_25 , V_36 , sizeof( * V_36 ) ) ;
}
}
#endif
return V_25 ;
}
static inline T_2 bool F_18 ( void )
{
char * V_37 ;
#if F_15 ( V_38 )
const char * V_39 = V_40 ;
V_37 = strstr ( V_39 , L_6 ) ;
if ( V_37 == V_39 ||
( V_37 > V_39 && * ( V_37 - 1 ) == ' ' ) )
return true ;
#endif
V_37 = strstr ( V_41 , L_6 ) ;
if ( V_37 == V_41 || ( V_37 > V_41 && * ( V_37 - 1 ) == ' ' ) )
return true ;
return false ;
}
static inline void T_2 * F_19 ( void )
{
unsigned long V_3 ;
void * V_42 = & V_43 ;
unsigned long V_8 ;
if ( F_18 () )
return V_42 ;
V_3 = ( long ) V_44 - ( long ) ( & V_43 ) ;
V_8 = F_13 () << 16 ;
V_8 &= ( V_45 - 1 ) ;
if ( V_8 < V_3 )
V_8 += F_20 ( V_3 , 0xffff ) ;
return F_10 ( V_42 ) ;
}
static inline void T_2 * F_19 ( void )
{
return ( void * ) 0xffffffff81000000 ;
}
static inline int T_2 F_21 ( void * V_7 )
{
if ( ( unsigned long ) V_7 & 0x0000ffff ) {
return 0 ;
}
if ( ( unsigned long ) V_7 < ( unsigned long ) & V_44 ) {
return 0 ;
}
return 1 ;
}
void * T_2 F_22 ( void )
{
void * V_7 ;
unsigned long V_3 ;
unsigned long V_46 ;
long V_8 = 0 ;
int V_1 = 1 ;
void * V_47 = V_48 ;
F_23 () ;
#if F_15 ( V_32 )
F_24 ( F_25 () ) ;
if ( V_49 [ 0 ] ) {
F_26 ( V_41 , V_49 , V_50 ) ;
}
#endif
V_3 = ( long ) ( & V_17 ) - ( long ) ( & V_43 ) ;
V_46 = ( long ) & V_51 - ( long ) & V_52 ;
V_7 = F_19 () ;
if ( F_21 ( V_7 ) )
V_8 = ( unsigned long ) V_7 - ( unsigned long ) ( & V_43 ) ;
V_41 [ 0 ] = '\0' ;
if ( V_8 ) {
memcpy ( V_7 , & V_43 , V_3 ) ;
V_1 = F_9 ( & V_43 , V_7 , V_8 ) ;
if ( V_1 < 0 )
goto V_53;
F_2 ( V_7 , V_3 ) ;
V_1 = F_11 ( V_8 ) ;
if ( V_1 < 0 )
goto V_53;
memcpy ( F_10 ( & V_52 ) , & V_52 , V_46 ) ;
V_54 = F_10 ( & V_55 ) ;
V_47 = F_10 ( V_48 ) ;
}
V_53:
return V_47 ;
}
void F_27 ( const char * V_56 )
{
unsigned long V_8 ;
V_8 = F_28 ( V_43 ) - F_28 ( V_57 ) ;
if ( F_29 ( V_58 ) && V_8 > 0 ) {
F_30 ( V_56 ) ;
F_31 ( L_7 , ( void * ) V_8 ) ;
F_31 ( L_8 , V_43 ) ;
F_31 ( L_9 , V_59 ) ;
F_31 ( L_10 , V_52 ) ;
}
}
static int F_32 ( struct V_60 * V_61 ,
unsigned long V_62 , void * V_63 )
{
F_27 ( V_64 ) ;
return V_65 ;
}
static int T_2 F_33 ( void )
{
F_34 ( & V_66 ,
& V_67 ) ;
return 0 ;
}
