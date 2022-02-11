static inline T_1 F_1 ( int V_1 )
{
return ( 1 << 20 ) / V_2 * ( ( T_1 ) V_1 ) ;
}
static int F_2 ( const char * V_3 , int * V_4 , int V_5 , int V_6 )
{
int V_7 , V_8 ;
V_7 = F_3 ( V_3 , 10 , & V_8 ) ;
if ( V_7 )
return - V_9 ;
if ( V_8 < V_5 || V_8 > V_6 )
return - V_9 ;
* V_4 = V_8 ;
return 0 ;
}
static int F_4 ( const char * V_3 , const struct V_10 * V_11 )
{
return F_2 ( V_3 , & V_12 , V_13 , V_14 ) ;
}
static int F_5 ( const char * V_3 , const struct V_10 * V_11 )
{
return F_2 ( V_3 , & V_15 , V_16 ,
V_17 ) ;
}
static inline struct V_18 * F_6 ( struct V_19 * V_20 )
{
return V_20 ? F_7 ( V_20 , struct V_18 , V_20 ) : NULL ;
}
static inline T_2 F_8 ( unsigned int V_4 , char * V_21 )
{
return snprintf ( V_21 , V_22 , L_1 , V_4 ) ;
}
static inline T_2 F_9 ( unsigned long V_4 ,
char * V_21 )
{
return snprintf ( V_21 , V_22 , L_2 , V_4 ) ;
}
static inline T_2 F_10 ( bool V_4 , char * V_21 )
{
return snprintf ( V_21 , V_22 , L_1 , V_4 ) ;
}
static T_2 F_11 ( unsigned int * V_4 ,
const char * V_21 , T_3 V_23 )
{
unsigned int V_24 ;
int V_25 ;
V_25 = F_12 ( V_21 , 0 , & V_24 ) ;
if ( V_25 )
return V_25 ;
* V_4 = V_24 ;
return V_23 ;
}
static T_2 F_13 ( unsigned long * V_4 ,
const char * V_21 , T_3 V_23 )
{
int V_25 ;
unsigned long V_24 ;
V_25 = F_14 ( V_21 , 0 , & V_24 ) ;
if ( V_25 )
return V_25 ;
* V_4 = V_24 ;
return V_23 ;
}
static T_2 F_15 ( bool * V_4 , const char * V_21 ,
T_3 V_23 )
{
bool V_24 ;
int V_25 ;
V_25 = F_16 ( V_21 , & V_24 ) ;
if ( V_25 )
return V_25 ;
* V_4 = V_24 ;
return V_23 ;
}
static T_2 F_17 ( struct V_19 * V_20 , char * V_21 )
{
return F_10 ( F_6 ( V_20 ) -> V_26 , V_21 ) ;
}
static T_2 F_18 ( struct V_19 * V_20 ,
const char * V_21 , T_3 V_23 )
{
struct V_18 * V_27 = F_6 ( V_20 ) ;
bool V_28 = false ;
T_2 V_7 ;
V_7 = F_15 ( & V_28 , V_21 , V_23 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_27 -> V_26 && V_28 ) {
if ( F_19 ( V_29 , & V_27 -> V_30 ) )
return V_23 ;
if ( F_20 ( V_27 ) ) {
F_21 ( V_29 , & V_27 -> V_30 ) ;
return - V_31 ;
}
F_22 ( V_32 , & V_27 -> V_30 ) ;
V_27 -> V_26 = V_28 ;
} else if ( V_27 -> V_26 && ! V_28 ) {
F_23 ( & V_33 ) ;
V_27 -> V_26 = V_28 ;
F_24 ( V_27 -> V_34 ) ;
F_25 ( & V_33 ) ;
F_21 ( V_29 , & V_27 -> V_30 ) ;
}
return V_23 ;
}
static T_2 F_26 ( struct V_19 * V_20 , char * V_21 )
{
struct V_18 * V_35 = F_6 ( V_20 ) ;
return F_27 ( & V_35 -> V_36 , V_21 , 0 ) ;
}
static T_2 F_28 ( struct V_19 * V_20 ,
const char * V_21 , T_3 V_23 )
{
struct V_18 * V_35 = F_6 ( V_20 ) ;
char * V_37 , * V_38 , * V_24 ;
T_1 V_39 , V_40 ;
int V_7 ;
V_37 = F_29 ( V_21 , V_23 , V_41 ) ;
if ( ! V_37 )
return - V_31 ;
V_38 = F_30 ( V_37 ) ;
V_7 = - V_9 ;
if ( V_38 [ 0 ] != '+' && V_38 [ 0 ] != '-' )
goto V_42;
V_24 = strchr ( & V_38 [ 1 ] , '-' ) ;
if ( ! V_24 )
goto V_42;
* V_24 = '\0' ;
V_7 = F_31 ( V_38 + 1 , 0 , & V_39 ) ;
if ( V_7 )
goto V_42;
V_7 = F_31 ( V_24 + 1 , 0 , & V_40 ) ;
if ( V_7 )
goto V_42;
V_7 = - V_9 ;
if ( V_39 > V_40 )
goto V_42;
F_32 ( & V_35 -> V_36 . V_43 , - 1 , 0 ) ;
if ( V_38 [ 0 ] == '+' )
V_7 = F_33 ( & V_35 -> V_36 , V_39 ,
V_40 - V_39 + 1 , 1 ) ;
else
V_7 = F_34 ( & V_35 -> V_36 , V_39 ,
V_40 - V_39 + 1 ) ;
if ( V_7 == 0 )
V_7 = V_23 ;
V_42:
F_35 ( V_37 ) ;
return V_7 ;
}
static void F_36 ( struct V_19 * V_20 )
{
struct V_18 * V_27 = F_6 ( V_20 ) ;
F_37 ( & V_27 -> V_36 ) ;
F_38 ( V_27 , false ) ;
F_39 ( V_27 ) ;
}
static struct
V_19 * F_40 ( struct V_44 * V_45 , const char * V_46 )
{
struct V_18 * V_27 ;
V_27 = F_41 () ;
if ( ! V_27 )
return F_42 ( - V_31 ) ;
F_43 ( & V_27 -> V_20 , V_46 , & V_47 ) ;
return & V_27 -> V_20 ;
}
static void
F_44 ( struct V_44 * V_45 , struct V_19 * V_20 )
{
struct V_18 * V_27 = F_6 ( V_20 ) ;
if ( F_45 ( V_29 , & V_27 -> V_30 ) ) {
F_23 ( & V_33 ) ;
V_27 -> V_26 = false ;
F_24 ( V_27 -> V_34 ) ;
F_25 ( & V_33 ) ;
}
F_46 ( V_20 ) ;
}
static T_2 F_47 ( struct V_19 * V_20 , char * V_21 )
{
return snprintf ( V_21 , V_22 , L_3 ) ;
}
static inline int F_48 ( struct V_34 * V_34 )
{
return F_49 ( V_48 , & V_34 -> V_27 -> V_30 ) ;
}
static struct V_18 * F_41 ( void )
{
struct V_18 * V_27 ;
V_27 = F_50 ( sizeof( * V_27 ) , V_41 ) ;
if ( ! V_27 )
return NULL ;
F_51 ( & V_27 -> V_49 , V_50 ) ;
F_51 ( & V_27 -> V_51 , V_50 ) ;
if ( F_52 ( & V_27 -> V_36 , 0 ) ) {
F_35 ( V_27 ) ;
return NULL ;
}
V_27 -> V_52 = V_53 * 1024 ;
V_27 -> V_54 = V_55 ;
V_27 -> V_56 = V_57 ;
V_27 -> V_58 = V_59 ;
V_27 -> V_60 = V_12 ;
V_27 -> V_61 = V_62 ;
V_27 -> V_63 = V_15 ;
V_27 -> V_64 = V_65 ;
V_27 -> V_66 = V_67 ;
V_27 -> V_68 = V_69 ;
V_27 -> V_70 = V_71 ;
return V_27 ;
}
static void F_39 ( struct V_18 * V_27 )
{
F_35 ( V_27 ) ;
}
static void F_53 ( struct V_72 * V_73 , unsigned int V_74 )
{
F_54 ( V_74 , V_73 -> V_75 ) ;
if ( F_55 ( & V_73 -> V_76 ) )
F_56 ( & V_73 -> V_76 ) ;
}
static unsigned int F_57 ( struct V_72 * V_73 )
{
unsigned int V_74 ;
do {
V_74 = F_58 ( V_73 -> V_75 , V_73 -> V_77 ) ;
if ( V_74 >= V_73 -> V_77 )
return - 1U ;
} while ( F_59 ( V_74 , V_73 -> V_75 ) );
return V_74 ;
}
static void F_60 ( struct V_78 * V_79 )
{
F_53 ( V_79 -> V_73 , V_79 -> V_74 ) ;
}
static struct V_78 * F_61 ( struct V_72 * V_73 )
{
struct V_78 * V_79 ;
unsigned int V_74 ;
V_74 = F_57 ( V_73 ) ;
if ( V_74 != - 1U ) {
V_79 = & V_73 -> V_80 [ V_74 ] ;
V_79 -> V_74 = V_74 ;
V_79 -> V_73 = V_73 ;
if ( V_73 -> V_27 -> V_63 == V_17 ) {
F_62 ( & V_79 -> V_81 , V_82 ,
V_83 ) ;
V_79 -> V_81 . V_84 = V_85 ;
}
return V_79 ;
}
return NULL ;
}
static struct V_78 * F_63 ( struct V_72 * V_73 , int V_86 )
{
struct V_78 * V_79 ;
F_64 ( V_76 ) ;
V_79 = F_61 ( V_73 ) ;
if ( V_79 || ! V_86 )
return V_79 ;
do {
F_65 ( & V_73 -> V_76 , & V_76 , V_87 ) ;
V_79 = F_61 ( V_73 ) ;
if ( V_79 )
break;
F_66 () ;
} while ( 1 );
F_67 ( & V_73 -> V_76 , & V_76 ) ;
return V_79 ;
}
static void F_68 ( struct V_78 * V_79 )
{
struct V_88 * V_89 = NULL ;
int V_60 = V_79 -> V_73 -> V_27 -> V_60 ;
if ( V_79 -> V_90 )
V_89 = V_79 -> V_90 -> V_89 ;
switch ( V_60 ) {
case V_14 :
F_69 ( V_79 -> V_90 , V_79 -> error ) ;
return;
case V_91 :
F_70 ( & V_79 -> V_90 -> V_92 ) ;
F_71 ( V_79 -> V_90 , V_79 -> error ) ;
break;
case V_13 :
V_79 -> V_93 -> V_94 = V_79 -> error ;
F_72 ( V_79 -> V_93 ) ;
break;
}
F_60 ( V_79 ) ;
if ( V_60 == V_91 && F_73 ( V_89 ) ) {
unsigned long V_30 ;
F_74 ( V_89 -> V_95 , V_30 ) ;
F_75 ( V_89 ) ;
F_76 ( V_89 -> V_95 , V_30 ) ;
}
}
static enum V_96 V_85 ( struct V_97 * V_81 )
{
F_68 ( F_7 ( V_81 , struct V_78 , V_81 ) ) ;
return V_98 ;
}
static void F_77 ( struct V_78 * V_79 )
{
T_4 V_99 = V_79 -> V_73 -> V_27 -> V_54 ;
F_78 ( & V_79 -> V_81 , V_99 , V_83 ) ;
}
static void F_79 ( struct V_100 * V_90 )
{
struct V_34 * V_34 = V_90 -> V_89 -> V_101 ;
if ( V_34 -> V_27 -> V_60 == V_14 )
F_68 ( F_80 ( V_90 ) ) ;
else
F_68 ( V_90 -> V_102 ) ;
}
static struct V_103 * F_81 ( T_5 V_104 )
{
struct V_103 * V_105 ;
V_105 = F_82 ( sizeof( struct V_103 ) , V_104 ) ;
if ( ! V_105 )
goto V_42;
V_105 -> V_21 = F_83 ( V_104 , 0 ) ;
if ( ! V_105 -> V_21 )
goto V_106;
V_105 -> V_107 = 0 ;
return V_105 ;
V_106:
F_35 ( V_105 ) ;
V_42:
return NULL ;
}
static void F_84 ( struct V_103 * V_105 )
{
F_85 ( V_108 , & V_105 -> V_107 ) ;
if ( F_49 ( V_109 , & V_105 -> V_107 ) )
return;
F_86 ( V_105 -> V_21 ) ;
F_35 ( V_105 ) ;
}
static void F_87 ( struct V_34 * V_34 , T_6 V_110 ,
bool V_111 )
{
unsigned int V_112 ;
T_1 V_113 ;
struct V_103 * V_105 , * V_7 ;
struct V_114 * V_115 ;
V_115 = V_111 ? & V_34 -> V_27 -> V_51 : & V_34 -> V_27 -> V_49 ;
V_113 = V_110 >> V_116 ;
V_112 = ( V_110 & V_117 ) ;
V_105 = F_88 ( V_115 , V_113 ) ;
if ( V_105 ) {
F_89 ( V_112 , & V_105 -> V_107 ) ;
if ( ! V_105 -> V_107 ) {
V_7 = F_90 ( V_115 , V_113 , V_105 ) ;
F_91 ( V_7 != V_105 ) ;
F_84 ( V_7 ) ;
if ( V_111 )
V_34 -> V_27 -> V_118 -= V_22 ;
}
}
}
static struct V_103 * F_92 ( struct V_34 * V_34 , T_1 V_113 ,
struct V_103 * V_105 , bool V_111 )
{
struct V_114 * V_115 ;
V_115 = V_111 ? & V_34 -> V_27 -> V_51 : & V_34 -> V_27 -> V_49 ;
if ( F_93 ( V_115 , V_113 , V_105 ) ) {
F_84 ( V_105 ) ;
V_105 = F_88 ( V_115 , V_113 ) ;
F_91 ( ! V_105 || V_105 -> V_21 -> V_119 != V_113 ) ;
} else if ( V_111 )
V_34 -> V_27 -> V_118 += V_22 ;
return V_105 ;
}
static void F_38 ( struct V_18 * V_27 , bool V_111 )
{
unsigned long V_120 = 0 ;
int V_121 ;
struct V_103 * V_7 , * V_122 [ V_123 ] ;
struct V_114 * V_115 ;
V_115 = V_111 ? & V_27 -> V_51 : & V_27 -> V_49 ;
do {
int V_124 ;
V_121 = F_94 ( V_115 ,
( void * * ) V_122 , V_120 , V_123 ) ;
for ( V_124 = 0 ; V_124 < V_121 ; V_124 ++ ) {
V_120 = V_122 [ V_124 ] -> V_21 -> V_119 ;
V_7 = F_90 ( V_115 , V_120 , V_122 [ V_124 ] ) ;
F_91 ( V_7 != V_122 [ V_124 ] ) ;
F_84 ( V_7 ) ;
}
V_120 ++ ;
} while ( V_121 == V_123 );
if ( V_111 )
V_27 -> V_118 = 0 ;
}
static struct V_103 * F_95 ( struct V_34 * V_34 ,
T_6 V_110 , bool V_125 , bool V_111 )
{
unsigned int V_112 ;
T_1 V_113 ;
struct V_103 * V_105 ;
struct V_114 * V_115 ;
V_113 = V_110 >> V_116 ;
V_112 = ( V_110 & V_117 ) ;
V_115 = V_111 ? & V_34 -> V_27 -> V_51 : & V_34 -> V_27 -> V_49 ;
V_105 = F_88 ( V_115 , V_113 ) ;
F_91 ( V_105 && V_105 -> V_21 -> V_119 != V_113 ) ;
if ( V_105 && ( V_125 || F_49 ( V_112 , & V_105 -> V_107 ) ) )
return V_105 ;
return NULL ;
}
static struct V_103 * F_96 ( struct V_34 * V_34 ,
T_6 V_110 , bool V_125 , bool V_126 )
{
struct V_103 * V_21 = NULL ;
if ( ! V_126 )
V_21 = F_95 ( V_34 , V_110 , V_125 , true ) ;
if ( V_21 )
return V_21 ;
return F_95 ( V_34 , V_110 , V_125 , false ) ;
}
static struct V_103 * F_97 ( struct V_34 * V_34 ,
T_6 V_110 , bool V_126 )
{
T_1 V_113 ;
struct V_103 * V_105 ;
V_105 = F_96 ( V_34 , V_110 , true , V_126 ) ;
if ( V_105 )
return V_105 ;
F_98 ( & V_34 -> V_33 ) ;
V_105 = F_81 ( V_127 ) ;
if ( ! V_105 )
goto V_128;
if ( F_99 ( V_127 ) )
goto V_106;
F_100 ( & V_34 -> V_33 ) ;
V_113 = V_110 >> V_116 ;
V_105 -> V_21 -> V_119 = V_113 ;
V_105 = F_92 ( V_34 , V_113 , V_105 , ! V_126 ) ;
F_101 () ;
return V_105 ;
V_106:
F_84 ( V_105 ) ;
V_128:
F_100 ( & V_34 -> V_33 ) ;
return F_96 ( V_34 , V_110 , true , V_126 ) ;
}
static int F_102 ( struct V_34 * V_34 , struct V_103 * V_129 )
{
int V_124 ;
unsigned int V_130 ;
T_1 V_113 ;
struct V_103 * V_105 , * V_7 ;
void * V_131 , * V_132 ;
V_113 = V_129 -> V_21 -> V_119 ;
V_105 = F_97 ( V_34 , V_113 << V_116 , true ) ;
F_89 ( V_109 , & V_129 -> V_107 ) ;
if ( F_49 ( V_108 , & V_129 -> V_107 ) ) {
F_84 ( V_129 ) ;
if ( V_105 && V_105 -> V_107 == 0 ) {
V_7 = F_90 ( & V_34 -> V_27 -> V_49 ,
V_113 , V_105 ) ;
F_84 ( V_105 ) ;
}
return 0 ;
}
if ( ! V_105 )
return - V_31 ;
V_132 = F_103 ( V_129 -> V_21 ) ;
V_131 = F_103 ( V_105 -> V_21 ) ;
for ( V_124 = 0 ; V_124 < V_133 ;
V_124 += ( V_34 -> V_27 -> V_61 >> V_134 ) ) {
if ( F_49 ( V_124 , & V_129 -> V_107 ) ) {
V_130 = ( V_124 << V_134 ) ;
memcpy ( V_131 + V_130 , V_132 + V_130 ,
V_34 -> V_27 -> V_61 ) ;
F_85 ( V_124 , & V_105 -> V_107 ) ;
}
}
F_104 ( V_131 ) ;
F_104 ( V_132 ) ;
V_7 = F_90 ( & V_34 -> V_27 -> V_51 , V_113 , V_129 ) ;
F_84 ( V_7 ) ;
V_34 -> V_27 -> V_118 -= V_22 ;
return 0 ;
}
static int F_105 ( struct V_34 * V_34 , unsigned long V_135 )
{
int V_124 , V_136 , V_121 ;
struct V_103 * V_137 [ V_123 ] ;
unsigned long V_138 = 0 , V_139 ;
V_140:
if ( ( V_34 -> V_27 -> V_141 * 1024 * 1024 ) >
V_34 -> V_27 -> V_118 + V_135 || V_34 -> V_27 -> V_118 == 0 )
return 0 ;
V_121 = F_94 ( & V_34 -> V_27 -> V_51 ,
( void * * ) V_137 , V_34 -> V_142 , V_123 ) ;
for ( V_124 = 0 ; V_124 < V_121 ; V_124 ++ ) {
V_34 -> V_142 = V_137 [ V_124 ] -> V_21 -> V_119 ;
if ( F_49 ( V_109 , & V_137 [ V_124 ] -> V_107 ) )
V_137 [ V_124 ] = NULL ;
else
F_85 ( V_109 , & V_137 [ V_124 ] -> V_107 ) ;
}
V_139 = 0 ;
for ( V_124 = 0 ; V_124 < V_121 ; V_124 ++ ) {
if ( V_137 [ V_124 ] == NULL )
continue;
V_136 = F_102 ( V_34 , V_137 [ V_124 ] ) ;
if ( V_136 )
return V_136 ;
V_139 ++ ;
}
V_138 += V_139 << V_143 ;
if ( V_135 > V_138 ) {
if ( V_121 == 0 )
V_34 -> V_142 = 0 ;
if ( V_139 == 0 ) {
F_98 ( & V_34 -> V_33 ) ;
F_100 ( & V_34 -> V_33 ) ;
}
goto V_140;
}
return 0 ;
}
static int F_106 ( struct V_34 * V_34 , struct V_21 * V_144 ,
unsigned int V_145 , T_6 V_110 , T_3 V_135 , bool V_146 )
{
T_3 V_147 , V_23 = 0 ;
unsigned int V_130 ;
struct V_103 * V_105 ;
void * V_131 , * V_132 ;
while ( V_23 < V_135 ) {
V_147 = F_107 ( T_3 , V_34 -> V_27 -> V_61 , V_135 - V_23 ) ;
if ( F_48 ( V_34 ) && ! V_146 )
F_105 ( V_34 , V_22 ) ;
V_130 = ( V_110 & V_117 ) << V_134 ;
V_105 = F_97 ( V_34 , V_110 ,
! F_48 ( V_34 ) || V_146 ) ;
if ( ! V_105 )
return - V_148 ;
V_132 = F_103 ( V_144 ) ;
V_131 = F_103 ( V_105 -> V_21 ) ;
memcpy ( V_131 + V_130 , V_132 + V_145 + V_23 , V_147 ) ;
F_104 ( V_131 ) ;
F_104 ( V_132 ) ;
F_85 ( V_110 & V_117 , & V_105 -> V_107 ) ;
if ( V_146 )
F_87 ( V_34 , V_110 , true ) ;
V_23 += V_147 ;
V_110 += V_147 >> V_134 ;
}
return 0 ;
}
static int F_108 ( struct V_34 * V_34 , struct V_21 * V_149 ,
unsigned int V_145 , T_6 V_110 , T_3 V_135 )
{
T_3 V_147 , V_23 = 0 ;
unsigned int V_130 ;
struct V_103 * V_105 ;
void * V_131 , * V_132 ;
while ( V_23 < V_135 ) {
V_147 = F_107 ( T_3 , V_34 -> V_27 -> V_61 , V_135 - V_23 ) ;
V_130 = ( V_110 & V_117 ) << V_134 ;
V_105 = F_96 ( V_34 , V_110 , false ,
! F_48 ( V_34 ) ) ;
V_131 = F_103 ( V_149 ) ;
if ( ! V_105 ) {
memset ( V_131 + V_145 + V_23 , 0 , V_147 ) ;
goto V_150;
}
V_132 = F_103 ( V_105 -> V_21 ) ;
memcpy ( V_131 + V_145 + V_23 , V_132 + V_130 , V_147 ) ;
F_104 ( V_132 ) ;
V_150:
F_104 ( V_131 ) ;
V_23 += V_147 ;
V_110 += V_147 >> V_134 ;
}
return 0 ;
}
static void F_109 ( struct V_34 * V_34 , T_6 V_110 , T_3 V_135 )
{
T_3 V_147 ;
F_100 ( & V_34 -> V_33 ) ;
while ( V_135 > 0 ) {
V_147 = F_107 ( T_3 , V_135 , V_34 -> V_27 -> V_61 ) ;
F_87 ( V_34 , V_110 , false ) ;
if ( F_48 ( V_34 ) )
F_87 ( V_34 , V_110 , true ) ;
V_110 += V_147 >> V_134 ;
V_135 -= V_147 ;
}
F_98 ( & V_34 -> V_33 ) ;
}
static int F_110 ( struct V_34 * V_34 )
{
int V_136 ;
if ( ! F_48 ( V_34 ) )
return 0 ;
F_100 ( & V_34 -> V_33 ) ;
while ( true ) {
V_136 = F_105 ( V_34 ,
V_34 -> V_27 -> V_141 * 1024 * 1024 ) ;
if ( V_136 || V_34 -> V_27 -> V_118 == 0 )
break;
}
F_91 ( ! F_111 ( & V_34 -> V_27 -> V_51 ) ) ;
F_98 ( & V_34 -> V_33 ) ;
return V_136 ;
}
static int F_112 ( struct V_34 * V_34 , struct V_21 * V_21 ,
unsigned int V_151 , unsigned int V_145 , bool V_152 , T_6 V_110 ,
bool V_146 )
{
int V_136 = 0 ;
if ( ! V_152 ) {
V_136 = F_108 ( V_34 , V_21 , V_145 , V_110 , V_151 ) ;
F_113 ( V_21 ) ;
} else {
F_113 ( V_21 ) ;
V_136 = F_106 ( V_34 , V_21 , V_145 , V_110 , V_151 , V_146 ) ;
}
return V_136 ;
}
static int F_114 ( struct V_78 * V_79 )
{
struct V_100 * V_90 = V_79 -> V_90 ;
struct V_34 * V_34 = V_79 -> V_73 -> V_27 -> V_34 ;
int V_136 ;
unsigned int V_151 ;
T_6 V_110 ;
struct V_153 V_154 ;
struct V_155 V_156 ;
V_110 = F_115 ( V_90 ) ;
if ( F_116 ( V_90 ) == V_157 ) {
F_109 ( V_34 , V_110 , F_117 ( V_90 ) ) ;
return 0 ;
}
F_100 ( & V_34 -> V_33 ) ;
F_118 (bvec, rq, iter) {
V_151 = V_156 . V_158 ;
V_136 = F_112 ( V_34 , V_156 . V_159 , V_151 , V_156 . V_160 ,
F_119 ( F_116 ( V_90 ) ) , V_110 ,
F_116 ( V_90 ) & V_161 ) ;
if ( V_136 ) {
F_98 ( & V_34 -> V_33 ) ;
return V_136 ;
}
V_110 += V_151 >> V_134 ;
}
F_98 ( & V_34 -> V_33 ) ;
return 0 ;
}
static int F_120 ( struct V_78 * V_79 )
{
struct V_93 * V_93 = V_79 -> V_93 ;
struct V_34 * V_34 = V_79 -> V_73 -> V_27 -> V_34 ;
int V_136 ;
unsigned int V_151 ;
T_6 V_110 ;
struct V_155 V_156 ;
struct V_162 V_154 ;
V_110 = V_93 -> V_163 . V_164 ;
if ( F_121 ( V_93 ) == V_157 ) {
F_109 ( V_34 , V_110 ,
F_122 ( V_93 ) << V_134 ) ;
return 0 ;
}
F_100 ( & V_34 -> V_33 ) ;
F_123 (bvec, bio, iter) {
V_151 = V_156 . V_158 ;
V_136 = F_112 ( V_34 , V_156 . V_159 , V_151 , V_156 . V_160 ,
F_119 ( F_121 ( V_93 ) ) , V_110 ,
F_121 ( V_93 ) & V_161 ) ;
if ( V_136 ) {
F_98 ( & V_34 -> V_33 ) ;
return V_136 ;
}
V_110 += V_151 >> V_134 ;
}
F_98 ( & V_34 -> V_33 ) ;
return 0 ;
}
static void F_124 ( struct V_34 * V_34 )
{
struct V_88 * V_89 = V_34 -> V_89 ;
if ( V_34 -> V_27 -> V_60 == V_14 )
F_125 ( V_89 ) ;
else {
F_100 ( V_89 -> V_95 ) ;
F_126 ( V_89 ) ;
F_98 ( V_89 -> V_95 ) ;
}
}
static void F_127 ( struct V_34 * V_34 )
{
struct V_88 * V_89 = V_34 -> V_89 ;
unsigned long V_30 ;
if ( V_34 -> V_27 -> V_60 == V_14 )
F_128 ( V_89 , true ) ;
else {
F_74 ( V_89 -> V_95 , V_30 ) ;
F_75 ( V_89 ) ;
F_76 ( V_89 -> V_95 , V_30 ) ;
}
}
static T_7 F_129 ( struct V_78 * V_79 )
{
struct V_18 * V_27 = V_79 -> V_73 -> V_27 ;
struct V_34 * V_34 = V_27 -> V_34 ;
int V_136 = 0 ;
if ( F_49 ( V_165 , & V_27 -> V_30 ) ) {
struct V_100 * V_90 = V_79 -> V_90 ;
if ( ! F_130 ( & V_34 -> V_166 ) )
V_96 ( & V_34 -> V_166 ) ;
if ( F_131 ( F_117 ( V_90 ) ,
& V_34 -> V_167 ) < 0 ) {
F_124 ( V_34 ) ;
if ( F_132 ( & V_34 -> V_167 ) > 0 )
F_127 ( V_34 ) ;
if ( V_27 -> V_60 == V_91 ) {
struct V_88 * V_89 = V_34 -> V_89 ;
F_100 ( V_89 -> V_95 ) ;
V_90 -> V_168 |= V_169 ;
F_133 ( V_89 , V_90 ) ;
F_98 ( V_89 -> V_95 ) ;
return V_170 ;
} else
return V_171 ;
}
}
if ( V_34 -> V_27 -> V_36 . V_43 != - 1 ) {
int V_172 ;
T_6 V_110 , V_52 , V_173 ;
bool V_174 = true ;
if ( V_27 -> V_60 == V_13 &&
F_121 ( V_79 -> V_93 ) != V_175 ) {
V_174 = false ;
V_110 = V_79 -> V_93 -> V_163 . V_164 ;
V_52 = F_122 ( V_79 -> V_93 ) ;
}
if ( V_27 -> V_60 != V_13 &&
F_116 ( V_79 -> V_90 ) != V_175 ) {
V_174 = false ;
V_110 = F_115 ( V_79 -> V_90 ) ;
V_52 = F_134 ( V_79 -> V_90 ) ;
}
if ( ! V_174 && F_135 ( & V_34 -> V_27 -> V_36 , V_110 ,
V_52 , & V_173 , & V_172 ) ) {
V_79 -> error = V_176 ;
goto V_42;
}
}
if ( V_27 -> V_177 ) {
if ( V_27 -> V_60 == V_13 ) {
if ( F_121 ( V_79 -> V_93 ) == V_175 )
V_136 = F_110 ( V_34 ) ;
else
V_136 = F_120 ( V_79 ) ;
} else {
if ( F_116 ( V_79 -> V_90 ) == V_175 )
V_136 = F_110 ( V_34 ) ;
else
V_136 = F_114 ( V_79 ) ;
}
}
V_79 -> error = F_136 ( V_136 ) ;
V_42:
switch ( V_27 -> V_63 ) {
case V_178 :
switch ( V_27 -> V_60 ) {
case V_14 :
F_137 ( V_79 -> V_90 ) ;
break;
case V_91 :
F_138 ( V_79 -> V_90 ) ;
break;
case V_13 :
F_68 ( V_79 ) ;
break;
}
break;
case V_16 :
F_68 ( V_79 ) ;
break;
case V_17 :
F_77 ( V_79 ) ;
break;
}
return V_170 ;
}
static enum V_96 F_139 ( struct V_97 * V_81 )
{
struct V_34 * V_34 = F_7 ( V_81 , struct V_34 , V_166 ) ;
T_4 V_179 = F_140 ( 0 , V_180 ) ;
unsigned int V_1 = V_34 -> V_27 -> V_1 ;
if ( F_132 ( & V_34 -> V_167 ) == F_1 ( V_1 ) )
return V_98 ;
F_141 ( & V_34 -> V_167 , F_1 ( V_1 ) ) ;
F_127 ( V_34 ) ;
F_142 ( & V_34 -> V_166 , V_179 ) ;
return V_181 ;
}
static void F_143 ( struct V_34 * V_34 )
{
T_4 V_179 = F_140 ( 0 , V_180 ) ;
F_62 ( & V_34 -> V_166 , V_82 , V_83 ) ;
V_34 -> V_166 . V_84 = F_139 ;
F_141 ( & V_34 -> V_167 , F_1 ( V_34 -> V_27 -> V_1 ) ) ;
F_78 ( & V_34 -> V_166 , V_179 , V_83 ) ;
}
static struct V_72 * F_144 ( struct V_34 * V_34 )
{
int V_119 = 0 ;
if ( V_34 -> V_182 != 1 )
V_119 = F_145 () / ( ( V_183 + V_34 -> V_182 - 1 ) / V_34 -> V_182 ) ;
return & V_34 -> V_184 [ V_119 ] ;
}
static T_8 F_146 ( struct V_88 * V_89 , struct V_93 * V_93 )
{
struct V_34 * V_34 = V_89 -> V_101 ;
struct V_72 * V_73 = F_144 ( V_34 ) ;
struct V_78 * V_79 ;
V_79 = F_63 ( V_73 , 1 ) ;
V_79 -> V_93 = V_93 ;
F_129 ( V_79 ) ;
return V_185 ;
}
static int F_147 ( struct V_88 * V_89 , struct V_100 * V_186 )
{
struct V_34 * V_34 = V_89 -> V_101 ;
struct V_72 * V_73 = F_144 ( V_34 ) ;
struct V_78 * V_79 ;
V_79 = F_63 ( V_73 , 0 ) ;
if ( V_79 ) {
V_79 -> V_90 = V_186 ;
V_186 -> V_102 = V_79 ;
return V_187 ;
}
F_126 ( V_89 ) ;
return V_188 ;
}
static void F_148 ( struct V_88 * V_89 )
{
struct V_100 * V_90 ;
while ( ( V_90 = F_149 ( V_89 ) ) != NULL ) {
struct V_78 * V_79 = V_90 -> V_102 ;
F_98 ( V_89 -> V_95 ) ;
F_129 ( V_79 ) ;
F_100 ( V_89 -> V_95 ) ;
}
}
static T_7 F_150 ( struct V_189 * V_190 ,
const struct V_191 * V_192 )
{
struct V_78 * V_79 = F_80 ( V_192 -> V_90 ) ;
struct V_72 * V_73 = V_190 -> V_193 ;
F_151 ( V_190 -> V_30 & V_194 ) ;
if ( V_73 -> V_27 -> V_63 == V_17 ) {
F_62 ( & V_79 -> V_81 , V_82 , V_83 ) ;
V_79 -> V_81 . V_84 = V_85 ;
}
V_79 -> V_90 = V_192 -> V_90 ;
V_79 -> V_73 = V_73 ;
F_152 ( V_192 -> V_90 ) ;
return F_129 ( V_79 ) ;
}
static void F_153 ( struct V_72 * V_73 )
{
F_35 ( V_73 -> V_75 ) ;
F_35 ( V_73 -> V_80 ) ;
}
static void F_154 ( struct V_34 * V_34 )
{
int V_124 ;
for ( V_124 = 0 ; V_124 < V_34 -> V_182 ; V_124 ++ )
F_153 ( & V_34 -> V_184 [ V_124 ] ) ;
F_35 ( V_34 -> V_184 ) ;
}
static void F_155 ( struct V_100 * V_90 , T_7 V_195 )
{
struct V_196 * V_197 = V_90 -> V_198 ;
V_197 -> error = V_195 ? - V_199 : 0 ;
F_156 ( V_197 ) ;
F_157 ( V_90 ) ;
}
static int F_158 ( struct V_200 * V_27 , struct V_196 * V_197 )
{
struct V_88 * V_89 = V_27 -> V_89 ;
struct V_100 * V_90 ;
struct V_93 * V_93 = V_197 -> V_93 ;
V_90 = F_159 ( V_89 ,
F_119 ( F_121 ( V_93 ) ) ? V_201 : V_202 , 0 ) ;
if ( F_160 ( V_90 ) )
return - V_31 ;
F_161 ( V_90 , V_93 ) ;
V_90 -> V_198 = V_197 ;
F_162 ( V_89 , NULL , V_90 , 0 , F_155 ) ;
return 0 ;
}
static int F_163 ( struct V_200 * V_27 , struct V_203 * V_204 )
{
struct V_34 * V_34 = V_27 -> V_89 -> V_101 ;
T_6 V_52 = ( T_6 ) V_34 -> V_27 -> V_52 * 1024 * 1024ULL ;
T_6 V_205 ;
struct V_206 * V_207 ;
V_204 -> V_208 = 0x1 ;
V_204 -> V_209 = 0 ;
V_204 -> V_210 = 0x2 ;
V_204 -> V_211 = 0x1 ;
V_204 -> V_212 . V_213 = 0 ;
V_204 -> V_212 . V_214 = 16 ;
V_204 -> V_212 . V_215 = 16 ;
V_204 -> V_212 . V_216 = 16 ;
V_204 -> V_212 . V_217 = 32 ;
V_204 -> V_212 . V_218 = 8 ;
V_204 -> V_212 . V_219 = 40 ;
V_204 -> V_212 . V_220 = 8 ;
V_204 -> V_212 . V_221 = 48 ;
V_204 -> V_212 . V_222 = 8 ;
V_204 -> V_212 . V_223 = 56 ;
V_204 -> V_212 . V_224 = 8 ;
F_164 ( V_52 , V_34 -> V_27 -> V_61 ) ;
V_52 >>= 8 ;
V_207 = & V_204 -> V_207 ;
V_207 -> V_225 = 0 ;
V_207 -> V_226 = 0 ;
V_207 -> V_227 = 1 ;
V_207 -> V_228 = 256 ;
V_205 = V_52 ;
V_52 >>= 16 ;
V_207 -> V_229 = V_52 + 1 ;
F_164 ( V_205 , V_207 -> V_229 ) ;
V_207 -> V_230 = V_205 ;
V_207 -> V_231 = 1 ;
V_207 -> V_232 = V_34 -> V_27 -> V_61 ;
V_207 -> V_233 = V_34 -> V_27 -> V_61 ;
V_207 -> V_234 = 25000 ;
V_207 -> V_235 = 25000 ;
V_207 -> V_236 = 500000 ;
V_207 -> V_237 = 500000 ;
V_207 -> V_238 = 1500000 ;
V_207 -> V_239 = 1500000 ;
V_207 -> V_240 = 0x010101 ;
V_207 -> V_241 = V_34 -> V_27 -> V_64 ;
return 0 ;
}
static void * F_165 ( struct V_200 * V_27 , char * V_46 )
{
T_9 * V_242 ;
V_242 = F_166 ( 64 , V_243 ) ;
if ( ! V_242 ) {
F_167 ( L_4 ) ;
return NULL ;
}
return V_242 ;
}
static void F_168 ( void * V_244 )
{
F_169 ( V_244 ) ;
}
static void * F_170 ( struct V_200 * V_27 , void * V_244 ,
T_5 V_245 , T_10 * V_246 )
{
return F_171 ( V_244 , V_245 ) ;
}
static void F_172 ( void * V_244 , void * V_247 ,
T_10 V_246 )
{
F_173 ( V_247 , V_244 ) ;
}
static int F_174 ( struct V_34 * V_34 )
{
struct V_200 * V_27 ;
int V_248 ;
V_27 = F_175 ( 0 ) ;
if ( ! V_27 )
return - V_31 ;
V_27 -> V_89 = V_34 -> V_89 ;
memcpy ( V_27 -> V_46 , V_34 -> V_249 , V_250 ) ;
V_27 -> V_251 = & V_252 ;
V_248 = F_176 ( V_27 ) ;
if ( V_248 ) {
F_35 ( V_27 ) ;
return V_248 ;
}
V_34 -> V_253 = V_27 ;
return 0 ;
}
static void F_177 ( struct V_34 * V_34 )
{
F_178 ( V_34 -> V_253 ) ;
}
static int F_174 ( struct V_34 * V_34 )
{
F_167 ( L_5 ) ;
return - V_9 ;
}
static void F_177 ( struct V_34 * V_34 ) {}
static void F_24 ( struct V_34 * V_34 )
{
struct V_18 * V_27 = V_34 -> V_27 ;
F_179 ( & V_254 , V_34 -> V_119 ) ;
F_180 ( & V_34 -> V_255 ) ;
if ( V_27 -> V_66 )
F_177 ( V_34 ) ;
else
F_181 ( V_34 -> V_256 ) ;
if ( F_49 ( V_165 , & V_34 -> V_27 -> V_30 ) ) {
F_182 ( & V_34 -> V_166 ) ;
F_141 ( & V_34 -> V_167 , V_257 ) ;
F_127 ( V_34 ) ;
}
F_183 ( V_34 -> V_89 ) ;
if ( V_27 -> V_60 == V_14 &&
V_34 -> V_258 == & V_34 -> V_259 )
F_184 ( V_34 -> V_258 ) ;
if ( ! V_27 -> V_66 )
F_185 ( V_34 -> V_256 ) ;
F_154 ( V_34 ) ;
if ( F_48 ( V_34 ) )
F_38 ( V_34 -> V_27 , true ) ;
F_35 ( V_34 ) ;
V_27 -> V_34 = NULL ;
}
static void F_186 ( struct V_34 * V_34 )
{
if ( V_34 -> V_27 -> V_260 == false )
return;
V_34 -> V_89 -> V_261 . V_262 = V_34 -> V_27 -> V_61 ;
V_34 -> V_89 -> V_261 . V_263 = V_34 -> V_27 -> V_61 ;
F_187 ( V_34 -> V_89 , V_264 >> 9 ) ;
F_188 ( V_265 , V_34 -> V_89 ) ;
}
static int F_189 ( struct V_266 * V_267 , T_11 V_268 )
{
return 0 ;
}
static void F_190 ( struct V_269 * V_256 , T_11 V_268 )
{
}
static void F_191 ( struct V_34 * V_34 , struct V_72 * V_73 )
{
F_192 ( ! V_34 ) ;
F_192 ( ! V_73 ) ;
F_193 ( & V_73 -> V_76 ) ;
V_73 -> V_77 = V_34 -> V_77 ;
V_73 -> V_27 = V_34 -> V_27 ;
}
static void F_194 ( struct V_34 * V_34 )
{
struct V_88 * V_89 = V_34 -> V_89 ;
struct V_189 * V_190 ;
struct V_72 * V_73 ;
int V_124 ;
F_195 (q, hctx, i) {
if ( ! V_190 -> V_270 || ! V_190 -> V_271 )
continue;
V_73 = & V_34 -> V_184 [ V_124 ] ;
V_190 -> V_193 = V_73 ;
F_191 ( V_34 , V_73 ) ;
V_34 -> V_182 ++ ;
}
}
static int F_196 ( struct V_72 * V_73 )
{
struct V_78 * V_79 ;
int V_124 , V_272 ;
V_73 -> V_80 = F_50 ( V_73 -> V_77 * sizeof( * V_79 ) , V_41 ) ;
if ( ! V_73 -> V_80 )
return - V_31 ;
V_272 = F_197 ( V_73 -> V_77 , V_273 ) / V_273 ;
V_73 -> V_75 = F_50 ( V_272 * sizeof( unsigned long ) , V_41 ) ;
if ( ! V_73 -> V_75 ) {
F_35 ( V_73 -> V_80 ) ;
return - V_31 ;
}
for ( V_124 = 0 ; V_124 < V_73 -> V_77 ; V_124 ++ ) {
V_79 = & V_73 -> V_80 [ V_124 ] ;
F_70 ( & V_79 -> V_255 ) ;
V_79 -> V_274 . V_150 = NULL ;
V_79 -> V_74 = - 1U ;
}
return 0 ;
}
static int F_198 ( struct V_34 * V_34 )
{
V_34 -> V_184 = F_50 ( V_34 -> V_27 -> V_56 *
sizeof( struct V_72 ) , V_41 ) ;
if ( ! V_34 -> V_184 )
return - V_31 ;
V_34 -> V_182 = 0 ;
V_34 -> V_77 = V_34 -> V_27 -> V_64 ;
return 0 ;
}
static int F_199 ( struct V_34 * V_34 )
{
struct V_72 * V_73 ;
int V_124 , V_7 = 0 ;
for ( V_124 = 0 ; V_124 < V_34 -> V_27 -> V_56 ; V_124 ++ ) {
V_73 = & V_34 -> V_184 [ V_124 ] ;
F_191 ( V_34 , V_73 ) ;
V_7 = F_196 ( V_73 ) ;
if ( V_7 )
return V_7 ;
V_34 -> V_182 ++ ;
}
return 0 ;
}
static int F_200 ( struct V_34 * V_34 )
{
struct V_269 * V_256 ;
T_6 V_52 ;
V_256 = V_34 -> V_256 = F_201 ( 1 , V_34 -> V_27 -> V_58 ) ;
if ( ! V_256 )
return - V_31 ;
V_52 = ( T_6 ) V_34 -> V_27 -> V_52 * 1024 * 1024ULL ;
F_202 ( V_256 , V_52 >> 9 ) ;
V_256 -> V_30 |= V_275 | V_276 ;
V_256 -> V_277 = V_278 ;
V_256 -> V_279 = V_34 -> V_119 ;
V_256 -> V_280 = & V_281 ;
V_256 -> V_282 = V_34 ;
V_256 -> V_283 = V_34 -> V_89 ;
strncpy ( V_256 -> V_249 , V_34 -> V_249 , V_250 ) ;
F_203 ( V_256 ) ;
return 0 ;
}
static int F_204 ( struct V_34 * V_34 , struct V_284 * V_285 )
{
V_285 -> V_251 = & V_286 ;
V_285 -> V_287 = V_34 ? V_34 -> V_27 -> V_56 :
V_57 ;
V_285 -> V_77 = V_34 ? V_34 -> V_27 -> V_64 :
V_65 ;
V_285 -> V_288 = V_34 ? V_34 -> V_27 -> V_58 : V_59 ;
V_285 -> V_289 = sizeof( struct V_78 ) ;
V_285 -> V_30 = V_290 ;
V_285 -> V_193 = NULL ;
if ( ( V_34 && V_34 -> V_27 -> V_68 ) || V_69 )
V_285 -> V_30 |= V_194 ;
return F_205 ( V_285 ) ;
}
static void F_206 ( struct V_18 * V_27 )
{
V_27 -> V_61 = F_207 ( V_27 -> V_61 , 512 ) ;
V_27 -> V_61 = F_208 (unsigned int, dev->blocksize, 512 , 4096 ) ;
if ( V_27 -> V_66 && V_27 -> V_61 != 4096 )
V_27 -> V_61 = 4096 ;
if ( V_27 -> V_66 && V_27 -> V_60 != V_14 )
V_27 -> V_60 = V_14 ;
if ( V_27 -> V_60 == V_14 && V_27 -> V_70 ) {
if ( V_27 -> V_56 != V_291 )
V_27 -> V_56 = V_291 ;
} else if ( V_27 -> V_56 > V_183 )
V_27 -> V_56 = V_183 ;
else if ( V_27 -> V_56 == 0 )
V_27 -> V_56 = 1 ;
V_27 -> V_60 = F_107 (unsigned int, dev->queue_mode, NULL_Q_MQ) ;
V_27 -> V_63 = F_107 (unsigned int, dev->irqmode, NULL_IRQ_TIMER) ;
if ( V_27 -> V_177 )
V_27 -> V_68 = true ;
else
V_27 -> V_141 = 0 ;
V_27 -> V_141 = F_107 (unsigned long, ULONG_MAX / 1024 / 1024 ,
dev->cache_size) ;
V_27 -> V_1 = F_107 (unsigned int, 1024 * 40 , dev->mbps) ;
if ( V_27 -> V_60 == V_13 )
V_27 -> V_1 = 0 ;
}
static int F_20 ( struct V_18 * V_27 )
{
struct V_34 * V_34 ;
int V_248 ;
F_206 ( V_27 ) ;
V_34 = F_209 ( sizeof( * V_34 ) , V_41 , V_27 -> V_58 ) ;
if ( ! V_34 ) {
V_248 = - V_31 ;
goto V_42;
}
V_34 -> V_27 = V_27 ;
V_27 -> V_34 = V_34 ;
F_210 ( & V_34 -> V_33 ) ;
V_248 = F_198 ( V_34 ) ;
if ( V_248 )
goto V_292;
if ( V_27 -> V_60 == V_14 ) {
if ( V_293 ) {
V_34 -> V_258 = & V_258 ;
V_248 = 0 ;
} else {
V_34 -> V_258 = & V_34 -> V_259 ;
V_248 = F_204 ( V_34 , V_34 -> V_258 ) ;
}
if ( V_248 )
goto V_294;
V_34 -> V_89 = F_211 ( V_34 -> V_258 ) ;
if ( F_160 ( V_34 -> V_89 ) ) {
V_248 = - V_31 ;
goto V_295;
}
F_194 ( V_34 ) ;
} else if ( V_27 -> V_60 == V_13 ) {
V_34 -> V_89 = F_212 ( V_41 , V_27 -> V_58 ) ;
if ( ! V_34 -> V_89 ) {
V_248 = - V_31 ;
goto V_294;
}
F_213 ( V_34 -> V_89 , F_146 ) ;
V_248 = F_199 ( V_34 ) ;
if ( V_248 )
goto V_296;
} else {
V_34 -> V_89 = F_214 ( F_148 , & V_34 -> V_33 ,
V_27 -> V_58 ) ;
if ( ! V_34 -> V_89 ) {
V_248 = - V_31 ;
goto V_294;
}
F_215 ( V_34 -> V_89 , F_147 ) ;
F_216 ( V_34 -> V_89 , F_79 ) ;
V_248 = F_199 ( V_34 ) ;
if ( V_248 )
goto V_296;
}
if ( V_27 -> V_1 ) {
F_22 ( V_165 , & V_27 -> V_30 ) ;
F_143 ( V_34 ) ;
}
if ( V_27 -> V_141 > 0 ) {
F_22 ( V_48 , & V_34 -> V_27 -> V_30 ) ;
F_217 ( V_34 -> V_89 , true , true ) ;
F_218 ( V_34 -> V_89 , true ) ;
}
V_34 -> V_89 -> V_101 = V_34 ;
F_188 ( V_297 , V_34 -> V_89 ) ;
F_219 ( V_298 , V_34 -> V_89 ) ;
F_23 ( & V_33 ) ;
V_34 -> V_119 = F_220 ( & V_254 , 0 , 0 , V_41 ) ;
V_27 -> V_119 = V_34 -> V_119 ;
F_25 ( & V_33 ) ;
F_221 ( V_34 -> V_89 , V_27 -> V_61 ) ;
F_222 ( V_34 -> V_89 , V_27 -> V_61 ) ;
F_186 ( V_34 ) ;
sprintf ( V_34 -> V_249 , L_6 , V_34 -> V_119 ) ;
if ( V_27 -> V_66 )
V_248 = F_174 ( V_34 ) ;
else
V_248 = F_200 ( V_34 ) ;
if ( V_248 )
goto V_296;
F_23 ( & V_33 ) ;
F_223 ( & V_34 -> V_255 , & V_299 ) ;
F_25 ( & V_33 ) ;
return 0 ;
V_296:
F_183 ( V_34 -> V_89 ) ;
V_295:
if ( V_27 -> V_60 == V_14 && V_34 -> V_258 == & V_34 -> V_259 )
F_184 ( V_34 -> V_258 ) ;
V_294:
F_154 ( V_34 ) ;
V_292:
F_35 ( V_34 ) ;
V_42:
return V_248 ;
}
static int T_12 F_224 ( void )
{
int V_7 = 0 ;
unsigned int V_124 ;
struct V_34 * V_34 ;
struct V_18 * V_27 ;
if (sizeof( unsigned long ) * 8 - 2 < ( V_22 >> V_134 ) )
return - V_9 ;
if ( V_62 > V_22 ) {
F_225 ( L_7 ) ;
F_225 ( L_8 , V_22 ) ;
V_62 = V_22 ;
}
if ( V_67 && V_62 != 4096 ) {
F_225 ( L_9 ) ;
F_225 ( L_10 ) ;
V_62 = 4096 ;
}
if ( V_67 && V_12 != V_14 ) {
F_225 ( L_11 ) ;
F_225 ( L_12 ) ;
V_12 = V_14 ;
}
if ( V_12 == V_14 && V_71 ) {
if ( V_57 != V_291 ) {
F_225 ( L_13 ,
V_291 ) ;
V_57 = V_291 ;
}
} else if ( V_57 > V_183 )
V_57 = V_183 ;
else if ( V_57 <= 0 )
V_57 = 1 ;
if ( V_12 == V_14 && V_293 ) {
V_7 = F_204 ( NULL , & V_258 ) ;
if ( V_7 )
return V_7 ;
}
F_226 ( & V_300 . V_301 ) ;
F_227 ( & V_300 . V_302 ) ;
V_7 = F_228 ( & V_300 ) ;
if ( V_7 )
goto V_303;
F_227 ( & V_33 ) ;
V_278 = F_229 ( 0 , L_14 ) ;
if ( V_278 < 0 ) {
V_7 = V_278 ;
goto V_304;
}
if ( V_67 ) {
V_243 = F_230 ( L_15 , 64 * sizeof( T_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_243 ) {
F_167 ( L_16 ) ;
V_7 = - V_31 ;
goto V_305;
}
}
for ( V_124 = 0 ; V_124 < V_306 ; V_124 ++ ) {
V_27 = F_41 () ;
if ( ! V_27 )
goto V_307;
V_7 = F_20 ( V_27 ) ;
if ( V_7 ) {
F_39 ( V_27 ) ;
goto V_307;
}
}
F_231 ( L_17 ) ;
return 0 ;
V_307:
while ( ! F_232 ( & V_299 ) ) {
V_34 = F_233 ( V_299 . V_150 , struct V_34 , V_255 ) ;
V_27 = V_34 -> V_27 ;
F_24 ( V_34 ) ;
F_39 ( V_27 ) ;
}
F_234 ( V_243 ) ;
V_305:
F_235 ( V_278 , L_14 ) ;
V_304:
F_236 ( & V_300 ) ;
V_303:
if ( V_12 == V_14 && V_293 )
F_184 ( & V_258 ) ;
return V_7 ;
}
static void T_13 F_237 ( void )
{
struct V_34 * V_34 ;
F_236 ( & V_300 ) ;
F_235 ( V_278 , L_14 ) ;
F_23 ( & V_33 ) ;
while ( ! F_232 ( & V_299 ) ) {
struct V_18 * V_27 ;
V_34 = F_233 ( V_299 . V_150 , struct V_34 , V_255 ) ;
V_27 = V_34 -> V_27 ;
F_24 ( V_34 ) ;
F_39 ( V_27 ) ;
}
F_25 ( & V_33 ) ;
if ( V_12 == V_14 && V_293 )
F_184 ( & V_258 ) ;
F_234 ( V_243 ) ;
}
