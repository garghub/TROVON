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
V_12 = F_4 ( V_9 , V_17
| V_18
| V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_4 ( V_10 , V_17
| V_18
| V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_16 == V_20 ) {
V_12 = F_5 ( V_9 , V_21 ,
V_16 , V_22 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_9 , V_23 ,
V_21 ) ;
if ( V_12 < 0 )
return V_12 ;
} else {
V_12 = F_5 ( V_9 , V_24 ,
V_16 , V_22 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_9 , V_23 ,
V_24 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_9 , V_25 , 0 ,
V_20 , V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_12 = F_5 ( V_10 , V_26 ,
V_16 , V_22 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_10 , V_27 , V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_8 ( struct V_28 * V_29 )
{
int V_12 = 0 ;
V_20 = V_30 ;
V_16 = V_31 ;
if ( F_9 () || F_10 () )
V_20 = V_16 = V_32 ;
V_33 . V_34 = & V_29 -> V_34 ;
V_12 = F_11 ( & V_33 ) ;
if ( V_12 ) {
F_12 ( & V_29 -> V_34 , L_2 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static int F_13 ( struct V_28 * V_29 )
{
F_14 ( & V_33 ) ;
F_15 ( V_29 , NULL ) ;
return 0 ;
}
