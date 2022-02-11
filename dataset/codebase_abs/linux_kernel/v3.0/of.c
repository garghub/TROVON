static void * F_1 ( unsigned long V_1 )
{
unsigned long V_2 = 0 ;
if ( V_3 == 0 )
V_3 = F_2 ( ( unsigned long ) V_4 , V_5 ) ;
for(; V_3 < V_6 ; V_3 += V_5 ) {
#ifdef F_3
printf ( L_1 , V_3 ) ;
#endif
V_2 = ( unsigned long ) F_4 ( V_3 , V_1 , 0 ) ;
if ( ( void * ) V_2 != ( void * ) - 1 )
break;
}
if ( V_2 == 0 )
return NULL ;
V_3 = F_5 ( V_3 + V_1 ) ;
return ( void * ) V_2 ;
}
static void F_6 ( const void * V_7 )
{
const T_1 * V_8 = V_7 ;
if ( V_8 -> V_9 [ V_10 ] == V_11 ) {
if ( V_3 < V_12 )
V_3 = V_12 ;
}
}
void F_7 ( unsigned long V_13 , unsigned long V_14 , void * V_15 )
{
V_16 . V_17 = F_6 ;
V_16 . malloc = F_1 ;
V_16 . exit = V_18 ;
V_16 . V_19 = V_20 ;
V_21 . V_22 = V_23 ;
V_21 . V_24 = V_25 ;
V_21 . V_26 = V_27 ;
F_8 () ;
F_9 ( V_15 ) ;
V_28 . V_15 = V_15 ;
if ( V_13 && V_14 && V_14 != 0xdeadbeef ) {
V_28 . V_29 = V_13 ;
V_28 . V_30 = V_14 ;
}
}
