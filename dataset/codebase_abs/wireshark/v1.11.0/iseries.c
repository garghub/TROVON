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
V_5 = F_10 ( V_1 , V_2 , V_3 ) ;
if ( V_5 < 0 )
return FALSE ;
* V_41 = V_5 ;
return F_11 ( V_1 , V_1 -> V_11 , & V_1 -> V_42 , V_1 -> V_43 ,
V_2 , V_3 ) ;
}
static T_7
F_10 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_6 * V_33 = ( T_6 * ) V_1 -> V_34 ;
char V_31 [ V_7 ] , type [ 5 ] ;
int line , V_30 ;
T_7 V_44 ;
long V_45 ;
for ( line = 0 ; line < V_46 ; line ++ )
{
if ( F_7 ( V_31 , V_7 , V_1 -> V_11 ) == NULL )
{
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
return - 1 ;
}
if ( V_33 -> V_29 == V_14 )
{
V_45 = F_8 ( ( V_37 * ) V_31 , V_7 ) ;
}
else
{
V_45 = ( long ) strlen ( V_31 ) ;
}
F_9 ( V_31 ) ;
V_30 =
sscanf ( V_31 + 78 ,
L_4 , type ) ;
if ( V_30 == 1 )
{
V_44 = F_12 ( V_1 -> V_11 ) ;
if ( V_44 == - 1 )
{
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
return - 1 ;
}
if ( F_4 ( V_1 -> V_11 , V_44 - V_45 , V_13 , V_2 ) == - 1 )
{
return - 1 ;
}
return V_44 - V_45 ;
}
}
* V_2 = V_47 ;
* V_3 =
F_13 ( L_5 ,
V_46 ) ;
return - 1 ;
}
static T_4
V_23 ( T_1 * V_1 , T_7 V_48 , struct V_49 * V_42 ,
T_8 * V_31 , int T_9 V_50 , int * V_2 , T_2 * * V_3 )
{
if ( F_4 ( V_1 -> V_51 , V_48 - 1 , V_13 , V_2 ) == - 1 )
return FALSE ;
return F_11 ( V_1 , V_1 -> V_51 , V_42 , V_31 ,
V_2 , V_3 ) ;
}
static int
F_14 ( char * V_52 , int V_53 , int V_54 ,
char * V_55 , int * V_2 , T_2 * * V_3 )
{
int V_56 , V_57 ;
int V_58 ;
unsigned int V_59 ;
T_4 V_60 = FALSE ;
V_56 = 0 ;
V_57 = V_53 ;
for (; ; )
{
for ( V_59 = 0 ; V_59 < 16 ; V_59 ++ , V_56 ++ )
{
V_58 = V_55 [ V_56 ] & 0xFF ;
if ( V_58 == '\0' || V_58 == ' ' || V_58 == '*' || V_58 == '\r' || V_58 == '\n' )
{
goto V_61;
}
if ( ! isxdigit ( V_58 ) || islower ( V_58 ) )
{
return V_53 ;
}
if ( V_57 >= V_54 )
V_60 = TRUE ;
else
{
V_52 [ V_57 ] = V_58 ;
V_57 ++ ;
}
}
for (; ( V_55 [ V_56 ] & 0xFF ) == ' ' ; V_56 ++ )
;
}
V_61:
if ( ( V_59 % 2 ) != 0 )
{
* V_2 = V_47 ;
* V_3 = F_15 ( L_6 ) ;
return - 1 ;
}
if ( V_60 )
{
* V_2 = V_47 ;
* V_3 = F_15 ( L_7 ) ;
return - 1 ;
}
return V_57 ;
}
static T_4
F_11 ( T_1 * V_1 , T_10 V_11 , struct V_49 * V_42 ,
T_8 * V_31 , int * V_2 , T_2 * * V_3 )
{
T_6 * V_33 = ( T_6 * ) V_1 -> V_34 ;
T_7 V_44 ;
T_4 V_62 , V_63 ;
int V_30 , line , V_64 , V_45 ;
int V_65 , V_66 , V_67 , V_68 , V_69 ;
char V_70 [ 2 ] , V_71 [ 13 ] , V_72 [ 13 ] , type [ 5 ] , V_73 [ 9 + 1 ] ;
char V_55 [ V_7 * 2 ] ;
int V_5 ;
char * V_52 ;
int V_53 ;
struct V_74 V_74 ;
V_62 = FALSE ;
for ( line = 1 ; line < V_75 ; line ++ )
{
if ( F_7 ( V_55 , V_7 , V_11 ) == NULL )
{
* V_2 = F_3 ( V_11 , V_3 ) ;
return FALSE ;
}
if ( V_33 -> V_29 == V_14 )
{
F_8 ( ( V_37 * ) V_55 , V_7 ) ;
}
F_9 ( V_55 ) ;
V_30 =
sscanf ( V_55 ,
L_8
L_9 ,
& V_66 , V_70 , & V_65 , & V_67 , & V_68 , & V_69 , V_73 , V_71 ,
V_72 , type ) ;
if ( V_30 == 10 )
{
V_62 = TRUE ;
V_65 += 14 ;
break;
}
}
if ( ! V_62 )
{
* V_2 = V_47 ;
* V_3 = F_15 ( L_10 ) ;
return FALSE ;
}
V_42 -> V_76 = V_77 ;
if ( V_33 -> V_35 )
{
V_42 -> V_76 |= V_78 ;
V_74 . V_79 = 100 + V_33 -> V_40 ;
V_74 . V_80 = V_33 -> V_38 - 1 ;
V_74 . V_81 = V_33 -> V_39 ;
V_74 . V_82 = V_67 ;
V_74 . V_83 = V_68 ;
V_74 . V_84 = V_69 ;
V_74 . V_85 = - 1 ;
V_42 -> V_86 . V_87 = mktime ( & V_74 ) ;
switch ( strlen ( V_73 ) )
{
case 0 :
V_42 -> V_86 . V_88 = 0 ;
break;
case 1 :
V_42 -> V_86 . V_88 = atoi ( V_73 ) * 100000000 ;
break;
case 2 :
V_42 -> V_86 . V_88 = atoi ( V_73 ) * 10000000 ;
break;
case 3 :
V_42 -> V_86 . V_88 = atoi ( V_73 ) * 1000000 ;
break;
case 4 :
V_42 -> V_86 . V_88 = atoi ( V_73 ) * 100000 ;
break;
case 5 :
V_42 -> V_86 . V_88 = atoi ( V_73 ) * 10000 ;
break;
case 6 :
V_42 -> V_86 . V_88 = atoi ( V_73 ) * 1000 ;
break;
case 7 :
V_42 -> V_86 . V_88 = atoi ( V_73 ) * 100 ;
break;
case 8 :
V_42 -> V_86 . V_88 = atoi ( V_73 ) * 10 ;
break;
case 9 :
V_42 -> V_86 . V_88 = atoi ( V_73 ) ;
break;
}
}
V_42 -> T_9 = V_65 ;
V_42 -> V_89 = V_16 ;
V_42 -> V_90 . V_91 . V_92 = - 1 ;
V_52 = ( char * ) F_6 ( V_93 ) ;
F_16 ( V_52 , V_93 , L_11 , V_71 , V_72 , type ) ;
V_53 = 14 * 2 ;
V_63 = TRUE ;
V_64 = 0 ;
while ( V_63 )
{
V_64 ++ ;
if ( F_7 ( V_55 , V_7 , V_11 ) == NULL )
{
* V_2 = F_3 ( V_11 , V_3 ) ;
if ( * V_2 == 0 )
{
break;
}
goto V_94;
}
if ( V_33 -> V_29 == V_14 )
{
V_45 = F_8 ( ( V_37 * ) V_55 , V_7 ) ;
}
else
{
V_45 = ( int ) strlen ( V_55 ) ;
}
for ( V_5 = 0 ; isspace ( V_55 [ V_5 ] ) ; V_5 ++ )
;
if ( V_5 == 22 )
{
if ( strncmp ( V_55 + 22 , L_12 , 14 ) == 0 ||
strncmp ( V_55 + 22 , L_13 , 14 ) == 0 ||
strncmp ( V_55 + 22 , L_14 , 14 ) == 0 ||
strncmp ( V_55 + 22 , L_15 , 14 ) == 0 ||
strncmp ( V_55 + 22 , L_16 , 14 ) == 0 ||
strncmp ( V_55 + 22 , L_17 , 14 ) == 0 ||
strncmp ( V_55 + 22 , L_18 , 14 ) == 0 ||
strncmp ( V_55 + 22 , L_19 , 14 ) == 0 )
{
V_53 = F_14 ( V_52 , V_53 ,
V_93 - 1 ,
V_55 + 22 + 14 , V_2 ,
V_3 ) ;
if ( V_53 == - 1 )
{
return FALSE ;
}
continue;
}
}
if ( V_5 == 9 )
{
if ( strncmp ( V_55 + 9 , L_20 , 18 ) == 0 )
{
V_53 = F_14 ( V_52 , V_53 ,
V_93 - 1 ,
V_55 + 9 + 18 , V_2 ,
V_3 ) ;
if ( V_53 == - 1 )
{
return FALSE ;
}
continue;
}
}
if ( V_5 == 36 || V_5 == 27 )
{
V_53 = F_14 ( V_52 , V_53 ,
V_93 - 1 ,
V_55 + V_5 , V_2 ,
V_3 ) ;
if ( V_53 == - 1 )
{
return FALSE ;
}
continue;
}
F_9 ( V_55 ) ;
V_30 =
sscanf ( V_55 + 78 ,
L_4 , type ) ;
if ( ( V_30 == 1 ) && V_64 > 1 )
{
V_63 = FALSE ;
V_44 = F_12 ( V_11 ) ;
if ( V_44 == - 1 )
{
* V_2 = F_3 ( V_11 , V_3 ) ;
goto V_94;
}
if ( F_4 ( V_11 , V_44 - V_45 , V_13 , V_2 ) == - 1 )
{
goto V_94;
}
}
}
V_52 [ V_53 ] = '\0' ;
V_42 -> V_95 = ( ( V_96 ) strlen ( V_52 ) ) / 2 ;
F_17 ( V_31 , V_97 ) ;
F_18 ( V_52 , F_19 ( V_31 ) , strlen ( V_52 ) ) ;
* V_2 = 0 ;
F_20 ( V_52 ) ;
return TRUE ;
V_94:
F_20 ( V_52 ) ;
return FALSE ;
}
static int
F_8 ( V_37 * V_31 , T_5 V_98 )
{
T_5 V_59 ;
V_37 * V_99 ;
V_99 = V_31 ;
for ( V_59 = 0 ; V_59 < V_98 ; V_59 ++ )
{
switch ( V_31 [ V_59 ] )
{
case 0xFE :
case 0xFF :
case 0x00 :
break;
default:
* V_99 = V_31 [ V_59 ] ;
V_99 ++ ;
}
if ( V_31 [ V_59 ] == 0x0A )
return V_59 ;
}
return V_59 ;
}
static T_4
F_18 ( const char * V_100 , V_37 * V_31 , T_11 T_9 )
{
T_11 V_59 ;
int V_101 ;
T_3 V_102 ;
V_37 V_103 ;
V_101 = 0 ;
for ( V_59 = 0 ; V_59 < T_9 ; V_59 ++ )
{
V_102 = F_21 ( V_100 [ V_59 ] ) ;
V_59 ++ ;
if ( V_102 == - 1 )
return FALSE ;
V_103 = ( V_37 ) ( V_102 << 4 ) ;
if ( V_59 >= T_9 )
return FALSE ;
V_102 = F_21 ( V_100 [ V_59 ] ) ;
if ( V_102 == - 1 )
return FALSE ;
V_103 |= ( V_37 ) V_102 ;
V_31 [ V_101 ] = V_103 ;
V_101 ++ ;
}
return TRUE ;
}
