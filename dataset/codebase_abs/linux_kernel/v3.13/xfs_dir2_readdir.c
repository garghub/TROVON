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
T_2 * V_8 ,
struct V_9 * V_10 )
{
int V_11 ;
T_3 * V_2 ;
T_4 V_12 ;
T_5 * V_13 ;
T_6 * V_14 ;
T_4 V_15 ;
T_4 V_16 ;
T_7 V_17 ;
V_2 = V_8 -> V_18 ;
ASSERT ( V_8 -> V_19 . V_20 & V_21 ) ;
if ( V_8 -> V_22 . V_23 < F_4 ( T_6 , V_24 ) ) {
ASSERT ( F_5 ( V_2 ) ) ;
return F_6 ( V_25 ) ;
}
ASSERT ( V_8 -> V_19 . V_26 == V_8 -> V_22 . V_23 ) ;
ASSERT ( V_8 -> V_19 . V_27 . V_28 != NULL ) ;
V_14 = ( T_6 * ) V_8 -> V_19 . V_27 . V_28 ;
ASSERT ( V_8 -> V_22 . V_23 >= F_7 ( V_14 -> V_29 ) ) ;
if ( F_8 ( V_2 , V_10 -> V_30 ) > V_2 -> V_31 )
return 0 ;
V_15 = F_9 ( V_2 , V_2 -> V_31 ,
V_8 -> V_32 -> V_33 ) ;
V_16 = F_9 ( V_2 , V_2 -> V_31 ,
V_8 -> V_32 -> V_34 ) ;
if ( V_10 -> V_30 <= V_15 ) {
V_10 -> V_30 = V_15 & 0x7fffffff ;
if ( ! F_10 ( V_10 , L_1 , 1 , V_8 -> V_35 , V_36 ) )
return 0 ;
}
if ( V_10 -> V_30 <= V_16 ) {
V_17 = V_8 -> V_32 -> V_37 ( V_14 ) ;
V_10 -> V_30 = V_16 & 0x7fffffff ;
if ( ! F_10 ( V_10 , L_2 , 2 , V_17 , V_36 ) )
return 0 ;
}
V_13 = F_11 ( V_14 ) ;
for ( V_11 = 0 ; V_11 < V_14 -> V_38 ; V_11 ++ ) {
T_1 V_3 ;
V_12 = F_9 ( V_2 , V_2 -> V_31 ,
F_12 ( V_13 ) ) ;
if ( V_10 -> V_30 > V_12 ) {
V_13 = V_8 -> V_32 -> V_39 ( V_14 , V_13 ) ;
continue;
}
V_17 = V_8 -> V_32 -> V_40 ( V_14 , V_13 ) ;
V_3 = V_8 -> V_32 -> V_41 ( V_13 ) ;
V_10 -> V_30 = V_12 & 0x7fffffff ;
if ( ! F_10 ( V_10 , ( char * ) V_13 -> V_42 , V_13 -> V_43 , V_17 ,
F_1 ( V_2 , V_3 ) ) )
return 0 ;
V_13 = V_8 -> V_32 -> V_39 ( V_14 , V_13 ) ;
}
V_10 -> V_30 = F_9 ( V_2 , V_2 -> V_31 + 1 , 0 ) &
0x7fffffff ;
return 0 ;
}
STATIC int
F_13 (
T_2 * V_8 ,
struct V_9 * V_10 )
{
T_8 * V_44 ;
struct V_45 * V_46 ;
T_9 * V_47 ;
T_10 * V_48 ;
T_11 * V_49 ;
char * V_50 ;
int error ;
T_3 * V_2 ;
char * V_51 ;
int V_52 ;
T_12 V_53 ;
V_2 = V_8 -> V_18 ;
if ( F_8 ( V_2 , V_10 -> V_30 ) > V_2 -> V_31 )
return 0 ;
error = F_14 ( NULL , V_8 , & V_46 ) ;
if ( error )
return error ;
V_52 = F_15 ( V_2 , V_10 -> V_30 ) ;
V_44 = V_46 -> V_54 ;
F_16 ( V_8 , V_46 ) ;
V_47 = F_17 ( V_2 , V_44 ) ;
V_51 = ( char * ) V_8 -> V_32 -> V_55 ( V_44 ) ;
V_50 = ( char * ) F_18 ( V_47 ) ;
while ( V_51 < V_50 ) {
T_1 V_3 ;
V_49 = ( T_11 * ) V_51 ;
if ( F_19 ( V_49 -> V_56 ) == V_57 ) {
V_51 += F_19 ( V_49 -> V_58 ) ;
continue;
}
V_48 = ( T_10 * ) V_51 ;
V_51 += V_8 -> V_32 -> V_59 ( V_48 -> V_43 ) ;
if ( ( char * ) V_48 - ( char * ) V_44 < V_52 )
continue;
V_53 = F_9 ( V_2 , V_2 -> V_31 ,
( char * ) V_48 - ( char * ) V_44 ) ;
V_10 -> V_30 = V_53 & 0x7fffffff ;
V_3 = V_8 -> V_32 -> V_60 ( V_48 ) ;
if ( ! F_10 ( V_10 , ( char * ) V_48 -> V_42 , V_48 -> V_43 ,
F_20 ( V_48 -> V_61 ) ,
F_1 ( V_2 , V_3 ) ) ) {
F_21 ( NULL , V_46 ) ;
return 0 ;
}
}
V_10 -> V_30 = F_9 ( V_2 , V_2 -> V_31 + 1 , 0 ) &
0x7fffffff ;
F_21 ( NULL , V_46 ) ;
return 0 ;
}
STATIC int
F_22 (
struct V_62 * V_8 ,
T_13 V_63 ,
struct V_64 * V_65 ,
T_14 * V_66 ,
struct V_45 * * V_67 )
{
struct V_1 * V_2 = V_8 -> V_18 ;
struct V_45 * V_46 = * V_67 ;
struct V_68 * V_69 = V_65 -> V_69 ;
struct V_70 V_71 ;
int error = 0 ;
int V_58 ;
int V_11 ;
int V_72 ;
if ( V_46 ) {
F_21 ( NULL , V_46 ) ;
V_46 = NULL ;
V_65 -> V_73 -= V_2 -> V_74 ;
for ( V_11 = V_2 -> V_74 ; V_11 > 0 ; ) {
V_72 = F_23 ( int , V_69 -> V_75 , V_11 ) ;
V_69 -> V_75 -= V_72 ;
V_69 -> V_76 += V_72 ;
V_69 -> V_77 += V_72 ;
if ( ! V_69 -> V_75 && -- V_65 -> V_78 )
memmove ( & V_69 [ 0 ] , & V_69 [ 1 ] ,
sizeof( V_69 [ 0 ] ) * V_65 -> V_78 ) ;
V_11 -= V_72 ;
}
}
V_65 -> V_79 = F_24 ( V_63 + V_2 -> V_80 ,
V_2 -> V_4 . V_81 ) - 1 ;
ASSERT ( V_65 -> V_79 >= 0 ) ;
if ( 1 + V_65 -> V_79 > V_65 -> V_73 &&
V_65 -> V_82 < F_25 ( V_2 , V_83 ) ) {
V_65 -> V_84 = V_65 -> V_85 - V_65 -> V_78 ;
error = F_26 ( V_8 , V_65 -> V_82 ,
F_25 ( V_2 , V_83 ) -
V_65 -> V_82 ,
& V_69 [ V_65 -> V_78 ] , & V_65 -> V_84 , 0 ) ;
if ( error )
goto V_86;
if ( V_65 -> V_84 == V_65 -> V_85 - V_65 -> V_78 ) {
V_11 = V_65 -> V_78 + V_65 -> V_84 - 1 ;
V_65 -> V_82 = V_69 [ V_11 ] . V_77 + V_69 [ V_11 ] . V_75 ;
} else
V_65 -> V_82 = F_25 ( V_2 ,
V_83 ) ;
for ( V_11 = V_65 -> V_78 ; V_11 < V_65 -> V_78 + V_65 -> V_84 ; ) {
if ( V_69 [ V_11 ] . V_76 == V_87 ) {
V_65 -> V_84 -- ;
V_58 = V_65 -> V_78 + V_65 -> V_84 - V_11 ;
if ( V_58 )
memmove ( & V_69 [ V_11 ] , & V_69 [ V_11 + 1 ] ,
sizeof( V_69 [ V_11 ] ) * V_58 ) ;
} else {
V_65 -> V_73 += V_69 [ V_11 ] . V_75 ;
V_11 ++ ;
}
}
V_65 -> V_78 += V_65 -> V_84 ;
}
if ( ! V_65 -> V_78 ) {
* V_66 = F_27 ( V_2 , V_65 -> V_82 ) ;
goto V_86;
}
V_65 -> V_88 = F_28 ( V_2 , V_69 -> V_77 ) ;
error = F_29 ( NULL , V_8 , V_69 -> V_77 ,
V_69 -> V_75 >= V_2 -> V_74 ?
F_30 ( V_2 , V_69 -> V_76 ) : - 1 , & V_46 ) ;
if ( error )
goto V_86;
if ( V_65 -> V_89 )
V_65 -> V_89 -= V_2 -> V_74 ;
F_31 ( & V_71 ) ;
for ( V_65 -> V_90 = V_65 -> V_91 = V_11 = 0 ;
V_65 -> V_79 > V_65 -> V_89 && V_11 < V_65 -> V_73 ;
V_11 += V_2 -> V_74 ) {
ASSERT ( V_65 -> V_90 < V_65 -> V_78 ) ;
if ( V_11 > V_65 -> V_89 &&
V_69 [ V_65 -> V_90 ] . V_75 >= V_2 -> V_74 ) {
F_32 ( NULL , V_8 ,
V_69 [ V_65 -> V_90 ] . V_77 + V_65 -> V_91 ,
F_30 ( V_2 ,
V_69 [ V_65 -> V_90 ] . V_76 +
V_65 -> V_91 ) ) ;
V_65 -> V_89 = V_11 ;
}
else if ( V_11 > V_65 -> V_89 ) {
F_32 ( NULL , V_8 ,
V_69 [ V_65 -> V_90 ] . V_77 +
V_65 -> V_91 , - 1 ) ;
V_65 -> V_89 = V_11 ;
}
for ( V_72 = 0 ; V_72 < V_2 -> V_74 ; V_72 ++ ) {
V_58 = F_23 ( int , V_2 -> V_74 ,
V_69 [ V_65 -> V_90 ] . V_75 -
V_65 -> V_91 ) ;
V_72 += V_58 ;
V_65 -> V_91 += V_58 ;
if ( V_65 -> V_91 == V_69 [ V_65 -> V_90 ] . V_75 ) {
V_65 -> V_91 = 0 ;
V_65 -> V_90 ++ ;
}
}
}
F_33 ( & V_71 ) ;
V_86:
* V_67 = V_46 ;
return error ;
}
STATIC int
F_34 (
T_2 * V_8 ,
struct V_9 * V_10 ,
T_13 V_63 )
{
struct V_45 * V_46 = NULL ;
T_8 * V_44 ;
T_10 * V_48 ;
T_11 * V_49 ;
int error = 0 ;
int V_58 ;
T_3 * V_2 ;
int V_92 ;
T_14 V_66 ;
T_14 V_93 ;
char * V_51 = NULL ;
struct V_64 * V_94 ;
if ( V_10 -> V_30 >= V_95 )
return 0 ;
V_2 = V_8 -> V_18 ;
V_58 = F_24 ( V_63 + V_2 -> V_80 ,
V_2 -> V_4 . V_81 ) ;
V_94 = F_35 ( F_4 ( struct V_64 , V_69 ) +
( V_58 * sizeof( struct V_68 ) ) ,
V_96 | V_97 ) ;
V_94 -> V_85 = V_58 ;
V_66 = F_36 ( V_2 , V_10 -> V_30 ) ;
V_94 -> V_82 = F_37 ( V_2 ,
F_38 ( V_2 , V_66 ) ) ;
while ( V_66 < V_83 ) {
T_1 V_3 ;
if ( ! V_46 || V_51 >= ( char * ) V_46 -> V_54 + V_2 -> V_80 ) {
error = F_22 ( V_8 , V_63 , V_94 ,
& V_66 , & V_46 ) ;
if ( error || ! V_94 -> V_78 )
break;
V_93 = F_39 ( V_2 , V_94 -> V_88 , 0 ) ;
if ( V_66 < V_93 )
V_66 = V_93 ;
else if ( V_66 > V_93 )
ASSERT ( F_38 ( V_2 , V_66 ) ==
V_94 -> V_88 ) ;
V_44 = V_46 -> V_54 ;
F_16 ( V_8 , V_46 ) ;
V_51 = ( char * ) V_8 -> V_32 -> V_55 ( V_44 ) ;
V_92 = F_40 ( V_2 , V_66 ) ;
if ( V_92 == 0 )
V_66 += V_8 -> V_32 -> V_98 ;
else {
while ( ( char * ) V_51 - ( char * ) V_44 < V_92 ) {
V_49 = ( T_11 * ) V_51 ;
if ( F_19 ( V_49 -> V_56 )
== V_57 ) {
V_58 = F_19 ( V_49 -> V_58 ) ;
V_51 += V_58 ;
continue;
}
V_48 = ( T_10 * ) V_51 ;
V_58 =
V_8 -> V_32 -> V_59 ( V_48 -> V_43 ) ;
V_51 += V_58 ;
}
V_66 =
F_39 ( V_2 ,
F_38 ( V_2 , V_66 ) ,
( char * ) V_51 - ( char * ) V_44 ) ;
if ( V_51 >= ( char * ) V_44 + V_2 -> V_80 ) {
continue;
}
}
}
V_49 = ( T_11 * ) V_51 ;
if ( F_19 ( V_49 -> V_56 ) == V_57 ) {
V_58 = F_19 ( V_49 -> V_58 ) ;
V_51 += V_58 ;
V_66 += V_58 ;
continue;
}
V_48 = ( T_10 * ) V_51 ;
V_58 = V_8 -> V_32 -> V_59 ( V_48 -> V_43 ) ;
V_3 = V_8 -> V_32 -> V_60 ( V_48 ) ;
V_10 -> V_30 = F_41 ( V_2 , V_66 ) & 0x7fffffff ;
if ( ! F_10 ( V_10 , ( char * ) V_48 -> V_42 , V_48 -> V_43 ,
F_20 ( V_48 -> V_61 ) ,
F_1 ( V_2 , V_3 ) ) )
break;
V_51 += V_58 ;
V_66 += V_58 ;
V_63 = V_63 > V_58 ? V_63 - V_58 : 0 ;
}
if ( V_66 > F_36 ( V_2 , V_95 ) )
V_10 -> V_30 = V_95 & 0x7fffffff ;
else
V_10 -> V_30 = F_41 ( V_2 , V_66 ) & 0x7fffffff ;
F_42 ( V_94 ) ;
if ( V_46 )
F_21 ( NULL , V_46 ) ;
return error ;
}
int
F_43 (
T_2 * V_8 ,
struct V_9 * V_10 ,
T_13 V_63 )
{
int V_99 ;
int V_100 ;
F_44 ( V_8 ) ;
if ( F_5 ( V_8 -> V_18 ) )
return F_6 ( V_25 ) ;
ASSERT ( F_45 ( V_8 -> V_22 . V_101 ) ) ;
F_46 ( V_102 ) ;
if ( V_8 -> V_22 . V_103 == V_104 )
V_99 = F_3 ( V_8 , V_10 ) ;
else if ( ( V_99 = F_47 ( NULL , V_8 , & V_100 ) ) )
;
else if ( V_100 )
V_99 = F_13 ( V_8 , V_10 ) ;
else
V_99 = F_34 ( V_8 , V_10 , V_63 ) ;
return V_99 ;
}
