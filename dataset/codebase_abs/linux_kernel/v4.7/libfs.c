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
const struct V_70 * V_71 ,
const struct V_72 * V_73 , unsigned long V_74 )
{
struct V_75 * V_76 ;
struct V_3 * V_3 ;
struct V_6 * V_77 ;
struct V_78 V_22 = F_40 ( V_62 , strlen ( V_62 ) ) ;
V_76 = F_41 ( V_69 , NULL , V_79 , V_80 , NULL ) ;
if ( F_42 ( V_76 ) )
return F_43 ( V_76 ) ;
V_76 -> V_81 = V_82 ;
V_76 -> V_83 = V_17 ;
V_76 -> V_84 = V_10 ;
V_76 -> V_15 = V_74 ;
V_76 -> V_85 = V_71 ? V_71 : & V_86 ;
V_76 -> V_87 = 1 ;
V_77 = F_44 ( V_76 ) ;
if ( ! V_77 )
goto V_88;
V_77 -> V_63 = 1 ;
V_77 -> V_57 = V_89 | V_90 | V_91 ;
V_77 -> V_92 = V_77 -> V_93 = V_77 -> V_94 = V_95 ;
V_3 = F_45 ( V_76 , & V_22 ) ;
if ( ! V_3 ) {
F_46 ( V_77 ) ;
goto V_88;
}
F_47 ( V_3 , V_77 ) ;
V_76 -> V_96 = V_3 ;
V_76 -> V_25 = V_73 ;
V_76 -> V_97 |= V_98 ;
return F_48 ( V_76 -> V_96 ) ;
V_88:
F_49 ( V_76 ) ;
return F_7 ( - V_30 ) ;
}
int F_50 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
if ( V_6 -> V_99 )
V_27 -> V_28 = V_6 -> V_99 ;
return 0 ;
}
int F_51 ( struct V_3 * V_100 , struct V_6 * V_20 , struct V_3 * V_3 )
{
struct V_6 * V_6 = F_2 ( V_100 ) ;
V_6 -> V_94 = V_20 -> V_94 = V_20 -> V_93 = V_95 ;
F_52 ( V_6 ) ;
F_53 ( V_6 ) ;
F_48 ( V_3 ) ;
F_47 ( V_3 , V_6 ) ;
return 0 ;
}
int F_54 ( struct V_3 * V_3 )
{
struct V_3 * V_101 ;
int V_102 = 0 ;
F_23 ( & V_3 -> V_50 ) ;
F_55 (child, &dentry->d_subdirs, d_child) {
F_56 ( & V_101 -> V_50 , V_103 ) ;
if ( F_18 ( V_101 ) ) {
F_30 ( & V_101 -> V_50 ) ;
goto V_104;
}
F_30 ( & V_101 -> V_50 ) ;
}
V_102 = 1 ;
V_104:
F_30 ( & V_3 -> V_50 ) ;
return V_102 ;
}
int F_57 ( struct V_6 * V_20 , struct V_3 * V_3 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
V_6 -> V_94 = V_20 -> V_94 = V_20 -> V_93 = V_95 ;
F_58 ( V_6 ) ;
F_13 ( V_3 ) ;
return 0 ;
}
int F_59 ( struct V_6 * V_20 , struct V_3 * V_3 )
{
if ( ! F_54 ( V_3 ) )
return - V_105 ;
F_58 ( F_2 ( V_3 ) ) ;
F_57 ( V_20 , V_3 ) ;
F_58 ( V_20 ) ;
return 0 ;
}
int F_60 ( struct V_6 * V_106 , struct V_3 * V_100 ,
struct V_6 * V_107 , struct V_3 * V_108 )
{
struct V_6 * V_6 = F_2 ( V_100 ) ;
int V_109 = F_61 ( V_100 ) ;
if ( ! F_54 ( V_108 ) )
return - V_105 ;
if ( F_62 ( V_108 ) ) {
F_57 ( V_107 , V_108 ) ;
if ( V_109 ) {
F_58 ( F_2 ( V_108 ) ) ;
F_58 ( V_106 ) ;
}
} else if ( V_109 ) {
F_58 ( V_106 ) ;
F_52 ( V_107 ) ;
}
V_106 -> V_94 = V_106 -> V_93 = V_107 -> V_94 =
V_107 -> V_93 = V_6 -> V_94 = V_95 ;
return 0 ;
}
int F_63 ( struct V_3 * V_3 , struct V_110 * V_110 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
int error ;
error = F_64 ( V_6 , V_110 ) ;
if ( error )
return error ;
if ( V_110 -> V_111 & V_112 )
F_65 ( V_6 , V_110 -> V_113 ) ;
F_66 ( V_6 , V_110 ) ;
F_67 ( V_6 ) ;
return 0 ;
}
int F_68 ( struct V_27 * V_27 , struct V_114 * V_114 )
{
F_69 ( V_114 ) ;
F_70 ( V_114 ) ;
F_71 ( V_114 ) ;
F_72 ( V_114 ) ;
return 0 ;
}
int F_73 ( struct V_27 * V_27 , struct V_115 * V_116 ,
T_1 V_61 , unsigned V_23 , unsigned V_21 ,
struct V_114 * * V_117 , void * * V_118 )
{
struct V_114 * V_114 ;
T_5 V_119 ;
V_119 = V_61 >> V_10 ;
V_114 = F_74 ( V_116 , V_119 , V_21 ) ;
if ( ! V_114 )
return - V_30 ;
* V_117 = V_114 ;
if ( ! F_75 ( V_114 ) && ( V_23 != V_17 ) ) {
unsigned V_33 = V_61 & ( V_17 - 1 ) ;
F_76 ( V_114 , 0 , V_33 , V_33 + V_23 , V_17 ) ;
}
return 0 ;
}
int F_77 ( struct V_27 * V_27 , struct V_115 * V_116 ,
T_1 V_61 , unsigned V_23 , unsigned V_120 ,
struct V_114 * V_114 , void * V_118 )
{
struct V_6 * V_6 = V_114 -> V_116 -> V_121 ;
T_1 V_122 = V_61 + V_120 ;
if ( V_120 < V_23 ) {
unsigned V_33 = V_61 & ( V_17 - 1 ) ;
F_78 ( V_114 , V_33 + V_120 , V_23 - V_120 ) ;
}
if ( ! F_75 ( V_114 ) )
F_71 ( V_114 ) ;
if ( V_122 > V_6 -> V_123 )
F_79 ( V_6 , V_122 ) ;
F_80 ( V_114 ) ;
F_72 ( V_114 ) ;
F_81 ( V_114 ) ;
return V_120 ;
}
int F_82 ( struct V_75 * V_76 , unsigned long V_74 ,
struct V_124 * V_125 )
{
struct V_6 * V_6 ;
struct V_3 * V_77 ;
struct V_3 * V_3 ;
int V_41 ;
V_76 -> V_83 = V_17 ;
V_76 -> V_84 = V_10 ;
V_76 -> V_15 = V_74 ;
V_76 -> V_85 = & V_86 ;
V_76 -> V_87 = 1 ;
V_6 = F_44 ( V_76 ) ;
if ( ! V_6 )
return - V_30 ;
V_6 -> V_63 = 1 ;
V_6 -> V_57 = V_89 | 0755 ;
V_6 -> V_92 = V_6 -> V_93 = V_6 -> V_94 = V_95 ;
V_6 -> V_126 = & V_127 ;
V_6 -> V_128 = & V_129 ;
F_83 ( V_6 , 2 ) ;
V_77 = F_84 ( V_6 ) ;
if ( ! V_77 )
return - V_30 ;
for ( V_41 = 0 ; ! V_125 -> V_62 || V_125 -> V_62 [ 0 ] ; V_41 ++ , V_125 ++ ) {
if ( ! V_125 -> V_62 )
continue;
if ( F_21 ( V_41 == 1 ) )
F_85 ( V_130 L_1
L_2 , V_131 ,
V_76 -> V_132 -> V_62 ) ;
V_3 = F_86 ( V_77 , V_125 -> V_62 ) ;
if ( ! V_3 )
goto V_104;
V_6 = F_44 ( V_76 ) ;
if ( ! V_6 ) {
F_13 ( V_3 ) ;
goto V_104;
}
V_6 -> V_57 = V_133 | V_125 -> V_134 ;
V_6 -> V_92 = V_6 -> V_93 = V_6 -> V_94 = V_95 ;
V_6 -> V_128 = V_125 -> V_71 ;
V_6 -> V_63 = V_41 ;
F_9 ( V_3 , V_6 ) ;
}
V_76 -> V_96 = V_77 ;
return 0 ;
V_104:
F_87 ( V_77 ) ;
F_88 ( V_77 ) ;
F_13 ( V_77 ) ;
return - V_30 ;
}
int F_89 ( struct V_68 * type , struct V_1 * * V_135 , int * V_34 )
{
struct V_1 * V_2 = NULL ;
F_23 ( & V_136 ) ;
if ( F_21 ( ! * V_135 ) ) {
F_30 ( & V_136 ) ;
V_2 = F_90 ( type , V_137 , type -> V_62 , NULL ) ;
if ( F_42 ( V_2 ) )
return F_91 ( V_2 ) ;
F_23 ( & V_136 ) ;
if ( ! * V_135 )
* V_135 = V_2 ;
}
F_92 ( * V_135 ) ;
++ * V_34 ;
F_30 ( & V_136 ) ;
F_93 ( V_2 ) ;
return 0 ;
}
void F_94 ( struct V_1 * * V_135 , int * V_34 )
{
struct V_1 * V_2 ;
F_23 ( & V_136 ) ;
V_2 = * V_135 ;
if ( ! -- * V_34 )
* V_135 = NULL ;
F_30 ( & V_136 ) ;
F_93 ( V_2 ) ;
}
T_2 F_95 ( void T_3 * V_56 , T_4 V_34 , T_1 * V_66 ,
const void * V_33 , T_4 V_138 )
{
T_1 V_61 = * V_66 ;
T_4 V_102 ;
if ( V_61 < 0 )
return - V_55 ;
if ( V_61 >= V_138 || ! V_34 )
return 0 ;
if ( V_34 > V_138 - V_61 )
V_34 = V_138 - V_61 ;
V_102 = F_96 ( V_56 , V_33 + V_61 , V_34 ) ;
if ( V_102 == V_34 )
return - V_139 ;
V_34 -= V_102 ;
* V_66 = V_61 + V_34 ;
return V_34 ;
}
T_2 F_97 ( void * V_56 , T_4 V_138 , T_1 * V_66 ,
const void T_3 * V_33 , T_4 V_34 )
{
T_1 V_61 = * V_66 ;
T_4 V_38 ;
if ( V_61 < 0 )
return - V_55 ;
if ( V_61 >= V_138 || ! V_34 )
return 0 ;
if ( V_34 > V_138 - V_61 )
V_34 = V_138 - V_61 ;
V_38 = F_98 ( V_56 + V_61 , V_33 , V_34 ) ;
if ( V_38 == V_34 )
return - V_139 ;
V_34 -= V_38 ;
* V_66 = V_61 + V_34 ;
return V_34 ;
}
T_2 F_99 ( void * V_56 , T_4 V_34 , T_1 * V_66 ,
const void * V_33 , T_4 V_138 )
{
T_1 V_61 = * V_66 ;
if ( V_61 < 0 )
return - V_55 ;
if ( V_61 >= V_138 )
return 0 ;
if ( V_34 > V_138 - V_61 )
V_34 = V_138 - V_61 ;
memcpy ( V_56 , V_33 + V_61 , V_34 ) ;
* V_66 = V_61 + V_34 ;
return V_34 ;
}
void F_100 ( struct V_27 * V_27 , T_4 V_37 )
{
struct V_140 * V_141 = V_27 -> V_28 ;
F_101 ( V_37 > V_142 ) ;
F_102 () ;
V_141 -> V_143 = V_37 ;
}
char * F_103 ( struct V_27 * V_27 , const char T_3 * V_12 , T_4 V_143 )
{
struct V_140 * V_141 ;
static F_104 ( V_144 ) ;
if ( V_143 > V_142 - 1 )
return F_7 ( - V_145 ) ;
V_141 = (struct V_140 * ) F_105 ( V_146 ) ;
if ( ! V_141 )
return F_7 ( - V_30 ) ;
F_23 ( & V_144 ) ;
if ( V_27 -> V_28 ) {
F_30 ( & V_144 ) ;
F_106 ( ( unsigned long ) V_141 ) ;
return F_7 ( - V_147 ) ;
}
V_27 -> V_28 = V_141 ;
F_30 ( & V_144 ) ;
if ( F_98 ( V_141 -> V_148 , V_12 , V_143 ) )
return F_7 ( - V_139 ) ;
return V_141 -> V_148 ;
}
T_2 F_107 ( struct V_27 * V_27 , char T_3 * V_12 , T_4 V_143 , T_1 * V_61 )
{
struct V_140 * V_141 = V_27 -> V_28 ;
if ( ! V_141 )
return 0 ;
return F_95 ( V_12 , V_143 , V_61 , V_141 -> V_148 , V_141 -> V_143 ) ;
}
int F_108 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
F_106 ( ( unsigned long ) V_27 -> V_28 ) ;
return 0 ;
}
int F_109 ( struct V_6 * V_6 , struct V_27 * V_27 ,
int (* F_110)( void * , T_6 * ) , int (* F_111)( void * , T_6 ) ,
const char * V_149 )
{
struct V_150 * V_151 ;
V_151 = F_112 ( sizeof( * V_151 ) , V_146 ) ;
if ( ! V_151 )
return - V_30 ;
V_151 -> F_110 = F_110 ;
V_151 -> F_111 = F_111 ;
V_151 -> V_148 = V_6 -> V_99 ;
V_151 -> V_149 = V_149 ;
F_113 ( & V_151 -> V_152 ) ;
V_27 -> V_28 = V_151 ;
return F_114 ( V_6 , V_27 ) ;
}
int F_115 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
F_116 ( V_27 -> V_28 ) ;
return 0 ;
}
T_2 F_117 ( struct V_27 * V_27 , char T_3 * V_12 ,
T_4 V_23 , T_1 * V_66 )
{
struct V_150 * V_151 ;
T_4 V_143 ;
T_2 V_102 ;
V_151 = V_27 -> V_28 ;
if ( ! V_151 -> F_110 )
return - V_153 ;
V_102 = F_118 ( & V_151 -> V_152 ) ;
if ( V_102 )
return V_102 ;
if ( * V_66 ) {
V_143 = strlen ( V_151 -> V_154 ) ;
} else {
T_6 V_155 ;
V_102 = V_151 -> F_110 ( V_151 -> V_148 , & V_155 ) ;
if ( V_102 )
goto V_104;
V_143 = F_119 ( V_151 -> V_154 , sizeof( V_151 -> V_154 ) ,
V_151 -> V_149 , ( unsigned long long ) V_155 ) ;
}
V_102 = F_95 ( V_12 , V_23 , V_66 , V_151 -> V_154 , V_143 ) ;
V_104:
F_120 ( & V_151 -> V_152 ) ;
return V_102 ;
}
T_2 F_121 ( struct V_27 * V_27 , const char T_3 * V_12 ,
T_4 V_23 , T_1 * V_66 )
{
struct V_150 * V_151 ;
T_6 V_155 ;
T_4 V_143 ;
T_2 V_102 ;
V_151 = V_27 -> V_28 ;
if ( ! V_151 -> F_111 )
return - V_153 ;
V_102 = F_118 ( & V_151 -> V_152 ) ;
if ( V_102 )
return V_102 ;
V_102 = - V_139 ;
V_143 = F_122 ( sizeof( V_151 -> V_156 ) - 1 , V_23 ) ;
if ( F_98 ( V_151 -> V_156 , V_12 , V_143 ) )
goto V_104;
V_151 -> V_156 [ V_143 ] = '\0' ;
V_155 = F_123 ( V_151 -> V_156 , NULL , 0 ) ;
V_102 = V_151 -> F_111 ( V_151 -> V_148 , V_155 ) ;
if ( V_102 == 0 )
V_102 = V_23 ;
V_104:
F_120 ( & V_151 -> V_152 ) ;
return V_102 ;
}
int F_124 ( struct V_27 * V_27 , T_1 V_157 , T_1 V_158 ,
int V_159 )
{
struct V_6 * V_6 = V_27 -> V_160 -> V_121 ;
int V_161 ;
int V_102 ;
V_161 = F_125 ( V_6 -> V_8 , V_157 , V_158 ) ;
if ( V_161 )
return V_161 ;
F_126 ( V_6 ) ;
V_102 = F_127 ( V_6 -> V_8 ) ;
if ( ! ( V_6 -> V_162 & V_163 ) )
goto V_104;
if ( V_159 && ! ( V_6 -> V_162 & V_164 ) )
goto V_104;
V_161 = F_128 ( V_6 , 1 ) ;
if ( V_102 == 0 )
V_102 = V_161 ;
V_104:
F_129 ( V_6 ) ;
return V_102 ;
}
int F_130 ( struct V_27 * V_27 , T_1 V_157 , T_1 V_158 ,
int V_159 )
{
struct V_6 * V_6 = V_27 -> V_160 -> V_121 ;
int V_161 ;
V_161 = F_124 ( V_27 , V_157 , V_158 , V_159 ) ;
if ( V_161 )
return V_161 ;
return F_131 ( V_6 -> V_165 -> V_166 , V_146 , NULL ) ;
}
int F_132 ( unsigned V_167 , T_6 V_168 )
{
T_6 V_169 = V_168 - 1 ;
T_6 V_170 =
V_169 >> ( V_10 - V_167 ) ;
if ( F_21 ( V_168 == 0 ) )
return 0 ;
if ( ( V_167 < 9 ) || ( V_167 > V_10 ) )
return - V_55 ;
if ( ( V_169 > ( V_171 ) ( ~ 0ULL ) >> ( V_167 - 9 ) ) ||
( V_170 > ( T_5 ) ( ~ 0ULL ) ) ) {
return - V_145 ;
}
return 0 ;
}
int F_133 ( struct V_27 * V_27 , T_1 V_157 , T_1 V_158 , int V_159 )
{
return 0 ;
}
void F_134 ( void * V_39 )
{
F_116 ( V_39 ) ;
}
static int F_135 ( struct V_114 * V_114 )
{
return 0 ;
}
struct V_6 * F_136 ( struct V_75 * V_76 )
{
static const struct V_172 V_173 = {
. F_80 = F_135 ,
} ;
struct V_6 * V_6 = F_137 ( V_76 ) ;
if ( ! V_6 )
return F_7 ( - V_30 ) ;
V_6 -> V_63 = F_138 () ;
V_6 -> V_8 -> V_174 = & V_173 ;
V_6 -> V_162 = V_175 ;
V_6 -> V_57 = V_90 | V_91 ;
V_6 -> V_176 = F_139 () ;
V_6 -> V_177 = F_140 () ;
V_6 -> V_178 |= V_179 ;
V_6 -> V_92 = V_6 -> V_93 = V_6 -> V_94 = V_95 ;
return V_6 ;
}
int
F_141 ( struct V_27 * V_64 , long V_180 , struct V_181 * * V_182 ,
void * * V_183 )
{
return - V_55 ;
}
const char * F_142 ( struct V_3 * V_3 , struct V_6 * V_6 ,
struct V_184 * V_185 )
{
return V_6 -> V_186 ;
}
static struct V_3 * F_143 ( struct V_6 * V_20 , struct V_3 * V_3 , unsigned int V_21 )
{
return F_7 ( - V_187 ) ;
}
static int F_144 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
F_3 ( V_6 , V_5 ) ;
return 0 ;
}
static int F_145 ( struct V_3 * V_3 , struct V_110 * V_151 )
{
return - V_188 ;
}
static int F_146 ( struct V_3 * V_3 , struct V_6 * V_6 ,
const char * V_62 , const void * V_189 ,
T_4 V_143 , int V_21 )
{
return - V_190 ;
}
static T_2 F_147 ( struct V_3 * V_3 , struct V_6 * V_6 ,
const char * V_62 , void * V_189 , T_4 V_143 )
{
return - V_190 ;
}
static int F_148 ( struct V_3 * V_3 , const char * V_62 )
{
return - V_190 ;
}
static T_2 F_149 ( struct V_3 * V_3 , char * V_191 , T_4 V_143 )
{
return - V_190 ;
}
static T_1 F_150 ( struct V_27 * V_27 , T_1 V_52 , int V_53 )
{
return F_151 ( V_27 , V_52 , V_53 , 2 , 2 ) ;
}
static int F_152 ( struct V_27 * V_27 , struct V_58 * V_59 )
{
F_36 ( V_27 , V_59 ) ;
return 0 ;
}
void F_153 ( struct V_6 * V_6 )
{
F_83 ( V_6 , 2 ) ;
V_6 -> V_57 = V_89 | V_192 | V_193 ;
V_6 -> V_176 = V_194 ;
V_6 -> V_177 = V_195 ;
V_6 -> V_196 = 0 ;
V_6 -> V_123 = 0 ;
V_6 -> V_197 = V_10 ;
V_6 -> V_198 = 0 ;
V_6 -> V_126 = & V_199 ;
V_6 -> V_128 = & V_200 ;
}
bool F_154 ( struct V_6 * V_6 )
{
return ( V_6 -> V_128 == & V_200 ) &&
( V_6 -> V_126 == & V_199 ) ;
}
