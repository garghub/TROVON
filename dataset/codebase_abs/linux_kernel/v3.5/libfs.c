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
int F_26 ( struct V_30 * V_52 , void * V_53 , T_2 V_54 )
{
struct V_1 * V_1 = V_52 -> V_34 . V_1 ;
struct V_1 * V_43 = V_52 -> V_33 ;
struct V_41 * V_42 , * V_55 = & V_43 -> V_46 . V_47 ;
T_3 V_56 ;
int V_57 = V_52 -> V_39 ;
switch ( V_57 ) {
case 0 :
V_56 = V_1 -> V_2 -> V_58 ;
if ( V_54 ( V_53 , L_1 , 1 , V_57 , V_56 , V_59 ) < 0 )
break;
V_52 -> V_39 ++ ;
V_57 ++ ;
case 1 :
V_56 = F_27 ( V_1 ) ;
if ( V_54 ( V_53 , L_2 , 2 , V_57 , V_56 , V_59 ) < 0 )
break;
V_52 -> V_39 ++ ;
V_57 ++ ;
default:
F_19 ( & V_1 -> V_45 ) ;
if ( V_52 -> V_39 == 2 )
F_28 ( V_55 , & V_1 -> V_48 ) ;
for ( V_42 = V_55 -> V_49 ; V_42 != & V_1 -> V_48 ; V_42 = V_42 -> V_49 ) {
struct V_1 * V_49 ;
V_49 = F_21 ( V_42 , struct V_1 , V_46 . V_47 ) ;
F_22 ( & V_49 -> V_45 , V_50 ) ;
if ( ! F_1 ( V_49 ) ) {
F_23 ( & V_49 -> V_45 ) ;
continue;
}
F_23 ( & V_49 -> V_45 ) ;
F_23 ( & V_1 -> V_45 ) ;
if ( V_54 ( V_53 , V_49 -> V_27 . V_60 ,
V_49 -> V_27 . V_28 , V_52 -> V_39 ,
V_49 -> V_2 -> V_58 ,
F_25 ( V_49 -> V_2 ) ) < 0 )
return 0 ;
F_19 ( & V_1 -> V_45 ) ;
F_22 ( & V_49 -> V_45 , V_50 ) ;
F_28 ( V_55 , V_42 ) ;
F_23 ( & V_49 -> V_45 ) ;
V_42 = V_55 ;
V_52 -> V_39 ++ ;
}
F_23 ( & V_1 -> V_45 ) ;
}
return 0 ;
}
T_4 F_29 ( struct V_30 * V_52 , char T_5 * V_13 , T_6 V_61 , T_1 * V_62 )
{
return - V_63 ;
}
struct V_1 * F_30 ( struct V_64 * V_65 , char * V_60 ,
const struct V_66 * V_67 ,
const struct V_24 * V_68 , unsigned long V_69 )
{
struct V_70 * V_71 = F_31 ( V_65 , NULL , V_72 , NULL ) ;
struct V_1 * V_1 ;
struct V_7 * V_73 ;
struct V_31 V_27 = F_12 ( V_60 , strlen ( V_60 ) ) ;
if ( F_32 ( V_71 ) )
return F_33 ( V_71 ) ;
V_71 -> V_74 = V_75 ;
V_71 -> V_76 = V_77 ;
V_71 -> V_78 = V_79 ;
V_71 -> V_80 = V_81 ;
V_71 -> V_16 = V_69 ;
V_71 -> V_82 = V_67 ? V_67 : & V_83 ;
V_71 -> V_84 = 1 ;
V_73 = F_34 ( V_71 ) ;
if ( ! V_73 )
goto V_85;
V_73 -> V_58 = 1 ;
V_73 -> V_51 = V_86 | V_87 | V_88 ;
V_73 -> V_89 = V_73 -> V_90 = V_73 -> V_91 = V_92 ;
V_1 = F_35 ( V_71 , & V_27 ) ;
if ( ! V_1 ) {
F_36 ( V_73 ) ;
goto V_85;
}
F_37 ( V_1 , V_73 ) ;
V_71 -> V_93 = V_1 ;
V_71 -> V_94 = V_68 ;
V_71 -> V_74 |= V_95 ;
return F_38 ( V_71 -> V_93 ) ;
V_85:
F_39 ( V_71 ) ;
return F_8 ( - V_35 ) ;
}
int F_40 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
if ( V_7 -> V_96 )
V_30 -> V_33 = V_7 -> V_96 ;
return 0 ;
}
int F_41 ( struct V_1 * V_97 , struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_97 -> V_2 ;
V_7 -> V_91 = V_21 -> V_91 = V_21 -> V_90 = V_92 ;
F_42 ( V_7 ) ;
F_43 ( V_7 ) ;
F_38 ( V_1 ) ;
F_37 ( V_1 , V_7 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_1 )
{
struct V_1 * V_98 ;
int V_99 = 0 ;
F_19 ( & V_1 -> V_45 ) ;
F_45 (child, &dentry->d_subdirs, d_u.d_child) {
F_22 ( & V_98 -> V_45 , V_50 ) ;
if ( F_1 ( V_98 ) ) {
F_23 ( & V_98 -> V_45 ) ;
goto V_100;
}
F_23 ( & V_98 -> V_45 ) ;
}
V_99 = 1 ;
V_100:
F_23 ( & V_1 -> V_45 ) ;
return V_99 ;
}
int F_46 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
V_7 -> V_91 = V_21 -> V_91 = V_21 -> V_90 = V_92 ;
F_47 ( V_7 ) ;
F_15 ( V_1 ) ;
return 0 ;
}
int F_48 ( struct V_7 * V_21 , struct V_1 * V_1 )
{
if ( ! F_44 ( V_1 ) )
return - V_101 ;
F_47 ( V_1 -> V_2 ) ;
F_46 ( V_21 , V_1 ) ;
F_47 ( V_21 ) ;
return 0 ;
}
int F_49 ( struct V_7 * V_102 , struct V_1 * V_97 ,
struct V_7 * V_103 , struct V_1 * V_104 )
{
struct V_7 * V_7 = V_97 -> V_2 ;
int V_105 = F_50 ( V_97 -> V_2 -> V_51 ) ;
if ( ! F_44 ( V_104 ) )
return - V_101 ;
if ( V_104 -> V_2 ) {
F_46 ( V_103 , V_104 ) ;
if ( V_105 ) {
F_47 ( V_104 -> V_2 ) ;
F_47 ( V_102 ) ;
}
} else if ( V_105 ) {
F_47 ( V_102 ) ;
F_42 ( V_103 ) ;
}
V_102 -> V_91 = V_102 -> V_90 = V_103 -> V_91 =
V_103 -> V_90 = V_7 -> V_91 = V_92 ;
return 0 ;
}
int F_51 ( struct V_1 * V_1 , struct V_106 * V_106 )
{
struct V_7 * V_7 = V_1 -> V_2 ;
int error ;
F_52 ( V_7 -> V_107 -> V_108 ) ;
error = F_53 ( V_7 , V_106 ) ;
if ( error )
return error ;
if ( V_106 -> V_109 & V_110 )
F_54 ( V_7 , V_106 -> V_111 ) ;
F_55 ( V_7 , V_106 ) ;
F_56 ( V_7 ) ;
return 0 ;
}
int F_57 ( struct V_30 * V_30 , struct V_112 * V_112 )
{
F_58 ( V_112 ) ;
F_59 ( V_112 ) ;
F_60 ( V_112 ) ;
F_61 ( V_112 ) ;
return 0 ;
}
int F_62 ( struct V_30 * V_30 , struct V_113 * V_114 ,
T_1 V_115 , unsigned V_28 , unsigned V_116 ,
struct V_112 * * V_117 , void * * V_118 )
{
struct V_112 * V_112 ;
T_7 V_119 ;
V_119 = V_115 >> V_11 ;
V_112 = F_63 ( V_114 , V_119 , V_116 ) ;
if ( ! V_112 )
return - V_35 ;
* V_117 = V_112 ;
if ( ! F_64 ( V_112 ) && ( V_28 != V_18 ) ) {
unsigned V_120 = V_115 & ( V_18 - 1 ) ;
F_65 ( V_112 , 0 , V_120 , V_120 + V_28 , V_18 ) ;
}
return 0 ;
}
int F_66 ( struct V_30 * V_30 , struct V_113 * V_114 ,
T_1 V_115 , unsigned V_28 , unsigned V_121 ,
struct V_112 * V_112 , void * V_118 )
{
struct V_7 * V_7 = V_112 -> V_114 -> V_122 ;
T_1 V_123 = V_115 + V_121 ;
if ( V_121 < V_28 ) {
unsigned V_120 = V_115 & ( V_18 - 1 ) ;
F_67 ( V_112 , V_120 + V_121 , V_28 - V_121 ) ;
}
if ( ! F_64 ( V_112 ) )
F_60 ( V_112 ) ;
if ( V_123 > V_7 -> V_124 )
F_68 ( V_7 , V_123 ) ;
F_69 ( V_112 ) ;
F_61 ( V_112 ) ;
F_70 ( V_112 ) ;
return V_121 ;
}
int F_71 ( struct V_70 * V_71 , unsigned long V_69 ,
struct V_125 * V_126 )
{
struct V_7 * V_7 ;
struct V_1 * V_73 ;
struct V_1 * V_1 ;
int V_57 ;
V_71 -> V_78 = V_18 ;
V_71 -> V_80 = V_11 ;
V_71 -> V_16 = V_69 ;
V_71 -> V_82 = & V_83 ;
V_71 -> V_84 = 1 ;
V_7 = F_34 ( V_71 ) ;
if ( ! V_7 )
return - V_35 ;
V_7 -> V_58 = 1 ;
V_7 -> V_51 = V_86 | 0755 ;
V_7 -> V_89 = V_7 -> V_90 = V_7 -> V_91 = V_92 ;
V_7 -> V_107 = & V_127 ;
V_7 -> V_128 = & V_129 ;
F_72 ( V_7 , 2 ) ;
V_73 = F_73 ( V_7 ) ;
if ( ! V_73 )
return - V_35 ;
for ( V_57 = 0 ; ! V_126 -> V_60 || V_126 -> V_60 [ 0 ] ; V_57 ++ , V_126 ++ ) {
if ( ! V_126 -> V_60 )
continue;
if ( F_74 ( V_57 == 1 ) )
F_75 ( V_130 L_3
L_4 , V_131 ,
V_71 -> V_132 -> V_60 ) ;
V_1 = F_76 ( V_73 , V_126 -> V_60 ) ;
if ( ! V_1 )
goto V_100;
V_7 = F_34 ( V_71 ) ;
if ( ! V_7 ) {
F_15 ( V_1 ) ;
goto V_100;
}
V_7 -> V_51 = V_133 | V_126 -> V_134 ;
V_7 -> V_89 = V_7 -> V_90 = V_7 -> V_91 = V_92 ;
V_7 -> V_128 = V_126 -> V_67 ;
V_7 -> V_58 = V_57 ;
F_10 ( V_1 , V_7 ) ;
}
V_71 -> V_93 = V_73 ;
return 0 ;
V_100:
F_77 ( V_73 ) ;
F_78 ( V_73 ) ;
F_15 ( V_73 ) ;
return - V_35 ;
}
int F_79 ( struct V_64 * type , struct V_3 * * V_135 , int * V_136 )
{
struct V_3 * V_4 = NULL ;
F_19 ( & V_137 ) ;
if ( F_74 ( ! * V_135 ) ) {
F_23 ( & V_137 ) ;
V_4 = F_80 ( type , V_138 , type -> V_60 , NULL ) ;
if ( F_32 ( V_4 ) )
return F_81 ( V_4 ) ;
F_19 ( & V_137 ) ;
if ( ! * V_135 )
* V_135 = V_4 ;
}
F_82 ( * V_135 ) ;
++ * V_136 ;
F_23 ( & V_137 ) ;
F_83 ( V_4 ) ;
return 0 ;
}
void F_84 ( struct V_3 * * V_135 , int * V_136 )
{
struct V_3 * V_4 ;
F_19 ( & V_137 ) ;
V_4 = * V_135 ;
if ( ! -- * V_136 )
* V_135 = NULL ;
F_23 ( & V_137 ) ;
F_83 ( V_4 ) ;
}
T_4 F_85 ( void T_5 * V_139 , T_6 V_136 , T_1 * V_62 ,
const void * V_120 , T_6 V_140 )
{
T_1 V_115 = * V_62 ;
T_6 V_99 ;
if ( V_115 < 0 )
return - V_40 ;
if ( V_115 >= V_140 || ! V_136 )
return 0 ;
if ( V_136 > V_140 - V_115 )
V_136 = V_140 - V_115 ;
V_99 = F_86 ( V_139 , V_120 + V_115 , V_136 ) ;
if ( V_99 == V_136 )
return - V_141 ;
V_136 -= V_99 ;
* V_62 = V_115 + V_136 ;
return V_136 ;
}
T_4 F_87 ( void * V_139 , T_6 V_140 , T_1 * V_62 ,
const void T_5 * V_120 , T_6 V_136 )
{
T_1 V_115 = * V_62 ;
T_6 V_142 ;
if ( V_115 < 0 )
return - V_40 ;
if ( V_115 >= V_140 || ! V_136 )
return 0 ;
if ( V_136 > V_140 - V_115 )
V_136 = V_140 - V_115 ;
V_142 = F_88 ( V_139 + V_115 , V_120 , V_136 ) ;
if ( V_142 == V_136 )
return - V_141 ;
V_136 -= V_142 ;
* V_62 = V_115 + V_136 ;
return V_136 ;
}
T_4 F_89 ( void * V_139 , T_6 V_136 , T_1 * V_62 ,
const void * V_120 , T_6 V_140 )
{
T_1 V_115 = * V_62 ;
if ( V_115 < 0 )
return - V_40 ;
if ( V_115 >= V_140 )
return 0 ;
if ( V_136 > V_140 - V_115 )
V_136 = V_140 - V_115 ;
memcpy ( V_139 , V_120 + V_115 , V_136 ) ;
* V_62 = V_115 + V_136 ;
return V_136 ;
}
void F_90 ( struct V_30 * V_30 , T_6 V_44 )
{
struct V_143 * V_144 = V_30 -> V_33 ;
F_91 ( V_44 > V_145 ) ;
F_92 () ;
V_144 -> V_146 = V_44 ;
}
char * F_93 ( struct V_30 * V_30 , const char T_5 * V_13 , T_6 V_146 )
{
struct V_143 * V_144 ;
static F_94 ( V_147 ) ;
if ( V_146 > V_145 - 1 )
return F_8 ( - V_148 ) ;
V_144 = (struct V_143 * ) F_95 ( V_149 ) ;
if ( ! V_144 )
return F_8 ( - V_35 ) ;
F_19 ( & V_147 ) ;
if ( V_30 -> V_33 ) {
F_23 ( & V_147 ) ;
F_96 ( ( unsigned long ) V_144 ) ;
return F_8 ( - V_150 ) ;
}
V_30 -> V_33 = V_144 ;
F_23 ( & V_147 ) ;
if ( F_88 ( V_144 -> V_151 , V_13 , V_146 ) )
return F_8 ( - V_141 ) ;
return V_144 -> V_151 ;
}
T_4 F_97 ( struct V_30 * V_30 , char T_5 * V_13 , T_6 V_146 , T_1 * V_115 )
{
struct V_143 * V_144 = V_30 -> V_33 ;
if ( ! V_144 )
return 0 ;
return F_85 ( V_13 , V_146 , V_115 , V_144 -> V_151 , V_144 -> V_146 ) ;
}
int F_98 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
F_96 ( ( unsigned long ) V_30 -> V_33 ) ;
return 0 ;
}
int F_99 ( struct V_7 * V_7 , struct V_30 * V_30 ,
int (* F_100)( void * , T_8 * ) , int (* F_101)( void * , T_8 ) ,
const char * V_152 )
{
struct V_153 * V_154 ;
V_154 = F_102 ( sizeof( * V_154 ) , V_149 ) ;
if ( ! V_154 )
return - V_35 ;
V_154 -> F_100 = F_100 ;
V_154 -> F_101 = F_101 ;
V_154 -> V_151 = V_7 -> V_96 ;
V_154 -> V_152 = V_152 ;
F_103 ( & V_154 -> V_155 ) ;
V_30 -> V_33 = V_154 ;
return F_104 ( V_7 , V_30 ) ;
}
int F_105 ( struct V_7 * V_7 , struct V_30 * V_30 )
{
F_106 ( V_30 -> V_33 ) ;
return 0 ;
}
T_4 F_107 ( struct V_30 * V_30 , char T_5 * V_13 ,
T_6 V_28 , T_1 * V_62 )
{
struct V_153 * V_154 ;
T_6 V_146 ;
T_4 V_99 ;
V_154 = V_30 -> V_33 ;
if ( ! V_154 -> F_100 )
return - V_156 ;
V_99 = F_108 ( & V_154 -> V_155 ) ;
if ( V_99 )
return V_99 ;
if ( * V_62 ) {
V_146 = strlen ( V_154 -> V_157 ) ;
} else {
T_8 V_158 ;
V_99 = V_154 -> F_100 ( V_154 -> V_151 , & V_158 ) ;
if ( V_99 )
goto V_100;
V_146 = F_109 ( V_154 -> V_157 , sizeof( V_154 -> V_157 ) ,
V_154 -> V_152 , ( unsigned long long ) V_158 ) ;
}
V_99 = F_85 ( V_13 , V_28 , V_62 , V_154 -> V_157 , V_146 ) ;
V_100:
F_18 ( & V_154 -> V_155 ) ;
return V_99 ;
}
T_4 F_110 ( struct V_30 * V_30 , const char T_5 * V_13 ,
T_6 V_28 , T_1 * V_62 )
{
struct V_153 * V_154 ;
T_8 V_158 ;
T_6 V_146 ;
T_4 V_99 ;
V_154 = V_30 -> V_33 ;
if ( ! V_154 -> F_101 )
return - V_156 ;
V_99 = F_108 ( & V_154 -> V_155 ) ;
if ( V_99 )
return V_99 ;
V_99 = - V_141 ;
V_146 = F_111 ( sizeof( V_154 -> V_159 ) - 1 , V_28 ) ;
if ( F_88 ( V_154 -> V_159 , V_13 , V_146 ) )
goto V_100;
V_154 -> V_159 [ V_146 ] = '\0' ;
V_158 = F_112 ( V_154 -> V_159 , NULL , 0 ) ;
V_99 = V_154 -> F_101 ( V_154 -> V_151 , V_158 ) ;
if ( V_99 == 0 )
V_99 = V_28 ;
V_100:
F_18 ( & V_154 -> V_155 ) ;
return V_99 ;
}
int F_113 ( struct V_30 * V_30 , T_1 V_160 , T_1 V_161 ,
int V_162 )
{
struct V_7 * V_7 = V_30 -> V_163 -> V_122 ;
int V_164 ;
int V_99 ;
V_164 = F_114 ( V_7 -> V_9 , V_160 , V_161 ) ;
if ( V_164 )
return V_164 ;
F_17 ( & V_7 -> V_38 ) ;
V_99 = F_115 ( V_7 -> V_9 ) ;
if ( ! ( V_7 -> V_165 & V_166 ) )
goto V_100;
if ( V_162 && ! ( V_7 -> V_165 & V_167 ) )
goto V_100;
V_164 = F_116 ( V_7 , 1 ) ;
if ( V_99 == 0 )
V_99 = V_164 ;
V_100:
F_18 ( & V_7 -> V_38 ) ;
return V_99 ;
}
int F_117 ( unsigned V_168 , T_8 V_169 )
{
T_8 V_170 = V_169 - 1 ;
T_8 V_171 =
V_170 >> ( V_11 - V_168 ) ;
if ( F_74 ( V_169 == 0 ) )
return 0 ;
if ( ( V_168 < 9 ) || ( V_168 > V_11 ) )
return - V_40 ;
if ( ( V_170 > ( V_172 ) ( ~ 0ULL ) >> ( V_168 - 9 ) ) ||
( V_171 > ( T_7 ) ( ~ 0ULL ) ) ) {
return - V_148 ;
}
return 0 ;
}
int F_118 ( struct V_30 * V_30 , T_1 V_160 , T_1 V_161 , int V_162 )
{
return 0 ;
}
