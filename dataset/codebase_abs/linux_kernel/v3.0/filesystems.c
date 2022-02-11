void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static struct V_1 * * F_5 ( const char * V_4 , unsigned V_5 )
{
struct V_1 * * V_6 ;
for ( V_6 = & V_7 ; * V_6 ; V_6 = & ( * V_6 ) -> V_8 )
if ( strlen ( ( * V_6 ) -> V_4 ) == V_5 &&
strncmp ( ( * V_6 ) -> V_4 , V_4 , V_5 ) == 0 )
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
F_8 ( & V_2 -> V_11 ) ;
F_9 ( & V_12 ) ;
V_6 = F_5 ( V_2 -> V_4 , strlen ( V_2 -> V_4 ) ) ;
if ( * V_6 )
V_9 = - V_10 ;
else
* V_6 = V_2 ;
F_10 ( & V_12 ) ;
return V_9 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_1 * * V_13 ;
F_9 ( & V_12 ) ;
V_13 = & V_7 ;
while ( * V_13 ) {
if ( V_2 == * V_13 ) {
* V_13 = V_2 -> V_8 ;
V_2 -> V_8 = NULL ;
F_10 ( & V_12 ) ;
F_12 () ;
return 0 ;
}
V_13 = & ( * V_13 ) -> V_8 ;
}
F_10 ( & V_12 ) ;
return - V_14 ;
}
static int F_13 ( const char T_1 * V_15 )
{
struct V_1 * V_13 ;
char * V_4 ;
int V_16 , V_17 ;
V_4 = F_14 ( V_15 ) ;
V_16 = F_15 ( V_4 ) ;
if ( F_16 ( V_4 ) )
return V_16 ;
V_16 = - V_14 ;
F_17 ( & V_12 ) ;
for ( V_13 = V_7 , V_17 = 0 ; V_13 ; V_13 = V_13 -> V_8 , V_17 ++ ) {
if ( strcmp ( V_13 -> V_4 , V_4 ) == 0 ) {
V_16 = V_17 ;
break;
}
}
F_18 ( & V_12 ) ;
F_19 ( V_4 ) ;
return V_16 ;
}
static int F_20 ( unsigned int V_17 , char T_1 * V_18 )
{
struct V_1 * V_13 ;
int V_5 , V_9 ;
F_17 ( & V_12 ) ;
for ( V_13 = V_7 ; V_13 ; V_13 = V_13 -> V_8 , V_17 -- )
if ( V_17 <= 0 && F_21 ( V_13 -> V_3 ) )
break;
F_18 ( & V_12 ) ;
if ( ! V_13 )
return - V_14 ;
V_5 = strlen ( V_13 -> V_4 ) + 1 ;
V_9 = F_22 ( V_18 , V_13 -> V_4 , V_5 ) ? - V_19 : 0 ;
F_3 ( V_13 ) ;
return V_9 ;
}
static int F_23 ( void )
{
struct V_1 * V_13 ;
int V_17 ;
F_17 ( & V_12 ) ;
for ( V_13 = V_7 , V_17 = 0 ; V_13 ; V_13 = V_13 -> V_8 , V_17 ++ )
;
F_18 ( & V_12 ) ;
return V_17 ;
}
int T_2 F_24 ( char * V_18 )
{
int V_5 = 0 ;
struct V_1 * V_13 ;
F_17 ( & V_12 ) ;
V_13 = V_7 ;
while ( V_13 && V_5 < V_20 - 80 ) {
V_5 += sprintf ( V_18 + V_5 , L_1 ,
( V_13 -> V_21 & V_22 ) ? L_2 : L_3 ,
V_13 -> V_4 ) ;
V_13 = V_13 -> V_8 ;
}
F_18 ( & V_12 ) ;
return V_5 ;
}
static int F_25 ( struct V_23 * V_24 , void * V_25 )
{
struct V_1 * V_13 ;
F_17 ( & V_12 ) ;
V_13 = V_7 ;
while ( V_13 ) {
F_26 ( V_24 , L_1 ,
( V_13 -> V_21 & V_22 ) ? L_2 : L_3 ,
V_13 -> V_4 ) ;
V_13 = V_13 -> V_8 ;
}
F_18 ( & V_12 ) ;
return 0 ;
}
static int F_27 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
return F_28 ( V_27 , F_25 , NULL ) ;
}
static int T_2 F_29 ( void )
{
F_30 ( L_4 , 0 , NULL , & V_28 ) ;
return 0 ;
}
static struct V_1 * F_31 ( const char * V_4 , int V_5 )
{
struct V_1 * V_2 ;
F_17 ( & V_12 ) ;
V_2 = * ( F_5 ( V_4 , V_5 ) ) ;
if ( V_2 && ! F_21 ( V_2 -> V_3 ) )
V_2 = NULL ;
F_18 ( & V_12 ) ;
return V_2 ;
}
struct V_1 * F_32 ( const char * V_4 )
{
struct V_1 * V_2 ;
const char * V_29 = strchr ( V_4 , '.' ) ;
int V_5 = V_29 ? V_29 - V_4 : strlen ( V_4 ) ;
V_2 = F_31 ( V_4 , V_5 ) ;
if ( ! V_2 && ( F_33 ( L_5 , V_5 , V_4 ) == 0 ) )
V_2 = F_31 ( V_4 , V_5 ) ;
if ( V_29 && V_2 && ! ( V_2 -> V_21 & V_30 ) ) {
F_3 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
