int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
F_3 ( V_6 , V_5 ) ;
V_5 -> V_7 = V_6 -> V_8 -> V_9 << ( V_10 - 9 ) ;
return 0 ;
}
int F_4 ( struct V_3 * V_3 , struct V_11 * V_12 )
{
V_12 -> V_13 = V_3 -> V_14 -> V_15 ;
V_12 -> V_16 = V_17 ;
V_12 -> V_18 = V_19 ;
return 0 ;
}
int F_5 ( const struct V_3 * V_3 )
{
return 1 ;
}
struct V_3 * F_6 ( struct V_6 * V_20 , struct V_3 * V_3 , unsigned int V_21 )
{
if ( V_3 -> V_22 . V_23 > V_19 )
return F_7 ( - V_24 ) ;
if ( ! V_3 -> V_14 -> V_25 )
F_8 ( V_3 , & V_26 ) ;
F_9 ( V_3 , NULL ) ;
return NULL ;
}
int F_10 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
V_27 -> V_28 = F_11 ( V_27 -> V_29 . V_3 ) ;
return V_27 -> V_28 ? 0 : - V_30 ;
}
int F_12 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
F_13 ( V_27 -> V_28 ) ;
return 0 ;
}
static struct V_3 * F_14 ( struct V_3 * V_31 ,
struct V_32 * V_33 ,
int V_34 )
{
unsigned * V_35 = & V_31 -> F_2 -> V_36 , V_37 ;
struct V_3 * V_38 ;
struct V_32 * V_39 ;
bool V_40 ;
int V_41 ;
V_42:
V_41 = V_34 ;
V_40 = false ;
V_37 = F_15 ( V_35 ) & ~ 1 ;
V_38 = NULL ;
F_16 () ;
for ( V_39 = V_33 -> V_43 ; V_39 != & V_31 -> V_44 ; V_39 = V_39 -> V_43 ) {
struct V_3 * V_45 = F_17 ( V_39 , struct V_3 , V_46 ) ;
if ( ! F_18 ( V_45 ) ) {
V_40 = true ;
} else if ( ! -- V_41 ) {
V_38 = V_45 ;
break;
}
}
F_19 () ;
if ( V_40 ) {
F_20 () ;
if ( F_21 ( * V_35 != V_37 ) )
goto V_42;
}
return V_38 ;
}
static void F_22 ( struct V_3 * V_47 , struct V_32 * V_48 )
{
struct V_3 * V_31 = V_47 -> V_49 ;
unsigned V_37 , * V_35 = & V_31 -> F_2 -> V_36 ;
F_23 ( & V_31 -> V_50 ) ;
for (; ; ) {
V_37 = * V_35 ;
if ( ! ( V_37 & 1 ) && F_24 ( V_35 , V_37 , V_37 + 1 ) == V_37 )
break;
F_25 () ;
}
F_26 ( V_47 -> V_46 . V_51 , V_47 -> V_46 . V_43 ) ;
if ( V_48 )
F_27 ( & V_47 -> V_46 , V_48 ) ;
else
F_28 ( & V_47 -> V_46 , & V_31 -> V_44 ) ;
F_29 ( V_35 , V_37 + 2 ) ;
F_30 ( & V_31 -> V_50 ) ;
}
T_1 F_31 ( struct V_27 * V_27 , T_1 V_52 , int V_53 )
{
struct V_3 * V_3 = V_27 -> V_29 . V_3 ;
switch ( V_53 ) {
case 1 :
V_52 += V_27 -> V_54 ;
case 0 :
if ( V_52 >= 0 )
break;
default:
return - V_55 ;
}
if ( V_52 != V_27 -> V_54 ) {
V_27 -> V_54 = V_52 ;
if ( V_27 -> V_54 >= 2 ) {
struct V_3 * V_47 = V_27 -> V_28 ;
struct V_3 * V_56 ;
T_1 V_37 = V_27 -> V_54 - 2 ;
F_32 ( V_3 -> F_2 ) ;
V_56 = F_14 ( V_3 , & V_3 -> V_44 , V_37 ) ;
F_22 ( V_47 , V_56 ? & V_56 -> V_46 : NULL ) ;
F_33 ( V_3 -> F_2 ) ;
}
}
return V_52 ;
}
static inline unsigned char F_34 ( struct V_6 * V_6 )
{
return ( V_6 -> V_57 >> 12 ) & 15 ;
}
int F_35 ( struct V_27 * V_27 , struct V_58 * V_59 )
{
struct V_3 * V_3 = V_27 -> V_29 . V_3 ;
struct V_3 * V_47 = V_27 -> V_28 ;
struct V_32 * V_39 = & V_47 -> V_46 ;
struct V_3 * V_43 ;
bool V_60 = false ;
if ( ! F_36 ( V_27 , V_59 ) )
return 0 ;
if ( V_59 -> V_61 == 2 )
V_39 = & V_3 -> V_44 ;
while ( ( V_43 = F_14 ( V_3 , V_39 , 1 ) ) != NULL ) {
if ( ! F_37 ( V_59 , V_43 -> V_22 . V_62 , V_43 -> V_22 . V_23 ,
F_2 ( V_43 ) -> V_63 , F_34 ( F_2 ( V_43 ) ) ) )
break;
V_60 = true ;
V_39 = & V_43 -> V_46 ;
V_59 -> V_61 ++ ;
}
if ( V_60 )
F_22 ( V_47 , V_39 ) ;
return 0 ;
}
T_2 F_38 ( struct V_27 * V_64 , char T_3 * V_12 , T_4 V_65 , T_1 * V_66 )
{
return - V_67 ;
}
struct V_3 * F_39 ( struct V_68 * V_69 , char * V_62 ,
const struct V_70 * V_71 , const struct V_72 * * V_73 ,
const struct V_74 * V_75 , unsigned long V_76 )
{
struct V_77 * V_78 ;
struct V_3 * V_3 ;
struct V_6 * V_79 ;
struct V_80 V_22 = F_40 ( V_62 , strlen ( V_62 ) ) ;
V_78 = F_41 ( V_69 , NULL , V_81 , V_82 , NULL ) ;
if ( F_42 ( V_78 ) )
return F_43 ( V_78 ) ;
V_78 -> V_83 = V_84 ;
V_78 -> V_85 = V_17 ;
V_78 -> V_86 = V_10 ;
V_78 -> V_15 = V_76 ;
V_78 -> V_87 = V_71 ? V_71 : & V_88 ;
V_78 -> V_89 = V_73 ;
V_78 -> V_90 = 1 ;
V_79 = F_44 ( V_78 ) ;
if ( ! V_79 )
goto V_91;
V_79 -> V_63 = 1 ;
V_79 -> V_57 = V_92 | V_93 | V_94 ;
V_79 -> V_95 = V_79 -> V_96 = V_79 -> V_97 = F_45 ( V_79 ) ;
V_3 = F_46 ( V_78 , & V_22 ) ;
if ( ! V_3 ) {
F_47 ( V_79 ) ;
goto V_91;
}
F_48 ( V_3 , V_79 ) ;
V_78 -> V_98 = V_3 ;
V_78 -> V_25 = V_75 ;
V_78 -> V_99 |= V_100 ;
return F_49 ( V_78 -> V_98 ) ;
V_91:
F_50 ( V_78 ) ;
return F_7 ( - V_30 ) ;
}
int F_51 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
if ( V_6 -> V_101 )
V_27 -> V_28 = V_6 -> V_101 ;
return 0 ;
}
int F_52 ( struct V_3 * V_102 , struct V_6 * V_20 , struct V_3 * V_3 )
{
struct V_6 * V_6 = F_2 ( V_102 ) ;
V_6 -> V_97 = V_20 -> V_97 = V_20 -> V_96 = F_45 ( V_6 ) ;
F_53 ( V_6 ) ;
F_54 ( V_6 ) ;
F_49 ( V_3 ) ;
F_48 ( V_3 , V_6 ) ;
return 0 ;
}
int F_55 ( struct V_3 * V_3 )
{
struct V_3 * V_103 ;
int V_104 = 0 ;
F_23 ( & V_3 -> V_50 ) ;
F_56 (child, &dentry->d_subdirs, d_child) {
F_57 ( & V_103 -> V_50 , V_105 ) ;
if ( F_18 ( V_103 ) ) {
F_30 ( & V_103 -> V_50 ) ;
goto V_106;
}
F_30 ( & V_103 -> V_50 ) ;
}
V_104 = 1 ;
V_106:
F_30 ( & V_3 -> V_50 ) ;
return V_104 ;
}
int F_58 ( struct V_6 * V_20 , struct V_3 * V_3 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
V_6 -> V_97 = V_20 -> V_97 = V_20 -> V_96 = F_45 ( V_6 ) ;
F_59 ( V_6 ) ;
F_13 ( V_3 ) ;
return 0 ;
}
int F_60 ( struct V_6 * V_20 , struct V_3 * V_3 )
{
if ( ! F_55 ( V_3 ) )
return - V_107 ;
F_59 ( F_2 ( V_3 ) ) ;
F_58 ( V_20 , V_3 ) ;
F_59 ( V_20 ) ;
return 0 ;
}
int F_61 ( struct V_6 * V_108 , struct V_3 * V_102 ,
struct V_6 * V_109 , struct V_3 * V_110 ,
unsigned int V_21 )
{
struct V_6 * V_6 = F_2 ( V_102 ) ;
int V_111 = F_62 ( V_102 ) ;
if ( V_21 & ~ V_112 )
return - V_55 ;
if ( ! F_55 ( V_110 ) )
return - V_107 ;
if ( F_63 ( V_110 ) ) {
F_58 ( V_109 , V_110 ) ;
if ( V_111 ) {
F_59 ( F_2 ( V_110 ) ) ;
F_59 ( V_108 ) ;
}
} else if ( V_111 ) {
F_59 ( V_108 ) ;
F_53 ( V_109 ) ;
}
V_108 -> V_97 = V_108 -> V_96 = V_109 -> V_97 =
V_109 -> V_96 = V_6 -> V_97 = F_45 ( V_108 ) ;
return 0 ;
}
int F_64 ( struct V_3 * V_3 , struct V_113 * V_113 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
int error ;
error = F_65 ( V_3 , V_113 ) ;
if ( error )
return error ;
if ( V_113 -> V_114 & V_115 )
F_66 ( V_6 , V_113 -> V_116 ) ;
F_67 ( V_6 , V_113 ) ;
F_68 ( V_6 ) ;
return 0 ;
}
int F_69 ( struct V_27 * V_27 , struct V_117 * V_117 )
{
F_70 ( V_117 ) ;
F_71 ( V_117 ) ;
F_72 ( V_117 ) ;
F_73 ( V_117 ) ;
return 0 ;
}
int F_74 ( struct V_27 * V_27 , struct V_118 * V_119 ,
T_1 V_61 , unsigned V_23 , unsigned V_21 ,
struct V_117 * * V_120 , void * * V_121 )
{
struct V_117 * V_117 ;
T_5 V_122 ;
V_122 = V_61 >> V_10 ;
V_117 = F_75 ( V_119 , V_122 , V_21 ) ;
if ( ! V_117 )
return - V_30 ;
* V_120 = V_117 ;
if ( ! F_76 ( V_117 ) && ( V_23 != V_17 ) ) {
unsigned V_33 = V_61 & ( V_17 - 1 ) ;
F_77 ( V_117 , 0 , V_33 , V_33 + V_23 , V_17 ) ;
}
return 0 ;
}
int F_78 ( struct V_27 * V_27 , struct V_118 * V_119 ,
T_1 V_61 , unsigned V_23 , unsigned V_123 ,
struct V_117 * V_117 , void * V_121 )
{
struct V_6 * V_6 = V_117 -> V_119 -> V_124 ;
T_1 V_125 = V_61 + V_123 ;
if ( V_123 < V_23 ) {
unsigned V_33 = V_61 & ( V_17 - 1 ) ;
F_79 ( V_117 , V_33 + V_123 , V_23 - V_123 ) ;
}
if ( ! F_76 ( V_117 ) )
F_72 ( V_117 ) ;
if ( V_125 > V_6 -> V_126 )
F_80 ( V_6 , V_125 ) ;
F_81 ( V_117 ) ;
F_73 ( V_117 ) ;
F_82 ( V_117 ) ;
return V_123 ;
}
int F_83 ( struct V_77 * V_78 , unsigned long V_76 ,
struct V_127 * V_128 )
{
struct V_6 * V_6 ;
struct V_3 * V_79 ;
struct V_3 * V_3 ;
int V_41 ;
V_78 -> V_85 = V_17 ;
V_78 -> V_86 = V_10 ;
V_78 -> V_15 = V_76 ;
V_78 -> V_87 = & V_88 ;
V_78 -> V_90 = 1 ;
V_6 = F_44 ( V_78 ) ;
if ( ! V_6 )
return - V_30 ;
V_6 -> V_63 = 1 ;
V_6 -> V_57 = V_92 | 0755 ;
V_6 -> V_95 = V_6 -> V_96 = V_6 -> V_97 = F_45 ( V_6 ) ;
V_6 -> V_129 = & V_130 ;
V_6 -> V_131 = & V_132 ;
F_84 ( V_6 , 2 ) ;
V_79 = F_85 ( V_6 ) ;
if ( ! V_79 )
return - V_30 ;
for ( V_41 = 0 ; ! V_128 -> V_62 || V_128 -> V_62 [ 0 ] ; V_41 ++ , V_128 ++ ) {
if ( ! V_128 -> V_62 )
continue;
if ( F_21 ( V_41 == 1 ) )
F_86 ( V_133 L_1
L_2 , V_134 ,
V_78 -> V_135 -> V_62 ) ;
V_3 = F_87 ( V_79 , V_128 -> V_62 ) ;
if ( ! V_3 )
goto V_106;
V_6 = F_44 ( V_78 ) ;
if ( ! V_6 ) {
F_13 ( V_3 ) ;
goto V_106;
}
V_6 -> V_57 = V_136 | V_128 -> V_137 ;
V_6 -> V_95 = V_6 -> V_96 = V_6 -> V_97 = F_45 ( V_6 ) ;
V_6 -> V_131 = V_128 -> V_71 ;
V_6 -> V_63 = V_41 ;
F_9 ( V_3 , V_6 ) ;
}
V_78 -> V_98 = V_79 ;
return 0 ;
V_106:
F_88 ( V_79 ) ;
F_89 ( V_79 ) ;
F_13 ( V_79 ) ;
return - V_30 ;
}
int F_90 ( struct V_68 * type , struct V_1 * * V_138 , int * V_34 )
{
struct V_1 * V_2 = NULL ;
F_23 ( & V_139 ) ;
if ( F_21 ( ! * V_138 ) ) {
F_30 ( & V_139 ) ;
V_2 = F_91 ( type , V_140 , type -> V_62 , NULL ) ;
if ( F_42 ( V_2 ) )
return F_92 ( V_2 ) ;
F_23 ( & V_139 ) ;
if ( ! * V_138 )
* V_138 = V_2 ;
}
F_93 ( * V_138 ) ;
++ * V_34 ;
F_30 ( & V_139 ) ;
F_94 ( V_2 ) ;
return 0 ;
}
void F_95 ( struct V_1 * * V_138 , int * V_34 )
{
struct V_1 * V_2 ;
F_23 ( & V_139 ) ;
V_2 = * V_138 ;
if ( ! -- * V_34 )
* V_138 = NULL ;
F_30 ( & V_139 ) ;
F_94 ( V_2 ) ;
}
T_2 F_96 ( void T_3 * V_56 , T_4 V_34 , T_1 * V_66 ,
const void * V_33 , T_4 V_141 )
{
T_1 V_61 = * V_66 ;
T_4 V_104 ;
if ( V_61 < 0 )
return - V_55 ;
if ( V_61 >= V_141 || ! V_34 )
return 0 ;
if ( V_34 > V_141 - V_61 )
V_34 = V_141 - V_61 ;
V_104 = F_97 ( V_56 , V_33 + V_61 , V_34 ) ;
if ( V_104 == V_34 )
return - V_142 ;
V_34 -= V_104 ;
* V_66 = V_61 + V_34 ;
return V_34 ;
}
T_2 F_98 ( void * V_56 , T_4 V_141 , T_1 * V_66 ,
const void T_3 * V_33 , T_4 V_34 )
{
T_1 V_61 = * V_66 ;
T_4 V_38 ;
if ( V_61 < 0 )
return - V_55 ;
if ( V_61 >= V_141 || ! V_34 )
return 0 ;
if ( V_34 > V_141 - V_61 )
V_34 = V_141 - V_61 ;
V_38 = F_99 ( V_56 + V_61 , V_33 , V_34 ) ;
if ( V_38 == V_34 )
return - V_142 ;
V_34 -= V_38 ;
* V_66 = V_61 + V_34 ;
return V_34 ;
}
T_2 F_100 ( void * V_56 , T_4 V_34 , T_1 * V_66 ,
const void * V_33 , T_4 V_141 )
{
T_1 V_61 = * V_66 ;
if ( V_61 < 0 )
return - V_55 ;
if ( V_61 >= V_141 )
return 0 ;
if ( V_34 > V_141 - V_61 )
V_34 = V_141 - V_61 ;
memcpy ( V_56 , V_33 + V_61 , V_34 ) ;
* V_66 = V_61 + V_34 ;
return V_34 ;
}
void F_101 ( struct V_27 * V_27 , T_4 V_37 )
{
struct V_143 * V_144 = V_27 -> V_28 ;
F_102 ( V_37 > V_145 ) ;
F_103 () ;
V_144 -> V_146 = V_37 ;
}
char * F_104 ( struct V_27 * V_27 , const char T_3 * V_12 , T_4 V_146 )
{
struct V_143 * V_144 ;
static F_105 ( V_147 ) ;
if ( V_146 > V_145 - 1 )
return F_7 ( - V_148 ) ;
V_144 = (struct V_143 * ) F_106 ( V_149 ) ;
if ( ! V_144 )
return F_7 ( - V_30 ) ;
F_23 ( & V_147 ) ;
if ( V_27 -> V_28 ) {
F_30 ( & V_147 ) ;
F_107 ( ( unsigned long ) V_144 ) ;
return F_7 ( - V_150 ) ;
}
V_27 -> V_28 = V_144 ;
F_30 ( & V_147 ) ;
if ( F_99 ( V_144 -> V_151 , V_12 , V_146 ) )
return F_7 ( - V_142 ) ;
return V_144 -> V_151 ;
}
T_2 F_108 ( struct V_27 * V_27 , char T_3 * V_12 , T_4 V_146 , T_1 * V_61 )
{
struct V_143 * V_144 = V_27 -> V_28 ;
if ( ! V_144 )
return 0 ;
return F_96 ( V_12 , V_146 , V_61 , V_144 -> V_151 , V_144 -> V_146 ) ;
}
int F_109 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
F_107 ( ( unsigned long ) V_27 -> V_28 ) ;
return 0 ;
}
int F_110 ( struct V_6 * V_6 , struct V_27 * V_27 ,
int (* F_111)( void * , T_6 * ) , int (* F_112)( void * , T_6 ) ,
const char * V_152 )
{
struct V_153 * V_154 ;
V_154 = F_113 ( sizeof( * V_154 ) , V_149 ) ;
if ( ! V_154 )
return - V_30 ;
V_154 -> F_111 = F_111 ;
V_154 -> F_112 = F_112 ;
V_154 -> V_151 = V_6 -> V_101 ;
V_154 -> V_152 = V_152 ;
F_114 ( & V_154 -> V_155 ) ;
V_27 -> V_28 = V_154 ;
return F_115 ( V_6 , V_27 ) ;
}
int F_116 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
F_117 ( V_27 -> V_28 ) ;
return 0 ;
}
T_2 F_118 ( struct V_27 * V_27 , char T_3 * V_12 ,
T_4 V_23 , T_1 * V_66 )
{
struct V_153 * V_154 ;
T_4 V_146 ;
T_2 V_104 ;
V_154 = V_27 -> V_28 ;
if ( ! V_154 -> F_111 )
return - V_156 ;
V_104 = F_119 ( & V_154 -> V_155 ) ;
if ( V_104 )
return V_104 ;
if ( * V_66 ) {
V_146 = strlen ( V_154 -> V_157 ) ;
} else {
T_6 V_158 ;
V_104 = V_154 -> F_111 ( V_154 -> V_151 , & V_158 ) ;
if ( V_104 )
goto V_106;
V_146 = F_120 ( V_154 -> V_157 , sizeof( V_154 -> V_157 ) ,
V_154 -> V_152 , ( unsigned long long ) V_158 ) ;
}
V_104 = F_96 ( V_12 , V_23 , V_66 , V_154 -> V_157 , V_146 ) ;
V_106:
F_121 ( & V_154 -> V_155 ) ;
return V_104 ;
}
T_2 F_122 ( struct V_27 * V_27 , const char T_3 * V_12 ,
T_4 V_23 , T_1 * V_66 )
{
struct V_153 * V_154 ;
T_6 V_158 ;
T_4 V_146 ;
T_2 V_104 ;
V_154 = V_27 -> V_28 ;
if ( ! V_154 -> F_112 )
return - V_156 ;
V_104 = F_119 ( & V_154 -> V_155 ) ;
if ( V_104 )
return V_104 ;
V_104 = - V_142 ;
V_146 = F_123 ( sizeof( V_154 -> V_159 ) - 1 , V_23 ) ;
if ( F_99 ( V_154 -> V_159 , V_12 , V_146 ) )
goto V_106;
V_154 -> V_159 [ V_146 ] = '\0' ;
V_158 = F_124 ( V_154 -> V_159 , NULL , 0 ) ;
V_104 = V_154 -> F_112 ( V_154 -> V_151 , V_158 ) ;
if ( V_104 == 0 )
V_104 = V_23 ;
V_106:
F_121 ( & V_154 -> V_155 ) ;
return V_104 ;
}
int F_125 ( struct V_27 * V_27 , T_1 V_160 , T_1 V_161 ,
int V_162 )
{
struct V_6 * V_6 = V_27 -> V_163 -> V_124 ;
int V_164 ;
int V_104 ;
V_164 = F_126 ( V_6 -> V_8 , V_160 , V_161 ) ;
if ( V_164 )
return V_164 ;
F_127 ( V_6 ) ;
V_104 = F_128 ( V_6 -> V_8 ) ;
if ( ! ( V_6 -> V_165 & V_166 ) )
goto V_106;
if ( V_162 && ! ( V_6 -> V_165 & V_167 ) )
goto V_106;
V_164 = F_129 ( V_6 , 1 ) ;
if ( V_104 == 0 )
V_104 = V_164 ;
V_106:
F_130 ( V_6 ) ;
return V_104 ;
}
int F_131 ( struct V_27 * V_27 , T_1 V_160 , T_1 V_161 ,
int V_162 )
{
struct V_6 * V_6 = V_27 -> V_163 -> V_124 ;
int V_164 ;
V_164 = F_125 ( V_27 , V_160 , V_161 , V_162 ) ;
if ( V_164 )
return V_164 ;
return F_132 ( V_6 -> V_168 -> V_169 , V_149 , NULL ) ;
}
int F_133 ( unsigned V_170 , T_6 V_171 )
{
T_6 V_172 = V_171 - 1 ;
T_6 V_173 =
V_172 >> ( V_10 - V_170 ) ;
if ( F_21 ( V_171 == 0 ) )
return 0 ;
if ( ( V_170 < 9 ) || ( V_170 > V_10 ) )
return - V_55 ;
if ( ( V_172 > ( V_174 ) ( ~ 0ULL ) >> ( V_170 - 9 ) ) ||
( V_173 > ( T_5 ) ( ~ 0ULL ) ) ) {
return - V_148 ;
}
return 0 ;
}
int F_134 ( struct V_27 * V_27 , T_1 V_160 , T_1 V_161 , int V_162 )
{
return 0 ;
}
void F_135 ( void * V_39 )
{
F_117 ( V_39 ) ;
}
static int F_136 ( struct V_117 * V_117 )
{
return 0 ;
}
struct V_6 * F_137 ( struct V_77 * V_78 )
{
static const struct V_175 V_176 = {
. F_81 = F_136 ,
} ;
struct V_6 * V_6 = F_138 ( V_78 ) ;
if ( ! V_6 )
return F_7 ( - V_30 ) ;
V_6 -> V_63 = F_139 () ;
V_6 -> V_8 -> V_177 = & V_176 ;
V_6 -> V_165 = V_178 ;
V_6 -> V_57 = V_93 | V_94 ;
V_6 -> V_179 = F_140 () ;
V_6 -> V_180 = F_141 () ;
V_6 -> V_181 |= V_182 ;
V_6 -> V_95 = V_6 -> V_96 = V_6 -> V_97 = F_45 ( V_6 ) ;
return V_6 ;
}
int
F_142 ( struct V_27 * V_64 , long V_183 , struct V_184 * * V_185 ,
void * * V_186 )
{
return - V_55 ;
}
const char * F_143 ( struct V_3 * V_3 , struct V_6 * V_6 ,
struct V_187 * V_188 )
{
return V_6 -> V_189 ;
}
static struct V_3 * F_144 ( struct V_6 * V_20 , struct V_3 * V_3 , unsigned int V_21 )
{
return F_7 ( - V_190 ) ;
}
static int F_145 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
F_3 ( V_6 , V_5 ) ;
return 0 ;
}
static int F_146 ( struct V_3 * V_3 , struct V_113 * V_154 )
{
return - V_191 ;
}
static T_2 F_147 ( struct V_3 * V_3 , char * V_192 , T_4 V_146 )
{
return - V_193 ;
}
static T_1 F_148 ( struct V_27 * V_27 , T_1 V_52 , int V_53 )
{
return F_149 ( V_27 , V_52 , V_53 , 2 , 2 ) ;
}
static int F_150 ( struct V_27 * V_27 , struct V_58 * V_59 )
{
F_36 ( V_27 , V_59 ) ;
return 0 ;
}
void F_151 ( struct V_6 * V_6 )
{
F_84 ( V_6 , 2 ) ;
V_6 -> V_57 = V_92 | V_194 | V_195 ;
V_6 -> V_179 = V_196 ;
V_6 -> V_180 = V_197 ;
V_6 -> V_198 = 0 ;
V_6 -> V_126 = 0 ;
V_6 -> V_199 = V_10 ;
V_6 -> V_200 = 0 ;
V_6 -> V_129 = & V_201 ;
V_6 -> V_202 &= ~ V_203 ;
V_6 -> V_131 = & V_204 ;
}
bool F_152 ( struct V_6 * V_6 )
{
return ( V_6 -> V_131 == & V_204 ) &&
( V_6 -> V_129 == & V_201 ) ;
}
