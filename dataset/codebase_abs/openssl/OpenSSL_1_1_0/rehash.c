static void F_1 ( unsigned char * V_1 , unsigned int V_2 )
{
V_1 [ V_2 >> 3 ] |= 1 << ( V_2 & 0x7 ) ;
}
static int F_2 ( unsigned char * V_1 , unsigned int V_2 )
{
return V_1 [ V_2 >> 3 ] & ( 1 << ( V_2 & 0x7 ) ) ;
}
static int F_3 ( enum Type type , unsigned int V_3 , const char * V_4 ,
const unsigned char * V_5 , int V_6 ,
unsigned short V_7 )
{
static T_1 V_8 ;
static T_2 V_9 ;
T_1 * V_10 ;
T_2 * V_11 , * V_12 = NULL ;
unsigned int V_13 = ( type + V_3 ) % F_4 ( V_14 ) ;
for ( V_10 = V_14 [ V_13 ] ; V_10 ; V_10 = V_10 -> V_15 )
if ( V_10 -> type == type && V_10 -> V_3 == V_3 )
break;
if ( V_10 == NULL ) {
V_10 = F_5 ( sizeof( * V_10 ) , L_1 ) ;
* V_10 = V_8 ;
V_10 -> V_15 = V_14 [ V_13 ] ;
V_10 -> type = type ;
V_10 -> V_3 = V_3 ;
V_14 [ V_13 ] = V_10 ;
}
for ( V_11 = V_10 -> V_16 ; V_11 ; V_11 = V_11 -> V_15 ) {
if ( V_5 && memcmp ( V_5 , V_11 -> V_5 , V_17 ) == 0 ) {
F_6 ( V_18 ,
L_2 , F_7 () ,
type == V_19 ? L_3 : L_4 , V_4 ) ;
return 1 ;
}
if ( strcmp ( V_4 , V_11 -> V_4 ) == 0 ) {
V_12 = V_11 ;
if ( V_5 == NULL )
break;
}
}
V_11 = V_12 ;
if ( V_11 == NULL ) {
if ( V_10 -> V_20 >= V_21 ) {
F_6 ( V_18 ,
L_5 ,
F_7 () , V_4 ) ;
return 1 ;
}
V_11 = F_5 ( sizeof( * V_11 ) , L_6 ) ;
* V_11 = V_9 ;
V_11 -> V_7 = ~ 0 ;
V_11 -> V_4 = F_8 ( V_4 ) ;
if ( V_10 -> V_22 )
V_10 -> V_22 -> V_15 = V_11 ;
if ( V_10 -> V_16 == NULL )
V_10 -> V_16 = V_11 ;
V_10 -> V_22 = V_11 ;
}
if ( V_7 < V_11 -> V_7 )
V_11 -> V_7 = V_7 ;
if ( V_6 && ! V_11 -> V_6 ) {
V_11 -> V_6 = 1 ;
V_10 -> V_20 ++ ;
memcpy ( V_11 -> V_5 , V_5 , V_17 ) ;
}
return 0 ;
}
static int F_9 ( const char * V_4 , const char * V_23 )
{
unsigned int V_3 = 0 ;
int V_24 , type , V_25 ;
unsigned char V_26 ;
char V_27 [ V_28 ] , * V_29 ;
T_3 V_30 ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
V_26 = V_4 [ V_24 ] ;
if ( ! isxdigit ( V_26 ) )
return - 1 ;
V_3 <<= 4 ;
V_3 += F_10 ( V_26 ) ;
}
if ( V_4 [ V_24 ++ ] != '.' )
return - 1 ;
for ( type = F_4 ( V_31 ) - 1 ; type > 0 ; type -- ) {
const char * V_32 = V_31 [ type ] ;
if ( strncasecmp ( V_32 , & V_4 [ V_24 ] , strlen ( V_32 ) ) == 0 )
break;
}
V_24 += strlen ( V_31 [ type ] ) ;
V_25 = strtoul ( & V_4 [ V_24 ] , & V_29 , 10 ) ;
if ( * V_29 != '\0' )
return - 1 ;
V_30 = F_11 ( V_23 , V_27 , sizeof( V_27 ) ) ;
if ( V_30 < 0 || V_30 >= ( int ) sizeof( V_27 ) )
return - 1 ;
V_27 [ V_30 ] = 0 ;
return F_3 ( type , V_3 , V_27 , NULL , 0 , V_25 ) ;
}
static int F_12 ( const char * V_4 , const char * V_23 , enum V_33 V_34 )
{
F_13 ( V_35 ) * V_36 = NULL ;
V_35 * V_37 ;
T_4 * V_38 = NULL ;
T_5 * V_39 ;
const char * V_40 ;
unsigned char V_5 [ V_41 ] ;
int type , V_42 = 0 ;
T_6 V_24 ;
if ( ( V_40 = strrchr ( V_4 , '.' ) ) == NULL )
goto V_43;
for ( V_24 = 0 ; V_24 < F_4 ( V_44 ) ; V_24 ++ ) {
if ( strcasecmp ( V_44 [ V_24 ] , V_40 + 1 ) == 0 )
break;
}
if ( V_24 >= F_4 ( V_44 ) )
goto V_43;
if ( ( V_39 = F_14 ( V_23 , L_7 ) ) == NULL ) {
F_6 ( V_18 , L_8 ,
F_7 () , V_4 ) ;
V_42 ++ ;
goto V_43;
}
V_36 = F_15 ( V_39 , NULL , NULL , NULL ) ;
F_16 ( V_39 ) ;
if ( V_36 == NULL )
goto V_43;
if ( F_17 ( V_36 ) != 1 ) {
F_6 ( V_18 ,
L_9
L_10 ,
F_7 () , V_4 ) ;
goto V_43;
}
V_37 = F_18 ( V_36 , 0 ) ;
if ( V_37 -> V_45 ) {
type = V_19 ;
V_38 = F_19 ( V_37 -> V_45 ) ;
F_20 ( V_37 -> V_45 , V_46 , V_5 , NULL ) ;
} else if ( V_37 -> V_47 ) {
type = V_48 ;
V_38 = F_21 ( V_37 -> V_47 ) ;
F_22 ( V_37 -> V_47 , V_46 , V_5 , NULL ) ;
} else {
++ V_42 ;
goto V_43;
}
if ( V_38 ) {
if ( ( V_34 == V_49 ) || ( V_34 == V_50 ) )
V_42 += F_3 ( type , F_23 ( V_38 ) , V_4 , V_5 , 1 , ~ 0 ) ;
if ( ( V_34 == V_51 ) || ( V_34 == V_50 ) )
V_42 += F_3 ( type , F_24 ( V_38 ) , V_4 , V_5 , 1 , ~ 0 ) ;
}
V_43:
F_25 ( V_36 , V_52 ) ;
return V_42 ;
}
static void F_26 ( char * V_53 )
{
F_27 ( V_53 ) ;
}
static int F_28 ( const char * V_54 , enum V_33 V_34 )
{
T_1 * V_10 , * V_55 ;
T_2 * V_11 , * V_56 ;
T_7 * V_57 = NULL ;
struct V_58 V_59 ;
unsigned char V_60 [ V_21 / 8 ] ;
int V_30 , V_61 , V_62 , V_63 , V_42 = 0 ;
T_6 V_24 ;
const char * V_64 ;
const char * V_4 ;
char * V_65 , * V_66 ;
F_13 ( V_67 ) * V_68 = NULL ;
if ( F_29 ( V_54 , V_69 ) < 0 ) {
F_6 ( V_18 , L_11 , V_54 ) ;
return 1 ;
}
V_63 = strlen ( V_54 ) ;
V_64 = ( V_63 && V_54 [ V_63 - 1 ] == '/' ) ? L_12 : L_13 ;
V_63 += V_70 + 1 + 1 ;
V_65 = F_5 ( V_63 , L_14 ) ;
if ( V_71 )
F_6 ( V_72 , L_15 , V_54 ) ;
if ( ( V_68 = F_30 () ) == NULL ) {
F_6 ( V_18 , L_16 , V_54 ) ;
exit ( 1 ) ;
}
while ( ( V_4 = F_31 ( & V_57 , V_54 ) ) != NULL ) {
if ( ( V_66 = F_32 ( V_4 ) ) == NULL
|| F_33 ( V_68 , V_66 ) == 0 ) {
F_34 ( V_18 , L_17 ) ;
exit ( 1 ) ;
}
}
F_35 ( & V_57 ) ;
F_36 ( V_68 ) ;
V_61 = F_37 ( V_68 ) ;
for ( V_30 = 0 ; V_30 < V_61 ; ++ V_30 ) {
V_4 = F_38 ( V_68 , V_30 ) ;
if ( snprintf ( V_65 , V_63 , L_18 ,
V_54 , V_64 , V_4 ) >= V_63 )
continue;
if ( F_39 ( V_65 , & V_59 ) < 0 )
continue;
if ( F_40 ( V_59 . V_73 ) && F_9 ( V_4 , V_65 ) == 0 )
continue;
V_42 += F_12 ( V_4 , V_65 , V_34 ) ;
}
F_41 ( V_68 , F_26 ) ;
for ( V_24 = 0 ; V_24 < F_4 ( V_14 ) ; V_24 ++ ) {
for ( V_10 = V_14 [ V_24 ] ; V_10 ; V_10 = V_55 ) {
V_55 = V_10 -> V_15 ;
V_62 = 0 ;
memset ( V_60 , 0 , ( V_10 -> V_20 + 7 ) / 8 ) ;
for ( V_11 = V_10 -> V_16 ; V_11 ; V_11 = V_11 -> V_15 )
if ( V_11 -> V_7 < V_10 -> V_20 )
F_1 ( V_60 , V_11 -> V_7 ) ;
for ( V_11 = V_10 -> V_16 ; V_11 ; V_11 = V_56 ) {
V_56 = V_11 -> V_15 ;
if ( V_11 -> V_7 < V_10 -> V_20 ) {
snprintf ( V_65 , V_63 , L_19 , V_10 -> V_3 ,
V_31 [ V_10 -> type ] , V_11 -> V_7 ) ;
if ( V_71 )
F_6 ( V_72 , L_20 ,
V_11 -> V_4 , V_65 ) ;
} else if ( V_11 -> V_6 ) {
while ( F_2 ( V_60 , V_62 ) )
V_62 ++ ;
snprintf ( V_65 , V_63 , L_21 ,
V_54 , V_64 , & V_30 , V_10 -> V_3 ,
V_31 [ V_10 -> type ] , V_62 ) ;
if ( V_71 )
F_6 ( V_72 , L_20 ,
V_11 -> V_4 , & V_65 [ V_30 ] ) ;
if ( F_42 ( V_65 ) < 0 && V_74 != V_75 ) {
F_6 ( V_18 ,
L_22 ,
F_7 () , V_65 , strerror ( V_74 ) ) ;
V_42 ++ ;
}
if ( F_43 ( V_11 -> V_4 , V_65 ) < 0 ) {
F_6 ( V_18 ,
L_23 ,
F_7 () , V_11 -> V_4 ,
strerror ( V_74 ) ) ;
V_42 ++ ;
}
F_1 ( V_60 , V_62 ) ;
} else if ( V_76 ) {
snprintf ( V_65 , V_63 , L_21 ,
V_54 , V_64 , & V_30 , V_10 -> V_3 ,
V_31 [ V_10 -> type ] , V_11 -> V_7 ) ;
if ( V_71 )
F_6 ( V_72 , L_24 ,
& V_65 [ V_30 ] ) ;
if ( F_42 ( V_65 ) < 0 && V_74 != V_75 ) {
F_6 ( V_18 ,
L_22 ,
F_7 () , V_65 , strerror ( V_74 ) ) ;
V_42 ++ ;
}
}
F_27 ( V_11 -> V_4 ) ;
F_27 ( V_11 ) ;
}
F_27 ( V_10 ) ;
}
V_14 [ V_24 ] = NULL ;
}
F_27 ( V_65 ) ;
return V_42 ;
}
int F_44 ( int V_77 , char * * V_78 )
{
const char * V_79 , * V_80 ;
char * V_81 , * V_82 ;
int V_42 = 0 ;
T_8 V_83 ;
enum V_33 V_34 = V_49 ;
V_80 = F_45 ( V_77 , V_78 , V_84 ) ;
while ( ( V_83 = F_46 () ) != V_85 ) {
switch ( V_83 ) {
case V_85 :
case V_86 :
F_6 ( V_18 , L_25 , V_80 ) ;
goto V_43;
case V_87 :
F_47 ( V_84 ) ;
goto V_43;
case V_88 :
V_34 = V_50 ;
break;
case V_89 :
V_34 = V_51 ;
break;
case V_90 :
V_76 = 0 ;
break;
case V_91 :
V_71 = 1 ;
break;
}
}
V_77 = F_48 () ;
V_78 = F_49 () ;
V_46 = F_50 () ;
V_17 = F_51 ( V_46 ) ;
if ( * V_78 ) {
while ( * V_78 )
V_42 += F_28 ( * V_78 ++ , V_34 ) ;
} else if ( ( V_79 = getenv ( L_26 ) ) != NULL ) {
V_82 = F_8 ( V_79 ) ;
for ( V_81 = strtok ( V_82 , L_27 ) ; V_81 != NULL ; V_81 = strtok ( NULL , L_27 ) )
V_42 += F_28 ( V_81 , V_34 ) ;
F_27 ( V_82 ) ;
} else {
V_42 += F_28 ( L_28 , V_34 ) ;
}
V_43:
return V_42 ;
}
int F_44 ( int V_77 , char * * V_78 )
{
F_6 ( V_18 , L_29 ) ;
return ( 1 ) ;
}
