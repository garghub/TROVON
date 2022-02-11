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
if ( args . V_85 == V_58 ) {
args . V_85 = F_19 ( V_82 -> V_53 ) ;
args . type = V_86 ;
args . V_87 = F_40 ( args . V_84 ) ;
} else if ( V_65 -> V_69 . V_70 . V_73 -> V_88 ) {
args . type = V_86 ;
} else {
args . type = V_89 ;
}
args . V_90 = args . V_91 = args . V_92 = 1 ;
args . V_93 = V_65 -> V_69 . V_70 . V_74 & V_94 ;
if ( ! args . V_93 && F_40 ( args . V_84 ) == 0 ) {
error = - V_95 ;
goto V_96;
}
error = F_41 ( & args ) ;
if ( error )
goto V_96;
if ( args . V_85 == V_58 && args . V_87 ) {
args . V_85 = 0 ;
args . type = V_97 ;
args . V_87 = 0 ;
error = F_41 ( & args ) ;
if ( error )
goto V_96;
V_65 -> V_69 . V_70 . V_73 -> V_88 = 1 ;
}
if ( args . V_85 == V_58 ) {
F_42 ( V_65 , V_98 ) ;
* V_83 = 0 ;
return 0 ;
}
ASSERT ( args . V_99 == 1 ) ;
V_65 -> V_69 . V_70 . V_72 = args . V_85 ;
V_65 -> V_69 . V_70 . V_80 ++ ;
V_65 -> V_69 . V_70 . V_6 -> V_77 . V_100 ++ ;
F_43 ( args . V_84 , V_65 -> V_69 . V_70 . V_6 , V_101 ) ;
F_44 ( args . V_84 , V_65 -> V_69 . V_70 . V_6 ,
V_102 , 1L ) ;
V_66 -> V_53 = F_25 ( args . V_85 ) ;
F_42 ( V_65 , V_98 ) ;
* V_83 = 1 ;
return 0 ;
V_96:
F_42 ( V_65 , V_103 ) ;
return error ;
}
STATIC int
F_45 (
struct V_64 * V_65 ,
struct V_104 * V_105 )
{
struct V_12 * V_13 = V_65 -> V_67 ;
struct V_5 * V_6 = V_65 -> V_69 . V_70 . V_6 ;
struct V_106 * V_84 = V_65 -> V_68 ;
V_38 V_85 = F_46 ( V_13 , F_47 ( V_105 ) ) ;
F_48 ( V_85 , 1 , V_65 -> V_69 . V_70 . V_73 , V_13 ) ;
V_6 -> V_77 . V_100 -- ;
F_43 ( V_84 , V_6 , V_101 ) ;
F_44 ( V_84 , V_6 , V_102 , - 1L ) ;
F_49 ( V_84 , V_105 ) ;
return 0 ;
}
STATIC int
F_50 (
struct V_64 * V_65 ,
int V_107 )
{
if ( V_107 == V_65 -> V_108 - 1 ) {
struct V_109 * V_60 ;
V_60 = F_51 ( V_65 -> V_69 . V_70 . V_6 ,
V_65 -> V_69 . V_70 . V_71 ) ;
return F_52 ( V_65 -> V_67 ,
V_60 -> V_110 , V_107 == 0 ) / 2 ;
}
return V_65 -> V_67 -> V_111 [ V_107 != 0 ] ;
}
int
F_53 (
struct V_64 * V_65 ,
int V_107 )
{
if ( V_107 == V_65 -> V_108 - 1 ) {
struct V_109 * V_60 ;
V_60 = F_51 ( V_65 -> V_69 . V_70 . V_6 ,
V_65 -> V_69 . V_70 . V_71 ) ;
return F_52 ( V_65 -> V_67 ,
V_60 -> V_110 , V_107 == 0 ) ;
}
return V_65 -> V_67 -> V_112 [ V_107 != 0 ] ;
}
STATIC int
F_54 (
struct V_64 * V_65 ,
int V_107 )
{
if ( V_107 != V_65 -> V_108 - 1 )
return V_65 -> V_67 -> V_112 [ V_107 != 0 ] ;
return F_6 ( V_65 -> V_69 . V_70 . V_113 , V_107 == 0 ) ;
}
STATIC void
F_55 (
union V_114 * V_115 ,
union V_116 * V_117 )
{
V_115 -> V_118 . V_35 =
F_25 ( F_20 ( & V_117 -> V_118 ) ) ;
}
STATIC void
F_56 (
union V_114 * V_115 ,
union V_116 * V_117 )
{
ASSERT ( V_115 -> V_118 . V_35 != 0 ) ;
F_24 ( & V_117 -> V_118 , F_19 ( V_115 -> V_118 . V_35 ) ,
0 , 0 , V_4 ) ;
}
STATIC void
F_57 (
struct V_64 * V_65 ,
union V_116 * V_117 )
{
F_26 ( & V_117 -> V_118 , & V_65 -> V_119 . V_70 ) ;
}
STATIC void
F_58 (
struct V_64 * V_65 ,
union V_81 * V_120 )
{
V_120 -> V_53 = 0 ;
}
STATIC T_13
F_59 (
struct V_64 * V_65 ,
union V_114 * V_115 )
{
return ( T_13 ) F_19 ( V_115 -> V_118 . V_35 ) -
V_65 -> V_119 . V_70 . V_35 ;
}
static bool
F_60 (
struct V_104 * V_105 )
{
struct V_12 * V_13 = V_105 -> V_121 -> V_122 ;
struct V_9 * V_123 = F_61 ( V_105 ) ;
unsigned int V_107 ;
switch ( V_123 -> V_51 ) {
case F_32 ( V_22 ) :
if ( ! F_3 ( & V_13 -> V_20 ) )
return false ;
if ( ! F_33 ( & V_123 -> V_52 . V_53 . V_54 , & V_13 -> V_20 . V_55 ) )
return false ;
if ( F_19 ( V_123 -> V_52 . V_53 . V_56 ) != V_105 -> V_124 )
return false ;
if ( F_19 ( V_123 -> V_52 . V_53 . V_125 ) == 0 )
return false ;
case F_32 ( V_26 ) :
break;
default:
return false ;
}
V_107 = F_5 ( V_123 -> V_27 ) ;
if ( V_107 > F_62 ( V_13 -> V_126 [ 0 ] , V_13 -> V_126 [ 1 ] ) )
return false ;
if ( F_5 ( V_123 -> V_28 ) > V_13 -> V_112 [ V_107 != 0 ] )
return false ;
if ( ! V_123 -> V_52 . V_53 . V_57 ||
( V_123 -> V_52 . V_53 . V_57 != F_25 ( V_58 ) &&
! F_63 ( V_13 , F_19 ( V_123 -> V_52 . V_53 . V_57 ) ) ) )
return false ;
if ( ! V_123 -> V_52 . V_53 . V_59 ||
( V_123 -> V_52 . V_53 . V_59 != F_25 ( V_58 ) &&
! F_63 ( V_13 , F_19 ( V_123 -> V_52 . V_53 . V_59 ) ) ) )
return false ;
return true ;
}
static void
F_64 (
struct V_104 * V_105 )
{
if ( ! F_65 ( V_105 ) )
F_66 ( V_105 , - V_127 ) ;
else if ( ! F_60 ( V_105 ) )
F_66 ( V_105 , - V_128 ) ;
if ( V_105 -> V_129 ) {
F_67 ( V_105 , V_130 ) ;
F_68 ( V_105 ) ;
}
}
static void
F_69 (
struct V_104 * V_105 )
{
if ( ! F_60 ( V_105 ) ) {
F_67 ( V_105 , V_130 ) ;
F_66 ( V_105 , - V_128 ) ;
F_68 ( V_105 ) ;
return;
}
F_70 ( V_105 ) ;
}
STATIC int
F_71 (
struct V_64 * V_65 ,
union V_114 * V_131 ,
union V_114 * V_132 )
{
return F_19 ( V_131 -> V_118 . V_35 ) <
F_19 ( V_132 -> V_118 . V_35 ) ;
}
STATIC int
F_72 (
struct V_64 * V_65 ,
union V_116 * V_133 ,
union V_116 * V_134 )
{
return F_20 ( & V_133 -> V_118 ) +
F_18 ( & V_133 -> V_118 ) <=
F_20 ( & V_134 -> V_118 ) ;
}
struct V_64 *
F_37 (
struct V_12 * V_13 ,
struct V_106 * V_84 ,
struct V_5 * V_6 ,
int V_71 )
{
struct V_109 * V_60 = F_51 ( V_6 , V_71 ) ;
struct V_64 * V_65 ;
V_65 = F_73 ( V_135 , V_136 ) ;
V_65 -> V_68 = V_84 ;
V_65 -> V_67 = V_13 ;
V_65 -> V_108 = F_5 ( V_60 -> V_137 -> V_27 ) + 1 ;
V_65 -> V_138 = V_139 ;
V_65 -> V_140 = V_13 -> V_20 . V_141 ;
V_65 -> V_142 = & V_143 ;
V_65 -> V_144 = V_24 | V_145 ;
if ( F_3 ( & V_13 -> V_20 ) )
V_65 -> V_144 |= V_25 ;
V_65 -> V_69 . V_70 . V_113 = F_74 ( V_6 , V_71 ) ;
V_65 -> V_69 . V_70 . V_6 = V_6 ;
V_65 -> V_69 . V_70 . V_72 = V_58 ;
V_65 -> V_69 . V_70 . V_73 = NULL ;
V_65 -> V_69 . V_70 . V_80 = 0 ;
V_65 -> V_69 . V_70 . V_74 = 0 ;
V_65 -> V_69 . V_70 . V_71 = V_71 ;
return V_65 ;
}
int
F_52 (
struct V_12 * V_13 ,
int V_146 ,
int V_147 )
{
V_146 -= F_75 ( V_13 ) ;
if ( V_147 )
return V_146 / sizeof( T_9 ) ;
return V_146 / ( sizeof( T_4 ) + sizeof( V_148 ) ) ;
}
int
F_6 (
int V_146 ,
int V_147 )
{
V_146 -= sizeof( T_3 ) ;
if ( V_147 )
return V_146 / sizeof( V_149 ) ;
return V_146 / ( sizeof( V_150 ) + sizeof( V_151 ) ) ;
}
int
F_76 (
struct V_106 * V_84 ,
struct V_5 * V_6 ,
int V_71 ,
T_14 V_152 ,
struct V_153 * V_154 )
{
struct V_64 * V_65 ;
int error ;
ASSERT ( V_84 || V_154 ) ;
ASSERT ( ! ( V_84 && V_154 ) ) ;
if ( V_71 == V_155 )
ASSERT ( V_6 -> V_77 . V_156 == V_157 ) ;
else
ASSERT ( V_6 -> V_77 . V_158 == V_157 ) ;
V_65 = F_37 ( V_6 -> V_14 , V_84 , V_6 , V_71 ) ;
if ( ! V_65 )
return - V_159 ;
error = F_77 ( V_65 , V_152 , V_154 ) ;
F_78 ( V_65 , error ? V_160 : V_161 ) ;
return error ;
}
