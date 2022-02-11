static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_1 * V_7 = V_6 ;
F_4 ( & V_6 -> V_8 ) ;
if ( F_5 ( V_9 , V_6 -> V_10 +
V_11 / V_12 ) || ! V_6 -> V_13 ) {
int V_14 ;
F_6 ( & V_5 -> V_3 , L_1 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_15 -> V_16 ; V_14 ++ ) {
int V_17 = F_7 ( V_5 , V_14 ) ;
if ( V_17 < 0 ) {
V_7 = F_8 ( V_17 ) ;
goto abort;
}
V_6 -> V_18 [ V_14 ] = V_17 ;
}
V_6 -> V_10 = V_9 ;
V_6 -> V_13 = 1 ;
}
abort:
F_9 ( & V_6 -> V_8 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_6 , T_1 V_19 )
{
int V_20 ;
switch ( V_19 ) {
case V_21 :
V_20 = F_11 ( V_6 -> V_18 [ V_19 ] ,
V_6 -> V_15 -> V_22 ) ;
break;
case V_23 :
V_20 = ( V_6 -> V_18 [ V_19 ] >> V_6 -> V_15 -> V_24 )
* V_6 -> V_15 -> V_25 ;
V_20 = F_11 ( V_20 , 1000 ) ;
break;
case V_26 :
V_20 = V_6 -> V_18 [ V_19 ] * V_6 -> V_15 -> V_27 ;
break;
case V_28 :
V_20 = V_6 -> V_18 [ V_19 ] ;
break;
default:
F_12 ( 1 ) ;
V_20 = 0 ;
break;
}
return V_20 ;
}
static T_2 F_13 ( struct V_2 * V_3 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_32 * V_33 = F_14 ( V_30 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( F_15 ( V_6 ) )
return F_16 ( V_6 ) ;
return snprintf ( V_31 , V_34 , L_2 ,
F_10 ( V_6 , V_33 -> V_35 ) ) ;
}
static int F_17 ( struct V_4 * V_5 ,
const struct V_36 * V_37 )
{
struct V_38 * V_39 = V_5 -> V_39 ;
struct V_1 * V_6 ;
struct V_40 * V_41 ;
int V_7 ;
T_3 V_20 ;
long V_42 = 10000 ;
if ( ! F_18 ( V_39 , V_43 ) )
return - V_44 ;
V_6 = F_19 ( & V_5 -> V_3 , sizeof( * V_6 ) , V_45 ) ;
if ( ! V_6 )
return - V_46 ;
if ( F_20 ( & V_5 -> V_3 ) ) {
V_41 = F_20 ( & V_5 -> V_3 ) ;
V_42 = V_41 -> V_47 ;
} else if ( ! F_21 ( V_5 -> V_3 . V_48 ,
L_3 , & V_20 ) ) {
V_42 = V_20 ;
}
if ( V_42 <= 0 )
return - V_44 ;
V_6 -> V_49 = V_37 -> V_50 ;
V_6 -> V_15 = & V_51 [ V_6 -> V_49 ] ;
F_22 ( V_5 , V_52 ,
V_6 -> V_15 -> V_53 ) ;
F_22 ( V_5 , V_54 ,
V_6 -> V_15 -> V_55 / V_42 ) ;
F_23 ( V_5 , V_6 ) ;
F_24 ( & V_6 -> V_8 ) ;
V_7 = F_25 ( & V_5 -> V_3 . V_56 , & V_57 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_58 = F_26 ( & V_5 -> V_3 ) ;
if ( F_15 ( V_6 -> V_58 ) ) {
V_7 = F_16 ( V_6 -> V_58 ) ;
goto V_59;
}
F_27 ( & V_5 -> V_3 , L_4 ,
V_37 -> V_60 , V_42 ) ;
return 0 ;
V_59:
F_28 ( & V_5 -> V_3 . V_56 , & V_57 ) ;
return V_7 ;
}
static int F_29 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_30 ( V_6 -> V_58 ) ;
F_28 ( & V_5 -> V_3 . V_56 , & V_57 ) ;
return 0 ;
}
