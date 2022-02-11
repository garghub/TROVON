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
}
return L_12 ;
}
static const char * F_2 ( int V_1 )
{
switch ( V_1 ) {
case V_13 : return L_13 ;
case V_14 : return L_14 ;
case V_15 : return L_9 ;
}
return L_15 ;
}
static void F_3 ( struct V_16 * V_17 )
{
int error = V_17 -> V_18 ? - V_19 : 0 ;
struct V_20 * V_21 = V_17 -> V_21 ;
unsigned long V_22 ;
F_4 ( V_23 , L_16 , V_17 -> V_24 -> V_25 ,
V_17 , error ? L_17 : L_18 ) ;
F_5 ( V_21 -> V_26 , V_22 ) ;
F_6 ( V_17 , error ) ;
F_7 ( V_21 -> V_26 , V_22 ) ;
}
static void F_8 ( struct V_27 * V_28 , int V_29 )
{
if ( V_29 )
F_9 ( & V_28 -> V_30 ) ;
if ( V_28 -> V_31 ) {
F_10 ( F_11 ( V_28 -> V_32 ) , L_19 ) ;
F_12 ( V_28 -> V_31 , V_33 ) ;
V_28 -> V_31 = NULL ;
}
if ( V_29 )
F_13 ( & V_28 -> V_30 ) ;
}
static void F_14 ( unsigned long V_34 )
{
struct V_35 * V_36 = (struct V_35 * ) V_34 ;
F_15 ( V_37 L_20 ,
V_36 -> V_38 , V_36 -> V_39 ) ;
F_16 ( V_40 , V_36 ) ;
}
static int F_17 ( struct V_27 * V_28 , int V_41 , void * V_42 , int V_43 ,
int V_44 )
{
struct V_45 * V_31 = V_28 -> V_31 ;
int V_46 ;
struct V_47 V_48 ;
struct V_49 V_50 ;
T_1 V_51 , V_52 ;
unsigned long V_53 = V_54 -> V_22 ;
if ( F_18 ( ! V_31 ) ) {
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_21 ,
( V_41 ? L_22 : L_23 ) ) ;
return - V_55 ;
}
F_20 ( & V_51 , F_21 ( V_40 ) ) ;
F_22 ( V_56 , & V_51 , & V_52 ) ;
V_54 -> V_22 |= V_57 ;
do {
V_31 -> V_58 -> V_59 = V_60 | V_61 ;
V_50 . V_62 = V_42 ;
V_50 . V_63 = V_43 ;
V_48 . V_64 = NULL ;
V_48 . V_65 = 0 ;
V_48 . V_66 = NULL ;
V_48 . V_67 = 0 ;
V_48 . V_44 = V_44 | V_68 ;
if ( V_41 ) {
struct V_69 V_70 ;
if ( V_28 -> V_71 ) {
F_23 ( & V_70 ) ;
V_70 . V_72 = F_14 ;
V_70 . V_73 = ( unsigned long ) V_54 ;
V_70 . V_74 = V_75 + V_28 -> V_71 ;
F_24 ( & V_70 ) ;
}
V_46 = F_25 ( V_31 , & V_48 , & V_50 , 1 , V_43 ) ;
if ( V_28 -> V_71 )
F_26 ( & V_70 ) ;
} else
V_46 = F_27 ( V_31 , & V_48 , & V_50 , 1 , V_43 ,
V_48 . V_44 ) ;
if ( F_28 ( V_54 ) ) {
T_2 V_76 ;
F_15 ( V_37 L_24 ,
F_29 ( V_54 ) , V_54 -> V_38 ,
F_30 ( V_54 , & V_54 -> V_51 , & V_76 ) ) ;
V_46 = - V_77 ;
F_8 ( V_28 , ! V_41 ) ;
break;
}
if ( V_46 <= 0 ) {
if ( V_46 == 0 )
V_46 = - V_78 ;
break;
}
V_43 -= V_46 ;
V_42 += V_46 ;
} while ( V_43 > 0 );
F_22 ( V_56 , & V_52 , NULL ) ;
F_31 ( V_54 , V_53 , V_57 ) ;
return V_46 ;
}
static inline int F_32 ( struct V_27 * V_28 , struct V_79 * V_80 ,
int V_22 )
{
int V_46 ;
void * V_81 = F_33 ( V_80 -> V_82 ) ;
V_46 = F_17 ( V_28 , 1 , V_81 + V_80 -> V_83 ,
V_80 -> V_84 , V_22 ) ;
F_34 ( V_80 -> V_82 ) ;
return V_46 ;
}
static int F_35 ( struct V_27 * V_28 , struct V_16 * V_17 )
{
int V_46 , V_22 ;
struct V_85 V_16 ;
unsigned long V_43 = F_36 ( V_17 ) ;
V_16 . V_86 = F_37 ( V_87 ) ;
V_16 . type = F_37 ( F_38 ( V_17 ) ) ;
V_16 . V_88 = F_39 ( ( V_89 ) F_40 ( V_17 ) << 9 ) ;
V_16 . V_90 = F_37 ( V_43 ) ;
memcpy ( V_16 . V_91 , & V_17 , sizeof( V_17 ) ) ;
F_4 ( V_92 , L_25 ,
V_28 -> V_32 -> V_25 , V_17 ,
F_2 ( F_38 ( V_17 ) ) ,
( unsigned long long ) F_40 ( V_17 ) << 9 ,
F_36 ( V_17 ) ) ;
V_46 = F_17 ( V_28 , 1 , & V_16 , sizeof( V_16 ) ,
( F_38 ( V_17 ) == V_14 ) ? V_93 : 0 ) ;
if ( V_46 <= 0 ) {
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_26 , V_46 ) ;
goto V_94;
}
if ( F_38 ( V_17 ) == V_14 ) {
struct V_95 V_96 ;
struct V_79 * V_80 ;
F_41 (bvec, req, iter) {
V_22 = 0 ;
if ( ! F_42 ( V_17 , V_96 ) )
V_22 = V_93 ;
F_4 ( V_92 , L_27 ,
V_28 -> V_32 -> V_25 , V_17 , V_80 -> V_84 ) ;
V_46 = F_32 ( V_28 , V_80 , V_22 ) ;
if ( V_46 <= 0 ) {
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_28 ,
V_46 ) ;
goto V_94;
}
}
}
return 0 ;
V_94:
return - V_19 ;
}
static struct V_16 * F_43 ( struct V_27 * V_28 ,
struct V_16 * V_97 )
{
struct V_16 * V_17 , * V_98 ;
int V_99 ;
V_99 = F_44 ( V_28 -> V_100 , V_28 -> V_101 != V_97 ) ;
if ( F_18 ( V_99 ) )
goto V_102;
F_45 ( & V_28 -> V_26 ) ;
F_46 (req, tmp, &nbd->queue_head, queuelist) {
if ( V_17 != V_97 )
continue;
F_47 ( & V_17 -> V_103 ) ;
F_48 ( & V_28 -> V_26 ) ;
return V_17 ;
}
F_48 ( & V_28 -> V_26 ) ;
V_99 = - V_104 ;
V_102:
return F_49 ( V_99 ) ;
}
static inline int F_50 ( struct V_27 * V_28 , struct V_79 * V_80 )
{
int V_46 ;
void * V_81 = F_33 ( V_80 -> V_82 ) ;
V_46 = F_17 ( V_28 , 0 , V_81 + V_80 -> V_83 , V_80 -> V_84 ,
V_105 ) ;
F_34 ( V_80 -> V_82 ) ;
return V_46 ;
}
static struct V_16 * F_51 ( struct V_27 * V_28 )
{
int V_46 ;
struct V_106 V_107 ;
struct V_16 * V_17 ;
V_107 . V_86 = 0 ;
V_46 = F_17 ( V_28 , 0 , & V_107 , sizeof( V_107 ) , V_105 ) ;
if ( V_46 <= 0 ) {
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_29 , V_46 ) ;
goto V_108;
}
if ( F_52 ( V_107 . V_86 ) != V_109 ) {
F_19 ( F_11 ( V_28 -> V_32 ) , L_30 ,
( unsigned long ) F_52 ( V_107 . V_86 ) ) ;
V_46 = - V_110 ;
goto V_108;
}
V_17 = F_43 ( V_28 , * (struct V_16 * * ) V_107 . V_91 ) ;
if ( F_53 ( V_17 ) ) {
V_46 = F_54 ( V_17 ) ;
if ( V_46 != - V_104 )
goto V_108;
F_19 ( F_11 ( V_28 -> V_32 ) , L_31 ,
V_107 . V_91 ) ;
V_46 = - V_111 ;
goto V_108;
}
if ( F_52 ( V_107 . error ) ) {
F_19 ( F_11 ( V_28 -> V_32 ) , L_32 ,
F_52 ( V_107 . error ) ) ;
V_17 -> V_18 ++ ;
return V_17 ;
}
F_4 ( V_112 , L_33 ,
V_28 -> V_32 -> V_25 , V_17 ) ;
if ( F_38 ( V_17 ) == V_13 ) {
struct V_95 V_96 ;
struct V_79 * V_80 ;
F_41 (bvec, req, iter) {
V_46 = F_50 ( V_28 , V_80 ) ;
if ( V_46 <= 0 ) {
F_19 ( F_11 ( V_28 -> V_32 ) , L_34 ,
V_46 ) ;
V_17 -> V_18 ++ ;
return V_17 ;
}
F_4 ( V_112 , L_35 ,
V_28 -> V_32 -> V_25 , V_17 , V_80 -> V_84 ) ;
}
}
return V_17 ;
V_108:
V_28 -> V_108 = V_46 ;
return NULL ;
}
static T_3 F_55 ( struct V_113 * V_114 ,
struct V_115 * V_116 , char * V_42 )
{
struct V_117 * V_32 = F_56 ( V_114 ) ;
return sprintf ( V_42 , L_36 ,
( long ) ( (struct V_27 * ) V_32 -> V_118 ) -> V_39 ) ;
}
static int F_57 ( struct V_27 * V_28 )
{
struct V_16 * V_17 ;
int V_119 ;
F_58 ( V_28 -> V_86 != V_120 ) ;
F_59 ( V_28 -> V_31 -> V_58 ) ;
V_28 -> V_39 = F_29 ( V_54 ) ;
V_119 = F_60 ( F_11 ( V_28 -> V_32 ) , & V_121 ) ;
if ( V_119 ) {
F_19 ( F_11 ( V_28 -> V_32 ) , L_37 ) ;
V_28 -> V_39 = 0 ;
return V_119 ;
}
while ( ( V_17 = F_51 ( V_28 ) ) != NULL )
F_3 ( V_17 ) ;
F_61 ( F_11 ( V_28 -> V_32 ) , & V_121 ) ;
V_28 -> V_39 = 0 ;
return 0 ;
}
static void F_62 ( struct V_27 * V_28 )
{
struct V_16 * V_17 ;
F_58 ( V_28 -> V_86 != V_120 ) ;
F_58 ( V_28 -> V_31 ) ;
F_58 ( V_28 -> V_101 ) ;
while ( ! F_63 ( & V_28 -> V_122 ) ) {
V_17 = F_64 ( V_28 -> V_122 . V_123 , struct V_16 ,
V_103 ) ;
F_47 ( & V_17 -> V_103 ) ;
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
}
while ( ! F_63 ( & V_28 -> V_124 ) ) {
V_17 = F_64 ( V_28 -> V_124 . V_123 , struct V_16 ,
V_103 ) ;
F_47 ( & V_17 -> V_103 ) ;
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
}
}
static void F_65 ( struct V_27 * V_28 , struct V_16 * V_17 )
{
if ( V_17 -> V_125 != V_126 )
goto V_94;
F_38 ( V_17 ) = V_13 ;
if ( F_66 ( V_17 ) == V_127 ) {
F_38 ( V_17 ) = V_14 ;
if ( V_28 -> V_22 & V_128 ) {
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_38 ) ;
goto V_94;
}
}
V_17 -> V_18 = 0 ;
F_9 ( & V_28 -> V_30 ) ;
if ( F_18 ( ! V_28 -> V_31 ) ) {
F_13 ( & V_28 -> V_30 ) ;
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_39 ) ;
goto V_94;
}
V_28 -> V_101 = V_17 ;
if ( F_35 ( V_28 , V_17 ) != 0 ) {
F_19 ( F_11 ( V_28 -> V_32 ) , L_40 ) ;
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
} else {
F_45 ( & V_28 -> V_26 ) ;
F_67 ( & V_17 -> V_103 , & V_28 -> V_122 ) ;
F_48 ( & V_28 -> V_26 ) ;
}
V_28 -> V_101 = NULL ;
F_13 ( & V_28 -> V_30 ) ;
F_68 ( & V_28 -> V_100 ) ;
return;
V_94:
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
}
static int F_69 ( void * V_73 )
{
struct V_27 * V_28 = V_73 ;
struct V_16 * V_17 ;
F_70 ( V_54 , - 20 ) ;
while ( ! F_71 () || ! F_63 ( & V_28 -> V_124 ) ) {
F_44 ( V_28 -> V_129 ,
F_71 () ||
! F_63 ( & V_28 -> V_124 ) ) ;
if ( F_63 ( & V_28 -> V_124 ) )
continue;
F_72 ( & V_28 -> V_26 ) ;
V_17 = F_64 ( V_28 -> V_124 . V_123 , struct V_16 ,
V_103 ) ;
F_47 ( & V_17 -> V_103 ) ;
F_73 ( & V_28 -> V_26 ) ;
F_65 ( V_28 , V_17 ) ;
}
return 0 ;
}
static void F_74 ( struct V_20 * V_21 )
{
struct V_16 * V_17 ;
while ( ( V_17 = F_75 ( V_21 ) ) != NULL ) {
struct V_27 * V_28 ;
F_73 ( V_21 -> V_26 ) ;
F_4 ( V_23 , L_41 ,
V_17 -> V_24 -> V_25 , V_17 , V_17 -> V_125 ) ;
V_28 = V_17 -> V_24 -> V_118 ;
F_58 ( V_28 -> V_86 != V_120 ) ;
if ( F_18 ( ! V_28 -> V_31 ) ) {
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_39 ) ;
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
F_72 ( V_21 -> V_26 ) ;
continue;
}
F_72 ( & V_28 -> V_26 ) ;
F_67 ( & V_17 -> V_103 , & V_28 -> V_124 ) ;
F_73 ( & V_28 -> V_26 ) ;
F_76 ( & V_28 -> V_129 ) ;
F_72 ( V_21 -> V_26 ) ;
}
}
static int F_77 ( struct V_130 * V_131 , struct V_27 * V_28 ,
unsigned int V_1 , unsigned long V_34 )
{
switch ( V_1 ) {
case V_10 : {
struct V_16 V_132 ;
F_78 ( F_11 ( V_28 -> V_32 ) , L_42 ) ;
F_79 ( NULL , & V_132 ) ;
V_132 . V_125 = V_133 ;
F_38 ( & V_132 ) = V_15 ;
if ( ! V_28 -> V_31 )
return - V_55 ;
F_35 ( V_28 , & V_132 ) ;
return 0 ;
}
case V_6 : {
struct V_134 * V_134 ;
V_28 -> V_31 = NULL ;
V_134 = V_28 -> V_134 ;
V_28 -> V_134 = NULL ;
F_62 ( V_28 ) ;
F_58 ( ! F_63 ( & V_28 -> V_122 ) ) ;
F_58 ( ! F_63 ( & V_28 -> V_124 ) ) ;
if ( V_134 )
F_80 ( V_134 ) ;
return 0 ;
}
case V_2 : {
struct V_134 * V_134 ;
if ( V_28 -> V_134 )
return - V_135 ;
V_134 = F_81 ( V_34 ) ;
if ( V_134 ) {
struct V_136 * V_136 = V_134 -> V_137 . V_138 -> V_139 ;
if ( F_82 ( V_136 -> V_140 ) ) {
V_28 -> V_134 = V_134 ;
V_28 -> V_31 = F_83 ( V_136 ) ;
if ( V_141 > 0 )
V_131 -> V_142 = 1 ;
return 0 ;
} else {
F_80 ( V_134 ) ;
}
}
return - V_55 ;
}
case V_3 :
V_28 -> V_143 = V_34 ;
V_28 -> V_144 &= ~ ( V_28 -> V_143 - 1 ) ;
V_131 -> V_145 -> V_146 = V_28 -> V_144 ;
F_84 ( V_131 , V_28 -> V_143 ) ;
F_85 ( V_28 -> V_32 , V_28 -> V_144 >> 9 ) ;
return 0 ;
case V_4 :
V_28 -> V_144 = V_34 & ~ ( V_28 -> V_143 - 1 ) ;
V_131 -> V_145 -> V_146 = V_28 -> V_144 ;
F_84 ( V_131 , V_28 -> V_143 ) ;
F_85 ( V_28 -> V_32 , V_28 -> V_144 >> 9 ) ;
return 0 ;
case V_147 :
V_28 -> V_71 = V_34 * V_148 ;
return 0 ;
case V_9 :
V_28 -> V_144 = ( ( V_89 ) V_34 ) * V_28 -> V_143 ;
V_131 -> V_145 -> V_146 = V_28 -> V_144 ;
F_84 ( V_131 , V_28 -> V_143 ) ;
F_85 ( V_28 -> V_32 , V_28 -> V_144 >> 9 ) ;
return 0 ;
case V_5 : {
struct V_35 * V_149 ;
struct V_134 * V_134 ;
int error ;
if ( V_28 -> V_39 )
return - V_135 ;
if ( ! V_28 -> V_134 )
return - V_55 ;
F_13 ( & V_28 -> V_30 ) ;
V_149 = F_86 ( F_69 , V_28 , V_28 -> V_32 -> V_25 ) ;
if ( F_53 ( V_149 ) ) {
F_9 ( & V_28 -> V_30 ) ;
return F_54 ( V_149 ) ;
}
F_87 ( V_149 ) ;
error = F_57 ( V_28 ) ;
F_88 ( V_149 ) ;
F_9 ( & V_28 -> V_30 ) ;
if ( error )
return error ;
F_8 ( V_28 , 0 ) ;
V_134 = V_28 -> V_134 ;
V_28 -> V_134 = NULL ;
F_62 ( V_28 ) ;
F_10 ( F_11 ( V_28 -> V_32 ) , L_43 ) ;
if ( V_134 )
F_80 ( V_134 ) ;
V_28 -> V_144 = 0 ;
V_131 -> V_145 -> V_146 = 0 ;
F_85 ( V_28 -> V_32 , 0 ) ;
if ( V_141 > 0 )
F_89 ( V_131 , V_150 , 0 ) ;
return V_28 -> V_108 ;
}
case V_7 :
F_58 ( ! V_28 -> V_31 && ! F_63 ( & V_28 -> V_122 ) ) ;
return 0 ;
case V_8 :
F_78 ( F_11 ( V_28 -> V_32 ) ,
L_44 ,
V_28 -> V_122 . V_123 , V_28 -> V_122 . V_151 ,
& V_28 -> V_122 ) ;
return 0 ;
}
return - V_152 ;
}
static int F_90 ( struct V_130 * V_131 , T_4 V_153 ,
unsigned int V_1 , unsigned long V_34 )
{
struct V_27 * V_28 = V_131 -> V_154 -> V_118 ;
int error ;
if ( ! F_91 ( V_155 ) )
return - V_156 ;
F_58 ( V_28 -> V_86 != V_120 ) ;
F_4 ( V_157 , L_45 ,
V_28 -> V_32 -> V_25 , F_1 ( V_1 ) , V_1 , V_34 ) ;
F_9 ( & V_28 -> V_30 ) ;
error = F_77 ( V_131 , V_28 , V_1 , V_34 ) ;
F_13 ( & V_28 -> V_30 ) ;
return error ;
}
static int T_5 F_92 ( void )
{
int V_99 = - V_158 ;
int V_159 ;
int V_160 ;
F_93 ( sizeof( struct V_85 ) != 28 ) ;
if ( V_141 < 0 ) {
F_15 ( V_161 L_46 ) ;
return - V_55 ;
}
V_162 = F_94 ( V_163 , sizeof( * V_162 ) , V_164 ) ;
if ( ! V_162 )
return - V_158 ;
V_160 = 0 ;
if ( V_141 > 0 ) {
V_160 = F_95 ( V_141 ) ;
V_141 = ( 1UL << V_160 ) - 1 ;
}
if ( ( 1UL << V_160 ) > V_165 )
return - V_55 ;
if ( V_163 > 1UL << ( V_166 - V_160 ) )
return - V_55 ;
for ( V_159 = 0 ; V_159 < V_163 ; V_159 ++ ) {
struct V_117 * V_32 = F_96 ( 1 << V_160 ) ;
if ( ! V_32 )
goto V_102;
V_162 [ V_159 ] . V_32 = V_32 ;
V_32 -> V_167 = F_97 ( F_74 , & V_168 ) ;
if ( ! V_32 -> V_167 ) {
F_98 ( V_32 ) ;
goto V_102;
}
F_99 ( V_169 , V_32 -> V_167 ) ;
}
if ( F_100 ( V_170 , L_47 ) ) {
V_99 = - V_19 ;
goto V_102;
}
F_15 ( V_171 L_48 , V_170 ) ;
F_4 ( V_172 , L_49 , V_173 ) ;
for ( V_159 = 0 ; V_159 < V_163 ; V_159 ++ ) {
struct V_117 * V_32 = V_162 [ V_159 ] . V_32 ;
V_162 [ V_159 ] . V_134 = NULL ;
V_162 [ V_159 ] . V_86 = V_120 ;
V_162 [ V_159 ] . V_22 = 0 ;
F_101 ( & V_162 [ V_159 ] . V_124 ) ;
F_102 ( & V_162 [ V_159 ] . V_26 ) ;
F_101 ( & V_162 [ V_159 ] . V_122 ) ;
F_103 ( & V_162 [ V_159 ] . V_30 ) ;
F_104 ( & V_162 [ V_159 ] . V_100 ) ;
F_104 ( & V_162 [ V_159 ] . V_129 ) ;
V_162 [ V_159 ] . V_143 = 1024 ;
V_162 [ V_159 ] . V_144 = 0 ;
V_32 -> V_174 = V_170 ;
V_32 -> V_175 = V_159 << V_160 ;
V_32 -> V_176 = & V_177 ;
V_32 -> V_118 = & V_162 [ V_159 ] ;
sprintf ( V_32 -> V_25 , L_50 , V_159 ) ;
F_85 ( V_32 , 0 ) ;
F_105 ( V_32 ) ;
}
return 0 ;
V_102:
while ( V_159 -- ) {
F_106 ( V_162 [ V_159 ] . V_32 -> V_167 ) ;
F_98 ( V_162 [ V_159 ] . V_32 ) ;
}
F_107 ( V_162 ) ;
return V_99 ;
}
static void T_6 F_108 ( void )
{
int V_159 ;
for ( V_159 = 0 ; V_159 < V_163 ; V_159 ++ ) {
struct V_117 * V_32 = V_162 [ V_159 ] . V_32 ;
V_162 [ V_159 ] . V_86 = 0 ;
if ( V_32 ) {
F_109 ( V_32 ) ;
F_106 ( V_32 -> V_167 ) ;
F_98 ( V_32 ) ;
}
}
F_110 ( V_170 , L_47 ) ;
F_107 ( V_162 ) ;
F_15 ( V_171 L_51 , V_170 ) ;
}
