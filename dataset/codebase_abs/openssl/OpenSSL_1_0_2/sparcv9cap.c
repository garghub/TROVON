int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_4 , const T_1 * V_5 , int V_6 )
{
int V_7 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_4 , const T_1 * V_5 , int V_6 ) ;
int V_8 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_4 , const T_1 * V_5 , int V_6 ) ;
int V_9 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_4 , const T_1 * V_5 , int V_6 ) ;
if ( ! ( V_6 & 1 ) && V_6 >= 6 ) {
if ( ( V_6 & 15 ) == 0 && V_6 <= 64 &&
( V_10 [ 1 ] & ( V_11 | V_12 ) ) ==
( V_11 | V_12 ) ) {
typedef int (* F_2) ( T_1 * V_1 , const T_1 * V_2 ,
const T_1 * V_3 ,
const T_1 * V_4 ,
const T_1 * V_5 );
int V_13 ( T_1 * V_1 , const T_1 * V_2 ,
const T_1 * V_3 , const T_1 * V_4 ,
const T_1 * V_5 ) ;
int V_14 ( T_1 * V_1 , const T_1 * V_2 ,
const T_1 * V_3 , const T_1 * V_4 ,
const T_1 * V_5 ) ;
int V_15 ( T_1 * V_1 , const T_1 * V_2 ,
const T_1 * V_3 , const T_1 * V_4 ,
const T_1 * V_5 ) ;
int V_16 ( T_1 * V_1 , const T_1 * V_2 ,
const T_1 * V_3 , const T_1 * V_4 ,
const T_1 * V_5 ) ;
static const F_2 V_17 [ 4 ] = {
V_13 , V_14 ,
V_15 , V_16
} ;
F_2 V_18 = V_17 [ V_6 / 16 - 1 ] ;
if ( (* V_18) ( V_1 , V_2 , V_3 , V_4 , V_5 ) )
return 1 ;
if ( (* V_18) ( V_1 , V_2 , V_3 , V_4 , V_5 ) )
return 1 ;
return V_7 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
if ( ( V_10 [ 0 ] & V_19 ) )
return V_7 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
else if ( V_6 >= 8 &&
( V_10 [ 0 ] &
( V_20 | V_21 ) ) ==
( V_20 | V_21 ) )
return V_8 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
return V_9 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
unsigned long F_3 ( void )
{
if ( V_10 [ 0 ] & V_22 )
#if F_4 ( V_23 ) && F_4 ( V_24 )
return F_5 () ;
#else
return 0 ;
#endif
else
return F_6 () ;
}
T_2 F_7 ( unsigned int * V_25 , T_2 V_26 )
{
if ( ( V_10 [ 0 ] & ( V_22 | V_27 ) ) ==
V_27 )
return F_8 ( V_25 , V_26 ) ;
else
return 0 ;
}
T_2 F_9 ( unsigned int * V_25 , T_2 V_26 , T_2 V_28 )
{
if ( ( V_10 [ 0 ] & ( V_22 | V_27 ) ) ==
V_27 )
return F_10 ( V_25 , V_26 , V_28 ) ;
else
return 0 ;
}
static void F_11 ( int V_29 )
{
F_12 ( V_30 , V_29 ) ;
}
void F_13 ( void )
{
char * V_31 ;
struct V_32 V_33 , V_34 , V_35 ;
T_3 V_36 , V_37 ;
static int V_38 = 0 ;
if ( V_38 )
return;
V_38 = 1 ;
if ( ( V_31 = getenv ( L_1 ) ) ) {
V_10 [ 0 ] = strtoul ( V_31 , NULL , 0 ) ;
if ( ( V_31 = strchr ( V_31 , ':' ) ) )
V_10 [ 1 ] = strtoul ( V_31 + 1 , NULL , 0 ) ;
return;
}
V_10 [ 0 ] = V_20 | V_22 ;
F_14 ( & V_36 ) ;
F_15 ( & V_36 , V_39 ) ;
F_15 ( & V_36 , V_40 ) ;
# ifdef F_16
F_15 ( & V_36 , F_16 ) ;
# endif
F_15 ( & V_36 , V_41 ) ;
F_15 ( & V_36 , V_42 ) ;
F_15 ( & V_36 , V_43 ) ;
F_17 ( V_44 , & V_36 , & V_37 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_45 = F_11 ;
V_33 . V_46 = V_36 ;
V_32 ( V_39 , & V_33 , & V_34 ) ;
V_32 ( V_42 , & V_33 , & V_35 ) ;
if ( F_18 ( V_30 , 1 ) == 0 ) {
F_6 () ;
V_10 [ 0 ] &= ~ V_22 ;
}
if ( F_18 ( V_30 , 1 ) == 0 ) {
F_19 () ;
V_10 [ 0 ] |= V_21 | V_27 ;
if ( F_20 () >= 12 )
V_10 [ 0 ] &= ~ ( V_21 | V_20 ) ;
else {
F_21 () ;
V_10 [ 0 ] |= V_47 ;
}
}
if ( F_18 ( V_30 , 1 ) == 0 ) {
F_22 () ;
V_10 [ 0 ] |= V_48 ;
}
if ( F_18 ( V_30 , 1 ) == 0 ) {
F_23 () ;
V_10 [ 0 ] |= V_19 ;
}
# if 0
if (sigsetjmp(common_jmp, 1) == 0) {
(void)_sparcv9_random();
OPENSSL_sparcv9cap_P[0] |= SPARCV9_RANDOM;
}
# endif
if ( ( V_10 [ 0 ] & V_19 ) &&
F_18 ( V_30 , 1 ) == 0 ) {
V_10 [ 1 ] = ( unsigned int ) F_24 () ;
}
V_32 ( V_42 , & V_35 , NULL ) ;
V_32 ( V_39 , & V_34 , NULL ) ;
F_17 ( V_44 , & V_37 , NULL ) ;
if ( sizeof( T_2 ) == 8 )
V_10 [ 0 ] |= V_49 ;
# ifdef F_25
else {
int V_50 = F_26 ( 340 ) ;
if ( V_50 >= 0 && V_50 & 1 )
V_10 [ 0 ] |= V_49 ;
}
# endif
}
