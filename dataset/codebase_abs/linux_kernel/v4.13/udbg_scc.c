static void F_1 ( char V_1 )
{
if ( V_2 ) {
while ( ( F_2 ( V_2 ) & V_3 ) == 0 )
;
F_3 ( V_4 , V_1 ) ;
if ( V_1 == '\n' )
F_1 ( '\r' ) ;
}
}
static int F_4 ( void )
{
if ( V_2 ) {
if ( ( F_2 ( V_2 ) & V_5 ) != 0 )
return F_2 ( V_4 ) ;
else
return - 1 ;
}
return - 1 ;
}
static int F_5 ( void )
{
if ( V_2 ) {
while ( ( F_2 ( V_2 ) & V_5 ) == 0 )
;
return F_2 ( V_4 ) ;
}
return - 1 ;
}
void F_6 ( int V_6 )
{
const T_1 * V_7 ;
unsigned long V_8 ;
struct V_9 * stdout = NULL , * V_10 = NULL , * V_11 = NULL ;
struct V_9 * V_12 , * V_13 = NULL , * V_14 = NULL ;
const char * V_15 ;
int V_16 , V_17 ;
V_10 = F_7 ( NULL , L_1 ) ;
if ( V_10 == NULL )
goto V_18;
V_11 = F_8 ( V_10 ) ;
if ( V_11 == NULL )
goto V_18;
V_15 = F_9 ( V_19 , L_2 , NULL ) ;
if ( V_15 != NULL )
stdout = F_10 ( V_15 ) ;
for ( V_12 = NULL ; ( V_12 = F_11 ( V_10 , V_12 ) ) != NULL ; ) {
if ( V_12 == stdout )
V_13 = F_12 ( V_12 ) ;
if ( strcmp ( V_12 -> V_20 , L_3 ) == 0 )
V_14 = F_12 ( V_12 ) ;
}
if ( V_13 == NULL && ! V_6 )
goto V_18;
V_12 = V_13 ? V_13 : V_14 ;
V_7 = F_9 ( V_10 , L_4 , NULL ) ;
if ( V_7 == NULL )
goto V_18;
V_8 = V_7 [ 0 ] ;
V_7 = F_9 ( V_11 , L_5 , NULL ) ;
if ( V_7 == NULL )
goto V_18;
V_8 += V_7 [ 2 ] ;
F_13 ( V_21 , V_12 ,
V_22 | V_23 , 1 ) ;
if ( V_12 == V_14 )
V_8 += 0x20 ;
V_2 = F_14 ( V_8 & V_24 , V_25 ) ;
V_2 += V_8 & ~ V_24 ;
V_4 = V_2 + 0x10 ;
F_15 () ;
for ( V_16 = 20000 ; V_16 != 0 ; -- V_16 )
V_17 = F_2 ( V_2 ) ;
F_3 ( V_2 , 0x09 ) ;
F_3 ( V_2 , 0xc0 ) ;
if ( V_13 != NULL ) {
F_3 ( V_2 , 13 ) ;
V_26 [ 1 ] = F_2 ( V_2 ) ;
F_3 ( V_2 , 12 ) ;
V_26 [ 3 ] = F_2 ( V_2 ) ;
} else if ( F_16 ( L_6 )
|| F_16 ( L_7 )
|| F_16 ( L_8 ) ) {
V_26 [ 1 ] = 0 ;
V_26 [ 3 ] = 0 ;
} else {
V_26 [ 1 ] = 0 ;
V_26 [ 3 ] = 1 ;
}
for ( V_16 = 0 ; V_16 < sizeof( V_26 ) ; ++ V_16 )
F_3 ( V_2 , V_26 [ V_16 ] ) ;
V_27 = F_1 ;
V_28 = F_5 ;
V_29 = F_4 ;
F_17 ( L_9 ) ;
V_18:
F_18 ( V_11 ) ;
F_18 ( V_10 ) ;
F_18 ( stdout ) ;
F_18 ( V_13 ) ;
F_18 ( V_14 ) ;
}
static void F_19 ( char V_1 )
{
while ( ( F_20 ( V_2 ) & V_3 ) == 0 )
;
F_21 ( V_1 , V_4 ) ;
if ( V_1 == '\n' )
F_19 ( '\r' ) ;
}
void T_2 F_22 ( void )
{
V_2 = ( volatile V_30 V_31 * ) 0x80013020ul ;
V_4 = ( volatile V_30 V_31 * ) 0x80013030ul ;
V_27 = F_19 ;
V_28 = NULL ;
V_29 = NULL ;
}
