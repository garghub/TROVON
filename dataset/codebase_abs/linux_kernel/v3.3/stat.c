static T_1 F_1 ( int V_1 )
{
T_1 V_2 , V_3 = F_2 ( V_1 , NULL ) ;
if ( V_3 == - 1ULL ) {
V_2 = F_3 ( V_1 ) . V_4 [ V_5 ] ;
V_2 += F_4 ( V_1 ) ;
} else
V_2 = F_5 ( V_3 ) ;
return V_2 ;
}
static T_1 F_6 ( int V_1 )
{
T_1 V_6 , V_7 = F_7 ( V_1 , NULL ) ;
if ( V_7 == - 1ULL )
V_6 = F_3 ( V_1 ) . V_4 [ V_8 ] ;
else
V_6 = F_5 ( V_7 ) ;
return V_6 ;
}
static int F_8 ( struct V_9 * V_10 , void * V_11 )
{
int V_12 , V_13 ;
unsigned long V_14 ;
T_1 V_15 , V_16 , system , V_2 , V_6 , V_17 , V_18 , V_19 ;
T_1 V_20 , V_21 ;
T_1 V_22 = 0 ;
T_1 V_23 = 0 ;
unsigned int V_24 [ V_25 ] = { 0 } ;
struct V_26 V_27 ;
V_15 = V_16 = system = V_2 = V_6 =
V_17 = V_18 = V_19 = 0 ;
V_20 = V_21 = 0 ;
F_9 ( & V_27 ) ;
V_14 = V_27 . V_28 ;
F_10 (i) {
V_15 += F_3 ( V_12 ) . V_4 [ V_29 ] ;
V_16 += F_3 ( V_12 ) . V_4 [ V_30 ] ;
system += F_3 ( V_12 ) . V_4 [ V_31 ] ;
V_2 += F_1 ( V_12 ) ;
V_6 += F_6 ( V_12 ) ;
V_17 += F_3 ( V_12 ) . V_4 [ V_32 ] ;
V_18 += F_3 ( V_12 ) . V_4 [ V_33 ] ;
V_19 += F_3 ( V_12 ) . V_4 [ V_34 ] ;
V_20 += F_3 ( V_12 ) . V_4 [ V_35 ] ;
V_21 += F_3 ( V_12 ) . V_4 [ V_36 ] ;
V_22 += F_11 ( V_12 ) ;
V_22 += F_12 ( V_12 ) ;
for ( V_13 = 0 ; V_13 < V_25 ; V_13 ++ ) {
unsigned int V_37 = F_13 ( V_13 , V_12 ) ;
V_24 [ V_13 ] += V_37 ;
V_23 += V_37 ;
}
}
V_22 += F_14 () ;
F_15 ( V_10 , L_1
L_2 ,
( unsigned long long ) F_16 ( V_15 ) ,
( unsigned long long ) F_16 ( V_16 ) ,
( unsigned long long ) F_16 ( system ) ,
( unsigned long long ) F_16 ( V_2 ) ,
( unsigned long long ) F_16 ( V_6 ) ,
( unsigned long long ) F_16 ( V_17 ) ,
( unsigned long long ) F_16 ( V_18 ) ,
( unsigned long long ) F_16 ( V_19 ) ,
( unsigned long long ) F_16 ( V_20 ) ,
( unsigned long long ) F_16 ( V_21 ) ) ;
F_17 (i) {
V_15 = F_3 ( V_12 ) . V_4 [ V_29 ] ;
V_16 = F_3 ( V_12 ) . V_4 [ V_30 ] ;
system = F_3 ( V_12 ) . V_4 [ V_31 ] ;
V_2 = F_1 ( V_12 ) ;
V_6 = F_6 ( V_12 ) ;
V_17 = F_3 ( V_12 ) . V_4 [ V_32 ] ;
V_18 = F_3 ( V_12 ) . V_4 [ V_33 ] ;
V_19 = F_3 ( V_12 ) . V_4 [ V_34 ] ;
V_20 = F_3 ( V_12 ) . V_4 [ V_35 ] ;
V_21 = F_3 ( V_12 ) . V_4 [ V_36 ] ;
F_15 ( V_10 ,
L_3
L_2 ,
V_12 ,
( unsigned long long ) F_16 ( V_15 ) ,
( unsigned long long ) F_16 ( V_16 ) ,
( unsigned long long ) F_16 ( system ) ,
( unsigned long long ) F_16 ( V_2 ) ,
( unsigned long long ) F_16 ( V_6 ) ,
( unsigned long long ) F_16 ( V_17 ) ,
( unsigned long long ) F_16 ( V_18 ) ,
( unsigned long long ) F_16 ( V_19 ) ,
( unsigned long long ) F_16 ( V_20 ) ,
( unsigned long long ) F_16 ( V_21 ) ) ;
}
F_15 ( V_10 , L_4 , ( unsigned long long ) V_22 ) ;
F_18 (j)
F_15 ( V_10 , L_5 , F_19 ( V_13 ) ) ;
F_15 ( V_10 ,
L_6
L_7
L_8
L_9
L_10 ,
F_20 () ,
( unsigned long ) V_14 ,
V_38 ,
F_21 () ,
F_22 () ) ;
F_15 ( V_10 , L_11 , ( unsigned long long ) V_23 ) ;
for ( V_12 = 0 ; V_12 < V_25 ; V_12 ++ )
F_15 ( V_10 , L_5 , V_24 [ V_12 ] ) ;
F_23 ( V_10 , '\n' ) ;
return 0 ;
}
static int F_24 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
unsigned V_41 = 4096 * ( 1 + F_25 () / 32 ) ;
char * V_42 ;
struct V_9 * V_43 ;
int V_44 ;
if ( V_41 > V_45 )
V_41 = V_45 ;
V_42 = F_26 ( V_41 , V_46 ) ;
if ( ! V_42 )
return - V_47 ;
V_44 = F_27 ( V_40 , F_8 , NULL ) ;
if ( ! V_44 ) {
V_43 = V_40 -> V_48 ;
V_43 -> V_42 = V_42 ;
V_43 -> V_41 = V_41 ;
} else
F_28 ( V_42 ) ;
return V_44 ;
}
static int T_2 F_29 ( void )
{
F_30 ( L_12 , 0 , NULL , & V_49 ) ;
return 0 ;
}
