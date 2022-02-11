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
char * V_10 , * V_11 ;
struct V_12 V_13 ;
T_2 * V_14 ;
V_14 = F_3 ( V_7 ) ;
if ( V_14 == NULL ) {
if ( F_4 ( V_7 , 0755 ) ) {
perror ( L_4 ) ;
fprintf ( V_15 , L_5 ,
V_7 ) ;
return NULL ;
}
}
V_9 = strlen ( V_7 ) + 30 ;
V_10 = malloc ( sizeof( char ) * V_9 ) ;
if ( ! V_10 ) {
perror ( L_6 ) ;
goto V_16;
}
if ( F_5 ( & V_13 ) == 0 ) {
V_9 += strlen ( V_13 . V_17 ) + strlen ( V_13 . V_18 ) ;
V_11 = realloc ( V_10 , sizeof( * V_10 ) * V_9 ) ;
if ( V_11 == NULL ) {
free ( V_10 ) ;
perror ( L_7 ) ;
goto V_16;
}
V_10 = V_11 ;
snprintf ( V_10 , V_9 - 1 , L_8 ,
V_7 , V_13 . V_17 , V_13 . V_18 , time ( NULL ) ) ;
} else {
snprintf ( V_10 , V_9 - 1 , L_9 ,
V_7 , time ( NULL ) ) ;
}
F_6 ( L_10 , V_10 ) ;
V_8 = fopen ( V_10 , L_11 ) ;
if ( V_8 == NULL ) {
perror ( L_12 ) ;
fprintf ( V_15 , L_13 ) ;
goto V_19;
}
fprintf ( stdout , L_14 , V_10 ) ;
fprintf ( V_8 , L_15 ) ;
V_19:
free ( V_10 ) ;
V_16:
F_7 ( V_14 ) ;
return V_8 ;
}
struct V_20 * F_8 ()
{
struct V_20 * V_20 = malloc ( sizeof( struct V_20 ) ) ;
F_6 ( L_16 ) ;
V_20 -> V_21 = 500000 ;
V_20 -> V_22 = 500000 ;
V_20 -> V_23 = 500000 ;
V_20 -> V_24 = 500000 ;
V_20 -> V_25 = 5 ;
V_20 -> V_26 = 50 ;
V_20 -> V_27 = 0 ;
V_20 -> V_28 = V_3 ;
V_20 -> V_29 = 0 ;
strncpy ( V_20 -> V_30 , L_17 , 8 ) ;
V_20 -> V_8 = stdout ;
#ifdef F_9
if ( F_10 ( F_9 , V_20 ) )
return NULL ;
#endif
return V_20 ;
}
int F_10 ( const char * V_31 , struct V_20 * V_20 )
{
T_3 V_9 = 0 ;
char V_32 [ 16 ] , V_33 [ 32 ] , * line = NULL ;
T_1 * V_34 ;
if ( V_20 == NULL ) {
fprintf ( V_15 , L_18 ) ;
return 1 ;
}
V_34 = fopen ( V_31 , L_19 ) ;
if ( V_34 == NULL ) {
perror ( L_12 ) ;
fprintf ( V_15 , L_20 ) ;
free ( V_20 ) ;
return 1 ;
}
while ( F_11 ( & line , & V_9 , V_34 ) != - 1 ) {
if ( line [ 0 ] == '#' || line [ 0 ] == ' ' || line [ 0 ] == '\n' )
continue;
if ( sscanf ( line , L_21 , V_32 , V_33 ) < 2 )
continue;
F_6 ( L_22 , V_32 , V_33 ) ;
if ( strcmp ( L_23 , V_32 ) == 0 )
sscanf ( V_33 , L_24 , & V_20 -> V_21 ) ;
else if ( strcmp ( L_25 , V_32 ) == 0 )
sscanf ( V_33 , L_24 , & V_20 -> V_22 ) ;
else if ( strcmp ( L_26 , V_32 ) == 0 )
sscanf ( V_33 , L_24 , & V_20 -> V_24 ) ;
else if ( strcmp ( L_27 , V_32 ) == 0 )
sscanf ( V_33 , L_24 , & V_20 -> V_23 ) ;
else if ( strcmp ( L_28 , V_32 ) == 0 )
sscanf ( V_33 , L_29 , & V_20 -> V_25 ) ;
else if ( strcmp ( L_30 , V_32 ) == 0 )
sscanf ( V_33 , L_29 , & V_20 -> V_26 ) ;
else if ( strcmp ( L_31 , V_32 ) == 0 )
sscanf ( V_33 , L_29 , & V_20 -> V_29 ) ;
else if ( strcmp ( L_32 , V_32 ) == 0 )
V_20 -> V_8 = F_2 ( V_33 ) ;
else if ( strcmp ( L_33 , V_32 ) == 0 )
sscanf ( V_33 , L_29 , & V_20 -> V_27 ) ;
else if ( strcmp ( L_34 , V_32 ) == 0 ) {
strncpy ( V_20 -> V_30 , V_33 ,
sizeof( V_20 -> V_30 ) ) ;
V_20 -> V_30 [ sizeof( V_20 -> V_30 ) - 1 ] = '\0' ;
}
else if ( strcmp ( L_35 , V_32 ) == 0 ) {
if ( F_1 ( V_33 ) != V_6 )
V_20 -> V_28 = F_1 ( V_33 ) ;
}
}
free ( line ) ;
return 0 ;
}
