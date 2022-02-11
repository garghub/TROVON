static int F_1 ( unsigned char V_1 )
{
if ( V_1 >= 'a' && V_1 <= 'f' )
return V_1 - 'a' + 10 ;
if ( V_1 >= '0' && V_1 <= '9' )
return V_1 - '0' ;
if ( V_1 >= 'A' && V_1 <= 'F' )
return V_1 - 'A' + 10 ;
return - 1 ;
}
void F_2 ( const char * V_2 , int V_3 )
{
F_3 ( V_2 , V_3 ) ;
}
void F_4 ( const char * V_4 , ... )
{
T_1 args ;
int V_5 ;
va_start ( args , V_4 ) ;
V_5 = vsnprintf ( V_6 , sizeof( V_6 ) , V_4 , args ) ;
va_end ( args ) ;
F_2 ( V_6 , V_5 ) ;
}
static inline char * F_5 ( char * V_7 , const char * V_8 )
{
int V_9 = 0 ;
while ( ( V_7 [ V_9 ] = V_8 [ V_9 ] ) )
V_9 ++ ;
return V_7 ;
}
static void F_6 ( char * V_10 )
{
unsigned char V_11 ;
unsigned char V_12 ;
unsigned char V_1 ;
int V_13 , V_14 , V_15 , error ;
for (; ; ) {
do {
F_7 ( & V_1 , 0 ) ;
} while ( V_1 != '$' );
V_11 = 0 ;
V_12 = - 1 ;
V_13 = 0 ;
error = 0 ;
while ( V_13 < V_16 ) {
V_15 = F_7 ( & V_1 , 0 ) ;
if ( V_15 < 0 )
error = V_15 ;
if ( V_1 == '#' )
break;
V_11 += V_1 ;
V_10 [ V_13 ] = V_1 ;
V_13 ++ ;
}
if ( error == - V_17 ) {
F_8 ( L_1
L_2 ) ;
F_8 ( L_3 ) ;
F_9 ( '-' ) ;
continue;
}
if ( V_13 >= V_16 || error )
continue;
V_10 [ V_13 ] = 0 ;
V_15 = F_7 ( & V_1 , 0 ) ;
if ( V_15 < 0 )
error = V_15 ;
V_12 = F_1 ( V_1 ) << 4 ;
V_15 = F_7 ( & V_1 , 0 ) ;
if ( V_15 < 0 )
error = V_15 ;
V_12 |= F_1 ( V_1 ) ;
if ( error ) {
if ( error == - V_17 )
F_10 ( L_4
L_5 ) ;
F_10 ( L_3 ) ;
F_9 ( '-' ) ;
continue;
}
if ( V_11 != V_12 ) {
F_10 ( L_3 ) ;
F_9 ( '-' ) ;
continue;
}
F_8 ( L_6 , V_10 , V_11 ) ;
F_10 ( L_7 ) ;
F_9 ( '+' ) ;
if ( V_10 [ 2 ] == ':' ) {
F_9 ( V_10 [ 0 ] ) ;
F_9 ( V_10 [ 1 ] ) ;
V_13 = 0 ;
while ( V_10 [ V_13 ] )
V_13 ++ ;
for ( V_14 = 3 ; V_14 <= V_13 ; V_14 ++ )
V_10 [ V_14 - 3 ] = V_10 [ V_14 ] ;
}
break;
}
}
static int F_11 ( char * V_10 )
{
unsigned char V_11 ;
unsigned char V_1 ;
int V_13 ;
F_8 ( L_8 , V_10 ) ;
do {
F_9 ( '$' ) ;
V_11 = 0 ;
V_13 = 0 ;
while ( ( V_1 = V_10 [ V_13 ] ) != 0 ) {
F_9 ( V_1 ) ;
V_11 += V_1 ;
V_13 += 1 ;
}
F_9 ( '#' ) ;
F_9 ( F_12 ( V_11 ) ) ;
F_9 ( F_13 ( V_11 ) ) ;
} while ( F_7 ( & V_1 , 0 ) ,
V_1 == '-' && ( F_10 ( L_9 ) , 0 ) ,
V_1 != '-' && V_1 != '+' &&
( F_10 ( L_10 , V_1 ) , 0 ) ,
V_1 != '+' && V_1 != '$' );
if ( V_1 == '+' ) {
F_10 ( L_11 ) ;
return 0 ;
}
F_10 ( L_12 ) ;
V_18 = V_1 ;
return 1 ;
}
static int F_14 ( char * * V_19 , int * V_20 )
{
int V_21 = 0 ;
int V_22 ;
* V_20 = 0 ;
while ( * * V_19 ) {
V_22 = F_1 ( * * V_19 ) ;
if ( V_22 < 0 )
break;
* V_20 = ( * V_20 << 4 ) | V_22 ;
V_21 ++ ;
( * V_19 ) ++ ;
}
return ( V_21 ) ;
}
static int F_15 ( T_2 * V_23 , int V_24 )
{
if ( ( ( T_2 * ) V_25 <= V_23 ) && ( V_23 < ( T_2 * ) V_26 ) )
goto V_27;
if ( ( ( T_2 * ) 0x80000000UL <= V_23 ) && ( V_23 < ( T_2 * ) 0xa0000000UL ) )
goto V_27;
return 0 ;
V_27:
if ( F_16 ( V_23 + 0 , & V_28 [ V_24 ] . V_29 [ 0 ] ) < 0 ||
F_16 ( V_23 + 1 , & V_28 [ V_24 ] . V_29 [ 1 ] ) < 0 )
return 0 ;
V_28 [ V_24 ] . V_23 = V_23 ;
return 1 ;
}
static inline void F_17 ( void )
{
#ifdef F_18
if ( V_28 [ 0 ] . V_23 ) {
F_19 ( V_28 [ 0 ] . V_29 [ 0 ] , V_28 [ 0 ] . V_23 + 0 ) ;
F_19 ( V_28 [ 0 ] . V_29 [ 1 ] , V_28 [ 0 ] . V_23 + 1 ) ;
}
if ( V_28 [ 1 ] . V_23 ) {
F_19 ( V_28 [ 1 ] . V_29 [ 0 ] , V_28 [ 1 ] . V_23 + 0 ) ;
F_19 ( V_28 [ 1 ] . V_29 [ 1 ] , V_28 [ 1 ] . V_23 + 1 ) ;
}
#else
if ( V_28 [ 0 ] . V_23 )
F_19 ( V_28 [ 0 ] . V_29 [ 0 ] , V_28 [ 0 ] . V_23 + 0 ) ;
if ( V_28 [ 1 ] . V_23 )
F_19 ( V_28 [ 1 ] . V_29 [ 0 ] , V_28 [ 1 ] . V_23 + 0 ) ;
#endif
V_30 = 1 ;
V_28 [ 0 ] . V_23 = NULL ;
V_28 [ 0 ] . V_29 [ 0 ] = 0 ;
V_28 [ 0 ] . V_29 [ 1 ] = 0 ;
V_28 [ 1 ] . V_23 = NULL ;
V_28 [ 1 ] . V_29 [ 0 ] = 0 ;
V_28 [ 1 ] . V_29 [ 1 ] = 0 ;
}
static int F_20 ( struct V_31 * V_32 )
{
unsigned V_33 ;
T_3 V_34 ;
T_4 V_35 , * V_36 , * V_37 ;
V_28 [ 0 ] . V_23 = NULL ;
V_28 [ 0 ] . V_29 [ 0 ] = 0 ;
V_28 [ 0 ] . V_29 [ 1 ] = 0 ;
V_28 [ 1 ] . V_23 = NULL ;
V_28 [ 1 ] . V_29 [ 0 ] = 0 ;
V_28 [ 1 ] . V_29 [ 1 ] = 0 ;
V_34 = 0 ;
V_36 = ( T_2 * ) V_32 -> V_36 ;
V_37 = ( T_2 * ) ( V_32 + 1 ) ;
if ( F_16 ( V_36 , & V_35 ) < 0 )
return - V_38 ;
F_21 ( L_13 , V_36 , V_35 ) ;
V_30 = 1 ;
V_33 = V_39 [ V_35 ] ;
if ( V_33 > 0 ) {
if ( ! F_15 ( V_36 + V_33 , 0 ) )
goto V_40;
} else {
switch ( V_35 ) {
case 0xc0 ... 0xca :
if ( F_16 ( V_36 + 1 , ( T_2 * ) & V_34 ) < 0 )
goto V_40;
if ( ! F_15 ( V_36 + 2 , 0 ) )
goto V_40;
if ( ( V_34 < 0 || V_34 > 2 ) &&
! F_15 ( V_36 + ( V_41 ) V_34 , 1 ) )
goto V_40;
break;
case 0xd0 ... 0xda :
if ( ! F_15 ( V_36 + 1 , 0 ) )
goto V_40;
if ( V_32 -> V_36 != V_32 -> V_42 &&
! F_15 ( ( T_2 * ) V_32 -> V_42 , 1 ) )
goto V_40;
break;
case 0xdb :
if ( ! F_15 ( V_36 + 1 , 0 ) )
goto V_40;
break;
case 0xcc :
case 0xcd :
if ( F_16 ( V_36 + 1 , ( ( T_2 * ) & V_34 ) + 0 ) < 0 ||
F_16 ( V_36 + 2 , ( ( T_2 * ) & V_34 ) + 1 ) < 0 )
goto V_40;
if ( ! F_15 ( V_36 + ( V_43 ) V_34 , 0 ) )
goto V_40;
break;
case 0xdc :
case 0xdd :
if ( F_16 ( V_36 + 1 , ( ( T_2 * ) & V_34 ) + 0 ) < 0 ||
F_16 ( V_36 + 2 , ( ( T_2 * ) & V_34 ) + 1 ) < 0 ||
F_16 ( V_36 + 3 , ( ( T_2 * ) & V_34 ) + 2 ) < 0 ||
F_16 ( V_36 + 4 , ( ( T_2 * ) & V_34 ) + 3 ) < 0 )
goto V_40;
if ( ! F_15 ( V_36 + ( V_44 ) V_34 , 0 ) )
goto V_40;
break;
case 0xde :
if ( ! F_15 ( ( T_2 * ) V_32 -> V_45 , 0 ) )
goto V_40;
break;
case 0xdf :
if ( F_16 ( V_36 + 2 , ( T_2 * ) & V_34 ) < 0 )
goto V_40;
V_37 += ( V_41 ) V_34 ;
if ( F_16 ( V_37 + 0 , ( ( T_2 * ) & V_34 ) + 0 ) < 0 ||
F_16 ( V_37 + 1 , ( ( T_2 * ) & V_34 ) + 1 ) < 0 ||
F_16 ( V_37 + 2 , ( ( T_2 * ) & V_34 ) + 2 ) < 0 ||
F_16 ( V_37 + 3 , ( ( T_2 * ) & V_34 ) + 3 ) < 0 )
goto V_40;
if ( ! F_15 ( ( T_2 * ) V_34 , 0 ) )
goto V_40;
break;
case 0xf0 :
if ( F_16 ( V_36 + 1 , & V_35 ) < 0 )
goto V_40;
if ( V_35 >= 0xf0 && V_35 <= 0xf7 ) {
switch ( V_35 & 3 ) {
case 0 : V_34 = V_32 -> V_46 ; break;
case 1 : V_34 = V_32 -> V_47 ; break;
case 2 : V_34 = V_32 -> V_48 ; break;
case 3 : V_34 = V_32 -> V_49 ; break;
}
if ( ! F_15 ( ( T_2 * ) V_34 , 0 ) )
goto V_40;
} else if ( V_35 == 0xfc ) {
if ( F_16 (
V_37 + 0 , ( ( T_2 * ) & V_34 ) + 0 ) < 0 ||
F_16 (
V_37 + 1 , ( ( T_2 * ) & V_34 ) + 1 ) < 0 ||
F_16 (
V_37 + 2 , ( ( T_2 * ) & V_34 ) + 2 ) < 0 ||
F_16 (
V_37 + 3 , ( ( T_2 * ) & V_34 ) + 3 ) < 0 )
goto V_40;
if ( ! F_15 ( ( T_2 * ) V_34 , 0 ) )
goto V_40;
} else if ( V_35 == 0xfd ) {
if ( F_16 (
V_37 + 4 , ( ( T_2 * ) & V_34 ) + 0 ) < 0 ||
F_16 (
V_37 + 5 , ( ( T_2 * ) & V_34 ) + 1 ) < 0 ||
F_16 (
V_37 + 6 , ( ( T_2 * ) & V_34 ) + 2 ) < 0 ||
F_16 (
V_37 + 7 , ( ( T_2 * ) & V_34 ) + 3 ) < 0 )
goto V_40;
if ( ! F_15 ( ( T_2 * ) V_34 , 0 ) )
goto V_40;
} else {
if ( ! F_15 ( V_36 + 2 , 0 ) )
goto V_40;
}
break;
case 0xf8 :
if ( F_16 ( V_36 + 1 , & V_35 ) < 0 )
goto V_40;
if ( ! F_15 ( V_36 + 3 , 0 ) )
goto V_40;
if ( V_35 >= 0xe8 && V_35 <= 0xeb ) {
if ( F_16 (
V_36 + 2 , ( ( T_2 * ) & V_34 ) + 0 ) < 0 )
goto V_40;
if ( ( V_34 < 0 || V_34 > 3 ) &&
! F_15 ( V_36 + ( V_41 ) V_34 , 1 ) )
goto V_40;
}
break;
case 0xfa :
if ( F_16 ( V_36 + 1 , & V_35 ) < 0 )
goto V_40;
if ( V_35 == 0xff ) {
if ( F_16 (
V_36 + 2 , ( ( T_2 * ) & V_34 ) + 0 ) < 0 ||
F_16 (
V_36 + 3 , ( ( T_2 * ) & V_34 ) + 1 ) < 0 )
goto V_40;
if ( ! F_15 ( V_36 + ( V_43 ) V_34 , 0 ) )
goto V_40;
} else {
if ( ! F_15 ( V_36 + 4 , 0 ) )
goto V_40;
}
break;
case 0xfc :
if ( F_16 ( V_36 + 1 , & V_35 ) < 0 )
goto V_40;
if ( V_35 == 0xff ) {
if ( F_16 (
V_36 + 2 , ( ( T_2 * ) & V_34 ) + 0 ) < 0 ||
F_16 (
V_36 + 3 , ( ( T_2 * ) & V_34 ) + 1 ) < 0 ||
F_16 (
V_36 + 4 , ( ( T_2 * ) & V_34 ) + 2 ) < 0 ||
F_16 (
V_36 + 5 , ( ( T_2 * ) & V_34 ) + 3 ) < 0 )
goto V_40;
if ( ! F_15 (
V_36 + ( V_44 ) V_34 , 0 ) )
goto V_40;
} else {
if ( ! F_15 (
V_36 + 6 , 0 ) )
goto V_40;
}
break;
}
}
F_21 ( L_14 ,
V_28 [ 0 ] . V_29 [ 0 ] , V_28 [ 0 ] . V_23 ,
V_28 [ 1 ] . V_29 [ 0 ] , V_28 [ 1 ] . V_23 ) ;
if ( V_28 [ 0 ] . V_23 ) {
#ifdef F_18
if ( F_19 ( 0xF7 , V_28 [ 0 ] . V_23 + 0 ) < 0 ||
F_19 ( 0xF7 , V_28 [ 0 ] . V_23 + 1 ) < 0 )
goto V_40;
#else
if ( F_19 ( 0xFF , V_28 [ 0 ] . V_23 + 0 ) < 0 )
goto V_40;
#endif
}
if ( V_28 [ 1 ] . V_23 ) {
#ifdef F_18
if ( F_19 ( 0xF7 , V_28 [ 1 ] . V_23 + 0 ) < 0 ||
F_19 ( 0xF7 , V_28 [ 1 ] . V_23 + 1 ) < 0 )
goto V_40;
#else
if ( F_19 ( 0xFF , V_28 [ 1 ] . V_23 + 0 ) < 0 )
goto V_40;
#endif
}
return 0 ;
V_40:
F_17 () ;
return - V_38 ;
}
void F_22 ( struct V_50 * V_51 , const char * V_2 , unsigned V_3 )
{
static const char V_52 [] = { 0x0d } ;
char V_53 [ 26 ] ;
int V_54 ;
T_2 V_55 ;
V_55 = V_56 ;
V_56 = 1 ;
V_53 [ 0 ] = 'O' ;
while ( V_3 > 0 ) {
V_54 = 1 ;
while ( V_3 > 0 && V_54 < 20 ) {
F_23 ( V_2 , V_53 + V_54 , 2 , 0 ) ;
V_54 += 2 ;
if ( * V_2 == 0x0a ) {
F_23 ( V_52 , V_53 + V_54 , 2 , 0 ) ;
V_54 += 2 ;
}
V_2 ++ ;
V_3 -- ;
}
V_53 [ V_54 ] = 0 ;
F_11 ( V_53 ) ;
}
V_56 = V_55 ;
}
static T_5 F_24 ( struct V_50 * V_51 )
{
return F_25 ( 1 , 3 ) ;
}
static
unsigned char * F_23 ( const void * V_57 , char * V_58 , int V_13 , int V_59 )
{
const T_2 * V_60 = V_57 ;
T_2 V_1 [ 4 ] ;
if ( ( V_61 ) V_60 & 1 && V_13 >= 1 ) {
if ( F_16 ( V_60 , V_1 ) != 0 )
return 0 ;
V_58 = F_26 ( V_58 , V_1 [ 0 ] ) ;
V_60 ++ ;
V_13 -- ;
}
if ( ( V_61 ) V_60 & 3 && V_13 >= 2 ) {
if ( F_27 ( V_60 , V_1 ) != 0 )
return 0 ;
V_58 = F_26 ( V_58 , V_1 [ 0 ] ) ;
V_58 = F_26 ( V_58 , V_1 [ 1 ] ) ;
V_60 += 2 ;
V_13 -= 2 ;
}
while ( V_13 >= 4 ) {
if ( F_28 ( V_60 , V_1 ) != 0 )
return 0 ;
V_58 = F_26 ( V_58 , V_1 [ 0 ] ) ;
V_58 = F_26 ( V_58 , V_1 [ 1 ] ) ;
V_58 = F_26 ( V_58 , V_1 [ 2 ] ) ;
V_58 = F_26 ( V_58 , V_1 [ 3 ] ) ;
V_60 += 4 ;
V_13 -= 4 ;
}
if ( V_13 >= 2 ) {
if ( F_27 ( V_60 , V_1 ) != 0 )
return 0 ;
V_58 = F_26 ( V_58 , V_1 [ 0 ] ) ;
V_58 = F_26 ( V_58 , V_1 [ 1 ] ) ;
V_60 += 2 ;
V_13 -= 2 ;
}
if ( V_13 >= 1 ) {
if ( F_16 ( V_60 , V_1 ) != 0 )
return 0 ;
V_58 = F_26 ( V_58 , V_1 [ 0 ] ) ;
}
* V_58 = 0 ;
return V_58 ;
}
static
const char * F_29 ( const char * V_58 , void * V_57 , int V_13 , int V_59 )
{
T_2 * V_60 = V_57 ;
union {
V_61 V_62 ;
T_2 V_63 [ 4 ] ;
} V_1 ;
if ( ( V_61 ) V_60 & 1 && V_13 >= 1 ) {
V_1 . V_63 [ 0 ] = F_1 ( * V_58 ++ ) << 4 ;
V_1 . V_63 [ 0 ] |= F_1 ( * V_58 ++ ) ;
if ( F_19 ( V_1 . V_62 , V_60 ) != 0 )
return 0 ;
V_60 ++ ;
V_13 -- ;
}
if ( ( V_61 ) V_60 & 3 && V_13 >= 2 ) {
V_1 . V_63 [ 0 ] = F_1 ( * V_58 ++ ) << 4 ;
V_1 . V_63 [ 0 ] |= F_1 ( * V_58 ++ ) ;
V_1 . V_63 [ 1 ] = F_1 ( * V_58 ++ ) << 4 ;
V_1 . V_63 [ 1 ] |= F_1 ( * V_58 ++ ) ;
if ( F_30 ( V_1 . V_62 , V_60 ) != 0 )
return 0 ;
V_60 += 2 ;
V_13 -= 2 ;
}
while ( V_13 >= 4 ) {
V_1 . V_63 [ 0 ] = F_1 ( * V_58 ++ ) << 4 ;
V_1 . V_63 [ 0 ] |= F_1 ( * V_58 ++ ) ;
V_1 . V_63 [ 1 ] = F_1 ( * V_58 ++ ) << 4 ;
V_1 . V_63 [ 1 ] |= F_1 ( * V_58 ++ ) ;
V_1 . V_63 [ 2 ] = F_1 ( * V_58 ++ ) << 4 ;
V_1 . V_63 [ 2 ] |= F_1 ( * V_58 ++ ) ;
V_1 . V_63 [ 3 ] = F_1 ( * V_58 ++ ) << 4 ;
V_1 . V_63 [ 3 ] |= F_1 ( * V_58 ++ ) ;
if ( F_31 ( V_1 . V_62 , V_60 ) != 0 )
return 0 ;
V_60 += 4 ;
V_13 -= 4 ;
}
if ( V_13 >= 2 ) {
V_1 . V_63 [ 0 ] = F_1 ( * V_58 ++ ) << 4 ;
V_1 . V_63 [ 0 ] |= F_1 ( * V_58 ++ ) ;
V_1 . V_63 [ 1 ] = F_1 ( * V_58 ++ ) << 4 ;
V_1 . V_63 [ 1 ] |= F_1 ( * V_58 ++ ) ;
if ( F_30 ( V_1 . V_62 , V_60 ) != 0 )
return 0 ;
V_60 += 2 ;
V_13 -= 2 ;
}
if ( V_13 >= 1 ) {
V_1 . V_63 [ 0 ] = F_1 ( * V_58 ++ ) << 4 ;
V_1 . V_63 [ 0 ] |= F_1 ( * V_58 ++ ) ;
if ( F_19 ( V_1 . V_62 , V_60 ) != 0 )
return 0 ;
}
return V_58 ;
}
static int F_32 ( enum V_64 V_65 )
{
const struct V_66 * V_67 ;
for ( V_67 = V_66 ; V_67 -> V_68 ; V_67 ++ )
if ( V_67 -> V_65 == V_65 )
return V_67 -> V_68 ;
return V_69 ;
}
static void F_33 ( void )
{
#ifdef F_34
asm volatile(
"or %2,epsw\n"
#ifdef F_35
"nop\n"
"nop\n"
#endif
"mov %1, a1\n"
"fmov fs0, (a1+)\n"
"fmov fs1, (a1+)\n"
"fmov fs2, (a1+)\n"
"fmov fs3, (a1+)\n"
"fmov fs4, (a1+)\n"
"fmov fs5, (a1+)\n"
"fmov fs6, (a1+)\n"
"fmov fs7, (a1+)\n"
"fmov fs8, (a1+)\n"
"fmov fs9, (a1+)\n"
"fmov fs10, (a1+)\n"
"fmov fs11, (a1+)\n"
"fmov fs12, (a1+)\n"
"fmov fs13, (a1+)\n"
"fmov fs14, (a1+)\n"
"fmov fs15, (a1+)\n"
"fmov fs16, (a1+)\n"
"fmov fs17, (a1+)\n"
"fmov fs18, (a1+)\n"
"fmov fs19, (a1+)\n"
"fmov fs20, (a1+)\n"
"fmov fs21, (a1+)\n"
"fmov fs22, (a1+)\n"
"fmov fs23, (a1+)\n"
"fmov fs24, (a1+)\n"
"fmov fs25, (a1+)\n"
"fmov fs26, (a1+)\n"
"fmov fs27, (a1+)\n"
"fmov fs28, (a1+)\n"
"fmov fs29, (a1+)\n"
"fmov fs30, (a1+)\n"
"fmov fs31, (a1+)\n"
"fmov fpcr, %0\n"
: "=d"(gdbstub_fpcr)
: "g" (&gdbstub_fpufs_array), "i"(EPSW_FE)
: "a1"
);
#endif
}
static void F_36 ( void )
{
#ifdef F_34
asm volatile(
"or %1,epsw\n"
#ifdef F_35
"nop\n"
"nop\n"
#endif
"mov %0, a1\n"
"fmov (a1+), fs0\n"
"fmov (a1+), fs1\n"
"fmov (a1+), fs2\n"
"fmov (a1+), fs3\n"
"fmov (a1+), fs4\n"
"fmov (a1+), fs5\n"
"fmov (a1+), fs6\n"
"fmov (a1+), fs7\n"
"fmov (a1+), fs8\n"
"fmov (a1+), fs9\n"
"fmov (a1+), fs10\n"
"fmov (a1+), fs11\n"
"fmov (a1+), fs12\n"
"fmov (a1+), fs13\n"
"fmov (a1+), fs14\n"
"fmov (a1+), fs15\n"
"fmov (a1+), fs16\n"
"fmov (a1+), fs17\n"
"fmov (a1+), fs18\n"
"fmov (a1+), fs19\n"
"fmov (a1+), fs20\n"
"fmov (a1+), fs21\n"
"fmov (a1+), fs22\n"
"fmov (a1+), fs23\n"
"fmov (a1+), fs24\n"
"fmov (a1+), fs25\n"
"fmov (a1+), fs26\n"
"fmov (a1+), fs27\n"
"fmov (a1+), fs28\n"
"fmov (a1+), fs29\n"
"fmov (a1+), fs30\n"
"fmov (a1+), fs31\n"
"fmov %2, fpcr\n"
:
: "g" (&gdbstub_fpufs_array), "i"(EPSW_FE), "d"(gdbstub_fpcr)
: "a1"
);
#endif
}
int F_37 ( T_2 * V_23 , int V_5 )
{
int V_70 , V_9 , V_71 ;
#ifdef F_18
V_5 = ( V_5 + 1 ) & ~ 1 ;
#endif
F_21 ( L_15 , V_23 , V_5 ) ;
for ( V_70 = 255 ; V_70 >= 0 ; V_70 -- )
if ( ! V_72 [ V_70 ] . V_23 )
break;
if ( V_70 < 0 )
return - V_73 ;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 ++ )
if ( F_16 ( & V_23 [ V_9 ] ,
& V_72 [ V_70 ] . V_74 [ V_9 ]
) < 0 )
return - V_38 ;
V_30 = 1 ;
#ifdef F_18
for ( V_9 = 0 ; V_9 < V_5 ; V_9 ++ )
if ( F_19 ( 0xF7 , & V_23 [ V_9 ] ) < 0 )
goto V_75;
#else
for ( V_9 = 0 ; V_9 < V_5 ; V_9 ++ )
if ( F_19 ( 0xFF , & V_23 [ V_9 ] ) < 0 )
goto V_75;
#endif
V_72 [ V_70 ] . V_23 = V_23 ;
V_72 [ V_70 ] . V_5 = V_5 ;
F_21 ( L_16 ,
V_70 ,
V_72 [ V_70 ] . V_23 ,
V_72 [ V_70 ] . V_23 + V_72 [ V_70 ] . V_5 - 1 ,
V_72 [ V_70 ] . V_74 [ 0 ] ,
V_72 [ V_70 ] . V_74 [ 1 ] ,
V_72 [ V_70 ] . V_74 [ 2 ] ,
V_72 [ V_70 ] . V_74 [ 3 ] ,
V_72 [ V_70 ] . V_74 [ 4 ] ,
V_72 [ V_70 ] . V_74 [ 5 ] ,
V_72 [ V_70 ] . V_74 [ 6 ]
) ;
return 0 ;
V_75:
for ( V_71 = 0 ; V_71 < V_9 ; V_71 ++ )
F_19 ( V_72 [ V_70 ] . V_74 [ V_71 ] ,
V_23 + V_71 ) ;
return - V_38 ;
}
int F_38 ( T_2 * V_23 , int V_5 )
{
int V_70 , V_9 ;
#ifdef F_18
V_5 = ( V_5 + 1 ) & ~ 1 ;
#endif
F_21 ( L_17 , V_23 , V_5 ) ;
for ( V_70 = 255 ; V_70 >= 0 ; V_70 -- )
if ( V_72 [ V_70 ] . V_23 == V_23 &&
V_72 [ V_70 ] . V_5 == V_5 )
break;
if ( V_70 < 0 )
return - V_76 ;
V_72 [ V_70 ] . V_23 = NULL ;
V_30 = 1 ;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 ++ )
if ( F_19 ( V_72 [ V_70 ] . V_74 [ V_9 ] ,
V_23 + V_9 ) < 0 )
return - V_38 ;
return 0 ;
}
static int F_39 ( struct V_31 * V_32 , enum V_64 V_65 )
{
unsigned long * V_77 ;
unsigned long V_78 , V_45 ;
T_3 V_79 , V_80 ;
T_4 V_81 ;
char * V_19 ;
int V_82 ;
int V_23 ;
int V_83 ;
int V_9 ;
if ( V_65 == V_84 )
return - V_85 ;
V_30 = 0 ;
F_40 ( 1 ) ;
asm volatile("mov mdr,%0" : "=d"(mdr));
F_41 ( V_78 ) ;
F_42 (
F_43 ( V_86 + 1 ) ) ;
F_33 () ;
#ifdef F_44
if ( V_32 -> V_36 == ( unsigned long ) V_87 )
V_32 -> V_36 = ( unsigned long ) V_88 ;
#endif
V_81 = 0 ;
#ifdef F_45
if ( ( V_28 [ 0 ] . V_23 && V_28 [ 0 ] . V_23 == ( T_2 * ) V_32 -> V_36 ) ||
( V_28 [ 1 ] . V_23 && V_28 [ 1 ] . V_23 == ( T_2 * ) V_32 -> V_36 ) )
V_81 = 1 ;
F_17 () ;
#endif
if ( V_18 ) {
V_82 = V_89 ;
if ( V_18 != 3 )
goto V_90;
V_18 = 0 ;
}
V_77 = ( unsigned long * ) V_32 -> V_37 ;
V_82 = V_81 ? V_91 : F_32 ( V_65 ) ;
if ( ! F_46 ( V_32 ) && V_65 == V_92 ) {
const struct V_93 * V_94 ;
V_94 = F_47 ( V_32 -> V_36 ) ;
if ( V_94 )
goto V_95;
V_83 = snprintf ( V_6 , sizeof( V_6 ) ,
L_18 , V_32 -> V_36 ) ;
goto V_96;
V_95:
V_83 = snprintf ( V_6 , sizeof( V_6 ) ,
L_19 ,
V_32 -> V_36 , V_94 -> V_97 , V_94 -> line ) ;
V_96:
V_19 = V_98 ;
* V_19 ++ = 'O' ;
V_19 = F_23 ( V_6 , V_19 , V_83 , 0 ) ;
* V_19 = 0 ;
F_11 ( V_98 ) ;
V_32 -> V_36 -= 2 ;
V_82 = V_99 ;
} else if ( V_32 -> V_36 == ( unsigned long ) V_100 ) {
V_32 -> V_36 = V_32 -> V_45 ;
V_82 = V_99 ;
}
if ( V_82 != V_89 && V_82 != V_91 && V_82 != V_101 ) {
static const char V_102 [] = L_20 , V_103 [] = L_21 ;
static const char V_104 [] = L_22 ;
char V_105 ;
V_61 V_106 = V_107 ;
V_19 = V_98 ;
* V_19 ++ = 'O' ;
V_19 = F_23 ( V_102 , V_19 , sizeof( V_102 ) - 1 , 0 ) ;
V_105 = F_12 ( V_65 >> 8 ) ;
V_19 = F_26 ( V_19 , V_105 ) ;
V_105 = F_13 ( V_65 >> 8 ) ;
V_19 = F_26 ( V_19 , V_105 ) ;
V_105 = F_12 ( V_65 ) ;
V_19 = F_26 ( V_19 , V_105 ) ;
V_105 = F_13 ( V_65 ) ;
V_19 = F_26 ( V_19 , V_105 ) ;
V_19 = F_23 ( V_104 , V_19 , sizeof( V_104 ) - 1 , 0 ) ;
* V_19 = 0 ;
F_11 ( V_98 ) ;
V_19 = V_98 ;
* V_19 ++ = 'O' ;
V_19 = F_23 ( V_103 , V_19 , sizeof( V_103 ) - 1 , 0 ) ;
V_105 = F_12 ( V_106 >> 24 ) ;
V_19 = F_26 ( V_19 , V_105 ) ;
V_105 = F_13 ( V_106 >> 24 ) ;
V_19 = F_26 ( V_19 , V_105 ) ;
V_105 = F_12 ( V_106 >> 16 ) ;
V_19 = F_26 ( V_19 , V_105 ) ;
V_105 = F_13 ( V_106 >> 16 ) ;
V_19 = F_26 ( V_19 , V_105 ) ;
V_105 = F_12 ( V_106 >> 8 ) ;
V_19 = F_26 ( V_19 , V_105 ) ;
V_105 = F_13 ( V_106 >> 8 ) ;
V_19 = F_26 ( V_19 , V_105 ) ;
V_105 = F_12 ( V_106 ) ;
V_19 = F_26 ( V_19 , V_105 ) ;
V_105 = F_13 ( V_106 ) ;
V_19 = F_26 ( V_19 , V_105 ) ;
V_19 = F_23 ( V_104 , V_19 , sizeof( V_104 ) - 1 , 0 ) ;
* V_19 = 0 ;
F_11 ( V_98 ) ;
}
V_19 = V_98 ;
* V_19 ++ = 'T' ;
V_19 = F_26 ( V_19 , V_82 ) ;
V_19 = F_26 ( V_19 , V_108 ) ;
* V_19 ++ = ':' ;
V_19 = F_23 ( & V_32 -> V_36 , V_19 , 4 , 0 ) ;
* V_19 ++ = ';' ;
V_19 = F_26 ( V_19 , V_109 ) ;
* V_19 ++ = ':' ;
V_19 = F_23 ( & V_32 -> V_49 , V_19 , 4 , 0 ) ;
* V_19 ++ = ';' ;
V_80 = ( unsigned long ) ( V_32 + 1 ) ;
V_19 = F_26 ( V_19 , V_110 ) ;
* V_19 ++ = ':' ;
V_19 = F_23 ( & V_80 , V_19 , 4 , 0 ) ;
* V_19 ++ = ';' ;
* V_19 ++ = 0 ;
F_11 ( V_98 ) ;
V_90:
while ( 1 ) {
V_98 [ 0 ] = 0 ;
F_6 ( V_111 ) ;
switch ( V_111 [ 0 ] ) {
case '?' :
V_98 [ 0 ] = 'S' ;
V_98 [ 1 ] = F_12 ( V_82 ) ;
V_98 [ 2 ] = F_13 ( V_82 ) ;
V_98 [ 3 ] = 0 ;
break;
case 'd' :
break;
case 'g' :
V_79 = 0 ;
V_80 = ( V_61 ) ( V_32 + 1 ) ;
V_19 = V_98 ;
V_19 = F_23 ( & V_32 -> V_112 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_113 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_114 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_115 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_46 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_47 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_48 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_49 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_80 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_36 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_45 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_78 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_116 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_42 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_117 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_118 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_119 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_120 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_121 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_122 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_123 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_124 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_125 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_80 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_37 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_126 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_127 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_32 -> V_128 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_129 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_79 , V_19 , 4 , 0 ) ;
V_19 = F_23 ( & V_79 , V_19 , 4 , 0 ) ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ )
V_19 = F_23 ( & V_130 [ V_9 ] ,
V_19 , 4 , 0 ) ;
break;
case 'G' :
{
const char * V_19 ;
V_19 = & V_111 [ 1 ] ;
V_19 = F_29 ( V_19 , & V_32 -> V_112 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_113 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_114 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_115 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_46 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_47 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_48 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_49 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_80 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_36 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_45 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_78 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_116 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_42 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_117 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_118 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_119 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_120 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_121 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_122 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_123 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_124 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_125 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_80 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_79 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_37 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_126 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_127 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_32 -> V_128 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_79 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_79 , 4 , 0 ) ;
V_19 = F_29 ( V_19 , & V_79 , 4 , 0 ) ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ )
V_19 = F_29 ( V_19 , & V_79 , 4 , 0 ) ;
#if 0
unsigned long *newsp = (unsigned long *) registers[SP];
if (sp != newsp)
sp = memcpy(newsp, sp, 16 * 4);
#endif
F_5 ( V_98 , L_23 ) ;
}
break;
case 'm' :
V_19 = & V_111 [ 1 ] ;
if ( F_14 ( & V_19 , & V_23 ) &&
* V_19 ++ == ',' &&
F_14 ( & V_19 , & V_83 )
) {
if ( F_23 ( ( char * ) V_23 , V_98 ,
V_83 , 1 ) )
break;
F_5 ( V_98 , L_24 ) ;
} else {
F_5 ( V_98 , L_25 ) ;
}
break;
case 'M' :
V_19 = & V_111 [ 1 ] ;
if ( F_14 ( & V_19 , & V_23 ) &&
* V_19 ++ == ',' &&
F_14 ( & V_19 , & V_83 ) &&
* V_19 ++ == ':'
) {
if ( F_29 ( V_19 , ( char * ) V_23 , V_83 , 1 ) )
F_5 ( V_98 , L_23 ) ;
else
F_5 ( V_98 , L_24 ) ;
V_30 = 1 ;
} else {
F_5 ( V_98 , L_26 ) ;
}
break;
case 'c' :
V_19 = & V_111 [ 1 ] ;
if ( F_14 ( & V_19 , & V_23 ) )
V_32 -> V_36 = V_23 ;
goto V_131;
case 'k' :
goto V_131;
case 'r' :
break;
case 's' :
#ifdef F_45
if ( F_20 ( V_32 ) < 0 )
F_4 ( L_27
L_28 ) ;
goto V_131;
#else
F_5 ( V_98 , L_25 ) ;
break;
#endif
case 'b' :
do {
int V_132 ;
V_19 = & V_111 [ 1 ] ;
if ( ! F_14 ( & V_19 , & V_132 ) ) {
F_5 ( V_98 , L_29 ) ;
break;
}
if ( V_132 ) {
F_11 ( L_23 ) ;
F_48 ( V_132 ) ;
}
} while ( 0 );
break;
case 'Z' :
V_19 = & V_111 [ 1 ] ;
if ( ! F_14 ( & V_19 , & V_9 ) || * V_19 ++ != ',' ||
! F_14 ( & V_19 , & V_23 ) || * V_19 ++ != ',' ||
! F_14 ( & V_19 , & V_83 )
) {
F_5 ( V_98 , L_25 ) ;
break;
}
F_5 ( V_98 , L_24 ) ;
if ( V_9 != 0 ||
V_83 < 1 ||
V_83 > 7 ||
( unsigned long ) V_23 < 4096 )
break;
if ( F_37 ( ( T_2 * ) V_23 , V_83 ) < 0 )
break;
F_5 ( V_98 , L_23 ) ;
break;
case 'z' :
V_19 = & V_111 [ 1 ] ;
if ( ! F_14 ( & V_19 , & V_9 ) || * V_19 ++ != ',' ||
! F_14 ( & V_19 , & V_23 ) || * V_19 ++ != ',' ||
! F_14 ( & V_19 , & V_83 )
) {
F_5 ( V_98 , L_25 ) ;
break;
}
F_5 ( V_98 , L_24 ) ;
if ( V_9 != 0 ||
V_83 < 1 ||
V_83 > 7 ||
( unsigned long ) V_23 < 4096 )
break;
if ( F_38 ( ( T_2 * ) V_23 , V_83 ) < 0 )
break;
F_5 ( V_98 , L_23 ) ;
break;
default:
F_8 ( L_30 ,
V_111 ) ;
break;
}
F_11 ( V_98 ) ;
}
V_131:
if ( V_30 )
F_49 () ;
F_36 () ;
F_40 ( 0 ) ;
if ( V_65 == V_133 )
V_134 = V_135 ;
F_50 () ;
F_51 ( V_78 ) ;
return 0 ;
}
int F_52 ( struct V_31 * V_32 )
{
return 0 ;
}
T_6 int F_53 ( enum V_64 V_65 ,
int V_68 , int V_136 , struct V_31 * V_32 )
{
static T_2 V_137 = 1 ;
int V_15 ;
if ( V_56 )
F_4 ( L_31 ) ;
V_56 = 1 ;
if ( V_137 ) {
unsigned long V_45 ;
asm("mov mdr,%0" : "=d"(mdr));
F_54 (
L_32 ,
V_32 , V_65 , V_45 , V_32 -> V_36 ) ;
F_54 (
L_33 ,
V_32 -> V_36 , V_32 -> V_78 , ( unsigned long ) & V_15 ,
F_46 ( V_32 ) ? L_34 : L_35 ) ;
F_54 (
L_36 ,
V_32 -> V_112 , V_32 -> V_113 , V_32 -> V_114 , V_32 -> V_115 ) ;
F_54 (
L_37 ,
V_32 -> V_46 , V_32 -> V_47 , V_32 -> V_48 , V_32 -> V_49 ) ;
F_54 (
L_38 ,
V_32 -> V_118 , V_32 -> V_119 , V_32 -> V_120 , V_32 -> V_121 ) ;
F_54 (
L_39 ,
V_32 -> V_122 , V_32 -> V_123 , V_32 -> V_124 , V_32 -> V_125 ) ;
F_54 (
L_40 ,
V_32 -> V_42 , V_32 -> V_116 , V_32 -> V_45 , V_32 -> V_37 ) ;
F_54 (
L_41 ,
V_32 -> V_128 , V_32 -> V_127 , V_32 -> V_126 , V_32 -> V_117 ) ;
F_54 (
L_42 ,
F_55 () , V_138 ) ;
} else {
V_137 = 1 ;
}
V_15 = F_39 ( V_32 , V_65 ) ;
F_54 ( L_43 ) ;
V_56 = 0 ;
return V_15 ;
}
T_6 void F_56 ( struct V_31 * V_32 ,
enum V_64 V_65 )
{
unsigned long V_45 ;
asm("mov mdr,%0" : "=d"(mdr));
F_54 ( L_44 ,
V_32 , V_65 , V_45 ) ;
while ( ( unsigned long ) V_32 == 0xffffffff ) {}
if ( V_32 -> V_36 == ( unsigned ) V_139 ) {
V_32 -> V_36 = ( unsigned ) V_140 ;
goto V_40;
}
if ( V_32 -> V_36 == ( unsigned ) V_141 ) {
V_32 -> V_36 = ( unsigned ) V_142 ;
goto V_40;
}
if ( V_32 -> V_36 == ( unsigned ) V_143 ) {
V_32 -> V_36 = ( unsigned ) V_144 ;
goto V_40;
}
if ( V_32 -> V_36 == ( unsigned ) V_145 ) {
V_32 -> V_36 = ( unsigned ) V_146 ;
goto V_40;
}
if ( V_32 -> V_36 == ( unsigned ) V_147 ) {
V_32 -> V_36 = ( unsigned ) V_148 ;
goto V_40;
}
if ( V_32 -> V_36 == ( unsigned ) V_149 ) {
V_32 -> V_36 = ( unsigned ) V_150 ;
goto V_40;
}
F_4 ( L_45 ) ;
F_57 () ;
F_58 ( V_32 ) ;
F_59 ( L_46 ) ;
V_40:
F_54 ( L_47 ) ;
V_32 -> V_112 = - V_38 ;
return;
}
void F_60 ( int V_151 )
{
unsigned char V_11 ;
unsigned char V_1 ;
int V_13 ;
V_56 = 1 ;
V_98 [ 0 ] = 'W' ;
V_98 [ 1 ] = F_12 ( V_151 ) ;
V_98 [ 2 ] = F_13 ( V_151 ) ;
V_98 [ 3 ] = 0 ;
F_9 ( '$' ) ;
V_11 = 0 ;
V_13 = 0 ;
while ( ( V_1 = V_98 [ V_13 ] ) != 0 ) {
F_9 ( V_1 ) ;
V_11 += V_1 ;
V_13 += 1 ;
}
F_9 ( '#' ) ;
F_9 ( F_12 ( V_11 ) ) ;
F_9 ( F_13 ( V_11 ) ) ;
F_61 () ;
V_56 = 0 ;
}
T_6 void T_7 F_62 ( void )
{
#ifdef F_44
unsigned char V_1 ;
int V_15 ;
#endif
V_56 = 1 ;
F_63 ( V_152 L_48 , V_153 ) ;
F_64 () ;
F_54 ( L_49 ) ;
F_10 ( L_7 ) ;
F_9 ( '+' ) ;
#ifdef F_44
F_4 ( L_50 ) ;
do { F_7 ( & V_1 , 0 ) ; } while ( V_1 != '$' );
do { F_7 ( & V_1 , 0 ) ; } while ( V_1 != '#' );
do { V_15 = F_7 ( & V_1 , 0 ) ; } while ( V_15 != 0 );
do { V_15 = F_7 ( & V_1 , 0 ) ; } while ( V_15 != 0 );
F_10 ( L_3 ) ;
F_9 ( '-' ) ;
#else
F_63 ( L_51 ) ;
#endif
V_56 = 0 ;
F_54 ( L_52 ) ;
}
static int T_7 F_65 ( void )
{
F_63 ( V_154 L_53 ) ;
F_66 ( & V_155 ) ;
return 0 ;
}
T_6 void F_67 ( struct V_31 * V_32 , enum V_64 V_65 )
{
char V_1 ;
int V_15 ;
F_54 ( L_54 ) ;
do {
V_15 = F_7 ( & V_1 , 1 ) ;
if ( V_15 != - V_17 && V_15 != - V_156 ) {
if ( V_15 != - V_157 )
V_18 = V_1 ;
F_39 ( V_32 , V_65 ) ;
}
} while ( V_15 != - V_156 );
F_54 ( L_55 ) ;
}
