static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_5 , unsigned long V_6 ,
unsigned long V_7 )
{
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_14 , V_15 ;
unsigned long V_16 ;
unsigned long V_17 ;
if ( V_6 > V_9 -> V_18 )
return - V_19 ;
V_17 = F_3 ( V_5 , V_9 -> V_18 ) ;
V_16 = V_17 / V_9 -> V_18 ;
if ( V_17 > V_9 -> V_5 - V_9 -> V_20 )
return - V_21 ;
V_11 = F_4 ( sizeof( struct V_10 ) , V_22 ) ;
if ( ! V_11 )
return - V_21 ;
V_14 = F_5 ( V_11 , V_16 , V_22 ) ;
if ( V_14 ) {
F_6 ( V_11 ) ;
return V_14 ;
}
V_13 = V_11 -> V_23 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
unsigned long V_24 = F_7 ( V_9 -> V_25 ,
V_9 -> V_18 ) ;
if ( ! V_24 )
goto V_26;
F_8 ( V_13 , F_9 ( F_10 ( V_24 ) ) ,
V_9 -> V_18 , 0 ) ;
V_13 = F_11 ( V_13 ) ;
}
V_4 -> V_27 = V_11 ;
V_9 -> V_20 += V_17 ;
return 0 ;
V_26:
V_13 = V_11 -> V_23 ;
for ( V_15 -= 1 ; V_15 >= 0 ; V_15 -- ) {
F_12 ( V_9 -> V_25 , F_13 ( F_14 ( V_13 ) ) ,
V_13 -> V_28 ) ;
V_13 = F_11 ( V_13 ) ;
}
F_15 ( V_11 ) ;
F_6 ( V_11 ) ;
return - V_21 ;
}
static void F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
struct V_10 * V_11 = V_4 -> V_27 ;
struct V_12 * V_13 ;
int V_15 ;
unsigned long V_17 ;
V_17 = F_3 ( V_4 -> V_5 , V_9 -> V_18 ) ;
F_17 ( V_4 ) ;
if ( F_18 ( V_4 ) )
F_19 ( NULL , V_11 -> V_23 , V_11 -> V_29 ,
V_30 ) ;
F_20 (table->sgl, sg, table->nents, i) {
F_12 ( V_9 -> V_25 , F_13 ( F_14 ( V_13 ) ) ,
V_13 -> V_28 ) ;
}
V_9 -> V_20 -= V_17 ;
F_15 ( V_11 ) ;
F_6 ( V_11 ) ;
}
static struct V_10 * F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return V_4 -> V_27 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
struct V_1 * F_23 ( struct V_31 * V_32 )
{
struct V_8 * V_9 ;
int V_14 ;
struct V_33 * V_33 ;
T_1 V_5 ;
V_33 = F_9 ( F_10 ( V_32 -> V_34 ) ) ;
V_5 = V_32 -> V_5 ;
F_24 ( NULL , V_33 , V_5 , V_30 ) ;
V_14 = F_25 ( V_33 , V_5 , F_26 ( V_35 ) ) ;
if ( V_14 )
return F_27 ( V_14 ) ;
V_9 = F_28 ( sizeof( struct V_8 ) , V_22 ) ;
if ( ! V_9 )
return F_27 ( - V_21 ) ;
V_9 -> V_18 = ( unsigned long ) V_32 -> V_36 ;
V_9 -> V_25 = F_29 ( F_30 ( V_9 -> V_18 ) +
V_37 , - 1 ) ;
if ( ! V_9 -> V_25 ) {
V_14 = - V_21 ;
goto V_38;
}
V_9 -> V_34 = V_32 -> V_34 ;
V_9 -> V_5 = V_32 -> V_5 ;
V_9 -> V_20 = 0 ;
F_31 ( V_9 -> V_25 , V_9 -> V_34 , V_32 -> V_5 , - 1 ) ;
V_9 -> V_2 . V_39 = & V_40 ;
V_9 -> V_2 . type = V_41 ;
V_9 -> V_2 . V_7 = V_42 ;
F_32 ( L_1 , V_43 ,
V_9 -> V_34 , V_32 -> V_5 , V_32 -> V_6 ) ;
return & V_9 -> V_2 ;
V_38:
F_6 ( V_9 ) ;
return F_27 ( V_14 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
F_34 ( V_9 -> V_25 ) ;
F_6 ( V_9 ) ;
V_9 = NULL ;
}
