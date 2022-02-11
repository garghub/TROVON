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
V_78 = F_41 ( V_69 , NULL , V_81 , V_82 | V_83 ,
& V_84 , NULL ) ;
if ( F_42 ( V_78 ) )
return F_43 ( V_78 ) ;
V_78 -> V_85 = V_86 ;
V_78 -> V_87 = V_17 ;
V_78 -> V_88 = V_10 ;
V_78 -> V_15 = V_76 ;
V_78 -> V_89 = V_71 ? V_71 : & V_90 ;
V_78 -> V_91 = V_73 ;
V_78 -> V_92 = 1 ;
V_79 = F_44 ( V_78 ) ;
if ( ! V_79 )
goto V_93;
V_79 -> V_63 = 1 ;
V_79 -> V_57 = V_94 | V_95 | V_96 ;
V_79 -> V_97 = V_79 -> V_98 = V_79 -> V_99 = F_45 ( V_79 ) ;
V_3 = F_46 ( V_78 , & V_22 ) ;
if ( ! V_3 ) {
F_47 ( V_79 ) ;
goto V_93;
}
F_48 ( V_3 , V_79 ) ;
V_78 -> V_100 = V_3 ;
V_78 -> V_25 = V_75 ;
V_78 -> V_101 |= V_102 ;
return F_49 ( V_78 -> V_100 ) ;
V_93:
F_50 ( V_78 ) ;
return F_7 ( - V_30 ) ;
}
int F_51 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
if ( V_6 -> V_103 )
V_27 -> V_28 = V_6 -> V_103 ;
return 0 ;
}
int F_52 ( struct V_3 * V_104 , struct V_6 * V_20 , struct V_3 * V_3 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
V_6 -> V_99 = V_20 -> V_99 = V_20 -> V_98 = F_45 ( V_6 ) ;
F_53 ( V_6 ) ;
F_54 ( V_6 ) ;
F_49 ( V_3 ) ;
F_48 ( V_3 , V_6 ) ;
return 0 ;
}
int F_55 ( struct V_3 * V_3 )
{
struct V_3 * V_105 ;
int V_106 = 0 ;
F_23 ( & V_3 -> V_50 ) ;
F_56 (child, &dentry->d_subdirs, d_child) {
F_57 ( & V_105 -> V_50 , V_107 ) ;
if ( F_18 ( V_105 ) ) {
F_30 ( & V_105 -> V_50 ) ;
goto V_108;
}
F_30 ( & V_105 -> V_50 ) ;
}
V_106 = 1 ;
V_108:
F_30 ( & V_3 -> V_50 ) ;
return V_106 ;
}
int F_58 ( struct V_6 * V_20 , struct V_3 * V_3 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
V_6 -> V_99 = V_20 -> V_99 = V_20 -> V_98 = F_45 ( V_6 ) ;
F_59 ( V_6 ) ;
F_13 ( V_3 ) ;
return 0 ;
}
int F_60 ( struct V_6 * V_20 , struct V_3 * V_3 )
{
if ( ! F_55 ( V_3 ) )
return - V_109 ;
F_59 ( F_2 ( V_3 ) ) ;
F_58 ( V_20 , V_3 ) ;
F_59 ( V_20 ) ;
return 0 ;
}
int F_61 ( struct V_6 * V_110 , struct V_3 * V_104 ,
struct V_6 * V_111 , struct V_3 * V_112 ,
unsigned int V_21 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
int V_113 = F_62 ( V_104 ) ;
if ( V_21 & ~ V_114 )
return - V_55 ;
if ( ! F_55 ( V_112 ) )
return - V_109 ;
if ( F_63 ( V_112 ) ) {
F_58 ( V_111 , V_112 ) ;
if ( V_113 ) {
F_59 ( F_2 ( V_112 ) ) ;
F_59 ( V_110 ) ;
}
} else if ( V_113 ) {
F_59 ( V_110 ) ;
F_53 ( V_111 ) ;
}
V_110 -> V_99 = V_110 -> V_98 = V_111 -> V_99 =
V_111 -> V_98 = V_6 -> V_99 = F_45 ( V_110 ) ;
return 0 ;
}
int F_64 ( struct V_3 * V_3 , struct V_115 * V_115 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
int error ;
error = F_65 ( V_3 , V_115 ) ;
if ( error )
return error ;
if ( V_115 -> V_116 & V_117 )
F_66 ( V_6 , V_115 -> V_118 ) ;
F_67 ( V_6 , V_115 ) ;
F_68 ( V_6 ) ;
return 0 ;
}
int F_69 ( struct V_27 * V_27 , struct V_119 * V_119 )
{
F_70 ( V_119 ) ;
F_71 ( V_119 ) ;
F_72 ( V_119 ) ;
F_73 ( V_119 ) ;
return 0 ;
}
int F_74 ( struct V_27 * V_27 , struct V_120 * V_121 ,
T_1 V_61 , unsigned V_23 , unsigned V_21 ,
struct V_119 * * V_122 , void * * V_123 )
{
struct V_119 * V_119 ;
T_5 V_124 ;
V_124 = V_61 >> V_10 ;
V_119 = F_75 ( V_121 , V_124 , V_21 ) ;
if ( ! V_119 )
return - V_30 ;
* V_122 = V_119 ;
if ( ! F_76 ( V_119 ) && ( V_23 != V_17 ) ) {
unsigned V_33 = V_61 & ( V_17 - 1 ) ;
F_77 ( V_119 , 0 , V_33 , V_33 + V_23 , V_17 ) ;
}
return 0 ;
}
int F_78 ( struct V_27 * V_27 , struct V_120 * V_121 ,
T_1 V_61 , unsigned V_23 , unsigned V_125 ,
struct V_119 * V_119 , void * V_123 )
{
struct V_6 * V_6 = V_119 -> V_121 -> V_126 ;
T_1 V_127 = V_61 + V_125 ;
if ( ! F_76 ( V_119 ) ) {
if ( V_125 < V_23 ) {
unsigned V_33 = V_61 & ( V_17 - 1 ) ;
F_79 ( V_119 , V_33 + V_125 , V_23 - V_125 ) ;
}
F_72 ( V_119 ) ;
}
if ( V_127 > V_6 -> V_128 )
F_80 ( V_6 , V_127 ) ;
F_81 ( V_119 ) ;
F_73 ( V_119 ) ;
F_82 ( V_119 ) ;
return V_125 ;
}
int F_83 ( struct V_77 * V_78 , unsigned long V_76 ,
struct V_129 * V_130 )
{
struct V_6 * V_6 ;
struct V_3 * V_79 ;
struct V_3 * V_3 ;
int V_41 ;
V_78 -> V_87 = V_17 ;
V_78 -> V_88 = V_10 ;
V_78 -> V_15 = V_76 ;
V_78 -> V_89 = & V_90 ;
V_78 -> V_92 = 1 ;
V_6 = F_44 ( V_78 ) ;
if ( ! V_6 )
return - V_30 ;
V_6 -> V_63 = 1 ;
V_6 -> V_57 = V_94 | 0755 ;
V_6 -> V_97 = V_6 -> V_98 = V_6 -> V_99 = F_45 ( V_6 ) ;
V_6 -> V_131 = & V_132 ;
V_6 -> V_133 = & V_134 ;
F_84 ( V_6 , 2 ) ;
V_79 = F_85 ( V_6 ) ;
if ( ! V_79 )
return - V_30 ;
for ( V_41 = 0 ; ! V_130 -> V_62 || V_130 -> V_62 [ 0 ] ; V_41 ++ , V_130 ++ ) {
if ( ! V_130 -> V_62 )
continue;
if ( F_21 ( V_41 == 1 ) )
F_86 ( V_135 L_1
L_2 , V_136 ,
V_78 -> V_137 -> V_62 ) ;
V_3 = F_87 ( V_79 , V_130 -> V_62 ) ;
if ( ! V_3 )
goto V_108;
V_6 = F_44 ( V_78 ) ;
if ( ! V_6 ) {
F_13 ( V_3 ) ;
goto V_108;
}
V_6 -> V_57 = V_138 | V_130 -> V_139 ;
V_6 -> V_97 = V_6 -> V_98 = V_6 -> V_99 = F_45 ( V_6 ) ;
V_6 -> V_133 = V_130 -> V_71 ;
V_6 -> V_63 = V_41 ;
F_9 ( V_3 , V_6 ) ;
}
V_78 -> V_100 = V_79 ;
return 0 ;
V_108:
F_88 ( V_79 ) ;
F_89 ( V_79 ) ;
F_13 ( V_79 ) ;
return - V_30 ;
}
int F_90 ( struct V_68 * type , struct V_1 * * V_140 , int * V_34 )
{
struct V_1 * V_2 = NULL ;
F_23 ( & V_141 ) ;
if ( F_21 ( ! * V_140 ) ) {
F_30 ( & V_141 ) ;
V_2 = F_91 ( type , V_82 , type -> V_62 , NULL ) ;
if ( F_42 ( V_2 ) )
return F_92 ( V_2 ) ;
F_23 ( & V_141 ) ;
if ( ! * V_140 )
* V_140 = V_2 ;
}
F_93 ( * V_140 ) ;
++ * V_34 ;
F_30 ( & V_141 ) ;
F_94 ( V_2 ) ;
return 0 ;
}
void F_95 ( struct V_1 * * V_140 , int * V_34 )
{
struct V_1 * V_2 ;
F_23 ( & V_141 ) ;
V_2 = * V_140 ;
if ( ! -- * V_34 )
* V_140 = NULL ;
F_30 ( & V_141 ) ;
F_94 ( V_2 ) ;
}
T_2 F_96 ( void T_3 * V_56 , T_4 V_34 , T_1 * V_66 ,
const void * V_33 , T_4 V_142 )
{
T_1 V_61 = * V_66 ;
T_4 V_106 ;
if ( V_61 < 0 )
return - V_55 ;
if ( V_61 >= V_142 || ! V_34 )
return 0 ;
if ( V_34 > V_142 - V_61 )
V_34 = V_142 - V_61 ;
V_106 = F_97 ( V_56 , V_33 + V_61 , V_34 ) ;
if ( V_106 == V_34 )
return - V_143 ;
V_34 -= V_106 ;
* V_66 = V_61 + V_34 ;
return V_34 ;
}
T_2 F_98 ( void * V_56 , T_4 V_142 , T_1 * V_66 ,
const void T_3 * V_33 , T_4 V_34 )
{
T_1 V_61 = * V_66 ;
T_4 V_38 ;
if ( V_61 < 0 )
return - V_55 ;
if ( V_61 >= V_142 || ! V_34 )
return 0 ;
if ( V_34 > V_142 - V_61 )
V_34 = V_142 - V_61 ;
V_38 = F_99 ( V_56 + V_61 , V_33 , V_34 ) ;
if ( V_38 == V_34 )
return - V_143 ;
V_34 -= V_38 ;
* V_66 = V_61 + V_34 ;
return V_34 ;
}
T_2 F_100 ( void * V_56 , T_4 V_34 , T_1 * V_66 ,
const void * V_33 , T_4 V_142 )
{
T_1 V_61 = * V_66 ;
if ( V_61 < 0 )
return - V_55 ;
if ( V_61 >= V_142 )
return 0 ;
if ( V_34 > V_142 - V_61 )
V_34 = V_142 - V_61 ;
memcpy ( V_56 , V_33 + V_61 , V_34 ) ;
* V_66 = V_61 + V_34 ;
return V_34 ;
}
void F_101 ( struct V_27 * V_27 , T_4 V_37 )
{
struct V_144 * V_145 = V_27 -> V_28 ;
F_102 ( V_37 > V_146 ) ;
F_103 () ;
V_145 -> V_147 = V_37 ;
}
char * F_104 ( struct V_27 * V_27 , const char T_3 * V_12 , T_4 V_147 )
{
struct V_144 * V_145 ;
static F_105 ( V_148 ) ;
if ( V_147 > V_146 - 1 )
return F_7 ( - V_149 ) ;
V_145 = (struct V_144 * ) F_106 ( V_150 ) ;
if ( ! V_145 )
return F_7 ( - V_30 ) ;
F_23 ( & V_148 ) ;
if ( V_27 -> V_28 ) {
F_30 ( & V_148 ) ;
F_107 ( ( unsigned long ) V_145 ) ;
return F_7 ( - V_151 ) ;
}
V_27 -> V_28 = V_145 ;
F_30 ( & V_148 ) ;
if ( F_99 ( V_145 -> V_152 , V_12 , V_147 ) )
return F_7 ( - V_143 ) ;
return V_145 -> V_152 ;
}
T_2 F_108 ( struct V_27 * V_27 , char T_3 * V_12 , T_4 V_147 , T_1 * V_61 )
{
struct V_144 * V_145 = V_27 -> V_28 ;
if ( ! V_145 )
return 0 ;
return F_96 ( V_12 , V_147 , V_61 , V_145 -> V_152 , V_145 -> V_147 ) ;
}
int F_109 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
F_107 ( ( unsigned long ) V_27 -> V_28 ) ;
return 0 ;
}
int F_110 ( struct V_6 * V_6 , struct V_27 * V_27 ,
int (* F_111)( void * , T_6 * ) , int (* F_112)( void * , T_6 ) ,
const char * V_153 )
{
struct V_154 * V_155 ;
V_155 = F_113 ( sizeof( * V_155 ) , V_150 ) ;
if ( ! V_155 )
return - V_30 ;
V_155 -> F_111 = F_111 ;
V_155 -> F_112 = F_112 ;
V_155 -> V_152 = V_6 -> V_103 ;
V_155 -> V_153 = V_153 ;
F_114 ( & V_155 -> V_156 ) ;
V_27 -> V_28 = V_155 ;
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
struct V_154 * V_155 ;
T_4 V_147 ;
T_2 V_106 ;
V_155 = V_27 -> V_28 ;
if ( ! V_155 -> F_111 )
return - V_157 ;
V_106 = F_119 ( & V_155 -> V_156 ) ;
if ( V_106 )
return V_106 ;
if ( * V_66 ) {
V_147 = strlen ( V_155 -> V_158 ) ;
} else {
T_6 V_159 ;
V_106 = V_155 -> F_111 ( V_155 -> V_152 , & V_159 ) ;
if ( V_106 )
goto V_108;
V_147 = F_120 ( V_155 -> V_158 , sizeof( V_155 -> V_158 ) ,
V_155 -> V_153 , ( unsigned long long ) V_159 ) ;
}
V_106 = F_96 ( V_12 , V_23 , V_66 , V_155 -> V_158 , V_147 ) ;
V_108:
F_121 ( & V_155 -> V_156 ) ;
return V_106 ;
}
T_2 F_122 ( struct V_27 * V_27 , const char T_3 * V_12 ,
T_4 V_23 , T_1 * V_66 )
{
struct V_154 * V_155 ;
T_6 V_159 ;
T_4 V_147 ;
T_2 V_106 ;
V_155 = V_27 -> V_28 ;
if ( ! V_155 -> F_112 )
return - V_157 ;
V_106 = F_119 ( & V_155 -> V_156 ) ;
if ( V_106 )
return V_106 ;
V_106 = - V_143 ;
V_147 = F_123 ( sizeof( V_155 -> V_160 ) - 1 , V_23 ) ;
if ( F_99 ( V_155 -> V_160 , V_12 , V_147 ) )
goto V_108;
V_155 -> V_160 [ V_147 ] = '\0' ;
V_159 = F_124 ( V_155 -> V_160 , NULL , 0 ) ;
V_106 = V_155 -> F_112 ( V_155 -> V_152 , V_159 ) ;
if ( V_106 == 0 )
V_106 = V_23 ;
V_108:
F_121 ( & V_155 -> V_156 ) ;
return V_106 ;
}
int F_125 ( struct V_27 * V_27 , T_1 V_161 , T_1 V_162 ,
int V_163 )
{
struct V_6 * V_6 = V_27 -> V_164 -> V_126 ;
int V_165 ;
int V_106 ;
V_165 = F_126 ( V_6 -> V_8 , V_161 , V_162 ) ;
if ( V_165 )
return V_165 ;
F_127 ( V_6 ) ;
V_106 = F_128 ( V_6 -> V_8 ) ;
if ( ! ( V_6 -> V_166 & V_167 ) )
goto V_108;
if ( V_163 && ! ( V_6 -> V_166 & V_168 ) )
goto V_108;
V_165 = F_129 ( V_6 , 1 ) ;
if ( V_106 == 0 )
V_106 = V_165 ;
V_108:
F_130 ( V_6 ) ;
return V_106 ;
}
int F_131 ( struct V_27 * V_27 , T_1 V_161 , T_1 V_162 ,
int V_163 )
{
struct V_6 * V_6 = V_27 -> V_164 -> V_126 ;
int V_165 ;
V_165 = F_125 ( V_27 , V_161 , V_162 , V_163 ) ;
if ( V_165 )
return V_165 ;
return F_132 ( V_6 -> V_169 -> V_170 , V_150 , NULL ) ;
}
int F_133 ( unsigned V_171 , T_6 V_172 )
{
T_6 V_173 = V_172 - 1 ;
T_6 V_174 =
V_173 >> ( V_10 - V_171 ) ;
if ( F_21 ( V_172 == 0 ) )
return 0 ;
if ( ( V_171 < 9 ) || ( V_171 > V_10 ) )
return - V_55 ;
if ( ( V_173 > ( V_175 ) ( ~ 0ULL ) >> ( V_171 - 9 ) ) ||
( V_174 > ( T_5 ) ( ~ 0ULL ) ) ) {
return - V_149 ;
}
return 0 ;
}
int F_134 ( struct V_27 * V_27 , T_1 V_161 , T_1 V_162 , int V_163 )
{
return 0 ;
}
void F_135 ( void * V_39 )
{
F_117 ( V_39 ) ;
}
static int F_136 ( struct V_119 * V_119 )
{
return 0 ;
}
struct V_6 * F_137 ( struct V_77 * V_78 )
{
static const struct V_176 V_177 = {
. F_81 = F_136 ,
} ;
struct V_6 * V_6 = F_138 ( V_78 ) ;
if ( ! V_6 )
return F_7 ( - V_30 ) ;
V_6 -> V_63 = F_139 () ;
V_6 -> V_8 -> V_178 = & V_177 ;
V_6 -> V_166 = V_179 ;
V_6 -> V_57 = V_95 | V_96 ;
V_6 -> V_180 = F_140 () ;
V_6 -> V_181 = F_141 () ;
V_6 -> V_182 |= V_183 ;
V_6 -> V_97 = V_6 -> V_98 = V_6 -> V_99 = F_45 ( V_6 ) ;
return V_6 ;
}
int
F_142 ( struct V_27 * V_64 , long V_184 , struct V_185 * * V_186 ,
void * * V_187 )
{
return - V_55 ;
}
const char * F_143 ( struct V_3 * V_3 , struct V_6 * V_6 ,
struct V_188 * V_189 )
{
return V_6 -> V_190 ;
}
static struct V_3 * F_144 ( struct V_6 * V_20 , struct V_3 * V_3 , unsigned int V_21 )
{
return F_7 ( - V_191 ) ;
}
static int F_145 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
F_3 ( V_6 , V_5 ) ;
return 0 ;
}
static int F_146 ( struct V_3 * V_3 , struct V_115 * V_155 )
{
return - V_192 ;
}
static T_2 F_147 ( struct V_3 * V_3 , char * V_193 , T_4 V_147 )
{
return - V_194 ;
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
V_6 -> V_57 = V_94 | V_195 | V_196 ;
V_6 -> V_180 = V_197 ;
V_6 -> V_181 = V_198 ;
V_6 -> V_199 = 0 ;
V_6 -> V_128 = 0 ;
V_6 -> V_200 = V_10 ;
V_6 -> V_201 = 0 ;
V_6 -> V_131 = & V_202 ;
V_6 -> V_203 &= ~ V_204 ;
V_6 -> V_133 = & V_205 ;
}
bool F_152 ( struct V_6 * V_6 )
{
return ( V_6 -> V_133 == & V_205 ) &&
( V_6 -> V_131 == & V_202 ) ;
}
