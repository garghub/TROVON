int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 , V_3 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
int V_6 ;
V_6 = F_5 ( V_5 , true ) ;
if ( V_6 < 0 )
goto V_7;
V_6 = F_6 ( V_5 ) ;
V_7:
return V_6 ;
}
static int F_7 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_8 * V_9 = F_8 ( V_5 ) ;
V_9 -> V_10 = F_9 ( V_5 -> V_11 , V_12 ) ;
if ( V_9 -> V_10 == NULL ) {
V_6 = - V_13 ;
goto V_14;
}
V_6 = F_10 ( V_5 ) ;
if ( V_6 < 0 )
goto V_15;
return V_6 ;
V_15:
F_11 ( V_9 -> V_10 ) ;
V_14:
return V_6 ;
}
static int F_12 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_8 * V_9 = F_8 ( V_5 ) ;
V_6 = F_13 ( V_5 ) ;
if ( V_6 < 0 )
goto V_16;
V_6 = F_5 ( V_5 , false ) ;
V_16:
F_11 ( V_9 -> V_10 ) ;
return V_6 ;
}
int F_14 ( struct V_4 * V_5 )
{
return F_15 ( V_5 , & V_17 ,
& V_18 , & V_19 ) ;
}
void F_16 ( struct V_4 * V_5 )
{
F_17 ( V_5 ) ;
}
