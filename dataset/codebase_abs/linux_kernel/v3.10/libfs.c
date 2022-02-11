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
error = F_52 ( V_7 , V_105 ) ;
if ( error )
return error ;
if ( V_105 -> V_106 & V_107 )
F_53 ( V_7 , V_105 -> V_108 ) ;
F_54 ( V_7 , V_105 ) ;
F_55 ( V_7 ) ;
return 0 ;
}
int F_56 ( struct V_29 * V_29 , struct V_109 * V_109 )
{
F_57 ( V_109 ) ;
F_58 ( V_109 ) ;
F_59 ( V_109 ) ;
F_60 ( V_109 ) ;
return 0 ;
}
int F_61 ( struct V_29 * V_29 , struct V_110 * V_111 ,
T_1 V_112 , unsigned V_27 , unsigned V_22 ,
struct V_109 * * V_113 , void * * V_114 )
{
struct V_109 * V_109 ;
T_7 V_115 ;
V_115 = V_112 >> V_11 ;
V_109 = F_62 ( V_111 , V_115 , V_22 ) ;
if ( ! V_109 )
return - V_34 ;
* V_113 = V_109 ;
if ( ! F_63 ( V_109 ) && ( V_27 != V_18 ) ) {
unsigned V_116 = V_112 & ( V_18 - 1 ) ;
F_64 ( V_109 , 0 , V_116 , V_116 + V_27 , V_18 ) ;
}
return 0 ;
}
int F_65 ( struct V_29 * V_29 , struct V_110 * V_111 ,
T_1 V_112 , unsigned V_27 , unsigned V_117 ,
struct V_109 * V_109 , void * V_114 )
{
struct V_7 * V_7 = V_109 -> V_111 -> V_118 ;
T_1 V_119 = V_112 + V_117 ;
if ( V_117 < V_27 ) {
unsigned V_116 = V_112 & ( V_18 - 1 ) ;
F_66 ( V_109 , V_116 + V_117 , V_27 - V_117 ) ;
}
if ( ! F_63 ( V_109 ) )
F_59 ( V_109 ) ;
if ( V_119 > V_7 -> V_120 )
F_67 ( V_7 , V_119 ) ;
F_68 ( V_109 ) ;
F_60 ( V_109 ) ;
F_69 ( V_109 ) ;
return V_117 ;
}
int F_70 ( struct V_69 * V_70 , unsigned long V_68 ,
struct V_121 * V_122 )
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
V_7 -> V_123 = & V_124 ;
V_7 -> V_125 = & V_126 ;
F_71 ( V_7 , 2 ) ;
V_71 = F_72 ( V_7 ) ;
if ( ! V_71 )
return - V_34 ;
for ( V_56 = 0 ; ! V_122 -> V_59 || V_122 -> V_59 [ 0 ] ; V_56 ++ , V_122 ++ ) {
if ( ! V_122 -> V_59 )
continue;
if ( F_73 ( V_56 == 1 ) )
F_74 ( V_127 L_3
L_4 , V_128 ,
V_70 -> V_129 -> V_59 ) ;
V_1 = F_75 ( V_71 , V_122 -> V_59 ) ;
if ( ! V_1 )
goto V_99;
V_7 = F_34 ( V_70 ) ;
if ( ! V_7 ) {
F_15 ( V_1 ) ;
goto V_99;
}
V_7 -> V_50 = V_130 | V_122 -> V_131 ;
V_7 -> V_87 = V_7 -> V_88 = V_7 -> V_89 = V_90 ;
V_7 -> V_125 = V_122 -> V_66 ;
V_7 -> V_57 = V_56 ;
F_10 ( V_1 , V_7 ) ;
}
V_70 -> V_91 = V_71 ;
return 0 ;
V_99:
F_76 ( V_71 ) ;
F_77 ( V_71 ) ;
F_15 ( V_71 ) ;
return - V_34 ;
}
int F_78 ( struct V_63 * type , struct V_3 * * V_132 , int * V_133 )
{
struct V_3 * V_4 = NULL ;
F_19 ( & V_134 ) ;
if ( F_73 ( ! * V_132 ) ) {
F_23 ( & V_134 ) ;
V_4 = F_79 ( type , V_135 , type -> V_59 , NULL ) ;
if ( F_32 ( V_4 ) )
return F_80 ( V_4 ) ;
F_19 ( & V_134 ) ;
if ( ! * V_132 )
* V_132 = V_4 ;
}
F_81 ( * V_132 ) ;
++ * V_133 ;
F_23 ( & V_134 ) ;
F_82 ( V_4 ) ;
return 0 ;
}
void F_83 ( struct V_3 * * V_132 , int * V_133 )
{
struct V_3 * V_4 ;
F_19 ( & V_134 ) ;
V_4 = * V_132 ;
if ( ! -- * V_133 )
* V_132 = NULL ;
F_23 ( & V_134 ) ;
F_82 ( V_4 ) ;
}
T_4 F_84 ( void T_5 * V_136 , T_6 V_133 , T_1 * V_61 ,
const void * V_116 , T_6 V_137 )
{
T_1 V_112 = * V_61 ;
T_6 V_98 ;
if ( V_112 < 0 )
return - V_39 ;
if ( V_112 >= V_137 || ! V_133 )
return 0 ;
if ( V_133 > V_137 - V_112 )
V_133 = V_137 - V_112 ;
V_98 = F_85 ( V_136 , V_116 + V_112 , V_133 ) ;
if ( V_98 == V_133 )
return - V_138 ;
V_133 -= V_98 ;
* V_61 = V_112 + V_133 ;
return V_133 ;
}
T_4 F_86 ( void * V_136 , T_6 V_137 , T_1 * V_61 ,
const void T_5 * V_116 , T_6 V_133 )
{
T_1 V_112 = * V_61 ;
T_6 V_139 ;
if ( V_112 < 0 )
return - V_39 ;
if ( V_112 >= V_137 || ! V_133 )
return 0 ;
if ( V_133 > V_137 - V_112 )
V_133 = V_137 - V_112 ;
V_139 = F_87 ( V_136 + V_112 , V_116 , V_133 ) ;
if ( V_139 == V_133 )
return - V_138 ;
V_133 -= V_139 ;
* V_61 = V_112 + V_133 ;
return V_133 ;
}
T_4 F_88 ( void * V_136 , T_6 V_133 , T_1 * V_61 ,
const void * V_116 , T_6 V_137 )
{
T_1 V_112 = * V_61 ;
if ( V_112 < 0 )
return - V_39 ;
if ( V_112 >= V_137 )
return 0 ;
if ( V_133 > V_137 - V_112 )
V_133 = V_137 - V_112 ;
memcpy ( V_136 , V_116 + V_112 , V_133 ) ;
* V_61 = V_112 + V_133 ;
return V_133 ;
}
void F_89 ( struct V_29 * V_29 , T_6 V_43 )
{
struct V_140 * V_141 = V_29 -> V_32 ;
F_90 ( V_43 > V_142 ) ;
F_91 () ;
V_141 -> V_143 = V_43 ;
}
char * F_92 ( struct V_29 * V_29 , const char T_5 * V_13 , T_6 V_143 )
{
struct V_140 * V_141 ;
static F_93 ( V_144 ) ;
if ( V_143 > V_142 - 1 )
return F_8 ( - V_145 ) ;
V_141 = (struct V_140 * ) F_94 ( V_146 ) ;
if ( ! V_141 )
return F_8 ( - V_34 ) ;
F_19 ( & V_144 ) ;
if ( V_29 -> V_32 ) {
F_23 ( & V_144 ) ;
F_95 ( ( unsigned long ) V_141 ) ;
return F_8 ( - V_147 ) ;
}
V_29 -> V_32 = V_141 ;
F_23 ( & V_144 ) ;
if ( F_87 ( V_141 -> V_148 , V_13 , V_143 ) )
return F_8 ( - V_138 ) ;
return V_141 -> V_148 ;
}
T_4 F_96 ( struct V_29 * V_29 , char T_5 * V_13 , T_6 V_143 , T_1 * V_112 )
{
struct V_140 * V_141 = V_29 -> V_32 ;
if ( ! V_141 )
return 0 ;
return F_84 ( V_13 , V_143 , V_112 , V_141 -> V_148 , V_141 -> V_143 ) ;
}
int F_97 ( struct V_7 * V_7 , struct V_29 * V_29 )
{
F_95 ( ( unsigned long ) V_29 -> V_32 ) ;
return 0 ;
}
int F_98 ( struct V_7 * V_7 , struct V_29 * V_29 ,
int (* F_99)( void * , T_8 * ) , int (* F_100)( void * , T_8 ) ,
const char * V_149 )
{
struct V_150 * V_151 ;
V_151 = F_101 ( sizeof( * V_151 ) , V_146 ) ;
if ( ! V_151 )
return - V_34 ;
V_151 -> F_99 = F_99 ;
V_151 -> F_100 = F_100 ;
V_151 -> V_148 = V_7 -> V_95 ;
V_151 -> V_149 = V_149 ;
F_102 ( & V_151 -> V_152 ) ;
V_29 -> V_32 = V_151 ;
return F_103 ( V_7 , V_29 ) ;
}
int F_104 ( struct V_7 * V_7 , struct V_29 * V_29 )
{
F_105 ( V_29 -> V_32 ) ;
return 0 ;
}
T_4 F_106 ( struct V_29 * V_29 , char T_5 * V_13 ,
T_6 V_27 , T_1 * V_61 )
{
struct V_150 * V_151 ;
T_6 V_143 ;
T_4 V_98 ;
V_151 = V_29 -> V_32 ;
if ( ! V_151 -> F_99 )
return - V_153 ;
V_98 = F_107 ( & V_151 -> V_152 ) ;
if ( V_98 )
return V_98 ;
if ( * V_61 ) {
V_143 = strlen ( V_151 -> V_154 ) ;
} else {
T_8 V_155 ;
V_98 = V_151 -> F_99 ( V_151 -> V_148 , & V_155 ) ;
if ( V_98 )
goto V_99;
V_143 = F_108 ( V_151 -> V_154 , sizeof( V_151 -> V_154 ) ,
V_151 -> V_149 , ( unsigned long long ) V_155 ) ;
}
V_98 = F_84 ( V_13 , V_27 , V_61 , V_151 -> V_154 , V_143 ) ;
V_99:
F_18 ( & V_151 -> V_152 ) ;
return V_98 ;
}
T_4 F_109 ( struct V_29 * V_29 , const char T_5 * V_13 ,
T_6 V_27 , T_1 * V_61 )
{
struct V_150 * V_151 ;
T_8 V_155 ;
T_6 V_143 ;
T_4 V_98 ;
V_151 = V_29 -> V_32 ;
if ( ! V_151 -> F_100 )
return - V_153 ;
V_98 = F_107 ( & V_151 -> V_152 ) ;
if ( V_98 )
return V_98 ;
V_98 = - V_138 ;
V_143 = F_110 ( sizeof( V_151 -> V_156 ) - 1 , V_27 ) ;
if ( F_87 ( V_151 -> V_156 , V_13 , V_143 ) )
goto V_99;
V_151 -> V_156 [ V_143 ] = '\0' ;
V_155 = F_111 ( V_151 -> V_156 , NULL , 0 ) ;
V_98 = V_151 -> F_100 ( V_151 -> V_148 , V_155 ) ;
if ( V_98 == 0 )
V_98 = V_27 ;
V_99:
F_18 ( & V_151 -> V_152 ) ;
return V_98 ;
}
int F_112 ( struct V_29 * V_29 , T_1 V_157 , T_1 V_158 ,
int V_159 )
{
struct V_7 * V_7 = V_29 -> V_160 -> V_118 ;
int V_161 ;
int V_98 ;
V_161 = F_113 ( V_7 -> V_9 , V_157 , V_158 ) ;
if ( V_161 )
return V_161 ;
F_17 ( & V_7 -> V_37 ) ;
V_98 = F_114 ( V_7 -> V_9 ) ;
if ( ! ( V_7 -> V_162 & V_163 ) )
goto V_99;
if ( V_159 && ! ( V_7 -> V_162 & V_164 ) )
goto V_99;
V_161 = F_115 ( V_7 , 1 ) ;
if ( V_98 == 0 )
V_98 = V_161 ;
V_99:
F_18 ( & V_7 -> V_37 ) ;
return V_98 ;
}
int F_116 ( unsigned V_165 , T_8 V_166 )
{
T_8 V_167 = V_166 - 1 ;
T_8 V_168 =
V_167 >> ( V_11 - V_165 ) ;
if ( F_73 ( V_166 == 0 ) )
return 0 ;
if ( ( V_165 < 9 ) || ( V_165 > V_11 ) )
return - V_39 ;
if ( ( V_167 > ( V_169 ) ( ~ 0ULL ) >> ( V_165 - 9 ) ) ||
( V_168 > ( T_7 ) ( ~ 0ULL ) ) ) {
return - V_145 ;
}
return 0 ;
}
int F_117 ( struct V_29 * V_29 , T_1 V_157 , T_1 V_158 , int V_159 )
{
return 0 ;
}
