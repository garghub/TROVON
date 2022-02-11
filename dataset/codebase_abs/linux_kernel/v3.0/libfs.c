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
V_1 = F_12 ( NULL , & V_27 ) ;
if ( ! V_1 ) {
F_34 ( V_73 ) ;
goto V_85;
}
V_1 -> V_15 = V_71 ;
V_1 -> V_93 = V_1 ;
F_35 ( V_1 , V_73 ) ;
V_71 -> V_94 = V_1 ;
V_71 -> V_95 = V_68 ;
V_71 -> V_74 |= V_96 ;
return F_36 ( V_71 -> V_94 ) ;
V_85:
F_37 ( V_71 ) ;
return F_8 ( - V_36 ) ;
}
int F_38 ( struct V_1 * V_97 , struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_97 -> V_2 ;
V_7 -> V_91 = V_21 -> V_91 = V_21 -> V_90 = V_92 ;
F_39 ( V_7 ) ;
F_40 ( V_7 ) ;
F_36 ( V_1 ) ;
F_35 ( V_1 , V_7 ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_1 )
{
struct V_1 * V_98 ;
int V_99 = 0 ;
F_18 ( & V_1 -> V_46 ) ;
F_42 (child, &dentry->d_subdirs, d_u.d_child) {
F_21 ( & V_98 -> V_46 , V_51 ) ;
if ( F_1 ( V_98 ) ) {
F_22 ( & V_98 -> V_46 ) ;
goto V_100;
}
F_22 ( & V_98 -> V_46 ) ;
}
V_99 = 1 ;
V_100:
F_22 ( & V_1 -> V_46 ) ;
return V_99 ;
}
int F_43 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
V_7 -> V_91 = V_21 -> V_91 = V_21 -> V_90 = V_92 ;
F_44 ( V_7 ) ;
F_14 ( V_1 ) ;
return 0 ;
}
int F_45 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
if ( ! F_41 ( V_1 ) )
return - V_101 ;
F_44 ( V_1 -> V_2 ) ;
F_43 ( V_21 , V_1 ) ;
F_44 ( V_21 ) ;
return 0 ;
}
int F_46 ( struct V_7 * V_102 , struct V_1 * V_97 ,
struct V_7 * V_103 , struct V_1 * V_104 )
{
struct V_7 * V_7 = V_97 -> V_2 ;
int V_105 = F_47 ( V_97 -> V_2 -> V_52 ) ;
if ( ! F_41 ( V_104 ) )
return - V_101 ;
if ( V_104 -> V_2 ) {
F_43 ( V_103 , V_104 ) ;
if ( V_105 )
F_44 ( V_102 ) ;
} else if ( V_105 ) {
F_44 ( V_102 ) ;
F_39 ( V_103 ) ;
}
V_102 -> V_91 = V_102 -> V_90 = V_103 -> V_91 =
V_103 -> V_90 = V_7 -> V_91 = V_92 ;
return 0 ;
}
int F_48 ( struct V_1 * V_1 , struct V_106 * V_106 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
int error ;
F_49 ( V_7 -> V_107 -> V_108 ) ;
error = F_50 ( V_7 , V_106 ) ;
if ( error )
return error ;
if ( V_106 -> V_109 & V_110 )
F_51 ( V_7 , V_106 -> V_111 ) ;
F_52 ( V_7 , V_106 ) ;
F_53 ( V_7 ) ;
return 0 ;
}
int F_54 ( struct V_30 * V_30 , struct V_112 * V_112 )
{
F_55 ( V_112 ) ;
F_56 ( V_112 ) ;
F_57 ( V_112 ) ;
F_58 ( V_112 ) ;
return 0 ;
}
int F_59 ( struct V_30 * V_30 , struct V_113 * V_114 ,
T_1 V_115 , unsigned V_28 , unsigned V_116 ,
struct V_112 * * V_117 , void * * V_118 )
{
struct V_112 * V_112 ;
T_7 V_119 ;
V_119 = V_115 >> V_11 ;
V_112 = F_60 ( V_114 , V_119 , V_116 ) ;
if ( ! V_112 )
return - V_36 ;
* V_117 = V_112 ;
if ( ! F_61 ( V_112 ) && ( V_28 != V_18 ) ) {
unsigned V_120 = V_115 & ( V_18 - 1 ) ;
F_62 ( V_112 , 0 , V_120 , V_120 + V_28 , V_18 ) ;
}
return 0 ;
}
int F_63 ( struct V_30 * V_30 , struct V_113 * V_114 ,
T_1 V_115 , unsigned V_28 , unsigned V_121 ,
struct V_112 * V_112 , void * V_118 )
{
struct V_7 * V_7 = V_112 -> V_114 -> V_122 ;
T_1 V_123 = V_115 + V_121 ;
if ( V_121 < V_28 ) {
unsigned V_120 = V_115 & ( V_18 - 1 ) ;
F_64 ( V_112 , V_120 + V_121 , V_28 - V_121 ) ;
}
if ( ! F_61 ( V_112 ) )
F_57 ( V_112 ) ;
if ( V_123 > V_7 -> V_124 )
F_65 ( V_7 , V_123 ) ;
F_66 ( V_112 ) ;
F_58 ( V_112 ) ;
F_67 ( V_112 ) ;
return V_121 ;
}
int F_68 ( struct V_70 * V_71 , unsigned long V_69 ,
struct V_125 * V_126 )
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
V_7 -> V_107 = & V_127 ;
V_7 -> V_128 = & V_129 ;
V_7 -> V_130 = 2 ;
V_73 = F_69 ( V_7 ) ;
if ( ! V_73 ) {
F_34 ( V_7 ) ;
return - V_36 ;
}
for ( V_58 = 0 ; ! V_126 -> V_33 || V_126 -> V_33 [ 0 ] ; V_58 ++ , V_126 ++ ) {
if ( ! V_126 -> V_33 )
continue;
if ( F_70 ( V_58 == 1 ) )
F_71 ( V_131 L_3
L_4 , V_132 ,
V_71 -> V_133 -> V_33 ) ;
V_1 = F_72 ( V_73 , V_126 -> V_33 ) ;
if ( ! V_1 )
goto V_100;
V_7 = F_33 ( V_71 ) ;
if ( ! V_7 )
goto V_100;
V_7 -> V_52 = V_134 | V_126 -> V_135 ;
V_7 -> V_89 = V_7 -> V_90 = V_7 -> V_91 = V_92 ;
V_7 -> V_128 = V_126 -> V_67 ;
V_7 -> V_59 = V_58 ;
F_10 ( V_1 , V_7 ) ;
}
V_71 -> V_94 = V_73 ;
return 0 ;
V_100:
F_73 ( V_73 ) ;
F_14 ( V_73 ) ;
return - V_36 ;
}
int F_74 ( struct V_64 * type , struct V_3 * * V_136 , int * V_137 )
{
struct V_3 * V_4 = NULL ;
F_18 ( & V_138 ) ;
if ( F_70 ( ! * V_136 ) ) {
F_22 ( & V_138 ) ;
V_4 = F_75 ( type , 0 , type -> V_33 , NULL ) ;
if ( F_31 ( V_4 ) )
return F_76 ( V_4 ) ;
F_18 ( & V_138 ) ;
if ( ! * V_136 )
* V_136 = V_4 ;
}
F_77 ( * V_136 ) ;
++ * V_137 ;
F_22 ( & V_138 ) ;
F_78 ( V_4 ) ;
return 0 ;
}
void F_79 ( struct V_3 * * V_136 , int * V_137 )
{
struct V_3 * V_4 ;
F_18 ( & V_138 ) ;
V_4 = * V_136 ;
if ( ! -- * V_137 )
* V_136 = NULL ;
F_22 ( & V_138 ) ;
F_78 ( V_4 ) ;
}
T_4 F_80 ( void T_5 * V_139 , T_6 V_137 , T_1 * V_62 ,
const void * V_120 , T_6 V_140 )
{
T_1 V_115 = * V_62 ;
T_6 V_99 ;
if ( V_115 < 0 )
return - V_41 ;
if ( V_115 >= V_140 || ! V_137 )
return 0 ;
if ( V_137 > V_140 - V_115 )
V_137 = V_140 - V_115 ;
V_99 = F_81 ( V_139 , V_120 + V_115 , V_137 ) ;
if ( V_99 == V_137 )
return - V_141 ;
V_137 -= V_99 ;
* V_62 = V_115 + V_137 ;
return V_137 ;
}
T_4 F_82 ( void * V_139 , T_6 V_140 , T_1 * V_62 ,
const void T_5 * V_120 , T_6 V_137 )
{
T_1 V_115 = * V_62 ;
T_6 V_142 ;
if ( V_115 < 0 )
return - V_41 ;
if ( V_115 >= V_140 || ! V_137 )
return 0 ;
if ( V_137 > V_140 - V_115 )
V_137 = V_140 - V_115 ;
V_142 = F_83 ( V_139 + V_115 , V_120 , V_137 ) ;
if ( V_142 == V_137 )
return - V_141 ;
V_137 -= V_142 ;
* V_62 = V_115 + V_137 ;
return V_137 ;
}
T_4 F_84 ( void * V_139 , T_6 V_137 , T_1 * V_62 ,
const void * V_120 , T_6 V_140 )
{
T_1 V_115 = * V_62 ;
if ( V_115 < 0 )
return - V_41 ;
if ( V_115 >= V_140 )
return 0 ;
if ( V_137 > V_140 - V_115 )
V_137 = V_140 - V_115 ;
memcpy ( V_139 , V_120 + V_115 , V_137 ) ;
* V_62 = V_115 + V_137 ;
return V_137 ;
}
void F_85 ( struct V_30 * V_30 , T_6 V_45 )
{
struct V_143 * V_144 = V_30 -> V_34 ;
F_86 ( V_45 > V_145 ) ;
F_87 () ;
V_144 -> V_146 = V_45 ;
}
char * F_88 ( struct V_30 * V_30 , const char T_5 * V_13 , T_6 V_146 )
{
struct V_143 * V_144 ;
static F_89 ( V_147 ) ;
if ( V_146 > V_145 - 1 )
return F_8 ( - V_148 ) ;
V_144 = (struct V_143 * ) F_90 ( V_149 ) ;
if ( ! V_144 )
return F_8 ( - V_36 ) ;
F_18 ( & V_147 ) ;
if ( V_30 -> V_34 ) {
F_22 ( & V_147 ) ;
F_91 ( ( unsigned long ) V_144 ) ;
return F_8 ( - V_150 ) ;
}
V_30 -> V_34 = V_144 ;
F_22 ( & V_147 ) ;
if ( F_83 ( V_144 -> V_151 , V_13 , V_146 ) )
return F_8 ( - V_141 ) ;
return V_144 -> V_151 ;
}
T_4 F_92 ( struct V_30 * V_30 , char T_5 * V_13 , T_6 V_146 , T_1 * V_115 )
{
struct V_143 * V_144 = V_30 -> V_34 ;
if ( ! V_144 )
return 0 ;
return F_80 ( V_13 , V_146 , V_115 , V_144 -> V_151 , V_144 -> V_146 ) ;
}
int F_93 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
F_91 ( ( unsigned long ) V_30 -> V_34 ) ;
return 0 ;
}
int F_94 ( struct V_7 * V_7 , struct V_30 * V_30 ,
int (* F_95)( void * , T_8 * ) , int (* F_96)( void * , T_8 ) ,
const char * V_152 )
{
struct V_153 * V_154 ;
V_154 = F_97 ( sizeof( * V_154 ) , V_149 ) ;
if ( ! V_154 )
return - V_36 ;
V_154 -> F_95 = F_95 ;
V_154 -> F_96 = F_96 ;
V_154 -> V_151 = V_7 -> V_155 ;
V_154 -> V_152 = V_152 ;
F_98 ( & V_154 -> V_156 ) ;
V_30 -> V_34 = V_154 ;
return F_99 ( V_7 , V_30 ) ;
}
int F_100 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
F_101 ( V_30 -> V_34 ) ;
return 0 ;
}
T_4 F_102 ( struct V_30 * V_30 , char T_5 * V_13 ,
T_6 V_28 , T_1 * V_62 )
{
struct V_153 * V_154 ;
T_6 V_146 ;
T_4 V_99 ;
V_154 = V_30 -> V_34 ;
if ( ! V_154 -> F_95 )
return - V_157 ;
V_99 = F_103 ( & V_154 -> V_156 ) ;
if ( V_99 )
return V_99 ;
if ( * V_62 ) {
V_146 = strlen ( V_154 -> V_158 ) ;
} else {
T_8 V_159 ;
V_99 = V_154 -> F_95 ( V_154 -> V_151 , & V_159 ) ;
if ( V_99 )
goto V_100;
V_146 = F_104 ( V_154 -> V_158 , sizeof( V_154 -> V_158 ) ,
V_154 -> V_152 , ( unsigned long long ) V_159 ) ;
}
V_99 = F_80 ( V_13 , V_28 , V_62 , V_154 -> V_158 , V_146 ) ;
V_100:
F_17 ( & V_154 -> V_156 ) ;
return V_99 ;
}
T_4 F_105 ( struct V_30 * V_30 , const char T_5 * V_13 ,
T_6 V_28 , T_1 * V_62 )
{
struct V_153 * V_154 ;
T_8 V_159 ;
T_6 V_146 ;
T_4 V_99 ;
V_154 = V_30 -> V_34 ;
if ( ! V_154 -> F_96 )
return - V_157 ;
V_99 = F_103 ( & V_154 -> V_156 ) ;
if ( V_99 )
return V_99 ;
V_99 = - V_141 ;
V_146 = F_106 ( sizeof( V_154 -> V_160 ) - 1 , V_28 ) ;
if ( F_83 ( V_154 -> V_160 , V_13 , V_146 ) )
goto V_100;
V_154 -> V_160 [ V_146 ] = '\0' ;
V_159 = F_107 ( V_154 -> V_160 , NULL , 0 ) ;
V_99 = V_154 -> F_96 ( V_154 -> V_151 , V_159 ) ;
if ( V_99 == 0 )
V_99 = V_28 ;
V_100:
F_17 ( & V_154 -> V_156 ) ;
return V_99 ;
}
int F_108 ( struct V_30 * V_30 , int V_161 )
{
struct V_7 * V_7 = V_30 -> V_162 -> V_122 ;
int V_163 ;
int V_99 ;
V_99 = F_109 ( V_7 -> V_9 ) ;
if ( ! ( V_7 -> V_164 & V_165 ) )
return V_99 ;
if ( V_161 && ! ( V_7 -> V_164 & V_166 ) )
return V_99 ;
V_163 = F_110 ( V_7 , 1 ) ;
if ( V_99 == 0 )
V_99 = V_163 ;
return V_99 ;
}
int F_111 ( unsigned V_167 , T_8 V_168 )
{
T_8 V_169 = V_168 - 1 ;
T_8 V_170 =
V_169 >> ( V_11 - V_167 ) ;
if ( F_70 ( V_168 == 0 ) )
return 0 ;
if ( ( V_167 < 9 ) || ( V_167 > V_11 ) )
return - V_41 ;
if ( ( V_169 > ( V_171 ) ( ~ 0ULL ) >> ( V_167 - 9 ) ) ||
( V_170 > ( T_7 ) ( ~ 0ULL ) ) ) {
return - V_148 ;
}
return 0 ;
}
int F_112 ( struct V_30 * V_30 , int V_161 )
{
return 0 ;
}
