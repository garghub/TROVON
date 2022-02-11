static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = 0 ;
int V_8 = V_9 ;
F_2 ( 1000 * V_10 ) ;
while ( V_8 ) {
V_8 -- ;
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
static int F_7 ( struct V_5 * V_6 ,
struct V_13 * V_14 )
{
if ( V_14 -> V_15 == 0 || V_14 -> V_16 == 0 )
return - V_17 ;
if ( V_14 -> V_15 > 1 && V_14 -> V_16 > 1 ) {
V_14 -> V_18 [ 0 ] = V_14 -> V_18 [ 1 ] ;
V_14 -> V_19 [ 0 ] = V_14 -> V_19 [ 1 ] ;
}
V_14 -> V_15 = 1 ;
V_14 -> V_16 = 1 ;
return 1 ;
}
static int F_8 ( struct V_5 * V_6 )
{
if ( V_6 -> V_11 -> V_20 -> V_21 . V_22 != 1 ) {
F_5 ( & V_6 -> V_11 -> V_11 , L_2 ,
V_6 -> V_11 -> V_20 -> V_21 . V_22 ) ;
return - V_17 ;
}
return F_9 ( V_6 -> V_11 ) ;
}
