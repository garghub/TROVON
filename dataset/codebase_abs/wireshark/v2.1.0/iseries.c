T_1
F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_4 V_4 ;
char V_5 [ V_6 ] ;
if ( ! F_2 ( V_1 -> V_7 , & V_5 , sizeof V_5 , V_2 , V_3 ) )
{
if ( * V_2 != V_8 )
return V_9 ;
return V_10 ;
}
V_4 = 0 ;
while ( ( unsigned int ) V_4 < ( V_6 - ( sizeof F_3 ) ) )
{
if ( memcmp ( V_5 + V_4 , F_3 , sizeof F_3 ) == 0 ) {
if ( F_4 ( V_1 -> V_7 , 0 , V_11 , V_2 ) == - 1 )
{
return V_9 ;
}
if ( ! F_5 ( V_1 , V_2 , V_3 , V_12 ) )
{
if ( * V_2 == 0 )
return V_10 ;
else
return V_9 ;
}
V_1 -> V_13 = V_14 ;
V_1 -> V_15 = V_16 ;
V_1 -> V_17 = 0 ;
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = V_23 ;
if ( F_4 ( V_1 -> V_7 , 0 , V_11 , V_2 ) == - 1 )
{
return V_9 ;
}
return V_24 ;
}
V_4 += 1 ;
}
V_4 = 0 ;
while ( ( unsigned int ) V_4 < ( V_6 - sizeof F_6 ) )
{
if ( memcmp ( V_5 + V_4 , F_6 , sizeof F_6 ) == 0 )
{
if ( F_4 ( V_1 -> V_7 , 0 , V_11 , V_2 ) == - 1 )
{
return V_9 ;
}
if ( ! F_5 ( V_1 , V_2 , V_3 , V_25 ) )
{
if ( * V_2 == 0 )
return V_10 ;
else
return V_9 ;
}
V_1 -> V_13 = V_14 ;
V_1 -> V_15 = V_16 ;
V_1 -> V_17 = 0 ;
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = V_23 ;
if ( F_4 ( V_1 -> V_7 , 0 , V_11 , V_2 ) == - 1 )
{
return V_9 ;
}
return V_24 ;
}
V_4 += 1 ;
}
return V_10 ;
}
static T_5
F_5 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , int V_26 )
{
T_5 V_27 = FALSE ;
T_6 line ;
int V_28 ;
char V_29 [ V_6 ] , V_30 [ 9 ] ;
T_7 * V_31 ;
V_31 = ( T_7 * ) F_7 ( sizeof ( T_7 ) ) ;
V_31 -> V_32 = FALSE ;
V_31 -> V_26 = V_26 ;
for ( line = 0 ; line < V_33 ; line ++ )
{
memset ( V_29 , 0x0 , sizeof( V_29 ) ) ;
if ( F_8 ( V_29 , V_6 , V_1 -> V_7 ) == NULL )
{
* V_2 = F_9 ( V_1 -> V_7 , V_3 ) ;
if ( * V_2 == V_8 )
* V_2 = 0 ;
break;
}
if ( V_31 -> V_26 == V_12 )
{
F_10 ( ( V_34 * ) V_29 , V_6 ) ;
}
F_11 ( V_29 ) ;
V_28 = sscanf ( V_29 ,
L_1 ,
V_30 ) ;
if ( V_28 == 1 )
{
if ( memcmp ( V_30 , L_2 , 8 ) == 0 )
{
* V_2 = 0 ;
V_27 = TRUE ;
}
}
V_28 = sscanf ( V_29 ,
L_3 ,
& V_31 -> V_35 , & V_31 -> V_36 ,
& V_31 -> V_37 ) ;
if ( V_28 == 3 )
{
V_31 -> V_32 = TRUE ;
}
}
if ( V_27 )
V_1 -> V_38 = ( void * ) V_31 ;
else
F_12 ( V_31 ) ;
return V_27 ;
}
static T_5
V_19 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , T_8 * V_39 )
{
T_8 V_4 ;
V_4 = F_13 ( V_1 , V_2 , V_3 ) ;
if ( V_4 < 0 )
return FALSE ;
* V_39 = V_4 ;
return F_14 ( V_1 , V_1 -> V_7 , & V_1 -> V_40 , V_1 -> V_41 ,
V_2 , V_3 ) ;
}
static T_8
F_13 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_7 * V_31 = ( T_7 * ) V_1 -> V_38 ;
char V_29 [ V_6 ] , type [ 5 ] ;
int line , V_28 ;
T_8 V_42 ;
long V_43 ;
for ( line = 0 ; line < V_44 ; line ++ )
{
if ( F_8 ( V_29 , V_6 , V_1 -> V_7 ) == NULL )
{
* V_2 = F_9 ( V_1 -> V_7 , V_3 ) ;
return - 1 ;
}
if ( V_31 -> V_26 == V_12 )
{
V_43 = F_10 ( ( V_34 * ) V_29 , V_6 ) ;
}
else
{
V_43 = ( long ) strlen ( V_29 ) ;
}
F_11 ( V_29 ) ;
V_28 =
sscanf ( V_29 + 78 ,
L_4 , type ) ;
if ( V_28 == 1 )
{
V_42 = F_15 ( V_1 -> V_7 ) ;
if ( V_42 == - 1 )
{
* V_2 = F_9 ( V_1 -> V_7 , V_3 ) ;
return - 1 ;
}
if ( F_4 ( V_1 -> V_7 , V_42 - V_43 , V_11 , V_2 ) == - 1 )
{
return - 1 ;
}
return V_42 - V_43 ;
}
}
* V_2 = V_45 ;
* V_3 =
F_16 ( L_5 ,
V_44 ) ;
return - 1 ;
}
static T_5
V_21 ( T_2 * V_1 , T_8 V_46 , struct V_47 * V_40 ,
T_9 * V_29 , int * V_2 , T_3 * * V_3 )
{
if ( F_4 ( V_1 -> V_48 , V_46 - 1 , V_11 , V_2 ) == - 1 )
return FALSE ;
return F_14 ( V_1 , V_1 -> V_48 , V_40 , V_29 ,
V_2 , V_3 ) ;
}
static int
F_17 ( char * V_49 , int V_50 , int V_51 ,
char * V_52 , int * V_2 , T_3 * * V_3 )
{
int V_53 , V_54 ;
int V_55 ;
unsigned int V_56 ;
T_5 V_57 = FALSE ;
V_53 = 0 ;
V_54 = V_50 ;
for (; ; )
{
for ( V_56 = 0 ; V_56 < 16 ; V_56 ++ , V_53 ++ )
{
V_55 = V_52 [ V_53 ] & 0xFF ;
if ( V_55 == '\0' || V_55 == ' ' || V_55 == '*' || V_55 == '\r' || V_55 == '\n' )
{
goto V_58;
}
if ( ! F_18 ( V_55 ) || F_19 ( V_55 ) )
{
return V_50 ;
}
if ( V_54 >= V_51 )
V_57 = TRUE ;
else
{
V_49 [ V_54 ] = V_55 ;
V_54 ++ ;
}
}
for (; ( V_52 [ V_53 ] & 0xFF ) == ' ' ; V_53 ++ )
;
}
V_58:
if ( ( V_56 % 2 ) != 0 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_6 ) ;
return - 1 ;
}
if ( V_57 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_7 ) ;
return - 1 ;
}
return V_54 ;
}
static T_5
F_14 ( T_2 * V_1 , T_10 V_7 , struct V_47 * V_40 ,
T_9 * V_29 , int * V_2 , T_3 * * V_3 )
{
T_7 * V_31 = ( T_7 * ) V_1 -> V_38 ;
T_8 V_42 ;
T_5 V_59 , V_60 ;
int V_28 , line , V_61 , V_43 ;
int V_62 , V_63 , V_64 , V_65 , V_66 ;
char V_67 [ 2 ] , V_68 [ 13 ] , V_69 [ 13 ] , type [ 5 ] , V_70 [ 9 + 1 ] ;
char V_52 [ V_6 * 2 ] ;
int V_4 ;
char * V_49 ;
int V_50 ;
struct V_71 V_71 ;
V_59 = FALSE ;
for ( line = 1 ; line < V_72 ; line ++ )
{
if ( F_8 ( V_52 , V_6 , V_7 ) == NULL )
{
* V_2 = F_9 ( V_7 , V_3 ) ;
return FALSE ;
}
if ( V_31 -> V_26 == V_12 )
{
F_10 ( ( V_34 * ) V_52 , V_6 ) ;
}
F_11 ( V_52 ) ;
V_28 =
sscanf ( V_52 ,
L_8
L_9 ,
& V_63 , V_67 , & V_62 , & V_64 , & V_65 , & V_66 , V_70 , V_68 ,
V_69 , type ) ;
if ( V_28 == 10 )
{
if ( V_63 < 0 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_10 ) ;
return FALSE ;
}
if ( V_62 < 0 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_11 ) ;
return FALSE ;
}
if ( V_64 < 0 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_12 ) ;
return FALSE ;
}
if ( V_64 > 23 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_13 ) ;
return FALSE ;
}
if ( V_65 < 0 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_14 ) ;
return FALSE ;
}
if ( V_65 > 59 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_15 ) ;
return FALSE ;
}
if ( V_66 < 0 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_16 ) ;
return FALSE ;
}
if ( V_66 > 60 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_17 ) ;
return FALSE ;
}
if ( strlen ( V_68 ) != 12 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_18 ) ;
return FALSE ;
}
if ( strlen ( V_69 ) != 12 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_19 ) ;
return FALSE ;
}
if ( strlen ( type ) != 4 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_20 ) ;
return FALSE ;
}
V_59 = TRUE ;
if ( V_62 > V_73 - 14 )
{
* V_2 = V_45 ;
* V_3 = F_16 ( L_21 V_74 L_22 ,
( V_75 ) V_62 + 14 ,
V_73 ) ;
return FALSE ;
}
V_62 += 14 ;
break;
}
}
if ( ! V_59 )
{
* V_2 = V_45 ;
* V_3 = F_20 ( L_23 ) ;
return FALSE ;
}
V_40 -> V_76 = V_77 ;
V_40 -> V_78 = V_79 ;
if ( V_31 -> V_32 )
{
V_40 -> V_78 |= V_80 ;
V_71 . V_81 = 100 + V_31 -> V_37 ;
V_71 . V_82 = V_31 -> V_35 - 1 ;
V_71 . V_83 = V_31 -> V_36 ;
V_71 . V_84 = V_64 ;
V_71 . V_85 = V_65 ;
V_71 . V_86 = V_66 ;
V_71 . V_87 = - 1 ;
V_40 -> V_88 . V_89 = mktime ( & V_71 ) ;
V_70 [ sizeof( V_70 ) - 1 ] = '\0' ;
switch ( strlen ( V_70 ) )
{
case 0 :
V_40 -> V_88 . V_90 = 0 ;
break;
case 1 :
V_40 -> V_88 . V_90 = atoi ( V_70 ) * 100000000 ;
break;
case 2 :
V_40 -> V_88 . V_90 = atoi ( V_70 ) * 10000000 ;
break;
case 3 :
V_40 -> V_88 . V_90 = atoi ( V_70 ) * 1000000 ;
break;
case 4 :
V_40 -> V_88 . V_90 = atoi ( V_70 ) * 100000 ;
break;
case 5 :
V_40 -> V_88 . V_90 = atoi ( V_70 ) * 10000 ;
break;
case 6 :
V_40 -> V_88 . V_90 = atoi ( V_70 ) * 1000 ;
break;
case 7 :
V_40 -> V_88 . V_90 = atoi ( V_70 ) * 100 ;
break;
case 8 :
V_40 -> V_88 . V_90 = atoi ( V_70 ) * 10 ;
break;
case 9 :
V_40 -> V_88 . V_90 = atoi ( V_70 ) ;
break;
}
}
V_40 -> V_91 = V_62 ;
V_40 -> V_92 = V_14 ;
V_40 -> V_93 . V_94 . V_95 = - 1 ;
V_49 = ( char * ) F_7 ( V_62 * 2 ) ;
V_50 = 0 ;
memcpy ( & V_49 [ 0 ] , V_68 , 12 ) ;
V_50 += 12 ;
memcpy ( & V_49 [ 12 ] , V_69 , 12 ) ;
V_50 += 12 ;
memcpy ( & V_49 [ 24 ] , type , 4 ) ;
V_50 += 4 ;
V_60 = TRUE ;
V_61 = 0 ;
while ( V_60 )
{
V_61 ++ ;
if ( F_8 ( V_52 , V_6 , V_7 ) == NULL )
{
* V_2 = F_9 ( V_7 , V_3 ) ;
if ( * V_2 == 0 )
{
break;
}
goto V_96;
}
if ( V_31 -> V_26 == V_12 )
{
V_43 = F_10 ( ( V_34 * ) V_52 , V_6 ) ;
}
else
{
V_43 = ( int ) strlen ( V_52 ) ;
}
for ( V_4 = 0 ; F_21 ( V_52 [ V_4 ] ) ; V_4 ++ )
;
if ( V_4 == 22 )
{
if ( strncmp ( V_52 + 22 , L_24 , 14 ) == 0 ||
strncmp ( V_52 + 22 , L_25 , 14 ) == 0 ||
strncmp ( V_52 + 22 , L_26 , 14 ) == 0 ||
strncmp ( V_52 + 22 , L_27 , 14 ) == 0 ||
strncmp ( V_52 + 22 , L_28 , 14 ) == 0 ||
strncmp ( V_52 + 22 , L_29 , 14 ) == 0 ||
strncmp ( V_52 + 22 , L_30 , 14 ) == 0 ||
strncmp ( V_52 + 22 , L_31 , 14 ) == 0 )
{
V_50 = F_17 ( V_49 , V_50 ,
V_62 * 2 ,
V_52 + 22 + 14 , V_2 ,
V_3 ) ;
if ( V_50 == - 1 )
{
return FALSE ;
}
continue;
}
}
if ( V_4 == 9 )
{
if ( strncmp ( V_52 + 9 , L_32 , 18 ) == 0 )
{
V_50 = F_17 ( V_49 , V_50 ,
V_62 * 2 ,
V_52 + 9 + 18 , V_2 ,
V_3 ) ;
if ( V_50 == - 1 )
{
return FALSE ;
}
continue;
}
}
if ( V_4 == 36 || V_4 == 27 )
{
V_50 = F_17 ( V_49 , V_50 ,
V_62 * 2 ,
V_52 + V_4 , V_2 ,
V_3 ) ;
if ( V_50 == - 1 )
{
return FALSE ;
}
continue;
}
F_11 ( V_52 ) ;
V_28 =
sscanf ( V_52 + 78 ,
L_4 , type ) ;
if ( ( V_28 == 1 ) && V_61 > 1 )
{
V_60 = FALSE ;
V_42 = F_15 ( V_7 ) ;
if ( V_42 == - 1 )
{
* V_2 = F_9 ( V_7 , V_3 ) ;
goto V_96;
}
if ( F_4 ( V_7 , V_42 - V_43 , V_11 , V_2 ) == - 1 )
{
goto V_96;
}
}
}
V_40 -> V_97 = ( ( V_98 ) V_50 ) / 2 ;
F_22 ( V_29 , V_40 -> V_97 ) ;
F_23 ( V_49 , F_24 ( V_29 ) , V_50 ) ;
* V_2 = 0 ;
F_12 ( V_49 ) ;
return TRUE ;
V_96:
F_12 ( V_49 ) ;
return FALSE ;
}
static int
F_10 ( V_34 * V_29 , T_6 V_99 )
{
T_6 V_56 ;
V_34 * V_100 ;
V_100 = V_29 ;
for ( V_56 = 0 ; V_56 < V_99 ; V_56 ++ )
{
switch ( V_29 [ V_56 ] )
{
case 0xFE :
case 0xFF :
case 0x00 :
break;
default:
* V_100 = V_29 [ V_56 ] ;
V_100 ++ ;
}
if ( V_29 [ V_56 ] == 0x0A )
return V_56 ;
}
return V_56 ;
}
static T_5
F_23 ( const char * V_101 , V_34 * V_29 , T_11 V_91 )
{
T_11 V_56 ;
int V_102 ;
T_4 V_103 ;
V_34 V_104 ;
V_102 = 0 ;
for ( V_56 = 0 ; V_56 < V_91 ; V_56 ++ )
{
V_103 = F_25 ( V_101 [ V_56 ] ) ;
V_56 ++ ;
if ( V_103 == - 1 )
return FALSE ;
V_104 = ( V_34 ) ( V_103 << 4 ) ;
if ( V_56 >= V_91 )
return FALSE ;
V_103 = F_25 ( V_101 [ V_56 ] ) ;
if ( V_103 == - 1 )
return FALSE ;
V_104 |= ( V_34 ) V_103 ;
V_29 [ V_102 ] = V_104 ;
V_102 ++ ;
}
return TRUE ;
}
