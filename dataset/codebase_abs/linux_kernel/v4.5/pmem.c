static bool F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned int V_4 )
{
if ( V_2 -> V_5 ) {
T_1 V_6 ;
int V_7 ;
return ! ! F_2 ( V_2 , V_3 , V_4 / 512 , & V_6 ,
& V_7 ) ;
}
return false ;
}
static int F_3 ( struct V_8 * V_9 , struct V_10 * V_10 ,
unsigned int V_4 , unsigned int V_11 , int V_12 ,
T_1 V_3 )
{
void * V_13 = F_4 ( V_10 ) ;
T_2 V_14 = V_3 * 512 + V_9 -> V_15 ;
void T_3 * V_16 = V_9 -> V_17 + V_14 ;
if ( V_12 == V_18 ) {
if ( F_5 ( F_1 ( & V_9 -> V_2 , V_3 , V_4 ) ) )
return - V_19 ;
F_6 ( V_13 + V_11 , V_16 , V_4 ) ;
F_7 ( V_10 ) ;
} else {
F_7 ( V_10 ) ;
F_8 ( V_16 , V_13 + V_11 , V_4 ) ;
}
F_9 ( V_13 ) ;
return 0 ;
}
static T_4 F_10 ( struct V_20 * V_21 , struct V_22 * V_22 )
{
int V_23 = 0 ;
bool V_24 ;
unsigned long V_25 ;
struct V_26 V_27 ;
struct V_28 V_29 ;
struct V_30 * V_31 = V_22 -> V_32 ;
struct V_8 * V_9 = V_31 -> V_33 -> V_34 ;
V_24 = F_11 ( V_22 , & V_25 ) ;
F_12 (bvec, bio, iter) {
V_23 = F_3 ( V_9 , V_27 . V_35 , V_27 . V_36 ,
V_27 . V_37 , F_13 ( V_22 ) ,
V_29 . V_38 ) ;
if ( V_23 ) {
V_22 -> V_39 = V_23 ;
break;
}
}
if ( V_24 )
F_14 ( V_22 , V_25 ) ;
if ( F_13 ( V_22 ) )
F_15 () ;
F_16 ( V_22 ) ;
return V_40 ;
}
static int F_17 ( struct V_30 * V_31 , T_1 V_3 ,
struct V_10 * V_10 , int V_12 )
{
struct V_8 * V_9 = V_31 -> V_33 -> V_34 ;
int V_23 ;
V_23 = F_3 ( V_9 , V_10 , V_41 , 0 , V_12 , V_3 ) ;
if ( V_12 & V_42 )
F_15 () ;
if ( V_23 == 0 )
F_18 ( V_10 , V_12 & V_42 , 0 ) ;
return V_23 ;
}
static long F_19 ( struct V_30 * V_31 , T_1 V_3 ,
void T_3 * * V_43 , T_5 * V_44 )
{
struct V_8 * V_9 = V_31 -> V_33 -> V_34 ;
T_6 V_45 = V_3 * 512 + V_9 -> V_15 ;
* V_43 = V_9 -> V_17 + V_45 ;
* V_44 = F_20 ( V_9 -> V_46 + V_45 , V_9 -> V_47 ) ;
return V_9 -> V_48 - V_45 ;
}
static struct V_8 * F_21 ( struct V_49 * V_50 ,
struct V_51 * V_52 , int V_53 )
{
struct V_8 * V_9 ;
struct V_20 * V_21 ;
V_9 = F_22 ( V_50 , sizeof( * V_9 ) , V_54 ) ;
if ( ! V_9 )
return F_23 ( - V_55 ) ;
V_9 -> V_46 = V_52 -> V_25 ;
V_9 -> V_48 = F_24 ( V_52 ) ;
if ( ! F_25 () )
F_26 ( V_50 , L_1 ) ;
if ( ! F_27 ( V_50 , V_9 -> V_46 , V_9 -> V_48 ,
F_28 ( V_50 ) ) ) {
F_26 ( V_50 , L_2 ,
& V_9 -> V_46 , V_9 -> V_48 ) ;
return F_23 ( - V_56 ) ;
}
V_21 = F_29 ( V_54 , F_30 ( V_50 ) ) ;
if ( ! V_21 )
return F_23 ( - V_55 ) ;
V_9 -> V_47 = V_57 ;
if ( F_31 ( V_50 ) ) {
V_9 -> V_17 = ( void T_3 * ) F_32 ( V_50 , V_52 ,
& V_21 -> V_58 , NULL ) ;
V_9 -> V_47 |= V_59 ;
} else
V_9 -> V_17 = ( void T_3 * ) F_33 ( V_50 ,
V_9 -> V_46 , V_9 -> V_48 ,
V_60 ) ;
if ( F_34 ( V_9 -> V_17 ) ) {
F_35 ( V_21 ) ;
return ( void V_61 * ) V_9 -> V_17 ;
}
V_9 -> V_62 = V_21 ;
return V_9 ;
}
static void F_36 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_63 )
return;
F_37 ( V_9 -> V_63 ) ;
F_38 ( V_9 -> V_63 ) ;
F_35 ( V_9 -> V_62 ) ;
}
static int F_39 ( struct V_49 * V_50 ,
struct V_64 * V_65 , struct V_8 * V_9 )
{
int V_66 = F_30 ( V_50 ) ;
struct V_67 * V_68 ;
F_40 ( V_9 -> V_62 , F_10 ) ;
F_41 ( V_9 -> V_62 , V_69 ) ;
F_42 ( V_9 -> V_62 , V_70 ) ;
F_43 ( V_9 -> V_62 , V_71 ) ;
F_44 ( V_72 , V_9 -> V_62 ) ;
V_68 = F_45 ( 0 , V_66 ) ;
if ( ! V_68 ) {
F_35 ( V_9 -> V_62 ) ;
return - V_55 ;
}
V_68 -> V_73 = V_74 ;
V_68 -> V_75 = 0 ;
V_68 -> V_76 = & V_77 ;
V_68 -> V_34 = V_9 ;
V_68 -> V_78 = V_9 -> V_62 ;
V_68 -> V_79 = V_80 ;
F_46 ( V_65 , V_68 -> V_81 ) ;
V_68 -> V_82 = V_50 ;
F_47 ( V_68 , ( V_9 -> V_48 - V_9 -> V_15 ) / 512 ) ;
V_9 -> V_63 = V_68 ;
F_48 ( V_50 , & V_9 -> V_2 ) ;
if ( F_49 ( V_50 , & V_9 -> V_2 ) )
return - V_55 ;
F_50 ( V_65 , & V_9 -> V_2 , V_9 -> V_15 ) ;
V_68 -> V_2 = & V_9 -> V_2 ;
F_51 ( V_68 ) ;
F_52 ( V_68 ) ;
return 0 ;
}
static int F_53 ( struct V_64 * V_65 ,
T_6 V_45 , void * V_83 , T_7 V_48 , int V_12 )
{
struct V_8 * V_9 = F_54 ( V_65 -> V_84 ) ;
if ( F_5 ( V_45 + V_48 > V_9 -> V_48 ) ) {
F_55 ( & V_65 -> V_50 , 1 , L_3 ) ;
return - V_85 ;
}
if ( V_12 == V_18 ) {
unsigned int V_86 = F_56 ( V_48 + ( V_45 & ( 512 - 1 ) ) , 512 ) ;
if ( F_5 ( F_1 ( & V_9 -> V_2 , V_45 / 512 , V_86 ) ) )
return - V_19 ;
F_6 ( V_83 , V_9 -> V_17 + V_45 , V_48 ) ;
} else {
F_8 ( V_9 -> V_17 + V_45 , V_83 , V_48 ) ;
F_15 () ;
}
return 0 ;
}
static int F_57 ( struct V_87 * V_87 )
{
struct V_88 * V_89 = F_58 ( sizeof( * V_89 ) , V_54 ) ;
struct V_8 * V_9 = F_54 ( & V_87 -> V_50 ) ;
struct V_64 * V_65 = V_87 -> V_65 ;
struct V_90 * V_90 ;
unsigned long V_91 ;
T_2 V_45 ;
T_8 V_92 ;
int V_23 ;
if ( ! V_89 )
return - V_55 ;
V_87 -> V_89 = V_89 ;
V_23 = F_59 ( V_87 ) ;
if ( V_23 == - V_93 )
;
else
return V_23 ;
V_90 = F_60 ( V_87 -> V_50 . V_94 ) ;
if ( V_90 -> V_95 ) {
F_61 ( & V_87 -> V_50 ,
L_4 ,
F_28 ( & V_90 -> V_50 ) ) ;
goto V_96;
}
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_91 = ( V_9 -> V_48 - V_97 ) / V_98 ;
if ( V_87 -> V_99 == V_100 )
V_45 = F_56 ( V_97 + 64 * V_91 , V_87 -> V_101 ) ;
else if ( V_87 -> V_99 == V_102 )
V_45 = F_56 ( V_97 , V_87 -> V_101 ) ;
else
goto V_96;
V_91 = ( V_9 -> V_48 - V_45 ) / V_98 ;
V_89 -> V_99 = F_62 ( V_87 -> V_99 ) ;
V_89 -> V_103 = F_63 ( V_45 ) ;
V_89 -> V_91 = F_63 ( V_91 ) ;
memcpy ( V_89 -> V_104 , V_105 , V_106 ) ;
memcpy ( V_89 -> V_107 , V_87 -> V_107 , 16 ) ;
memcpy ( V_89 -> V_108 , F_64 ( & V_65 -> V_50 ) , 16 ) ;
V_89 -> V_109 = F_65 ( 1 ) ;
V_92 = F_66 ( (struct V_110 * ) V_89 ) ;
V_89 -> V_92 = F_63 ( V_92 ) ;
V_23 = F_67 ( V_65 , V_98 , V_89 , sizeof( * V_89 ) ) ;
if ( V_23 )
goto V_96;
return 0 ;
V_96:
V_87 -> V_89 = NULL ;
F_68 ( V_89 ) ;
return - V_111 ;
}
static int F_69 ( struct V_64 * V_65 )
{
struct V_87 * V_87 = F_70 ( V_65 -> V_84 ) ;
struct V_8 * V_9 ;
V_9 = F_54 ( & V_87 -> V_50 ) ;
F_36 ( V_9 ) ;
F_68 ( V_87 -> V_89 ) ;
V_87 -> V_89 = NULL ;
return 0 ;
}
static int F_71 ( struct V_64 * V_65 )
{
struct V_112 * V_113 = F_72 ( & V_65 -> V_50 ) ;
struct V_87 * V_87 = F_70 ( V_65 -> V_84 ) ;
struct V_49 * V_50 = & V_87 -> V_50 ;
struct V_90 * V_90 ;
struct V_114 * V_115 ;
struct V_88 * V_89 ;
struct V_8 * V_9 ;
struct V_20 * V_21 ;
T_2 V_45 ;
int V_23 ;
struct V_114 V_116 = {
. V_117 = F_73 ( V_113 -> V_52 . V_25 ) ,
. V_118 = F_73 ( V_97 ) ,
} ;
if ( ! V_87 -> V_107 || ! V_87 -> V_65 )
return - V_93 ;
V_90 = F_60 ( V_50 -> V_94 ) ;
V_23 = F_57 ( V_87 ) ;
if ( V_23 )
return V_23 ;
V_89 = V_87 -> V_89 ;
V_45 = F_74 ( V_89 -> V_103 ) ;
V_87 -> V_99 = F_75 ( V_87 -> V_89 -> V_99 ) ;
if ( V_87 -> V_99 == V_102 ) {
if ( V_45 < V_97 )
return - V_119 ;
V_87 -> V_91 = F_74 ( V_89 -> V_91 ) ;
V_115 = NULL ;
} else if ( V_87 -> V_99 == V_100 ) {
V_87 -> V_91 = ( F_24 ( & V_113 -> V_52 ) - V_45 )
/ V_69 ;
if ( F_74 ( V_87 -> V_89 -> V_91 ) > V_87 -> V_91 )
F_61 ( & V_87 -> V_50 ,
L_5 ,
F_74 ( V_87 -> V_89 -> V_91 ) ,
V_87 -> V_91 ) ;
V_115 = & V_116 ;
V_115 -> free = F_73 ( V_45 - V_97 ) ;
V_115 -> V_120 = 0 ;
} else {
V_23 = - V_111 ;
goto V_96;
}
V_9 = F_54 ( V_50 ) ;
V_21 = V_9 -> V_62 ;
F_76 ( V_50 , ( void V_61 * ) V_9 -> V_17 ) ;
V_9 -> V_17 = ( void T_3 * ) F_32 ( V_50 , & V_113 -> V_52 ,
& V_21 -> V_58 , V_115 ) ;
V_9 -> V_47 |= V_59 ;
if ( F_34 ( V_9 -> V_17 ) ) {
V_23 = F_77 ( V_9 -> V_17 ) ;
goto V_96;
}
V_9 -> V_15 = V_45 ;
V_23 = F_39 ( V_50 , V_65 , V_9 ) ;
if ( V_23 )
goto V_96;
return V_23 ;
V_96:
F_69 ( V_65 ) ;
return V_23 ;
}
static int F_78 ( struct V_49 * V_50 )
{
struct V_90 * V_90 = F_60 ( V_50 -> V_94 ) ;
struct V_64 * V_65 ;
struct V_112 * V_113 ;
struct V_8 * V_9 ;
V_65 = F_79 ( V_50 ) ;
if ( F_34 ( V_65 ) )
return F_77 ( V_65 ) ;
V_113 = F_72 ( & V_65 -> V_50 ) ;
V_9 = F_21 ( V_50 , & V_113 -> V_52 , V_90 -> V_53 ) ;
if ( F_34 ( V_9 ) )
return F_77 ( V_9 ) ;
V_9 -> V_65 = V_65 ;
F_80 ( V_50 , V_9 ) ;
V_65 -> V_121 = F_53 ;
if ( F_49 ( V_50 , & V_9 -> V_2 ) )
return - V_55 ;
F_50 ( V_65 , & V_9 -> V_2 , 0 ) ;
if ( F_81 ( V_50 ) ) {
F_35 ( V_9 -> V_62 ) ;
V_9 -> V_62 = NULL ;
return F_82 ( V_65 ) ;
}
if ( F_83 ( V_50 ) )
return F_71 ( V_65 ) ;
if ( F_84 ( V_65 , V_9 ) == 0 || F_85 ( V_65 , V_9 ) == 0 ) {
F_35 ( V_9 -> V_62 ) ;
return - V_111 ;
}
return F_39 ( V_50 , V_65 , V_9 ) ;
}
static int F_86 ( struct V_49 * V_50 )
{
struct V_8 * V_9 = F_54 ( V_50 ) ;
if ( F_81 ( V_50 ) )
F_87 ( V_9 -> V_65 ) ;
else if ( F_83 ( V_50 ) )
F_69 ( V_9 -> V_65 ) ;
else
F_36 ( V_9 ) ;
return 0 ;
}
static int T_9 F_88 ( void )
{
int error ;
V_74 = F_89 ( 0 , L_6 ) ;
if ( V_74 < 0 )
return V_74 ;
error = F_90 ( & V_122 ) ;
if ( error ) {
F_91 ( V_74 , L_6 ) ;
return error ;
}
return 0 ;
}
static void F_92 ( void )
{
F_93 ( & V_122 . V_123 ) ;
F_91 ( V_74 , L_6 ) ;
}
