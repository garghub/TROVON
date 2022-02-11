void * F_1 ( struct V_1 * V_2 ,
void * V_3 )
{
struct V_4 * V_5 ;
struct V_4 T_1 * V_6 ;
int V_7 , V_8 ;
V_6 = F_2 ( struct V_4 ) ;
if ( V_6 == NULL )
return F_3 ( - V_9 ) ;
F_4 (cpu) {
V_5 = F_5 ( V_6 , V_8 ) ;
V_5 -> V_5 = V_2 -> V_10 -> V_11 ( V_2 , V_3 ) ;
if ( F_6 ( V_5 -> V_5 ) ) {
V_7 = F_7 ( V_5 -> V_5 ) ;
goto V_12;
}
}
F_8 ( V_3 ) ;
return ( V_13 void * ) V_6 ;
V_12:
F_4 (cpu) {
V_5 = F_5 ( V_6 , V_8 ) ;
if ( ! F_9 ( V_5 -> V_5 ) )
V_2 -> V_10 -> free ( V_5 -> V_5 ) ;
}
F_10 ( V_6 ) ;
return F_3 ( V_7 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_4 T_1 * V_6 =
(struct V_4 T_1 * ) V_2 -> V_5 ;
struct V_4 * V_5 ;
int V_8 ;
if ( V_2 -> V_5 ) {
F_4 (cpu) {
V_5 = F_5 ( V_6 , V_8 ) ;
V_2 -> V_10 -> free ( V_5 -> V_5 ) ;
}
F_10 ( V_6 ) ;
}
}
int F_12 ( struct V_1 * V_2 , struct V_14 * * V_15 ,
int V_16 , int V_17 , int V_18 , struct V_19 * V_20 )
{
struct V_4 T_1 * V_6 =
(struct V_4 T_1 * ) V_2 -> V_5 ;
struct V_4 * V_5 = F_13 ( V_6 ) ;
int V_21 = V_2 -> V_10 -> V_22 ( V_2 , V_5 -> V_5 , V_15 , V_16 ,
V_17 , V_18 , V_20 ) ;
F_14 ( V_5 ) ;
if ( V_21 < 0 )
ERROR ( L_1 ,
V_2 -> V_10 -> V_23 ) ;
return V_21 ;
}
int F_15 ( void )
{
return F_16 () ;
}
