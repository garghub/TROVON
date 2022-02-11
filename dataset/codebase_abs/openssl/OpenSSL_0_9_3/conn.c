int main ( T_1 , T_2 )
int T_1 ;
char * T_2 [] ;
{
T_3 * V_1 ;
char * V_2 ;
char V_3 [ 1024 * 10 ] , * V_4 ;
T_4 * V_5 ;
int V_6 , V_7 , V_8 , V_9 = 1 ;
if ( T_1 <= 1 )
V_2 = L_1 ;
else
V_2 = T_2 [ 1 ] ;
F_1 () ;
V_1 = F_2 () ;
F_3 ( V_1 , V_10 , L_2 ) ;
V_5 = F_4 ( F_5 () ) ;
F_6 ( V_5 , V_2 ) ;
F_7 ( V_5 , V_1 ) ;
F_8 ( V_5 , L_3 ) ;
F_9 ( V_5 , 1 ) ;
V_4 = L_4 ;
V_7 = strlen ( V_4 ) ;
V_8 = 0 ;
for (; ; )
{
V_6 = F_10 ( V_5 , & ( V_4 [ V_8 ] ) , V_7 ) ;
if ( V_6 <= 0 )
{
if ( F_11 ( V_5 ) )
{
fprintf ( V_11 , L_5 ) ;
F_12 ( 1 ) ;
continue;
}
else
{
goto V_12;
}
}
V_8 += V_6 ;
V_7 -= V_6 ;
if ( V_7 <= 0 ) break;
}
for (; ; )
{
V_6 = F_13 ( V_5 , V_3 , sizeof( V_3 ) ) ;
if ( V_6 == 0 ) break;
if ( V_6 < 0 )
{
if ( F_11 ( V_5 ) )
{
fprintf ( V_11 , L_6 ) ;
F_12 ( 1 ) ;
continue;
}
goto V_12;
}
fwrite ( V_3 , 1 , V_6 , stdout ) ;
}
V_9 = 1 ;
if ( 0 )
{
V_12:
if ( F_14 () == 0 )
{
fprintf ( V_11 , L_7 , V_13 ) ;
perror ( L_8 ) ;
}
else
F_15 ( V_11 ) ;
}
F_16 ( V_5 ) ;
if ( V_1 != NULL ) F_17 ( V_1 ) ;
exit ( ! V_9 ) ;
return ( V_9 ) ;
}
