static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
static int V_7 ;
int V_8 = 0 ;
switch ( V_6 ) {
case V_9 :
case V_10 :
if ( ! V_7 )
V_8 = F_2 ( V_11 ) ;
if ( V_8 == 0 )
V_7 = 1 ;
break;
case V_12 :
case V_13 :
if ( V_7 )
F_3 ( V_11 ) ;
V_7 = 0 ;
break;
}
return V_8 ;
}
static int F_4 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_15 -> V_19 ;
struct V_3 * V_4 = & V_17 -> V_4 ;
int V_8 ;
F_5 ( V_20
L_1
L_2 ) ;
V_8 = F_6 ( V_19 , V_21 ,
V_22 , V_23 ) ;
if ( V_8 < 0 ) {
F_5 ( V_24 L_3 , V_8 ) ;
return V_8 ;
}
F_7 ( V_4 , L_4 ) ;
F_7 ( V_4 , L_5 ) ;
#ifndef F_8
F_7 ( & V_15 -> V_2 -> V_4 , L_6 ) ;
#endif
return 0 ;
}
static int F_9 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_29 . V_30 ;
struct V_27 * V_31 , * V_32 ;
struct V_33 * V_34 ;
struct V_1 * V_2 = & V_35 ;
int V_8 ;
if ( ! V_28 ) {
return - V_36 ;
}
V_8 = F_10 ( 0 ) ;
if ( V_8 ) {
F_11 ( & V_26 -> V_29 , L_7 ) ;
return - V_37 ;
}
V_11 = F_12 ( NULL , L_8 ) ;
if ( F_13 ( V_11 ) ) {
F_5 ( V_24 L_9 ) ;
V_8 = F_14 ( V_11 ) ;
goto V_38;
}
V_34 = F_12 ( NULL , L_10 ) ;
if ( F_13 ( V_34 ) ) {
F_5 ( V_24 L_11 ) ;
V_8 = F_14 ( V_34 ) ;
goto V_39;
}
V_8 = F_15 ( V_11 , V_34 ) ;
F_16 ( V_34 ) ;
if ( V_8 != 0 ) {
F_5 ( V_24 L_12 ) ;
goto V_39;
}
F_17 ( V_11 , V_22 ) ;
V_2 -> V_29 = & V_26 -> V_29 ;
V_8 = F_18 ( V_2 , L_13 ) ;
if ( V_8 )
goto V_38;
V_8 = F_19 ( V_2 ,
L_14 ) ;
if ( V_8 )
goto V_38;
V_40 . V_41 = NULL ;
V_31 = F_20 ( V_28 , L_15 , 0 ) ;
if ( ! V_31 ) {
F_11 ( & V_26 -> V_29 , L_16 ) ;
return - V_37 ;
}
V_40 . V_42 = V_31 ;
V_40 . V_43 = NULL ;
V_40 . V_44 = NULL ;
V_32 = F_20 ( V_28 , L_17 , 0 ) ;
if ( ! V_32 ) {
F_11 ( & V_26 -> V_29 , L_18 ) ;
return - V_37 ;
}
V_40 . V_45 = V_32 ;
V_40 . V_46 = V_32 ;
F_21 ( V_31 ) ;
F_21 ( V_32 ) ;
V_8 = F_22 ( V_2 ) ;
if ( V_8 ) {
F_5 ( V_24 L_19 ) ;
}
return V_8 ;
V_39:
F_16 ( V_11 ) ;
V_11 = NULL ;
V_38:
F_23 ( 0 ) ;
return V_8 ;
}
static int F_24 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_25 ( V_26 ) ;
F_3 ( V_11 ) ;
V_11 = NULL ;
F_26 ( V_2 ) ;
F_23 ( 0 ) ;
return 0 ;
}
