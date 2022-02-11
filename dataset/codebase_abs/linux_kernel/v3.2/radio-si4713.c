static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , L_1 , 32 ) ;
return 0 ;
}
static int F_3 ( struct V_4 * V_4 , void * V_5 ,
struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
static int F_4 ( struct V_4 * V_4 , void * V_5 ,
struct V_1 * V_2 )
{
int V_6 = F_1 ( V_2 ) ;
V_2 -> V_7 = 0 ;
return V_6 ;
}
static int F_5 ( struct V_4 * V_4 , void * V_5 ,
struct V_1 * V_2 )
{
return V_2 -> V_7 ? - V_8 : 0 ;
}
static int F_6 ( struct V_4 * V_4 , void * V_5 ,
struct V_9 * V_10 )
{
F_2 ( V_10 -> V_11 , L_2 , sizeof( V_10 -> V_11 ) ) ;
F_2 ( V_10 -> V_12 , L_3 ,
sizeof( V_10 -> V_12 ) ) ;
V_10 -> V_13 = V_14 | V_15 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_4 , void * V_5 ,
struct V_16 * V_17 )
{
static const T_1 V_18 [] = {
V_19 ,
V_20 ,
0
} ;
static const T_1 V_21 [] = {
V_22 ,
V_23 ,
V_24 ,
V_25 ,
V_26 ,
V_27 ,
V_28 ,
V_29 ,
V_30 ,
V_31 ,
V_32 ,
V_33 ,
V_34 ,
V_35 ,
V_36 ,
V_37 ,
V_38 ,
V_39 ,
V_40 ,
V_41 ,
0
} ;
static const T_1 * V_42 [] = {
V_18 ,
V_21 ,
NULL
} ;
struct V_43 * V_44 ;
V_44 = F_8 ( F_9 ( V_4 ) ) ;
V_17 -> V_45 = F_10 ( V_42 , V_17 -> V_45 ) ;
if ( V_17 -> V_45 == 0 )
return - V_8 ;
if ( V_17 -> V_45 == V_19 || V_17 -> V_45 == V_22 )
return F_11 ( V_17 , 0 , 0 , 0 , 0 ) ;
return F_12 ( & V_44 -> V_46 , 0 , V_47 ,
V_48 , V_17 ) ;
}
static inline struct V_49 * F_13 ( struct V_4 * V_4 )
{
return & ( (struct V_43 * ) F_14 ( V_4 ) ) -> V_46 ;
}
static int F_15 ( struct V_4 * V_4 , void * V_50 ,
struct V_51 * V_52 )
{
return F_12 ( F_13 ( V_4 ) , 0 , V_47 ,
V_53 , V_52 ) ;
}
static int F_16 ( struct V_4 * V_4 , void * V_50 ,
struct V_51 * V_52 )
{
return F_12 ( F_13 ( V_4 ) , 0 , V_47 ,
V_54 , V_52 ) ;
}
static int F_17 ( struct V_4 * V_4 , void * V_50 ,
struct V_55 * V_56 )
{
return F_12 ( F_13 ( V_4 ) , 0 , V_47 ,
V_57 , V_56 ) ;
}
static int F_18 ( struct V_4 * V_4 , void * V_50 ,
struct V_55 * V_56 )
{
return F_12 ( F_13 ( V_4 ) , 0 , V_47 ,
V_58 , V_56 ) ;
}
static int F_19 ( struct V_4 * V_4 , void * V_50 ,
struct V_59 * V_60 )
{
return F_12 ( F_13 ( V_4 ) , 0 , V_61 ,
V_62 , V_60 ) ;
}
static int F_20 ( struct V_4 * V_4 , void * V_50 ,
struct V_59 * V_60 )
{
return F_12 ( F_13 ( V_4 ) , 0 , V_61 ,
V_63 , V_60 ) ;
}
static int F_21 ( struct V_4 * V_4 , void * V_50 ,
struct V_64 * V_65 )
{
return F_12 ( F_13 ( V_4 ) , 0 , V_61 ,
V_66 , V_65 ) ;
}
static int F_22 ( struct V_4 * V_4 , void * V_50 ,
struct V_64 * V_65 )
{
return F_12 ( F_13 ( V_4 ) , 0 , V_61 ,
V_67 , V_65 ) ;
}
static long F_23 ( struct V_4 * V_4 , void * V_50 ,
bool V_68 , int V_69 , void * V_70 )
{
return F_12 ( F_13 ( V_4 ) , 0 , V_47 ,
V_71 , V_69 , V_70 ) ;
}
static int F_24 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 . V_77 ;
struct V_43 * V_44 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
int V_6 = 0 ;
if ( ! V_75 ) {
F_25 ( & V_73 -> V_76 , L_4 ) ;
V_6 = - V_8 ;
goto exit;
}
V_44 = F_26 ( sizeof *V_44 , V_82 ) ;
if ( ! V_44 ) {
F_25 ( & V_73 -> V_76 , L_5 ) ;
V_6 = - V_83 ;
goto exit;
}
V_6 = F_27 ( & V_73 -> V_76 , & V_44 -> V_46 ) ;
if ( V_6 ) {
F_25 ( & V_73 -> V_76 , L_6 ) ;
goto V_84;
}
V_79 = F_28 ( V_75 -> V_85 ) ;
if ( ! V_79 ) {
F_25 ( & V_73 -> V_76 , L_7 ,
V_75 -> V_85 ) ;
V_6 = - V_86 ;
goto V_87;
}
V_81 = F_29 ( & V_44 -> V_46 , V_79 ,
V_75 -> V_88 , NULL ) ;
if ( ! V_81 ) {
F_25 ( & V_73 -> V_76 , L_8 ) ;
V_6 = - V_86 ;
goto V_89;
}
V_44 -> V_90 = F_30 () ;
if ( ! V_44 -> V_90 ) {
F_25 ( & V_73 -> V_76 , L_5 ) ;
V_6 = - V_83 ;
goto V_89;
}
memcpy ( V_44 -> V_90 , & V_91 ,
sizeof( V_91 ) ) ;
F_31 ( V_44 -> V_90 , V_44 ) ;
if ( F_32 ( V_44 -> V_90 , V_92 , V_93 ) ) {
F_25 ( & V_73 -> V_76 , L_9 ) ;
V_6 = - V_94 ;
goto V_95;
}
F_33 ( & V_73 -> V_76 , L_10 ) ;
goto exit;
V_95:
F_34 ( V_44 -> V_90 ) ;
V_89:
F_35 ( V_79 ) ;
V_87:
F_36 ( & V_44 -> V_46 ) ;
V_84:
F_37 ( V_44 ) ;
exit:
return V_6 ;
}
static int T_2 F_38 ( struct V_72 * V_73 )
{
struct V_49 * V_46 = F_39 ( V_73 ) ;
struct V_43 * V_44 = F_40 ( V_46 ,
struct V_43 ,
V_46 ) ;
struct V_80 * V_81 = F_41 ( V_46 -> V_96 . V_97 ,
struct V_80 , V_98 ) ;
struct V_99 * V_100 = F_42 ( V_81 ) ;
F_43 ( V_44 -> V_90 ) ;
F_35 ( V_100 -> V_79 ) ;
F_36 ( & V_44 -> V_46 ) ;
F_37 ( V_44 ) ;
return 0 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_101 ) ;
}
static void T_2 F_46 ( void )
{
F_47 ( & V_101 ) ;
}
