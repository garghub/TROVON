int main ( T_1 , T_2 )
int T_1 ;
char * T_2 [] ;
{
char * V_1 ;
T_3 * V_2 ;
char V_3 [ 1024 * 10 ] , * V_4 ;
T_4 * V_5 = NULL ;
T_5 * V_6 ;
T_3 * V_7 ;
int V_8 , V_9 , V_10 , V_11 = 1 ;
if ( T_1 <= 1 )
V_1 = L_1 ;
else
V_1 = T_2 [ 1 ] ;
F_1 () ;
F_2 () ;
V_5 = F_3 ( F_4 () ) ;
V_6 = F_5 ( V_5 ) ;
F_6 ( V_6 ) ;
V_7 = F_7 ( F_8 () ) ;
F_9 ( V_7 , V_6 , V_12 ) ;
V_2 = F_7 ( F_10 () ) ;
F_11 ( V_2 , V_1 ) ;
F_12 ( V_2 , 1 ) ;
V_2 = F_13 ( V_7 , V_2 ) ;
V_4 = L_2 ;
V_9 = strlen ( V_4 ) ;
V_10 = 0 ;
for (; ; )
{
V_8 = F_14 ( V_2 , & ( V_4 [ V_10 ] ) , V_9 ) ;
if ( V_8 <= 0 )
{
if ( F_15 ( V_2 ) )
{
fprintf ( V_13 , L_3 ) ;
F_16 ( 1 ) ;
continue;
}
else
{
goto V_14;
}
}
V_10 += V_8 ;
V_9 -= V_8 ;
if ( V_9 <= 0 ) break;
}
for (; ; )
{
V_8 = F_17 ( V_2 , V_3 , sizeof( V_3 ) ) ;
if ( V_8 == 0 ) break;
if ( V_8 < 0 )
{
if ( F_15 ( V_2 ) )
{
fprintf ( V_13 , L_4 ) ;
F_16 ( 1 ) ;
continue;
}
goto V_14;
}
fwrite ( V_3 , 1 , V_8 , stdout ) ;
}
V_11 = 1 ;
if ( 0 )
{
V_14:
if ( F_18 () == 0 )
{
fprintf ( V_13 , L_5 , V_15 ) ;
perror ( L_6 ) ;
}
else
F_19 ( V_13 ) ;
}
F_20 ( V_2 ) ;
if ( V_5 != NULL ) F_21 ( V_5 ) ;
exit ( ! V_11 ) ;
return ( V_11 ) ;
}
