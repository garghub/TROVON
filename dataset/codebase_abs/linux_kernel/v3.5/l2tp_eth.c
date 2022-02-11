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
F_13 ( V_13 -> V_16 , & V_7 -> V_17 ) ;
F_14 ( & V_7 -> V_18 ) ;
F_15 ( V_15 , V_13 , V_15 -> V_19 ) ;
return V_20 ;
}
static struct V_21 * F_16 ( struct V_4 * V_5 ,
struct V_21 * V_22 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
V_22 -> V_17 = F_17 ( & V_7 -> V_17 ) ;
V_22 -> V_18 = F_17 ( & V_7 -> V_18 ) ;
V_22 -> V_23 = F_17 ( & V_7 -> V_23 ) ;
V_22 -> V_24 = F_17 ( & V_7 -> V_24 ) ;
V_22 -> V_25 = F_17 ( & V_7 -> V_25 ) ;
return V_22 ;
}
static void F_18 ( struct V_4 * V_5 )
{
F_19 ( V_5 ) ;
V_5 -> V_26 &= ~ V_27 ;
V_5 -> V_28 |= V_29 ;
V_5 -> V_30 = & V_31 ;
V_5 -> V_32 = V_33 ;
}
static void F_20 ( struct V_14 * V_15 , struct V_12 * V_13 , int V_34 )
{
struct V_35 * V_36 = F_21 ( V_15 ) ;
struct V_4 * V_5 = V_36 -> V_5 ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
if ( V_15 -> V_37 & V_38 ) {
unsigned int V_39 ;
V_39 = F_22 ( 32u , V_13 -> V_16 ) ;
if ( ! F_23 ( V_13 , V_39 ) )
goto error;
F_24 ( L_1 , V_15 -> V_40 ) ;
F_25 ( L_2 , V_41 , V_13 -> V_42 , V_39 ) ;
}
if ( ! F_23 ( V_13 , sizeof( V_43 ) ) )
goto error;
F_26 ( V_13 ) ;
V_13 -> V_44 = V_45 ;
F_27 ( V_13 ) ;
F_28 ( V_13 ) ;
if ( F_29 ( V_5 , V_13 ) == V_46 ) {
F_14 ( & V_7 -> V_24 ) ;
F_13 ( V_34 , & V_7 -> V_23 ) ;
} else {
F_14 ( & V_7 -> V_25 ) ;
}
return;
error:
F_14 ( & V_7 -> V_25 ) ;
F_30 ( V_13 ) ;
}
static void F_31 ( struct V_14 * V_15 )
{
struct V_35 * V_36 ;
struct V_4 * V_5 ;
if ( V_15 ) {
V_36 = F_21 ( V_15 ) ;
V_5 = V_36 -> V_5 ;
if ( V_5 ) {
F_32 ( V_5 ) ;
V_36 -> V_5 = NULL ;
F_33 ( V_47 ) ;
}
}
}
static void F_34 ( struct V_48 * V_49 , void * V_50 )
{
struct V_14 * V_15 = V_50 ;
struct V_35 * V_36 = F_21 ( V_15 ) ;
struct V_4 * V_5 = V_36 -> V_5 ;
F_35 ( V_49 , L_3 , V_5 -> V_40 ) ;
}
static int F_36 ( struct V_2 * V_2 , T_1 V_51 , T_1 V_52 , T_1 V_53 , struct V_54 * V_55 )
{
struct V_4 * V_5 ;
char V_40 [ V_56 ] ;
struct V_57 * V_58 ;
struct V_14 * V_15 ;
struct V_6 * V_7 ;
struct V_35 * V_36 ;
int V_59 ;
struct V_1 * V_9 ;
V_58 = F_37 ( V_2 , V_51 ) ;
if ( ! V_58 ) {
V_59 = - V_60 ;
goto V_61;
}
V_15 = F_38 ( V_2 , V_58 , V_52 ) ;
if ( V_15 ) {
V_59 = - V_62 ;
goto V_61;
}
if ( V_55 -> V_63 ) {
V_5 = F_39 ( V_2 , V_55 -> V_63 ) ;
if ( V_5 ) {
F_11 ( V_5 ) ;
V_59 = - V_62 ;
goto V_61;
}
F_40 ( V_40 , V_55 -> V_63 , V_56 ) ;
} else
strcpy ( V_40 , V_64 ) ;
V_15 = F_41 ( sizeof( * V_36 ) , V_58 , V_52 ,
V_53 , V_55 ) ;
if ( ! V_15 ) {
V_59 = - V_65 ;
goto V_61;
}
V_5 = F_42 ( sizeof( * V_7 ) , V_40 , F_18 ) ;
if ( ! V_5 ) {
V_59 = - V_65 ;
goto V_66;
}
F_43 ( V_5 , V_2 ) ;
if ( V_15 -> V_67 == 0 )
V_15 -> V_67 = V_5 -> V_67 - V_15 -> V_19 ;
V_5 -> V_67 = V_15 -> V_67 ;
V_5 -> V_68 += V_15 -> V_19 ;
V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_15 = V_15 ;
F_44 ( & V_7 -> V_11 ) ;
V_7 -> V_69 = V_58 -> V_70 ;
V_15 -> V_71 = F_20 ;
V_15 -> V_72 = F_31 ;
#if F_45 ( V_73 ) || F_45 ( V_74 )
V_15 -> V_75 = F_34 ;
#endif
V_36 = F_21 ( V_15 ) ;
V_36 -> V_5 = V_5 ;
V_59 = F_46 ( V_5 ) ;
if ( V_59 < 0 )
goto V_76;
F_47 ( V_47 ) ;
F_40 ( V_15 -> V_63 , V_5 -> V_40 , V_56 ) ;
F_48 ( V_5 ) ;
V_9 = F_1 ( F_7 ( V_5 ) ) ;
F_8 ( & V_9 -> V_10 ) ;
F_49 ( & V_7 -> V_11 , & V_9 -> V_77 ) ;
F_10 ( & V_9 -> V_10 ) ;
return 0 ;
V_76:
V_33 ( V_5 ) ;
V_66:
F_50 ( V_15 ) ;
V_61:
return V_59 ;
}
static T_2 int F_51 ( struct V_2 * V_2 )
{
struct V_1 * V_9 = F_2 ( V_2 , V_3 ) ;
F_44 ( & V_9 -> V_77 ) ;
F_52 ( & V_9 -> V_10 ) ;
return 0 ;
}
static int T_3 F_53 ( void )
{
int V_78 = 0 ;
V_78 = F_54 ( V_79 , & V_80 ) ;
if ( V_78 )
goto V_61;
V_78 = F_55 ( & V_81 ) ;
if ( V_78 )
goto V_82;
F_56 ( L_4 ) ;
return 0 ;
V_82:
F_57 ( V_79 ) ;
V_61:
return V_78 ;
}
static void T_4 F_58 ( void )
{
F_59 ( & V_81 ) ;
F_57 ( V_79 ) ;
}
