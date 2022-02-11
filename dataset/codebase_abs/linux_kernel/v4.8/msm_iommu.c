static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 , int V_6 , void * V_7 )
{
F_2 ( L_1 , V_5 , V_6 ) ;
return 0 ;
}
static int F_3 ( struct V_8 * V_9 , const char * const * V_10 ,
int V_11 )
{
struct V_12 * V_2 = F_4 ( V_9 ) ;
return F_5 ( V_2 -> V_13 , V_9 -> V_4 ) ;
}
static void F_6 ( struct V_8 * V_9 , const char * const * V_10 ,
int V_11 )
{
struct V_12 * V_2 = F_4 ( V_9 ) ;
F_7 ( V_2 -> V_13 , V_9 -> V_4 ) ;
}
static int F_8 ( struct V_8 * V_9 , T_1 V_5 ,
struct V_14 * V_15 , unsigned V_16 , int V_17 )
{
struct V_12 * V_2 = F_4 ( V_9 ) ;
struct V_1 * V_13 = V_2 -> V_13 ;
struct V_18 * V_19 ;
unsigned int V_20 = V_5 ;
unsigned int V_21 , V_22 ;
int V_23 ;
if ( ! V_13 || ! V_15 )
return - V_24 ;
F_9 (sgt->sgl, sg, sgt->nents, i) {
T_2 V_25 = F_10 ( V_19 ) - V_19 -> V_26 ;
T_3 V_27 = V_19 -> V_28 + V_19 -> V_26 ;
F_11 ( L_2 , V_21 , V_20 , ( unsigned long ) V_25 , V_27 ) ;
V_23 = F_12 ( V_13 , V_20 , V_25 , V_27 , V_17 ) ;
if ( V_23 )
goto V_29;
V_20 += V_27 ;
}
return 0 ;
V_29:
V_20 = V_5 ;
F_9 (sgt->sgl, sg, i, j) {
T_3 V_27 = V_19 -> V_28 + V_19 -> V_26 ;
F_13 ( V_13 , V_20 , V_27 ) ;
V_20 += V_27 ;
}
return V_23 ;
}
static int F_14 ( struct V_8 * V_9 , T_1 V_5 ,
struct V_14 * V_15 , unsigned V_16 )
{
struct V_12 * V_2 = F_4 ( V_9 ) ;
struct V_1 * V_13 = V_2 -> V_13 ;
struct V_18 * V_19 ;
unsigned int V_20 = V_5 ;
int V_21 ;
F_9 (sgt->sgl, sg, sgt->nents, i) {
T_3 V_27 = V_19 -> V_28 + V_19 -> V_26 ;
T_3 V_30 ;
V_30 = F_13 ( V_13 , V_20 , V_27 ) ;
if ( V_30 < V_27 )
return V_30 ;
F_11 ( L_3 , V_21 , V_20 , V_27 ) ;
F_15 ( ! F_16 ( V_27 ) ) ;
V_20 += V_27 ;
}
return 0 ;
}
static void F_17 ( struct V_8 * V_9 )
{
struct V_12 * V_2 = F_4 ( V_9 ) ;
F_18 ( V_2 -> V_13 ) ;
F_19 ( V_2 ) ;
}
struct V_8 * F_20 ( struct V_3 * V_4 , struct V_1 * V_13 )
{
struct V_12 * V_2 ;
V_2 = F_21 ( sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
return F_22 ( - V_32 ) ;
V_2 -> V_13 = V_13 ;
F_23 ( & V_2 -> V_33 , V_4 , & V_34 ) ;
F_24 ( V_13 , F_1 , V_4 ) ;
return & V_2 -> V_33 ;
}
