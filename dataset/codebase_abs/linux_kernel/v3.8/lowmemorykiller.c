static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_5 * V_7 = NULL ;
int V_8 = 0 ;
int V_9 ;
int V_10 ;
short V_11 = V_12 + 1 ;
int V_13 = 0 ;
short V_14 ;
int V_15 = F_2 ( V_16 ) ;
int V_17 = F_3 ( V_18 ) ;
int V_19 = F_3 ( V_20 ) -
F_3 ( V_21 ) ;
if ( V_22 < V_15 )
V_15 = V_22 ;
if ( V_23 < V_15 )
V_15 = V_23 ;
for ( V_10 = 0 ; V_10 < V_15 ; V_10 ++ ) {
if ( V_17 < V_24 [ V_10 ] &&
V_19 < V_24 [ V_10 ] ) {
V_11 = V_16 [ V_10 ] ;
break;
}
}
if ( V_4 -> V_25 > 0 )
F_4 ( 3 , L_1 ,
V_4 -> V_25 , V_4 -> V_26 , V_17 ,
V_19 , V_11 ) ;
V_8 = F_3 ( V_27 ) +
F_3 ( V_28 ) +
F_3 ( V_29 ) +
F_3 ( V_30 ) ;
if ( V_4 -> V_25 <= 0 || V_11 == V_12 + 1 ) {
F_4 ( 5 , L_2 ,
V_4 -> V_25 , V_4 -> V_26 , V_8 ) ;
return V_8 ;
}
V_14 = V_11 ;
F_5 () ;
F_6 (tsk) {
struct V_5 * V_31 ;
short V_32 ;
if ( V_6 -> V_33 & V_34 )
continue;
V_31 = F_7 ( V_6 ) ;
if ( ! V_31 )
continue;
if ( F_8 ( V_31 , V_35 ) &&
F_9 ( V_36 , V_37 ) ) {
F_10 ( V_31 ) ;
F_11 () ;
return 0 ;
}
V_32 = V_31 -> signal -> V_32 ;
if ( V_32 < V_11 ) {
F_10 ( V_31 ) ;
continue;
}
V_9 = F_12 ( V_31 -> V_38 ) ;
F_10 ( V_31 ) ;
if ( V_9 <= 0 )
continue;
if ( V_7 ) {
if ( V_32 < V_14 )
continue;
if ( V_32 == V_14 &&
V_9 <= V_13 )
continue;
}
V_7 = V_31 ;
V_13 = V_9 ;
V_14 = V_32 ;
F_4 ( 2 , L_3 ,
V_31 -> V_39 , V_31 -> V_40 , V_32 , V_9 ) ;
}
if ( V_7 ) {
F_4 ( 1 , L_4 ,
V_7 -> V_39 , V_7 -> V_40 ,
V_14 , V_13 ) ;
V_37 = V_36 + V_41 ;
F_13 ( V_42 , V_7 , 0 ) ;
F_14 ( V_7 , V_35 ) ;
V_8 -= V_13 ;
}
F_4 ( 4 , L_2 ,
V_4 -> V_25 , V_4 -> V_26 , V_8 ) ;
F_11 () ;
return V_8 ;
}
static int T_1 F_15 ( void )
{
F_16 ( & V_43 ) ;
return 0 ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_43 ) ;
}
