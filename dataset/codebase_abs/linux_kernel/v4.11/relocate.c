int __weak F_1 ( long V_1 )
{
return 0 ;
}
static inline T_1 T_2 F_2 ( void )
{
T_1 V_2 ;
__asm__("rdhwr %0, $1" : "=r" (res));
return V_2 ;
}
static void T_2 F_3 ( void * V_3 , unsigned long V_4 )
{
void * V_5 = V_3 + V_4 ;
T_1 V_6 = F_2 () ;
do {
__asm__ __volatile__(
"synci 0(%0)"
:
: "r" (kbase));
V_3 += V_6 ;
} while ( V_3 < V_5 );
F_4 () ;
}
static int T_2 F_5 ( T_1 * V_7 , T_1 * V_8 , long V_1 )
{
* ( V_9 * ) V_8 += V_1 ;
return 0 ;
}
static int T_2 F_6 ( T_1 * V_7 , T_1 * V_8 , long V_1 )
{
* V_8 += V_1 ;
return 0 ;
}
static int T_2 F_7 ( T_1 * V_7 , T_1 * V_8 , long V_1 )
{
unsigned long V_10 = ( * V_7 ) & 0x03ffffff ;
if ( V_1 % 4 ) {
F_8 ( L_1 ) ;
return - V_11 ;
}
V_10 <<= 2 ;
V_10 += ( unsigned long ) V_7 & ~ 0x03ffffff ;
V_10 += V_1 ;
if ( ( V_10 & 0xf0000000 ) != ( ( unsigned long ) V_8 & 0xf0000000 ) ) {
F_8 ( L_2 ) ;
return - V_11 ;
}
V_10 -= ( unsigned long ) V_8 & ~ 0x03ffffff ;
V_10 >>= 2 ;
* V_8 = ( * V_8 & ~ 0x03ffffff ) | ( V_10 & 0x03ffffff ) ;
return 0 ;
}
static int T_2 F_9 ( T_1 * V_7 , T_1 * V_8 , long V_1 )
{
unsigned long V_12 = * V_7 ;
unsigned long V_13 = ( V_12 & 0xffff ) << 16 ;
V_13 += V_1 ;
* V_8 = ( V_12 & ~ 0xffff ) | ( ( V_13 >> 16 ) & 0xffff ) ;
return 0 ;
}
int T_2 F_10 ( void * V_14 , void * V_15 , long V_1 )
{
T_1 * V_16 ;
T_1 * V_7 ;
T_1 * V_8 ;
int type ;
int V_2 ;
for ( V_16 = V_17 ; V_16 < V_18 ; V_16 ++ ) {
if ( * V_16 == 0 )
break;
type = ( * V_16 >> 24 ) & 0xff ;
V_7 = ( void * ) ( V_14 + ( ( * V_16 & 0x00ffffff ) << 2 ) ) ;
V_8 = F_11 ( V_7 ) ;
if ( V_19 [ type ] == NULL ) {
F_8 ( L_3 ,
type , V_7 ) ;
return - V_11 ;
}
V_2 = V_19 [ type ] ( V_7 , V_8 , V_1 ) ;
if ( V_2 )
return V_2 ;
}
return 0 ;
}
static int T_2 F_12 ( long V_1 )
{
unsigned long * V_20 , * V_21 , * V_22 ;
V_20 = F_11 ( & V_23 ) ;
V_21 = F_11 ( & V_24 ) ;
for ( V_22 = V_20 ; V_22 < V_21 ; V_22 ++ )
* V_22 += V_1 ;
return 0 ;
}
static inline T_2 unsigned long F_13 ( unsigned long V_25 ,
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
static inline T_2 unsigned long F_14 ( void )
{
unsigned long V_30 = F_15 () ;
unsigned long V_25 = 0 ;
V_25 = F_13 ( V_25 , V_31 , strlen ( V_31 ) ) ;
V_25 = F_13 ( V_25 , & V_30 , sizeof( V_30 ) ) ;
#if F_16 ( V_32 )
if ( V_33 ) {
int V_34 , V_35 ;
V_9 * V_36 ;
V_34 = F_17 ( V_33 , L_4 ) ;
if ( V_34 >= 0 ) {
V_36 = F_18 ( V_33 , V_34 ,
L_5 , & V_35 ) ;
if ( V_36 && ( V_35 == sizeof( V_9 ) ) )
V_25 = F_13 ( V_25 , V_36 , sizeof( * V_36 ) ) ;
}
}
#endif
return V_25 ;
}
static inline T_2 bool F_19 ( void )
{
char * V_37 ;
#if F_16 ( V_38 )
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
static inline void T_2 * F_20 ( void )
{
unsigned long V_4 ;
void * V_42 = & V_43 ;
unsigned long V_1 ;
if ( F_19 () )
return V_42 ;
V_4 = ( long ) V_44 - ( long ) ( & V_43 ) ;
V_1 = F_14 () << 16 ;
V_1 &= ( V_45 - 1 ) ;
if ( V_1 < V_4 )
V_1 += F_21 ( V_4 , 0xffff ) ;
return F_11 ( V_42 ) ;
}
static inline void T_2 * F_20 ( void )
{
return ( void * ) 0xffffffff81000000 ;
}
static inline int T_2 F_22 ( void * V_8 )
{
if ( ( unsigned long ) V_8 & 0x0000ffff ) {
return 0 ;
}
if ( ( unsigned long ) V_8 < ( unsigned long ) & V_44 ) {
return 0 ;
}
return 1 ;
}
void * T_2 F_23 ( void )
{
void * V_8 ;
unsigned long V_4 ;
unsigned long V_46 ;
long V_1 = 0 ;
int V_2 = 1 ;
void * V_47 = V_48 ;
void * V_49 = NULL ;
F_24 () ;
#if F_16 ( V_32 )
V_49 = F_25 () ;
F_26 ( V_49 ) ;
if ( V_50 [ 0 ] ) {
F_27 ( V_41 , V_50 , V_51 ) ;
}
#endif
V_4 = ( long ) ( & V_17 ) - ( long ) ( & V_43 ) ;
V_46 = ( long ) & V_52 - ( long ) & V_53 ;
V_8 = F_20 () ;
if ( F_22 ( V_8 ) )
V_1 = ( unsigned long ) V_8 - ( unsigned long ) ( & V_43 ) ;
V_41 [ 0 ] = '\0' ;
if ( V_1 ) {
void (* F_28)( void * ) = NULL ;
#if F_16 ( V_32 )
unsigned long V_54 = F_29 ( V_49 ) ;
if ( V_54 >= F_29 ( F_11 ( & V_43 ) ) &&
V_54 <= F_29 ( F_11 ( & V_44 ) ) ) {
void * V_55 =
F_11 ( F_21 ( ( long ) & V_44 , V_56 ) ) ;
memcpy ( V_55 , V_49 , F_30 ( V_49 ) ) ;
V_49 = V_55 ;
F_28 = F_11 ( & V_57 ) ;
}
#endif
memcpy ( V_8 , & V_43 , V_4 ) ;
V_2 = F_10 ( & V_43 , V_8 , V_1 ) ;
if ( V_2 < 0 )
goto V_58;
F_3 ( V_8 , V_4 ) ;
V_2 = F_12 ( V_1 ) ;
if ( V_2 < 0 )
goto V_58;
memcpy ( F_11 ( & V_53 ) , & V_53 , V_46 ) ;
if ( F_28 )
F_28 ( V_49 ) ;
if ( F_1 ( V_1 ) )
goto V_58;
V_59 = F_11 ( & V_60 ) ;
V_47 = F_11 ( V_48 ) ;
}
V_58:
return V_47 ;
}
void F_31 ( const char * V_61 )
{
unsigned long V_1 ;
V_1 = F_32 ( V_43 ) - F_32 ( V_62 ) ;
if ( F_33 ( V_63 ) && V_1 > 0 ) {
F_34 ( V_61 ) ;
F_35 ( L_7 , ( void * ) V_1 ) ;
F_35 ( L_8 , V_43 ) ;
F_35 ( L_9 , V_64 ) ;
F_35 ( L_10 , V_53 ) ;
}
}
static int F_36 ( struct V_65 * V_66 ,
unsigned long V_67 , void * V_68 )
{
F_31 ( V_69 ) ;
return V_70 ;
}
static int T_2 F_37 ( void )
{
F_38 ( & V_71 ,
& V_72 ) ;
return 0 ;
}
