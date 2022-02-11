static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 , int V_6 , void * V_7 )
{
struct V_8 * V_9 = V_7 ;
if ( V_9 -> V_10 . V_11 )
return V_9 -> V_10 . V_11 ( V_9 -> V_10 . V_7 , V_5 , V_6 ) ;
F_2 ( L_1 , V_5 , V_6 ) ;
return 0 ;
}
static int F_3 ( struct V_12 * V_13 , const char * const * V_14 ,
int V_15 )
{
struct V_8 * V_9 = F_4 ( V_13 ) ;
return F_5 ( V_9 -> V_2 , V_13 -> V_4 ) ;
}
static void F_6 ( struct V_12 * V_13 , const char * const * V_14 ,
int V_15 )
{
struct V_8 * V_9 = F_4 ( V_13 ) ;
F_7 ( V_9 -> V_2 , V_13 -> V_4 ) ;
}
static int F_8 ( struct V_12 * V_13 , T_1 V_5 ,
struct V_16 * V_17 , unsigned V_18 , int V_19 )
{
struct V_8 * V_9 = F_4 ( V_13 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_20 * V_21 ;
unsigned long V_22 = V_5 ;
unsigned int V_23 , V_24 ;
int V_25 ;
if ( ! V_2 || ! V_17 )
return - V_26 ;
F_9 (sgt->sgl, sg, sgt->nents, i) {
T_2 V_27 = F_10 ( V_21 ) - V_21 -> V_28 ;
T_3 V_29 = V_21 -> V_30 + V_21 -> V_28 ;
F_11 ( L_2 , V_23 , V_22 , ( unsigned long ) V_27 , V_29 ) ;
V_25 = F_12 ( V_2 , V_22 , V_27 , V_29 , V_19 ) ;
if ( V_25 )
goto V_31;
V_22 += V_29 ;
}
return 0 ;
V_31:
V_22 = V_5 ;
F_9 (sgt->sgl, sg, i, j) {
T_3 V_29 = V_21 -> V_30 + V_21 -> V_28 ;
F_13 ( V_2 , V_22 , V_29 ) ;
V_22 += V_29 ;
}
return V_25 ;
}
static int F_14 ( struct V_12 * V_13 , T_1 V_5 ,
struct V_16 * V_17 , unsigned V_18 )
{
struct V_8 * V_9 = F_4 ( V_13 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_20 * V_21 ;
unsigned long V_22 = V_5 ;
int V_23 ;
F_9 (sgt->sgl, sg, sgt->nents, i) {
T_3 V_29 = V_21 -> V_30 + V_21 -> V_28 ;
T_3 V_32 ;
V_32 = F_13 ( V_2 , V_22 , V_29 ) ;
if ( V_32 < V_29 )
return V_32 ;
F_11 ( L_3 , V_23 , V_22 , V_29 ) ;
F_15 ( ! F_16 ( V_29 ) ) ;
V_22 += V_29 ;
}
return 0 ;
}
static void F_17 ( struct V_12 * V_13 )
{
struct V_8 * V_9 = F_4 ( V_13 ) ;
F_18 ( V_9 -> V_2 ) ;
F_19 ( V_9 ) ;
}
struct V_12 * F_20 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = F_21 ( sizeof( * V_9 ) , V_33 ) ;
if ( ! V_9 )
return F_22 ( - V_34 ) ;
V_9 -> V_2 = V_2 ;
F_23 ( & V_9 -> V_10 , V_4 , & V_35 ) ;
F_24 ( V_2 , F_1 , V_9 ) ;
return & V_9 -> V_10 ;
}
