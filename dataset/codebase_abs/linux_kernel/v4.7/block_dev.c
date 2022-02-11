static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_3 ) ;
}
struct V_4 * F_3 ( struct V_2 * V_2 )
{
return & F_1 ( V_2 ) -> V_5 ;
}
void F_4 ( struct V_6 * V_7 , const char * V_8 , const char * V_9 , ... )
{
struct V_10 V_11 ;
T_1 args ;
va_start ( args , V_9 ) ;
V_11 . V_9 = V_9 ;
V_11 . V_12 = & args ;
F_5 ( L_1 , V_8 , V_7 -> V_13 , & V_11 ) ;
va_end ( args ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
struct V_2 * V_2 = V_5 -> V_14 ;
int V_15 ;
F_7 ( & V_2 -> V_16 ) ;
while ( V_2 -> V_17 & V_18 ) {
F_8 ( & V_2 -> V_16 ) ;
V_15 = F_9 ( V_2 , true ) ;
if ( V_15 ) {
char V_19 [ V_20 ] ;
F_10 ( L_2
L_3 ,
F_11 ( V_5 , V_19 ) , V_15 ) ;
}
F_7 ( & V_2 -> V_16 ) ;
}
F_8 ( & V_2 -> V_16 ) ;
}
void F_12 ( struct V_4 * V_5 )
{
struct V_21 * V_22 = V_5 -> V_14 -> V_23 ;
if ( V_22 -> V_24 == 0 && V_22 -> V_25 == 0 )
return;
F_13 () ;
F_14 ( V_22 , 0 ) ;
}
void F_15 ( struct V_4 * V_5 )
{
struct V_21 * V_22 = V_5 -> V_14 -> V_23 ;
if ( V_22 -> V_24 == 0 )
return;
F_13 () ;
F_16 () ;
F_17 ( V_22 , 0 , - 1 ) ;
F_18 ( V_22 ) ;
}
int F_19 ( struct V_4 * V_5 , int V_26 )
{
if ( V_26 > V_27 || V_26 < 512 || ! F_20 ( V_26 ) )
return - V_28 ;
if ( V_26 < F_21 ( V_5 ) )
return - V_28 ;
if ( V_5 -> V_29 != V_26 ) {
F_22 ( V_5 ) ;
V_5 -> V_29 = V_26 ;
V_5 -> V_14 -> V_30 = F_23 ( V_26 ) ;
F_12 ( V_5 ) ;
}
return 0 ;
}
int F_24 ( struct V_6 * V_7 , int V_26 )
{
if ( F_19 ( V_7 -> V_31 , V_26 ) )
return 0 ;
V_7 -> V_32 = V_26 ;
V_7 -> V_33 = F_23 ( V_26 ) ;
return V_7 -> V_32 ;
}
int F_25 ( struct V_6 * V_7 , int V_26 )
{
int V_34 = F_21 ( V_7 -> V_31 ) ;
if ( V_26 < V_34 )
V_26 = V_34 ;
return F_24 ( V_7 , V_26 ) ;
}
static int
F_26 ( struct V_2 * V_2 , T_2 V_35 ,
struct V_36 * V_37 , int V_38 )
{
V_37 -> V_39 = F_3 ( V_2 ) ;
V_37 -> V_40 = V_35 ;
F_27 ( V_37 ) ;
return 0 ;
}
static struct V_2 * F_28 ( struct V_41 * V_41 )
{
return V_41 -> V_42 -> V_43 ;
}
static T_3
F_29 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
struct V_41 * V_41 = V_45 -> V_48 ;
struct V_2 * V_2 = F_28 ( V_41 ) ;
if ( F_30 ( V_2 ) )
return F_31 ( V_45 , V_2 , V_47 , F_26 ,
NULL , V_49 ) ;
return F_32 ( V_45 , V_2 , F_3 ( V_2 ) , V_47 ,
F_26 , NULL , NULL ,
V_49 ) ;
}
int F_33 ( struct V_4 * V_5 , int V_50 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_50 )
return F_34 ( V_5 -> V_14 -> V_23 ) ;
return F_35 ( V_5 -> V_14 -> V_23 ) ;
}
int F_22 ( struct V_4 * V_5 )
{
return F_33 ( V_5 , 1 ) ;
}
int F_36 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_37 ( V_5 ) ;
if ( V_7 ) {
int V_51 = F_38 ( V_7 ) ;
F_39 ( V_7 ) ;
return V_51 ;
}
return F_22 ( V_5 ) ;
}
struct V_6 * F_40 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_41 ( & V_5 -> V_52 ) ;
if ( ++ V_5 -> V_53 > 1 ) {
V_7 = F_37 ( V_5 ) ;
F_39 ( V_7 ) ;
F_42 ( & V_5 -> V_52 ) ;
return V_7 ;
}
V_7 = F_43 ( V_5 ) ;
if ( ! V_7 )
goto V_54;
if ( V_7 -> V_55 -> V_56 )
error = V_7 -> V_55 -> V_56 ( V_7 ) ;
else
error = V_56 ( V_7 ) ;
if ( error ) {
F_44 ( V_7 ) ;
V_5 -> V_53 -- ;
F_42 ( & V_5 -> V_52 ) ;
return F_45 ( error ) ;
}
F_44 ( V_7 ) ;
V_54:
F_22 ( V_5 ) ;
F_42 ( & V_5 -> V_52 ) ;
return V_7 ;
}
int F_46 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
int error = - V_28 ;
F_41 ( & V_5 -> V_52 ) ;
if ( ! V_5 -> V_53 )
goto V_54;
error = 0 ;
if ( -- V_5 -> V_53 > 0 )
goto V_54;
if ( ! V_7 )
goto V_54;
if ( V_7 -> V_55 -> V_57 )
error = V_7 -> V_55 -> V_57 ( V_7 ) ;
else
error = V_57 ( V_7 ) ;
if ( error ) {
V_5 -> V_53 ++ ;
F_42 ( & V_5 -> V_52 ) ;
return error ;
}
V_54:
F_42 ( & V_5 -> V_52 ) ;
return 0 ;
}
static int F_47 ( struct V_58 * V_58 , struct V_59 * V_60 )
{
return F_48 ( V_58 , F_26 , V_60 ) ;
}
static int F_49 ( struct V_41 * V_41 , struct V_58 * V_58 )
{
return F_50 ( V_58 , F_26 ) ;
}
static int F_51 ( struct V_41 * V_41 , struct V_21 * V_22 ,
struct V_61 * V_62 , unsigned V_63 )
{
return F_52 ( V_22 , V_62 , V_63 , F_26 ) ;
}
static int F_53 ( struct V_41 * V_41 , struct V_21 * V_22 ,
T_4 V_64 , unsigned V_65 , unsigned V_66 ,
struct V_58 * * V_67 , void * * V_68 )
{
return F_54 ( V_22 , V_64 , V_65 , V_66 , V_67 ,
F_26 ) ;
}
static int F_55 ( struct V_41 * V_41 , struct V_21 * V_22 ,
T_4 V_64 , unsigned V_65 , unsigned V_69 ,
struct V_58 * V_58 , void * V_68 )
{
int V_15 ;
V_15 = F_56 ( V_41 , V_22 , V_64 , V_65 , V_69 , V_58 , V_68 ) ;
F_57 ( V_58 ) ;
F_58 ( V_58 ) ;
return V_15 ;
}
static T_4 F_59 ( struct V_41 * V_41 , T_4 V_70 , int V_71 )
{
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_72 ;
F_60 ( V_14 ) ;
V_72 = F_61 ( V_41 , V_70 , V_71 , F_62 ( V_14 ) ) ;
F_63 ( V_14 ) ;
return V_72 ;
}
int F_64 ( struct V_41 * V_73 , T_4 V_74 , T_4 V_75 , int V_76 )
{
struct V_2 * V_14 = F_28 ( V_73 ) ;
struct V_4 * V_5 = F_3 ( V_14 ) ;
int error ;
error = F_65 ( V_73 -> V_42 , V_74 , V_75 ) ;
if ( error )
return error ;
error = F_66 ( V_5 , V_77 , NULL ) ;
if ( error == - V_78 )
error = 0 ;
return error ;
}
int F_67 ( struct V_4 * V_5 , T_2 V_79 ,
struct V_58 * V_58 )
{
const struct V_80 * V_81 = V_5 -> V_82 -> V_83 ;
int V_84 = - V_78 ;
if ( ! V_81 -> V_85 || F_68 ( V_5 ) )
return V_84 ;
V_84 = F_69 ( V_5 -> V_86 , false ) ;
if ( V_84 )
return V_84 ;
V_84 = V_81 -> V_85 ( V_5 , V_79 + F_70 ( V_5 ) , V_58 , V_87 ) ;
F_71 ( V_5 -> V_86 ) ;
return V_84 ;
}
int F_72 ( struct V_4 * V_5 , T_2 V_79 ,
struct V_58 * V_58 , struct V_59 * V_60 )
{
int V_84 ;
int V_88 = ( V_60 -> V_89 == V_90 ) ? V_91 : V_92 ;
const struct V_80 * V_81 = V_5 -> V_82 -> V_83 ;
if ( ! V_81 -> V_85 || F_68 ( V_5 ) )
return - V_78 ;
V_84 = F_69 ( V_5 -> V_86 , false ) ;
if ( V_84 )
return V_84 ;
F_73 ( V_58 ) ;
V_84 = V_81 -> V_85 ( V_5 , V_79 + F_70 ( V_5 ) , V_58 , V_88 ) ;
if ( V_84 )
F_74 ( V_58 ) ;
else
F_57 ( V_58 ) ;
F_71 ( V_5 -> V_86 ) ;
return V_84 ;
}
long F_75 ( struct V_4 * V_5 , struct V_93 * V_94 )
{
T_2 V_79 = V_94 -> V_79 ;
long V_95 , V_26 = V_94 -> V_26 ;
const struct V_80 * V_81 = V_5 -> V_82 -> V_83 ;
F_76 () ;
if ( V_26 < 0 )
return V_26 ;
if ( ! V_81 -> V_96 )
return - V_78 ;
if ( ( V_79 + F_77 ( V_26 , 512 ) ) >
F_78 ( V_5 -> V_97 ) )
return - V_98 ;
V_79 += F_70 ( V_5 ) ;
if ( V_79 % ( V_27 / 512 ) )
return - V_28 ;
V_95 = V_81 -> V_96 ( V_5 , V_79 , & V_94 -> V_99 , & V_94 -> V_100 , V_26 ) ;
if ( ! V_95 )
return - V_98 ;
if ( V_95 > 0 && V_95 & ~ V_101 )
return - V_102 ;
return F_79 ( V_95 , V_26 ) ;
}
int F_80 ( struct V_6 * V_7 , int V_103 )
{
struct V_93 V_94 = {
. V_79 = 0 ,
. V_26 = V_27 ,
} ;
int V_104 ;
if ( V_103 != V_27 ) {
F_81 ( V_7 , V_105 , L_4 ) ;
return - V_28 ;
}
V_104 = F_75 ( V_7 -> V_31 , & V_94 ) ;
if ( V_104 < 0 ) {
switch ( V_104 ) {
case - V_78 :
F_81 ( V_7 , V_105 ,
L_5 ) ;
break;
case - V_28 :
F_81 ( V_7 , V_105 ,
L_6 ) ;
break;
default:
F_81 ( V_7 , V_105 ,
L_7 , V_104 ) ;
}
return V_104 ;
}
return 0 ;
}
bool F_82 ( struct V_4 * V_5 )
{
struct V_93 V_94 = {
. V_26 = V_27 ,
} ;
if ( ! F_83 ( V_106 ) )
return false ;
V_94 . V_79 = 0 ;
if ( F_75 ( V_5 , & V_94 ) < 0 )
return false ;
V_94 . V_79 = V_5 -> V_97 -> V_107 - ( V_27 / 512 ) ;
if ( F_75 ( V_5 , & V_94 ) < 0 )
return false ;
return true ;
}
static struct V_2 * F_84 ( struct V_6 * V_7 )
{
struct V_1 * V_108 = F_85 ( V_109 , V_77 ) ;
if ( ! V_108 )
return NULL ;
return & V_108 -> V_3 ;
}
static void F_86 ( struct V_110 * V_111 )
{
struct V_2 * V_2 = F_2 ( V_111 , struct V_2 , V_112 ) ;
struct V_1 * V_113 = F_1 ( V_2 ) ;
F_87 ( V_109 , V_113 ) ;
}
static void F_88 ( struct V_2 * V_2 )
{
F_89 ( & V_2 -> V_112 , F_86 ) ;
}
static void F_90 ( void * V_114 )
{
struct V_1 * V_108 = (struct V_1 * ) V_114 ;
struct V_4 * V_5 = & V_108 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_91 ( & V_5 -> V_115 ) ;
F_92 ( & V_5 -> V_116 ) ;
F_92 ( & V_5 -> V_117 ) ;
#ifdef F_93
F_92 ( & V_5 -> V_118 ) ;
#endif
F_94 ( & V_108 -> V_3 ) ;
F_91 ( & V_5 -> V_52 ) ;
}
static inline void F_95 ( struct V_2 * V_2 )
{
F_96 ( & V_2 -> V_119 ) ;
V_2 -> V_120 = NULL ;
V_2 -> V_23 = & V_2 -> V_121 ;
}
static void F_97 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_61 * V_122 ;
F_98 ( & V_2 -> V_121 ) ;
F_99 ( V_2 ) ;
F_100 ( V_2 ) ;
F_7 ( & V_123 ) ;
while ( ( V_122 = V_5 -> V_116 . V_124 ) != & V_5 -> V_116 ) {
F_95 ( F_101 ( V_122 , struct V_2 , V_119 ) ) ;
}
F_96 ( & V_5 -> V_117 ) ;
F_8 ( & V_123 ) ;
}
static struct V_125 * F_102 ( struct V_126 * V_127 ,
int V_66 , const char * V_128 , void * V_129 )
{
struct V_125 * V_130 ;
V_130 = F_103 ( V_127 , L_8 , & V_131 , NULL , V_132 ) ;
if ( V_130 )
V_130 -> V_133 -> V_134 |= V_135 ;
return V_130 ;
}
void T_5 F_104 ( void )
{
int V_104 ;
static struct V_136 * V_137 ;
V_109 = F_105 ( L_9 , sizeof( struct V_1 ) ,
0 , ( V_138 | V_139 |
V_140 | V_141 | V_142 ) ,
F_90 ) ;
V_104 = F_106 ( & V_143 ) ;
if ( V_104 )
F_107 ( L_10 ) ;
V_137 = F_108 ( & V_143 ) ;
if ( F_109 ( V_137 ) )
F_107 ( L_11 ) ;
V_144 = V_137 -> V_145 ;
}
static inline unsigned long F_110 ( T_6 V_146 )
{
return F_111 ( V_146 ) + F_112 ( V_146 ) ;
}
static int F_113 ( struct V_2 * V_2 , void * V_129 )
{
return F_1 ( V_2 ) -> V_5 . V_147 == * ( T_6 * ) V_129 ;
}
static int F_114 ( struct V_2 * V_2 , void * V_129 )
{
F_1 ( V_2 ) -> V_5 . V_147 = * ( T_6 * ) V_129 ;
return 0 ;
}
struct V_4 * F_115 ( T_6 V_146 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_116 ( V_144 , F_110 ( V_146 ) ,
F_113 , F_114 , & V_146 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_17 & V_148 ) {
V_5 -> V_149 = NULL ;
V_5 -> V_150 = NULL ;
V_5 -> V_14 = V_2 ;
V_5 -> V_29 = ( 1 << V_2 -> V_30 ) ;
V_5 -> V_151 = 0 ;
V_5 -> V_152 = 0 ;
V_2 -> V_153 = V_154 ;
V_2 -> V_155 = V_146 ;
V_2 -> V_120 = V_5 ;
V_2 -> V_121 . V_156 = & V_157 ;
F_117 ( & V_2 -> V_121 , V_158 ) ;
F_7 ( & V_123 ) ;
F_118 ( & V_5 -> V_117 , & V_159 ) ;
F_8 ( & V_123 ) ;
F_119 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_120 ( struct V_4 * V_5 )
{
F_121 ( V_5 -> V_14 ) ;
return V_5 ;
}
long F_122 ( void )
{
struct V_4 * V_5 ;
long V_15 = 0 ;
F_7 ( & V_123 ) ;
F_123 (bdev, &all_bdevs, bd_list) {
V_15 += V_5 -> V_14 -> V_23 -> V_24 ;
}
F_8 ( & V_123 ) ;
return V_15 ;
}
void F_124 ( struct V_4 * V_5 )
{
F_125 ( V_5 -> V_14 ) ;
}
static struct V_4 * F_126 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_7 ( & V_123 ) ;
V_5 = V_2 -> V_120 ;
if ( V_5 ) {
F_120 ( V_5 ) ;
F_8 ( & V_123 ) ;
return V_5 ;
}
F_8 ( & V_123 ) ;
V_5 = F_115 ( V_2 -> V_155 ) ;
if ( V_5 ) {
F_7 ( & V_123 ) ;
if ( ! V_2 -> V_120 ) {
F_120 ( V_5 ) ;
V_2 -> V_120 = V_5 ;
V_2 -> V_23 = V_5 -> V_14 -> V_23 ;
F_118 ( & V_2 -> V_119 , & V_5 -> V_116 ) ;
}
F_8 ( & V_123 ) ;
}
return V_5 ;
}
void F_127 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_7 ( & V_123 ) ;
if ( ! F_128 ( V_2 -> V_160 ) )
V_5 = V_2 -> V_120 ;
F_95 ( V_2 ) ;
F_8 ( & V_123 ) ;
if ( V_5 )
F_124 ( V_5 ) ;
}
static bool F_129 ( struct V_4 * V_5 , struct V_4 * V_161 ,
void * V_162 )
{
if ( V_5 -> V_163 == V_162 )
return true ;
else if ( V_5 -> V_163 != NULL )
return false ;
else if ( V_5 -> V_149 == V_5 )
return true ;
else if ( V_161 -> V_163 == F_129 )
return true ;
else if ( V_161 -> V_163 != NULL )
return false ;
else
return true ;
}
static int F_130 ( struct V_4 * V_5 ,
struct V_4 * V_161 , void * V_162 )
{
V_164:
if ( ! F_129 ( V_5 , V_161 , V_162 ) )
return - V_165 ;
if ( V_161 -> V_166 ) {
T_7 * V_167 = F_131 ( & V_161 -> V_166 , 0 ) ;
F_132 ( V_50 ) ;
F_133 ( V_167 , & V_50 , V_168 ) ;
F_8 ( & V_123 ) ;
F_134 () ;
F_135 ( V_167 , & V_50 ) ;
F_7 ( & V_123 ) ;
goto V_164;
}
return 0 ;
}
static struct V_4 * F_136 ( struct V_4 * V_5 ,
void * V_162 )
{
struct V_169 * V_170 ;
struct V_4 * V_161 ;
int V_171 , V_104 ;
F_76 () ;
V_170 = F_137 ( V_5 -> V_147 , & V_171 ) ;
if ( ! V_170 )
return F_45 ( - V_102 ) ;
if ( V_171 )
V_161 = F_138 ( V_170 , 0 ) ;
else
V_161 = F_120 ( V_5 ) ;
F_139 ( V_170 -> V_83 -> V_172 ) ;
F_140 ( V_170 ) ;
if ( ! V_161 )
return F_45 ( - V_173 ) ;
F_7 ( & V_123 ) ;
V_104 = F_130 ( V_5 , V_161 , V_162 ) ;
if ( V_104 == 0 ) {
V_161 -> V_166 = V_162 ;
F_8 ( & V_123 ) ;
return V_161 ;
} else {
F_8 ( & V_123 ) ;
F_124 ( V_161 ) ;
return F_45 ( V_104 ) ;
}
}
static struct V_174 * F_141 ( struct V_4 * V_5 ,
struct V_169 * V_170 )
{
struct V_174 * V_162 ;
F_123 (holder, &bdev->bd_holder_disks, list)
if ( V_162 -> V_170 == V_170 )
return V_162 ;
return NULL ;
}
static int F_142 ( struct V_175 * V_176 , struct V_175 * V_177 )
{
return F_143 ( V_176 , V_177 , F_144 ( V_177 ) ) ;
}
static void F_145 ( struct V_175 * V_176 , struct V_175 * V_177 )
{
F_146 ( V_176 , F_144 ( V_177 ) ) ;
}
int F_147 ( struct V_4 * V_5 , struct V_169 * V_170 )
{
struct V_174 * V_162 ;
int V_15 = 0 ;
F_41 ( & V_5 -> V_115 ) ;
F_148 ( ! V_5 -> V_163 ) ;
if ( F_149 ( ! V_170 -> V_178 || ! V_5 -> V_97 -> V_179 ) )
goto V_180;
V_162 = F_141 ( V_5 , V_170 ) ;
if ( V_162 ) {
V_162 -> V_181 ++ ;
goto V_180;
}
V_162 = F_150 ( sizeof( * V_162 ) , V_77 ) ;
if ( ! V_162 ) {
V_15 = - V_173 ;
goto V_180;
}
F_92 ( & V_162 -> V_182 ) ;
V_162 -> V_170 = V_170 ;
V_162 -> V_181 = 1 ;
V_15 = F_142 ( V_170 -> V_178 , & F_151 ( V_5 -> V_97 ) -> V_183 ) ;
if ( V_15 )
goto V_184;
V_15 = F_142 ( V_5 -> V_97 -> V_179 , & F_152 ( V_170 ) -> V_183 ) ;
if ( V_15 )
goto V_185;
F_153 ( V_5 -> V_97 -> V_179 ) ;
F_118 ( & V_162 -> V_182 , & V_5 -> V_118 ) ;
goto V_180;
V_185:
F_145 ( V_170 -> V_178 , & F_151 ( V_5 -> V_97 ) -> V_183 ) ;
V_184:
F_154 ( V_162 ) ;
V_180:
F_42 ( & V_5 -> V_115 ) ;
return V_15 ;
}
void F_155 ( struct V_4 * V_5 , struct V_169 * V_170 )
{
struct V_174 * V_162 ;
F_41 ( & V_5 -> V_115 ) ;
V_162 = F_141 ( V_5 , V_170 ) ;
if ( ! F_148 ( V_162 == NULL ) && ! -- V_162 -> V_181 ) {
F_145 ( V_170 -> V_178 , & F_151 ( V_5 -> V_97 ) -> V_183 ) ;
F_145 ( V_5 -> V_97 -> V_179 ,
& F_152 ( V_170 ) -> V_183 ) ;
F_156 ( V_5 -> V_97 -> V_179 ) ;
F_96 ( & V_162 -> V_182 ) ;
F_154 ( V_162 ) ;
}
F_42 ( & V_5 -> V_115 ) ;
}
static void F_157 ( struct V_4 * V_5 , bool V_186 )
{
if ( F_158 ( V_5 , V_186 ) ) {
F_159 ( V_187 L_12
L_13 ,
V_5 -> V_82 ? V_5 -> V_82 -> V_188 : L_14 ) ;
}
if ( ! V_5 -> V_82 )
return;
if ( F_160 ( V_5 -> V_82 ) )
V_5 -> V_152 = 1 ;
}
void F_161 ( struct V_169 * V_170 , struct V_4 * V_5 )
{
T_4 V_189 , V_190 ;
V_189 = ( T_4 ) F_162 ( V_170 ) << 9 ;
V_190 = F_62 ( V_5 -> V_14 ) ;
if ( V_189 != V_190 ) {
F_159 ( V_191
L_15 ,
V_170 -> V_188 , V_190 , V_189 ) ;
F_163 ( V_5 -> V_14 , V_189 ) ;
F_157 ( V_5 , false ) ;
}
}
int F_164 ( struct V_169 * V_170 )
{
struct V_4 * V_5 ;
int V_15 = 0 ;
if ( V_170 -> V_83 -> F_164 )
V_15 = V_170 -> V_83 -> F_164 ( V_170 ) ;
F_165 ( V_170 ) ;
V_5 = F_138 ( V_170 , 0 ) ;
if ( ! V_5 )
return V_15 ;
F_41 ( & V_5 -> V_115 ) ;
F_161 ( V_170 , V_5 ) ;
V_5 -> V_152 = 0 ;
F_42 ( & V_5 -> V_115 ) ;
F_124 ( V_5 ) ;
return V_15 ;
}
int F_166 ( struct V_4 * V_5 )
{
struct V_169 * V_170 = V_5 -> V_82 ;
const struct V_80 * V_192 = V_170 -> V_83 ;
unsigned int V_193 ;
V_193 = F_167 ( V_170 , V_194 |
V_195 ) ;
if ( ! ( V_193 & V_194 ) )
return 0 ;
F_157 ( V_5 , true ) ;
if ( V_192 -> F_164 )
V_192 -> F_164 ( V_5 -> V_82 ) ;
return 1 ;
}
void F_168 ( struct V_4 * V_5 , T_4 V_26 )
{
unsigned V_196 = F_21 ( V_5 ) ;
F_60 ( V_5 -> V_14 ) ;
F_163 ( V_5 -> V_14 , V_26 ) ;
F_63 ( V_5 -> V_14 ) ;
while ( V_196 < V_27 ) {
if ( V_26 & V_196 )
break;
V_196 <<= 1 ;
}
V_5 -> V_29 = V_196 ;
V_5 -> V_14 -> V_30 = F_23 ( V_196 ) ;
}
static int F_169 ( struct V_4 * V_5 , T_8 V_197 , int V_198 )
{
struct V_169 * V_170 ;
struct V_199 * V_172 ;
int V_15 ;
int V_171 ;
int V_200 = 0 ;
if ( V_197 & V_201 )
V_200 |= V_202 ;
if ( V_197 & V_203 )
V_200 |= V_204 ;
if ( ! V_198 ) {
V_15 = F_170 ( V_5 -> V_14 , V_200 ) ;
if ( V_15 != 0 ) {
F_124 ( V_5 ) ;
return V_15 ;
}
}
V_205:
V_15 = - V_102 ;
V_170 = F_137 ( V_5 -> V_147 , & V_171 ) ;
if ( ! V_170 )
goto V_54;
V_172 = V_170 -> V_83 -> V_172 ;
F_171 ( V_170 ) ;
F_172 ( & V_5 -> V_115 , V_198 ) ;
if ( ! V_5 -> V_206 ) {
V_5 -> V_82 = V_170 ;
V_5 -> V_86 = V_170 -> V_207 ;
V_5 -> V_149 = V_5 ;
if ( F_83 ( V_208 ) && V_170 -> V_83 -> V_96 )
V_5 -> V_14 -> V_209 = V_210 ;
else
V_5 -> V_14 -> V_209 = 0 ;
if ( ! V_171 ) {
V_15 = - V_102 ;
V_5 -> V_97 = F_173 ( V_170 , V_171 ) ;
if ( ! V_5 -> V_97 )
goto V_211;
V_15 = 0 ;
if ( V_170 -> V_83 -> V_212 ) {
V_15 = V_170 -> V_83 -> V_212 ( V_5 , V_197 ) ;
if ( V_15 == - V_213 ) {
F_174 ( V_5 -> V_97 ) ;
V_5 -> V_97 = NULL ;
V_5 -> V_82 = NULL ;
V_5 -> V_86 = NULL ;
F_42 ( & V_5 -> V_115 ) ;
F_175 ( V_170 ) ;
F_140 ( V_170 ) ;
F_139 ( V_172 ) ;
goto V_205;
}
}
if ( ! V_15 ) {
F_168 ( V_5 , ( T_4 ) F_162 ( V_170 ) << 9 ) ;
if ( ! F_82 ( V_5 ) )
V_5 -> V_14 -> V_209 &= ~ V_210 ;
}
if ( V_5 -> V_152 ) {
if ( ! V_15 )
F_176 ( V_170 , V_5 ) ;
else if ( V_15 == - V_214 )
F_177 ( V_170 , V_5 ) ;
}
if ( V_15 )
goto V_211;
} else {
struct V_4 * V_161 ;
V_161 = F_138 ( V_170 , 0 ) ;
V_15 = - V_173 ;
if ( ! V_161 )
goto V_211;
F_178 ( V_198 ) ;
V_15 = F_169 ( V_161 , V_197 , 1 ) ;
if ( V_15 )
goto V_211;
V_5 -> V_149 = V_161 ;
V_5 -> V_97 = F_173 ( V_170 , V_171 ) ;
if ( ! ( V_170 -> V_66 & V_215 ) ||
! V_5 -> V_97 || ! V_5 -> V_97 -> V_107 ) {
V_15 = - V_102 ;
goto V_211;
}
F_168 ( V_5 , ( T_4 ) V_5 -> V_97 -> V_107 << 9 ) ;
if ( ! F_82 ( V_5 ) )
V_5 -> V_14 -> V_209 &= ~ V_210 ;
}
} else {
if ( V_5 -> V_149 == V_5 ) {
V_15 = 0 ;
if ( V_5 -> V_82 -> V_83 -> V_212 )
V_15 = V_5 -> V_82 -> V_83 -> V_212 ( V_5 , V_197 ) ;
if ( V_5 -> V_152 ) {
if ( ! V_15 )
F_176 ( V_5 -> V_82 , V_5 ) ;
else if ( V_15 == - V_214 )
F_177 ( V_5 -> V_82 , V_5 ) ;
}
if ( V_15 )
goto V_216;
}
F_140 ( V_170 ) ;
F_139 ( V_172 ) ;
}
V_5 -> V_206 ++ ;
if ( V_198 )
V_5 -> V_151 ++ ;
F_42 ( & V_5 -> V_115 ) ;
F_175 ( V_170 ) ;
return 0 ;
V_211:
F_174 ( V_5 -> V_97 ) ;
V_5 -> V_82 = NULL ;
V_5 -> V_97 = NULL ;
V_5 -> V_86 = NULL ;
if ( V_5 != V_5 -> V_149 )
F_179 ( V_5 -> V_149 , V_197 , 1 ) ;
V_5 -> V_149 = NULL ;
V_216:
F_42 ( & V_5 -> V_115 ) ;
F_175 ( V_170 ) ;
F_140 ( V_170 ) ;
F_139 ( V_172 ) ;
V_54:
F_124 ( V_5 ) ;
return V_15 ;
}
int F_180 ( struct V_4 * V_5 , T_8 V_197 , void * V_162 )
{
struct V_4 * V_161 = NULL ;
int V_51 ;
F_148 ( ( V_197 & V_217 ) && ! V_162 ) ;
if ( ( V_197 & V_217 ) && V_162 ) {
V_161 = F_136 ( V_5 , V_162 ) ;
if ( F_109 ( V_161 ) ) {
F_124 ( V_5 ) ;
return F_181 ( V_161 ) ;
}
}
V_51 = F_169 ( V_5 , V_197 , 0 ) ;
if ( V_161 ) {
struct V_169 * V_170 = V_161 -> V_82 ;
F_41 ( & V_5 -> V_115 ) ;
F_7 ( & V_123 ) ;
if ( ! V_51 ) {
F_178 ( ! F_129 ( V_5 , V_161 , V_162 ) ) ;
V_161 -> V_218 ++ ;
V_161 -> V_163 = F_129 ;
V_5 -> V_218 ++ ;
V_5 -> V_163 = V_162 ;
}
F_178 ( V_161 -> V_166 != V_162 ) ;
V_161 -> V_166 = NULL ;
F_182 ( & V_161 -> V_166 , 0 ) ;
F_8 ( & V_123 ) ;
if ( ! V_51 && ( V_197 & V_203 ) && ! V_5 -> V_219 &&
( V_170 -> V_66 & V_220 ) ) {
V_5 -> V_219 = true ;
F_171 ( V_170 ) ;
}
F_42 ( & V_5 -> V_115 ) ;
F_124 ( V_161 ) ;
}
return V_51 ;
}
struct V_4 * F_183 ( const char * V_221 , T_8 V_197 ,
void * V_162 )
{
struct V_4 * V_5 ;
int V_104 ;
V_5 = F_184 ( V_221 ) ;
if ( F_109 ( V_5 ) )
return V_5 ;
V_104 = F_180 ( V_5 , V_197 , V_162 ) ;
if ( V_104 )
return F_45 ( V_104 ) ;
if ( ( V_197 & V_203 ) && F_185 ( V_5 ) ) {
F_186 ( V_5 , V_197 ) ;
return F_45 ( - V_222 ) ;
}
return V_5 ;
}
struct V_4 * F_187 ( T_6 V_146 , T_8 V_197 , void * V_162 )
{
struct V_4 * V_5 ;
int V_104 ;
V_5 = F_115 ( V_146 ) ;
if ( ! V_5 )
return F_45 ( - V_173 ) ;
V_104 = F_180 ( V_5 , V_197 , V_162 ) ;
if ( V_104 )
return F_45 ( V_104 ) ;
return V_5 ;
}
static int F_188 ( struct V_2 * V_2 , struct V_41 * V_73 )
{
struct V_4 * V_5 ;
V_73 -> V_223 |= V_224 ;
if ( V_73 -> V_223 & V_225 )
V_73 -> V_226 |= V_227 ;
if ( V_73 -> V_223 & V_228 )
V_73 -> V_226 |= V_217 ;
if ( ( V_73 -> V_223 & V_229 ) == 3 )
V_73 -> V_226 |= V_230 ;
V_5 = F_126 ( V_2 ) ;
if ( V_5 == NULL )
return - V_173 ;
V_73 -> V_42 = V_5 -> V_14 -> V_23 ;
return F_180 ( V_5 , V_73 -> V_226 , V_73 ) ;
}
static void F_179 ( struct V_4 * V_5 , T_8 V_197 , int V_198 )
{
struct V_169 * V_170 = V_5 -> V_82 ;
struct V_4 * V_231 = NULL ;
F_172 ( & V_5 -> V_115 , V_198 ) ;
if ( V_198 )
V_5 -> V_151 -- ;
if ( ! -- V_5 -> V_206 ) {
F_148 ( V_5 -> V_218 ) ;
F_22 ( V_5 ) ;
F_12 ( V_5 ) ;
F_6 ( V_5 ) ;
F_189 ( V_5 -> V_14 ) ;
}
if ( V_5 -> V_149 == V_5 ) {
if ( V_170 -> V_83 -> V_232 )
V_170 -> V_83 -> V_232 ( V_170 , V_197 ) ;
}
if ( ! V_5 -> V_206 ) {
struct V_199 * V_172 = V_170 -> V_83 -> V_172 ;
F_174 ( V_5 -> V_97 ) ;
V_5 -> V_97 = NULL ;
V_5 -> V_82 = NULL ;
if ( V_5 != V_5 -> V_149 )
V_231 = V_5 -> V_149 ;
V_5 -> V_149 = NULL ;
F_140 ( V_170 ) ;
F_139 ( V_172 ) ;
}
F_42 ( & V_5 -> V_115 ) ;
F_124 ( V_5 ) ;
if ( V_231 )
F_179 ( V_231 , V_197 , 1 ) ;
}
void F_186 ( struct V_4 * V_5 , T_8 V_197 )
{
F_41 ( & V_5 -> V_115 ) ;
if ( V_197 & V_217 ) {
bool V_233 ;
F_7 ( & V_123 ) ;
F_148 ( -- V_5 -> V_218 < 0 ) ;
F_148 ( -- V_5 -> V_149 -> V_218 < 0 ) ;
if ( ( V_233 = ! V_5 -> V_218 ) )
V_5 -> V_163 = NULL ;
if ( ! V_5 -> V_149 -> V_218 )
V_5 -> V_149 -> V_163 = NULL ;
F_8 ( & V_123 ) ;
if ( V_233 && V_5 -> V_219 ) {
F_175 ( V_5 -> V_82 ) ;
V_5 -> V_219 = false ;
}
}
F_190 ( V_5 -> V_82 , V_194 ) ;
F_42 ( & V_5 -> V_115 ) ;
F_179 ( V_5 , V_197 , 0 ) ;
}
static int F_191 ( struct V_2 * V_2 , struct V_41 * V_73 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_73 ) ) ;
F_186 ( V_5 , V_73 -> V_226 ) ;
return 0 ;
}
static long F_192 ( struct V_41 * V_41 , unsigned V_234 , unsigned long V_235 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_41 ) ) ;
T_8 V_197 = V_41 -> V_226 ;
if ( V_41 -> V_223 & V_225 )
V_197 |= V_227 ;
else
V_197 &= ~ V_227 ;
return F_193 ( V_5 , V_197 , V_234 , V_235 ) ;
}
T_3 F_194 ( struct V_44 * V_45 , struct V_46 * V_176 )
{
struct V_41 * V_41 = V_45 -> V_48 ;
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_26 = F_62 ( V_14 ) ;
struct V_236 V_237 ;
T_3 V_15 ;
if ( F_185 ( F_3 ( V_14 ) ) )
return - V_238 ;
if ( ! F_195 ( V_176 ) )
return 0 ;
if ( V_45 -> V_239 >= V_26 )
return - V_240 ;
F_196 ( V_176 , V_26 - V_45 -> V_239 ) ;
F_197 ( & V_237 ) ;
V_15 = F_198 ( V_45 , V_176 ) ;
if ( V_15 > 0 )
V_15 = F_199 ( V_45 , V_15 ) ;
F_200 ( & V_237 ) ;
return V_15 ;
}
T_3 F_201 ( struct V_44 * V_45 , struct V_46 * V_177 )
{
struct V_41 * V_41 = V_45 -> V_48 ;
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_26 = F_62 ( V_14 ) ;
T_4 V_64 = V_45 -> V_239 ;
if ( V_64 >= V_26 )
return 0 ;
V_26 -= V_64 ;
F_196 ( V_177 , V_26 ) ;
return F_202 ( V_45 , V_177 ) ;
}
static int F_203 ( struct V_58 * V_58 , T_9 V_50 )
{
struct V_6 * V_241 = F_1 ( V_58 -> V_22 -> V_43 ) -> V_5 . V_150 ;
if ( V_241 && V_241 -> V_55 -> V_242 )
return V_241 -> V_55 -> V_242 ( V_241 , V_58 , V_50 ) ;
return F_204 ( V_58 ) ;
}
static int F_205 ( struct V_21 * V_22 ,
struct V_59 * V_60 )
{
if ( F_206 ( V_22 ) ) {
struct V_4 * V_5 = F_3 ( V_22 -> V_43 ) ;
return F_207 ( V_22 , V_5 , V_60 ) ;
}
return F_208 ( V_22 , V_60 ) ;
}
int F_209 ( struct V_4 * V_5 , unsigned V_234 , unsigned long V_235 )
{
int V_51 ;
T_10 V_243 = F_210 () ;
F_211 ( V_244 ) ;
V_51 = F_193 ( V_5 , 0 , V_234 , V_235 ) ;
F_211 ( V_243 ) ;
return V_51 ;
}
struct V_4 * F_184 ( const char * V_245 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_221 V_221 ;
int error ;
if ( ! V_245 || ! * V_245 )
return F_45 ( - V_28 ) ;
error = F_212 ( V_245 , V_246 , & V_221 ) ;
if ( error )
return F_45 ( error ) ;
V_2 = F_213 ( V_221 . V_125 ) ;
error = - V_247 ;
if ( ! F_214 ( V_2 -> V_153 ) )
goto V_248;
error = - V_222 ;
if ( V_221 . V_249 -> V_250 & V_251 )
goto V_248;
error = - V_173 ;
V_5 = F_126 ( V_2 ) ;
if ( ! V_5 )
goto V_248;
V_54:
F_215 ( & V_221 ) ;
return V_5 ;
V_248:
V_5 = F_45 ( error ) ;
goto V_54;
}
int F_158 ( struct V_4 * V_5 , bool V_186 )
{
struct V_6 * V_7 = F_37 ( V_5 ) ;
int V_51 = 0 ;
if ( V_7 ) {
F_216 ( V_7 ) ;
V_51 = F_217 ( V_7 , V_186 ) ;
F_39 ( V_7 ) ;
}
F_15 ( V_5 ) ;
return V_51 ;
}
void F_218 ( void (* F_219)( struct V_4 * , void * ) , void * V_235 )
{
struct V_2 * V_2 , * V_252 = NULL ;
F_7 ( & V_144 -> V_253 ) ;
F_123 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_21 * V_22 = V_2 -> V_23 ;
F_7 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_17 & ( V_254 | V_255 | V_148 ) ||
V_22 -> V_24 == 0 ) {
F_8 ( & V_2 -> V_16 ) ;
continue;
}
F_220 ( V_2 ) ;
F_8 ( & V_2 -> V_16 ) ;
F_8 ( & V_144 -> V_253 ) ;
F_125 ( V_252 ) ;
V_252 = V_2 ;
F_219 ( F_3 ( V_2 ) , V_235 ) ;
F_7 ( & V_144 -> V_253 ) ;
}
F_8 ( & V_144 -> V_253 ) ;
F_125 ( V_252 ) ;
}
