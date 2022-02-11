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
if ( V_11 == 0 )
return 0 ;
V_11 = V_11 * V_4 -> V_12 - V_4 -> V_12 / 2 ;
return V_11 * F_6 ( V_4 -> V_13 ,
( 1 << V_4 -> V_14 ) * V_4 -> V_12 ) ;
}
static T_3 F_7 ( struct V_15 * V_16 , struct V_17 * V_18 ,
char * V_7 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 , V_19 ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_19 = F_5 ( V_4 , V_6 ) ;
return sprintf ( V_7 , L_1 , V_19 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
int V_22 ;
struct V_3 * V_4 = NULL ;
if ( ! F_10 ( V_2 -> V_23 , V_24 ) )
return - V_25 ;
V_4 = F_11 ( & V_2 -> V_16 , sizeof( struct V_3 ) ,
V_26 ) ;
if ( ! V_4 )
return - V_27 ;
F_12 ( V_2 , V_4 ) ;
switch ( V_21 -> V_28 ) {
case V_29 :
V_4 -> V_9 = V_30 ;
V_4 -> V_10 = V_31 ;
V_4 -> V_14 = V_32 ;
V_4 -> V_12 = V_33 ;
break;
case V_34 :
V_4 -> V_9 = V_35 ;
V_4 -> V_10 = V_36 ;
V_4 -> V_14 = V_37 ;
V_4 -> V_12 = V_38 ;
break;
}
if ( F_13 ( & V_2 -> V_16 ) ) {
V_4 -> V_13 = * ( V_39 * ) F_13 ( & V_2 -> V_16 ) ;
if ( V_4 -> V_13 > V_40 || V_4 -> V_13 < V_41 )
return - V_42 ;
} else {
V_4 -> V_13 = V_43 ;
}
V_22 = F_14 ( & V_2 -> V_16 . V_44 , & V_45 . V_18 ) ;
if ( V_22 )
return V_22 ;
V_4 -> V_46 = F_15 ( & V_2 -> V_16 ) ;
if ( F_16 ( V_4 -> V_46 ) ) {
V_22 = F_17 ( V_4 -> V_46 ) ;
goto V_47;
}
return 0 ;
V_47:
F_18 ( & V_2 -> V_16 . V_44 , & V_45 . V_18 ) ;
return V_22 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_20 ( V_4 -> V_46 ) ;
F_18 ( & V_2 -> V_16 . V_44 , & V_45 . V_18 ) ;
return 0 ;
}
