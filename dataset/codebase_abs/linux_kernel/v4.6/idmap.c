static void F_1 ( T_1 * V_1 , unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
T_2 * V_5 ;
unsigned long V_6 ;
if ( F_2 ( V_1 ) || ( F_3 ( * V_1 ) & V_7 ) ) {
V_5 = F_4 ( & V_8 , V_2 ) ;
if ( ! V_5 ) {
F_5 ( L_1 ) ;
return;
}
if ( ! F_6 ( * V_1 ) )
memcpy ( V_5 , F_7 ( V_1 , 0 ) ,
V_9 * sizeof( T_2 ) ) ;
F_8 ( & V_8 , V_1 , V_5 ) ;
V_5 += F_9 ( V_2 ) ;
} else
V_5 = F_7 ( V_1 , V_2 ) ;
do {
V_6 = F_10 ( V_2 , V_3 ) ;
* V_5 = F_11 ( ( V_2 & V_10 ) | V_4 ) ;
F_12 ( V_5 ) ;
} while ( V_5 ++ , V_2 = V_6 , V_2 != V_3 );
}
static void F_1 ( T_1 * V_1 , unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
T_2 * V_5 = F_7 ( V_1 , V_2 ) ;
V_2 = ( V_2 & V_10 ) | V_4 ;
V_5 [ 0 ] = F_11 ( V_2 ) ;
V_2 += V_11 ;
V_5 [ 1 ] = F_11 ( V_2 ) ;
F_12 ( V_5 ) ;
}
static void F_13 ( T_3 * V_12 , unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
T_1 * V_1 = F_14 ( V_12 , V_2 ) ;
unsigned long V_6 ;
do {
V_6 = F_15 ( V_2 , V_3 ) ;
F_1 ( V_1 , V_2 , V_6 , V_4 ) ;
} while ( V_1 ++ , V_2 = V_6 , V_2 != V_3 );
}
static void F_16 ( T_3 * V_12 , const char * V_13 ,
const char * V_14 , unsigned long V_4 )
{
unsigned long V_2 , V_3 ;
unsigned long V_6 ;
V_2 = F_17 ( V_13 ) ;
V_3 = F_17 ( V_14 ) ;
F_18 ( L_2 , V_2 , V_3 ) ;
V_4 |= V_15 | V_16 | V_17 ;
if ( F_19 () <= V_18 && ! F_20 () )
V_4 |= V_19 ;
V_12 += F_21 ( V_2 ) ;
do {
V_6 = F_22 ( V_2 , V_3 ) ;
F_13 ( V_12 , V_2 , V_6 , V_4 ) ;
} while ( V_12 ++ , V_2 = V_6 , V_2 != V_3 );
}
static int T_4 F_23 ( void )
{
V_20 = F_24 ( & V_8 ) ;
if ( ! V_20 )
return - V_21 ;
F_16 ( V_20 , V_22 ,
V_23 , 0 ) ;
F_25 () ;
return 0 ;
}
void F_26 ( void )
{
F_27 ( V_20 , & V_8 ) ;
F_28 () ;
#ifdef F_29
F_30 () ;
#endif
}
