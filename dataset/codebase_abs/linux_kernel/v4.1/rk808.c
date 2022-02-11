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
int V_28 = 0 ;
int V_16 ;
int V_29 ;
if ( ! V_22 -> V_30 ) {
F_6 ( & V_22 -> V_2 , L_3 ) ;
return - V_31 ;
}
V_17 = F_8 ( & V_22 -> V_2 , sizeof( * V_17 ) , V_32 ) ;
if ( ! V_17 )
return - V_33 ;
V_17 -> V_19 = F_9 ( V_22 , & V_34 ) ;
if ( F_10 ( V_17 -> V_19 ) ) {
F_6 ( & V_22 -> V_2 , L_4 ) ;
return F_11 ( V_17 -> V_19 ) ;
}
for ( V_29 = 0 ; V_29 < F_12 ( V_35 ) ; V_29 ++ ) {
V_16 = F_5 ( V_17 -> V_19 , V_35 [ V_29 ] . V_36 ,
V_35 [ V_29 ] . V_37 ,
V_35 [ V_29 ] . V_38 ) ;
if ( V_16 ) {
F_6 ( & V_22 -> V_2 ,
L_5 , V_35 [ V_29 ] . V_36 ) ;
return V_16 ;
}
}
V_16 = F_13 ( V_17 -> V_19 , V_22 -> V_30 ,
V_39 , - 1 ,
& V_40 , & V_17 -> V_41 ) ;
if ( V_16 ) {
F_6 ( & V_22 -> V_2 , L_6 , V_16 ) ;
return V_16 ;
}
V_17 -> V_42 = V_22 ;
F_14 ( V_22 , V_17 ) ;
V_16 = F_15 ( & V_22 -> V_2 , - 1 ,
V_43 , F_12 ( V_43 ) ,
NULL , 0 , F_16 ( V_17 -> V_41 ) ) ;
if ( V_16 ) {
F_6 ( & V_22 -> V_2 , L_7 , V_16 ) ;
goto V_44;
}
V_28 = F_17 ( V_26 ,
L_8 ) ;
if ( V_28 && ! V_45 ) {
V_18 = V_22 ;
V_45 = F_2 ;
}
return 0 ;
V_44:
F_18 ( V_22 -> V_30 , V_17 -> V_41 ) ;
return V_16 ;
}
static int F_19 ( struct V_21 * V_22 )
{
struct V_17 * V_17 = F_3 ( V_22 ) ;
F_18 ( V_22 -> V_30 , V_17 -> V_41 ) ;
F_20 ( & V_22 -> V_2 ) ;
V_45 = NULL ;
return 0 ;
}
