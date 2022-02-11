static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
V_7 = V_3 ? 1 : 0 ;
if ( F_2 ( V_8 ) )
++ V_7 ;
V_5 -> V_9 = V_3 ;
F_3 ( V_5 -> V_10 , V_5 -> V_11 . V_12 ,
V_5 -> V_11 . V_13 ,
( V_14 ) V_7 ) ;
F_3 ( V_5 -> V_10 , V_5 -> V_15 . V_12 ,
V_5 -> V_15 . V_13 ,
( V_14 ) V_7 ) ;
return 0 ;
}
void F_4 ( struct V_16 * V_17 )
{
F_5 ( V_17 -> V_2 ) ;
F_6 ( V_17 -> V_2 ) ;
V_17 -> V_2 = NULL ;
}
int F_7 ( struct V_16 * V_17 , const char * V_18 ,
struct V_4 * V_19 )
{
int V_20 ;
struct V_1 * V_2 ;
V_2 = F_8 ( L_1 , V_18 , V_17 -> V_21 ) ;
if ( V_2 == NULL ) {
F_9 ( & V_17 -> V_22 , L_2 ) ;
V_20 = - V_23 ;
goto V_24;
}
V_2 -> V_22 . V_25 = V_17 -> V_22 . V_25 ;
V_2 -> V_6 = V_19 ;
V_2 -> V_26 = & V_27 ;
V_20 = F_10 ( V_2 ) ;
if ( V_20 ) {
F_9 ( & V_17 -> V_22 , L_3 ) ;
goto V_28;
}
V_17 -> V_2 = V_2 ;
return V_20 ;
V_28:
F_6 ( V_2 ) ;
V_24:
return V_20 ;
}
