static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
if ( V_6 == V_7 ) {
V_7 = NULL ;
F_2 ( & V_8 ) ;
}
return V_9 ;
}
static int F_3 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_5 * V_14 ;
struct V_5 * V_15 = NULL ;
int V_16 = 0 ;
int V_17 ;
int V_18 ;
int V_19 = V_20 + 1 ;
int V_21 = 0 ;
int V_22 ;
int V_23 = F_4 ( V_24 ) ;
int V_25 = F_5 ( V_26 ) ;
int V_27 = F_5 ( V_28 ) -
F_5 ( V_29 ) ;
if ( V_7 &&
F_6 ( V_30 , V_31 ) )
return 0 ;
if ( V_32 < V_23 )
V_23 = V_32 ;
if ( V_33 < V_23 )
V_23 = V_33 ;
for ( V_18 = 0 ; V_18 < V_23 ; V_18 ++ ) {
if ( V_25 < V_34 [ V_18 ] &&
V_27 < V_34 [ V_18 ] ) {
V_19 = V_24 [ V_18 ] ;
break;
}
}
if ( V_13 -> V_35 > 0 )
F_7 ( 3 , L_1 ,
V_13 -> V_35 , V_13 -> V_36 , V_25 ,
V_27 , V_19 ) ;
V_16 = F_5 ( V_37 ) +
F_5 ( V_38 ) +
F_5 ( V_39 ) +
F_5 ( V_40 ) ;
if ( V_13 -> V_35 <= 0 || V_19 == V_20 + 1 ) {
F_7 ( 5 , L_2 ,
V_13 -> V_35 , V_13 -> V_36 , V_16 ) ;
return V_16 ;
}
V_22 = V_19 ;
F_8 ( & V_41 ) ;
F_9 (p) {
struct V_42 * V_43 ;
struct V_44 * V_45 ;
int V_46 ;
F_10 ( V_14 ) ;
V_43 = V_14 -> V_43 ;
V_45 = V_14 -> signal ;
if ( ! V_43 || ! V_45 ) {
F_11 ( V_14 ) ;
continue;
}
V_46 = V_45 -> V_46 ;
if ( V_46 < V_19 ) {
F_11 ( V_14 ) ;
continue;
}
V_17 = F_12 ( V_43 ) ;
F_11 ( V_14 ) ;
if ( V_17 <= 0 )
continue;
if ( V_15 ) {
if ( V_46 < V_22 )
continue;
if ( V_46 == V_22 &&
V_17 <= V_21 )
continue;
}
V_15 = V_14 ;
V_21 = V_17 ;
V_22 = V_46 ;
F_7 ( 2 , L_3 ,
V_14 -> V_47 , V_14 -> V_48 , V_46 , V_17 ) ;
}
if ( V_15 ) {
F_7 ( 1 , L_4 ,
V_15 -> V_47 , V_15 -> V_48 ,
V_22 , V_21 ) ;
#ifdef F_13
V_7 = V_15 ;
V_31 = V_30 + V_49 ;
F_14 ( & V_8 ) ;
#endif
F_15 ( V_50 , V_15 ) ;
V_16 -= V_21 ;
}
F_7 ( 4 , L_2 ,
V_13 -> V_35 , V_13 -> V_36 , V_16 ) ;
F_16 ( & V_41 ) ;
return V_16 ;
}
static int T_1 F_17 ( void )
{
F_18 ( & V_51 ) ;
return 0 ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_51 ) ;
}
