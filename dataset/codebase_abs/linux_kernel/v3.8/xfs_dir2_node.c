static void
F_1 (
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 = 0 ;
V_10 = V_8 -> V_11 == F_2 ( V_12 ) ;
if ( ! V_10 ) {
F_3 ( L_1 ,
V_13 , V_4 , V_8 ) ;
F_4 ( V_2 , V_14 ) ;
}
}
static void
F_5 (
struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
static void
F_6 (
struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
static int
F_7 (
struct V_15 * V_16 ,
struct V_17 * V_18 ,
T_1 V_19 ,
T_2 V_20 ,
struct V_1 * * V_21 )
{
return F_8 ( V_16 , V_18 , V_19 , V_20 , V_21 ,
V_22 , & V_23 ) ;
}
int
F_9 (
struct V_15 * V_16 ,
struct V_17 * V_18 ,
T_1 V_19 ,
struct V_1 * * V_21 )
{
return F_7 ( V_16 , V_18 , V_19 , - 1 , V_21 ) ;
}
static int
F_10 (
struct V_15 * V_16 ,
struct V_17 * V_18 ,
T_1 V_19 ,
struct V_1 * * V_21 )
{
return F_7 ( V_16 , V_18 , V_19 , - 2 , V_21 ) ;
}
STATIC void
F_11 (
struct V_15 * V_16 ,
struct V_1 * V_2 ,
int V_24 ,
int V_25 )
{
T_3 * free ;
free = V_2 -> V_9 ;
ASSERT ( free -> V_8 . V_11 == F_2 ( V_12 ) ) ;
F_12 ( V_16 , V_2 ,
( V_26 ) ( ( char * ) & free -> V_27 [ V_24 ] - ( char * ) free ) ,
( V_26 ) ( ( char * ) & free -> V_27 [ V_25 ] - ( char * ) free +
sizeof( free -> V_27 [ 0 ] ) - 1 ) ) ;
}
static void
F_13 (
struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_3 * free ;
free = V_2 -> V_9 ;
ASSERT ( free -> V_8 . V_11 == F_2 ( V_12 ) ) ;
F_12 ( V_16 , V_2 , ( V_26 ) ( ( char * ) & free -> V_8 - ( char * ) free ) ,
( V_26 ) ( sizeof( V_28 ) - 1 ) ) ;
}
int
F_14 (
T_4 * args ,
struct V_1 * V_29 )
{
T_5 * V_18 ;
int error ;
struct V_1 * V_30 ;
T_6 V_31 ;
T_3 * free ;
T_7 * V_32 ;
int V_33 ;
T_8 * V_34 ;
T_9 * V_35 ;
T_10 * V_4 ;
int V_36 ;
T_11 V_37 ;
T_7 * V_38 ;
T_12 * V_16 ;
F_15 ( args ) ;
V_18 = args -> V_18 ;
V_4 = V_18 -> V_39 ;
V_16 = args -> V_40 ;
if ( ( error = F_16 ( args , V_41 , & V_31 ) ) ) {
return error ;
}
ASSERT ( V_31 == F_17 ( V_4 ) ) ;
error = F_18 ( V_16 , V_18 , F_19 ( V_4 , V_31 ) , - 1 , & V_30 ,
V_22 ) ;
if ( error )
return error ;
V_30 -> V_42 = & V_23 ;
free = V_30 -> V_9 ;
V_34 = V_29 -> V_9 ;
V_35 = F_20 ( V_4 , V_34 ) ;
free -> V_8 . V_11 = F_2 ( V_12 ) ;
free -> V_8 . V_43 = 0 ;
ASSERT ( F_21 ( V_35 -> V_44 ) <= ( V_26 ) V_18 -> V_45 . V_46 / V_4 -> V_47 ) ;
free -> V_8 . V_48 = V_35 -> V_44 ;
for ( V_33 = V_36 = 0 , V_32 = F_22 ( V_35 ) , V_38 = free -> V_27 ;
V_33 < F_21 ( V_35 -> V_44 ) ; V_33 ++ , V_32 ++ , V_38 ++ ) {
if ( ( V_37 = F_23 ( * V_32 ) ) != V_49 )
V_36 ++ ;
* V_38 = F_24 ( V_37 ) ;
}
free -> V_8 . V_50 = F_2 ( V_36 ) ;
V_29 -> V_42 = & V_51 ;
V_34 -> V_8 . V_52 . V_11 = F_24 ( V_53 ) ;
F_25 ( V_16 , V_29 ) ;
F_13 ( V_16 , V_30 ) ;
F_11 ( V_16 , V_30 , 0 , F_21 ( free -> V_8 . V_48 ) - 1 ) ;
F_26 ( V_18 , V_29 ) ;
return 0 ;
}
static int
F_27 (
struct V_1 * V_2 ,
T_4 * args ,
int V_54 )
{
int V_55 ;
T_5 * V_18 ;
int V_56 ;
T_8 * V_34 ;
T_13 * V_57 ;
int V_58 ;
int V_59 ;
int V_60 ;
T_10 * V_4 ;
T_12 * V_16 ;
F_28 ( args , V_54 ) ;
V_18 = args -> V_18 ;
V_4 = V_18 -> V_39 ;
V_16 = args -> V_40 ;
V_34 = V_2 -> V_9 ;
if ( V_54 < 0 )
return F_29 ( V_14 ) ;
if ( F_23 ( V_34 -> V_8 . V_61 ) == F_30 ( V_4 ) ) {
if ( ! V_34 -> V_8 . V_62 )
return F_29 ( V_63 ) ;
V_55 = F_23 ( V_34 -> V_8 . V_62 ) > 1 ;
} else
V_55 = 0 ;
ASSERT ( V_54 == 0 || F_21 ( V_34 -> V_64 [ V_54 - 1 ] . V_65 ) <= args -> V_65 ) ;
ASSERT ( V_54 == F_23 ( V_34 -> V_8 . V_61 ) ||
F_21 ( V_34 -> V_64 [ V_54 ] . V_65 ) >= args -> V_65 ) ;
if ( args -> V_66 & V_67 )
return 0 ;
if ( V_55 ) {
F_31 ( V_2 , & V_54 , & V_60 , & V_56 ,
& V_59 , & V_58 ) ;
}
else if ( V_34 -> V_8 . V_62 ) {
V_59 = F_23 ( V_34 -> V_8 . V_61 ) ;
V_58 = - 1 ;
}
V_57 = F_32 ( V_34 , V_54 , V_55 , V_60 ,
V_56 , & V_59 , & V_58 ) ;
V_57 -> V_65 = F_2 ( args -> V_65 ) ;
V_57 -> V_68 = F_2 ( F_33 ( V_4 ,
args -> V_69 , args -> V_54 ) ) ;
F_25 ( V_16 , V_2 ) ;
F_34 ( V_16 , V_2 , V_59 , V_58 ) ;
F_26 ( V_18 , V_2 ) ;
return 0 ;
}
void
F_26 (
struct V_17 * V_18 ,
struct V_1 * V_2 )
{
int V_33 ;
T_8 * V_34 ;
T_10 * V_4 ;
int V_62 ;
V_34 = V_2 -> V_9 ;
V_4 = V_18 -> V_39 ;
ASSERT ( V_34 -> V_8 . V_52 . V_11 == F_24 ( V_53 ) ) ;
ASSERT ( F_23 ( V_34 -> V_8 . V_61 ) <= F_30 ( V_4 ) ) ;
for ( V_33 = V_62 = 0 ; V_33 < F_23 ( V_34 -> V_8 . V_61 ) ; V_33 ++ ) {
if ( V_33 + 1 < F_23 ( V_34 -> V_8 . V_61 ) ) {
ASSERT ( F_21 ( V_34 -> V_64 [ V_33 ] . V_65 ) <=
F_21 ( V_34 -> V_64 [ V_33 + 1 ] . V_65 ) ) ;
}
if ( V_34 -> V_64 [ V_33 ] . V_68 == F_2 ( V_70 ) )
V_62 ++ ;
}
ASSERT ( F_23 ( V_34 -> V_8 . V_62 ) == V_62 ) ;
}
T_14
F_35 (
struct V_1 * V_2 ,
int * V_61 )
{
T_8 * V_34 ;
V_34 = V_2 -> V_9 ;
ASSERT ( V_34 -> V_8 . V_52 . V_11 == F_24 ( V_53 ) ) ;
if ( V_61 )
* V_61 = F_23 ( V_34 -> V_8 . V_61 ) ;
if ( ! V_34 -> V_8 . V_61 )
return 0 ;
return F_21 ( V_34 -> V_64 [ F_23 ( V_34 -> V_8 . V_61 ) - 1 ] . V_65 ) ;
}
STATIC int
F_36 (
struct V_1 * V_2 ,
T_4 * args ,
int * V_71 ,
T_15 * V_72 )
{
struct V_1 * V_73 = NULL ;
T_6 V_74 = - 1 ;
T_6 V_75 = - 1 ;
T_5 * V_18 ;
int error ;
int V_76 ;
T_3 * free = NULL ;
int V_54 ;
T_8 * V_34 ;
int V_77 ;
T_13 * V_57 ;
T_10 * V_4 ;
T_6 V_78 ;
T_6 V_79 ;
T_12 * V_16 ;
V_18 = args -> V_18 ;
V_16 = args -> V_40 ;
V_4 = V_18 -> V_39 ;
V_34 = V_2 -> V_9 ;
ASSERT ( V_34 -> V_8 . V_52 . V_11 == F_24 ( V_53 ) ) ;
#ifdef F_37
ASSERT ( F_23 ( V_34 -> V_8 . V_61 ) > 0 ) ;
#endif
F_26 ( V_18 , V_2 ) ;
V_54 = F_38 ( args , V_2 ) ;
if ( V_72 -> V_80 ) {
V_73 = V_72 -> V_81 . V_2 ;
V_75 = V_72 -> V_81 . V_69 ;
free = V_73 -> V_9 ;
ASSERT ( free -> V_8 . V_11 == F_2 ( V_12 ) ) ;
}
V_77 = F_39 ( args -> V_82 ) ;
for ( V_57 = & V_34 -> V_64 [ V_54 ] ; V_54 < F_23 ( V_34 -> V_8 . V_61 ) &&
F_21 ( V_57 -> V_65 ) == args -> V_65 ;
V_57 ++ , V_54 ++ ) {
if ( F_21 ( V_57 -> V_68 ) == V_70 )
continue;
V_78 = F_40 ( V_4 , F_21 ( V_57 -> V_68 ) ) ;
if ( V_78 != V_74 ) {
V_74 = V_78 ;
V_79 = F_41 ( V_4 , V_78 ) ;
if ( V_79 != V_75 ) {
if ( V_73 )
F_42 ( V_16 , V_73 ) ;
error = F_9 ( V_16 , V_18 ,
F_19 ( V_4 , V_79 ) ,
& V_73 ) ;
if ( error )
return error ;
free = V_73 -> V_9 ;
ASSERT ( F_21 ( free -> V_8 . V_11 ) ==
V_12 ) ;
ASSERT ( ( F_21 ( free -> V_8 . V_43 ) %
F_43 ( V_4 ) ) == 0 ) ;
ASSERT ( F_21 ( free -> V_8 . V_43 ) <= V_74 ) ;
ASSERT ( V_74 < F_21 ( free -> V_8 . V_43 ) +
F_21 ( free -> V_8 . V_48 ) ) ;
}
V_76 = F_44 ( V_4 , V_74 ) ;
if ( F_45 ( free -> V_27 [ V_76 ] ==
F_24 ( V_49 ) ) ) {
F_46 ( L_2 ,
V_13 , V_4 ) ;
if ( V_75 != V_79 )
F_42 ( V_16 , V_73 ) ;
return F_29 ( V_14 ) ;
}
V_75 = V_79 ;
if ( F_23 ( free -> V_27 [ V_76 ] ) >= V_77 )
goto V_83;
}
}
V_76 = - 1 ;
V_83:
ASSERT ( args -> V_66 & V_84 ) ;
if ( V_73 ) {
V_72 -> V_80 = 1 ;
V_72 -> V_81 . V_2 = V_73 ;
V_72 -> V_81 . V_54 = V_76 ;
V_72 -> V_81 . V_69 = V_75 ;
V_72 -> V_81 . V_11 = V_12 ;
} else {
V_72 -> V_80 = 0 ;
}
* V_71 = V_54 ;
return F_29 ( V_85 ) ;
}
STATIC int
F_47 (
struct V_1 * V_2 ,
T_4 * args ,
int * V_71 ,
T_15 * V_72 )
{
struct V_1 * V_73 = NULL ;
T_6 V_74 = - 1 ;
T_16 * V_86 ;
T_5 * V_18 ;
int error ;
int V_54 ;
T_8 * V_34 ;
T_13 * V_57 ;
T_10 * V_4 ;
T_6 V_78 ;
T_12 * V_16 ;
enum V_87 V_88 ;
V_18 = args -> V_18 ;
V_16 = args -> V_40 ;
V_4 = V_18 -> V_39 ;
V_34 = V_2 -> V_9 ;
ASSERT ( V_34 -> V_8 . V_52 . V_11 == F_24 ( V_53 ) ) ;
#ifdef F_37
ASSERT ( F_23 ( V_34 -> V_8 . V_61 ) > 0 ) ;
#endif
F_26 ( V_18 , V_2 ) ;
V_54 = F_38 ( args , V_2 ) ;
if ( V_72 -> V_80 ) {
V_73 = V_72 -> V_81 . V_2 ;
V_74 = V_72 -> V_81 . V_69 ;
}
for ( V_57 = & V_34 -> V_64 [ V_54 ] ; V_54 < F_23 ( V_34 -> V_8 . V_61 ) &&
F_21 ( V_57 -> V_65 ) == args -> V_65 ;
V_57 ++ , V_54 ++ ) {
if ( F_21 ( V_57 -> V_68 ) == V_70 )
continue;
V_78 = F_40 ( V_4 , F_21 ( V_57 -> V_68 ) ) ;
if ( V_78 != V_74 ) {
if ( V_73 && ( args -> V_89 == V_90 ||
V_74 != V_72 -> V_81 . V_69 ) )
F_42 ( V_16 , V_73 ) ;
if ( args -> V_89 != V_90 &&
V_78 == V_72 -> V_81 . V_69 ) {
ASSERT ( V_72 -> V_80 ) ;
V_73 = V_72 -> V_81 . V_2 ;
} else {
error = F_48 ( V_16 , V_18 ,
F_19 ( V_4 , V_78 ) ,
- 1 , & V_73 ) ;
if ( error )
return error ;
}
F_49 ( V_18 , V_73 ) ;
V_74 = V_78 ;
}
V_86 = ( T_16 * ) ( ( char * ) V_73 -> V_9 +
F_50 ( V_4 , F_21 ( V_57 -> V_68 ) ) ) ;
V_88 = V_4 -> V_91 -> V_92 ( args , V_86 -> V_93 , V_86 -> V_82 ) ;
if ( V_88 != V_90 && V_88 != args -> V_89 ) {
if ( args -> V_89 != V_90 &&
V_74 != V_72 -> V_81 . V_69 )
F_42 ( V_16 , V_72 -> V_81 . V_2 ) ;
args -> V_89 = V_88 ;
args -> V_94 = F_51 ( V_86 -> V_94 ) ;
* V_71 = V_54 ;
V_72 -> V_80 = 1 ;
V_72 -> V_81 . V_2 = V_73 ;
V_72 -> V_81 . V_69 = V_74 ;
V_72 -> V_81 . V_54 = ( int ) ( ( char * ) V_86 -
( char * ) V_73 -> V_9 ) ;
V_72 -> V_81 . V_11 = V_95 ;
V_73 -> V_42 = & V_96 ;
if ( V_88 == V_97 )
return F_29 ( V_98 ) ;
}
}
ASSERT ( V_54 == F_23 ( V_34 -> V_8 . V_61 ) ||
( args -> V_66 & V_84 ) ) ;
if ( V_73 ) {
if ( args -> V_89 == V_90 ) {
V_72 -> V_80 = 1 ;
V_72 -> V_81 . V_2 = V_73 ;
V_72 -> V_81 . V_54 = - 1 ;
V_72 -> V_81 . V_69 = V_74 ;
V_72 -> V_81 . V_11 = V_95 ;
V_73 -> V_42 = & V_96 ;
} else {
if ( V_72 -> V_81 . V_2 != V_73 )
F_42 ( V_16 , V_73 ) ;
}
} else {
V_72 -> V_80 = 0 ;
}
* V_71 = V_54 ;
return F_29 ( V_85 ) ;
}
int
F_52 (
struct V_1 * V_2 ,
T_4 * args ,
int * V_71 ,
T_15 * V_72 )
{
if ( args -> V_66 & V_99 )
return F_36 ( V_2 , args , V_71 ,
V_72 ) ;
return F_47 ( V_2 , args , V_71 , V_72 ) ;
}
static void
F_53 (
T_4 * args ,
struct V_1 * V_100 ,
int V_101 ,
struct V_1 * V_102 ,
int V_103 ,
int V_61 )
{
T_8 * V_104 ;
T_8 * V_105 ;
int V_62 ;
T_12 * V_16 ;
F_54 ( args , V_101 , V_103 , V_61 ) ;
if ( V_61 == 0 ) {
return;
}
V_16 = args -> V_40 ;
V_105 = V_100 -> V_9 ;
V_104 = V_102 -> V_9 ;
if ( V_103 < F_23 ( V_104 -> V_8 . V_61 ) ) {
memmove ( & V_104 -> V_64 [ V_103 + V_61 ] , & V_104 -> V_64 [ V_103 ] ,
( F_23 ( V_104 -> V_8 . V_61 ) - V_103 ) *
sizeof( T_13 ) ) ;
F_34 ( V_16 , V_102 , V_103 + V_61 ,
V_61 + F_23 ( V_104 -> V_8 . V_61 ) - 1 ) ;
}
if ( V_105 -> V_8 . V_62 ) {
int V_33 ;
for ( V_33 = V_101 , V_62 = 0 ; V_33 < V_101 + V_61 ; V_33 ++ ) {
if ( V_105 -> V_64 [ V_33 ] . V_68 ==
F_2 ( V_70 ) )
V_62 ++ ;
}
} else
V_62 = 0 ;
memcpy ( & V_104 -> V_64 [ V_103 ] , & V_105 -> V_64 [ V_101 ] ,
V_61 * sizeof( T_13 ) ) ;
F_34 ( V_16 , V_102 , V_103 , V_103 + V_61 - 1 ) ;
if ( V_101 + V_61 < F_23 ( V_105 -> V_8 . V_61 ) ) {
memmove ( & V_105 -> V_64 [ V_101 ] , & V_105 -> V_64 [ V_101 + V_61 ] ,
V_61 * sizeof( T_13 ) ) ;
F_34 ( V_16 , V_100 , V_101 , V_101 + V_61 - 1 ) ;
}
F_55 ( & V_105 -> V_8 . V_61 , - ( V_61 ) ) ;
F_55 ( & V_105 -> V_8 . V_62 , - ( V_62 ) ) ;
F_55 ( & V_104 -> V_8 . V_61 , V_61 ) ;
F_55 ( & V_104 -> V_8 . V_62 , V_62 ) ;
F_25 ( V_16 , V_100 ) ;
F_25 ( V_16 , V_102 ) ;
F_26 ( args -> V_18 , V_100 ) ;
F_26 ( args -> V_18 , V_102 ) ;
}
int
F_56 (
struct V_1 * V_106 ,
struct V_1 * V_107 )
{
T_8 * V_108 ;
T_8 * V_109 ;
V_108 = V_106 -> V_9 ;
V_109 = V_107 -> V_9 ;
ASSERT ( V_108 -> V_8 . V_52 . V_11 == F_24 ( V_53 ) ) ;
ASSERT ( V_109 -> V_8 . V_52 . V_11 == F_24 ( V_53 ) ) ;
if ( F_23 ( V_108 -> V_8 . V_61 ) > 0 &&
F_23 ( V_109 -> V_8 . V_61 ) > 0 &&
( F_21 ( V_109 -> V_64 [ 0 ] . V_65 ) < F_21 ( V_108 -> V_64 [ 0 ] . V_65 ) ||
F_21 ( V_109 -> V_64 [ F_23 ( V_109 -> V_8 . V_61 ) - 1 ] . V_65 ) <
F_21 ( V_108 -> V_64 [ F_23 ( V_108 -> V_8 . V_61 ) - 1 ] . V_65 ) ) )
return 1 ;
return 0 ;
}
static void
F_57 (
T_15 * V_72 ,
T_17 * V_110 ,
T_17 * V_111 )
{
T_4 * args ;
int V_61 ;
int V_112 ;
T_8 * V_108 ;
T_8 * V_109 ;
int V_113 ;
#ifdef F_58
int V_114 ;
#endif
int V_115 ;
int V_116 ;
args = V_72 -> args ;
if ( ( V_116 = F_56 ( V_110 -> V_2 , V_111 -> V_2 ) ) ) {
T_17 * V_117 ;
V_117 = V_110 ;
V_110 = V_111 ;
V_111 = V_117 ;
}
V_108 = V_110 -> V_2 -> V_9 ;
V_109 = V_111 -> V_2 -> V_9 ;
V_115 = F_23 ( V_108 -> V_8 . V_61 ) + F_23 ( V_109 -> V_8 . V_61 ) ;
#ifdef F_58
V_114 = F_23 ( V_108 -> V_8 . V_62 ) + F_23 ( V_109 -> V_8 . V_62 ) ;
#endif
V_113 = V_115 >> 1 ;
if ( V_115 & 1 ) {
T_14 V_118 ;
if ( V_113 >= F_23 ( V_108 -> V_8 . V_61 ) )
V_118 = F_21 ( V_109 -> V_64 [ V_113 - F_23 ( V_108 -> V_8 . V_61 ) ] . V_65 ) ;
else
V_118 = F_21 ( V_108 -> V_64 [ V_113 ] . V_65 ) ;
V_112 = args -> V_65 <= V_118 ;
}
else
V_112 = 1 ;
V_61 = F_23 ( V_108 -> V_8 . V_61 ) - V_113 + ( V_112 == 0 ) ;
if ( V_61 > 0 )
F_53 ( args , V_110 -> V_2 ,
F_23 ( V_108 -> V_8 . V_61 ) - V_61 , V_111 -> V_2 , 0 , V_61 ) ;
else if ( V_61 < 0 )
F_53 ( args , V_111 -> V_2 , 0 , V_110 -> V_2 ,
F_23 ( V_108 -> V_8 . V_61 ) , V_61 ) ;
ASSERT ( F_23 ( V_108 -> V_8 . V_61 ) + F_23 ( V_109 -> V_8 . V_61 ) == V_115 ) ;
ASSERT ( F_23 ( V_108 -> V_8 . V_62 ) + F_23 ( V_109 -> V_8 . V_62 ) == V_114 ) ;
if ( F_23 ( V_108 -> V_8 . V_61 ) < F_23 ( V_109 -> V_8 . V_61 ) )
V_72 -> V_119 = V_116 ;
else if ( F_23 ( V_108 -> V_8 . V_61 ) > F_23 ( V_109 -> V_8 . V_61 ) )
V_72 -> V_119 = ! V_116 ;
else
V_72 -> V_119 =
V_116 ^ ( V_110 -> V_54 <= F_23 ( V_108 -> V_8 . V_61 ) ) ;
if ( ! V_72 -> V_119 )
V_111 -> V_54 = V_110 -> V_54 - F_23 ( V_108 -> V_8 . V_61 ) ;
if( V_111 -> V_54 < 0 ) {
V_72 -> V_119 = 1 ;
V_111 -> V_54 = 0 ;
F_59 ( args -> V_18 -> V_39 ,
L_3 ,
V_120 , V_110 -> V_54 ) ;
}
}
static int
F_60 (
T_4 * args ,
struct V_121 * V_8 ,
struct V_122 * free ,
T_6 V_31 ,
int V_123 ,
struct V_1 * V_30 ,
int V_124 )
{
struct V_15 * V_16 = args -> V_40 ;
int V_125 = 0 ;
if ( ! V_8 ) {
F_61 ( & free -> V_8 . V_50 , - 1 ) ;
F_13 ( V_16 , V_30 ) ;
if ( V_123 == F_21 ( free -> V_8 . V_48 ) - 1 ) {
int V_33 ;
for ( V_33 = V_123 - 1 ; V_33 >= 0 ; V_33 -- ) {
if ( free -> V_27 [ V_33 ] != F_24 ( V_49 ) )
break;
}
free -> V_8 . V_48 = F_2 ( V_33 + 1 ) ;
V_125 = 0 ;
} else {
free -> V_27 [ V_123 ] = F_24 ( V_49 ) ;
V_125 = 1 ;
}
if ( ! free -> V_8 . V_50 ) {
int error ;
error = F_62 ( args , V_31 , V_30 ) ;
if ( error == 0 ) {
V_30 = NULL ;
V_125 = 0 ;
} else if ( error != V_63 || args -> V_126 != 0 )
return error ;
}
} else {
free -> V_27 [ V_123 ] = F_24 ( V_124 ) ;
V_125 = 1 ;
}
if ( V_125 )
F_11 ( V_16 , V_30 , V_123 , V_123 ) ;
return 0 ;
}
static int
F_63 (
T_4 * args ,
struct V_1 * V_2 ,
int V_54 ,
T_17 * V_127 ,
int * V_128 )
{
T_18 * V_8 ;
T_6 V_129 ;
struct V_1 * V_130 ;
T_16 * V_86 ;
T_5 * V_18 ;
T_8 * V_34 ;
T_13 * V_57 ;
int V_124 ;
int V_37 ;
T_10 * V_4 ;
int V_131 ;
int V_132 ;
T_12 * V_16 ;
F_64 ( args , V_54 ) ;
V_18 = args -> V_18 ;
V_16 = args -> V_40 ;
V_4 = V_18 -> V_39 ;
V_34 = V_2 -> V_9 ;
ASSERT ( V_34 -> V_8 . V_52 . V_11 == F_24 ( V_53 ) ) ;
V_57 = & V_34 -> V_64 [ V_54 ] ;
V_129 = F_40 ( V_4 , F_21 ( V_57 -> V_68 ) ) ;
ASSERT ( V_127 -> V_69 == V_129 ) ;
V_37 = F_50 ( V_4 , F_21 ( V_57 -> V_68 ) ) ;
ASSERT ( V_127 -> V_54 == V_37 ) ;
F_55 ( & V_34 -> V_8 . V_62 , 1 ) ;
F_25 ( V_16 , V_2 ) ;
V_57 -> V_68 = F_2 ( V_70 ) ;
F_34 ( V_16 , V_2 , V_54 , V_54 ) ;
V_130 = V_127 -> V_2 ;
V_8 = V_130 -> V_9 ;
V_86 = ( T_16 * ) ( ( char * ) V_8 + V_37 ) ;
V_124 = F_23 ( V_8 -> V_133 [ 0 ] . V_77 ) ;
V_131 = V_132 = 0 ;
F_65 ( V_16 , V_130 , V_37 ,
F_39 ( V_86 -> V_82 ) , & V_131 , & V_132 ) ;
if ( V_132 )
F_66 ( V_4 , V_8 , & V_131 ) ;
if ( V_131 )
F_67 ( V_16 , V_130 ) ;
F_49 ( V_18 , V_130 ) ;
if ( V_124 < F_23 ( V_8 -> V_133 [ 0 ] . V_77 ) ) {
int error ;
struct V_1 * V_30 ;
T_6 V_31 ;
int V_123 ;
T_3 * free ;
V_31 = F_41 ( V_4 , V_129 ) ;
error = F_9 ( V_16 , V_18 , F_19 ( V_4 , V_31 ) ,
& V_30 ) ;
if ( error )
return error ;
free = V_30 -> V_9 ;
ASSERT ( free -> V_8 . V_11 == F_2 ( V_12 ) ) ;
ASSERT ( F_21 ( free -> V_8 . V_43 ) ==
F_43 ( V_4 ) *
( V_31 - F_17 ( V_4 ) ) ) ;
V_123 = F_44 ( V_4 , V_129 ) ;
V_124 = F_23 ( V_8 -> V_133 [ 0 ] . V_77 ) ;
if ( V_124 == V_4 -> V_47 - ( V_26 ) sizeof( * V_8 ) ) {
error = F_62 ( args , V_129 , V_130 ) ;
if ( error == 0 ) {
V_127 -> V_2 = NULL ;
V_8 = NULL ;
}
else if ( ! ( error == V_63 && args -> V_126 == 0 ) )
return error ;
}
error = F_60 ( args , V_8 , free ,
V_31 , V_123 , V_30 , V_124 ) ;
if ( error )
return error ;
}
F_26 ( V_18 , V_2 ) ;
* V_128 =
( ( V_26 ) sizeof( V_34 -> V_8 ) +
( V_26 ) sizeof( V_34 -> V_64 [ 0 ] ) *
( F_23 ( V_34 -> V_8 . V_61 ) - F_23 ( V_34 -> V_8 . V_62 ) ) ) <
V_4 -> V_134 ;
return 0 ;
}
int
F_68 (
T_15 * V_72 ,
T_17 * V_135 ,
T_17 * V_136 )
{
T_4 * args ;
T_1 V_69 ;
int error ;
T_10 * V_4 ;
args = V_72 -> args ;
V_4 = args -> V_18 -> V_39 ;
ASSERT ( args != NULL ) ;
ASSERT ( V_135 -> V_11 == V_53 ) ;
error = F_69 ( args , & V_69 ) ;
if ( error ) {
return error ;
}
error = F_70 ( args , F_71 ( V_4 , V_69 ) ,
& V_136 -> V_2 , V_53 ) ;
if ( error ) {
return error ;
}
V_136 -> V_69 = V_69 ;
V_136 -> V_11 = V_53 ;
F_57 ( V_72 , V_135 , V_136 ) ;
error = F_72 ( V_72 , V_135 , V_136 ) ;
if ( error ) {
return error ;
}
if ( V_72 -> V_119 )
error = F_27 ( V_135 -> V_2 , args , V_135 -> V_54 ) ;
else
error = F_27 ( V_136 -> V_2 , args , V_136 -> V_54 ) ;
V_135 -> V_65 = F_35 ( V_135 -> V_2 , NULL ) ;
V_136 -> V_65 = F_35 ( V_136 -> V_2 , NULL ) ;
F_26 ( args -> V_18 , V_135 -> V_2 ) ;
F_26 ( args -> V_18 , V_136 -> V_2 ) ;
return error ;
}
int
F_73 (
T_15 * V_72 ,
int * V_137 )
{
T_17 * V_138 ;
T_1 V_69 ;
struct V_1 * V_2 ;
int V_139 ;
int V_61 ;
int error ;
int V_140 ;
int V_33 ;
T_19 * V_52 ;
T_8 * V_34 ;
int V_128 ;
V_138 = & V_72 -> V_141 . V_138 [ V_72 -> V_141 . V_142 - 1 ] ;
V_52 = V_138 -> V_2 -> V_9 ;
ASSERT ( V_52 -> V_11 == F_24 ( V_53 ) ) ;
V_34 = ( T_8 * ) V_52 ;
V_61 = F_23 ( V_34 -> V_8 . V_61 ) - F_23 ( V_34 -> V_8 . V_62 ) ;
V_139 = ( V_26 ) sizeof( V_34 -> V_8 ) + V_61 * ( V_26 ) sizeof( V_34 -> V_64 [ 0 ] ) ;
if ( V_139 > ( V_72 -> V_143 >> 1 ) ) {
* V_137 = 0 ;
return 0 ;
}
if ( V_61 == 0 ) {
V_140 = ( V_52 -> V_144 != 0 ) ;
memcpy ( & V_72 -> V_145 , & V_72 -> V_141 , sizeof( V_72 -> V_141 ) ) ;
error = F_74 ( V_72 , & V_72 -> V_145 , V_140 , 0 ,
& V_128 ) ;
if ( error )
return error ;
* V_137 = V_128 ? 2 : 0 ;
return 0 ;
}
V_140 = F_21 ( V_52 -> V_144 ) < F_21 ( V_52 -> V_146 ) ;
for ( V_33 = 0 , V_2 = NULL ; V_33 < 2 ; V_140 = ! V_140 , V_33 ++ ) {
V_69 = V_140 ? F_21 ( V_52 -> V_144 ) : F_21 ( V_52 -> V_146 ) ;
if ( V_69 == 0 )
continue;
error = F_75 ( V_72 -> args -> V_40 , V_72 -> args -> V_18 ,
V_69 , - 1 , & V_2 ) ;
if ( error )
return error ;
V_34 = ( T_8 * ) V_52 ;
V_61 = F_23 ( V_34 -> V_8 . V_61 ) - F_23 ( V_34 -> V_8 . V_62 ) ;
V_139 = V_72 -> V_143 - ( V_72 -> V_143 >> 2 ) ;
V_34 = V_2 -> V_9 ;
ASSERT ( V_34 -> V_8 . V_52 . V_11 == F_24 ( V_53 ) ) ;
V_61 += F_23 ( V_34 -> V_8 . V_61 ) - F_23 ( V_34 -> V_8 . V_62 ) ;
V_139 -= V_61 * ( V_26 ) sizeof( V_34 -> V_64 [ 0 ] ) ;
if ( V_139 >= 0 )
break;
F_42 ( V_72 -> args -> V_40 , V_2 ) ;
}
if ( V_33 >= 2 ) {
* V_137 = 0 ;
return 0 ;
}
memcpy ( & V_72 -> V_145 , & V_72 -> V_141 , sizeof( V_72 -> V_141 ) ) ;
if ( V_69 < V_138 -> V_69 )
error = F_74 ( V_72 , & V_72 -> V_145 , V_140 , 0 ,
& V_128 ) ;
else
error = F_74 ( V_72 , & V_72 -> V_141 , V_140 , 0 ,
& V_128 ) ;
if ( error ) {
return error ;
}
* V_137 = V_128 ? 0 : 1 ;
return 0 ;
}
void
F_76 (
T_15 * V_72 ,
T_17 * V_147 ,
T_17 * V_148 )
{
T_4 * args ;
T_8 * V_149 ;
T_8 * V_150 ;
args = V_72 -> args ;
ASSERT ( V_147 -> V_11 == V_53 ) ;
ASSERT ( V_148 -> V_11 == V_53 ) ;
V_149 = V_147 -> V_2 -> V_9 ;
V_150 = V_148 -> V_2 -> V_9 ;
ASSERT ( V_149 -> V_8 . V_52 . V_11 == F_24 ( V_53 ) ) ;
ASSERT ( V_150 -> V_8 . V_52 . V_11 == F_24 ( V_53 ) ) ;
if ( V_149 -> V_8 . V_62 )
F_77 ( args , V_147 -> V_2 ) ;
if ( V_150 -> V_8 . V_62 )
F_77 ( args , V_148 -> V_2 ) ;
V_147 -> V_65 = F_21 ( V_149 -> V_64 [ F_23 ( V_149 -> V_8 . V_61 ) - 1 ] . V_65 ) ;
if ( F_56 ( V_148 -> V_2 , V_147 -> V_2 ) )
F_53 ( args , V_147 -> V_2 , 0 , V_148 -> V_2 , 0 ,
F_23 ( V_149 -> V_8 . V_61 ) ) ;
else
F_53 ( args , V_147 -> V_2 , 0 , V_148 -> V_2 ,
F_23 ( V_150 -> V_8 . V_61 ) , F_23 ( V_149 -> V_8 . V_61 ) ) ;
V_148 -> V_65 = F_21 ( V_150 -> V_64 [ F_23 ( V_150 -> V_8 . V_61 ) - 1 ] . V_65 ) ;
F_26 ( args -> V_18 , V_148 -> V_2 ) ;
}
int
F_78 (
T_4 * args )
{
T_17 * V_138 ;
int error ;
int V_128 ;
T_15 * V_72 ;
F_79 ( args ) ;
V_72 = F_80 () ;
V_72 -> args = args ;
V_72 -> V_4 = args -> V_18 -> V_39 ;
V_72 -> V_143 = V_72 -> V_4 -> V_47 ;
V_72 -> V_151 = V_72 -> V_4 -> V_152 ;
error = F_81 ( V_72 , & V_128 ) ;
if ( error )
V_128 = error ;
if ( V_128 != V_85 ) {
goto V_153;
}
V_128 = F_82 ( args ,
V_72 -> V_80 ? & V_72 -> V_81 : NULL ) ;
if ( V_128 ) {
goto V_153;
}
V_138 = & V_72 -> V_141 . V_138 [ V_72 -> V_141 . V_142 - 1 ] ;
ASSERT ( V_138 -> V_11 == V_53 ) ;
V_128 = F_27 ( V_138 -> V_2 , args , V_138 -> V_54 ) ;
if ( V_128 == 0 ) {
if ( ! ( args -> V_66 & V_67 ) )
F_83 ( V_72 , & V_72 -> V_141 ) ;
} else {
if ( args -> V_126 == 0 ) {
ASSERT ( V_128 == V_63 ) ;
goto V_153;
}
V_128 = F_84 ( V_72 ) ;
}
V_153:
F_85 ( V_72 ) ;
return V_128 ;
}
static int
F_82 (
T_4 * args ,
T_17 * V_154 )
{
T_18 * V_8 ;
T_6 V_155 ;
struct V_1 * V_130 ;
T_16 * V_86 ;
T_5 * V_18 ;
T_20 * V_156 ;
int error ;
T_6 V_19 ;
struct V_1 * V_30 ;
int V_123 ;
T_3 * free = NULL ;
T_6 V_157 ;
T_6 V_158 = 0 ;
int V_77 ;
int V_125 ;
T_10 * V_4 ;
int V_131 ;
int V_132 ;
T_7 * V_159 ;
T_12 * V_16 ;
V_18 = args -> V_18 ;
V_4 = V_18 -> V_39 ;
V_16 = args -> V_40 ;
V_77 = F_39 ( args -> V_82 ) ;
if ( V_154 ) {
V_30 = V_154 -> V_2 ;
V_157 = V_154 -> V_69 ;
free = V_30 -> V_9 ;
ASSERT ( free -> V_8 . V_11 == F_2 ( V_12 ) ) ;
V_123 = V_154 -> V_54 ;
if ( V_123 >= 0 ) {
ASSERT ( V_123 < F_21 ( free -> V_8 . V_48 ) ) ;
ASSERT ( F_23 ( free -> V_27 [ V_123 ] ) != V_49 ) ;
ASSERT ( F_23 ( free -> V_27 [ V_123 ] ) >= V_77 ) ;
V_155 = F_21 ( free -> V_8 . V_43 ) + V_123 ;
}
else {
V_155 = - 1 ;
V_123 = 0 ;
}
}
else {
V_157 = V_155 = - 1 ;
V_30 = NULL ;
V_123 = 0 ;
}
if ( V_155 == - 1 ) {
T_21 V_160 ;
if ( ( error = F_86 ( V_16 , V_18 , & V_160 , V_22 ) ) )
return error ;
V_158 = F_71 ( V_4 , ( T_1 ) V_160 ) ;
V_19 = V_157 ;
}
while ( V_155 == - 1 ) {
if ( V_30 == NULL ) {
if ( ++ V_19 == 0 )
V_19 = F_17 ( V_4 ) ;
if ( V_19 == V_157 )
V_19 ++ ;
if ( V_19 >= V_158 )
break;
error = F_10 ( V_16 , V_18 ,
F_19 ( V_4 , V_19 ) ,
& V_30 ) ;
if ( error )
return error ;
if ( ! V_30 )
continue;
free = V_30 -> V_9 ;
ASSERT ( free -> V_8 . V_11 == F_2 ( V_12 ) ) ;
V_123 = 0 ;
}
if ( F_23 ( free -> V_27 [ V_123 ] ) != V_49 &&
F_23 ( free -> V_27 [ V_123 ] ) >= V_77 )
V_155 = F_21 ( free -> V_8 . V_43 ) + V_123 ;
else {
if ( ++ V_123 == F_21 ( free -> V_8 . V_48 ) ) {
F_42 ( V_16 , V_30 ) ;
V_30 = NULL ;
if ( V_154 && V_154 -> V_2 )
V_154 -> V_2 = NULL ;
}
}
}
if ( F_45 ( V_155 == - 1 ) ) {
if ( ( args -> V_66 & V_67 ) || args -> V_126 == 0 )
return F_29 ( V_63 ) ;
if ( F_45 ( ( error = F_16 ( args ,
V_161 ,
& V_155 ) ) ||
( error = F_87 ( args , V_155 , & V_130 ) ) ) )
return error ;
if ( V_30 )
F_42 ( V_16 , V_30 ) ;
if ( V_154 && V_154 -> V_2 )
V_154 -> V_2 = NULL ;
V_19 = F_41 ( V_4 , V_155 ) ;
error = F_10 ( V_16 , V_18 ,
F_19 ( V_4 , V_19 ) ,
& V_30 ) ;
if ( error )
return error ;
if( V_30 == NULL ) {
if ( ( error = F_16 ( args , V_41 ,
& V_19 ) ) ) {
return error ;
}
if ( F_45 ( F_41 ( V_4 , V_155 ) != V_19 ) ) {
F_59 ( V_4 ,
L_4
L_5 ,
V_120 , ( unsigned long long ) V_18 -> V_162 ,
( long long ) F_41 ( V_4 , V_155 ) ,
( long long ) V_155 , ( long long ) V_19 ,
( unsigned long long ) V_157 , V_158 ) ;
if ( V_154 ) {
F_59 ( V_4 ,
L_6 ,
V_154 ,
( unsigned long long ) V_154 -> V_69 ,
V_154 -> V_54 ,
V_154 -> V_11 ) ;
} else {
F_59 ( V_4 , L_7 ) ;
}
F_46 ( L_8 ,
V_13 , V_4 ) ;
return F_29 ( V_14 ) ;
}
error = F_18 ( V_16 , V_18 ,
F_19 ( V_4 , V_19 ) ,
- 1 , & V_30 , V_22 ) ;
if ( error )
return error ;
V_30 -> V_42 = & V_23 ;
free = V_30 -> V_9 ;
free -> V_8 . V_11 = F_2 ( V_12 ) ;
free -> V_8 . V_43 = F_2 (
( V_19 - F_17 ( V_4 ) ) *
F_43 ( V_4 ) ) ;
free -> V_8 . V_48 = 0 ;
free -> V_8 . V_50 = 0 ;
} else {
free = V_30 -> V_9 ;
ASSERT ( free -> V_8 . V_11 == F_2 ( V_12 ) ) ;
}
V_123 = F_44 ( V_4 , V_155 ) ;
if ( V_123 >= F_21 ( free -> V_8 . V_48 ) ) {
ASSERT ( V_123 < F_43 ( V_4 ) ) ;
free -> V_8 . V_48 = F_2 ( V_123 + 1 ) ;
free -> V_27 [ V_123 ] = F_24 ( V_49 ) ;
}
if ( free -> V_27 [ V_123 ] == F_24 ( V_49 ) ) {
F_61 ( & free -> V_8 . V_50 , 1 ) ;
F_13 ( V_16 , V_30 ) ;
}
V_8 = V_130 -> V_9 ;
free -> V_27 [ V_123 ] = V_8 -> V_133 [ 0 ] . V_77 ;
V_125 = 1 ;
}
else {
if ( args -> V_66 & V_67 )
return 0 ;
error = F_48 ( V_16 , V_18 , F_19 ( V_4 , V_155 ) ,
- 1 , & V_130 ) ;
if ( error )
return error ;
V_8 = V_130 -> V_9 ;
V_125 = 0 ;
}
ASSERT ( F_23 ( V_8 -> V_133 [ 0 ] . V_77 ) >= V_77 ) ;
V_156 = ( T_20 * )
( ( char * ) V_8 + F_23 ( V_8 -> V_133 [ 0 ] . V_163 ) ) ;
V_132 = V_131 = 0 ;
F_88 ( V_16 , V_130 , V_156 ,
( V_164 ) ( ( char * ) V_156 - ( char * ) V_8 ) , V_77 ,
& V_131 , & V_132 ) ;
V_86 = ( T_16 * ) V_156 ;
V_86 -> V_94 = F_89 ( args -> V_94 ) ;
V_86 -> V_82 = args -> V_82 ;
memcpy ( V_86 -> V_93 , args -> V_93 , V_86 -> V_82 ) ;
V_159 = F_90 ( V_86 ) ;
* V_159 = F_24 ( ( char * ) V_86 - ( char * ) V_8 ) ;
F_91 ( V_16 , V_130 , V_86 ) ;
if ( V_132 )
F_66 ( V_4 , V_8 , & V_131 ) ;
if ( V_131 )
F_67 ( V_16 , V_130 ) ;
if ( F_23 ( free -> V_27 [ V_123 ] ) != F_23 ( V_8 -> V_133 [ 0 ] . V_77 ) ) {
free -> V_27 [ V_123 ] = V_8 -> V_133 [ 0 ] . V_77 ;
V_125 = 1 ;
}
if ( V_125 )
F_11 ( V_16 , V_30 , V_123 , V_123 ) ;
args -> V_69 = ( T_1 ) V_155 ;
args -> V_54 = F_23 ( * V_159 ) ;
return 0 ;
}
int
F_92 (
T_4 * args )
{
int error ;
int V_33 ;
int V_128 ;
T_15 * V_72 ;
F_93 ( args ) ;
V_72 = F_80 () ;
V_72 -> args = args ;
V_72 -> V_4 = args -> V_18 -> V_39 ;
V_72 -> V_143 = V_72 -> V_4 -> V_47 ;
V_72 -> V_151 = V_72 -> V_4 -> V_152 ;
error = F_81 ( V_72 , & V_128 ) ;
if ( error )
V_128 = error ;
else if ( V_128 == V_85 && args -> V_89 == V_165 ) {
T_16 * V_86 ;
V_86 = ( T_16 * )
( ( char * ) V_72 -> V_81 . V_2 -> V_9 +
V_72 -> V_81 . V_54 ) ;
V_128 = F_94 ( args , V_86 -> V_93 , V_86 -> V_82 ) ;
}
for ( V_33 = 0 ; V_33 < V_72 -> V_141 . V_142 ; V_33 ++ ) {
F_42 ( args -> V_40 , V_72 -> V_141 . V_138 [ V_33 ] . V_2 ) ;
V_72 -> V_141 . V_138 [ V_33 ] . V_2 = NULL ;
}
if ( V_72 -> V_80 && V_72 -> V_81 . V_2 ) {
F_42 ( args -> V_40 , V_72 -> V_81 . V_2 ) ;
V_72 -> V_81 . V_2 = NULL ;
}
F_85 ( V_72 ) ;
return V_128 ;
}
int
F_95 (
T_4 * args )
{
T_17 * V_138 ;
int error ;
int V_128 ;
T_15 * V_72 ;
F_96 ( args ) ;
V_72 = F_80 () ;
V_72 -> args = args ;
V_72 -> V_4 = args -> V_18 -> V_39 ;
V_72 -> V_143 = V_72 -> V_4 -> V_47 ;
V_72 -> V_151 = V_72 -> V_4 -> V_152 ;
error = F_81 ( V_72 , & V_128 ) ;
if ( error )
V_128 = error ;
if ( V_128 != V_98 ) {
F_85 ( V_72 ) ;
return V_128 ;
}
V_138 = & V_72 -> V_141 . V_138 [ V_72 -> V_141 . V_142 - 1 ] ;
ASSERT ( V_138 -> V_11 == V_53 ) ;
ASSERT ( V_72 -> V_80 ) ;
error = F_63 ( args , V_138 -> V_2 , V_138 -> V_54 ,
& V_72 -> V_81 , & V_128 ) ;
if ( error )
return error ;
F_83 ( V_72 , & V_72 -> V_141 ) ;
if ( V_128 && V_72 -> V_141 . V_142 > 1 )
error = F_97 ( V_72 ) ;
if ( ! error )
error = F_98 ( V_72 ) ;
F_85 ( V_72 ) ;
return error ;
}
int
F_99 (
T_4 * args )
{
T_17 * V_138 ;
T_18 * V_8 ;
T_16 * V_86 ;
int error ;
int V_33 ;
T_22 V_166 ;
T_8 * V_34 ;
T_13 * V_57 ;
int V_128 ;
T_15 * V_72 ;
F_100 ( args ) ;
V_72 = F_80 () ;
V_72 -> args = args ;
V_72 -> V_4 = args -> V_18 -> V_39 ;
V_72 -> V_143 = V_72 -> V_4 -> V_47 ;
V_72 -> V_151 = V_72 -> V_4 -> V_152 ;
V_166 = args -> V_94 ;
error = F_81 ( V_72 , & V_128 ) ;
if ( error ) {
V_128 = error ;
}
if ( V_128 == V_98 ) {
V_138 = & V_72 -> V_141 . V_138 [ V_72 -> V_141 . V_142 - 1 ] ;
ASSERT ( V_138 -> V_11 == V_53 ) ;
V_34 = V_138 -> V_2 -> V_9 ;
V_57 = & V_34 -> V_64 [ V_138 -> V_54 ] ;
ASSERT ( V_72 -> V_80 ) ;
V_8 = V_72 -> V_81 . V_2 -> V_9 ;
ASSERT ( V_8 -> V_11 == F_2 ( V_95 ) ) ;
V_86 = ( T_16 * )
( ( char * ) V_8 +
F_50 ( V_72 -> V_4 , F_21 ( V_57 -> V_68 ) ) ) ;
ASSERT ( V_166 != F_51 ( V_86 -> V_94 ) ) ;
V_86 -> V_94 = F_89 ( V_166 ) ;
F_91 ( args -> V_40 , V_72 -> V_81 . V_2 , V_86 ) ;
V_128 = 0 ;
}
else if ( V_72 -> V_80 ) {
F_42 ( args -> V_40 , V_72 -> V_81 . V_2 ) ;
V_72 -> V_81 . V_2 = NULL ;
}
for ( V_33 = 0 ; V_33 < V_72 -> V_141 . V_142 ; V_33 ++ ) {
F_42 ( args -> V_40 , V_72 -> V_141 . V_138 [ V_33 ] . V_2 ) ;
V_72 -> V_141 . V_138 [ V_33 ] . V_2 = NULL ;
}
F_85 ( V_72 ) ;
return V_128 ;
}
int
F_101 (
T_4 * args ,
T_21 V_160 ,
int * V_167 )
{
struct V_1 * V_2 ;
T_5 * V_18 ;
int error ;
T_3 * free ;
T_10 * V_4 ;
T_12 * V_16 ;
V_18 = args -> V_18 ;
V_4 = V_18 -> V_39 ;
V_16 = args -> V_40 ;
error = F_10 ( V_16 , V_18 , V_160 , & V_2 ) ;
if ( error )
return error ;
if ( ! V_2 )
return 0 ;
free = V_2 -> V_9 ;
ASSERT ( free -> V_8 . V_11 == F_2 ( V_12 ) ) ;
if ( F_21 ( free -> V_8 . V_50 ) > 0 ) {
F_42 ( V_16 , V_2 ) ;
* V_167 = 0 ;
return 0 ;
}
if ( ( error =
F_62 ( args , F_71 ( V_4 , ( T_1 ) V_160 ) ,
V_2 ) ) ) {
ASSERT ( error != V_63 ) ;
F_42 ( V_16 , V_2 ) ;
return error ;
}
* V_167 = 1 ;
return 0 ;
}
