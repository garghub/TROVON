static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
V_2 -> V_4 . V_5 ++ ;
V_2 -> V_4 . V_6 += V_3 ;
}
static void F_2 ( struct V_1 * V_2 ,
T_1 V_3 )
{
V_2 -> V_4 . V_5 -- ;
V_2 -> V_4 . V_6 -= V_3 ;
}
static int
F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_10 * V_11 = & V_2 -> V_12 ;
unsigned long V_13 ;
int V_14 ;
if ( ! F_4 ( & V_2 -> V_4 . V_15 ) )
return 0 ;
V_14 = F_5 ( V_11 ) ;
if ( V_14 )
return V_14 ;
if ( F_4 ( & V_2 -> V_4 . V_15 ) ) {
F_6 ( & V_11 -> V_16 . V_17 , V_13 ) ;
V_11 -> V_18 ++ ;
F_7 ( & V_11 -> V_16 . V_17 , V_13 ) ;
}
return 0 ;
}
int F_8 ( struct V_7 * V_8 )
{
int V_14 ;
V_14 = F_3 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_9 ( & V_8 -> V_19 ) ;
if ( V_14 )
return V_14 ;
F_10 ( F_11 ( V_8 ) ) ;
return 0 ;
}
static inline bool
F_12 ( struct V_20 * V_21 )
{
return V_21 -> V_22 && ! V_21 -> V_23 && V_21 -> V_24 == 0 ;
}
void F_13 ( struct V_7 * V_8 ,
unsigned long V_25 ,
unsigned long V_26 ,
unsigned long V_27 )
{
T_2 * V_2 = V_8 -> V_9 ;
F_14 ( & V_2 -> V_4 . V_22 , V_25 , V_27 - V_25 ) ;
V_2 -> V_4 . V_28 = V_25 ;
V_2 -> V_4 . V_29 = V_26 ;
V_2 -> V_4 . V_30 = V_27 ;
V_2 -> V_4 . V_31 = V_27 - V_25 ;
V_2 -> V_4 . V_32 = F_15 ( V_27 , V_26 ) - V_25 ;
F_16 ( V_25 / V_33 , ( V_27 - V_25 ) / V_33 ) ;
}
int
F_17 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * args = V_34 ;
if ( args -> V_28 >= args -> V_30 ||
( args -> V_30 | args -> V_28 ) & ( V_33 - 1 ) )
return - V_38 ;
F_18 ( & V_8 -> V_19 ) ;
F_13 ( V_8 , args -> V_28 , args -> V_30 , args -> V_30 ) ;
F_19 ( & V_8 -> V_19 ) ;
return 0 ;
}
int
F_20 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_39 * args = V_34 ;
struct V_20 * V_21 ;
T_1 V_40 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
V_40 = 0 ;
F_18 ( & V_8 -> V_19 ) ;
F_21 (obj, &dev_priv->mm.pinned_list, mm_list)
V_40 += V_21 -> V_22 -> V_3 ;
F_19 ( & V_8 -> V_19 ) ;
args -> V_45 = V_2 -> V_4 . V_31 ;
args -> V_46 = args -> V_45 - V_40 ;
return 0 ;
}
static int
F_22 ( struct V_35 * V_36 ,
struct V_7 * V_8 ,
T_3 V_3 ,
T_4 * V_47 )
{
struct V_20 * V_21 ;
int V_14 ;
T_5 V_48 ;
V_3 = F_23 ( V_3 , V_33 ) ;
if ( V_3 == 0 )
return - V_38 ;
V_21 = F_24 ( V_8 , V_3 ) ;
if ( V_21 == NULL )
return - V_49 ;
V_14 = F_25 ( V_36 , & V_21 -> V_50 , & V_48 ) ;
if ( V_14 ) {
F_26 ( & V_21 -> V_50 ) ;
F_2 ( V_8 -> V_9 , V_21 -> V_50 . V_3 ) ;
F_27 ( V_21 ) ;
return V_14 ;
}
F_28 ( & V_21 -> V_50 ) ;
F_29 ( V_21 ) ;
* V_47 = V_48 ;
return 0 ;
}
int
F_30 ( struct V_35 * V_36 ,
struct V_7 * V_8 ,
struct V_51 * args )
{
args -> V_52 = F_31 ( args -> V_53 * ( ( args -> V_54 + 7 ) / 8 ) , 64 ) ;
args -> V_3 = args -> V_52 * args -> V_55 ;
return F_22 ( V_36 , V_8 ,
args -> V_3 , & args -> V_48 ) ;
}
int F_32 ( struct V_35 * V_36 ,
struct V_7 * V_8 ,
T_4 V_48 )
{
return F_33 ( V_36 , V_48 ) ;
}
int
F_34 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_56 * args = V_34 ;
return F_22 ( V_36 , V_8 ,
args -> V_3 , & args -> V_48 ) ;
}
static int F_35 ( struct V_20 * V_21 )
{
T_2 * V_2 = V_21 -> V_50 . V_8 -> V_9 ;
return V_2 -> V_4 . V_57 == V_58 &&
V_21 -> V_59 != V_60 ;
}
static int
F_36 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_61 * args ,
struct V_35 * V_36 )
{
struct V_62 * V_63 = V_21 -> V_50 . V_64 -> V_65 . V_66 -> V_67 -> V_68 ;
T_6 V_69 ;
T_7 V_70 ;
char T_8 * V_71 ;
int V_72 , V_73 ;
V_71 = ( char T_8 * ) ( V_74 ) args -> V_75 ;
V_69 = args -> V_3 ;
V_70 = args -> V_70 ;
while ( V_69 > 0 ) {
struct V_76 * V_76 ;
char * V_77 ;
int V_14 ;
V_72 = F_37 ( V_70 ) ;
V_73 = V_69 ;
if ( ( V_72 + V_69 ) > V_33 )
V_73 = V_33 - V_72 ;
V_76 = F_38 ( V_63 , V_70 >> V_78 ) ;
if ( F_39 ( V_76 ) )
return F_40 ( V_76 ) ;
V_77 = F_41 ( V_76 ) ;
V_14 = F_42 ( V_71 ,
V_77 + V_72 ,
V_73 ) ;
F_43 ( V_77 ) ;
F_44 ( V_76 ) ;
F_45 ( V_76 ) ;
if ( V_14 )
return - V_79 ;
V_69 -= V_73 ;
V_71 += V_73 ;
V_70 += V_73 ;
}
return 0 ;
}
static inline int
F_46 ( char T_8 * V_80 ,
const char * V_81 , int V_82 ,
int V_83 )
{
int V_14 , V_84 = 0 ;
while ( V_83 > 0 ) {
int V_85 = F_31 ( V_82 + 1 , 64 ) ;
int V_86 = F_15 ( V_85 - V_82 , V_83 ) ;
int V_87 = V_82 ^ 64 ;
V_14 = F_47 ( V_80 + V_84 ,
V_81 + V_87 ,
V_86 ) ;
if ( V_14 )
return V_14 + V_83 ;
V_84 += V_86 ;
V_82 += V_86 ;
V_83 -= V_86 ;
}
return 0 ;
}
static inline int
F_48 ( char T_8 * V_81 , int V_82 ,
const char * V_80 ,
int V_83 )
{
int V_14 , V_84 = 0 ;
while ( V_83 > 0 ) {
int V_85 = F_31 ( V_82 + 1 , 64 ) ;
int V_86 = F_15 ( V_85 - V_82 , V_83 ) ;
int V_87 = V_82 ^ 64 ;
V_14 = F_49 ( V_81 + V_87 ,
V_80 + V_84 ,
V_86 ) ;
if ( V_14 )
return V_14 + V_83 ;
V_84 += V_86 ;
V_82 += V_86 ;
V_83 -= V_86 ;
}
return 0 ;
}
static int
F_50 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_61 * args ,
struct V_35 * V_36 )
{
struct V_62 * V_63 = V_21 -> V_50 . V_64 -> V_65 . V_66 -> V_67 -> V_68 ;
char T_8 * V_71 ;
T_6 V_69 ;
T_7 V_70 ;
int V_88 , V_73 , V_14 ;
int V_89 , V_90 ;
V_71 = ( char T_8 * ) ( V_74 ) args -> V_75 ;
V_69 = args -> V_3 ;
V_89 = F_35 ( V_21 ) ;
V_70 = args -> V_70 ;
F_19 ( & V_8 -> V_19 ) ;
while ( V_69 > 0 ) {
struct V_76 * V_76 ;
char * V_77 ;
V_88 = F_37 ( V_70 ) ;
V_73 = V_69 ;
if ( ( V_88 + V_73 ) > V_33 )
V_73 = V_33 - V_88 ;
V_76 = F_38 ( V_63 , V_70 >> V_78 ) ;
if ( F_39 ( V_76 ) ) {
V_14 = F_40 ( V_76 ) ;
goto V_91;
}
V_90 = V_89 &&
( F_51 ( V_76 ) & ( 1 << 17 ) ) != 0 ;
V_77 = F_52 ( V_76 ) ;
if ( V_90 )
V_14 = F_46 ( V_71 ,
V_77 , V_88 ,
V_73 ) ;
else
V_14 = F_47 ( V_71 ,
V_77 + V_88 ,
V_73 ) ;
F_53 ( V_76 ) ;
F_44 ( V_76 ) ;
F_45 ( V_76 ) ;
if ( V_14 ) {
V_14 = - V_79 ;
goto V_91;
}
V_69 -= V_73 ;
V_71 += V_73 ;
V_70 += V_73 ;
}
V_91:
F_18 ( & V_8 -> V_19 ) ;
if ( V_21 -> V_92 == V_93 )
F_54 ( V_21 ) ;
return V_14 ;
}
int
F_55 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_61 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 = 0 ;
if ( args -> V_3 == 0 )
return 0 ;
if ( ! F_56 ( V_94 ,
( char T_8 * ) ( V_74 ) args -> V_75 ,
args -> V_3 ) )
return - V_79 ;
V_14 = F_57 ( ( char T_8 * ) ( V_74 ) args -> V_75 ,
args -> V_3 ) ;
if ( V_14 )
return - V_79 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_58 ( F_59 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( args -> V_70 > V_21 -> V_50 . V_3 ||
args -> V_3 > V_21 -> V_50 . V_3 - args -> V_70 ) {
V_14 = - V_38 ;
goto V_91;
}
F_60 ( V_21 , args -> V_70 , args -> V_3 ) ;
V_14 = F_61 ( V_21 ,
args -> V_70 ,
args -> V_3 ) ;
if ( V_14 )
goto V_91;
V_14 = - V_79 ;
if ( ! F_35 ( V_21 ) )
V_14 = F_36 ( V_8 , V_21 , args , V_36 ) ;
if ( V_14 == - V_79 )
V_14 = F_50 ( V_8 , V_21 , args , V_36 ) ;
V_91:
F_28 ( & V_21 -> V_50 ) ;
V_96:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
static inline int
F_62 ( struct V_97 * V_63 ,
T_7 V_98 , int V_72 ,
char T_8 * V_71 ,
int V_83 )
{
char * V_99 ;
unsigned long V_100 ;
V_99 = F_63 ( V_63 , V_98 ) ;
V_100 = F_64 ( V_99 + V_72 ,
V_71 , V_83 ) ;
F_65 ( V_99 ) ;
return V_100 ;
}
static inline void
F_66 ( struct V_97 * V_63 ,
T_7 V_101 , int V_102 ,
struct V_76 * V_103 , int V_104 ,
int V_83 )
{
char T_9 * V_105 ;
char * V_106 ;
V_105 = F_67 ( V_63 , V_101 ) ;
V_106 = F_52 ( V_103 ) ;
F_68 ( V_105 + V_102 ,
V_106 + V_104 ,
V_83 ) ;
F_53 ( V_103 ) ;
F_69 ( V_105 ) ;
}
static int
F_70 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_107 * args ,
struct V_35 * V_36 )
{
T_2 * V_2 = V_8 -> V_9 ;
T_6 V_69 ;
T_7 V_70 , V_98 ;
char T_8 * V_71 ;
int V_72 , V_73 ;
V_71 = ( char T_8 * ) ( V_74 ) args -> V_75 ;
V_69 = args -> V_3 ;
V_70 = V_21 -> V_102 + args -> V_70 ;
while ( V_69 > 0 ) {
V_98 = V_70 & V_108 ;
V_72 = F_37 ( V_70 ) ;
V_73 = V_69 ;
if ( ( V_72 + V_69 ) > V_33 )
V_73 = V_33 - V_72 ;
if ( F_62 ( V_2 -> V_4 . V_109 , V_98 ,
V_72 , V_71 , V_73 ) )
return - V_79 ;
V_69 -= V_73 ;
V_71 += V_73 ;
V_70 += V_73 ;
}
return 0 ;
}
static int
F_71 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_107 * args ,
struct V_35 * V_36 )
{
T_2 * V_2 = V_8 -> V_9 ;
T_6 V_69 ;
T_7 V_110 , V_70 ;
T_7 V_111 , V_112 , V_113 ;
T_7 V_114 , V_115 ;
struct V_76 * * V_116 ;
struct V_117 * V_4 = V_118 -> V_4 ;
int V_119 , V_120 , V_121 , V_73 ;
int V_14 ;
T_3 V_75 = args -> V_75 ;
V_69 = args -> V_3 ;
V_111 = V_75 / V_33 ;
V_112 = ( V_75 + args -> V_3 - 1 ) / V_33 ;
V_113 = V_112 - V_111 + 1 ;
V_116 = F_72 ( V_113 , sizeof( struct V_76 * ) ) ;
if ( V_116 == NULL )
return - V_49 ;
F_19 ( & V_8 -> V_19 ) ;
F_73 ( & V_4 -> V_122 ) ;
V_114 = F_74 ( V_118 , V_4 , ( V_74 ) args -> V_75 ,
V_113 , 0 , 0 , V_116 , NULL ) ;
F_75 ( & V_4 -> V_122 ) ;
F_18 ( & V_8 -> V_19 ) ;
if ( V_114 < V_113 ) {
V_14 = - V_79 ;
goto V_123;
}
V_14 = F_76 ( V_21 , true ) ;
if ( V_14 )
goto V_123;
V_14 = F_77 ( V_21 ) ;
if ( V_14 )
goto V_123;
V_70 = V_21 -> V_102 + args -> V_70 ;
while ( V_69 > 0 ) {
V_110 = V_70 & V_108 ;
V_119 = F_37 ( V_70 ) ;
V_121 = V_75 / V_33 - V_111 ;
V_120 = F_37 ( V_75 ) ;
V_73 = V_69 ;
if ( ( V_119 + V_73 ) > V_33 )
V_73 = V_33 - V_119 ;
if ( ( V_120 + V_73 ) > V_33 )
V_73 = V_33 - V_120 ;
F_66 ( V_2 -> V_4 . V_109 ,
V_110 , V_119 ,
V_116 [ V_121 ] ,
V_120 ,
V_73 ) ;
V_69 -= V_73 ;
V_70 += V_73 ;
V_75 += V_73 ;
}
V_123:
for ( V_115 = 0 ; V_115 < V_114 ; V_115 ++ )
F_45 ( V_116 [ V_115 ] ) ;
F_78 ( V_116 ) ;
return V_14 ;
}
static int
F_79 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_107 * args ,
struct V_35 * V_36 )
{
struct V_62 * V_63 = V_21 -> V_50 . V_64 -> V_65 . V_66 -> V_67 -> V_68 ;
T_6 V_69 ;
T_7 V_70 ;
char T_8 * V_71 ;
int V_72 , V_73 ;
V_71 = ( char T_8 * ) ( V_74 ) args -> V_75 ;
V_69 = args -> V_3 ;
V_70 = args -> V_70 ;
V_21 -> V_124 = 1 ;
while ( V_69 > 0 ) {
struct V_76 * V_76 ;
char * V_77 ;
int V_14 ;
V_72 = F_37 ( V_70 ) ;
V_73 = V_69 ;
if ( ( V_72 + V_69 ) > V_33 )
V_73 = V_33 - V_72 ;
V_76 = F_38 ( V_63 , V_70 >> V_78 ) ;
if ( F_39 ( V_76 ) )
return F_40 ( V_76 ) ;
V_77 = F_41 ( V_76 ) ;
V_14 = F_80 ( V_77 + V_72 ,
V_71 ,
V_73 ) ;
F_43 ( V_77 ) ;
F_81 ( V_76 ) ;
F_44 ( V_76 ) ;
F_45 ( V_76 ) ;
if ( V_14 )
return - V_79 ;
V_69 -= V_73 ;
V_71 += V_73 ;
V_70 += V_73 ;
}
return 0 ;
}
static int
F_82 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_107 * args ,
struct V_35 * V_36 )
{
struct V_62 * V_63 = V_21 -> V_50 . V_64 -> V_65 . V_66 -> V_67 -> V_68 ;
T_6 V_69 ;
T_7 V_70 ;
char T_8 * V_71 ;
int V_88 , V_73 , V_14 ;
int V_89 , V_90 ;
V_71 = ( char T_8 * ) ( V_74 ) args -> V_75 ;
V_69 = args -> V_3 ;
V_89 = F_35 ( V_21 ) ;
V_70 = args -> V_70 ;
V_21 -> V_124 = 1 ;
F_19 ( & V_8 -> V_19 ) ;
while ( V_69 > 0 ) {
struct V_76 * V_76 ;
char * V_77 ;
V_88 = F_37 ( V_70 ) ;
V_73 = V_69 ;
if ( ( V_88 + V_73 ) > V_33 )
V_73 = V_33 - V_88 ;
V_76 = F_38 ( V_63 , V_70 >> V_78 ) ;
if ( F_39 ( V_76 ) ) {
V_14 = F_40 ( V_76 ) ;
goto V_91;
}
V_90 = V_89 &&
( F_51 ( V_76 ) & ( 1 << 17 ) ) != 0 ;
V_77 = F_52 ( V_76 ) ;
if ( V_90 )
V_14 = F_48 ( V_77 , V_88 ,
V_71 ,
V_73 ) ;
else
V_14 = F_49 ( V_77 + V_88 ,
V_71 ,
V_73 ) ;
F_53 ( V_76 ) ;
F_81 ( V_76 ) ;
F_44 ( V_76 ) ;
F_45 ( V_76 ) ;
if ( V_14 ) {
V_14 = - V_79 ;
goto V_91;
}
V_69 -= V_73 ;
V_71 += V_73 ;
V_70 += V_73 ;
}
V_91:
F_18 ( & V_8 -> V_19 ) ;
if ( V_21 -> V_92 == V_93 )
F_54 ( V_21 ) ;
if ( V_21 -> V_50 . V_125 != V_126 ) {
F_83 ( V_21 ) ;
F_84 () ;
}
return V_14 ;
}
int
F_85 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_107 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 ;
if ( args -> V_3 == 0 )
return 0 ;
if ( ! F_56 ( V_127 ,
( char T_8 * ) ( V_74 ) args -> V_75 ,
args -> V_3 ) )
return - V_79 ;
V_14 = F_86 ( ( char T_8 * ) ( V_74 ) args -> V_75 ,
args -> V_3 ) ;
if ( V_14 )
return - V_79 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_58 ( F_59 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( args -> V_70 > V_21 -> V_50 . V_3 ||
args -> V_3 > V_21 -> V_50 . V_3 - args -> V_70 ) {
V_14 = - V_38 ;
goto V_91;
}
F_87 ( V_21 , args -> V_70 , args -> V_3 ) ;
if ( V_21 -> V_128 ) {
V_14 = F_88 ( V_8 , V_21 , args , V_36 ) ;
goto V_91;
}
if ( V_21 -> V_22 &&
V_21 -> V_50 . V_125 != V_126 ) {
V_14 = F_89 ( V_21 , 0 , true ) ;
if ( V_14 )
goto V_91;
V_14 = F_76 ( V_21 , true ) ;
if ( V_14 )
goto V_129;
V_14 = F_77 ( V_21 ) ;
if ( V_14 )
goto V_129;
V_14 = F_70 ( V_8 , V_21 , args , V_36 ) ;
if ( V_14 == - V_79 )
V_14 = F_71 ( V_8 , V_21 , args , V_36 ) ;
V_129:
F_90 ( V_21 ) ;
if ( V_14 != - V_79 )
goto V_91;
}
V_14 = F_91 ( V_21 , 1 ) ;
if ( V_14 )
goto V_91;
V_14 = - V_79 ;
if ( ! F_35 ( V_21 ) )
V_14 = F_79 ( V_8 , V_21 , args , V_36 ) ;
if ( V_14 == - V_79 )
V_14 = F_82 ( V_8 , V_21 , args , V_36 ) ;
V_91:
F_28 ( & V_21 -> V_50 ) ;
V_96:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_92 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_130 * args = V_34 ;
struct V_20 * V_21 ;
T_4 V_131 = args -> V_131 ;
T_4 V_125 = args -> V_125 ;
int V_14 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
if ( V_125 & V_132 )
return - V_38 ;
if ( V_131 & V_132 )
return - V_38 ;
if ( V_125 != 0 && V_131 != V_125 )
return - V_38 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_58 ( F_59 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( V_131 & V_133 ) {
V_14 = F_76 ( V_21 , V_125 != 0 ) ;
if ( V_14 == - V_38 )
V_14 = 0 ;
} else {
V_14 = F_91 ( V_21 , V_125 != 0 ) ;
}
F_28 ( & V_21 -> V_50 ) ;
V_96:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_93 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_134 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 = 0 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_58 ( F_59 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( V_21 -> V_24 )
F_94 ( V_21 ) ;
F_28 ( & V_21 -> V_50 ) ;
V_96:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_95 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_135 * args = V_34 ;
struct V_136 * V_21 ;
unsigned long V_137 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
V_21 = F_59 ( V_8 , V_36 , args -> V_48 ) ;
if ( V_21 == NULL )
return - V_95 ;
V_137 = F_96 ( V_21 -> V_64 , 0 , args -> V_3 ,
V_138 | V_139 , V_140 ,
args -> V_70 ) ;
F_97 ( V_21 ) ;
if ( F_39 ( ( void * ) V_137 ) )
return V_137 ;
args -> V_141 = ( T_3 ) V_137 ;
return 0 ;
}
int F_98 ( struct V_142 * V_143 , struct V_144 * V_145 )
{
struct V_20 * V_21 = F_58 ( V_143 -> V_146 ) ;
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_10 V_72 ;
unsigned long V_147 ;
int V_14 = 0 ;
bool V_148 = ! ! ( V_145 -> V_13 & V_149 ) ;
V_72 = ( ( unsigned long ) V_145 -> V_150 - V_143 -> V_151 ) >>
V_78 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
goto V_91;
F_99 ( V_21 , V_72 , true , V_148 ) ;
if ( ! V_21 -> V_152 ) {
V_14 = F_100 ( V_21 ) ;
if ( V_14 )
goto V_96;
}
if ( ! V_21 -> V_22 ) {
V_14 = F_101 ( V_21 , 0 , true ) ;
if ( V_14 )
goto V_96;
V_14 = F_76 ( V_21 , V_148 ) ;
if ( V_14 )
goto V_96;
}
if ( V_21 -> V_59 == V_60 )
V_14 = F_77 ( V_21 ) ;
else
V_14 = F_102 ( V_21 , NULL ) ;
if ( V_14 )
goto V_96;
if ( F_12 ( V_21 ) )
F_103 ( & V_21 -> V_153 , & V_2 -> V_4 . V_154 ) ;
V_21 -> V_155 = true ;
V_147 = ( ( V_8 -> V_156 -> V_50 + V_21 -> V_102 ) >> V_78 ) +
V_72 ;
V_14 = F_104 ( V_143 , ( unsigned long ) V_145 -> V_150 , V_147 ) ;
V_96:
F_19 ( & V_8 -> V_19 ) ;
V_91:
switch ( V_14 ) {
case - V_157 :
case - V_158 :
F_105 () ;
case 0 :
case - V_159 :
case - V_160 :
return V_161 ;
case - V_49 :
return V_162 ;
default:
return V_163 ;
}
}
void
F_106 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_155 )
return;
if ( V_21 -> V_50 . V_8 -> V_164 )
F_107 ( V_21 -> V_50 . V_8 -> V_164 ,
( T_7 ) V_21 -> V_50 . V_165 . V_166 . V_167 << V_78 ,
V_21 -> V_50 . V_3 , 1 ) ;
V_21 -> V_155 = false ;
}
static T_4
F_108 ( struct V_7 * V_8 , T_4 V_3 , int V_59 )
{
T_4 V_168 ;
if ( F_109 ( V_8 ) -> V_169 >= 4 ||
V_59 == V_60 )
return V_3 ;
if ( F_109 ( V_8 ) -> V_169 == 3 )
V_168 = 1024 * 1024 ;
else
V_168 = 512 * 1024 ;
while ( V_168 < V_3 )
V_168 <<= 1 ;
return V_168 ;
}
static T_4
F_110 ( struct V_7 * V_8 ,
T_4 V_3 ,
int V_59 )
{
if ( F_109 ( V_8 ) -> V_169 >= 4 ||
V_59 == V_60 )
return 4096 ;
return F_108 ( V_8 , V_3 , V_59 ) ;
}
T_4
F_111 ( struct V_7 * V_8 ,
T_4 V_3 ,
int V_59 )
{
if ( F_109 ( V_8 ) -> V_169 >= 4 || F_112 ( V_8 ) ||
V_59 == V_60 )
return 4096 ;
return F_108 ( V_8 , V_3 , V_59 ) ;
}
int
F_113 ( struct V_35 * V_36 ,
struct V_7 * V_8 ,
T_4 V_48 ,
T_3 * V_70 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_20 * V_21 ;
int V_14 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_58 ( F_59 ( V_8 , V_36 , V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( V_21 -> V_50 . V_3 > V_2 -> V_4 . V_29 ) {
V_14 = - V_170 ;
goto V_91;
}
if ( V_21 -> V_92 != V_171 ) {
F_114 ( L_1 ) ;
V_14 = - V_38 ;
goto V_91;
}
if ( ! V_21 -> V_50 . V_165 . V_172 ) {
V_14 = F_115 ( & V_21 -> V_50 ) ;
if ( V_14 )
goto V_91;
}
* V_70 = ( V_173 ) V_21 -> V_50 . V_165 . V_166 . V_167 << V_78 ;
V_91:
F_28 ( & V_21 -> V_50 ) ;
V_96:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_116 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_174 * args = V_34 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
return F_113 ( V_36 , V_8 , args -> V_48 , & args -> V_70 ) ;
}
static int
F_117 ( struct V_20 * V_21 ,
T_11 V_175 )
{
int V_176 , V_115 ;
struct V_62 * V_63 ;
struct V_177 * V_177 ;
struct V_76 * V_76 ;
V_176 = V_21 -> V_50 . V_3 / V_33 ;
F_118 ( V_21 -> V_178 != NULL ) ;
V_21 -> V_178 = F_72 ( V_176 , sizeof( struct V_76 * ) ) ;
if ( V_21 -> V_178 == NULL )
return - V_49 ;
V_177 = V_21 -> V_50 . V_64 -> V_65 . V_66 -> V_67 ;
V_63 = V_177 -> V_68 ;
V_175 |= F_119 ( V_63 ) ;
for ( V_115 = 0 ; V_115 < V_176 ; V_115 ++ ) {
V_76 = F_120 ( V_63 , V_115 , V_175 ) ;
if ( F_39 ( V_76 ) )
goto V_179;
V_21 -> V_178 [ V_115 ] = V_76 ;
}
if ( F_35 ( V_21 ) )
F_121 ( V_21 ) ;
return 0 ;
V_179:
while ( V_115 -- )
F_45 ( V_21 -> V_178 [ V_115 ] ) ;
F_78 ( V_21 -> V_178 ) ;
V_21 -> V_178 = NULL ;
return F_40 ( V_76 ) ;
}
static void
F_122 ( struct V_20 * V_21 )
{
int V_176 = V_21 -> V_50 . V_3 / V_33 ;
int V_115 ;
F_118 ( V_21 -> V_92 == V_93 ) ;
if ( F_35 ( V_21 ) )
F_123 ( V_21 ) ;
if ( V_21 -> V_92 == V_180 )
V_21 -> V_124 = 0 ;
for ( V_115 = 0 ; V_115 < V_176 ; V_115 ++ ) {
if ( V_21 -> V_124 )
F_81 ( V_21 -> V_178 [ V_115 ] ) ;
if ( V_21 -> V_92 == V_171 )
F_44 ( V_21 -> V_178 [ V_115 ] ) ;
F_45 ( V_21 -> V_178 [ V_115 ] ) ;
}
V_21 -> V_124 = 0 ;
F_78 ( V_21 -> V_178 ) ;
V_21 -> V_178 = NULL ;
}
void
F_124 ( struct V_20 * V_21 ,
struct V_181 * V_182 ,
T_5 V_183 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
F_118 ( V_182 == NULL ) ;
V_21 -> V_182 = V_182 ;
if ( ! V_21 -> V_23 ) {
F_125 ( & V_21 -> V_50 ) ;
V_21 -> V_23 = 1 ;
}
F_103 ( & V_21 -> V_153 , & V_2 -> V_4 . V_184 ) ;
F_103 ( & V_21 -> V_185 , & V_182 -> V_184 ) ;
V_21 -> V_186 = V_183 ;
if ( V_21 -> V_187 ) {
V_21 -> V_188 = V_183 ;
V_21 -> V_189 = V_182 ;
if ( V_21 -> V_190 != V_191 ) {
struct V_192 * V_193 ;
V_193 = & V_2 -> V_194 [ V_21 -> V_190 ] ;
F_103 ( & V_193 -> V_195 ,
& V_2 -> V_4 . V_196 ) ;
}
}
}
static void
F_126 ( struct V_20 * V_21 )
{
F_127 ( & V_21 -> V_185 ) ;
V_21 -> V_186 = 0 ;
V_21 -> V_188 = 0 ;
}
static void
F_128 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
F_118 ( ! V_21 -> V_23 ) ;
F_103 ( & V_21 -> V_153 , & V_2 -> V_4 . V_197 ) ;
F_126 ( V_21 ) ;
}
static void
F_129 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
if ( V_21 -> V_24 != 0 )
F_103 ( & V_21 -> V_153 , & V_2 -> V_4 . V_198 ) ;
else
F_103 ( & V_21 -> V_153 , & V_2 -> V_4 . V_154 ) ;
F_118 ( ! F_130 ( & V_21 -> V_199 ) ) ;
F_118 ( ! V_21 -> V_23 ) ;
V_21 -> V_182 = NULL ;
V_21 -> V_189 = NULL ;
F_126 ( V_21 ) ;
V_21 -> V_187 = false ;
V_21 -> V_23 = 0 ;
V_21 -> V_200 = false ;
F_28 ( & V_21 -> V_50 ) ;
F_10 ( F_11 ( V_8 ) ) ;
}
static void
F_54 ( struct V_20 * V_21 )
{
struct V_177 * V_177 ;
V_177 = V_21 -> V_50 . V_64 -> V_65 . V_66 -> V_67 ;
F_131 ( V_177 , 0 , ( T_7 ) - 1 ) ;
V_21 -> V_92 = V_93 ;
}
static inline int
F_132 ( struct V_20 * V_21 )
{
return V_21 -> V_92 == V_180 ;
}
static void
F_133 ( struct V_181 * V_182 ,
T_4 V_201 )
{
struct V_20 * V_21 , * V_202 ;
F_134 (obj, next,
&ring->gpu_write_list,
gpu_write_list) {
if ( V_21 -> V_50 . V_125 & V_201 ) {
T_4 V_203 = V_21 -> V_50 . V_125 ;
V_21 -> V_50 . V_125 = 0 ;
F_127 ( & V_21 -> V_199 ) ;
F_124 ( V_21 , V_182 ,
F_135 ( V_182 ) ) ;
F_136 ( V_21 ,
V_21 -> V_50 . V_131 ,
V_203 ) ;
}
}
}
static T_5
F_137 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_183 = V_2 -> V_204 ;
if ( ++ V_2 -> V_204 == 0 )
V_2 -> V_204 = 1 ;
return V_183 ;
}
T_5
F_135 ( struct V_181 * V_182 )
{
if ( V_182 -> V_205 == 0 )
V_182 -> V_205 = F_137 ( V_182 -> V_8 ) ;
return V_182 -> V_205 ;
}
int
F_138 ( struct V_181 * V_182 ,
struct V_35 * V_36 ,
struct V_206 * V_207 )
{
T_2 * V_2 = V_182 -> V_8 -> V_9 ;
T_4 V_183 ;
T_5 V_208 ;
int V_209 ;
int V_14 ;
F_118 ( V_207 == NULL ) ;
V_183 = F_135 ( V_182 ) ;
V_208 = F_139 ( V_182 ) ;
V_14 = V_182 -> V_210 ( V_182 , & V_183 ) ;
if ( V_14 )
return V_14 ;
F_140 ( V_182 , V_183 ) ;
V_207 -> V_183 = V_183 ;
V_207 -> V_182 = V_182 ;
V_207 -> V_211 = V_208 ;
V_207 -> V_212 = V_213 ;
V_209 = F_130 ( & V_182 -> V_214 ) ;
F_141 ( & V_207 -> V_215 , & V_182 -> V_214 ) ;
if ( V_36 ) {
struct V_216 * V_217 = V_36 -> V_218 ;
F_142 ( & V_217 -> V_4 . V_17 ) ;
V_207 -> V_217 = V_217 ;
F_141 ( & V_207 -> V_219 ,
& V_217 -> V_4 . V_214 ) ;
F_143 ( & V_217 -> V_4 . V_17 ) ;
}
V_182 -> V_205 = 0 ;
if ( ! V_2 -> V_4 . V_220 ) {
if ( V_221 ) {
F_144 ( & V_2 -> V_222 ,
V_213 +
F_145 ( V_223 ) ) ;
}
if ( V_209 )
F_146 ( V_2 -> V_224 ,
& V_2 -> V_4 . V_225 , V_226 ) ;
}
return 0 ;
}
static inline void
F_147 ( struct V_206 * V_207 )
{
struct V_216 * V_217 = V_207 -> V_217 ;
if ( ! V_217 )
return;
F_142 ( & V_217 -> V_4 . V_17 ) ;
if ( V_207 -> V_217 ) {
F_148 ( & V_207 -> V_219 ) ;
V_207 -> V_217 = NULL ;
}
F_143 ( & V_217 -> V_4 . V_17 ) ;
}
static void F_149 ( struct V_1 * V_2 ,
struct V_181 * V_182 )
{
while ( ! F_130 ( & V_182 -> V_214 ) ) {
struct V_206 * V_207 ;
V_207 = F_150 ( & V_182 -> V_214 ,
struct V_206 ,
V_215 ) ;
F_148 ( & V_207 -> V_215 ) ;
F_147 ( V_207 ) ;
F_27 ( V_207 ) ;
}
while ( ! F_130 ( & V_182 -> V_184 ) ) {
struct V_20 * V_21 ;
V_21 = F_150 ( & V_182 -> V_184 ,
struct V_20 ,
V_185 ) ;
V_21 -> V_50 . V_125 = 0 ;
F_127 ( & V_21 -> V_199 ) ;
F_129 ( V_21 ) ;
}
}
static void F_151 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
int V_115 ;
for ( V_115 = 0 ; V_115 < V_2 -> V_227 ; V_115 ++ ) {
struct V_192 * V_193 = & V_2 -> V_194 [ V_115 ] ;
struct V_20 * V_21 = V_193 -> V_21 ;
if ( ! V_21 )
continue;
if ( V_21 -> V_59 )
F_106 ( V_21 ) ;
V_193 -> V_21 -> V_190 = V_191 ;
V_193 -> V_21 -> V_187 = false ;
V_193 -> V_21 -> V_188 = 0 ;
V_193 -> V_21 -> V_189 = NULL ;
F_152 ( V_8 , V_193 ) ;
}
}
void F_153 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_20 * V_21 ;
int V_115 ;
for ( V_115 = 0 ; V_115 < V_228 ; V_115 ++ )
F_149 ( V_2 , & V_2 -> V_182 [ V_115 ] ) ;
while ( ! F_130 ( & V_2 -> V_4 . V_197 ) ) {
V_21 = F_150 ( & V_2 -> V_4 . V_197 ,
struct V_20 ,
V_153 ) ;
V_21 -> V_50 . V_125 = 0 ;
F_127 ( & V_21 -> V_199 ) ;
F_129 ( V_21 ) ;
}
F_21 (obj,
&dev_priv->mm.inactive_list,
mm_list)
{
V_21 -> V_50 . V_131 &= ~ V_132 ;
}
F_151 ( V_8 ) ;
}
void
F_154 ( struct V_181 * V_182 )
{
T_4 V_183 ;
int V_115 ;
if ( F_130 ( & V_182 -> V_214 ) )
return;
F_10 ( F_11 ( V_182 -> V_8 ) ) ;
V_183 = V_182 -> V_229 ( V_182 ) ;
for ( V_115 = 0 ; V_115 < F_155 ( V_182 -> V_230 ) ; V_115 ++ )
if ( V_183 >= V_182 -> V_230 [ V_115 ] )
V_182 -> V_230 [ V_115 ] = 0 ;
while ( ! F_130 ( & V_182 -> V_214 ) ) {
struct V_206 * V_207 ;
V_207 = F_150 ( & V_182 -> V_214 ,
struct V_206 ,
V_215 ) ;
if ( ! F_156 ( V_183 , V_207 -> V_183 ) )
break;
F_157 ( V_182 , V_207 -> V_183 ) ;
V_182 -> V_231 = V_207 -> V_211 ;
F_148 ( & V_207 -> V_215 ) ;
F_147 ( V_207 ) ;
F_27 ( V_207 ) ;
}
while ( ! F_130 ( & V_182 -> V_184 ) ) {
struct V_20 * V_21 ;
V_21 = F_150 ( & V_182 -> V_184 ,
struct V_20 ,
V_185 ) ;
if ( ! F_156 ( V_183 , V_21 -> V_186 ) )
break;
if ( V_21 -> V_50 . V_125 != 0 )
F_128 ( V_21 ) ;
else
F_129 ( V_21 ) ;
}
if ( F_158 ( V_182 -> V_232 &&
F_156 ( V_183 , V_182 -> V_232 ) ) ) {
V_182 -> V_233 ( V_182 ) ;
V_182 -> V_232 = 0 ;
}
F_10 ( F_11 ( V_182 -> V_8 ) ) ;
}
void
F_159 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_115 ;
if ( ! F_130 ( & V_2 -> V_4 . V_234 ) ) {
struct V_20 * V_21 , * V_202 ;
F_134 (obj, next,
&dev_priv->mm.deferred_free_list,
mm_list)
F_160 ( V_21 ) ;
}
for ( V_115 = 0 ; V_115 < V_228 ; V_115 ++ )
F_154 ( & V_2 -> V_182 [ V_115 ] ) ;
}
static void
F_161 ( struct V_235 * V_236 )
{
T_2 * V_2 ;
struct V_7 * V_8 ;
bool V_237 ;
int V_115 ;
V_2 = F_162 ( V_236 , T_2 ,
V_4 . V_225 . V_236 ) ;
V_8 = V_2 -> V_8 ;
if ( ! F_163 ( & V_8 -> V_19 ) ) {
F_146 ( V_2 -> V_224 , & V_2 -> V_4 . V_225 , V_226 ) ;
return;
}
F_159 ( V_8 ) ;
V_237 = true ;
for ( V_115 = 0 ; V_115 < V_228 ; V_115 ++ ) {
struct V_181 * V_182 = & V_2 -> V_182 [ V_115 ] ;
if ( ! F_130 ( & V_182 -> V_199 ) ) {
struct V_206 * V_207 ;
int V_14 ;
V_14 = F_164 ( V_182 ,
0 , V_132 ) ;
V_207 = F_165 ( sizeof( * V_207 ) , V_238 ) ;
if ( V_14 || V_207 == NULL ||
F_138 ( V_182 , NULL , V_207 ) )
F_27 ( V_207 ) ;
}
V_237 &= F_130 ( & V_182 -> V_214 ) ;
}
if ( ! V_2 -> V_4 . V_220 && ! V_237 )
F_146 ( V_2 -> V_224 , & V_2 -> V_4 . V_225 , V_226 ) ;
F_19 ( & V_8 -> V_19 ) ;
}
int
F_166 ( struct V_181 * V_182 ,
T_4 V_183 ,
bool V_239 )
{
T_2 * V_2 = V_182 -> V_8 -> V_9 ;
T_5 V_240 ;
int V_14 = 0 ;
F_118 ( V_183 == 0 ) ;
if ( F_4 ( & V_2 -> V_4 . V_15 ) ) {
struct V_10 * V_11 = & V_2 -> V_12 ;
bool V_241 ;
unsigned long V_13 ;
F_6 ( & V_11 -> V_16 . V_17 , V_13 ) ;
V_241 = V_11 -> V_18 > 0 ;
F_7 ( & V_11 -> V_16 . V_17 , V_13 ) ;
return V_241 ? - V_157 : - V_158 ;
}
if ( V_183 == V_182 -> V_205 ) {
struct V_206 * V_207 ;
V_207 = F_165 ( sizeof( * V_207 ) , V_238 ) ;
if ( V_207 == NULL )
return - V_49 ;
V_14 = F_138 ( V_182 , NULL , V_207 ) ;
if ( V_14 ) {
F_27 ( V_207 ) ;
return V_14 ;
}
V_183 = V_207 -> V_183 ;
}
if ( ! F_156 ( V_182 -> V_229 ( V_182 ) , V_183 ) ) {
if ( F_167 ( V_182 -> V_8 ) )
V_240 = F_168 ( V_242 ) | F_168 ( V_243 ) ;
else
V_240 = F_168 ( V_244 ) ;
if ( ! V_240 ) {
F_114 ( L_2
L_3 ) ;
V_182 -> V_8 -> V_41 -> V_245 ( V_182 -> V_8 ) ;
V_182 -> V_8 -> V_41 -> V_246 ( V_182 -> V_8 ) ;
}
F_169 ( V_182 , V_183 ) ;
V_182 -> V_247 = V_183 ;
if ( V_182 -> V_248 ( V_182 ) ) {
if ( V_2 -> V_4 . V_249 )
V_14 = F_170 ( V_182 -> V_250 ,
F_156 ( V_182 -> V_229 ( V_182 ) , V_183 )
|| F_4 ( & V_2 -> V_4 . V_15 ) ) ;
else
F_171 ( V_182 -> V_250 ,
F_156 ( V_182 -> V_229 ( V_182 ) , V_183 )
|| F_4 ( & V_2 -> V_4 . V_15 ) ) ;
V_182 -> V_233 ( V_182 ) ;
} else if ( F_172 ( F_156 ( V_182 -> V_229 ( V_182 ) ,
V_183 ) ||
F_4 ( & V_2 -> V_4 . V_15 ) , 3000 ) )
V_14 = - V_251 ;
V_182 -> V_247 = 0 ;
F_173 ( V_182 , V_183 ) ;
}
if ( F_4 ( & V_2 -> V_4 . V_15 ) )
V_14 = - V_158 ;
if ( V_14 == 0 && V_239 )
F_154 ( V_182 ) ;
return V_14 ;
}
int
F_174 ( struct V_20 * V_21 )
{
int V_14 ;
F_118 ( ( V_21 -> V_50 . V_125 & V_132 ) != 0 ) ;
if ( V_21 -> V_23 ) {
V_14 = F_166 ( V_21 -> V_182 , V_21 -> V_186 ,
true ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static void F_175 ( struct V_20 * V_21 )
{
T_5 V_203 , V_252 ;
F_176 () ;
F_106 ( V_21 ) ;
if ( ( V_21 -> V_50 . V_131 & V_133 ) == 0 )
return;
V_252 = V_21 -> V_50 . V_131 ;
V_203 = V_21 -> V_50 . V_125 ;
V_21 -> V_50 . V_131 &= ~ V_133 ;
V_21 -> V_50 . V_125 &= ~ V_133 ;
F_136 ( V_21 ,
V_252 ,
V_203 ) ;
}
int
F_100 ( struct V_20 * V_21 )
{
T_2 * V_2 = V_21 -> V_50 . V_8 -> V_9 ;
int V_14 = 0 ;
if ( V_21 -> V_22 == NULL )
return 0 ;
if ( V_21 -> V_24 != 0 ) {
F_114 ( L_4 ) ;
return - V_38 ;
}
V_14 = F_177 ( V_21 ) ;
if ( V_14 == - V_159 )
return V_14 ;
F_175 ( V_21 ) ;
if ( V_14 == 0 )
V_14 = F_91 ( V_21 , 1 ) ;
if ( V_14 == - V_159 )
return V_14 ;
if ( V_14 ) {
F_83 ( V_21 ) ;
V_21 -> V_50 . V_131 = V_21 -> V_50 . V_125 = V_126 ;
}
V_14 = F_77 ( V_21 ) ;
if ( V_14 == - V_159 )
return V_14 ;
F_178 ( V_21 ) ;
F_179 ( V_21 ) ;
if ( V_21 -> V_253 ) {
F_180 ( V_2 -> V_4 . V_254 , V_21 ) ;
V_21 -> V_253 = 0 ;
}
F_122 ( V_21 ) ;
F_127 ( & V_21 -> V_255 ) ;
F_127 ( & V_21 -> V_153 ) ;
V_21 -> V_152 = true ;
F_181 ( V_21 -> V_22 ) ;
V_21 -> V_22 = NULL ;
V_21 -> V_102 = 0 ;
if ( F_132 ( V_21 ) )
F_54 ( V_21 ) ;
return V_14 ;
}
int
F_164 ( struct V_181 * V_182 ,
T_4 V_256 ,
T_4 V_201 )
{
int V_14 ;
if ( ( ( V_256 | V_201 ) & V_132 ) == 0 )
return 0 ;
F_182 ( V_182 , V_256 , V_201 ) ;
V_14 = V_182 -> V_257 ( V_182 , V_256 , V_201 ) ;
if ( V_14 )
return V_14 ;
if ( V_201 & V_132 )
F_133 ( V_182 , V_201 ) ;
return 0 ;
}
static int F_183 ( struct V_181 * V_182 , bool V_239 )
{
int V_14 ;
if ( F_130 ( & V_182 -> V_199 ) && F_130 ( & V_182 -> V_184 ) )
return 0 ;
if ( ! F_130 ( & V_182 -> V_199 ) ) {
V_14 = F_164 ( V_182 ,
V_132 , V_132 ) ;
if ( V_14 )
return V_14 ;
}
return F_166 ( V_182 , F_135 ( V_182 ) ,
V_239 ) ;
}
int F_184 ( struct V_7 * V_8 , bool V_239 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_14 , V_115 ;
for ( V_115 = 0 ; V_115 < V_228 ; V_115 ++ ) {
V_14 = F_183 ( & V_2 -> V_182 [ V_115 ] , V_239 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static int F_185 ( struct V_20 * V_21 ,
struct V_181 * V_258 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_3 = V_21 -> V_22 -> V_3 ;
int V_259 = V_21 -> V_190 ;
T_3 V_260 ;
V_260 = ( T_3 ) ( ( V_21 -> V_102 + V_3 - 4096 ) &
0xfffff000 ) << 32 ;
V_260 |= V_21 -> V_102 & 0xfffff000 ;
V_260 |= ( T_3 ) ( ( V_21 -> V_261 / 128 ) - 1 ) <<
V_262 ;
if ( V_21 -> V_59 == V_263 )
V_260 |= 1 << V_264 ;
V_260 |= V_265 ;
if ( V_258 ) {
int V_14 = F_186 ( V_258 , 6 ) ;
if ( V_14 )
return V_14 ;
F_187 ( V_258 , V_266 ) ;
F_187 ( V_258 , F_188 ( 2 ) ) ;
F_187 ( V_258 , V_267 + V_259 * 8 ) ;
F_187 ( V_258 , ( T_5 ) V_260 ) ;
F_187 ( V_258 , V_267 + V_259 * 8 + 4 ) ;
F_187 ( V_258 , ( T_5 ) ( V_260 >> 32 ) ) ;
F_189 ( V_258 ) ;
} else
F_190 ( V_267 + V_259 * 8 , V_260 ) ;
return 0 ;
}
static int F_191 ( struct V_20 * V_21 ,
struct V_181 * V_258 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_3 = V_21 -> V_22 -> V_3 ;
int V_259 = V_21 -> V_190 ;
T_3 V_260 ;
V_260 = ( T_3 ) ( ( V_21 -> V_102 + V_3 - 4096 ) &
0xfffff000 ) << 32 ;
V_260 |= V_21 -> V_102 & 0xfffff000 ;
V_260 |= ( ( V_21 -> V_261 / 128 ) - 1 ) << V_268 ;
if ( V_21 -> V_59 == V_263 )
V_260 |= 1 << V_264 ;
V_260 |= V_265 ;
if ( V_258 ) {
int V_14 = F_186 ( V_258 , 6 ) ;
if ( V_14 )
return V_14 ;
F_187 ( V_258 , V_266 ) ;
F_187 ( V_258 , F_188 ( 2 ) ) ;
F_187 ( V_258 , V_269 + V_259 * 8 ) ;
F_187 ( V_258 , ( T_5 ) V_260 ) ;
F_187 ( V_258 , V_269 + V_259 * 8 + 4 ) ;
F_187 ( V_258 , ( T_5 ) ( V_260 >> 32 ) ) ;
F_189 ( V_258 ) ;
} else
F_190 ( V_269 + V_259 * 8 , V_260 ) ;
return 0 ;
}
static int F_192 ( struct V_20 * V_21 ,
struct V_181 * V_258 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_3 = V_21 -> V_22 -> V_3 ;
T_5 V_190 , V_260 , V_270 ;
int V_271 ;
if ( F_193 ( ( V_21 -> V_102 & ~ V_272 ) ||
( V_3 & - V_3 ) != V_3 ||
( V_21 -> V_102 & ( V_3 - 1 ) ) ,
L_5 ,
V_21 -> V_102 , V_21 -> V_152 , V_3 ) )
return - V_38 ;
if ( V_21 -> V_59 == V_263 && F_194 ( V_8 ) )
V_271 = 128 ;
else
V_271 = 512 ;
V_270 = V_21 -> V_261 / V_271 ;
V_270 = F_195 ( V_270 ) - 1 ;
V_260 = V_21 -> V_102 ;
if ( V_21 -> V_59 == V_263 )
V_260 |= 1 << V_273 ;
V_260 |= F_196 ( V_3 ) ;
V_260 |= V_270 << V_274 ;
V_260 |= V_275 ;
V_190 = V_21 -> V_190 ;
if ( V_190 < 8 )
V_190 = V_276 + V_190 * 4 ;
else
V_190 = V_277 + ( V_190 - 8 ) * 4 ;
if ( V_258 ) {
int V_14 = F_186 ( V_258 , 4 ) ;
if ( V_14 )
return V_14 ;
F_187 ( V_258 , V_266 ) ;
F_187 ( V_258 , F_188 ( 1 ) ) ;
F_187 ( V_258 , V_190 ) ;
F_187 ( V_258 , V_260 ) ;
F_189 ( V_258 ) ;
} else
F_197 ( V_190 , V_260 ) ;
return 0 ;
}
static int F_198 ( struct V_20 * V_21 ,
struct V_181 * V_258 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_3 = V_21 -> V_22 -> V_3 ;
int V_259 = V_21 -> V_190 ;
T_4 V_260 ;
T_4 V_270 ;
if ( F_193 ( ( V_21 -> V_102 & ~ V_278 ) ||
( V_3 & - V_3 ) != V_3 ||
( V_21 -> V_102 & ( V_3 - 1 ) ) ,
L_6 ,
V_21 -> V_102 , V_3 ) )
return - V_38 ;
V_270 = V_21 -> V_261 / 128 ;
V_270 = F_195 ( V_270 ) - 1 ;
V_260 = V_21 -> V_102 ;
if ( V_21 -> V_59 == V_263 )
V_260 |= 1 << V_273 ;
V_260 |= F_199 ( V_3 ) ;
V_260 |= V_270 << V_274 ;
V_260 |= V_275 ;
if ( V_258 ) {
int V_14 = F_186 ( V_258 , 4 ) ;
if ( V_14 )
return V_14 ;
F_187 ( V_258 , V_266 ) ;
F_187 ( V_258 , F_188 ( 1 ) ) ;
F_187 ( V_258 , V_276 + V_259 * 4 ) ;
F_187 ( V_258 , V_260 ) ;
F_189 ( V_258 ) ;
} else
F_197 ( V_276 + V_259 * 4 , V_260 ) ;
return 0 ;
}
static bool F_200 ( struct V_181 * V_182 , T_5 V_183 )
{
return F_156 ( V_182 -> V_229 ( V_182 ) , V_183 ) ;
}
static int
F_201 ( struct V_20 * V_21 ,
struct V_181 * V_258 )
{
int V_14 ;
if ( V_21 -> V_187 ) {
if ( V_21 -> V_50 . V_125 & V_132 ) {
V_14 = F_164 ( V_21 -> V_189 ,
0 , V_21 -> V_50 . V_125 ) ;
if ( V_14 )
return V_14 ;
}
V_21 -> V_187 = false ;
}
if ( V_21 -> V_188 && V_258 != V_21 -> V_189 ) {
if ( ! F_200 ( V_21 -> V_189 ,
V_21 -> V_188 ) ) {
V_14 = F_166 ( V_21 -> V_189 ,
V_21 -> V_188 ,
true ) ;
if ( V_14 )
return V_14 ;
}
V_21 -> V_188 = 0 ;
V_21 -> V_189 = NULL ;
}
if ( V_21 -> V_50 . V_131 & V_133 )
F_176 () ;
return 0 ;
}
int
F_77 ( struct V_20 * V_21 )
{
int V_14 ;
if ( V_21 -> V_59 )
F_106 ( V_21 ) ;
V_14 = F_201 ( V_21 , NULL ) ;
if ( V_14 )
return V_14 ;
if ( V_21 -> V_190 != V_191 ) {
struct V_1 * V_2 = V_21 -> V_50 . V_8 -> V_9 ;
F_10 ( V_2 -> V_194 [ V_21 -> V_190 ] . V_24 ) ;
F_152 ( V_21 -> V_50 . V_8 ,
& V_2 -> V_194 [ V_21 -> V_190 ] ) ;
V_21 -> V_190 = V_191 ;
}
return 0 ;
}
static struct V_192 *
F_202 ( struct V_7 * V_8 ,
struct V_181 * V_258 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_192 * V_193 , * V_279 , * V_280 ;
int V_115 ;
V_280 = NULL ;
for ( V_115 = V_2 -> V_281 ; V_115 < V_2 -> V_227 ; V_115 ++ ) {
V_193 = & V_2 -> V_194 [ V_115 ] ;
if ( ! V_193 -> V_21 )
return V_193 ;
if ( ! V_193 -> V_24 )
V_280 = V_193 ;
}
if ( V_280 == NULL )
return NULL ;
V_280 = V_279 = NULL ;
F_21 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_193 -> V_24 )
continue;
if ( V_279 == NULL )
V_279 = V_193 ;
if ( ! V_258 ||
! V_193 -> V_21 -> V_189 ||
V_193 -> V_21 -> V_189 == V_258 ) {
V_280 = V_193 ;
break;
}
}
if ( V_280 == NULL )
V_280 = V_279 ;
return V_280 ;
}
int
F_102 ( struct V_20 * V_21 ,
struct V_181 * V_258 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_192 * V_193 ;
int V_14 ;
V_258 = NULL ;
if ( V_21 -> V_190 != V_191 ) {
V_193 = & V_2 -> V_194 [ V_21 -> V_190 ] ;
F_103 ( & V_193 -> V_195 , & V_2 -> V_4 . V_196 ) ;
if ( V_21 -> V_282 ) {
V_14 = F_201 ( V_21 , V_258 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_21 -> V_187 && ! V_21 -> V_188 )
V_258 = NULL ;
if ( V_258 ) {
V_193 -> V_283 =
F_135 ( V_258 ) ;
V_21 -> V_188 = V_193 -> V_283 ;
V_21 -> V_189 = V_258 ;
}
goto V_284;
}
if ( ! V_258 ) {
if ( V_193 -> V_283 ) {
if ( ! F_200 ( V_21 -> V_189 ,
V_193 -> V_283 ) ) {
V_14 = F_166 ( V_21 -> V_189 ,
V_193 -> V_283 ,
true ) ;
if ( V_14 )
return V_14 ;
}
V_193 -> V_283 = 0 ;
}
} else if ( V_21 -> V_189 &&
V_21 -> V_189 != V_258 ) {
V_14 = F_201 ( V_21 , V_258 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
V_193 = F_202 ( V_8 , V_258 ) ;
if ( V_193 == NULL )
return - V_285 ;
V_14 = F_201 ( V_21 , V_258 ) ;
if ( V_14 )
return V_14 ;
if ( V_193 -> V_21 ) {
struct V_20 * V_286 = V_193 -> V_21 ;
F_125 ( & V_286 -> V_50 ) ;
if ( V_286 -> V_59 )
F_106 ( V_286 ) ;
V_14 = F_201 ( V_286 , V_258 ) ;
if ( V_14 ) {
F_28 ( & V_286 -> V_50 ) ;
return V_14 ;
}
if ( V_286 -> V_188 == 0 && V_21 -> V_188 == 0 )
V_258 = NULL ;
V_286 -> V_190 = V_191 ;
V_286 -> V_189 = V_258 ;
V_286 -> V_188 =
V_258 ? F_135 ( V_258 ) : 0 ;
F_28 ( & V_286 -> V_50 ) ;
} else if ( V_21 -> V_188 == 0 )
V_258 = NULL ;
V_193 -> V_21 = V_21 ;
F_103 ( & V_193 -> V_195 , & V_2 -> V_4 . V_196 ) ;
V_21 -> V_190 = V_193 - V_2 -> V_194 ;
V_21 -> V_189 = V_258 ;
V_193 -> V_283 =
V_258 ? F_135 ( V_258 ) : 0 ;
V_21 -> V_188 = V_193 -> V_283 ;
V_284:
V_21 -> V_282 = false ;
switch ( F_109 ( V_8 ) -> V_169 ) {
case 7 :
case 6 :
V_14 = F_185 ( V_21 , V_258 ) ;
break;
case 5 :
case 4 :
V_14 = F_191 ( V_21 , V_258 ) ;
break;
case 3 :
V_14 = F_192 ( V_21 , V_258 ) ;
break;
case 2 :
V_14 = F_198 ( V_21 , V_258 ) ;
break;
}
return V_14 ;
}
static void
F_152 ( struct V_7 * V_8 ,
struct V_192 * V_193 )
{
T_2 * V_2 = V_8 -> V_9 ;
T_4 V_190 = V_193 - V_2 -> V_194 ;
switch ( F_109 ( V_8 ) -> V_169 ) {
case 7 :
case 6 :
F_190 ( V_267 + V_190 * 8 , 0 ) ;
break;
case 5 :
case 4 :
F_190 ( V_269 + V_190 * 8 , 0 ) ;
break;
case 3 :
if ( V_190 >= 8 )
V_190 = V_277 + ( V_190 - 8 ) * 4 ;
else
case 2 :
V_190 = V_276 + V_190 * 4 ;
F_197 ( V_190 , 0 ) ;
break;
}
F_127 ( & V_193 -> V_195 ) ;
V_193 -> V_21 = NULL ;
V_193 -> V_283 = 0 ;
V_193 -> V_24 = 0 ;
}
static int
F_101 ( struct V_20 * V_21 ,
unsigned V_287 ,
bool V_152 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
struct V_288 * V_289 ;
T_11 V_175 = V_290 | V_291 ;
T_5 V_3 , V_292 , V_293 , V_294 ;
bool V_295 , V_296 ;
int V_14 ;
if ( V_21 -> V_92 != V_171 ) {
F_114 ( L_7 ) ;
return - V_38 ;
}
V_292 = F_108 ( V_8 ,
V_21 -> V_50 . V_3 ,
V_21 -> V_59 ) ;
V_293 = F_110 ( V_8 ,
V_21 -> V_50 . V_3 ,
V_21 -> V_59 ) ;
V_294 =
F_111 ( V_8 ,
V_21 -> V_50 . V_3 ,
V_21 -> V_59 ) ;
if ( V_287 == 0 )
V_287 = V_152 ? V_293 :
V_294 ;
if ( V_152 && V_287 & ( V_293 - 1 ) ) {
F_114 ( L_8 , V_287 ) ;
return - V_38 ;
}
V_3 = V_152 ? V_292 : V_21 -> V_50 . V_3 ;
if ( V_21 -> V_50 . V_3 >
( V_152 ? V_2 -> V_4 . V_29 : V_2 -> V_4 . V_31 ) ) {
F_114 ( L_9 ) ;
return - V_170 ;
}
V_297:
if ( V_152 )
V_289 =
F_203 ( & V_2 -> V_4 . V_22 ,
V_3 , V_287 , 0 ,
V_2 -> V_4 . V_29 ,
0 ) ;
else
V_289 = F_204 ( & V_2 -> V_4 . V_22 ,
V_3 , V_287 , 0 ) ;
if ( V_289 != NULL ) {
if ( V_152 )
V_21 -> V_22 =
F_205 ( V_289 ,
V_3 , V_287 , 0 ,
V_2 -> V_4 . V_29 ,
0 ) ;
else
V_21 -> V_22 =
F_206 ( V_289 , V_3 , V_287 ) ;
}
if ( V_21 -> V_22 == NULL ) {
V_14 = F_207 ( V_8 , V_3 , V_287 ,
V_152 ) ;
if ( V_14 )
return V_14 ;
goto V_297;
}
V_14 = F_117 ( V_21 , V_175 ) ;
if ( V_14 ) {
F_181 ( V_21 -> V_22 ) ;
V_21 -> V_22 = NULL ;
if ( V_14 == - V_49 ) {
V_14 = F_208 ( V_8 , false ) ;
if ( V_14 ) {
if ( V_175 ) {
V_175 = 0 ;
goto V_297;
}
return - V_49 ;
}
goto V_297;
}
return V_14 ;
}
V_14 = F_209 ( V_21 ) ;
if ( V_14 ) {
F_122 ( V_21 ) ;
F_181 ( V_21 -> V_22 ) ;
V_21 -> V_22 = NULL ;
if ( F_208 ( V_8 , false ) )
return V_14 ;
goto V_297;
}
F_141 ( & V_21 -> V_255 , & V_2 -> V_4 . V_255 ) ;
F_141 ( & V_21 -> V_153 , & V_2 -> V_4 . V_154 ) ;
F_118 ( V_21 -> V_50 . V_131 & V_132 ) ;
F_118 ( V_21 -> V_50 . V_125 & V_132 ) ;
V_21 -> V_102 = V_21 -> V_22 -> V_25 ;
V_296 =
V_21 -> V_22 -> V_3 == V_292 &&
( V_21 -> V_22 -> V_25 & ( V_293 - 1 ) ) == 0 ;
V_295 =
V_21 -> V_102 + V_21 -> V_50 . V_3 <= V_2 -> V_4 . V_29 ;
V_21 -> V_152 = V_295 && V_296 ;
F_210 ( V_21 , V_152 ) ;
return 0 ;
}
void
F_83 ( struct V_20 * V_21 )
{
if ( V_21 -> V_178 == NULL )
return;
if ( V_21 -> V_298 != V_299 )
return;
F_211 ( V_21 ) ;
F_212 ( V_21 -> V_178 , V_21 -> V_50 . V_3 / V_33 ) ;
}
static int
F_213 ( struct V_20 * V_21 )
{
if ( ( V_21 -> V_50 . V_125 & V_132 ) == 0 )
return 0 ;
return F_164 ( V_21 -> V_182 , 0 , V_21 -> V_50 . V_125 ) ;
}
static void
F_214 ( struct V_20 * V_21 )
{
T_4 V_203 ;
if ( V_21 -> V_50 . V_125 != V_133 )
return;
F_215 () ;
V_203 = V_21 -> V_50 . V_125 ;
V_21 -> V_50 . V_125 = 0 ;
F_136 ( V_21 ,
V_21 -> V_50 . V_131 ,
V_203 ) ;
}
static void
F_94 ( struct V_20 * V_21 )
{
T_4 V_203 ;
if ( V_21 -> V_50 . V_125 != V_126 )
return;
F_83 ( V_21 ) ;
F_84 () ;
V_203 = V_21 -> V_50 . V_125 ;
V_21 -> V_50 . V_125 = 0 ;
F_136 ( V_21 ,
V_21 -> V_50 . V_131 ,
V_203 ) ;
}
int
F_76 ( struct V_20 * V_21 , bool V_148 )
{
T_4 V_203 , V_252 ;
int V_14 ;
if ( V_21 -> V_22 == NULL )
return - V_38 ;
if ( V_21 -> V_50 . V_125 == V_133 )
return 0 ;
V_14 = F_213 ( V_21 ) ;
if ( V_14 )
return V_14 ;
if ( V_21 -> V_200 || V_148 ) {
V_14 = F_174 ( V_21 ) ;
if ( V_14 )
return V_14 ;
}
F_94 ( V_21 ) ;
V_203 = V_21 -> V_50 . V_125 ;
V_252 = V_21 -> V_50 . V_131 ;
F_118 ( ( V_21 -> V_50 . V_125 & ~ V_133 ) != 0 ) ;
V_21 -> V_50 . V_131 |= V_133 ;
if ( V_148 ) {
V_21 -> V_50 . V_131 = V_133 ;
V_21 -> V_50 . V_125 = V_133 ;
V_21 -> V_124 = 1 ;
}
F_136 ( V_21 ,
V_252 ,
V_203 ) ;
return 0 ;
}
int F_216 ( struct V_20 * V_21 ,
enum V_300 V_298 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
int V_14 ;
if ( V_21 -> V_298 == V_298 )
return 0 ;
if ( V_21 -> V_24 ) {
F_217 ( L_10 ) ;
return - V_251 ;
}
if ( V_21 -> V_22 ) {
V_14 = F_177 ( V_21 ) ;
if ( V_14 )
return V_14 ;
F_175 ( V_21 ) ;
if ( F_109 ( V_21 -> V_50 . V_8 ) -> V_169 < 6 ) {
V_14 = F_77 ( V_21 ) ;
if ( V_14 )
return V_14 ;
}
F_218 ( V_21 , V_298 ) ;
if ( V_21 -> V_253 )
F_219 ( V_2 -> V_4 . V_254 ,
V_21 , V_298 ) ;
}
if ( V_298 == V_299 ) {
T_5 V_252 , V_203 ;
F_10 ( V_21 -> V_50 . V_125 & ~ V_126 ) ;
F_10 ( V_21 -> V_50 . V_131 & ~ V_126 ) ;
V_252 = V_21 -> V_50 . V_131 ;
V_203 = V_21 -> V_50 . V_125 ;
V_21 -> V_50 . V_131 = V_126 ;
V_21 -> V_50 . V_125 = V_126 ;
F_136 ( V_21 ,
V_252 ,
V_203 ) ;
}
V_21 -> V_298 = V_298 ;
return 0 ;
}
int
F_220 ( struct V_20 * V_21 ,
T_5 V_287 ,
struct V_181 * V_258 )
{
T_5 V_252 , V_203 ;
int V_14 ;
V_14 = F_213 ( V_21 ) ;
if ( V_14 )
return V_14 ;
if ( V_258 != V_21 -> V_182 ) {
V_14 = F_174 ( V_21 ) ;
if ( V_14 == - V_159 )
return V_14 ;
}
V_14 = F_216 ( V_21 , V_299 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_89 ( V_21 , V_287 , true ) ;
if ( V_14 )
return V_14 ;
F_94 ( V_21 ) ;
V_203 = V_21 -> V_50 . V_125 ;
V_252 = V_21 -> V_50 . V_131 ;
F_118 ( ( V_21 -> V_50 . V_125 & ~ V_133 ) != 0 ) ;
V_21 -> V_50 . V_131 |= V_133 ;
F_136 ( V_21 ,
V_252 ,
V_203 ) ;
return 0 ;
}
int
F_177 ( struct V_20 * V_21 )
{
int V_14 ;
if ( ( V_21 -> V_50 . V_131 & V_132 ) == 0 )
return 0 ;
if ( V_21 -> V_50 . V_125 & V_132 ) {
V_14 = F_164 ( V_21 -> V_182 , 0 , V_21 -> V_50 . V_125 ) ;
if ( V_14 )
return V_14 ;
}
V_14 = F_174 ( V_21 ) ;
if ( V_14 )
return V_14 ;
V_21 -> V_50 . V_131 &= ~ V_132 ;
return 0 ;
}
static int
F_91 ( struct V_20 * V_21 , bool V_148 )
{
T_4 V_203 , V_252 ;
int V_14 ;
if ( V_21 -> V_50 . V_125 == V_126 )
return 0 ;
V_14 = F_213 ( V_21 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_174 ( V_21 ) ;
if ( V_14 )
return V_14 ;
F_214 ( V_21 ) ;
F_221 ( V_21 ) ;
V_203 = V_21 -> V_50 . V_125 ;
V_252 = V_21 -> V_50 . V_131 ;
if ( ( V_21 -> V_50 . V_131 & V_126 ) == 0 ) {
F_83 ( V_21 ) ;
V_21 -> V_50 . V_131 |= V_126 ;
}
F_118 ( ( V_21 -> V_50 . V_125 & ~ V_126 ) != 0 ) ;
if ( V_148 ) {
V_21 -> V_50 . V_131 = V_126 ;
V_21 -> V_50 . V_125 = V_126 ;
}
F_136 ( V_21 ,
V_252 ,
V_203 ) ;
return 0 ;
}
static void
F_221 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_301 )
return;
if ( V_21 -> V_50 . V_131 & V_126 ) {
int V_115 ;
for ( V_115 = 0 ; V_115 <= ( V_21 -> V_50 . V_3 - 1 ) / V_33 ; V_115 ++ ) {
if ( V_21 -> V_301 [ V_115 ] )
continue;
F_212 ( V_21 -> V_178 + V_115 , 1 ) ;
}
}
F_27 ( V_21 -> V_301 ) ;
V_21 -> V_301 = NULL ;
}
static int
F_61 ( struct V_20 * V_21 ,
T_3 V_70 , T_3 V_3 )
{
T_4 V_252 ;
int V_115 , V_14 ;
if ( V_70 == 0 && V_3 == V_21 -> V_50 . V_3 )
return F_91 ( V_21 , 0 ) ;
V_14 = F_213 ( V_21 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_174 ( V_21 ) ;
if ( V_14 )
return V_14 ;
F_214 ( V_21 ) ;
if ( V_21 -> V_301 == NULL &&
( V_21 -> V_50 . V_131 & V_126 ) != 0 )
return 0 ;
if ( V_21 -> V_301 == NULL ) {
V_21 -> V_301 = F_165 ( V_21 -> V_50 . V_3 / V_33 ,
V_238 ) ;
if ( V_21 -> V_301 == NULL )
return - V_49 ;
} else if ( ( V_21 -> V_50 . V_131 & V_126 ) == 0 )
memset ( V_21 -> V_301 , 0 , V_21 -> V_50 . V_3 / V_33 ) ;
for ( V_115 = V_70 / V_33 ; V_115 <= ( V_70 + V_3 - 1 ) / V_33 ;
V_115 ++ ) {
if ( V_21 -> V_301 [ V_115 ] )
continue;
F_212 ( V_21 -> V_178 + V_115 , 1 ) ;
V_21 -> V_301 [ V_115 ] = 1 ;
}
F_118 ( ( V_21 -> V_50 . V_125 & ~ V_126 ) != 0 ) ;
V_252 = V_21 -> V_50 . V_131 ;
V_21 -> V_50 . V_131 |= V_126 ;
F_136 ( V_21 ,
V_252 ,
V_21 -> V_50 . V_125 ) ;
return 0 ;
}
static int
F_222 ( struct V_7 * V_8 , struct V_35 * V_36 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_216 * V_217 = V_36 -> V_218 ;
unsigned long V_302 = V_213 - F_145 ( 20 ) ;
struct V_206 * V_207 ;
struct V_181 * V_182 = NULL ;
T_5 V_183 = 0 ;
int V_14 ;
if ( F_4 ( & V_2 -> V_4 . V_15 ) )
return - V_157 ;
F_142 ( & V_217 -> V_4 . V_17 ) ;
F_21 (request, &file_priv->mm.request_list, client_list) {
if ( F_223 ( V_207 -> V_212 , V_302 ) )
break;
V_182 = V_207 -> V_182 ;
V_183 = V_207 -> V_183 ;
}
F_143 ( & V_217 -> V_4 . V_17 ) ;
if ( V_183 == 0 )
return 0 ;
V_14 = 0 ;
if ( ! F_156 ( V_182 -> V_229 ( V_182 ) , V_183 ) ) {
if ( V_182 -> V_248 ( V_182 ) ) {
V_14 = F_170 ( V_182 -> V_250 ,
F_156 ( V_182 -> V_229 ( V_182 ) , V_183 )
|| F_4 ( & V_2 -> V_4 . V_15 ) ) ;
V_182 -> V_233 ( V_182 ) ;
if ( V_14 == 0 && F_4 ( & V_2 -> V_4 . V_15 ) )
V_14 = - V_157 ;
} else if ( F_172 ( F_156 ( V_182 -> V_229 ( V_182 ) ,
V_183 ) ||
F_4 ( & V_2 -> V_4 . V_15 ) , 3000 ) ) {
V_14 = - V_251 ;
}
}
if ( V_14 == 0 )
F_146 ( V_2 -> V_224 , & V_2 -> V_4 . V_225 , 0 ) ;
return V_14 ;
}
int
F_89 ( struct V_20 * V_21 ,
T_4 V_287 ,
bool V_152 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
int V_14 ;
F_118 ( V_21 -> V_24 == V_303 ) ;
F_10 ( F_11 ( V_8 ) ) ;
if ( V_21 -> V_22 != NULL ) {
if ( ( V_287 && V_21 -> V_102 & ( V_287 - 1 ) ) ||
( V_152 && ! V_21 -> V_152 ) ) {
F_193 ( V_21 -> V_24 ,
L_11
L_12
L_13 ,
V_21 -> V_102 , V_287 ,
V_152 ,
V_21 -> V_152 ) ;
V_14 = F_100 ( V_21 ) ;
if ( V_14 )
return V_14 ;
}
}
if ( V_21 -> V_22 == NULL ) {
V_14 = F_101 ( V_21 , V_287 ,
V_152 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_21 -> V_24 ++ == 0 ) {
if ( ! V_21 -> V_23 )
F_103 ( & V_21 -> V_153 ,
& V_2 -> V_4 . V_198 ) ;
}
V_21 -> V_304 |= V_152 ;
F_10 ( F_11 ( V_8 ) ) ;
return 0 ;
}
void
F_90 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
F_10 ( F_11 ( V_8 ) ) ;
F_118 ( V_21 -> V_24 == 0 ) ;
F_118 ( V_21 -> V_22 == NULL ) ;
if ( -- V_21 -> V_24 == 0 ) {
if ( ! V_21 -> V_23 )
F_103 ( & V_21 -> V_153 ,
& V_2 -> V_4 . V_154 ) ;
V_21 -> V_304 = false ;
}
F_10 ( F_11 ( V_8 ) ) ;
}
int
F_224 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_305 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_58 ( F_59 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( V_21 -> V_92 != V_171 ) {
F_114 ( L_14 ) ;
V_14 = - V_38 ;
goto V_91;
}
if ( V_21 -> V_306 != NULL && V_21 -> V_306 != V_36 ) {
F_114 ( L_15 ,
args -> V_48 ) ;
V_14 = - V_38 ;
goto V_91;
}
V_21 -> V_307 ++ ;
V_21 -> V_306 = V_36 ;
if ( V_21 -> V_307 == 1 ) {
V_14 = F_89 ( V_21 , args -> V_287 , true ) ;
if ( V_14 )
goto V_91;
}
F_94 ( V_21 ) ;
args -> V_70 = V_21 -> V_102 ;
V_91:
F_28 ( & V_21 -> V_50 ) ;
V_96:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_225 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_305 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_58 ( F_59 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( V_21 -> V_306 != V_36 ) {
F_114 ( L_16 ,
args -> V_48 ) ;
V_14 = - V_38 ;
goto V_91;
}
V_21 -> V_307 -- ;
if ( V_21 -> V_307 == 0 ) {
V_21 -> V_306 = NULL ;
F_90 ( V_21 ) ;
}
V_91:
F_28 ( & V_21 -> V_50 ) ;
V_96:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_226 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_308 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_58 ( F_59 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
args -> V_309 = V_21 -> V_23 ;
if ( args -> V_309 ) {
if ( V_21 -> V_50 . V_125 & V_132 ) {
V_14 = F_164 ( V_21 -> V_182 ,
0 , V_21 -> V_50 . V_125 ) ;
} else if ( V_21 -> V_182 -> V_205 ==
V_21 -> V_186 ) {
struct V_206 * V_207 ;
V_207 = F_165 ( sizeof( * V_207 ) , V_238 ) ;
if ( V_207 ) {
V_14 = F_138 ( V_21 -> V_182 , NULL , V_207 ) ;
if ( V_14 )
F_27 ( V_207 ) ;
} else
V_14 = - V_49 ;
}
F_154 ( V_21 -> V_182 ) ;
args -> V_309 = V_21 -> V_23 ;
}
F_28 ( & V_21 -> V_50 ) ;
V_96:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_227 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_217 )
{
return F_222 ( V_8 , V_217 ) ;
}
int
F_228 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_217 )
{
struct V_310 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 ;
switch ( args -> V_92 ) {
case V_180 :
case V_171 :
break;
default:
return - V_38 ;
}
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_58 ( F_59 ( V_8 , V_217 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_95 ;
goto V_96;
}
if ( V_21 -> V_24 ) {
V_14 = - V_38 ;
goto V_91;
}
if ( V_21 -> V_92 != V_93 )
V_21 -> V_92 = args -> V_92 ;
if ( F_132 ( V_21 ) &&
V_21 -> V_22 == NULL )
F_54 ( V_21 ) ;
args -> V_311 = V_21 -> V_92 != V_93 ;
V_91:
F_28 ( & V_21 -> V_50 ) ;
V_96:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
struct V_20 * F_24 ( struct V_7 * V_8 ,
T_1 V_3 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_20 * V_21 ;
struct V_62 * V_63 ;
V_21 = F_165 ( sizeof( * V_21 ) , V_238 ) ;
if ( V_21 == NULL )
return NULL ;
if ( F_229 ( V_8 , & V_21 -> V_50 , V_3 ) != 0 ) {
F_27 ( V_21 ) ;
return NULL ;
}
V_63 = V_21 -> V_50 . V_64 -> V_65 . V_66 -> V_67 -> V_68 ;
F_230 ( V_63 , V_312 | V_313 ) ;
F_1 ( V_2 , V_3 ) ;
V_21 -> V_50 . V_125 = V_126 ;
V_21 -> V_50 . V_131 = V_126 ;
if ( F_231 ( V_8 ) ) {
V_21 -> V_298 = V_314 ;
} else
V_21 -> V_298 = V_299 ;
V_21 -> V_50 . V_315 = NULL ;
V_21 -> V_190 = V_191 ;
F_232 ( & V_21 -> V_153 ) ;
F_232 ( & V_21 -> V_255 ) ;
F_232 ( & V_21 -> V_185 ) ;
F_232 ( & V_21 -> V_316 ) ;
F_232 ( & V_21 -> V_199 ) ;
V_21 -> V_92 = V_171 ;
V_21 -> V_152 = true ;
return V_21 ;
}
int F_233 ( struct V_136 * V_21 )
{
F_234 () ;
return 0 ;
}
static void F_160 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
int V_14 ;
V_14 = F_100 ( V_21 ) ;
if ( V_14 == - V_159 ) {
F_235 ( & V_21 -> V_153 ,
& V_2 -> V_4 . V_234 ) ;
return;
}
F_236 ( V_21 ) ;
if ( V_21 -> V_50 . V_165 . V_172 )
F_237 ( & V_21 -> V_50 ) ;
F_26 ( & V_21 -> V_50 ) ;
F_2 ( V_2 , V_21 -> V_50 . V_3 ) ;
F_27 ( V_21 -> V_301 ) ;
F_27 ( V_21 -> V_317 ) ;
F_27 ( V_21 ) ;
}
void F_238 ( struct V_136 * V_318 )
{
struct V_20 * V_21 = F_58 ( V_318 ) ;
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
while ( V_21 -> V_24 > 0 )
F_90 ( V_21 ) ;
if ( V_21 -> V_128 )
F_239 ( V_8 , V_21 ) ;
F_160 ( V_21 ) ;
}
int
F_240 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_14 ;
F_18 ( & V_8 -> V_19 ) ;
if ( V_2 -> V_4 . V_220 ) {
F_19 ( & V_8 -> V_19 ) ;
return 0 ;
}
V_14 = F_184 ( V_8 , true ) ;
if ( V_14 ) {
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
if ( ! F_241 ( V_8 , V_319 ) ) {
V_14 = F_242 ( V_8 , false ) ;
if ( V_14 ) {
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
}
F_151 ( V_8 ) ;
V_2 -> V_4 . V_220 = 1 ;
F_243 ( & V_2 -> V_222 ) ;
F_244 ( V_8 ) ;
F_245 ( V_8 ) ;
F_19 ( & V_8 -> V_19 ) ;
F_246 ( & V_2 -> V_4 . V_225 ) ;
return 0 ;
}
void F_247 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
if ( F_109 ( V_8 ) -> V_169 < 5 ||
V_2 -> V_4 . V_57 == V_320 )
return;
F_197 ( V_321 , F_168 ( V_321 ) |
V_322 ) ;
if ( F_248 ( V_8 ) )
return;
F_197 ( V_323 , F_168 ( V_323 ) | V_324 ) ;
if ( F_249 ( V_8 ) )
F_197 ( V_325 , F_250 ( V_326 ) ) ;
else
F_197 ( V_325 , F_250 ( V_327 ) ) ;
}
void F_251 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
T_4 V_328 ;
struct V_181 * V_182 ;
struct V_329 * V_330 = V_2 -> V_4 . V_254 ;
T_4 T_9 * V_331 ;
T_4 V_332 ;
int V_115 ;
if ( ! V_2 -> V_4 . V_254 )
return;
V_331 = V_2 -> V_4 . V_333 -> V_333 + V_330 -> V_328 / sizeof( T_4 ) ;
for ( V_115 = 0 ; V_115 < V_330 -> V_334 ; V_115 ++ ) {
T_12 V_335 ;
if ( V_2 -> V_4 . V_333 -> V_336 )
V_335 = V_330 -> V_337 [ V_115 ] ;
else
V_335 = F_51 ( V_330 -> V_338 [ V_115 ] ) ;
V_332 = F_252 ( V_335 ) ;
V_332 |= V_339 ;
F_253 ( V_332 , V_331 + V_115 ) ;
}
F_254 ( V_331 ) ;
V_328 = V_330 -> V_328 ;
V_328 /= 64 ;
V_328 <<= 16 ;
if ( F_109 ( V_8 ) -> V_169 == 6 ) {
T_4 V_340 = F_168 ( V_341 ) ;
F_197 ( V_341 , V_340 | V_342 |
V_343 ) ;
F_197 ( V_344 , F_255 ( V_345 ) ) ;
} else if ( F_109 ( V_8 ) -> V_169 >= 7 ) {
F_197 ( V_341 , V_343 ) ;
}
for ( V_115 = 0 ; V_115 < V_228 ; V_115 ++ ) {
V_182 = & V_2 -> V_182 [ V_115 ] ;
if ( F_109 ( V_8 ) -> V_169 >= 7 )
F_197 ( F_256 ( V_182 ) ,
F_255 ( V_345 ) ) ;
F_197 ( F_257 ( V_182 ) , V_346 ) ;
F_197 ( F_258 ( V_182 ) , V_328 ) ;
}
}
int
F_259 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_14 ;
F_247 ( V_8 ) ;
V_14 = F_260 ( V_8 ) ;
if ( V_14 )
return V_14 ;
if ( F_261 ( V_8 ) ) {
V_14 = F_262 ( V_8 ) ;
if ( V_14 )
goto V_347;
}
if ( F_263 ( V_8 ) ) {
V_14 = F_264 ( V_8 ) ;
if ( V_14 )
goto V_348;
}
V_2 -> V_204 = 1 ;
F_251 ( V_8 ) ;
return 0 ;
V_348:
F_265 ( & V_2 -> V_182 [ V_349 ] ) ;
V_347:
F_265 ( & V_2 -> V_182 [ V_350 ] ) ;
return V_14 ;
}
void
F_245 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_115 ;
for ( V_115 = 0 ; V_115 < V_228 ; V_115 ++ )
F_265 ( & V_2 -> V_182 [ V_115 ] ) ;
}
int
F_266 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_217 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_14 , V_115 ;
if ( F_241 ( V_8 , V_319 ) )
return 0 ;
if ( F_4 ( & V_2 -> V_4 . V_15 ) ) {
F_114 ( L_17 ) ;
F_267 ( & V_2 -> V_4 . V_15 , 0 ) ;
}
F_18 ( & V_8 -> V_19 ) ;
V_2 -> V_4 . V_220 = 0 ;
V_14 = F_259 ( V_8 ) ;
if ( V_14 != 0 ) {
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
F_118 ( ! F_130 ( & V_2 -> V_4 . V_184 ) ) ;
F_118 ( ! F_130 ( & V_2 -> V_4 . V_197 ) ) ;
F_118 ( ! F_130 ( & V_2 -> V_4 . V_154 ) ) ;
for ( V_115 = 0 ; V_115 < V_228 ; V_115 ++ ) {
F_118 ( ! F_130 ( & V_2 -> V_182 [ V_115 ] . V_184 ) ) ;
F_118 ( ! F_130 ( & V_2 -> V_182 [ V_115 ] . V_214 ) ) ;
}
F_19 ( & V_8 -> V_19 ) ;
V_14 = F_268 ( V_8 ) ;
if ( V_14 )
goto V_351;
return 0 ;
V_351:
F_18 ( & V_8 -> V_19 ) ;
F_245 ( V_8 ) ;
V_2 -> V_4 . V_220 = 1 ;
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_269 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_217 )
{
if ( F_241 ( V_8 , V_319 ) )
return 0 ;
F_270 ( V_8 ) ;
return F_240 ( V_8 ) ;
}
void
F_271 ( struct V_7 * V_8 )
{
int V_14 ;
if ( F_241 ( V_8 , V_319 ) )
return;
V_14 = F_240 ( V_8 ) ;
if ( V_14 )
F_114 ( L_18 , V_14 ) ;
}
static void
F_272 ( struct V_181 * V_182 )
{
F_232 ( & V_182 -> V_184 ) ;
F_232 ( & V_182 -> V_214 ) ;
F_232 ( & V_182 -> V_199 ) ;
}
void
F_273 ( struct V_7 * V_8 )
{
int V_115 ;
T_2 * V_2 = V_8 -> V_9 ;
F_232 ( & V_2 -> V_4 . V_184 ) ;
F_232 ( & V_2 -> V_4 . V_197 ) ;
F_232 ( & V_2 -> V_4 . V_154 ) ;
F_232 ( & V_2 -> V_4 . V_198 ) ;
F_232 ( & V_2 -> V_4 . V_196 ) ;
F_232 ( & V_2 -> V_4 . V_234 ) ;
F_232 ( & V_2 -> V_4 . V_255 ) ;
for ( V_115 = 0 ; V_115 < V_228 ; V_115 ++ )
F_272 ( & V_2 -> V_182 [ V_115 ] ) ;
for ( V_115 = 0 ; V_115 < V_352 ; V_115 ++ )
F_232 ( & V_2 -> V_194 [ V_115 ] . V_195 ) ;
F_274 ( & V_2 -> V_4 . V_225 ,
F_161 ) ;
F_275 ( & V_2 -> V_12 ) ;
if ( F_276 ( V_8 ) ) {
T_5 V_353 = F_168 ( V_354 ) ;
if ( ! ( V_353 & V_355 ) ) {
V_353 = V_355 | ( V_355 << V_356 ) ;
F_197 ( V_354 , V_353 ) ;
}
}
V_2 -> V_357 = V_358 ;
if ( ! F_241 ( V_8 , V_319 ) )
V_2 -> V_281 = 3 ;
if ( F_109 ( V_8 ) -> V_169 >= 4 || F_277 ( V_8 ) || F_278 ( V_8 ) || F_112 ( V_8 ) )
V_2 -> V_227 = 16 ;
else
V_2 -> V_227 = 8 ;
for ( V_115 = 0 ; V_115 < V_2 -> V_227 ; V_115 ++ ) {
F_152 ( V_8 , & V_2 -> V_194 [ V_115 ] ) ;
}
F_279 ( V_8 ) ;
F_280 ( & V_2 -> V_359 ) ;
V_2 -> V_4 . V_249 = true ;
V_2 -> V_4 . V_360 . V_361 = V_362 ;
V_2 -> V_4 . V_360 . V_363 = V_364 ;
F_281 ( & V_2 -> V_4 . V_360 ) ;
}
static int F_282 ( struct V_7 * V_8 ,
int V_365 , int V_3 , int V_366 )
{
T_2 * V_2 = V_8 -> V_9 ;
struct V_367 * V_128 ;
int V_14 ;
if ( V_2 -> V_4 . V_368 [ V_365 - 1 ] || ! V_3 )
return 0 ;
V_128 = F_165 ( sizeof( struct V_367 ) , V_238 ) ;
if ( ! V_128 )
return - V_49 ;
V_128 -> V_365 = V_365 ;
V_128 -> V_48 = F_283 ( V_8 , V_3 , V_366 ) ;
if ( ! V_128 -> V_48 ) {
V_14 = - V_49 ;
goto V_369;
}
#ifdef F_284
F_285 ( ( unsigned long ) V_128 -> V_48 -> V_77 , V_128 -> V_48 -> V_3 / V_33 ) ;
#endif
V_2 -> V_4 . V_368 [ V_365 - 1 ] = V_128 ;
return 0 ;
V_369:
F_27 ( V_128 ) ;
return V_14 ;
}
static void F_286 ( struct V_7 * V_8 , int V_365 )
{
T_2 * V_2 = V_8 -> V_9 ;
struct V_367 * V_128 ;
if ( ! V_2 -> V_4 . V_368 [ V_365 - 1 ] )
return;
V_128 = V_2 -> V_4 . V_368 [ V_365 - 1 ] ;
if ( V_128 -> V_370 ) {
F_239 ( V_8 , V_128 -> V_370 ) ;
}
#ifdef F_284
F_287 ( ( unsigned long ) V_128 -> V_48 -> V_77 , V_128 -> V_48 -> V_3 / V_33 ) ;
#endif
F_288 ( V_8 , V_128 -> V_48 ) ;
F_27 ( V_128 ) ;
V_2 -> V_4 . V_368 [ V_365 - 1 ] = NULL ;
}
void F_289 ( struct V_7 * V_8 )
{
int V_115 ;
for ( V_115 = V_371 ; V_115 <= V_372 ; V_115 ++ )
F_286 ( V_8 , V_115 ) ;
}
void F_239 ( struct V_7 * V_8 ,
struct V_20 * V_21 )
{
struct V_62 * V_63 = V_21 -> V_50 . V_64 -> V_65 . V_66 -> V_67 -> V_68 ;
char * V_77 ;
int V_115 ;
int V_176 ;
if ( ! V_21 -> V_128 )
return;
V_77 = V_21 -> V_128 -> V_48 -> V_77 ;
V_176 = V_21 -> V_50 . V_3 / V_33 ;
for ( V_115 = 0 ; V_115 < V_176 ; V_115 ++ ) {
struct V_76 * V_76 = F_38 ( V_63 , V_115 ) ;
if ( ! F_39 ( V_76 ) ) {
char * V_373 = F_41 ( V_76 ) ;
memcpy ( V_373 , V_77 + V_115 * V_33 , V_33 ) ;
F_43 ( V_373 ) ;
F_212 ( & V_76 , 1 ) ;
F_81 ( V_76 ) ;
F_44 ( V_76 ) ;
F_45 ( V_76 ) ;
}
}
F_84 () ;
V_21 -> V_128 -> V_370 = NULL ;
V_21 -> V_128 = NULL ;
}
int
F_290 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
int V_365 ,
int V_366 )
{
struct V_62 * V_63 = V_21 -> V_50 . V_64 -> V_65 . V_66 -> V_67 -> V_68 ;
T_2 * V_2 = V_8 -> V_9 ;
int V_14 = 0 ;
int V_176 ;
int V_115 ;
if ( V_365 > V_372 )
return - V_38 ;
if ( V_21 -> V_128 ) {
if ( V_21 -> V_128 -> V_365 == V_365 )
return 0 ;
F_239 ( V_8 , V_21 ) ;
}
if ( ! V_2 -> V_4 . V_368 [ V_365 - 1 ] ) {
V_14 = F_282 ( V_8 , V_365 ,
V_21 -> V_50 . V_3 , V_366 ) ;
if ( V_14 ) {
F_114 ( L_19 ,
V_365 , V_21 -> V_50 . V_3 ) ;
return V_14 ;
}
}
V_21 -> V_128 = V_2 -> V_4 . V_368 [ V_365 - 1 ] ;
V_21 -> V_128 -> V_370 = V_21 ;
V_176 = V_21 -> V_50 . V_3 / V_33 ;
for ( V_115 = 0 ; V_115 < V_176 ; V_115 ++ ) {
struct V_76 * V_76 ;
char * V_373 , * V_374 ;
V_76 = F_38 ( V_63 , V_115 ) ;
if ( F_39 ( V_76 ) )
return F_40 ( V_76 ) ;
V_374 = F_41 ( V_76 ) ;
V_373 = V_21 -> V_128 -> V_48 -> V_77 + ( V_115 * V_33 ) ;
memcpy ( V_373 , V_374 , V_33 ) ;
F_43 ( V_374 ) ;
F_44 ( V_76 ) ;
F_45 ( V_76 ) ;
}
return 0 ;
}
static int
F_88 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_107 * args ,
struct V_35 * V_217 )
{
void * V_77 = V_21 -> V_128 -> V_48 -> V_77 + args -> V_70 ;
char T_8 * V_71 = ( char T_8 * ) ( V_74 ) args -> V_75 ;
if ( F_64 ( V_77 , V_71 , args -> V_3 ) ) {
unsigned long V_100 ;
F_19 ( & V_8 -> V_19 ) ;
V_100 = F_291 ( V_77 , V_71 , args -> V_3 ) ;
F_18 ( & V_8 -> V_19 ) ;
if ( V_100 )
return - V_79 ;
}
F_84 () ;
return 0 ;
}
void F_292 ( struct V_7 * V_8 , struct V_35 * V_36 )
{
struct V_216 * V_217 = V_36 -> V_218 ;
F_142 ( & V_217 -> V_4 . V_17 ) ;
while ( ! F_130 ( & V_217 -> V_4 . V_214 ) ) {
struct V_206 * V_207 ;
V_207 = F_150 ( & V_217 -> V_4 . V_214 ,
struct V_206 ,
V_219 ) ;
F_148 ( & V_207 -> V_219 ) ;
V_207 -> V_217 = NULL ;
}
F_143 ( & V_217 -> V_4 . V_17 ) ;
}
static int
F_293 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_375 ;
V_375 = F_130 ( & V_2 -> V_4 . V_197 ) &&
F_130 ( & V_2 -> V_4 . V_184 ) ;
return ! V_375 ;
}
static int
V_362 ( struct V_376 * V_376 , struct V_377 * V_378 )
{
struct V_1 * V_2 =
F_162 ( V_376 ,
struct V_1 ,
V_4 . V_360 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_20 * V_21 , * V_202 ;
int V_379 = V_378 -> V_379 ;
int V_380 ;
if ( ! F_163 ( & V_8 -> V_19 ) )
return 0 ;
if ( V_379 == 0 ) {
V_380 = 0 ;
F_21 (obj,
&dev_priv->mm.inactive_list,
mm_list)
V_380 ++ ;
F_19 ( & V_8 -> V_19 ) ;
return V_380 / 100 * V_381 ;
}
V_382:
F_159 ( V_8 ) ;
F_134 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( F_132 ( V_21 ) ) {
if ( F_100 ( V_21 ) == 0 &&
-- V_379 == 0 )
break;
}
}
V_380 = 0 ;
F_134 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( V_379 &&
F_100 ( V_21 ) == 0 )
V_379 -- ;
else
V_380 ++ ;
}
if ( V_379 && F_293 ( V_8 ) ) {
if ( F_184 ( V_8 , true ) == 0 )
goto V_382;
}
F_19 ( & V_8 -> V_19 ) ;
return V_380 / 100 * V_381 ;
}
