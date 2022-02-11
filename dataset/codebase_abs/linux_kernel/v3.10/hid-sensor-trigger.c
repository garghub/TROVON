static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = V_3 ? 1 : 0 ;
if ( F_3 ( V_7 ) )
++ V_6 ;
V_5 -> V_8 = V_3 ;
F_4 ( V_5 -> V_9 , V_5 -> V_10 . V_11 ,
V_5 -> V_10 . V_12 ,
( V_13 ) V_6 ) ;
F_4 ( V_5 -> V_9 , V_5 -> V_14 . V_11 ,
V_5 -> V_14 . V_12 ,
( V_13 ) V_6 ) ;
return 0 ;
}
void F_5 ( struct V_15 * V_16 )
{
F_6 ( V_16 -> V_2 ) ;
F_7 ( V_16 -> V_2 ) ;
V_16 -> V_2 = NULL ;
}
int F_8 ( struct V_15 * V_16 , const char * V_17 ,
struct V_4 * V_18 )
{
int V_19 ;
struct V_1 * V_2 ;
V_2 = F_9 ( L_1 , V_17 , V_16 -> V_20 ) ;
if ( V_2 == NULL ) {
F_10 ( & V_16 -> V_21 , L_2 ) ;
V_19 = - V_22 ;
goto V_23;
}
V_2 -> V_21 . V_24 = V_16 -> V_21 . V_24 ;
F_11 ( V_2 , V_18 ) ;
V_2 -> V_25 = & V_26 ;
V_19 = F_12 ( V_2 ) ;
if ( V_19 ) {
F_10 ( & V_16 -> V_21 , L_3 ) ;
goto V_27;
}
V_16 -> V_2 = V_2 ;
return V_19 ;
V_27:
F_7 ( V_2 ) ;
V_23:
return V_19 ;
}
