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
V_5 -> V_7 . V_12 [ V_13 - 1 ] = '\0' ;
return & V_5 -> V_7 ;
}
static int V_9 ( struct V_1 * V_14 , struct V_15 * V_16 )
{
T_1 V_17 = - 1 ;
T_1 V_18 [ 3 ] ;
int V_19 ;
F_3 ( V_14 -> V_20 != NULL ) ;
F_3 ( V_14 -> V_8 != NULL ) ;
F_3 ( V_14 -> V_21 != NULL ) ;
if ( F_6 ( V_16 , & V_17 , 1 ) < 0 ) {
F_7 ( L_2 ) ;
F_8 ( V_16 ) ;
return - V_22 ;
}
if ( ( V_17 & V_23 ) == 0 ) {
if ( F_6 ( V_16 , & V_18 , 3 ) < 0 ) {
F_7 ( L_2 ) ;
F_8 ( V_16 ) ;
return - V_22 ;
}
V_19 = V_14 -> V_20 -> V_8 ( V_14 -> V_20 , V_16 ) ;
return V_19 ;
}
switch ( V_17 ) {
case V_24 :
V_14 -> V_21 ( V_14 , V_25 , 0 ) ;
F_8 ( V_16 ) ;
return 0 ;
case V_26 :
V_14 -> V_21 ( V_14 , V_27 , 0 ) ;
F_8 ( V_16 ) ;
return 0 ;
default:
F_8 ( V_16 ) ;
F_9 ( L_3 , V_17 , V_17 ) ;
return - V_22 ;
}
}
static int V_11 ( struct V_1 * V_14 , struct V_15 * V_16 )
{
T_1 V_28 ;
T_2 V_29 = 0 ;
struct V_30 * V_31 ;
struct V_4 * V_32 = F_10 ( V_14 ) ;
int V_19 ;
if ( ! F_11 ( V_32 , & V_19 ) ) {
F_8 ( V_16 ) ;
return V_19 ;
}
if ( F_12 ( V_16 ) > V_33 ) {
F_8 ( V_16 ) ;
return - V_34 ;
}
F_13 ( V_16 , & V_29 , 3 ) ;
V_28 = 0x08 ;
F_13 ( V_16 , & V_28 , 1 ) ;
V_31 = F_14 ( V_16 ) ;
V_31 -> V_2 = V_32 -> V_7 . V_35 ;
V_31 -> V_36 = 4 ;
V_31 -> V_3 = & V_32 -> V_3 ;
return V_14 -> V_37 -> V_10 ( V_14 -> V_37 , V_16 ) ;
}
