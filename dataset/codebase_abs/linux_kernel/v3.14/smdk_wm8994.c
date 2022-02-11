static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_10 ;
int V_11 ;
if ( F_2 ( V_4 ) == V_12 )
V_10 = F_3 ( V_4 ) * 384 ;
else if ( F_3 ( V_4 ) == 8000 || F_3 ( V_4 ) == 11025 )
V_10 = F_3 ( V_4 ) * 512 ;
else
V_10 = F_3 ( V_4 ) * 256 ;
V_11 = F_4 ( V_9 , V_13 , V_14 ,
V_15 , V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_9 , V_16 ,
V_10 , V_17 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_19 ;
struct V_20 * V_21 = & V_19 -> V_21 ;
F_7 ( V_21 , L_1 ) ;
F_7 ( V_21 , L_2 ) ;
F_7 ( V_21 , L_3 ) ;
F_7 ( V_21 , L_4 ) ;
F_7 ( V_21 , L_5 ) ;
F_7 ( V_21 , L_6 ) ;
F_8 ( V_21 , L_7 ) ;
F_8 ( V_21 , L_8 ) ;
F_8 ( V_21 , L_9 ) ;
F_8 ( V_21 , L_10 ) ;
F_8 ( V_21 , L_11 ) ;
F_8 ( V_21 , L_12 ) ;
F_8 ( V_21 , L_13 ) ;
F_8 ( V_21 , L_14 ) ;
F_8 ( V_21 , L_15 ) ;
F_8 ( V_21 , L_16 ) ;
F_8 ( V_21 , L_17 ) ;
F_8 ( V_21 , L_18 ) ;
F_8 ( V_21 , L_19 ) ;
F_8 ( V_21 , L_20 ) ;
return 0 ;
}
static int F_9 ( struct V_22 * V_23 )
{
int V_11 ;
struct V_24 * V_25 = V_23 -> V_26 . V_27 ;
struct V_28 * V_29 = & V_30 ;
struct V_31 * V_32 ;
const struct V_33 * V_34 ;
V_29 -> V_26 = & V_23 -> V_26 ;
V_32 = F_10 ( & V_23 -> V_26 , sizeof( * V_32 ) , V_35 ) ;
if ( ! V_32 )
return - V_36 ;
if ( V_25 ) {
V_37 [ 0 ] . V_38 = NULL ;
V_37 [ 0 ] . V_39 = F_11 ( V_25 ,
L_21 , 0 ) ;
if ( ! V_37 [ 0 ] . V_39 ) {
F_12 ( & V_23 -> V_26 ,
L_22 ) ;
V_11 = - V_40 ;
}
V_37 [ 0 ] . V_41 = NULL ;
V_37 [ 0 ] . V_42 = V_37 [ 0 ] . V_39 ;
}
V_34 = F_13 ( F_14 ( V_43 ) , & V_23 -> V_26 ) ;
if ( V_34 )
* V_32 = * ( (struct V_31 * ) V_34 -> V_44 ) ;
F_15 ( V_23 , V_32 ) ;
V_11 = F_16 ( & V_23 -> V_26 , V_29 ) ;
if ( V_11 )
F_12 ( & V_23 -> V_26 , L_23 , V_11 ) ;
return V_11 ;
}
