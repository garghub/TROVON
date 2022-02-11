static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 , int V_6 , void * V_7 )
{
F_2 ( L_1 , V_5 , V_6 ) ;
return - V_8 ;
}
static int F_3 ( struct V_9 * V_10 , const char * * V_11 , int V_12 )
{
struct V_13 * V_4 = V_10 -> V_4 ;
struct V_14 * V_2 = F_4 ( V_10 ) ;
int V_15 , V_16 ;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ ) {
struct V_3 * V_17 ( const char * V_18 ) ;
struct V_3 * V_19 = V_17 ( V_11 [ V_15 ] ) ;
if ( F_5 ( V_19 ) ) {
F_6 ( V_4 -> V_4 , L_2 , V_11 [ V_15 ] ) ;
continue;
}
V_16 = F_7 ( V_2 -> V_20 , V_19 ) ;
if ( V_16 ) {
F_6 ( V_4 -> V_4 , L_3 , V_11 [ V_15 ] ) ;
return V_16 ;
}
}
return 0 ;
}
static void F_8 ( struct V_9 * V_10 , const char * * V_11 , int V_12 )
{
struct V_14 * V_2 = F_4 ( V_10 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ ) {
struct V_3 * V_17 ( const char * V_18 ) ;
struct V_3 * V_19 = V_17 ( V_11 [ V_15 ] ) ;
if ( F_5 ( V_19 ) )
continue;
F_9 ( V_2 -> V_20 , V_19 ) ;
}
}
static int F_10 ( struct V_9 * V_10 , T_1 V_5 ,
struct V_21 * V_22 , unsigned V_23 , int V_24 )
{
struct V_14 * V_2 = F_4 ( V_10 ) ;
struct V_1 * V_20 = V_2 -> V_20 ;
struct V_25 * V_26 ;
unsigned int V_27 = V_5 ;
unsigned int V_15 , V_28 ;
int V_16 ;
if ( ! V_20 || ! V_22 )
return - V_29 ;
F_11 (sgt->sgl, sg, sgt->nents, i) {
T_2 V_30 = F_12 ( V_26 ) - V_26 -> V_31 ;
T_3 V_32 = V_26 -> V_33 + V_26 -> V_31 ;
F_13 ( L_4 , V_15 , V_5 , V_30 , V_32 ) ;
V_16 = F_14 ( V_20 , V_27 , V_30 , V_32 , V_24 ) ;
if ( V_16 )
goto V_34;
V_27 += V_32 ;
}
return 0 ;
V_34:
V_27 = V_5 ;
F_11 (sgt->sgl, sg, i, j) {
T_3 V_32 = V_26 -> V_33 + V_26 -> V_31 ;
F_15 ( V_20 , V_27 , V_32 ) ;
V_27 += V_32 ;
}
return V_16 ;
}
static int F_16 ( struct V_9 * V_10 , T_1 V_5 ,
struct V_21 * V_22 , unsigned V_23 )
{
struct V_14 * V_2 = F_4 ( V_10 ) ;
struct V_1 * V_20 = V_2 -> V_20 ;
struct V_25 * V_26 ;
unsigned int V_27 = V_5 ;
int V_15 ;
F_11 (sgt->sgl, sg, sgt->nents, i) {
T_3 V_32 = V_26 -> V_33 + V_26 -> V_31 ;
T_3 V_35 ;
V_35 = F_15 ( V_20 , V_27 , V_32 ) ;
if ( V_35 < V_32 )
return V_35 ;
F_13 ( L_5 , V_15 , V_5 , V_32 ) ;
F_17 ( ! F_18 ( V_32 ) ) ;
V_27 += V_32 ;
}
return 0 ;
}
static void F_19 ( struct V_9 * V_10 )
{
struct V_14 * V_2 = F_4 ( V_10 ) ;
F_20 ( V_2 -> V_20 ) ;
F_21 ( V_2 ) ;
}
struct V_9 * F_22 ( struct V_13 * V_4 , struct V_1 * V_20 )
{
struct V_14 * V_2 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return F_24 ( - V_37 ) ;
V_2 -> V_20 = V_20 ;
F_25 ( & V_2 -> V_38 , V_4 , & V_39 ) ;
F_26 ( V_20 , F_1 , V_4 ) ;
return & V_2 -> V_38 ;
}
