static void
F_1 ( void )
{
F_2 ( V_1 == NULL ) ;
V_1 = F_3 ( TRUE , TRUE , sizeof( V_2 ) ) ;
}
static void
F_4 ( void )
{
F_5 ( F_6 () , V_3 ) ;
V_3 = NULL ;
if ( V_1 != NULL ) {
V_2 * V_4 ;
T_1 V_5 ;
V_4 = ( V_2 * ) ( void * ) V_1 -> V_6 ;
for ( V_5 = 0 ; V_5 < V_1 -> V_7 ; V_5 ++ ) {
F_7 ( ( V_8 * ) V_4 [ V_5 ] . V_9 ) ;
}
F_8 ( V_1 , TRUE ) ;
V_1 = NULL ;
}
}
static void
F_9 ( T_2 V_10 , V_8 * V_11 )
{
V_2 V_12 = { V_10 , V_11 } ;
F_2 ( V_1 != NULL ) ;
F_10 ( V_1 , V_12 ) ;
}
static T_3
F_11 ( T_4 V_13 , T_4 V_14 )
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
F_12 ( void )
{
F_2 ( V_3 == NULL ) ;
F_2 ( V_1 != NULL ) ;
F_13 ( V_1 , F_11 ) ;
V_3 = F_14 ( ( V_2 * ) ( void * ) V_1 -> V_6 ,
V_1 -> V_7 + 1 ,
L_1 ) ;
}
static T_5
F_15 ( T_6 V_18 )
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
F_16 ( const char * V_38 )
{
T_7 * V_39 ;
V_39 = F_17 ( V_38 , L_2 ) ;
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
F_9 ( V_10 ,
F_18 ( L_5 V_42 L_6 , & line [ V_41 + 1 ] ) ) ;
}
fclose ( V_39 ) ;
}
}
static void
F_19 ( const char * V_43 )
{
T_9 * V_44 ;
T_10 * V_45 ;
const char * V_46 ;
char * V_38 ;
T_11 * V_47 = NULL ;
if( V_48 != NULL ) {
F_7 ( V_48 ) ;
V_48 = NULL ;
}
F_4 () ;
if ( ( V_43 == NULL ) || ( V_43 [ 0 ] == '\0' ) )
return;
if ( ( V_44 = F_20 ( V_43 , 0 , & V_47 ) ) != NULL ) {
F_1 () ;
V_48 = F_21 ( V_43 ) ;
while ( ( V_45 = F_22 ( V_44 ) ) != NULL ) {
V_46 = F_23 ( V_45 ) ;
if ( F_24 ( V_45 , L_7 ) ) {
V_38 =
F_18 ( L_8 V_49 L_8 , V_43 ,
V_46 ) ;
F_16 ( V_38 ) ;
F_7 ( V_38 ) ;
}
}
F_25 ( V_44 ) ;
F_12 () ;
} else{
F_26 ( L_8 , V_47 -> V_50 ) ;
F_27 ( V_47 ) ;
}
}
static T_6
F_28 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
T_2 V_54 ;
const V_8 * V_55 ;
V_54 = F_29 ( V_52 , * V_51 ) ;
V_55 = F_30 ( V_54 , V_56 , L_9 ) ;
F_31 ( V_53 , V_52 , * V_51 , 1 , L_8 , V_55 ) ;
( * V_51 ) ++ ;
return V_54 ;
}
static void
F_32 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
T_2 V_54 ;
V_54 = F_29 ( V_52 , * V_51 ) ;
F_28 ( V_51 , V_52 , V_53 ) ;
if ( V_54 == V_36 ) {
F_28 ( V_51 , V_52 , V_53 ) ;
F_33 ( V_53 , V_57 , V_52 , * V_51 , 4 ,
V_58 ) ;
( * V_51 ) += 4 ;
}
}
static T_2
F_34 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
T_2 V_40 ;
int V_59 ;
T_6 V_60 ;
V_60 = F_29 ( V_52 , * V_51 ) ;
if ( V_60 <= V_25
|| V_60 >= V_24 ) {
V_40 = V_60 ;
V_59 = 1 ;
} else {
T_6 V_54 ;
V_54 = F_28 ( V_51 , V_52 , V_53 ) ;
V_59 = F_15 ( V_54 ) ;
switch ( V_59 ) {
case 1 :
V_40 = F_29 ( V_52 , * V_51 ) ;
break;
case 2 :
V_40 = F_35 ( V_52 , * V_51 ) ;
break;
case 4 :
V_40 = F_36 ( V_52 , * V_51 ) ;
break;
default:
return 0 ;
}
}
F_33 ( V_53 , V_61 , V_52 , * V_51 ,
V_59 , V_58 ) ;
( * V_51 ) += V_59 ;
if ( * V_51 + V_40 < * V_51 ) {
V_40 = F_37 ( V_52 , * V_51 ) ;
}
return V_40 ;
}
static void
F_38 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
int V_40 ;
F_28 ( V_51 , V_52 , V_53 ) ;
F_32 ( V_51 , V_52 , V_53 ) ;
F_33 ( V_53 , V_62 , V_52 , * V_51 , 1 , V_63 ) ;
( * V_51 ) ++ ;
V_40 = F_34 ( V_51 , V_52 , V_53 ) ;
for (; V_40 > 0 ; V_40 -- ) {
F_39 ( V_51 , V_52 , V_53 , V_57 ) ;
}
F_28 ( V_51 , V_52 , V_53 ) ;
}
static void
F_40 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
int V_40 ;
F_28 ( V_51 , V_52 , V_53 ) ;
V_40 = F_34 ( V_51 , V_52 , V_53 ) ;
F_33 ( V_53 , V_64 , V_52 , * V_51 , V_40 ,
V_63 ) ;
( * V_51 ) += V_40 ;
}
static void
F_41 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
int V_65 ;
F_28 ( V_51 , V_52 , V_53 ) ;
V_65 = F_34 ( V_51 , V_52 , V_53 ) ;
F_33 ( V_53 , V_66 , V_52 , * V_51 ,
V_65 , V_67 | V_63 ) ;
( * V_51 ) += V_65 ;
}
static void
F_42 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 ,
int V_68 , T_6 V_54 )
{
int V_65 ;
F_28 ( V_51 , V_52 , V_53 ) ;
V_65 = F_15 ( V_54 ) ;
if ( V_65 > 0 ) {
T_14 * V_69 ;
const V_8 * V_11 = NULL ;
T_2 V_10 = 0 ;
V_70 = F_43 ( F_44 () ) ;
if ( V_65 == 4 ) {
V_10 = F_36 ( V_52 , * V_51 ) ;
V_11 = F_45 ( V_10 , V_3 ) ;
if( V_11 != NULL ) {
V_68 = V_71 ;
V_72 = TRUE ;
F_46 ( V_70 , L_8 , V_11 ) ;
}
}
V_69 = F_33 ( V_53 , V_68 , V_52 , * V_51 ,
V_65 , V_58 ) ;
* V_51 += V_65 ;
if ( V_11 != NULL ) {
F_47 ( V_69 , L_10 , V_10 , V_11 ) ;
}
}
}
static int
F_39 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 ,
int V_68 )
{
T_6 V_54 ;
V_54 = F_29 ( V_52 , * V_51 ) ;
if ( V_54 <= V_25 ||
V_54 >= V_24 ) {
F_33 ( V_53 , V_68 , V_52 , * V_51 , 1 , V_58 ) ;
( * V_51 ) ++ ;
return V_54 ;
}
switch( V_54 ) {
case V_36 :
F_48 ( V_51 , V_52 , V_53 , 1 ) ;
break;
case V_33 :
F_38 ( V_51 , V_52 , V_53 ) ;
break;
case V_34 :
F_41 ( V_51 , V_52 , V_53 ) ;
break;
case V_29 :
F_42 ( V_51 , V_52 , V_53 , V_73 , V_54 ) ;
break;
case V_31 :
F_42 ( V_51 , V_52 , V_53 , V_74 , V_54 ) ;
break;
case V_27 :
F_42 ( V_51 , V_52 , V_53 , V_75 , V_54 ) ;
break;
case V_28 :
F_42 ( V_51 , V_52 , V_53 , V_76 , V_54 ) ;
break;
case V_30 :
F_42 ( V_51 , V_52 , V_53 , V_77 , V_54 ) ;
break;
case V_26 :
F_42 ( V_51 , V_52 , V_53 , V_78 , V_54 ) ;
break;
case V_32 :
F_40 ( V_51 , V_52 , V_53 ) ;
break;
default:
F_42 ( V_51 , V_52 , V_53 , V_68 , V_54 ) ;
}
return 0 ;
}
static void
F_48 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 ,
int V_79 )
{
T_14 * V_69 ;
T_13 * V_80 ;
int V_40 ;
int V_5 ;
V_69 = F_33 ( V_53 , V_81 , V_52 , * V_51 ,
F_49 ( V_52 ) - * V_51 , V_63 ) ;
V_80 = F_50 ( V_69 , V_82 ) ;
if ( V_79 ) {
F_28 ( V_51 , V_52 , V_80 ) ;
}
F_39 ( V_51 , V_52 , V_80 , V_57 ) ;
V_40 = F_39 ( V_51 , V_52 , V_80 , V_61 ) ;
for ( V_5 = 0 ; V_5 < V_40 ; V_5 ++ ) {
F_51 ( V_51 , V_52 , V_80 ) ;
}
F_28 ( V_51 , V_52 , V_80 ) ;
}
static void
F_51 ( unsigned int * V_51 , T_12 * V_52 , T_13 * V_53 )
{
T_13 * V_80 ;
T_13 * V_83 ;
T_14 * V_69 , * V_84 ;
V_72 = FALSE ;
V_84 =
F_33 ( V_53 , V_85 , V_52 , * V_51 , 1 ,
V_63 ) ;
V_83 = V_80 =
F_50 ( V_84 , V_86 ) ;
V_69 = F_33 ( V_80 , V_87 , V_52 , * V_51 , 0 ,
V_63 ) ;
V_80 = F_50 ( V_69 , V_88 ) ;
F_39 ( V_51 , V_52 , V_80 , V_57 ) ;
if( V_72 == TRUE ) {
F_47 ( V_84 , L_11 ) ;
F_47 ( V_84 , L_8 , F_52 ( V_70 ) ) ;
F_47 ( V_84 , L_12 ) ;
}
V_69 = F_33 ( V_83 , V_89 , V_52 , * V_51 ,
0 , V_63 ) ;
V_80 = F_50 ( V_69 , V_90 ) ;
F_39 ( V_51 , V_52 , V_80 , V_57 ) ;
}
static T_15 *
F_53 ( T_12 * V_52 )
{
int V_91 ;
T_6 V_54 ;
T_15 * V_92 ;
int V_93 = 0 ;
V_92 = F_43 ( F_44 () ) ;
V_93 += ( 4 + 4 + 1 ) ;
V_54 = F_29 ( V_52 , V_93 ) ;
V_91 = F_15 ( V_54 ) ;
V_93 ++ ;
if ( V_91 == 4 ) {
const V_8 * V_11 ;
T_2 V_10 ;
V_10 = F_36 ( V_52 , V_93 ) ;
V_11 = F_45 ( V_10 , V_3 ) ;
if ( V_11 != NULL ) {
F_46 ( V_92 , L_13 , V_11 ) ;
}
}
return V_92 ;
}
static void
F_54 ( T_12 * V_52 , T_16 * V_94 , T_13 * V_95 )
{
T_15 * V_96 = NULL ;
if ( V_94 -> V_97 || V_95 ) {
V_96 = F_53 ( V_52 ) ;
}
if ( V_94 -> V_97 ) {
F_55 ( V_94 -> V_97 , V_98 , L_14 ) ;
V_99 ++ ;
if ( V_94 -> V_100 -> V_101 != V_102 ) {
F_56 ( V_94 -> V_97 , V_103 ) ;
V_99 = 0 ;
}
V_102 = V_94 -> V_100 -> V_101 ;
F_57 ( V_94 -> V_97 , TRUE ) ;
F_58 ( V_94 -> V_97 , V_103 , L_15 , F_52 ( V_96 ) ) ;
}
if ( V_95 ) {
unsigned int V_51 ;
T_14 * V_69 ;
T_13 * V_53 ;
V_69 = F_59 ( V_95 , V_104 , V_52 , 0 , - 1 ,
L_16 , F_52 ( V_96 ) ) ;
V_51 = 9 ;
V_53 = F_50 ( V_69 , V_105 ) ;
F_33 ( V_53 , V_106 , V_52 , 0 , 4 , V_58 ) ;
F_33 ( V_53 , V_61 , V_52 , 4 , 4 , V_58 ) ;
F_33 ( V_53 , V_107 , V_52 , 8 , 1 , V_63 ) ;
F_48 ( & V_51 , V_52 , V_53 , 0 ) ;
}
}
static T_1
F_60 ( T_16 * V_94 V_108 , T_12 * V_52 , int V_51 )
{
return F_36 ( V_52 , V_51 + 4 ) + 8 ;
}
static int
F_61 ( T_12 * V_52 , T_16 * V_94 , T_13 * V_95 , void * V_6 V_108 )
{
if ( F_49 ( V_52 ) < 4 ) {
return 0 ;
}
if ( F_62 ( V_52 , 0 , V_109 , 4 ) == - 1 ) {
return 0 ;
}
F_63 ( V_52 , V_94 , V_95 , TRUE , 8 , F_60 ,
F_54 ) ;
if ( V_99 > 0 ) {
F_57 ( V_94 -> V_97 , TRUE ) ;
F_64 ( V_94 -> V_97 , V_103 , L_17 , V_99 + 1 ) ;
}
return 1 ;
}
static void
F_65 ( void )
{
V_99 = 0 ;
V_102 = 0xFFFFFFFF ;
}
void F_66 ( void )
{
T_17 * V_110 ;
static T_18 V_111 [] = {
{ & V_106 ,
{ L_18 , L_19 ,
V_112 , V_113 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_61 ,
{ L_20 , L_21 ,
V_115 , V_116 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_62 ,
{ L_22 , L_23 ,
V_117 , V_116 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_107 ,
{ L_24 , L_25 ,
V_117 , V_116 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
#if 0
{&hf_etch_typecode,
{"Etch TypeCode", "etch.typecode",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL}
},
#endif
{ & V_57 ,
{ L_26 , L_27 ,
V_115 , V_116 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_64 ,
{ L_28 , L_29 ,
V_118 , V_119 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_78 ,
{ L_30 , L_31 ,
V_120 , V_116 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_75 ,
{ L_32 , L_33 ,
V_121 , V_116 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_76 ,
{ L_34 , L_35 ,
V_122 , V_116 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_77 ,
{ L_36 , L_37 ,
V_123 , V_116 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_73 ,
{ L_38 , L_39 ,
V_124 , V_119 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_74 ,
{ L_40 , L_41 ,
V_125 , V_119 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_85 ,
{ L_42 , L_43 ,
V_126 , V_119 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
#if 0
{&hf_etch_key,
{"Etch key", "etch.key",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL}
},
#endif
{ & V_71 ,
{ L_44 , L_45 ,
V_112 , V_113 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_81 ,
{ L_46 , L_47 ,
V_118 , V_119 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_66 ,
{ L_48 , L_49 ,
V_127 , V_119 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_87 ,
{ L_50 , L_51 ,
V_126 , V_119 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
{ & V_89 ,
{ L_52 , L_53 ,
V_126 , V_119 ,
NULL , 0x0 ,
NULL , V_114 }
} ,
} ;
static T_3 * V_128 [] = {
& V_105 ,
& V_82 ,
& V_86 ,
& V_88 ,
& V_90 ,
} ;
V_104 = F_67 ( L_54 ,
L_55 ,
L_56
) ;
F_68 ( V_104 , V_111 , F_69 ( V_111 ) ) ;
F_70 ( V_128 , F_69 ( V_128 ) ) ;
V_129 = F_71 ( L_56 , F_61 , V_104 ) ;
F_72 ( & F_65 ) ;
V_110 = F_73 ( V_104 ,
V_130 ) ;
F_74 ( V_110 , L_57 ,
L_58 ,
L_59
L_60
L_61 ,
& V_131 ) ;
F_75 ( V_110 , L_62 ,
L_63 ,
L_64 ,
10 ,
& V_132 ) ;
}
void V_130 ( void )
{
static T_19 V_133 = FALSE ;
static T_1 V_134 = 0 ;
if( ! V_133 ) {
F_76 ( L_65 , F_61 , V_104 ) ;
V_133 = TRUE ;
}
if( V_134 != 0 && V_134 != V_132 ) {
F_77 ( L_62 , V_134 , V_129 ) ;
}
if( V_132 != 0 && V_134 != V_132 ) {
F_78 ( L_62 , V_132 , V_129 ) ;
}
V_134 = V_132 ;
if( ( V_131 == NULL ) || ( V_48 == NULL ) ||
( strcmp ( V_131 , V_48 ) != 0 ) ) {
F_19 ( V_131 ) ;
}
}
