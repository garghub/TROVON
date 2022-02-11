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
V_20 = F_10 ( V_4 -> V_18 [ V_19 ] ,
V_4 -> V_15 -> V_22 ) ;
break;
case V_23 :
V_20 = ( V_4 -> V_18 [ V_19 ] >> V_4 -> V_15 -> V_24 )
* V_4 -> V_15 -> V_25 ;
V_20 = F_10 ( V_20 , 1000 ) ;
break;
case V_26 :
V_20 = V_4 -> V_18 [ V_19 ] * V_4 -> V_15 -> V_27 ;
break;
case V_28 :
V_20 = V_4 -> V_18 [ V_19 ] ;
break;
default:
F_11 ( 1 ) ;
V_20 = 0 ;
break;
}
return V_20 ;
}
static T_2 F_12 ( struct V_2 * V_3 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_32 * V_33 = F_13 ( V_30 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
return snprintf ( V_31 , V_34 , L_2 ,
F_9 ( V_4 , V_33 -> V_35 ) ) ;
}
static int F_16 ( struct V_5 * V_6 ,
const struct V_36 * V_37 )
{
struct V_38 * V_39 = V_6 -> V_39 ;
struct V_40 * V_41 ;
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_42 ;
long V_43 = 10000 ;
T_3 V_20 ;
if ( ! F_17 ( V_39 , V_44 ) )
return - V_45 ;
V_4 = F_18 ( V_3 , sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 )
return - V_47 ;
if ( F_19 ( V_3 ) ) {
V_41 = F_19 ( V_3 ) ;
V_43 = V_41 -> V_48 ;
} else if ( ! F_20 ( V_3 -> V_49 ,
L_3 , & V_20 ) ) {
V_43 = V_20 ;
}
if ( V_43 <= 0 )
return - V_45 ;
V_4 -> V_50 = V_37 -> V_51 ;
V_4 -> V_15 = & V_52 [ V_4 -> V_50 ] ;
F_21 ( V_6 , V_53 ,
V_4 -> V_15 -> V_54 ) ;
F_21 ( V_6 , V_55 ,
V_4 -> V_15 -> V_56 / V_43 ) ;
V_4 -> V_6 = V_6 ;
F_22 ( & V_4 -> V_8 ) ;
V_42 = F_23 ( V_3 , V_6 -> V_57 ,
V_4 , V_58 ) ;
if ( F_14 ( V_42 ) )
return F_15 ( V_42 ) ;
F_24 ( V_3 , L_4 ,
V_37 -> V_57 , V_43 ) ;
return 0 ;
}
