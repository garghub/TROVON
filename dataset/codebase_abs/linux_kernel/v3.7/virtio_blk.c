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
static void F_5 ( struct V_8 * V_9 ,
struct V_1 * V_2 ,
unsigned long V_15 ,
unsigned long V_16 )
{
F_6 ( V_17 ) ;
for (; ; ) {
F_7 ( & V_9 -> V_18 , & V_17 ,
V_19 ) ;
F_8 ( V_9 -> V_20 -> V_21 -> V_22 ) ;
if ( F_9 ( V_9 -> V_23 , V_2 -> V_13 , V_15 , V_16 , V_2 ,
V_24 ) < 0 ) {
F_10 ( V_9 -> V_20 -> V_21 -> V_22 ) ;
F_11 () ;
} else {
F_12 ( V_9 -> V_23 ) ;
F_10 ( V_9 -> V_20 -> V_21 -> V_22 ) ;
break;
}
}
F_13 ( & V_9 -> V_18 , & V_17 ) ;
}
static inline void F_14 ( struct V_1 * V_2 ,
unsigned int V_15 , unsigned int V_16 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
F_8 ( V_9 -> V_20 -> V_21 -> V_22 ) ;
if ( F_15 ( F_9 ( V_9 -> V_23 , V_2 -> V_13 , V_15 , V_16 , V_2 ,
V_24 ) < 0 ) ) {
F_10 ( V_9 -> V_20 -> V_21 -> V_22 ) ;
F_5 ( V_9 , V_2 , V_15 , V_16 ) ;
return;
}
F_12 ( V_9 -> V_23 ) ;
F_10 ( V_9 -> V_20 -> V_21 -> V_22 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned int V_15 = 0 , V_16 = 0 ;
V_2 -> V_25 |= V_26 ;
V_2 -> V_27 . type = V_28 ;
V_2 -> V_27 . V_29 = 0 ;
V_2 -> V_27 . V_30 = 0 ;
F_17 ( & V_2 -> V_13 [ V_15 ++ ] , & V_2 -> V_27 , sizeof( V_2 -> V_27 ) ) ;
F_17 ( & V_2 -> V_13 [ V_15 + V_16 ++ ] , & V_2 -> V_3 , sizeof( V_2 -> V_3 ) ) ;
F_14 ( V_2 , V_15 , V_16 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned int V_31 , V_15 = 0 , V_16 = 0 ;
struct V_32 * V_32 = V_2 -> V_32 ;
V_2 -> V_25 &= ~ V_26 ;
V_2 -> V_27 . type = 0 ;
V_2 -> V_27 . V_29 = V_32 -> V_33 ;
V_2 -> V_27 . V_30 = F_19 ( V_32 ) ;
F_17 ( & V_2 -> V_13 [ V_15 ++ ] , & V_2 -> V_27 , sizeof( V_2 -> V_27 ) ) ;
V_31 = F_20 ( V_9 -> V_20 -> V_21 , V_32 , V_2 -> V_13 + V_15 ) ;
F_17 ( & V_2 -> V_13 [ V_31 + V_15 + V_16 ++ ] , & V_2 -> V_3 ,
sizeof( V_2 -> V_3 ) ) ;
if ( V_31 ) {
if ( V_32 -> V_34 & V_35 ) {
V_2 -> V_27 . type |= V_36 ;
V_15 += V_31 ;
} else {
V_2 -> V_27 . type |= V_37 ;
V_16 += V_31 ;
}
}
F_14 ( V_2 , V_15 , V_16 ) ;
return 0 ;
}
static void F_21 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_39 , struct V_1 , V_39 ) ;
F_18 ( V_2 ) ;
}
static void F_23 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_39 , struct V_1 , V_39 ) ;
F_16 ( V_2 ) ;
}
static inline void F_24 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_40 * V_41 = V_2 -> V_41 ;
int error = F_1 ( V_2 ) ;
if ( V_41 -> V_42 == V_43 ) {
V_41 -> V_44 = V_2 -> V_45 . V_46 ;
V_41 -> V_47 = V_2 -> V_45 . V_47 ;
V_41 -> V_48 = V_2 -> V_45 . V_48 ;
} else if ( V_41 -> V_42 == V_49 ) {
V_41 -> V_48 = ( error != 0 ) ;
}
F_25 ( V_41 , error ) ;
F_26 ( V_2 , V_9 -> V_11 ) ;
}
static inline void F_27 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
if ( V_2 -> V_25 & V_50 ) {
F_28 ( & V_2 -> V_39 , F_21 ) ;
F_29 ( V_51 , & V_2 -> V_39 ) ;
} else {
F_30 ( V_2 -> V_32 , F_1 ( V_2 ) ) ;
F_26 ( V_2 , V_9 -> V_11 ) ;
}
}
static inline void F_31 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
if ( F_15 ( V_2 -> V_25 & V_52 ) ) {
V_2 -> V_25 &= ~ V_50 ;
F_28 ( & V_2 -> V_39 , F_23 ) ;
F_29 ( V_51 , & V_2 -> V_39 ) ;
} else {
F_30 ( V_2 -> V_32 , F_1 ( V_2 ) ) ;
F_26 ( V_2 , V_9 -> V_11 ) ;
}
}
static inline void F_32 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 -> V_25 & V_26 ) )
F_27 ( V_2 ) ;
else
F_31 ( V_2 ) ;
}
static void F_33 ( struct V_53 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_54 -> V_55 ;
bool V_56 = false , V_57 = false ;
struct V_1 * V_2 ;
unsigned long V_25 ;
unsigned int V_58 ;
F_34 ( V_9 -> V_20 -> V_21 -> V_22 , V_25 ) ;
do {
F_35 ( V_23 ) ;
while ( ( V_2 = F_36 ( V_9 -> V_23 , & V_58 ) ) != NULL ) {
if ( V_2 -> V_32 ) {
F_32 ( V_2 ) ;
V_56 = true ;
} else {
F_24 ( V_2 ) ;
V_57 = true ;
}
}
} while ( ! F_37 ( V_23 ) );
if ( V_57 )
F_38 ( V_9 -> V_20 -> V_21 ) ;
F_39 ( V_9 -> V_20 -> V_21 -> V_22 , V_25 ) ;
if ( V_56 )
F_40 ( & V_9 -> V_18 ) ;
}
static bool F_41 ( struct V_59 * V_60 , struct V_8 * V_9 ,
struct V_40 * V_41 )
{
unsigned long V_31 , V_15 = 0 , V_16 = 0 ;
struct V_1 * V_2 ;
V_2 = F_2 ( V_9 , V_24 ) ;
if ( ! V_2 )
return false ;
V_2 -> V_41 = V_41 ;
V_2 -> V_32 = NULL ;
if ( V_41 -> V_61 & V_62 ) {
V_2 -> V_27 . type = V_28 ;
V_2 -> V_27 . V_29 = 0 ;
V_2 -> V_27 . V_30 = F_42 ( V_2 -> V_41 ) ;
} else {
switch ( V_41 -> V_42 ) {
case V_63 :
V_2 -> V_27 . type = 0 ;
V_2 -> V_27 . V_29 = F_43 ( V_2 -> V_41 ) ;
V_2 -> V_27 . V_30 = F_42 ( V_2 -> V_41 ) ;
break;
case V_43 :
V_2 -> V_27 . type = V_64 ;
V_2 -> V_27 . V_29 = 0 ;
V_2 -> V_27 . V_30 = F_42 ( V_2 -> V_41 ) ;
break;
case V_49 :
V_2 -> V_27 . type = V_65 ;
V_2 -> V_27 . V_29 = 0 ;
V_2 -> V_27 . V_30 = F_42 ( V_2 -> V_41 ) ;
break;
default:
F_44 () ;
}
}
F_17 ( & V_9 -> V_13 [ V_15 ++ ] , & V_2 -> V_27 , sizeof( V_2 -> V_27 ) ) ;
if ( V_2 -> V_41 -> V_42 == V_43 )
F_17 ( & V_9 -> V_13 [ V_15 ++ ] , V_2 -> V_41 -> V_66 , V_2 -> V_41 -> V_67 ) ;
V_31 = F_45 ( V_60 , V_2 -> V_41 , V_9 -> V_13 + V_15 ) ;
if ( V_2 -> V_41 -> V_42 == V_43 ) {
F_17 ( & V_9 -> V_13 [ V_31 + V_15 + V_16 ++ ] , V_2 -> V_41 -> V_68 , V_69 ) ;
F_17 ( & V_9 -> V_13 [ V_31 + V_15 + V_16 ++ ] , & V_2 -> V_45 ,
sizeof( V_2 -> V_45 ) ) ;
}
F_17 ( & V_9 -> V_13 [ V_31 + V_15 + V_16 ++ ] , & V_2 -> V_3 ,
sizeof( V_2 -> V_3 ) ) ;
if ( V_31 ) {
if ( F_46 ( V_2 -> V_41 ) == V_70 ) {
V_2 -> V_27 . type |= V_36 ;
V_15 += V_31 ;
} else {
V_2 -> V_27 . type |= V_37 ;
V_16 += V_31 ;
}
}
if ( F_9 ( V_9 -> V_23 , V_9 -> V_13 , V_15 , V_16 , V_2 ,
V_24 ) < 0 ) {
F_26 ( V_2 , V_9 -> V_11 ) ;
return false ;
}
return true ;
}
static void F_47 ( struct V_59 * V_60 )
{
struct V_8 * V_9 = V_60 -> V_71 ;
struct V_40 * V_41 ;
unsigned int V_72 = 0 ;
while ( ( V_41 = F_48 ( V_60 ) ) != NULL ) {
F_49 ( V_41 -> V_73 + 2 > V_9 -> V_14 ) ;
if ( ! F_41 ( V_60 , V_9 , V_41 ) ) {
F_50 ( V_60 ) ;
break;
}
F_51 ( V_41 ) ;
V_72 ++ ;
}
if ( V_72 )
F_12 ( V_9 -> V_23 ) ;
}
static void F_52 ( struct V_59 * V_60 , struct V_32 * V_32 )
{
struct V_8 * V_9 = V_60 -> V_71 ;
struct V_1 * V_2 ;
F_49 ( V_32 -> V_74 + 2 > V_9 -> V_14 ) ;
V_2 = F_2 ( V_9 , V_75 ) ;
if ( ! V_2 ) {
F_30 ( V_32 , - V_76 ) ;
return;
}
V_2 -> V_32 = V_32 ;
V_2 -> V_25 = 0 ;
if ( V_32 -> V_34 & V_62 )
V_2 -> V_25 |= V_77 ;
if ( V_32 -> V_34 & V_78 )
V_2 -> V_25 |= V_52 ;
if ( V_32 -> V_79 )
V_2 -> V_25 |= V_50 ;
if ( F_15 ( V_2 -> V_25 & V_77 ) )
F_16 ( V_2 ) ;
else
F_18 ( V_2 ) ;
}
static int F_53 ( struct V_80 * V_20 , char * V_81 )
{
struct V_8 * V_9 = V_20 -> V_82 ;
struct V_40 * V_41 ;
struct V_32 * V_32 ;
int V_83 ;
V_32 = F_54 ( V_9 -> V_20 -> V_21 , V_81 , V_84 ,
V_85 ) ;
if ( F_55 ( V_32 ) )
return F_56 ( V_32 ) ;
V_41 = F_57 ( V_9 -> V_20 -> V_21 , V_32 , V_85 ) ;
if ( F_55 ( V_41 ) ) {
F_58 ( V_32 ) ;
return F_56 ( V_41 ) ;
}
V_41 -> V_42 = V_49 ;
V_83 = F_59 ( V_9 -> V_20 -> V_21 , V_9 -> V_20 , V_41 , false ) ;
F_60 ( V_41 ) ;
return V_83 ;
}
static int F_61 ( struct V_86 * V_87 , T_2 V_88 ,
unsigned int V_66 , unsigned long V_89 )
{
struct V_80 * V_20 = V_87 -> V_90 ;
struct V_8 * V_9 = V_20 -> V_82 ;
if ( ! F_62 ( V_9 -> V_54 , V_91 ) )
return - V_6 ;
return F_63 ( V_87 , V_88 , V_66 ,
( void V_92 * ) V_89 ) ;
}
static int F_64 ( struct V_86 * V_93 , struct V_94 * V_95 )
{
struct V_8 * V_9 = V_93 -> V_90 -> V_82 ;
struct V_96 V_97 ;
int V_83 ;
V_83 = F_65 ( V_9 -> V_54 , V_98 ,
F_66 ( struct V_99 , V_100 ) ,
& V_97 ) ;
if ( ! V_83 ) {
V_95 -> V_101 = V_97 . V_101 ;
V_95 -> V_102 = V_97 . V_102 ;
V_95 -> V_103 = V_97 . V_103 ;
} else {
V_95 -> V_101 = 1 << 6 ;
V_95 -> V_102 = 1 << 5 ;
V_95 -> V_103 = F_67 ( V_93 -> V_90 ) >> 11 ;
}
return 0 ;
}
static int F_68 ( int V_104 )
{
return V_104 << V_105 ;
}
static int F_69 ( int V_106 )
{
return V_106 >> V_105 ;
}
static T_3 F_70 ( struct V_107 * V_108 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_80 * V_20 = F_71 ( V_108 ) ;
int V_83 ;
F_72 ( V_112 < V_84 ) ;
V_111 [ V_84 ] = '\0' ;
V_83 = F_53 ( V_20 , V_111 ) ;
if ( ! V_83 )
return strlen ( V_111 ) ;
if ( V_83 == - V_7 )
return 0 ;
return V_83 ;
}
static void F_73 ( struct V_38 * V_39 )
{
struct V_8 * V_9 =
F_22 ( V_39 , struct V_8 , V_113 ) ;
struct V_114 * V_54 = V_9 -> V_54 ;
struct V_59 * V_60 = V_9 -> V_20 -> V_21 ;
char V_115 [ 10 ] , V_116 [ 10 ] ;
T_4 V_117 , V_118 ;
F_74 ( & V_9 -> V_119 ) ;
if ( ! V_9 -> V_120 )
goto V_121;
V_54 -> V_122 -> V_123 ( V_54 , F_66 ( struct V_99 , V_117 ) ,
& V_117 , sizeof( V_117 ) ) ;
if ( ( V_124 ) V_117 != V_117 ) {
F_75 ( & V_54 -> V_108 , L_1 ,
( unsigned long long ) V_117 ) ;
V_117 = ( V_124 ) - 1 ;
}
V_118 = V_117 * F_76 ( V_60 ) ;
F_77 ( V_118 , V_125 , V_115 , sizeof( V_115 ) ) ;
F_77 ( V_118 , V_126 , V_116 , sizeof( V_116 ) ) ;
F_78 ( & V_54 -> V_108 ,
L_2 ,
( unsigned long long ) V_117 ,
F_76 ( V_60 ) ,
V_116 , V_115 ) ;
F_79 ( V_9 -> V_20 , V_117 ) ;
F_80 ( V_9 -> V_20 ) ;
V_121:
F_81 ( & V_9 -> V_119 ) ;
}
static void F_82 ( struct V_114 * V_54 )
{
struct V_8 * V_9 = V_54 -> V_55 ;
F_29 ( V_51 , & V_9 -> V_113 ) ;
}
static int F_83 ( struct V_8 * V_9 )
{
int V_83 = 0 ;
V_9 -> V_23 = F_84 ( V_9 -> V_54 , F_33 , L_3 ) ;
if ( F_55 ( V_9 -> V_23 ) )
V_83 = F_56 ( V_9 -> V_23 ) ;
return V_83 ;
}
static int F_85 ( char * V_127 , int V_104 , char * V_111 , int V_128 )
{
const int V_129 = 'z' - 'a' + 1 ;
char * V_130 = V_111 + strlen ( V_127 ) ;
char * V_131 = V_111 + V_128 ;
char * V_132 ;
int V_133 ;
V_132 = V_131 - 1 ;
* V_132 = '\0' ;
V_133 = V_129 ;
do {
if ( V_132 == V_130 )
return - V_134 ;
* -- V_132 = 'a' + ( V_104 % V_133 ) ;
V_104 = ( V_104 / V_133 ) - 1 ;
} while ( V_104 >= 0 );
memmove ( V_130 , V_132 , V_131 - V_132 ) ;
memcpy ( V_111 , V_127 , strlen ( V_127 ) ) ;
return 0 ;
}
static int F_86 ( struct V_114 * V_54 )
{
T_5 V_135 ;
int V_83 ;
V_83 = F_65 ( V_54 , V_136 ,
F_66 ( struct V_99 , V_137 ) ,
& V_135 ) ;
if ( V_83 )
V_135 = F_62 ( V_54 , V_138 ) ;
return V_135 ;
}
static void F_87 ( struct V_114 * V_54 )
{
T_5 V_135 = F_86 ( V_54 ) ;
struct V_8 * V_9 = V_54 -> V_55 ;
if ( V_135 )
F_88 ( V_9 -> V_20 -> V_21 , V_62 ) ;
else
F_88 ( V_9 -> V_20 -> V_21 , 0 ) ;
F_80 ( V_9 -> V_20 ) ;
}
static T_3
F_89 ( struct V_107 * V_108 , struct V_109 * V_110 ,
const char * V_111 , T_6 V_139 )
{
struct V_80 * V_20 = F_71 ( V_108 ) ;
struct V_8 * V_9 = V_20 -> V_82 ;
struct V_114 * V_54 = V_9 -> V_54 ;
int V_140 ;
T_5 V_135 ;
F_49 ( ! F_62 ( V_9 -> V_54 , V_136 ) ) ;
for ( V_140 = F_90 ( V_141 ) ; -- V_140 >= 0 ; )
if ( F_91 ( V_111 , V_141 [ V_140 ] ) )
break;
if ( V_140 < 0 )
return - V_134 ;
V_135 = V_140 ;
V_54 -> V_122 -> V_142 ( V_54 ,
F_66 ( struct V_99 , V_137 ) ,
& V_135 , sizeof( V_135 ) ) ;
F_87 ( V_54 ) ;
return V_139 ;
}
static T_3
F_92 ( struct V_107 * V_108 , struct V_109 * V_110 ,
char * V_111 )
{
struct V_80 * V_20 = F_71 ( V_108 ) ;
struct V_8 * V_9 = V_20 -> V_82 ;
T_5 V_135 = F_86 ( V_9 -> V_54 ) ;
F_49 ( V_135 >= F_90 ( V_141 ) ) ;
return snprintf ( V_111 , 40 , L_4 , V_141 [ V_135 ] ) ;
}
static int T_7 F_93 ( struct V_114 * V_54 )
{
struct V_8 * V_9 ;
struct V_59 * V_60 ;
int V_83 , V_104 ;
int V_143 ;
T_4 V_144 ;
T_8 V_145 , V_146 , V_14 , V_147 ;
T_9 V_148 ;
T_5 V_149 , V_150 ;
V_83 = F_94 ( & V_151 , 0 , F_69 ( 1 << V_152 ) ,
V_85 ) ;
if ( V_83 < 0 )
goto V_15;
V_104 = V_83 ;
V_83 = F_65 ( V_54 , V_153 ,
F_66 ( struct V_99 , V_154 ) ,
& V_14 ) ;
if ( V_83 || ! V_14 )
V_14 = 1 ;
V_14 += 2 ;
V_54 -> V_55 = V_9 = F_95 ( sizeof( * V_9 ) +
sizeof( V_9 -> V_13 [ 0 ] ) * V_14 , V_85 ) ;
if ( ! V_9 ) {
V_83 = - V_76 ;
goto V_155;
}
F_96 ( & V_9 -> V_18 ) ;
V_9 -> V_54 = V_54 ;
V_9 -> V_14 = V_14 ;
F_4 ( V_9 -> V_13 , V_9 -> V_14 ) ;
F_97 ( & V_9 -> V_119 ) ;
F_28 ( & V_9 -> V_113 , F_73 ) ;
V_9 -> V_120 = true ;
V_83 = F_83 ( V_9 ) ;
if ( V_83 )
goto V_156;
V_143 = sizeof( struct V_1 ) ;
if ( V_12 )
V_143 += sizeof( struct V_157 ) * V_14 ;
V_9 -> V_11 = F_98 ( 1 , V_143 ) ;
if ( ! V_9 -> V_11 ) {
V_83 = - V_76 ;
goto V_158;
}
V_9 -> V_20 = F_99 ( 1 << V_105 ) ;
if ( ! V_9 -> V_20 ) {
V_83 = - V_76 ;
goto V_159;
}
V_60 = V_9 -> V_20 -> V_21 = F_100 ( F_47 , NULL ) ;
if ( ! V_60 ) {
V_83 = - V_76 ;
goto V_160;
}
if ( V_12 )
F_101 ( V_60 , F_52 ) ;
V_60 -> V_71 = V_9 ;
F_85 ( L_5 , V_104 , V_9 -> V_20 -> V_161 , V_162 ) ;
V_9 -> V_20 -> V_163 = V_163 ;
V_9 -> V_20 -> V_164 = F_68 ( V_104 ) ;
V_9 -> V_20 -> V_82 = V_9 ;
V_9 -> V_20 -> V_165 = & V_166 ;
V_9 -> V_20 -> V_167 = & V_54 -> V_108 ;
V_9 -> V_104 = V_104 ;
F_87 ( V_54 ) ;
if ( F_62 ( V_54 , V_168 ) )
F_102 ( V_9 -> V_20 , 1 ) ;
V_54 -> V_122 -> V_123 ( V_54 , F_66 ( struct V_99 , V_117 ) ,
& V_144 , sizeof( V_144 ) ) ;
if ( ( V_124 ) V_144 != V_144 ) {
F_75 ( & V_54 -> V_108 , L_1 ,
( unsigned long long ) V_144 ) ;
V_144 = ( V_124 ) - 1 ;
}
F_79 ( V_9 -> V_20 , V_144 ) ;
F_103 ( V_60 , V_9 -> V_14 - 2 ) ;
F_104 ( V_60 , V_169 ) ;
F_105 ( V_60 , - 1U ) ;
V_83 = F_65 ( V_54 , V_170 ,
F_66 ( struct V_99 , V_171 ) ,
& V_145 ) ;
if ( ! V_83 )
F_106 ( V_60 , V_145 ) ;
else
F_106 ( V_60 , - 1U ) ;
V_83 = F_65 ( V_54 , V_172 ,
F_66 ( struct V_99 , V_146 ) ,
& V_146 ) ;
if ( ! V_83 )
F_107 ( V_60 , V_146 ) ;
else
V_146 = F_76 ( V_60 ) ;
V_83 = F_65 ( V_54 , V_173 ,
F_66 ( struct V_99 , V_149 ) ,
& V_149 ) ;
if ( ! V_83 && V_149 )
F_108 ( V_60 ,
V_146 * ( 1 << V_149 ) ) ;
V_83 = F_65 ( V_54 , V_173 ,
F_66 ( struct V_99 , V_150 ) ,
& V_150 ) ;
if ( ! V_83 && V_150 )
F_109 ( V_60 , V_146 * V_150 ) ;
V_83 = F_65 ( V_54 , V_173 ,
F_66 ( struct V_99 , V_148 ) ,
& V_148 ) ;
if ( ! V_83 && V_148 )
F_110 ( V_60 , V_146 * V_148 ) ;
V_83 = F_65 ( V_54 , V_173 ,
F_66 ( struct V_99 , V_147 ) ,
& V_147 ) ;
if ( ! V_83 && V_147 )
F_111 ( V_60 , V_146 * V_147 ) ;
F_112 ( V_9 -> V_20 ) ;
V_83 = F_113 ( F_114 ( V_9 -> V_20 ) , & V_174 ) ;
if ( V_83 )
goto V_175;
if ( F_62 ( V_54 , V_136 ) )
V_83 = F_113 ( F_114 ( V_9 -> V_20 ) ,
& V_176 ) ;
else
V_83 = F_113 ( F_114 ( V_9 -> V_20 ) ,
& V_177 ) ;
if ( V_83 )
goto V_175;
return 0 ;
V_175:
F_115 ( V_9 -> V_20 ) ;
F_116 ( V_9 -> V_20 -> V_21 ) ;
V_160:
F_117 ( V_9 -> V_20 ) ;
V_159:
F_118 ( V_9 -> V_11 ) ;
V_158:
V_54 -> V_122 -> V_178 ( V_54 ) ;
V_156:
F_119 ( V_9 ) ;
V_155:
F_120 ( & V_151 , V_104 ) ;
V_15:
return V_83 ;
}
static void T_10 F_121 ( struct V_114 * V_54 )
{
struct V_8 * V_9 = V_54 -> V_55 ;
int V_104 = V_9 -> V_104 ;
F_74 ( & V_9 -> V_119 ) ;
V_9 -> V_120 = false ;
F_81 ( & V_9 -> V_119 ) ;
F_115 ( V_9 -> V_20 ) ;
F_116 ( V_9 -> V_20 -> V_21 ) ;
V_54 -> V_122 -> V_179 ( V_54 ) ;
F_122 ( & V_9 -> V_113 ) ;
F_117 ( V_9 -> V_20 ) ;
F_118 ( V_9 -> V_11 ) ;
V_54 -> V_122 -> V_178 ( V_54 ) ;
F_119 ( V_9 ) ;
F_120 ( & V_151 , V_104 ) ;
}
static int F_123 ( struct V_114 * V_54 )
{
struct V_8 * V_9 = V_54 -> V_55 ;
V_54 -> V_122 -> V_179 ( V_54 ) ;
F_74 ( & V_9 -> V_119 ) ;
V_9 -> V_120 = false ;
F_81 ( & V_9 -> V_119 ) ;
F_122 ( & V_9 -> V_113 ) ;
F_8 ( V_9 -> V_20 -> V_21 -> V_22 ) ;
F_50 ( V_9 -> V_20 -> V_21 ) ;
F_10 ( V_9 -> V_20 -> V_21 -> V_22 ) ;
F_124 ( V_9 -> V_20 -> V_21 ) ;
V_54 -> V_122 -> V_178 ( V_54 ) ;
return 0 ;
}
static int F_125 ( struct V_114 * V_54 )
{
struct V_8 * V_9 = V_54 -> V_55 ;
int V_180 ;
V_9 -> V_120 = true ;
V_180 = F_83 ( V_54 -> V_55 ) ;
if ( ! V_180 ) {
F_8 ( V_9 -> V_20 -> V_21 -> V_22 ) ;
F_38 ( V_9 -> V_20 -> V_21 ) ;
F_10 ( V_9 -> V_20 -> V_21 -> V_22 ) ;
}
return V_180 ;
}
static int T_11 F_126 ( void )
{
int error ;
V_51 = F_127 ( L_6 , 0 , 0 ) ;
if ( ! V_51 )
return - V_76 ;
V_163 = F_128 ( 0 , L_7 ) ;
if ( V_163 < 0 ) {
error = V_163 ;
goto V_181;
}
error = F_129 ( & V_8 ) ;
if ( error )
goto V_182;
return 0 ;
V_182:
F_130 ( V_163 , L_7 ) ;
V_181:
F_131 ( V_51 ) ;
return error ;
}
static void T_12 F_132 ( void )
{
F_130 ( V_163 , L_7 ) ;
F_133 ( & V_8 ) ;
F_131 ( V_51 ) ;
}
