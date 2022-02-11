static void F_1 ( void )
{
T_1 V_1 ;
T_1 V_2 ;
T_1 V_3 ;
T_1 V_4 ;
T_1 V_5 ;
T_1 V_6 ;
unsigned int V_7 ;
unsigned int V_8 = 0 ;
if ( ! F_2 () )
return;
F_3 () ;
V_1 = F_4 () ;
F_5 ( V_9 ) ;
V_2 = F_4 () ;
F_6 () ;
V_10 ++ ;
V_3 = V_2 - V_1 ;
if ( V_10 == 1 ) {
V_11 = V_3 ;
F_7 ( V_9 , V_12 ,
L_1 , V_11 ) ;
return;
}
V_13 = V_3 ;
if ( V_3 > V_14 )
V_14 = V_3 ;
if ( ! V_15 || V_3 < V_15 )
V_15 = V_3 ;
if ( V_10 > V_16 ) {
F_7 ( V_9 , V_12 ,
L_2 ,
V_13 , V_11 , V_14 , V_15 , V_17 , V_18 , V_19 ) ;
return;
}
V_20 += V_3 ;
V_21 += V_3 * V_3 ;
if ( V_10 > 1 ) {
V_4 = ( T_1 ) V_10 * V_21 - V_20 * V_20 ;
F_8 ( V_4 , ( V_22 ) V_10 ) ;
F_8 ( V_4 , ( V_22 ) V_10 - 1 ) ;
} else
V_4 = 0 ;
V_3 = V_20 ;
F_8 ( V_3 , V_10 ) ;
V_7 = V_3 ;
if ( V_4 > 0 ) {
int V_23 = 0 ;
V_5 = V_7 ;
do {
V_6 = V_5 ;
V_5 = V_4 ;
if ( ! V_6 )
break;
F_8 ( V_5 , V_6 ) ;
V_5 += V_6 ;
F_8 ( V_5 , 2 ) ;
} while ( V_23 ++ < 10 && V_6 != V_5 );
V_8 = V_5 ;
}
F_7 ( V_9 , V_12 ,
L_3 ,
V_13 , V_11 , V_14 , V_15 , V_7 , V_8 , V_4 ) ;
V_18 = V_8 ;
V_17 = V_7 ;
V_19 = V_4 ;
}
static int F_9 ( void * V_24 )
{
F_10 ( 100 ) ;
while ( ! F_11 () ) {
F_1 () ;
F_12 () ;
}
return 0 ;
}
void F_13 ( void )
{
V_25 = F_14 ( F_9 ,
NULL , L_4 ) ;
F_15 ( ! V_25 ) ;
}
void F_16 ( void )
{
if ( ! V_25 )
return;
F_17 ( V_25 ) ;
strcpy ( V_9 , L_5 ) ;
V_20 = 0 ;
V_21 = 0 ;
V_13 = 0 ;
V_14 = 0 ;
V_15 = 0 ;
V_10 = 0 ;
V_11 = 0 ;
V_18 = 0 ;
V_17 = 0 ;
V_19 = 0 ;
}
