static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = F_3 ( V_4 -> V_8 -> V_9 , V_5 ) ;
switch ( V_2 -> V_7 ) {
case V_10 :
F_4 ( V_2 ) ;
break;
case V_11 :
F_5 ( F_6 ( V_2 ) ,
L_1 , V_2 -> V_5 ) ;
break;
default:
F_7 ( F_6 ( V_2 ) ,
L_2 ,
V_2 -> V_7 , V_2 -> V_5 ) ;
break;
}
}
static void F_8 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_7 ) {
case V_10 :
F_9 ( V_2 ) ;
break;
default:
break;
}
}
static T_1 F_10 ( int V_12 , void * V_13 )
{
struct V_3 * V_14 = V_13 ;
struct V_1 * V_2 ;
T_2 V_15 , V_16 ;
int V_17 , V_18 = 8 ;
V_16 = F_11 ( V_14 ) ;
if ( ! V_16 )
return V_19 ;
while ( V_16 != 0 && ( V_18 -- >= 0 ) ) {
F_12 ( V_14 , V_16 ) ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ ) {
V_2 = & V_14 -> V_2 [ V_17 ] ;
V_15 = 0 ;
if ( V_16 & F_13 ( V_17 ) )
V_15 = F_14 ( V_14 , V_17 ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 ( V_2 , V_16 , V_15 ) ;
}
V_16 = F_11 ( V_14 ) ;
}
if ( V_16 )
F_15 ( & V_14 -> V_21 -> V_4 , L_3
L_4 , V_16 ) ;
return V_22 ;
}
static int T_3 F_16 ( struct V_23 * V_21 )
{
struct V_3 * V_14 ;
struct V_24 * V_8 ;
struct V_25 * V_26 , * V_27 ;
int V_28 , V_17 ;
V_26 = F_17 ( V_21 , V_29 , 0 ) ;
if ( ! V_26 )
return - V_30 ;
V_27 = F_17 ( V_21 , V_31 , 0 ) ;
if ( ! V_27 )
return - V_30 ;
V_8 = V_21 -> V_4 . V_32 ;
if ( ! V_8 )
return - V_30 ;
V_14 = F_18 ( sizeof( * V_14 ) , V_33 ) ;
if ( ! V_14 )
return - V_34 ;
if ( ! F_19 ( V_26 -> V_35 , F_20 ( V_26 ) ,
V_21 -> V_36 ) ) {
F_7 ( & V_21 -> V_4 , L_5 ) ;
V_28 = - V_37 ;
goto V_38;
}
V_14 -> V_39 . V_40 = F_21 ( V_26 -> V_35 , F_20 ( V_26 ) ) ;
if ( ! V_14 -> V_39 . V_40 ) {
F_7 ( & V_21 -> V_4 , L_6 ) ;
V_28 = - V_41 ;
goto V_42;
}
F_2 ( & V_14 -> V_39 . V_6 ) ;
V_14 -> V_39 . V_43 = V_8 -> V_44 ;
V_14 -> V_8 = V_21 -> V_4 . V_32 ;
V_14 -> V_21 = V_21 ;
F_22 ( V_14 ) ;
F_23 ( V_14 ) ;
V_28 = F_24 ( V_27 -> V_35 , F_10 , 0 , V_21 -> V_36 , V_14 ) ;
if ( V_28 ) {
F_7 ( & V_21 -> V_4 , L_7 ) ;
goto V_45;
}
V_28 = F_25 ( V_14 ) ;
if ( V_28 ) {
F_7 ( & V_21 -> V_4 , L_8 ) ;
goto V_46;
}
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ )
F_1 ( & V_14 -> V_2 [ V_17 ] , V_14 , V_17 ) ;
F_26 ( V_21 , V_14 ) ;
return 0 ;
V_46:
F_27 ( V_27 -> V_35 , V_14 ) ;
V_45:
F_28 ( V_14 -> V_39 . V_40 ) ;
V_42:
F_29 ( V_26 -> V_35 , F_20 ( V_26 ) ) ;
V_38:
F_30 ( V_14 ) ;
return V_28 ;
}
static int T_4 F_31 ( struct V_23 * V_21 )
{
struct V_3 * V_14 = F_32 ( V_21 ) ;
struct V_25 * V_26 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ )
F_8 ( & V_14 -> V_2 [ V_17 ] ) ;
F_33 ( V_14 ) ;
V_26 = F_17 ( V_21 , V_31 , 0 ) ;
if ( V_26 )
F_27 ( V_26 -> V_35 , V_14 ) ;
F_28 ( V_14 -> V_39 . V_40 ) ;
V_26 = F_17 ( V_21 , V_29 , 0 ) ;
if ( V_26 )
F_29 ( V_26 -> V_35 , F_20 ( V_26 ) ) ;
F_30 ( V_14 ) ;
return 0 ;
}
static int T_5 F_34 ( void )
{
return F_35 ( & V_47 ) ;
}
static void T_6 F_36 ( void )
{
F_37 ( & V_47 ) ;
}
