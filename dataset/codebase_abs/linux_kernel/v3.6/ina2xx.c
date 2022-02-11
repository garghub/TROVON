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
for ( V_14 = 0 ; V_14 < V_6 -> V_15 ; V_14 ++ ) {
int V_16 = F_7 ( V_5 , V_14 ) ;
if ( V_16 < 0 ) {
V_7 = F_8 ( V_16 ) ;
goto abort;
}
V_6 -> V_17 [ V_14 ] = V_16 ;
}
V_6 -> V_10 = V_9 ;
V_6 -> V_13 = 1 ;
}
abort:
F_9 ( & V_6 -> V_8 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_6 , T_1 V_18 )
{
int V_19 = V_6 -> V_17 [ V_18 ] ;
switch ( V_18 ) {
case V_20 :
V_19 = F_11 ( V_19 , 100 ) ;
break;
case V_21 :
V_19 = ( V_19 >> 3 ) * 4 ;
break;
case V_22 :
V_19 = V_19 * 20 * 1000 ;
break;
case V_23 :
break;
default:
F_12 ( 1 ) ;
V_19 = 0 ;
break;
}
return V_19 ;
}
static int F_13 ( struct V_1 * V_6 , T_1 V_18 )
{
int V_19 = V_6 -> V_17 [ V_18 ] ;
switch ( V_18 ) {
case V_20 :
V_19 = F_11 ( V_19 , 400 ) ;
break;
case V_21 :
V_19 = V_19 + F_11 ( V_19 , 4 ) ;
break;
case V_22 :
V_19 = V_19 * 25 * 1000 ;
break;
case V_23 :
break;
default:
F_12 ( 1 ) ;
V_19 = 0 ;
break;
}
return V_19 ;
}
static T_2 F_14 ( struct V_2 * V_3 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_27 * V_28 = F_15 ( V_25 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_29 = 0 ;
if ( F_16 ( V_6 ) )
return F_17 ( V_6 ) ;
switch ( V_6 -> V_30 ) {
case V_31 :
V_29 = F_10 ( V_6 , V_28 -> V_32 ) ;
break;
case V_33 :
V_29 = F_13 ( V_6 , V_28 -> V_32 ) ;
break;
default:
F_12 ( 1 ) ;
break;
}
return snprintf ( V_26 , V_34 , L_2 , V_29 ) ;
}
static int F_18 ( struct V_4 * V_5 ,
const struct V_35 * V_36 )
{
struct V_37 * V_38 = V_5 -> V_38 ;
struct V_1 * V_6 ;
struct V_39 * V_40 ;
int V_7 = 0 ;
long V_41 = 10000 ;
if ( ! F_19 ( V_38 , V_42 ) )
return - V_43 ;
V_6 = F_20 ( & V_5 -> V_3 , sizeof( * V_6 ) , V_44 ) ;
if ( ! V_6 )
return - V_45 ;
if ( V_5 -> V_3 . V_46 ) {
V_40 =
(struct V_39 * ) V_5 -> V_3 . V_46 ;
V_41 = V_40 -> V_47 ;
}
if ( V_41 <= 0 )
return - V_43 ;
V_6 -> V_30 = V_36 -> V_48 ;
switch ( V_6 -> V_30 ) {
case V_31 :
F_21 ( V_5 , V_49 ,
V_50 ) ;
F_21 ( V_5 , V_51 ,
40960000 / V_41 ) ;
F_22 ( & V_5 -> V_3 ,
L_3 , V_41 ) ;
V_6 -> V_15 = V_52 ;
break;
case V_33 :
F_21 ( V_5 , V_49 ,
V_53 ) ;
F_21 ( V_5 , V_51 ,
5120000 / V_41 ) ;
F_22 ( & V_5 -> V_3 ,
L_4 , V_41 ) ;
V_6 -> V_15 = V_54 ;
break;
default:
return - V_43 ;
}
F_23 ( V_5 , V_6 ) ;
F_24 ( & V_6 -> V_8 ) ;
V_7 = F_25 ( & V_5 -> V_3 . V_55 , & V_56 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_57 = F_26 ( & V_5 -> V_3 ) ;
if ( F_16 ( V_6 -> V_57 ) ) {
V_7 = F_17 ( V_6 -> V_57 ) ;
goto V_58;
}
return 0 ;
V_58:
F_27 ( & V_5 -> V_3 . V_55 , & V_56 ) ;
return V_7 ;
}
static int F_28 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_29 ( V_6 -> V_57 ) ;
F_27 ( & V_5 -> V_3 . V_55 , & V_56 ) ;
return 0 ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_59 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_59 ) ;
}
