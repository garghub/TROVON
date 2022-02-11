static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
F_5 ( V_5 -> V_8 ) ;
memset ( & V_5 -> V_9 [ 0 ] , 0xff , 6 ) ;
return 0 ;
}
static void F_6 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_1 * V_10 = F_1 ( F_7 ( V_5 ) ) ;
F_8 ( & V_10 -> V_11 ) ;
F_9 ( & V_7 -> V_12 ) ;
F_10 ( & V_10 -> V_11 ) ;
F_11 ( V_5 ) ;
}
static int F_12 ( struct V_13 * V_14 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_15 * V_16 = V_7 -> V_16 ;
F_13 ( V_16 , V_14 , V_16 -> V_17 ) ;
V_5 -> V_18 . V_19 += V_14 -> V_20 ;
V_5 -> V_18 . V_21 ++ ;
return 0 ;
}
static void F_14 ( struct V_4 * V_5 )
{
F_15 ( V_5 ) ;
V_5 -> V_22 &= ~ V_23 ;
V_5 -> V_24 = & V_25 ;
V_5 -> V_26 = V_27 ;
}
static void F_16 ( struct V_15 * V_16 , struct V_13 * V_14 , int V_28 )
{
struct V_29 * V_30 = F_17 ( V_16 ) ;
struct V_4 * V_5 = V_30 -> V_5 ;
if ( V_16 -> V_31 & V_32 ) {
unsigned int V_33 ;
int V_34 ;
T_1 * V_35 = V_14 -> V_36 ;
V_33 = F_18 ( 32u , V_14 -> V_20 ) ;
if ( ! F_19 ( V_14 , V_33 ) )
goto error;
F_20 ( V_37 L_1 , V_16 -> V_38 ) ;
V_34 = 0 ;
do {
F_20 ( L_2 , V_35 [ V_34 ] ) ;
} while ( ++ V_34 < V_33 );
F_20 ( L_3 ) ;
}
if ( ! F_19 ( V_14 , sizeof( V_39 ) ) )
goto error;
F_21 ( V_14 ) ;
V_14 -> V_40 = V_41 ;
F_22 ( V_14 ) ;
F_23 ( V_14 ) ;
if ( F_24 ( V_5 , V_14 ) == V_42 ) {
V_5 -> V_18 . V_43 ++ ;
V_5 -> V_18 . V_44 += V_28 ;
} else
V_5 -> V_18 . V_45 ++ ;
return;
error:
V_5 -> V_18 . V_45 ++ ;
F_25 ( V_14 ) ;
}
static void F_26 ( struct V_15 * V_16 )
{
struct V_29 * V_30 ;
struct V_4 * V_5 ;
if ( V_16 ) {
V_30 = F_17 ( V_16 ) ;
V_5 = V_30 -> V_5 ;
if ( V_5 ) {
F_27 ( V_5 ) ;
V_30 -> V_5 = NULL ;
}
}
}
static void F_28 ( struct V_46 * V_47 , void * V_48 )
{
struct V_15 * V_16 = V_48 ;
struct V_29 * V_30 = F_17 ( V_16 ) ;
struct V_4 * V_5 = V_30 -> V_5 ;
F_29 ( V_47 , L_4 , V_5 -> V_38 ) ;
}
static int F_30 ( struct V_2 * V_2 , T_2 V_49 , T_2 V_50 , T_2 V_51 , struct V_52 * V_53 )
{
struct V_4 * V_5 ;
char V_38 [ V_54 ] ;
struct V_55 * V_56 ;
struct V_15 * V_16 ;
struct V_6 * V_7 ;
struct V_29 * V_30 ;
int V_57 ;
struct V_1 * V_10 ;
V_56 = F_31 ( V_2 , V_49 ) ;
if ( ! V_56 ) {
V_57 = - V_58 ;
goto V_59;
}
V_16 = F_32 ( V_2 , V_56 , V_50 ) ;
if ( V_16 ) {
V_57 = - V_60 ;
goto V_59;
}
if ( V_53 -> V_61 ) {
V_5 = F_33 ( V_2 , V_53 -> V_61 ) ;
if ( V_5 ) {
F_11 ( V_5 ) ;
V_57 = - V_60 ;
goto V_59;
}
F_34 ( V_38 , V_53 -> V_61 , V_54 ) ;
} else
strcpy ( V_38 , V_62 ) ;
V_16 = F_35 ( sizeof( * V_30 ) , V_56 , V_50 ,
V_51 , V_53 ) ;
if ( ! V_16 ) {
V_57 = - V_63 ;
goto V_59;
}
V_5 = F_36 ( sizeof( * V_7 ) , V_38 , F_14 ) ;
if ( ! V_5 ) {
V_57 = - V_63 ;
goto V_64;
}
F_37 ( V_5 , V_2 ) ;
if ( V_16 -> V_65 == 0 )
V_16 -> V_65 = V_5 -> V_65 - V_16 -> V_17 ;
V_5 -> V_65 = V_16 -> V_65 ;
V_5 -> V_66 += V_16 -> V_17 ;
V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_16 = V_16 ;
F_38 ( & V_7 -> V_12 ) ;
V_7 -> V_67 = V_56 -> V_68 ;
V_16 -> V_69 = F_16 ;
V_16 -> V_70 = F_26 ;
#if F_39 ( V_71 ) || F_39 ( V_72 )
V_16 -> V_73 = F_28 ;
#endif
V_30 = F_17 ( V_16 ) ;
V_30 -> V_5 = V_5 ;
V_57 = F_40 ( V_5 ) ;
if ( V_57 < 0 )
goto V_74;
F_34 ( V_16 -> V_61 , V_5 -> V_38 , V_54 ) ;
F_41 ( V_5 ) ;
V_10 = F_1 ( F_7 ( V_5 ) ) ;
F_8 ( & V_10 -> V_11 ) ;
F_42 ( & V_7 -> V_12 , & V_10 -> V_75 ) ;
F_10 ( & V_10 -> V_11 ) ;
return 0 ;
V_74:
V_27 ( V_5 ) ;
V_64:
F_43 ( V_16 ) ;
V_59:
return V_57 ;
}
static T_3 int F_44 ( struct V_2 * V_2 )
{
struct V_1 * V_10 = F_2 ( V_2 , V_3 ) ;
F_38 ( & V_10 -> V_75 ) ;
F_45 ( & V_10 -> V_11 ) ;
return 0 ;
}
static int T_4 F_46 ( void )
{
int V_76 = 0 ;
V_76 = F_47 ( V_77 , & V_78 ) ;
if ( V_76 )
goto V_59;
V_76 = F_48 ( & V_79 ) ;
if ( V_76 )
goto V_80;
F_20 ( V_81 L_5 ) ;
return 0 ;
V_80:
F_49 ( V_77 ) ;
V_59:
return V_76 ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_79 ) ;
F_49 ( V_77 ) ;
}
