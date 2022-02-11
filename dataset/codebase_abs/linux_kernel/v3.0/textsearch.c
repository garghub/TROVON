static inline struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 () ;
F_3 (o, &ts_ops, list) {
if ( ! strcmp ( V_2 , V_3 -> V_2 ) ) {
if ( ! F_4 ( V_3 -> V_4 ) )
V_3 = NULL ;
F_5 () ;
return V_3 ;
}
}
F_5 () ;
return NULL ;
}
int F_6 ( struct V_1 * V_5 )
{
int V_6 = - V_7 ;
struct V_1 * V_3 ;
if ( V_5 -> V_2 == NULL || V_5 -> V_8 == NULL || V_5 -> V_9 == NULL ||
V_5 -> V_10 == NULL || V_5 -> V_11 == NULL )
return - V_12 ;
F_7 ( & V_13 ) ;
F_8 (o, &ts_ops, list) {
if ( ! strcmp ( V_5 -> V_2 , V_3 -> V_2 ) )
goto V_14;
}
F_9 ( & V_5 -> V_15 , & V_1 ) ;
V_6 = 0 ;
V_14:
F_10 ( & V_13 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_5 )
{
int V_6 = 0 ;
struct V_1 * V_3 ;
F_7 ( & V_13 ) ;
F_8 (o, &ts_ops, list) {
if ( V_3 == V_5 ) {
F_12 ( & V_3 -> V_15 ) ;
goto V_16;
}
}
V_6 = - V_17 ;
V_16:
F_10 ( & V_13 ) ;
return V_6 ;
}
static unsigned int F_13 ( unsigned int V_18 , const T_1 * * V_19 ,
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_23 -> V_26 ;
if ( F_14 ( V_18 < V_25 -> V_27 ) ) {
* V_19 = V_25 -> V_28 + V_18 ;
return V_25 -> V_27 - V_18 ;
}
return 0 ;
}
unsigned int F_15 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
const void * V_28 , unsigned int V_27 )
{
struct V_24 * V_25 = (struct V_24 * ) V_23 -> V_26 ;
V_21 -> V_29 = F_13 ;
V_25 -> V_28 = V_28 ;
V_25 -> V_27 = V_27 ;
return F_16 ( V_21 , V_23 ) ;
}
struct V_20 * F_17 ( const char * V_30 , const void * V_31 ,
unsigned int V_27 , T_2 V_32 , int V_33 )
{
int V_6 = - V_17 ;
struct V_20 * V_21 ;
struct V_1 * V_5 ;
if ( V_27 == 0 )
return F_18 ( - V_12 ) ;
V_5 = F_1 ( V_30 ) ;
#ifdef F_19
if ( V_5 == NULL && V_33 & V_34 ) {
F_20 ( L_1 , V_30 ) ;
V_5 = F_1 ( V_30 ) ;
}
#endif
if ( V_5 == NULL )
goto V_14;
V_21 = V_5 -> V_9 ( V_31 , V_27 , V_32 , V_33 ) ;
if ( F_21 ( V_21 ) ) {
V_6 = F_22 ( V_21 ) ;
goto V_14;
}
V_21 -> V_5 = V_5 ;
return V_21 ;
V_14:
if ( V_5 )
F_23 ( V_5 -> V_4 ) ;
return F_18 ( V_6 ) ;
}
void F_24 ( struct V_20 * V_21 )
{
if ( V_21 -> V_5 ) {
if ( V_21 -> V_5 -> V_35 )
V_21 -> V_5 -> V_35 ( V_21 ) ;
F_23 ( V_21 -> V_5 -> V_4 ) ;
}
F_25 ( V_21 ) ;
}
