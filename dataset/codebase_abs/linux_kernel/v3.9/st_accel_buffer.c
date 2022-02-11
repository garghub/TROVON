int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return F_2 ( V_5 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
int V_7 ;
V_7 = F_4 ( V_5 , true ) ;
if ( V_7 < 0 )
goto V_8;
V_7 = F_5 ( V_5 ) ;
V_8:
return V_7 ;
}
static int F_6 ( struct V_4 * V_5 )
{
int V_7 ;
struct V_9 * V_10 = F_7 ( V_5 ) ;
V_10 -> V_11 = F_8 ( V_5 -> V_12 , V_13 ) ;
if ( V_10 -> V_11 == NULL ) {
V_7 = - V_14 ;
goto V_15;
}
V_7 = F_9 ( V_5 ,
( V_16 ) V_5 -> V_17 [ 0 ] ) ;
if ( V_7 < 0 )
goto V_18;
V_7 = F_10 ( V_5 ) ;
if ( V_7 < 0 )
goto V_18;
return V_7 ;
V_18:
F_11 ( V_10 -> V_11 ) ;
V_15:
return V_7 ;
}
static int F_12 ( struct V_4 * V_5 )
{
int V_7 ;
struct V_9 * V_10 = F_7 ( V_5 ) ;
V_7 = F_13 ( V_5 ) ;
if ( V_7 < 0 )
goto V_19;
V_7 = F_9 ( V_5 , V_20 ) ;
if ( V_7 < 0 )
goto V_19;
V_7 = F_4 ( V_5 , false ) ;
V_19:
F_11 ( V_10 -> V_11 ) ;
return V_7 ;
}
int F_14 ( struct V_4 * V_5 )
{
return F_15 ( V_5 , & V_21 ,
& V_22 , & V_23 ) ;
}
void F_16 ( struct V_4 * V_5 )
{
F_17 ( V_5 ) ;
}
