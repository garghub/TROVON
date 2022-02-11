int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 , V_3 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
return F_5 ( V_5 , true ) ;
}
static int F_6 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_7 * V_8 = F_7 ( V_5 ) ;
V_8 -> V_9 = F_8 ( V_5 -> V_10 , V_11 ) ;
if ( V_8 -> V_9 == NULL ) {
V_6 = - V_12 ;
goto V_13;
}
V_6 = F_9 ( V_5 ) ;
if ( V_6 < 0 )
goto V_14;
return V_6 ;
V_14:
F_10 ( V_8 -> V_9 ) ;
V_13:
return V_6 ;
}
static int F_11 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_7 * V_8 = F_7 ( V_5 ) ;
V_6 = F_12 ( V_5 ) ;
if ( V_6 < 0 )
goto V_15;
V_6 = F_5 ( V_5 , false ) ;
V_15:
F_10 ( V_8 -> V_9 ) ;
return V_6 ;
}
int F_13 ( struct V_4 * V_5 )
{
return F_14 ( V_5 , NULL ,
& V_16 , & V_17 ) ;
}
void F_15 ( struct V_4 * V_5 )
{
F_16 ( V_5 ) ;
}
