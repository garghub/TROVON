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
T_2 V_55 = 0 ;
T_2 V_56 = 0 ;
T_2 V_57 ;
char V_21 [ V_22 ] ;
char * V_58 ;
struct V_28 * V_29 = NULL ;
char V_59 [ V_60 + 2 ] ;
char * V_61 ;
T_2 V_27 ;
char V_25 [ V_26 ] ;
V_58 = F_6 ( V_60 , V_14 ) ;
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
F_22 ( V_50 , V_58 , V_60 ) ;
if ( ( strlen ( V_21 ) + V_60 ) < V_22 )
strncat ( V_21 , V_58 , V_60 ) ;
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
V_4 = - V_62 ;
goto V_13;
}
}
V_4 = F_23 ( V_12 -> V_11 , V_29 -> V_43 ,
V_63 , & V_54 ) ;
if ( V_4 ) {
V_4 = - V_64 ;
goto V_13;
}
strncpy ( V_59 , L_3 , 2 ) ;
strncat ( V_59 , V_58 , strlen ( V_58 ) ) ;
V_4 = F_24 ( V_54 , V_59 , & V_55 , & V_56 ) ;
if ( V_4 ) {
V_4 = - V_64 ;
goto V_13;
}
V_61 = F_6 ( V_56 + 4 , V_14 ) ;
if ( V_61 == NULL ) {
V_4 = - V_15 ;
goto V_13;
}
#ifdef F_25
if ( strstr ( V_29 -> V_43 , L_4 ) == NULL ) {
V_4 =
F_26 ( V_54 , V_59 , V_61 , V_56 ) ;
} else {
V_4 =
F_26 ( V_54 , V_59 , V_61 , V_56 ) ;
F_27 ( V_65 , L_5 , V_66 ) ;
}
#else
V_4 = F_26 ( V_54 , V_59 , V_61 , V_56 ) ;
#endif
if ( ! V_4 ) {
if ( strstr ( V_29 -> V_43 , L_4 ) == NULL ) {
F_28 ( V_61 , V_56 , V_67 ) ;
} else {
F_28 ( V_61 , V_56 , 1 ) ;
F_27 ( V_65 , L_6
L_7 , V_66 ) ;
}
V_4 =
F_29 ( V_61 , V_56 , V_18 , V_52 ) ;
if ( V_4 )
V_4 = - V_64 ;
} else {
V_4 = - V_64 ;
}
F_9 ( V_61 ) ;
V_13:
if ( V_54 )
F_30 ( V_54 ) ;
F_9 ( V_58 ) ;
return V_4 ;
}
int F_2 ( struct V_1 * V_2 ,
char * V_3 , V_5 V_68 ,
void * V_69 )
{
struct V_1 * V_12 = V_2 ;
int V_4 = 0 ;
char * V_61 ;
char * V_70 ;
struct V_53 * V_54 = NULL ;
T_2 V_55 = 0 ;
T_2 V_56 = 0 ;
char V_71 [] = L_8 ;
char * V_72 = NULL ;
struct V_19 V_24 ;
T_1 V_73 ;
if ( ! V_2 ) {
V_4 = - V_7 ;
goto V_13;
}
V_4 = F_23 ( V_12 -> V_11 , V_3 , V_63 , & V_54 ) ;
if ( V_4 ) {
V_4 = - V_64 ;
goto V_74;
}
V_4 = F_24 ( V_54 , V_75 , & V_55 , & V_56 ) ;
if ( V_4 || ! ( V_56 > 0 ) ) {
V_4 = - V_64 ;
goto V_74;
}
V_61 = F_6 ( V_56 + 4 , V_14 ) ;
if ( V_61 == NULL ) {
V_4 = - V_15 ;
goto V_74;
}
#ifdef F_25
if ( strstr ( V_3 , L_4 ) == NULL ) {
V_4 = F_26 ( V_54 , V_75 ,
V_61 , V_56 ) ;
} else {
F_27 ( V_65 , L_5 , V_66 ) ;
V_4 = F_26 ( V_54 , V_75 ,
V_61 , V_56 ) ;
}
#else
V_4 =
F_26 ( V_54 , V_75 , V_61 , V_56 ) ;
#endif
if ( ! V_4 ) {
if ( strstr ( V_3 , L_4 ) == NULL ) {
F_28 ( V_61 , V_56 , V_67 ) ;
} else {
F_28 ( V_61 , V_56 , 1 ) ;
F_27 ( V_65 , L_9
L_7 , V_66 ) ;
}
V_70 = V_61 ;
while ( ( V_72 = F_31 ( & V_70 , V_71 ) ) && * V_72 != '\0' ) {
F_14 ( V_72 , & V_24 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_73 = atoi ( V_72 ) ;
V_4 =
V_68 ( & V_24 , V_73 , V_69 ) ;
if ( V_4 ) {
break;
}
}
} else {
V_4 = - V_64 ;
}
F_9 ( V_61 ) ;
V_74:
if ( V_54 )
F_30 ( V_54 ) ;
V_13:
return V_4 ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
char * V_76 ,
T_2 * V_77 ,
enum V_47 V_48 , bool * V_78 )
{
char V_21 [ V_22 ] ;
char V_58 [ V_60 ] ;
T_2 V_27 ;
char V_25 [ V_26 ] ;
int V_4 = 0 ;
struct V_28 * V_29 = NULL ;
F_27 ( V_65 , L_10
L_11 , V_66 , V_2 , V_20 , V_76 ,
V_77 ) ;
V_27 = strlen ( V_33 ) + 1 + sizeof( V_25 ) + 1 ;
strncpy ( V_21 , V_33 , strlen ( V_33 ) + 1 ) ;
if ( ( strlen ( V_21 ) + strlen ( L_1 ) ) < V_22 )
strncat ( V_21 , L_1 , 2 ) ;
else
V_4 = - V_34 ;
switch ( V_48 ) {
case V_79 :
sprintf ( V_25 , L_2 , V_80 ) ;
break;
case V_81 :
sprintf ( V_25 , L_2 , V_82 ) ;
break;
case V_83 :
sprintf ( V_25 , L_2 , V_84 ) ;
break;
case V_85 :
sprintf ( V_25 , L_2 , V_86 ) ;
break;
default:
V_4 = - V_87 ;
}
if ( ! V_4 ) {
if ( ( strlen ( V_21 ) + strlen ( V_25 ) ) <
V_22 ) {
strncat ( V_21 , V_25 ,
strlen ( V_25 ) + 1 ) ;
} else {
V_4 = - V_34 ;
}
F_22 ( V_20 , V_58 , V_60 ) ;
if ( ( strlen ( V_21 ) + V_60 ) < V_22 )
strncat ( V_21 , V_58 , V_60 ) ;
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
V_4 = - V_62 ;
if ( V_4 && V_48 != V_85 ) {
if ( V_78 )
* V_78 = false ;
strncpy ( V_21 , V_33 , strlen ( V_33 ) + 1 ) ;
if ( ( strlen ( V_21 ) + strlen ( L_1 ) ) <
V_22 ) {
strncat ( V_21 , L_1 , 2 ) ;
} else {
V_4 = - V_34 ;
}
sprintf ( V_25 , L_2 , V_86 ) ;
if ( ( strlen ( V_21 ) + strlen ( V_25 ) )
< V_22 ) {
strncat ( V_21 , V_25 ,
strlen ( V_25 ) + 1 ) ;
} else {
V_4 = - V_34 ;
}
F_22 ( V_20 , V_58 , V_60 ) ;
if ( ( strlen ( V_21 ) + V_60 ) < V_22 )
strncat ( V_21 , V_58 , V_60 ) ;
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
0 : - V_62 ;
}
if ( ! V_4 )
memcpy ( V_76 , V_29 -> V_43 , strlen ( V_29 -> V_43 ) + 1 ) ;
return V_4 ;
}
bool F_33 ( void )
{
bool V_88 = true ;
if ( V_42 == 0 )
F_34 ( & V_38 ) ;
if ( V_88 )
V_42 ++ ;
return V_88 ;
}
int V_6 ( struct V_19 * V_20 ,
enum V_17 V_18 ,
char * V_89 )
{
int V_4 = 0 ;
char V_21 [ V_22 ] ;
char V_58 [ V_60 + 1 ] ;
T_2 V_90 = 0 ;
T_2 V_27 ;
char V_25 [ V_26 ] ;
struct V_28 * V_29 = NULL ;
F_27 ( V_65 , L_12 ,
V_66 , V_20 , V_18 , V_89 ) ;
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
F_22 ( V_20 , V_58 , V_60 ) ;
if ( ( strlen ( V_21 ) + V_60 ) < V_22 )
strncat ( V_21 , V_58 , V_60 ) ;
else
V_4 = - V_34 ;
}
if ( V_4 )
goto V_13;
if ( V_89 ) {
V_90 = strlen ( V_89 ) + 1 ;
F_11 ( & V_35 ) ;
F_12 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_29 -> V_36 , V_21 ,
strlen ( V_21 ) + 1 ) )
break;
}
F_13 ( & V_35 ) ;
if ( & V_29 -> V_37 == & V_38 ) {
V_29 = F_35 ( sizeof( struct V_28 ) ,
V_14 ) ;
if ( ! V_29 ) {
V_4 = - V_15 ;
goto V_13;
}
V_29 -> V_43 = F_35 ( strlen ( V_21 ) + 1 ,
V_14 ) ;
if ( ! V_29 -> V_43 ) {
F_9 ( V_29 ) ;
V_4 = - V_15 ;
goto V_13;
}
strncpy ( V_29 -> V_36 , V_21 ,
strlen ( V_21 ) + 1 ) ;
strncpy ( V_29 -> V_43 , V_89 ,
V_90 ) ;
F_11 ( & V_35 ) ;
F_36 ( & V_29 -> V_37 , & V_38 ) ;
F_13 ( & V_35 ) ;
} else {
if ( strncmp ( V_29 -> V_43 , V_89 ,
V_90 ) ) {
F_9 ( V_29 -> V_43 ) ;
V_29 -> V_43 = F_35 ( V_90 ,
V_14 ) ;
if ( V_29 -> V_43 == NULL ) {
V_4 = - V_15 ;
goto V_13;
}
}
memcpy ( V_29 -> V_43 , V_89 , V_90 ) ;
}
F_27 ( V_65 , L_13 ,
V_66 , V_89 , V_90 ) ;
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
int F_37 ( struct V_19 * V_20 ,
enum V_17 V_18 )
{
int V_4 = 0 ;
V_4 = V_6 ( V_20 , V_18 , NULL ) ;
return V_4 ;
}
static T_1 atoi ( char * V_91 )
{
char * V_92 = V_91 ;
T_1 V_93 = 0 ;
while ( isspace ( * V_92 ) )
V_92 ++ ;
if ( * V_92 == '-' || * V_92 == '+' ) {
V_93 = 10 ;
V_92 ++ ;
} else if ( * V_92 && tolower ( V_92 [ strlen ( V_92 ) - 1 ] ) == 'h' ) {
V_93 = 16 ;
}
return F_38 ( V_92 , NULL , V_93 ) ;
}
static int F_29 ( char * V_91 , T_2 V_94 ,
enum V_17 V_18 ,
struct V_51 * V_95 )
{
int V_4 = 0 ;
char V_71 [] = L_14 ;
char * V_70 ;
char * V_72 ;
T_1 V_96 = 0 ;
T_2 V_97 = 0 ;
#ifdef F_25
T_1 V_98 ;
#endif
switch ( V_18 ) {
case V_99 :
V_70 = V_91 ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 . V_103 =
( T_2 ) atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
F_14 ( V_72 ,
& V_95 -> V_100 . V_101 . V_102 .
V_104 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_96 = strlen ( V_72 ) ;
if ( V_96 > V_105 - 1 )
V_96 = V_105 - 1 ;
strncpy ( V_95 -> V_100 . V_101 . V_102 . V_106 ,
V_72 , V_96 ) ;
V_95 -> V_100 . V_101 . V_102 . V_106 [ V_96 ] = '\0' ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 . V_107 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 . V_108 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 . V_109 .
V_103 = ( T_2 ) atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 .
V_109 . V_110 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 .
V_109 . V_111 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 .
V_109 . V_112 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 .
V_109 . V_113 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 .
V_109 . V_114 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 .
V_109 . V_115 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 .
V_109 . V_116 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 .
V_109 . V_117 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 . V_118 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 . V_119 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 . V_120 =
atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 . V_121 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 . V_122 =
atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 . V_123 =
atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 . V_124 =
atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_102 . V_125 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_96 = strlen ( V_72 ) ;
V_95 -> V_100 . V_101 . V_126 =
F_6 ( V_96 + 1 , V_14 ) ;
strncpy ( V_95 -> V_100 . V_101 . V_126 ,
V_72 , V_96 ) ;
V_95 -> V_100 . V_101 . V_126 [ V_96 ] =
'\0' ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_96 = strlen ( V_72 ) ;
V_95 -> V_100 . V_101 . V_127 =
F_6 ( V_96 + 1 , V_14 ) ;
strncpy ( V_95 -> V_100 . V_101 . V_127 ,
V_72 , V_96 ) ;
V_95 -> V_100 . V_101 . V_127 [ V_96 ] =
'\0' ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_96 = strlen ( V_72 ) ;
V_95 -> V_100 . V_101 . V_128 =
F_6 ( V_96 + 1 , V_14 ) ;
strncpy ( V_95 -> V_100 . V_101 . V_128 ,
V_72 , V_96 ) ;
V_95 -> V_100 . V_101 . V_128 [ V_96 ] =
'\0' ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_129 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_101 . V_130 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
if ( V_72 ) {
V_96 = strlen ( V_72 ) ;
V_95 -> V_100 . V_101 . V_131 =
F_6 ( V_96 + 1 , V_14 ) ;
strncpy ( V_95 -> V_100 . V_101 . V_131 ,
V_72 , V_96 ) ;
V_95 -> V_100 . V_101 . V_131 [ V_96 ] =
'\0' ;
V_72 = F_31 ( & V_70 , V_71 ) ;
}
if ( V_72 ) {
V_95 -> V_100 . V_101 . V_132 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
}
if ( V_72 ) {
V_95 -> V_100 . V_101 . V_133 =
atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
}
if ( V_72 ) {
V_95 -> V_100 . V_101 . V_134 =
atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
}
if ( V_72 ) {
V_95 -> V_100 . V_101 . V_102 . V_135 =
atoi ( V_72 ) ;
for ( V_97 = 0 ;
V_97 <
V_95 -> V_100 . V_101 .
V_102 . V_135 ; V_97 ++ ) {
V_72 = F_31 ( & V_70 , V_71 ) ;
if ( V_72 ) {
V_95 -> V_100 . V_101 .
V_102 . V_136 [ V_97 ] .
V_137 = atoi ( V_72 ) ;
}
}
}
V_72 = F_31 ( & V_70 , V_71 ) ;
if ( V_72 ) {
V_95 -> V_100 . V_101 . V_102 . V_138 =
( T_2 ) ( V_72 ) ;
}
break;
case V_139 :
V_70 = V_91 ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_140 . V_103 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_140 . V_141 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_140 . V_142 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_140 . V_143 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_140 . V_144 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_140 . V_145 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_140 . V_146 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_140 . V_147 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_140 . V_148 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_140 . V_149 = atoi ( V_72 ) ;
#ifdef F_25
for ( V_98 = 0 ; V_98 < 7 ; V_98 ++ ) {
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_150 . V_151 [ V_98 ] .
V_152 = atoi ( V_72 ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_95 -> V_100 . V_150 . V_151 [ V_98 ] .
V_153 = atoi ( V_72 ) ;
}
#endif
break;
default:
V_4 = - V_34 ;
break;
}
return V_4 ;
}
static void F_28 ( char * V_91 , T_2 V_94 , T_1 V_154 )
{
char * V_155 ;
char V_156 ;
char * V_157 ;
V_155 = V_91 ;
if ( V_155 == NULL )
return;
for ( V_157 = V_91 ; V_157 < ( V_91 + V_94 ) ; ) {
V_156 = F_39 ( V_157 , V_154 ) ;
if ( V_156 == '\\' ) {
V_157 += V_154 ;
V_156 = F_39 ( V_157 , V_154 ) ;
switch ( V_156 ) {
case 't' :
* V_155 = '\t' ;
break;
case 'n' :
* V_155 = '\n' ;
break;
case 'r' :
* V_155 = '\r' ;
break;
case '0' :
* V_155 = '\0' ;
break;
default:
* V_155 = V_156 ;
break;
}
} else {
* V_155 = V_156 ;
}
V_155 ++ ;
V_157 += V_154 ;
}
while ( V_155 < V_157 )
* V_155 ++ = '\0' ;
}
static char F_39 ( char * V_158 , T_1 V_159 )
{
char V_156 = '\0' ;
char * V_160 ;
T_1 V_97 ;
for ( V_160 = V_158 , V_97 = V_159 ; V_97 > 0 ; V_97 -- )
V_156 |= * V_160 ++ ;
return V_156 ;
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
char * V_61 = NULL ;
char * V_70 ;
char * V_161 = NULL ;
struct V_53 * V_54 = NULL ;
T_2 V_55 = 0 ;
T_2 V_56 = 0 ;
T_2 V_162 = V_163 ;
char V_71 [] = L_14 ;
char * V_72 = NULL ;
bool V_164 = ( V_45 != NULL ) ;
T_3 V_165 = 0 ;
int V_4 = 0 ;
if ( ! V_164 ) {
* V_44 = 0 ;
* V_49 = 0 ;
}
V_161 = F_6 ( V_162 , V_14 ) ;
if ( V_161 == NULL ) {
V_4 = - V_15 ;
} else {
V_4 = F_32 ( V_2 , V_20 , V_161 ,
& V_162 , V_48 , NULL ) ;
}
if ( ! V_4 ) {
V_4 = F_23 ( V_12 -> V_11 , V_161 ,
V_63 , & V_54 ) ;
}
if ( ! V_4 ) {
V_4 = F_24 ( V_54 , V_166 , & V_55 , & V_56 ) ;
if ( V_4 ) {
V_56 = 0 ;
V_4 = 0 ;
}
}
if ( V_4 || ! ( V_56 > 0 ) )
goto V_74;
V_61 = F_6 ( V_56 + 4 , V_14 ) ;
if ( V_61 == NULL )
V_4 = - V_15 ;
V_4 = F_26 ( V_54 , V_166 , V_61 , V_56 ) ;
if ( V_4 )
goto V_74;
F_28 ( V_61 , V_56 , V_67 ) ;
V_70 = V_61 ;
while ( ( V_72 = F_31 ( & V_70 , V_71 ) ) && * V_72 != '\0' ) {
if ( V_164 ) {
if ( V_165 >= * V_44 ) {
break;
} else {
F_14 ( V_72 ,
& ( V_45
[ V_165 ] ) ) ;
V_72 = F_31 ( & V_70 , V_71 ) ;
V_46 [ V_165 ] = atoi ( V_72 ) ;
V_165 ++ ;
}
} else {
V_72 = F_31 ( & V_70 , V_71 ) ;
if ( atoi ( V_72 ) )
( * V_49 ) ++ ;
( * V_44 ) ++ ;
}
}
V_74:
if ( V_54 )
F_30 ( V_54 ) ;
F_9 ( V_161 ) ;
F_9 ( V_61 ) ;
return V_4 ;
}
