struct V_1 * F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
return V_2 ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static struct V_1 * * F_5 ( const char * V_4 , unsigned V_5 )
{
struct V_1 * * V_6 ;
for ( V_6 = & V_7 ; * V_6 ; V_6 = & ( * V_6 ) -> V_8 )
if ( strncmp ( ( * V_6 ) -> V_4 , V_4 , V_5 ) == 0 &&
! ( * V_6 ) -> V_4 [ V_5 ] )
break;
return V_6 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
struct V_1 * * V_6 ;
F_7 ( strchr ( V_2 -> V_4 , '.' ) ) ;
if ( V_2 -> V_8 )
return - V_10 ;
F_8 ( & V_11 ) ;
V_6 = F_5 ( V_2 -> V_4 , strlen ( V_2 -> V_4 ) ) ;
if ( * V_6 )
V_9 = - V_10 ;
else
* V_6 = V_2 ;
F_9 ( & V_11 ) ;
return V_9 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_1 * * V_12 ;
F_8 ( & V_11 ) ;
V_12 = & V_7 ;
while ( * V_12 ) {
if ( V_2 == * V_12 ) {
* V_12 = V_2 -> V_8 ;
V_2 -> V_8 = NULL ;
F_9 ( & V_11 ) ;
F_11 () ;
return 0 ;
}
V_12 = & ( * V_12 ) -> V_8 ;
}
F_9 ( & V_11 ) ;
return - V_13 ;
}
static int F_12 ( const char T_1 * V_14 )
{
struct V_1 * V_12 ;
struct V_15 * V_4 ;
int V_16 , V_17 ;
V_4 = F_13 ( V_14 ) ;
V_16 = F_14 ( V_4 ) ;
if ( F_15 ( V_4 ) )
return V_16 ;
V_16 = - V_13 ;
F_16 ( & V_11 ) ;
for ( V_12 = V_7 , V_17 = 0 ; V_12 ; V_12 = V_12 -> V_8 , V_17 ++ ) {
if ( strcmp ( V_12 -> V_4 , V_4 -> V_4 ) == 0 ) {
V_16 = V_17 ;
break;
}
}
F_17 ( & V_11 ) ;
F_18 ( V_4 ) ;
return V_16 ;
}
static int F_19 ( unsigned int V_17 , char T_1 * V_18 )
{
struct V_1 * V_12 ;
int V_5 , V_9 ;
F_16 ( & V_11 ) ;
for ( V_12 = V_7 ; V_12 ; V_12 = V_12 -> V_8 , V_17 -- )
if ( V_17 <= 0 && F_20 ( V_12 -> V_3 ) )
break;
F_17 ( & V_11 ) ;
if ( ! V_12 )
return - V_13 ;
V_5 = strlen ( V_12 -> V_4 ) + 1 ;
V_9 = F_21 ( V_18 , V_12 -> V_4 , V_5 ) ? - V_19 : 0 ;
F_3 ( V_12 ) ;
return V_9 ;
}
static int F_22 ( void )
{
struct V_1 * V_12 ;
int V_17 ;
F_16 ( & V_11 ) ;
for ( V_12 = V_7 , V_17 = 0 ; V_12 ; V_12 = V_12 -> V_8 , V_17 ++ )
;
F_17 ( & V_11 ) ;
return V_17 ;
}
int T_2 F_23 ( char * V_18 )
{
int V_5 = 0 ;
struct V_1 * V_12 ;
F_16 ( & V_11 ) ;
V_12 = V_7 ;
while ( V_12 && V_5 < V_20 - 80 ) {
V_5 += sprintf ( V_18 + V_5 , L_1 ,
( V_12 -> V_21 & V_22 ) ? L_2 : L_3 ,
V_12 -> V_4 ) ;
V_12 = V_12 -> V_8 ;
}
F_17 ( & V_11 ) ;
return V_5 ;
}
static int F_24 ( struct V_23 * V_24 , void * V_25 )
{
struct V_1 * V_12 ;
F_16 ( & V_11 ) ;
V_12 = V_7 ;
while ( V_12 ) {
F_25 ( V_24 , L_1 ,
( V_12 -> V_21 & V_22 ) ? L_2 : L_3 ,
V_12 -> V_4 ) ;
V_12 = V_12 -> V_8 ;
}
F_17 ( & V_11 ) ;
return 0 ;
}
static int F_26 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
return F_27 ( V_27 , F_24 , NULL ) ;
}
static int T_2 F_28 ( void )
{
F_29 ( L_4 , 0 , NULL , & V_28 ) ;
return 0 ;
}
static struct V_1 * F_30 ( const char * V_4 , int V_5 )
{
struct V_1 * V_2 ;
F_16 ( & V_11 ) ;
V_2 = * ( F_5 ( V_4 , V_5 ) ) ;
if ( V_2 && ! F_20 ( V_2 -> V_3 ) )
V_2 = NULL ;
F_17 ( & V_11 ) ;
return V_2 ;
}
struct V_1 * F_31 ( const char * V_4 )
{
struct V_1 * V_2 ;
const char * V_29 = strchr ( V_4 , '.' ) ;
int V_5 = V_29 ? V_29 - V_4 : strlen ( V_4 ) ;
V_2 = F_30 ( V_4 , V_5 ) ;
if ( ! V_2 && ( F_32 ( L_5 , V_5 , V_4 ) == 0 ) ) {
V_2 = F_30 ( V_4 , V_5 ) ;
F_33 ( ! V_2 , L_6 , V_5 , V_4 ) ;
}
if ( V_29 && V_2 && ! ( V_2 -> V_21 & V_30 ) ) {
F_3 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
