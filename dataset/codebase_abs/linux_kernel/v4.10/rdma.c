static unsigned int F_1 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 + V_2 -> V_4 <= V_2 -> V_3 ) ||
( V_2 -> V_4 > ( V_5 ) V_6 ) )
return 0 ;
return ( ( V_2 -> V_3 + V_2 -> V_4 + V_7 - 1 ) >> V_8 ) -
( V_2 -> V_3 >> V_8 ) ;
}
static struct V_9 * F_2 ( struct V_10 * V_11 , V_5 V_12 ,
struct V_9 * V_13 )
{
struct V_14 * * V_15 = & V_11 -> V_14 ;
struct V_14 * V_16 = NULL ;
struct V_9 * V_17 ;
while ( * V_15 ) {
V_16 = * V_15 ;
V_17 = F_3 ( V_16 , struct V_9 , V_18 ) ;
if ( V_12 < V_17 -> V_19 )
V_15 = & ( * V_15 ) -> V_20 ;
else if ( V_12 > V_17 -> V_19 )
V_15 = & ( * V_15 ) -> V_21 ;
else
return V_17 ;
}
if ( V_13 ) {
F_4 ( & V_13 -> V_18 , V_16 , V_15 ) ;
F_5 ( & V_13 -> V_18 , V_11 ) ;
F_6 ( & V_13 -> V_22 ) ;
}
return NULL ;
}
static void F_7 ( struct V_9 * V_17 )
{
struct V_23 * V_24 = V_17 -> V_25 ;
void * V_26 = NULL ;
unsigned long V_27 ;
F_8 ( L_1 ,
V_17 -> V_19 , F_9 ( & V_17 -> V_22 ) ) ;
if ( F_10 ( V_28 , & V_17 -> V_29 ) )
return;
F_11 ( & V_24 -> V_30 , V_27 ) ;
if ( ! F_12 ( & V_17 -> V_18 ) )
F_13 ( & V_17 -> V_18 , & V_24 -> V_31 ) ;
V_26 = V_17 -> V_32 ;
V_17 -> V_32 = NULL ;
F_14 ( & V_24 -> V_30 , V_27 ) ;
if ( V_26 )
V_17 -> V_33 -> V_34 ( V_26 , V_17 -> V_35 ) ;
}
void F_15 ( struct V_9 * V_17 )
{
F_7 ( V_17 ) ;
F_16 ( V_17 ) ;
}
void F_17 ( struct V_23 * V_24 )
{
struct V_9 * V_17 ;
struct V_14 * V_36 ;
unsigned long V_27 ;
F_11 ( & V_24 -> V_30 , V_27 ) ;
while ( ( V_36 = F_18 ( & V_24 -> V_31 ) ) ) {
V_17 = F_3 ( V_36 , struct V_9 , V_18 ) ;
if ( V_17 -> V_33 == V_24 -> V_37 )
V_17 -> V_35 = 0 ;
F_13 ( & V_17 -> V_18 , & V_24 -> V_31 ) ;
F_19 ( & V_17 -> V_18 ) ;
F_14 ( & V_24 -> V_30 , V_27 ) ;
F_7 ( V_17 ) ;
F_20 ( V_17 ) ;
F_11 ( & V_24 -> V_30 , V_27 ) ;
}
F_14 ( & V_24 -> V_30 , V_27 ) ;
if ( V_24 -> V_37 && V_24 -> V_37 -> V_38 )
V_24 -> V_37 -> V_38 () ;
}
static int F_21 ( unsigned long V_39 , unsigned int V_40 ,
struct V_41 * * V_42 , int V_43 )
{
int V_44 ;
V_44 = F_22 ( V_39 , V_40 , V_43 , V_42 ) ;
if ( V_44 >= 0 && V_44 < V_40 ) {
while ( V_44 -- )
F_23 ( V_42 [ V_44 ] ) ;
V_44 = - V_45 ;
}
return V_44 ;
}
static int F_24 ( struct V_23 * V_24 , struct V_46 * args ,
V_5 * V_47 , struct V_9 * * V_48 )
{
struct V_9 * V_17 = NULL , * V_49 ;
unsigned int V_40 ;
struct V_41 * * V_42 = NULL ;
struct V_50 * V_51 ;
void * V_26 ;
unsigned long V_27 ;
T_1 V_52 ;
unsigned int V_53 ;
long V_54 ;
int V_44 ;
if ( V_24 -> V_55 == 0 ) {
V_44 = - V_56 ;
goto V_57;
}
if ( ! V_24 -> V_37 -> V_58 ) {
V_44 = - V_59 ;
goto V_57;
}
V_40 = F_1 ( & args -> V_2 ) ;
if ( V_40 == 0 ) {
V_44 = - V_60 ;
goto V_57;
}
F_8 ( L_2 ,
args -> V_2 . V_3 , args -> V_2 . V_4 , V_40 ) ;
V_42 = F_25 ( V_40 , sizeof( struct V_41 * ) , V_61 ) ;
if ( ! V_42 ) {
V_44 = - V_62 ;
goto V_57;
}
V_17 = F_26 ( sizeof( struct V_9 ) , V_61 ) ;
if ( ! V_17 ) {
V_44 = - V_62 ;
goto V_57;
}
F_27 ( & V_17 -> V_22 , 1 ) ;
F_19 ( & V_17 -> V_18 ) ;
V_17 -> V_33 = V_24 -> V_37 ;
V_17 -> V_25 = V_24 ;
if ( args -> V_27 & V_63 )
V_17 -> V_64 = 1 ;
if ( args -> V_27 & V_65 )
V_17 -> V_35 = 1 ;
if ( args -> V_27 & V_66 )
V_17 -> V_67 = 1 ;
V_44 = F_21 ( args -> V_2 . V_3 , V_40 , V_42 , 1 ) ;
if ( V_44 < 0 )
goto V_57;
V_53 = V_44 ;
V_51 = F_25 ( V_53 , sizeof( * V_51 ) , V_61 ) ;
if ( ! V_51 ) {
V_44 = - V_62 ;
goto V_57;
}
F_28 ( ! V_53 ) ;
F_29 ( V_51 , V_53 ) ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ )
F_30 ( & V_51 [ V_54 ] , V_42 [ V_54 ] , V_7 , 0 ) ;
F_8 ( L_3 , V_53 ) ;
V_26 = V_24 -> V_37 -> V_58 ( V_51 , V_53 , V_24 ,
& V_17 -> V_19 ) ;
if ( F_31 ( V_26 ) ) {
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ )
F_23 ( F_32 ( & V_51 [ V_54 ] ) ) ;
F_16 ( V_51 ) ;
V_44 = F_33 ( V_26 ) ;
goto V_57;
}
V_17 -> V_32 = V_26 ;
F_8 ( L_4 ,
V_17 -> V_19 , ( void * ) ( unsigned long ) args -> V_68 ) ;
V_52 = F_34 ( V_17 -> V_19 , args -> V_2 . V_3 & ~ V_69 ) ;
if ( V_47 )
* V_47 = V_52 ;
if ( args -> V_68 && F_35 ( V_52 , ( V_5 V_70 * ) ( unsigned long ) args -> V_68 ) ) {
V_44 = - V_45 ;
goto V_57;
}
F_11 ( & V_24 -> V_30 , V_27 ) ;
V_49 = F_2 ( & V_24 -> V_31 , V_17 -> V_19 , V_17 ) ;
F_14 ( & V_24 -> V_30 , V_27 ) ;
F_36 ( V_49 && V_49 != V_17 ) ;
F_8 ( L_5 , V_17 -> V_19 ) ;
if ( V_48 ) {
F_6 ( & V_17 -> V_22 ) ;
* V_48 = V_17 ;
}
V_44 = 0 ;
V_57:
F_16 ( V_42 ) ;
if ( V_17 )
F_20 ( V_17 ) ;
return V_44 ;
}
int F_37 ( struct V_23 * V_24 , char V_70 * V_71 , int V_72 )
{
struct V_46 args ;
if ( V_72 != sizeof( struct V_46 ) )
return - V_60 ;
if ( F_38 ( & args , (struct V_46 V_70 * ) V_71 ,
sizeof( struct V_46 ) ) )
return - V_45 ;
return F_24 ( V_24 , & args , NULL , NULL ) ;
}
int F_39 ( struct V_23 * V_24 , char V_70 * V_71 , int V_72 )
{
struct V_73 args ;
struct V_46 V_74 ;
if ( V_72 != sizeof( struct V_73 ) )
return - V_60 ;
if ( F_38 ( & args , (struct V_73 V_70 * ) V_71 ,
sizeof( struct V_73 ) ) )
return - V_45 ;
V_74 . V_2 = args . V_2 ;
V_74 . V_68 = args . V_68 ;
V_74 . V_27 = args . V_27 ;
return F_24 ( V_24 , & V_74 , NULL , NULL ) ;
}
int F_40 ( struct V_23 * V_24 , char V_70 * V_71 , int V_72 )
{
struct V_75 args ;
struct V_9 * V_17 ;
unsigned long V_27 ;
if ( V_72 != sizeof( struct V_75 ) )
return - V_60 ;
if ( F_38 ( & args , (struct V_75 V_70 * ) V_71 ,
sizeof( struct V_75 ) ) )
return - V_45 ;
if ( args . V_52 == 0 ) {
if ( ! V_24 -> V_37 || ! V_24 -> V_37 -> V_38 )
return - V_60 ;
V_24 -> V_37 -> V_38 () ;
return 0 ;
}
F_11 ( & V_24 -> V_30 , V_27 ) ;
V_17 = F_2 ( & V_24 -> V_31 , F_41 ( args . V_52 ) , NULL ) ;
if ( V_17 ) {
F_13 ( & V_17 -> V_18 , & V_24 -> V_31 ) ;
F_19 ( & V_17 -> V_18 ) ;
if ( args . V_27 & V_65 )
V_17 -> V_35 = 1 ;
}
F_14 ( & V_24 -> V_30 , V_27 ) ;
if ( ! V_17 )
return - V_60 ;
F_7 ( V_17 ) ;
F_20 ( V_17 ) ;
return 0 ;
}
void F_42 ( struct V_23 * V_24 , T_2 V_19 , int V_76 )
{
struct V_9 * V_17 ;
unsigned long V_27 ;
int V_77 = 0 ;
F_11 ( & V_24 -> V_30 , V_27 ) ;
V_17 = F_2 ( & V_24 -> V_31 , V_19 , NULL ) ;
if ( ! V_17 ) {
F_43 ( V_78 L_6 , V_19 ) ;
F_14 ( & V_24 -> V_30 , V_27 ) ;
return;
}
if ( V_17 -> V_64 || V_76 ) {
F_13 ( & V_17 -> V_18 , & V_24 -> V_31 ) ;
F_19 ( & V_17 -> V_18 ) ;
V_77 = 1 ;
}
F_14 ( & V_24 -> V_30 , V_27 ) ;
if ( V_17 -> V_33 -> V_79 )
V_17 -> V_33 -> V_79 ( V_17 -> V_32 , V_80 ) ;
if ( V_77 ) {
F_7 ( V_17 ) ;
F_20 ( V_17 ) ;
}
}
void F_44 ( struct V_81 * V_82 )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < V_82 -> V_83 ; V_54 ++ ) {
struct V_41 * V_41 = F_32 ( & V_82 -> V_84 [ V_54 ] ) ;
if ( ! V_82 -> V_85 ) {
F_28 ( ! V_41 -> V_86 && F_45 () ) ;
F_46 ( V_41 ) ;
}
F_23 ( V_41 ) ;
}
F_16 ( V_82 -> V_87 ) ;
V_82 -> V_87 = NULL ;
V_82 -> V_88 = 0 ;
}
void F_47 ( struct V_89 * V_90 )
{
struct V_41 * V_41 = F_32 ( V_90 -> V_84 ) ;
F_46 ( V_41 ) ;
F_23 ( V_41 ) ;
F_16 ( V_90 -> V_87 ) ;
V_90 -> V_87 = NULL ;
V_90 -> V_88 = 0 ;
}
static int F_48 ( struct V_1 V_91 [] , int V_92 )
{
int V_93 = 0 ;
unsigned int V_40 ;
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < V_92 ; V_54 ++ ) {
V_40 = F_1 ( & V_91 [ V_54 ] ) ;
if ( V_40 == 0 )
return - V_60 ;
V_93 += V_40 ;
if ( V_93 < 0 )
return - V_60 ;
}
return V_93 ;
}
int F_49 ( struct V_94 * args )
{
struct V_1 V_2 ;
struct V_1 V_70 * V_95 ;
int V_93 = 0 ;
unsigned int V_40 ;
unsigned int V_54 ;
V_95 = (struct V_1 V_70 * ) ( unsigned long ) args -> V_96 ;
for ( V_54 = 0 ; V_54 < args -> V_97 ; V_54 ++ ) {
if ( F_38 ( & V_2 , & V_95 [ V_54 ] ,
sizeof( struct V_1 ) ) )
return - V_45 ;
V_40 = F_1 ( & V_2 ) ;
if ( V_40 == 0 )
return - V_60 ;
V_93 += V_40 ;
if ( V_93 < 0 )
return - V_60 ;
}
return V_93 * sizeof( struct V_50 ) ;
}
int F_50 ( struct V_23 * V_24 , struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_94 * args ;
struct V_81 * V_102 = & V_99 -> V_103 ;
int V_40 ;
unsigned int V_104 ;
struct V_41 * * V_42 = NULL ;
struct V_1 V_105 [ V_106 ] , * V_107 = V_105 ;
int V_108 ;
unsigned int V_54 , V_109 ;
int V_44 = 0 ;
if ( V_101 -> V_110 < F_51 ( sizeof( struct V_94 ) )
|| V_99 -> V_103 . V_88 )
return - V_60 ;
args = F_52 ( V_101 ) ;
if ( V_24 -> V_55 == 0 ) {
V_44 = - V_56 ;
goto V_111;
}
if ( args -> V_97 > V_112 ) {
V_44 = - V_113 ;
goto V_111;
}
V_108 = args -> V_97 * sizeof( struct V_1 ) ;
if ( args -> V_97 > V_106 ) {
V_107 = F_53 ( F_54 ( V_24 ) , V_108 , V_61 ) ;
if ( ! V_107 ) {
V_44 = - V_62 ;
goto V_111;
}
}
if ( F_38 ( V_107 , (struct V_1 V_70 * ) ( unsigned long ) args -> V_96 , V_108 ) ) {
V_44 = - V_45 ;
goto V_57;
}
V_40 = F_48 ( V_107 , args -> V_97 ) ;
if ( V_40 < 0 ) {
V_44 = - V_60 ;
goto V_57;
}
V_42 = F_25 ( V_40 , sizeof( struct V_41 * ) , V_61 ) ;
if ( ! V_42 ) {
V_44 = - V_62 ;
goto V_57;
}
V_102 -> V_85 = ! ! ( args -> V_27 & V_66 ) ;
V_102 -> V_114 = ! ! ( args -> V_27 & V_115 ) ;
V_102 -> V_116 = ! ! ( args -> V_27 & V_117 ) ;
V_102 -> V_118 = ! ! ( args -> V_27 & V_119 ) ;
V_102 -> V_88 = 1 ;
V_102 -> V_120 = V_24 -> V_121 ;
F_28 ( ! V_40 ) ;
V_102 -> V_84 = F_55 ( V_99 , V_40 ) ;
if ( ! V_102 -> V_84 ) {
V_44 = - V_62 ;
goto V_57;
}
if ( V_102 -> V_116 || V_102 -> V_120 ) {
V_102 -> V_87 = F_56 ( sizeof( struct V_122 ) , V_61 ) ;
if ( ! V_102 -> V_87 ) {
V_44 = - V_62 ;
goto V_57;
}
V_102 -> V_87 -> V_123 = args -> V_124 ;
V_102 -> V_87 -> V_125 = V_126 ;
}
V_102 -> V_127 = F_41 ( args -> V_52 ) ;
V_102 -> V_128 = args -> V_129 . V_3 + F_57 ( args -> V_52 ) ;
V_104 = 0 ;
F_8 ( L_7 ,
( unsigned long long ) args -> V_97 ,
( unsigned long long ) args -> V_129 . V_3 ,
V_102 -> V_127 ) ;
for ( V_54 = 0 ; V_54 < args -> V_97 ; V_54 ++ ) {
struct V_1 * V_91 = & V_107 [ V_54 ] ;
unsigned int V_130 = F_1 ( V_91 ) ;
V_24 -> V_131 = V_91 -> V_3 ;
V_24 -> V_132 = V_91 -> V_4 ;
V_44 = F_21 ( V_91 -> V_3 , V_130 , V_42 , ! V_102 -> V_85 ) ;
if ( V_44 < 0 )
goto V_57;
else
V_44 = 0 ;
F_8 ( L_8 ,
V_104 , V_130 , V_91 -> V_4 , V_91 -> V_3 ) ;
V_104 += V_91 -> V_4 ;
for ( V_109 = 0 ; V_109 < V_130 ; V_109 ++ ) {
unsigned int V_133 = V_91 -> V_3 & ~ V_69 ;
struct V_50 * V_51 ;
V_51 = & V_102 -> V_84 [ V_102 -> V_83 + V_109 ] ;
F_30 ( V_51 , V_42 [ V_109 ] ,
F_58 (unsigned int, iov->bytes, PAGE_SIZE - offset) ,
V_133 ) ;
F_8 ( L_9 ,
V_51 -> V_133 , V_51 -> V_134 , V_91 -> V_3 , V_91 -> V_4 ) ;
V_91 -> V_3 += V_51 -> V_134 ;
V_91 -> V_4 -= V_51 -> V_134 ;
}
V_102 -> V_83 += V_130 ;
}
if ( V_104 > args -> V_129 . V_4 ) {
F_8 ( L_10 ,
V_104 ,
( unsigned int ) args -> V_129 . V_4 ) ;
V_44 = - V_60 ;
goto V_57;
}
V_102 -> V_135 = V_104 ;
V_57:
if ( V_107 != V_105 )
F_59 ( F_54 ( V_24 ) , V_107 , V_108 ) ;
F_16 ( V_42 ) ;
V_111:
if ( V_44 )
F_44 ( V_102 ) ;
else
F_60 ( V_136 ) ;
return V_44 ;
}
int F_61 ( struct V_23 * V_24 , struct V_98 * V_99 ,
struct V_100 * V_101 )
{
unsigned long V_27 ;
struct V_9 * V_17 ;
T_2 V_19 ;
int V_137 = 0 ;
if ( V_101 -> V_110 < F_51 ( sizeof( T_1 ) ) ||
V_99 -> V_138 != 0 )
return - V_60 ;
memcpy ( & V_99 -> V_138 , F_52 ( V_101 ) , sizeof( V_99 -> V_138 ) ) ;
V_19 = F_41 ( V_99 -> V_138 ) ;
F_11 ( & V_24 -> V_30 , V_27 ) ;
V_17 = F_2 ( & V_24 -> V_31 , V_19 , NULL ) ;
if ( ! V_17 )
V_137 = - V_60 ;
else
F_6 ( & V_17 -> V_22 ) ;
F_14 ( & V_24 -> V_30 , V_27 ) ;
if ( V_17 ) {
V_17 -> V_33 -> V_79 ( V_17 -> V_32 , V_139 ) ;
V_99 -> V_103 . V_140 = V_17 ;
}
return V_137 ;
}
int F_62 ( struct V_23 * V_24 , struct V_98 * V_99 ,
struct V_100 * V_101 )
{
if ( V_101 -> V_110 < F_51 ( sizeof( struct V_46 ) ) ||
V_99 -> V_138 != 0 )
return - V_60 ;
return F_24 ( V_24 , F_52 ( V_101 ) , & V_99 -> V_138 , & V_99 -> V_103 . V_140 ) ;
}
int F_63 ( struct V_23 * V_24 , struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_41 * V_41 = NULL ;
struct V_141 * args ;
int V_44 = 0 ;
if ( V_101 -> V_110 < F_51 ( sizeof( struct V_141 ) )
|| V_99 -> V_142 . V_88 )
return - V_60 ;
args = F_52 ( V_101 ) ;
switch ( V_101 -> V_143 ) {
case V_144 :
V_99 -> V_142 . V_145 = V_146 ;
V_99 -> V_142 . V_147 . V_148 = args -> V_149 . V_148 ;
V_99 -> V_142 . V_147 . V_150 = 0 ;
break;
case V_151 :
V_99 -> V_142 . V_145 = V_146 ;
V_99 -> V_142 . V_147 . V_148 = args -> V_152 . V_148 ;
V_99 -> V_142 . V_147 . V_150 = args -> V_152 . V_150 ;
break;
case V_153 :
V_99 -> V_142 . V_145 = V_154 ;
V_99 -> V_142 . V_155 . V_156 = args -> V_157 . V_156 ;
V_99 -> V_142 . V_155 . V_158 = args -> V_157 . V_158 ;
V_99 -> V_142 . V_155 . V_159 = ~ 0 ;
V_99 -> V_142 . V_155 . V_160 = ~ 0 ;
break;
case V_161 :
V_99 -> V_142 . V_145 = V_154 ;
V_99 -> V_142 . V_155 . V_156 = args -> V_162 . V_156 ;
V_99 -> V_142 . V_155 . V_158 = args -> V_162 . V_158 ;
V_99 -> V_142 . V_155 . V_159 = args -> V_162 . V_159 ;
V_99 -> V_142 . V_155 . V_160 = args -> V_162 . V_160 ;
break;
default:
F_64 () ;
}
V_99 -> V_142 . V_116 = ! ! ( args -> V_27 & V_117 ) ;
V_99 -> V_142 . V_118 = ! ! ( args -> V_27 & V_119 ) ;
V_99 -> V_142 . V_88 = 1 ;
V_99 -> V_142 . V_120 = V_24 -> V_121 ;
V_99 -> V_142 . V_84 = F_55 ( V_99 , 1 ) ;
if ( ! V_99 -> V_142 . V_84 ) {
V_44 = - V_62 ;
goto V_137;
}
if ( args -> V_163 & 0x7 ) {
V_44 = - V_45 ;
goto V_137;
}
V_44 = F_21 ( args -> V_163 , 1 , & V_41 , 1 ) ;
if ( V_44 != 1 )
goto V_137;
V_44 = 0 ;
F_30 ( V_99 -> V_142 . V_84 , V_41 , 8 , F_65 ( args -> V_163 ) ) ;
if ( V_99 -> V_142 . V_116 || V_99 -> V_142 . V_120 ) {
V_99 -> V_142 . V_87 = F_56 ( sizeof( * V_99 -> V_142 . V_87 ) , V_61 ) ;
if ( ! V_99 -> V_142 . V_87 ) {
V_44 = - V_62 ;
goto V_137;
}
V_99 -> V_142 . V_87 -> V_123 = args -> V_124 ;
V_99 -> V_142 . V_87 -> V_125 = V_126 ;
}
V_99 -> V_142 . V_127 = F_41 ( args -> V_52 ) ;
V_99 -> V_142 . V_128 = args -> V_164 + F_57 ( args -> V_52 ) ;
return V_44 ;
V_137:
if ( V_41 )
F_23 ( V_41 ) ;
F_16 ( V_99 -> V_142 . V_87 ) ;
return V_44 ;
}
