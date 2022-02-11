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
static char * F_2 ( const char * V_5 , const char * V_6 , T_1 * * V_7 )
{
char * V_8 ;
if ( ! V_5 || V_6 [ 0 ] == '/' )
V_8 = F_3 ( V_6 ) ;
else
V_8 = F_4 ( V_5 , V_6 ) ;
* V_7 = fopen ( V_8 , L_1 ) ;
if ( ! * V_7 ) {
free ( V_8 ) ;
V_8 = NULL ;
}
return V_8 ;
}
static char * F_5 ( const char * V_6 , T_1 * * V_7 )
{
const char * V_9 = NULL ;
struct V_10 * V_11 ;
char * V_8 ;
assert ( V_7 ) ;
if ( V_12 )
V_9 = V_12 -> V_4 ;
V_8 = F_2 ( V_9 , V_6 , V_7 ) ;
for ( V_11 = V_13 ; ! * V_7 && V_11 ; V_11 = V_11 -> V_14 )
V_8 = F_2 ( V_11 -> V_5 , V_6 , V_7 ) ;
return V_8 ;
}
T_1 * F_6 ( const char * V_6 , char * * V_15 )
{
T_1 * V_16 ;
char * V_8 ;
if ( F_7 ( V_6 , L_2 ) ) {
V_16 = V_17 ;
V_8 = F_3 ( L_3 ) ;
} else {
V_8 = F_5 ( V_6 , & V_16 ) ;
if ( ! V_16 )
F_8 ( L_4 , V_6 ,
strerror ( V_18 ) ) ;
}
if ( V_19 )
fprintf ( V_19 , L_5 , V_8 ) ;
if ( V_15 )
* V_15 = V_8 ;
else
free ( V_8 ) ;
return V_16 ;
}
void F_9 ( const char * V_6 )
{
struct V_20 * V_21 ;
if ( V_22 ++ >= V_23 )
F_8 ( L_6 ) ;
V_21 = xmalloc ( sizeof( * V_21 ) ) ;
V_21 -> V_16 = F_6 ( V_6 , & V_21 -> V_24 ) ;
V_21 -> V_4 = F_1 ( V_21 -> V_24 ) ;
V_21 -> V_25 = V_12 ;
V_21 -> V_26 = 1 ;
V_21 -> V_27 = 1 ;
V_12 = V_21 ;
}
bool F_10 ( void )
{
struct V_20 * V_21 = V_12 ;
assert ( V_21 ) ;
V_12 = V_21 -> V_25 ;
if ( fclose ( V_21 -> V_16 ) )
F_8 ( L_7 , V_21 -> V_24 ,
strerror ( V_18 ) ) ;
return V_12 ? true : false ;
}
void F_11 ( const char * V_5 )
{
struct V_10 * V_11 ;
V_11 = xmalloc ( sizeof( * V_11 ) ) ;
V_11 -> V_14 = NULL ;
V_11 -> V_5 = F_3 ( V_5 ) ;
if ( V_28 )
* V_28 = V_11 ;
else
V_13 = V_11 ;
V_28 = & V_11 -> V_14 ;
}
void F_12 ( struct V_29 * V_30 , const char * V_31 , int V_3 )
{
int V_32 ;
V_30 -> V_33 = V_12 ;
V_30 -> V_34 = V_12 -> V_26 ;
V_30 -> V_35 = V_12 -> V_27 ;
for ( V_32 = 0 ; V_32 < V_3 ; V_32 ++ )
if ( V_31 [ V_32 ] == '\n' ) {
V_12 -> V_26 ++ ;
V_12 -> V_27 = 1 ;
} else if ( V_31 [ V_32 ] == '\t' ) {
V_12 -> V_27 =
F_13 ( V_12 -> V_27 , V_36 ) ;
} else {
V_12 -> V_27 ++ ;
}
V_30 -> V_37 = V_12 -> V_26 ;
V_30 -> V_38 = V_12 -> V_27 ;
}
struct V_29 *
F_14 ( struct V_29 * V_30 )
{
struct V_29 * V_39 ;
V_39 = xmalloc ( sizeof( struct V_29 ) ) ;
memcpy ( V_39 , V_30 , sizeof( struct V_29 ) ) ;
return V_39 ;
}
char *
F_15 ( struct V_29 * V_30 )
{
const char * V_6 = L_8 ;
char * V_40 ;
if ( V_30 )
V_6 = V_30 -> V_33 -> V_24 ;
if ( V_30 -> V_34 != V_30 -> V_37 )
F_16 ( & V_40 , L_9 , V_6 ,
V_30 -> V_34 , V_30 -> V_35 ,
V_30 -> V_37 , V_30 -> V_38 ) ;
else if ( V_30 -> V_35 != V_30 -> V_38 )
F_16 ( & V_40 , L_10 , V_6 ,
V_30 -> V_34 , V_30 -> V_35 ,
V_30 -> V_38 ) ;
else
F_16 ( & V_40 , L_11 , V_6 ,
V_30 -> V_34 , V_30 -> V_35 ) ;
return V_40 ;
}
void F_17 ( struct V_29 * V_30 , const char * V_41 ,
const char * V_42 , T_2 V_43 )
{
char * V_44 ;
V_44 = F_15 ( V_30 ) ;
fprintf ( V_45 , L_12 , V_41 , V_44 ) ;
vfprintf ( V_45 , V_42 , V_43 ) ;
fprintf ( V_45 , L_13 ) ;
free ( V_44 ) ;
}
void F_18 ( struct V_29 * V_30 , const char * V_41 ,
const char * V_42 , ... )
{
T_2 V_43 ;
va_start ( V_43 , V_42 ) ;
F_17 ( V_30 , V_41 , V_42 , V_43 ) ;
va_end ( V_43 ) ;
}
void F_19 ( char * V_16 , int V_46 )
{
V_12 -> V_24 = V_16 ;
V_12 -> V_26 = V_46 ;
}
