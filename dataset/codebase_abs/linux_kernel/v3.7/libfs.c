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
static int F_6 ( const struct V_1 * V_1 )
{
return 1 ;
}
struct V_1 * F_7 ( struct V_7 * V_21 , struct V_1 * V_1 , unsigned int V_22 )
{
static const struct V_23 V_24 = {
. V_25 = F_6 ,
} ;
if ( V_1 -> V_26 . V_27 > V_20 )
return F_8 ( - V_28 ) ;
F_9 ( V_1 , & V_24 ) ;
F_10 ( V_1 , NULL ) ;
return NULL ;
}
int F_11 ( struct V_7 * V_7 , struct V_29 * V_29 )
{
static struct V_30 V_31 = F_12 ( L_1 , 1 ) ;
V_29 -> V_32 = F_13 ( V_29 -> V_33 . V_1 , & V_31 ) ;
return V_29 -> V_32 ? 0 : - V_34 ;
}
int F_14 ( struct V_7 * V_7 , struct V_29 * V_29 )
{
F_15 ( V_29 -> V_32 ) ;
return 0 ;
}
T_1 F_16 ( struct V_29 * V_29 , T_1 V_35 , int V_36 )
{
struct V_1 * V_1 = V_29 -> V_33 . V_1 ;
F_17 ( & V_1 -> V_2 -> V_37 ) ;
switch ( V_36 ) {
case 1 :
V_35 += V_29 -> V_38 ;
case 0 :
if ( V_35 >= 0 )
break;
default:
F_18 ( & V_1 -> V_2 -> V_37 ) ;
return - V_39 ;
}
if ( V_35 != V_29 -> V_38 ) {
V_29 -> V_38 = V_35 ;
if ( V_29 -> V_38 >= 2 ) {
struct V_40 * V_41 ;
struct V_1 * V_42 = V_29 -> V_32 ;
T_1 V_43 = V_29 -> V_38 - 2 ;
F_19 ( & V_1 -> V_44 ) ;
F_20 ( & V_42 -> V_45 . V_46 ) ;
V_41 = V_1 -> V_47 . V_48 ;
while ( V_43 && V_41 != & V_1 -> V_47 ) {
struct V_1 * V_48 ;
V_48 = F_21 ( V_41 , struct V_1 , V_45 . V_46 ) ;
F_22 ( & V_48 -> V_44 , V_49 ) ;
if ( F_1 ( V_48 ) )
V_43 -- ;
F_23 ( & V_48 -> V_44 ) ;
V_41 = V_41 -> V_48 ;
}
F_24 ( & V_42 -> V_45 . V_46 , V_41 ) ;
F_23 ( & V_1 -> V_44 ) ;
}
}
F_18 ( & V_1 -> V_2 -> V_37 ) ;
return V_35 ;
}
static inline unsigned char F_25 ( struct V_7 * V_7 )
{
return ( V_7 -> V_50 >> 12 ) & 15 ;
}
int F_26 ( struct V_29 * V_51 , void * V_52 , T_2 V_53 )
{
struct V_1 * V_1 = V_51 -> V_33 . V_1 ;
struct V_1 * V_42 = V_51 -> V_32 ;
struct V_40 * V_41 , * V_54 = & V_42 -> V_45 . V_46 ;
T_3 V_55 ;
int V_56 = V_51 -> V_38 ;
switch ( V_56 ) {
case 0 :
V_55 = V_1 -> V_2 -> V_57 ;
if ( V_53 ( V_52 , L_1 , 1 , V_56 , V_55 , V_58 ) < 0 )
break;
V_51 -> V_38 ++ ;
V_56 ++ ;
case 1 :
V_55 = F_27 ( V_1 ) ;
if ( V_53 ( V_52 , L_2 , 2 , V_56 , V_55 , V_58 ) < 0 )
break;
V_51 -> V_38 ++ ;
V_56 ++ ;
default:
F_19 ( & V_1 -> V_44 ) ;
if ( V_51 -> V_38 == 2 )
F_28 ( V_54 , & V_1 -> V_47 ) ;
for ( V_41 = V_54 -> V_48 ; V_41 != & V_1 -> V_47 ; V_41 = V_41 -> V_48 ) {
struct V_1 * V_48 ;
V_48 = F_21 ( V_41 , struct V_1 , V_45 . V_46 ) ;
F_22 ( & V_48 -> V_44 , V_49 ) ;
if ( ! F_1 ( V_48 ) ) {
F_23 ( & V_48 -> V_44 ) ;
continue;
}
F_23 ( & V_48 -> V_44 ) ;
F_23 ( & V_1 -> V_44 ) ;
if ( V_53 ( V_52 , V_48 -> V_26 . V_59 ,
V_48 -> V_26 . V_27 , V_51 -> V_38 ,
V_48 -> V_2 -> V_57 ,
F_25 ( V_48 -> V_2 ) ) < 0 )
return 0 ;
F_19 ( & V_1 -> V_44 ) ;
F_22 ( & V_48 -> V_44 , V_49 ) ;
F_28 ( V_54 , V_41 ) ;
F_23 ( & V_48 -> V_44 ) ;
V_41 = V_54 ;
V_51 -> V_38 ++ ;
}
F_23 ( & V_1 -> V_44 ) ;
}
return 0 ;
}
T_4 F_29 ( struct V_29 * V_51 , char T_5 * V_13 , T_6 V_60 , T_1 * V_61 )
{
return - V_62 ;
}
struct V_1 * F_30 ( struct V_63 * V_64 , char * V_59 ,
const struct V_65 * V_66 ,
const struct V_23 * V_67 , unsigned long V_68 )
{
struct V_69 * V_70 ;
struct V_1 * V_1 ;
struct V_7 * V_71 ;
struct V_30 V_26 = F_12 ( V_59 , strlen ( V_59 ) ) ;
V_70 = F_31 ( V_64 , NULL , V_72 , V_73 , NULL ) ;
if ( F_32 ( V_70 ) )
return F_33 ( V_70 ) ;
V_70 -> V_74 = V_75 ;
V_70 -> V_76 = V_77 ;
V_70 -> V_78 = V_79 ;
V_70 -> V_16 = V_68 ;
V_70 -> V_80 = V_66 ? V_66 : & V_81 ;
V_70 -> V_82 = 1 ;
V_71 = F_34 ( V_70 ) ;
if ( ! V_71 )
goto V_83;
V_71 -> V_57 = 1 ;
V_71 -> V_50 = V_84 | V_85 | V_86 ;
V_71 -> V_87 = V_71 -> V_88 = V_71 -> V_89 = V_90 ;
V_1 = F_35 ( V_70 , & V_26 ) ;
if ( ! V_1 ) {
F_36 ( V_71 ) ;
goto V_83;
}
F_37 ( V_1 , V_71 ) ;
V_70 -> V_91 = V_1 ;
V_70 -> V_92 = V_67 ;
V_70 -> V_93 |= V_94 ;
return F_38 ( V_70 -> V_91 ) ;
V_83:
F_39 ( V_70 ) ;
return F_8 ( - V_34 ) ;
}
int F_40 ( struct V_7 * V_7 , struct V_29 * V_29 )
{
if ( V_7 -> V_95 )
V_29 -> V_32 = V_7 -> V_95 ;
return 0 ;
}
int F_41 ( struct V_1 * V_96 , struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_96 -> V_2 ;
V_7 -> V_89 = V_21 -> V_89 = V_21 -> V_88 = V_90 ;
F_42 ( V_7 ) ;
F_43 ( V_7 ) ;
F_38 ( V_1 ) ;
F_37 ( V_1 , V_7 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_1 )
{
struct V_1 * V_97 ;
int V_98 = 0 ;
F_19 ( & V_1 -> V_44 ) ;
F_45 (child, &dentry->d_subdirs, d_u.d_child) {
F_22 ( & V_97 -> V_44 , V_49 ) ;
if ( F_1 ( V_97 ) ) {
F_23 ( & V_97 -> V_44 ) ;
goto V_99;
}
F_23 ( & V_97 -> V_44 ) ;
}
V_98 = 1 ;
V_99:
F_23 ( & V_1 -> V_44 ) ;
return V_98 ;
}
int F_46 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
V_7 -> V_89 = V_21 -> V_89 = V_21 -> V_88 = V_90 ;
F_47 ( V_7 ) ;
F_15 ( V_1 ) ;
return 0 ;
}
int F_48 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
if ( ! F_44 ( V_1 ) )
return - V_100 ;
F_47 ( V_1 -> V_2 ) ;
F_46 ( V_21 , V_1 ) ;
F_47 ( V_21 ) ;
return 0 ;
}
int F_49 ( struct V_7 * V_101 , struct V_1 * V_96 ,
struct V_7 * V_102 , struct V_1 * V_103 )
{
struct V_7 * V_7 = V_96 -> V_2 ;
int V_104 = F_50 ( V_96 -> V_2 -> V_50 ) ;
if ( ! F_44 ( V_103 ) )
return - V_100 ;
if ( V_103 -> V_2 ) {
F_46 ( V_102 , V_103 ) ;
if ( V_104 ) {
F_47 ( V_103 -> V_2 ) ;
F_47 ( V_101 ) ;
}
} else if ( V_104 ) {
F_47 ( V_101 ) ;
F_42 ( V_102 ) ;
}
V_101 -> V_89 = V_101 -> V_88 = V_102 -> V_89 =
V_102 -> V_88 = V_7 -> V_89 = V_90 ;
return 0 ;
}
int F_51 ( struct V_1 * V_1 , struct V_105 * V_105 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
int error ;
F_52 ( V_7 -> V_106 -> V_107 ) ;
error = F_53 ( V_7 , V_105 ) ;
if ( error )
return error ;
if ( V_105 -> V_108 & V_109 )
F_54 ( V_7 , V_105 -> V_110 ) ;
F_55 ( V_7 , V_105 ) ;
F_56 ( V_7 ) ;
return 0 ;
}
int F_57 ( struct V_29 * V_29 , struct V_111 * V_111 )
{
F_58 ( V_111 ) ;
F_59 ( V_111 ) ;
F_60 ( V_111 ) ;
F_61 ( V_111 ) ;
return 0 ;
}
int F_62 ( struct V_29 * V_29 , struct V_112 * V_113 ,
T_1 V_114 , unsigned V_27 , unsigned V_22 ,
struct V_111 * * V_115 , void * * V_116 )
{
struct V_111 * V_111 ;
T_7 V_117 ;
V_117 = V_114 >> V_11 ;
V_111 = F_63 ( V_113 , V_117 , V_22 ) ;
if ( ! V_111 )
return - V_34 ;
* V_115 = V_111 ;
if ( ! F_64 ( V_111 ) && ( V_27 != V_18 ) ) {
unsigned V_118 = V_114 & ( V_18 - 1 ) ;
F_65 ( V_111 , 0 , V_118 , V_118 + V_27 , V_18 ) ;
}
return 0 ;
}
int F_66 ( struct V_29 * V_29 , struct V_112 * V_113 ,
T_1 V_114 , unsigned V_27 , unsigned V_119 ,
struct V_111 * V_111 , void * V_116 )
{
struct V_7 * V_7 = V_111 -> V_113 -> V_120 ;
T_1 V_121 = V_114 + V_119 ;
if ( V_119 < V_27 ) {
unsigned V_118 = V_114 & ( V_18 - 1 ) ;
F_67 ( V_111 , V_118 + V_119 , V_27 - V_119 ) ;
}
if ( ! F_64 ( V_111 ) )
F_60 ( V_111 ) ;
if ( V_121 > V_7 -> V_122 )
F_68 ( V_7 , V_121 ) ;
F_69 ( V_111 ) ;
F_61 ( V_111 ) ;
F_70 ( V_111 ) ;
return V_119 ;
}
int F_71 ( struct V_69 * V_70 , unsigned long V_68 ,
struct V_123 * V_124 )
{
struct V_7 * V_7 ;
struct V_1 * V_71 ;
struct V_1 * V_1 ;
int V_56 ;
V_70 -> V_76 = V_18 ;
V_70 -> V_78 = V_11 ;
V_70 -> V_16 = V_68 ;
V_70 -> V_80 = & V_81 ;
V_70 -> V_82 = 1 ;
V_7 = F_34 ( V_70 ) ;
if ( ! V_7 )
return - V_34 ;
V_7 -> V_57 = 1 ;
V_7 -> V_50 = V_84 | 0755 ;
V_7 -> V_87 = V_7 -> V_88 = V_7 -> V_89 = V_90 ;
V_7 -> V_106 = & V_125 ;
V_7 -> V_126 = & V_127 ;
F_72 ( V_7 , 2 ) ;
V_71 = F_73 ( V_7 ) ;
if ( ! V_71 )
return - V_34 ;
for ( V_56 = 0 ; ! V_124 -> V_59 || V_124 -> V_59 [ 0 ] ; V_56 ++ , V_124 ++ ) {
if ( ! V_124 -> V_59 )
continue;
if ( F_74 ( V_56 == 1 ) )
F_75 ( V_128 L_3
L_4 , V_129 ,
V_70 -> V_130 -> V_59 ) ;
V_1 = F_76 ( V_71 , V_124 -> V_59 ) ;
if ( ! V_1 )
goto V_99;
V_7 = F_34 ( V_70 ) ;
if ( ! V_7 ) {
F_15 ( V_1 ) ;
goto V_99;
}
V_7 -> V_50 = V_131 | V_124 -> V_132 ;
V_7 -> V_87 = V_7 -> V_88 = V_7 -> V_89 = V_90 ;
V_7 -> V_126 = V_124 -> V_66 ;
V_7 -> V_57 = V_56 ;
F_10 ( V_1 , V_7 ) ;
}
V_70 -> V_91 = V_71 ;
return 0 ;
V_99:
F_77 ( V_71 ) ;
F_78 ( V_71 ) ;
F_15 ( V_71 ) ;
return - V_34 ;
}
int F_79 ( struct V_63 * type , struct V_3 * * V_133 , int * V_134 )
{
struct V_3 * V_4 = NULL ;
F_19 ( & V_135 ) ;
if ( F_74 ( ! * V_133 ) ) {
F_23 ( & V_135 ) ;
V_4 = F_80 ( type , V_136 , type -> V_59 , NULL ) ;
if ( F_32 ( V_4 ) )
return F_81 ( V_4 ) ;
F_19 ( & V_135 ) ;
if ( ! * V_133 )
* V_133 = V_4 ;
}
F_82 ( * V_133 ) ;
++ * V_134 ;
F_23 ( & V_135 ) ;
F_83 ( V_4 ) ;
return 0 ;
}
void F_84 ( struct V_3 * * V_133 , int * V_134 )
{
struct V_3 * V_4 ;
F_19 ( & V_135 ) ;
V_4 = * V_133 ;
if ( ! -- * V_134 )
* V_133 = NULL ;
F_23 ( & V_135 ) ;
F_83 ( V_4 ) ;
}
T_4 F_85 ( void T_5 * V_137 , T_6 V_134 , T_1 * V_61 ,
const void * V_118 , T_6 V_138 )
{
T_1 V_114 = * V_61 ;
T_6 V_98 ;
if ( V_114 < 0 )
return - V_39 ;
if ( V_114 >= V_138 || ! V_134 )
return 0 ;
if ( V_134 > V_138 - V_114 )
V_134 = V_138 - V_114 ;
V_98 = F_86 ( V_137 , V_118 + V_114 , V_134 ) ;
if ( V_98 == V_134 )
return - V_139 ;
V_134 -= V_98 ;
* V_61 = V_114 + V_134 ;
return V_134 ;
}
T_4 F_87 ( void * V_137 , T_6 V_138 , T_1 * V_61 ,
const void T_5 * V_118 , T_6 V_134 )
{
T_1 V_114 = * V_61 ;
T_6 V_140 ;
if ( V_114 < 0 )
return - V_39 ;
if ( V_114 >= V_138 || ! V_134 )
return 0 ;
if ( V_134 > V_138 - V_114 )
V_134 = V_138 - V_114 ;
V_140 = F_88 ( V_137 + V_114 , V_118 , V_134 ) ;
if ( V_140 == V_134 )
return - V_139 ;
V_134 -= V_140 ;
* V_61 = V_114 + V_134 ;
return V_134 ;
}
T_4 F_89 ( void * V_137 , T_6 V_134 , T_1 * V_61 ,
const void * V_118 , T_6 V_138 )
{
T_1 V_114 = * V_61 ;
if ( V_114 < 0 )
return - V_39 ;
if ( V_114 >= V_138 )
return 0 ;
if ( V_134 > V_138 - V_114 )
V_134 = V_138 - V_114 ;
memcpy ( V_137 , V_118 + V_114 , V_134 ) ;
* V_61 = V_114 + V_134 ;
return V_134 ;
}
void F_90 ( struct V_29 * V_29 , T_6 V_43 )
{
struct V_141 * V_142 = V_29 -> V_32 ;
F_91 ( V_43 > V_143 ) ;
F_92 () ;
V_142 -> V_144 = V_43 ;
}
char * F_93 ( struct V_29 * V_29 , const char T_5 * V_13 , T_6 V_144 )
{
struct V_141 * V_142 ;
static F_94 ( V_145 ) ;
if ( V_144 > V_143 - 1 )
return F_8 ( - V_146 ) ;
V_142 = (struct V_141 * ) F_95 ( V_147 ) ;
if ( ! V_142 )
return F_8 ( - V_34 ) ;
F_19 ( & V_145 ) ;
if ( V_29 -> V_32 ) {
F_23 ( & V_145 ) ;
F_96 ( ( unsigned long ) V_142 ) ;
return F_8 ( - V_148 ) ;
}
V_29 -> V_32 = V_142 ;
F_23 ( & V_145 ) ;
if ( F_88 ( V_142 -> V_149 , V_13 , V_144 ) )
return F_8 ( - V_139 ) ;
return V_142 -> V_149 ;
}
T_4 F_97 ( struct V_29 * V_29 , char T_5 * V_13 , T_6 V_144 , T_1 * V_114 )
{
struct V_141 * V_142 = V_29 -> V_32 ;
if ( ! V_142 )
return 0 ;
return F_85 ( V_13 , V_144 , V_114 , V_142 -> V_149 , V_142 -> V_144 ) ;
}
int F_98 ( struct V_7 * V_7 , struct V_29 * V_29 )
{
F_96 ( ( unsigned long ) V_29 -> V_32 ) ;
return 0 ;
}
int F_99 ( struct V_7 * V_7 , struct V_29 * V_29 ,
int (* F_100)( void * , T_8 * ) , int (* F_101)( void * , T_8 ) ,
const char * V_150 )
{
struct V_151 * V_152 ;
V_152 = F_102 ( sizeof( * V_152 ) , V_147 ) ;
if ( ! V_152 )
return - V_34 ;
V_152 -> F_100 = F_100 ;
V_152 -> F_101 = F_101 ;
V_152 -> V_149 = V_7 -> V_95 ;
V_152 -> V_150 = V_150 ;
F_103 ( & V_152 -> V_153 ) ;
V_29 -> V_32 = V_152 ;
return F_104 ( V_7 , V_29 ) ;
}
int F_105 ( struct V_7 * V_7 , struct V_29 * V_29 )
{
F_106 ( V_29 -> V_32 ) ;
return 0 ;
}
T_4 F_107 ( struct V_29 * V_29 , char T_5 * V_13 ,
T_6 V_27 , T_1 * V_61 )
{
struct V_151 * V_152 ;
T_6 V_144 ;
T_4 V_98 ;
V_152 = V_29 -> V_32 ;
if ( ! V_152 -> F_100 )
return - V_154 ;
V_98 = F_108 ( & V_152 -> V_153 ) ;
if ( V_98 )
return V_98 ;
if ( * V_61 ) {
V_144 = strlen ( V_152 -> V_155 ) ;
} else {
T_8 V_156 ;
V_98 = V_152 -> F_100 ( V_152 -> V_149 , & V_156 ) ;
if ( V_98 )
goto V_99;
V_144 = F_109 ( V_152 -> V_155 , sizeof( V_152 -> V_155 ) ,
V_152 -> V_150 , ( unsigned long long ) V_156 ) ;
}
V_98 = F_85 ( V_13 , V_27 , V_61 , V_152 -> V_155 , V_144 ) ;
V_99:
F_18 ( & V_152 -> V_153 ) ;
return V_98 ;
}
T_4 F_110 ( struct V_29 * V_29 , const char T_5 * V_13 ,
T_6 V_27 , T_1 * V_61 )
{
struct V_151 * V_152 ;
T_8 V_156 ;
T_6 V_144 ;
T_4 V_98 ;
V_152 = V_29 -> V_32 ;
if ( ! V_152 -> F_101 )
return - V_154 ;
V_98 = F_108 ( & V_152 -> V_153 ) ;
if ( V_98 )
return V_98 ;
V_98 = - V_139 ;
V_144 = F_111 ( sizeof( V_152 -> V_157 ) - 1 , V_27 ) ;
if ( F_88 ( V_152 -> V_157 , V_13 , V_144 ) )
goto V_99;
V_152 -> V_157 [ V_144 ] = '\0' ;
V_156 = F_112 ( V_152 -> V_157 , NULL , 0 ) ;
V_98 = V_152 -> F_101 ( V_152 -> V_149 , V_156 ) ;
if ( V_98 == 0 )
V_98 = V_27 ;
V_99:
F_18 ( & V_152 -> V_153 ) ;
return V_98 ;
}
int F_113 ( struct V_29 * V_29 , T_1 V_158 , T_1 V_159 ,
int V_160 )
{
struct V_7 * V_7 = V_29 -> V_161 -> V_120 ;
int V_162 ;
int V_98 ;
V_162 = F_114 ( V_7 -> V_9 , V_158 , V_159 ) ;
if ( V_162 )
return V_162 ;
F_17 ( & V_7 -> V_37 ) ;
V_98 = F_115 ( V_7 -> V_9 ) ;
if ( ! ( V_7 -> V_163 & V_164 ) )
goto V_99;
if ( V_160 && ! ( V_7 -> V_163 & V_165 ) )
goto V_99;
V_162 = F_116 ( V_7 , 1 ) ;
if ( V_98 == 0 )
V_98 = V_162 ;
V_99:
F_18 ( & V_7 -> V_37 ) ;
return V_98 ;
}
int F_117 ( unsigned V_166 , T_8 V_167 )
{
T_8 V_168 = V_167 - 1 ;
T_8 V_169 =
V_168 >> ( V_11 - V_166 ) ;
if ( F_74 ( V_167 == 0 ) )
return 0 ;
if ( ( V_166 < 9 ) || ( V_166 > V_11 ) )
return - V_39 ;
if ( ( V_168 > ( V_170 ) ( ~ 0ULL ) >> ( V_166 - 9 ) ) ||
( V_169 > ( T_7 ) ( ~ 0ULL ) ) ) {
return - V_146 ;
}
return 0 ;
}
int F_118 ( struct V_29 * V_29 , T_1 V_158 , T_1 V_159 , int V_160 )
{
return 0 ;
}
