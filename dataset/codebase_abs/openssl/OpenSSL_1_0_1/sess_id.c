int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL ;
int V_5 = 1 , V_6 , V_7 , V_8 = 0 ;
T_3 * V_9 = NULL ;
int V_10 , V_11 ;
char * V_12 = NULL , * V_13 = NULL , * V_14 = NULL ;
int V_15 = 0 , V_16 = 0 , V_17 = 0 ;
const char * * V_18 ;
F_1 () ;
if ( V_19 == NULL )
if ( ( V_19 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_19 , V_20 , V_21 | V_22 ) ;
V_10 = V_23 ;
V_11 = V_23 ;
V_1 -- ;
V_2 ++ ;
V_7 = 0 ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_10 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_11 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_12 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_13 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_17 = ++ V_7 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_15 = ++ V_7 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_16 = ++ V_7 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if( -- V_1 < 1 ) goto V_24;
V_14 = * ++ V_2 ;
}
else
{
F_6 ( V_19 , L_9 , * V_2 ) ;
V_8 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_8 )
{
V_24:
for ( V_18 = V_25 ; ( * V_18 != NULL ) ; V_18 ++ )
F_6 ( V_19 , L_10 , * V_18 ) ;
goto V_26;
}
F_7 () ;
V_3 = F_8 ( V_12 , V_10 ) ;
if ( V_3 == NULL ) { goto V_26; }
V_4 = F_9 ( V_3 ) ;
if( V_14 )
{
T_4 V_27 = strlen ( V_14 ) ;
if( V_27 > V_28 )
{
F_6 ( V_19 , L_11 ) ;
goto V_26;
}
F_10 ( V_3 , ( unsigned char * ) V_14 , V_27 ) ;
}
#ifdef undef
{
T_1 * V_29 ;
char V_30 [ 1024 * 10 ] , * V_31 ;
int V_6 ;
V_29 = F_11 () ;
V_31 = & V_30 ;
V_6 = F_12 ( V_3 , & V_31 ) ;
V_31 = & V_30 ;
F_13 ( & V_29 , & V_31 , ( long ) V_6 ) ;
V_31 = & V_30 ;
F_13 ( & V_29 , & V_31 , ( long ) V_6 ) ;
V_31 = & V_30 ;
F_13 ( & V_29 , & V_31 , ( long ) V_6 ) ;
F_14 ( V_29 ) ;
}
#endif
if ( ! V_16 || V_17 )
{
V_9 = F_2 ( F_3 () ) ;
if ( V_9 == NULL )
{
F_15 ( V_19 ) ;
goto V_26;
}
if ( V_13 == NULL )
{
F_4 ( V_9 , stdout , V_21 ) ;
#ifdef F_16
{
T_3 * V_32 = F_2 ( F_17 () ) ;
V_9 = F_18 ( V_32 , V_9 ) ;
}
#endif
}
else
{
if ( F_19 ( V_9 , V_13 ) <= 0 )
{
perror ( V_13 ) ;
goto V_26;
}
}
}
if ( V_17 )
{
F_20 ( V_9 , V_3 ) ;
if ( V_15 )
{
if ( V_4 == NULL )
F_21 ( V_9 , L_12 ) ;
else
F_22 ( V_9 , V_4 ) ;
}
}
if ( ! V_16 && ! V_15 )
{
if ( V_11 == V_33 )
V_6 = F_23 ( V_9 , V_3 ) ;
else if ( V_11 == V_23 )
V_6 = F_24 ( V_9 , V_3 ) ;
else {
F_6 ( V_19 , L_13 ) ;
goto V_26;
}
if ( ! V_6 ) {
F_6 ( V_19 , L_14 ) ;
goto V_26;
}
}
else if ( ! V_16 && ( V_4 != NULL ) )
{
if ( V_11 == V_33 )
V_6 = ( int ) F_25 ( V_9 , V_4 ) ;
else if ( V_11 == V_23 )
V_6 = F_26 ( V_9 , V_4 ) ;
else {
F_6 ( V_19 , L_13 ) ;
goto V_26;
}
if ( ! V_6 ) {
F_6 ( V_19 , L_15 ) ;
goto V_26;
}
}
V_5 = 0 ;
V_26:
if ( V_9 != NULL ) F_27 ( V_9 ) ;
if ( V_3 != NULL ) F_14 ( V_3 ) ;
F_28 () ;
F_29 ( V_5 ) ;
}
static T_1 * F_8 ( char * V_12 , int V_34 )
{
T_1 * V_3 = NULL ;
T_3 * V_35 = NULL ;
V_35 = F_2 ( F_3 () ) ;
if ( V_35 == NULL )
{
F_15 ( V_19 ) ;
goto V_26;
}
if ( V_12 == NULL )
F_4 ( V_35 , V_36 , V_21 ) ;
else
{
if ( F_30 ( V_35 , V_12 ) <= 0 )
{
perror ( V_12 ) ;
goto V_26;
}
}
if ( V_34 == V_33 )
V_3 = F_31 ( V_35 , NULL ) ;
else if ( V_34 == V_23 )
V_3 = F_32 ( V_35 , NULL , NULL , NULL ) ;
else {
F_6 ( V_19 , L_16 ) ;
goto V_26;
}
if ( V_3 == NULL )
{
F_6 ( V_19 , L_17 ) ;
F_15 ( V_19 ) ;
goto V_26;
}
V_26:
if ( V_35 != NULL ) F_33 ( V_35 ) ;
return ( V_3 ) ;
}
