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
F_9 ( V_18 , V_34 ,
F_10 ( V_34 ) ) ;
F_11 ( V_18 , V_35 , F_10 ( V_35 ) ) ;
F_12 ( V_18 , L_4 ) ;
F_12 ( V_18 , L_5 ) ;
#ifdef F_13
F_14 ( V_18 , L_6 ) ;
#else
F_12 ( V_18 , L_6 ) ;
#endif
F_14 ( V_18 , L_7 ) ;
return 0 ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_40 . V_41 ;
struct V_38 * V_42 , * V_43 ;
struct V_44 * V_45 ;
struct V_15 * V_16 = & V_46 ;
int V_11 ;
if ( ! V_39 ) {
if ( ! ( F_16 () ||
F_17 () ) )
return - V_47 ;
}
V_11 = F_18 ( 0 ) ;
if ( V_11 ) {
F_19 ( & V_37 -> V_40 , L_8 ) ;
return - V_48 ;
}
V_24 = F_20 ( NULL , L_9 ) ;
if ( F_21 ( V_24 ) ) {
F_7 ( V_33 L_10 ) ;
V_11 = F_22 ( V_24 ) ;
goto V_49;
}
V_45 = F_20 ( NULL , L_11 ) ;
if ( F_21 ( V_45 ) ) {
F_7 ( V_33 L_12 ) ;
V_11 = F_22 ( V_45 ) ;
goto V_50;
}
V_11 = F_23 ( V_24 , V_45 ) ;
F_24 ( V_45 ) ;
if ( V_11 != 0 ) {
F_7 ( V_33 L_13 ) ;
goto V_50;
}
F_25 ( V_24 , V_31 ) ;
V_16 -> V_40 = & V_37 -> V_40 ;
if ( V_39 ) {
V_11 = F_26 ( V_16 , L_14 ) ;
if ( V_11 )
goto V_49;
V_11 = F_27 ( V_16 ,
L_15 ) ;
if ( V_11 )
goto V_49;
V_51 . V_52 = NULL ;
V_42 = F_28 ( V_39 , L_16 , 0 ) ;
if ( ! V_42 ) {
F_19 ( & V_37 -> V_40 , L_17 ) ;
return - V_48 ;
}
V_51 . V_53 = V_42 ;
V_51 . V_54 = NULL ;
V_51 . V_55 = NULL ;
V_43 = F_28 ( V_39 , L_18 , 0 ) ;
if ( ! V_43 ) {
F_19 ( & V_37 -> V_40 , L_19 ) ;
return - V_48 ;
}
V_51 . V_56 = V_43 ;
V_51 . V_57 = V_43 ;
F_29 ( V_42 ) ;
F_29 ( V_43 ) ;
}
V_11 = F_30 ( V_16 ) ;
if ( V_11 ) {
F_7 ( V_33 L_20 ) ;
}
return V_11 ;
V_50:
F_24 ( V_24 ) ;
V_24 = NULL ;
V_49:
F_31 ( 0 ) ;
return V_11 ;
}
static int F_32 ( struct V_36 * V_37 )
{
struct V_15 * V_16 = F_33 ( V_37 ) ;
F_5 ( V_24 ) ;
V_24 = NULL ;
F_34 ( V_16 ) ;
F_31 ( 0 ) ;
return 0 ;
}
