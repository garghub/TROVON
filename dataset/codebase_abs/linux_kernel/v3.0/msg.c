int F_1 ( struct V_1 * * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_1 * V_10 ;
int V_11 = 0 ;
F_2 ( V_12 > 0 ) ;
F_2 ( V_2 != NULL ) ;
F_2 ( V_5 != NULL ) ;
F_2 ( V_4 != NULL ) ;
* V_2 = NULL ;
F_3 ( V_4 , & V_7 ) ;
V_11 =
(* V_7 -> F_1 ) ( & V_10 , V_4 , V_5 ) ;
if ( ! V_11 ) {
V_9 = (struct V_8 * ) V_10 ;
V_9 -> V_7 = V_7 ;
* V_2 = V_10 ;
} else {
V_11 = - V_13 ;
}
return V_11 ;
}
void F_4 ( struct V_1 * V_10 )
{
struct V_8 * V_9 = (struct V_8 * ) V_10 ;
struct V_6 * V_7 ;
F_2 ( V_12 > 0 ) ;
if ( V_9 ) {
V_7 = V_9 -> V_7 ;
(* V_7 -> F_4 ) ( V_10 ) ;
} else {
F_5 ( V_14 , L_1 ,
V_15 , V_10 ) ;
}
}
void F_6 ( void )
{
F_2 ( V_12 > 0 ) ;
V_12 -- ;
F_7 ( V_12 >= 0 ) ;
}
bool F_8 ( void )
{
F_2 ( V_12 >= 0 ) ;
V_12 ++ ;
F_7 ( V_12 >= 0 ) ;
return true ;
}
