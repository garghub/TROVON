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
struct V_1 * F_7 ( struct V_7 * V_21 , struct V_1 * V_1 , struct V_22 * V_23 )
{
static const struct V_24 V_25 = {
. V_26 = F_6 ,
} ;
if ( V_1 -> V_27 . V_28 > V_20 )
return F_8 ( - V_29 ) ;
F_9 ( V_1 , & V_25 ) ;
F_10 ( V_1 , NULL ) ;
return NULL ;
}
int F_11 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
static struct V_31 V_32 = { . V_28 = 1 , . V_33 = L_1 } ;
V_30 -> V_34 = F_12 ( V_30 -> V_35 . V_1 , & V_32 ) ;
return V_30 -> V_34 ? 0 : - V_36 ;
}
int F_13 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
F_14 ( V_30 -> V_34 ) ;
return 0 ;
}
T_1 F_15 ( struct V_30 * V_30 , T_1 V_37 , int V_38 )
{
struct V_1 * V_1 = V_30 -> V_35 . V_1 ;
F_16 ( & V_1 -> V_2 -> V_39 ) ;
switch ( V_38 ) {
case 1 :
V_37 += V_30 -> V_40 ;
case 0 :
if ( V_37 >= 0 )
break;
default:
F_17 ( & V_1 -> V_2 -> V_39 ) ;
return - V_41 ;
}
if ( V_37 != V_30 -> V_40 ) {
V_30 -> V_40 = V_37 ;
if ( V_30 -> V_40 >= 2 ) {
struct V_42 * V_43 ;
struct V_1 * V_44 = V_30 -> V_34 ;
T_1 V_45 = V_30 -> V_40 - 2 ;
F_18 ( & V_1 -> V_46 ) ;
F_19 ( & V_44 -> V_47 . V_48 ) ;
V_43 = V_1 -> V_49 . V_50 ;
while ( V_45 && V_43 != & V_1 -> V_49 ) {
struct V_1 * V_50 ;
V_50 = F_20 ( V_43 , struct V_1 , V_47 . V_48 ) ;
F_21 ( & V_50 -> V_46 , V_51 ) ;
if ( F_1 ( V_50 ) )
V_45 -- ;
F_22 ( & V_50 -> V_46 ) ;
V_43 = V_43 -> V_50 ;
}
F_23 ( & V_44 -> V_47 . V_48 , V_43 ) ;
F_22 ( & V_1 -> V_46 ) ;
}
}
F_17 ( & V_1 -> V_2 -> V_39 ) ;
return V_37 ;
}
static inline unsigned char F_24 ( struct V_7 * V_7 )
{
return ( V_7 -> V_52 >> 12 ) & 15 ;
}
int F_25 ( struct V_30 * V_53 , void * V_54 , T_2 V_55 )
{
struct V_1 * V_1 = V_53 -> V_35 . V_1 ;
struct V_1 * V_44 = V_53 -> V_34 ;
struct V_42 * V_43 , * V_56 = & V_44 -> V_47 . V_48 ;
T_3 V_57 ;
int V_58 = V_53 -> V_40 ;
switch ( V_58 ) {
case 0 :
V_57 = V_1 -> V_2 -> V_59 ;
if ( V_55 ( V_54 , L_1 , 1 , V_58 , V_57 , V_60 ) < 0 )
break;
V_53 -> V_40 ++ ;
V_58 ++ ;
case 1 :
V_57 = F_26 ( V_1 ) ;
if ( V_55 ( V_54 , L_2 , 2 , V_58 , V_57 , V_60 ) < 0 )
break;
V_53 -> V_40 ++ ;
V_58 ++ ;
default:
F_18 ( & V_1 -> V_46 ) ;
if ( V_53 -> V_40 == 2 )
F_27 ( V_56 , & V_1 -> V_49 ) ;
for ( V_43 = V_56 -> V_50 ; V_43 != & V_1 -> V_49 ; V_43 = V_43 -> V_50 ) {
struct V_1 * V_50 ;
V_50 = F_20 ( V_43 , struct V_1 , V_47 . V_48 ) ;
F_21 ( & V_50 -> V_46 , V_51 ) ;
if ( ! F_1 ( V_50 ) ) {
F_22 ( & V_50 -> V_46 ) ;
continue;
}
F_22 ( & V_50 -> V_46 ) ;
F_22 ( & V_1 -> V_46 ) ;
if ( V_55 ( V_54 , V_50 -> V_27 . V_33 ,
V_50 -> V_27 . V_28 , V_53 -> V_40 ,
V_50 -> V_2 -> V_59 ,
F_24 ( V_50 -> V_2 ) ) < 0 )
return 0 ;
F_18 ( & V_1 -> V_46 ) ;
F_21 ( & V_50 -> V_46 , V_51 ) ;
F_27 ( V_56 , V_43 ) ;
F_22 ( & V_50 -> V_46 ) ;
V_43 = V_56 ;
V_53 -> V_40 ++ ;
}
F_22 ( & V_1 -> V_46 ) ;
}
return 0 ;
}
T_4 F_28 ( struct V_30 * V_53 , char T_5 * V_13 , T_6 V_61 , T_1 * V_62 )
{
return - V_63 ;
}
struct V_1 * F_29 ( struct V_64 * V_65 , char * V_33 ,
const struct V_66 * V_67 ,
const struct V_24 * V_68 , unsigned long V_69 )
{
struct V_70 * V_71 = F_30 ( V_65 , NULL , V_72 , NULL ) ;
struct V_1 * V_1 ;
struct V_7 * V_73 ;
struct V_31 V_27 = { . V_33 = V_33 , . V_28 = strlen (name) } ;
if ( F_31 ( V_71 ) )
return F_32 ( V_71 ) ;
V_71 -> V_74 = V_75 ;
V_71 -> V_76 = V_77 ;
V_71 -> V_78 = V_79 ;
V_71 -> V_80 = V_81 ;
V_71 -> V_16 = V_69 ;
V_71 -> V_82 = V_67 ? V_67 : & V_83 ;
V_71 -> V_84 = 1 ;
V_73 = F_33 ( V_71 ) ;
if ( ! V_73 )
goto V_85;
V_73 -> V_59 = 1 ;
V_73 -> V_52 = V_86 | V_87 | V_88 ;
V_73 -> V_89 = V_73 -> V_90 = V_73 -> V_91 = V_92 ;
V_1 = F_34 ( V_71 , & V_27 ) ;
if ( ! V_1 ) {
F_35 ( V_73 ) ;
goto V_85;
}
F_36 ( V_1 , V_73 ) ;
V_71 -> V_93 = V_1 ;
V_71 -> V_94 = V_68 ;
V_71 -> V_74 |= V_95 ;
return F_37 ( V_71 -> V_93 ) ;
V_85:
F_38 ( V_71 ) ;
return F_8 ( - V_36 ) ;
}
int F_39 ( struct V_1 * V_96 , struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_96 -> V_2 ;
V_7 -> V_91 = V_21 -> V_91 = V_21 -> V_90 = V_92 ;
F_40 ( V_7 ) ;
F_41 ( V_7 ) ;
F_37 ( V_1 ) ;
F_36 ( V_1 , V_7 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_1 )
{
struct V_1 * V_97 ;
int V_98 = 0 ;
F_18 ( & V_1 -> V_46 ) ;
F_43 (child, &dentry->d_subdirs, d_u.d_child) {
F_21 ( & V_97 -> V_46 , V_51 ) ;
if ( F_1 ( V_97 ) ) {
F_22 ( & V_97 -> V_46 ) ;
goto V_99;
}
F_22 ( & V_97 -> V_46 ) ;
}
V_98 = 1 ;
V_99:
F_22 ( & V_1 -> V_46 ) ;
return V_98 ;
}
int F_44 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
V_7 -> V_91 = V_21 -> V_91 = V_21 -> V_90 = V_92 ;
F_45 ( V_7 ) ;
F_14 ( V_1 ) ;
return 0 ;
}
int F_46 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
if ( ! F_42 ( V_1 ) )
return - V_100 ;
F_45 ( V_1 -> V_2 ) ;
F_44 ( V_21 , V_1 ) ;
F_45 ( V_21 ) ;
return 0 ;
}
int F_47 ( struct V_7 * V_101 , struct V_1 * V_96 ,
struct V_7 * V_102 , struct V_1 * V_103 )
{
struct V_7 * V_7 = V_96 -> V_2 ;
int V_104 = F_48 ( V_96 -> V_2 -> V_52 ) ;
if ( ! F_42 ( V_103 ) )
return - V_100 ;
if ( V_103 -> V_2 ) {
F_44 ( V_102 , V_103 ) ;
if ( V_104 ) {
F_45 ( V_103 -> V_2 ) ;
F_45 ( V_101 ) ;
}
} else if ( V_104 ) {
F_45 ( V_101 ) ;
F_40 ( V_102 ) ;
}
V_101 -> V_91 = V_101 -> V_90 = V_102 -> V_91 =
V_102 -> V_90 = V_7 -> V_91 = V_92 ;
return 0 ;
}
int F_49 ( struct V_1 * V_1 , struct V_105 * V_105 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
int error ;
F_50 ( V_7 -> V_106 -> V_107 ) ;
error = F_51 ( V_7 , V_105 ) ;
if ( error )
return error ;
if ( V_105 -> V_108 & V_109 )
F_52 ( V_7 , V_105 -> V_110 ) ;
F_53 ( V_7 , V_105 ) ;
F_54 ( V_7 ) ;
return 0 ;
}
int F_55 ( struct V_30 * V_30 , struct V_111 * V_111 )
{
F_56 ( V_111 ) ;
F_57 ( V_111 ) ;
F_58 ( V_111 ) ;
F_59 ( V_111 ) ;
return 0 ;
}
int F_60 ( struct V_30 * V_30 , struct V_112 * V_113 ,
T_1 V_114 , unsigned V_28 , unsigned V_115 ,
struct V_111 * * V_116 , void * * V_117 )
{
struct V_111 * V_111 ;
T_7 V_118 ;
V_118 = V_114 >> V_11 ;
V_111 = F_61 ( V_113 , V_118 , V_115 ) ;
if ( ! V_111 )
return - V_36 ;
* V_116 = V_111 ;
if ( ! F_62 ( V_111 ) && ( V_28 != V_18 ) ) {
unsigned V_119 = V_114 & ( V_18 - 1 ) ;
F_63 ( V_111 , 0 , V_119 , V_119 + V_28 , V_18 ) ;
}
return 0 ;
}
int F_64 ( struct V_30 * V_30 , struct V_112 * V_113 ,
T_1 V_114 , unsigned V_28 , unsigned V_120 ,
struct V_111 * V_111 , void * V_117 )
{
struct V_7 * V_7 = V_111 -> V_113 -> V_121 ;
T_1 V_122 = V_114 + V_120 ;
if ( V_120 < V_28 ) {
unsigned V_119 = V_114 & ( V_18 - 1 ) ;
F_65 ( V_111 , V_119 + V_120 , V_28 - V_120 ) ;
}
if ( ! F_62 ( V_111 ) )
F_58 ( V_111 ) ;
if ( V_122 > V_7 -> V_123 )
F_66 ( V_7 , V_122 ) ;
F_67 ( V_111 ) ;
F_59 ( V_111 ) ;
F_68 ( V_111 ) ;
return V_120 ;
}
int F_69 ( struct V_70 * V_71 , unsigned long V_69 ,
struct V_124 * V_125 )
{
struct V_7 * V_7 ;
struct V_1 * V_73 ;
struct V_1 * V_1 ;
int V_58 ;
V_71 -> V_78 = V_18 ;
V_71 -> V_80 = V_11 ;
V_71 -> V_16 = V_69 ;
V_71 -> V_82 = & V_83 ;
V_71 -> V_84 = 1 ;
V_7 = F_33 ( V_71 ) ;
if ( ! V_7 )
return - V_36 ;
V_7 -> V_59 = 1 ;
V_7 -> V_52 = V_86 | 0755 ;
V_7 -> V_89 = V_7 -> V_90 = V_7 -> V_91 = V_92 ;
V_7 -> V_106 = & V_126 ;
V_7 -> V_127 = & V_128 ;
V_7 -> V_129 = 2 ;
V_73 = F_70 ( V_7 ) ;
if ( ! V_73 ) {
F_35 ( V_7 ) ;
return - V_36 ;
}
for ( V_58 = 0 ; ! V_125 -> V_33 || V_125 -> V_33 [ 0 ] ; V_58 ++ , V_125 ++ ) {
if ( ! V_125 -> V_33 )
continue;
if ( F_71 ( V_58 == 1 ) )
F_72 ( V_130 L_3
L_4 , V_131 ,
V_71 -> V_132 -> V_33 ) ;
V_1 = F_73 ( V_73 , V_125 -> V_33 ) ;
if ( ! V_1 )
goto V_99;
V_7 = F_33 ( V_71 ) ;
if ( ! V_7 )
goto V_99;
V_7 -> V_52 = V_133 | V_125 -> V_134 ;
V_7 -> V_89 = V_7 -> V_90 = V_7 -> V_91 = V_92 ;
V_7 -> V_127 = V_125 -> V_67 ;
V_7 -> V_59 = V_58 ;
F_10 ( V_1 , V_7 ) ;
}
V_71 -> V_93 = V_73 ;
return 0 ;
V_99:
F_74 ( V_73 ) ;
F_14 ( V_73 ) ;
return - V_36 ;
}
int F_75 ( struct V_64 * type , struct V_3 * * V_135 , int * V_136 )
{
struct V_3 * V_4 = NULL ;
F_18 ( & V_137 ) ;
if ( F_71 ( ! * V_135 ) ) {
F_22 ( & V_137 ) ;
V_4 = F_76 ( type , 0 , type -> V_33 , NULL ) ;
if ( F_31 ( V_4 ) )
return F_77 ( V_4 ) ;
F_18 ( & V_137 ) ;
if ( ! * V_135 )
* V_135 = V_4 ;
}
F_78 ( * V_135 ) ;
++ * V_136 ;
F_22 ( & V_137 ) ;
F_79 ( V_4 ) ;
return 0 ;
}
void F_80 ( struct V_3 * * V_135 , int * V_136 )
{
struct V_3 * V_4 ;
F_18 ( & V_137 ) ;
V_4 = * V_135 ;
if ( ! -- * V_136 )
* V_135 = NULL ;
F_22 ( & V_137 ) ;
F_79 ( V_4 ) ;
}
T_4 F_81 ( void T_5 * V_138 , T_6 V_136 , T_1 * V_62 ,
const void * V_119 , T_6 V_139 )
{
T_1 V_114 = * V_62 ;
T_6 V_98 ;
if ( V_114 < 0 )
return - V_41 ;
if ( V_114 >= V_139 || ! V_136 )
return 0 ;
if ( V_136 > V_139 - V_114 )
V_136 = V_139 - V_114 ;
V_98 = F_82 ( V_138 , V_119 + V_114 , V_136 ) ;
if ( V_98 == V_136 )
return - V_140 ;
V_136 -= V_98 ;
* V_62 = V_114 + V_136 ;
return V_136 ;
}
T_4 F_83 ( void * V_138 , T_6 V_139 , T_1 * V_62 ,
const void T_5 * V_119 , T_6 V_136 )
{
T_1 V_114 = * V_62 ;
T_6 V_141 ;
if ( V_114 < 0 )
return - V_41 ;
if ( V_114 >= V_139 || ! V_136 )
return 0 ;
if ( V_136 > V_139 - V_114 )
V_136 = V_139 - V_114 ;
V_141 = F_84 ( V_138 + V_114 , V_119 , V_136 ) ;
if ( V_141 == V_136 )
return - V_140 ;
V_136 -= V_141 ;
* V_62 = V_114 + V_136 ;
return V_136 ;
}
T_4 F_85 ( void * V_138 , T_6 V_136 , T_1 * V_62 ,
const void * V_119 , T_6 V_139 )
{
T_1 V_114 = * V_62 ;
if ( V_114 < 0 )
return - V_41 ;
if ( V_114 >= V_139 )
return 0 ;
if ( V_136 > V_139 - V_114 )
V_136 = V_139 - V_114 ;
memcpy ( V_138 , V_119 + V_114 , V_136 ) ;
* V_62 = V_114 + V_136 ;
return V_136 ;
}
void F_86 ( struct V_30 * V_30 , T_6 V_45 )
{
struct V_142 * V_143 = V_30 -> V_34 ;
F_87 ( V_45 > V_144 ) ;
F_88 () ;
V_143 -> V_145 = V_45 ;
}
char * F_89 ( struct V_30 * V_30 , const char T_5 * V_13 , T_6 V_145 )
{
struct V_142 * V_143 ;
static F_90 ( V_146 ) ;
if ( V_145 > V_144 - 1 )
return F_8 ( - V_147 ) ;
V_143 = (struct V_142 * ) F_91 ( V_148 ) ;
if ( ! V_143 )
return F_8 ( - V_36 ) ;
F_18 ( & V_146 ) ;
if ( V_30 -> V_34 ) {
F_22 ( & V_146 ) ;
F_92 ( ( unsigned long ) V_143 ) ;
return F_8 ( - V_149 ) ;
}
V_30 -> V_34 = V_143 ;
F_22 ( & V_146 ) ;
if ( F_84 ( V_143 -> V_150 , V_13 , V_145 ) )
return F_8 ( - V_140 ) ;
return V_143 -> V_150 ;
}
T_4 F_93 ( struct V_30 * V_30 , char T_5 * V_13 , T_6 V_145 , T_1 * V_114 )
{
struct V_142 * V_143 = V_30 -> V_34 ;
if ( ! V_143 )
return 0 ;
return F_81 ( V_13 , V_145 , V_114 , V_143 -> V_150 , V_143 -> V_145 ) ;
}
int F_94 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
F_92 ( ( unsigned long ) V_30 -> V_34 ) ;
return 0 ;
}
int F_95 ( struct V_7 * V_7 , struct V_30 * V_30 ,
int (* F_96)( void * , T_8 * ) , int (* F_97)( void * , T_8 ) ,
const char * V_151 )
{
struct V_152 * V_153 ;
V_153 = F_98 ( sizeof( * V_153 ) , V_148 ) ;
if ( ! V_153 )
return - V_36 ;
V_153 -> F_96 = F_96 ;
V_153 -> F_97 = F_97 ;
V_153 -> V_150 = V_7 -> V_154 ;
V_153 -> V_151 = V_151 ;
F_99 ( & V_153 -> V_155 ) ;
V_30 -> V_34 = V_153 ;
return F_100 ( V_7 , V_30 ) ;
}
int F_101 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
F_102 ( V_30 -> V_34 ) ;
return 0 ;
}
T_4 F_103 ( struct V_30 * V_30 , char T_5 * V_13 ,
T_6 V_28 , T_1 * V_62 )
{
struct V_152 * V_153 ;
T_6 V_145 ;
T_4 V_98 ;
V_153 = V_30 -> V_34 ;
if ( ! V_153 -> F_96 )
return - V_156 ;
V_98 = F_104 ( & V_153 -> V_155 ) ;
if ( V_98 )
return V_98 ;
if ( * V_62 ) {
V_145 = strlen ( V_153 -> V_157 ) ;
} else {
T_8 V_158 ;
V_98 = V_153 -> F_96 ( V_153 -> V_150 , & V_158 ) ;
if ( V_98 )
goto V_99;
V_145 = F_105 ( V_153 -> V_157 , sizeof( V_153 -> V_157 ) ,
V_153 -> V_151 , ( unsigned long long ) V_158 ) ;
}
V_98 = F_81 ( V_13 , V_28 , V_62 , V_153 -> V_157 , V_145 ) ;
V_99:
F_17 ( & V_153 -> V_155 ) ;
return V_98 ;
}
T_4 F_106 ( struct V_30 * V_30 , const char T_5 * V_13 ,
T_6 V_28 , T_1 * V_62 )
{
struct V_152 * V_153 ;
T_8 V_158 ;
T_6 V_145 ;
T_4 V_98 ;
V_153 = V_30 -> V_34 ;
if ( ! V_153 -> F_97 )
return - V_156 ;
V_98 = F_104 ( & V_153 -> V_155 ) ;
if ( V_98 )
return V_98 ;
V_98 = - V_140 ;
V_145 = F_107 ( sizeof( V_153 -> V_159 ) - 1 , V_28 ) ;
if ( F_84 ( V_153 -> V_159 , V_13 , V_145 ) )
goto V_99;
V_153 -> V_159 [ V_145 ] = '\0' ;
V_158 = F_108 ( V_153 -> V_159 , NULL , 0 ) ;
V_98 = V_153 -> F_97 ( V_153 -> V_150 , V_158 ) ;
if ( V_98 == 0 )
V_98 = V_28 ;
V_99:
F_17 ( & V_153 -> V_155 ) ;
return V_98 ;
}
int F_109 ( struct V_30 * V_30 , T_1 V_160 , T_1 V_161 ,
int V_162 )
{
struct V_7 * V_7 = V_30 -> V_163 -> V_121 ;
int V_164 ;
int V_98 ;
V_164 = F_110 ( V_7 -> V_9 , V_160 , V_161 ) ;
if ( V_164 )
return V_164 ;
F_16 ( & V_7 -> V_39 ) ;
V_98 = F_111 ( V_7 -> V_9 ) ;
if ( ! ( V_7 -> V_165 & V_166 ) )
goto V_99;
if ( V_162 && ! ( V_7 -> V_165 & V_167 ) )
goto V_99;
V_164 = F_112 ( V_7 , 1 ) ;
if ( V_98 == 0 )
V_98 = V_164 ;
V_99:
F_17 ( & V_7 -> V_39 ) ;
return V_98 ;
}
int F_113 ( unsigned V_168 , T_8 V_169 )
{
T_8 V_170 = V_169 - 1 ;
T_8 V_171 =
V_170 >> ( V_11 - V_168 ) ;
if ( F_71 ( V_169 == 0 ) )
return 0 ;
if ( ( V_168 < 9 ) || ( V_168 > V_11 ) )
return - V_41 ;
if ( ( V_170 > ( V_172 ) ( ~ 0ULL ) >> ( V_168 - 9 ) ) ||
( V_171 > ( T_7 ) ( ~ 0ULL ) ) ) {
return - V_147 ;
}
return 0 ;
}
int F_114 ( struct V_30 * V_30 , T_1 V_160 , T_1 V_161 , int V_162 )
{
return 0 ;
}
