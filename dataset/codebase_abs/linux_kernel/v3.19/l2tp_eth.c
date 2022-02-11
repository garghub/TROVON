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
V_5 -> V_9 = & V_10 ;
return 0 ;
}
static void F_6 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_1 * V_11 = F_1 ( F_7 ( V_5 ) ) ;
F_8 ( & V_11 -> V_12 ) ;
F_9 ( & V_7 -> V_13 ) ;
F_10 ( & V_11 -> V_12 ) ;
F_11 ( V_5 ) ;
}
static int F_12 ( struct V_14 * V_15 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_16 * V_17 = V_7 -> V_17 ;
unsigned int V_18 = V_15 -> V_18 ;
int V_19 = F_13 ( V_17 , V_15 , V_17 -> V_20 ) ;
if ( F_14 ( V_19 == V_21 ) ) {
F_15 ( V_18 , & V_7 -> V_22 ) ;
F_16 ( & V_7 -> V_23 ) ;
} else {
F_16 ( & V_7 -> V_24 ) ;
}
return V_25 ;
}
static struct V_26 * F_17 ( struct V_4 * V_5 ,
struct V_26 * V_27 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
V_27 -> V_22 = F_18 ( & V_7 -> V_22 ) ;
V_27 -> V_23 = F_18 ( & V_7 -> V_23 ) ;
V_27 -> V_24 = F_18 ( & V_7 -> V_24 ) ;
V_27 -> V_28 = F_18 ( & V_7 -> V_28 ) ;
V_27 -> V_29 = F_18 ( & V_7 -> V_29 ) ;
V_27 -> V_30 = F_18 ( & V_7 -> V_30 ) ;
return V_27 ;
}
static void F_19 ( struct V_4 * V_5 )
{
F_20 ( V_5 ) ;
V_5 -> V_31 &= ~ V_32 ;
V_5 -> V_33 |= V_34 ;
V_5 -> V_35 = & V_36 ;
V_5 -> V_37 = V_38 ;
}
static void F_21 ( struct V_16 * V_17 , struct V_14 * V_15 , int V_39 )
{
struct V_40 * V_41 = F_22 ( V_17 ) ;
struct V_4 * V_5 = V_41 -> V_5 ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
if ( V_17 -> V_42 & V_43 ) {
unsigned int V_44 ;
V_44 = F_23 ( 32u , V_15 -> V_18 ) ;
if ( ! F_24 ( V_15 , V_44 ) )
goto error;
F_25 ( L_1 , V_17 -> V_45 ) ;
F_26 ( L_2 , V_46 , V_15 -> V_47 , V_44 ) ;
}
if ( ! F_24 ( V_15 , V_48 ) )
goto error;
F_27 ( V_15 ) ;
V_15 -> V_49 = V_50 ;
F_28 ( V_15 ) ;
F_29 ( V_15 ) ;
if ( F_30 ( V_5 , V_15 ) == V_51 ) {
F_16 ( & V_7 -> V_29 ) ;
F_15 ( V_39 , & V_7 -> V_28 ) ;
} else {
F_16 ( & V_7 -> V_30 ) ;
}
return;
error:
F_16 ( & V_7 -> V_30 ) ;
F_31 ( V_15 ) ;
}
static void F_32 ( struct V_16 * V_17 )
{
struct V_40 * V_41 ;
struct V_4 * V_5 ;
if ( V_17 ) {
V_41 = F_22 ( V_17 ) ;
V_5 = V_41 -> V_5 ;
if ( V_5 ) {
F_33 ( V_5 ) ;
V_41 -> V_5 = NULL ;
F_34 ( V_52 ) ;
}
}
}
static void F_35 ( struct V_53 * V_54 , void * V_55 )
{
struct V_16 * V_17 = V_55 ;
struct V_40 * V_41 = F_22 ( V_17 ) ;
struct V_4 * V_5 = V_41 -> V_5 ;
F_36 ( V_54 , L_3 , V_5 -> V_45 ) ;
}
static int F_37 ( struct V_2 * V_2 , T_1 V_56 , T_1 V_57 , T_1 V_58 , struct V_59 * V_60 )
{
struct V_4 * V_5 ;
char V_45 [ V_61 ] ;
struct V_62 * V_63 ;
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_40 * V_41 ;
int V_64 ;
struct V_1 * V_11 ;
V_63 = F_38 ( V_2 , V_56 ) ;
if ( ! V_63 ) {
V_64 = - V_65 ;
goto V_66;
}
V_17 = F_39 ( V_2 , V_63 , V_57 ) ;
if ( V_17 ) {
V_64 = - V_67 ;
goto V_66;
}
if ( V_60 -> V_68 ) {
V_5 = F_40 ( V_2 , V_60 -> V_68 ) ;
if ( V_5 ) {
F_11 ( V_5 ) ;
V_64 = - V_67 ;
goto V_66;
}
F_41 ( V_45 , V_60 -> V_68 , V_61 ) ;
} else
strcpy ( V_45 , V_69 ) ;
V_17 = F_42 ( sizeof( * V_41 ) , V_63 , V_57 ,
V_58 , V_60 ) ;
if ( ! V_17 ) {
V_64 = - V_70 ;
goto V_66;
}
V_5 = F_43 ( sizeof( * V_7 ) , V_45 , V_71 ,
F_19 ) ;
if ( ! V_5 ) {
V_64 = - V_70 ;
goto V_72;
}
F_44 ( V_5 , V_2 ) ;
if ( V_17 -> V_73 == 0 )
V_17 -> V_73 = V_5 -> V_73 - V_17 -> V_20 ;
V_5 -> V_73 = V_17 -> V_73 ;
V_5 -> V_74 += V_17 -> V_20 ;
V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_17 = V_17 ;
F_45 ( & V_7 -> V_13 ) ;
V_7 -> V_75 = V_63 -> V_76 ;
V_17 -> V_77 = F_21 ;
V_17 -> V_78 = F_32 ;
#if F_46 ( V_79 ) || F_46 ( V_80 )
V_17 -> V_81 = F_35 ;
#endif
V_41 = F_22 ( V_17 ) ;
V_41 -> V_5 = V_5 ;
V_64 = F_47 ( V_5 ) ;
if ( V_64 < 0 )
goto V_82;
F_48 ( V_52 ) ;
F_41 ( V_17 -> V_68 , V_5 -> V_45 , V_61 ) ;
F_49 ( V_5 ) ;
V_11 = F_1 ( F_7 ( V_5 ) ) ;
F_8 ( & V_11 -> V_12 ) ;
F_50 ( & V_7 -> V_13 , & V_11 -> V_83 ) ;
F_10 ( & V_11 -> V_12 ) ;
return 0 ;
V_82:
V_38 ( V_5 ) ;
V_41 -> V_5 = NULL ;
V_72:
F_51 ( V_17 ) ;
V_66:
return V_64 ;
}
static T_2 int F_52 ( struct V_2 * V_2 )
{
struct V_1 * V_11 = F_2 ( V_2 , V_3 ) ;
F_45 ( & V_11 -> V_83 ) ;
F_53 ( & V_11 -> V_12 ) ;
return 0 ;
}
static int T_3 F_54 ( void )
{
int V_84 = 0 ;
V_84 = F_55 ( V_85 , & V_86 ) ;
if ( V_84 )
goto V_66;
V_84 = F_56 ( & V_87 ) ;
if ( V_84 )
goto V_88;
F_57 ( L_4 ) ;
return 0 ;
V_88:
F_58 ( V_85 ) ;
V_66:
return V_84 ;
}
static void T_4 F_59 ( void )
{
F_60 ( & V_87 ) ;
F_58 ( V_85 ) ;
}
