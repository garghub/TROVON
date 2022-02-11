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
return - 1 ;
}
if ( F_5 ( V_7 , sizeof( V_7 ) , V_2 -> V_9 ) == NULL ) {
* V_3 = F_4 ( V_2 -> V_9 , V_4 ) ;
return - 1 ;
}
if ( strstr ( V_7 , V_10 ) ||
strstr ( V_7 , V_11 ) ) {
F_6 ( V_5 , V_7 , V_8 ) ;
return V_6 ;
}
}
return - 1 ;
}
static T_1 F_7 ( T_4 * V_2 , int * V_3 , T_2 * * V_4 )
{
char V_7 [ V_8 ] ;
T_5 V_12 ;
T_6 line ;
V_7 [ V_8 - 1 ] = '\0' ;
for ( line = 0 ; line < V_13 ; line ++ ) {
if ( F_5 ( V_7 , V_8 , V_2 -> V_9 ) == NULL ) {
* V_3 = F_4 ( V_2 -> V_9 , V_4 ) ;
return FALSE ;
}
V_12 = strlen ( V_7 ) ;
if ( V_12 < strlen ( V_14 ) ||
V_12 < strlen ( V_15 ) ) {
continue;
}
if ( strstr ( V_7 , V_14 ) ||
strstr ( V_7 , V_15 ) ) {
return TRUE ;
}
}
* V_3 = 0 ;
return FALSE ;
}
int F_8 ( T_4 * V_2 , int * V_3 , T_2 * * V_4 )
{
if ( ! F_7 ( V_2 , V_3 , V_4 ) ) {
if ( * V_3 != 0 && * V_3 != V_16 )
return - 1 ;
return 0 ;
}
if ( F_9 ( V_2 -> V_9 , 0L , V_17 , V_3 ) == - 1 )
return - 1 ;
V_2 -> V_18 = V_19 ;
V_2 -> V_20 = V_21 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = V_24 ;
V_2 -> V_25 = V_26 ;
V_2 -> V_27 = V_28 ;
return 1 ;
}
static T_1 V_24 ( T_4 * V_2 , int * V_3 , T_2 * * V_4 ,
T_3 * V_29 )
{
T_3 V_30 ;
int V_31 ;
char line [ V_8 ] ;
V_30 = F_2 ( V_2 , V_3 , V_4 , line ) ;
if ( V_30 < 0 )
return FALSE ;
* V_29 = V_30 ;
V_31 = F_10 ( & V_2 -> V_32 , line , V_3 , V_4 ) ;
if ( V_31 == - 1 )
return FALSE ;
return F_11 ( V_2 -> V_9 , & V_2 -> V_32 , V_31 ,
V_2 -> V_33 , V_3 , V_4 ) ;
}
static T_1
V_26 ( T_4 * V_2 , T_3 V_34 , struct V_35 * V_32 ,
T_7 * V_7 , int * V_3 , T_2 * * V_4 )
{
int V_31 ;
char line [ V_8 ] ;
if ( F_9 ( V_2 -> V_36 , V_34 , V_17 , V_3 ) == - 1 )
return FALSE ;
if ( F_5 ( line , V_8 , V_2 -> V_36 ) == NULL ) {
* V_3 = F_4 ( V_2 -> V_36 , V_4 ) ;
if ( * V_3 == 0 ) {
* V_3 = V_16 ;
}
return FALSE ;
}
V_31 = F_10 ( V_32 , line , V_3 , V_4 ) ;
if ( V_31 == - 1 )
return FALSE ;
return F_11 ( V_2 -> V_36 , V_32 , V_31 , V_7 , V_3 ,
V_4 ) ;
}
static int
F_10 ( struct V_35 * V_32 , const char * line ,
int * V_3 , T_2 * * V_4 )
{
union V_37 * V_38 = & V_32 -> V_38 ;
int V_39 ;
int V_40 , V_41 , V_42 , V_43 , V_44 , V_45 , V_46 , V_31 ;
int V_47 , V_48 , V_49 , V_50 , error ;
T_6 V_51 , V_52 ;
char V_53 [ V_54 ] = L_1 , V_55 [ 6 ] = L_1 ;
struct V_56 V_56 ;
if ( sscanf ( line , L_2 ,
& V_40 , & V_41 , & V_42 , & V_43 , & V_44 , & V_45 , & V_46 ) == 7 ) {
V_39 = sscanf ( line ,
L_3 ,
& V_40 , & V_41 , & V_42 , & V_43 , & V_44 , & V_45 , & V_46 ,
V_55 , V_53 , & V_31 ,
& V_47 , & V_48 , & V_49 , & V_50 , & error ,
& V_51 , & V_52 ) ;
if ( V_39 != 17 ) {
* V_3 = V_57 ;
* V_4 = F_12 ( L_4 ) ;
return - 1 ;
}
} else {
V_39 = sscanf ( line ,
L_5 ,
V_55 , V_53 , & V_31 ,
& V_47 , & V_48 , & V_49 , & V_50 , & error ,
& V_51 , & V_52 ) ;
if ( V_39 != 10 ) {
* V_3 = V_57 ;
* V_4 = F_12 ( L_6 ) ;
return - 1 ;
}
V_40 = V_41 = V_42 = V_43 = V_44 = V_45 = V_46 = 0 ;
}
V_32 -> V_58 = V_59 ;
V_32 -> V_60 = V_61 | V_62 ;
V_56 . V_63 = V_40 - 1900 ;
V_56 . V_64 = V_41 - 1 ;
V_56 . V_65 = V_42 ;
V_56 . V_66 = V_43 ;
V_56 . V_67 = V_44 ;
V_56 . V_68 = V_45 ;
V_56 . V_69 = - 1 ;
V_32 -> V_70 . V_71 = mktime ( & V_56 ) ;
V_32 -> V_70 . V_72 = V_46 * 10000000 ;
V_32 -> V_73 = V_31 ;
if ( strncmp ( V_53 , L_7 , 5 ) == 0 ) {
V_38 -> V_74 . V_75 = V_76 ;
} else if ( strncmp ( V_53 , L_8 , 7 ) == 0 ) {
V_38 -> V_74 . V_75 = V_77 ;
} else if ( strncmp ( V_53 , L_9 , 6 ) == 0 ) {
V_38 -> V_74 . V_75 = V_78 ;
} else if ( strncmp ( V_53 , L_10 , 4 ) == 0 ) {
V_38 -> V_74 . V_75 = V_79 ;
} else if ( strncmp ( V_53 , L_11 , 3 ) == 0 ) {
V_38 -> V_74 . V_75 = V_80 ;
} else if ( strncmp ( V_53 , L_12 , 5 ) == 0 ) {
V_38 -> V_74 . V_75 = V_81 ;
} else if ( strncmp ( V_53 , L_13 , 4 ) == 0 ) {
V_38 -> V_74 . V_75 = V_82 ;
} else if ( strncmp ( V_53 , L_14 , 4 ) == 0 ) {
V_38 -> V_74 . V_75 = V_83 ;
} else {
V_38 -> V_74 . V_75 = V_84 ;
}
if ( strncmp ( V_55 , L_15 , 5 ) == 0 ) {
V_38 -> V_74 . V_55 = V_85 ;
} else if ( strncmp ( V_55 , L_16 , 5 ) == 0 ) {
V_38 -> V_74 . V_55 = V_86 ;
}
F_6 ( V_38 -> V_74 . V_53 , V_53 ,
V_54 ) ;
V_38 -> V_74 . V_47 = V_47 ;
V_38 -> V_74 . V_48 = V_48 ;
V_38 -> V_74 . V_49 = V_49 ;
V_38 -> V_74 . V_50 = V_50 ;
V_38 -> V_74 . V_3 = error ;
return V_31 ;
}
static T_1
F_11 ( T_8 V_9 , struct V_35 * V_32 , int V_31 ,
T_7 * V_7 , int * V_3 , T_2 * * V_4 )
{
T_9 * V_87 ;
T_2 line [ V_8 ] ;
int V_88 , V_89 , V_90 , V_91 = 0 ;
F_13 ( V_7 , V_92 ) ;
V_87 = F_14 ( V_7 ) ;
V_89 = V_31 / 16 + ( ( V_31 % 16 ) ? 1 : 0 ) ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ ) {
if ( F_5 ( line , V_8 , V_9 ) == NULL ) {
* V_3 = F_4 ( V_9 , V_4 ) ;
if ( * V_3 == 0 ) {
* V_3 = V_16 ;
}
return FALSE ;
}
if ( F_1 ( line ) ) {
break;
}
if ( ( V_90 = F_15 ( line , V_87 , V_88 * 16 ) ) == - 1 ) {
* V_3 = V_57 ;
* V_4 = F_12 ( L_17 ) ;
return FALSE ;
}
V_91 += V_90 ;
}
V_32 -> V_91 = V_91 ;
return TRUE ;
}
static int
F_15 ( char * V_93 , T_9 * V_7 , T_6 V_94 )
{
int V_39 , V_88 ;
unsigned int V_95 [ 16 ] ;
V_39 = sscanf ( V_93 , L_18 ,
& V_95 [ 0 ] , & V_95 [ 1 ] , & V_95 [ 2 ] , & V_95 [ 3 ] ,
& V_95 [ 4 ] , & V_95 [ 5 ] , & V_95 [ 6 ] , & V_95 [ 7 ] ,
& V_95 [ 8 ] , & V_95 [ 9 ] , & V_95 [ 10 ] , & V_95 [ 11 ] ,
& V_95 [ 12 ] , & V_95 [ 13 ] , & V_95 [ 14 ] , & V_95 [ 15 ] ) ;
if ( V_39 == 0 )
return - 1 ;
if ( V_39 > 16 )
V_39 = 16 ;
for ( V_88 = 0 ; V_88 < V_39 ; V_88 ++ ) {
V_7 [ V_94 + V_88 ] = ( T_9 ) V_95 [ V_88 ] ;
}
return V_39 ;
}
