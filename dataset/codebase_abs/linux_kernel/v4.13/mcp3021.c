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
static T_3 F_7 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_7 )
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
struct V_22 * V_23 = V_2 -> V_15 . V_24 ;
if ( ! F_10 ( V_2 -> V_25 , V_26 ) )
return - V_27 ;
V_4 = F_11 ( & V_2 -> V_15 , sizeof( struct V_3 ) ,
V_28 ) ;
if ( ! V_4 )
return - V_29 ;
F_12 ( V_2 , V_4 ) ;
if ( V_23 ) {
if ( ! F_13 ( V_23 , L_2 ,
& V_4 -> V_12 ) )
V_4 -> V_12 /= 1000 ;
else
V_4 -> V_12 = V_30 ;
} else {
T_4 * V_31 = F_14 ( & V_2 -> V_15 ) ;
if ( V_31 )
V_4 -> V_12 = * V_31 ;
else
V_4 -> V_12 = V_30 ;
}
switch ( V_20 -> V_32 ) {
case V_33 :
V_4 -> V_9 = V_34 ;
V_4 -> V_10 = V_35 ;
V_4 -> V_13 = V_36 ;
break;
case V_37 :
V_4 -> V_9 = V_38 ;
V_4 -> V_10 = V_39 ;
V_4 -> V_13 = V_40 ;
break;
}
if ( V_4 -> V_12 > V_41 || V_4 -> V_12 < V_42 )
return - V_43 ;
V_21 = F_15 ( & V_2 -> V_15 . V_44 , & V_45 . V_17 ) ;
if ( V_21 )
return V_21 ;
V_4 -> V_46 = F_16 ( & V_2 -> V_15 ) ;
if ( F_17 ( V_4 -> V_46 ) ) {
V_21 = F_18 ( V_4 -> V_46 ) ;
goto V_47;
}
return 0 ;
V_47:
F_19 ( & V_2 -> V_15 . V_44 , & V_45 . V_17 ) ;
return V_21 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_21 ( V_4 -> V_46 ) ;
F_19 ( & V_2 -> V_15 . V_44 , & V_45 . V_17 ) ;
return 0 ;
}
