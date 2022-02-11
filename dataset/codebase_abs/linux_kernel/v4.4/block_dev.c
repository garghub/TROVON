static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_3 ) ;
}
struct V_4 * F_3 ( struct V_2 * V_2 )
{
return & F_1 ( V_2 ) -> V_5 ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_2 * V_2 = V_5 -> V_6 ;
int V_7 ;
F_5 ( & V_2 -> V_8 ) ;
while ( V_2 -> V_9 & V_10 ) {
F_6 ( & V_2 -> V_8 ) ;
V_7 = F_7 ( V_2 , true ) ;
if ( V_7 ) {
char V_11 [ V_12 ] ;
F_8 ( L_1
L_2 ,
F_9 ( V_5 , V_11 ) , V_7 ) ;
}
F_5 ( & V_2 -> V_8 ) ;
}
F_6 ( & V_2 -> V_8 ) ;
}
void F_10 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = V_5 -> V_6 -> V_15 ;
if ( V_14 -> V_16 == 0 && V_14 -> V_17 == 0 )
return;
F_11 () ;
F_12 ( V_14 , 0 ) ;
}
void F_13 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = V_5 -> V_6 -> V_15 ;
if ( V_14 -> V_16 == 0 )
return;
F_11 () ;
F_14 () ;
F_15 ( V_14 , 0 , - 1 ) ;
F_16 ( V_14 ) ;
}
int F_17 ( struct V_4 * V_5 , int V_18 )
{
if ( V_18 > V_19 || V_18 < 512 || ! F_18 ( V_18 ) )
return - V_20 ;
if ( V_18 < F_19 ( V_5 ) )
return - V_20 ;
if ( V_5 -> V_21 != V_18 ) {
F_20 ( V_5 ) ;
V_5 -> V_21 = V_18 ;
V_5 -> V_6 -> V_22 = F_21 ( V_18 ) ;
F_10 ( V_5 ) ;
}
return 0 ;
}
int F_22 ( struct V_23 * V_24 , int V_18 )
{
if ( F_17 ( V_24 -> V_25 , V_18 ) )
return 0 ;
V_24 -> V_26 = V_18 ;
V_24 -> V_27 = F_21 ( V_18 ) ;
return V_24 -> V_26 ;
}
int F_23 ( struct V_23 * V_24 , int V_18 )
{
int V_28 = F_19 ( V_24 -> V_25 ) ;
if ( V_18 < V_28 )
V_18 = V_28 ;
return F_22 ( V_24 , V_18 ) ;
}
static int
F_24 ( struct V_2 * V_2 , T_1 V_29 ,
struct V_30 * V_31 , int V_32 )
{
V_31 -> V_33 = F_3 ( V_2 ) ;
V_31 -> V_34 = V_29 ;
F_25 ( V_31 ) ;
return 0 ;
}
static T_2
F_26 ( struct V_35 * V_36 , struct V_37 * V_38 , T_3 V_39 )
{
struct V_40 * V_40 = V_36 -> V_41 ;
struct V_2 * V_2 = V_40 -> V_42 -> V_43 ;
if ( F_27 ( V_2 ) )
return F_28 ( V_36 , V_2 , V_38 , V_39 , F_24 ,
NULL , V_44 ) ;
return F_29 ( V_36 , V_2 , F_3 ( V_2 ) , V_38 , V_39 ,
F_24 , NULL , NULL ,
V_44 ) ;
}
int F_30 ( struct V_4 * V_5 , int V_45 )
{
if ( ! V_5 )
return 0 ;
if ( ! V_45 )
return F_31 ( V_5 -> V_6 -> V_15 ) ;
return F_32 ( V_5 -> V_6 -> V_15 ) ;
}
int F_20 ( struct V_4 * V_5 )
{
return F_30 ( V_5 , 1 ) ;
}
int F_33 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = F_34 ( V_5 ) ;
if ( V_24 ) {
int V_46 = F_35 ( V_24 ) ;
F_36 ( V_24 ) ;
return V_46 ;
}
return F_20 ( V_5 ) ;
}
struct V_23 * F_37 ( struct V_4 * V_5 )
{
struct V_23 * V_24 ;
int error = 0 ;
F_38 ( & V_5 -> V_47 ) ;
if ( ++ V_5 -> V_48 > 1 ) {
V_24 = F_34 ( V_5 ) ;
F_36 ( V_24 ) ;
F_39 ( & V_5 -> V_47 ) ;
return V_24 ;
}
V_24 = F_40 ( V_5 ) ;
if ( ! V_24 )
goto V_49;
if ( V_24 -> V_50 -> V_51 )
error = V_24 -> V_50 -> V_51 ( V_24 ) ;
else
error = V_51 ( V_24 ) ;
if ( error ) {
F_41 ( V_24 ) ;
V_5 -> V_48 -- ;
F_39 ( & V_5 -> V_47 ) ;
return F_42 ( error ) ;
}
F_41 ( V_24 ) ;
V_49:
F_20 ( V_5 ) ;
F_39 ( & V_5 -> V_47 ) ;
return V_24 ;
}
int F_43 ( struct V_4 * V_5 , struct V_23 * V_24 )
{
int error = - V_20 ;
F_38 ( & V_5 -> V_47 ) ;
if ( ! V_5 -> V_48 )
goto V_49;
error = 0 ;
if ( -- V_5 -> V_48 > 0 )
goto V_49;
if ( ! V_24 )
goto V_49;
if ( V_24 -> V_50 -> V_52 )
error = V_24 -> V_50 -> V_52 ( V_24 ) ;
else
error = V_52 ( V_24 ) ;
if ( error ) {
V_5 -> V_48 ++ ;
F_39 ( & V_5 -> V_47 ) ;
return error ;
}
V_49:
F_39 ( & V_5 -> V_47 ) ;
return 0 ;
}
static int F_44 ( struct V_53 * V_53 , struct V_54 * V_55 )
{
return F_45 ( V_53 , F_24 , V_55 ) ;
}
static int F_46 ( struct V_40 * V_40 , struct V_53 * V_53 )
{
return F_47 ( V_53 , F_24 ) ;
}
static int F_48 ( struct V_40 * V_40 , struct V_13 * V_14 ,
struct V_56 * V_57 , unsigned V_58 )
{
return F_49 ( V_14 , V_57 , V_58 , F_24 ) ;
}
static int F_50 ( struct V_40 * V_40 , struct V_13 * V_14 ,
T_3 V_59 , unsigned V_60 , unsigned V_61 ,
struct V_53 * * V_62 , void * * V_63 )
{
return F_51 ( V_14 , V_59 , V_60 , V_61 , V_62 ,
F_24 ) ;
}
static int F_52 ( struct V_40 * V_40 , struct V_13 * V_14 ,
T_3 V_59 , unsigned V_60 , unsigned V_64 ,
struct V_53 * V_53 , void * V_63 )
{
int V_7 ;
V_7 = F_53 ( V_40 , V_14 , V_59 , V_60 , V_64 , V_53 , V_63 ) ;
F_54 ( V_53 ) ;
F_55 ( V_53 ) ;
return V_7 ;
}
static T_3 F_56 ( struct V_40 * V_40 , T_3 V_39 , int V_65 )
{
struct V_2 * V_6 = V_40 -> V_42 -> V_43 ;
T_3 V_66 ;
F_38 ( & V_6 -> V_67 ) ;
V_66 = F_57 ( V_40 , V_39 , V_65 , F_58 ( V_6 ) ) ;
F_39 ( & V_6 -> V_67 ) ;
return V_66 ;
}
int F_59 ( struct V_40 * V_68 , T_3 V_69 , T_3 V_70 , int V_71 )
{
struct V_2 * V_6 = V_68 -> V_42 -> V_43 ;
struct V_4 * V_5 = F_3 ( V_6 ) ;
int error ;
error = F_60 ( V_68 -> V_42 , V_69 , V_70 ) ;
if ( error )
return error ;
error = F_61 ( V_5 , V_72 , NULL ) ;
if ( error == - V_73 )
error = 0 ;
return error ;
}
int F_62 ( struct V_4 * V_5 , T_1 V_74 ,
struct V_53 * V_53 )
{
const struct V_75 * V_76 = V_5 -> V_77 -> V_78 ;
int V_79 = - V_73 ;
if ( ! V_76 -> V_80 || F_63 ( V_5 ) )
return V_79 ;
V_79 = F_64 ( V_5 -> V_81 , V_72 ) ;
if ( V_79 )
return V_79 ;
V_79 = V_76 -> V_80 ( V_5 , V_74 + F_65 ( V_5 ) , V_53 , V_82 ) ;
F_66 ( V_5 -> V_81 ) ;
return V_79 ;
}
int F_67 ( struct V_4 * V_5 , T_1 V_74 ,
struct V_53 * V_53 , struct V_54 * V_55 )
{
int V_79 ;
int V_83 = ( V_55 -> V_84 == V_85 ) ? V_86 : V_87 ;
const struct V_75 * V_76 = V_5 -> V_77 -> V_78 ;
if ( ! V_76 -> V_80 || F_63 ( V_5 ) )
return - V_73 ;
V_79 = F_64 ( V_5 -> V_81 , V_72 ) ;
if ( V_79 )
return V_79 ;
F_68 ( V_53 ) ;
V_79 = V_76 -> V_80 ( V_5 , V_74 + F_65 ( V_5 ) , V_53 , V_83 ) ;
if ( V_79 )
F_69 ( V_53 ) ;
else
F_54 ( V_53 ) ;
F_66 ( V_5 -> V_81 ) ;
return V_79 ;
}
long F_70 ( struct V_4 * V_5 , T_1 V_74 ,
void T_4 * * V_88 , unsigned long * V_89 , long V_18 )
{
long V_90 ;
const struct V_75 * V_76 = V_5 -> V_77 -> V_78 ;
F_71 () ;
if ( V_18 < 0 )
return V_18 ;
if ( ! V_76 -> V_91 )
return - V_73 ;
if ( ( V_74 + F_72 ( V_18 , 512 ) ) >
F_73 ( V_5 -> V_92 ) )
return - V_93 ;
V_74 += F_65 ( V_5 ) ;
if ( V_74 % ( V_19 / 512 ) )
return - V_20 ;
V_90 = V_76 -> V_91 ( V_5 , V_74 , V_88 , V_89 ) ;
if ( ! V_90 )
return - V_93 ;
return F_74 ( V_90 , V_18 ) ;
}
static struct V_2 * F_75 ( struct V_23 * V_24 )
{
struct V_1 * V_94 = F_76 ( V_95 , V_72 ) ;
if ( ! V_94 )
return NULL ;
return & V_94 -> V_3 ;
}
static void F_77 ( struct V_96 * V_97 )
{
struct V_2 * V_2 = F_2 ( V_97 , struct V_2 , V_98 ) ;
struct V_1 * V_99 = F_1 ( V_2 ) ;
F_78 ( V_95 , V_99 ) ;
}
static void F_79 ( struct V_2 * V_2 )
{
F_80 ( & V_2 -> V_98 , F_77 ) ;
}
static void F_81 ( void * V_100 )
{
struct V_1 * V_94 = (struct V_1 * ) V_100 ;
struct V_4 * V_5 = & V_94 -> V_5 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_82 ( & V_5 -> V_101 ) ;
F_83 ( & V_5 -> V_102 ) ;
F_83 ( & V_5 -> V_103 ) ;
#ifdef F_84
F_83 ( & V_5 -> V_104 ) ;
#endif
F_85 ( & V_94 -> V_3 ) ;
F_82 ( & V_5 -> V_47 ) ;
}
static inline void F_86 ( struct V_2 * V_2 )
{
F_87 ( & V_2 -> V_105 ) ;
V_2 -> V_106 = NULL ;
V_2 -> V_15 = & V_2 -> V_107 ;
}
static void F_88 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = & F_1 ( V_2 ) -> V_5 ;
struct V_56 * V_108 ;
F_89 ( & V_2 -> V_107 ) ;
F_90 ( V_2 ) ;
F_91 ( V_2 ) ;
F_5 ( & V_109 ) ;
while ( ( V_108 = V_5 -> V_102 . V_110 ) != & V_5 -> V_102 ) {
F_86 ( F_92 ( V_108 , struct V_2 , V_105 ) ) ;
}
F_87 ( & V_5 -> V_103 ) ;
F_6 ( & V_109 ) ;
}
static struct V_111 * F_93 ( struct V_112 * V_113 ,
int V_61 , const char * V_114 , void * V_115 )
{
return F_94 ( V_113 , L_3 , & V_116 , NULL , V_117 ) ;
}
void T_5 F_95 ( void )
{
int V_118 ;
static struct V_119 * V_120 ;
V_95 = F_96 ( L_4 , sizeof( struct V_1 ) ,
0 , ( V_121 | V_122 |
V_123 | V_124 ) ,
F_81 ) ;
V_118 = F_97 ( & V_125 ) ;
if ( V_118 )
F_98 ( L_5 ) ;
V_120 = F_99 ( & V_125 ) ;
if ( F_100 ( V_120 ) )
F_98 ( L_6 ) ;
V_126 = V_120 -> V_127 ;
}
static inline unsigned long F_101 ( T_6 V_128 )
{
return F_102 ( V_128 ) + F_103 ( V_128 ) ;
}
static int F_104 ( struct V_2 * V_2 , void * V_115 )
{
return F_1 ( V_2 ) -> V_5 . V_129 == * ( T_6 * ) V_115 ;
}
static int F_105 ( struct V_2 * V_2 , void * V_115 )
{
F_1 ( V_2 ) -> V_5 . V_129 = * ( T_6 * ) V_115 ;
return 0 ;
}
struct V_4 * F_106 ( T_6 V_128 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_2 = F_107 ( V_126 , F_101 ( V_128 ) ,
F_104 , F_105 , & V_128 ) ;
if ( ! V_2 )
return NULL ;
V_5 = & F_1 ( V_2 ) -> V_5 ;
if ( V_2 -> V_9 & V_130 ) {
V_5 -> V_131 = NULL ;
V_5 -> V_132 = NULL ;
V_5 -> V_6 = V_2 ;
V_5 -> V_21 = ( 1 << V_2 -> V_22 ) ;
V_5 -> V_133 = 0 ;
V_5 -> V_134 = 0 ;
V_2 -> V_135 = V_136 ;
V_2 -> V_137 = V_128 ;
V_2 -> V_106 = V_5 ;
V_2 -> V_107 . V_138 = & V_139 ;
F_108 ( & V_2 -> V_107 , V_140 ) ;
F_5 ( & V_109 ) ;
F_109 ( & V_5 -> V_103 , & V_141 ) ;
F_6 ( & V_109 ) ;
F_110 ( V_2 ) ;
}
return V_5 ;
}
struct V_4 * F_111 ( struct V_4 * V_5 )
{
F_112 ( V_5 -> V_6 ) ;
return V_5 ;
}
long F_113 ( void )
{
struct V_4 * V_5 ;
long V_7 = 0 ;
F_5 ( & V_109 ) ;
F_114 (bdev, &all_bdevs, bd_list) {
V_7 += V_5 -> V_6 -> V_15 -> V_16 ;
}
F_6 ( & V_109 ) ;
return V_7 ;
}
void F_115 ( struct V_4 * V_5 )
{
F_116 ( V_5 -> V_6 ) ;
}
static struct V_4 * F_117 ( struct V_2 * V_2 )
{
struct V_4 * V_5 ;
F_5 ( & V_109 ) ;
V_5 = V_2 -> V_106 ;
if ( V_5 ) {
F_112 ( V_5 -> V_6 ) ;
F_6 ( & V_109 ) ;
return V_5 ;
}
F_6 ( & V_109 ) ;
V_5 = F_106 ( V_2 -> V_137 ) ;
if ( V_5 ) {
F_5 ( & V_109 ) ;
if ( ! V_2 -> V_106 ) {
F_112 ( V_5 -> V_6 ) ;
V_2 -> V_106 = V_5 ;
V_2 -> V_15 = V_5 -> V_6 -> V_15 ;
F_109 ( & V_2 -> V_105 , & V_5 -> V_102 ) ;
}
F_6 ( & V_109 ) ;
}
return V_5 ;
}
void F_118 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = NULL ;
F_5 ( & V_109 ) ;
if ( ! F_119 ( V_2 -> V_142 ) )
V_5 = V_2 -> V_106 ;
F_86 ( V_2 ) ;
F_6 ( & V_109 ) ;
if ( V_5 )
F_116 ( V_5 -> V_6 ) ;
}
static bool F_120 ( struct V_4 * V_5 , struct V_4 * V_143 ,
void * V_144 )
{
if ( V_5 -> V_145 == V_144 )
return true ;
else if ( V_5 -> V_145 != NULL )
return false ;
else if ( V_5 -> V_131 == V_5 )
return true ;
else if ( V_143 -> V_145 == F_120 )
return true ;
else if ( V_143 -> V_145 != NULL )
return false ;
else
return true ;
}
static int F_121 ( struct V_4 * V_5 ,
struct V_4 * V_143 , void * V_144 )
{
V_146:
if ( ! F_120 ( V_5 , V_143 , V_144 ) )
return - V_147 ;
if ( V_143 -> V_148 ) {
T_7 * V_149 = F_122 ( & V_143 -> V_148 , 0 ) ;
F_123 ( V_45 ) ;
F_124 ( V_149 , & V_45 , V_150 ) ;
F_6 ( & V_109 ) ;
F_125 () ;
F_126 ( V_149 , & V_45 ) ;
F_5 ( & V_109 ) ;
goto V_146;
}
return 0 ;
}
static struct V_4 * F_127 ( struct V_4 * V_5 ,
void * V_144 )
{
struct V_151 * V_152 ;
struct V_4 * V_143 ;
int V_153 , V_118 ;
F_71 () ;
V_152 = F_128 ( V_5 -> V_129 , & V_153 ) ;
if ( ! V_152 )
return F_42 ( - V_154 ) ;
if ( V_153 )
V_143 = F_129 ( V_152 , 0 ) ;
else
V_143 = F_111 ( V_5 ) ;
F_130 ( V_152 -> V_78 -> V_155 ) ;
F_131 ( V_152 ) ;
if ( ! V_143 )
return F_42 ( - V_156 ) ;
F_5 ( & V_109 ) ;
V_118 = F_121 ( V_5 , V_143 , V_144 ) ;
if ( V_118 == 0 ) {
V_143 -> V_148 = V_144 ;
F_6 ( & V_109 ) ;
return V_143 ;
} else {
F_6 ( & V_109 ) ;
F_115 ( V_143 ) ;
return F_42 ( V_118 ) ;
}
}
static struct V_157 * F_132 ( struct V_4 * V_5 ,
struct V_151 * V_152 )
{
struct V_157 * V_144 ;
F_114 (holder, &bdev->bd_holder_disks, list)
if ( V_144 -> V_152 == V_152 )
return V_144 ;
return NULL ;
}
static int F_133 ( struct V_158 * V_159 , struct V_158 * V_160 )
{
return F_134 ( V_159 , V_160 , F_135 ( V_160 ) ) ;
}
static void F_136 ( struct V_158 * V_159 , struct V_158 * V_160 )
{
F_137 ( V_159 , F_135 ( V_160 ) ) ;
}
int F_138 ( struct V_4 * V_5 , struct V_151 * V_152 )
{
struct V_157 * V_144 ;
int V_7 = 0 ;
F_38 ( & V_5 -> V_101 ) ;
F_139 ( ! V_5 -> V_145 ) ;
if ( F_140 ( ! V_152 -> V_161 || ! V_5 -> V_92 -> V_162 ) )
goto V_163;
V_144 = F_132 ( V_5 , V_152 ) ;
if ( V_144 ) {
V_144 -> V_164 ++ ;
goto V_163;
}
V_144 = F_141 ( sizeof( * V_144 ) , V_72 ) ;
if ( ! V_144 ) {
V_7 = - V_156 ;
goto V_163;
}
F_83 ( & V_144 -> V_165 ) ;
V_144 -> V_152 = V_152 ;
V_144 -> V_164 = 1 ;
V_7 = F_133 ( V_152 -> V_161 , & F_142 ( V_5 -> V_92 ) -> V_166 ) ;
if ( V_7 )
goto V_167;
V_7 = F_133 ( V_5 -> V_92 -> V_162 , & F_143 ( V_152 ) -> V_166 ) ;
if ( V_7 )
goto V_168;
F_144 ( V_5 -> V_92 -> V_162 ) ;
F_109 ( & V_144 -> V_165 , & V_5 -> V_104 ) ;
goto V_163;
V_168:
F_136 ( V_152 -> V_161 , & F_142 ( V_5 -> V_92 ) -> V_166 ) ;
V_167:
F_145 ( V_144 ) ;
V_163:
F_39 ( & V_5 -> V_101 ) ;
return V_7 ;
}
void F_146 ( struct V_4 * V_5 , struct V_151 * V_152 )
{
struct V_157 * V_144 ;
F_38 ( & V_5 -> V_101 ) ;
V_144 = F_132 ( V_5 , V_152 ) ;
if ( ! F_139 ( V_144 == NULL ) && ! -- V_144 -> V_164 ) {
F_136 ( V_152 -> V_161 , & F_142 ( V_5 -> V_92 ) -> V_166 ) ;
F_136 ( V_5 -> V_92 -> V_162 ,
& F_143 ( V_152 ) -> V_166 ) ;
F_147 ( V_5 -> V_92 -> V_162 ) ;
F_87 ( & V_144 -> V_165 ) ;
F_145 ( V_144 ) ;
}
F_39 ( & V_5 -> V_101 ) ;
}
static void F_148 ( struct V_4 * V_5 , bool V_169 )
{
if ( F_149 ( V_5 , V_169 ) ) {
char V_11 [ V_12 ] = L_7 ;
if ( V_5 -> V_77 )
F_150 ( V_5 -> V_77 , 0 , V_11 ) ;
F_151 ( V_170 L_8
L_9 , V_11 ) ;
}
if ( ! V_5 -> V_77 )
return;
if ( F_152 ( V_5 -> V_77 ) )
V_5 -> V_134 = 1 ;
}
void F_153 ( struct V_151 * V_152 , struct V_4 * V_5 )
{
T_3 V_171 , V_172 ;
V_171 = ( T_3 ) F_154 ( V_152 ) << 9 ;
V_172 = F_58 ( V_5 -> V_6 ) ;
if ( V_171 != V_172 ) {
char V_11 [ V_12 ] ;
F_150 ( V_152 , 0 , V_11 ) ;
F_151 ( V_173
L_10 ,
V_11 , V_172 , V_171 ) ;
F_155 ( V_5 -> V_6 , V_171 ) ;
F_148 ( V_5 , false ) ;
}
}
int F_156 ( struct V_151 * V_152 )
{
struct V_4 * V_5 ;
int V_7 = 0 ;
if ( V_152 -> V_78 -> F_156 )
V_7 = V_152 -> V_78 -> F_156 ( V_152 ) ;
F_157 ( V_152 ) ;
V_5 = F_129 ( V_152 , 0 ) ;
if ( ! V_5 )
return V_7 ;
F_38 ( & V_5 -> V_101 ) ;
F_153 ( V_152 , V_5 ) ;
V_5 -> V_134 = 0 ;
F_39 ( & V_5 -> V_101 ) ;
F_115 ( V_5 ) ;
return V_7 ;
}
int F_158 ( struct V_4 * V_5 )
{
struct V_151 * V_152 = V_5 -> V_77 ;
const struct V_75 * V_174 = V_152 -> V_78 ;
unsigned int V_175 ;
V_175 = F_159 ( V_152 , V_176 |
V_177 ) ;
if ( ! ( V_175 & V_176 ) )
return 0 ;
F_148 ( V_5 , true ) ;
if ( V_174 -> F_156 )
V_174 -> F_156 ( V_5 -> V_77 ) ;
return 1 ;
}
void F_160 ( struct V_4 * V_5 , T_3 V_18 )
{
unsigned V_178 = F_19 ( V_5 ) ;
F_38 ( & V_5 -> V_6 -> V_67 ) ;
F_155 ( V_5 -> V_6 , V_18 ) ;
F_39 ( & V_5 -> V_6 -> V_67 ) ;
while ( V_178 < V_179 ) {
if ( V_18 & V_178 )
break;
V_178 <<= 1 ;
}
V_5 -> V_21 = V_178 ;
V_5 -> V_6 -> V_22 = F_21 ( V_178 ) ;
}
static int F_161 ( struct V_4 * V_5 , T_8 V_180 , int V_181 )
{
struct V_151 * V_152 ;
struct V_182 * V_155 ;
int V_7 ;
int V_153 ;
int V_183 = 0 ;
if ( V_180 & V_184 )
V_183 |= V_185 ;
if ( V_180 & V_186 )
V_183 |= V_187 ;
if ( ! V_181 ) {
V_7 = F_162 ( V_5 -> V_6 , V_183 ) ;
if ( V_7 != 0 ) {
F_115 ( V_5 ) ;
return V_7 ;
}
}
V_188:
V_7 = - V_154 ;
V_152 = F_128 ( V_5 -> V_129 , & V_153 ) ;
if ( ! V_152 )
goto V_49;
V_155 = V_152 -> V_78 -> V_155 ;
F_163 ( V_152 ) ;
F_164 ( & V_5 -> V_101 , V_181 ) ;
if ( ! V_5 -> V_189 ) {
V_5 -> V_77 = V_152 ;
V_5 -> V_81 = V_152 -> V_190 ;
V_5 -> V_131 = V_5 ;
V_5 -> V_6 -> V_191 = V_152 -> V_78 -> V_91 ? V_192 : 0 ;
if ( ! V_153 ) {
V_7 = - V_154 ;
V_5 -> V_92 = F_165 ( V_152 , V_153 ) ;
if ( ! V_5 -> V_92 )
goto V_193;
V_7 = 0 ;
if ( V_152 -> V_78 -> V_194 ) {
V_7 = V_152 -> V_78 -> V_194 ( V_5 , V_180 ) ;
if ( V_7 == - V_195 ) {
F_166 ( V_5 -> V_92 ) ;
V_5 -> V_92 = NULL ;
V_5 -> V_77 = NULL ;
V_5 -> V_81 = NULL ;
F_39 ( & V_5 -> V_101 ) ;
F_167 ( V_152 ) ;
F_131 ( V_152 ) ;
F_130 ( V_155 ) ;
goto V_188;
}
}
if ( ! V_7 )
F_160 ( V_5 , ( T_3 ) F_154 ( V_152 ) << 9 ) ;
if ( V_5 -> V_134 ) {
if ( ! V_7 )
F_168 ( V_152 , V_5 ) ;
else if ( V_7 == - V_196 )
F_169 ( V_152 , V_5 ) ;
}
if ( V_7 )
goto V_193;
} else {
struct V_4 * V_143 ;
V_143 = F_129 ( V_152 , 0 ) ;
V_7 = - V_156 ;
if ( ! V_143 )
goto V_193;
F_170 ( V_181 ) ;
V_7 = F_161 ( V_143 , V_180 , 1 ) ;
if ( V_7 )
goto V_193;
V_5 -> V_131 = V_143 ;
V_5 -> V_92 = F_165 ( V_152 , V_153 ) ;
if ( ! ( V_152 -> V_61 & V_197 ) ||
! V_5 -> V_92 || ! V_5 -> V_92 -> V_198 ) {
V_7 = - V_154 ;
goto V_193;
}
F_160 ( V_5 , ( T_3 ) V_5 -> V_92 -> V_198 << 9 ) ;
if ( ( V_5 -> V_92 -> V_199 % ( V_19 / 512 ) ) ||
( V_5 -> V_92 -> V_198 % ( V_19 / 512 ) ) )
V_5 -> V_6 -> V_191 &= ~ V_192 ;
}
} else {
if ( V_5 -> V_131 == V_5 ) {
V_7 = 0 ;
if ( V_5 -> V_77 -> V_78 -> V_194 )
V_7 = V_5 -> V_77 -> V_78 -> V_194 ( V_5 , V_180 ) ;
if ( V_5 -> V_134 ) {
if ( ! V_7 )
F_168 ( V_5 -> V_77 , V_5 ) ;
else if ( V_7 == - V_196 )
F_169 ( V_5 -> V_77 , V_5 ) ;
}
if ( V_7 )
goto V_200;
}
F_131 ( V_152 ) ;
F_130 ( V_155 ) ;
}
V_5 -> V_189 ++ ;
if ( V_181 )
V_5 -> V_133 ++ ;
F_39 ( & V_5 -> V_101 ) ;
F_167 ( V_152 ) ;
return 0 ;
V_193:
F_166 ( V_5 -> V_92 ) ;
V_5 -> V_77 = NULL ;
V_5 -> V_92 = NULL ;
V_5 -> V_81 = NULL ;
if ( V_5 != V_5 -> V_131 )
F_171 ( V_5 -> V_131 , V_180 , 1 ) ;
V_5 -> V_131 = NULL ;
V_200:
F_39 ( & V_5 -> V_101 ) ;
F_167 ( V_152 ) ;
F_131 ( V_152 ) ;
F_130 ( V_155 ) ;
V_49:
F_115 ( V_5 ) ;
return V_7 ;
}
int F_172 ( struct V_4 * V_5 , T_8 V_180 , void * V_144 )
{
struct V_4 * V_143 = NULL ;
int V_46 ;
F_139 ( ( V_180 & V_201 ) && ! V_144 ) ;
if ( ( V_180 & V_201 ) && V_144 ) {
V_143 = F_127 ( V_5 , V_144 ) ;
if ( F_100 ( V_143 ) ) {
F_115 ( V_5 ) ;
return F_173 ( V_143 ) ;
}
}
V_46 = F_161 ( V_5 , V_180 , 0 ) ;
if ( V_143 ) {
struct V_151 * V_152 = V_143 -> V_77 ;
F_38 ( & V_5 -> V_101 ) ;
F_5 ( & V_109 ) ;
if ( ! V_46 ) {
F_170 ( ! F_120 ( V_5 , V_143 , V_144 ) ) ;
V_143 -> V_202 ++ ;
V_143 -> V_145 = F_120 ;
V_5 -> V_202 ++ ;
V_5 -> V_145 = V_144 ;
}
F_170 ( V_143 -> V_148 != V_144 ) ;
V_143 -> V_148 = NULL ;
F_174 ( & V_143 -> V_148 , 0 ) ;
F_6 ( & V_109 ) ;
if ( ! V_46 && ( V_180 & V_186 ) && ! V_5 -> V_203 &&
( V_152 -> V_61 & V_204 ) ) {
V_5 -> V_203 = true ;
F_163 ( V_152 ) ;
}
F_39 ( & V_5 -> V_101 ) ;
F_115 ( V_143 ) ;
}
return V_46 ;
}
struct V_4 * F_175 ( const char * V_205 , T_8 V_180 ,
void * V_144 )
{
struct V_4 * V_5 ;
int V_118 ;
V_5 = F_176 ( V_205 ) ;
if ( F_100 ( V_5 ) )
return V_5 ;
V_118 = F_172 ( V_5 , V_180 , V_144 ) ;
if ( V_118 )
return F_42 ( V_118 ) ;
if ( ( V_180 & V_186 ) && F_177 ( V_5 ) ) {
F_178 ( V_5 , V_180 ) ;
return F_42 ( - V_206 ) ;
}
return V_5 ;
}
struct V_4 * F_179 ( T_6 V_128 , T_8 V_180 , void * V_144 )
{
struct V_4 * V_5 ;
int V_118 ;
V_5 = F_106 ( V_128 ) ;
if ( ! V_5 )
return F_42 ( - V_156 ) ;
V_118 = F_172 ( V_5 , V_180 , V_144 ) ;
if ( V_118 )
return F_42 ( V_118 ) ;
return V_5 ;
}
static int F_180 ( struct V_2 * V_2 , struct V_40 * V_68 )
{
struct V_4 * V_5 ;
V_68 -> V_207 |= V_208 ;
if ( V_68 -> V_207 & V_209 )
V_68 -> V_210 |= V_211 ;
if ( V_68 -> V_207 & V_212 )
V_68 -> V_210 |= V_201 ;
if ( ( V_68 -> V_207 & V_213 ) == 3 )
V_68 -> V_210 |= V_214 ;
V_5 = F_117 ( V_2 ) ;
if ( V_5 == NULL )
return - V_156 ;
V_68 -> V_42 = V_5 -> V_6 -> V_15 ;
return F_172 ( V_5 , V_68 -> V_210 , V_68 ) ;
}
static void F_171 ( struct V_4 * V_5 , T_8 V_180 , int V_181 )
{
struct V_151 * V_152 = V_5 -> V_77 ;
struct V_4 * V_215 = NULL ;
F_164 ( & V_5 -> V_101 , V_181 ) ;
if ( V_181 )
V_5 -> V_133 -- ;
if ( ! -- V_5 -> V_189 ) {
F_139 ( V_5 -> V_202 ) ;
F_20 ( V_5 ) ;
F_10 ( V_5 ) ;
F_4 ( V_5 ) ;
F_181 ( V_5 -> V_6 ) ;
}
if ( V_5 -> V_131 == V_5 ) {
if ( V_152 -> V_78 -> V_216 )
V_152 -> V_78 -> V_216 ( V_152 , V_180 ) ;
}
if ( ! V_5 -> V_189 ) {
struct V_182 * V_155 = V_152 -> V_78 -> V_155 ;
F_166 ( V_5 -> V_92 ) ;
V_5 -> V_92 = NULL ;
V_5 -> V_77 = NULL ;
if ( V_5 != V_5 -> V_131 )
V_215 = V_5 -> V_131 ;
V_5 -> V_131 = NULL ;
F_131 ( V_152 ) ;
F_130 ( V_155 ) ;
}
F_39 ( & V_5 -> V_101 ) ;
F_115 ( V_5 ) ;
if ( V_215 )
F_171 ( V_215 , V_180 , 1 ) ;
}
void F_178 ( struct V_4 * V_5 , T_8 V_180 )
{
F_38 ( & V_5 -> V_101 ) ;
if ( V_180 & V_201 ) {
bool V_217 ;
F_5 ( & V_109 ) ;
F_139 ( -- V_5 -> V_202 < 0 ) ;
F_139 ( -- V_5 -> V_131 -> V_202 < 0 ) ;
if ( ( V_217 = ! V_5 -> V_202 ) )
V_5 -> V_145 = NULL ;
if ( ! V_5 -> V_131 -> V_202 )
V_5 -> V_131 -> V_145 = NULL ;
F_6 ( & V_109 ) ;
if ( V_217 && V_5 -> V_203 ) {
F_167 ( V_5 -> V_77 ) ;
V_5 -> V_203 = false ;
}
}
F_182 ( V_5 -> V_77 , V_176 ) ;
F_39 ( & V_5 -> V_101 ) ;
F_171 ( V_5 , V_180 , 0 ) ;
}
static int F_183 ( struct V_2 * V_2 , struct V_40 * V_68 )
{
struct V_4 * V_5 = F_3 ( V_68 -> V_42 -> V_43 ) ;
F_178 ( V_5 , V_68 -> V_210 ) ;
return 0 ;
}
static long F_184 ( struct V_40 * V_40 , unsigned V_218 , unsigned long V_219 )
{
struct V_4 * V_5 = F_3 ( V_40 -> V_42 -> V_43 ) ;
T_8 V_180 = V_40 -> V_210 ;
if ( V_40 -> V_207 & V_209 )
V_180 |= V_211 ;
else
V_180 &= ~ V_211 ;
return F_185 ( V_5 , V_180 , V_218 , V_219 ) ;
}
T_2 F_186 ( struct V_35 * V_36 , struct V_37 * V_159 )
{
struct V_40 * V_40 = V_36 -> V_41 ;
struct V_2 * V_6 = V_40 -> V_42 -> V_43 ;
T_3 V_18 = F_58 ( V_6 ) ;
struct V_220 V_221 ;
T_2 V_7 ;
if ( F_177 ( F_3 ( V_6 ) ) )
return - V_222 ;
if ( ! F_187 ( V_159 ) )
return 0 ;
if ( V_36 -> V_223 >= V_18 )
return - V_224 ;
F_188 ( V_159 , V_18 - V_36 -> V_223 ) ;
F_189 ( & V_221 ) ;
V_7 = F_190 ( V_36 , V_159 ) ;
if ( V_7 > 0 ) {
T_2 V_118 ;
V_118 = F_191 ( V_40 , V_36 -> V_223 - V_7 , V_7 ) ;
if ( V_118 < 0 )
V_7 = V_118 ;
}
F_192 ( & V_221 ) ;
return V_7 ;
}
T_2 F_193 ( struct V_35 * V_36 , struct V_37 * V_160 )
{
struct V_40 * V_40 = V_36 -> V_41 ;
struct V_2 * V_6 = V_40 -> V_42 -> V_43 ;
T_3 V_18 = F_58 ( V_6 ) ;
T_3 V_59 = V_36 -> V_223 ;
if ( V_59 >= V_18 )
return 0 ;
V_18 -= V_59 ;
F_188 ( V_160 , V_18 ) ;
return F_194 ( V_36 , V_160 ) ;
}
static int F_195 ( struct V_53 * V_53 , T_9 V_45 )
{
struct V_23 * V_225 = F_1 ( V_53 -> V_14 -> V_43 ) -> V_5 . V_132 ;
if ( V_225 && V_225 -> V_50 -> V_226 )
return V_225 -> V_50 -> V_226 ( V_225 , V_53 , V_45 ) ;
return F_196 ( V_53 ) ;
}
int F_197 ( struct V_4 * V_5 , unsigned V_218 , unsigned long V_219 )
{
int V_46 ;
T_10 V_227 = F_198 () ;
F_199 ( V_228 ) ;
V_46 = F_185 ( V_5 , 0 , V_218 , V_219 ) ;
F_199 ( V_227 ) ;
return V_46 ;
}
struct V_4 * F_176 ( const char * V_229 )
{
struct V_4 * V_5 ;
struct V_2 * V_2 ;
struct V_205 V_205 ;
int error ;
if ( ! V_229 || ! * V_229 )
return F_42 ( - V_20 ) ;
error = F_200 ( V_229 , V_230 , & V_205 ) ;
if ( error )
return F_42 ( error ) ;
V_2 = F_201 ( V_205 . V_111 ) ;
error = - V_231 ;
if ( ! F_202 ( V_2 -> V_135 ) )
goto V_232;
error = - V_206 ;
if ( V_205 . V_233 -> V_234 & V_235 )
goto V_232;
error = - V_156 ;
V_5 = F_117 ( V_2 ) ;
if ( ! V_5 )
goto V_232;
V_49:
F_203 ( & V_205 ) ;
return V_5 ;
V_232:
V_5 = F_42 ( error ) ;
goto V_49;
}
int F_149 ( struct V_4 * V_5 , bool V_169 )
{
struct V_23 * V_24 = F_34 ( V_5 ) ;
int V_46 = 0 ;
if ( V_24 ) {
F_204 ( V_24 ) ;
V_46 = F_205 ( V_24 , V_169 ) ;
F_36 ( V_24 ) ;
}
F_13 ( V_5 ) ;
return V_46 ;
}
void F_206 ( void (* F_207)( struct V_4 * , void * ) , void * V_219 )
{
struct V_2 * V_2 , * V_236 = NULL ;
F_5 ( & V_126 -> V_237 ) ;
F_114 (inode, &blockdev_superblock->s_inodes, i_sb_list) {
struct V_13 * V_14 = V_2 -> V_15 ;
F_5 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_9 & ( V_238 | V_239 | V_130 ) ||
V_14 -> V_16 == 0 ) {
F_6 ( & V_2 -> V_8 ) ;
continue;
}
F_208 ( V_2 ) ;
F_6 ( & V_2 -> V_8 ) ;
F_6 ( & V_126 -> V_237 ) ;
F_116 ( V_236 ) ;
V_236 = V_2 ;
F_207 ( F_3 ( V_2 ) , V_219 ) ;
F_5 ( & V_126 -> V_237 ) ;
}
F_6 ( & V_126 -> V_237 ) ;
F_116 ( V_236 ) ;
}
