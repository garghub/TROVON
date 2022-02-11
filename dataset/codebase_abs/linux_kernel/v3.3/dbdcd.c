int F_1 ( struct V_1 * V_2 ,
char * V_3 )
{
int V_4 = 0 ;
F_2 ( V_5 > 0 ) ;
if ( V_2 )
V_4 = F_3 ( V_2 , V_3 ,
( V_6 ) V_7 ,
( void * ) V_3 ) ;
else
V_4 = - V_8 ;
return V_4 ;
}
int F_4 ( struct V_1 * V_2 ,
char * V_3 )
{
int V_4 = 0 ;
F_2 ( V_5 > 0 ) ;
if ( V_2 )
V_4 = F_3 ( V_2 , V_3 ,
( V_6 ) V_7 ,
NULL ) ;
else
V_4 = - V_8 ;
return V_4 ;
}
int F_5 ( char * V_9 ,
struct V_1 * * V_10 )
{
struct V_11 * V_12 ;
struct V_1 * V_13 = NULL ;
int V_4 = 0 ;
F_2 ( V_5 >= 0 ) ;
F_2 ( V_10 ) ;
V_4 = F_6 ( & V_12 , V_9 ) ;
if ( V_4 )
goto V_14;
V_13 = F_7 ( sizeof( struct V_1 ) , V_15 ) ;
if ( V_13 != NULL ) {
V_13 -> V_12 = V_12 ;
* V_10 = V_13 ;
} else {
V_4 = - V_16 ;
F_8 ( V_12 ) ;
}
F_9 ( ( ! V_4 ) ||
( ( V_13 == NULL ) && ( V_4 == - V_16 ) ) ) ;
V_14:
return V_4 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_1 * V_13 = V_2 ;
int V_4 = - V_8 ;
F_2 ( V_5 >= 0 ) ;
if ( V_2 ) {
F_8 ( V_13 -> V_12 ) ;
F_11 ( V_13 ) ;
V_4 = 0 ;
}
return V_4 ;
}
int F_12 ( T_1 V_17 , enum V_18 V_19 ,
struct V_20 * V_21 )
{
int V_4 = 0 ;
char V_22 [ V_23 ] ;
char V_24 [ V_23 ] ;
struct V_20 V_25 ;
char V_26 [ V_27 ] ;
T_2 V_28 = 0 ;
struct V_29 * V_30 ;
int V_31 ;
F_2 ( V_5 >= 0 ) ;
F_2 ( V_17 >= 0 ) ;
F_2 ( V_21 != NULL ) ;
if ( ( V_17 != 0 ) && ( V_32 == 0 ) ) {
V_4 = - V_33 ;
} else {
V_28 = strlen ( V_34 ) + 1 + sizeof( V_26 ) + 1 ;
F_13 ( V_28 < V_23 ) ;
strncpy ( V_22 , V_34 , strlen ( V_34 ) + 1 ) ;
if ( ( strlen ( V_22 ) + strlen ( L_1 ) ) <
V_23 ) {
strncat ( V_22 , L_1 , 2 ) ;
} else {
V_4 = - V_35 ;
}
V_4 = snprintf ( V_26 , V_27 , L_2 ,
V_19 ) ;
if ( V_4 == - 1 ) {
V_4 = - V_35 ;
} else {
V_4 = 0 ;
if ( ( strlen ( V_22 ) + strlen ( V_26 ) ) <
V_23 ) {
strncat ( V_22 , V_26 ,
strlen ( V_26 ) + 1 ) ;
} else {
V_4 = - V_35 ;
}
}
if ( ! V_4 ) {
V_31 = strlen ( V_22 ) ;
F_14 ( & V_36 ) ;
F_15 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_30 -> V_37 , V_22 , V_31 )
&& ! V_17 -- ) {
strncpy ( V_24 , & V_30 -> V_37 [ V_31 ] ,
strlen ( & V_30 -> V_37 [ V_31 ] ) + 1 ) ;
break;
}
}
F_16 ( & V_36 ) ;
if ( & V_30 -> V_38 == & V_39 )
V_4 = - V_40 ;
}
if ( ! V_4 ) {
F_17 ( V_24 , & V_25 ) ;
* V_21 = V_25 ;
V_32 ++ ;
V_4 = 0 ;
} else if ( V_4 == - V_40 ) {
V_32 = 0 ;
V_4 = V_40 ;
} else {
V_4 = - V_35 ;
}
}
F_9 ( V_21 || ( V_4 == - V_35 ) ) ;
return V_4 ;
}
void F_18 ( void )
{
struct V_29 * V_41 , * V_42 ;
F_2 ( V_5 > 0 ) ;
V_5 -- ;
if ( V_5 == 0 ) {
F_19 () ;
F_20 (rv, rv_tmp, &reg_key_list, link) {
F_21 ( & V_41 -> V_38 ) ;
F_11 ( V_41 -> V_43 ) ;
F_11 ( V_41 ) ;
}
}
F_9 ( V_5 >= 0 ) ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
T_3 V_44 , struct V_20 * V_45 ,
bool * V_46 ,
enum V_47 V_48 )
{
int V_4 = 0 ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_2 ) ;
F_2 ( V_21 != NULL ) ;
F_2 ( V_45 != NULL ) ;
F_2 ( V_46 != NULL ) ;
V_4 =
F_23 ( V_2 , V_21 , & V_44 , NULL , V_45 ,
V_46 , V_48 ) ;
return V_4 ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
T_3 * V_44 , T_3 * V_49 ,
enum V_47 V_48 )
{
int V_4 = 0 ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_2 ) ;
F_2 ( V_44 != NULL ) ;
F_2 ( V_49 != NULL ) ;
F_2 ( V_21 != NULL ) ;
V_4 = F_23 ( V_2 , V_21 , V_44 , V_49 ,
NULL , NULL , V_48 ) ;
return V_4 ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_20 * V_50 ,
enum V_18 V_19 ,
struct V_51 * V_52 )
{
struct V_1 * V_13 = V_2 ;
struct V_53 * V_54 = NULL ;
int V_4 = 0 ;
T_2 V_55 = 0 ;
T_2 V_56 = 0 ;
T_2 V_57 ;
char V_22 [ V_23 ] ;
char * V_58 ;
struct V_29 * V_30 = NULL ;
char V_59 [ V_60 + 2 ] ;
char * V_61 ;
T_2 V_28 ;
char V_26 [ V_27 ] ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_52 != NULL ) ;
F_2 ( V_50 != NULL ) ;
V_58 = F_7 ( V_60 , V_15 ) ;
if ( ! V_58 ) {
V_4 = - V_16 ;
goto V_14;
}
if ( ! V_2 ) {
V_4 = - V_8 ;
goto V_14;
}
V_28 = strlen ( V_34 ) + 1 + sizeof( V_26 ) + 1 ;
F_13 ( V_28 < V_23 ) ;
strncpy ( V_22 , V_34 , strlen ( V_34 ) + 1 ) ;
if ( ( strlen ( V_22 ) + strlen ( L_1 ) ) < V_23 )
strncat ( V_22 , L_1 , 2 ) ;
else
V_4 = - V_35 ;
V_4 = snprintf ( V_26 , V_27 , L_2 , V_19 ) ;
if ( V_4 == - 1 ) {
V_4 = - V_35 ;
} else {
V_4 = 0 ;
if ( ( strlen ( V_22 ) + strlen ( V_26 ) ) <
V_23 ) {
strncat ( V_22 , V_26 ,
strlen ( V_26 ) + 1 ) ;
} else {
V_4 = - V_35 ;
}
F_26 ( V_50 , V_58 , V_60 ) ;
if ( ( strlen ( V_22 ) + V_60 ) < V_23 )
strncat ( V_22 , V_58 , V_60 ) ;
else
V_4 = - V_35 ;
V_57 = V_23 ;
}
if ( ! V_4 ) {
F_14 ( & V_36 ) ;
F_15 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_30 -> V_37 , V_22 ,
strlen ( V_22 ) + 1 ) )
break;
}
F_16 ( & V_36 ) ;
if ( & V_30 -> V_38 == & V_39 ) {
V_4 = - V_62 ;
goto V_14;
}
}
V_4 = F_27 ( V_13 -> V_12 , V_30 -> V_43 ,
V_63 , & V_54 ) ;
if ( V_4 ) {
V_4 = - V_64 ;
goto V_14;
}
F_13 ( ( strlen ( V_58 ) + 1 ) < sizeof( V_59 ) ) ;
strncpy ( V_59 , L_3 , 2 ) ;
strncat ( V_59 , V_58 , strlen ( V_58 ) ) ;
V_4 = F_28 ( V_54 , V_59 , & V_55 , & V_56 ) ;
if ( V_4 ) {
V_4 = - V_64 ;
goto V_14;
}
V_61 = F_7 ( V_56 + 4 , V_15 ) ;
if ( V_61 == NULL ) {
V_4 = - V_16 ;
goto V_14;
}
#ifdef F_29
if ( strstr ( V_30 -> V_43 , L_4 ) == NULL ) {
V_4 =
F_30 ( V_54 , V_59 , V_61 , V_56 ) ;
} else {
V_4 =
F_30 ( V_54 , V_59 , V_61 , V_56 ) ;
F_31 ( V_65 , L_5 , V_66 ) ;
}
#else
V_4 = F_30 ( V_54 , V_59 , V_61 , V_56 ) ;
#endif
if ( ! V_4 ) {
if ( strstr ( V_30 -> V_43 , L_4 ) == NULL ) {
F_32 ( V_61 , V_56 , V_67 ) ;
} else {
F_32 ( V_61 , V_56 , 1 ) ;
F_31 ( V_65 , L_6
L_7 , V_66 ) ;
}
V_4 =
F_33 ( V_61 , V_56 , V_19 , V_52 ) ;
if ( V_4 )
V_4 = - V_64 ;
} else {
V_4 = - V_64 ;
}
F_11 ( V_61 ) ;
V_14:
if ( V_54 )
F_34 ( V_54 ) ;
F_11 ( V_58 ) ;
return V_4 ;
}
int F_3 ( struct V_1 * V_2 ,
char * V_3 , V_6 V_68 ,
void * V_69 )
{
struct V_1 * V_13 = V_2 ;
int V_4 = 0 ;
char * V_61 ;
char * V_70 ;
struct V_53 * V_54 = NULL ;
T_2 V_55 = 0 ;
T_2 V_56 = 0 ;
char V_71 [] = L_8 ;
char * V_72 = NULL ;
struct V_20 V_25 ;
T_1 V_73 ;
F_2 ( V_5 > 0 ) ;
if ( ! V_2 ) {
V_4 = - V_8 ;
goto V_14;
}
V_4 = F_27 ( V_13 -> V_12 , V_3 , V_63 , & V_54 ) ;
if ( V_4 ) {
V_4 = - V_64 ;
goto V_74;
}
V_4 = F_28 ( V_54 , V_75 , & V_55 , & V_56 ) ;
if ( V_4 || ! ( V_56 > 0 ) ) {
V_4 = - V_64 ;
goto V_74;
}
V_61 = F_7 ( V_56 + 4 , V_15 ) ;
if ( V_61 == NULL ) {
V_4 = - V_16 ;
goto V_74;
}
#ifdef F_29
if ( strstr ( V_3 , L_4 ) == NULL ) {
V_4 = F_30 ( V_54 , V_75 ,
V_61 , V_56 ) ;
} else {
F_31 ( V_65 , L_5 , V_66 ) ;
V_4 = F_30 ( V_54 , V_75 ,
V_61 , V_56 ) ;
}
#else
V_4 =
F_30 ( V_54 , V_75 , V_61 , V_56 ) ;
#endif
if ( ! V_4 ) {
if ( strstr ( V_3 , L_4 ) == NULL ) {
F_32 ( V_61 , V_56 , V_67 ) ;
} else {
F_32 ( V_61 , V_56 , 1 ) ;
F_31 ( V_65 , L_9
L_7 , V_66 ) ;
}
V_70 = V_61 ;
while ( ( V_72 = F_35 ( & V_70 , V_71 ) ) && * V_72 != '\0' ) {
F_17 ( V_72 , & V_25 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_73 = atoi ( V_72 ) ;
V_4 =
V_68 ( & V_25 , V_73 , V_69 ) ;
if ( V_4 ) {
break;
}
}
} else {
V_4 = - V_64 ;
}
F_11 ( V_61 ) ;
V_74:
if ( V_54 )
F_34 ( V_54 ) ;
V_14:
return V_4 ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
char * V_76 ,
T_2 * V_77 ,
enum V_47 V_48 , bool * V_78 )
{
char V_22 [ V_23 ] ;
char V_58 [ V_60 ] ;
T_2 V_28 ;
char V_26 [ V_27 ] ;
int V_4 = 0 ;
struct V_29 * V_30 = NULL ;
F_2 ( V_21 != NULL ) ;
F_2 ( V_76 != NULL ) ;
F_2 ( V_77 != NULL ) ;
F_2 ( V_2 ) ;
F_31 ( V_65 , L_10
L_11 , V_66 , V_2 , V_21 , V_76 ,
V_77 ) ;
V_28 = strlen ( V_34 ) + 1 + sizeof( V_26 ) + 1 ;
F_13 ( V_28 < V_23 ) ;
strncpy ( V_22 , V_34 , strlen ( V_34 ) + 1 ) ;
if ( ( strlen ( V_22 ) + strlen ( L_1 ) ) < V_23 )
strncat ( V_22 , L_1 , 2 ) ;
else
V_4 = - V_35 ;
switch ( V_48 ) {
case V_79 :
sprintf ( V_26 , L_2 , V_80 ) ;
break;
case V_81 :
sprintf ( V_26 , L_2 , V_82 ) ;
break;
case V_83 :
sprintf ( V_26 , L_2 , V_84 ) ;
break;
case V_85 :
sprintf ( V_26 , L_2 , V_86 ) ;
break;
default:
V_4 = - V_87 ;
F_13 ( false ) ;
}
if ( ! V_4 ) {
if ( ( strlen ( V_22 ) + strlen ( V_26 ) ) <
V_23 ) {
strncat ( V_22 , V_26 ,
strlen ( V_26 ) + 1 ) ;
} else {
V_4 = - V_35 ;
}
F_26 ( V_21 , V_58 , V_60 ) ;
if ( ( strlen ( V_22 ) + V_60 ) < V_23 )
strncat ( V_22 , V_58 , V_60 ) ;
else
V_4 = - V_35 ;
}
if ( ! V_4 ) {
F_14 ( & V_36 ) ;
F_15 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_30 -> V_37 , V_22 ,
strlen ( V_22 ) + 1 ) )
break;
}
F_16 ( & V_36 ) ;
}
if ( & V_30 -> V_38 == & V_39 )
V_4 = - V_62 ;
if ( V_4 && V_48 != V_85 ) {
if ( V_78 )
* V_78 = false ;
strncpy ( V_22 , V_34 , strlen ( V_34 ) + 1 ) ;
if ( ( strlen ( V_22 ) + strlen ( L_1 ) ) <
V_23 ) {
strncat ( V_22 , L_1 , 2 ) ;
} else {
V_4 = - V_35 ;
}
sprintf ( V_26 , L_2 , V_86 ) ;
if ( ( strlen ( V_22 ) + strlen ( V_26 ) )
< V_23 ) {
strncat ( V_22 , V_26 ,
strlen ( V_26 ) + 1 ) ;
} else {
V_4 = - V_35 ;
}
F_26 ( V_21 , V_58 , V_60 ) ;
if ( ( strlen ( V_22 ) + V_60 ) < V_23 )
strncat ( V_22 , V_58 , V_60 ) ;
else
V_4 = - V_35 ;
F_14 ( & V_36 ) ;
F_15 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_30 -> V_37 , V_22 ,
strlen ( V_22 ) + 1 ) )
break;
}
F_16 ( & V_36 ) ;
V_4 = ( & V_30 -> V_38 != & V_39 ) ?
0 : - V_62 ;
}
if ( ! V_4 )
memcpy ( V_76 , V_30 -> V_43 , strlen ( V_30 -> V_43 ) + 1 ) ;
return V_4 ;
}
bool F_37 ( void )
{
bool V_88 ;
bool V_89 = true ;
F_2 ( V_5 >= 0 ) ;
if ( V_5 == 0 ) {
V_88 = F_38 () ;
if ( ! V_88 ) {
V_89 = false ;
if ( V_88 )
F_19 () ;
}
F_39 ( & V_39 ) ;
}
if ( V_89 )
V_5 ++ ;
F_9 ( ( V_89 && ( V_5 > 0 ) ) || ( ! V_89 && ( V_5 == 0 ) ) ) ;
return V_89 ;
}
int V_7 ( struct V_20 * V_21 ,
enum V_18 V_19 ,
char * V_90 )
{
int V_4 = 0 ;
char V_22 [ V_23 ] ;
char V_58 [ V_60 + 1 ] ;
T_2 V_91 = 0 ;
T_2 V_28 ;
char V_26 [ V_27 ] ;
struct V_29 * V_30 = NULL ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_21 != NULL ) ;
F_2 ( ( V_19 == V_92 ) ||
( V_19 == V_93 ) ||
( V_19 == V_86 ) ||
( V_19 == V_80 ) ||
( V_19 == V_82 ) ||
( V_19 == V_84 ) ) ;
F_31 ( V_65 , L_12 ,
V_66 , V_21 , V_19 , V_90 ) ;
V_28 = strlen ( V_34 ) + 1 + sizeof( V_26 ) + 1 ;
F_13 ( V_28 < V_23 ) ;
strncpy ( V_22 , V_34 , strlen ( V_34 ) + 1 ) ;
if ( ( strlen ( V_22 ) + strlen ( L_1 ) ) < V_23 )
strncat ( V_22 , L_1 , 2 ) ;
else {
V_4 = - V_35 ;
goto V_14;
}
V_4 = snprintf ( V_26 , V_27 , L_2 , V_19 ) ;
if ( V_4 == - 1 ) {
V_4 = - V_35 ;
} else {
V_4 = 0 ;
if ( ( strlen ( V_22 ) + strlen ( V_26 ) ) <
V_23 ) {
strncat ( V_22 , V_26 ,
strlen ( V_26 ) + 1 ) ;
} else
V_4 = - V_35 ;
F_26 ( V_21 , V_58 , V_60 ) ;
if ( ( strlen ( V_22 ) + V_60 ) < V_23 )
strncat ( V_22 , V_58 , V_60 ) ;
else
V_4 = - V_35 ;
}
if ( V_4 )
goto V_14;
if ( V_90 ) {
V_91 = strlen ( V_90 ) + 1 ;
F_14 ( & V_36 ) ;
F_15 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_30 -> V_37 , V_22 ,
strlen ( V_22 ) + 1 ) )
break;
}
F_16 ( & V_36 ) ;
if ( & V_30 -> V_38 == & V_39 ) {
V_30 = F_40 ( sizeof( struct V_29 ) ,
V_15 ) ;
if ( ! V_30 ) {
V_4 = - V_16 ;
goto V_14;
}
V_30 -> V_43 = F_40 ( strlen ( V_22 ) + 1 ,
V_15 ) ;
if ( ! V_30 -> V_43 ) {
F_11 ( V_30 ) ;
V_4 = - V_16 ;
goto V_14;
}
strncpy ( V_30 -> V_37 , V_22 ,
strlen ( V_22 ) + 1 ) ;
strncpy ( V_30 -> V_43 , V_90 ,
V_91 ) ;
F_14 ( & V_36 ) ;
F_41 ( & V_30 -> V_38 , & V_39 ) ;
F_16 ( & V_36 ) ;
} else {
if ( strncmp ( V_30 -> V_43 , V_90 ,
V_91 ) ) {
F_11 ( V_30 -> V_43 ) ;
V_30 -> V_43 = F_40 ( V_91 ,
V_15 ) ;
if ( V_30 -> V_43 == NULL ) {
V_4 = - V_16 ;
goto V_14;
}
}
memcpy ( V_30 -> V_43 , V_90 , V_91 ) ;
}
F_31 ( V_65 , L_13 ,
V_66 , V_90 , V_91 ) ;
} else {
F_14 ( & V_36 ) ;
F_15 (dcd_key, &reg_key_list, link) {
if ( ! strncmp ( V_30 -> V_37 , V_22 ,
strlen ( V_22 ) + 1 ) ) {
F_21 ( & V_30 -> V_38 ) ;
F_11 ( V_30 -> V_43 ) ;
F_11 ( V_30 ) ;
break;
}
}
F_16 ( & V_36 ) ;
if ( & V_30 -> V_38 == & V_39 )
V_4 = - V_35 ;
}
if ( ! V_4 ) {
V_32 = 0 ;
}
V_14:
return V_4 ;
}
int F_42 ( struct V_20 * V_21 ,
enum V_18 V_19 )
{
int V_4 = 0 ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_21 != NULL ) ;
F_2 ( ( V_19 == V_92 ) ||
( V_19 == V_93 ) ||
( V_19 == V_86 ) ||
( V_19 == V_80 ) ||
( V_19 == V_82 ) ||
( V_19 == V_84 ) ) ;
V_4 = V_7 ( V_21 , V_19 , NULL ) ;
return V_4 ;
}
static T_1 atoi ( char * V_94 )
{
char * V_95 = V_94 ;
T_1 V_96 = 0 ;
while ( isspace ( * V_95 ) )
V_95 ++ ;
if ( * V_95 == '-' || * V_95 == '+' ) {
V_96 = 10 ;
V_95 ++ ;
} else if ( * V_95 && tolower ( V_95 [ strlen ( V_95 ) - 1 ] ) == 'h' ) {
V_96 = 16 ;
}
return F_43 ( V_95 , NULL , V_96 ) ;
}
static int F_33 ( char * V_94 , T_2 V_97 ,
enum V_18 V_19 ,
struct V_51 * V_98 )
{
int V_4 = 0 ;
char V_71 [] = L_14 ;
char * V_70 ;
char * V_72 ;
T_1 V_99 = 0 ;
T_2 V_100 = 0 ;
#ifdef F_29
T_1 V_101 ;
#endif
F_2 ( V_94 != NULL ) ;
F_2 ( V_97 != 0 ) ;
F_2 ( ( V_19 == V_92 )
|| ( V_19 == V_93 ) ) ;
F_2 ( V_98 != NULL ) ;
switch ( V_19 ) {
case V_92 :
V_70 = V_94 ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 . V_105 =
( T_2 ) atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
F_17 ( V_72 ,
& V_98 -> V_102 . V_103 . V_104 .
V_106 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
F_2 ( V_72 ) ;
V_99 = strlen ( V_72 ) ;
if ( V_99 > V_107 - 1 )
V_99 = V_107 - 1 ;
strncpy ( V_98 -> V_102 . V_103 . V_104 . V_108 ,
V_72 , V_99 ) ;
V_98 -> V_102 . V_103 . V_104 . V_108 [ V_99 ] = '\0' ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 . V_109 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 . V_110 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 . V_111 .
V_105 = ( T_2 ) atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 .
V_111 . V_112 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 .
V_111 . V_113 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 .
V_111 . V_114 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 .
V_111 . V_115 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 .
V_111 . V_116 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 .
V_111 . V_117 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 .
V_111 . V_118 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 .
V_111 . V_119 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 . V_120 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 . V_121 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 . V_122 =
atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 . V_123 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 . V_124 =
atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 . V_125 =
atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 . V_126 =
atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_104 . V_127 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
F_2 ( V_72 ) ;
V_99 = strlen ( V_72 ) ;
V_98 -> V_102 . V_103 . V_128 =
F_7 ( V_99 + 1 , V_15 ) ;
strncpy ( V_98 -> V_102 . V_103 . V_128 ,
V_72 , V_99 ) ;
V_98 -> V_102 . V_103 . V_128 [ V_99 ] =
'\0' ;
V_72 = F_35 ( & V_70 , V_71 ) ;
F_2 ( V_72 ) ;
V_99 = strlen ( V_72 ) ;
V_98 -> V_102 . V_103 . V_129 =
F_7 ( V_99 + 1 , V_15 ) ;
strncpy ( V_98 -> V_102 . V_103 . V_129 ,
V_72 , V_99 ) ;
V_98 -> V_102 . V_103 . V_129 [ V_99 ] =
'\0' ;
V_72 = F_35 ( & V_70 , V_71 ) ;
F_2 ( V_72 ) ;
V_99 = strlen ( V_72 ) ;
V_98 -> V_102 . V_103 . V_130 =
F_7 ( V_99 + 1 , V_15 ) ;
strncpy ( V_98 -> V_102 . V_103 . V_130 ,
V_72 , V_99 ) ;
V_98 -> V_102 . V_103 . V_130 [ V_99 ] =
'\0' ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_131 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_103 . V_132 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
if ( V_72 ) {
V_99 = strlen ( V_72 ) ;
V_98 -> V_102 . V_103 . V_133 =
F_7 ( V_99 + 1 , V_15 ) ;
strncpy ( V_98 -> V_102 . V_103 . V_133 ,
V_72 , V_99 ) ;
V_98 -> V_102 . V_103 . V_133 [ V_99 ] =
'\0' ;
V_72 = F_35 ( & V_70 , V_71 ) ;
}
if ( V_72 ) {
V_98 -> V_102 . V_103 . V_134 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
}
if ( V_72 ) {
V_98 -> V_102 . V_103 . V_135 =
atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
}
if ( V_72 ) {
V_98 -> V_102 . V_103 . V_136 =
atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
}
if ( V_72 ) {
V_98 -> V_102 . V_103 . V_104 . V_137 =
atoi ( V_72 ) ;
for ( V_100 = 0 ;
V_100 <
V_98 -> V_102 . V_103 .
V_104 . V_137 ; V_100 ++ ) {
V_72 = F_35 ( & V_70 , V_71 ) ;
if ( V_72 ) {
V_98 -> V_102 . V_103 .
V_104 . V_138 [ V_100 ] .
V_139 = atoi ( V_72 ) ;
}
}
}
V_72 = F_35 ( & V_70 , V_71 ) ;
if ( V_72 ) {
V_98 -> V_102 . V_103 . V_104 . V_140 =
( T_2 ) ( V_72 ) ;
}
break;
case V_93 :
V_70 = V_94 ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_141 . V_105 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_141 . V_142 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_141 . V_143 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_141 . V_144 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_141 . V_145 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_141 . V_146 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_141 . V_147 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_141 . V_148 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_141 . V_149 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_141 . V_150 = atoi ( V_72 ) ;
#ifdef F_29
for ( V_101 = 0 ; V_101 < 7 ; V_101 ++ ) {
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_151 . V_152 [ V_101 ] .
V_153 = atoi ( V_72 ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_98 -> V_102 . V_151 . V_152 [ V_101 ] .
V_154 = atoi ( V_72 ) ;
}
#endif
break;
default:
V_4 = - V_35 ;
break;
}
return V_4 ;
}
static void F_32 ( char * V_94 , T_2 V_97 , T_1 V_155 )
{
char * V_156 ;
char V_157 ;
char * V_158 ;
V_156 = V_94 ;
if ( V_156 == NULL )
return;
for ( V_158 = V_94 ; V_158 < ( V_94 + V_97 ) ; ) {
V_157 = F_44 ( V_158 , V_155 ) ;
if ( V_157 == '\\' ) {
V_158 += V_155 ;
V_157 = F_44 ( V_158 , V_155 ) ;
switch ( V_157 ) {
case 't' :
* V_156 = '\t' ;
break;
case 'n' :
* V_156 = '\n' ;
break;
case 'r' :
* V_156 = '\r' ;
break;
case '0' :
* V_156 = '\0' ;
break;
default:
* V_156 = V_157 ;
break;
}
} else {
* V_156 = V_157 ;
}
V_156 ++ ;
V_158 += V_155 ;
}
while ( V_156 < V_158 )
* V_156 ++ = '\0' ;
}
static char F_44 ( char * V_159 , T_1 V_160 )
{
char V_157 = '\0' ;
char * V_161 ;
T_1 V_100 ;
for ( V_161 = V_159 , V_100 = V_160 ; V_100 > 0 ; V_100 -- )
V_157 |= * V_161 ++ ;
return V_157 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
T_3 * V_44 ,
T_3 * V_49 ,
struct V_20 * V_45 ,
bool * V_46 ,
enum V_47 V_48 )
{
struct V_1 * V_13 = V_2 ;
char * V_61 = NULL ;
char * V_70 ;
char * V_162 = NULL ;
struct V_53 * V_54 = NULL ;
T_2 V_55 = 0 ;
T_2 V_56 = 0 ;
T_2 V_163 = V_164 ;
char V_71 [] = L_14 ;
char * V_72 = NULL ;
bool V_165 = ( V_45 != NULL ) ;
T_3 V_166 = 0 ;
int V_4 = 0 ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_2 ) ;
F_2 ( V_44 != NULL ) ;
F_2 ( V_21 != NULL ) ;
if ( ! V_165 ) {
* V_44 = 0 ;
* V_49 = 0 ;
}
V_162 = F_7 ( V_163 , V_15 ) ;
if ( V_162 == NULL ) {
V_4 = - V_16 ;
} else {
V_4 = F_36 ( V_2 , V_21 , V_162 ,
& V_163 , V_48 , NULL ) ;
}
if ( ! V_4 ) {
V_4 = F_27 ( V_13 -> V_12 , V_162 ,
V_63 , & V_54 ) ;
}
if ( ! V_4 ) {
V_4 = F_28 ( V_54 , V_167 , & V_55 , & V_56 ) ;
if ( V_4 ) {
V_56 = 0 ;
V_4 = 0 ;
}
}
if ( V_4 || ! ( V_56 > 0 ) )
goto V_74;
V_61 = F_7 ( V_56 + 4 , V_15 ) ;
if ( V_61 == NULL )
V_4 = - V_16 ;
V_4 = F_30 ( V_54 , V_167 , V_61 , V_56 ) ;
if ( V_4 )
goto V_74;
F_32 ( V_61 , V_56 , V_67 ) ;
V_70 = V_61 ;
while ( ( V_72 = F_35 ( & V_70 , V_71 ) ) && * V_72 != '\0' ) {
if ( V_165 ) {
if ( V_166 >= * V_44 ) {
break;
} else {
F_17 ( V_72 ,
& ( V_45
[ V_166 ] ) ) ;
V_72 = F_35 ( & V_70 , V_71 ) ;
V_46 [ V_166 ] = atoi ( V_72 ) ;
V_166 ++ ;
}
} else {
V_72 = F_35 ( & V_70 , V_71 ) ;
if ( atoi ( V_72 ) )
( * V_49 ) ++ ;
( * V_44 ) ++ ;
}
}
V_74:
if ( V_54 )
F_34 ( V_54 ) ;
F_11 ( V_162 ) ;
F_11 ( V_61 ) ;
return V_4 ;
}
