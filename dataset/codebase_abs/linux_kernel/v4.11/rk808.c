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
static void F_7 ( void )
{
int V_16 ;
struct V_17 * V_17 = F_3 ( V_18 ) ;
if ( ! V_17 ) {
F_4 ( & V_18 -> V_2 ,
L_3 ) ;
return;
}
V_16 = F_5 ( V_17 -> V_19 ,
V_21 ,
V_22 , V_22 ) ;
if ( V_16 )
F_6 ( & V_18 -> V_2 , L_2 ) ;
}
static int F_8 ( struct V_23 * V_24 ,
const struct V_25 * V_26 )
{
struct V_27 * V_28 = V_24 -> V_2 . V_29 ;
struct V_17 * V_17 ;
const struct V_30 * V_31 ;
const struct V_32 * V_33 ;
void (* F_9)( void );
int V_34 ;
int V_35 ;
int V_36 = 0 ;
int V_16 ;
int V_37 ;
V_17 = F_10 ( & V_24 -> V_2 , sizeof( * V_17 ) , V_38 ) ;
if ( ! V_17 )
return - V_39 ;
V_17 -> V_40 = F_11 ( V_24 , V_41 ) ;
if ( V_17 -> V_40 < 0 ) {
F_6 ( & V_24 -> V_2 , L_4 ,
V_41 ) ;
return V_17 -> V_40 ;
}
F_12 ( & V_24 -> V_2 , L_5 , ( unsigned int ) V_17 -> V_40 ) ;
switch ( V_17 -> V_40 ) {
case V_42 :
V_17 -> V_43 = & V_44 ;
V_17 -> V_45 = & V_46 ;
V_31 = V_47 ;
V_34 = F_13 ( V_47 ) ;
V_33 = V_48 ;
V_35 = F_13 ( V_48 ) ;
F_9 = F_2 ;
break;
case V_49 :
V_17 -> V_43 = & V_50 ;
V_17 -> V_45 = & V_51 ;
V_31 = V_52 ;
V_34 = F_13 ( V_52 ) ;
V_33 = V_53 ;
V_35 = F_13 ( V_53 ) ;
F_9 = F_7 ;
break;
default:
F_6 ( & V_24 -> V_2 , L_6 ,
V_17 -> V_40 ) ;
return - V_54 ;
}
V_17 -> V_55 = V_24 ;
F_14 ( V_24 , V_17 ) ;
V_17 -> V_19 = F_15 ( V_24 , V_17 -> V_43 ) ;
if ( F_16 ( V_17 -> V_19 ) ) {
F_6 ( & V_24 -> V_2 , L_7 ) ;
return F_17 ( V_17 -> V_19 ) ;
}
if ( ! V_24 -> V_56 ) {
F_6 ( & V_24 -> V_2 , L_8 ) ;
return - V_54 ;
}
V_16 = F_18 ( V_17 -> V_19 , V_24 -> V_56 ,
V_57 , - 1 ,
V_17 -> V_45 , & V_17 -> V_58 ) ;
if ( V_16 ) {
F_6 ( & V_24 -> V_2 , L_9 , V_16 ) ;
return V_16 ;
}
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ ) {
V_16 = F_5 ( V_17 -> V_19 ,
V_31 [ V_37 ] . V_59 ,
V_31 [ V_37 ] . V_60 ,
V_31 [ V_37 ] . V_61 ) ;
if ( V_16 ) {
F_6 ( & V_24 -> V_2 ,
L_10 ,
V_31 [ V_37 ] . V_59 ) ;
return V_16 ;
}
}
V_16 = F_19 ( & V_24 -> V_2 , V_62 ,
V_33 , V_35 , NULL , 0 ,
F_20 ( V_17 -> V_58 ) ) ;
if ( V_16 ) {
F_6 ( & V_24 -> V_2 , L_11 , V_16 ) ;
goto V_63;
}
V_36 = F_21 ( V_28 ,
L_12 ) ;
if ( V_36 && ! V_64 ) {
V_18 = V_24 ;
V_64 = F_9 ;
}
return 0 ;
V_63:
F_22 ( V_24 -> V_56 , V_17 -> V_58 ) ;
return V_16 ;
}
static int F_23 ( struct V_23 * V_24 )
{
struct V_17 * V_17 = F_3 ( V_24 ) ;
F_22 ( V_24 -> V_56 , V_17 -> V_58 ) ;
V_64 = NULL ;
return 0 ;
}
