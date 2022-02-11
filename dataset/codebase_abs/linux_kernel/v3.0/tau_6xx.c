void F_1 ( unsigned long V_1 )
{
#ifdef F_2
F_3 ( V_2 , F_4 ( V_3 [ V_1 ] . V_4 ) | V_5 | V_6 | V_7 ) ;
F_3 ( V_8 , F_4 ( V_3 [ V_1 ] . V_9 ) | V_5 | V_6 ) ;
#else
F_3 ( V_2 , F_4 ( V_3 [ V_1 ] . V_4 ) | V_5 | V_7 ) ;
F_3 ( V_8 , F_4 ( V_3 [ V_1 ] . V_9 ) | V_5 ) ;
#endif
}
void F_5 ( int V_1 )
{
unsigned V_10 ;
#ifdef F_6
F_7 ( L_1 ) ;
#endif
if( ( V_10 = F_8 ( V_2 ) ) & V_11 ) {
if( V_10 & V_12 ) {
if ( V_3 [ V_1 ] . V_4 >= V_13 ) {
V_3 [ V_1 ] . V_4 -= V_13 ;
V_3 [ V_1 ] . V_9 -= ( V_13 - V_14 ) ;
}
V_3 [ V_1 ] . V_15 = 1 ;
#ifdef F_6
F_7 ( L_2 ) ;
#endif
}
}
if( ( V_10 = F_8 ( V_8 ) ) & V_11 ) {
if( V_10 & V_12 ) {
if ( V_3 [ V_1 ] . V_9 <= 127 - V_13 ) {
V_3 [ V_1 ] . V_4 += ( V_13 - V_14 ) ;
V_3 [ V_1 ] . V_9 += V_13 ;
}
V_3 [ V_1 ] . V_15 = 1 ;
#ifdef F_6
F_7 ( L_3 ) ;
#endif
}
}
#ifdef F_6
F_7 ( L_4 , V_3 [ V_1 ] . V_15 ) ;
#endif
#ifndef F_2
F_1 ( V_1 ) ;
#endif
}
void F_9 ( struct V_16 * V_17 )
{
int V_1 = F_10 () ;
F_11 () ;
V_3 [ V_1 ] . V_18 ++ ;
F_5 ( V_1 ) ;
F_12 () ;
}
static void F_13 ( void * V_19 )
{
int V_1 ;
unsigned long V_20 ;
int V_21 ;
int V_22 ;
F_14 ( V_20 ) ;
V_1 = F_10 () ;
#ifndef F_2
F_5 ( V_1 ) ;
#endif
V_21 = V_3 [ V_1 ] . V_9 - V_3 [ V_1 ] . V_4 ;
if ( V_21 > V_23 && ! V_3 [ V_1 ] . V_15 ) {
V_22 = ( 2 + V_21 - V_23 ) / 4 ;
if ( V_22 ) {
V_3 [ V_1 ] . V_4 += V_22 ;
V_3 [ V_1 ] . V_9 -= V_22 ;
} else {
V_3 [ V_1 ] . V_4 += 1 ;
#if 1
if ( ( V_3 [ V_1 ] . V_9 - V_3 [ V_1 ] . V_4 ) != V_23 ) {
F_7 ( V_24 L_5 , __LINE__ ) ;
}
#endif
}
}
V_3 [ V_1 ] . V_15 = 0 ;
F_1 ( V_1 ) ;
F_3 ( V_25 , F_15 ( 500 * 60 ) | V_26 ) ;
F_16 ( V_20 ) ;
}
static void F_17 ( unsigned long V_27 )
{
F_18 ( & V_28 , V_29 + V_30 ) ;
F_19 ( F_13 , NULL , 0 ) ;
}
void T_1 F_20 ( void * V_19 )
{
unsigned long V_1 = F_10 () ;
V_3 [ V_1 ] . V_4 = 5 ;
V_3 [ V_1 ] . V_9 = 120 ;
F_1 ( V_1 ) ;
}
int T_1 F_21 ( void )
{
if ( ! F_22 ( V_31 ) ) {
F_7 ( L_6 ) ;
V_32 = 0 ;
return 1 ;
}
F_23 ( & V_28 ) ;
V_28 . V_33 = F_17 ;
V_28 . V_34 = V_29 + V_30 ;
F_24 ( & V_28 ) ;
F_19 ( F_20 , NULL , 0 ) ;
F_7 ( L_7 ) ;
#ifdef F_2
F_7 ( L_8 ) ;
#else
F_7 ( L_9 ) ;
#endif
F_7 ( L_10 , V_30 ) ;
V_32 = 1 ;
return 0 ;
}
T_2 F_25 ( unsigned long V_1 )
{
return ( ( V_3 [ V_1 ] . V_9 << 16 ) | V_3 [ V_1 ] . V_4 ) ;
}
int F_26 ( unsigned long V_1 )
{
return ( ( V_3 [ V_1 ] . V_9 + V_3 [ V_1 ] . V_4 ) / 2 ) ;
}
int F_27 ( unsigned long V_1 )
{
return ( V_3 [ V_1 ] . V_18 ) ;
}
