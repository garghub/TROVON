static void F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
unsigned int V_4 , unsigned int V_5 , int V_6 ,
T_1 V_7 )
{
void * V_8 = F_2 ( V_3 ) ;
T_2 V_9 = V_7 * 512 + V_2 -> V_10 ;
void T_3 * V_11 = V_2 -> V_12 + V_9 ;
if ( V_6 == V_13 ) {
F_3 ( V_8 + V_5 , V_11 , V_4 ) ;
F_4 ( V_3 ) ;
} else {
F_4 ( V_3 ) ;
F_5 ( V_11 , V_8 + V_5 , V_4 ) ;
}
F_6 ( V_8 ) ;
}
static T_4 F_7 ( struct V_14 * V_15 , struct V_16 * V_16 )
{
bool V_17 ;
unsigned long V_18 ;
struct V_19 V_20 ;
struct V_21 V_22 ;
struct V_23 * V_24 = V_16 -> V_25 ;
struct V_1 * V_2 = V_24 -> V_26 -> V_27 ;
V_17 = F_8 ( V_16 , & V_18 ) ;
F_9 (bvec, bio, iter)
F_1 ( V_2 , V_20 . V_28 , V_20 . V_29 , V_20 . V_30 ,
F_10 ( V_16 ) , V_22 . V_31 ) ;
if ( V_17 )
F_11 ( V_16 , V_18 ) ;
if ( F_10 ( V_16 ) )
F_12 () ;
F_13 ( V_16 ) ;
return V_32 ;
}
static int F_14 ( struct V_23 * V_24 , T_1 V_7 ,
struct V_3 * V_3 , int V_6 )
{
struct V_1 * V_2 = V_24 -> V_26 -> V_27 ;
F_1 ( V_2 , V_3 , V_33 , 0 , V_6 , V_7 ) ;
if ( V_6 & V_34 )
F_12 () ;
F_15 ( V_3 , V_6 & V_34 , 0 ) ;
return 0 ;
}
static long F_16 ( struct V_23 * V_24 , T_1 V_7 ,
void T_3 * * V_35 , unsigned long * V_36 )
{
struct V_1 * V_2 = V_24 -> V_26 -> V_27 ;
T_5 V_37 = V_7 * 512 + V_2 -> V_10 ;
* V_35 = V_2 -> V_12 + V_37 ;
* V_36 = ( V_2 -> V_38 + V_37 ) >> V_39 ;
return V_2 -> V_40 - V_37 ;
}
static struct V_1 * F_17 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int V_45 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_42 , sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return F_19 ( - V_47 ) ;
V_2 -> V_38 = V_44 -> V_18 ;
V_2 -> V_40 = F_20 ( V_44 ) ;
if ( ! F_21 () )
F_22 ( V_42 , L_1 ) ;
if ( ! F_23 ( V_42 , V_2 -> V_38 , V_2 -> V_40 ,
F_24 ( V_42 ) ) ) {
F_22 ( V_42 , L_2 ,
& V_2 -> V_38 , V_2 -> V_40 ) ;
return F_19 ( - V_48 ) ;
}
if ( F_25 ( V_42 ) )
V_2 -> V_12 = ( void T_3 * ) F_26 ( V_42 , V_44 ) ;
else
V_2 -> V_12 = ( void T_3 * ) F_27 ( V_42 ,
V_2 -> V_38 , V_2 -> V_40 ,
V_49 ) ;
if ( F_28 ( V_2 -> V_12 ) )
return ( void V_50 * ) V_2 -> V_12 ;
return V_2 ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_51 )
return;
F_30 ( V_2 -> V_51 ) ;
F_31 ( V_2 -> V_51 ) ;
F_32 ( V_2 -> V_52 ) ;
}
static int F_33 ( struct V_41 * V_42 ,
struct V_53 * V_54 , struct V_1 * V_2 )
{
int V_55 = F_34 ( V_42 ) ;
struct V_56 * V_57 ;
V_2 -> V_52 = F_35 ( V_46 , V_55 ) ;
if ( ! V_2 -> V_52 )
return - V_47 ;
F_36 ( V_2 -> V_52 , F_7 ) ;
F_37 ( V_2 -> V_52 , V_58 ) ;
F_38 ( V_2 -> V_52 , V_59 ) ;
F_39 ( V_2 -> V_52 , V_60 ) ;
F_40 ( V_61 , V_2 -> V_52 ) ;
V_57 = F_41 ( 0 , V_55 ) ;
if ( ! V_57 ) {
F_32 ( V_2 -> V_52 ) ;
return - V_47 ;
}
V_57 -> V_62 = V_63 ;
V_57 -> V_64 = 0 ;
V_57 -> V_65 = & V_66 ;
V_57 -> V_27 = V_2 ;
V_57 -> V_67 = V_2 -> V_52 ;
V_57 -> V_68 = V_69 ;
F_42 ( V_54 , V_57 -> V_70 ) ;
V_57 -> V_71 = V_42 ;
F_43 ( V_57 , ( V_2 -> V_40 - V_2 -> V_10 ) / 512 ) ;
V_2 -> V_51 = V_57 ;
F_44 ( V_57 ) ;
F_45 ( V_57 ) ;
return 0 ;
}
static int F_46 ( struct V_53 * V_54 ,
T_5 V_37 , void * V_72 , T_6 V_40 , int V_6 )
{
struct V_1 * V_2 = F_47 ( V_54 -> V_73 ) ;
if ( F_48 ( V_37 + V_40 > V_2 -> V_40 ) ) {
F_49 ( & V_54 -> V_42 , 1 , L_3 ) ;
return - V_74 ;
}
if ( V_6 == V_13 )
F_3 ( V_72 , V_2 -> V_12 + V_37 , V_40 ) ;
else {
F_5 ( V_2 -> V_12 + V_37 , V_72 , V_40 ) ;
F_12 () ;
}
return 0 ;
}
static int F_50 ( struct V_75 * V_75 )
{
struct V_76 * V_77 = F_51 ( sizeof( * V_77 ) , V_46 ) ;
struct V_1 * V_2 = F_47 ( & V_75 -> V_42 ) ;
struct V_53 * V_54 = V_75 -> V_54 ;
struct V_78 * V_78 ;
unsigned long V_79 ;
T_2 V_37 ;
T_7 V_80 ;
int V_81 ;
if ( ! V_77 )
return - V_47 ;
V_75 -> V_77 = V_77 ;
V_81 = F_52 ( V_75 ) ;
if ( V_81 == 0 || V_81 == - V_48 )
return V_81 ;
if ( F_53 ( V_54 ) < V_82
|| V_2 -> V_38 & V_83 )
return - V_84 ;
V_78 = F_54 ( V_75 -> V_42 . V_85 ) ;
if ( V_78 -> V_86 ) {
F_55 ( & V_75 -> V_42 ,
L_4 ,
F_24 ( & V_78 -> V_42 ) ) ;
goto V_87;
}
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
V_79 = ( V_2 -> V_40 - V_88 ) / V_89 ;
if ( V_75 -> V_90 == V_91 )
V_37 = F_56 ( V_88 + 64 * V_79 , V_92 ) ;
else if ( V_75 -> V_90 == V_93 )
V_37 = V_88 ;
else
goto V_87;
V_79 = ( V_2 -> V_40 - V_37 ) / V_89 ;
V_77 -> V_90 = F_57 ( V_75 -> V_90 ) ;
V_77 -> V_94 = F_58 ( V_37 ) ;
V_77 -> V_79 = F_58 ( V_79 ) ;
memcpy ( V_77 -> V_95 , V_96 , V_97 ) ;
memcpy ( V_77 -> V_98 , V_75 -> V_98 , 16 ) ;
V_77 -> V_99 = F_59 ( 1 ) ;
V_80 = F_60 ( (struct V_100 * ) V_77 ) ;
V_77 -> V_80 = F_58 ( V_80 ) ;
V_81 = F_61 ( V_54 , V_89 , V_77 , sizeof( * V_77 ) ) ;
if ( V_81 )
goto V_87;
return 0 ;
V_87:
V_75 -> V_77 = NULL ;
F_62 ( V_77 ) ;
return - V_101 ;
}
static int F_63 ( struct V_53 * V_54 )
{
struct V_75 * V_75 = F_64 ( V_54 -> V_73 ) ;
struct V_1 * V_2 ;
V_2 = F_47 ( & V_75 -> V_42 ) ;
F_29 ( V_2 ) ;
F_62 ( V_75 -> V_77 ) ;
V_75 -> V_77 = NULL ;
return 0 ;
}
static int F_65 ( struct V_53 * V_54 )
{
struct V_102 * V_103 = F_66 ( & V_54 -> V_42 ) ;
struct V_75 * V_75 = F_64 ( V_54 -> V_73 ) ;
struct V_41 * V_42 = & V_75 -> V_42 ;
struct V_104 * V_105 ;
struct V_78 * V_78 ;
struct V_76 * V_77 ;
struct V_1 * V_2 ;
T_2 V_37 ;
int V_81 ;
if ( ! V_75 -> V_98 || ! V_75 -> V_54 )
return - V_84 ;
V_78 = F_54 ( V_42 -> V_85 ) ;
V_81 = F_50 ( V_75 ) ;
if ( V_81 )
return V_81 ;
if ( V_58 != V_89 ) {
F_67 ( V_42 , L_5 ) ;
return - V_101 ;
}
if ( V_103 -> V_44 . V_18 & V_83 ) {
F_67 ( V_42 , L_6 ,
F_24 ( & V_54 -> V_42 ) ) ;
return - V_101 ;
}
V_77 = V_75 -> V_77 ;
V_37 = F_68 ( V_77 -> V_94 ) ;
V_75 -> V_90 = F_69 ( V_75 -> V_77 -> V_90 ) ;
if ( V_75 -> V_90 == V_93 ) {
if ( V_37 != V_88 )
return - V_106 ;
V_75 -> V_79 = F_68 ( V_77 -> V_79 ) ;
V_105 = NULL ;
} else {
V_81 = - V_101 ;
goto V_87;
}
V_2 = F_47 ( V_42 ) ;
F_70 ( V_42 , ( void V_50 * ) V_2 -> V_12 ) ;
V_2 -> V_12 = ( void T_3 * ) F_26 ( V_42 , & V_103 -> V_44 ) ;
if ( F_28 ( V_2 -> V_12 ) ) {
V_81 = F_71 ( V_2 -> V_12 ) ;
goto V_87;
}
V_2 -> V_10 = V_37 ;
V_81 = F_33 ( V_42 , V_54 , V_2 ) ;
if ( V_81 )
goto V_87;
return V_81 ;
V_87:
F_63 ( V_54 ) ;
return V_81 ;
}
static int F_72 ( struct V_41 * V_42 )
{
struct V_78 * V_78 = F_54 ( V_42 -> V_85 ) ;
struct V_53 * V_54 ;
struct V_102 * V_103 ;
struct V_1 * V_2 ;
V_54 = F_73 ( V_42 ) ;
if ( F_28 ( V_54 ) )
return F_71 ( V_54 ) ;
V_103 = F_66 ( & V_54 -> V_42 ) ;
V_2 = F_17 ( V_42 , & V_103 -> V_44 , V_78 -> V_45 ) ;
if ( F_28 ( V_2 ) )
return F_71 ( V_2 ) ;
V_2 -> V_54 = V_54 ;
F_74 ( V_42 , V_2 ) ;
V_54 -> V_107 = F_46 ;
if ( F_75 ( V_42 ) )
return F_76 ( V_54 ) ;
if ( F_77 ( V_42 ) )
return F_65 ( V_54 ) ;
if ( F_78 ( V_54 , V_2 ) == 0 ) {
return - V_101 ;
}
if ( F_79 ( V_54 , V_2 ) == 0 ) {
return - V_101 ;
}
return F_33 ( V_42 , V_54 , V_2 ) ;
}
static int F_80 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
if ( F_75 ( V_42 ) )
F_81 ( V_2 -> V_54 ) ;
else if ( F_77 ( V_42 ) )
F_63 ( V_2 -> V_54 ) ;
else
F_29 ( V_2 ) ;
return 0 ;
}
static int T_8 F_82 ( void )
{
int error ;
V_63 = F_83 ( 0 , L_7 ) ;
if ( V_63 < 0 )
return V_63 ;
error = F_84 ( & V_108 ) ;
if ( error ) {
F_85 ( V_63 , L_7 ) ;
return error ;
}
return 0 ;
}
static void F_86 ( void )
{
F_87 ( & V_108 . V_109 ) ;
F_85 ( V_63 , L_7 ) ;
}
