int F_1 ( struct V_1 * V_2 ,
char * V_3 )
{
int V_4 = 0 ;
if ( V_2 )
V_4 = F_2 ( V_2 , V_3 ,
( V_5 ) V_6 ,
( void * ) V_3 ) ;
else
V_4 = - V_7 ;
return V_4 ;
}
int F_3 ( struct V_1 * V_2 ,
char * V_3 )
{
int V_4 = 0 ;
if ( V_2 )
V_4 = F_2 ( V_2 , V_3 ,
( V_5 ) V_6 ,
NULL ) ;
else
V_4 = - V_7 ;
return V_4 ;
}
int F_4 ( char * V_8 ,
struct V_1 * * V_9 )
{
struct V_10 * V_11 ;
struct V_1 * V_12 = NULL ;
int V_4 = 0 ;
V_4 = F_5 ( & V_11 , V_8 ) ;
if ( V_4 )
goto V_13;
V_12 = F_6 ( sizeof( struct V_1 ) , V_14 ) ;
if ( V_12 != NULL ) {
V_12 -> V_11 = V_11 ;
* V_9 = V_12 ;
} else {
V_4 = - V_15 ;
F_7 ( V_11 ) ;
}
V_13:
return V_4 ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_1 * V_12 = V_2 ;
int V_4 = - V_7 ;
if ( V_2 ) {
F_7 ( V_12 -> V_11 ) ;
F_9 ( V_12 ) ;
V_4 = 0 ;
}
return V_4 ;
}
int F_10 ( T_1 V_16 , enum V_17 V_18 ,
struct V_19 * V_20 )
{
int V_4 = 0 ;
char V_21 [ V_22 ] ;
char V_23 [ V_22 ] ;
struct V_19 V_24 ;
char V_25 [ V_26 ] ;
T_2 V_27 = 0 ;
struct V_28 * V_29 ;
int V_30 ;
if ( ( V_16 != 0 ) && ( V_31 == 0 ) ) {
V_4 = - V_32 ;
} else {
V_27 = strlen ( V_33 ) + 1 + sizeof( V_25 ) + 1 ;
strncpy ( V_21 , V_33 , strlen ( V_33 ) + 1 ) ;
if ( ( strlen ( V_21 ) + strlen ( L_1 ) ) <
V_22 ) {
strncat ( V_21 , L_1 , 2 ) ;
} else {
V_4 = - V_34 ;
}
V_4 = snprintf ( V_25 , V_26 , L_2 ,
V_18 ) ;
if ( V_4 == - 1 ) {
V_4 = - V_34 ;
} else {
V_4 = 0 ;
if ( ( strlen ( V_21 ) + strlen ( V_25 ) ) <
V_22 ) {
strncat ( V_21 , V_25 ,
strlen ( V_25 ) + 1 ) ;
} else {
V_4 = - V_34 ;
}
}
if ( ! V_4 ) {
V_30 = strlen ( V_21 ) ;
F_11 ( & V_35 ) ;
F_12 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_29 -> V_36 , V_21 , V_30 )
&& ! V_16 -- ) {
strncpy ( V_23 , & V_29 -> V_36 [ V_30 ] ,
strlen ( & V_29 -> V_36 [ V_30 ] ) + 1 ) ;
break;
}
}
F_13 ( & V_35 ) ;
if ( & V_29 -> V_37 == & V_38 )
V_4 = - V_39 ;
}
if ( ! V_4 ) {
F_14 ( V_23 , & V_24 ) ;
* V_20 = V_24 ;
V_31 ++ ;
V_4 = 0 ;
} else if ( V_4 == - V_39 ) {
V_31 = 0 ;
V_4 = V_39 ;
} else {
V_4 = - V_34 ;
}
}
return V_4 ;
}
void F_15 ( void )
{
struct V_28 * V_40 , * V_41 ;
V_42 -- ;
if ( V_42 == 0 ) {
F_16 (rv, rv_tmp, &reg_key_list, link) {
F_17 ( & V_40 -> V_37 ) ;
F_9 ( V_40 -> V_43 ) ;
F_9 ( V_40 ) ;
}
}
}
int F_18 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
T_3 V_44 , struct V_19 * V_45 ,
bool * V_46 ,
enum V_47 V_48 )
{
int V_4 = 0 ;
V_4 =
F_19 ( V_2 , V_20 , & V_44 , NULL , V_45 ,
V_46 , V_48 ) ;
return V_4 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
T_3 * V_44 , T_3 * V_49 ,
enum V_47 V_48 )
{
int V_4 = 0 ;
V_4 = F_19 ( V_2 , V_20 , V_44 , V_49 ,
NULL , NULL , V_48 ) ;
return V_4 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_19 * V_50 ,
enum V_17 V_18 ,
struct V_51 * V_52 )
{
struct V_1 * V_12 = V_2 ;
struct V_53 * V_54 = NULL ;
int V_4 = 0 ;
int V_30 ;
T_2 V_55 = 0 ;
T_2 V_56 = 0 ;
T_2 V_57 ;
char V_21 [ V_22 ] ;
char * V_58 ;
char * V_59 ;
struct V_28 * V_29 = NULL ;
char V_60 [ V_61 + 2 ] ;
char * V_62 ;
T_2 V_27 ;
char V_25 [ V_26 ] ;
V_58 = F_6 ( V_61 , V_14 ) ;
if ( ! V_58 ) {
V_4 = - V_15 ;
goto V_13;
}
if ( ! V_2 ) {
V_4 = - V_7 ;
goto V_13;
}
V_27 = strlen ( V_33 ) + 1 + sizeof( V_25 ) + 1 ;
strncpy ( V_21 , V_33 , strlen ( V_33 ) + 1 ) ;
if ( ( strlen ( V_21 ) + strlen ( L_1 ) ) < V_22 )
strncat ( V_21 , L_1 , 2 ) ;
else
V_4 = - V_34 ;
V_4 = snprintf ( V_25 , V_26 , L_2 , V_18 ) ;
if ( V_4 == - 1 ) {
V_4 = - V_34 ;
} else {
V_4 = 0 ;
if ( ( strlen ( V_21 ) + strlen ( V_25 ) ) <
V_22 ) {
strncat ( V_21 , V_25 ,
strlen ( V_25 ) + 1 ) ;
} else {
V_4 = - V_34 ;
}
snprintf ( V_58 , V_61 , L_3 , V_50 ) ;
if ( ( strlen ( V_21 ) + V_61 ) < V_22 )
strncat ( V_21 , V_58 , V_61 ) ;
else
V_4 = - V_34 ;
V_57 = V_22 ;
}
if ( ! V_4 ) {
F_11 ( & V_35 ) ;
F_12 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_29 -> V_36 , V_21 ,
strlen ( V_21 ) + 1 ) )
break;
}
F_13 ( & V_35 ) ;
if ( & V_29 -> V_37 == & V_38 ) {
V_4 = - V_63 ;
goto V_13;
}
}
V_4 = F_22 ( V_12 -> V_11 , V_29 -> V_43 ,
V_64 , & V_54 ) ;
if ( V_4 ) {
V_4 = - V_65 ;
goto V_13;
}
V_30 = strlen ( V_58 ) ;
if ( V_30 + 1 > sizeof( V_60 ) ) {
V_4 = - V_34 ;
goto V_13;
}
V_30 -= 4 ;
V_59 = V_58 ;
strncpy ( V_60 , L_4 , 2 ) ;
do {
char * V_66 = F_23 ( & V_59 , L_5 ) ;
if ( ! V_66 )
break;
V_30 -= strlen ( V_66 ) ;
strncat ( V_60 , V_66 , strlen ( V_66 ) + 1 ) ;
} while ( V_30 && strncat ( V_60 , L_6 , 2 ) );
V_4 = F_24 ( V_54 , V_60 , & V_55 , & V_56 ) ;
if ( V_4 ) {
V_4 = - V_65 ;
goto V_13;
}
V_62 = F_6 ( V_56 + 4 , V_14 ) ;
if ( V_62 == NULL ) {
V_4 = - V_15 ;
goto V_13;
}
#ifdef F_25
if ( strstr ( V_29 -> V_43 , L_7 ) == NULL ) {
V_4 =
F_26 ( V_54 , V_60 , V_62 , V_56 ) ;
} else {
V_4 =
F_26 ( V_54 , V_60 , V_62 , V_56 ) ;
F_27 ( V_67 , L_8 , V_68 ) ;
}
#else
V_4 = F_26 ( V_54 , V_60 , V_62 , V_56 ) ;
#endif
if ( ! V_4 ) {
if ( strstr ( V_29 -> V_43 , L_7 ) == NULL ) {
F_28 ( V_62 , V_56 , V_69 ) ;
} else {
F_28 ( V_62 , V_56 , 1 ) ;
F_27 ( V_67 , L_9
L_10 , V_68 ) ;
}
V_4 =
F_29 ( V_62 , V_56 , V_18 , V_52 ) ;
if ( V_4 )
V_4 = - V_65 ;
} else {
V_4 = - V_65 ;
}
F_9 ( V_62 ) ;
V_13:
if ( V_54 )
F_30 ( V_54 ) ;
F_9 ( V_58 ) ;
return V_4 ;
}
int F_2 ( struct V_1 * V_2 ,
char * V_3 , V_5 V_70 ,
void * V_71 )
{
struct V_1 * V_12 = V_2 ;
int V_4 = 0 ;
char * V_62 ;
char * V_72 ;
struct V_53 * V_54 = NULL ;
T_2 V_55 = 0 ;
T_2 V_56 = 0 ;
char V_73 [] = L_11 ;
char * V_74 = NULL ;
struct V_19 V_24 ;
T_1 V_75 ;
if ( ! V_2 ) {
V_4 = - V_7 ;
goto V_13;
}
V_4 = F_22 ( V_12 -> V_11 , V_3 , V_64 , & V_54 ) ;
if ( V_4 ) {
V_4 = - V_65 ;
goto V_76;
}
V_4 = F_24 ( V_54 , V_77 , & V_55 , & V_56 ) ;
if ( V_4 || ! ( V_56 > 0 ) ) {
V_4 = - V_65 ;
goto V_76;
}
V_62 = F_6 ( V_56 + 4 , V_14 ) ;
if ( V_62 == NULL ) {
V_4 = - V_15 ;
goto V_76;
}
#ifdef F_25
if ( strstr ( V_3 , L_7 ) == NULL ) {
V_4 = F_26 ( V_54 , V_77 ,
V_62 , V_56 ) ;
} else {
F_27 ( V_67 , L_8 , V_68 ) ;
V_4 = F_26 ( V_54 , V_77 ,
V_62 , V_56 ) ;
}
#else
V_4 =
F_26 ( V_54 , V_77 , V_62 , V_56 ) ;
#endif
if ( ! V_4 ) {
if ( strstr ( V_3 , L_7 ) == NULL ) {
F_28 ( V_62 , V_56 , V_69 ) ;
} else {
F_28 ( V_62 , V_56 , 1 ) ;
F_27 ( V_67 , L_12
L_10 , V_68 ) ;
}
V_72 = V_62 ;
while ( ( V_74 = F_23 ( & V_72 , V_73 ) ) && * V_74 != '\0' ) {
F_14 ( V_74 , & V_24 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_75 = atoi ( V_74 ) ;
V_4 =
V_70 ( & V_24 , V_75 , V_71 ) ;
if ( V_4 ) {
break;
}
}
} else {
V_4 = - V_65 ;
}
F_9 ( V_62 ) ;
V_76:
if ( V_54 )
F_30 ( V_54 ) ;
V_13:
return V_4 ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
char * V_78 ,
T_2 * V_79 ,
enum V_47 V_48 , bool * V_80 )
{
char V_21 [ V_22 ] ;
char V_58 [ V_61 ] ;
T_2 V_27 ;
char V_25 [ V_26 ] ;
int V_4 = 0 ;
struct V_28 * V_29 = NULL ;
F_27 ( V_67 , L_13
L_14 , V_68 , V_2 , V_20 , V_78 ,
V_79 ) ;
V_27 = strlen ( V_33 ) + 1 + sizeof( V_25 ) + 1 ;
strncpy ( V_21 , V_33 , strlen ( V_33 ) + 1 ) ;
if ( ( strlen ( V_21 ) + strlen ( L_1 ) ) < V_22 )
strncat ( V_21 , L_1 , 2 ) ;
else
V_4 = - V_34 ;
switch ( V_48 ) {
case V_81 :
sprintf ( V_25 , L_2 , V_82 ) ;
break;
case V_83 :
sprintf ( V_25 , L_2 , V_84 ) ;
break;
case V_85 :
sprintf ( V_25 , L_2 , V_86 ) ;
break;
case V_87 :
sprintf ( V_25 , L_2 , V_88 ) ;
break;
default:
V_4 = - V_89 ;
}
if ( ! V_4 ) {
if ( ( strlen ( V_21 ) + strlen ( V_25 ) ) <
V_22 ) {
strncat ( V_21 , V_25 ,
strlen ( V_25 ) + 1 ) ;
} else {
V_4 = - V_34 ;
}
snprintf ( V_58 , V_61 , L_3 , V_20 ) ;
if ( ( strlen ( V_21 ) + V_61 ) < V_22 )
strncat ( V_21 , V_58 , V_61 ) ;
else
V_4 = - V_34 ;
}
if ( ! V_4 ) {
F_11 ( & V_35 ) ;
F_12 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_29 -> V_36 , V_21 ,
strlen ( V_21 ) + 1 ) )
break;
}
F_13 ( & V_35 ) ;
}
if ( & V_29 -> V_37 == & V_38 )
V_4 = - V_63 ;
if ( V_4 && V_48 != V_87 ) {
if ( V_80 )
* V_80 = false ;
strncpy ( V_21 , V_33 , strlen ( V_33 ) + 1 ) ;
if ( ( strlen ( V_21 ) + strlen ( L_1 ) ) <
V_22 ) {
strncat ( V_21 , L_1 , 2 ) ;
} else {
V_4 = - V_34 ;
}
sprintf ( V_25 , L_2 , V_88 ) ;
if ( ( strlen ( V_21 ) + strlen ( V_25 ) )
< V_22 ) {
strncat ( V_21 , V_25 ,
strlen ( V_25 ) + 1 ) ;
} else {
V_4 = - V_34 ;
}
snprintf ( V_58 , V_61 , L_3 , V_20 ) ;
if ( ( strlen ( V_21 ) + V_61 ) < V_22 )
strncat ( V_21 , V_58 , V_61 ) ;
else
V_4 = - V_34 ;
F_11 ( & V_35 ) ;
F_12 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_29 -> V_36 , V_21 ,
strlen ( V_21 ) + 1 ) )
break;
}
F_13 ( & V_35 ) ;
V_4 = ( & V_29 -> V_37 != & V_38 ) ?
0 : - V_63 ;
}
if ( ! V_4 )
memcpy ( V_78 , V_29 -> V_43 , strlen ( V_29 -> V_43 ) + 1 ) ;
return V_4 ;
}
bool F_32 ( void )
{
bool V_90 = true ;
if ( V_42 == 0 )
F_33 ( & V_38 ) ;
if ( V_90 )
V_42 ++ ;
return V_90 ;
}
int V_6 ( struct V_19 * V_20 ,
enum V_17 V_18 ,
char * V_91 )
{
int V_4 = 0 ;
char V_21 [ V_22 ] ;
char V_58 [ V_61 + 1 ] ;
T_2 V_92 = 0 ;
T_2 V_27 ;
char V_25 [ V_26 ] ;
struct V_28 * V_29 = NULL ;
F_27 ( V_67 , L_15 ,
V_68 , V_20 , V_18 , V_91 ) ;
V_27 = strlen ( V_33 ) + 1 + sizeof( V_25 ) + 1 ;
strncpy ( V_21 , V_33 , strlen ( V_33 ) + 1 ) ;
if ( ( strlen ( V_21 ) + strlen ( L_1 ) ) < V_22 )
strncat ( V_21 , L_1 , 2 ) ;
else {
V_4 = - V_34 ;
goto V_13;
}
V_4 = snprintf ( V_25 , V_26 , L_2 , V_18 ) ;
if ( V_4 == - 1 ) {
V_4 = - V_34 ;
} else {
V_4 = 0 ;
if ( ( strlen ( V_21 ) + strlen ( V_25 ) ) <
V_22 ) {
strncat ( V_21 , V_25 ,
strlen ( V_25 ) + 1 ) ;
} else
V_4 = - V_34 ;
snprintf ( V_58 , V_61 , L_3 , V_20 ) ;
if ( ( strlen ( V_21 ) + V_61 ) < V_22 )
strncat ( V_21 , V_58 , V_61 ) ;
else
V_4 = - V_34 ;
}
if ( V_4 )
goto V_13;
if ( V_91 ) {
V_92 = strlen ( V_91 ) + 1 ;
F_11 ( & V_35 ) ;
F_12 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_29 -> V_36 , V_21 ,
strlen ( V_21 ) + 1 ) )
break;
}
F_13 ( & V_35 ) ;
if ( & V_29 -> V_37 == & V_38 ) {
V_29 = F_34 ( sizeof( struct V_28 ) ,
V_14 ) ;
if ( ! V_29 ) {
V_4 = - V_15 ;
goto V_13;
}
V_29 -> V_43 = F_34 ( V_92 , V_14 ) ;
if ( ! V_29 -> V_43 ) {
F_9 ( V_29 ) ;
V_4 = - V_15 ;
goto V_13;
}
strncpy ( V_29 -> V_36 , V_21 ,
strlen ( V_21 ) + 1 ) ;
strncpy ( V_29 -> V_43 , V_91 ,
V_92 ) ;
F_11 ( & V_35 ) ;
F_35 ( & V_29 -> V_37 , & V_38 ) ;
F_13 ( & V_35 ) ;
} else {
if ( strncmp ( V_29 -> V_43 , V_91 ,
V_92 ) ) {
F_9 ( V_29 -> V_43 ) ;
V_29 -> V_43 = F_34 ( V_92 ,
V_14 ) ;
if ( V_29 -> V_43 == NULL ) {
V_4 = - V_15 ;
goto V_13;
}
}
memcpy ( V_29 -> V_43 , V_91 , V_92 ) ;
}
F_27 ( V_67 , L_16 ,
V_68 , V_91 , V_92 ) ;
} else {
F_11 ( & V_35 ) ;
F_12 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_29 -> V_36 , V_21 ,
strlen ( V_21 ) + 1 ) ) {
F_17 ( & V_29 -> V_37 ) ;
F_9 ( V_29 -> V_43 ) ;
F_9 ( V_29 ) ;
break;
}
}
F_13 ( & V_35 ) ;
if ( & V_29 -> V_37 == & V_38 )
V_4 = - V_34 ;
}
if ( ! V_4 ) {
V_31 = 0 ;
}
V_13:
return V_4 ;
}
int F_36 ( struct V_19 * V_20 ,
enum V_17 V_18 )
{
int V_4 = 0 ;
V_4 = V_6 ( V_20 , V_18 , NULL ) ;
return V_4 ;
}
static T_1 atoi ( char * V_93 )
{
char * V_94 = V_93 ;
T_1 V_95 = 0 ;
while ( isspace ( * V_94 ) )
V_94 ++ ;
if ( * V_94 == '-' || * V_94 == '+' ) {
V_95 = 10 ;
V_94 ++ ;
} else if ( * V_94 && tolower ( V_94 [ strlen ( V_94 ) - 1 ] ) == 'h' ) {
V_95 = 16 ;
}
return F_37 ( V_94 , NULL , V_95 ) ;
}
static int F_29 ( char * V_93 , T_2 V_96 ,
enum V_17 V_18 ,
struct V_51 * V_97 )
{
int V_4 = 0 ;
char V_73 [] = L_17 ;
char * V_72 ;
char * V_74 ;
T_1 V_98 = 0 ;
T_2 V_99 = 0 ;
#ifdef F_25
T_1 V_100 ;
#endif
switch ( V_18 ) {
case V_101 :
V_72 = V_93 ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 . V_105 =
( T_2 ) atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
F_14 ( V_74 ,
& V_97 -> V_102 . V_103 . V_104 .
V_106 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_98 = strlen ( V_74 ) ;
if ( V_98 > V_107 - 1 )
V_98 = V_107 - 1 ;
strncpy ( V_97 -> V_102 . V_103 . V_104 . V_108 ,
V_74 , V_98 ) ;
V_97 -> V_102 . V_103 . V_104 . V_108 [ V_98 ] = '\0' ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 . V_109 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 . V_110 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 . V_111 .
V_105 = ( T_2 ) atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 .
V_111 . V_112 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 .
V_111 . V_113 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 .
V_111 . V_114 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 .
V_111 . V_115 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 .
V_111 . V_116 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 .
V_111 . V_117 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 .
V_111 . V_118 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 .
V_111 . V_119 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 . V_120 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 . V_121 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 . V_122 =
atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 . V_123 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 . V_124 =
atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 . V_125 =
atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 . V_126 =
atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_104 . V_127 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_98 = strlen ( V_74 ) ;
V_97 -> V_102 . V_103 . V_128 =
F_6 ( V_98 + 1 , V_14 ) ;
strncpy ( V_97 -> V_102 . V_103 . V_128 ,
V_74 , V_98 ) ;
V_97 -> V_102 . V_103 . V_128 [ V_98 ] =
'\0' ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_98 = strlen ( V_74 ) ;
V_97 -> V_102 . V_103 . V_129 =
F_6 ( V_98 + 1 , V_14 ) ;
strncpy ( V_97 -> V_102 . V_103 . V_129 ,
V_74 , V_98 ) ;
V_97 -> V_102 . V_103 . V_129 [ V_98 ] =
'\0' ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_98 = strlen ( V_74 ) ;
V_97 -> V_102 . V_103 . V_130 =
F_6 ( V_98 + 1 , V_14 ) ;
strncpy ( V_97 -> V_102 . V_103 . V_130 ,
V_74 , V_98 ) ;
V_97 -> V_102 . V_103 . V_130 [ V_98 ] =
'\0' ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_131 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_103 . V_132 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
if ( V_74 ) {
V_98 = strlen ( V_74 ) ;
V_97 -> V_102 . V_103 . V_133 =
F_6 ( V_98 + 1 , V_14 ) ;
strncpy ( V_97 -> V_102 . V_103 . V_133 ,
V_74 , V_98 ) ;
V_97 -> V_102 . V_103 . V_133 [ V_98 ] =
'\0' ;
V_74 = F_23 ( & V_72 , V_73 ) ;
}
if ( V_74 ) {
V_97 -> V_102 . V_103 . V_134 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
}
if ( V_74 ) {
V_97 -> V_102 . V_103 . V_135 =
atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
}
if ( V_74 ) {
V_97 -> V_102 . V_103 . V_136 =
atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
}
if ( V_74 ) {
V_97 -> V_102 . V_103 . V_104 . V_137 =
atoi ( V_74 ) ;
for ( V_99 = 0 ;
V_99 <
V_97 -> V_102 . V_103 .
V_104 . V_137 ; V_99 ++ ) {
V_74 = F_23 ( & V_72 , V_73 ) ;
if ( V_74 ) {
V_97 -> V_102 . V_103 .
V_104 . V_138 [ V_99 ] .
V_139 = atoi ( V_74 ) ;
}
}
}
V_74 = F_23 ( & V_72 , V_73 ) ;
if ( V_74 ) {
V_97 -> V_102 . V_103 . V_104 . V_140 =
( T_2 ) ( V_74 ) ;
}
break;
case V_141 :
V_72 = V_93 ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_142 . V_105 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_142 . V_143 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_142 . V_144 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_142 . V_145 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_142 . V_146 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_142 . V_147 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_142 . V_148 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_142 . V_149 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_142 . V_150 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_142 . V_151 = atoi ( V_74 ) ;
#ifdef F_25
for ( V_100 = 0 ; V_100 < 7 ; V_100 ++ ) {
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_152 . V_153 [ V_100 ] .
V_154 = atoi ( V_74 ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_97 -> V_102 . V_152 . V_153 [ V_100 ] .
V_155 = atoi ( V_74 ) ;
}
#endif
break;
default:
V_4 = - V_34 ;
break;
}
return V_4 ;
}
static void F_28 ( char * V_93 , T_2 V_96 , T_1 V_156 )
{
char * V_157 ;
char V_158 ;
char * V_159 ;
V_157 = V_93 ;
if ( V_157 == NULL )
return;
for ( V_159 = V_93 ; V_159 < ( V_93 + V_96 ) ; ) {
V_158 = F_38 ( V_159 , V_156 ) ;
if ( V_158 == '\\' ) {
V_159 += V_156 ;
V_158 = F_38 ( V_159 , V_156 ) ;
switch ( V_158 ) {
case 't' :
* V_157 = '\t' ;
break;
case 'n' :
* V_157 = '\n' ;
break;
case 'r' :
* V_157 = '\r' ;
break;
case '0' :
* V_157 = '\0' ;
break;
default:
* V_157 = V_158 ;
break;
}
} else {
* V_157 = V_158 ;
}
V_157 ++ ;
V_159 += V_156 ;
}
while ( V_157 < V_159 )
* V_157 ++ = '\0' ;
}
static char F_38 ( char * V_160 , T_1 V_161 )
{
char V_158 = '\0' ;
char * V_162 ;
T_1 V_99 ;
for ( V_162 = V_160 , V_99 = V_161 ; V_99 > 0 ; V_99 -- )
V_158 |= * V_162 ++ ;
return V_158 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
T_3 * V_44 ,
T_3 * V_49 ,
struct V_19 * V_45 ,
bool * V_46 ,
enum V_47 V_48 )
{
struct V_1 * V_12 = V_2 ;
char * V_62 = NULL ;
char * V_72 ;
char * V_163 = NULL ;
struct V_53 * V_54 = NULL ;
T_2 V_55 = 0 ;
T_2 V_56 = 0 ;
T_2 V_164 = V_165 ;
char V_73 [] = L_17 ;
char * V_74 = NULL ;
bool V_166 = ( V_45 != NULL ) ;
T_3 V_167 = 0 ;
int V_4 = 0 ;
if ( ! V_166 ) {
* V_44 = 0 ;
* V_49 = 0 ;
}
V_163 = F_6 ( V_164 , V_14 ) ;
if ( V_163 == NULL ) {
V_4 = - V_15 ;
} else {
V_4 = F_31 ( V_2 , V_20 , V_163 ,
& V_164 , V_48 , NULL ) ;
}
if ( ! V_4 ) {
V_4 = F_22 ( V_12 -> V_11 , V_163 ,
V_64 , & V_54 ) ;
}
if ( ! V_4 ) {
V_4 = F_24 ( V_54 , V_168 , & V_55 , & V_56 ) ;
if ( V_4 ) {
V_56 = 0 ;
V_4 = 0 ;
}
}
if ( V_4 || ! ( V_56 > 0 ) )
goto V_76;
V_62 = F_6 ( V_56 + 4 , V_14 ) ;
if ( V_62 == NULL )
V_4 = - V_15 ;
V_4 = F_26 ( V_54 , V_168 , V_62 , V_56 ) ;
if ( V_4 )
goto V_76;
F_28 ( V_62 , V_56 , V_69 ) ;
V_72 = V_62 ;
while ( ( V_74 = F_23 ( & V_72 , V_73 ) ) && * V_74 != '\0' ) {
if ( V_166 ) {
if ( V_167 >= * V_44 ) {
break;
} else {
F_14 ( V_74 ,
& ( V_45
[ V_167 ] ) ) ;
V_74 = F_23 ( & V_72 , V_73 ) ;
V_46 [ V_167 ] = atoi ( V_74 ) ;
V_167 ++ ;
}
} else {
V_74 = F_23 ( & V_72 , V_73 ) ;
if ( atoi ( V_74 ) )
( * V_49 ) ++ ;
( * V_44 ) ++ ;
}
}
V_76:
if ( V_54 )
F_30 ( V_54 ) ;
F_9 ( V_163 ) ;
F_9 ( V_62 ) ;
return V_4 ;
}
