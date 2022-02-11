static void F_1 ( struct V_1 * V_2 )
{
char * * V_3 ;
unsigned int V_4 , V_5 , V_6 = 0 ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_8 , V_9 , & V_4 ) ;
for ( V_5 = 0 , V_3 = V_10 ; * V_3 ; V_3 ++ , V_5 ++ ) {
if ( V_4 & F_3 ( V_5 ) ) {
F_4 ( V_2 -> V_11 , L_1 , * V_3 ) ;
V_6 |= F_3 ( V_5 ) ;
}
}
F_5 ( V_2 -> V_8 , V_9 , V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
static bool V_12 , V_13 ;
static unsigned int V_14 ;
int V_7 , V_15 , V_16 , V_17 ;
T_1 V_18 ;
bool V_19 = false ;
V_7 = F_2 ( V_2 -> V_8 , V_20 , & V_17 ) ;
if ( V_7 < 0 ) {
F_7 ( V_2 -> V_11 , L_2 ) ;
return V_7 ;
}
V_19 = ( V_17 & V_21 ) ;
if ( ! V_19 )
goto V_12;
V_7 = F_2 ( V_2 -> V_8 , V_22 , & V_16 ) ;
if ( V_7 < 0 )
goto V_23;
if ( V_16 & V_24 ) {
F_4 ( V_2 -> V_11 , L_3 ) ;
goto V_23;
}
V_7 = F_2 ( V_2 -> V_8 , V_25 , & V_15 ) ;
if ( V_7 < 0 )
goto V_23;
V_18 = ( V_15 & V_26 ) >> V_27 ;
switch ( V_18 ) {
case V_28 :
F_4 ( V_2 -> V_11 , L_4 ) ;
V_12 = true ;
V_13 = true ;
V_14 = V_29 ;
break;
case V_30 :
F_4 ( V_2 -> V_11 , L_5 ) ;
V_12 = true ;
V_13 = true ;
V_14 = V_31 ;
break;
case V_32 :
F_4 ( V_2 -> V_11 , L_6 ) ;
V_13 = true ;
V_14 = V_33 ;
break;
default:
F_8 ( V_2 -> V_11 ,
L_7 ) ;
}
V_12:
if ( V_12 ) {
if ( V_2 -> V_34 -> V_35 )
F_9 ( V_2 -> V_34 -> V_35 ,
V_19 ? V_36
: V_37 ) ;
F_10 ( & V_2 -> V_38 -> V_39 ,
V_19 ? V_40 : V_41 , NULL ) ;
}
if ( V_13 )
F_11 ( V_2 -> V_42 , V_14 , V_19 ) ;
if ( ! V_19 )
V_12 = V_13 = false ;
return 0 ;
V_23:
if ( V_7 < 0 )
F_7 ( V_2 -> V_11 , L_8 ) ;
return V_7 ;
}
static T_2 F_12 ( int V_43 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
int V_7 ;
V_7 = F_6 ( V_2 ) ;
if ( V_7 < 0 )
F_7 ( V_2 -> V_11 , L_9 ) ;
return V_45 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_8 , V_46 ,
V_47 ) ;
F_14 ( V_2 -> V_8 , V_22 ,
V_48 , 0 ) ;
F_5 ( V_2 -> V_8 , V_49 , V_50 ) ;
F_14 ( V_2 -> V_8 , V_22 ,
V_48 , V_48 ) ;
}
static int F_15 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
struct V_53 * V_54 = F_16 ( V_52 -> V_11 . V_55 ) ;
int V_7 , V_5 , V_56 , V_57 ;
V_2 = F_17 ( & V_52 -> V_11 , sizeof( * V_2 ) , V_58 ) ;
if ( ! V_2 )
return - V_59 ;
V_2 -> V_11 = & V_52 -> V_11 ;
V_2 -> V_8 = V_54 -> V_8 ;
V_2 -> V_60 = V_54 -> V_60 ;
V_2 -> V_34 = V_52 -> V_11 . V_61 ;
if ( ! V_2 -> V_34 ) {
if ( ! F_18 ( & V_52 -> V_11 ,
L_10 ) )
F_7 ( & V_52 -> V_11 , L_11 ) ;
return - V_62 ;
}
F_19 ( V_52 , V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_42 = F_20 ( & V_52 -> V_11 ,
V_63 ) ;
if ( F_21 ( V_2 -> V_42 ) ) {
F_7 ( & V_52 -> V_11 , L_12 ) ;
return F_22 ( V_2 -> V_42 ) ;
}
V_7 = F_23 ( & V_52 -> V_11 , V_2 -> V_42 ) ;
if ( V_7 ) {
F_7 ( & V_52 -> V_11 , L_13 ) ;
return V_7 ;
}
V_2 -> V_38 = F_24 ( & V_52 -> V_11 , V_64 ) ;
if ( F_21 ( V_2 -> V_38 ) ) {
F_7 ( & V_52 -> V_11 , L_14 ) ;
return F_22 ( V_2 -> V_38 ) ;
}
if ( V_2 -> V_34 -> V_35 ) {
V_57 = F_25 ( V_2 -> V_34 -> V_35 ) ;
V_7 = F_26 ( & V_52 -> V_11 , V_57 , L_15 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_52 -> V_11 ,
L_16 , V_57 ) ;
return V_7 ;
}
F_27 ( V_2 -> V_34 -> V_35 ,
V_37 ) ;
}
for ( V_5 = 0 ; V_5 < V_65 ; V_5 ++ ) {
V_56 = F_28 ( V_52 , V_5 ) ;
V_2 -> V_43 [ V_5 ] = F_29 ( V_2 -> V_60 , V_56 ) ;
if ( V_2 -> V_43 [ V_5 ] < 0 ) {
F_7 ( & V_52 -> V_11 ,
L_17 , V_56 ) ;
V_7 = V_2 -> V_43 [ V_5 ] ;
return V_7 ;
}
V_7 = F_30 ( & V_52 -> V_11 , V_2 -> V_43 [ V_5 ] ,
NULL , F_12 ,
V_66 | V_67 ,
V_52 -> V_68 , V_2 ) ;
if ( V_7 ) {
F_7 ( & V_52 -> V_11 , L_18 ,
V_2 -> V_43 [ V_5 ] ) ;
return V_7 ;
}
}
F_13 ( V_2 ) ;
return 0 ;
}
