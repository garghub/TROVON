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
T_7 * V_7 , int T_8 V_36 , int * V_3 , T_2 * * V_4 )
{
int V_31 ;
char line [ V_8 ] ;
if ( F_9 ( V_2 -> V_37 , V_34 , V_17 , V_3 ) == - 1 )
return FALSE ;
if ( F_5 ( line , V_8 , V_2 -> V_37 ) == NULL ) {
* V_3 = F_4 ( V_2 -> V_37 , V_4 ) ;
if ( * V_3 == 0 ) {
* V_3 = V_16 ;
}
return FALSE ;
}
V_31 = F_10 ( V_32 , line , V_3 , V_4 ) ;
if ( V_31 == - 1 )
return FALSE ;
return F_11 ( V_2 -> V_37 , V_32 , V_31 , V_7 , V_3 ,
V_4 ) ;
}
static int
F_10 ( struct V_35 * V_32 , const char * line ,
int * V_3 , T_2 * * V_4 )
{
union V_38 * V_39 = & V_32 -> V_39 ;
int V_40 ;
int V_41 , V_42 , V_43 , V_44 , V_45 , V_46 , V_47 , V_31 ;
int V_48 , V_49 , V_50 , V_51 , error ;
T_6 V_52 , V_53 ;
char V_54 [ V_55 ] = L_1 , V_56 [ 6 ] = L_1 ;
struct V_57 V_57 ;
if ( sscanf ( line , L_2 ,
& V_41 , & V_42 , & V_43 , & V_44 , & V_45 , & V_46 , & V_47 ) == 7 ) {
V_40 = sscanf ( line ,
L_3 ,
& V_41 , & V_42 , & V_43 , & V_44 , & V_45 , & V_46 , & V_47 ,
V_56 , V_54 , & V_31 ,
& V_48 , & V_49 , & V_50 , & V_51 , & error ,
& V_52 , & V_53 ) ;
if ( V_40 != 17 ) {
* V_3 = V_58 ;
* V_4 = F_12 ( L_4 ) ;
return - 1 ;
}
} else {
V_40 = sscanf ( line ,
L_5 ,
V_56 , V_54 , & V_31 ,
& V_48 , & V_49 , & V_50 , & V_51 , & error ,
& V_52 , & V_53 ) ;
if ( V_40 != 10 ) {
* V_3 = V_58 ;
* V_4 = F_12 ( L_6 ) ;
return - 1 ;
}
V_41 = V_42 = V_43 = V_44 = V_45 = V_46 = V_47 = 0 ;
}
V_32 -> V_59 = V_60 | V_61 ;
V_57 . V_62 = V_41 - 1900 ;
V_57 . V_63 = V_42 - 1 ;
V_57 . V_64 = V_43 ;
V_57 . V_65 = V_44 ;
V_57 . V_66 = V_45 ;
V_57 . V_67 = V_46 ;
V_57 . V_68 = - 1 ;
V_32 -> V_69 . V_70 = mktime ( & V_57 ) ;
V_32 -> V_69 . V_71 = V_47 * 10000000 ;
V_32 -> T_8 = V_31 ;
if ( strncmp ( V_54 , L_7 , 5 ) == 0 ) {
V_39 -> V_72 . V_73 = V_74 ;
} else if ( strncmp ( V_54 , L_8 , 7 ) == 0 ) {
V_39 -> V_72 . V_73 = V_75 ;
} else if ( strncmp ( V_54 , L_9 , 6 ) == 0 ) {
V_39 -> V_72 . V_73 = V_76 ;
} else if ( strncmp ( V_54 , L_10 , 4 ) == 0 ) {
V_39 -> V_72 . V_73 = V_77 ;
} else if ( strncmp ( V_54 , L_11 , 3 ) == 0 ) {
V_39 -> V_72 . V_73 = V_78 ;
} else if ( strncmp ( V_54 , L_12 , 5 ) == 0 ) {
V_39 -> V_72 . V_73 = V_79 ;
} else if ( strncmp ( V_54 , L_13 , 4 ) == 0 ) {
V_39 -> V_72 . V_73 = V_80 ;
} else if ( strncmp ( V_54 , L_14 , 4 ) == 0 ) {
V_39 -> V_72 . V_73 = V_81 ;
} else {
V_39 -> V_72 . V_73 = V_82 ;
}
if ( strncmp ( V_56 , L_15 , 5 ) == 0 ) {
V_39 -> V_72 . V_56 = V_83 ;
} else if ( strncmp ( V_56 , L_16 , 5 ) == 0 ) {
V_39 -> V_72 . V_56 = V_84 ;
}
F_6 ( V_39 -> V_72 . V_54 , V_54 ,
V_55 ) ;
V_39 -> V_72 . V_48 = V_48 ;
V_39 -> V_72 . V_49 = V_49 ;
V_39 -> V_72 . V_50 = V_50 ;
V_39 -> V_72 . V_51 = V_51 ;
V_39 -> V_72 . V_3 = error ;
return V_31 ;
}
static T_1
F_11 ( T_9 V_9 , struct V_35 * V_32 , int V_31 ,
T_7 * V_7 , int * V_3 , T_2 * * V_4 )
{
T_10 * V_85 ;
T_2 line [ V_8 ] ;
int V_86 , V_87 , V_88 , V_89 = 0 ;
F_13 ( V_7 , V_90 ) ;
V_85 = F_14 ( V_7 ) ;
V_87 = V_31 / 16 + ( ( V_31 % 16 ) ? 1 : 0 ) ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
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
if ( ( V_88 = F_15 ( line , V_85 , V_86 * 16 ) ) == - 1 ) {
* V_3 = V_58 ;
* V_4 = F_12 ( L_17 ) ;
return FALSE ;
}
V_89 += V_88 ;
}
V_32 -> V_89 = V_89 ;
return TRUE ;
}
static int
F_15 ( char * V_91 , T_10 * V_7 , T_6 V_92 )
{
int V_40 , V_86 ;
unsigned int V_93 [ 16 ] ;
V_40 = sscanf ( V_91 , L_18 ,
& V_93 [ 0 ] , & V_93 [ 1 ] , & V_93 [ 2 ] , & V_93 [ 3 ] ,
& V_93 [ 4 ] , & V_93 [ 5 ] , & V_93 [ 6 ] , & V_93 [ 7 ] ,
& V_93 [ 8 ] , & V_93 [ 9 ] , & V_93 [ 10 ] , & V_93 [ 11 ] ,
& V_93 [ 12 ] , & V_93 [ 13 ] , & V_93 [ 14 ] , & V_93 [ 15 ] ) ;
if ( V_40 == 0 )
return - 1 ;
if ( V_40 > 16 )
V_40 = 16 ;
for ( V_86 = 0 ; V_86 < V_40 ; V_86 ++ ) {
V_7 [ V_92 + V_86 ] = ( T_10 ) V_93 [ V_86 ] ;
}
return V_40 ;
}
