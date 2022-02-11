static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_8 ;
switch ( V_7 -> V_9 ) {
case V_10 :
V_8 = L_1 ;
break;
case V_11 :
V_8 = L_2 ;
break;
case V_12 :
V_8 = L_3 ;
break;
default:
V_8 = L_4 ;
break;
}
return sprintf ( V_5 , L_5 , V_8 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_4 ( V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_13 * V_14 = F_6 ( V_2 -> V_15 -> V_15 ) ;
struct V_16 * V_17 = F_7 ( V_2 -> V_15 ) ;
struct V_18 * V_19 = F_8 ( V_14 ) ;
int V_20 = V_7 -> V_21 ;
int V_22 ;
if ( ! V_19 )
return - V_23 ;
F_9 ( V_17 ) ;
F_10 ( V_20 , V_19 -> V_24 ) ;
V_22 = F_11 ( V_14 , V_19 , V_20 , true ) ;
if ( V_7 -> V_25 && ! V_22 ) {
V_22 = F_12 ( V_19 , V_20 ) ;
if ( V_22 < 0 )
F_13 ( & V_7 -> V_2 , L_6 ,
V_22 ) ;
F_14 ( V_14 , V_20 , V_26 ) ;
V_22 = 0 ;
}
F_15 ( V_20 , V_19 -> V_24 ) ;
F_16 ( V_17 ) ;
return V_22 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_13 * V_14 = F_6 ( V_2 -> V_15 -> V_15 ) ;
struct V_16 * V_17 = F_7 ( V_2 -> V_15 ) ;
struct V_18 * V_19 = F_8 ( V_14 ) ;
int V_20 = V_7 -> V_21 ;
int V_22 ;
if ( ! V_19 )
return - V_23 ;
if ( F_18 ( & V_7 -> V_2 , V_27 )
== V_28 )
return - V_29 ;
F_9 ( V_17 ) ;
F_10 ( V_20 , V_19 -> V_24 ) ;
V_22 = F_11 ( V_14 , V_19 , V_20 , false ) ;
F_14 ( V_14 , V_20 , V_30 ) ;
F_14 ( V_14 , V_20 , V_26 ) ;
F_15 ( V_20 , V_19 -> V_24 ) ;
F_16 ( V_17 ) ;
return V_22 ;
}
int F_19 ( struct V_18 * V_19 , int V_20 )
{
struct V_6 * V_7 = NULL ;
int V_22 ;
V_7 = F_20 ( sizeof( * V_7 ) , V_31 ) ;
if ( ! V_7 ) {
V_22 = - V_32 ;
goto exit;
}
V_19 -> V_33 [ V_20 - 1 ] = V_7 ;
V_7 -> V_21 = V_20 ;
V_7 -> V_34 = true ;
V_7 -> V_2 . V_15 = V_19 -> V_35 ;
V_7 -> V_2 . V_36 = V_37 ;
V_7 -> V_2 . type = & V_38 ;
F_21 ( & V_7 -> V_2 , L_7 , V_20 ) ;
V_22 = F_22 ( & V_7 -> V_2 ) ;
if ( V_22 )
goto V_39;
F_23 ( & V_7 -> V_2 ) ;
if ( ! F_24 ( & V_7 -> V_2 ,
V_27 ) )
F_25 ( & V_7 -> V_2 ) ;
F_26 ( & V_7 -> V_2 ) ;
return 0 ;
V_39:
F_27 ( & V_7 -> V_2 ) ;
exit:
return V_22 ;
}
void F_28 ( struct V_18 * V_19 ,
int V_20 )
{
F_29 ( & V_19 -> V_33 [ V_20 - 1 ] -> V_2 ) ;
}
