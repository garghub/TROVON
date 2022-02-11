static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , true ) ;
if ( V_3 < 0 )
goto V_4;
V_3 = F_3 ( V_2 ) ;
V_4:
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_6 -> V_7 = F_6 ( V_2 -> V_8 , V_9 ) ;
if ( V_6 -> V_7 == NULL ) {
V_3 = - V_10 ;
goto V_11;
}
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
goto V_12;
return V_3 ;
V_12:
F_8 ( V_6 -> V_7 ) ;
V_11:
return V_3 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_3 = F_10 ( V_2 ) ;
if ( V_3 < 0 )
goto V_13;
V_3 = F_2 ( V_2 , false ) ;
V_13:
F_8 ( V_6 -> V_7 ) ;
return V_3 ;
}
int F_11 ( struct V_1 * V_2 )
{
return F_12 ( V_2 , & V_14 ,
& V_15 , & V_16 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
}
