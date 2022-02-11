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
short V_18 ;
int V_19 = F_4 ( V_20 ) ;
int V_21 = F_2 ( V_22 ) - V_23 ;
int V_24 = F_2 ( V_25 ) -
F_2 ( V_26 ) -
F_5 () ;
if ( V_27 < V_19 )
V_19 = V_27 ;
if ( V_28 < V_19 )
V_19 = V_28 ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ ) {
if ( V_21 < V_29 [ V_14 ] &&
V_24 < V_29 [ V_14 ] ) {
V_15 = V_20 [ V_14 ] ;
break;
}
}
F_6 ( 3 , L_1 ,
V_4 -> V_30 , V_4 -> V_31 , V_21 ,
V_24 , V_15 ) ;
if ( V_15 == V_16 + 1 ) {
F_6 ( 5 , L_2 ,
V_4 -> V_30 , V_4 -> V_31 ) ;
return 0 ;
}
V_18 = V_15 ;
F_7 () ;
F_8 (tsk) {
struct V_9 * V_32 ;
short V_33 ;
if ( V_10 -> V_34 & V_35 )
continue;
V_32 = F_9 ( V_10 ) ;
if ( ! V_32 )
continue;
if ( F_10 ( V_32 , V_36 ) &&
F_11 ( V_37 , V_38 ) ) {
F_12 ( V_32 ) ;
F_13 () ;
return 0 ;
}
V_33 = V_32 -> signal -> V_33 ;
if ( V_33 < V_15 ) {
F_12 ( V_32 ) ;
continue;
}
V_13 = F_14 ( V_32 -> V_39 ) ;
F_12 ( V_32 ) ;
if ( V_13 <= 0 )
continue;
if ( V_11 ) {
if ( V_33 < V_18 )
continue;
if ( V_33 == V_18 &&
V_13 <= V_17 )
continue;
}
V_11 = V_32 ;
V_17 = V_13 ;
V_18 = V_33 ;
F_6 ( 2 , L_3 ,
V_32 -> V_40 , V_32 -> V_41 , V_33 , V_13 ) ;
}
if ( V_11 ) {
F_15 ( V_11 ) ;
F_16 ( V_42 , V_11 , 0 ) ;
if ( V_11 -> V_39 )
F_17 ( V_11 ) ;
F_12 ( V_11 ) ;
F_6 ( 1 , L_4 ,
V_11 -> V_40 , V_11 -> V_41 ,
V_18 , V_17 ) ;
V_38 = V_37 + V_43 ;
V_12 += V_17 ;
}
F_6 ( 4 , L_5 ,
V_4 -> V_30 , V_4 -> V_31 , V_12 ) ;
F_13 () ;
return V_12 ;
}
static int T_1 F_18 ( void )
{
F_19 ( & V_44 ) ;
return 0 ;
}
