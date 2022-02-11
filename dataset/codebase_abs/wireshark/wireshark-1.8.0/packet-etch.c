static void
F_1 ( void ) {
F_2 ( V_1 == NULL ) ;
V_1 = F_3 ( TRUE , TRUE , sizeof( V_2 ) ) ;
}
static void
F_4 ( void ) {
F_5 ( V_3 ) ;
V_3 = NULL ;
if ( V_1 != NULL ) {
V_2 * V_4 ;
T_1 V_5 ;
V_4 = ( V_2 * ) ( void * ) V_1 -> V_6 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_7 ; V_5 ++ ) {
F_5 ( ( V_8 * ) V_4 [ V_5 ] . V_9 ) ;
}
F_6 ( V_1 , TRUE ) ;
V_1 = NULL ;
}
}
static void
F_7 ( int V_10 , V_8 * V_11 ) {
V_2 V_12 = { V_10 , V_11 } ;
F_2 ( V_1 != NULL ) ;
F_8 ( V_1 , V_12 ) ;
}
static T_2
F_9 ( T_3 V_13 , T_3 V_14 )
{
V_2 * V_15 = ( V_2 * ) V_13 ;
V_2 * V_16 = ( V_2 * ) V_14 ;
if( V_15 -> V_17 > V_16 -> V_17 )
return 1 ;
if( V_15 -> V_17 < V_16 -> V_17 )
return - 1 ;
return 0 ;
}
static void
F_10 ( void ) {
F_2 ( V_3 == NULL ) ;
F_2 ( V_1 != NULL ) ;
F_11 ( V_1 , F_9 ) ;
V_3 = F_12 ( ( V_2 * ) ( void * ) V_1 -> V_6 ,
V_1 -> V_7 + 1 ,
L_1 ) ;
}
static T_4
F_13 ( T_5 V_18 )
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
F_14 ( const char * V_38 )
{
T_6 * V_39 ;
V_39 = F_15 ( V_38 , L_2 ) ;
if ( V_39 != NULL ) {
char line [ 256 ] ;
while ( fgets ( line , sizeof line , V_39 ) != NULL ) {
int V_10 ;
T_7 V_40 , V_41 ;
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
F_7 ( V_10 ,
F_16 ( L_5 V_42 L_6 , & line [ V_41 + 1 ] ) ) ;
}
fclose ( V_39 ) ;
}
}
static void
F_17 ( const char * V_43 )
{
T_8 * V_44 ;
T_9 * V_45 ;
const char * V_46 ;
char * V_38 ;
T_10 * V_47 = NULL ;
if( V_48 != NULL ) {
F_5 ( V_48 ) ;
V_48 = NULL ;
}
F_4 () ;
if ( ( V_43 == NULL ) || ( V_43 [ 0 ] == '\0' ) )
return;
if ( ( V_44 = F_18 ( V_43 , 0 , & V_47 ) ) != NULL ) {
F_1 () ;
V_48 = F_19 ( V_43 ) ;
while ( ( V_45 = F_20 ( V_44 ) ) != NULL ) {
V_46 = F_21 ( V_45 ) ;
if ( F_22 ( V_45 , L_7 ) ) {
V_38 =
F_16 ( L_8 V_49 L_8 , V_43 ,
V_46 ) ;
F_14 ( V_38 ) ;
F_5 ( V_38 ) ;
}
}
F_23 ( V_44 ) ;
F_10 () ;
} else{
F_24 ( L_8 , V_47 -> V_50 ) ;
F_25 ( V_47 ) ;
}
}
static T_5
F_26 ( unsigned int * V_51 , T_11 * V_52 , T_12 * V_53 )
{
T_13 V_54 ;
const V_8 * V_55 ;
V_54 = F_27 ( V_52 , * V_51 ) ;
V_55 = F_28 ( V_54 , V_56 , L_9 ) ;
F_29 ( V_53 , V_52 , * V_51 , 1 , L_8 , V_55 ) ;
( * V_51 ) ++ ;
return V_54 ;
}
static void
F_30 ( unsigned int * V_51 , T_11 * V_52 , T_12 * V_53 )
{
T_13 V_54 ;
V_54 = F_27 ( V_52 , * V_51 ) ;
F_26 ( V_51 , V_52 , V_53 ) ;
if ( V_54 == V_36 ) {
F_26 ( V_51 , V_52 , V_53 ) ;
F_31 ( V_53 , V_57 , V_52 , * V_51 , 4 ,
V_58 ) ;
( * V_51 ) += 4 ;
}
}
static T_13
F_32 ( unsigned int * V_51 , T_11 * V_52 , T_12 * V_53 )
{
T_13 V_40 ;
int V_59 ;
T_5 V_60 ;
V_60 = F_27 ( V_52 , * V_51 ) ;
if ( V_60 <= V_25
|| V_60 >= V_24 ) {
V_40 = V_60 ;
V_59 = 1 ;
} else {
T_5 V_54 ;
V_54 = F_26 ( V_51 , V_52 , V_53 ) ;
V_59 = F_13 ( V_54 ) ;
switch ( V_59 ) {
case 1 :
V_40 = F_27 ( V_52 , * V_51 ) ;
break;
case 2 :
V_40 = F_33 ( V_52 , * V_51 ) ;
break;
case 4 :
V_40 = F_34 ( V_52 , * V_51 ) ;
break;
default:
return 0 ;
}
}
F_31 ( V_53 , V_61 , V_52 , * V_51 ,
V_59 , V_58 ) ;
( * V_51 ) += V_59 ;
return V_40 ;
}
static void
F_35 ( unsigned int * V_51 , T_11 * V_52 , T_12 * V_53 )
{
int V_40 ;
F_26 ( V_51 , V_52 , V_53 ) ;
F_30 ( V_51 , V_52 , V_53 ) ;
F_31 ( V_53 , V_62 , V_52 , * V_51 , 1 , V_63 ) ;
( * V_51 ) ++ ;
V_40 = F_32 ( V_51 , V_52 , V_53 ) ;
for (; V_40 > 0 ; V_40 -- ) {
F_36 ( V_51 , V_52 , V_53 , V_57 ) ;
}
F_26 ( V_51 , V_52 , V_53 ) ;
}
static void
F_37 ( unsigned int * V_51 , T_11 * V_52 , T_12 * V_53 )
{
int V_40 ;
F_26 ( V_51 , V_52 , V_53 ) ;
V_40 = F_32 ( V_51 , V_52 , V_53 ) ;
F_31 ( V_53 , V_64 , V_52 , * V_51 , V_40 ,
V_63 ) ;
( * V_51 ) += V_40 ;
}
static void
F_38 ( unsigned int * V_51 , T_11 * V_52 , T_12 * V_53 )
{
int V_65 ;
F_26 ( V_51 , V_52 , V_53 ) ;
V_65 = F_32 ( V_51 , V_52 , V_53 ) ;
F_31 ( V_53 , V_66 , V_52 , * V_51 ,
V_65 , V_67 | V_63 ) ;
( * V_51 ) += V_65 ;
}
static void
F_39 ( unsigned int * V_51 , T_11 * V_52 , T_12 * V_53 ,
int V_68 , T_5 V_54 )
{
int V_65 ;
F_26 ( V_51 , V_52 , V_53 ) ;
V_65 = F_13 ( V_54 ) ;
if ( V_65 > 0 ) {
T_14 * V_69 ;
const V_8 * V_11 = NULL ;
T_13 V_10 = 0 ;
V_70 = F_40 ( L_10 ) ;
if ( V_65 == 4 ) {
V_10 = F_34 ( V_52 , * V_51 ) ;
V_11 = F_41 ( V_10 , V_3 ) ;
if( V_11 != NULL ) {
V_68 = V_71 ;
V_72 = TRUE ;
F_42 ( V_70 , L_8 , V_11 ) ;
}
}
V_69 = F_31 ( V_53 , V_68 , V_52 , * V_51 ,
V_65 , V_58 ) ;
* V_51 += V_65 ;
if ( V_11 != NULL ) {
F_43 ( V_69 , L_11 , V_10 , V_11 ) ;
}
}
}
static int
F_36 ( unsigned int * V_51 , T_11 * V_52 , T_12 * V_53 ,
int V_68 )
{
T_5 V_54 ;
V_54 = F_27 ( V_52 , * V_51 ) ;
if ( V_54 <= V_25 ||
V_54 >= V_24 ) {
F_31 ( V_53 , V_68 , V_52 , * V_51 , 1 , V_58 ) ;
( * V_51 ) ++ ;
return V_54 ;
}
switch( V_54 ) {
case V_36 :
F_44 ( V_51 , V_52 , V_53 , 1 ) ;
break;
case V_33 :
F_35 ( V_51 , V_52 , V_53 ) ;
break;
case V_34 :
F_38 ( V_51 , V_52 , V_53 ) ;
break;
case V_29 :
F_39 ( V_51 , V_52 , V_53 , V_73 , V_54 ) ;
break;
case V_31 :
F_39 ( V_51 , V_52 , V_53 , V_74 , V_54 ) ;
break;
case V_27 :
F_39 ( V_51 , V_52 , V_53 , V_75 , V_54 ) ;
break;
case V_28 :
F_39 ( V_51 , V_52 , V_53 , V_76 , V_54 ) ;
break;
case V_30 :
F_39 ( V_51 , V_52 , V_53 , V_77 , V_54 ) ;
break;
case V_26 :
F_39 ( V_51 , V_52 , V_53 , V_78 , V_54 ) ;
break;
case V_32 :
F_37 ( V_51 , V_52 , V_53 ) ;
break;
default:
F_39 ( V_51 , V_52 , V_53 , V_68 , V_54 ) ;
}
return 0 ;
}
static void
F_44 ( unsigned int * V_51 , T_11 * V_52 , T_12 * V_53 ,
int V_79 )
{
T_14 * V_69 ;
T_12 * V_80 ;
int V_40 ;
int V_5 ;
V_69 = F_31 ( V_53 , V_81 , V_52 , * V_51 ,
F_45 ( V_52 ) - * V_51 , V_63 ) ;
V_80 = F_46 ( V_69 , V_82 ) ;
if ( V_79 ) {
F_26 ( V_51 , V_52 , V_80 ) ;
}
F_36 ( V_51 , V_52 , V_80 , V_57 ) ;
V_40 = F_36 ( V_51 , V_52 , V_80 , V_61 ) ;
for ( V_5 = 0 ; V_5 < V_40 ; V_5 ++ ) {
F_47 ( V_51 , V_52 , V_80 ) ;
}
F_26 ( V_51 , V_52 , V_80 ) ;
}
static void
F_47 ( unsigned int * V_51 , T_11 * V_52 , T_12 * V_53 )
{
T_12 * V_80 ;
T_12 * V_83 ;
T_14 * V_69 , * V_84 ;
V_72 = FALSE ;
V_84 =
F_31 ( V_53 , V_85 , V_52 , * V_51 , 1 ,
V_63 ) ;
V_83 = V_80 =
F_46 ( V_84 , V_86 ) ;
V_69 = F_31 ( V_80 , V_87 , V_52 , * V_51 , 0 ,
V_63 ) ;
V_80 = F_46 ( V_69 , V_88 ) ;
F_36 ( V_51 , V_52 , V_80 , V_57 ) ;
if( V_72 == TRUE ) {
F_43 ( V_84 , L_12 ) ;
F_43 ( V_84 , L_8 , V_70 -> V_89 ) ;
F_43 ( V_84 , L_13 ) ;
}
V_69 = F_31 ( V_83 , V_90 , V_52 , * V_51 ,
0 , V_63 ) ;
V_80 = F_46 ( V_69 , V_91 ) ;
F_36 ( V_51 , V_52 , V_80 , V_57 ) ;
}
static T_15 *
F_48 ( T_11 * V_52 )
{
int V_92 ;
T_5 V_54 ;
T_15 * V_93 ;
int V_94 = 0 ;
V_93 = F_40 ( L_10 ) ;
V_94 += ( 4 + 4 + 1 ) ;
V_54 = F_27 ( V_52 , V_94 ) ;
V_92 = F_13 ( V_54 ) ;
V_94 ++ ;
if ( V_92 == 4 ) {
const V_8 * V_11 ;
T_13 V_10 ;
V_10 = F_34 ( V_52 , V_94 ) ;
V_11 = F_41 ( V_10 , V_3 ) ;
if ( V_11 != NULL ) {
F_42 ( V_93 , L_14 , V_11 ) ;
}
}
return V_93 ;
}
static void
F_49 ( T_11 * V_52 , T_16 * V_95 , T_12 * V_96 )
{
T_15 * V_97 = NULL ;
if ( V_95 -> V_98 || V_96 ) {
V_97 = F_48 ( V_52 ) ;
}
if ( V_95 -> V_98 ) {
F_50 ( V_95 -> V_98 , V_99 , L_15 ) ;
V_100 ++ ;
if ( V_95 -> V_101 -> V_102 != V_103 ) {
F_51 ( V_95 -> V_98 , V_104 ) ;
V_100 = 0 ;
}
V_103 = V_95 -> V_101 -> V_102 ;
F_52 ( V_95 -> V_98 , 1 ) ;
F_53 ( V_95 -> V_98 , V_104 , L_16 , V_97 -> V_89 ) ;
}
if ( V_96 ) {
unsigned int V_51 ;
T_14 * V_69 ;
T_12 * V_53 ;
V_69 = F_54 ( V_96 , V_105 , V_52 , 0 , - 1 ,
L_17 , V_97 -> V_89 ) ;
V_51 = 9 ;
V_53 = F_46 ( V_69 , V_106 ) ;
F_31 ( V_53 , V_107 , V_52 , 0 , 4 , V_58 ) ;
F_31 ( V_53 , V_61 , V_52 , 4 , 4 , V_58 ) ;
F_31 ( V_53 , V_108 , V_52 , 8 , 1 , V_63 ) ;
F_44 ( & V_51 , V_52 , V_53 , 0 ) ;
}
}
static T_1
F_55 ( T_16 * V_95 V_109 , T_11 * V_52 , int V_51 )
{
return F_34 ( V_52 , V_51 + 4 ) + 8 ;
}
static int
F_56 ( T_11 * V_52 , T_16 * V_95 , T_12 * V_96 )
{
if ( F_45 ( V_52 ) < 4 ) {
return 0 ;
}
if ( F_57 ( V_52 , 0 , V_110 , 4 ) == - 1 ) {
return 0 ;
}
F_58 ( V_52 , V_95 , V_96 , TRUE , 8 , F_55 ,
F_49 ) ;
if ( V_100 > 0 ) {
F_52 ( V_95 -> V_98 , 1 ) ;
F_59 ( V_95 -> V_98 , V_104 , L_18 , V_100 + 1 ) ;
}
return 1 ;
}
static void
F_60 ( void )
{
V_100 = 0 ;
V_103 = 0xFFFFFFFF ;
}
void F_61 ( void )
{
T_17 * V_111 ;
static T_18 V_112 [] = {
{ & V_107 ,
{ L_19 , L_20 ,
V_113 , V_114 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_61 ,
{ L_21 , L_22 ,
V_116 , V_117 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_62 ,
{ L_23 , L_24 ,
V_118 , V_117 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_108 ,
{ L_25 , L_26 ,
V_118 , V_117 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_119 ,
{ L_27 , L_28 ,
V_120 , V_121 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_57 ,
{ L_29 , L_30 ,
V_116 , V_117 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_64 ,
{ L_31 , L_32 ,
V_122 , V_121 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_78 ,
{ L_33 , L_34 ,
V_123 , V_117 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_75 ,
{ L_35 , L_36 ,
V_124 , V_117 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_76 ,
{ L_37 , L_38 ,
V_125 , V_117 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_77 ,
{ L_39 , L_40 ,
V_126 , V_117 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_73 ,
{ L_41 , L_42 ,
V_127 , V_121 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_74 ,
{ L_43 , L_44 ,
V_128 , V_121 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_85 ,
{ L_45 , L_46 ,
V_129 , V_121 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_130 ,
{ L_47 , L_48 ,
V_122 , V_121 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_71 ,
{ L_49 , L_50 ,
V_113 , V_114 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_81 ,
{ L_51 , L_52 ,
V_122 , V_121 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_66 ,
{ L_53 , L_54 ,
V_120 , V_121 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_87 ,
{ L_47 , L_55 ,
V_129 , V_121 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
{ & V_90 ,
{ L_56 , L_57 ,
V_129 , V_121 ,
NULL , 0x0 ,
NULL , V_115 }
} ,
} ;
static T_2 * V_131 [] = {
& V_106 ,
& V_82 ,
& V_86 ,
& V_88 ,
& V_91 ,
} ;
V_105 = F_62 ( L_58 ,
L_15 ,
L_59
) ;
F_63 ( V_105 , V_112 , F_64 ( V_112 ) ) ;
F_65 ( V_131 , F_64 ( V_131 ) ) ;
F_66 ( L_59 , F_56 , V_105 ) ;
F_67 ( & F_60 ) ;
V_111 = F_68 ( V_105 ,
V_132 ) ;
F_69 ( V_111 , L_60 ,
L_61 ,
L_62
L_63
L_64 ,
& V_133 ) ;
F_70 ( V_111 , L_65 ,
L_66 ,
L_67 ,
10 ,
& V_134 ) ;
}
void V_132 ( void )
{
static T_19 V_135 = FALSE ;
static T_20 V_136 ;
static T_1 V_137 = 0 ;
if( ! V_135 ) {
V_136 = F_71 ( F_56 , V_105 ) ;
F_72 ( L_68 , F_56 , V_105 ) ;
V_135 = TRUE ;
}
if( V_137 != 0 && V_137 != V_134 ) {
F_73 ( L_65 , V_137 , V_136 ) ;
}
if( V_134 != 0 && V_137 != V_134 ) {
F_74 ( L_65 , V_134 , V_136 ) ;
}
V_137 = V_134 ;
if( V_133 == NULL || V_48 == NULL ||
strcmp ( V_133 , V_48 ) != 0 ) {
F_17 ( V_133 ) ;
}
}
