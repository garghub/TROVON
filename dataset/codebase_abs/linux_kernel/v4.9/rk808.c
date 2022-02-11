static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
}
return false ;
}
static void F_2 ( void )
{
int V_16 ;
struct V_17 * V_17 = F_3 ( V_18 ) ;
if ( ! V_17 ) {
F_4 ( & V_18 -> V_2 ,
L_1 ) ;
return;
}
V_16 = F_5 ( V_17 -> V_19 ,
V_13 ,
V_20 , V_20 ) ;
if ( V_16 )
F_6 ( & V_18 -> V_2 , L_2 ) ;
}
static int F_7 ( struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
struct V_25 * V_26 = V_22 -> V_2 . V_27 ;
struct V_17 * V_17 ;
const struct V_28 * V_29 ;
const struct V_30 * V_31 ;
int V_32 ;
int V_33 ;
int V_34 = 0 ;
int V_16 ;
int V_35 ;
V_17 = F_8 ( & V_22 -> V_2 , sizeof( * V_17 ) , V_36 ) ;
if ( ! V_17 )
return - V_37 ;
V_17 -> V_38 = F_9 ( V_22 , V_39 ) ;
if ( V_17 -> V_38 < 0 ) {
F_6 ( & V_22 -> V_2 , L_3 ,
V_39 ) ;
return V_17 -> V_38 ;
}
F_10 ( & V_22 -> V_2 , L_4 , ( unsigned int ) V_17 -> V_38 ) ;
switch ( V_17 -> V_38 ) {
case V_40 :
V_17 -> V_41 = & V_42 ;
V_17 -> V_43 = & V_44 ;
V_29 = V_45 ;
V_32 = F_11 ( V_45 ) ;
V_31 = V_46 ;
V_33 = F_11 ( V_46 ) ;
break;
case V_47 :
V_17 -> V_41 = & V_48 ;
V_17 -> V_43 = & V_49 ;
V_29 = V_50 ;
V_32 = F_11 ( V_50 ) ;
V_31 = V_51 ;
V_33 = F_11 ( V_51 ) ;
break;
default:
F_6 ( & V_22 -> V_2 , L_5 ,
V_17 -> V_38 ) ;
return - V_52 ;
}
V_17 -> V_53 = V_22 ;
F_12 ( V_22 , V_17 ) ;
V_17 -> V_19 = F_13 ( V_22 , V_17 -> V_41 ) ;
if ( F_14 ( V_17 -> V_19 ) ) {
F_6 ( & V_22 -> V_2 , L_6 ) ;
return F_15 ( V_17 -> V_19 ) ;
}
if ( ! V_22 -> V_54 ) {
F_6 ( & V_22 -> V_2 , L_7 ) ;
return - V_52 ;
}
V_16 = F_16 ( V_17 -> V_19 , V_22 -> V_54 ,
V_55 , - 1 ,
V_17 -> V_43 , & V_17 -> V_56 ) ;
if ( V_16 ) {
F_6 ( & V_22 -> V_2 , L_8 , V_16 ) ;
return V_16 ;
}
for ( V_35 = 0 ; V_35 < V_32 ; V_35 ++ ) {
V_16 = F_5 ( V_17 -> V_19 ,
V_29 [ V_35 ] . V_57 ,
V_29 [ V_35 ] . V_58 ,
V_29 [ V_35 ] . V_59 ) ;
if ( V_16 ) {
F_6 ( & V_22 -> V_2 ,
L_9 ,
V_29 [ V_35 ] . V_57 ) ;
return V_16 ;
}
}
V_16 = F_17 ( & V_22 -> V_2 , V_60 ,
V_31 , V_33 , NULL , 0 ,
F_18 ( V_17 -> V_56 ) ) ;
if ( V_16 ) {
F_6 ( & V_22 -> V_2 , L_10 , V_16 ) ;
goto V_61;
}
V_34 = F_19 ( V_26 ,
L_11 ) ;
if ( V_34 && ! V_62 ) {
V_18 = V_22 ;
V_62 = F_2 ;
}
return 0 ;
V_61:
F_20 ( V_22 -> V_54 , V_17 -> V_56 ) ;
return V_16 ;
}
static int F_21 ( struct V_21 * V_22 )
{
struct V_17 * V_17 = F_3 ( V_22 ) ;
F_20 ( V_22 -> V_54 , V_17 -> V_56 ) ;
V_62 = NULL ;
return 0 ;
}
