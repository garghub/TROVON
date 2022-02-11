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
static struct V_28 V_29 = F_11 ( L_1 , 1 ) ;
V_27 -> V_30 = F_12 ( V_27 -> V_31 . V_3 , & V_29 ) ;
return V_27 -> V_30 ? 0 : - V_32 ;
}
int F_13 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
F_14 ( V_27 -> V_30 ) ;
return 0 ;
}
T_1 F_15 ( struct V_27 * V_27 , T_1 V_33 , int V_34 )
{
struct V_3 * V_3 = V_27 -> V_31 . V_3 ;
F_16 ( F_2 ( V_3 ) ) ;
switch ( V_34 ) {
case 1 :
V_33 += V_27 -> V_35 ;
case 0 :
if ( V_33 >= 0 )
break;
default:
F_17 ( F_2 ( V_3 ) ) ;
return - V_36 ;
}
if ( V_33 != V_27 -> V_35 ) {
V_27 -> V_35 = V_33 ;
if ( V_27 -> V_35 >= 2 ) {
struct V_37 * V_38 ;
struct V_3 * V_39 = V_27 -> V_30 ;
T_1 V_40 = V_27 -> V_35 - 2 ;
F_18 ( & V_3 -> V_41 ) ;
F_19 ( & V_39 -> V_42 ) ;
V_38 = V_3 -> V_43 . V_44 ;
while ( V_40 && V_38 != & V_3 -> V_43 ) {
struct V_3 * V_44 ;
V_44 = F_20 ( V_38 , struct V_3 , V_42 ) ;
F_21 ( & V_44 -> V_41 , V_45 ) ;
if ( F_22 ( V_44 ) )
V_40 -- ;
F_23 ( & V_44 -> V_41 ) ;
V_38 = V_38 -> V_44 ;
}
F_24 ( & V_39 -> V_42 , V_38 ) ;
F_23 ( & V_3 -> V_41 ) ;
}
}
F_17 ( F_2 ( V_3 ) ) ;
return V_33 ;
}
static inline unsigned char F_25 ( struct V_6 * V_6 )
{
return ( V_6 -> V_46 >> 12 ) & 15 ;
}
int F_26 ( struct V_27 * V_27 , struct V_47 * V_48 )
{
struct V_3 * V_3 = V_27 -> V_31 . V_3 ;
struct V_3 * V_39 = V_27 -> V_30 ;
struct V_37 * V_38 , * V_49 = & V_39 -> V_42 ;
if ( ! F_27 ( V_27 , V_48 ) )
return 0 ;
F_18 ( & V_3 -> V_41 ) ;
if ( V_48 -> V_50 == 2 )
F_28 ( V_49 , & V_3 -> V_43 ) ;
for ( V_38 = V_49 -> V_44 ; V_38 != & V_3 -> V_43 ; V_38 = V_38 -> V_44 ) {
struct V_3 * V_44 = F_20 ( V_38 , struct V_3 , V_42 ) ;
F_21 ( & V_44 -> V_41 , V_45 ) ;
if ( ! F_22 ( V_44 ) ) {
F_23 ( & V_44 -> V_41 ) ;
continue;
}
F_23 ( & V_44 -> V_41 ) ;
F_23 ( & V_3 -> V_41 ) ;
if ( ! F_29 ( V_48 , V_44 -> V_22 . V_51 , V_44 -> V_22 . V_23 ,
F_2 ( V_44 ) -> V_52 , F_25 ( F_2 ( V_44 ) ) ) )
return 0 ;
F_18 ( & V_3 -> V_41 ) ;
F_21 ( & V_44 -> V_41 , V_45 ) ;
F_28 ( V_49 , V_38 ) ;
F_23 ( & V_44 -> V_41 ) ;
V_38 = V_49 ;
V_48 -> V_50 ++ ;
}
F_23 ( & V_3 -> V_41 ) ;
return 0 ;
}
T_2 F_30 ( struct V_27 * V_53 , char T_3 * V_12 , T_4 V_54 , T_1 * V_55 )
{
return - V_56 ;
}
struct V_3 * F_31 ( struct V_57 * V_58 , char * V_51 ,
const struct V_59 * V_60 ,
const struct V_61 * V_62 , unsigned long V_63 )
{
struct V_64 * V_65 ;
struct V_3 * V_3 ;
struct V_6 * V_66 ;
struct V_28 V_22 = F_11 ( V_51 , strlen ( V_51 ) ) ;
V_65 = F_32 ( V_58 , NULL , V_67 , V_68 , NULL ) ;
if ( F_33 ( V_65 ) )
return F_34 ( V_65 ) ;
V_65 -> V_69 = V_70 ;
V_65 -> V_71 = V_72 ;
V_65 -> V_73 = V_74 ;
V_65 -> V_15 = V_63 ;
V_65 -> V_75 = V_60 ? V_60 : & V_76 ;
V_65 -> V_77 = 1 ;
V_66 = F_35 ( V_65 ) ;
if ( ! V_66 )
goto V_78;
V_66 -> V_52 = 1 ;
V_66 -> V_46 = V_79 | V_80 | V_81 ;
V_66 -> V_82 = V_66 -> V_83 = V_66 -> V_84 = V_85 ;
V_3 = F_36 ( V_65 , & V_22 ) ;
if ( ! V_3 ) {
F_37 ( V_66 ) ;
goto V_78;
}
F_38 ( V_3 , V_66 ) ;
V_65 -> V_86 = V_3 ;
V_65 -> V_25 = V_62 ;
V_65 -> V_87 |= V_88 ;
return F_39 ( V_65 -> V_86 ) ;
V_78:
F_40 ( V_65 ) ;
return F_7 ( - V_32 ) ;
}
int F_41 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
if ( V_6 -> V_89 )
V_27 -> V_30 = V_6 -> V_89 ;
return 0 ;
}
int F_42 ( struct V_3 * V_90 , struct V_6 * V_20 , struct V_3 * V_3 )
{
struct V_6 * V_6 = F_2 ( V_90 ) ;
V_6 -> V_84 = V_20 -> V_84 = V_20 -> V_83 = V_85 ;
F_43 ( V_6 ) ;
F_44 ( V_6 ) ;
F_39 ( V_3 ) ;
F_38 ( V_3 , V_6 ) ;
return 0 ;
}
int F_45 ( struct V_3 * V_3 )
{
struct V_3 * V_91 ;
int V_92 = 0 ;
F_18 ( & V_3 -> V_41 ) ;
F_46 (child, &dentry->d_subdirs, d_child) {
F_21 ( & V_91 -> V_41 , V_45 ) ;
if ( F_22 ( V_91 ) ) {
F_23 ( & V_91 -> V_41 ) ;
goto V_93;
}
F_23 ( & V_91 -> V_41 ) ;
}
V_92 = 1 ;
V_93:
F_23 ( & V_3 -> V_41 ) ;
return V_92 ;
}
int F_47 ( struct V_6 * V_20 , struct V_3 * V_3 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
V_6 -> V_84 = V_20 -> V_84 = V_20 -> V_83 = V_85 ;
F_48 ( V_6 ) ;
F_14 ( V_3 ) ;
return 0 ;
}
int F_49 ( struct V_6 * V_20 , struct V_3 * V_3 )
{
if ( ! F_45 ( V_3 ) )
return - V_94 ;
F_48 ( F_2 ( V_3 ) ) ;
F_47 ( V_20 , V_3 ) ;
F_48 ( V_20 ) ;
return 0 ;
}
int F_50 ( struct V_6 * V_95 , struct V_3 * V_90 ,
struct V_6 * V_96 , struct V_3 * V_97 )
{
struct V_6 * V_6 = F_2 ( V_90 ) ;
int V_98 = F_51 ( V_90 ) ;
if ( ! F_45 ( V_97 ) )
return - V_94 ;
if ( F_52 ( V_97 ) ) {
F_47 ( V_96 , V_97 ) ;
if ( V_98 ) {
F_48 ( F_2 ( V_97 ) ) ;
F_48 ( V_95 ) ;
}
} else if ( V_98 ) {
F_48 ( V_95 ) ;
F_43 ( V_96 ) ;
}
V_95 -> V_84 = V_95 -> V_83 = V_96 -> V_84 =
V_96 -> V_83 = V_6 -> V_84 = V_85 ;
return 0 ;
}
int F_53 ( struct V_3 * V_3 , struct V_99 * V_99 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
int error ;
error = F_54 ( V_6 , V_99 ) ;
if ( error )
return error ;
if ( V_99 -> V_100 & V_101 )
F_55 ( V_6 , V_99 -> V_102 ) ;
F_56 ( V_6 , V_99 ) ;
F_57 ( V_6 ) ;
return 0 ;
}
int F_58 ( struct V_27 * V_27 , struct V_103 * V_103 )
{
F_59 ( V_103 ) ;
F_60 ( V_103 ) ;
F_61 ( V_103 ) ;
F_62 ( V_103 ) ;
return 0 ;
}
int F_63 ( struct V_27 * V_27 , struct V_104 * V_105 ,
T_1 V_50 , unsigned V_23 , unsigned V_21 ,
struct V_103 * * V_106 , void * * V_107 )
{
struct V_103 * V_103 ;
T_5 V_108 ;
V_108 = V_50 >> V_10 ;
V_103 = F_64 ( V_105 , V_108 , V_21 ) ;
if ( ! V_103 )
return - V_32 ;
* V_106 = V_103 ;
if ( ! F_65 ( V_103 ) && ( V_23 != V_17 ) ) {
unsigned V_109 = V_50 & ( V_17 - 1 ) ;
F_66 ( V_103 , 0 , V_109 , V_109 + V_23 , V_17 ) ;
}
return 0 ;
}
int F_67 ( struct V_27 * V_27 , struct V_104 * V_105 ,
T_1 V_50 , unsigned V_23 , unsigned V_110 ,
struct V_103 * V_103 , void * V_107 )
{
struct V_6 * V_6 = V_103 -> V_105 -> V_111 ;
T_1 V_112 = V_50 + V_110 ;
if ( V_110 < V_23 ) {
unsigned V_109 = V_50 & ( V_17 - 1 ) ;
F_68 ( V_103 , V_109 + V_110 , V_23 - V_110 ) ;
}
if ( ! F_65 ( V_103 ) )
F_61 ( V_103 ) ;
if ( V_112 > V_6 -> V_113 )
F_69 ( V_6 , V_112 ) ;
F_70 ( V_103 ) ;
F_62 ( V_103 ) ;
F_71 ( V_103 ) ;
return V_110 ;
}
int F_72 ( struct V_64 * V_65 , unsigned long V_63 ,
struct V_114 * V_115 )
{
struct V_6 * V_6 ;
struct V_3 * V_66 ;
struct V_3 * V_3 ;
int V_116 ;
V_65 -> V_71 = V_17 ;
V_65 -> V_73 = V_10 ;
V_65 -> V_15 = V_63 ;
V_65 -> V_75 = & V_76 ;
V_65 -> V_77 = 1 ;
V_6 = F_35 ( V_65 ) ;
if ( ! V_6 )
return - V_32 ;
V_6 -> V_52 = 1 ;
V_6 -> V_46 = V_79 | 0755 ;
V_6 -> V_82 = V_6 -> V_83 = V_6 -> V_84 = V_85 ;
V_6 -> V_117 = & V_118 ;
V_6 -> V_119 = & V_120 ;
F_73 ( V_6 , 2 ) ;
V_66 = F_74 ( V_6 ) ;
if ( ! V_66 )
return - V_32 ;
for ( V_116 = 0 ; ! V_115 -> V_51 || V_115 -> V_51 [ 0 ] ; V_116 ++ , V_115 ++ ) {
if ( ! V_115 -> V_51 )
continue;
if ( F_75 ( V_116 == 1 ) )
F_76 ( V_121 L_2
L_3 , V_122 ,
V_65 -> V_123 -> V_51 ) ;
V_3 = F_77 ( V_66 , V_115 -> V_51 ) ;
if ( ! V_3 )
goto V_93;
V_6 = F_35 ( V_65 ) ;
if ( ! V_6 ) {
F_14 ( V_3 ) ;
goto V_93;
}
V_6 -> V_46 = V_124 | V_115 -> V_125 ;
V_6 -> V_82 = V_6 -> V_83 = V_6 -> V_84 = V_85 ;
V_6 -> V_119 = V_115 -> V_60 ;
V_6 -> V_52 = V_116 ;
F_9 ( V_3 , V_6 ) ;
}
V_65 -> V_86 = V_66 ;
return 0 ;
V_93:
F_78 ( V_66 ) ;
F_79 ( V_66 ) ;
F_14 ( V_66 ) ;
return - V_32 ;
}
int F_80 ( struct V_57 * type , struct V_1 * * V_126 , int * V_127 )
{
struct V_1 * V_2 = NULL ;
F_18 ( & V_128 ) ;
if ( F_75 ( ! * V_126 ) ) {
F_23 ( & V_128 ) ;
V_2 = F_81 ( type , V_129 , type -> V_51 , NULL ) ;
if ( F_33 ( V_2 ) )
return F_82 ( V_2 ) ;
F_18 ( & V_128 ) ;
if ( ! * V_126 )
* V_126 = V_2 ;
}
F_83 ( * V_126 ) ;
++ * V_127 ;
F_23 ( & V_128 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
void F_85 ( struct V_1 * * V_126 , int * V_127 )
{
struct V_1 * V_2 ;
F_18 ( & V_128 ) ;
V_2 = * V_126 ;
if ( ! -- * V_127 )
* V_126 = NULL ;
F_23 ( & V_128 ) ;
F_84 ( V_2 ) ;
}
T_2 F_86 ( void T_3 * V_130 , T_4 V_127 , T_1 * V_55 ,
const void * V_109 , T_4 V_131 )
{
T_1 V_50 = * V_55 ;
T_4 V_92 ;
if ( V_50 < 0 )
return - V_36 ;
if ( V_50 >= V_131 || ! V_127 )
return 0 ;
if ( V_127 > V_131 - V_50 )
V_127 = V_131 - V_50 ;
V_92 = F_87 ( V_130 , V_109 + V_50 , V_127 ) ;
if ( V_92 == V_127 )
return - V_132 ;
V_127 -= V_92 ;
* V_55 = V_50 + V_127 ;
return V_127 ;
}
T_2 F_88 ( void * V_130 , T_4 V_131 , T_1 * V_55 ,
const void T_3 * V_109 , T_4 V_127 )
{
T_1 V_50 = * V_55 ;
T_4 V_133 ;
if ( V_50 < 0 )
return - V_36 ;
if ( V_50 >= V_131 || ! V_127 )
return 0 ;
if ( V_127 > V_131 - V_50 )
V_127 = V_131 - V_50 ;
V_133 = F_89 ( V_130 + V_50 , V_109 , V_127 ) ;
if ( V_133 == V_127 )
return - V_132 ;
V_127 -= V_133 ;
* V_55 = V_50 + V_127 ;
return V_127 ;
}
T_2 F_90 ( void * V_130 , T_4 V_127 , T_1 * V_55 ,
const void * V_109 , T_4 V_131 )
{
T_1 V_50 = * V_55 ;
if ( V_50 < 0 )
return - V_36 ;
if ( V_50 >= V_131 )
return 0 ;
if ( V_127 > V_131 - V_50 )
V_127 = V_131 - V_50 ;
memcpy ( V_130 , V_109 + V_50 , V_127 ) ;
* V_55 = V_50 + V_127 ;
return V_127 ;
}
void F_91 ( struct V_27 * V_27 , T_4 V_40 )
{
struct V_134 * V_135 = V_27 -> V_30 ;
F_92 ( V_40 > V_136 ) ;
F_93 () ;
V_135 -> V_137 = V_40 ;
}
char * F_94 ( struct V_27 * V_27 , const char T_3 * V_12 , T_4 V_137 )
{
struct V_134 * V_135 ;
static F_95 ( V_138 ) ;
if ( V_137 > V_136 - 1 )
return F_7 ( - V_139 ) ;
V_135 = (struct V_134 * ) F_96 ( V_140 ) ;
if ( ! V_135 )
return F_7 ( - V_32 ) ;
F_18 ( & V_138 ) ;
if ( V_27 -> V_30 ) {
F_23 ( & V_138 ) ;
F_97 ( ( unsigned long ) V_135 ) ;
return F_7 ( - V_141 ) ;
}
V_27 -> V_30 = V_135 ;
F_23 ( & V_138 ) ;
if ( F_89 ( V_135 -> V_142 , V_12 , V_137 ) )
return F_7 ( - V_132 ) ;
return V_135 -> V_142 ;
}
T_2 F_98 ( struct V_27 * V_27 , char T_3 * V_12 , T_4 V_137 , T_1 * V_50 )
{
struct V_134 * V_135 = V_27 -> V_30 ;
if ( ! V_135 )
return 0 ;
return F_86 ( V_12 , V_137 , V_50 , V_135 -> V_142 , V_135 -> V_137 ) ;
}
int F_99 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
F_97 ( ( unsigned long ) V_27 -> V_30 ) ;
return 0 ;
}
int F_100 ( struct V_6 * V_6 , struct V_27 * V_27 ,
int (* F_101)( void * , T_6 * ) , int (* F_102)( void * , T_6 ) ,
const char * V_143 )
{
struct V_144 * V_145 ;
V_145 = F_103 ( sizeof( * V_145 ) , V_140 ) ;
if ( ! V_145 )
return - V_32 ;
V_145 -> F_101 = F_101 ;
V_145 -> F_102 = F_102 ;
V_145 -> V_142 = V_6 -> V_89 ;
V_145 -> V_143 = V_143 ;
F_104 ( & V_145 -> V_146 ) ;
V_27 -> V_30 = V_145 ;
return F_105 ( V_6 , V_27 ) ;
}
int F_106 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
F_107 ( V_27 -> V_30 ) ;
return 0 ;
}
T_2 F_108 ( struct V_27 * V_27 , char T_3 * V_12 ,
T_4 V_23 , T_1 * V_55 )
{
struct V_144 * V_145 ;
T_4 V_137 ;
T_2 V_92 ;
V_145 = V_27 -> V_30 ;
if ( ! V_145 -> F_101 )
return - V_147 ;
V_92 = F_109 ( & V_145 -> V_146 ) ;
if ( V_92 )
return V_92 ;
if ( * V_55 ) {
V_137 = strlen ( V_145 -> V_148 ) ;
} else {
T_6 V_149 ;
V_92 = V_145 -> F_101 ( V_145 -> V_142 , & V_149 ) ;
if ( V_92 )
goto V_93;
V_137 = F_110 ( V_145 -> V_148 , sizeof( V_145 -> V_148 ) ,
V_145 -> V_143 , ( unsigned long long ) V_149 ) ;
}
V_92 = F_86 ( V_12 , V_23 , V_55 , V_145 -> V_148 , V_137 ) ;
V_93:
F_111 ( & V_145 -> V_146 ) ;
return V_92 ;
}
T_2 F_112 ( struct V_27 * V_27 , const char T_3 * V_12 ,
T_4 V_23 , T_1 * V_55 )
{
struct V_144 * V_145 ;
T_6 V_149 ;
T_4 V_137 ;
T_2 V_92 ;
V_145 = V_27 -> V_30 ;
if ( ! V_145 -> F_102 )
return - V_147 ;
V_92 = F_109 ( & V_145 -> V_146 ) ;
if ( V_92 )
return V_92 ;
V_92 = - V_132 ;
V_137 = F_113 ( sizeof( V_145 -> V_150 ) - 1 , V_23 ) ;
if ( F_89 ( V_145 -> V_150 , V_12 , V_137 ) )
goto V_93;
V_145 -> V_150 [ V_137 ] = '\0' ;
V_149 = F_114 ( V_145 -> V_150 , NULL , 0 ) ;
V_92 = V_145 -> F_102 ( V_145 -> V_142 , V_149 ) ;
if ( V_92 == 0 )
V_92 = V_23 ;
V_93:
F_111 ( & V_145 -> V_146 ) ;
return V_92 ;
}
int F_115 ( struct V_27 * V_27 , T_1 V_151 , T_1 V_152 ,
int V_153 )
{
struct V_6 * V_6 = V_27 -> V_154 -> V_111 ;
int V_155 ;
int V_92 ;
V_155 = F_116 ( V_6 -> V_8 , V_151 , V_152 ) ;
if ( V_155 )
return V_155 ;
F_16 ( V_6 ) ;
V_92 = F_117 ( V_6 -> V_8 ) ;
if ( ! ( V_6 -> V_156 & V_157 ) )
goto V_93;
if ( V_153 && ! ( V_6 -> V_156 & V_158 ) )
goto V_93;
V_155 = F_118 ( V_6 , 1 ) ;
if ( V_92 == 0 )
V_92 = V_155 ;
V_93:
F_17 ( V_6 ) ;
return V_92 ;
}
int F_119 ( struct V_27 * V_27 , T_1 V_151 , T_1 V_152 ,
int V_153 )
{
struct V_6 * V_6 = V_27 -> V_154 -> V_111 ;
int V_155 ;
V_155 = F_115 ( V_27 , V_151 , V_152 , V_153 ) ;
if ( V_155 )
return V_155 ;
return F_120 ( V_6 -> V_159 -> V_160 , V_140 , NULL ) ;
}
int F_121 ( unsigned V_161 , T_6 V_162 )
{
T_6 V_163 = V_162 - 1 ;
T_6 V_164 =
V_163 >> ( V_10 - V_161 ) ;
if ( F_75 ( V_162 == 0 ) )
return 0 ;
if ( ( V_161 < 9 ) || ( V_161 > V_10 ) )
return - V_36 ;
if ( ( V_163 > ( V_165 ) ( ~ 0ULL ) >> ( V_161 - 9 ) ) ||
( V_164 > ( T_5 ) ( ~ 0ULL ) ) ) {
return - V_139 ;
}
return 0 ;
}
int F_122 ( struct V_27 * V_27 , T_1 V_151 , T_1 V_152 , int V_153 )
{
return 0 ;
}
void F_123 ( void * V_38 )
{
F_107 ( V_38 ) ;
}
static int F_124 ( struct V_103 * V_103 )
{
return 0 ;
}
struct V_6 * F_125 ( struct V_64 * V_65 )
{
static const struct V_166 V_167 = {
. F_70 = F_124 ,
} ;
struct V_6 * V_6 = F_126 ( V_65 ) ;
if ( ! V_6 )
return F_7 ( - V_32 ) ;
V_6 -> V_52 = F_127 () ;
V_6 -> V_8 -> V_168 = & V_167 ;
V_6 -> V_156 = V_169 ;
V_6 -> V_46 = V_80 | V_81 ;
V_6 -> V_170 = F_128 () ;
V_6 -> V_171 = F_129 () ;
V_6 -> V_172 |= V_173 ;
V_6 -> V_82 = V_6 -> V_83 = V_6 -> V_84 = V_85 ;
return V_6 ;
}
int
F_130 ( struct V_27 * V_53 , long V_174 , struct V_175 * * V_176 ,
void * * V_177 )
{
return - V_36 ;
}
const char * F_131 ( struct V_3 * V_3 , struct V_6 * V_6 ,
struct V_178 * V_179 )
{
return V_6 -> V_180 ;
}
static struct V_3 * F_132 ( struct V_6 * V_20 , struct V_3 * V_3 , unsigned int V_21 )
{
return F_7 ( - V_181 ) ;
}
static int F_133 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
F_3 ( V_6 , V_5 ) ;
return 0 ;
}
static int F_134 ( struct V_3 * V_3 , struct V_99 * V_145 )
{
return - V_182 ;
}
static int F_135 ( struct V_3 * V_3 , const char * V_51 ,
const void * V_183 , T_4 V_137 , int V_21 )
{
return - V_184 ;
}
static T_2 F_136 ( struct V_3 * V_3 , const char * V_51 ,
void * V_183 , T_4 V_137 )
{
return - V_184 ;
}
static int F_137 ( struct V_3 * V_3 , const char * V_51 )
{
return - V_184 ;
}
static T_2 F_138 ( struct V_3 * V_3 , char * V_185 , T_4 V_137 )
{
return - V_184 ;
}
static T_1 F_139 ( struct V_27 * V_27 , T_1 V_33 , int V_34 )
{
return F_140 ( V_27 , V_33 , V_34 , 2 , 2 ) ;
}
static int F_141 ( struct V_27 * V_27 , struct V_47 * V_48 )
{
F_27 ( V_27 , V_48 ) ;
return 0 ;
}
void F_142 ( struct V_6 * V_6 )
{
F_73 ( V_6 , 2 ) ;
V_6 -> V_46 = V_79 | V_186 | V_187 ;
V_6 -> V_170 = V_188 ;
V_6 -> V_171 = V_189 ;
V_6 -> V_190 = 0 ;
V_6 -> V_113 = 0 ;
V_6 -> V_191 = V_74 ;
V_6 -> V_192 = 0 ;
V_6 -> V_117 = & V_193 ;
V_6 -> V_119 = & V_194 ;
}
bool F_143 ( struct V_6 * V_6 )
{
return ( V_6 -> V_119 == & V_194 ) &&
( V_6 -> V_117 == & V_193 ) ;
}
