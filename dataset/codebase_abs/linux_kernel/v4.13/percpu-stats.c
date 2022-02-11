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
void * V_11 )
{
int V_12 , V_13 , V_14 , V_15 , V_16 ;
int * V_17 , * V_18 ;
int V_19 = 0 , V_20 = 0 ;
int V_21 = 0 , V_22 = 0 , V_23 = 0 ;
V_17 = V_11 ;
V_13 = V_4 -> V_24 ? 1 : 0 ;
V_14 = - 1 ;
for ( V_12 = V_4 -> V_8 - 1 ; V_12 >= V_13 ; V_12 -- ) {
if ( V_4 -> V_25 [ V_12 ] & 1 ) {
V_14 = V_12 ;
break;
}
}
if ( V_14 >= V_13 ) {
V_16 = V_14 + 1 - V_13 ;
for ( V_12 = 0 , V_18 = V_4 -> V_25 + V_13 ; V_12 < V_16 ; V_12 ++ , V_18 ++ ) {
V_15 = ( * V_18 & 1 ) ? 1 : - 1 ;
V_17 [ V_12 ] = V_15 *
( ( V_18 [ 1 ] & ~ 1 ) - ( V_18 [ 0 ] & ~ 1 ) ) ;
}
F_6 ( V_17 , V_16 , sizeof( V_4 -> V_25 [ 0 ] ) , F_1 , NULL ) ;
for ( V_12 = 0 , V_18 = V_17 ; * V_18 < 0 && V_12 < V_16 ; V_12 ++ , V_18 ++ ) {
V_19 -= * V_18 ;
V_20 = F_4 ( V_20 , - 1 * ( * V_18 ) ) ;
}
V_21 = V_17 [ V_12 ] ;
V_22 = V_17 [ ( V_12 + V_16 - 1 ) / 2 ] ;
V_23 = V_17 [ V_16 - 1 ] ;
}
F_7 ( L_1 , V_4 -> V_26 ) ;
F_7 ( L_2 , V_4 -> V_27 ) ;
F_7 ( L_3 , V_4 -> V_28 ) ;
F_7 ( L_4 , V_4 -> V_29 ) ;
F_7 ( L_5 , V_19 ) ;
F_7 ( L_6 , V_20 ) ;
F_7 ( L_7 , V_21 ) ;
F_7 ( L_8 , V_22 ) ;
F_7 ( L_9 , V_23 ) ;
F_8 ( V_10 , '\n' ) ;
}
static int F_9 ( struct V_9 * V_10 , void * V_30 )
{
struct V_3 * V_4 ;
int V_5 , V_6 ;
void * V_11 ;
V_31:
F_10 ( & V_32 ) ;
V_6 = F_2 () ;
F_11 ( & V_32 ) ;
V_11 = F_12 ( V_6 * sizeof( V_33 -> V_25 [ 0 ] ) ) ;
if ( ! V_11 )
return - V_34 ;
F_10 ( & V_32 ) ;
if ( V_6 < F_2 () ) {
F_11 ( & V_32 ) ;
F_13 ( V_11 ) ;
goto V_31;
}
#define F_14 ( T_1 ) \
seq_printf(m, " %-24s: %8lld\n", #X, (long long int)pcpu_stats_ai.X)
F_15 ( V_10 ,
L_10
L_11
L_12 ) ;
F_14 ( V_35 ) ;
F_14 ( V_36 ) ;
F_14 ( V_37 ) ;
F_14 ( V_38 ) ;
F_14 ( V_39 ) ;
F_14 ( V_40 ) ;
F_8 ( V_10 , '\n' ) ;
#undef F_14
#define F_16 ( T_1 ) \
seq_printf(m, " %-18s: %14llu\n", #X, (unsigned long long)pcpu_stats.X)
F_15 ( V_10 ,
L_13
L_12 ) ;
F_16 ( V_26 ) ;
F_16 ( V_41 ) ;
F_16 ( V_42 ) ;
F_16 ( V_43 ) ;
F_16 ( V_44 ) ;
F_16 ( V_45 ) ;
F_16 ( V_46 ) ;
F_16 ( V_27 ) ;
F_8 ( V_10 , '\n' ) ;
#undef F_16
F_15 ( V_10 ,
L_14
L_12 ) ;
if ( V_47 ) {
F_17 ( V_10 , L_15 ) ;
F_5 ( V_10 , V_47 , V_11 ) ;
}
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
F_3 (chunk, &pcpu_slot[slot], list) {
if ( V_4 == V_33 ) {
F_17 ( V_10 , L_16 ) ;
F_5 ( V_10 , V_4 , V_11 ) ;
} else {
F_17 ( V_10 , L_17 ) ;
F_5 ( V_10 , V_4 , V_11 ) ;
}
}
}
F_11 ( & V_32 ) ;
F_13 ( V_11 ) ;
return 0 ;
}
static int F_18 ( struct V_48 * V_48 , struct V_49 * V_50 )
{
return F_19 ( V_50 , F_9 , NULL ) ;
}
static int T_2 F_20 ( void )
{
F_21 ( L_18 , 0444 , NULL , NULL ,
& V_51 ) ;
return 0 ;
}
