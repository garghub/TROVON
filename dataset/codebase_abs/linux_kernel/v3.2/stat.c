static T_1 F_1 ( int V_1 )
{
T_2 V_2 = F_2 ( V_1 , NULL ) ;
T_1 V_3 ;
if ( V_2 == - 1ULL ) {
V_3 = F_3 ( V_1 ) . V_4 . V_3 ;
V_3 = F_4 ( V_3 , F_5 ( V_1 ) ) ;
} else
V_3 = F_6 ( V_2 ) ;
return V_3 ;
}
static T_1 F_7 ( int V_1 )
{
T_2 V_5 = F_8 ( V_1 , NULL ) ;
T_1 V_6 ;
if ( V_5 == - 1ULL )
V_6 = F_3 ( V_1 ) . V_4 . V_6 ;
else
V_6 = F_6 ( V_5 ) ;
return V_6 ;
}
static int F_9 ( struct V_7 * V_8 , void * V_9 )
{
int V_10 , V_11 ;
unsigned long V_12 ;
T_1 V_13 , V_14 , system , V_3 , V_6 , V_15 , V_16 , V_17 ;
T_1 V_18 , V_19 ;
T_2 V_20 = 0 ;
T_2 V_21 = 0 ;
unsigned int V_22 [ V_23 ] = { 0 } ;
struct V_24 V_25 ;
V_13 = V_14 = system = V_3 = V_6 =
V_15 = V_16 = V_17 = V_26 ;
V_18 = V_19 = V_26 ;
F_10 ( & V_25 ) ;
V_12 = V_25 . V_27 ;
F_11 (i) {
V_13 = F_4 ( V_13 , F_3 ( V_10 ) . V_4 . V_13 ) ;
V_14 = F_4 ( V_14 , F_3 ( V_10 ) . V_4 . V_14 ) ;
system = F_4 ( system , F_3 ( V_10 ) . V_4 . system ) ;
V_3 = F_4 ( V_3 , F_1 ( V_10 ) ) ;
V_6 = F_4 ( V_6 , F_7 ( V_10 ) ) ;
V_15 = F_4 ( V_15 , F_3 ( V_10 ) . V_4 . V_15 ) ;
V_16 = F_4 ( V_16 , F_3 ( V_10 ) . V_4 . V_16 ) ;
V_17 = F_4 ( V_17 , F_3 ( V_10 ) . V_4 . V_17 ) ;
V_18 = F_4 ( V_18 , F_3 ( V_10 ) . V_4 . V_18 ) ;
V_19 = F_4 ( V_19 ,
F_3 ( V_10 ) . V_4 . V_19 ) ;
V_20 += F_12 ( V_10 ) ;
V_20 += F_13 ( V_10 ) ;
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ ) {
unsigned int V_28 = F_14 ( V_11 , V_10 ) ;
V_22 [ V_11 ] += V_28 ;
V_21 += V_28 ;
}
}
V_20 += F_15 () ;
F_16 ( V_8 , L_1
L_2 ,
( unsigned long long ) F_17 ( V_13 ) ,
( unsigned long long ) F_17 ( V_14 ) ,
( unsigned long long ) F_17 ( system ) ,
( unsigned long long ) F_17 ( V_3 ) ,
( unsigned long long ) F_17 ( V_6 ) ,
( unsigned long long ) F_17 ( V_15 ) ,
( unsigned long long ) F_17 ( V_16 ) ,
( unsigned long long ) F_17 ( V_17 ) ,
( unsigned long long ) F_17 ( V_18 ) ,
( unsigned long long ) F_17 ( V_19 ) ) ;
F_18 (i) {
V_13 = F_3 ( V_10 ) . V_4 . V_13 ;
V_14 = F_3 ( V_10 ) . V_4 . V_14 ;
system = F_3 ( V_10 ) . V_4 . system ;
V_3 = F_1 ( V_10 ) ;
V_6 = F_7 ( V_10 ) ;
V_15 = F_3 ( V_10 ) . V_4 . V_15 ;
V_16 = F_3 ( V_10 ) . V_4 . V_16 ;
V_17 = F_3 ( V_10 ) . V_4 . V_17 ;
V_18 = F_3 ( V_10 ) . V_4 . V_18 ;
V_19 = F_3 ( V_10 ) . V_4 . V_19 ;
F_16 ( V_8 ,
L_3
L_2 ,
V_10 ,
( unsigned long long ) F_17 ( V_13 ) ,
( unsigned long long ) F_17 ( V_14 ) ,
( unsigned long long ) F_17 ( system ) ,
( unsigned long long ) F_17 ( V_3 ) ,
( unsigned long long ) F_17 ( V_6 ) ,
( unsigned long long ) F_17 ( V_15 ) ,
( unsigned long long ) F_17 ( V_16 ) ,
( unsigned long long ) F_17 ( V_17 ) ,
( unsigned long long ) F_17 ( V_18 ) ,
( unsigned long long ) F_17 ( V_19 ) ) ;
}
F_16 ( V_8 , L_4 , ( unsigned long long ) V_20 ) ;
F_19 (j)
F_16 ( V_8 , L_5 , F_20 ( V_11 ) ) ;
F_16 ( V_8 ,
L_6
L_7
L_8
L_9
L_10 ,
F_21 () ,
( unsigned long ) V_12 ,
V_29 ,
F_22 () ,
F_23 () ) ;
F_16 ( V_8 , L_11 , ( unsigned long long ) V_21 ) ;
for ( V_10 = 0 ; V_10 < V_23 ; V_10 ++ )
F_16 ( V_8 , L_5 , V_22 [ V_10 ] ) ;
F_24 ( V_8 , '\n' ) ;
return 0 ;
}
static int F_25 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
unsigned V_32 = 4096 * ( 1 + F_26 () / 32 ) ;
char * V_33 ;
struct V_7 * V_34 ;
int V_35 ;
if ( V_32 > V_36 )
V_32 = V_36 ;
V_33 = F_27 ( V_32 , V_37 ) ;
if ( ! V_33 )
return - V_38 ;
V_35 = F_28 ( V_31 , F_9 , NULL ) ;
if ( ! V_35 ) {
V_34 = V_31 -> V_39 ;
V_34 -> V_33 = V_33 ;
V_34 -> V_32 = V_32 ;
} else
F_29 ( V_33 ) ;
return V_35 ;
}
static int T_3 F_30 ( void )
{
F_31 ( L_12 , 0 , NULL , & V_40 ) ;
return 0 ;
}
