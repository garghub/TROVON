static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
switch ( V_3 ) {
case V_4 :
F_2 ( V_2 , L_1 ) ;
break;
case V_5 :
F_2 ( V_2 , L_2 ) ;
break;
case V_6 :
F_2 ( V_2 , L_3 ) ;
break;
case V_7 :
F_2 ( V_2 , L_4 ) ;
break;
}
}
static void F_3 ( struct V_1 * V_2 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
if ( F_4 ( V_10 ) -> V_11 & V_12 ) {
F_5 ( V_2 , L_5 ) ;
F_1 ( V_2 , F_4 ( V_10 ) -> V_11 ) ;
if ( F_4 ( V_10 ) -> V_13 & V_12 ) {
F_5 ( V_2 , L_6 ) ;
F_1 ( V_2 , F_4 ( V_10 ) -> V_13 ) ;
}
}
F_5 ( V_2 , L_7 ) ;
F_6 ( V_2 , F_7 ( F_4 ( V_10 ) -> V_14 ) , F_4 ( V_10 ) -> V_15 ,
V_16 , V_17 ) ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_18 * V_15 , T_1 V_11 ,
struct V_9 * V_10 )
{
struct V_20 V_21 = { } ;
if ( F_9 ( V_19 ) ||
! F_10 ( V_19 , V_22 ) )
return 0 ;
F_4 ( V_10 ) -> V_15 = & V_15 -> V_14 ;
F_11 ( V_19 , & V_15 -> V_14 , V_22 , V_11 ,
& V_21 ) ;
F_12 ( V_19 , & V_21 ) ;
return F_13 ( V_19 , & V_21 , V_11 , V_10 , F_3 ) ;
}
static int F_14 ( struct V_18 * V_23 ,
struct V_18 * V_24 , T_1 V_11 ,
struct V_9 * V_10 )
{
if ( F_10 ( V_23 , V_22 ) )
return F_15 ( F_8 ( V_23 , V_24 , V_11 , V_10 ) ,
F_8 ( V_24 , V_23 ,
V_11 << V_25 ,
V_10 ) ) ;
if ( F_9 ( V_23 ) || V_23 == V_24 )
return 0 ;
F_4 ( V_10 ) -> V_14 = & V_23 -> V_14 ;
F_4 ( V_10 ) -> V_15 = & V_24 -> V_14 ;
F_4 ( V_10 ) -> V_11 = 0 ;
F_4 ( V_10 ) -> error = F_16 ( & V_23 -> V_14 , V_26 , 1 ) ;
return F_17 ( V_27 , V_23 , V_10 , F_3 ) ;
}
int F_18 ( struct V_28 * V_23 , struct V_28 * V_24 ,
T_1 V_11 )
{
F_19 ( V_10 , V_29 , V_30 ) ;
return F_20 ( V_23 , V_24 , F_14 ,
V_11 , & V_10 ) ;
}
