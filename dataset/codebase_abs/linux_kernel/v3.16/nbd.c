static const char * F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 : return L_1 ;
case V_3 : return L_2 ;
case V_4 : return L_3 ;
case V_5 : return L_4 ;
case V_6 : return L_5 ;
case V_7 : return L_6 ;
case V_8 : return L_7 ;
case V_9 : return L_8 ;
case V_10 : return L_9 ;
case V_11 : return L_10 ;
case V_12 : return L_11 ;
case V_13 : return L_12 ;
case V_14 : return L_13 ;
}
return L_14 ;
}
static const char * F_2 ( int V_1 )
{
switch ( V_1 ) {
case V_15 : return L_15 ;
case V_16 : return L_16 ;
case V_17 : return L_11 ;
case V_18 : return L_17 ;
case V_19 : return L_18 ;
}
return L_19 ;
}
static void F_3 ( struct V_20 * V_21 )
{
int error = V_21 -> V_22 ? - V_23 : 0 ;
struct V_24 * V_25 = V_21 -> V_25 ;
unsigned long V_26 ;
F_4 ( V_27 , L_20 , V_21 -> V_28 -> V_29 ,
V_21 , error ? L_21 : L_22 ) ;
F_5 ( V_25 -> V_30 , V_26 ) ;
F_6 ( V_21 , error ) ;
F_7 ( V_25 -> V_30 , V_26 ) ;
}
static void F_8 ( struct V_31 * V_32 , int V_33 )
{
if ( V_33 )
F_9 ( & V_32 -> V_34 ) ;
if ( V_32 -> V_35 ) {
F_10 ( F_11 ( V_32 -> V_36 ) , L_23 ) ;
F_12 ( V_32 -> V_35 , V_37 ) ;
V_32 -> V_35 = NULL ;
}
if ( V_33 )
F_13 ( & V_32 -> V_34 ) ;
}
static void F_14 ( unsigned long V_38 )
{
struct V_39 * V_40 = (struct V_39 * ) V_38 ;
F_15 ( V_41 L_24 ,
V_40 -> V_42 , V_40 -> V_43 ) ;
F_16 ( V_44 , V_40 ) ;
}
static int F_17 ( struct V_31 * V_32 , int V_45 , void * V_46 , int V_47 ,
int V_48 )
{
struct V_49 * V_35 = V_32 -> V_35 ;
int V_50 ;
struct V_51 V_52 ;
struct V_53 V_54 ;
T_1 V_55 , V_56 ;
unsigned long V_57 = V_58 -> V_26 ;
if ( F_18 ( ! V_35 ) ) {
F_19 ( F_11 ( V_32 -> V_36 ) ,
L_25 ,
( V_45 ? L_26 : L_27 ) ) ;
return - V_59 ;
}
F_20 ( & V_55 , F_21 ( V_44 ) ) ;
F_22 ( V_60 , & V_55 , & V_56 ) ;
V_58 -> V_26 |= V_61 ;
do {
V_35 -> V_62 -> V_63 = V_64 | V_65 ;
V_54 . V_66 = V_46 ;
V_54 . V_67 = V_47 ;
V_52 . V_68 = NULL ;
V_52 . V_69 = 0 ;
V_52 . V_70 = NULL ;
V_52 . V_71 = 0 ;
V_52 . V_48 = V_48 | V_72 ;
if ( V_45 ) {
struct V_73 V_74 ;
if ( V_32 -> V_75 ) {
F_23 ( & V_74 ) ;
V_74 . V_76 = F_14 ;
V_74 . V_77 = ( unsigned long ) V_58 ;
V_74 . V_78 = V_79 + V_32 -> V_75 ;
F_24 ( & V_74 ) ;
}
V_50 = F_25 ( V_35 , & V_52 , & V_54 , 1 , V_47 ) ;
if ( V_32 -> V_75 )
F_26 ( & V_74 ) ;
} else
V_50 = F_27 ( V_35 , & V_52 , & V_54 , 1 , V_47 ,
V_52 . V_48 ) ;
if ( F_28 ( V_58 ) ) {
T_2 V_80 ;
F_15 ( V_41 L_28 ,
F_29 ( V_58 ) , V_58 -> V_42 ,
F_30 ( V_58 , & V_58 -> V_55 , & V_80 ) ) ;
V_50 = - V_81 ;
F_8 ( V_32 , ! V_45 ) ;
break;
}
if ( V_50 <= 0 ) {
if ( V_50 == 0 )
V_50 = - V_82 ;
break;
}
V_47 -= V_50 ;
V_46 += V_50 ;
} while ( V_47 > 0 );
F_22 ( V_60 , & V_56 , NULL ) ;
F_31 ( V_58 , V_57 , V_61 ) ;
return V_50 ;
}
static inline int F_32 ( struct V_31 * V_32 , struct V_83 * V_84 ,
int V_26 )
{
int V_50 ;
void * V_85 = F_33 ( V_84 -> V_86 ) ;
V_50 = F_17 ( V_32 , 1 , V_85 + V_84 -> V_87 ,
V_84 -> V_88 , V_26 ) ;
F_34 ( V_84 -> V_86 ) ;
return V_50 ;
}
static int F_35 ( struct V_31 * V_32 , struct V_20 * V_21 )
{
int V_50 , V_26 ;
struct V_89 V_20 ;
unsigned long V_47 = F_36 ( V_21 ) ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_90 = F_37 ( V_91 ) ;
V_20 . type = F_37 ( F_38 ( V_21 ) ) ;
if ( F_38 ( V_21 ) != V_18 && F_38 ( V_21 ) != V_17 ) {
V_20 . V_92 = F_39 ( ( V_93 ) F_40 ( V_21 ) << 9 ) ;
V_20 . V_94 = F_37 ( V_47 ) ;
}
memcpy ( V_20 . V_95 , & V_21 , sizeof( V_21 ) ) ;
F_4 ( V_96 , L_29 ,
V_32 -> V_36 -> V_29 , V_21 ,
F_2 ( F_38 ( V_21 ) ) ,
( unsigned long long ) F_40 ( V_21 ) << 9 ,
F_36 ( V_21 ) ) ;
V_50 = F_17 ( V_32 , 1 , & V_20 , sizeof( V_20 ) ,
( F_38 ( V_21 ) == V_16 ) ? V_97 : 0 ) ;
if ( V_50 <= 0 ) {
F_19 ( F_11 ( V_32 -> V_36 ) ,
L_30 , V_50 ) ;
goto V_98;
}
if ( F_38 ( V_21 ) == V_16 ) {
struct V_99 V_100 ;
struct V_83 V_84 ;
F_41 (bvec, req, iter) {
V_26 = 0 ;
if ( ! F_42 ( V_84 , V_100 ) )
V_26 = V_97 ;
F_4 ( V_96 , L_31 ,
V_32 -> V_36 -> V_29 , V_21 , V_84 . V_88 ) ;
V_50 = F_32 ( V_32 , & V_84 , V_26 ) ;
if ( V_50 <= 0 ) {
F_19 ( F_11 ( V_32 -> V_36 ) ,
L_32 ,
V_50 ) ;
goto V_98;
}
}
}
return 0 ;
V_98:
return - V_23 ;
}
static struct V_20 * F_43 ( struct V_31 * V_32 ,
struct V_20 * V_101 )
{
struct V_20 * V_21 , * V_102 ;
int V_103 ;
V_103 = F_44 ( V_32 -> V_104 , V_32 -> V_105 != V_101 ) ;
if ( F_18 ( V_103 ) )
goto V_106;
F_45 ( & V_32 -> V_30 ) ;
F_46 (req, tmp, &nbd->queue_head, queuelist) {
if ( V_21 != V_101 )
continue;
F_47 ( & V_21 -> V_107 ) ;
F_48 ( & V_32 -> V_30 ) ;
return V_21 ;
}
F_48 ( & V_32 -> V_30 ) ;
V_103 = - V_108 ;
V_106:
return F_49 ( V_103 ) ;
}
static inline int F_50 ( struct V_31 * V_32 , struct V_83 * V_84 )
{
int V_50 ;
void * V_85 = F_33 ( V_84 -> V_86 ) ;
V_50 = F_17 ( V_32 , 0 , V_85 + V_84 -> V_87 , V_84 -> V_88 ,
V_109 ) ;
F_34 ( V_84 -> V_86 ) ;
return V_50 ;
}
static struct V_20 * F_51 ( struct V_31 * V_32 )
{
int V_50 ;
struct V_110 V_111 ;
struct V_20 * V_21 ;
V_111 . V_90 = 0 ;
V_50 = F_17 ( V_32 , 0 , & V_111 , sizeof( V_111 ) , V_109 ) ;
if ( V_50 <= 0 ) {
F_19 ( F_11 ( V_32 -> V_36 ) ,
L_33 , V_50 ) ;
goto V_112;
}
if ( F_52 ( V_111 . V_90 ) != V_113 ) {
F_19 ( F_11 ( V_32 -> V_36 ) , L_34 ,
( unsigned long ) F_52 ( V_111 . V_90 ) ) ;
V_50 = - V_114 ;
goto V_112;
}
V_21 = F_43 ( V_32 , * (struct V_20 * * ) V_111 . V_95 ) ;
if ( F_53 ( V_21 ) ) {
V_50 = F_54 ( V_21 ) ;
if ( V_50 != - V_108 )
goto V_112;
F_19 ( F_11 ( V_32 -> V_36 ) , L_35 ,
V_111 . V_95 ) ;
V_50 = - V_115 ;
goto V_112;
}
if ( F_52 ( V_111 . error ) ) {
F_19 ( F_11 ( V_32 -> V_36 ) , L_36 ,
F_52 ( V_111 . error ) ) ;
V_21 -> V_22 ++ ;
return V_21 ;
}
F_4 ( V_116 , L_37 ,
V_32 -> V_36 -> V_29 , V_21 ) ;
if ( F_38 ( V_21 ) == V_15 ) {
struct V_99 V_100 ;
struct V_83 V_84 ;
F_41 (bvec, req, iter) {
V_50 = F_50 ( V_32 , & V_84 ) ;
if ( V_50 <= 0 ) {
F_19 ( F_11 ( V_32 -> V_36 ) , L_38 ,
V_50 ) ;
V_21 -> V_22 ++ ;
return V_21 ;
}
F_4 ( V_116 , L_39 ,
V_32 -> V_36 -> V_29 , V_21 , V_84 . V_88 ) ;
}
}
return V_21 ;
V_112:
V_32 -> V_112 = V_50 ;
return NULL ;
}
static T_3 F_55 ( struct V_117 * V_118 ,
struct V_119 * V_120 , char * V_46 )
{
struct V_121 * V_36 = F_56 ( V_118 ) ;
return sprintf ( V_46 , L_40 ,
( long ) ( (struct V_31 * ) V_36 -> V_122 ) -> V_43 ) ;
}
static int F_57 ( struct V_31 * V_32 )
{
struct V_20 * V_21 ;
int V_123 ;
F_58 ( V_32 -> V_90 != V_124 ) ;
F_59 ( V_32 -> V_35 -> V_62 ) ;
V_32 -> V_43 = F_29 ( V_58 ) ;
V_123 = F_60 ( F_11 ( V_32 -> V_36 ) , & V_125 ) ;
if ( V_123 ) {
F_19 ( F_11 ( V_32 -> V_36 ) , L_41 ) ;
V_32 -> V_43 = 0 ;
return V_123 ;
}
while ( ( V_21 = F_51 ( V_32 ) ) != NULL )
F_3 ( V_21 ) ;
F_61 ( F_11 ( V_32 -> V_36 ) , & V_125 ) ;
V_32 -> V_43 = 0 ;
return 0 ;
}
static void F_62 ( struct V_31 * V_32 )
{
struct V_20 * V_21 ;
F_58 ( V_32 -> V_90 != V_124 ) ;
F_58 ( V_32 -> V_35 ) ;
F_58 ( V_32 -> V_105 ) ;
while ( ! F_63 ( & V_32 -> V_126 ) ) {
V_21 = F_64 ( V_32 -> V_126 . V_127 , struct V_20 ,
V_107 ) ;
F_47 ( & V_21 -> V_107 ) ;
V_21 -> V_22 ++ ;
F_3 ( V_21 ) ;
}
while ( ! F_63 ( & V_32 -> V_128 ) ) {
V_21 = F_64 ( V_32 -> V_128 . V_127 , struct V_20 ,
V_107 ) ;
F_47 ( & V_21 -> V_107 ) ;
V_21 -> V_22 ++ ;
F_3 ( V_21 ) ;
}
}
static void F_65 ( struct V_31 * V_32 , struct V_20 * V_21 )
{
if ( V_21 -> V_129 != V_130 )
goto V_98;
F_38 ( V_21 ) = V_15 ;
if ( F_66 ( V_21 ) == V_131 ) {
if ( ( V_21 -> V_132 & V_133 ) ) {
F_67 ( ! ( V_32 -> V_26 & V_134 ) ) ;
F_38 ( V_21 ) = V_19 ;
} else
F_38 ( V_21 ) = V_16 ;
if ( V_32 -> V_26 & V_135 ) {
F_19 ( F_11 ( V_32 -> V_36 ) ,
L_42 ) ;
goto V_98;
}
}
if ( V_21 -> V_132 & V_136 ) {
F_58 ( F_18 ( F_68 ( V_21 ) ) ) ;
F_38 ( V_21 ) = V_18 ;
}
V_21 -> V_22 = 0 ;
F_9 ( & V_32 -> V_34 ) ;
if ( F_18 ( ! V_32 -> V_35 ) ) {
F_13 ( & V_32 -> V_34 ) ;
F_19 ( F_11 ( V_32 -> V_36 ) ,
L_43 ) ;
goto V_98;
}
V_32 -> V_105 = V_21 ;
if ( F_35 ( V_32 , V_21 ) != 0 ) {
F_19 ( F_11 ( V_32 -> V_36 ) , L_44 ) ;
V_21 -> V_22 ++ ;
F_3 ( V_21 ) ;
} else {
F_45 ( & V_32 -> V_30 ) ;
F_69 ( & V_21 -> V_107 , & V_32 -> V_126 ) ;
F_48 ( & V_32 -> V_30 ) ;
}
V_32 -> V_105 = NULL ;
F_13 ( & V_32 -> V_34 ) ;
F_70 ( & V_32 -> V_104 ) ;
return;
V_98:
V_21 -> V_22 ++ ;
F_3 ( V_21 ) ;
}
static int F_71 ( void * V_77 )
{
struct V_31 * V_32 = V_77 ;
struct V_20 * V_21 ;
F_72 ( V_58 , V_137 ) ;
while ( ! F_73 () || ! F_63 ( & V_32 -> V_128 ) ) {
F_44 ( V_32 -> V_138 ,
F_73 () ||
! F_63 ( & V_32 -> V_128 ) ) ;
if ( F_63 ( & V_32 -> V_128 ) )
continue;
F_74 ( & V_32 -> V_30 ) ;
V_21 = F_64 ( V_32 -> V_128 . V_127 , struct V_20 ,
V_107 ) ;
F_47 ( & V_21 -> V_107 ) ;
F_75 ( & V_32 -> V_30 ) ;
F_65 ( V_32 , V_21 ) ;
}
return 0 ;
}
static void F_76 ( struct V_24 * V_25 )
__releases( V_25 -> V_30 ) __acquires( V_25 -> V_30 )
{
struct V_20 * V_21 ;
while ( ( V_21 = F_77 ( V_25 ) ) != NULL ) {
struct V_31 * V_32 ;
F_75 ( V_25 -> V_30 ) ;
F_4 ( V_27 , L_45 ,
V_21 -> V_28 -> V_29 , V_21 , V_21 -> V_129 ) ;
V_32 = V_21 -> V_28 -> V_122 ;
F_58 ( V_32 -> V_90 != V_124 ) ;
if ( F_18 ( ! V_32 -> V_35 ) ) {
F_19 ( F_11 ( V_32 -> V_36 ) ,
L_43 ) ;
V_21 -> V_22 ++ ;
F_3 ( V_21 ) ;
F_74 ( V_25 -> V_30 ) ;
continue;
}
F_74 ( & V_32 -> V_30 ) ;
F_69 ( & V_21 -> V_107 , & V_32 -> V_128 ) ;
F_75 ( & V_32 -> V_30 ) ;
F_78 ( & V_32 -> V_138 ) ;
F_74 ( V_25 -> V_30 ) ;
}
}
static int F_79 ( struct V_139 * V_140 , struct V_31 * V_32 ,
unsigned int V_1 , unsigned long V_38 )
{
switch ( V_1 ) {
case V_12 : {
struct V_20 V_141 ;
F_80 ( F_11 ( V_32 -> V_36 ) , L_46 ) ;
if ( ! V_32 -> V_35 )
return - V_59 ;
F_13 ( & V_32 -> V_34 ) ;
F_81 ( V_140 ) ;
F_9 ( & V_32 -> V_34 ) ;
F_82 ( NULL , & V_141 ) ;
V_141 . V_129 = V_142 ;
F_38 ( & V_141 ) = V_17 ;
if ( ! V_32 -> V_35 )
return - V_59 ;
V_32 -> V_143 = 1 ;
F_35 ( V_32 , & V_141 ) ;
return 0 ;
}
case V_8 : {
struct V_49 * V_35 = V_32 -> V_35 ;
V_32 -> V_35 = NULL ;
F_62 ( V_32 ) ;
F_58 ( ! F_63 ( & V_32 -> V_126 ) ) ;
F_58 ( ! F_63 ( & V_32 -> V_128 ) ) ;
F_83 ( V_140 ) ;
if ( V_35 )
F_84 ( V_35 ) ;
return 0 ;
}
case V_2 : {
struct V_49 * V_35 ;
int V_103 ;
if ( V_32 -> V_35 )
return - V_144 ;
V_35 = F_85 ( V_38 , & V_103 ) ;
if ( V_35 ) {
V_32 -> V_35 = V_35 ;
if ( V_145 > 0 )
V_140 -> V_146 = 1 ;
V_32 -> V_143 = 0 ;
return 0 ;
}
return - V_59 ;
}
case V_3 :
V_32 -> V_147 = V_38 ;
V_32 -> V_148 &= ~ ( V_32 -> V_147 - 1 ) ;
V_140 -> V_149 -> V_150 = V_32 -> V_148 ;
F_86 ( V_140 , V_32 -> V_147 ) ;
F_87 ( V_32 -> V_36 , V_32 -> V_148 >> 9 ) ;
return 0 ;
case V_4 :
V_32 -> V_148 = V_38 & ~ ( V_32 -> V_147 - 1 ) ;
V_140 -> V_149 -> V_150 = V_32 -> V_148 ;
F_86 ( V_140 , V_32 -> V_147 ) ;
F_87 ( V_32 -> V_36 , V_32 -> V_148 >> 9 ) ;
return 0 ;
case V_5 :
V_32 -> V_75 = V_38 * V_151 ;
return 0 ;
case V_6 :
V_32 -> V_26 = V_38 ;
return 0 ;
case V_11 :
V_32 -> V_148 = ( ( V_93 ) V_38 ) * V_32 -> V_147 ;
V_140 -> V_149 -> V_150 = V_32 -> V_148 ;
F_86 ( V_140 , V_32 -> V_147 ) ;
F_87 ( V_32 -> V_36 , V_32 -> V_148 >> 9 ) ;
return 0 ;
case V_7 : {
struct V_39 * V_152 ;
struct V_49 * V_35 ;
int error ;
if ( V_32 -> V_43 )
return - V_144 ;
if ( ! V_32 -> V_35 )
return - V_59 ;
F_13 ( & V_32 -> V_34 ) ;
if ( V_32 -> V_26 & V_135 )
F_88 ( V_140 , true ) ;
if ( V_32 -> V_26 & V_134 )
F_89 ( V_153 ,
V_32 -> V_36 -> V_154 ) ;
if ( V_32 -> V_26 & V_155 )
F_90 ( V_32 -> V_36 -> V_154 , V_136 ) ;
else
F_90 ( V_32 -> V_36 -> V_154 , 0 ) ;
V_152 = F_91 ( F_71 , V_32 , L_47 ,
V_32 -> V_36 -> V_29 ) ;
if ( F_53 ( V_152 ) ) {
F_9 ( & V_32 -> V_34 ) ;
return F_54 ( V_152 ) ;
}
F_92 ( V_152 ) ;
error = F_57 ( V_32 ) ;
F_93 ( V_152 ) ;
F_9 ( & V_32 -> V_34 ) ;
if ( error )
return error ;
F_8 ( V_32 , 0 ) ;
V_35 = V_32 -> V_35 ;
V_32 -> V_35 = NULL ;
F_62 ( V_32 ) ;
F_10 ( F_11 ( V_32 -> V_36 ) , L_48 ) ;
F_83 ( V_140 ) ;
F_94 ( V_153 , V_32 -> V_36 -> V_154 ) ;
F_88 ( V_140 , false ) ;
if ( V_35 )
F_84 ( V_35 ) ;
V_32 -> V_26 = 0 ;
V_32 -> V_148 = 0 ;
V_140 -> V_149 -> V_150 = 0 ;
F_87 ( V_32 -> V_36 , 0 ) ;
if ( V_145 > 0 )
F_95 ( V_140 , V_156 , 0 ) ;
if ( V_32 -> V_143 )
return 0 ;
return V_32 -> V_112 ;
}
case V_9 :
return 0 ;
case V_10 :
F_80 ( F_11 ( V_32 -> V_36 ) ,
L_49 ,
V_32 -> V_126 . V_127 , V_32 -> V_126 . V_157 ,
& V_32 -> V_126 ) ;
return 0 ;
}
return - V_158 ;
}
static int F_96 ( struct V_139 * V_140 , T_4 V_159 ,
unsigned int V_1 , unsigned long V_38 )
{
struct V_31 * V_32 = V_140 -> V_160 -> V_122 ;
int error ;
if ( ! F_97 ( V_161 ) )
return - V_162 ;
F_58 ( V_32 -> V_90 != V_124 ) ;
F_4 ( V_163 , L_50 ,
V_32 -> V_36 -> V_29 , F_1 ( V_1 ) , V_1 , V_38 ) ;
F_9 ( & V_32 -> V_34 ) ;
error = F_79 ( V_140 , V_32 , V_1 , V_38 ) ;
F_13 ( & V_32 -> V_34 ) ;
return error ;
}
static int T_5 F_98 ( void )
{
int V_103 = - V_164 ;
int V_165 ;
int V_166 ;
F_99 ( sizeof( struct V_89 ) != 28 ) ;
if ( V_145 < 0 ) {
F_15 ( V_167 L_51 ) ;
return - V_59 ;
}
V_168 = F_100 ( V_169 , sizeof( * V_168 ) , V_170 ) ;
if ( ! V_168 )
return - V_164 ;
V_166 = 0 ;
if ( V_145 > 0 ) {
V_166 = F_101 ( V_145 ) ;
V_145 = ( 1UL << V_166 ) - 1 ;
}
if ( ( 1UL << V_166 ) > V_171 )
return - V_59 ;
if ( V_169 > 1UL << ( V_172 - V_166 ) )
return - V_59 ;
for ( V_165 = 0 ; V_165 < V_169 ; V_165 ++ ) {
struct V_121 * V_36 = F_102 ( 1 << V_166 ) ;
if ( ! V_36 )
goto V_106;
V_168 [ V_165 ] . V_36 = V_36 ;
V_36 -> V_154 = F_103 ( F_76 , & V_173 ) ;
if ( ! V_36 -> V_154 ) {
F_104 ( V_36 ) ;
goto V_106;
}
F_89 ( V_174 , V_36 -> V_154 ) ;
V_36 -> V_154 -> V_175 . V_176 = 512 ;
V_36 -> V_154 -> V_175 . V_177 = V_178 ;
V_36 -> V_154 -> V_175 . V_179 = 0 ;
F_105 ( V_36 -> V_154 , 65536 ) ;
V_36 -> V_154 -> V_175 . V_180 = 256 ;
}
if ( F_106 ( V_181 , L_52 ) ) {
V_103 = - V_23 ;
goto V_106;
}
F_15 ( V_182 L_53 , V_181 ) ;
F_4 ( V_183 , L_54 , V_184 ) ;
for ( V_165 = 0 ; V_165 < V_169 ; V_165 ++ ) {
struct V_121 * V_36 = V_168 [ V_165 ] . V_36 ;
V_168 [ V_165 ] . V_90 = V_124 ;
F_107 ( & V_168 [ V_165 ] . V_128 ) ;
F_108 ( & V_168 [ V_165 ] . V_30 ) ;
F_107 ( & V_168 [ V_165 ] . V_126 ) ;
F_109 ( & V_168 [ V_165 ] . V_34 ) ;
F_110 ( & V_168 [ V_165 ] . V_104 ) ;
F_110 ( & V_168 [ V_165 ] . V_138 ) ;
V_168 [ V_165 ] . V_147 = 1024 ;
V_168 [ V_165 ] . V_148 = 0 ;
V_36 -> V_185 = V_181 ;
V_36 -> V_186 = V_165 << V_166 ;
V_36 -> V_187 = & V_188 ;
V_36 -> V_122 = & V_168 [ V_165 ] ;
sprintf ( V_36 -> V_29 , L_55 , V_165 ) ;
F_87 ( V_36 , 0 ) ;
F_111 ( V_36 ) ;
}
return 0 ;
V_106:
while ( V_165 -- ) {
F_112 ( V_168 [ V_165 ] . V_36 -> V_154 ) ;
F_104 ( V_168 [ V_165 ] . V_36 ) ;
}
F_113 ( V_168 ) ;
return V_103 ;
}
static void T_6 F_114 ( void )
{
int V_165 ;
for ( V_165 = 0 ; V_165 < V_169 ; V_165 ++ ) {
struct V_121 * V_36 = V_168 [ V_165 ] . V_36 ;
V_168 [ V_165 ] . V_90 = 0 ;
if ( V_36 ) {
F_115 ( V_36 ) ;
F_112 ( V_36 -> V_154 ) ;
F_104 ( V_36 ) ;
}
}
F_116 ( V_181 , L_52 ) ;
F_113 ( V_168 ) ;
F_15 ( V_182 L_56 , V_181 ) ;
}
