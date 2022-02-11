static void F_1 ( T_1 V_1 , T_2 * V_2 , T_3 * V_3 ,
T_1 * V_4 , T_4 * V_5 ) {
T_5 * V_6 = NULL ;
T_3 * V_7 = NULL ;
T_6 V_8 ;
T_7 V_9 ;
T_8 V_10 ;
T_9 V_11 ;
T_10 V_12 ;
T_1 V_13 , V_14 , V_15 , V_16 ;
T_4 * V_17 = NULL ;
V_6 = F_2 ( V_3 , V_18 ) ;
V_17 = & V_5 [ V_1 ] ;
while ( V_17 ) {
switch( V_17 -> V_19 ) {
case 1 : case 2 : case 3 : case 4 :
case 5 : case 6 : case 7 : case 8 :
if ( ( V_13 = V_17 -> V_20 ) ) {
V_13 = F_3 ( V_13 , F_4 ( V_2 , * V_4 ) ) ;
F_5 ( V_6 , V_17 -> V_21 ,
V_2 , * V_4 , V_13 , V_22 | V_23 ) ;
( * V_4 ) += V_13 ;
}
else {
V_12 = F_6 ( V_2 , * V_4 ) ;
if ( V_17 -> V_19 != 8 ) {
for ( V_14 = 0 , V_16 = 0x0 , V_15 = V_24 ;
V_14 < V_17 -> V_19 ;
V_14 ++ )
V_16 |= V_25 [ V_24 ++ ] ;
V_12 &= V_16 ;
V_12 >>= V_15 ;
}
if ( V_17 -> V_26 || V_17 -> V_19 != 8 ) {
F_7 ( V_6 , V_17 -> V_21 ,
V_2 , * V_4 , 1 , V_12 ) ;
}
else {
V_11 = ( T_9 ) V_12 ;
F_8 ( V_6 , V_17 -> V_21 ,
V_2 , * V_4 , 1 , V_11 ) ;
}
if ( ( V_24 == 0 ) || ( V_24 == 8 ) ) {
( * V_4 ) ++ ;
V_24 = 0 ;
}
}
break;
case 16 :
if ( V_17 -> V_26 ) {
V_10 = F_9 ( V_2 , * V_4 ) ;
F_7 ( V_6 , V_17 -> V_21 ,
V_2 , * V_4 , 2 , V_10 ) ;
}
else {
V_9 = F_9 ( V_2 , * V_4 ) ;
F_8 ( V_6 , V_17 -> V_21 ,
V_2 , * V_4 , 2 , V_9 ) ;
}
( * V_4 ) += 2 ;
break;
case 32 :
V_8 = F_10 ( V_2 , * V_4 ) ;
if ( V_17 -> V_26 ) {
V_7 = F_7 ( V_6 , V_17 -> V_21 ,
V_2 , * V_4 , 4 , V_8 ) ;
}
else {
V_7 = F_8 ( V_6 , V_17 -> V_21 ,
V_2 , * V_4 , 4 , V_8 ) ;
}
if ( V_17 -> V_27 ) {
F_11 ( V_7 , L_1 , F_12 ( V_2 , * V_4 ) ) ;
}
( * V_4 ) += 4 ;
break;
default:
break;
}
V_17 = V_17 -> V_28 ;
if ( F_4 ( V_2 , * V_4 ) <= 0 ) {
break;
}
}
}
static void F_13 ( T_1 V_29 , T_2 * V_2 ,
T_3 * V_3 , T_1 * V_4 ) {
switch ( V_29 ) {
default:
F_1 ( V_29 , V_2 , V_3 , V_4 , V_30 ) ;
break;
}
}
static void F_14 ( T_1 V_31 , T_2 * V_2 ,
T_3 * V_3 , T_1 * V_4 ) {
switch ( V_31 ) {
default:
F_1 ( V_31 , V_2 , V_3 , V_4 , V_32 ) ;
break;
}
}
static void F_15 ( T_2 * V_2 , T_11 * V_33 , T_5 * V_34 ) {
T_3 * V_3 = NULL , * V_35 = NULL ;
T_5 * V_36 = NULL ;
T_1 V_4 = 0 ;
T_12 V_37 , V_38 = 0 ;
T_8 V_39 , V_40 , V_41 , V_42 ;
T_13 * V_43 ;
V_41 = F_9 ( V_2 , 0 ) ;
V_40 = F_9 ( V_2 , 2 ) ;
V_39 = F_9 ( V_2 , 4 ) ;
V_42 = F_9 ( V_2 , 6 ) ;
V_37 = F_10 ( V_2 , 8 ) ;
if ( V_33 -> V_44 == V_45 )
V_38 = F_10 ( V_2 , 12 ) ;
F_16 ( V_33 -> V_46 , V_47 , L_2 ) ;
if ( V_33 -> V_44 == V_45 ) {
F_17 ( V_33 -> V_46 , V_48 ,
L_3 ,
F_18 ( V_37 , V_49 , L_4 ) ,
V_37 , V_39 , V_38 , V_40 , V_41 ) ;
} else {
F_17 ( V_33 -> V_46 , V_48 ,
L_5 ,
F_18 ( V_37 , V_50 , L_4 ) ,
V_37 , V_39 , V_40 , V_41 ) ;
}
if ( V_34 ) {
V_3 = F_5 ( V_34 , V_51 , V_2 , 0 , - 1 , V_22 ) ;
V_36 = F_2 ( V_3 , V_52 ) ;
F_7 ( V_36 , V_53 , V_2 , 0 , 2 , V_41 ) ;
F_7 ( V_36 , V_54 , V_2 , 2 , 2 , V_40 ) ;
F_7 ( V_36 , V_55 , V_2 , 4 , 2 , V_39 ) ;
F_7 ( V_36 , V_56 , V_2 , 6 , 2 , V_42 ) ;
if ( V_33 -> V_44 == V_45 ) {
if ( F_19 ( V_37 , V_49 ) ) {
F_7 ( V_36 , V_57 , V_2 , 8 , 4 , V_37 ) ;
F_8 ( V_36 , V_58 , V_2 , 12 , 4 , V_38 ) ;
V_4 += 16 ;
if ( V_30 [ V_37 ] . V_19 ) {
V_43 = F_20 ( F_21 () , L_6 ,
F_18 ( V_37 , V_49 , L_4 ) , V_37 ) ;
V_35 = F_22 ( V_34 , V_2 , V_4 , - 1 , L_7 , V_43 ) ;
F_13 ( V_37 , V_2 , V_35 , & V_4 ) ;
}
}
}
else {
if ( F_19 ( V_37 , V_50 ) ) {
F_7 ( V_36 , V_59 , V_2 , 8 , 4 , V_37 ) ;
V_4 += 12 ;
if ( V_32 [ V_37 ] . V_19 ) {
V_43 = F_20 ( F_21 () , L_8 ,
F_18 ( V_37 , V_50 , L_4 ) , V_37 ) ;
V_35 = F_22 ( V_34 , V_2 , V_4 , - 1 , L_7 , V_43 ) ;
F_14 ( V_37 , V_2 , V_35 , & V_4 ) ;
}
}
}
}
}
static T_14 F_23 ( T_11 * V_33 V_60 , T_2 * V_2 , T_1 V_4 ) {
T_8 V_61 ;
V_61 = F_9 ( V_2 , V_4 + 2 ) ;
V_61 += 4 ;
return V_61 ;
}
static void F_24 ( T_2 * V_2 , T_11 * V_33 , T_5 * V_34 ) {
if ( V_33 -> V_62 )
F_25 ( V_2 , V_33 , V_34 , V_63 , 4 , F_23 , F_15 ) ;
else
F_15 ( V_2 , V_33 , V_34 ) ;
}
static T_1 F_26 ( T_15 string [] , T_16 * V_64 ) {
T_1 V_65 = 0 , V_66 = 0 ;
T_13 * V_67 = NULL , * V_68 = NULL ;
V_68 = ( T_13 * ) F_27 ( V_69 ) ;
V_68 [ 0 ] = 0 ;
V_67 = ( T_13 * ) F_27 ( V_69 ) ;
V_67 [ 0 ] = 0 ;
while ( fgets ( V_68 , V_69 , V_64 ) != NULL ) {
if ( ! strncmp ( V_68 , L_9 , 5 ) ) {
break;
}
if ( sscanf ( V_68 , L_10 , V_67 , & V_66 ) == 2 ) {
string [ V_65 ] . V_70 = F_28 ( V_67 ) ;
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
static T_1 F_29 ( T_16 * V_64 ) {
T_1 V_65 = 0 , V_73 = 0 , V_74 = 0 ;
T_17 V_75 = TRUE ;
T_13 * V_68 = NULL , * V_76 = NULL ,
* V_77 = NULL , * V_78 = NULL ;
V_68 = ( T_13 * ) F_27 ( V_69 ) ;
V_68 [ 0 ] = 0 ;
V_76 = ( T_13 * ) F_27 ( V_69 ) ;
V_76 [ 0 ] = 0 ;
V_77 = ( T_13 * ) F_27 ( V_69 ) ;
V_77 [ 0 ] = 0 ;
V_78 = ( T_13 * ) F_27 ( V_69 ) ;
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
V_75 = FALSE ;
V_81 [ V_74 ] = F_28 ( V_76 ) ;
F_30 ( V_77 , V_76 , V_69 ) ;
}
V_79 [ V_74 ] [ V_65 ] . V_70 = F_28 ( V_78 ) ;
V_79 [ V_74 ] [ V_65 ] . V_71 = V_73 ;
if ( V_65 < ( V_82 - 1 ) ) {
V_65 ++ ;
}
else {
break;
}
}
}
if ( V_74 + 1 >= V_80 ) {
F_31 ( V_81 [ V_74 ] ) ;
V_81 [ V_74 ] = NULL ;
}
else {
V_81 [ V_74 + 1 ] = NULL ;
}
return 0 ;
}
static T_1 F_32 ( T_13 * V_76 ) {
T_1 V_74 = 0 ;
while ( V_81 [ V_74 ] ) {
if ( ! strcmp ( V_76 , V_81 [ V_74 ] ) )
return V_74 ;
V_74 ++ ;
}
return - 1 ;
}
static T_1 F_33 ( T_4 * V_5 , T_16 * V_64 ) {
static T_17 V_83 = FALSE ;
T_13 * V_84 = NULL , * V_85 = NULL , * V_86 = NULL ;
T_1 V_74 , V_1 , V_87 = - 1 ,
V_26 , V_19 ,
V_20 , V_27 ;
T_14 V_88 ;
T_4 * V_17 = NULL ;
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
#if 0
{
&hf_tpncp_old_event_seq_number,
{
"Sequence number",
"tpncp.old_event_seq_number",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
#endif
{
& V_56 ,
{
L_18 ,
L_19 ,
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
L_20 ,
L_21 ,
V_94 ,
V_92 ,
F_34 ( V_50 ) ,
0x0 ,
NULL , V_93
}
} ,
#if 0
{
&hf_tpncp_old_command_id,
{
"Command ID",
"tpncp.old_command_id",
FT_UINT16,
BASE_DEC,
VALS(tpncp_commands_id_vals),
0x0,
NULL, HFILL
}
},
#endif
{
& V_57 ,
{
L_22 ,
L_23 ,
V_94 ,
V_92 ,
F_34 ( V_49 ) ,
0x0 ,
NULL , V_93
}
} ,
{
& V_58 ,
{
L_24 ,
L_25 ,
V_95 ,
V_92 ,
NULL ,
0x0 ,
NULL , V_93
}
}
} ;
V_84 = ( T_13 * ) F_27 ( V_69 ) ;
V_84 [ 0 ] = 0 ;
V_89 . V_96 . type = V_97 ;
V_89 . V_96 . V_98 = NULL ;
V_89 . V_96 . V_16 = 0x0 ;
V_89 . V_96 . V_99 = NULL ;
V_89 . V_96 . V_37 = 0 ;
V_89 . V_96 . V_100 = 0 ;
V_89 . V_96 . V_101 = V_102 ;
V_89 . V_96 . V_103 = NULL ;
V_89 . V_96 . V_104 = - 1 ;
if ( ! V_83 ) {
V_105 = V_106 + ( int ) F_35 ( V_90 ) - 1 ;
if ( ( V_107 = ( T_18 * ) F_36 ( V_107 , V_105 * sizeof( T_18 ) ) ) == NULL )
return ( - 1 ) ;
for ( V_88 = 0 ; V_88 < F_35 ( V_90 ) ; V_88 ++ ) {
memcpy ( V_107 + ( V_106 - 1 ) , V_90 + V_88 , sizeof( T_18 ) ) ;
V_106 ++ ;
}
V_83 = TRUE ;
}
else
V_106 ++ ;
while ( fgets ( V_84 , V_69 , V_64 ) != NULL ) {
if ( ! strncmp ( V_84 , L_9 , 5 ) ) {
V_106 -- ;
break;
}
V_89 . V_96 . V_108 = V_92 ;
if ( ( V_86 = strtok ( V_84 , L_26 ) ) == NULL )
continue;
V_1 = atoi ( V_86 ) ;
if ( ( V_85 = strtok ( NULL , L_26 ) ) == NULL )
continue;
if ( ( V_86 = strtok ( NULL , L_26 ) ) == NULL )
continue;
V_26 = atoi ( V_86 ) ;
if ( ( V_86 = strtok ( NULL , L_26 ) ) == NULL )
continue;
V_19 = atoi ( V_86 ) ;
if ( ( V_86 = strtok ( NULL , L_26 ) ) == NULL )
continue;
V_20 = atoi ( V_86 ) ;
if ( ( V_86 = strtok ( NULL , L_26 ) ) == NULL )
continue;
V_27 = atoi ( V_86 ) ;
if ( ( V_86 = strtok ( NULL , L_27 ) ) == NULL )
continue;
if ( V_87 != V_1 ) {
V_17 = & V_5 [ V_1 ] ;
V_87 = V_1 ;
}
else {
if ( ( V_17 -> V_28 =
( T_4 * ) F_37 ( sizeof( T_4 ) ) )
== NULL )
return ( - 1 ) ;
V_17 = V_17 -> V_28 ;
}
if ( strcmp ( V_86 , L_28 ) ) {
V_74 = F_32 ( V_86 ) ;
if ( V_74 == - 1 ) {
V_89 . V_96 . V_98 = NULL ;
}
else {
V_89 . V_96 . V_98 = F_34 ( V_79 [ V_74 ] ) ;
}
}
else {
V_89 . V_96 . V_98 = NULL ;
}
V_17 -> V_21 = - 1 ;
V_89 . V_109 = & V_17 -> V_21 ;
V_17 -> V_85 = F_38 ( L_29 , V_85 ) ;
V_89 . V_96 . V_110 = V_17 -> V_85 ;
V_89 . V_96 . V_111 = V_17 -> V_85 ;
switch ( V_19 ) {
case 1 : case 2 : case 3 : case 4 :
case 5 : case 6 : case 7 : case 8 :
if ( V_20 ) {
V_89 . V_96 . type = V_112 ;
V_89 . V_96 . V_108 = V_113 ;
}
else
V_89 . V_96 . type = ( V_26 ) ? V_114 : V_115 ;
break;
case 16 :
V_89 . V_96 . type = ( V_26 ) ? V_91 : V_116 ;
break;
case 32 :
V_89 . V_96 . type = ( V_26 ) ? V_94 : V_95 ;
break;
default:
break;
}
if ( V_106 > V_105 ) {
V_105 += 1024 ;
if ( ( V_107 = ( T_18 * ) F_36 ( V_107 , V_105 * sizeof( T_18 ) ) ) == NULL )
return ( - 1 ) ;
}
memcpy ( V_107 + V_106 - 1 , & V_89 , sizeof( T_18 ) ) ;
V_106 ++ ;
V_17 -> V_26 = V_26 ;
V_17 -> V_19 = V_19 ;
V_17 -> V_20 = V_20 ;
V_17 -> V_27 = V_27 ;
}
return 0 ;
}
static T_1 F_39 ( void ) {
T_13 * V_117 ;
T_16 * V_64 ;
V_117 = F_40 ( L_7 V_118 L_30 V_118 L_31 , F_41 () ) ;
if ( ( V_64 = F_42 ( V_117 , L_32 ) ) == NULL )
return ( - 1 ) ;
F_26 ( V_49 , V_64 ) ;
F_26 ( V_50 , V_64 ) ;
F_29 ( V_64 ) ;
F_33 ( V_30 , V_64 ) ;
F_33 ( V_32 , V_64 ) ;
fclose ( V_64 ) ;
return 0 ;
}
void F_43 ( void ) {
static T_1 V_119 = FALSE ;
static T_19 V_120 ;
if ( V_51 == - 1 )
return;
if ( ! V_119 ) {
V_120 = F_44 ( F_24 , V_51 ) ;
V_119 = TRUE ;
}
else {
F_45 ( L_33 , V_121 , V_120 ) ;
F_45 ( L_34 , V_122 , V_123 ) ;
F_45 ( L_33 , V_124 , V_120 ) ;
F_45 ( L_34 , V_125 , V_123 ) ;
}
V_121 = V_126 ;
V_122 = V_127 ;
V_124 = V_128 ;
V_125 = V_129 ;
F_46 ( L_33 , V_126 , V_120 ) ;
F_46 ( L_34 , V_127 , V_123 ) ;
}
void F_47 ( void ) {
T_1 V_88 ;
T_20 * V_130 ;
static T_1 * V_131 [] = {
& V_52 ,
& V_18
} ;
if ( F_39 () == - 1 )
return;
V_51 = F_48 ( L_35 ,
L_2 , L_30 ) ;
F_49 {
for( V_88 = 0 ; V_88 < V_106 ; V_88 ++ ) {
F_50 ( V_51 , & V_107 [ V_88 ] , 1 ) ;
}
}
F_51 {
F_52 ( L_36 ) ;
}
V_132 ;
F_53 ( V_131 , F_35 ( V_131 ) ) ;
V_123 = F_54 ( L_30 , F_15 , V_51 ) ;
V_130 = F_55 ( V_51 , F_43 ) ;
F_56 ( V_130 , L_37 ,
L_38 ,
L_39 , 10 , & V_126 ) ;
F_56 ( V_130 , L_40 ,
L_41 ,
L_39 , 10 , & V_127 ) ;
}
