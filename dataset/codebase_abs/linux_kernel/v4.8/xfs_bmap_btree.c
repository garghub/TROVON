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
if ( F_3 ( & V_13 -> V_20 ) )
F_4 ( V_13 , V_10 , V_21 ,
V_22 , 0 , 0 , V_6 -> V_23 ,
V_24 | V_25 ) ;
else
F_4 ( V_13 , V_10 , V_21 ,
V_26 , 0 , 0 , V_6 -> V_23 ,
V_24 ) ;
V_10 -> V_27 = V_7 -> V_27 ;
ASSERT ( F_5 ( V_10 -> V_27 ) > 0 ) ;
V_10 -> V_28 = V_7 -> V_28 ;
V_15 = F_6 ( V_8 , 0 ) ;
V_16 = F_7 ( V_7 , 1 ) ;
V_18 = F_8 ( V_13 , V_10 , 1 ) ;
V_17 = F_9 ( V_7 , 1 , V_15 ) ;
V_19 = F_10 ( V_13 , V_10 , 1 , V_11 ) ;
V_15 = F_5 ( V_7 -> V_28 ) ;
memcpy ( V_18 , V_16 , sizeof( * V_16 ) * V_15 ) ;
memcpy ( V_19 , V_17 , sizeof( * V_17 ) * V_15 ) ;
}
STATIC void
F_11 (
T_6 V_29 ,
T_6 V_30 ,
T_7 * V_31 )
{
int V_32 ;
T_1 V_33 ;
V_32 = ( int ) ( V_29 >> ( 64 - V_34 ) ) ;
V_31 -> V_35 = ( ( V_36 ) V_29 &
F_12 ( 64 - V_34 ) ) >> 9 ;
V_31 -> V_37 = ( ( ( V_38 ) V_29 & F_12 ( 9 ) ) << 43 ) |
( ( ( V_38 ) V_30 ) >> 21 ) ;
V_31 -> V_39 = ( T_2 ) ( V_30 & F_12 ( 21 ) ) ;
if ( V_32 ) {
ASSERT ( V_31 -> V_39 != 0 ) ;
V_33 = V_3 ;
} else
V_33 = V_4 ;
V_31 -> V_40 = V_33 ;
}
void
F_13 (
T_8 * V_41 ,
T_7 * V_31 )
{
F_11 ( V_41 -> V_29 , V_41 -> V_30 , V_31 ) ;
}
T_2
F_14 (
T_8 * V_41 )
{
return ( T_2 ) ( V_41 -> V_30 & F_12 ( 21 ) ) ;
}
V_38
F_15 (
T_8 * V_41 )
{
return ( ( ( V_38 ) V_41 -> V_29 & F_12 ( 9 ) ) << 43 ) |
( ( ( V_38 ) V_41 -> V_30 ) >> 21 ) ;
}
V_36
F_16 (
T_8 * V_41 )
{
return ( ( V_36 ) V_41 -> V_29 &
F_12 ( 64 - V_34 ) ) >> 9 ;
}
T_1
F_17 (
T_8 * V_41 )
{
int V_32 ;
V_32 = ( int ) ( ( V_41 -> V_29 ) >> ( 64 - V_34 ) ) ;
return F_1 ( F_14 ( V_41 ) ,
V_32 ) ;
}
T_2
F_18 (
T_9 * V_41 )
{
return ( T_2 ) ( F_19 ( V_41 -> V_30 ) & F_12 ( 21 ) ) ;
}
V_36
F_20 (
T_9 * V_41 )
{
return ( ( V_36 ) F_19 ( V_41 -> V_29 ) &
F_12 ( 64 - V_34 ) ) >> 9 ;
}
void
F_21 (
T_8 * V_41 ,
V_36 V_42 ,
V_38 V_43 ,
T_2 V_44 ,
T_1 V_45 )
{
int V_2 = ( V_45 == V_4 ) ? 0 : 1 ;
ASSERT ( V_45 == V_4 || V_45 == V_3 ) ;
ASSERT ( ( V_42 & F_22 ( 64 - V_46 ) ) == 0 ) ;
ASSERT ( ( V_44 & F_22 ( 64 - V_47 ) ) == 0 ) ;
ASSERT ( ( V_43 & F_22 ( 64 - V_48 ) ) == 0 ) ;
V_41 -> V_29 = ( ( V_49 ) V_2 << 63 ) |
( ( V_49 ) V_42 << 9 ) |
( ( V_49 ) V_43 >> 43 ) ;
V_41 -> V_30 = ( ( V_49 ) V_43 << 21 ) |
( ( V_49 ) V_44 &
( V_49 ) F_12 ( 21 ) ) ;
}
void
F_23 (
T_8 * V_41 ,
T_7 * V_31 )
{
F_21 ( V_41 , V_31 -> V_35 , V_31 -> V_37 ,
V_31 -> V_39 , V_31 -> V_40 ) ;
}
void
F_24 (
T_9 * V_41 ,
V_36 V_42 ,
V_38 V_43 ,
T_2 V_44 ,
T_1 V_45 )
{
int V_2 = ( V_45 == V_4 ) ? 0 : 1 ;
ASSERT ( V_45 == V_4 || V_45 == V_3 ) ;
ASSERT ( ( V_42 & F_22 ( 64 - V_46 ) ) == 0 ) ;
ASSERT ( ( V_44 & F_22 ( 64 - V_47 ) ) == 0 ) ;
ASSERT ( ( V_43 & F_22 ( 64 - V_48 ) ) == 0 ) ;
V_41 -> V_29 = F_25 (
( ( V_49 ) V_2 << 63 ) |
( ( V_49 ) V_42 << 9 ) |
( ( V_49 ) V_43 >> 43 ) ) ;
V_41 -> V_30 = F_25 (
( ( V_49 ) V_43 << 21 ) |
( ( V_49 ) V_44 &
( V_49 ) F_12 ( 21 ) ) ) ;
}
STATIC void
F_26 (
T_9 * V_41 ,
T_7 * V_31 )
{
F_24 ( V_41 , V_31 -> V_35 , V_31 -> V_37 ,
V_31 -> V_39 , V_31 -> V_40 ) ;
}
void
F_27 (
T_8 * V_41 ,
T_2 V_50 )
{
ASSERT ( ( V_50 & F_22 ( 43 ) ) == 0 ) ;
V_41 -> V_30 = ( V_41 -> V_30 & ( V_49 ) F_22 ( 43 ) ) |
( V_49 ) ( V_50 & F_12 ( 21 ) ) ;
}
void
F_28 (
T_8 * V_41 ,
V_38 V_50 )
{
ASSERT ( ( V_50 & F_22 ( 12 ) ) == 0 ) ;
V_41 -> V_29 = ( V_41 -> V_29 & ( V_49 ) F_22 ( 55 ) ) |
( V_49 ) ( V_50 >> 43 ) ;
V_41 -> V_30 = ( V_41 -> V_30 & ( V_49 ) F_12 ( 21 ) ) |
( V_49 ) ( V_50 << 21 ) ;
}
void
F_29 (
T_8 * V_41 ,
V_36 V_50 )
{
ASSERT ( ( V_50 & F_22 ( 9 ) ) == 0 ) ;
V_41 -> V_29 = ( V_41 -> V_29 & ( V_49 ) F_22 ( 1 ) ) |
( ( V_49 ) V_50 << 9 ) |
( V_41 -> V_29 & ( V_49 ) F_12 ( 9 ) ) ;
}
void
F_30 (
T_8 * V_41 ,
T_1 V_50 )
{
ASSERT ( V_50 == V_4 || V_50 == V_3 ) ;
if ( V_50 == V_4 )
V_41 -> V_29 &= F_12 ( 64 - V_34 ) ;
else
V_41 -> V_29 |= F_22 ( V_34 ) ;
}
void
F_31 (
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
if ( F_3 ( & V_13 -> V_20 ) ) {
ASSERT ( V_10 -> V_51 == F_32 ( V_22 ) ) ;
ASSERT ( F_33 ( & V_10 -> V_52 . V_53 . V_54 ,
& V_13 -> V_20 . V_55 ) ) ;
ASSERT ( V_10 -> V_52 . V_53 . V_56 ==
F_25 ( V_21 ) ) ;
} else
ASSERT ( V_10 -> V_51 == F_32 ( V_26 ) ) ;
ASSERT ( V_10 -> V_52 . V_53 . V_57 == F_25 ( V_58 ) ) ;
ASSERT ( V_10 -> V_52 . V_53 . V_59 == F_25 ( V_58 ) ) ;
ASSERT ( V_10 -> V_27 != 0 ) ;
V_7 -> V_27 = V_10 -> V_27 ;
V_7 -> V_28 = V_10 -> V_28 ;
V_15 = F_6 ( V_8 , 0 ) ;
V_16 = F_8 ( V_13 , V_10 , 1 ) ;
V_18 = F_7 ( V_7 , 1 ) ;
V_17 = F_10 ( V_13 , V_10 , 1 , V_11 ) ;
V_19 = F_9 ( V_7 , 1 , V_15 ) ;
V_15 = F_5 ( V_7 -> V_28 ) ;
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
if ( ( V_63 -> V_29 >>
( 64 - V_34 ) ) != 0 ) {
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
F_40 ( & args . V_86 , V_65 -> V_69 . V_70 . V_6 -> V_23 ,
V_65 -> V_69 . V_70 . V_71 ) ;
if ( args . V_85 == V_58 ) {
args . V_85 = F_19 ( V_82 -> V_53 ) ;
args . type = V_87 ;
args . V_88 = args . V_84 -> V_89 ;
} else if ( V_65 -> V_69 . V_70 . V_73 -> V_90 ) {
args . type = V_87 ;
} else {
args . type = V_91 ;
}
args . V_92 = args . V_93 = args . V_94 = 1 ;
args . V_95 = V_65 -> V_69 . V_70 . V_74 & V_96 ;
if ( ! args . V_95 && args . V_84 -> V_89 == 0 ) {
error = - V_97 ;
goto V_98;
}
error = F_41 ( & args ) ;
if ( error )
goto V_98;
if ( args . V_85 == V_58 && args . V_88 ) {
args . V_85 = 0 ;
args . type = V_99 ;
args . V_88 = 0 ;
error = F_41 ( & args ) ;
if ( error )
goto V_98;
V_65 -> V_69 . V_70 . V_73 -> V_90 = true ;
}
if ( args . V_85 == V_58 ) {
F_42 ( V_65 , V_100 ) ;
* V_83 = 0 ;
return 0 ;
}
ASSERT ( args . V_101 == 1 ) ;
V_65 -> V_69 . V_70 . V_72 = args . V_85 ;
V_65 -> V_69 . V_70 . V_80 ++ ;
V_65 -> V_69 . V_70 . V_6 -> V_77 . V_102 ++ ;
F_43 ( args . V_84 , V_65 -> V_69 . V_70 . V_6 , V_103 ) ;
F_44 ( args . V_84 , V_65 -> V_69 . V_70 . V_6 ,
V_104 , 1L ) ;
V_66 -> V_53 = F_25 ( args . V_85 ) ;
F_42 ( V_65 , V_100 ) ;
* V_83 = 1 ;
return 0 ;
V_98:
F_42 ( V_65 , V_105 ) ;
return error ;
}
STATIC int
F_45 (
struct V_64 * V_65 ,
struct V_106 * V_107 )
{
struct V_12 * V_13 = V_65 -> V_67 ;
struct V_5 * V_6 = V_65 -> V_69 . V_70 . V_6 ;
struct V_108 * V_84 = V_65 -> V_68 ;
V_38 V_85 = F_46 ( V_13 , F_47 ( V_107 ) ) ;
struct V_109 V_86 ;
F_40 ( & V_86 , V_6 -> V_23 , V_65 -> V_69 . V_70 . V_71 ) ;
F_48 ( V_13 , V_65 -> V_69 . V_70 . V_73 , V_85 , 1 , & V_86 ) ;
V_6 -> V_77 . V_102 -- ;
F_43 ( V_84 , V_6 , V_103 ) ;
F_44 ( V_84 , V_6 , V_104 , - 1L ) ;
return 0 ;
}
STATIC int
F_49 (
struct V_64 * V_65 ,
int V_110 )
{
if ( V_110 == V_65 -> V_111 - 1 ) {
struct V_112 * V_60 ;
V_60 = F_50 ( V_65 -> V_69 . V_70 . V_6 ,
V_65 -> V_69 . V_70 . V_71 ) ;
return F_51 ( V_65 -> V_67 ,
V_60 -> V_113 , V_110 == 0 ) / 2 ;
}
return V_65 -> V_67 -> V_114 [ V_110 != 0 ] ;
}
int
F_52 (
struct V_64 * V_65 ,
int V_110 )
{
if ( V_110 == V_65 -> V_111 - 1 ) {
struct V_112 * V_60 ;
V_60 = F_50 ( V_65 -> V_69 . V_70 . V_6 ,
V_65 -> V_69 . V_70 . V_71 ) ;
return F_51 ( V_65 -> V_67 ,
V_60 -> V_113 , V_110 == 0 ) ;
}
return V_65 -> V_67 -> V_115 [ V_110 != 0 ] ;
}
STATIC int
F_53 (
struct V_64 * V_65 ,
int V_110 )
{
if ( V_110 != V_65 -> V_111 - 1 )
return V_65 -> V_67 -> V_115 [ V_110 != 0 ] ;
return F_6 ( V_65 -> V_69 . V_70 . V_116 , V_110 == 0 ) ;
}
STATIC void
F_54 (
union V_117 * V_118 ,
union V_119 * V_120 )
{
V_118 -> V_121 . V_35 =
F_25 ( F_20 ( & V_120 -> V_121 ) ) ;
}
STATIC void
F_55 (
struct V_64 * V_65 ,
union V_119 * V_120 )
{
F_26 ( & V_120 -> V_121 , & V_65 -> V_122 . V_70 ) ;
}
STATIC void
F_56 (
struct V_64 * V_65 ,
union V_81 * V_123 )
{
V_123 -> V_53 = 0 ;
}
STATIC T_13
F_57 (
struct V_64 * V_65 ,
union V_117 * V_118 )
{
return ( T_13 ) F_19 ( V_118 -> V_121 . V_35 ) -
V_65 -> V_122 . V_70 . V_35 ;
}
static bool
F_58 (
struct V_106 * V_107 )
{
struct V_12 * V_13 = V_107 -> V_124 -> V_125 ;
struct V_9 * V_126 = F_59 ( V_107 ) ;
unsigned int V_110 ;
switch ( V_126 -> V_51 ) {
case F_32 ( V_22 ) :
if ( ! F_3 ( & V_13 -> V_20 ) )
return false ;
if ( ! F_33 ( & V_126 -> V_52 . V_53 . V_54 , & V_13 -> V_20 . V_55 ) )
return false ;
if ( F_19 ( V_126 -> V_52 . V_53 . V_56 ) != V_107 -> V_127 )
return false ;
if ( F_19 ( V_126 -> V_52 . V_53 . V_128 ) == 0 )
return false ;
case F_32 ( V_26 ) :
break;
default:
return false ;
}
V_110 = F_5 ( V_126 -> V_27 ) ;
if ( V_110 > F_60 ( V_13 -> V_129 [ 0 ] , V_13 -> V_129 [ 1 ] ) )
return false ;
if ( F_5 ( V_126 -> V_28 ) > V_13 -> V_115 [ V_110 != 0 ] )
return false ;
if ( ! V_126 -> V_52 . V_53 . V_57 ||
( V_126 -> V_52 . V_53 . V_57 != F_25 ( V_58 ) &&
! F_61 ( V_13 , F_19 ( V_126 -> V_52 . V_53 . V_57 ) ) ) )
return false ;
if ( ! V_126 -> V_52 . V_53 . V_59 ||
( V_126 -> V_52 . V_53 . V_59 != F_25 ( V_58 ) &&
! F_61 ( V_13 , F_19 ( V_126 -> V_52 . V_53 . V_59 ) ) ) )
return false ;
return true ;
}
static void
F_62 (
struct V_106 * V_107 )
{
if ( ! F_63 ( V_107 ) )
F_64 ( V_107 , - V_130 ) ;
else if ( ! F_58 ( V_107 ) )
F_64 ( V_107 , - V_131 ) ;
if ( V_107 -> V_132 ) {
F_65 ( V_107 , V_133 ) ;
F_66 ( V_107 ) ;
}
}
static void
F_67 (
struct V_106 * V_107 )
{
if ( ! F_58 ( V_107 ) ) {
F_65 ( V_107 , V_133 ) ;
F_64 ( V_107 , - V_131 ) ;
F_66 ( V_107 ) ;
return;
}
F_68 ( V_107 ) ;
}
STATIC int
F_69 (
struct V_64 * V_65 ,
union V_117 * V_134 ,
union V_117 * V_135 )
{
return F_19 ( V_134 -> V_121 . V_35 ) <
F_19 ( V_135 -> V_121 . V_35 ) ;
}
STATIC int
F_70 (
struct V_64 * V_65 ,
union V_119 * V_136 ,
union V_119 * V_137 )
{
return F_20 ( & V_136 -> V_121 ) +
F_18 ( & V_136 -> V_121 ) <=
F_20 ( & V_137 -> V_121 ) ;
}
struct V_64 *
F_37 (
struct V_12 * V_13 ,
struct V_108 * V_84 ,
struct V_5 * V_6 ,
int V_71 )
{
struct V_112 * V_60 = F_50 ( V_6 , V_71 ) ;
struct V_64 * V_65 ;
V_65 = F_71 ( V_138 , V_139 ) ;
V_65 -> V_68 = V_84 ;
V_65 -> V_67 = V_13 ;
V_65 -> V_111 = F_5 ( V_60 -> V_140 -> V_27 ) + 1 ;
V_65 -> V_141 = V_142 ;
V_65 -> V_143 = V_13 -> V_20 . V_144 ;
V_65 -> V_145 = & V_146 ;
V_65 -> V_147 = V_24 | V_148 ;
if ( F_3 ( & V_13 -> V_20 ) )
V_65 -> V_147 |= V_25 ;
V_65 -> V_69 . V_70 . V_116 = F_72 ( V_6 , V_71 ) ;
V_65 -> V_69 . V_70 . V_6 = V_6 ;
V_65 -> V_69 . V_70 . V_72 = V_58 ;
V_65 -> V_69 . V_70 . V_73 = NULL ;
V_65 -> V_69 . V_70 . V_80 = 0 ;
V_65 -> V_69 . V_70 . V_74 = 0 ;
V_65 -> V_69 . V_70 . V_71 = V_71 ;
return V_65 ;
}
int
F_51 (
struct V_12 * V_13 ,
int V_149 ,
int V_150 )
{
V_149 -= F_73 ( V_13 ) ;
if ( V_150 )
return V_149 / sizeof( T_9 ) ;
return V_149 / ( sizeof( T_4 ) + sizeof( V_151 ) ) ;
}
int
F_6 (
int V_149 ,
int V_150 )
{
V_149 -= sizeof( T_3 ) ;
if ( V_150 )
return V_149 / sizeof( V_152 ) ;
return V_149 / ( sizeof( V_153 ) + sizeof( V_154 ) ) ;
}
int
F_74 (
struct V_108 * V_84 ,
struct V_5 * V_6 ,
int V_71 ,
T_14 V_155 ,
struct V_156 * V_157 )
{
struct V_64 * V_65 ;
int error ;
ASSERT ( V_84 || V_157 ) ;
ASSERT ( ! ( V_84 && V_157 ) ) ;
if ( V_71 == V_158 )
ASSERT ( V_6 -> V_77 . V_159 == V_160 ) ;
else
ASSERT ( V_6 -> V_77 . V_161 == V_160 ) ;
V_65 = F_37 ( V_6 -> V_14 , V_84 , V_6 , V_71 ) ;
if ( ! V_65 )
return - V_162 ;
error = F_75 ( V_65 , V_155 , V_157 ) ;
F_76 ( V_65 , error ? V_163 : V_164 ) ;
return error ;
}
