void F_1 ( struct V_1 * V_2 , T_1 * V_3 , void * V_4 )
{
V_2 -> V_5 = V_3 ;
V_2 -> V_6 = V_4 ;
}
inline void F_2 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_7 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_8 , V_9 , V_10 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_9 , & V_2 -> V_8 ) ;
F_9 () ;
F_10 ( & V_2 -> V_8 , V_9 ) ;
}
void F_11 ( struct V_11 * V_11 ,
bool * V_12 , bool * V_13 )
{
struct V_1 * V_14 , * V_2 ;
* V_12 = false ;
* V_13 = false ;
F_12 ( ! F_13 ( V_11 ) ) ;
if ( ! F_14 ( V_11 ) )
return;
if ( F_15 ( V_11 ) )
* V_13 = true ;
V_14 = F_16 ( V_11 ) ;
V_2 = V_14 ;
do {
if ( F_17 ( V_2 ) )
* V_13 = true ;
if ( F_18 ( V_2 ) )
* V_12 = true ;
V_2 = V_2 -> V_15 ;
} while ( V_2 != V_14 );
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_8 , V_9 , V_10 ) ;
}
static void
F_21 ( struct V_11 * V_11 )
{
F_22 ( V_11 ) ;
F_23 ( V_11 , 0 ) ;
F_24 ( V_11 ) ;
}
static void F_25 ( struct V_1 * V_2 , char * V_16 )
{
if ( ! F_26 ( V_17 , & V_2 -> V_8 ) )
F_27 ( V_18
L_1 ,
V_2 -> V_19 , ( unsigned long long ) V_2 -> V_20 , V_16 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_21 )
{
if ( V_21 ) {
F_29 ( V_2 ) ;
} else {
F_30 ( V_2 ) ;
}
F_7 ( V_2 ) ;
}
void F_31 ( struct V_1 * V_2 , int V_21 )
{
F_28 ( V_2 , V_21 ) ;
F_32 ( V_2 ) ;
}
void F_33 ( struct V_1 * V_2 , int V_21 )
{
if ( V_21 ) {
F_29 ( V_2 ) ;
} else {
F_25 ( V_2 , L_2 ) ;
F_34 ( V_2 ) ;
F_30 ( V_2 ) ;
}
F_7 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static struct V_1 *
F_35 ( struct V_22 * V_23 , T_2 V_24 )
{
struct V_25 * V_26 = V_23 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_1 * V_30 = NULL ;
T_3 V_31 ;
struct V_1 * V_2 ;
struct V_1 * V_14 ;
struct V_11 * V_11 ;
int V_32 = 1 ;
V_31 = V_24 >> ( V_33 - V_26 -> V_34 ) ;
V_11 = F_36 ( V_28 , V_31 , V_35 ) ;
if ( ! V_11 )
goto V_36;
F_37 ( & V_28 -> V_37 ) ;
if ( ! F_14 ( V_11 ) )
goto V_38;
V_14 = F_16 ( V_11 ) ;
V_2 = V_14 ;
do {
if ( ! F_38 ( V_2 ) )
V_32 = 0 ;
else if ( V_2 -> V_20 == V_24 ) {
V_30 = V_2 ;
F_39 ( V_2 ) ;
goto V_38;
}
V_2 = V_2 -> V_15 ;
} while ( V_2 != V_14 );
if ( V_32 ) {
F_40 ( L_3
L_4 ,
( unsigned long long ) V_24 ,
( unsigned long long ) V_2 -> V_20 ) ;
F_40 ( L_5 ,
V_2 -> V_8 , V_2 -> V_39 ) ;
F_40 ( L_6 , V_23 ,
1 << V_26 -> V_34 ) ;
}
V_38:
F_41 ( & V_28 -> V_37 ) ;
F_24 ( V_11 ) ;
V_36:
return V_30 ;
}
static void F_42 ( void )
{
struct V_40 * V_41 ;
int V_42 ;
F_43 ( 1024 , V_43 ) ;
F_44 () ;
F_45 (nid) {
V_41 = F_46 ( F_47 ( V_42 , V_44 ) ,
F_48 ( V_44 ) , NULL ) ;
if ( V_41 -> V_45 )
F_49 ( F_47 ( V_42 , V_44 ) , 0 ,
V_44 , NULL ) ;
}
}
static void F_50 ( struct V_1 * V_2 , int V_21 )
{
unsigned long V_46 ;
struct V_1 * V_47 ;
struct V_1 * V_48 ;
struct V_11 * V_11 ;
int V_49 = 1 ;
F_12 ( ! F_51 ( V_2 ) ) ;
V_11 = V_2 -> V_7 ;
if ( V_21 ) {
F_29 ( V_2 ) ;
} else {
F_30 ( V_2 ) ;
F_25 ( V_2 , L_7 ) ;
F_52 ( V_11 ) ;
}
V_47 = F_16 ( V_11 ) ;
F_53 ( V_46 ) ;
F_54 ( V_50 , & V_47 -> V_8 ) ;
F_55 ( V_2 ) ;
F_7 ( V_2 ) ;
V_48 = V_2 ;
do {
if ( ! F_56 ( V_48 ) )
V_49 = 0 ;
if ( F_51 ( V_48 ) ) {
F_12 ( ! F_17 ( V_48 ) ) ;
goto V_51;
}
V_48 = V_48 -> V_15 ;
} while ( V_48 != V_2 );
F_57 ( V_50 , & V_47 -> V_8 ) ;
F_58 ( V_46 ) ;
if ( V_49 && ! F_59 ( V_11 ) )
F_60 ( V_11 ) ;
F_61 ( V_11 ) ;
return;
V_51:
F_57 ( V_50 , & V_47 -> V_8 ) ;
F_58 ( V_46 ) ;
return;
}
void F_62 ( struct V_1 * V_2 , int V_21 )
{
unsigned long V_46 ;
struct V_1 * V_47 ;
struct V_1 * V_48 ;
struct V_11 * V_11 ;
F_12 ( ! F_63 ( V_2 ) ) ;
V_11 = V_2 -> V_7 ;
if ( V_21 ) {
F_29 ( V_2 ) ;
} else {
F_25 ( V_2 , L_8 ) ;
F_34 ( V_2 ) ;
F_30 ( V_2 ) ;
F_52 ( V_11 ) ;
}
V_47 = F_16 ( V_11 ) ;
F_53 ( V_46 ) ;
F_54 ( V_50 , & V_47 -> V_8 ) ;
F_64 ( V_2 ) ;
F_7 ( V_2 ) ;
V_48 = V_2 -> V_15 ;
while ( V_48 != V_2 ) {
if ( F_63 ( V_48 ) ) {
F_12 ( ! F_17 ( V_48 ) ) ;
goto V_51;
}
V_48 = V_48 -> V_15 ;
}
F_57 ( V_50 , & V_47 -> V_8 ) ;
F_58 ( V_46 ) ;
F_65 ( V_11 ) ;
return;
V_51:
F_57 ( V_50 , & V_47 -> V_8 ) ;
F_58 ( V_46 ) ;
return;
}
static void F_66 ( struct V_1 * V_2 )
{
V_2 -> V_5 = F_50 ;
F_67 ( V_2 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
V_2 -> V_5 = V_3 ;
F_69 ( V_2 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
F_68 ( V_2 , F_62 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_72 ( & V_2 -> V_52 ) ;
F_73 ( ! V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
}
int F_74 ( struct V_25 * V_25 )
{
return ! F_75 ( & V_25 -> V_54 . V_55 ) ;
}
static int F_76 ( T_4 * V_56 , struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_57 * V_59 ;
int V_60 = 0 ;
F_37 ( V_56 ) ;
V_61:
F_77 (p, list) {
V_2 = F_78 ( V_59 ) ;
if ( F_17 ( V_2 ) ) {
F_39 ( V_2 ) ;
F_41 ( V_56 ) ;
F_79 ( V_2 ) ;
if ( ! F_56 ( V_2 ) )
V_60 = - V_62 ;
F_80 ( V_2 ) ;
F_37 ( V_56 ) ;
goto V_61;
}
}
F_41 ( V_56 ) ;
return V_60 ;
}
static void F_81 ( struct V_63 * V_64 , void * V_65 )
{
while ( V_64 -> V_66 && ! F_82 ( V_64 -> V_66 , V_64 ) )
F_40 ( V_67 L_9 , V_64 -> V_66 ) ;
}
static void F_83 ( struct V_68 * V_69 )
{
F_84 ( F_81 , NULL ) ;
F_85 ( V_69 ) ;
F_40 ( V_67 L_10 ) ;
}
void F_86 ( void )
{
struct V_68 * V_69 ;
V_69 = F_87 ( sizeof( * V_69 ) , V_70 ) ;
if ( V_69 ) {
F_88 ( V_69 , F_83 ) ;
F_89 ( V_69 ) ;
}
}
int F_90 ( struct V_27 * V_71 )
{
struct V_27 * V_72 = V_71 -> V_73 ;
if ( V_72 == NULL || F_75 ( & V_71 -> V_55 ) )
return 0 ;
return F_91 ( & V_72 -> V_37 ,
& V_71 -> V_55 ) ;
}
void F_92 ( struct V_22 * V_23 ,
T_2 V_74 , unsigned V_75 )
{
struct V_1 * V_2 = F_93 ( V_23 , V_74 + 1 , V_75 ) ;
if ( V_2 ) {
if ( F_18 ( V_2 ) )
F_94 ( V_76 , 0 , 1 , & V_2 ) ;
F_32 ( V_2 ) ;
}
}
void F_95 ( struct V_1 * V_2 , struct V_25 * V_25 )
{
struct V_27 * V_71 = V_25 -> V_29 ;
struct V_27 * V_72 = V_2 -> V_7 -> V_71 ;
F_96 ( V_2 ) ;
if ( ! V_71 -> V_73 ) {
V_71 -> V_73 = V_72 ;
} else {
F_12 ( V_71 -> V_73 != V_72 ) ;
}
if ( ! V_2 -> V_53 ) {
F_37 ( & V_72 -> V_37 ) ;
F_97 ( & V_2 -> V_52 ,
& V_71 -> V_55 ) ;
V_2 -> V_53 = V_71 ;
F_41 ( & V_72 -> V_37 ) ;
}
}
static void F_98 ( struct V_11 * V_11 , struct V_27 * V_71 ,
int V_77 )
{
unsigned long V_46 ;
F_99 ( & V_71 -> V_78 , V_46 ) ;
if ( V_11 -> V_71 ) {
F_100 ( V_77 && ! F_101 ( V_11 ) ) ;
F_102 ( V_11 , V_71 ) ;
F_103 ( & V_71 -> V_79 ,
F_104 ( V_11 ) , V_80 ) ;
}
F_105 ( & V_71 -> V_78 , V_46 ) ;
}
int F_106 ( struct V_11 * V_11 )
{
int V_81 ;
struct V_27 * V_71 = F_107 ( V_11 ) ;
if ( F_108 ( ! V_71 ) )
return ! F_109 ( V_11 ) ;
F_37 ( & V_71 -> V_37 ) ;
if ( F_14 ( V_11 ) ) {
struct V_1 * V_14 = F_16 ( V_11 ) ;
struct V_1 * V_2 = V_14 ;
do {
F_110 ( V_2 ) ;
V_2 = V_2 -> V_15 ;
} while ( V_2 != V_14 );
}
F_111 ( V_11 ) ;
V_81 = ! F_109 ( V_11 ) ;
F_41 ( & V_71 -> V_37 ) ;
if ( V_81 )
F_98 ( V_11 , V_71 , 1 ) ;
F_112 ( V_11 ) ;
if ( V_81 )
F_113 ( V_71 -> V_82 , V_83 ) ;
return V_81 ;
}
static int F_91 ( T_4 * V_56 , struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_57 V_48 ;
struct V_27 * V_71 ;
int V_60 = 0 , V_84 ;
struct V_85 V_86 ;
F_114 ( & V_48 ) ;
F_115 ( & V_86 ) ;
F_37 ( V_56 ) ;
while ( ! F_75 ( V_58 ) ) {
V_2 = F_78 ( V_58 -> V_87 ) ;
V_71 = V_2 -> V_53 ;
F_71 ( V_2 ) ;
F_116 () ;
if ( F_18 ( V_2 ) || F_17 ( V_2 ) ) {
F_117 ( & V_2 -> V_52 , & V_48 ) ;
V_2 -> V_53 = V_71 ;
if ( F_18 ( V_2 ) ) {
F_39 ( V_2 ) ;
F_41 ( V_56 ) ;
F_118 ( V_2 , V_88 ) ;
F_80 ( V_2 ) ;
F_37 ( V_56 ) ;
}
}
}
F_41 ( V_56 ) ;
F_119 ( & V_86 ) ;
F_37 ( V_56 ) ;
while ( ! F_75 ( & V_48 ) ) {
V_2 = F_78 ( V_48 . V_89 ) ;
F_39 ( V_2 ) ;
V_71 = V_2 -> V_53 ;
F_71 ( V_2 ) ;
F_116 () ;
if ( F_18 ( V_2 ) ) {
F_117 ( & V_2 -> V_52 ,
& V_71 -> V_55 ) ;
V_2 -> V_53 = V_71 ;
}
F_41 ( V_56 ) ;
F_79 ( V_2 ) ;
if ( ! F_56 ( V_2 ) )
V_60 = - V_62 ;
F_80 ( V_2 ) ;
F_37 ( V_56 ) ;
}
F_41 ( V_56 ) ;
V_84 = F_76 ( V_56 , V_58 ) ;
if ( V_60 )
return V_60 ;
else
return V_84 ;
}
void F_120 ( struct V_25 * V_25 )
{
if ( F_74 ( V_25 ) ) {
struct V_27 * V_71 = & V_25 -> V_54 ;
struct V_57 * V_58 = & V_71 -> V_55 ;
struct V_27 * V_72 = V_71 -> V_73 ;
F_37 ( & V_72 -> V_37 ) ;
while ( ! F_75 ( V_58 ) )
F_71 ( F_78 ( V_58 -> V_87 ) ) ;
F_41 ( & V_72 -> V_37 ) ;
}
}
int F_121 ( struct V_25 * V_25 )
{
int V_30 = 1 ;
if ( F_74 ( V_25 ) ) {
struct V_27 * V_71 = & V_25 -> V_54 ;
struct V_57 * V_58 = & V_71 -> V_55 ;
struct V_27 * V_72 = V_71 -> V_73 ;
F_37 ( & V_72 -> V_37 ) ;
while ( ! F_75 ( V_58 ) ) {
struct V_1 * V_2 = F_78 ( V_58 -> V_87 ) ;
if ( F_18 ( V_2 ) ) {
V_30 = 0 ;
break;
}
F_71 ( V_2 ) ;
}
F_41 ( & V_72 -> V_37 ) ;
}
return V_30 ;
}
struct V_1 * F_122 ( struct V_11 * V_11 , unsigned long V_90 ,
int V_91 )
{
struct V_1 * V_2 , * V_14 ;
long V_92 ;
V_93:
V_14 = NULL ;
V_92 = V_94 ;
while ( ( V_92 -= V_90 ) >= 0 ) {
V_2 = F_123 ( V_44 ) ;
if ( ! V_2 )
goto V_95;
V_2 -> V_15 = V_14 ;
V_2 -> V_20 = - 1 ;
V_14 = V_2 ;
V_2 -> V_39 = V_90 ;
F_124 ( V_2 , V_11 , V_92 ) ;
}
return V_14 ;
V_95:
if ( V_14 ) {
do {
V_2 = V_14 ;
V_14 = V_14 -> V_15 ;
F_125 ( V_2 ) ;
} while ( V_14 );
}
if ( ! V_91 )
return NULL ;
F_42 () ;
goto V_93;
}
static inline void
F_126 ( struct V_11 * V_11 , struct V_1 * V_14 )
{
struct V_1 * V_2 , * V_96 ;
V_2 = V_14 ;
do {
V_96 = V_2 ;
V_2 = V_2 -> V_15 ;
} while ( V_2 );
V_96 -> V_15 = V_14 ;
F_127 ( V_11 , V_14 ) ;
}
static T_2 F_128 ( struct V_22 * V_23 , unsigned int V_90 )
{
T_2 V_97 = ~ ( ( T_2 ) 0 ) ;
T_5 V_98 = F_129 ( V_23 -> V_26 ) ;
if ( V_98 ) {
unsigned int V_99 = F_130 ( V_90 ) ;
V_97 = ( V_98 >> V_99 ) ;
}
return V_97 ;
}
static T_2
F_131 ( struct V_11 * V_11 , struct V_22 * V_23 ,
T_2 V_24 , int V_90 )
{
struct V_1 * V_14 = F_16 ( V_11 ) ;
struct V_1 * V_2 = V_14 ;
int V_21 = F_101 ( V_11 ) ;
T_2 V_100 = F_128 ( F_132 ( V_23 -> V_26 ) , V_90 ) ;
do {
if ( ! F_38 ( V_2 ) ) {
F_1 ( V_2 , NULL , NULL ) ;
V_2 -> V_19 = V_23 ;
V_2 -> V_20 = V_24 ;
if ( V_21 )
F_29 ( V_2 ) ;
if ( V_24 < V_100 )
F_133 ( V_2 ) ;
}
V_24 ++ ;
V_2 = V_2 -> V_15 ;
} while ( V_2 != V_14 );
return V_100 ;
}
static int
F_134 ( struct V_22 * V_23 , T_2 V_24 ,
T_3 V_31 , int V_90 , int V_99 , T_6 V_101 )
{
struct V_25 * V_25 = V_23 -> V_26 ;
struct V_11 * V_11 ;
struct V_1 * V_2 ;
T_2 V_100 ;
int V_30 = 0 ;
T_6 V_102 ;
V_102 = F_135 ( V_25 -> V_29 , ~ V_103 ) | V_101 ;
V_102 |= V_104 ;
V_11 = F_136 ( V_25 -> V_29 , V_31 , V_102 ) ;
if ( ! V_11 )
return V_30 ;
F_12 ( ! F_13 ( V_11 ) ) ;
if ( F_14 ( V_11 ) ) {
V_2 = F_16 ( V_11 ) ;
if ( V_2 -> V_39 == V_90 ) {
V_100 = F_131 ( V_11 , V_23 ,
( T_2 ) V_31 << V_99 ,
V_90 ) ;
goto V_105;
}
if ( ! F_137 ( V_11 ) )
goto V_106;
}
V_2 = F_122 ( V_11 , V_90 , 0 ) ;
if ( ! V_2 )
goto V_106;
F_37 ( & V_25 -> V_29 -> V_37 ) ;
F_126 ( V_11 , V_2 ) ;
V_100 = F_131 ( V_11 , V_23 , ( T_2 ) V_31 << V_99 ,
V_90 ) ;
F_41 ( & V_25 -> V_29 -> V_37 ) ;
V_105:
V_30 = ( V_24 < V_100 ) ? 1 : - V_107 ;
V_106:
F_61 ( V_11 ) ;
F_24 ( V_11 ) ;
return V_30 ;
}
static int
F_138 ( struct V_22 * V_23 , T_2 V_24 , int V_90 , T_6 V_101 )
{
T_3 V_31 ;
int V_99 ;
V_99 = - 1 ;
do {
V_99 ++ ;
} while ( ( V_90 << V_99 ) < V_94 );
V_31 = V_24 >> V_99 ;
if ( F_108 ( V_31 != V_24 >> V_99 ) ) {
F_40 ( V_18 L_11
L_12 ,
V_108 , ( unsigned long long ) V_24 ,
V_23 ) ;
return - V_62 ;
}
return F_134 ( V_23 , V_24 , V_31 , V_90 , V_99 , V_101 ) ;
}
static struct V_1 *
F_139 ( struct V_22 * V_23 , T_2 V_24 ,
unsigned V_90 , T_6 V_101 )
{
if ( F_108 ( V_90 & ( F_140 ( V_23 ) - 1 ) ||
( V_90 < 512 || V_90 > V_94 ) ) ) {
F_40 ( V_18 L_13 ,
V_90 ) ;
F_40 ( V_18 L_14 ,
F_140 ( V_23 ) ) ;
F_141 () ;
return NULL ;
}
for (; ; ) {
struct V_1 * V_2 ;
int V_30 ;
V_2 = F_93 ( V_23 , V_24 , V_90 ) ;
if ( V_2 )
return V_2 ;
V_30 = F_138 ( V_23 , V_24 , V_90 , V_101 ) ;
if ( V_30 < 0 )
return NULL ;
if ( V_30 == 0 )
F_42 () ;
}
}
void F_96 ( struct V_1 * V_2 )
{
F_100 ( ! F_56 ( V_2 ) ) ;
F_142 ( V_2 ) ;
if ( F_18 ( V_2 ) ) {
F_116 () ;
if ( F_18 ( V_2 ) )
return;
}
if ( ! F_143 ( V_2 ) ) {
struct V_11 * V_11 = V_2 -> V_7 ;
struct V_27 * V_71 = NULL ;
F_111 ( V_11 ) ;
if ( ! F_109 ( V_11 ) ) {
V_71 = F_107 ( V_11 ) ;
if ( V_71 )
F_98 ( V_11 , V_71 , 0 ) ;
}
F_112 ( V_11 ) ;
if ( V_71 )
F_113 ( V_71 -> V_82 , V_83 ) ;
}
}
void F_34 ( struct V_1 * V_2 )
{
F_144 ( V_2 ) ;
if ( V_2 -> V_7 && V_2 -> V_7 -> V_71 )
F_145 ( V_2 -> V_7 -> V_71 , - V_62 ) ;
if ( V_2 -> V_53 )
F_145 ( V_2 -> V_53 , - V_62 ) ;
}
void F_146 ( struct V_1 * V_109 )
{
if ( F_147 ( & V_109 -> V_110 ) ) {
F_32 ( V_109 ) ;
return;
}
F_148 ( 1 , V_18 L_15 ) ;
}
void F_149 ( struct V_1 * V_2 )
{
F_150 ( V_2 ) ;
if ( V_2 -> V_53 ) {
struct V_27 * V_72 = V_2 -> V_7 -> V_71 ;
F_37 ( & V_72 -> V_37 ) ;
F_72 ( & V_2 -> V_52 ) ;
V_2 -> V_53 = NULL ;
F_41 ( & V_72 -> V_37 ) ;
}
F_146 ( V_2 ) ;
}
static struct V_1 * F_151 ( struct V_1 * V_2 )
{
F_152 ( V_2 ) ;
if ( F_56 ( V_2 ) ) {
F_7 ( V_2 ) ;
return V_2 ;
} else {
F_39 ( V_2 ) ;
V_2 -> V_5 = F_31 ;
F_153 ( V_111 , 0 , V_2 ) ;
F_79 ( V_2 ) ;
if ( F_56 ( V_2 ) )
return V_2 ;
}
F_80 ( V_2 ) ;
return NULL ;
}
static inline void F_154 ( void )
{
#ifdef F_155
F_12 ( F_155 () ) ;
#endif
}
static void F_156 ( struct V_1 * V_2 )
{
struct V_1 * V_112 = V_2 ;
struct V_113 * V_114 ;
int V_115 ;
F_154 () ;
F_157 () ;
V_114 = F_158 ( & V_116 ) ;
for ( V_115 = 0 ; V_115 < V_117 ; V_115 ++ ) {
F_159 ( V_112 , V_114 -> V_118 [ V_115 ] ) ;
if ( V_112 == V_2 ) {
F_160 () ;
return;
}
}
F_39 ( V_2 ) ;
F_160 () ;
F_80 ( V_112 ) ;
}
static struct V_1 *
F_161 ( struct V_22 * V_23 , T_2 V_24 , unsigned V_90 )
{
struct V_1 * V_30 = NULL ;
unsigned int V_115 ;
F_154 () ;
F_157 () ;
for ( V_115 = 0 ; V_115 < V_117 ; V_115 ++ ) {
struct V_1 * V_2 = F_162 ( V_116 . V_118 [ V_115 ] ) ;
if ( V_2 && V_2 -> V_20 == V_24 && V_2 -> V_19 == V_23 &&
V_2 -> V_39 == V_90 ) {
if ( V_115 ) {
while ( V_115 ) {
F_163 ( V_116 . V_118 [ V_115 ] ,
F_162 ( V_116 . V_118 [ V_115 - 1 ] ) ) ;
V_115 -- ;
}
F_163 ( V_116 . V_118 [ 0 ] , V_2 ) ;
}
F_39 ( V_2 ) ;
V_30 = V_2 ;
break;
}
}
F_160 () ;
return V_30 ;
}
struct V_1 *
F_93 ( struct V_22 * V_23 , T_2 V_24 , unsigned V_90 )
{
struct V_1 * V_2 = F_161 ( V_23 , V_24 , V_90 ) ;
if ( V_2 == NULL ) {
V_2 = F_35 ( V_23 , V_24 ) ;
if ( V_2 )
F_156 ( V_2 ) ;
} else
F_2 ( V_2 ) ;
return V_2 ;
}
struct V_1 *
F_164 ( struct V_22 * V_23 , T_2 V_24 ,
unsigned V_90 , T_6 V_101 )
{
struct V_1 * V_2 = F_93 ( V_23 , V_24 , V_90 ) ;
F_165 () ;
if ( V_2 == NULL )
V_2 = F_139 ( V_23 , V_24 , V_90 , V_101 ) ;
return V_2 ;
}
void F_166 ( struct V_22 * V_23 , T_2 V_24 , unsigned V_90 )
{
struct V_1 * V_2 = F_167 ( V_23 , V_24 , V_90 ) ;
if ( F_168 ( V_2 ) ) {
F_94 ( V_111 , V_119 , 1 , & V_2 ) ;
F_80 ( V_2 ) ;
}
}
struct V_1 *
F_169 ( struct V_22 * V_23 , T_2 V_24 ,
unsigned V_90 , T_6 V_101 )
{
struct V_1 * V_2 = F_164 ( V_23 , V_24 , V_90 , V_101 ) ;
if ( F_168 ( V_2 ) && ! F_56 ( V_2 ) )
V_2 = F_151 ( V_2 ) ;
return V_2 ;
}
static void F_170 ( void * V_120 )
{
struct V_113 * V_114 = & F_171 ( V_116 ) ;
int V_115 ;
for ( V_115 = 0 ; V_115 < V_117 ; V_115 ++ ) {
F_80 ( V_114 -> V_118 [ V_115 ] ) ;
V_114 -> V_118 [ V_115 ] = NULL ;
}
F_172 ( V_116 ) ;
}
static bool F_173 ( int V_121 , void * V_122 )
{
struct V_113 * V_114 = F_174 ( & V_116 , V_121 ) ;
int V_115 ;
for ( V_115 = 0 ; V_115 < V_117 ; V_115 ++ ) {
if ( V_114 -> V_118 [ V_115 ] )
return 1 ;
}
return 0 ;
}
void F_175 ( void )
{
F_176 ( F_173 , F_170 , NULL , 1 , V_123 ) ;
}
void F_124 ( struct V_1 * V_2 ,
struct V_11 * V_11 , unsigned long V_92 )
{
V_2 -> V_7 = V_11 ;
F_12 ( V_92 >= V_94 ) ;
if ( F_177 ( V_11 ) )
V_2 -> V_124 = ( char * ) ( 0 + V_92 ) ;
else
V_2 -> V_124 = F_178 ( V_11 ) + V_92 ;
}
static void F_179 ( struct V_1 * V_2 )
{
unsigned long V_8 , V_125 ;
F_152 ( V_2 ) ;
F_150 ( V_2 ) ;
V_2 -> V_19 = NULL ;
V_8 = V_2 -> V_8 ;
for (; ; ) {
V_125 = F_180 ( & V_2 -> V_8 , V_8 ,
( V_8 & ~ V_126 ) ) ;
if ( V_125 == V_8 )
break;
V_8 = V_125 ;
}
F_7 ( V_2 ) ;
}
void F_181 ( struct V_11 * V_11 , unsigned int V_92 ,
unsigned int V_127 )
{
struct V_1 * V_14 , * V_2 , * V_87 ;
unsigned int V_128 = 0 ;
unsigned int V_129 = V_127 + V_92 ;
F_12 ( ! F_13 ( V_11 ) ) ;
if ( ! F_14 ( V_11 ) )
goto V_36;
F_12 ( V_129 > V_94 || V_129 < V_127 ) ;
V_14 = F_16 ( V_11 ) ;
V_2 = V_14 ;
do {
unsigned int V_130 = V_128 + V_2 -> V_39 ;
V_87 = V_2 -> V_15 ;
if ( V_130 > V_129 )
goto V_36;
if ( V_92 <= V_128 )
F_179 ( V_2 ) ;
V_128 = V_130 ;
V_2 = V_87 ;
} while ( V_2 != V_14 );
if ( V_92 == 0 )
F_182 ( V_11 , 0 ) ;
V_36:
return;
}
void F_183 ( struct V_11 * V_11 ,
unsigned long V_75 , unsigned long V_8 )
{
struct V_1 * V_2 , * V_14 , * V_96 ;
V_14 = F_122 ( V_11 , V_75 , 1 ) ;
V_2 = V_14 ;
do {
V_2 -> V_8 |= V_8 ;
V_96 = V_2 ;
V_2 = V_2 -> V_15 ;
} while ( V_2 );
V_96 -> V_15 = V_14 ;
F_37 ( & V_11 -> V_71 -> V_37 ) ;
if ( F_101 ( V_11 ) || F_184 ( V_11 ) ) {
V_2 = V_14 ;
do {
if ( F_184 ( V_11 ) )
F_110 ( V_2 ) ;
if ( F_101 ( V_11 ) )
F_29 ( V_2 ) ;
V_2 = V_2 -> V_15 ;
} while ( V_2 != V_14 );
}
F_127 ( V_11 , V_14 ) ;
F_41 ( & V_11 -> V_71 -> V_37 ) ;
}
void F_185 ( struct V_22 * V_23 , T_2 V_24 , T_2 V_131 )
{
struct V_25 * V_26 = V_23 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_132 V_133 ;
T_3 V_31 = V_24 >> ( V_33 - V_26 -> V_34 ) ;
T_3 V_134 ;
int V_115 ;
struct V_1 * V_2 ;
struct V_1 * V_14 ;
V_134 = ( V_24 + V_131 - 1 ) >> ( V_33 - V_26 -> V_34 ) ;
F_186 ( & V_133 , 0 ) ;
while ( V_31 <= V_134 && F_187 ( & V_133 , V_28 , V_31 ,
F_188 ( V_134 - V_31 , ( T_3 ) V_135 - 1 ) + 1 ) ) {
for ( V_115 = 0 ; V_115 < F_189 ( & V_133 ) ; V_115 ++ ) {
struct V_11 * V_11 = V_133 . V_136 [ V_115 ] ;
V_31 = V_11 -> V_31 ;
if ( V_31 > V_134 )
break;
if ( ! F_14 ( V_11 ) )
continue;
F_190 ( V_11 ) ;
if ( ! F_14 ( V_11 ) )
goto F_61;
V_14 = F_16 ( V_11 ) ;
V_2 = V_14 ;
do {
if ( ! F_38 ( V_2 ) || ( V_2 -> V_20 < V_24 ) )
goto V_87;
if ( V_2 -> V_20 >= V_24 + V_131 )
break;
F_150 ( V_2 ) ;
F_79 ( V_2 ) ;
F_191 ( V_2 ) ;
V_87:
V_2 = V_2 -> V_15 ;
} while ( V_2 != V_14 );
F_61:
F_61 ( V_11 ) ;
}
F_192 ( & V_133 ) ;
F_193 () ;
V_31 ++ ;
}
}
static inline int F_194 ( unsigned int V_75 )
{
return F_195 ( V_75 ) ;
}
static struct V_1 * F_196 ( struct V_11 * V_11 , struct V_25 * V_25 , unsigned int V_8 )
{
F_12 ( ! F_13 ( V_11 ) ) ;
if ( ! F_14 ( V_11 ) )
F_183 ( V_11 , 1 << F_197 ( V_25 -> V_34 ) , V_8 ) ;
return F_16 ( V_11 ) ;
}
int F_198 ( struct V_25 * V_25 , struct V_11 * V_11 ,
T_7 * V_137 , struct V_138 * V_139 ,
T_1 * V_3 )
{
int V_60 ;
T_2 V_24 ;
T_2 V_140 ;
struct V_1 * V_2 , * V_14 ;
unsigned int V_75 , V_141 ;
int V_142 = 0 ;
int V_143 = F_199 ( V_139 ) ;
V_14 = F_196 ( V_11 , V_25 ,
( 1 << V_144 ) | ( 1 << V_145 ) ) ;
V_2 = V_14 ;
V_75 = V_2 -> V_39 ;
V_141 = F_194 ( V_75 ) ;
V_24 = ( T_2 ) V_11 -> V_31 << ( V_33 - V_141 ) ;
V_140 = ( F_129 ( V_25 ) - 1 ) >> V_141 ;
do {
if ( V_24 > V_140 ) {
F_150 ( V_2 ) ;
F_29 ( V_2 ) ;
} else if ( ( ! F_38 ( V_2 ) || F_200 ( V_2 ) ) &&
F_18 ( V_2 ) ) {
F_73 ( V_2 -> V_39 != V_75 ) ;
V_60 = V_137 ( V_25 , V_24 , V_2 , 1 ) ;
if ( V_60 )
goto V_146;
F_201 ( V_2 ) ;
if ( F_202 ( V_2 ) ) {
F_203 ( V_2 ) ;
F_204 ( V_2 ) ;
}
}
V_2 = V_2 -> V_15 ;
V_24 ++ ;
} while ( V_2 != V_14 );
do {
if ( ! F_38 ( V_2 ) )
continue;
if ( V_139 -> V_147 != V_148 ) {
F_152 ( V_2 ) ;
} else if ( ! F_205 ( V_2 ) ) {
F_206 ( V_139 , V_11 ) ;
continue;
}
if ( F_207 ( V_2 ) ) {
F_68 ( V_2 , V_3 ) ;
} else {
F_7 ( V_2 ) ;
}
} while ( ( V_2 = V_2 -> V_15 ) != V_14 );
F_12 ( F_15 ( V_11 ) ) ;
F_208 ( V_11 ) ;
do {
struct V_1 * V_87 = V_2 -> V_15 ;
if ( F_63 ( V_2 ) ) {
F_209 ( V_76 , V_143 , V_2 ,
V_25 -> V_149 , V_139 ) ;
V_142 ++ ;
}
V_2 = V_87 ;
} while ( V_2 != V_14 );
F_61 ( V_11 ) ;
V_60 = 0 ;
V_105:
if ( V_142 == 0 ) {
F_65 ( V_11 ) ;
}
return V_60 ;
V_146:
V_2 = V_14 ;
do {
if ( F_38 ( V_2 ) && F_18 ( V_2 ) &&
! F_200 ( V_2 ) ) {
F_152 ( V_2 ) ;
F_68 ( V_2 , V_3 ) ;
} else {
F_150 ( V_2 ) ;
}
} while ( ( V_2 = V_2 -> V_15 ) != V_14 );
F_52 ( V_11 ) ;
F_12 ( F_15 ( V_11 ) ) ;
F_145 ( V_11 -> V_71 , V_60 ) ;
F_208 ( V_11 ) ;
do {
struct V_1 * V_87 = V_2 -> V_15 ;
if ( F_63 ( V_2 ) ) {
F_150 ( V_2 ) ;
F_209 ( V_76 , V_143 , V_2 ,
V_25 -> V_149 , V_139 ) ;
V_142 ++ ;
}
V_2 = V_87 ;
} while ( V_2 != V_14 );
F_61 ( V_11 ) ;
goto V_105;
}
void F_210 ( struct V_11 * V_11 , unsigned V_150 , unsigned V_151 )
{
unsigned int V_152 , V_153 ;
struct V_1 * V_14 , * V_2 ;
F_12 ( ! F_13 ( V_11 ) ) ;
if ( ! F_14 ( V_11 ) )
return;
V_2 = V_14 = F_16 ( V_11 ) ;
V_152 = 0 ;
do {
V_153 = V_152 + V_2 -> V_39 ;
if ( F_202 ( V_2 ) ) {
if ( V_153 > V_150 && V_152 < V_151 ) {
if ( ! F_101 ( V_11 ) ) {
unsigned V_154 , V_90 ;
V_154 = F_211 ( V_150 , V_152 ) ;
V_90 = F_188 ( V_151 , V_153 ) - V_154 ;
F_212 ( V_11 , V_154 , V_90 ) ;
F_29 ( V_2 ) ;
}
F_203 ( V_2 ) ;
F_96 ( V_2 ) ;
}
}
V_152 = V_153 ;
V_2 = V_2 -> V_15 ;
} while ( V_2 != V_14 );
}
static void
F_213 ( struct V_25 * V_25 , T_2 V_24 , struct V_1 * V_2 ,
struct V_155 * V_155 )
{
T_5 V_92 = V_24 << V_25 -> V_34 ;
V_2 -> V_19 = V_155 -> V_23 ;
F_12 ( V_92 >= V_155 -> V_92 + V_155 -> V_127 ) ;
switch ( V_155 -> type ) {
case V_156 :
if ( ! F_56 ( V_2 ) ||
( V_92 >= F_129 ( V_25 ) ) )
F_214 ( V_2 ) ;
break;
case V_157 :
if ( ! F_56 ( V_2 ) ||
( V_92 >= F_129 ( V_25 ) ) )
F_214 ( V_2 ) ;
F_29 ( V_2 ) ;
F_133 ( V_2 ) ;
F_215 ( V_2 ) ;
break;
case V_158 :
F_214 ( V_2 ) ;
F_216 ( V_2 ) ;
case V_159 :
if ( V_92 >= F_129 ( V_25 ) )
F_214 ( V_2 ) ;
V_2 -> V_20 = ( V_155 -> V_160 >> ( V_25 -> V_34 - 9 ) ) +
( ( V_92 - V_155 -> V_92 ) >> V_25 -> V_34 ) ;
F_133 ( V_2 ) ;
break;
}
}
int F_217 ( struct V_11 * V_11 , T_5 V_161 , unsigned V_131 ,
T_7 * V_137 , struct V_155 * V_155 )
{
unsigned V_150 = V_161 & ( V_94 - 1 ) ;
unsigned V_151 = V_150 + V_131 ;
struct V_25 * V_25 = V_11 -> V_71 -> V_82 ;
unsigned V_152 , V_153 ;
T_2 V_24 ;
int V_60 = 0 ;
unsigned V_75 , V_141 ;
struct V_1 * V_2 , * V_14 , * V_162 [ 2 ] , * * V_163 = V_162 ;
F_12 ( ! F_13 ( V_11 ) ) ;
F_12 ( V_150 > V_94 ) ;
F_12 ( V_151 > V_94 ) ;
F_12 ( V_150 > V_151 ) ;
V_14 = F_196 ( V_11 , V_25 , 0 ) ;
V_75 = V_14 -> V_39 ;
V_141 = F_194 ( V_75 ) ;
V_24 = ( T_2 ) V_11 -> V_31 << ( V_33 - V_141 ) ;
for( V_2 = V_14 , V_152 = 0 ; V_2 != V_14 || ! V_152 ;
V_24 ++ , V_152 = V_153 , V_2 = V_2 -> V_15 ) {
V_153 = V_152 + V_75 ;
if ( V_153 <= V_150 || V_152 >= V_151 ) {
if ( F_101 ( V_11 ) ) {
if ( ! F_56 ( V_2 ) )
F_29 ( V_2 ) ;
}
continue;
}
if ( F_202 ( V_2 ) )
F_203 ( V_2 ) ;
if ( ! F_38 ( V_2 ) ) {
F_73 ( V_2 -> V_39 != V_75 ) ;
if ( V_137 ) {
V_60 = V_137 ( V_25 , V_24 , V_2 , 1 ) ;
if ( V_60 )
break;
} else {
F_213 ( V_25 , V_24 , V_2 , V_155 ) ;
}
if ( F_202 ( V_2 ) ) {
F_204 ( V_2 ) ;
if ( F_101 ( V_11 ) ) {
F_203 ( V_2 ) ;
F_29 ( V_2 ) ;
F_96 ( V_2 ) ;
continue;
}
if ( V_153 > V_151 || V_152 < V_150 )
F_218 ( V_11 ,
V_151 , V_153 ,
V_152 , V_150 ) ;
continue;
}
}
if ( F_101 ( V_11 ) ) {
if ( ! F_56 ( V_2 ) )
F_29 ( V_2 ) ;
continue;
}
if ( ! F_56 ( V_2 ) && ! F_200 ( V_2 ) &&
! F_219 ( V_2 ) &&
( V_152 < V_150 || V_153 > V_151 ) ) {
F_94 ( V_111 , 0 , 1 , & V_2 ) ;
* V_163 ++ = V_2 ;
}
}
while( V_163 > V_162 ) {
F_79 ( * -- V_163 ) ;
if ( ! F_56 ( * V_163 ) )
V_60 = - V_62 ;
}
if ( F_108 ( V_60 ) )
F_210 ( V_11 , V_150 , V_151 ) ;
return V_60 ;
}
int F_220 ( struct V_11 * V_11 , T_5 V_161 , unsigned V_131 ,
T_7 * V_137 )
{
return F_217 ( V_11 , V_161 , V_131 , V_137 , NULL ) ;
}
static int F_221 ( struct V_25 * V_25 , struct V_11 * V_11 ,
unsigned V_150 , unsigned V_151 )
{
unsigned V_152 , V_153 ;
int V_164 = 0 ;
unsigned V_75 ;
struct V_1 * V_2 , * V_14 ;
V_2 = V_14 = F_16 ( V_11 ) ;
V_75 = V_2 -> V_39 ;
V_152 = 0 ;
do {
V_153 = V_152 + V_75 ;
if ( V_153 <= V_150 || V_152 >= V_151 ) {
if ( ! F_56 ( V_2 ) )
V_164 = 1 ;
} else {
F_29 ( V_2 ) ;
F_96 ( V_2 ) ;
}
F_203 ( V_2 ) ;
V_152 = V_153 ;
V_2 = V_2 -> V_15 ;
} while ( V_2 != V_14 );
if ( ! V_164 )
F_60 ( V_11 ) ;
return 0 ;
}
int F_222 ( struct V_27 * V_71 , T_5 V_161 , unsigned V_131 ,
unsigned V_46 , struct V_11 * * V_165 , T_7 * V_137 )
{
T_3 V_31 = V_161 >> V_33 ;
struct V_11 * V_11 ;
int V_166 ;
V_11 = F_223 ( V_71 , V_31 , V_46 ) ;
if ( ! V_11 )
return - V_167 ;
V_166 = F_220 ( V_11 , V_161 , V_131 , V_137 ) ;
if ( F_108 ( V_166 ) ) {
F_61 ( V_11 ) ;
F_24 ( V_11 ) ;
V_11 = NULL ;
}
* V_165 = V_11 ;
return V_166 ;
}
int F_224 ( struct V_168 * V_168 , struct V_27 * V_71 ,
T_5 V_161 , unsigned V_131 , unsigned V_169 ,
struct V_11 * V_11 , void * V_170 )
{
struct V_25 * V_25 = V_71 -> V_82 ;
unsigned V_154 ;
V_154 = V_161 & ( V_94 - 1 ) ;
if ( F_108 ( V_169 < V_131 ) ) {
if ( ! F_101 ( V_11 ) )
V_169 = 0 ;
F_210 ( V_11 , V_154 + V_169 , V_154 + V_131 ) ;
}
F_225 ( V_11 ) ;
F_221 ( V_25 , V_11 , V_154 , V_154 + V_169 ) ;
return V_169 ;
}
int F_226 ( struct V_168 * V_168 , struct V_27 * V_71 ,
T_5 V_161 , unsigned V_131 , unsigned V_169 ,
struct V_11 * V_11 , void * V_170 )
{
struct V_25 * V_25 = V_71 -> V_82 ;
T_5 V_171 = V_25 -> V_172 ;
int V_173 = 0 ;
V_169 = F_224 ( V_168 , V_71 , V_161 , V_131 , V_169 , V_11 , V_170 ) ;
if ( V_161 + V_169 > V_25 -> V_172 ) {
F_227 ( V_25 , V_161 + V_169 ) ;
V_173 = 1 ;
}
F_61 ( V_11 ) ;
F_24 ( V_11 ) ;
if ( V_171 < V_161 )
F_228 ( V_25 , V_171 , V_161 ) ;
if ( V_173 )
F_229 ( V_25 ) ;
return V_169 ;
}
int F_230 ( struct V_11 * V_11 , unsigned long V_150 ,
unsigned long V_174 )
{
unsigned V_152 , V_153 , V_75 ;
unsigned V_151 ;
struct V_1 * V_2 , * V_14 ;
int V_30 = 1 ;
if ( ! F_14 ( V_11 ) )
return 0 ;
V_14 = F_16 ( V_11 ) ;
V_75 = V_14 -> V_39 ;
V_151 = F_231 ( unsigned , V_94 - V_150 , V_174 ) ;
V_151 = V_150 + V_151 ;
if ( V_150 < V_75 && V_151 > V_94 - V_75 )
return 0 ;
V_2 = V_14 ;
V_152 = 0 ;
do {
V_153 = V_152 + V_75 ;
if ( V_153 > V_150 && V_152 < V_151 ) {
if ( ! F_56 ( V_2 ) ) {
V_30 = 0 ;
break;
}
if ( V_153 >= V_151 )
break;
}
V_152 = V_153 ;
V_2 = V_2 -> V_15 ;
} while ( V_2 != V_14 );
return V_30 ;
}
int F_232 ( struct V_11 * V_11 , T_7 * V_137 )
{
struct V_25 * V_25 = V_11 -> V_71 -> V_82 ;
T_2 V_175 , V_176 ;
struct V_1 * V_2 , * V_14 , * V_177 [ V_178 ] ;
unsigned int V_75 , V_141 ;
int V_179 , V_115 ;
int V_180 = 1 ;
V_14 = F_196 ( V_11 , V_25 , 0 ) ;
V_75 = V_14 -> V_39 ;
V_141 = F_194 ( V_75 ) ;
V_175 = ( T_2 ) V_11 -> V_31 << ( V_33 - V_141 ) ;
V_176 = ( F_129 ( V_25 ) + V_75 - 1 ) >> V_141 ;
V_2 = V_14 ;
V_179 = 0 ;
V_115 = 0 ;
do {
if ( F_56 ( V_2 ) )
continue;
if ( ! F_38 ( V_2 ) ) {
int V_60 = 0 ;
V_180 = 0 ;
if ( V_175 < V_176 ) {
F_73 ( V_2 -> V_39 != V_75 ) ;
V_60 = V_137 ( V_25 , V_175 , V_2 , 0 ) ;
if ( V_60 )
F_52 ( V_11 ) ;
}
if ( ! F_38 ( V_2 ) ) {
F_212 ( V_11 , V_115 * V_75 , V_75 ) ;
if ( ! V_60 )
F_29 ( V_2 ) ;
continue;
}
if ( F_56 ( V_2 ) )
continue;
}
V_177 [ V_179 ++ ] = V_2 ;
} while ( V_115 ++ , V_175 ++ , ( V_2 = V_2 -> V_15 ) != V_14 );
if ( V_180 )
F_233 ( V_11 ) ;
if ( ! V_179 ) {
if ( ! F_59 ( V_11 ) )
F_60 ( V_11 ) ;
F_61 ( V_11 ) ;
return 0 ;
}
for ( V_115 = 0 ; V_115 < V_179 ; V_115 ++ ) {
V_2 = V_177 [ V_115 ] ;
F_152 ( V_2 ) ;
F_66 ( V_2 ) ;
}
for ( V_115 = 0 ; V_115 < V_179 ; V_115 ++ ) {
V_2 = V_177 [ V_115 ] ;
if ( F_56 ( V_2 ) )
F_50 ( V_2 , 1 ) ;
else
F_153 ( V_111 , 0 , V_2 ) ;
}
return 0 ;
}
int F_234 ( struct V_25 * V_25 , T_5 V_90 )
{
struct V_27 * V_71 = V_25 -> V_29 ;
struct V_11 * V_11 ;
void * V_170 ;
int V_60 ;
V_60 = F_235 ( V_25 , V_90 ) ;
if ( V_60 )
goto V_36;
V_60 = F_236 ( NULL , V_71 , V_90 , 0 ,
V_181 , & V_11 , & V_170 ) ;
if ( V_60 )
goto V_36;
V_60 = F_237 ( NULL , V_71 , V_90 , 0 , 0 , V_11 , V_170 ) ;
F_12 ( V_60 > 0 ) ;
V_36:
return V_60 ;
}
static int F_238 ( struct V_168 * V_168 , struct V_27 * V_71 ,
T_5 V_161 , T_5 * V_182 )
{
struct V_25 * V_25 = V_71 -> V_82 ;
unsigned int V_75 = F_239 ( V_25 ) ;
struct V_11 * V_11 ;
void * V_170 ;
T_3 V_31 , V_183 ;
T_5 V_184 ;
unsigned V_185 , V_92 , V_131 ;
int V_60 = 0 ;
V_31 = V_161 >> V_33 ;
V_92 = V_161 & ~ V_186 ;
while ( V_31 > ( V_183 = ( V_184 = * V_182 ) >> V_33 ) ) {
V_185 = V_184 & ~ V_186 ;
if ( V_185 & ( V_75 - 1 ) ) {
* V_182 |= ( V_75 - 1 ) ;
( * V_182 ) ++ ;
}
V_131 = V_94 - V_185 ;
V_60 = F_236 ( V_168 , V_71 , V_184 , V_131 , 0 ,
& V_11 , & V_170 ) ;
if ( V_60 )
goto V_36;
F_212 ( V_11 , V_185 , V_131 ) ;
V_60 = F_237 ( V_168 , V_71 , V_184 , V_131 , V_131 ,
V_11 , V_170 ) ;
if ( V_60 < 0 )
goto V_36;
F_12 ( V_60 != V_131 ) ;
V_60 = 0 ;
F_240 ( V_71 ) ;
if ( F_108 ( F_241 ( V_187 ) ) ) {
V_60 = - V_188 ;
goto V_36;
}
}
if ( V_31 == V_183 ) {
V_185 = V_184 & ~ V_186 ;
if ( V_92 <= V_185 ) {
goto V_36;
}
if ( V_185 & ( V_75 - 1 ) ) {
* V_182 |= ( V_75 - 1 ) ;
( * V_182 ) ++ ;
}
V_131 = V_92 - V_185 ;
V_60 = F_236 ( V_168 , V_71 , V_184 , V_131 , 0 ,
& V_11 , & V_170 ) ;
if ( V_60 )
goto V_36;
F_212 ( V_11 , V_185 , V_131 ) ;
V_60 = F_237 ( V_168 , V_71 , V_184 , V_131 , V_131 ,
V_11 , V_170 ) ;
if ( V_60 < 0 )
goto V_36;
F_12 ( V_60 != V_131 ) ;
V_60 = 0 ;
}
V_36:
return V_60 ;
}
int F_242 ( struct V_168 * V_168 , struct V_27 * V_71 ,
T_5 V_161 , unsigned V_131 , unsigned V_46 ,
struct V_11 * * V_165 , void * * V_170 ,
T_7 * V_137 , T_5 * V_182 )
{
struct V_25 * V_25 = V_71 -> V_82 ;
unsigned int V_75 = F_239 ( V_25 ) ;
unsigned int V_185 ;
int V_60 ;
V_60 = F_238 ( V_168 , V_71 , V_161 , V_182 ) ;
if ( V_60 )
return V_60 ;
V_185 = * V_182 & ~ V_186 ;
if ( V_161 + V_131 > * V_182 && V_185 & ( V_75 - 1 ) ) {
* V_182 |= ( V_75 - 1 ) ;
( * V_182 ) ++ ;
}
return F_222 ( V_71 , V_161 , V_131 , V_46 , V_165 , V_137 ) ;
}
int F_243 ( struct V_11 * V_11 , unsigned V_150 , unsigned V_151 )
{
struct V_25 * V_25 = V_11 -> V_71 -> V_82 ;
F_221 ( V_25 , V_11 , V_150 , V_151 ) ;
return 0 ;
}
int F_244 ( struct V_189 * V_190 , struct V_191 * V_192 ,
T_7 V_137 )
{
struct V_11 * V_11 = V_192 -> V_11 ;
struct V_25 * V_25 = F_245 ( V_190 -> V_193 ) ;
unsigned long V_134 ;
T_5 V_90 ;
int V_30 ;
F_190 ( V_11 ) ;
V_90 = F_129 ( V_25 ) ;
if ( ( V_11 -> V_71 != V_25 -> V_29 ) ||
( F_246 ( V_11 ) > V_90 ) ) {
V_30 = - V_194 ;
goto V_38;
}
if ( ( ( V_11 -> V_31 + 1 ) << V_33 ) > V_90 )
V_134 = V_90 & ~ V_186 ;
else
V_134 = V_94 ;
V_30 = F_220 ( V_11 , 0 , V_134 , V_137 ) ;
if ( ! V_30 )
V_30 = F_243 ( V_11 , 0 , V_134 ) ;
if ( F_108 ( V_30 < 0 ) )
goto V_38;
F_247 ( V_11 ) ;
F_248 ( V_11 ) ;
return 0 ;
V_38:
F_61 ( V_11 ) ;
return V_30 ;
}
static void F_249 ( struct V_1 * V_2 , int V_21 )
{
F_28 ( V_2 , V_21 ) ;
}
static void F_250 ( struct V_11 * V_11 , struct V_1 * V_14 )
{
struct V_1 * V_2 ;
F_12 ( ! F_13 ( V_11 ) ) ;
F_37 ( & V_11 -> V_71 -> V_37 ) ;
V_2 = V_14 ;
do {
if ( F_184 ( V_11 ) )
F_110 ( V_2 ) ;
if ( ! V_2 -> V_15 )
V_2 -> V_15 = V_14 ;
V_2 = V_2 -> V_15 ;
} while ( V_2 != V_14 );
F_127 ( V_11 , V_14 ) ;
F_41 ( & V_11 -> V_71 -> V_37 ) ;
}
int F_251 ( struct V_27 * V_71 ,
T_5 V_161 , unsigned V_131 , unsigned V_46 ,
struct V_11 * * V_165 , void * * V_170 ,
T_7 * V_137 )
{
struct V_25 * V_25 = V_71 -> V_82 ;
const unsigned V_195 = V_25 -> V_34 ;
const unsigned V_75 = 1 << V_195 ;
struct V_1 * V_14 , * V_2 ;
struct V_11 * V_11 ;
T_3 V_31 ;
unsigned V_150 , V_151 ;
unsigned V_196 ;
unsigned V_152 , V_153 ;
T_2 V_197 ;
int V_198 = 0 ;
int V_30 = 0 ;
int V_199 = 1 ;
V_31 = V_161 >> V_33 ;
V_150 = V_161 & ( V_94 - 1 ) ;
V_151 = V_150 + V_131 ;
V_11 = F_223 ( V_71 , V_31 , V_46 ) ;
if ( ! V_11 )
return - V_167 ;
* V_165 = V_11 ;
* V_170 = NULL ;
if ( F_14 ( V_11 ) ) {
V_30 = F_220 ( V_11 , V_161 , V_131 , V_137 ) ;
if ( F_108 ( V_30 ) )
goto V_200;
return V_30 ;
}
if ( F_252 ( V_11 ) )
return 0 ;
V_14 = F_122 ( V_11 , V_75 , 0 ) ;
if ( ! V_14 ) {
V_30 = - V_167 ;
goto V_200;
}
V_197 = ( T_2 ) V_11 -> V_31 << ( V_33 - V_195 ) ;
for ( V_152 = 0 , V_196 = 0 , V_2 = V_14 ;
V_152 < V_94 ;
V_196 ++ , V_152 += V_75 , V_2 = V_2 -> V_15 ) {
int V_201 ;
V_153 = V_152 + V_75 ;
V_2 -> V_8 = 0 ;
V_201 = 1 ;
if ( V_152 >= V_151 )
V_201 = 0 ;
V_30 = V_137 ( V_25 , V_197 + V_196 ,
V_2 , V_201 ) ;
if ( V_30 )
goto V_106;
if ( ! F_38 ( V_2 ) )
V_199 = 0 ;
if ( F_202 ( V_2 ) )
F_204 ( V_2 ) ;
if ( F_101 ( V_11 ) ) {
F_29 ( V_2 ) ;
continue;
}
if ( F_202 ( V_2 ) || ! F_38 ( V_2 ) ) {
F_218 ( V_11 , V_152 , V_150 ,
V_151 , V_153 ) ;
continue;
}
if ( F_56 ( V_2 ) )
continue;
if ( V_152 < V_150 || V_153 > V_151 ) {
F_152 ( V_2 ) ;
V_2 -> V_5 = F_249 ;
F_153 ( V_111 , 0 , V_2 ) ;
V_198 ++ ;
}
}
if ( V_198 ) {
for ( V_2 = V_14 ; V_2 ; V_2 = V_2 -> V_15 ) {
F_79 ( V_2 ) ;
if ( ! F_56 ( V_2 ) )
V_30 = - V_62 ;
}
if ( V_30 )
goto V_106;
}
if ( V_199 )
F_233 ( V_11 ) ;
* V_170 = V_14 ;
return 0 ;
V_106:
F_12 ( ! V_30 ) ;
F_250 ( V_11 , V_14 ) ;
F_210 ( V_11 , V_150 , V_151 ) ;
V_200:
F_61 ( V_11 ) ;
F_24 ( V_11 ) ;
* V_165 = NULL ;
return V_30 ;
}
int F_253 ( struct V_168 * V_168 , struct V_27 * V_71 ,
T_5 V_161 , unsigned V_131 , unsigned V_169 ,
struct V_11 * V_11 , void * V_170 )
{
struct V_25 * V_25 = V_11 -> V_71 -> V_82 ;
struct V_1 * V_14 = V_170 ;
struct V_1 * V_2 ;
F_12 ( V_170 != NULL && F_14 ( V_11 ) ) ;
if ( F_108 ( V_169 < V_131 ) && V_14 )
F_250 ( V_11 , V_14 ) ;
if ( F_14 ( V_11 ) )
return F_226 ( V_168 , V_71 , V_161 , V_131 ,
V_169 , V_11 , V_170 ) ;
F_60 ( V_11 ) ;
F_247 ( V_11 ) ;
if ( V_161 + V_169 > V_25 -> V_172 ) {
F_227 ( V_25 , V_161 + V_169 ) ;
F_229 ( V_25 ) ;
}
F_61 ( V_11 ) ;
F_24 ( V_11 ) ;
while ( V_14 ) {
V_2 = V_14 ;
V_14 = V_14 -> V_15 ;
F_125 ( V_2 ) ;
}
return V_169 ;
}
int F_254 ( struct V_11 * V_11 , T_7 * V_137 ,
struct V_138 * V_139 )
{
struct V_25 * const V_25 = V_11 -> V_71 -> V_82 ;
T_5 V_172 = F_129 ( V_25 ) ;
const T_3 V_202 = V_172 >> V_33 ;
unsigned V_92 ;
int V_30 ;
if ( V_11 -> V_31 < V_202 )
goto V_36;
V_92 = V_172 & ( V_94 - 1 ) ;
if ( V_11 -> V_31 >= V_202 + 1 || ! V_92 ) {
#if 0
if (page->mapping->a_ops->invalidatepage)
page->mapping->a_ops->invalidatepage(page, offset);
#endif
F_61 ( V_11 ) ;
return 0 ;
}
F_255 ( V_11 , V_92 , V_94 ) ;
V_36:
V_30 = F_256 ( V_11 , V_137 , V_139 ) ;
if ( V_30 == - V_203 )
V_30 = F_198 ( V_25 , V_11 , V_137 , V_139 ,
F_62 ) ;
return V_30 ;
}
int F_257 ( struct V_27 * V_71 ,
T_5 V_150 , T_7 * V_137 )
{
T_3 V_31 = V_150 >> V_33 ;
unsigned V_92 = V_150 & ( V_94 - 1 ) ;
unsigned V_75 ;
T_2 V_175 ;
unsigned V_127 , V_161 ;
struct V_25 * V_25 = V_71 -> V_82 ;
struct V_11 * V_11 ;
struct V_1 V_204 ;
int V_60 ;
V_75 = F_239 ( V_25 ) ;
V_127 = V_92 & ( V_75 - 1 ) ;
if ( ! V_127 )
return 0 ;
V_127 = V_75 - V_127 ;
V_175 = ( T_2 ) V_31 << ( V_33 - V_25 -> V_34 ) ;
V_11 = F_258 ( V_71 , V_31 ) ;
V_60 = - V_167 ;
if ( ! V_11 )
goto V_36;
if ( F_14 ( V_11 ) ) {
V_205:
F_61 ( V_11 ) ;
F_24 ( V_11 ) ;
return F_259 ( V_71 , V_150 , V_137 ) ;
}
V_161 = V_75 ;
while ( V_92 >= V_161 ) {
V_175 ++ ;
V_161 += V_75 ;
}
V_204 . V_39 = V_75 ;
V_204 . V_8 = 0 ;
V_60 = V_137 ( V_25 , V_175 , & V_204 , 0 ) ;
if ( V_60 )
goto V_206;
if ( ! F_38 ( & V_204 ) )
goto V_206;
if ( ! F_101 ( V_11 ) ) {
V_60 = V_71 -> V_207 -> V_208 ( NULL , V_11 ) ;
if ( V_60 ) {
F_24 ( V_11 ) ;
goto V_36;
}
F_190 ( V_11 ) ;
if ( ! F_101 ( V_11 ) ) {
V_60 = - V_62 ;
goto V_206;
}
if ( F_14 ( V_11 ) )
goto V_205;
}
F_212 ( V_11 , V_92 , V_127 ) ;
F_247 ( V_11 ) ;
V_60 = 0 ;
V_206:
F_61 ( V_11 ) ;
F_24 ( V_11 ) ;
V_36:
return V_60 ;
}
int F_259 ( struct V_27 * V_71 ,
T_5 V_150 , T_7 * V_137 )
{
T_3 V_31 = V_150 >> V_33 ;
unsigned V_92 = V_150 & ( V_94 - 1 ) ;
unsigned V_75 ;
T_2 V_175 ;
unsigned V_127 , V_161 ;
struct V_25 * V_25 = V_71 -> V_82 ;
struct V_11 * V_11 ;
struct V_1 * V_2 ;
int V_60 ;
V_75 = F_239 ( V_25 ) ;
V_127 = V_92 & ( V_75 - 1 ) ;
if ( ! V_127 )
return 0 ;
V_127 = V_75 - V_127 ;
V_175 = ( T_2 ) V_31 << ( V_33 - V_25 -> V_34 ) ;
V_11 = F_258 ( V_71 , V_31 ) ;
V_60 = - V_167 ;
if ( ! V_11 )
goto V_36;
if ( ! F_14 ( V_11 ) )
F_183 ( V_11 , V_75 , 0 ) ;
V_2 = F_16 ( V_11 ) ;
V_161 = V_75 ;
while ( V_92 >= V_161 ) {
V_2 = V_2 -> V_15 ;
V_175 ++ ;
V_161 += V_75 ;
}
V_60 = 0 ;
if ( ! F_38 ( V_2 ) ) {
F_73 ( V_2 -> V_39 != V_75 ) ;
V_60 = V_137 ( V_25 , V_175 , V_2 , 0 ) ;
if ( V_60 )
goto V_206;
if ( ! F_38 ( V_2 ) )
goto V_206;
}
if ( F_101 ( V_11 ) )
F_29 ( V_2 ) ;
if ( ! F_56 ( V_2 ) && ! F_200 ( V_2 ) && ! F_219 ( V_2 ) ) {
V_60 = - V_62 ;
F_94 ( V_111 , 0 , 1 , & V_2 ) ;
F_79 ( V_2 ) ;
if ( ! F_56 ( V_2 ) )
goto V_206;
}
F_212 ( V_11 , V_92 , V_127 ) ;
F_96 ( V_2 ) ;
V_60 = 0 ;
V_206:
F_61 ( V_11 ) ;
F_24 ( V_11 ) ;
V_36:
return V_60 ;
}
int F_260 ( struct V_11 * V_11 , T_7 * V_137 ,
struct V_138 * V_139 )
{
struct V_25 * const V_25 = V_11 -> V_71 -> V_82 ;
T_5 V_172 = F_129 ( V_25 ) ;
const T_3 V_202 = V_172 >> V_33 ;
unsigned V_92 ;
if ( V_11 -> V_31 < V_202 )
return F_198 ( V_25 , V_11 , V_137 , V_139 ,
F_62 ) ;
V_92 = V_172 & ( V_94 - 1 ) ;
if ( V_11 -> V_31 >= V_202 + 1 || ! V_92 ) {
F_261 ( V_11 , 0 , V_94 ) ;
F_61 ( V_11 ) ;
return 0 ;
}
F_255 ( V_11 , V_92 , V_94 ) ;
return F_198 ( V_25 , V_11 , V_137 , V_139 ,
F_62 ) ;
}
T_2 F_262 ( struct V_27 * V_71 , T_2 V_24 ,
T_7 * V_137 )
{
struct V_25 * V_25 = V_71 -> V_82 ;
struct V_1 V_48 = {
. V_39 = F_239 ( V_25 ) ,
} ;
V_137 ( V_25 , V_24 , & V_48 , 0 ) ;
return V_48 . V_20 ;
}
static void F_263 ( struct V_209 * V_209 )
{
struct V_1 * V_2 = V_209 -> V_210 ;
if ( F_108 ( F_264 ( V_209 , V_211 ) ) )
F_265 ( V_17 , & V_2 -> V_8 ) ;
V_2 -> V_5 ( V_2 , ! V_209 -> V_212 ) ;
F_266 ( V_209 ) ;
}
void F_267 ( int V_213 , struct V_209 * V_209 )
{
T_2 V_214 ;
struct V_215 * V_216 = & V_209 -> V_217 [ V_209 -> V_218 - 1 ] ;
unsigned V_219 ;
V_214 = F_129 ( V_209 -> V_220 -> V_26 ) >> 9 ;
if ( ! V_214 )
return;
if ( F_108 ( V_209 -> V_221 . V_222 >= V_214 ) )
return;
V_214 -= V_209 -> V_221 . V_222 ;
if ( F_168 ( ( V_209 -> V_221 . V_223 >> 9 ) <= V_214 ) )
return;
V_219 = V_209 -> V_221 . V_223 - ( V_214 << 9 ) ;
V_209 -> V_221 . V_223 -= V_219 ;
V_216 -> V_224 -= V_219 ;
if ( V_213 == V_111 ) {
F_212 ( V_216 -> V_225 , V_216 -> V_226 + V_216 -> V_224 ,
V_219 ) ;
}
}
static int F_209 ( int V_213 , int V_227 , struct V_1 * V_2 ,
enum V_228 V_229 , struct V_138 * V_139 )
{
struct V_209 * V_209 ;
F_12 ( ! F_17 ( V_2 ) ) ;
F_12 ( ! F_38 ( V_2 ) ) ;
F_12 ( ! V_2 -> V_5 ) ;
F_12 ( F_200 ( V_2 ) ) ;
F_12 ( F_219 ( V_2 ) ) ;
if ( F_268 ( V_2 ) && ( V_213 == V_76 ) )
F_269 ( V_2 ) ;
V_209 = F_270 ( V_230 , 1 ) ;
if ( V_139 ) {
F_271 ( V_139 , V_209 ) ;
F_272 ( V_139 , V_2 -> V_7 , V_2 -> V_39 ) ;
}
V_209 -> V_221 . V_222 = V_2 -> V_20 * ( V_2 -> V_39 >> 9 ) ;
V_209 -> V_220 = V_2 -> V_19 ;
V_209 -> V_231 = V_229 ;
F_273 ( V_209 , V_2 -> V_7 , V_2 -> V_39 , F_274 ( V_2 ) ) ;
F_12 ( V_209 -> V_221 . V_223 != V_2 -> V_39 ) ;
V_209 -> V_232 = F_263 ;
V_209 -> V_210 = V_2 ;
F_267 ( V_213 , V_209 ) ;
if ( F_275 ( V_2 ) )
V_227 |= V_233 ;
if ( F_276 ( V_2 ) )
V_227 |= V_234 ;
F_277 ( V_209 , V_213 , V_227 ) ;
F_278 ( V_209 ) ;
return 0 ;
}
int F_153 ( int V_213 , int V_227 , struct V_1 * V_2 )
{
return F_209 ( V_213 , V_227 , V_2 , 0 , NULL ) ;
}
void F_94 ( int V_213 , int V_227 , int V_179 , struct V_1 * V_118 [] )
{
int V_115 ;
for ( V_115 = 0 ; V_115 < V_179 ; V_115 ++ ) {
struct V_1 * V_2 = V_118 [ V_115 ] ;
if ( ! F_205 ( V_2 ) )
continue;
if ( V_213 == V_235 ) {
if ( F_207 ( V_2 ) ) {
V_2 -> V_5 = F_33 ;
F_39 ( V_2 ) ;
F_153 ( V_213 , V_227 , V_2 ) ;
continue;
}
} else {
if ( ! F_56 ( V_2 ) ) {
V_2 -> V_5 = F_31 ;
F_39 ( V_2 ) ;
F_153 ( V_213 , V_227 , V_2 ) ;
continue;
}
}
F_7 ( V_2 ) ;
}
}
void F_118 ( struct V_1 * V_2 , int V_227 )
{
F_152 ( V_2 ) ;
if ( ! F_207 ( V_2 ) ) {
F_7 ( V_2 ) ;
return;
}
V_2 -> V_5 = F_33 ;
F_39 ( V_2 ) ;
F_153 ( V_76 , V_227 , V_2 ) ;
}
int F_279 ( struct V_1 * V_2 , int V_227 )
{
int V_30 = 0 ;
F_73 ( F_147 ( & V_2 -> V_110 ) < 1 ) ;
F_152 ( V_2 ) ;
if ( F_207 ( V_2 ) ) {
F_39 ( V_2 ) ;
V_2 -> V_5 = F_33 ;
V_30 = F_153 ( V_76 , V_227 , V_2 ) ;
F_79 ( V_2 ) ;
if ( ! V_30 && ! F_56 ( V_2 ) )
V_30 = - V_62 ;
} else {
F_7 ( V_2 ) ;
}
return V_30 ;
}
int F_280 ( struct V_1 * V_2 )
{
return F_279 ( V_2 , V_88 ) ;
}
static inline int F_281 ( struct V_1 * V_2 )
{
return F_147 ( & V_2 -> V_110 ) |
( V_2 -> V_8 & ( ( 1 << V_144 ) | ( 1 << V_9 ) ) ) ;
}
static int
F_282 ( struct V_11 * V_11 , struct V_1 * * V_236 )
{
struct V_1 * V_14 = F_16 ( V_11 ) ;
struct V_1 * V_2 ;
V_2 = V_14 ;
do {
if ( F_281 ( V_2 ) )
goto V_106;
V_2 = V_2 -> V_15 ;
} while ( V_2 != V_14 );
do {
struct V_1 * V_87 = V_2 -> V_15 ;
if ( V_2 -> V_53 )
F_71 ( V_2 ) ;
V_2 = V_87 ;
} while ( V_2 != V_14 );
* V_236 = V_14 ;
F_21 ( V_11 ) ;
return 1 ;
V_106:
return 0 ;
}
int F_137 ( struct V_11 * V_11 )
{
struct V_27 * const V_71 = V_11 -> V_71 ;
struct V_1 * V_236 = NULL ;
int V_30 = 0 ;
F_12 ( ! F_13 ( V_11 ) ) ;
if ( F_15 ( V_11 ) )
return 0 ;
if ( V_71 == NULL ) {
V_30 = F_282 ( V_11 , & V_236 ) ;
goto V_36;
}
F_37 ( & V_71 -> V_37 ) ;
V_30 = F_282 ( V_11 , & V_236 ) ;
if ( V_30 )
F_283 ( V_11 ) ;
F_41 ( & V_71 -> V_37 ) ;
V_36:
if ( V_236 ) {
struct V_1 * V_2 = V_236 ;
do {
struct V_1 * V_87 = V_2 -> V_15 ;
F_125 ( V_2 ) ;
V_2 = V_87 ;
} while ( V_2 != V_236 );
}
return V_30 ;
}
static void F_284 ( void )
{
int V_115 ;
int V_237 = 0 ;
if ( F_285 ( V_238 . V_239 ) - 1 < 4096 )
return;
F_163 ( V_238 . V_239 , 0 ) ;
F_286 (i)
V_237 += F_287 ( V_238 , V_115 ) . V_179 ;
V_240 = ( V_237 > V_241 ) ;
}
struct V_1 * F_123 ( T_6 V_242 )
{
struct V_1 * V_30 = F_288 ( V_243 , V_242 ) ;
if ( V_30 ) {
F_114 ( & V_30 -> V_52 ) ;
F_289 () ;
F_290 ( V_238 . V_179 ) ;
F_284 () ;
F_291 () ;
}
return V_30 ;
}
void F_125 ( struct V_1 * V_2 )
{
F_12 ( ! F_75 ( & V_2 -> V_52 ) ) ;
F_292 ( V_243 , V_2 ) ;
F_289 () ;
F_293 ( V_238 . V_179 ) ;
F_284 () ;
F_291 () ;
}
static int F_294 ( unsigned int V_121 )
{
int V_115 ;
struct V_113 * V_114 = & F_287 ( V_116 , V_121 ) ;
for ( V_115 = 0 ; V_115 < V_117 ; V_115 ++ ) {
F_80 ( V_114 -> V_118 [ V_115 ] ) ;
V_114 -> V_118 [ V_115 ] = NULL ;
}
F_295 ( V_238 . V_179 , F_287 ( V_238 , V_121 ) . V_179 ) ;
F_287 ( V_238 , V_121 ) . V_179 = 0 ;
return 0 ;
}
int F_296 ( struct V_1 * V_2 )
{
if ( ! F_56 ( V_2 ) ) {
F_152 ( V_2 ) ;
if ( ! F_56 ( V_2 ) )
return 0 ;
F_7 ( V_2 ) ;
}
return 1 ;
}
int F_297 ( struct V_1 * V_2 )
{
F_12 ( ! F_17 ( V_2 ) ) ;
if ( F_56 ( V_2 ) ) {
F_7 ( V_2 ) ;
return 0 ;
}
F_39 ( V_2 ) ;
V_2 -> V_5 = F_31 ;
F_153 ( V_111 , 0 , V_2 ) ;
F_79 ( V_2 ) ;
if ( F_56 ( V_2 ) )
return 0 ;
return - V_62 ;
}
static T_5
F_298 ( struct V_11 * V_11 , T_5 V_244 , int V_245 )
{
T_5 V_92 = F_246 ( V_11 ) ;
struct V_1 * V_2 , * V_14 ;
bool V_246 = V_245 == V_247 ;
if ( V_244 < V_92 )
V_244 = V_92 ;
V_2 = V_14 = F_16 ( V_11 ) ;
do {
V_92 += V_2 -> V_39 ;
if ( V_244 >= V_92 )
continue;
if ( ( F_219 ( V_2 ) || F_56 ( V_2 ) ) == V_246 )
return V_244 ;
V_244 = V_92 ;
} while ( ( V_2 = V_2 -> V_15 ) != V_14 );
return - V_248 ;
}
T_5
F_299 ( struct V_25 * V_25 , T_5 V_92 , T_5 V_127 ,
int V_245 )
{
T_3 V_31 = V_92 >> V_33 ;
T_3 V_134 = F_300 ( V_92 + V_127 , V_94 ) ;
T_5 V_244 = V_92 ;
struct V_132 V_133 ;
if ( V_127 <= 0 )
return - V_248 ;
F_186 ( & V_133 , 0 ) ;
do {
unsigned V_249 , V_250 , V_115 ;
V_249 = F_231 ( unsigned , V_134 - V_31 , V_135 ) ;
V_250 = F_187 ( & V_133 , V_25 -> V_29 , V_31 , V_249 ) ;
if ( V_250 == 0 )
break;
for ( V_115 = 0 ; V_115 < V_250 ; V_115 ++ ) {
struct V_11 * V_11 = V_133 . V_136 [ V_115 ] ;
if ( V_245 == V_251 &&
V_244 < F_246 ( V_11 ) )
goto V_252;
if ( V_11 -> V_31 >= V_134 )
goto V_253;
F_190 ( V_11 ) ;
if ( F_168 ( V_11 -> V_71 == V_25 -> V_29 ) &&
F_14 ( V_11 ) ) {
V_244 = F_298 ( V_11 , V_244 , V_245 ) ;
if ( V_244 >= 0 ) {
F_61 ( V_11 ) ;
goto V_252;
}
}
F_61 ( V_11 ) ;
V_244 = F_246 ( V_11 ) + V_94 ;
}
if ( V_250 < V_249 )
break;
V_31 = V_133 . V_136 [ V_115 - 1 ] -> V_31 + 1 ;
F_192 ( & V_133 ) ;
} while ( V_31 < V_134 );
if ( V_245 != V_251 )
goto V_253;
V_252:
if ( V_244 < V_92 + V_127 )
goto V_36;
V_253:
V_244 = - V_248 ;
V_36:
F_192 ( & V_133 ) ;
return V_244 ;
}
void T_8 F_301 ( void )
{
unsigned long V_254 ;
int V_30 ;
V_243 = F_302 ( L_16 ,
sizeof( struct V_1 ) , 0 ,
( V_255 | V_256 |
V_257 ) ,
NULL ) ;
V_254 = ( F_303 () * 10 ) / 100 ;
V_241 = V_254 * ( V_94 / sizeof( struct V_1 ) ) ;
V_30 = F_304 ( V_258 , L_17 ,
NULL , F_294 ) ;
F_73 ( V_30 < 0 ) ;
}
