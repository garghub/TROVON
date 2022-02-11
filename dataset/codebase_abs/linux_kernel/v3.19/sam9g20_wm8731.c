static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 , V_12 |
V_13 | V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_2 ( V_10 , V_12 |
V_13 | V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_3 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
enum V_19 V_20 )
{
static int V_21 ;
int V_11 = 0 ;
switch ( V_20 ) {
case V_22 :
case V_23 :
if ( ! V_21 )
V_11 = F_4 ( V_24 ) ;
if ( V_11 == 0 )
V_21 = 1 ;
break;
case V_25 :
case V_26 :
if ( V_21 )
F_5 ( V_24 ) ;
V_21 = 0 ;
break;
}
return V_11 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_27 * V_28 = V_6 -> V_28 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_17 * V_18 = & V_28 -> V_18 ;
int V_11 ;
F_7 ( V_29
L_1
L_2 ) ;
V_11 = F_8 ( V_9 , V_30 ,
V_31 , V_32 ) ;
if ( V_11 < 0 ) {
F_7 ( V_33 L_3 , V_11 ) ;
return V_11 ;
}
F_9 ( V_18 , L_4 ) ;
F_9 ( V_18 , L_5 ) ;
#ifndef F_10
F_9 ( & V_6 -> V_16 -> V_18 , L_6 ) ;
#endif
return 0 ;
}
static int F_11 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_38 . V_39 ;
struct V_36 * V_40 , * V_41 ;
struct V_42 * V_43 ;
struct V_15 * V_16 = & V_44 ;
int V_11 ;
if ( ! V_37 ) {
if ( ! ( F_12 () ||
F_13 () ) )
return - V_45 ;
}
V_11 = F_14 ( 0 ) ;
if ( V_11 ) {
F_15 ( & V_35 -> V_38 , L_7 ) ;
return - V_46 ;
}
V_24 = F_16 ( NULL , L_8 ) ;
if ( F_17 ( V_24 ) ) {
F_7 ( V_33 L_9 ) ;
V_11 = F_18 ( V_24 ) ;
goto V_47;
}
V_43 = F_16 ( NULL , L_10 ) ;
if ( F_17 ( V_43 ) ) {
F_7 ( V_33 L_11 ) ;
V_11 = F_18 ( V_43 ) ;
goto V_48;
}
V_11 = F_19 ( V_24 , V_43 ) ;
F_20 ( V_43 ) ;
if ( V_11 != 0 ) {
F_7 ( V_33 L_12 ) ;
goto V_48;
}
F_21 ( V_24 , V_31 ) ;
V_16 -> V_38 = & V_35 -> V_38 ;
if ( V_37 ) {
V_11 = F_22 ( V_16 , L_13 ) ;
if ( V_11 )
goto V_47;
V_11 = F_23 ( V_16 ,
L_14 ) ;
if ( V_11 )
goto V_47;
V_49 . V_50 = NULL ;
V_40 = F_24 ( V_37 , L_15 , 0 ) ;
if ( ! V_40 ) {
F_15 ( & V_35 -> V_38 , L_16 ) ;
return - V_46 ;
}
V_49 . V_51 = V_40 ;
V_49 . V_52 = NULL ;
V_49 . V_53 = NULL ;
V_41 = F_24 ( V_37 , L_17 , 0 ) ;
if ( ! V_41 ) {
F_15 ( & V_35 -> V_38 , L_18 ) ;
return - V_46 ;
}
V_49 . V_54 = V_41 ;
V_49 . V_55 = V_41 ;
F_25 ( V_40 ) ;
F_25 ( V_41 ) ;
}
V_11 = F_26 ( V_16 ) ;
if ( V_11 ) {
F_7 ( V_33 L_19 ) ;
}
return V_11 ;
V_48:
F_20 ( V_24 ) ;
V_24 = NULL ;
V_47:
F_27 ( 0 ) ;
return V_11 ;
}
static int F_28 ( struct V_34 * V_35 )
{
struct V_15 * V_16 = F_29 ( V_35 ) ;
F_5 ( V_24 ) ;
V_24 = NULL ;
F_30 ( V_16 ) ;
F_27 ( 0 ) ;
return 0 ;
}
