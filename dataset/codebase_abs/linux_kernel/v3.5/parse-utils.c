void F_1 ( const char * V_1 , T_1 V_2 )
{
int V_3 = V_4 ;
if ( V_4 )
perror ( L_1 ) ;
else
V_3 = - 1 ;
fprintf ( V_5 , L_2 ) ;
vfprintf ( V_5 , V_1 , V_2 ) ;
fprintf ( V_5 , L_3 ) ;
exit ( V_3 ) ;
}
void F_2 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_1 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
void __weak F_3 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_1 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
void F_4 ( const char * V_1 , T_1 V_2 )
{
if ( V_4 )
perror ( L_1 ) ;
V_4 = 0 ;
fprintf ( V_5 , L_2 ) ;
vfprintf ( V_5 , V_1 , V_2 ) ;
fprintf ( V_5 , L_3 ) ;
}
void F_5 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_4 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
void __weak F_6 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_4 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
void F_7 ( const char * V_1 , T_1 V_2 )
{
vprintf ( V_1 , V_2 ) ;
printf ( L_3 ) ;
}
void F_8 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_7 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
void __weak F_9 ( const char * V_1 , T_1 V_2 )
{
F_7 ( V_1 , V_2 ) ;
}
void __weak F_10 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_7 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
void __weak * F_11 ( unsigned int V_6 )
{
void * V_7 ;
V_7 = malloc ( V_6 ) ;
if ( ! V_7 )
F_3 ( L_4 ) ;
return V_7 ;
}
