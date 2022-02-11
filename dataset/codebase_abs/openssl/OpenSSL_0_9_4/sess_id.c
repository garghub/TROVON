int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 , V_5 , V_6 , V_7 = 0 ;
T_2 * V_8 = NULL ;
int V_9 , V_10 ;
char * V_11 = NULL , * V_12 = NULL , * V_13 = NULL ;
int V_14 = 0 , V_15 = 0 , V_16 = 0 ;
char * * V_17 ;
F_1 () ;
if ( V_18 == NULL )
if ( ( V_18 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_18 , V_19 , V_20 | V_21 ) ;
V_9 = V_22 ;
V_10 = V_22 ;
V_1 -- ;
V_2 ++ ;
V_6 = 0 ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_9 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_10 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_11 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_23;
V_12 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_16 = ++ V_6 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_14 = ++ V_6 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_15 = ++ V_6 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if( -- V_1 < 1 ) goto V_23;
V_13 = * ++ V_2 ;
}
else
{
F_6 ( V_18 , L_9 , * V_2 ) ;
V_7 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_7 )
{
V_23:
for ( V_17 = V_24 ; ( * V_17 != NULL ) ; V_17 ++ )
F_6 ( V_18 , * V_17 ) ;
goto V_25;
}
F_7 () ;
V_3 = F_8 ( V_11 , V_9 ) ;
if ( V_3 == NULL ) { goto V_25; }
if( V_13 )
{
V_3 -> V_26 = strlen ( V_13 ) ;
if( V_3 -> V_26 > V_27 )
{
F_6 ( V_18 , L_10 ) ;
goto V_25;
}
memcpy ( V_3 -> V_28 , V_13 , V_3 -> V_26 ) ;
}
#ifdef undef
{
T_1 * V_29 ;
char V_30 [ 1024 * 10 ] , * V_31 ;
int V_5 ;
V_29 = F_9 () ;
V_31 = & V_30 ;
V_5 = F_10 ( V_3 , & V_31 ) ;
V_31 = & V_30 ;
F_11 ( & V_29 , & V_31 , ( long ) V_5 ) ;
V_31 = & V_30 ;
F_11 ( & V_29 , & V_31 , ( long ) V_5 ) ;
V_31 = & V_30 ;
F_11 ( & V_29 , & V_31 , ( long ) V_5 ) ;
F_12 ( V_29 ) ;
}
#endif
if ( ! V_15 || V_16 )
{
V_8 = F_2 ( F_3 () ) ;
if ( V_8 == NULL )
{
F_13 ( V_18 ) ;
goto V_25;
}
if ( V_12 == NULL )
F_4 ( V_8 , stdout , V_20 ) ;
else
{
if ( F_14 ( V_8 , V_12 ) <= 0 )
{
perror ( V_12 ) ;
goto V_25;
}
}
}
if ( V_16 )
{
F_15 ( V_8 , V_3 ) ;
if ( V_14 )
{
if ( V_3 -> V_32 == NULL )
F_16 ( V_8 , L_11 ) ;
else
F_17 ( V_8 , V_3 -> V_32 ) ;
}
}
if ( ! V_15 && ! V_14 )
{
if ( V_10 == V_33 )
V_5 = ( int ) F_18 ( V_8 , V_3 ) ;
else if ( V_10 == V_22 )
V_5 = F_19 ( V_8 , V_3 ) ;
else {
F_6 ( V_18 , L_12 ) ;
goto V_25;
}
if ( ! V_5 ) {
F_6 ( V_18 , L_13 ) ;
goto V_25;
}
}
else if ( ! V_15 && ( V_3 -> V_32 != NULL ) )
{
if ( V_10 == V_33 )
V_5 = ( int ) F_20 ( V_8 , V_3 -> V_32 ) ;
else if ( V_10 == V_22 )
V_5 = F_21 ( V_8 , V_3 -> V_32 ) ;
else {
F_6 ( V_18 , L_12 ) ;
goto V_25;
}
if ( ! V_5 ) {
F_6 ( V_18 , L_14 ) ;
goto V_25;
}
}
V_4 = 0 ;
V_25:
if ( V_8 != NULL ) F_22 ( V_8 ) ;
if ( V_3 != NULL ) F_12 ( V_3 ) ;
EXIT ( V_4 ) ;
}
static T_1 * F_8 ( char * V_11 , int V_34 )
{
T_1 * V_3 = NULL ;
T_2 * V_35 = NULL ;
V_35 = F_2 ( F_3 () ) ;
if ( V_35 == NULL )
{
F_13 ( V_18 ) ;
goto V_25;
}
if ( V_11 == NULL )
F_4 ( V_35 , V_36 , V_20 ) ;
else
{
if ( F_23 ( V_35 , V_11 ) <= 0 )
{
perror ( V_11 ) ;
goto V_25;
}
}
if ( V_34 == V_33 )
V_3 = F_24 ( V_35 , NULL ) ;
else if ( V_34 == V_22 )
V_3 = F_25 ( V_35 , NULL , NULL , NULL ) ;
else {
F_6 ( V_18 , L_15 ) ;
goto V_25;
}
if ( V_3 == NULL )
{
F_6 ( V_18 , L_16 ) ;
F_13 ( V_18 ) ;
goto V_25;
}
V_25:
if ( V_35 != NULL ) F_22 ( V_35 ) ;
return ( V_3 ) ;
}
