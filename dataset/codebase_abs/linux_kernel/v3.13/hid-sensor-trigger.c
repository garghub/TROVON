static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
int V_7 ;
if ( V_3 ) {
if ( F_3 ( V_5 -> V_8 ) )
return - V_9 ;
V_6 =
V_10 ;
V_7 =
V_11 ;
} else {
F_4 ( V_5 -> V_8 ) ;
V_6 =
V_12 ;
V_7 =
V_13 ;
}
V_5 -> V_14 = V_3 ;
V_6 += V_5 -> V_15 . V_16 ;
V_7 += V_5 -> V_17 . V_16 ;
F_5 ( V_5 -> V_8 , V_5 -> V_15 . V_18 ,
V_5 -> V_15 . V_19 ,
( V_20 ) V_6 ) ;
F_5 ( V_5 -> V_8 , V_5 -> V_17 . V_18 ,
V_5 -> V_17 . V_19 ,
( V_20 ) V_7 ) ;
return 0 ;
}
void F_6 ( struct V_4 * V_21 )
{
F_7 ( V_21 -> V_22 ) ;
F_8 ( V_21 -> V_22 ) ;
}
int F_9 ( struct V_23 * V_24 , const char * V_25 ,
struct V_4 * V_21 )
{
int V_26 ;
struct V_1 * V_2 ;
V_2 = F_10 ( L_1 , V_25 , V_24 -> V_27 ) ;
if ( V_2 == NULL ) {
F_11 ( & V_24 -> V_28 , L_2 ) ;
V_26 = - V_29 ;
goto V_30;
}
V_2 -> V_28 . V_31 = V_24 -> V_28 . V_31 ;
F_12 ( V_2 , V_21 ) ;
V_2 -> V_32 = & V_33 ;
V_26 = F_13 ( V_2 ) ;
if ( V_26 ) {
F_11 ( & V_24 -> V_28 , L_3 ) ;
goto V_34;
}
V_24 -> V_2 = V_21 -> V_22 = V_2 ;
return V_26 ;
V_34:
F_8 ( V_2 ) ;
V_30:
return V_26 ;
}
