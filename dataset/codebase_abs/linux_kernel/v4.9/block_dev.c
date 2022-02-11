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
return F_30 ( V_45 , V_2 , F_3 ( V_2 ) , V_47 ,
F_26 , NULL , NULL ,
V_49 ) ;
}
int F_31 ( struct V_4 * V_5 , int V_50 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_50 )
return F_32 ( V_5 -> V_14 -> V_23 ) ;
return F_33 ( V_5 -> V_14 -> V_23 ) ;
}
int F_22 ( struct V_4 * V_5 )
{
return F_31 ( V_5 , 1 ) ;
}
int F_34 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_35 ( V_5 ) ;
if ( V_7 ) {
int V_51 = F_36 ( V_7 ) ;
F_37 ( V_7 ) ;
return V_51 ;
}
return F_22 ( V_5 ) ;
}
struct V_6 * F_38 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_39 ( & V_5 -> V_52 ) ;
if ( ++ V_5 -> V_53 > 1 ) {
V_7 = F_35 ( V_5 ) ;
if ( V_7 )
F_37 ( V_7 ) ;
F_40 ( & V_5 -> V_52 ) ;
return V_7 ;
}
V_7 = F_41 ( V_5 ) ;
if ( ! V_7 )
goto V_54;
if ( V_7 -> V_55 -> V_56 )
error = V_7 -> V_55 -> V_56 ( V_7 ) ;
else
error = V_56 ( V_7 ) ;
if ( error ) {
F_42 ( V_7 ) ;
V_5 -> V_53 -- ;
F_40 ( & V_5 -> V_52 ) ;
return F_43 ( error ) ;
}
F_42 ( V_7 ) ;
V_54:
F_22 ( V_5 ) ;
F_40 ( & V_5 -> V_52 ) ;
return V_7 ;
}
int F_44 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
int error = - V_28 ;
F_39 ( & V_5 -> V_52 ) ;
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
if ( error )
V_5 -> V_53 ++ ;
V_54:
F_40 ( & V_5 -> V_52 ) ;
return error ;
}
static int F_45 ( struct V_58 * V_58 , struct V_59 * V_60 )
{
return F_46 ( V_58 , F_26 , V_60 ) ;
}
static int F_47 ( struct V_41 * V_41 , struct V_58 * V_58 )
{
return F_48 ( V_58 , F_26 ) ;
}
static int F_49 ( struct V_41 * V_41 , struct V_21 * V_22 ,
struct V_61 * V_62 , unsigned V_63 )
{
return F_50 ( V_22 , V_62 , V_63 , F_26 ) ;
}
static int F_51 ( struct V_41 * V_41 , struct V_21 * V_22 ,
T_4 V_64 , unsigned V_65 , unsigned V_66 ,
struct V_58 * * V_67 , void * * V_68 )
{
return F_52 ( V_22 , V_64 , V_65 , V_66 , V_67 ,
F_26 ) ;
}
static int F_53 ( struct V_41 * V_41 , struct V_21 * V_22 ,
T_4 V_64 , unsigned V_65 , unsigned V_69 ,
struct V_58 * V_58 , void * V_68 )
{
int V_15 ;
V_15 = F_54 ( V_41 , V_22 , V_64 , V_65 , V_69 , V_58 , V_68 ) ;
F_55 ( V_58 ) ;
F_56 ( V_58 ) ;
return V_15 ;
}
static T_4 F_57 ( struct V_41 * V_41 , T_4 V_70 , int V_71 )
{
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_72 ;
F_58 ( V_14 ) ;
V_72 = F_59 ( V_41 , V_70 , V_71 , F_60 ( V_14 ) ) ;
F_61 ( V_14 ) ;
return V_72 ;
}
int F_62 ( struct V_41 * V_73 , T_4 V_74 , T_4 V_75 , int V_76 )
{
struct V_2 * V_14 = F_28 ( V_73 ) ;
struct V_4 * V_5 = F_3 ( V_14 ) ;
int error ;
error = F_63 ( V_73 -> V_42 , V_74 , V_75 ) ;
if ( error )
return error ;
error = F_64 ( V_5 , V_77 , NULL ) ;
if ( error == - V_78 )
error = 0 ;
return error ;
}
int F_65 ( struct V_4 * V_5 , T_2 V_79 ,
struct V_58 * V_58 )
{
const struct V_80 * V_81 = V_5 -> V_82 -> V_83 ;
int V_84 = - V_78 ;
if ( ! V_81 -> V_85 || F_66 ( V_5 ) )
return V_84 ;
V_84 = F_67 ( V_5 -> V_86 , false ) ;
if ( V_84 )
return V_84 ;
V_84 = V_81 -> V_85 ( V_5 , V_79 + F_68 ( V_5 ) , V_58 , false ) ;
F_69 ( V_5 -> V_86 ) ;
return V_84 ;
}
int F_70 ( struct V_4 * V_5 , T_2 V_79 ,
struct V_58 * V_58 , struct V_59 * V_60 )
{
int V_84 ;
const struct V_80 * V_81 = V_5 -> V_82 -> V_83 ;
if ( ! V_81 -> V_85 || F_66 ( V_5 ) )
return - V_78 ;
V_84 = F_67 ( V_5 -> V_86 , false ) ;
if ( V_84 )
return V_84 ;
F_71 ( V_58 ) ;
V_84 = V_81 -> V_85 ( V_5 , V_79 + F_68 ( V_5 ) , V_58 , true ) ;
if ( V_84 )
F_72 ( V_58 ) ;
else
F_55 ( V_58 ) ;
F_69 ( V_5 -> V_86 ) ;
return V_84 ;
}
long F_73 ( struct V_4 * V_5 , struct V_87 * V_88 )
{
T_2 V_79 = V_88 -> V_79 ;
long V_89 , V_26 = V_88 -> V_26 ;
const struct V_80 * V_81 = V_5 -> V_82 -> V_83 ;
F_74 () ;
if ( V_26 < 0 )
return V_26 ;
if ( ! F_75 ( F_76 ( V_5 ) ) || ! V_81 -> V_90 )
return - V_78 ;
if ( ( V_79 + F_77 ( V_26 , 512 ) ) >
F_78 ( V_5 -> V_91 ) )
return - V_92 ;
V_79 += F_68 ( V_5 ) ;
if ( V_79 % ( V_27 / 512 ) )
return - V_28 ;
V_89 = V_81 -> V_90 ( V_5 , V_79 , & V_88 -> V_93 , & V_88 -> V_94 , V_26 ) ;
if ( ! V_89 )
return - V_92 ;
if ( V_89 > 0 && V_89 & ~ V_95 )
return - V_96 ;
return F_79 ( V_89 , V_26 ) ;
}
int F_80 ( struct V_6 * V_7 , int V_97 )
{
struct V_87 V_88 = {
. V_79 = 0 ,
. V_26 = V_27 ,
} ;
int V_98 ;
if ( V_97 != V_27 ) {
F_81 ( V_7 , V_99 , L_4 ) ;
return - V_28 ;
}
V_98 = F_73 ( V_7 -> V_31 , & V_88 ) ;
if ( V_98 < 0 ) {
switch ( V_98 ) {
case - V_78 :
F_81 ( V_7 , V_99 ,
L_5 ) ;
break;
case - V_28 :
F_81 ( V_7 , V_99 ,
L_6 ) ;
break;
default:
F_81 ( V_7 , V_99 ,
L_7 , V_98 ) ;
}
return V_98 ;
}
return 0 ;
}
bool F_82 ( struct V_4 * V_5 )
{
struct V_87 V_88 = {
. V_26 = V_27 ,
} ;
if ( ! F_83 ( V_100 ) )
return false ;
V_88 . V_79 = 0 ;
if ( F_73 ( V_5 , & V_88 ) < 0 )
return false ;
V_88 . V_79 = V_5 -> V_91 -> V_101 - ( V_27 / 512 ) ;
if ( F_73 ( V_5 , & V_88 ) < 0 )
return false ;
return true ;
}
static struct V_2 * F_84 ( struct V_6 * V_7 )
{
struct V_1 * V_102 = F_85 ( V_103 , V_77 ) ;
if ( ! V_102 )
return NULL ;
return & V_102 -> V_3 ;
}
static void F_86 ( struct V_104 * V_105 )
{
struct V_2 * V_2 = F_2 ( V_105 , struct V_2 , V_106 ) ;
struct V_1 * V_107 = F_1 ( V_2 ) ;
F_87 ( V_103 , V_107 ) ;
}
static void F_88 ( struct V_2 * V_2 )
{
F_89 ( & V_2 -> V_106 , F_86 ) ;
}
static void F_90 ( void * V_108 )
{
struct V_1 * V_102 = (struct V_1 * ) V_108 ;
struct V_4 * V_5 = & V_102 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_91 ( & V_5 -> V_109 ) ;
F_92 ( & V_5 -> V_110 ) ;
#ifdef F_93
F_92 ( & V_5 -> V_111 ) ;
#endif
F_94 ( & V_102 -> V_3 ) ;
F_91 ( & V_5 -> V_52 ) ;
}
static void F_95 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
F_96 ( & V_2 -> V_112 ) ;
F_97 ( V_2 ) ;
F_98 ( V_2 ) ;
F_7 ( & V_113 ) ;
F_99 ( & V_5 -> V_110 ) ;
F_8 ( & V_113 ) ;
}
static struct V_114 * F_100 ( struct V_115 * V_116 ,
int V_66 , const char * V_117 , void * V_118 )
{
struct V_114 * V_119 ;
V_119 = F_101 ( V_116 , L_8 , & V_120 , NULL , V_121 ) ;
if ( ! F_102 ( V_119 ) )
V_119 -> V_122 -> V_123 |= V_124 ;
return V_119 ;
}
void T_5 F_103 ( void )
{
int V_98 ;
static struct V_125 * V_126 ;
V_103 = F_104 ( L_9 , sizeof( struct V_1 ) ,
0 , ( V_127 | V_128 |
V_129 | V_130 | V_131 ) ,
F_90 ) ;
V_98 = F_105 ( & V_132 ) ;
if ( V_98 )
F_106 ( L_10 ) ;
V_126 = F_107 ( & V_132 ) ;
if ( F_102 ( V_126 ) )
F_106 ( L_11 ) ;
V_133 = V_126 -> V_134 ;
}
static inline unsigned long F_108 ( T_6 V_135 )
{
return F_109 ( V_135 ) + F_110 ( V_135 ) ;
}
static int F_111 ( struct V_2 * V_2 , void * V_118 )
{
return F_1 ( V_2 ) -> V_5 . V_136 == * ( T_6 * ) V_118 ;
}
static int F_112 ( struct V_2 * V_2 , void * V_118 )
{
F_1 ( V_2 ) -> V_5 . V_136 = * ( T_6 * ) V_118 ;
return 0 ;
}
struct V_4 * F_113 ( T_6 V_135 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_114 ( V_133 , F_108 ( V_135 ) ,
F_111 , F_112 , & V_135 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_17 & V_137 ) {
V_5 -> V_138 = NULL ;
V_5 -> V_139 = NULL ;
V_5 -> V_14 = V_2 ;
V_5 -> V_29 = ( 1 << V_2 -> V_30 ) ;
V_5 -> V_140 = 0 ;
V_5 -> V_141 = 0 ;
V_2 -> V_142 = V_143 ;
V_2 -> V_144 = V_135 ;
V_2 -> V_145 = V_5 ;
V_2 -> V_112 . V_146 = & V_147 ;
F_115 ( & V_2 -> V_112 , V_148 ) ;
F_7 ( & V_113 ) ;
F_116 ( & V_5 -> V_110 , & V_149 ) ;
F_8 ( & V_113 ) ;
F_117 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_118 ( struct V_4 * V_5 )
{
F_119 ( V_5 -> V_14 ) ;
return V_5 ;
}
long F_120 ( void )
{
struct V_4 * V_5 ;
long V_15 = 0 ;
F_7 ( & V_113 ) ;
F_121 (bdev, &all_bdevs, bd_list) {
V_15 += V_5 -> V_14 -> V_23 -> V_24 ;
}
F_8 ( & V_113 ) ;
return V_15 ;
}
void F_122 ( struct V_4 * V_5 )
{
F_123 ( V_5 -> V_14 ) ;
}
static struct V_4 * F_124 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_7 ( & V_113 ) ;
V_5 = V_2 -> V_145 ;
if ( V_5 ) {
F_118 ( V_5 ) ;
F_8 ( & V_113 ) ;
return V_5 ;
}
F_8 ( & V_113 ) ;
V_5 = F_113 ( V_2 -> V_144 ) ;
if ( V_5 ) {
F_7 ( & V_113 ) ;
if ( ! V_2 -> V_145 ) {
F_118 ( V_5 ) ;
V_2 -> V_145 = V_5 ;
V_2 -> V_23 = V_5 -> V_14 -> V_23 ;
}
F_8 ( & V_113 ) ;
}
return V_5 ;
}
void F_125 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_7 ( & V_113 ) ;
if ( ! F_126 ( V_2 -> V_150 ) )
V_5 = V_2 -> V_145 ;
V_2 -> V_145 = NULL ;
V_2 -> V_23 = & V_2 -> V_112 ;
F_8 ( & V_113 ) ;
if ( V_5 )
F_122 ( V_5 ) ;
}
static bool F_127 ( struct V_4 * V_5 , struct V_4 * V_151 ,
void * V_152 )
{
if ( V_5 -> V_153 == V_152 )
return true ;
else if ( V_5 -> V_153 != NULL )
return false ;
else if ( V_5 -> V_138 == V_5 )
return true ;
else if ( V_151 -> V_153 == F_127 )
return true ;
else if ( V_151 -> V_153 != NULL )
return false ;
else
return true ;
}
static int F_128 ( struct V_4 * V_5 ,
struct V_4 * V_151 , void * V_152 )
{
V_154:
if ( ! F_127 ( V_5 , V_151 , V_152 ) )
return - V_155 ;
if ( V_151 -> V_156 ) {
T_7 * V_157 = F_129 ( & V_151 -> V_156 , 0 ) ;
F_130 ( V_50 ) ;
F_131 ( V_157 , & V_50 , V_158 ) ;
F_8 ( & V_113 ) ;
F_132 () ;
F_133 ( V_157 , & V_50 ) ;
F_7 ( & V_113 ) ;
goto V_154;
}
return 0 ;
}
static struct V_4 * F_134 ( struct V_4 * V_5 ,
void * V_152 )
{
struct V_159 * V_160 ;
struct V_4 * V_151 ;
int V_161 , V_98 ;
F_74 () ;
V_160 = F_135 ( V_5 -> V_136 , & V_161 ) ;
if ( ! V_160 )
return F_43 ( - V_96 ) ;
if ( V_161 )
V_151 = F_136 ( V_160 , 0 ) ;
else
V_151 = F_118 ( V_5 ) ;
F_137 ( V_160 -> V_83 -> V_162 ) ;
F_138 ( V_160 ) ;
if ( ! V_151 )
return F_43 ( - V_163 ) ;
F_7 ( & V_113 ) ;
V_98 = F_128 ( V_5 , V_151 , V_152 ) ;
if ( V_98 == 0 ) {
V_151 -> V_156 = V_152 ;
F_8 ( & V_113 ) ;
return V_151 ;
} else {
F_8 ( & V_113 ) ;
F_122 ( V_151 ) ;
return F_43 ( V_98 ) ;
}
}
static struct V_164 * F_139 ( struct V_4 * V_5 ,
struct V_159 * V_160 )
{
struct V_164 * V_152 ;
F_121 (holder, &bdev->bd_holder_disks, list)
if ( V_152 -> V_160 == V_160 )
return V_152 ;
return NULL ;
}
static int F_140 ( struct V_165 * V_166 , struct V_165 * V_167 )
{
return F_141 ( V_166 , V_167 , F_142 ( V_167 ) ) ;
}
static void F_143 ( struct V_165 * V_166 , struct V_165 * V_167 )
{
F_144 ( V_166 , F_142 ( V_167 ) ) ;
}
int F_145 ( struct V_4 * V_5 , struct V_159 * V_160 )
{
struct V_164 * V_152 ;
int V_15 = 0 ;
F_39 ( & V_5 -> V_109 ) ;
F_146 ( ! V_5 -> V_153 ) ;
if ( F_147 ( ! V_160 -> V_168 || ! V_5 -> V_91 -> V_169 ) )
goto V_170;
V_152 = F_139 ( V_5 , V_160 ) ;
if ( V_152 ) {
V_152 -> V_171 ++ ;
goto V_170;
}
V_152 = F_148 ( sizeof( * V_152 ) , V_77 ) ;
if ( ! V_152 ) {
V_15 = - V_163 ;
goto V_170;
}
F_92 ( & V_152 -> V_172 ) ;
V_152 -> V_160 = V_160 ;
V_152 -> V_171 = 1 ;
V_15 = F_140 ( V_160 -> V_168 , & F_149 ( V_5 -> V_91 ) -> V_173 ) ;
if ( V_15 )
goto V_174;
V_15 = F_140 ( V_5 -> V_91 -> V_169 , & F_150 ( V_160 ) -> V_173 ) ;
if ( V_15 )
goto V_175;
F_151 ( V_5 -> V_91 -> V_169 ) ;
F_116 ( & V_152 -> V_172 , & V_5 -> V_111 ) ;
goto V_170;
V_175:
F_143 ( V_160 -> V_168 , & F_149 ( V_5 -> V_91 ) -> V_173 ) ;
V_174:
F_152 ( V_152 ) ;
V_170:
F_40 ( & V_5 -> V_109 ) ;
return V_15 ;
}
void F_153 ( struct V_4 * V_5 , struct V_159 * V_160 )
{
struct V_164 * V_152 ;
F_39 ( & V_5 -> V_109 ) ;
V_152 = F_139 ( V_5 , V_160 ) ;
if ( ! F_146 ( V_152 == NULL ) && ! -- V_152 -> V_171 ) {
F_143 ( V_160 -> V_168 , & F_149 ( V_5 -> V_91 ) -> V_173 ) ;
F_143 ( V_5 -> V_91 -> V_169 ,
& F_150 ( V_160 ) -> V_173 ) ;
F_154 ( V_5 -> V_91 -> V_169 ) ;
F_99 ( & V_152 -> V_172 ) ;
F_152 ( V_152 ) ;
}
F_40 ( & V_5 -> V_109 ) ;
}
static void F_155 ( struct V_4 * V_5 , bool V_176 )
{
if ( F_156 ( V_5 , V_176 ) ) {
F_157 ( V_177 L_12
L_13 ,
V_5 -> V_82 ? V_5 -> V_82 -> V_178 : L_14 ) ;
}
if ( ! V_5 -> V_82 )
return;
if ( F_158 ( V_5 -> V_82 ) )
V_5 -> V_141 = 1 ;
}
void F_159 ( struct V_159 * V_160 , struct V_4 * V_5 )
{
T_4 V_179 , V_180 ;
V_179 = ( T_4 ) F_160 ( V_160 ) << 9 ;
V_180 = F_60 ( V_5 -> V_14 ) ;
if ( V_179 != V_180 ) {
F_157 ( V_181
L_15 ,
V_160 -> V_178 , V_180 , V_179 ) ;
F_161 ( V_5 -> V_14 , V_179 ) ;
F_155 ( V_5 , false ) ;
}
}
int F_162 ( struct V_159 * V_160 )
{
struct V_4 * V_5 ;
int V_15 = 0 ;
if ( V_160 -> V_83 -> F_162 )
V_15 = V_160 -> V_83 -> F_162 ( V_160 ) ;
F_163 ( V_160 ) ;
V_5 = F_136 ( V_160 , 0 ) ;
if ( ! V_5 )
return V_15 ;
F_39 ( & V_5 -> V_109 ) ;
F_159 ( V_160 , V_5 ) ;
V_5 -> V_141 = 0 ;
F_40 ( & V_5 -> V_109 ) ;
F_122 ( V_5 ) ;
return V_15 ;
}
int F_164 ( struct V_4 * V_5 )
{
struct V_159 * V_160 = V_5 -> V_82 ;
const struct V_80 * V_182 = V_160 -> V_83 ;
unsigned int V_183 ;
V_183 = F_165 ( V_160 , V_184 |
V_185 ) ;
if ( ! ( V_183 & V_184 ) )
return 0 ;
F_155 ( V_5 , true ) ;
if ( V_182 -> F_162 )
V_182 -> F_162 ( V_5 -> V_82 ) ;
return 1 ;
}
void F_166 ( struct V_4 * V_5 , T_4 V_26 )
{
unsigned V_186 = F_21 ( V_5 ) ;
F_58 ( V_5 -> V_14 ) ;
F_161 ( V_5 -> V_14 , V_26 ) ;
F_61 ( V_5 -> V_14 ) ;
while ( V_186 < V_27 ) {
if ( V_26 & V_186 )
break;
V_186 <<= 1 ;
}
V_5 -> V_29 = V_186 ;
V_5 -> V_14 -> V_30 = F_23 ( V_186 ) ;
}
static int F_167 ( struct V_4 * V_5 , T_8 V_187 , int V_188 )
{
struct V_159 * V_160 ;
struct V_189 * V_162 ;
int V_15 ;
int V_161 ;
int V_190 = 0 ;
if ( V_187 & V_191 )
V_190 |= V_192 ;
if ( V_187 & V_193 )
V_190 |= V_194 ;
if ( ! V_188 ) {
V_15 = F_168 ( V_5 -> V_14 , V_190 ) ;
if ( V_15 != 0 ) {
F_122 ( V_5 ) ;
return V_15 ;
}
}
V_195:
V_15 = - V_96 ;
V_160 = F_135 ( V_5 -> V_136 , & V_161 ) ;
if ( ! V_160 )
goto V_54;
V_162 = V_160 -> V_83 -> V_162 ;
F_169 ( V_160 ) ;
F_170 ( & V_5 -> V_109 , V_188 ) ;
if ( ! V_5 -> V_196 ) {
V_5 -> V_82 = V_160 ;
V_5 -> V_86 = V_160 -> V_197 ;
V_5 -> V_138 = V_5 ;
if ( ! V_161 ) {
V_15 = - V_96 ;
V_5 -> V_91 = F_171 ( V_160 , V_161 ) ;
if ( ! V_5 -> V_91 )
goto V_198;
V_15 = 0 ;
if ( V_160 -> V_83 -> V_199 ) {
V_15 = V_160 -> V_83 -> V_199 ( V_5 , V_187 ) ;
if ( V_15 == - V_200 ) {
F_172 ( V_5 -> V_91 ) ;
V_5 -> V_91 = NULL ;
V_5 -> V_82 = NULL ;
V_5 -> V_86 = NULL ;
F_40 ( & V_5 -> V_109 ) ;
F_173 ( V_160 ) ;
F_138 ( V_160 ) ;
F_137 ( V_162 ) ;
goto V_195;
}
}
if ( ! V_15 )
F_166 ( V_5 , ( T_4 ) F_160 ( V_160 ) << 9 ) ;
if ( V_5 -> V_141 ) {
if ( ! V_15 )
F_174 ( V_160 , V_5 ) ;
else if ( V_15 == - V_201 )
F_175 ( V_160 , V_5 ) ;
}
if ( V_15 )
goto V_198;
} else {
struct V_4 * V_151 ;
V_151 = F_136 ( V_160 , 0 ) ;
V_15 = - V_163 ;
if ( ! V_151 )
goto V_198;
F_176 ( V_188 ) ;
V_15 = F_167 ( V_151 , V_187 , 1 ) ;
if ( V_15 )
goto V_198;
V_5 -> V_138 = V_151 ;
V_5 -> V_91 = F_171 ( V_160 , V_161 ) ;
if ( ! ( V_160 -> V_66 & V_202 ) ||
! V_5 -> V_91 || ! V_5 -> V_91 -> V_101 ) {
V_15 = - V_96 ;
goto V_198;
}
F_166 ( V_5 , ( T_4 ) V_5 -> V_91 -> V_101 << 9 ) ;
}
} else {
if ( V_5 -> V_138 == V_5 ) {
V_15 = 0 ;
if ( V_5 -> V_82 -> V_83 -> V_199 )
V_15 = V_5 -> V_82 -> V_83 -> V_199 ( V_5 , V_187 ) ;
if ( V_5 -> V_141 ) {
if ( ! V_15 )
F_174 ( V_5 -> V_82 , V_5 ) ;
else if ( V_15 == - V_201 )
F_175 ( V_5 -> V_82 , V_5 ) ;
}
if ( V_15 )
goto V_203;
}
F_138 ( V_160 ) ;
F_137 ( V_162 ) ;
}
V_5 -> V_196 ++ ;
if ( V_188 )
V_5 -> V_140 ++ ;
F_40 ( & V_5 -> V_109 ) ;
F_173 ( V_160 ) ;
return 0 ;
V_198:
F_172 ( V_5 -> V_91 ) ;
V_5 -> V_82 = NULL ;
V_5 -> V_91 = NULL ;
V_5 -> V_86 = NULL ;
if ( V_5 != V_5 -> V_138 )
F_177 ( V_5 -> V_138 , V_187 , 1 ) ;
V_5 -> V_138 = NULL ;
V_203:
F_40 ( & V_5 -> V_109 ) ;
F_173 ( V_160 ) ;
F_138 ( V_160 ) ;
F_137 ( V_162 ) ;
V_54:
F_122 ( V_5 ) ;
return V_15 ;
}
int F_178 ( struct V_4 * V_5 , T_8 V_187 , void * V_152 )
{
struct V_4 * V_151 = NULL ;
int V_51 ;
F_146 ( ( V_187 & V_204 ) && ! V_152 ) ;
if ( ( V_187 & V_204 ) && V_152 ) {
V_151 = F_134 ( V_5 , V_152 ) ;
if ( F_102 ( V_151 ) ) {
F_122 ( V_5 ) ;
return F_179 ( V_151 ) ;
}
}
V_51 = F_167 ( V_5 , V_187 , 0 ) ;
if ( V_151 ) {
struct V_159 * V_160 = V_151 -> V_82 ;
F_39 ( & V_5 -> V_109 ) ;
F_7 ( & V_113 ) ;
if ( ! V_51 ) {
F_176 ( ! F_127 ( V_5 , V_151 , V_152 ) ) ;
V_151 -> V_205 ++ ;
V_151 -> V_153 = F_127 ;
V_5 -> V_205 ++ ;
V_5 -> V_153 = V_152 ;
}
F_176 ( V_151 -> V_156 != V_152 ) ;
V_151 -> V_156 = NULL ;
F_180 ( & V_151 -> V_156 , 0 ) ;
F_8 ( & V_113 ) ;
if ( ! V_51 && ( V_187 & V_193 ) && ! V_5 -> V_206 &&
( V_160 -> V_66 & V_207 ) ) {
V_5 -> V_206 = true ;
F_169 ( V_160 ) ;
}
F_40 ( & V_5 -> V_109 ) ;
F_122 ( V_151 ) ;
}
return V_51 ;
}
struct V_4 * F_181 ( const char * V_208 , T_8 V_187 ,
void * V_152 )
{
struct V_4 * V_5 ;
int V_98 ;
V_5 = F_182 ( V_208 ) ;
if ( F_102 ( V_5 ) )
return V_5 ;
V_98 = F_178 ( V_5 , V_187 , V_152 ) ;
if ( V_98 )
return F_43 ( V_98 ) ;
if ( ( V_187 & V_193 ) && F_183 ( V_5 ) ) {
F_184 ( V_5 , V_187 ) ;
return F_43 ( - V_209 ) ;
}
return V_5 ;
}
struct V_4 * F_185 ( T_6 V_135 , T_8 V_187 , void * V_152 )
{
struct V_4 * V_5 ;
int V_98 ;
V_5 = F_113 ( V_135 ) ;
if ( ! V_5 )
return F_43 ( - V_163 ) ;
V_98 = F_178 ( V_5 , V_187 , V_152 ) ;
if ( V_98 )
return F_43 ( V_98 ) ;
return V_5 ;
}
static int F_186 ( struct V_2 * V_2 , struct V_41 * V_73 )
{
struct V_4 * V_5 ;
V_73 -> V_210 |= V_211 ;
if ( V_73 -> V_210 & V_212 )
V_73 -> V_213 |= V_214 ;
if ( V_73 -> V_210 & V_215 )
V_73 -> V_213 |= V_204 ;
if ( ( V_73 -> V_210 & V_216 ) == 3 )
V_73 -> V_213 |= V_217 ;
V_5 = F_124 ( V_2 ) ;
if ( V_5 == NULL )
return - V_163 ;
V_73 -> V_42 = V_5 -> V_14 -> V_23 ;
return F_178 ( V_5 , V_73 -> V_213 , V_73 ) ;
}
static void F_177 ( struct V_4 * V_5 , T_8 V_187 , int V_188 )
{
struct V_159 * V_160 = V_5 -> V_82 ;
struct V_4 * V_218 = NULL ;
F_170 ( & V_5 -> V_109 , V_188 ) ;
if ( V_188 )
V_5 -> V_140 -- ;
if ( ! -- V_5 -> V_196 ) {
F_146 ( V_5 -> V_205 ) ;
F_22 ( V_5 ) ;
F_12 ( V_5 ) ;
F_6 ( V_5 ) ;
F_187 ( V_5 -> V_14 ) ;
}
if ( V_5 -> V_138 == V_5 ) {
if ( V_160 -> V_83 -> V_219 )
V_160 -> V_83 -> V_219 ( V_160 , V_187 ) ;
}
if ( ! V_5 -> V_196 ) {
struct V_189 * V_162 = V_160 -> V_83 -> V_162 ;
F_172 ( V_5 -> V_91 ) ;
V_5 -> V_91 = NULL ;
V_5 -> V_82 = NULL ;
if ( V_5 != V_5 -> V_138 )
V_218 = V_5 -> V_138 ;
V_5 -> V_138 = NULL ;
F_138 ( V_160 ) ;
F_137 ( V_162 ) ;
}
F_40 ( & V_5 -> V_109 ) ;
F_122 ( V_5 ) ;
if ( V_218 )
F_177 ( V_218 , V_187 , 1 ) ;
}
void F_184 ( struct V_4 * V_5 , T_8 V_187 )
{
F_39 ( & V_5 -> V_109 ) ;
if ( V_187 & V_204 ) {
bool V_220 ;
F_7 ( & V_113 ) ;
F_146 ( -- V_5 -> V_205 < 0 ) ;
F_146 ( -- V_5 -> V_138 -> V_205 < 0 ) ;
if ( ( V_220 = ! V_5 -> V_205 ) )
V_5 -> V_153 = NULL ;
if ( ! V_5 -> V_138 -> V_205 )
V_5 -> V_138 -> V_153 = NULL ;
F_8 ( & V_113 ) ;
if ( V_220 && V_5 -> V_206 ) {
F_173 ( V_5 -> V_82 ) ;
V_5 -> V_206 = false ;
}
}
F_188 ( V_5 -> V_82 , V_184 ) ;
F_40 ( & V_5 -> V_109 ) ;
F_177 ( V_5 , V_187 , 0 ) ;
}
static int F_189 ( struct V_2 * V_2 , struct V_41 * V_73 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_73 ) ) ;
F_184 ( V_5 , V_73 -> V_213 ) ;
return 0 ;
}
static long F_190 ( struct V_41 * V_41 , unsigned V_221 , unsigned long V_222 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_41 ) ) ;
T_8 V_187 = V_41 -> V_213 ;
if ( V_41 -> V_210 & V_212 )
V_187 |= V_214 ;
else
V_187 &= ~ V_214 ;
return F_191 ( V_5 , V_187 , V_221 , V_222 ) ;
}
T_3 F_192 ( struct V_44 * V_45 , struct V_46 * V_166 )
{
struct V_41 * V_41 = V_45 -> V_48 ;
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_26 = F_60 ( V_14 ) ;
struct V_223 V_224 ;
T_3 V_15 ;
if ( F_183 ( F_3 ( V_14 ) ) )
return - V_225 ;
if ( ! F_193 ( V_166 ) )
return 0 ;
if ( V_45 -> V_226 >= V_26 )
return - V_227 ;
F_194 ( V_166 , V_26 - V_45 -> V_226 ) ;
F_195 ( & V_224 ) ;
V_15 = F_196 ( V_45 , V_166 ) ;
if ( V_15 > 0 )
V_15 = F_197 ( V_45 , V_15 ) ;
F_198 ( & V_224 ) ;
return V_15 ;
}
T_3 F_199 ( struct V_44 * V_45 , struct V_46 * V_167 )
{
struct V_41 * V_41 = V_45 -> V_48 ;
struct V_2 * V_14 = F_28 ( V_41 ) ;
T_4 V_26 = F_60 ( V_14 ) ;
T_4 V_64 = V_45 -> V_226 ;
if ( V_64 >= V_26 )
return 0 ;
V_26 -= V_64 ;
F_194 ( V_167 , V_26 ) ;
return F_200 ( V_45 , V_167 ) ;
}
static int F_201 ( struct V_58 * V_58 , T_9 V_50 )
{
struct V_6 * V_228 = F_1 ( V_58 -> V_22 -> V_43 ) -> V_5 . V_139 ;
if ( V_228 && V_228 -> V_55 -> V_229 )
return V_228 -> V_55 -> V_229 ( V_228 , V_58 , V_50 ) ;
return F_202 ( V_58 ) ;
}
static int F_203 ( struct V_21 * V_22 ,
struct V_59 * V_60 )
{
if ( F_204 ( V_22 ) ) {
struct V_4 * V_5 = F_3 ( V_22 -> V_43 ) ;
return F_205 ( V_22 , V_5 , V_60 ) ;
}
return F_206 ( V_22 , V_60 ) ;
}
static long F_207 ( struct V_41 * V_41 , int V_187 , T_4 V_74 ,
T_4 V_65 )
{
struct V_4 * V_5 = F_3 ( F_28 ( V_41 ) ) ;
struct V_230 * V_231 = F_76 ( V_5 ) ;
struct V_21 * V_22 ;
T_4 V_75 = V_74 + V_65 - 1 ;
T_4 V_232 ;
int error ;
if ( V_187 & ~ V_233 )
return - V_78 ;
V_232 = F_60 ( V_5 -> V_14 ) ;
if ( V_74 >= V_232 )
return - V_28 ;
if ( V_75 >= V_232 ) {
if ( V_187 & V_234 ) {
V_65 = V_232 - V_74 ;
V_75 = V_74 + V_65 - 1 ;
} else
return - V_28 ;
}
if ( ( V_74 | V_65 ) & ( F_21 ( V_5 ) - 1 ) )
return - V_28 ;
V_22 = V_5 -> V_14 -> V_23 ;
F_208 ( V_22 , V_74 , V_75 ) ;
switch ( V_187 ) {
case V_235 :
case V_235 | V_234 :
error = F_209 ( V_5 , V_74 >> 9 , V_65 >> 9 ,
V_77 , false ) ;
break;
case V_236 | V_234 :
if ( ! F_210 ( V_231 ) || ! V_231 -> V_237 . V_238 )
return - V_78 ;
error = F_211 ( V_5 , V_74 >> 9 , V_65 >> 9 ,
V_77 , 0 ) ;
break;
case V_236 | V_234 | V_239 :
if ( ! F_210 ( V_231 ) )
return - V_78 ;
error = F_211 ( V_5 , V_74 >> 9 , V_65 >> 9 ,
V_77 , 0 ) ;
break;
default:
return - V_78 ;
}
if ( error )
return error ;
return F_212 ( V_22 ,
V_74 >> V_240 ,
V_75 >> V_240 ) ;
}
int F_213 ( struct V_4 * V_5 , unsigned V_221 , unsigned long V_222 )
{
int V_51 ;
T_10 V_241 = F_214 () ;
F_215 ( V_242 ) ;
V_51 = F_191 ( V_5 , 0 , V_221 , V_222 ) ;
F_215 ( V_241 ) ;
return V_51 ;
}
struct V_4 * F_182 ( const char * V_243 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_208 V_208 ;
int error ;
if ( ! V_243 || ! * V_243 )
return F_43 ( - V_28 ) ;
error = F_216 ( V_243 , V_244 , & V_208 ) ;
if ( error )
return F_43 ( error ) ;
V_2 = F_217 ( V_208 . V_114 ) ;
error = - V_245 ;
if ( ! F_218 ( V_2 -> V_142 ) )
goto V_246;
error = - V_209 ;
if ( ! F_219 ( & V_208 ) )
goto V_246;
error = - V_163 ;
V_5 = F_124 ( V_2 ) ;
if ( ! V_5 )
goto V_246;
V_54:
F_220 ( & V_208 ) ;
return V_5 ;
V_246:
V_5 = F_43 ( error ) ;
goto V_54;
}
int F_156 ( struct V_4 * V_5 , bool V_176 )
{
struct V_6 * V_7 = F_35 ( V_5 ) ;
int V_51 = 0 ;
if ( V_7 ) {
F_221 ( V_7 ) ;
V_51 = F_222 ( V_7 , V_176 ) ;
F_37 ( V_7 ) ;
}
F_15 ( V_5 ) ;
return V_51 ;
}
void F_223 ( void (* F_224)( struct V_4 * , void * ) , void * V_222 )
{
struct V_2 * V_2 , * V_247 = NULL ;
F_7 ( & V_133 -> V_248 ) ;
F_121 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_21 * V_22 = V_2 -> V_23 ;
F_7 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_17 & ( V_249 | V_250 | V_137 ) ||
V_22 -> V_24 == 0 ) {
F_8 ( & V_2 -> V_16 ) ;
continue;
}
F_225 ( V_2 ) ;
F_8 ( & V_2 -> V_16 ) ;
F_8 ( & V_133 -> V_248 ) ;
F_123 ( V_247 ) ;
V_247 = V_2 ;
F_224 ( F_3 ( V_2 ) , V_222 ) ;
F_7 ( & V_133 -> V_248 ) ;
}
F_8 ( & V_133 -> V_248 ) ;
F_123 ( V_247 ) ;
}
