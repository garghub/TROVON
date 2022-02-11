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
V_20 = F_7 ( V_17 ) ;
if ( V_20 )
return V_20 ;
if ( F_6 ( & V_8 -> V_10 . V_21 ) ) {
F_8 ( & V_17 -> V_22 . V_23 , V_19 ) ;
V_17 -> V_24 ++ ;
F_9 ( & V_17 -> V_22 . V_23 , V_19 ) ;
}
return 0 ;
}
int F_10 ( struct V_13 * V_14 )
{
int V_20 ;
V_20 = F_5 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_11 ( & V_14 -> V_25 ) ;
if ( V_20 )
return V_20 ;
F_12 ( F_13 ( V_14 ) ) ;
return 0 ;
}
static inline bool
F_14 ( struct V_1 * V_2 )
{
return ! V_2 -> V_26 ;
}
int
F_15 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * args = V_27 ;
if ( F_16 ( V_14 , V_31 ) )
return - V_32 ;
if ( args -> V_33 >= args -> V_34 ||
( args -> V_34 | args -> V_33 ) & ( V_35 - 1 ) )
return - V_36 ;
if ( F_17 ( V_14 ) -> V_37 >= 5 )
return - V_32 ;
F_18 ( & V_14 -> V_25 ) ;
F_19 ( V_14 , args -> V_33 ,
args -> V_34 , args -> V_34 ) ;
F_20 ( & V_14 -> V_25 ) ;
return 0 ;
}
int
F_21 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_38 * args = V_27 ;
struct V_1 * V_2 ;
T_1 V_39 ;
V_39 = 0 ;
F_18 ( & V_14 -> V_25 ) ;
F_22 (obj, &dev_priv->mm.gtt_list, gtt_list)
if ( V_2 -> V_40 )
V_39 += V_2 -> V_41 -> V_9 ;
F_20 ( & V_14 -> V_25 ) ;
args -> V_42 = V_8 -> V_10 . V_43 ;
args -> V_44 = args -> V_42 - V_39 ;
return 0 ;
}
static int
F_23 ( struct V_28 * V_29 ,
struct V_13 * V_14 ,
T_2 V_9 ,
T_3 * V_45 )
{
struct V_1 * V_2 ;
int V_20 ;
T_4 V_46 ;
V_9 = F_24 ( V_9 , V_35 ) ;
if ( V_9 == 0 )
return - V_36 ;
V_2 = F_25 ( V_14 , V_9 ) ;
if ( V_2 == NULL )
return - V_47 ;
V_20 = F_26 ( V_29 , & V_2 -> V_48 , & V_46 ) ;
if ( V_20 ) {
F_27 ( & V_2 -> V_48 ) ;
F_4 ( V_14 -> V_15 , V_2 -> V_48 . V_9 ) ;
F_28 ( V_2 ) ;
return V_20 ;
}
F_29 ( & V_2 -> V_48 ) ;
F_30 ( V_2 ) ;
* V_45 = V_46 ;
return 0 ;
}
int
F_31 ( struct V_28 * V_29 ,
struct V_13 * V_14 ,
struct V_49 * args )
{
args -> V_50 = F_32 ( args -> V_51 * ( ( args -> V_52 + 7 ) / 8 ) , 64 ) ;
args -> V_9 = args -> V_50 * args -> V_53 ;
return F_23 ( V_29 , V_14 ,
args -> V_9 , & args -> V_46 ) ;
}
int F_33 ( struct V_28 * V_29 ,
struct V_13 * V_14 ,
T_3 V_46 )
{
return F_34 ( V_29 , V_46 ) ;
}
int
F_35 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_54 * args = V_27 ;
return F_23 ( V_29 , V_14 ,
args -> V_9 , & args -> V_46 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_5 * V_8 = V_2 -> V_48 . V_14 -> V_15 ;
return V_8 -> V_10 . V_55 == V_56 &&
V_2 -> V_3 != V_57 ;
}
static inline int
F_37 ( char T_6 * V_58 ,
const char * V_59 , int V_60 ,
int V_61 )
{
int V_20 , V_62 = 0 ;
while ( V_61 > 0 ) {
int V_63 = F_32 ( V_60 + 1 , 64 ) ;
int V_64 = F_38 ( V_63 - V_60 , V_61 ) ;
int V_65 = V_60 ^ 64 ;
V_20 = F_39 ( V_58 + V_62 ,
V_59 + V_65 ,
V_64 ) ;
if ( V_20 )
return V_20 + V_61 ;
V_62 += V_64 ;
V_60 += V_64 ;
V_61 -= V_64 ;
}
return 0 ;
}
static inline int
F_40 ( char * V_59 , int V_60 ,
const char T_6 * V_58 ,
int V_61 )
{
int V_20 , V_62 = 0 ;
while ( V_61 > 0 ) {
int V_63 = F_32 ( V_60 + 1 , 64 ) ;
int V_64 = F_38 ( V_63 - V_60 , V_61 ) ;
int V_65 = V_60 ^ 64 ;
V_20 = F_41 ( V_59 + V_65 ,
V_58 + V_62 ,
V_64 ) ;
if ( V_20 )
return V_20 + V_61 ;
V_62 += V_64 ;
V_60 += V_64 ;
V_61 -= V_64 ;
}
return 0 ;
}
static int
F_42 ( struct V_66 * V_66 , int V_67 , int V_68 ,
char T_6 * V_69 ,
bool V_70 , bool V_71 )
{
char * V_72 ;
int V_20 ;
if ( F_43 ( V_70 ) )
return - V_36 ;
V_72 = F_44 ( V_66 ) ;
if ( V_71 )
F_45 ( V_72 + V_67 ,
V_68 ) ;
V_20 = F_46 ( V_69 ,
V_72 + V_67 ,
V_68 ) ;
F_47 ( V_72 ) ;
return V_20 ;
}
static void
F_48 ( char * V_73 , unsigned long V_61 ,
bool V_74 )
{
if ( F_43 ( V_74 ) ) {
unsigned long V_75 = ( unsigned long ) V_73 ;
unsigned long V_76 = ( unsigned long ) V_73 + V_61 ;
V_75 = F_49 ( V_75 , 128 ) ;
V_76 = F_50 ( V_76 , 128 ) ;
F_45 ( ( void * ) V_75 , V_76 - V_75 ) ;
} else {
F_45 ( V_73 , V_61 ) ;
}
}
static int
F_51 ( struct V_66 * V_66 , int V_67 , int V_68 ,
char T_6 * V_69 ,
bool V_70 , bool V_71 )
{
char * V_72 ;
int V_20 ;
V_72 = F_52 ( V_66 ) ;
if ( V_71 )
F_48 ( V_72 + V_67 ,
V_68 ,
V_70 ) ;
if ( V_70 )
V_20 = F_37 ( V_69 ,
V_72 , V_67 ,
V_68 ) ;
else
V_20 = F_39 ( V_69 ,
V_72 + V_67 ,
V_68 ) ;
F_53 ( V_66 ) ;
return V_20 ;
}
static int
F_54 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_77 * args ,
struct V_28 * V_29 )
{
struct V_78 * V_79 = V_2 -> V_48 . V_80 -> V_81 . V_82 -> V_83 -> V_84 ;
char T_6 * V_69 ;
T_7 V_85 ;
T_8 V_86 ;
int V_67 , V_68 , V_20 = 0 ;
int V_87 , V_70 ;
int V_88 = 0 ;
int V_89 = 0 ;
int V_71 = 0 ;
int V_90 ;
V_69 = ( char T_6 * ) ( V_91 ) args -> V_92 ;
V_85 = args -> V_9 ;
V_87 = F_36 ( V_2 ) ;
if ( ! ( V_2 -> V_48 . V_93 & V_94 ) ) {
if ( V_2 -> V_95 == V_96 )
V_71 = 1 ;
V_20 = F_55 ( V_2 , false ) ;
if ( V_20 )
return V_20 ;
}
V_86 = args -> V_86 ;
while ( V_85 > 0 ) {
struct V_66 * V_66 ;
V_67 = F_56 ( V_86 ) ;
V_68 = V_85 ;
if ( ( V_67 + V_68 ) > V_35 )
V_68 = V_35 - V_67 ;
if ( V_2 -> V_97 ) {
V_66 = V_2 -> V_97 [ V_86 >> V_98 ] ;
V_90 = 0 ;
} else {
V_66 = F_57 ( V_79 , V_86 >> V_98 ) ;
if ( F_58 ( V_66 ) ) {
V_20 = F_59 ( V_66 ) ;
goto V_99;
}
V_90 = 1 ;
}
V_70 = V_87 &&
( F_60 ( V_66 ) & ( 1 << 17 ) ) != 0 ;
V_20 = F_42 ( V_66 , V_67 , V_68 ,
V_69 , V_70 ,
V_71 ) ;
if ( V_20 == 0 )
goto V_100;
V_88 = 1 ;
F_61 ( V_66 ) ;
F_20 ( & V_14 -> V_25 ) ;
if ( ! V_89 ) {
V_20 = F_62 ( V_69 , V_85 ) ;
( void ) V_20 ;
V_89 = 1 ;
}
V_20 = F_51 ( V_66 , V_67 , V_68 ,
V_69 , V_70 ,
V_71 ) ;
F_18 ( & V_14 -> V_25 ) ;
F_63 ( V_66 ) ;
V_100:
F_64 ( V_66 ) ;
if ( V_90 )
F_63 ( V_66 ) ;
if ( V_20 ) {
V_20 = - V_101 ;
goto V_99;
}
V_85 -= V_68 ;
V_69 += V_68 ;
V_86 += V_68 ;
}
V_99:
if ( V_88 ) {
if ( V_2 -> V_102 == V_103 )
F_65 ( V_2 ) ;
}
return V_20 ;
}
int
F_66 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_77 * args = V_27 ;
struct V_1 * V_2 ;
int V_20 = 0 ;
if ( args -> V_9 == 0 )
return 0 ;
if ( ! F_67 ( V_104 ,
( char T_6 * ) ( V_91 ) args -> V_92 ,
args -> V_9 ) )
return - V_101 ;
V_20 = F_10 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_68 ( F_69 ( V_14 , V_29 , args -> V_46 ) ) ;
if ( & V_2 -> V_48 == NULL ) {
V_20 = - V_105 ;
goto V_106;
}
if ( args -> V_86 > V_2 -> V_48 . V_9 ||
args -> V_9 > V_2 -> V_48 . V_9 - args -> V_86 ) {
V_20 = - V_36 ;
goto V_99;
}
if ( ! V_2 -> V_48 . V_80 ) {
V_20 = - V_36 ;
goto V_99;
}
F_70 ( V_2 , args -> V_86 , args -> V_9 ) ;
V_20 = F_54 ( V_14 , V_2 , args , V_29 ) ;
V_99:
F_29 ( & V_2 -> V_48 ) ;
V_106:
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
static inline int
F_71 ( struct V_107 * V_79 ,
T_8 V_108 , int V_109 ,
char T_6 * V_69 ,
int V_61 )
{
void T_9 * V_110 ;
void * V_72 ;
unsigned long V_111 ;
V_110 = F_72 ( V_79 , V_108 ) ;
V_72 = ( void V_112 * ) V_110 + V_109 ;
V_111 = F_73 ( V_72 ,
V_69 , V_61 ) ;
F_74 ( V_110 ) ;
return V_111 ;
}
static int
F_75 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_113 * args ,
struct V_28 * V_29 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_7 V_85 ;
T_8 V_86 , V_108 ;
char T_6 * V_69 ;
int V_109 , V_68 , V_20 ;
V_20 = F_76 ( V_2 , 0 , true ) ;
if ( V_20 )
goto V_99;
V_20 = F_55 ( V_2 , true ) ;
if ( V_20 )
goto V_114;
V_20 = F_77 ( V_2 ) ;
if ( V_20 )
goto V_114;
V_69 = ( char T_6 * ) ( V_91 ) args -> V_92 ;
V_85 = args -> V_9 ;
V_86 = V_2 -> V_115 + args -> V_86 ;
while ( V_85 > 0 ) {
V_108 = V_86 & V_116 ;
V_109 = F_56 ( V_86 ) ;
V_68 = V_85 ;
if ( ( V_109 + V_85 ) > V_35 )
V_68 = V_35 - V_109 ;
if ( F_71 ( V_8 -> V_10 . V_117 , V_108 ,
V_109 , V_69 , V_68 ) ) {
V_20 = - V_101 ;
goto V_114;
}
V_85 -= V_68 ;
V_69 += V_68 ;
V_86 += V_68 ;
}
V_114:
F_78 ( V_2 ) ;
V_99:
return V_20 ;
}
static int
F_79 ( struct V_66 * V_66 , int V_67 , int V_68 ,
char T_6 * V_69 ,
bool V_70 ,
bool V_118 ,
bool V_119 )
{
char * V_72 ;
int V_20 ;
if ( F_43 ( V_70 ) )
return - V_36 ;
V_72 = F_44 ( V_66 ) ;
if ( V_118 )
F_45 ( V_72 + V_67 ,
V_68 ) ;
V_20 = F_73 ( V_72 + V_67 ,
V_69 ,
V_68 ) ;
if ( V_119 )
F_45 ( V_72 + V_67 ,
V_68 ) ;
F_47 ( V_72 ) ;
return V_20 ;
}
static int
F_80 ( struct V_66 * V_66 , int V_67 , int V_68 ,
char T_6 * V_69 ,
bool V_70 ,
bool V_118 ,
bool V_119 )
{
char * V_72 ;
int V_20 ;
V_72 = F_52 ( V_66 ) ;
if ( F_43 ( V_118 || V_70 ) )
F_48 ( V_72 + V_67 ,
V_68 ,
V_70 ) ;
if ( V_70 )
V_20 = F_40 ( V_72 , V_67 ,
V_69 ,
V_68 ) ;
else
V_20 = F_41 ( V_72 + V_67 ,
V_69 ,
V_68 ) ;
if ( V_119 )
F_48 ( V_72 + V_67 ,
V_68 ,
V_70 ) ;
F_53 ( V_66 ) ;
return V_20 ;
}
static int
F_81 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_113 * args ,
struct V_28 * V_29 )
{
struct V_78 * V_79 = V_2 -> V_48 . V_80 -> V_81 . V_82 -> V_83 -> V_84 ;
T_7 V_85 ;
T_8 V_86 ;
char T_6 * V_69 ;
int V_67 , V_68 , V_20 = 0 ;
int V_87 , V_70 ;
int V_88 = 0 ;
int V_119 = 0 ;
int V_118 = 0 ;
int V_90 ;
V_69 = ( char T_6 * ) ( V_91 ) args -> V_92 ;
V_85 = args -> V_9 ;
V_87 = F_36 ( V_2 ) ;
if ( V_2 -> V_48 . V_120 != V_94 ) {
if ( V_2 -> V_95 == V_96 )
V_119 = 1 ;
V_20 = F_55 ( V_2 , true ) ;
if ( V_20 )
return V_20 ;
}
if ( ! ( V_2 -> V_48 . V_93 & V_94 )
&& V_2 -> V_95 == V_96 )
V_118 = 1 ;
V_86 = args -> V_86 ;
V_2 -> V_121 = 1 ;
while ( V_85 > 0 ) {
struct V_66 * V_66 ;
int V_122 ;
V_67 = F_56 ( V_86 ) ;
V_68 = V_85 ;
if ( ( V_67 + V_68 ) > V_35 )
V_68 = V_35 - V_67 ;
V_122 = V_118 &&
( ( V_67 | V_68 )
& ( V_123 . V_124 - 1 ) ) ;
if ( V_2 -> V_97 ) {
V_66 = V_2 -> V_97 [ V_86 >> V_98 ] ;
V_90 = 0 ;
} else {
V_66 = F_57 ( V_79 , V_86 >> V_98 ) ;
if ( F_58 ( V_66 ) ) {
V_20 = F_59 ( V_66 ) ;
goto V_99;
}
V_90 = 1 ;
}
V_70 = V_87 &&
( F_60 ( V_66 ) & ( 1 << 17 ) ) != 0 ;
V_20 = F_79 ( V_66 , V_67 , V_68 ,
V_69 , V_70 ,
V_122 ,
V_119 ) ;
if ( V_20 == 0 )
goto V_100;
V_88 = 1 ;
F_61 ( V_66 ) ;
F_20 ( & V_14 -> V_25 ) ;
V_20 = F_80 ( V_66 , V_67 , V_68 ,
V_69 , V_70 ,
V_122 ,
V_119 ) ;
F_18 ( & V_14 -> V_25 ) ;
F_63 ( V_66 ) ;
V_100:
F_82 ( V_66 ) ;
F_64 ( V_66 ) ;
if ( V_90 )
F_63 ( V_66 ) ;
if ( V_20 ) {
V_20 = - V_101 ;
goto V_99;
}
V_85 -= V_68 ;
V_69 += V_68 ;
V_86 += V_68 ;
}
V_99:
if ( V_88 ) {
if ( V_2 -> V_102 == V_103 )
F_65 ( V_2 ) ;
if ( V_2 -> V_48 . V_120 != V_94 ) {
F_83 ( V_2 ) ;
F_84 () ;
}
}
if ( V_119 )
F_84 () ;
return V_20 ;
}
int
F_85 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_113 * args = V_27 ;
struct V_1 * V_2 ;
int V_20 ;
if ( args -> V_9 == 0 )
return 0 ;
if ( ! F_67 ( V_125 ,
( char T_6 * ) ( V_91 ) args -> V_92 ,
args -> V_9 ) )
return - V_101 ;
V_20 = F_86 ( ( char T_6 * ) ( V_91 ) args -> V_92 ,
args -> V_9 ) ;
if ( V_20 )
return - V_101 ;
V_20 = F_10 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_68 ( F_69 ( V_14 , V_29 , args -> V_46 ) ) ;
if ( & V_2 -> V_48 == NULL ) {
V_20 = - V_105 ;
goto V_106;
}
if ( args -> V_86 > V_2 -> V_48 . V_9 ||
args -> V_9 > V_2 -> V_48 . V_9 - args -> V_86 ) {
V_20 = - V_36 ;
goto V_99;
}
if ( ! V_2 -> V_48 . V_80 ) {
V_20 = - V_36 ;
goto V_99;
}
F_87 ( V_2 , args -> V_86 , args -> V_9 ) ;
V_20 = - V_101 ;
if ( V_2 -> V_126 ) {
V_20 = F_88 ( V_14 , V_2 , args , V_29 ) ;
goto V_99;
}
if ( V_2 -> V_41 &&
V_2 -> V_95 == V_96 &&
V_2 -> V_3 == V_57 &&
V_2 -> V_127 &&
V_2 -> V_48 . V_120 != V_94 ) {
V_20 = F_75 ( V_14 , V_2 , args , V_29 ) ;
}
if ( V_20 == - V_101 )
V_20 = F_81 ( V_14 , V_2 , args , V_29 ) ;
V_99:
F_29 ( & V_2 -> V_48 ) ;
V_106:
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
int
F_89 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_128 * args = V_27 ;
struct V_1 * V_2 ;
T_3 V_93 = args -> V_93 ;
T_3 V_120 = args -> V_120 ;
int V_20 ;
if ( V_120 & V_129 )
return - V_36 ;
if ( V_93 & V_129 )
return - V_36 ;
if ( V_120 != 0 && V_93 != V_120 )
return - V_36 ;
V_20 = F_10 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_68 ( F_69 ( V_14 , V_29 , args -> V_46 ) ) ;
if ( & V_2 -> V_48 == NULL ) {
V_20 = - V_105 ;
goto V_106;
}
if ( V_93 & V_130 ) {
V_20 = F_55 ( V_2 , V_120 != 0 ) ;
if ( V_20 == - V_36 )
V_20 = 0 ;
} else {
V_20 = F_90 ( V_2 , V_120 != 0 ) ;
}
F_29 ( & V_2 -> V_48 ) ;
V_106:
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
int
F_91 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_131 * args = V_27 ;
struct V_1 * V_2 ;
int V_20 = 0 ;
V_20 = F_10 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_68 ( F_69 ( V_14 , V_29 , args -> V_46 ) ) ;
if ( & V_2 -> V_48 == NULL ) {
V_20 = - V_105 ;
goto V_106;
}
if ( V_2 -> V_40 )
F_92 ( V_2 ) ;
F_29 ( & V_2 -> V_48 ) ;
V_106:
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
int
F_93 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_132 * args = V_27 ;
struct V_133 * V_2 ;
unsigned long V_73 ;
V_2 = F_69 ( V_14 , V_29 , args -> V_46 ) ;
if ( V_2 == NULL )
return - V_105 ;
if ( ! V_2 -> V_80 ) {
F_94 ( V_2 ) ;
return - V_36 ;
}
V_73 = F_95 ( V_2 -> V_80 , 0 , args -> V_9 ,
V_134 | V_135 , V_136 ,
args -> V_86 ) ;
F_94 ( V_2 ) ;
if ( F_58 ( ( void * ) V_73 ) )
return V_73 ;
args -> V_137 = ( T_2 ) V_73 ;
return 0 ;
}
int F_96 ( struct V_138 * V_139 , struct V_140 * V_141 )
{
struct V_1 * V_2 = F_68 ( V_139 -> V_142 ) ;
struct V_13 * V_14 = V_2 -> V_48 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
T_10 V_109 ;
unsigned long V_143 ;
int V_20 = 0 ;
bool V_144 = ! ! ( V_141 -> V_19 & V_145 ) ;
V_109 = ( ( unsigned long ) V_141 -> V_146 - V_139 -> V_147 ) >>
V_98 ;
V_20 = F_10 ( V_14 ) ;
if ( V_20 )
goto V_99;
F_97 ( V_2 , V_109 , true , V_144 ) ;
if ( ! V_2 -> V_127 ) {
V_20 = F_98 ( V_2 ) ;
if ( V_20 )
goto V_106;
}
if ( ! V_2 -> V_41 ) {
V_20 = F_99 ( V_2 , 0 , true ) ;
if ( V_20 )
goto V_106;
V_20 = F_55 ( V_2 , V_144 ) ;
if ( V_20 )
goto V_106;
}
if ( ! V_2 -> V_148 )
F_100 ( V_2 , V_2 -> V_95 ) ;
V_20 = F_101 ( V_2 ) ;
if ( V_20 )
goto V_106;
if ( F_14 ( V_2 ) )
F_102 ( & V_2 -> V_149 , & V_8 -> V_10 . V_150 ) ;
V_2 -> V_151 = true ;
V_143 = ( ( V_14 -> V_152 -> V_48 + V_2 -> V_115 ) >> V_98 ) +
V_109 ;
V_20 = F_103 ( V_139 , ( unsigned long ) V_141 -> V_146 , V_143 ) ;
V_106:
F_20 ( & V_14 -> V_25 ) ;
V_99:
switch ( V_20 ) {
case - V_153 :
case - V_154 :
F_104 () ;
case 0 :
case - V_155 :
case - V_156 :
return V_157 ;
case - V_47 :
return V_158 ;
default:
return V_159 ;
}
}
void
F_2 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_151 )
return;
if ( V_2 -> V_48 . V_14 -> V_160 )
F_105 ( V_2 -> V_48 . V_14 -> V_160 ,
( T_8 ) V_2 -> V_48 . V_161 . V_162 . V_163 << V_98 ,
V_2 -> V_48 . V_9 , 1 ) ;
V_2 -> V_151 = false ;
}
static T_3
F_106 ( struct V_13 * V_14 , T_3 V_9 , int V_3 )
{
T_3 V_164 ;
if ( F_17 ( V_14 ) -> V_37 >= 4 ||
V_3 == V_57 )
return V_9 ;
if ( F_17 ( V_14 ) -> V_37 == 3 )
V_164 = 1024 * 1024 ;
else
V_164 = 512 * 1024 ;
while ( V_164 < V_9 )
V_164 <<= 1 ;
return V_164 ;
}
static T_3
F_107 ( struct V_13 * V_14 ,
T_3 V_9 ,
int V_3 )
{
if ( F_17 ( V_14 ) -> V_37 >= 4 ||
V_3 == V_57 )
return 4096 ;
return F_106 ( V_14 , V_9 , V_3 ) ;
}
T_3
F_108 ( struct V_13 * V_14 ,
T_3 V_9 ,
int V_3 )
{
if ( F_17 ( V_14 ) -> V_37 >= 4 || F_109 ( V_14 ) ||
V_3 == V_57 )
return 4096 ;
return F_106 ( V_14 , V_9 , V_3 ) ;
}
int
F_110 ( struct V_28 * V_29 ,
struct V_13 * V_14 ,
T_3 V_46 ,
T_2 * V_86 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_10 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_68 ( F_69 ( V_14 , V_29 , V_46 ) ) ;
if ( & V_2 -> V_48 == NULL ) {
V_20 = - V_105 ;
goto V_106;
}
if ( V_2 -> V_48 . V_9 > V_8 -> V_10 . V_165 ) {
V_20 = - V_166 ;
goto V_99;
}
if ( V_2 -> V_102 != V_167 ) {
F_111 ( L_1 ) ;
V_20 = - V_36 ;
goto V_99;
}
if ( ! V_2 -> V_48 . V_161 . V_168 ) {
V_20 = F_112 ( & V_2 -> V_48 ) ;
if ( V_20 )
goto V_99;
}
* V_86 = ( V_169 ) V_2 -> V_48 . V_161 . V_162 . V_163 << V_98 ;
V_99:
F_29 ( & V_2 -> V_48 ) ;
V_106:
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
int
F_113 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_170 * args = V_27 ;
return F_110 ( V_29 , V_14 , args -> V_46 , & args -> V_86 ) ;
}
int
F_114 ( struct V_1 * V_2 ,
T_11 V_171 )
{
int V_172 , V_173 ;
struct V_78 * V_79 ;
struct V_174 * V_174 ;
struct V_66 * V_66 ;
if ( V_2 -> V_97 || V_2 -> V_175 )
return 0 ;
V_172 = V_2 -> V_48 . V_9 / V_35 ;
F_115 ( V_2 -> V_97 != NULL ) ;
V_2 -> V_97 = F_116 ( V_172 , sizeof( struct V_66 * ) ) ;
if ( V_2 -> V_97 == NULL )
return - V_47 ;
V_174 = V_2 -> V_48 . V_80 -> V_81 . V_82 -> V_83 ;
V_79 = V_174 -> V_84 ;
V_171 |= F_117 ( V_79 ) ;
for ( V_173 = 0 ; V_173 < V_172 ; V_173 ++ ) {
V_66 = F_118 ( V_79 , V_173 , V_171 ) ;
if ( F_58 ( V_66 ) )
goto V_176;
V_2 -> V_97 [ V_173 ] = V_66 ;
}
if ( F_36 ( V_2 ) )
F_119 ( V_2 ) ;
return 0 ;
V_176:
while ( V_173 -- )
F_63 ( V_2 -> V_97 [ V_173 ] ) ;
F_120 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
return F_59 ( V_66 ) ;
}
static void
F_121 ( struct V_1 * V_2 )
{
int V_172 = V_2 -> V_48 . V_9 / V_35 ;
int V_173 ;
if ( ! V_2 -> V_97 )
return;
F_115 ( V_2 -> V_102 == V_103 ) ;
if ( F_36 ( V_2 ) )
F_122 ( V_2 ) ;
if ( V_2 -> V_102 == V_177 )
V_2 -> V_121 = 0 ;
for ( V_173 = 0 ; V_173 < V_172 ; V_173 ++ ) {
if ( V_2 -> V_121 )
F_82 ( V_2 -> V_97 [ V_173 ] ) ;
if ( V_2 -> V_102 == V_167 )
F_64 ( V_2 -> V_97 [ V_173 ] ) ;
F_63 ( V_2 -> V_97 [ V_173 ] ) ;
}
V_2 -> V_121 = 0 ;
F_120 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
}
void
F_123 ( struct V_1 * V_2 ,
struct V_178 * V_179 ,
T_4 V_180 )
{
struct V_13 * V_14 = V_2 -> V_48 . V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
F_115 ( V_179 == NULL ) ;
V_2 -> V_179 = V_179 ;
if ( ! V_2 -> V_26 ) {
F_124 ( & V_2 -> V_48 ) ;
V_2 -> V_26 = 1 ;
}
F_102 ( & V_2 -> V_149 , & V_8 -> V_10 . V_181 ) ;
F_102 ( & V_2 -> V_182 , & V_179 -> V_181 ) ;
V_2 -> V_183 = V_180 ;
if ( V_2 -> V_184 ) {
V_2 -> V_185 = V_180 ;
if ( V_2 -> V_5 != V_6 ) {
struct V_186 * V_187 ;
V_187 = & V_8 -> V_188 [ V_2 -> V_5 ] ;
F_102 ( & V_187 -> V_189 ,
& V_8 -> V_10 . V_190 ) ;
}
}
}
static void
F_125 ( struct V_1 * V_2 )
{
F_126 ( & V_2 -> V_182 ) ;
V_2 -> V_183 = 0 ;
V_2 -> V_185 = 0 ;
}
static void
F_127 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_48 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
F_115 ( ! V_2 -> V_26 ) ;
F_102 ( & V_2 -> V_149 , & V_8 -> V_10 . V_191 ) ;
F_125 ( V_2 ) ;
}
static void
F_128 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_48 . V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
F_102 ( & V_2 -> V_149 , & V_8 -> V_10 . V_150 ) ;
F_115 ( ! F_129 ( & V_2 -> V_192 ) ) ;
F_115 ( ! V_2 -> V_26 ) ;
V_2 -> V_179 = NULL ;
F_125 ( V_2 ) ;
V_2 -> V_184 = false ;
V_2 -> V_26 = 0 ;
V_2 -> V_193 = false ;
F_29 ( & V_2 -> V_48 ) ;
F_12 ( F_13 ( V_14 ) ) ;
}
static void
F_65 ( struct V_1 * V_2 )
{
struct V_174 * V_174 ;
V_174 = V_2 -> V_48 . V_80 -> V_81 . V_82 -> V_83 ;
F_130 ( V_174 , 0 , ( T_8 ) - 1 ) ;
if ( V_2 -> V_48 . V_161 . V_168 )
F_131 ( & V_2 -> V_48 ) ;
V_2 -> V_102 = V_103 ;
}
static inline int
F_132 ( struct V_1 * V_2 )
{
return V_2 -> V_102 == V_177 ;
}
static void
F_133 ( struct V_178 * V_179 ,
T_3 V_194 )
{
struct V_1 * V_2 , * V_195 ;
F_134 (obj, next,
&ring->gpu_write_list,
gpu_write_list) {
if ( V_2 -> V_48 . V_120 & V_194 ) {
T_3 V_196 = V_2 -> V_48 . V_120 ;
V_2 -> V_48 . V_120 = 0 ;
F_126 ( & V_2 -> V_192 ) ;
F_123 ( V_2 , V_179 ,
F_135 ( V_179 ) ) ;
F_136 ( V_2 ,
V_2 -> V_48 . V_93 ,
V_196 ) ;
}
}
}
static T_4
F_137 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_4 V_180 = V_8 -> V_197 ;
if ( ++ V_8 -> V_197 == 0 )
V_8 -> V_197 = 1 ;
return V_180 ;
}
T_4
F_135 ( struct V_178 * V_179 )
{
if ( V_179 -> V_198 == 0 )
V_179 -> V_198 = F_137 ( V_179 -> V_14 ) ;
return V_179 -> V_198 ;
}
int
F_138 ( struct V_178 * V_179 ,
struct V_28 * V_29 ,
struct V_199 * V_200 )
{
T_5 * V_8 = V_179 -> V_14 -> V_15 ;
T_3 V_180 ;
T_4 V_201 ;
int V_202 ;
int V_20 ;
F_115 ( V_200 == NULL ) ;
V_180 = F_135 ( V_179 ) ;
V_201 = F_139 ( V_179 ) ;
V_20 = V_179 -> V_203 ( V_179 , & V_180 ) ;
if ( V_20 )
return V_20 ;
F_140 ( V_179 , V_180 ) ;
V_200 -> V_180 = V_180 ;
V_200 -> V_179 = V_179 ;
V_200 -> V_204 = V_201 ;
V_200 -> V_205 = V_206 ;
V_202 = F_129 ( & V_179 -> V_207 ) ;
F_141 ( & V_200 -> V_208 , & V_179 -> V_207 ) ;
if ( V_29 ) {
struct V_209 * V_210 = V_29 -> V_211 ;
F_142 ( & V_210 -> V_10 . V_23 ) ;
V_200 -> V_210 = V_210 ;
F_141 ( & V_200 -> V_212 ,
& V_210 -> V_10 . V_207 ) ;
F_143 ( & V_210 -> V_10 . V_23 ) ;
}
V_179 -> V_198 = 0 ;
if ( ! V_8 -> V_10 . V_213 ) {
if ( V_214 ) {
F_144 ( & V_8 -> V_215 ,
V_206 +
F_145 ( V_216 ) ) ;
}
if ( V_202 )
F_146 ( V_8 -> V_217 ,
& V_8 -> V_10 . V_218 , V_219 ) ;
}
return 0 ;
}
static inline void
F_147 ( struct V_199 * V_200 )
{
struct V_209 * V_210 = V_200 -> V_210 ;
if ( ! V_210 )
return;
F_142 ( & V_210 -> V_10 . V_23 ) ;
if ( V_200 -> V_210 ) {
F_148 ( & V_200 -> V_212 ) ;
V_200 -> V_210 = NULL ;
}
F_143 ( & V_210 -> V_10 . V_23 ) ;
}
static void F_149 ( struct V_7 * V_8 ,
struct V_178 * V_179 )
{
while ( ! F_129 ( & V_179 -> V_207 ) ) {
struct V_199 * V_200 ;
V_200 = F_150 ( & V_179 -> V_207 ,
struct V_199 ,
V_208 ) ;
F_148 ( & V_200 -> V_208 ) ;
F_147 ( V_200 ) ;
F_28 ( V_200 ) ;
}
while ( ! F_129 ( & V_179 -> V_181 ) ) {
struct V_1 * V_2 ;
V_2 = F_150 ( & V_179 -> V_181 ,
struct V_1 ,
V_182 ) ;
V_2 -> V_48 . V_120 = 0 ;
F_126 ( & V_2 -> V_192 ) ;
F_128 ( V_2 ) ;
}
}
static void F_151 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
int V_173 ;
for ( V_173 = 0 ; V_173 < V_8 -> V_220 ; V_173 ++ ) {
struct V_186 * V_187 = & V_8 -> V_188 [ V_173 ] ;
F_152 ( V_14 , V_173 , NULL ) ;
if ( V_187 -> V_2 )
F_1 ( V_187 -> V_2 ) ;
V_187 -> V_40 = 0 ;
V_187 -> V_2 = NULL ;
F_153 ( & V_187 -> V_189 ) ;
}
F_153 ( & V_8 -> V_10 . V_190 ) ;
}
void F_154 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_1 * V_2 ;
struct V_178 * V_179 ;
int V_173 ;
F_155 (ring, dev_priv, i)
F_149 ( V_8 , V_179 ) ;
while ( ! F_129 ( & V_8 -> V_10 . V_191 ) ) {
V_2 = F_150 ( & V_8 -> V_10 . V_191 ,
struct V_1 ,
V_149 ) ;
V_2 -> V_48 . V_120 = 0 ;
F_126 ( & V_2 -> V_192 ) ;
F_128 ( V_2 ) ;
}
F_22 (obj,
&dev_priv->mm.inactive_list,
mm_list)
{
V_2 -> V_48 . V_93 &= ~ V_129 ;
}
F_151 ( V_14 ) ;
}
void
F_156 ( struct V_178 * V_179 )
{
T_3 V_180 ;
int V_173 ;
if ( F_129 ( & V_179 -> V_207 ) )
return;
F_12 ( F_13 ( V_179 -> V_14 ) ) ;
V_180 = V_179 -> V_221 ( V_179 ) ;
for ( V_173 = 0 ; V_173 < F_157 ( V_179 -> V_222 ) ; V_173 ++ )
if ( V_180 >= V_179 -> V_222 [ V_173 ] )
V_179 -> V_222 [ V_173 ] = 0 ;
while ( ! F_129 ( & V_179 -> V_207 ) ) {
struct V_199 * V_200 ;
V_200 = F_150 ( & V_179 -> V_207 ,
struct V_199 ,
V_208 ) ;
if ( ! F_158 ( V_180 , V_200 -> V_180 ) )
break;
F_159 ( V_179 , V_200 -> V_180 ) ;
V_179 -> V_223 = V_200 -> V_204 ;
F_148 ( & V_200 -> V_208 ) ;
F_147 ( V_200 ) ;
F_28 ( V_200 ) ;
}
while ( ! F_129 ( & V_179 -> V_181 ) ) {
struct V_1 * V_2 ;
V_2 = F_150 ( & V_179 -> V_181 ,
struct V_1 ,
V_182 ) ;
if ( ! F_158 ( V_180 , V_2 -> V_183 ) )
break;
if ( V_2 -> V_48 . V_120 != 0 )
F_127 ( V_2 ) ;
else
F_128 ( V_2 ) ;
}
if ( F_43 ( V_179 -> V_224 &&
F_158 ( V_180 , V_179 -> V_224 ) ) ) {
V_179 -> V_225 ( V_179 ) ;
V_179 -> V_224 = 0 ;
}
F_12 ( F_13 ( V_179 -> V_14 ) ) ;
}
void
F_160 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_178 * V_179 ;
int V_173 ;
F_155 (ring, dev_priv, i)
F_156 ( V_179 ) ;
}
static void
F_161 ( struct V_226 * V_227 )
{
T_5 * V_8 ;
struct V_13 * V_14 ;
struct V_178 * V_179 ;
bool V_228 ;
int V_173 ;
V_8 = F_162 ( V_227 , T_5 ,
V_10 . V_218 . V_227 ) ;
V_14 = V_8 -> V_14 ;
if ( ! F_163 ( & V_14 -> V_25 ) ) {
F_146 ( V_8 -> V_217 , & V_8 -> V_10 . V_218 , V_219 ) ;
return;
}
F_160 ( V_14 ) ;
V_228 = true ;
F_155 (ring, dev_priv, i) {
if ( ! F_129 ( & V_179 -> V_192 ) ) {
struct V_199 * V_200 ;
int V_20 ;
V_20 = F_164 ( V_179 ,
0 , V_129 ) ;
V_200 = F_165 ( sizeof( * V_200 ) , V_229 ) ;
if ( V_20 || V_200 == NULL ||
F_138 ( V_179 , NULL , V_200 ) )
F_28 ( V_200 ) ;
}
V_228 &= F_129 ( & V_179 -> V_207 ) ;
}
if ( ! V_8 -> V_10 . V_213 && ! V_228 )
F_146 ( V_8 -> V_217 , & V_8 -> V_10 . V_218 , V_219 ) ;
F_20 ( & V_14 -> V_25 ) ;
}
static int
F_166 ( struct V_7 * V_8 )
{
F_115 ( ! F_167 ( & V_8 -> V_14 -> V_25 ) ) ;
if ( F_6 ( & V_8 -> V_10 . V_21 ) ) {
struct V_16 * V_17 = & V_8 -> V_18 ;
bool V_230 ;
unsigned long V_19 ;
F_8 ( & V_17 -> V_22 . V_23 , V_19 ) ;
V_230 = V_17 -> V_24 > 0 ;
F_9 ( & V_17 -> V_22 . V_23 , V_19 ) ;
return V_230 ? - V_153 : - V_154 ;
}
return 0 ;
}
static int
F_168 ( struct V_178 * V_179 , T_4 V_180 )
{
int V_20 = 0 ;
F_115 ( ! F_167 ( & V_179 -> V_14 -> V_25 ) ) ;
if ( V_180 == V_179 -> V_198 ) {
struct V_199 * V_200 ;
V_200 = F_165 ( sizeof( * V_200 ) , V_229 ) ;
if ( V_200 == NULL )
return - V_47 ;
V_20 = F_138 ( V_179 , NULL , V_200 ) ;
if ( V_20 ) {
F_28 ( V_200 ) ;
return V_20 ;
}
F_115 ( V_180 != V_200 -> V_180 ) ;
}
return V_20 ;
}
static int F_169 ( struct V_178 * V_179 , T_4 V_180 ,
bool V_231 )
{
T_5 * V_8 = V_179 -> V_14 -> V_15 ;
int V_20 = 0 ;
if ( F_158 ( V_179 -> V_221 ( V_179 ) , V_180 ) )
return 0 ;
F_170 ( V_179 , V_180 ) ;
if ( F_12 ( ! V_179 -> V_232 ( V_179 ) ) )
return - V_32 ;
#define F_171 \
(i915_seqno_passed(ring->get_seqno(ring), seqno) || \
atomic_read(&dev_priv->mm.wedged))
if ( V_231 )
V_20 = F_172 ( V_179 -> V_233 ,
F_171 ) ;
else
F_173 ( V_179 -> V_233 , F_171 ) ;
V_179 -> V_225 ( V_179 ) ;
F_174 ( V_179 , V_180 ) ;
#undef F_171
return V_20 ;
}
int
F_175 ( struct V_178 * V_179 ,
T_3 V_180 )
{
T_5 * V_8 = V_179 -> V_14 -> V_15 ;
int V_20 = 0 ;
F_115 ( V_180 == 0 ) ;
V_20 = F_166 ( V_8 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_168 ( V_179 , V_180 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_169 ( V_179 , V_180 , V_8 -> V_10 . V_231 ) ;
if ( F_6 ( & V_8 -> V_10 . V_21 ) )
V_20 = - V_154 ;
return V_20 ;
}
int
F_176 ( struct V_1 * V_2 )
{
int V_20 ;
F_115 ( ( V_2 -> V_48 . V_120 & V_129 ) != 0 ) ;
if ( V_2 -> V_26 ) {
V_20 = F_175 ( V_2 -> V_179 , V_2 -> V_183 ) ;
if ( V_20 )
return V_20 ;
F_156 ( V_2 -> V_179 ) ;
}
return 0 ;
}
int
F_177 ( struct V_1 * V_2 ,
struct V_178 * V_234 )
{
struct V_178 * V_235 = V_2 -> V_179 ;
T_4 V_180 ;
int V_20 , V_236 ;
if ( V_235 == NULL || V_234 == V_235 )
return 0 ;
if ( V_234 == NULL || ! F_178 ( V_2 -> V_48 . V_14 ) )
return F_176 ( V_2 ) ;
V_236 = F_179 ( V_235 , V_234 ) ;
V_180 = V_2 -> V_183 ;
if ( V_180 <= V_235 -> V_222 [ V_236 ] )
return 0 ;
V_20 = F_168 ( V_2 -> V_179 , V_180 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_234 -> V_237 ( V_234 , V_235 , V_180 ) ;
if ( ! V_20 )
V_235 -> V_222 [ V_236 ] = V_180 ;
return V_20 ;
}
static void F_180 ( struct V_1 * V_2 )
{
T_4 V_196 , V_238 ;
F_181 () ;
F_2 ( V_2 ) ;
if ( ( V_2 -> V_48 . V_93 & V_130 ) == 0 )
return;
V_238 = V_2 -> V_48 . V_93 ;
V_196 = V_2 -> V_48 . V_120 ;
V_2 -> V_48 . V_93 &= ~ V_130 ;
V_2 -> V_48 . V_120 &= ~ V_130 ;
F_136 ( V_2 ,
V_238 ,
V_196 ) ;
}
int
F_98 ( struct V_1 * V_2 )
{
T_5 * V_8 = V_2 -> V_48 . V_14 -> V_15 ;
int V_20 = 0 ;
if ( V_2 -> V_41 == NULL )
return 0 ;
if ( V_2 -> V_40 )
return - V_239 ;
V_20 = F_182 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_180 ( V_2 ) ;
if ( V_20 == 0 )
V_20 = F_90 ( V_2 , 1 ) ;
if ( V_20 == - V_155 )
return V_20 ;
if ( V_20 ) {
F_83 ( V_2 ) ;
V_2 -> V_48 . V_93 = V_2 -> V_48 . V_120 = V_94 ;
}
V_20 = F_77 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_183 ( V_2 ) ;
if ( V_2 -> V_148 )
F_184 ( V_2 ) ;
if ( V_2 -> V_240 ) {
F_185 ( V_8 -> V_10 . V_241 , V_2 ) ;
V_2 -> V_240 = 0 ;
}
F_186 ( V_2 ) ;
F_121 ( V_2 ) ;
F_126 ( & V_2 -> V_242 ) ;
F_126 ( & V_2 -> V_149 ) ;
V_2 -> V_127 = true ;
F_187 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
V_2 -> V_115 = 0 ;
if ( F_132 ( V_2 ) )
F_65 ( V_2 ) ;
return V_20 ;
}
int
F_164 ( struct V_178 * V_179 ,
T_3 V_243 ,
T_3 V_194 )
{
int V_20 ;
if ( ( ( V_243 | V_194 ) & V_129 ) == 0 )
return 0 ;
F_188 ( V_179 , V_243 , V_194 ) ;
V_20 = V_179 -> V_244 ( V_179 , V_243 , V_194 ) ;
if ( V_20 )
return V_20 ;
if ( V_194 & V_129 )
F_133 ( V_179 , V_194 ) ;
return 0 ;
}
static int F_189 ( struct V_178 * V_179 )
{
int V_20 ;
if ( F_129 ( & V_179 -> V_192 ) && F_129 ( & V_179 -> V_181 ) )
return 0 ;
if ( ! F_129 ( & V_179 -> V_192 ) ) {
V_20 = F_164 ( V_179 ,
V_129 , V_129 ) ;
if ( V_20 )
return V_20 ;
}
return F_175 ( V_179 , F_135 ( V_179 ) ) ;
}
int F_190 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_178 * V_179 ;
int V_20 , V_173 ;
F_155 (ring, dev_priv, i) {
V_20 = F_189 ( V_179 ) ;
if ( V_20 )
return V_20 ;
if ( F_12 ( ! F_129 ( & V_179 -> V_192 ) ) )
return - V_239 ;
}
return 0 ;
}
static void F_191 ( struct V_13 * V_14 , int V_187 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_2 V_245 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_41 -> V_9 ;
V_245 = ( T_2 ) ( ( V_2 -> V_115 + V_9 - 4096 ) &
0xfffff000 ) << 32 ;
V_245 |= V_2 -> V_115 & 0xfffff000 ;
V_245 |= ( T_2 ) ( ( V_2 -> V_246 / 128 ) - 1 ) <<
V_247 ;
if ( V_2 -> V_3 == V_248 )
V_245 |= 1 << V_249 ;
V_245 |= V_250 ;
} else
V_245 = 0 ;
F_192 ( V_251 + V_187 * 8 , V_245 ) ;
F_193 ( V_251 + V_187 * 8 ) ;
}
static void F_194 ( struct V_13 * V_14 , int V_187 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_2 V_245 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_41 -> V_9 ;
V_245 = ( T_2 ) ( ( V_2 -> V_115 + V_9 - 4096 ) &
0xfffff000 ) << 32 ;
V_245 |= V_2 -> V_115 & 0xfffff000 ;
V_245 |= ( ( V_2 -> V_246 / 128 ) - 1 ) << V_252 ;
if ( V_2 -> V_3 == V_248 )
V_245 |= 1 << V_249 ;
V_245 |= V_250 ;
} else
V_245 = 0 ;
F_192 ( V_253 + V_187 * 8 , V_245 ) ;
F_193 ( V_253 + V_187 * 8 ) ;
}
static void F_195 ( struct V_13 * V_14 , int V_187 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_4 V_245 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_41 -> V_9 ;
int V_254 ;
int V_255 ;
F_196 ( ( V_2 -> V_115 & ~ V_256 ) ||
( V_9 & - V_9 ) != V_9 ||
( V_2 -> V_115 & ( V_9 - 1 ) ) ,
L_2 ,
V_2 -> V_115 , V_2 -> V_127 , V_9 ) ;
if ( V_2 -> V_3 == V_248 && F_197 ( V_14 ) )
V_255 = 128 ;
else
V_255 = 512 ;
V_254 = V_2 -> V_246 / V_255 ;
V_254 = F_198 ( V_254 ) - 1 ;
V_245 = V_2 -> V_115 ;
if ( V_2 -> V_3 == V_248 )
V_245 |= 1 << V_257 ;
V_245 |= F_199 ( V_9 ) ;
V_245 |= V_254 << V_258 ;
V_245 |= V_259 ;
} else
V_245 = 0 ;
if ( V_187 < 8 )
V_187 = V_260 + V_187 * 4 ;
else
V_187 = V_261 + ( V_187 - 8 ) * 4 ;
F_200 ( V_187 , V_245 ) ;
F_193 ( V_187 ) ;
}
static void F_201 ( struct V_13 * V_14 , int V_187 ,
struct V_1 * V_2 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_3 V_245 ;
if ( V_2 ) {
T_4 V_9 = V_2 -> V_41 -> V_9 ;
T_3 V_254 ;
F_196 ( ( V_2 -> V_115 & ~ V_262 ) ||
( V_9 & - V_9 ) != V_9 ||
( V_2 -> V_115 & ( V_9 - 1 ) ) ,
L_3 ,
V_2 -> V_115 , V_9 ) ;
V_254 = V_2 -> V_246 / 128 ;
V_254 = F_198 ( V_254 ) - 1 ;
V_245 = V_2 -> V_115 ;
if ( V_2 -> V_3 == V_248 )
V_245 |= 1 << V_257 ;
V_245 |= F_202 ( V_9 ) ;
V_245 |= V_254 << V_258 ;
V_245 |= V_259 ;
} else
V_245 = 0 ;
F_200 ( V_260 + V_187 * 4 , V_245 ) ;
F_193 ( V_260 + V_187 * 4 ) ;
}
static void F_152 ( struct V_13 * V_14 , int V_187 ,
struct V_1 * V_2 )
{
switch ( F_17 ( V_14 ) -> V_37 ) {
case 7 :
case 6 : F_191 ( V_14 , V_187 , V_2 ) ; break;
case 5 :
case 4 : F_194 ( V_14 , V_187 , V_2 ) ; break;
case 3 : F_195 ( V_14 , V_187 , V_2 ) ; break;
case 2 : F_201 ( V_14 , V_187 , V_2 ) ; break;
default: break;
}
}
static inline int F_203 ( struct V_7 * V_8 ,
struct V_186 * V_263 )
{
return V_263 - V_8 -> V_188 ;
}
static void F_204 ( struct V_1 * V_2 ,
struct V_186 * V_263 ,
bool V_264 )
{
struct V_7 * V_8 = V_2 -> V_48 . V_14 -> V_15 ;
int V_187 = F_203 ( V_8 , V_263 ) ;
F_152 ( V_2 -> V_48 . V_14 , V_187 , V_264 ? V_2 : NULL ) ;
if ( V_264 ) {
V_2 -> V_5 = V_187 ;
V_263 -> V_2 = V_2 ;
F_102 ( & V_263 -> V_189 , & V_8 -> V_10 . V_190 ) ;
} else {
V_2 -> V_5 = V_6 ;
V_263 -> V_2 = NULL ;
F_126 ( & V_263 -> V_189 ) ;
}
}
static int
F_205 ( struct V_1 * V_2 )
{
int V_20 ;
if ( V_2 -> V_184 ) {
if ( V_2 -> V_48 . V_120 & V_129 ) {
V_20 = F_164 ( V_2 -> V_179 ,
0 , V_2 -> V_48 . V_120 ) ;
if ( V_20 )
return V_20 ;
}
V_2 -> V_184 = false ;
}
if ( V_2 -> V_185 ) {
V_20 = F_175 ( V_2 -> V_179 , V_2 -> V_185 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_185 = 0 ;
}
if ( V_2 -> V_48 . V_93 & V_130 )
F_181 () ;
return 0 ;
}
int
F_77 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_48 . V_14 -> V_15 ;
int V_20 ;
V_20 = F_205 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( V_2 -> V_5 == V_6 )
return 0 ;
F_204 ( V_2 ,
& V_8 -> V_188 [ V_2 -> V_5 ] ,
false ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static struct V_186 *
F_206 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_186 * V_187 , * V_265 ;
int V_173 ;
V_265 = NULL ;
for ( V_173 = V_8 -> V_266 ; V_173 < V_8 -> V_220 ; V_173 ++ ) {
V_187 = & V_8 -> V_188 [ V_173 ] ;
if ( ! V_187 -> V_2 )
return V_187 ;
if ( ! V_187 -> V_40 )
V_265 = V_187 ;
}
if ( V_265 == NULL )
return NULL ;
F_22 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_187 -> V_40 )
continue;
return V_187 ;
}
return NULL ;
}
int
F_101 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_48 . V_14 ;
struct V_7 * V_8 = V_14 -> V_15 ;
bool V_264 = V_2 -> V_3 != V_57 ;
struct V_186 * V_187 ;
int V_20 ;
if ( V_2 -> V_4 ) {
V_20 = F_205 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_2 -> V_5 != V_6 ) {
V_187 = & V_8 -> V_188 [ V_2 -> V_5 ] ;
if ( ! V_2 -> V_4 ) {
F_102 ( & V_187 -> V_189 ,
& V_8 -> V_10 . V_190 ) ;
return 0 ;
}
} else if ( V_264 ) {
V_187 = F_206 ( V_14 ) ;
if ( V_187 == NULL )
return - V_267 ;
if ( V_187 -> V_2 ) {
struct V_1 * V_268 = V_187 -> V_2 ;
V_20 = F_205 ( V_268 ) ;
if ( V_20 )
return V_20 ;
F_1 ( V_268 ) ;
}
} else
return 0 ;
F_204 ( V_2 , V_187 , V_264 ) ;
V_2 -> V_4 = false ;
return 0 ;
}
static int
F_99 ( struct V_1 * V_2 ,
unsigned V_269 ,
bool V_127 )
{
struct V_13 * V_14 = V_2 -> V_48 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
struct V_270 * V_271 ;
T_11 V_171 = V_272 | V_273 ;
T_4 V_9 , V_274 , V_275 , V_276 ;
bool V_277 , V_278 ;
int V_20 ;
if ( V_2 -> V_102 != V_167 ) {
F_111 ( L_4 ) ;
return - V_36 ;
}
V_274 = F_106 ( V_14 ,
V_2 -> V_48 . V_9 ,
V_2 -> V_3 ) ;
V_275 = F_107 ( V_14 ,
V_2 -> V_48 . V_9 ,
V_2 -> V_3 ) ;
V_276 =
F_108 ( V_14 ,
V_2 -> V_48 . V_9 ,
V_2 -> V_3 ) ;
if ( V_269 == 0 )
V_269 = V_127 ? V_275 :
V_276 ;
if ( V_127 && V_269 & ( V_275 - 1 ) ) {
F_111 ( L_5 , V_269 ) ;
return - V_36 ;
}
V_9 = V_127 ? V_274 : V_2 -> V_48 . V_9 ;
if ( V_2 -> V_48 . V_9 >
( V_127 ? V_8 -> V_10 . V_165 : V_8 -> V_10 . V_43 ) ) {
F_111 ( L_6 ) ;
return - V_166 ;
}
V_279:
if ( V_127 )
V_271 =
F_207 ( & V_8 -> V_10 . V_41 ,
V_9 , V_269 , 0 ,
V_8 -> V_10 . V_165 ,
0 ) ;
else
V_271 = F_208 ( & V_8 -> V_10 . V_41 ,
V_9 , V_269 , 0 ) ;
if ( V_271 != NULL ) {
if ( V_127 )
V_2 -> V_41 =
F_209 ( V_271 ,
V_9 , V_269 , 0 ,
V_8 -> V_10 . V_165 ,
0 ) ;
else
V_2 -> V_41 =
F_210 ( V_271 , V_9 , V_269 ) ;
}
if ( V_2 -> V_41 == NULL ) {
V_20 = F_211 ( V_14 , V_9 , V_269 ,
V_127 ) ;
if ( V_20 )
return V_20 ;
goto V_279;
}
V_20 = F_114 ( V_2 , V_171 ) ;
if ( V_20 ) {
F_187 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
if ( V_20 == - V_47 ) {
V_20 = F_212 ( V_14 , false ) ;
if ( V_20 ) {
if ( V_171 ) {
V_171 = 0 ;
goto V_279;
}
return - V_47 ;
}
goto V_279;
}
return V_20 ;
}
V_20 = F_213 ( V_2 ) ;
if ( V_20 ) {
F_121 ( V_2 ) ;
F_187 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
if ( F_212 ( V_14 , false ) )
return V_20 ;
goto V_279;
}
if ( ! V_8 -> V_10 . V_241 )
F_100 ( V_2 , V_2 -> V_95 ) ;
F_141 ( & V_2 -> V_242 , & V_8 -> V_10 . V_242 ) ;
F_141 ( & V_2 -> V_149 , & V_8 -> V_10 . V_150 ) ;
F_115 ( V_2 -> V_48 . V_93 & V_129 ) ;
F_115 ( V_2 -> V_48 . V_120 & V_129 ) ;
V_2 -> V_115 = V_2 -> V_41 -> V_75 ;
V_278 =
V_2 -> V_41 -> V_9 == V_274 &&
( V_2 -> V_41 -> V_75 & ( V_275 - 1 ) ) == 0 ;
V_277 =
V_2 -> V_115 + V_2 -> V_48 . V_9 <= V_8 -> V_10 . V_165 ;
V_2 -> V_127 = V_277 && V_278 ;
F_214 ( V_2 , V_127 ) ;
return 0 ;
}
void
F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_97 == NULL )
return;
if ( V_2 -> V_95 != V_96 )
return;
F_215 ( V_2 ) ;
F_216 ( V_2 -> V_97 , V_2 -> V_48 . V_9 / V_35 ) ;
}
static int
F_217 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_48 . V_120 & V_129 ) == 0 )
return 0 ;
return F_164 ( V_2 -> V_179 , 0 , V_2 -> V_48 . V_120 ) ;
}
static void
F_218 ( struct V_1 * V_2 )
{
T_3 V_196 ;
if ( V_2 -> V_48 . V_120 != V_130 )
return;
F_219 () ;
V_196 = V_2 -> V_48 . V_120 ;
V_2 -> V_48 . V_120 = 0 ;
F_136 ( V_2 ,
V_2 -> V_48 . V_93 ,
V_196 ) ;
}
static void
F_92 ( struct V_1 * V_2 )
{
T_3 V_196 ;
if ( V_2 -> V_48 . V_120 != V_94 )
return;
F_83 ( V_2 ) ;
F_84 () ;
V_196 = V_2 -> V_48 . V_120 ;
V_2 -> V_48 . V_120 = 0 ;
F_136 ( V_2 ,
V_2 -> V_48 . V_93 ,
V_196 ) ;
}
int
F_55 ( struct V_1 * V_2 , bool V_144 )
{
T_5 * V_8 = V_2 -> V_48 . V_14 -> V_15 ;
T_3 V_196 , V_238 ;
int V_20 ;
if ( V_2 -> V_41 == NULL )
return - V_36 ;
if ( V_2 -> V_48 . V_120 == V_130 )
return 0 ;
V_20 = F_217 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( V_2 -> V_193 || V_144 ) {
V_20 = F_176 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
F_92 ( V_2 ) ;
V_196 = V_2 -> V_48 . V_120 ;
V_238 = V_2 -> V_48 . V_93 ;
F_115 ( ( V_2 -> V_48 . V_120 & ~ V_130 ) != 0 ) ;
V_2 -> V_48 . V_93 |= V_130 ;
if ( V_144 ) {
V_2 -> V_48 . V_93 = V_130 ;
V_2 -> V_48 . V_120 = V_130 ;
V_2 -> V_121 = 1 ;
}
F_136 ( V_2 ,
V_238 ,
V_196 ) ;
if ( F_14 ( V_2 ) )
F_102 ( & V_2 -> V_149 , & V_8 -> V_10 . V_150 ) ;
return 0 ;
}
int F_220 ( struct V_1 * V_2 ,
enum V_280 V_95 )
{
struct V_13 * V_14 = V_2 -> V_48 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
if ( V_2 -> V_95 == V_95 )
return 0 ;
if ( V_2 -> V_40 ) {
F_221 ( L_7 ) ;
return - V_239 ;
}
if ( V_2 -> V_41 ) {
V_20 = F_182 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_180 ( V_2 ) ;
if ( F_17 ( V_2 -> V_48 . V_14 ) -> V_37 < 6 ) {
V_20 = F_77 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_2 -> V_148 )
F_100 ( V_2 , V_95 ) ;
if ( V_2 -> V_240 )
F_222 ( V_8 -> V_10 . V_241 ,
V_2 , V_95 ) ;
}
if ( V_95 == V_96 ) {
T_4 V_238 , V_196 ;
F_12 ( V_2 -> V_48 . V_120 & ~ V_94 ) ;
F_12 ( V_2 -> V_48 . V_93 & ~ V_94 ) ;
V_238 = V_2 -> V_48 . V_93 ;
V_196 = V_2 -> V_48 . V_120 ;
V_2 -> V_48 . V_93 = V_94 ;
V_2 -> V_48 . V_120 = V_94 ;
F_136 ( V_2 ,
V_238 ,
V_196 ) ;
}
V_2 -> V_95 = V_95 ;
return 0 ;
}
int
F_223 ( struct V_1 * V_2 ,
T_4 V_269 ,
struct V_178 * V_281 )
{
T_4 V_238 , V_196 ;
int V_20 ;
V_20 = F_217 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( V_281 != V_2 -> V_179 ) {
V_20 = F_177 ( V_2 , V_281 ) ;
if ( V_20 )
return V_20 ;
}
V_20 = F_220 ( V_2 , V_96 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_76 ( V_2 , V_269 , true ) ;
if ( V_20 )
return V_20 ;
F_92 ( V_2 ) ;
V_196 = V_2 -> V_48 . V_120 ;
V_238 = V_2 -> V_48 . V_93 ;
F_115 ( ( V_2 -> V_48 . V_120 & ~ V_130 ) != 0 ) ;
V_2 -> V_48 . V_93 |= V_130 ;
F_136 ( V_2 ,
V_238 ,
V_196 ) ;
return 0 ;
}
int
F_182 ( struct V_1 * V_2 )
{
int V_20 ;
if ( ( V_2 -> V_48 . V_93 & V_129 ) == 0 )
return 0 ;
if ( V_2 -> V_48 . V_120 & V_129 ) {
V_20 = F_164 ( V_2 -> V_179 , 0 , V_2 -> V_48 . V_120 ) ;
if ( V_20 )
return V_20 ;
}
V_20 = F_176 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_48 . V_93 &= ~ V_129 ;
return 0 ;
}
int
F_90 ( struct V_1 * V_2 , bool V_144 )
{
T_3 V_196 , V_238 ;
int V_20 ;
if ( V_2 -> V_48 . V_120 == V_94 )
return 0 ;
V_20 = F_217 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( V_144 || V_2 -> V_193 ) {
V_20 = F_176 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
F_218 ( V_2 ) ;
V_196 = V_2 -> V_48 . V_120 ;
V_238 = V_2 -> V_48 . V_93 ;
if ( ( V_2 -> V_48 . V_93 & V_94 ) == 0 ) {
F_83 ( V_2 ) ;
V_2 -> V_48 . V_93 |= V_94 ;
}
F_115 ( ( V_2 -> V_48 . V_120 & ~ V_94 ) != 0 ) ;
if ( V_144 ) {
V_2 -> V_48 . V_93 = V_94 ;
V_2 -> V_48 . V_120 = V_94 ;
}
F_136 ( V_2 ,
V_238 ,
V_196 ) ;
return 0 ;
}
static int
F_224 ( struct V_13 * V_14 , struct V_28 * V_29 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_209 * V_210 = V_29 -> V_211 ;
unsigned long V_282 = V_206 - F_145 ( 20 ) ;
struct V_199 * V_200 ;
struct V_178 * V_179 = NULL ;
T_4 V_180 = 0 ;
int V_20 ;
if ( F_6 ( & V_8 -> V_10 . V_21 ) )
return - V_153 ;
F_142 ( & V_210 -> V_10 . V_23 ) ;
F_22 (request, &file_priv->mm.request_list, client_list) {
if ( F_225 ( V_200 -> V_205 , V_282 ) )
break;
V_179 = V_200 -> V_179 ;
V_180 = V_200 -> V_180 ;
}
F_143 ( & V_210 -> V_10 . V_23 ) ;
if ( V_180 == 0 )
return 0 ;
V_20 = F_169 ( V_179 , V_180 , true ) ;
if ( V_20 == 0 )
F_146 ( V_8 -> V_217 , & V_8 -> V_10 . V_218 , 0 ) ;
return V_20 ;
}
int
F_76 ( struct V_1 * V_2 ,
T_3 V_269 ,
bool V_127 )
{
int V_20 ;
F_115 ( V_2 -> V_40 == V_283 ) ;
if ( V_2 -> V_41 != NULL ) {
if ( ( V_269 && V_2 -> V_115 & ( V_269 - 1 ) ) ||
( V_127 && ! V_2 -> V_127 ) ) {
F_196 ( V_2 -> V_40 ,
L_8
L_9
L_10 ,
V_2 -> V_115 , V_269 ,
V_127 ,
V_2 -> V_127 ) ;
V_20 = F_98 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
}
if ( V_2 -> V_41 == NULL ) {
V_20 = F_99 ( V_2 , V_269 ,
V_127 ) ;
if ( V_20 )
return V_20 ;
}
if ( ! V_2 -> V_148 && V_127 )
F_100 ( V_2 , V_2 -> V_95 ) ;
V_2 -> V_40 ++ ;
V_2 -> V_284 |= V_127 ;
return 0 ;
}
void
F_78 ( struct V_1 * V_2 )
{
F_115 ( V_2 -> V_40 == 0 ) ;
F_115 ( V_2 -> V_41 == NULL ) ;
if ( -- V_2 -> V_40 == 0 )
V_2 -> V_284 = false ;
}
int
F_226 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_285 * args = V_27 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_10 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_68 ( F_69 ( V_14 , V_29 , args -> V_46 ) ) ;
if ( & V_2 -> V_48 == NULL ) {
V_20 = - V_105 ;
goto V_106;
}
if ( V_2 -> V_102 != V_167 ) {
F_111 ( L_11 ) ;
V_20 = - V_36 ;
goto V_99;
}
if ( V_2 -> V_286 != NULL && V_2 -> V_286 != V_29 ) {
F_111 ( L_12 ,
args -> V_46 ) ;
V_20 = - V_36 ;
goto V_99;
}
V_2 -> V_287 ++ ;
V_2 -> V_286 = V_29 ;
if ( V_2 -> V_287 == 1 ) {
V_20 = F_76 ( V_2 , args -> V_269 , true ) ;
if ( V_20 )
goto V_99;
}
F_92 ( V_2 ) ;
args -> V_86 = V_2 -> V_115 ;
V_99:
F_29 ( & V_2 -> V_48 ) ;
V_106:
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
int
F_227 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_285 * args = V_27 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_10 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_68 ( F_69 ( V_14 , V_29 , args -> V_46 ) ) ;
if ( & V_2 -> V_48 == NULL ) {
V_20 = - V_105 ;
goto V_106;
}
if ( V_2 -> V_286 != V_29 ) {
F_111 ( L_13 ,
args -> V_46 ) ;
V_20 = - V_36 ;
goto V_99;
}
V_2 -> V_287 -- ;
if ( V_2 -> V_287 == 0 ) {
V_2 -> V_286 = NULL ;
F_78 ( V_2 ) ;
}
V_99:
F_29 ( & V_2 -> V_48 ) ;
V_106:
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
int
F_228 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_288 * args = V_27 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_10 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_68 ( F_69 ( V_14 , V_29 , args -> V_46 ) ) ;
if ( & V_2 -> V_48 == NULL ) {
V_20 = - V_105 ;
goto V_106;
}
args -> V_289 = V_2 -> V_26 ;
if ( args -> V_289 ) {
if ( V_2 -> V_48 . V_120 & V_129 ) {
V_20 = F_164 ( V_2 -> V_179 ,
0 , V_2 -> V_48 . V_120 ) ;
} else {
V_20 = F_168 ( V_2 -> V_179 ,
V_2 -> V_183 ) ;
}
F_156 ( V_2 -> V_179 ) ;
args -> V_289 = V_2 -> V_26 ;
}
F_29 ( & V_2 -> V_48 ) ;
V_106:
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
int
F_229 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_210 )
{
return F_224 ( V_14 , V_210 ) ;
}
int
F_230 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_210 )
{
struct V_290 * args = V_27 ;
struct V_1 * V_2 ;
int V_20 ;
switch ( args -> V_102 ) {
case V_177 :
case V_167 :
break;
default:
return - V_36 ;
}
V_20 = F_10 ( V_14 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_68 ( F_69 ( V_14 , V_210 , args -> V_46 ) ) ;
if ( & V_2 -> V_48 == NULL ) {
V_20 = - V_105 ;
goto V_106;
}
if ( V_2 -> V_40 ) {
V_20 = - V_36 ;
goto V_99;
}
if ( V_2 -> V_102 != V_103 )
V_2 -> V_102 = args -> V_102 ;
if ( F_132 ( V_2 ) &&
V_2 -> V_41 == NULL )
F_65 ( V_2 ) ;
args -> V_291 = V_2 -> V_102 != V_103 ;
V_99:
F_29 ( & V_2 -> V_48 ) ;
V_106:
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
struct V_1 * F_25 ( struct V_13 * V_14 ,
T_1 V_9 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_1 * V_2 ;
struct V_78 * V_79 ;
T_4 V_292 ;
V_2 = F_165 ( sizeof( * V_2 ) , V_229 ) ;
if ( V_2 == NULL )
return NULL ;
if ( F_231 ( V_14 , & V_2 -> V_48 , V_9 ) != 0 ) {
F_28 ( V_2 ) ;
return NULL ;
}
V_292 = V_293 | V_294 ;
if ( F_232 ( V_14 ) || F_233 ( V_14 ) ) {
V_292 &= ~ V_295 ;
V_292 |= V_296 ;
}
V_79 = V_2 -> V_48 . V_80 -> V_81 . V_82 -> V_83 -> V_84 ;
F_234 ( V_79 , V_292 ) ;
F_3 ( V_8 , V_9 ) ;
V_2 -> V_48 . V_120 = V_94 ;
V_2 -> V_48 . V_93 = V_94 ;
if ( F_235 ( V_14 ) ) {
V_2 -> V_95 = V_297 ;
} else
V_2 -> V_95 = V_96 ;
V_2 -> V_48 . V_298 = NULL ;
V_2 -> V_5 = V_6 ;
F_153 ( & V_2 -> V_149 ) ;
F_153 ( & V_2 -> V_242 ) ;
F_153 ( & V_2 -> V_182 ) ;
F_153 ( & V_2 -> V_299 ) ;
F_153 ( & V_2 -> V_192 ) ;
V_2 -> V_102 = V_167 ;
V_2 -> V_127 = true ;
return V_2 ;
}
int F_236 ( struct V_133 * V_2 )
{
F_237 () ;
return 0 ;
}
void F_238 ( struct V_133 * V_300 )
{
struct V_1 * V_2 = F_68 ( V_300 ) ;
struct V_13 * V_14 = V_2 -> V_48 . V_14 ;
T_5 * V_8 = V_14 -> V_15 ;
F_239 ( V_2 ) ;
if ( V_300 -> V_301 )
F_240 ( V_300 , V_2 -> V_175 ) ;
if ( V_2 -> V_126 )
F_241 ( V_14 , V_2 ) ;
V_2 -> V_40 = 0 ;
if ( F_12 ( F_98 ( V_2 ) == - V_155 ) ) {
bool V_302 ;
V_302 = V_8 -> V_10 . V_231 ;
V_8 -> V_10 . V_231 = false ;
F_12 ( F_98 ( V_2 ) ) ;
V_8 -> V_10 . V_231 = V_302 ;
}
if ( V_2 -> V_48 . V_161 . V_168 )
F_131 ( & V_2 -> V_48 ) ;
F_27 ( & V_2 -> V_48 ) ;
F_4 ( V_8 , V_2 -> V_48 . V_9 ) ;
F_28 ( V_2 -> V_303 ) ;
F_28 ( V_2 ) ;
}
int
F_242 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
F_18 ( & V_14 -> V_25 ) ;
if ( V_8 -> V_10 . V_213 ) {
F_20 ( & V_14 -> V_25 ) ;
return 0 ;
}
V_20 = F_190 ( V_14 ) ;
if ( V_20 ) {
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
F_160 ( V_14 ) ;
if ( ! F_16 ( V_14 , V_31 ) )
F_212 ( V_14 , false ) ;
F_151 ( V_14 ) ;
V_8 -> V_10 . V_213 = 1 ;
F_243 ( & V_8 -> V_215 ) ;
F_244 ( V_14 ) ;
F_245 ( V_14 ) ;
F_20 ( & V_14 -> V_25 ) ;
F_246 ( & V_8 -> V_10 . V_218 ) ;
return 0 ;
}
void F_247 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
if ( F_17 ( V_14 ) -> V_37 < 5 ||
V_8 -> V_10 . V_55 == V_304 )
return;
F_200 ( V_305 , F_248 ( V_305 ) |
V_306 ) ;
if ( F_249 ( V_14 ) )
return;
F_200 ( V_307 , F_248 ( V_307 ) | V_308 ) ;
if ( F_250 ( V_14 ) )
F_200 ( V_309 , F_251 ( V_310 ) ) ;
else
F_200 ( V_309 , F_251 ( V_311 ) ) ;
}
void F_252 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
T_3 V_312 ;
struct V_178 * V_179 ;
struct V_313 * V_314 = V_8 -> V_10 . V_241 ;
T_3 T_9 * V_315 ;
T_3 V_316 ;
int V_173 ;
if ( ! V_8 -> V_10 . V_241 )
return;
V_315 = V_8 -> V_10 . V_317 -> V_317 + V_314 -> V_312 / sizeof( T_3 ) ;
for ( V_173 = 0 ; V_173 < V_314 -> V_318 ; V_173 ++ ) {
T_12 V_319 ;
if ( V_8 -> V_10 . V_317 -> V_320 )
V_319 = V_314 -> V_321 [ V_173 ] ;
else
V_319 = F_60 ( V_314 -> V_322 [ V_173 ] ) ;
V_316 = F_253 ( V_319 ) ;
V_316 |= V_323 ;
F_254 ( V_316 , V_315 + V_173 ) ;
}
F_255 ( V_315 ) ;
V_312 = V_314 -> V_312 ;
V_312 /= 64 ;
V_312 <<= 16 ;
if ( F_17 ( V_14 ) -> V_37 == 6 ) {
T_3 V_324 , V_325 , V_326 ;
V_326 = F_248 ( V_327 ) ;
F_200 ( V_327 , V_326 | V_328 ) ;
V_325 = F_248 ( V_329 ) ;
F_200 ( V_329 , V_325 | V_330 ) ;
V_324 = F_248 ( V_331 ) ;
F_200 ( V_331 , V_324 | V_332 |
V_333 ) ;
F_200 ( V_334 , F_251 ( V_335 ) ) ;
} else if ( F_17 ( V_14 ) -> V_37 >= 7 ) {
F_200 ( V_331 , V_333 ) ;
}
F_155 (ring, dev_priv, i) {
if ( F_17 ( V_14 ) -> V_37 >= 7 )
F_200 ( F_256 ( V_179 ) ,
F_251 ( V_335 ) ) ;
F_200 ( F_257 ( V_179 ) , V_336 ) ;
F_200 ( F_258 ( V_179 ) , V_312 ) ;
}
}
int
F_259 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
F_247 ( V_14 ) ;
V_20 = F_260 ( V_14 ) ;
if ( V_20 )
return V_20 ;
if ( F_261 ( V_14 ) ) {
V_20 = F_262 ( V_14 ) ;
if ( V_20 )
goto V_337;
}
if ( F_263 ( V_14 ) ) {
V_20 = F_264 ( V_14 ) ;
if ( V_20 )
goto V_338;
}
V_8 -> V_197 = 1 ;
F_252 ( V_14 ) ;
return 0 ;
V_338:
F_265 ( & V_8 -> V_179 [ V_339 ] ) ;
V_337:
F_265 ( & V_8 -> V_179 [ V_340 ] ) ;
return V_20 ;
}
static bool
F_266 ( struct V_13 * V_14 )
{
if ( V_341 >= 0 )
return V_341 ;
#ifdef F_267
if ( F_17 ( V_14 ) -> V_37 == 6 && V_342 )
return false ;
#endif
return true ;
}
int F_268 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_15 ;
unsigned long V_164 , V_343 ;
int V_20 ;
V_164 = V_8 -> V_10 . V_317 -> V_344 << V_98 ;
V_343 = V_8 -> V_10 . V_317 -> V_345 << V_98 ;
F_18 ( & V_14 -> V_25 ) ;
if ( F_266 ( V_14 ) && F_269 ( V_14 ) ) {
V_164 -= V_346 * V_35 ;
F_19 ( V_14 , 0 , V_343 , V_164 ) ;
V_20 = F_270 ( V_14 ) ;
if ( V_20 ) {
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
} else {
F_19 ( V_14 , 0 , V_343 ,
V_164 ) ;
}
V_20 = F_259 ( V_14 ) ;
F_20 ( & V_14 -> V_25 ) ;
if ( V_20 ) {
F_271 ( V_14 ) ;
return V_20 ;
}
if ( ! F_16 ( V_14 , V_31 ) )
V_8 -> V_347 . V_348 = 1 ;
return 0 ;
}
void
F_245 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_178 * V_179 ;
int V_173 ;
F_155 (ring, dev_priv, i)
F_265 ( V_179 ) ;
}
int
F_272 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_210 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_20 ;
if ( F_16 ( V_14 , V_31 ) )
return 0 ;
if ( F_6 ( & V_8 -> V_10 . V_21 ) ) {
F_111 ( L_14 ) ;
F_273 ( & V_8 -> V_10 . V_21 , 0 ) ;
}
F_18 ( & V_14 -> V_25 ) ;
V_8 -> V_10 . V_213 = 0 ;
V_20 = F_259 ( V_14 ) ;
if ( V_20 != 0 ) {
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
F_115 ( ! F_129 ( & V_8 -> V_10 . V_181 ) ) ;
F_115 ( ! F_129 ( & V_8 -> V_10 . V_191 ) ) ;
F_115 ( ! F_129 ( & V_8 -> V_10 . V_150 ) ) ;
F_20 ( & V_14 -> V_25 ) ;
V_20 = F_274 ( V_14 ) ;
if ( V_20 )
goto V_349;
return 0 ;
V_349:
F_18 ( & V_14 -> V_25 ) ;
F_245 ( V_14 ) ;
V_8 -> V_10 . V_213 = 1 ;
F_20 ( & V_14 -> V_25 ) ;
return V_20 ;
}
int
F_275 ( struct V_13 * V_14 , void * V_27 ,
struct V_28 * V_210 )
{
if ( F_16 ( V_14 , V_31 ) )
return 0 ;
F_276 ( V_14 ) ;
return F_242 ( V_14 ) ;
}
void
F_277 ( struct V_13 * V_14 )
{
int V_20 ;
if ( F_16 ( V_14 , V_31 ) )
return;
V_20 = F_242 ( V_14 ) ;
if ( V_20 )
F_111 ( L_15 , V_20 ) ;
}
static void
F_278 ( struct V_178 * V_179 )
{
F_153 ( & V_179 -> V_181 ) ;
F_153 ( & V_179 -> V_207 ) ;
F_153 ( & V_179 -> V_192 ) ;
}
void
F_279 ( struct V_13 * V_14 )
{
int V_173 ;
T_5 * V_8 = V_14 -> V_15 ;
F_153 ( & V_8 -> V_10 . V_181 ) ;
F_153 ( & V_8 -> V_10 . V_191 ) ;
F_153 ( & V_8 -> V_10 . V_150 ) ;
F_153 ( & V_8 -> V_10 . V_190 ) ;
F_153 ( & V_8 -> V_10 . V_242 ) ;
for ( V_173 = 0 ; V_173 < V_350 ; V_173 ++ )
F_278 ( & V_8 -> V_179 [ V_173 ] ) ;
for ( V_173 = 0 ; V_173 < V_351 ; V_173 ++ )
F_153 ( & V_8 -> V_188 [ V_173 ] . V_189 ) ;
F_280 ( & V_8 -> V_10 . V_218 ,
F_161 ) ;
F_281 ( & V_8 -> V_18 ) ;
if ( F_282 ( V_14 ) ) {
F_200 ( V_352 ,
F_251 ( V_353 ) ) ;
}
V_8 -> V_354 = V_355 ;
if ( ! F_16 ( V_14 , V_31 ) )
V_8 -> V_266 = 3 ;
if ( F_17 ( V_14 ) -> V_37 >= 4 || F_283 ( V_14 ) || F_284 ( V_14 ) || F_109 ( V_14 ) )
V_8 -> V_220 = 16 ;
else
V_8 -> V_220 = 8 ;
F_151 ( V_14 ) ;
F_285 ( V_14 ) ;
F_286 ( & V_8 -> V_356 ) ;
V_8 -> V_10 . V_231 = true ;
V_8 -> V_10 . V_357 . V_358 = V_359 ;
V_8 -> V_10 . V_357 . V_360 = V_361 ;
F_287 ( & V_8 -> V_10 . V_357 ) ;
}
static int F_288 ( struct V_13 * V_14 ,
int V_362 , int V_9 , int V_363 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_364 * V_126 ;
int V_20 ;
if ( V_8 -> V_10 . V_365 [ V_362 - 1 ] || ! V_9 )
return 0 ;
V_126 = F_165 ( sizeof( struct V_364 ) , V_229 ) ;
if ( ! V_126 )
return - V_47 ;
V_126 -> V_362 = V_362 ;
V_126 -> V_46 = F_289 ( V_14 , V_9 , V_363 ) ;
if ( ! V_126 -> V_46 ) {
V_20 = - V_47 ;
goto V_366;
}
#ifdef F_290
F_291 ( ( unsigned long ) V_126 -> V_46 -> V_72 , V_126 -> V_46 -> V_9 / V_35 ) ;
#endif
V_8 -> V_10 . V_365 [ V_362 - 1 ] = V_126 ;
return 0 ;
V_366:
F_28 ( V_126 ) ;
return V_20 ;
}
static void F_292 ( struct V_13 * V_14 , int V_362 )
{
T_5 * V_8 = V_14 -> V_15 ;
struct V_364 * V_126 ;
if ( ! V_8 -> V_10 . V_365 [ V_362 - 1 ] )
return;
V_126 = V_8 -> V_10 . V_365 [ V_362 - 1 ] ;
if ( V_126 -> V_367 ) {
F_241 ( V_14 , V_126 -> V_367 ) ;
}
#ifdef F_290
F_293 ( ( unsigned long ) V_126 -> V_46 -> V_72 , V_126 -> V_46 -> V_9 / V_35 ) ;
#endif
F_294 ( V_14 , V_126 -> V_46 ) ;
F_28 ( V_126 ) ;
V_8 -> V_10 . V_365 [ V_362 - 1 ] = NULL ;
}
void F_295 ( struct V_13 * V_14 )
{
int V_173 ;
for ( V_173 = V_368 ; V_173 <= V_369 ; V_173 ++ )
F_292 ( V_14 , V_173 ) ;
}
void F_241 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_78 * V_79 = V_2 -> V_48 . V_80 -> V_81 . V_82 -> V_83 -> V_84 ;
char * V_72 ;
int V_173 ;
int V_172 ;
if ( ! V_2 -> V_126 )
return;
V_72 = V_2 -> V_126 -> V_46 -> V_72 ;
V_172 = V_2 -> V_48 . V_9 / V_35 ;
for ( V_173 = 0 ; V_173 < V_172 ; V_173 ++ ) {
struct V_66 * V_66 = F_57 ( V_79 , V_173 ) ;
if ( ! F_58 ( V_66 ) ) {
char * V_370 = F_44 ( V_66 ) ;
memcpy ( V_370 , V_72 + V_173 * V_35 , V_35 ) ;
F_47 ( V_370 ) ;
F_216 ( & V_66 , 1 ) ;
F_82 ( V_66 ) ;
F_64 ( V_66 ) ;
F_63 ( V_66 ) ;
}
}
F_84 () ;
V_2 -> V_126 -> V_367 = NULL ;
V_2 -> V_126 = NULL ;
}
int
F_296 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_362 ,
int V_363 )
{
struct V_78 * V_79 = V_2 -> V_48 . V_80 -> V_81 . V_82 -> V_83 -> V_84 ;
T_5 * V_8 = V_14 -> V_15 ;
int V_20 = 0 ;
int V_172 ;
int V_173 ;
if ( V_362 > V_369 )
return - V_36 ;
if ( V_2 -> V_126 ) {
if ( V_2 -> V_126 -> V_362 == V_362 )
return 0 ;
F_241 ( V_14 , V_2 ) ;
}
if ( ! V_8 -> V_10 . V_365 [ V_362 - 1 ] ) {
V_20 = F_288 ( V_14 , V_362 ,
V_2 -> V_48 . V_9 , V_363 ) ;
if ( V_20 ) {
F_111 ( L_16 ,
V_362 , V_2 -> V_48 . V_9 ) ;
return V_20 ;
}
}
V_2 -> V_126 = V_8 -> V_10 . V_365 [ V_362 - 1 ] ;
V_2 -> V_126 -> V_367 = V_2 ;
V_172 = V_2 -> V_48 . V_9 / V_35 ;
for ( V_173 = 0 ; V_173 < V_172 ; V_173 ++ ) {
struct V_66 * V_66 ;
char * V_370 , * V_371 ;
V_66 = F_57 ( V_79 , V_173 ) ;
if ( F_58 ( V_66 ) )
return F_59 ( V_66 ) ;
V_371 = F_44 ( V_66 ) ;
V_370 = V_2 -> V_126 -> V_46 -> V_72 + ( V_173 * V_35 ) ;
memcpy ( V_370 , V_371 , V_35 ) ;
F_47 ( V_371 ) ;
F_64 ( V_66 ) ;
F_63 ( V_66 ) ;
}
return 0 ;
}
static int
F_88 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_113 * args ,
struct V_28 * V_210 )
{
void * V_72 = V_2 -> V_126 -> V_46 -> V_72 + args -> V_86 ;
char T_6 * V_69 = ( char T_6 * ) ( V_91 ) args -> V_92 ;
if ( F_73 ( V_72 , V_69 , args -> V_9 ) ) {
unsigned long V_111 ;
F_20 ( & V_14 -> V_25 ) ;
V_111 = F_297 ( V_72 , V_69 , args -> V_9 ) ;
F_18 ( & V_14 -> V_25 ) ;
if ( V_111 )
return - V_101 ;
}
F_84 () ;
return 0 ;
}
void F_298 ( struct V_13 * V_14 , struct V_28 * V_29 )
{
struct V_209 * V_210 = V_29 -> V_211 ;
F_142 ( & V_210 -> V_10 . V_23 ) ;
while ( ! F_129 ( & V_210 -> V_10 . V_207 ) ) {
struct V_199 * V_200 ;
V_200 = F_150 ( & V_210 -> V_10 . V_207 ,
struct V_199 ,
V_212 ) ;
F_148 ( & V_200 -> V_212 ) ;
V_200 -> V_210 = NULL ;
}
F_143 ( & V_210 -> V_10 . V_23 ) ;
}
static int
F_299 ( struct V_13 * V_14 )
{
T_5 * V_8 = V_14 -> V_15 ;
int V_372 ;
V_372 = F_129 ( & V_8 -> V_10 . V_191 ) &&
F_129 ( & V_8 -> V_10 . V_181 ) ;
return ! V_372 ;
}
static int
V_359 ( struct V_373 * V_373 , struct V_374 * V_375 )
{
struct V_7 * V_8 =
F_162 ( V_373 ,
struct V_7 ,
V_10 . V_357 ) ;
struct V_13 * V_14 = V_8 -> V_14 ;
struct V_1 * V_2 , * V_195 ;
int V_376 = V_375 -> V_376 ;
int V_377 ;
if ( ! F_163 ( & V_14 -> V_25 ) )
return 0 ;
if ( V_376 == 0 ) {
V_377 = 0 ;
F_22 (obj,
&dev_priv->mm.inactive_list,
mm_list)
V_377 ++ ;
F_20 ( & V_14 -> V_25 ) ;
return V_377 / 100 * V_378 ;
}
V_379:
F_160 ( V_14 ) ;
F_134 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( F_132 ( V_2 ) ) {
if ( F_98 ( V_2 ) == 0 &&
-- V_376 == 0 )
break;
}
}
V_377 = 0 ;
F_134 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( V_376 &&
F_98 ( V_2 ) == 0 )
V_376 -- ;
else
V_377 ++ ;
}
if ( V_376 && F_299 ( V_14 ) ) {
if ( F_190 ( V_14 ) == 0 )
goto V_379;
}
F_20 ( & V_14 -> V_25 ) ;
return V_377 / 100 * V_378 ;
}
