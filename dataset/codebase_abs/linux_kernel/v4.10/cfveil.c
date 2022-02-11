struct V_1 * F_1 ( T_1 V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( sizeof( struct V_4 ) , V_6 ) ;
if ( ! V_5 )
return NULL ;
F_3 ( F_4 ( struct V_4 , V_7 ) == 0 ) ;
F_5 ( V_5 , V_2 , V_3 , true ) ;
V_5 -> V_7 . V_8 = V_9 ;
V_5 -> V_7 . V_10 = V_11 ;
snprintf ( V_5 -> V_7 . V_12 , V_13 - 1 , L_1 , V_2 ) ;
return & V_5 -> V_7 ;
}
static int V_9 ( struct V_1 * V_14 , struct V_15 * V_16 )
{
T_1 V_17 ;
int V_18 ;
F_3 ( V_14 -> V_19 != NULL ) ;
F_3 ( V_14 -> V_8 != NULL ) ;
F_3 ( V_14 -> V_20 != NULL ) ;
if ( F_6 ( V_16 , & V_17 , 1 ) < 0 ) {
F_7 ( L_2 ) ;
F_8 ( V_16 ) ;
return - V_21 ;
}
switch ( V_17 ) {
case V_22 :
V_18 = V_14 -> V_19 -> V_8 ( V_14 -> V_19 , V_16 ) ;
return V_18 ;
case V_23 :
V_14 -> V_20 ( V_14 , V_24 , 0 ) ;
F_8 ( V_16 ) ;
return 0 ;
case V_25 :
V_14 -> V_20 ( V_14 , V_26 , 0 ) ;
F_8 ( V_16 ) ;
return 0 ;
case V_27 :
F_8 ( V_16 ) ;
return 0 ;
default:
F_9 ( L_3 , V_17 , V_17 ) ;
F_8 ( V_16 ) ;
return - V_21 ;
}
}
static int V_11 ( struct V_1 * V_14 , struct V_15 * V_16 )
{
T_1 V_28 = 0 ;
struct V_29 * V_30 ;
int V_18 ;
struct V_4 * V_31 = F_10 ( V_14 ) ;
if ( ! F_11 ( V_31 , & V_18 ) )
goto V_32;
F_3 ( V_14 -> V_33 != NULL ) ;
F_3 ( V_14 -> V_33 -> V_10 != NULL ) ;
if ( F_12 ( V_16 , & V_28 , 1 ) < 0 ) {
F_7 ( L_2 ) ;
V_18 = - V_21 ;
goto V_32;
}
V_30 = F_13 ( V_16 ) ;
V_30 -> V_2 = V_31 -> V_7 . V_34 ;
V_30 -> V_35 = 1 ;
V_30 -> V_3 = & V_31 -> V_3 ;
return V_14 -> V_33 -> V_10 ( V_14 -> V_33 , V_16 ) ;
V_32:
F_8 ( V_16 ) ;
return V_18 ;
}
