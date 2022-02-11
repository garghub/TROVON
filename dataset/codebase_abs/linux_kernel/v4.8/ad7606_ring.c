static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 -> V_7 ) ;
F_3 ( V_6 -> V_8 -> V_9 , 1 ) ;
return V_10 ;
}
static void F_4 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = F_5 ( V_12 , struct V_5 ,
V_13 ) ;
struct V_14 * V_7 = F_6 ( V_6 ) ;
T_2 * V_15 ;
int V_16 ;
V_15 = F_7 ( V_7 -> V_17 , V_18 ) ;
if ( ! V_15 )
return;
if ( F_8 ( V_6 -> V_8 -> V_19 ) ) {
V_16 = V_6 -> V_20 -> V_21 ( V_6 -> V_22 , 1 , V_15 ) ;
if ( V_16 )
goto V_23;
if ( ! F_9 ( V_6 -> V_8 -> V_19 ) ) {
F_10 ( V_6 ) ;
goto V_23;
}
V_16 = V_6 -> V_20 -> V_21 ( V_6 -> V_22 ,
V_6 -> V_24 -> V_25 - 1 , V_15 + 2 ) ;
if ( V_16 )
goto V_23;
} else {
V_16 = V_6 -> V_20 -> V_21 ( V_6 -> V_22 ,
V_6 -> V_24 -> V_25 , V_15 ) ;
if ( V_16 )
goto V_23;
}
F_11 ( V_7 , V_15 ,
F_12 ( V_7 ) ) ;
V_23:
F_3 ( V_6 -> V_8 -> V_9 , 0 ) ;
F_13 ( V_7 -> V_26 ) ;
F_14 ( V_15 ) ;
}
int F_15 ( struct V_14 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
F_16 ( & V_6 -> V_13 , & F_4 ) ;
return F_17 ( V_7 ,
& F_1 , & F_1 ,
NULL ) ;
}
void F_18 ( struct V_14 * V_7 )
{
F_19 ( V_7 ) ;
}
