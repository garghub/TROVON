static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_2 , F_3 () ) ;
return V_3 ;
}
static int F_4 ( struct V_4 * V_2 ,
bool V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_5 ( & V_7 -> V_9 , L_1 , V_10 , V_5 ) ;
return F_6 ( V_7 , V_5 ) ;
}
int F_7 ( struct V_6 * V_7 )
{
int V_11 ;
struct V_12 * V_13 = F_8 ( V_7 ) ;
V_13 -> V_2 = F_9 ( L_2 , V_7 -> V_14 ) ;
if ( V_13 -> V_2 == NULL ) {
V_11 = - V_15 ;
goto V_16;
}
V_11 = F_10 ( V_13 -> V_17 -> V_1 ,
F_1 ,
V_18 ,
L_3 ,
V_13 -> V_2 ) ;
if ( V_11 )
goto V_19;
V_13 -> V_2 -> V_9 . V_20 = & V_13 -> V_17 -> V_9 ;
V_13 -> V_2 -> V_21 = V_22 ;
V_13 -> V_2 -> V_8 = V_7 ;
V_13 -> V_2 -> V_23 = & F_4 ;
V_11 = F_11 ( V_13 -> V_2 ) ;
V_7 -> V_2 = V_13 -> V_2 ;
if ( V_11 )
goto V_24;
return 0 ;
V_24:
F_12 ( V_13 -> V_17 -> V_1 , V_13 -> V_2 ) ;
V_19:
F_13 ( V_13 -> V_2 ) ;
V_16:
return V_11 ;
}
void F_14 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_8 ( V_7 ) ;
F_15 ( V_13 -> V_2 ) ;
F_12 ( V_13 -> V_17 -> V_1 , V_13 -> V_2 ) ;
F_13 ( V_13 -> V_2 ) ;
}
