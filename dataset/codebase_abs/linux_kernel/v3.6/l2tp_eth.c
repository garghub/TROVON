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
unsigned int V_16 = V_13 -> V_16 ;
int V_17 = F_13 ( V_15 , V_13 , V_15 -> V_18 ) ;
if ( F_14 ( V_17 == V_19 ) ) {
F_15 ( V_16 , & V_7 -> V_20 ) ;
F_16 ( & V_7 -> V_21 ) ;
} else {
F_16 ( & V_7 -> V_22 ) ;
}
return V_23 ;
}
static struct V_24 * F_17 ( struct V_4 * V_5 ,
struct V_24 * V_25 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
V_25 -> V_20 = F_18 ( & V_7 -> V_20 ) ;
V_25 -> V_21 = F_18 ( & V_7 -> V_21 ) ;
V_25 -> V_22 = F_18 ( & V_7 -> V_22 ) ;
V_25 -> V_26 = F_18 ( & V_7 -> V_26 ) ;
V_25 -> V_27 = F_18 ( & V_7 -> V_27 ) ;
V_25 -> V_28 = F_18 ( & V_7 -> V_28 ) ;
return V_25 ;
}
static void F_19 ( struct V_4 * V_5 )
{
F_20 ( V_5 ) ;
V_5 -> V_29 &= ~ V_30 ;
V_5 -> V_31 |= V_32 ;
V_5 -> V_33 = & V_34 ;
V_5 -> V_35 = V_36 ;
}
static void F_21 ( struct V_14 * V_15 , struct V_12 * V_13 , int V_37 )
{
struct V_38 * V_39 = F_22 ( V_15 ) ;
struct V_4 * V_5 = V_39 -> V_5 ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
if ( V_15 -> V_40 & V_41 ) {
unsigned int V_42 ;
V_42 = F_23 ( 32u , V_13 -> V_16 ) ;
if ( ! F_24 ( V_13 , V_42 ) )
goto error;
F_25 ( L_1 , V_15 -> V_43 ) ;
F_26 ( L_2 , V_44 , V_13 -> V_45 , V_42 ) ;
}
if ( ! F_24 ( V_13 , V_46 ) )
goto error;
F_27 ( V_13 ) ;
V_13 -> V_47 = V_48 ;
F_28 ( V_13 ) ;
F_29 ( V_13 ) ;
if ( F_30 ( V_5 , V_13 ) == V_49 ) {
F_16 ( & V_7 -> V_27 ) ;
F_15 ( V_37 , & V_7 -> V_26 ) ;
} else {
F_16 ( & V_7 -> V_28 ) ;
}
return;
error:
F_16 ( & V_7 -> V_28 ) ;
F_31 ( V_13 ) ;
}
static void F_32 ( struct V_14 * V_15 )
{
struct V_38 * V_39 ;
struct V_4 * V_5 ;
if ( V_15 ) {
V_39 = F_22 ( V_15 ) ;
V_5 = V_39 -> V_5 ;
if ( V_5 ) {
F_33 ( V_5 ) ;
V_39 -> V_5 = NULL ;
F_34 ( V_50 ) ;
}
}
}
static void F_35 ( struct V_51 * V_52 , void * V_53 )
{
struct V_14 * V_15 = V_53 ;
struct V_38 * V_39 = F_22 ( V_15 ) ;
struct V_4 * V_5 = V_39 -> V_5 ;
F_36 ( V_52 , L_3 , V_5 -> V_43 ) ;
}
static int F_37 ( struct V_2 * V_2 , T_1 V_54 , T_1 V_55 , T_1 V_56 , struct V_57 * V_58 )
{
struct V_4 * V_5 ;
char V_43 [ V_59 ] ;
struct V_60 * V_61 ;
struct V_14 * V_15 ;
struct V_6 * V_7 ;
struct V_38 * V_39 ;
int V_62 ;
struct V_1 * V_9 ;
V_61 = F_38 ( V_2 , V_54 ) ;
if ( ! V_61 ) {
V_62 = - V_63 ;
goto V_64;
}
V_15 = F_39 ( V_2 , V_61 , V_55 ) ;
if ( V_15 ) {
V_62 = - V_65 ;
goto V_64;
}
if ( V_58 -> V_66 ) {
V_5 = F_40 ( V_2 , V_58 -> V_66 ) ;
if ( V_5 ) {
F_11 ( V_5 ) ;
V_62 = - V_65 ;
goto V_64;
}
F_41 ( V_43 , V_58 -> V_66 , V_59 ) ;
} else
strcpy ( V_43 , V_67 ) ;
V_15 = F_42 ( sizeof( * V_39 ) , V_61 , V_55 ,
V_56 , V_58 ) ;
if ( ! V_15 ) {
V_62 = - V_68 ;
goto V_64;
}
V_5 = F_43 ( sizeof( * V_7 ) , V_43 , F_19 ) ;
if ( ! V_5 ) {
V_62 = - V_68 ;
goto V_69;
}
F_44 ( V_5 , V_2 ) ;
if ( V_15 -> V_70 == 0 )
V_15 -> V_70 = V_5 -> V_70 - V_15 -> V_18 ;
V_5 -> V_70 = V_15 -> V_70 ;
V_5 -> V_71 += V_15 -> V_18 ;
V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_15 = V_15 ;
F_45 ( & V_7 -> V_11 ) ;
V_7 -> V_72 = V_61 -> V_73 ;
V_15 -> V_74 = F_21 ;
V_15 -> V_75 = F_32 ;
#if F_46 ( V_76 ) || F_46 ( V_77 )
V_15 -> V_78 = F_35 ;
#endif
V_39 = F_22 ( V_15 ) ;
V_39 -> V_5 = V_5 ;
V_62 = F_47 ( V_5 ) ;
if ( V_62 < 0 )
goto V_79;
F_48 ( V_50 ) ;
F_41 ( V_15 -> V_66 , V_5 -> V_43 , V_59 ) ;
F_49 ( V_5 ) ;
V_9 = F_1 ( F_7 ( V_5 ) ) ;
F_8 ( & V_9 -> V_10 ) ;
F_50 ( & V_7 -> V_11 , & V_9 -> V_80 ) ;
F_10 ( & V_9 -> V_10 ) ;
return 0 ;
V_79:
V_36 ( V_5 ) ;
V_69:
F_51 ( V_15 ) ;
V_64:
return V_62 ;
}
static T_2 int F_52 ( struct V_2 * V_2 )
{
struct V_1 * V_9 = F_2 ( V_2 , V_3 ) ;
F_45 ( & V_9 -> V_80 ) ;
F_53 ( & V_9 -> V_10 ) ;
return 0 ;
}
static int T_3 F_54 ( void )
{
int V_81 = 0 ;
V_81 = F_55 ( V_82 , & V_83 ) ;
if ( V_81 )
goto V_64;
V_81 = F_56 ( & V_84 ) ;
if ( V_81 )
goto V_85;
F_57 ( L_4 ) ;
return 0 ;
V_85:
F_58 ( V_82 ) ;
V_64:
return V_81 ;
}
static void T_4 F_59 ( void )
{
F_60 ( & V_84 ) ;
F_58 ( V_82 ) ;
}
