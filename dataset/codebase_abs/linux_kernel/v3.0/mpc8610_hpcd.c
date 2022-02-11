static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( L_1 , V_3 ) ;
return V_4 ;
}
static void T_2 F_3 ( void )
{
int V_1 ;
int V_5 ;
if ( ! V_6 )
return;
V_1 = F_4 ( V_6 , 0 ) ;
if ( ! V_1 ) {
F_5 ( L_2 , V_3 ) ;
return;
}
V_5 = F_6 ( V_1 , F_1 , 0 , L_3 , NULL ) ;
if ( V_5 ) {
F_5 ( L_4 ,
V_3 , V_5 ) ;
F_7 ( V_1 ) ;
}
F_8 ( V_1 ) ;
}
static inline void F_3 ( void ) { }
static int T_2 F_9 ( void )
{
F_10 ( L_5 ) ;
F_3 () ;
F_11 ( NULL , V_7 , NULL ) ;
return 0 ;
}
unsigned int F_12 ( unsigned int V_8 ,
int V_9 )
{
static const unsigned long V_10 [] [ 3 ] = {
{
F_13 ( 3 , 0 , 2 , 1 , 3 , 8 , 8 , 8 , 8 ) ,
F_13 ( 4 , 2 , 0 , 1 , 2 , 8 , 8 , 8 , 0 ) ,
F_13 ( 4 , 0 , 2 , 1 , 1 , 5 , 6 , 5 , 0 )
} ,
{
F_13 ( 3 , 2 , 0 , 1 , 3 , 8 , 8 , 8 , 8 ) ,
F_13 ( 4 , 0 , 2 , 1 , 2 , 8 , 8 , 8 , 0 ) ,
F_13 ( 4 , 2 , 0 , 1 , 1 , 5 , 6 , 5 , 0 )
} ,
} ;
unsigned int V_11 ;
V_11 = ( ( * V_12 == 0x01 ) && ( V_9 == 0 ) ) ? 0 : 1 ;
switch ( V_8 ) {
case 32 :
return V_10 [ V_11 ] [ 0 ] ;
case 24 :
return V_10 [ V_11 ] [ 1 ] ;
case 16 :
return V_10 [ V_11 ] [ 2 ] ;
default:
F_5 ( L_6 , V_8 ) ;
return 0 ;
}
}
void F_14 ( int V_9 , char * V_13 )
{
int V_14 ;
if ( V_9 == 2 ) {
for ( V_14 = 0 ; V_14 < 256 * 3 ; V_14 ++ )
V_13 [ V_14 ] = ( V_13 [ V_14 ] << 2 ) |
( ( V_13 [ V_14 ] >> 6 ) & 0x03 ) ;
}
}
void F_15 ( int V_9 )
{
static const T_3 V_15 [] = {
V_16 | V_17 ,
V_17 ,
0 ,
} ;
if ( V_9 < 3 )
F_16 ( V_18 , V_19 ,
V_15 [ V_9 ] ) ;
}
void F_17 ( unsigned int V_20 )
{
T_4 T_5 * V_21 ;
T_4 V_22 ;
T_6 V_23 , V_24 , V_25 , V_26 , V_27 ;
T_6 V_28 ;
long V_29 ;
int V_14 ;
V_21 = F_18 ( F_19 () + 0xe0800 , sizeof( T_4 ) ) ;
if ( ! V_21 ) {
F_20 ( V_30 L_7 ) ;
return;
}
V_25 = F_21 () ;
F_2 ( L_8 , V_20 ) ;
V_22 = 1000000000 / V_20 ;
V_22 *= 1000 ;
V_20 = V_22 ;
F_2 ( L_9 , V_20 ) ;
V_22 = V_20 * 5 / 100 ;
F_2 ( L_10 , V_22 ) ;
V_26 = V_20 - V_22 ;
V_27 = V_20 + V_22 ;
F_2 ( L_11 , V_26 ) ;
F_2 ( L_12 , V_27 ) ;
V_28 = V_25 / V_20 ;
F_2 ( L_13 , V_28 ) ;
V_29 = 100000000 ;
V_23 = V_28 ;
F_2 ( L_14 , V_23 ) ;
V_24 = 0 ;
for ( V_14 = - 1 ; V_14 <= 1 ; V_14 ++ ) {
V_22 = V_25 / ( ( V_28 + V_14 ) + 1 ) ;
F_2 ( L_15 ,
V_14 , V_28 , V_22 ) ;
if ( ( V_22 < V_26 ) || ( V_22 > V_27 ) )
F_2 ( L_16 ,
V_26 , V_27 ) ;
else if ( abs ( V_22 - V_20 ) < V_29 ) {
F_2 ( L_17 , V_14 ) ;
V_29 = abs ( V_22 - V_20 ) ;
V_23 = V_28 + V_14 ;
V_24 = V_22 ;
}
}
F_2 ( L_18 , V_23 ) ;
F_2 ( L_19 , V_29 ) ;
F_2 ( L_20 , V_24 ) ;
F_2 ( L_21 , ( * V_21 ) ) ;
V_22 = ( * V_21 ) & 0x2000FFFF ;
* V_21 = V_22 ;
* V_21 = V_22 | 0x80000000 | ( ( ( V_23 ) & 0x1F ) << 16 ) ;
F_2 ( L_22 , ( * V_21 ) ) ;
F_22 ( V_21 ) ;
}
T_7 F_23 ( int V_9 , char * V_31 )
{
return snprintf ( V_31 , V_32 ,
L_23
L_24
L_25 ,
V_9 == 0 ? '*' : ' ' ,
V_9 == 1 ? '*' : ' ' ,
V_9 == 2 ? '*' : ' ' ) ;
}
int F_24 ( int V_33 )
{
return V_33 < 3 ? V_33 : 0 ;
}
static void T_2 F_25 ( void )
{
struct V_34 V_35 ;
struct V_36 * V_37 ;
unsigned char * V_38 ;
if ( V_39 . V_40 )
V_39 . V_40 ( L_26 , 0 ) ;
#ifdef F_26
F_27 (np, L_27 ) {
if ( F_28 ( V_37 , L_28 )
|| F_28 ( V_37 , L_29 ) ) {
struct V_34 V_41 ;
F_29 ( V_37 , 0 , & V_41 ) ;
if ( ( V_41 . V_42 & 0xfffff ) == 0xa000 )
F_30 ( V_37 , 1 ) ;
else
F_30 ( V_37 , 0 ) ;
}
}
#endif
#if F_31 ( V_43 ) || F_31 ( V_44 )
V_45 . V_46 = F_12 ;
V_45 . V_47 = F_14 ;
V_45 . V_48 = F_15 ;
V_45 . V_49 = F_17 ;
V_45 . V_50 = F_23 ;
V_45 . V_51 = F_24 ;
#endif
V_6 = F_32 ( NULL , NULL , L_30 ) ;
if ( V_6 ) {
F_29 ( V_6 , 0 , & V_35 ) ;
F_33 ( V_6 ) ;
V_38 = F_18 ( V_35 . V_42 , 32 ) ;
if ( ! V_38 ) {
F_20 ( V_30 L_31 ) ;
return;
}
V_18 = V_38 + 8 ;
V_12 = V_38 + 1 ;
} else
F_20 ( V_30 L_32
L_33 ) ;
F_20 ( L_34 ) ;
}
static int T_2 F_34 ( void )
{
unsigned long V_52 = F_35 () ;
if ( F_36 ( V_52 , L_35 ) )
return 1 ;
return 0 ;
}
static long T_2 F_37 ( void )
{
unsigned int V_22 ;
F_38 ( V_53 , 0 ) ;
F_38 ( V_54 , 0 ) ;
V_22 = F_39 ( V_55 ) ;
V_22 |= V_56 ;
F_38 ( V_55 , V_22 ) ;
asm volatile("isync");
return 0 ;
}
