static T_1 F_1 ( const T_2 * line )
{
while ( * line ) {
if ( isspace ( ( V_1 ) * line ) ) {
line ++ ;
continue;
} else {
break;
}
}
if ( * line == '\0' )
return TRUE ;
else
return FALSE ;
}
static T_3 F_2 ( T_4 * V_2 , int * V_3 , T_2 * * V_4 ,
char * V_5 )
{
T_3 V_6 ;
char V_7 [ V_8 ] ;
while ( 1 ) {
V_6 = F_3 ( V_2 -> V_9 ) ;
if ( V_6 == - 1 ) {
* V_3 = F_4 ( V_2 -> V_9 , V_4 ) ;
V_5 = NULL ;
return - 1 ;
}
if ( F_5 ( V_7 , sizeof( V_7 ) , V_2 -> V_9 ) != NULL ) {
if ( strstr ( V_7 , V_10 ) ||
strstr ( V_7 , V_11 ) ) {
F_6 ( V_5 , V_7 , V_8 ) ;
return V_6 ;
}
} else {
if ( F_7 ( V_2 -> V_9 ) ) {
* V_3 = 0 ;
} else {
* V_3 = F_4 ( V_2 -> V_9 , V_4 ) ;
}
break;
}
}
V_5 = NULL ;
return - 1 ;
}
static T_1 F_8 ( T_4 * V_2 , int * V_3 , T_2 * * V_4 )
{
char V_7 [ V_8 ] ;
T_5 V_12 ;
T_6 line ;
V_7 [ V_8 - 1 ] = '\0' ;
for ( line = 0 ; line < V_13 ; line ++ ) {
if ( F_5 ( V_7 , V_8 , V_2 -> V_9 ) != NULL ) {
V_12 = strlen ( V_7 ) ;
if ( V_12 < strlen ( V_14 ) ||
V_12 < strlen ( V_15 ) ) {
continue;
}
if ( strstr ( V_7 , V_14 ) ||
strstr ( V_7 , V_15 ) ) {
return TRUE ;
}
} else {
if ( F_7 ( V_2 -> V_9 ) )
* V_3 = 0 ;
else
* V_3 = F_4 ( V_2 -> V_9 , V_4 ) ;
return FALSE ;
}
}
* V_3 = 0 ;
return FALSE ;
}
int F_9 ( T_4 * V_2 , int * V_3 , T_2 * * V_4 )
{
if ( ! F_8 ( V_2 , V_3 , V_4 ) ) {
if ( * V_3 == 0 )
return 0 ;
else
return - 1 ;
}
if ( F_10 ( V_2 -> V_9 , 0L , V_16 , V_3 ) == - 1 )
return - 1 ;
V_2 -> V_17 = V_18 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = V_27 ;
return 1 ;
}
static T_1 V_23 ( T_4 * V_2 , int * V_3 , T_2 * * V_4 ,
T_3 * V_28 )
{
T_3 V_29 ;
T_7 * V_7 ;
int V_30 , V_31 ;
char line [ V_8 ] ;
V_29 = F_2 ( V_2 , V_3 , V_4 , line ) ;
if ( V_29 < 0 )
return FALSE ;
V_30 = F_11 ( V_2 , line , & V_2 -> V_32 , V_3 ,
V_4 ) ;
if ( V_30 == - 1 )
return FALSE ;
F_12 ( V_2 -> V_33 , V_34 ) ;
V_7 = F_13 ( V_2 -> V_33 ) ;
if ( ( V_31 = F_14 ( V_2 -> V_9 , V_30 , V_7 , V_3 ,
V_4 ) ) == - 1 )
return FALSE ;
V_2 -> V_35 . V_36 = V_37 | V_38 ;
V_2 -> V_35 . V_31 = V_31 ;
* V_28 = V_29 ;
return TRUE ;
}
static T_1
V_25 ( T_4 * V_2 , T_3 V_39 ,
union V_40 * V_32 , T_7 * V_41 , int V_42 ,
int * V_3 , T_2 * * V_4 )
{
char line [ V_8 ] ;
if ( F_10 ( V_2 -> V_43 , V_39 , V_16 , V_3 ) == - 1 )
return FALSE ;
if ( F_5 ( line , V_8 , V_2 -> V_43 ) == NULL ) {
* V_3 = F_4 ( V_2 -> V_43 , V_4 ) ;
if ( * V_3 == 0 ) {
* V_3 = V_44 ;
}
return FALSE ;
}
if ( F_11 ( NULL , line , V_32 , V_3 , V_4 ) == - 1 )
return FALSE ;
return F_14 ( V_2 -> V_43 , V_42 , V_41 , V_3 , V_4 ) ;
}
static int
F_11 ( T_4 * V_2 , const char * line ,
union V_40 * V_32 , int * V_3 , T_2 * * V_4 )
{
int V_45 ;
int V_46 , V_47 , V_48 , V_49 , V_50 , V_51 , V_52 , V_30 ;
int V_53 , V_54 , V_55 , V_56 , error ;
T_6 V_57 , V_58 ;
char V_59 [ V_60 ] = L_1 , V_61 [ 6 ] = L_1 ;
struct V_62 V_62 ;
if ( sscanf ( line , L_2 ,
& V_46 , & V_47 , & V_48 , & V_49 , & V_50 , & V_51 , & V_52 ) == 7 ) {
V_45 = sscanf ( line ,
L_3 ,
& V_46 , & V_47 , & V_48 , & V_49 , & V_50 , & V_51 , & V_52 ,
V_61 , V_59 , & V_30 ,
& V_53 , & V_54 , & V_55 , & V_56 , & error ,
& V_57 , & V_58 ) ;
if ( V_45 != 17 ) {
* V_3 = V_63 ;
* V_4 = F_15 ( L_4 ) ;
return - 1 ;
}
} else {
V_45 = sscanf ( line ,
L_5 ,
V_61 , V_59 , & V_30 ,
& V_53 , & V_54 , & V_55 , & V_56 , & error ,
& V_57 , & V_58 ) ;
if ( V_45 != 10 ) {
* V_3 = V_63 ;
* V_4 = F_15 ( L_6 ) ;
return - 1 ;
}
V_46 = V_47 = V_48 = V_49 = V_50 = V_51 = V_52 = 0 ;
}
if ( V_2 ) {
V_62 . V_64 = V_46 - 1900 ;
V_62 . V_65 = V_47 - 1 ;
V_62 . V_66 = V_48 ;
V_62 . V_67 = V_49 ;
V_62 . V_68 = V_50 ;
V_62 . V_69 = V_51 ;
V_62 . V_70 = - 1 ;
V_2 -> V_35 . V_71 . V_72 = mktime ( & V_62 ) ;
V_2 -> V_35 . V_71 . V_73 = V_52 * 10000000 ;
V_2 -> V_35 . V_42 = V_30 ;
}
if ( strncmp ( V_59 , L_7 , 5 ) == 0 ) {
V_32 -> V_74 . V_75 = V_76 ;
} else if ( strncmp ( V_59 , L_8 , 7 ) == 0 ) {
V_32 -> V_74 . V_75 = V_77 ;
} else if ( strncmp ( V_59 , L_9 , 6 ) == 0 ) {
V_32 -> V_74 . V_75 = V_78 ;
} else if ( strncmp ( V_59 , L_10 , 4 ) == 0 ) {
V_32 -> V_74 . V_75 = V_79 ;
} else if ( strncmp ( V_59 , L_11 , 3 ) == 0 ) {
V_32 -> V_74 . V_75 = V_80 ;
} else if ( strncmp ( V_59 , L_12 , 5 ) == 0 ) {
V_32 -> V_74 . V_75 = V_81 ;
} else if ( strncmp ( V_59 , L_13 , 4 ) == 0 ) {
V_32 -> V_74 . V_75 = V_82 ;
} else if ( strncmp ( V_59 , L_14 , 4 ) == 0 ) {
V_32 -> V_74 . V_75 = V_83 ;
} else {
V_32 -> V_74 . V_75 = V_84 ;
}
if ( strncmp ( V_61 , L_15 , 5 ) == 0 ) {
V_32 -> V_74 . V_61 = V_85 ;
} else if ( strncmp ( V_61 , L_16 , 5 ) == 0 ) {
V_32 -> V_74 . V_61 = V_86 ;
}
F_6 ( V_32 -> V_74 . V_59 , V_59 ,
V_60 ) ;
V_32 -> V_74 . V_53 = V_53 ;
V_32 -> V_74 . V_54 = V_54 ;
V_32 -> V_74 . V_55 = V_55 ;
V_32 -> V_74 . V_56 = V_56 ;
V_32 -> V_74 . V_3 = error ;
return V_30 ;
}
static int
F_14 ( T_8 V_9 , int V_30 , T_7 * V_7 , int * V_3 ,
T_2 * * V_4 )
{
T_2 line [ V_8 ] ;
int V_87 , V_88 , V_89 , V_31 = 0 ;
V_88 = V_30 / 16 + ( ( V_30 % 16 ) ? 1 : 0 ) ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ ) {
if ( F_5 ( line , V_8 , V_9 ) == NULL ) {
* V_3 = F_4 ( V_9 , V_4 ) ;
if ( * V_3 == 0 ) {
* V_3 = V_44 ;
}
return - 1 ;
}
if ( F_1 ( line ) ) {
break;
}
if ( ( V_89 = F_16 ( line , V_7 , V_87 * 16 ) ) == - 1 ) {
* V_3 = V_63 ;
* V_4 = F_15 ( L_17 ) ;
return - 1 ;
}
V_31 += V_89 ;
}
return V_31 ;
}
static int
F_16 ( char * V_90 , T_7 * V_7 , T_6 V_91 )
{
int V_45 , V_87 ;
unsigned int V_92 [ 16 ] ;
V_45 = sscanf ( V_90 , L_18 ,
& V_92 [ 0 ] , & V_92 [ 1 ] , & V_92 [ 2 ] , & V_92 [ 3 ] ,
& V_92 [ 4 ] , & V_92 [ 5 ] , & V_92 [ 6 ] , & V_92 [ 7 ] ,
& V_92 [ 8 ] , & V_92 [ 9 ] , & V_92 [ 10 ] , & V_92 [ 11 ] ,
& V_92 [ 12 ] , & V_92 [ 13 ] , & V_92 [ 14 ] , & V_92 [ 15 ] ) ;
if ( V_45 == 0 )
return - 1 ;
if ( V_45 > 16 )
V_45 = 16 ;
for ( V_87 = 0 ; V_87 < V_45 ; V_87 ++ ) {
V_7 [ V_91 + V_87 ] = ( T_7 ) V_92 [ V_87 ] ;
}
return V_45 ;
}
