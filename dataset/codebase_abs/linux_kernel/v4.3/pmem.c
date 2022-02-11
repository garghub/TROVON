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
static void F_7 ( struct V_14 * V_15 , struct V_16 * V_16 )
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
}
static int F_14 ( struct V_23 * V_24 , T_1 V_7 ,
struct V_3 * V_3 , int V_6 )
{
struct V_1 * V_2 = V_24 -> V_26 -> V_27 ;
F_1 ( V_2 , V_3 , V_32 , 0 , V_6 , V_7 ) ;
if ( V_6 & V_33 )
F_12 () ;
F_15 ( V_3 , V_6 & V_33 , 0 ) ;
return 0 ;
}
static long F_16 ( struct V_23 * V_24 , T_1 V_7 ,
void T_3 * * V_34 , unsigned long * V_35 )
{
struct V_1 * V_2 = V_24 -> V_26 -> V_27 ;
T_4 V_36 = V_7 * 512 + V_2 -> V_10 ;
T_4 V_37 ;
if ( V_2 -> V_10 ) {
V_37 = ( V_2 -> V_37 - V_36 ) & ~ V_38 ;
} else
V_37 = V_2 -> V_37 - V_36 ;
* V_34 = V_2 -> V_12 + V_36 ;
* V_35 = ( V_2 -> V_39 + V_36 ) >> V_40 ;
return V_37 ;
}
static struct V_1 * F_17 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int V_45 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_42 , sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return F_19 ( - V_47 ) ;
V_2 -> V_39 = V_44 -> V_18 ;
V_2 -> V_37 = F_20 ( V_44 ) ;
if ( ! F_21 () )
F_22 ( V_42 , L_1 ) ;
if ( ! F_23 ( V_42 , V_2 -> V_39 , V_2 -> V_37 ,
F_24 ( V_42 ) ) ) {
F_22 ( V_42 , L_2 ,
& V_2 -> V_39 , V_2 -> V_37 ) ;
return F_19 ( - V_48 ) ;
}
if ( F_25 ( V_42 ) ) {
void * V_49 = F_26 ( V_42 , V_44 ) ;
if ( F_27 ( V_49 ) )
return V_49 ;
V_2 -> V_12 = ( void T_3 * ) V_49 ;
} else {
V_2 -> V_12 = F_28 ( V_42 , V_2 -> V_39 ,
V_2 -> V_37 ) ;
if ( ! V_2 -> V_12 )
return F_19 ( - V_50 ) ;
}
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
struct V_55 * V_56 ;
V_2 -> V_52 = F_34 ( V_46 ) ;
if ( ! V_2 -> V_52 )
return - V_47 ;
F_35 ( V_2 -> V_52 , F_7 ) ;
F_36 ( V_2 -> V_52 , V_57 ) ;
F_37 ( V_2 -> V_52 , V_58 ) ;
F_38 ( V_2 -> V_52 , V_59 ) ;
F_39 ( V_60 , V_2 -> V_52 ) ;
V_56 = F_40 ( 0 ) ;
if ( ! V_56 ) {
F_32 ( V_2 -> V_52 ) ;
return - V_47 ;
}
V_56 -> V_61 = V_62 ;
V_56 -> V_63 = 0 ;
V_56 -> V_64 = & V_65 ;
V_56 -> V_27 = V_2 ;
V_56 -> V_66 = V_2 -> V_52 ;
V_56 -> V_67 = V_68 ;
F_41 ( V_54 , V_56 -> V_69 ) ;
V_56 -> V_70 = V_42 ;
F_42 ( V_56 , ( V_2 -> V_37 - V_2 -> V_10 ) / 512 ) ;
V_2 -> V_51 = V_56 ;
F_43 ( V_56 ) ;
F_44 ( V_56 ) ;
return 0 ;
}
static int F_45 ( struct V_53 * V_54 ,
T_4 V_36 , void * V_71 , T_5 V_37 , int V_6 )
{
struct V_1 * V_2 = F_46 ( V_54 -> V_72 ) ;
if ( F_47 ( V_36 + V_37 > V_2 -> V_37 ) ) {
F_48 ( & V_54 -> V_42 , 1 , L_3 ) ;
return - V_73 ;
}
if ( V_6 == V_13 )
F_3 ( V_71 , V_2 -> V_12 + V_36 , V_37 ) ;
else {
F_5 ( V_2 -> V_12 + V_36 , V_71 , V_37 ) ;
F_12 () ;
}
return 0 ;
}
static int F_49 ( struct V_74 * V_74 )
{
struct V_75 * V_76 = F_50 ( sizeof( * V_76 ) , V_46 ) ;
struct V_1 * V_2 = F_46 ( & V_74 -> V_42 ) ;
struct V_53 * V_54 = V_74 -> V_54 ;
struct V_77 * V_77 ;
unsigned long V_78 ;
T_2 V_36 ;
T_6 V_79 ;
int V_80 ;
if ( ! V_76 )
return - V_47 ;
V_74 -> V_76 = V_76 ;
V_80 = F_51 ( V_74 ) ;
if ( V_80 == 0 || V_80 == - V_48 )
return V_80 ;
if ( F_52 ( V_54 ) < V_81
|| V_2 -> V_39 & V_38 )
return - V_82 ;
V_77 = F_53 ( V_74 -> V_42 . V_83 ) ;
if ( V_77 -> V_84 ) {
F_54 ( & V_74 -> V_42 ,
L_4 ,
F_24 ( & V_77 -> V_42 ) ) ;
goto V_85;
}
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_78 = ( V_2 -> V_37 - V_86 ) / V_87 ;
if ( V_74 -> V_88 == V_89 )
V_36 = F_55 ( V_86 + 64 * V_78 , V_90 ) ;
else if ( V_74 -> V_88 == V_91 )
V_36 = V_86 ;
else
goto V_85;
V_78 = ( V_2 -> V_37 - V_36 ) / V_87 ;
V_76 -> V_88 = F_56 ( V_74 -> V_88 ) ;
V_76 -> V_92 = F_57 ( V_36 ) ;
V_76 -> V_78 = F_57 ( V_78 ) ;
memcpy ( V_76 -> V_93 , V_94 , V_95 ) ;
memcpy ( V_76 -> V_96 , V_74 -> V_96 , 16 ) ;
V_76 -> V_97 = F_58 ( 1 ) ;
V_79 = F_59 ( (struct V_98 * ) V_76 ) ;
V_76 -> V_79 = F_57 ( V_79 ) ;
V_80 = F_60 ( V_54 , V_87 , V_76 , sizeof( * V_76 ) ) ;
if ( V_80 )
goto V_85;
return 0 ;
V_85:
V_74 -> V_76 = NULL ;
F_61 ( V_76 ) ;
return - V_50 ;
}
static int F_62 ( struct V_53 * V_54 )
{
struct V_74 * V_74 = F_63 ( V_54 -> V_72 ) ;
struct V_1 * V_2 ;
V_2 = F_46 ( & V_74 -> V_42 ) ;
F_29 ( V_2 ) ;
F_61 ( V_74 -> V_76 ) ;
V_74 -> V_76 = NULL ;
return 0 ;
}
static int F_64 ( struct V_53 * V_54 )
{
struct V_99 * V_100 = F_65 ( & V_54 -> V_42 ) ;
struct V_74 * V_74 = F_63 ( V_54 -> V_72 ) ;
struct V_41 * V_42 = & V_74 -> V_42 ;
struct V_101 * V_102 ;
struct V_77 * V_77 ;
struct V_75 * V_76 ;
struct V_1 * V_2 ;
T_2 V_36 ;
int V_80 ;
if ( ! V_74 -> V_96 || ! V_74 -> V_54 )
return - V_82 ;
V_77 = F_53 ( V_42 -> V_83 ) ;
V_80 = F_49 ( V_74 ) ;
if ( V_80 )
return V_80 ;
if ( V_57 != V_87 ) {
F_66 ( V_42 , L_5 ) ;
return - V_50 ;
}
if ( V_100 -> V_44 . V_18 & V_38 ) {
F_66 ( V_42 , L_6 ,
F_24 ( & V_54 -> V_42 ) ) ;
return - V_50 ;
}
V_76 = V_74 -> V_76 ;
V_36 = F_67 ( V_76 -> V_92 ) ;
V_74 -> V_88 = F_68 ( V_74 -> V_76 -> V_88 ) ;
if ( V_74 -> V_88 == V_91 ) {
if ( V_36 != V_86 )
return - V_103 ;
V_74 -> V_78 = F_67 ( V_76 -> V_78 ) ;
V_102 = NULL ;
} else {
V_80 = - V_50 ;
goto V_85;
}
V_2 = F_46 ( V_42 ) ;
F_69 ( V_42 , V_2 -> V_12 ) ;
V_2 -> V_12 = ( void T_3 * ) F_26 ( V_42 , & V_100 -> V_44 ) ;
if ( F_27 ( V_2 -> V_12 ) ) {
V_80 = F_70 ( V_2 -> V_12 ) ;
goto V_85;
}
V_2 -> V_10 = V_36 ;
V_80 = F_33 ( V_42 , V_54 , V_2 ) ;
if ( V_80 )
goto V_85;
return V_80 ;
V_85:
F_62 ( V_54 ) ;
return V_80 ;
}
static int F_71 ( struct V_41 * V_42 )
{
struct V_77 * V_77 = F_53 ( V_42 -> V_83 ) ;
struct V_53 * V_54 ;
struct V_99 * V_100 ;
struct V_1 * V_2 ;
V_54 = F_72 ( V_42 ) ;
if ( F_27 ( V_54 ) )
return F_70 ( V_54 ) ;
V_100 = F_65 ( & V_54 -> V_42 ) ;
V_2 = F_17 ( V_42 , & V_100 -> V_44 , V_77 -> V_45 ) ;
if ( F_27 ( V_2 ) )
return F_70 ( V_2 ) ;
V_2 -> V_54 = V_54 ;
F_73 ( V_42 , V_2 ) ;
V_54 -> V_104 = F_45 ;
if ( F_74 ( V_42 ) )
return F_75 ( V_54 ) ;
if ( F_76 ( V_42 ) )
return F_64 ( V_54 ) ;
if ( F_77 ( V_54 , V_2 ) == 0 ) {
return - V_50 ;
}
if ( F_78 ( V_54 , V_2 ) == 0 ) {
return - V_50 ;
}
return F_33 ( V_42 , V_54 , V_2 ) ;
}
static int F_79 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_46 ( V_42 ) ;
if ( F_74 ( V_42 ) )
F_80 ( V_2 -> V_54 ) ;
else if ( F_76 ( V_42 ) )
F_62 ( V_2 -> V_54 ) ;
else
F_29 ( V_2 ) ;
return 0 ;
}
static int T_7 F_81 ( void )
{
int error ;
V_62 = F_82 ( 0 , L_7 ) ;
if ( V_62 < 0 )
return V_62 ;
error = F_83 ( & V_105 ) ;
if ( error ) {
F_84 ( V_62 , L_7 ) ;
return error ;
}
return 0 ;
}
static void F_85 ( void )
{
F_86 ( & V_105 . V_106 ) ;
F_84 ( V_62 , L_7 ) ;
}
