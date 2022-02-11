static void F_1 ( struct V_1 * V_2 , void T_1 * V_3 , T_2 V_4 , int V_5 )
{
T_2 V_6 ;
V_6 = V_2 -> V_7 ( V_3 ) ;
if ( V_5 )
V_6 |= F_2 ( V_4 ) ;
else
V_6 &= ~ F_2 ( V_4 ) ;
V_2 -> V_8 ( V_3 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_4 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_11 [ V_4 ] )
return V_10 -> V_11 [ V_4 ] ;
return - V_12 ;
}
static int F_5 ( struct V_13 * V_14 )
{
struct V_9 * V_10 ;
T_2 V_15 , V_16 ;
T_2 V_17 [] = { 0x08 , 0x09 , 0x0A , 0x0B , 0x0C , 0x0D } ;
struct V_18 * V_19 ;
void T_1 * V_20 ;
V_10 = F_6 ( & V_14 -> V_21 , sizeof( * V_10 ) , V_22 ) ;
if ( ! V_10 )
return - V_23 ;
V_19 = F_7 ( V_14 , V_24 , 0 ) ;
V_20 = F_8 ( & V_14 -> V_21 , V_19 ) ;
if ( F_9 ( V_20 ) )
return F_10 ( V_20 ) ;
V_15 = F_11 ( & V_10 -> V_2 , & V_14 -> V_21 , 4 ,
V_20 + V_25 ,
V_20 + V_26 , NULL ,
V_20 + V_27 , NULL , 0 ) ;
if ( V_15 )
return V_15 ;
V_10 -> V_2 . V_28 = F_3 ;
V_10 -> V_2 . V_29 = V_30 ;
V_10 -> V_31 = V_32 ;
V_10 -> V_11 = F_6 ( & V_14 -> V_21 , sizeof( T_2 ) * V_30 ,
V_22 ) ;
if ( ! V_10 -> V_11 )
return - V_23 ;
for ( V_16 = 0 ; V_16 < V_10 -> V_31 ; V_16 ++ ) {
V_10 -> V_11 [ V_17 [ V_16 ] ] = F_12 ( V_14 , V_16 ) ;
F_1 ( & V_10 -> V_2 , V_20 + V_33 ,
V_17 [ V_16 ] * 2 , 1 ) ;
F_1 ( & V_10 -> V_2 , V_20 + V_34 , V_16 , 1 ) ;
}
F_13 ( V_14 , V_10 ) ;
V_15 = F_14 ( & V_10 -> V_2 , V_10 ) ;
if ( V_15 )
F_15 ( & V_14 -> V_21 , L_1 ) ;
else
F_16 ( & V_14 -> V_21 , L_2 ) ;
if ( V_10 -> V_31 > 0 ) {
F_17 ( & V_10 -> V_2 ) ;
}
return V_15 ;
}
static int F_18 ( struct V_13 * V_14 )
{
struct V_9 * V_10 = F_19 ( V_14 ) ;
if ( V_10 -> V_31 > 0 ) {
F_20 ( & V_10 -> V_2 ) ;
}
F_21 ( & V_10 -> V_2 ) ;
return 0 ;
}
