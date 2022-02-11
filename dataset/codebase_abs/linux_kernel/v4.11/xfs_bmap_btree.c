STATIC T_1
F_1 (
T_2 V_1 ,
int V_2 )
{
if ( V_2 ) {
ASSERT ( V_1 != 0 ) ;
return V_3 ;
}
return V_4 ;
}
void
F_2 (
struct V_5 * V_6 ,
T_3 * V_7 ,
int V_8 ,
struct V_9 * V_10 ,
int V_11 )
{
struct V_12 * V_13 = V_6 -> V_14 ;
int V_15 ;
T_4 * V_16 ;
T_5 * V_17 ;
T_4 * V_18 ;
T_5 * V_19 ;
F_3 ( V_13 , V_10 , V_20 ,
V_21 , 0 , 0 , V_6 -> V_22 ,
V_23 ) ;
V_10 -> V_24 = V_7 -> V_24 ;
ASSERT ( F_4 ( V_10 -> V_24 ) > 0 ) ;
V_10 -> V_25 = V_7 -> V_25 ;
V_15 = F_5 ( V_8 , 0 ) ;
V_16 = F_6 ( V_7 , 1 ) ;
V_18 = F_7 ( V_13 , V_10 , 1 ) ;
V_17 = F_8 ( V_7 , 1 , V_15 ) ;
V_19 = F_9 ( V_13 , V_10 , 1 , V_11 ) ;
V_15 = F_4 ( V_7 -> V_25 ) ;
memcpy ( V_18 , V_16 , sizeof( * V_16 ) * V_15 ) ;
memcpy ( V_19 , V_17 , sizeof( * V_17 ) * V_15 ) ;
}
STATIC void
F_10 (
T_6 V_26 ,
T_6 V_27 ,
T_7 * V_28 )
{
int V_29 ;
T_1 V_30 ;
V_29 = ( int ) ( V_26 >> ( 64 - V_31 ) ) ;
V_28 -> V_32 = ( ( V_33 ) V_26 &
F_11 ( 64 - V_31 ) ) >> 9 ;
V_28 -> V_34 = ( ( ( V_35 ) V_26 & F_11 ( 9 ) ) << 43 ) |
( ( ( V_35 ) V_27 ) >> 21 ) ;
V_28 -> V_36 = ( T_2 ) ( V_27 & F_11 ( 21 ) ) ;
if ( V_29 ) {
ASSERT ( V_28 -> V_36 != 0 ) ;
V_30 = V_3 ;
} else
V_30 = V_4 ;
V_28 -> V_37 = V_30 ;
}
void
F_12 (
T_8 * V_38 ,
T_7 * V_28 )
{
F_10 ( V_38 -> V_26 , V_38 -> V_27 , V_28 ) ;
}
T_2
F_13 (
T_8 * V_38 )
{
return ( T_2 ) ( V_38 -> V_27 & F_11 ( 21 ) ) ;
}
V_35
F_14 (
T_8 * V_38 )
{
return ( ( ( V_35 ) V_38 -> V_26 & F_11 ( 9 ) ) << 43 ) |
( ( ( V_35 ) V_38 -> V_27 ) >> 21 ) ;
}
V_33
F_15 (
T_8 * V_38 )
{
return ( ( V_33 ) V_38 -> V_26 &
F_11 ( 64 - V_31 ) ) >> 9 ;
}
T_1
F_16 (
T_8 * V_38 )
{
int V_29 ;
V_29 = ( int ) ( ( V_38 -> V_26 ) >> ( 64 - V_31 ) ) ;
return F_1 ( F_13 ( V_38 ) ,
V_29 ) ;
}
T_2
F_17 (
T_9 * V_38 )
{
return ( T_2 ) ( F_18 ( V_38 -> V_27 ) & F_11 ( 21 ) ) ;
}
V_33
F_19 (
T_9 * V_38 )
{
return ( ( V_33 ) F_18 ( V_38 -> V_26 ) &
F_11 ( 64 - V_31 ) ) >> 9 ;
}
void
F_20 (
T_8 * V_38 ,
V_33 V_39 ,
V_35 V_40 ,
T_2 V_41 ,
T_1 V_42 )
{
int V_2 = ( V_42 == V_4 ) ? 0 : 1 ;
ASSERT ( V_42 == V_4 || V_42 == V_3 ) ;
ASSERT ( ( V_39 & F_21 ( 64 - V_43 ) ) == 0 ) ;
ASSERT ( ( V_41 & F_21 ( 64 - V_44 ) ) == 0 ) ;
ASSERT ( ( V_40 & F_21 ( 64 - V_45 ) ) == 0 ) ;
V_38 -> V_26 = ( ( V_46 ) V_2 << 63 ) |
( ( V_46 ) V_39 << 9 ) |
( ( V_46 ) V_40 >> 43 ) ;
V_38 -> V_27 = ( ( V_46 ) V_40 << 21 ) |
( ( V_46 ) V_41 &
( V_46 ) F_11 ( 21 ) ) ;
}
void
F_22 (
T_8 * V_38 ,
T_7 * V_28 )
{
F_20 ( V_38 , V_28 -> V_32 , V_28 -> V_34 ,
V_28 -> V_36 , V_28 -> V_37 ) ;
}
void
F_23 (
T_9 * V_38 ,
V_33 V_39 ,
V_35 V_40 ,
T_2 V_41 ,
T_1 V_42 )
{
int V_2 = ( V_42 == V_4 ) ? 0 : 1 ;
ASSERT ( V_42 == V_4 || V_42 == V_3 ) ;
ASSERT ( ( V_39 & F_21 ( 64 - V_43 ) ) == 0 ) ;
ASSERT ( ( V_41 & F_21 ( 64 - V_44 ) ) == 0 ) ;
ASSERT ( ( V_40 & F_21 ( 64 - V_45 ) ) == 0 ) ;
V_38 -> V_26 = F_24 (
( ( V_46 ) V_2 << 63 ) |
( ( V_46 ) V_39 << 9 ) |
( ( V_46 ) V_40 >> 43 ) ) ;
V_38 -> V_27 = F_24 (
( ( V_46 ) V_40 << 21 ) |
( ( V_46 ) V_41 &
( V_46 ) F_11 ( 21 ) ) ) ;
}
STATIC void
F_25 (
T_9 * V_38 ,
T_7 * V_28 )
{
F_23 ( V_38 , V_28 -> V_32 , V_28 -> V_34 ,
V_28 -> V_36 , V_28 -> V_37 ) ;
}
void
F_26 (
T_8 * V_38 ,
T_2 V_47 )
{
ASSERT ( ( V_47 & F_21 ( 43 ) ) == 0 ) ;
V_38 -> V_27 = ( V_38 -> V_27 & ( V_46 ) F_21 ( 43 ) ) |
( V_46 ) ( V_47 & F_11 ( 21 ) ) ;
}
void
F_27 (
T_8 * V_38 ,
V_35 V_47 )
{
ASSERT ( ( V_47 & F_21 ( 12 ) ) == 0 ) ;
V_38 -> V_26 = ( V_38 -> V_26 & ( V_46 ) F_21 ( 55 ) ) |
( V_46 ) ( V_47 >> 43 ) ;
V_38 -> V_27 = ( V_38 -> V_27 & ( V_46 ) F_11 ( 21 ) ) |
( V_46 ) ( V_47 << 21 ) ;
}
void
F_28 (
T_8 * V_38 ,
V_33 V_47 )
{
ASSERT ( ( V_47 & F_21 ( 9 ) ) == 0 ) ;
V_38 -> V_26 = ( V_38 -> V_26 & ( V_46 ) F_21 ( 1 ) ) |
( ( V_46 ) V_47 << 9 ) |
( V_38 -> V_26 & ( V_46 ) F_11 ( 9 ) ) ;
}
void
F_29 (
T_8 * V_38 ,
T_1 V_47 )
{
ASSERT ( V_47 == V_4 || V_47 == V_3 ) ;
if ( V_47 == V_4 )
V_38 -> V_26 &= F_11 ( 64 - V_31 ) ;
else
V_38 -> V_26 |= F_21 ( V_31 ) ;
}
void
F_30 (
struct V_12 * V_13 ,
struct V_9 * V_10 ,
int V_11 ,
T_3 * V_7 ,
int V_8 )
{
int V_15 ;
T_4 * V_16 ;
T_5 * V_17 ;
T_4 * V_18 ;
T_5 * V_19 ;
if ( F_31 ( & V_13 -> V_48 ) ) {
ASSERT ( V_10 -> V_49 == F_32 ( V_50 ) ) ;
ASSERT ( F_33 ( & V_10 -> V_51 . V_52 . V_53 ,
& V_13 -> V_48 . V_54 ) ) ;
ASSERT ( V_10 -> V_51 . V_52 . V_55 ==
F_24 ( V_20 ) ) ;
} else
ASSERT ( V_10 -> V_49 == F_32 ( V_56 ) ) ;
ASSERT ( V_10 -> V_51 . V_52 . V_57 == F_24 ( V_58 ) ) ;
ASSERT ( V_10 -> V_51 . V_52 . V_59 == F_24 ( V_58 ) ) ;
ASSERT ( V_10 -> V_24 != 0 ) ;
V_7 -> V_24 = V_10 -> V_24 ;
V_7 -> V_25 = V_10 -> V_25 ;
V_15 = F_5 ( V_8 , 0 ) ;
V_16 = F_7 ( V_13 , V_10 , 1 ) ;
V_18 = F_6 ( V_7 , 1 ) ;
V_17 = F_9 ( V_13 , V_10 , 1 , V_11 ) ;
V_19 = F_8 ( V_7 , 1 , V_15 ) ;
V_15 = F_4 ( V_7 -> V_25 ) ;
memcpy ( V_18 , V_16 , sizeof( * V_16 ) * V_15 ) ;
memcpy ( V_19 , V_17 , sizeof( * V_17 ) * V_15 ) ;
}
int
F_34 (
T_10 * V_60 ,
T_11 V_61 ,
T_11 V_62 )
{
for (; V_62 > 0 ; V_62 -- , V_61 ++ ) {
T_8 * V_63 = F_35 ( V_60 , V_61 ) ;
if ( ( V_63 -> V_26 >>
( 64 - V_31 ) ) != 0 ) {
ASSERT ( 0 ) ;
return 1 ;
}
}
return 0 ;
}
STATIC struct V_64 *
F_36 (
struct V_64 * V_65 )
{
struct V_64 * V_66 ;
V_66 = F_37 ( V_65 -> V_67 , V_65 -> V_68 ,
V_65 -> V_69 . V_70 . V_6 , V_65 -> V_69 . V_70 . V_71 ) ;
V_66 -> V_69 . V_70 . V_72 = V_65 -> V_69 . V_70 . V_72 ;
V_66 -> V_69 . V_70 . V_73 = V_65 -> V_69 . V_70 . V_73 ;
V_66 -> V_69 . V_70 . V_74 = V_65 -> V_69 . V_70 . V_74 ;
return V_66 ;
}
STATIC void
F_38 (
struct V_64 * V_75 ,
struct V_64 * V_76 )
{
ASSERT ( ( V_76 -> V_69 . V_70 . V_72 != V_58 ) ||
( V_76 -> V_69 . V_70 . V_6 -> V_77 . V_78 & V_79 ) ) ;
ASSERT ( V_76 -> V_69 . V_70 . V_73 == V_75 -> V_69 . V_70 . V_73 ) ;
V_76 -> V_69 . V_70 . V_80 += V_75 -> V_69 . V_70 . V_80 ;
V_76 -> V_69 . V_70 . V_72 = V_75 -> V_69 . V_70 . V_72 ;
V_75 -> V_69 . V_70 . V_80 = 0 ;
}
STATIC int
F_39 (
struct V_64 * V_65 ,
union V_81 * V_82 ,
union V_81 * V_66 ,
int * V_83 )
{
T_12 args ;
int error ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_84 = V_65 -> V_68 ;
args . V_13 = V_65 -> V_67 ;
args . V_85 = V_65 -> V_69 . V_70 . V_72 ;
args . V_72 = args . V_85 ;
F_40 ( & args . V_86 , V_65 -> V_69 . V_70 . V_6 -> V_22 ,
V_65 -> V_69 . V_70 . V_71 ) ;
if ( args . V_85 == V_58 ) {
args . V_85 = F_18 ( V_82 -> V_52 ) ;
args . type = V_87 ;
V_88:
args . V_89 = args . V_84 -> V_90 ;
} else if ( V_65 -> V_69 . V_70 . V_73 -> V_91 ) {
args . type = V_87 ;
} else {
args . type = V_92 ;
}
args . V_93 = args . V_94 = args . V_95 = 1 ;
args . V_96 = V_65 -> V_69 . V_70 . V_74 & V_97 ;
if ( ! args . V_96 && args . V_84 -> V_90 == 0 ) {
error = - V_98 ;
goto V_99;
}
error = F_41 ( & args ) ;
if ( error )
goto V_99;
if ( F_42 ( & V_65 -> V_67 -> V_48 ) &&
args . V_85 == V_58 &&
args . type == V_92 ) {
args . V_85 = V_65 -> V_69 . V_70 . V_72 ;
args . type = V_100 ;
goto V_88;
}
if ( args . V_85 == V_58 && args . V_89 ) {
args . V_85 = 0 ;
args . type = V_100 ;
error = F_41 ( & args ) ;
if ( error )
goto V_99;
V_65 -> V_69 . V_70 . V_73 -> V_91 = true ;
}
if ( F_43 ( args . V_85 == V_58 ) ) {
F_44 ( V_65 , V_101 ) ;
* V_83 = 0 ;
return 0 ;
}
ASSERT ( args . V_102 == 1 ) ;
V_65 -> V_69 . V_70 . V_72 = args . V_85 ;
V_65 -> V_69 . V_70 . V_80 ++ ;
V_65 -> V_69 . V_70 . V_6 -> V_77 . V_103 ++ ;
F_45 ( args . V_84 , V_65 -> V_69 . V_70 . V_6 , V_104 ) ;
F_46 ( args . V_84 , V_65 -> V_69 . V_70 . V_6 ,
V_105 , 1L ) ;
V_66 -> V_52 = F_24 ( args . V_85 ) ;
F_44 ( V_65 , V_101 ) ;
* V_83 = 1 ;
return 0 ;
V_99:
F_44 ( V_65 , V_106 ) ;
return error ;
}
STATIC int
F_47 (
struct V_64 * V_65 ,
struct V_107 * V_108 )
{
struct V_12 * V_13 = V_65 -> V_67 ;
struct V_5 * V_6 = V_65 -> V_69 . V_70 . V_6 ;
struct V_109 * V_84 = V_65 -> V_68 ;
V_35 V_85 = F_48 ( V_13 , F_49 ( V_108 ) ) ;
struct V_110 V_86 ;
F_40 ( & V_86 , V_6 -> V_22 , V_65 -> V_69 . V_70 . V_71 ) ;
F_50 ( V_13 , V_65 -> V_69 . V_70 . V_73 , V_85 , 1 , & V_86 ) ;
V_6 -> V_77 . V_103 -- ;
F_45 ( V_84 , V_6 , V_104 ) ;
F_46 ( V_84 , V_6 , V_105 , - 1L ) ;
return 0 ;
}
STATIC int
F_51 (
struct V_64 * V_65 ,
int V_111 )
{
if ( V_111 == V_65 -> V_112 - 1 ) {
struct V_113 * V_60 ;
V_60 = F_52 ( V_65 -> V_69 . V_70 . V_6 ,
V_65 -> V_69 . V_70 . V_71 ) ;
return F_53 ( V_65 -> V_67 ,
V_60 -> V_114 , V_111 == 0 ) / 2 ;
}
return V_65 -> V_67 -> V_115 [ V_111 != 0 ] ;
}
int
F_54 (
struct V_64 * V_65 ,
int V_111 )
{
if ( V_111 == V_65 -> V_112 - 1 ) {
struct V_113 * V_60 ;
V_60 = F_52 ( V_65 -> V_69 . V_70 . V_6 ,
V_65 -> V_69 . V_70 . V_71 ) ;
return F_53 ( V_65 -> V_67 ,
V_60 -> V_114 , V_111 == 0 ) ;
}
return V_65 -> V_67 -> V_116 [ V_111 != 0 ] ;
}
STATIC int
F_55 (
struct V_64 * V_65 ,
int V_111 )
{
if ( V_111 != V_65 -> V_112 - 1 )
return V_65 -> V_67 -> V_116 [ V_111 != 0 ] ;
return F_5 ( V_65 -> V_69 . V_70 . V_117 , V_111 == 0 ) ;
}
STATIC void
F_56 (
union V_118 * V_119 ,
union V_120 * V_121 )
{
V_119 -> V_122 . V_32 =
F_24 ( F_19 ( & V_121 -> V_122 ) ) ;
}
STATIC void
F_57 (
struct V_64 * V_65 ,
union V_120 * V_121 )
{
F_25 ( & V_121 -> V_122 , & V_65 -> V_123 . V_70 ) ;
}
STATIC void
F_58 (
struct V_64 * V_65 ,
union V_81 * V_124 )
{
V_124 -> V_52 = 0 ;
}
STATIC T_13
F_59 (
struct V_64 * V_65 ,
union V_118 * V_119 )
{
return ( T_13 ) F_18 ( V_119 -> V_122 . V_32 ) -
V_65 -> V_123 . V_70 . V_32 ;
}
static bool
F_60 (
struct V_107 * V_108 )
{
struct V_12 * V_13 = V_108 -> V_125 -> V_126 ;
struct V_9 * V_127 = F_61 ( V_108 ) ;
unsigned int V_111 ;
switch ( V_127 -> V_49 ) {
case F_32 ( V_50 ) :
if ( ! F_31 ( & V_13 -> V_48 ) )
return false ;
if ( ! F_33 ( & V_127 -> V_51 . V_52 . V_53 , & V_13 -> V_48 . V_54 ) )
return false ;
if ( F_18 ( V_127 -> V_51 . V_52 . V_55 ) != V_108 -> V_128 )
return false ;
if ( F_18 ( V_127 -> V_51 . V_52 . V_129 ) == 0 )
return false ;
case F_32 ( V_56 ) :
break;
default:
return false ;
}
V_111 = F_4 ( V_127 -> V_24 ) ;
if ( V_111 > F_62 ( V_13 -> V_130 [ 0 ] , V_13 -> V_130 [ 1 ] ) )
return false ;
if ( F_4 ( V_127 -> V_25 ) > V_13 -> V_116 [ V_111 != 0 ] )
return false ;
if ( ! V_127 -> V_51 . V_52 . V_57 ||
( V_127 -> V_51 . V_52 . V_57 != F_24 ( V_58 ) &&
! F_63 ( V_13 , F_18 ( V_127 -> V_51 . V_52 . V_57 ) ) ) )
return false ;
if ( ! V_127 -> V_51 . V_52 . V_59 ||
( V_127 -> V_51 . V_52 . V_59 != F_24 ( V_58 ) &&
! F_63 ( V_13 , F_18 ( V_127 -> V_51 . V_52 . V_59 ) ) ) )
return false ;
return true ;
}
static void
F_64 (
struct V_107 * V_108 )
{
if ( ! F_65 ( V_108 ) )
F_66 ( V_108 , - V_131 ) ;
else if ( ! F_60 ( V_108 ) )
F_66 ( V_108 , - V_132 ) ;
if ( V_108 -> V_133 ) {
F_67 ( V_108 , V_134 ) ;
F_68 ( V_108 ) ;
}
}
static void
F_69 (
struct V_107 * V_108 )
{
if ( ! F_60 ( V_108 ) ) {
F_67 ( V_108 , V_134 ) ;
F_66 ( V_108 , - V_132 ) ;
F_68 ( V_108 ) ;
return;
}
F_70 ( V_108 ) ;
}
STATIC int
F_71 (
struct V_64 * V_65 ,
union V_118 * V_135 ,
union V_118 * V_136 )
{
return F_18 ( V_135 -> V_122 . V_32 ) <
F_18 ( V_136 -> V_122 . V_32 ) ;
}
STATIC int
F_72 (
struct V_64 * V_65 ,
union V_120 * V_137 ,
union V_120 * V_138 )
{
return F_19 ( & V_137 -> V_122 ) +
F_17 ( & V_137 -> V_122 ) <=
F_19 ( & V_138 -> V_122 ) ;
}
struct V_64 *
F_37 (
struct V_12 * V_13 ,
struct V_109 * V_84 ,
struct V_5 * V_6 ,
int V_71 )
{
struct V_113 * V_60 = F_52 ( V_6 , V_71 ) ;
struct V_64 * V_65 ;
ASSERT ( V_71 != V_139 ) ;
V_65 = F_73 ( V_140 , V_141 ) ;
V_65 -> V_68 = V_84 ;
V_65 -> V_67 = V_13 ;
V_65 -> V_112 = F_4 ( V_60 -> V_142 -> V_24 ) + 1 ;
V_65 -> V_143 = V_21 ;
V_65 -> V_144 = V_13 -> V_48 . V_145 ;
V_65 -> V_146 = F_74 ( V_147 ) ;
V_65 -> V_148 = & V_149 ;
V_65 -> V_150 = V_23 | V_151 ;
if ( F_31 ( & V_13 -> V_48 ) )
V_65 -> V_150 |= V_152 ;
V_65 -> V_69 . V_70 . V_117 = F_75 ( V_6 , V_71 ) ;
V_65 -> V_69 . V_70 . V_6 = V_6 ;
V_65 -> V_69 . V_70 . V_72 = V_58 ;
V_65 -> V_69 . V_70 . V_73 = NULL ;
V_65 -> V_69 . V_70 . V_80 = 0 ;
V_65 -> V_69 . V_70 . V_74 = 0 ;
V_65 -> V_69 . V_70 . V_71 = V_71 ;
return V_65 ;
}
int
F_53 (
struct V_12 * V_13 ,
int V_153 ,
int V_154 )
{
V_153 -= F_76 ( V_13 ) ;
if ( V_154 )
return V_153 / sizeof( T_9 ) ;
return V_153 / ( sizeof( T_4 ) + sizeof( V_155 ) ) ;
}
int
F_5 (
int V_153 ,
int V_154 )
{
V_153 -= sizeof( T_3 ) ;
if ( V_154 )
return V_153 / sizeof( V_156 ) ;
return V_153 / ( sizeof( V_157 ) + sizeof( V_158 ) ) ;
}
int
F_77 (
struct V_109 * V_84 ,
struct V_5 * V_6 ,
int V_71 ,
T_14 V_159 ,
struct V_160 * V_161 )
{
struct V_64 * V_65 ;
int error ;
ASSERT ( V_84 || V_161 ) ;
ASSERT ( ! ( V_84 && V_161 ) ) ;
if ( V_71 == V_162 )
ASSERT ( V_6 -> V_77 . V_163 == V_164 ) ;
else
ASSERT ( V_6 -> V_77 . V_165 == V_164 ) ;
V_65 = F_37 ( V_6 -> V_14 , V_84 , V_6 , V_71 ) ;
if ( ! V_65 )
return - V_166 ;
error = F_78 ( V_65 , V_159 , V_161 ) ;
F_79 ( V_65 , error ? V_167 : V_168 ) ;
return error ;
}
