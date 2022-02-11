static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_2 , F_4 () ) ;
return V_3 ;
}
static int F_5 ( struct V_4 * V_5 ,
bool V_6 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
F_6 ( & V_8 -> V_10 , L_1 , V_11 , V_6 ) ;
return F_7 ( & V_8 -> V_10 , V_6 ) ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_12 * V_13 = F_9 ( V_8 ) ;
F_10 ( V_13 -> V_14 -> V_1 ) ;
return 0 ;
}
int F_11 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_8 ) ;
int V_15 ;
V_13 -> V_5 = F_12 ( L_2 ,
F_13 ( V_13 -> V_14 ) -> V_16 ,
V_8 -> V_17 ) ;
if ( V_13 -> V_5 == NULL ) {
V_15 = - V_18 ;
goto V_19;
}
V_15 = F_14 ( V_13 -> V_14 -> V_1 ,
F_1 ,
V_20 ,
F_13 ( V_13 -> V_14 ) -> V_16 ,
V_13 -> V_5 ) ;
if ( V_15 )
goto V_21;
V_13 -> V_5 -> V_10 . V_22 = & V_13 -> V_14 -> V_10 ;
V_13 -> V_5 -> V_23 = V_24 ;
V_13 -> V_5 -> V_9 = V_8 ;
V_13 -> V_5 -> V_25 = & F_5 ;
V_13 -> V_5 -> V_26 = & F_8 ;
V_15 = F_15 ( V_13 -> V_5 ) ;
V_8 -> V_5 = V_13 -> V_5 ;
if ( V_15 )
goto V_27;
return 0 ;
V_27:
F_16 ( V_13 -> V_14 -> V_1 , V_13 -> V_5 ) ;
V_21:
F_17 ( V_13 -> V_5 ) ;
V_19:
return V_15 ;
}
void F_18 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_8 ) ;
F_19 ( V_13 -> V_5 ) ;
F_16 ( V_13 -> V_14 -> V_1 , V_13 -> V_5 ) ;
F_17 ( V_13 -> V_5 ) ;
}
