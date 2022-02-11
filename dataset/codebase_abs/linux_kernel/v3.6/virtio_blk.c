static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 ;
unsigned int V_9 ;
unsigned long V_10 ;
F_2 ( V_4 -> V_11 -> V_12 -> V_13 , V_10 ) ;
while ( ( V_8 = F_3 ( V_4 -> V_2 , & V_9 ) ) != NULL ) {
int error ;
switch ( V_8 -> V_14 ) {
case V_15 :
error = 0 ;
break;
case V_16 :
error = - V_17 ;
break;
default:
error = - V_18 ;
break;
}
switch ( V_8 -> V_19 -> V_20 ) {
case V_21 :
V_8 -> V_19 -> V_22 = V_8 -> V_23 . V_24 ;
V_8 -> V_19 -> V_25 = V_8 -> V_23 . V_25 ;
V_8 -> V_19 -> V_26 = V_8 -> V_23 . V_26 ;
break;
case V_27 :
V_8 -> V_19 -> V_26 = ( error != 0 ) ;
break;
default:
break;
}
F_4 ( V_8 -> V_19 , error ) ;
F_5 ( V_8 , V_4 -> V_28 ) ;
}
F_6 ( V_4 -> V_11 -> V_12 ) ;
F_7 ( V_4 -> V_11 -> V_12 -> V_13 , V_10 ) ;
}
static bool F_8 ( struct V_29 * V_30 , struct V_3 * V_4 ,
struct V_31 * V_19 )
{
unsigned long V_32 , V_33 = 0 , V_34 = 0 ;
struct V_7 * V_8 ;
V_8 = F_9 ( V_4 -> V_28 , V_35 ) ;
if ( ! V_8 )
return false ;
V_8 -> V_19 = V_19 ;
if ( V_19 -> V_36 & V_37 ) {
V_8 -> V_38 . type = V_39 ;
V_8 -> V_38 . V_40 = 0 ;
V_8 -> V_38 . V_41 = F_10 ( V_8 -> V_19 ) ;
} else {
switch ( V_19 -> V_20 ) {
case V_42 :
V_8 -> V_38 . type = 0 ;
V_8 -> V_38 . V_40 = F_11 ( V_8 -> V_19 ) ;
V_8 -> V_38 . V_41 = F_10 ( V_8 -> V_19 ) ;
break;
case V_21 :
V_8 -> V_38 . type = V_43 ;
V_8 -> V_38 . V_40 = 0 ;
V_8 -> V_38 . V_41 = F_10 ( V_8 -> V_19 ) ;
break;
case V_27 :
V_8 -> V_38 . type = V_44 ;
V_8 -> V_38 . V_40 = 0 ;
V_8 -> V_38 . V_41 = F_10 ( V_8 -> V_19 ) ;
break;
default:
F_12 () ;
}
}
F_13 ( & V_4 -> V_45 [ V_33 ++ ] , & V_8 -> V_38 , sizeof( V_8 -> V_38 ) ) ;
if ( V_8 -> V_19 -> V_20 == V_21 )
F_13 ( & V_4 -> V_45 [ V_33 ++ ] , V_8 -> V_19 -> V_46 , V_8 -> V_19 -> V_47 ) ;
V_32 = F_14 ( V_30 , V_8 -> V_19 , V_4 -> V_45 + V_33 ) ;
if ( V_8 -> V_19 -> V_20 == V_21 ) {
F_13 ( & V_4 -> V_45 [ V_32 + V_33 + V_34 ++ ] , V_8 -> V_19 -> V_48 , V_49 ) ;
F_13 ( & V_4 -> V_45 [ V_32 + V_33 + V_34 ++ ] , & V_8 -> V_23 ,
sizeof( V_8 -> V_23 ) ) ;
}
F_13 ( & V_4 -> V_45 [ V_32 + V_33 + V_34 ++ ] , & V_8 -> V_14 ,
sizeof( V_8 -> V_14 ) ) ;
if ( V_32 ) {
if ( F_15 ( V_8 -> V_19 ) == V_50 ) {
V_8 -> V_38 . type |= V_51 ;
V_33 += V_32 ;
} else {
V_8 -> V_38 . type |= V_52 ;
V_34 += V_32 ;
}
}
if ( F_16 ( V_4 -> V_2 , V_4 -> V_45 , V_33 , V_34 , V_8 , V_35 ) < 0 ) {
F_5 ( V_8 , V_4 -> V_28 ) ;
return false ;
}
return true ;
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_53 ;
struct V_31 * V_19 ;
unsigned int V_54 = 0 ;
while ( ( V_19 = F_18 ( V_30 ) ) != NULL ) {
F_19 ( V_19 -> V_55 + 2 > V_4 -> V_56 ) ;
if ( ! F_8 ( V_30 , V_4 , V_19 ) ) {
F_20 ( V_30 ) ;
break;
}
F_21 ( V_19 ) ;
V_54 ++ ;
}
if ( V_54 )
F_22 ( V_4 -> V_2 ) ;
}
static int F_23 ( struct V_57 * V_11 , char * V_58 )
{
struct V_3 * V_4 = V_11 -> V_59 ;
struct V_31 * V_19 ;
struct V_60 * V_60 ;
int V_61 ;
V_60 = F_24 ( V_4 -> V_11 -> V_12 , V_58 , V_62 ,
V_63 ) ;
if ( F_25 ( V_60 ) )
return F_26 ( V_60 ) ;
V_19 = F_27 ( V_4 -> V_11 -> V_12 , V_60 , V_63 ) ;
if ( F_25 ( V_19 ) ) {
F_28 ( V_60 ) ;
return F_26 ( V_19 ) ;
}
V_19 -> V_20 = V_27 ;
V_61 = F_29 ( V_4 -> V_11 -> V_12 , V_4 -> V_11 , V_19 , false ) ;
F_30 ( V_19 ) ;
return V_61 ;
}
static int F_31 ( struct V_64 * V_65 , T_1 V_66 ,
unsigned int V_46 , unsigned long V_67 )
{
struct V_57 * V_11 = V_65 -> V_68 ;
struct V_3 * V_4 = V_11 -> V_59 ;
if ( ! F_32 ( V_4 -> V_5 , V_69 ) )
return - V_17 ;
return F_33 ( V_65 , V_66 , V_46 ,
( void V_70 * ) V_67 ) ;
}
static int F_34 ( struct V_64 * V_71 , struct V_72 * V_73 )
{
struct V_3 * V_4 = V_71 -> V_68 -> V_59 ;
struct V_74 V_75 ;
int V_61 ;
V_61 = F_35 ( V_4 -> V_5 , V_76 ,
F_36 ( struct V_77 , V_78 ) ,
& V_75 ) ;
if ( ! V_61 ) {
V_73 -> V_79 = V_75 . V_79 ;
V_73 -> V_80 = V_75 . V_80 ;
V_73 -> V_81 = V_75 . V_81 ;
} else {
V_73 -> V_79 = 1 << 6 ;
V_73 -> V_80 = 1 << 5 ;
V_73 -> V_81 = F_37 ( V_71 -> V_68 ) >> 11 ;
}
return 0 ;
}
static int F_38 ( int V_82 )
{
return V_82 << V_83 ;
}
static int F_39 ( int V_84 )
{
return V_84 >> V_83 ;
}
static T_2 F_40 ( struct V_85 * V_86 ,
struct V_87 * V_88 , char * V_89 )
{
struct V_57 * V_11 = F_41 ( V_86 ) ;
int V_61 ;
F_42 ( V_90 < V_62 ) ;
V_89 [ V_62 ] = '\0' ;
V_61 = F_23 ( V_11 , V_89 ) ;
if ( ! V_61 )
return strlen ( V_89 ) ;
if ( V_61 == - V_18 )
return 0 ;
return V_61 ;
}
static void F_43 ( struct V_91 * V_92 )
{
struct V_3 * V_4 =
F_44 ( V_92 , struct V_3 , V_93 ) ;
struct V_94 * V_5 = V_4 -> V_5 ;
struct V_29 * V_30 = V_4 -> V_11 -> V_12 ;
char V_95 [ 10 ] , V_96 [ 10 ] ;
T_3 V_97 , V_98 ;
F_45 ( & V_4 -> V_99 ) ;
if ( ! V_4 -> V_100 )
goto V_101;
V_5 -> V_102 -> V_103 ( V_5 , F_36 ( struct V_77 , V_97 ) ,
& V_97 , sizeof( V_97 ) ) ;
if ( ( V_104 ) V_97 != V_97 ) {
F_46 ( & V_5 -> V_86 , L_1 ,
( unsigned long long ) V_97 ) ;
V_97 = ( V_104 ) - 1 ;
}
V_98 = V_97 * F_47 ( V_30 ) ;
F_48 ( V_98 , V_105 , V_95 , sizeof( V_95 ) ) ;
F_48 ( V_98 , V_106 , V_96 , sizeof( V_96 ) ) ;
F_49 ( & V_5 -> V_86 ,
L_2 ,
( unsigned long long ) V_97 ,
F_47 ( V_30 ) ,
V_96 , V_95 ) ;
F_50 ( V_4 -> V_11 , V_97 ) ;
F_51 ( V_4 -> V_11 ) ;
V_101:
F_52 ( & V_4 -> V_99 ) ;
}
static void F_53 ( struct V_94 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
F_54 ( V_107 , & V_4 -> V_93 ) ;
}
static int F_55 ( struct V_3 * V_4 )
{
int V_61 = 0 ;
V_4 -> V_2 = F_56 ( V_4 -> V_5 , F_1 , L_3 ) ;
if ( F_25 ( V_4 -> V_2 ) )
V_61 = F_26 ( V_4 -> V_2 ) ;
return V_61 ;
}
static int F_57 ( char * V_108 , int V_82 , char * V_89 , int V_109 )
{
const int V_110 = 'z' - 'a' + 1 ;
char * V_111 = V_89 + strlen ( V_108 ) ;
char * V_112 = V_89 + V_109 ;
char * V_113 ;
int V_114 ;
V_113 = V_112 - 1 ;
* V_113 = '\0' ;
V_114 = V_110 ;
do {
if ( V_113 == V_111 )
return - V_115 ;
* -- V_113 = 'a' + ( V_82 % V_114 ) ;
V_82 = ( V_82 / V_114 ) - 1 ;
} while ( V_82 >= 0 );
memmove ( V_111 , V_113 , V_112 - V_113 ) ;
memcpy ( V_89 , V_108 , strlen ( V_108 ) ) ;
return 0 ;
}
static int F_58 ( struct V_94 * V_5 )
{
T_4 V_116 ;
int V_61 ;
V_61 = F_35 ( V_5 , V_117 ,
F_36 ( struct V_77 , V_118 ) ,
& V_116 ) ;
if ( V_61 )
V_116 = F_32 ( V_5 , V_119 ) ;
return V_116 ;
}
static void F_59 ( struct V_94 * V_5 )
{
T_4 V_116 = F_58 ( V_5 ) ;
struct V_3 * V_4 = V_5 -> V_6 ;
if ( V_116 )
F_60 ( V_4 -> V_11 -> V_12 , V_37 ) ;
else
F_60 ( V_4 -> V_11 -> V_12 , 0 ) ;
F_51 ( V_4 -> V_11 ) ;
}
static T_2
F_61 ( struct V_85 * V_86 , struct V_87 * V_88 ,
const char * V_89 , T_5 V_120 )
{
struct V_57 * V_11 = F_41 ( V_86 ) ;
struct V_3 * V_4 = V_11 -> V_59 ;
struct V_94 * V_5 = V_4 -> V_5 ;
int V_121 ;
T_4 V_116 ;
F_19 ( ! F_32 ( V_4 -> V_5 , V_117 ) ) ;
for ( V_121 = F_62 ( V_122 ) ; -- V_121 >= 0 ; )
if ( F_63 ( V_89 , V_122 [ V_121 ] ) )
break;
if ( V_121 < 0 )
return - V_115 ;
V_116 = V_121 ;
V_5 -> V_102 -> V_123 ( V_5 ,
F_36 ( struct V_77 , V_118 ) ,
& V_116 , sizeof( V_116 ) ) ;
F_59 ( V_5 ) ;
return V_120 ;
}
static T_2
F_64 ( struct V_85 * V_86 , struct V_87 * V_88 ,
char * V_89 )
{
struct V_57 * V_11 = F_41 ( V_86 ) ;
struct V_3 * V_4 = V_11 -> V_59 ;
T_4 V_116 = F_58 ( V_4 -> V_5 ) ;
F_19 ( V_116 >= F_62 ( V_122 ) ) ;
return snprintf ( V_89 , 40 , L_4 , V_122 [ V_116 ] ) ;
}
static int T_6 F_65 ( struct V_94 * V_5 )
{
struct V_3 * V_4 ;
struct V_29 * V_30 ;
int V_61 , V_82 ;
T_3 V_124 ;
T_7 V_125 , V_126 , V_56 , V_127 ;
T_8 V_128 ;
T_4 V_129 , V_130 ;
V_61 = F_66 ( & V_131 , 0 , F_39 ( 1 << V_132 ) ,
V_63 ) ;
if ( V_61 < 0 )
goto V_33;
V_82 = V_61 ;
V_61 = F_35 ( V_5 , V_133 ,
F_36 ( struct V_77 , V_134 ) ,
& V_56 ) ;
if ( V_61 || ! V_56 )
V_56 = 1 ;
V_56 += 2 ;
V_5 -> V_6 = V_4 = F_67 ( sizeof( * V_4 ) +
sizeof( V_4 -> V_45 [ 0 ] ) * V_56 , V_63 ) ;
if ( ! V_4 ) {
V_61 = - V_135 ;
goto V_136;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_56 = V_56 ;
F_68 ( V_4 -> V_45 , V_4 -> V_56 ) ;
F_69 ( & V_4 -> V_99 ) ;
F_70 ( & V_4 -> V_93 , F_43 ) ;
V_4 -> V_100 = true ;
V_61 = F_55 ( V_4 ) ;
if ( V_61 )
goto V_137;
V_4 -> V_28 = F_71 ( 1 , sizeof( struct V_7 ) ) ;
if ( ! V_4 -> V_28 ) {
V_61 = - V_135 ;
goto V_138;
}
V_4 -> V_11 = F_72 ( 1 << V_83 ) ;
if ( ! V_4 -> V_11 ) {
V_61 = - V_135 ;
goto V_139;
}
V_30 = V_4 -> V_11 -> V_12 = F_73 ( F_17 , NULL ) ;
if ( ! V_30 ) {
V_61 = - V_135 ;
goto V_140;
}
V_30 -> V_53 = V_4 ;
F_57 ( L_5 , V_82 , V_4 -> V_11 -> V_141 , V_142 ) ;
V_4 -> V_11 -> V_143 = V_143 ;
V_4 -> V_11 -> V_144 = F_38 ( V_82 ) ;
V_4 -> V_11 -> V_59 = V_4 ;
V_4 -> V_11 -> V_145 = & V_146 ;
V_4 -> V_11 -> V_147 = & V_5 -> V_86 ;
V_4 -> V_82 = V_82 ;
F_59 ( V_5 ) ;
if ( F_32 ( V_5 , V_148 ) )
F_74 ( V_4 -> V_11 , 1 ) ;
V_5 -> V_102 -> V_103 ( V_5 , F_36 ( struct V_77 , V_97 ) ,
& V_124 , sizeof( V_124 ) ) ;
if ( ( V_104 ) V_124 != V_124 ) {
F_46 ( & V_5 -> V_86 , L_1 ,
( unsigned long long ) V_124 ) ;
V_124 = ( V_104 ) - 1 ;
}
F_50 ( V_4 -> V_11 , V_124 ) ;
F_75 ( V_30 , V_4 -> V_56 - 2 ) ;
F_76 ( V_30 , V_149 ) ;
F_77 ( V_30 , - 1U ) ;
V_61 = F_35 ( V_5 , V_150 ,
F_36 ( struct V_77 , V_151 ) ,
& V_125 ) ;
if ( ! V_61 )
F_78 ( V_30 , V_125 ) ;
else
F_78 ( V_30 , - 1U ) ;
V_61 = F_35 ( V_5 , V_152 ,
F_36 ( struct V_77 , V_126 ) ,
& V_126 ) ;
if ( ! V_61 )
F_79 ( V_30 , V_126 ) ;
else
V_126 = F_47 ( V_30 ) ;
V_61 = F_35 ( V_5 , V_153 ,
F_36 ( struct V_77 , V_129 ) ,
& V_129 ) ;
if ( ! V_61 && V_129 )
F_80 ( V_30 ,
V_126 * ( 1 << V_129 ) ) ;
V_61 = F_35 ( V_5 , V_153 ,
F_36 ( struct V_77 , V_130 ) ,
& V_130 ) ;
if ( ! V_61 && V_130 )
F_81 ( V_30 , V_126 * V_130 ) ;
V_61 = F_35 ( V_5 , V_153 ,
F_36 ( struct V_77 , V_128 ) ,
& V_128 ) ;
if ( ! V_61 && V_128 )
F_82 ( V_30 , V_126 * V_128 ) ;
V_61 = F_35 ( V_5 , V_153 ,
F_36 ( struct V_77 , V_127 ) ,
& V_127 ) ;
if ( ! V_61 && V_127 )
F_83 ( V_30 , V_126 * V_127 ) ;
F_84 ( V_4 -> V_11 ) ;
V_61 = F_85 ( F_86 ( V_4 -> V_11 ) , & V_154 ) ;
if ( V_61 )
goto V_155;
if ( F_32 ( V_5 , V_117 ) )
V_61 = F_85 ( F_86 ( V_4 -> V_11 ) ,
& V_156 ) ;
else
V_61 = F_85 ( F_86 ( V_4 -> V_11 ) ,
& V_157 ) ;
if ( V_61 )
goto V_155;
return 0 ;
V_155:
F_87 ( V_4 -> V_11 ) ;
F_88 ( V_4 -> V_11 -> V_12 ) ;
V_140:
F_89 ( V_4 -> V_11 ) ;
V_139:
F_90 ( V_4 -> V_28 ) ;
V_138:
V_5 -> V_102 -> V_158 ( V_5 ) ;
V_137:
F_91 ( V_4 ) ;
V_136:
F_92 ( & V_131 , V_82 ) ;
V_33:
return V_61 ;
}
static void T_9 F_93 ( struct V_94 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
int V_82 = V_4 -> V_82 ;
F_45 ( & V_4 -> V_99 ) ;
V_4 -> V_100 = false ;
F_52 ( & V_4 -> V_99 ) ;
F_87 ( V_4 -> V_11 ) ;
F_88 ( V_4 -> V_11 -> V_12 ) ;
V_5 -> V_102 -> V_159 ( V_5 ) ;
F_94 ( & V_4 -> V_93 ) ;
F_89 ( V_4 -> V_11 ) ;
F_90 ( V_4 -> V_28 ) ;
V_5 -> V_102 -> V_158 ( V_5 ) ;
F_91 ( V_4 ) ;
F_92 ( & V_131 , V_82 ) ;
}
static int F_95 ( struct V_94 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
V_5 -> V_102 -> V_159 ( V_5 ) ;
F_45 ( & V_4 -> V_99 ) ;
V_4 -> V_100 = false ;
F_52 ( & V_4 -> V_99 ) ;
F_94 ( & V_4 -> V_93 ) ;
F_96 ( V_4 -> V_11 -> V_12 -> V_13 ) ;
F_20 ( V_4 -> V_11 -> V_12 ) ;
F_97 ( V_4 -> V_11 -> V_12 -> V_13 ) ;
F_98 ( V_4 -> V_11 -> V_12 ) ;
V_5 -> V_102 -> V_158 ( V_5 ) ;
return 0 ;
}
static int F_99 ( struct V_94 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
int V_160 ;
V_4 -> V_100 = true ;
V_160 = F_55 ( V_5 -> V_6 ) ;
if ( ! V_160 ) {
F_96 ( V_4 -> V_11 -> V_12 -> V_13 ) ;
F_6 ( V_4 -> V_11 -> V_12 ) ;
F_97 ( V_4 -> V_11 -> V_12 -> V_13 ) ;
}
return V_160 ;
}
static int T_10 F_100 ( void )
{
int error ;
V_107 = F_101 ( L_6 , 0 , 0 ) ;
if ( ! V_107 )
return - V_135 ;
V_143 = F_102 ( 0 , L_7 ) ;
if ( V_143 < 0 ) {
error = V_143 ;
goto V_161;
}
error = F_103 ( & V_3 ) ;
if ( error )
goto V_162;
return 0 ;
V_162:
F_104 ( V_143 , L_7 ) ;
V_161:
F_105 ( V_107 ) ;
return error ;
}
static void T_11 F_106 ( void )
{
F_104 ( V_143 , L_7 ) ;
F_107 ( & V_3 ) ;
F_105 ( V_107 ) ;
}
