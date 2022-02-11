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
if ( ( V_40 - 1 ) > ( V_61 >> V_8 ) ) {
V_44 = - V_62 ;
goto V_57;
}
F_8 ( L_2 ,
args -> V_2 . V_3 , args -> V_2 . V_4 , V_40 ) ;
V_42 = F_25 ( V_40 , sizeof( struct V_41 * ) , V_63 ) ;
if ( ! V_42 ) {
V_44 = - V_64 ;
goto V_57;
}
V_17 = F_26 ( sizeof( struct V_9 ) , V_63 ) ;
if ( ! V_17 ) {
V_44 = - V_64 ;
goto V_57;
}
F_27 ( & V_17 -> V_22 , 1 ) ;
F_19 ( & V_17 -> V_18 ) ;
V_17 -> V_33 = V_24 -> V_37 ;
V_17 -> V_25 = V_24 ;
if ( args -> V_27 & V_65 )
V_17 -> V_66 = 1 ;
if ( args -> V_27 & V_67 )
V_17 -> V_35 = 1 ;
if ( args -> V_27 & V_68 )
V_17 -> V_69 = 1 ;
V_44 = F_21 ( args -> V_2 . V_3 , V_40 , V_42 , 1 ) ;
if ( V_44 < 0 )
goto V_57;
V_53 = V_44 ;
V_51 = F_25 ( V_53 , sizeof( * V_51 ) , V_63 ) ;
if ( ! V_51 ) {
V_44 = - V_64 ;
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
V_17 -> V_19 , ( void * ) ( unsigned long ) args -> V_70 ) ;
V_52 = F_34 ( V_17 -> V_19 , args -> V_2 . V_3 & ~ V_71 ) ;
if ( V_47 )
* V_47 = V_52 ;
if ( args -> V_70 && F_35 ( V_52 , ( V_5 V_72 * ) ( unsigned long ) args -> V_70 ) ) {
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
int F_37 ( struct V_23 * V_24 , char V_72 * V_73 , int V_74 )
{
struct V_46 args ;
if ( V_74 != sizeof( struct V_46 ) )
return - V_60 ;
if ( F_38 ( & args , (struct V_46 V_72 * ) V_73 ,
sizeof( struct V_46 ) ) )
return - V_45 ;
return F_24 ( V_24 , & args , NULL , NULL ) ;
}
int F_39 ( struct V_23 * V_24 , char V_72 * V_73 , int V_74 )
{
struct V_75 args ;
struct V_46 V_76 ;
if ( V_74 != sizeof( struct V_75 ) )
return - V_60 ;
if ( F_38 ( & args , (struct V_75 V_72 * ) V_73 ,
sizeof( struct V_75 ) ) )
return - V_45 ;
V_76 . V_2 = args . V_2 ;
V_76 . V_70 = args . V_70 ;
V_76 . V_27 = args . V_27 ;
return F_24 ( V_24 , & V_76 , NULL , NULL ) ;
}
int F_40 ( struct V_23 * V_24 , char V_72 * V_73 , int V_74 )
{
struct V_77 args ;
struct V_9 * V_17 ;
unsigned long V_27 ;
if ( V_74 != sizeof( struct V_77 ) )
return - V_60 ;
if ( F_38 ( & args , (struct V_77 V_72 * ) V_73 ,
sizeof( struct V_77 ) ) )
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
if ( args . V_27 & V_67 )
V_17 -> V_35 = 1 ;
}
F_14 ( & V_24 -> V_30 , V_27 ) ;
if ( ! V_17 )
return - V_60 ;
F_7 ( V_17 ) ;
F_20 ( V_17 ) ;
return 0 ;
}
void F_42 ( struct V_23 * V_24 , T_2 V_19 , int V_78 )
{
struct V_9 * V_17 ;
unsigned long V_27 ;
int V_79 = 0 ;
F_11 ( & V_24 -> V_30 , V_27 ) ;
V_17 = F_2 ( & V_24 -> V_31 , V_19 , NULL ) ;
if ( ! V_17 ) {
F_43 ( L_6 ,
V_19 ) ;
F_14 ( & V_24 -> V_30 , V_27 ) ;
return;
}
if ( V_17 -> V_66 || V_78 ) {
F_13 ( & V_17 -> V_18 , & V_24 -> V_31 ) ;
F_19 ( & V_17 -> V_18 ) ;
V_79 = 1 ;
}
F_14 ( & V_24 -> V_30 , V_27 ) ;
if ( V_17 -> V_33 -> V_80 )
V_17 -> V_33 -> V_80 ( V_17 -> V_32 , V_81 ) ;
if ( V_79 ) {
F_7 ( V_17 ) ;
F_20 ( V_17 ) ;
}
}
void F_44 ( struct V_82 * V_83 )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < V_83 -> V_84 ; V_54 ++ ) {
struct V_41 * V_41 = F_32 ( & V_83 -> V_85 [ V_54 ] ) ;
if ( ! V_83 -> V_86 ) {
F_28 ( ! V_41 -> V_87 && F_45 () ) ;
F_46 ( V_41 ) ;
}
F_23 ( V_41 ) ;
}
F_16 ( V_83 -> V_88 ) ;
V_83 -> V_88 = NULL ;
V_83 -> V_89 = 0 ;
}
void F_47 ( struct V_90 * V_91 )
{
struct V_41 * V_41 = F_32 ( V_91 -> V_85 ) ;
F_46 ( V_41 ) ;
F_23 ( V_41 ) ;
F_16 ( V_91 -> V_88 ) ;
V_91 -> V_88 = NULL ;
V_91 -> V_89 = 0 ;
}
static int F_48 ( struct V_1 V_92 [] , int V_93 )
{
int V_94 = 0 ;
unsigned int V_40 ;
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < V_93 ; V_54 ++ ) {
V_40 = F_1 ( & V_92 [ V_54 ] ) ;
if ( V_40 == 0 )
return - V_60 ;
V_94 += V_40 ;
if ( V_94 < 0 )
return - V_60 ;
}
return V_94 ;
}
int F_49 ( struct V_95 * args )
{
struct V_1 V_2 ;
struct V_1 V_72 * V_96 ;
int V_94 = 0 ;
unsigned int V_40 ;
unsigned int V_54 ;
V_96 = (struct V_1 V_72 * ) ( unsigned long ) args -> V_97 ;
for ( V_54 = 0 ; V_54 < args -> V_98 ; V_54 ++ ) {
if ( F_38 ( & V_2 , & V_96 [ V_54 ] ,
sizeof( struct V_1 ) ) )
return - V_45 ;
V_40 = F_1 ( & V_2 ) ;
if ( V_40 == 0 )
return - V_60 ;
V_94 += V_40 ;
if ( V_94 < 0 )
return - V_60 ;
}
return V_94 * sizeof( struct V_50 ) ;
}
int F_50 ( struct V_23 * V_24 , struct V_99 * V_100 ,
struct V_101 * V_102 )
{
struct V_95 * args ;
struct V_82 * V_103 = & V_100 -> V_104 ;
int V_40 ;
unsigned int V_105 ;
struct V_41 * * V_42 = NULL ;
struct V_1 V_106 [ V_107 ] , * V_108 = V_106 ;
int V_109 ;
unsigned int V_54 , V_110 ;
int V_44 = 0 ;
if ( V_102 -> V_111 < F_51 ( sizeof( struct V_95 ) )
|| V_100 -> V_104 . V_89 )
return - V_60 ;
args = F_52 ( V_102 ) ;
if ( V_24 -> V_55 == 0 ) {
V_44 = - V_56 ;
goto V_112;
}
if ( args -> V_98 > V_113 ) {
V_44 = - V_62 ;
goto V_112;
}
V_109 = args -> V_98 * sizeof( struct V_1 ) ;
if ( args -> V_98 > V_107 ) {
V_108 = F_53 ( F_54 ( V_24 ) , V_109 , V_63 ) ;
if ( ! V_108 ) {
V_44 = - V_64 ;
goto V_112;
}
}
if ( F_38 ( V_108 , (struct V_1 V_72 * ) ( unsigned long ) args -> V_97 , V_109 ) ) {
V_44 = - V_45 ;
goto V_57;
}
V_40 = F_48 ( V_108 , args -> V_98 ) ;
if ( V_40 < 0 ) {
V_44 = - V_60 ;
goto V_57;
}
V_42 = F_25 ( V_40 , sizeof( struct V_41 * ) , V_63 ) ;
if ( ! V_42 ) {
V_44 = - V_64 ;
goto V_57;
}
V_103 -> V_86 = ! ! ( args -> V_27 & V_68 ) ;
V_103 -> V_114 = ! ! ( args -> V_27 & V_115 ) ;
V_103 -> V_116 = ! ! ( args -> V_27 & V_117 ) ;
V_103 -> V_118 = ! ! ( args -> V_27 & V_119 ) ;
V_103 -> V_89 = 1 ;
V_103 -> V_120 = V_24 -> V_121 ;
F_28 ( ! V_40 ) ;
V_103 -> V_85 = F_55 ( V_100 , V_40 ) ;
if ( ! V_103 -> V_85 ) {
V_44 = - V_64 ;
goto V_57;
}
if ( V_103 -> V_116 || V_103 -> V_120 ) {
V_103 -> V_88 = F_56 ( sizeof( struct V_122 ) , V_63 ) ;
if ( ! V_103 -> V_88 ) {
V_44 = - V_64 ;
goto V_57;
}
V_103 -> V_88 -> V_123 = args -> V_124 ;
V_103 -> V_88 -> V_125 = V_126 ;
if ( V_100 -> V_127 . V_85 ) {
V_100 -> V_104 . V_116 = 0 ;
V_100 -> V_127 . V_116 = ! ! ( args -> V_27 & V_117 ) ;
}
}
V_103 -> V_128 = F_41 ( args -> V_52 ) ;
V_103 -> V_129 = args -> V_130 . V_3 + F_57 ( args -> V_52 ) ;
V_105 = 0 ;
F_8 ( L_7 ,
( unsigned long long ) args -> V_98 ,
( unsigned long long ) args -> V_130 . V_3 ,
V_103 -> V_128 ) ;
for ( V_54 = 0 ; V_54 < args -> V_98 ; V_54 ++ ) {
struct V_1 * V_92 = & V_108 [ V_54 ] ;
unsigned int V_131 = F_1 ( V_92 ) ;
V_24 -> V_132 = V_92 -> V_3 ;
V_24 -> V_133 = V_92 -> V_4 ;
V_44 = F_21 ( V_92 -> V_3 , V_131 , V_42 , ! V_103 -> V_86 ) ;
if ( V_44 < 0 )
goto V_57;
else
V_44 = 0 ;
F_8 ( L_8 ,
V_105 , V_131 , V_92 -> V_4 , V_92 -> V_3 ) ;
V_105 += V_92 -> V_4 ;
for ( V_110 = 0 ; V_110 < V_131 ; V_110 ++ ) {
unsigned int V_134 = V_92 -> V_3 & ~ V_71 ;
struct V_50 * V_51 ;
V_51 = & V_103 -> V_85 [ V_103 -> V_84 + V_110 ] ;
F_30 ( V_51 , V_42 [ V_110 ] ,
F_58 (unsigned int, iov->bytes, PAGE_SIZE - offset) ,
V_134 ) ;
F_8 ( L_9 ,
V_51 -> V_134 , V_51 -> V_135 , V_92 -> V_3 , V_92 -> V_4 ) ;
V_92 -> V_3 += V_51 -> V_135 ;
V_92 -> V_4 -= V_51 -> V_135 ;
}
V_103 -> V_84 += V_131 ;
}
if ( V_105 > args -> V_130 . V_4 ) {
F_8 ( L_10 ,
V_105 ,
( unsigned int ) args -> V_130 . V_4 ) ;
V_44 = - V_60 ;
goto V_57;
}
V_103 -> V_136 = V_105 ;
V_57:
if ( V_108 != V_106 )
F_59 ( F_54 ( V_24 ) , V_108 , V_109 ) ;
F_16 ( V_42 ) ;
V_112:
if ( V_44 )
F_44 ( V_103 ) ;
else
F_60 ( V_137 ) ;
return V_44 ;
}
int F_61 ( struct V_23 * V_24 , struct V_99 * V_100 ,
struct V_101 * V_102 )
{
unsigned long V_27 ;
struct V_9 * V_17 ;
T_2 V_19 ;
int V_138 = 0 ;
if ( V_102 -> V_111 < F_51 ( sizeof( T_1 ) ) ||
V_100 -> V_139 != 0 )
return - V_60 ;
memcpy ( & V_100 -> V_139 , F_52 ( V_102 ) , sizeof( V_100 -> V_139 ) ) ;
V_19 = F_41 ( V_100 -> V_139 ) ;
F_11 ( & V_24 -> V_30 , V_27 ) ;
V_17 = F_2 ( & V_24 -> V_31 , V_19 , NULL ) ;
if ( ! V_17 )
V_138 = - V_60 ;
else
F_6 ( & V_17 -> V_22 ) ;
F_14 ( & V_24 -> V_30 , V_27 ) ;
if ( V_17 ) {
V_17 -> V_33 -> V_80 ( V_17 -> V_32 , V_140 ) ;
V_100 -> V_104 . V_141 = V_17 ;
}
return V_138 ;
}
int F_62 ( struct V_23 * V_24 , struct V_99 * V_100 ,
struct V_101 * V_102 )
{
if ( V_102 -> V_111 < F_51 ( sizeof( struct V_46 ) ) ||
V_100 -> V_139 != 0 )
return - V_60 ;
return F_24 ( V_24 , F_52 ( V_102 ) , & V_100 -> V_139 , & V_100 -> V_104 . V_141 ) ;
}
int F_63 ( struct V_23 * V_24 , struct V_99 * V_100 ,
struct V_101 * V_102 )
{
struct V_41 * V_41 = NULL ;
struct V_142 * args ;
int V_44 = 0 ;
if ( V_102 -> V_111 < F_51 ( sizeof( struct V_142 ) )
|| V_100 -> V_143 . V_89 )
return - V_60 ;
args = F_52 ( V_102 ) ;
switch ( V_102 -> V_144 ) {
case V_145 :
V_100 -> V_143 . V_146 = V_147 ;
V_100 -> V_143 . V_148 . V_149 = args -> V_150 . V_149 ;
V_100 -> V_143 . V_148 . V_151 = 0 ;
break;
case V_152 :
V_100 -> V_143 . V_146 = V_147 ;
V_100 -> V_143 . V_148 . V_149 = args -> V_153 . V_149 ;
V_100 -> V_143 . V_148 . V_151 = args -> V_153 . V_151 ;
break;
case V_154 :
V_100 -> V_143 . V_146 = V_155 ;
V_100 -> V_143 . V_156 . V_157 = args -> V_158 . V_157 ;
V_100 -> V_143 . V_156 . V_159 = args -> V_158 . V_159 ;
V_100 -> V_143 . V_156 . V_160 = ~ 0 ;
V_100 -> V_143 . V_156 . V_161 = ~ 0 ;
break;
case V_162 :
V_100 -> V_143 . V_146 = V_155 ;
V_100 -> V_143 . V_156 . V_157 = args -> V_163 . V_157 ;
V_100 -> V_143 . V_156 . V_159 = args -> V_163 . V_159 ;
V_100 -> V_143 . V_156 . V_160 = args -> V_163 . V_160 ;
V_100 -> V_143 . V_156 . V_161 = args -> V_163 . V_161 ;
break;
default:
F_64 () ;
}
V_100 -> V_143 . V_116 = ! ! ( args -> V_27 & V_117 ) ;
V_100 -> V_143 . V_118 = ! ! ( args -> V_27 & V_119 ) ;
V_100 -> V_143 . V_89 = 1 ;
V_100 -> V_143 . V_120 = V_24 -> V_121 ;
V_100 -> V_143 . V_85 = F_55 ( V_100 , 1 ) ;
if ( ! V_100 -> V_143 . V_85 ) {
V_44 = - V_64 ;
goto V_138;
}
if ( args -> V_164 & 0x7 ) {
V_44 = - V_45 ;
goto V_138;
}
V_44 = F_21 ( args -> V_164 , 1 , & V_41 , 1 ) ;
if ( V_44 != 1 )
goto V_138;
V_44 = 0 ;
F_30 ( V_100 -> V_143 . V_85 , V_41 , 8 , F_65 ( args -> V_164 ) ) ;
if ( V_100 -> V_143 . V_116 || V_100 -> V_143 . V_120 ) {
V_100 -> V_143 . V_88 = F_56 ( sizeof( * V_100 -> V_143 . V_88 ) , V_63 ) ;
if ( ! V_100 -> V_143 . V_88 ) {
V_44 = - V_64 ;
goto V_138;
}
V_100 -> V_143 . V_88 -> V_123 = args -> V_124 ;
V_100 -> V_143 . V_88 -> V_125 = V_126 ;
}
V_100 -> V_143 . V_128 = F_41 ( args -> V_52 ) ;
V_100 -> V_143 . V_129 = args -> V_165 + F_57 ( args -> V_52 ) ;
return V_44 ;
V_138:
if ( V_41 )
F_23 ( V_41 ) ;
F_16 ( V_100 -> V_143 . V_88 ) ;
return V_44 ;
}
