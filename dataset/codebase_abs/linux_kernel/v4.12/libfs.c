int F_1 ( const struct V_1 * V_1 , struct V_2 * V_3 ,
T_1 V_4 , unsigned int V_5 )
{
struct V_6 * V_6 = F_2 ( V_1 -> V_7 ) ;
F_3 ( V_6 , V_3 ) ;
V_3 -> V_8 = V_6 -> V_9 -> V_10 << ( V_11 - 9 ) ;
return 0 ;
}
int F_4 ( struct V_7 * V_7 , struct V_12 * V_13 )
{
V_13 -> V_14 = V_7 -> V_15 -> V_16 ;
V_13 -> V_17 = V_18 ;
V_13 -> V_19 = V_20 ;
return 0 ;
}
int F_5 ( const struct V_7 * V_7 )
{
return 1 ;
}
struct V_7 * F_6 ( struct V_6 * V_21 , struct V_7 * V_7 , unsigned int V_22 )
{
if ( V_7 -> V_23 . V_24 > V_20 )
return F_7 ( - V_25 ) ;
if ( ! V_7 -> V_15 -> V_26 )
F_8 ( V_7 , & V_27 ) ;
F_9 ( V_7 , NULL ) ;
return NULL ;
}
int F_10 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
V_28 -> V_29 = F_11 ( V_28 -> V_30 . V_7 ) ;
return V_28 -> V_29 ? 0 : - V_31 ;
}
int F_12 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
F_13 ( V_28 -> V_29 ) ;
return 0 ;
}
static struct V_7 * F_14 ( struct V_7 * V_32 ,
struct V_33 * V_34 ,
int V_35 )
{
unsigned * V_36 = & V_32 -> F_2 -> V_37 , V_38 ;
struct V_7 * V_39 ;
struct V_33 * V_40 ;
bool V_41 ;
int V_42 ;
V_43:
V_42 = V_35 ;
V_41 = false ;
V_38 = F_15 ( V_36 ) & ~ 1 ;
V_39 = NULL ;
F_16 () ;
for ( V_40 = V_34 -> V_44 ; V_40 != & V_32 -> V_45 ; V_40 = V_40 -> V_44 ) {
struct V_7 * V_46 = F_17 ( V_40 , struct V_7 , V_47 ) ;
if ( ! F_18 ( V_46 ) ) {
V_41 = true ;
} else if ( ! -- V_42 ) {
V_39 = V_46 ;
break;
}
}
F_19 () ;
if ( V_41 ) {
F_20 () ;
if ( F_21 ( * V_36 != V_38 ) )
goto V_43;
}
return V_39 ;
}
static void F_22 ( struct V_7 * V_48 , struct V_33 * V_49 )
{
struct V_7 * V_32 = V_48 -> V_50 ;
unsigned V_38 , * V_36 = & V_32 -> F_2 -> V_37 ;
F_23 ( & V_32 -> V_51 ) ;
for (; ; ) {
V_38 = * V_36 ;
if ( ! ( V_38 & 1 ) && F_24 ( V_36 , V_38 , V_38 + 1 ) == V_38 )
break;
F_25 () ;
}
F_26 ( V_48 -> V_47 . V_52 , V_48 -> V_47 . V_44 ) ;
if ( V_49 )
F_27 ( & V_48 -> V_47 , V_49 ) ;
else
F_28 ( & V_48 -> V_47 , & V_32 -> V_45 ) ;
F_29 ( V_36 , V_38 + 2 ) ;
F_30 ( & V_32 -> V_51 ) ;
}
T_2 F_31 ( struct V_28 * V_28 , T_2 V_53 , int V_54 )
{
struct V_7 * V_7 = V_28 -> V_30 . V_7 ;
switch ( V_54 ) {
case 1 :
V_53 += V_28 -> V_55 ;
case 0 :
if ( V_53 >= 0 )
break;
default:
return - V_56 ;
}
if ( V_53 != V_28 -> V_55 ) {
V_28 -> V_55 = V_53 ;
if ( V_28 -> V_55 >= 2 ) {
struct V_7 * V_48 = V_28 -> V_29 ;
struct V_7 * V_57 ;
T_2 V_38 = V_28 -> V_55 - 2 ;
F_32 ( V_7 -> F_2 ) ;
V_57 = F_14 ( V_7 , & V_7 -> V_45 , V_38 ) ;
F_22 ( V_48 , V_57 ? & V_57 -> V_47 : NULL ) ;
F_33 ( V_7 -> F_2 ) ;
}
}
return V_53 ;
}
static inline unsigned char F_34 ( struct V_6 * V_6 )
{
return ( V_6 -> V_58 >> 12 ) & 15 ;
}
int F_35 ( struct V_28 * V_28 , struct V_59 * V_60 )
{
struct V_7 * V_7 = V_28 -> V_30 . V_7 ;
struct V_7 * V_48 = V_28 -> V_29 ;
struct V_33 * V_40 = & V_48 -> V_47 ;
struct V_7 * V_44 ;
bool V_61 = false ;
if ( ! F_36 ( V_28 , V_60 ) )
return 0 ;
if ( V_60 -> V_62 == 2 )
V_40 = & V_7 -> V_45 ;
while ( ( V_44 = F_14 ( V_7 , V_40 , 1 ) ) != NULL ) {
if ( ! F_37 ( V_60 , V_44 -> V_23 . V_63 , V_44 -> V_23 . V_24 ,
F_2 ( V_44 ) -> V_64 , F_34 ( F_2 ( V_44 ) ) ) )
break;
V_61 = true ;
V_40 = & V_44 -> V_47 ;
V_60 -> V_62 ++ ;
}
if ( V_61 )
F_22 ( V_48 , V_40 ) ;
return 0 ;
}
T_3 F_38 ( struct V_28 * V_65 , char T_4 * V_13 , T_5 V_66 , T_2 * V_67 )
{
return - V_68 ;
}
struct V_7 * F_39 ( struct V_69 * V_70 , char * V_63 ,
const struct V_71 * V_72 , const struct V_73 * * V_74 ,
const struct V_75 * V_76 , unsigned long V_77 )
{
struct V_78 * V_79 ;
struct V_7 * V_7 ;
struct V_6 * V_80 ;
struct V_81 V_23 = F_40 ( V_63 , strlen ( V_63 ) ) ;
V_79 = F_41 ( V_70 , NULL , V_82 , V_83 | V_84 ,
& V_85 , NULL ) ;
if ( F_42 ( V_79 ) )
return F_43 ( V_79 ) ;
V_79 -> V_86 = V_87 ;
V_79 -> V_88 = V_18 ;
V_79 -> V_89 = V_11 ;
V_79 -> V_16 = V_77 ;
V_79 -> V_90 = V_72 ? V_72 : & V_91 ;
V_79 -> V_92 = V_74 ;
V_79 -> V_93 = 1 ;
V_80 = F_44 ( V_79 ) ;
if ( ! V_80 )
goto V_94;
V_80 -> V_64 = 1 ;
V_80 -> V_58 = V_95 | V_96 | V_97 ;
V_80 -> V_98 = V_80 -> V_99 = V_80 -> V_100 = F_45 ( V_80 ) ;
V_7 = F_46 ( V_79 , & V_23 ) ;
if ( ! V_7 ) {
F_47 ( V_80 ) ;
goto V_94;
}
F_48 ( V_7 , V_80 ) ;
V_79 -> V_101 = V_7 ;
V_79 -> V_26 = V_76 ;
V_79 -> V_102 |= V_103 ;
return F_49 ( V_79 -> V_101 ) ;
V_94:
F_50 ( V_79 ) ;
return F_7 ( - V_31 ) ;
}
int F_51 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
if ( V_6 -> V_104 )
V_28 -> V_29 = V_6 -> V_104 ;
return 0 ;
}
int F_52 ( struct V_7 * V_105 , struct V_6 * V_21 , struct V_7 * V_7 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
V_6 -> V_100 = V_21 -> V_100 = V_21 -> V_99 = F_45 ( V_6 ) ;
F_53 ( V_6 ) ;
F_54 ( V_6 ) ;
F_49 ( V_7 ) ;
F_48 ( V_7 , V_6 ) ;
return 0 ;
}
int F_55 ( struct V_7 * V_7 )
{
struct V_7 * V_106 ;
int V_107 = 0 ;
F_23 ( & V_7 -> V_51 ) ;
F_56 (child, &dentry->d_subdirs, d_child) {
F_57 ( & V_106 -> V_51 , V_108 ) ;
if ( F_18 ( V_106 ) ) {
F_30 ( & V_106 -> V_51 ) ;
goto V_109;
}
F_30 ( & V_106 -> V_51 ) ;
}
V_107 = 1 ;
V_109:
F_30 ( & V_7 -> V_51 ) ;
return V_107 ;
}
int F_58 ( struct V_6 * V_21 , struct V_7 * V_7 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
V_6 -> V_100 = V_21 -> V_100 = V_21 -> V_99 = F_45 ( V_6 ) ;
F_59 ( V_6 ) ;
F_13 ( V_7 ) ;
return 0 ;
}
int F_60 ( struct V_6 * V_21 , struct V_7 * V_7 )
{
if ( ! F_55 ( V_7 ) )
return - V_110 ;
F_59 ( F_2 ( V_7 ) ) ;
F_58 ( V_21 , V_7 ) ;
F_59 ( V_21 ) ;
return 0 ;
}
int F_61 ( struct V_6 * V_111 , struct V_7 * V_105 ,
struct V_6 * V_112 , struct V_7 * V_113 ,
unsigned int V_22 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
int V_114 = F_62 ( V_105 ) ;
if ( V_22 & ~ V_115 )
return - V_56 ;
if ( ! F_55 ( V_113 ) )
return - V_110 ;
if ( F_63 ( V_113 ) ) {
F_58 ( V_112 , V_113 ) ;
if ( V_114 ) {
F_59 ( F_2 ( V_113 ) ) ;
F_59 ( V_111 ) ;
}
} else if ( V_114 ) {
F_59 ( V_111 ) ;
F_53 ( V_112 ) ;
}
V_111 -> V_100 = V_111 -> V_99 = V_112 -> V_100 =
V_112 -> V_99 = V_6 -> V_100 = F_45 ( V_111 ) ;
return 0 ;
}
int F_64 ( struct V_7 * V_7 , struct V_116 * V_116 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
int error ;
error = F_65 ( V_7 , V_116 ) ;
if ( error )
return error ;
if ( V_116 -> V_117 & V_118 )
F_66 ( V_6 , V_116 -> V_119 ) ;
F_67 ( V_6 , V_116 ) ;
F_68 ( V_6 ) ;
return 0 ;
}
int F_69 ( struct V_28 * V_28 , struct V_120 * V_120 )
{
F_70 ( V_120 ) ;
F_71 ( V_120 ) ;
F_72 ( V_120 ) ;
F_73 ( V_120 ) ;
return 0 ;
}
int F_74 ( struct V_28 * V_28 , struct V_121 * V_122 ,
T_2 V_62 , unsigned V_24 , unsigned V_22 ,
struct V_120 * * V_123 , void * * V_124 )
{
struct V_120 * V_120 ;
T_6 V_125 ;
V_125 = V_62 >> V_11 ;
V_120 = F_75 ( V_122 , V_125 , V_22 ) ;
if ( ! V_120 )
return - V_31 ;
* V_123 = V_120 ;
if ( ! F_76 ( V_120 ) && ( V_24 != V_18 ) ) {
unsigned V_34 = V_62 & ( V_18 - 1 ) ;
F_77 ( V_120 , 0 , V_34 , V_34 + V_24 , V_18 ) ;
}
return 0 ;
}
int F_78 ( struct V_28 * V_28 , struct V_121 * V_122 ,
T_2 V_62 , unsigned V_24 , unsigned V_126 ,
struct V_120 * V_120 , void * V_124 )
{
struct V_6 * V_6 = V_120 -> V_122 -> V_127 ;
T_2 V_128 = V_62 + V_126 ;
if ( ! F_76 ( V_120 ) ) {
if ( V_126 < V_24 ) {
unsigned V_34 = V_62 & ( V_18 - 1 ) ;
F_79 ( V_120 , V_34 + V_126 , V_24 - V_126 ) ;
}
F_72 ( V_120 ) ;
}
if ( V_128 > V_6 -> V_129 )
F_80 ( V_6 , V_128 ) ;
F_81 ( V_120 ) ;
F_73 ( V_120 ) ;
F_82 ( V_120 ) ;
return V_126 ;
}
int F_83 ( struct V_78 * V_79 , unsigned long V_77 ,
const struct V_130 * V_131 )
{
struct V_6 * V_6 ;
struct V_7 * V_80 ;
struct V_7 * V_7 ;
int V_42 ;
V_79 -> V_88 = V_18 ;
V_79 -> V_89 = V_11 ;
V_79 -> V_16 = V_77 ;
V_79 -> V_90 = & V_91 ;
V_79 -> V_93 = 1 ;
V_6 = F_44 ( V_79 ) ;
if ( ! V_6 )
return - V_31 ;
V_6 -> V_64 = 1 ;
V_6 -> V_58 = V_95 | 0755 ;
V_6 -> V_98 = V_6 -> V_99 = V_6 -> V_100 = F_45 ( V_6 ) ;
V_6 -> V_132 = & V_133 ;
V_6 -> V_134 = & V_135 ;
F_84 ( V_6 , 2 ) ;
V_80 = F_85 ( V_6 ) ;
if ( ! V_80 )
return - V_31 ;
for ( V_42 = 0 ; ! V_131 -> V_63 || V_131 -> V_63 [ 0 ] ; V_42 ++ , V_131 ++ ) {
if ( ! V_131 -> V_63 )
continue;
if ( F_21 ( V_42 == 1 ) )
F_86 ( V_136 L_1
L_2 , V_137 ,
V_79 -> V_138 -> V_63 ) ;
V_7 = F_87 ( V_80 , V_131 -> V_63 ) ;
if ( ! V_7 )
goto V_109;
V_6 = F_44 ( V_79 ) ;
if ( ! V_6 ) {
F_13 ( V_7 ) ;
goto V_109;
}
V_6 -> V_58 = V_139 | V_131 -> V_140 ;
V_6 -> V_98 = V_6 -> V_99 = V_6 -> V_100 = F_45 ( V_6 ) ;
V_6 -> V_134 = V_131 -> V_72 ;
V_6 -> V_64 = V_42 ;
F_9 ( V_7 , V_6 ) ;
}
V_79 -> V_101 = V_80 ;
return 0 ;
V_109:
F_88 ( V_80 ) ;
F_89 ( V_80 ) ;
F_13 ( V_80 ) ;
return - V_31 ;
}
int F_90 ( struct V_69 * type , struct V_141 * * V_142 , int * V_35 )
{
struct V_141 * V_143 = NULL ;
F_23 ( & V_144 ) ;
if ( F_21 ( ! * V_142 ) ) {
F_30 ( & V_144 ) ;
V_143 = F_91 ( type , V_83 , type -> V_63 , NULL ) ;
if ( F_42 ( V_143 ) )
return F_92 ( V_143 ) ;
F_23 ( & V_144 ) ;
if ( ! * V_142 )
* V_142 = V_143 ;
}
F_93 ( * V_142 ) ;
++ * V_35 ;
F_30 ( & V_144 ) ;
F_94 ( V_143 ) ;
return 0 ;
}
void F_95 ( struct V_141 * * V_142 , int * V_35 )
{
struct V_141 * V_143 ;
F_23 ( & V_144 ) ;
V_143 = * V_142 ;
if ( ! -- * V_35 )
* V_142 = NULL ;
F_30 ( & V_144 ) ;
F_94 ( V_143 ) ;
}
T_3 F_96 ( void T_4 * V_57 , T_5 V_35 , T_2 * V_67 ,
const void * V_34 , T_5 V_145 )
{
T_2 V_62 = * V_67 ;
T_5 V_107 ;
if ( V_62 < 0 )
return - V_56 ;
if ( V_62 >= V_145 || ! V_35 )
return 0 ;
if ( V_35 > V_145 - V_62 )
V_35 = V_145 - V_62 ;
V_107 = F_97 ( V_57 , V_34 + V_62 , V_35 ) ;
if ( V_107 == V_35 )
return - V_146 ;
V_35 -= V_107 ;
* V_67 = V_62 + V_35 ;
return V_35 ;
}
T_3 F_98 ( void * V_57 , T_5 V_145 , T_2 * V_67 ,
const void T_4 * V_34 , T_5 V_35 )
{
T_2 V_62 = * V_67 ;
T_5 V_39 ;
if ( V_62 < 0 )
return - V_56 ;
if ( V_62 >= V_145 || ! V_35 )
return 0 ;
if ( V_35 > V_145 - V_62 )
V_35 = V_145 - V_62 ;
V_39 = F_99 ( V_57 + V_62 , V_34 , V_35 ) ;
if ( V_39 == V_35 )
return - V_146 ;
V_35 -= V_39 ;
* V_67 = V_62 + V_35 ;
return V_35 ;
}
T_3 F_100 ( void * V_57 , T_5 V_35 , T_2 * V_67 ,
const void * V_34 , T_5 V_145 )
{
T_2 V_62 = * V_67 ;
if ( V_62 < 0 )
return - V_56 ;
if ( V_62 >= V_145 )
return 0 ;
if ( V_35 > V_145 - V_62 )
V_35 = V_145 - V_62 ;
memcpy ( V_57 , V_34 + V_62 , V_35 ) ;
* V_67 = V_62 + V_35 ;
return V_35 ;
}
void F_101 ( struct V_28 * V_28 , T_5 V_38 )
{
struct V_147 * V_148 = V_28 -> V_29 ;
F_102 ( V_38 > V_149 ) ;
F_103 () ;
V_148 -> V_150 = V_38 ;
}
char * F_104 ( struct V_28 * V_28 , const char T_4 * V_13 , T_5 V_150 )
{
struct V_147 * V_148 ;
static F_105 ( V_151 ) ;
if ( V_150 > V_149 - 1 )
return F_7 ( - V_152 ) ;
V_148 = (struct V_147 * ) F_106 ( V_153 ) ;
if ( ! V_148 )
return F_7 ( - V_31 ) ;
F_23 ( & V_151 ) ;
if ( V_28 -> V_29 ) {
F_30 ( & V_151 ) ;
F_107 ( ( unsigned long ) V_148 ) ;
return F_7 ( - V_154 ) ;
}
V_28 -> V_29 = V_148 ;
F_30 ( & V_151 ) ;
if ( F_99 ( V_148 -> V_155 , V_13 , V_150 ) )
return F_7 ( - V_146 ) ;
return V_148 -> V_155 ;
}
T_3 F_108 ( struct V_28 * V_28 , char T_4 * V_13 , T_5 V_150 , T_2 * V_62 )
{
struct V_147 * V_148 = V_28 -> V_29 ;
if ( ! V_148 )
return 0 ;
return F_96 ( V_13 , V_150 , V_62 , V_148 -> V_155 , V_148 -> V_150 ) ;
}
int F_109 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
F_107 ( ( unsigned long ) V_28 -> V_29 ) ;
return 0 ;
}
int F_110 ( struct V_6 * V_6 , struct V_28 * V_28 ,
int (* F_111)( void * , T_7 * ) , int (* F_112)( void * , T_7 ) ,
const char * V_156 )
{
struct V_157 * V_158 ;
V_158 = F_113 ( sizeof( * V_158 ) , V_153 ) ;
if ( ! V_158 )
return - V_31 ;
V_158 -> F_111 = F_111 ;
V_158 -> F_112 = F_112 ;
V_158 -> V_155 = V_6 -> V_104 ;
V_158 -> V_156 = V_156 ;
F_114 ( & V_158 -> V_159 ) ;
V_28 -> V_29 = V_158 ;
return F_115 ( V_6 , V_28 ) ;
}
int F_116 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
F_117 ( V_28 -> V_29 ) ;
return 0 ;
}
T_3 F_118 ( struct V_28 * V_28 , char T_4 * V_13 ,
T_5 V_24 , T_2 * V_67 )
{
struct V_157 * V_158 ;
T_5 V_150 ;
T_3 V_107 ;
V_158 = V_28 -> V_29 ;
if ( ! V_158 -> F_111 )
return - V_160 ;
V_107 = F_119 ( & V_158 -> V_159 ) ;
if ( V_107 )
return V_107 ;
if ( * V_67 ) {
V_150 = strlen ( V_158 -> V_161 ) ;
} else {
T_7 V_162 ;
V_107 = V_158 -> F_111 ( V_158 -> V_155 , & V_162 ) ;
if ( V_107 )
goto V_109;
V_150 = F_120 ( V_158 -> V_161 , sizeof( V_158 -> V_161 ) ,
V_158 -> V_156 , ( unsigned long long ) V_162 ) ;
}
V_107 = F_96 ( V_13 , V_24 , V_67 , V_158 -> V_161 , V_150 ) ;
V_109:
F_121 ( & V_158 -> V_159 ) ;
return V_107 ;
}
T_3 F_122 ( struct V_28 * V_28 , const char T_4 * V_13 ,
T_5 V_24 , T_2 * V_67 )
{
struct V_157 * V_158 ;
T_7 V_162 ;
T_5 V_150 ;
T_3 V_107 ;
V_158 = V_28 -> V_29 ;
if ( ! V_158 -> F_112 )
return - V_160 ;
V_107 = F_119 ( & V_158 -> V_159 ) ;
if ( V_107 )
return V_107 ;
V_107 = - V_146 ;
V_150 = F_123 ( sizeof( V_158 -> V_163 ) - 1 , V_24 ) ;
if ( F_99 ( V_158 -> V_163 , V_13 , V_150 ) )
goto V_109;
V_158 -> V_163 [ V_150 ] = '\0' ;
V_162 = F_124 ( V_158 -> V_163 , NULL , 0 ) ;
V_107 = V_158 -> F_112 ( V_158 -> V_155 , V_162 ) ;
if ( V_107 == 0 )
V_107 = V_24 ;
V_109:
F_121 ( & V_158 -> V_159 ) ;
return V_107 ;
}
int F_125 ( struct V_28 * V_28 , T_2 V_164 , T_2 V_165 ,
int V_166 )
{
struct V_6 * V_6 = V_28 -> V_167 -> V_127 ;
int V_168 ;
int V_107 ;
V_168 = F_126 ( V_6 -> V_9 , V_164 , V_165 ) ;
if ( V_168 )
return V_168 ;
F_127 ( V_6 ) ;
V_107 = F_128 ( V_6 -> V_9 ) ;
if ( ! ( V_6 -> V_169 & V_170 ) )
goto V_109;
if ( V_166 && ! ( V_6 -> V_169 & V_171 ) )
goto V_109;
V_168 = F_129 ( V_6 , 1 ) ;
if ( V_107 == 0 )
V_107 = V_168 ;
V_109:
F_130 ( V_6 ) ;
return V_107 ;
}
int F_131 ( struct V_28 * V_28 , T_2 V_164 , T_2 V_165 ,
int V_166 )
{
struct V_6 * V_6 = V_28 -> V_167 -> V_127 ;
int V_168 ;
V_168 = F_125 ( V_28 , V_164 , V_165 , V_166 ) ;
if ( V_168 )
return V_168 ;
return F_132 ( V_6 -> V_172 -> V_173 , V_153 , NULL ) ;
}
int F_133 ( unsigned V_174 , T_7 V_175 )
{
T_7 V_176 = V_175 - 1 ;
T_7 V_177 =
V_176 >> ( V_11 - V_174 ) ;
if ( F_21 ( V_175 == 0 ) )
return 0 ;
if ( ( V_174 < 9 ) || ( V_174 > V_11 ) )
return - V_56 ;
if ( ( V_176 > ( V_178 ) ( ~ 0ULL ) >> ( V_174 - 9 ) ) ||
( V_177 > ( T_6 ) ( ~ 0ULL ) ) ) {
return - V_152 ;
}
return 0 ;
}
int F_134 ( struct V_28 * V_28 , T_2 V_164 , T_2 V_165 , int V_166 )
{
return 0 ;
}
void F_135 ( void * V_40 )
{
F_117 ( V_40 ) ;
}
static int F_136 ( struct V_120 * V_120 )
{
return 0 ;
}
struct V_6 * F_137 ( struct V_78 * V_79 )
{
static const struct V_179 V_180 = {
. F_81 = F_136 ,
} ;
struct V_6 * V_6 = F_138 ( V_79 ) ;
if ( ! V_6 )
return F_7 ( - V_31 ) ;
V_6 -> V_64 = F_139 () ;
V_6 -> V_9 -> V_181 = & V_180 ;
V_6 -> V_169 = V_182 ;
V_6 -> V_58 = V_96 | V_97 ;
V_6 -> V_183 = F_140 () ;
V_6 -> V_184 = F_141 () ;
V_6 -> V_185 |= V_186 ;
V_6 -> V_98 = V_6 -> V_99 = V_6 -> V_100 = F_45 ( V_6 ) ;
return V_6 ;
}
int
F_142 ( struct V_28 * V_65 , long V_187 , struct V_188 * * V_189 ,
void * * V_190 )
{
return - V_56 ;
}
const char * F_143 ( struct V_7 * V_7 , struct V_6 * V_6 ,
struct V_191 * V_192 )
{
return V_6 -> V_193 ;
}
static struct V_7 * F_144 ( struct V_6 * V_21 , struct V_7 * V_7 , unsigned int V_22 )
{
return F_7 ( - V_194 ) ;
}
static int F_145 ( const struct V_1 * V_1 , struct V_2 * V_3 ,
T_1 V_4 , unsigned int V_5 )
{
struct V_6 * V_6 = F_2 ( V_1 -> V_7 ) ;
F_3 ( V_6 , V_3 ) ;
return 0 ;
}
static int F_146 ( struct V_7 * V_7 , struct V_116 * V_158 )
{
return - V_195 ;
}
static T_3 F_147 ( struct V_7 * V_7 , char * V_196 , T_5 V_150 )
{
return - V_197 ;
}
static T_2 F_148 ( struct V_28 * V_28 , T_2 V_53 , int V_54 )
{
return F_149 ( V_28 , V_53 , V_54 , 2 , 2 ) ;
}
static int F_150 ( struct V_28 * V_28 , struct V_59 * V_60 )
{
F_36 ( V_28 , V_60 ) ;
return 0 ;
}
void F_151 ( struct V_6 * V_6 )
{
F_84 ( V_6 , 2 ) ;
V_6 -> V_58 = V_95 | V_198 | V_199 ;
V_6 -> V_183 = V_200 ;
V_6 -> V_184 = V_201 ;
V_6 -> V_202 = 0 ;
V_6 -> V_129 = 0 ;
V_6 -> V_203 = V_11 ;
V_6 -> V_204 = 0 ;
V_6 -> V_132 = & V_205 ;
V_6 -> V_206 &= ~ V_207 ;
V_6 -> V_134 = & V_208 ;
}
bool F_152 ( struct V_6 * V_6 )
{
return ( V_6 -> V_134 == & V_208 ) &&
( V_6 -> V_132 == & V_205 ) ;
}
