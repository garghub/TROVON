static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_5 ,
unsigned long V_6 )
{
struct V_7 * V_8 =
F_2 ( V_2 , struct V_7 , V_2 ) ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 , V_14 ;
unsigned long V_15 ;
unsigned long V_16 ;
V_16 = F_3 ( V_5 , V_8 -> V_17 ) ;
V_15 = V_16 / V_8 -> V_17 ;
if ( V_16 > V_8 -> V_5 - V_8 -> V_18 )
return - V_19 ;
V_10 = F_4 ( sizeof( * V_10 ) , V_20 ) ;
if ( ! V_10 )
return - V_19 ;
V_13 = F_5 ( V_10 , V_15 , V_20 ) ;
if ( V_13 ) {
F_6 ( V_10 ) ;
return V_13 ;
}
V_12 = V_10 -> V_21 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
unsigned long V_22 = F_7 ( V_8 -> V_23 ,
V_8 -> V_17 ) ;
if ( ! V_22 )
goto V_24;
F_8 ( V_12 , F_9 ( F_10 ( V_22 ) ) ,
V_8 -> V_17 , 0 ) ;
V_12 = F_11 ( V_12 ) ;
}
V_4 -> V_9 = V_10 ;
V_8 -> V_18 += V_16 ;
return 0 ;
V_24:
V_12 = V_10 -> V_21 ;
for ( V_14 -= 1 ; V_14 >= 0 ; V_14 -- ) {
F_12 ( V_8 -> V_23 , F_13 ( F_14 ( V_12 ) ) ,
V_12 -> V_25 ) ;
V_12 = F_11 ( V_12 ) ;
}
F_15 ( V_10 ) ;
F_6 ( V_10 ) ;
return - V_19 ;
}
static void F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 =
F_2 ( V_2 , struct V_7 , V_2 ) ;
struct V_9 * V_10 = V_4 -> V_9 ;
struct V_11 * V_12 ;
int V_14 ;
unsigned long V_16 ;
V_16 = F_3 ( V_4 -> V_5 , V_8 -> V_17 ) ;
F_17 ( V_4 ) ;
F_18 (table->sgl, sg, table->nents, i) {
F_12 ( V_8 -> V_23 , F_13 ( F_14 ( V_12 ) ) ,
V_12 -> V_25 ) ;
}
V_8 -> V_18 -= V_16 ;
F_15 ( V_10 ) ;
F_6 ( V_10 ) ;
}
struct V_1 * F_19 ( struct V_26 * V_27 )
{
struct V_7 * V_8 ;
int V_13 ;
struct V_28 * V_28 ;
T_1 V_5 ;
V_28 = F_9 ( F_10 ( V_27 -> V_29 ) ) ;
V_5 = V_27 -> V_5 ;
V_13 = F_20 ( V_28 , V_5 , F_21 ( V_30 ) ) ;
if ( V_13 )
return F_22 ( V_13 ) ;
V_8 = F_23 ( sizeof( * V_8 ) , V_20 ) ;
if ( ! V_8 )
return F_22 ( - V_19 ) ;
V_8 -> V_17 = ( unsigned long ) V_27 -> V_31 ;
V_8 -> V_23 = F_24 ( F_25 ( V_8 -> V_17 ) +
V_32 , - 1 ) ;
if ( ! V_8 -> V_23 ) {
V_13 = - V_19 ;
goto V_33;
}
V_8 -> V_29 = V_27 -> V_29 ;
V_8 -> V_5 = V_27 -> V_5 ;
V_8 -> V_18 = 0 ;
F_26 ( V_8 -> V_23 , V_8 -> V_29 , V_27 -> V_5 , - 1 ) ;
V_8 -> V_2 . V_34 = & V_35 ;
V_8 -> V_2 . type = V_36 ;
V_8 -> V_2 . V_6 = V_37 ;
F_27 ( L_1 , V_38 ,
& V_8 -> V_29 , V_27 -> V_5 ) ;
return & V_8 -> V_2 ;
V_33:
F_6 ( V_8 ) ;
return F_22 ( V_13 ) ;
}
