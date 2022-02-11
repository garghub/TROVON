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
F_20 ( & V_41 -> V_44 ) ;
V_40 = V_1 -> V_45 . V_46 ;
while ( V_42 && V_40 != & V_1 -> V_45 ) {
struct V_1 * V_46 ;
V_46 = F_21 ( V_40 , struct V_1 , V_44 ) ;
F_22 ( & V_46 -> V_43 , V_47 ) ;
if ( F_1 ( V_46 ) )
V_42 -- ;
F_23 ( & V_46 -> V_43 ) ;
V_40 = V_40 -> V_46 ;
}
F_24 ( & V_41 -> V_44 , V_40 ) ;
F_23 ( & V_1 -> V_43 ) ;
}
}
F_18 ( & V_1 -> V_2 -> V_36 ) ;
return V_34 ;
}
static inline unsigned char F_25 ( struct V_7 * V_7 )
{
return ( V_7 -> V_48 >> 12 ) & 15 ;
}
int F_26 ( struct V_28 * V_28 , struct V_49 * V_50 )
{
struct V_1 * V_1 = V_28 -> V_32 . V_1 ;
struct V_1 * V_41 = V_28 -> V_31 ;
struct V_39 * V_40 , * V_51 = & V_41 -> V_44 ;
if ( ! F_27 ( V_28 , V_50 ) )
return 0 ;
F_19 ( & V_1 -> V_43 ) ;
if ( V_50 -> V_52 == 2 )
F_28 ( V_51 , & V_1 -> V_45 ) ;
for ( V_40 = V_51 -> V_46 ; V_40 != & V_1 -> V_45 ; V_40 = V_40 -> V_46 ) {
struct V_1 * V_46 = F_21 ( V_40 , struct V_1 , V_44 ) ;
F_22 ( & V_46 -> V_43 , V_47 ) ;
if ( ! F_1 ( V_46 ) ) {
F_23 ( & V_46 -> V_43 ) ;
continue;
}
F_23 ( & V_46 -> V_43 ) ;
F_23 ( & V_1 -> V_43 ) ;
if ( ! F_29 ( V_50 , V_46 -> V_23 . V_53 , V_46 -> V_23 . V_24 ,
V_46 -> V_2 -> V_54 , F_25 ( V_46 -> V_2 ) ) )
return 0 ;
F_19 ( & V_1 -> V_43 ) ;
F_22 ( & V_46 -> V_43 , V_47 ) ;
F_28 ( V_51 , V_40 ) ;
F_23 ( & V_46 -> V_43 ) ;
V_40 = V_51 ;
V_50 -> V_52 ++ ;
}
F_23 ( & V_1 -> V_43 ) ;
return 0 ;
}
T_2 F_30 ( struct V_28 * V_55 , char T_3 * V_13 , T_4 V_56 , T_1 * V_57 )
{
return - V_58 ;
}
struct V_1 * F_31 ( struct V_59 * V_60 , char * V_53 ,
const struct V_61 * V_62 ,
const struct V_63 * V_64 , unsigned long V_65 )
{
struct V_66 * V_67 ;
struct V_1 * V_1 ;
struct V_7 * V_68 ;
struct V_29 V_23 = F_12 ( V_53 , strlen ( V_53 ) ) ;
V_67 = F_32 ( V_60 , NULL , V_69 , V_70 , NULL ) ;
if ( F_33 ( V_67 ) )
return F_34 ( V_67 ) ;
V_67 -> V_71 = V_72 ;
V_67 -> V_73 = V_74 ;
V_67 -> V_75 = V_76 ;
V_67 -> V_16 = V_65 ;
V_67 -> V_77 = V_62 ? V_62 : & V_78 ;
V_67 -> V_79 = 1 ;
V_68 = F_35 ( V_67 ) ;
if ( ! V_68 )
goto V_80;
V_68 -> V_54 = 1 ;
V_68 -> V_48 = V_81 | V_82 | V_83 ;
V_68 -> V_84 = V_68 -> V_85 = V_68 -> V_86 = V_87 ;
V_1 = F_36 ( V_67 , & V_23 ) ;
if ( ! V_1 ) {
F_37 ( V_68 ) ;
goto V_80;
}
F_38 ( V_1 , V_68 ) ;
V_67 -> V_88 = V_1 ;
V_67 -> V_26 = V_64 ;
V_67 -> V_89 |= V_90 ;
return F_39 ( V_67 -> V_88 ) ;
V_80:
F_40 ( V_67 ) ;
return F_8 ( - V_33 ) ;
}
int F_41 ( struct V_7 * V_7 , struct V_28 * V_28 )
{
if ( V_7 -> V_91 )
V_28 -> V_31 = V_7 -> V_91 ;
return 0 ;
}
int F_42 ( struct V_1 * V_92 , struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_92 -> V_2 ;
V_7 -> V_86 = V_21 -> V_86 = V_21 -> V_85 = V_87 ;
F_43 ( V_7 ) ;
F_44 ( V_7 ) ;
F_39 ( V_1 ) ;
F_38 ( V_1 , V_7 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_1 )
{
struct V_1 * V_93 ;
int V_94 = 0 ;
F_19 ( & V_1 -> V_43 ) ;
F_46 (child, &dentry->d_subdirs, d_child) {
F_22 ( & V_93 -> V_43 , V_47 ) ;
if ( F_1 ( V_93 ) ) {
F_23 ( & V_93 -> V_43 ) ;
goto V_95;
}
F_23 ( & V_93 -> V_43 ) ;
}
V_94 = 1 ;
V_95:
F_23 ( & V_1 -> V_43 ) ;
return V_94 ;
}
int F_47 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
V_7 -> V_86 = V_21 -> V_86 = V_21 -> V_85 = V_87 ;
F_48 ( V_7 ) ;
F_15 ( V_1 ) ;
return 0 ;
}
int F_49 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
if ( ! F_45 ( V_1 ) )
return - V_96 ;
F_48 ( V_1 -> V_2 ) ;
F_47 ( V_21 , V_1 ) ;
F_48 ( V_21 ) ;
return 0 ;
}
int F_50 ( struct V_7 * V_97 , struct V_1 * V_92 ,
struct V_7 * V_98 , struct V_1 * V_99 )
{
struct V_7 * V_7 = V_92 -> V_2 ;
int V_100 = F_51 ( V_92 -> V_2 -> V_48 ) ;
if ( ! F_45 ( V_99 ) )
return - V_96 ;
if ( V_99 -> V_2 ) {
F_47 ( V_98 , V_99 ) ;
if ( V_100 ) {
F_48 ( V_99 -> V_2 ) ;
F_48 ( V_97 ) ;
}
} else if ( V_100 ) {
F_48 ( V_97 ) ;
F_43 ( V_98 ) ;
}
V_97 -> V_86 = V_97 -> V_85 = V_98 -> V_86 =
V_98 -> V_85 = V_7 -> V_86 = V_87 ;
return 0 ;
}
int F_52 ( struct V_1 * V_1 , struct V_101 * V_101 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
int error ;
error = F_53 ( V_7 , V_101 ) ;
if ( error )
return error ;
if ( V_101 -> V_102 & V_103 )
F_54 ( V_7 , V_101 -> V_104 ) ;
F_55 ( V_7 , V_101 ) ;
F_56 ( V_7 ) ;
return 0 ;
}
int F_57 ( struct V_28 * V_28 , struct V_105 * V_105 )
{
F_58 ( V_105 ) ;
F_59 ( V_105 ) ;
F_60 ( V_105 ) ;
F_61 ( V_105 ) ;
return 0 ;
}
int F_62 ( struct V_28 * V_28 , struct V_106 * V_107 ,
T_1 V_52 , unsigned V_24 , unsigned V_22 ,
struct V_105 * * V_108 , void * * V_109 )
{
struct V_105 * V_105 ;
T_5 V_110 ;
V_110 = V_52 >> V_11 ;
V_105 = F_63 ( V_107 , V_110 , V_22 ) ;
if ( ! V_105 )
return - V_33 ;
* V_108 = V_105 ;
if ( ! F_64 ( V_105 ) && ( V_24 != V_18 ) ) {
unsigned V_111 = V_52 & ( V_18 - 1 ) ;
F_65 ( V_105 , 0 , V_111 , V_111 + V_24 , V_18 ) ;
}
return 0 ;
}
int F_66 ( struct V_28 * V_28 , struct V_106 * V_107 ,
T_1 V_52 , unsigned V_24 , unsigned V_112 ,
struct V_105 * V_105 , void * V_109 )
{
struct V_7 * V_7 = V_105 -> V_107 -> V_113 ;
T_1 V_114 = V_52 + V_112 ;
if ( V_112 < V_24 ) {
unsigned V_111 = V_52 & ( V_18 - 1 ) ;
F_67 ( V_105 , V_111 + V_112 , V_24 - V_112 ) ;
}
if ( ! F_64 ( V_105 ) )
F_60 ( V_105 ) ;
if ( V_114 > V_7 -> V_115 )
F_68 ( V_7 , V_114 ) ;
F_69 ( V_105 ) ;
F_61 ( V_105 ) ;
F_70 ( V_105 ) ;
return V_112 ;
}
int F_71 ( struct V_66 * V_67 , unsigned long V_65 ,
struct V_116 * V_117 )
{
struct V_7 * V_7 ;
struct V_1 * V_68 ;
struct V_1 * V_1 ;
int V_118 ;
V_67 -> V_73 = V_18 ;
V_67 -> V_75 = V_11 ;
V_67 -> V_16 = V_65 ;
V_67 -> V_77 = & V_78 ;
V_67 -> V_79 = 1 ;
V_7 = F_35 ( V_67 ) ;
if ( ! V_7 )
return - V_33 ;
V_7 -> V_54 = 1 ;
V_7 -> V_48 = V_81 | 0755 ;
V_7 -> V_84 = V_7 -> V_85 = V_7 -> V_86 = V_87 ;
V_7 -> V_119 = & V_120 ;
V_7 -> V_121 = & V_122 ;
F_72 ( V_7 , 2 ) ;
V_68 = F_73 ( V_7 ) ;
if ( ! V_68 )
return - V_33 ;
for ( V_118 = 0 ; ! V_117 -> V_53 || V_117 -> V_53 [ 0 ] ; V_118 ++ , V_117 ++ ) {
if ( ! V_117 -> V_53 )
continue;
if ( F_74 ( V_118 == 1 ) )
F_75 ( V_123 L_2
L_3 , V_124 ,
V_67 -> V_125 -> V_53 ) ;
V_1 = F_76 ( V_68 , V_117 -> V_53 ) ;
if ( ! V_1 )
goto V_95;
V_7 = F_35 ( V_67 ) ;
if ( ! V_7 ) {
F_15 ( V_1 ) ;
goto V_95;
}
V_7 -> V_48 = V_126 | V_117 -> V_127 ;
V_7 -> V_84 = V_7 -> V_85 = V_7 -> V_86 = V_87 ;
V_7 -> V_121 = V_117 -> V_62 ;
V_7 -> V_54 = V_118 ;
F_10 ( V_1 , V_7 ) ;
}
V_67 -> V_88 = V_68 ;
return 0 ;
V_95:
F_77 ( V_68 ) ;
F_78 ( V_68 ) ;
F_15 ( V_68 ) ;
return - V_33 ;
}
int F_79 ( struct V_59 * type , struct V_3 * * V_128 , int * V_129 )
{
struct V_3 * V_4 = NULL ;
F_19 ( & V_130 ) ;
if ( F_74 ( ! * V_128 ) ) {
F_23 ( & V_130 ) ;
V_4 = F_80 ( type , V_131 , type -> V_53 , NULL ) ;
if ( F_33 ( V_4 ) )
return F_81 ( V_4 ) ;
F_19 ( & V_130 ) ;
if ( ! * V_128 )
* V_128 = V_4 ;
}
F_82 ( * V_128 ) ;
++ * V_129 ;
F_23 ( & V_130 ) ;
F_83 ( V_4 ) ;
return 0 ;
}
void F_84 ( struct V_3 * * V_128 , int * V_129 )
{
struct V_3 * V_4 ;
F_19 ( & V_130 ) ;
V_4 = * V_128 ;
if ( ! -- * V_129 )
* V_128 = NULL ;
F_23 ( & V_130 ) ;
F_83 ( V_4 ) ;
}
T_2 F_85 ( void T_3 * V_132 , T_4 V_129 , T_1 * V_57 ,
const void * V_111 , T_4 V_133 )
{
T_1 V_52 = * V_57 ;
T_4 V_94 ;
if ( V_52 < 0 )
return - V_38 ;
if ( V_52 >= V_133 || ! V_129 )
return 0 ;
if ( V_129 > V_133 - V_52 )
V_129 = V_133 - V_52 ;
V_94 = F_86 ( V_132 , V_111 + V_52 , V_129 ) ;
if ( V_94 == V_129 )
return - V_134 ;
V_129 -= V_94 ;
* V_57 = V_52 + V_129 ;
return V_129 ;
}
T_2 F_87 ( void * V_132 , T_4 V_133 , T_1 * V_57 ,
const void T_3 * V_111 , T_4 V_129 )
{
T_1 V_52 = * V_57 ;
T_4 V_135 ;
if ( V_52 < 0 )
return - V_38 ;
if ( V_52 >= V_133 || ! V_129 )
return 0 ;
if ( V_129 > V_133 - V_52 )
V_129 = V_133 - V_52 ;
V_135 = F_88 ( V_132 + V_52 , V_111 , V_129 ) ;
if ( V_135 == V_129 )
return - V_134 ;
V_129 -= V_135 ;
* V_57 = V_52 + V_129 ;
return V_129 ;
}
T_2 F_89 ( void * V_132 , T_4 V_129 , T_1 * V_57 ,
const void * V_111 , T_4 V_133 )
{
T_1 V_52 = * V_57 ;
if ( V_52 < 0 )
return - V_38 ;
if ( V_52 >= V_133 )
return 0 ;
if ( V_129 > V_133 - V_52 )
V_129 = V_133 - V_52 ;
memcpy ( V_132 , V_111 + V_52 , V_129 ) ;
* V_57 = V_52 + V_129 ;
return V_129 ;
}
void F_90 ( struct V_28 * V_28 , T_4 V_42 )
{
struct V_136 * V_137 = V_28 -> V_31 ;
F_91 ( V_42 > V_138 ) ;
F_92 () ;
V_137 -> V_139 = V_42 ;
}
char * F_93 ( struct V_28 * V_28 , const char T_3 * V_13 , T_4 V_139 )
{
struct V_136 * V_137 ;
static F_94 ( V_140 ) ;
if ( V_139 > V_138 - 1 )
return F_8 ( - V_141 ) ;
V_137 = (struct V_136 * ) F_95 ( V_142 ) ;
if ( ! V_137 )
return F_8 ( - V_33 ) ;
F_19 ( & V_140 ) ;
if ( V_28 -> V_31 ) {
F_23 ( & V_140 ) ;
F_96 ( ( unsigned long ) V_137 ) ;
return F_8 ( - V_143 ) ;
}
V_28 -> V_31 = V_137 ;
F_23 ( & V_140 ) ;
if ( F_88 ( V_137 -> V_144 , V_13 , V_139 ) )
return F_8 ( - V_134 ) ;
return V_137 -> V_144 ;
}
T_2 F_97 ( struct V_28 * V_28 , char T_3 * V_13 , T_4 V_139 , T_1 * V_52 )
{
struct V_136 * V_137 = V_28 -> V_31 ;
if ( ! V_137 )
return 0 ;
return F_85 ( V_13 , V_139 , V_52 , V_137 -> V_144 , V_137 -> V_139 ) ;
}
int F_98 ( struct V_7 * V_7 , struct V_28 * V_28 )
{
F_96 ( ( unsigned long ) V_28 -> V_31 ) ;
return 0 ;
}
int F_99 ( struct V_7 * V_7 , struct V_28 * V_28 ,
int (* F_100)( void * , T_6 * ) , int (* F_101)( void * , T_6 ) ,
const char * V_145 )
{
struct V_146 * V_147 ;
V_147 = F_102 ( sizeof( * V_147 ) , V_142 ) ;
if ( ! V_147 )
return - V_33 ;
V_147 -> F_100 = F_100 ;
V_147 -> F_101 = F_101 ;
V_147 -> V_144 = V_7 -> V_91 ;
V_147 -> V_145 = V_145 ;
F_103 ( & V_147 -> V_148 ) ;
V_28 -> V_31 = V_147 ;
return F_104 ( V_7 , V_28 ) ;
}
int F_105 ( struct V_7 * V_7 , struct V_28 * V_28 )
{
F_106 ( V_28 -> V_31 ) ;
return 0 ;
}
T_2 F_107 ( struct V_28 * V_28 , char T_3 * V_13 ,
T_4 V_24 , T_1 * V_57 )
{
struct V_146 * V_147 ;
T_4 V_139 ;
T_2 V_94 ;
V_147 = V_28 -> V_31 ;
if ( ! V_147 -> F_100 )
return - V_149 ;
V_94 = F_108 ( & V_147 -> V_148 ) ;
if ( V_94 )
return V_94 ;
if ( * V_57 ) {
V_139 = strlen ( V_147 -> V_150 ) ;
} else {
T_6 V_151 ;
V_94 = V_147 -> F_100 ( V_147 -> V_144 , & V_151 ) ;
if ( V_94 )
goto V_95;
V_139 = F_109 ( V_147 -> V_150 , sizeof( V_147 -> V_150 ) ,
V_147 -> V_145 , ( unsigned long long ) V_151 ) ;
}
V_94 = F_85 ( V_13 , V_24 , V_57 , V_147 -> V_150 , V_139 ) ;
V_95:
F_18 ( & V_147 -> V_148 ) ;
return V_94 ;
}
T_2 F_110 ( struct V_28 * V_28 , const char T_3 * V_13 ,
T_4 V_24 , T_1 * V_57 )
{
struct V_146 * V_147 ;
T_6 V_151 ;
T_4 V_139 ;
T_2 V_94 ;
V_147 = V_28 -> V_31 ;
if ( ! V_147 -> F_101 )
return - V_149 ;
V_94 = F_108 ( & V_147 -> V_148 ) ;
if ( V_94 )
return V_94 ;
V_94 = - V_134 ;
V_139 = F_111 ( sizeof( V_147 -> V_152 ) - 1 , V_24 ) ;
if ( F_88 ( V_147 -> V_152 , V_13 , V_139 ) )
goto V_95;
V_147 -> V_152 [ V_139 ] = '\0' ;
V_151 = F_112 ( V_147 -> V_152 , NULL , 0 ) ;
V_94 = V_147 -> F_101 ( V_147 -> V_144 , V_151 ) ;
if ( V_94 == 0 )
V_94 = V_24 ;
V_95:
F_18 ( & V_147 -> V_148 ) ;
return V_94 ;
}
int F_113 ( struct V_28 * V_28 , T_1 V_153 , T_1 V_154 ,
int V_155 )
{
struct V_7 * V_7 = V_28 -> V_156 -> V_113 ;
int V_157 ;
int V_94 ;
V_157 = F_114 ( V_7 -> V_9 , V_153 , V_154 ) ;
if ( V_157 )
return V_157 ;
F_17 ( & V_7 -> V_36 ) ;
V_94 = F_115 ( V_7 -> V_9 ) ;
if ( ! ( V_7 -> V_158 & V_159 ) )
goto V_95;
if ( V_155 && ! ( V_7 -> V_158 & V_160 ) )
goto V_95;
V_157 = F_116 ( V_7 , 1 ) ;
if ( V_94 == 0 )
V_94 = V_157 ;
V_95:
F_18 ( & V_7 -> V_36 ) ;
return V_94 ;
}
int F_117 ( struct V_28 * V_28 , T_1 V_153 , T_1 V_154 ,
int V_155 )
{
struct V_7 * V_7 = V_28 -> V_156 -> V_113 ;
int V_157 ;
V_157 = F_113 ( V_28 , V_153 , V_154 , V_155 ) ;
if ( V_157 )
return V_157 ;
return F_118 ( V_7 -> V_161 -> V_162 , V_142 , NULL ) ;
}
int F_119 ( unsigned V_163 , T_6 V_164 )
{
T_6 V_165 = V_164 - 1 ;
T_6 V_166 =
V_165 >> ( V_11 - V_163 ) ;
if ( F_74 ( V_164 == 0 ) )
return 0 ;
if ( ( V_163 < 9 ) || ( V_163 > V_11 ) )
return - V_38 ;
if ( ( V_165 > ( V_167 ) ( ~ 0ULL ) >> ( V_163 - 9 ) ) ||
( V_166 > ( T_5 ) ( ~ 0ULL ) ) ) {
return - V_141 ;
}
return 0 ;
}
int F_120 ( struct V_28 * V_28 , T_1 V_153 , T_1 V_154 , int V_155 )
{
return 0 ;
}
void F_121 ( struct V_1 * V_1 , struct V_168 * V_169 ,
void * V_170 )
{
char * V_67 = F_122 ( V_169 ) ;
if ( ! F_33 ( V_67 ) )
F_106 ( V_67 ) ;
}
static int F_123 ( struct V_105 * V_105 )
{
return 0 ;
}
struct V_7 * F_124 ( struct V_66 * V_67 )
{
static const struct V_171 V_172 = {
. F_69 = F_123 ,
} ;
struct V_7 * V_7 = F_125 ( V_67 ) ;
if ( ! V_7 )
return F_8 ( - V_33 ) ;
V_7 -> V_54 = F_126 () ;
V_7 -> V_9 -> V_173 = & V_172 ;
V_7 -> V_158 = V_159 ;
V_7 -> V_48 = V_82 | V_83 ;
V_7 -> V_174 = F_127 () ;
V_7 -> V_175 = F_128 () ;
V_7 -> V_176 |= V_177 ;
V_7 -> V_84 = V_7 -> V_85 = V_7 -> V_86 = V_87 ;
return V_7 ;
}
int
F_129 ( struct V_28 * V_55 , long V_178 , struct V_179 * * V_180 ,
void * * V_181 )
{
return - V_38 ;
}
