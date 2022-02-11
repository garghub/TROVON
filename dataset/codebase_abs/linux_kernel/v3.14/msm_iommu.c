static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 , int V_6 , void * V_7 )
{
F_2 ( L_1 , V_5 , V_6 ) ;
return 0 ;
}
static int F_3 ( struct V_8 * V_9 , const char * * V_10 , int V_11 )
{
struct V_12 * V_4 = V_9 -> V_4 ;
struct V_13 * V_2 = F_4 ( V_9 ) ;
int V_14 , V_15 ;
for ( V_14 = 0 ; V_14 < V_11 ; V_14 ++ ) {
struct V_3 * V_16 ( const char * V_17 ) ;
struct V_3 * V_18 = V_16 ( V_10 [ V_14 ] ) ;
if ( F_5 ( V_18 ) )
continue;
V_15 = F_6 ( V_2 -> V_19 , V_18 ) ;
if ( V_15 ) {
F_7 ( V_4 -> V_4 , L_2 , V_10 [ V_14 ] ) ;
return V_15 ;
}
}
return 0 ;
}
static int F_8 ( struct V_8 * V_9 , T_1 V_5 ,
struct V_20 * V_21 , unsigned V_22 , int V_23 )
{
struct V_13 * V_2 = F_4 ( V_9 ) ;
struct V_1 * V_19 = V_2 -> V_19 ;
struct V_24 * V_25 ;
unsigned int V_26 = V_5 ;
unsigned int V_14 , V_27 ;
int V_15 ;
if ( ! V_19 || ! V_21 )
return - V_28 ;
F_9 (sgt->sgl, sg, sgt->nents, i) {
T_2 V_29 = F_10 ( V_25 ) - V_25 -> V_30 ;
T_3 V_31 = V_25 -> V_32 + V_25 -> V_30 ;
F_11 ( L_3 , V_14 , V_5 , V_29 , V_31 ) ;
V_15 = F_12 ( V_19 , V_26 , V_29 , V_31 , V_23 ) ;
if ( V_15 )
goto V_33;
V_26 += V_31 ;
}
return 0 ;
V_33:
V_26 = V_5 ;
F_9 (sgt->sgl, sg, i, j) {
T_3 V_31 = V_25 -> V_32 + V_25 -> V_30 ;
F_13 ( V_19 , V_26 , V_31 ) ;
V_26 += V_31 ;
}
return V_15 ;
}
static int F_14 ( struct V_8 * V_9 , T_1 V_5 ,
struct V_20 * V_21 , unsigned V_22 )
{
struct V_13 * V_2 = F_4 ( V_9 ) ;
struct V_1 * V_19 = V_2 -> V_19 ;
struct V_24 * V_25 ;
unsigned int V_26 = V_5 ;
int V_14 ;
F_9 (sgt->sgl, sg, sgt->nents, i) {
T_3 V_31 = V_25 -> V_32 + V_25 -> V_30 ;
T_3 V_34 ;
V_34 = F_13 ( V_19 , V_26 , V_31 ) ;
if ( V_34 < V_31 )
return V_34 ;
F_11 ( L_4 , V_14 , V_5 , V_31 ) ;
F_15 ( ! F_16 ( V_31 , V_35 ) ) ;
V_26 += V_31 ;
}
return 0 ;
}
static void F_17 ( struct V_8 * V_9 )
{
struct V_13 * V_2 = F_4 ( V_9 ) ;
F_18 ( V_2 -> V_19 ) ;
F_19 ( V_2 ) ;
}
struct V_8 * F_20 ( struct V_12 * V_4 , struct V_1 * V_19 )
{
struct V_13 * V_2 ;
V_2 = F_21 ( sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return F_22 ( - V_37 ) ;
V_2 -> V_19 = V_19 ;
F_23 ( & V_2 -> V_38 , V_4 , & V_39 ) ;
F_24 ( V_19 , F_1 , V_4 ) ;
return & V_2 -> V_38 ;
}
