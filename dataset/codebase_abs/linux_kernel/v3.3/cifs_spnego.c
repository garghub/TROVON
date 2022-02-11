static int
F_1 ( struct V_1 * V_1 , const void * V_2 , T_1 V_3 )
{
char * V_4 ;
int V_5 ;
V_5 = - V_6 ;
V_4 = F_2 ( V_3 , V_7 ) ;
if ( ! V_4 )
goto error;
memcpy ( V_4 , V_2 , V_3 ) ;
V_1 -> V_4 . V_2 = V_4 ;
V_5 = 0 ;
error:
return V_5 ;
}
static void
F_3 ( struct V_1 * V_1 )
{
F_4 ( V_1 -> V_4 . V_2 ) ;
}
struct V_1 *
F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = (struct V_12 * ) & V_11 -> V_14 ;
struct V_15 * V_16 = (struct V_15 * ) & V_11 -> V_14 ;
char * V_17 , * V_18 ;
T_1 V_19 ;
struct V_1 * V_20 ;
const char * V_21 = V_11 -> V_21 ;
V_19 = V_22 +
V_23 + strlen ( V_21 ) +
V_24 + V_25 +
V_26 +
V_27 + ( sizeof( V_28 ) * 2 ) +
V_29 + ( sizeof( V_28 ) * 2 ) +
V_30 + ( sizeof( V_31 ) * 2 ) + 1 ;
if ( V_9 -> V_32 )
V_19 += V_33 + strlen ( V_9 -> V_32 ) ;
V_20 = F_6 ( - V_6 ) ;
V_17 = F_7 ( V_19 , V_7 ) ;
if ( V_17 == NULL )
goto V_34;
V_18 = V_17 ;
V_20 = F_6 ( - V_35 ) ;
sprintf ( V_18 , L_1 , V_36 ,
V_21 ) ;
V_18 = V_17 + strlen ( V_17 ) ;
if ( V_11 -> V_14 . V_37 == V_38 )
sprintf ( V_18 , L_2 , & V_13 -> V_39 ) ;
else if ( V_11 -> V_14 . V_37 == V_40 )
sprintf ( V_18 , L_3 , & V_16 -> V_41 ) ;
else
goto V_34;
V_18 = V_17 + strlen ( V_17 ) ;
if ( V_11 -> V_42 )
sprintf ( V_18 , L_4 ) ;
else if ( V_11 -> V_43 )
sprintf ( V_18 , L_5 ) ;
else
goto V_34;
V_18 = V_17 + strlen ( V_17 ) ;
sprintf ( V_18 , L_6 , V_9 -> V_44 ) ;
V_18 = V_17 + strlen ( V_17 ) ;
sprintf ( V_18 , L_7 , V_9 -> V_45 ) ;
if ( V_9 -> V_32 ) {
V_18 = V_17 + strlen ( V_17 ) ;
sprintf ( V_18 , L_8 , V_9 -> V_32 ) ;
}
V_18 = V_17 + strlen ( V_17 ) ;
sprintf ( V_18 , L_9 , V_46 -> V_47 ) ;
F_8 ( 1 , L_10 , V_17 ) ;
V_20 = F_9 ( & V_48 , V_17 , L_11 ) ;
#ifdef F_10
if ( V_49 && ! F_11 ( V_20 ) ) {
struct V_50 * V_51 = V_20 -> V_4 . V_2 ;
F_12 ( L_12 , V_51 -> V_2 , F_13 ( 1024U ,
V_51 -> V_52 + V_51 -> V_53 ) ) ;
}
#endif
V_34:
F_4 ( V_17 ) ;
return V_20 ;
}
