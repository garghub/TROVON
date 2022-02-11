static inline int F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
return 0 ;
case V_5 :
return - V_6 ;
default:
return - V_7 ;
}
}
static int F_2 ( struct V_8 * V_9 ,
struct V_1 * V_2 ,
struct V_10 * V_11 ,
bool V_12 )
{
struct V_10 V_13 , V_3 , V_14 , V_15 , V_16 , * V_17 [ 6 ] ;
unsigned int V_18 = 0 , V_19 = 0 ;
int type = V_2 -> V_20 . type & ~ V_21 ;
F_3 ( & V_13 , & V_2 -> V_20 , sizeof( V_2 -> V_20 ) ) ;
V_17 [ V_18 ++ ] = & V_13 ;
if ( type == V_22 ) {
F_3 ( & V_14 , V_2 -> V_23 -> V_14 , V_2 -> V_23 -> V_24 ) ;
V_17 [ V_18 ++ ] = & V_14 ;
}
if ( V_12 ) {
if ( V_2 -> V_20 . type & V_21 )
V_17 [ V_18 ++ ] = V_11 ;
else
V_17 [ V_18 + V_19 ++ ] = V_11 ;
}
if ( type == V_22 ) {
F_3 ( & V_15 , V_2 -> V_23 -> V_15 , V_25 ) ;
V_17 [ V_18 + V_19 ++ ] = & V_15 ;
F_3 ( & V_16 , & V_2 -> V_26 , sizeof( V_2 -> V_26 ) ) ;
V_17 [ V_18 + V_19 ++ ] = & V_16 ;
}
F_3 ( & V_3 , & V_2 -> V_3 , sizeof( V_2 -> V_3 ) ) ;
V_17 [ V_18 + V_19 ++ ] = & V_3 ;
return F_4 ( V_9 , V_17 , V_18 , V_19 , V_2 , V_27 ) ;
}
static inline void F_5 ( struct V_28 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_29 ;
int error = F_1 ( V_2 ) ;
if ( V_23 -> V_30 == V_31 ) {
V_23 -> V_32 = V_2 -> V_26 . V_33 ;
V_23 -> V_34 = V_2 -> V_26 . V_34 ;
V_23 -> V_35 = V_2 -> V_26 . V_35 ;
} else if ( V_23 -> V_30 == V_36 ) {
V_23 -> V_35 = ( error != 0 ) ;
}
F_6 ( V_23 , error ) ;
}
static void F_7 ( struct V_8 * V_9 )
{
struct V_37 * V_38 = V_9 -> V_39 -> V_40 ;
bool V_41 = false ;
struct V_1 * V_2 ;
unsigned long V_42 ;
unsigned int V_43 ;
F_8 ( & V_38 -> V_44 , V_42 ) ;
do {
F_9 ( V_9 ) ;
while ( ( V_2 = F_10 ( V_38 -> V_9 , & V_43 ) ) != NULL ) {
F_11 ( V_2 -> V_23 ) ;
V_41 = true ;
}
if ( F_12 ( F_13 ( V_9 ) ) )
break;
} while ( ! F_14 ( V_9 ) );
if ( V_41 )
F_15 ( V_38 -> V_45 -> V_46 ) ;
F_16 ( & V_38 -> V_44 , V_42 ) ;
}
static int F_17 ( struct V_47 * V_48 , struct V_28 * V_23 )
{
struct V_37 * V_38 = V_48 -> V_46 -> V_49 ;
struct V_1 * V_2 = V_23 -> V_29 ;
unsigned long V_42 ;
unsigned int V_50 ;
const bool V_51 = ( V_23 -> V_52 & V_53 ) != 0 ;
int V_54 ;
F_18 ( V_23 -> V_55 + 2 > V_38 -> V_56 ) ;
V_2 -> V_23 = V_23 ;
if ( V_23 -> V_52 & V_57 ) {
V_2 -> V_20 . type = V_58 ;
V_2 -> V_20 . V_59 = 0 ;
V_2 -> V_20 . V_60 = F_19 ( V_2 -> V_23 ) ;
} else {
switch ( V_23 -> V_30 ) {
case V_61 :
V_2 -> V_20 . type = 0 ;
V_2 -> V_20 . V_59 = F_20 ( V_2 -> V_23 ) ;
V_2 -> V_20 . V_60 = F_19 ( V_2 -> V_23 ) ;
break;
case V_31 :
V_2 -> V_20 . type = V_22 ;
V_2 -> V_20 . V_59 = 0 ;
V_2 -> V_20 . V_60 = F_19 ( V_2 -> V_23 ) ;
break;
case V_36 :
V_2 -> V_20 . type = V_62 ;
V_2 -> V_20 . V_59 = 0 ;
V_2 -> V_20 . V_60 = F_19 ( V_2 -> V_23 ) ;
break;
default:
F_21 () ;
}
}
V_50 = F_22 ( V_48 -> V_46 , V_2 -> V_23 , V_2 -> V_63 ) ;
if ( V_50 ) {
if ( F_23 ( V_2 -> V_23 ) == V_64 )
V_2 -> V_20 . type |= V_21 ;
else
V_2 -> V_20 . type |= V_65 ;
}
F_8 ( & V_38 -> V_44 , V_42 ) ;
V_54 = F_2 ( V_38 -> V_9 , V_2 , V_2 -> V_63 , V_50 ) ;
if ( V_54 ) {
F_24 ( V_38 -> V_9 ) ;
F_25 ( V_48 ) ;
F_16 ( & V_38 -> V_44 , V_42 ) ;
if ( V_54 == - V_66 || V_54 == - V_67 )
return V_68 ;
return V_69 ;
}
if ( V_51 )
F_24 ( V_38 -> V_9 ) ;
F_16 ( & V_38 -> V_44 , V_42 ) ;
return V_70 ;
}
static int F_26 ( struct V_71 * V_45 , char * V_72 )
{
struct V_37 * V_38 = V_45 -> V_73 ;
struct V_28 * V_23 ;
struct V_74 * V_74 ;
int V_54 ;
V_74 = F_27 ( V_38 -> V_45 -> V_46 , V_72 , V_75 ,
V_76 ) ;
if ( F_28 ( V_74 ) )
return F_29 ( V_74 ) ;
V_23 = F_30 ( V_38 -> V_45 -> V_46 , V_74 , V_76 ) ;
if ( F_28 ( V_23 ) ) {
F_31 ( V_74 ) ;
return F_29 ( V_23 ) ;
}
V_23 -> V_30 = V_36 ;
V_54 = F_32 ( V_38 -> V_45 -> V_46 , V_38 -> V_45 , V_23 , false ) ;
F_33 ( V_23 ) ;
return V_54 ;
}
static int F_34 ( struct V_77 * V_78 , T_1 V_79 ,
unsigned int V_14 , unsigned long V_80 )
{
struct V_71 * V_45 = V_78 -> V_81 ;
struct V_37 * V_38 = V_45 -> V_73 ;
if ( ! F_35 ( V_38 -> V_39 , V_82 ) )
return - V_6 ;
return F_36 ( V_78 , V_79 , V_14 ,
( void V_83 * ) V_80 ) ;
}
static int F_37 ( struct V_77 * V_84 , struct V_85 * V_86 )
{
struct V_37 * V_38 = V_84 -> V_81 -> V_73 ;
if ( F_35 ( V_38 -> V_39 , V_87 ) ) {
F_38 ( V_38 -> V_39 , struct V_88 ,
V_89 . V_90 , & V_86 -> V_90 ) ;
F_38 ( V_38 -> V_39 , struct V_88 ,
V_89 . V_91 , & V_86 -> V_91 ) ;
F_38 ( V_38 -> V_39 , struct V_88 ,
V_89 . V_92 , & V_86 -> V_92 ) ;
} else {
V_86 -> V_91 = 1 << 6 ;
V_86 -> V_92 = 1 << 5 ;
V_86 -> V_90 = F_39 ( V_84 -> V_81 ) >> 11 ;
}
return 0 ;
}
static int F_40 ( int V_93 )
{
return V_93 << V_94 ;
}
static int F_41 ( int V_95 )
{
return V_95 >> V_94 ;
}
static T_2 F_42 ( struct V_96 * V_97 ,
struct V_98 * V_99 , char * V_100 )
{
struct V_71 * V_45 = F_43 ( V_97 ) ;
int V_54 ;
F_44 ( V_101 < V_75 ) ;
V_100 [ V_75 ] = '\0' ;
V_54 = F_26 ( V_45 , V_100 ) ;
if ( ! V_54 )
return strlen ( V_100 ) ;
if ( V_54 == - V_7 )
return 0 ;
return V_54 ;
}
static void F_45 ( struct V_102 * V_103 )
{
struct V_37 * V_38 =
F_46 ( V_103 , struct V_37 , V_104 ) ;
struct V_105 * V_39 = V_38 -> V_39 ;
struct V_106 * V_107 = V_38 -> V_45 -> V_46 ;
char V_108 [ 10 ] , V_109 [ 10 ] ;
char * V_110 [] = { L_1 , NULL } ;
T_3 V_111 , V_112 ;
F_47 ( & V_38 -> V_113 ) ;
if ( ! V_38 -> V_114 )
goto V_115;
F_38 ( V_39 , struct V_88 , V_111 , & V_111 ) ;
if ( ( V_116 ) V_111 != V_111 ) {
F_48 ( & V_39 -> V_97 , L_2 ,
( unsigned long long ) V_111 ) ;
V_111 = ( V_116 ) - 1 ;
}
V_112 = V_111 * F_49 ( V_107 ) ;
F_50 ( V_112 , V_117 , V_108 , sizeof( V_108 ) ) ;
F_50 ( V_112 , V_118 , V_109 , sizeof( V_109 ) ) ;
F_51 ( & V_39 -> V_97 ,
L_3 ,
( unsigned long long ) V_111 ,
F_49 ( V_107 ) ,
V_109 , V_108 ) ;
F_52 ( V_38 -> V_45 , V_111 ) ;
F_53 ( V_38 -> V_45 ) ;
F_54 ( & F_55 ( V_38 -> V_45 ) -> V_119 , V_120 , V_110 ) ;
V_115:
F_56 ( & V_38 -> V_113 ) ;
}
static void F_57 ( struct V_105 * V_39 )
{
struct V_37 * V_38 = V_39 -> V_40 ;
F_58 ( V_121 , & V_38 -> V_104 ) ;
}
static int F_59 ( struct V_37 * V_38 )
{
int V_54 = 0 ;
V_38 -> V_9 = F_60 ( V_38 -> V_39 , F_7 , L_4 ) ;
if ( F_28 ( V_38 -> V_9 ) )
V_54 = F_29 ( V_38 -> V_9 ) ;
return V_54 ;
}
static int F_61 ( char * V_122 , int V_93 , char * V_100 , int V_123 )
{
const int V_124 = 'z' - 'a' + 1 ;
char * V_125 = V_100 + strlen ( V_122 ) ;
char * V_126 = V_100 + V_123 ;
char * V_127 ;
int V_128 ;
V_127 = V_126 - 1 ;
* V_127 = '\0' ;
V_128 = V_124 ;
do {
if ( V_127 == V_125 )
return - V_129 ;
* -- V_127 = 'a' + ( V_93 % V_128 ) ;
V_93 = ( V_93 / V_128 ) - 1 ;
} while ( V_93 >= 0 );
memmove ( V_125 , V_127 , V_126 - V_127 ) ;
memcpy ( V_100 , V_122 , strlen ( V_122 ) ) ;
return 0 ;
}
static int F_62 ( struct V_105 * V_39 )
{
T_4 V_130 ;
int V_54 ;
V_54 = F_63 ( V_39 , V_131 ,
struct V_88 , V_132 ,
& V_130 ) ;
if ( V_54 )
V_130 = F_35 ( V_39 , V_133 ) ;
return V_130 ;
}
static void F_64 ( struct V_105 * V_39 )
{
T_4 V_130 = F_62 ( V_39 ) ;
struct V_37 * V_38 = V_39 -> V_40 ;
if ( V_130 )
F_65 ( V_38 -> V_45 -> V_46 , V_57 ) ;
else
F_65 ( V_38 -> V_45 -> V_46 , 0 ) ;
F_53 ( V_38 -> V_45 ) ;
}
static T_2
F_66 ( struct V_96 * V_97 , struct V_98 * V_99 ,
const char * V_100 , T_5 V_134 )
{
struct V_71 * V_45 = F_43 ( V_97 ) ;
struct V_37 * V_38 = V_45 -> V_73 ;
struct V_105 * V_39 = V_38 -> V_39 ;
int V_135 ;
F_18 ( ! F_35 ( V_38 -> V_39 , V_131 ) ) ;
for ( V_135 = F_67 ( V_136 ) ; -- V_135 >= 0 ; )
if ( F_68 ( V_100 , V_136 [ V_135 ] ) )
break;
if ( V_135 < 0 )
return - V_129 ;
F_69 ( V_39 , F_70 ( struct V_88 , V_132 ) , V_135 ) ;
F_64 ( V_39 ) ;
return V_134 ;
}
static T_2
F_71 ( struct V_96 * V_97 , struct V_98 * V_99 ,
char * V_100 )
{
struct V_71 * V_45 = F_43 ( V_97 ) ;
struct V_37 * V_38 = V_45 -> V_73 ;
T_4 V_130 = F_62 ( V_38 -> V_39 ) ;
F_18 ( V_130 >= F_67 ( V_136 ) ) ;
return snprintf ( V_100 , 40 , L_5 , V_136 [ V_130 ] ) ;
}
static int F_72 ( void * V_80 , struct V_47 * V_48 ,
struct V_28 * V_137 , unsigned int V_138 )
{
struct V_37 * V_38 = V_80 ;
struct V_1 * V_2 = V_137 -> V_29 ;
F_73 ( V_2 -> V_63 , V_38 -> V_56 ) ;
return 0 ;
}
static int F_74 ( struct V_105 * V_39 )
{
struct V_37 * V_38 ;
struct V_106 * V_107 ;
int V_54 , V_93 ;
T_3 V_139 ;
T_6 V_140 , V_141 , V_56 , V_142 ;
T_7 V_143 ;
T_4 V_144 , V_145 ;
V_54 = F_75 ( & V_146 , 0 , F_41 ( 1 << V_147 ) ,
V_76 ) ;
if ( V_54 < 0 )
goto V_148;
V_93 = V_54 ;
V_54 = F_63 ( V_39 , V_149 ,
struct V_88 , V_150 ,
& V_56 ) ;
if ( V_54 || ! V_56 )
V_56 = 1 ;
V_56 += 2 ;
V_39 -> V_40 = V_38 = F_76 ( sizeof( * V_38 ) , V_76 ) ;
if ( ! V_38 ) {
V_54 = - V_66 ;
goto V_151;
}
V_38 -> V_39 = V_39 ;
V_38 -> V_56 = V_56 ;
F_77 ( & V_38 -> V_113 ) ;
F_78 ( & V_38 -> V_104 , F_45 ) ;
V_38 -> V_114 = true ;
V_54 = F_59 ( V_38 ) ;
if ( V_54 )
goto V_152;
F_79 ( & V_38 -> V_44 ) ;
V_38 -> V_45 = F_80 ( 1 << V_94 ) ;
if ( ! V_38 -> V_45 ) {
V_54 = - V_66 ;
goto V_153;
}
if ( ! V_154 . V_155 ) {
V_154 . V_155 = V_38 -> V_9 -> V_156 ;
if ( ! F_35 ( V_39 , V_157 ) )
V_154 . V_155 /= 2 ;
}
V_154 . V_158 =
sizeof( struct V_1 ) +
sizeof( struct V_10 ) * V_56 ;
V_107 = V_38 -> V_45 -> V_46 = F_81 ( & V_154 , V_38 ) ;
if ( ! V_107 ) {
V_54 = - V_66 ;
goto V_159;
}
F_82 ( V_107 , F_72 , V_38 ) ;
V_107 -> V_49 = V_38 ;
F_61 ( L_6 , V_93 , V_38 -> V_45 -> V_160 , V_161 ) ;
V_38 -> V_45 -> V_162 = V_162 ;
V_38 -> V_45 -> V_163 = F_40 ( V_93 ) ;
V_38 -> V_45 -> V_73 = V_38 ;
V_38 -> V_45 -> V_164 = & V_165 ;
V_38 -> V_45 -> V_166 = & V_39 -> V_97 ;
V_38 -> V_93 = V_93 ;
F_64 ( V_39 ) ;
if ( F_35 ( V_39 , V_167 ) )
F_83 ( V_38 -> V_45 , 1 ) ;
F_38 ( V_39 , struct V_88 , V_111 , & V_139 ) ;
if ( ( V_116 ) V_139 != V_139 ) {
F_48 ( & V_39 -> V_97 , L_2 ,
( unsigned long long ) V_139 ) ;
V_139 = ( V_116 ) - 1 ;
}
F_52 ( V_38 -> V_45 , V_139 ) ;
F_84 ( V_107 , V_38 -> V_56 - 2 ) ;
F_85 ( V_107 , V_168 ) ;
F_86 ( V_107 , - 1U ) ;
V_54 = F_63 ( V_39 , V_169 ,
struct V_88 , V_170 , & V_140 ) ;
if ( ! V_54 )
F_87 ( V_107 , V_140 ) ;
else
F_87 ( V_107 , - 1U ) ;
V_54 = F_63 ( V_39 , V_171 ,
struct V_88 , V_141 ,
& V_141 ) ;
if ( ! V_54 )
F_88 ( V_107 , V_141 ) ;
else
V_141 = F_49 ( V_107 ) ;
V_54 = F_63 ( V_39 , V_172 ,
struct V_88 , V_144 ,
& V_144 ) ;
if ( ! V_54 && V_144 )
F_89 ( V_107 ,
V_141 * ( 1 << V_144 ) ) ;
V_54 = F_63 ( V_39 , V_172 ,
struct V_88 , V_145 ,
& V_145 ) ;
if ( ! V_54 && V_145 )
F_90 ( V_107 , V_141 * V_145 ) ;
V_54 = F_63 ( V_39 , V_172 ,
struct V_88 , V_143 ,
& V_143 ) ;
if ( ! V_54 && V_143 )
F_91 ( V_107 , V_141 * V_143 ) ;
V_54 = F_63 ( V_39 , V_172 ,
struct V_88 , V_142 ,
& V_142 ) ;
if ( ! V_54 && V_142 )
F_92 ( V_107 , V_141 * V_142 ) ;
F_93 ( V_38 -> V_45 ) ;
V_54 = F_94 ( F_55 ( V_38 -> V_45 ) , & V_173 ) ;
if ( V_54 )
goto V_174;
if ( F_35 ( V_39 , V_131 ) )
V_54 = F_94 ( F_55 ( V_38 -> V_45 ) ,
& V_175 ) ;
else
V_54 = F_94 ( F_55 ( V_38 -> V_45 ) ,
& V_176 ) ;
if ( V_54 )
goto V_174;
return 0 ;
V_174:
F_95 ( V_38 -> V_45 ) ;
F_96 ( V_38 -> V_45 -> V_46 ) ;
V_159:
F_97 ( V_38 -> V_45 ) ;
V_153:
V_39 -> V_177 -> V_178 ( V_39 ) ;
V_152:
F_98 ( V_38 ) ;
V_151:
F_99 ( & V_146 , V_93 ) ;
V_148:
return V_54 ;
}
static void F_100 ( struct V_105 * V_39 )
{
struct V_37 * V_38 = V_39 -> V_40 ;
int V_93 = V_38 -> V_93 ;
int V_179 ;
F_47 ( & V_38 -> V_113 ) ;
V_38 -> V_114 = false ;
F_56 ( & V_38 -> V_113 ) ;
F_95 ( V_38 -> V_45 ) ;
F_96 ( V_38 -> V_45 -> V_46 ) ;
V_39 -> V_177 -> V_180 ( V_39 ) ;
F_101 ( & V_38 -> V_104 ) ;
V_179 = F_102 ( & F_55 ( V_38 -> V_45 ) -> V_119 . V_181 . V_182 ) ;
F_97 ( V_38 -> V_45 ) ;
V_39 -> V_177 -> V_178 ( V_39 ) ;
F_98 ( V_38 ) ;
if ( V_179 == 1 )
F_99 ( & V_146 , V_93 ) ;
}
static int F_103 ( struct V_105 * V_39 )
{
struct V_37 * V_38 = V_39 -> V_40 ;
V_39 -> V_177 -> V_180 ( V_39 ) ;
F_47 ( & V_38 -> V_113 ) ;
V_38 -> V_114 = false ;
F_56 ( & V_38 -> V_113 ) ;
F_101 ( & V_38 -> V_104 ) ;
F_104 ( V_38 -> V_45 -> V_46 ) ;
V_39 -> V_177 -> V_178 ( V_39 ) ;
return 0 ;
}
static int F_105 ( struct V_105 * V_39 )
{
struct V_37 * V_38 = V_39 -> V_40 ;
int V_183 ;
V_38 -> V_114 = true ;
V_183 = F_59 ( V_39 -> V_40 ) ;
if ( ! V_183 )
F_15 ( V_38 -> V_45 -> V_46 ) ;
return V_183 ;
}
static int T_8 F_106 ( void )
{
int error ;
V_121 = F_107 ( L_7 , 0 , 0 ) ;
if ( ! V_121 )
return - V_66 ;
V_162 = F_108 ( 0 , L_8 ) ;
if ( V_162 < 0 ) {
error = V_162 ;
goto V_184;
}
error = F_109 ( & V_37 ) ;
if ( error )
goto V_185;
return 0 ;
V_185:
F_110 ( V_162 , L_8 ) ;
V_184:
F_111 ( V_121 ) ;
return error ;
}
static void T_9 F_112 ( void )
{
F_110 ( V_162 , L_8 ) ;
F_113 ( & V_37 ) ;
F_111 ( V_121 ) ;
}
