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
T_7 * V_7 ;
int V_31 , V_32 ;
char line [ V_8 ] ;
V_30 = F_2 ( V_2 , V_3 , V_4 , line ) ;
if ( V_30 < 0 )
return FALSE ;
V_31 = F_10 ( & V_2 -> V_33 , line , V_3 , V_4 ) ;
if ( V_31 == - 1 )
return FALSE ;
F_11 ( V_2 -> V_34 , V_35 ) ;
V_7 = F_12 ( V_2 -> V_34 ) ;
if ( ( V_32 = F_13 ( V_2 -> V_9 , V_31 , V_7 , V_3 ,
V_4 ) ) == - 1 )
return FALSE ;
V_2 -> V_33 . V_36 = V_37 | V_38 ;
V_2 -> V_33 . V_32 = V_32 ;
* V_29 = V_30 ;
return TRUE ;
}
static T_1
V_26 ( T_4 * V_2 , T_3 V_39 ,
struct V_40 * V_33 , T_7 * V_41 , int V_42 ,
int * V_3 , T_2 * * V_4 )
{
char line [ V_8 ] ;
if ( F_9 ( V_2 -> V_43 , V_39 , V_17 , V_3 ) == - 1 )
return FALSE ;
if ( F_5 ( line , V_8 , V_2 -> V_43 ) == NULL ) {
* V_3 = F_4 ( V_2 -> V_43 , V_4 ) ;
if ( * V_3 == 0 ) {
* V_3 = V_16 ;
}
return FALSE ;
}
if ( F_10 ( V_33 , line , V_3 , V_4 ) == - 1 )
return FALSE ;
return F_13 ( V_2 -> V_43 , V_42 , V_41 , V_3 , V_4 ) ;
}
static int
F_10 ( struct V_40 * V_33 , const char * line ,
int * V_3 , T_2 * * V_4 )
{
union V_44 * V_45 = & V_33 -> V_45 ;
int V_46 ;
int V_47 , V_48 , V_49 , V_50 , V_51 , V_52 , V_53 , V_31 ;
int V_54 , V_55 , V_56 , V_57 , error ;
T_6 V_58 , V_59 ;
char V_60 [ V_61 ] = L_1 , V_62 [ 6 ] = L_1 ;
struct V_63 V_63 ;
if ( sscanf ( line , L_2 ,
& V_47 , & V_48 , & V_49 , & V_50 , & V_51 , & V_52 , & V_53 ) == 7 ) {
V_46 = sscanf ( line ,
L_3 ,
& V_47 , & V_48 , & V_49 , & V_50 , & V_51 , & V_52 , & V_53 ,
V_62 , V_60 , & V_31 ,
& V_54 , & V_55 , & V_56 , & V_57 , & error ,
& V_58 , & V_59 ) ;
if ( V_46 != 17 ) {
* V_3 = V_64 ;
* V_4 = F_14 ( L_4 ) ;
return - 1 ;
}
} else {
V_46 = sscanf ( line ,
L_5 ,
V_62 , V_60 , & V_31 ,
& V_54 , & V_55 , & V_56 , & V_57 , & error ,
& V_58 , & V_59 ) ;
if ( V_46 != 10 ) {
* V_3 = V_64 ;
* V_4 = F_14 ( L_6 ) ;
return - 1 ;
}
V_47 = V_48 = V_49 = V_50 = V_51 = V_52 = V_53 = 0 ;
}
{
V_63 . V_65 = V_47 - 1900 ;
V_63 . V_66 = V_48 - 1 ;
V_63 . V_67 = V_49 ;
V_63 . V_68 = V_50 ;
V_63 . V_69 = V_51 ;
V_63 . V_70 = V_52 ;
V_63 . V_71 = - 1 ;
V_33 -> V_72 . V_73 = mktime ( & V_63 ) ;
V_33 -> V_72 . V_74 = V_53 * 10000000 ;
V_33 -> V_42 = V_31 ;
}
if ( strncmp ( V_60 , L_7 , 5 ) == 0 ) {
V_45 -> V_75 . V_76 = V_77 ;
} else if ( strncmp ( V_60 , L_8 , 7 ) == 0 ) {
V_45 -> V_75 . V_76 = V_78 ;
} else if ( strncmp ( V_60 , L_9 , 6 ) == 0 ) {
V_45 -> V_75 . V_76 = V_79 ;
} else if ( strncmp ( V_60 , L_10 , 4 ) == 0 ) {
V_45 -> V_75 . V_76 = V_80 ;
} else if ( strncmp ( V_60 , L_11 , 3 ) == 0 ) {
V_45 -> V_75 . V_76 = V_81 ;
} else if ( strncmp ( V_60 , L_12 , 5 ) == 0 ) {
V_45 -> V_75 . V_76 = V_82 ;
} else if ( strncmp ( V_60 , L_13 , 4 ) == 0 ) {
V_45 -> V_75 . V_76 = V_83 ;
} else if ( strncmp ( V_60 , L_14 , 4 ) == 0 ) {
V_45 -> V_75 . V_76 = V_84 ;
} else {
V_45 -> V_75 . V_76 = V_85 ;
}
if ( strncmp ( V_62 , L_15 , 5 ) == 0 ) {
V_45 -> V_75 . V_62 = V_86 ;
} else if ( strncmp ( V_62 , L_16 , 5 ) == 0 ) {
V_45 -> V_75 . V_62 = V_87 ;
}
F_6 ( V_45 -> V_75 . V_60 , V_60 ,
V_61 ) ;
V_45 -> V_75 . V_54 = V_54 ;
V_45 -> V_75 . V_55 = V_55 ;
V_45 -> V_75 . V_56 = V_56 ;
V_45 -> V_75 . V_57 = V_57 ;
V_45 -> V_75 . V_3 = error ;
return V_31 ;
}
static int
F_13 ( T_8 V_9 , int V_31 , T_7 * V_7 , int * V_3 ,
T_2 * * V_4 )
{
T_2 line [ V_8 ] ;
int V_88 , V_89 , V_90 , V_32 = 0 ;
V_89 = V_31 / 16 + ( ( V_31 % 16 ) ? 1 : 0 ) ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ ) {
if ( F_5 ( line , V_8 , V_9 ) == NULL ) {
* V_3 = F_4 ( V_9 , V_4 ) ;
if ( * V_3 == 0 ) {
* V_3 = V_16 ;
}
return - 1 ;
}
if ( F_1 ( line ) ) {
break;
}
if ( ( V_90 = F_15 ( line , V_7 , V_88 * 16 ) ) == - 1 ) {
* V_3 = V_64 ;
* V_4 = F_14 ( L_17 ) ;
return - 1 ;
}
V_32 += V_90 ;
}
return V_32 ;
}
static int
F_15 ( char * V_91 , T_7 * V_7 , T_6 V_92 )
{
int V_46 , V_88 ;
unsigned int V_93 [ 16 ] ;
V_46 = sscanf ( V_91 , L_18 ,
& V_93 [ 0 ] , & V_93 [ 1 ] , & V_93 [ 2 ] , & V_93 [ 3 ] ,
& V_93 [ 4 ] , & V_93 [ 5 ] , & V_93 [ 6 ] , & V_93 [ 7 ] ,
& V_93 [ 8 ] , & V_93 [ 9 ] , & V_93 [ 10 ] , & V_93 [ 11 ] ,
& V_93 [ 12 ] , & V_93 [ 13 ] , & V_93 [ 14 ] , & V_93 [ 15 ] ) ;
if ( V_46 == 0 )
return - 1 ;
if ( V_46 > 16 )
V_46 = 16 ;
for ( V_88 = 0 ; V_88 < V_46 ; V_88 ++ ) {
V_7 [ V_92 + V_88 ] = ( T_7 ) V_93 [ V_88 ] ;
}
return V_46 ;
}
