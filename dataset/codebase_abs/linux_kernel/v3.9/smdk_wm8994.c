static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 ;
int V_12 ;
if ( F_2 ( V_4 ) == V_13 )
V_11 = F_3 ( V_4 ) * 384 ;
else if ( F_3 ( V_4 ) == 8000 || F_3 ( V_4 ) == 11025 )
V_11 = F_3 ( V_4 ) * 512 ;
else
V_11 = F_3 ( V_4 ) * 256 ;
V_12 = F_4 ( V_10 , V_14
| V_15
| V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_4 ( V_9 , V_14
| V_15
| V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_10 , V_17 , V_18 ,
V_19 , V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_10 , V_20 ,
V_11 , V_21 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_22 * V_23 = V_6 -> V_23 ;
struct V_24 * V_25 = & V_23 -> V_25 ;
F_8 ( V_25 , L_1 ) ;
F_8 ( V_25 , L_2 ) ;
F_8 ( V_25 , L_3 ) ;
F_8 ( V_25 , L_4 ) ;
F_8 ( V_25 , L_5 ) ;
F_8 ( V_25 , L_6 ) ;
F_9 ( V_25 , L_7 ) ;
F_9 ( V_25 , L_8 ) ;
F_9 ( V_25 , L_9 ) ;
F_9 ( V_25 , L_10 ) ;
F_9 ( V_25 , L_11 ) ;
F_9 ( V_25 , L_12 ) ;
F_9 ( V_25 , L_13 ) ;
F_9 ( V_25 , L_14 ) ;
F_9 ( V_25 , L_15 ) ;
F_9 ( V_25 , L_16 ) ;
F_9 ( V_25 , L_17 ) ;
F_9 ( V_25 , L_18 ) ;
F_9 ( V_25 , L_19 ) ;
F_9 ( V_25 , L_20 ) ;
return 0 ;
}
static int F_10 ( struct V_26 * V_27 )
{
int V_12 ;
struct V_28 * V_29 = V_27 -> V_30 . V_31 ;
struct V_32 * V_33 = & V_34 ;
V_33 -> V_30 = & V_27 -> V_30 ;
if ( V_29 ) {
V_35 [ 0 ] . V_36 = NULL ;
V_35 [ 0 ] . V_37 = F_11 ( V_29 ,
L_21 , 0 ) ;
if ( ! V_35 [ 0 ] . V_37 ) {
F_12 ( & V_27 -> V_30 ,
L_22 ) ;
V_12 = - V_38 ;
}
V_35 [ 0 ] . V_39 = NULL ;
V_35 [ 0 ] . V_40 = V_35 [ 0 ] . V_37 ;
}
V_12 = F_13 ( V_33 ) ;
if ( V_12 )
F_12 ( & V_27 -> V_30 , L_23 , V_12 ) ;
return V_12 ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_32 * V_33 = F_15 ( V_27 ) ;
F_16 ( V_33 ) ;
return 0 ;
}
