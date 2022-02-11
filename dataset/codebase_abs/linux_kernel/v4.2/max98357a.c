static int F_1 ( struct V_1 * V_2 ,
int V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
F_3 ( V_7 , 1 ) ;
break;
case V_11 :
case V_12 :
case V_13 :
F_3 ( V_7 , 0 ) ;
break;
}
return 0 ;
}
static int F_4 ( struct V_14 * V_15 )
{
struct V_6 * V_7 ;
V_7 = F_5 ( V_15 -> V_16 , L_1 , V_17 ) ;
if ( F_6 ( V_7 ) ) {
F_7 ( V_15 -> V_16 , L_2 ,
V_18 , F_8 ( V_7 ) ) ;
return F_8 ( V_7 ) ;
}
F_9 ( V_15 , V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 )
{
int V_21 ;
V_21 = F_11 ( & V_20 -> V_16 , & V_22 ,
& V_23 , 1 ) ;
if ( V_21 )
F_7 ( & V_20 -> V_16 , L_3 ,
V_18 , V_21 ) ;
return V_21 ;
}
static int F_12 ( struct V_19 * V_20 )
{
F_13 ( & V_20 -> V_16 ) ;
return 0 ;
}
