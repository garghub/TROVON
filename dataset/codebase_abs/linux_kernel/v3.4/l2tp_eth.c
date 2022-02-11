static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
F_5 ( V_5 ) ;
memset ( & V_5 -> V_8 [ 0 ] , 0xff , 6 ) ;
return 0 ;
}
static void F_6 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_1 * V_9 = F_1 ( F_7 ( V_5 ) ) ;
F_8 ( & V_9 -> V_10 ) ;
F_9 ( & V_7 -> V_11 ) ;
F_10 ( & V_9 -> V_10 ) ;
F_11 ( V_5 ) ;
}
static int F_12 ( struct V_12 * V_13 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_14 * V_15 = V_7 -> V_15 ;
F_13 ( V_15 , V_13 , V_15 -> V_16 ) ;
V_5 -> V_17 . V_18 += V_13 -> V_19 ;
V_5 -> V_17 . V_20 ++ ;
return 0 ;
}
static void F_14 ( struct V_4 * V_5 )
{
F_15 ( V_5 ) ;
V_5 -> V_21 &= ~ V_22 ;
V_5 -> V_23 = & V_24 ;
V_5 -> V_25 = V_26 ;
}
static void F_16 ( struct V_14 * V_15 , struct V_12 * V_13 , int V_27 )
{
struct V_28 * V_29 = F_17 ( V_15 ) ;
struct V_4 * V_5 = V_29 -> V_5 ;
if ( V_15 -> V_30 & V_31 ) {
unsigned int V_32 ;
int V_33 ;
T_1 * V_34 = V_13 -> V_35 ;
V_32 = F_18 ( 32u , V_13 -> V_19 ) ;
if ( ! F_19 ( V_13 , V_32 ) )
goto error;
F_20 ( V_36 L_1 , V_15 -> V_37 ) ;
V_33 = 0 ;
do {
F_20 ( L_2 , V_34 [ V_33 ] ) ;
} while ( ++ V_33 < V_32 );
F_20 ( L_3 ) ;
}
if ( ! F_19 ( V_13 , sizeof( V_38 ) ) )
goto error;
F_21 ( V_13 ) ;
V_13 -> V_39 = V_40 ;
F_22 ( V_13 ) ;
F_23 ( V_13 ) ;
if ( F_24 ( V_5 , V_13 ) == V_41 ) {
V_5 -> V_17 . V_42 ++ ;
V_5 -> V_17 . V_43 += V_27 ;
} else
V_5 -> V_17 . V_44 ++ ;
return;
error:
V_5 -> V_17 . V_44 ++ ;
F_25 ( V_13 ) ;
}
static void F_26 ( struct V_14 * V_15 )
{
struct V_28 * V_29 ;
struct V_4 * V_5 ;
if ( V_15 ) {
V_29 = F_17 ( V_15 ) ;
V_5 = V_29 -> V_5 ;
if ( V_5 ) {
F_27 ( V_5 ) ;
V_29 -> V_5 = NULL ;
}
}
}
static void F_28 ( struct V_45 * V_46 , void * V_47 )
{
struct V_14 * V_15 = V_47 ;
struct V_28 * V_29 = F_17 ( V_15 ) ;
struct V_4 * V_5 = V_29 -> V_5 ;
F_29 ( V_46 , L_4 , V_5 -> V_37 ) ;
}
static int F_30 ( struct V_2 * V_2 , T_2 V_48 , T_2 V_49 , T_2 V_50 , struct V_51 * V_52 )
{
struct V_4 * V_5 ;
char V_37 [ V_53 ] ;
struct V_54 * V_55 ;
struct V_14 * V_15 ;
struct V_6 * V_7 ;
struct V_28 * V_29 ;
int V_56 ;
struct V_1 * V_9 ;
V_55 = F_31 ( V_2 , V_48 ) ;
if ( ! V_55 ) {
V_56 = - V_57 ;
goto V_58;
}
V_15 = F_32 ( V_2 , V_55 , V_49 ) ;
if ( V_15 ) {
V_56 = - V_59 ;
goto V_58;
}
if ( V_52 -> V_60 ) {
V_5 = F_33 ( V_2 , V_52 -> V_60 ) ;
if ( V_5 ) {
F_11 ( V_5 ) ;
V_56 = - V_59 ;
goto V_58;
}
F_34 ( V_37 , V_52 -> V_60 , V_53 ) ;
} else
strcpy ( V_37 , V_61 ) ;
V_15 = F_35 ( sizeof( * V_29 ) , V_55 , V_49 ,
V_50 , V_52 ) ;
if ( ! V_15 ) {
V_56 = - V_62 ;
goto V_58;
}
V_5 = F_36 ( sizeof( * V_7 ) , V_37 , F_14 ) ;
if ( ! V_5 ) {
V_56 = - V_62 ;
goto V_63;
}
F_37 ( V_5 , V_2 ) ;
if ( V_15 -> V_64 == 0 )
V_15 -> V_64 = V_5 -> V_64 - V_15 -> V_16 ;
V_5 -> V_64 = V_15 -> V_64 ;
V_5 -> V_65 += V_15 -> V_16 ;
V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_15 = V_15 ;
F_38 ( & V_7 -> V_11 ) ;
V_7 -> V_66 = V_55 -> V_67 ;
V_15 -> V_68 = F_16 ;
V_15 -> V_69 = F_26 ;
#if F_39 ( V_70 ) || F_39 ( V_71 )
V_15 -> V_72 = F_28 ;
#endif
V_29 = F_17 ( V_15 ) ;
V_29 -> V_5 = V_5 ;
V_56 = F_40 ( V_5 ) ;
if ( V_56 < 0 )
goto V_73;
F_34 ( V_15 -> V_60 , V_5 -> V_37 , V_53 ) ;
F_41 ( V_5 ) ;
V_9 = F_1 ( F_7 ( V_5 ) ) ;
F_8 ( & V_9 -> V_10 ) ;
F_42 ( & V_7 -> V_11 , & V_9 -> V_74 ) ;
F_10 ( & V_9 -> V_10 ) ;
return 0 ;
V_73:
V_26 ( V_5 ) ;
V_63:
F_43 ( V_15 ) ;
V_58:
return V_56 ;
}
static T_3 int F_44 ( struct V_2 * V_2 )
{
struct V_1 * V_9 = F_2 ( V_2 , V_3 ) ;
F_38 ( & V_9 -> V_74 ) ;
F_45 ( & V_9 -> V_10 ) ;
return 0 ;
}
static int T_4 F_46 ( void )
{
int V_75 = 0 ;
V_75 = F_47 ( V_76 , & V_77 ) ;
if ( V_75 )
goto V_58;
V_75 = F_48 ( & V_78 ) ;
if ( V_75 )
goto V_79;
F_20 ( V_80 L_5 ) ;
return 0 ;
V_79:
F_49 ( V_76 ) ;
V_58:
return V_75 ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_78 ) ;
F_49 ( V_76 ) ;
}
