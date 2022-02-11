static int F_1 ( struct V_1 * V_2 ,
int V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
if ( ! V_7 )
return 0 ;
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
if ( F_6 ( V_7 ) )
return F_7 ( V_7 ) ;
F_8 ( V_15 , V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_18 * V_19 )
{
return F_10 ( & V_19 -> V_16 , & V_20 ,
& V_21 , 1 ) ;
}
static int F_11 ( struct V_18 * V_19 )
{
F_12 ( & V_19 -> V_16 ) ;
return 0 ;
}
