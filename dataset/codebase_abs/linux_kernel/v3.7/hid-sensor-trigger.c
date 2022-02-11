static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
V_7 = V_3 ? 1 : 0 ;
#if ( V_8 V_9 ) || \
( V_8 V_10 )
++ V_7 ;
#endif
V_5 -> V_11 = V_3 ;
F_2 ( V_5 -> V_12 , V_5 -> V_13 . V_14 ,
V_5 -> V_13 . V_15 ,
( V_16 ) V_7 ) ;
F_2 ( V_5 -> V_12 , V_5 -> V_17 . V_14 ,
V_5 -> V_17 . V_15 ,
( V_16 ) V_7 ) ;
return 0 ;
}
void F_3 ( struct V_18 * V_19 )
{
F_4 ( V_19 -> V_2 ) ;
F_5 ( V_19 -> V_2 ) ;
V_19 -> V_2 = NULL ;
}
int F_6 ( struct V_18 * V_19 , const char * V_20 ,
struct V_4 * V_21 )
{
int V_22 ;
struct V_1 * V_2 ;
V_2 = F_7 ( L_1 , V_20 , V_19 -> V_23 ) ;
if ( V_2 == NULL ) {
F_8 ( & V_19 -> V_24 , L_2 ) ;
V_22 = - V_25 ;
goto V_26;
}
V_2 -> V_24 . V_27 = V_19 -> V_24 . V_27 ;
V_2 -> V_6 = V_21 ;
V_2 -> V_28 = & V_29 ;
V_22 = F_9 ( V_2 ) ;
if ( V_22 ) {
F_8 ( & V_19 -> V_24 , L_3 ) ;
goto V_30;
}
V_19 -> V_2 = V_2 ;
return V_22 ;
V_30:
F_5 ( V_2 ) ;
V_26:
return V_22 ;
}
