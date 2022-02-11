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
if ( * V_2 != 0 && * V_2 != V_12 )
return - 1 ;
return 0 ;
}
V_5 = 0 ;
while ( ( unsigned ) V_5 < ( V_7 - ( sizeof V_8 ) ) )
{
if ( memcmp ( V_6 + V_5 , V_8 , sizeof V_8 ) == 0 ) {
if ( F_4 ( V_1 -> V_11 , 0 , V_13 , V_2 ) == - 1 )
{
return 0 ;
}
if ( ! F_5 ( V_1 , V_2 , V_3 , V_14 ) )
{
if ( * V_2 == 0 )
return 0 ;
else
return - 1 ;
}
V_1 -> V_15 = V_16 ;
V_1 -> V_17 = V_18 ;
V_1 -> V_19 = 0 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = V_23 ;
V_1 -> V_24 = V_25 ;
if ( F_4 ( V_1 -> V_11 , 0 , V_13 , V_2 ) == - 1 )
{
return 0 ;
}
return 1 ;
}
V_5 += 1 ;
}
V_5 = 0 ;
while ( V_5 < ( V_7 - V_26 ) )
{
if ( memcmp ( V_6 + V_5 , V_27 , V_26 ) == 0 )
{
if ( F_4 ( V_1 -> V_11 , 0 , V_13 , V_2 ) == - 1 )
{
return 0 ;
}
if ( ! F_5 ( V_1 , V_2 , V_3 , V_28 ) )
{
if ( * V_2 == 0 )
return 0 ;
else
return - 1 ;
}
V_1 -> V_15 = V_16 ;
V_1 -> V_17 = V_18 ;
V_1 -> V_19 = 0 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = V_23 ;
V_1 -> V_24 = V_25 ;
if ( F_4 ( V_1 -> V_11 , 0 , V_13 , V_2 ) == - 1 )
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
F_5 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , int V_29 )
{
T_5 line ;
int V_30 ;
char V_31 [ V_7 ] , V_32 [ 9 ] ;
T_6 * V_33 ;
V_33 = ( T_6 * ) F_6 ( sizeof ( T_6 ) ) ;
V_1 -> V_34 = ( void * ) V_33 ;
V_33 -> V_35 = FALSE ;
V_33 -> V_29 = V_29 ;
for ( line = 0 ; line < V_36 ; line ++ )
{
if ( F_7 ( V_31 , V_7 , V_1 -> V_11 ) == NULL )
{
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
if ( * V_2 == V_12 )
* V_2 = 0 ;
return FALSE ;
}
if ( V_33 -> V_29 == V_14 )
{
F_8 ( ( V_37 * ) V_31 , V_7 ) ;
}
F_9 ( V_31 ) ;
V_30 = sscanf ( V_31 ,
L_1 ,
V_32 ) ;
if ( V_30 == 1 )
{
if ( memcmp ( V_32 , L_2 , 8 ) != 0 )
return FALSE ;
}
V_30 = sscanf ( V_31 ,
L_3 ,
& V_33 -> V_38 , & V_33 -> V_39 ,
& V_33 -> V_40 ) ;
if ( V_30 == 3 )
{
V_33 -> V_35 = TRUE ;
}
}
* V_2 = 0 ;
return TRUE ;
}
static T_4
V_21 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_7 * V_41 )
{
T_7 V_5 ;
int V_42 ;
V_5 = F_10 ( V_1 , V_2 , V_3 ) ;
if ( V_5 < 1 )
return FALSE ;
V_42 =
F_11 ( V_1 , V_1 -> V_11 , & V_1 -> V_43 . V_44 , NULL , V_2 ,
V_3 ) ;
if ( V_42 == - 1 )
return FALSE ;
* V_41 = V_5 ;
return TRUE ;
}
static T_7
F_10 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_6 * V_33 = ( T_6 * ) V_1 -> V_34 ;
char V_31 [ V_7 ] , type [ 5 ] ;
int line , V_30 ;
T_7 V_45 ;
long V_46 ;
for ( line = 0 ; line < V_47 ; line ++ )
{
if ( F_7 ( V_31 , V_7 , V_1 -> V_11 ) == NULL )
{
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
if ( * V_2 != 0 )
{
return - 1 ;
}
return 0 ;
}
if ( V_33 -> V_29 == V_14 )
{
V_46 = F_8 ( ( V_37 * ) V_31 , V_7 ) ;
}
else
{
V_46 = ( long ) strlen ( V_31 ) ;
}
F_9 ( V_31 ) ;
V_30 =
sscanf ( V_31 + 78 ,
L_4 , type ) ;
if ( V_30 == 1 )
{
V_45 = F_12 ( V_1 -> V_11 ) ;
if ( V_45 == - 1 )
{
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
return - 1 ;
}
if ( F_4 ( V_1 -> V_11 , V_45 - V_46 , V_13 , V_2 ) == - 1 )
{
return - 1 ;
}
return V_45 - V_46 ;
}
}
* V_2 = V_48 ;
* V_3 =
F_13 ( L_5 ,
V_47 ) ;
return - 1 ;
}
static T_4
V_23 ( T_1 * V_1 , T_7 V_49 ,
struct V_50 * V_43 , V_37 * V_51 ,
int V_52 , int * V_2 , T_2 * * V_3 )
{
union V_53 * V_44 = & V_43 -> V_44 ;
int V_42 ;
if ( F_4 ( V_1 -> V_54 , V_49 - 1 , V_13 , V_2 ) == - 1 )
return FALSE ;
V_42 = F_11 ( V_1 , V_1 -> V_54 , V_44 , V_51 ,
V_2 , V_3 ) ;
if ( V_42 != V_52 )
{
if ( V_42 != - 1 )
{
* V_2 = V_48 ;
* V_3 =
F_13 ( L_6 ,
V_52 , V_42 ) ;
}
return FALSE ;
}
return TRUE ;
}
static int
F_14 ( char * V_55 , int V_56 , int V_57 ,
char * V_58 , int * V_2 , T_2 * * V_3 )
{
int V_59 , V_60 ;
int V_61 ;
unsigned int V_62 ;
T_4 V_63 = FALSE ;
V_59 = 0 ;
V_60 = V_56 ;
for (; ; )
{
for ( V_62 = 0 ; V_62 < 16 ; V_62 ++ , V_59 ++ )
{
V_61 = V_58 [ V_59 ] & 0xFF ;
if ( V_61 == '\0' || V_61 == ' ' || V_61 == '*' || V_61 == '\r' || V_61 == '\n' )
{
goto V_64;
}
if ( ! isxdigit ( V_61 ) || islower ( V_61 ) )
{
return V_56 ;
}
if ( V_60 >= V_57 )
V_63 = TRUE ;
else
{
V_55 [ V_60 ] = V_61 ;
V_60 ++ ;
}
}
for (; ( V_58 [ V_59 ] & 0xFF ) == ' ' ; V_59 ++ )
;
}
V_64:
if ( ( V_62 % 2 ) != 0 )
{
* V_2 = V_48 ;
* V_3 = F_15 ( L_7 ) ;
return - 1 ;
}
if ( V_63 )
{
* V_2 = V_48 ;
* V_3 = F_15 ( L_8 ) ;
return - 1 ;
}
return V_60 ;
}
static int
F_11 ( T_1 * V_1 , T_8 V_11 ,
union V_53 * V_44 , V_37 * V_51 ,
int * V_2 , T_2 * * V_3 )
{
T_6 * V_33 = ( T_6 * ) V_1 -> V_34 ;
T_7 V_45 ;
T_4 V_65 , V_66 ;
int V_30 , line , V_67 , V_46 ;
int V_68 , V_69 , V_70 , V_71 , V_72 ;
char V_73 [ 2 ] , V_74 [ 13 ] , V_75 [ 13 ] , type [ 5 ] , V_76 [ 9 + 1 ] ;
char V_58 [ V_7 * 2 ] ;
int V_5 ;
V_37 * V_31 ;
char * V_55 ;
int V_56 ;
struct V_77 V_77 ;
V_65 = FALSE ;
for ( line = 1 ; line < V_78 ; line ++ )
{
if ( F_7 ( V_58 , V_7 , V_11 ) == NULL )
{
* V_2 = F_3 ( V_11 , V_3 ) ;
if ( * V_2 != 0 )
{
return - 1 ;
}
return 0 ;
}
if ( V_33 -> V_29 == V_14 )
{
F_8 ( ( V_37 * ) V_58 , V_7 ) ;
}
F_9 ( V_58 ) ;
V_30 =
sscanf ( V_58 ,
L_9
L_10 ,
& V_69 , V_73 , & V_68 , & V_70 , & V_71 , & V_72 , V_76 , V_74 ,
V_75 , type ) ;
if ( V_30 == 10 )
{
V_65 = TRUE ;
V_68 += 14 ;
break;
}
}
if ( ! V_65 )
{
* V_2 = V_48 ;
* V_3 = F_15 ( L_11 ) ;
return - 1 ;
}
V_1 -> V_43 . V_79 = V_80 ;
if ( V_33 -> V_35 )
{
V_1 -> V_43 . V_79 |= V_81 ;
V_77 . V_82 = 100 + V_33 -> V_40 ;
V_77 . V_83 = V_33 -> V_38 - 1 ;
V_77 . V_84 = V_33 -> V_39 ;
V_77 . V_85 = V_70 ;
V_77 . V_86 = V_71 ;
V_77 . V_87 = V_72 ;
V_77 . V_88 = - 1 ;
V_1 -> V_43 . V_89 . V_90 = mktime ( & V_77 ) ;
switch ( strlen ( V_76 ) )
{
case 0 :
V_1 -> V_43 . V_89 . V_91 = 0 ;
break;
case 1 :
V_1 -> V_43 . V_89 . V_91 = atoi ( V_76 ) * 100000000 ;
break;
case 2 :
V_1 -> V_43 . V_89 . V_91 = atoi ( V_76 ) * 10000000 ;
break;
case 3 :
V_1 -> V_43 . V_89 . V_91 = atoi ( V_76 ) * 1000000 ;
break;
case 4 :
V_1 -> V_43 . V_89 . V_91 = atoi ( V_76 ) * 100000 ;
break;
case 5 :
V_1 -> V_43 . V_89 . V_91 = atoi ( V_76 ) * 10000 ;
break;
case 6 :
V_1 -> V_43 . V_89 . V_91 = atoi ( V_76 ) * 1000 ;
break;
case 7 :
V_1 -> V_43 . V_89 . V_91 = atoi ( V_76 ) * 100 ;
break;
case 8 :
V_1 -> V_43 . V_89 . V_91 = atoi ( V_76 ) * 10 ;
break;
case 9 :
V_1 -> V_43 . V_89 . V_91 = atoi ( V_76 ) ;
break;
}
}
V_1 -> V_43 . V_52 = V_68 ;
V_1 -> V_43 . V_92 = V_16 ;
V_44 -> V_93 . V_94 = - 1 ;
V_55 = ( char * ) F_6 ( V_95 ) ;
F_16 ( V_55 , V_95 , L_12 , V_74 , V_75 , type ) ;
V_56 = 14 * 2 ;
V_66 = TRUE ;
V_67 = 0 ;
while ( V_66 )
{
V_67 ++ ;
if ( F_7 ( V_58 , V_7 , V_11 ) == NULL )
{
* V_2 = F_3 ( V_11 , V_3 ) ;
if ( * V_2 == 0 )
{
break;
}
goto V_96;
}
if ( V_33 -> V_29 == V_14 )
{
V_46 = F_8 ( ( V_37 * ) V_58 , V_7 ) ;
}
else
{
V_46 = ( int ) strlen ( V_58 ) ;
}
for ( V_5 = 0 ; isspace ( V_58 [ V_5 ] ) ; V_5 ++ )
;
if ( V_5 == 22 )
{
if ( strncmp ( V_58 + 22 , L_13 , 14 ) == 0 ||
strncmp ( V_58 + 22 , L_14 , 14 ) == 0 ||
strncmp ( V_58 + 22 , L_15 , 14 ) == 0 ||
strncmp ( V_58 + 22 , L_16 , 14 ) == 0 ||
strncmp ( V_58 + 22 , L_17 , 14 ) == 0 ||
strncmp ( V_58 + 22 , L_18 , 14 ) == 0 ||
strncmp ( V_58 + 22 , L_19 , 14 ) == 0 ||
strncmp ( V_58 + 22 , L_20 , 14 ) == 0 )
{
V_56 = F_14 ( V_55 , V_56 ,
V_95 - 1 ,
V_58 + 22 + 14 , V_2 ,
V_3 ) ;
if ( V_56 == - 1 )
{
return - 1 ;
}
continue;
}
}
if ( V_5 == 9 )
{
if ( strncmp ( V_58 + 9 , L_21 , 18 ) == 0 )
{
V_56 = F_14 ( V_55 , V_56 ,
V_95 - 1 ,
V_58 + 9 + 18 , V_2 ,
V_3 ) ;
if ( V_56 == - 1 )
{
return - 1 ;
}
continue;
}
}
if ( V_5 == 36 || V_5 == 27 )
{
V_56 = F_14 ( V_55 , V_56 ,
V_95 - 1 ,
V_58 + V_5 , V_2 ,
V_3 ) ;
if ( V_56 == - 1 )
{
return - 1 ;
}
continue;
}
F_9 ( V_58 ) ;
V_30 =
sscanf ( V_58 + 78 ,
L_4 , type ) ;
if ( ( V_30 == 1 ) && V_67 > 1 )
{
V_66 = FALSE ;
V_45 = F_12 ( V_11 ) ;
if ( V_45 == - 1 )
{
* V_2 = F_3 ( V_11 , V_3 ) ;
goto V_96;
}
if ( F_4 ( V_11 , V_45 - V_46 , V_13 , V_2 ) == - 1 )
{
goto V_96;
}
}
}
V_55 [ V_56 ] = '\0' ;
V_1 -> V_43 . V_97 = ( ( V_98 ) strlen ( V_55 ) ) / 2 ;
if ( V_51 == NULL )
{
F_17 ( V_1 -> V_99 , V_100 ) ;
V_31 = F_18 ( V_1 -> V_99 ) ;
F_19 ( V_55 , V_31 , strlen ( V_55 ) ) ;
}
else
{
F_19 ( V_55 , V_51 , strlen ( V_55 ) ) ;
}
* V_2 = 0 ;
F_20 ( V_55 ) ;
return V_1 -> V_43 . V_97 ;
V_96:
F_20 ( V_55 ) ;
return - 1 ;
}
static int
F_8 ( V_37 * V_31 , T_5 V_101 )
{
T_5 V_62 ;
V_37 * V_102 ;
V_102 = V_31 ;
for ( V_62 = 0 ; V_62 < V_101 ; V_62 ++ )
{
switch ( V_31 [ V_62 ] )
{
case 0xFE :
case 0xFF :
case 0x00 :
break;
default:
* V_102 = V_31 [ V_62 ] ;
V_102 ++ ;
}
if ( V_31 [ V_62 ] == 0x0A )
return V_62 ;
}
return V_62 ;
}
static T_4
F_19 ( const char * V_103 , V_37 * V_31 , T_9 V_52 )
{
T_9 V_62 ;
int V_104 ;
T_3 V_105 ;
V_37 V_106 ;
V_104 = 0 ;
for ( V_62 = 0 ; V_62 < V_52 ; V_62 ++ )
{
V_105 = F_21 ( V_103 [ V_62 ] ) ;
V_62 ++ ;
if ( V_105 == - 1 )
return FALSE ;
V_106 = ( V_37 ) ( V_105 << 4 ) ;
if ( V_62 >= V_52 )
return FALSE ;
V_105 = F_21 ( V_103 [ V_62 ] ) ;
if ( V_105 == - 1 )
return FALSE ;
V_106 |= ( V_37 ) V_105 ;
V_31 [ V_104 ] = V_106 ;
V_104 ++ ;
}
return TRUE ;
}
