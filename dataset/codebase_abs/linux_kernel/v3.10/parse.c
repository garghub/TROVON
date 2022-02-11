enum V_1 F_1 ( const char * V_2 )
{
if ( strncasecmp ( L_1 , V_2 , strlen ( V_2 ) ) == 0 )
return V_3 ;
else if ( strncasecmp ( L_2 , V_2 , strlen ( V_2 ) ) == 0 )
return V_4 ;
else if ( strncasecmp ( L_3 , V_2 , strlen ( V_2 ) ) == 0 )
return V_5 ;
else
return V_6 ;
}
T_1 * F_2 ( const char * V_7 )
{
T_1 * V_8 = NULL ;
int V_9 ;
char * V_10 ;
struct V_11 V_12 ;
T_2 * V_13 ;
V_13 = F_3 ( V_7 ) ;
if ( V_13 == NULL ) {
if ( F_4 ( V_7 , 0755 ) ) {
perror ( L_4 ) ;
fprintf ( V_14 , L_5 ,
V_7 ) ;
return NULL ;
}
}
V_9 = strlen ( V_7 ) + 30 ;
V_10 = malloc ( sizeof( char ) * V_9 ) ;
if ( F_5 ( & V_12 ) == 0 ) {
V_9 += strlen ( V_12 . V_15 ) + strlen ( V_12 . V_16 ) ;
V_10 = realloc ( V_10 , sizeof( char ) * V_9 ) ;
if ( V_10 == NULL ) {
perror ( L_6 ) ;
return NULL ;
}
snprintf ( V_10 , V_9 - 1 , L_7 ,
V_7 , V_12 . V_15 , V_12 . V_16 , time ( NULL ) ) ;
} else {
snprintf ( V_10 , V_9 - 1 , L_8 ,
V_7 , time ( NULL ) ) ;
}
F_6 ( L_9 , V_10 ) ;
V_8 = fopen ( V_10 , L_10 ) ;
if ( V_8 == NULL ) {
perror ( L_11 ) ;
fprintf ( V_14 , L_12 ) ;
}
fprintf ( stdout , L_13 , V_10 ) ;
free ( V_10 ) ;
fprintf ( V_8 , L_14 ) ;
return V_8 ;
}
struct V_17 * F_7 ()
{
struct V_17 * V_17 = malloc ( sizeof( struct V_17 ) ) ;
F_6 ( L_15 ) ;
V_17 -> V_18 = 500000 ;
V_17 -> V_19 = 500000 ;
V_17 -> V_20 = 500000 ;
V_17 -> V_21 = 500000 ;
V_17 -> V_22 = 5 ;
V_17 -> V_23 = 50 ;
V_17 -> V_24 = 0 ;
V_17 -> V_25 = V_3 ;
V_17 -> V_26 = 0 ;
strncpy ( V_17 -> V_27 , L_16 , 8 ) ;
V_17 -> V_8 = stdout ;
#ifdef F_8
if ( F_9 ( F_8 , V_17 ) )
return NULL ;
#endif
return V_17 ;
}
int F_9 ( const char * V_28 , struct V_17 * V_17 )
{
T_3 V_9 = 0 ;
char * V_29 , * V_30 , * line = NULL ;
T_1 * V_31 = fopen ( V_28 , L_17 ) ;
if ( V_17 == NULL ) {
fprintf ( V_14 , L_18 ) ;
return 1 ;
}
if ( V_31 == NULL ) {
perror ( L_11 ) ;
fprintf ( V_14 , L_19 ) ;
free ( V_17 ) ;
return 1 ;
}
while ( F_10 ( & line , & V_9 , V_31 ) != - 1 ) {
if ( line [ 0 ] == '#' || line [ 0 ] == ' ' )
continue;
sscanf ( line , L_20 , & V_29 , & V_30 ) ;
F_6 ( L_21 , V_29 , V_30 ) ;
if ( strncmp ( L_22 , V_29 , strlen ( V_29 ) ) == 0 )
sscanf ( V_30 , L_23 , & V_17 -> V_18 ) ;
else if ( strncmp ( L_24 , V_29 , strlen ( V_29 ) ) == 0 )
sscanf ( V_30 , L_23 , & V_17 -> V_19 ) ;
else if ( strncmp ( L_25 , V_29 , strlen ( V_29 ) ) == 0 )
sscanf ( V_30 , L_23 , & V_17 -> V_21 ) ;
else if ( strncmp ( L_26 , V_29 , strlen ( V_29 ) ) == 0 )
sscanf ( V_30 , L_23 , & V_17 -> V_20 ) ;
else if ( strncmp ( L_27 , V_29 , strlen ( V_29 ) ) == 0 )
sscanf ( V_30 , L_28 , & V_17 -> V_22 ) ;
else if ( strncmp ( L_29 , V_29 , strlen ( V_29 ) ) == 0 )
sscanf ( V_30 , L_28 , & V_17 -> V_23 ) ;
else if ( strncmp ( L_30 , V_29 , strlen ( V_29 ) ) == 0 )
sscanf ( V_30 , L_28 , & V_17 -> V_26 ) ;
else if ( strncmp ( L_31 , V_29 , strlen ( V_29 ) ) == 0 )
V_17 -> V_8 = F_2 ( V_30 ) ;
else if ( strncmp ( L_32 , V_29 , strlen ( V_29 ) ) == 0 )
sscanf ( V_30 , L_28 , & V_17 -> V_24 ) ;
else if ( strncmp ( L_33 , V_29 , 14 ) == 0 )
strncpy ( V_17 -> V_27 , V_30 , 14 ) ;
else if ( strncmp ( L_34 , V_29 , strlen ( V_29 ) ) == 0 ) {
if ( F_1 ( V_30 ) != V_6 )
V_17 -> V_25 = F_1 ( V_30 ) ;
}
}
free ( line ) ;
free ( V_29 ) ;
free ( V_30 ) ;
return 0 ;
}
