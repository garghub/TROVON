static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static const char * F_3 ( int V_5 )
{
switch ( V_5 ) {
case V_6 : return L_1 ;
case V_7 : return L_2 ;
case V_8 : return L_3 ;
case V_9 : return L_4 ;
case V_10 : return L_5 ;
}
return L_6 ;
}
static void F_4 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
int error = V_12 -> V_13 ? - V_14 : 0 ;
struct V_15 * V_16 = V_12 -> V_16 ;
unsigned long V_17 ;
F_5 ( F_1 ( V_3 ) , L_7 , V_12 ,
error ? L_8 : L_9 ) ;
F_6 ( V_16 -> V_18 , V_17 ) ;
F_7 ( V_12 , error ) ;
F_8 ( V_16 -> V_18 , V_17 ) ;
}
static void F_9 ( struct V_2 * V_3 , int V_19 )
{
if ( V_19 )
F_10 ( & V_3 -> V_20 ) ;
if ( V_3 -> V_21 ) {
F_11 ( F_2 ( V_3 -> V_4 ) , L_10 ) ;
F_12 ( V_3 -> V_21 , V_22 ) ;
V_3 -> V_21 = NULL ;
}
if ( V_19 )
F_13 ( & V_3 -> V_20 ) ;
}
static void F_14 ( unsigned long V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_23 ;
F_15 ( V_26 L_11 ,
V_25 -> V_27 , V_25 -> V_28 ) ;
F_16 ( V_29 , V_25 ) ;
}
static int F_17 ( struct V_2 * V_3 , int V_30 , void * V_31 , int V_32 ,
int V_33 )
{
struct V_34 * V_21 = V_3 -> V_21 ;
int V_35 ;
struct V_36 V_37 ;
struct V_38 V_39 ;
T_1 V_40 , V_41 ;
unsigned long V_42 = V_43 -> V_17 ;
if ( F_18 ( ! V_21 ) ) {
F_19 ( F_2 ( V_3 -> V_4 ) ,
L_12 ,
( V_30 ? L_13 : L_14 ) ) ;
return - V_44 ;
}
F_20 ( & V_40 , F_21 ( V_29 ) ) ;
F_22 ( V_45 , & V_40 , & V_41 ) ;
V_43 -> V_17 |= V_46 ;
do {
V_21 -> V_47 -> V_48 = V_49 | V_50 ;
V_39 . V_51 = V_31 ;
V_39 . V_52 = V_32 ;
V_37 . V_53 = NULL ;
V_37 . V_54 = 0 ;
V_37 . V_55 = NULL ;
V_37 . V_56 = 0 ;
V_37 . V_33 = V_33 | V_57 ;
if ( V_30 ) {
struct V_58 V_59 ;
if ( V_3 -> V_60 ) {
F_23 ( & V_59 ) ;
V_59 . V_61 = F_14 ;
V_59 . V_62 = ( unsigned long ) V_43 ;
V_59 . V_63 = V_64 + V_3 -> V_60 ;
F_24 ( & V_59 ) ;
}
V_35 = F_25 ( V_21 , & V_37 , & V_39 , 1 , V_32 ) ;
if ( V_3 -> V_60 )
F_26 ( & V_59 ) ;
} else
V_35 = F_27 ( V_21 , & V_37 , & V_39 , 1 , V_32 ,
V_37 . V_33 ) ;
if ( F_28 ( V_43 ) ) {
T_2 V_65 ;
F_15 ( V_26 L_15 ,
F_29 ( V_43 ) , V_43 -> V_27 ,
F_30 ( V_43 , & V_43 -> V_40 , & V_65 ) ) ;
V_35 = - V_66 ;
F_9 ( V_3 , ! V_30 ) ;
break;
}
if ( V_35 <= 0 ) {
if ( V_35 == 0 )
V_35 = - V_67 ;
break;
}
V_32 -= V_35 ;
V_31 += V_35 ;
} while ( V_32 > 0 );
F_22 ( V_45 , & V_41 , NULL ) ;
F_31 ( V_43 , V_42 , V_46 ) ;
return V_35 ;
}
static inline int F_32 ( struct V_2 * V_3 , struct V_68 * V_69 ,
int V_17 )
{
int V_35 ;
void * V_70 = F_33 ( V_69 -> V_71 ) ;
V_35 = F_17 ( V_3 , 1 , V_70 + V_69 -> V_72 ,
V_69 -> V_73 , V_17 ) ;
F_34 ( V_69 -> V_71 ) ;
return V_35 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
int V_35 , V_17 ;
struct V_74 V_11 ;
unsigned long V_32 = F_36 ( V_12 ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_75 = F_37 ( V_76 ) ;
V_11 . type = F_37 ( F_38 ( V_12 ) ) ;
if ( F_38 ( V_12 ) != V_9 && F_38 ( V_12 ) != V_8 ) {
V_11 . V_77 = F_39 ( ( V_78 ) F_40 ( V_12 ) << 9 ) ;
V_11 . V_79 = F_37 ( V_32 ) ;
}
memcpy ( V_11 . V_80 , & V_12 , sizeof( V_12 ) ) ;
F_5 ( F_1 ( V_3 ) , L_16 ,
V_12 , F_3 ( F_38 ( V_12 ) ) ,
( unsigned long long ) F_40 ( V_12 ) << 9 , F_36 ( V_12 ) ) ;
V_35 = F_17 ( V_3 , 1 , & V_11 , sizeof( V_11 ) ,
( F_38 ( V_12 ) == V_7 ) ? V_81 : 0 ) ;
if ( V_35 <= 0 ) {
F_19 ( F_2 ( V_3 -> V_4 ) ,
L_17 , V_35 ) ;
return - V_14 ;
}
if ( F_38 ( V_12 ) == V_7 ) {
struct V_82 V_83 ;
struct V_68 V_69 ;
F_41 (bvec, req, iter) {
V_17 = 0 ;
if ( ! F_42 ( V_69 , V_83 ) )
V_17 = V_81 ;
F_5 ( F_1 ( V_3 ) , L_18 ,
V_12 , V_69 . V_73 ) ;
V_35 = F_32 ( V_3 , & V_69 , V_17 ) ;
if ( V_35 <= 0 ) {
F_19 ( F_2 ( V_3 -> V_4 ) ,
L_19 ,
V_35 ) ;
return - V_14 ;
}
}
}
return 0 ;
}
static struct V_11 * F_43 ( struct V_2 * V_3 ,
struct V_11 * V_84 )
{
struct V_11 * V_12 , * V_85 ;
int V_86 ;
V_86 = F_44 ( V_3 -> V_87 , V_3 -> V_88 != V_84 ) ;
if ( F_18 ( V_86 ) )
return F_45 ( V_86 ) ;
F_46 ( & V_3 -> V_18 ) ;
F_47 (req, tmp, &nbd->queue_head, queuelist) {
if ( V_12 != V_84 )
continue;
F_48 ( & V_12 -> V_89 ) ;
F_49 ( & V_3 -> V_18 ) ;
return V_12 ;
}
F_49 ( & V_3 -> V_18 ) ;
return F_45 ( - V_90 ) ;
}
static inline int F_50 ( struct V_2 * V_3 , struct V_68 * V_69 )
{
int V_35 ;
void * V_70 = F_33 ( V_69 -> V_71 ) ;
V_35 = F_17 ( V_3 , 0 , V_70 + V_69 -> V_72 , V_69 -> V_73 ,
V_91 ) ;
F_34 ( V_69 -> V_71 ) ;
return V_35 ;
}
static struct V_11 * F_51 ( struct V_2 * V_3 )
{
int V_35 ;
struct V_92 V_93 ;
struct V_11 * V_12 ;
V_93 . V_75 = 0 ;
V_35 = F_17 ( V_3 , 0 , & V_93 , sizeof( V_93 ) , V_91 ) ;
if ( V_35 <= 0 ) {
F_19 ( F_2 ( V_3 -> V_4 ) ,
L_20 , V_35 ) ;
goto V_94;
}
if ( F_52 ( V_93 . V_75 ) != V_95 ) {
F_19 ( F_2 ( V_3 -> V_4 ) , L_21 ,
( unsigned long ) F_52 ( V_93 . V_75 ) ) ;
V_35 = - V_96 ;
goto V_94;
}
V_12 = F_43 ( V_3 , * (struct V_11 * * ) V_93 . V_80 ) ;
if ( F_53 ( V_12 ) ) {
V_35 = F_54 ( V_12 ) ;
if ( V_35 != - V_90 )
goto V_94;
F_19 ( F_2 ( V_3 -> V_4 ) , L_22 ,
V_93 . V_80 ) ;
V_35 = - V_97 ;
goto V_94;
}
if ( F_52 ( V_93 . error ) ) {
F_19 ( F_2 ( V_3 -> V_4 ) , L_23 ,
F_52 ( V_93 . error ) ) ;
V_12 -> V_13 ++ ;
return V_12 ;
}
F_5 ( F_1 ( V_3 ) , L_24 , V_12 ) ;
if ( F_38 ( V_12 ) == V_6 ) {
struct V_82 V_83 ;
struct V_68 V_69 ;
F_41 (bvec, req, iter) {
V_35 = F_50 ( V_3 , & V_69 ) ;
if ( V_35 <= 0 ) {
F_19 ( F_2 ( V_3 -> V_4 ) , L_25 ,
V_35 ) ;
V_12 -> V_13 ++ ;
return V_12 ;
}
F_5 ( F_1 ( V_3 ) , L_26 ,
V_12 , V_69 . V_73 ) ;
}
}
return V_12 ;
V_94:
V_3 -> V_94 = V_35 ;
return NULL ;
}
static T_3 F_55 ( struct V_1 * V_98 ,
struct V_99 * V_100 , char * V_31 )
{
struct V_101 * V_4 = F_56 ( V_98 ) ;
return sprintf ( V_31 , L_27 ,
( long ) ( (struct V_2 * ) V_4 -> V_102 ) -> V_28 ) ;
}
static int F_57 ( struct V_2 * V_3 )
{
struct V_11 * V_12 ;
int V_103 ;
F_58 ( V_3 -> V_75 != V_104 ) ;
F_59 ( V_3 -> V_21 -> V_47 ) ;
V_3 -> V_28 = F_29 ( V_43 ) ;
V_103 = F_60 ( F_2 ( V_3 -> V_4 ) , & V_105 ) ;
if ( V_103 ) {
F_19 ( F_2 ( V_3 -> V_4 ) , L_28 ) ;
V_3 -> V_28 = 0 ;
return V_103 ;
}
while ( ( V_12 = F_51 ( V_3 ) ) != NULL )
F_4 ( V_3 , V_12 ) ;
F_61 ( F_2 ( V_3 -> V_4 ) , & V_105 ) ;
V_3 -> V_28 = 0 ;
return 0 ;
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_11 * V_12 ;
F_58 ( V_3 -> V_75 != V_104 ) ;
F_58 ( V_3 -> V_21 ) ;
F_58 ( V_3 -> V_88 ) ;
while ( ! F_63 ( & V_3 -> V_106 ) ) {
V_12 = F_64 ( V_3 -> V_106 . V_107 , struct V_11 ,
V_89 ) ;
F_48 ( & V_12 -> V_89 ) ;
V_12 -> V_13 ++ ;
F_4 ( V_3 , V_12 ) ;
}
while ( ! F_63 ( & V_3 -> V_108 ) ) {
V_12 = F_64 ( V_3 -> V_108 . V_107 , struct V_11 ,
V_89 ) ;
F_48 ( & V_12 -> V_89 ) ;
V_12 -> V_13 ++ ;
F_4 ( V_3 , V_12 ) ;
}
}
static void F_65 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
if ( V_12 -> V_109 != V_110 )
goto V_111;
F_38 ( V_12 ) = V_6 ;
if ( F_66 ( V_12 ) == V_112 ) {
if ( ( V_12 -> V_113 & V_114 ) ) {
F_67 ( ! ( V_3 -> V_17 & V_115 ) ) ;
F_38 ( V_12 ) = V_10 ;
} else
F_38 ( V_12 ) = V_7 ;
if ( V_3 -> V_17 & V_116 ) {
F_19 ( F_2 ( V_3 -> V_4 ) ,
L_29 ) ;
goto V_111;
}
}
if ( V_12 -> V_113 & V_117 ) {
F_58 ( F_18 ( F_68 ( V_12 ) ) ) ;
F_38 ( V_12 ) = V_9 ;
}
V_12 -> V_13 = 0 ;
F_10 ( & V_3 -> V_20 ) ;
if ( F_18 ( ! V_3 -> V_21 ) ) {
F_13 ( & V_3 -> V_20 ) ;
F_19 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
goto V_111;
}
V_3 -> V_88 = V_12 ;
if ( F_35 ( V_3 , V_12 ) != 0 ) {
F_19 ( F_2 ( V_3 -> V_4 ) , L_31 ) ;
V_12 -> V_13 ++ ;
F_4 ( V_3 , V_12 ) ;
} else {
F_46 ( & V_3 -> V_18 ) ;
F_69 ( & V_12 -> V_89 , & V_3 -> V_106 ) ;
F_49 ( & V_3 -> V_18 ) ;
}
V_3 -> V_88 = NULL ;
F_13 ( & V_3 -> V_20 ) ;
F_70 ( & V_3 -> V_87 ) ;
return;
V_111:
V_12 -> V_13 ++ ;
F_4 ( V_3 , V_12 ) ;
}
static int F_71 ( void * V_62 )
{
struct V_2 * V_3 = V_62 ;
struct V_11 * V_12 ;
F_72 ( V_43 , V_118 ) ;
while ( ! F_73 () || ! F_63 ( & V_3 -> V_108 ) ) {
F_44 ( V_3 -> V_119 ,
F_73 () ||
! F_63 ( & V_3 -> V_108 ) ) ;
if ( F_63 ( & V_3 -> V_108 ) )
continue;
F_74 ( & V_3 -> V_18 ) ;
V_12 = F_64 ( V_3 -> V_108 . V_107 , struct V_11 ,
V_89 ) ;
F_48 ( & V_12 -> V_89 ) ;
F_75 ( & V_3 -> V_18 ) ;
F_65 ( V_3 , V_12 ) ;
}
return 0 ;
}
static void F_76 ( struct V_15 * V_16 )
__releases( V_16 -> V_18 ) __acquires( V_16 -> V_18 )
{
struct V_11 * V_12 ;
while ( ( V_12 = F_77 ( V_16 ) ) != NULL ) {
struct V_2 * V_3 ;
F_75 ( V_16 -> V_18 ) ;
V_3 = V_12 -> V_120 -> V_102 ;
F_58 ( V_3 -> V_75 != V_104 ) ;
F_5 ( F_1 ( V_3 ) , L_32 ,
V_12 , V_12 -> V_109 ) ;
if ( F_18 ( ! V_3 -> V_21 ) ) {
F_19 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
V_12 -> V_13 ++ ;
F_4 ( V_3 , V_12 ) ;
F_74 ( V_16 -> V_18 ) ;
continue;
}
F_74 ( & V_3 -> V_18 ) ;
F_69 ( & V_12 -> V_89 , & V_3 -> V_108 ) ;
F_75 ( & V_3 -> V_18 ) ;
F_78 ( & V_3 -> V_119 ) ;
F_74 ( V_16 -> V_18 ) ;
}
}
static int F_79 ( struct V_121 * V_122 , struct V_2 * V_3 ,
unsigned int V_5 , unsigned long V_23 )
{
switch ( V_5 ) {
case V_123 : {
struct V_11 V_124 ;
F_80 ( F_2 ( V_3 -> V_4 ) , L_33 ) ;
if ( ! V_3 -> V_21 )
return - V_44 ;
F_13 ( & V_3 -> V_20 ) ;
F_81 ( V_122 ) ;
F_10 ( & V_3 -> V_20 ) ;
F_82 ( NULL , & V_124 ) ;
V_124 . V_109 = V_125 ;
F_38 ( & V_124 ) = V_8 ;
if ( ! V_3 -> V_21 )
return - V_44 ;
V_3 -> V_126 = 1 ;
F_35 ( V_3 , & V_124 ) ;
return 0 ;
}
case V_127 : {
struct V_34 * V_21 = V_3 -> V_21 ;
V_3 -> V_21 = NULL ;
F_62 ( V_3 ) ;
F_58 ( ! F_63 ( & V_3 -> V_106 ) ) ;
F_58 ( ! F_63 ( & V_3 -> V_108 ) ) ;
F_83 ( V_122 ) ;
if ( V_21 )
F_84 ( V_21 ) ;
return 0 ;
}
case V_128 : {
struct V_34 * V_21 ;
int V_86 ;
if ( V_3 -> V_21 )
return - V_129 ;
V_21 = F_85 ( V_23 , & V_86 ) ;
if ( V_21 ) {
V_3 -> V_21 = V_21 ;
if ( V_130 > 0 )
V_122 -> V_131 = 1 ;
V_3 -> V_126 = 0 ;
return 0 ;
}
return - V_44 ;
}
case V_132 :
V_3 -> V_133 = V_23 ;
V_3 -> V_134 &= ~ ( V_3 -> V_133 - 1 ) ;
V_122 -> V_135 -> V_136 = V_3 -> V_134 ;
F_86 ( V_122 , V_3 -> V_133 ) ;
F_87 ( V_3 -> V_4 , V_3 -> V_134 >> 9 ) ;
return 0 ;
case V_137 :
V_3 -> V_134 = V_23 & ~ ( V_3 -> V_133 - 1 ) ;
V_122 -> V_135 -> V_136 = V_3 -> V_134 ;
F_86 ( V_122 , V_3 -> V_133 ) ;
F_87 ( V_3 -> V_4 , V_3 -> V_134 >> 9 ) ;
return 0 ;
case V_138 :
V_3 -> V_60 = V_23 * V_139 ;
return 0 ;
case V_140 :
V_3 -> V_17 = V_23 ;
return 0 ;
case V_141 :
V_3 -> V_134 = ( ( V_78 ) V_23 ) * V_3 -> V_133 ;
V_122 -> V_135 -> V_136 = V_3 -> V_134 ;
F_86 ( V_122 , V_3 -> V_133 ) ;
F_87 ( V_3 -> V_4 , V_3 -> V_134 >> 9 ) ;
return 0 ;
case V_142 : {
struct V_24 * V_143 ;
struct V_34 * V_21 ;
int error ;
if ( V_3 -> V_28 )
return - V_129 ;
if ( ! V_3 -> V_21 )
return - V_44 ;
F_13 ( & V_3 -> V_20 ) ;
if ( V_3 -> V_17 & V_116 )
F_88 ( V_122 , true ) ;
if ( V_3 -> V_17 & V_115 )
F_89 ( V_144 ,
V_3 -> V_4 -> V_145 ) ;
if ( V_3 -> V_17 & V_146 )
F_90 ( V_3 -> V_4 -> V_145 , V_117 ) ;
else
F_90 ( V_3 -> V_4 -> V_145 , 0 ) ;
V_143 = F_91 ( F_71 , V_3 , L_34 ,
V_3 -> V_4 -> V_147 ) ;
if ( F_53 ( V_143 ) ) {
F_10 ( & V_3 -> V_20 ) ;
return F_54 ( V_143 ) ;
}
error = F_57 ( V_3 ) ;
F_92 ( V_143 ) ;
F_10 ( & V_3 -> V_20 ) ;
if ( error )
return error ;
F_9 ( V_3 , 0 ) ;
V_21 = V_3 -> V_21 ;
V_3 -> V_21 = NULL ;
F_62 ( V_3 ) ;
F_11 ( F_2 ( V_3 -> V_4 ) , L_35 ) ;
F_83 ( V_122 ) ;
F_93 ( V_144 , V_3 -> V_4 -> V_145 ) ;
F_88 ( V_122 , false ) ;
if ( V_21 )
F_84 ( V_21 ) ;
V_3 -> V_17 = 0 ;
V_3 -> V_134 = 0 ;
V_122 -> V_135 -> V_136 = 0 ;
F_87 ( V_3 -> V_4 , 0 ) ;
if ( V_130 > 0 )
F_94 ( V_122 , V_148 , 0 ) ;
if ( V_3 -> V_126 )
return 0 ;
return V_3 -> V_94 ;
}
case V_149 :
return 0 ;
case V_150 :
F_80 ( F_2 ( V_3 -> V_4 ) ,
L_36 ,
V_3 -> V_106 . V_107 , V_3 -> V_106 . V_151 ,
& V_3 -> V_106 ) ;
return 0 ;
}
return - V_152 ;
}
static int F_95 ( struct V_121 * V_122 , T_4 V_153 ,
unsigned int V_5 , unsigned long V_23 )
{
struct V_2 * V_3 = V_122 -> V_154 -> V_102 ;
int error ;
if ( ! F_96 ( V_155 ) )
return - V_156 ;
F_58 ( V_3 -> V_75 != V_104 ) ;
F_10 ( & V_3 -> V_20 ) ;
error = F_79 ( V_122 , V_3 , V_5 , V_23 ) ;
F_13 ( & V_3 -> V_20 ) ;
return error ;
}
static int T_5 F_97 ( void )
{
int V_86 = - V_157 ;
int V_158 ;
int V_159 ;
F_98 ( sizeof( struct V_74 ) != 28 ) ;
if ( V_130 < 0 ) {
F_15 ( V_160 L_37 ) ;
return - V_44 ;
}
V_159 = 0 ;
if ( V_130 > 0 ) {
V_159 = F_99 ( V_130 ) ;
V_130 = ( 1UL << V_159 ) - 1 ;
}
if ( ( 1UL << V_159 ) > V_161 )
return - V_44 ;
if ( V_162 > 1UL << ( V_163 - V_159 ) )
return - V_44 ;
V_164 = F_100 ( V_162 , sizeof( * V_164 ) , V_165 ) ;
if ( ! V_164 )
return - V_157 ;
for ( V_158 = 0 ; V_158 < V_162 ; V_158 ++ ) {
struct V_101 * V_4 = F_101 ( 1 << V_159 ) ;
if ( ! V_4 )
goto V_166;
V_164 [ V_158 ] . V_4 = V_4 ;
V_4 -> V_145 = F_102 ( F_76 , & V_167 ) ;
if ( ! V_4 -> V_145 ) {
F_103 ( V_4 ) ;
goto V_166;
}
F_89 ( V_168 , V_4 -> V_145 ) ;
F_93 ( V_169 , V_4 -> V_145 ) ;
V_4 -> V_145 -> V_170 . V_171 = 512 ;
V_4 -> V_145 -> V_170 . V_172 = V_173 ;
V_4 -> V_145 -> V_170 . V_174 = 0 ;
F_104 ( V_4 -> V_145 , 65536 ) ;
V_4 -> V_145 -> V_170 . V_175 = 256 ;
}
if ( F_105 ( V_176 , L_38 ) ) {
V_86 = - V_14 ;
goto V_166;
}
F_15 ( V_177 L_39 , V_176 ) ;
for ( V_158 = 0 ; V_158 < V_162 ; V_158 ++ ) {
struct V_101 * V_4 = V_164 [ V_158 ] . V_4 ;
V_164 [ V_158 ] . V_75 = V_104 ;
F_106 ( & V_164 [ V_158 ] . V_108 ) ;
F_107 ( & V_164 [ V_158 ] . V_18 ) ;
F_106 ( & V_164 [ V_158 ] . V_106 ) ;
F_108 ( & V_164 [ V_158 ] . V_20 ) ;
F_109 ( & V_164 [ V_158 ] . V_87 ) ;
F_109 ( & V_164 [ V_158 ] . V_119 ) ;
V_164 [ V_158 ] . V_133 = 1024 ;
V_164 [ V_158 ] . V_134 = 0 ;
V_4 -> V_178 = V_176 ;
V_4 -> V_179 = V_158 << V_159 ;
V_4 -> V_180 = & V_181 ;
V_4 -> V_102 = & V_164 [ V_158 ] ;
sprintf ( V_4 -> V_147 , L_40 , V_158 ) ;
F_87 ( V_4 , 0 ) ;
F_110 ( V_4 ) ;
}
return 0 ;
V_166:
while ( V_158 -- ) {
F_111 ( V_164 [ V_158 ] . V_4 -> V_145 ) ;
F_103 ( V_164 [ V_158 ] . V_4 ) ;
}
F_112 ( V_164 ) ;
return V_86 ;
}
static void T_6 F_113 ( void )
{
int V_158 ;
for ( V_158 = 0 ; V_158 < V_162 ; V_158 ++ ) {
struct V_101 * V_4 = V_164 [ V_158 ] . V_4 ;
V_164 [ V_158 ] . V_75 = 0 ;
if ( V_4 ) {
F_114 ( V_4 ) ;
F_111 ( V_4 -> V_145 ) ;
F_103 ( V_4 ) ;
}
}
F_115 ( V_176 , L_38 ) ;
F_112 ( V_164 ) ;
F_15 ( V_177 L_41 , V_176 ) ;
}
