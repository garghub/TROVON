static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , true ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_4 ( V_2 ) ;
V_5 -> V_6 = F_5 ( V_2 -> V_7 , V_8 ) ;
if ( V_5 -> V_6 == NULL ) {
V_3 = - V_9 ;
goto V_10;
}
V_3 = F_6 ( V_2 ) ;
if ( V_3 < 0 )
goto V_11;
return V_3 ;
V_11:
F_7 ( V_5 -> V_6 ) ;
V_10:
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_4 ( V_2 ) ;
V_3 = F_9 ( V_2 ) ;
if ( V_3 < 0 )
goto V_12;
V_3 = F_2 ( V_2 , false ) ;
V_12:
F_7 ( V_5 -> V_6 ) ;
return V_3 ;
}
int F_10 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , & V_13 ,
& V_14 , & V_15 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
}
