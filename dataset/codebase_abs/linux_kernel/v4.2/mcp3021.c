static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
T_1 V_6 ;
T_2 V_7 ;
V_5 = F_3 ( V_2 , ( char * ) & V_7 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != 2 )
return - V_8 ;
V_6 = F_4 ( V_7 ) ;
V_6 = ( V_6 >> V_4 -> V_9 ) & V_4 -> V_10 ;
return V_6 ;
}
static inline T_1 F_5 ( struct V_3 * V_4 , T_1 V_11 )
{
return F_6 ( V_4 -> V_12 * V_11 , 1 << V_4 -> V_13 ) ;
}
static T_3 F_7 ( struct V_14 * V_15 , struct V_16 * V_17 ,
char * V_7 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 , V_18 ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_18 = F_5 ( V_4 , V_6 ) ;
return sprintf ( V_7 , L_1 , V_18 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
int V_21 ;
struct V_3 * V_4 = NULL ;
if ( ! F_10 ( V_2 -> V_22 , V_23 ) )
return - V_24 ;
V_4 = F_11 ( & V_2 -> V_15 , sizeof( struct V_3 ) ,
V_25 ) ;
if ( ! V_4 )
return - V_26 ;
F_12 ( V_2 , V_4 ) ;
switch ( V_20 -> V_27 ) {
case V_28 :
V_4 -> V_9 = V_29 ;
V_4 -> V_10 = V_30 ;
V_4 -> V_13 = V_31 ;
break;
case V_32 :
V_4 -> V_9 = V_33 ;
V_4 -> V_10 = V_34 ;
V_4 -> V_13 = V_35 ;
break;
}
if ( F_13 ( & V_2 -> V_15 ) ) {
V_4 -> V_12 = * ( V_36 * ) F_13 ( & V_2 -> V_15 ) ;
if ( V_4 -> V_12 > V_37 || V_4 -> V_12 < V_38 )
return - V_39 ;
} else {
V_4 -> V_12 = V_40 ;
}
V_21 = F_14 ( & V_2 -> V_15 . V_41 , & V_42 . V_17 ) ;
if ( V_21 )
return V_21 ;
V_4 -> V_43 = F_15 ( & V_2 -> V_15 ) ;
if ( F_16 ( V_4 -> V_43 ) ) {
V_21 = F_17 ( V_4 -> V_43 ) ;
goto V_44;
}
return 0 ;
V_44:
F_18 ( & V_2 -> V_15 . V_41 , & V_42 . V_17 ) ;
return V_21 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_20 ( V_4 -> V_43 ) ;
F_18 ( & V_2 -> V_15 . V_41 , & V_42 . V_17 ) ;
return 0 ;
}
