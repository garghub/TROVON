static T_1 F_1 ( const T_2 * line )
{
while ( * line ) {
if ( F_2 ( * line ) ) {
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
static T_3 F_3 ( T_4 * V_1 , int * V_2 , T_2 * * V_3 ,
char * V_4 )
{
T_3 V_5 ;
char V_6 [ V_7 ] ;
while ( 1 ) {
V_5 = F_4 ( V_1 -> V_8 ) ;
if ( V_5 == - 1 ) {
* V_2 = F_5 ( V_1 -> V_8 , V_3 ) ;
return - 1 ;
}
if ( F_6 ( V_6 , sizeof( V_6 ) , V_1 -> V_8 ) == NULL ) {
* V_2 = F_5 ( V_1 -> V_8 , V_3 ) ;
return - 1 ;
}
if ( strstr ( V_6 , V_9 ) ||
strstr ( V_6 , V_10 ) ) {
F_7 ( V_4 , V_6 , V_7 ) ;
return V_5 ;
}
}
return - 1 ;
}
static T_1 F_8 ( T_4 * V_1 , int * V_2 , T_2 * * V_3 )
{
char V_6 [ V_7 ] ;
T_5 V_11 ;
T_6 line ;
V_6 [ V_7 - 1 ] = '\0' ;
for ( line = 0 ; line < V_12 ; line ++ ) {
if ( F_6 ( V_6 , V_7 , V_1 -> V_8 ) == NULL ) {
* V_2 = F_5 ( V_1 -> V_8 , V_3 ) ;
return FALSE ;
}
V_11 = strlen ( V_6 ) ;
if ( V_11 < strlen ( V_13 ) ||
V_11 < strlen ( V_14 ) ) {
continue;
}
if ( strstr ( V_6 , V_13 ) ||
strstr ( V_6 , V_14 ) ) {
return TRUE ;
}
}
* V_2 = 0 ;
return FALSE ;
}
T_7 F_9 ( T_4 * V_1 , int * V_2 , T_2 * * V_3 )
{
if ( ! F_8 ( V_1 , V_2 , V_3 ) ) {
if ( * V_2 != 0 && * V_2 != V_15 )
return V_16 ;
return V_17 ;
}
if ( F_10 ( V_1 -> V_8 , 0L , V_18 , V_2 ) == - 1 )
return V_16 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = 0 ;
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
return V_30 ;
}
static T_1 V_25 ( T_4 * V_1 , int * V_2 , T_2 * * V_3 ,
T_3 * V_31 )
{
T_3 V_32 ;
char line [ V_7 ] ;
V_32 = F_3 ( V_1 , V_2 , V_3 , line ) ;
if ( V_32 < 0 )
return FALSE ;
* V_31 = V_32 ;
return F_11 ( V_1 -> V_8 , & V_1 -> V_33 , V_1 -> V_34 ,
line , V_2 , V_3 ) ;
}
static T_1
V_27 ( T_4 * V_1 , T_3 V_35 , struct V_36 * V_33 ,
T_8 * V_6 , int * V_2 , T_2 * * V_3 )
{
char line [ V_7 ] ;
if ( F_10 ( V_1 -> V_37 , V_35 , V_18 , V_2 ) == - 1 )
return FALSE ;
if ( F_6 ( line , V_7 , V_1 -> V_37 ) == NULL ) {
* V_2 = F_5 ( V_1 -> V_37 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_15 ;
}
return FALSE ;
}
return F_11 ( V_1 -> V_37 , V_33 , V_6 , line , V_2 ,
V_3 ) ;
}
static T_1
F_11 ( T_9 V_8 , struct V_36 * V_33 , T_8 * V_6 ,
char * line , int * V_2 , T_2 * * V_3 )
{
union V_38 * V_39 = & V_33 -> V_39 ;
int V_40 ;
int V_41 , V_42 , V_43 , V_44 , V_45 , V_46 , V_47 , V_48 ;
int V_49 , V_50 , V_51 , V_52 , error ;
T_6 V_53 , V_54 ;
char V_55 [ V_56 ] = L_1 , V_57 [ 6 ] = L_1 ;
struct V_58 V_58 ;
T_10 * V_59 ;
int V_60 , V_61 , V_62 , V_63 = 0 ;
if ( sscanf ( line , L_2 ,
& V_41 , & V_42 , & V_43 , & V_44 , & V_45 , & V_46 , & V_47 ) == 7 ) {
V_40 = sscanf ( line ,
L_3 ,
& V_41 , & V_42 , & V_43 , & V_44 , & V_45 , & V_46 , & V_47 ,
V_57 , V_55 , & V_48 ,
& V_49 , & V_50 , & V_51 , & V_52 , & error ,
& V_53 , & V_54 ) ;
if ( V_40 != 17 ) {
* V_2 = V_64 ;
* V_3 = F_12 ( L_4 ) ;
return FALSE ;
}
} else {
V_40 = sscanf ( line ,
L_5 ,
V_57 , V_55 , & V_48 ,
& V_49 , & V_50 , & V_51 , & V_52 , & error ,
& V_53 , & V_54 ) ;
if ( V_40 != 10 ) {
* V_2 = V_64 ;
* V_3 = F_12 ( L_6 ) ;
return FALSE ;
}
V_41 = V_42 = V_43 = V_44 = V_45 = V_46 = V_47 = 0 ;
}
if ( V_48 < 0 ) {
* V_2 = V_64 ;
* V_3 = F_12 ( L_7 ) ;
return FALSE ;
}
if ( V_48 > V_65 ) {
* V_2 = V_64 ;
* V_3 = F_13 ( L_8 ,
V_48 , V_65 ) ;
return FALSE ;
}
V_33 -> V_66 = V_67 ;
V_33 -> V_68 = V_69 | V_70 ;
V_58 . V_71 = V_41 - 1900 ;
V_58 . V_72 = V_42 - 1 ;
V_58 . V_73 = V_43 ;
V_58 . V_74 = V_44 ;
V_58 . V_75 = V_45 ;
V_58 . V_76 = V_46 ;
V_58 . V_77 = - 1 ;
V_33 -> V_78 . V_79 = mktime ( & V_58 ) ;
V_33 -> V_78 . V_80 = V_47 * 10000000 ;
V_33 -> V_81 = V_48 ;
if ( strncmp ( V_55 , L_9 , 5 ) == 0 ) {
V_39 -> V_82 . V_83 = V_84 ;
} else if ( strncmp ( V_55 , L_10 , 7 ) == 0 ) {
V_39 -> V_82 . V_83 = V_85 ;
} else if ( strncmp ( V_55 , L_11 , 6 ) == 0 ) {
V_39 -> V_82 . V_83 = V_86 ;
} else if ( strncmp ( V_55 , L_12 , 4 ) == 0 ) {
V_39 -> V_82 . V_83 = V_87 ;
} else if ( strncmp ( V_55 , L_13 , 3 ) == 0 ) {
V_39 -> V_82 . V_83 = V_88 ;
} else if ( strncmp ( V_55 , L_14 , 5 ) == 0 ) {
V_39 -> V_82 . V_83 = V_89 ;
} else if ( strncmp ( V_55 , L_15 , 4 ) == 0 ) {
V_39 -> V_82 . V_83 = V_90 ;
} else if ( strncmp ( V_55 , L_16 , 4 ) == 0 ) {
V_39 -> V_82 . V_83 = V_91 ;
} else {
V_39 -> V_82 . V_83 = V_92 ;
}
if ( strncmp ( V_57 , L_17 , 5 ) == 0 ) {
V_39 -> V_82 . V_57 = V_93 ;
} else if ( strncmp ( V_57 , L_18 , 5 ) == 0 ) {
V_39 -> V_82 . V_57 = V_94 ;
}
F_7 ( V_39 -> V_82 . V_55 , V_55 ,
V_56 ) ;
V_39 -> V_82 . V_49 = V_49 ;
V_39 -> V_82 . V_50 = V_50 ;
V_39 -> V_82 . V_51 = V_51 ;
V_39 -> V_82 . V_52 = V_52 ;
V_39 -> V_82 . V_2 = error ;
F_14 ( V_6 , V_48 ) ;
V_59 = F_15 ( V_6 ) ;
V_61 = V_48 / 16 + ( ( V_48 % 16 ) ? 1 : 0 ) ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
if ( F_6 ( line , V_7 , V_8 ) == NULL ) {
* V_2 = F_5 ( V_8 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_15 ;
}
return FALSE ;
}
if ( F_1 ( line ) ) {
break;
}
if ( ( V_62 = F_16 ( line , V_59 , V_60 * 16 ) ) == - 1 ) {
* V_2 = V_64 ;
* V_3 = F_12 ( L_19 ) ;
return FALSE ;
}
V_63 += V_62 ;
}
V_33 -> V_63 = V_63 ;
return TRUE ;
}
static int
F_16 ( char * V_95 , T_10 * V_6 , T_6 V_96 )
{
int V_40 , V_60 ;
unsigned int V_97 [ 16 ] ;
V_40 = sscanf ( V_95 , L_20 ,
& V_97 [ 0 ] , & V_97 [ 1 ] , & V_97 [ 2 ] , & V_97 [ 3 ] ,
& V_97 [ 4 ] , & V_97 [ 5 ] , & V_97 [ 6 ] , & V_97 [ 7 ] ,
& V_97 [ 8 ] , & V_97 [ 9 ] , & V_97 [ 10 ] , & V_97 [ 11 ] ,
& V_97 [ 12 ] , & V_97 [ 13 ] , & V_97 [ 14 ] , & V_97 [ 15 ] ) ;
if ( V_40 == 0 )
return - 1 ;
if ( V_40 > 16 )
V_40 = 16 ;
for ( V_60 = 0 ; V_60 < V_40 ; V_60 ++ ) {
V_6 [ V_96 + V_60 ] = ( T_10 ) V_97 [ V_60 ] ;
}
return V_40 ;
}
