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
if ( V_12 )
fprintf ( V_12 , L_5 , V_8 ) ;
if ( V_6 )
* V_6 = V_8 ;
else
free ( V_8 ) ;
return V_7 ;
}
void F_7 ( const char * V_5 )
{
struct V_13 * V_14 ;
if ( V_15 ++ >= V_16 )
F_6 ( L_6 ) ;
V_14 = xmalloc ( sizeof( * V_14 ) ) ;
V_14 -> V_7 = F_2 ( V_5 , & V_14 -> V_17 ) ;
V_14 -> V_4 = F_1 ( V_14 -> V_17 ) ;
V_14 -> V_18 = V_10 ;
V_14 -> V_19 = 1 ;
V_14 -> V_20 = 1 ;
V_10 = V_14 ;
}
int F_8 ( void )
{
struct V_13 * V_14 = V_10 ;
assert ( V_14 ) ;
V_10 = V_14 -> V_18 ;
if ( fclose ( V_14 -> V_7 ) )
F_6 ( L_7 , V_14 -> V_17 ,
strerror ( V_11 ) ) ;
return V_10 ? 1 : 0 ;
}
void F_9 ( struct V_21 * V_22 , const char * V_23 , int V_3 )
{
int V_24 ;
V_22 -> V_25 = V_10 ;
V_22 -> V_26 = V_10 -> V_19 ;
V_22 -> V_27 = V_10 -> V_20 ;
for ( V_24 = 0 ; V_24 < V_3 ; V_24 ++ )
if ( V_23 [ V_24 ] == '\n' ) {
V_10 -> V_19 ++ ;
V_10 -> V_20 = 1 ;
} else if ( V_23 [ V_24 ] == '\t' ) {
V_10 -> V_20 =
F_10 ( V_10 -> V_20 , V_28 ) ;
} else {
V_10 -> V_20 ++ ;
}
V_22 -> V_29 = V_10 -> V_19 ;
V_22 -> V_30 = V_10 -> V_20 ;
}
struct V_21 *
F_11 ( struct V_21 * V_22 )
{
struct V_21 * V_31 ;
V_31 = xmalloc ( sizeof( struct V_21 ) ) ;
memcpy ( V_31 , V_22 , sizeof( struct V_21 ) ) ;
return V_31 ;
}
void
F_12 ( struct V_21 * V_22 )
{
printf ( L_8 ,
V_22 -> V_25 ? ( char * ) V_22 -> V_25 : L_9 ) ;
printf ( L_10 , V_22 -> V_26 ) ;
printf ( L_11 , V_22 -> V_27 ) ;
printf ( L_12 , V_22 -> V_29 ) ;
printf ( L_13 , V_22 -> V_30 ) ;
printf ( L_14 , V_22 -> V_25 -> V_17 ) ;
}
char *
F_13 ( struct V_21 * V_22 )
{
const char * V_5 = L_15 ;
char * V_32 ;
int V_33 ;
if ( V_22 )
V_5 = V_22 -> V_25 -> V_17 ;
if ( V_22 -> V_26 != V_22 -> V_29 )
V_33 = F_14 ( & V_32 , L_16 , V_5 ,
V_22 -> V_26 , V_22 -> V_27 ,
V_22 -> V_29 , V_22 -> V_30 ) ;
else if ( V_22 -> V_27 != V_22 -> V_30 )
V_33 = F_14 ( & V_32 , L_17 , V_5 ,
V_22 -> V_26 , V_22 -> V_27 ,
V_22 -> V_30 ) ;
else
V_33 = F_14 ( & V_32 , L_18 , V_5 ,
V_22 -> V_26 , V_22 -> V_27 ) ;
if ( V_33 == - 1 )
F_6 ( L_19 ) ;
return V_32 ;
}
void
F_15 ( struct V_21 * V_22 , char const * V_34 , T_2 V_35 )
{
const char * V_36 ;
V_36 = F_13 ( V_22 ) ;
fprintf ( stdout , L_20 , V_36 ) ;
vfprintf ( stdout , V_34 , V_35 ) ;
fprintf ( stdout , L_21 ) ;
}
void
F_16 ( struct V_21 * V_22 , char const * V_34 , ... )
{
T_2 V_35 ;
va_start ( V_35 , V_34 ) ;
F_15 ( V_22 , V_34 , V_35 ) ;
va_end ( V_35 ) ;
}
void
F_17 ( struct V_21 * V_22 , char const * V_34 , ... )
{
const char * V_36 ;
T_2 V_35 ;
va_start ( V_35 , V_34 ) ;
V_36 = F_13 ( V_22 ) ;
fprintf ( V_37 , L_22 , V_36 ) ;
vfprintf ( V_37 , V_34 , V_35 ) ;
fprintf ( V_37 , L_21 ) ;
va_end ( V_35 ) ;
}
