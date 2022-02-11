static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
char * V_4 ;
int V_5 ;
V_5 = - V_6 ;
V_4 = F_2 ( V_3 -> V_7 , V_3 -> V_8 , V_9 ) ;
if ( ! V_4 )
goto error;
V_1 -> V_4 . V_7 [ 0 ] = V_4 ;
V_5 = 0 ;
error:
return V_5 ;
}
static void
F_3 ( struct V_1 * V_1 )
{
F_4 ( V_1 -> V_4 . V_7 [ 0 ] ) ;
}
struct V_1 *
F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = (struct V_14 * ) & V_13 -> V_16 ;
struct V_17 * V_18 = (struct V_17 * ) & V_13 -> V_16 ;
char * V_19 , * V_20 ;
T_1 V_21 ;
struct V_1 * V_22 ;
const char * V_23 = V_13 -> V_23 ;
V_21 = V_24 +
V_25 + strlen ( V_23 ) +
V_26 + V_27 +
V_28 +
V_29 + ( sizeof( V_30 ) * 2 ) +
V_31 + ( sizeof( V_30 ) * 2 ) +
V_32 + ( sizeof( V_33 ) * 2 ) + 1 ;
if ( V_11 -> V_34 )
V_21 += V_35 + strlen ( V_11 -> V_34 ) ;
V_22 = F_6 ( - V_6 ) ;
V_19 = F_7 ( V_21 , V_9 ) ;
if ( V_19 == NULL )
goto V_36;
V_20 = V_19 ;
V_22 = F_6 ( - V_37 ) ;
sprintf ( V_20 , L_1 , V_38 ,
V_23 ) ;
V_20 = V_19 + strlen ( V_19 ) ;
if ( V_13 -> V_16 . V_39 == V_40 )
sprintf ( V_20 , L_2 , & V_15 -> V_41 ) ;
else if ( V_13 -> V_16 . V_39 == V_42 )
sprintf ( V_20 , L_3 , & V_18 -> V_43 ) ;
else
goto V_36;
V_20 = V_19 + strlen ( V_19 ) ;
if ( V_13 -> V_44 )
sprintf ( V_20 , L_4 ) ;
else if ( V_13 -> V_45 )
sprintf ( V_20 , L_5 ) ;
else
goto V_36;
V_20 = V_19 + strlen ( V_19 ) ;
sprintf ( V_20 , L_6 ,
F_8 ( & V_46 , V_11 -> V_47 ) ) ;
V_20 = V_19 + strlen ( V_19 ) ;
sprintf ( V_20 , L_7 ,
F_8 ( & V_46 , V_11 -> V_48 ) ) ;
if ( V_11 -> V_34 ) {
V_20 = V_19 + strlen ( V_19 ) ;
sprintf ( V_20 , L_8 , V_11 -> V_34 ) ;
}
V_20 = V_19 + strlen ( V_19 ) ;
sprintf ( V_20 , L_9 , V_49 -> V_50 ) ;
F_9 ( V_51 , L_10 , V_19 ) ;
V_22 = F_10 ( & V_52 , V_19 , L_11 ) ;
#ifdef F_11
if ( V_53 && ! F_12 ( V_22 ) ) {
struct V_54 * V_55 = V_22 -> V_4 . V_7 [ 0 ] ;
F_13 ( L_12 , V_55 -> V_7 , F_14 ( 1024U ,
V_55 -> V_56 + V_55 -> V_57 ) ) ;
}
#endif
V_36:
F_4 ( V_19 ) ;
return V_22 ;
}
