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
int V_8 ;
F_5 ( V_18
L_1
L_2 ) ;
V_8 = F_6 ( V_17 , V_19 ,
V_20 , V_21 ) ;
if ( V_8 < 0 ) {
F_5 ( V_22 L_3 , V_8 ) ;
return V_8 ;
}
#ifndef F_7
F_8 ( & V_15 -> V_2 -> V_4 , L_4 ) ;
#endif
return 0 ;
}
static int F_9 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 . V_28 ;
struct V_25 * V_29 , * V_30 ;
struct V_31 * V_32 ;
struct V_1 * V_2 = & V_33 ;
int V_8 ;
if ( ! V_26 ) {
return - V_34 ;
}
V_8 = F_10 ( 0 ) ;
if ( V_8 ) {
F_11 ( & V_24 -> V_27 , L_5 ) ;
return - V_35 ;
}
V_11 = F_12 ( NULL , L_6 ) ;
if ( F_13 ( V_11 ) ) {
F_5 ( V_22 L_7 ) ;
V_8 = F_14 ( V_11 ) ;
goto V_36;
}
V_32 = F_12 ( NULL , L_8 ) ;
if ( F_13 ( V_32 ) ) {
F_5 ( V_22 L_9 ) ;
V_8 = F_14 ( V_32 ) ;
goto V_37;
}
V_8 = F_15 ( V_11 , V_32 ) ;
F_16 ( V_32 ) ;
if ( V_8 != 0 ) {
F_5 ( V_22 L_10 ) ;
goto V_37;
}
F_17 ( V_11 , V_20 ) ;
V_2 -> V_27 = & V_24 -> V_27 ;
V_8 = F_18 ( V_2 , L_11 ) ;
if ( V_8 )
goto V_36;
V_8 = F_19 ( V_2 ,
L_12 ) ;
if ( V_8 )
goto V_36;
V_38 . V_39 = NULL ;
V_29 = F_20 ( V_26 , L_13 , 0 ) ;
if ( ! V_29 ) {
F_11 ( & V_24 -> V_27 , L_14 ) ;
return - V_35 ;
}
V_38 . V_40 = V_29 ;
V_38 . V_41 = NULL ;
V_38 . V_42 = NULL ;
V_30 = F_20 ( V_26 , L_15 , 0 ) ;
if ( ! V_30 ) {
F_11 ( & V_24 -> V_27 , L_16 ) ;
return - V_35 ;
}
V_38 . V_43 = V_30 ;
V_38 . V_44 = V_30 ;
F_21 ( V_29 ) ;
F_21 ( V_30 ) ;
V_8 = F_22 ( V_2 ) ;
if ( V_8 ) {
F_5 ( V_22 L_17 ) ;
}
return V_8 ;
V_37:
F_16 ( V_11 ) ;
V_11 = NULL ;
V_36:
F_23 ( 0 ) ;
return V_8 ;
}
static int F_24 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_25 ( V_24 ) ;
F_3 ( V_11 ) ;
V_11 = NULL ;
F_26 ( V_2 ) ;
F_23 ( 0 ) ;
return 0 ;
}
