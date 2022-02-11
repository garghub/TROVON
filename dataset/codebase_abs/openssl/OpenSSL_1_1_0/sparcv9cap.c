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
( ( V_10 [ 0 ] & V_20 ) ||
( V_10 [ 0 ] &
( V_21 | V_22 ) ) ==
( V_21 | V_22 ) ) )
return V_8 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
return V_9 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
unsigned long F_3 ( void )
{
if ( V_10 [ 0 ] & V_23 )
#if F_4 ( V_24 ) && F_4 ( V_25 )
return F_5 () ;
#else
return 0 ;
#endif
else
return F_6 () ;
}
T_2 F_7 ( unsigned int * V_26 , T_2 V_27 )
{
if ( ( V_10 [ 0 ] & ( V_23 | V_28 ) ) ==
V_28 )
return F_8 ( V_26 , V_27 ) ;
else
return 0 ;
}
T_2 F_9 ( unsigned int * V_26 , T_2 V_27 , T_2 V_29 )
{
if ( ( V_10 [ 0 ] & ( V_23 | V_28 ) ) ==
V_28 )
return F_10 ( V_26 , V_27 , V_29 ) ;
else
return 0 ;
}
static void F_11 ( int V_30 )
{
F_12 ( V_31 , V_30 ) ;
}
void F_13 ( void )
{
char * V_32 ;
struct V_33 V_34 , V_35 , V_36 ;
T_3 V_37 , V_38 ;
static int V_39 = 0 ;
if ( V_39 )
return;
V_39 = 1 ;
if ( ( V_32 = getenv ( L_1 ) ) ) {
V_10 [ 0 ] = strtoul ( V_32 , NULL , 0 ) ;
if ( ( V_32 = strchr ( V_32 , ':' ) ) )
V_10 [ 1 ] = strtoul ( V_32 + 1 , NULL , 0 ) ;
return;
}
#if F_4 ( V_24 ) && F_4 ( V_25 )
if ( V_40 != NULL ) {
unsigned int V_41 [ 2 ] = { 0 , 0 } ;
if ( V_40 ( V_41 , 2 ) ) {
if ( V_41 [ 0 ] & 0x00020 ) V_10 [ 0 ] |= V_22 ;
if ( V_41 [ 0 ] & 0x00040 ) V_10 [ 0 ] |= V_42 ;
if ( V_41 [ 0 ] & 0x00080 ) V_10 [ 0 ] |= V_28 ;
if ( V_41 [ 0 ] & 0x00100 ) V_10 [ 0 ] |= V_20 ;
if ( V_41 [ 0 ] & 0x00400 ) V_10 [ 0 ] |= V_19 ;
if ( V_41 [ 0 ] & 0x01000 ) V_10 [ 0 ] |= V_43 ;
if ( V_41 [ 0 ] & 0x02000 ) V_10 [ 0 ] |= V_44 ;
if ( V_41 [ 0 ] & 0x08000 ) V_10 [ 0 ] |= V_45 ;
if ( V_41 [ 0 ] & 0x10000 ) V_10 [ 0 ] |= V_46 ;
if ( V_41 [ 1 ] & 0x00008 ) V_10 [ 0 ] |= V_47 ;
V_10 [ 1 ] = ( V_41 [ 0 ] >> 17 ) & 0x3ff ;
V_10 [ 1 ] |= ( V_10 [ 1 ] & V_11 ) << 1 ;
if ( V_41 [ 0 ] & 0x20000000 ) V_10 [ 1 ] |= V_48 ;
if ( V_41 [ 1 ] & 0x00000020 ) V_10 [ 1 ] |= V_49 ;
if ( V_41 [ 1 ] & 0x00000040 )
V_10 [ 1 ] |= V_50 | V_51 ;
if ( V_10 [ 0 ] & V_42 )
V_10 [ 0 ] &= ~ V_23 ;
V_10 [ 0 ] |= V_21 ;
if ( ( V_10 [ 0 ] & V_22 ) &&
F_14 () >= 12 )
V_10 [ 0 ] &= ~ ( V_22 | V_21 ) ;
}
if ( sizeof( T_2 ) == 8 )
V_10 [ 0 ] |= V_52 ;
return;
}
#endif
V_10 [ 0 ] = V_21 | V_23 ;
F_15 ( & V_37 ) ;
F_16 ( & V_37 , V_53 ) ;
F_16 ( & V_37 , V_54 ) ;
# ifdef F_17
F_16 ( & V_37 , F_17 ) ;
# endif
F_16 ( & V_37 , V_55 ) ;
F_16 ( & V_37 , V_56 ) ;
F_16 ( & V_37 , V_57 ) ;
F_18 ( V_58 , & V_37 , & V_38 ) ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_59 = F_11 ;
V_34 . V_60 = V_37 ;
V_33 ( V_53 , & V_34 , & V_35 ) ;
V_33 ( V_56 , & V_34 , & V_36 ) ;
if ( F_19 ( V_31 , 1 ) == 0 ) {
F_6 () ;
V_10 [ 0 ] &= ~ V_23 ;
}
if ( F_19 ( V_31 , 1 ) == 0 ) {
F_20 () ;
V_10 [ 0 ] |= V_22 | V_28 ;
if ( F_14 () >= 12 )
V_10 [ 0 ] &= ~ ( V_22 | V_21 ) ;
else {
F_21 () ;
V_10 [ 0 ] |= V_42 ;
}
}
if ( F_19 ( V_31 , 1 ) == 0 ) {
F_22 () ;
V_10 [ 0 ] |= V_20 ;
}
if ( F_19 ( V_31 , 1 ) == 0 ) {
F_23 () ;
V_10 [ 0 ] |= V_19 ;
}
if ( F_19 ( V_31 , 1 ) == 0 ) {
F_24 () ;
V_10 [ 0 ] |= V_46 ;
}
if ( ( V_10 [ 0 ] & V_19 ) &&
F_19 ( V_31 , 1 ) == 0 ) {
V_10 [ 1 ] = ( unsigned int ) F_25 () ;
}
V_33 ( V_56 , & V_36 , NULL ) ;
V_33 ( V_53 , & V_35 , NULL ) ;
F_18 ( V_58 , & V_38 , NULL ) ;
if ( sizeof( T_2 ) == 8 )
V_10 [ 0 ] |= V_52 ;
# ifdef F_26
else {
int V_61 = F_27 ( 340 ) ;
if ( V_61 >= 0 && V_61 & 1 )
V_10 [ 0 ] |= V_52 ;
}
# endif
}
