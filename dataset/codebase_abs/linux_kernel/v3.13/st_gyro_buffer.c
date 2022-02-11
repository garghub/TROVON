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
V_6 = F_9 ( V_5 ,
( V_14 ) V_5 -> V_15 [ 0 ] ) ;
if ( V_6 < 0 )
goto V_16;
V_6 = F_10 ( V_5 ) ;
if ( V_6 < 0 )
goto V_16;
return V_6 ;
V_16:
F_11 ( V_8 -> V_9 ) ;
V_13:
return V_6 ;
}
static int F_12 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_7 * V_8 = F_7 ( V_5 ) ;
V_6 = F_13 ( V_5 ) ;
if ( V_6 < 0 )
goto V_17;
V_6 = F_9 ( V_5 , V_18 ) ;
if ( V_6 < 0 )
goto V_17;
V_6 = F_5 ( V_5 , false ) ;
V_17:
F_11 ( V_8 -> V_9 ) ;
return V_6 ;
}
int F_14 ( struct V_4 * V_5 )
{
return F_15 ( V_5 , & V_19 ,
& V_20 , & V_21 ) ;
}
void F_16 ( struct V_4 * V_5 )
{
F_17 ( V_5 ) ;
}
