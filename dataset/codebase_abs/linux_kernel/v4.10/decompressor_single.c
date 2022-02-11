void * F_1 ( struct V_1 * V_2 ,
void * V_3 )
{
struct V_4 * V_5 ;
int V_6 = - V_7 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_8 ) ;
if ( V_5 == NULL )
goto V_9;
V_5 -> V_5 = V_2 -> V_10 -> V_11 ( V_2 , V_3 ) ;
if ( F_3 ( V_5 -> V_5 ) ) {
V_6 = F_4 ( V_5 -> V_5 ) ;
goto V_9;
}
F_5 ( V_3 ) ;
F_6 ( & V_5 -> V_12 ) ;
return V_5 ;
V_9:
F_5 ( V_5 ) ;
return F_7 ( V_6 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 ) {
V_2 -> V_10 -> free ( V_5 -> V_5 ) ;
F_5 ( V_5 ) ;
}
}
int F_9 ( struct V_1 * V_2 , struct V_13 * * V_14 ,
int V_15 , int V_16 , int V_17 , struct V_18 * V_19 )
{
int V_20 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_10 ( & V_5 -> V_12 ) ;
V_20 = V_2 -> V_10 -> V_21 ( V_2 , V_5 -> V_5 , V_14 , V_15 ,
V_16 , V_17 , V_19 ) ;
F_11 ( & V_5 -> V_12 ) ;
if ( V_20 < 0 )
ERROR ( L_1 ,
V_2 -> V_10 -> V_22 ) ;
return V_20 ;
}
int F_12 ( void )
{
return 1 ;
}
