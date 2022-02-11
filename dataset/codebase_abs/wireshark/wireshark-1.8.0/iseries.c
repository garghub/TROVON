int
F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
T_3 V_5 ;
char V_6 [ V_7 ] ;
char V_8 [] =
{ '\x43' , '\x00' , '\x4F' , '\x00' , '\x4D' ,
'\x00' , '\x4D' , '\x00' , '\x55' , '\x00' , '\x4E' , '\x00' , '\x49' , '\x00' ,
'\x43' , '\x00' , '\x41'
} ;
V_9 = V_10 ;
V_4 = F_2 ( & V_6 , sizeof V_6 , V_1 -> V_11 ) ;
if ( V_4 != sizeof V_6 )
{
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
V_5 = 0 ;
while ( ( unsigned ) V_5 < ( V_7 - ( sizeof V_8 ) ) )
{
if ( memcmp ( V_6 + V_5 , V_8 , sizeof V_8 ) == 0 ) {
if ( F_4 ( V_1 -> V_11 , 0 , V_12 , V_2 ) == - 1 )
{
return 0 ;
}
if ( ! F_5 ( V_1 , V_2 , V_3 , V_13 ) )
{
if ( * V_2 == 0 )
return 0 ;
else
return - 1 ;
}
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = 0 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = V_24 ;
if ( F_4 ( V_1 -> V_11 , 0 , V_12 , V_2 ) == - 1 )
{
return 0 ;
}
return 1 ;
}
V_5 += 1 ;
}
V_5 = 0 ;
while ( V_5 < ( V_7 - V_25 ) )
{
if ( memcmp ( V_6 + V_5 , V_26 , V_25 ) == 0 )
{
if ( F_4 ( V_1 -> V_11 , 0 , V_12 , V_2 ) == - 1 )
{
return 0 ;
}
if ( ! F_5 ( V_1 , V_2 , V_3 , V_27 ) )
{
if ( * V_2 == 0 )
return 0 ;
else
return - 1 ;
}
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = 0 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = V_24 ;
if ( F_4 ( V_1 -> V_11 , 0 , V_12 , V_2 ) == - 1 )
{
return 0 ;
}
return 1 ;
}
V_5 += 1 ;
}
return 0 ;
}
static T_4
F_5 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , int V_28 )
{
T_5 line ;
int V_29 ;
char V_30 [ V_7 ] , V_31 [ 9 ] , type [ 5 ] , V_32 [ 2 ] ;
T_6 * V_33 ;
V_33 = ( T_6 * ) F_6 ( sizeof ( T_6 ) ) ;
V_1 -> V_34 = ( void * ) V_33 ;
V_33 -> V_35 = FALSE ;
V_33 -> V_28 = V_28 ;
V_33 -> V_36 = FALSE ;
V_33 -> V_37 = FALSE ;
for ( line = 0 ; line < V_38 ; line ++ )
{
if ( F_7 ( V_30 , V_7 , V_1 -> V_11 ) != NULL )
{
if ( V_33 -> V_28 == V_13 )
{
F_8 ( ( V_39 * ) V_30 , V_7 ) ;
}
F_9 ( V_30 ) ;
V_29 = sscanf ( V_30 ,
L_1 ,
V_31 ) ;
if ( V_29 == 1 )
{
if ( memcmp ( V_31 , L_2 , 8 ) != 0 )
return FALSE ;
}
V_29 = sscanf ( V_30 ,
L_3 ,
& V_33 -> V_40 , & V_33 -> V_41 ,
& V_33 -> V_42 ) ;
if ( V_29 == 3 )
{
V_33 -> V_35 = TRUE ;
}
V_29 =
sscanf ( V_30 + 78 ,
L_4 , type ) ;
if ( V_29 == 1 )
{
if ( strncmp ( type , L_5 , 1 ) == 0 )
{
V_33 -> V_37 = FALSE ;
}
if ( strncmp ( type , L_6 , 1 ) == 0 )
{
V_33 -> V_37 = TRUE ;
}
}
V_29 = sscanf ( V_30 ,
L_7 ,
V_32 ) ;
if ( V_29 == 1 )
{
V_33 -> V_36 = TRUE ;
return TRUE ;
}
V_29 = sscanf ( V_30 ,
L_8 ,
V_32 ) ;
if ( V_29 == 1 )
{
V_33 -> V_36 = TRUE ;
return TRUE ;
}
}
else
{
if ( F_10 ( V_1 -> V_11 ) )
* V_2 = 0 ;
else
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
return FALSE ;
}
}
* V_2 = 0 ;
return TRUE ;
}
static T_4
V_20 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_7 * V_43 )
{
T_7 V_5 ;
int V_44 ;
V_5 = F_11 ( V_1 , V_2 , V_3 ) ;
if ( V_5 < 1 )
return FALSE ;
V_44 =
F_12 ( V_1 , V_1 -> V_11 , & V_1 -> V_45 , NULL , V_2 ,
V_3 ) ;
if ( V_44 == - 1 )
return FALSE ;
* V_43 = V_5 ;
return TRUE ;
}
static T_7
F_11 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_6 * V_33 = ( T_6 * ) V_1 -> V_34 ;
char V_30 [ V_7 ] , type [ 5 ] ;
int line , V_29 ;
T_7 V_46 ;
long V_47 ;
for ( line = 0 ; line < V_48 ; line ++ )
{
if ( F_7 ( V_30 , V_7 , V_1 -> V_11 ) != NULL )
{
if ( V_33 -> V_28 == V_13 )
{
V_47 = F_8 ( ( V_39 * ) V_30 , V_7 ) ;
}
else
{
V_47 = ( long ) strlen ( V_30 ) ;
}
F_9 ( V_30 ) ;
V_29 =
sscanf ( V_30 + 78 ,
L_4 , type ) ;
if ( V_29 == 1 )
{
V_46 = F_13 ( V_1 -> V_11 ) ;
if ( V_46 == - 1 )
{
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
return - 1 ;
}
if ( F_4 ( V_1 -> V_11 , V_46 - V_47 , V_12 , V_2 ) == - 1 )
{
return - 1 ;
}
return V_46 - V_47 ;
}
}
else
{
if ( F_10 ( V_1 -> V_11 ) )
{
* V_2 = 0 ;
}
else
{
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
}
return - 1 ;
}
}
return - 1 ;
}
static T_4
V_22 ( T_1 * V_1 , T_7 V_49 ,
union V_50 * V_45 , V_39 * V_51 ,
int V_52 , int * V_2 , T_2 * * V_3 )
{
int V_44 ;
if ( F_4 ( V_1 -> V_53 , V_49 - 1 , V_12 , V_2 ) == - 1 )
return FALSE ;
V_44 = F_12 ( V_1 , V_1 -> V_53 , V_45 , V_51 ,
V_2 , V_3 ) ;
if ( V_44 != V_52 )
{
if ( V_44 != - 1 )
{
* V_2 = V_54 ;
* V_3 =
F_14 ( L_9 ,
V_52 , V_44 ) ;
}
return FALSE ;
}
return TRUE ;
}
static int
F_12 ( T_1 * V_1 , T_8 V_11 ,
union V_50 * V_45 , V_39 * V_51 ,
int * V_2 , T_2 * * V_3 )
{
T_6 * V_33 = ( T_6 * ) V_1 -> V_34 ;
T_7 V_46 ;
T_4 V_55 , V_56 , V_57 , V_58 , V_59 , V_60 ;
int V_29 , line , V_61 , V_47 ;
T_9 V_44 ;
int V_62 , V_63 , V_64 , V_65 , V_66 , V_67 ;
char V_68 [ 2 ] , V_69 [ 13 ] , V_70 [ 13 ] , type [ 5 ] ;
char V_71 [ 41 ] , V_72 [ 81 ] ;
char V_73 [ 17 ] , V_74 [ 17 ] , V_75 [ 17 ] , V_76 [ 17 ] ;
char V_77 [ V_7 * 2 ] ;
V_39 * V_30 ;
char * V_78 , * V_79 , * V_80 ;
struct V_81 V_81 ;
V_55 = FALSE ;
for ( line = 1 ; line < V_82 ; line ++ )
{
if ( F_7 ( V_77 , V_7 , V_11 ) == NULL )
{
* V_2 = F_3 ( V_11 , V_3 ) ;
if ( * V_2 == 0 )
{
* V_2 = V_83 ;
}
return - 1 ;
}
if ( V_33 -> V_28 == V_13 )
{
F_8 ( ( V_39 * ) V_77 , V_7 ) ;
}
F_9 ( V_77 ) ;
V_29 =
sscanf ( V_77 ,
L_10
L_11 ,
& V_63 , V_68 , & V_62 , & V_64 , & V_65 , & V_66 , & V_67 , V_69 ,
V_70 , type ) ;
if ( V_29 == 10 )
{
V_55 = TRUE ;
V_62 += 14 ;
break;
}
}
if ( ! V_55 )
{
* V_2 = V_54 ;
* V_3 = F_15 ( L_12 ) ;
return - 1 ;
}
V_1 -> V_84 . V_85 = V_86 ;
if ( V_33 -> V_35 )
{
V_1 -> V_84 . V_85 |= V_87 ;
V_81 . V_88 = 100 + V_33 -> V_42 ;
V_81 . V_89 = V_33 -> V_40 - 1 ;
V_81 . V_90 = V_33 -> V_41 ;
V_81 . V_91 = V_64 ;
V_81 . V_92 = V_65 ;
V_81 . V_93 = V_66 ;
V_81 . V_94 = - 1 ;
V_1 -> V_84 . V_95 . V_96 = mktime ( & V_81 ) ;
if ( V_67 > 99999 )
{
V_1 -> V_84 . V_95 . V_97 = V_67 * 1000 ;
}
else
{
V_1 -> V_84 . V_95 . V_97 = V_67 * 10000 ;
}
}
V_1 -> V_84 . V_98 = V_62 ;
V_1 -> V_84 . V_99 = V_15 ;
V_45 -> V_100 . V_101 = - 1 ;
V_56 = TRUE ;
V_57 = FALSE ;
V_58 = FALSE ;
V_59 = FALSE ;
V_78 = F_6 ( V_102 ) ;
V_79 = F_6 ( V_102 ) ;
V_78 [ 0 ] = '\0' ;
V_79 [ 0 ] = '\0' ;
V_61 = 0 ;
while ( V_56 )
{
V_61 ++ ;
if ( F_7 ( V_77 , V_7 , V_11 ) == NULL )
{
if ( F_10 ( V_11 ) )
{
break;
}
else
{
* V_2 = F_3 ( V_11 , V_3 ) ;
if ( * V_2 == 0 )
{
* V_2 = V_83 ;
}
goto V_103;
}
}
if ( V_33 -> V_28 == V_13 )
{
V_47 = F_8 ( ( V_39 * ) V_77 , V_7 ) ;
}
else
{
V_47 = ( int ) strlen ( V_77 ) ;
}
if ( ( ! V_33 -> V_37 ) || ( ( V_33 -> V_37 ) && ( ! V_33 -> V_36 ) ) )
{
V_29 = sscanf ( V_77 + 22 , L_13 , V_71 ) ;
if ( V_29 == 1 )
{
V_57 = TRUE ;
}
V_29 = sscanf ( V_77 + 22 , L_14 , V_72 ) ;
if ( V_29 == 1 )
{
V_58 = TRUE ;
}
V_29 =
sscanf ( V_77 + 27 , L_15 ,
V_73 , V_74 , V_75 , V_76 ) ;
if ( V_29 > 0 )
{
V_59 = TRUE ;
switch ( V_29 )
{
case 1 :
F_16 ( V_79 , V_102 , L_16 , V_78 ,
V_73 ) ;
break;
case 2 :
F_16 ( V_79 , V_102 , L_17 ,
V_78 , V_73 , V_74 ) ;
break;
case 3 :
F_16 ( V_79 , V_102 , L_18 ,
V_78 , V_73 , V_74 , V_75 ) ;
break;
default:
F_16 ( V_79 , V_102 , L_19 ,
V_78 , V_73 , V_74 , V_75 , V_76 ) ;
}
memcpy ( V_78 , V_79 , V_102 ) ;
}
}
if ( ( V_33 -> V_37 ) && ( V_33 -> V_36 ) )
{
V_60 = FALSE ;
V_29 =
sscanf ( V_77 + 35 , L_20 ,
V_73 , V_74 , V_75 , V_76 ) ;
if ( V_29 > 0 )
{
V_59 = TRUE ;
switch ( V_29 )
{
case 1 :
if ( strlen ( V_73 ) == 16 )
{
F_16 ( V_79 , V_102 , L_16 , V_78 ,
V_73 ) ;
V_60 = TRUE ;
}
break;
case 2 :
if ( ( strlen ( V_73 ) == 16 ) && ( strlen ( V_74 ) == 16 ) )
{
F_16 ( V_79 , V_102 , L_17 ,
V_78 , V_73 , V_74 ) ;
V_60 = TRUE ;
}
break;
case 3 :
if ( ( strlen ( V_73 ) == 16 ) && ( strlen ( V_74 ) == 16 ) && ( strlen ( V_75 ) == 16 ) )
{
F_16 ( V_79 , V_102 , L_18 ,
V_78 , V_73 , V_74 , V_75 ) ;
V_60 = TRUE ;
}
break;
default:
if ( ( strlen ( V_73 ) == 16 ) && ( strlen ( V_74 ) == 16 ) && ( strlen ( V_75 ) == 16 ) && ( strlen ( V_76 ) == 16 ) )
{
F_16 ( V_79 , V_102 , L_19 ,
V_78 , V_73 , V_74 , V_75 , V_76 ) ;
V_60 = TRUE ;
}
}
memcpy ( V_78 , V_79 , V_102 ) ;
}
V_29 =
sscanf ( V_77 + 26 , L_20 ,
V_73 , V_74 , V_75 , V_76 ) ;
if ( ( V_29 > 0 ) && ( V_60 == FALSE ) )
{
V_59 = TRUE ;
switch ( V_29 )
{
case 1 :
if ( strlen ( V_73 ) == 16 )
{
F_16 ( V_79 , V_102 , L_16 , V_78 ,
V_73 ) ;
}
break;
case 2 :
if ( ( strlen ( V_73 ) == 16 ) && ( strlen ( V_74 ) == 16 ) )
{
F_16 ( V_79 , V_102 , L_17 ,
V_78 , V_73 , V_74 ) ;
}
break;
case 3 :
if ( ( strlen ( V_73 ) == 16 ) && ( strlen ( V_74 ) == 16 ) && ( strlen ( V_75 ) == 16 ) )
{
F_16 ( V_79 , V_102 , L_18 ,
V_78 , V_73 , V_74 , V_75 ) ;
}
break;
default:
if ( ( strlen ( V_73 ) == 16 ) && ( strlen ( V_74 ) == 16 ) && ( strlen ( V_75 ) == 16 ) && ( strlen ( V_76 ) == 16 ) )
{
F_16 ( V_79 , V_102 , L_19 ,
V_78 , V_73 , V_74 , V_75 , V_76 ) ;
}
}
memcpy ( V_78 , V_79 , V_102 ) ;
}
}
F_9 ( V_77 ) ;
V_29 =
sscanf ( V_77 + 78 ,
L_4 , type ) ;
if ( ( V_29 == 1 ) && V_61 > 1 )
{
V_56 = FALSE ;
V_46 = F_13 ( V_11 ) ;
if ( V_46 == - 1 )
{
* V_2 = F_3 ( V_11 , V_3 ) ;
goto V_103;
}
if ( F_4 ( V_11 , V_46 - V_47 , V_12 , V_2 ) == - 1 )
{
goto V_103;
}
}
}
if ( ( V_33 -> V_36 ) && ( V_33 -> V_37 == FALSE ) )
{
if ( ! V_57 )
{
* V_2 = V_54 ;
* V_3 = F_15 ( L_21 ) ;
goto V_103;
}
if ( ! V_58 )
{
* V_2 = V_54 ;
* V_3 = F_15 ( L_22 ) ;
goto V_103;
}
}
V_80 = F_6 ( V_102 ) ;
if ( V_59 )
{
if ( ( V_33 -> V_36 ) && ( V_33 -> V_37 == FALSE ) )
{
F_16 ( V_80 , V_102 , L_23 ,
V_69 , V_70 , type , V_71 , V_72 , V_78 ) ;
}
else
{
F_16 ( V_80 , V_102 , L_18 , V_69 ,
V_70 , type , V_78 ) ;
}
}
else
{
F_16 ( V_80 , V_102 , L_19 , V_69 ,
V_70 , type , V_71 , V_72 ) ;
}
if ( ! V_33 -> V_37 )
{
sscanf ( V_80 + 32 , L_24 , & V_44 ) ;
V_1 -> V_84 . V_52 = V_44 + 14 ;
}
else
{
sscanf ( V_80 + 36 , L_24 , & V_44 ) ;
V_1 -> V_84 . V_52 = V_44 + 14 ;
}
if ( V_1 -> V_84 . V_98 > V_1 -> V_84 . V_52 )
V_1 -> V_84 . V_52 = V_1 -> V_84 . V_98 ;
if ( V_51 == NULL )
{
F_17 ( V_1 -> V_104 , V_105 ) ;
V_30 = F_18 ( V_1 -> V_104 ) ;
F_19 ( V_80 , V_30 , ( int ) strlen ( V_80 ) ) ;
}
else
{
F_19 ( V_80 , V_51 , ( int ) strlen ( V_80 ) ) ;
}
* V_2 = 0 ;
F_20 ( V_80 ) ;
F_20 ( V_78 ) ;
F_20 ( V_79 ) ;
return V_1 -> V_84 . V_52 ;
V_103:
F_20 ( V_78 ) ;
F_20 ( V_79 ) ;
return - 1 ;
}
static int
F_8 ( V_39 * V_30 , T_5 V_106 )
{
T_5 V_107 ;
V_39 * V_108 ;
V_108 = V_30 ;
for ( V_107 = 0 ; V_107 < V_106 ; V_107 ++ )
{
switch ( V_30 [ V_107 ] )
{
case 0xFE :
case 0xFF :
case 0x00 :
break;
default:
* V_108 = V_30 [ V_107 ] ;
V_108 ++ ;
}
if ( V_30 [ V_107 ] == 0x0A )
return V_107 ;
}
return V_107 ;
}
static T_4
F_19 ( const char * V_109 , V_39 * V_30 , int V_52 )
{
int V_107 , V_110 ;
T_3 V_111 ;
V_39 V_112 ;
V_110 = 0 ;
V_107 = 0 ;
for (; ; )
{
if ( V_107 >= V_52 )
break;
V_111 = F_21 ( V_109 [ V_107 ] ) ;
V_107 ++ ;
if ( V_111 == - 1 )
return FALSE ;
V_112 = ( V_39 ) ( V_111 << 4 ) ;
if ( V_107 >= V_52 )
return FALSE ;
V_111 = F_21 ( V_109 [ V_107 ] ) ;
V_107 ++ ;
if ( V_111 == - 1 )
return FALSE ;
V_112 |= ( V_39 ) V_111 ;
V_30 [ V_110 ] = V_112 ;
V_110 ++ ;
}
return TRUE ;
}
