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
V_15 = F_6 ( V_13 , V_8 , 0 ) ;
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
#if V_37
V_31 -> V_38 = ( ( ( V_39 ) V_29 & F_12 ( 9 ) ) << 43 ) |
( ( ( V_39 ) V_30 ) >> 21 ) ;
#else
#ifdef F_13
{
T_8 V_40 ;
V_40 = ( ( ( T_8 ) V_29 & F_12 ( 9 ) ) << 43 ) |
( ( ( T_8 ) V_30 ) >> 21 ) ;
ASSERT ( ( V_40 >> 32 ) == 0 || F_14 ( V_40 ) ) ;
V_31 -> V_38 = ( V_39 ) V_40 ;
}
#else
V_31 -> V_38 = ( V_39 ) ( ( ( T_8 ) V_30 ) >> 21 ) ;
#endif
#endif
V_31 -> V_41 = ( T_2 ) ( V_30 & F_12 ( 21 ) ) ;
if ( V_32 ) {
ASSERT ( V_31 -> V_41 != 0 ) ;
V_33 = V_3 ;
} else
V_33 = V_4 ;
V_31 -> V_42 = V_33 ;
}
void
F_15 (
T_9 * V_43 ,
T_7 * V_31 )
{
F_11 ( V_43 -> V_29 , V_43 -> V_30 , V_31 ) ;
}
T_2
F_16 (
T_9 * V_43 )
{
return ( T_2 ) ( V_43 -> V_30 & F_12 ( 21 ) ) ;
}
V_39
F_17 (
T_9 * V_43 )
{
#if V_37
return ( ( ( V_39 ) V_43 -> V_29 & F_12 ( 9 ) ) << 43 ) |
( ( ( V_39 ) V_43 -> V_30 ) >> 21 ) ;
#else
#ifdef F_13
T_8 V_40 ;
V_40 = ( ( ( T_8 ) V_43 -> V_29 & F_12 ( 9 ) ) << 43 ) |
( ( ( T_8 ) V_43 -> V_30 ) >> 21 ) ;
ASSERT ( ( V_40 >> 32 ) == 0 || F_14 ( V_40 ) ) ;
return ( V_39 ) V_40 ;
#else
return ( V_39 ) ( ( ( T_8 ) V_43 -> V_30 ) >> 21 ) ;
#endif
#endif
}
V_36
F_18 (
T_9 * V_43 )
{
return ( ( V_36 ) V_43 -> V_29 &
F_12 ( 64 - V_34 ) ) >> 9 ;
}
T_1
F_19 (
T_9 * V_43 )
{
int V_32 ;
V_32 = ( int ) ( ( V_43 -> V_29 ) >> ( 64 - V_34 ) ) ;
return F_1 ( F_16 ( V_43 ) ,
V_32 ) ;
}
T_2
F_20 (
T_10 * V_43 )
{
return ( T_2 ) ( F_21 ( V_43 -> V_30 ) & F_12 ( 21 ) ) ;
}
V_36
F_22 (
T_10 * V_43 )
{
return ( ( V_36 ) F_21 ( V_43 -> V_29 ) &
F_12 ( 64 - V_34 ) ) >> 9 ;
}
void
F_23 (
T_9 * V_43 ,
V_36 V_44 ,
V_39 V_45 ,
T_2 V_46 ,
T_1 V_47 )
{
int V_2 = ( V_47 == V_4 ) ? 0 : 1 ;
ASSERT ( V_47 == V_4 || V_47 == V_3 ) ;
ASSERT ( ( V_44 & F_24 ( 64 - V_48 ) ) == 0 ) ;
ASSERT ( ( V_46 & F_24 ( 64 - V_49 ) ) == 0 ) ;
#if V_37
ASSERT ( ( V_45 & F_24 ( 64 - V_50 ) ) == 0 ) ;
V_43 -> V_29 = ( ( V_51 ) V_2 << 63 ) |
( ( V_51 ) V_44 << 9 ) |
( ( V_51 ) V_45 >> 43 ) ;
V_43 -> V_30 = ( ( V_51 ) V_45 << 21 ) |
( ( V_51 ) V_46 &
( V_51 ) F_12 ( 21 ) ) ;
#else
if ( F_25 ( V_45 ) ) {
V_43 -> V_29 = ( ( V_51 ) V_2 << 63 ) |
( ( V_51 ) V_44 << 9 ) |
( V_51 ) F_12 ( 9 ) ;
V_43 -> V_30 = F_24 ( 11 ) |
( ( V_51 ) V_45 << 21 ) |
( ( V_51 ) V_46 &
( V_51 ) F_12 ( 21 ) ) ;
} else {
V_43 -> V_29 = ( ( V_51 ) V_2 << 63 ) |
( ( V_51 ) V_44 << 9 ) ;
V_43 -> V_30 = ( ( V_51 ) V_45 << 21 ) |
( ( V_51 ) V_46 &
( V_51 ) F_12 ( 21 ) ) ;
}
#endif
}
void
F_26 (
T_9 * V_43 ,
T_7 * V_31 )
{
F_23 ( V_43 , V_31 -> V_35 , V_31 -> V_38 ,
V_31 -> V_41 , V_31 -> V_42 ) ;
}
void
F_27 (
T_10 * V_43 ,
V_36 V_44 ,
V_39 V_45 ,
T_2 V_46 ,
T_1 V_47 )
{
int V_2 = ( V_47 == V_4 ) ? 0 : 1 ;
ASSERT ( V_47 == V_4 || V_47 == V_3 ) ;
ASSERT ( ( V_44 & F_24 ( 64 - V_48 ) ) == 0 ) ;
ASSERT ( ( V_46 & F_24 ( 64 - V_49 ) ) == 0 ) ;
#if V_37
ASSERT ( ( V_45 & F_24 ( 64 - V_50 ) ) == 0 ) ;
V_43 -> V_29 = F_28 (
( ( V_51 ) V_2 << 63 ) |
( ( V_51 ) V_44 << 9 ) |
( ( V_51 ) V_45 >> 43 ) ) ;
V_43 -> V_30 = F_28 (
( ( V_51 ) V_45 << 21 ) |
( ( V_51 ) V_46 &
( V_51 ) F_12 ( 21 ) ) ) ;
#else
if ( F_25 ( V_45 ) ) {
V_43 -> V_29 = F_28 (
( ( V_51 ) V_2 << 63 ) |
( ( V_51 ) V_44 << 9 ) |
( V_51 ) F_12 ( 9 ) ) ;
V_43 -> V_30 = F_28 ( F_24 ( 11 ) |
( ( V_51 ) V_45 << 21 ) |
( ( V_51 ) V_46 &
( V_51 ) F_12 ( 21 ) ) ) ;
} else {
V_43 -> V_29 = F_28 (
( ( V_51 ) V_2 << 63 ) |
( ( V_51 ) V_44 << 9 ) ) ;
V_43 -> V_30 = F_28 (
( ( V_51 ) V_45 << 21 ) |
( ( V_51 ) V_46 &
( V_51 ) F_12 ( 21 ) ) ) ;
}
#endif
}
STATIC void
F_29 (
T_10 * V_43 ,
T_7 * V_31 )
{
F_27 ( V_43 , V_31 -> V_35 , V_31 -> V_38 ,
V_31 -> V_41 , V_31 -> V_42 ) ;
}
void
F_30 (
T_9 * V_43 ,
T_2 V_52 )
{
ASSERT ( ( V_52 & F_24 ( 43 ) ) == 0 ) ;
V_43 -> V_30 = ( V_43 -> V_30 & ( V_51 ) F_24 ( 43 ) ) |
( V_51 ) ( V_52 & F_12 ( 21 ) ) ;
}
void
F_31 (
T_9 * V_43 ,
V_39 V_52 )
{
#if V_37
ASSERT ( ( V_52 & F_24 ( 12 ) ) == 0 ) ;
V_43 -> V_29 = ( V_43 -> V_29 & ( V_51 ) F_24 ( 55 ) ) |
( V_51 ) ( V_52 >> 43 ) ;
V_43 -> V_30 = ( V_43 -> V_30 & ( V_51 ) F_12 ( 21 ) ) |
( V_51 ) ( V_52 << 21 ) ;
#else
if ( F_25 ( V_52 ) ) {
V_43 -> V_29 |= ( V_51 ) F_12 ( 9 ) ;
V_43 -> V_30 = ( V_51 ) F_24 ( 11 ) |
( ( V_51 ) V_52 << 21 ) |
( V_43 -> V_30 & ( V_51 ) F_12 ( 21 ) ) ;
} else {
V_43 -> V_29 &= ~ ( V_51 ) F_12 ( 9 ) ;
V_43 -> V_30 = ( ( V_51 ) V_52 << 21 ) |
( V_43 -> V_30 & ( V_51 ) F_12 ( 21 ) ) ;
}
#endif
}
void
F_32 (
T_9 * V_43 ,
V_36 V_52 )
{
ASSERT ( ( V_52 & F_24 ( 9 ) ) == 0 ) ;
V_43 -> V_29 = ( V_43 -> V_29 & ( V_51 ) F_24 ( 1 ) ) |
( ( V_51 ) V_52 << 9 ) |
( V_43 -> V_29 & ( V_51 ) F_12 ( 9 ) ) ;
}
void
F_33 (
T_9 * V_43 ,
T_1 V_52 )
{
ASSERT ( V_52 == V_4 || V_52 == V_3 ) ;
if ( V_52 == V_4 )
V_43 -> V_29 &= F_12 ( 64 - V_34 ) ;
else
V_43 -> V_29 |= F_24 ( V_34 ) ;
}
void
F_34 (
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
ASSERT ( V_10 -> V_53 == F_35 ( V_22 ) ) ;
ASSERT ( F_36 ( & V_10 -> V_54 . V_55 . V_56 , & V_13 -> V_20 . V_57 ) ) ;
ASSERT ( V_10 -> V_54 . V_55 . V_58 ==
F_28 ( V_21 ) ) ;
} else
ASSERT ( V_10 -> V_53 == F_35 ( V_26 ) ) ;
ASSERT ( V_10 -> V_54 . V_55 . V_59 == F_28 ( V_60 ) ) ;
ASSERT ( V_10 -> V_54 . V_55 . V_61 == F_28 ( V_60 ) ) ;
ASSERT ( V_10 -> V_27 != 0 ) ;
V_7 -> V_27 = V_10 -> V_27 ;
V_7 -> V_28 = V_10 -> V_28 ;
V_15 = F_6 ( V_13 , V_8 , 0 ) ;
V_16 = F_8 ( V_13 , V_10 , 1 ) ;
V_18 = F_7 ( V_7 , 1 ) ;
V_17 = F_10 ( V_13 , V_10 , 1 , V_11 ) ;
V_19 = F_9 ( V_7 , 1 , V_15 ) ;
V_15 = F_5 ( V_7 -> V_28 ) ;
memcpy ( V_18 , V_16 , sizeof( * V_16 ) * V_15 ) ;
memcpy ( V_19 , V_17 , sizeof( * V_17 ) * V_15 ) ;
}
int
F_37 (
T_11 * V_62 ,
T_12 V_63 ,
T_12 V_64 )
{
for (; V_64 > 0 ; V_64 -- , V_63 ++ ) {
T_9 * V_65 = F_38 ( V_62 , V_63 ) ;
if ( ( V_65 -> V_29 >>
( 64 - V_34 ) ) != 0 ) {
ASSERT ( 0 ) ;
return 1 ;
}
}
return 0 ;
}
STATIC struct V_66 *
F_39 (
struct V_66 * V_67 )
{
struct V_66 * V_68 ;
V_68 = F_40 ( V_67 -> V_69 , V_67 -> V_70 ,
V_67 -> V_71 . V_40 . V_6 , V_67 -> V_71 . V_40 . V_72 ) ;
V_68 -> V_71 . V_40 . V_73 = V_67 -> V_71 . V_40 . V_73 ;
V_68 -> V_71 . V_40 . V_74 = V_67 -> V_71 . V_40 . V_74 ;
V_68 -> V_71 . V_40 . V_75 = V_67 -> V_71 . V_40 . V_75 ;
return V_68 ;
}
STATIC void
F_41 (
struct V_66 * V_76 ,
struct V_66 * V_77 )
{
ASSERT ( ( V_77 -> V_71 . V_40 . V_73 != V_78 ) ||
( V_77 -> V_71 . V_40 . V_6 -> V_79 . V_80 & V_81 ) ) ;
ASSERT ( V_77 -> V_71 . V_40 . V_74 == V_76 -> V_71 . V_40 . V_74 ) ;
V_77 -> V_71 . V_40 . V_82 += V_76 -> V_71 . V_40 . V_82 ;
V_77 -> V_71 . V_40 . V_73 = V_76 -> V_71 . V_40 . V_73 ;
V_76 -> V_71 . V_40 . V_82 = 0 ;
}
STATIC int
F_42 (
struct V_66 * V_67 ,
union V_83 * V_84 ,
union V_83 * V_68 ,
int V_85 ,
int * V_86 )
{
T_13 args ;
int error ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_87 = V_67 -> V_70 ;
args . V_13 = V_67 -> V_69 ;
args . V_88 = V_67 -> V_71 . V_40 . V_73 ;
args . V_73 = args . V_88 ;
if ( args . V_88 == V_78 ) {
args . V_88 = F_21 ( V_84 -> V_55 ) ;
args . type = V_89 ;
args . V_90 = F_43 ( args . V_87 ) ;
} else if ( V_67 -> V_71 . V_40 . V_74 -> V_91 ) {
args . type = V_89 ;
} else {
args . type = V_92 ;
}
args . V_93 = args . V_94 = args . V_95 = 1 ;
args . V_96 = V_67 -> V_71 . V_40 . V_75 & V_97 ;
if ( ! args . V_96 && F_43 ( args . V_87 ) == 0 ) {
error = F_44 ( V_98 ) ;
goto V_99;
}
error = F_45 ( & args ) ;
if ( error )
goto V_99;
if ( args . V_88 == V_78 && args . V_90 ) {
args . V_88 = 0 ;
args . type = V_100 ;
args . V_90 = 0 ;
error = F_45 ( & args ) ;
if ( error )
goto V_99;
V_67 -> V_71 . V_40 . V_74 -> V_91 = 1 ;
}
if ( args . V_88 == V_78 ) {
F_46 ( V_67 , V_101 ) ;
* V_86 = 0 ;
return 0 ;
}
ASSERT ( args . V_102 == 1 ) ;
V_67 -> V_71 . V_40 . V_73 = args . V_88 ;
V_67 -> V_71 . V_40 . V_82 ++ ;
V_67 -> V_71 . V_40 . V_6 -> V_79 . V_103 ++ ;
F_47 ( args . V_87 , V_67 -> V_71 . V_40 . V_6 , V_104 ) ;
F_48 ( args . V_87 , V_67 -> V_71 . V_40 . V_6 ,
V_105 , 1L ) ;
V_68 -> V_55 = F_28 ( args . V_88 ) ;
F_46 ( V_67 , V_101 ) ;
* V_86 = 1 ;
return 0 ;
V_99:
F_46 ( V_67 , V_106 ) ;
return error ;
}
STATIC int
F_49 (
struct V_66 * V_67 ,
struct V_107 * V_108 )
{
struct V_12 * V_13 = V_67 -> V_69 ;
struct V_5 * V_6 = V_67 -> V_71 . V_40 . V_6 ;
struct V_109 * V_87 = V_67 -> V_70 ;
V_39 V_88 = F_50 ( V_13 , F_51 ( V_108 ) ) ;
F_52 ( V_88 , 1 , V_67 -> V_71 . V_40 . V_74 , V_13 ) ;
V_6 -> V_79 . V_103 -- ;
F_47 ( V_87 , V_6 , V_104 ) ;
F_48 ( V_87 , V_6 , V_105 , - 1L ) ;
F_53 ( V_87 , V_108 ) ;
return 0 ;
}
STATIC int
F_54 (
struct V_66 * V_67 ,
int V_110 )
{
if ( V_110 == V_67 -> V_111 - 1 ) {
struct V_112 * V_62 ;
V_62 = F_55 ( V_67 -> V_71 . V_40 . V_6 ,
V_67 -> V_71 . V_40 . V_72 ) ;
return F_56 ( V_67 -> V_69 ,
V_62 -> V_113 , V_110 == 0 ) / 2 ;
}
return V_67 -> V_69 -> V_114 [ V_110 != 0 ] ;
}
int
F_57 (
struct V_66 * V_67 ,
int V_110 )
{
if ( V_110 == V_67 -> V_111 - 1 ) {
struct V_112 * V_62 ;
V_62 = F_55 ( V_67 -> V_71 . V_40 . V_6 ,
V_67 -> V_71 . V_40 . V_72 ) ;
return F_56 ( V_67 -> V_69 ,
V_62 -> V_113 , V_110 == 0 ) ;
}
return V_67 -> V_69 -> V_115 [ V_110 != 0 ] ;
}
STATIC int
F_58 (
struct V_66 * V_67 ,
int V_110 )
{
if ( V_110 != V_67 -> V_111 - 1 )
return V_67 -> V_69 -> V_115 [ V_110 != 0 ] ;
return F_6 ( V_67 -> V_69 , V_67 -> V_71 . V_40 . V_116 ,
V_110 == 0 ) ;
}
STATIC void
F_59 (
union V_117 * V_118 ,
union V_119 * V_120 )
{
V_118 -> V_121 . V_35 =
F_28 ( F_22 ( & V_120 -> V_121 ) ) ;
}
STATIC void
F_60 (
union V_117 * V_118 ,
union V_119 * V_120 )
{
ASSERT ( V_118 -> V_121 . V_35 != 0 ) ;
F_27 ( & V_120 -> V_121 , F_21 ( V_118 -> V_121 . V_35 ) ,
0 , 0 , V_4 ) ;
}
STATIC void
F_61 (
struct V_66 * V_67 ,
union V_119 * V_120 )
{
F_29 ( & V_120 -> V_121 , & V_67 -> V_122 . V_40 ) ;
}
STATIC void
F_62 (
struct V_66 * V_67 ,
union V_83 * V_123 )
{
V_123 -> V_55 = 0 ;
}
STATIC T_14
F_63 (
struct V_66 * V_67 ,
union V_117 * V_118 )
{
return ( T_14 ) F_21 ( V_118 -> V_121 . V_35 ) -
V_67 -> V_122 . V_40 . V_35 ;
}
static bool
F_64 (
struct V_107 * V_108 )
{
struct V_12 * V_13 = V_108 -> V_124 -> V_125 ;
struct V_9 * V_126 = F_65 ( V_108 ) ;
unsigned int V_110 ;
switch ( V_126 -> V_53 ) {
case F_35 ( V_22 ) :
if ( ! F_3 ( & V_13 -> V_20 ) )
return false ;
if ( ! F_36 ( & V_126 -> V_54 . V_55 . V_56 , & V_13 -> V_20 . V_57 ) )
return false ;
if ( F_21 ( V_126 -> V_54 . V_55 . V_58 ) != V_108 -> V_127 )
return false ;
if ( F_21 ( V_126 -> V_54 . V_55 . V_128 ) == 0 )
return false ;
case F_35 ( V_26 ) :
break;
default:
return false ;
}
V_110 = F_5 ( V_126 -> V_27 ) ;
if ( V_110 > F_66 ( V_13 -> V_129 [ 0 ] , V_13 -> V_129 [ 1 ] ) )
return false ;
if ( F_5 ( V_126 -> V_28 ) > V_13 -> V_115 [ V_110 != 0 ] )
return false ;
if ( ! V_126 -> V_54 . V_55 . V_59 ||
( V_126 -> V_54 . V_55 . V_59 != F_28 ( V_60 ) &&
! F_67 ( V_13 , F_21 ( V_126 -> V_54 . V_55 . V_59 ) ) ) )
return false ;
if ( ! V_126 -> V_54 . V_55 . V_61 ||
( V_126 -> V_54 . V_55 . V_61 != F_28 ( V_60 ) &&
! F_67 ( V_13 , F_21 ( V_126 -> V_54 . V_55 . V_61 ) ) ) )
return false ;
return true ;
}
static void
F_68 (
struct V_107 * V_108 )
{
if ( ! F_69 ( V_108 ) )
F_70 ( V_108 , V_130 ) ;
else if ( ! F_64 ( V_108 ) )
F_70 ( V_108 , V_131 ) ;
if ( V_108 -> V_132 ) {
F_71 ( V_108 , V_133 ) ;
F_72 ( V_108 ) ;
}
}
static void
F_73 (
struct V_107 * V_108 )
{
if ( ! F_64 ( V_108 ) ) {
F_71 ( V_108 , V_133 ) ;
F_70 ( V_108 , V_131 ) ;
F_72 ( V_108 ) ;
return;
}
F_74 ( V_108 ) ;
}
STATIC int
F_75 (
struct V_66 * V_67 ,
union V_117 * V_134 ,
union V_117 * V_135 )
{
return F_21 ( V_134 -> V_121 . V_35 ) <
F_21 ( V_135 -> V_121 . V_35 ) ;
}
STATIC int
F_76 (
struct V_66 * V_67 ,
union V_119 * V_136 ,
union V_119 * V_137 )
{
return F_22 ( & V_136 -> V_121 ) +
F_20 ( & V_136 -> V_121 ) <=
F_22 ( & V_137 -> V_121 ) ;
}
struct V_66 *
F_40 (
struct V_12 * V_13 ,
struct V_109 * V_87 ,
struct V_5 * V_6 ,
int V_72 )
{
struct V_112 * V_62 = F_55 ( V_6 , V_72 ) ;
struct V_66 * V_67 ;
V_67 = F_77 ( V_138 , V_139 ) ;
V_67 -> V_70 = V_87 ;
V_67 -> V_69 = V_13 ;
V_67 -> V_111 = F_5 ( V_62 -> V_140 -> V_27 ) + 1 ;
V_67 -> V_141 = V_142 ;
V_67 -> V_143 = V_13 -> V_20 . V_144 ;
V_67 -> V_145 = & V_146 ;
V_67 -> V_147 = V_24 | V_148 ;
if ( F_3 ( & V_13 -> V_20 ) )
V_67 -> V_147 |= V_25 ;
V_67 -> V_71 . V_40 . V_116 = F_78 ( V_6 , V_72 ) ;
V_67 -> V_71 . V_40 . V_6 = V_6 ;
V_67 -> V_71 . V_40 . V_73 = V_78 ;
V_67 -> V_71 . V_40 . V_74 = NULL ;
V_67 -> V_71 . V_40 . V_82 = 0 ;
V_67 -> V_71 . V_40 . V_75 = 0 ;
V_67 -> V_71 . V_40 . V_72 = V_72 ;
return V_67 ;
}
int
F_56 (
struct V_12 * V_13 ,
int V_149 ,
int V_150 )
{
V_149 -= F_79 ( V_13 ) ;
if ( V_150 )
return V_149 / sizeof( T_10 ) ;
return V_149 / ( sizeof( T_4 ) + sizeof( V_151 ) ) ;
}
int
F_6 (
struct V_12 * V_13 ,
int V_149 ,
int V_150 )
{
V_149 -= sizeof( T_3 ) ;
if ( V_150 )
return V_149 / sizeof( V_152 ) ;
return V_149 / ( sizeof( V_153 ) + sizeof( V_154 ) ) ;
}
int
F_80 (
struct V_109 * V_87 ,
struct V_5 * V_6 ,
int V_72 ,
T_15 V_155 ,
struct V_156 * V_157 )
{
struct V_66 * V_67 ;
int error ;
ASSERT ( V_87 || V_157 ) ;
ASSERT ( ! ( V_87 && V_157 ) ) ;
if ( V_72 == V_158 )
ASSERT ( V_6 -> V_79 . V_159 == V_160 ) ;
else
ASSERT ( V_6 -> V_79 . V_161 == V_160 ) ;
V_67 = F_40 ( V_6 -> V_14 , V_87 , V_6 , V_72 ) ;
if ( ! V_67 )
return V_162 ;
error = F_81 ( V_67 , V_155 , V_157 ) ;
F_82 ( V_67 , error ? V_163 : V_164 ) ;
return error ;
}
