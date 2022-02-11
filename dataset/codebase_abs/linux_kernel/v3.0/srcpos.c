static char * F_1 ( const char * V_1 )
{
const char * V_2 = strrchr ( V_1 , '/' ) ;
if ( V_2 ) {
int V_3 = V_2 - V_1 ;
char * V_4 = xmalloc ( V_3 + 1 ) ;
memcpy ( V_4 , V_1 , V_3 ) ;
V_4 [ V_3 ] = '\0' ;
return V_4 ;
}
return NULL ;
}
T_1 * F_2 ( const char * V_5 , char * * V_6 )
{
T_1 * V_7 ;
char * V_8 ;
if ( F_3 ( V_5 , L_1 ) ) {
V_7 = V_9 ;
V_8 = F_4 ( L_2 ) ;
} else {
if ( ! V_10 || ! V_10 -> V_4
|| ( V_5 [ 0 ] == '/' ) )
V_8 = F_4 ( V_5 ) ;
else
V_8 = F_5 ( V_10 -> V_4 , V_5 ) ;
V_7 = fopen ( V_8 , L_3 ) ;
if ( ! V_7 )
F_6 ( L_4 , V_5 ,
strerror ( V_11 ) ) ;
}
if ( V_6 )
* V_6 = V_8 ;
else
free ( V_8 ) ;
return V_7 ;
}
void F_7 ( const char * V_5 )
{
struct V_12 * V_13 ;
if ( V_14 ++ >= V_15 )
F_6 ( L_5 ) ;
V_13 = xmalloc ( sizeof( * V_13 ) ) ;
V_13 -> V_7 = F_2 ( V_5 , & V_13 -> V_16 ) ;
V_13 -> V_4 = F_1 ( V_13 -> V_16 ) ;
V_13 -> V_17 = V_10 ;
V_13 -> V_18 = 1 ;
V_13 -> V_19 = 1 ;
V_10 = V_13 ;
}
int F_8 ( void )
{
struct V_12 * V_13 = V_10 ;
assert ( V_13 ) ;
V_10 = V_13 -> V_17 ;
if ( fclose ( V_13 -> V_7 ) )
F_6 ( L_6 , V_13 -> V_16 ,
strerror ( V_11 ) ) ;
return V_10 ? 1 : 0 ;
}
void F_9 ( struct V_20 * V_21 , const char * V_22 , int V_3 )
{
int V_23 ;
V_21 -> V_24 = V_10 ;
V_21 -> V_25 = V_10 -> V_18 ;
V_21 -> V_26 = V_10 -> V_19 ;
for ( V_23 = 0 ; V_23 < V_3 ; V_23 ++ )
if ( V_22 [ V_23 ] == '\n' ) {
V_10 -> V_18 ++ ;
V_10 -> V_19 = 1 ;
} else if ( V_22 [ V_23 ] == '\t' ) {
V_10 -> V_19 =
F_10 ( V_10 -> V_19 , V_27 ) ;
} else {
V_10 -> V_19 ++ ;
}
V_21 -> V_28 = V_10 -> V_18 ;
V_21 -> V_29 = V_10 -> V_19 ;
}
struct V_20 *
F_11 ( struct V_20 * V_21 )
{
struct V_20 * V_30 ;
V_30 = xmalloc ( sizeof( struct V_20 ) ) ;
memcpy ( V_30 , V_21 , sizeof( struct V_20 ) ) ;
return V_30 ;
}
void
F_12 ( struct V_20 * V_21 )
{
printf ( L_7 ,
V_21 -> V_24 ? ( char * ) V_21 -> V_24 : L_8 ) ;
printf ( L_9 , V_21 -> V_25 ) ;
printf ( L_10 , V_21 -> V_26 ) ;
printf ( L_11 , V_21 -> V_28 ) ;
printf ( L_12 , V_21 -> V_29 ) ;
printf ( L_13 , V_21 -> V_24 -> V_16 ) ;
}
char *
F_13 ( struct V_20 * V_21 )
{
const char * V_5 = L_14 ;
char * V_31 ;
int V_32 ;
if ( V_21 )
V_5 = V_21 -> V_24 -> V_16 ;
if ( V_21 -> V_25 != V_21 -> V_28 )
V_32 = F_14 ( & V_31 , L_15 , V_5 ,
V_21 -> V_25 , V_21 -> V_26 ,
V_21 -> V_28 , V_21 -> V_29 ) ;
else if ( V_21 -> V_26 != V_21 -> V_29 )
V_32 = F_14 ( & V_31 , L_16 , V_5 ,
V_21 -> V_25 , V_21 -> V_26 ,
V_21 -> V_29 ) ;
else
V_32 = F_14 ( & V_31 , L_17 , V_5 ,
V_21 -> V_25 , V_21 -> V_26 ) ;
if ( V_32 == - 1 )
F_6 ( L_18 ) ;
return V_31 ;
}
void
F_15 ( struct V_20 * V_21 , char const * V_33 , T_2 V_34 )
{
const char * V_35 ;
V_35 = F_13 ( V_21 ) ;
fprintf ( stdout , L_19 , V_35 ) ;
vfprintf ( stdout , V_33 , V_34 ) ;
fprintf ( stdout , L_20 ) ;
}
void
F_16 ( struct V_20 * V_21 , char const * V_33 , ... )
{
T_2 V_34 ;
va_start ( V_34 , V_33 ) ;
F_15 ( V_21 , V_33 , V_34 ) ;
va_end ( V_34 ) ;
}
void
F_17 ( struct V_20 * V_21 , char const * V_33 , ... )
{
const char * V_35 ;
T_2 V_34 ;
va_start ( V_34 , V_33 ) ;
V_35 = F_13 ( V_21 ) ;
fprintf ( V_36 , L_21 , V_35 ) ;
vfprintf ( V_36 , V_33 , V_34 ) ;
fprintf ( V_36 , L_20 ) ;
va_end ( V_34 ) ;
}
