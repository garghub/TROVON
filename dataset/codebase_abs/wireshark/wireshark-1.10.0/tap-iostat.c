static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * V_3 , const void * T_3 V_4 )
{
T_4 * V_5 ;
T_5 * V_6 ;
T_5 * V_7 ;
T_6 V_8 , V_9 ;
T_7 * V_10 ;
T_8 * V_11 ;
T_9 V_12 ;
int V_13 ;
V_6 = ( T_5 * ) V_1 ;
V_5 = V_6 -> V_5 ;
V_8 = ( T_6 ) ( ( V_2 -> V_14 -> V_15 . V_16 * 1000000 ) + ( ( V_2 -> V_14 -> V_15 . V_17 + 500 ) / 1000 ) ) ;
if ( V_6 -> V_5 -> V_18 == 0 ) {
V_6 -> V_5 -> V_18 = V_2 -> V_14 -> V_19 . V_16 - V_2 -> V_14 -> V_15 . V_16 ;
}
V_7 = V_6 -> V_20 ;
if( V_8 < V_7 -> time ) {
return FALSE ;
}
V_9 = V_8 ;
while ( V_9 >= V_7 -> time + V_5 -> V_21 ) {
V_7 -> V_22 = ( T_5 * ) F_2 ( sizeof( T_5 ) ) ;
V_7 -> V_22 -> V_20 = V_7 ;
V_7 -> V_22 -> V_22 = NULL ;
V_7 = V_7 -> V_22 ;
V_6 -> V_20 = V_7 ;
V_7 -> time = V_7 -> V_20 -> time + V_5 -> V_21 ;
V_7 -> V_23 = 0 ;
V_7 -> V_24 = 0 ;
V_7 -> V_25 = 0 ;
V_7 -> V_26 = 0 ;
V_7 -> V_27 = 0 ;
V_7 -> V_28 = V_7 -> V_20 -> V_28 ;
V_7 -> V_29 = V_7 -> V_20 -> V_29 ;
V_7 -> V_30 = V_7 -> V_20 -> V_30 ;
}
V_7 -> V_23 ++ ;
switch( V_7 -> V_28 ) {
case V_31 :
case V_32 :
case V_33 :
V_7 -> V_24 += V_2 -> V_14 -> V_34 ;
break;
case V_35 :
V_11 = F_3 ( V_3 -> V_36 , V_7 -> V_29 ) ;
if( V_11 ) {
V_7 -> V_24 += V_11 -> V_37 ;
}
break;
case V_38 :
V_11 = F_3 ( V_3 -> V_36 , V_7 -> V_29 ) ;
if( V_11 ) {
T_6 V_39 ;
for( V_12 = 0 ; V_12 < V_11 -> V_37 ; V_12 ++ ) {
switch( F_4 ( V_7 -> V_29 ) ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
V_7 -> V_24 += F_5 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
break;
case V_47 :
V_7 -> V_24 += F_6 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
break;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_7 -> V_24 += F_7 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
break;
case V_52 :
V_7 -> V_24 += ( V_53 ) F_6 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
break;
case V_54 :
V_7 -> V_25 +=
( V_55 ) F_8 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
break;
case V_56 :
V_7 -> V_26 += F_8 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
break;
case V_57 :
V_10 = ( T_7 * ) F_9 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
V_39 = ( T_6 ) ( ( V_10 -> V_16 * V_58 ) + V_10 -> V_17 ) ;
V_7 -> V_24 += V_39 ;
break;
default:
F_10 () ;
break;
}
}
}
break;
case V_59 :
V_11 = F_3 ( V_3 -> V_36 , V_7 -> V_29 ) ;
if( V_11 ) {
T_6 V_39 ;
V_55 V_60 ;
T_10 V_61 ;
V_13 = F_4 ( V_7 -> V_29 ) ;
for( V_12 = 0 ; V_12 < V_11 -> V_37 ; V_12 ++ ) {
switch( V_13 ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
V_39 = F_5 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
if ( ( V_7 -> V_23 == 1 && V_12 == 0 ) || ( V_39 < V_7 -> V_24 ) ) {
V_7 -> V_24 = V_39 ;
}
break;
case V_47 :
V_39 = F_6 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
if( ( V_7 -> V_23 == 1 && V_12 == 0 ) || ( V_39 < V_7 -> V_24 ) ) {
V_7 -> V_24 = V_39 ;
}
break;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_39 = F_7 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
if( ( V_7 -> V_23 == 1 && V_12 == 0 ) || ( ( V_62 ) V_39 < ( V_62 ) V_7 -> V_24 ) ) {
V_7 -> V_24 = V_39 ;
}
break;
case V_52 :
V_39 = F_6 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
if( ( V_7 -> V_23 == 1 && V_12 == 0 ) || ( ( V_53 ) V_39 < ( V_53 ) V_7 -> V_24 ) ) {
V_7 -> V_24 = V_39 ;
}
break;
case V_54 :
V_60 = ( V_55 ) F_8 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
if( ( V_7 -> V_23 == 1 && V_12 == 0 ) || ( V_60 < V_7 -> V_25 ) ) {
V_7 -> V_25 = V_60 ;
}
break;
case V_56 :
V_61 = F_8 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
if( ( V_7 -> V_23 == 1 && V_12 == 0 ) || ( V_61 < V_7 -> V_26 ) ) {
V_7 -> V_26 = V_61 ;
}
break;
case V_57 :
V_10 = ( T_7 * ) F_9 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
V_39 = ( T_6 ) V_10 -> V_16 * V_58 + V_10 -> V_17 ;
if( ( V_7 -> V_23 == 1 && V_12 == 0 ) || ( V_39 < V_7 -> V_24 ) ) {
V_7 -> V_24 = V_39 ;
}
break;
default:
F_10 () ;
break;
}
}
}
break;
case V_63 :
V_11 = F_3 ( V_3 -> V_36 , V_7 -> V_29 ) ;
if( V_11 ) {
T_6 V_39 ;
V_55 V_60 ;
T_10 V_61 ;
V_13 = F_4 ( V_7 -> V_29 ) ;
for( V_12 = 0 ; V_12 < V_11 -> V_37 ; V_12 ++ ) {
switch( V_13 ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
V_39 = F_5 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
if( V_39 > V_7 -> V_24 )
V_7 -> V_24 = V_39 ;
break;
case V_47 :
V_39 = F_6 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
if( V_39 > V_7 -> V_24 )
V_7 -> V_24 = V_39 ;
break;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_39 = F_7 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
if( ( V_62 ) V_39 > ( V_62 ) V_7 -> V_24 )
V_7 -> V_24 = V_39 ;
break;
case V_52 :
V_39 = F_6 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
if ( ( V_53 ) V_39 > ( V_53 ) V_7 -> V_24 )
V_7 -> V_24 = V_39 ;
break;
case V_54 :
V_60 = ( V_55 ) F_8 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
if( V_60 > V_7 -> V_25 )
V_7 -> V_25 = V_60 ;
break;
case V_56 :
V_61 = F_8 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
if( V_61 > V_7 -> V_26 )
V_7 -> V_26 = V_61 ;
break;
case V_57 :
V_10 = ( T_7 * ) F_9 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
V_39 = ( T_6 ) ( ( V_10 -> V_16 * V_58 ) + V_10 -> V_17 ) ;
if ( V_39 > V_7 -> V_24 )
V_7 -> V_24 = V_39 ;
break;
default:
F_10 () ;
break;
}
}
}
break;
case V_64 :
V_11 = F_3 ( V_3 -> V_36 , V_7 -> V_29 ) ;
if( V_11 ) {
T_6 V_39 ;
V_13 = F_4 ( V_7 -> V_29 ) ;
for( V_12 = 0 ; V_12 < V_11 -> V_37 ; V_12 ++ ) {
V_7 -> V_27 ++ ;
switch( V_13 ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
V_39 = F_5 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
V_7 -> V_24 += V_39 ;
break;
case V_47 :
case V_52 :
V_39 = F_6 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
V_7 -> V_24 += V_39 ;
break;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_39 = F_7 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
V_7 -> V_24 += V_39 ;
break;
case V_54 :
V_7 -> V_25 += ( V_55 ) F_8 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
break;
case V_56 :
V_7 -> V_26 += F_8 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
break;
case V_57 :
V_10 = ( T_7 * ) F_9 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
V_39 = ( T_6 ) ( ( V_10 -> V_16 * V_58 ) + V_10 -> V_17 ) ;
V_7 -> V_24 += V_39 ;
break;
default:
F_10 () ;
break;
}
}
}
break;
case V_65 :
V_11 = F_3 ( V_3 -> V_36 , V_7 -> V_29 ) ;
if ( V_11 ) {
V_13 = F_4 ( V_7 -> V_29 ) ;
if ( V_13 != V_57 ) {
fprintf ( V_66 ,
L_1 ) ;
exit ( 10 ) ;
}
for( V_12 = 0 ; V_12 < V_11 -> V_37 ; V_12 ++ ) {
T_6 V_39 ;
int V_67 ;
T_5 * V_68 ;
V_10 = ( T_7 * ) F_9 ( & ( ( V_44 * ) V_11 -> V_45 [ V_12 ] ) -> V_46 ) ;
V_39 = ( T_6 ) ( ( V_10 -> V_16 * 1000000 ) + ( V_10 -> V_17 / 1000 ) ) ;
V_67 = ( int ) ( V_39 % V_5 -> V_21 ) ;
V_7 -> V_24 += V_67 ;
V_39 -= V_67 ;
V_68 = V_7 -> V_20 ;
while ( V_39 > 0 ) {
if ( V_39 < ( T_6 ) V_5 -> V_21 ) {
V_68 -> V_24 += V_39 ;
break;
}
V_68 -> V_24 += V_5 -> V_21 ;
V_39 -= V_5 -> V_21 ;
V_68 = V_68 -> V_20 ;
}
}
}
break;
}
switch( V_7 -> V_28 ) {
case V_31 :
case V_33 :
V_5 -> V_69 [ V_7 -> V_30 ] =
F_11 ( V_5 -> V_69 [ V_7 -> V_30 ] , V_7 -> V_23 ) ;
if ( V_7 -> V_28 == V_33 )
V_5 -> V_70 [ V_7 -> V_30 ] =
F_11 ( V_5 -> V_70 [ V_7 -> V_30 ] , V_7 -> V_24 ) ;
case V_32 :
case V_35 :
case V_65 :
V_5 -> V_70 [ V_7 -> V_30 ] = F_11 ( V_5 -> V_70 [ V_7 -> V_30 ] , V_7 -> V_24 ) ;
break;
case V_38 :
case V_59 :
case V_63 :
V_13 = F_4 ( V_7 -> V_29 ) ;
switch( V_13 ) {
case V_54 :
V_5 -> V_70 [ V_7 -> V_30 ] =
F_11 ( V_5 -> V_70 [ V_7 -> V_30 ] , ( T_6 ) ( V_7 -> V_25 + 0.5 ) ) ;
break;
case V_56 :
V_5 -> V_70 [ V_7 -> V_30 ] =
F_11 ( V_5 -> V_70 [ V_7 -> V_30 ] , ( T_6 ) ( V_7 -> V_26 + 0.5 ) ) ;
break;
case V_57 :
V_5 -> V_70 [ V_7 -> V_30 ] =
F_11 ( V_5 -> V_70 [ V_7 -> V_30 ] , V_7 -> V_24 ) ;
break;
default:
V_5 -> V_70 [ V_7 -> V_30 ] =
F_11 ( V_5 -> V_70 [ V_7 -> V_30 ] , V_7 -> V_24 ) ;
break;
}
break;
case V_64 :
if ( V_7 -> V_27 == 0 )
break;
V_13 = F_4 ( V_7 -> V_29 ) ;
switch( V_13 ) {
case V_54 :
V_5 -> V_70 [ V_7 -> V_30 ] =
F_11 ( V_5 -> V_70 [ V_7 -> V_30 ] , ( T_6 ) V_7 -> V_25 / V_7 -> V_27 ) ;
break;
case V_56 :
V_5 -> V_70 [ V_7 -> V_30 ] =
F_11 ( V_5 -> V_70 [ V_7 -> V_30 ] , ( T_6 ) V_7 -> V_26 / V_7 -> V_27 ) ;
break;
case V_57 :
V_5 -> V_70 [ V_7 -> V_30 ] =
F_11 ( V_5 -> V_70 [ V_7 -> V_30 ] , ( ( V_7 -> V_24 / V_7 -> V_27 ) + 500000000 ) / V_58 ) ;
break;
default:
V_5 -> V_70 [ V_7 -> V_30 ] =
F_11 ( V_5 -> V_70 [ V_7 -> V_30 ] , V_7 -> V_24 / V_7 -> V_27 ) ;
break;
}
}
return TRUE ;
}
static int
F_12 ( T_6 V_39 , int V_71 )
{
int V_12 , V_72 = 0 ;
for ( V_12 = 0 ; V_12 < V_71 ; V_12 ++ ) {
V_72 ++ ;
if ( ( V_39 /= 10 ) == 0 )
break;
}
return ( V_72 ) ;
}
static void
F_13 ( const char * V_73 , int V_74 , int V_75 )
{
int V_76 = ( int ) strlen ( V_73 ) , V_37 ;
const char V_77 [] = L_2 , * V_78 ;
V_37 = ( int ) ( strlen ( V_77 ) ) - ( ( ( V_74 - V_76 ) / 2 ) + V_75 ) ;
if ( V_37 > 0 && V_37 < 6 ) {
V_78 = & V_77 [ V_37 ] ;
if ( ( V_74 - V_76 ) % 2 == 0 ) {
printf ( L_3 , V_78 , V_73 , V_78 ) ;
} else {
printf ( L_3 , V_78 - 1 , V_73 , V_78 ) ;
}
} else if ( V_37 > 0 && V_37 <= 15 ) {
printf ( L_4 , V_73 ) ;
}
}
static void
F_14 ( void * V_1 )
{
T_11 V_27 ;
T_6 V_21 , V_79 , V_80 , V_81 ;
int V_12 , V_82 , V_83 , V_84 , V_85 , V_86 , V_87 , V_88 , V_89 , V_90 , V_91 ,
V_92 , V_93 , V_75 = 1 , V_94 , V_95 , type , V_96 , V_13 ;
int V_97 ;
int V_98 ;
char * V_77 , * V_99 , * V_100 = NULL , * * V_101 , * V_102 = NULL ;
const char * V_103 ;
static T_12 V_104 [ 3 ] , V_105 [ 3 ] , V_106 [ 3 ] , V_107 [ 3 ] , V_108 [ 3 ] , * V_109 , * V_110 ;
T_5 * V_6 , * * V_111 , * V_112 , * * V_113 ;
T_13 V_114 = FALSE ;
T_4 * V_115 ;
T_14 * V_116 ;
struct V_117 * V_118 ;
T_15 V_119 ;
V_6 = ( T_5 * ) V_1 ;
V_115 = V_6 -> V_5 ;
V_84 = V_115 -> V_84 ;
V_116 = ( T_14 * ) F_2 ( sizeof( T_14 ) * V_84 ) ;
V_101 = ( char * * ) F_2 ( sizeof( char * ) * V_84 ) ;
V_79 = ( T_6 ) ( ( V_120 . V_121 . V_16 * 1000000 ) + ( ( V_120 . V_121 . V_17 + 500 ) / 1000 ) ) ;
V_111 = ( T_5 * * ) F_2 ( sizeof( T_5 * ) * V_84 ) ;
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ )
V_111 [ V_82 ] = & V_115 -> V_122 [ V_82 ] ;
if ( V_115 -> V_21 > V_79 || V_115 -> V_21 == V_123 ) {
V_21 = V_79 ;
V_115 -> V_21 = V_123 ;
} else {
V_21 = V_115 -> V_21 ;
}
V_87 = ( int ) V_79 / 1000000 ;
V_88 = F_12 ( ( T_6 ) V_87 , 5 ) ;
F_15 ( V_104 , 3 , L_5 , V_88 ) ;
V_89 = F_12 ( ( T_6 ) V_21 / 1000000 , 5 ) ;
if ( V_21 == V_79 ) {
if ( V_88 >= 2 )
V_90 = 1 ;
else if ( V_88 == 1 )
V_90 = 3 ;
else
V_90 = 6 ;
V_92 = 30 + V_88 + ( V_90 == 0 ? 0 : V_90 + 1 ) ;
} else {
V_90 = V_115 -> V_90 ;
V_92 = 24 + V_89 + ( V_90 == 0 ? 0 : V_90 + 1 ) ;
}
V_86 = 1000000 ;
for ( V_12 = 0 ; V_12 < V_90 ; V_12 ++ )
V_86 /= 10 ;
V_79 = V_79 + ( 5 * ( V_86 / 10 ) ) ;
if ( V_115 -> V_21 == V_123 )
V_21 = V_79 ;
V_87 = ( int ) V_79 / 1000000 ;
V_88 = F_12 ( ( T_6 ) V_87 , 5 ) ;
if ( V_90 == 0 )
V_93 = ( 2 * V_88 ) + 8 ;
else
V_93 = ( 2 * V_88 ) + ( 2 * V_90 ) + 10 ;
if ( F_16 () == V_124 )
V_93 = F_11 ( V_93 , 23 ) ;
else
V_93 = F_11 ( V_93 , 12 ) ;
V_92 = F_11 ( V_92 , V_93 ) ;
V_91 = V_93 ;
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ ) {
type = V_115 -> V_122 [ V_82 ] . V_28 ;
if ( type == V_33 ) {
V_94 = 5 ;
} else {
V_94 = ( int ) strlen ( V_125 [ type ] . V_126 ) ;
}
if( type == V_31
|| type == V_33 ) {
V_97 = F_12 ( V_115 -> V_69 [ V_82 ] , 15 ) ;
V_97 = F_11 ( 6 , V_97 ) ;
V_116 [ V_82 ] . V_127 = V_97 ;
V_91 += V_116 [ V_82 ] . V_127 + 3 ;
F_15 ( V_107 , 3 , L_5 , V_97 ) ;
if ( type == V_31 ) {
V_102 = F_17 ( L_6 , V_107 , L_7 , NULL ) ;
} else {
V_98 = F_12 ( V_115 -> V_70 [ V_82 ] , 15 ) ;
V_98 = F_11 ( 5 , V_98 ) ;
V_116 [ V_82 ] . V_39 = V_98 ;
V_91 += ( V_116 [ V_82 ] . V_39 + 3 ) ;
F_15 ( V_108 , 3 , L_5 , V_98 ) ;
V_102 = F_17 ( L_6 , V_107 , L_7 , L_6 , V_108 , V_128 , L_7 , NULL ) ;
}
if ( V_102 )
V_101 [ V_82 ] = V_102 ;
continue;
}
switch( type ) {
case V_32 :
case V_35 :
V_98 = F_12 ( V_115 -> V_70 [ V_82 ] , 15 ) ;
V_98 = F_11 ( 5 , V_98 ) ;
V_116 [ V_82 ] . V_39 = V_98 ;
F_15 ( V_108 , 3 , L_5 , V_98 ) ;
V_102 = F_17 ( L_6 , V_108 , V_128 , L_7 , NULL ) ;
break;
default:
V_13 = F_4 ( V_111 [ V_82 ] -> V_29 ) ;
switch ( V_13 ) {
case V_54 :
case V_56 :
V_98 = F_12 ( V_115 -> V_70 [ V_82 ] , 15 ) ;
F_15 ( V_108 , 3 , L_5 , V_98 ) ;
V_102 = F_17 ( L_6 , V_108 , L_8 , NULL ) ;
V_116 [ V_82 ] . V_39 = V_98 + 7 ;
break;
case V_57 :
if ( type == V_65 ) {
V_115 -> V_70 [ V_82 ] /= V_21 ;
} else if ( type != V_64 ) {
V_115 -> V_70 [ V_82 ] = ( V_115 -> V_70 [ V_82 ] + 500000000 ) / V_58 ;
}
V_98 = F_12 ( V_115 -> V_70 [ V_82 ] , 15 ) ;
F_15 ( V_108 , 3 , L_5 , V_98 ) ;
V_102 = F_17 ( L_6 , V_108 , L_9 , NULL ) ;
V_116 [ V_82 ] . V_39 = V_98 + 7 ;
break;
default:
V_98 = F_12 ( V_115 -> V_70 [ V_82 ] , 15 ) ;
V_98 = F_11 ( V_94 , V_98 ) ;
V_116 [ V_82 ] . V_39 = V_98 ;
F_15 ( V_108 , 3 , L_5 , V_98 ) ;
switch ( V_13 ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_47 :
V_102 = F_17 ( L_6 , V_108 , V_128 , L_7 , NULL ) ;
break;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
V_102 = F_17 ( L_6 , V_108 , V_128 , L_10 , NULL ) ;
break;
}
}
}
V_91 += V_116 [ V_82 ] . V_39 + 3 ;
if ( V_102 )
V_101 [ V_82 ] = V_102 ;
}
V_92 = F_11 ( V_92 , V_91 ) ;
V_96 = 0 ;
for( V_82 = 0 ; V_82 < V_84 ; V_82 ++ ) {
if ( V_115 -> V_129 [ V_82 ] ) {
V_83 = ( int ) ( strlen ( V_115 -> V_129 [ V_82 ] ) + 11 ) ;
V_96 = F_11 ( V_96 , V_83 ) ;
} else {
V_96 = F_11 ( V_96 , 26 ) ;
}
}
if ( V_96 > V_92 && V_92 < 102 )
V_92 = F_18 ( V_96 , 102 ) ;
if ( V_92 - V_91 == 1 )
V_92 ++ ;
printf ( L_11 ) ;
for ( V_12 = 0 ; V_12 < V_92 ; V_12 ++ )
printf ( L_12 ) ;
V_77 = ( char * ) F_2 ( V_92 + 1 ) ;
for ( V_12 = 0 ; V_12 < V_92 ; V_12 ++ )
V_77 [ V_12 ] = ' ' ;
V_77 [ V_92 ] = '\0' ;
V_99 = & V_77 [ 16 ] ;
printf ( L_13 , V_99 ) ;
V_99 = & V_77 [ 2 ] ;
printf ( L_14 , V_99 ) ;
F_15 ( V_105 , 3 , L_5 , V_89 ) ;
if ( V_90 > 0 ) {
F_15 ( V_106 , 3 , L_5 , V_90 ) ;
V_109 = F_17 ( L_15 , V_105 , L_16 , V_106 , L_17 , NULL ) ;
if ( V_21 == V_79 ) {
V_110 = F_17 ( L_18 , V_109 , L_19 , NULL ) ;
V_99 = & V_77 [ 30 + V_89 + V_90 ] ;
} else {
V_110 = F_17 ( L_18 , V_109 , L_20 , NULL ) ;
V_99 = & V_77 [ 24 + V_89 + V_90 ] ;
}
printf ( V_110 , ( T_11 ) V_21 / 1000000 ,
( T_11 ) ( ( V_21 % 1000000 ) / V_86 ) , V_99 ) ;
} else {
V_109 = F_17 ( L_15 , V_105 , L_17 , NULL ) ;
V_110 = F_17 ( L_18 , V_109 , L_20 , NULL ) ;
V_99 = & V_77 [ 23 + V_89 ] ;
printf ( V_110 , ( T_11 ) V_21 / 1000000 , V_99 ) ;
}
F_19 ( V_109 ) ;
F_19 ( V_110 ) ;
if ( V_90 > 0 )
V_109 = F_17 ( L_15 , V_104 , L_16 , V_106 , L_17 , NULL ) ;
else
V_109 = F_17 ( L_15 , V_104 , L_17 , NULL ) ;
printf ( L_21 ) ;
for( V_82 = 0 ; V_82 < V_84 ; V_82 ++ ) {
printf ( ( V_82 == 0 ? L_22 : L_23 ) , V_82 + 1 ) ;
if ( ! V_115 -> V_129 [ V_82 ] || ( V_115 -> V_129 [ V_82 ] == 0 ) ) {
V_99 = & V_77 [ 16 + 10 ] ;
printf ( L_24 , V_99 ) ;
} else {
V_103 = V_115 -> V_129 [ V_82 ] ;
V_95 = ( int ) strlen ( V_103 ) ;
if ( V_95 + 11 <= V_92 ) {
printf ( L_25 , V_103 ) ;
if ( V_95 + 11 <= V_92 ) {
V_99 = & V_77 [ V_95 + 10 ] ;
printf ( L_25 , V_99 ) ;
}
printf ( L_26 ) ;
} else {
T_12 * V_130 , * V_131 ;
const T_12 * V_132 ;
T_16 V_37 ;
int V_133 , V_71 = V_92 - 11 ;
do {
if ( V_95 > V_71 ) {
V_130 = F_20 ( ( T_12 * ) V_103 , ( T_16 ) V_71 ) ;
V_132 = F_21 ( V_130 , L_27 ) ;
if ( V_132 ) {
V_37 = ( T_16 ) ( V_132 - V_130 ) ;
V_133 = ( int ) V_37 + 1 ;
} else {
V_37 = ( T_16 ) strlen ( V_130 ) ;
V_133 = ( int ) V_37 ;
}
V_131 = F_20 ( V_130 , V_37 ) ;
printf ( L_28 , V_131 , & V_77 [ V_37 + 10 ] ) ;
F_19 ( V_130 ) ;
F_19 ( V_131 ) ;
printf ( L_29 ) ;
V_103 = & V_103 [ V_133 ] ;
V_95 = ( int ) strlen ( V_103 ) ;
} else {
printf ( L_28 , V_103 , & V_77 [ ( ( int ) strlen ( V_103 ) ) + 10 ] ) ;
break;
}
} while ( 1 );
}
}
}
printf ( L_30 ) ;
for( V_12 = 0 ; V_12 < V_92 - 3 ; V_12 ++ ) {
printf ( L_31 ) ;
}
printf ( L_26 ) ;
V_99 = & V_77 [ V_92 - ( V_93 - 2 ) ] ;
printf ( L_32 , V_99 ) ;
for( V_82 = 0 ; V_82 < V_84 ; V_82 ++ ) {
V_112 = V_111 [ V_82 ] ;
if( V_112 -> V_28 == V_33 )
V_99 = & V_77 [ V_92 - ( V_116 [ V_82 ] . V_127 + V_116 [ V_82 ] . V_39 ) ] - 3 ;
else if ( V_112 -> V_28 == V_31 )
V_99 = & V_77 [ V_92 - V_116 [ V_82 ] . V_127 ] ;
else
V_99 = & V_77 [ V_92 - V_116 [ V_82 ] . V_39 ] ;
printf ( L_33 , V_82 + 1 , V_99 ) ;
}
if ( V_91 < V_92 ) {
V_100 = & V_77 [ V_91 + 1 ] ;
printf ( L_4 , V_100 ) ;
}
V_83 = 11 ;
switch ( F_16 () ) {
case V_134 :
printf ( L_34 ) ;
break;
case V_124 :
printf ( L_35 ) ;
V_83 = 16 ;
break;
case V_135 :
case V_136 :
printf ( L_36 ) ;
break;
default:
break;
}
V_99 = & V_77 [ V_92 - ( V_93 - V_83 ) ] ;
printf ( L_4 , V_99 ) ;
for( V_82 = 0 ; V_82 < V_84 ; V_82 ++ ) {
type = V_111 [ V_82 ] -> V_28 ;
if( type == V_31 ) {
F_13 ( V_125 [ type ] . V_126 , V_116 [ V_82 ] . V_127 , V_75 ) ;
} else if ( type == V_33 ) {
F_13 ( L_37 , V_116 [ V_82 ] . V_127 , V_75 ) ;
F_13 ( L_38 , V_116 [ V_82 ] . V_39 , V_75 ) ;
} else {
F_13 ( V_125 [ type ] . V_126 , V_116 [ V_82 ] . V_39 , V_75 ) ;
}
}
if ( V_100 )
printf ( L_4 , V_100 ) ;
printf ( L_39 ) ;
for( V_12 = 0 ; V_12 < V_91 - 3 ; V_12 ++ )
printf ( L_31 ) ;
printf ( L_40 ) ;
if ( V_91 < V_92 )
printf ( L_4 , & V_77 [ V_91 + 1 ] ) ;
printf ( L_11 ) ;
V_80 = 0 ;
V_110 = F_17 ( L_41 , V_109 , L_42 , V_109 , L_43 , NULL ) ;
V_85 = ( int ) ( V_79 / V_21 ) + ( ( ( V_79 % V_21 + 500000 ) / 1000000 ) > 0 ? 1 : 0 ) ;
V_113 = ( T_5 * * ) F_2 ( sizeof( T_5 ) * V_84 ) ;
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ ) {
V_113 [ V_82 ] = V_111 [ V_82 ] ;
}
for ( V_12 = 0 ; V_12 < V_85 ; V_12 ++ ) {
if ( V_12 == V_85 - 1 )
V_114 = TRUE ;
if ( ! V_114 ) {
V_81 = V_80 + V_21 ;
} else {
V_81 = V_79 ;
}
V_119 = V_115 -> V_18 + ( T_11 ) ( V_80 / 1000000 ) ;
V_118 = localtime ( & V_119 ) ;
switch ( F_16 () ) {
case V_134 :
printf ( L_44 ,
V_118 -> V_137 ,
V_118 -> V_138 ,
V_118 -> V_139 ) ;
break;
case V_124 :
printf ( L_45 ,
V_118 -> V_140 + 1900 ,
V_118 -> V_141 + 1 ,
V_118 -> V_142 ,
V_118 -> V_137 ,
V_118 -> V_138 ,
V_118 -> V_139 ) ;
break;
case V_135 :
case V_136 :
if ( V_90 == 0 ) {
printf ( V_110 , ( T_11 ) ( V_80 / 1000000 ) ,
( T_11 ) ( V_81 / 1000000 ) ) ;
} else {
printf ( V_110 , ( T_11 ) ( V_80 / 1000000 ) ,
( T_11 ) ( V_80 % 1000000 ) / V_86 ,
( T_11 ) ( V_81 / 1000000 ) ,
( T_11 ) ( ( V_81 % 1000000 ) / V_86 ) ) ;
}
break;
default:
break;
}
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ ) {
V_102 = V_101 [ V_82 ] ;
V_112 = V_113 [ V_82 ] ;
if ( V_112 ) {
switch( V_112 -> V_28 ) {
case V_31 :
printf ( V_102 , V_112 -> V_23 ) ;
break;
case V_32 :
case V_35 :
printf ( V_102 , V_112 -> V_24 ) ;
break;
case V_33 :
printf ( V_102 , V_112 -> V_23 , V_112 -> V_24 ) ;
break;
case V_38 :
case V_59 :
case V_63 :
V_13 = F_4 ( V_111 [ V_82 ] -> V_29 ) ;
switch( V_13 ) {
case V_54 :
printf ( V_102 , V_112 -> V_25 ) ;
break;
case V_56 :
printf ( V_102 , V_112 -> V_26 ) ;
break;
case V_57 :
V_112 -> V_24 = ( V_112 -> V_24 + 500 ) / 1000 ;
printf ( V_102 , ( int ) ( V_112 -> V_24 / 1000000 ) , ( int ) ( V_112 -> V_24 % 1000000 ) ) ;
break;
default:
printf ( V_102 , V_112 -> V_24 ) ;
break;
}
break;
case V_64 :
V_27 = V_112 -> V_27 ;
if( V_27 == 0 )
V_27 = 1 ;
V_13 = F_4 ( V_111 [ V_82 ] -> V_29 ) ;
switch( V_13 ) {
case V_54 :
printf ( V_102 , V_112 -> V_25 / V_27 ) ;
break;
case V_56 :
printf ( V_102 , V_112 -> V_26 / V_27 ) ;
break;
case V_57 :
V_112 -> V_24 = ( ( V_112 -> V_24 / V_27 ) + 500 ) / 1000 ;
printf ( V_102 ,
( int ) ( V_112 -> V_24 / 1000000 ) , ( int ) ( V_112 -> V_24 % 1000000 ) ) ;
break;
default:
printf ( V_102 , V_112 -> V_24 / V_27 ) ;
break;
}
break;
case V_65 :
V_13 = F_4 ( V_111 [ V_82 ] -> V_29 ) ;
switch( V_13 ) {
case V_57 :
if ( ! V_114 ) {
printf ( V_102 ,
( int ) ( V_112 -> V_24 / V_21 ) ,
( int ) ( ( V_112 -> V_24 % V_21 ) * 1000000 / V_21 ) ) ;
} else {
printf ( V_102 ,
( int ) ( V_112 -> V_24 / ( V_81 - V_80 ) ) ,
( int ) ( ( V_112 -> V_24 % ( V_81 - V_80 ) ) * 1000000 / ( V_81 - V_80 ) ) ) ;
}
break;
}
break;
}
if ( V_114 ) {
if ( V_102 )
F_19 ( V_102 ) ;
} else {
V_113 [ V_82 ] = V_113 [ V_82 ] -> V_22 ;
}
} else {
printf ( V_102 , ( T_6 ) 0 , ( T_6 ) 0 ) ;
}
}
if ( V_100 )
printf ( L_4 , V_100 ) ;
printf ( L_11 ) ;
V_80 += V_21 ;
}
for( V_12 = 0 ; V_12 < V_92 ; V_12 ++ ) {
printf ( L_12 ) ;
}
printf ( L_11 ) ;
F_19 ( V_115 -> V_122 ) ;
F_19 ( V_115 -> V_70 ) ;
F_19 ( V_115 -> V_69 ) ;
F_19 ( V_115 ) ;
F_19 ( V_116 ) ;
F_19 ( V_109 ) ;
F_19 ( V_110 ) ;
F_19 ( V_101 ) ;
F_19 ( V_77 ) ;
F_19 ( V_111 ) ;
F_19 ( V_113 ) ;
}
static void
F_22 ( T_4 * V_143 , int V_12 , const char * V_103 )
{
T_17 * V_144 ;
const char * V_145 ;
int V_82 ;
T_18 V_94 ;
const char * V_146 , * V_147 ;
char * V_148 ;
T_19 * V_149 ;
V_143 -> V_122 [ V_12 ] . V_20 = & V_143 -> V_122 [ V_12 ] ;
V_143 -> V_122 [ V_12 ] . V_22 = NULL ;
V_143 -> V_122 [ V_12 ] . V_5 = V_143 ;
V_143 -> V_122 [ V_12 ] . time = 0 ;
V_143 -> V_122 [ V_12 ] . V_28 = V_33 ;
V_143 -> V_122 [ V_12 ] . V_23 = 0 ;
V_143 -> V_122 [ V_12 ] . V_24 = 0 ;
V_143 -> V_122 [ V_12 ] . V_27 = 0 ;
V_143 -> V_129 [ V_12 ] = V_103 ;
V_145 = V_103 ;
V_148 = NULL ;
V_149 = NULL ;
for( V_82 = 0 ; V_125 [ V_82 ] . V_126 ; V_82 ++ ) {
V_94 = strlen ( V_125 [ V_82 ] . V_126 ) ;
if( V_103 && strncmp ( V_103 , V_125 [ V_82 ] . V_126 , V_94 ) == 0 ) {
V_143 -> V_122 [ V_12 ] . V_28 = V_125 [ V_82 ] . V_28 ;
V_143 -> V_122 [ V_12 ] . V_30 = V_12 ;
if( * ( V_103 + V_94 ) == '(' ) {
V_146 = V_103 + V_94 + 1 ;
V_147 = strchr ( V_146 , ')' ) ;
if( ! V_147 ) {
fprintf ( V_66 ,
L_46 ) ;
exit ( 10 ) ;
}
if( V_143 -> V_122 [ V_12 ] . V_28 == V_31 || V_143 -> V_122 [ V_12 ] . V_28 == V_32 ) {
if( V_147 != V_146 ) {
fprintf ( V_66 ,
L_47 ,
V_125 [ V_82 ] . V_126 ) ;
exit ( 10 ) ;
}
} else {
if( V_147 == V_146 ) {
fprintf ( V_66 , L_48 ,
V_125 [ V_82 ] . V_126 ) ;
exit ( 10 ) ;
}
}
V_148 = ( char * ) F_2 ( V_147 - V_146 + 1 ) ;
memcpy ( V_148 , V_146 , V_147 - V_146 ) ;
V_148 [ V_147 - V_146 ] = '\0' ;
V_145 = V_147 + 1 ;
if ( V_143 -> V_122 [ V_12 ] . V_28 == V_31 || V_143 -> V_122 [ V_12 ] . V_28 == V_32 )
break;
V_149 = F_23 ( V_148 ) ;
if( ! V_149 ) {
fprintf ( V_66 , L_49 ,
V_148 ) ;
F_19 ( V_148 ) ;
exit ( 10 ) ;
}
V_143 -> V_122 [ V_12 ] . V_29 = V_149 -> V_150 ;
break;
}
} else {
if ( V_143 -> V_122 [ V_12 ] . V_28 == V_31 || V_143 -> V_122 [ V_12 ] . V_28 == V_32 )
V_145 = L_50 ;
V_143 -> V_122 [ V_12 ] . V_30 = V_12 ;
}
}
if( V_149 && ! ( V_143 -> V_122 [ V_12 ] . V_28 == V_32 ||
V_143 -> V_122 [ V_12 ] . V_28 == V_31 ||
V_143 -> V_122 [ V_12 ] . V_28 == V_33 ) ) {
switch( V_149 -> type ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
break;
case V_54 :
case V_56 :
switch( V_143 -> V_122 [ V_12 ] . V_28 ) {
case V_38 :
case V_35 :
case V_63 :
case V_59 :
case V_64 :
break;
default:
fprintf ( V_66 ,
L_51 ,
V_148 ,
V_125 [ V_82 ] . V_126 ) ;
exit ( 10 ) ;
}
break;
case V_57 :
switch( V_143 -> V_122 [ V_12 ] . V_28 ) {
case V_38 :
case V_35 :
case V_63 :
case V_59 :
case V_64 :
case V_65 :
break;
default:
fprintf ( V_66 ,
L_52 ,
V_148 ,
V_125 [ V_82 ] . V_126 ) ;
exit ( 10 ) ;
}
break;
default:
if( V_143 -> V_122 [ V_12 ] . V_28 != V_35 ) {
fprintf ( V_66 ,
L_53
L_54 ,
V_148 ,
V_125 [ V_82 ] . V_126 ) ;
exit ( 10 ) ;
}
break;
}
F_19 ( V_148 ) ;
}
V_144 = F_24 ( L_55 , & V_143 -> V_122 [ V_12 ] , V_145 , V_151 , NULL ,
F_1 , V_12 ? NULL : F_14 ) ;
if( V_144 ) {
F_19 ( V_143 -> V_122 ) ;
F_19 ( V_143 ) ;
fprintf ( V_66 , L_56 ,
V_144 -> V_152 ) ;
F_25 ( V_144 , TRUE ) ;
exit ( 1 ) ;
}
}
static void
F_26 ( const char * V_153 , void * T_20 V_4 )
{
T_10 V_154 ;
T_11 V_155 = 0 , V_12 ;
T_4 * V_143 ;
const T_12 * V_129 , * V_152 , * V_132 ;
if ( ( * ( V_153 + ( strlen ( V_153 ) - 1 ) ) == ',' ) ||
( sscanf ( V_153 , L_57 , & V_154 , ( int * ) & V_155 ) != 1 ) ||
( V_155 < 8 ) ) {
fprintf ( V_66 , L_58 ) ;
exit ( 1 ) ;
}
V_129 = V_153 + V_155 ;
if ( * V_129 ) {
if ( * V_129 != ',' ) {
-- V_129 ;
if ( * V_129 != ',' ) {
fprintf ( V_66 , L_58 ) ;
exit ( 1 ) ;
}
}
} else
V_129 = NULL ;
switch ( F_16 () ) {
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
fprintf ( V_66 , L_59 ) ;
exit ( 1 ) ;
default:
break;
}
V_143 = ( T_4 * ) F_2 ( sizeof( T_4 ) ) ;
if ( V_154 == 0 ) {
V_143 -> V_21 = V_123 ;
V_143 -> V_90 = 0 ;
} else {
V_143 -> V_21 = ( V_53 ) ( V_154 * 1000000.0 + 0.5 ) ;
V_143 -> V_90 = 6 ;
for ( V_12 = 10 ; V_12 < 10000000 ; V_12 *= 10 ) {
if ( V_143 -> V_21 % V_12 > 0 )
break;
V_143 -> V_90 -- ;
}
}
if ( V_143 -> V_21 < 1 ) {
fprintf ( V_66 ,
L_60 ) ;
exit ( 10 ) ;
}
V_143 -> V_84 = 1 ;
V_143 -> V_18 = 0 ;
if ( V_129 && ( * V_129 != '\0' ) ) {
V_152 = V_129 ;
while( ( V_152 = strchr ( V_152 , ',' ) ) ) {
V_143 -> V_84 ++ ;
V_152 ++ ;
}
}
V_143 -> V_122 = ( T_5 * ) F_2 ( sizeof( T_5 ) * V_143 -> V_84 ) ;
V_143 -> V_129 = ( const char * * ) F_2 ( sizeof( char * ) * V_143 -> V_84 ) ;
V_143 -> V_70 = ( T_6 * ) F_2 ( sizeof( T_6 ) * V_143 -> V_84 ) ;
V_143 -> V_69 = ( T_11 * ) F_2 ( sizeof( T_11 ) * V_143 -> V_84 ) ;
for ( V_12 = 0 ; V_12 < V_143 -> V_84 ; V_12 ++ ) {
V_143 -> V_70 [ V_12 ] = 0 ;
V_143 -> V_69 [ V_12 ] = 0 ;
}
if( ( ! V_129 ) || ( V_129 [ 0 ] == 0 ) ) {
F_22 ( V_143 , 0 , NULL ) ;
} else {
T_12 * V_103 ;
V_12 = 0 ;
V_152 = V_129 ;
do {
V_132 = ( T_12 * ) strchr ( V_152 , ',' ) ;
if( V_132 == V_152 ) {
F_22 ( V_143 , V_12 , NULL ) ;
} else if ( V_132 == NULL ) {
V_152 = ( const char * ) F_27 ( ( T_12 * ) V_152 ) ;
V_103 = F_28 ( ( T_12 * ) V_152 ) ;
if ( * V_103 )
F_22 ( V_143 , V_12 , V_103 ) ;
else
F_22 ( V_143 , V_12 , NULL ) ;
} else {
V_103 = ( T_12 * ) F_2 ( ( V_132 - V_152 ) + 1 ) ;
F_29 ( V_103 , V_152 , ( T_16 ) ( ( V_132 - V_152 ) + 1 ) ) ;
V_103 = F_27 ( V_103 ) ;
F_22 ( V_143 , V_12 , ( char * ) V_103 ) ;
}
V_152 = V_132 + 1 ;
V_12 ++ ;
} while( V_132 );
}
}
void
F_30 ( void )
{
F_31 ( L_61 , F_26 , NULL ) ;
}
