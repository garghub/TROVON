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
V_7 = F_5 ( V_15 -> V_16 , L_1 ) ;
if ( F_6 ( V_7 ) ) {
F_7 ( V_15 -> V_16 , L_2 ,
V_17 , F_8 ( V_7 ) ) ;
return F_8 ( V_7 ) ;
}
F_9 ( V_7 , 0 ) ;
F_10 ( V_15 , V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 )
{
int V_20 ;
V_20 = F_12 ( & V_19 -> V_16 , & V_21 ,
& V_22 , 1 ) ;
if ( V_20 )
F_7 ( & V_19 -> V_16 , L_3 ,
V_17 , V_20 ) ;
return V_20 ;
}
static int F_13 ( struct V_18 * V_19 )
{
F_14 ( & V_19 -> V_16 ) ;
return 0 ;
}
