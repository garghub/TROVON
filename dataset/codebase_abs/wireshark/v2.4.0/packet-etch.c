static void
F_1 ( void )
{
F_2 ( V_1 == NULL ) ;
V_1 = F_3 ( TRUE , TRUE , sizeof( V_2 ) ) ;
}
static void
F_4 ( void )
{
F_5 ( V_3 ) ;
V_3 = NULL ;
if ( V_1 != NULL ) {
V_2 * V_4 ;
T_1 V_5 ;
V_4 = ( V_2 * ) ( void * ) V_1 -> V_6 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_7 ; V_5 ++ ) {
F_6 ( ( V_8 * ) V_4 [ V_5 ] . V_9 ) ;
}
F_7 ( V_1 , TRUE ) ;
V_1 = NULL ;
}
}
static void
F_8 ( T_2 V_10 , V_8 * V_11 )
{
V_2 V_12 = { V_10 , V_11 } ;
F_2 ( V_1 != NULL ) ;
F_9 ( V_1 , V_12 ) ;
}
static T_3
F_10 ( T_4 V_13 , T_4 V_14 )
{
const V_2 * V_15 = ( const V_2 * ) V_13 ;
const V_2 * V_16 = ( const V_2 * ) V_14 ;
if( V_15 -> V_17 > V_16 -> V_17 )
return 1 ;
if( V_15 -> V_17 < V_16 -> V_17 )
return - 1 ;
return 0 ;
}
static void
F_11 ( void )
{
F_2 ( V_3 == NULL ) ;
F_2 ( V_1 != NULL ) ;
F_12 ( V_1 , F_10 ) ;
V_3 = F_13 ( ( V_2 * ) ( void * ) V_1 -> V_6 ,
V_1 -> V_7 + 1 ,
L_1 ) ;
}
static T_5
F_14 ( T_6 V_18 )
{
switch ( V_18 ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
return 0 ;
break;
case V_26 :
return 1 ;
break;
case V_27 :
return 2 ;
break;
case V_28 :
case V_29 :
return 4 ;
break;
case V_30 :
case V_31 :
return 8 ;
break;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
return - 1 ;
break;
default:
return 0 ;
break;
}
}
static void
F_15 ( const char * V_38 )
{
T_7 * V_39 ;
V_39 = F_16 ( V_38 , L_2 ) ;
if ( V_39 != NULL ) {
char line [ 256 ] ;
while ( fgets ( line , sizeof line , V_39 ) != NULL ) {
unsigned int V_10 ;
T_8 V_40 , V_41 ;
V_40 = strlen ( line ) ;
if ( V_40 < 10 )
continue;
V_41 = V_40 - 1 ;
while ( V_41 > 0 && ( line [ V_41 ] == 0xD || line [ V_41 ] == 0xA ) ) {
V_41 -- ;
}
line [ V_41 + 1 ] = '\0' ;
if ( sscanf ( & line [ 0 ] , L_3 , & V_10 ) != 1 )
continue;
V_41 = strcspn ( line , L_4 ) ;
if ( ( line [ V_41 ] != '\0' ) && ( line [ V_41 + 1 ] != '\0' ) )
F_8 ( V_10 ,
F_17 ( L_5 V_42 L_6 , & line [ V_41 + 1 ] ) ) ;
}
fclose ( V_39 ) ;
}
}
static void
F_18 ( const char * V_43 )
{
T_9 * V_44 ;
T_10 * V_45 ;
const char * V_46 ;
char * V_38 ;
T_11 * V_47 = NULL ;
if( V_48 != NULL ) {
F_6 ( V_48 ) ;
V_48 = NULL ;
}
F_4 () ;
if ( ( V_43 == NULL ) || ( V_43 [ 0 ] == '\0' ) )
return;
if ( ( V_44 = F_19 ( V_43 , 0 , & V_47 ) ) != NULL ) {
F_1 () ;
V_48 = F_20 ( V_43 ) ;
while ( ( V_45 = F_21 ( V_44 ) ) != NULL ) {
V_46 = F_22 ( V_45 ) ;
if ( F_23 ( V_45 , L_7 ) ) {
V_38 =
F_17 ( L_8 V_49 L_8 , V_43 ,
V_46 ) ;
F_15 ( V_38 ) ;
F_6 ( V_38 ) ;
}
}
F_24 ( V_44 ) ;
F_11 () ;
} else{
F_25 ( L_9 , V_47 -> V_50 ) ;
F_26 ( V_47 ) ;
}
}
static T_6
F_27 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
T_2 V_54 ;
V_54 = F_28 ( V_52 , * V_51 ) ;
F_29 ( V_53 , V_55 , V_52 , * V_51 , 1 , V_56 ) ;
( * V_51 ) ++ ;
return V_54 ;
}
static void
F_30 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
T_2 V_54 ;
V_54 = F_28 ( V_52 , * V_51 ) ;
F_27 ( V_51 , V_52 , V_53 ) ;
if ( V_54 == V_36 ) {
F_27 ( V_51 , V_52 , V_53 ) ;
F_29 ( V_53 , V_57 , V_52 , * V_51 , 4 ,
V_56 ) ;
( * V_51 ) += 4 ;
}
}
static T_2
F_31 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
T_2 V_40 ;
int V_58 ;
T_6 V_59 ;
V_59 = F_28 ( V_52 , * V_51 ) ;
if ( V_59 <= V_25
|| V_59 >= V_24 ) {
V_40 = V_59 ;
V_58 = 1 ;
} else {
T_6 V_54 ;
V_54 = F_27 ( V_51 , V_52 , V_53 ) ;
V_58 = F_14 ( V_54 ) ;
switch ( V_58 ) {
case 1 :
V_40 = F_28 ( V_52 , * V_51 ) ;
break;
case 2 :
V_40 = F_32 ( V_52 , * V_51 ) ;
break;
case 4 :
V_40 = F_33 ( V_52 , * V_51 ) ;
break;
default:
return 0 ;
}
}
F_29 ( V_53 , V_60 , V_52 , * V_51 ,
V_58 , V_56 ) ;
( * V_51 ) += V_58 ;
if ( * V_51 + V_40 < * V_51 ) {
V_40 = F_34 ( V_52 , * V_51 ) ;
}
return V_40 ;
}
static void
F_35 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
int V_40 ;
F_27 ( V_51 , V_52 , V_53 ) ;
F_30 ( V_51 , V_52 , V_53 ) ;
F_29 ( V_53 , V_61 , V_52 , * V_51 , 1 , V_56 ) ;
( * V_51 ) ++ ;
V_40 = F_31 ( V_51 , V_52 , V_53 ) ;
for (; V_40 > 0 ; V_40 -- ) {
F_36 ( V_51 , V_52 , V_53 , V_57 ) ;
}
F_27 ( V_51 , V_52 , V_53 ) ;
}
static void
F_37 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
int V_40 ;
F_27 ( V_51 , V_52 , V_53 ) ;
V_40 = F_31 ( V_51 , V_52 , V_53 ) ;
F_29 ( V_53 , V_62 , V_52 , * V_51 , V_40 ,
V_63 ) ;
( * V_51 ) += V_40 ;
}
static void
F_38 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
int V_64 ;
F_27 ( V_51 , V_52 , V_53 ) ;
V_64 = F_31 ( V_51 , V_52 , V_53 ) ;
F_29 ( V_53 , V_65 , V_52 , * V_51 ,
V_64 , V_66 | V_63 ) ;
( * V_51 ) += V_64 ;
}
static void
F_39 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 ,
int V_67 , T_6 V_54 )
{
int V_64 ;
F_27 ( V_51 , V_52 , V_53 ) ;
V_64 = F_14 ( V_54 ) ;
if ( V_64 > 0 ) {
T_14 * V_68 ;
const V_8 * V_11 = NULL ;
T_2 V_10 = 0 ;
V_69 = F_40 ( F_41 () ) ;
if ( V_64 == 4 ) {
V_10 = F_33 ( V_52 , * V_51 ) ;
V_11 = F_42 ( V_10 , V_3 ) ;
if( V_11 != NULL ) {
V_67 = V_70 ;
V_71 = TRUE ;
F_43 ( V_69 , L_8 , V_11 ) ;
}
}
V_68 = F_29 ( V_53 , V_67 , V_52 , * V_51 ,
V_64 , V_56 ) ;
* V_51 += V_64 ;
if ( V_11 != NULL ) {
F_44 ( V_68 , L_10 , V_10 , V_11 ) ;
}
}
}
static int
F_36 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 ,
int V_67 )
{
T_6 V_54 ;
V_54 = F_28 ( V_52 , * V_51 ) ;
if ( V_54 <= V_25 ||
V_54 >= V_24 ) {
F_29 ( V_53 , V_67 , V_52 , * V_51 , 1 , V_56 ) ;
( * V_51 ) ++ ;
return V_54 ;
}
switch( V_54 ) {
case V_36 :
F_45 ( V_51 , V_52 , V_53 , 1 ) ;
break;
case V_33 :
F_35 ( V_51 , V_52 , V_53 ) ;
break;
case V_34 :
F_38 ( V_51 , V_52 , V_53 ) ;
break;
case V_29 :
F_39 ( V_51 , V_52 , V_53 , V_72 , V_54 ) ;
break;
case V_31 :
F_39 ( V_51 , V_52 , V_53 , V_73 , V_54 ) ;
break;
case V_27 :
F_39 ( V_51 , V_52 , V_53 , V_74 , V_54 ) ;
break;
case V_28 :
F_39 ( V_51 , V_52 , V_53 , V_75 , V_54 ) ;
break;
case V_30 :
F_39 ( V_51 , V_52 , V_53 , V_76 , V_54 ) ;
break;
case V_26 :
F_39 ( V_51 , V_52 , V_53 , V_77 , V_54 ) ;
break;
case V_32 :
F_37 ( V_51 , V_52 , V_53 ) ;
break;
default:
F_39 ( V_51 , V_52 , V_53 , V_67 , V_54 ) ;
}
return 0 ;
}
static void
F_45 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 ,
int V_78 )
{
T_14 * V_68 ;
T_13 * V_79 ;
int V_40 ;
int V_5 ;
V_68 = F_29 ( V_53 , V_80 , V_52 , * V_51 ,
F_46 ( V_52 ) - * V_51 , V_63 ) ;
V_79 = F_47 ( V_68 , V_81 ) ;
if ( V_78 ) {
F_27 ( V_51 , V_52 , V_79 ) ;
}
F_36 ( V_51 , V_52 , V_79 , V_57 ) ;
V_40 = F_36 ( V_51 , V_52 , V_79 , V_60 ) ;
for ( V_5 = 0 ; V_5 < V_40 ; V_5 ++ ) {
F_48 ( V_51 , V_52 , V_79 ) ;
}
F_27 ( V_51 , V_52 , V_79 ) ;
}
static void
F_48 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
T_13 * V_79 ;
T_13 * V_82 ;
T_14 * V_68 , * V_83 ;
V_71 = FALSE ;
V_83 =
F_29 ( V_53 , V_84 , V_52 , * V_51 , 1 ,
V_63 ) ;
V_82 = V_79 =
F_47 ( V_83 , V_85 ) ;
V_68 = F_29 ( V_79 , V_86 , V_52 , * V_51 , 0 ,
V_63 ) ;
V_79 = F_47 ( V_68 , V_87 ) ;
F_36 ( V_51 , V_52 , V_79 , V_57 ) ;
if( V_71 == TRUE ) {
F_44 ( V_83 , L_11 , F_49 ( V_69 ) ) ;
}
V_68 = F_29 ( V_82 , V_88 , V_52 , * V_51 ,
0 , V_63 ) ;
V_79 = F_47 ( V_68 , V_89 ) ;
F_36 ( V_51 , V_52 , V_79 , V_57 ) ;
}
static T_15 *
F_50 ( T_12 * V_52 )
{
int V_90 ;
T_6 V_54 ;
T_15 * V_91 ;
int V_92 = 0 ;
V_91 = F_40 ( F_41 () ) ;
V_92 += ( 4 + 4 + 1 ) ;
V_54 = F_28 ( V_52 , V_92 ) ;
V_90 = F_14 ( V_54 ) ;
V_92 ++ ;
if ( V_90 == 4 ) {
const V_8 * V_11 ;
T_2 V_10 ;
V_10 = F_33 ( V_52 , V_92 ) ;
V_11 = F_42 ( V_10 , V_3 ) ;
if ( V_11 != NULL ) {
F_43 ( V_91 , L_12 , V_11 ) ;
}
}
return V_91 ;
}
static int
F_51 ( T_12 * V_52 , T_16 * V_93 , T_13 * V_94 , void * V_6 V_95 )
{
T_15 * V_96 = NULL ;
if ( V_93 -> V_97 || V_94 ) {
V_96 = F_50 ( V_52 ) ;
}
if ( V_93 -> V_97 ) {
F_52 ( V_93 -> V_97 , V_98 , L_13 ) ;
V_99 ++ ;
if ( V_93 -> V_100 != V_101 ) {
F_53 ( V_93 -> V_97 , V_102 ) ;
V_99 = 0 ;
}
V_101 = V_93 -> V_100 ;
F_54 ( V_93 -> V_97 , V_102 , L_14 , F_49 ( V_96 ) ) ;
}
if ( V_94 ) {
unsigned int V_51 ;
T_14 * V_68 ;
T_13 * V_53 ;
V_68 = F_55 ( V_94 , V_103 , V_52 , 0 , - 1 ,
L_15 , F_49 ( V_96 ) ) ;
V_51 = 9 ;
V_53 = F_47 ( V_68 , V_104 ) ;
F_29 ( V_53 , V_105 , V_52 , 0 , 4 , V_56 ) ;
F_29 ( V_53 , V_60 , V_52 , 4 , 4 , V_56 ) ;
F_29 ( V_53 , V_106 , V_52 , 8 , 1 , V_56 ) ;
F_45 ( & V_51 , V_52 , V_53 , 0 ) ;
}
return F_46 ( V_52 ) ;
}
static T_1
F_56 ( T_16 * V_93 V_95 , T_12 * V_52 ,
int V_51 , void * V_6 V_95 )
{
return F_33 ( V_52 , V_51 + 4 ) + 8 ;
}
static int
F_57 ( T_12 * V_52 , T_16 * V_93 , T_13 * V_94 , void * V_6 )
{
if ( F_46 ( V_52 ) < 4 ) {
return 0 ;
}
if ( F_58 ( V_52 , 0 , V_107 , 4 ) == - 1 ) {
return 0 ;
}
F_59 ( V_52 , V_93 , V_94 , TRUE , 8 , F_56 ,
F_51 , V_6 ) ;
if ( V_99 > 0 ) {
F_60 ( V_93 -> V_97 , V_102 , L_16 , V_99 + 1 ) ;
}
return 1 ;
}
static void
F_61 ( void )
{
V_99 = 0 ;
V_101 = 0xFFFFFFFF ;
}
void F_62 ( void )
{
T_17 * V_108 ;
static T_18 V_109 [] = {
{ & V_105 ,
{ L_17 , L_18 ,
V_110 , V_111 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_60 ,
{ L_19 , L_20 ,
V_113 , V_114 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_61 ,
{ L_21 , L_22 ,
V_115 , V_114 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_106 ,
{ L_23 , L_24 ,
V_115 , V_114 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_55 ,
{ L_25 , L_26 ,
V_115 , V_111 ,
F_63 ( V_116 ) , 0x0 ,
NULL , V_112 }
} ,
{ & V_57 ,
{ L_27 , L_28 ,
V_113 , V_114 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_62 ,
{ L_29 , L_30 ,
V_117 , V_118 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_77 ,
{ L_31 , L_32 ,
V_119 , V_114 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_74 ,
{ L_33 , L_34 ,
V_120 , V_114 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_75 ,
{ L_35 , L_36 ,
V_121 , V_114 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_76 ,
{ L_37 , L_38 ,
V_122 , V_114 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_72 ,
{ L_39 , L_40 ,
V_123 , V_118 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_73 ,
{ L_41 , L_42 ,
V_124 , V_118 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_84 ,
{ L_43 , L_44 ,
V_125 , V_118 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
#if 0
{&hf_etch_key,
{"Etch key", "etch.key",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL}
},
#endif
{ & V_70 ,
{ L_45 , L_46 ,
V_110 , V_111 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_80 ,
{ L_47 , L_48 ,
V_117 , V_118 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_65 ,
{ L_49 , L_50 ,
V_126 , V_118 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_86 ,
{ L_51 , L_52 ,
V_125 , V_118 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
{ & V_88 ,
{ L_53 , L_54 ,
V_125 , V_118 ,
NULL , 0x0 ,
NULL , V_112 }
} ,
} ;
static T_3 * V_127 [] = {
& V_104 ,
& V_81 ,
& V_85 ,
& V_87 ,
& V_89 ,
} ;
V_103 = F_64 ( L_55 ,
L_56 ,
L_57
) ;
F_65 ( V_103 , V_109 , F_66 ( V_109 ) ) ;
F_67 ( V_127 , F_66 ( V_127 ) ) ;
V_128 = F_68 ( L_57 , F_57 , V_103 ) ;
F_69 ( & F_61 ) ;
V_108 = F_70 ( V_103 , V_129 ) ;
F_71 ( V_108 , L_58 ,
L_59 ,
L_60
L_61
L_62 ,
& V_130 ) ;
}
void V_129 ( void )
{
static T_19 V_131 = FALSE ;
if( ! V_131 ) {
F_72 ( L_63 , F_57 , L_64 , L_65 , V_103 , V_132 ) ;
F_73 ( L_66 , V_128 ) ;
V_131 = TRUE ;
}
if( ( V_130 == NULL ) || ( V_48 == NULL ) ||
( strcmp ( V_130 , V_48 ) != 0 ) ) {
F_18 ( V_130 ) ;
}
}
