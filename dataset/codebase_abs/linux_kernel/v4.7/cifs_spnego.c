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
const struct V_24 * V_25 ;
V_21 = V_26 +
V_27 + strlen ( V_23 ) +
V_28 + V_29 +
V_30 +
V_31 + ( sizeof( V_32 ) * 2 ) +
V_33 + ( sizeof( V_32 ) * 2 ) +
V_34 + ( sizeof( V_35 ) * 2 ) + 1 ;
if ( V_11 -> V_36 )
V_21 += V_37 + strlen ( V_11 -> V_36 ) ;
V_22 = F_6 ( - V_6 ) ;
V_19 = F_7 ( V_21 , V_9 ) ;
if ( V_19 == NULL )
goto V_38;
V_20 = V_19 ;
V_22 = F_6 ( - V_39 ) ;
sprintf ( V_20 , L_1 , V_40 ,
V_23 ) ;
V_20 = V_19 + strlen ( V_19 ) ;
if ( V_13 -> V_16 . V_41 == V_42 )
sprintf ( V_20 , L_2 , & V_15 -> V_43 ) ;
else if ( V_13 -> V_16 . V_41 == V_44 )
sprintf ( V_20 , L_3 , & V_18 -> V_45 ) ;
else
goto V_38;
V_20 = V_19 + strlen ( V_19 ) ;
if ( V_13 -> V_46 )
sprintf ( V_20 , L_4 ) ;
else if ( V_13 -> V_47 )
sprintf ( V_20 , L_5 ) ;
else
goto V_38;
V_20 = V_19 + strlen ( V_19 ) ;
sprintf ( V_20 , L_6 ,
F_8 ( & V_48 , V_11 -> V_49 ) ) ;
V_20 = V_19 + strlen ( V_19 ) ;
sprintf ( V_20 , L_7 ,
F_8 ( & V_48 , V_11 -> V_50 ) ) ;
if ( V_11 -> V_36 ) {
V_20 = V_19 + strlen ( V_19 ) ;
sprintf ( V_20 , L_8 , V_11 -> V_36 ) ;
}
V_20 = V_19 + strlen ( V_19 ) ;
sprintf ( V_20 , L_9 , V_51 -> V_52 ) ;
F_9 ( V_53 , L_10 , V_19 ) ;
V_25 = F_10 ( V_54 ) ;
V_22 = F_11 ( & V_55 , V_19 , L_11 ) ;
F_12 ( V_25 ) ;
#ifdef F_13
if ( V_56 && ! F_14 ( V_22 ) ) {
struct V_57 * V_58 = V_22 -> V_4 . V_7 [ 0 ] ;
F_15 ( L_12 , V_58 -> V_7 , F_16 ( 1024U ,
V_58 -> V_59 + V_58 -> V_60 ) ) ;
}
#endif
V_38:
F_4 ( V_19 ) ;
return V_22 ;
}
int
F_17 ( void )
{
struct V_24 * V_24 ;
struct V_1 * V_61 ;
int V_5 ;
F_9 ( V_53 , L_13 ,
V_55 . V_62 ) ;
V_24 = F_18 ( NULL ) ;
if ( ! V_24 )
return - V_6 ;
V_61 = F_19 ( L_14 ,
V_63 , V_64 , V_24 ,
( V_65 & ~ V_66 ) |
V_67 | V_68 ,
V_69 , NULL , NULL ) ;
if ( F_14 ( V_61 ) ) {
V_5 = F_20 ( V_61 ) ;
goto V_70;
}
V_5 = F_21 ( & V_55 ) ;
if ( V_5 < 0 )
goto V_71;
F_22 ( V_72 , & V_61 -> V_73 ) ;
V_24 -> V_74 = V_61 ;
V_24 -> V_75 = V_76 ;
V_54 = V_24 ;
F_9 ( V_53 , L_15 , F_23 ( V_61 ) ) ;
return 0 ;
V_71:
F_24 ( V_61 ) ;
V_70:
F_25 ( V_24 ) ;
return V_5 ;
}
void
F_26 ( void )
{
F_27 ( V_54 -> V_74 ) ;
F_28 ( & V_55 ) ;
F_25 ( V_54 ) ;
F_9 ( V_53 , L_16 , V_55 . V_62 ) ;
}
