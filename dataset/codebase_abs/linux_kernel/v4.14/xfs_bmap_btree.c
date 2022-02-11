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
STATIC struct V_60 *
F_34 (
struct V_60 * V_61 )
{
struct V_60 * V_62 ;
V_62 = F_35 ( V_61 -> V_63 , V_61 -> V_64 ,
V_61 -> V_65 . V_66 . V_6 , V_61 -> V_65 . V_66 . V_67 ) ;
V_62 -> V_65 . V_66 . V_68 = V_61 -> V_65 . V_66 . V_68 ;
V_62 -> V_65 . V_66 . V_69 = V_61 -> V_65 . V_66 . V_69 ;
V_62 -> V_65 . V_66 . V_70 = V_61 -> V_65 . V_66 . V_70 ;
return V_62 ;
}
STATIC void
F_36 (
struct V_60 * V_71 ,
struct V_60 * V_72 )
{
ASSERT ( ( V_72 -> V_65 . V_66 . V_68 != V_58 ) ||
( V_72 -> V_65 . V_66 . V_6 -> V_73 . V_74 & V_75 ) ) ;
ASSERT ( V_72 -> V_65 . V_66 . V_69 == V_71 -> V_65 . V_66 . V_69 ) ;
V_72 -> V_65 . V_66 . V_76 += V_71 -> V_65 . V_66 . V_76 ;
V_72 -> V_65 . V_66 . V_68 = V_71 -> V_65 . V_66 . V_68 ;
V_71 -> V_65 . V_66 . V_76 = 0 ;
}
STATIC int
F_37 (
struct V_60 * V_61 ,
union V_77 * V_78 ,
union V_77 * V_62 ,
int * V_79 )
{
T_10 args ;
int error ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_80 = V_61 -> V_64 ;
args . V_13 = V_61 -> V_63 ;
args . V_81 = V_61 -> V_65 . V_66 . V_68 ;
args . V_68 = args . V_81 ;
F_38 ( & args . V_82 , V_61 -> V_65 . V_66 . V_6 -> V_22 ,
V_61 -> V_65 . V_66 . V_67 ) ;
if ( args . V_81 == V_58 ) {
args . V_81 = F_18 ( V_78 -> V_52 ) ;
args . type = V_83 ;
args . V_84 = args . V_80 -> V_85 ;
} else if ( V_61 -> V_65 . V_66 . V_69 -> V_86 ) {
args . type = V_83 ;
} else {
args . type = V_87 ;
}
args . V_88 = args . V_89 = args . V_90 = 1 ;
args . V_91 = V_61 -> V_65 . V_66 . V_70 & V_92 ;
if ( ! args . V_91 && args . V_80 -> V_85 == 0 ) {
error = - V_93 ;
goto V_94;
}
error = F_39 ( & args ) ;
if ( error )
goto V_94;
if ( args . V_81 == V_58 && args . V_84 ) {
args . V_81 = 0 ;
args . type = V_95 ;
error = F_39 ( & args ) ;
if ( error )
goto V_94;
V_61 -> V_65 . V_66 . V_69 -> V_86 = true ;
}
if ( F_40 ( args . V_81 == V_58 ) ) {
F_41 ( V_61 , V_96 ) ;
* V_79 = 0 ;
return 0 ;
}
ASSERT ( args . V_97 == 1 ) ;
V_61 -> V_65 . V_66 . V_68 = args . V_81 ;
V_61 -> V_65 . V_66 . V_76 ++ ;
V_61 -> V_65 . V_66 . V_6 -> V_73 . V_98 ++ ;
F_42 ( args . V_80 , V_61 -> V_65 . V_66 . V_6 , V_99 ) ;
F_43 ( args . V_80 , V_61 -> V_65 . V_66 . V_6 ,
V_100 , 1L ) ;
V_62 -> V_52 = F_24 ( args . V_81 ) ;
F_41 ( V_61 , V_96 ) ;
* V_79 = 1 ;
return 0 ;
V_94:
F_41 ( V_61 , V_101 ) ;
return error ;
}
STATIC int
F_44 (
struct V_60 * V_61 ,
struct V_102 * V_103 )
{
struct V_12 * V_13 = V_61 -> V_63 ;
struct V_5 * V_6 = V_61 -> V_65 . V_66 . V_6 ;
struct V_104 * V_80 = V_61 -> V_64 ;
V_35 V_81 = F_45 ( V_13 , F_46 ( V_103 ) ) ;
struct V_105 V_82 ;
F_38 ( & V_82 , V_6 -> V_22 , V_61 -> V_65 . V_66 . V_67 ) ;
F_47 ( V_13 , V_61 -> V_65 . V_66 . V_69 , V_81 , 1 , & V_82 ) ;
V_6 -> V_73 . V_98 -- ;
F_42 ( V_80 , V_6 , V_99 ) ;
F_43 ( V_80 , V_6 , V_100 , - 1L ) ;
return 0 ;
}
STATIC int
F_48 (
struct V_60 * V_61 ,
int V_106 )
{
if ( V_106 == V_61 -> V_107 - 1 ) {
struct V_108 * V_109 ;
V_109 = F_49 ( V_61 -> V_65 . V_66 . V_6 ,
V_61 -> V_65 . V_66 . V_67 ) ;
return F_50 ( V_61 -> V_63 ,
V_109 -> V_110 , V_106 == 0 ) / 2 ;
}
return V_61 -> V_63 -> V_111 [ V_106 != 0 ] ;
}
int
F_51 (
struct V_60 * V_61 ,
int V_106 )
{
if ( V_106 == V_61 -> V_107 - 1 ) {
struct V_108 * V_109 ;
V_109 = F_49 ( V_61 -> V_65 . V_66 . V_6 ,
V_61 -> V_65 . V_66 . V_67 ) ;
return F_50 ( V_61 -> V_63 ,
V_109 -> V_110 , V_106 == 0 ) ;
}
return V_61 -> V_63 -> V_112 [ V_106 != 0 ] ;
}
STATIC int
F_52 (
struct V_60 * V_61 ,
int V_106 )
{
if ( V_106 != V_61 -> V_107 - 1 )
return V_61 -> V_63 -> V_112 [ V_106 != 0 ] ;
return F_5 ( V_61 -> V_65 . V_66 . V_113 , V_106 == 0 ) ;
}
STATIC void
F_53 (
union V_114 * V_115 ,
union V_116 * V_117 )
{
V_115 -> V_118 . V_32 =
F_24 ( F_19 ( & V_117 -> V_118 ) ) ;
}
STATIC void
F_54 (
union V_114 * V_115 ,
union V_116 * V_117 )
{
V_115 -> V_118 . V_32 = F_24 (
F_19 ( & V_117 -> V_118 ) +
F_17 ( & V_117 -> V_118 ) - 1 ) ;
}
STATIC void
F_55 (
struct V_60 * V_61 ,
union V_116 * V_117 )
{
F_25 ( & V_117 -> V_118 , & V_61 -> V_119 . V_66 ) ;
}
STATIC void
F_56 (
struct V_60 * V_61 ,
union V_77 * V_120 )
{
V_120 -> V_52 = 0 ;
}
STATIC T_11
F_57 (
struct V_60 * V_61 ,
union V_114 * V_115 )
{
return ( T_11 ) F_18 ( V_115 -> V_118 . V_32 ) -
V_61 -> V_119 . V_66 . V_32 ;
}
STATIC T_11
F_58 (
struct V_60 * V_61 ,
union V_114 * V_121 ,
union V_114 * V_122 )
{
return ( T_11 ) F_18 ( V_121 -> V_118 . V_32 ) -
F_18 ( V_122 -> V_118 . V_32 ) ;
}
static bool
F_59 (
struct V_102 * V_103 )
{
struct V_12 * V_13 = V_103 -> V_123 -> V_124 ;
struct V_9 * V_125 = F_60 ( V_103 ) ;
unsigned int V_106 ;
switch ( V_125 -> V_49 ) {
case F_32 ( V_50 ) :
if ( ! F_31 ( & V_13 -> V_48 ) )
return false ;
if ( ! F_33 ( & V_125 -> V_51 . V_52 . V_53 , & V_13 -> V_48 . V_54 ) )
return false ;
if ( F_18 ( V_125 -> V_51 . V_52 . V_55 ) != V_103 -> V_126 )
return false ;
if ( F_18 ( V_125 -> V_51 . V_52 . V_127 ) == 0 )
return false ;
case F_32 ( V_56 ) :
break;
default:
return false ;
}
V_106 = F_4 ( V_125 -> V_24 ) ;
if ( V_106 > F_61 ( V_13 -> V_128 [ 0 ] , V_13 -> V_128 [ 1 ] ) )
return false ;
if ( F_4 ( V_125 -> V_25 ) > V_13 -> V_112 [ V_106 != 0 ] )
return false ;
if ( ! V_125 -> V_51 . V_52 . V_57 ||
( V_125 -> V_51 . V_52 . V_57 != F_24 ( V_58 ) &&
! F_62 ( V_13 , F_18 ( V_125 -> V_51 . V_52 . V_57 ) ) ) )
return false ;
if ( ! V_125 -> V_51 . V_52 . V_59 ||
( V_125 -> V_51 . V_52 . V_59 != F_24 ( V_58 ) &&
! F_62 ( V_13 , F_18 ( V_125 -> V_51 . V_52 . V_59 ) ) ) )
return false ;
return true ;
}
static void
F_63 (
struct V_102 * V_103 )
{
if ( ! F_64 ( V_103 ) )
F_65 ( V_103 , - V_129 ) ;
else if ( ! F_59 ( V_103 ) )
F_65 ( V_103 , - V_130 ) ;
if ( V_103 -> V_131 ) {
F_66 ( V_103 , V_132 ) ;
F_67 ( V_103 ) ;
}
}
static void
F_68 (
struct V_102 * V_103 )
{
if ( ! F_59 ( V_103 ) ) {
F_66 ( V_103 , V_132 ) ;
F_65 ( V_103 , - V_130 ) ;
F_67 ( V_103 ) ;
return;
}
F_69 ( V_103 ) ;
}
STATIC int
F_70 (
struct V_60 * V_61 ,
union V_114 * V_121 ,
union V_114 * V_122 )
{
return F_18 ( V_121 -> V_118 . V_32 ) <
F_18 ( V_122 -> V_118 . V_32 ) ;
}
STATIC int
F_71 (
struct V_60 * V_61 ,
union V_116 * V_133 ,
union V_116 * V_134 )
{
return F_19 ( & V_133 -> V_118 ) +
F_17 ( & V_133 -> V_118 ) <=
F_19 ( & V_134 -> V_118 ) ;
}
struct V_60 *
F_35 (
struct V_12 * V_13 ,
struct V_104 * V_80 ,
struct V_5 * V_6 ,
int V_67 )
{
struct V_108 * V_109 = F_49 ( V_6 , V_67 ) ;
struct V_60 * V_61 ;
ASSERT ( V_67 != V_135 ) ;
V_61 = F_72 ( V_136 , V_137 ) ;
V_61 -> V_64 = V_80 ;
V_61 -> V_63 = V_13 ;
V_61 -> V_107 = F_4 ( V_109 -> V_138 -> V_24 ) + 1 ;
V_61 -> V_139 = V_21 ;
V_61 -> V_140 = V_13 -> V_48 . V_141 ;
V_61 -> V_142 = F_73 ( V_143 ) ;
V_61 -> V_144 = & V_145 ;
V_61 -> V_146 = V_23 | V_147 ;
if ( F_31 ( & V_13 -> V_48 ) )
V_61 -> V_146 |= V_148 ;
V_61 -> V_65 . V_66 . V_113 = F_74 ( V_6 , V_67 ) ;
V_61 -> V_65 . V_66 . V_6 = V_6 ;
V_61 -> V_65 . V_66 . V_68 = V_58 ;
V_61 -> V_65 . V_66 . V_69 = NULL ;
V_61 -> V_65 . V_66 . V_76 = 0 ;
V_61 -> V_65 . V_66 . V_70 = 0 ;
V_61 -> V_65 . V_66 . V_67 = V_67 ;
return V_61 ;
}
int
F_50 (
struct V_12 * V_13 ,
int V_149 ,
int V_150 )
{
V_149 -= F_75 ( V_13 ) ;
if ( V_150 )
return V_149 / sizeof( T_9 ) ;
return V_149 / ( sizeof( T_4 ) + sizeof( V_151 ) ) ;
}
int
F_5 (
int V_149 ,
int V_150 )
{
V_149 -= sizeof( T_3 ) ;
if ( V_150 )
return V_149 / sizeof( V_152 ) ;
return V_149 / ( sizeof( V_153 ) + sizeof( V_154 ) ) ;
}
int
F_76 (
struct V_104 * V_80 ,
struct V_5 * V_6 ,
int V_67 ,
T_12 V_155 ,
struct V_156 * V_157 )
{
struct V_60 * V_61 ;
int error ;
ASSERT ( V_80 || V_157 ) ;
ASSERT ( ! ( V_80 && V_157 ) ) ;
if ( V_67 == V_158 )
ASSERT ( V_6 -> V_73 . V_159 == V_160 ) ;
else
ASSERT ( V_6 -> V_73 . V_161 == V_160 ) ;
V_61 = F_35 ( V_6 -> V_14 , V_80 , V_6 , V_67 ) ;
if ( ! V_61 )
return - V_162 ;
V_61 -> V_65 . V_66 . V_70 |= V_163 ;
error = F_77 ( V_61 , V_155 , V_157 ) ;
F_78 ( V_61 , error ? V_164 : V_165 ) ;
return error ;
}
