static void F_1 ( const char * V_1 , const char * V_2 , T_1 V_3 )
{
char V_4 [ 1024 ] ;
vsnprintf ( V_4 , sizeof( V_4 ) , V_2 , V_3 ) ;
fprintf ( V_5 , L_1 , V_1 , V_4 ) ;
}
static NORETURN void F_2 ( const char * V_2 )
{
fprintf ( V_5 , L_2 , V_2 ) ;
exit ( 129 ) ;
}
static NORETURN void F_3 ( const char * V_2 , T_1 V_3 )
{
F_1 ( L_3 , V_2 , V_3 ) ;
exit ( 128 ) ;
}
static void F_4 ( const char * V_2 , T_1 V_3 )
{
F_1 ( L_4 , V_2 , V_3 ) ;
}
static void F_5 ( const char * V_6 , T_1 V_3 )
{
F_1 ( L_5 , V_6 , V_3 ) ;
}
void F_6 ( const char * V_2 )
{
F_7 ( V_2 ) ;
}
void F_8 ( const char * V_2 , ... )
{
T_1 V_3 ;
va_start ( V_3 , V_2 ) ;
F_9 ( V_2 , V_3 ) ;
va_end ( V_3 ) ;
}
int error ( const char * V_2 , ... )
{
T_1 V_3 ;
va_start ( V_3 , V_2 ) ;
F_10 ( V_2 , V_3 ) ;
va_end ( V_3 ) ;
return - 1 ;
}
void F_11 ( const char * V_6 , ... )
{
T_1 V_3 ;
va_start ( V_3 , V_6 ) ;
F_12 ( V_6 , V_3 ) ;
va_end ( V_3 ) ;
}
T_2 F_13 ( const char * V_7 , const char * V_8 , const char * V_9 )
{
struct V_10 V_11 , * V_12 ;
char V_13 [ 1024 ] ;
if ( V_7 == NULL )
return V_14 ;
if ( V_8 || V_9 ) {
F_14 ( L_6 ) ;
F_15 ( 1 ) ;
return V_14 ;
}
F_16 ( V_7 , & V_11 , V_13 , sizeof( V_13 ) , & V_12 ) ;
if ( V_12 == NULL ) {
char * V_15 ;
int V_16 = strtol ( V_7 , & V_15 , 10 ) ;
if ( * V_15 != '\0' ) {
F_17 ( L_7 , V_7 ) ;
return V_14 - 1 ;
}
F_18 ( V_16 , & V_11 , V_13 , sizeof( V_13 ) , & V_12 ) ;
if ( V_12 == NULL ) {
F_17 ( L_8 ,
V_7 ) ;
return V_14 - 1 ;
}
}
return V_12 -> V_17 ;
}
