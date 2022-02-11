void F_1 ( void )
{
V_1 = true ;
}
void F_2 ( void )
{
if ( V_2 )
fflush ( V_2 ) ;
V_1 = false ;
}
void F_3 ( const char * V_3 )
{
strncpy ( V_4 , V_3 , V_5 - 5 ) ;
strcat ( V_4 , L_1 ) ;
}
static void F_4 ( const unsigned char * V_6 , int V_7 , T_1 V_8 ,
int V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
fprintf ( V_2 , L_2 ) ;
fprintf ( V_2 , L_3 V_11 L_4 , V_8 ) ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ )
fprintf ( V_2 , L_5 , V_6 [ V_10 ] ) ;
for (; V_10 < 16 ; V_10 ++ )
fprintf ( V_2 , L_6 ) ;
fprintf ( V_2 , L_2 ) ;
}
static void F_5 ( T_1 V_8 , int V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
fprintf ( V_2 , L_2 ) ;
fprintf ( V_2 , L_3 V_11 L_4 , V_8 ) ;
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ )
fprintf ( V_2 , L_6 ) ;
fprintf ( V_2 , L_2 ) ;
}
static int F_6 ( void )
{
if ( ! V_1 )
return - 1 ;
if ( V_2 )
return 0 ;
if ( ! V_4 [ 0 ] )
return - 1 ;
V_2 = fopen ( V_4 , L_7 ) ;
if ( ! V_2 ) {
V_1 = false ;
return - 1 ;
}
return 0 ;
}
void F_7 ( const struct V_12 * V_13 , int V_14 ,
T_1 V_8 , const unsigned char * V_6 )
{
char V_15 [ V_16 ] ;
if ( F_6 () )
return;
F_4 ( V_6 , V_14 , V_8 , 0 ) ;
F_8 ( V_13 , V_15 , V_16 ) ;
fprintf ( V_2 , L_8 , V_15 ) ;
}
void F_9 ( struct V_17 * V_17 , T_1 V_18 )
{
char V_15 [ V_19 ] ;
T_2 V_7 = V_17 -> V_20 ;
if ( F_6 () )
return;
if ( V_7 > V_21 )
V_7 = V_21 ;
F_4 ( V_17 -> V_6 , V_7 , V_18 , 8 ) ;
if ( F_10 ( V_17 , V_15 , V_19 ) > 0 )
fprintf ( V_2 , L_8 , V_15 ) ;
else
fprintf ( V_2 , L_9 ) ;
}
void F_11 ( struct V_17 * V_17 , T_1 V_18 )
{
char V_15 [ V_19 ] ;
if ( F_6 () )
return;
F_5 ( V_18 , 8 ) ;
if ( F_10 ( V_17 , V_15 , V_19 ) > 0 )
fprintf ( V_2 , L_8 , V_15 ) ;
else
fprintf ( V_2 , L_9 ) ;
}
void F_12 ( const char * V_22 , ... )
{
T_3 args ;
if ( F_6 () )
return;
va_start ( args , V_22 ) ;
vfprintf ( V_2 , V_22 , args ) ;
va_end ( args ) ;
}
