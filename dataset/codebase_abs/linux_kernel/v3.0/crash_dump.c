void T_1 F_1 ( void )
{
F_2 ( 0 , V_1 ) ;
}
static void T_1 F_3 ( unsigned long V_2 )
{
unsigned int * V_3 = ( unsigned int * ) V_2 ;
F_4 ( V_3 , V_4 ) ;
F_5 ( ++ V_3 , V_2 + V_5 , 0 ) ;
}
void T_1 F_6 ( void )
{
unsigned long V_6 ;
F_7 ( L_1 ) ;
for ( V_6 = V_7 ; V_6 < V_8 ; V_6 += 8 ) {
F_3 ( V_6 ) ;
}
#ifdef F_8
F_3 ( F_9 ( V_9 ) - V_5 ) ;
F_3 ( F_9 ( V_10 ) - V_5 ) ;
#endif
F_7 ( L_2 ) ;
}
static int T_1 F_10 ( char * V_3 )
{
if ( V_3 )
V_11 = ( F_11 ( V_3 , & V_3 ) >> V_12 ) - 1 ;
return 1 ;
}
static T_2 F_12 ( void * V_13 , char * V_14 , T_2 V_15 ,
unsigned long V_16 , int V_17 )
{
if ( V_17 ) {
if ( F_13 ( ( char V_18 * ) V_14 , ( V_13 + V_16 ) , V_15 ) )
return - V_19 ;
} else
memcpy ( V_14 , ( V_13 + V_16 ) , V_15 ) ;
return V_15 ;
}
T_3 F_14 ( unsigned long V_20 , char * V_14 ,
T_2 V_15 , unsigned long V_16 , int V_17 )
{
void * V_13 ;
if ( ! V_15 )
return 0 ;
V_15 = F_15 ( T_2 , V_15 , V_21 ) ;
if ( ( V_22 < V_20 ) && ( V_20 < V_23 ) ) {
V_13 = F_16 ( V_20 << V_12 ) ;
V_15 = F_12 ( V_13 , V_14 , V_15 , V_16 , V_17 ) ;
} else {
V_13 = F_17 ( V_20 << V_12 , V_21 , 0 ) ;
V_15 = F_12 ( V_13 , V_14 , V_15 , V_16 , V_17 ) ;
F_18 ( V_13 ) ;
}
return V_15 ;
}
void F_19 ( unsigned long V_24 , unsigned long V_25 )
{
unsigned long V_2 ;
const T_4 * V_26 , * V_27 ;
unsigned int V_28 = 0 , V_29 = 0 ;
V_26 = F_20 ( V_30 . V_31 , L_3 , NULL ) ;
V_27 = F_20 ( V_30 . V_31 , L_4 , NULL ) ;
if ( V_26 && V_27 ) {
V_28 = * V_26 ;
V_29 = * V_26 + * V_27 ;
}
for ( V_2 = V_24 ; V_2 < V_25 ; V_2 += V_21 ) {
if ( V_2 <= V_29 && ( ( V_2 + V_21 ) > V_28 ) )
continue;
F_21 ( F_22 ( V_2 >> V_12 ) ) ;
F_23 ( F_22 ( V_2 >> V_12 ) ) ;
F_24 ( ( unsigned long ) F_16 ( V_2 ) ) ;
V_32 ++ ;
}
}
