static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 ;
F_3 ( & V_4 -> V_8 ) ;
if ( F_4 ( V_9 , V_4 -> V_10 +
V_11 / V_12 ) || ! V_4 -> V_13 ) {
int V_14 ;
F_5 ( & V_6 -> V_3 , L_1 ) ;
for ( V_14 = 0 ; V_14 < V_4 -> V_15 -> V_16 ; V_14 ++ ) {
int V_17 = F_6 ( V_6 , V_14 ) ;
if ( V_17 < 0 ) {
V_7 = F_7 ( V_17 ) ;
goto abort;
}
V_4 -> V_18 [ V_14 ] = V_17 ;
}
V_4 -> V_10 = V_9 ;
V_4 -> V_13 = 1 ;
}
abort:
F_8 ( & V_4 -> V_8 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_4 , T_1 V_19 )
{
int V_20 ;
switch ( V_19 ) {
case V_21 :
V_20 = F_10 ( ( V_22 ) V_4 -> V_18 [ V_19 ] ,
V_4 -> V_15 -> V_23 ) ;
break;
case V_24 :
V_20 = ( V_4 -> V_18 [ V_19 ] >> V_4 -> V_15 -> V_25 )
* V_4 -> V_15 -> V_26 ;
V_20 = F_10 ( V_20 , 1000 ) ;
break;
case V_27 :
V_20 = V_4 -> V_18 [ V_19 ] * V_4 -> V_15 -> V_28 ;
break;
case V_29 :
V_20 = ( V_22 ) V_4 -> V_18 [ V_19 ] ;
break;
default:
F_11 ( 1 ) ;
V_20 = 0 ;
break;
}
return V_20 ;
}
static T_2 F_12 ( struct V_2 * V_3 ,
struct V_30 * V_31 , char * V_32 )
{
struct V_33 * V_34 = F_13 ( V_31 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
return snprintf ( V_32 , V_35 , L_2 ,
F_9 ( V_4 , V_34 -> V_36 ) ) ;
}
static int F_16 ( struct V_5 * V_6 ,
const struct V_37 * V_38 )
{
struct V_39 * V_40 = V_6 -> V_40 ;
struct V_41 * V_42 ;
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_43 ;
long V_44 = 10000 ;
T_3 V_20 ;
int V_7 ;
if ( ! F_17 ( V_40 , V_45 ) )
return - V_46 ;
V_4 = F_18 ( V_3 , sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 )
return - V_48 ;
if ( F_19 ( V_3 ) ) {
V_42 = F_19 ( V_3 ) ;
V_44 = V_42 -> V_49 ;
} else if ( ! F_20 ( V_3 -> V_50 ,
L_3 , & V_20 ) ) {
V_44 = V_20 ;
}
if ( V_44 <= 0 )
return - V_46 ;
V_4 -> V_51 = V_38 -> V_52 ;
V_4 -> V_15 = & V_53 [ V_4 -> V_51 ] ;
V_7 = F_21 ( V_6 , V_54 ,
V_4 -> V_15 -> V_55 ) ;
if ( V_7 < 0 ) {
F_22 ( V_3 ,
L_4 , V_7 ) ;
return - V_46 ;
}
V_7 = F_21 ( V_6 , V_56 ,
V_4 -> V_15 -> V_57 / V_44 ) ;
if ( V_7 < 0 ) {
F_22 ( V_3 ,
L_5 , V_7 ) ;
return - V_46 ;
}
V_4 -> V_6 = V_6 ;
F_23 ( & V_4 -> V_8 ) ;
V_43 = F_24 ( V_3 , V_6 -> V_58 ,
V_4 , V_59 ) ;
if ( F_14 ( V_43 ) )
return F_15 ( V_43 ) ;
F_25 ( V_3 , L_6 ,
V_38 -> V_58 , V_44 ) ;
return 0 ;
}
