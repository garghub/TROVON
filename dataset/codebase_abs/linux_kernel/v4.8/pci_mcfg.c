T_1 F_1 ( T_2 V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_2 (e, &pci_mcfg_list, list) {
if ( V_5 -> V_6 == V_1 && V_5 -> V_7 == V_3 -> V_8 &&
V_5 -> V_9 >= V_3 -> V_10 )
return V_5 -> V_11 ;
}
return 0 ;
}
static T_3 int F_3 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_4 * V_5 , * V_18 ;
int V_19 , V_20 ;
if ( V_13 -> V_21 < sizeof( struct V_14 ) )
return - V_22 ;
V_20 = ( V_13 -> V_21 - sizeof( struct V_14 ) ) /
sizeof( struct V_16 ) ;
V_15 = (struct V_14 * ) V_13 ;
V_17 = (struct V_16 * ) & V_15 [ 1 ] ;
V_18 = F_4 ( V_20 , sizeof( * V_18 ) , V_23 ) ;
if ( ! V_18 )
return - V_24 ;
for ( V_19 = 0 , V_5 = V_18 ; V_19 < V_20 ; V_19 ++ , V_17 ++ , V_5 ++ ) {
V_5 -> V_6 = V_17 -> V_25 ;
V_5 -> V_11 = V_17 -> V_26 ;
V_5 -> V_7 = V_17 -> V_27 ;
V_5 -> V_9 = V_17 -> V_28 ;
F_5 ( & V_5 -> V_29 , & V_30 ) ;
}
F_6 ( L_1 , V_20 ) ;
return 0 ;
}
void T_3 F_7 ( void )
{
int V_31 = F_8 ( V_32 , F_3 ) ;
if ( V_31 )
F_9 ( L_2 , V_31 ) ;
}
