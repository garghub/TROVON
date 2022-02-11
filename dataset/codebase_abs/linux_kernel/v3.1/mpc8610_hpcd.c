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
struct V_21 * V_22 = NULL ;
struct V_23 T_4 * V_24 ;
unsigned long V_25 ;
T_5 V_26 ;
T_6 V_27 ;
V_22 = F_18 ( NULL , NULL , L_7 ) ;
if ( ! V_22 ) {
F_5 ( L_8 ) ;
return;
}
V_24 = F_19 ( V_22 , 0 ) ;
F_20 ( V_22 ) ;
if ( ! V_24 ) {
F_5 ( L_9 ) ;
return;
}
V_26 = 1000000000000ULL ;
F_21 ( V_26 , V_20 ) ;
V_25 = V_26 ;
V_27 = F_22 ( F_23 () , V_25 ) - 1 ;
V_27 = F_24 ( T_6 , V_27 , 2 , 31 ) ;
F_25 ( & V_24 -> V_28 ,
V_29 | V_30 | V_31 ) ;
F_26 ( & V_24 -> V_28 , V_29 | ( V_27 << 16 ) ) ;
F_27 ( V_24 ) ;
}
T_7 F_28 ( int V_9 , char * V_32 )
{
return snprintf ( V_32 , V_33 ,
L_10
L_11
L_12 ,
V_9 == 0 ? '*' : ' ' ,
V_9 == 1 ? '*' : ' ' ,
V_9 == 2 ? '*' : ' ' ) ;
}
int F_29 ( int V_34 )
{
return V_34 < 3 ? V_34 : 0 ;
}
static void T_2 F_30 ( void )
{
struct V_35 V_36 ;
struct V_21 * V_37 ;
unsigned char * V_38 ;
if ( V_39 . V_40 )
V_39 . V_40 ( L_13 , 0 ) ;
#ifdef F_31
F_32 (np, L_14 ) {
if ( F_33 ( V_37 , L_15 )
|| F_33 ( V_37 , L_16 ) ) {
struct V_35 V_41 ;
F_34 ( V_37 , 0 , & V_41 ) ;
if ( ( V_41 . V_42 & 0xfffff ) == 0xa000 )
F_35 ( V_37 , 1 ) ;
else
F_35 ( V_37 , 0 ) ;
}
}
#endif
#if F_36 ( V_43 ) || F_36 ( V_44 )
V_45 . V_46 = F_12 ;
V_45 . V_47 = F_14 ;
V_45 . V_48 = F_15 ;
V_45 . V_49 = F_17 ;
V_45 . V_50 = F_28 ;
V_45 . V_51 = F_29 ;
#endif
V_6 = F_18 ( NULL , NULL , L_17 ) ;
if ( V_6 ) {
F_34 ( V_6 , 0 , & V_36 ) ;
F_20 ( V_6 ) ;
V_38 = F_37 ( V_36 . V_42 , 32 ) ;
if ( ! V_38 ) {
F_38 ( V_52 L_18 ) ;
return;
}
V_18 = V_38 + 8 ;
V_12 = V_38 + 1 ;
} else
F_38 ( V_52 L_19
L_20 ) ;
F_38 ( L_21 ) ;
}
static int T_2 F_39 ( void )
{
unsigned long V_53 = F_40 () ;
if ( F_41 ( V_53 , L_22 ) )
return 1 ;
return 0 ;
}
static long T_2 F_42 ( void )
{
unsigned int V_26 ;
F_43 ( V_54 , 0 ) ;
F_43 ( V_55 , 0 ) ;
V_26 = F_44 ( V_56 ) ;
V_26 |= V_57 ;
F_43 ( V_56 , V_26 ) ;
asm volatile("isync");
return 0 ;
}
