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
struct V_17 * V_18 = V_6 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
F_7 ( V_20 , L_1 ) ;
F_7 ( V_20 , L_2 ) ;
F_7 ( V_20 , L_3 ) ;
F_7 ( V_20 , L_4 ) ;
F_7 ( V_20 , L_5 ) ;
F_7 ( V_20 , L_6 ) ;
F_7 ( V_20 , L_7 ) ;
F_7 ( V_20 , L_8 ) ;
F_7 ( V_20 , L_9 ) ;
F_7 ( V_20 , L_10 ) ;
F_7 ( V_20 , L_11 ) ;
F_7 ( V_20 , L_12 ) ;
F_7 ( V_20 , L_13 ) ;
F_7 ( V_20 , L_14 ) ;
return 0 ;
}
static int F_8 ( struct V_21 * V_22 )
{
int V_11 ;
struct V_23 * V_24 = V_22 -> V_25 . V_26 ;
struct V_27 * V_28 = & V_29 ;
struct V_30 * V_31 ;
const struct V_32 * V_33 ;
V_28 -> V_25 = & V_22 -> V_25 ;
V_31 = F_9 ( & V_22 -> V_25 , sizeof( * V_31 ) , V_34 ) ;
if ( ! V_31 )
return - V_35 ;
if ( V_24 ) {
V_36 [ 0 ] . V_37 = NULL ;
V_36 [ 0 ] . V_38 = F_10 ( V_24 ,
L_15 , 0 ) ;
if ( ! V_36 [ 0 ] . V_38 ) {
F_11 ( & V_22 -> V_25 ,
L_16 ) ;
V_11 = - V_39 ;
}
V_36 [ 0 ] . V_40 = NULL ;
V_36 [ 0 ] . V_41 = V_36 [ 0 ] . V_38 ;
}
V_33 = F_12 ( F_13 ( V_42 ) , & V_22 -> V_25 ) ;
if ( V_33 )
* V_31 = * ( (struct V_30 * ) V_33 -> V_43 ) ;
F_14 ( V_22 , V_31 ) ;
V_11 = F_15 ( & V_22 -> V_25 , V_28 ) ;
if ( V_11 )
F_11 ( & V_22 -> V_25 , L_17 , V_11 ) ;
return V_11 ;
}
