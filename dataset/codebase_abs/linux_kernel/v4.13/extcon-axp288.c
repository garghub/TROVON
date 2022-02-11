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
int V_7 , V_12 , V_13 , V_14 ;
T_1 V_15 ;
unsigned int V_16 = V_2 -> V_17 ;
bool V_18 = false ;
V_7 = F_2 ( V_2 -> V_8 , V_19 , & V_14 ) ;
if ( V_7 < 0 ) {
F_7 ( V_2 -> V_11 , L_2 ) ;
return V_7 ;
}
V_18 = ( V_14 & V_20 ) ;
if ( ! V_18 )
goto V_21;
V_7 = F_2 ( V_2 -> V_8 , V_22 , & V_13 ) ;
if ( V_7 < 0 )
goto V_23;
if ( V_13 & V_24 ) {
F_4 ( V_2 -> V_11 , L_3 ) ;
goto V_23;
}
V_7 = F_2 ( V_2 -> V_8 , V_25 , & V_12 ) ;
if ( V_7 < 0 )
goto V_23;
V_15 = ( V_12 & V_26 ) >> V_27 ;
switch ( V_15 ) {
case V_28 :
F_4 ( V_2 -> V_11 , L_4 ) ;
V_16 = V_29 ;
break;
case V_30 :
F_4 ( V_2 -> V_11 , L_5 ) ;
V_16 = V_31 ;
break;
case V_32 :
F_4 ( V_2 -> V_11 , L_6 ) ;
V_16 = V_33 ;
break;
default:
F_8 ( V_2 -> V_11 ,
L_7 ) ;
}
V_21:
if ( V_2 -> V_34 )
F_9 ( V_2 -> V_34 ,
V_18 ? V_35
: V_36 ) ;
F_10 ( V_2 -> V_37 , V_2 -> V_17 , false ) ;
if ( V_2 -> V_17 == V_29 )
F_10 ( V_2 -> V_37 , V_38 , false ) ;
if ( V_18 ) {
F_10 ( V_2 -> V_37 , V_16 , V_18 ) ;
if ( V_16 == V_29 )
F_10 ( V_2 -> V_37 , V_38 ,
V_18 ) ;
V_2 -> V_17 = V_16 ;
}
return 0 ;
V_23:
if ( V_7 < 0 )
F_7 ( V_2 -> V_11 , L_8 ) ;
return V_7 ;
}
static T_2 F_11 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
int V_7 ;
V_7 = F_6 ( V_2 ) ;
if ( V_7 < 0 )
F_7 ( V_2 -> V_11 , L_9 ) ;
return V_41 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_8 , V_22 ,
V_42 , 0 ) ;
F_13 ( V_2 -> V_8 , V_22 ,
V_42 , V_42 ) ;
}
static int F_14 ( struct V_43 * V_44 )
{
struct V_1 * V_2 ;
struct V_45 * V_46 = F_15 ( V_44 -> V_11 . V_47 ) ;
struct V_48 * V_49 = V_44 -> V_11 . V_50 ;
int V_7 , V_5 , V_51 , V_52 ;
V_2 = F_16 ( & V_44 -> V_11 , sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
V_2 -> V_11 = & V_44 -> V_11 ;
V_2 -> V_8 = V_46 -> V_8 ;
V_2 -> V_55 = V_46 -> V_55 ;
V_2 -> V_17 = V_56 ;
if ( V_49 )
V_2 -> V_34 = V_49 -> V_34 ;
F_17 ( V_44 , V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_37 = F_18 ( & V_44 -> V_11 ,
V_57 ) ;
if ( F_19 ( V_2 -> V_37 ) ) {
F_7 ( & V_44 -> V_11 , L_10 ) ;
return F_20 ( V_2 -> V_37 ) ;
}
V_7 = F_21 ( & V_44 -> V_11 , V_2 -> V_37 ) ;
if ( V_7 ) {
F_7 ( & V_44 -> V_11 , L_11 ) ;
return V_7 ;
}
if ( V_2 -> V_34 ) {
V_52 = F_22 ( V_2 -> V_34 ) ;
V_7 = F_23 ( & V_44 -> V_11 , V_52 , L_12 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_44 -> V_11 ,
L_13 , V_52 ) ;
return V_7 ;
}
F_24 ( V_2 -> V_34 ,
V_36 ) ;
}
for ( V_5 = 0 ; V_5 < V_58 ; V_5 ++ ) {
V_51 = F_25 ( V_44 , V_5 ) ;
V_2 -> V_39 [ V_5 ] = F_26 ( V_2 -> V_55 , V_51 ) ;
if ( V_2 -> V_39 [ V_5 ] < 0 ) {
F_7 ( & V_44 -> V_11 ,
L_14 , V_51 ) ;
V_7 = V_2 -> V_39 [ V_5 ] ;
return V_7 ;
}
V_7 = F_27 ( & V_44 -> V_11 , V_2 -> V_39 [ V_5 ] ,
NULL , F_11 ,
V_59 | V_60 ,
V_44 -> V_61 , V_2 ) ;
if ( V_7 ) {
F_7 ( & V_44 -> V_11 , L_15 ,
V_2 -> V_39 [ V_5 ] ) ;
return V_7 ;
}
}
F_12 ( V_2 ) ;
return 0 ;
}
