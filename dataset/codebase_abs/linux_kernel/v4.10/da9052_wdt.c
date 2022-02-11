static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_7 , V_8 ;
V_7 = F_3 ( V_6 , V_9 ,
V_10 , 0 ) ;
if ( V_7 < 0 ) {
F_4 ( V_6 -> V_11 , L_1 ,
V_7 ) ;
return V_7 ;
}
if ( V_3 ) {
F_5 ( 150 ) ;
for ( V_8 = 0 ; V_8 < F_6 ( V_12 ) ; V_8 ++ )
if ( V_12 [ V_8 ] . time == V_3 )
break;
if ( V_8 == F_6 ( V_12 ) )
V_7 = - V_13 ;
else
V_7 = F_3 ( V_6 , V_9 ,
V_10 ,
V_12 [ V_8 ] . V_14 ) ;
if ( V_7 < 0 ) {
F_4 ( V_6 -> V_11 ,
L_2 , V_7 ) ;
return V_7 ;
}
V_2 -> V_3 = V_3 ;
V_5 -> V_15 = V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_2 -> V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
unsigned long V_17 , V_18 = V_16 ;
int V_7 ;
V_17 = ( V_18 - V_5 -> V_15 ) * 1000 / V_19 ;
if ( V_17 < V_20 )
F_10 ( V_17 ) ;
V_7 = F_3 ( V_6 , V_9 ,
V_21 , 1 << 7 ) ;
if ( V_7 < 0 )
goto V_22;
V_7 = F_3 ( V_6 , V_9 ,
V_21 , 0 << 7 ) ;
V_22:
return V_7 ;
}
static int F_11 ( struct V_23 * V_24 )
{
struct V_6 * V_6 = F_12 ( V_24 -> V_11 . V_25 ) ;
struct V_4 * V_5 ;
struct V_1 * V_26 ;
int V_7 ;
V_5 = F_13 ( & V_24 -> V_11 , sizeof( * V_5 ) ,
V_27 ) ;
if ( ! V_5 ) {
V_7 = - V_28 ;
goto V_29;
}
V_5 -> V_6 = V_6 ;
V_26 = & V_5 -> V_30 ;
V_26 -> V_3 = V_31 ;
V_26 -> V_32 = & V_33 ;
V_26 -> V_34 = & V_35 ;
V_26 -> V_25 = & V_24 -> V_11 ;
F_14 ( V_26 , V_5 ) ;
V_7 = F_3 ( V_6 , V_9 ,
V_10 , 0 ) ;
if ( V_7 < 0 ) {
F_4 ( & V_24 -> V_11 , L_3 ,
V_7 ) ;
goto V_29;
}
V_7 = F_15 ( & V_5 -> V_30 ) ;
if ( V_7 != 0 ) {
F_4 ( V_6 -> V_11 , L_4 ,
V_7 ) ;
goto V_29;
}
F_16 ( V_24 , V_5 ) ;
V_29:
return V_7 ;
}
static int F_17 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_18 ( V_24 ) ;
F_19 ( & V_5 -> V_30 ) ;
return 0 ;
}
