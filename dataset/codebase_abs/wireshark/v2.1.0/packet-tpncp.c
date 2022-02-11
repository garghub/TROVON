static void F_1 ( T_1 V_1 , T_2 * V_2 , T_3 * V_3 ,
T_1 * V_4 , T_4 * V_5 ) {
T_5 * V_6 = NULL ;
T_6 V_7 ;
T_7 V_8 ;
T_8 V_9 ;
T_9 V_10 ;
T_10 V_11 ;
T_1 V_12 , V_13 , V_14 , V_15 ;
T_4 * V_16 = NULL ;
V_16 = & V_5 [ V_1 ] ;
while ( V_16 ) {
switch( V_16 -> V_17 ) {
case 1 : case 2 : case 3 : case 4 :
case 5 : case 6 : case 7 : case 8 :
if ( ( V_12 = V_16 -> V_18 ) ) {
V_12 = F_2 ( V_12 , F_3 ( V_2 , * V_4 ) ) ;
F_4 ( V_3 , V_16 -> V_19 ,
V_2 , * V_4 , V_12 , V_20 | V_21 ) ;
( * V_4 ) += V_12 ;
}
else {
V_11 = F_5 ( V_2 , * V_4 ) ;
if ( V_16 -> V_17 != 8 ) {
for ( V_13 = 0 , V_15 = 0x0 , V_14 = V_22 ;
V_13 < V_16 -> V_17 ;
V_13 ++ )
V_15 |= V_23 [ V_22 ++ ] ;
V_11 &= V_15 ;
V_11 >>= V_14 ;
}
if ( V_16 -> V_24 || V_16 -> V_17 != 8 ) {
F_6 ( V_3 , V_16 -> V_19 ,
V_2 , * V_4 , 1 , V_11 ) ;
}
else {
V_10 = ( T_9 ) V_11 ;
F_7 ( V_3 , V_16 -> V_19 ,
V_2 , * V_4 , 1 , V_10 ) ;
}
if ( ( V_22 == 0 ) || ( V_22 == 8 ) ) {
( * V_4 ) ++ ;
V_22 = 0 ;
}
}
break;
case 16 :
if ( V_16 -> V_24 ) {
V_9 = F_8 ( V_2 , * V_4 ) ;
F_6 ( V_3 , V_16 -> V_19 ,
V_2 , * V_4 , 2 , V_9 ) ;
}
else {
V_8 = F_8 ( V_2 , * V_4 ) ;
F_7 ( V_3 , V_16 -> V_19 ,
V_2 , * V_4 , 2 , V_8 ) ;
}
( * V_4 ) += 2 ;
break;
case 32 :
V_7 = F_9 ( V_2 , * V_4 ) ;
if ( V_16 -> V_24 ) {
V_6 = F_6 ( V_3 , V_16 -> V_19 ,
V_2 , * V_4 , 4 , V_7 ) ;
}
else {
V_6 = F_7 ( V_3 , V_16 -> V_19 ,
V_2 , * V_4 , 4 , V_7 ) ;
}
if ( V_16 -> V_25 ) {
F_10 ( V_6 , L_1 , F_11 ( V_2 , * V_4 ) ) ;
}
( * V_4 ) += 4 ;
break;
default:
break;
}
V_16 = V_16 -> V_26 ;
if ( F_3 ( V_2 , * V_4 ) <= 0 ) {
break;
}
}
}
static void F_12 ( T_1 V_27 , T_2 * V_2 ,
T_3 * V_28 , T_1 * V_4 ) {
switch ( V_27 ) {
default:
F_1 ( V_27 , V_2 , V_28 , V_4 , V_29 ) ;
break;
}
}
static void F_13 ( T_1 V_30 , T_2 * V_2 ,
T_3 * V_28 , T_1 * V_4 ) {
switch ( V_30 ) {
default:
F_1 ( V_30 , V_2 , V_28 , V_4 , V_31 ) ;
break;
}
}
static int F_14 ( T_2 * V_2 , T_11 * V_32 , T_3 * V_28 , void * T_12 V_33 ) {
T_5 * V_34 = NULL ;
T_3 * V_35 = NULL , * V_36 , * V_37 ;
T_1 V_4 = 0 ;
T_13 V_38 , V_39 = 0 ;
T_8 V_40 , V_41 , V_42 , V_43 ;
V_42 = F_8 ( V_2 , 0 ) ;
V_41 = F_8 ( V_2 , 2 ) ;
V_40 = F_8 ( V_2 , 4 ) ;
V_43 = F_8 ( V_2 , 6 ) ;
V_38 = F_9 ( V_2 , 8 ) ;
if ( V_32 -> V_44 == V_45 )
V_39 = F_9 ( V_2 , 12 ) ;
F_15 ( V_32 -> V_46 , V_47 , L_2 ) ;
if ( V_32 -> V_44 == V_45 ) {
F_16 ( V_32 -> V_46 , V_48 ,
L_3 ,
F_17 ( V_38 , V_49 , L_4 ) ,
V_38 , V_40 , V_39 , V_41 , V_42 ) ;
} else {
F_16 ( V_32 -> V_46 , V_48 ,
L_5 ,
F_17 ( V_38 , V_50 , L_4 ) ,
V_38 , V_40 , V_41 , V_42 ) ;
}
if ( V_28 ) {
V_34 = F_4 ( V_28 , V_51 , V_2 , 0 , - 1 , V_20 ) ;
V_35 = F_18 ( V_34 , V_52 ) ;
F_6 ( V_35 , V_53 , V_2 , 0 , 2 , V_42 ) ;
F_6 ( V_35 , V_54 , V_2 , 2 , 2 , V_41 ) ;
F_6 ( V_35 , V_55 , V_2 , 4 , 2 , V_40 ) ;
F_6 ( V_35 , V_56 , V_2 , 6 , 2 , V_43 ) ;
if ( V_32 -> V_44 == V_45 ) {
if ( F_19 ( V_38 , V_49 ) ) {
F_6 ( V_35 , V_57 , V_2 , 8 , 4 , V_38 ) ;
F_7 ( V_35 , V_58 , V_2 , 12 , 4 , V_39 ) ;
V_4 += 16 ;
if ( V_29 [ V_38 ] . V_17 ) {
V_36 = F_20 ( V_28 , V_2 , V_4 , - 1 , V_59 , NULL , L_6 ,
F_17 ( V_38 , V_49 , L_4 ) , V_38 ) ;
F_12 ( V_38 , V_2 , V_36 , & V_4 ) ;
}
}
}
else {
if ( F_19 ( V_38 , V_50 ) ) {
F_6 ( V_35 , V_60 , V_2 , 8 , 4 , V_38 ) ;
V_4 += 12 ;
if ( V_31 [ V_38 ] . V_17 ) {
V_37 = F_20 ( V_28 , V_2 , V_4 , - 1 , V_59 , NULL , L_7 ,
F_17 ( V_38 , V_50 , L_4 ) , V_38 ) ;
F_13 ( V_38 , V_2 , V_37 , & V_4 ) ;
}
}
}
}
return F_21 ( V_2 ) ;
}
static T_14 F_22 ( T_11 * V_32 V_33 , T_2 * V_2 ,
int V_4 , void * T_12 V_33 )
{
T_8 V_61 ;
V_61 = F_8 ( V_2 , V_4 + 2 ) ;
V_61 += 4 ;
return V_61 ;
}
static int F_23 ( T_2 * V_2 , T_11 * V_32 , T_3 * V_28 , void * T_12 ) {
if ( V_32 -> V_62 )
F_24 ( V_2 , V_32 , V_28 , V_63 , 4 , F_22 , F_14 , T_12 ) ;
else
F_14 ( V_2 , V_32 , V_28 , T_12 ) ;
return F_21 ( V_2 ) ;
}
static T_1 F_25 ( T_15 string [] , T_16 * V_64 ) {
T_1 V_65 = 0 , V_66 = 0 ;
T_17 * V_67 , * V_68 ;
V_68 = ( T_17 * ) F_26 ( V_69 ) ;
V_68 [ 0 ] = 0 ;
V_67 = ( T_17 * ) F_26 ( V_69 ) ;
V_67 [ 0 ] = 0 ;
while ( fgets ( V_68 , V_69 , V_64 ) != NULL ) {
if ( ! strncmp ( V_68 , L_8 , 5 ) ) {
break;
}
if ( sscanf ( V_68 , L_9 , V_67 , & V_66 ) == 2 ) {
string [ V_65 ] . V_70 = F_27 ( V_67 ) ;
string [ V_65 ] . V_71 = V_66 ;
if ( V_65 < ( V_72 - 1 ) ) {
V_65 ++ ;
}
else {
break;
}
}
}
F_28 ( V_68 ) ;
F_28 ( V_67 ) ;
return 0 ;
}
static T_1 F_29 ( T_16 * V_64 ) {
T_1 V_65 = 0 , V_73 = 0 , V_74 = 0 ;
T_18 V_75 = TRUE ;
T_17 * V_68 = NULL , * V_76 = NULL ,
* V_77 = NULL , * V_78 = NULL ;
V_68 = ( T_17 * ) F_26 ( V_69 ) ;
V_68 [ 0 ] = 0 ;
V_76 = ( T_17 * ) F_26 ( V_69 ) ;
V_76 [ 0 ] = 0 ;
V_77 = ( T_17 * ) F_26 ( V_69 ) ;
V_77 [ 0 ] = 0 ;
V_78 = ( T_17 * ) F_26 ( V_69 ) ;
V_78 [ 0 ] = 0 ;
while ( fgets ( V_68 , V_69 , V_64 ) != NULL ) {
if ( ! strncmp ( V_68 , L_8 , 5 ) ) {
break;
}
if ( sscanf ( V_68 , L_10 , V_76 , V_78 , & V_73 ) == 3 ) {
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
V_81 [ V_74 ] = F_27 ( V_76 ) ;
F_30 ( V_77 , V_76 , V_69 ) ;
}
V_79 [ V_74 ] [ V_65 ] . V_70 = F_27 ( V_78 ) ;
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
F_28 ( V_81 [ V_74 ] ) ;
V_81 [ V_74 ] = NULL ;
}
else {
V_81 [ V_74 + 1 ] = NULL ;
}
F_28 ( V_68 ) ;
F_28 ( V_76 ) ;
F_28 ( V_77 ) ;
F_28 ( V_78 ) ;
return 0 ;
}
static T_1 F_31 ( T_17 * V_76 ) {
T_1 V_74 = 0 ;
while ( V_81 [ V_74 ] ) {
if ( ! strcmp ( V_76 , V_81 [ V_74 ] ) )
return V_74 ;
V_74 ++ ;
}
return - 1 ;
}
static T_1 F_32 ( T_4 * V_5 , T_16 * V_64 ) {
static T_18 V_83 = FALSE ;
T_17 * V_84 = NULL , * V_85 = NULL , * V_86 = NULL ;
T_1 V_74 , V_1 , V_87 = - 1 ,
V_24 , V_17 ,
V_18 , V_25 ;
T_14 V_88 ;
T_4 * V_16 = NULL ;
T_19 V_89 ;
static T_19 V_90 [] = {
{
& V_53 ,
{
L_11 ,
L_12 ,
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
L_13 ,
L_14 ,
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
L_15 ,
L_16 ,
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
L_17 ,
L_18 ,
V_91 ,
V_92 ,
NULL ,
0x0 ,
NULL , V_93
}
} ,
{
& V_60 ,
{
L_19 ,
L_20 ,
V_94 ,
V_92 ,
F_33 ( V_50 ) ,
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
L_21 ,
L_22 ,
V_94 ,
V_92 ,
F_33 ( V_49 ) ,
0x0 ,
NULL , V_93
}
} ,
{
& V_58 ,
{
L_23 ,
L_24 ,
V_95 ,
V_92 ,
NULL ,
0x0 ,
NULL , V_93
}
}
} ;
V_89 . V_96 . type = V_97 ;
V_89 . V_96 . V_98 = NULL ;
V_89 . V_96 . V_15 = 0x0 ;
V_89 . V_96 . V_99 = NULL ;
F_34 ( V_89 ) ;
if ( ! V_83 ) {
V_100 = V_101 + ( int ) F_35 ( V_90 ) - 1 ;
if ( ( V_102 = ( T_19 * ) F_36 ( V_102 , V_100 * sizeof( T_19 ) ) ) == NULL ) {
return ( - 1 ) ;
}
for ( V_88 = 0 ; V_88 < F_35 ( V_90 ) ; V_88 ++ ) {
memcpy ( V_102 + ( V_101 - 1 ) , V_90 + V_88 , sizeof( T_19 ) ) ;
V_101 ++ ;
}
V_83 = TRUE ;
}
else
V_101 ++ ;
V_84 = ( T_17 * ) F_26 ( V_69 ) ;
V_84 [ 0 ] = 0 ;
while ( fgets ( V_84 , V_69 , V_64 ) != NULL ) {
if ( ! strncmp ( V_84 , L_8 , 5 ) ) {
V_101 -- ;
break;
}
V_89 . V_96 . V_103 = V_92 ;
if ( ( V_86 = strtok ( V_84 , L_25 ) ) == NULL )
continue;
V_1 = atoi ( V_86 ) ;
if ( ( V_85 = strtok ( NULL , L_25 ) ) == NULL )
continue;
if ( ( V_86 = strtok ( NULL , L_25 ) ) == NULL )
continue;
V_24 = atoi ( V_86 ) ;
if ( ( V_86 = strtok ( NULL , L_25 ) ) == NULL )
continue;
V_17 = atoi ( V_86 ) ;
if ( ( V_86 = strtok ( NULL , L_25 ) ) == NULL )
continue;
V_18 = atoi ( V_86 ) ;
if ( ( V_86 = strtok ( NULL , L_25 ) ) == NULL )
continue;
V_25 = atoi ( V_86 ) ;
if ( ( V_86 = strtok ( NULL , L_26 ) ) == NULL )
continue;
if ( V_87 != V_1 ) {
V_16 = & V_5 [ V_1 ] ;
V_87 = V_1 ;
}
else {
if ( ( V_16 -> V_26 =
( T_4 * ) F_37 ( sizeof( T_4 ) ) )
== NULL ) {
F_28 ( V_84 ) ;
return ( - 1 ) ;
}
V_16 = V_16 -> V_26 ;
}
if ( strcmp ( V_86 , L_27 ) ) {
V_74 = F_31 ( V_86 ) ;
if ( V_74 == - 1 ) {
V_89 . V_96 . V_98 = NULL ;
}
else {
V_89 . V_96 . V_98 = F_33 ( V_79 [ V_74 ] ) ;
}
}
else {
V_89 . V_96 . V_98 = NULL ;
}
V_16 -> V_19 = - 1 ;
V_89 . V_104 = & V_16 -> V_19 ;
V_16 -> V_85 = F_38 ( L_28 , V_85 ) ;
V_89 . V_96 . V_105 = V_16 -> V_85 ;
V_89 . V_96 . V_106 = V_16 -> V_85 ;
switch ( V_17 ) {
case 1 : case 2 : case 3 : case 4 :
case 5 : case 6 : case 7 : case 8 :
if ( V_18 ) {
V_89 . V_96 . type = V_107 ;
V_89 . V_96 . V_103 = V_108 ;
}
else
V_89 . V_96 . type = ( V_24 ) ? V_109 : V_110 ;
break;
case 16 :
V_89 . V_96 . type = ( V_24 ) ? V_91 : V_111 ;
break;
case 32 :
V_89 . V_96 . type = ( V_24 ) ? V_94 : V_95 ;
break;
default:
break;
}
if ( V_101 > V_100 ) {
V_100 += 1024 ;
if ( ( V_102 = ( T_19 * ) F_36 ( V_102 , V_100 * sizeof( T_19 ) ) ) == NULL ) {
F_28 ( V_84 ) ;
return ( - 1 ) ;
}
}
memcpy ( V_102 + V_101 - 1 , & V_89 , sizeof( T_19 ) ) ;
V_101 ++ ;
V_16 -> V_24 = V_24 ;
V_16 -> V_17 = V_17 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_25 = V_25 ;
}
F_28 ( V_84 ) ;
return 0 ;
}
static T_1 F_39 ( void ) {
T_17 * V_112 ;
T_1 V_113 ;
T_16 * V_64 ;
V_112 = F_38 ( L_29 V_114 L_30 V_114 L_31 , F_40 () ) ;
if ( ( V_64 = F_41 ( V_112 , L_32 ) ) == NULL ) {
F_28 ( V_112 ) ;
return ( - 1 ) ;
}
F_28 ( V_112 ) ;
V_113 = F_25 ( V_49 , V_64 ) ;
if ( V_113 != 0 )
goto V_115;
V_113 = F_25 ( V_50 , V_64 ) ;
if ( V_113 != 0 )
goto V_115;
V_113 = F_29 ( V_64 ) ;
if ( V_113 != 0 )
goto V_115;
V_113 = F_32 ( V_29 , V_64 ) ;
if ( V_113 != 0 )
goto V_115;
V_113 = F_32 ( V_31 , V_64 ) ;
V_115:
fclose ( V_64 ) ;
return V_113 ;
}
void F_42 ( void ) {
static T_1 V_116 = FALSE ;
static T_20 V_117 ;
if ( V_51 == - 1 )
return;
if ( ! V_116 ) {
V_117 = F_43 ( F_23 , V_51 ) ;
V_116 = TRUE ;
}
else {
F_44 ( L_33 , V_118 , V_117 ) ;
F_44 ( L_34 , V_119 , V_120 ) ;
F_44 ( L_33 , V_121 , V_117 ) ;
F_44 ( L_34 , V_122 , V_120 ) ;
}
if( V_123 ) {
V_118 = V_124 ;
V_119 = V_125 ;
V_121 = V_126 ;
V_122 = V_127 ;
F_45 ( L_33 , V_124 , V_117 ) ;
F_45 ( L_34 , V_125 , V_120 ) ;
}
}
void F_46 ( void ) {
T_1 V_88 ;
T_21 * V_128 ;
static T_1 * V_129 [] = {
& V_52 ,
& V_59
} ;
V_51 = F_47 ( L_35 ,
L_2 , L_30 ) ;
if( V_123 ) {
if ( F_39 () == - 1 ) {
F_48 ( L_36 ) ;
return;
}
F_49 {
for( V_88 = 0 ; V_88 < V_101 ; V_88 ++ ) {
F_50 ( V_51 , & V_102 [ V_88 ] , 1 ) ;
}
}
F_51 {
F_48 ( L_37 ) ;
}
V_130 ;
F_52 ( V_129 , F_35 ( V_129 ) ) ;
}
V_120 = F_53 ( L_30 , F_14 , V_51 ) ;
V_128 = F_54 ( V_51 , F_42 ) ;
F_55 ( V_128 , L_38 ,
L_39 ,
L_40
L_41
L_42 ,
& V_123 ) ;
F_56 ( V_128 , L_43 ,
L_44 ,
L_45 , 10 , & V_124 ) ;
F_56 ( V_128 , L_46 ,
L_47 ,
L_45 , 10 , & V_125 ) ;
}
