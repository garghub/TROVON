static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = 0 ;
int V_8 = V_9 ;
F_2 ( 1000 * V_10 ) ;
while ( V_8 -- ) {
V_7 = F_3 ( V_6 -> V_11 ,
F_4 ( V_6 -> V_11 , 0 ) , 0x22 , 0x21 ,
0x1 , 0 , NULL , 0 , 100 ) ;
if ( ! V_7 )
break;
F_2 ( 1000 ) ;
}
if ( ! V_8 && V_7 ) {
F_5 ( & V_4 -> V_11 , L_1 ,
V_12 , V_7 ) ;
return V_7 ;
}
return F_6 ( V_2 , V_4 ) ;
}
static int F_7 ( struct V_5 * V_6 )
{
int V_13 = 1 ;
F_8 ( & V_6 -> V_11 -> V_11 , L_2 , V_12 ,
( int ) V_6 -> V_14 -> V_15 -> V_16 . V_17 ) ;
if ( V_6 -> V_14 -> V_15 -> V_16 . V_17 > 3 ) {
V_13 = 2 ;
}
return V_13 ;
}
static int F_9 ( struct V_5 * V_6 )
{
if ( V_6 -> V_18 < V_6 -> V_19 ||
V_6 -> V_20 < V_6 -> V_19 )
return - V_21 ;
if ( V_6 -> V_11 -> V_22 -> V_16 . V_23 != 1 ) {
F_5 ( & V_6 -> V_11 -> V_11 , L_3 ,
V_6 -> V_11 -> V_22 -> V_16 . V_23 ) ;
return - V_21 ;
}
F_8 ( & V_6 -> V_11 -> V_11 ,
L_4 , V_12 ,
V_6 -> V_19 ) ;
return F_10 ( V_6 -> V_11 ) ;
}
