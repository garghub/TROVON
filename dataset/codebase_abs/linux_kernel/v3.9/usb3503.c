static int F_1 ( struct V_1 * V_2 ,
char V_3 , char V_4 )
{
return F_2 ( V_2 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , char V_3 )
{
return F_4 ( V_2 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , char V_3 , char V_5 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_1 ( V_2 , V_3 , V_6 | V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , char V_3 , char V_5 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_1 ( V_2 , V_3 , V_6 & ~ V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_7 ( int V_7 , int V_8 )
{
if ( F_8 ( V_7 ) )
F_9 ( V_7 , V_8 ) ;
if ( V_8 )
F_10 ( 100 ) ;
return 0 ;
}
static int F_11 ( struct V_9 * V_10 , enum V_11 V_12 )
{
struct V_1 * V_13 = V_10 -> V_2 ;
int V_6 = 0 ;
switch ( V_12 ) {
case V_14 :
F_7 ( V_10 -> V_7 , 1 ) ;
V_6 = F_1 ( V_13 , V_15 ,
( V_16
| V_17 ) ) ;
if ( V_6 < 0 ) {
F_12 ( & V_13 -> V_18 , L_1 , V_6 ) ;
goto V_19;
}
V_6 = F_5 ( V_13 , V_20 ,
( V_21 | V_22 ) ) ;
if ( V_6 < 0 ) {
F_12 ( & V_13 -> V_18 , L_2 , V_6 ) ;
goto V_19;
}
V_6 = F_5 ( V_13 , V_23 , V_24 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_13 -> V_18 , L_3 , V_6 ) ;
goto V_19;
}
V_6 = F_6 ( V_13 , V_15 ,
( V_16
| V_17 ) ) ;
if ( V_6 < 0 ) {
F_12 ( & V_13 -> V_18 , L_1 , V_6 ) ;
goto V_19;
}
V_10 -> V_12 = V_12 ;
F_13 ( & V_13 -> V_18 , L_4 ) ;
break;
case V_25 :
F_7 ( V_10 -> V_7 , 0 ) ;
V_10 -> V_12 = V_12 ;
F_13 ( & V_13 -> V_18 , L_5 ) ;
break;
default:
F_12 ( & V_13 -> V_18 , L_6 ) ;
V_6 = - V_26 ;
break;
}
V_19:
return V_6 ;
}
static int F_14 ( struct V_1 * V_13 , const struct V_27 * V_28 )
{
struct V_29 * V_30 = V_13 -> V_18 . V_31 ;
struct V_32 * V_33 = V_13 -> V_18 . V_34 ;
struct V_9 * V_10 ;
int V_6 = - V_35 ;
T_1 V_12 = V_36 ;
V_10 = F_15 ( sizeof( struct V_9 ) , V_37 ) ;
if ( ! V_10 ) {
F_12 ( & V_13 -> V_18 , L_7 ) ;
return V_6 ;
}
F_16 ( V_13 , V_10 ) ;
V_10 -> V_2 = V_13 ;
if ( V_30 ) {
V_10 -> V_38 = V_30 -> V_38 ;
V_10 -> V_39 = V_30 -> V_39 ;
V_10 -> V_7 = V_30 -> V_7 ;
V_10 -> V_12 = V_30 -> V_40 ;
} else if ( V_33 ) {
V_10 -> V_38 = F_17 ( V_33 , L_8 , 0 ) ;
if ( V_10 -> V_38 == - V_41 )
return - V_41 ;
V_10 -> V_39 = F_17 ( V_33 , L_9 , 0 ) ;
if ( V_10 -> V_39 == - V_41 )
return - V_41 ;
V_10 -> V_7 = F_17 ( V_33 , L_10 , 0 ) ;
if ( V_10 -> V_7 == - V_41 )
return - V_41 ;
F_18 ( V_33 , L_11 , & V_12 ) ;
V_10 -> V_12 = V_12 ;
}
if ( F_8 ( V_10 -> V_38 ) ) {
V_6 = F_19 ( V_10 -> V_38 ,
V_42 , L_12 ) ;
if ( V_6 ) {
F_12 ( & V_13 -> V_18 ,
L_13 ,
V_10 -> V_38 , V_6 ) ;
goto V_43;
}
}
if ( F_8 ( V_10 -> V_39 ) ) {
V_6 = F_19 ( V_10 -> V_39 ,
V_42 , L_14 ) ;
if ( V_6 ) {
F_12 ( & V_13 -> V_18 ,
L_13 ,
V_10 -> V_39 , V_6 ) ;
goto V_44;
}
}
if ( F_8 ( V_10 -> V_7 ) ) {
V_6 = F_19 ( V_10 -> V_7 ,
V_45 , L_15 ) ;
if ( V_6 ) {
F_12 ( & V_13 -> V_18 ,
L_16 ,
V_10 -> V_7 , V_6 ) ;
goto V_46;
}
}
F_11 ( V_10 , V_10 -> V_12 ) ;
F_13 ( & V_13 -> V_18 , L_17 , V_47 ,
( V_10 -> V_12 == V_14 ) ? L_18 : L_19 ) ;
return 0 ;
V_46:
if ( F_8 ( V_10 -> V_39 ) )
F_20 ( V_10 -> V_39 ) ;
V_44:
if ( F_8 ( V_10 -> V_38 ) )
F_20 ( V_10 -> V_38 ) ;
V_43:
F_21 ( V_10 ) ;
return V_6 ;
}
static int F_22 ( struct V_1 * V_13 )
{
struct V_9 * V_10 = F_23 ( V_13 ) ;
if ( F_8 ( V_10 -> V_38 ) )
F_20 ( V_10 -> V_38 ) ;
if ( F_8 ( V_10 -> V_39 ) )
F_20 ( V_10 -> V_39 ) ;
if ( F_8 ( V_10 -> V_7 ) )
F_20 ( V_10 -> V_7 ) ;
F_21 ( V_10 ) ;
return 0 ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_48 ) ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_48 ) ;
}
