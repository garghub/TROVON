static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 && ! F_2 ( V_1 ) ;
}
int F_3 ( struct V_3 * V_4 , struct V_1 * V_1 ,
struct V_5 * V_6 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
F_4 ( V_7 , V_6 ) ;
V_6 -> V_8 = V_7 -> V_9 -> V_10 << ( V_11 - 9 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_1 , struct V_12 * V_13 )
{
V_13 -> V_14 = V_1 -> V_15 -> V_16 ;
V_13 -> V_17 = V_18 ;
V_13 -> V_19 = V_20 ;
return 0 ;
}
int F_6 ( const struct V_1 * V_1 )
{
return 1 ;
}
struct V_1 * F_7 ( struct V_7 * V_21 , struct V_1 * V_1 , unsigned int V_22 )
{
if ( V_1 -> V_23 . V_24 > V_20 )
return F_8 ( - V_25 ) ;
if ( ! V_1 -> V_15 -> V_26 )
F_9 ( V_1 , & V_27 ) ;
F_10 ( V_1 , NULL ) ;
return NULL ;
}
int F_11 ( struct V_7 * V_7 , struct V_28 * V_28 )
{
static struct V_29 V_30 = F_12 ( L_1 , 1 ) ;
V_28 -> V_31 = F_13 ( V_28 -> V_32 . V_1 , & V_30 ) ;
return V_28 -> V_31 ? 0 : - V_33 ;
}
int F_14 ( struct V_7 * V_7 , struct V_28 * V_28 )
{
F_15 ( V_28 -> V_31 ) ;
return 0 ;
}
T_1 F_16 ( struct V_28 * V_28 , T_1 V_34 , int V_35 )
{
struct V_1 * V_1 = V_28 -> V_32 . V_1 ;
F_17 ( & V_1 -> V_2 -> V_36 ) ;
switch ( V_35 ) {
case 1 :
V_34 += V_28 -> V_37 ;
case 0 :
if ( V_34 >= 0 )
break;
default:
F_18 ( & V_1 -> V_2 -> V_36 ) ;
return - V_38 ;
}
if ( V_34 != V_28 -> V_37 ) {
V_28 -> V_37 = V_34 ;
if ( V_28 -> V_37 >= 2 ) {
struct V_39 * V_40 ;
struct V_1 * V_41 = V_28 -> V_31 ;
T_1 V_42 = V_28 -> V_37 - 2 ;
F_19 ( & V_1 -> V_43 ) ;
F_20 ( & V_41 -> V_44 . V_45 ) ;
V_40 = V_1 -> V_46 . V_47 ;
while ( V_42 && V_40 != & V_1 -> V_46 ) {
struct V_1 * V_47 ;
V_47 = F_21 ( V_40 , struct V_1 , V_44 . V_45 ) ;
F_22 ( & V_47 -> V_43 , V_48 ) ;
if ( F_1 ( V_47 ) )
V_42 -- ;
F_23 ( & V_47 -> V_43 ) ;
V_40 = V_40 -> V_47 ;
}
F_24 ( & V_41 -> V_44 . V_45 , V_40 ) ;
F_23 ( & V_1 -> V_43 ) ;
}
}
F_18 ( & V_1 -> V_2 -> V_36 ) ;
return V_34 ;
}
static inline unsigned char F_25 ( struct V_7 * V_7 )
{
return ( V_7 -> V_49 >> 12 ) & 15 ;
}
int F_26 ( struct V_28 * V_28 , struct V_50 * V_51 )
{
struct V_1 * V_1 = V_28 -> V_32 . V_1 ;
struct V_1 * V_41 = V_28 -> V_31 ;
struct V_39 * V_40 , * V_52 = & V_41 -> V_44 . V_45 ;
if ( ! F_27 ( V_28 , V_51 ) )
return 0 ;
F_19 ( & V_1 -> V_43 ) ;
if ( V_51 -> V_53 == 2 )
F_28 ( V_52 , & V_1 -> V_46 ) ;
for ( V_40 = V_52 -> V_47 ; V_40 != & V_1 -> V_46 ; V_40 = V_40 -> V_47 ) {
struct V_1 * V_47 = F_21 ( V_40 , struct V_1 , V_44 . V_45 ) ;
F_22 ( & V_47 -> V_43 , V_48 ) ;
if ( ! F_1 ( V_47 ) ) {
F_23 ( & V_47 -> V_43 ) ;
continue;
}
F_23 ( & V_47 -> V_43 ) ;
F_23 ( & V_1 -> V_43 ) ;
if ( ! F_29 ( V_51 , V_47 -> V_23 . V_54 , V_47 -> V_23 . V_24 ,
V_47 -> V_2 -> V_55 , F_25 ( V_47 -> V_2 ) ) )
return 0 ;
F_19 ( & V_1 -> V_43 ) ;
F_22 ( & V_47 -> V_43 , V_48 ) ;
F_28 ( V_52 , V_40 ) ;
F_23 ( & V_47 -> V_43 ) ;
V_40 = V_52 ;
V_51 -> V_53 ++ ;
}
F_23 ( & V_1 -> V_43 ) ;
return 0 ;
}
T_2 F_30 ( struct V_28 * V_56 , char T_3 * V_13 , T_4 V_57 , T_1 * V_58 )
{
return - V_59 ;
}
struct V_1 * F_31 ( struct V_60 * V_61 , char * V_54 ,
const struct V_62 * V_63 ,
const struct V_64 * V_65 , unsigned long V_66 )
{
struct V_67 * V_68 ;
struct V_1 * V_1 ;
struct V_7 * V_69 ;
struct V_29 V_23 = F_12 ( V_54 , strlen ( V_54 ) ) ;
V_68 = F_32 ( V_61 , NULL , V_70 , V_71 , NULL ) ;
if ( F_33 ( V_68 ) )
return F_34 ( V_68 ) ;
V_68 -> V_72 = V_73 ;
V_68 -> V_74 = V_75 ;
V_68 -> V_76 = V_77 ;
V_68 -> V_16 = V_66 ;
V_68 -> V_78 = V_63 ? V_63 : & V_79 ;
V_68 -> V_80 = 1 ;
V_69 = F_35 ( V_68 ) ;
if ( ! V_69 )
goto V_81;
V_69 -> V_55 = 1 ;
V_69 -> V_49 = V_82 | V_83 | V_84 ;
V_69 -> V_85 = V_69 -> V_86 = V_69 -> V_87 = V_88 ;
V_1 = F_36 ( V_68 , & V_23 ) ;
if ( ! V_1 ) {
F_37 ( V_69 ) ;
goto V_81;
}
F_38 ( V_1 , V_69 ) ;
V_68 -> V_89 = V_1 ;
V_68 -> V_26 = V_65 ;
V_68 -> V_90 |= V_91 ;
return F_39 ( V_68 -> V_89 ) ;
V_81:
F_40 ( V_68 ) ;
return F_8 ( - V_33 ) ;
}
int F_41 ( struct V_7 * V_7 , struct V_28 * V_28 )
{
if ( V_7 -> V_92 )
V_28 -> V_31 = V_7 -> V_92 ;
return 0 ;
}
int F_42 ( struct V_1 * V_93 , struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_93 -> V_2 ;
V_7 -> V_87 = V_21 -> V_87 = V_21 -> V_86 = V_88 ;
F_43 ( V_7 ) ;
F_44 ( V_7 ) ;
F_39 ( V_1 ) ;
F_38 ( V_1 , V_7 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_1 )
{
struct V_1 * V_94 ;
int V_95 = 0 ;
F_19 ( & V_1 -> V_43 ) ;
F_46 (child, &dentry->d_subdirs, d_u.d_child) {
F_22 ( & V_94 -> V_43 , V_48 ) ;
if ( F_1 ( V_94 ) ) {
F_23 ( & V_94 -> V_43 ) ;
goto V_96;
}
F_23 ( & V_94 -> V_43 ) ;
}
V_95 = 1 ;
V_96:
F_23 ( & V_1 -> V_43 ) ;
return V_95 ;
}
int F_47 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
V_7 -> V_87 = V_21 -> V_87 = V_21 -> V_86 = V_88 ;
F_48 ( V_7 ) ;
F_15 ( V_1 ) ;
return 0 ;
}
int F_49 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
if ( ! F_45 ( V_1 ) )
return - V_97 ;
F_48 ( V_1 -> V_2 ) ;
F_47 ( V_21 , V_1 ) ;
F_48 ( V_21 ) ;
return 0 ;
}
int F_50 ( struct V_7 * V_98 , struct V_1 * V_93 ,
struct V_7 * V_99 , struct V_1 * V_100 )
{
struct V_7 * V_7 = V_93 -> V_2 ;
int V_101 = F_51 ( V_93 -> V_2 -> V_49 ) ;
if ( ! F_45 ( V_100 ) )
return - V_97 ;
if ( V_100 -> V_2 ) {
F_47 ( V_99 , V_100 ) ;
if ( V_101 ) {
F_48 ( V_100 -> V_2 ) ;
F_48 ( V_98 ) ;
}
} else if ( V_101 ) {
F_48 ( V_98 ) ;
F_43 ( V_99 ) ;
}
V_98 -> V_87 = V_98 -> V_86 = V_99 -> V_87 =
V_99 -> V_86 = V_7 -> V_87 = V_88 ;
return 0 ;
}
int F_52 ( struct V_1 * V_1 , struct V_102 * V_102 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
int error ;
error = F_53 ( V_7 , V_102 ) ;
if ( error )
return error ;
if ( V_102 -> V_103 & V_104 )
F_54 ( V_7 , V_102 -> V_105 ) ;
F_55 ( V_7 , V_102 ) ;
F_56 ( V_7 ) ;
return 0 ;
}
int F_57 ( struct V_28 * V_28 , struct V_106 * V_106 )
{
F_58 ( V_106 ) ;
F_59 ( V_106 ) ;
F_60 ( V_106 ) ;
F_61 ( V_106 ) ;
return 0 ;
}
int F_62 ( struct V_28 * V_28 , struct V_107 * V_108 ,
T_1 V_53 , unsigned V_24 , unsigned V_22 ,
struct V_106 * * V_109 , void * * V_110 )
{
struct V_106 * V_106 ;
T_5 V_111 ;
V_111 = V_53 >> V_11 ;
V_106 = F_63 ( V_108 , V_111 , V_22 ) ;
if ( ! V_106 )
return - V_33 ;
* V_109 = V_106 ;
if ( ! F_64 ( V_106 ) && ( V_24 != V_18 ) ) {
unsigned V_112 = V_53 & ( V_18 - 1 ) ;
F_65 ( V_106 , 0 , V_112 , V_112 + V_24 , V_18 ) ;
}
return 0 ;
}
int F_66 ( struct V_28 * V_28 , struct V_107 * V_108 ,
T_1 V_53 , unsigned V_24 , unsigned V_113 ,
struct V_106 * V_106 , void * V_110 )
{
struct V_7 * V_7 = V_106 -> V_108 -> V_114 ;
T_1 V_115 = V_53 + V_113 ;
if ( V_113 < V_24 ) {
unsigned V_112 = V_53 & ( V_18 - 1 ) ;
F_67 ( V_106 , V_112 + V_113 , V_24 - V_113 ) ;
}
if ( ! F_64 ( V_106 ) )
F_60 ( V_106 ) ;
if ( V_115 > V_7 -> V_116 )
F_68 ( V_7 , V_115 ) ;
F_69 ( V_106 ) ;
F_61 ( V_106 ) ;
F_70 ( V_106 ) ;
return V_113 ;
}
int F_71 ( struct V_67 * V_68 , unsigned long V_66 ,
struct V_117 * V_118 )
{
struct V_7 * V_7 ;
struct V_1 * V_69 ;
struct V_1 * V_1 ;
int V_119 ;
V_68 -> V_74 = V_18 ;
V_68 -> V_76 = V_11 ;
V_68 -> V_16 = V_66 ;
V_68 -> V_78 = & V_79 ;
V_68 -> V_80 = 1 ;
V_7 = F_35 ( V_68 ) ;
if ( ! V_7 )
return - V_33 ;
V_7 -> V_55 = 1 ;
V_7 -> V_49 = V_82 | 0755 ;
V_7 -> V_85 = V_7 -> V_86 = V_7 -> V_87 = V_88 ;
V_7 -> V_120 = & V_121 ;
V_7 -> V_122 = & V_123 ;
F_72 ( V_7 , 2 ) ;
V_69 = F_73 ( V_7 ) ;
if ( ! V_69 )
return - V_33 ;
for ( V_119 = 0 ; ! V_118 -> V_54 || V_118 -> V_54 [ 0 ] ; V_119 ++ , V_118 ++ ) {
if ( ! V_118 -> V_54 )
continue;
if ( F_74 ( V_119 == 1 ) )
F_75 ( V_124 L_2
L_3 , V_125 ,
V_68 -> V_126 -> V_54 ) ;
V_1 = F_76 ( V_69 , V_118 -> V_54 ) ;
if ( ! V_1 )
goto V_96;
V_7 = F_35 ( V_68 ) ;
if ( ! V_7 ) {
F_15 ( V_1 ) ;
goto V_96;
}
V_7 -> V_49 = V_127 | V_118 -> V_128 ;
V_7 -> V_85 = V_7 -> V_86 = V_7 -> V_87 = V_88 ;
V_7 -> V_122 = V_118 -> V_63 ;
V_7 -> V_55 = V_119 ;
F_10 ( V_1 , V_7 ) ;
}
V_68 -> V_89 = V_69 ;
return 0 ;
V_96:
F_77 ( V_69 ) ;
F_78 ( V_69 ) ;
F_15 ( V_69 ) ;
return - V_33 ;
}
int F_79 ( struct V_60 * type , struct V_3 * * V_129 , int * V_130 )
{
struct V_3 * V_4 = NULL ;
F_19 ( & V_131 ) ;
if ( F_74 ( ! * V_129 ) ) {
F_23 ( & V_131 ) ;
V_4 = F_80 ( type , V_132 , type -> V_54 , NULL ) ;
if ( F_33 ( V_4 ) )
return F_81 ( V_4 ) ;
F_19 ( & V_131 ) ;
if ( ! * V_129 )
* V_129 = V_4 ;
}
F_82 ( * V_129 ) ;
++ * V_130 ;
F_23 ( & V_131 ) ;
F_83 ( V_4 ) ;
return 0 ;
}
void F_84 ( struct V_3 * * V_129 , int * V_130 )
{
struct V_3 * V_4 ;
F_19 ( & V_131 ) ;
V_4 = * V_129 ;
if ( ! -- * V_130 )
* V_129 = NULL ;
F_23 ( & V_131 ) ;
F_83 ( V_4 ) ;
}
T_2 F_85 ( void T_3 * V_133 , T_4 V_130 , T_1 * V_58 ,
const void * V_112 , T_4 V_134 )
{
T_1 V_53 = * V_58 ;
T_4 V_95 ;
if ( V_53 < 0 )
return - V_38 ;
if ( V_53 >= V_134 || ! V_130 )
return 0 ;
if ( V_130 > V_134 - V_53 )
V_130 = V_134 - V_53 ;
V_95 = F_86 ( V_133 , V_112 + V_53 , V_130 ) ;
if ( V_95 == V_130 )
return - V_135 ;
V_130 -= V_95 ;
* V_58 = V_53 + V_130 ;
return V_130 ;
}
T_2 F_87 ( void * V_133 , T_4 V_134 , T_1 * V_58 ,
const void T_3 * V_112 , T_4 V_130 )
{
T_1 V_53 = * V_58 ;
T_4 V_136 ;
if ( V_53 < 0 )
return - V_38 ;
if ( V_53 >= V_134 || ! V_130 )
return 0 ;
if ( V_130 > V_134 - V_53 )
V_130 = V_134 - V_53 ;
V_136 = F_88 ( V_133 + V_53 , V_112 , V_130 ) ;
if ( V_136 == V_130 )
return - V_135 ;
V_130 -= V_136 ;
* V_58 = V_53 + V_130 ;
return V_130 ;
}
T_2 F_89 ( void * V_133 , T_4 V_130 , T_1 * V_58 ,
const void * V_112 , T_4 V_134 )
{
T_1 V_53 = * V_58 ;
if ( V_53 < 0 )
return - V_38 ;
if ( V_53 >= V_134 )
return 0 ;
if ( V_130 > V_134 - V_53 )
V_130 = V_134 - V_53 ;
memcpy ( V_133 , V_112 + V_53 , V_130 ) ;
* V_58 = V_53 + V_130 ;
return V_130 ;
}
void F_90 ( struct V_28 * V_28 , T_4 V_42 )
{
struct V_137 * V_138 = V_28 -> V_31 ;
F_91 ( V_42 > V_139 ) ;
F_92 () ;
V_138 -> V_140 = V_42 ;
}
char * F_93 ( struct V_28 * V_28 , const char T_3 * V_13 , T_4 V_140 )
{
struct V_137 * V_138 ;
static F_94 ( V_141 ) ;
if ( V_140 > V_139 - 1 )
return F_8 ( - V_142 ) ;
V_138 = (struct V_137 * ) F_95 ( V_143 ) ;
if ( ! V_138 )
return F_8 ( - V_33 ) ;
F_19 ( & V_141 ) ;
if ( V_28 -> V_31 ) {
F_23 ( & V_141 ) ;
F_96 ( ( unsigned long ) V_138 ) ;
return F_8 ( - V_144 ) ;
}
V_28 -> V_31 = V_138 ;
F_23 ( & V_141 ) ;
if ( F_88 ( V_138 -> V_145 , V_13 , V_140 ) )
return F_8 ( - V_135 ) ;
return V_138 -> V_145 ;
}
T_2 F_97 ( struct V_28 * V_28 , char T_3 * V_13 , T_4 V_140 , T_1 * V_53 )
{
struct V_137 * V_138 = V_28 -> V_31 ;
if ( ! V_138 )
return 0 ;
return F_85 ( V_13 , V_140 , V_53 , V_138 -> V_145 , V_138 -> V_140 ) ;
}
int F_98 ( struct V_7 * V_7 , struct V_28 * V_28 )
{
F_96 ( ( unsigned long ) V_28 -> V_31 ) ;
return 0 ;
}
int F_99 ( struct V_7 * V_7 , struct V_28 * V_28 ,
int (* F_100)( void * , T_6 * ) , int (* F_101)( void * , T_6 ) ,
const char * V_146 )
{
struct V_147 * V_148 ;
V_148 = F_102 ( sizeof( * V_148 ) , V_143 ) ;
if ( ! V_148 )
return - V_33 ;
V_148 -> F_100 = F_100 ;
V_148 -> F_101 = F_101 ;
V_148 -> V_145 = V_7 -> V_92 ;
V_148 -> V_146 = V_146 ;
F_103 ( & V_148 -> V_149 ) ;
V_28 -> V_31 = V_148 ;
return F_104 ( V_7 , V_28 ) ;
}
int F_105 ( struct V_7 * V_7 , struct V_28 * V_28 )
{
F_106 ( V_28 -> V_31 ) ;
return 0 ;
}
T_2 F_107 ( struct V_28 * V_28 , char T_3 * V_13 ,
T_4 V_24 , T_1 * V_58 )
{
struct V_147 * V_148 ;
T_4 V_140 ;
T_2 V_95 ;
V_148 = V_28 -> V_31 ;
if ( ! V_148 -> F_100 )
return - V_150 ;
V_95 = F_108 ( & V_148 -> V_149 ) ;
if ( V_95 )
return V_95 ;
if ( * V_58 ) {
V_140 = strlen ( V_148 -> V_151 ) ;
} else {
T_6 V_152 ;
V_95 = V_148 -> F_100 ( V_148 -> V_145 , & V_152 ) ;
if ( V_95 )
goto V_96;
V_140 = F_109 ( V_148 -> V_151 , sizeof( V_148 -> V_151 ) ,
V_148 -> V_146 , ( unsigned long long ) V_152 ) ;
}
V_95 = F_85 ( V_13 , V_24 , V_58 , V_148 -> V_151 , V_140 ) ;
V_96:
F_18 ( & V_148 -> V_149 ) ;
return V_95 ;
}
T_2 F_110 ( struct V_28 * V_28 , const char T_3 * V_13 ,
T_4 V_24 , T_1 * V_58 )
{
struct V_147 * V_148 ;
T_6 V_152 ;
T_4 V_140 ;
T_2 V_95 ;
V_148 = V_28 -> V_31 ;
if ( ! V_148 -> F_101 )
return - V_150 ;
V_95 = F_108 ( & V_148 -> V_149 ) ;
if ( V_95 )
return V_95 ;
V_95 = - V_135 ;
V_140 = F_111 ( sizeof( V_148 -> V_153 ) - 1 , V_24 ) ;
if ( F_88 ( V_148 -> V_153 , V_13 , V_140 ) )
goto V_96;
V_148 -> V_153 [ V_140 ] = '\0' ;
V_152 = F_112 ( V_148 -> V_153 , NULL , 0 ) ;
V_95 = V_148 -> F_101 ( V_148 -> V_145 , V_152 ) ;
if ( V_95 == 0 )
V_95 = V_24 ;
V_96:
F_18 ( & V_148 -> V_149 ) ;
return V_95 ;
}
int F_113 ( struct V_28 * V_28 , T_1 V_154 , T_1 V_155 ,
int V_156 )
{
struct V_7 * V_7 = V_28 -> V_157 -> V_114 ;
int V_158 ;
int V_95 ;
V_158 = F_114 ( V_7 -> V_9 , V_154 , V_155 ) ;
if ( V_158 )
return V_158 ;
F_17 ( & V_7 -> V_36 ) ;
V_95 = F_115 ( V_7 -> V_9 ) ;
if ( ! ( V_7 -> V_159 & V_160 ) )
goto V_96;
if ( V_156 && ! ( V_7 -> V_159 & V_161 ) )
goto V_96;
V_158 = F_116 ( V_7 , 1 ) ;
if ( V_95 == 0 )
V_95 = V_158 ;
V_96:
F_18 ( & V_7 -> V_36 ) ;
return V_95 ;
}
int F_117 ( struct V_28 * V_28 , T_1 V_154 , T_1 V_155 ,
int V_156 )
{
struct V_7 * V_7 = V_28 -> V_157 -> V_114 ;
int V_158 ;
V_158 = F_113 ( V_28 , V_154 , V_155 , V_156 ) ;
if ( V_158 )
return V_158 ;
return F_118 ( V_7 -> V_162 -> V_163 , V_143 , NULL ) ;
}
int F_119 ( unsigned V_164 , T_6 V_165 )
{
T_6 V_166 = V_165 - 1 ;
T_6 V_167 =
V_166 >> ( V_11 - V_164 ) ;
if ( F_74 ( V_165 == 0 ) )
return 0 ;
if ( ( V_164 < 9 ) || ( V_164 > V_11 ) )
return - V_38 ;
if ( ( V_166 > ( V_168 ) ( ~ 0ULL ) >> ( V_164 - 9 ) ) ||
( V_167 > ( T_5 ) ( ~ 0ULL ) ) ) {
return - V_142 ;
}
return 0 ;
}
int F_120 ( struct V_28 * V_28 , T_1 V_154 , T_1 V_155 , int V_156 )
{
return 0 ;
}
void F_121 ( struct V_1 * V_1 , struct V_169 * V_170 ,
void * V_171 )
{
char * V_68 = F_122 ( V_170 ) ;
if ( ! F_33 ( V_68 ) )
F_106 ( V_68 ) ;
}
static int F_123 ( struct V_106 * V_106 )
{
return 0 ;
}
struct V_7 * F_124 ( struct V_67 * V_68 )
{
static const struct V_172 V_173 = {
. F_69 = F_123 ,
} ;
struct V_7 * V_7 = F_125 ( V_68 ) ;
if ( ! V_7 )
return F_8 ( - V_33 ) ;
V_7 -> V_55 = F_126 () ;
V_7 -> V_9 -> V_174 = & V_173 ;
V_7 -> V_159 = V_160 ;
V_7 -> V_49 = V_83 | V_84 ;
V_7 -> V_175 = F_127 () ;
V_7 -> V_176 = F_128 () ;
V_7 -> V_177 |= V_178 ;
V_7 -> V_85 = V_7 -> V_86 = V_7 -> V_87 = V_88 ;
return V_7 ;
}
