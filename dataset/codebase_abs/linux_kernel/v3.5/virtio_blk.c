static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 ;
unsigned int V_9 ;
unsigned long V_10 ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
while ( ( V_8 = F_3 ( V_4 -> V_2 , & V_9 ) ) != NULL ) {
int error ;
switch ( V_8 -> V_12 ) {
case V_13 :
error = 0 ;
break;
case V_14 :
error = - V_15 ;
break;
default:
error = - V_16 ;
break;
}
switch ( V_8 -> V_17 -> V_18 ) {
case V_19 :
V_8 -> V_17 -> V_20 = V_8 -> V_21 . V_22 ;
V_8 -> V_17 -> V_23 = V_8 -> V_21 . V_23 ;
V_8 -> V_17 -> V_24 = V_8 -> V_21 . V_24 ;
break;
case V_25 :
V_8 -> V_17 -> V_24 = ( error != 0 ) ;
break;
default:
break;
}
F_4 ( V_8 -> V_17 , error ) ;
F_5 ( V_8 , V_4 -> V_26 ) ;
}
F_6 ( V_4 -> V_27 -> V_28 ) ;
F_7 ( & V_4 -> V_11 , V_10 ) ;
}
static bool F_8 ( struct V_29 * V_30 , struct V_3 * V_4 ,
struct V_31 * V_17 )
{
unsigned long V_32 , V_33 = 0 , V_34 = 0 ;
struct V_7 * V_8 ;
V_8 = F_9 ( V_4 -> V_26 , V_35 ) ;
if ( ! V_8 )
return false ;
V_8 -> V_17 = V_17 ;
if ( V_17 -> V_36 & V_37 ) {
V_8 -> V_38 . type = V_39 ;
V_8 -> V_38 . V_40 = 0 ;
V_8 -> V_38 . V_41 = F_10 ( V_8 -> V_17 ) ;
} else {
switch ( V_17 -> V_18 ) {
case V_42 :
V_8 -> V_38 . type = 0 ;
V_8 -> V_38 . V_40 = F_11 ( V_8 -> V_17 ) ;
V_8 -> V_38 . V_41 = F_10 ( V_8 -> V_17 ) ;
break;
case V_19 :
V_8 -> V_38 . type = V_43 ;
V_8 -> V_38 . V_40 = 0 ;
V_8 -> V_38 . V_41 = F_10 ( V_8 -> V_17 ) ;
break;
case V_25 :
V_8 -> V_38 . type = V_44 ;
V_8 -> V_38 . V_40 = 0 ;
V_8 -> V_38 . V_41 = F_10 ( V_8 -> V_17 ) ;
break;
default:
F_12 () ;
}
}
F_13 ( & V_4 -> V_45 [ V_33 ++ ] , & V_8 -> V_38 , sizeof( V_8 -> V_38 ) ) ;
if ( V_8 -> V_17 -> V_18 == V_19 )
F_13 ( & V_4 -> V_45 [ V_33 ++ ] , V_8 -> V_17 -> V_46 , V_8 -> V_17 -> V_47 ) ;
V_32 = F_14 ( V_30 , V_8 -> V_17 , V_4 -> V_45 + V_33 ) ;
if ( V_8 -> V_17 -> V_18 == V_19 ) {
F_13 ( & V_4 -> V_45 [ V_32 + V_33 + V_34 ++ ] , V_8 -> V_17 -> V_48 , V_49 ) ;
F_13 ( & V_4 -> V_45 [ V_32 + V_33 + V_34 ++ ] , & V_8 -> V_21 ,
sizeof( V_8 -> V_21 ) ) ;
}
F_13 ( & V_4 -> V_45 [ V_32 + V_33 + V_34 ++ ] , & V_8 -> V_12 ,
sizeof( V_8 -> V_12 ) ) ;
if ( V_32 ) {
if ( F_15 ( V_8 -> V_17 ) == V_50 ) {
V_8 -> V_38 . type |= V_51 ;
V_33 += V_32 ;
} else {
V_8 -> V_38 . type |= V_52 ;
V_34 += V_32 ;
}
}
if ( F_16 ( V_4 -> V_2 , V_4 -> V_45 , V_33 , V_34 , V_8 , V_35 ) < 0 ) {
F_5 ( V_8 , V_4 -> V_26 ) ;
return false ;
}
return true ;
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_53 ;
struct V_31 * V_17 ;
unsigned int V_54 = 0 ;
while ( ( V_17 = F_18 ( V_30 ) ) != NULL ) {
F_19 ( V_17 -> V_55 + 2 > V_4 -> V_56 ) ;
if ( ! F_8 ( V_30 , V_4 , V_17 ) ) {
F_20 ( V_30 ) ;
break;
}
F_21 ( V_17 ) ;
V_54 ++ ;
}
if ( V_54 )
F_22 ( V_4 -> V_2 ) ;
}
static int F_23 ( struct V_57 * V_27 , char * V_58 )
{
struct V_3 * V_4 = V_27 -> V_59 ;
struct V_31 * V_17 ;
struct V_60 * V_60 ;
int V_61 ;
V_60 = F_24 ( V_4 -> V_27 -> V_28 , V_58 , V_62 ,
V_63 ) ;
if ( F_25 ( V_60 ) )
return F_26 ( V_60 ) ;
V_17 = F_27 ( V_4 -> V_27 -> V_28 , V_60 , V_63 ) ;
if ( F_25 ( V_17 ) ) {
F_28 ( V_60 ) ;
return F_26 ( V_17 ) ;
}
V_17 -> V_18 = V_25 ;
V_61 = F_29 ( V_4 -> V_27 -> V_28 , V_4 -> V_27 , V_17 , false ) ;
F_30 ( V_17 ) ;
return V_61 ;
}
static int F_31 ( struct V_64 * V_65 , T_1 V_66 ,
unsigned int V_46 , unsigned long V_67 )
{
struct V_57 * V_27 = V_65 -> V_68 ;
struct V_3 * V_4 = V_27 -> V_59 ;
if ( ! F_32 ( V_4 -> V_5 , V_69 ) )
return - V_15 ;
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
struct V_57 * V_27 = F_41 ( V_86 ) ;
int V_61 ;
F_42 ( V_90 < V_62 ) ;
V_89 [ V_62 ] = '\0' ;
V_61 = F_23 ( V_27 , V_89 ) ;
if ( ! V_61 )
return strlen ( V_89 ) ;
if ( V_61 == - V_16 )
return 0 ;
return V_61 ;
}
static void F_43 ( struct V_91 * V_92 )
{
struct V_3 * V_4 =
F_44 ( V_92 , struct V_3 , V_93 ) ;
struct V_94 * V_5 = V_4 -> V_5 ;
struct V_29 * V_30 = V_4 -> V_27 -> V_28 ;
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
F_50 ( V_4 -> V_27 , V_97 ) ;
F_51 ( V_4 -> V_27 ) ;
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
static int T_4 F_58 ( struct V_94 * V_5 )
{
struct V_3 * V_4 ;
struct V_29 * V_30 ;
int V_61 , V_82 ;
T_3 V_116 ;
T_5 V_117 , V_118 , V_56 , V_119 ;
T_6 V_120 ;
T_7 V_121 , V_122 ;
V_61 = F_59 ( & V_123 , 0 , F_39 ( 1 << V_124 ) ,
V_63 ) ;
if ( V_61 < 0 )
goto V_33;
V_82 = V_61 ;
V_61 = F_35 ( V_5 , V_125 ,
F_36 ( struct V_77 , V_126 ) ,
& V_56 ) ;
if ( V_61 || ! V_56 )
V_56 = 1 ;
V_56 += 2 ;
V_5 -> V_6 = V_4 = F_60 ( sizeof( * V_4 ) +
sizeof( V_4 -> V_45 [ 0 ] ) * V_56 , V_63 ) ;
if ( ! V_4 ) {
V_61 = - V_127 ;
goto V_128;
}
F_61 ( & V_4 -> V_11 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_56 = V_56 ;
F_62 ( V_4 -> V_45 , V_4 -> V_56 ) ;
F_63 ( & V_4 -> V_99 ) ;
F_64 ( & V_4 -> V_93 , F_43 ) ;
V_4 -> V_100 = true ;
V_61 = F_55 ( V_4 ) ;
if ( V_61 )
goto V_129;
V_4 -> V_26 = F_65 ( 1 , sizeof( struct V_7 ) ) ;
if ( ! V_4 -> V_26 ) {
V_61 = - V_127 ;
goto V_130;
}
V_4 -> V_27 = F_66 ( 1 << V_83 ) ;
if ( ! V_4 -> V_27 ) {
V_61 = - V_127 ;
goto V_131;
}
V_30 = V_4 -> V_27 -> V_28 = F_67 ( F_17 , & V_4 -> V_11 ) ;
if ( ! V_30 ) {
V_61 = - V_127 ;
goto V_132;
}
V_30 -> V_53 = V_4 ;
F_57 ( L_4 , V_82 , V_4 -> V_27 -> V_133 , V_134 ) ;
V_4 -> V_27 -> V_135 = V_135 ;
V_4 -> V_27 -> V_136 = F_38 ( V_82 ) ;
V_4 -> V_27 -> V_59 = V_4 ;
V_4 -> V_27 -> V_137 = & V_138 ;
V_4 -> V_27 -> V_139 = & V_5 -> V_86 ;
V_4 -> V_82 = V_82 ;
if ( F_32 ( V_5 , V_140 ) )
F_68 ( V_30 , V_37 ) ;
if ( F_32 ( V_5 , V_141 ) )
F_69 ( V_4 -> V_27 , 1 ) ;
V_5 -> V_102 -> V_103 ( V_5 , F_36 ( struct V_77 , V_97 ) ,
& V_116 , sizeof( V_116 ) ) ;
if ( ( V_104 ) V_116 != V_116 ) {
F_46 ( & V_5 -> V_86 , L_1 ,
( unsigned long long ) V_116 ) ;
V_116 = ( V_104 ) - 1 ;
}
F_50 ( V_4 -> V_27 , V_116 ) ;
F_70 ( V_30 , V_4 -> V_56 - 2 ) ;
F_71 ( V_30 , V_142 ) ;
F_72 ( V_30 , - 1U ) ;
V_61 = F_35 ( V_5 , V_143 ,
F_36 ( struct V_77 , V_144 ) ,
& V_117 ) ;
if ( ! V_61 )
F_73 ( V_30 , V_117 ) ;
else
F_73 ( V_30 , - 1U ) ;
V_61 = F_35 ( V_5 , V_145 ,
F_36 ( struct V_77 , V_118 ) ,
& V_118 ) ;
if ( ! V_61 )
F_74 ( V_30 , V_118 ) ;
else
V_118 = F_47 ( V_30 ) ;
V_61 = F_35 ( V_5 , V_146 ,
F_36 ( struct V_77 , V_121 ) ,
& V_121 ) ;
if ( ! V_61 && V_121 )
F_75 ( V_30 ,
V_118 * ( 1 << V_121 ) ) ;
V_61 = F_35 ( V_5 , V_146 ,
F_36 ( struct V_77 , V_122 ) ,
& V_122 ) ;
if ( ! V_61 && V_122 )
F_76 ( V_30 , V_118 * V_122 ) ;
V_61 = F_35 ( V_5 , V_146 ,
F_36 ( struct V_77 , V_120 ) ,
& V_120 ) ;
if ( ! V_61 && V_120 )
F_77 ( V_30 , V_118 * V_120 ) ;
V_61 = F_35 ( V_5 , V_146 ,
F_36 ( struct V_77 , V_119 ) ,
& V_119 ) ;
if ( ! V_61 && V_119 )
F_78 ( V_30 , V_118 * V_119 ) ;
F_79 ( V_4 -> V_27 ) ;
V_61 = F_80 ( F_81 ( V_4 -> V_27 ) , & V_147 ) ;
if ( V_61 )
goto V_148;
return 0 ;
V_148:
F_82 ( V_4 -> V_27 ) ;
F_83 ( V_4 -> V_27 -> V_28 ) ;
V_132:
F_84 ( V_4 -> V_27 ) ;
V_131:
F_85 ( V_4 -> V_26 ) ;
V_130:
V_5 -> V_102 -> V_149 ( V_5 ) ;
V_129:
F_86 ( V_4 ) ;
V_128:
F_87 ( & V_123 , V_82 ) ;
V_33:
return V_61 ;
}
static void T_8 F_88 ( struct V_94 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
int V_82 = V_4 -> V_82 ;
struct V_7 * V_8 ;
unsigned long V_10 ;
F_45 ( & V_4 -> V_99 ) ;
V_4 -> V_100 = false ;
F_52 ( & V_4 -> V_99 ) ;
V_5 -> V_102 -> V_150 ( V_5 ) ;
F_89 ( & V_4 -> V_93 ) ;
F_82 ( V_4 -> V_27 ) ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
while ( ( V_8 = F_90 ( V_4 -> V_2 ) ) ) {
F_4 ( V_8 -> V_17 , - V_16 ) ;
F_5 ( V_8 , V_4 -> V_26 ) ;
}
F_7 ( & V_4 -> V_11 , V_10 ) ;
F_83 ( V_4 -> V_27 -> V_28 ) ;
F_84 ( V_4 -> V_27 ) ;
F_85 ( V_4 -> V_26 ) ;
V_5 -> V_102 -> V_149 ( V_5 ) ;
F_86 ( V_4 ) ;
F_87 ( & V_123 , V_82 ) ;
}
static int F_91 ( struct V_94 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
V_5 -> V_102 -> V_150 ( V_5 ) ;
F_45 ( & V_4 -> V_99 ) ;
V_4 -> V_100 = false ;
F_52 ( & V_4 -> V_99 ) ;
F_89 ( & V_4 -> V_93 ) ;
F_92 ( V_4 -> V_27 -> V_28 -> V_151 ) ;
F_20 ( V_4 -> V_27 -> V_28 ) ;
F_93 ( V_4 -> V_27 -> V_28 -> V_151 ) ;
F_94 ( V_4 -> V_27 -> V_28 ) ;
V_5 -> V_102 -> V_149 ( V_5 ) ;
return 0 ;
}
static int F_95 ( struct V_94 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
int V_152 ;
V_4 -> V_100 = true ;
V_152 = F_55 ( V_5 -> V_6 ) ;
if ( ! V_152 ) {
F_92 ( V_4 -> V_27 -> V_28 -> V_151 ) ;
F_6 ( V_4 -> V_27 -> V_28 ) ;
F_93 ( V_4 -> V_27 -> V_28 -> V_151 ) ;
}
return V_152 ;
}
static int T_9 F_96 ( void )
{
int error ;
V_107 = F_97 ( L_5 , 0 , 0 ) ;
if ( ! V_107 )
return - V_127 ;
V_135 = F_98 ( 0 , L_6 ) ;
if ( V_135 < 0 ) {
error = V_135 ;
goto V_153;
}
error = F_99 ( & V_3 ) ;
if ( error )
goto V_154;
return 0 ;
V_154:
F_100 ( V_135 , L_6 ) ;
V_153:
F_101 ( V_107 ) ;
return error ;
}
static void T_10 F_102 ( void )
{
F_100 ( V_135 , L_6 ) ;
F_103 ( & V_3 ) ;
F_101 ( V_107 ) ;
}
