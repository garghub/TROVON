static unsigned char
F_1 (
struct V_1 * V_2 ,
T_1 V_3 )
{
if ( ! F_2 ( & V_2 -> V_4 ) )
return V_5 ;
if ( V_3 >= V_6 )
return V_5 ;
return V_7 [ V_3 ] ;
}
STATIC int
F_3 (
struct V_8 * args ,
struct V_9 * V_10 )
{
int V_11 ;
struct V_12 * V_13 = args -> V_13 ;
T_2 V_14 ;
T_3 * V_15 ;
T_4 * V_16 ;
T_2 V_17 ;
T_2 V_18 ;
T_5 V_19 ;
struct V_20 * V_21 = args -> V_21 ;
ASSERT ( V_13 -> V_22 . V_23 & V_24 ) ;
if ( V_13 -> V_25 . V_26 < F_4 ( T_4 , V_27 ) ) {
ASSERT ( F_5 ( V_13 -> V_28 ) ) ;
return - V_29 ;
}
ASSERT ( V_13 -> V_22 . V_30 == V_13 -> V_25 . V_26 ) ;
ASSERT ( V_13 -> V_22 . V_31 . V_32 != NULL ) ;
V_16 = ( T_4 * ) V_13 -> V_22 . V_31 . V_32 ;
ASSERT ( V_13 -> V_25 . V_26 >= F_6 ( V_16 -> V_33 ) ) ;
if ( F_7 ( V_21 , V_10 -> V_34 ) > V_21 -> V_35 )
return 0 ;
V_17 = F_8 ( V_21 , V_21 -> V_35 ,
V_13 -> V_36 -> V_37 ) ;
V_18 = F_8 ( V_21 , V_21 -> V_35 ,
V_13 -> V_36 -> V_38 ) ;
if ( V_10 -> V_34 <= V_17 ) {
V_10 -> V_34 = V_17 & 0x7fffffff ;
if ( ! F_9 ( V_10 , L_1 , 1 , V_13 -> V_39 , V_40 ) )
return 0 ;
}
if ( V_10 -> V_34 <= V_18 ) {
V_19 = V_13 -> V_36 -> V_41 ( V_16 ) ;
V_10 -> V_34 = V_18 & 0x7fffffff ;
if ( ! F_9 ( V_10 , L_2 , 2 , V_19 , V_40 ) )
return 0 ;
}
V_15 = F_10 ( V_16 ) ;
for ( V_11 = 0 ; V_11 < V_16 -> V_42 ; V_11 ++ ) {
T_1 V_3 ;
V_14 = F_8 ( V_21 , V_21 -> V_35 ,
F_11 ( V_15 ) ) ;
if ( V_10 -> V_34 > V_14 ) {
V_15 = V_13 -> V_36 -> V_43 ( V_16 , V_15 ) ;
continue;
}
V_19 = V_13 -> V_36 -> V_44 ( V_16 , V_15 ) ;
V_3 = V_13 -> V_36 -> V_45 ( V_15 ) ;
V_10 -> V_34 = V_14 & 0x7fffffff ;
if ( ! F_9 ( V_10 , ( char * ) V_15 -> V_46 , V_15 -> V_47 , V_19 ,
F_1 ( V_13 -> V_28 , V_3 ) ) )
return 0 ;
V_15 = V_13 -> V_36 -> V_43 ( V_16 , V_15 ) ;
}
V_10 -> V_34 = F_8 ( V_21 , V_21 -> V_35 + 1 , 0 ) &
0x7fffffff ;
return 0 ;
}
STATIC int
F_12 (
struct V_8 * args ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = args -> V_13 ;
T_6 * V_48 ;
struct V_49 * V_50 ;
T_7 * V_51 ;
T_8 * V_52 ;
T_9 * V_53 ;
char * V_54 ;
int error ;
char * V_55 ;
int V_56 ;
T_10 V_57 ;
struct V_20 * V_21 = args -> V_21 ;
int V_58 ;
if ( F_7 ( V_21 , V_10 -> V_34 ) > V_21 -> V_35 )
return 0 ;
V_58 = F_13 ( V_13 ) ;
error = F_14 ( NULL , V_13 , & V_50 ) ;
F_15 ( V_13 , V_58 ) ;
if ( error )
return error ;
V_56 = F_16 ( V_21 , V_10 -> V_34 ) ;
V_48 = V_50 -> V_59 ;
F_17 ( V_13 , V_50 ) ;
V_51 = F_18 ( V_21 , V_48 ) ;
V_55 = ( char * ) V_13 -> V_36 -> V_60 ( V_48 ) ;
V_54 = ( char * ) F_19 ( V_51 ) ;
while ( V_55 < V_54 ) {
T_1 V_3 ;
V_53 = ( T_9 * ) V_55 ;
if ( F_20 ( V_53 -> V_61 ) == V_62 ) {
V_55 += F_20 ( V_53 -> V_63 ) ;
continue;
}
V_52 = ( T_8 * ) V_55 ;
V_55 += V_13 -> V_36 -> V_64 ( V_52 -> V_47 ) ;
if ( ( char * ) V_52 - ( char * ) V_48 < V_56 )
continue;
V_57 = F_8 ( V_21 , V_21 -> V_35 ,
( char * ) V_52 - ( char * ) V_48 ) ;
V_10 -> V_34 = V_57 & 0x7fffffff ;
V_3 = V_13 -> V_36 -> V_65 ( V_52 ) ;
if ( ! F_9 ( V_10 , ( char * ) V_52 -> V_46 , V_52 -> V_47 ,
F_21 ( V_52 -> V_66 ) ,
F_1 ( V_13 -> V_28 , V_3 ) ) ) {
F_22 ( NULL , V_50 ) ;
return 0 ;
}
}
V_10 -> V_34 = F_8 ( V_21 , V_21 -> V_35 + 1 , 0 ) &
0x7fffffff ;
F_22 ( NULL , V_50 ) ;
return 0 ;
}
STATIC int
F_23 (
struct V_8 * args ,
T_11 V_67 ,
struct V_68 * V_69 ,
T_12 * V_70 ,
struct V_49 * * V_71 ,
bool V_72 )
{
struct V_12 * V_13 = args -> V_13 ;
struct V_49 * V_50 = NULL ;
struct V_73 * V_74 = V_69 -> V_74 ;
struct V_75 V_76 ;
int error = 0 ;
int V_63 ;
int V_11 ;
int V_77 ;
struct V_20 * V_21 = args -> V_21 ;
if ( V_72 ) {
V_69 -> V_78 -= V_21 -> V_79 ;
for ( V_11 = V_21 -> V_79 ; V_11 > 0 ; ) {
V_77 = F_24 ( int , V_74 -> V_80 , V_11 ) ;
V_74 -> V_80 -= V_77 ;
V_74 -> V_81 += V_77 ;
V_74 -> V_82 += V_77 ;
if ( ! V_74 -> V_80 && -- V_69 -> V_83 )
memmove ( & V_74 [ 0 ] , & V_74 [ 1 ] ,
sizeof( V_74 [ 0 ] ) * V_69 -> V_83 ) ;
V_11 -= V_77 ;
}
}
V_69 -> V_84 = F_25 ( V_67 + V_21 -> V_85 , ( 1 << V_21 -> V_86 ) ) - 1 ;
ASSERT ( V_69 -> V_84 >= 0 ) ;
if ( 1 + V_69 -> V_84 > V_69 -> V_78 &&
V_69 -> V_87 < F_26 ( V_21 , V_88 ) ) {
V_69 -> V_89 = V_69 -> V_90 - V_69 -> V_83 ;
error = F_27 ( V_13 , V_69 -> V_87 ,
F_26 ( V_21 , V_88 ) -
V_69 -> V_87 ,
& V_74 [ V_69 -> V_83 ] , & V_69 -> V_89 , 0 ) ;
if ( error )
goto V_91;
if ( V_69 -> V_89 == V_69 -> V_90 - V_69 -> V_83 ) {
V_11 = V_69 -> V_83 + V_69 -> V_89 - 1 ;
V_69 -> V_87 = V_74 [ V_11 ] . V_82 + V_74 [ V_11 ] . V_80 ;
} else
V_69 -> V_87 = F_26 ( V_21 ,
V_88 ) ;
for ( V_11 = V_69 -> V_83 ; V_11 < V_69 -> V_83 + V_69 -> V_89 ; ) {
if ( V_74 [ V_11 ] . V_81 == V_92 ) {
V_69 -> V_89 -- ;
V_63 = V_69 -> V_83 + V_69 -> V_89 - V_11 ;
if ( V_63 )
memmove ( & V_74 [ V_11 ] , & V_74 [ V_11 + 1 ] ,
sizeof( V_74 [ V_11 ] ) * V_63 ) ;
} else {
V_69 -> V_78 += V_74 [ V_11 ] . V_80 ;
V_11 ++ ;
}
}
V_69 -> V_83 += V_69 -> V_89 ;
}
if ( ! V_69 -> V_83 ) {
* V_70 = F_28 ( V_21 , V_69 -> V_87 ) ;
goto V_91;
}
V_69 -> V_93 = F_29 ( V_21 , V_74 -> V_82 ) ;
error = F_30 ( NULL , V_13 , V_74 -> V_82 ,
V_74 -> V_80 >= V_21 -> V_79 ?
F_31 ( V_13 -> V_28 , V_74 -> V_81 ) :
- 1 , & V_50 ) ;
if ( error )
goto V_91;
if ( V_69 -> V_94 )
V_69 -> V_94 -= V_21 -> V_79 ;
F_32 ( & V_76 ) ;
for ( V_69 -> V_95 = V_69 -> V_96 = V_11 = 0 ;
V_69 -> V_84 > V_69 -> V_94 && V_11 < V_69 -> V_78 ;
V_11 += V_21 -> V_79 ) {
ASSERT ( V_69 -> V_95 < V_69 -> V_83 ) ;
if ( V_11 > V_69 -> V_94 &&
V_74 [ V_69 -> V_95 ] . V_80 >= V_21 -> V_79 ) {
F_33 ( V_13 ,
V_74 [ V_69 -> V_95 ] . V_82 + V_69 -> V_96 ,
F_31 ( V_13 -> V_28 ,
V_74 [ V_69 -> V_95 ] . V_81 +
V_69 -> V_96 ) ) ;
V_69 -> V_94 = V_11 ;
}
else if ( V_11 > V_69 -> V_94 ) {
F_33 ( V_13 ,
V_74 [ V_69 -> V_95 ] . V_82 +
V_69 -> V_96 , - 1 ) ;
V_69 -> V_94 = V_11 ;
}
for ( V_77 = 0 ; V_77 < V_21 -> V_79 ; V_77 += V_63 ) {
V_63 = F_24 ( int , V_21 -> V_79 ,
V_74 [ V_69 -> V_95 ] . V_80 -
V_69 -> V_96 ) ;
V_69 -> V_96 += V_63 ;
if ( V_69 -> V_96 == V_74 [ V_69 -> V_95 ] . V_80 ) {
V_69 -> V_96 = 0 ;
V_69 -> V_95 ++ ;
}
}
}
F_34 ( & V_76 ) ;
V_91:
* V_71 = V_50 ;
return error ;
}
STATIC int
F_35 (
struct V_8 * args ,
struct V_9 * V_10 ,
T_11 V_67 )
{
struct V_12 * V_13 = args -> V_13 ;
struct V_49 * V_50 = NULL ;
T_6 * V_48 ;
T_8 * V_52 ;
T_9 * V_53 ;
int error = 0 ;
int V_63 ;
int V_97 ;
T_12 V_70 ;
T_12 V_98 ;
char * V_55 = NULL ;
struct V_68 * V_99 ;
struct V_20 * V_21 = args -> V_21 ;
if ( V_10 -> V_34 >= V_100 )
return 0 ;
V_63 = F_25 ( V_67 + V_21 -> V_85 , ( 1 << V_21 -> V_86 ) ) ;
V_99 = F_36 ( F_4 ( struct V_68 , V_74 ) +
( V_63 * sizeof( struct V_73 ) ) ,
V_101 | V_102 ) ;
V_99 -> V_90 = V_63 ;
V_70 = F_37 ( V_10 -> V_34 ) ;
V_99 -> V_87 = F_38 ( V_21 ,
F_39 ( V_21 , V_70 ) ) ;
while ( V_70 < V_88 ) {
T_1 V_3 ;
if ( ! V_50 || V_55 >= ( char * ) V_50 -> V_59 + V_21 -> V_85 ) {
int V_58 ;
bool V_72 = false ;
if ( V_50 ) {
F_22 ( NULL , V_50 ) ;
V_50 = NULL ;
V_72 = true ;
}
V_58 = F_13 ( V_13 ) ;
error = F_23 ( args , V_67 , V_99 ,
& V_70 , & V_50 , V_72 ) ;
F_15 ( V_13 , V_58 ) ;
if ( error || ! V_99 -> V_83 )
break;
V_98 = F_40 ( V_21 ,
V_99 -> V_93 , 0 ) ;
if ( V_70 < V_98 )
V_70 = V_98 ;
else if ( V_70 > V_98 )
ASSERT ( F_39 ( V_21 , V_70 ) ==
V_99 -> V_93 ) ;
V_48 = V_50 -> V_59 ;
F_17 ( V_13 , V_50 ) ;
V_55 = ( char * ) V_13 -> V_36 -> V_60 ( V_48 ) ;
V_97 = F_41 ( V_21 , V_70 ) ;
if ( V_97 == 0 )
V_70 += V_13 -> V_36 -> V_103 ;
else {
while ( ( char * ) V_55 - ( char * ) V_48 < V_97 ) {
V_53 = ( T_9 * ) V_55 ;
if ( F_20 ( V_53 -> V_61 )
== V_62 ) {
V_63 = F_20 ( V_53 -> V_63 ) ;
V_55 += V_63 ;
continue;
}
V_52 = ( T_8 * ) V_55 ;
V_63 =
V_13 -> V_36 -> V_64 ( V_52 -> V_47 ) ;
V_55 += V_63 ;
}
V_70 =
F_40 ( V_21 ,
F_39 ( V_21 , V_70 ) ,
( char * ) V_55 - ( char * ) V_48 ) ;
if ( V_55 >= ( char * ) V_48 + V_21 -> V_85 ) {
continue;
}
}
}
V_53 = ( T_9 * ) V_55 ;
if ( F_20 ( V_53 -> V_61 ) == V_62 ) {
V_63 = F_20 ( V_53 -> V_63 ) ;
V_55 += V_63 ;
V_70 += V_63 ;
continue;
}
V_52 = ( T_8 * ) V_55 ;
V_63 = V_13 -> V_36 -> V_64 ( V_52 -> V_47 ) ;
V_3 = V_13 -> V_36 -> V_65 ( V_52 ) ;
V_10 -> V_34 = F_42 ( V_70 ) & 0x7fffffff ;
if ( ! F_9 ( V_10 , ( char * ) V_52 -> V_46 , V_52 -> V_47 ,
F_21 ( V_52 -> V_66 ) ,
F_1 ( V_13 -> V_28 , V_3 ) ) )
break;
V_55 += V_63 ;
V_70 += V_63 ;
V_67 = V_67 > V_63 ? V_67 - V_63 : 0 ;
}
if ( V_70 > F_37 ( V_100 ) )
V_10 -> V_34 = V_100 & 0x7fffffff ;
else
V_10 -> V_34 = F_42 ( V_70 ) & 0x7fffffff ;
F_43 ( V_99 ) ;
if ( V_50 )
F_22 ( NULL , V_50 ) ;
return error ;
}
int
F_44 (
struct V_12 * V_13 ,
struct V_9 * V_10 ,
T_11 V_67 )
{
struct V_8 args = { NULL } ;
int V_104 ;
int V_105 ;
F_45 ( V_13 ) ;
if ( F_5 ( V_13 -> V_28 ) )
return - V_29 ;
ASSERT ( F_46 ( F_47 ( V_13 ) -> V_106 ) ) ;
F_48 ( V_13 -> V_28 , V_107 ) ;
args . V_13 = V_13 ;
args . V_21 = V_13 -> V_28 -> V_108 ;
F_49 ( V_13 , V_109 ) ;
if ( V_13 -> V_25 . V_110 == V_111 )
V_104 = F_3 ( & args , V_10 ) ;
else if ( ( V_104 = F_50 ( & args , & V_105 ) ) )
;
else if ( V_105 )
V_104 = F_12 ( & args , V_10 ) ;
else
V_104 = F_35 ( & args , V_10 , V_67 ) ;
F_15 ( V_13 , V_109 ) ;
return V_104 ;
}
