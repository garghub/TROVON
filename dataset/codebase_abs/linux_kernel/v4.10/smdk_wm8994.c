static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_10 ;
int V_11 ;
if ( F_2 ( V_4 ) == 24 )
V_10 = F_3 ( V_4 ) * 384 ;
else if ( F_3 ( V_4 ) == 8000 || F_3 ( V_4 ) == 11025 )
V_10 = F_3 ( V_4 ) * 512 ;
else
V_10 = F_3 ( V_4 ) * 256 ;
V_11 = F_4 ( V_9 , V_12 , V_13 ,
V_14 , V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_9 , V_15 ,
V_10 , V_16 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_17 * V_18 = & V_6 -> V_19 -> V_18 ;
F_7 ( V_18 , L_1 ) ;
F_7 ( V_18 , L_2 ) ;
F_7 ( V_18 , L_3 ) ;
F_7 ( V_18 , L_4 ) ;
F_7 ( V_18 , L_5 ) ;
F_7 ( V_18 , L_6 ) ;
F_7 ( V_18 , L_7 ) ;
F_7 ( V_18 , L_8 ) ;
F_7 ( V_18 , L_9 ) ;
F_7 ( V_18 , L_10 ) ;
F_7 ( V_18 , L_11 ) ;
F_7 ( V_18 , L_12 ) ;
F_7 ( V_18 , L_13 ) ;
F_7 ( V_18 , L_14 ) ;
return 0 ;
}
static int F_8 ( struct V_20 * V_21 )
{
int V_11 ;
struct V_22 * V_23 = V_21 -> V_24 . V_25 ;
struct V_26 * V_19 = & V_27 ;
struct V_28 * V_29 ;
const struct V_30 * V_31 ;
V_19 -> V_24 = & V_21 -> V_24 ;
V_29 = F_9 ( & V_21 -> V_24 , sizeof( * V_29 ) , V_32 ) ;
if ( ! V_29 )
return - V_33 ;
if ( V_23 ) {
V_34 [ 0 ] . V_35 = NULL ;
V_34 [ 0 ] . V_36 = F_10 ( V_23 ,
L_15 , 0 ) ;
if ( ! V_34 [ 0 ] . V_36 ) {
F_11 ( & V_21 -> V_24 ,
L_16 ) ;
V_11 = - V_37 ;
}
V_34 [ 0 ] . V_38 = NULL ;
V_34 [ 0 ] . V_39 = V_34 [ 0 ] . V_36 ;
}
V_31 = F_12 ( F_13 ( V_40 ) , & V_21 -> V_24 ) ;
if ( V_31 )
* V_29 = * ( (struct V_28 * ) V_31 -> V_41 ) ;
F_14 ( V_21 , V_29 ) ;
V_11 = F_15 ( & V_21 -> V_24 , V_19 ) ;
if ( V_11 )
F_11 ( & V_21 -> V_24 , L_17 , V_11 ) ;
return V_11 ;
}
