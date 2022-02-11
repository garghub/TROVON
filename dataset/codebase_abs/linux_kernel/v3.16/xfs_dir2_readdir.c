unsigned char
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
return F_6 ( V_29 ) ;
}
ASSERT ( V_13 -> V_22 . V_30 == V_13 -> V_25 . V_26 ) ;
ASSERT ( V_13 -> V_22 . V_31 . V_32 != NULL ) ;
V_16 = ( T_4 * ) V_13 -> V_22 . V_31 . V_32 ;
ASSERT ( V_13 -> V_25 . V_26 >= F_7 ( V_16 -> V_33 ) ) ;
if ( F_8 ( V_21 , V_10 -> V_34 ) > V_21 -> V_35 )
return 0 ;
V_17 = F_9 ( V_21 , V_21 -> V_35 ,
V_13 -> V_36 -> V_37 ) ;
V_18 = F_9 ( V_21 , V_21 -> V_35 ,
V_13 -> V_36 -> V_38 ) ;
if ( V_10 -> V_34 <= V_17 ) {
V_10 -> V_34 = V_17 & 0x7fffffff ;
if ( ! F_10 ( V_10 , L_1 , 1 , V_13 -> V_39 , V_40 ) )
return 0 ;
}
if ( V_10 -> V_34 <= V_18 ) {
V_19 = V_13 -> V_36 -> V_41 ( V_16 ) ;
V_10 -> V_34 = V_18 & 0x7fffffff ;
if ( ! F_10 ( V_10 , L_2 , 2 , V_19 , V_40 ) )
return 0 ;
}
V_15 = F_11 ( V_16 ) ;
for ( V_11 = 0 ; V_11 < V_16 -> V_42 ; V_11 ++ ) {
T_1 V_3 ;
V_14 = F_9 ( V_21 , V_21 -> V_35 ,
F_12 ( V_15 ) ) ;
if ( V_10 -> V_34 > V_14 ) {
V_15 = V_13 -> V_36 -> V_43 ( V_16 , V_15 ) ;
continue;
}
V_19 = V_13 -> V_36 -> V_44 ( V_16 , V_15 ) ;
V_3 = V_13 -> V_36 -> V_45 ( V_15 ) ;
V_10 -> V_34 = V_14 & 0x7fffffff ;
if ( ! F_10 ( V_10 , ( char * ) V_15 -> V_46 , V_15 -> V_47 , V_19 ,
F_1 ( V_13 -> V_28 , V_3 ) ) )
return 0 ;
V_15 = V_13 -> V_36 -> V_43 ( V_16 , V_15 ) ;
}
V_10 -> V_34 = F_9 ( V_21 , V_21 -> V_35 + 1 , 0 ) &
0x7fffffff ;
return 0 ;
}
STATIC int
F_13 (
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
if ( F_8 ( V_21 , V_10 -> V_34 ) > V_21 -> V_35 )
return 0 ;
error = F_14 ( NULL , V_13 , & V_50 ) ;
if ( error )
return error ;
V_56 = F_15 ( V_21 , V_10 -> V_34 ) ;
V_48 = V_50 -> V_58 ;
F_16 ( V_13 , V_50 ) ;
V_51 = F_17 ( V_21 , V_48 ) ;
V_55 = ( char * ) V_13 -> V_36 -> V_59 ( V_48 ) ;
V_54 = ( char * ) F_18 ( V_51 ) ;
while ( V_55 < V_54 ) {
T_1 V_3 ;
V_53 = ( T_9 * ) V_55 ;
if ( F_19 ( V_53 -> V_60 ) == V_61 ) {
V_55 += F_19 ( V_53 -> V_62 ) ;
continue;
}
V_52 = ( T_8 * ) V_55 ;
V_55 += V_13 -> V_36 -> V_63 ( V_52 -> V_47 ) ;
if ( ( char * ) V_52 - ( char * ) V_48 < V_56 )
continue;
V_57 = F_9 ( V_21 , V_21 -> V_35 ,
( char * ) V_52 - ( char * ) V_48 ) ;
V_10 -> V_34 = V_57 & 0x7fffffff ;
V_3 = V_13 -> V_36 -> V_64 ( V_52 ) ;
if ( ! F_10 ( V_10 , ( char * ) V_52 -> V_46 , V_52 -> V_47 ,
F_20 ( V_52 -> V_65 ) ,
F_1 ( V_13 -> V_28 , V_3 ) ) ) {
F_21 ( NULL , V_50 ) ;
return 0 ;
}
}
V_10 -> V_34 = F_9 ( V_21 , V_21 -> V_35 + 1 , 0 ) &
0x7fffffff ;
F_21 ( NULL , V_50 ) ;
return 0 ;
}
STATIC int
F_22 (
struct V_8 * args ,
T_11 V_66 ,
struct V_67 * V_68 ,
T_12 * V_69 ,
struct V_49 * * V_70 )
{
struct V_12 * V_13 = args -> V_13 ;
struct V_49 * V_50 = * V_70 ;
struct V_71 * V_72 = V_68 -> V_72 ;
struct V_73 V_74 ;
int error = 0 ;
int V_62 ;
int V_11 ;
int V_75 ;
struct V_20 * V_21 = args -> V_21 ;
if ( V_50 ) {
F_21 ( NULL , V_50 ) ;
V_50 = NULL ;
V_68 -> V_76 -= V_21 -> V_77 ;
for ( V_11 = V_21 -> V_77 ; V_11 > 0 ; ) {
V_75 = F_23 ( int , V_72 -> V_78 , V_11 ) ;
V_72 -> V_78 -= V_75 ;
V_72 -> V_79 += V_75 ;
V_72 -> V_80 += V_75 ;
if ( ! V_72 -> V_78 && -- V_68 -> V_81 )
memmove ( & V_72 [ 0 ] , & V_72 [ 1 ] ,
sizeof( V_72 [ 0 ] ) * V_68 -> V_81 ) ;
V_11 -= V_75 ;
}
}
V_68 -> V_82 = F_24 ( V_66 + V_21 -> V_83 , ( 1 << V_21 -> V_84 ) ) - 1 ;
ASSERT ( V_68 -> V_82 >= 0 ) ;
if ( 1 + V_68 -> V_82 > V_68 -> V_76 &&
V_68 -> V_85 < F_25 ( V_21 , V_86 ) ) {
V_68 -> V_87 = V_68 -> V_88 - V_68 -> V_81 ;
error = F_26 ( V_13 , V_68 -> V_85 ,
F_25 ( V_21 , V_86 ) -
V_68 -> V_85 ,
& V_72 [ V_68 -> V_81 ] , & V_68 -> V_87 , 0 ) ;
if ( error )
goto V_89;
if ( V_68 -> V_87 == V_68 -> V_88 - V_68 -> V_81 ) {
V_11 = V_68 -> V_81 + V_68 -> V_87 - 1 ;
V_68 -> V_85 = V_72 [ V_11 ] . V_80 + V_72 [ V_11 ] . V_78 ;
} else
V_68 -> V_85 = F_25 ( V_21 ,
V_86 ) ;
for ( V_11 = V_68 -> V_81 ; V_11 < V_68 -> V_81 + V_68 -> V_87 ; ) {
if ( V_72 [ V_11 ] . V_79 == V_90 ) {
V_68 -> V_87 -- ;
V_62 = V_68 -> V_81 + V_68 -> V_87 - V_11 ;
if ( V_62 )
memmove ( & V_72 [ V_11 ] , & V_72 [ V_11 + 1 ] ,
sizeof( V_72 [ V_11 ] ) * V_62 ) ;
} else {
V_68 -> V_76 += V_72 [ V_11 ] . V_78 ;
V_11 ++ ;
}
}
V_68 -> V_81 += V_68 -> V_87 ;
}
if ( ! V_68 -> V_81 ) {
* V_69 = F_27 ( V_21 , V_68 -> V_85 ) ;
goto V_89;
}
V_68 -> V_91 = F_28 ( V_21 , V_72 -> V_80 ) ;
error = F_29 ( NULL , V_13 , V_72 -> V_80 ,
V_72 -> V_78 >= V_21 -> V_77 ?
F_30 ( V_13 -> V_28 , V_72 -> V_79 ) :
- 1 , & V_50 ) ;
if ( error )
goto V_89;
if ( V_68 -> V_92 )
V_68 -> V_92 -= V_21 -> V_77 ;
F_31 ( & V_74 ) ;
for ( V_68 -> V_93 = V_68 -> V_94 = V_11 = 0 ;
V_68 -> V_82 > V_68 -> V_92 && V_11 < V_68 -> V_76 ;
V_11 += V_21 -> V_77 ) {
ASSERT ( V_68 -> V_93 < V_68 -> V_81 ) ;
if ( V_11 > V_68 -> V_92 &&
V_72 [ V_68 -> V_93 ] . V_78 >= V_21 -> V_77 ) {
F_32 ( V_13 ,
V_72 [ V_68 -> V_93 ] . V_80 + V_68 -> V_94 ,
F_30 ( V_13 -> V_28 ,
V_72 [ V_68 -> V_93 ] . V_79 +
V_68 -> V_94 ) ) ;
V_68 -> V_92 = V_11 ;
}
else if ( V_11 > V_68 -> V_92 ) {
F_32 ( V_13 ,
V_72 [ V_68 -> V_93 ] . V_80 +
V_68 -> V_94 , - 1 ) ;
V_68 -> V_92 = V_11 ;
}
for ( V_75 = 0 ; V_75 < V_21 -> V_77 ; V_75 += V_62 ) {
V_62 = F_23 ( int , V_21 -> V_77 ,
V_72 [ V_68 -> V_93 ] . V_78 -
V_68 -> V_94 ) ;
V_68 -> V_94 += V_62 ;
if ( V_68 -> V_94 == V_72 [ V_68 -> V_93 ] . V_78 ) {
V_68 -> V_94 = 0 ;
V_68 -> V_93 ++ ;
}
}
}
F_33 ( & V_74 ) ;
V_89:
* V_70 = V_50 ;
return error ;
}
STATIC int
F_34 (
struct V_8 * args ,
struct V_9 * V_10 ,
T_11 V_66 )
{
struct V_12 * V_13 = args -> V_13 ;
struct V_49 * V_50 = NULL ;
T_6 * V_48 ;
T_8 * V_52 ;
T_9 * V_53 ;
int error = 0 ;
int V_62 ;
int V_95 ;
T_12 V_69 ;
T_12 V_96 ;
char * V_55 = NULL ;
struct V_67 * V_97 ;
struct V_20 * V_21 = args -> V_21 ;
if ( V_10 -> V_34 >= V_98 )
return 0 ;
V_62 = F_24 ( V_66 + V_21 -> V_83 , ( 1 << V_21 -> V_84 ) ) ;
V_97 = F_35 ( F_4 ( struct V_67 , V_72 ) +
( V_62 * sizeof( struct V_71 ) ) ,
V_99 | V_100 ) ;
V_97 -> V_88 = V_62 ;
V_69 = F_36 ( V_10 -> V_34 ) ;
V_97 -> V_85 = F_37 ( V_21 ,
F_38 ( V_21 , V_69 ) ) ;
while ( V_69 < V_86 ) {
T_1 V_3 ;
if ( ! V_50 || V_55 >= ( char * ) V_50 -> V_58 + V_21 -> V_83 ) {
error = F_22 ( args , V_66 , V_97 ,
& V_69 , & V_50 ) ;
if ( error || ! V_97 -> V_81 )
break;
V_96 = F_39 ( V_21 ,
V_97 -> V_91 , 0 ) ;
if ( V_69 < V_96 )
V_69 = V_96 ;
else if ( V_69 > V_96 )
ASSERT ( F_38 ( V_21 , V_69 ) ==
V_97 -> V_91 ) ;
V_48 = V_50 -> V_58 ;
F_16 ( V_13 , V_50 ) ;
V_55 = ( char * ) V_13 -> V_36 -> V_59 ( V_48 ) ;
V_95 = F_40 ( V_21 , V_69 ) ;
if ( V_95 == 0 )
V_69 += V_13 -> V_36 -> V_101 ;
else {
while ( ( char * ) V_55 - ( char * ) V_48 < V_95 ) {
V_53 = ( T_9 * ) V_55 ;
if ( F_19 ( V_53 -> V_60 )
== V_61 ) {
V_62 = F_19 ( V_53 -> V_62 ) ;
V_55 += V_62 ;
continue;
}
V_52 = ( T_8 * ) V_55 ;
V_62 =
V_13 -> V_36 -> V_63 ( V_52 -> V_47 ) ;
V_55 += V_62 ;
}
V_69 =
F_39 ( V_21 ,
F_38 ( V_21 , V_69 ) ,
( char * ) V_55 - ( char * ) V_48 ) ;
if ( V_55 >= ( char * ) V_48 + V_21 -> V_83 ) {
continue;
}
}
}
V_53 = ( T_9 * ) V_55 ;
if ( F_19 ( V_53 -> V_60 ) == V_61 ) {
V_62 = F_19 ( V_53 -> V_62 ) ;
V_55 += V_62 ;
V_69 += V_62 ;
continue;
}
V_52 = ( T_8 * ) V_55 ;
V_62 = V_13 -> V_36 -> V_63 ( V_52 -> V_47 ) ;
V_3 = V_13 -> V_36 -> V_64 ( V_52 ) ;
V_10 -> V_34 = F_41 ( V_69 ) & 0x7fffffff ;
if ( ! F_10 ( V_10 , ( char * ) V_52 -> V_46 , V_52 -> V_47 ,
F_20 ( V_52 -> V_65 ) ,
F_1 ( V_13 -> V_28 , V_3 ) ) )
break;
V_55 += V_62 ;
V_69 += V_62 ;
V_66 = V_66 > V_62 ? V_66 - V_62 : 0 ;
}
if ( V_69 > F_36 ( V_98 ) )
V_10 -> V_34 = V_98 & 0x7fffffff ;
else
V_10 -> V_34 = F_41 ( V_69 ) & 0x7fffffff ;
F_42 ( V_97 ) ;
if ( V_50 )
F_21 ( NULL , V_50 ) ;
return error ;
}
int
F_43 (
struct V_12 * V_13 ,
struct V_9 * V_10 ,
T_11 V_66 )
{
struct V_8 args = { NULL } ;
int V_102 ;
int V_103 ;
T_13 V_104 ;
F_44 ( V_13 ) ;
if ( F_5 ( V_13 -> V_28 ) )
return F_6 ( V_29 ) ;
ASSERT ( F_45 ( V_13 -> V_25 . V_105 ) ) ;
F_46 ( V_106 ) ;
args . V_13 = V_13 ;
args . V_21 = V_13 -> V_28 -> V_107 ;
V_104 = F_47 ( V_13 ) ;
if ( V_13 -> V_25 . V_108 == V_109 )
V_102 = F_3 ( & args , V_10 ) ;
else if ( ( V_102 = F_48 ( & args , & V_103 ) ) )
;
else if ( V_103 )
V_102 = F_13 ( & args , V_10 ) ;
else
V_102 = F_34 ( & args , V_10 , V_66 ) ;
F_49 ( V_13 , V_104 ) ;
return V_102 ;
}
