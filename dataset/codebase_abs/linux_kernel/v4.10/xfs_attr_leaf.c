static void
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
if ( V_6 -> V_9 . V_10 . V_11 == F_2 ( V_12 ) ) {
V_8 = (struct V_7 * ) V_6 ;
V_4 -> V_13 = F_3 ( V_8 -> V_13 ) ;
} else {
V_4 -> V_13 = F_3 ( V_6 -> V_9 . V_13 ) ;
}
if ( V_4 -> V_13 == V_14 ) {
ASSERT ( ! V_4 -> V_15 && ! V_4 -> V_16 ) ;
ASSERT ( V_2 -> V_17 > V_18 ) ;
V_4 -> V_13 = V_2 -> V_17 ;
}
}
static void
F_4 (
struct V_1 * V_2 ,
struct V_5 * V_4 ,
struct V_3 * V_6 )
{
struct V_7 * V_8 ;
T_1 V_13 ;
ASSERT ( V_6 -> V_13 != V_14 ) ;
V_13 = V_6 -> V_13 ;
if ( V_13 > V_18 ) {
ASSERT ( V_6 -> V_13 == V_2 -> V_17 ) ;
V_13 = V_14 ;
}
if ( V_6 -> V_11 == V_12 ) {
V_8 = (struct V_7 * ) V_4 ;
V_8 -> V_13 = F_2 ( V_13 ) ;
} else {
V_4 -> V_9 . V_13 = F_2 ( V_13 ) ;
}
}
void
F_5 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_19 ;
ASSERT ( V_6 -> V_9 . V_10 . V_11 == F_2 ( V_20 ) ||
V_6 -> V_9 . V_10 . V_11 == F_2 ( V_12 ) ) ;
if ( V_6 -> V_9 . V_10 . V_11 == F_2 ( V_12 ) ) {
struct V_7 * V_8 = (struct V_7 * ) V_6 ;
V_4 -> V_21 = F_6 ( V_8 -> V_10 . V_9 . V_21 ) ;
V_4 -> V_22 = F_6 ( V_8 -> V_10 . V_9 . V_22 ) ;
V_4 -> V_11 = F_3 ( V_8 -> V_10 . V_9 . V_11 ) ;
V_4 -> V_15 = F_3 ( V_8 -> V_15 ) ;
V_4 -> V_16 = F_3 ( V_8 -> V_16 ) ;
F_1 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_23 = V_8 -> V_23 ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
V_4 -> V_25 [ V_19 ] . V_26 = F_3 ( V_8 -> V_25 [ V_19 ] . V_26 ) ;
V_4 -> V_25 [ V_19 ] . V_27 = F_3 ( V_8 -> V_25 [ V_19 ] . V_27 ) ;
}
return;
}
V_4 -> V_21 = F_6 ( V_6 -> V_9 . V_10 . V_21 ) ;
V_4 -> V_22 = F_6 ( V_6 -> V_9 . V_10 . V_22 ) ;
V_4 -> V_11 = F_3 ( V_6 -> V_9 . V_10 . V_11 ) ;
V_4 -> V_15 = F_3 ( V_6 -> V_9 . V_15 ) ;
V_4 -> V_16 = F_3 ( V_6 -> V_9 . V_16 ) ;
F_1 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_23 = V_6 -> V_9 . V_23 ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
V_4 -> V_25 [ V_19 ] . V_26 = F_3 ( V_6 -> V_9 . V_25 [ V_19 ] . V_26 ) ;
V_4 -> V_25 [ V_19 ] . V_27 = F_3 ( V_6 -> V_9 . V_25 [ V_19 ] . V_27 ) ;
}
}
void
F_7 (
struct V_1 * V_2 ,
struct V_5 * V_4 ,
struct V_3 * V_6 )
{
int V_19 ;
ASSERT ( V_6 -> V_11 == V_20 ||
V_6 -> V_11 == V_12 ) ;
if ( V_6 -> V_11 == V_12 ) {
struct V_7 * V_8 = (struct V_7 * ) V_4 ;
V_8 -> V_10 . V_9 . V_21 = F_8 ( V_6 -> V_21 ) ;
V_8 -> V_10 . V_9 . V_22 = F_8 ( V_6 -> V_22 ) ;
V_8 -> V_10 . V_9 . V_11 = F_2 ( V_6 -> V_11 ) ;
V_8 -> V_15 = F_2 ( V_6 -> V_15 ) ;
V_8 -> V_16 = F_2 ( V_6 -> V_16 ) ;
F_4 ( V_2 , V_4 , V_6 ) ;
V_8 -> V_23 = V_6 -> V_23 ;
V_8 -> V_28 = 0 ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
V_8 -> V_25 [ V_19 ] . V_26 = F_2 ( V_6 -> V_25 [ V_19 ] . V_26 ) ;
V_8 -> V_25 [ V_19 ] . V_27 = F_2 ( V_6 -> V_25 [ V_19 ] . V_27 ) ;
}
return;
}
V_4 -> V_9 . V_10 . V_21 = F_8 ( V_6 -> V_21 ) ;
V_4 -> V_9 . V_10 . V_22 = F_8 ( V_6 -> V_22 ) ;
V_4 -> V_9 . V_10 . V_11 = F_2 ( V_6 -> V_11 ) ;
V_4 -> V_9 . V_15 = F_2 ( V_6 -> V_15 ) ;
V_4 -> V_9 . V_16 = F_2 ( V_6 -> V_16 ) ;
F_4 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_9 . V_23 = V_6 -> V_23 ;
V_4 -> V_9 . V_28 = 0 ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
V_4 -> V_9 . V_25 [ V_19 ] . V_26 = F_2 ( V_6 -> V_25 [ V_19 ] . V_26 ) ;
V_4 -> V_9 . V_25 [ V_19 ] . V_27 = F_2 ( V_6 -> V_25 [ V_19 ] . V_27 ) ;
}
}
static bool
F_9 (
struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 -> V_34 ;
struct V_5 * V_35 = V_30 -> V_36 ;
struct V_37 * V_38 = V_30 -> V_39 ;
struct V_3 V_40 ;
F_5 ( V_32 -> V_41 , & V_40 , V_35 ) ;
if ( F_10 ( & V_32 -> V_42 ) ) {
struct V_43 * V_8 = V_30 -> V_36 ;
if ( V_40 . V_11 != V_12 )
return false ;
if ( ! F_11 ( & V_8 -> V_10 . V_44 , & V_32 -> V_42 . V_45 ) )
return false ;
if ( F_12 ( V_8 -> V_10 . V_46 ) != V_30 -> V_47 )
return false ;
if ( ! F_13 ( V_32 , F_12 ( V_8 -> V_10 . V_48 ) ) )
return false ;
} else {
if ( V_40 . V_11 != V_20 )
return false ;
}
if ( V_38 && V_38 -> V_49 && V_40 . V_15 == 0 )
return false ;
return true ;
}
static void
F_14 (
struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 -> V_34 ;
struct V_50 * V_51 = V_30 -> V_52 ;
struct V_7 * V_8 = V_30 -> V_36 ;
if ( ! F_9 ( V_30 ) ) {
F_15 ( V_30 , - V_53 ) ;
F_16 ( V_30 ) ;
return;
}
if ( ! F_10 ( & V_32 -> V_42 ) )
return;
if ( V_51 )
V_8 -> V_10 . V_48 = F_17 ( V_51 -> V_54 . V_55 ) ;
F_18 ( V_30 , V_56 ) ;
}
static void
F_19 (
struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 -> V_34 ;
if ( F_10 ( & V_32 -> V_42 ) &&
! F_20 ( V_30 , V_56 ) )
F_15 ( V_30 , - V_57 ) ;
else if ( ! F_9 ( V_30 ) )
F_15 ( V_30 , - V_53 ) ;
if ( V_30 -> V_58 )
F_16 ( V_30 ) ;
}
int
F_21 (
struct V_59 * V_60 ,
struct V_61 * V_62 ,
T_2 V_63 ,
T_3 V_64 ,
struct V_29 * * V_65 )
{
int V_66 ;
V_66 = F_22 ( V_60 , V_62 , V_63 , V_64 , V_65 ,
V_67 , & V_68 ) ;
if ( ! V_66 && V_60 )
F_23 ( V_60 , * V_65 , V_69 ) ;
return V_66 ;
}
STATIC int
F_24 ( int V_70 , int V_71 )
{
return F_25 ( V_71 ) == F_26 ( V_70 ) ;
}
int
F_27 ( T_4 * V_62 , int V_72 )
{
int V_73 ;
int V_74 ;
int V_75 ;
int V_76 ;
T_5 * V_32 = V_62 -> V_77 ;
V_73 = ( F_28 ( V_32 , V_62 -> V_78 . V_79 ) - V_72 ) >> 3 ;
switch ( V_62 -> V_78 . V_80 ) {
case V_81 :
V_74 = F_29 ( sizeof( V_82 ) , 8 ) >> 3 ;
return ( V_73 >= V_74 ) ? V_74 : 0 ;
case V_83 :
V_74 = F_29 ( sizeof( V_84 ) , 8 ) >> 3 ;
return ( V_73 >= V_74 ) ? V_74 : 0 ;
}
if ( V_72 <= F_30 ( V_62 ) )
return V_62 -> V_78 . V_85 ;
if ( ! ( V_32 -> V_86 & V_87 ) )
return 0 ;
V_76 = V_62 -> V_88 . V_89 ;
switch ( V_62 -> V_78 . V_80 ) {
case V_90 :
if ( ! V_62 -> V_78 . V_85 && V_62 -> V_88 . V_89 >
F_31 ( V_62 ) )
V_76 = F_32 ( V_91 ) ;
break;
case V_92 :
if ( V_62 -> V_78 . V_85 ) {
if ( V_73 < V_62 -> V_78 . V_85 )
return 0 ;
return V_62 -> V_78 . V_85 ;
}
V_76 = F_33 ( V_32 , V_62 -> V_88 . V_93 ) ;
break;
}
V_74 = F_34 ( V_76 , F_32 ( V_91 ) ) ;
V_74 = F_29 ( V_74 , 8 ) >> 3 ;
V_75 = F_28 ( V_32 , V_62 -> V_78 . V_79 ) -
F_32 ( V_94 ) ;
V_75 = V_75 >> 3 ;
if ( V_73 >= V_75 )
return V_75 ;
if ( V_73 >= V_74 )
return V_73 ;
return 0 ;
}
STATIC void
F_35 ( T_5 * V_32 , T_6 * V_60 )
{
if ( ( V_32 -> V_86 & V_87 ) &&
! ( F_36 ( & V_32 -> V_42 ) ) ) {
F_37 ( & V_32 -> V_95 ) ;
if ( ! F_36 ( & V_32 -> V_42 ) ) {
F_38 ( & V_32 -> V_42 ) ;
F_39 ( & V_32 -> V_95 ) ;
F_40 ( V_60 ) ;
} else
F_39 ( & V_32 -> V_95 ) ;
}
}
void
F_41 ( T_7 * args )
{
T_8 * V_9 ;
T_4 * V_62 ;
T_9 * V_96 ;
F_42 ( args ) ;
V_62 = args -> V_62 ;
ASSERT ( V_62 != NULL ) ;
V_96 = V_62 -> V_97 ;
ASSERT ( V_96 != NULL ) ;
ASSERT ( V_96 -> V_89 == 0 ) ;
if ( V_62 -> V_78 . V_98 == V_90 ) {
V_96 -> V_99 &= ~ V_100 ;
V_62 -> V_78 . V_98 = V_101 ;
V_96 -> V_99 |= V_102 ;
} else {
ASSERT ( V_96 -> V_99 & V_102 ) ;
}
F_43 ( V_62 , sizeof( * V_9 ) , V_67 ) ;
V_9 = ( T_8 * ) V_96 -> V_103 . V_104 ;
V_9 -> V_15 = 0 ;
V_9 -> V_105 = F_2 ( sizeof( * V_9 ) ) ;
F_44 ( args -> V_106 , V_62 , V_107 | V_108 ) ;
}
void
F_45 ( T_7 * args , int V_109 )
{
T_10 * V_110 ;
T_11 * V_111 ;
int V_19 , V_73 , V_27 ;
T_5 * V_32 ;
T_4 * V_62 ;
T_9 * V_96 ;
F_46 ( args ) ;
V_62 = args -> V_62 ;
V_32 = V_62 -> V_77 ;
V_62 -> V_78 . V_85 = V_109 ;
V_96 = V_62 -> V_97 ;
ASSERT ( V_96 -> V_99 & V_102 ) ;
V_110 = ( T_10 * ) V_96 -> V_103 . V_104 ;
V_111 = & V_110 -> V_112 [ 0 ] ;
for ( V_19 = 0 ; V_19 < V_110 -> V_9 . V_15 ; V_111 = F_47 ( V_111 ) , V_19 ++ ) {
#ifdef F_48
if ( V_111 -> V_113 != args -> V_113 )
continue;
if ( memcmp ( args -> V_114 , V_111 -> V_115 , args -> V_113 ) != 0 )
continue;
if ( ! F_24 ( args -> V_116 , V_111 -> V_116 ) )
continue;
ASSERT ( 0 ) ;
#endif
}
V_73 = ( char * ) V_111 - ( char * ) V_110 ;
V_27 = F_49 ( args -> V_113 , args -> V_117 ) ;
F_43 ( V_62 , V_27 , V_67 ) ;
V_110 = ( T_10 * ) V_96 -> V_103 . V_104 ;
V_111 = ( T_11 * ) ( ( char * ) V_110 + V_73 ) ;
V_111 -> V_113 = args -> V_113 ;
V_111 -> V_117 = args -> V_117 ;
V_111 -> V_116 = F_26 ( args -> V_116 ) ;
memcpy ( V_111 -> V_115 , args -> V_114 , args -> V_113 ) ;
memcpy ( & V_111 -> V_115 [ args -> V_113 ] , args -> V_118 , args -> V_117 ) ;
V_110 -> V_9 . V_15 ++ ;
F_50 ( & V_110 -> V_9 . V_105 , V_27 ) ;
F_44 ( args -> V_106 , V_62 , V_107 | V_108 ) ;
F_35 ( V_32 , args -> V_106 ) ;
}
void
F_51 (
struct V_61 * V_119 ,
struct V_59 * V_60 )
{
F_52 ( V_119 , V_67 ) ;
V_119 -> V_78 . V_85 = 0 ;
V_119 -> V_78 . V_98 = V_90 ;
ASSERT ( V_119 -> V_78 . V_120 == 0 ) ;
ASSERT ( V_119 -> V_97 == NULL ) ;
F_44 ( V_60 , V_119 , V_107 ) ;
}
int
F_53 ( T_7 * args )
{
T_10 * V_110 ;
T_11 * V_111 ;
int V_26 , V_27 = 0 , V_121 , V_105 , V_19 ;
T_5 * V_32 ;
T_4 * V_62 ;
F_54 ( args ) ;
V_62 = args -> V_62 ;
V_32 = V_62 -> V_77 ;
V_26 = sizeof( T_8 ) ;
V_110 = ( T_10 * ) V_62 -> V_97 -> V_103 . V_104 ;
V_111 = & V_110 -> V_112 [ 0 ] ;
V_121 = V_110 -> V_9 . V_15 ;
for ( V_19 = 0 ; V_19 < V_121 ; V_111 = F_47 ( V_111 ) ,
V_26 += V_27 , V_19 ++ ) {
V_27 = F_55 ( V_111 ) ;
if ( V_111 -> V_113 != args -> V_113 )
continue;
if ( memcmp ( V_111 -> V_115 , args -> V_114 , args -> V_113 ) != 0 )
continue;
if ( ! F_24 ( args -> V_116 , V_111 -> V_116 ) )
continue;
break;
}
if ( V_19 == V_121 )
return - V_122 ;
V_121 = V_26 + V_27 ;
V_105 = F_3 ( V_110 -> V_9 . V_105 ) ;
if ( V_121 != V_105 )
memmove ( & ( ( char * ) V_110 ) [ V_26 ] , & ( ( char * ) V_110 ) [ V_121 ] , V_105 - V_121 ) ;
V_110 -> V_9 . V_15 -- ;
F_50 ( & V_110 -> V_9 . V_105 , - V_27 ) ;
V_105 -= V_27 ;
if ( V_105 == sizeof( T_8 ) &&
( V_32 -> V_86 & V_87 ) &&
( V_62 -> V_78 . V_80 != V_92 ) &&
! ( args -> V_123 & V_124 ) ) {
F_51 ( V_62 , args -> V_106 ) ;
} else {
F_43 ( V_62 , - V_27 , V_67 ) ;
V_62 -> V_78 . V_85 = F_27 ( V_62 , V_105 ) ;
ASSERT ( V_62 -> V_78 . V_85 ) ;
ASSERT ( V_105 > sizeof( T_8 ) ||
( args -> V_123 & V_124 ) ||
! ( V_32 -> V_86 & V_87 ) ||
V_62 -> V_78 . V_80 == V_92 ) ;
F_44 ( args -> V_106 , V_62 ,
V_107 | V_108 ) ;
}
F_35 ( V_32 , args -> V_106 ) ;
return 0 ;
}
int
F_56 ( T_7 * args )
{
T_10 * V_110 ;
T_11 * V_111 ;
int V_19 ;
T_9 * V_96 ;
F_57 ( args ) ;
V_96 = args -> V_62 -> V_97 ;
ASSERT ( V_96 -> V_99 & V_102 ) ;
V_110 = ( T_10 * ) V_96 -> V_103 . V_104 ;
V_111 = & V_110 -> V_112 [ 0 ] ;
for ( V_19 = 0 ; V_19 < V_110 -> V_9 . V_15 ;
V_111 = F_47 ( V_111 ) , V_19 ++ ) {
if ( V_111 -> V_113 != args -> V_113 )
continue;
if ( memcmp ( args -> V_114 , V_111 -> V_115 , args -> V_113 ) != 0 )
continue;
if ( ! F_24 ( args -> V_116 , V_111 -> V_116 ) )
continue;
return - V_125 ;
}
return - V_122 ;
}
int
F_58 ( T_7 * args )
{
T_10 * V_110 ;
T_11 * V_111 ;
int V_19 ;
ASSERT ( args -> V_62 -> V_97 -> V_99 == V_102 ) ;
V_110 = ( T_10 * ) args -> V_62 -> V_97 -> V_103 . V_104 ;
V_111 = & V_110 -> V_112 [ 0 ] ;
for ( V_19 = 0 ; V_19 < V_110 -> V_9 . V_15 ;
V_111 = F_47 ( V_111 ) , V_19 ++ ) {
if ( V_111 -> V_113 != args -> V_113 )
continue;
if ( memcmp ( args -> V_114 , V_111 -> V_115 , args -> V_113 ) != 0 )
continue;
if ( ! F_24 ( args -> V_116 , V_111 -> V_116 ) )
continue;
if ( args -> V_116 & V_126 ) {
args -> V_117 = V_111 -> V_117 ;
return - V_125 ;
}
if ( args -> V_117 < V_111 -> V_117 ) {
args -> V_117 = V_111 -> V_117 ;
return - V_127 ;
}
args -> V_117 = V_111 -> V_117 ;
memcpy ( args -> V_118 , & V_111 -> V_115 [ args -> V_113 ] ,
args -> V_117 ) ;
return - V_125 ;
}
return - V_122 ;
}
int
F_59 ( T_7 * args )
{
T_4 * V_62 ;
T_10 * V_110 ;
T_11 * V_111 ;
T_7 V_128 ;
char * V_129 ;
int error , V_19 , V_27 ;
T_2 V_46 ;
struct V_29 * V_30 ;
T_9 * V_96 ;
F_60 ( args ) ;
V_62 = args -> V_62 ;
V_96 = V_62 -> V_97 ;
V_110 = ( T_10 * ) V_96 -> V_103 . V_104 ;
V_27 = F_3 ( V_110 -> V_9 . V_105 ) ;
V_129 = F_61 ( V_27 , V_130 ) ;
ASSERT ( V_129 != NULL ) ;
memcpy ( V_129 , V_96 -> V_103 . V_104 , V_27 ) ;
V_110 = ( T_10 * ) V_129 ;
F_43 ( V_62 , - V_27 , V_67 ) ;
F_62 ( V_62 , V_67 ) ;
V_30 = NULL ;
error = F_63 ( args , & V_46 ) ;
if ( error ) {
if ( error == - V_131 )
goto V_132;
F_43 ( V_62 , V_27 , V_67 ) ;
memcpy ( V_96 -> V_103 . V_104 , V_129 , V_27 ) ;
goto V_132;
}
ASSERT ( V_46 == 0 ) ;
error = F_64 ( args , V_46 , & V_30 ) ;
if ( error ) {
error = F_65 ( args , 0 , V_30 ) ;
V_30 = NULL ;
if ( error )
goto V_132;
F_43 ( V_62 , V_27 , V_67 ) ;
memcpy ( V_96 -> V_103 . V_104 , V_129 , V_27 ) ;
goto V_132;
}
memset ( ( char * ) & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_62 = V_62 ;
V_128 . V_2 = args -> V_2 ;
V_128 . V_133 = args -> V_133 ;
V_128 . V_134 = args -> V_134 ;
V_128 . V_135 = args -> V_135 ;
V_128 . V_136 = V_67 ;
V_128 . V_106 = args -> V_106 ;
V_128 . V_123 = V_137 ;
V_111 = & V_110 -> V_112 [ 0 ] ;
for ( V_19 = 0 ; V_19 < V_110 -> V_9 . V_15 ; V_19 ++ ) {
V_128 . V_114 = V_111 -> V_115 ;
V_128 . V_113 = V_111 -> V_113 ;
V_128 . V_118 = & V_111 -> V_115 [ V_128 . V_113 ] ;
V_128 . V_117 = V_111 -> V_117 ;
V_128 . V_138 = F_66 ( V_111 -> V_115 ,
V_111 -> V_113 ) ;
V_128 . V_116 = F_67 ( V_111 -> V_116 ) ;
error = F_68 ( V_30 , & V_128 ) ;
ASSERT ( error == - V_122 ) ;
error = F_69 ( V_30 , & V_128 ) ;
ASSERT ( error != - V_139 ) ;
if ( error )
goto V_132;
V_111 = F_47 ( V_111 ) ;
}
error = 0 ;
V_132:
F_70 ( V_129 ) ;
return error ;
}
int
F_71 (
struct V_29 * V_30 ,
struct V_61 * V_62 )
{
struct V_5 * V_35 ;
struct V_140 * V_141 ;
T_12 * V_142 ;
struct V_3 V_143 ;
int V_72 ;
int V_19 ;
struct V_31 * V_32 = V_30 -> V_33 -> V_34 ;
V_35 = V_30 -> V_36 ;
F_5 ( V_32 -> V_41 , & V_143 , V_35 ) ;
V_141 = F_72 ( V_35 ) ;
V_72 = sizeof( struct V_144 ) ;
for ( V_19 = 0 ; V_19 < V_143 . V_15 ; V_141 ++ , V_19 ++ ) {
if ( V_141 -> V_116 & V_145 )
continue;
if ( ! ( V_141 -> V_116 & V_146 ) )
return 0 ;
V_142 = F_73 ( V_35 , V_19 ) ;
if ( V_142 -> V_113 >= V_147 )
return 0 ;
if ( F_3 ( V_142 -> V_117 ) >= V_147 )
return 0 ;
V_72 += sizeof( struct V_148 ) - 1
+ V_142 -> V_113
+ F_3 ( V_142 -> V_117 ) ;
}
if ( ( V_62 -> V_77 -> V_86 & V_87 ) &&
( V_62 -> V_78 . V_80 != V_92 ) &&
( V_72 == sizeof( struct V_144 ) ) )
return - 1 ;
return F_27 ( V_62 , V_72 ) ;
}
int
F_74 (
struct V_29 * V_30 ,
struct V_149 * args ,
int V_109 )
{
struct V_5 * V_35 ;
struct V_3 V_40 ;
struct V_140 * V_141 ;
struct V_150 * V_142 ;
struct V_149 V_128 ;
struct V_61 * V_62 = args -> V_62 ;
char * V_129 ;
int error ;
int V_19 ;
F_75 ( args ) ;
V_129 = F_61 ( args -> V_2 -> V_17 , V_130 ) ;
if ( ! V_129 )
return - V_151 ;
memcpy ( V_129 , V_30 -> V_36 , args -> V_2 -> V_17 ) ;
V_35 = ( V_152 * ) V_129 ;
F_5 ( args -> V_2 , & V_40 , V_35 ) ;
V_141 = F_72 ( V_35 ) ;
memset ( V_30 -> V_36 , 0 , args -> V_2 -> V_17 ) ;
error = F_65 ( args , 0 , V_30 ) ;
if ( error )
goto V_132;
if ( V_109 == - 1 ) {
ASSERT ( V_62 -> V_77 -> V_86 & V_87 ) ;
ASSERT ( V_62 -> V_78 . V_80 != V_92 ) ;
F_51 ( V_62 , args -> V_106 ) ;
goto V_132;
}
F_41 ( args ) ;
memset ( ( char * ) & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_2 = args -> V_2 ;
V_128 . V_62 = V_62 ;
V_128 . V_133 = args -> V_133 ;
V_128 . V_134 = args -> V_134 ;
V_128 . V_135 = args -> V_135 ;
V_128 . V_136 = V_67 ;
V_128 . V_106 = args -> V_106 ;
V_128 . V_123 = V_137 ;
for ( V_19 = 0 ; V_19 < V_40 . V_15 ; V_141 ++ , V_19 ++ ) {
if ( V_141 -> V_116 & V_145 )
continue;
if ( ! V_141 -> V_153 )
continue;
ASSERT ( V_141 -> V_116 & V_146 ) ;
V_142 = F_73 ( V_35 , V_19 ) ;
V_128 . V_114 = V_142 -> V_115 ;
V_128 . V_113 = V_142 -> V_113 ;
V_128 . V_118 = & V_142 -> V_115 [ V_128 . V_113 ] ;
V_128 . V_117 = F_3 ( V_142 -> V_117 ) ;
V_128 . V_138 = F_6 ( V_141 -> V_138 ) ;
V_128 . V_116 = F_67 ( V_141 -> V_116 ) ;
F_45 ( & V_128 , V_109 ) ;
}
error = 0 ;
V_132:
F_70 ( V_129 ) ;
return error ;
}
int
F_76 (
struct V_149 * args )
{
struct V_5 * V_35 ;
struct V_3 V_154 ;
struct V_140 * V_155 ;
struct V_156 * V_157 ;
struct V_158 V_159 ;
struct V_160 * V_161 ;
struct V_61 * V_62 = args -> V_62 ;
struct V_31 * V_32 = V_62 -> V_77 ;
struct V_29 * V_162 = NULL ;
struct V_29 * V_163 = NULL ;
T_2 V_46 ;
int error ;
F_77 ( args ) ;
error = F_63 ( args , & V_46 ) ;
if ( error )
goto V_132;
error = F_21 ( args -> V_106 , V_62 , 0 , - 1 , & V_162 ) ;
if ( error )
goto V_132;
error = F_78 ( args -> V_106 , V_62 , V_46 , - 1 , & V_163 , V_67 ) ;
if ( error )
goto V_132;
F_23 ( args -> V_106 , V_163 , V_69 ) ;
V_163 -> V_164 = V_162 -> V_164 ;
memcpy ( V_163 -> V_36 , V_162 -> V_36 , args -> V_2 -> V_17 ) ;
if ( F_10 ( & V_32 -> V_42 ) ) {
struct V_165 * V_8 = V_163 -> V_36 ;
V_8 -> V_46 = F_17 ( V_163 -> V_47 ) ;
}
F_79 ( args -> V_106 , V_163 , 0 , args -> V_2 -> V_17 - 1 ) ;
error = F_80 ( args , 0 , 1 , & V_162 , V_67 ) ;
if ( error )
goto V_132;
V_161 = V_162 -> V_36 ;
V_62 -> V_166 -> V_167 ( & V_159 , V_161 ) ;
V_157 = V_62 -> V_166 -> V_168 ( V_161 ) ;
V_35 = V_163 -> V_36 ;
F_5 ( args -> V_2 , & V_154 , V_35 ) ;
V_155 = F_72 ( V_35 ) ;
V_157 [ 0 ] . V_138 = V_155 [ V_154 . V_15 - 1 ] . V_138 ;
V_157 [ 0 ] . V_169 = F_8 ( V_46 ) ;
V_159 . V_15 = 1 ;
V_62 -> V_166 -> V_170 ( V_161 , & V_159 ) ;
F_79 ( args -> V_106 , V_162 , 0 , args -> V_2 -> V_17 - 1 ) ;
error = 0 ;
V_132:
return error ;
}
STATIC int
F_64 (
struct V_149 * args ,
T_2 V_46 ,
struct V_29 * * V_65 )
{
struct V_5 * V_35 ;
struct V_3 V_40 ;
struct V_61 * V_62 = args -> V_62 ;
struct V_31 * V_32 = V_62 -> V_77 ;
struct V_29 * V_30 ;
int error ;
F_81 ( args ) ;
error = F_78 ( args -> V_106 , args -> V_62 , V_46 , - 1 , & V_30 ,
V_67 ) ;
if ( error )
return error ;
V_30 -> V_164 = & V_68 ;
F_23 ( args -> V_106 , V_30 , V_69 ) ;
V_35 = V_30 -> V_36 ;
memset ( V_35 , 0 , args -> V_2 -> V_17 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_13 = args -> V_2 -> V_17 ;
if ( F_10 ( & V_32 -> V_42 ) ) {
struct V_165 * V_8 = V_30 -> V_36 ;
V_40 . V_11 = V_12 ;
V_8 -> V_46 = F_17 ( V_30 -> V_47 ) ;
V_8 -> V_171 = F_17 ( V_62 -> V_172 ) ;
F_82 ( & V_8 -> V_44 , & V_32 -> V_42 . V_45 ) ;
V_40 . V_25 [ 0 ] . V_26 = sizeof( struct V_7 ) ;
} else {
V_40 . V_11 = V_20 ;
V_40 . V_25 [ 0 ] . V_26 = sizeof( struct V_173 ) ;
}
V_40 . V_25 [ 0 ] . V_27 = V_40 . V_13 - V_40 . V_25 [ 0 ] . V_26 ;
F_7 ( args -> V_2 , V_35 , & V_40 ) ;
F_79 ( args -> V_106 , V_30 , 0 , args -> V_2 -> V_17 - 1 ) ;
* V_65 = V_30 ;
return 0 ;
}
int
F_83 (
struct V_174 * V_175 ,
struct V_176 * V_177 ,
struct V_176 * V_178 )
{
T_2 V_46 ;
int error ;
F_84 ( V_175 -> args ) ;
ASSERT ( V_177 -> V_11 == V_20 ) ;
error = F_63 ( V_175 -> args , & V_46 ) ;
if ( error )
return error ;
error = F_64 ( V_175 -> args , V_46 , & V_178 -> V_30 ) ;
if ( error )
return error ;
V_178 -> V_46 = V_46 ;
V_178 -> V_11 = V_20 ;
F_85 ( V_175 , V_177 , V_178 ) ;
error = F_86 ( V_175 , V_177 , V_178 ) ;
if ( error )
return error ;
if ( V_175 -> V_179 ) {
F_87 ( V_175 -> args ) ;
error = F_69 ( V_177 -> V_30 , V_175 -> args ) ;
} else {
F_88 ( V_175 -> args ) ;
error = F_69 ( V_178 -> V_30 , V_175 -> args ) ;
}
V_177 -> V_138 = F_89 ( V_177 -> V_30 , NULL ) ;
V_178 -> V_138 = F_89 ( V_178 -> V_30 , NULL ) ;
return error ;
}
int
F_69 (
struct V_29 * V_30 ,
struct V_149 * args )
{
struct V_5 * V_35 ;
struct V_3 V_40 ;
int V_180 ;
int V_181 ;
int V_182 ;
int V_183 ;
int V_19 ;
F_90 ( args ) ;
V_35 = V_30 -> V_36 ;
F_5 ( args -> V_2 , & V_40 , V_35 ) ;
ASSERT ( args -> V_184 >= 0 && args -> V_184 <= V_40 . V_15 ) ;
V_181 = F_91 ( args , NULL ) ;
V_180 = ( V_40 . V_15 + 1 ) * sizeof( V_185 )
+ F_92 ( V_35 ) ;
for ( V_182 = 0 , V_19 = V_24 - 1 ; V_19 >= 0 ; V_19 -- ) {
if ( V_180 > V_40 . V_13 ) {
V_182 += V_40 . V_25 [ V_19 ] . V_27 ;
continue;
}
if ( ! V_40 . V_25 [ V_19 ] . V_27 )
continue;
V_183 = V_181 ;
if ( V_40 . V_25 [ V_19 ] . V_26 < V_40 . V_13 )
V_183 += sizeof( V_185 ) ;
if ( V_40 . V_25 [ V_19 ] . V_27 >= V_183 ) {
V_183 = F_93 ( V_30 , & V_40 , args , V_19 ) ;
goto V_186;
}
V_182 += V_40 . V_25 [ V_19 ] . V_27 ;
}
if ( ! V_40 . V_23 && V_182 < V_181 )
return - V_139 ;
F_94 ( args , & V_40 , V_30 ) ;
if ( V_40 . V_25 [ 0 ] . V_27 < ( V_181 + sizeof( V_185 ) ) ) {
V_183 = - V_139 ;
goto V_186;
}
V_183 = F_93 ( V_30 , & V_40 , args , 0 ) ;
V_186:
F_7 ( args -> V_2 , V_35 , & V_40 ) ;
F_79 ( args -> V_106 , V_30 ,
F_95 ( V_35 , & V_35 -> V_9 ,
F_92 ( V_35 ) ) ) ;
return V_183 ;
}
STATIC int
F_93 (
struct V_29 * V_30 ,
struct V_3 * V_40 ,
struct V_149 * args ,
int V_187 )
{
struct V_5 * V_35 ;
struct V_140 * V_141 ;
struct V_150 * V_142 ;
struct V_188 * V_189 ;
struct V_31 * V_32 ;
int V_183 ;
int V_19 ;
F_96 ( args ) ;
V_35 = V_30 -> V_36 ;
ASSERT ( V_187 >= 0 && V_187 < V_24 ) ;
ASSERT ( args -> V_184 >= 0 && args -> V_184 <= V_40 -> V_15 ) ;
V_141 = & F_72 ( V_35 ) [ args -> V_184 ] ;
if ( args -> V_184 < V_40 -> V_15 ) {
V_183 = V_40 -> V_15 - args -> V_184 ;
V_183 *= sizeof( V_185 ) ;
memmove ( V_141 + 1 , V_141 , V_183 ) ;
F_79 ( args -> V_106 , V_30 ,
F_95 ( V_35 , V_141 , V_183 + sizeof( * V_141 ) ) ) ;
}
V_40 -> V_15 ++ ;
V_32 = args -> V_106 -> V_190 ;
ASSERT ( V_40 -> V_25 [ V_187 ] . V_26 < args -> V_2 -> V_17 ) ;
ASSERT ( ( V_40 -> V_25 [ V_187 ] . V_26 & 0x3 ) == 0 ) ;
ASSERT ( V_40 -> V_25 [ V_187 ] . V_27 >=
F_91 ( args , NULL ) ) ;
ASSERT ( V_40 -> V_25 [ V_187 ] . V_27 < args -> V_2 -> V_17 ) ;
ASSERT ( ( V_40 -> V_25 [ V_187 ] . V_27 & 0x3 ) == 0 ) ;
V_40 -> V_25 [ V_187 ] . V_27 -= F_91 ( args , & V_183 ) ;
V_141 -> V_153 = F_2 ( V_40 -> V_25 [ V_187 ] . V_26 +
V_40 -> V_25 [ V_187 ] . V_27 ) ;
V_141 -> V_138 = F_8 ( args -> V_138 ) ;
V_141 -> V_116 = V_183 ? V_146 : 0 ;
V_141 -> V_116 |= F_26 ( args -> V_116 ) ;
if ( args -> V_123 & V_191 ) {
V_141 -> V_116 |= V_145 ;
if ( ( args -> V_192 == args -> V_46 ) &&
( args -> V_193 <= args -> V_184 ) ) {
args -> V_193 ++ ;
}
}
F_79 ( args -> V_106 , V_30 ,
F_95 ( V_35 , V_141 , sizeof( * V_141 ) ) ) ;
ASSERT ( ( args -> V_184 == 0 ) ||
( F_6 ( V_141 -> V_138 ) >= F_6 ( ( V_141 - 1 ) -> V_138 ) ) ) ;
ASSERT ( ( args -> V_184 == V_40 -> V_15 - 1 ) ||
( F_6 ( V_141 -> V_138 ) <= F_6 ( ( V_141 + 1 ) -> V_138 ) ) ) ;
if ( V_141 -> V_116 & V_146 ) {
V_142 = F_73 ( V_35 , args -> V_184 ) ;
V_142 -> V_113 = args -> V_113 ;
V_142 -> V_117 = F_2 ( args -> V_117 ) ;
memcpy ( ( char * ) V_142 -> V_115 , args -> V_114 , args -> V_113 ) ;
memcpy ( ( char * ) & V_142 -> V_115 [ args -> V_113 ] , args -> V_118 ,
F_3 ( V_142 -> V_117 ) ) ;
} else {
V_189 = F_97 ( V_35 , args -> V_184 ) ;
V_189 -> V_113 = args -> V_113 ;
memcpy ( ( char * ) V_189 -> V_114 , args -> V_114 , args -> V_113 ) ;
V_141 -> V_116 |= V_145 ;
V_189 -> V_117 = 0 ;
V_189 -> V_194 = 0 ;
args -> V_195 = 1 ;
args -> V_196 = F_98 ( V_32 , args -> V_117 ) ;
args -> V_197 = args -> V_117 ;
}
F_79 ( args -> V_106 , V_30 ,
F_95 ( V_35 , F_99 ( V_35 , args -> V_184 ) ,
F_100 ( V_35 , args -> V_184 ) ) ) ;
if ( F_3 ( V_141 -> V_153 ) < V_40 -> V_13 )
V_40 -> V_13 = F_3 ( V_141 -> V_153 ) ;
ASSERT ( V_40 -> V_13 >= V_40 -> V_15 * sizeof( V_185 )
+ F_92 ( V_35 ) ) ;
V_183 = ( V_40 -> V_15 - 1 ) * sizeof( V_185 )
+ F_92 ( V_35 ) ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
if ( V_40 -> V_25 [ V_19 ] . V_26 == V_183 ) {
V_40 -> V_25 [ V_19 ] . V_26 += sizeof( V_185 ) ;
V_40 -> V_25 [ V_19 ] . V_27 -= sizeof( V_185 ) ;
}
}
V_40 -> V_16 += F_100 ( V_35 , args -> V_184 ) ;
return 0 ;
}
STATIC void
F_94 (
struct V_149 * args ,
struct V_3 * V_198 ,
struct V_29 * V_30 )
{
struct V_5 * V_199 ;
struct V_5 * V_200 ;
struct V_3 V_201 ;
struct V_59 * V_106 = args -> V_106 ;
char * V_129 ;
F_101 ( args ) ;
V_129 = F_61 ( args -> V_2 -> V_17 , V_130 ) ;
memcpy ( V_129 , V_30 -> V_36 , args -> V_2 -> V_17 ) ;
memset ( V_30 -> V_36 , 0 , args -> V_2 -> V_17 ) ;
V_199 = ( V_152 * ) V_129 ;
V_200 = V_30 -> V_36 ;
memcpy ( V_30 -> V_36 , V_129 , F_92 ( V_199 ) ) ;
V_201 = * V_198 ;
V_198 -> V_13 = args -> V_2 -> V_17 ;
V_198 -> V_16 = 0 ;
V_198 -> V_15 = 0 ;
V_198 -> V_23 = 0 ;
V_198 -> V_25 [ 0 ] . V_26 = F_92 ( V_199 ) ;
V_198 -> V_25 [ 0 ] . V_27 = V_198 -> V_13 -
V_198 -> V_25 [ 0 ] . V_26 ;
F_7 ( args -> V_2 , V_200 , V_198 ) ;
F_102 ( args , V_199 , & V_201 , 0 ,
V_200 , V_198 , 0 , V_201 . V_15 ) ;
F_79 ( V_106 , V_30 , 0 , args -> V_2 -> V_17 - 1 ) ;
F_70 ( V_129 ) ;
}
static int
F_103 (
struct V_29 * V_202 ,
struct V_3 * V_203 ,
struct V_29 * V_204 ,
struct V_3 * V_205 )
{
struct V_140 * V_206 ;
struct V_140 * V_207 ;
V_206 = F_72 ( V_202 -> V_36 ) ;
V_207 = F_72 ( V_204 -> V_36 ) ;
if ( V_203 -> V_15 > 0 && V_205 -> V_15 > 0 &&
( ( F_6 ( V_207 [ 0 ] . V_138 ) <
F_6 ( V_206 [ 0 ] . V_138 ) ) ||
( F_6 ( V_207 [ V_205 -> V_15 - 1 ] . V_138 ) <
F_6 ( V_206 [ V_203 -> V_15 - 1 ] . V_138 ) ) ) ) {
return 1 ;
}
return 0 ;
}
int
F_104 (
struct V_29 * V_202 ,
struct V_29 * V_204 )
{
struct V_3 V_208 ;
struct V_3 V_209 ;
struct V_31 * V_32 = V_202 -> V_33 -> V_34 ;
F_5 ( V_32 -> V_41 , & V_208 , V_202 -> V_36 ) ;
F_5 ( V_32 -> V_41 , & V_209 , V_204 -> V_36 ) ;
return F_103 ( V_202 , & V_208 , V_204 , & V_209 ) ;
}
STATIC void
F_85 (
struct V_174 * V_175 ,
struct V_176 * V_210 ,
struct V_176 * V_211 )
{
struct V_149 * args ;
struct V_5 * V_212 ;
struct V_5 * V_213 ;
struct V_3 V_208 ;
struct V_3 V_209 ;
struct V_140 * V_206 ;
struct V_140 * V_207 ;
int V_15 ;
int V_214 ;
int V_215 ;
int V_216 ;
int V_217 ;
ASSERT ( V_210 -> V_11 == V_20 ) ;
ASSERT ( V_211 -> V_11 == V_20 ) ;
V_212 = V_210 -> V_30 -> V_36 ;
V_213 = V_211 -> V_30 -> V_36 ;
F_5 ( V_175 -> args -> V_2 , & V_208 , V_212 ) ;
F_5 ( V_175 -> args -> V_2 , & V_209 , V_213 ) ;
ASSERT ( V_209 . V_15 == 0 ) ;
args = V_175 -> args ;
F_105 ( args ) ;
V_217 = 0 ;
if ( F_103 ( V_210 -> V_30 , & V_208 , V_211 -> V_30 , & V_209 ) ) {
struct V_176 * V_218 ;
struct V_3 V_219 ;
V_218 = V_210 ;
V_210 = V_211 ;
V_211 = V_218 ;
V_219 = V_208 ;
V_208 = V_209 ;
V_209 = V_219 ;
V_212 = V_210 -> V_30 -> V_36 ;
V_213 = V_211 -> V_30 -> V_36 ;
V_217 = 1 ;
}
V_175 -> V_179 = F_106 ( V_175 , V_210 , & V_208 ,
V_211 , & V_209 ,
& V_15 , & V_214 ) ;
if ( V_217 )
V_175 -> V_179 = ! V_175 -> V_179 ;
if ( V_15 < V_208 . V_15 ) {
V_15 = V_208 . V_15 - V_15 ;
V_216 = V_208 . V_16 - V_214 ;
V_216 += V_15 * sizeof( V_185 ) ;
V_215 = V_209 . V_13 - F_92 ( V_212 ) ;
V_215 -= V_209 . V_15 * sizeof( V_185 ) ;
if ( V_216 > V_215 )
F_94 ( args , & V_209 , V_211 -> V_30 ) ;
F_102 ( args , V_212 , & V_208 ,
V_208 . V_15 - V_15 , V_213 , & V_209 , 0 , V_15 ) ;
} else if ( V_15 > V_208 . V_15 ) {
ASSERT ( 0 ) ;
V_15 -= V_208 . V_15 ;
V_216 = V_214 - V_208 . V_16 ;
V_216 += V_15 * sizeof( V_185 ) ;
V_215 = V_208 . V_13 - F_92 ( V_212 ) ;
V_215 -= V_208 . V_15 * sizeof( V_185 ) ;
if ( V_216 > V_215 )
F_94 ( args , & V_208 , V_210 -> V_30 ) ;
F_102 ( args , V_213 , & V_209 , 0 , V_212 , & V_208 ,
V_208 . V_15 , V_15 ) ;
}
F_7 ( V_175 -> args -> V_2 , V_212 , & V_208 ) ;
F_7 ( V_175 -> args -> V_2 , V_213 , & V_209 ) ;
F_79 ( args -> V_106 , V_210 -> V_30 , 0 , args -> V_2 -> V_17 - 1 ) ;
F_79 ( args -> V_106 , V_211 -> V_30 , 0 , args -> V_2 -> V_17 - 1 ) ;
V_206 = F_72 ( V_212 ) ;
V_207 = F_72 ( V_213 ) ;
V_210 -> V_138 = F_6 ( V_206 [ V_208 . V_15 - 1 ] . V_138 ) ;
V_211 -> V_138 = F_6 ( V_207 [ V_209 . V_15 - 1 ] . V_138 ) ;
if ( V_210 -> V_184 > V_208 . V_15 ) {
ASSERT ( V_175 -> V_179 == 0 ) ;
V_211 -> V_184 = V_210 -> V_184 - V_208 . V_15 ;
args -> V_184 = args -> V_193 = V_211 -> V_184 ;
args -> V_46 = args -> V_192 = V_211 -> V_46 ;
} else if ( V_210 -> V_184 == V_208 . V_15 ) {
if ( V_175 -> V_179 ) {
args -> V_184 = V_210 -> V_184 ;
args -> V_46 = V_210 -> V_46 ;
args -> V_193 = 0 ;
args -> V_192 = V_211 -> V_46 ;
} else {
V_211 -> V_184 = V_210 -> V_184 - V_208 . V_15 ;
args -> V_184 = V_211 -> V_184 ;
args -> V_46 = V_211 -> V_46 ;
if ( ! V_175 -> V_220 ) {
args -> V_193 = V_211 -> V_184 ;
args -> V_192 = V_211 -> V_46 ;
}
}
} else {
ASSERT ( V_175 -> V_179 == 1 ) ;
args -> V_184 = args -> V_193 = V_210 -> V_184 ;
args -> V_46 = args -> V_192 = V_210 -> V_46 ;
}
}
STATIC int
F_106 (
struct V_174 * V_175 ,
struct V_176 * V_210 ,
struct V_3 * V_208 ,
struct V_176 * V_211 ,
struct V_3 * V_209 ,
int * V_221 ,
int * V_222 )
{
struct V_5 * V_212 = V_210 -> V_30 -> V_36 ;
struct V_5 * V_213 = V_211 -> V_30 -> V_36 ;
struct V_140 * V_141 ;
int V_15 ;
int V_215 ;
int V_184 ;
int V_214 = 0 ;
int V_223 ;
int V_224 ;
int V_225 = 0 ;
int V_183 ;
V_215 = V_208 -> V_15 + V_209 -> V_15 ;
V_223 = ( V_215 + 1 ) * sizeof( * V_141 ) ;
V_223 += V_208 -> V_16 + V_209 -> V_16 +
F_91 ( V_175 -> args , NULL ) ;
V_223 /= 2 ;
V_224 = V_175 -> args -> V_2 -> V_17 ;
V_141 = F_72 ( V_212 ) ;
for ( V_15 = V_184 = 0 ; V_15 < V_215 ; V_141 ++ , V_184 ++ , V_15 ++ ) {
#define F_107 ( T_13 ) (((A) < 0) ? -(A) : (A))
if ( V_15 == V_210 -> V_184 ) {
V_183 = V_214 + sizeof( * V_141 ) +
F_91 ( V_175 -> args , NULL ) ;
if ( F_107 ( V_223 - V_183 ) > V_224 )
break;
V_224 = F_107 ( V_223 - V_183 ) ;
V_214 = V_183 ;
V_225 = 1 ;
}
if ( V_15 == V_208 -> V_15 ) {
V_212 = V_213 ;
V_141 = F_72 ( V_212 ) ;
V_184 = 0 ;
}
V_183 = V_214 + sizeof( * V_141 ) + F_100 ( V_212 ,
V_184 ) ;
if ( F_107 ( V_223 - V_183 ) > V_224 )
break;
V_224 = F_107 ( V_223 - V_183 ) ;
V_214 = V_183 ;
#undef F_107
}
V_214 -= V_15 * sizeof( * V_141 ) ;
if ( V_225 ) {
V_214 -= sizeof( * V_141 ) +
F_91 ( V_175 -> args , NULL ) ;
}
* V_221 = V_15 ;
* V_222 = V_214 ;
return V_225 ;
}
int
F_108 (
struct V_174 * V_175 ,
int * V_226 )
{
struct V_5 * V_35 ;
struct V_176 * V_227 ;
struct V_3 V_40 ;
struct V_29 * V_30 ;
T_2 V_46 ;
int V_72 ;
int V_228 ;
int error ;
int V_229 ;
int V_19 ;
F_109 ( V_175 -> args ) ;
V_227 = & V_175 -> V_230 . V_227 [ V_175 -> V_230 . V_231 - 1 ] ;
V_35 = V_227 -> V_30 -> V_36 ;
F_5 ( V_175 -> args -> V_2 , & V_40 , V_35 ) ;
V_72 = F_92 ( V_35 ) +
V_40 . V_15 * sizeof( V_185 ) +
V_40 . V_16 ;
if ( V_72 > ( V_175 -> args -> V_2 -> V_17 >> 1 ) ) {
* V_226 = 0 ;
return 0 ;
}
if ( V_40 . V_15 == 0 ) {
V_228 = ( V_40 . V_21 != 0 ) ;
memcpy ( & V_175 -> V_232 , & V_175 -> V_230 , sizeof( V_175 -> V_230 ) ) ;
error = F_110 ( V_175 , & V_175 -> V_232 , V_228 ,
0 , & V_229 ) ;
if ( error )
return error ;
if ( V_229 ) {
* V_226 = 0 ;
} else {
* V_226 = 2 ;
}
return 0 ;
}
V_228 = V_40 . V_21 < V_40 . V_22 ;
for ( V_19 = 0 ; V_19 < 2 ; V_228 = ! V_228 , V_19 ++ ) {
struct V_3 V_209 ;
if ( V_228 )
V_46 = V_40 . V_21 ;
else
V_46 = V_40 . V_22 ;
if ( V_46 == 0 )
continue;
error = F_21 ( V_175 -> args -> V_106 , V_175 -> args -> V_62 ,
V_46 , - 1 , & V_30 ) ;
if ( error )
return error ;
F_5 ( V_175 -> args -> V_2 , & V_209 , V_30 -> V_36 ) ;
V_72 = V_175 -> args -> V_2 -> V_17 -
( V_175 -> args -> V_2 -> V_17 >> 2 ) -
V_40 . V_16 - V_209 . V_16 -
( ( V_40 . V_15 + V_209 . V_15 ) *
sizeof( V_185 ) ) -
F_92 ( V_35 ) ;
F_111 ( V_175 -> args -> V_106 , V_30 ) ;
if ( V_72 >= 0 )
break;
}
if ( V_19 >= 2 ) {
* V_226 = 0 ;
return 0 ;
}
memcpy ( & V_175 -> V_232 , & V_175 -> V_230 , sizeof( V_175 -> V_230 ) ) ;
if ( V_46 < V_227 -> V_46 ) {
error = F_110 ( V_175 , & V_175 -> V_232 , V_228 ,
0 , & V_229 ) ;
} else {
error = F_110 ( V_175 , & V_175 -> V_230 , V_228 ,
0 , & V_229 ) ;
}
if ( error )
return error ;
if ( V_229 ) {
* V_226 = 0 ;
} else {
* V_226 = 1 ;
}
return 0 ;
}
int
F_112 (
struct V_29 * V_30 ,
struct V_149 * args )
{
struct V_5 * V_35 ;
struct V_3 V_40 ;
struct V_140 * V_141 ;
int V_169 ;
int V_233 ;
int V_234 ;
int V_181 ;
int V_180 ;
int V_183 ;
int V_19 ;
F_113 ( args ) ;
V_35 = V_30 -> V_36 ;
F_5 ( args -> V_2 , & V_40 , V_35 ) ;
ASSERT ( V_40 . V_15 > 0 && V_40 . V_15 < args -> V_2 -> V_17 / 8 ) ;
ASSERT ( args -> V_184 >= 0 && args -> V_184 < V_40 . V_15 ) ;
ASSERT ( V_40 . V_13 >= V_40 . V_15 * sizeof( * V_141 ) +
F_92 ( V_35 ) ) ;
V_141 = & F_72 ( V_35 ) [ args -> V_184 ] ;
ASSERT ( F_3 ( V_141 -> V_153 ) >= V_40 . V_13 ) ;
ASSERT ( F_3 ( V_141 -> V_153 ) < args -> V_2 -> V_17 ) ;
V_180 = V_40 . V_15 * sizeof( V_185 )
+ F_92 ( V_35 ) ;
V_183 = V_40 . V_25 [ 0 ] . V_27 ;
V_169 = V_233 = - 1 ;
V_234 = V_24 - 1 ;
V_181 = F_100 ( V_35 , args -> V_184 ) ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
ASSERT ( V_40 . V_25 [ V_19 ] . V_26 < args -> V_2 -> V_17 ) ;
ASSERT ( V_40 . V_25 [ V_19 ] . V_27 < args -> V_2 -> V_17 ) ;
if ( V_40 . V_25 [ V_19 ] . V_26 == V_180 ) {
V_40 . V_25 [ V_19 ] . V_26 -= sizeof( V_185 ) ;
V_40 . V_25 [ V_19 ] . V_27 += sizeof( V_185 ) ;
}
if ( V_40 . V_25 [ V_19 ] . V_26 + V_40 . V_25 [ V_19 ] . V_27 ==
F_3 ( V_141 -> V_153 ) ) {
V_169 = V_19 ;
} else if ( V_40 . V_25 [ V_19 ] . V_26 ==
( F_3 ( V_141 -> V_153 ) + V_181 ) ) {
V_233 = V_19 ;
} else if ( V_40 . V_25 [ V_19 ] . V_27 < V_183 ) {
V_183 = V_40 . V_25 [ V_19 ] . V_27 ;
V_234 = V_19 ;
}
}
if ( ( V_169 >= 0 ) || ( V_233 >= 0 ) ) {
if ( ( V_169 >= 0 ) && ( V_233 >= 0 ) ) {
V_40 . V_25 [ V_169 ] . V_27 += V_181 ;
V_40 . V_25 [ V_169 ] . V_27 += V_40 . V_25 [ V_233 ] . V_27 ;
V_40 . V_25 [ V_233 ] . V_26 = 0 ;
V_40 . V_25 [ V_233 ] . V_27 = 0 ;
} else if ( V_169 >= 0 ) {
V_40 . V_25 [ V_169 ] . V_27 += V_181 ;
} else {
V_40 . V_25 [ V_233 ] . V_26 = F_3 ( V_141 -> V_153 ) ;
V_40 . V_25 [ V_233 ] . V_27 += V_181 ;
}
} else {
if ( V_40 . V_25 [ V_234 ] . V_27 < V_181 ) {
V_40 . V_25 [ V_234 ] . V_26 = F_3 ( V_141 -> V_153 ) ;
V_40 . V_25 [ V_234 ] . V_27 = V_181 ;
}
}
if ( F_3 ( V_141 -> V_153 ) == V_40 . V_13 )
V_234 = 1 ;
else
V_234 = 0 ;
memset ( F_99 ( V_35 , args -> V_184 ) , 0 , V_181 ) ;
V_40 . V_16 -= V_181 ;
F_79 ( args -> V_106 , V_30 ,
F_95 ( V_35 , F_99 ( V_35 , args -> V_184 ) ,
V_181 ) ) ;
V_183 = ( V_40 . V_15 - args -> V_184 ) * sizeof( V_185 ) ;
memmove ( V_141 , V_141 + 1 , V_183 ) ;
V_40 . V_15 -- ;
F_79 ( args -> V_106 , V_30 ,
F_95 ( V_35 , V_141 , V_183 + sizeof( V_185 ) ) ) ;
V_141 = & F_72 ( V_35 ) [ V_40 . V_15 ] ;
memset ( V_141 , 0 , sizeof( V_185 ) ) ;
if ( V_234 ) {
V_183 = args -> V_2 -> V_17 ;
V_141 = F_72 ( V_35 ) ;
for ( V_19 = V_40 . V_15 - 1 ; V_19 >= 0 ; V_141 ++ , V_19 -- ) {
ASSERT ( F_3 ( V_141 -> V_153 ) >= V_40 . V_13 ) ;
ASSERT ( F_3 ( V_141 -> V_153 ) < args -> V_2 -> V_17 ) ;
if ( F_3 ( V_141 -> V_153 ) < V_183 )
V_183 = F_3 ( V_141 -> V_153 ) ;
}
V_40 . V_13 = V_183 ;
ASSERT ( V_40 . V_13 != 0 ) ;
} else {
V_40 . V_23 = 1 ;
}
F_7 ( args -> V_2 , V_35 , & V_40 ) ;
F_79 ( args -> V_106 , V_30 ,
F_95 ( V_35 , & V_35 -> V_9 ,
F_92 ( V_35 ) ) ) ;
V_183 = V_40 . V_16 + F_92 ( V_35 ) +
V_40 . V_15 * sizeof( V_185 ) ;
return V_183 < args -> V_2 -> V_235 ;
}
void
F_114 (
struct V_174 * V_175 ,
struct V_176 * V_236 ,
struct V_176 * V_237 )
{
struct V_5 * V_238 = V_236 -> V_30 -> V_36 ;
struct V_5 * V_239 = V_237 -> V_30 -> V_36 ;
struct V_3 V_240 ;
struct V_3 V_241 ;
struct V_140 * V_141 ;
F_115 ( V_175 -> args ) ;
V_238 = V_236 -> V_30 -> V_36 ;
V_239 = V_237 -> V_30 -> V_36 ;
F_5 ( V_175 -> args -> V_2 , & V_240 , V_238 ) ;
F_5 ( V_175 -> args -> V_2 , & V_241 , V_239 ) ;
V_141 = F_72 ( V_238 ) ;
V_236 -> V_138 = F_6 ( V_141 [ V_240 . V_15 - 1 ] . V_138 ) ;
if ( V_241 . V_23 == 0 ) {
if ( F_103 ( V_237 -> V_30 , & V_241 ,
V_236 -> V_30 , & V_240 ) ) {
F_102 ( V_175 -> args ,
V_238 , & V_240 , 0 ,
V_239 , & V_241 , 0 ,
V_240 . V_15 ) ;
} else {
F_102 ( V_175 -> args ,
V_238 , & V_240 , 0 ,
V_239 , & V_241 ,
V_241 . V_15 , V_240 . V_15 ) ;
}
} else {
struct V_5 * V_242 ;
struct V_3 V_243 ;
V_242 = F_116 ( V_175 -> args -> V_2 -> V_17 , V_130 ) ;
memcpy ( V_242 , V_239 , F_92 ( V_239 ) ) ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_243 . V_11 = V_241 . V_11 ;
V_243 . V_21 = V_241 . V_21 ;
V_243 . V_22 = V_241 . V_22 ;
V_243 . V_13 = V_175 -> args -> V_2 -> V_17 ;
F_7 ( V_175 -> args -> V_2 , V_242 , & V_243 ) ;
if ( F_103 ( V_237 -> V_30 , & V_241 ,
V_236 -> V_30 , & V_240 ) ) {
F_102 ( V_175 -> args ,
V_238 , & V_240 , 0 ,
V_242 , & V_243 , 0 ,
V_240 . V_15 ) ;
F_102 ( V_175 -> args ,
V_239 , & V_241 , 0 ,
V_242 , & V_243 , V_243 . V_15 ,
V_241 . V_15 ) ;
} else {
F_102 ( V_175 -> args ,
V_239 , & V_241 , 0 ,
V_242 , & V_243 , 0 ,
V_241 . V_15 ) ;
F_102 ( V_175 -> args ,
V_238 , & V_240 , 0 ,
V_242 , & V_243 , V_243 . V_15 ,
V_240 . V_15 ) ;
}
memcpy ( V_239 , V_242 , V_175 -> args -> V_2 -> V_17 ) ;
V_241 = V_243 ;
F_70 ( V_242 ) ;
}
F_7 ( V_175 -> args -> V_2 , V_239 , & V_241 ) ;
F_79 ( V_175 -> args -> V_106 , V_237 -> V_30 , 0 ,
V_175 -> args -> V_2 -> V_17 - 1 ) ;
V_141 = F_72 ( V_239 ) ;
V_237 -> V_138 = F_6 ( V_141 [ V_241 . V_15 - 1 ] . V_138 ) ;
}
int
F_68 (
struct V_29 * V_30 ,
struct V_149 * args )
{
struct V_5 * V_35 ;
struct V_3 V_40 ;
struct V_140 * V_141 ;
struct V_140 * V_155 ;
struct V_150 * V_142 ;
struct V_188 * V_189 ;
T_14 V_138 ;
int V_244 ;
int V_245 ;
F_117 ( args ) ;
V_35 = V_30 -> V_36 ;
F_5 ( args -> V_2 , & V_40 , V_35 ) ;
V_155 = F_72 ( V_35 ) ;
ASSERT ( V_40 . V_15 < args -> V_2 -> V_17 / 8 ) ;
V_138 = args -> V_138 ;
V_244 = V_245 = V_40 . V_15 / 2 ;
for ( V_141 = & V_155 [ V_244 ] ; V_245 > 4 ; V_141 = & V_155 [ V_244 ] ) {
V_245 /= 2 ;
if ( F_6 ( V_141 -> V_138 ) < V_138 )
V_244 += V_245 ;
else if ( F_6 ( V_141 -> V_138 ) > V_138 )
V_244 -= V_245 ;
else
break;
}
ASSERT ( V_244 >= 0 && ( ! V_40 . V_15 || V_244 < V_40 . V_15 ) ) ;
ASSERT ( V_245 <= 4 || F_6 ( V_141 -> V_138 ) == V_138 ) ;
while ( V_244 > 0 && F_6 ( V_141 -> V_138 ) >= V_138 ) {
V_141 -- ;
V_244 -- ;
}
while ( V_244 < V_40 . V_15 &&
F_6 ( V_141 -> V_138 ) < V_138 ) {
V_141 ++ ;
V_244 ++ ;
}
if ( V_244 == V_40 . V_15 || F_6 ( V_141 -> V_138 ) != V_138 ) {
args -> V_184 = V_244 ;
return - V_122 ;
}
for (; V_244 < V_40 . V_15 && ( F_6 ( V_141 -> V_138 ) == V_138 ) ;
V_141 ++ , V_244 ++ ) {
if ( ( args -> V_116 & V_145 ) !=
( V_141 -> V_116 & V_145 ) ) {
continue;
}
if ( V_141 -> V_116 & V_146 ) {
V_142 = F_73 ( V_35 , V_244 ) ;
if ( V_142 -> V_113 != args -> V_113 )
continue;
if ( memcmp ( args -> V_114 , V_142 -> V_115 ,
args -> V_113 ) != 0 )
continue;
if ( ! F_24 ( args -> V_116 , V_141 -> V_116 ) )
continue;
args -> V_184 = V_244 ;
return - V_125 ;
} else {
V_189 = F_97 ( V_35 , V_244 ) ;
if ( V_189 -> V_113 != args -> V_113 )
continue;
if ( memcmp ( args -> V_114 , V_189 -> V_114 ,
args -> V_113 ) != 0 )
continue;
if ( ! F_24 ( args -> V_116 , V_141 -> V_116 ) )
continue;
args -> V_184 = V_244 ;
args -> V_197 = F_6 ( V_189 -> V_117 ) ;
args -> V_195 = F_6 ( V_189 -> V_194 ) ;
args -> V_196 = F_98 (
args -> V_62 -> V_77 ,
args -> V_197 ) ;
return - V_125 ;
}
}
args -> V_184 = V_244 ;
return - V_122 ;
}
int
F_118 (
struct V_29 * V_30 ,
struct V_149 * args )
{
struct V_5 * V_35 ;
struct V_3 V_40 ;
struct V_140 * V_141 ;
struct V_150 * V_142 ;
struct V_188 * V_189 ;
int V_117 ;
V_35 = V_30 -> V_36 ;
F_5 ( args -> V_2 , & V_40 , V_35 ) ;
ASSERT ( V_40 . V_15 < args -> V_2 -> V_17 / 8 ) ;
ASSERT ( args -> V_184 < V_40 . V_15 ) ;
V_141 = & F_72 ( V_35 ) [ args -> V_184 ] ;
if ( V_141 -> V_116 & V_146 ) {
V_142 = F_73 ( V_35 , args -> V_184 ) ;
ASSERT ( V_142 -> V_113 == args -> V_113 ) ;
ASSERT ( memcmp ( args -> V_114 , V_142 -> V_115 , args -> V_113 ) == 0 ) ;
V_117 = F_3 ( V_142 -> V_117 ) ;
if ( args -> V_116 & V_126 ) {
args -> V_117 = V_117 ;
return 0 ;
}
if ( args -> V_117 < V_117 ) {
args -> V_117 = V_117 ;
return - V_127 ;
}
args -> V_117 = V_117 ;
memcpy ( args -> V_118 , & V_142 -> V_115 [ args -> V_113 ] , V_117 ) ;
} else {
V_189 = F_97 ( V_35 , args -> V_184 ) ;
ASSERT ( V_189 -> V_113 == args -> V_113 ) ;
ASSERT ( memcmp ( args -> V_114 , V_189 -> V_114 , args -> V_113 ) == 0 ) ;
args -> V_197 = F_6 ( V_189 -> V_117 ) ;
args -> V_195 = F_6 ( V_189 -> V_194 ) ;
args -> V_196 = F_98 ( args -> V_62 -> V_77 ,
args -> V_197 ) ;
if ( args -> V_116 & V_126 ) {
args -> V_117 = args -> V_197 ;
return 0 ;
}
if ( args -> V_117 < args -> V_197 ) {
args -> V_117 = args -> V_197 ;
return - V_127 ;
}
args -> V_117 = args -> V_197 ;
}
return 0 ;
}
STATIC void
F_102 (
struct V_149 * args ,
struct V_5 * V_246 ,
struct V_3 * V_247 ,
int V_248 ,
struct V_5 * V_249 ,
struct V_3 * V_250 ,
int V_251 ,
int V_15 )
{
struct V_140 * V_252 ;
struct V_140 * V_253 ;
int V_254 ;
int V_183 ;
int V_19 ;
if ( V_15 == 0 )
return;
ASSERT ( V_247 -> V_11 == V_20 ||
V_247 -> V_11 == V_12 ) ;
ASSERT ( V_247 -> V_11 == V_250 -> V_11 ) ;
ASSERT ( V_247 -> V_15 > 0 && V_247 -> V_15 < args -> V_2 -> V_17 / 8 ) ;
ASSERT ( V_247 -> V_13 >= ( V_247 -> V_15 * sizeof( * V_252 ) )
+ F_92 ( V_246 ) ) ;
ASSERT ( V_250 -> V_15 < args -> V_2 -> V_17 / 8 ) ;
ASSERT ( V_250 -> V_13 >= ( V_250 -> V_15 * sizeof( * V_253 ) )
+ F_92 ( V_249 ) ) ;
ASSERT ( V_248 < V_247 -> V_15 ) ;
ASSERT ( V_251 <= V_250 -> V_15 ) ;
ASSERT ( V_15 <= V_247 -> V_15 ) ;
if ( V_251 < V_250 -> V_15 ) {
V_183 = V_250 -> V_15 - V_251 ;
V_183 *= sizeof( V_185 ) ;
V_252 = & F_72 ( V_249 ) [ V_251 ] ;
V_253 = & F_72 ( V_249 ) [ V_251 + V_15 ] ;
memmove ( V_253 , V_252 , V_183 ) ;
}
V_252 = & F_72 ( V_246 ) [ V_248 ] ;
V_253 = & F_72 ( V_249 ) [ V_251 ] ;
V_254 = V_251 ;
for ( V_19 = 0 ; V_19 < V_15 ; V_252 ++ , V_253 ++ , V_254 ++ , V_19 ++ ) {
ASSERT ( F_3 ( V_252 -> V_153 ) >= V_247 -> V_13 ) ;
V_183 = F_100 ( V_246 , V_248 + V_19 ) ;
#ifdef F_119
if ( V_252 -> V_116 & V_145 ) {
memset ( F_99 ( V_246 , V_248 + V_19 ) , 0 , V_183 ) ;
V_247 -> V_16 -= V_183 ;
V_247 -> V_15 -= 1 ;
V_253 -- ;
V_254 -- ;
if ( ( V_248 + V_19 ) < V_73 )
V_255 ++ ;
} else {
#endif
V_250 -> V_13 -= V_183 ;
V_253 -> V_138 = V_252 -> V_138 ;
V_253 -> V_153 = F_2 ( V_250 -> V_13 ) ;
V_253 -> V_116 = V_252 -> V_116 ;
ASSERT ( F_3 ( V_253 -> V_153 ) + V_183
<= args -> V_2 -> V_17 ) ;
memmove ( F_99 ( V_249 , V_254 ) ,
F_99 ( V_246 , V_248 + V_19 ) , V_183 ) ;
ASSERT ( F_3 ( V_252 -> V_153 ) + V_183
<= args -> V_2 -> V_17 ) ;
memset ( F_99 ( V_246 , V_248 + V_19 ) , 0 , V_183 ) ;
V_247 -> V_16 -= V_183 ;
V_250 -> V_16 += V_183 ;
V_247 -> V_15 -= 1 ;
V_250 -> V_15 += 1 ;
V_183 = V_250 -> V_15 * sizeof( V_185 )
+ F_92 ( V_249 ) ;
ASSERT ( V_250 -> V_13 >= V_183 ) ;
#ifdef F_119
}
#endif
}
if ( V_248 == V_247 -> V_15 ) {
V_183 = V_15 * sizeof( V_185 ) ;
V_252 = & F_72 ( V_246 ) [ V_248 ] ;
ASSERT ( ( ( char * ) V_252 + V_183 ) <=
( ( char * ) V_246 + args -> V_2 -> V_17 ) ) ;
memset ( V_252 , 0 , V_183 ) ;
} else {
V_183 = ( V_247 -> V_15 - V_15 ) * sizeof( V_185 ) ;
V_252 = & F_72 ( V_246 ) [ V_248 + V_15 ] ;
V_253 = & F_72 ( V_246 ) [ V_248 ] ;
memmove ( V_253 , V_252 , V_183 ) ;
V_183 = V_15 * sizeof( V_185 ) ;
V_252 = & F_72 ( V_246 ) [ V_247 -> V_15 ] ;
ASSERT ( ( ( char * ) V_252 + V_183 ) <=
( ( char * ) V_246 + args -> V_2 -> V_17 ) ) ;
memset ( V_252 , 0 , V_183 ) ;
}
V_250 -> V_25 [ 0 ] . V_26 = F_92 ( V_249 ) ;
V_250 -> V_25 [ 0 ] . V_26 += V_250 -> V_15 * sizeof( V_185 ) ;
V_250 -> V_25 [ 0 ] . V_27 = V_250 -> V_13 - V_250 -> V_25 [ 0 ] . V_26 ;
V_250 -> V_25 [ 1 ] . V_26 = 0 ;
V_250 -> V_25 [ 2 ] . V_26 = 0 ;
V_250 -> V_25 [ 1 ] . V_27 = 0 ;
V_250 -> V_25 [ 2 ] . V_27 = 0 ;
V_247 -> V_23 = 1 ;
}
T_14
F_89 (
struct V_29 * V_30 ,
int * V_15 )
{
struct V_3 V_40 ;
struct V_140 * V_155 ;
struct V_31 * V_32 = V_30 -> V_33 -> V_34 ;
F_5 ( V_32 -> V_41 , & V_40 , V_30 -> V_36 ) ;
V_155 = F_72 ( V_30 -> V_36 ) ;
if ( V_15 )
* V_15 = V_40 . V_15 ;
if ( ! V_40 . V_15 )
return 0 ;
return F_6 ( V_155 [ V_40 . V_15 - 1 ] . V_138 ) ;
}
STATIC int
F_100 ( V_152 * V_35 , int V_184 )
{
struct V_140 * V_155 ;
T_12 * V_142 ;
T_15 * V_189 ;
int V_27 ;
V_155 = F_72 ( V_35 ) ;
if ( V_155 [ V_184 ] . V_116 & V_146 ) {
V_142 = F_73 ( V_35 , V_184 ) ;
V_27 = F_120 ( V_142 -> V_113 ,
F_3 ( V_142 -> V_117 ) ) ;
} else {
V_189 = F_97 ( V_35 , V_184 ) ;
V_27 = F_121 ( V_189 -> V_113 ) ;
}
return V_27 ;
}
int
F_91 (
struct V_149 * args ,
int * V_256 )
{
int V_27 ;
V_27 = F_120 ( args -> V_113 , args -> V_117 ) ;
if ( V_27 < F_122 ( args -> V_2 -> V_17 ) ) {
if ( V_256 )
* V_256 = 1 ;
return V_27 ;
}
if ( V_256 )
* V_256 = 0 ;
return F_121 ( args -> V_113 ) ;
}
int
F_123 (
struct V_149 * args )
{
struct V_5 * V_35 ;
struct V_140 * V_141 ;
struct V_188 * V_189 ;
struct V_29 * V_30 ;
int error ;
#ifdef F_48
struct V_3 V_40 ;
T_12 * V_142 ;
int V_113 ;
char * V_114 ;
#endif
F_124 ( args ) ;
error = F_21 ( args -> V_106 , args -> V_62 , args -> V_46 , - 1 , & V_30 ) ;
if ( error )
return error ;
V_35 = V_30 -> V_36 ;
V_141 = & F_72 ( V_35 ) [ args -> V_184 ] ;
ASSERT ( V_141 -> V_116 & V_145 ) ;
#ifdef F_48
F_5 ( args -> V_2 , & V_40 , V_35 ) ;
ASSERT ( args -> V_184 < V_40 . V_15 ) ;
ASSERT ( args -> V_184 >= 0 ) ;
if ( V_141 -> V_116 & V_146 ) {
V_142 = F_73 ( V_35 , args -> V_184 ) ;
V_113 = V_142 -> V_113 ;
V_114 = ( char * ) V_142 -> V_115 ;
} else {
V_189 = F_97 ( V_35 , args -> V_184 ) ;
V_113 = V_189 -> V_113 ;
V_114 = ( char * ) V_189 -> V_114 ;
}
ASSERT ( F_6 ( V_141 -> V_138 ) == args -> V_138 ) ;
ASSERT ( V_113 == args -> V_113 ) ;
ASSERT ( memcmp ( V_114 , args -> V_114 , V_113 ) == 0 ) ;
#endif
V_141 -> V_116 &= ~ V_145 ;
F_79 ( args -> V_106 , V_30 ,
F_95 ( V_35 , V_141 , sizeof( * V_141 ) ) ) ;
if ( args -> V_195 ) {
ASSERT ( ( V_141 -> V_116 & V_146 ) == 0 ) ;
V_189 = F_97 ( V_35 , args -> V_184 ) ;
V_189 -> V_194 = F_8 ( args -> V_195 ) ;
V_189 -> V_117 = F_8 ( args -> V_197 ) ;
F_79 ( args -> V_106 , V_30 ,
F_95 ( V_35 , V_189 , sizeof( * V_189 ) ) ) ;
}
return F_125 ( & args -> V_106 , args -> V_62 ) ;
}
int
F_126 (
struct V_149 * args )
{
struct V_5 * V_35 ;
struct V_140 * V_141 ;
struct V_188 * V_189 ;
struct V_29 * V_30 ;
int error ;
#ifdef F_48
struct V_3 V_40 ;
#endif
F_127 ( args ) ;
error = F_21 ( args -> V_106 , args -> V_62 , args -> V_46 , - 1 , & V_30 ) ;
if ( error )
return error ;
V_35 = V_30 -> V_36 ;
#ifdef F_48
F_5 ( args -> V_2 , & V_40 , V_35 ) ;
ASSERT ( args -> V_184 < V_40 . V_15 ) ;
ASSERT ( args -> V_184 >= 0 ) ;
#endif
V_141 = & F_72 ( V_35 ) [ args -> V_184 ] ;
ASSERT ( ( V_141 -> V_116 & V_145 ) == 0 ) ;
V_141 -> V_116 |= V_145 ;
F_79 ( args -> V_106 , V_30 ,
F_95 ( V_35 , V_141 , sizeof( * V_141 ) ) ) ;
if ( ( V_141 -> V_116 & V_146 ) == 0 ) {
V_189 = F_97 ( V_35 , args -> V_184 ) ;
V_189 -> V_194 = 0 ;
V_189 -> V_117 = 0 ;
F_79 ( args -> V_106 , V_30 ,
F_95 ( V_35 , V_189 , sizeof( * V_189 ) ) ) ;
}
return F_125 ( & args -> V_106 , args -> V_62 ) ;
}
int
F_128 (
struct V_149 * args )
{
struct V_5 * V_212 ;
struct V_5 * V_213 ;
struct V_140 * V_257 ;
struct V_140 * V_258 ;
struct V_188 * V_189 ;
struct V_29 * V_162 ;
struct V_29 * V_163 ;
int error ;
#ifdef F_48
struct V_3 V_208 ;
struct V_3 V_209 ;
T_12 * V_142 ;
int V_259 , V_260 ;
char * V_261 , * V_262 ;
#endif
F_129 ( args ) ;
error = F_21 ( args -> V_106 , args -> V_62 , args -> V_46 , - 1 , & V_162 ) ;
if ( error )
return error ;
if ( args -> V_192 != args -> V_46 ) {
error = F_21 ( args -> V_106 , args -> V_62 , args -> V_192 ,
- 1 , & V_163 ) ;
if ( error )
return error ;
} else {
V_163 = V_162 ;
}
V_212 = V_162 -> V_36 ;
V_257 = & F_72 ( V_212 ) [ args -> V_184 ] ;
V_213 = V_163 -> V_36 ;
V_258 = & F_72 ( V_213 ) [ args -> V_193 ] ;
#ifdef F_48
F_5 ( args -> V_2 , & V_208 , V_212 ) ;
ASSERT ( args -> V_184 < V_208 . V_15 ) ;
ASSERT ( args -> V_184 >= 0 ) ;
F_5 ( args -> V_2 , & V_209 , V_213 ) ;
ASSERT ( args -> V_193 < V_209 . V_15 ) ;
ASSERT ( args -> V_193 >= 0 ) ;
if ( V_257 -> V_116 & V_146 ) {
V_142 = F_73 ( V_212 , args -> V_184 ) ;
V_259 = V_142 -> V_113 ;
V_261 = ( char * ) V_142 -> V_115 ;
} else {
V_189 = F_97 ( V_212 , args -> V_184 ) ;
V_259 = V_189 -> V_113 ;
V_261 = ( char * ) V_189 -> V_114 ;
}
if ( V_258 -> V_116 & V_146 ) {
V_142 = F_73 ( V_213 , args -> V_193 ) ;
V_260 = V_142 -> V_113 ;
V_262 = ( char * ) V_142 -> V_115 ;
} else {
V_189 = F_97 ( V_213 , args -> V_193 ) ;
V_260 = V_189 -> V_113 ;
V_262 = ( char * ) V_189 -> V_114 ;
}
ASSERT ( F_6 ( V_257 -> V_138 ) == F_6 ( V_258 -> V_138 ) ) ;
ASSERT ( V_259 == V_260 ) ;
ASSERT ( memcmp ( V_261 , V_262 , V_259 ) == 0 ) ;
#endif
ASSERT ( V_257 -> V_116 & V_145 ) ;
ASSERT ( ( V_258 -> V_116 & V_145 ) == 0 ) ;
V_257 -> V_116 &= ~ V_145 ;
F_79 ( args -> V_106 , V_162 ,
F_95 ( V_212 , V_257 , sizeof( * V_257 ) ) ) ;
if ( args -> V_195 ) {
ASSERT ( ( V_257 -> V_116 & V_146 ) == 0 ) ;
V_189 = F_97 ( V_212 , args -> V_184 ) ;
V_189 -> V_194 = F_8 ( args -> V_195 ) ;
V_189 -> V_117 = F_8 ( args -> V_197 ) ;
F_79 ( args -> V_106 , V_162 ,
F_95 ( V_212 , V_189 , sizeof( * V_189 ) ) ) ;
}
V_258 -> V_116 |= V_145 ;
F_79 ( args -> V_106 , V_163 ,
F_95 ( V_213 , V_258 , sizeof( * V_258 ) ) ) ;
if ( ( V_258 -> V_116 & V_146 ) == 0 ) {
V_189 = F_97 ( V_213 , args -> V_193 ) ;
V_189 -> V_194 = 0 ;
V_189 -> V_117 = 0 ;
F_79 ( args -> V_106 , V_163 ,
F_95 ( V_213 , V_189 , sizeof( * V_189 ) ) ) ;
}
error = F_125 ( & args -> V_106 , args -> V_62 ) ;
return error ;
}
