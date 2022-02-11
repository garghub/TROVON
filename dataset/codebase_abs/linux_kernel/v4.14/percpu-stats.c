static int F_1 ( const void * V_1 , const void * V_2 )
{
return * ( int * ) V_1 - * ( int * ) V_2 ;
}
static int F_2 ( void )
{
struct V_3 * V_4 ;
int V_5 , V_6 ;
V_6 = 0 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
F_3 (chunk, &pcpu_slot[slot], list)
V_6 = F_4 ( V_6 , V_4 -> V_8 ) ;
return V_6 ;
}
static void F_5 ( struct V_9 * V_10 , struct V_3 * V_4 ,
int * V_11 )
{
int V_12 , V_13 , V_14 , V_15 , V_16 ;
int * V_17 , * V_18 ;
int V_19 = 0 , V_20 = 0 ;
int V_21 = 0 , V_22 = 0 , V_23 = 0 ;
V_17 = V_11 ;
V_13 = F_6 ( V_4 -> V_24 ,
F_7 ( V_4 ) -
V_4 -> V_25 / V_26 - 1 ) ;
V_13 = F_8 ( V_13 , V_4 -> V_24 ) ?
V_13 + 1 : 0 ;
V_14 = 0 ;
V_15 = V_4 -> V_27 / V_26 ;
while ( V_15 < V_13 ) {
if ( F_8 ( V_15 , V_4 -> V_24 ) ) {
V_16 = F_9 ( V_4 -> V_28 , V_13 ,
V_15 + 1 ) ;
V_17 [ V_14 ] = 1 ;
} else {
V_16 = F_9 ( V_4 -> V_24 , V_13 ,
V_15 + 1 ) ;
V_17 [ V_14 ] = - 1 ;
}
V_17 [ V_14 ++ ] *= ( V_16 - V_15 ) * V_26 ;
V_15 = V_16 ;
}
if ( V_14 > 0 ) {
F_10 ( V_17 , V_14 , sizeof( int ) , F_1 , NULL ) ;
for ( V_12 = 0 , V_18 = V_17 ; * V_18 < 0 && V_12 < V_14 ; V_12 ++ , V_18 ++ ) {
V_19 -= * V_18 ;
V_20 = F_4 ( V_20 , - 1 * ( * V_18 ) ) ;
}
V_21 = V_17 [ V_12 ] ;
V_22 = V_17 [ ( V_12 + V_14 - 1 ) / 2 ] ;
V_23 = V_17 [ V_14 - 1 ] ;
}
F_11 ( L_1 , V_4 -> V_8 ) ;
F_11 ( L_2 , V_4 -> V_29 ) ;
F_11 ( L_3 , V_4 -> V_30 ) ;
F_11 ( L_4 , V_4 -> V_31 ) ;
F_11 ( L_5 , V_4 -> V_32 ) ;
F_11 ( L_6 , V_4 -> V_33 * V_26 ) ;
F_11 ( L_7 , V_19 ) ;
F_11 ( L_8 , V_20 ) ;
F_11 ( L_9 , V_21 ) ;
F_11 ( L_10 , V_22 ) ;
F_11 ( L_11 , V_23 ) ;
F_12 ( V_10 , '\n' ) ;
}
static int F_13 ( struct V_9 * V_10 , void * V_34 )
{
struct V_3 * V_4 ;
int V_5 , V_6 ;
int * V_11 ;
V_35:
F_14 ( & V_36 ) ;
V_6 = F_2 () ;
F_15 ( & V_36 ) ;
V_11 = F_16 ( ( 2 * V_6 + 1 ) * sizeof( int ) ) ;
if ( ! V_11 )
return - V_37 ;
F_14 ( & V_36 ) ;
if ( V_6 < F_2 () ) {
F_15 ( & V_36 ) ;
F_17 ( V_11 ) ;
goto V_35;
}
#define F_18 ( T_1 ) \
seq_printf(m, " %-20s: %12lld\n", #X, (long long int)pcpu_stats_ai.X)
F_19 ( V_10 ,
L_12
L_13
L_14 ) ;
F_18 ( V_38 ) ;
F_18 ( V_39 ) ;
F_18 ( V_40 ) ;
F_18 ( V_41 ) ;
F_18 ( V_42 ) ;
F_18 ( V_43 ) ;
F_12 ( V_10 , '\n' ) ;
#undef F_18
#define F_20 ( T_1 ) \
seq_printf(m, " %-20s: %12llu\n", #X, (unsigned long long)pcpu_stats.X)
F_19 ( V_10 ,
L_15
L_14 ) ;
F_20 ( V_8 ) ;
F_20 ( V_44 ) ;
F_20 ( V_45 ) ;
F_20 ( V_46 ) ;
F_20 ( V_47 ) ;
F_20 ( V_48 ) ;
F_20 ( V_49 ) ;
F_20 ( V_29 ) ;
F_11 ( L_3 , V_50 ) ;
F_12 ( V_10 , '\n' ) ;
#undef F_20
F_19 ( V_10 ,
L_16
L_14 ) ;
if ( V_51 ) {
F_21 ( V_10 , L_17 ) ;
F_5 ( V_10 , V_51 , V_11 ) ;
}
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
F_3 (chunk, &pcpu_slot[slot], list) {
if ( V_4 == V_52 ) {
F_21 ( V_10 , L_18 ) ;
F_5 ( V_10 , V_4 , V_11 ) ;
} else {
F_21 ( V_10 , L_19 ) ;
F_5 ( V_10 , V_4 , V_11 ) ;
}
}
}
F_15 ( & V_36 ) ;
F_17 ( V_11 ) ;
return 0 ;
}
static int F_22 ( struct V_53 * V_53 , struct V_54 * V_55 )
{
return F_23 ( V_55 , F_13 , NULL ) ;
}
static int T_2 F_24 ( void )
{
F_25 ( L_20 , 0444 , NULL , NULL ,
& V_56 ) ;
return 0 ;
}
