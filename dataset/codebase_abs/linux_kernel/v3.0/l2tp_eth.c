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
V_5 -> V_22 = & V_23 ;
V_5 -> V_24 = V_25 ;
}
static void F_16 ( struct V_15 * V_16 , struct V_13 * V_14 , int V_26 )
{
struct V_27 * V_28 = F_17 ( V_16 ) ;
struct V_4 * V_5 = V_28 -> V_5 ;
if ( V_16 -> V_29 & V_30 ) {
unsigned int V_31 ;
int V_32 ;
T_1 * V_33 = V_14 -> V_34 ;
V_31 = F_18 ( 32u , V_14 -> V_20 ) ;
if ( ! F_19 ( V_14 , V_31 ) )
goto error;
F_20 ( V_35 L_1 , V_16 -> V_36 ) ;
V_32 = 0 ;
do {
F_20 ( L_2 , V_33 [ V_32 ] ) ;
} while ( ++ V_32 < V_31 );
F_20 ( L_3 ) ;
}
if ( ! F_19 ( V_14 , sizeof( V_37 ) ) )
goto error;
F_21 ( V_14 ) ;
V_14 -> V_38 = V_39 ;
F_22 ( V_14 ) ;
F_23 ( V_14 ) ;
if ( F_24 ( V_5 , V_14 ) == V_40 ) {
V_5 -> V_18 . V_41 ++ ;
V_5 -> V_18 . V_42 += V_26 ;
} else
V_5 -> V_18 . V_43 ++ ;
return;
error:
V_5 -> V_18 . V_43 ++ ;
F_25 ( V_14 ) ;
}
static void F_26 ( struct V_15 * V_16 )
{
struct V_27 * V_28 ;
struct V_4 * V_5 ;
if ( V_16 ) {
V_28 = F_17 ( V_16 ) ;
V_5 = V_28 -> V_5 ;
if ( V_5 ) {
F_27 ( V_5 ) ;
V_28 -> V_5 = NULL ;
}
}
}
static void F_28 ( struct V_44 * V_45 , void * V_46 )
{
struct V_15 * V_16 = V_46 ;
struct V_27 * V_28 = F_17 ( V_16 ) ;
struct V_4 * V_5 = V_28 -> V_5 ;
F_29 ( V_45 , L_4 , V_5 -> V_36 ) ;
}
static int F_30 ( struct V_2 * V_2 , T_2 V_47 , T_2 V_48 , T_2 V_49 , struct V_50 * V_51 )
{
struct V_4 * V_5 ;
char V_36 [ V_52 ] ;
struct V_53 * V_54 ;
struct V_15 * V_16 ;
struct V_6 * V_7 ;
struct V_27 * V_28 ;
int V_55 ;
struct V_1 * V_10 ;
V_54 = F_31 ( V_2 , V_47 ) ;
if ( ! V_54 ) {
V_55 = - V_56 ;
goto V_57;
}
V_16 = F_32 ( V_2 , V_54 , V_48 ) ;
if ( V_16 ) {
V_55 = - V_58 ;
goto V_57;
}
if ( V_51 -> V_59 ) {
V_5 = F_33 ( V_2 , V_51 -> V_59 ) ;
if ( V_5 ) {
F_11 ( V_5 ) ;
V_55 = - V_58 ;
goto V_57;
}
F_34 ( V_36 , V_51 -> V_59 , V_52 ) ;
} else
strcpy ( V_36 , V_60 ) ;
V_16 = F_35 ( sizeof( * V_28 ) , V_54 , V_48 ,
V_49 , V_51 ) ;
if ( ! V_16 ) {
V_55 = - V_61 ;
goto V_57;
}
V_5 = F_36 ( sizeof( * V_7 ) , V_36 , F_14 ) ;
if ( ! V_5 ) {
V_55 = - V_61 ;
goto V_62;
}
F_37 ( V_5 , V_2 ) ;
if ( V_16 -> V_63 == 0 )
V_16 -> V_63 = V_5 -> V_63 - V_16 -> V_17 ;
V_5 -> V_63 = V_16 -> V_63 ;
V_5 -> V_64 += V_16 -> V_17 ;
V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_16 = V_16 ;
F_38 ( & V_7 -> V_12 ) ;
V_7 -> V_65 = V_54 -> V_66 ;
V_16 -> V_67 = F_16 ;
V_16 -> V_68 = F_26 ;
#if F_39 ( V_69 ) || F_39 ( V_70 )
V_16 -> V_71 = F_28 ;
#endif
V_28 = F_17 ( V_16 ) ;
V_28 -> V_5 = V_5 ;
V_55 = F_40 ( V_5 ) ;
if ( V_55 < 0 )
goto V_72;
F_34 ( V_16 -> V_59 , V_5 -> V_36 , V_52 ) ;
F_41 ( V_5 ) ;
V_10 = F_1 ( F_7 ( V_5 ) ) ;
F_8 ( & V_10 -> V_11 ) ;
F_42 ( & V_7 -> V_12 , & V_10 -> V_73 ) ;
F_10 ( & V_10 -> V_11 ) ;
return 0 ;
V_72:
V_25 ( V_5 ) ;
V_62:
F_43 ( V_16 ) ;
V_57:
return V_55 ;
}
static T_3 int F_44 ( struct V_2 * V_2 )
{
struct V_1 * V_10 = F_2 ( V_2 , V_3 ) ;
F_38 ( & V_10 -> V_73 ) ;
F_45 ( & V_10 -> V_11 ) ;
return 0 ;
}
static int T_4 F_46 ( void )
{
int V_74 = 0 ;
V_74 = F_47 ( V_75 , & V_76 ) ;
if ( V_74 )
goto V_57;
V_74 = F_48 ( & V_77 ) ;
if ( V_74 )
goto V_78;
F_20 ( V_79 L_5 ) ;
return 0 ;
V_78:
F_49 ( V_75 ) ;
V_57:
return V_74 ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_77 ) ;
F_49 ( V_75 ) ;
}
