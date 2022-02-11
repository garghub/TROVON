static long F_1 ( unsigned long V_1 )
{
return F_2 ( ( V_1 >> V_2 )
* sizeof( V_3 ) , V_4 ) / V_4 ;
}
static void F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = V_6 -> V_7 ;
int V_8 ;
F_4 ( & V_7 -> V_9 ) ;
F_5 ( & V_6 -> V_10 ) ;
for ( V_8 = 0 ; V_8 < F_1 ( V_6 -> V_1 ) ; V_8 ++ )
F_6 ( V_6 -> V_11 [ V_8 ] ) ;
F_7 ( V_6 ) ;
F_8 ( & V_7 -> V_9 ) ;
F_9 ( V_7 ) ;
}
static int F_10 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_5 * V_6 = V_13 -> V_16 -> V_17 ;
struct V_18 * V_18 ;
if ( V_15 -> V_19 >= F_1 ( V_6 -> V_1 ) )
return V_20 ;
V_18 = V_6 -> V_11 [ V_15 -> V_19 ] ;
F_11 ( V_18 ) ;
V_15 -> V_18 = V_18 ;
return 0 ;
}
static int F_12 ( struct V_21 * V_21 , struct V_12 * V_13 )
{
V_13 -> V_22 = & V_23 ;
return 0 ;
}
static int F_13 ( struct V_24 * V_24 , struct V_21 * V_25 )
{
struct V_5 * V_6 = V_25 -> V_17 ;
F_3 ( V_6 ) ;
return 0 ;
}
long F_14 ( struct V_7 * V_7 ,
struct V_26 * args )
{
struct V_5 * V_6 = NULL ;
long V_27 ;
int V_28 = - V_29 ;
int V_8 ;
F_15 (stt, &kvm->arch.spapr_tce_tables, list) {
if ( V_6 -> V_30 == args -> V_30 )
return - V_31 ;
}
V_27 = F_1 ( args -> V_1 ) ;
V_6 = F_16 ( sizeof( * V_6 ) + V_27 * sizeof( struct V_18 * ) ,
V_32 ) ;
if ( ! V_6 )
goto V_33;
V_6 -> V_30 = args -> V_30 ;
V_6 -> V_1 = args -> V_1 ;
V_6 -> V_7 = V_7 ;
for ( V_8 = 0 ; V_8 < V_27 ; V_8 ++ ) {
V_6 -> V_11 [ V_8 ] = F_17 ( V_32 | V_34 ) ;
if ( ! V_6 -> V_11 [ V_8 ] )
goto V_33;
}
F_18 ( V_7 ) ;
F_4 ( & V_7 -> V_9 ) ;
F_19 ( & V_6 -> V_10 , & V_7 -> V_35 . V_36 ) ;
F_8 ( & V_7 -> V_9 ) ;
return F_20 ( L_1 , & V_37 ,
V_6 , V_38 | V_39 ) ;
V_33:
if ( V_6 ) {
for ( V_8 = 0 ; V_8 < V_27 ; V_8 ++ )
if ( V_6 -> V_11 [ V_8 ] )
F_6 ( V_6 -> V_11 [ V_8 ] ) ;
F_7 ( V_6 ) ;
}
return V_28 ;
}
