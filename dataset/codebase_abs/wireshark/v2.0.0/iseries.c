T_1
F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_4 V_4 ;
char V_5 [ V_6 ] ;
char V_7 [] =
{ '\x43' , '\x00' , '\x4F' , '\x00' , '\x4D' ,
'\x00' , '\x4D' , '\x00' , '\x55' , '\x00' , '\x4E' , '\x00' , '\x49' , '\x00' ,
'\x43' , '\x00' , '\x41'
} ;
if ( ! F_2 ( V_1 -> V_8 , & V_5 , sizeof V_5 , V_2 , V_3 ) )
{
if ( * V_2 != V_9 )
return V_10 ;
return V_11 ;
}
V_4 = 0 ;
while ( ( unsigned int ) V_4 < ( V_6 - ( sizeof V_7 ) ) )
{
if ( memcmp ( V_5 + V_4 , V_7 , sizeof V_7 ) == 0 ) {
if ( F_3 ( V_1 -> V_8 , 0 , V_12 , V_2 ) == - 1 )
{
return V_11 ;
}
if ( ! F_4 ( V_1 , V_2 , V_3 , V_13 ) )
{
if ( * V_2 == 0 )
return V_11 ;
else
return V_10 ;
}
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = 0 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = V_24 ;
if ( F_3 ( V_1 -> V_8 , 0 , V_12 , V_2 ) == - 1 )
{
return V_11 ;
}
return V_25 ;
}
V_4 += 1 ;
}
V_4 = 0 ;
while ( V_4 < ( V_6 - V_26 ) )
{
if ( memcmp ( V_5 + V_4 , V_27 , V_26 ) == 0 )
{
if ( F_3 ( V_1 -> V_8 , 0 , V_12 , V_2 ) == - 1 )
{
return V_11 ;
}
if ( ! F_4 ( V_1 , V_2 , V_3 , V_28 ) )
{
if ( * V_2 == 0 )
return V_11 ;
else
return V_10 ;
}
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = 0 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = V_24 ;
if ( F_3 ( V_1 -> V_8 , 0 , V_12 , V_2 ) == - 1 )
{
return V_11 ;
}
return V_25 ;
}
V_4 += 1 ;
}
return V_11 ;
}
static T_5
F_4 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , int V_29 )
{
T_6 line ;
int V_30 ;
char V_31 [ V_6 ] , V_32 [ 9 ] ;
T_7 * V_33 ;
V_33 = ( T_7 * ) F_5 ( sizeof ( T_7 ) ) ;
V_1 -> V_34 = ( void * ) V_33 ;
V_33 -> V_35 = FALSE ;
V_33 -> V_29 = V_29 ;
for ( line = 0 ; line < V_36 ; line ++ )
{
if ( F_6 ( V_31 , V_6 , V_1 -> V_8 ) == NULL )
{
* V_2 = F_7 ( V_1 -> V_8 , V_3 ) ;
if ( * V_2 == V_9 )
* V_2 = 0 ;
return FALSE ;
}
if ( V_33 -> V_29 == V_13 )
{
F_8 ( ( V_37 * ) V_31 , V_6 ) ;
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
static T_5
V_20 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , T_8 * V_41 )
{
T_8 V_4 ;
V_4 = F_10 ( V_1 , V_2 , V_3 ) ;
if ( V_4 < 0 )
return FALSE ;
* V_41 = V_4 ;
return F_11 ( V_1 , V_1 -> V_8 , & V_1 -> V_42 , V_1 -> V_43 ,
V_2 , V_3 ) ;
}
static T_8
F_10 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_7 * V_33 = ( T_7 * ) V_1 -> V_34 ;
char V_31 [ V_6 ] , type [ 5 ] ;
int line , V_30 ;
T_8 V_44 ;
long V_45 ;
for ( line = 0 ; line < V_46 ; line ++ )
{
if ( F_6 ( V_31 , V_6 , V_1 -> V_8 ) == NULL )
{
* V_2 = F_7 ( V_1 -> V_8 , V_3 ) ;
return - 1 ;
}
if ( V_33 -> V_29 == V_13 )
{
V_45 = F_8 ( ( V_37 * ) V_31 , V_6 ) ;
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
V_44 = F_12 ( V_1 -> V_8 ) ;
if ( V_44 == - 1 )
{
* V_2 = F_7 ( V_1 -> V_8 , V_3 ) ;
return - 1 ;
}
if ( F_3 ( V_1 -> V_8 , V_44 - V_45 , V_12 , V_2 ) == - 1 )
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
static T_5
V_22 ( T_2 * V_1 , T_8 V_48 , struct V_49 * V_42 ,
T_9 * V_31 , int * V_2 , T_3 * * V_3 )
{
if ( F_3 ( V_1 -> V_50 , V_48 - 1 , V_12 , V_2 ) == - 1 )
return FALSE ;
return F_11 ( V_1 , V_1 -> V_50 , V_42 , V_31 ,
V_2 , V_3 ) ;
}
static int
F_14 ( char * V_51 , int V_52 , int V_53 ,
char * V_54 , int * V_2 , T_3 * * V_3 )
{
int V_55 , V_56 ;
int V_57 ;
unsigned int V_58 ;
T_5 V_59 = FALSE ;
V_55 = 0 ;
V_56 = V_52 ;
for (; ; )
{
for ( V_58 = 0 ; V_58 < 16 ; V_58 ++ , V_55 ++ )
{
V_57 = V_54 [ V_55 ] & 0xFF ;
if ( V_57 == '\0' || V_57 == ' ' || V_57 == '*' || V_57 == '\r' || V_57 == '\n' )
{
goto V_60;
}
if ( ! F_15 ( V_57 ) || F_16 ( V_57 ) )
{
return V_52 ;
}
if ( V_56 >= V_53 )
V_59 = TRUE ;
else
{
V_51 [ V_56 ] = V_57 ;
V_56 ++ ;
}
}
for (; ( V_54 [ V_55 ] & 0xFF ) == ' ' ; V_55 ++ )
;
}
V_60:
if ( ( V_58 % 2 ) != 0 )
{
* V_2 = V_47 ;
* V_3 = F_17 ( L_6 ) ;
return - 1 ;
}
if ( V_59 )
{
* V_2 = V_47 ;
* V_3 = F_17 ( L_7 ) ;
return - 1 ;
}
return V_56 ;
}
static T_5
F_11 ( T_2 * V_1 , T_10 V_8 , struct V_49 * V_42 ,
T_9 * V_31 , int * V_2 , T_3 * * V_3 )
{
T_7 * V_33 = ( T_7 * ) V_1 -> V_34 ;
T_8 V_44 ;
T_5 V_61 , V_62 ;
int V_30 , line , V_63 , V_45 ;
int V_64 , V_65 , V_66 , V_67 , V_68 ;
char V_69 [ 2 ] , V_70 [ 13 ] , V_71 [ 13 ] , type [ 5 ] , V_72 [ 9 + 1 ] ;
char V_54 [ V_6 * 2 ] ;
int V_4 ;
char * V_51 ;
int V_52 ;
struct V_73 V_73 ;
V_61 = FALSE ;
for ( line = 1 ; line < V_74 ; line ++ )
{
if ( F_6 ( V_54 , V_6 , V_8 ) == NULL )
{
* V_2 = F_7 ( V_8 , V_3 ) ;
return FALSE ;
}
if ( V_33 -> V_29 == V_13 )
{
F_8 ( ( V_37 * ) V_54 , V_6 ) ;
}
F_9 ( V_54 ) ;
V_30 =
sscanf ( V_54 ,
L_8
L_9 ,
& V_65 , V_69 , & V_64 , & V_66 , & V_67 , & V_68 , V_72 , V_70 ,
V_71 , type ) ;
if ( V_30 == 10 )
{
V_61 = TRUE ;
V_64 += 14 ;
break;
}
}
if ( ! V_61 )
{
* V_2 = V_47 ;
* V_3 = F_17 ( L_10 ) ;
return FALSE ;
}
V_42 -> V_75 = V_76 ;
V_42 -> V_77 = V_78 ;
if ( V_33 -> V_35 )
{
V_42 -> V_77 |= V_79 ;
V_73 . V_80 = 100 + V_33 -> V_40 ;
V_73 . V_81 = V_33 -> V_38 - 1 ;
V_73 . V_82 = V_33 -> V_39 ;
V_73 . V_83 = V_66 ;
V_73 . V_84 = V_67 ;
V_73 . V_85 = V_68 ;
V_73 . V_86 = - 1 ;
V_42 -> V_87 . V_88 = mktime ( & V_73 ) ;
V_72 [ sizeof( V_72 ) - 1 ] = '\0' ;
switch ( strlen ( V_72 ) )
{
case 0 :
V_42 -> V_87 . V_89 = 0 ;
break;
case 1 :
V_42 -> V_87 . V_89 = atoi ( V_72 ) * 100000000 ;
break;
case 2 :
V_42 -> V_87 . V_89 = atoi ( V_72 ) * 10000000 ;
break;
case 3 :
V_42 -> V_87 . V_89 = atoi ( V_72 ) * 1000000 ;
break;
case 4 :
V_42 -> V_87 . V_89 = atoi ( V_72 ) * 100000 ;
break;
case 5 :
V_42 -> V_87 . V_89 = atoi ( V_72 ) * 10000 ;
break;
case 6 :
V_42 -> V_87 . V_89 = atoi ( V_72 ) * 1000 ;
break;
case 7 :
V_42 -> V_87 . V_89 = atoi ( V_72 ) * 100 ;
break;
case 8 :
V_42 -> V_87 . V_89 = atoi ( V_72 ) * 10 ;
break;
case 9 :
V_42 -> V_87 . V_89 = atoi ( V_72 ) ;
break;
}
}
V_42 -> V_90 = V_64 ;
V_42 -> V_91 = V_15 ;
V_42 -> V_92 . V_93 . V_94 = - 1 ;
V_51 = ( char * ) F_5 ( V_95 ) ;
F_18 ( V_51 , V_95 , L_11 , V_70 , V_71 , type ) ;
V_52 = 14 * 2 ;
V_62 = TRUE ;
V_63 = 0 ;
while ( V_62 )
{
V_63 ++ ;
if ( F_6 ( V_54 , V_6 , V_8 ) == NULL )
{
* V_2 = F_7 ( V_8 , V_3 ) ;
if ( * V_2 == 0 )
{
break;
}
goto V_96;
}
if ( V_33 -> V_29 == V_13 )
{
V_45 = F_8 ( ( V_37 * ) V_54 , V_6 ) ;
}
else
{
V_45 = ( int ) strlen ( V_54 ) ;
}
for ( V_4 = 0 ; F_19 ( V_54 [ V_4 ] ) ; V_4 ++ )
;
if ( V_4 == 22 )
{
if ( strncmp ( V_54 + 22 , L_12 , 14 ) == 0 ||
strncmp ( V_54 + 22 , L_13 , 14 ) == 0 ||
strncmp ( V_54 + 22 , L_14 , 14 ) == 0 ||
strncmp ( V_54 + 22 , L_15 , 14 ) == 0 ||
strncmp ( V_54 + 22 , L_16 , 14 ) == 0 ||
strncmp ( V_54 + 22 , L_17 , 14 ) == 0 ||
strncmp ( V_54 + 22 , L_18 , 14 ) == 0 ||
strncmp ( V_54 + 22 , L_19 , 14 ) == 0 )
{
V_52 = F_14 ( V_51 , V_52 ,
V_95 - 1 ,
V_54 + 22 + 14 , V_2 ,
V_3 ) ;
if ( V_52 == - 1 )
{
return FALSE ;
}
continue;
}
}
if ( V_4 == 9 )
{
if ( strncmp ( V_54 + 9 , L_20 , 18 ) == 0 )
{
V_52 = F_14 ( V_51 , V_52 ,
V_95 - 1 ,
V_54 + 9 + 18 , V_2 ,
V_3 ) ;
if ( V_52 == - 1 )
{
return FALSE ;
}
continue;
}
}
if ( V_4 == 36 || V_4 == 27 )
{
V_52 = F_14 ( V_51 , V_52 ,
V_95 - 1 ,
V_54 + V_4 , V_2 ,
V_3 ) ;
if ( V_52 == - 1 )
{
return FALSE ;
}
continue;
}
F_9 ( V_54 ) ;
V_30 =
sscanf ( V_54 + 78 ,
L_4 , type ) ;
if ( ( V_30 == 1 ) && V_63 > 1 )
{
V_62 = FALSE ;
V_44 = F_12 ( V_8 ) ;
if ( V_44 == - 1 )
{
* V_2 = F_7 ( V_8 , V_3 ) ;
goto V_96;
}
if ( F_3 ( V_8 , V_44 - V_45 , V_12 , V_2 ) == - 1 )
{
goto V_96;
}
}
}
V_51 [ V_52 ] = '\0' ;
V_42 -> V_97 = ( ( V_98 ) strlen ( V_51 ) ) / 2 ;
F_20 ( V_31 , V_99 ) ;
F_21 ( V_51 , F_22 ( V_31 ) , strlen ( V_51 ) ) ;
* V_2 = 0 ;
F_23 ( V_51 ) ;
return TRUE ;
V_96:
F_23 ( V_51 ) ;
return FALSE ;
}
static int
F_8 ( V_37 * V_31 , T_6 V_100 )
{
T_6 V_58 ;
V_37 * V_101 ;
V_101 = V_31 ;
for ( V_58 = 0 ; V_58 < V_100 ; V_58 ++ )
{
switch ( V_31 [ V_58 ] )
{
case 0xFE :
case 0xFF :
case 0x00 :
break;
default:
* V_101 = V_31 [ V_58 ] ;
V_101 ++ ;
}
if ( V_31 [ V_58 ] == 0x0A )
return V_58 ;
}
return V_58 ;
}
static T_5
F_21 ( const char * V_102 , V_37 * V_31 , T_11 V_90 )
{
T_11 V_58 ;
int V_103 ;
T_4 V_104 ;
V_37 V_105 ;
V_103 = 0 ;
for ( V_58 = 0 ; V_58 < V_90 ; V_58 ++ )
{
V_104 = F_24 ( V_102 [ V_58 ] ) ;
V_58 ++ ;
if ( V_104 == - 1 )
return FALSE ;
V_105 = ( V_37 ) ( V_104 << 4 ) ;
if ( V_58 >= V_90 )
return FALSE ;
V_104 = F_24 ( V_102 [ V_58 ] ) ;
if ( V_104 == - 1 )
return FALSE ;
V_105 |= ( V_37 ) V_104 ;
V_31 [ V_103 ] = V_105 ;
V_103 ++ ;
}
return TRUE ;
}
