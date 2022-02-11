static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_2 ) ;
return V_3 ;
}
static int F_4 ( struct V_4 * V_5 ,
bool V_6 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
F_6 ( & V_8 -> V_9 , L_1 , V_10 , V_6 ) ;
return F_7 ( & V_8 -> V_9 , V_6 ) ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_5 ( V_5 ) ;
struct V_11 * V_12 = F_9 ( V_8 ) ;
F_10 ( V_12 -> V_13 -> V_1 ) ;
return 0 ;
}
int F_11 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_9 ( V_8 ) ;
int V_14 ;
V_12 -> V_5 = F_12 ( L_2 ,
F_13 ( V_12 -> V_13 ) -> V_15 ,
V_8 -> V_16 ) ;
if ( ! V_12 -> V_5 ) {
V_14 = - V_17 ;
goto V_18;
}
V_14 = F_14 ( V_12 -> V_13 -> V_1 ,
F_1 ,
V_19 ,
F_13 ( V_12 -> V_13 ) -> V_15 ,
V_12 -> V_5 ) ;
if ( V_14 )
goto V_20;
V_12 -> V_5 -> V_9 . V_21 = & V_12 -> V_13 -> V_9 ;
V_12 -> V_5 -> V_22 = & V_23 ;
F_15 ( V_12 -> V_5 , V_8 ) ;
V_14 = F_16 ( V_12 -> V_5 ) ;
V_8 -> V_5 = F_17 ( V_12 -> V_5 ) ;
if ( V_14 )
goto V_24;
return 0 ;
V_24:
F_18 ( V_12 -> V_13 -> V_1 , V_12 -> V_5 ) ;
V_20:
F_19 ( V_12 -> V_5 ) ;
V_18:
return V_14 ;
}
void F_20 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_9 ( V_8 ) ;
F_21 ( V_12 -> V_5 ) ;
F_18 ( V_12 -> V_13 -> V_1 , V_12 -> V_5 ) ;
F_19 ( V_12 -> V_5 ) ;
}
