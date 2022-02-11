const char * F_1 ( const char * V_1 )
{
static const char * V_2 = V_3 ;
struct V_4 V_5 = V_6 ;
if ( F_2 ( V_1 ) )
return V_1 ;
F_3 ( & V_5 , L_1 , V_2 , V_1 ) ;
V_1 = F_4 ( & V_5 , NULL ) ;
return V_1 ;
}
const char * F_5 ( const char * V_7 )
{
const char * V_8 ;
if ( ! V_7 || ! * V_7 )
return NULL ;
V_8 = V_7 + strlen ( V_7 ) ;
while ( V_7 <= V_8 && ! F_6 ( * V_8 ) )
V_8 -- ;
if ( V_8 >= V_7 ) {
V_9 = F_7 ( V_7 , V_8 - V_7 ) ;
return V_9 ? V_8 + 1 : NULL ;
}
return V_7 ;
}
void F_8 ( const char * V_10 )
{
V_11 = V_10 ;
F_9 ( V_12 , V_10 , 1 ) ;
}
const char * F_10 ( void )
{
const char * V_13 ;
if ( V_11 )
return V_11 ;
V_13 = getenv ( V_12 ) ;
if ( V_13 && * V_13 ) {
return V_13 ;
}
return F_1 ( V_14 ) ;
}
static void F_11 ( struct V_4 * V_15 , const char * V_1 )
{
if ( V_1 && * V_1 ) {
if ( F_2 ( V_1 ) )
F_12 ( V_15 , V_1 ) ;
else
F_12 ( V_15 , F_13 ( V_1 ) ) ;
F_14 ( V_15 , V_16 ) ;
}
}
void F_15 ( void )
{
const char * V_17 = getenv ( L_2 ) ;
struct V_4 V_18 = V_6 ;
F_11 ( & V_18 , F_10 () ) ;
F_11 ( & V_18 , V_9 ) ;
if ( V_17 )
F_12 ( & V_18 , V_17 ) ;
else
F_12 ( & V_18 , L_3 ) ;
F_9 ( L_2 , V_18 . V_19 , 1 ) ;
F_16 ( & V_18 ) ;
}
static const char * * F_17 ( const char * * V_20 )
{
int V_21 ;
const char * * V_22 ;
for ( V_21 = 0 ; V_20 [ V_21 ] ; V_21 ++ )
;
V_22 = malloc ( sizeof( * V_22 ) * ( V_21 + 2 ) ) ;
V_22 [ 0 ] = L_4 ;
for ( V_21 = 0 ; V_20 [ V_21 ] ; V_21 ++ )
V_22 [ V_21 + 1 ] = V_20 [ V_21 ] ;
V_22 [ V_21 + 1 ] = NULL ;
return V_22 ;
}
int F_18 ( const char * * V_20 ) {
const char * * V_22 = F_17 ( V_20 ) ;
F_19 ( L_4 , ( char * * ) V_22 ) ;
free ( V_22 ) ;
return - 1 ;
}
int F_20 ( const char * V_23 , ... )
{
int V_21 ;
const char * V_20 [ V_24 + 1 ] ;
const char * V_25 ;
T_1 V_26 ;
va_start ( V_26 , V_23 ) ;
V_20 [ 0 ] = V_23 ;
V_21 = 1 ;
while ( V_21 < V_24 ) {
V_25 = V_20 [ V_21 ++ ] = va_arg ( V_26 , char * ) ;
if ( ! V_25 )
break;
}
va_end ( V_26 ) ;
if ( V_24 <= V_21 )
return error ( L_5 , V_23 ) ;
V_20 [ V_21 ] = NULL ;
return F_18 ( V_20 ) ;
}
