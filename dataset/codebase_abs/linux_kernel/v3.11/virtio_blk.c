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
static inline struct V_1 * F_2 ( struct V_8 * V_9 ,
T_1 V_10 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( V_9 -> V_11 , V_10 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_9 = V_9 ;
if ( V_12 )
F_4 ( V_2 -> V_13 , V_9 -> V_14 ) ;
return V_2 ;
}
static int F_5 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_17 * V_18 ,
bool V_19 )
{
struct V_17 V_20 , V_3 , V_21 , V_22 , V_23 , * V_24 [ 6 ] ;
unsigned int V_25 = 0 , V_26 = 0 ;
int type = V_2 -> V_27 . type & ~ V_28 ;
F_6 ( & V_20 , & V_2 -> V_27 , sizeof( V_2 -> V_27 ) ) ;
V_24 [ V_25 ++ ] = & V_20 ;
if ( type == V_29 ) {
F_6 ( & V_21 , V_2 -> V_30 -> V_21 , V_2 -> V_30 -> V_31 ) ;
V_24 [ V_25 ++ ] = & V_21 ;
}
if ( V_19 ) {
if ( V_2 -> V_27 . type & V_28 )
V_24 [ V_25 ++ ] = V_18 ;
else
V_24 [ V_25 + V_26 ++ ] = V_18 ;
}
if ( type == V_29 ) {
F_6 ( & V_22 , V_2 -> V_30 -> V_22 , V_32 ) ;
V_24 [ V_25 + V_26 ++ ] = & V_22 ;
F_6 ( & V_23 , & V_2 -> V_33 , sizeof( V_2 -> V_33 ) ) ;
V_24 [ V_25 + V_26 ++ ] = & V_23 ;
}
F_6 ( & V_3 , & V_2 -> V_3 , sizeof( V_2 -> V_3 ) ) ;
V_24 [ V_25 + V_26 ++ ] = & V_3 ;
return F_7 ( V_16 , V_24 , V_25 , V_26 , V_2 , V_34 ) ;
}
static void F_8 ( struct V_1 * V_2 , bool V_19 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
F_9 ( V_35 ) ;
int V_36 ;
F_10 ( V_9 -> V_37 -> V_38 -> V_39 ) ;
while ( F_11 ( ( V_36 = F_5 ( V_9 -> V_16 , V_2 , V_2 -> V_13 ,
V_19 ) ) < 0 ) ) {
F_12 ( & V_9 -> V_40 , & V_35 ,
V_41 ) ;
F_13 ( V_9 -> V_37 -> V_38 -> V_39 ) ;
F_14 () ;
F_10 ( V_9 -> V_37 -> V_38 -> V_39 ) ;
F_15 ( & V_9 -> V_40 , & V_35 ) ;
}
F_16 ( V_9 -> V_16 ) ;
F_13 ( V_9 -> V_37 -> V_38 -> V_39 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_42 |= V_43 ;
V_2 -> V_27 . type = V_44 ;
V_2 -> V_27 . V_45 = 0 ;
V_2 -> V_27 . V_46 = 0 ;
F_8 ( V_2 , false ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_47 * V_47 = V_2 -> V_47 ;
bool V_19 ;
V_2 -> V_42 &= ~ V_43 ;
V_2 -> V_27 . type = 0 ;
V_2 -> V_27 . V_45 = V_47 -> V_48 ;
V_2 -> V_27 . V_46 = F_19 ( V_47 ) ;
if ( F_20 ( V_9 -> V_37 -> V_38 , V_47 , V_2 -> V_13 ) ) {
V_19 = true ;
if ( V_47 -> V_49 & V_50 )
V_2 -> V_27 . type |= V_28 ;
else
V_2 -> V_27 . type |= V_51 ;
} else
V_19 = false ;
F_8 ( V_2 , V_19 ) ;
}
static void F_21 ( struct V_52 * V_53 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_53 , struct V_1 , V_53 ) ;
F_18 ( V_2 ) ;
}
static void F_23 ( struct V_52 * V_53 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_53 , struct V_1 , V_53 ) ;
F_17 ( V_2 ) ;
}
static inline void F_24 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_54 * V_30 = V_2 -> V_30 ;
int error = F_1 ( V_2 ) ;
if ( V_30 -> V_55 == V_56 ) {
V_30 -> V_57 = V_2 -> V_33 . V_58 ;
V_30 -> V_59 = V_2 -> V_33 . V_59 ;
V_30 -> V_60 = V_2 -> V_33 . V_60 ;
} else if ( V_30 -> V_55 == V_61 ) {
V_30 -> V_60 = ( error != 0 ) ;
}
F_25 ( V_30 , error ) ;
F_26 ( V_2 , V_9 -> V_11 ) ;
}
static inline void F_27 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
if ( V_2 -> V_42 & V_62 ) {
F_28 ( & V_2 -> V_53 , F_21 ) ;
F_29 ( V_63 , & V_2 -> V_53 ) ;
} else {
F_30 ( V_2 -> V_47 , F_1 ( V_2 ) ) ;
F_26 ( V_2 , V_9 -> V_11 ) ;
}
}
static inline void F_31 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
if ( F_11 ( V_2 -> V_42 & V_64 ) ) {
V_2 -> V_42 &= ~ V_62 ;
F_28 ( & V_2 -> V_53 , F_23 ) ;
F_29 ( V_63 , & V_2 -> V_53 ) ;
} else {
F_30 ( V_2 -> V_47 , F_1 ( V_2 ) ) ;
F_26 ( V_2 , V_9 -> V_11 ) ;
}
}
static inline void F_32 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 -> V_42 & V_43 ) )
F_27 ( V_2 ) ;
else
F_31 ( V_2 ) ;
}
static void F_33 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = V_16 -> V_65 -> V_66 ;
bool V_67 = false , V_68 = false ;
struct V_1 * V_2 ;
unsigned long V_42 ;
unsigned int V_69 ;
F_34 ( V_9 -> V_37 -> V_38 -> V_39 , V_42 ) ;
do {
F_35 ( V_16 ) ;
while ( ( V_2 = F_36 ( V_9 -> V_16 , & V_69 ) ) != NULL ) {
if ( V_2 -> V_47 ) {
F_32 ( V_2 ) ;
V_67 = true ;
} else {
F_24 ( V_2 ) ;
V_68 = true ;
}
}
} while ( ! F_37 ( V_16 ) );
if ( V_68 )
F_38 ( V_9 -> V_37 -> V_38 ) ;
F_39 ( V_9 -> V_37 -> V_38 -> V_39 , V_42 ) ;
if ( V_67 )
F_40 ( & V_9 -> V_40 ) ;
}
static bool F_41 ( struct V_70 * V_71 , struct V_8 * V_9 ,
struct V_54 * V_30 )
{
unsigned int V_72 ;
struct V_1 * V_2 ;
V_2 = F_2 ( V_9 , V_34 ) ;
if ( ! V_2 )
return false ;
V_2 -> V_30 = V_30 ;
V_2 -> V_47 = NULL ;
if ( V_30 -> V_73 & V_74 ) {
V_2 -> V_27 . type = V_44 ;
V_2 -> V_27 . V_45 = 0 ;
V_2 -> V_27 . V_46 = F_42 ( V_2 -> V_30 ) ;
} else {
switch ( V_30 -> V_55 ) {
case V_75 :
V_2 -> V_27 . type = 0 ;
V_2 -> V_27 . V_45 = F_43 ( V_2 -> V_30 ) ;
V_2 -> V_27 . V_46 = F_42 ( V_2 -> V_30 ) ;
break;
case V_56 :
V_2 -> V_27 . type = V_29 ;
V_2 -> V_27 . V_45 = 0 ;
V_2 -> V_27 . V_46 = F_42 ( V_2 -> V_30 ) ;
break;
case V_61 :
V_2 -> V_27 . type = V_76 ;
V_2 -> V_27 . V_45 = 0 ;
V_2 -> V_27 . V_46 = F_42 ( V_2 -> V_30 ) ;
break;
default:
F_44 () ;
}
}
V_72 = F_45 ( V_71 , V_2 -> V_30 , V_9 -> V_13 ) ;
if ( V_72 ) {
if ( F_46 ( V_2 -> V_30 ) == V_77 )
V_2 -> V_27 . type |= V_28 ;
else
V_2 -> V_27 . type |= V_51 ;
}
if ( F_5 ( V_9 -> V_16 , V_2 , V_9 -> V_13 , V_72 ) < 0 ) {
F_26 ( V_2 , V_9 -> V_11 ) ;
return false ;
}
return true ;
}
static void F_47 ( struct V_70 * V_71 )
{
struct V_8 * V_9 = V_71 -> V_78 ;
struct V_54 * V_30 ;
unsigned int V_79 = 0 ;
while ( ( V_30 = F_48 ( V_71 ) ) != NULL ) {
F_49 ( V_30 -> V_80 + 2 > V_9 -> V_14 ) ;
if ( ! F_41 ( V_71 , V_9 , V_30 ) ) {
F_50 ( V_71 ) ;
break;
}
F_51 ( V_30 ) ;
V_79 ++ ;
}
if ( V_79 )
F_16 ( V_9 -> V_16 ) ;
}
static void F_52 ( struct V_70 * V_71 , struct V_47 * V_47 )
{
struct V_8 * V_9 = V_71 -> V_78 ;
struct V_1 * V_2 ;
F_49 ( V_47 -> V_81 + 2 > V_9 -> V_14 ) ;
V_2 = F_2 ( V_9 , V_82 ) ;
if ( ! V_2 ) {
F_30 ( V_47 , - V_83 ) ;
return;
}
V_2 -> V_47 = V_47 ;
V_2 -> V_42 = 0 ;
if ( V_47 -> V_49 & V_74 )
V_2 -> V_42 |= V_84 ;
if ( V_47 -> V_49 & V_85 )
V_2 -> V_42 |= V_64 ;
if ( V_47 -> V_86 )
V_2 -> V_42 |= V_62 ;
if ( F_11 ( V_2 -> V_42 & V_84 ) )
F_17 ( V_2 ) ;
else
F_18 ( V_2 ) ;
}
static int F_53 ( struct V_87 * V_37 , char * V_88 )
{
struct V_8 * V_9 = V_37 -> V_89 ;
struct V_54 * V_30 ;
struct V_47 * V_47 ;
int V_90 ;
V_47 = F_54 ( V_9 -> V_37 -> V_38 , V_88 , V_91 ,
V_92 ) ;
if ( F_55 ( V_47 ) )
return F_56 ( V_47 ) ;
V_30 = F_57 ( V_9 -> V_37 -> V_38 , V_47 , V_92 ) ;
if ( F_55 ( V_30 ) ) {
F_58 ( V_47 ) ;
return F_56 ( V_30 ) ;
}
V_30 -> V_55 = V_61 ;
V_90 = F_59 ( V_9 -> V_37 -> V_38 , V_9 -> V_37 , V_30 , false ) ;
F_60 ( V_30 ) ;
return V_90 ;
}
static int F_61 ( struct V_93 * V_94 , T_2 V_95 ,
unsigned int V_21 , unsigned long V_96 )
{
struct V_87 * V_37 = V_94 -> V_97 ;
struct V_8 * V_9 = V_37 -> V_89 ;
if ( ! F_62 ( V_9 -> V_65 , V_98 ) )
return - V_6 ;
return F_63 ( V_94 , V_95 , V_21 ,
( void V_99 * ) V_96 ) ;
}
static int F_64 ( struct V_93 * V_100 , struct V_101 * V_102 )
{
struct V_8 * V_9 = V_100 -> V_97 -> V_89 ;
struct V_103 V_104 ;
int V_90 ;
V_90 = F_65 ( V_9 -> V_65 , V_105 ,
F_66 ( struct V_106 , V_107 ) ,
& V_104 ) ;
if ( ! V_90 ) {
V_102 -> V_108 = V_104 . V_108 ;
V_102 -> V_109 = V_104 . V_109 ;
V_102 -> V_110 = V_104 . V_110 ;
} else {
V_102 -> V_108 = 1 << 6 ;
V_102 -> V_109 = 1 << 5 ;
V_102 -> V_110 = F_67 ( V_100 -> V_97 ) >> 11 ;
}
return 0 ;
}
static int F_68 ( int V_111 )
{
return V_111 << V_112 ;
}
static int F_69 ( int V_113 )
{
return V_113 >> V_112 ;
}
static T_3 F_70 ( struct V_114 * V_115 ,
struct V_116 * V_117 , char * V_118 )
{
struct V_87 * V_37 = F_71 ( V_115 ) ;
int V_90 ;
F_72 ( V_119 < V_91 ) ;
V_118 [ V_91 ] = '\0' ;
V_90 = F_53 ( V_37 , V_118 ) ;
if ( ! V_90 )
return strlen ( V_118 ) ;
if ( V_90 == - V_7 )
return 0 ;
return V_90 ;
}
static void F_73 ( struct V_52 * V_53 )
{
struct V_8 * V_9 =
F_22 ( V_53 , struct V_8 , V_120 ) ;
struct V_121 * V_65 = V_9 -> V_65 ;
struct V_70 * V_71 = V_9 -> V_37 -> V_38 ;
char V_122 [ 10 ] , V_123 [ 10 ] ;
char * V_124 [] = { L_1 , NULL } ;
T_4 V_125 , V_126 ;
F_74 ( & V_9 -> V_127 ) ;
if ( ! V_9 -> V_128 )
goto V_129;
V_65 -> V_130 -> V_131 ( V_65 , F_66 ( struct V_106 , V_125 ) ,
& V_125 , sizeof( V_125 ) ) ;
if ( ( V_132 ) V_125 != V_125 ) {
F_75 ( & V_65 -> V_115 , L_2 ,
( unsigned long long ) V_125 ) ;
V_125 = ( V_132 ) - 1 ;
}
V_126 = V_125 * F_76 ( V_71 ) ;
F_77 ( V_126 , V_133 , V_122 , sizeof( V_122 ) ) ;
F_77 ( V_126 , V_134 , V_123 , sizeof( V_123 ) ) ;
F_78 ( & V_65 -> V_115 ,
L_3 ,
( unsigned long long ) V_125 ,
F_76 ( V_71 ) ,
V_123 , V_122 ) ;
F_79 ( V_9 -> V_37 , V_125 ) ;
F_80 ( V_9 -> V_37 ) ;
F_81 ( & F_82 ( V_9 -> V_37 ) -> V_135 , V_136 , V_124 ) ;
V_129:
F_83 ( & V_9 -> V_127 ) ;
}
static void F_84 ( struct V_121 * V_65 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
F_29 ( V_63 , & V_9 -> V_120 ) ;
}
static int F_85 ( struct V_8 * V_9 )
{
int V_90 = 0 ;
V_9 -> V_16 = F_86 ( V_9 -> V_65 , F_33 , L_4 ) ;
if ( F_55 ( V_9 -> V_16 ) )
V_90 = F_56 ( V_9 -> V_16 ) ;
return V_90 ;
}
static int F_87 ( char * V_137 , int V_111 , char * V_118 , int V_138 )
{
const int V_139 = 'z' - 'a' + 1 ;
char * V_140 = V_118 + strlen ( V_137 ) ;
char * V_141 = V_118 + V_138 ;
char * V_142 ;
int V_143 ;
V_142 = V_141 - 1 ;
* V_142 = '\0' ;
V_143 = V_139 ;
do {
if ( V_142 == V_140 )
return - V_144 ;
* -- V_142 = 'a' + ( V_111 % V_143 ) ;
V_111 = ( V_111 / V_143 ) - 1 ;
} while ( V_111 >= 0 );
memmove ( V_140 , V_142 , V_141 - V_142 ) ;
memcpy ( V_118 , V_137 , strlen ( V_137 ) ) ;
return 0 ;
}
static int F_88 ( struct V_121 * V_65 )
{
T_5 V_145 ;
int V_90 ;
V_90 = F_65 ( V_65 , V_146 ,
F_66 ( struct V_106 , V_147 ) ,
& V_145 ) ;
if ( V_90 )
V_145 = F_62 ( V_65 , V_148 ) ;
return V_145 ;
}
static void F_89 ( struct V_121 * V_65 )
{
T_5 V_145 = F_88 ( V_65 ) ;
struct V_8 * V_9 = V_65 -> V_66 ;
if ( V_145 )
F_90 ( V_9 -> V_37 -> V_38 , V_74 ) ;
else
F_90 ( V_9 -> V_37 -> V_38 , 0 ) ;
F_80 ( V_9 -> V_37 ) ;
}
static T_3
F_91 ( struct V_114 * V_115 , struct V_116 * V_117 ,
const char * V_118 , T_6 V_149 )
{
struct V_87 * V_37 = F_71 ( V_115 ) ;
struct V_8 * V_9 = V_37 -> V_89 ;
struct V_121 * V_65 = V_9 -> V_65 ;
int V_150 ;
T_5 V_145 ;
F_49 ( ! F_62 ( V_9 -> V_65 , V_146 ) ) ;
for ( V_150 = F_92 ( V_151 ) ; -- V_150 >= 0 ; )
if ( F_93 ( V_118 , V_151 [ V_150 ] ) )
break;
if ( V_150 < 0 )
return - V_144 ;
V_145 = V_150 ;
V_65 -> V_130 -> V_152 ( V_65 ,
F_66 ( struct V_106 , V_147 ) ,
& V_145 , sizeof( V_145 ) ) ;
F_89 ( V_65 ) ;
return V_149 ;
}
static T_3
F_94 ( struct V_114 * V_115 , struct V_116 * V_117 ,
char * V_118 )
{
struct V_87 * V_37 = F_71 ( V_115 ) ;
struct V_8 * V_9 = V_37 -> V_89 ;
T_5 V_145 = F_88 ( V_9 -> V_65 ) ;
F_49 ( V_145 >= F_92 ( V_151 ) ) ;
return snprintf ( V_118 , 40 , L_5 , V_151 [ V_145 ] ) ;
}
static int F_95 ( struct V_121 * V_65 )
{
struct V_8 * V_9 ;
struct V_70 * V_71 ;
int V_90 , V_111 ;
int V_153 ;
T_4 V_154 ;
T_7 V_155 , V_156 , V_14 , V_157 ;
T_8 V_158 ;
T_5 V_159 , V_160 ;
V_90 = F_96 ( & V_161 , 0 , F_69 ( 1 << V_162 ) ,
V_92 ) ;
if ( V_90 < 0 )
goto V_163;
V_111 = V_90 ;
V_90 = F_65 ( V_65 , V_164 ,
F_66 ( struct V_106 , V_165 ) ,
& V_14 ) ;
if ( V_90 || ! V_14 )
V_14 = 1 ;
V_14 += 2 ;
V_65 -> V_66 = V_9 = F_97 ( sizeof( * V_9 ) +
sizeof( V_9 -> V_13 [ 0 ] ) * V_14 , V_92 ) ;
if ( ! V_9 ) {
V_90 = - V_83 ;
goto V_166;
}
F_98 ( & V_9 -> V_40 ) ;
V_9 -> V_65 = V_65 ;
V_9 -> V_14 = V_14 ;
F_4 ( V_9 -> V_13 , V_9 -> V_14 ) ;
F_99 ( & V_9 -> V_127 ) ;
F_28 ( & V_9 -> V_120 , F_73 ) ;
V_9 -> V_128 = true ;
V_90 = F_85 ( V_9 ) ;
if ( V_90 )
goto V_167;
V_153 = sizeof( struct V_1 ) ;
if ( V_12 )
V_153 += sizeof( struct V_17 ) * V_14 ;
V_9 -> V_11 = F_100 ( 1 , V_153 ) ;
if ( ! V_9 -> V_11 ) {
V_90 = - V_83 ;
goto V_168;
}
V_9 -> V_37 = F_101 ( 1 << V_112 ) ;
if ( ! V_9 -> V_37 ) {
V_90 = - V_83 ;
goto V_169;
}
V_71 = V_9 -> V_37 -> V_38 = F_102 ( F_47 , NULL ) ;
if ( ! V_71 ) {
V_90 = - V_83 ;
goto V_170;
}
if ( V_12 )
F_103 ( V_71 , F_52 ) ;
V_71 -> V_78 = V_9 ;
F_87 ( L_6 , V_111 , V_9 -> V_37 -> V_171 , V_172 ) ;
V_9 -> V_37 -> V_173 = V_173 ;
V_9 -> V_37 -> V_174 = F_68 ( V_111 ) ;
V_9 -> V_37 -> V_89 = V_9 ;
V_9 -> V_37 -> V_175 = & V_176 ;
V_9 -> V_37 -> V_177 = & V_65 -> V_115 ;
V_9 -> V_111 = V_111 ;
F_89 ( V_65 ) ;
if ( F_62 ( V_65 , V_178 ) )
F_104 ( V_9 -> V_37 , 1 ) ;
V_65 -> V_130 -> V_131 ( V_65 , F_66 ( struct V_106 , V_125 ) ,
& V_154 , sizeof( V_154 ) ) ;
if ( ( V_132 ) V_154 != V_154 ) {
F_75 ( & V_65 -> V_115 , L_2 ,
( unsigned long long ) V_154 ) ;
V_154 = ( V_132 ) - 1 ;
}
F_79 ( V_9 -> V_37 , V_154 ) ;
F_105 ( V_71 , V_9 -> V_14 - 2 ) ;
F_106 ( V_71 , V_179 ) ;
F_107 ( V_71 , - 1U ) ;
V_90 = F_65 ( V_65 , V_180 ,
F_66 ( struct V_106 , V_181 ) ,
& V_155 ) ;
if ( ! V_90 )
F_108 ( V_71 , V_155 ) ;
else
F_108 ( V_71 , - 1U ) ;
V_90 = F_65 ( V_65 , V_182 ,
F_66 ( struct V_106 , V_156 ) ,
& V_156 ) ;
if ( ! V_90 )
F_109 ( V_71 , V_156 ) ;
else
V_156 = F_76 ( V_71 ) ;
V_90 = F_65 ( V_65 , V_183 ,
F_66 ( struct V_106 , V_159 ) ,
& V_159 ) ;
if ( ! V_90 && V_159 )
F_110 ( V_71 ,
V_156 * ( 1 << V_159 ) ) ;
V_90 = F_65 ( V_65 , V_183 ,
F_66 ( struct V_106 , V_160 ) ,
& V_160 ) ;
if ( ! V_90 && V_160 )
F_111 ( V_71 , V_156 * V_160 ) ;
V_90 = F_65 ( V_65 , V_183 ,
F_66 ( struct V_106 , V_158 ) ,
& V_158 ) ;
if ( ! V_90 && V_158 )
F_112 ( V_71 , V_156 * V_158 ) ;
V_90 = F_65 ( V_65 , V_183 ,
F_66 ( struct V_106 , V_157 ) ,
& V_157 ) ;
if ( ! V_90 && V_157 )
F_113 ( V_71 , V_156 * V_157 ) ;
F_114 ( V_9 -> V_37 ) ;
V_90 = F_115 ( F_82 ( V_9 -> V_37 ) , & V_184 ) ;
if ( V_90 )
goto V_185;
if ( F_62 ( V_65 , V_146 ) )
V_90 = F_115 ( F_82 ( V_9 -> V_37 ) ,
& V_186 ) ;
else
V_90 = F_115 ( F_82 ( V_9 -> V_37 ) ,
& V_187 ) ;
if ( V_90 )
goto V_185;
return 0 ;
V_185:
F_116 ( V_9 -> V_37 ) ;
F_117 ( V_9 -> V_37 -> V_38 ) ;
V_170:
F_118 ( V_9 -> V_37 ) ;
V_169:
F_119 ( V_9 -> V_11 ) ;
V_168:
V_65 -> V_130 -> V_188 ( V_65 ) ;
V_167:
F_120 ( V_9 ) ;
V_166:
F_121 ( & V_161 , V_111 ) ;
V_163:
return V_90 ;
}
static void F_122 ( struct V_121 * V_65 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
int V_111 = V_9 -> V_111 ;
int V_189 ;
F_74 ( & V_9 -> V_127 ) ;
V_9 -> V_128 = false ;
F_83 ( & V_9 -> V_127 ) ;
F_116 ( V_9 -> V_37 ) ;
F_117 ( V_9 -> V_37 -> V_38 ) ;
V_65 -> V_130 -> V_190 ( V_65 ) ;
F_123 ( & V_9 -> V_120 ) ;
V_189 = F_124 ( & F_82 ( V_9 -> V_37 ) -> V_135 . V_191 . V_192 ) ;
F_118 ( V_9 -> V_37 ) ;
F_119 ( V_9 -> V_11 ) ;
V_65 -> V_130 -> V_188 ( V_65 ) ;
F_120 ( V_9 ) ;
if ( V_189 == 1 )
F_121 ( & V_161 , V_111 ) ;
}
static int F_125 ( struct V_121 * V_65 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
V_65 -> V_130 -> V_190 ( V_65 ) ;
F_74 ( & V_9 -> V_127 ) ;
V_9 -> V_128 = false ;
F_83 ( & V_9 -> V_127 ) ;
F_123 ( & V_9 -> V_120 ) ;
F_10 ( V_9 -> V_37 -> V_38 -> V_39 ) ;
F_50 ( V_9 -> V_37 -> V_38 ) ;
F_13 ( V_9 -> V_37 -> V_38 -> V_39 ) ;
F_126 ( V_9 -> V_37 -> V_38 ) ;
V_65 -> V_130 -> V_188 ( V_65 ) ;
return 0 ;
}
static int F_127 ( struct V_121 * V_65 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
int V_36 ;
V_9 -> V_128 = true ;
V_36 = F_85 ( V_65 -> V_66 ) ;
if ( ! V_36 ) {
F_10 ( V_9 -> V_37 -> V_38 -> V_39 ) ;
F_38 ( V_9 -> V_37 -> V_38 ) ;
F_13 ( V_9 -> V_37 -> V_38 -> V_39 ) ;
}
return V_36 ;
}
static int T_9 F_128 ( void )
{
int error ;
V_63 = F_129 ( L_7 , 0 , 0 ) ;
if ( ! V_63 )
return - V_83 ;
V_173 = F_130 ( 0 , L_8 ) ;
if ( V_173 < 0 ) {
error = V_173 ;
goto V_193;
}
error = F_131 ( & V_8 ) ;
if ( error )
goto V_194;
return 0 ;
V_194:
F_132 ( V_173 , L_8 ) ;
V_193:
F_133 ( V_63 ) ;
return error ;
}
static void T_10 F_134 ( void )
{
F_132 ( V_173 , L_8 ) ;
F_135 ( & V_8 ) ;
F_133 ( V_63 ) ;
}
