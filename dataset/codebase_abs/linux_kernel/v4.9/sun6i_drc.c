static int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
void * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_6 = F_2 ( V_2 , sizeof( * V_6 ) , V_8 ) ;
if ( ! V_6 )
return - V_9 ;
F_3 ( V_2 , V_6 ) ;
V_6 -> V_10 = F_4 ( V_2 , NULL ) ;
if ( F_5 ( V_6 -> V_10 ) ) {
F_6 ( V_2 , L_1 ) ;
return F_7 ( V_6 -> V_10 ) ;
}
V_7 = F_8 ( V_6 -> V_10 ) ;
if ( V_7 ) {
F_6 ( V_2 , L_2 ) ;
return V_7 ;
}
V_6 -> V_11 = F_9 ( V_2 , L_3 ) ;
if ( F_5 ( V_6 -> V_11 ) ) {
F_6 ( V_2 , L_4 ) ;
V_7 = F_7 ( V_6 -> V_11 ) ;
goto V_12;
}
F_10 ( V_6 -> V_11 ) ;
V_6 -> V_13 = F_9 ( V_2 , L_5 ) ;
if ( F_5 ( V_6 -> V_13 ) ) {
F_6 ( V_2 , L_6 ) ;
V_7 = F_7 ( V_6 -> V_13 ) ;
goto V_14;
}
F_10 ( V_6 -> V_13 ) ;
return 0 ;
V_14:
F_11 ( V_6 -> V_11 ) ;
V_12:
F_12 ( V_6 -> V_10 ) ;
return V_7 ;
}
static void F_13 ( struct V_1 * V_2 , struct V_1 * V_3 ,
void * V_4 )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
F_11 ( V_6 -> V_13 ) ;
F_11 ( V_6 -> V_11 ) ;
F_12 ( V_6 -> V_10 ) ;
}
static int F_15 ( struct V_15 * V_16 )
{
return F_16 ( & V_16 -> V_2 , & V_17 ) ;
}
static int F_17 ( struct V_15 * V_16 )
{
F_18 ( & V_16 -> V_2 , & V_17 ) ;
return 0 ;
}
