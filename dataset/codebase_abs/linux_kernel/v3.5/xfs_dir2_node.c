STATIC void
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
int V_3 ,
int V_4 )
{
T_3 * free ;
free = V_2 -> V_5 ;
ASSERT ( free -> V_6 . V_7 == F_2 ( V_8 ) ) ;
F_3 ( V_1 , V_2 ,
( V_9 ) ( ( char * ) & free -> V_10 [ V_3 ] - ( char * ) free ) ,
( V_9 ) ( ( char * ) & free -> V_10 [ V_4 ] - ( char * ) free +
sizeof( free -> V_10 [ 0 ] ) - 1 ) ) ;
}
static void
F_4 (
T_1 * V_1 ,
T_2 * V_2 )
{
T_3 * free ;
free = V_2 -> V_5 ;
ASSERT ( free -> V_6 . V_7 == F_2 ( V_8 ) ) ;
F_3 ( V_1 , V_2 , ( V_9 ) ( ( char * ) & free -> V_6 - ( char * ) free ) ,
( V_9 ) ( sizeof( V_11 ) - 1 ) ) ;
}
int
F_5 (
T_4 * args ,
T_2 * V_12 )
{
T_5 * V_13 ;
int error ;
T_2 * V_14 ;
T_6 V_15 ;
T_3 * free ;
T_7 * V_16 ;
int V_17 ;
T_8 * V_18 ;
T_9 * V_19 ;
T_10 * V_20 ;
int V_21 ;
T_11 V_22 ;
T_7 * V_23 ;
T_1 * V_1 ;
F_6 ( args ) ;
V_13 = args -> V_13 ;
V_20 = V_13 -> V_24 ;
V_1 = args -> V_25 ;
if ( ( error = F_7 ( args , V_26 , & V_15 ) ) ) {
return error ;
}
ASSERT ( V_15 == F_8 ( V_20 ) ) ;
if ( ( error = F_9 ( V_1 , V_13 , F_10 ( V_20 , V_15 ) , - 1 , & V_14 ,
V_27 ) ) ) {
return error ;
}
ASSERT ( V_14 != NULL ) ;
free = V_14 -> V_5 ;
V_18 = V_12 -> V_5 ;
V_19 = F_11 ( V_20 , V_18 ) ;
free -> V_6 . V_7 = F_2 ( V_8 ) ;
free -> V_6 . V_28 = 0 ;
ASSERT ( F_12 ( V_19 -> V_29 ) <= ( V_9 ) V_13 -> V_30 . V_31 / V_20 -> V_32 ) ;
free -> V_6 . V_33 = V_19 -> V_29 ;
for ( V_17 = V_21 = 0 , V_16 = F_13 ( V_19 ) , V_23 = free -> V_10 ;
V_17 < F_12 ( V_19 -> V_29 ) ; V_17 ++ , V_16 ++ , V_23 ++ ) {
if ( ( V_22 = F_14 ( * V_16 ) ) != V_34 )
V_21 ++ ;
* V_23 = F_15 ( V_22 ) ;
}
free -> V_6 . V_35 = F_2 ( V_21 ) ;
V_18 -> V_6 . V_36 . V_7 = F_15 ( V_37 ) ;
F_16 ( V_1 , V_12 ) ;
F_4 ( V_1 , V_14 ) ;
F_1 ( V_1 , V_14 , 0 , F_12 ( free -> V_6 . V_33 ) - 1 ) ;
F_17 ( V_14 ) ;
F_18 ( V_13 , V_12 ) ;
return 0 ;
}
static int
F_19 (
T_2 * V_2 ,
T_4 * args ,
int V_38 )
{
int V_39 ;
T_5 * V_13 ;
int V_40 ;
T_8 * V_18 ;
T_12 * V_41 ;
int V_42 ;
int V_43 ;
int V_44 ;
T_10 * V_20 ;
T_1 * V_1 ;
F_20 ( args , V_38 ) ;
V_13 = args -> V_13 ;
V_20 = V_13 -> V_24 ;
V_1 = args -> V_25 ;
V_18 = V_2 -> V_5 ;
if ( V_38 < 0 )
return F_21 ( V_45 ) ;
if ( F_14 ( V_18 -> V_6 . V_46 ) == F_22 ( V_20 ) ) {
if ( ! V_18 -> V_6 . V_47 )
return F_21 ( V_48 ) ;
V_39 = F_14 ( V_18 -> V_6 . V_47 ) > 1 ;
} else
V_39 = 0 ;
ASSERT ( V_38 == 0 || F_12 ( V_18 -> V_49 [ V_38 - 1 ] . V_50 ) <= args -> V_50 ) ;
ASSERT ( V_38 == F_14 ( V_18 -> V_6 . V_46 ) ||
F_12 ( V_18 -> V_49 [ V_38 ] . V_50 ) >= args -> V_50 ) ;
if ( args -> V_51 & V_52 )
return 0 ;
if ( V_39 ) {
F_23 ( V_2 , & V_38 , & V_44 , & V_40 ,
& V_43 , & V_42 ) ;
}
else if ( V_18 -> V_6 . V_47 ) {
V_43 = F_14 ( V_18 -> V_6 . V_46 ) ;
V_42 = - 1 ;
}
V_41 = F_24 ( V_18 , V_38 , V_39 , V_44 ,
V_40 , & V_43 , & V_42 ) ;
V_41 -> V_50 = F_2 ( args -> V_50 ) ;
V_41 -> V_53 = F_2 ( F_25 ( V_20 ,
args -> V_54 , args -> V_38 ) ) ;
F_16 ( V_1 , V_2 ) ;
F_26 ( V_1 , V_2 , V_43 , V_42 ) ;
F_18 ( V_13 , V_2 ) ;
return 0 ;
}
void
F_18 (
T_5 * V_13 ,
T_2 * V_2 )
{
int V_17 ;
T_8 * V_18 ;
T_10 * V_20 ;
int V_47 ;
V_18 = V_2 -> V_5 ;
V_20 = V_13 -> V_24 ;
ASSERT ( V_18 -> V_6 . V_36 . V_7 == F_15 ( V_37 ) ) ;
ASSERT ( F_14 ( V_18 -> V_6 . V_46 ) <= F_22 ( V_20 ) ) ;
for ( V_17 = V_47 = 0 ; V_17 < F_14 ( V_18 -> V_6 . V_46 ) ; V_17 ++ ) {
if ( V_17 + 1 < F_14 ( V_18 -> V_6 . V_46 ) ) {
ASSERT ( F_12 ( V_18 -> V_49 [ V_17 ] . V_50 ) <=
F_12 ( V_18 -> V_49 [ V_17 + 1 ] . V_50 ) ) ;
}
if ( V_18 -> V_49 [ V_17 ] . V_53 == F_2 ( V_55 ) )
V_47 ++ ;
}
ASSERT ( F_14 ( V_18 -> V_6 . V_47 ) == V_47 ) ;
}
T_13
F_27 (
T_2 * V_2 ,
int * V_46 )
{
T_8 * V_18 ;
V_18 = V_2 -> V_5 ;
ASSERT ( V_18 -> V_6 . V_36 . V_7 == F_15 ( V_37 ) ) ;
if ( V_46 )
* V_46 = F_14 ( V_18 -> V_6 . V_46 ) ;
if ( ! V_18 -> V_6 . V_46 )
return 0 ;
return F_12 ( V_18 -> V_49 [ F_14 ( V_18 -> V_6 . V_46 ) - 1 ] . V_50 ) ;
}
STATIC int
F_28 (
T_2 * V_2 ,
T_4 * args ,
int * V_56 ,
T_14 * V_57 )
{
T_2 * V_58 = NULL ;
T_6 V_59 = - 1 ;
T_6 V_60 = - 1 ;
T_5 * V_13 ;
int error ;
int V_61 ;
T_3 * free = NULL ;
int V_38 ;
T_8 * V_18 ;
int V_62 ;
T_12 * V_41 ;
T_10 * V_20 ;
T_6 V_63 ;
T_6 V_64 ;
T_1 * V_1 ;
V_13 = args -> V_13 ;
V_1 = args -> V_25 ;
V_20 = V_13 -> V_24 ;
V_18 = V_2 -> V_5 ;
ASSERT ( V_18 -> V_6 . V_36 . V_7 == F_15 ( V_37 ) ) ;
#ifdef F_29
ASSERT ( F_14 ( V_18 -> V_6 . V_46 ) > 0 ) ;
#endif
F_18 ( V_13 , V_2 ) ;
V_38 = F_30 ( args , V_2 ) ;
if ( V_57 -> V_65 ) {
V_58 = V_57 -> V_66 . V_2 ;
V_60 = V_57 -> V_66 . V_54 ;
free = V_58 -> V_5 ;
ASSERT ( free -> V_6 . V_7 == F_2 ( V_8 ) ) ;
}
V_62 = F_31 ( args -> V_67 ) ;
for ( V_41 = & V_18 -> V_49 [ V_38 ] ; V_38 < F_14 ( V_18 -> V_6 . V_46 ) &&
F_12 ( V_41 -> V_50 ) == args -> V_50 ;
V_41 ++ , V_38 ++ ) {
if ( F_12 ( V_41 -> V_53 ) == V_55 )
continue;
V_63 = F_32 ( V_20 , F_12 ( V_41 -> V_53 ) ) ;
if ( V_63 != V_59 ) {
V_59 = V_63 ;
V_64 = F_33 ( V_20 , V_63 ) ;
if ( V_64 != V_60 ) {
if ( V_58 )
F_34 ( V_1 , V_58 ) ;
error = F_35 ( V_1 , V_13 ,
F_10 ( V_20 , V_64 ) ,
- 1 , & V_58 , V_27 ) ;
if ( error )
return error ;
free = V_58 -> V_5 ;
ASSERT ( F_12 ( free -> V_6 . V_7 ) ==
V_8 ) ;
ASSERT ( ( F_12 ( free -> V_6 . V_28 ) %
F_36 ( V_20 ) ) == 0 ) ;
ASSERT ( F_12 ( free -> V_6 . V_28 ) <= V_59 ) ;
ASSERT ( V_59 < F_12 ( free -> V_6 . V_28 ) +
F_12 ( free -> V_6 . V_33 ) ) ;
}
V_61 = F_37 ( V_20 , V_59 ) ;
if ( F_38 ( free -> V_10 [ V_61 ] ==
F_15 ( V_34 ) ) ) {
F_39 ( L_1 ,
V_68 , V_20 ) ;
if ( V_60 != V_64 )
F_34 ( V_1 , V_58 ) ;
return F_21 ( V_45 ) ;
}
V_60 = V_64 ;
if ( F_14 ( free -> V_10 [ V_61 ] ) >= V_62 )
goto V_69;
}
}
V_61 = - 1 ;
V_69:
ASSERT ( args -> V_51 & V_70 ) ;
if ( V_58 ) {
V_57 -> V_65 = 1 ;
V_57 -> V_66 . V_2 = V_58 ;
V_57 -> V_66 . V_38 = V_61 ;
V_57 -> V_66 . V_54 = V_60 ;
V_57 -> V_66 . V_7 = V_8 ;
} else {
V_57 -> V_65 = 0 ;
}
* V_56 = V_38 ;
return F_21 ( V_71 ) ;
}
STATIC int
F_40 (
T_2 * V_2 ,
T_4 * args ,
int * V_56 ,
T_14 * V_57 )
{
T_2 * V_58 = NULL ;
T_6 V_59 = - 1 ;
T_15 * V_72 ;
T_5 * V_13 ;
int error ;
int V_38 ;
T_8 * V_18 ;
T_12 * V_41 ;
T_10 * V_20 ;
T_6 V_63 ;
T_1 * V_1 ;
enum V_73 V_74 ;
V_13 = args -> V_13 ;
V_1 = args -> V_25 ;
V_20 = V_13 -> V_24 ;
V_18 = V_2 -> V_5 ;
ASSERT ( V_18 -> V_6 . V_36 . V_7 == F_15 ( V_37 ) ) ;
#ifdef F_29
ASSERT ( F_14 ( V_18 -> V_6 . V_46 ) > 0 ) ;
#endif
F_18 ( V_13 , V_2 ) ;
V_38 = F_30 ( args , V_2 ) ;
if ( V_57 -> V_65 ) {
V_58 = V_57 -> V_66 . V_2 ;
V_59 = V_57 -> V_66 . V_54 ;
}
for ( V_41 = & V_18 -> V_49 [ V_38 ] ; V_38 < F_14 ( V_18 -> V_6 . V_46 ) &&
F_12 ( V_41 -> V_50 ) == args -> V_50 ;
V_41 ++ , V_38 ++ ) {
if ( F_12 ( V_41 -> V_53 ) == V_55 )
continue;
V_63 = F_32 ( V_20 , F_12 ( V_41 -> V_53 ) ) ;
if ( V_63 != V_59 ) {
if ( V_58 && ( args -> V_75 == V_76 ||
V_59 != V_57 -> V_66 . V_54 ) )
F_34 ( V_1 , V_58 ) ;
if ( args -> V_75 != V_76 &&
V_63 == V_57 -> V_66 . V_54 ) {
ASSERT ( V_57 -> V_65 ) ;
V_58 = V_57 -> V_66 . V_2 ;
} else {
error = F_35 ( V_1 , V_13 ,
F_10 ( V_20 , V_63 ) ,
- 1 , & V_58 , V_27 ) ;
if ( error )
return error ;
}
F_41 ( V_13 , V_58 ) ;
V_59 = V_63 ;
}
V_72 = ( T_15 * ) ( ( char * ) V_58 -> V_5 +
F_42 ( V_20 , F_12 ( V_41 -> V_53 ) ) ) ;
V_74 = V_20 -> V_77 -> V_78 ( args , V_72 -> V_79 , V_72 -> V_67 ) ;
if ( V_74 != V_76 && V_74 != args -> V_75 ) {
if ( args -> V_75 != V_76 &&
V_59 != V_57 -> V_66 . V_54 )
F_34 ( V_1 , V_57 -> V_66 . V_2 ) ;
args -> V_75 = V_74 ;
args -> V_80 = F_43 ( V_72 -> V_80 ) ;
* V_56 = V_38 ;
V_57 -> V_65 = 1 ;
V_57 -> V_66 . V_2 = V_58 ;
V_57 -> V_66 . V_54 = V_59 ;
V_57 -> V_66 . V_38 = ( int ) ( ( char * ) V_72 -
( char * ) V_58 -> V_5 ) ;
V_57 -> V_66 . V_7 = V_81 ;
if ( V_74 == V_82 )
return F_21 ( V_83 ) ;
}
}
ASSERT ( V_38 == F_14 ( V_18 -> V_6 . V_46 ) ||
( args -> V_51 & V_70 ) ) ;
if ( V_58 ) {
if ( args -> V_75 == V_76 ) {
V_57 -> V_65 = 1 ;
V_57 -> V_66 . V_2 = V_58 ;
V_57 -> V_66 . V_38 = - 1 ;
V_57 -> V_66 . V_54 = V_59 ;
V_57 -> V_66 . V_7 = V_81 ;
} else {
if ( V_57 -> V_66 . V_2 != V_58 )
F_34 ( V_1 , V_58 ) ;
}
} else {
V_57 -> V_65 = 0 ;
}
* V_56 = V_38 ;
return F_21 ( V_71 ) ;
}
int
F_44 (
T_2 * V_2 ,
T_4 * args ,
int * V_56 ,
T_14 * V_57 )
{
if ( args -> V_51 & V_84 )
return F_28 ( V_2 , args , V_56 ,
V_57 ) ;
return F_40 ( V_2 , args , V_56 , V_57 ) ;
}
static void
F_45 (
T_4 * args ,
T_2 * V_85 ,
int V_86 ,
T_2 * V_87 ,
int V_88 ,
int V_46 )
{
T_8 * V_89 ;
T_8 * V_90 ;
int V_47 ;
T_1 * V_1 ;
F_46 ( args , V_86 , V_88 , V_46 ) ;
if ( V_46 == 0 ) {
return;
}
V_1 = args -> V_25 ;
V_90 = V_85 -> V_5 ;
V_89 = V_87 -> V_5 ;
if ( V_88 < F_14 ( V_89 -> V_6 . V_46 ) ) {
memmove ( & V_89 -> V_49 [ V_88 + V_46 ] , & V_89 -> V_49 [ V_88 ] ,
( F_14 ( V_89 -> V_6 . V_46 ) - V_88 ) *
sizeof( T_12 ) ) ;
F_26 ( V_1 , V_87 , V_88 + V_46 ,
V_46 + F_14 ( V_89 -> V_6 . V_46 ) - 1 ) ;
}
if ( V_90 -> V_6 . V_47 ) {
int V_17 ;
for ( V_17 = V_86 , V_47 = 0 ; V_17 < V_86 + V_46 ; V_17 ++ ) {
if ( V_90 -> V_49 [ V_17 ] . V_53 ==
F_2 ( V_55 ) )
V_47 ++ ;
}
} else
V_47 = 0 ;
memcpy ( & V_89 -> V_49 [ V_88 ] , & V_90 -> V_49 [ V_86 ] ,
V_46 * sizeof( T_12 ) ) ;
F_26 ( V_1 , V_87 , V_88 , V_88 + V_46 - 1 ) ;
if ( V_86 + V_46 < F_14 ( V_90 -> V_6 . V_46 ) ) {
memmove ( & V_90 -> V_49 [ V_86 ] , & V_90 -> V_49 [ V_86 + V_46 ] ,
V_46 * sizeof( T_12 ) ) ;
F_26 ( V_1 , V_85 , V_86 , V_86 + V_46 - 1 ) ;
}
F_47 ( & V_90 -> V_6 . V_46 , - ( V_46 ) ) ;
F_47 ( & V_90 -> V_6 . V_47 , - ( V_47 ) ) ;
F_47 ( & V_89 -> V_6 . V_46 , V_46 ) ;
F_47 ( & V_89 -> V_6 . V_47 , V_47 ) ;
F_16 ( V_1 , V_85 ) ;
F_16 ( V_1 , V_87 ) ;
F_18 ( args -> V_13 , V_85 ) ;
F_18 ( args -> V_13 , V_87 ) ;
}
int
F_48 (
T_2 * V_91 ,
T_2 * V_92 )
{
T_8 * V_93 ;
T_8 * V_94 ;
V_93 = V_91 -> V_5 ;
V_94 = V_92 -> V_5 ;
ASSERT ( V_93 -> V_6 . V_36 . V_7 == F_15 ( V_37 ) ) ;
ASSERT ( V_94 -> V_6 . V_36 . V_7 == F_15 ( V_37 ) ) ;
if ( F_14 ( V_93 -> V_6 . V_46 ) > 0 &&
F_14 ( V_94 -> V_6 . V_46 ) > 0 &&
( F_12 ( V_94 -> V_49 [ 0 ] . V_50 ) < F_12 ( V_93 -> V_49 [ 0 ] . V_50 ) ||
F_12 ( V_94 -> V_49 [ F_14 ( V_94 -> V_6 . V_46 ) - 1 ] . V_50 ) <
F_12 ( V_93 -> V_49 [ F_14 ( V_93 -> V_6 . V_46 ) - 1 ] . V_50 ) ) )
return 1 ;
return 0 ;
}
static void
F_49 (
T_14 * V_57 ,
T_16 * V_95 ,
T_16 * V_96 )
{
T_4 * args ;
int V_46 ;
int V_97 ;
T_8 * V_93 ;
T_8 * V_94 ;
int V_98 ;
#ifdef F_50
int V_99 ;
#endif
int V_100 ;
int V_101 ;
args = V_57 -> args ;
if ( ( V_101 = F_48 ( V_95 -> V_2 , V_96 -> V_2 ) ) ) {
T_16 * V_102 ;
V_102 = V_95 ;
V_95 = V_96 ;
V_96 = V_102 ;
}
V_93 = V_95 -> V_2 -> V_5 ;
V_94 = V_96 -> V_2 -> V_5 ;
V_100 = F_14 ( V_93 -> V_6 . V_46 ) + F_14 ( V_94 -> V_6 . V_46 ) ;
#ifdef F_50
V_99 = F_14 ( V_93 -> V_6 . V_47 ) + F_14 ( V_94 -> V_6 . V_47 ) ;
#endif
V_98 = V_100 >> 1 ;
if ( V_100 & 1 ) {
T_13 V_103 ;
if ( V_98 >= F_14 ( V_93 -> V_6 . V_46 ) )
V_103 = F_12 ( V_94 -> V_49 [ V_98 - F_14 ( V_93 -> V_6 . V_46 ) ] . V_50 ) ;
else
V_103 = F_12 ( V_93 -> V_49 [ V_98 ] . V_50 ) ;
V_97 = args -> V_50 <= V_103 ;
}
else
V_97 = 1 ;
V_46 = F_14 ( V_93 -> V_6 . V_46 ) - V_98 + ( V_97 == 0 ) ;
if ( V_46 > 0 )
F_45 ( args , V_95 -> V_2 ,
F_14 ( V_93 -> V_6 . V_46 ) - V_46 , V_96 -> V_2 , 0 , V_46 ) ;
else if ( V_46 < 0 )
F_45 ( args , V_96 -> V_2 , 0 , V_95 -> V_2 ,
F_14 ( V_93 -> V_6 . V_46 ) , V_46 ) ;
ASSERT ( F_14 ( V_93 -> V_6 . V_46 ) + F_14 ( V_94 -> V_6 . V_46 ) == V_100 ) ;
ASSERT ( F_14 ( V_93 -> V_6 . V_47 ) + F_14 ( V_94 -> V_6 . V_47 ) == V_99 ) ;
if ( F_14 ( V_93 -> V_6 . V_46 ) < F_14 ( V_94 -> V_6 . V_46 ) )
V_57 -> V_104 = V_101 ;
else if ( F_14 ( V_93 -> V_6 . V_46 ) > F_14 ( V_94 -> V_6 . V_46 ) )
V_57 -> V_104 = ! V_101 ;
else
V_57 -> V_104 =
V_101 ^ ( V_95 -> V_38 <= F_14 ( V_93 -> V_6 . V_46 ) ) ;
if ( ! V_57 -> V_104 )
V_96 -> V_38 = V_95 -> V_38 - F_14 ( V_93 -> V_6 . V_46 ) ;
if( V_96 -> V_38 < 0 ) {
V_57 -> V_104 = 1 ;
V_96 -> V_38 = 0 ;
F_51 ( args -> V_13 -> V_24 ,
L_2 ,
V_105 , V_95 -> V_38 ) ;
}
}
static int
F_52 (
T_4 * args ,
T_2 * V_2 ,
int V_38 ,
T_16 * V_106 ,
int * V_107 )
{
T_17 * V_6 ;
T_6 V_108 ;
T_2 * V_109 ;
T_15 * V_72 ;
T_5 * V_13 ;
T_8 * V_18 ;
T_12 * V_41 ;
int V_110 ;
int V_22 ;
T_10 * V_20 ;
int V_111 ;
int V_112 ;
T_1 * V_1 ;
F_53 ( args , V_38 ) ;
V_13 = args -> V_13 ;
V_1 = args -> V_25 ;
V_20 = V_13 -> V_24 ;
V_18 = V_2 -> V_5 ;
ASSERT ( V_18 -> V_6 . V_36 . V_7 == F_15 ( V_37 ) ) ;
V_41 = & V_18 -> V_49 [ V_38 ] ;
V_108 = F_32 ( V_20 , F_12 ( V_41 -> V_53 ) ) ;
ASSERT ( V_106 -> V_54 == V_108 ) ;
V_22 = F_42 ( V_20 , F_12 ( V_41 -> V_53 ) ) ;
ASSERT ( V_106 -> V_38 == V_22 ) ;
F_47 ( & V_18 -> V_6 . V_47 , 1 ) ;
F_16 ( V_1 , V_2 ) ;
V_41 -> V_53 = F_2 ( V_55 ) ;
F_26 ( V_1 , V_2 , V_38 , V_38 ) ;
V_109 = V_106 -> V_2 ;
V_6 = V_109 -> V_5 ;
V_72 = ( T_15 * ) ( ( char * ) V_6 + V_22 ) ;
V_110 = F_14 ( V_6 -> V_113 [ 0 ] . V_62 ) ;
V_111 = V_112 = 0 ;
F_54 ( V_1 , V_109 , V_22 ,
F_31 ( V_72 -> V_67 ) , & V_111 , & V_112 ) ;
if ( V_112 )
F_55 ( V_20 , V_6 , & V_111 ) ;
if ( V_111 )
F_56 ( V_1 , V_109 ) ;
F_41 ( V_13 , V_109 ) ;
if ( V_110 < F_14 ( V_6 -> V_113 [ 0 ] . V_62 ) ) {
int error ;
T_2 * V_14 ;
T_6 V_15 ;
int V_114 ;
T_3 * free ;
int V_115 ;
V_15 = F_33 ( V_20 , V_108 ) ;
if ( ( error = F_35 ( V_1 , V_13 , F_10 ( V_20 , V_15 ) ,
- 1 , & V_14 , V_27 ) ) ) {
return error ;
}
free = V_14 -> V_5 ;
ASSERT ( free -> V_6 . V_7 == F_2 ( V_8 ) ) ;
ASSERT ( F_12 ( free -> V_6 . V_28 ) ==
F_36 ( V_20 ) *
( V_15 - F_8 ( V_20 ) ) ) ;
V_114 = F_37 ( V_20 , V_108 ) ;
V_110 = F_14 ( V_6 -> V_113 [ 0 ] . V_62 ) ;
if ( V_110 == V_20 -> V_32 - ( V_9 ) sizeof( * V_6 ) ) {
error = F_57 ( args , V_108 , V_109 ) ;
if ( error == 0 ) {
V_106 -> V_2 = NULL ;
V_6 = NULL ;
}
else if ( error == V_48 && args -> V_116 == 0 )
F_17 ( V_109 ) ;
else
return error ;
}
if ( V_6 == NULL ) {
F_58 ( & free -> V_6 . V_35 , - 1 ) ;
F_4 ( V_1 , V_14 ) ;
if ( V_114 == F_12 ( free -> V_6 . V_33 ) - 1 ) {
int V_17 ;
for ( V_17 = V_114 - 1 ;
V_17 >= 0 &&
free -> V_10 [ V_17 ] == F_15 ( V_34 ) ;
V_17 -- )
continue;
free -> V_6 . V_33 = F_2 ( V_17 + 1 ) ;
V_115 = 0 ;
}
else {
free -> V_10 [ V_114 ] = F_15 ( V_34 ) ;
V_115 = 1 ;
}
if ( ! free -> V_6 . V_35 ) {
error = F_57 ( args , V_15 , V_14 ) ;
if ( error == 0 ) {
V_14 = NULL ;
V_115 = 0 ;
} else if ( error != V_48 || args -> V_116 != 0 )
return error ;
}
}
else {
free -> V_10 [ V_114 ] = F_15 ( V_110 ) ;
V_115 = 1 ;
}
if ( V_115 )
F_1 ( V_1 , V_14 , V_114 , V_114 ) ;
if ( V_14 )
F_17 ( V_14 ) ;
}
F_18 ( V_13 , V_2 ) ;
* V_107 =
( ( V_9 ) sizeof( V_18 -> V_6 ) +
( V_9 ) sizeof( V_18 -> V_49 [ 0 ] ) *
( F_14 ( V_18 -> V_6 . V_46 ) - F_14 ( V_18 -> V_6 . V_47 ) ) ) <
V_20 -> V_117 ;
return 0 ;
}
int
F_59 (
T_14 * V_57 ,
T_16 * V_118 ,
T_16 * V_119 )
{
T_4 * args ;
T_18 V_54 ;
int error ;
T_10 * V_20 ;
args = V_57 -> args ;
V_20 = args -> V_13 -> V_24 ;
ASSERT ( args != NULL ) ;
ASSERT ( V_118 -> V_7 == V_37 ) ;
error = F_60 ( args , & V_54 ) ;
if ( error ) {
return error ;
}
error = F_61 ( args , F_62 ( V_20 , V_54 ) ,
& V_119 -> V_2 , V_37 ) ;
if ( error ) {
return error ;
}
V_119 -> V_54 = V_54 ;
V_119 -> V_7 = V_37 ;
F_49 ( V_57 , V_118 , V_119 ) ;
error = F_63 ( V_57 , V_118 , V_119 ) ;
if ( error ) {
return error ;
}
if ( V_57 -> V_104 )
error = F_19 ( V_118 -> V_2 , args , V_118 -> V_38 ) ;
else
error = F_19 ( V_119 -> V_2 , args , V_119 -> V_38 ) ;
V_118 -> V_50 = F_27 ( V_118 -> V_2 , NULL ) ;
V_119 -> V_50 = F_27 ( V_119 -> V_2 , NULL ) ;
F_18 ( args -> V_13 , V_118 -> V_2 ) ;
F_18 ( args -> V_13 , V_119 -> V_2 ) ;
return error ;
}
int
F_64 (
T_14 * V_57 ,
int * V_120 )
{
T_16 * V_121 ;
T_18 V_54 ;
T_2 * V_2 ;
int V_122 ;
int V_46 ;
int error ;
int V_123 ;
int V_17 ;
T_19 * V_36 ;
T_8 * V_18 ;
int V_107 ;
V_121 = & V_57 -> V_124 . V_121 [ V_57 -> V_124 . V_125 - 1 ] ;
V_36 = V_121 -> V_2 -> V_5 ;
ASSERT ( V_36 -> V_7 == F_15 ( V_37 ) ) ;
V_18 = ( T_8 * ) V_36 ;
V_46 = F_14 ( V_18 -> V_6 . V_46 ) - F_14 ( V_18 -> V_6 . V_47 ) ;
V_122 = ( V_9 ) sizeof( V_18 -> V_6 ) + V_46 * ( V_9 ) sizeof( V_18 -> V_49 [ 0 ] ) ;
if ( V_122 > ( V_57 -> V_126 >> 1 ) ) {
* V_120 = 0 ;
return 0 ;
}
if ( V_46 == 0 ) {
V_123 = ( V_36 -> V_127 != 0 ) ;
memcpy ( & V_57 -> V_128 , & V_57 -> V_124 , sizeof( V_57 -> V_124 ) ) ;
error = F_65 ( V_57 , & V_57 -> V_128 , V_123 , 0 ,
& V_107 ) ;
if ( error )
return error ;
* V_120 = V_107 ? 2 : 0 ;
return 0 ;
}
V_123 = F_12 ( V_36 -> V_127 ) < F_12 ( V_36 -> V_129 ) ;
for ( V_17 = 0 , V_2 = NULL ; V_17 < 2 ; V_123 = ! V_123 , V_17 ++ ) {
V_54 = V_123 ? F_12 ( V_36 -> V_127 ) : F_12 ( V_36 -> V_129 ) ;
if ( V_54 == 0 )
continue;
if ( ( error =
F_35 ( V_57 -> args -> V_25 , V_57 -> args -> V_13 , V_54 ,
- 1 , & V_2 , V_27 ) ) ) {
return error ;
}
ASSERT ( V_2 != NULL ) ;
V_18 = ( T_8 * ) V_36 ;
V_46 = F_14 ( V_18 -> V_6 . V_46 ) - F_14 ( V_18 -> V_6 . V_47 ) ;
V_122 = V_57 -> V_126 - ( V_57 -> V_126 >> 2 ) ;
V_18 = V_2 -> V_5 ;
ASSERT ( V_18 -> V_6 . V_36 . V_7 == F_15 ( V_37 ) ) ;
V_46 += F_14 ( V_18 -> V_6 . V_46 ) - F_14 ( V_18 -> V_6 . V_47 ) ;
V_122 -= V_46 * ( V_9 ) sizeof( V_18 -> V_49 [ 0 ] ) ;
if ( V_122 >= 0 )
break;
F_34 ( V_57 -> args -> V_25 , V_2 ) ;
}
if ( V_17 >= 2 ) {
* V_120 = 0 ;
return 0 ;
}
F_17 ( V_2 ) ;
memcpy ( & V_57 -> V_128 , & V_57 -> V_124 , sizeof( V_57 -> V_124 ) ) ;
if ( V_54 < V_121 -> V_54 )
error = F_65 ( V_57 , & V_57 -> V_128 , V_123 , 0 ,
& V_107 ) ;
else
error = F_65 ( V_57 , & V_57 -> V_124 , V_123 , 0 ,
& V_107 ) ;
if ( error ) {
return error ;
}
* V_120 = V_107 ? 0 : 1 ;
return 0 ;
}
void
F_66 (
T_14 * V_57 ,
T_16 * V_130 ,
T_16 * V_131 )
{
T_4 * args ;
T_8 * V_132 ;
T_8 * V_133 ;
args = V_57 -> args ;
ASSERT ( V_130 -> V_7 == V_37 ) ;
ASSERT ( V_131 -> V_7 == V_37 ) ;
V_132 = V_130 -> V_2 -> V_5 ;
V_133 = V_131 -> V_2 -> V_5 ;
ASSERT ( V_132 -> V_6 . V_36 . V_7 == F_15 ( V_37 ) ) ;
ASSERT ( V_133 -> V_6 . V_36 . V_7 == F_15 ( V_37 ) ) ;
if ( V_132 -> V_6 . V_47 )
F_67 ( args , V_130 -> V_2 ) ;
if ( V_133 -> V_6 . V_47 )
F_67 ( args , V_131 -> V_2 ) ;
V_130 -> V_50 = F_12 ( V_132 -> V_49 [ F_14 ( V_132 -> V_6 . V_46 ) - 1 ] . V_50 ) ;
if ( F_48 ( V_131 -> V_2 , V_130 -> V_2 ) )
F_45 ( args , V_130 -> V_2 , 0 , V_131 -> V_2 , 0 ,
F_14 ( V_132 -> V_6 . V_46 ) ) ;
else
F_45 ( args , V_130 -> V_2 , 0 , V_131 -> V_2 ,
F_14 ( V_133 -> V_6 . V_46 ) , F_14 ( V_132 -> V_6 . V_46 ) ) ;
V_131 -> V_50 = F_12 ( V_133 -> V_49 [ F_14 ( V_133 -> V_6 . V_46 ) - 1 ] . V_50 ) ;
F_18 ( args -> V_13 , V_131 -> V_2 ) ;
}
int
F_68 (
T_4 * args )
{
T_16 * V_121 ;
int error ;
int V_107 ;
T_14 * V_57 ;
F_69 ( args ) ;
V_57 = F_70 () ;
V_57 -> args = args ;
V_57 -> V_20 = args -> V_13 -> V_24 ;
V_57 -> V_126 = V_57 -> V_20 -> V_32 ;
V_57 -> V_134 = V_57 -> V_20 -> V_135 ;
error = F_71 ( V_57 , & V_107 ) ;
if ( error )
V_107 = error ;
if ( V_107 != V_71 ) {
goto V_136;
}
V_107 = F_72 ( args ,
V_57 -> V_65 ? & V_57 -> V_66 : NULL ) ;
if ( V_107 ) {
goto V_136;
}
V_121 = & V_57 -> V_124 . V_121 [ V_57 -> V_124 . V_125 - 1 ] ;
ASSERT ( V_121 -> V_7 == V_37 ) ;
V_107 = F_19 ( V_121 -> V_2 , args , V_121 -> V_38 ) ;
if ( V_107 == 0 ) {
if ( ! ( args -> V_51 & V_52 ) )
F_73 ( V_57 , & V_57 -> V_124 ) ;
} else {
if ( args -> V_116 == 0 ) {
ASSERT ( V_107 == V_48 ) ;
goto V_136;
}
V_107 = F_74 ( V_57 ) ;
}
V_136:
F_75 ( V_57 ) ;
return V_107 ;
}
static int
F_72 (
T_4 * args ,
T_16 * V_137 )
{
T_17 * V_6 ;
T_6 V_138 ;
T_2 * V_109 ;
T_15 * V_72 ;
T_5 * V_13 ;
T_20 * V_139 ;
int error ;
T_6 V_140 ;
T_2 * V_14 ;
int V_114 ;
T_3 * free = NULL ;
T_6 V_141 ;
T_6 V_142 = 0 ;
int V_62 ;
int V_115 ;
T_10 * V_20 ;
int V_111 ;
int V_112 ;
T_7 * V_143 ;
T_1 * V_1 ;
V_13 = args -> V_13 ;
V_20 = V_13 -> V_24 ;
V_1 = args -> V_25 ;
V_62 = F_31 ( args -> V_67 ) ;
if ( V_137 ) {
V_14 = V_137 -> V_2 ;
V_141 = V_137 -> V_54 ;
free = V_14 -> V_5 ;
ASSERT ( free -> V_6 . V_7 == F_2 ( V_8 ) ) ;
V_114 = V_137 -> V_38 ;
if ( V_114 >= 0 ) {
ASSERT ( V_114 < F_12 ( free -> V_6 . V_33 ) ) ;
ASSERT ( F_14 ( free -> V_10 [ V_114 ] ) != V_34 ) ;
ASSERT ( F_14 ( free -> V_10 [ V_114 ] ) >= V_62 ) ;
V_138 = F_12 ( free -> V_6 . V_28 ) + V_114 ;
}
else {
V_138 = - 1 ;
V_114 = 0 ;
}
}
else {
V_141 = V_138 = - 1 ;
V_14 = NULL ;
V_114 = 0 ;
}
if ( V_138 == - 1 ) {
T_21 V_144 ;
if ( ( error = F_76 ( V_1 , V_13 , & V_144 , V_27 ) ) )
return error ;
V_142 = F_62 ( V_20 , ( T_18 ) V_144 ) ;
V_140 = V_141 ;
}
while ( V_138 == - 1 ) {
if ( V_14 == NULL ) {
if ( ++ V_140 == 0 )
V_140 = F_8 ( V_20 ) ;
if ( V_140 == V_141 )
V_140 ++ ;
if ( V_140 >= V_142 )
break;
if ( ( error = F_35 ( V_1 , V_13 ,
F_10 ( V_20 , V_140 ) , - 2 , & V_14 ,
V_27 ) ) ) {
return error ;
}
if ( F_38 ( V_14 == NULL ) ) {
continue;
}
free = V_14 -> V_5 ;
ASSERT ( free -> V_6 . V_7 == F_2 ( V_8 ) ) ;
V_114 = 0 ;
}
if ( F_14 ( free -> V_10 [ V_114 ] ) != V_34 &&
F_14 ( free -> V_10 [ V_114 ] ) >= V_62 )
V_138 = F_12 ( free -> V_6 . V_28 ) + V_114 ;
else {
if ( ++ V_114 == F_12 ( free -> V_6 . V_33 ) ) {
F_34 ( V_1 , V_14 ) ;
V_14 = NULL ;
if ( V_137 && V_137 -> V_2 )
V_137 -> V_2 = NULL ;
}
}
}
if ( F_38 ( V_138 == - 1 ) ) {
if ( ( args -> V_51 & V_52 ) ||
args -> V_116 == 0 ) {
if ( ( V_137 == NULL || V_137 -> V_2 == NULL ) && V_14 != NULL )
F_17 ( V_14 ) ;
return F_21 ( V_48 ) ;
}
if ( F_38 ( ( error = F_7 ( args ,
V_145 ,
& V_138 ) ) ||
( error = F_77 ( args , V_138 , & V_109 ) ) ) ) {
if ( ( V_137 == NULL || V_137 -> V_2 == NULL ) && V_14 != NULL )
F_17 ( V_14 ) ;
return error ;
}
if ( V_14 )
F_34 ( V_1 , V_14 ) ;
if ( V_137 && V_137 -> V_2 )
V_137 -> V_2 = NULL ;
V_140 = F_33 ( V_20 , V_138 ) ;
if ( F_38 ( error = F_35 ( V_1 , V_13 ,
F_10 ( V_20 , V_140 ) , - 2 , & V_14 ,
V_27 ) ) ) {
F_17 ( V_109 ) ;
return error ;
}
if( V_14 == NULL ) {
if ( ( error = F_7 ( args , V_26 ,
& V_140 ) ) ) {
return error ;
}
if ( F_38 ( F_33 ( V_20 , V_138 ) != V_140 ) ) {
F_51 ( V_20 ,
L_3
L_4 ,
V_105 , ( unsigned long long ) V_13 -> V_146 ,
( long long ) F_33 ( V_20 , V_138 ) ,
( long long ) V_138 , ( long long ) V_140 ,
( unsigned long long ) V_141 , V_142 ) ;
if ( V_137 ) {
F_51 ( V_20 ,
L_5 ,
V_137 ,
( unsigned long long ) V_137 -> V_54 ,
V_137 -> V_38 ,
V_137 -> V_7 ) ;
} else {
F_51 ( V_20 , L_6 ) ;
}
F_39 ( L_7 ,
V_68 , V_20 ) ;
return F_21 ( V_45 ) ;
}
if ( ( error = F_9 ( V_1 , V_13 ,
F_10 ( V_20 , V_140 ) ,
- 1 , & V_14 , V_27 ) ) ) {
return error ;
}
ASSERT ( V_14 != NULL ) ;
free = V_14 -> V_5 ;
free -> V_6 . V_7 = F_2 ( V_8 ) ;
free -> V_6 . V_28 = F_2 (
( V_140 - F_8 ( V_20 ) ) *
F_36 ( V_20 ) ) ;
free -> V_6 . V_33 = 0 ;
free -> V_6 . V_35 = 0 ;
} else {
free = V_14 -> V_5 ;
ASSERT ( free -> V_6 . V_7 == F_2 ( V_8 ) ) ;
}
V_114 = F_37 ( V_20 , V_138 ) ;
if ( V_114 >= F_12 ( free -> V_6 . V_33 ) ) {
ASSERT ( V_114 < F_36 ( V_20 ) ) ;
free -> V_6 . V_33 = F_2 ( V_114 + 1 ) ;
free -> V_10 [ V_114 ] = F_15 ( V_34 ) ;
}
if ( free -> V_10 [ V_114 ] == F_15 ( V_34 ) ) {
F_58 ( & free -> V_6 . V_35 , 1 ) ;
F_4 ( V_1 , V_14 ) ;
}
V_6 = V_109 -> V_5 ;
free -> V_10 [ V_114 ] = V_6 -> V_113 [ 0 ] . V_62 ;
V_115 = 1 ;
}
else {
if ( args -> V_51 & V_52 ) {
if ( ( V_137 == NULL || V_137 -> V_2 == NULL ) && V_14 != NULL )
F_17 ( V_14 ) ;
return 0 ;
}
if ( F_38 (
error = F_35 ( V_1 , V_13 , F_10 ( V_20 , V_138 ) ,
- 1 , & V_109 , V_27 ) ) ) {
if ( ( V_137 == NULL || V_137 -> V_2 == NULL ) && V_14 != NULL )
F_17 ( V_14 ) ;
return error ;
}
V_6 = V_109 -> V_5 ;
V_115 = 0 ;
}
ASSERT ( F_14 ( V_6 -> V_113 [ 0 ] . V_62 ) >= V_62 ) ;
V_139 = ( T_20 * )
( ( char * ) V_6 + F_14 ( V_6 -> V_113 [ 0 ] . V_147 ) ) ;
V_112 = V_111 = 0 ;
F_78 ( V_1 , V_109 , V_139 ,
( V_148 ) ( ( char * ) V_139 - ( char * ) V_6 ) , V_62 ,
& V_111 , & V_112 ) ;
V_72 = ( T_15 * ) V_139 ;
V_72 -> V_80 = F_79 ( args -> V_80 ) ;
V_72 -> V_67 = args -> V_67 ;
memcpy ( V_72 -> V_79 , args -> V_79 , V_72 -> V_67 ) ;
V_143 = F_80 ( V_72 ) ;
* V_143 = F_15 ( ( char * ) V_72 - ( char * ) V_6 ) ;
F_81 ( V_1 , V_109 , V_72 ) ;
if ( V_112 )
F_55 ( V_20 , V_6 , & V_111 ) ;
if ( V_111 )
F_56 ( V_1 , V_109 ) ;
if ( F_14 ( free -> V_10 [ V_114 ] ) != F_14 ( V_6 -> V_113 [ 0 ] . V_62 ) ) {
free -> V_10 [ V_114 ] = V_6 -> V_113 [ 0 ] . V_62 ;
V_115 = 1 ;
}
if ( V_115 )
F_1 ( V_1 , V_14 , V_114 , V_114 ) ;
if ( ( V_137 == NULL || V_137 -> V_2 == NULL ) && V_14 != NULL )
F_17 ( V_14 ) ;
args -> V_54 = ( T_18 ) V_138 ;
args -> V_38 = F_14 ( * V_143 ) ;
F_17 ( V_109 ) ;
return 0 ;
}
int
F_82 (
T_4 * args )
{
int error ;
int V_17 ;
int V_107 ;
T_14 * V_57 ;
F_83 ( args ) ;
V_57 = F_70 () ;
V_57 -> args = args ;
V_57 -> V_20 = args -> V_13 -> V_24 ;
V_57 -> V_126 = V_57 -> V_20 -> V_32 ;
V_57 -> V_134 = V_57 -> V_20 -> V_135 ;
error = F_71 ( V_57 , & V_107 ) ;
if ( error )
V_107 = error ;
else if ( V_107 == V_71 && args -> V_75 == V_149 ) {
T_15 * V_72 ;
V_72 = ( T_15 * ) ( ( char * ) V_57 -> V_66 . V_2 ->
V_5 + V_57 -> V_66 . V_38 ) ;
V_107 = F_84 ( args , V_72 -> V_79 , V_72 -> V_67 ) ;
}
for ( V_17 = 0 ; V_17 < V_57 -> V_124 . V_125 ; V_17 ++ ) {
F_34 ( args -> V_25 , V_57 -> V_124 . V_121 [ V_17 ] . V_2 ) ;
V_57 -> V_124 . V_121 [ V_17 ] . V_2 = NULL ;
}
if ( V_57 -> V_65 && V_57 -> V_66 . V_2 ) {
F_34 ( args -> V_25 , V_57 -> V_66 . V_2 ) ;
V_57 -> V_66 . V_2 = NULL ;
}
F_75 ( V_57 ) ;
return V_107 ;
}
int
F_85 (
T_4 * args )
{
T_16 * V_121 ;
int error ;
int V_107 ;
T_14 * V_57 ;
F_86 ( args ) ;
V_57 = F_70 () ;
V_57 -> args = args ;
V_57 -> V_20 = args -> V_13 -> V_24 ;
V_57 -> V_126 = V_57 -> V_20 -> V_32 ;
V_57 -> V_134 = V_57 -> V_20 -> V_135 ;
error = F_71 ( V_57 , & V_107 ) ;
if ( error )
V_107 = error ;
if ( V_107 != V_83 ) {
F_75 ( V_57 ) ;
return V_107 ;
}
V_121 = & V_57 -> V_124 . V_121 [ V_57 -> V_124 . V_125 - 1 ] ;
ASSERT ( V_121 -> V_7 == V_37 ) ;
ASSERT ( V_57 -> V_65 ) ;
error = F_52 ( args , V_121 -> V_2 , V_121 -> V_38 ,
& V_57 -> V_66 , & V_107 ) ;
if ( error )
return error ;
F_73 ( V_57 , & V_57 -> V_124 ) ;
if ( V_107 && V_57 -> V_124 . V_125 > 1 )
error = F_87 ( V_57 ) ;
if ( ! error )
error = F_88 ( V_57 ) ;
F_75 ( V_57 ) ;
return error ;
}
int
F_89 (
T_4 * args )
{
T_16 * V_121 ;
T_17 * V_6 ;
T_15 * V_72 ;
int error ;
int V_17 ;
T_22 V_150 ;
T_8 * V_18 ;
T_12 * V_41 ;
int V_107 ;
T_14 * V_57 ;
F_90 ( args ) ;
V_57 = F_70 () ;
V_57 -> args = args ;
V_57 -> V_20 = args -> V_13 -> V_24 ;
V_57 -> V_126 = V_57 -> V_20 -> V_32 ;
V_57 -> V_134 = V_57 -> V_20 -> V_135 ;
V_150 = args -> V_80 ;
error = F_71 ( V_57 , & V_107 ) ;
if ( error ) {
V_107 = error ;
}
if ( V_107 == V_83 ) {
V_121 = & V_57 -> V_124 . V_121 [ V_57 -> V_124 . V_125 - 1 ] ;
ASSERT ( V_121 -> V_7 == V_37 ) ;
V_18 = V_121 -> V_2 -> V_5 ;
V_41 = & V_18 -> V_49 [ V_121 -> V_38 ] ;
ASSERT ( V_57 -> V_65 ) ;
V_6 = V_57 -> V_66 . V_2 -> V_5 ;
ASSERT ( V_6 -> V_7 == F_2 ( V_81 ) ) ;
V_72 = ( T_15 * )
( ( char * ) V_6 +
F_42 ( V_57 -> V_20 , F_12 ( V_41 -> V_53 ) ) ) ;
ASSERT ( V_150 != F_43 ( V_72 -> V_80 ) ) ;
V_72 -> V_80 = F_79 ( V_150 ) ;
F_81 ( args -> V_25 , V_57 -> V_66 . V_2 , V_72 ) ;
V_107 = 0 ;
}
else if ( V_57 -> V_65 ) {
F_34 ( args -> V_25 , V_57 -> V_66 . V_2 ) ;
V_57 -> V_66 . V_2 = NULL ;
}
for ( V_17 = 0 ; V_17 < V_57 -> V_124 . V_125 ; V_17 ++ ) {
F_34 ( args -> V_25 , V_57 -> V_124 . V_121 [ V_17 ] . V_2 ) ;
V_57 -> V_124 . V_121 [ V_17 ] . V_2 = NULL ;
}
F_75 ( V_57 ) ;
return V_107 ;
}
int
F_91 (
T_4 * args ,
T_21 V_144 ,
int * V_151 )
{
T_2 * V_2 ;
T_5 * V_13 ;
int error ;
T_3 * free ;
T_10 * V_20 ;
T_1 * V_1 ;
V_13 = args -> V_13 ;
V_20 = V_13 -> V_24 ;
V_1 = args -> V_25 ;
if ( F_38 ( error = F_35 ( V_1 , V_13 , ( T_18 ) V_144 , - 2 , & V_2 ,
V_27 ) ) ) {
return error ;
}
if ( V_2 == NULL ) {
return 0 ;
}
free = V_2 -> V_5 ;
ASSERT ( free -> V_6 . V_7 == F_2 ( V_8 ) ) ;
if ( F_12 ( free -> V_6 . V_35 ) > 0 ) {
F_34 ( V_1 , V_2 ) ;
* V_151 = 0 ;
return 0 ;
}
if ( ( error =
F_57 ( args , F_62 ( V_20 , ( T_18 ) V_144 ) ,
V_2 ) ) ) {
ASSERT ( error != V_48 ) ;
F_34 ( V_1 , V_2 ) ;
return error ;
}
* V_151 = 1 ;
return 0 ;
}
