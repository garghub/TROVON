static int F_1 ( char * V_1 , struct V_2 * V_3 )
{
char V_4 ;
T_1 V_5 ;
struct V_2 V_6 ;
if ( sscanf ( V_1 , L_1 ,
& V_6 . V_7 , & V_4 , & V_6 . V_8 , & V_4 ,
& V_6 . V_9 , & V_4 , & V_6 . V_10 ,
& V_6 . V_11 , & V_4 , & V_5 ) != 10 )
return - V_12 ;
V_5 = F_2 ( V_5 ) ;
memcpy ( & V_6 . V_13 [ 0 ] , ( ( char * ) & V_5 ) + 2 , 6 ) ;
* V_3 = V_6 ;
return 0 ;
}
int F_3 ( struct V_14 * V_15 ,
char * V_16 )
{
int V_17 = 0 ;
if ( V_15 )
V_17 = F_4 ( V_15 , V_16 ,
( V_18 ) V_19 ,
( void * ) V_16 ) ;
else
V_17 = - V_20 ;
return V_17 ;
}
int F_5 ( struct V_14 * V_15 ,
char * V_16 )
{
int V_17 = 0 ;
if ( V_15 )
V_17 = F_4 ( V_15 , V_16 ,
( V_18 ) V_19 ,
NULL ) ;
else
V_17 = - V_20 ;
return V_17 ;
}
int F_6 ( char * V_21 ,
struct V_14 * * V_22 )
{
struct V_23 * V_24 ;
struct V_14 * V_25 = NULL ;
int V_17 = 0 ;
V_17 = F_7 ( & V_24 , V_21 ) ;
if ( V_17 )
goto V_26;
V_25 = F_8 ( sizeof( struct V_14 ) , V_27 ) ;
if ( V_25 != NULL ) {
V_25 -> V_24 = V_24 ;
* V_22 = V_25 ;
} else {
V_17 = - V_28 ;
F_9 ( V_24 ) ;
}
V_26:
return V_17 ;
}
int F_10 ( struct V_14 * V_15 )
{
struct V_14 * V_25 = V_15 ;
int V_17 = - V_20 ;
if ( V_15 ) {
F_9 ( V_25 -> V_24 ) ;
F_11 ( V_25 ) ;
V_17 = 0 ;
}
return V_17 ;
}
int F_12 ( T_2 V_29 , enum V_30 V_31 ,
struct V_2 * V_3 )
{
int V_17 = 0 ;
char V_32 [ V_33 ] ;
char V_34 [ V_33 ] ;
struct V_2 V_35 ;
char V_36 [ V_37 ] ;
T_3 V_38 = 0 ;
struct V_39 * V_40 ;
int V_41 ;
if ( ( V_29 != 0 ) && ( V_42 == 0 ) ) {
V_17 = - V_43 ;
} else {
V_38 = strlen ( V_44 ) + 1 + sizeof( V_36 ) + 1 ;
strncpy ( V_32 , V_44 , strlen ( V_44 ) + 1 ) ;
if ( ( strlen ( V_32 ) + strlen ( L_2 ) ) <
V_33 ) {
strncat ( V_32 , L_2 , 2 ) ;
} else {
V_17 = - V_45 ;
}
V_17 = snprintf ( V_36 , V_37 , L_3 ,
V_31 ) ;
if ( V_17 == - 1 ) {
V_17 = - V_45 ;
} else {
V_17 = 0 ;
if ( ( strlen ( V_32 ) + strlen ( V_36 ) ) <
V_33 ) {
strncat ( V_32 , V_36 ,
strlen ( V_36 ) + 1 ) ;
} else {
V_17 = - V_45 ;
}
}
if ( ! V_17 ) {
V_41 = strlen ( V_32 ) ;
F_13 ( & V_46 ) ;
F_14 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_40 -> V_47 , V_32 , V_41 )
&& ! V_29 -- ) {
strncpy ( V_34 , & V_40 -> V_47 [ V_41 ] ,
strlen ( & V_40 -> V_47 [ V_41 ] ) + 1 ) ;
break;
}
}
F_15 ( & V_46 ) ;
if ( & V_40 -> V_48 == & V_49 )
V_17 = - V_50 ;
}
if ( ! V_17 ) {
V_17 = F_1 ( V_34 , & V_35 ) ;
if ( ! V_17 ) {
* V_3 = V_35 ;
V_42 ++ ;
}
} else if ( V_17 == - V_50 ) {
V_42 = 0 ;
V_17 = V_50 ;
} else {
V_17 = - V_45 ;
}
}
return V_17 ;
}
void F_16 ( void )
{
struct V_39 * V_51 , * V_52 ;
V_53 -- ;
if ( V_53 == 0 ) {
F_17 (rv, rv_tmp, &reg_key_list, link) {
F_18 ( & V_51 -> V_48 ) ;
F_11 ( V_51 -> V_54 ) ;
F_11 ( V_51 ) ;
}
}
}
int F_19 ( struct V_14 * V_15 ,
struct V_2 * V_3 ,
T_4 V_55 , struct V_2 * V_56 ,
bool * V_57 ,
enum V_58 V_59 )
{
int V_17 = 0 ;
V_17 =
F_20 ( V_15 , V_3 , & V_55 , NULL , V_56 ,
V_57 , V_59 ) ;
return V_17 ;
}
int F_21 ( struct V_14 * V_15 ,
struct V_2 * V_3 ,
T_4 * V_55 , T_4 * V_60 ,
enum V_58 V_59 )
{
int V_17 = 0 ;
V_17 = F_20 ( V_15 , V_3 , V_55 , V_60 ,
NULL , NULL , V_59 ) ;
return V_17 ;
}
int F_22 ( struct V_14 * V_15 ,
struct V_2 * V_61 ,
enum V_30 V_31 ,
struct V_62 * V_63 )
{
struct V_14 * V_25 = V_15 ;
struct V_64 * V_65 = NULL ;
int V_17 = 0 ;
int V_41 ;
T_3 V_66 = 0 ;
T_3 V_67 = 0 ;
T_3 V_68 ;
char V_32 [ V_33 ] ;
char * V_1 ;
char * V_69 ;
struct V_39 * V_40 = NULL ;
char V_70 [ V_71 + 2 ] ;
char * V_72 ;
T_3 V_38 ;
char V_36 [ V_37 ] ;
V_1 = F_8 ( V_71 , V_27 ) ;
if ( ! V_1 ) {
V_17 = - V_28 ;
goto V_26;
}
if ( ! V_15 ) {
V_17 = - V_20 ;
goto V_26;
}
V_38 = strlen ( V_44 ) + 1 + sizeof( V_36 ) + 1 ;
strncpy ( V_32 , V_44 , strlen ( V_44 ) + 1 ) ;
if ( ( strlen ( V_32 ) + strlen ( L_2 ) ) < V_33 )
strncat ( V_32 , L_2 , 2 ) ;
else
V_17 = - V_45 ;
V_17 = snprintf ( V_36 , V_37 , L_3 , V_31 ) ;
if ( V_17 == - 1 ) {
V_17 = - V_45 ;
} else {
V_17 = 0 ;
if ( ( strlen ( V_32 ) + strlen ( V_36 ) ) <
V_33 ) {
strncat ( V_32 , V_36 ,
strlen ( V_36 ) + 1 ) ;
} else {
V_17 = - V_45 ;
}
snprintf ( V_1 , V_71 , L_4 , V_61 ) ;
if ( ( strlen ( V_32 ) + V_71 ) < V_33 )
strncat ( V_32 , V_1 , V_71 ) ;
else
V_17 = - V_45 ;
V_68 = V_33 ;
}
if ( ! V_17 ) {
F_13 ( & V_46 ) ;
F_14 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_40 -> V_47 , V_32 ,
strlen ( V_32 ) + 1 ) )
break;
}
F_15 ( & V_46 ) ;
if ( & V_40 -> V_48 == & V_49 ) {
V_17 = - V_73 ;
goto V_26;
}
}
V_17 = F_23 ( V_25 -> V_24 , V_40 -> V_54 ,
V_74 , & V_65 ) ;
if ( V_17 ) {
V_17 = - V_75 ;
goto V_26;
}
V_41 = strlen ( V_1 ) ;
if ( V_41 + 1 > sizeof( V_70 ) ) {
V_17 = - V_45 ;
goto V_26;
}
V_41 -= 4 ;
V_69 = V_1 ;
strncpy ( V_70 , L_5 , 2 ) ;
do {
char * V_76 = F_24 ( & V_69 , L_6 ) ;
if ( ! V_76 )
break;
V_41 -= strlen ( V_76 ) ;
strncat ( V_70 , V_76 , strlen ( V_76 ) + 1 ) ;
} while ( V_41 && strncat ( V_70 , L_7 , 2 ) );
V_17 = F_25 ( V_65 , V_70 , & V_66 , & V_67 ) ;
if ( V_17 ) {
V_17 = - V_75 ;
goto V_26;
}
V_72 = F_8 ( V_67 + 4 , V_27 ) ;
if ( V_72 == NULL ) {
V_17 = - V_28 ;
goto V_26;
}
#ifdef F_26
if ( strstr ( V_40 -> V_54 , L_8 ) == NULL ) {
V_17 =
F_27 ( V_65 , V_70 , V_72 , V_67 ) ;
} else {
V_17 =
F_27 ( V_65 , V_70 , V_72 , V_67 ) ;
F_28 ( V_77 , L_9 , V_78 ) ;
}
#else
V_17 = F_27 ( V_65 , V_70 , V_72 , V_67 ) ;
#endif
if ( ! V_17 ) {
if ( strstr ( V_40 -> V_54 , L_8 ) == NULL ) {
F_29 ( V_72 , V_67 , V_79 ) ;
} else {
F_29 ( V_72 , V_67 , 1 ) ;
F_28 ( V_77 , L_10
L_11 , V_78 ) ;
}
V_17 =
F_30 ( V_72 , V_67 , V_31 , V_63 ) ;
if ( V_17 )
V_17 = - V_75 ;
} else {
V_17 = - V_75 ;
}
F_11 ( V_72 ) ;
V_26:
if ( V_65 )
F_31 ( V_65 ) ;
F_11 ( V_1 ) ;
return V_17 ;
}
int F_4 ( struct V_14 * V_15 ,
char * V_16 , V_18 V_80 ,
void * V_81 )
{
struct V_14 * V_25 = V_15 ;
int V_17 = 0 ;
char * V_72 ;
char * V_82 ;
struct V_64 * V_65 = NULL ;
T_3 V_66 = 0 ;
T_3 V_67 = 0 ;
char V_83 [] = L_12 ;
char * V_84 = NULL ;
struct V_2 V_35 ;
T_2 V_85 ;
if ( ! V_15 ) {
V_17 = - V_20 ;
goto V_26;
}
V_17 = F_23 ( V_25 -> V_24 , V_16 , V_74 , & V_65 ) ;
if ( V_17 ) {
V_17 = - V_75 ;
goto V_86;
}
V_17 = F_25 ( V_65 , V_87 , & V_66 , & V_67 ) ;
if ( V_17 || ! ( V_67 > 0 ) ) {
V_17 = - V_75 ;
goto V_86;
}
V_72 = F_8 ( V_67 + 4 , V_27 ) ;
if ( V_72 == NULL ) {
V_17 = - V_28 ;
goto V_86;
}
#ifdef F_26
if ( strstr ( V_16 , L_8 ) == NULL ) {
V_17 = F_27 ( V_65 , V_87 ,
V_72 , V_67 ) ;
} else {
F_28 ( V_77 , L_9 , V_78 ) ;
V_17 = F_27 ( V_65 , V_87 ,
V_72 , V_67 ) ;
}
#else
V_17 =
F_27 ( V_65 , V_87 , V_72 , V_67 ) ;
#endif
if ( ! V_17 ) {
if ( strstr ( V_16 , L_8 ) == NULL ) {
F_29 ( V_72 , V_67 , V_79 ) ;
} else {
F_29 ( V_72 , V_67 , 1 ) ;
F_28 ( V_77 , L_13
L_11 , V_78 ) ;
}
V_82 = V_72 ;
while ( ( V_84 = F_24 ( & V_82 , V_83 ) ) && * V_84 != '\0' ) {
V_17 = F_1 ( V_84 , & V_35 ) ;
if ( ! V_17 ) {
V_84 = F_24 ( & V_82 , V_83 ) ;
V_85 = atoi ( V_84 ) ;
V_17 =
V_80 ( & V_35 , V_85 ,
V_81 ) ;
}
if ( V_17 ) {
break;
}
}
} else {
V_17 = - V_75 ;
}
F_11 ( V_72 ) ;
V_86:
if ( V_65 )
F_31 ( V_65 ) ;
V_26:
return V_17 ;
}
int F_32 ( struct V_14 * V_15 ,
struct V_2 * V_3 ,
char * V_88 ,
T_3 * V_89 ,
enum V_58 V_59 , bool * V_90 )
{
char V_32 [ V_33 ] ;
char V_1 [ V_71 ] ;
T_3 V_38 ;
char V_36 [ V_37 ] ;
int V_17 = 0 ;
struct V_39 * V_40 = NULL ;
F_28 ( V_77 , L_14
L_15 , V_78 , V_15 , V_3 , V_88 ,
V_89 ) ;
V_38 = strlen ( V_44 ) + 1 + sizeof( V_36 ) + 1 ;
strncpy ( V_32 , V_44 , strlen ( V_44 ) + 1 ) ;
if ( ( strlen ( V_32 ) + strlen ( L_2 ) ) < V_33 )
strncat ( V_32 , L_2 , 2 ) ;
else
V_17 = - V_45 ;
switch ( V_59 ) {
case V_91 :
sprintf ( V_36 , L_3 , V_92 ) ;
break;
case V_93 :
sprintf ( V_36 , L_3 , V_94 ) ;
break;
case V_95 :
sprintf ( V_36 , L_3 , V_96 ) ;
break;
case V_97 :
sprintf ( V_36 , L_3 , V_98 ) ;
break;
default:
V_17 = - V_12 ;
}
if ( ! V_17 ) {
if ( ( strlen ( V_32 ) + strlen ( V_36 ) ) <
V_33 ) {
strncat ( V_32 , V_36 ,
strlen ( V_36 ) + 1 ) ;
} else {
V_17 = - V_45 ;
}
snprintf ( V_1 , V_71 , L_4 , V_3 ) ;
if ( ( strlen ( V_32 ) + V_71 ) < V_33 )
strncat ( V_32 , V_1 , V_71 ) ;
else
V_17 = - V_45 ;
}
if ( ! V_17 ) {
F_13 ( & V_46 ) ;
F_14 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_40 -> V_47 , V_32 ,
strlen ( V_32 ) + 1 ) )
break;
}
F_15 ( & V_46 ) ;
}
if ( & V_40 -> V_48 == & V_49 )
V_17 = - V_73 ;
if ( V_17 && V_59 != V_97 ) {
if ( V_90 )
* V_90 = false ;
strncpy ( V_32 , V_44 , strlen ( V_44 ) + 1 ) ;
if ( ( strlen ( V_32 ) + strlen ( L_2 ) ) <
V_33 ) {
strncat ( V_32 , L_2 , 2 ) ;
} else {
V_17 = - V_45 ;
}
sprintf ( V_36 , L_3 , V_98 ) ;
if ( ( strlen ( V_32 ) + strlen ( V_36 ) )
< V_33 ) {
strncat ( V_32 , V_36 ,
strlen ( V_36 ) + 1 ) ;
} else {
V_17 = - V_45 ;
}
snprintf ( V_1 , V_71 , L_4 , V_3 ) ;
if ( ( strlen ( V_32 ) + V_71 ) < V_33 )
strncat ( V_32 , V_1 , V_71 ) ;
else
V_17 = - V_45 ;
F_13 ( & V_46 ) ;
F_14 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_40 -> V_47 , V_32 ,
strlen ( V_32 ) + 1 ) )
break;
}
F_15 ( & V_46 ) ;
V_17 = ( & V_40 -> V_48 != & V_49 ) ?
0 : - V_73 ;
}
if ( ! V_17 )
memcpy ( V_88 , V_40 -> V_54 , strlen ( V_40 -> V_54 ) + 1 ) ;
return V_17 ;
}
bool F_33 ( void )
{
bool V_99 = true ;
if ( V_53 == 0 )
F_34 ( & V_49 ) ;
if ( V_99 )
V_53 ++ ;
return V_99 ;
}
int V_19 ( struct V_2 * V_3 ,
enum V_30 V_31 ,
char * V_100 )
{
int V_17 = 0 ;
char V_32 [ V_33 ] ;
char V_1 [ V_71 + 1 ] ;
T_3 V_101 = 0 ;
T_3 V_38 ;
char V_36 [ V_37 ] ;
struct V_39 * V_40 = NULL ;
F_28 ( V_77 , L_16 ,
V_78 , V_3 , V_31 , V_100 ) ;
V_38 = strlen ( V_44 ) + 1 + sizeof( V_36 ) + 1 ;
strncpy ( V_32 , V_44 , strlen ( V_44 ) + 1 ) ;
if ( ( strlen ( V_32 ) + strlen ( L_2 ) ) < V_33 )
strncat ( V_32 , L_2 , 2 ) ;
else {
V_17 = - V_45 ;
goto V_26;
}
V_17 = snprintf ( V_36 , V_37 , L_3 , V_31 ) ;
if ( V_17 == - 1 ) {
V_17 = - V_45 ;
} else {
V_17 = 0 ;
if ( ( strlen ( V_32 ) + strlen ( V_36 ) ) <
V_33 ) {
strncat ( V_32 , V_36 ,
strlen ( V_36 ) + 1 ) ;
} else
V_17 = - V_45 ;
snprintf ( V_1 , V_71 , L_4 , V_3 ) ;
if ( ( strlen ( V_32 ) + V_71 ) < V_33 )
strncat ( V_32 , V_1 , V_71 ) ;
else
V_17 = - V_45 ;
}
if ( V_17 )
goto V_26;
if ( V_100 ) {
V_101 = strlen ( V_100 ) + 1 ;
F_13 ( & V_46 ) ;
F_14 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_40 -> V_47 , V_32 ,
strlen ( V_32 ) + 1 ) )
break;
}
F_15 ( & V_46 ) ;
if ( & V_40 -> V_48 == & V_49 ) {
V_40 = F_35 ( sizeof( struct V_39 ) ,
V_27 ) ;
if ( ! V_40 ) {
V_17 = - V_28 ;
goto V_26;
}
V_40 -> V_54 = F_35 ( V_101 , V_27 ) ;
if ( ! V_40 -> V_54 ) {
F_11 ( V_40 ) ;
V_17 = - V_28 ;
goto V_26;
}
strncpy ( V_40 -> V_47 , V_32 ,
strlen ( V_32 ) + 1 ) ;
strncpy ( V_40 -> V_54 , V_100 ,
V_101 ) ;
F_13 ( & V_46 ) ;
F_36 ( & V_40 -> V_48 , & V_49 ) ;
F_15 ( & V_46 ) ;
} else {
if ( strncmp ( V_40 -> V_54 , V_100 ,
V_101 ) ) {
F_11 ( V_40 -> V_54 ) ;
V_40 -> V_54 = F_35 ( V_101 ,
V_27 ) ;
if ( V_40 -> V_54 == NULL ) {
V_17 = - V_28 ;
goto V_26;
}
}
memcpy ( V_40 -> V_54 , V_100 , V_101 ) ;
}
F_28 ( V_77 , L_17 ,
V_78 , V_100 , V_101 ) ;
} else {
F_13 ( & V_46 ) ;
F_14 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_40 -> V_47 , V_32 ,
strlen ( V_32 ) + 1 ) ) {
F_18 ( & V_40 -> V_48 ) ;
F_11 ( V_40 -> V_54 ) ;
F_11 ( V_40 ) ;
break;
}
}
F_15 ( & V_46 ) ;
if ( & V_40 -> V_48 == & V_49 )
V_17 = - V_45 ;
}
if ( ! V_17 ) {
V_42 = 0 ;
}
V_26:
return V_17 ;
}
int F_37 ( struct V_2 * V_3 ,
enum V_30 V_31 )
{
int V_17 = 0 ;
V_17 = V_19 ( V_3 , V_31 , NULL ) ;
return V_17 ;
}
static T_2 atoi ( char * V_102 )
{
char * V_103 = V_102 ;
T_2 V_104 = 0 ;
while ( isspace ( * V_103 ) )
V_103 ++ ;
if ( * V_103 == '-' || * V_103 == '+' ) {
V_104 = 10 ;
V_103 ++ ;
} else if ( * V_103 && tolower ( V_103 [ strlen ( V_103 ) - 1 ] ) == 'h' ) {
V_104 = 16 ;
}
return F_38 ( V_103 , NULL , V_104 ) ;
}
static int F_30 ( char * V_102 , T_3 V_105 ,
enum V_30 V_31 ,
struct V_62 * V_106 )
{
int V_17 = 0 ;
char V_83 [] = L_18 ;
char * V_82 ;
char * V_84 ;
T_2 V_107 = 0 ;
T_3 V_108 = 0 ;
#ifdef F_26
T_2 V_109 ;
#endif
switch ( V_31 ) {
case V_110 :
V_82 = V_102 ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 . V_114 =
( T_3 ) atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_17 = F_1 ( V_84 ,
& V_106 -> V_111 . V_112 .
V_113 . V_115 ) ;
if ( V_17 )
break;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_107 = strlen ( V_84 ) ;
if ( V_107 > V_116 - 1 )
V_107 = V_116 - 1 ;
strncpy ( V_106 -> V_111 . V_112 . V_113 . V_117 ,
V_84 , V_107 ) ;
V_106 -> V_111 . V_112 . V_113 . V_117 [ V_107 ] = '\0' ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 . V_118 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 . V_119 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 . V_120 .
V_114 = ( T_3 ) atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 .
V_120 . V_121 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 .
V_120 . V_122 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 .
V_120 . V_123 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 .
V_120 . V_124 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 .
V_120 . V_125 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 .
V_120 . V_126 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 .
V_120 . V_127 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 .
V_120 . V_128 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 . V_129 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 . V_130 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 . V_131 =
atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 . V_132 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 . V_133 =
atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 . V_134 =
atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 . V_135 =
atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_113 . V_136 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_107 = strlen ( V_84 ) ;
V_106 -> V_111 . V_112 . V_137 =
F_8 ( V_107 + 1 , V_27 ) ;
strncpy ( V_106 -> V_111 . V_112 . V_137 ,
V_84 , V_107 ) ;
V_106 -> V_111 . V_112 . V_137 [ V_107 ] =
'\0' ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_107 = strlen ( V_84 ) ;
V_106 -> V_111 . V_112 . V_138 =
F_8 ( V_107 + 1 , V_27 ) ;
strncpy ( V_106 -> V_111 . V_112 . V_138 ,
V_84 , V_107 ) ;
V_106 -> V_111 . V_112 . V_138 [ V_107 ] =
'\0' ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_107 = strlen ( V_84 ) ;
V_106 -> V_111 . V_112 . V_139 =
F_8 ( V_107 + 1 , V_27 ) ;
strncpy ( V_106 -> V_111 . V_112 . V_139 ,
V_84 , V_107 ) ;
V_106 -> V_111 . V_112 . V_139 [ V_107 ] =
'\0' ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_140 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_112 . V_141 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
if ( V_84 ) {
V_107 = strlen ( V_84 ) ;
V_106 -> V_111 . V_112 . V_142 =
F_8 ( V_107 + 1 , V_27 ) ;
strncpy ( V_106 -> V_111 . V_112 . V_142 ,
V_84 , V_107 ) ;
V_106 -> V_111 . V_112 . V_142 [ V_107 ] =
'\0' ;
V_84 = F_24 ( & V_82 , V_83 ) ;
}
if ( V_84 ) {
V_106 -> V_111 . V_112 . V_143 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
}
if ( V_84 ) {
V_106 -> V_111 . V_112 . V_144 =
atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
}
if ( V_84 ) {
V_106 -> V_111 . V_112 . V_145 =
atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
}
if ( V_84 ) {
V_106 -> V_111 . V_112 . V_113 . V_146 =
atoi ( V_84 ) ;
for ( V_108 = 0 ;
V_108 <
V_106 -> V_111 . V_112 .
V_113 . V_146 ; V_108 ++ ) {
V_84 = F_24 ( & V_82 , V_83 ) ;
if ( V_84 ) {
V_106 -> V_111 . V_112 .
V_113 . V_147 [ V_108 ] .
V_148 = atoi ( V_84 ) ;
}
}
}
V_84 = F_24 ( & V_82 , V_83 ) ;
if ( V_84 ) {
V_106 -> V_111 . V_112 . V_113 . V_149 =
( T_3 ) ( V_84 ) ;
}
break;
case V_150 :
V_82 = V_102 ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_151 . V_114 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_151 . V_152 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_151 . V_153 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_151 . V_154 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_151 . V_155 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_151 . V_156 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_151 . V_157 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_151 . V_158 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_151 . V_159 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_151 . V_160 = atoi ( V_84 ) ;
#ifdef F_26
for ( V_109 = 0 ; V_109 < 7 ; V_109 ++ ) {
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_161 . V_162 [ V_109 ] .
V_163 = atoi ( V_84 ) ;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_106 -> V_111 . V_161 . V_162 [ V_109 ] .
V_164 = atoi ( V_84 ) ;
}
#endif
break;
default:
V_17 = - V_45 ;
break;
}
return V_17 ;
}
static void F_29 ( char * V_102 , T_3 V_105 , T_2 V_165 )
{
char * V_166 ;
char V_167 ;
char * V_168 ;
V_166 = V_102 ;
if ( V_166 == NULL )
return;
for ( V_168 = V_102 ; V_168 < ( V_102 + V_105 ) ; ) {
V_167 = F_39 ( V_168 , V_165 ) ;
if ( V_167 == '\\' ) {
V_168 += V_165 ;
V_167 = F_39 ( V_168 , V_165 ) ;
switch ( V_167 ) {
case 't' :
* V_166 = '\t' ;
break;
case 'n' :
* V_166 = '\n' ;
break;
case 'r' :
* V_166 = '\r' ;
break;
case '0' :
* V_166 = '\0' ;
break;
default:
* V_166 = V_167 ;
break;
}
} else {
* V_166 = V_167 ;
}
V_166 ++ ;
V_168 += V_165 ;
}
while ( V_166 < V_168 )
* V_166 ++ = '\0' ;
}
static char F_39 ( char * V_169 , T_2 V_170 )
{
char V_167 = '\0' ;
char * V_171 ;
T_2 V_108 ;
for ( V_171 = V_169 , V_108 = V_170 ; V_108 > 0 ; V_108 -- )
V_167 |= * V_171 ++ ;
return V_167 ;
}
static int F_20 ( struct V_14 * V_15 ,
struct V_2 * V_3 ,
T_4 * V_55 ,
T_4 * V_60 ,
struct V_2 * V_56 ,
bool * V_57 ,
enum V_58 V_59 )
{
struct V_14 * V_25 = V_15 ;
char * V_72 = NULL ;
char * V_82 ;
char * V_172 = NULL ;
struct V_64 * V_65 = NULL ;
T_3 V_66 = 0 ;
T_3 V_67 = 0 ;
T_3 V_173 = V_174 ;
char V_83 [] = L_18 ;
char * V_84 = NULL ;
bool V_175 = ( V_56 != NULL ) ;
T_4 V_176 = 0 ;
int V_17 = 0 ;
if ( ! V_175 ) {
* V_55 = 0 ;
* V_60 = 0 ;
}
V_172 = F_8 ( V_173 , V_27 ) ;
if ( V_172 == NULL ) {
V_17 = - V_28 ;
} else {
V_17 = F_32 ( V_15 , V_3 , V_172 ,
& V_173 , V_59 , NULL ) ;
}
if ( ! V_17 ) {
V_17 = F_23 ( V_25 -> V_24 , V_172 ,
V_74 , & V_65 ) ;
}
if ( ! V_17 ) {
V_17 = F_25 ( V_65 , V_177 , & V_66 , & V_67 ) ;
if ( V_17 ) {
V_67 = 0 ;
V_17 = 0 ;
}
}
if ( V_17 || ! ( V_67 > 0 ) )
goto V_86;
V_72 = F_8 ( V_67 + 4 , V_27 ) ;
if ( V_72 == NULL )
V_17 = - V_28 ;
V_17 = F_27 ( V_65 , V_177 , V_72 , V_67 ) ;
if ( V_17 )
goto V_86;
F_29 ( V_72 , V_67 , V_79 ) ;
V_82 = V_72 ;
while ( ( V_84 = F_24 ( & V_82 , V_83 ) ) && * V_84 != '\0' ) {
if ( V_175 ) {
if ( V_176 >= * V_55 ) {
break;
} else {
V_17 = F_1 ( V_84 ,
& ( V_56
[ V_176 ] ) ) ;
if ( V_17 )
break;
V_84 = F_24 ( & V_82 , V_83 ) ;
V_57 [ V_176 ] = atoi ( V_84 ) ;
V_176 ++ ;
}
} else {
V_84 = F_24 ( & V_82 , V_83 ) ;
if ( atoi ( V_84 ) )
( * V_60 ) ++ ;
( * V_55 ) ++ ;
}
}
V_86:
if ( V_65 )
F_31 ( V_65 ) ;
F_11 ( V_172 ) ;
F_11 ( V_72 ) ;
return V_17 ;
}
