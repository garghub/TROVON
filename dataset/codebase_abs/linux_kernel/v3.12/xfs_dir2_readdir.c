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
F_10 ( V_2 ) ) ;
V_16 = F_9 ( V_2 , V_2 -> V_31 ,
F_11 ( V_2 ) ) ;
if ( V_10 -> V_30 <= V_15 ) {
V_10 -> V_30 = V_15 & 0x7fffffff ;
if ( ! F_12 ( V_10 , L_1 , 1 , V_8 -> V_32 , V_33 ) )
return 0 ;
}
if ( V_10 -> V_30 <= V_16 ) {
V_17 = F_13 ( V_14 ) ;
V_10 -> V_30 = V_16 & 0x7fffffff ;
if ( ! F_12 ( V_10 , L_2 , 2 , V_17 , V_33 ) )
return 0 ;
}
V_13 = F_14 ( V_14 ) ;
for ( V_11 = 0 ; V_11 < V_14 -> V_34 ; V_11 ++ ) {
T_1 V_3 ;
V_12 = F_9 ( V_2 , V_2 -> V_31 ,
F_15 ( V_13 ) ) ;
if ( V_10 -> V_30 > V_12 ) {
V_13 = F_16 ( V_2 , V_14 , V_13 ) ;
continue;
}
V_17 = F_17 ( V_2 , V_14 , V_13 ) ;
V_3 = F_18 ( V_2 , V_14 , V_13 ) ;
V_10 -> V_30 = V_12 & 0x7fffffff ;
if ( ! F_12 ( V_10 , ( char * ) V_13 -> V_35 , V_13 -> V_36 , V_17 ,
F_1 ( V_2 , V_3 ) ) )
return 0 ;
V_13 = F_16 ( V_2 , V_14 , V_13 ) ;
}
V_10 -> V_30 = F_9 ( V_2 , V_2 -> V_31 + 1 , 0 ) &
0x7fffffff ;
return 0 ;
}
STATIC int
F_19 (
T_2 * V_8 ,
struct V_9 * V_10 )
{
T_8 * V_37 ;
struct V_38 * V_39 ;
T_9 * V_40 ;
T_10 * V_41 ;
T_11 * V_42 ;
char * V_43 ;
int error ;
T_3 * V_2 ;
char * V_44 ;
int V_45 ;
T_12 V_46 ;
V_2 = V_8 -> V_18 ;
if ( F_8 ( V_2 , V_10 -> V_30 ) > V_2 -> V_31 )
return 0 ;
error = F_20 ( NULL , V_8 , & V_39 ) ;
if ( error )
return error ;
V_45 = F_21 ( V_2 , V_10 -> V_30 ) ;
V_37 = V_39 -> V_47 ;
F_22 ( V_8 , V_39 ) ;
V_40 = F_23 ( V_2 , V_37 ) ;
V_44 = ( char * ) F_24 ( V_37 ) ;
V_43 = ( char * ) F_25 ( V_40 ) ;
while ( V_44 < V_43 ) {
T_1 V_3 ;
V_42 = ( T_11 * ) V_44 ;
if ( F_26 ( V_42 -> V_48 ) == V_49 ) {
V_44 += F_26 ( V_42 -> V_50 ) ;
continue;
}
V_41 = ( T_10 * ) V_44 ;
V_44 += F_27 ( V_2 , V_41 -> V_36 ) ;
if ( ( char * ) V_41 - ( char * ) V_37 < V_45 )
continue;
V_46 = F_9 ( V_2 , V_2 -> V_31 ,
( char * ) V_41 - ( char * ) V_37 ) ;
V_10 -> V_30 = V_46 & 0x7fffffff ;
V_3 = F_28 ( V_2 , V_41 ) ;
if ( ! F_12 ( V_10 , ( char * ) V_41 -> V_35 , V_41 -> V_36 ,
F_29 ( V_41 -> V_51 ) ,
F_1 ( V_2 , V_3 ) ) ) {
F_30 ( NULL , V_39 ) ;
return 0 ;
}
}
V_10 -> V_30 = F_9 ( V_2 , V_2 -> V_31 + 1 , 0 ) &
0x7fffffff ;
F_30 ( NULL , V_39 ) ;
return 0 ;
}
STATIC int
F_31 (
struct V_52 * V_8 ,
T_13 V_53 ,
struct V_54 * V_55 ,
T_14 * V_56 ,
struct V_38 * * V_57 )
{
struct V_1 * V_2 = V_8 -> V_18 ;
struct V_38 * V_39 = * V_57 ;
struct V_58 * V_59 = V_55 -> V_59 ;
struct V_60 V_61 ;
int error = 0 ;
int V_50 ;
int V_11 ;
int V_62 ;
if ( V_39 ) {
F_30 ( NULL , V_39 ) ;
V_39 = NULL ;
V_55 -> V_63 -= V_2 -> V_64 ;
for ( V_11 = V_2 -> V_64 ; V_11 > 0 ; ) {
V_62 = F_32 ( int , V_59 -> V_65 , V_11 ) ;
V_59 -> V_65 -= V_62 ;
V_59 -> V_66 += V_62 ;
V_59 -> V_67 += V_62 ;
if ( ! V_59 -> V_65 && -- V_55 -> V_68 )
memmove ( & V_59 [ 0 ] , & V_59 [ 1 ] ,
sizeof( V_59 [ 0 ] ) * V_55 -> V_68 ) ;
V_11 -= V_62 ;
}
}
V_55 -> V_69 = F_33 ( V_53 + V_2 -> V_70 ,
V_2 -> V_4 . V_71 ) - 1 ;
ASSERT ( V_55 -> V_69 >= 0 ) ;
if ( 1 + V_55 -> V_69 > V_55 -> V_63 &&
V_55 -> V_72 < F_34 ( V_2 , V_73 ) ) {
V_55 -> V_74 = V_55 -> V_75 - V_55 -> V_68 ;
error = F_35 ( V_8 , V_55 -> V_72 ,
F_34 ( V_2 , V_73 ) -
V_55 -> V_72 ,
& V_59 [ V_55 -> V_68 ] , & V_55 -> V_74 , 0 ) ;
if ( error )
goto V_76;
if ( V_55 -> V_74 == V_55 -> V_75 - V_55 -> V_68 ) {
V_11 = V_55 -> V_68 + V_55 -> V_74 - 1 ;
V_55 -> V_72 = V_59 [ V_11 ] . V_67 + V_59 [ V_11 ] . V_65 ;
} else
V_55 -> V_72 = F_34 ( V_2 ,
V_73 ) ;
for ( V_11 = V_55 -> V_68 ; V_11 < V_55 -> V_68 + V_55 -> V_74 ; ) {
if ( V_59 [ V_11 ] . V_66 == V_77 ) {
V_55 -> V_74 -- ;
V_50 = V_55 -> V_68 + V_55 -> V_74 - V_11 ;
if ( V_50 )
memmove ( & V_59 [ V_11 ] , & V_59 [ V_11 + 1 ] ,
sizeof( V_59 [ V_11 ] ) * V_50 ) ;
} else {
V_55 -> V_63 += V_59 [ V_11 ] . V_65 ;
V_11 ++ ;
}
}
V_55 -> V_68 += V_55 -> V_74 ;
}
if ( ! V_55 -> V_68 ) {
* V_56 = F_36 ( V_2 , V_55 -> V_72 ) ;
goto V_76;
}
V_55 -> V_78 = F_37 ( V_2 , V_59 -> V_67 ) ;
error = F_38 ( NULL , V_8 , V_59 -> V_67 ,
V_59 -> V_65 >= V_2 -> V_64 ?
F_39 ( V_2 , V_59 -> V_66 ) : - 1 , & V_39 ) ;
if ( error )
goto V_76;
if ( V_55 -> V_79 )
V_55 -> V_79 -= V_2 -> V_64 ;
F_40 ( & V_61 ) ;
for ( V_55 -> V_80 = V_55 -> V_81 = V_11 = 0 ;
V_55 -> V_69 > V_55 -> V_79 && V_11 < V_55 -> V_63 ;
V_11 += V_2 -> V_64 ) {
ASSERT ( V_55 -> V_80 < V_55 -> V_68 ) ;
if ( V_11 > V_55 -> V_79 &&
V_59 [ V_55 -> V_80 ] . V_65 >= V_2 -> V_64 ) {
F_41 ( NULL , V_8 ,
V_59 [ V_55 -> V_80 ] . V_67 + V_55 -> V_81 ,
F_39 ( V_2 ,
V_59 [ V_55 -> V_80 ] . V_66 +
V_55 -> V_81 ) ) ;
V_55 -> V_79 = V_11 ;
}
else if ( V_11 > V_55 -> V_79 ) {
F_41 ( NULL , V_8 ,
V_59 [ V_55 -> V_80 ] . V_67 +
V_55 -> V_81 , - 1 ) ;
V_55 -> V_79 = V_11 ;
}
for ( V_62 = 0 ; V_62 < V_2 -> V_64 ; V_62 ++ ) {
V_50 = F_32 ( int , V_2 -> V_64 ,
V_59 [ V_55 -> V_80 ] . V_65 -
V_55 -> V_81 ) ;
V_62 += V_50 ;
V_55 -> V_81 += V_50 ;
if ( V_55 -> V_81 == V_59 [ V_55 -> V_80 ] . V_65 ) {
V_55 -> V_81 = 0 ;
V_55 -> V_80 ++ ;
}
}
}
F_42 ( & V_61 ) ;
V_76:
* V_57 = V_39 ;
return error ;
}
STATIC int
F_43 (
T_2 * V_8 ,
struct V_9 * V_10 ,
T_13 V_53 )
{
struct V_38 * V_39 = NULL ;
T_8 * V_37 ;
T_10 * V_41 ;
T_11 * V_42 ;
int error = 0 ;
int V_50 ;
T_3 * V_2 ;
int V_82 ;
T_14 V_56 ;
T_14 V_83 ;
char * V_44 = NULL ;
struct V_54 * V_84 ;
if ( V_10 -> V_30 >= V_85 )
return 0 ;
V_2 = V_8 -> V_18 ;
V_50 = F_33 ( V_53 + V_2 -> V_70 ,
V_2 -> V_4 . V_71 ) ;
V_84 = F_44 ( F_4 ( struct V_54 , V_59 ) +
( V_50 * sizeof( struct V_58 ) ) ,
V_86 | V_87 ) ;
V_84 -> V_75 = V_50 ;
V_56 = F_45 ( V_2 , V_10 -> V_30 ) ;
V_84 -> V_72 = F_46 ( V_2 ,
F_47 ( V_2 , V_56 ) ) ;
while ( V_56 < V_73 ) {
T_1 V_3 ;
if ( ! V_39 || V_44 >= ( char * ) V_39 -> V_47 + V_2 -> V_70 ) {
error = F_31 ( V_8 , V_53 , V_84 ,
& V_56 , & V_39 ) ;
if ( error || ! V_84 -> V_68 )
break;
V_83 = F_48 ( V_2 , V_84 -> V_78 , 0 ) ;
if ( V_56 < V_83 )
V_56 = V_83 ;
else if ( V_56 > V_83 )
ASSERT ( F_47 ( V_2 , V_56 ) ==
V_84 -> V_78 ) ;
V_37 = V_39 -> V_47 ;
F_22 ( V_8 , V_39 ) ;
V_44 = ( char * ) F_24 ( V_37 ) ;
V_82 = F_49 ( V_2 , V_56 ) ;
if ( V_82 == 0 )
V_56 += F_50 ( V_37 ) ;
else {
while ( ( char * ) V_44 - ( char * ) V_37 < V_82 ) {
V_42 = ( T_11 * ) V_44 ;
if ( F_26 ( V_42 -> V_48 )
== V_49 ) {
V_50 = F_26 ( V_42 -> V_50 ) ;
V_44 += V_50 ;
continue;
}
V_41 = ( T_10 * ) V_44 ;
V_50 =
F_27 ( V_2 , V_41 -> V_36 ) ;
V_44 += V_50 ;
}
V_56 =
F_48 ( V_2 ,
F_47 ( V_2 , V_56 ) ,
( char * ) V_44 - ( char * ) V_37 ) ;
if ( V_44 >= ( char * ) V_37 + V_2 -> V_70 ) {
continue;
}
}
}
V_42 = ( T_11 * ) V_44 ;
if ( F_26 ( V_42 -> V_48 ) == V_49 ) {
V_50 = F_26 ( V_42 -> V_50 ) ;
V_44 += V_50 ;
V_56 += V_50 ;
continue;
}
V_41 = ( T_10 * ) V_44 ;
V_50 = F_27 ( V_2 , V_41 -> V_36 ) ;
V_3 = F_28 ( V_2 , V_41 ) ;
V_10 -> V_30 = F_51 ( V_2 , V_56 ) & 0x7fffffff ;
if ( ! F_12 ( V_10 , ( char * ) V_41 -> V_35 , V_41 -> V_36 ,
F_29 ( V_41 -> V_51 ) ,
F_1 ( V_2 , V_3 ) ) )
break;
V_44 += V_50 ;
V_56 += V_50 ;
V_53 = V_53 > V_50 ? V_53 - V_50 : 0 ;
}
if ( V_56 > F_45 ( V_2 , V_85 ) )
V_10 -> V_30 = V_85 & 0x7fffffff ;
else
V_10 -> V_30 = F_51 ( V_2 , V_56 ) & 0x7fffffff ;
F_52 ( V_84 ) ;
if ( V_39 )
F_30 ( NULL , V_39 ) ;
return error ;
}
int
F_53 (
T_2 * V_8 ,
struct V_9 * V_10 ,
T_13 V_53 )
{
int V_88 ;
int V_89 ;
F_54 ( V_8 ) ;
if ( F_5 ( V_8 -> V_18 ) )
return F_6 ( V_25 ) ;
ASSERT ( F_55 ( V_8 -> V_22 . V_90 ) ) ;
F_56 ( V_91 ) ;
if ( V_8 -> V_22 . V_92 == V_93 )
V_88 = F_3 ( V_8 , V_10 ) ;
else if ( ( V_88 = F_57 ( NULL , V_8 , & V_89 ) ) )
;
else if ( V_89 )
V_88 = F_19 ( V_8 , V_10 ) ;
else
V_88 = F_43 ( V_8 , V_10 , V_53 ) ;
return V_88 ;
}
