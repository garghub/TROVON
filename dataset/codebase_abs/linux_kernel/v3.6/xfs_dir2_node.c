STATIC void
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
int V_6 )
{
T_1 * free ;
free = V_4 -> V_7 ;
ASSERT ( free -> V_8 . V_9 == F_2 ( V_10 ) ) ;
F_3 ( V_2 , V_4 ,
( V_11 ) ( ( char * ) & free -> V_12 [ V_5 ] - ( char * ) free ) ,
( V_11 ) ( ( char * ) & free -> V_12 [ V_6 ] - ( char * ) free +
sizeof( free -> V_12 [ 0 ] ) - 1 ) ) ;
}
static void
F_4 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * free ;
free = V_4 -> V_7 ;
ASSERT ( free -> V_8 . V_9 == F_2 ( V_10 ) ) ;
F_3 ( V_2 , V_4 , ( V_11 ) ( ( char * ) & free -> V_8 - ( char * ) free ) ,
( V_11 ) ( sizeof( V_13 ) - 1 ) ) ;
}
int
F_5 (
T_2 * args ,
struct V_3 * V_14 )
{
T_3 * V_15 ;
int error ;
struct V_3 * V_16 ;
T_4 V_17 ;
T_1 * free ;
T_5 * V_18 ;
int V_19 ;
T_6 * V_20 ;
T_7 * V_21 ;
T_8 * V_22 ;
int V_23 ;
T_9 V_24 ;
T_5 * V_25 ;
T_10 * V_2 ;
F_6 ( args ) ;
V_15 = args -> V_15 ;
V_22 = V_15 -> V_26 ;
V_2 = args -> V_27 ;
if ( ( error = F_7 ( args , V_28 , & V_17 ) ) ) {
return error ;
}
ASSERT ( V_17 == F_8 ( V_22 ) ) ;
if ( ( error = F_9 ( V_2 , V_15 , F_10 ( V_22 , V_17 ) , - 1 , & V_16 ,
V_29 ) ) ) {
return error ;
}
ASSERT ( V_16 != NULL ) ;
free = V_16 -> V_7 ;
V_20 = V_14 -> V_7 ;
V_21 = F_11 ( V_22 , V_20 ) ;
free -> V_8 . V_9 = F_2 ( V_10 ) ;
free -> V_8 . V_30 = 0 ;
ASSERT ( F_12 ( V_21 -> V_31 ) <= ( V_11 ) V_15 -> V_32 . V_33 / V_22 -> V_34 ) ;
free -> V_8 . V_35 = V_21 -> V_31 ;
for ( V_19 = V_23 = 0 , V_18 = F_13 ( V_21 ) , V_25 = free -> V_12 ;
V_19 < F_12 ( V_21 -> V_31 ) ; V_19 ++ , V_18 ++ , V_25 ++ ) {
if ( ( V_24 = F_14 ( * V_18 ) ) != V_36 )
V_23 ++ ;
* V_25 = F_15 ( V_24 ) ;
}
free -> V_8 . V_37 = F_2 ( V_23 ) ;
V_20 -> V_8 . V_38 . V_9 = F_15 ( V_39 ) ;
F_16 ( V_2 , V_14 ) ;
F_4 ( V_2 , V_16 ) ;
F_1 ( V_2 , V_16 , 0 , F_12 ( free -> V_8 . V_35 ) - 1 ) ;
F_17 ( V_15 , V_14 ) ;
return 0 ;
}
static int
F_18 (
struct V_3 * V_4 ,
T_2 * args ,
int V_40 )
{
int V_41 ;
T_3 * V_15 ;
int V_42 ;
T_6 * V_20 ;
T_11 * V_43 ;
int V_44 ;
int V_45 ;
int V_46 ;
T_8 * V_22 ;
T_10 * V_2 ;
F_19 ( args , V_40 ) ;
V_15 = args -> V_15 ;
V_22 = V_15 -> V_26 ;
V_2 = args -> V_27 ;
V_20 = V_4 -> V_7 ;
if ( V_40 < 0 )
return F_20 ( V_47 ) ;
if ( F_14 ( V_20 -> V_8 . V_48 ) == F_21 ( V_22 ) ) {
if ( ! V_20 -> V_8 . V_49 )
return F_20 ( V_50 ) ;
V_41 = F_14 ( V_20 -> V_8 . V_49 ) > 1 ;
} else
V_41 = 0 ;
ASSERT ( V_40 == 0 || F_12 ( V_20 -> V_51 [ V_40 - 1 ] . V_52 ) <= args -> V_52 ) ;
ASSERT ( V_40 == F_14 ( V_20 -> V_8 . V_48 ) ||
F_12 ( V_20 -> V_51 [ V_40 ] . V_52 ) >= args -> V_52 ) ;
if ( args -> V_53 & V_54 )
return 0 ;
if ( V_41 ) {
F_22 ( V_4 , & V_40 , & V_46 , & V_42 ,
& V_45 , & V_44 ) ;
}
else if ( V_20 -> V_8 . V_49 ) {
V_45 = F_14 ( V_20 -> V_8 . V_48 ) ;
V_44 = - 1 ;
}
V_43 = F_23 ( V_20 , V_40 , V_41 , V_46 ,
V_42 , & V_45 , & V_44 ) ;
V_43 -> V_52 = F_2 ( args -> V_52 ) ;
V_43 -> V_55 = F_2 ( F_24 ( V_22 ,
args -> V_56 , args -> V_40 ) ) ;
F_16 ( V_2 , V_4 ) ;
F_25 ( V_2 , V_4 , V_45 , V_44 ) ;
F_17 ( V_15 , V_4 ) ;
return 0 ;
}
void
F_17 (
struct V_57 * V_15 ,
struct V_3 * V_4 )
{
int V_19 ;
T_6 * V_20 ;
T_8 * V_22 ;
int V_49 ;
V_20 = V_4 -> V_7 ;
V_22 = V_15 -> V_26 ;
ASSERT ( V_20 -> V_8 . V_38 . V_9 == F_15 ( V_39 ) ) ;
ASSERT ( F_14 ( V_20 -> V_8 . V_48 ) <= F_21 ( V_22 ) ) ;
for ( V_19 = V_49 = 0 ; V_19 < F_14 ( V_20 -> V_8 . V_48 ) ; V_19 ++ ) {
if ( V_19 + 1 < F_14 ( V_20 -> V_8 . V_48 ) ) {
ASSERT ( F_12 ( V_20 -> V_51 [ V_19 ] . V_52 ) <=
F_12 ( V_20 -> V_51 [ V_19 + 1 ] . V_52 ) ) ;
}
if ( V_20 -> V_51 [ V_19 ] . V_55 == F_2 ( V_58 ) )
V_49 ++ ;
}
ASSERT ( F_14 ( V_20 -> V_8 . V_49 ) == V_49 ) ;
}
T_12
F_26 (
struct V_3 * V_4 ,
int * V_48 )
{
T_6 * V_20 ;
V_20 = V_4 -> V_7 ;
ASSERT ( V_20 -> V_8 . V_38 . V_9 == F_15 ( V_39 ) ) ;
if ( V_48 )
* V_48 = F_14 ( V_20 -> V_8 . V_48 ) ;
if ( ! V_20 -> V_8 . V_48 )
return 0 ;
return F_12 ( V_20 -> V_51 [ F_14 ( V_20 -> V_8 . V_48 ) - 1 ] . V_52 ) ;
}
STATIC int
F_27 (
struct V_3 * V_4 ,
T_2 * args ,
int * V_59 ,
T_13 * V_60 )
{
struct V_3 * V_61 = NULL ;
T_4 V_62 = - 1 ;
T_4 V_63 = - 1 ;
T_3 * V_15 ;
int error ;
int V_64 ;
T_1 * free = NULL ;
int V_40 ;
T_6 * V_20 ;
int V_65 ;
T_11 * V_43 ;
T_8 * V_22 ;
T_4 V_66 ;
T_4 V_67 ;
T_10 * V_2 ;
V_15 = args -> V_15 ;
V_2 = args -> V_27 ;
V_22 = V_15 -> V_26 ;
V_20 = V_4 -> V_7 ;
ASSERT ( V_20 -> V_8 . V_38 . V_9 == F_15 ( V_39 ) ) ;
#ifdef F_28
ASSERT ( F_14 ( V_20 -> V_8 . V_48 ) > 0 ) ;
#endif
F_17 ( V_15 , V_4 ) ;
V_40 = F_29 ( args , V_4 ) ;
if ( V_60 -> V_68 ) {
V_61 = V_60 -> V_69 . V_4 ;
V_63 = V_60 -> V_69 . V_56 ;
free = V_61 -> V_7 ;
ASSERT ( free -> V_8 . V_9 == F_2 ( V_10 ) ) ;
}
V_65 = F_30 ( args -> V_70 ) ;
for ( V_43 = & V_20 -> V_51 [ V_40 ] ; V_40 < F_14 ( V_20 -> V_8 . V_48 ) &&
F_12 ( V_43 -> V_52 ) == args -> V_52 ;
V_43 ++ , V_40 ++ ) {
if ( F_12 ( V_43 -> V_55 ) == V_58 )
continue;
V_66 = F_31 ( V_22 , F_12 ( V_43 -> V_55 ) ) ;
if ( V_66 != V_62 ) {
V_62 = V_66 ;
V_67 = F_32 ( V_22 , V_66 ) ;
if ( V_67 != V_63 ) {
if ( V_61 )
F_33 ( V_2 , V_61 ) ;
error = F_34 ( V_2 , V_15 ,
F_10 ( V_22 , V_67 ) ,
- 1 , & V_61 , V_29 ) ;
if ( error )
return error ;
free = V_61 -> V_7 ;
ASSERT ( F_12 ( free -> V_8 . V_9 ) ==
V_10 ) ;
ASSERT ( ( F_12 ( free -> V_8 . V_30 ) %
F_35 ( V_22 ) ) == 0 ) ;
ASSERT ( F_12 ( free -> V_8 . V_30 ) <= V_62 ) ;
ASSERT ( V_62 < F_12 ( free -> V_8 . V_30 ) +
F_12 ( free -> V_8 . V_35 ) ) ;
}
V_64 = F_36 ( V_22 , V_62 ) ;
if ( F_37 ( free -> V_12 [ V_64 ] ==
F_15 ( V_36 ) ) ) {
F_38 ( L_1 ,
V_71 , V_22 ) ;
if ( V_63 != V_67 )
F_33 ( V_2 , V_61 ) ;
return F_20 ( V_47 ) ;
}
V_63 = V_67 ;
if ( F_14 ( free -> V_12 [ V_64 ] ) >= V_65 )
goto V_72;
}
}
V_64 = - 1 ;
V_72:
ASSERT ( args -> V_53 & V_73 ) ;
if ( V_61 ) {
V_60 -> V_68 = 1 ;
V_60 -> V_69 . V_4 = V_61 ;
V_60 -> V_69 . V_40 = V_64 ;
V_60 -> V_69 . V_56 = V_63 ;
V_60 -> V_69 . V_9 = V_10 ;
} else {
V_60 -> V_68 = 0 ;
}
* V_59 = V_40 ;
return F_20 ( V_74 ) ;
}
STATIC int
F_39 (
struct V_3 * V_4 ,
T_2 * args ,
int * V_59 ,
T_13 * V_60 )
{
struct V_3 * V_61 = NULL ;
T_4 V_62 = - 1 ;
T_14 * V_75 ;
T_3 * V_15 ;
int error ;
int V_40 ;
T_6 * V_20 ;
T_11 * V_43 ;
T_8 * V_22 ;
T_4 V_66 ;
T_10 * V_2 ;
enum V_76 V_77 ;
V_15 = args -> V_15 ;
V_2 = args -> V_27 ;
V_22 = V_15 -> V_26 ;
V_20 = V_4 -> V_7 ;
ASSERT ( V_20 -> V_8 . V_38 . V_9 == F_15 ( V_39 ) ) ;
#ifdef F_28
ASSERT ( F_14 ( V_20 -> V_8 . V_48 ) > 0 ) ;
#endif
F_17 ( V_15 , V_4 ) ;
V_40 = F_29 ( args , V_4 ) ;
if ( V_60 -> V_68 ) {
V_61 = V_60 -> V_69 . V_4 ;
V_62 = V_60 -> V_69 . V_56 ;
}
for ( V_43 = & V_20 -> V_51 [ V_40 ] ; V_40 < F_14 ( V_20 -> V_8 . V_48 ) &&
F_12 ( V_43 -> V_52 ) == args -> V_52 ;
V_43 ++ , V_40 ++ ) {
if ( F_12 ( V_43 -> V_55 ) == V_58 )
continue;
V_66 = F_31 ( V_22 , F_12 ( V_43 -> V_55 ) ) ;
if ( V_66 != V_62 ) {
if ( V_61 && ( args -> V_78 == V_79 ||
V_62 != V_60 -> V_69 . V_56 ) )
F_33 ( V_2 , V_61 ) ;
if ( args -> V_78 != V_79 &&
V_66 == V_60 -> V_69 . V_56 ) {
ASSERT ( V_60 -> V_68 ) ;
V_61 = V_60 -> V_69 . V_4 ;
} else {
error = F_34 ( V_2 , V_15 ,
F_10 ( V_22 , V_66 ) ,
- 1 , & V_61 , V_29 ) ;
if ( error )
return error ;
}
F_40 ( V_15 , V_61 ) ;
V_62 = V_66 ;
}
V_75 = ( T_14 * ) ( ( char * ) V_61 -> V_7 +
F_41 ( V_22 , F_12 ( V_43 -> V_55 ) ) ) ;
V_77 = V_22 -> V_80 -> V_81 ( args , V_75 -> V_82 , V_75 -> V_70 ) ;
if ( V_77 != V_79 && V_77 != args -> V_78 ) {
if ( args -> V_78 != V_79 &&
V_62 != V_60 -> V_69 . V_56 )
F_33 ( V_2 , V_60 -> V_69 . V_4 ) ;
args -> V_78 = V_77 ;
args -> V_83 = F_42 ( V_75 -> V_83 ) ;
* V_59 = V_40 ;
V_60 -> V_68 = 1 ;
V_60 -> V_69 . V_4 = V_61 ;
V_60 -> V_69 . V_56 = V_62 ;
V_60 -> V_69 . V_40 = ( int ) ( ( char * ) V_75 -
( char * ) V_61 -> V_7 ) ;
V_60 -> V_69 . V_9 = V_84 ;
if ( V_77 == V_85 )
return F_20 ( V_86 ) ;
}
}
ASSERT ( V_40 == F_14 ( V_20 -> V_8 . V_48 ) ||
( args -> V_53 & V_73 ) ) ;
if ( V_61 ) {
if ( args -> V_78 == V_79 ) {
V_60 -> V_68 = 1 ;
V_60 -> V_69 . V_4 = V_61 ;
V_60 -> V_69 . V_40 = - 1 ;
V_60 -> V_69 . V_56 = V_62 ;
V_60 -> V_69 . V_9 = V_84 ;
} else {
if ( V_60 -> V_69 . V_4 != V_61 )
F_33 ( V_2 , V_61 ) ;
}
} else {
V_60 -> V_68 = 0 ;
}
* V_59 = V_40 ;
return F_20 ( V_74 ) ;
}
int
F_43 (
struct V_3 * V_4 ,
T_2 * args ,
int * V_59 ,
T_13 * V_60 )
{
if ( args -> V_53 & V_87 )
return F_27 ( V_4 , args , V_59 ,
V_60 ) ;
return F_39 ( V_4 , args , V_59 , V_60 ) ;
}
static void
F_44 (
T_2 * args ,
struct V_3 * V_88 ,
int V_89 ,
struct V_3 * V_90 ,
int V_91 ,
int V_48 )
{
T_6 * V_92 ;
T_6 * V_93 ;
int V_49 ;
T_10 * V_2 ;
F_45 ( args , V_89 , V_91 , V_48 ) ;
if ( V_48 == 0 ) {
return;
}
V_2 = args -> V_27 ;
V_93 = V_88 -> V_7 ;
V_92 = V_90 -> V_7 ;
if ( V_91 < F_14 ( V_92 -> V_8 . V_48 ) ) {
memmove ( & V_92 -> V_51 [ V_91 + V_48 ] , & V_92 -> V_51 [ V_91 ] ,
( F_14 ( V_92 -> V_8 . V_48 ) - V_91 ) *
sizeof( T_11 ) ) ;
F_25 ( V_2 , V_90 , V_91 + V_48 ,
V_48 + F_14 ( V_92 -> V_8 . V_48 ) - 1 ) ;
}
if ( V_93 -> V_8 . V_49 ) {
int V_19 ;
for ( V_19 = V_89 , V_49 = 0 ; V_19 < V_89 + V_48 ; V_19 ++ ) {
if ( V_93 -> V_51 [ V_19 ] . V_55 ==
F_2 ( V_58 ) )
V_49 ++ ;
}
} else
V_49 = 0 ;
memcpy ( & V_92 -> V_51 [ V_91 ] , & V_93 -> V_51 [ V_89 ] ,
V_48 * sizeof( T_11 ) ) ;
F_25 ( V_2 , V_90 , V_91 , V_91 + V_48 - 1 ) ;
if ( V_89 + V_48 < F_14 ( V_93 -> V_8 . V_48 ) ) {
memmove ( & V_93 -> V_51 [ V_89 ] , & V_93 -> V_51 [ V_89 + V_48 ] ,
V_48 * sizeof( T_11 ) ) ;
F_25 ( V_2 , V_88 , V_89 , V_89 + V_48 - 1 ) ;
}
F_46 ( & V_93 -> V_8 . V_48 , - ( V_48 ) ) ;
F_46 ( & V_93 -> V_8 . V_49 , - ( V_49 ) ) ;
F_46 ( & V_92 -> V_8 . V_48 , V_48 ) ;
F_46 ( & V_92 -> V_8 . V_49 , V_49 ) ;
F_16 ( V_2 , V_88 ) ;
F_16 ( V_2 , V_90 ) ;
F_17 ( args -> V_15 , V_88 ) ;
F_17 ( args -> V_15 , V_90 ) ;
}
int
F_47 (
struct V_3 * V_94 ,
struct V_3 * V_95 )
{
T_6 * V_96 ;
T_6 * V_97 ;
V_96 = V_94 -> V_7 ;
V_97 = V_95 -> V_7 ;
ASSERT ( V_96 -> V_8 . V_38 . V_9 == F_15 ( V_39 ) ) ;
ASSERT ( V_97 -> V_8 . V_38 . V_9 == F_15 ( V_39 ) ) ;
if ( F_14 ( V_96 -> V_8 . V_48 ) > 0 &&
F_14 ( V_97 -> V_8 . V_48 ) > 0 &&
( F_12 ( V_97 -> V_51 [ 0 ] . V_52 ) < F_12 ( V_96 -> V_51 [ 0 ] . V_52 ) ||
F_12 ( V_97 -> V_51 [ F_14 ( V_97 -> V_8 . V_48 ) - 1 ] . V_52 ) <
F_12 ( V_96 -> V_51 [ F_14 ( V_96 -> V_8 . V_48 ) - 1 ] . V_52 ) ) )
return 1 ;
return 0 ;
}
static void
F_48 (
T_13 * V_60 ,
T_15 * V_98 ,
T_15 * V_99 )
{
T_2 * args ;
int V_48 ;
int V_100 ;
T_6 * V_96 ;
T_6 * V_97 ;
int V_101 ;
#ifdef F_49
int V_102 ;
#endif
int V_103 ;
int V_104 ;
args = V_60 -> args ;
if ( ( V_104 = F_47 ( V_98 -> V_4 , V_99 -> V_4 ) ) ) {
T_15 * V_105 ;
V_105 = V_98 ;
V_98 = V_99 ;
V_99 = V_105 ;
}
V_96 = V_98 -> V_4 -> V_7 ;
V_97 = V_99 -> V_4 -> V_7 ;
V_103 = F_14 ( V_96 -> V_8 . V_48 ) + F_14 ( V_97 -> V_8 . V_48 ) ;
#ifdef F_49
V_102 = F_14 ( V_96 -> V_8 . V_49 ) + F_14 ( V_97 -> V_8 . V_49 ) ;
#endif
V_101 = V_103 >> 1 ;
if ( V_103 & 1 ) {
T_12 V_106 ;
if ( V_101 >= F_14 ( V_96 -> V_8 . V_48 ) )
V_106 = F_12 ( V_97 -> V_51 [ V_101 - F_14 ( V_96 -> V_8 . V_48 ) ] . V_52 ) ;
else
V_106 = F_12 ( V_96 -> V_51 [ V_101 ] . V_52 ) ;
V_100 = args -> V_52 <= V_106 ;
}
else
V_100 = 1 ;
V_48 = F_14 ( V_96 -> V_8 . V_48 ) - V_101 + ( V_100 == 0 ) ;
if ( V_48 > 0 )
F_44 ( args , V_98 -> V_4 ,
F_14 ( V_96 -> V_8 . V_48 ) - V_48 , V_99 -> V_4 , 0 , V_48 ) ;
else if ( V_48 < 0 )
F_44 ( args , V_99 -> V_4 , 0 , V_98 -> V_4 ,
F_14 ( V_96 -> V_8 . V_48 ) , V_48 ) ;
ASSERT ( F_14 ( V_96 -> V_8 . V_48 ) + F_14 ( V_97 -> V_8 . V_48 ) == V_103 ) ;
ASSERT ( F_14 ( V_96 -> V_8 . V_49 ) + F_14 ( V_97 -> V_8 . V_49 ) == V_102 ) ;
if ( F_14 ( V_96 -> V_8 . V_48 ) < F_14 ( V_97 -> V_8 . V_48 ) )
V_60 -> V_107 = V_104 ;
else if ( F_14 ( V_96 -> V_8 . V_48 ) > F_14 ( V_97 -> V_8 . V_48 ) )
V_60 -> V_107 = ! V_104 ;
else
V_60 -> V_107 =
V_104 ^ ( V_98 -> V_40 <= F_14 ( V_96 -> V_8 . V_48 ) ) ;
if ( ! V_60 -> V_107 )
V_99 -> V_40 = V_98 -> V_40 - F_14 ( V_96 -> V_8 . V_48 ) ;
if( V_99 -> V_40 < 0 ) {
V_60 -> V_107 = 1 ;
V_99 -> V_40 = 0 ;
F_50 ( args -> V_15 -> V_26 ,
L_2 ,
V_108 , V_98 -> V_40 ) ;
}
}
static int
F_51 (
T_2 * args ,
struct V_3 * V_4 ,
int V_40 ,
T_15 * V_109 ,
int * V_110 )
{
T_16 * V_8 ;
T_4 V_111 ;
struct V_3 * V_112 ;
T_14 * V_75 ;
T_3 * V_15 ;
T_6 * V_20 ;
T_11 * V_43 ;
int V_113 ;
int V_24 ;
T_8 * V_22 ;
int V_114 ;
int V_115 ;
T_10 * V_2 ;
F_52 ( args , V_40 ) ;
V_15 = args -> V_15 ;
V_2 = args -> V_27 ;
V_22 = V_15 -> V_26 ;
V_20 = V_4 -> V_7 ;
ASSERT ( V_20 -> V_8 . V_38 . V_9 == F_15 ( V_39 ) ) ;
V_43 = & V_20 -> V_51 [ V_40 ] ;
V_111 = F_31 ( V_22 , F_12 ( V_43 -> V_55 ) ) ;
ASSERT ( V_109 -> V_56 == V_111 ) ;
V_24 = F_41 ( V_22 , F_12 ( V_43 -> V_55 ) ) ;
ASSERT ( V_109 -> V_40 == V_24 ) ;
F_46 ( & V_20 -> V_8 . V_49 , 1 ) ;
F_16 ( V_2 , V_4 ) ;
V_43 -> V_55 = F_2 ( V_58 ) ;
F_25 ( V_2 , V_4 , V_40 , V_40 ) ;
V_112 = V_109 -> V_4 ;
V_8 = V_112 -> V_7 ;
V_75 = ( T_14 * ) ( ( char * ) V_8 + V_24 ) ;
V_113 = F_14 ( V_8 -> V_116 [ 0 ] . V_65 ) ;
V_114 = V_115 = 0 ;
F_53 ( V_2 , V_112 , V_24 ,
F_30 ( V_75 -> V_70 ) , & V_114 , & V_115 ) ;
if ( V_115 )
F_54 ( V_22 , V_8 , & V_114 ) ;
if ( V_114 )
F_55 ( V_2 , V_112 ) ;
F_40 ( V_15 , V_112 ) ;
if ( V_113 < F_14 ( V_8 -> V_116 [ 0 ] . V_65 ) ) {
int error ;
struct V_3 * V_16 ;
T_4 V_17 ;
int V_117 ;
T_1 * free ;
int V_118 ;
V_17 = F_32 ( V_22 , V_111 ) ;
if ( ( error = F_34 ( V_2 , V_15 , F_10 ( V_22 , V_17 ) ,
- 1 , & V_16 , V_29 ) ) ) {
return error ;
}
free = V_16 -> V_7 ;
ASSERT ( free -> V_8 . V_9 == F_2 ( V_10 ) ) ;
ASSERT ( F_12 ( free -> V_8 . V_30 ) ==
F_35 ( V_22 ) *
( V_17 - F_8 ( V_22 ) ) ) ;
V_117 = F_36 ( V_22 , V_111 ) ;
V_113 = F_14 ( V_8 -> V_116 [ 0 ] . V_65 ) ;
if ( V_113 == V_22 -> V_34 - ( V_11 ) sizeof( * V_8 ) ) {
error = F_56 ( args , V_111 , V_112 ) ;
if ( error == 0 ) {
V_109 -> V_4 = NULL ;
V_8 = NULL ;
}
else if ( ! ( error == V_50 && args -> V_119 == 0 ) )
return error ;
}
if ( V_8 == NULL ) {
F_57 ( & free -> V_8 . V_37 , - 1 ) ;
F_4 ( V_2 , V_16 ) ;
if ( V_117 == F_12 ( free -> V_8 . V_35 ) - 1 ) {
int V_19 ;
for ( V_19 = V_117 - 1 ;
V_19 >= 0 &&
free -> V_12 [ V_19 ] == F_15 ( V_36 ) ;
V_19 -- )
continue;
free -> V_8 . V_35 = F_2 ( V_19 + 1 ) ;
V_118 = 0 ;
}
else {
free -> V_12 [ V_117 ] = F_15 ( V_36 ) ;
V_118 = 1 ;
}
if ( ! free -> V_8 . V_37 ) {
error = F_56 ( args , V_17 , V_16 ) ;
if ( error == 0 ) {
V_16 = NULL ;
V_118 = 0 ;
} else if ( error != V_50 || args -> V_119 != 0 )
return error ;
}
}
else {
free -> V_12 [ V_117 ] = F_15 ( V_113 ) ;
V_118 = 1 ;
}
if ( V_118 )
F_1 ( V_2 , V_16 , V_117 , V_117 ) ;
}
F_17 ( V_15 , V_4 ) ;
* V_110 =
( ( V_11 ) sizeof( V_20 -> V_8 ) +
( V_11 ) sizeof( V_20 -> V_51 [ 0 ] ) *
( F_14 ( V_20 -> V_8 . V_48 ) - F_14 ( V_20 -> V_8 . V_49 ) ) ) <
V_22 -> V_120 ;
return 0 ;
}
int
F_58 (
T_13 * V_60 ,
T_15 * V_121 ,
T_15 * V_122 )
{
T_2 * args ;
T_17 V_56 ;
int error ;
T_8 * V_22 ;
args = V_60 -> args ;
V_22 = args -> V_15 -> V_26 ;
ASSERT ( args != NULL ) ;
ASSERT ( V_121 -> V_9 == V_39 ) ;
error = F_59 ( args , & V_56 ) ;
if ( error ) {
return error ;
}
error = F_60 ( args , F_61 ( V_22 , V_56 ) ,
& V_122 -> V_4 , V_39 ) ;
if ( error ) {
return error ;
}
V_122 -> V_56 = V_56 ;
V_122 -> V_9 = V_39 ;
F_48 ( V_60 , V_121 , V_122 ) ;
error = F_62 ( V_60 , V_121 , V_122 ) ;
if ( error ) {
return error ;
}
if ( V_60 -> V_107 )
error = F_18 ( V_121 -> V_4 , args , V_121 -> V_40 ) ;
else
error = F_18 ( V_122 -> V_4 , args , V_122 -> V_40 ) ;
V_121 -> V_52 = F_26 ( V_121 -> V_4 , NULL ) ;
V_122 -> V_52 = F_26 ( V_122 -> V_4 , NULL ) ;
F_17 ( args -> V_15 , V_121 -> V_4 ) ;
F_17 ( args -> V_15 , V_122 -> V_4 ) ;
return error ;
}
int
F_63 (
T_13 * V_60 ,
int * V_123 )
{
T_15 * V_124 ;
T_17 V_56 ;
struct V_3 * V_4 ;
int V_125 ;
int V_48 ;
int error ;
int V_126 ;
int V_19 ;
T_18 * V_38 ;
T_6 * V_20 ;
int V_110 ;
V_124 = & V_60 -> V_127 . V_124 [ V_60 -> V_127 . V_128 - 1 ] ;
V_38 = V_124 -> V_4 -> V_7 ;
ASSERT ( V_38 -> V_9 == F_15 ( V_39 ) ) ;
V_20 = ( T_6 * ) V_38 ;
V_48 = F_14 ( V_20 -> V_8 . V_48 ) - F_14 ( V_20 -> V_8 . V_49 ) ;
V_125 = ( V_11 ) sizeof( V_20 -> V_8 ) + V_48 * ( V_11 ) sizeof( V_20 -> V_51 [ 0 ] ) ;
if ( V_125 > ( V_60 -> V_129 >> 1 ) ) {
* V_123 = 0 ;
return 0 ;
}
if ( V_48 == 0 ) {
V_126 = ( V_38 -> V_130 != 0 ) ;
memcpy ( & V_60 -> V_131 , & V_60 -> V_127 , sizeof( V_60 -> V_127 ) ) ;
error = F_64 ( V_60 , & V_60 -> V_131 , V_126 , 0 ,
& V_110 ) ;
if ( error )
return error ;
* V_123 = V_110 ? 2 : 0 ;
return 0 ;
}
V_126 = F_12 ( V_38 -> V_130 ) < F_12 ( V_38 -> V_132 ) ;
for ( V_19 = 0 , V_4 = NULL ; V_19 < 2 ; V_126 = ! V_126 , V_19 ++ ) {
V_56 = V_126 ? F_12 ( V_38 -> V_130 ) : F_12 ( V_38 -> V_132 ) ;
if ( V_56 == 0 )
continue;
if ( ( error =
F_34 ( V_60 -> args -> V_27 , V_60 -> args -> V_15 , V_56 ,
- 1 , & V_4 , V_29 ) ) ) {
return error ;
}
ASSERT ( V_4 != NULL ) ;
V_20 = ( T_6 * ) V_38 ;
V_48 = F_14 ( V_20 -> V_8 . V_48 ) - F_14 ( V_20 -> V_8 . V_49 ) ;
V_125 = V_60 -> V_129 - ( V_60 -> V_129 >> 2 ) ;
V_20 = V_4 -> V_7 ;
ASSERT ( V_20 -> V_8 . V_38 . V_9 == F_15 ( V_39 ) ) ;
V_48 += F_14 ( V_20 -> V_8 . V_48 ) - F_14 ( V_20 -> V_8 . V_49 ) ;
V_125 -= V_48 * ( V_11 ) sizeof( V_20 -> V_51 [ 0 ] ) ;
if ( V_125 >= 0 )
break;
F_33 ( V_60 -> args -> V_27 , V_4 ) ;
}
if ( V_19 >= 2 ) {
* V_123 = 0 ;
return 0 ;
}
memcpy ( & V_60 -> V_131 , & V_60 -> V_127 , sizeof( V_60 -> V_127 ) ) ;
if ( V_56 < V_124 -> V_56 )
error = F_64 ( V_60 , & V_60 -> V_131 , V_126 , 0 ,
& V_110 ) ;
else
error = F_64 ( V_60 , & V_60 -> V_127 , V_126 , 0 ,
& V_110 ) ;
if ( error ) {
return error ;
}
* V_123 = V_110 ? 0 : 1 ;
return 0 ;
}
void
F_65 (
T_13 * V_60 ,
T_15 * V_133 ,
T_15 * V_134 )
{
T_2 * args ;
T_6 * V_135 ;
T_6 * V_136 ;
args = V_60 -> args ;
ASSERT ( V_133 -> V_9 == V_39 ) ;
ASSERT ( V_134 -> V_9 == V_39 ) ;
V_135 = V_133 -> V_4 -> V_7 ;
V_136 = V_134 -> V_4 -> V_7 ;
ASSERT ( V_135 -> V_8 . V_38 . V_9 == F_15 ( V_39 ) ) ;
ASSERT ( V_136 -> V_8 . V_38 . V_9 == F_15 ( V_39 ) ) ;
if ( V_135 -> V_8 . V_49 )
F_66 ( args , V_133 -> V_4 ) ;
if ( V_136 -> V_8 . V_49 )
F_66 ( args , V_134 -> V_4 ) ;
V_133 -> V_52 = F_12 ( V_135 -> V_51 [ F_14 ( V_135 -> V_8 . V_48 ) - 1 ] . V_52 ) ;
if ( F_47 ( V_134 -> V_4 , V_133 -> V_4 ) )
F_44 ( args , V_133 -> V_4 , 0 , V_134 -> V_4 , 0 ,
F_14 ( V_135 -> V_8 . V_48 ) ) ;
else
F_44 ( args , V_133 -> V_4 , 0 , V_134 -> V_4 ,
F_14 ( V_136 -> V_8 . V_48 ) , F_14 ( V_135 -> V_8 . V_48 ) ) ;
V_134 -> V_52 = F_12 ( V_136 -> V_51 [ F_14 ( V_136 -> V_8 . V_48 ) - 1 ] . V_52 ) ;
F_17 ( args -> V_15 , V_134 -> V_4 ) ;
}
int
F_67 (
T_2 * args )
{
T_15 * V_124 ;
int error ;
int V_110 ;
T_13 * V_60 ;
F_68 ( args ) ;
V_60 = F_69 () ;
V_60 -> args = args ;
V_60 -> V_22 = args -> V_15 -> V_26 ;
V_60 -> V_129 = V_60 -> V_22 -> V_34 ;
V_60 -> V_137 = V_60 -> V_22 -> V_138 ;
error = F_70 ( V_60 , & V_110 ) ;
if ( error )
V_110 = error ;
if ( V_110 != V_74 ) {
goto V_139;
}
V_110 = F_71 ( args ,
V_60 -> V_68 ? & V_60 -> V_69 : NULL ) ;
if ( V_110 ) {
goto V_139;
}
V_124 = & V_60 -> V_127 . V_124 [ V_60 -> V_127 . V_128 - 1 ] ;
ASSERT ( V_124 -> V_9 == V_39 ) ;
V_110 = F_18 ( V_124 -> V_4 , args , V_124 -> V_40 ) ;
if ( V_110 == 0 ) {
if ( ! ( args -> V_53 & V_54 ) )
F_72 ( V_60 , & V_60 -> V_127 ) ;
} else {
if ( args -> V_119 == 0 ) {
ASSERT ( V_110 == V_50 ) ;
goto V_139;
}
V_110 = F_73 ( V_60 ) ;
}
V_139:
F_74 ( V_60 ) ;
return V_110 ;
}
static int
F_71 (
T_2 * args ,
T_15 * V_140 )
{
T_16 * V_8 ;
T_4 V_141 ;
struct V_3 * V_112 ;
T_14 * V_75 ;
T_3 * V_15 ;
T_19 * V_142 ;
int error ;
T_4 V_143 ;
struct V_3 * V_16 ;
int V_117 ;
T_1 * free = NULL ;
T_4 V_144 ;
T_4 V_145 = 0 ;
int V_65 ;
int V_118 ;
T_8 * V_22 ;
int V_114 ;
int V_115 ;
T_5 * V_146 ;
T_10 * V_2 ;
V_15 = args -> V_15 ;
V_22 = V_15 -> V_26 ;
V_2 = args -> V_27 ;
V_65 = F_30 ( args -> V_70 ) ;
if ( V_140 ) {
V_16 = V_140 -> V_4 ;
V_144 = V_140 -> V_56 ;
free = V_16 -> V_7 ;
ASSERT ( free -> V_8 . V_9 == F_2 ( V_10 ) ) ;
V_117 = V_140 -> V_40 ;
if ( V_117 >= 0 ) {
ASSERT ( V_117 < F_12 ( free -> V_8 . V_35 ) ) ;
ASSERT ( F_14 ( free -> V_12 [ V_117 ] ) != V_36 ) ;
ASSERT ( F_14 ( free -> V_12 [ V_117 ] ) >= V_65 ) ;
V_141 = F_12 ( free -> V_8 . V_30 ) + V_117 ;
}
else {
V_141 = - 1 ;
V_117 = 0 ;
}
}
else {
V_144 = V_141 = - 1 ;
V_16 = NULL ;
V_117 = 0 ;
}
if ( V_141 == - 1 ) {
T_20 V_147 ;
if ( ( error = F_75 ( V_2 , V_15 , & V_147 , V_29 ) ) )
return error ;
V_145 = F_61 ( V_22 , ( T_17 ) V_147 ) ;
V_143 = V_144 ;
}
while ( V_141 == - 1 ) {
if ( V_16 == NULL ) {
if ( ++ V_143 == 0 )
V_143 = F_8 ( V_22 ) ;
if ( V_143 == V_144 )
V_143 ++ ;
if ( V_143 >= V_145 )
break;
if ( ( error = F_34 ( V_2 , V_15 ,
F_10 ( V_22 , V_143 ) , - 2 , & V_16 ,
V_29 ) ) ) {
return error ;
}
if ( F_37 ( V_16 == NULL ) ) {
continue;
}
free = V_16 -> V_7 ;
ASSERT ( free -> V_8 . V_9 == F_2 ( V_10 ) ) ;
V_117 = 0 ;
}
if ( F_14 ( free -> V_12 [ V_117 ] ) != V_36 &&
F_14 ( free -> V_12 [ V_117 ] ) >= V_65 )
V_141 = F_12 ( free -> V_8 . V_30 ) + V_117 ;
else {
if ( ++ V_117 == F_12 ( free -> V_8 . V_35 ) ) {
F_33 ( V_2 , V_16 ) ;
V_16 = NULL ;
if ( V_140 && V_140 -> V_4 )
V_140 -> V_4 = NULL ;
}
}
}
if ( F_37 ( V_141 == - 1 ) ) {
if ( ( args -> V_53 & V_54 ) || args -> V_119 == 0 )
return F_20 ( V_50 ) ;
if ( F_37 ( ( error = F_7 ( args ,
V_148 ,
& V_141 ) ) ||
( error = F_76 ( args , V_141 , & V_112 ) ) ) )
return error ;
if ( V_16 )
F_33 ( V_2 , V_16 ) ;
if ( V_140 && V_140 -> V_4 )
V_140 -> V_4 = NULL ;
V_143 = F_32 ( V_22 , V_141 ) ;
if ( F_37 ( error = F_34 ( V_2 , V_15 ,
F_10 ( V_22 , V_143 ) , - 2 , & V_16 ,
V_29 ) ) )
return error ;
if( V_16 == NULL ) {
if ( ( error = F_7 ( args , V_28 ,
& V_143 ) ) ) {
return error ;
}
if ( F_37 ( F_32 ( V_22 , V_141 ) != V_143 ) ) {
F_50 ( V_22 ,
L_3
L_4 ,
V_108 , ( unsigned long long ) V_15 -> V_149 ,
( long long ) F_32 ( V_22 , V_141 ) ,
( long long ) V_141 , ( long long ) V_143 ,
( unsigned long long ) V_144 , V_145 ) ;
if ( V_140 ) {
F_50 ( V_22 ,
L_5 ,
V_140 ,
( unsigned long long ) V_140 -> V_56 ,
V_140 -> V_40 ,
V_140 -> V_9 ) ;
} else {
F_50 ( V_22 , L_6 ) ;
}
F_38 ( L_7 ,
V_71 , V_22 ) ;
return F_20 ( V_47 ) ;
}
if ( ( error = F_9 ( V_2 , V_15 ,
F_10 ( V_22 , V_143 ) ,
- 1 , & V_16 , V_29 ) ) ) {
return error ;
}
ASSERT ( V_16 != NULL ) ;
free = V_16 -> V_7 ;
free -> V_8 . V_9 = F_2 ( V_10 ) ;
free -> V_8 . V_30 = F_2 (
( V_143 - F_8 ( V_22 ) ) *
F_35 ( V_22 ) ) ;
free -> V_8 . V_35 = 0 ;
free -> V_8 . V_37 = 0 ;
} else {
free = V_16 -> V_7 ;
ASSERT ( free -> V_8 . V_9 == F_2 ( V_10 ) ) ;
}
V_117 = F_36 ( V_22 , V_141 ) ;
if ( V_117 >= F_12 ( free -> V_8 . V_35 ) ) {
ASSERT ( V_117 < F_35 ( V_22 ) ) ;
free -> V_8 . V_35 = F_2 ( V_117 + 1 ) ;
free -> V_12 [ V_117 ] = F_15 ( V_36 ) ;
}
if ( free -> V_12 [ V_117 ] == F_15 ( V_36 ) ) {
F_57 ( & free -> V_8 . V_37 , 1 ) ;
F_4 ( V_2 , V_16 ) ;
}
V_8 = V_112 -> V_7 ;
free -> V_12 [ V_117 ] = V_8 -> V_116 [ 0 ] . V_65 ;
V_118 = 1 ;
}
else {
if ( args -> V_53 & V_54 )
return 0 ;
error = F_34 ( V_2 , V_15 , F_10 ( V_22 , V_141 ) ,
- 1 , & V_112 , V_29 ) ;
if ( error )
return error ;
V_8 = V_112 -> V_7 ;
V_118 = 0 ;
}
ASSERT ( F_14 ( V_8 -> V_116 [ 0 ] . V_65 ) >= V_65 ) ;
V_142 = ( T_19 * )
( ( char * ) V_8 + F_14 ( V_8 -> V_116 [ 0 ] . V_150 ) ) ;
V_115 = V_114 = 0 ;
F_77 ( V_2 , V_112 , V_142 ,
( V_151 ) ( ( char * ) V_142 - ( char * ) V_8 ) , V_65 ,
& V_114 , & V_115 ) ;
V_75 = ( T_14 * ) V_142 ;
V_75 -> V_83 = F_78 ( args -> V_83 ) ;
V_75 -> V_70 = args -> V_70 ;
memcpy ( V_75 -> V_82 , args -> V_82 , V_75 -> V_70 ) ;
V_146 = F_79 ( V_75 ) ;
* V_146 = F_15 ( ( char * ) V_75 - ( char * ) V_8 ) ;
F_80 ( V_2 , V_112 , V_75 ) ;
if ( V_115 )
F_54 ( V_22 , V_8 , & V_114 ) ;
if ( V_114 )
F_55 ( V_2 , V_112 ) ;
if ( F_14 ( free -> V_12 [ V_117 ] ) != F_14 ( V_8 -> V_116 [ 0 ] . V_65 ) ) {
free -> V_12 [ V_117 ] = V_8 -> V_116 [ 0 ] . V_65 ;
V_118 = 1 ;
}
if ( V_118 )
F_1 ( V_2 , V_16 , V_117 , V_117 ) ;
args -> V_56 = ( T_17 ) V_141 ;
args -> V_40 = F_14 ( * V_146 ) ;
return 0 ;
}
int
F_81 (
T_2 * args )
{
int error ;
int V_19 ;
int V_110 ;
T_13 * V_60 ;
F_82 ( args ) ;
V_60 = F_69 () ;
V_60 -> args = args ;
V_60 -> V_22 = args -> V_15 -> V_26 ;
V_60 -> V_129 = V_60 -> V_22 -> V_34 ;
V_60 -> V_137 = V_60 -> V_22 -> V_138 ;
error = F_70 ( V_60 , & V_110 ) ;
if ( error )
V_110 = error ;
else if ( V_110 == V_74 && args -> V_78 == V_152 ) {
T_14 * V_75 ;
V_75 = ( T_14 * )
( ( char * ) V_60 -> V_69 . V_4 -> V_7 +
V_60 -> V_69 . V_40 ) ;
V_110 = F_83 ( args , V_75 -> V_82 , V_75 -> V_70 ) ;
}
for ( V_19 = 0 ; V_19 < V_60 -> V_127 . V_128 ; V_19 ++ ) {
F_33 ( args -> V_27 , V_60 -> V_127 . V_124 [ V_19 ] . V_4 ) ;
V_60 -> V_127 . V_124 [ V_19 ] . V_4 = NULL ;
}
if ( V_60 -> V_68 && V_60 -> V_69 . V_4 ) {
F_33 ( args -> V_27 , V_60 -> V_69 . V_4 ) ;
V_60 -> V_69 . V_4 = NULL ;
}
F_74 ( V_60 ) ;
return V_110 ;
}
int
F_84 (
T_2 * args )
{
T_15 * V_124 ;
int error ;
int V_110 ;
T_13 * V_60 ;
F_85 ( args ) ;
V_60 = F_69 () ;
V_60 -> args = args ;
V_60 -> V_22 = args -> V_15 -> V_26 ;
V_60 -> V_129 = V_60 -> V_22 -> V_34 ;
V_60 -> V_137 = V_60 -> V_22 -> V_138 ;
error = F_70 ( V_60 , & V_110 ) ;
if ( error )
V_110 = error ;
if ( V_110 != V_86 ) {
F_74 ( V_60 ) ;
return V_110 ;
}
V_124 = & V_60 -> V_127 . V_124 [ V_60 -> V_127 . V_128 - 1 ] ;
ASSERT ( V_124 -> V_9 == V_39 ) ;
ASSERT ( V_60 -> V_68 ) ;
error = F_51 ( args , V_124 -> V_4 , V_124 -> V_40 ,
& V_60 -> V_69 , & V_110 ) ;
if ( error )
return error ;
F_72 ( V_60 , & V_60 -> V_127 ) ;
if ( V_110 && V_60 -> V_127 . V_128 > 1 )
error = F_86 ( V_60 ) ;
if ( ! error )
error = F_87 ( V_60 ) ;
F_74 ( V_60 ) ;
return error ;
}
int
F_88 (
T_2 * args )
{
T_15 * V_124 ;
T_16 * V_8 ;
T_14 * V_75 ;
int error ;
int V_19 ;
T_21 V_153 ;
T_6 * V_20 ;
T_11 * V_43 ;
int V_110 ;
T_13 * V_60 ;
F_89 ( args ) ;
V_60 = F_69 () ;
V_60 -> args = args ;
V_60 -> V_22 = args -> V_15 -> V_26 ;
V_60 -> V_129 = V_60 -> V_22 -> V_34 ;
V_60 -> V_137 = V_60 -> V_22 -> V_138 ;
V_153 = args -> V_83 ;
error = F_70 ( V_60 , & V_110 ) ;
if ( error ) {
V_110 = error ;
}
if ( V_110 == V_86 ) {
V_124 = & V_60 -> V_127 . V_124 [ V_60 -> V_127 . V_128 - 1 ] ;
ASSERT ( V_124 -> V_9 == V_39 ) ;
V_20 = V_124 -> V_4 -> V_7 ;
V_43 = & V_20 -> V_51 [ V_124 -> V_40 ] ;
ASSERT ( V_60 -> V_68 ) ;
V_8 = V_60 -> V_69 . V_4 -> V_7 ;
ASSERT ( V_8 -> V_9 == F_2 ( V_84 ) ) ;
V_75 = ( T_14 * )
( ( char * ) V_8 +
F_41 ( V_60 -> V_22 , F_12 ( V_43 -> V_55 ) ) ) ;
ASSERT ( V_153 != F_42 ( V_75 -> V_83 ) ) ;
V_75 -> V_83 = F_78 ( V_153 ) ;
F_80 ( args -> V_27 , V_60 -> V_69 . V_4 , V_75 ) ;
V_110 = 0 ;
}
else if ( V_60 -> V_68 ) {
F_33 ( args -> V_27 , V_60 -> V_69 . V_4 ) ;
V_60 -> V_69 . V_4 = NULL ;
}
for ( V_19 = 0 ; V_19 < V_60 -> V_127 . V_128 ; V_19 ++ ) {
F_33 ( args -> V_27 , V_60 -> V_127 . V_124 [ V_19 ] . V_4 ) ;
V_60 -> V_127 . V_124 [ V_19 ] . V_4 = NULL ;
}
F_74 ( V_60 ) ;
return V_110 ;
}
int
F_90 (
T_2 * args ,
T_20 V_147 ,
int * V_154 )
{
struct V_3 * V_4 ;
T_3 * V_15 ;
int error ;
T_1 * free ;
T_8 * V_22 ;
T_10 * V_2 ;
V_15 = args -> V_15 ;
V_22 = V_15 -> V_26 ;
V_2 = args -> V_27 ;
if ( F_37 ( error = F_34 ( V_2 , V_15 , ( T_17 ) V_147 , - 2 , & V_4 ,
V_29 ) ) ) {
return error ;
}
if ( V_4 == NULL ) {
return 0 ;
}
free = V_4 -> V_7 ;
ASSERT ( free -> V_8 . V_9 == F_2 ( V_10 ) ) ;
if ( F_12 ( free -> V_8 . V_37 ) > 0 ) {
F_33 ( V_2 , V_4 ) ;
* V_154 = 0 ;
return 0 ;
}
if ( ( error =
F_56 ( args , F_61 ( V_22 , ( T_17 ) V_147 ) ,
V_4 ) ) ) {
ASSERT ( error != V_50 ) ;
F_33 ( V_2 , V_4 ) ;
return error ;
}
* V_154 = 1 ;
return 0 ;
}
