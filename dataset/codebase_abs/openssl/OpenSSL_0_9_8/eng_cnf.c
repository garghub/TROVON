static char * F_1 ( char * V_1 )
{
char * V_2 ;
V_2 = strchr ( V_1 , '.' ) ;
if ( V_2 )
return V_2 + 1 ;
return V_1 ;
}
static int F_2 ( T_1 * V_3 )
{
if ( ! F_3 ( V_3 ) )
return 0 ;
if ( ! V_4 )
V_4 = F_4 () ;
if ( ! V_4 || ! F_5 ( V_4 , V_3 ) )
{
F_6 ( V_3 ) ;
return 0 ;
}
return 1 ;
}
static int F_7 ( char * V_1 , char * V_5 , const T_2 * V_6 )
{
int V_7 ;
int V_8 = 0 ;
long V_9 = - 1 ;
F_8 ( V_10 ) * V_11 ;
V_10 * V_12 ;
char * V_13 , * V_14 ;
T_1 * V_3 = NULL ;
V_1 = F_1 ( V_1 ) ;
#ifdef F_9
fprintf ( V_15 , L_1 , V_1 ) ;
#endif
V_11 = F_10 ( V_6 , V_5 ) ;
if ( ! V_11 )
{
F_11 ( V_16 , V_17 ) ;
return 0 ;
}
for ( V_7 = 0 ; V_7 < F_12 ( V_11 ) ; V_7 ++ )
{
V_12 = F_13 ( V_11 , V_7 ) ;
V_13 = F_1 ( V_12 -> V_1 ) ;
V_14 = V_12 -> V_5 ;
#ifdef F_9
fprintf ( V_15 , L_2 , V_13 , V_14 ) ;
#endif
if ( ! strcmp ( V_13 , L_3 ) )
V_1 = V_14 ;
else if ( ! strcmp ( V_13 , L_4 ) )
{
V_3 = F_14 ( L_5 ) ;
if ( ! V_3 )
goto V_18;
if ( ! F_15 ( V_3 , L_6 , V_14 , 0 ) )
goto V_18;
if ( ! F_15 ( V_3 , L_7 , L_8 , 0 ) )
goto V_18;
if ( ! F_15 ( V_3 , L_9 , NULL , 0 ) )
goto V_18;
}
else
{
if ( ! V_3 )
{
V_3 = F_14 ( V_1 ) ;
if ( ! V_3 )
return 0 ;
}
if ( ! strcmp ( V_14 , L_10 ) )
V_14 = NULL ;
if ( ! strcmp ( V_13 , L_11 ) )
{
if ( ! F_16 ( V_6 , V_5 , L_11 , & V_9 ) )
goto V_18;
if ( V_9 == 1 )
{
if ( ! F_2 ( V_3 ) )
goto V_18;
}
else if ( V_9 != 0 )
{
F_11 ( V_16 , V_19 ) ;
goto V_18;
}
}
else if ( ! strcmp ( V_13 , L_12 ) )
{
if ( ! F_17 ( V_3 , V_14 ) )
goto V_18;
}
else if ( ! F_15 ( V_3 ,
V_13 , V_14 , 0 ) )
return 0 ;
}
}
if ( V_3 && ( V_9 == - 1 ) && ! F_2 ( V_3 ) )
goto V_18;
V_8 = 1 ;
V_18:
if ( V_3 )
F_18 ( V_3 ) ;
return V_8 ;
}
static int F_19 ( T_3 * V_20 , const T_2 * V_6 )
{
F_8 ( V_10 ) * V_21 ;
V_10 * V_22 ;
int V_7 ;
#ifdef F_9
fprintf ( V_15 , L_13 ,
F_20 ( V_20 ) , F_21 ( V_20 ) ) ;
#endif
V_21 = F_10 ( V_6 , F_21 ( V_20 ) ) ;
if ( ! V_21 )
{
F_11 ( V_23 , V_24 ) ;
return 0 ;
}
for ( V_7 = 0 ; V_7 < F_12 ( V_21 ) ; V_7 ++ )
{
V_22 = F_13 ( V_21 , V_7 ) ;
if ( ! F_7 ( V_22 -> V_1 , V_22 -> V_5 , V_6 ) )
return 0 ;
}
return 1 ;
}
static void F_22 ( T_3 * V_20 )
{
T_1 * V_3 ;
while ( ( V_3 = F_23 ( V_4 ) ) )
F_6 ( V_3 ) ;
F_24 ( V_4 ) ;
V_4 = NULL ;
}
void F_25 ( void )
{
F_26 ( L_14 ,
F_19 ,
F_22 ) ;
}
