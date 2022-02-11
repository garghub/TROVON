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
F_10 ( V_32 L_19 ,
V_28 -> V_33 -> V_25 ) ;
F_11 ( V_28 -> V_31 , V_34 ) ;
V_28 -> V_31 = NULL ;
}
if ( V_29 )
F_12 ( & V_28 -> V_30 ) ;
}
static void F_13 ( unsigned long V_35 )
{
struct V_36 * V_37 = (struct V_36 * ) V_35 ;
F_10 ( V_32 L_20 ,
V_37 -> V_38 , V_37 -> V_39 ) ;
F_14 ( V_40 , V_37 ) ;
}
static int F_15 ( struct V_27 * V_28 , int V_41 , void * V_42 , int V_43 ,
int V_44 )
{
struct V_45 * V_31 = V_28 -> V_31 ;
int V_46 ;
struct V_47 V_48 ;
struct V_49 V_50 ;
T_1 V_51 , V_52 ;
if ( F_16 ( ! V_31 ) ) {
F_10 ( V_53 L_21 ,
V_28 -> V_33 -> V_25 , ( V_41 ? L_22 : L_23 ) ) ;
return - V_54 ;
}
F_17 ( & V_51 , F_18 ( V_40 ) ) ;
F_19 ( V_55 , & V_51 , & V_52 ) ;
do {
V_31 -> V_56 -> V_57 = V_58 ;
V_50 . V_59 = V_42 ;
V_50 . V_60 = V_43 ;
V_48 . V_61 = NULL ;
V_48 . V_62 = 0 ;
V_48 . V_63 = NULL ;
V_48 . V_64 = 0 ;
V_48 . V_44 = V_44 | V_65 ;
if ( V_41 ) {
struct V_66 V_67 ;
if ( V_28 -> V_68 ) {
F_20 ( & V_67 ) ;
V_67 . V_69 = F_13 ;
V_67 . V_70 = ( unsigned long ) V_71 ;
V_67 . V_72 = V_73 + V_28 -> V_68 ;
F_21 ( & V_67 ) ;
}
V_46 = F_22 ( V_31 , & V_48 , & V_50 , 1 , V_43 ) ;
if ( V_28 -> V_68 )
F_23 ( & V_67 ) ;
} else
V_46 = F_24 ( V_31 , & V_48 , & V_50 , 1 , V_43 ,
V_48 . V_44 ) ;
if ( F_25 ( V_71 ) ) {
T_2 V_74 ;
F_10 ( V_32 L_24 ,
F_26 ( V_71 ) , V_71 -> V_38 ,
F_27 ( V_71 , & V_71 -> V_51 , & V_74 ) ) ;
V_46 = - V_75 ;
F_8 ( V_28 , ! V_41 ) ;
break;
}
if ( V_46 <= 0 ) {
if ( V_46 == 0 )
V_46 = - V_76 ;
break;
}
V_43 -= V_46 ;
V_42 += V_46 ;
} while ( V_43 > 0 );
F_19 ( V_55 , & V_52 , NULL ) ;
return V_46 ;
}
static inline int F_28 ( struct V_27 * V_28 , struct V_77 * V_78 ,
int V_22 )
{
int V_46 ;
void * V_79 = F_29 ( V_78 -> V_80 ) ;
V_46 = F_15 ( V_28 , 1 , V_79 + V_78 -> V_81 , V_78 -> V_82 , V_22 ) ;
F_30 ( V_78 -> V_80 ) ;
return V_46 ;
}
static int F_31 ( struct V_27 * V_28 , struct V_16 * V_17 )
{
int V_46 , V_22 ;
struct V_83 V_16 ;
unsigned long V_43 = F_32 ( V_17 ) ;
V_16 . V_84 = F_33 ( V_85 ) ;
V_16 . type = F_33 ( F_34 ( V_17 ) ) ;
V_16 . V_86 = F_35 ( ( V_87 ) F_36 ( V_17 ) << 9 ) ;
V_16 . V_88 = F_33 ( V_43 ) ;
memcpy ( V_16 . V_89 , & V_17 , sizeof( V_17 ) ) ;
F_4 ( V_90 , L_25 ,
V_28 -> V_33 -> V_25 , V_17 ,
F_2 ( F_34 ( V_17 ) ) ,
( unsigned long long ) F_36 ( V_17 ) << 9 ,
F_32 ( V_17 ) ) ;
V_46 = F_15 ( V_28 , 1 , & V_16 , sizeof( V_16 ) ,
( F_34 ( V_17 ) == V_14 ) ? V_91 : 0 ) ;
if ( V_46 <= 0 ) {
F_10 ( V_53 L_26 ,
V_28 -> V_33 -> V_25 , V_46 ) ;
goto V_92;
}
if ( F_34 ( V_17 ) == V_14 ) {
struct V_93 V_94 ;
struct V_77 * V_78 ;
F_37 (bvec, req, iter) {
V_22 = 0 ;
if ( ! F_38 ( V_17 , V_94 ) )
V_22 = V_91 ;
F_4 ( V_90 , L_27 ,
V_28 -> V_33 -> V_25 , V_17 , V_78 -> V_82 ) ;
V_46 = F_28 ( V_28 , V_78 , V_22 ) ;
if ( V_46 <= 0 ) {
F_10 ( V_53 L_28 ,
V_28 -> V_33 -> V_25 , V_46 ) ;
goto V_92;
}
}
}
return 0 ;
V_92:
return - V_19 ;
}
static struct V_16 * F_39 ( struct V_27 * V_28 ,
struct V_16 * V_95 )
{
struct V_16 * V_17 , * V_96 ;
int V_97 ;
V_97 = F_40 ( V_28 -> V_98 , V_28 -> V_99 != V_95 ) ;
if ( F_16 ( V_97 ) )
goto V_100;
F_41 ( & V_28 -> V_26 ) ;
F_42 (req, tmp, &lo->queue_head, queuelist) {
if ( V_17 != V_95 )
continue;
F_43 ( & V_17 -> V_101 ) ;
F_44 ( & V_28 -> V_26 ) ;
return V_17 ;
}
F_44 ( & V_28 -> V_26 ) ;
V_97 = - V_102 ;
V_100:
return F_45 ( V_97 ) ;
}
static inline int F_46 ( struct V_27 * V_28 , struct V_77 * V_78 )
{
int V_46 ;
void * V_79 = F_29 ( V_78 -> V_80 ) ;
V_46 = F_15 ( V_28 , 0 , V_79 + V_78 -> V_81 , V_78 -> V_82 ,
V_103 ) ;
F_30 ( V_78 -> V_80 ) ;
return V_46 ;
}
static struct V_16 * F_47 ( struct V_27 * V_28 )
{
int V_46 ;
struct V_104 V_105 ;
struct V_16 * V_17 ;
V_105 . V_84 = 0 ;
V_46 = F_15 ( V_28 , 0 , & V_105 , sizeof( V_105 ) , V_103 ) ;
if ( V_46 <= 0 ) {
F_10 ( V_53 L_29 ,
V_28 -> V_33 -> V_25 , V_46 ) ;
goto V_106;
}
if ( F_48 ( V_105 . V_84 ) != V_107 ) {
F_10 ( V_53 L_30 ,
V_28 -> V_33 -> V_25 ,
( unsigned long ) F_48 ( V_105 . V_84 ) ) ;
V_46 = - V_108 ;
goto V_106;
}
V_17 = F_39 ( V_28 , * (struct V_16 * * ) V_105 . V_89 ) ;
if ( F_49 ( V_17 ) ) {
V_46 = F_50 ( V_17 ) ;
if ( V_46 != - V_102 )
goto V_106;
F_10 ( V_53 L_31 ,
V_28 -> V_33 -> V_25 , V_105 . V_89 ) ;
V_46 = - V_109 ;
goto V_106;
}
if ( F_48 ( V_105 . error ) ) {
F_10 ( V_53 L_32 ,
V_28 -> V_33 -> V_25 , F_48 ( V_105 . error ) ) ;
V_17 -> V_18 ++ ;
return V_17 ;
}
F_4 ( V_110 , L_33 ,
V_28 -> V_33 -> V_25 , V_17 ) ;
if ( F_34 ( V_17 ) == V_13 ) {
struct V_93 V_94 ;
struct V_77 * V_78 ;
F_37 (bvec, req, iter) {
V_46 = F_46 ( V_28 , V_78 ) ;
if ( V_46 <= 0 ) {
F_10 ( V_53 L_34 ,
V_28 -> V_33 -> V_25 , V_46 ) ;
V_17 -> V_18 ++ ;
return V_17 ;
}
F_4 ( V_110 , L_35 ,
V_28 -> V_33 -> V_25 , V_17 , V_78 -> V_82 ) ;
}
}
return V_17 ;
V_106:
V_28 -> V_106 = V_46 ;
return NULL ;
}
static T_3 F_51 ( struct V_111 * V_112 ,
struct V_113 * V_114 , char * V_42 )
{
struct V_115 * V_33 = F_52 ( V_112 ) ;
return sprintf ( V_42 , L_36 ,
( long ) ( (struct V_27 * ) V_33 -> V_116 ) -> V_39 ) ;
}
static int F_53 ( struct V_27 * V_28 )
{
struct V_16 * V_17 ;
int V_117 ;
F_54 ( V_28 -> V_84 != V_118 ) ;
V_28 -> V_39 = V_71 -> V_39 ;
V_117 = F_55 ( & F_56 ( V_28 -> V_33 ) -> V_119 , & V_120 . V_114 ) ;
if ( V_117 ) {
F_10 ( V_53 L_37 ) ;
V_28 -> V_39 = 0 ;
return V_117 ;
}
while ( ( V_17 = F_47 ( V_28 ) ) != NULL )
F_3 ( V_17 ) ;
F_57 ( & F_56 ( V_28 -> V_33 ) -> V_119 , & V_120 . V_114 ) ;
V_28 -> V_39 = 0 ;
return 0 ;
}
static void F_58 ( struct V_27 * V_28 )
{
struct V_16 * V_17 ;
F_54 ( V_28 -> V_84 != V_118 ) ;
F_54 ( V_28 -> V_31 ) ;
F_54 ( V_28 -> V_99 ) ;
while ( ! F_59 ( & V_28 -> V_121 ) ) {
V_17 = F_60 ( V_28 -> V_121 . V_122 , struct V_16 ,
V_101 ) ;
F_43 ( & V_17 -> V_101 ) ;
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
}
}
static void F_61 ( struct V_27 * V_28 , struct V_16 * V_17 )
{
if ( V_17 -> V_123 != V_124 )
goto V_92;
F_34 ( V_17 ) = V_13 ;
if ( F_62 ( V_17 ) == V_125 ) {
F_34 ( V_17 ) = V_14 ;
if ( V_28 -> V_22 & V_126 ) {
F_10 ( V_53 L_38 ,
V_28 -> V_33 -> V_25 ) ;
goto V_92;
}
}
V_17 -> V_18 = 0 ;
F_9 ( & V_28 -> V_30 ) ;
if ( F_16 ( ! V_28 -> V_31 ) ) {
F_12 ( & V_28 -> V_30 ) ;
F_10 ( V_53 L_39 ,
V_28 -> V_33 -> V_25 ) ;
goto V_92;
}
V_28 -> V_99 = V_17 ;
if ( F_31 ( V_28 , V_17 ) != 0 ) {
F_10 ( V_53 L_40 ,
V_28 -> V_33 -> V_25 ) ;
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
} else {
F_41 ( & V_28 -> V_26 ) ;
F_63 ( & V_17 -> V_101 , & V_28 -> V_121 ) ;
F_44 ( & V_28 -> V_26 ) ;
}
V_28 -> V_99 = NULL ;
F_12 ( & V_28 -> V_30 ) ;
F_64 ( & V_28 -> V_98 ) ;
return;
V_92:
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
}
static int F_65 ( void * V_70 )
{
struct V_27 * V_28 = V_70 ;
struct V_16 * V_17 ;
F_66 ( V_71 , - 20 ) ;
while ( ! F_67 () || ! F_59 ( & V_28 -> V_127 ) ) {
F_40 ( V_28 -> V_128 ,
F_67 () ||
! F_59 ( & V_28 -> V_127 ) ) ;
if ( F_59 ( & V_28 -> V_127 ) )
continue;
F_68 ( & V_28 -> V_26 ) ;
V_17 = F_60 ( V_28 -> V_127 . V_122 , struct V_16 ,
V_101 ) ;
F_43 ( & V_17 -> V_101 ) ;
F_69 ( & V_28 -> V_26 ) ;
F_61 ( V_28 , V_17 ) ;
}
return 0 ;
}
static void F_70 ( struct V_20 * V_21 )
{
struct V_16 * V_17 ;
while ( ( V_17 = F_71 ( V_21 ) ) != NULL ) {
struct V_27 * V_28 ;
F_69 ( V_21 -> V_26 ) ;
F_4 ( V_23 , L_41 ,
V_17 -> V_24 -> V_25 , V_17 , V_17 -> V_123 ) ;
V_28 = V_17 -> V_24 -> V_116 ;
F_54 ( V_28 -> V_84 != V_118 ) ;
if ( F_16 ( ! V_28 -> V_31 ) ) {
F_10 ( V_53 L_39 ,
V_28 -> V_33 -> V_25 ) ;
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
F_68 ( V_21 -> V_26 ) ;
continue;
}
F_68 ( & V_28 -> V_26 ) ;
F_72 ( & V_17 -> V_101 , & V_28 -> V_127 ) ;
F_69 ( & V_28 -> V_26 ) ;
F_73 ( & V_28 -> V_128 ) ;
F_68 ( V_21 -> V_26 ) ;
}
}
static int F_74 ( struct V_129 * V_130 , struct V_27 * V_28 ,
unsigned int V_1 , unsigned long V_35 )
{
switch ( V_1 ) {
case V_10 : {
struct V_16 V_131 ;
F_10 ( V_132 L_42 , V_28 -> V_33 -> V_25 ) ;
F_75 ( NULL , & V_131 ) ;
V_131 . V_123 = V_133 ;
F_34 ( & V_131 ) = V_15 ;
if ( ! V_28 -> V_31 )
return - V_54 ;
F_31 ( V_28 , & V_131 ) ;
return 0 ;
}
case V_6 : {
struct V_134 * V_134 ;
V_28 -> V_31 = NULL ;
V_134 = V_28 -> V_134 ;
V_28 -> V_134 = NULL ;
F_58 ( V_28 ) ;
F_54 ( ! F_59 ( & V_28 -> V_121 ) ) ;
if ( V_134 )
F_76 ( V_134 ) ;
return 0 ;
}
case V_2 : {
struct V_134 * V_134 ;
if ( V_28 -> V_134 )
return - V_135 ;
V_134 = F_77 ( V_35 ) ;
if ( V_134 ) {
struct V_136 * V_136 = V_134 -> V_137 . V_138 -> V_139 ;
if ( F_78 ( V_136 -> V_140 ) ) {
V_28 -> V_134 = V_134 ;
V_28 -> V_31 = F_79 ( V_136 ) ;
if ( V_141 > 0 )
V_130 -> V_142 = 1 ;
return 0 ;
} else {
F_76 ( V_134 ) ;
}
}
return - V_54 ;
}
case V_3 :
V_28 -> V_143 = V_35 ;
V_28 -> V_144 &= ~ ( V_28 -> V_143 - 1 ) ;
V_130 -> V_145 -> V_146 = V_28 -> V_144 ;
F_80 ( V_130 , V_28 -> V_143 ) ;
F_81 ( V_28 -> V_33 , V_28 -> V_144 >> 9 ) ;
return 0 ;
case V_4 :
V_28 -> V_144 = V_35 & ~ ( V_28 -> V_143 - 1 ) ;
V_130 -> V_145 -> V_146 = V_28 -> V_144 ;
F_80 ( V_130 , V_28 -> V_143 ) ;
F_81 ( V_28 -> V_33 , V_28 -> V_144 >> 9 ) ;
return 0 ;
case V_147 :
V_28 -> V_68 = V_35 * V_148 ;
return 0 ;
case V_9 :
V_28 -> V_144 = ( ( V_87 ) V_35 ) * V_28 -> V_143 ;
V_130 -> V_145 -> V_146 = V_28 -> V_144 ;
F_80 ( V_130 , V_28 -> V_143 ) ;
F_81 ( V_28 -> V_33 , V_28 -> V_144 >> 9 ) ;
return 0 ;
case V_5 : {
struct V_36 * V_149 ;
struct V_134 * V_134 ;
int error ;
if ( V_28 -> V_39 )
return - V_135 ;
if ( ! V_28 -> V_134 )
return - V_54 ;
F_12 ( & V_28 -> V_30 ) ;
V_149 = F_82 ( F_65 , V_28 , V_28 -> V_33 -> V_25 ) ;
if ( F_49 ( V_149 ) ) {
F_9 ( & V_28 -> V_30 ) ;
return F_50 ( V_149 ) ;
}
F_83 ( V_149 ) ;
error = F_53 ( V_28 ) ;
F_84 ( V_149 ) ;
F_9 ( & V_28 -> V_30 ) ;
if ( error )
return error ;
F_8 ( V_28 , 0 ) ;
V_134 = V_28 -> V_134 ;
V_28 -> V_134 = NULL ;
F_58 ( V_28 ) ;
F_10 ( V_32 L_43 , V_28 -> V_33 -> V_25 ) ;
if ( V_134 )
F_76 ( V_134 ) ;
V_28 -> V_144 = 0 ;
V_130 -> V_145 -> V_146 = 0 ;
F_81 ( V_28 -> V_33 , 0 ) ;
if ( V_141 > 0 )
F_85 ( V_130 , V_150 , 0 ) ;
return V_28 -> V_106 ;
}
case V_7 :
F_54 ( ! V_28 -> V_31 && ! F_59 ( & V_28 -> V_121 ) ) ;
return 0 ;
case V_8 :
F_10 ( V_132 L_44 ,
V_130 -> V_151 -> V_25 ,
V_28 -> V_121 . V_122 , V_28 -> V_121 . V_152 ,
& V_28 -> V_121 ) ;
return 0 ;
}
return - V_153 ;
}
static int F_86 ( struct V_129 * V_130 , T_4 V_154 ,
unsigned int V_1 , unsigned long V_35 )
{
struct V_27 * V_28 = V_130 -> V_151 -> V_116 ;
int error ;
if ( ! F_87 ( V_155 ) )
return - V_156 ;
F_54 ( V_28 -> V_84 != V_118 ) ;
F_4 ( V_157 , L_45 ,
V_28 -> V_33 -> V_25 , F_1 ( V_1 ) , V_1 , V_35 ) ;
F_9 ( & V_28 -> V_30 ) ;
error = F_74 ( V_130 , V_28 , V_1 , V_35 ) ;
F_12 ( & V_28 -> V_30 ) ;
return error ;
}
static int T_5 F_88 ( void )
{
int V_97 = - V_158 ;
int V_159 ;
int V_160 ;
F_89 ( sizeof( struct V_83 ) != 28 ) ;
if ( V_141 < 0 ) {
F_10 ( V_161 L_46 ) ;
return - V_54 ;
}
V_162 = F_90 ( V_163 , sizeof( * V_162 ) , V_164 ) ;
if ( ! V_162 )
return - V_158 ;
V_160 = 0 ;
if ( V_141 > 0 ) {
V_160 = F_91 ( V_141 ) ;
V_141 = ( 1UL << V_160 ) - 1 ;
}
if ( ( 1UL << V_160 ) > V_165 )
return - V_54 ;
if ( V_163 > 1UL << ( V_166 - V_160 ) )
return - V_54 ;
for ( V_159 = 0 ; V_159 < V_163 ; V_159 ++ ) {
struct V_115 * V_33 = F_92 ( 1 << V_160 ) ;
if ( ! V_33 )
goto V_100;
V_162 [ V_159 ] . V_33 = V_33 ;
V_33 -> V_167 = F_93 ( F_70 , & V_168 ) ;
if ( ! V_33 -> V_167 ) {
F_94 ( V_33 ) ;
goto V_100;
}
F_95 ( V_169 , V_33 -> V_167 ) ;
}
if ( F_96 ( V_170 , L_47 ) ) {
V_97 = - V_19 ;
goto V_100;
}
F_10 ( V_132 L_48 , V_170 ) ;
F_4 ( V_171 , L_49 , V_172 ) ;
for ( V_159 = 0 ; V_159 < V_163 ; V_159 ++ ) {
struct V_115 * V_33 = V_162 [ V_159 ] . V_33 ;
V_162 [ V_159 ] . V_134 = NULL ;
V_162 [ V_159 ] . V_84 = V_118 ;
V_162 [ V_159 ] . V_22 = 0 ;
F_97 ( & V_162 [ V_159 ] . V_127 ) ;
F_98 ( & V_162 [ V_159 ] . V_26 ) ;
F_97 ( & V_162 [ V_159 ] . V_121 ) ;
F_99 ( & V_162 [ V_159 ] . V_30 ) ;
F_100 ( & V_162 [ V_159 ] . V_98 ) ;
F_100 ( & V_162 [ V_159 ] . V_128 ) ;
V_162 [ V_159 ] . V_143 = 1024 ;
V_162 [ V_159 ] . V_144 = 0 ;
V_33 -> V_173 = V_170 ;
V_33 -> V_174 = V_159 << V_160 ;
V_33 -> V_175 = & V_176 ;
V_33 -> V_116 = & V_162 [ V_159 ] ;
sprintf ( V_33 -> V_25 , L_50 , V_159 ) ;
F_81 ( V_33 , 0 ) ;
F_101 ( V_33 ) ;
}
return 0 ;
V_100:
while ( V_159 -- ) {
F_102 ( V_162 [ V_159 ] . V_33 -> V_167 ) ;
F_94 ( V_162 [ V_159 ] . V_33 ) ;
}
F_103 ( V_162 ) ;
return V_97 ;
}
static void T_6 F_104 ( void )
{
int V_159 ;
for ( V_159 = 0 ; V_159 < V_163 ; V_159 ++ ) {
struct V_115 * V_33 = V_162 [ V_159 ] . V_33 ;
V_162 [ V_159 ] . V_84 = 0 ;
if ( V_33 ) {
F_105 ( V_33 ) ;
F_102 ( V_33 -> V_167 ) ;
F_94 ( V_33 ) ;
}
}
F_106 ( V_170 , L_47 ) ;
F_103 ( V_162 ) ;
F_10 ( V_132 L_51 , V_170 ) ;
}
