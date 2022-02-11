static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int (* F_2)( struct V_1 * ) )
{
return V_2 -> V_5 -> V_6 ( V_4 , F_2 ) ;
}
static inline int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return V_2 -> V_5 -> V_7 ( V_2 , V_4 ) ;
}
static inline void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_5 -> V_8 ( V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_5 -> V_9 ( V_2 , V_4 ) ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
V_13 = F_7 ( V_11 , struct V_12 , V_11 ) ;
F_8 ( V_11 , L_1 , F_9 ( V_11 ) ) ;
F_10 ( V_13 ) ;
}
int F_11 ( struct V_10 * V_14 , struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_15 = - V_16 ;
V_13 = F_12 ( sizeof( * V_13 ) , V_17 ) ;
if ( ! V_13 )
goto V_18;
F_13 ( & V_13 -> V_11 ) ;
V_13 -> V_11 . V_19 = F_6 ;
V_13 -> V_11 . V_20 = V_21 ;
V_13 -> V_11 . V_22 = V_23 ;
V_13 -> V_11 . V_14 = V_14 ;
V_15 = F_14 ( & V_13 -> V_11 , L_2 , F_15 ( & V_14 -> V_24 ) ) ;
if ( V_15 )
goto V_25;
V_13 -> V_2 = V_2 ;
F_16 ( & V_26 ) ;
F_17 ( & V_13 -> V_27 , & V_28 ) ;
V_15 = F_18 ( & V_13 -> V_11 ) ;
if ( V_15 )
goto V_29;
F_19 ( & V_26 ) ;
return 0 ;
V_29:
F_20 ( & V_13 -> V_27 ) ;
F_19 ( & V_26 ) ;
V_25:
F_21 ( & V_13 -> V_11 ) ;
V_18:
return V_15 ;
}
static int F_22 ( struct V_12 * V_13 )
{
if ( V_13 -> V_2 -> V_5 -> V_7 && V_13 -> V_2 -> V_5 -> V_9 )
return 1 ;
return 0 ;
}
static void F_23 ( struct V_12 * V_13 )
{
F_8 ( & V_13 -> V_11 , L_3 ,
V_13 -> V_2 -> V_30 ) ;
F_24 ( & V_13 -> V_11 . V_24 , V_31 ) ;
if ( F_22 ( V_13 ) ) {
F_25 ( V_13 -> V_2 ) ;
V_13 -> V_4 -> V_32 ( V_13 -> V_2 ) ;
F_5 ( V_13 -> V_2 , V_13 -> V_4 ) ;
} else {
F_4 ( V_13 -> V_2 , V_13 -> V_4 ) ;
}
V_13 -> V_4 = NULL ;
V_13 -> V_11 . V_4 = NULL ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = NULL ;
F_16 ( & V_26 ) ;
F_27 (udc, &udc_list, list)
if ( V_13 -> V_2 == V_2 )
goto V_33;
F_28 ( V_2 -> V_11 . V_14 , L_4 ) ;
F_19 ( & V_26 ) ;
return;
V_33:
F_29 ( V_2 -> V_11 . V_14 , L_5 ) ;
F_20 ( & V_13 -> V_27 ) ;
F_19 ( & V_26 ) ;
if ( V_13 -> V_4 )
F_23 ( V_13 ) ;
F_24 ( & V_13 -> V_11 . V_24 , V_34 ) ;
F_30 ( & V_13 -> V_11 ) ;
}
int F_31 ( struct V_3 * V_4 ,
int (* F_2)( struct V_1 * ) )
{
struct V_12 * V_13 = NULL ;
int V_15 ;
if ( ! V_4 || ! F_2 || ! V_4 -> V_35 )
return - V_36 ;
F_16 ( & V_26 ) ;
F_27 (udc, &udc_list, list) {
if ( ! V_13 -> V_4 )
goto V_33;
}
F_32 ( L_6 ) ;
F_19 ( & V_26 ) ;
return - V_37 ;
V_33:
F_8 ( & V_13 -> V_11 , L_7 ,
V_4 -> V_38 ) ;
V_13 -> V_4 = V_4 ;
V_13 -> V_11 . V_4 = & V_4 -> V_4 ;
if ( F_22 ( V_13 ) ) {
V_15 = F_2 ( V_13 -> V_2 ) ;
if ( V_15 )
goto V_18;
V_15 = F_3 ( V_13 -> V_2 , V_4 ) ;
if ( V_15 ) {
V_4 -> V_32 ( V_13 -> V_2 ) ;
goto V_18;
}
F_33 ( V_13 -> V_2 ) ;
} else {
V_15 = F_1 ( V_13 -> V_2 , V_4 , F_2 ) ;
if ( V_15 )
goto V_18;
}
F_24 ( & V_13 -> V_11 . V_24 , V_31 ) ;
F_19 ( & V_26 ) ;
return 0 ;
V_18:
F_28 ( & V_13 -> V_11 , L_8 ,
V_13 -> V_4 -> V_38 , V_15 ) ;
V_13 -> V_4 = NULL ;
V_13 -> V_11 . V_4 = NULL ;
F_19 ( & V_26 ) ;
return V_15 ;
}
int F_34 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = NULL ;
int V_15 = - V_37 ;
if ( ! V_4 || ! V_4 -> V_32 )
return - V_36 ;
F_16 ( & V_26 ) ;
F_27 (udc, &udc_list, list)
if ( V_13 -> V_4 == V_4 ) {
F_23 ( V_13 ) ;
V_15 = 0 ;
break;
}
F_19 ( & V_26 ) ;
return V_15 ;
}
static T_1 F_35 ( struct V_10 * V_11 ,
struct V_39 * V_40 , const char * V_41 , T_2 V_42 )
{
struct V_12 * V_13 = F_36 ( V_11 ) ;
if ( F_37 ( V_41 , L_9 ) )
F_38 ( V_13 -> V_2 ) ;
return V_42 ;
}
static T_1 F_39 ( struct V_10 * V_11 ,
struct V_39 * V_40 , const char * V_41 , T_2 V_42 )
{
struct V_12 * V_13 = F_36 ( V_11 ) ;
if ( F_37 ( V_41 , L_10 ) ) {
F_33 ( V_13 -> V_2 ) ;
} else if ( F_37 ( V_41 , L_11 ) ) {
F_25 ( V_13 -> V_2 ) ;
} else {
F_28 ( V_11 , L_12 , V_41 ) ;
return - V_36 ;
}
return V_42 ;
}
static T_1 F_40 ( struct V_10 * V_11 ,
struct V_39 * V_40 , char * V_41 )
{
struct V_12 * V_13 = F_7 ( V_11 , struct V_12 , V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
switch ( V_2 -> V_43 ) {
case V_44 :
return snprintf ( V_41 , V_45 , L_13 ) ;
case V_46 :
return snprintf ( V_41 , V_45 , L_14 ) ;
case V_47 :
return snprintf ( V_41 , V_45 , L_15 ) ;
case V_48 :
return snprintf ( V_41 , V_45 , L_16 ) ;
case V_49 :
return snprintf ( V_41 , V_45 , L_17 ) ;
case V_50 :
default:
return snprintf ( V_41 , V_45 , L_18 ) ;
}
}
static int F_41 ( struct V_10 * V_11 , struct V_51 * V_52 )
{
struct V_12 * V_13 = F_7 ( V_11 , struct V_12 , V_11 ) ;
int V_15 ;
V_15 = F_42 ( V_52 , L_19 , V_13 -> V_2 -> V_30 ) ;
if ( V_15 ) {
F_28 ( V_11 , L_20 ) ;
return V_15 ;
}
if ( V_13 -> V_4 ) {
V_15 = F_42 ( V_52 , L_21 ,
V_13 -> V_4 -> V_38 ) ;
if ( V_15 ) {
F_28 ( V_11 , L_22 ) ;
return V_15 ;
}
}
return 0 ;
}
static int T_3 F_43 ( void )
{
V_21 = F_44 ( V_53 , L_23 ) ;
if ( F_45 ( V_21 ) ) {
F_46 ( L_24 ,
F_47 ( V_21 ) ) ;
return F_47 ( V_21 ) ;
}
V_21 -> V_54 = F_41 ;
return 0 ;
}
static void T_4 F_48 ( void )
{
F_49 ( V_21 ) ;
}
