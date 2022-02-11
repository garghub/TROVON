static void T_1 F_1 ( void )
{
V_1 . V_2 . V_3 = V_4 ;
V_1 . V_5 . V_6 = V_7 ;
}
T_2 T_3 void T_1 F_2 ( void )
{
F_3 () ;
F_4 () ;
F_5 ( & V_8 ) ;
F_6 () ;
switch ( V_8 . V_9 . V_10 ) {
case V_11 :
F_7 () ;
break;
case V_12 :
F_8 () ;
break;
default:
F_1 () ;
break;
}
F_9 () ;
}
void T_1 F_10 ( void )
{
#ifdef F_11
#undef F_11
#endif
#define F_11 ( T_4 ) ((unsigned long)(x) - PAGE_OFFSET)
T_5 V_13 , * V_14 ;
int V_15 ;
unsigned long * V_16 ;
const unsigned long V_17 = F_11 ( V_18 ) +
( F_12 ( V_19 ) << V_20 ) ;
#ifdef F_13
T_6 V_21 , * V_22 = ( T_6 * ) F_11 ( V_23 ) ;
#define F_14 ( V_21 , T_7 ) { (pl2).pmd = (val); }
#else
T_8 V_21 , * V_22 = ( T_8 * ) F_11 ( V_24 ) ;
#define F_14 ( V_21 , T_7 ) { (pl2).pgd = (val); }
#endif
V_14 = ( T_5 * ) F_11 ( V_25 ) ;
V_13 . V_13 = V_26 ;
while ( ( V_13 . V_13 & V_27 ) < V_17 ) {
F_14 ( V_21 , ( unsigned long ) V_14 | V_28 ) ;
* V_22 = V_21 ;
#ifndef F_13
* ( V_22 + ( ( V_29 >> V_30 ) ) ) = V_21 ;
#endif
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ ) {
* V_14 = V_13 ;
V_13 . V_13 += V_32 ;
V_14 ++ ;
}
V_22 ++ ;
}
V_16 = ( unsigned long * ) F_11 ( & V_33 ) ;
* V_16 = ( V_13 . V_13 & V_27 ) >> V_20 ;
V_16 = ( unsigned long * ) F_11 ( & V_34 ) ;
* V_16 = ( unsigned long ) V_14 + V_29 ;
}
