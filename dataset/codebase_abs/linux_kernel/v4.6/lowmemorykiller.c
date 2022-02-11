static unsigned long F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return F_2 ( V_5 ) +
F_2 ( V_6 ) +
F_2 ( V_7 ) +
F_2 ( V_8 ) ;
}
static unsigned long F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_9 * V_11 = NULL ;
unsigned long V_12 = 0 ;
int V_13 ;
int V_14 ;
short V_15 = V_16 + 1 ;
int V_17 = 0 ;
int V_18 = 0 ;
short V_19 ;
int V_20 = F_4 ( V_21 ) ;
int V_22 = F_2 ( V_23 ) - V_24 ;
int V_25 = F_2 ( V_26 ) -
F_2 ( V_27 ) -
F_5 () ;
if ( V_28 < V_20 )
V_20 = V_28 ;
if ( V_29 < V_20 )
V_20 = V_29 ;
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
V_17 = V_30 [ V_14 ] ;
if ( V_22 < V_17 && V_25 < V_17 ) {
V_15 = V_21 [ V_14 ] ;
break;
}
}
F_6 ( 3 , L_1 ,
V_4 -> V_31 , V_4 -> V_32 , V_22 ,
V_25 , V_15 ) ;
if ( V_15 == V_16 + 1 ) {
F_6 ( 5 , L_2 ,
V_4 -> V_31 , V_4 -> V_32 ) ;
return 0 ;
}
V_19 = V_15 ;
F_7 () ;
F_8 (tsk) {
struct V_9 * V_33 ;
short V_34 ;
if ( V_10 -> V_35 & V_36 )
continue;
V_33 = F_9 ( V_10 ) ;
if ( ! V_33 )
continue;
if ( F_10 ( V_33 , V_37 ) &&
F_11 ( V_38 , V_39 ) ) {
F_12 ( V_33 ) ;
F_13 () ;
return 0 ;
}
V_34 = V_33 -> signal -> V_34 ;
if ( V_34 < V_15 ) {
F_12 ( V_33 ) ;
continue;
}
V_13 = F_14 ( V_33 -> V_40 ) ;
F_12 ( V_33 ) ;
if ( V_13 <= 0 )
continue;
if ( V_11 ) {
if ( V_34 < V_19 )
continue;
if ( V_34 == V_19 &&
V_13 <= V_18 )
continue;
}
V_11 = V_33 ;
V_18 = V_13 ;
V_19 = V_34 ;
F_6 ( 2 , L_3 ,
V_33 -> V_41 , V_33 -> V_42 , V_34 , V_13 ) ;
}
if ( V_11 ) {
F_15 ( V_11 ) ;
F_16 ( V_43 , V_11 , 0 ) ;
if ( V_11 -> V_40 )
F_17 ( V_11 ) ;
F_12 ( V_11 ) ;
F_6 ( 1 , L_4
L_5
L_6
L_7 ,
V_11 -> V_41 , V_11 -> V_42 ,
V_19 ,
V_18 * ( long ) ( V_44 / 1024 ) ,
V_45 -> V_41 , V_45 -> V_42 ,
V_25 * ( long ) ( V_44 / 1024 ) ,
V_17 * ( long ) ( V_44 / 1024 ) ,
V_15 ,
V_22 * ( long ) ( V_44 / 1024 ) ) ;
V_39 = V_38 + V_46 ;
V_12 += V_18 ;
}
F_6 ( 4 , L_8 ,
V_4 -> V_31 , V_4 -> V_32 , V_12 ) ;
F_13 () ;
return V_12 ;
}
static int T_1 F_18 ( void )
{
F_19 ( & V_47 ) ;
return 0 ;
}
