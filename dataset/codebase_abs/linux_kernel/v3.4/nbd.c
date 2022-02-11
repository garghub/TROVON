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
if ( F_18 ( ! V_31 ) ) {
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_21 ,
( V_41 ? L_22 : L_23 ) ) ;
return - V_53 ;
}
F_20 ( & V_51 , F_21 ( V_40 ) ) ;
F_22 ( V_54 , & V_51 , & V_52 ) ;
do {
V_31 -> V_55 -> V_56 = V_57 ;
V_50 . V_58 = V_42 ;
V_50 . V_59 = V_43 ;
V_48 . V_60 = NULL ;
V_48 . V_61 = 0 ;
V_48 . V_62 = NULL ;
V_48 . V_63 = 0 ;
V_48 . V_44 = V_44 | V_64 ;
if ( V_41 ) {
struct V_65 V_66 ;
if ( V_28 -> V_67 ) {
F_23 ( & V_66 ) ;
V_66 . V_68 = F_14 ;
V_66 . V_69 = ( unsigned long ) V_70 ;
V_66 . V_71 = V_72 + V_28 -> V_67 ;
F_24 ( & V_66 ) ;
}
V_46 = F_25 ( V_31 , & V_48 , & V_50 , 1 , V_43 ) ;
if ( V_28 -> V_67 )
F_26 ( & V_66 ) ;
} else
V_46 = F_27 ( V_31 , & V_48 , & V_50 , 1 , V_43 ,
V_48 . V_44 ) ;
if ( F_28 ( V_70 ) ) {
T_2 V_73 ;
F_15 ( V_37 L_24 ,
F_29 ( V_70 ) , V_70 -> V_38 ,
F_30 ( V_70 , & V_70 -> V_51 , & V_73 ) ) ;
V_46 = - V_74 ;
F_8 ( V_28 , ! V_41 ) ;
break;
}
if ( V_46 <= 0 ) {
if ( V_46 == 0 )
V_46 = - V_75 ;
break;
}
V_43 -= V_46 ;
V_42 += V_46 ;
} while ( V_43 > 0 );
F_22 ( V_54 , & V_52 , NULL ) ;
return V_46 ;
}
static inline int F_31 ( struct V_27 * V_28 , struct V_76 * V_77 ,
int V_22 )
{
int V_46 ;
void * V_78 = F_32 ( V_77 -> V_79 ) ;
V_46 = F_17 ( V_28 , 1 , V_78 + V_77 -> V_80 ,
V_77 -> V_81 , V_22 ) ;
F_33 ( V_77 -> V_79 ) ;
return V_46 ;
}
static int F_34 ( struct V_27 * V_28 , struct V_16 * V_17 )
{
int V_46 , V_22 ;
struct V_82 V_16 ;
unsigned long V_43 = F_35 ( V_17 ) ;
V_16 . V_83 = F_36 ( V_84 ) ;
V_16 . type = F_36 ( F_37 ( V_17 ) ) ;
V_16 . V_85 = F_38 ( ( V_86 ) F_39 ( V_17 ) << 9 ) ;
V_16 . V_87 = F_36 ( V_43 ) ;
memcpy ( V_16 . V_88 , & V_17 , sizeof( V_17 ) ) ;
F_4 ( V_89 , L_25 ,
V_28 -> V_32 -> V_25 , V_17 ,
F_2 ( F_37 ( V_17 ) ) ,
( unsigned long long ) F_39 ( V_17 ) << 9 ,
F_35 ( V_17 ) ) ;
V_46 = F_17 ( V_28 , 1 , & V_16 , sizeof( V_16 ) ,
( F_37 ( V_17 ) == V_14 ) ? V_90 : 0 ) ;
if ( V_46 <= 0 ) {
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_26 , V_46 ) ;
goto V_91;
}
if ( F_37 ( V_17 ) == V_14 ) {
struct V_92 V_93 ;
struct V_76 * V_77 ;
F_40 (bvec, req, iter) {
V_22 = 0 ;
if ( ! F_41 ( V_17 , V_93 ) )
V_22 = V_90 ;
F_4 ( V_89 , L_27 ,
V_28 -> V_32 -> V_25 , V_17 , V_77 -> V_81 ) ;
V_46 = F_31 ( V_28 , V_77 , V_22 ) ;
if ( V_46 <= 0 ) {
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_28 ,
V_46 ) ;
goto V_91;
}
}
}
return 0 ;
V_91:
return - V_19 ;
}
static struct V_16 * F_42 ( struct V_27 * V_28 ,
struct V_16 * V_94 )
{
struct V_16 * V_17 , * V_95 ;
int V_96 ;
V_96 = F_43 ( V_28 -> V_97 , V_28 -> V_98 != V_94 ) ;
if ( F_18 ( V_96 ) )
goto V_99;
F_44 ( & V_28 -> V_26 ) ;
F_45 (req, tmp, &nbd->queue_head, queuelist) {
if ( V_17 != V_94 )
continue;
F_46 ( & V_17 -> V_100 ) ;
F_47 ( & V_28 -> V_26 ) ;
return V_17 ;
}
F_47 ( & V_28 -> V_26 ) ;
V_96 = - V_101 ;
V_99:
return F_48 ( V_96 ) ;
}
static inline int F_49 ( struct V_27 * V_28 , struct V_76 * V_77 )
{
int V_46 ;
void * V_78 = F_32 ( V_77 -> V_79 ) ;
V_46 = F_17 ( V_28 , 0 , V_78 + V_77 -> V_80 , V_77 -> V_81 ,
V_102 ) ;
F_33 ( V_77 -> V_79 ) ;
return V_46 ;
}
static struct V_16 * F_50 ( struct V_27 * V_28 )
{
int V_46 ;
struct V_103 V_104 ;
struct V_16 * V_17 ;
V_104 . V_83 = 0 ;
V_46 = F_17 ( V_28 , 0 , & V_104 , sizeof( V_104 ) , V_102 ) ;
if ( V_46 <= 0 ) {
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_29 , V_46 ) ;
goto V_105;
}
if ( F_51 ( V_104 . V_83 ) != V_106 ) {
F_19 ( F_11 ( V_28 -> V_32 ) , L_30 ,
( unsigned long ) F_51 ( V_104 . V_83 ) ) ;
V_46 = - V_107 ;
goto V_105;
}
V_17 = F_42 ( V_28 , * (struct V_16 * * ) V_104 . V_88 ) ;
if ( F_52 ( V_17 ) ) {
V_46 = F_53 ( V_17 ) ;
if ( V_46 != - V_101 )
goto V_105;
F_19 ( F_11 ( V_28 -> V_32 ) , L_31 ,
V_104 . V_88 ) ;
V_46 = - V_108 ;
goto V_105;
}
if ( F_51 ( V_104 . error ) ) {
F_19 ( F_11 ( V_28 -> V_32 ) , L_32 ,
F_51 ( V_104 . error ) ) ;
V_17 -> V_18 ++ ;
return V_17 ;
}
F_4 ( V_109 , L_33 ,
V_28 -> V_32 -> V_25 , V_17 ) ;
if ( F_37 ( V_17 ) == V_13 ) {
struct V_92 V_93 ;
struct V_76 * V_77 ;
F_40 (bvec, req, iter) {
V_46 = F_49 ( V_28 , V_77 ) ;
if ( V_46 <= 0 ) {
F_19 ( F_11 ( V_28 -> V_32 ) , L_34 ,
V_46 ) ;
V_17 -> V_18 ++ ;
return V_17 ;
}
F_4 ( V_109 , L_35 ,
V_28 -> V_32 -> V_25 , V_17 , V_77 -> V_81 ) ;
}
}
return V_17 ;
V_105:
V_28 -> V_105 = V_46 ;
return NULL ;
}
static T_3 F_54 ( struct V_110 * V_111 ,
struct V_112 * V_113 , char * V_42 )
{
struct V_114 * V_32 = F_55 ( V_111 ) ;
return sprintf ( V_42 , L_36 ,
( long ) ( (struct V_27 * ) V_32 -> V_115 ) -> V_39 ) ;
}
static int F_56 ( struct V_27 * V_28 )
{
struct V_16 * V_17 ;
int V_116 ;
F_57 ( V_28 -> V_83 != V_117 ) ;
V_28 -> V_39 = F_29 ( V_70 ) ;
V_116 = F_58 ( F_11 ( V_28 -> V_32 ) , & V_118 ) ;
if ( V_116 ) {
F_19 ( F_11 ( V_28 -> V_32 ) , L_37 ) ;
V_28 -> V_39 = 0 ;
return V_116 ;
}
while ( ( V_17 = F_50 ( V_28 ) ) != NULL )
F_3 ( V_17 ) ;
F_59 ( F_11 ( V_28 -> V_32 ) , & V_118 ) ;
V_28 -> V_39 = 0 ;
return 0 ;
}
static void F_60 ( struct V_27 * V_28 )
{
struct V_16 * V_17 ;
F_57 ( V_28 -> V_83 != V_117 ) ;
F_57 ( V_28 -> V_31 ) ;
F_57 ( V_28 -> V_98 ) ;
while ( ! F_61 ( & V_28 -> V_119 ) ) {
V_17 = F_62 ( V_28 -> V_119 . V_120 , struct V_16 ,
V_100 ) ;
F_46 ( & V_17 -> V_100 ) ;
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
}
}
static void F_63 ( struct V_27 * V_28 , struct V_16 * V_17 )
{
if ( V_17 -> V_121 != V_122 )
goto V_91;
F_37 ( V_17 ) = V_13 ;
if ( F_64 ( V_17 ) == V_123 ) {
F_37 ( V_17 ) = V_14 ;
if ( V_28 -> V_22 & V_124 ) {
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_38 ) ;
goto V_91;
}
}
V_17 -> V_18 = 0 ;
F_9 ( & V_28 -> V_30 ) ;
if ( F_18 ( ! V_28 -> V_31 ) ) {
F_13 ( & V_28 -> V_30 ) ;
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_39 ) ;
goto V_91;
}
V_28 -> V_98 = V_17 ;
if ( F_34 ( V_28 , V_17 ) != 0 ) {
F_19 ( F_11 ( V_28 -> V_32 ) , L_40 ) ;
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
} else {
F_44 ( & V_28 -> V_26 ) ;
F_65 ( & V_17 -> V_100 , & V_28 -> V_119 ) ;
F_47 ( & V_28 -> V_26 ) ;
}
V_28 -> V_98 = NULL ;
F_13 ( & V_28 -> V_30 ) ;
F_66 ( & V_28 -> V_97 ) ;
return;
V_91:
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
}
static int F_67 ( void * V_69 )
{
struct V_27 * V_28 = V_69 ;
struct V_16 * V_17 ;
F_68 ( V_70 , - 20 ) ;
while ( ! F_69 () || ! F_61 ( & V_28 -> V_125 ) ) {
F_43 ( V_28 -> V_126 ,
F_69 () ||
! F_61 ( & V_28 -> V_125 ) ) ;
if ( F_61 ( & V_28 -> V_125 ) )
continue;
F_70 ( & V_28 -> V_26 ) ;
V_17 = F_62 ( V_28 -> V_125 . V_120 , struct V_16 ,
V_100 ) ;
F_46 ( & V_17 -> V_100 ) ;
F_71 ( & V_28 -> V_26 ) ;
F_63 ( V_28 , V_17 ) ;
}
return 0 ;
}
static void F_72 ( struct V_20 * V_21 )
{
struct V_16 * V_17 ;
while ( ( V_17 = F_73 ( V_21 ) ) != NULL ) {
struct V_27 * V_28 ;
F_71 ( V_21 -> V_26 ) ;
F_4 ( V_23 , L_41 ,
V_17 -> V_24 -> V_25 , V_17 , V_17 -> V_121 ) ;
V_28 = V_17 -> V_24 -> V_115 ;
F_57 ( V_28 -> V_83 != V_117 ) ;
if ( F_18 ( ! V_28 -> V_31 ) ) {
F_19 ( F_11 ( V_28 -> V_32 ) ,
L_39 ) ;
V_17 -> V_18 ++ ;
F_3 ( V_17 ) ;
F_70 ( V_21 -> V_26 ) ;
continue;
}
F_70 ( & V_28 -> V_26 ) ;
F_74 ( & V_17 -> V_100 , & V_28 -> V_125 ) ;
F_71 ( & V_28 -> V_26 ) ;
F_75 ( & V_28 -> V_126 ) ;
F_70 ( V_21 -> V_26 ) ;
}
}
static int F_76 ( struct V_127 * V_128 , struct V_27 * V_28 ,
unsigned int V_1 , unsigned long V_34 )
{
switch ( V_1 ) {
case V_10 : {
struct V_16 V_129 ;
F_77 ( F_11 ( V_28 -> V_32 ) , L_42 ) ;
F_78 ( NULL , & V_129 ) ;
V_129 . V_121 = V_130 ;
F_37 ( & V_129 ) = V_15 ;
if ( ! V_28 -> V_31 )
return - V_53 ;
F_34 ( V_28 , & V_129 ) ;
return 0 ;
}
case V_6 : {
struct V_131 * V_131 ;
V_28 -> V_31 = NULL ;
V_131 = V_28 -> V_131 ;
V_28 -> V_131 = NULL ;
F_60 ( V_28 ) ;
F_57 ( ! F_61 ( & V_28 -> V_119 ) ) ;
if ( V_131 )
F_79 ( V_131 ) ;
return 0 ;
}
case V_2 : {
struct V_131 * V_131 ;
if ( V_28 -> V_131 )
return - V_132 ;
V_131 = F_80 ( V_34 ) ;
if ( V_131 ) {
struct V_133 * V_133 = V_131 -> V_134 . V_135 -> V_136 ;
if ( F_81 ( V_133 -> V_137 ) ) {
V_28 -> V_131 = V_131 ;
V_28 -> V_31 = F_82 ( V_133 ) ;
if ( V_138 > 0 )
V_128 -> V_139 = 1 ;
return 0 ;
} else {
F_79 ( V_131 ) ;
}
}
return - V_53 ;
}
case V_3 :
V_28 -> V_140 = V_34 ;
V_28 -> V_141 &= ~ ( V_28 -> V_140 - 1 ) ;
V_128 -> V_142 -> V_143 = V_28 -> V_141 ;
F_83 ( V_128 , V_28 -> V_140 ) ;
F_84 ( V_28 -> V_32 , V_28 -> V_141 >> 9 ) ;
return 0 ;
case V_4 :
V_28 -> V_141 = V_34 & ~ ( V_28 -> V_140 - 1 ) ;
V_128 -> V_142 -> V_143 = V_28 -> V_141 ;
F_83 ( V_128 , V_28 -> V_140 ) ;
F_84 ( V_28 -> V_32 , V_28 -> V_141 >> 9 ) ;
return 0 ;
case V_144 :
V_28 -> V_67 = V_34 * V_145 ;
return 0 ;
case V_9 :
V_28 -> V_141 = ( ( V_86 ) V_34 ) * V_28 -> V_140 ;
V_128 -> V_142 -> V_143 = V_28 -> V_141 ;
F_83 ( V_128 , V_28 -> V_140 ) ;
F_84 ( V_28 -> V_32 , V_28 -> V_141 >> 9 ) ;
return 0 ;
case V_5 : {
struct V_35 * V_146 ;
struct V_131 * V_131 ;
int error ;
if ( V_28 -> V_39 )
return - V_132 ;
if ( ! V_28 -> V_131 )
return - V_53 ;
F_13 ( & V_28 -> V_30 ) ;
V_146 = F_85 ( F_67 , V_28 , V_28 -> V_32 -> V_25 ) ;
if ( F_52 ( V_146 ) ) {
F_9 ( & V_28 -> V_30 ) ;
return F_53 ( V_146 ) ;
}
F_86 ( V_146 ) ;
error = F_56 ( V_28 ) ;
F_87 ( V_146 ) ;
F_9 ( & V_28 -> V_30 ) ;
if ( error )
return error ;
F_8 ( V_28 , 0 ) ;
V_131 = V_28 -> V_131 ;
V_28 -> V_131 = NULL ;
F_60 ( V_28 ) ;
F_10 ( F_11 ( V_28 -> V_32 ) , L_43 ) ;
if ( V_131 )
F_79 ( V_131 ) ;
V_28 -> V_141 = 0 ;
V_128 -> V_142 -> V_143 = 0 ;
F_84 ( V_28 -> V_32 , 0 ) ;
if ( V_138 > 0 )
F_88 ( V_128 , V_147 , 0 ) ;
return V_28 -> V_105 ;
}
case V_7 :
F_57 ( ! V_28 -> V_31 && ! F_61 ( & V_28 -> V_119 ) ) ;
return 0 ;
case V_8 :
F_77 ( F_11 ( V_28 -> V_32 ) ,
L_44 ,
V_28 -> V_119 . V_120 , V_28 -> V_119 . V_148 ,
& V_28 -> V_119 ) ;
return 0 ;
}
return - V_149 ;
}
static int F_89 ( struct V_127 * V_128 , T_4 V_150 ,
unsigned int V_1 , unsigned long V_34 )
{
struct V_27 * V_28 = V_128 -> V_151 -> V_115 ;
int error ;
if ( ! F_90 ( V_152 ) )
return - V_153 ;
F_57 ( V_28 -> V_83 != V_117 ) ;
F_4 ( V_154 , L_45 ,
V_28 -> V_32 -> V_25 , F_1 ( V_1 ) , V_1 , V_34 ) ;
F_9 ( & V_28 -> V_30 ) ;
error = F_76 ( V_128 , V_28 , V_1 , V_34 ) ;
F_13 ( & V_28 -> V_30 ) ;
return error ;
}
static int T_5 F_91 ( void )
{
int V_96 = - V_155 ;
int V_156 ;
int V_157 ;
F_92 ( sizeof( struct V_82 ) != 28 ) ;
if ( V_138 < 0 ) {
F_15 ( V_158 L_46 ) ;
return - V_53 ;
}
V_159 = F_93 ( V_160 , sizeof( * V_159 ) , V_161 ) ;
if ( ! V_159 )
return - V_155 ;
V_157 = 0 ;
if ( V_138 > 0 ) {
V_157 = F_94 ( V_138 ) ;
V_138 = ( 1UL << V_157 ) - 1 ;
}
if ( ( 1UL << V_157 ) > V_162 )
return - V_53 ;
if ( V_160 > 1UL << ( V_163 - V_157 ) )
return - V_53 ;
for ( V_156 = 0 ; V_156 < V_160 ; V_156 ++ ) {
struct V_114 * V_32 = F_95 ( 1 << V_157 ) ;
if ( ! V_32 )
goto V_99;
V_159 [ V_156 ] . V_32 = V_32 ;
V_32 -> V_164 = F_96 ( F_72 , & V_165 ) ;
if ( ! V_32 -> V_164 ) {
F_97 ( V_32 ) ;
goto V_99;
}
F_98 ( V_166 , V_32 -> V_164 ) ;
}
if ( F_99 ( V_167 , L_47 ) ) {
V_96 = - V_19 ;
goto V_99;
}
F_15 ( V_168 L_48 , V_167 ) ;
F_4 ( V_169 , L_49 , V_170 ) ;
for ( V_156 = 0 ; V_156 < V_160 ; V_156 ++ ) {
struct V_114 * V_32 = V_159 [ V_156 ] . V_32 ;
V_159 [ V_156 ] . V_131 = NULL ;
V_159 [ V_156 ] . V_83 = V_117 ;
V_159 [ V_156 ] . V_22 = 0 ;
F_100 ( & V_159 [ V_156 ] . V_125 ) ;
F_101 ( & V_159 [ V_156 ] . V_26 ) ;
F_100 ( & V_159 [ V_156 ] . V_119 ) ;
F_102 ( & V_159 [ V_156 ] . V_30 ) ;
F_103 ( & V_159 [ V_156 ] . V_97 ) ;
F_103 ( & V_159 [ V_156 ] . V_126 ) ;
V_159 [ V_156 ] . V_140 = 1024 ;
V_159 [ V_156 ] . V_141 = 0 ;
V_32 -> V_171 = V_167 ;
V_32 -> V_172 = V_156 << V_157 ;
V_32 -> V_173 = & V_174 ;
V_32 -> V_115 = & V_159 [ V_156 ] ;
sprintf ( V_32 -> V_25 , L_50 , V_156 ) ;
F_84 ( V_32 , 0 ) ;
F_104 ( V_32 ) ;
}
return 0 ;
V_99:
while ( V_156 -- ) {
F_105 ( V_159 [ V_156 ] . V_32 -> V_164 ) ;
F_97 ( V_159 [ V_156 ] . V_32 ) ;
}
F_106 ( V_159 ) ;
return V_96 ;
}
static void T_6 F_107 ( void )
{
int V_156 ;
for ( V_156 = 0 ; V_156 < V_160 ; V_156 ++ ) {
struct V_114 * V_32 = V_159 [ V_156 ] . V_32 ;
V_159 [ V_156 ] . V_83 = 0 ;
if ( V_32 ) {
F_108 ( V_32 ) ;
F_105 ( V_32 -> V_164 ) ;
F_97 ( V_32 ) ;
}
}
F_109 ( V_167 , L_47 ) ;
F_106 ( V_159 ) ;
F_15 ( V_168 L_51 , V_167 ) ;
}
