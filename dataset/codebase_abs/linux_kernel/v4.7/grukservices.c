static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
void * V_8 ;
int V_9 , V_10 ;
F_2 ( & V_2 -> V_11 ) ;
F_3 ( & V_2 -> V_11 ) ;
if ( ! V_2 -> V_12 ) {
do {
V_2 -> V_12 = F_4 ( NULL , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! F_5 ( V_2 -> V_12 ) )
break;
F_6 ( 1 ) ;
} while ( true );
V_2 -> V_12 -> V_13 = V_3 ;
}
V_7 = V_2 -> V_12 ;
if ( ! V_7 -> V_14 ) {
F_7 ( V_15 ) ;
V_10 = F_8 ( V_3 ) ;
V_7 -> V_16 = F_9 (
V_17 * V_10 + V_2 -> V_18 ) ;
V_7 -> V_19 = F_10 (
V_20 * V_10 +
V_2 -> V_21 ) ;
while ( ! F_11 ( V_7 ) ) {
F_6 ( 1 ) ;
F_12 ( V_7 ) ;
}
F_13 ( V_7 ) ;
V_5 = V_2 -> V_12 -> V_14 ;
V_8 = V_5 -> V_22 ;
V_9 = V_7 -> V_23 ;
V_2 -> V_24 = F_14 ( V_8 , V_9 , 0 ) ;
V_2 -> V_25 = F_15 ( V_8 , V_9 , 0 ) ;
}
F_16 ( & V_2 -> V_11 ) ;
}
static int F_17 ( void )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
int V_26 , V_27 = 0 ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
V_2 = V_29 [ V_26 ] ;
if ( ! V_2 )
continue;
if ( F_18 ( & V_2 -> V_11 ) ) {
V_7 = V_2 -> V_12 ;
if ( V_7 && V_7 -> V_14 )
F_19 ( V_7 , 0 ) ;
V_2 -> V_12 = NULL ;
F_20 ( & V_2 -> V_11 ) ;
F_21 ( V_7 ) ;
} else {
V_27 ++ ;
}
}
return V_27 ;
}
static struct V_1 * F_22 ( int V_3 )
{
struct V_1 * V_2 ;
int V_26 ;
F_7 ( V_30 ) ;
V_31:
V_26 = V_3 < 0 ? F_23 () : V_3 ;
V_2 = V_29 [ V_26 ] ;
F_24 ( & V_2 -> V_11 ) ;
if ( V_3 < 0 && V_26 != F_23 () ) {
F_2 ( & V_2 -> V_11 ) ;
goto V_31;
}
if ( ! V_2 -> V_12 || ! V_2 -> V_12 -> V_14 )
F_1 ( V_2 , V_26 ) ;
return V_2 ;
}
static void F_25 ( int V_3 )
{
struct V_1 * V_2 ;
V_2 = V_29 [ V_3 ] ;
F_2 ( & V_2 -> V_11 ) ;
F_7 ( V_32 ) ;
}
static int F_26 ( int V_33 , void * * V_34 , void * * V_35 )
{
struct V_1 * V_2 ;
int V_36 ;
F_27 ( V_33 > V_20 ) ;
F_28 () ;
V_2 = F_22 ( - 1 ) ;
V_36 = F_29 () ;
* V_34 = V_2 -> V_24 + V_36 * V_37 ;
* V_35 = V_2 -> V_25 + V_36 * V_20 ;
return 0 ;
}
static void F_30 ( void * V_34 , void * V_35 )
{
F_25 ( F_23 () ) ;
F_31 () ;
}
unsigned long F_32 ( int V_3 , int V_38 , int V_33 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
int V_27 = 0 ;
V_2 = V_29 [ V_3 ] ;
F_3 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_21 + V_2 -> V_18 )
goto V_41;
V_2 -> V_21 = V_33 ;
V_2 -> V_18 = V_38 ;
V_2 -> V_42 = V_40 ;
V_7 = V_2 -> V_12 ;
if ( V_7 && V_7 -> V_14 )
F_19 ( V_7 , 0 ) ;
V_27 = F_33 ( V_3 ) ;
V_41:
F_20 ( & V_2 -> V_11 ) ;
return V_27 ;
}
void F_34 ( unsigned long V_43 )
{
struct V_1 * V_2 = F_35 ( V_43 ) ;
F_3 ( & V_2 -> V_11 ) ;
V_2 -> V_21 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_42 = NULL ;
F_20 ( & V_2 -> V_11 ) ;
}
void F_36 ( unsigned long V_43 )
{
struct V_1 * V_2 = F_35 ( V_43 ) ;
F_37 ( V_2 -> V_42 ) ;
F_38 () ;
}
void F_39 ( unsigned long V_43 , void * * V_34 , void * * V_35 )
{
struct V_1 * V_2 = F_35 ( V_43 ) ;
int V_3 = F_40 ( V_43 ) ;
int V_10 ;
F_22 ( V_3 ) ;
V_10 = F_8 ( V_3 ) ;
if ( V_34 )
* V_34 = V_2 -> V_24 + V_10 * V_37 ;
if ( V_35 )
* V_35 = V_2 -> V_25 + V_10 * V_20 ;
}
void F_41 ( unsigned long V_43 )
{
int V_3 = F_40 ( V_43 ) ;
F_25 ( V_3 ) ;
}
int F_42 ( void * V_34 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 ;
struct V_6 * V_7 = NULL ;
unsigned long V_48 ;
int V_49 , V_26 ;
F_43 (bid) {
if ( ! V_29 [ V_26 ] )
break;
V_7 = V_29 [ V_26 ] -> V_12 ;
if ( ! V_7 || ! V_7 -> V_14 )
continue;
V_48 = V_34 - V_7 -> V_14 -> V_22 ;
if ( V_48 < V_50 )
break;
V_7 = NULL ;
}
F_27 ( ! V_7 ) ;
V_49 = F_44 ( V_7 , F_45 ( V_34 ) ) ;
V_47 = F_46 ( F_47 ( V_34 ) , V_49 ) ;
F_48 ( V_47 ) ;
F_49 () ;
V_45 -> V_51 = V_47 -> V_52 ;
V_45 -> V_53 = V_47 -> V_54 ;
V_45 -> V_55 = V_47 -> V_55 ;
V_45 -> V_56 = V_47 -> V_57 ;
V_45 -> V_58 = V_47 -> V_59 ;
F_48 ( V_47 ) ;
return 0 ;
}
static char * F_50 ( int V_27 , void * V_34 ,
char * V_60 , int V_61 )
{
struct V_62 * V_63 = ( void * ) V_34 ;
struct V_44 V_45 ;
if ( V_27 > 0 && V_63 -> V_64 == V_65 ) {
F_42 ( V_34 , & V_45 ) ;
snprintf ( V_60 , V_61 ,
L_1
L_2 , F_51 () ,
V_63 , V_45 . V_51 , V_45 . V_53 , V_45 . V_55 ,
V_45 . V_56 , V_45 . V_58 ) ;
} else {
snprintf ( V_60 , V_61 , L_3 ) ;
}
return V_60 ;
}
static int F_52 ( struct V_62 * V_63 )
{
while ( V_63 -> V_64 >= V_66 ) {
F_53 () ;
F_54 () ;
}
return V_63 -> V_64 ;
}
static int F_55 ( void * V_34 )
{
struct V_62 * V_63 = ( void * ) V_34 ;
struct V_44 V_45 ;
int V_67 = V_68 ;
while ( 1 ) {
if ( F_52 ( V_63 ) == V_69 )
return V_69 ;
if ( F_56 ( V_34 ) )
return V_65 ;
F_42 ( V_34 , & V_45 ) ;
if ( ( V_45 . V_55 & ~ V_70 ) ||
( V_45 . V_71 & V_72 ) )
break;
if ( V_67 -- == 0 )
break;
V_63 -> V_73 = 1 ;
F_48 ( V_63 ) ;
}
return V_65 ;
}
int F_57 ( void * V_34 )
{
struct V_62 * V_63 = ( void * ) V_34 ;
int V_27 ;
V_27 = V_63 -> V_64 ;
if ( V_27 == V_65 )
V_27 = F_55 ( V_34 ) ;
F_58 () ;
return V_27 ;
}
int F_59 ( void * V_34 )
{
struct V_62 * V_63 = ( void * ) V_34 ;
int V_27 ;
V_27 = F_52 ( V_63 ) ;
if ( V_27 == V_65 )
V_27 = F_55 ( V_34 ) ;
F_58 () ;
return V_27 ;
}
static void F_60 ( int V_27 , void * V_34 , char * V_74 )
{
char V_60 [ V_75 ] ;
F_61 ( L_4 , V_74 ,
F_50 ( V_27 , V_34 , V_60 , sizeof( V_60 ) ) ) ;
}
void F_62 ( void * V_34 )
{
int V_27 ;
V_27 = F_59 ( V_34 ) ;
if ( V_27 )
F_60 ( V_27 , V_34 , L_5 ) ;
}
static inline int F_63 ( void * V_76 )
{
struct V_77 * V_78 = V_76 + V_79 ;
return V_78 -> V_80 ;
}
static inline void F_64 ( void * V_76 , int V_81 )
{
struct V_77 * V_78 = V_76 + V_79 ;
V_78 -> V_80 = V_81 ;
}
int F_65 ( struct V_82 * V_83 ,
void * V_76 , unsigned int V_84 , int V_85 , int V_86 , int V_87 )
{
struct V_88 * V_89 = V_76 ;
unsigned int V_90 ;
V_90 = V_84 / V_79 - 2 ;
memset ( V_89 , 0 , V_84 ) ;
V_89 -> V_91 = & V_89 -> V_92 ;
V_89 -> V_93 = & V_89 -> V_92 + ( V_90 / 2 - 1 ) * V_79 ;
V_89 -> V_94 = & V_89 -> V_92 ;
V_89 -> V_95 = & V_89 -> V_92 + ( V_90 - 2 ) * V_79 ;
V_89 -> V_90 = V_90 ;
V_89 -> V_96 [ 0 ] = 0 ;
V_89 -> V_96 [ 1 ] = 1 ;
V_89 -> V_97 = F_66 ( 2 , V_90 / 2 + 1 ) ;
V_83 -> V_89 = V_89 ;
V_83 -> V_98 = F_67 ( V_89 ) ;
V_83 -> V_90 = V_90 ;
V_83 -> V_99 = V_85 >> 1 ;
V_83 -> V_100 = V_86 ;
V_83 -> V_101 = V_87 ;
return 0 ;
}
static int F_68 ( void * V_34 , struct V_82 * V_83 ,
void * V_102 )
{
const struct V_77 V_103 = {
. V_80 = V_104 , . V_105 = 1 } ;
unsigned long V_106 ;
int V_107 , V_27 ;
struct V_77 V_108 , * V_78 = V_102 ;
F_7 ( V_109 ) ;
V_108 = * V_78 ;
* V_78 = V_103 ;
F_69 ( V_34 , V_83 -> V_98 , F_70 ( V_78 ) , 1 , V_110 ) ;
V_27 = F_71 ( V_34 ) ;
if ( V_27 ) {
V_107 = F_56 ( V_34 ) ;
switch ( V_107 ) {
case V_111 :
F_7 ( V_112 ) ;
V_27 = V_113 ;
break;
case V_114 :
F_7 ( V_115 ) ;
V_27 = V_116 ;
break;
case V_117 :
F_7 ( V_118 ) ;
V_27 = 0 ;
break;
case V_119 :
F_7 ( V_120 ) ;
V_27 = V_116 ;
break;
case V_121 :
F_7 ( V_122 ) ;
V_106 = V_83 -> V_98 + ( F_72 ( V_34 ) << 6 ) ;
F_73 ( V_34 , V_106 , F_70 ( V_102 ) , V_123 , 1 , 1 ,
V_110 ) ;
if ( F_71 ( V_34 ) == V_69 )
V_27 = V_124 ;
else
V_27 = V_113 ;
break;
case V_125 :
F_7 ( V_126 ) ;
default:
F_74 () ;
}
}
* V_78 = V_108 ;
return V_27 ;
}
static int F_75 ( void * V_34 , struct V_82 * V_83 ,
void * V_102 , int V_105 )
{
union V_127 V_128 ;
unsigned int V_95 , V_97 ;
unsigned long V_129 ;
int V_130 , V_90 ;
V_129 = F_76 ( V_34 ) ;
V_97 = F_72 ( V_34 ) ;
V_95 = F_77 ( V_34 ) ;
V_90 = V_83 -> V_90 ;
V_130 = ( V_95 != V_90 ) ;
if ( V_130 )
V_128 = F_66 ( V_90 / 2 + 1 , V_90 ) ;
else
V_128 = F_66 ( 2 , V_90 / 2 + 1 ) ;
F_78 ( V_34 , V_131 , F_79 ( V_83 -> V_98 , V_130 ) , V_132 , V_110 ) ;
if ( F_71 ( V_34 ) != V_69 )
goto V_133;
if ( ! F_76 ( V_34 ) ) {
F_7 ( V_134 ) ;
return V_135 ;
}
if ( V_97 != V_95 ) {
if ( F_68 ( V_34 , V_83 , V_102 ) ) {
F_78 ( V_34 , V_136 , F_79 ( V_83 -> V_98 , V_130 ) ,
V_132 , V_110 ) ;
if ( F_71 ( V_34 ) != V_69 )
goto V_133;
F_7 ( V_137 ) ;
return V_124 ;
}
V_129 ++ ;
}
F_80 ( V_34 , V_138 , V_83 -> V_98 , V_132 , V_128 . V_81 , V_129 ,
V_110 ) ;
if ( F_71 ( V_34 ) != V_69 )
goto V_133;
if ( F_76 ( V_34 ) != V_129 ) {
F_7 ( V_139 ) ;
F_78 ( V_34 , V_136 , F_79 ( V_83 -> V_98 , V_130 ) , V_132 ,
V_110 ) ;
if ( F_71 ( V_34 ) != V_69 )
goto V_133;
}
return V_124 ;
V_133:
F_7 ( V_140 ) ;
return V_113 ;
}
static int F_81 ( void * V_34 , struct V_82 * V_83 ,
void * V_102 , int V_105 )
{
unsigned long V_106 ;
int V_27 , V_141 = 200 ;
V_106 = V_83 -> V_98 + ( F_72 ( V_34 ) << 6 ) ;
if ( V_105 == 2 ) {
F_82 ( V_34 , V_106 , 0 , V_123 , V_105 , 1 , V_110 ) ;
if ( F_71 ( V_34 ) != V_69 )
return V_113 ;
}
F_73 ( V_34 , V_106 , F_70 ( V_102 ) , V_123 , V_105 , 1 , V_110 ) ;
if ( F_71 ( V_34 ) != V_69 )
return V_113 ;
if ( ! V_83 -> V_100 )
return V_142 ;
do {
V_27 = F_68 ( V_34 , V_83 , V_102 ) ;
} while ( ( V_27 == V_124 || V_27 == V_116 ) && ( V_141 -- > 0 ) );
if ( V_27 == V_124 || V_27 == V_116 ) {
V_27 = V_142 ;
}
return V_27 ;
}
static int F_83 ( void * V_34 , struct V_82 * V_83 ,
void * V_102 , int V_105 )
{
int V_107 , V_27 = 0 ;
V_107 = F_56 ( V_34 ) ;
switch ( V_107 ) {
case V_111 :
F_7 ( V_143 ) ;
V_27 = V_113 ;
break;
case V_114 :
F_7 ( V_144 ) ;
V_27 = V_116 ;
break;
case V_117 :
F_7 ( V_145 ) ;
V_27 = F_75 ( V_34 , V_83 , V_102 , V_105 ) ;
break;
case V_119 :
F_7 ( V_146 ) ;
V_27 = V_116 ;
break;
case V_121 :
F_7 ( V_147 ) ;
V_27 = F_81 ( V_34 , V_83 , V_102 , V_105 ) ;
break;
case V_125 :
F_7 ( V_148 ) ;
default:
F_74 () ;
}
return V_27 ;
}
int F_84 ( struct V_82 * V_83 , void * V_102 ,
unsigned int V_84 )
{
struct V_77 * V_78 ;
void * V_34 ;
void * V_35 ;
int V_64 , V_149 , V_27 ;
F_7 ( V_150 ) ;
F_27 ( V_84 < sizeof( int ) || V_84 > 2 * V_79 ) ;
V_149 = F_85 ( V_84 , V_79 ) ;
if ( F_26 ( V_84 , & V_34 , & V_35 ) )
return V_151 ;
memcpy ( V_35 , V_102 , V_84 ) ;
V_78 = V_35 ;
V_78 -> V_80 = V_152 ;
V_78 -> V_105 = V_149 ;
if ( V_149 == 2 ) {
V_78 -> V_153 = F_63 ( V_78 ) ;
F_64 ( V_78 , V_152 ) ;
}
do {
V_27 = V_142 ;
F_69 ( V_34 , V_83 -> V_98 , F_70 ( V_78 ) , V_149 , V_110 ) ;
V_64 = F_71 ( V_34 ) ;
if ( V_64 != V_69 )
V_27 = F_83 ( V_34 , V_83 , V_35 , V_149 ) ;
} while ( V_27 == V_124 );
F_30 ( V_34 , V_35 ) ;
if ( V_27 )
F_7 ( V_154 ) ;
return V_27 ;
}
void F_86 ( struct V_82 * V_83 , void * V_102 )
{
struct V_88 * V_89 = V_83 -> V_89 ;
struct V_77 * V_78 = V_89 -> V_94 ;
void * V_94 , * V_155 ;
int V_130 = - 1 ;
int V_105 = V_78 -> V_105 ;
if ( V_105 == 2 )
F_64 ( V_78 , V_156 ) ;
V_78 -> V_80 = V_156 ;
V_155 = V_89 -> V_94 ;
V_94 = V_155 + V_79 * V_105 ;
if ( V_94 == V_89 -> V_95 ) {
V_94 = V_89 -> V_91 ;
V_130 = 1 ;
} else if ( V_155 < V_89 -> V_93 && V_94 >= V_89 -> V_93 ) {
V_130 = 0 ;
}
if ( V_130 >= 0 )
V_89 -> V_96 [ V_130 ] = 1 ;
V_89 -> V_94 = V_94 ;
}
void * F_87 ( struct V_82 * V_83 )
{
struct V_88 * V_89 = V_83 -> V_89 ;
struct V_77 * V_78 = V_89 -> V_94 ;
int V_80 = V_78 -> V_80 ;
while ( V_80 == V_104 ) {
F_86 ( V_83 , V_78 ) ;
V_78 = V_89 -> V_94 ;
V_80 = V_78 -> V_80 ;
}
if ( V_80 == V_152 && V_78 -> V_105 == 2 &&
F_63 ( V_78 ) == V_156 )
V_80 = V_156 ;
if ( ! V_80 ) {
F_7 ( V_157 ) ;
return NULL ;
}
if ( V_78 -> V_105 == 2 )
F_64 ( V_78 , V_78 -> V_153 ) ;
F_7 ( V_158 ) ;
return V_78 ;
}
int F_88 ( unsigned long * V_159 , unsigned long V_160 )
{
void * V_34 ;
void * V_35 ;
int V_27 , V_161 ;
F_7 ( V_162 ) ;
if ( F_26 ( V_20 , & V_34 , & V_35 ) )
return V_151 ;
V_161 = V_160 >> 62 ;
F_89 ( V_34 , V_160 , F_70 ( V_35 ) , V_161 , V_110 ) ;
V_27 = F_71 ( V_34 ) ;
if ( V_27 == V_69 )
* V_159 = * ( unsigned long * ) V_35 ;
F_30 ( V_34 , V_35 ) ;
return V_27 ;
}
int F_90 ( unsigned long V_163 , unsigned long V_164 ,
unsigned int V_84 )
{
void * V_34 ;
void * V_35 ;
int V_27 ;
F_7 ( V_165 ) ;
if ( F_26 ( V_20 , & V_34 , & V_35 ) )
return V_151 ;
F_91 ( V_34 , V_164 , V_163 , F_70 ( V_35 ) ,
V_166 , V_84 , V_167 , V_110 ) ;
V_27 = F_71 ( V_34 ) ;
F_30 ( V_34 , V_35 ) ;
return V_27 ;
}
static int F_92 ( unsigned long V_168 )
{
unsigned long V_169 ;
unsigned long V_170 ;
void * V_34 ;
void * V_35 ;
unsigned long * V_76 ;
int V_27 = - V_171 ;
if ( F_26 ( V_79 , & V_34 , & V_35 ) )
return V_151 ;
V_76 = V_35 ;
V_169 = V_172 ;
V_170 = 0 ;
F_93 ( V_34 , F_67 ( & V_169 ) , F_70 ( V_35 ) , V_132 , 1 , 1 , V_110 ) ;
if ( F_71 ( V_34 ) != V_69 ) {
F_94 ( V_173 L_6 , F_51 () ) ;
goto V_41;
}
if ( * V_76 != V_172 ) {
F_94 ( V_173 L_7 , F_51 () , * V_76 ) ;
goto V_41;
}
F_73 ( V_34 , F_67 ( & V_170 ) , F_70 ( V_35 ) , V_132 , 1 , 1 , V_110 ) ;
if ( F_71 ( V_34 ) != V_69 ) {
F_94 ( V_173 L_8 , F_51 () ) ;
goto V_41;
}
if ( V_169 != V_170 || V_170 != V_172 ) {
F_94 ( V_173
L_9 ,
F_51 () , V_170 , V_172 ) ;
goto V_41;
}
V_27 = 0 ;
V_41:
F_30 ( V_34 , V_35 ) ;
return V_27 ;
}
static int F_95 ( unsigned long V_168 )
{
struct V_82 V_83 ;
void * V_76 , * V_89 ;
int V_174 , V_27 = - V_171 ;
char V_175 [ V_79 ] , * V_106 ;
V_76 = F_96 ( 4096 , 0 ) ;
if ( V_76 == NULL )
return - V_176 ;
V_89 = F_97 ( V_76 , 1024 ) ;
memset ( V_175 , 0xee , sizeof( V_175 ) ) ;
F_65 ( & V_83 , V_89 , 8 * V_79 , 0 , 0 , 0 ) ;
for ( V_174 = 0 ; V_174 < 6 ; V_174 ++ ) {
V_175 [ 8 ] = V_174 ;
do {
V_27 = F_84 ( & V_83 , V_175 , sizeof( V_175 ) ) ;
} while ( V_27 == V_116 );
if ( V_27 )
break;
}
if ( V_27 != V_135 || V_174 != 4 ) {
F_94 ( V_173 L_10 ,
F_51 () , V_27 , V_174 ) ;
goto V_41;
}
for ( V_174 = 0 ; V_174 < 6 ; V_174 ++ ) {
V_106 = F_87 ( & V_83 ) ;
if ( ! V_106 || V_106 [ 8 ] != V_174 )
break;
F_86 ( & V_83 , V_106 ) ;
}
if ( V_174 != 4 ) {
F_94 ( V_173 L_11 ,
F_51 () , V_174 , V_106 , V_106 ? V_106 [ 8 ] : - 1 ) ;
goto V_41;
}
V_27 = 0 ;
V_41:
F_21 ( V_76 ) ;
return V_27 ;
}
static int F_98 ( unsigned long V_168 )
{
static F_99 ( V_40 ) ;
unsigned long V_43 ;
int V_3 = 0 ;
int V_177 = 4 ;
int V_27 = 0 ;
unsigned long * V_60 ;
void * V_178 , * V_34 ;
struct V_62 * V_63 ;
int V_174 , V_179 , V_64 , V_84 ;
V_84 = V_177 * 4 * 8 ;
V_60 = F_96 ( V_84 , V_180 ) ;
if ( ! V_60 )
return - V_176 ;
V_27 = - V_181 ;
V_43 = F_32 ( V_3 , V_177 , 0 , & V_40 ) ;
if ( ! V_43 )
goto V_41;
F_39 ( V_43 , & V_178 , NULL ) ;
memset ( V_60 , 0xee , V_84 ) ;
for ( V_174 = 0 ; V_174 < V_177 ; V_174 ++ )
F_82 ( V_178 + V_174 * V_37 , F_67 ( & V_60 [ V_174 * 4 ] ) , 0 ,
V_132 , 4 , 1 , V_182 ) ;
V_27 = 0 ;
V_179 = V_177 ;
do {
F_36 ( V_43 ) ;
for ( V_174 = 0 ; V_174 < V_177 ; V_174 ++ ) {
V_34 = V_178 + V_174 * V_37 ;
V_64 = F_100 ( V_34 ) ;
if ( V_64 != V_66 && V_64 != V_183 )
break;
}
if ( V_174 == V_177 )
continue;
if ( V_64 != V_69 ) {
F_94 ( V_173 L_12 , F_51 () , V_174 ) ;
V_27 = - V_184 ;
} else if ( V_60 [ 4 * V_174 ] || V_60 [ 4 * V_174 + 1 ] || V_60 [ 4 * V_174 + 2 ] ||
V_60 [ 4 * V_174 + 3 ] ) {
F_94 ( V_173 L_13 ,
F_51 () , V_174 , V_60 [ 4 * V_174 ] , V_60 [ 4 * V_174 + 1 ] , V_60 [ 4 * V_174 + 2 ] , V_60 [ 4 * V_174 + 3 ] ) ;
V_27 = - V_171 ;
}
V_179 -- ;
V_63 = V_34 ;
V_63 -> V_64 = V_183 ;
} while ( V_179 );
F_27 ( V_40 . V_41 ) ;
F_41 ( V_43 ) ;
F_34 ( V_43 ) ;
V_41:
F_21 ( V_60 ) ;
return V_27 ;
}
static int F_101 ( unsigned long V_168 )
{
char V_185 [ V_186 ] , V_187 [ V_186 ] ;
int V_27 = 0 ;
memset ( V_187 , 0 , sizeof( V_187 ) ) ;
memset ( V_185 , F_102 () & 255 , sizeof( V_185 ) ) ;
F_90 ( F_67 ( V_187 ) , F_67 ( V_185 ) , V_186 ) ;
if ( memcmp ( V_185 , V_187 , V_186 ) ) {
F_94 ( V_173 L_14 , F_51 () ) ;
V_27 = - V_171 ;
}
return V_27 ;
}
int F_103 ( unsigned long V_168 )
{
int V_27 = - V_188 ;
switch ( V_168 & 0xff ) {
case 0 :
V_27 = F_92 ( V_168 ) ;
break;
case 1 :
V_27 = F_95 ( V_168 ) ;
break;
case 2 :
V_27 = F_98 ( V_168 ) ;
break;
case 3 :
V_27 = F_101 ( V_168 ) ;
break;
case 99 :
V_27 = F_17 () ;
break;
}
return V_27 ;
}
int F_104 ( void )
{
return 0 ;
}
void F_105 ( void )
{
if ( F_17 () )
F_74 () ;
}
