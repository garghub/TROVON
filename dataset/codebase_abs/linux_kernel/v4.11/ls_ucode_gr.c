static void *
F_1 ( const struct V_1 * V_2 , const struct V_1 * V_3 ,
const struct V_1 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 = ( void * ) V_2 -> V_4 ;
struct V_9 * V_10 = ( void * ) V_2 -> V_4 + V_8 -> V_11 ;
void * V_12 = ( void * ) V_2 -> V_4 + V_8 -> V_13 ;
T_1 V_14 = 0 ;
void * V_15 ;
V_6 -> V_16 = V_14 ;
V_6 -> V_17 = F_2 ( V_10 -> V_18 , sizeof( T_1 ) ) ;
V_6 -> V_19 = V_10 -> V_20 * 256 ;
V_6 -> V_21 = V_10 -> V_20 * 256 ;
V_14 = F_2 ( V_14 + V_6 -> V_17 , V_22 ) ;
V_6 -> V_23 = V_14 ;
V_6 -> V_24 = F_2 ( V_3 -> V_25 , V_22 ) +
F_2 ( V_4 -> V_25 , V_22 ) ;
V_6 -> V_26 = 0 ;
V_6 -> V_27 = 0 ;
V_6 -> V_28 = 0 ;
V_6 -> V_29 = 0 ;
V_6 -> V_30 = F_2 ( V_3 -> V_25 , V_22 ) ;
V_14 = F_2 ( V_14 + V_6 -> V_30 , V_22 ) ;
V_6 -> V_31 = V_14 - V_6 -> V_23 ;
V_6 -> V_32 = F_2 ( V_4 -> V_25 , V_22 ) ;
V_6 -> V_33 = F_2 ( V_10 -> V_18 , V_22 ) +
V_6 -> V_24 ;
V_15 = F_3 ( V_6 -> V_33 , V_34 ) ;
if ( ! V_15 )
return F_4 ( - V_35 ) ;
memcpy ( V_15 + V_6 -> V_16 , V_12 ,
V_10 -> V_18 ) ;
memcpy ( V_15 + V_6 -> V_23 , V_3 -> V_4 , V_3 -> V_25 ) ;
memcpy ( V_15 + V_6 -> V_23 + V_6 -> V_31 ,
V_4 -> V_4 , V_4 -> V_25 ) ;
return V_15 ;
}
static int
F_5 ( const struct V_36 * V_37 , struct V_38 * V_39 ,
const char * V_40 )
{
const struct V_1 * V_2 , * V_3 , * V_4 , * V_41 ;
char V_42 [ 64 ] ;
int V_43 ;
snprintf ( V_42 , sizeof( V_42 ) , L_1 , V_40 ) ;
V_43 = F_6 ( V_37 -> V_44 , V_42 , & V_2 ) ;
if ( V_43 )
goto error;
snprintf ( V_42 , sizeof( V_42 ) , L_2 , V_40 ) ;
V_43 = F_6 ( V_37 -> V_44 , V_42 , & V_3 ) ;
if ( V_43 )
goto V_45;
snprintf ( V_42 , sizeof( V_42 ) , L_3 , V_40 ) ;
V_43 = F_6 ( V_37 -> V_44 , V_42 , & V_4 ) ;
if ( V_43 )
goto V_46;
snprintf ( V_42 , sizeof( V_42 ) , L_4 , V_40 ) ;
V_43 = F_6 ( V_37 -> V_44 , V_42 , & V_41 ) ;
if ( V_43 )
goto V_47;
V_39 -> V_41 = F_7 ( V_41 -> V_4 , V_41 -> V_25 , V_34 ) ;
if ( ! V_39 -> V_41 ) {
V_43 = - V_35 ;
goto V_48;
}
V_39 -> V_49 = V_41 -> V_25 ;
V_39 -> V_50 = F_1 ( V_2 , V_3 , V_4 ,
& V_39 -> V_51 ) ;
if ( F_8 ( V_39 -> V_50 ) ) {
V_43 = F_9 ( V_39 -> V_50 ) ;
goto V_47;
}
V_39 -> V_52 = V_39 -> V_51 . V_33 ;
V_48:
F_10 ( V_41 ) ;
V_47:
F_10 ( V_4 ) ;
V_46:
F_10 ( V_3 ) ;
V_45:
F_10 ( V_2 ) ;
error:
return V_43 ;
}
int
F_11 ( const struct V_36 * V_37 ,
struct V_38 * V_39 )
{
return F_5 ( V_37 , V_39 , L_5 ) ;
}
int
F_12 ( const struct V_36 * V_37 ,
struct V_38 * V_39 )
{
return F_5 ( V_37 , V_39 , L_6 ) ;
}
