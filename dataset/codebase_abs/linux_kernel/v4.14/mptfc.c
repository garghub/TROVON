static int
F_1 ( struct V_1 * V_2 ,
int (* F_2)( struct V_1 * V_2 ) ,
const char * V_3 )
{
T_1 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_12 = F_3 ( F_4 ( V_6 ) ) ;
unsigned long V_13 ;
int V_14 ;
T_2 * V_15 ;
int V_16 = 40 ;
V_4 = F_5 ( V_2 -> V_7 -> V_10 ) ;
V_15 = V_4 -> V_15 ;
F_6 ( V_9 -> V_17 , V_13 ) ;
while ( ( V_14 = F_7 ( V_12 ) >> 16 ) == V_18
|| ( V_16 > 0 && V_15 -> V_19 == 0 ) ) {
F_8 ( V_9 -> V_17 , V_13 ) ;
F_9 ( V_15 , F_10 ( V_20
L_1
L_2 ,
V_15 -> V_21 , V_15 -> V_22 -> V_23 ,
V_2 -> V_7 -> V_24 , V_2 -> V_7 -> V_25 ,
V_14 , V_15 -> V_19 , V_3 ) ) ;
F_11 ( 1000 ) ;
F_6 ( V_9 -> V_17 , V_13 ) ;
V_16 -- ;
}
F_8 ( V_9 -> V_17 , V_13 ) ;
if ( V_14 == V_26 || ! V_2 -> V_7 -> V_27
|| V_15 -> V_19 == 0 ) {
F_9 ( V_15 , F_10 ( V_20
L_3
L_4 , V_3 ,
V_15 -> V_21 , V_15 -> V_22 -> V_23 ,
V_2 -> V_7 -> V_24 , V_2 -> V_7 -> V_25 , V_14 ,
V_15 -> V_19 , V_2 -> V_7 -> V_27 ) ) ;
return V_28 ;
}
F_9 ( V_15 , F_10 ( V_20
L_5 , V_3 ,
V_15 -> V_21 , V_15 -> V_22 -> V_23 ,
V_2 -> V_7 -> V_24 , V_2 -> V_7 -> V_25 ) ) ;
return (* F_2)( V_2 ) ;
}
static int
F_12 ( struct V_1 * V_2 )
{
return
F_1 ( V_2 , V_29 , V_30 ) ;
}
static int
F_13 ( struct V_1 * V_2 )
{
return
F_1 ( V_2 , V_31 , V_30 ) ;
}
static int
F_14 ( struct V_1 * V_2 )
{
return
F_1 ( V_2 , V_32 , V_30 ) ;
}
static void
F_15 ( struct V_11 * V_12 , T_3 V_33 )
{
if ( V_33 > 0 )
V_12 -> V_34 = V_33 ;
else
V_12 -> V_34 = V_35 ;
}
static int
F_16 ( const void * V_36 , const void * V_37 )
{
T_4 * * V_38 = ( T_4 * * ) V_36 ;
T_4 * * V_39 = ( T_4 * * ) V_37 ;
if ( ( * V_38 ) -> V_40 == ( * V_39 ) -> V_40 ) {
if ( ( * V_38 ) -> V_41 == ( * V_39 ) -> V_41 )
return 0 ;
if ( ( * V_38 ) -> V_41 < ( * V_39 ) -> V_41 )
return - 1 ;
return 1 ;
}
if ( ( * V_38 ) -> V_40 < ( * V_39 ) -> V_40 )
return - 1 ;
return 1 ;
}
static int
F_17 ( T_2 * V_15 , int V_42 ,
void (* F_2)( T_2 * V_15 , int V_43 , T_4 * V_44 ) )
{
T_5 V_45 ;
T_6 V_46 ;
T_4 * V_47 , * V_48 ;
T_7 V_49 ;
int V_50 ;
int V_51 ;
T_4 * V_52 = NULL , * V_53 ;
T_4 * * V_54 = NULL , * * V_55 ;
int V_56 = - V_57 ;
T_8 V_58 = 0xffffff ;
int V_59 = 0 ;
int V_60 = V_15 -> V_61 . V_62 ;
int V_63 ;
V_63 = ( V_15 -> V_61 . V_64 == 0 ) ? 256 : V_15 -> V_61 . V_64 ;
V_50 = sizeof( T_4 ) * V_60 * V_63 ;
V_53 = V_52 = F_18 ( V_50 , V_65 ) ;
if ( ! V_52 )
goto V_66;
V_50 = sizeof( T_4 * ) * V_60 * V_63 ;
V_55 = V_54 = F_18 ( V_50 , V_65 ) ;
if ( ! V_54 )
goto V_66;
do {
V_45 . V_67 = 0 ;
V_45 . V_68 = 0 ;
V_45 . V_69 = 0 ;
V_45 . V_70 = V_71 ;
V_46 . V_72 . V_45 = & V_45 ;
V_46 . V_73 = - 1 ;
V_46 . V_74 = V_75 ;
V_46 . V_76 = 0 ;
V_46 . V_77 = V_58 ;
V_46 . V_33 = 0 ;
if ( ( V_56 = F_19 ( V_15 , & V_46 ) ) != 0 )
break;
if ( V_45 . V_68 <= 0 )
break;
V_50 = V_45 . V_68 * 4 ;
V_47 = F_20 ( V_15 -> V_78 , V_50 ,
& V_49 ) ;
V_56 = - V_57 ;
if ( ! V_47 )
break;
V_46 . V_73 = V_49 ;
V_46 . V_74 = V_79 ;
if ( ( V_56 = F_19 ( V_15 , & V_46 ) ) == 0 ) {
V_47 -> V_80 =
F_21 ( V_47 -> V_80 ) ;
V_47 -> V_81 . V_82 =
F_21 ( V_47 -> V_81 . V_82 ) ;
V_47 -> V_81 . V_83 =
F_21 ( V_47 -> V_81 . V_83 ) ;
V_47 -> V_84 . V_82 =
F_21 ( V_47 -> V_84 . V_82 ) ;
V_47 -> V_84 . V_83 =
F_21 ( V_47 -> V_84 . V_83 ) ;
V_47 -> V_85 =
F_22 ( V_47 -> V_85 ) ;
V_47 -> V_86 =
F_22 ( V_47 -> V_86 ) ;
V_58 = V_47 -> V_80 ;
V_59 ++ ;
* V_53 = * V_47 ;
* V_55 ++ = V_53 ++ ;
}
F_23 ( V_15 -> V_78 , V_50 ,
( V_87 * ) V_47 , V_49 ) ;
if ( V_56 != 0 )
break;
} while ( V_58 <= 0xff0000 );
if ( V_59 ) {
if ( V_59 > 1 )
F_24 ( V_54 , V_59 , sizeof( T_4 * ) ,
F_16 , NULL ) ;
for ( V_51 = 0 ; V_51 < V_59 ; V_51 ++ ) {
V_48 = * ( V_54 + V_51 ) ;
F_2 ( V_15 , V_42 , V_48 ) ;
}
}
V_66:
F_25 ( V_54 ) ;
F_25 ( V_52 ) ;
return V_56 ;
}
static int
F_26 ( T_4 * V_88 , struct V_89 * V_90 )
{
if ( V_88 -> V_91 & ( V_92 |
V_93 ) )
return - 1 ;
if ( ! ( V_88 -> V_91 & V_94 ) )
return - 1 ;
if ( ! ( V_88 -> V_95 & V_96 ) )
return - 1 ;
V_90 -> V_97 = ( ( V_98 ) V_88 -> V_81 . V_83 ) << 32 | ( V_98 ) V_88 -> V_81 . V_82 ;
V_90 -> V_99 = ( ( V_98 ) V_88 -> V_84 . V_83 ) << 32 | ( V_98 ) V_88 -> V_84 . V_82 ;
V_90 -> V_58 = V_88 -> V_80 ;
V_90 -> V_100 = V_101 ;
return 0 ;
}
static void
F_27 ( T_2 * V_15 , int V_43 , T_4 * V_88 )
{
struct V_89 V_102 ;
struct V_11 * V_12 ;
struct V_103 * V_104 ;
int V_105 = 1 ;
V_98 V_106 , V_107 ;
T_9 * V_108 ;
T_10 V_100 = V_101 ;
if ( F_26 ( V_88 , & V_102 ) < 0 )
return;
V_100 |= V_109 ;
if ( V_88 -> V_95 & V_110 )
V_100 |= V_111 ;
F_28 (ri, &ioc->fc_rports, list) {
V_106 = ( V_98 ) V_104 -> V_88 . V_84 . V_83 << 32 | ( V_98 ) V_104 -> V_88 . V_84 . V_82 ;
if ( V_106 == V_102 . V_99 ) {
F_29 ( & V_104 -> V_112 , & V_15 -> V_113 ) ;
V_105 = 0 ;
break;
}
}
if ( V_105 ) {
V_104 = F_18 ( sizeof( struct V_103 ) , V_65 ) ;
if ( ! V_104 )
return;
F_30 ( & V_104 -> V_112 , & V_15 -> V_113 ) ;
}
V_104 -> V_88 = * V_88 ;
V_104 -> V_13 &= ~ V_114 ;
if ( ! ( V_104 -> V_13 & V_115 ) ) {
V_104 -> V_13 |= V_115 ;
V_12 = F_31 ( V_15 -> V_22 , V_43 , & V_102 ) ;
if ( V_12 ) {
V_104 -> V_12 = V_12 ;
if ( V_105 )
V_12 -> V_34 = V_35 ;
if ( V_104 -> V_116 ) {
V_108 = V_104 -> V_116 -> V_27 ;
if ( V_108 ) {
V_108 -> V_24 = V_88 -> V_41 ;
V_108 -> V_43 = V_88 -> V_40 ;
V_108 -> V_117 = 0 ;
}
}
* ( (struct V_103 * * ) V_12 -> V_118 ) = V_104 ;
F_32 ( V_12 , V_100 ) ;
V_106 = ( V_98 ) V_104 -> V_88 . V_84 . V_83 << 32 | ( V_98 ) V_104 -> V_88 . V_84 . V_82 ;
V_107 = ( V_98 ) V_104 -> V_88 . V_81 . V_83 << 32 | ( V_98 ) V_104 -> V_88 . V_81 . V_82 ;
F_9 ( V_15 , F_10 ( V_20
L_6
L_7 ,
V_15 -> V_21 ,
V_15 -> V_22 -> V_23 ,
V_88 -> V_80 ,
( unsigned long long ) V_107 ,
( unsigned long long ) V_106 ,
V_88 -> V_41 ,
V_104 -> V_12 -> V_119 ,
V_104 -> V_12 -> V_34 ) ) ;
} else {
F_33 ( & V_104 -> V_112 ) ;
F_25 ( V_104 ) ;
V_104 = NULL ;
}
}
}
static void
F_34 ( struct F_4 * V_116 )
{
struct V_11 * V_12 ;
struct V_103 * V_104 ;
V_12 = F_3 ( V_116 ) ;
if ( V_12 ) {
V_104 = * ( (struct V_103 * * ) V_12 -> V_118 ) ;
if ( V_104 )
V_104 -> V_116 = NULL ;
}
F_25 ( V_116 -> V_27 ) ;
V_116 -> V_27 = NULL ;
}
static int
F_35 ( struct F_4 * V_116 )
{
T_9 * V_108 ;
struct V_11 * V_12 ;
struct V_103 * V_104 ;
int V_56 ;
V_108 = F_18 ( sizeof( T_9 ) , V_65 ) ;
if ( ! V_108 )
return - V_57 ;
V_116 -> V_27 = V_108 ;
V_56 = - V_120 ;
V_12 = F_3 ( V_116 ) ;
if ( V_12 ) {
V_104 = * ( (struct V_103 * * ) V_12 -> V_118 ) ;
if ( V_104 ) {
V_108 -> V_24 = V_104 -> V_88 . V_41 ;
V_108 -> V_43 = V_104 -> V_88 . V_40 ;
V_104 -> V_116 = V_116 ;
V_56 = 0 ;
}
}
if ( V_56 != 0 ) {
F_25 ( V_108 ) ;
V_116 -> V_27 = NULL ;
}
return V_56 ;
}
static void
F_36 ( T_2 * V_15 , struct V_11 * V_12 , struct V_5 * V_6 ,
T_9 * V_108 )
{
V_98 V_107 , V_106 ;
struct V_103 * V_104 ;
V_104 = * ( (struct V_103 * * ) V_12 -> V_118 ) ;
V_106 = ( V_98 ) V_104 -> V_88 . V_84 . V_83 << 32 | ( V_98 ) V_104 -> V_88 . V_84 . V_82 ;
V_107 = ( V_98 ) V_104 -> V_88 . V_81 . V_83 << 32 | ( V_98 ) V_104 -> V_88 . V_81 . V_82 ;
F_9 ( V_15 , F_10 ( V_20
L_8
L_9 ,
V_15 -> V_21 ,
V_6 -> V_10 -> V_23 ,
V_108 -> V_121 ,
V_6 -> V_24 , V_104 -> V_88 . V_41 ,
V_104 -> V_88 . V_80 ,
( unsigned long long ) V_106 ,
( unsigned long long ) V_107 ) ) ;
}
static int
F_37 ( struct V_5 * V_6 )
{
T_1 * V_4 ;
T_9 * V_108 ;
T_11 * V_122 ;
struct F_4 * V_116 ;
struct V_11 * V_12 ;
T_2 * V_15 ;
V_116 = F_4 ( V_6 ) ;
V_12 = F_3 ( V_116 ) ;
if ( ! V_12 || F_7 ( V_12 ) )
return - V_123 ;
V_4 = F_5 ( V_6 -> V_10 ) ;
V_15 = V_4 -> V_15 ;
V_122 = F_18 ( sizeof( T_11 ) , V_65 ) ;
if ( ! V_122 ) {
F_10 ( V_124 L_10 ,
V_15 -> V_21 , sizeof( T_11 ) ) ;
return - V_57 ;
}
V_6 -> V_27 = V_122 ;
V_108 = V_116 -> V_27 ;
if ( V_108 -> V_121 == 0 ) {
V_108 -> V_125 = V_15 -> V_24 ;
V_108 -> V_126 = V_127 ;
}
V_122 -> V_108 = V_108 ;
V_122 -> V_25 = V_6 -> V_25 ;
V_108 -> V_121 ++ ;
F_36 ( V_15 , V_12 , V_6 , V_108 ) ;
return 0 ;
}
static int
F_38 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_103 * V_104 ;
struct V_11 * V_12 = F_3 ( F_4 ( V_2 -> V_7 ) ) ;
int V_128 ;
T_11 * V_122 = V_2 -> V_7 -> V_27 ;
if ( ! V_122 || ! V_122 -> V_108 ) {
V_2 -> V_129 = V_26 << 16 ;
V_2 -> V_130 ( V_2 ) ;
return 0 ;
}
V_128 = F_7 ( V_12 ) ;
if ( F_39 ( V_128 ) ) {
V_2 -> V_129 = V_128 ;
V_2 -> V_130 ( V_2 ) ;
return 0 ;
}
V_104 = * ( (struct V_103 * * ) V_12 -> V_118 ) ;
if ( F_39 ( ! V_104 ) ) {
V_2 -> V_129 = V_18 << 16 ;
V_2 -> V_130 ( V_2 ) ;
return 0 ;
}
return F_40 ( V_2 ) ;
}
static void
F_41 ( T_2 * V_15 , int V_131 , T_12 * V_132 )
{
V_87 V_133 , V_134 , V_135 ;
char * V_136 , * V_137 ;
if ( V_131 >= 2 )
return;
V_133 = V_15 -> V_138 [ V_131 ] ;
V_134 = V_132 -> V_139 ;
V_135 = V_132 -> V_140 ;
if ( V_135 != V_141 &&
V_134 != V_142 ) {
V_136 = V_133 == V_143 ? L_11 :
V_133 == V_144 ? L_12 :
V_133 == V_145 ? L_13 :
L_14 ;
V_137 = V_134 == V_143 ? L_11 :
V_134 == V_144 ? L_12 :
V_134 == V_145 ? L_13 :
L_14 ;
if ( V_133 == 0 )
F_10 ( V_146
L_15 ,
V_15 -> V_21 , V_137 ) ;
else if ( V_133 != V_134 )
F_10 ( V_147
L_16 ,
V_15 -> V_21 , V_136 , V_137 ) ;
V_15 -> V_138 [ V_131 ] = V_134 ;
}
}
static int
F_42 ( T_2 * V_15 , int V_131 )
{
T_5 V_45 ;
T_6 V_46 ;
T_12 * V_47 ;
T_12 * V_132 ;
T_7 V_49 ;
int V_50 ;
int V_148 ;
int V_56 ;
int V_149 = 400 ;
if ( V_131 > 1 )
return - V_150 ;
V_45 . V_67 = 0 ;
V_45 . V_68 = 0 ;
V_45 . V_69 = 0 ;
V_45 . V_70 = V_151 ;
V_46 . V_72 . V_45 = & V_45 ;
V_46 . V_73 = - 1 ;
V_46 . V_74 = V_75 ;
V_46 . V_76 = 0 ;
V_46 . V_77 = V_131 ;
V_46 . V_33 = 0 ;
if ( ( V_56 = F_19 ( V_15 , & V_46 ) ) != 0 )
return V_56 ;
if ( V_45 . V_68 == 0 )
return 0 ;
V_50 = V_45 . V_68 * 4 ;
V_56 = - V_57 ;
V_47 = ( T_12 * ) F_20 ( V_15 -> V_78 , V_50 , & V_49 ) ;
if ( V_47 ) {
V_152:
memset ( ( V_87 * ) V_47 , 0 , V_50 ) ;
V_46 . V_73 = V_49 ;
V_46 . V_74 = V_79 ;
if ( ( V_56 = F_19 ( V_15 , & V_46 ) ) == 0 ) {
V_132 = & V_15 -> V_153 [ V_131 ] ;
V_148 = F_43 ( int , sizeof( T_12 ) , V_50 ) ;
memcpy ( V_132 , V_47 , V_148 ) ;
V_132 -> V_91 = F_21 ( V_132 -> V_91 ) ;
V_132 -> V_80 = F_21 ( V_132 -> V_80 ) ;
V_132 -> V_81 . V_82 = F_21 ( V_132 -> V_81 . V_82 ) ;
V_132 -> V_81 . V_83 = F_21 ( V_132 -> V_81 . V_83 ) ;
V_132 -> V_84 . V_82 = F_21 ( V_132 -> V_84 . V_82 ) ;
V_132 -> V_84 . V_83 = F_21 ( V_132 -> V_84 . V_83 ) ;
V_132 -> V_154 = F_21 ( V_132 -> V_154 ) ;
V_132 -> V_155 = F_21 ( V_132 -> V_155 ) ;
V_132 -> V_139 = F_21 ( V_132 -> V_139 ) ;
V_132 -> V_156 = F_21 ( V_132 -> V_156 ) ;
V_132 -> V_157 . V_82 = F_21 ( V_132 -> V_157 . V_82 ) ;
V_132 -> V_157 . V_83 = F_21 ( V_132 -> V_157 . V_83 ) ;
V_132 -> V_158 . V_82 = F_21 ( V_132 -> V_158 . V_82 ) ;
V_132 -> V_158 . V_83 = F_21 ( V_132 -> V_158 . V_83 ) ;
V_132 -> V_159 = F_21 ( V_132 -> V_159 ) ;
V_132 -> V_160 = F_21 ( V_132 -> V_160 ) ;
if ( ( V_132 -> V_140 == V_161 ) ||
( V_132 -> V_140 == V_162 &&
( V_132 -> V_91 & V_163 )
== V_164 ) ) {
if ( V_149 -- > 0 ) {
F_11 ( 100 ) ;
goto V_152;
}
F_10 ( V_165 L_17
L_18 ,
V_15 -> V_21 ) ;
}
F_41 ( V_15 , V_131 , V_132 ) ;
}
F_23 ( V_15 -> V_78 , V_50 , ( V_87 * ) V_47 , V_49 ) ;
}
return V_56 ;
}
static int
F_44 ( T_2 * V_15 , int V_131 )
{
T_5 V_45 ;
T_6 V_46 ;
int V_56 ;
if ( V_131 > 1 )
return - V_150 ;
if ( ! ( V_15 -> V_166 . V_167 [ V_131 ] . V_168 ) )
return - V_150 ;
V_45 . V_67 = 0 ;
V_45 . V_68 = 0 ;
V_45 . V_69 = 1 ;
V_45 . V_70 = V_151 ;
V_46 . V_72 . V_45 = & V_45 ;
V_46 . V_73 = - 1 ;
V_46 . V_74 = V_75 ;
V_46 . V_76 = 0 ;
V_46 . V_77 = V_131 ;
V_46 . V_33 = 0 ;
if ( ( V_56 = F_19 ( V_15 , & V_46 ) ) != 0 )
return V_56 ;
if ( V_45 . V_68 == 0 )
return - V_120 ;
if ( V_45 . V_68 * 4 != V_15 -> V_166 . V_167 [ V_131 ] . V_169 )
return - V_150 ;
V_46 . V_73 = V_15 -> V_166 . V_167 [ V_131 ] . V_170 ;
V_46 . V_74 = V_171 ;
V_46 . V_76 = 1 ;
V_56 = F_19 ( V_15 , & V_46 ) ;
return V_56 ;
}
static int
F_45 ( T_2 * V_15 , int V_131 )
{
T_5 V_45 ;
T_6 V_46 ;
T_13 * V_172 ;
T_7 V_173 ;
int V_50 ;
int V_56 ;
if ( V_131 > 1 )
return - V_150 ;
V_45 . V_67 = 0 ;
V_45 . V_68 = 0 ;
V_45 . V_69 = 1 ;
V_45 . V_70 = V_151 ;
V_46 . V_72 . V_45 = & V_45 ;
V_46 . V_73 = - 1 ;
V_46 . V_74 = V_75 ;
V_46 . V_76 = 0 ;
V_46 . V_77 = V_131 ;
V_46 . V_33 = 0 ;
if ( ( V_56 = F_19 ( V_15 , & V_46 ) ) != 0 )
return V_56 ;
if ( V_45 . V_68 == 0 )
return - V_120 ;
V_174:
if ( V_15 -> V_166 . V_167 [ V_131 ] . V_168 == NULL ) {
V_50 = V_45 . V_68 * 4 ;
if ( V_50 < sizeof( T_13 ) )
V_50 = sizeof( T_13 ) ;
V_172 = ( T_13 * ) F_20 ( V_15 -> V_78 ,
V_50 ,
& V_173 ) ;
if ( ! V_172 )
return - V_57 ;
}
else {
V_172 = V_15 -> V_166 . V_167 [ V_131 ] . V_168 ;
V_173 = V_15 -> V_166 . V_167 [ V_131 ] . V_170 ;
V_50 = V_15 -> V_166 . V_167 [ V_131 ] . V_169 ;
if ( V_45 . V_68 * 4 > V_50 ) {
V_15 -> V_166 . V_167 [ V_131 ] . V_168 = NULL ;
F_23 ( V_15 -> V_78 , V_50 , ( V_87 * )
V_172 , V_173 ) ;
goto V_174;
}
}
memset ( V_172 , 0 , V_50 ) ;
V_46 . V_73 = V_173 ;
V_46 . V_74 = V_79 ;
if ( ( V_56 = F_19 ( V_15 , & V_46 ) ) == 0 ) {
V_15 -> V_166 . V_167 [ V_131 ] . V_168 = V_172 ;
V_15 -> V_166 . V_167 [ V_131 ] . V_169 = V_50 ;
V_15 -> V_166 . V_167 [ V_131 ] . V_170 = V_173 ;
}
else {
V_15 -> V_166 . V_167 [ V_131 ] . V_168 = NULL ;
F_23 ( V_15 -> V_78 , V_50 , ( V_87 * )
V_172 , V_173 ) ;
}
return V_56 ;
}
static void
F_46 ( T_2 * V_15 )
{
int V_51 ;
T_13 * V_175 ;
#define F_47 (1)
#define F_48 (1)
#define F_49 (MPI_FCPORTPAGE1_FLAGS_IMMEDIATE_ERROR_REPLY)
#define F_50 (MPI_FCPORTPAGE1_FLAGS_VERBOSE_RESCAN_EVENTS)
for ( V_51 = 0 ; V_51 < V_15 -> V_61 . V_176 ; V_51 ++ ) {
if ( F_45 ( V_15 , V_51 ) != 0 )
continue;
V_175 = V_15 -> V_166 . V_167 [ V_51 ] . V_168 ;
if ( ( V_175 -> V_177 == F_47 )
&& ( V_175 -> V_178 == F_48 )
&& ( ( V_175 -> V_91 & F_49 ) == F_49 )
&& ( ( V_175 -> V_91 & F_50 ) == 0 ) )
continue;
V_175 -> V_177 = F_47 ;
V_175 -> V_178 = F_48 ;
V_175 -> V_91 &= ~ F_50 ;
V_175 -> V_91 |= F_49 ;
F_44 ( V_15 , V_51 ) ;
}
}
static void
F_51 ( T_2 * V_15 , int V_131 )
{
unsigned V_179 = 0 ;
unsigned cos = 0 ;
unsigned V_180 ;
unsigned V_181 ;
unsigned V_182 ;
T_12 * V_183 ;
struct V_8 * V_22 ;
char * V_184 ;
if ( V_131 != 0 )
return;
V_183 = & V_15 -> V_153 [ V_131 ] ;
V_22 = V_15 -> V_22 ;
V_184 = F_52 ( V_22 ) ;
snprintf ( V_184 , V_185 , L_19 ,
V_15 -> V_186 ,
V_187 ,
V_15 -> V_61 . V_188 . V_189 ) ;
F_53 ( V_22 ) = V_190 ;
F_54 ( V_22 ) = V_183 -> V_156 ;
F_55 ( V_22 ) =
( V_98 ) V_183 -> V_81 . V_83 << 32 | ( V_98 ) V_183 -> V_81 . V_82 ;
F_56 ( V_22 ) =
( V_98 ) V_183 -> V_84 . V_83 << 32 | ( V_98 ) V_183 -> V_84 . V_82 ;
F_57 ( V_22 ) = V_183 -> V_80 ;
V_179 = V_183 -> V_154 ;
if ( V_179 & V_191 )
cos |= V_192 ;
if ( V_179 & V_193 )
cos |= V_194 ;
if ( V_179 & V_195 )
cos |= V_196 ;
F_58 ( V_22 ) = cos ;
if ( V_183 -> V_139 == V_143 )
V_180 = V_197 ;
else if ( V_183 -> V_139 == V_144 )
V_180 = V_198 ;
else if ( V_183 -> V_139 == V_145 )
V_180 = V_199 ;
else if ( V_183 -> V_139 == V_200 )
V_180 = V_201 ;
else
V_180 = V_202 ;
F_59 ( V_22 ) = V_180 ;
V_180 = 0 ;
if ( V_183 -> V_155 & V_203 )
V_180 |= V_197 ;
if ( V_183 -> V_155 & V_204 )
V_180 |= V_198 ;
if ( V_183 -> V_155 & V_205 )
V_180 |= V_199 ;
if ( V_183 -> V_155 & V_206 )
V_180 |= V_201 ;
F_60 ( V_22 ) = V_180 ;
V_182 = V_207 ;
if ( V_183 -> V_140 == V_162 )
V_182 = V_208 ;
else if ( V_183 -> V_140 == V_141 )
V_182 = V_209 ;
F_61 ( V_22 ) = V_182 ;
V_181 = V_210 ;
if ( V_183 -> V_91 & V_211 )
V_181 = V_212 ;
else if ( V_183 -> V_91 & V_213 )
V_181 = V_214 ;
else if ( V_183 -> V_91 & V_215 )
V_181 = V_216 ;
else if ( V_183 -> V_91 & V_217 )
V_181 = V_218 ;
F_62 ( V_22 ) = V_181 ;
F_63 ( V_22 ) =
( V_183 -> V_91 & V_219 ) ?
( V_98 ) V_183 -> V_157 . V_83 << 32 | ( V_98 ) V_183 -> V_158 . V_82 :
( V_98 ) V_183 -> V_81 . V_83 << 32 | ( V_98 ) V_183 -> V_81 . V_82 ;
}
static void
F_64 ( struct V_220 * V_221 )
{
T_2 * V_15 =
F_65 ( V_221 , T_2 , V_222 ) ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_15 -> V_61 . V_176 ; V_51 ++ )
( void ) F_42 ( V_15 , V_51 ) ;
}
static void
F_66 ( struct V_220 * V_221 )
{
T_2 * V_15 =
F_65 ( V_221 , T_2 , V_223 ) ;
V_98 V_106 ;
struct V_103 * V_104 ;
struct F_4 * V_116 ;
T_9 * V_108 ;
F_28 (ri, &ioc->fc_rports, list) {
if ( V_104 -> V_13 & V_115 ) {
V_104 -> V_13 &= ~ V_115 ;
F_67 ( V_104 -> V_12 ) ;
V_104 -> V_12 = NULL ;
V_116 = V_104 -> V_116 ;
if ( V_116 ) {
V_108 = V_116 -> V_27 ;
if ( V_108 )
V_108 -> V_117 = 1 ;
}
V_106 = ( V_98 ) V_104 -> V_88 . V_84 . V_83 << 32 |
( V_98 ) V_104 -> V_88 . V_84 . V_82 ;
F_9 ( V_15 , F_10 ( V_20
L_20 ,
V_15 -> V_21 ,
V_15 -> V_22 -> V_23 ,
( unsigned long long ) V_106 ) ) ;
}
}
}
static void
F_68 ( struct V_220 * V_221 )
{
T_2 * V_15 =
F_65 ( V_221 , T_2 , V_222 ) ;
int V_51 ;
V_98 V_106 ;
struct V_103 * V_104 ;
struct F_4 * V_116 ;
T_9 * V_108 ;
F_28 (ri, &ioc->fc_rports, list) {
if ( V_104 -> V_13 & V_115 ) {
V_104 -> V_13 |= V_114 ;
}
}
for ( V_51 = 0 ; V_51 < V_15 -> V_61 . V_176 ; V_51 ++ ) {
( void ) F_42 ( V_15 , V_51 ) ;
F_51 ( V_15 , V_51 ) ;
F_17 ( V_15 , V_51 , F_27 ) ;
}
F_28 (ri, &ioc->fc_rports, list) {
if ( V_104 -> V_13 & V_114 ) {
V_104 -> V_13 &= ~ ( V_115 |
V_114 ) ;
F_67 ( V_104 -> V_12 ) ;
V_104 -> V_12 = NULL ;
V_116 = V_104 -> V_116 ;
if ( V_116 ) {
V_108 = V_116 -> V_27 ;
if ( V_108 )
V_108 -> V_117 = 1 ;
}
V_106 = ( V_98 ) V_104 -> V_88 . V_84 . V_83 << 32 |
( V_98 ) V_104 -> V_88 . V_84 . V_82 ;
F_9 ( V_15 , F_10 ( V_20
L_21 ,
V_15 -> V_21 ,
V_15 -> V_22 -> V_23 ,
( unsigned long long ) V_106 ) ) ;
}
}
}
static int
F_69 ( struct V_224 * V_225 , const struct V_226 * V_24 )
{
struct V_8 * V_22 ;
T_1 * V_4 ;
T_2 * V_15 ;
unsigned long V_13 ;
int V_51 ;
int V_227 = 0 ;
int V_228 ;
int V_229 ;
int error = 0 ;
int V_230 ;
if ( ( V_230 = F_70 ( V_225 , V_24 ) ) != 0 )
return V_230 ;
V_15 = F_71 ( V_225 ) ;
V_15 -> V_231 = V_232 ;
V_15 -> V_233 = V_234 ;
V_15 -> V_235 = V_236 ;
if ( V_15 -> V_237 != V_238 ) {
F_10 ( V_147
L_22 ,
V_15 -> V_21 ) ;
error = - V_120 ;
goto V_239;
}
if ( ! V_15 -> V_19 ) {
F_10 ( V_147 L_23 ,
V_15 -> V_21 ) ;
error = - V_120 ;
goto V_239;
}
V_229 = 0 ;
for ( V_51 = 0 ; V_51 < V_15 -> V_61 . V_176 ; V_51 ++ ) {
if ( V_15 -> V_240 [ V_51 ] . V_241 &
V_242 )
V_229 ++ ;
}
if ( ! V_229 ) {
F_10 ( V_147
L_24 ,
V_15 -> V_21 , V_15 ) ;
return 0 ;
}
V_22 = F_72 ( & V_243 , sizeof( T_1 ) ) ;
if ( ! V_22 ) {
F_10 ( V_147
L_25 ,
V_15 -> V_21 ) ;
error = - 1 ;
goto V_239;
}
F_73 ( & V_15 -> V_244 ) ;
F_74 ( & V_15 -> V_222 , F_68 ) ;
F_74 ( & V_15 -> V_223 , F_66 ) ;
F_74 ( & V_15 -> V_245 , F_64 ) ;
F_6 ( & V_15 -> V_246 , V_13 ) ;
V_15 -> V_22 = V_22 ;
V_22 -> V_247 = 0 ;
V_22 -> V_248 = 0 ;
V_22 -> V_249 = 0 ;
V_22 -> V_250 = 16 ;
V_22 -> V_251 = V_15 -> V_240 -> V_64 ;
V_22 -> V_252 = V_252 ;
V_22 -> V_253 = V_15 -> V_24 ;
V_228 = V_15 -> V_254 / V_15 -> V_255 ;
if ( V_15 -> V_256 == sizeof( V_98 ) ) {
V_227 = ( V_228 - 1 ) *
( V_15 -> V_61 . V_257 - 1 ) + V_228 +
( V_15 -> V_254 - 60 ) / V_15 -> V_255 ;
} else {
V_227 = 1 + ( V_228 - 1 ) *
( V_15 -> V_61 . V_257 - 1 ) + V_228 +
( V_15 -> V_254 - 64 ) / V_15 -> V_255 ;
}
if ( V_227 < V_22 -> V_258 ) {
F_75 ( V_15 , F_10 ( V_20
L_26 ,
V_15 -> V_21 , V_227 , V_22 -> V_258 ) ) ;
V_22 -> V_258 = V_227 ;
}
F_8 ( & V_15 -> V_246 , V_13 ) ;
V_4 = F_5 ( V_22 ) ;
V_4 -> V_15 = V_15 ;
V_15 -> V_259 = F_76 ( V_15 -> V_260 , sizeof( void * ) , V_261 ) ;
if ( ! V_15 -> V_259 ) {
error = - V_57 ;
goto V_239;
}
F_73 ( & V_15 -> V_262 ) ;
F_75 ( V_15 , F_10 ( V_20 L_27 ,
V_15 -> V_21 , V_15 -> V_259 ) ) ;
V_4 -> V_263 = 0 ;
V_22 -> V_264 = V_265 ;
error = F_77 ( V_22 , & V_15 -> V_78 -> V_266 ) ;
if( error ) {
F_75 ( V_15 , F_10 ( V_124
L_28 , V_15 -> V_21 ) ) ;
goto V_239;
}
snprintf ( V_15 -> V_267 , sizeof( V_15 -> V_267 ) ,
L_29 , V_22 -> V_23 ) ;
V_15 -> V_268 =
F_78 ( V_15 -> V_267 ,
V_269 ) ;
if ( ! V_15 -> V_268 ) {
error = - V_57 ;
goto V_270;
}
for ( V_51 = 0 ; V_51 < V_15 -> V_61 . V_176 ; V_51 ++ ) {
( void ) F_42 ( V_15 , V_51 ) ;
}
F_46 ( V_15 ) ;
F_79 ( V_15 -> V_268 , & V_15 -> V_222 ) ;
F_80 ( V_15 -> V_268 ) ;
return 0 ;
V_270:
F_81 ( V_22 ) ;
V_239:
F_82 ( V_225 ) ;
return error ;
}
static int
F_83 ( T_2 * V_15 , T_14 * V_271 )
{
T_1 * V_4 ;
V_87 V_272 = F_21 ( V_271 -> V_273 ) & 0xFF ;
unsigned long V_13 ;
int V_56 = 1 ;
if ( V_15 -> V_274 != V_275 )
return 0 ;
F_84 ( V_15 , F_10 ( V_20 L_30 ,
V_15 -> V_21 , V_272 ) ) ;
if ( V_15 -> V_22 == NULL ||
( ( V_4 = F_5 ( V_15 -> V_22 ) ) == NULL ) )
return 1 ;
switch ( V_272 ) {
case V_276 :
F_6 ( & V_15 -> V_244 , V_13 ) ;
if ( V_15 -> V_268 ) {
F_79 ( V_15 -> V_268 ,
& V_15 -> V_222 ) ;
}
F_8 ( & V_15 -> V_244 , V_13 ) ;
break;
case V_277 :
F_6 ( & V_15 -> V_244 , V_13 ) ;
if ( V_15 -> V_268 ) {
F_79 ( V_15 -> V_268 ,
& V_15 -> V_245 ) ;
}
F_8 ( & V_15 -> V_244 , V_13 ) ;
break;
default:
V_56 = F_85 ( V_15 , V_271 ) ;
break;
}
return V_56 ;
}
static int
F_86 ( T_2 * V_15 , int V_278 )
{
int V_56 ;
unsigned long V_13 ;
V_56 = F_87 ( V_15 , V_278 ) ;
if ( ( V_15 -> V_274 != V_275 ) || ( ! V_56 ) )
return V_56 ;
F_88 ( V_15 , F_10 ( V_20
L_31 , V_15 -> V_21 ,
V_278 == V_279 ? L_32 : (
V_278 == V_280 ? L_33 : L_34 ) ) ) ;
if ( V_278 == V_279 ) {
F_6 ( & V_15 -> V_244 , V_13 ) ;
if ( V_15 -> V_268 ) {
F_79 ( V_15 -> V_268 ,
& V_15 -> V_223 ) ;
}
F_8 ( & V_15 -> V_244 , V_13 ) ;
}
else if ( V_278 == V_280 ) {
}
else {
F_46 ( V_15 ) ;
F_6 ( & V_15 -> V_244 , V_13 ) ;
if ( V_15 -> V_268 ) {
F_79 ( V_15 -> V_268 ,
& V_15 -> V_222 ) ;
}
F_8 ( & V_15 -> V_244 , V_13 ) ;
}
return 1 ;
}
static int T_15
F_89 ( void )
{
int error ;
F_90 ( V_281 , V_282 ) ;
if ( V_35 <= 0 )
V_35 = V_283 ;
V_265 =
F_91 ( & V_284 ) ;
if ( ! V_265 )
return - V_120 ;
V_232 = F_92 ( V_285 , V_286 ,
L_35 ) ;
V_234 = F_92 ( V_287 , V_286 ,
L_35 ) ;
V_236 = F_92 ( V_288 , V_286 ,
L_35 ) ;
F_93 ( V_232 , F_83 ) ;
F_94 ( V_232 , F_86 ) ;
error = F_95 ( & V_289 ) ;
if ( error )
F_96 ( V_265 ) ;
return error ;
}
static void F_97 ( struct V_224 * V_225 )
{
T_2 * V_15 = F_71 ( V_225 ) ;
struct V_103 * V_290 , * V_291 ;
struct V_292 * V_293 ;
unsigned long V_13 ;
int V_51 ;
if ( ( V_293 = V_15 -> V_268 ) ) {
F_6 ( & V_15 -> V_244 , V_13 ) ;
V_15 -> V_268 = NULL ;
F_8 ( & V_15 -> V_244 , V_13 ) ;
F_98 ( V_293 ) ;
}
F_99 ( V_15 -> V_22 ) ;
F_100 (p, n, &ioc->fc_rports, list) {
F_33 ( & V_290 -> V_112 ) ;
F_25 ( V_290 ) ;
}
for ( V_51 = 0 ; V_51 < V_15 -> V_61 . V_176 ; V_51 ++ ) {
if ( V_15 -> V_166 . V_167 [ V_51 ] . V_168 ) {
F_23 ( V_15 -> V_78 ,
V_15 -> V_166 . V_167 [ V_51 ] . V_169 ,
( V_87 * ) V_15 -> V_166 . V_167 [ V_51 ] . V_168 ,
V_15 -> V_166 . V_167 [ V_51 ] . V_170 ) ;
V_15 -> V_166 . V_167 [ V_51 ] . V_168 = NULL ;
}
}
F_81 ( V_15 -> V_22 ) ;
F_82 ( V_225 ) ;
}
static void T_16
F_101 ( void )
{
F_102 ( & V_289 ) ;
F_96 ( V_265 ) ;
F_103 ( V_232 ) ;
F_104 ( V_232 ) ;
F_105 ( V_236 ) ;
F_105 ( V_234 ) ;
F_105 ( V_232 ) ;
}
