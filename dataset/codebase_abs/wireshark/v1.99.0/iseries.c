int
F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
char V_5 [ V_6 ] ;
char V_7 [] =
{ '\x43' , '\x00' , '\x4F' , '\x00' , '\x4D' ,
'\x00' , '\x4D' , '\x00' , '\x55' , '\x00' , '\x4E' , '\x00' , '\x49' , '\x00' ,
'\x43' , '\x00' , '\x41'
} ;
V_8 = V_9 ;
if ( ! F_2 ( V_1 -> V_10 , & V_5 , sizeof V_5 , V_2 , V_3 ) )
{
if ( * V_2 != V_11 )
return - 1 ;
return 0 ;
}
V_4 = 0 ;
while ( ( unsigned int ) V_4 < ( V_6 - ( sizeof V_7 ) ) )
{
if ( memcmp ( V_5 + V_4 , V_7 , sizeof V_7 ) == 0 ) {
if ( F_3 ( V_1 -> V_10 , 0 , V_12 , V_2 ) == - 1 )
{
return 0 ;
}
if ( ! F_4 ( V_1 , V_2 , V_3 , V_13 ) )
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
if ( F_3 ( V_1 -> V_10 , 0 , V_12 , V_2 ) == - 1 )
{
return 0 ;
}
return 1 ;
}
V_4 += 1 ;
}
V_4 = 0 ;
while ( V_4 < ( V_6 - V_25 ) )
{
if ( memcmp ( V_5 + V_4 , V_26 , V_25 ) == 0 )
{
if ( F_3 ( V_1 -> V_10 , 0 , V_12 , V_2 ) == - 1 )
{
return 0 ;
}
if ( ! F_4 ( V_1 , V_2 , V_3 , V_27 ) )
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
if ( F_3 ( V_1 -> V_10 , 0 , V_12 , V_2 ) == - 1 )
{
return 0 ;
}
return 1 ;
}
V_4 += 1 ;
}
return 0 ;
}
static T_4
F_4 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , int V_28 )
{
T_5 line ;
int V_29 ;
char V_30 [ V_6 ] , V_31 [ 9 ] ;
T_6 * V_32 ;
V_32 = ( T_6 * ) F_5 ( sizeof ( T_6 ) ) ;
V_1 -> V_33 = ( void * ) V_32 ;
V_32 -> V_34 = FALSE ;
V_32 -> V_28 = V_28 ;
for ( line = 0 ; line < V_35 ; line ++ )
{
if ( F_6 ( V_30 , V_6 , V_1 -> V_10 ) == NULL )
{
* V_2 = F_7 ( V_1 -> V_10 , V_3 ) ;
if ( * V_2 == V_11 )
* V_2 = 0 ;
return FALSE ;
}
if ( V_32 -> V_28 == V_13 )
{
F_8 ( ( V_36 * ) V_30 , V_6 ) ;
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
& V_32 -> V_37 , & V_32 -> V_38 ,
& V_32 -> V_39 ) ;
if ( V_29 == 3 )
{
V_32 -> V_34 = TRUE ;
}
}
* V_2 = 0 ;
return TRUE ;
}
static T_4
V_20 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_7 * V_40 )
{
T_7 V_4 ;
V_4 = F_10 ( V_1 , V_2 , V_3 ) ;
if ( V_4 < 0 )
return FALSE ;
* V_40 = V_4 ;
return F_11 ( V_1 , V_1 -> V_10 , & V_1 -> V_41 , V_1 -> V_42 ,
V_2 , V_3 ) ;
}
static T_7
F_10 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_6 * V_32 = ( T_6 * ) V_1 -> V_33 ;
char V_30 [ V_6 ] , type [ 5 ] ;
int line , V_29 ;
T_7 V_43 ;
long V_44 ;
for ( line = 0 ; line < V_45 ; line ++ )
{
if ( F_6 ( V_30 , V_6 , V_1 -> V_10 ) == NULL )
{
* V_2 = F_7 ( V_1 -> V_10 , V_3 ) ;
return - 1 ;
}
if ( V_32 -> V_28 == V_13 )
{
V_44 = F_8 ( ( V_36 * ) V_30 , V_6 ) ;
}
else
{
V_44 = ( long ) strlen ( V_30 ) ;
}
F_9 ( V_30 ) ;
V_29 =
sscanf ( V_30 + 78 ,
L_4 , type ) ;
if ( V_29 == 1 )
{
V_43 = F_12 ( V_1 -> V_10 ) ;
if ( V_43 == - 1 )
{
* V_2 = F_7 ( V_1 -> V_10 , V_3 ) ;
return - 1 ;
}
if ( F_3 ( V_1 -> V_10 , V_43 - V_44 , V_12 , V_2 ) == - 1 )
{
return - 1 ;
}
return V_43 - V_44 ;
}
}
* V_2 = V_46 ;
* V_3 =
F_13 ( L_5 ,
V_45 ) ;
return - 1 ;
}
static T_4
V_22 ( T_1 * V_1 , T_7 V_47 , struct V_48 * V_41 ,
T_8 * V_30 , int * V_2 , T_2 * * V_3 )
{
if ( F_3 ( V_1 -> V_49 , V_47 - 1 , V_12 , V_2 ) == - 1 )
return FALSE ;
return F_11 ( V_1 , V_1 -> V_49 , V_41 , V_30 ,
V_2 , V_3 ) ;
}
static int
F_14 ( char * V_50 , int V_51 , int V_52 ,
char * V_53 , int * V_2 , T_2 * * V_3 )
{
int V_54 , V_55 ;
int V_56 ;
unsigned int V_57 ;
T_4 V_58 = FALSE ;
V_54 = 0 ;
V_55 = V_51 ;
for (; ; )
{
for ( V_57 = 0 ; V_57 < 16 ; V_57 ++ , V_54 ++ )
{
V_56 = V_53 [ V_54 ] & 0xFF ;
if ( V_56 == '\0' || V_56 == ' ' || V_56 == '*' || V_56 == '\r' || V_56 == '\n' )
{
goto V_59;
}
if ( ! isxdigit ( V_56 ) || islower ( V_56 ) )
{
return V_51 ;
}
if ( V_55 >= V_52 )
V_58 = TRUE ;
else
{
V_50 [ V_55 ] = V_56 ;
V_55 ++ ;
}
}
for (; ( V_53 [ V_54 ] & 0xFF ) == ' ' ; V_54 ++ )
;
}
V_59:
if ( ( V_57 % 2 ) != 0 )
{
* V_2 = V_46 ;
* V_3 = F_15 ( L_6 ) ;
return - 1 ;
}
if ( V_58 )
{
* V_2 = V_46 ;
* V_3 = F_15 ( L_7 ) ;
return - 1 ;
}
return V_55 ;
}
static T_4
F_11 ( T_1 * V_1 , T_9 V_10 , struct V_48 * V_41 ,
T_8 * V_30 , int * V_2 , T_2 * * V_3 )
{
T_6 * V_32 = ( T_6 * ) V_1 -> V_33 ;
T_7 V_43 ;
T_4 V_60 , V_61 ;
int V_29 , line , V_62 , V_44 ;
int V_63 , V_64 , V_65 , V_66 , V_67 ;
char V_68 [ 2 ] , V_69 [ 13 ] , V_70 [ 13 ] , type [ 5 ] , V_71 [ 9 + 1 ] ;
char V_53 [ V_6 * 2 ] ;
int V_4 ;
char * V_50 ;
int V_51 ;
struct V_72 V_72 ;
V_60 = FALSE ;
for ( line = 1 ; line < V_73 ; line ++ )
{
if ( F_6 ( V_53 , V_6 , V_10 ) == NULL )
{
* V_2 = F_7 ( V_10 , V_3 ) ;
return FALSE ;
}
if ( V_32 -> V_28 == V_13 )
{
F_8 ( ( V_36 * ) V_53 , V_6 ) ;
}
F_9 ( V_53 ) ;
V_29 =
sscanf ( V_53 ,
L_8
L_9 ,
& V_64 , V_68 , & V_63 , & V_65 , & V_66 , & V_67 , V_71 , V_69 ,
V_70 , type ) ;
if ( V_29 == 10 )
{
V_60 = TRUE ;
V_63 += 14 ;
break;
}
}
if ( ! V_60 )
{
* V_2 = V_46 ;
* V_3 = F_15 ( L_10 ) ;
return FALSE ;
}
V_41 -> V_74 = V_75 ;
V_41 -> V_76 = V_77 ;
if ( V_32 -> V_34 )
{
V_41 -> V_76 |= V_78 ;
V_72 . V_79 = 100 + V_32 -> V_39 ;
V_72 . V_80 = V_32 -> V_37 - 1 ;
V_72 . V_81 = V_32 -> V_38 ;
V_72 . V_82 = V_65 ;
V_72 . V_83 = V_66 ;
V_72 . V_84 = V_67 ;
V_72 . V_85 = - 1 ;
V_41 -> V_86 . V_87 = mktime ( & V_72 ) ;
V_71 [ sizeof( V_71 ) - 1 ] = '\0' ;
switch ( strlen ( V_71 ) )
{
case 0 :
V_41 -> V_86 . V_88 = 0 ;
break;
case 1 :
V_41 -> V_86 . V_88 = atoi ( V_71 ) * 100000000 ;
break;
case 2 :
V_41 -> V_86 . V_88 = atoi ( V_71 ) * 10000000 ;
break;
case 3 :
V_41 -> V_86 . V_88 = atoi ( V_71 ) * 1000000 ;
break;
case 4 :
V_41 -> V_86 . V_88 = atoi ( V_71 ) * 100000 ;
break;
case 5 :
V_41 -> V_86 . V_88 = atoi ( V_71 ) * 10000 ;
break;
case 6 :
V_41 -> V_86 . V_88 = atoi ( V_71 ) * 1000 ;
break;
case 7 :
V_41 -> V_86 . V_88 = atoi ( V_71 ) * 100 ;
break;
case 8 :
V_41 -> V_86 . V_88 = atoi ( V_71 ) * 10 ;
break;
case 9 :
V_41 -> V_86 . V_88 = atoi ( V_71 ) ;
break;
}
}
V_41 -> V_89 = V_63 ;
V_41 -> V_90 = V_15 ;
V_41 -> V_91 . V_92 . V_93 = - 1 ;
V_50 = ( char * ) F_5 ( V_94 ) ;
F_16 ( V_50 , V_94 , L_11 , V_69 , V_70 , type ) ;
V_51 = 14 * 2 ;
V_61 = TRUE ;
V_62 = 0 ;
while ( V_61 )
{
V_62 ++ ;
if ( F_6 ( V_53 , V_6 , V_10 ) == NULL )
{
* V_2 = F_7 ( V_10 , V_3 ) ;
if ( * V_2 == 0 )
{
break;
}
goto V_95;
}
if ( V_32 -> V_28 == V_13 )
{
V_44 = F_8 ( ( V_36 * ) V_53 , V_6 ) ;
}
else
{
V_44 = ( int ) strlen ( V_53 ) ;
}
for ( V_4 = 0 ; isspace ( ( V_96 ) V_53 [ V_4 ] ) ; V_4 ++ )
;
if ( V_4 == 22 )
{
if ( strncmp ( V_53 + 22 , L_12 , 14 ) == 0 ||
strncmp ( V_53 + 22 , L_13 , 14 ) == 0 ||
strncmp ( V_53 + 22 , L_14 , 14 ) == 0 ||
strncmp ( V_53 + 22 , L_15 , 14 ) == 0 ||
strncmp ( V_53 + 22 , L_16 , 14 ) == 0 ||
strncmp ( V_53 + 22 , L_17 , 14 ) == 0 ||
strncmp ( V_53 + 22 , L_18 , 14 ) == 0 ||
strncmp ( V_53 + 22 , L_19 , 14 ) == 0 )
{
V_51 = F_14 ( V_50 , V_51 ,
V_94 - 1 ,
V_53 + 22 + 14 , V_2 ,
V_3 ) ;
if ( V_51 == - 1 )
{
return FALSE ;
}
continue;
}
}
if ( V_4 == 9 )
{
if ( strncmp ( V_53 + 9 , L_20 , 18 ) == 0 )
{
V_51 = F_14 ( V_50 , V_51 ,
V_94 - 1 ,
V_53 + 9 + 18 , V_2 ,
V_3 ) ;
if ( V_51 == - 1 )
{
return FALSE ;
}
continue;
}
}
if ( V_4 == 36 || V_4 == 27 )
{
V_51 = F_14 ( V_50 , V_51 ,
V_94 - 1 ,
V_53 + V_4 , V_2 ,
V_3 ) ;
if ( V_51 == - 1 )
{
return FALSE ;
}
continue;
}
F_9 ( V_53 ) ;
V_29 =
sscanf ( V_53 + 78 ,
L_4 , type ) ;
if ( ( V_29 == 1 ) && V_62 > 1 )
{
V_61 = FALSE ;
V_43 = F_12 ( V_10 ) ;
if ( V_43 == - 1 )
{
* V_2 = F_7 ( V_10 , V_3 ) ;
goto V_95;
}
if ( F_3 ( V_10 , V_43 - V_44 , V_12 , V_2 ) == - 1 )
{
goto V_95;
}
}
}
V_50 [ V_51 ] = '\0' ;
V_41 -> V_97 = ( ( V_98 ) strlen ( V_50 ) ) / 2 ;
F_17 ( V_30 , V_99 ) ;
F_18 ( V_50 , F_19 ( V_30 ) , strlen ( V_50 ) ) ;
* V_2 = 0 ;
F_20 ( V_50 ) ;
return TRUE ;
V_95:
F_20 ( V_50 ) ;
return FALSE ;
}
static int
F_8 ( V_36 * V_30 , T_5 V_100 )
{
T_5 V_57 ;
V_36 * V_101 ;
V_101 = V_30 ;
for ( V_57 = 0 ; V_57 < V_100 ; V_57 ++ )
{
switch ( V_30 [ V_57 ] )
{
case 0xFE :
case 0xFF :
case 0x00 :
break;
default:
* V_101 = V_30 [ V_57 ] ;
V_101 ++ ;
}
if ( V_30 [ V_57 ] == 0x0A )
return V_57 ;
}
return V_57 ;
}
static T_4
F_18 ( const char * V_102 , V_36 * V_30 , T_10 V_89 )
{
T_10 V_57 ;
int V_103 ;
T_3 V_104 ;
V_36 V_105 ;
V_103 = 0 ;
for ( V_57 = 0 ; V_57 < V_89 ; V_57 ++ )
{
V_104 = F_21 ( V_102 [ V_57 ] ) ;
V_57 ++ ;
if ( V_104 == - 1 )
return FALSE ;
V_105 = ( V_36 ) ( V_104 << 4 ) ;
if ( V_57 >= V_89 )
return FALSE ;
V_104 = F_21 ( V_102 [ V_57 ] ) ;
if ( V_104 == - 1 )
return FALSE ;
V_105 |= ( V_36 ) V_104 ;
V_30 [ V_103 ] = V_105 ;
V_103 ++ ;
}
return TRUE ;
}
