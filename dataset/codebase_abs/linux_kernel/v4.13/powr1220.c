static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
int V_7 ;
int V_8 = 0 ;
F_3 ( & V_5 -> V_9 ) ;
if ( F_4 ( V_10 , V_5 -> V_11 [ V_3 ] + V_12 ) ||
! V_5 -> V_13 [ V_3 ] ) {
if ( V_5 -> V_14 [ V_3 ] > V_15 ||
V_5 -> V_14 [ V_3 ] == 0 )
V_8 = 1 << 4 ;
V_7 = F_5 ( V_5 -> V_16 , V_17 ,
V_8 | V_3 ) ;
if ( V_7 )
goto exit;
F_6 ( 200 ) ;
V_7 = F_7 ( V_5 -> V_16 , V_18 ) ;
if ( V_7 < 0 )
goto exit;
V_6 = V_7 >> 4 ;
V_7 = F_7 ( V_5 -> V_16 , V_19 ) ;
if ( V_7 < 0 )
goto exit;
V_6 |= V_7 << 4 ;
V_6 *= V_20 ;
V_5 -> V_21 [ V_3 ] = V_6 ;
V_5 -> V_13 [ V_3 ] = true ;
V_5 -> V_11 [ V_3 ] = V_10 ;
V_7 = V_6 ;
if ( V_6 > V_5 -> V_14 [ V_3 ] )
V_5 -> V_14 [ V_3 ] = V_6 ;
} else {
V_7 = V_5 -> V_21 [ V_3 ] ;
}
exit:
F_8 ( & V_5 -> V_9 ) ;
return V_7 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_22 * V_23 , char * V_24 )
{
struct V_25 * V_26 = F_10 ( V_23 ) ;
int V_27 = F_1 ( V_2 , V_26 -> V_28 ) ;
if ( V_27 < 0 )
return V_27 ;
return sprintf ( V_24 , L_1 , V_27 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_22 * V_23 , char * V_24 )
{
struct V_25 * V_26 = F_10 ( V_23 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
return sprintf ( V_24 , L_1 , V_5 -> V_14 [ V_26 -> V_28 ] ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_22 * V_23 , char * V_24 )
{
struct V_25 * V_26 = F_10 ( V_23 ) ;
return sprintf ( V_24 , L_2 , V_29 [ V_26 -> V_28 ] ) ;
}
static int F_13 ( struct V_30 * V_16 ,
const struct V_31 * V_32 )
{
struct V_4 * V_5 ;
struct V_1 * V_33 ;
if ( ! F_14 ( V_16 -> V_34 , V_35 ) )
return - V_36 ;
V_5 = F_15 ( & V_16 -> V_2 , sizeof( * V_5 ) , V_37 ) ;
if ( ! V_5 )
return - V_38 ;
F_16 ( & V_5 -> V_9 ) ;
V_5 -> V_16 = V_16 ;
V_33 = F_17 ( & V_16 -> V_2 ,
V_16 -> V_39 , V_5 , V_40 ) ;
return F_18 ( V_33 ) ;
}
