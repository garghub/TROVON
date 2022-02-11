static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
void * V_8 ;
int V_9 , V_10 ;
F_2 ( & V_2 -> V_11 ) ;
F_3 ( & V_2 -> V_11 ) ;
if ( ! V_2 -> V_12 ) {
V_2 -> V_12 = F_4 ( NULL , 0 , 0 , 0 , 0 , 0 ) ;
V_2 -> V_12 -> V_13 = V_3 ;
}
V_7 = V_2 -> V_12 ;
if ( ! V_7 -> V_14 ) {
F_5 ( V_15 ) ;
V_10 = F_6 ( V_3 ) ;
V_7 -> V_16 = F_7 (
V_17 * V_10 + V_2 -> V_18 ) ;
V_7 -> V_19 = F_8 (
V_20 * V_10 +
V_2 -> V_21 ) ;
while ( ! F_9 ( V_7 ) ) {
F_10 ( 1 ) ;
F_11 ( V_7 ) ;
}
F_12 ( V_7 ) ;
V_5 = V_2 -> V_12 -> V_14 ;
V_8 = V_5 -> V_22 ;
V_9 = V_7 -> V_23 ;
V_2 -> V_24 = F_13 ( V_8 , V_9 , 0 ) ;
V_2 -> V_25 = F_14 ( V_8 , V_9 , 0 ) ;
}
F_15 ( & V_2 -> V_11 ) ;
}
static int F_16 ( void )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
int V_26 , V_27 = 0 ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
V_2 = V_29 [ V_26 ] ;
if ( ! V_2 )
continue;
if ( F_17 ( & V_2 -> V_11 ) ) {
V_7 = V_2 -> V_12 ;
if ( V_7 && V_7 -> V_14 )
F_18 ( V_7 , 0 ) ;
V_2 -> V_12 = NULL ;
F_19 ( & V_2 -> V_11 ) ;
F_20 ( V_7 ) ;
} else {
V_27 ++ ;
}
}
return V_27 ;
}
static struct V_1 * F_21 ( int V_3 )
{
struct V_1 * V_2 ;
int V_26 ;
F_5 ( V_30 ) ;
V_31:
V_26 = V_3 < 0 ? F_22 () : V_3 ;
V_2 = V_29 [ V_26 ] ;
F_23 ( & V_2 -> V_11 ) ;
if ( V_3 < 0 && V_26 != F_22 () ) {
F_2 ( & V_2 -> V_11 ) ;
goto V_31;
}
if ( ! V_2 -> V_12 || ! V_2 -> V_12 -> V_14 )
F_1 ( V_2 , V_26 ) ;
return V_2 ;
}
static void F_24 ( int V_3 )
{
struct V_1 * V_2 ;
V_2 = V_29 [ V_3 ] ;
F_2 ( & V_2 -> V_11 ) ;
F_5 ( V_32 ) ;
}
static int F_25 ( int V_33 , void * * V_34 , void * * V_35 )
{
struct V_1 * V_2 ;
int V_36 ;
F_26 ( V_33 > V_20 ) ;
F_27 () ;
V_2 = F_21 ( - 1 ) ;
V_36 = F_28 () ;
* V_34 = V_2 -> V_24 + V_36 * V_37 ;
* V_35 = V_2 -> V_25 + V_36 * V_20 ;
return 0 ;
}
static void F_29 ( void * V_34 , void * V_35 )
{
F_24 ( F_22 () ) ;
F_30 () ;
}
unsigned long F_31 ( int V_3 , int V_38 , int V_33 ,
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
F_18 ( V_7 , 0 ) ;
V_27 = F_32 ( V_3 ) ;
V_41:
F_19 ( & V_2 -> V_11 ) ;
return V_27 ;
}
void F_33 ( unsigned long V_43 )
{
struct V_1 * V_2 = F_34 ( V_43 ) ;
F_3 ( & V_2 -> V_11 ) ;
V_2 -> V_21 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_42 = NULL ;
F_19 ( & V_2 -> V_11 ) ;
}
void F_35 ( unsigned long V_43 )
{
struct V_1 * V_2 = F_34 ( V_43 ) ;
F_36 ( V_2 -> V_42 ) ;
F_37 () ;
}
void F_38 ( unsigned long V_43 , void * * V_34 , void * * V_35 )
{
struct V_1 * V_2 = F_34 ( V_43 ) ;
int V_3 = F_39 ( V_43 ) ;
int V_10 ;
F_21 ( V_3 ) ;
V_10 = F_6 ( V_3 ) ;
if ( V_34 )
* V_34 = V_2 -> V_24 + V_10 * V_37 ;
if ( V_35 )
* V_35 = V_2 -> V_25 + V_10 * V_20 ;
}
void F_40 ( unsigned long V_43 )
{
int V_3 = F_39 ( V_43 ) ;
F_24 ( V_3 ) ;
}
int F_41 ( void * V_34 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 ;
struct V_6 * V_7 = NULL ;
unsigned long V_48 ;
int V_49 , V_26 ;
F_42 (bid) {
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
F_26 ( ! V_7 ) ;
V_49 = F_43 ( V_7 , F_44 ( V_34 ) ) ;
V_47 = F_45 ( F_46 ( V_34 ) , V_49 ) ;
F_47 ( V_47 ) ;
F_48 () ;
V_45 -> V_51 = V_47 -> V_52 ;
V_45 -> V_53 = V_47 -> V_54 ;
V_45 -> V_55 = V_47 -> V_55 ;
V_45 -> V_56 = V_47 -> V_57 ;
V_45 -> V_58 = V_47 -> V_59 ;
F_47 ( V_47 ) ;
return 0 ;
}
char * F_49 ( int V_27 , void * V_34 ,
char * V_60 , int V_61 )
{
struct V_62 * V_63 = ( void * ) V_34 ;
struct V_44 V_45 ;
if ( V_27 > 0 && V_63 -> V_64 == V_65 ) {
F_41 ( V_34 , & V_45 ) ;
snprintf ( V_60 , V_61 ,
L_1
L_2 , F_50 () ,
V_63 , V_45 . V_51 , V_45 . V_53 , V_45 . V_55 ,
V_45 . V_56 , V_45 . V_58 ) ;
} else {
snprintf ( V_60 , V_61 , L_3 ) ;
}
return V_60 ;
}
static int F_51 ( struct V_62 * V_63 )
{
while ( V_63 -> V_64 >= V_66 ) {
F_52 () ;
F_53 () ;
}
return V_63 -> V_64 ;
}
static int F_54 ( void * V_34 )
{
struct V_62 * V_63 = ( void * ) V_34 ;
struct V_44 V_45 ;
int V_67 = V_68 ;
while ( 1 ) {
if ( F_51 ( V_63 ) == V_69 )
return V_69 ;
if ( F_55 ( V_34 ) )
return V_65 ;
F_41 ( V_34 , & V_45 ) ;
if ( ( V_45 . V_55 & ~ V_70 ) ||
( V_45 . V_71 & V_72 ) )
break;
if ( V_67 -- == 0 )
break;
V_63 -> V_73 = 1 ;
F_47 ( V_63 ) ;
}
return V_65 ;
}
int F_56 ( void * V_34 )
{
struct V_62 * V_63 = ( void * ) V_34 ;
int V_27 ;
V_27 = V_63 -> V_64 ;
if ( V_27 == V_65 )
V_27 = F_54 ( V_34 ) ;
F_57 () ;
return V_27 ;
}
int F_58 ( void * V_34 )
{
struct V_62 * V_63 = ( void * ) V_34 ;
int V_27 ;
V_27 = F_51 ( V_63 ) ;
if ( V_27 == V_65 )
V_27 = F_54 ( V_34 ) ;
F_57 () ;
return V_27 ;
}
void F_59 ( int V_27 , void * V_34 , char * V_74 )
{
char V_60 [ V_75 ] ;
F_60 ( L_4 , V_74 ,
F_49 ( V_27 , V_34 , V_60 , sizeof( V_60 ) ) ) ;
}
void F_61 ( void * V_34 )
{
int V_27 ;
V_27 = F_58 ( V_34 ) ;
if ( V_27 )
F_59 ( V_27 , V_34 , L_5 ) ;
}
static inline int F_62 ( void * V_76 )
{
struct V_77 * V_78 = V_76 + V_79 ;
return V_78 -> V_80 ;
}
static inline void F_63 ( void * V_76 , int V_81 )
{
struct V_77 * V_78 = V_76 + V_79 ;
V_78 -> V_80 = V_81 ;
}
int F_64 ( struct V_82 * V_83 ,
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
V_89 -> V_97 = F_65 ( 2 , V_90 / 2 + 1 ) ;
V_83 -> V_89 = V_89 ;
V_83 -> V_98 = F_66 ( V_89 ) ;
V_83 -> V_90 = V_90 ;
V_83 -> V_99 = V_85 >> 1 ;
V_83 -> V_100 = V_86 ;
V_83 -> V_101 = V_87 ;
return 0 ;
}
static int F_67 ( void * V_34 , struct V_82 * V_83 ,
void * V_102 )
{
const struct V_77 V_103 = {
. V_80 = V_104 , . V_105 = 1 } ;
unsigned long V_106 ;
int V_107 , V_27 ;
struct V_77 V_108 , * V_78 = V_102 ;
F_5 ( V_109 ) ;
V_108 = * V_78 ;
* V_78 = V_103 ;
F_68 ( V_34 , V_83 -> V_98 , F_69 ( V_78 ) , 1 , V_110 ) ;
V_27 = F_70 ( V_34 ) ;
if ( V_27 ) {
V_107 = F_55 ( V_34 ) ;
switch ( V_107 ) {
case V_111 :
F_5 ( V_112 ) ;
V_27 = V_113 ;
break;
case V_114 :
F_5 ( V_115 ) ;
V_27 = V_116 ;
break;
case V_117 :
F_5 ( V_118 ) ;
V_27 = 0 ;
break;
case V_119 :
F_5 ( V_120 ) ;
V_27 = V_116 ;
break;
case V_121 :
F_5 ( V_122 ) ;
V_106 = V_83 -> V_98 + ( F_71 ( V_34 ) << 6 ) ;
F_72 ( V_34 , V_106 , F_69 ( V_102 ) , V_123 , 1 , 1 ,
V_110 ) ;
if ( F_70 ( V_34 ) == V_69 )
V_27 = V_124 ;
else
V_27 = V_113 ;
break;
case V_125 :
F_5 ( V_126 ) ;
default:
F_73 () ;
}
}
* V_78 = V_108 ;
return V_27 ;
}
static int F_74 ( void * V_34 , struct V_82 * V_83 ,
void * V_102 , int V_105 )
{
union V_127 V_128 ;
unsigned int V_95 , V_97 ;
unsigned long V_129 ;
int V_130 , V_90 ;
V_129 = F_75 ( V_34 ) ;
V_97 = F_71 ( V_34 ) ;
V_95 = F_76 ( V_34 ) ;
V_90 = V_83 -> V_90 ;
V_130 = ( V_95 != V_90 ) ;
if ( V_130 )
V_128 = F_65 ( V_90 / 2 + 1 , V_90 ) ;
else
V_128 = F_65 ( 2 , V_90 / 2 + 1 ) ;
F_77 ( V_34 , V_131 , F_78 ( V_83 -> V_98 , V_130 ) , V_132 , V_110 ) ;
if ( F_70 ( V_34 ) != V_69 )
goto V_133;
if ( ! F_75 ( V_34 ) ) {
F_5 ( V_134 ) ;
return V_135 ;
}
if ( V_97 != V_95 ) {
if ( F_67 ( V_34 , V_83 , V_102 ) ) {
F_77 ( V_34 , V_136 , F_78 ( V_83 -> V_98 , V_130 ) ,
V_132 , V_110 ) ;
if ( F_70 ( V_34 ) != V_69 )
goto V_133;
F_5 ( V_137 ) ;
return V_124 ;
}
V_129 ++ ;
}
F_79 ( V_34 , V_138 , V_83 -> V_98 , V_132 , V_128 . V_81 , V_129 ,
V_110 ) ;
if ( F_70 ( V_34 ) != V_69 )
goto V_133;
if ( F_75 ( V_34 ) != V_129 ) {
F_5 ( V_139 ) ;
F_77 ( V_34 , V_136 , F_78 ( V_83 -> V_98 , V_130 ) , V_132 ,
V_110 ) ;
if ( F_70 ( V_34 ) != V_69 )
goto V_133;
}
return V_124 ;
V_133:
F_5 ( V_140 ) ;
return V_113 ;
}
static int F_80 ( void * V_34 , struct V_82 * V_83 ,
void * V_102 , int V_105 )
{
unsigned long V_106 , * V_81 = V_102 , V_141 , V_142 ;
int V_27 ;
V_106 = V_83 -> V_98 + ( F_71 ( V_34 ) << 6 ) ;
if ( V_105 == 2 ) {
F_81 ( V_34 , V_106 , 0 , V_123 , V_105 , 1 , V_110 ) ;
if ( F_70 ( V_34 ) != V_69 )
return V_113 ;
}
F_72 ( V_34 , V_106 , F_69 ( V_102 ) , V_123 , V_105 , 1 , V_110 ) ;
if ( F_70 ( V_34 ) != V_69 )
return V_113 ;
if ( ! V_83 -> V_100 )
return V_143 ;
V_141 = F_82 ( V_83 -> V_99 , V_144 ) ;
V_142 = * V_81 ;
* V_81 = F_83 ( V_83 -> V_101 , V_83 -> V_100 ,
V_145 ) ;
F_84 ( V_34 , V_141 , F_69 ( V_102 ) , V_146 , V_110 ) ;
V_27 = F_70 ( V_34 ) ;
* V_81 = V_142 ;
if ( V_27 != V_69 )
return V_113 ;
return V_143 ;
}
static int F_85 ( void * V_34 , struct V_82 * V_83 ,
void * V_102 , int V_105 )
{
int V_107 , V_27 = 0 ;
V_107 = F_55 ( V_34 ) ;
switch ( V_107 ) {
case V_111 :
F_5 ( V_147 ) ;
V_27 = V_113 ;
break;
case V_114 :
F_5 ( V_148 ) ;
V_27 = V_116 ;
break;
case V_117 :
F_5 ( V_149 ) ;
V_27 = F_74 ( V_34 , V_83 , V_102 , V_105 ) ;
break;
case V_119 :
F_5 ( V_150 ) ;
V_27 = V_116 ;
break;
case V_121 :
F_5 ( V_151 ) ;
V_27 = F_80 ( V_34 , V_83 , V_102 , V_105 ) ;
break;
case V_125 :
F_5 ( V_152 ) ;
default:
F_73 () ;
}
return V_27 ;
}
int F_86 ( struct V_82 * V_83 , void * V_102 ,
unsigned int V_84 )
{
struct V_77 * V_78 ;
void * V_34 ;
void * V_35 ;
int V_64 , V_153 , V_27 ;
F_5 ( V_154 ) ;
F_26 ( V_84 < sizeof( int ) || V_84 > 2 * V_79 ) ;
V_153 = F_87 ( V_84 , V_79 ) ;
if ( F_25 ( V_84 , & V_34 , & V_35 ) )
return V_155 ;
memcpy ( V_35 , V_102 , V_84 ) ;
V_78 = V_35 ;
V_78 -> V_80 = V_156 ;
V_78 -> V_105 = V_153 ;
if ( V_153 == 2 ) {
V_78 -> V_157 = F_62 ( V_78 ) ;
F_63 ( V_78 , V_156 ) ;
}
do {
V_27 = V_143 ;
F_68 ( V_34 , V_83 -> V_98 , F_69 ( V_78 ) , V_153 , V_110 ) ;
V_64 = F_70 ( V_34 ) ;
if ( V_64 != V_69 )
V_27 = F_85 ( V_34 , V_83 , V_35 , V_153 ) ;
} while ( V_27 == V_124 );
F_29 ( V_34 , V_35 ) ;
if ( V_27 )
F_5 ( V_158 ) ;
return V_27 ;
}
void F_88 ( struct V_82 * V_83 , void * V_102 )
{
struct V_88 * V_89 = V_83 -> V_89 ;
struct V_77 * V_78 = V_89 -> V_94 ;
void * V_94 , * V_159 ;
int V_130 = - 1 ;
int V_105 = V_78 -> V_105 ;
if ( V_105 == 2 )
F_63 ( V_78 , V_160 ) ;
V_78 -> V_80 = V_160 ;
V_159 = V_89 -> V_94 ;
V_94 = V_159 + V_79 * V_105 ;
if ( V_94 == V_89 -> V_95 ) {
V_94 = V_89 -> V_91 ;
V_130 = 1 ;
} else if ( V_159 < V_89 -> V_93 && V_94 >= V_89 -> V_93 ) {
V_130 = 0 ;
}
if ( V_130 >= 0 )
V_89 -> V_96 [ V_130 ] = 1 ;
V_89 -> V_94 = V_94 ;
}
void * F_89 ( struct V_82 * V_83 )
{
struct V_88 * V_89 = V_83 -> V_89 ;
struct V_77 * V_78 = V_89 -> V_94 ;
int V_80 = V_78 -> V_80 ;
while ( V_80 == V_104 ) {
F_88 ( V_83 , V_78 ) ;
V_78 = V_89 -> V_94 ;
V_80 = V_78 -> V_80 ;
}
if ( V_80 == V_156 && V_78 -> V_105 == 2 &&
F_62 ( V_78 ) == V_160 )
V_80 = V_160 ;
if ( ! V_80 ) {
F_5 ( V_161 ) ;
return NULL ;
}
if ( V_78 -> V_105 == 2 )
F_63 ( V_78 , V_78 -> V_157 ) ;
F_5 ( V_162 ) ;
return V_78 ;
}
int F_90 ( unsigned long * V_163 , unsigned long V_141 )
{
void * V_34 ;
void * V_35 ;
int V_27 , V_164 ;
F_5 ( V_165 ) ;
if ( F_25 ( V_20 , & V_34 , & V_35 ) )
return V_155 ;
V_164 = V_141 >> 62 ;
F_91 ( V_34 , V_141 , F_69 ( V_35 ) , V_164 , V_110 ) ;
V_27 = F_70 ( V_34 ) ;
if ( V_27 == V_69 )
* V_163 = * ( unsigned long * ) V_35 ;
F_29 ( V_34 , V_35 ) ;
return V_27 ;
}
int F_92 ( unsigned long V_166 , unsigned long V_167 ,
unsigned int V_84 )
{
void * V_34 ;
void * V_35 ;
int V_27 ;
F_5 ( V_168 ) ;
if ( F_25 ( V_20 , & V_34 , & V_35 ) )
return V_155 ;
F_93 ( V_34 , V_167 , V_166 , F_69 ( V_35 ) ,
V_169 , V_84 , V_170 , V_110 ) ;
V_27 = F_70 ( V_34 ) ;
F_29 ( V_34 , V_35 ) ;
return V_27 ;
}
static int F_94 ( unsigned long V_171 )
{
unsigned long V_172 ;
unsigned long V_173 ;
void * V_34 ;
void * V_35 ;
unsigned long * V_76 ;
int V_27 = - V_174 ;
if ( F_25 ( V_79 , & V_34 , & V_35 ) )
return V_155 ;
V_76 = V_35 ;
V_172 = V_175 ;
V_173 = 0 ;
F_95 ( V_34 , F_66 ( & V_172 ) , F_69 ( V_35 ) , V_132 , 1 , 1 , V_110 ) ;
if ( F_70 ( V_34 ) != V_69 ) {
F_96 ( V_176 L_6 , F_50 () ) ;
goto V_41;
}
if ( * V_76 != V_175 ) {
F_96 ( V_176 L_7 , F_50 () , * V_76 ) ;
goto V_41;
}
F_72 ( V_34 , F_66 ( & V_173 ) , F_69 ( V_35 ) , V_132 , 1 , 1 , V_110 ) ;
if ( F_70 ( V_34 ) != V_69 ) {
F_96 ( V_176 L_8 , F_50 () ) ;
goto V_41;
}
if ( V_172 != V_173 || V_173 != V_175 ) {
F_96 ( V_176
L_9 ,
F_50 () , V_173 , V_175 ) ;
goto V_41;
}
V_27 = 0 ;
V_41:
F_29 ( V_34 , V_35 ) ;
return V_27 ;
}
static int F_97 ( unsigned long V_171 )
{
struct V_82 V_83 ;
void * V_76 , * V_89 ;
unsigned long * V_177 ;
int V_178 , V_27 = - V_174 ;
char V_179 [ V_79 ] , * V_106 ;
V_76 = F_98 ( 4096 , 0 ) ;
if ( V_76 == NULL )
return - V_180 ;
V_89 = F_99 ( V_76 , 1024 ) ;
memset ( V_179 , 0xee , sizeof( V_179 ) ) ;
V_177 = V_89 ;
F_64 ( & V_83 , V_89 , 8 * V_79 , 0 , 0 , 0 ) ;
for ( V_178 = 0 ; V_178 < 6 ; V_178 ++ ) {
V_179 [ 8 ] = V_178 ;
do {
V_27 = F_86 ( & V_83 , V_179 , sizeof( V_179 ) ) ;
} while ( V_27 == V_116 );
if ( V_27 )
break;
}
if ( V_27 != V_135 || V_178 != 4 ) {
F_96 ( V_176 L_10 ,
F_50 () , V_27 , V_178 ) ;
goto V_41;
}
for ( V_178 = 0 ; V_178 < 6 ; V_178 ++ ) {
V_106 = F_89 ( & V_83 ) ;
if ( ! V_106 || V_106 [ 8 ] != V_178 )
break;
F_88 ( & V_83 , V_106 ) ;
}
if ( V_178 != 4 ) {
F_96 ( V_176 L_11 ,
F_50 () , V_178 , V_106 , V_106 ? V_106 [ 8 ] : - 1 ) ;
goto V_41;
}
V_27 = 0 ;
V_41:
F_20 ( V_76 ) ;
return V_27 ;
}
static int F_100 ( unsigned long V_171 )
{
static F_101 ( V_40 ) ;
unsigned long V_43 ;
int V_3 = 0 ;
int V_181 = 4 ;
int V_27 = 0 ;
unsigned long * V_60 ;
void * V_182 , * V_34 ;
struct V_62 * V_63 ;
int V_178 , V_183 , V_64 , V_84 ;
V_84 = V_181 * 4 * 8 ;
V_60 = F_98 ( V_84 , V_184 ) ;
if ( ! V_60 )
return - V_180 ;
V_27 = - V_185 ;
V_43 = F_31 ( V_3 , V_181 , 0 , & V_40 ) ;
if ( ! V_43 )
goto V_41;
F_38 ( V_43 , & V_182 , NULL ) ;
memset ( V_60 , 0xee , V_84 ) ;
for ( V_178 = 0 ; V_178 < V_181 ; V_178 ++ )
F_81 ( V_182 + V_178 * V_37 , F_66 ( & V_60 [ V_178 * 4 ] ) , 0 ,
V_132 , 4 , 1 , V_186 ) ;
V_27 = 0 ;
V_183 = V_181 ;
do {
F_35 ( V_43 ) ;
for ( V_178 = 0 ; V_178 < V_181 ; V_178 ++ ) {
V_34 = V_182 + V_178 * V_37 ;
V_64 = F_102 ( V_34 ) ;
if ( V_64 != V_66 && V_64 != V_187 )
break;
}
if ( V_178 == V_181 )
continue;
if ( V_64 != V_69 ) {
F_96 ( V_176 L_12 , F_50 () , V_178 ) ;
V_27 = - V_188 ;
} else if ( V_60 [ 4 * V_178 ] || V_60 [ 4 * V_178 + 1 ] || V_60 [ 4 * V_178 + 2 ] ||
V_60 [ 4 * V_178 + 3 ] ) {
F_96 ( V_176 L_13 ,
F_50 () , V_178 , V_60 [ 4 * V_178 ] , V_60 [ 4 * V_178 + 1 ] , V_60 [ 4 * V_178 + 2 ] , V_60 [ 4 * V_178 + 3 ] ) ;
V_27 = - V_174 ;
}
V_183 -- ;
V_63 = V_34 ;
V_63 -> V_64 = V_187 ;
} while ( V_183 );
F_26 ( V_40 . V_41 ) ;
F_40 ( V_43 ) ;
F_33 ( V_43 ) ;
V_41:
F_20 ( V_60 ) ;
return V_27 ;
}
static int F_103 ( unsigned long V_171 )
{
char V_189 [ V_190 ] , V_191 [ V_190 ] ;
int V_27 = 0 ;
memset ( V_191 , 0 , sizeof( V_191 ) ) ;
memset ( V_189 , F_104 () & 255 , sizeof( V_189 ) ) ;
F_92 ( F_66 ( V_191 ) , F_66 ( V_189 ) , V_190 ) ;
if ( memcmp ( V_189 , V_191 , V_190 ) ) {
F_96 ( V_176 L_14 , F_50 () ) ;
V_27 = - V_174 ;
}
return V_27 ;
}
int F_105 ( unsigned long V_171 )
{
int V_27 = - V_192 ;
switch ( V_171 & 0xff ) {
case 0 :
V_27 = F_94 ( V_171 ) ;
break;
case 1 :
V_27 = F_97 ( V_171 ) ;
break;
case 2 :
V_27 = F_100 ( V_171 ) ;
break;
case 3 :
V_27 = F_103 ( V_171 ) ;
break;
case 99 :
V_27 = F_16 () ;
break;
}
return V_27 ;
}
int F_106 ( void )
{
return 0 ;
}
void F_107 ( void )
{
if ( F_16 () )
F_73 () ;
}
