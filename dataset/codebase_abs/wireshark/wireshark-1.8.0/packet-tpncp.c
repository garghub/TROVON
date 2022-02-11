static void F_1 ( T_1 V_1 , T_2 * V_2 , T_3 * V_3 ,
T_1 * V_4 , T_4 * V_5 ) {
T_5 * V_6 = NULL ;
T_3 * V_7 = NULL ;
T_6 V_8 ;
T_7 V_9 ;
T_8 V_10 ;
T_9 V_11 ;
T_10 V_12 ;
T_11 * V_13 = NULL ;
T_1 V_14 , V_15 , V_16 , V_17 ;
T_4 * V_18 = NULL ;
V_6 = F_2 ( V_3 , V_19 ) ;
V_18 = & V_5 [ V_1 ] ;
while ( V_18 ) {
switch( V_18 -> V_20 ) {
case 1 : case 2 : case 3 : case 4 :
case 5 : case 6 : case 7 : case 8 :
if ( ( V_14 = V_18 -> V_21 ) ) {
V_14 = F_3 ( V_14 , F_4 ( V_2 , * V_4 ) ) ;
V_13 = F_5 ( V_14 ) ;
F_6 ( V_2 , V_13 , * V_4 , V_14 ) ;
V_13 [ V_14 - 1 ] = '\0' ;
F_7 ( V_6 , V_18 -> V_22 ,
V_2 , * V_4 , V_14 , V_13 ) ;
( * V_4 ) += V_14 ;
F_8 ( V_13 ) ;
}
else {
V_12 = F_9 ( V_2 , * V_4 ) ;
if ( V_18 -> V_20 != 8 ) {
for ( V_15 = 0 , V_17 = 0x0 , V_16 = V_23 ;
V_15 < V_18 -> V_20 ;
V_15 ++ )
V_17 |= V_24 [ V_23 ++ ] ;
V_12 &= V_17 ;
V_12 >>= V_16 ;
}
if ( V_18 -> V_25 || V_18 -> V_20 != 8 ) {
F_10 ( V_6 , V_18 -> V_22 ,
V_2 , * V_4 , 1 , V_12 ) ;
}
else {
V_11 = ( T_9 ) V_12 ;
F_11 ( V_6 , V_18 -> V_22 ,
V_2 , * V_4 , 1 , V_11 ) ;
}
if ( ( V_23 == 0 ) || ( V_23 == 8 ) ) {
( * V_4 ) ++ ;
V_23 = 0 ;
}
}
break;
case 16 :
if ( V_18 -> V_25 ) {
V_10 = F_12 ( V_2 , * V_4 ) ;
F_10 ( V_6 , V_18 -> V_22 ,
V_2 , * V_4 , 2 , V_10 ) ;
}
else {
V_9 = F_12 ( V_2 , * V_4 ) ;
F_11 ( V_6 , V_18 -> V_22 ,
V_2 , * V_4 , 2 , V_9 ) ;
}
( * V_4 ) += 2 ;
break;
case 32 :
V_8 = F_13 ( V_2 , * V_4 ) ;
if ( V_18 -> V_25 ) {
V_7 = F_10 ( V_6 , V_18 -> V_22 ,
V_2 , * V_4 , 4 , V_8 ) ;
}
else {
V_7 = F_11 ( V_6 , V_18 -> V_22 ,
V_2 , * V_4 , 4 , V_8 ) ;
}
if ( V_18 -> V_26 ) {
F_14 ( V_7 , L_1 , F_15 ( V_2 , * V_4 ) ) ;
}
( * V_4 ) += 4 ;
break;
default:
break;
}
V_18 = V_18 -> V_27 ;
if ( F_4 ( V_2 , * V_4 ) <= 0 ) {
break;
}
}
}
static void F_16 ( T_1 V_28 , T_2 * V_2 ,
T_3 * V_3 , T_1 * V_4 ) {
switch ( V_28 ) {
default:
F_1 ( V_28 , V_2 , V_3 , V_4 , V_29 ) ;
break;
}
}
static void F_17 ( T_1 V_30 , T_2 * V_2 ,
T_3 * V_3 , T_1 * V_4 ) {
switch ( V_30 ) {
default:
F_1 ( V_30 , V_2 , V_3 , V_4 , V_31 ) ;
break;
}
}
static void F_18 ( T_2 * V_2 , T_12 * V_32 , T_5 * V_33 ) {
T_3 * V_3 = NULL , * V_34 = NULL ;
T_5 * V_35 = NULL ;
T_1 V_4 = 0 ;
T_13 V_36 , V_37 = 0 ;
T_8 V_38 , V_39 , V_40 , V_41 ;
T_11 * V_42 ;
V_40 = F_12 ( V_2 , 0 ) ;
V_39 = F_12 ( V_2 , 2 ) ;
V_38 = F_12 ( V_2 , 4 ) ;
V_41 = F_12 ( V_2 , 6 ) ;
V_36 = F_13 ( V_2 , 8 ) ;
if ( V_32 -> V_43 == V_44 )
V_37 = F_13 ( V_2 , 12 ) ;
F_19 ( V_32 -> V_45 , V_46 , L_2 ) ;
if ( F_20 ( V_32 -> V_45 , V_47 ) ) {
if ( V_32 -> V_43 == V_44 ) {
F_21 ( V_32 -> V_45 , V_47 ,
L_3 ,
F_22 ( V_36 , V_48 , L_4 ) ,
V_36 , V_38 , V_37 , V_39 , V_40 ) ;
} else {
F_21 ( V_32 -> V_45 , V_47 ,
L_5 ,
F_22 ( V_36 , V_49 , L_4 ) ,
V_36 , V_38 , V_39 , V_40 ) ;
}
}
if ( V_33 ) {
V_3 = F_23 ( V_33 , V_50 , V_2 , 0 , - 1 , V_51 ) ;
V_35 = F_2 ( V_3 , V_52 ) ;
F_10 ( V_35 , V_53 , V_2 , 0 , 2 , V_40 ) ;
F_10 ( V_35 , V_54 , V_2 , 2 , 2 , V_39 ) ;
F_10 ( V_35 , V_55 , V_2 , 4 , 2 , V_38 ) ;
F_10 ( V_35 , V_56 , V_2 , 6 , 2 , V_41 ) ;
if ( V_32 -> V_43 == V_44 ) {
if ( F_24 ( V_36 , V_48 ) ) {
F_10 ( V_35 , V_57 , V_2 , 8 , 4 , V_36 ) ;
F_11 ( V_35 , V_58 , V_2 , 12 , 4 , V_37 ) ;
V_4 += 16 ;
if ( V_29 [ V_36 ] . V_20 ) {
V_42 = F_25 ( L_6 , F_22 ( V_36 , V_48 , L_4 ) , V_36 ) ;
V_34 = F_26 ( V_33 , V_2 , V_4 , - 1 , L_7 , V_42 ) ;
F_16 ( V_36 , V_2 , V_34 , & V_4 ) ;
}
}
}
else {
if ( F_24 ( V_36 , V_49 ) ) {
F_10 ( V_35 , V_59 , V_2 , 8 , 4 , V_36 ) ;
V_4 += 12 ;
if ( V_31 [ V_36 ] . V_20 ) {
V_42 = F_25 ( L_8 , F_22 ( V_36 , V_49 , L_4 ) , V_36 ) ;
V_34 = F_26 ( V_33 , V_2 , V_4 , - 1 , L_7 , V_42 ) ;
F_17 ( V_36 , V_2 , V_34 , & V_4 ) ;
}
}
}
}
}
static T_14 F_27 ( T_12 * V_32 V_60 , T_2 * V_2 , T_1 V_4 ) {
T_8 V_61 ;
V_61 = F_12 ( V_2 , V_4 + 2 ) ;
V_61 += 4 ;
return V_61 ;
}
static void F_28 ( T_2 * V_2 , T_12 * V_32 , T_5 * V_33 ) {
if ( V_32 -> V_62 )
F_29 ( V_2 , V_32 , V_33 , V_63 , 4 , F_27 , F_18 ) ;
else
F_18 ( V_2 , V_32 , V_33 ) ;
}
static T_1 F_30 ( T_15 string [] , T_16 * V_64 ) {
T_1 V_65 = 0 , V_66 = 0 ;
T_11 * V_67 = NULL , * V_68 = NULL ;
V_68 = F_31 ( V_69 ) ;
V_68 [ 0 ] = 0 ;
V_67 = F_31 ( V_69 ) ;
V_67 [ 0 ] = 0 ;
while ( fgets ( V_68 , V_69 , V_64 ) != NULL ) {
if ( ! strncmp ( V_68 , L_9 , 5 ) ) {
break;
}
if ( sscanf ( V_68 , L_10 , V_67 , & V_66 ) == 2 ) {
string [ V_65 ] . V_70 = F_32 ( V_67 ) ;
string [ V_65 ] . V_71 = V_66 ;
if ( V_65 < ( V_72 - 1 ) ) {
V_65 ++ ;
}
else {
break;
}
}
}
return 0 ;
}
static T_1 F_33 ( T_16 * V_64 ) {
T_1 V_65 = 0 , V_73 = 0 , V_74 = 0 , V_75 = 1 ;
T_11 * V_68 = NULL , * V_76 = NULL ,
* V_77 = NULL , * V_78 = NULL ;
V_68 = F_31 ( V_69 ) ;
V_68 [ 0 ] = 0 ;
V_76 = F_31 ( V_69 ) ;
V_76 [ 0 ] = 0 ;
V_77 = F_31 ( V_69 ) ;
V_77 [ 0 ] = 0 ;
V_78 = F_31 ( V_69 ) ;
V_78 [ 0 ] = 0 ;
while ( fgets ( V_68 , V_69 , V_64 ) != NULL ) {
if ( ! strncmp ( V_68 , L_9 , 5 ) ) {
break;
}
if ( sscanf ( V_68 , L_11 , V_76 , V_78 , & V_73 ) == 3 ) {
if ( strcmp ( V_77 , V_76 ) ) {
if ( ! V_75 ) {
V_79 [ V_74 ] [ V_65 ] . V_70 = NULL ;
V_79 [ V_74 ] [ V_65 ] . V_71 = 0 ;
if ( V_74 < ( V_80 - 1 ) ) {
V_74 ++ ; V_65 = 0 ;
}
else {
break;
}
}
else
V_75 = 0 ;
V_81 [ V_74 ] = F_32 ( V_76 ) ;
F_34 ( V_77 , V_76 , V_69 ) ;
}
V_79 [ V_74 ] [ V_65 ] . V_70 = F_32 ( V_78 ) ;
V_79 [ V_74 ] [ V_65 ] . V_71 = V_73 ;
if ( V_65 < ( V_82 - 1 ) ) {
V_65 ++ ;
}
else {
break;
}
}
}
return 0 ;
}
static T_1 F_35 ( T_11 * V_76 ) {
T_1 V_74 = 0 ;
while ( V_81 [ V_74 ] ) {
if ( ! strcmp ( V_76 , V_81 [ V_74 ] ) )
return V_74 ;
V_74 ++ ;
}
return - 1 ;
}
static T_1 F_36 ( T_4 * V_5 , T_16 * V_64 ) {
static T_17 V_83 = FALSE ;
T_11 * V_84 = NULL , * V_85 = NULL , * V_86 = NULL ;
T_1 V_74 , V_1 , V_87 = - 1 ,
V_25 , V_20 ,
V_21 , V_26 ;
T_14 V_88 ;
T_4 * V_18 = NULL ;
T_18 V_89 ;
static T_18 V_90 [] = {
{
& V_53 ,
{
L_12 ,
L_13 ,
V_91 ,
V_92 ,
NULL ,
0x0 ,
NULL , V_93
}
} ,
{
& V_54 ,
{
L_14 ,
L_15 ,
V_91 ,
V_92 ,
NULL ,
0x0 ,
NULL , V_93
}
} ,
{
& V_55 ,
{
L_16 ,
L_17 ,
V_91 ,
V_92 ,
NULL ,
0x0 ,
NULL , V_93
}
} ,
{
& V_94 ,
{
L_16 ,
L_18 ,
V_95 ,
V_92 ,
NULL ,
0x0 ,
NULL , V_93
}
} ,
{
& V_56 ,
{
L_19 ,
L_20 ,
V_91 ,
V_92 ,
NULL ,
0x0 ,
NULL , V_93
}
} ,
{
& V_59 ,
{
L_21 ,
L_22 ,
V_95 ,
V_92 ,
F_37 ( V_49 ) ,
0x0 ,
NULL , V_93
}
} ,
{
& V_96 ,
{
L_21 ,
L_23 ,
V_91 ,
V_92 ,
F_37 ( V_49 ) ,
0x0 ,
NULL , V_93
}
} ,
{
& V_57 ,
{
L_24 ,
L_25 ,
V_95 ,
V_92 ,
F_37 ( V_48 ) ,
0x0 ,
NULL , V_93
}
} ,
{
& V_58 ,
{
L_26 ,
L_27 ,
V_97 ,
V_92 ,
NULL ,
0x0 ,
NULL , V_93
}
}
} ;
V_84 = F_31 ( V_69 ) ;
V_84 [ 0 ] = 0 ;
V_89 . V_98 . type = 0 ;
V_89 . V_98 . V_99 = NULL ;
V_89 . V_98 . V_17 = 0x0 ;
V_89 . V_98 . V_100 = NULL ;
V_89 . V_98 . V_36 = 0 ;
V_89 . V_98 . V_101 = 0 ;
V_89 . V_98 . V_102 = V_103 ;
V_89 . V_98 . V_16 = 0 ;
V_89 . V_98 . V_104 = NULL ;
V_89 . V_98 . V_105 = NULL ;
if ( ! V_83 ) {
V_106 = V_107 + F_38 ( V_90 ) - 1 ;
if ( ( V_108 = ( T_18 * ) F_39 ( V_108 , V_106 * sizeof( T_18 ) ) ) == NULL )
return ( - 1 ) ;
for ( V_88 = 0 ; V_88 < F_38 ( V_90 ) ; V_88 ++ ) {
memcpy ( V_108 + ( V_107 - 1 ) , V_90 + V_88 , sizeof( T_18 ) ) ;
V_107 ++ ;
}
V_83 = TRUE ;
}
else
V_107 ++ ;
while ( fgets ( V_84 , V_69 , V_64 ) != NULL ) {
if ( ! strncmp ( V_84 , L_9 , 5 ) ) {
V_107 -- ;
break;
}
V_89 . V_98 . V_109 = V_92 ;
if ( ( V_86 = strtok ( V_84 , L_28 ) ) == NULL )
continue;
V_1 = atoi ( V_86 ) ;
if ( ( V_85 = strtok ( NULL , L_28 ) ) == NULL )
continue;
if ( ( V_86 = strtok ( NULL , L_28 ) ) == NULL )
continue;
V_25 = atoi ( V_86 ) ;
if ( ( V_86 = strtok ( NULL , L_28 ) ) == NULL )
continue;
V_20 = atoi ( V_86 ) ;
if ( ( V_86 = strtok ( NULL , L_28 ) ) == NULL )
continue;
V_21 = atoi ( V_86 ) ;
if ( ( V_86 = strtok ( NULL , L_28 ) ) == NULL )
continue;
V_26 = atoi ( V_86 ) ;
if ( ( V_86 = strtok ( NULL , L_29 ) ) == NULL )
continue;
if ( V_87 != V_1 ) {
V_18 = & V_5 [ V_1 ] ;
V_87 = V_1 ;
}
else {
if ( ( V_18 -> V_27 =
( T_4 * ) F_40 ( sizeof( T_4 ) ) )
== NULL )
return ( - 1 ) ;
V_18 = V_18 -> V_27 ;
}
if ( strcmp ( V_86 , L_30 ) ) {
V_74 = F_35 ( V_86 ) ;
if ( V_74 == - 1 ) {
V_89 . V_98 . V_99 = NULL ;
}
else {
V_89 . V_98 . V_99 = F_37 ( V_79 [ V_74 ] ) ;
}
}
else {
V_89 . V_98 . V_99 = NULL ;
}
V_18 -> V_22 = - 1 ;
V_89 . V_110 = & V_18 -> V_22 ;
V_18 -> V_85 = F_41 ( L_31 , V_85 ) ;
V_89 . V_98 . V_111 = V_18 -> V_85 ;
V_89 . V_98 . V_112 = V_18 -> V_85 ;
switch ( V_20 ) {
case 1 : case 2 : case 3 : case 4 :
case 5 : case 6 : case 7 : case 8 :
if ( V_21 ) {
V_89 . V_98 . type = V_113 ;
V_89 . V_98 . V_109 = V_114 ;
}
else
V_89 . V_98 . type = ( V_25 ) ? V_115 : V_116 ;
break;
case 16 :
V_89 . V_98 . type = ( V_25 ) ? V_91 : V_117 ;
break;
case 32 :
V_89 . V_98 . type = ( V_25 ) ? V_95 : V_97 ;
break;
default:
break;
}
if ( V_107 > V_106 ) {
V_106 += 1024 ;
if ( ( V_108 = ( T_18 * ) F_39 ( V_108 , V_106 * sizeof( T_18 ) ) ) == NULL )
return ( - 1 ) ;
}
memcpy ( V_108 + V_107 - 1 , & V_89 , sizeof( T_18 ) ) ;
V_107 ++ ;
V_18 -> V_25 = V_25 ;
V_18 -> V_20 = V_20 ;
V_18 -> V_21 = V_21 ;
V_18 -> V_26 = V_26 ;
}
return 0 ;
}
static T_1 F_42 ( void ) {
T_11 * V_118 ;
T_16 * V_64 ;
V_118 = F_25 ( L_7 V_119 L_32 V_119 L_33 , F_43 () ) ;
if ( ( V_64 = F_44 ( V_118 , L_34 ) ) == NULL )
return ( - 1 ) ;
F_30 ( V_48 , V_64 ) ;
F_30 ( V_49 , V_64 ) ;
F_33 ( V_64 ) ;
F_36 ( V_29 , V_64 ) ;
F_36 ( V_31 , V_64 ) ;
fclose ( V_64 ) ;
return 0 ;
}
void F_45 ( void ) {
static T_1 V_120 = FALSE ;
static T_19 V_121 , V_122 ;
if ( V_50 == - 1 )
return;
if ( ! V_120 ) {
V_121 = F_46 ( F_18 , V_50 ) ;
V_122 = F_46 ( F_28 , V_50 ) ;
V_120 = TRUE ;
}
else {
F_47 ( L_35 , V_123 , V_122 ) ;
F_47 ( L_36 , V_124 , V_121 ) ;
F_47 ( L_35 , V_125 , V_122 ) ;
F_47 ( L_36 , V_126 , V_121 ) ;
}
V_123 = V_127 ;
V_124 = V_128 ;
V_125 = V_129 ;
V_126 = V_130 ;
F_48 ( L_35 , V_127 , V_122 ) ;
F_48 ( L_36 , V_128 , V_121 ) ;
}
void F_49 ( void ) {
T_1 V_88 ;
T_20 * V_131 ;
static T_1 * V_132 [] = {
& V_52 ,
& V_19
} ;
if ( F_42 () == - 1 )
return;
V_50 = F_50 ( L_37 ,
L_2 , L_32 ) ;
for( V_88 = 0 ; V_88 < V_107 ; V_88 ++ ) {
F_51 ( V_50 , & V_108 [ V_88 ] , 1 ) ;
}
F_52 ( V_132 , F_38 ( V_132 ) ) ;
F_53 ( L_32 , F_18 , V_50 ) ;
V_131 = F_54 ( V_50 , F_45 ) ;
F_55 ( V_131 , L_38 ,
L_39 ,
L_40 , 10 , & V_127 ) ;
F_55 ( V_131 , L_41 ,
L_42 ,
L_40 , 10 , & V_128 ) ;
}
