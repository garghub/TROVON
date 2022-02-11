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
V_6 = F_10 ( V_5 ,
( V_15 ) V_5 -> V_16 [ 0 ] ) ;
if ( V_6 < 0 )
goto V_17;
V_6 = F_11 ( V_5 ) ;
if ( V_6 < 0 )
goto V_17;
return V_6 ;
V_17:
F_12 ( V_9 -> V_10 ) ;
V_14:
return V_6 ;
}
static int F_13 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_8 * V_9 = F_8 ( V_5 ) ;
V_6 = F_14 ( V_5 ) ;
if ( V_6 < 0 )
goto V_18;
V_6 = F_10 ( V_5 , V_19 ) ;
if ( V_6 < 0 )
goto V_18;
V_6 = F_5 ( V_5 , false ) ;
V_18:
F_12 ( V_9 -> V_10 ) ;
return V_6 ;
}
int F_15 ( struct V_4 * V_5 )
{
return F_16 ( V_5 , & V_20 ,
& V_21 , & V_22 ) ;
}
void F_17 ( struct V_4 * V_5 )
{
F_18 ( V_5 ) ;
}
