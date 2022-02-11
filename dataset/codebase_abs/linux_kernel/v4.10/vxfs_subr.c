inline void
F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
}
struct V_1 *
F_4 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_4 , V_5 , NULL ) ;
if ( ! F_6 ( V_2 ) ) {
F_7 ( V_2 ) ;
if ( F_8 ( V_2 ) )
goto V_6;
}
return ( V_2 ) ;
V_6:
F_1 ( V_2 ) ;
return F_9 ( - V_7 ) ;
}
struct V_8 *
F_10 ( struct V_9 * V_10 , int V_11 )
{
struct V_8 * V_12 ;
T_2 V_13 ;
V_13 = F_11 ( V_10 , V_11 ) ;
V_12 = F_12 ( V_10 -> V_14 , V_13 ) ;
return ( V_12 ) ;
}
static int
F_13 ( struct V_9 * V_10 , T_3 V_15 ,
struct V_8 * V_12 , int V_16 )
{
T_2 V_13 ;
V_13 = F_11 ( V_10 , V_15 ) ;
if ( V_13 != 0 ) {
F_14 ( V_12 , V_10 -> V_14 , V_13 ) ;
return 0 ;
}
return - V_7 ;
}
static int
F_15 ( struct V_17 * V_17 , struct V_1 * V_1 )
{
return F_16 ( V_1 , F_13 ) ;
}
static T_3
F_17 ( struct V_3 * V_4 , T_3 V_11 )
{
return F_18 ( V_4 , V_11 , F_13 ) ;
}
