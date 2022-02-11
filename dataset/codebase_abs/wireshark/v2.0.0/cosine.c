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
int V_33 ;
char line [ V_7 ] ;
V_32 = F_3 ( V_1 , V_2 , V_3 , line ) ;
if ( V_32 < 0 )
return FALSE ;
* V_31 = V_32 ;
V_33 = F_11 ( & V_1 -> V_34 , line , V_2 , V_3 ) ;
if ( V_33 == - 1 )
return FALSE ;
return F_12 ( V_1 -> V_8 , & V_1 -> V_34 , V_33 ,
V_1 -> V_35 , V_2 , V_3 ) ;
}
static T_1
V_27 ( T_4 * V_1 , T_3 V_36 , struct V_37 * V_34 ,
T_8 * V_6 , int * V_2 , T_2 * * V_3 )
{
int V_33 ;
char line [ V_7 ] ;
if ( F_10 ( V_1 -> V_38 , V_36 , V_18 , V_2 ) == - 1 )
return FALSE ;
if ( F_6 ( line , V_7 , V_1 -> V_38 ) == NULL ) {
* V_2 = F_5 ( V_1 -> V_38 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_15 ;
}
return FALSE ;
}
V_33 = F_11 ( V_34 , line , V_2 , V_3 ) ;
if ( V_33 == - 1 )
return FALSE ;
return F_12 ( V_1 -> V_38 , V_34 , V_33 , V_6 , V_2 ,
V_3 ) ;
}
static int
F_11 ( struct V_37 * V_34 , const char * line ,
int * V_2 , T_2 * * V_3 )
{
union V_39 * V_40 = & V_34 -> V_40 ;
int V_41 ;
int V_42 , V_43 , V_44 , V_45 , V_46 , V_47 , V_48 , V_33 ;
int V_49 , V_50 , V_51 , V_52 , error ;
T_6 V_53 , V_54 ;
char V_55 [ V_56 ] = L_1 , V_57 [ 6 ] = L_1 ;
struct V_58 V_58 ;
if ( sscanf ( line , L_2 ,
& V_42 , & V_43 , & V_44 , & V_45 , & V_46 , & V_47 , & V_48 ) == 7 ) {
V_41 = sscanf ( line ,
L_3 ,
& V_42 , & V_43 , & V_44 , & V_45 , & V_46 , & V_47 , & V_48 ,
V_57 , V_55 , & V_33 ,
& V_49 , & V_50 , & V_51 , & V_52 , & error ,
& V_53 , & V_54 ) ;
if ( V_41 != 17 ) {
* V_2 = V_59 ;
* V_3 = F_13 ( L_4 ) ;
return - 1 ;
}
} else {
V_41 = sscanf ( line ,
L_5 ,
V_57 , V_55 , & V_33 ,
& V_49 , & V_50 , & V_51 , & V_52 , & error ,
& V_53 , & V_54 ) ;
if ( V_41 != 10 ) {
* V_2 = V_59 ;
* V_3 = F_13 ( L_6 ) ;
return - 1 ;
}
V_42 = V_43 = V_44 = V_45 = V_46 = V_47 = V_48 = 0 ;
}
V_34 -> V_60 = V_61 ;
V_34 -> V_62 = V_63 | V_64 ;
V_58 . V_65 = V_42 - 1900 ;
V_58 . V_66 = V_43 - 1 ;
V_58 . V_67 = V_44 ;
V_58 . V_68 = V_45 ;
V_58 . V_69 = V_46 ;
V_58 . V_70 = V_47 ;
V_58 . V_71 = - 1 ;
V_34 -> V_72 . V_73 = mktime ( & V_58 ) ;
V_34 -> V_72 . V_74 = V_48 * 10000000 ;
V_34 -> V_75 = V_33 ;
if ( strncmp ( V_55 , L_7 , 5 ) == 0 ) {
V_40 -> V_76 . V_77 = V_78 ;
} else if ( strncmp ( V_55 , L_8 , 7 ) == 0 ) {
V_40 -> V_76 . V_77 = V_79 ;
} else if ( strncmp ( V_55 , L_9 , 6 ) == 0 ) {
V_40 -> V_76 . V_77 = V_80 ;
} else if ( strncmp ( V_55 , L_10 , 4 ) == 0 ) {
V_40 -> V_76 . V_77 = V_81 ;
} else if ( strncmp ( V_55 , L_11 , 3 ) == 0 ) {
V_40 -> V_76 . V_77 = V_82 ;
} else if ( strncmp ( V_55 , L_12 , 5 ) == 0 ) {
V_40 -> V_76 . V_77 = V_83 ;
} else if ( strncmp ( V_55 , L_13 , 4 ) == 0 ) {
V_40 -> V_76 . V_77 = V_84 ;
} else if ( strncmp ( V_55 , L_14 , 4 ) == 0 ) {
V_40 -> V_76 . V_77 = V_85 ;
} else {
V_40 -> V_76 . V_77 = V_86 ;
}
if ( strncmp ( V_57 , L_15 , 5 ) == 0 ) {
V_40 -> V_76 . V_57 = V_87 ;
} else if ( strncmp ( V_57 , L_16 , 5 ) == 0 ) {
V_40 -> V_76 . V_57 = V_88 ;
}
F_7 ( V_40 -> V_76 . V_55 , V_55 ,
V_56 ) ;
V_40 -> V_76 . V_49 = V_49 ;
V_40 -> V_76 . V_50 = V_50 ;
V_40 -> V_76 . V_51 = V_51 ;
V_40 -> V_76 . V_52 = V_52 ;
V_40 -> V_76 . V_2 = error ;
return V_33 ;
}
static T_1
F_12 ( T_9 V_8 , struct V_37 * V_34 , int V_33 ,
T_8 * V_6 , int * V_2 , T_2 * * V_3 )
{
T_10 * V_89 ;
T_2 line [ V_7 ] ;
int V_90 , V_91 , V_92 , V_93 = 0 ;
F_14 ( V_6 , V_94 ) ;
V_89 = F_15 ( V_6 ) ;
V_91 = V_33 / 16 + ( ( V_33 % 16 ) ? 1 : 0 ) ;
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ ) {
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
if ( ( V_92 = F_16 ( line , V_89 , V_90 * 16 ) ) == - 1 ) {
* V_2 = V_59 ;
* V_3 = F_13 ( L_17 ) ;
return FALSE ;
}
V_93 += V_92 ;
}
V_34 -> V_93 = V_93 ;
return TRUE ;
}
static int
F_16 ( char * V_95 , T_10 * V_6 , T_6 V_96 )
{
int V_41 , V_90 ;
unsigned int V_97 [ 16 ] ;
V_41 = sscanf ( V_95 , L_18 ,
& V_97 [ 0 ] , & V_97 [ 1 ] , & V_97 [ 2 ] , & V_97 [ 3 ] ,
& V_97 [ 4 ] , & V_97 [ 5 ] , & V_97 [ 6 ] , & V_97 [ 7 ] ,
& V_97 [ 8 ] , & V_97 [ 9 ] , & V_97 [ 10 ] , & V_97 [ 11 ] ,
& V_97 [ 12 ] , & V_97 [ 13 ] , & V_97 [ 14 ] , & V_97 [ 15 ] ) ;
if ( V_41 == 0 )
return - 1 ;
if ( V_41 > 16 )
V_41 = 16 ;
for ( V_90 = 0 ; V_90 < V_41 ; V_90 ++ ) {
V_6 [ V_96 + V_90 ] = ( T_10 ) V_97 [ V_90 ] ;
}
return V_41 ;
}
