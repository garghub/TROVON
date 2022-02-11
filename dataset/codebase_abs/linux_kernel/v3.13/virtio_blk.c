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
static inline void F_5 ( struct V_1 * V_2 )
{
struct V_28 * V_23 = V_2 -> V_23 ;
int error = F_1 ( V_2 ) ;
if ( V_23 -> V_29 == V_30 ) {
V_23 -> V_31 = V_2 -> V_26 . V_32 ;
V_23 -> V_33 = V_2 -> V_26 . V_33 ;
V_23 -> V_34 = V_2 -> V_26 . V_34 ;
} else if ( V_23 -> V_29 == V_35 ) {
V_23 -> V_34 = ( error != 0 ) ;
}
F_6 ( V_23 , error ) ;
}
static void F_7 ( struct V_8 * V_9 )
{
struct V_36 * V_37 = V_9 -> V_38 -> V_39 ;
bool V_40 = false ;
struct V_1 * V_2 ;
unsigned long V_41 ;
unsigned int V_42 ;
F_8 ( & V_37 -> V_43 , V_41 ) ;
do {
F_9 ( V_9 ) ;
while ( ( V_2 = F_10 ( V_37 -> V_9 , & V_42 ) ) != NULL ) {
F_5 ( V_2 ) ;
V_40 = true ;
}
if ( F_11 ( F_12 ( V_9 ) ) )
break;
} while ( ! F_13 ( V_9 ) );
F_14 ( & V_37 -> V_43 , V_41 ) ;
if ( V_40 )
F_15 ( V_37 -> V_44 -> V_45 ) ;
}
static int F_16 ( struct V_46 * V_47 , struct V_28 * V_23 )
{
struct V_36 * V_37 = V_47 -> V_45 -> V_48 ;
struct V_1 * V_2 = V_23 -> V_49 ;
unsigned long V_41 ;
unsigned int V_50 ;
const bool V_51 = ( V_23 -> V_52 & V_53 ) != 0 ;
F_17 ( V_23 -> V_54 + 2 > V_37 -> V_55 ) ;
V_2 -> V_23 = V_23 ;
if ( V_23 -> V_52 & V_56 ) {
V_2 -> V_20 . type = V_57 ;
V_2 -> V_20 . V_58 = 0 ;
V_2 -> V_20 . V_59 = F_18 ( V_2 -> V_23 ) ;
} else {
switch ( V_23 -> V_29 ) {
case V_60 :
V_2 -> V_20 . type = 0 ;
V_2 -> V_20 . V_58 = F_19 ( V_2 -> V_23 ) ;
V_2 -> V_20 . V_59 = F_18 ( V_2 -> V_23 ) ;
break;
case V_30 :
V_2 -> V_20 . type = V_22 ;
V_2 -> V_20 . V_58 = 0 ;
V_2 -> V_20 . V_59 = F_18 ( V_2 -> V_23 ) ;
break;
case V_35 :
V_2 -> V_20 . type = V_61 ;
V_2 -> V_20 . V_58 = 0 ;
V_2 -> V_20 . V_59 = F_18 ( V_2 -> V_23 ) ;
break;
default:
F_20 () ;
}
}
V_50 = F_21 ( V_47 -> V_45 , V_2 -> V_23 , V_2 -> V_62 ) ;
if ( V_50 ) {
if ( F_22 ( V_2 -> V_23 ) == V_63 )
V_2 -> V_20 . type |= V_21 ;
else
V_2 -> V_20 . type |= V_64 ;
}
F_8 ( & V_37 -> V_43 , V_41 ) ;
if ( F_2 ( V_37 -> V_9 , V_2 , V_2 -> V_62 , V_50 ) < 0 ) {
F_23 ( V_37 -> V_9 ) ;
F_14 ( & V_37 -> V_43 , V_41 ) ;
F_24 ( V_47 ) ;
return V_65 ;
}
if ( V_51 )
F_23 ( V_37 -> V_9 ) ;
F_14 ( & V_37 -> V_43 , V_41 ) ;
return V_66 ;
}
static int F_25 ( struct V_67 * V_44 , char * V_68 )
{
struct V_36 * V_37 = V_44 -> V_69 ;
struct V_28 * V_23 ;
struct V_70 * V_70 ;
int V_71 ;
V_70 = F_26 ( V_37 -> V_44 -> V_45 , V_68 , V_72 ,
V_73 ) ;
if ( F_27 ( V_70 ) )
return F_28 ( V_70 ) ;
V_23 = F_29 ( V_37 -> V_44 -> V_45 , V_70 , V_73 ) ;
if ( F_27 ( V_23 ) ) {
F_30 ( V_70 ) ;
return F_28 ( V_23 ) ;
}
V_23 -> V_29 = V_35 ;
V_71 = F_31 ( V_37 -> V_44 -> V_45 , V_37 -> V_44 , V_23 , false ) ;
F_32 ( V_23 ) ;
return V_71 ;
}
static int F_33 ( struct V_74 * V_75 , T_1 V_76 ,
unsigned int V_14 , unsigned long V_77 )
{
struct V_67 * V_44 = V_75 -> V_78 ;
struct V_36 * V_37 = V_44 -> V_69 ;
if ( ! F_34 ( V_37 -> V_38 , V_79 ) )
return - V_6 ;
return F_35 ( V_75 , V_76 , V_14 ,
( void V_80 * ) V_77 ) ;
}
static int F_36 ( struct V_74 * V_81 , struct V_82 * V_83 )
{
struct V_36 * V_37 = V_81 -> V_78 -> V_69 ;
if ( F_34 ( V_37 -> V_38 , V_84 ) ) {
F_37 ( V_37 -> V_38 , struct V_85 ,
V_86 . V_87 , & V_83 -> V_87 ) ;
F_37 ( V_37 -> V_38 , struct V_85 ,
V_86 . V_88 , & V_83 -> V_88 ) ;
F_37 ( V_37 -> V_38 , struct V_85 ,
V_86 . V_89 , & V_83 -> V_89 ) ;
} else {
V_83 -> V_88 = 1 << 6 ;
V_83 -> V_89 = 1 << 5 ;
V_83 -> V_87 = F_38 ( V_81 -> V_78 ) >> 11 ;
}
return 0 ;
}
static int F_39 ( int V_90 )
{
return V_90 << V_91 ;
}
static int F_40 ( int V_92 )
{
return V_92 >> V_91 ;
}
static T_2 F_41 ( struct V_93 * V_94 ,
struct V_95 * V_96 , char * V_97 )
{
struct V_67 * V_44 = F_42 ( V_94 ) ;
int V_71 ;
F_43 ( V_98 < V_72 ) ;
V_97 [ V_72 ] = '\0' ;
V_71 = F_25 ( V_44 , V_97 ) ;
if ( ! V_71 )
return strlen ( V_97 ) ;
if ( V_71 == - V_7 )
return 0 ;
return V_71 ;
}
static void F_44 ( struct V_99 * V_100 )
{
struct V_36 * V_37 =
F_45 ( V_100 , struct V_36 , V_101 ) ;
struct V_102 * V_38 = V_37 -> V_38 ;
struct V_103 * V_104 = V_37 -> V_44 -> V_45 ;
char V_105 [ 10 ] , V_106 [ 10 ] ;
char * V_107 [] = { L_1 , NULL } ;
T_3 V_108 , V_109 ;
F_46 ( & V_37 -> V_110 ) ;
if ( ! V_37 -> V_111 )
goto V_112;
F_37 ( V_38 , struct V_85 , V_108 , & V_108 ) ;
if ( ( V_113 ) V_108 != V_108 ) {
F_47 ( & V_38 -> V_94 , L_2 ,
( unsigned long long ) V_108 ) ;
V_108 = ( V_113 ) - 1 ;
}
V_109 = V_108 * F_48 ( V_104 ) ;
F_49 ( V_109 , V_114 , V_105 , sizeof( V_105 ) ) ;
F_49 ( V_109 , V_115 , V_106 , sizeof( V_106 ) ) ;
F_50 ( & V_38 -> V_94 ,
L_3 ,
( unsigned long long ) V_108 ,
F_48 ( V_104 ) ,
V_106 , V_105 ) ;
F_51 ( V_37 -> V_44 , V_108 ) ;
F_52 ( V_37 -> V_44 ) ;
F_53 ( & F_54 ( V_37 -> V_44 ) -> V_116 , V_117 , V_107 ) ;
V_112:
F_55 ( & V_37 -> V_110 ) ;
}
static void F_56 ( struct V_102 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
F_57 ( V_118 , & V_37 -> V_101 ) ;
}
static int F_58 ( struct V_36 * V_37 )
{
int V_71 = 0 ;
V_37 -> V_9 = F_59 ( V_37 -> V_38 , F_7 , L_4 ) ;
if ( F_27 ( V_37 -> V_9 ) )
V_71 = F_28 ( V_37 -> V_9 ) ;
return V_71 ;
}
static int F_60 ( char * V_119 , int V_90 , char * V_97 , int V_120 )
{
const int V_121 = 'z' - 'a' + 1 ;
char * V_122 = V_97 + strlen ( V_119 ) ;
char * V_123 = V_97 + V_120 ;
char * V_124 ;
int V_125 ;
V_124 = V_123 - 1 ;
* V_124 = '\0' ;
V_125 = V_121 ;
do {
if ( V_124 == V_122 )
return - V_126 ;
* -- V_124 = 'a' + ( V_90 % V_125 ) ;
V_90 = ( V_90 / V_125 ) - 1 ;
} while ( V_90 >= 0 );
memmove ( V_122 , V_124 , V_123 - V_124 ) ;
memcpy ( V_97 , V_119 , strlen ( V_119 ) ) ;
return 0 ;
}
static int F_61 ( struct V_102 * V_38 )
{
T_4 V_127 ;
int V_71 ;
V_71 = F_62 ( V_38 , V_128 ,
struct V_85 , V_129 ,
& V_127 ) ;
if ( V_71 )
V_127 = F_34 ( V_38 , V_130 ) ;
return V_127 ;
}
static void F_63 ( struct V_102 * V_38 )
{
T_4 V_127 = F_61 ( V_38 ) ;
struct V_36 * V_37 = V_38 -> V_39 ;
if ( V_127 )
F_64 ( V_37 -> V_44 -> V_45 , V_56 ) ;
else
F_64 ( V_37 -> V_44 -> V_45 , 0 ) ;
F_52 ( V_37 -> V_44 ) ;
}
static T_2
F_65 ( struct V_93 * V_94 , struct V_95 * V_96 ,
const char * V_97 , T_5 V_131 )
{
struct V_67 * V_44 = F_42 ( V_94 ) ;
struct V_36 * V_37 = V_44 -> V_69 ;
struct V_102 * V_38 = V_37 -> V_38 ;
int V_132 ;
F_17 ( ! F_34 ( V_37 -> V_38 , V_128 ) ) ;
for ( V_132 = F_66 ( V_133 ) ; -- V_132 >= 0 ; )
if ( F_67 ( V_97 , V_133 [ V_132 ] ) )
break;
if ( V_132 < 0 )
return - V_126 ;
F_68 ( V_38 , F_69 ( struct V_85 , V_129 ) , V_132 ) ;
F_63 ( V_38 ) ;
return V_131 ;
}
static T_2
F_70 ( struct V_93 * V_94 , struct V_95 * V_96 ,
char * V_97 )
{
struct V_67 * V_44 = F_42 ( V_94 ) ;
struct V_36 * V_37 = V_44 -> V_69 ;
T_4 V_127 = F_61 ( V_37 -> V_38 ) ;
F_17 ( V_127 >= F_66 ( V_133 ) ) ;
return snprintf ( V_97 , 40 , L_5 , V_133 [ V_127 ] ) ;
}
static void F_71 ( void * V_77 , struct V_46 * V_47 ,
struct V_28 * V_134 , unsigned int V_135 )
{
struct V_36 * V_37 = V_77 ;
struct V_1 * V_2 = V_134 -> V_49 ;
F_72 ( V_2 -> V_62 , V_37 -> V_55 ) ;
}
static int F_73 ( struct V_102 * V_38 )
{
struct V_36 * V_37 ;
struct V_103 * V_104 ;
int V_71 , V_90 ;
T_3 V_136 ;
T_6 V_137 , V_138 , V_55 , V_139 ;
T_7 V_140 ;
T_4 V_141 , V_142 ;
V_71 = F_74 ( & V_143 , 0 , F_40 ( 1 << V_144 ) ,
V_73 ) ;
if ( V_71 < 0 )
goto V_145;
V_90 = V_71 ;
V_71 = F_62 ( V_38 , V_146 ,
struct V_85 , V_147 ,
& V_55 ) ;
if ( V_71 || ! V_55 )
V_55 = 1 ;
V_55 += 2 ;
V_38 -> V_39 = V_37 = F_75 ( sizeof( * V_37 ) , V_73 ) ;
if ( ! V_37 ) {
V_71 = - V_148 ;
goto V_149;
}
V_37 -> V_38 = V_38 ;
V_37 -> V_55 = V_55 ;
F_76 ( & V_37 -> V_110 ) ;
F_77 ( & V_37 -> V_101 , F_44 ) ;
V_37 -> V_111 = true ;
V_71 = F_58 ( V_37 ) ;
if ( V_71 )
goto V_150;
F_78 ( & V_37 -> V_43 ) ;
V_37 -> V_44 = F_79 ( 1 << V_91 ) ;
if ( ! V_37 -> V_44 ) {
V_71 = - V_148 ;
goto V_151;
}
V_152 . V_153 =
sizeof( struct V_1 ) +
sizeof( struct V_10 ) * V_55 ;
V_104 = V_37 -> V_44 -> V_45 = F_80 ( & V_152 , V_37 ) ;
if ( ! V_104 ) {
V_71 = - V_148 ;
goto V_154;
}
F_81 ( V_104 , F_71 , V_37 ) ;
V_104 -> V_48 = V_37 ;
F_60 ( L_6 , V_90 , V_37 -> V_44 -> V_155 , V_156 ) ;
V_37 -> V_44 -> V_157 = V_157 ;
V_37 -> V_44 -> V_158 = F_39 ( V_90 ) ;
V_37 -> V_44 -> V_69 = V_37 ;
V_37 -> V_44 -> V_159 = & V_160 ;
V_37 -> V_44 -> V_161 = & V_38 -> V_94 ;
V_37 -> V_90 = V_90 ;
F_63 ( V_38 ) ;
if ( F_34 ( V_38 , V_162 ) )
F_82 ( V_37 -> V_44 , 1 ) ;
F_37 ( V_38 , struct V_85 , V_108 , & V_136 ) ;
if ( ( V_113 ) V_136 != V_136 ) {
F_47 ( & V_38 -> V_94 , L_2 ,
( unsigned long long ) V_136 ) ;
V_136 = ( V_113 ) - 1 ;
}
F_51 ( V_37 -> V_44 , V_136 ) ;
F_83 ( V_104 , V_37 -> V_55 - 2 ) ;
F_84 ( V_104 , V_163 ) ;
F_85 ( V_104 , - 1U ) ;
V_71 = F_62 ( V_38 , V_164 ,
struct V_85 , V_165 , & V_137 ) ;
if ( ! V_71 )
F_86 ( V_104 , V_137 ) ;
else
F_86 ( V_104 , - 1U ) ;
V_71 = F_62 ( V_38 , V_166 ,
struct V_85 , V_138 ,
& V_138 ) ;
if ( ! V_71 )
F_87 ( V_104 , V_138 ) ;
else
V_138 = F_48 ( V_104 ) ;
V_71 = F_62 ( V_38 , V_167 ,
struct V_85 , V_141 ,
& V_141 ) ;
if ( ! V_71 && V_141 )
F_88 ( V_104 ,
V_138 * ( 1 << V_141 ) ) ;
V_71 = F_62 ( V_38 , V_167 ,
struct V_85 , V_142 ,
& V_142 ) ;
if ( ! V_71 && V_142 )
F_89 ( V_104 , V_138 * V_142 ) ;
V_71 = F_62 ( V_38 , V_167 ,
struct V_85 , V_140 ,
& V_140 ) ;
if ( ! V_71 && V_140 )
F_90 ( V_104 , V_138 * V_140 ) ;
V_71 = F_62 ( V_38 , V_167 ,
struct V_85 , V_139 ,
& V_139 ) ;
if ( ! V_71 && V_139 )
F_91 ( V_104 , V_138 * V_139 ) ;
F_92 ( V_37 -> V_44 ) ;
V_71 = F_93 ( F_54 ( V_37 -> V_44 ) , & V_168 ) ;
if ( V_71 )
goto V_169;
if ( F_34 ( V_38 , V_128 ) )
V_71 = F_93 ( F_54 ( V_37 -> V_44 ) ,
& V_170 ) ;
else
V_71 = F_93 ( F_54 ( V_37 -> V_44 ) ,
& V_171 ) ;
if ( V_71 )
goto V_169;
return 0 ;
V_169:
F_94 ( V_37 -> V_44 ) ;
F_95 ( V_37 -> V_44 -> V_45 ) ;
V_154:
F_96 ( V_37 -> V_44 ) ;
V_151:
V_38 -> V_172 -> V_173 ( V_38 ) ;
V_150:
F_97 ( V_37 ) ;
V_149:
F_98 ( & V_143 , V_90 ) ;
V_145:
return V_71 ;
}
static void F_99 ( struct V_102 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
int V_90 = V_37 -> V_90 ;
int V_174 ;
F_46 ( & V_37 -> V_110 ) ;
V_37 -> V_111 = false ;
F_55 ( & V_37 -> V_110 ) ;
F_94 ( V_37 -> V_44 ) ;
F_95 ( V_37 -> V_44 -> V_45 ) ;
V_38 -> V_172 -> V_175 ( V_38 ) ;
F_100 ( & V_37 -> V_101 ) ;
V_174 = F_101 ( & F_54 ( V_37 -> V_44 ) -> V_116 . V_176 . V_177 ) ;
F_96 ( V_37 -> V_44 ) ;
V_38 -> V_172 -> V_173 ( V_38 ) ;
F_97 ( V_37 ) ;
if ( V_174 == 1 )
F_98 ( & V_143 , V_90 ) ;
}
static int F_102 ( struct V_102 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
V_38 -> V_172 -> V_175 ( V_38 ) ;
F_46 ( & V_37 -> V_110 ) ;
V_37 -> V_111 = false ;
F_55 ( & V_37 -> V_110 ) ;
F_100 ( & V_37 -> V_101 ) ;
F_103 ( V_37 -> V_44 -> V_45 ) ;
V_38 -> V_172 -> V_173 ( V_38 ) ;
return 0 ;
}
static int F_104 ( struct V_102 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
int V_178 ;
V_37 -> V_111 = true ;
V_178 = F_58 ( V_38 -> V_39 ) ;
if ( ! V_178 )
F_15 ( V_37 -> V_44 -> V_45 ) ;
return V_178 ;
}
static int T_8 F_105 ( void )
{
int error ;
V_118 = F_106 ( L_7 , 0 , 0 ) ;
if ( ! V_118 )
return - V_148 ;
V_157 = F_107 ( 0 , L_8 ) ;
if ( V_157 < 0 ) {
error = V_157 ;
goto V_179;
}
error = F_108 ( & V_36 ) ;
if ( error )
goto V_180;
return 0 ;
V_180:
F_109 ( V_157 , L_8 ) ;
V_179:
F_110 ( V_118 ) ;
return error ;
}
static void T_9 F_111 ( void )
{
F_109 ( V_157 , L_8 ) ;
F_112 ( & V_36 ) ;
F_110 ( V_118 ) ;
}
