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
static char * F_2 ( const char * F_1 , const char * V_5 , T_1 * * V_6 )
{
char * V_7 ;
if ( ! F_1 || V_5 [ 0 ] == '/' )
V_7 = F_3 ( V_5 ) ;
else
V_7 = F_4 ( F_1 , V_5 ) ;
* V_6 = fopen ( V_7 , L_1 ) ;
if ( ! * V_6 ) {
free ( V_7 ) ;
V_7 = NULL ;
}
return V_7 ;
}
static char * F_5 ( const char * V_5 , T_1 * * V_6 )
{
const char * V_8 = NULL ;
struct V_9 * V_10 ;
char * V_7 ;
assert ( V_6 ) ;
if ( V_11 )
V_8 = V_11 -> V_4 ;
V_7 = F_2 ( V_8 , V_5 , V_6 ) ;
for ( V_10 = V_12 ; ! * V_6 && V_10 ; V_10 = V_10 -> V_13 )
V_7 = F_2 ( V_10 -> F_1 , V_5 , V_6 ) ;
return V_7 ;
}
T_1 * F_6 ( const char * V_5 , char * * V_14 )
{
T_1 * V_15 ;
char * V_7 ;
if ( F_7 ( V_5 , L_2 ) ) {
V_15 = V_16 ;
V_7 = F_3 ( L_3 ) ;
} else {
V_7 = F_5 ( V_5 , & V_15 ) ;
if ( ! V_15 )
F_8 ( L_4 , V_5 ,
strerror ( V_17 ) ) ;
}
if ( V_18 )
fprintf ( V_18 , L_5 , V_7 ) ;
if ( V_14 )
* V_14 = V_7 ;
else
free ( V_7 ) ;
return V_15 ;
}
void F_9 ( const char * V_5 )
{
struct V_19 * V_20 ;
if ( V_21 ++ >= V_22 )
F_8 ( L_6 ) ;
V_20 = xmalloc ( sizeof( * V_20 ) ) ;
V_20 -> V_15 = F_6 ( V_5 , & V_20 -> V_23 ) ;
V_20 -> V_4 = F_1 ( V_20 -> V_23 ) ;
V_20 -> V_24 = V_11 ;
V_20 -> V_25 = 1 ;
V_20 -> V_26 = 1 ;
V_11 = V_20 ;
}
int F_10 ( void )
{
struct V_19 * V_20 = V_11 ;
assert ( V_20 ) ;
V_11 = V_20 -> V_24 ;
if ( fclose ( V_20 -> V_15 ) )
F_8 ( L_7 , V_20 -> V_23 ,
strerror ( V_17 ) ) ;
return V_11 ? 1 : 0 ;
}
void F_11 ( const char * F_1 )
{
struct V_9 * V_10 ;
V_10 = xmalloc ( sizeof( * V_10 ) ) ;
V_10 -> V_13 = NULL ;
V_10 -> F_1 = F_3 ( F_1 ) ;
if ( V_27 )
* V_27 = V_10 ;
else
V_12 = V_10 ;
V_27 = & V_10 -> V_13 ;
}
void F_12 ( struct V_28 * V_29 , const char * V_30 , int V_3 )
{
int V_31 ;
V_29 -> V_32 = V_11 ;
V_29 -> V_33 = V_11 -> V_25 ;
V_29 -> V_34 = V_11 -> V_26 ;
for ( V_31 = 0 ; V_31 < V_3 ; V_31 ++ )
if ( V_30 [ V_31 ] == '\n' ) {
V_11 -> V_25 ++ ;
V_11 -> V_26 = 1 ;
} else if ( V_30 [ V_31 ] == '\t' ) {
V_11 -> V_26 =
F_13 ( V_11 -> V_26 , V_35 ) ;
} else {
V_11 -> V_26 ++ ;
}
V_29 -> V_36 = V_11 -> V_25 ;
V_29 -> V_37 = V_11 -> V_26 ;
}
struct V_28 *
F_14 ( struct V_28 * V_29 )
{
struct V_28 * V_38 ;
V_38 = xmalloc ( sizeof( struct V_28 ) ) ;
memcpy ( V_38 , V_29 , sizeof( struct V_28 ) ) ;
return V_38 ;
}
void
F_15 ( struct V_28 * V_29 )
{
printf ( L_8 ,
V_29 -> V_32 ? ( char * ) V_29 -> V_32 : L_9 ) ;
printf ( L_10 , V_29 -> V_33 ) ;
printf ( L_11 , V_29 -> V_34 ) ;
printf ( L_12 , V_29 -> V_36 ) ;
printf ( L_13 , V_29 -> V_37 ) ;
printf ( L_14 , V_29 -> V_32 -> V_23 ) ;
}
char *
F_16 ( struct V_28 * V_29 )
{
const char * V_5 = L_15 ;
char * V_39 ;
int V_40 ;
if ( V_29 )
V_5 = V_29 -> V_32 -> V_23 ;
if ( V_29 -> V_33 != V_29 -> V_36 )
V_40 = F_17 ( & V_39 , L_16 , V_5 ,
V_29 -> V_33 , V_29 -> V_34 ,
V_29 -> V_36 , V_29 -> V_37 ) ;
else if ( V_29 -> V_34 != V_29 -> V_37 )
V_40 = F_17 ( & V_39 , L_17 , V_5 ,
V_29 -> V_33 , V_29 -> V_34 ,
V_29 -> V_37 ) ;
else
V_40 = F_17 ( & V_39 , L_18 , V_5 ,
V_29 -> V_33 , V_29 -> V_34 ) ;
if ( V_40 == - 1 )
F_8 ( L_19 ) ;
return V_39 ;
}
void
F_18 ( struct V_28 * V_29 , char const * V_41 , T_2 V_42 )
{
const char * V_43 ;
V_43 = F_16 ( V_29 ) ;
fprintf ( stdout , L_20 , V_43 ) ;
vfprintf ( stdout , V_41 , V_42 ) ;
fprintf ( stdout , L_21 ) ;
}
void
F_19 ( struct V_28 * V_29 , char const * V_41 , ... )
{
T_2 V_42 ;
va_start ( V_42 , V_41 ) ;
F_18 ( V_29 , V_41 , V_42 ) ;
va_end ( V_42 ) ;
}
void
F_20 ( struct V_28 * V_29 , char const * V_41 , ... )
{
const char * V_43 ;
T_2 V_42 ;
va_start ( V_42 , V_41 ) ;
V_43 = F_16 ( V_29 ) ;
fprintf ( V_44 , L_22 , V_43 ) ;
vfprintf ( V_44 , V_41 , V_42 ) ;
fprintf ( V_44 , L_21 ) ;
va_end ( V_42 ) ;
}
void F_21 ( char * V_15 , int V_45 )
{
V_11 -> V_23 = V_15 ;
V_11 -> V_25 = V_45 ;
}
