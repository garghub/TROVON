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
ASSERT ( V_13 -> V_22 . V_25 == V_13 -> V_26 . V_27 ) ;
ASSERT ( V_13 -> V_22 . V_28 . V_29 != NULL ) ;
V_16 = ( T_4 * ) V_13 -> V_22 . V_28 . V_29 ;
if ( F_4 ( V_21 , V_10 -> V_30 ) > V_21 -> V_31 )
return 0 ;
V_17 = F_5 ( V_21 , V_21 -> V_31 ,
V_13 -> V_32 -> V_33 ) ;
V_18 = F_5 ( V_21 , V_21 -> V_31 ,
V_13 -> V_32 -> V_34 ) ;
if ( V_10 -> V_30 <= V_17 ) {
V_10 -> V_30 = V_17 & 0x7fffffff ;
if ( ! F_6 ( V_10 , L_1 , 1 , V_13 -> V_35 , V_36 ) )
return 0 ;
}
if ( V_10 -> V_30 <= V_18 ) {
V_19 = V_13 -> V_32 -> V_37 ( V_16 ) ;
V_10 -> V_30 = V_18 & 0x7fffffff ;
if ( ! F_6 ( V_10 , L_2 , 2 , V_19 , V_36 ) )
return 0 ;
}
V_15 = F_7 ( V_16 ) ;
for ( V_11 = 0 ; V_11 < V_16 -> V_38 ; V_11 ++ ) {
T_1 V_3 ;
V_14 = F_5 ( V_21 , V_21 -> V_31 ,
F_8 ( V_15 ) ) ;
if ( V_10 -> V_30 > V_14 ) {
V_15 = V_13 -> V_32 -> V_39 ( V_16 , V_15 ) ;
continue;
}
V_19 = V_13 -> V_32 -> V_40 ( V_16 , V_15 ) ;
V_3 = V_13 -> V_32 -> V_41 ( V_15 ) ;
V_10 -> V_30 = V_14 & 0x7fffffff ;
if ( ! F_6 ( V_10 , ( char * ) V_15 -> V_42 , V_15 -> V_43 , V_19 ,
F_1 ( V_13 -> V_44 , V_3 ) ) )
return 0 ;
V_15 = V_13 -> V_32 -> V_39 ( V_16 , V_15 ) ;
}
V_10 -> V_30 = F_5 ( V_21 , V_21 -> V_31 + 1 , 0 ) &
0x7fffffff ;
return 0 ;
}
STATIC int
F_9 (
struct V_8 * args ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = args -> V_13 ;
T_6 * V_45 ;
struct V_46 * V_47 ;
T_7 * V_48 ;
T_8 * V_49 ;
T_9 * V_50 ;
char * V_51 ;
int error ;
char * V_52 ;
int V_53 ;
T_10 V_54 ;
struct V_20 * V_21 = args -> V_21 ;
int V_55 ;
if ( F_4 ( V_21 , V_10 -> V_30 ) > V_21 -> V_31 )
return 0 ;
V_55 = F_10 ( V_13 ) ;
error = F_11 ( NULL , V_13 , & V_47 ) ;
F_12 ( V_13 , V_55 ) ;
if ( error )
return error ;
V_53 = F_13 ( V_21 , V_10 -> V_30 ) ;
V_45 = V_47 -> V_56 ;
F_14 ( V_13 , V_47 ) ;
V_48 = F_15 ( V_21 , V_45 ) ;
V_52 = ( char * ) V_13 -> V_32 -> V_57 ( V_45 ) ;
V_51 = ( char * ) F_16 ( V_48 ) ;
while ( V_52 < V_51 ) {
T_1 V_3 ;
V_50 = ( T_9 * ) V_52 ;
if ( F_17 ( V_50 -> V_58 ) == V_59 ) {
V_52 += F_17 ( V_50 -> V_60 ) ;
continue;
}
V_49 = ( T_8 * ) V_52 ;
V_52 += V_13 -> V_32 -> V_61 ( V_49 -> V_43 ) ;
if ( ( char * ) V_49 - ( char * ) V_45 < V_53 )
continue;
V_54 = F_5 ( V_21 , V_21 -> V_31 ,
( char * ) V_49 - ( char * ) V_45 ) ;
V_10 -> V_30 = V_54 & 0x7fffffff ;
V_3 = V_13 -> V_32 -> V_62 ( V_49 ) ;
if ( ! F_6 ( V_10 , ( char * ) V_49 -> V_42 , V_49 -> V_43 ,
F_18 ( V_49 -> V_63 ) ,
F_1 ( V_13 -> V_44 , V_3 ) ) ) {
F_19 ( NULL , V_47 ) ;
return 0 ;
}
}
V_10 -> V_30 = F_5 ( V_21 , V_21 -> V_31 + 1 , 0 ) &
0x7fffffff ;
F_19 ( NULL , V_47 ) ;
return 0 ;
}
STATIC int
F_20 (
struct V_8 * args ,
T_11 V_64 ,
struct V_65 * V_66 ,
T_12 * V_67 ,
struct V_46 * * V_68 ,
bool V_69 )
{
struct V_12 * V_13 = args -> V_13 ;
struct V_46 * V_47 = NULL ;
struct V_70 * V_71 = V_66 -> V_71 ;
struct V_72 V_73 ;
int error = 0 ;
int V_60 ;
int V_11 ;
int V_74 ;
struct V_20 * V_21 = args -> V_21 ;
if ( V_69 ) {
V_66 -> V_75 -= V_21 -> V_76 ;
for ( V_11 = V_21 -> V_76 ; V_11 > 0 ; ) {
V_74 = F_21 ( int , V_71 -> V_77 , V_11 ) ;
V_71 -> V_77 -= V_74 ;
V_71 -> V_78 += V_74 ;
V_71 -> V_79 += V_74 ;
if ( ! V_71 -> V_77 && -- V_66 -> V_80 )
memmove ( & V_71 [ 0 ] , & V_71 [ 1 ] ,
sizeof( V_71 [ 0 ] ) * V_66 -> V_80 ) ;
V_11 -= V_74 ;
}
}
V_66 -> V_81 = F_22 ( V_64 + V_21 -> V_82 , ( 1 << V_21 -> V_83 ) ) - 1 ;
ASSERT ( V_66 -> V_81 >= 0 ) ;
if ( 1 + V_66 -> V_81 > V_66 -> V_75 &&
V_66 -> V_84 < F_23 ( V_21 , V_85 ) ) {
V_66 -> V_86 = V_66 -> V_87 - V_66 -> V_80 ;
error = F_24 ( V_13 , V_66 -> V_84 ,
F_23 ( V_21 , V_85 ) -
V_66 -> V_84 ,
& V_71 [ V_66 -> V_80 ] , & V_66 -> V_86 , 0 ) ;
if ( error )
goto V_88;
if ( V_66 -> V_86 == V_66 -> V_87 - V_66 -> V_80 ) {
V_11 = V_66 -> V_80 + V_66 -> V_86 - 1 ;
V_66 -> V_84 = V_71 [ V_11 ] . V_79 + V_71 [ V_11 ] . V_77 ;
} else
V_66 -> V_84 = F_23 ( V_21 ,
V_85 ) ;
for ( V_11 = V_66 -> V_80 ; V_11 < V_66 -> V_80 + V_66 -> V_86 ; ) {
if ( V_71 [ V_11 ] . V_78 == V_89 ) {
V_66 -> V_86 -- ;
V_60 = V_66 -> V_80 + V_66 -> V_86 - V_11 ;
if ( V_60 )
memmove ( & V_71 [ V_11 ] , & V_71 [ V_11 + 1 ] ,
sizeof( V_71 [ V_11 ] ) * V_60 ) ;
} else {
V_66 -> V_75 += V_71 [ V_11 ] . V_77 ;
V_11 ++ ;
}
}
V_66 -> V_80 += V_66 -> V_86 ;
}
if ( ! V_66 -> V_80 ) {
* V_67 = F_25 ( V_21 , V_66 -> V_84 ) ;
goto V_88;
}
V_66 -> V_90 = F_26 ( V_21 , V_71 -> V_79 ) ;
error = F_27 ( NULL , V_13 , V_71 -> V_79 ,
V_71 -> V_77 >= V_21 -> V_76 ?
F_28 ( V_13 -> V_44 , V_71 -> V_78 ) :
- 1 , & V_47 ) ;
if ( error )
goto V_88;
if ( V_66 -> V_91 )
V_66 -> V_91 -= V_21 -> V_76 ;
F_29 ( & V_73 ) ;
for ( V_66 -> V_92 = V_66 -> V_93 = V_11 = 0 ;
V_66 -> V_81 > V_66 -> V_91 && V_11 < V_66 -> V_75 ;
V_11 += V_21 -> V_76 ) {
ASSERT ( V_66 -> V_92 < V_66 -> V_80 ) ;
if ( V_11 > V_66 -> V_91 &&
V_71 [ V_66 -> V_92 ] . V_77 >= V_21 -> V_76 ) {
F_30 ( V_13 ,
V_71 [ V_66 -> V_92 ] . V_79 + V_66 -> V_93 ,
F_28 ( V_13 -> V_44 ,
V_71 [ V_66 -> V_92 ] . V_78 +
V_66 -> V_93 ) ) ;
V_66 -> V_91 = V_11 ;
}
else if ( V_11 > V_66 -> V_91 ) {
F_30 ( V_13 ,
V_71 [ V_66 -> V_92 ] . V_79 +
V_66 -> V_93 , - 1 ) ;
V_66 -> V_91 = V_11 ;
}
for ( V_74 = 0 ; V_74 < V_21 -> V_76 ; V_74 += V_60 ) {
V_60 = F_21 ( int , V_21 -> V_76 ,
V_71 [ V_66 -> V_92 ] . V_77 -
V_66 -> V_93 ) ;
V_66 -> V_93 += V_60 ;
if ( V_66 -> V_93 == V_71 [ V_66 -> V_92 ] . V_77 ) {
V_66 -> V_93 = 0 ;
V_66 -> V_92 ++ ;
}
}
}
F_31 ( & V_73 ) ;
V_88:
* V_68 = V_47 ;
return error ;
}
STATIC int
F_32 (
struct V_8 * args ,
struct V_9 * V_10 ,
T_11 V_64 )
{
struct V_12 * V_13 = args -> V_13 ;
struct V_46 * V_47 = NULL ;
T_6 * V_45 ;
T_8 * V_49 ;
T_9 * V_50 ;
int error = 0 ;
int V_60 ;
int V_94 ;
T_12 V_67 ;
T_12 V_95 ;
char * V_52 = NULL ;
struct V_65 * V_96 ;
struct V_20 * V_21 = args -> V_21 ;
if ( V_10 -> V_30 >= V_97 )
return 0 ;
V_60 = F_22 ( V_64 + V_21 -> V_82 , ( 1 << V_21 -> V_83 ) ) ;
V_96 = F_33 ( F_34 ( struct V_65 , V_71 ) +
( V_60 * sizeof( struct V_70 ) ) ,
V_98 | V_99 ) ;
V_96 -> V_87 = V_60 ;
V_67 = F_35 ( V_10 -> V_30 ) ;
V_96 -> V_84 = F_36 ( V_21 ,
F_37 ( V_21 , V_67 ) ) ;
while ( V_67 < V_85 ) {
T_1 V_3 ;
if ( ! V_47 || V_52 >= ( char * ) V_47 -> V_56 + V_21 -> V_82 ) {
int V_55 ;
bool V_69 = false ;
if ( V_47 ) {
F_19 ( NULL , V_47 ) ;
V_47 = NULL ;
V_69 = true ;
}
V_55 = F_10 ( V_13 ) ;
error = F_20 ( args , V_64 , V_96 ,
& V_67 , & V_47 , V_69 ) ;
F_12 ( V_13 , V_55 ) ;
if ( error || ! V_96 -> V_80 )
break;
V_95 = F_38 ( V_21 ,
V_96 -> V_90 , 0 ) ;
if ( V_67 < V_95 )
V_67 = V_95 ;
else if ( V_67 > V_95 )
ASSERT ( F_37 ( V_21 , V_67 ) ==
V_96 -> V_90 ) ;
V_45 = V_47 -> V_56 ;
F_14 ( V_13 , V_47 ) ;
V_52 = ( char * ) V_13 -> V_32 -> V_57 ( V_45 ) ;
V_94 = F_39 ( V_21 , V_67 ) ;
if ( V_94 == 0 )
V_67 += V_13 -> V_32 -> V_100 ;
else {
while ( ( char * ) V_52 - ( char * ) V_45 < V_94 ) {
V_50 = ( T_9 * ) V_52 ;
if ( F_17 ( V_50 -> V_58 )
== V_59 ) {
V_60 = F_17 ( V_50 -> V_60 ) ;
V_52 += V_60 ;
continue;
}
V_49 = ( T_8 * ) V_52 ;
V_60 =
V_13 -> V_32 -> V_61 ( V_49 -> V_43 ) ;
V_52 += V_60 ;
}
V_67 =
F_38 ( V_21 ,
F_37 ( V_21 , V_67 ) ,
( char * ) V_52 - ( char * ) V_45 ) ;
if ( V_52 >= ( char * ) V_45 + V_21 -> V_82 ) {
continue;
}
}
}
V_50 = ( T_9 * ) V_52 ;
if ( F_17 ( V_50 -> V_58 ) == V_59 ) {
V_60 = F_17 ( V_50 -> V_60 ) ;
V_52 += V_60 ;
V_67 += V_60 ;
continue;
}
V_49 = ( T_8 * ) V_52 ;
V_60 = V_13 -> V_32 -> V_61 ( V_49 -> V_43 ) ;
V_3 = V_13 -> V_32 -> V_62 ( V_49 ) ;
V_10 -> V_30 = F_40 ( V_67 ) & 0x7fffffff ;
if ( ! F_6 ( V_10 , ( char * ) V_49 -> V_42 , V_49 -> V_43 ,
F_18 ( V_49 -> V_63 ) ,
F_1 ( V_13 -> V_44 , V_3 ) ) )
break;
V_52 += V_60 ;
V_67 += V_60 ;
V_64 = V_64 > V_60 ? V_64 - V_60 : 0 ;
}
if ( V_67 > F_35 ( V_97 ) )
V_10 -> V_30 = V_97 & 0x7fffffff ;
else
V_10 -> V_30 = F_40 ( V_67 ) & 0x7fffffff ;
F_41 ( V_96 ) ;
if ( V_47 )
F_19 ( NULL , V_47 ) ;
return error ;
}
int
F_42 (
struct V_12 * V_13 ,
struct V_9 * V_10 ,
T_11 V_64 )
{
struct V_8 args = { NULL } ;
int V_101 ;
int V_102 ;
F_43 ( V_13 ) ;
if ( F_44 ( V_13 -> V_44 ) )
return - V_103 ;
ASSERT ( F_45 ( F_46 ( V_13 ) -> V_104 ) ) ;
F_47 ( V_13 -> V_44 , V_105 ) ;
args . V_13 = V_13 ;
args . V_21 = V_13 -> V_44 -> V_106 ;
if ( V_13 -> V_26 . V_107 == V_108 )
V_101 = F_3 ( & args , V_10 ) ;
else if ( ( V_101 = F_48 ( & args , & V_102 ) ) )
;
else if ( V_102 )
V_101 = F_9 ( & args , V_10 ) ;
else
V_101 = F_32 ( & args , V_10 , V_64 ) ;
return V_101 ;
}
