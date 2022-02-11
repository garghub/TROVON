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
static void F_3 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned int V_4 )
{
struct V_11 * V_12 = F_4 ( V_9 -> V_13 ) ;
T_1 V_3 ;
long V_14 ;
V_3 = ( V_10 - V_9 -> V_15 ) / 512 ;
V_14 = F_5 ( V_12 , V_9 -> V_16 + V_10 , V_4 ) ;
if ( V_14 > 0 && V_14 / 512 ) {
F_6 ( V_12 , L_1 ,
V_17 , ( unsigned long long ) V_3 ,
V_14 / 512 , V_14 / 512 > 1 ? L_2 : L_3 ) ;
F_7 ( & V_9 -> V_2 , V_3 , V_14 / 512 ) ;
}
F_8 ( V_9 -> V_18 + V_10 , V_4 ) ;
}
static int F_9 ( struct V_8 * V_9 , struct V_19 * V_19 ,
unsigned int V_4 , unsigned int V_20 , int V_21 ,
T_1 V_3 )
{
int V_22 = 0 ;
bool V_23 = false ;
void * V_24 = F_10 ( V_19 ) ;
T_2 V_25 = V_3 * 512 + V_9 -> V_15 ;
void T_3 * V_26 = V_9 -> V_18 + V_25 ;
if ( F_11 ( F_1 ( & V_9 -> V_2 , V_3 , V_4 ) ) )
V_23 = true ;
if ( V_21 == V_27 ) {
if ( F_11 ( V_23 ) )
V_22 = - V_28 ;
else {
V_22 = F_12 ( V_24 + V_20 , V_26 , V_4 ) ;
F_13 ( V_19 ) ;
}
} else {
F_13 ( V_19 ) ;
F_14 ( V_26 , V_24 + V_20 , V_4 ) ;
if ( F_11 ( V_23 ) ) {
F_3 ( V_9 , V_25 , V_4 ) ;
F_14 ( V_26 , V_24 + V_20 , V_4 ) ;
}
}
F_15 ( V_24 ) ;
return V_22 ;
}
static T_4 F_16 ( struct V_29 * V_30 , struct V_31 * V_31 )
{
int V_22 = 0 ;
bool V_32 ;
unsigned long V_33 ;
struct V_34 V_35 ;
struct V_36 V_37 ;
struct V_38 * V_39 = V_31 -> V_40 ;
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
V_32 = F_17 ( V_31 , & V_33 ) ;
F_18 (bvec, bio, iter) {
V_22 = F_9 ( V_9 , V_35 . V_43 , V_35 . V_44 ,
V_35 . V_45 , F_19 ( V_31 ) ,
V_37 . V_46 ) ;
if ( V_22 ) {
V_31 -> V_47 = V_22 ;
break;
}
}
if ( V_32 )
F_20 ( V_31 , V_33 ) ;
if ( F_19 ( V_31 ) )
F_21 () ;
F_22 ( V_31 ) ;
return V_48 ;
}
static int F_23 ( struct V_38 * V_39 , T_1 V_3 ,
struct V_19 * V_19 , int V_21 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
int V_22 ;
V_22 = F_9 ( V_9 , V_19 , V_49 , 0 , V_21 , V_3 ) ;
if ( V_21 & V_50 )
F_21 () ;
if ( V_22 == 0 )
F_24 ( V_19 , V_21 & V_50 , 0 ) ;
return V_22 ;
}
static long F_25 ( struct V_38 * V_39 , T_1 V_3 ,
void T_3 * * V_51 , T_5 * V_52 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_42 ;
T_6 V_10 = V_3 * 512 + V_9 -> V_15 ;
* V_51 = V_9 -> V_18 + V_10 ;
* V_52 = F_26 ( V_9 -> V_16 + V_10 , V_9 -> V_53 ) ;
return V_9 -> V_54 - V_9 -> V_55 - V_10 ;
}
static struct V_8 * F_27 ( struct V_11 * V_12 ,
struct V_56 * V_57 , int V_58 )
{
struct V_8 * V_9 ;
struct V_29 * V_30 ;
V_9 = F_28 ( V_12 , sizeof( * V_9 ) , V_59 ) ;
if ( ! V_9 )
return F_29 ( - V_60 ) ;
V_9 -> V_16 = V_57 -> V_33 ;
V_9 -> V_54 = F_30 ( V_57 ) ;
if ( ! F_31 () )
F_32 ( V_12 , L_4 ) ;
if ( ! F_33 ( V_12 , V_9 -> V_16 , V_9 -> V_54 ,
F_34 ( V_12 ) ) ) {
F_32 ( V_12 , L_5 ,
& V_9 -> V_16 , V_9 -> V_54 ) ;
return F_29 ( - V_61 ) ;
}
V_30 = F_35 ( V_59 , F_36 ( V_12 ) ) ;
if ( ! V_30 )
return F_29 ( - V_60 ) ;
V_9 -> V_53 = V_62 ;
if ( F_37 ( V_12 ) ) {
V_9 -> V_18 = ( void T_3 * ) F_38 ( V_12 , V_57 ,
& V_30 -> V_63 , NULL ) ;
V_9 -> V_53 |= V_64 ;
} else
V_9 -> V_18 = ( void T_3 * ) F_39 ( V_12 ,
V_9 -> V_16 , V_9 -> V_54 ,
V_65 ) ;
if ( F_40 ( V_9 -> V_18 ) ) {
F_41 ( V_30 ) ;
return ( void V_66 * ) V_9 -> V_18 ;
}
V_9 -> V_67 = V_30 ;
return V_9 ;
}
static void F_42 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_13 )
return;
F_43 ( V_9 -> V_13 ) ;
F_44 ( V_9 -> V_13 ) ;
F_41 ( V_9 -> V_67 ) ;
}
static int F_45 ( struct V_11 * V_12 ,
struct V_68 * V_69 , struct V_8 * V_9 )
{
struct V_70 * V_71 = F_46 ( & V_69 -> V_12 ) ;
int V_72 = F_36 ( V_12 ) ;
struct V_56 V_73 ;
struct V_74 * V_75 ;
F_47 ( V_9 -> V_67 , F_16 ) ;
F_48 ( V_9 -> V_67 , V_49 ) ;
F_49 ( V_9 -> V_67 , V_76 ) ;
F_50 ( V_9 -> V_67 , V_77 ) ;
F_51 ( V_78 , V_9 -> V_67 ) ;
V_75 = F_52 ( 0 , V_72 ) ;
if ( ! V_75 ) {
F_41 ( V_9 -> V_67 ) ;
return - V_60 ;
}
V_75 -> V_79 = & V_80 ;
V_75 -> V_42 = V_9 ;
V_75 -> V_81 = V_9 -> V_67 ;
V_75 -> V_82 = V_83 ;
F_53 ( V_69 , V_75 -> V_84 ) ;
V_75 -> V_85 = V_12 ;
F_54 ( V_75 , ( V_9 -> V_54 - V_9 -> V_55 - V_9 -> V_15 )
/ 512 ) ;
V_9 -> V_13 = V_75 ;
F_55 ( V_12 , & V_9 -> V_2 ) ;
if ( F_56 ( V_12 , & V_9 -> V_2 ) )
return - V_60 ;
V_73 . V_33 = V_71 -> V_57 . V_33 + V_9 -> V_15 ;
V_73 . V_86 = V_71 -> V_57 . V_86 ;
if ( F_57 ( V_12 ) ) {
struct V_87 * V_87 = F_58 ( V_12 ) ;
struct V_88 * V_89 = V_87 -> V_89 ;
V_73 . V_33 += F_59 ( V_89 -> V_90 ) ;
V_73 . V_86 -= F_59 ( V_89 -> V_91 ) ;
}
F_60 ( F_61 ( V_12 -> V_92 ) , & V_9 -> V_2 ,
& V_73 ) ;
V_75 -> V_2 = & V_9 -> V_2 ;
F_62 ( V_75 ) ;
F_63 ( V_75 ) ;
return 0 ;
}
static int F_64 ( struct V_68 * V_69 ,
T_6 V_10 , void * V_93 , T_7 V_54 , int V_21 )
{
struct V_8 * V_9 = F_65 ( V_69 -> V_94 ) ;
if ( F_11 ( V_10 + V_54 > V_9 -> V_54 ) ) {
F_66 ( & V_69 -> V_12 , 1 , L_6 ) ;
return - V_95 ;
}
if ( V_21 == V_27 ) {
unsigned int V_96 = F_67 ( V_54 + ( V_10 & ( 512 - 1 ) ) , 512 ) ;
if ( F_11 ( F_1 ( & V_9 -> V_2 , V_10 / 512 , V_96 ) ) )
return - V_28 ;
return F_12 ( V_93 , V_9 -> V_18 + V_10 , V_54 ) ;
} else {
F_14 ( V_9 -> V_18 + V_10 , V_93 , V_54 ) ;
F_21 () ;
}
return 0 ;
}
static int F_68 ( struct V_87 * V_87 )
{
struct V_88 * V_89 = F_69 ( sizeof( * V_89 ) , V_59 ) ;
struct V_8 * V_9 = F_65 ( & V_87 -> V_12 ) ;
struct V_68 * V_69 = V_87 -> V_69 ;
T_8 V_90 = 0 , V_91 = 0 ;
T_6 V_33 , V_54 ;
struct V_70 * V_71 ;
struct V_97 * V_97 ;
unsigned long V_98 ;
T_2 V_10 ;
T_9 V_99 ;
int V_22 ;
if ( ! V_89 )
return - V_60 ;
V_87 -> V_89 = V_89 ;
V_22 = F_70 ( V_87 ) ;
if ( V_22 == - V_100 )
;
else
return V_22 ;
V_97 = F_61 ( V_87 -> V_12 . V_92 ) ;
if ( V_97 -> V_101 ) {
F_71 ( & V_87 -> V_12 ,
L_7 ,
F_34 ( & V_97 -> V_12 ) ) ;
goto V_102;
}
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_71 = F_46 ( & V_69 -> V_12 ) ;
V_33 = F_72 ( V_71 -> V_57 . V_33 ) ;
V_54 = F_30 ( & V_71 -> V_57 ) ;
if ( F_73 ( V_33 , V_54 , V_103 ,
V_104 ) == V_105 ) {
V_33 = V_71 -> V_57 . V_33 ;
V_90 = F_74 ( V_33 ) - V_33 ;
}
V_33 = V_71 -> V_57 . V_33 ;
V_54 = F_74 ( V_33 + V_54 ) - V_33 ;
if ( F_73 ( V_33 , V_54 , V_103 ,
V_104 ) == V_105 ) {
V_54 = F_30 ( & V_71 -> V_57 ) ;
V_91 = V_33 + V_54 - F_72 ( V_33 + V_54 ) ;
}
if ( V_90 + V_91 )
F_71 ( & V_87 -> V_12 , L_8 ,
F_34 ( & V_69 -> V_12 ) , V_90 + V_91 ) ;
V_33 += V_90 ;
V_98 = ( V_9 -> V_54 - V_90 - V_91 - V_106 ) / V_107 ;
if ( V_87 -> V_108 == V_109 ) {
unsigned long V_110 ;
V_110 = F_67 ( 64 * V_98 , V_111 ) ;
V_10 = F_67 ( V_33 + V_106 + V_110 , V_87 -> V_112 )
- V_33 ;
} else if ( V_87 -> V_108 == V_113 )
V_10 = F_67 ( V_33 + V_106 , V_87 -> V_112 ) - V_33 ;
else
goto V_102;
if ( V_10 + V_90 + V_91 >= V_9 -> V_54 ) {
F_75 ( & V_87 -> V_12 , L_9 ,
F_34 ( & V_69 -> V_12 ) ) ;
goto V_102;
}
V_98 = ( V_9 -> V_54 - V_10 - V_90 - V_91 ) / V_107 ;
V_89 -> V_108 = F_76 ( V_87 -> V_108 ) ;
V_89 -> V_114 = F_77 ( V_10 ) ;
V_89 -> V_98 = F_77 ( V_98 ) ;
memcpy ( V_89 -> V_115 , V_116 , V_117 ) ;
memcpy ( V_89 -> V_118 , V_87 -> V_118 , 16 ) ;
memcpy ( V_89 -> V_119 , F_78 ( & V_69 -> V_12 ) , 16 ) ;
V_89 -> V_120 = F_79 ( 1 ) ;
V_89 -> V_121 = F_79 ( 1 ) ;
V_89 -> V_90 = F_76 ( V_90 ) ;
V_89 -> V_91 = F_76 ( V_91 ) ;
V_99 = F_80 ( (struct V_122 * ) V_89 ) ;
V_89 -> V_99 = F_77 ( V_99 ) ;
V_22 = F_81 ( V_69 , V_107 , V_89 , sizeof( * V_89 ) ) ;
if ( V_22 )
goto V_102;
return 0 ;
V_102:
V_87 -> V_89 = NULL ;
F_82 ( V_89 ) ;
return - V_123 ;
}
static int F_83 ( struct V_68 * V_69 )
{
struct V_87 * V_87 = F_58 ( V_69 -> V_94 ) ;
struct V_8 * V_9 ;
V_9 = F_65 ( & V_87 -> V_12 ) ;
F_42 ( V_9 ) ;
F_82 ( V_87 -> V_89 ) ;
V_87 -> V_89 = NULL ;
return 0 ;
}
static unsigned long F_84 ( T_6 V_124 )
{
unsigned long V_125 = F_85 ( V_124 ) ;
return F_86 ( V_125 ) ;
}
static unsigned long F_87 ( T_6 V_124 )
{
unsigned long V_126 = F_85 ( V_106 ) ;
unsigned long V_125 = F_85 ( V_124 ) ;
V_126 += V_125 - F_86 ( V_125 ) ;
return V_126 ;
}
static int F_88 ( struct V_87 * V_87 )
{
int V_22 ;
struct V_56 V_57 ;
struct V_29 * V_30 ;
struct V_8 * V_9 ;
struct V_127 * V_128 ;
struct V_11 * V_12 = & V_87 -> V_12 ;
struct V_88 * V_89 = V_87 -> V_89 ;
struct V_68 * V_69 = V_87 -> V_69 ;
T_8 V_90 = F_59 ( V_89 -> V_90 ) ;
T_8 V_91 = F_59 ( V_89 -> V_91 ) ;
struct V_70 * V_71 = F_46 ( & V_69 -> V_12 ) ;
T_6 V_124 = V_71 -> V_57 . V_33 + V_90 ;
struct V_127 V_129 = {
. V_125 = F_84 ( V_124 ) ,
. V_126 = F_87 ( V_124 ) ,
} ;
V_9 = F_65 ( V_12 ) ;
V_9 -> V_15 = F_89 ( V_89 -> V_114 ) ;
V_9 -> V_55 = V_90 + V_91 ;
V_87 -> V_108 = F_90 ( V_87 -> V_89 -> V_108 ) ;
if ( V_87 -> V_108 == V_113 ) {
if ( V_9 -> V_15 < V_106 )
return - V_130 ;
V_87 -> V_98 = F_89 ( V_89 -> V_98 ) ;
V_128 = NULL ;
} else if ( V_87 -> V_108 == V_109 ) {
V_87 -> V_98 = ( V_9 -> V_54 - V_9 -> V_55 - V_9 -> V_15 )
/ V_49 ;
if ( F_89 ( V_87 -> V_89 -> V_98 ) > V_87 -> V_98 )
F_71 ( & V_87 -> V_12 ,
L_10 ,
F_89 ( V_87 -> V_89 -> V_98 ) ,
V_87 -> V_98 ) ;
V_128 = & V_129 ;
V_128 -> free = F_85 ( V_9 -> V_15 - V_106 ) ;
V_128 -> V_131 = 0 ;
} else {
V_22 = - V_123 ;
goto V_102;
}
V_30 = V_9 -> V_67 ;
memcpy ( & V_57 , & V_71 -> V_57 , sizeof( V_57 ) ) ;
V_57 . V_33 += V_90 ;
V_57 . V_86 -= V_91 ;
F_91 ( V_12 , ( void V_66 * ) V_9 -> V_18 ) ;
V_9 -> V_18 = ( void T_3 * ) F_38 ( V_12 , & V_57 ,
& V_30 -> V_63 , V_128 ) ;
V_9 -> V_53 |= V_64 ;
if ( F_40 ( V_9 -> V_18 ) ) {
V_22 = F_92 ( V_9 -> V_18 ) ;
goto V_102;
}
V_22 = F_45 ( V_12 , V_69 , V_9 ) ;
if ( V_22 )
goto V_102;
return V_22 ;
V_102:
F_83 ( V_69 ) ;
return V_22 ;
}
static int F_93 ( struct V_68 * V_69 )
{
struct V_87 * V_87 = F_58 ( V_69 -> V_94 ) ;
int V_22 ;
if ( ! V_87 -> V_118 || ! V_87 -> V_69 )
return - V_100 ;
V_22 = F_68 ( V_87 ) ;
if ( V_22 )
return V_22 ;
return F_88 ( V_87 ) ;
}
static int F_94 ( struct V_11 * V_12 )
{
struct V_97 * V_97 = F_61 ( V_12 -> V_92 ) ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_8 * V_9 ;
V_69 = F_95 ( V_12 ) ;
if ( F_40 ( V_69 ) )
return F_92 ( V_69 ) ;
V_71 = F_46 ( & V_69 -> V_12 ) ;
V_9 = F_27 ( V_12 , & V_71 -> V_57 , V_97 -> V_58 ) ;
if ( F_40 ( V_9 ) )
return F_92 ( V_9 ) ;
V_9 -> V_69 = V_69 ;
F_96 ( V_12 , V_9 ) ;
V_69 -> V_132 = F_64 ;
if ( F_56 ( V_12 , & V_9 -> V_2 ) )
return - V_60 ;
F_60 ( V_97 , & V_9 -> V_2 , & V_71 -> V_57 ) ;
if ( F_97 ( V_12 ) ) {
F_41 ( V_9 -> V_67 ) ;
V_9 -> V_67 = NULL ;
return F_98 ( V_69 ) ;
}
if ( F_57 ( V_12 ) )
return F_93 ( V_69 ) ;
if ( F_99 ( V_69 , V_9 ) == 0 || F_100 ( V_69 , V_9 ) == 0 ) {
F_41 ( V_9 -> V_67 ) ;
return - V_123 ;
}
return F_45 ( V_12 , V_69 , V_9 ) ;
}
static int F_101 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = F_65 ( V_12 ) ;
if ( F_97 ( V_12 ) )
F_102 ( V_9 -> V_69 ) ;
else if ( F_57 ( V_12 ) )
F_83 ( V_9 -> V_69 ) ;
else
F_42 ( V_9 ) ;
return 0 ;
}
static void F_103 ( struct V_11 * V_12 , enum V_133 V_134 )
{
struct V_8 * V_9 = F_65 ( V_12 ) ;
struct V_68 * V_69 = V_9 -> V_69 ;
struct V_97 * V_97 = F_61 ( V_12 -> V_92 ) ;
struct V_70 * V_71 = F_46 ( & V_69 -> V_12 ) ;
struct V_56 V_57 = {
. V_33 = V_71 -> V_57 . V_33 + V_9 -> V_15 ,
. V_86 = V_71 -> V_57 . V_86 ,
} ;
if ( V_134 != V_135 )
return;
if ( F_57 ( V_12 ) ) {
struct V_87 * V_87 = F_58 ( V_12 ) ;
struct V_88 * V_89 = V_87 -> V_89 ;
V_57 . V_33 += F_59 ( V_89 -> V_90 ) ;
V_57 . V_86 -= F_59 ( V_89 -> V_91 ) ;
}
F_60 ( V_97 , & V_9 -> V_2 , & V_57 ) ;
}
static int T_10 F_104 ( void )
{
return F_105 ( & V_136 ) ;
}
static void F_106 ( void )
{
F_107 ( & V_136 . V_137 ) ;
}
