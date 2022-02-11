static int F_1 ( union V_1 * V_2 ,
struct V_3 * T_1 V_4 ,
struct V_5 * T_2 V_4 ,
struct V_6 * V_7 )
{
struct V_8 V_9 ;
T_3 V_10 = V_2 -> V_11 . V_12 & V_13 ;
struct V_14 * V_14 = F_2 ( V_7 , V_2 -> V_15 . V_16 ) ;
if ( V_14 == NULL ) {
F_3 ( L_1 ,
V_2 -> V_11 . type ) ;
return - 1 ;
}
F_4 ( V_14 , V_7 , V_10 , V_17 ,
V_2 -> V_15 . V_16 , V_2 -> V_15 . V_15 , & V_9 ) ;
if ( V_9 . V_18 != NULL )
V_9 . V_18 -> V_19 -> V_20 = 1 ;
return 0 ;
}
static int F_5 ( union V_1 * V_2 ,
struct V_3 * T_1 V_4 ,
struct V_6 * V_7 )
{
struct V_14 * V_14 = F_2 ( V_7 , V_2 -> V_21 . V_22 ) ;
F_6 ( L_2 , V_2 -> V_21 . V_16 , V_2 -> V_21 . V_22 ,
V_2 -> V_21 . V_23 , V_2 -> V_21 . V_24 ) ;
if ( V_14 ) {
F_7 ( & V_14 -> V_25 , & V_7 -> V_26 ) ;
V_7 -> V_27 = NULL ;
F_8 ( V_14 ) ;
}
return 0 ;
}
char * F_9 ( struct V_19 * V_28 , char * V_29 , T_4 V_30 )
{
char V_31 [ V_32 * 2 + 1 ] ;
if ( ! V_28 -> V_33 )
return NULL ;
F_10 ( V_28 -> V_34 , sizeof( V_28 -> V_34 ) , V_31 ) ;
if ( V_29 == NULL ) {
if ( F_11 ( & V_29 , L_3 , V_35 ,
V_31 , V_31 + 2 ) < 0 )
return NULL ;
} else
snprintf ( V_29 , V_30 , L_3 , V_35 ,
V_31 , V_31 + 2 ) ;
return V_29 ;
}
