static void F_1 ( char V_1 )
{
if ( V_1 == '\n' )
F_1 ( '\r' ) ;
while( F_2 ( V_2 + V_3 ) & V_4 )
;
F_3 ( V_2 + V_5 , V_1 ) ;
F_3 ( V_2 + V_3 , V_4 ) ;
}
static int F_4 ( void )
{
return ( F_2 ( V_6 ) & V_7 ) != 0 ;
}
static int F_5 ( void )
{
int V_8 = 0 ;
int V_1 ;
while ( ! F_4 () )
;
V_1 = F_6 ( V_2 + V_9 + 2 ) ;
F_7 ( V_2 + V_9 + 2 , V_1 ) ;
F_3 ( V_6 , V_8 & ~ V_7 ) ;
return V_1 ;
}
static int F_8 ( void )
{
if ( ! F_4 () )
return - 1 ;
return F_5 () ;
}
static void F_9 ( void )
{
struct V_10 * V_11 , * V_12 , * stdout = NULL ;
const char * V_13 ;
const T_1 * V_14 ;
struct V_15 V_16 [ 2 ] ;
const int * V_17 ;
int V_18 ;
int V_19 ;
V_13 = F_10 ( V_20 , L_1 , NULL ) ;
if ( ! V_13 )
return;
stdout = F_11 ( V_13 ) ;
if ( ! stdout )
return;
F_12 (np, NULL, L_2 ) {
if ( V_11 == stdout )
break;
}
F_13 ( stdout ) ;
if ( ! V_11 )
return;
V_17 = F_10 ( V_11 , L_3 , NULL ) ;
if ( ! V_17 )
goto error;
switch ( * V_17 ) {
case 0 :
V_18 = V_21 ;
break;
case 1 :
V_18 = V_22 ;
break;
default:
goto error;
}
V_19 = F_14 ( V_11 , 0 , & V_16 [ 0 ] ) ;
if ( V_19 )
goto error;
V_14 = F_10 ( V_11 , L_4 , NULL ) ;
V_12 = F_15 ( * V_14 ) ;
if ( ! V_12 )
goto error;
V_19 = F_14 ( V_12 , 0 , & V_16 [ 1 ] ) ;
F_13 ( V_12 ) ;
if ( V_19 )
goto error;
F_13 ( V_11 ) ;
V_2 = F_16 ( V_16 [ 0 ] . V_23 , F_17 ( & V_16 [ 0 ] ) ) ;
if ( ! V_2 )
return;
V_6 = F_16 ( V_16 [ 1 ] . V_23 , F_17 ( & V_16 [ 1 ] ) ) ;
if ( ! V_6 ) {
F_18 ( V_2 ) ;
return;
}
V_6 += V_18 ;
V_24 = F_1 ;
V_25 = F_5 ;
V_26 = F_8 ;
return;
error:
F_13 ( V_11 ) ;
}
void F_19 ( void )
{
F_9 () ;
}
