static int F_1 ( const char * V_1 , char * V_2 , int V_3 )
{
int V_4 ;
if ( ! V_1 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_3 - 1 && V_1 [ V_4 ] && V_1 [ V_4 ] != '\n' ; V_4 ++ )
V_2 [ V_4 ] = V_1 [ V_4 ] ;
V_2 [ V_4 ] = 0 ;
if ( V_4 == 0 || ( V_1 [ V_4 ] != 0 && V_1 [ V_4 ] != '\n' ) )
return 0 ;
return V_4 ;
}
static void F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
bool V_9 = F_4 ( V_6 ) && F_5 ( V_6 ) ;
if ( ! V_8 )
goto V_10;
if ( V_9 )
F_6 ( V_8 ) ;
else
F_7 ( V_8 ) ;
V_10:
return;
}
static int F_8 ( const char * V_1 , const struct V_11 * V_12 )
{
int V_4 ;
int V_13 = 0 ;
char V_2 [ 32 ] ;
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 ;
V_4 = F_1 ( V_1 , V_2 , sizeof( V_2 ) ) ;
if ( ! V_4 ) {
F_9 ( L_1 ) ;
V_13 = - V_14 ;
goto V_13;
}
V_6 = F_10 ( & V_15 , V_2 ) ;
if ( ! V_6 ) {
F_9 ( L_2 , V_2 ) ;
V_13 = - V_14 ;
goto V_13;
}
if ( F_3 ( V_6 ) ) {
F_9 ( L_3 , V_2 ) ;
V_13 = - V_14 ;
goto V_13;
}
V_8 = F_11 ( V_6 ) ;
if ( ! V_8 ) {
F_9 ( L_4 , V_2 ) ;
V_13 = - V_14 ;
goto V_13;
}
F_2 ( V_6 ) ;
F_12 ( L_5 , V_8 -> V_16 . V_17 , V_2 ) ;
V_13:
if ( V_6 )
F_13 ( V_6 ) ;
return V_13 ;
}
static int F_14 ( const char * V_1 , const struct V_11 * V_12 )
{
int V_4 ;
char V_2 [ 32 ] ;
struct V_7 * V_8 ;
V_4 = F_1 ( V_1 , V_2 , sizeof( V_2 ) ) ;
if ( ! V_4 ) {
F_9 ( L_1 ) ;
return - V_14 ;
}
if ( strncmp ( L_6 , V_2 , V_4 ) == 0 ) {
F_12 ( L_7 ) ;
F_15 () ;
return 0 ;
}
V_8 = F_16 ( V_2 ) ;
if ( ! V_8 ) {
F_9 ( L_8 , V_2 ) ;
return - V_14 ;
}
F_17 ( & V_8 -> V_18 ) ;
F_18 ( V_8 ) ;
return 0 ;
}
