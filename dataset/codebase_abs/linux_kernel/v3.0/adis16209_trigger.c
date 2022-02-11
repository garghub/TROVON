static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_2 , F_3 () ) ;
return V_3 ;
}
static int F_4 ( struct V_4 * V_2 ,
bool V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
F_5 ( & V_10 -> V_11 , L_1 , V_12 , V_5 ) ;
return F_6 ( V_7 -> V_10 , V_5 ) ;
}
int F_7 ( struct V_9 * V_10 )
{
int V_13 ;
struct V_6 * V_7 = V_10 -> V_14 ;
V_7 -> V_2 = F_8 ( L_2 , V_10 -> V_15 ) ;
if ( V_7 -> V_2 == NULL ) {
V_13 = - V_16 ;
goto V_17;
}
V_13 = F_9 ( V_7 -> V_18 -> V_1 ,
F_1 ,
V_19 ,
L_3 ,
V_7 -> V_2 ) ;
if ( V_13 )
goto V_20;
V_7 -> V_2 -> V_11 . V_21 = & V_7 -> V_18 -> V_11 ;
V_7 -> V_2 -> V_22 = V_23 ;
V_7 -> V_2 -> V_8 = V_7 ;
V_7 -> V_2 -> V_24 = & F_4 ;
V_13 = F_10 ( V_7 -> V_2 ) ;
V_10 -> V_2 = V_7 -> V_2 ;
if ( V_13 )
goto V_25;
return 0 ;
V_25:
F_11 ( V_7 -> V_18 -> V_1 , V_7 -> V_2 ) ;
V_20:
F_12 ( V_7 -> V_2 ) ;
V_17:
return V_13 ;
}
void F_13 ( struct V_9 * V_10 )
{
struct V_6 * V_5 = V_10 -> V_14 ;
F_14 ( V_5 -> V_2 ) ;
F_11 ( V_5 -> V_18 -> V_1 , V_5 -> V_2 ) ;
F_12 ( V_5 -> V_2 ) ;
}
