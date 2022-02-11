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
F_16 ( & F_2 ( V_3 ) -> V_35 ) ;
switch ( V_34 ) {
case 1 :
V_33 += V_27 -> V_36 ;
case 0 :
if ( V_33 >= 0 )
break;
default:
F_17 ( & F_2 ( V_3 ) -> V_35 ) ;
return - V_37 ;
}
if ( V_33 != V_27 -> V_36 ) {
V_27 -> V_36 = V_33 ;
if ( V_27 -> V_36 >= 2 ) {
struct V_38 * V_39 ;
struct V_3 * V_40 = V_27 -> V_30 ;
T_1 V_41 = V_27 -> V_36 - 2 ;
F_18 ( & V_3 -> V_42 ) ;
F_19 ( & V_40 -> V_43 ) ;
V_39 = V_3 -> V_44 . V_45 ;
while ( V_41 && V_39 != & V_3 -> V_44 ) {
struct V_3 * V_45 ;
V_45 = F_20 ( V_39 , struct V_3 , V_43 ) ;
F_21 ( & V_45 -> V_42 , V_46 ) ;
if ( F_22 ( V_45 ) )
V_41 -- ;
F_23 ( & V_45 -> V_42 ) ;
V_39 = V_39 -> V_45 ;
}
F_24 ( & V_40 -> V_43 , V_39 ) ;
F_23 ( & V_3 -> V_42 ) ;
}
}
F_17 ( & F_2 ( V_3 ) -> V_35 ) ;
return V_33 ;
}
static inline unsigned char F_25 ( struct V_6 * V_6 )
{
return ( V_6 -> V_47 >> 12 ) & 15 ;
}
int F_26 ( struct V_27 * V_27 , struct V_48 * V_49 )
{
struct V_3 * V_3 = V_27 -> V_31 . V_3 ;
struct V_3 * V_40 = V_27 -> V_30 ;
struct V_38 * V_39 , * V_50 = & V_40 -> V_43 ;
if ( ! F_27 ( V_27 , V_49 ) )
return 0 ;
F_18 ( & V_3 -> V_42 ) ;
if ( V_49 -> V_51 == 2 )
F_28 ( V_50 , & V_3 -> V_44 ) ;
for ( V_39 = V_50 -> V_45 ; V_39 != & V_3 -> V_44 ; V_39 = V_39 -> V_45 ) {
struct V_3 * V_45 = F_20 ( V_39 , struct V_3 , V_43 ) ;
F_21 ( & V_45 -> V_42 , V_46 ) ;
if ( ! F_22 ( V_45 ) ) {
F_23 ( & V_45 -> V_42 ) ;
continue;
}
F_23 ( & V_45 -> V_42 ) ;
F_23 ( & V_3 -> V_42 ) ;
if ( ! F_29 ( V_49 , V_45 -> V_22 . V_52 , V_45 -> V_22 . V_23 ,
F_2 ( V_45 ) -> V_53 , F_25 ( F_2 ( V_45 ) ) ) )
return 0 ;
F_18 ( & V_3 -> V_42 ) ;
F_21 ( & V_45 -> V_42 , V_46 ) ;
F_28 ( V_50 , V_39 ) ;
F_23 ( & V_45 -> V_42 ) ;
V_39 = V_50 ;
V_49 -> V_51 ++ ;
}
F_23 ( & V_3 -> V_42 ) ;
return 0 ;
}
T_2 F_30 ( struct V_27 * V_54 , char T_3 * V_12 , T_4 V_55 , T_1 * V_56 )
{
return - V_57 ;
}
struct V_3 * F_31 ( struct V_58 * V_59 , char * V_52 ,
const struct V_60 * V_61 ,
const struct V_62 * V_63 , unsigned long V_64 )
{
struct V_65 * V_66 ;
struct V_3 * V_3 ;
struct V_6 * V_67 ;
struct V_28 V_22 = F_11 ( V_52 , strlen ( V_52 ) ) ;
V_66 = F_32 ( V_59 , NULL , V_68 , V_69 , NULL ) ;
if ( F_33 ( V_66 ) )
return F_34 ( V_66 ) ;
V_66 -> V_70 = V_71 ;
V_66 -> V_72 = V_73 ;
V_66 -> V_74 = V_75 ;
V_66 -> V_15 = V_64 ;
V_66 -> V_76 = V_61 ? V_61 : & V_77 ;
V_66 -> V_78 = 1 ;
V_67 = F_35 ( V_66 ) ;
if ( ! V_67 )
goto V_79;
V_67 -> V_53 = 1 ;
V_67 -> V_47 = V_80 | V_81 | V_82 ;
V_67 -> V_83 = V_67 -> V_84 = V_67 -> V_85 = V_86 ;
V_3 = F_36 ( V_66 , & V_22 ) ;
if ( ! V_3 ) {
F_37 ( V_67 ) ;
goto V_79;
}
F_38 ( V_3 , V_67 ) ;
V_66 -> V_87 = V_3 ;
V_66 -> V_25 = V_63 ;
V_66 -> V_88 |= V_89 ;
return F_39 ( V_66 -> V_87 ) ;
V_79:
F_40 ( V_66 ) ;
return F_7 ( - V_32 ) ;
}
int F_41 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
if ( V_6 -> V_90 )
V_27 -> V_30 = V_6 -> V_90 ;
return 0 ;
}
int F_42 ( struct V_3 * V_91 , struct V_6 * V_20 , struct V_3 * V_3 )
{
struct V_6 * V_6 = F_2 ( V_91 ) ;
V_6 -> V_85 = V_20 -> V_85 = V_20 -> V_84 = V_86 ;
F_43 ( V_6 ) ;
F_44 ( V_6 ) ;
F_39 ( V_3 ) ;
F_38 ( V_3 , V_6 ) ;
return 0 ;
}
int F_45 ( struct V_3 * V_3 )
{
struct V_3 * V_92 ;
int V_93 = 0 ;
F_18 ( & V_3 -> V_42 ) ;
F_46 (child, &dentry->d_subdirs, d_child) {
F_21 ( & V_92 -> V_42 , V_46 ) ;
if ( F_22 ( V_92 ) ) {
F_23 ( & V_92 -> V_42 ) ;
goto V_94;
}
F_23 ( & V_92 -> V_42 ) ;
}
V_93 = 1 ;
V_94:
F_23 ( & V_3 -> V_42 ) ;
return V_93 ;
}
int F_47 ( struct V_6 * V_20 , struct V_3 * V_3 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
V_6 -> V_85 = V_20 -> V_85 = V_20 -> V_84 = V_86 ;
F_48 ( V_6 ) ;
F_14 ( V_3 ) ;
return 0 ;
}
int F_49 ( struct V_6 * V_20 , struct V_3 * V_3 )
{
if ( ! F_45 ( V_3 ) )
return - V_95 ;
F_48 ( F_2 ( V_3 ) ) ;
F_47 ( V_20 , V_3 ) ;
F_48 ( V_20 ) ;
return 0 ;
}
int F_50 ( struct V_6 * V_96 , struct V_3 * V_91 ,
struct V_6 * V_97 , struct V_3 * V_98 )
{
struct V_6 * V_6 = F_2 ( V_91 ) ;
int V_99 = F_51 ( V_91 ) ;
if ( ! F_45 ( V_98 ) )
return - V_95 ;
if ( F_52 ( V_98 ) ) {
F_47 ( V_97 , V_98 ) ;
if ( V_99 ) {
F_48 ( F_2 ( V_98 ) ) ;
F_48 ( V_96 ) ;
}
} else if ( V_99 ) {
F_48 ( V_96 ) ;
F_43 ( V_97 ) ;
}
V_96 -> V_85 = V_96 -> V_84 = V_97 -> V_85 =
V_97 -> V_84 = V_6 -> V_85 = V_86 ;
return 0 ;
}
int F_53 ( struct V_3 * V_3 , struct V_100 * V_100 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
int error ;
error = F_54 ( V_6 , V_100 ) ;
if ( error )
return error ;
if ( V_100 -> V_101 & V_102 )
F_55 ( V_6 , V_100 -> V_103 ) ;
F_56 ( V_6 , V_100 ) ;
F_57 ( V_6 ) ;
return 0 ;
}
int F_58 ( struct V_27 * V_27 , struct V_104 * V_104 )
{
F_59 ( V_104 ) ;
F_60 ( V_104 ) ;
F_61 ( V_104 ) ;
F_62 ( V_104 ) ;
return 0 ;
}
int F_63 ( struct V_27 * V_27 , struct V_105 * V_106 ,
T_1 V_51 , unsigned V_23 , unsigned V_21 ,
struct V_104 * * V_107 , void * * V_108 )
{
struct V_104 * V_104 ;
T_5 V_109 ;
V_109 = V_51 >> V_10 ;
V_104 = F_64 ( V_106 , V_109 , V_21 ) ;
if ( ! V_104 )
return - V_32 ;
* V_107 = V_104 ;
if ( ! F_65 ( V_104 ) && ( V_23 != V_17 ) ) {
unsigned V_110 = V_51 & ( V_17 - 1 ) ;
F_66 ( V_104 , 0 , V_110 , V_110 + V_23 , V_17 ) ;
}
return 0 ;
}
int F_67 ( struct V_27 * V_27 , struct V_105 * V_106 ,
T_1 V_51 , unsigned V_23 , unsigned V_111 ,
struct V_104 * V_104 , void * V_108 )
{
struct V_6 * V_6 = V_104 -> V_106 -> V_112 ;
T_1 V_113 = V_51 + V_111 ;
if ( V_111 < V_23 ) {
unsigned V_110 = V_51 & ( V_17 - 1 ) ;
F_68 ( V_104 , V_110 + V_111 , V_23 - V_111 ) ;
}
if ( ! F_65 ( V_104 ) )
F_61 ( V_104 ) ;
if ( V_113 > V_6 -> V_114 )
F_69 ( V_6 , V_113 ) ;
F_70 ( V_104 ) ;
F_62 ( V_104 ) ;
F_71 ( V_104 ) ;
return V_111 ;
}
int F_72 ( struct V_65 * V_66 , unsigned long V_64 ,
struct V_115 * V_116 )
{
struct V_6 * V_6 ;
struct V_3 * V_67 ;
struct V_3 * V_3 ;
int V_117 ;
V_66 -> V_72 = V_17 ;
V_66 -> V_74 = V_10 ;
V_66 -> V_15 = V_64 ;
V_66 -> V_76 = & V_77 ;
V_66 -> V_78 = 1 ;
V_6 = F_35 ( V_66 ) ;
if ( ! V_6 )
return - V_32 ;
V_6 -> V_53 = 1 ;
V_6 -> V_47 = V_80 | 0755 ;
V_6 -> V_83 = V_6 -> V_84 = V_6 -> V_85 = V_86 ;
V_6 -> V_118 = & V_119 ;
V_6 -> V_120 = & V_121 ;
F_73 ( V_6 , 2 ) ;
V_67 = F_74 ( V_6 ) ;
if ( ! V_67 )
return - V_32 ;
for ( V_117 = 0 ; ! V_116 -> V_52 || V_116 -> V_52 [ 0 ] ; V_117 ++ , V_116 ++ ) {
if ( ! V_116 -> V_52 )
continue;
if ( F_75 ( V_117 == 1 ) )
F_76 ( V_122 L_2
L_3 , V_123 ,
V_66 -> V_124 -> V_52 ) ;
V_3 = F_77 ( V_67 , V_116 -> V_52 ) ;
if ( ! V_3 )
goto V_94;
V_6 = F_35 ( V_66 ) ;
if ( ! V_6 ) {
F_14 ( V_3 ) ;
goto V_94;
}
V_6 -> V_47 = V_125 | V_116 -> V_126 ;
V_6 -> V_83 = V_6 -> V_84 = V_6 -> V_85 = V_86 ;
V_6 -> V_120 = V_116 -> V_61 ;
V_6 -> V_53 = V_117 ;
F_9 ( V_3 , V_6 ) ;
}
V_66 -> V_87 = V_67 ;
return 0 ;
V_94:
F_78 ( V_67 ) ;
F_79 ( V_67 ) ;
F_14 ( V_67 ) ;
return - V_32 ;
}
int F_80 ( struct V_58 * type , struct V_1 * * V_127 , int * V_128 )
{
struct V_1 * V_2 = NULL ;
F_18 ( & V_129 ) ;
if ( F_75 ( ! * V_127 ) ) {
F_23 ( & V_129 ) ;
V_2 = F_81 ( type , V_130 , type -> V_52 , NULL ) ;
if ( F_33 ( V_2 ) )
return F_82 ( V_2 ) ;
F_18 ( & V_129 ) ;
if ( ! * V_127 )
* V_127 = V_2 ;
}
F_83 ( * V_127 ) ;
++ * V_128 ;
F_23 ( & V_129 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
void F_85 ( struct V_1 * * V_127 , int * V_128 )
{
struct V_1 * V_2 ;
F_18 ( & V_129 ) ;
V_2 = * V_127 ;
if ( ! -- * V_128 )
* V_127 = NULL ;
F_23 ( & V_129 ) ;
F_84 ( V_2 ) ;
}
T_2 F_86 ( void T_3 * V_131 , T_4 V_128 , T_1 * V_56 ,
const void * V_110 , T_4 V_132 )
{
T_1 V_51 = * V_56 ;
T_4 V_93 ;
if ( V_51 < 0 )
return - V_37 ;
if ( V_51 >= V_132 || ! V_128 )
return 0 ;
if ( V_128 > V_132 - V_51 )
V_128 = V_132 - V_51 ;
V_93 = F_87 ( V_131 , V_110 + V_51 , V_128 ) ;
if ( V_93 == V_128 )
return - V_133 ;
V_128 -= V_93 ;
* V_56 = V_51 + V_128 ;
return V_128 ;
}
T_2 F_88 ( void * V_131 , T_4 V_132 , T_1 * V_56 ,
const void T_3 * V_110 , T_4 V_128 )
{
T_1 V_51 = * V_56 ;
T_4 V_134 ;
if ( V_51 < 0 )
return - V_37 ;
if ( V_51 >= V_132 || ! V_128 )
return 0 ;
if ( V_128 > V_132 - V_51 )
V_128 = V_132 - V_51 ;
V_134 = F_89 ( V_131 + V_51 , V_110 , V_128 ) ;
if ( V_134 == V_128 )
return - V_133 ;
V_128 -= V_134 ;
* V_56 = V_51 + V_128 ;
return V_128 ;
}
T_2 F_90 ( void * V_131 , T_4 V_128 , T_1 * V_56 ,
const void * V_110 , T_4 V_132 )
{
T_1 V_51 = * V_56 ;
if ( V_51 < 0 )
return - V_37 ;
if ( V_51 >= V_132 )
return 0 ;
if ( V_128 > V_132 - V_51 )
V_128 = V_132 - V_51 ;
memcpy ( V_131 , V_110 + V_51 , V_128 ) ;
* V_56 = V_51 + V_128 ;
return V_128 ;
}
void F_91 ( struct V_27 * V_27 , T_4 V_41 )
{
struct V_135 * V_136 = V_27 -> V_30 ;
F_92 ( V_41 > V_137 ) ;
F_93 () ;
V_136 -> V_138 = V_41 ;
}
char * F_94 ( struct V_27 * V_27 , const char T_3 * V_12 , T_4 V_138 )
{
struct V_135 * V_136 ;
static F_95 ( V_139 ) ;
if ( V_138 > V_137 - 1 )
return F_7 ( - V_140 ) ;
V_136 = (struct V_135 * ) F_96 ( V_141 ) ;
if ( ! V_136 )
return F_7 ( - V_32 ) ;
F_18 ( & V_139 ) ;
if ( V_27 -> V_30 ) {
F_23 ( & V_139 ) ;
F_97 ( ( unsigned long ) V_136 ) ;
return F_7 ( - V_142 ) ;
}
V_27 -> V_30 = V_136 ;
F_23 ( & V_139 ) ;
if ( F_89 ( V_136 -> V_143 , V_12 , V_138 ) )
return F_7 ( - V_133 ) ;
return V_136 -> V_143 ;
}
T_2 F_98 ( struct V_27 * V_27 , char T_3 * V_12 , T_4 V_138 , T_1 * V_51 )
{
struct V_135 * V_136 = V_27 -> V_30 ;
if ( ! V_136 )
return 0 ;
return F_86 ( V_12 , V_138 , V_51 , V_136 -> V_143 , V_136 -> V_138 ) ;
}
int F_99 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
F_97 ( ( unsigned long ) V_27 -> V_30 ) ;
return 0 ;
}
int F_100 ( struct V_6 * V_6 , struct V_27 * V_27 ,
int (* F_101)( void * , T_6 * ) , int (* F_102)( void * , T_6 ) ,
const char * V_144 )
{
struct V_145 * V_146 ;
V_146 = F_103 ( sizeof( * V_146 ) , V_141 ) ;
if ( ! V_146 )
return - V_32 ;
V_146 -> F_101 = F_101 ;
V_146 -> F_102 = F_102 ;
V_146 -> V_143 = V_6 -> V_90 ;
V_146 -> V_144 = V_144 ;
F_104 ( & V_146 -> V_147 ) ;
V_27 -> V_30 = V_146 ;
return F_105 ( V_6 , V_27 ) ;
}
int F_106 ( struct V_6 * V_6 , struct V_27 * V_27 )
{
F_107 ( V_27 -> V_30 ) ;
return 0 ;
}
T_2 F_108 ( struct V_27 * V_27 , char T_3 * V_12 ,
T_4 V_23 , T_1 * V_56 )
{
struct V_145 * V_146 ;
T_4 V_138 ;
T_2 V_93 ;
V_146 = V_27 -> V_30 ;
if ( ! V_146 -> F_101 )
return - V_148 ;
V_93 = F_109 ( & V_146 -> V_147 ) ;
if ( V_93 )
return V_93 ;
if ( * V_56 ) {
V_138 = strlen ( V_146 -> V_149 ) ;
} else {
T_6 V_150 ;
V_93 = V_146 -> F_101 ( V_146 -> V_143 , & V_150 ) ;
if ( V_93 )
goto V_94;
V_138 = F_110 ( V_146 -> V_149 , sizeof( V_146 -> V_149 ) ,
V_146 -> V_144 , ( unsigned long long ) V_150 ) ;
}
V_93 = F_86 ( V_12 , V_23 , V_56 , V_146 -> V_149 , V_138 ) ;
V_94:
F_17 ( & V_146 -> V_147 ) ;
return V_93 ;
}
T_2 F_111 ( struct V_27 * V_27 , const char T_3 * V_12 ,
T_4 V_23 , T_1 * V_56 )
{
struct V_145 * V_146 ;
T_6 V_150 ;
T_4 V_138 ;
T_2 V_93 ;
V_146 = V_27 -> V_30 ;
if ( ! V_146 -> F_102 )
return - V_148 ;
V_93 = F_109 ( & V_146 -> V_147 ) ;
if ( V_93 )
return V_93 ;
V_93 = - V_133 ;
V_138 = F_112 ( sizeof( V_146 -> V_151 ) - 1 , V_23 ) ;
if ( F_89 ( V_146 -> V_151 , V_12 , V_138 ) )
goto V_94;
V_146 -> V_151 [ V_138 ] = '\0' ;
V_150 = F_113 ( V_146 -> V_151 , NULL , 0 ) ;
V_93 = V_146 -> F_102 ( V_146 -> V_143 , V_150 ) ;
if ( V_93 == 0 )
V_93 = V_23 ;
V_94:
F_17 ( & V_146 -> V_147 ) ;
return V_93 ;
}
int F_114 ( struct V_27 * V_27 , T_1 V_152 , T_1 V_153 ,
int V_154 )
{
struct V_6 * V_6 = V_27 -> V_155 -> V_112 ;
int V_156 ;
int V_93 ;
V_156 = F_115 ( V_6 -> V_8 , V_152 , V_153 ) ;
if ( V_156 )
return V_156 ;
F_16 ( & V_6 -> V_35 ) ;
V_93 = F_116 ( V_6 -> V_8 ) ;
if ( ! ( V_6 -> V_157 & V_158 ) )
goto V_94;
if ( V_154 && ! ( V_6 -> V_157 & V_159 ) )
goto V_94;
V_156 = F_117 ( V_6 , 1 ) ;
if ( V_93 == 0 )
V_93 = V_156 ;
V_94:
F_17 ( & V_6 -> V_35 ) ;
return V_93 ;
}
int F_118 ( struct V_27 * V_27 , T_1 V_152 , T_1 V_153 ,
int V_154 )
{
struct V_6 * V_6 = V_27 -> V_155 -> V_112 ;
int V_156 ;
V_156 = F_114 ( V_27 , V_152 , V_153 , V_154 ) ;
if ( V_156 )
return V_156 ;
return F_119 ( V_6 -> V_160 -> V_161 , V_141 , NULL ) ;
}
int F_120 ( unsigned V_162 , T_6 V_163 )
{
T_6 V_164 = V_163 - 1 ;
T_6 V_165 =
V_164 >> ( V_10 - V_162 ) ;
if ( F_75 ( V_163 == 0 ) )
return 0 ;
if ( ( V_162 < 9 ) || ( V_162 > V_10 ) )
return - V_37 ;
if ( ( V_164 > ( V_166 ) ( ~ 0ULL ) >> ( V_162 - 9 ) ) ||
( V_165 > ( T_5 ) ( ~ 0ULL ) ) ) {
return - V_140 ;
}
return 0 ;
}
int F_121 ( struct V_27 * V_27 , T_1 V_152 , T_1 V_153 , int V_154 )
{
return 0 ;
}
void F_122 ( struct V_6 * V_167 , void * V_168 )
{
F_107 ( V_168 ) ;
}
void F_123 ( struct V_6 * V_167 , void * V_168 )
{
F_97 ( ( unsigned long ) V_168 ) ;
}
static int F_124 ( struct V_104 * V_104 )
{
return 0 ;
}
struct V_6 * F_125 ( struct V_65 * V_66 )
{
static const struct V_169 V_170 = {
. F_70 = F_124 ,
} ;
struct V_6 * V_6 = F_126 ( V_66 ) ;
if ( ! V_6 )
return F_7 ( - V_32 ) ;
V_6 -> V_53 = F_127 () ;
V_6 -> V_8 -> V_171 = & V_170 ;
V_6 -> V_157 = V_172 ;
V_6 -> V_47 = V_81 | V_82 ;
V_6 -> V_173 = F_128 () ;
V_6 -> V_174 = F_129 () ;
V_6 -> V_175 |= V_176 ;
V_6 -> V_83 = V_6 -> V_84 = V_6 -> V_85 = V_86 ;
return V_6 ;
}
int
F_130 ( struct V_27 * V_54 , long V_177 , struct V_178 * * V_179 ,
void * * V_180 )
{
return - V_37 ;
}
const char * F_131 ( struct V_3 * V_3 , void * * V_168 )
{
return F_2 ( V_3 ) -> V_181 ;
}
static struct V_3 * F_132 ( struct V_6 * V_20 , struct V_3 * V_3 , unsigned int V_21 )
{
return F_7 ( - V_182 ) ;
}
static int F_133 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_3 ) ;
F_3 ( V_6 , V_5 ) ;
return 0 ;
}
static int F_134 ( struct V_3 * V_3 , struct V_100 * V_146 )
{
return - V_183 ;
}
static int F_135 ( struct V_3 * V_3 , const char * V_52 ,
const void * V_184 , T_4 V_138 , int V_21 )
{
return - V_185 ;
}
static T_2 F_136 ( struct V_3 * V_3 , const char * V_52 ,
void * V_184 , T_4 V_138 )
{
return - V_185 ;
}
static int F_137 ( struct V_3 * V_3 , const char * V_52 )
{
return - V_185 ;
}
static T_2 F_138 ( struct V_3 * V_3 , char * V_186 , T_4 V_138 )
{
return - V_185 ;
}
static T_1 F_139 ( struct V_27 * V_27 , T_1 V_33 , int V_34 )
{
return F_140 ( V_27 , V_33 , V_34 , 2 , 2 ) ;
}
static int F_141 ( struct V_27 * V_27 , struct V_48 * V_49 )
{
F_27 ( V_27 , V_49 ) ;
return 0 ;
}
void F_142 ( struct V_6 * V_6 )
{
F_73 ( V_6 , 2 ) ;
V_6 -> V_47 = V_80 | V_187 | V_188 ;
V_6 -> V_173 = V_189 ;
V_6 -> V_174 = V_190 ;
V_6 -> V_191 = 0 ;
V_6 -> V_114 = 2 ;
V_6 -> V_192 = V_75 ;
V_6 -> V_193 = 0 ;
V_6 -> V_118 = & V_194 ;
V_6 -> V_120 = & V_195 ;
}
bool F_143 ( struct V_6 * V_6 )
{
return ( V_6 -> V_120 == & V_195 ) &&
( V_6 -> V_118 == & V_194 ) ;
}
