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
V_94 = F_46 ( V_61 , V_129 ) ;
V_14 = F_78 ( V_94 + V_90 ,
V_89 ,
V_91 ) ;
F_48 ( V_94 , V_129 ) ;
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
if ( ! F_60 ( V_130 ,
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
if ( V_21 -> V_131 )
V_14 = F_85 ( V_8 , V_21 , args , V_36 ) ;
else if ( V_21 -> V_22 &&
V_21 -> V_50 . V_132 != V_133 ) {
V_14 = F_86 ( V_21 , 0 , true ) ;
if ( V_14 )
goto V_110;
V_14 = F_75 ( V_21 , true ) ;
if ( V_14 )
goto V_134;
V_14 = F_76 ( V_21 ) ;
if ( V_14 )
goto V_134;
V_14 = F_73 ( V_8 , V_21 , args , V_36 ) ;
if ( V_14 == - V_96 )
V_14 = F_74 ( V_8 , V_21 , args , V_36 ) ;
V_134:
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
struct V_135 * args = V_34 ;
struct V_20 * V_21 ;
T_4 V_136 = args -> V_136 ;
T_4 V_132 = args -> V_132 ;
int V_14 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
if ( V_132 & V_137 )
return - V_38 ;
if ( V_136 & V_137 )
return - V_38 ;
if ( V_132 != 0 && V_136 != V_132 )
return - V_38 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_62 ( F_63 ( V_8 , V_36 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_112 ;
goto V_113;
}
if ( V_136 & V_138 ) {
V_14 = F_75 ( V_21 , V_132 != 0 ) ;
if ( V_14 == - V_38 )
V_14 = 0 ;
} else {
V_14 = F_81 ( V_21 , V_132 != 0 ) ;
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
struct V_139 * args = V_34 ;
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
struct V_140 * args = V_34 ;
struct V_141 * V_21 ;
unsigned long V_142 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
V_21 = F_63 ( V_8 , V_36 , args -> V_48 ) ;
if ( V_21 == NULL )
return - V_112 ;
if ( V_21 -> V_3 > V_2 -> V_4 . V_29 ) {
F_92 ( V_21 ) ;
return - V_143 ;
}
F_93 ( & V_98 -> V_4 -> V_109 ) ;
V_142 = F_94 ( V_21 -> V_82 , 0 , args -> V_3 ,
V_144 | V_145 , V_146 ,
args -> V_88 ) ;
F_95 ( & V_98 -> V_4 -> V_109 ) ;
F_92 ( V_21 ) ;
if ( F_44 ( ( void * ) V_142 ) )
return V_142 ;
args -> V_147 = ( T_3 ) V_142 ;
return 0 ;
}
int F_96 ( struct V_148 * V_149 , struct V_150 * V_151 )
{
struct V_20 * V_21 = F_62 ( V_149 -> V_152 ) ;
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_10 V_90 ;
unsigned long V_153 ;
int V_14 = 0 ;
bool V_154 = ! ! ( V_151 -> V_13 & V_155 ) ;
V_90 = ( ( unsigned long ) V_151 -> V_156 - V_149 -> V_157 ) >>
V_95 ;
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
goto V_110;
F_97 ( V_21 , V_90 , true , V_154 ) ;
if ( ! V_21 -> V_158 ) {
V_14 = F_98 ( V_21 ) ;
if ( V_14 )
goto V_113;
}
if ( ! V_21 -> V_22 ) {
V_14 = F_99 ( V_21 , 0 , true ) ;
if ( V_14 )
goto V_113;
V_14 = F_75 ( V_21 , V_154 ) ;
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
F_101 ( & V_21 -> V_159 , & V_2 -> V_4 . V_160 ) ;
V_21 -> V_161 = true ;
V_153 = ( ( V_8 -> V_162 -> V_50 + V_21 -> V_119 ) >> V_95 ) +
V_90 ;
V_14 = F_102 ( V_149 , ( unsigned long ) V_151 -> V_156 , V_153 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
V_110:
switch ( V_14 ) {
case - V_163 :
case - V_164 :
F_103 () ;
case 0 :
case - V_165 :
case - V_166 :
return V_167 ;
case - V_49 :
return V_168 ;
default:
return V_169 ;
}
}
static int
F_104 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_170 * V_4 = V_8 -> V_171 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
int V_14 = 0 ;
V_173 = & V_21 -> V_50 . V_176 ;
V_173 -> V_175 = F_105 ( sizeof( struct V_172 ) , V_177 ) ;
if ( ! V_173 -> V_175 )
return - V_49 ;
V_175 = V_173 -> V_175 ;
V_175 -> type = V_178 ;
V_175 -> V_3 = V_21 -> V_50 . V_3 ;
V_175 -> V_48 = V_21 ;
V_173 -> V_179 = F_106 ( & V_4 -> V_180 ,
V_21 -> V_50 . V_3 / V_33 ,
0 , 0 ) ;
if ( ! V_173 -> V_179 ) {
F_107 ( L_1 ,
V_21 -> V_50 . V_181 ) ;
V_14 = - V_182 ;
goto V_183;
}
V_173 -> V_179 = F_108 ( V_173 -> V_179 ,
V_21 -> V_50 . V_3 / V_33 ,
0 ) ;
if ( ! V_173 -> V_179 ) {
V_14 = - V_49 ;
goto V_183;
}
V_173 -> V_184 . V_185 = V_173 -> V_179 -> V_25 ;
V_14 = F_109 ( & V_4 -> V_186 , & V_173 -> V_184 ) ;
if ( V_14 ) {
F_107 ( L_2 ) ;
goto V_187;
}
return 0 ;
V_187:
F_110 ( V_173 -> V_179 ) ;
V_183:
F_27 ( V_173 -> V_175 ) ;
V_173 -> V_175 = NULL ;
return V_14 ;
}
void
F_111 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_161 )
return;
if ( V_21 -> V_50 . V_8 -> V_188 )
F_112 ( V_21 -> V_50 . V_8 -> V_188 ,
( T_7 ) V_21 -> V_50 . V_176 . V_184 . V_185 << V_95 ,
V_21 -> V_50 . V_3 , 1 ) ;
V_21 -> V_161 = false ;
}
static void
F_113 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_170 * V_4 = V_8 -> V_171 ;
struct V_172 * V_173 = & V_21 -> V_50 . V_176 ;
F_114 ( & V_4 -> V_186 , & V_173 -> V_184 ) ;
F_110 ( V_173 -> V_179 ) ;
F_27 ( V_173 -> V_175 ) ;
V_173 -> V_175 = NULL ;
}
static T_4
F_115 ( struct V_7 * V_8 , T_4 V_3 , int V_59 )
{
T_4 V_189 ;
if ( F_116 ( V_8 ) -> V_190 >= 4 ||
V_59 == V_60 )
return V_3 ;
if ( F_116 ( V_8 ) -> V_190 == 3 )
V_189 = 1024 * 1024 ;
else
V_189 = 512 * 1024 ;
while ( V_189 < V_3 )
V_189 <<= 1 ;
return V_189 ;
}
static T_4
F_117 ( struct V_7 * V_8 ,
T_4 V_3 ,
int V_59 )
{
if ( F_116 ( V_8 ) -> V_190 >= 4 ||
V_59 == V_60 )
return 4096 ;
return F_115 ( V_8 , V_3 , V_59 ) ;
}
T_4
F_118 ( struct V_7 * V_8 ,
T_4 V_3 ,
int V_59 )
{
if ( F_116 ( V_8 ) -> V_190 >= 4 || F_119 ( V_8 ) ||
V_59 == V_60 )
return 4096 ;
return F_115 ( V_8 , V_3 , V_59 ) ;
}
int
F_120 ( struct V_35 * V_36 ,
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
V_14 = - V_143 ;
goto V_113;
}
if ( V_21 -> V_191 != V_192 ) {
F_107 ( L_3 ) ;
V_14 = - V_38 ;
goto V_110;
}
if ( ! V_21 -> V_50 . V_176 . V_175 ) {
V_14 = F_104 ( V_21 ) ;
if ( V_14 )
goto V_110;
}
* V_88 = ( V_193 ) V_21 -> V_50 . V_176 . V_184 . V_185 << V_95 ;
V_110:
F_28 ( & V_21 -> V_50 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_121 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_194 * args = V_34 ;
if ( ! ( V_8 -> V_41 -> V_42 & V_43 ) )
return - V_44 ;
return F_120 ( V_36 , V_8 , args -> V_48 , & args -> V_88 ) ;
}
static int
F_122 ( struct V_20 * V_21 ,
T_11 V_195 )
{
int V_196 , V_101 ;
struct V_80 * V_81 ;
struct V_197 * V_197 ;
struct V_61 * V_61 ;
V_196 = V_21 -> V_50 . V_3 / V_33 ;
F_123 ( V_21 -> V_198 != NULL ) ;
V_21 -> V_198 = F_52 ( V_196 , sizeof( struct V_61 * ) ) ;
if ( V_21 -> V_198 == NULL )
return - V_49 ;
V_197 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 ;
V_81 = V_197 -> V_86 ;
V_195 |= F_124 ( V_81 ) ;
for ( V_101 = 0 ; V_101 < V_196 ; V_101 ++ ) {
V_61 = F_125 ( V_81 , V_101 , V_195 ) ;
if ( F_44 ( V_61 ) )
goto V_199;
V_21 -> V_198 [ V_101 ] = V_61 ;
}
if ( V_21 -> V_59 != V_60 )
F_126 ( V_21 ) ;
return 0 ;
V_199:
while ( V_101 -- )
F_50 ( V_21 -> V_198 [ V_101 ] ) ;
F_58 ( V_21 -> V_198 ) ;
V_21 -> V_198 = NULL ;
return F_45 ( V_61 ) ;
}
static void
F_127 ( struct V_20 * V_21 )
{
int V_196 = V_21 -> V_50 . V_3 / V_33 ;
int V_101 ;
F_123 ( V_21 -> V_191 == V_200 ) ;
if ( V_21 -> V_59 != V_60 )
F_128 ( V_21 ) ;
if ( V_21 -> V_191 == V_201 )
V_21 -> V_128 = 0 ;
for ( V_101 = 0 ; V_101 < V_196 ; V_101 ++ ) {
if ( V_21 -> V_128 )
F_79 ( V_21 -> V_198 [ V_101 ] ) ;
if ( V_21 -> V_191 == V_192 )
F_49 ( V_21 -> V_198 [ V_101 ] ) ;
F_50 ( V_21 -> V_198 [ V_101 ] ) ;
}
V_21 -> V_128 = 0 ;
F_58 ( V_21 -> V_198 ) ;
V_21 -> V_198 = NULL ;
}
void
F_129 ( struct V_20 * V_21 ,
struct V_202 * V_203 ,
T_5 V_204 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
F_123 ( V_203 == NULL ) ;
V_21 -> V_203 = V_203 ;
if ( ! V_21 -> V_23 ) {
F_130 ( & V_21 -> V_50 ) ;
V_21 -> V_23 = 1 ;
}
F_101 ( & V_21 -> V_159 , & V_2 -> V_4 . V_205 ) ;
F_101 ( & V_21 -> V_206 , & V_203 -> V_205 ) ;
V_21 -> V_207 = V_204 ;
if ( V_21 -> V_208 ) {
struct V_209 * V_210 ;
F_123 ( V_21 -> V_211 == V_212 ) ;
V_21 -> V_213 = V_204 ;
V_21 -> V_214 = V_203 ;
V_210 = & V_2 -> V_215 [ V_21 -> V_211 ] ;
F_101 ( & V_210 -> V_216 , & V_2 -> V_4 . V_217 ) ;
}
}
static void
F_131 ( struct V_20 * V_21 )
{
F_132 ( & V_21 -> V_206 ) ;
V_21 -> V_207 = 0 ;
}
static void
F_133 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
F_123 ( ! V_21 -> V_23 ) ;
F_101 ( & V_21 -> V_159 , & V_2 -> V_4 . V_218 ) ;
F_131 ( V_21 ) ;
}
static void
F_134 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
if ( V_21 -> V_24 != 0 )
F_101 ( & V_21 -> V_159 , & V_2 -> V_4 . V_219 ) ;
else
F_101 ( & V_21 -> V_159 , & V_2 -> V_4 . V_160 ) ;
F_123 ( ! F_135 ( & V_21 -> V_220 ) ) ;
F_123 ( ! V_21 -> V_23 ) ;
V_21 -> V_203 = NULL ;
F_131 ( V_21 ) ;
V_21 -> V_208 = false ;
V_21 -> V_23 = 0 ;
V_21 -> V_221 = false ;
F_28 ( & V_21 -> V_50 ) ;
F_10 ( F_11 ( V_8 ) ) ;
}
static void
F_136 ( struct V_20 * V_21 )
{
struct V_197 * V_197 ;
V_197 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 ;
F_137 ( V_197 , 0 , ( T_7 ) - 1 ) ;
V_21 -> V_191 = V_200 ;
}
static inline int
F_138 ( struct V_20 * V_21 )
{
return V_21 -> V_191 == V_201 ;
}
static void
F_139 ( struct V_202 * V_203 ,
T_4 V_222 )
{
struct V_20 * V_21 , * V_223 ;
F_140 (obj, next,
&ring->gpu_write_list,
gpu_write_list) {
if ( V_21 -> V_50 . V_132 & V_222 ) {
T_4 V_224 = V_21 -> V_50 . V_132 ;
V_21 -> V_50 . V_132 = 0 ;
F_132 ( & V_21 -> V_220 ) ;
F_129 ( V_21 , V_203 ,
F_141 ( V_203 ) ) ;
F_142 ( V_21 ,
V_21 -> V_50 . V_136 ,
V_224 ) ;
}
}
}
int
F_143 ( struct V_202 * V_203 ,
struct V_35 * V_36 ,
struct V_225 * V_226 )
{
T_2 * V_2 = V_203 -> V_8 -> V_9 ;
T_4 V_204 ;
int V_227 ;
int V_14 ;
F_123 ( V_226 == NULL ) ;
V_14 = V_203 -> V_228 ( V_203 , & V_204 ) ;
if ( V_14 )
return V_14 ;
F_144 ( V_203 , V_204 ) ;
V_226 -> V_204 = V_204 ;
V_226 -> V_203 = V_203 ;
V_226 -> V_229 = V_230 ;
V_227 = F_135 ( & V_203 -> V_231 ) ;
F_145 ( & V_226 -> V_173 , & V_203 -> V_231 ) ;
if ( V_36 ) {
struct V_232 * V_233 = V_36 -> V_234 ;
F_146 ( & V_233 -> V_4 . V_17 ) ;
V_226 -> V_233 = V_233 ;
F_145 ( & V_226 -> V_235 ,
& V_233 -> V_4 . V_231 ) ;
F_147 ( & V_233 -> V_4 . V_17 ) ;
}
V_203 -> V_236 = false ;
if ( ! V_2 -> V_4 . V_237 ) {
F_148 ( & V_2 -> V_238 ,
V_230 + F_149 ( V_239 ) ) ;
if ( V_227 )
F_150 ( V_2 -> V_240 ,
& V_2 -> V_4 . V_241 , V_242 ) ;
}
return 0 ;
}
static inline void
F_151 ( struct V_225 * V_226 )
{
struct V_232 * V_233 = V_226 -> V_233 ;
if ( ! V_233 )
return;
F_146 ( & V_233 -> V_4 . V_17 ) ;
if ( V_226 -> V_233 ) {
F_152 ( & V_226 -> V_235 ) ;
V_226 -> V_233 = NULL ;
}
F_147 ( & V_233 -> V_4 . V_17 ) ;
}
static void F_153 ( struct V_1 * V_2 ,
struct V_202 * V_203 )
{
while ( ! F_135 ( & V_203 -> V_231 ) ) {
struct V_225 * V_226 ;
V_226 = F_154 ( & V_203 -> V_231 ,
struct V_225 ,
V_173 ) ;
F_152 ( & V_226 -> V_173 ) ;
F_151 ( V_226 ) ;
F_27 ( V_226 ) ;
}
while ( ! F_135 ( & V_203 -> V_205 ) ) {
struct V_20 * V_21 ;
V_21 = F_154 ( & V_203 -> V_205 ,
struct V_20 ,
V_206 ) ;
V_21 -> V_50 . V_132 = 0 ;
F_132 ( & V_21 -> V_220 ) ;
F_134 ( V_21 ) ;
}
}
static void F_155 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < 16 ; V_101 ++ ) {
struct V_209 * V_210 = & V_2 -> V_215 [ V_101 ] ;
struct V_20 * V_21 = V_210 -> V_21 ;
if ( ! V_21 )
continue;
if ( V_21 -> V_59 )
F_111 ( V_21 ) ;
V_210 -> V_21 -> V_211 = V_212 ;
V_210 -> V_21 -> V_208 = false ;
V_210 -> V_21 -> V_213 = 0 ;
V_210 -> V_21 -> V_214 = NULL ;
F_156 ( V_8 , V_210 ) ;
}
}
void F_157 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_20 * V_21 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_243 ; V_101 ++ )
F_153 ( V_2 , & V_2 -> V_203 [ V_101 ] ) ;
while ( ! F_135 ( & V_2 -> V_4 . V_218 ) ) {
V_21 = F_154 ( & V_2 -> V_4 . V_218 ,
struct V_20 ,
V_159 ) ;
V_21 -> V_50 . V_132 = 0 ;
F_132 ( & V_21 -> V_220 ) ;
F_134 ( V_21 ) ;
}
F_21 (obj,
&dev_priv->mm.inactive_list,
mm_list)
{
V_21 -> V_50 . V_136 &= ~ V_137 ;
}
F_155 ( V_8 ) ;
}
static void
F_158 ( struct V_202 * V_203 )
{
T_4 V_204 ;
int V_101 ;
if ( F_135 ( & V_203 -> V_231 ) )
return;
F_10 ( F_11 ( V_203 -> V_8 ) ) ;
V_204 = V_203 -> V_244 ( V_203 ) ;
for ( V_101 = 0 ; V_101 < F_159 ( V_203 -> V_245 ) ; V_101 ++ )
if ( V_204 >= V_203 -> V_245 [ V_101 ] )
V_203 -> V_245 [ V_101 ] = 0 ;
while ( ! F_135 ( & V_203 -> V_231 ) ) {
struct V_225 * V_226 ;
V_226 = F_154 ( & V_203 -> V_231 ,
struct V_225 ,
V_173 ) ;
if ( ! F_160 ( V_204 , V_226 -> V_204 ) )
break;
F_161 ( V_203 , V_226 -> V_204 ) ;
F_152 ( & V_226 -> V_173 ) ;
F_151 ( V_226 ) ;
F_27 ( V_226 ) ;
}
while ( ! F_135 ( & V_203 -> V_205 ) ) {
struct V_20 * V_21 ;
V_21 = F_154 ( & V_203 -> V_205 ,
struct V_20 ,
V_206 ) ;
if ( ! F_160 ( V_204 , V_21 -> V_207 ) )
break;
if ( V_21 -> V_50 . V_132 != 0 )
F_133 ( V_21 ) ;
else
F_134 ( V_21 ) ;
}
if ( F_162 ( V_203 -> V_246 &&
F_160 ( V_204 , V_203 -> V_246 ) ) ) {
V_203 -> V_247 ( V_203 ) ;
V_203 -> V_246 = 0 ;
}
F_10 ( F_11 ( V_203 -> V_8 ) ) ;
}
void
F_163 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_101 ;
if ( ! F_135 ( & V_2 -> V_4 . V_248 ) ) {
struct V_20 * V_21 , * V_223 ;
F_140 (obj, next,
&dev_priv->mm.deferred_free_list,
mm_list)
F_164 ( V_21 ) ;
}
for ( V_101 = 0 ; V_101 < V_243 ; V_101 ++ )
F_158 ( & V_2 -> V_203 [ V_101 ] ) ;
}
static void
F_165 ( struct V_249 * V_250 )
{
T_2 * V_2 ;
struct V_7 * V_8 ;
bool V_251 ;
int V_101 ;
V_2 = F_166 ( V_250 , T_2 ,
V_4 . V_241 . V_250 ) ;
V_8 = V_2 -> V_8 ;
if ( ! F_167 ( & V_8 -> V_19 ) ) {
F_150 ( V_2 -> V_240 , & V_2 -> V_4 . V_241 , V_242 ) ;
return;
}
F_163 ( V_8 ) ;
V_251 = true ;
for ( V_101 = 0 ; V_101 < V_243 ; V_101 ++ ) {
struct V_202 * V_203 = & V_2 -> V_203 [ V_101 ] ;
if ( ! F_135 ( & V_203 -> V_220 ) ) {
struct V_225 * V_226 ;
int V_14 ;
V_14 = F_168 ( V_203 ,
0 , V_137 ) ;
V_226 = F_105 ( sizeof( * V_226 ) , V_177 ) ;
if ( V_14 || V_226 == NULL ||
F_143 ( V_203 , NULL , V_226 ) )
F_27 ( V_226 ) ;
}
V_251 &= F_135 ( & V_203 -> V_231 ) ;
}
if ( ! V_2 -> V_4 . V_237 && ! V_251 )
F_150 ( V_2 -> V_240 , & V_2 -> V_4 . V_241 , V_242 ) ;
F_19 ( & V_8 -> V_19 ) ;
}
int
F_169 ( struct V_202 * V_203 ,
T_4 V_204 )
{
T_2 * V_2 = V_203 -> V_8 -> V_9 ;
T_5 V_252 ;
int V_14 = 0 ;
F_123 ( V_204 == 0 ) ;
if ( F_4 ( & V_2 -> V_4 . V_15 ) ) {
struct V_10 * V_11 = & V_2 -> V_12 ;
bool V_253 ;
unsigned long V_13 ;
F_6 ( & V_11 -> V_16 . V_17 , V_13 ) ;
V_253 = V_11 -> V_18 > 0 ;
F_7 ( & V_11 -> V_16 . V_17 , V_13 ) ;
return V_253 ? - V_163 : - V_164 ;
}
if ( V_204 == V_203 -> V_236 ) {
struct V_225 * V_226 ;
V_226 = F_105 ( sizeof( * V_226 ) , V_177 ) ;
if ( V_226 == NULL )
return - V_49 ;
V_14 = F_143 ( V_203 , NULL , V_226 ) ;
if ( V_14 ) {
F_27 ( V_226 ) ;
return V_14 ;
}
V_204 = V_226 -> V_204 ;
}
if ( ! F_160 ( V_203 -> V_244 ( V_203 ) , V_204 ) ) {
if ( F_170 ( V_203 -> V_8 ) )
V_252 = F_171 ( V_254 ) | F_171 ( V_255 ) ;
else
V_252 = F_171 ( V_256 ) ;
if ( ! V_252 ) {
F_107 ( L_4
L_5 ) ;
V_203 -> V_8 -> V_41 -> V_257 ( V_203 -> V_8 ) ;
V_203 -> V_8 -> V_41 -> V_258 ( V_203 -> V_8 ) ;
}
F_172 ( V_203 , V_204 ) ;
V_203 -> V_259 = V_204 ;
if ( V_203 -> V_260 ( V_203 ) ) {
if ( V_2 -> V_4 . V_261 )
V_14 = F_173 ( V_203 -> V_262 ,
F_160 ( V_203 -> V_244 ( V_203 ) , V_204 )
|| F_4 ( & V_2 -> V_4 . V_15 ) ) ;
else
F_174 ( V_203 -> V_262 ,
F_160 ( V_203 -> V_244 ( V_203 ) , V_204 )
|| F_4 ( & V_2 -> V_4 . V_15 ) ) ;
V_203 -> V_247 ( V_203 ) ;
} else if ( F_175 ( F_160 ( V_203 -> V_244 ( V_203 ) ,
V_204 ) ||
F_4 ( & V_2 -> V_4 . V_15 ) , 3000 ) )
V_14 = - V_263 ;
V_203 -> V_259 = 0 ;
F_176 ( V_203 , V_204 ) ;
}
if ( F_4 ( & V_2 -> V_4 . V_15 ) )
V_14 = - V_164 ;
if ( V_14 && V_14 != - V_165 )
F_107 ( L_6 ,
V_264 , V_14 , V_204 , V_203 -> V_244 ( V_203 ) ,
V_2 -> V_265 ) ;
if ( V_14 == 0 )
F_158 ( V_203 ) ;
return V_14 ;
}
int
F_177 ( struct V_20 * V_21 )
{
int V_14 ;
F_123 ( ( V_21 -> V_50 . V_132 & V_137 ) != 0 ) ;
if ( V_21 -> V_23 ) {
V_14 = F_169 ( V_21 -> V_203 , V_21 -> V_207 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
int
F_98 ( struct V_20 * V_21 )
{
int V_14 = 0 ;
if ( V_21 -> V_22 == NULL )
return 0 ;
if ( V_21 -> V_24 != 0 ) {
F_107 ( L_7 ) ;
return - V_38 ;
}
F_111 ( V_21 ) ;
V_14 = F_81 ( V_21 , 1 ) ;
if ( V_14 == - V_165 )
return V_14 ;
if ( V_14 ) {
F_178 ( V_21 ) ;
V_21 -> V_50 . V_136 = V_21 -> V_50 . V_132 = V_133 ;
}
V_14 = F_76 ( V_21 ) ;
if ( V_14 == - V_165 )
return V_14 ;
F_179 ( V_21 ) ;
F_180 ( V_21 ) ;
F_127 ( V_21 ) ;
F_132 ( & V_21 -> V_266 ) ;
F_132 ( & V_21 -> V_159 ) ;
V_21 -> V_158 = true ;
F_110 ( V_21 -> V_22 ) ;
V_21 -> V_22 = NULL ;
V_21 -> V_119 = 0 ;
if ( F_138 ( V_21 ) )
F_136 ( V_21 ) ;
return V_14 ;
}
int
F_168 ( struct V_202 * V_203 ,
T_4 V_267 ,
T_4 V_222 )
{
int V_14 ;
if ( ( ( V_267 | V_222 ) & V_137 ) == 0 )
return 0 ;
F_181 ( V_203 , V_267 , V_222 ) ;
V_14 = V_203 -> V_268 ( V_203 , V_267 , V_222 ) ;
if ( V_14 )
return V_14 ;
if ( V_222 & V_137 )
F_139 ( V_203 , V_222 ) ;
return 0 ;
}
static int F_182 ( struct V_202 * V_203 )
{
int V_14 ;
if ( F_135 ( & V_203 -> V_220 ) && F_135 ( & V_203 -> V_205 ) )
return 0 ;
if ( ! F_135 ( & V_203 -> V_220 ) ) {
V_14 = F_168 ( V_203 ,
V_137 , V_137 ) ;
if ( V_14 )
return V_14 ;
}
return F_169 ( V_203 , F_141 ( V_203 ) ) ;
}
int
F_183 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
bool V_269 ;
int V_14 , V_101 ;
V_269 = ( F_135 ( & V_2 -> V_4 . V_218 ) &&
F_135 ( & V_2 -> V_4 . V_205 ) ) ;
if ( V_269 )
return 0 ;
for ( V_101 = 0 ; V_101 < V_243 ; V_101 ++ ) {
V_14 = F_182 ( & V_2 -> V_203 [ V_101 ] ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static int F_184 ( struct V_20 * V_21 ,
struct V_202 * V_270 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_3 = V_21 -> V_22 -> V_3 ;
int V_271 = V_21 -> V_211 ;
T_3 V_272 ;
V_272 = ( T_3 ) ( ( V_21 -> V_119 + V_3 - 4096 ) &
0xfffff000 ) << 32 ;
V_272 |= V_21 -> V_119 & 0xfffff000 ;
V_272 |= ( T_3 ) ( ( V_21 -> V_273 / 128 ) - 1 ) <<
V_274 ;
if ( V_21 -> V_59 == V_275 )
V_272 |= 1 << V_276 ;
V_272 |= V_277 ;
if ( V_270 ) {
int V_14 = F_185 ( V_270 , 6 ) ;
if ( V_14 )
return V_14 ;
F_186 ( V_270 , V_278 ) ;
F_186 ( V_270 , F_187 ( 2 ) ) ;
F_186 ( V_270 , V_279 + V_271 * 8 ) ;
F_186 ( V_270 , ( T_5 ) V_272 ) ;
F_186 ( V_270 , V_279 + V_271 * 8 + 4 ) ;
F_186 ( V_270 , ( T_5 ) ( V_272 >> 32 ) ) ;
F_188 ( V_270 ) ;
} else
F_189 ( V_279 + V_271 * 8 , V_272 ) ;
return 0 ;
}
static int F_190 ( struct V_20 * V_21 ,
struct V_202 * V_270 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_3 = V_21 -> V_22 -> V_3 ;
int V_271 = V_21 -> V_211 ;
T_3 V_272 ;
V_272 = ( T_3 ) ( ( V_21 -> V_119 + V_3 - 4096 ) &
0xfffff000 ) << 32 ;
V_272 |= V_21 -> V_119 & 0xfffff000 ;
V_272 |= ( ( V_21 -> V_273 / 128 ) - 1 ) << V_280 ;
if ( V_21 -> V_59 == V_275 )
V_272 |= 1 << V_276 ;
V_272 |= V_277 ;
if ( V_270 ) {
int V_14 = F_185 ( V_270 , 6 ) ;
if ( V_14 )
return V_14 ;
F_186 ( V_270 , V_278 ) ;
F_186 ( V_270 , F_187 ( 2 ) ) ;
F_186 ( V_270 , V_281 + V_271 * 8 ) ;
F_186 ( V_270 , ( T_5 ) V_272 ) ;
F_186 ( V_270 , V_281 + V_271 * 8 + 4 ) ;
F_186 ( V_270 , ( T_5 ) ( V_272 >> 32 ) ) ;
F_188 ( V_270 ) ;
} else
F_189 ( V_281 + V_271 * 8 , V_272 ) ;
return 0 ;
}
static int F_191 ( struct V_20 * V_21 ,
struct V_202 * V_270 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_3 = V_21 -> V_22 -> V_3 ;
T_5 V_211 , V_272 , V_282 ;
int V_283 ;
if ( F_192 ( ( V_21 -> V_119 & ~ V_284 ) ||
( V_3 & - V_3 ) != V_3 ||
( V_21 -> V_119 & ( V_3 - 1 ) ) ,
L_8 ,
V_21 -> V_119 , V_21 -> V_158 , V_3 ) )
return - V_38 ;
if ( V_21 -> V_59 == V_275 && F_193 ( V_8 ) )
V_283 = 128 ;
else
V_283 = 512 ;
V_282 = V_21 -> V_273 / V_283 ;
V_282 = F_194 ( V_282 ) - 1 ;
V_272 = V_21 -> V_119 ;
if ( V_21 -> V_59 == V_275 )
V_272 |= 1 << V_285 ;
V_272 |= F_195 ( V_3 ) ;
V_272 |= V_282 << V_286 ;
V_272 |= V_287 ;
V_211 = V_21 -> V_211 ;
if ( V_211 < 8 )
V_211 = V_288 + V_211 * 4 ;
else
V_211 = V_289 + ( V_211 - 8 ) * 4 ;
if ( V_270 ) {
int V_14 = F_185 ( V_270 , 4 ) ;
if ( V_14 )
return V_14 ;
F_186 ( V_270 , V_278 ) ;
F_186 ( V_270 , F_187 ( 1 ) ) ;
F_186 ( V_270 , V_211 ) ;
F_186 ( V_270 , V_272 ) ;
F_188 ( V_270 ) ;
} else
F_196 ( V_211 , V_272 ) ;
return 0 ;
}
static int F_197 ( struct V_20 * V_21 ,
struct V_202 * V_270 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
T_5 V_3 = V_21 -> V_22 -> V_3 ;
int V_271 = V_21 -> V_211 ;
T_4 V_272 ;
T_4 V_282 ;
if ( F_192 ( ( V_21 -> V_119 & ~ V_290 ) ||
( V_3 & - V_3 ) != V_3 ||
( V_21 -> V_119 & ( V_3 - 1 ) ) ,
L_9 ,
V_21 -> V_119 , V_3 ) )
return - V_38 ;
V_282 = V_21 -> V_273 / 128 ;
V_282 = F_194 ( V_282 ) - 1 ;
V_272 = V_21 -> V_119 ;
if ( V_21 -> V_59 == V_275 )
V_272 |= 1 << V_285 ;
V_272 |= F_198 ( V_3 ) ;
V_272 |= V_282 << V_286 ;
V_272 |= V_287 ;
if ( V_270 ) {
int V_14 = F_185 ( V_270 , 4 ) ;
if ( V_14 )
return V_14 ;
F_186 ( V_270 , V_278 ) ;
F_186 ( V_270 , F_187 ( 1 ) ) ;
F_186 ( V_270 , V_288 + V_271 * 4 ) ;
F_186 ( V_270 , V_272 ) ;
F_188 ( V_270 ) ;
} else
F_196 ( V_288 + V_271 * 4 , V_272 ) ;
return 0 ;
}
static bool F_199 ( struct V_202 * V_203 , T_5 V_204 )
{
return F_160 ( V_203 -> V_244 ( V_203 ) , V_204 ) ;
}
static int
F_200 ( struct V_20 * V_21 ,
struct V_202 * V_270 )
{
int V_14 ;
if ( V_21 -> V_208 ) {
if ( V_21 -> V_50 . V_132 & V_137 ) {
V_14 = F_168 ( V_21 -> V_214 ,
0 , V_21 -> V_50 . V_132 ) ;
if ( V_14 )
return V_14 ;
}
V_21 -> V_208 = false ;
}
if ( V_21 -> V_213 && V_270 != V_21 -> V_214 ) {
if ( ! F_199 ( V_21 -> V_214 ,
V_21 -> V_213 ) ) {
V_14 = F_169 ( V_21 -> V_214 ,
V_21 -> V_213 ) ;
if ( V_14 )
return V_14 ;
}
V_21 -> V_213 = 0 ;
V_21 -> V_214 = NULL ;
}
if ( V_21 -> V_50 . V_136 & V_138 )
F_201 () ;
return 0 ;
}
int
F_76 ( struct V_20 * V_21 )
{
int V_14 ;
if ( V_21 -> V_59 )
F_111 ( V_21 ) ;
V_14 = F_200 ( V_21 , NULL ) ;
if ( V_14 )
return V_14 ;
if ( V_21 -> V_211 != V_212 ) {
struct V_1 * V_2 = V_21 -> V_50 . V_8 -> V_9 ;
F_156 ( V_21 -> V_50 . V_8 ,
& V_2 -> V_215 [ V_21 -> V_211 ] ) ;
V_21 -> V_211 = V_212 ;
}
return 0 ;
}
static struct V_209 *
F_202 ( struct V_7 * V_8 ,
struct V_202 * V_270 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_209 * V_210 , * V_291 , * V_292 ;
int V_101 ;
V_292 = NULL ;
for ( V_101 = V_2 -> V_293 ; V_101 < V_2 -> V_294 ; V_101 ++ ) {
V_210 = & V_2 -> V_215 [ V_101 ] ;
if ( ! V_210 -> V_21 )
return V_210 ;
if ( ! V_210 -> V_21 -> V_24 )
V_292 = V_210 ;
}
if ( V_292 == NULL )
return NULL ;
V_292 = V_291 = NULL ;
F_21 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_210 -> V_21 -> V_24 )
continue;
if ( V_291 == NULL )
V_291 = V_210 ;
if ( ! V_270 ||
! V_210 -> V_21 -> V_214 ||
V_210 -> V_21 -> V_214 == V_270 ) {
V_292 = V_210 ;
break;
}
}
if ( V_292 == NULL )
V_292 = V_291 ;
return V_292 ;
}
int
F_100 ( struct V_20 * V_21 ,
struct V_202 * V_270 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_209 * V_210 ;
int V_14 ;
V_270 = NULL ;
if ( V_21 -> V_211 != V_212 ) {
V_210 = & V_2 -> V_215 [ V_21 -> V_211 ] ;
F_101 ( & V_210 -> V_216 , & V_2 -> V_4 . V_217 ) ;
if ( V_21 -> V_295 ) {
V_14 = F_200 ( V_21 , V_270 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_21 -> V_208 && ! V_21 -> V_213 )
V_270 = NULL ;
if ( V_270 ) {
V_210 -> V_296 =
F_141 ( V_270 ) ;
V_21 -> V_213 = V_210 -> V_296 ;
V_21 -> V_214 = V_270 ;
}
goto V_297;
}
if ( ! V_270 ) {
if ( V_210 -> V_296 ) {
if ( ! F_199 ( V_21 -> V_214 ,
V_210 -> V_296 ) ) {
V_14 = F_169 ( V_21 -> V_214 ,
V_210 -> V_296 ) ;
if ( V_14 )
return V_14 ;
}
V_210 -> V_296 = 0 ;
}
} else if ( V_21 -> V_214 &&
V_21 -> V_214 != V_270 ) {
V_14 = F_200 ( V_21 , V_270 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
V_210 = F_202 ( V_8 , V_270 ) ;
if ( V_210 == NULL )
return - V_182 ;
V_14 = F_200 ( V_21 , V_270 ) ;
if ( V_14 )
return V_14 ;
if ( V_210 -> V_21 ) {
struct V_20 * V_298 = V_210 -> V_21 ;
F_130 ( & V_298 -> V_50 ) ;
if ( V_298 -> V_59 )
F_111 ( V_298 ) ;
V_14 = F_200 ( V_298 , V_270 ) ;
if ( V_14 ) {
F_28 ( & V_298 -> V_50 ) ;
return V_14 ;
}
if ( V_298 -> V_213 == 0 && V_21 -> V_213 == 0 )
V_270 = NULL ;
V_298 -> V_211 = V_212 ;
V_298 -> V_214 = V_270 ;
V_298 -> V_213 =
V_270 ? F_141 ( V_270 ) : 0 ;
F_28 ( & V_298 -> V_50 ) ;
} else if ( V_21 -> V_213 == 0 )
V_270 = NULL ;
V_210 -> V_21 = V_21 ;
F_101 ( & V_210 -> V_216 , & V_2 -> V_4 . V_217 ) ;
V_21 -> V_211 = V_210 - V_2 -> V_215 ;
V_21 -> V_214 = V_270 ;
V_210 -> V_296 =
V_270 ? F_141 ( V_270 ) : 0 ;
V_21 -> V_213 = V_210 -> V_296 ;
V_297:
V_21 -> V_295 = false ;
switch ( F_116 ( V_8 ) -> V_190 ) {
case 7 :
case 6 :
V_14 = F_184 ( V_21 , V_270 ) ;
break;
case 5 :
case 4 :
V_14 = F_190 ( V_21 , V_270 ) ;
break;
case 3 :
V_14 = F_191 ( V_21 , V_270 ) ;
break;
case 2 :
V_14 = F_197 ( V_21 , V_270 ) ;
break;
}
return V_14 ;
}
static void
F_156 ( struct V_7 * V_8 ,
struct V_209 * V_210 )
{
T_2 * V_2 = V_8 -> V_9 ;
T_4 V_211 = V_210 - V_2 -> V_215 ;
switch ( F_116 ( V_8 ) -> V_190 ) {
case 7 :
case 6 :
F_189 ( V_279 + V_211 * 8 , 0 ) ;
break;
case 5 :
case 4 :
F_189 ( V_281 + V_211 * 8 , 0 ) ;
break;
case 3 :
if ( V_211 >= 8 )
V_211 = V_289 + ( V_211 - 8 ) * 4 ;
else
case 2 :
V_211 = V_288 + V_211 * 4 ;
F_196 ( V_211 , 0 ) ;
break;
}
F_132 ( & V_210 -> V_216 ) ;
V_210 -> V_21 = NULL ;
V_210 -> V_296 = 0 ;
}
static int
F_99 ( struct V_20 * V_21 ,
unsigned V_299 ,
bool V_158 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
struct V_300 * V_301 ;
T_11 V_195 = V_302 | V_303 ;
T_5 V_3 , V_304 , V_305 , V_306 ;
bool V_307 , V_308 ;
int V_14 ;
if ( V_21 -> V_191 != V_192 ) {
F_107 ( L_10 ) ;
return - V_38 ;
}
V_304 = F_115 ( V_8 ,
V_21 -> V_50 . V_3 ,
V_21 -> V_59 ) ;
V_305 = F_117 ( V_8 ,
V_21 -> V_50 . V_3 ,
V_21 -> V_59 ) ;
V_306 =
F_118 ( V_8 ,
V_21 -> V_50 . V_3 ,
V_21 -> V_59 ) ;
if ( V_299 == 0 )
V_299 = V_158 ? V_305 :
V_306 ;
if ( V_158 && V_299 & ( V_305 - 1 ) ) {
F_107 ( L_11 , V_299 ) ;
return - V_38 ;
}
V_3 = V_158 ? V_304 : V_21 -> V_50 . V_3 ;
if ( V_21 -> V_50 . V_3 >
( V_158 ? V_2 -> V_4 . V_29 : V_2 -> V_4 . V_31 ) ) {
F_107 ( L_12 ) ;
return - V_143 ;
}
V_309:
if ( V_158 )
V_301 =
F_203 ( & V_2 -> V_4 . V_22 ,
V_3 , V_299 , 0 ,
V_2 -> V_4 . V_29 ,
0 ) ;
else
V_301 = F_106 ( & V_2 -> V_4 . V_22 ,
V_3 , V_299 , 0 ) ;
if ( V_301 != NULL ) {
if ( V_158 )
V_21 -> V_22 =
F_204 ( V_301 ,
V_3 , V_299 , 0 ,
V_2 -> V_4 . V_29 ,
0 ) ;
else
V_21 -> V_22 =
F_108 ( V_301 , V_3 , V_299 ) ;
}
if ( V_21 -> V_22 == NULL ) {
V_14 = F_205 ( V_8 , V_3 , V_299 ,
V_158 ) ;
if ( V_14 )
return V_14 ;
goto V_309;
}
V_14 = F_122 ( V_21 , V_195 ) ;
if ( V_14 ) {
F_110 ( V_21 -> V_22 ) ;
V_21 -> V_22 = NULL ;
if ( V_14 == - V_49 ) {
V_14 = F_206 ( V_8 , false ) ;
if ( V_14 ) {
if ( V_195 ) {
V_195 = 0 ;
goto V_309;
}
return - V_49 ;
}
goto V_309;
}
return V_14 ;
}
V_14 = F_207 ( V_21 ) ;
if ( V_14 ) {
F_127 ( V_21 ) ;
F_110 ( V_21 -> V_22 ) ;
V_21 -> V_22 = NULL ;
if ( F_206 ( V_8 , false ) )
return V_14 ;
goto V_309;
}
F_145 ( & V_21 -> V_266 , & V_2 -> V_4 . V_266 ) ;
F_145 ( & V_21 -> V_159 , & V_2 -> V_4 . V_160 ) ;
F_123 ( V_21 -> V_50 . V_136 & V_137 ) ;
F_123 ( V_21 -> V_50 . V_132 & V_137 ) ;
V_21 -> V_119 = V_21 -> V_22 -> V_25 ;
V_308 =
V_21 -> V_22 -> V_3 == V_304 &&
( V_21 -> V_22 -> V_25 & ( V_305 - 1 ) ) == 0 ;
V_307 =
V_21 -> V_119 + V_21 -> V_50 . V_3 <= V_2 -> V_4 . V_29 ;
V_21 -> V_158 = V_307 && V_308 ;
F_208 ( V_21 , V_158 ) ;
return 0 ;
}
void
F_178 ( struct V_20 * V_21 )
{
if ( V_21 -> V_198 == NULL )
return;
if ( V_21 -> V_310 != V_311 )
return;
F_209 ( V_21 ) ;
F_210 ( V_21 -> V_198 , V_21 -> V_50 . V_3 / V_33 ) ;
}
static int
F_211 ( struct V_20 * V_21 )
{
if ( ( V_21 -> V_50 . V_132 & V_137 ) == 0 )
return 0 ;
return F_168 ( V_21 -> V_203 , 0 , V_21 -> V_50 . V_132 ) ;
}
static void
F_212 ( struct V_20 * V_21 )
{
T_4 V_224 ;
if ( V_21 -> V_50 . V_132 != V_138 )
return;
F_213 () ;
V_224 = V_21 -> V_50 . V_132 ;
V_21 -> V_50 . V_132 = 0 ;
F_142 ( V_21 ,
V_21 -> V_50 . V_136 ,
V_224 ) ;
}
static void
F_90 ( struct V_20 * V_21 )
{
T_4 V_224 ;
if ( V_21 -> V_50 . V_132 != V_133 )
return;
F_178 ( V_21 ) ;
F_214 () ;
V_224 = V_21 -> V_50 . V_132 ;
V_21 -> V_50 . V_132 = 0 ;
F_142 ( V_21 ,
V_21 -> V_50 . V_136 ,
V_224 ) ;
}
int
F_75 ( struct V_20 * V_21 , bool V_154 )
{
T_4 V_224 , V_312 ;
int V_14 ;
if ( V_21 -> V_22 == NULL )
return - V_38 ;
if ( V_21 -> V_50 . V_132 == V_138 )
return 0 ;
V_14 = F_211 ( V_21 ) ;
if ( V_14 )
return V_14 ;
if ( V_21 -> V_221 || V_154 ) {
V_14 = F_177 ( V_21 ) ;
if ( V_14 )
return V_14 ;
}
F_90 ( V_21 ) ;
V_224 = V_21 -> V_50 . V_132 ;
V_312 = V_21 -> V_50 . V_136 ;
F_123 ( ( V_21 -> V_50 . V_132 & ~ V_138 ) != 0 ) ;
V_21 -> V_50 . V_136 |= V_138 ;
if ( V_154 ) {
V_21 -> V_50 . V_136 = V_138 ;
V_21 -> V_50 . V_132 = V_138 ;
V_21 -> V_128 = 1 ;
}
F_142 ( V_21 ,
V_312 ,
V_224 ) ;
return 0 ;
}
int
F_215 ( struct V_20 * V_21 ,
struct V_202 * V_270 )
{
T_4 V_312 ;
int V_14 ;
if ( V_21 -> V_22 == NULL )
return - V_38 ;
V_14 = F_211 ( V_21 ) ;
if ( V_14 )
return V_14 ;
if ( V_270 != V_21 -> V_203 ) {
V_14 = F_177 ( V_21 ) ;
if ( V_14 )
return V_14 ;
}
F_90 ( V_21 ) ;
V_312 = V_21 -> V_50 . V_136 ;
V_21 -> V_50 . V_136 |= V_138 ;
F_142 ( V_21 ,
V_312 ,
V_21 -> V_50 . V_132 ) ;
return 0 ;
}
int
F_216 ( struct V_20 * V_21 )
{
int V_14 ;
if ( ! V_21 -> V_23 )
return 0 ;
if ( V_21 -> V_50 . V_132 & V_137 ) {
V_14 = F_168 ( V_21 -> V_203 , 0 , V_21 -> V_50 . V_132 ) ;
if ( V_14 )
return V_14 ;
}
return F_177 ( V_21 ) ;
}
static int
F_81 ( struct V_20 * V_21 , bool V_154 )
{
T_4 V_224 , V_312 ;
int V_14 ;
if ( V_21 -> V_50 . V_132 == V_133 )
return 0 ;
V_14 = F_211 ( V_21 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_177 ( V_21 ) ;
if ( V_14 )
return V_14 ;
F_212 ( V_21 ) ;
F_217 ( V_21 ) ;
V_224 = V_21 -> V_50 . V_132 ;
V_312 = V_21 -> V_50 . V_136 ;
if ( ( V_21 -> V_50 . V_136 & V_133 ) == 0 ) {
F_178 ( V_21 ) ;
V_21 -> V_50 . V_136 |= V_133 ;
}
F_123 ( ( V_21 -> V_50 . V_132 & ~ V_133 ) != 0 ) ;
if ( V_154 ) {
V_21 -> V_50 . V_136 = V_133 ;
V_21 -> V_50 . V_132 = V_133 ;
}
F_142 ( V_21 ,
V_312 ,
V_224 ) ;
return 0 ;
}
static void
F_217 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_313 )
return;
if ( V_21 -> V_50 . V_136 & V_133 ) {
int V_101 ;
for ( V_101 = 0 ; V_101 <= ( V_21 -> V_50 . V_3 - 1 ) / V_33 ; V_101 ++ ) {
if ( V_21 -> V_313 [ V_101 ] )
continue;
F_210 ( V_21 -> V_198 + V_101 , 1 ) ;
}
}
F_27 ( V_21 -> V_313 ) ;
V_21 -> V_313 = NULL ;
}
static int
F_56 ( struct V_20 * V_21 ,
T_3 V_88 , T_3 V_3 )
{
T_4 V_312 ;
int V_101 , V_14 ;
if ( V_88 == 0 && V_3 == V_21 -> V_50 . V_3 )
return F_81 ( V_21 , 0 ) ;
V_14 = F_211 ( V_21 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_177 ( V_21 ) ;
if ( V_14 )
return V_14 ;
F_212 ( V_21 ) ;
if ( V_21 -> V_313 == NULL &&
( V_21 -> V_50 . V_136 & V_133 ) != 0 )
return 0 ;
if ( V_21 -> V_313 == NULL ) {
V_21 -> V_313 = F_105 ( V_21 -> V_50 . V_3 / V_33 ,
V_177 ) ;
if ( V_21 -> V_313 == NULL )
return - V_49 ;
} else if ( ( V_21 -> V_50 . V_136 & V_133 ) == 0 )
memset ( V_21 -> V_313 , 0 , V_21 -> V_50 . V_3 / V_33 ) ;
for ( V_101 = V_88 / V_33 ; V_101 <= ( V_88 + V_3 - 1 ) / V_33 ;
V_101 ++ ) {
if ( V_21 -> V_313 [ V_101 ] )
continue;
F_210 ( V_21 -> V_198 + V_101 , 1 ) ;
V_21 -> V_313 [ V_101 ] = 1 ;
}
F_123 ( ( V_21 -> V_50 . V_132 & ~ V_133 ) != 0 ) ;
V_312 = V_21 -> V_50 . V_136 ;
V_21 -> V_50 . V_136 |= V_133 ;
F_142 ( V_21 ,
V_312 ,
V_21 -> V_50 . V_132 ) ;
return 0 ;
}
static int
F_218 ( struct V_7 * V_8 , struct V_35 * V_36 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_232 * V_233 = V_36 -> V_234 ;
unsigned long V_314 = V_230 - F_149 ( 20 ) ;
struct V_225 * V_226 ;
struct V_202 * V_203 = NULL ;
T_5 V_204 = 0 ;
int V_14 ;
if ( F_4 ( & V_2 -> V_4 . V_15 ) )
return - V_163 ;
F_146 ( & V_233 -> V_4 . V_17 ) ;
F_21 (request, &file_priv->mm.request_list, client_list) {
if ( F_219 ( V_226 -> V_229 , V_314 ) )
break;
V_203 = V_226 -> V_203 ;
V_204 = V_226 -> V_204 ;
}
F_147 ( & V_233 -> V_4 . V_17 ) ;
if ( V_204 == 0 )
return 0 ;
V_14 = 0 ;
if ( ! F_160 ( V_203 -> V_244 ( V_203 ) , V_204 ) ) {
if ( V_203 -> V_260 ( V_203 ) ) {
V_14 = F_173 ( V_203 -> V_262 ,
F_160 ( V_203 -> V_244 ( V_203 ) , V_204 )
|| F_4 ( & V_2 -> V_4 . V_15 ) ) ;
V_203 -> V_247 ( V_203 ) ;
if ( V_14 == 0 && F_4 ( & V_2 -> V_4 . V_15 ) )
V_14 = - V_163 ;
}
}
if ( V_14 == 0 )
F_150 ( V_2 -> V_240 , & V_2 -> V_4 . V_241 , 0 ) ;
return V_14 ;
}
int
F_86 ( struct V_20 * V_21 ,
T_4 V_299 ,
bool V_158 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
int V_14 ;
F_123 ( V_21 -> V_24 == V_315 ) ;
F_10 ( F_11 ( V_8 ) ) ;
if ( V_21 -> V_22 != NULL ) {
if ( ( V_299 && V_21 -> V_119 & ( V_299 - 1 ) ) ||
( V_158 && ! V_21 -> V_158 ) ) {
F_192 ( V_21 -> V_24 ,
L_13
L_14
L_15 ,
V_21 -> V_119 , V_299 ,
V_158 ,
V_21 -> V_158 ) ;
V_14 = F_98 ( V_21 ) ;
if ( V_14 )
return V_14 ;
}
}
if ( V_21 -> V_22 == NULL ) {
V_14 = F_99 ( V_21 , V_299 ,
V_158 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_21 -> V_24 ++ == 0 ) {
if ( ! V_21 -> V_23 )
F_101 ( & V_21 -> V_159 ,
& V_2 -> V_4 . V_219 ) ;
}
V_21 -> V_316 |= V_158 ;
F_10 ( F_11 ( V_8 ) ) ;
return 0 ;
}
void
F_87 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
F_10 ( F_11 ( V_8 ) ) ;
F_123 ( V_21 -> V_24 == 0 ) ;
F_123 ( V_21 -> V_22 == NULL ) ;
if ( -- V_21 -> V_24 == 0 ) {
if ( ! V_21 -> V_23 )
F_101 ( & V_21 -> V_159 ,
& V_2 -> V_4 . V_160 ) ;
V_21 -> V_316 = false ;
}
F_10 ( F_11 ( V_8 ) ) ;
}
int
F_220 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_317 * args = V_34 ;
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
if ( V_21 -> V_191 != V_192 ) {
F_107 ( L_16 ) ;
V_14 = - V_38 ;
goto V_110;
}
if ( V_21 -> V_318 != NULL && V_21 -> V_318 != V_36 ) {
F_107 ( L_17 ,
args -> V_48 ) ;
V_14 = - V_38 ;
goto V_110;
}
V_21 -> V_319 ++ ;
V_21 -> V_318 = V_36 ;
if ( V_21 -> V_319 == 1 ) {
V_14 = F_86 ( V_21 , args -> V_299 , true ) ;
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
F_221 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_317 * args = V_34 ;
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
if ( V_21 -> V_318 != V_36 ) {
F_107 ( L_18 ,
args -> V_48 ) ;
V_14 = - V_38 ;
goto V_110;
}
V_21 -> V_319 -- ;
if ( V_21 -> V_319 == 0 ) {
V_21 -> V_318 = NULL ;
F_87 ( V_21 ) ;
}
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
struct V_320 * args = V_34 ;
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
args -> V_321 = V_21 -> V_23 ;
if ( args -> V_321 ) {
if ( V_21 -> V_50 . V_132 & V_137 ) {
V_14 = F_168 ( V_21 -> V_203 ,
0 , V_21 -> V_50 . V_132 ) ;
} else if ( V_21 -> V_203 -> V_236 ==
V_21 -> V_207 ) {
struct V_225 * V_226 ;
V_226 = F_105 ( sizeof( * V_226 ) , V_177 ) ;
if ( V_226 )
V_14 = F_143 ( V_21 -> V_203 , NULL , V_226 ) ;
else
V_14 = - V_49 ;
}
F_158 ( V_21 -> V_203 ) ;
args -> V_321 = V_21 -> V_23 ;
}
F_28 ( & V_21 -> V_50 ) ;
V_113:
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_223 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_233 )
{
return F_218 ( V_8 , V_233 ) ;
}
int
F_224 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_233 )
{
struct V_322 * args = V_34 ;
struct V_20 * V_21 ;
int V_14 ;
switch ( args -> V_191 ) {
case V_201 :
case V_192 :
break;
default:
return - V_38 ;
}
V_14 = F_8 ( V_8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_62 ( F_63 ( V_8 , V_233 , args -> V_48 ) ) ;
if ( & V_21 -> V_50 == NULL ) {
V_14 = - V_112 ;
goto V_113;
}
if ( V_21 -> V_24 ) {
V_14 = - V_38 ;
goto V_110;
}
if ( V_21 -> V_191 != V_200 )
V_21 -> V_191 = args -> V_191 ;
if ( F_138 ( V_21 ) &&
V_21 -> V_22 == NULL )
F_136 ( V_21 ) ;
args -> V_323 = V_21 -> V_191 != V_200 ;
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
V_21 = F_105 ( sizeof( * V_21 ) , V_177 ) ;
if ( V_21 == NULL )
return NULL ;
if ( F_225 ( V_8 , & V_21 -> V_50 , V_3 ) != 0 ) {
F_27 ( V_21 ) ;
return NULL ;
}
V_81 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
F_226 ( V_81 , V_324 | V_325 ) ;
F_1 ( V_2 , V_3 ) ;
V_21 -> V_50 . V_132 = V_133 ;
V_21 -> V_50 . V_136 = V_133 ;
V_21 -> V_310 = V_311 ;
V_21 -> V_50 . V_326 = NULL ;
V_21 -> V_211 = V_212 ;
F_227 ( & V_21 -> V_159 ) ;
F_227 ( & V_21 -> V_266 ) ;
F_227 ( & V_21 -> V_206 ) ;
F_227 ( & V_21 -> V_327 ) ;
F_227 ( & V_21 -> V_220 ) ;
V_21 -> V_191 = V_192 ;
V_21 -> V_158 = true ;
return V_21 ;
}
int F_228 ( struct V_141 * V_21 )
{
F_229 () ;
return 0 ;
}
static void F_164 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
T_2 * V_2 = V_8 -> V_9 ;
int V_14 ;
V_14 = F_98 ( V_21 ) ;
if ( V_14 == - V_165 ) {
F_230 ( & V_21 -> V_159 ,
& V_2 -> V_4 . V_248 ) ;
return;
}
F_231 ( V_21 ) ;
if ( V_21 -> V_50 . V_176 . V_175 )
F_113 ( V_21 ) ;
F_26 ( & V_21 -> V_50 ) ;
F_2 ( V_2 , V_21 -> V_50 . V_3 ) ;
F_27 ( V_21 -> V_313 ) ;
F_27 ( V_21 -> V_328 ) ;
F_27 ( V_21 ) ;
}
void F_232 ( struct V_141 * V_329 )
{
struct V_20 * V_21 = F_62 ( V_329 ) ;
struct V_7 * V_8 = V_21 -> V_50 . V_8 ;
while ( V_21 -> V_24 > 0 )
F_87 ( V_21 ) ;
if ( V_21 -> V_131 )
F_233 ( V_8 , V_21 ) ;
F_164 ( V_21 ) ;
}
int
F_234 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_14 ;
F_18 ( & V_8 -> V_19 ) ;
if ( V_2 -> V_4 . V_237 ) {
F_19 ( & V_8 -> V_19 ) ;
return 0 ;
}
V_14 = F_183 ( V_8 ) ;
if ( V_14 ) {
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
if ( ! F_235 ( V_8 , V_330 ) ) {
V_14 = F_236 ( V_8 , false ) ;
if ( V_14 ) {
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
}
F_155 ( V_8 ) ;
V_2 -> V_4 . V_237 = 1 ;
F_237 ( & V_2 -> V_238 ) ;
F_238 ( V_8 ) ;
F_239 ( V_8 ) ;
F_19 ( & V_8 -> V_19 ) ;
F_240 ( & V_2 -> V_4 . V_241 ) ;
return 0 ;
}
int
F_241 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_14 ;
V_14 = F_242 ( V_8 ) ;
if ( V_14 )
return V_14 ;
if ( F_243 ( V_8 ) ) {
V_14 = F_244 ( V_8 ) ;
if ( V_14 )
goto V_331;
}
if ( F_245 ( V_8 ) ) {
V_14 = F_246 ( V_8 ) ;
if ( V_14 )
goto V_332;
}
V_2 -> V_265 = 1 ;
return 0 ;
V_332:
F_247 ( & V_2 -> V_203 [ V_333 ] ) ;
V_331:
F_247 ( & V_2 -> V_203 [ V_334 ] ) ;
return V_14 ;
}
void
F_239 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_243 ; V_101 ++ )
F_247 ( & V_2 -> V_203 [ V_101 ] ) ;
}
int
F_248 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_233 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_14 , V_101 ;
if ( F_235 ( V_8 , V_330 ) )
return 0 ;
if ( F_4 ( & V_2 -> V_4 . V_15 ) ) {
F_107 ( L_19 ) ;
F_249 ( & V_2 -> V_4 . V_15 , 0 ) ;
}
F_18 ( & V_8 -> V_19 ) ;
V_2 -> V_4 . V_237 = 0 ;
V_14 = F_241 ( V_8 ) ;
if ( V_14 != 0 ) {
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
F_123 ( ! F_135 ( & V_2 -> V_4 . V_205 ) ) ;
F_123 ( ! F_135 ( & V_2 -> V_4 . V_218 ) ) ;
F_123 ( ! F_135 ( & V_2 -> V_4 . V_160 ) ) ;
for ( V_101 = 0 ; V_101 < V_243 ; V_101 ++ ) {
F_123 ( ! F_135 ( & V_2 -> V_203 [ V_101 ] . V_205 ) ) ;
F_123 ( ! F_135 ( & V_2 -> V_203 [ V_101 ] . V_231 ) ) ;
}
F_19 ( & V_8 -> V_19 ) ;
V_14 = F_250 ( V_8 ) ;
if ( V_14 )
goto V_335;
return 0 ;
V_335:
F_18 ( & V_8 -> V_19 ) ;
F_239 ( V_8 ) ;
V_2 -> V_4 . V_237 = 1 ;
F_19 ( & V_8 -> V_19 ) ;
return V_14 ;
}
int
F_251 ( struct V_7 * V_8 , void * V_34 ,
struct V_35 * V_233 )
{
if ( F_235 ( V_8 , V_330 ) )
return 0 ;
F_252 ( V_8 ) ;
return F_234 ( V_8 ) ;
}
void
F_253 ( struct V_7 * V_8 )
{
int V_14 ;
if ( F_235 ( V_8 , V_330 ) )
return;
V_14 = F_234 ( V_8 ) ;
if ( V_14 )
F_107 ( L_20 , V_14 ) ;
}
static void
F_254 ( struct V_202 * V_203 )
{
F_227 ( & V_203 -> V_205 ) ;
F_227 ( & V_203 -> V_231 ) ;
F_227 ( & V_203 -> V_220 ) ;
}
void
F_255 ( struct V_7 * V_8 )
{
int V_101 ;
T_2 * V_2 = V_8 -> V_9 ;
F_227 ( & V_2 -> V_4 . V_205 ) ;
F_227 ( & V_2 -> V_4 . V_218 ) ;
F_227 ( & V_2 -> V_4 . V_160 ) ;
F_227 ( & V_2 -> V_4 . V_219 ) ;
F_227 ( & V_2 -> V_4 . V_217 ) ;
F_227 ( & V_2 -> V_4 . V_248 ) ;
F_227 ( & V_2 -> V_4 . V_266 ) ;
for ( V_101 = 0 ; V_101 < V_243 ; V_101 ++ )
F_254 ( & V_2 -> V_203 [ V_101 ] ) ;
for ( V_101 = 0 ; V_101 < 16 ; V_101 ++ )
F_227 ( & V_2 -> V_215 [ V_101 ] . V_216 ) ;
F_256 ( & V_2 -> V_4 . V_241 ,
F_165 ) ;
F_257 ( & V_2 -> V_12 ) ;
if ( F_258 ( V_8 ) ) {
T_5 V_336 = F_171 ( V_337 ) ;
if ( ! ( V_336 & V_338 ) ) {
V_336 = V_338 | ( V_338 << V_339 ) ;
F_196 ( V_337 , V_336 ) ;
}
}
V_2 -> V_340 = V_341 ;
if ( ! F_235 ( V_8 , V_330 ) )
V_2 -> V_293 = 3 ;
if ( F_116 ( V_8 ) -> V_190 >= 4 || F_259 ( V_8 ) || F_260 ( V_8 ) || F_119 ( V_8 ) )
V_2 -> V_294 = 16 ;
else
V_2 -> V_294 = 8 ;
for ( V_101 = 0 ; V_101 < V_2 -> V_294 ; V_101 ++ ) {
F_156 ( V_8 , & V_2 -> V_215 [ V_101 ] ) ;
}
F_261 ( V_8 ) ;
F_262 ( & V_2 -> V_342 ) ;
V_2 -> V_4 . V_261 = true ;
V_2 -> V_4 . V_343 . V_344 = V_345 ;
V_2 -> V_4 . V_343 . V_346 = V_347 ;
F_263 ( & V_2 -> V_4 . V_343 ) ;
}
static int F_264 ( struct V_7 * V_8 ,
int V_348 , int V_3 , int V_349 )
{
T_2 * V_2 = V_8 -> V_9 ;
struct V_350 * V_131 ;
int V_14 ;
if ( V_2 -> V_4 . V_351 [ V_348 - 1 ] || ! V_3 )
return 0 ;
V_131 = F_105 ( sizeof( struct V_350 ) , V_177 ) ;
if ( ! V_131 )
return - V_49 ;
V_131 -> V_348 = V_348 ;
V_131 -> V_48 = F_265 ( V_8 , V_3 , V_349 ) ;
if ( ! V_131 -> V_48 ) {
V_14 = - V_49 ;
goto V_352;
}
#ifdef F_266
F_267 ( ( unsigned long ) V_131 -> V_48 -> V_94 , V_131 -> V_48 -> V_3 / V_33 ) ;
#endif
V_2 -> V_4 . V_351 [ V_348 - 1 ] = V_131 ;
return 0 ;
V_352:
F_27 ( V_131 ) ;
return V_14 ;
}
static void F_268 ( struct V_7 * V_8 , int V_348 )
{
T_2 * V_2 = V_8 -> V_9 ;
struct V_350 * V_131 ;
if ( ! V_2 -> V_4 . V_351 [ V_348 - 1 ] )
return;
V_131 = V_2 -> V_4 . V_351 [ V_348 - 1 ] ;
if ( V_131 -> V_353 ) {
F_233 ( V_8 , V_131 -> V_353 ) ;
}
#ifdef F_266
F_269 ( ( unsigned long ) V_131 -> V_48 -> V_94 , V_131 -> V_48 -> V_3 / V_33 ) ;
#endif
F_270 ( V_8 , V_131 -> V_48 ) ;
F_27 ( V_131 ) ;
V_2 -> V_4 . V_351 [ V_348 - 1 ] = NULL ;
}
void F_271 ( struct V_7 * V_8 )
{
int V_101 ;
for ( V_101 = V_354 ; V_101 <= V_355 ; V_101 ++ )
F_268 ( V_8 , V_101 ) ;
}
void F_233 ( struct V_7 * V_8 ,
struct V_20 * V_21 )
{
struct V_80 * V_81 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
char * V_94 ;
int V_101 ;
int V_196 ;
if ( ! V_21 -> V_131 )
return;
V_94 = V_21 -> V_131 -> V_48 -> V_94 ;
V_196 = V_21 -> V_50 . V_3 / V_33 ;
for ( V_101 = 0 ; V_101 < V_196 ; V_101 ++ ) {
struct V_61 * V_61 = F_43 ( V_81 , V_101 ) ;
if ( ! F_44 ( V_61 ) ) {
char * V_356 = F_46 ( V_61 ) ;
memcpy ( V_356 , V_94 + V_101 * V_33 , V_33 ) ;
F_48 ( V_356 ) ;
F_210 ( & V_61 , 1 ) ;
F_79 ( V_61 ) ;
F_49 ( V_61 ) ;
F_50 ( V_61 ) ;
}
}
F_214 () ;
V_21 -> V_131 -> V_353 = NULL ;
V_21 -> V_131 = NULL ;
}
int
F_272 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
int V_348 ,
int V_349 )
{
struct V_80 * V_81 = V_21 -> V_50 . V_82 -> V_83 . V_84 -> V_85 -> V_86 ;
T_2 * V_2 = V_8 -> V_9 ;
int V_14 = 0 ;
int V_196 ;
int V_101 ;
if ( V_348 > V_355 )
return - V_38 ;
if ( V_21 -> V_131 ) {
if ( V_21 -> V_131 -> V_348 == V_348 )
return 0 ;
F_233 ( V_8 , V_21 ) ;
}
if ( ! V_2 -> V_4 . V_351 [ V_348 - 1 ] ) {
V_14 = F_264 ( V_8 , V_348 ,
V_21 -> V_50 . V_3 , V_349 ) ;
if ( V_14 ) {
F_107 ( L_21 ,
V_348 , V_21 -> V_50 . V_3 ) ;
return V_14 ;
}
}
V_21 -> V_131 = V_2 -> V_4 . V_351 [ V_348 - 1 ] ;
V_21 -> V_131 -> V_353 = V_21 ;
V_196 = V_21 -> V_50 . V_3 / V_33 ;
for ( V_101 = 0 ; V_101 < V_196 ; V_101 ++ ) {
struct V_61 * V_61 ;
char * V_356 , * V_357 ;
V_61 = F_43 ( V_81 , V_101 ) ;
if ( F_44 ( V_61 ) )
return F_45 ( V_61 ) ;
V_357 = F_46 ( V_61 ) ;
V_356 = V_21 -> V_131 -> V_48 -> V_94 + ( V_101 * V_33 ) ;
memcpy ( V_356 , V_357 , V_33 ) ;
F_48 ( V_357 ) ;
F_49 ( V_61 ) ;
F_50 ( V_61 ) ;
}
return 0 ;
}
static int
F_85 ( struct V_7 * V_8 ,
struct V_20 * V_21 ,
struct V_122 * args ,
struct V_35 * V_233 )
{
void * V_94 = V_21 -> V_131 -> V_48 -> V_94 + args -> V_88 ;
char T_8 * V_89 = ( char T_8 * ) ( V_92 ) args -> V_93 ;
if ( F_67 ( V_94 , V_89 , args -> V_3 ) ) {
unsigned long V_117 ;
F_19 ( & V_8 -> V_19 ) ;
V_117 = F_273 ( V_94 , V_89 , args -> V_3 ) ;
F_18 ( & V_8 -> V_19 ) ;
if ( V_117 )
return - V_96 ;
}
F_214 () ;
return 0 ;
}
void F_274 ( struct V_7 * V_8 , struct V_35 * V_36 )
{
struct V_232 * V_233 = V_36 -> V_234 ;
F_146 ( & V_233 -> V_4 . V_17 ) ;
while ( ! F_135 ( & V_233 -> V_4 . V_231 ) ) {
struct V_225 * V_226 ;
V_226 = F_154 ( & V_233 -> V_4 . V_231 ,
struct V_225 ,
V_235 ) ;
F_152 ( & V_226 -> V_235 ) ;
V_226 -> V_233 = NULL ;
}
F_147 ( & V_233 -> V_4 . V_17 ) ;
}
static int
F_275 ( struct V_7 * V_8 )
{
T_2 * V_2 = V_8 -> V_9 ;
int V_269 ;
V_269 = F_135 ( & V_2 -> V_4 . V_218 ) &&
F_135 ( & V_2 -> V_4 . V_205 ) ;
return ! V_269 ;
}
static int
V_345 ( struct V_358 * V_358 , struct V_359 * V_360 )
{
struct V_1 * V_2 =
F_166 ( V_358 ,
struct V_1 ,
V_4 . V_343 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_20 * V_21 , * V_223 ;
int V_361 = V_360 -> V_361 ;
int V_362 ;
if ( ! F_167 ( & V_8 -> V_19 ) )
return 0 ;
if ( V_361 == 0 ) {
V_362 = 0 ;
F_21 (obj,
&dev_priv->mm.inactive_list,
mm_list)
V_362 ++ ;
F_19 ( & V_8 -> V_19 ) ;
return V_362 / 100 * V_363 ;
}
V_364:
F_163 ( V_8 ) ;
F_140 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( F_138 ( V_21 ) ) {
if ( F_98 ( V_21 ) == 0 &&
-- V_361 == 0 )
break;
}
}
V_362 = 0 ;
F_140 (obj, next,
&dev_priv->mm.inactive_list,
mm_list) {
if ( V_361 &&
F_98 ( V_21 ) == 0 )
V_361 -- ;
else
V_362 ++ ;
}
if ( V_361 && F_275 ( V_8 ) ) {
if ( F_183 ( V_8 ) == 0 )
goto V_364;
}
F_19 ( & V_8 -> V_19 ) ;
return V_362 / 100 * V_363 ;
}
