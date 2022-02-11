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
static inline void
F_36 ( struct V_61 * V_62 ,
int V_63 ,
struct V_61 * V_64 ,
int V_65 ,
int V_66 )
{
char * V_67 , * V_68 ;
V_67 = F_37 ( V_62 ) ;
V_68 = F_37 ( V_64 ) ;
memcpy ( V_67 + V_63 , V_68 + V_65 , V_66 ) ;
F_38 ( V_64 ) ;
F_38 ( V_62 ) ;
}
static inline void
F_39 ( struct V_61 * V_69 ,
int V_70 ,
struct V_61 * V_71 ,
int V_72 ,
int V_66 ,
int V_73 )
{
char * V_74 , * V_75 ;
if ( ( F_40 ( V_69 ) & ( 1 << 17 ) ) == 0 ) {
if ( V_73 )
return F_36 ( V_71 , V_72 ,
V_69 , V_70 , V_66 ) ;
else
return F_36 ( V_69 , V_70 ,
V_71 , V_72 , V_66 ) ;
}
V_74 = F_37 ( V_69 ) ;
V_75 = F_37 ( V_71 ) ;
while ( V_66 > 0 ) {
int V_76 = F_31 ( V_70 + 1 , 64 ) ;
int V_77 = F_15 ( V_76 - V_70 , V_66 ) ;
int V_78 = V_70 ^ 64 ;
if ( V_73 ) {
memcpy ( V_75 + V_72 ,
V_74 + V_78 ,
V_77 ) ;
} else {
memcpy ( V_74 + V_78 ,
V_75 + V_72 ,
V_77 ) ;
}
V_72 += V_77 ;
V_70 += V_77 ;
V_66 -= V_77 ;
}
F_38 ( V_71 ) ;
F_38 ( V_69 ) ;
}
static int
F_41 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_79 * args ,
struct V_35 * V_36 )
{
struct V_80 * V_81 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
T_6 V_87 ;
T_7 V_88 ;
char T_8 * V_89 ;
int V_90 , V_91 ;
V_89 = ( char T_8 * ) ( V_92 ) args -> V_93 ;
V_87 = args -> V_3 ;
V_88 = args -> V_88 ;
while ( V_87 > 0 ) {
struct V_61 * V_61 ;
char * V_94 ;
int V_14 ;
V_90 = F_42 ( V_88 ) ;
V_91 = V_87 ;
if ( ( V_90 + V_87 ) > V_33 )
V_91 = V_33 - V_90 ;
V_61 = F_43 ( V_81 , V_88 >> V_95 ) ;
if ( F_44 ( V_61 ) )
return F_45 ( V_61 ) ;
V_94 = F_46 ( V_61 ) ;
V_14 = F_47 ( V_89 ,
V_94 + V_90 ,
V_91 ) ;
F_48 ( V_94 ) ;
F_49 ( V_61 ) ;
F_50 ( V_61 ) ;
if ( V_14 )
return - V_96 ;
V_87 -= V_91 ;
V_89 += V_91 ;
V_88 += V_91 ;
}
return 0 ;
}
static int
F_51 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_79 * args ,
struct V_35 * V_36 )
{
struct V_80 * V_81 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
struct V_97 * V_4 = V_98 -> V_4 ;
struct V_61 * * V_99 ;
T_6 V_87 ;
T_7 V_88 , V_100 , V_101 ;
T_7 V_102 , V_103 , V_104 ;
int V_105 ;
int V_106 , V_107 ;
int V_91 ;
int V_14 ;
T_3 V_93 = args -> V_93 ;
int V_108 ;
V_87 = args -> V_3 ;
V_102 = V_93 / V_33 ;
V_103 = ( V_93 + args -> V_3 - 1 ) / V_33 ;
V_104 = V_103 - V_102 + 1 ;
V_99 = F_52 ( V_104 , sizeof( struct V_61 * ) ) ;
if ( V_99 == NULL )
return - V_49 ;
F_19 ( & V_8 -> V_19 ) ;
F_53 ( & V_4 -> V_109 ) ;
V_100 = F_54 ( V_98 , V_4 , ( V_92 ) args -> V_93 ,
V_104 , 1 , 0 , V_99 , NULL ) ;
F_55 ( & V_4 -> V_109 ) ;
F_18 ( & V_8 -> V_19 ) ;
if ( V_100 < V_104 ) {
V_14 = - V_96 ;
goto V_110;
}
V_14 = F_56 ( V_21 ,
args -> V_88 ,
args -> V_3 ) ;
if ( V_14 )
goto V_110;
V_108 = F_35 ( V_21 ) ;
V_88 = args -> V_88 ;
while ( V_87 > 0 ) {
struct V_61 * V_61 ;
V_105 = F_42 ( V_88 ) ;
V_106 = V_93 / V_33 - V_102 ;
V_107 = F_42 ( V_93 ) ;
V_91 = V_87 ;
if ( ( V_105 + V_91 ) > V_33 )
V_91 = V_33 - V_105 ;
if ( ( V_107 + V_91 ) > V_33 )
V_91 = V_33 - V_107 ;
V_61 = F_43 ( V_81 , V_88 >> V_95 ) ;
if ( F_44 ( V_61 ) ) {
V_14 = F_45 ( V_61 ) ;
goto V_110;
}
if ( V_108 ) {
F_39 ( V_61 ,
V_105 ,
V_99 [ V_106 ] ,
V_107 ,
V_91 ,
1 ) ;
} else {
F_36 ( V_99 [ V_106 ] ,
V_107 ,
V_61 ,
V_105 ,
V_91 ) ;
}
F_49 ( V_61 ) ;
F_50 ( V_61 ) ;
V_87 -= V_91 ;
V_93 += V_91 ;
V_88 += V_91 ;
}
V_110:
for ( V_101 = 0 ; V_101 < V_100 ; V_101 ++ ) {
F_57 ( V_99 [ V_101 ] ) ;
F_49 ( V_99 [ V_101 ] ) ;
F_50 ( V_99 [ V_101 ] ) ;
}
F_58 ( V_99 ) ;
return V_14 ;
}
int
F_59 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_79 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 = 0 ;
if ( args -> V_3 == 0 )
return 0 ;
if ( ! F_60 ( V_111 ,
( char T_8 * ) ( V_92 ) args -> V_93 ,
args -> V_3 ) )
return - V_96 ;
V_14 = F_61 ( ( char T_8 * ) ( V_92 ) args -> V_93 ,
args -> V_3 ) ;
if ( V_14 )
return - V_96 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_62 ( F_63 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_112 ;
goto V_113;
}
if ( args -> V_88 > V_21 -> V_50 . V_3 ||
args -> V_3 > V_21 -> V_50 . V_3 - args -> V_88 ) {
V_14 = - V_38 ;
goto V_110;
}
F_64 ( V_21 , args -> V_88 , args -> V_3 ) ;
V_14 = F_56 ( V_21 ,
args -> V_88 ,
args -> V_3 ) ;
if ( V_14 )
goto V_110;
V_14 = - V_96 ;
if ( ! F_35 ( V_21 ) )
V_14 = F_41 ( V_8 , V_21 , args , V_36 ) ;
if ( V_14 == - V_96 )
V_14 = F_51 ( V_8 , V_21 , args , V_36 ) ;
V_110:
F_28 ( & V_21 -> V_50 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
static inline int
F_65 ( struct V_114 * V_81 ,
T_7 V_115 , int V_90 ,
char T_8 * V_89 ,
int V_66 )
{
char * V_116 ;
unsigned long V_117 ;
V_116 = F_66 ( V_81 , V_115 ) ;
V_117 = F_67 ( V_116 + V_90 ,
V_89 , V_66 ) ;
F_68 ( V_116 ) ;
return V_117 ;
}
static inline void
F_69 ( struct V_114 * V_81 ,
T_7 V_118 , int V_119 ,
struct V_61 * V_120 , int V_121 ,
int V_66 )
{
char T_9 * V_67 ;
char * V_68 ;
V_67 = F_70 ( V_81 , V_118 ) ;
V_68 = F_37 ( V_120 ) ;
F_71 ( V_67 + V_119 ,
V_68 + V_121 ,
V_66 ) ;
F_38 ( V_120 ) ;
F_72 ( V_67 ) ;
}
static int
F_73 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_122 * args ,
struct V_35 * V_36 )
{
T_2 * V_2 = V_8 -> V_9 ;
T_6 V_87 ;
T_7 V_88 , V_115 ;
char T_8 * V_89 ;
int V_90 , V_91 ;
V_89 = ( char T_8 * ) ( V_92 ) args -> V_93 ;
V_87 = args -> V_3 ;
V_88 = V_21 -> V_119 + args -> V_88 ;
while ( V_87 > 0 ) {
V_115 = V_88 & V_123 ;
V_90 = F_42 ( V_88 ) ;
V_91 = V_87 ;
if ( ( V_90 + V_87 ) > V_33 )
V_91 = V_33 - V_90 ;
if ( F_65 ( V_2 -> V_4 . V_124 , V_115 ,
V_90 , V_89 , V_91 ) )
return - V_96 ;
V_87 -= V_91 ;
V_89 += V_91 ;
V_88 += V_91 ;
}
return 0 ;
}
static int
F_74 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_122 * args ,
struct V_35 * V_36 )
{
T_2 * V_2 = V_8 -> V_9 ;
T_6 V_87 ;
T_7 V_125 , V_88 ;
T_7 V_102 , V_103 , V_104 ;
T_7 V_100 , V_101 ;
struct V_61 * * V_99 ;
struct V_97 * V_4 = V_98 -> V_4 ;
int V_126 , V_107 , V_106 , V_91 ;
int V_14 ;
T_3 V_93 = args -> V_93 ;
V_87 = args -> V_3 ;
V_102 = V_93 / V_33 ;
V_103 = ( V_93 + args -> V_3 - 1 ) / V_33 ;
V_104 = V_103 - V_102 + 1 ;
V_99 = F_52 ( V_104 , sizeof( struct V_61 * ) ) ;
if ( V_99 == NULL )
return - V_49 ;
F_19 ( & V_8 -> V_19 ) ;
F_53 ( & V_4 -> V_109 ) ;
V_100 = F_54 ( V_98 , V_4 , ( V_92 ) args -> V_93 ,
V_104 , 0 , 0 , V_99 , NULL ) ;
F_55 ( & V_4 -> V_109 ) ;
F_18 ( & V_8 -> V_19 ) ;
if ( V_100 < V_104 ) {
V_14 = - V_96 ;
goto V_127;
}
V_14 = F_75 ( V_21 , true ) ;
if ( V_14 )
goto V_127;
V_14 = F_76 ( V_21 ) ;
if ( V_14 )
goto V_127;
V_88 = V_21 -> V_119 + args -> V_88 ;
while ( V_87 > 0 ) {
V_125 = V_88 & V_123 ;
V_126 = F_42 ( V_88 ) ;
V_106 = V_93 / V_33 - V_102 ;
V_107 = F_42 ( V_93 ) ;
V_91 = V_87 ;
if ( ( V_126 + V_91 ) > V_33 )
V_91 = V_33 - V_126 ;
if ( ( V_107 + V_91 ) > V_33 )
V_91 = V_33 - V_107 ;
F_69 ( V_2 -> V_4 . V_124 ,
V_125 , V_126 ,
V_99 [ V_106 ] ,
V_107 ,
V_91 ) ;
V_87 -= V_91 ;
V_88 += V_91 ;
V_93 += V_91 ;
}
V_127:
for ( V_101 = 0 ; V_101 < V_100 ; V_101 ++ )
F_50 ( V_99 [ V_101 ] ) ;
F_58 ( V_99 ) ;
return V_14 ;
}
static int
F_77 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_122 * args ,
struct V_35 * V_36 )
{
struct V_80 * V_81 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
T_6 V_87 ;
T_7 V_88 ;
char T_8 * V_89 ;
int V_90 , V_91 ;
V_89 = ( char T_8 * ) ( V_92 ) args -> V_93 ;
V_87 = args -> V_3 ;
V_88 = args -> V_88 ;
V_21 -> V_128 = 1 ;
while ( V_87 > 0 ) {
struct V_61 * V_61 ;
char * V_94 ;
int V_14 ;
V_90 = F_42 ( V_88 ) ;
V_91 = V_87 ;
if ( ( V_90 + V_87 ) > V_33 )
V_91 = V_33 - V_90 ;
V_61 = F_43 ( V_81 , V_88 >> V_95 ) ;
if ( F_44 ( V_61 ) )
return F_45 ( V_61 ) ;
V_94 = F_46 ( V_61 ) ;
V_14 = F_78 ( V_94 + V_90 ,
V_89 ,
V_91 ) ;
F_48 ( V_94 ) ;
F_79 ( V_61 ) ;
F_49 ( V_61 ) ;
F_50 ( V_61 ) ;
if ( V_14 )
return - V_96 ;
V_87 -= V_91 ;
V_89 += V_91 ;
V_88 += V_91 ;
}
return 0 ;
}
static int
F_80 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_122 * args ,
struct V_35 * V_36 )
{
struct V_80 * V_81 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
struct V_97 * V_4 = V_98 -> V_4 ;
struct V_61 * * V_99 ;
T_6 V_87 ;
T_7 V_88 , V_100 , V_101 ;
T_7 V_102 , V_103 , V_104 ;
int V_105 ;
int V_106 , V_107 ;
int V_91 ;
int V_14 ;
T_3 V_93 = args -> V_93 ;
int V_108 ;
V_87 = args -> V_3 ;
V_102 = V_93 / V_33 ;
V_103 = ( V_93 + args -> V_3 - 1 ) / V_33 ;
V_104 = V_103 - V_102 + 1 ;
V_99 = F_52 ( V_104 , sizeof( struct V_61 * ) ) ;
if ( V_99 == NULL )
return - V_49 ;
F_19 ( & V_8 -> V_19 ) ;
F_53 ( & V_4 -> V_109 ) ;
V_100 = F_54 ( V_98 , V_4 , ( V_92 ) args -> V_93 ,
V_104 , 0 , 0 , V_99 , NULL ) ;
F_55 ( & V_4 -> V_109 ) ;
F_18 ( & V_8 -> V_19 ) ;
if ( V_100 < V_104 ) {
V_14 = - V_96 ;
goto V_110;
}
V_14 = F_81 ( V_21 , 1 ) ;
if ( V_14 )
goto V_110;
V_108 = F_35 ( V_21 ) ;
V_88 = args -> V_88 ;
V_21 -> V_128 = 1 ;
while ( V_87 > 0 ) {
struct V_61 * V_61 ;
V_105 = F_42 ( V_88 ) ;
V_106 = V_93 / V_33 - V_102 ;
V_107 = F_42 ( V_93 ) ;
V_91 = V_87 ;
if ( ( V_105 + V_91 ) > V_33 )
V_91 = V_33 - V_105 ;
if ( ( V_107 + V_91 ) > V_33 )
V_91 = V_33 - V_107 ;
V_61 = F_43 ( V_81 , V_88 >> V_95 ) ;
if ( F_44 ( V_61 ) ) {
V_14 = F_45 ( V_61 ) ;
goto V_110;
}
if ( V_108 ) {
F_39 ( V_61 ,
V_105 ,
V_99 [ V_106 ] ,
V_107 ,
V_91 ,
0 ) ;
} else {
F_36 ( V_61 ,
V_105 ,
V_99 [ V_106 ] ,
V_107 ,
V_91 ) ;
}
F_79 ( V_61 ) ;
F_49 ( V_61 ) ;
F_50 ( V_61 ) ;
V_87 -= V_91 ;
V_93 += V_91 ;
V_88 += V_91 ;
}
V_110:
for ( V_101 = 0 ; V_101 < V_100 ; V_101 ++ )
F_50 ( V_99 [ V_101 ] ) ;
F_58 ( V_99 ) ;
return V_14 ;
}
int
F_82 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_122 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 ;
if ( args -> V_3 == 0 )
return 0 ;
if ( ! F_60 ( V_129 ,
( char T_8 * ) ( V_92 ) args -> V_93 ,
args -> V_3 ) )
return - V_96 ;
V_14 = F_83 ( ( char T_8 * ) ( V_92 ) args -> V_93 ,
args -> V_3 ) ;
if ( V_14 )
return - V_96 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_62 ( F_63 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_112 ;
goto V_113;
}
if ( args -> V_88 > V_21 -> V_50 . V_3 ||
args -> V_3 > V_21 -> V_50 . V_3 - args -> V_88 ) {
V_14 = - V_38 ;
goto V_110;
}
F_84 ( V_21 , args -> V_88 , args -> V_3 ) ;
if ( V_21 -> V_130 )
V_14 = F_85 ( V_8 , V_21 , args , V_36 ) ;
else if ( V_21 -> V_22 &&
V_21 -> V_50 . V_131 != V_132 ) {
V_14 = F_86 ( V_21 , 0 , true ) ;
if ( V_14 )
goto V_110;
V_14 = F_75 ( V_21 , true ) ;
if ( V_14 )
goto V_133;
V_14 = F_76 ( V_21 ) ;
if ( V_14 )
goto V_133;
V_14 = F_73 ( V_8 , V_21 , args , V_36 ) ;
if ( V_14 == - V_96 )
V_14 = F_74 ( V_8 , V_21 , args , V_36 ) ;
V_133:
F_87 ( V_21 ) ;
} else {
V_14 = F_81 ( V_21 , 1 ) ;
if ( V_14 )
goto V_110;
V_14 = - V_96 ;
if ( ! F_35 ( V_21 ) )
V_14 = F_77 ( V_8 , V_21 , args , V_36 ) ;
if ( V_14 == - V_96 )
V_14 = F_80 ( V_8 , V_21 , args , V_36 ) ;
}
V_110:
F_28 ( & V_21 -> V_50 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_88 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_134 * args = V_34 ;
struct V_20 * V_21 ;
T_4 V_135 = args -> V_135 ;
T_4 V_131 = args -> V_131 ;
int V_14 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
if ( V_131 & V_136 )
return - V_38 ;
if ( V_135 & V_136 )
return - V_38 ;
if ( V_131 != 0 && V_135 != V_131 )
return - V_38 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_62 ( F_63 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_112 ;
goto V_113;
}
if ( V_135 & V_137 ) {
V_14 = F_75 ( V_21 , V_131 != 0 ) ;
if ( V_14 == - V_38 )
V_14 = 0 ;
} else {
V_14 = F_81 ( V_21 , V_131 != 0 ) ;
}
F_28 ( & V_21 -> V_50 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_89 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_138 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 = 0 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_62 ( F_63 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_112 ;
goto V_113;
}
if ( V_21 -> V_24 )
F_90 ( V_21 ) ;
F_28 ( & V_21 -> V_50 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_91 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_139 * args = V_34 ;
struct V_140 * V_21 ;
unsigned long V_141 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
V_21 = F_63 ( V_8 , V_36 , args -> V_48 ) ;
if ( V_21 == NULL )
return - V_112 ;
if ( V_21 -> V_3 > V_2 -> V_4 . V_29 ) {
F_92 ( V_21 ) ;
return - V_142 ;
}
F_93 ( & V_98 -> V_4 -> V_109 ) ;
V_141 = F_94 ( V_21 -> V_82 , 0 , args -> V_3 ,
V_143 | V_144 , V_145 ,
args -> V_88 ) ;
F_95 ( & V_98 -> V_4 -> V_109 ) ;
F_92 ( V_21 ) ;
if ( F_44 ( ( void * ) V_141 ) )
return V_141 ;
args -> V_146 = ( T_3 ) V_141 ;
return 0 ;
}
int F_96 ( struct V_147 * V_148 , struct V_149 * V_150 )
{
struct V_20 * V_21 = F_62 ( V_148 -> V_151 ) ;
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_10 V_90 ;
unsigned long V_152 ;
int V_14 = 0 ;
bool V_153 = ! ! ( V_150 -> V_13 & V_154 ) ;
V_90 = ( ( unsigned long ) V_150 -> V_155 - V_148 -> V_156 ) >>
V_95 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
goto V_110;
F_97 ( V_21 , V_90 , true , V_153 ) ;
if ( ! V_21 -> V_157 ) {
V_14 = F_98 ( V_21 ) ;
if ( V_14 )
goto V_113;
}
if ( ! V_21 -> V_22 ) {
V_14 = F_99 ( V_21 , 0 , true ) ;
if ( V_14 )
goto V_113;
V_14 = F_75 ( V_21 , V_153 ) ;
if ( V_14 )
goto V_113;
}
if ( V_21 -> V_59 == V_60 )
V_14 = F_76 ( V_21 ) ;
else
V_14 = F_100 ( V_21 , NULL ) ;
if ( V_14 )
goto V_113;
if ( F_12 ( V_21 ) )
F_101 ( & V_21 -> V_158 , & V_2 -> V_4 . V_159 ) ;
V_21 -> V_160 = true ;
V_152 = ( ( V_8 -> V_161 -> V_50 + V_21 -> V_119 ) >> V_95 ) +
V_90 ;
V_14 = F_102 ( V_148 , ( unsigned long ) V_150 -> V_155 , V_152 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
V_110:
switch ( V_14 ) {
case - V_162 :
case - V_163 :
F_103 () ;
case 0 :
case - V_164 :
case - V_165 :
return V_166 ;
case - V_49 :
return V_167 ;
default:
return V_168 ;
}
}
void
F_104 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_160 )
return;
if ( V_21 -> V_50 . V_8 -> V_169 )
F_105 ( V_21 -> V_50 . V_8 -> V_169 ,
( T_7 ) V_21 -> V_50 . V_170 . V_171 . V_172 << V_95 ,
V_21 -> V_50 . V_3 , 1 ) ;
V_21 -> V_160 = false ;
}
static T_4
F_106 ( struct V_7 * V_8 , T_4 V_3 , int V_59 )
{
T_4 V_173 ;
if ( F_107 ( V_8 ) -> V_174 >= 4 ||
V_59 == V_60 )
return V_3 ;
if ( F_107 ( V_8 ) -> V_174 == 3 )
V_173 = 1024 * 1024 ;
else
V_173 = 512 * 1024 ;
while ( V_173 < V_3 )
V_173 <<= 1 ;
return V_173 ;
}
static T_4
F_108 ( struct V_7 * V_8 ,
T_4 V_3 ,
int V_59 )
{
if ( F_107 ( V_8 ) -> V_174 >= 4 ||
V_59 == V_60 )
return 4096 ;
return F_106 ( V_8 , V_3 , V_59 ) ;
}
T_4
F_109 ( struct V_7 * V_8 ,
T_4 V_3 ,
int V_59 )
{
if ( F_107 ( V_8 ) -> V_174 >= 4 || F_110 ( V_8 ) ||
V_59 == V_60 )
return 4096 ;
return F_106 ( V_8 , V_3 , V_59 ) ;
}
int
F_111 ( struct V_35 * V_36 ,
struct V_7 * V_8 ,
T_4 V_48 ,
T_3 * V_88 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_20 * V_21 ;
int V_14 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_62 ( F_63 ( V_8 , V_36 , V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_112 ;
goto V_113;
}
if ( V_21 -> V_50 . V_3 > V_2 -> V_4 . V_29 ) {
V_14 = - V_142 ;
goto V_110;
}
if ( V_21 -> V_175 != V_176 ) {
F_112 ( L_1 ) ;
V_14 = - V_38 ;
goto V_110;
}
if ( ! V_21 -> V_50 . V_170 . V_177 ) {
V_14 = F_113 ( & V_21 -> V_50 ) ;
if ( V_14 )
goto V_110;
}
* V_88 = ( V_178 ) V_21 -> V_50 . V_170 . V_171 . V_172 << V_95 ;
V_110:
F_28 ( & V_21 -> V_50 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_114 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_179 * args = V_34 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
return F_111 ( V_36 , V_8 , args -> V_48 , & args -> V_88 ) ;
}
static int
F_115 ( struct V_20 * V_21 ,
T_11 V_180 )
{
int V_181 , V_101 ;
struct V_80 * V_81 ;
struct V_182 * V_182 ;
struct V_61 * V_61 ;
V_181 = V_21 -> V_50 . V_3 / V_33 ;
F_116 ( V_21 -> V_183 != NULL ) ;
V_21 -> V_183 = F_52 ( V_181 , sizeof( struct V_61 * ) ) ;
if ( V_21 -> V_183 == NULL )
return - V_49 ;
V_182 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 ;
V_81 = V_182 -> V_86 ;
V_180 |= F_117 ( V_81 ) ;
for ( V_101 = 0 ; V_101 < V_181 ; V_101 ++ ) {
V_61 = F_118 ( V_81 , V_101 , V_180 ) ;
if ( F_44 ( V_61 ) )
goto V_184;
V_21 -> V_183 [ V_101 ] = V_61 ;
}
if ( F_35 ( V_21 ) )
F_119 ( V_21 ) ;
return 0 ;
V_184:
while ( V_101 -- )
F_50 ( V_21 -> V_183 [ V_101 ] ) ;
F_58 ( V_21 -> V_183 ) ;
V_21 -> V_183 = NULL ;
return F_45 ( V_61 ) ;
}
static void
F_120 ( struct V_20 * V_21 )
{
int V_181 = V_21 -> V_50 . V_3 / V_33 ;
int V_101 ;
F_116 ( V_21 -> V_175 == V_185 ) ;
if ( F_35 ( V_21 ) )
F_121 ( V_21 ) ;
if ( V_21 -> V_175 == V_186 )
V_21 -> V_128 = 0 ;
for ( V_101 = 0 ; V_101 < V_181 ; V_101 ++ ) {
if ( V_21 -> V_128 )
F_79 ( V_21 -> V_183 [ V_101 ] ) ;
if ( V_21 -> V_175 == V_176 )
F_49 ( V_21 -> V_183 [ V_101 ] ) ;
F_50 ( V_21 -> V_183 [ V_101 ] ) ;
}
V_21 -> V_128 = 0 ;
F_58 ( V_21 -> V_183 ) ;
V_21 -> V_183 = NULL ;
}
void
F_122 ( struct V_20 * V_21 ,
struct V_187 * V_188 ,
T_5 V_189 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
F_116 ( V_188 == NULL ) ;
V_21 -> V_188 = V_188 ;
if ( ! V_21 -> V_23 ) {
F_123 ( & V_21 -> V_50 ) ;
V_21 -> V_23 = 1 ;
}
F_101 ( & V_21 -> V_158 , & V_2 -> V_4 . V_190 ) ;
F_101 ( & V_21 -> V_191 , & V_188 -> V_190 ) ;
V_21 -> V_192 = V_189 ;
if ( V_21 -> V_193 ) {
struct V_194 * V_195 ;
F_116 ( V_21 -> V_196 == V_197 ) ;
V_21 -> V_198 = V_189 ;
V_21 -> V_199 = V_188 ;
V_195 = & V_2 -> V_200 [ V_21 -> V_196 ] ;
F_101 ( & V_195 -> V_201 , & V_2 -> V_4 . V_202 ) ;
}
}
static void
F_124 ( struct V_20 * V_21 )
{
F_125 ( & V_21 -> V_191 ) ;
V_21 -> V_192 = 0 ;
}
static void
F_126 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
F_116 ( ! V_21 -> V_23 ) ;
F_101 ( & V_21 -> V_158 , & V_2 -> V_4 . V_203 ) ;
F_124 ( V_21 ) ;
}
static void
F_127 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
if ( V_21 -> V_24 != 0 )
F_101 ( & V_21 -> V_158 , & V_2 -> V_4 . V_204 ) ;
else
F_101 ( & V_21 -> V_158 , & V_2 -> V_4 . V_159 ) ;
F_116 ( ! F_128 ( & V_21 -> V_205 ) ) ;
F_116 ( ! V_21 -> V_23 ) ;
V_21 -> V_188 = NULL ;
F_124 ( V_21 ) ;
V_21 -> V_193 = false ;
V_21 -> V_23 = 0 ;
V_21 -> V_206 = false ;
F_28 ( & V_21 -> V_50 ) ;
F_10 ( F_11 ( V_8 ) ) ;
}
static void
F_129 ( struct V_20 * V_21 )
{
struct V_182 * V_182 ;
V_182 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 ;
F_130 ( V_182 , 0 , ( T_7 ) - 1 ) ;
V_21 -> V_175 = V_185 ;
}
static inline int
F_131 ( struct V_20 * V_21 )
{
return V_21 -> V_175 == V_186 ;
}
static void
F_132 ( struct V_187 * V_188 ,
T_4 V_207 )
{
struct V_20 * V_21 , * V_208 ;
F_133 (obj, next,
&ring->gpu_write_list,
gpu_write_list) {
if ( V_21 -> V_50 . V_131 & V_207 ) {
T_4 V_209 = V_21 -> V_50 . V_131 ;
V_21 -> V_50 . V_131 = 0 ;
F_125 ( & V_21 -> V_205 ) ;
F_122 ( V_21 , V_188 ,
F_134 ( V_188 ) ) ;
F_135 ( V_21 ,
V_21 -> V_50 . V_135 ,
V_209 ) ;
}
}
}
int
F_136 ( struct V_187 * V_188 ,
struct V_35 * V_36 ,
struct V_210 * V_211 )
{
T_2 * V_2 = V_188 -> V_8 -> V_9 ;
T_4 V_189 ;
int V_212 ;
int V_14 ;
F_116 ( V_211 == NULL ) ;
V_14 = V_188 -> V_213 ( V_188 , & V_189 ) ;
if ( V_14 )
return V_14 ;
F_137 ( V_188 , V_189 ) ;
V_211 -> V_189 = V_189 ;
V_211 -> V_188 = V_188 ;
V_211 -> V_214 = V_215 ;
V_212 = F_128 ( & V_188 -> V_216 ) ;
F_138 ( & V_211 -> V_217 , & V_188 -> V_216 ) ;
if ( V_36 ) {
struct V_218 * V_219 = V_36 -> V_220 ;
F_139 ( & V_219 -> V_4 . V_17 ) ;
V_211 -> V_219 = V_219 ;
F_138 ( & V_211 -> V_221 ,
& V_219 -> V_4 . V_216 ) ;
F_140 ( & V_219 -> V_4 . V_17 ) ;
}
V_188 -> V_222 = false ;
if ( ! V_2 -> V_4 . V_223 ) {
if ( V_224 ) {
F_141 ( & V_2 -> V_225 ,
V_215 +
F_142 ( V_226 ) ) ;
}
if ( V_212 )
F_143 ( V_2 -> V_227 ,
& V_2 -> V_4 . V_228 , V_229 ) ;
}
return 0 ;
}
static inline void
F_144 ( struct V_210 * V_211 )
{
struct V_218 * V_219 = V_211 -> V_219 ;
if ( ! V_219 )
return;
F_139 ( & V_219 -> V_4 . V_17 ) ;
if ( V_211 -> V_219 ) {
F_145 ( & V_211 -> V_221 ) ;
V_211 -> V_219 = NULL ;
}
F_140 ( & V_219 -> V_4 . V_17 ) ;
}
static void F_146 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
while ( ! F_128 ( & V_188 -> V_216 ) ) {
struct V_210 * V_211 ;
V_211 = F_147 ( & V_188 -> V_216 ,
struct V_210 ,
V_217 ) ;
F_145 ( & V_211 -> V_217 ) ;
F_144 ( V_211 ) ;
F_27 ( V_211 ) ;
}
while ( ! F_128 ( & V_188 -> V_190 ) ) {
struct V_20 * V_21 ;
V_21 = F_147 ( & V_188 -> V_190 ,
struct V_20 ,
V_191 ) ;
V_21 -> V_50 . V_131 = 0 ;
F_125 ( & V_21 -> V_205 ) ;
F_127 ( V_21 ) ;
}
}
static void F_148 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_2 -> V_230 ; V_101 ++ ) {
struct V_194 * V_195 = & V_2 -> V_200 [ V_101 ] ;
struct V_20 * V_21 = V_195 -> V_21 ;
if ( ! V_21 )
continue;
if ( V_21 -> V_59 )
F_104 ( V_21 ) ;
V_195 -> V_21 -> V_196 = V_197 ;
V_195 -> V_21 -> V_193 = false ;
V_195 -> V_21 -> V_198 = 0 ;
V_195 -> V_21 -> V_199 = NULL ;
F_149 ( V_8 , V_195 ) ;
}
}
void F_150 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_20 * V_21 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_231 ; V_101 ++ )
F_146 ( V_2 , & V_2 -> V_188 [ V_101 ] ) ;
while ( ! F_128 ( & V_2 -> V_4 . V_203 ) ) {
V_21 = F_147 ( & V_2 -> V_4 . V_203 ,
struct V_20 ,
V_158 ) ;
V_21 -> V_50 . V_131 = 0 ;
F_125 ( & V_21 -> V_205 ) ;
F_127 ( V_21 ) ;
}
F_21 (obj,
&dev_priv->mm.inactive_list,
mm_list)
{
V_21 -> V_50 . V_135 &= ~ V_136 ;
}
F_148 ( V_8 ) ;
}
static void
F_151 ( struct V_187 * V_188 )
{
T_4 V_189 ;
int V_101 ;
if ( F_128 ( & V_188 -> V_216 ) )
return;
F_10 ( F_11 ( V_188 -> V_8 ) ) ;
V_189 = V_188 -> V_232 ( V_188 ) ;
for ( V_101 = 0 ; V_101 < F_152 ( V_188 -> V_233 ) ; V_101 ++ )
if ( V_189 >= V_188 -> V_233 [ V_101 ] )
V_188 -> V_233 [ V_101 ] = 0 ;
while ( ! F_128 ( & V_188 -> V_216 ) ) {
struct V_210 * V_211 ;
V_211 = F_147 ( & V_188 -> V_216 ,
struct V_210 ,
V_217 ) ;
if ( ! F_153 ( V_189 , V_211 -> V_189 ) )
break;
F_154 ( V_188 , V_211 -> V_189 ) ;
F_145 ( & V_211 -> V_217 ) ;
F_144 ( V_211 ) ;
F_27 ( V_211 ) ;
}
while ( ! F_128 ( & V_188 -> V_190 ) ) {
struct V_20 * V_21 ;
V_21 = F_147 ( & V_188 -> V_190 ,
struct V_20 ,
V_191 ) ;
if ( ! F_153 ( V_189 , V_21 -> V_192 ) )
break;
if ( V_21 -> V_50 . V_131 != 0 )
F_126 ( V_21 ) ;
else
F_127 ( V_21 ) ;
}
if ( F_155 ( V_188 -> V_234 &&
F_153 ( V_189 , V_188 -> V_234 ) ) ) {
V_188 -> V_235 ( V_188 ) ;
V_188 -> V_234 = 0 ;
}
F_10 ( F_11 ( V_188 -> V_8 ) ) ;
}
void
F_156 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_101 ;
if ( ! F_128 ( & V_2 -> V_4 . V_236 ) ) {
struct V_20 * V_21 , * V_208 ;
F_133 (obj, next,
&dev_priv->mm.deferred_free_list,
mm_list)
F_157 ( V_21 ) ;
}
for ( V_101 = 0 ; V_101 < V_231 ; V_101 ++ )
F_151 ( & V_2 -> V_188 [ V_101 ] ) ;
}
static void
F_158 ( struct V_237 * V_238 )
{
T_2 * V_2 ;
struct V_7 * V_8 ;
bool V_239 ;
int V_101 ;
V_2 = F_159 ( V_238 , T_2 ,
V_4 . V_228 . V_238 ) ;
V_8 = V_2 -> V_8 ;
if ( ! F_160 ( & V_8 -> V_19 ) ) {
F_143 ( V_2 -> V_227 , & V_2 -> V_4 . V_228 , V_229 ) ;
return;
}
F_156 ( V_8 ) ;
V_239 = true ;
for ( V_101 = 0 ; V_101 < V_231 ; V_101 ++ ) {
struct V_187 * V_188 = & V_2 -> V_188 [ V_101 ] ;
if ( ! F_128 ( & V_188 -> V_205 ) ) {
struct V_210 * V_211 ;
int V_14 ;
V_14 = F_161 ( V_188 ,
0 , V_136 ) ;
V_211 = F_162 ( sizeof( * V_211 ) , V_240 ) ;
if ( V_14 || V_211 == NULL ||
F_136 ( V_188 , NULL , V_211 ) )
F_27 ( V_211 ) ;
}
V_239 &= F_128 ( & V_188 -> V_216 ) ;
}
if ( ! V_2 -> V_4 . V_223 && ! V_239 )
F_143 ( V_2 -> V_227 , & V_2 -> V_4 . V_228 , V_229 ) ;
F_19 ( & V_8 -> V_19 ) ;
}
int
F_163 ( struct V_187 * V_188 ,
T_4 V_189 )
{
T_2 * V_2 = V_188 -> V_8 -> V_9 ;
T_5 V_241 ;
int V_14 = 0 ;
F_116 ( V_189 == 0 ) ;
if ( F_4 ( & V_2 -> V_4 . V_15 ) ) {
struct V_10 * V_11 = & V_2 -> V_12 ;
bool V_242 ;
unsigned long V_13 ;
F_6 ( & V_11 -> V_16 . V_17 , V_13 ) ;
V_242 = V_11 -> V_18 > 0 ;
F_7 ( & V_11 -> V_16 . V_17 , V_13 ) ;
return V_242 ? - V_162 : - V_163 ;
}
if ( V_189 == V_188 -> V_222 ) {
struct V_210 * V_211 ;
V_211 = F_162 ( sizeof( * V_211 ) , V_240 ) ;
if ( V_211 == NULL )
return - V_49 ;
V_14 = F_136 ( V_188 , NULL , V_211 ) ;
if ( V_14 ) {
F_27 ( V_211 ) ;
return V_14 ;
}
V_189 = V_211 -> V_189 ;
}
if ( ! F_153 ( V_188 -> V_232 ( V_188 ) , V_189 ) ) {
if ( F_164 ( V_188 -> V_8 ) )
V_241 = F_165 ( V_243 ) | F_165 ( V_244 ) ;
else
V_241 = F_165 ( V_245 ) ;
if ( ! V_241 ) {
F_112 ( L_2
L_3 ) ;
V_188 -> V_8 -> V_41 -> V_246 ( V_188 -> V_8 ) ;
V_188 -> V_8 -> V_41 -> V_247 ( V_188 -> V_8 ) ;
}
F_166 ( V_188 , V_189 ) ;
V_188 -> V_248 = V_189 ;
if ( V_188 -> V_249 ( V_188 ) ) {
if ( V_2 -> V_4 . V_250 )
V_14 = F_167 ( V_188 -> V_251 ,
F_153 ( V_188 -> V_232 ( V_188 ) , V_189 )
|| F_4 ( & V_2 -> V_4 . V_15 ) ) ;
else
F_168 ( V_188 -> V_251 ,
F_153 ( V_188 -> V_232 ( V_188 ) , V_189 )
|| F_4 ( & V_2 -> V_4 . V_15 ) ) ;
V_188 -> V_235 ( V_188 ) ;
} else if ( F_169 ( F_153 ( V_188 -> V_232 ( V_188 ) ,
V_189 ) ||
F_4 ( & V_2 -> V_4 . V_15 ) , 3000 ) )
V_14 = - V_252 ;
V_188 -> V_248 = 0 ;
F_170 ( V_188 , V_189 ) ;
}
if ( F_4 ( & V_2 -> V_4 . V_15 ) )
V_14 = - V_163 ;
if ( V_14 && V_14 != - V_164 )
F_112 ( L_4 ,
V_253 , V_14 , V_189 , V_188 -> V_232 ( V_188 ) ,
V_2 -> V_254 ) ;
if ( V_14 == 0 )
F_151 ( V_188 ) ;
return V_14 ;
}
int
F_171 ( struct V_20 * V_21 )
{
int V_14 ;
F_116 ( ( V_21 -> V_50 . V_131 & V_136 ) != 0 ) ;
if ( V_21 -> V_23 ) {
V_14 = F_163 ( V_21 -> V_188 , V_21 -> V_192 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static void F_172 ( struct V_20 * V_21 )
{
T_5 V_209 , V_255 ;
F_173 () ;
F_104 ( V_21 ) ;
if ( ( V_21 -> V_50 . V_135 & V_137 ) == 0 )
return;
V_255 = V_21 -> V_50 . V_135 ;
V_209 = V_21 -> V_50 . V_131 ;
V_21 -> V_50 . V_135 &= ~ V_137 ;
V_21 -> V_50 . V_131 &= ~ V_137 ;
F_135 ( V_21 ,
V_255 ,
V_209 ) ;
}
int
F_98 ( struct V_20 * V_21 )
{
int V_14 = 0 ;
if ( V_21 -> V_22 == NULL )
return 0 ;
if ( V_21 -> V_24 != 0 ) {
F_112 ( L_5 ) ;
return - V_38 ;
}
V_14 = F_174 ( V_21 ) ;
if ( V_14 == - V_164 )
return V_14 ;
F_172 ( V_21 ) ;
if ( V_14 == 0 )
V_14 = F_81 ( V_21 , 1 ) ;
if ( V_14 == - V_164 )
return V_14 ;
if ( V_14 ) {
F_175 ( V_21 ) ;
V_21 -> V_50 . V_135 = V_21 -> V_50 . V_131 = V_132 ;
}
V_14 = F_76 ( V_21 ) ;
if ( V_14 == - V_164 )
return V_14 ;
F_176 ( V_21 ) ;
F_177 ( V_21 ) ;
F_120 ( V_21 ) ;
F_125 ( & V_21 -> V_256 ) ;
F_125 ( & V_21 -> V_158 ) ;
V_21 -> V_157 = true ;
F_178 ( V_21 -> V_22 ) ;
V_21 -> V_22 = NULL ;
V_21 -> V_119 = 0 ;
if ( F_131 ( V_21 ) )
F_129 ( V_21 ) ;
return V_14 ;
}
int
F_161 ( struct V_187 * V_188 ,
T_4 V_257 ,
T_4 V_207 )
{
int V_14 ;
if ( ( ( V_257 | V_207 ) & V_136 ) == 0 )
return 0 ;
F_179 ( V_188 , V_257 , V_207 ) ;
V_14 = V_188 -> V_258 ( V_188 , V_257 , V_207 ) ;
if ( V_14 )
return V_14 ;
if ( V_207 & V_136 )
F_132 ( V_188 , V_207 ) ;
return 0 ;
}
static int F_180 ( struct V_187 * V_188 )
{
int V_14 ;
if ( F_128 ( & V_188 -> V_205 ) && F_128 ( & V_188 -> V_190 ) )
return 0 ;
if ( ! F_128 ( & V_188 -> V_205 ) ) {
V_14 = F_161 ( V_188 ,
V_136 , V_136 ) ;
if ( V_14 )
return V_14 ;
}
return F_163 ( V_188 , F_134 ( V_188 ) ) ;
}
int
F_181 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_14 , V_101 ;
for ( V_101 = 0 ; V_101 < V_231 ; V_101 ++ ) {
V_14 = F_180 ( & V_2 -> V_188 [ V_101 ] ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static int F_182 ( struct V_20 * V_21 ,
struct V_187 * V_259 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_3 = V_21 -> V_22 -> V_3 ;
int V_260 = V_21 -> V_196 ;
T_3 V_261 ;
V_261 = ( T_3 ) ( ( V_21 -> V_119 + V_3 - 4096 ) &
0xfffff000 ) << 32 ;
V_261 |= V_21 -> V_119 & 0xfffff000 ;
V_261 |= ( T_3 ) ( ( V_21 -> V_262 / 128 ) - 1 ) <<
V_263 ;
if ( V_21 -> V_59 == V_264 )
V_261 |= 1 << V_265 ;
V_261 |= V_266 ;
if ( V_259 ) {
int V_14 = F_183 ( V_259 , 6 ) ;
if ( V_14 )
return V_14 ;
F_184 ( V_259 , V_267 ) ;
F_184 ( V_259 , F_185 ( 2 ) ) ;
F_184 ( V_259 , V_268 + V_260 * 8 ) ;
F_184 ( V_259 , ( T_5 ) V_261 ) ;
F_184 ( V_259 , V_268 + V_260 * 8 + 4 ) ;
F_184 ( V_259 , ( T_5 ) ( V_261 >> 32 ) ) ;
F_186 ( V_259 ) ;
} else
F_187 ( V_268 + V_260 * 8 , V_261 ) ;
return 0 ;
}
static int F_188 ( struct V_20 * V_21 ,
struct V_187 * V_259 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_3 = V_21 -> V_22 -> V_3 ;
int V_260 = V_21 -> V_196 ;
T_3 V_261 ;
V_261 = ( T_3 ) ( ( V_21 -> V_119 + V_3 - 4096 ) &
0xfffff000 ) << 32 ;
V_261 |= V_21 -> V_119 & 0xfffff000 ;
V_261 |= ( ( V_21 -> V_262 / 128 ) - 1 ) << V_269 ;
if ( V_21 -> V_59 == V_264 )
V_261 |= 1 << V_265 ;
V_261 |= V_266 ;
if ( V_259 ) {
int V_14 = F_183 ( V_259 , 6 ) ;
if ( V_14 )
return V_14 ;
F_184 ( V_259 , V_267 ) ;
F_184 ( V_259 , F_185 ( 2 ) ) ;
F_184 ( V_259 , V_270 + V_260 * 8 ) ;
F_184 ( V_259 , ( T_5 ) V_261 ) ;
F_184 ( V_259 , V_270 + V_260 * 8 + 4 ) ;
F_184 ( V_259 , ( T_5 ) ( V_261 >> 32 ) ) ;
F_186 ( V_259 ) ;
} else
F_187 ( V_270 + V_260 * 8 , V_261 ) ;
return 0 ;
}
static int F_189 ( struct V_20 * V_21 ,
struct V_187 * V_259 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_3 = V_21 -> V_22 -> V_3 ;
T_5 V_196 , V_261 , V_271 ;
int V_272 ;
if ( F_190 ( ( V_21 -> V_119 & ~ V_273 ) ||
( V_3 & - V_3 ) != V_3 ||
( V_21 -> V_119 & ( V_3 - 1 ) ) ,
L_6 ,
V_21 -> V_119 , V_21 -> V_157 , V_3 ) )
return - V_38 ;
if ( V_21 -> V_59 == V_264 && F_191 ( V_8 ) )
V_272 = 128 ;
else
V_272 = 512 ;
V_271 = V_21 -> V_262 / V_272 ;
V_271 = F_192 ( V_271 ) - 1 ;
V_261 = V_21 -> V_119 ;
if ( V_21 -> V_59 == V_264 )
V_261 |= 1 << V_274 ;
V_261 |= F_193 ( V_3 ) ;
V_261 |= V_271 << V_275 ;
V_261 |= V_276 ;
V_196 = V_21 -> V_196 ;
if ( V_196 < 8 )
V_196 = V_277 + V_196 * 4 ;
else
V_196 = V_278 + ( V_196 - 8 ) * 4 ;
if ( V_259 ) {
int V_14 = F_183 ( V_259 , 4 ) ;
if ( V_14 )
return V_14 ;
F_184 ( V_259 , V_267 ) ;
F_184 ( V_259 , F_185 ( 1 ) ) ;
F_184 ( V_259 , V_196 ) ;
F_184 ( V_259 , V_261 ) ;
F_186 ( V_259 ) ;
} else
F_194 ( V_196 , V_261 ) ;
return 0 ;
}
static int F_195 ( struct V_20 * V_21 ,
struct V_187 * V_259 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_3 = V_21 -> V_22 -> V_3 ;
int V_260 = V_21 -> V_196 ;
T_4 V_261 ;
T_4 V_271 ;
if ( F_190 ( ( V_21 -> V_119 & ~ V_279 ) ||
( V_3 & - V_3 ) != V_3 ||
( V_21 -> V_119 & ( V_3 - 1 ) ) ,
L_7 ,
V_21 -> V_119 , V_3 ) )
return - V_38 ;
V_271 = V_21 -> V_262 / 128 ;
V_271 = F_192 ( V_271 ) - 1 ;
V_261 = V_21 -> V_119 ;
if ( V_21 -> V_59 == V_264 )
V_261 |= 1 << V_274 ;
V_261 |= F_196 ( V_3 ) ;
V_261 |= V_271 << V_275 ;
V_261 |= V_276 ;
if ( V_259 ) {
int V_14 = F_183 ( V_259 , 4 ) ;
if ( V_14 )
return V_14 ;
F_184 ( V_259 , V_267 ) ;
F_184 ( V_259 , F_185 ( 1 ) ) ;
F_184 ( V_259 , V_277 + V_260 * 4 ) ;
F_184 ( V_259 , V_261 ) ;
F_186 ( V_259 ) ;
} else
F_194 ( V_277 + V_260 * 4 , V_261 ) ;
return 0 ;
}
static bool F_197 ( struct V_187 * V_188 , T_5 V_189 )
{
return F_153 ( V_188 -> V_232 ( V_188 ) , V_189 ) ;
}
static int
F_198 ( struct V_20 * V_21 ,
struct V_187 * V_259 )
{
int V_14 ;
if ( V_21 -> V_193 ) {
if ( V_21 -> V_50 . V_131 & V_136 ) {
V_14 = F_161 ( V_21 -> V_199 ,
0 , V_21 -> V_50 . V_131 ) ;
if ( V_14 )
return V_14 ;
}
V_21 -> V_193 = false ;
}
if ( V_21 -> V_198 && V_259 != V_21 -> V_199 ) {
if ( ! F_197 ( V_21 -> V_199 ,
V_21 -> V_198 ) ) {
V_14 = F_163 ( V_21 -> V_199 ,
V_21 -> V_198 ) ;
if ( V_14 )
return V_14 ;
}
V_21 -> V_198 = 0 ;
V_21 -> V_199 = NULL ;
}
if ( V_21 -> V_50 . V_135 & V_137 )
F_173 () ;
return 0 ;
}
int
F_76 ( struct V_20 * V_21 )
{
int V_14 ;
if ( V_21 -> V_59 )
F_104 ( V_21 ) ;
V_14 = F_198 ( V_21 , NULL ) ;
if ( V_14 )
return V_14 ;
if ( V_21 -> V_196 != V_197 ) {
struct V_1 * V_2 = V_21 -> V_50 . V_8 -> V_9 ;
F_149 ( V_21 -> V_50 . V_8 ,
& V_2 -> V_200 [ V_21 -> V_196 ] ) ;
V_21 -> V_196 = V_197 ;
}
return 0 ;
}
static struct V_194 *
F_199 ( struct V_7 * V_8 ,
struct V_187 * V_259 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_194 * V_195 , * V_280 , * V_281 ;
int V_101 ;
V_281 = NULL ;
for ( V_101 = V_2 -> V_282 ; V_101 < V_2 -> V_230 ; V_101 ++ ) {
V_195 = & V_2 -> V_200 [ V_101 ] ;
if ( ! V_195 -> V_21 )
return V_195 ;
if ( ! V_195 -> V_21 -> V_24 )
V_281 = V_195 ;
}
if ( V_281 == NULL )
return NULL ;
V_281 = V_280 = NULL ;
F_21 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_195 -> V_21 -> V_24 )
continue;
if ( V_280 == NULL )
V_280 = V_195 ;
if ( ! V_259 ||
! V_195 -> V_21 -> V_199 ||
V_195 -> V_21 -> V_199 == V_259 ) {
V_281 = V_195 ;
break;
}
}
if ( V_281 == NULL )
V_281 = V_280 ;
return V_281 ;
}
int
F_100 ( struct V_20 * V_21 ,
struct V_187 * V_259 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_194 * V_195 ;
int V_14 ;
V_259 = NULL ;
if ( V_21 -> V_196 != V_197 ) {
V_195 = & V_2 -> V_200 [ V_21 -> V_196 ] ;
F_101 ( & V_195 -> V_201 , & V_2 -> V_4 . V_202 ) ;
if ( V_21 -> V_283 ) {
V_14 = F_198 ( V_21 , V_259 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_21 -> V_193 && ! V_21 -> V_198 )
V_259 = NULL ;
if ( V_259 ) {
V_195 -> V_284 =
F_134 ( V_259 ) ;
V_21 -> V_198 = V_195 -> V_284 ;
V_21 -> V_199 = V_259 ;
}
goto V_285;
}
if ( ! V_259 ) {
if ( V_195 -> V_284 ) {
if ( ! F_197 ( V_21 -> V_199 ,
V_195 -> V_284 ) ) {
V_14 = F_163 ( V_21 -> V_199 ,
V_195 -> V_284 ) ;
if ( V_14 )
return V_14 ;
}
V_195 -> V_284 = 0 ;
}
} else if ( V_21 -> V_199 &&
V_21 -> V_199 != V_259 ) {
V_14 = F_198 ( V_21 , V_259 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
V_195 = F_199 ( V_8 , V_259 ) ;
if ( V_195 == NULL )
return - V_286 ;
V_14 = F_198 ( V_21 , V_259 ) ;
if ( V_14 )
return V_14 ;
if ( V_195 -> V_21 ) {
struct V_20 * V_287 = V_195 -> V_21 ;
F_123 ( & V_287 -> V_50 ) ;
if ( V_287 -> V_59 )
F_104 ( V_287 ) ;
V_14 = F_198 ( V_287 , V_259 ) ;
if ( V_14 ) {
F_28 ( & V_287 -> V_50 ) ;
return V_14 ;
}
if ( V_287 -> V_198 == 0 && V_21 -> V_198 == 0 )
V_259 = NULL ;
V_287 -> V_196 = V_197 ;
V_287 -> V_199 = V_259 ;
V_287 -> V_198 =
V_259 ? F_134 ( V_259 ) : 0 ;
F_28 ( & V_287 -> V_50 ) ;
} else if ( V_21 -> V_198 == 0 )
V_259 = NULL ;
V_195 -> V_21 = V_21 ;
F_101 ( & V_195 -> V_201 , & V_2 -> V_4 . V_202 ) ;
V_21 -> V_196 = V_195 - V_2 -> V_200 ;
V_21 -> V_199 = V_259 ;
V_195 -> V_284 =
V_259 ? F_134 ( V_259 ) : 0 ;
V_21 -> V_198 = V_195 -> V_284 ;
V_285:
V_21 -> V_283 = false ;
switch ( F_107 ( V_8 ) -> V_174 ) {
case 7 :
case 6 :
V_14 = F_182 ( V_21 , V_259 ) ;
break;
case 5 :
case 4 :
V_14 = F_188 ( V_21 , V_259 ) ;
break;
case 3 :
V_14 = F_189 ( V_21 , V_259 ) ;
break;
case 2 :
V_14 = F_195 ( V_21 , V_259 ) ;
break;
}
return V_14 ;
}
static void
F_149 ( struct V_7 * V_8 ,
struct V_194 * V_195 )
{
T_2 * V_2 = V_8 -> V_9 ;
T_4 V_196 = V_195 - V_2 -> V_200 ;
switch ( F_107 ( V_8 ) -> V_174 ) {
case 7 :
case 6 :
F_187 ( V_268 + V_196 * 8 , 0 ) ;
break;
case 5 :
case 4 :
F_187 ( V_270 + V_196 * 8 , 0 ) ;
break;
case 3 :
if ( V_196 >= 8 )
V_196 = V_278 + ( V_196 - 8 ) * 4 ;
else
case 2 :
V_196 = V_277 + V_196 * 4 ;
F_194 ( V_196 , 0 ) ;
break;
}
F_125 ( & V_195 -> V_201 ) ;
V_195 -> V_21 = NULL ;
V_195 -> V_284 = 0 ;
}
static int
F_99 ( struct V_20 * V_21 ,
unsigned V_288 ,
bool V_157 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
struct V_289 * V_290 ;
T_11 V_180 = V_291 | V_292 ;
T_5 V_3 , V_293 , V_294 , V_295 ;
bool V_296 , V_297 ;
int V_14 ;
if ( V_21 -> V_175 != V_176 ) {
F_112 ( L_8 ) ;
return - V_38 ;
}
V_293 = F_106 ( V_8 ,
V_21 -> V_50 . V_3 ,
V_21 -> V_59 ) ;
V_294 = F_108 ( V_8 ,
V_21 -> V_50 . V_3 ,
V_21 -> V_59 ) ;
V_295 =
F_109 ( V_8 ,
V_21 -> V_50 . V_3 ,
V_21 -> V_59 ) ;
if ( V_288 == 0 )
V_288 = V_157 ? V_294 :
V_295 ;
if ( V_157 && V_288 & ( V_294 - 1 ) ) {
F_112 ( L_9 , V_288 ) ;
return - V_38 ;
}
V_3 = V_157 ? V_293 : V_21 -> V_50 . V_3 ;
if ( V_21 -> V_50 . V_3 >
( V_157 ? V_2 -> V_4 . V_29 : V_2 -> V_4 . V_31 ) ) {
F_112 ( L_10 ) ;
return - V_142 ;
}
V_298:
if ( V_157 )
V_290 =
F_200 ( & V_2 -> V_4 . V_22 ,
V_3 , V_288 , 0 ,
V_2 -> V_4 . V_29 ,
0 ) ;
else
V_290 = F_201 ( & V_2 -> V_4 . V_22 ,
V_3 , V_288 , 0 ) ;
if ( V_290 != NULL ) {
if ( V_157 )
V_21 -> V_22 =
F_202 ( V_290 ,
V_3 , V_288 , 0 ,
V_2 -> V_4 . V_29 ,
0 ) ;
else
V_21 -> V_22 =
F_203 ( V_290 , V_3 , V_288 ) ;
}
if ( V_21 -> V_22 == NULL ) {
V_14 = F_204 ( V_8 , V_3 , V_288 ,
V_157 ) ;
if ( V_14 )
return V_14 ;
goto V_298;
}
V_14 = F_115 ( V_21 , V_180 ) ;
if ( V_14 ) {
F_178 ( V_21 -> V_22 ) ;
V_21 -> V_22 = NULL ;
if ( V_14 == - V_49 ) {
V_14 = F_205 ( V_8 , false ) ;
if ( V_14 ) {
if ( V_180 ) {
V_180 = 0 ;
goto V_298;
}
return - V_49 ;
}
goto V_298;
}
return V_14 ;
}
V_14 = F_206 ( V_21 ) ;
if ( V_14 ) {
F_120 ( V_21 ) ;
F_178 ( V_21 -> V_22 ) ;
V_21 -> V_22 = NULL ;
if ( F_205 ( V_8 , false ) )
return V_14 ;
goto V_298;
}
F_138 ( & V_21 -> V_256 , & V_2 -> V_4 . V_256 ) ;
F_138 ( & V_21 -> V_158 , & V_2 -> V_4 . V_159 ) ;
F_116 ( V_21 -> V_50 . V_135 & V_136 ) ;
F_116 ( V_21 -> V_50 . V_131 & V_136 ) ;
V_21 -> V_119 = V_21 -> V_22 -> V_25 ;
V_297 =
V_21 -> V_22 -> V_3 == V_293 &&
( V_21 -> V_22 -> V_25 & ( V_294 - 1 ) ) == 0 ;
V_296 =
V_21 -> V_119 + V_21 -> V_50 . V_3 <= V_2 -> V_4 . V_29 ;
V_21 -> V_157 = V_296 && V_297 ;
F_207 ( V_21 , V_157 ) ;
return 0 ;
}
void
F_175 ( struct V_20 * V_21 )
{
if ( V_21 -> V_183 == NULL )
return;
if ( V_21 -> V_299 != V_300 )
return;
F_208 ( V_21 ) ;
F_209 ( V_21 -> V_183 , V_21 -> V_50 . V_3 / V_33 ) ;
}
static int
F_210 ( struct V_20 * V_21 )
{
if ( ( V_21 -> V_50 . V_131 & V_136 ) == 0 )
return 0 ;
return F_161 ( V_21 -> V_188 , 0 , V_21 -> V_50 . V_131 ) ;
}
static void
F_211 ( struct V_20 * V_21 )
{
T_4 V_209 ;
if ( V_21 -> V_50 . V_131 != V_137 )
return;
F_212 () ;
V_209 = V_21 -> V_50 . V_131 ;
V_21 -> V_50 . V_131 = 0 ;
F_135 ( V_21 ,
V_21 -> V_50 . V_135 ,
V_209 ) ;
}
static void
F_90 ( struct V_20 * V_21 )
{
T_4 V_209 ;
if ( V_21 -> V_50 . V_131 != V_132 )
return;
F_175 ( V_21 ) ;
F_213 () ;
V_209 = V_21 -> V_50 . V_131 ;
V_21 -> V_50 . V_131 = 0 ;
F_135 ( V_21 ,
V_21 -> V_50 . V_135 ,
V_209 ) ;
}
int
F_75 ( struct V_20 * V_21 , bool V_153 )
{
T_4 V_209 , V_255 ;
int V_14 ;
if ( V_21 -> V_22 == NULL )
return - V_38 ;
if ( V_21 -> V_50 . V_131 == V_137 )
return 0 ;
V_14 = F_210 ( V_21 ) ;
if ( V_14 )
return V_14 ;
if ( V_21 -> V_206 || V_153 ) {
V_14 = F_171 ( V_21 ) ;
if ( V_14 )
return V_14 ;
}
F_90 ( V_21 ) ;
V_209 = V_21 -> V_50 . V_131 ;
V_255 = V_21 -> V_50 . V_135 ;
F_116 ( ( V_21 -> V_50 . V_131 & ~ V_137 ) != 0 ) ;
V_21 -> V_50 . V_135 |= V_137 ;
if ( V_153 ) {
V_21 -> V_50 . V_135 = V_137 ;
V_21 -> V_50 . V_131 = V_137 ;
V_21 -> V_128 = 1 ;
}
F_135 ( V_21 ,
V_255 ,
V_209 ) ;
return 0 ;
}
int F_214 ( struct V_20 * V_21 ,
enum V_301 V_299 )
{
int V_14 ;
if ( V_21 -> V_299 == V_299 )
return 0 ;
if ( V_21 -> V_24 ) {
F_215 ( L_11 ) ;
return - V_252 ;
}
if ( V_21 -> V_22 ) {
V_14 = F_174 ( V_21 ) ;
if ( V_14 )
return V_14 ;
F_172 ( V_21 ) ;
if ( F_107 ( V_21 -> V_50 . V_8 ) -> V_174 < 6 ) {
V_14 = F_76 ( V_21 ) ;
if ( V_14 )
return V_14 ;
}
F_216 ( V_21 , V_299 ) ;
}
if ( V_299 == V_300 ) {
T_5 V_255 , V_209 ;
F_10 ( V_21 -> V_50 . V_131 & ~ V_132 ) ;
F_10 ( V_21 -> V_50 . V_135 & ~ V_132 ) ;
V_255 = V_21 -> V_50 . V_135 ;
V_209 = V_21 -> V_50 . V_131 ;
V_21 -> V_50 . V_135 = V_132 ;
V_21 -> V_50 . V_131 = V_132 ;
F_135 ( V_21 ,
V_255 ,
V_209 ) ;
}
V_21 -> V_299 = V_299 ;
return 0 ;
}
int
F_217 ( struct V_20 * V_21 ,
T_5 V_288 ,
struct V_187 * V_259 )
{
T_5 V_255 , V_209 ;
int V_14 ;
V_14 = F_210 ( V_21 ) ;
if ( V_14 )
return V_14 ;
if ( V_259 != V_21 -> V_188 ) {
V_14 = F_171 ( V_21 ) ;
if ( V_14 == - V_164 )
return V_14 ;
}
V_14 = F_214 ( V_21 , V_300 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_86 ( V_21 , V_288 , true ) ;
if ( V_14 )
return V_14 ;
F_90 ( V_21 ) ;
V_209 = V_21 -> V_50 . V_131 ;
V_255 = V_21 -> V_50 . V_135 ;
F_116 ( ( V_21 -> V_50 . V_131 & ~ V_137 ) != 0 ) ;
V_21 -> V_50 . V_135 |= V_137 ;
F_135 ( V_21 ,
V_255 ,
V_209 ) ;
return 0 ;
}
int
F_174 ( struct V_20 * V_21 )
{
int V_14 ;
if ( ( V_21 -> V_50 . V_135 & V_136 ) == 0 )
return 0 ;
if ( V_21 -> V_50 . V_131 & V_136 ) {
V_14 = F_161 ( V_21 -> V_188 , 0 , V_21 -> V_50 . V_131 ) ;
if ( V_14 )
return V_14 ;
}
V_21 -> V_50 . V_135 &= ~ V_136 ;
return F_171 ( V_21 ) ;
}
static int
F_81 ( struct V_20 * V_21 , bool V_153 )
{
T_4 V_209 , V_255 ;
int V_14 ;
if ( V_21 -> V_50 . V_131 == V_132 )
return 0 ;
V_14 = F_210 ( V_21 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_171 ( V_21 ) ;
if ( V_14 )
return V_14 ;
F_211 ( V_21 ) ;
F_218 ( V_21 ) ;
V_209 = V_21 -> V_50 . V_131 ;
V_255 = V_21 -> V_50 . V_135 ;
if ( ( V_21 -> V_50 . V_135 & V_132 ) == 0 ) {
F_175 ( V_21 ) ;
V_21 -> V_50 . V_135 |= V_132 ;
}
F_116 ( ( V_21 -> V_50 . V_131 & ~ V_132 ) != 0 ) ;
if ( V_153 ) {
V_21 -> V_50 . V_135 = V_132 ;
V_21 -> V_50 . V_131 = V_132 ;
}
F_135 ( V_21 ,
V_255 ,
V_209 ) ;
return 0 ;
}
static void
F_218 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_302 )
return;
if ( V_21 -> V_50 . V_135 & V_132 ) {
int V_101 ;
for ( V_101 = 0 ; V_101 <= ( V_21 -> V_50 . V_3 - 1 ) / V_33 ; V_101 ++ ) {
if ( V_21 -> V_302 [ V_101 ] )
continue;
F_209 ( V_21 -> V_183 + V_101 , 1 ) ;
}
}
F_27 ( V_21 -> V_302 ) ;
V_21 -> V_302 = NULL ;
}
static int
F_56 ( struct V_20 * V_21 ,
T_3 V_88 , T_3 V_3 )
{
T_4 V_255 ;
int V_101 , V_14 ;
if ( V_88 == 0 && V_3 == V_21 -> V_50 . V_3 )
return F_81 ( V_21 , 0 ) ;
V_14 = F_210 ( V_21 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_171 ( V_21 ) ;
if ( V_14 )
return V_14 ;
F_211 ( V_21 ) ;
if ( V_21 -> V_302 == NULL &&
( V_21 -> V_50 . V_135 & V_132 ) != 0 )
return 0 ;
if ( V_21 -> V_302 == NULL ) {
V_21 -> V_302 = F_162 ( V_21 -> V_50 . V_3 / V_33 ,
V_240 ) ;
if ( V_21 -> V_302 == NULL )
return - V_49 ;
} else if ( ( V_21 -> V_50 . V_135 & V_132 ) == 0 )
memset ( V_21 -> V_302 , 0 , V_21 -> V_50 . V_3 / V_33 ) ;
for ( V_101 = V_88 / V_33 ; V_101 <= ( V_88 + V_3 - 1 ) / V_33 ;
V_101 ++ ) {
if ( V_21 -> V_302 [ V_101 ] )
continue;
F_209 ( V_21 -> V_183 + V_101 , 1 ) ;
V_21 -> V_302 [ V_101 ] = 1 ;
}
F_116 ( ( V_21 -> V_50 . V_131 & ~ V_132 ) != 0 ) ;
V_255 = V_21 -> V_50 . V_135 ;
V_21 -> V_50 . V_135 |= V_132 ;
F_135 ( V_21 ,
V_255 ,
V_21 -> V_50 . V_131 ) ;
return 0 ;
}
static int
F_219 ( struct V_7 * V_8 , struct V_35 * V_36 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_218 * V_219 = V_36 -> V_220 ;
unsigned long V_303 = V_215 - F_142 ( 20 ) ;
struct V_210 * V_211 ;
struct V_187 * V_188 = NULL ;
T_5 V_189 = 0 ;
int V_14 ;
if ( F_4 ( & V_2 -> V_4 . V_15 ) )
return - V_162 ;
F_139 ( & V_219 -> V_4 . V_17 ) ;
F_21 (request, &file_priv->mm.request_list, client_list) {
if ( F_220 ( V_211 -> V_214 , V_303 ) )
break;
V_188 = V_211 -> V_188 ;
V_189 = V_211 -> V_189 ;
}
F_140 ( & V_219 -> V_4 . V_17 ) ;
if ( V_189 == 0 )
return 0 ;
V_14 = 0 ;
if ( ! F_153 ( V_188 -> V_232 ( V_188 ) , V_189 ) ) {
if ( V_188 -> V_249 ( V_188 ) ) {
V_14 = F_167 ( V_188 -> V_251 ,
F_153 ( V_188 -> V_232 ( V_188 ) , V_189 )
|| F_4 ( & V_2 -> V_4 . V_15 ) ) ;
V_188 -> V_235 ( V_188 ) ;
if ( V_14 == 0 && F_4 ( & V_2 -> V_4 . V_15 ) )
V_14 = - V_162 ;
} else if ( F_169 ( F_153 ( V_188 -> V_232 ( V_188 ) ,
V_189 ) ||
F_4 ( & V_2 -> V_4 . V_15 ) , 3000 ) ) {
V_14 = - V_252 ;
}
}
if ( V_14 == 0 )
F_143 ( V_2 -> V_227 , & V_2 -> V_4 . V_228 , 0 ) ;
return V_14 ;
}
int
F_86 ( struct V_20 * V_21 ,
T_4 V_288 ,
bool V_157 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
int V_14 ;
F_116 ( V_21 -> V_24 == V_304 ) ;
F_10 ( F_11 ( V_8 ) ) ;
if ( V_21 -> V_22 != NULL ) {
if ( ( V_288 && V_21 -> V_119 & ( V_288 - 1 ) ) ||
( V_157 && ! V_21 -> V_157 ) ) {
F_190 ( V_21 -> V_24 ,
L_12
L_13
L_14 ,
V_21 -> V_119 , V_288 ,
V_157 ,
V_21 -> V_157 ) ;
V_14 = F_98 ( V_21 ) ;
if ( V_14 )
return V_14 ;
}
}
if ( V_21 -> V_22 == NULL ) {
V_14 = F_99 ( V_21 , V_288 ,
V_157 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_21 -> V_24 ++ == 0 ) {
if ( ! V_21 -> V_23 )
F_101 ( & V_21 -> V_158 ,
& V_2 -> V_4 . V_204 ) ;
}
V_21 -> V_305 |= V_157 ;
F_10 ( F_11 ( V_8 ) ) ;
return 0 ;
}
void
F_87 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
F_10 ( F_11 ( V_8 ) ) ;
F_116 ( V_21 -> V_24 == 0 ) ;
F_116 ( V_21 -> V_22 == NULL ) ;
if ( -- V_21 -> V_24 == 0 ) {
if ( ! V_21 -> V_23 )
F_101 ( & V_21 -> V_158 ,
& V_2 -> V_4 . V_159 ) ;
V_21 -> V_305 = false ;
}
F_10 ( F_11 ( V_8 ) ) ;
}
int
F_221 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_306 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_62 ( F_63 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_112 ;
goto V_113;
}
if ( V_21 -> V_175 != V_176 ) {
F_112 ( L_15 ) ;
V_14 = - V_38 ;
goto V_110;
}
if ( V_21 -> V_307 != NULL && V_21 -> V_307 != V_36 ) {
F_112 ( L_16 ,
args -> V_48 ) ;
V_14 = - V_38 ;
goto V_110;
}
V_21 -> V_308 ++ ;
V_21 -> V_307 = V_36 ;
if ( V_21 -> V_308 == 1 ) {
V_14 = F_86 ( V_21 , args -> V_288 , true ) ;
if ( V_14 )
goto V_110;
}
F_90 ( V_21 ) ;
args -> V_88 = V_21 -> V_119 ;
V_110:
F_28 ( & V_21 -> V_50 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_222 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_306 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_62 ( F_63 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_112 ;
goto V_113;
}
if ( V_21 -> V_307 != V_36 ) {
F_112 ( L_17 ,
args -> V_48 ) ;
V_14 = - V_38 ;
goto V_110;
}
V_21 -> V_308 -- ;
if ( V_21 -> V_308 == 0 ) {
V_21 -> V_307 = NULL ;
F_87 ( V_21 ) ;
}
V_110:
F_28 ( & V_21 -> V_50 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_223 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_309 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_62 ( F_63 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_112 ;
goto V_113;
}
args -> V_310 = V_21 -> V_23 ;
if ( args -> V_310 ) {
if ( V_21 -> V_50 . V_131 & V_136 ) {
V_14 = F_161 ( V_21 -> V_188 ,
0 , V_21 -> V_50 . V_131 ) ;
} else if ( V_21 -> V_188 -> V_222 ==
V_21 -> V_192 ) {
struct V_210 * V_211 ;
V_211 = F_162 ( sizeof( * V_211 ) , V_240 ) ;
if ( V_211 ) {
V_14 = F_136 ( V_21 -> V_188 , NULL , V_211 ) ;
if ( V_14 )
F_27 ( V_211 ) ;
} else
V_14 = - V_49 ;
}
F_151 ( V_21 -> V_188 ) ;
args -> V_310 = V_21 -> V_23 ;
}
F_28 ( & V_21 -> V_50 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_224 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_219 )
{
return F_219 ( V_8 , V_219 ) ;
}
int
F_225 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_219 )
{
struct V_311 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 ;
switch ( args -> V_175 ) {
case V_186 :
case V_176 :
break;
default:
return - V_38 ;
}
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_62 ( F_63 ( V_8 , V_219 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_112 ;
goto V_113;
}
if ( V_21 -> V_24 ) {
V_14 = - V_38 ;
goto V_110;
}
if ( V_21 -> V_175 != V_185 )
V_21 -> V_175 = args -> V_175 ;
if ( F_131 ( V_21 ) &&
V_21 -> V_22 == NULL )
F_129 ( V_21 ) ;
args -> V_312 = V_21 -> V_175 != V_185 ;
V_110:
F_28 ( & V_21 -> V_50 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
struct V_20 * F_24 ( struct V_7 * V_8 ,
T_1 V_3 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_20 * V_21 ;
struct V_80 * V_81 ;
V_21 = F_162 ( sizeof( * V_21 ) , V_240 ) ;
if ( V_21 == NULL )
return NULL ;
if ( F_226 ( V_8 , & V_21 -> V_50 , V_3 ) != 0 ) {
F_27 ( V_21 ) ;
return NULL ;
}
V_81 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
F_227 ( V_81 , V_313 | V_314 ) ;
F_1 ( V_2 , V_3 ) ;
V_21 -> V_50 . V_131 = V_132 ;
V_21 -> V_50 . V_135 = V_132 ;
if ( F_228 ( V_8 ) || F_229 ( V_8 ) ) {
V_21 -> V_299 = V_315 ;
} else
V_21 -> V_299 = V_300 ;
V_21 -> V_50 . V_316 = NULL ;
V_21 -> V_196 = V_197 ;
F_230 ( & V_21 -> V_158 ) ;
F_230 ( & V_21 -> V_256 ) ;
F_230 ( & V_21 -> V_191 ) ;
F_230 ( & V_21 -> V_317 ) ;
F_230 ( & V_21 -> V_205 ) ;
V_21 -> V_175 = V_176 ;
V_21 -> V_157 = true ;
return V_21 ;
}
int F_231 ( struct V_140 * V_21 )
{
F_232 () ;
return 0 ;
}
static void F_157 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
int V_14 ;
V_14 = F_98 ( V_21 ) ;
if ( V_14 == - V_164 ) {
F_233 ( & V_21 -> V_158 ,
& V_2 -> V_4 . V_236 ) ;
return;
}
F_234 ( V_21 ) ;
if ( V_21 -> V_50 . V_170 . V_177 )
F_235 ( & V_21 -> V_50 ) ;
F_26 ( & V_21 -> V_50 ) ;
F_2 ( V_2 , V_21 -> V_50 . V_3 ) ;
F_27 ( V_21 -> V_302 ) ;
F_27 ( V_21 -> V_318 ) ;
F_27 ( V_21 ) ;
}
void F_236 ( struct V_140 * V_319 )
{
struct V_20 * V_21 = F_62 ( V_319 ) ;
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
while ( V_21 -> V_24 > 0 )
F_87 ( V_21 ) ;
if ( V_21 -> V_130 )
F_237 ( V_8 , V_21 ) ;
F_157 ( V_21 ) ;
}
int
F_238 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_14 ;
F_18 ( & V_8 -> V_19 ) ;
if ( V_2 -> V_4 . V_223 ) {
F_19 ( & V_8 -> V_19 ) ;
return 0 ;
}
V_14 = F_181 ( V_8 ) ;
if ( V_14 ) {
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
if ( ! F_239 ( V_8 , V_320 ) ) {
V_14 = F_240 ( V_8 , false ) ;
if ( V_14 ) {
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
}
F_148 ( V_8 ) ;
V_2 -> V_4 . V_223 = 1 ;
F_241 ( & V_2 -> V_225 ) ;
F_242 ( V_8 ) ;
F_243 ( V_8 ) ;
F_19 ( & V_8 -> V_19 ) ;
F_244 ( & V_2 -> V_4 . V_228 ) ;
return 0 ;
}
int
F_245 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_14 ;
V_14 = F_246 ( V_8 ) ;
if ( V_14 )
return V_14 ;
if ( F_247 ( V_8 ) ) {
V_14 = F_248 ( V_8 ) ;
if ( V_14 )
goto V_321;
}
if ( F_249 ( V_8 ) ) {
V_14 = F_250 ( V_8 ) ;
if ( V_14 )
goto V_322;
}
V_2 -> V_254 = 1 ;
return 0 ;
V_322:
F_251 ( & V_2 -> V_188 [ V_323 ] ) ;
V_321:
F_251 ( & V_2 -> V_188 [ V_324 ] ) ;
return V_14 ;
}
void
F_243 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_231 ; V_101 ++ )
F_251 ( & V_2 -> V_188 [ V_101 ] ) ;
}
int
F_252 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_219 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_14 , V_101 ;
if ( F_239 ( V_8 , V_320 ) )
return 0 ;
if ( F_4 ( & V_2 -> V_4 . V_15 ) ) {
F_112 ( L_18 ) ;
F_253 ( & V_2 -> V_4 . V_15 , 0 ) ;
}
F_18 ( & V_8 -> V_19 ) ;
V_2 -> V_4 . V_223 = 0 ;
V_14 = F_245 ( V_8 ) ;
if ( V_14 != 0 ) {
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
F_116 ( ! F_128 ( & V_2 -> V_4 . V_190 ) ) ;
F_116 ( ! F_128 ( & V_2 -> V_4 . V_203 ) ) ;
F_116 ( ! F_128 ( & V_2 -> V_4 . V_159 ) ) ;
for ( V_101 = 0 ; V_101 < V_231 ; V_101 ++ ) {
F_116 ( ! F_128 ( & V_2 -> V_188 [ V_101 ] . V_190 ) ) ;
F_116 ( ! F_128 ( & V_2 -> V_188 [ V_101 ] . V_216 ) ) ;
}
F_19 ( & V_8 -> V_19 ) ;
V_14 = F_254 ( V_8 ) ;
if ( V_14 )
goto V_325;
return 0 ;
V_325:
F_18 ( & V_8 -> V_19 ) ;
F_243 ( V_8 ) ;
V_2 -> V_4 . V_223 = 1 ;
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_255 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_219 )
{
if ( F_239 ( V_8 , V_320 ) )
return 0 ;
F_256 ( V_8 ) ;
return F_238 ( V_8 ) ;
}
void
F_257 ( struct V_7 * V_8 )
{
int V_14 ;
if ( F_239 ( V_8 , V_320 ) )
return;
V_14 = F_238 ( V_8 ) ;
if ( V_14 )
F_112 ( L_19 , V_14 ) ;
}
static void
F_258 ( struct V_187 * V_188 )
{
F_230 ( & V_188 -> V_190 ) ;
F_230 ( & V_188 -> V_216 ) ;
F_230 ( & V_188 -> V_205 ) ;
}
void
F_259 ( struct V_7 * V_8 )
{
int V_101 ;
T_2 * V_2 = V_8 -> V_9 ;
F_230 ( & V_2 -> V_4 . V_190 ) ;
F_230 ( & V_2 -> V_4 . V_203 ) ;
F_230 ( & V_2 -> V_4 . V_159 ) ;
F_230 ( & V_2 -> V_4 . V_204 ) ;
F_230 ( & V_2 -> V_4 . V_202 ) ;
F_230 ( & V_2 -> V_4 . V_236 ) ;
F_230 ( & V_2 -> V_4 . V_256 ) ;
for ( V_101 = 0 ; V_101 < V_231 ; V_101 ++ )
F_258 ( & V_2 -> V_188 [ V_101 ] ) ;
for ( V_101 = 0 ; V_101 < V_326 ; V_101 ++ )
F_230 ( & V_2 -> V_200 [ V_101 ] . V_201 ) ;
F_260 ( & V_2 -> V_4 . V_228 ,
F_158 ) ;
F_261 ( & V_2 -> V_12 ) ;
if ( F_262 ( V_8 ) ) {
T_5 V_327 = F_165 ( V_328 ) ;
if ( ! ( V_327 & V_329 ) ) {
V_327 = V_329 | ( V_329 << V_330 ) ;
F_194 ( V_328 , V_327 ) ;
}
}
V_2 -> V_331 = V_332 ;
if ( ! F_239 ( V_8 , V_320 ) )
V_2 -> V_282 = 3 ;
if ( F_107 ( V_8 ) -> V_174 >= 4 || F_263 ( V_8 ) || F_264 ( V_8 ) || F_110 ( V_8 ) )
V_2 -> V_230 = 16 ;
else
V_2 -> V_230 = 8 ;
for ( V_101 = 0 ; V_101 < V_2 -> V_230 ; V_101 ++ ) {
F_149 ( V_8 , & V_2 -> V_200 [ V_101 ] ) ;
}
F_265 ( V_8 ) ;
F_266 ( & V_2 -> V_333 ) ;
V_2 -> V_4 . V_250 = true ;
V_2 -> V_4 . V_334 . V_335 = V_336 ;
V_2 -> V_4 . V_334 . V_337 = V_338 ;
F_267 ( & V_2 -> V_4 . V_334 ) ;
}
static int F_268 ( struct V_7 * V_8 ,
int V_339 , int V_3 , int V_340 )
{
T_2 * V_2 = V_8 -> V_9 ;
struct V_341 * V_130 ;
int V_14 ;
if ( V_2 -> V_4 . V_342 [ V_339 - 1 ] || ! V_3 )
return 0 ;
V_130 = F_162 ( sizeof( struct V_341 ) , V_240 ) ;
if ( ! V_130 )
return - V_49 ;
V_130 -> V_339 = V_339 ;
V_130 -> V_48 = F_269 ( V_8 , V_3 , V_340 ) ;
if ( ! V_130 -> V_48 ) {
V_14 = - V_49 ;
goto V_343;
}
#ifdef F_270
F_271 ( ( unsigned long ) V_130 -> V_48 -> V_94 , V_130 -> V_48 -> V_3 / V_33 ) ;
#endif
V_2 -> V_4 . V_342 [ V_339 - 1 ] = V_130 ;
return 0 ;
V_343:
F_27 ( V_130 ) ;
return V_14 ;
}
static void F_272 ( struct V_7 * V_8 , int V_339 )
{
T_2 * V_2 = V_8 -> V_9 ;
struct V_341 * V_130 ;
if ( ! V_2 -> V_4 . V_342 [ V_339 - 1 ] )
return;
V_130 = V_2 -> V_4 . V_342 [ V_339 - 1 ] ;
if ( V_130 -> V_344 ) {
F_237 ( V_8 , V_130 -> V_344 ) ;
}
#ifdef F_270
F_273 ( ( unsigned long ) V_130 -> V_48 -> V_94 , V_130 -> V_48 -> V_3 / V_33 ) ;
#endif
F_274 ( V_8 , V_130 -> V_48 ) ;
F_27 ( V_130 ) ;
V_2 -> V_4 . V_342 [ V_339 - 1 ] = NULL ;
}
void F_275 ( struct V_7 * V_8 )
{
int V_101 ;
for ( V_101 = V_345 ; V_101 <= V_346 ; V_101 ++ )
F_272 ( V_8 , V_101 ) ;
}
void F_237 ( struct V_7 * V_8 ,
struct V_20 * V_21 )
{
struct V_80 * V_81 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
char * V_94 ;
int V_101 ;
int V_181 ;
if ( ! V_21 -> V_130 )
return;
V_94 = V_21 -> V_130 -> V_48 -> V_94 ;
V_181 = V_21 -> V_50 . V_3 / V_33 ;
for ( V_101 = 0 ; V_101 < V_181 ; V_101 ++ ) {
struct V_61 * V_61 = F_43 ( V_81 , V_101 ) ;
if ( ! F_44 ( V_61 ) ) {
char * V_347 = F_46 ( V_61 ) ;
memcpy ( V_347 , V_94 + V_101 * V_33 , V_33 ) ;
F_48 ( V_347 ) ;
F_209 ( & V_61 , 1 ) ;
F_79 ( V_61 ) ;
F_49 ( V_61 ) ;
F_50 ( V_61 ) ;
}
}
F_213 () ;
V_21 -> V_130 -> V_344 = NULL ;
V_21 -> V_130 = NULL ;
}
int
F_276 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
int V_339 ,
int V_340 )
{
struct V_80 * V_81 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
T_2 * V_2 = V_8 -> V_9 ;
int V_14 = 0 ;
int V_181 ;
int V_101 ;
if ( V_339 > V_346 )
return - V_38 ;
if ( V_21 -> V_130 ) {
if ( V_21 -> V_130 -> V_339 == V_339 )
return 0 ;
F_237 ( V_8 , V_21 ) ;
}
if ( ! V_2 -> V_4 . V_342 [ V_339 - 1 ] ) {
V_14 = F_268 ( V_8 , V_339 ,
V_21 -> V_50 . V_3 , V_340 ) ;
if ( V_14 ) {
F_112 ( L_20 ,
V_339 , V_21 -> V_50 . V_3 ) ;
return V_14 ;
}
}
V_21 -> V_130 = V_2 -> V_4 . V_342 [ V_339 - 1 ] ;
V_21 -> V_130 -> V_344 = V_21 ;
V_181 = V_21 -> V_50 . V_3 / V_33 ;
for ( V_101 = 0 ; V_101 < V_181 ; V_101 ++ ) {
struct V_61 * V_61 ;
char * V_347 , * V_348 ;
V_61 = F_43 ( V_81 , V_101 ) ;
if ( F_44 ( V_61 ) )
return F_45 ( V_61 ) ;
V_348 = F_46 ( V_61 ) ;
V_347 = V_21 -> V_130 -> V_48 -> V_94 + ( V_101 * V_33 ) ;
memcpy ( V_347 , V_348 , V_33 ) ;
F_48 ( V_348 ) ;
F_49 ( V_61 ) ;
F_50 ( V_61 ) ;
}
return 0 ;
}
static int
F_85 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_122 * args ,
struct V_35 * V_219 )
{
void * V_94 = V_21 -> V_130 -> V_48 -> V_94 + args -> V_88 ;
char T_8 * V_89 = ( char T_8 * ) ( V_92 ) args -> V_93 ;
if ( F_67 ( V_94 , V_89 , args -> V_3 ) ) {
unsigned long V_117 ;
F_19 ( & V_8 -> V_19 ) ;
V_117 = F_277 ( V_94 , V_89 , args -> V_3 ) ;
F_18 ( & V_8 -> V_19 ) ;
if ( V_117 )
return - V_96 ;
}
F_213 () ;
return 0 ;
}
void F_278 ( struct V_7 * V_8 , struct V_35 * V_36 )
{
struct V_218 * V_219 = V_36 -> V_220 ;
F_139 ( & V_219 -> V_4 . V_17 ) ;
while ( ! F_128 ( & V_219 -> V_4 . V_216 ) ) {
struct V_210 * V_211 ;
V_211 = F_147 ( & V_219 -> V_4 . V_216 ,
struct V_210 ,
V_221 ) ;
F_145 ( & V_211 -> V_221 ) ;
V_211 -> V_219 = NULL ;
}
F_140 ( & V_219 -> V_4 . V_17 ) ;
}
static int
F_279 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_349 ;
V_349 = F_128 ( & V_2 -> V_4 . V_203 ) &&
F_128 ( & V_2 -> V_4 . V_190 ) ;
return ! V_349 ;
}
static int
V_336 ( struct V_350 * V_350 , struct V_351 * V_352 )
{
struct V_1 * V_2 =
F_159 ( V_350 ,
struct V_1 ,
V_4 . V_334 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_20 * V_21 , * V_208 ;
int V_353 = V_352 -> V_353 ;
int V_354 ;
if ( ! F_160 ( & V_8 -> V_19 ) )
return 0 ;
if ( V_353 == 0 ) {
V_354 = 0 ;
F_21 (obj,
&dev_priv->mm.inactive_list,
mm_list)
V_354 ++ ;
F_19 ( & V_8 -> V_19 ) ;
return V_354 / 100 * V_355 ;
}
V_356:
F_156 ( V_8 ) ;
F_133 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( F_131 ( V_21 ) ) {
if ( F_98 ( V_21 ) == 0 &&
-- V_353 == 0 )
break;
}
}
V_354 = 0 ;
F_133 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( V_353 &&
F_98 ( V_21 ) == 0 )
V_353 -- ;
else
V_354 ++ ;
}
if ( V_353 && F_279 ( V_8 ) ) {
if ( F_181 ( V_8 ) == 0 )
goto V_356;
}
F_19 ( & V_8 -> V_19 ) ;
return V_354 / 100 * V_355 ;
}
