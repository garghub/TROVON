static inline void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( V_2 ) ;
V_2 -> V_4 = false ;
V_2 -> V_5 = V_6 ;
}
static void F_3 ( struct V_7 * V_8 ,
T_1 V_9 )
{
V_8 -> V_10 . V_11 ++ ;
V_8 -> V_10 . V_12 += V_9 ;
}
static void F_4 ( struct V_7 * V_8 ,
T_1 V_9 )
{
V_8 -> V_10 . V_11 -- ;
V_8 -> V_10 . V_12 -= V_9 ;
}
static int
F_5 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_16 * V_17 = & V_8 -> V_18 ;
unsigned long V_19 ;
int V_20 ;
if ( ! F_6 ( & V_8 -> V_10 . V_21 ) )
return 0 ;
V_20 = F_7 ( V_17 , 10 * V_22 ) ;
if ( V_20 == 0 ) {
F_8 ( L_1 ) ;
return - V_23 ;
} else if ( V_20 < 0 ) {
return V_20 ;
}
if ( F_6 ( & V_8 -> V_10 . V_21 ) ) {
F_9 ( & V_17 -> V_24 . V_25 , V_19 ) ;
V_17 -> V_26 ++ ;
F_10 ( & V_17 -> V_24 . V_25 , V_19 ) ;
}
return 0 ;
}
int F_11 ( struct V_13 * V_14 )
{
int V_20 ;
V_20 = F_5 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_12 ( & V_14 -> V_27 ) ;
if ( V_20 )
return V_20 ;
F_13 ( F_14 ( V_14 ) ) ;
return 0 ;
}
static inline bool
F_15 ( struct V_1 * V_2 )
{
return ! V_2 -> V_28 ;
}
int
F_16 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_32 * args = V_29 ;
if ( F_17 ( V_14 , V_33 ) )
return - V_34 ;
if ( args -> V_35 >= args -> V_36 ||
( args -> V_36 | args -> V_35 ) & ( V_37 - 1 ) )
return - V_38 ;
if ( F_18 ( V_14 ) -> V_39 >= 5 )
return - V_34 ;
F_19 ( & V_14 -> V_27 ) ;
F_20 ( V_14 , args -> V_35 ,
args -> V_36 , args -> V_36 ) ;
F_21 ( & V_14 -> V_27 ) ;
return 0 ;
}
int
F_22 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_40 * args = V_29 ;
struct V_1 * V_2 ;
T_1 V_41 ;
V_41 = 0 ;
F_19 ( & V_14 -> V_27 ) ;
F_23 (obj, &dev_priv->mm.gtt_list, gtt_list)
if ( V_2 -> V_42 )
V_41 += V_2 -> V_43 -> V_9 ;
F_21 ( & V_14 -> V_27 ) ;
args -> V_44 = V_8 -> V_10 . V_45 ;
args -> V_46 = args -> V_44 - V_41 ;
return 0 ;
}
static int
F_24 ( struct V_30 * V_31 ,
struct V_13 * V_14 ,
T_2 V_9 ,
T_3 * V_47 )
{
struct V_1 * V_2 ;
int V_20 ;
T_4 V_48 ;
V_9 = F_25 ( V_9 , V_37 ) ;
if ( V_9 == 0 )
return - V_38 ;
V_2 = F_26 ( V_14 , V_9 ) ;
if ( V_2 == NULL )
return - V_49 ;
V_20 = F_27 ( V_31 , & V_2 -> V_50 , & V_48 ) ;
if ( V_20 ) {
F_28 ( & V_2 -> V_50 ) ;
F_4 ( V_14 -> V_15 , V_2 -> V_50 . V_9 ) ;
F_29 ( V_2 ) ;
return V_20 ;
}
F_30 ( & V_2 -> V_50 ) ;
F_31 ( V_2 ) ;
* V_47 = V_48 ;
return 0 ;
}
int
F_32 ( struct V_30 * V_31 ,
struct V_13 * V_14 ,
struct V_51 * args )
{
args -> V_52 = F_33 ( args -> V_53 * ( ( args -> V_54 + 7 ) / 8 ) , 64 ) ;
args -> V_9 = args -> V_52 * args -> V_55 ;
return F_24 ( V_31 , V_14 ,
args -> V_9 , & args -> V_48 ) ;
}
int F_34 ( struct V_30 * V_31 ,
struct V_13 * V_14 ,
T_3 V_48 )
{
return F_35 ( V_31 , V_48 ) ;
}
int
F_36 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_56 * args = V_29 ;
return F_24 ( V_31 , V_14 ,
args -> V_9 , & args -> V_48 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_5 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
return V_8 -> V_10 . V_57 == V_58 &&
V_2 -> V_3 != V_59 ;
}
static inline int
F_38 ( char T_6 * V_60 ,
const char * V_61 , int V_62 ,
int V_63 )
{
int V_20 , V_64 = 0 ;
while ( V_63 > 0 ) {
int V_65 = F_33 ( V_62 + 1 , 64 ) ;
int V_66 = F_39 ( V_65 - V_62 , V_63 ) ;
int V_67 = V_62 ^ 64 ;
V_20 = F_40 ( V_60 + V_64 ,
V_61 + V_67 ,
V_66 ) ;
if ( V_20 )
return V_20 + V_63 ;
V_64 += V_66 ;
V_62 += V_66 ;
V_63 -= V_66 ;
}
return 0 ;
}
static inline int
F_41 ( char * V_61 , int V_62 ,
const char T_6 * V_60 ,
int V_63 )
{
int V_20 , V_64 = 0 ;
while ( V_63 > 0 ) {
int V_65 = F_33 ( V_62 + 1 , 64 ) ;
int V_66 = F_39 ( V_65 - V_62 , V_63 ) ;
int V_67 = V_62 ^ 64 ;
V_20 = F_42 ( V_61 + V_67 ,
V_60 + V_64 ,
V_66 ) ;
if ( V_20 )
return V_20 + V_63 ;
V_64 += V_66 ;
V_62 += V_66 ;
V_63 -= V_66 ;
}
return 0 ;
}
static int
F_43 ( struct V_68 * V_68 , int V_69 , int V_70 ,
char T_6 * V_71 ,
bool V_72 , bool V_73 )
{
char * V_74 ;
int V_20 ;
if ( F_44 ( V_72 ) )
return - V_38 ;
V_74 = F_45 ( V_68 ) ;
if ( V_73 )
F_46 ( V_74 + V_69 ,
V_70 ) ;
V_20 = F_47 ( V_71 ,
V_74 + V_69 ,
V_70 ) ;
F_48 ( V_74 ) ;
return V_20 ;
}
static void
F_49 ( char * V_75 , unsigned long V_63 ,
bool V_76 )
{
if ( F_44 ( V_76 ) ) {
unsigned long V_77 = ( unsigned long ) V_75 ;
unsigned long V_78 = ( unsigned long ) V_75 + V_63 ;
V_77 = F_50 ( V_77 , 128 ) ;
V_78 = F_51 ( V_78 , 128 ) ;
F_46 ( ( void * ) V_77 , V_78 - V_77 ) ;
} else {
F_46 ( V_75 , V_63 ) ;
}
}
static int
F_52 ( struct V_68 * V_68 , int V_69 , int V_70 ,
char T_6 * V_71 ,
bool V_72 , bool V_73 )
{
char * V_74 ;
int V_20 ;
V_74 = F_53 ( V_68 ) ;
if ( V_73 )
F_49 ( V_74 + V_69 ,
V_70 ,
V_72 ) ;
if ( V_72 )
V_20 = F_38 ( V_71 ,
V_74 , V_69 ,
V_70 ) ;
else
V_20 = F_40 ( V_71 ,
V_74 + V_69 ,
V_70 ) ;
F_54 ( V_68 ) ;
return V_20 ;
}
static int
F_55 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_79 * args ,
struct V_30 * V_31 )
{
struct V_80 * V_81 = V_2 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
char T_6 * V_71 ;
T_7 V_87 ;
T_8 V_88 ;
int V_69 , V_70 , V_20 = 0 ;
int V_89 , V_72 ;
int V_90 = 0 ;
int V_91 = 0 ;
int V_73 = 0 ;
int V_92 ;
V_71 = ( char T_6 * ) ( V_93 ) args -> V_94 ;
V_87 = args -> V_9 ;
V_89 = F_37 ( V_2 ) ;
if ( ! ( V_2 -> V_50 . V_95 & V_96 ) ) {
if ( V_2 -> V_97 == V_98 )
V_73 = 1 ;
V_20 = F_56 ( V_2 , false ) ;
if ( V_20 )
return V_20 ;
}
V_88 = args -> V_88 ;
while ( V_87 > 0 ) {
struct V_68 * V_68 ;
V_69 = F_57 ( V_88 ) ;
V_70 = V_87 ;
if ( ( V_69 + V_70 ) > V_37 )
V_70 = V_37 - V_69 ;
if ( V_2 -> V_99 ) {
V_68 = V_2 -> V_99 [ V_88 >> V_100 ] ;
V_92 = 0 ;
} else {
V_68 = F_58 ( V_81 , V_88 >> V_100 ) ;
if ( F_59 ( V_68 ) ) {
V_20 = F_60 ( V_68 ) ;
goto V_101;
}
V_92 = 1 ;
}
V_72 = V_89 &&
( F_61 ( V_68 ) & ( 1 << 17 ) ) != 0 ;
V_20 = F_43 ( V_68 , V_69 , V_70 ,
V_71 , V_72 ,
V_73 ) ;
if ( V_20 == 0 )
goto V_102;
V_90 = 1 ;
F_62 ( V_68 ) ;
F_21 ( & V_14 -> V_27 ) ;
if ( ! V_91 ) {
V_20 = F_63 ( V_71 , V_87 ) ;
( void ) V_20 ;
V_91 = 1 ;
}
V_20 = F_52 ( V_68 , V_69 , V_70 ,
V_71 , V_72 ,
V_73 ) ;
F_19 ( & V_14 -> V_27 ) ;
F_64 ( V_68 ) ;
V_102:
F_65 ( V_68 ) ;
if ( V_92 )
F_64 ( V_68 ) ;
if ( V_20 ) {
V_20 = - V_103 ;
goto V_101;
}
V_87 -= V_70 ;
V_71 += V_70 ;
V_88 += V_70 ;
}
V_101:
if ( V_90 ) {
if ( V_2 -> V_104 == V_105 )
F_66 ( V_2 ) ;
}
return V_20 ;
}
int
F_67 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_79 * args = V_29 ;
struct V_1 * V_2 ;
int V_20 = 0 ;
if ( args -> V_9 == 0 )
return 0 ;
if ( ! F_68 ( V_106 ,
( char T_6 * ) ( V_93 ) args -> V_94 ,
args -> V_9 ) )
return - V_103 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_31 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_107 ;
goto V_108;
}
if ( args -> V_88 > V_2 -> V_50 . V_9 ||
args -> V_9 > V_2 -> V_50 . V_9 - args -> V_88 ) {
V_20 = - V_38 ;
goto V_101;
}
if ( ! V_2 -> V_50 . V_82 ) {
V_20 = - V_38 ;
goto V_101;
}
F_71 ( V_2 , args -> V_88 , args -> V_9 ) ;
V_20 = F_55 ( V_14 , V_2 , args , V_31 ) ;
V_101:
F_30 ( & V_2 -> V_50 ) ;
V_108:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
static inline int
F_72 ( struct V_109 * V_81 ,
T_8 V_110 , int V_111 ,
char T_6 * V_71 ,
int V_63 )
{
void T_9 * V_112 ;
void * V_74 ;
unsigned long V_113 ;
V_112 = F_73 ( V_81 , V_110 ) ;
V_74 = ( void V_114 * ) V_112 + V_111 ;
V_113 = F_74 ( V_74 ,
V_71 , V_63 ) ;
F_75 ( V_112 ) ;
return V_113 ;
}
static int
F_76 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_115 * args ,
struct V_30 * V_31 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_7 V_87 ;
T_8 V_88 , V_110 ;
char T_6 * V_71 ;
int V_111 , V_70 , V_20 ;
V_20 = F_77 ( V_2 , 0 , true ) ;
if ( V_20 )
goto V_101;
V_20 = F_56 ( V_2 , true ) ;
if ( V_20 )
goto V_116;
V_20 = F_78 ( V_2 ) ;
if ( V_20 )
goto V_116;
V_71 = ( char T_6 * ) ( V_93 ) args -> V_94 ;
V_87 = args -> V_9 ;
V_88 = V_2 -> V_117 + args -> V_88 ;
while ( V_87 > 0 ) {
V_110 = V_88 & V_118 ;
V_111 = F_57 ( V_88 ) ;
V_70 = V_87 ;
if ( ( V_111 + V_87 ) > V_37 )
V_70 = V_37 - V_111 ;
if ( F_72 ( V_8 -> V_10 . V_119 , V_110 ,
V_111 , V_71 , V_70 ) ) {
V_20 = - V_103 ;
goto V_116;
}
V_87 -= V_70 ;
V_71 += V_70 ;
V_88 += V_70 ;
}
V_116:
F_79 ( V_2 ) ;
V_101:
return V_20 ;
}
static int
F_80 ( struct V_68 * V_68 , int V_69 , int V_70 ,
char T_6 * V_71 ,
bool V_72 ,
bool V_120 ,
bool V_121 )
{
char * V_74 ;
int V_20 ;
if ( F_44 ( V_72 ) )
return - V_38 ;
V_74 = F_45 ( V_68 ) ;
if ( V_120 )
F_46 ( V_74 + V_69 ,
V_70 ) ;
V_20 = F_74 ( V_74 + V_69 ,
V_71 ,
V_70 ) ;
if ( V_121 )
F_46 ( V_74 + V_69 ,
V_70 ) ;
F_48 ( V_74 ) ;
return V_20 ;
}
static int
F_81 ( struct V_68 * V_68 , int V_69 , int V_70 ,
char T_6 * V_71 ,
bool V_72 ,
bool V_120 ,
bool V_121 )
{
char * V_74 ;
int V_20 ;
V_74 = F_53 ( V_68 ) ;
if ( F_44 ( V_120 || V_72 ) )
F_49 ( V_74 + V_69 ,
V_70 ,
V_72 ) ;
if ( V_72 )
V_20 = F_41 ( V_74 , V_69 ,
V_71 ,
V_70 ) ;
else
V_20 = F_42 ( V_74 + V_69 ,
V_71 ,
V_70 ) ;
if ( V_121 )
F_49 ( V_74 + V_69 ,
V_70 ,
V_72 ) ;
F_54 ( V_68 ) ;
return V_20 ;
}
static int
F_82 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_115 * args ,
struct V_30 * V_31 )
{
struct V_80 * V_81 = V_2 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
T_7 V_87 ;
T_8 V_88 ;
char T_6 * V_71 ;
int V_69 , V_70 , V_20 = 0 ;
int V_89 , V_72 ;
int V_90 = 0 ;
int V_121 = 0 ;
int V_120 = 0 ;
int V_92 ;
V_71 = ( char T_6 * ) ( V_93 ) args -> V_94 ;
V_87 = args -> V_9 ;
V_89 = F_37 ( V_2 ) ;
if ( V_2 -> V_50 . V_122 != V_96 ) {
if ( V_2 -> V_97 == V_98 )
V_121 = 1 ;
V_20 = F_56 ( V_2 , true ) ;
if ( V_20 )
return V_20 ;
}
if ( ! ( V_2 -> V_50 . V_95 & V_96 )
&& V_2 -> V_97 == V_98 )
V_120 = 1 ;
V_88 = args -> V_88 ;
V_2 -> V_123 = 1 ;
while ( V_87 > 0 ) {
struct V_68 * V_68 ;
int V_124 ;
V_69 = F_57 ( V_88 ) ;
V_70 = V_87 ;
if ( ( V_69 + V_70 ) > V_37 )
V_70 = V_37 - V_69 ;
V_124 = V_120 &&
( ( V_69 | V_70 )
& ( V_125 . V_126 - 1 ) ) ;
if ( V_2 -> V_99 ) {
V_68 = V_2 -> V_99 [ V_88 >> V_100 ] ;
V_92 = 0 ;
} else {
V_68 = F_58 ( V_81 , V_88 >> V_100 ) ;
if ( F_59 ( V_68 ) ) {
V_20 = F_60 ( V_68 ) ;
goto V_101;
}
V_92 = 1 ;
}
V_72 = V_89 &&
( F_61 ( V_68 ) & ( 1 << 17 ) ) != 0 ;
V_20 = F_80 ( V_68 , V_69 , V_70 ,
V_71 , V_72 ,
V_124 ,
V_121 ) ;
if ( V_20 == 0 )
goto V_102;
V_90 = 1 ;
F_62 ( V_68 ) ;
F_21 ( & V_14 -> V_27 ) ;
V_20 = F_81 ( V_68 , V_69 , V_70 ,
V_71 , V_72 ,
V_124 ,
V_121 ) ;
F_19 ( & V_14 -> V_27 ) ;
F_64 ( V_68 ) ;
V_102:
F_83 ( V_68 ) ;
F_65 ( V_68 ) ;
if ( V_92 )
F_64 ( V_68 ) ;
if ( V_20 ) {
V_20 = - V_103 ;
goto V_101;
}
V_87 -= V_70 ;
V_71 += V_70 ;
V_88 += V_70 ;
}
V_101:
if ( V_90 ) {
if ( V_2 -> V_104 == V_105 )
F_66 ( V_2 ) ;
if ( V_2 -> V_50 . V_122 != V_96 ) {
F_84 ( V_2 ) ;
F_85 () ;
}
}
if ( V_121 )
F_85 () ;
return V_20 ;
}
int
F_86 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_115 * args = V_29 ;
struct V_1 * V_2 ;
int V_20 ;
if ( args -> V_9 == 0 )
return 0 ;
if ( ! F_68 ( V_127 ,
( char T_6 * ) ( V_93 ) args -> V_94 ,
args -> V_9 ) )
return - V_103 ;
V_20 = F_87 ( ( char T_6 * ) ( V_93 ) args -> V_94 ,
args -> V_9 ) ;
if ( V_20 )
return - V_103 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_31 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_107 ;
goto V_108;
}
if ( args -> V_88 > V_2 -> V_50 . V_9 ||
args -> V_9 > V_2 -> V_50 . V_9 - args -> V_88 ) {
V_20 = - V_38 ;
goto V_101;
}
if ( ! V_2 -> V_50 . V_82 ) {
V_20 = - V_38 ;
goto V_101;
}
F_88 ( V_2 , args -> V_88 , args -> V_9 ) ;
V_20 = - V_103 ;
if ( V_2 -> V_128 ) {
V_20 = F_89 ( V_14 , V_2 , args , V_31 ) ;
goto V_101;
}
if ( V_2 -> V_43 &&
V_2 -> V_97 == V_98 &&
V_2 -> V_3 == V_59 &&
V_2 -> V_129 &&
V_2 -> V_50 . V_122 != V_96 ) {
V_20 = F_76 ( V_14 , V_2 , args , V_31 ) ;
}
if ( V_20 == - V_103 )
V_20 = F_82 ( V_14 , V_2 , args , V_31 ) ;
V_101:
F_30 ( & V_2 -> V_50 ) ;
V_108:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_90 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_130 * args = V_29 ;
struct V_1 * V_2 ;
T_3 V_95 = args -> V_95 ;
T_3 V_122 = args -> V_122 ;
int V_20 ;
if ( V_122 & V_131 )
return - V_38 ;
if ( V_95 & V_131 )
return - V_38 ;
if ( V_122 != 0 && V_95 != V_122 )
return - V_38 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_31 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_107 ;
goto V_108;
}
if ( V_95 & V_132 ) {
V_20 = F_56 ( V_2 , V_122 != 0 ) ;
if ( V_20 == - V_38 )
V_20 = 0 ;
} else {
V_20 = F_91 ( V_2 , V_122 != 0 ) ;
}
F_30 ( & V_2 -> V_50 ) ;
V_108:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_92 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_133 * args = V_29 ;
struct V_1 * V_2 ;
int V_20 = 0 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_31 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_107 ;
goto V_108;
}
if ( V_2 -> V_42 )
F_93 ( V_2 ) ;
F_30 ( & V_2 -> V_50 ) ;
V_108:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_94 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_134 * args = V_29 ;
struct V_135 * V_2 ;
unsigned long V_75 ;
V_2 = F_70 ( V_14 , V_31 , args -> V_48 ) ;
if ( V_2 == NULL )
return - V_107 ;
if ( ! V_2 -> V_82 ) {
F_95 ( V_2 ) ;
return - V_38 ;
}
V_75 = F_96 ( V_2 -> V_82 , 0 , args -> V_9 ,
V_136 | V_137 , V_138 ,
args -> V_88 ) ;
F_95 ( V_2 ) ;
if ( F_59 ( ( void * ) V_75 ) )
return V_75 ;
args -> V_139 = ( T_2 ) V_75 ;
return 0 ;
}
int F_97 ( struct V_140 * V_141 , struct V_142 * V_143 )
{
struct V_1 * V_2 = F_69 ( V_141 -> V_144 ) ;
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
T_10 V_111 ;
unsigned long V_145 ;
int V_20 = 0 ;
bool V_146 = ! ! ( V_143 -> V_19 & V_147 ) ;
V_111 = ( ( unsigned long ) V_143 -> V_148 - V_141 -> V_149 ) >>
V_100 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
goto V_101;
F_98 ( V_2 , V_111 , true , V_146 ) ;
if ( ! V_2 -> V_129 ) {
V_20 = F_99 ( V_2 ) ;
if ( V_20 )
goto V_108;
}
if ( ! V_2 -> V_43 ) {
V_20 = F_100 ( V_2 , 0 , true ) ;
if ( V_20 )
goto V_108;
V_20 = F_56 ( V_2 , V_146 ) ;
if ( V_20 )
goto V_108;
}
if ( ! V_2 -> V_150 )
F_101 ( V_2 , V_2 -> V_97 ) ;
V_20 = F_102 ( V_2 ) ;
if ( V_20 )
goto V_108;
if ( F_15 ( V_2 ) )
F_103 ( & V_2 -> V_151 , & V_8 -> V_10 . V_152 ) ;
V_2 -> V_153 = true ;
V_145 = ( ( V_8 -> V_10 . V_154 + V_2 -> V_117 ) >> V_100 ) +
V_111 ;
V_20 = F_104 ( V_141 , ( unsigned long ) V_143 -> V_148 , V_145 ) ;
V_108:
F_21 ( & V_14 -> V_27 ) ;
V_101:
switch ( V_20 ) {
case - V_23 :
if ( ! F_6 ( & V_8 -> V_10 . V_21 ) )
return V_155 ;
case - V_156 :
F_105 () ;
case 0 :
case - V_157 :
case - V_158 :
return V_159 ;
case - V_49 :
return V_160 ;
default:
return V_155 ;
}
}
void
F_2 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_153 )
return;
if ( V_2 -> V_50 . V_14 -> V_161 )
F_106 ( V_2 -> V_50 . V_14 -> V_161 ,
( T_8 ) V_2 -> V_50 . V_162 . V_163 . V_164 << V_100 ,
V_2 -> V_50 . V_9 , 1 ) ;
V_2 -> V_153 = false ;
}
static T_3
F_107 ( struct V_13 * V_14 , T_3 V_9 , int V_3 )
{
T_3 V_165 ;
if ( F_18 ( V_14 ) -> V_39 >= 4 ||
V_3 == V_59 )
return V_9 ;
if ( F_18 ( V_14 ) -> V_39 == 3 )
V_165 = 1024 * 1024 ;
else
V_165 = 512 * 1024 ;
while ( V_165 < V_9 )
V_165 <<= 1 ;
return V_165 ;
}
static T_3
F_108 ( struct V_13 * V_14 ,
T_3 V_9 ,
int V_3 )
{
if ( F_18 ( V_14 ) -> V_39 >= 4 ||
V_3 == V_59 )
return 4096 ;
return F_107 ( V_14 , V_9 , V_3 ) ;
}
T_3
F_109 ( struct V_13 * V_14 ,
T_3 V_9 ,
int V_3 )
{
if ( F_18 ( V_14 ) -> V_39 >= 4 || F_110 ( V_14 ) ||
V_3 == V_59 )
return 4096 ;
return F_107 ( V_14 , V_9 , V_3 ) ;
}
int
F_111 ( struct V_30 * V_31 ,
struct V_13 * V_14 ,
T_3 V_48 ,
T_2 * V_88 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_31 , V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_107 ;
goto V_108;
}
if ( V_2 -> V_50 . V_9 > V_8 -> V_10 . V_166 ) {
V_20 = - V_167 ;
goto V_101;
}
if ( V_2 -> V_104 != V_168 ) {
F_8 ( L_2 ) ;
V_20 = - V_38 ;
goto V_101;
}
if ( ! V_2 -> V_50 . V_162 . V_169 ) {
V_20 = F_112 ( & V_2 -> V_50 ) ;
if ( V_20 )
goto V_101;
}
* V_88 = ( V_170 ) V_2 -> V_50 . V_162 . V_163 . V_164 << V_100 ;
V_101:
F_30 ( & V_2 -> V_50 ) ;
V_108:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_113 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_171 * args = V_29 ;
return F_111 ( V_31 , V_14 , args -> V_48 , & args -> V_88 ) ;
}
int
F_114 ( struct V_1 * V_2 ,
T_11 V_172 )
{
int V_173 , V_174 ;
struct V_80 * V_81 ;
struct V_175 * V_175 ;
struct V_68 * V_68 ;
if ( V_2 -> V_99 || V_2 -> V_176 )
return 0 ;
V_173 = V_2 -> V_50 . V_9 / V_37 ;
F_115 ( V_2 -> V_99 != NULL ) ;
V_2 -> V_99 = F_116 ( V_173 , sizeof( struct V_68 * ) ) ;
if ( V_2 -> V_99 == NULL )
return - V_49 ;
V_175 = V_2 -> V_50 . V_82 -> V_83 . V_84 -> V_85 ;
V_81 = V_175 -> V_86 ;
V_172 |= F_117 ( V_81 ) ;
for ( V_174 = 0 ; V_174 < V_173 ; V_174 ++ ) {
V_68 = F_118 ( V_81 , V_174 , V_172 ) ;
if ( F_59 ( V_68 ) )
goto V_177;
V_2 -> V_99 [ V_174 ] = V_68 ;
}
if ( F_37 ( V_2 ) )
F_119 ( V_2 ) ;
return 0 ;
V_177:
while ( V_174 -- )
F_64 ( V_2 -> V_99 [ V_174 ] ) ;
F_120 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
return F_60 ( V_68 ) ;
}
static void
F_121 ( struct V_1 * V_2 )
{
int V_173 = V_2 -> V_50 . V_9 / V_37 ;
int V_174 ;
if ( ! V_2 -> V_99 )
return;
F_115 ( V_2 -> V_104 == V_105 ) ;
if ( F_37 ( V_2 ) )
F_122 ( V_2 ) ;
if ( V_2 -> V_104 == V_178 )
V_2 -> V_123 = 0 ;
for ( V_174 = 0 ; V_174 < V_173 ; V_174 ++ ) {
if ( V_2 -> V_123 )
F_83 ( V_2 -> V_99 [ V_174 ] ) ;
if ( V_2 -> V_104 == V_168 )
F_65 ( V_2 -> V_99 [ V_174 ] ) ;
F_64 ( V_2 -> V_99 [ V_174 ] ) ;
}
V_2 -> V_123 = 0 ;
F_120 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
}
void
F_123 ( struct V_1 * V_2 ,
struct V_179 * V_180 ,
T_4 V_181 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
F_115 ( V_180 == NULL ) ;
V_2 -> V_180 = V_180 ;
if ( ! V_2 -> V_28 ) {
F_124 ( & V_2 -> V_50 ) ;
V_2 -> V_28 = 1 ;
}
F_103 ( & V_2 -> V_151 , & V_8 -> V_10 . V_182 ) ;
F_103 ( & V_2 -> V_183 , & V_180 -> V_182 ) ;
V_2 -> V_184 = V_181 ;
if ( V_2 -> V_185 ) {
V_2 -> V_186 = V_181 ;
if ( V_2 -> V_5 != V_6 ) {
struct V_187 * V_188 ;
V_188 = & V_8 -> V_189 [ V_2 -> V_5 ] ;
F_103 ( & V_188 -> V_190 ,
& V_8 -> V_10 . V_191 ) ;
}
}
}
static void
F_125 ( struct V_1 * V_2 )
{
F_126 ( & V_2 -> V_183 ) ;
V_2 -> V_184 = 0 ;
V_2 -> V_186 = 0 ;
}
static void
F_127 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
F_115 ( ! V_2 -> V_28 ) ;
F_103 ( & V_2 -> V_151 , & V_8 -> V_10 . V_192 ) ;
F_125 ( V_2 ) ;
}
static void
F_128 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
F_103 ( & V_2 -> V_151 , & V_8 -> V_10 . V_152 ) ;
F_115 ( ! F_129 ( & V_2 -> V_193 ) ) ;
F_115 ( ! V_2 -> V_28 ) ;
V_2 -> V_180 = NULL ;
F_125 ( V_2 ) ;
V_2 -> V_185 = false ;
V_2 -> V_28 = 0 ;
V_2 -> V_194 = false ;
F_30 ( & V_2 -> V_50 ) ;
F_13 ( F_14 ( V_14 ) ) ;
}
static void
F_66 ( struct V_1 * V_2 )
{
struct V_175 * V_175 ;
V_175 = V_2 -> V_50 . V_82 -> V_83 . V_84 -> V_85 ;
F_130 ( V_175 , 0 , ( T_8 ) - 1 ) ;
if ( V_2 -> V_50 . V_162 . V_169 )
F_131 ( & V_2 -> V_50 ) ;
V_2 -> V_104 = V_105 ;
}
static inline int
F_132 ( struct V_1 * V_2 )
{
return V_2 -> V_104 == V_178 ;
}
static void
F_133 ( struct V_179 * V_180 ,
T_3 V_195 )
{
struct V_1 * V_2 , * V_196 ;
F_134 (obj, next,
&ring->gpu_write_list,
gpu_write_list) {
if ( V_2 -> V_50 . V_122 & V_195 ) {
T_3 V_197 = V_2 -> V_50 . V_122 ;
V_2 -> V_50 . V_122 = 0 ;
F_126 ( & V_2 -> V_193 ) ;
F_123 ( V_2 , V_180 ,
F_135 ( V_180 ) ) ;
F_136 ( V_2 ,
V_2 -> V_50 . V_95 ,
V_197 ) ;
}
}
}
static T_4
F_137 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_4 V_181 = V_8 -> V_198 ;
if ( ++ V_8 -> V_198 == 0 )
V_8 -> V_198 = 1 ;
return V_181 ;
}
T_4
F_135 ( struct V_179 * V_180 )
{
if ( V_180 -> V_199 == 0 )
V_180 -> V_199 = F_137 ( V_180 -> V_14 ) ;
return V_180 -> V_199 ;
}
int
F_138 ( struct V_179 * V_180 ,
struct V_30 * V_31 ,
struct V_200 * V_201 )
{
T_5 * V_8 = V_180 -> V_14 -> V_15 ;
T_3 V_181 ;
T_4 V_202 ;
int V_203 ;
int V_20 ;
if ( V_180 -> V_204 ) {
V_20 = F_139 ( V_180 , 0 , V_131 ) ;
if ( V_20 )
return V_20 ;
V_180 -> V_204 = false ;
}
F_115 ( V_201 == NULL ) ;
V_181 = F_135 ( V_180 ) ;
V_202 = F_140 ( V_180 ) ;
V_20 = V_180 -> V_205 ( V_180 , & V_181 ) ;
if ( V_20 )
return V_20 ;
F_141 ( V_180 , V_181 ) ;
V_201 -> V_181 = V_181 ;
V_201 -> V_180 = V_180 ;
V_201 -> V_206 = V_202 ;
V_201 -> V_207 = V_208 ;
V_203 = F_129 ( & V_180 -> V_209 ) ;
F_142 ( & V_201 -> V_210 , & V_180 -> V_209 ) ;
if ( V_31 ) {
struct V_211 * V_212 = V_31 -> V_213 ;
F_143 ( & V_212 -> V_10 . V_25 ) ;
V_201 -> V_212 = V_212 ;
F_142 ( & V_201 -> V_214 ,
& V_212 -> V_10 . V_209 ) ;
F_144 ( & V_212 -> V_10 . V_25 ) ;
}
V_180 -> V_199 = 0 ;
if ( ! V_8 -> V_10 . V_215 ) {
if ( V_216 ) {
F_145 ( & V_8 -> V_217 ,
V_208 +
F_146 ( V_218 ) ) ;
}
if ( V_203 )
F_147 ( V_8 -> V_219 ,
& V_8 -> V_10 . V_220 , V_22 ) ;
}
F_13 ( ! F_129 ( & V_180 -> V_193 ) ) ;
return 0 ;
}
static inline void
F_148 ( struct V_200 * V_201 )
{
struct V_211 * V_212 = V_201 -> V_212 ;
if ( ! V_212 )
return;
F_143 ( & V_212 -> V_10 . V_25 ) ;
if ( V_201 -> V_212 ) {
F_149 ( & V_201 -> V_214 ) ;
V_201 -> V_212 = NULL ;
}
F_144 ( & V_212 -> V_10 . V_25 ) ;
}
static void F_150 ( struct V_7 * V_8 ,
struct V_179 * V_180 )
{
while ( ! F_129 ( & V_180 -> V_209 ) ) {
struct V_200 * V_201 ;
V_201 = F_151 ( & V_180 -> V_209 ,
struct V_200 ,
V_210 ) ;
F_149 ( & V_201 -> V_210 ) ;
F_148 ( V_201 ) ;
F_29 ( V_201 ) ;
}
while ( ! F_129 ( & V_180 -> V_182 ) ) {
struct V_1 * V_2 ;
V_2 = F_151 ( & V_180 -> V_182 ,
struct V_1 ,
V_183 ) ;
V_2 -> V_50 . V_122 = 0 ;
F_126 ( & V_2 -> V_193 ) ;
F_128 ( V_2 ) ;
}
}
static void F_152 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
int V_174 ;
for ( V_174 = 0 ; V_174 < V_8 -> V_221 ; V_174 ++ ) {
struct V_187 * V_188 = & V_8 -> V_189 [ V_174 ] ;
F_153 ( V_14 , V_174 , NULL ) ;
if ( V_188 -> V_2 )
F_1 ( V_188 -> V_2 ) ;
V_188 -> V_42 = 0 ;
V_188 -> V_2 = NULL ;
F_154 ( & V_188 -> V_190 ) ;
}
F_154 ( & V_8 -> V_10 . V_191 ) ;
}
void F_155 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_1 * V_2 ;
struct V_179 * V_180 ;
int V_174 ;
F_156 (ring, dev_priv, i)
F_150 ( V_8 , V_180 ) ;
while ( ! F_129 ( & V_8 -> V_10 . V_192 ) ) {
V_2 = F_151 ( & V_8 -> V_10 . V_192 ,
struct V_1 ,
V_151 ) ;
V_2 -> V_50 . V_122 = 0 ;
F_126 ( & V_2 -> V_193 ) ;
F_128 ( V_2 ) ;
}
F_23 (obj,
&dev_priv->mm.inactive_list,
mm_list)
{
V_2 -> V_50 . V_95 &= ~ V_131 ;
}
F_152 ( V_14 ) ;
}
void
F_157 ( struct V_179 * V_180 )
{
T_3 V_181 ;
int V_174 ;
if ( F_129 ( & V_180 -> V_209 ) )
return;
F_13 ( F_14 ( V_180 -> V_14 ) ) ;
V_181 = V_180 -> V_222 ( V_180 ) ;
for ( V_174 = 0 ; V_174 < F_158 ( V_180 -> V_223 ) ; V_174 ++ )
if ( V_181 >= V_180 -> V_223 [ V_174 ] )
V_180 -> V_223 [ V_174 ] = 0 ;
while ( ! F_129 ( & V_180 -> V_209 ) ) {
struct V_200 * V_201 ;
V_201 = F_151 ( & V_180 -> V_209 ,
struct V_200 ,
V_210 ) ;
if ( ! F_159 ( V_181 , V_201 -> V_181 ) )
break;
F_160 ( V_180 , V_201 -> V_181 ) ;
V_180 -> V_224 = V_201 -> V_206 ;
F_149 ( & V_201 -> V_210 ) ;
F_148 ( V_201 ) ;
F_29 ( V_201 ) ;
}
while ( ! F_129 ( & V_180 -> V_182 ) ) {
struct V_1 * V_2 ;
V_2 = F_151 ( & V_180 -> V_182 ,
struct V_1 ,
V_183 ) ;
if ( ! F_159 ( V_181 , V_2 -> V_184 ) )
break;
if ( V_2 -> V_50 . V_122 != 0 )
F_127 ( V_2 ) ;
else
F_128 ( V_2 ) ;
}
if ( F_44 ( V_180 -> V_225 &&
F_159 ( V_181 , V_180 -> V_225 ) ) ) {
V_180 -> V_226 ( V_180 ) ;
V_180 -> V_225 = 0 ;
}
F_13 ( F_14 ( V_180 -> V_14 ) ) ;
}
void
F_161 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_179 * V_180 ;
int V_174 ;
F_156 (ring, dev_priv, i)
F_157 ( V_180 ) ;
}
static void
F_162 ( struct V_227 * V_228 )
{
T_5 * V_8 ;
struct V_13 * V_14 ;
struct V_179 * V_180 ;
bool V_229 ;
int V_174 ;
V_8 = F_163 ( V_228 , T_5 ,
V_10 . V_220 . V_228 ) ;
V_14 = V_8 -> V_14 ;
if ( ! F_164 ( & V_14 -> V_27 ) ) {
F_147 ( V_8 -> V_219 , & V_8 -> V_10 . V_220 , V_22 ) ;
return;
}
F_161 ( V_14 ) ;
V_229 = true ;
F_156 (ring, dev_priv, i) {
if ( V_180 -> V_204 ) {
struct V_200 * V_201 ;
V_201 = F_165 ( sizeof( * V_201 ) , V_230 ) ;
if ( V_201 == NULL ||
F_138 ( V_180 , NULL , V_201 ) )
F_29 ( V_201 ) ;
}
V_229 &= F_129 ( & V_180 -> V_209 ) ;
}
if ( ! V_8 -> V_10 . V_215 && ! V_229 )
F_147 ( V_8 -> V_219 , & V_8 -> V_10 . V_220 , V_22 ) ;
F_21 ( & V_14 -> V_27 ) ;
}
int
F_166 ( struct V_7 * V_8 ,
bool V_231 )
{
if ( F_6 ( & V_8 -> V_10 . V_21 ) ) {
struct V_16 * V_17 = & V_8 -> V_18 ;
bool V_232 ;
unsigned long V_19 ;
F_9 ( & V_17 -> V_24 . V_25 , V_19 ) ;
V_232 = V_17 -> V_26 > 0 ;
F_10 ( & V_17 -> V_24 . V_25 , V_19 ) ;
if ( ! V_231 )
return - V_23 ;
if ( V_232 )
return - V_23 ;
return - V_156 ;
}
return 0 ;
}
static int
F_167 ( struct V_179 * V_180 , T_4 V_181 )
{
int V_20 = 0 ;
F_115 ( ! F_168 ( & V_180 -> V_14 -> V_27 ) ) ;
if ( V_181 == V_180 -> V_199 ) {
struct V_200 * V_201 ;
V_201 = F_165 ( sizeof( * V_201 ) , V_230 ) ;
if ( V_201 == NULL )
return - V_49 ;
V_20 = F_138 ( V_180 , NULL , V_201 ) ;
if ( V_20 ) {
F_29 ( V_201 ) ;
return V_20 ;
}
F_115 ( V_181 != V_201 -> V_181 ) ;
}
return V_20 ;
}
static int F_169 ( struct V_179 * V_180 , T_4 V_181 ,
bool V_231 , struct V_233 * V_234 )
{
T_5 * V_8 = V_180 -> V_14 -> V_15 ;
struct V_233 V_235 , V_236 , V_237 = { 1 , 0 } ;
unsigned long V_238 ;
long V_78 ;
bool V_239 = true ;
int V_20 ;
if ( F_159 ( V_180 -> V_222 ( V_180 ) , V_181 ) )
return 0 ;
F_170 ( V_180 , V_181 ) ;
if ( V_234 != NULL ) {
V_237 = * V_234 ;
V_239 = false ;
}
V_238 = F_171 ( & V_237 ) ;
if ( F_13 ( ! V_180 -> V_240 ( V_180 ) ) )
return - V_34 ;
F_172 ( & V_235 ) ;
#define F_173 \
(i915_seqno_passed(ring->get_seqno(ring), seqno) || \
atomic_read(&dev_priv->mm.wedged))
do {
if ( V_231 )
V_78 = F_174 ( V_180 -> V_241 ,
F_173 ,
V_238 ) ;
else
V_78 = F_175 ( V_180 -> V_241 , F_173 ,
V_238 ) ;
V_20 = F_166 ( V_8 , V_231 ) ;
if ( V_20 )
V_78 = V_20 ;
} while ( V_78 == 0 && V_239 );
F_172 ( & V_236 ) ;
V_180 -> V_226 ( V_180 ) ;
F_176 ( V_180 , V_181 ) ;
#undef F_173
if ( V_234 ) {
struct V_233 V_242 = F_177 ( V_236 , V_235 ) ;
* V_234 = F_177 ( * V_234 , V_242 ) ;
}
switch ( V_78 ) {
case - V_23 :
case - V_156 :
case - V_157 :
return ( int ) V_78 ;
case 0 :
if ( V_234 )
F_178 ( V_234 , 0 , 0 ) ;
return - V_243 ;
default:
F_13 ( V_78 < 0 ) ;
return 0 ;
}
}
int
F_179 ( struct V_179 * V_180 , T_3 V_181 )
{
T_5 * V_8 = V_180 -> V_14 -> V_15 ;
int V_20 = 0 ;
F_115 ( V_181 == 0 ) ;
V_20 = F_166 ( V_8 , V_8 -> V_10 . V_231 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_167 ( V_180 , V_181 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_169 ( V_180 , V_181 , V_8 -> V_10 . V_231 , NULL ) ;
return V_20 ;
}
int
F_180 ( struct V_1 * V_2 )
{
int V_20 ;
F_115 ( ( V_2 -> V_50 . V_122 & V_131 ) != 0 ) ;
if ( V_2 -> V_28 ) {
V_20 = F_179 ( V_2 -> V_180 , V_2 -> V_184 ) ;
if ( V_20 )
return V_20 ;
F_157 ( V_2 -> V_180 ) ;
}
return 0 ;
}
static int
F_181 ( struct V_1 * V_2 )
{
int V_20 ;
if ( V_2 -> V_28 ) {
V_20 = F_182 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_167 ( V_2 -> V_180 ,
V_2 -> V_184 ) ;
if ( V_20 )
return V_20 ;
F_157 ( V_2 -> V_180 ) ;
}
return 0 ;
}
int
F_183 ( struct V_13 * V_14 , void * V_29 , struct V_30 * V_31 )
{
struct V_244 * args = V_29 ;
struct V_1 * V_2 ;
struct V_179 * V_180 = NULL ;
struct V_233 V_245 , * V_234 = NULL ;
T_4 V_181 = 0 ;
int V_20 = 0 ;
if ( args -> V_246 >= 0 ) {
V_245 = F_184 ( args -> V_246 ) ;
V_234 = & V_245 ;
}
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_31 , args -> V_247 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
F_21 ( & V_14 -> V_27 ) ;
return - V_107 ;
}
V_20 = F_181 ( V_2 ) ;
if ( V_20 )
goto V_101;
if ( V_2 -> V_28 ) {
V_181 = V_2 -> V_184 ;
V_180 = V_2 -> V_180 ;
}
if ( V_181 == 0 )
goto V_101;
if ( ! args -> V_246 ) {
V_20 = - V_243 ;
goto V_101;
}
F_30 ( & V_2 -> V_50 ) ;
F_21 ( & V_14 -> V_27 ) ;
V_20 = F_169 ( V_180 , V_181 , true , V_234 ) ;
if ( V_234 ) {
F_13 ( ! F_185 ( V_234 ) ) ;
args -> V_246 = F_186 ( V_234 ) ;
}
return V_20 ;
V_101:
F_30 ( & V_2 -> V_50 ) ;
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_187 ( struct V_1 * V_2 ,
struct V_179 * V_248 )
{
struct V_179 * V_249 = V_2 -> V_180 ;
T_4 V_181 ;
int V_20 , V_250 ;
if ( V_249 == NULL || V_248 == V_249 )
return 0 ;
if ( V_248 == NULL || ! F_188 ( V_2 -> V_50 . V_14 ) )
return F_180 ( V_2 ) ;
V_250 = F_189 ( V_249 , V_248 ) ;
V_181 = V_2 -> V_184 ;
if ( V_181 <= V_249 -> V_223 [ V_250 ] )
return 0 ;
V_20 = F_167 ( V_2 -> V_180 , V_181 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_248 -> V_251 ( V_248 , V_249 , V_181 ) ;
if ( ! V_20 )
V_249 -> V_223 [ V_250 ] = V_181 ;
return V_20 ;
}
static void F_190 ( struct V_1 * V_2 )
{
T_4 V_197 , V_252 ;
F_191 () ;
F_2 ( V_2 ) ;
if ( ( V_2 -> V_50 . V_95 & V_132 ) == 0 )
return;
V_252 = V_2 -> V_50 . V_95 ;
V_197 = V_2 -> V_50 . V_122 ;
V_2 -> V_50 . V_95 &= ~ V_132 ;
V_2 -> V_50 . V_122 &= ~ V_132 ;
F_136 ( V_2 ,
V_252 ,
V_197 ) ;
}
int
F_99 ( struct V_1 * V_2 )
{
T_5 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_20 = 0 ;
if ( V_2 -> V_43 == NULL )
return 0 ;
if ( V_2 -> V_42 )
return - V_253 ;
V_20 = F_192 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_190 ( V_2 ) ;
if ( V_20 == 0 )
V_20 = F_91 ( V_2 , 1 ) ;
if ( V_20 == - V_157 )
return V_20 ;
if ( V_20 ) {
F_84 ( V_2 ) ;
V_2 -> V_50 . V_95 = V_2 -> V_50 . V_122 = V_96 ;
}
V_20 = F_78 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_193 ( V_2 ) ;
if ( V_2 -> V_150 )
F_194 ( V_2 ) ;
if ( V_2 -> V_254 ) {
F_195 ( V_8 -> V_10 . V_255 , V_2 ) ;
V_2 -> V_254 = 0 ;
}
F_196 ( V_2 ) ;
F_121 ( V_2 ) ;
F_126 ( & V_2 -> V_256 ) ;
F_126 ( & V_2 -> V_151 ) ;
V_2 -> V_129 = true ;
F_197 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
V_2 -> V_117 = 0 ;
if ( F_132 ( V_2 ) )
F_66 ( V_2 ) ;
return V_20 ;
}
int
F_139 ( struct V_179 * V_180 ,
T_3 V_257 ,
T_3 V_195 )
{
int V_20 ;
if ( ( ( V_257 | V_195 ) & V_131 ) == 0 )
return 0 ;
F_198 ( V_180 , V_257 , V_195 ) ;
V_20 = V_180 -> V_258 ( V_180 , V_257 , V_195 ) ;
if ( V_20 )
return V_20 ;
if ( V_195 & V_131 )
F_133 ( V_180 , V_195 ) ;
return 0 ;
}
static int F_199 ( struct V_179 * V_180 )
{
int V_20 ;
if ( F_129 ( & V_180 -> V_193 ) && F_129 ( & V_180 -> V_182 ) )
return 0 ;
if ( ! F_129 ( & V_180 -> V_193 ) ) {
V_20 = F_139 ( V_180 ,
V_131 , V_131 ) ;
if ( V_20 )
return V_20 ;
}
return F_179 ( V_180 , F_135 ( V_180 ) ) ;
}
int F_200 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_179 * V_180 ;
int V_20 , V_174 ;
F_156 (ring, dev_priv, i) {
V_20 = F_201 ( V_180 , NULL , V_259 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_199 ( V_180 ) ;
if ( V_20 )
return V_20 ;
if ( F_13 ( ! F_129 ( & V_180 -> V_193 ) ) )
return - V_253 ;
}
return 0 ;
}
static void F_202 ( struct V_13 * V_14 , int V_188 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_2 V_260 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_43 -> V_9 ;
V_260 = ( T_2 ) ( ( V_2 -> V_117 + V_9 - 4096 ) &
0xfffff000 ) << 32 ;
V_260 |= V_2 -> V_117 & 0xfffff000 ;
V_260 |= ( T_2 ) ( ( V_2 -> V_261 / 128 ) - 1 ) <<
V_262 ;
if ( V_2 -> V_3 == V_263 )
V_260 |= 1 << V_264 ;
V_260 |= V_265 ;
} else
V_260 = 0 ;
F_203 ( V_266 + V_188 * 8 , V_260 ) ;
F_204 ( V_266 + V_188 * 8 ) ;
}
static void F_205 ( struct V_13 * V_14 , int V_188 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_2 V_260 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_43 -> V_9 ;
V_260 = ( T_2 ) ( ( V_2 -> V_117 + V_9 - 4096 ) &
0xfffff000 ) << 32 ;
V_260 |= V_2 -> V_117 & 0xfffff000 ;
V_260 |= ( ( V_2 -> V_261 / 128 ) - 1 ) << V_267 ;
if ( V_2 -> V_3 == V_263 )
V_260 |= 1 << V_264 ;
V_260 |= V_265 ;
} else
V_260 = 0 ;
F_203 ( V_268 + V_188 * 8 , V_260 ) ;
F_204 ( V_268 + V_188 * 8 ) ;
}
static void F_206 ( struct V_13 * V_14 , int V_188 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_4 V_260 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_43 -> V_9 ;
int V_269 ;
int V_270 ;
F_207 ( ( V_2 -> V_117 & ~ V_271 ) ||
( V_9 & - V_9 ) != V_9 ||
( V_2 -> V_117 & ( V_9 - 1 ) ) ,
L_3 ,
V_2 -> V_117 , V_2 -> V_129 , V_9 ) ;
if ( V_2 -> V_3 == V_263 && F_208 ( V_14 ) )
V_270 = 128 ;
else
V_270 = 512 ;
V_269 = V_2 -> V_261 / V_270 ;
V_269 = F_209 ( V_269 ) - 1 ;
V_260 = V_2 -> V_117 ;
if ( V_2 -> V_3 == V_263 )
V_260 |= 1 << V_272 ;
V_260 |= F_210 ( V_9 ) ;
V_260 |= V_269 << V_273 ;
V_260 |= V_274 ;
} else
V_260 = 0 ;
if ( V_188 < 8 )
V_188 = V_275 + V_188 * 4 ;
else
V_188 = V_276 + ( V_188 - 8 ) * 4 ;
F_211 ( V_188 , V_260 ) ;
F_204 ( V_188 ) ;
}
static void F_212 ( struct V_13 * V_14 , int V_188 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_3 V_260 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_43 -> V_9 ;
T_3 V_269 ;
F_207 ( ( V_2 -> V_117 & ~ V_277 ) ||
( V_9 & - V_9 ) != V_9 ||
( V_2 -> V_117 & ( V_9 - 1 ) ) ,
L_4 ,
V_2 -> V_117 , V_9 ) ;
V_269 = V_2 -> V_261 / 128 ;
V_269 = F_209 ( V_269 ) - 1 ;
V_260 = V_2 -> V_117 ;
if ( V_2 -> V_3 == V_263 )
V_260 |= 1 << V_272 ;
V_260 |= F_213 ( V_9 ) ;
V_260 |= V_269 << V_273 ;
V_260 |= V_274 ;
} else
V_260 = 0 ;
F_211 ( V_275 + V_188 * 4 , V_260 ) ;
F_204 ( V_275 + V_188 * 4 ) ;
}
static void F_153 ( struct V_13 * V_14 , int V_188 ,
struct V_1 * V_2 )
{
switch ( F_18 ( V_14 ) -> V_39 ) {
case 7 :
case 6 : F_202 ( V_14 , V_188 , V_2 ) ; break;
case 5 :
case 4 : F_205 ( V_14 , V_188 , V_2 ) ; break;
case 3 : F_206 ( V_14 , V_188 , V_2 ) ; break;
case 2 : F_212 ( V_14 , V_188 , V_2 ) ; break;
default: break;
}
}
static inline int F_214 ( struct V_7 * V_8 ,
struct V_187 * V_278 )
{
return V_278 - V_8 -> V_189 ;
}
static void F_215 ( struct V_1 * V_2 ,
struct V_187 * V_278 ,
bool V_279 )
{
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_188 = F_214 ( V_8 , V_278 ) ;
F_153 ( V_2 -> V_50 . V_14 , V_188 , V_279 ? V_2 : NULL ) ;
if ( V_279 ) {
V_2 -> V_5 = V_188 ;
V_278 -> V_2 = V_2 ;
F_103 ( & V_278 -> V_190 , & V_8 -> V_10 . V_191 ) ;
} else {
V_2 -> V_5 = V_6 ;
V_278 -> V_2 = NULL ;
F_126 ( & V_278 -> V_190 ) ;
}
}
static int
F_216 ( struct V_1 * V_2 )
{
int V_20 ;
if ( V_2 -> V_185 ) {
if ( V_2 -> V_50 . V_122 & V_131 ) {
V_20 = F_139 ( V_2 -> V_180 ,
0 , V_2 -> V_50 . V_122 ) ;
if ( V_20 )
return V_20 ;
}
V_2 -> V_185 = false ;
}
if ( V_2 -> V_186 ) {
V_20 = F_179 ( V_2 -> V_180 , V_2 -> V_186 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_186 = 0 ;
}
if ( V_2 -> V_50 . V_95 & V_132 )
F_191 () ;
return 0 ;
}
int
F_78 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
int V_20 ;
V_20 = F_216 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( V_2 -> V_5 == V_6 )
return 0 ;
F_215 ( V_2 ,
& V_8 -> V_189 [ V_2 -> V_5 ] ,
false ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static struct V_187 *
F_217 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_187 * V_188 , * V_280 ;
int V_174 ;
V_280 = NULL ;
for ( V_174 = V_8 -> V_281 ; V_174 < V_8 -> V_221 ; V_174 ++ ) {
V_188 = & V_8 -> V_189 [ V_174 ] ;
if ( ! V_188 -> V_2 )
return V_188 ;
if ( ! V_188 -> V_42 )
V_280 = V_188 ;
}
if ( V_280 == NULL )
return NULL ;
F_23 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_188 -> V_42 )
continue;
return V_188 ;
}
return NULL ;
}
int
F_102 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
bool V_279 = V_2 -> V_3 != V_59 ;
struct V_187 * V_188 ;
int V_20 ;
if ( V_2 -> V_4 ) {
V_20 = F_216 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_2 -> V_5 != V_6 ) {
V_188 = & V_8 -> V_189 [ V_2 -> V_5 ] ;
if ( ! V_2 -> V_4 ) {
F_103 ( & V_188 -> V_190 ,
& V_8 -> V_10 . V_191 ) ;
return 0 ;
}
} else if ( V_279 ) {
V_188 = F_217 ( V_14 ) ;
if ( V_188 == NULL )
return - V_282 ;
if ( V_188 -> V_2 ) {
struct V_1 * V_283 = V_188 -> V_2 ;
V_20 = F_216 ( V_283 ) ;
if ( V_20 )
return V_20 ;
F_1 ( V_283 ) ;
}
} else
return 0 ;
F_215 ( V_2 , V_188 , V_279 ) ;
V_2 -> V_4 = false ;
return 0 ;
}
static int
F_100 ( struct V_1 * V_2 ,
unsigned V_284 ,
bool V_129 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
struct V_285 * V_286 ;
T_11 V_172 = V_287 | V_288 ;
T_4 V_9 , V_289 , V_290 , V_291 ;
bool V_292 , V_293 ;
int V_20 ;
if ( V_2 -> V_104 != V_168 ) {
F_8 ( L_5 ) ;
return - V_38 ;
}
V_289 = F_107 ( V_14 ,
V_2 -> V_50 . V_9 ,
V_2 -> V_3 ) ;
V_290 = F_108 ( V_14 ,
V_2 -> V_50 . V_9 ,
V_2 -> V_3 ) ;
V_291 =
F_109 ( V_14 ,
V_2 -> V_50 . V_9 ,
V_2 -> V_3 ) ;
if ( V_284 == 0 )
V_284 = V_129 ? V_290 :
V_291 ;
if ( V_129 && V_284 & ( V_290 - 1 ) ) {
F_8 ( L_6 , V_284 ) ;
return - V_38 ;
}
V_9 = V_129 ? V_289 : V_2 -> V_50 . V_9 ;
if ( V_2 -> V_50 . V_9 >
( V_129 ? V_8 -> V_10 . V_166 : V_8 -> V_10 . V_45 ) ) {
F_8 ( L_7 ) ;
return - V_167 ;
}
V_294:
if ( V_129 )
V_286 =
F_218 ( & V_8 -> V_10 . V_43 ,
V_9 , V_284 ,
0 , V_8 -> V_10 . V_166 ,
0 ) ;
else
V_286 = F_219 ( & V_8 -> V_10 . V_43 ,
V_9 , V_284 , 0 ) ;
if ( V_286 != NULL ) {
if ( V_129 )
V_2 -> V_43 =
F_220 ( V_286 ,
V_9 , V_284 , 0 ,
0 , V_8 -> V_10 . V_166 ,
0 ) ;
else
V_2 -> V_43 =
F_221 ( V_286 , V_9 , V_284 ) ;
}
if ( V_2 -> V_43 == NULL ) {
V_20 = F_222 ( V_14 , V_9 , V_284 ,
V_129 ) ;
if ( V_20 )
return V_20 ;
goto V_294;
}
V_20 = F_114 ( V_2 , V_172 ) ;
if ( V_20 ) {
F_197 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
if ( V_20 == - V_49 ) {
V_20 = F_223 ( V_14 , false ) ;
if ( V_20 ) {
if ( V_172 ) {
V_172 = 0 ;
goto V_294;
}
return - V_49 ;
}
goto V_294;
}
return V_20 ;
}
V_20 = F_224 ( V_2 ) ;
if ( V_20 ) {
F_121 ( V_2 ) ;
F_197 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
if ( F_223 ( V_14 , false ) )
return V_20 ;
goto V_294;
}
if ( ! V_8 -> V_10 . V_255 )
F_101 ( V_2 , V_2 -> V_97 ) ;
F_142 ( & V_2 -> V_256 , & V_8 -> V_10 . V_256 ) ;
F_142 ( & V_2 -> V_151 , & V_8 -> V_10 . V_152 ) ;
F_115 ( V_2 -> V_50 . V_95 & V_131 ) ;
F_115 ( V_2 -> V_50 . V_122 & V_131 ) ;
V_2 -> V_117 = V_2 -> V_43 -> V_77 ;
V_293 =
V_2 -> V_43 -> V_9 == V_289 &&
( V_2 -> V_43 -> V_77 & ( V_290 - 1 ) ) == 0 ;
V_292 =
V_2 -> V_117 + V_2 -> V_50 . V_9 <= V_8 -> V_10 . V_166 ;
V_2 -> V_129 = V_292 && V_293 ;
F_225 ( V_2 , V_129 ) ;
return 0 ;
}
void
F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_99 == NULL )
return;
if ( V_2 -> V_97 != V_98 )
return;
F_226 ( V_2 ) ;
F_227 ( V_2 -> V_99 , V_2 -> V_50 . V_9 / V_37 ) ;
}
static int
F_182 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_50 . V_122 & V_131 ) == 0 )
return 0 ;
return F_139 ( V_2 -> V_180 , 0 , V_2 -> V_50 . V_122 ) ;
}
static void
F_228 ( struct V_1 * V_2 )
{
T_3 V_197 ;
if ( V_2 -> V_50 . V_122 != V_132 )
return;
F_229 () ;
V_197 = V_2 -> V_50 . V_122 ;
V_2 -> V_50 . V_122 = 0 ;
F_136 ( V_2 ,
V_2 -> V_50 . V_95 ,
V_197 ) ;
}
static void
F_93 ( struct V_1 * V_2 )
{
T_3 V_197 ;
if ( V_2 -> V_50 . V_122 != V_96 )
return;
F_84 ( V_2 ) ;
F_85 () ;
V_197 = V_2 -> V_50 . V_122 ;
V_2 -> V_50 . V_122 = 0 ;
F_136 ( V_2 ,
V_2 -> V_50 . V_95 ,
V_197 ) ;
}
int
F_56 ( struct V_1 * V_2 , bool V_146 )
{
T_5 * V_8 = V_2 -> V_50 . V_14 -> V_15 ;
T_3 V_197 , V_252 ;
int V_20 ;
if ( V_2 -> V_43 == NULL )
return - V_38 ;
if ( V_2 -> V_50 . V_122 == V_132 )
return 0 ;
V_20 = F_182 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( V_2 -> V_194 || V_146 ) {
V_20 = F_180 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
F_93 ( V_2 ) ;
V_197 = V_2 -> V_50 . V_122 ;
V_252 = V_2 -> V_50 . V_95 ;
F_115 ( ( V_2 -> V_50 . V_122 & ~ V_132 ) != 0 ) ;
V_2 -> V_50 . V_95 |= V_132 ;
if ( V_146 ) {
V_2 -> V_50 . V_95 = V_132 ;
V_2 -> V_50 . V_122 = V_132 ;
V_2 -> V_123 = 1 ;
}
F_136 ( V_2 ,
V_252 ,
V_197 ) ;
if ( F_15 ( V_2 ) )
F_103 ( & V_2 -> V_151 , & V_8 -> V_10 . V_152 ) ;
return 0 ;
}
int F_230 ( struct V_1 * V_2 ,
enum V_295 V_97 )
{
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
if ( V_2 -> V_97 == V_97 )
return 0 ;
if ( V_2 -> V_42 ) {
F_231 ( L_8 ) ;
return - V_253 ;
}
if ( V_2 -> V_43 ) {
V_20 = F_192 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_190 ( V_2 ) ;
if ( F_18 ( V_2 -> V_50 . V_14 ) -> V_39 < 6 ) {
V_20 = F_78 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_2 -> V_150 )
F_101 ( V_2 , V_97 ) ;
if ( V_2 -> V_254 )
F_232 ( V_8 -> V_10 . V_255 ,
V_2 , V_97 ) ;
}
if ( V_97 == V_98 ) {
T_4 V_252 , V_197 ;
F_13 ( V_2 -> V_50 . V_122 & ~ V_96 ) ;
F_13 ( V_2 -> V_50 . V_95 & ~ V_96 ) ;
V_252 = V_2 -> V_50 . V_95 ;
V_197 = V_2 -> V_50 . V_122 ;
V_2 -> V_50 . V_95 = V_96 ;
V_2 -> V_50 . V_122 = V_96 ;
F_136 ( V_2 ,
V_252 ,
V_197 ) ;
}
V_2 -> V_97 = V_97 ;
return 0 ;
}
int
F_233 ( struct V_1 * V_2 ,
T_4 V_284 ,
struct V_179 * V_296 )
{
T_4 V_252 , V_197 ;
int V_20 ;
V_20 = F_182 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( V_296 != V_2 -> V_180 ) {
V_20 = F_187 ( V_2 , V_296 ) ;
if ( V_20 )
return V_20 ;
}
V_20 = F_230 ( V_2 , V_98 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_77 ( V_2 , V_284 , true ) ;
if ( V_20 )
return V_20 ;
F_93 ( V_2 ) ;
V_197 = V_2 -> V_50 . V_122 ;
V_252 = V_2 -> V_50 . V_95 ;
F_115 ( ( V_2 -> V_50 . V_122 & ~ V_132 ) != 0 ) ;
V_2 -> V_50 . V_95 |= V_132 ;
F_136 ( V_2 ,
V_252 ,
V_197 ) ;
return 0 ;
}
int
F_192 ( struct V_1 * V_2 )
{
int V_20 ;
if ( ( V_2 -> V_50 . V_95 & V_131 ) == 0 )
return 0 ;
if ( V_2 -> V_50 . V_122 & V_131 ) {
V_20 = F_139 ( V_2 -> V_180 , 0 , V_2 -> V_50 . V_122 ) ;
if ( V_20 )
return V_20 ;
}
V_20 = F_180 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_50 . V_95 &= ~ V_131 ;
return 0 ;
}
int
F_91 ( struct V_1 * V_2 , bool V_146 )
{
T_3 V_197 , V_252 ;
int V_20 ;
if ( V_2 -> V_50 . V_122 == V_96 )
return 0 ;
V_20 = F_182 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( V_146 || V_2 -> V_194 ) {
V_20 = F_180 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
F_228 ( V_2 ) ;
V_197 = V_2 -> V_50 . V_122 ;
V_252 = V_2 -> V_50 . V_95 ;
if ( ( V_2 -> V_50 . V_95 & V_96 ) == 0 ) {
F_84 ( V_2 ) ;
V_2 -> V_50 . V_95 |= V_96 ;
}
F_115 ( ( V_2 -> V_50 . V_122 & ~ V_96 ) != 0 ) ;
if ( V_146 ) {
V_2 -> V_50 . V_95 = V_96 ;
V_2 -> V_50 . V_122 = V_96 ;
}
F_136 ( V_2 ,
V_252 ,
V_197 ) ;
return 0 ;
}
static int
F_234 ( struct V_13 * V_14 , struct V_30 * V_31 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_211 * V_212 = V_31 -> V_213 ;
unsigned long V_297 = V_208 - F_146 ( 20 ) ;
struct V_200 * V_201 ;
struct V_179 * V_180 = NULL ;
T_4 V_181 = 0 ;
int V_20 ;
if ( F_6 ( & V_8 -> V_10 . V_21 ) )
return - V_23 ;
F_143 ( & V_212 -> V_10 . V_25 ) ;
F_23 (request, &file_priv->mm.request_list, client_list) {
if ( F_235 ( V_201 -> V_207 , V_297 ) )
break;
V_180 = V_201 -> V_180 ;
V_181 = V_201 -> V_181 ;
}
F_144 ( & V_212 -> V_10 . V_25 ) ;
if ( V_181 == 0 )
return 0 ;
V_20 = F_169 ( V_180 , V_181 , true , NULL ) ;
if ( V_20 == 0 )
F_147 ( V_8 -> V_219 , & V_8 -> V_10 . V_220 , 0 ) ;
return V_20 ;
}
int
F_77 ( struct V_1 * V_2 ,
T_3 V_284 ,
bool V_129 )
{
int V_20 ;
if ( F_13 ( V_2 -> V_42 == V_298 ) )
return - V_253 ;
if ( V_2 -> V_43 != NULL ) {
if ( ( V_284 && V_2 -> V_117 & ( V_284 - 1 ) ) ||
( V_129 && ! V_2 -> V_129 ) ) {
F_207 ( V_2 -> V_42 ,
L_9
L_10
L_11 ,
V_2 -> V_117 , V_284 ,
V_129 ,
V_2 -> V_129 ) ;
V_20 = F_99 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
}
if ( V_2 -> V_43 == NULL ) {
V_20 = F_100 ( V_2 , V_284 ,
V_129 ) ;
if ( V_20 )
return V_20 ;
}
if ( ! V_2 -> V_150 && V_129 )
F_101 ( V_2 , V_2 -> V_97 ) ;
V_2 -> V_42 ++ ;
V_2 -> V_299 |= V_129 ;
return 0 ;
}
void
F_79 ( struct V_1 * V_2 )
{
F_115 ( V_2 -> V_42 == 0 ) ;
F_115 ( V_2 -> V_43 == NULL ) ;
if ( -- V_2 -> V_42 == 0 )
V_2 -> V_299 = false ;
}
int
F_236 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_300 * args = V_29 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_31 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_107 ;
goto V_108;
}
if ( V_2 -> V_104 != V_168 ) {
F_8 ( L_12 ) ;
V_20 = - V_38 ;
goto V_101;
}
if ( V_2 -> V_301 != NULL && V_2 -> V_301 != V_31 ) {
F_8 ( L_13 ,
args -> V_48 ) ;
V_20 = - V_38 ;
goto V_101;
}
V_2 -> V_302 ++ ;
V_2 -> V_301 = V_31 ;
if ( V_2 -> V_302 == 1 ) {
V_20 = F_77 ( V_2 , args -> V_284 , true ) ;
if ( V_20 )
goto V_101;
}
F_93 ( V_2 ) ;
args -> V_88 = V_2 -> V_117 ;
V_101:
F_30 ( & V_2 -> V_50 ) ;
V_108:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_237 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_300 * args = V_29 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_31 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_107 ;
goto V_108;
}
if ( V_2 -> V_301 != V_31 ) {
F_8 ( L_14 ,
args -> V_48 ) ;
V_20 = - V_38 ;
goto V_101;
}
V_2 -> V_302 -- ;
if ( V_2 -> V_302 == 0 ) {
V_2 -> V_301 = NULL ;
F_79 ( V_2 ) ;
}
V_101:
F_30 ( & V_2 -> V_50 ) ;
V_108:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_238 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_303 * args = V_29 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_31 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_107 ;
goto V_108;
}
V_20 = F_181 ( V_2 ) ;
args -> V_304 = V_2 -> V_28 ;
F_30 ( & V_2 -> V_50 ) ;
V_108:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_239 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_212 )
{
return F_234 ( V_14 , V_212 ) ;
}
int
F_240 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_212 )
{
struct V_305 * args = V_29 ;
struct V_1 * V_2 ;
int V_20 ;
switch ( args -> V_104 ) {
case V_178 :
case V_168 :
break;
default:
return - V_38 ;
}
V_20 = F_11 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_69 ( F_70 ( V_14 , V_212 , args -> V_48 ) ) ;
if ( & V_2 -> V_50 == NULL ) {
V_20 = - V_107 ;
goto V_108;
}
if ( V_2 -> V_42 ) {
V_20 = - V_38 ;
goto V_101;
}
if ( V_2 -> V_104 != V_105 )
V_2 -> V_104 = args -> V_104 ;
if ( F_132 ( V_2 ) &&
V_2 -> V_43 == NULL )
F_66 ( V_2 ) ;
args -> V_306 = V_2 -> V_104 != V_105 ;
V_101:
F_30 ( & V_2 -> V_50 ) ;
V_108:
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
struct V_1 * F_26 ( struct V_13 * V_14 ,
T_1 V_9 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_1 * V_2 ;
struct V_80 * V_81 ;
T_4 V_307 ;
V_2 = F_165 ( sizeof( * V_2 ) , V_230 ) ;
if ( V_2 == NULL )
return NULL ;
if ( F_241 ( V_14 , & V_2 -> V_50 , V_9 ) != 0 ) {
F_29 ( V_2 ) ;
return NULL ;
}
V_307 = V_308 | V_309 ;
if ( F_242 ( V_14 ) || F_243 ( V_14 ) ) {
V_307 &= ~ V_310 ;
V_307 |= V_311 ;
}
V_81 = V_2 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
F_244 ( V_81 , V_307 ) ;
F_3 ( V_8 , V_9 ) ;
V_2 -> V_50 . V_122 = V_96 ;
V_2 -> V_50 . V_95 = V_96 ;
if ( F_245 ( V_14 ) ) {
V_2 -> V_97 = V_312 ;
} else
V_2 -> V_97 = V_98 ;
V_2 -> V_50 . V_313 = NULL ;
V_2 -> V_5 = V_6 ;
F_154 ( & V_2 -> V_151 ) ;
F_154 ( & V_2 -> V_256 ) ;
F_154 ( & V_2 -> V_183 ) ;
F_154 ( & V_2 -> V_314 ) ;
F_154 ( & V_2 -> V_193 ) ;
V_2 -> V_104 = V_168 ;
V_2 -> V_129 = true ;
return V_2 ;
}
int F_246 ( struct V_135 * V_2 )
{
F_247 () ;
return 0 ;
}
void F_248 ( struct V_135 * V_315 )
{
struct V_1 * V_2 = F_69 ( V_315 ) ;
struct V_13 * V_14 = V_2 -> V_50 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
F_249 ( V_2 ) ;
if ( V_315 -> V_316 )
F_250 ( V_315 , V_2 -> V_176 ) ;
if ( V_2 -> V_128 )
F_251 ( V_14 , V_2 ) ;
V_2 -> V_42 = 0 ;
if ( F_13 ( F_99 ( V_2 ) == - V_157 ) ) {
bool V_317 ;
V_317 = V_8 -> V_10 . V_231 ;
V_8 -> V_10 . V_231 = false ;
F_13 ( F_99 ( V_2 ) ) ;
V_8 -> V_10 . V_231 = V_317 ;
}
if ( V_2 -> V_50 . V_162 . V_169 )
F_131 ( & V_2 -> V_50 ) ;
F_28 ( & V_2 -> V_50 ) ;
F_4 ( V_8 , V_2 -> V_50 . V_9 ) ;
F_29 ( V_2 -> V_318 ) ;
F_29 ( V_2 ) ;
}
int
F_252 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
F_19 ( & V_14 -> V_27 ) ;
if ( V_8 -> V_10 . V_215 ) {
F_21 ( & V_14 -> V_27 ) ;
return 0 ;
}
V_20 = F_200 ( V_14 ) ;
if ( V_20 ) {
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
F_161 ( V_14 ) ;
if ( ! F_17 ( V_14 , V_33 ) )
F_223 ( V_14 , false ) ;
F_152 ( V_14 ) ;
V_8 -> V_10 . V_215 = 1 ;
F_253 ( & V_8 -> V_217 ) ;
F_254 ( V_14 ) ;
F_255 ( V_14 ) ;
F_21 ( & V_14 -> V_27 ) ;
F_256 ( & V_8 -> V_10 . V_220 ) ;
return 0 ;
}
void F_257 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_4 V_319 ;
int V_174 ;
if ( ! F_258 ( V_14 ) )
return;
if ( ! V_8 -> V_10 . V_320 )
return;
V_319 = F_259 ( V_321 ) ;
F_211 ( V_321 , V_319 & ~ V_322 ) ;
F_204 ( V_321 ) ;
for ( V_174 = 0 ; V_174 < V_323 ; V_174 += 4 ) {
T_4 V_324 = F_259 ( V_325 + V_174 ) ;
if ( V_324 && V_324 != V_8 -> V_10 . V_320 [ V_174 / 4 ] )
F_231 ( L_15 ,
V_325 + V_174 , V_324 ) ;
if ( V_324 && ! V_8 -> V_10 . V_320 [ V_174 / 4 ] )
F_260 ( L_16 ) ;
F_211 ( V_325 + V_174 , V_8 -> V_10 . V_320 [ V_174 / 4 ] ) ;
}
F_204 ( V_325 ) ;
F_211 ( V_321 , V_319 ) ;
}
void F_261 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
if ( F_18 ( V_14 ) -> V_39 < 5 ||
V_8 -> V_10 . V_57 == V_326 )
return;
F_211 ( V_327 , F_259 ( V_327 ) |
V_328 ) ;
if ( F_262 ( V_14 ) )
return;
F_211 ( V_329 , F_259 ( V_329 ) | V_330 ) ;
if ( F_263 ( V_14 ) )
F_211 ( V_331 , F_264 ( V_332 ) ) ;
else
F_211 ( V_331 , F_264 ( V_333 ) ) ;
}
void F_265 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_3 V_334 ;
struct V_179 * V_180 ;
struct V_335 * V_336 = V_8 -> V_10 . V_255 ;
T_3 T_9 * V_337 ;
T_3 V_338 ;
int V_174 ;
if ( ! V_8 -> V_10 . V_255 )
return;
V_337 = V_8 -> V_10 . V_339 -> V_339 + V_336 -> V_334 / sizeof( T_3 ) ;
for ( V_174 = 0 ; V_174 < V_336 -> V_340 ; V_174 ++ ) {
T_12 V_341 ;
if ( V_8 -> V_10 . V_339 -> V_342 )
V_341 = V_336 -> V_343 [ V_174 ] ;
else
V_341 = F_61 ( V_336 -> V_344 [ V_174 ] ) ;
V_338 = F_266 ( V_341 ) ;
V_338 |= V_345 ;
F_267 ( V_338 , V_337 + V_174 ) ;
}
F_268 ( V_337 ) ;
V_334 = V_336 -> V_334 ;
V_334 /= 64 ;
V_334 <<= 16 ;
if ( F_18 ( V_14 ) -> V_39 == 6 ) {
T_3 V_346 , V_347 , V_348 ;
V_348 = F_259 ( V_349 ) ;
F_211 ( V_349 , V_348 | V_350 ) ;
V_347 = F_259 ( V_351 ) ;
F_211 ( V_351 , V_347 | V_352 ) ;
V_346 = F_259 ( V_353 ) ;
F_211 ( V_353 , V_346 | V_354 |
V_355 ) ;
F_211 ( V_356 , F_264 ( V_357 ) ) ;
} else if ( F_18 ( V_14 ) -> V_39 >= 7 ) {
F_211 ( V_353 , V_355 ) ;
}
F_156 (ring, dev_priv, i) {
if ( F_18 ( V_14 ) -> V_39 >= 7 )
F_211 ( F_269 ( V_180 ) ,
F_264 ( V_357 ) ) ;
F_211 ( F_270 ( V_180 ) , V_358 ) ;
F_211 ( F_271 ( V_180 ) , V_334 ) ;
}
}
static bool
F_272 ( struct V_13 * V_14 )
{
if ( ! F_273 ( V_14 ) )
return false ;
if ( F_263 ( V_14 ) && V_14 -> V_359 -> V_360 < 8 ) {
F_274 ( L_17
L_18 ) ;
return false ;
}
return true ;
}
int
F_275 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
if ( ! F_276 () )
return - V_23 ;
F_257 ( V_14 ) ;
F_261 ( V_14 ) ;
V_20 = F_277 ( V_14 ) ;
if ( V_20 )
return V_20 ;
if ( F_278 ( V_14 ) ) {
V_20 = F_279 ( V_14 ) ;
if ( V_20 )
goto V_361;
}
if ( F_272 ( V_14 ) ) {
V_20 = F_280 ( V_14 ) ;
if ( V_20 )
goto V_362;
}
V_8 -> V_198 = 1 ;
F_281 ( V_14 ) ;
F_265 ( V_14 ) ;
return 0 ;
V_362:
F_282 ( & V_8 -> V_180 [ V_363 ] ) ;
V_361:
F_282 ( & V_8 -> V_180 [ V_364 ] ) ;
return V_20 ;
}
static bool
F_283 ( struct V_13 * V_14 )
{
if ( V_365 >= 0 )
return V_365 ;
#ifdef F_284
if ( F_18 ( V_14 ) -> V_39 == 6 && V_366 )
return false ;
#endif
return true ;
}
int F_285 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
unsigned long V_165 , V_367 ;
int V_20 ;
V_165 = V_8 -> V_10 . V_339 -> V_368 << V_100 ;
V_367 = V_8 -> V_10 . V_339 -> V_369 << V_100 ;
F_19 ( & V_14 -> V_27 ) ;
if ( F_283 ( V_14 ) && F_286 ( V_14 ) ) {
V_165 -= V_370 * V_37 ;
F_20 ( V_14 , 0 , V_367 , V_165 ) ;
V_20 = F_287 ( V_14 ) ;
if ( V_20 ) {
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
} else {
F_20 ( V_14 , 0 , V_367 ,
V_165 ) ;
}
V_20 = F_275 ( V_14 ) ;
F_21 ( & V_14 -> V_27 ) ;
if ( V_20 ) {
F_288 ( V_14 ) ;
return V_20 ;
}
if ( ! F_17 ( V_14 , V_33 ) )
V_8 -> V_371 . V_372 = 1 ;
return 0 ;
}
void
F_255 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_179 * V_180 ;
int V_174 ;
F_156 (ring, dev_priv, i)
F_282 ( V_180 ) ;
}
int
F_289 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_212 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
if ( F_17 ( V_14 , V_33 ) )
return 0 ;
if ( F_6 ( & V_8 -> V_10 . V_21 ) ) {
F_8 ( L_19 ) ;
F_290 ( & V_8 -> V_10 . V_21 , 0 ) ;
}
F_19 ( & V_14 -> V_27 ) ;
V_8 -> V_10 . V_215 = 0 ;
V_20 = F_275 ( V_14 ) ;
if ( V_20 != 0 ) {
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
F_115 ( ! F_129 ( & V_8 -> V_10 . V_182 ) ) ;
F_115 ( ! F_129 ( & V_8 -> V_10 . V_192 ) ) ;
F_115 ( ! F_129 ( & V_8 -> V_10 . V_152 ) ) ;
F_21 ( & V_14 -> V_27 ) ;
V_20 = F_291 ( V_14 ) ;
if ( V_20 )
goto V_373;
return 0 ;
V_373:
F_19 ( & V_14 -> V_27 ) ;
F_255 ( V_14 ) ;
V_8 -> V_10 . V_215 = 1 ;
F_21 ( & V_14 -> V_27 ) ;
return V_20 ;
}
int
F_292 ( struct V_13 * V_14 , void * V_29 ,
struct V_30 * V_212 )
{
if ( F_17 ( V_14 , V_33 ) )
return 0 ;
F_293 ( V_14 ) ;
return F_252 ( V_14 ) ;
}
void
F_294 ( struct V_13 * V_14 )
{
int V_20 ;
if ( F_17 ( V_14 , V_33 ) )
return;
V_20 = F_252 ( V_14 ) ;
if ( V_20 )
F_8 ( L_20 , V_20 ) ;
}
static void
F_295 ( struct V_179 * V_180 )
{
F_154 ( & V_180 -> V_182 ) ;
F_154 ( & V_180 -> V_209 ) ;
F_154 ( & V_180 -> V_193 ) ;
}
void
F_296 ( struct V_13 * V_14 )
{
int V_174 ;
T_5 * V_8 = V_14 -> V_15 ;
F_154 ( & V_8 -> V_10 . V_182 ) ;
F_154 ( & V_8 -> V_10 . V_192 ) ;
F_154 ( & V_8 -> V_10 . V_152 ) ;
F_154 ( & V_8 -> V_10 . V_191 ) ;
F_154 ( & V_8 -> V_10 . V_256 ) ;
for ( V_174 = 0 ; V_174 < V_374 ; V_174 ++ )
F_295 ( & V_8 -> V_180 [ V_174 ] ) ;
for ( V_174 = 0 ; V_174 < V_375 ; V_174 ++ )
F_154 ( & V_8 -> V_189 [ V_174 ] . V_190 ) ;
F_297 ( & V_8 -> V_10 . V_220 ,
F_162 ) ;
F_298 ( & V_8 -> V_18 ) ;
if ( F_299 ( V_14 ) ) {
F_211 ( V_376 ,
F_264 ( V_377 ) ) ;
}
V_8 -> V_378 = V_379 ;
if ( ! F_17 ( V_14 , V_33 ) )
V_8 -> V_281 = 3 ;
if ( F_18 ( V_14 ) -> V_39 >= 4 || F_300 ( V_14 ) || F_301 ( V_14 ) || F_110 ( V_14 ) )
V_8 -> V_221 = 16 ;
else
V_8 -> V_221 = 8 ;
F_152 ( V_14 ) ;
F_302 ( V_14 ) ;
F_303 ( & V_8 -> V_380 ) ;
V_8 -> V_10 . V_231 = true ;
V_8 -> V_10 . V_381 . V_382 = V_383 ;
V_8 -> V_10 . V_381 . V_384 = V_385 ;
F_304 ( & V_8 -> V_10 . V_381 ) ;
}
static int F_305 ( struct V_13 * V_14 ,
int V_386 , int V_9 , int V_387 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_388 * V_128 ;
int V_20 ;
if ( V_8 -> V_10 . V_389 [ V_386 - 1 ] || ! V_9 )
return 0 ;
V_128 = F_165 ( sizeof( struct V_388 ) , V_230 ) ;
if ( ! V_128 )
return - V_49 ;
V_128 -> V_386 = V_386 ;
V_128 -> V_48 = F_306 ( V_14 , V_9 , V_387 ) ;
if ( ! V_128 -> V_48 ) {
V_20 = - V_49 ;
goto V_390;
}
#ifdef F_307
F_308 ( ( unsigned long ) V_128 -> V_48 -> V_74 , V_128 -> V_48 -> V_9 / V_37 ) ;
#endif
V_8 -> V_10 . V_389 [ V_386 - 1 ] = V_128 ;
return 0 ;
V_390:
F_29 ( V_128 ) ;
return V_20 ;
}
static void F_309 ( struct V_13 * V_14 , int V_386 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_388 * V_128 ;
if ( ! V_8 -> V_10 . V_389 [ V_386 - 1 ] )
return;
V_128 = V_8 -> V_10 . V_389 [ V_386 - 1 ] ;
if ( V_128 -> V_391 ) {
F_251 ( V_14 , V_128 -> V_391 ) ;
}
#ifdef F_307
F_310 ( ( unsigned long ) V_128 -> V_48 -> V_74 , V_128 -> V_48 -> V_9 / V_37 ) ;
#endif
F_311 ( V_14 , V_128 -> V_48 ) ;
F_29 ( V_128 ) ;
V_8 -> V_10 . V_389 [ V_386 - 1 ] = NULL ;
}
void F_312 ( struct V_13 * V_14 )
{
int V_174 ;
for ( V_174 = V_392 ; V_174 <= V_393 ; V_174 ++ )
F_309 ( V_14 , V_174 ) ;
}
void F_251 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_80 * V_81 = V_2 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
char * V_74 ;
int V_174 ;
int V_173 ;
if ( ! V_2 -> V_128 )
return;
V_74 = V_2 -> V_128 -> V_48 -> V_74 ;
V_173 = V_2 -> V_50 . V_9 / V_37 ;
for ( V_174 = 0 ; V_174 < V_173 ; V_174 ++ ) {
struct V_68 * V_68 = F_58 ( V_81 , V_174 ) ;
if ( ! F_59 ( V_68 ) ) {
char * V_394 = F_45 ( V_68 ) ;
memcpy ( V_394 , V_74 + V_174 * V_37 , V_37 ) ;
F_48 ( V_394 ) ;
F_227 ( & V_68 , 1 ) ;
F_83 ( V_68 ) ;
F_65 ( V_68 ) ;
F_64 ( V_68 ) ;
}
}
F_85 () ;
V_2 -> V_128 -> V_391 = NULL ;
V_2 -> V_128 = NULL ;
}
int
F_313 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_386 ,
int V_387 )
{
struct V_80 * V_81 = V_2 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
T_5 * V_8 = V_14 -> V_15 ;
int V_20 = 0 ;
int V_173 ;
int V_174 ;
if ( V_386 > V_393 )
return - V_38 ;
if ( V_2 -> V_128 ) {
if ( V_2 -> V_128 -> V_386 == V_386 )
return 0 ;
F_251 ( V_14 , V_2 ) ;
}
if ( ! V_8 -> V_10 . V_389 [ V_386 - 1 ] ) {
V_20 = F_305 ( V_14 , V_386 ,
V_2 -> V_50 . V_9 , V_387 ) ;
if ( V_20 ) {
F_8 ( L_21 ,
V_386 , V_2 -> V_50 . V_9 ) ;
return V_20 ;
}
}
V_2 -> V_128 = V_8 -> V_10 . V_389 [ V_386 - 1 ] ;
V_2 -> V_128 -> V_391 = V_2 ;
V_173 = V_2 -> V_50 . V_9 / V_37 ;
for ( V_174 = 0 ; V_174 < V_173 ; V_174 ++ ) {
struct V_68 * V_68 ;
char * V_394 , * V_395 ;
V_68 = F_58 ( V_81 , V_174 ) ;
if ( F_59 ( V_68 ) )
return F_60 ( V_68 ) ;
V_395 = F_45 ( V_68 ) ;
V_394 = V_2 -> V_128 -> V_48 -> V_74 + ( V_174 * V_37 ) ;
memcpy ( V_394 , V_395 , V_37 ) ;
F_48 ( V_395 ) ;
F_65 ( V_68 ) ;
F_64 ( V_68 ) ;
}
return 0 ;
}
static int
F_89 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_115 * args ,
struct V_30 * V_212 )
{
void * V_74 = V_2 -> V_128 -> V_48 -> V_74 + args -> V_88 ;
char T_6 * V_71 = ( char T_6 * ) ( V_93 ) args -> V_94 ;
if ( F_74 ( V_74 , V_71 , args -> V_9 ) ) {
unsigned long V_113 ;
F_21 ( & V_14 -> V_27 ) ;
V_113 = F_314 ( V_74 , V_71 , args -> V_9 ) ;
F_19 ( & V_14 -> V_27 ) ;
if ( V_113 )
return - V_103 ;
}
F_85 () ;
return 0 ;
}
void F_315 ( struct V_13 * V_14 , struct V_30 * V_31 )
{
struct V_211 * V_212 = V_31 -> V_213 ;
F_143 ( & V_212 -> V_10 . V_25 ) ;
while ( ! F_129 ( & V_212 -> V_10 . V_209 ) ) {
struct V_200 * V_201 ;
V_201 = F_151 ( & V_212 -> V_10 . V_209 ,
struct V_200 ,
V_214 ) ;
F_149 ( & V_201 -> V_214 ) ;
V_201 -> V_212 = NULL ;
}
F_144 ( & V_212 -> V_10 . V_25 ) ;
}
static int
F_316 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_396 ;
V_396 = F_129 ( & V_8 -> V_10 . V_192 ) &&
F_129 ( & V_8 -> V_10 . V_182 ) ;
return ! V_396 ;
}
static int
V_383 ( struct V_397 * V_397 , struct V_398 * V_399 )
{
struct V_7 * V_8 =
F_163 ( V_397 ,
struct V_7 ,
V_10 . V_381 ) ;
struct V_13 * V_14 = V_8 -> V_14 ;
struct V_1 * V_2 , * V_196 ;
int V_400 = V_399 -> V_400 ;
int V_401 ;
if ( ! F_164 ( & V_14 -> V_27 ) )
return 0 ;
if ( V_400 == 0 ) {
V_401 = 0 ;
F_23 (obj,
&dev_priv->mm.inactive_list,
mm_list)
V_401 ++ ;
F_21 ( & V_14 -> V_27 ) ;
return V_401 / 100 * V_402 ;
}
V_403:
F_161 ( V_14 ) ;
F_134 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( F_132 ( V_2 ) ) {
if ( F_99 ( V_2 ) == 0 &&
-- V_400 == 0 )
break;
}
}
V_401 = 0 ;
F_134 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( V_400 &&
F_99 ( V_2 ) == 0 )
V_400 -- ;
else
V_401 ++ ;
}
if ( V_400 && F_316 ( V_14 ) ) {
if ( F_200 ( V_14 ) == 0 )
goto V_403;
}
F_21 ( & V_14 -> V_27 ) ;
return V_401 / 100 * V_402 ;
}
