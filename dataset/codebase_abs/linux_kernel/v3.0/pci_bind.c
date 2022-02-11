static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_4 )
goto V_6;
F_3 ( & V_4 -> V_4 , false ) ;
F_4 ( V_2 ) ;
if ( ! V_4 -> V_7 )
goto V_6;
F_5 ( V_4 -> V_7 ) ;
V_2 -> V_8 . V_9 = NULL ;
V_2 -> V_8 . V_10 = NULL ;
V_6:
F_6 ( V_4 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_11 ;
T_2 V_5 ;
struct V_12 * V_13 ;
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_4 )
return 0 ;
F_8 ( V_2 , V_4 ) ;
if ( V_2 -> V_14 . V_15 . V_16 )
F_3 ( & V_4 -> V_4 , true ) ;
if ( V_4 -> V_7 ) {
F_9 ( ( V_17 ,
L_1 ,
F_10 ( V_4 -> V_13 ) , V_4 -> V_13 -> V_18 ,
F_11 ( V_4 -> V_19 ) , F_12 ( V_4 -> V_19 ) ) ) ;
V_2 -> V_8 . V_9 = F_7 ;
V_2 -> V_8 . V_10 = F_1 ;
}
V_11 = F_13 ( V_2 -> V_5 , V_20 , & V_5 ) ;
if ( F_14 ( V_11 ) )
goto V_6;
if ( V_4 -> V_7 )
V_13 = V_4 -> V_7 ;
else
V_13 = V_4 -> V_13 ;
F_15 ( V_2 -> V_5 , V_13 ) ;
V_6:
F_6 ( V_4 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_9 = F_7 ;
V_2 -> V_8 . V_10 = F_1 ;
return 0 ;
}
