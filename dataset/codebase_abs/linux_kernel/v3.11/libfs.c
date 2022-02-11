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
if ( ! V_1 -> V_15 -> V_29 )
F_9 ( V_1 , & V_24 ) ;
F_10 ( V_1 , NULL ) ;
return NULL ;
}
int F_11 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
static struct V_31 V_32 = F_12 ( L_1 , 1 ) ;
V_30 -> V_33 = F_13 ( V_30 -> V_34 . V_1 , & V_32 ) ;
return V_30 -> V_33 ? 0 : - V_35 ;
}
int F_14 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
F_15 ( V_30 -> V_33 ) ;
return 0 ;
}
T_1 F_16 ( struct V_30 * V_30 , T_1 V_36 , int V_37 )
{
struct V_1 * V_1 = V_30 -> V_34 . V_1 ;
F_17 ( & V_1 -> V_2 -> V_38 ) ;
switch ( V_37 ) {
case 1 :
V_36 += V_30 -> V_39 ;
case 0 :
if ( V_36 >= 0 )
break;
default:
F_18 ( & V_1 -> V_2 -> V_38 ) ;
return - V_40 ;
}
if ( V_36 != V_30 -> V_39 ) {
V_30 -> V_39 = V_36 ;
if ( V_30 -> V_39 >= 2 ) {
struct V_41 * V_42 ;
struct V_1 * V_43 = V_30 -> V_33 ;
T_1 V_44 = V_30 -> V_39 - 2 ;
F_19 ( & V_1 -> V_45 ) ;
F_20 ( & V_43 -> V_46 . V_47 ) ;
V_42 = V_1 -> V_48 . V_49 ;
while ( V_44 && V_42 != & V_1 -> V_48 ) {
struct V_1 * V_49 ;
V_49 = F_21 ( V_42 , struct V_1 , V_46 . V_47 ) ;
F_22 ( & V_49 -> V_45 , V_50 ) ;
if ( F_1 ( V_49 ) )
V_44 -- ;
F_23 ( & V_49 -> V_45 ) ;
V_42 = V_42 -> V_49 ;
}
F_24 ( & V_43 -> V_46 . V_47 , V_42 ) ;
F_23 ( & V_1 -> V_45 ) ;
}
}
F_18 ( & V_1 -> V_2 -> V_38 ) ;
return V_36 ;
}
static inline unsigned char F_25 ( struct V_7 * V_7 )
{
return ( V_7 -> V_51 >> 12 ) & 15 ;
}
int F_26 ( struct V_30 * V_30 , struct V_52 * V_53 )
{
struct V_1 * V_1 = V_30 -> V_34 . V_1 ;
struct V_1 * V_43 = V_30 -> V_33 ;
struct V_41 * V_42 , * V_54 = & V_43 -> V_46 . V_47 ;
if ( ! F_27 ( V_30 , V_53 ) )
return 0 ;
F_19 ( & V_1 -> V_45 ) ;
if ( V_53 -> V_55 == 2 )
F_28 ( V_54 , & V_1 -> V_48 ) ;
for ( V_42 = V_54 -> V_49 ; V_42 != & V_1 -> V_48 ; V_42 = V_42 -> V_49 ) {
struct V_1 * V_49 = F_21 ( V_42 , struct V_1 , V_46 . V_47 ) ;
F_22 ( & V_49 -> V_45 , V_50 ) ;
if ( ! F_1 ( V_49 ) ) {
F_23 ( & V_49 -> V_45 ) ;
continue;
}
F_23 ( & V_49 -> V_45 ) ;
F_23 ( & V_1 -> V_45 ) ;
if ( ! F_29 ( V_53 , V_49 -> V_26 . V_56 , V_49 -> V_26 . V_27 ,
V_49 -> V_2 -> V_57 , F_25 ( V_49 -> V_2 ) ) )
return 0 ;
F_19 ( & V_1 -> V_45 ) ;
F_22 ( & V_49 -> V_45 , V_50 ) ;
F_28 ( V_54 , V_42 ) ;
F_23 ( & V_49 -> V_45 ) ;
V_42 = V_54 ;
V_53 -> V_55 ++ ;
}
F_23 ( & V_1 -> V_45 ) ;
return 0 ;
}
T_2 F_30 ( struct V_30 * V_58 , char T_3 * V_13 , T_4 V_59 , T_1 * V_60 )
{
return - V_61 ;
}
struct V_1 * F_31 ( struct V_62 * V_63 , char * V_56 ,
const struct V_64 * V_65 ,
const struct V_23 * V_66 , unsigned long V_67 )
{
struct V_68 * V_69 ;
struct V_1 * V_1 ;
struct V_7 * V_70 ;
struct V_31 V_26 = F_12 ( V_56 , strlen ( V_56 ) ) ;
V_69 = F_32 ( V_63 , NULL , V_71 , V_72 , NULL ) ;
if ( F_33 ( V_69 ) )
return F_34 ( V_69 ) ;
V_69 -> V_73 = V_74 ;
V_69 -> V_75 = V_76 ;
V_69 -> V_77 = V_78 ;
V_69 -> V_16 = V_67 ;
V_69 -> V_79 = V_65 ? V_65 : & V_80 ;
V_69 -> V_81 = 1 ;
V_70 = F_35 ( V_69 ) ;
if ( ! V_70 )
goto V_82;
V_70 -> V_57 = 1 ;
V_70 -> V_51 = V_83 | V_84 | V_85 ;
V_70 -> V_86 = V_70 -> V_87 = V_70 -> V_88 = V_89 ;
V_1 = F_36 ( V_69 , & V_26 ) ;
if ( ! V_1 ) {
F_37 ( V_70 ) ;
goto V_82;
}
F_38 ( V_1 , V_70 ) ;
V_69 -> V_90 = V_1 ;
V_69 -> V_29 = V_66 ;
V_69 -> V_91 |= V_92 ;
return F_39 ( V_69 -> V_90 ) ;
V_82:
F_40 ( V_69 ) ;
return F_8 ( - V_35 ) ;
}
int F_41 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
if ( V_7 -> V_93 )
V_30 -> V_33 = V_7 -> V_93 ;
return 0 ;
}
int F_42 ( struct V_1 * V_94 , struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_94 -> V_2 ;
V_7 -> V_88 = V_21 -> V_88 = V_21 -> V_87 = V_89 ;
F_43 ( V_7 ) ;
F_44 ( V_7 ) ;
F_39 ( V_1 ) ;
F_38 ( V_1 , V_7 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_1 )
{
struct V_1 * V_95 ;
int V_96 = 0 ;
F_19 ( & V_1 -> V_45 ) ;
F_46 (child, &dentry->d_subdirs, d_u.d_child) {
F_22 ( & V_95 -> V_45 , V_50 ) ;
if ( F_1 ( V_95 ) ) {
F_23 ( & V_95 -> V_45 ) ;
goto V_97;
}
F_23 ( & V_95 -> V_45 ) ;
}
V_96 = 1 ;
V_97:
F_23 ( & V_1 -> V_45 ) ;
return V_96 ;
}
int F_47 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
V_7 -> V_88 = V_21 -> V_88 = V_21 -> V_87 = V_89 ;
F_48 ( V_7 ) ;
F_15 ( V_1 ) ;
return 0 ;
}
int F_49 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
if ( ! F_45 ( V_1 ) )
return - V_98 ;
F_48 ( V_1 -> V_2 ) ;
F_47 ( V_21 , V_1 ) ;
F_48 ( V_21 ) ;
return 0 ;
}
int F_50 ( struct V_7 * V_99 , struct V_1 * V_94 ,
struct V_7 * V_100 , struct V_1 * V_101 )
{
struct V_7 * V_7 = V_94 -> V_2 ;
int V_102 = F_51 ( V_94 -> V_2 -> V_51 ) ;
if ( ! F_45 ( V_101 ) )
return - V_98 ;
if ( V_101 -> V_2 ) {
F_47 ( V_100 , V_101 ) ;
if ( V_102 ) {
F_48 ( V_101 -> V_2 ) ;
F_48 ( V_99 ) ;
}
} else if ( V_102 ) {
F_48 ( V_99 ) ;
F_43 ( V_100 ) ;
}
V_99 -> V_88 = V_99 -> V_87 = V_100 -> V_88 =
V_100 -> V_87 = V_7 -> V_88 = V_89 ;
return 0 ;
}
int F_52 ( struct V_1 * V_1 , struct V_103 * V_103 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
int error ;
error = F_53 ( V_7 , V_103 ) ;
if ( error )
return error ;
if ( V_103 -> V_104 & V_105 )
F_54 ( V_7 , V_103 -> V_106 ) ;
F_55 ( V_7 , V_103 ) ;
F_56 ( V_7 ) ;
return 0 ;
}
int F_57 ( struct V_30 * V_30 , struct V_107 * V_107 )
{
F_58 ( V_107 ) ;
F_59 ( V_107 ) ;
F_60 ( V_107 ) ;
F_61 ( V_107 ) ;
return 0 ;
}
int F_62 ( struct V_30 * V_30 , struct V_108 * V_109 ,
T_1 V_55 , unsigned V_27 , unsigned V_22 ,
struct V_107 * * V_110 , void * * V_111 )
{
struct V_107 * V_107 ;
T_5 V_112 ;
V_112 = V_55 >> V_11 ;
V_107 = F_63 ( V_109 , V_112 , V_22 ) ;
if ( ! V_107 )
return - V_35 ;
* V_110 = V_107 ;
if ( ! F_64 ( V_107 ) && ( V_27 != V_18 ) ) {
unsigned V_113 = V_55 & ( V_18 - 1 ) ;
F_65 ( V_107 , 0 , V_113 , V_113 + V_27 , V_18 ) ;
}
return 0 ;
}
int F_66 ( struct V_30 * V_30 , struct V_108 * V_109 ,
T_1 V_55 , unsigned V_27 , unsigned V_114 ,
struct V_107 * V_107 , void * V_111 )
{
struct V_7 * V_7 = V_107 -> V_109 -> V_115 ;
T_1 V_116 = V_55 + V_114 ;
if ( V_114 < V_27 ) {
unsigned V_113 = V_55 & ( V_18 - 1 ) ;
F_67 ( V_107 , V_113 + V_114 , V_27 - V_114 ) ;
}
if ( ! F_64 ( V_107 ) )
F_60 ( V_107 ) ;
if ( V_116 > V_7 -> V_117 )
F_68 ( V_7 , V_116 ) ;
F_69 ( V_107 ) ;
F_61 ( V_107 ) ;
F_70 ( V_107 ) ;
return V_114 ;
}
int F_71 ( struct V_68 * V_69 , unsigned long V_67 ,
struct V_118 * V_119 )
{
struct V_7 * V_7 ;
struct V_1 * V_70 ;
struct V_1 * V_1 ;
int V_120 ;
V_69 -> V_75 = V_18 ;
V_69 -> V_77 = V_11 ;
V_69 -> V_16 = V_67 ;
V_69 -> V_79 = & V_80 ;
V_69 -> V_81 = 1 ;
V_7 = F_35 ( V_69 ) ;
if ( ! V_7 )
return - V_35 ;
V_7 -> V_57 = 1 ;
V_7 -> V_51 = V_83 | 0755 ;
V_7 -> V_86 = V_7 -> V_87 = V_7 -> V_88 = V_89 ;
V_7 -> V_121 = & V_122 ;
V_7 -> V_123 = & V_124 ;
F_72 ( V_7 , 2 ) ;
V_70 = F_73 ( V_7 ) ;
if ( ! V_70 )
return - V_35 ;
for ( V_120 = 0 ; ! V_119 -> V_56 || V_119 -> V_56 [ 0 ] ; V_120 ++ , V_119 ++ ) {
if ( ! V_119 -> V_56 )
continue;
if ( F_74 ( V_120 == 1 ) )
F_75 ( V_125 L_2
L_3 , V_126 ,
V_69 -> V_127 -> V_56 ) ;
V_1 = F_76 ( V_70 , V_119 -> V_56 ) ;
if ( ! V_1 )
goto V_97;
V_7 = F_35 ( V_69 ) ;
if ( ! V_7 ) {
F_15 ( V_1 ) ;
goto V_97;
}
V_7 -> V_51 = V_128 | V_119 -> V_129 ;
V_7 -> V_86 = V_7 -> V_87 = V_7 -> V_88 = V_89 ;
V_7 -> V_123 = V_119 -> V_65 ;
V_7 -> V_57 = V_120 ;
F_10 ( V_1 , V_7 ) ;
}
V_69 -> V_90 = V_70 ;
return 0 ;
V_97:
F_77 ( V_70 ) ;
F_78 ( V_70 ) ;
F_15 ( V_70 ) ;
return - V_35 ;
}
int F_79 ( struct V_62 * type , struct V_3 * * V_130 , int * V_131 )
{
struct V_3 * V_4 = NULL ;
F_19 ( & V_132 ) ;
if ( F_74 ( ! * V_130 ) ) {
F_23 ( & V_132 ) ;
V_4 = F_80 ( type , V_133 , type -> V_56 , NULL ) ;
if ( F_33 ( V_4 ) )
return F_81 ( V_4 ) ;
F_19 ( & V_132 ) ;
if ( ! * V_130 )
* V_130 = V_4 ;
}
F_82 ( * V_130 ) ;
++ * V_131 ;
F_23 ( & V_132 ) ;
F_83 ( V_4 ) ;
return 0 ;
}
void F_84 ( struct V_3 * * V_130 , int * V_131 )
{
struct V_3 * V_4 ;
F_19 ( & V_132 ) ;
V_4 = * V_130 ;
if ( ! -- * V_131 )
* V_130 = NULL ;
F_23 ( & V_132 ) ;
F_83 ( V_4 ) ;
}
T_2 F_85 ( void T_3 * V_134 , T_4 V_131 , T_1 * V_60 ,
const void * V_113 , T_4 V_135 )
{
T_1 V_55 = * V_60 ;
T_4 V_96 ;
if ( V_55 < 0 )
return - V_40 ;
if ( V_55 >= V_135 || ! V_131 )
return 0 ;
if ( V_131 > V_135 - V_55 )
V_131 = V_135 - V_55 ;
V_96 = F_86 ( V_134 , V_113 + V_55 , V_131 ) ;
if ( V_96 == V_131 )
return - V_136 ;
V_131 -= V_96 ;
* V_60 = V_55 + V_131 ;
return V_131 ;
}
T_2 F_87 ( void * V_134 , T_4 V_135 , T_1 * V_60 ,
const void T_3 * V_113 , T_4 V_131 )
{
T_1 V_55 = * V_60 ;
T_4 V_137 ;
if ( V_55 < 0 )
return - V_40 ;
if ( V_55 >= V_135 || ! V_131 )
return 0 ;
if ( V_131 > V_135 - V_55 )
V_131 = V_135 - V_55 ;
V_137 = F_88 ( V_134 + V_55 , V_113 , V_131 ) ;
if ( V_137 == V_131 )
return - V_136 ;
V_131 -= V_137 ;
* V_60 = V_55 + V_131 ;
return V_131 ;
}
T_2 F_89 ( void * V_134 , T_4 V_131 , T_1 * V_60 ,
const void * V_113 , T_4 V_135 )
{
T_1 V_55 = * V_60 ;
if ( V_55 < 0 )
return - V_40 ;
if ( V_55 >= V_135 )
return 0 ;
if ( V_131 > V_135 - V_55 )
V_131 = V_135 - V_55 ;
memcpy ( V_134 , V_113 + V_55 , V_131 ) ;
* V_60 = V_55 + V_131 ;
return V_131 ;
}
void F_90 ( struct V_30 * V_30 , T_4 V_44 )
{
struct V_138 * V_139 = V_30 -> V_33 ;
F_91 ( V_44 > V_140 ) ;
F_92 () ;
V_139 -> V_141 = V_44 ;
}
char * F_93 ( struct V_30 * V_30 , const char T_3 * V_13 , T_4 V_141 )
{
struct V_138 * V_139 ;
static F_94 ( V_142 ) ;
if ( V_141 > V_140 - 1 )
return F_8 ( - V_143 ) ;
V_139 = (struct V_138 * ) F_95 ( V_144 ) ;
if ( ! V_139 )
return F_8 ( - V_35 ) ;
F_19 ( & V_142 ) ;
if ( V_30 -> V_33 ) {
F_23 ( & V_142 ) ;
F_96 ( ( unsigned long ) V_139 ) ;
return F_8 ( - V_145 ) ;
}
V_30 -> V_33 = V_139 ;
F_23 ( & V_142 ) ;
if ( F_88 ( V_139 -> V_146 , V_13 , V_141 ) )
return F_8 ( - V_136 ) ;
return V_139 -> V_146 ;
}
T_2 F_97 ( struct V_30 * V_30 , char T_3 * V_13 , T_4 V_141 , T_1 * V_55 )
{
struct V_138 * V_139 = V_30 -> V_33 ;
if ( ! V_139 )
return 0 ;
return F_85 ( V_13 , V_141 , V_55 , V_139 -> V_146 , V_139 -> V_141 ) ;
}
int F_98 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
F_96 ( ( unsigned long ) V_30 -> V_33 ) ;
return 0 ;
}
int F_99 ( struct V_7 * V_7 , struct V_30 * V_30 ,
int (* F_100)( void * , T_6 * ) , int (* F_101)( void * , T_6 ) ,
const char * V_147 )
{
struct V_148 * V_149 ;
V_149 = F_102 ( sizeof( * V_149 ) , V_144 ) ;
if ( ! V_149 )
return - V_35 ;
V_149 -> F_100 = F_100 ;
V_149 -> F_101 = F_101 ;
V_149 -> V_146 = V_7 -> V_93 ;
V_149 -> V_147 = V_147 ;
F_103 ( & V_149 -> V_150 ) ;
V_30 -> V_33 = V_149 ;
return F_104 ( V_7 , V_30 ) ;
}
int F_105 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
F_106 ( V_30 -> V_33 ) ;
return 0 ;
}
T_2 F_107 ( struct V_30 * V_30 , char T_3 * V_13 ,
T_4 V_27 , T_1 * V_60 )
{
struct V_148 * V_149 ;
T_4 V_141 ;
T_2 V_96 ;
V_149 = V_30 -> V_33 ;
if ( ! V_149 -> F_100 )
return - V_151 ;
V_96 = F_108 ( & V_149 -> V_150 ) ;
if ( V_96 )
return V_96 ;
if ( * V_60 ) {
V_141 = strlen ( V_149 -> V_152 ) ;
} else {
T_6 V_153 ;
V_96 = V_149 -> F_100 ( V_149 -> V_146 , & V_153 ) ;
if ( V_96 )
goto V_97;
V_141 = F_109 ( V_149 -> V_152 , sizeof( V_149 -> V_152 ) ,
V_149 -> V_147 , ( unsigned long long ) V_153 ) ;
}
V_96 = F_85 ( V_13 , V_27 , V_60 , V_149 -> V_152 , V_141 ) ;
V_97:
F_18 ( & V_149 -> V_150 ) ;
return V_96 ;
}
T_2 F_110 ( struct V_30 * V_30 , const char T_3 * V_13 ,
T_4 V_27 , T_1 * V_60 )
{
struct V_148 * V_149 ;
T_6 V_153 ;
T_4 V_141 ;
T_2 V_96 ;
V_149 = V_30 -> V_33 ;
if ( ! V_149 -> F_101 )
return - V_151 ;
V_96 = F_108 ( & V_149 -> V_150 ) ;
if ( V_96 )
return V_96 ;
V_96 = - V_136 ;
V_141 = F_111 ( sizeof( V_149 -> V_154 ) - 1 , V_27 ) ;
if ( F_88 ( V_149 -> V_154 , V_13 , V_141 ) )
goto V_97;
V_149 -> V_154 [ V_141 ] = '\0' ;
V_153 = F_112 ( V_149 -> V_154 , NULL , 0 ) ;
V_96 = V_149 -> F_101 ( V_149 -> V_146 , V_153 ) ;
if ( V_96 == 0 )
V_96 = V_27 ;
V_97:
F_18 ( & V_149 -> V_150 ) ;
return V_96 ;
}
int F_113 ( struct V_30 * V_30 , T_1 V_155 , T_1 V_156 ,
int V_157 )
{
struct V_7 * V_7 = V_30 -> V_158 -> V_115 ;
int V_159 ;
int V_96 ;
V_159 = F_114 ( V_7 -> V_9 , V_155 , V_156 ) ;
if ( V_159 )
return V_159 ;
F_17 ( & V_7 -> V_38 ) ;
V_96 = F_115 ( V_7 -> V_9 ) ;
if ( ! ( V_7 -> V_160 & V_161 ) )
goto V_97;
if ( V_157 && ! ( V_7 -> V_160 & V_162 ) )
goto V_97;
V_159 = F_116 ( V_7 , 1 ) ;
if ( V_96 == 0 )
V_96 = V_159 ;
V_97:
F_18 ( & V_7 -> V_38 ) ;
return V_96 ;
}
int F_117 ( unsigned V_163 , T_6 V_164 )
{
T_6 V_165 = V_164 - 1 ;
T_6 V_166 =
V_165 >> ( V_11 - V_163 ) ;
if ( F_74 ( V_164 == 0 ) )
return 0 ;
if ( ( V_163 < 9 ) || ( V_163 > V_11 ) )
return - V_40 ;
if ( ( V_165 > ( V_167 ) ( ~ 0ULL ) >> ( V_163 - 9 ) ) ||
( V_166 > ( T_5 ) ( ~ 0ULL ) ) ) {
return - V_143 ;
}
return 0 ;
}
int F_118 ( struct V_30 * V_30 , T_1 V_155 , T_1 V_156 , int V_157 )
{
return 0 ;
}
