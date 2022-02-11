static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
return false ;
}
return true ;
}
static int F_2 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
struct V_16 * V_17 = F_3 ( & V_13 -> V_2 ) ;
int V_18 = 0 ;
struct V_19 * V_19 ;
int V_20 ;
if ( ! V_17 && ! V_13 -> V_2 . V_21 ) {
F_4 ( & V_13 -> V_2 ,
L_1 ) ;
return - V_22 ;
}
if ( V_17 )
V_18 = V_17 -> V_18 ;
V_19 = F_5 ( & V_13 -> V_2 , sizeof( * V_19 ) , V_23 ) ;
if ( ! V_19 ) {
F_4 ( & V_13 -> V_2 , L_2 ) ;
return - V_24 ;
}
V_19 -> V_2 = & V_13 -> V_2 ;
F_6 ( V_13 , V_19 ) ;
V_19 -> V_25 = F_7 ( V_13 , & V_26 ) ;
if ( F_8 ( V_19 -> V_25 ) ) {
V_20 = F_9 ( V_19 -> V_25 ) ;
F_4 ( & V_13 -> V_2 , L_3 , V_20 ) ;
return V_20 ;
}
if ( V_13 -> V_27 ) {
V_20 = F_10 ( V_19 -> V_25 , V_13 -> V_27 ,
V_28 | V_29 , V_18 ,
& V_30 , & V_19 -> V_31 ) ;
if ( V_20 ) {
F_4 ( & V_13 -> V_2 ,
L_4 , V_20 ) ;
return V_20 ;
}
} else {
V_32 [ V_33 ] . V_34 = 0 ;
}
V_20 = F_11 ( V_19 -> V_2 , - 1 , V_32 ,
F_12 ( V_32 ) , NULL ,
0 , F_13 ( V_19 -> V_31 ) ) ;
if ( V_20 ) {
F_4 ( & V_13 -> V_2 , L_5 ,
V_20 ) ;
goto V_35;
}
return 0 ;
V_35:
if ( V_13 -> V_27 )
F_14 ( V_13 -> V_27 , V_19 -> V_31 ) ;
return V_20 ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_19 * V_19 = F_16 ( V_13 ) ;
F_17 ( V_19 -> V_2 ) ;
if ( V_13 -> V_27 )
F_14 ( V_13 -> V_27 , V_19 -> V_31 ) ;
return 0 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_36 ) ;
}
static void T_2 F_20 ( void )
{
F_21 ( & V_36 ) ;
}
