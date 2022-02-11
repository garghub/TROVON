static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 , V_12 ;
switch ( F_2 ( V_4 ) ) {
case 8000 :
break;
default:
F_3 ( V_13 L_1 ,
V_14 , __LINE__ , F_2 ( V_4 ) ) ;
return - V_15 ;
}
V_11 = V_16 / F_2 ( V_4 ) / 2 ;
if ( V_16 == V_17 ) {
V_12 = F_4 ( V_9 , V_18 ,
V_16 , V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_9 , V_20 ,
V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
} else {
V_12 = F_4 ( V_9 , V_21 ,
V_16 , V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_9 , V_20 ,
V_21 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_9 , V_22 , 0 ,
V_17 , V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_12 = F_4 ( V_10 , V_23 ,
V_16 , V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_10 , V_24 , V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_7 ( struct V_25 * V_26 )
{
int V_12 = 0 ;
V_17 = V_27 ;
V_16 = V_28 ;
if ( F_8 () || F_9 () )
V_17 = V_16 = V_29 ;
V_30 . V_31 = & V_26 -> V_31 ;
V_12 = F_10 ( & V_26 -> V_31 , & V_30 ) ;
if ( V_12 )
F_11 ( & V_26 -> V_31 , L_2 , V_12 ) ;
return V_12 ;
}
