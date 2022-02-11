static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
unsigned long V_4 ;
unsigned long V_5 = ( unsigned long ) V_2 -> V_6 ;
char * V_7 ;
V_7 = ( char * ) F_2 ( V_8 ) ;
if ( ! V_7 )
return - V_9 ;
V_4 = F_3 ( V_5 , V_7 , V_10 ) ;
if ( ( V_4 >> 61 ) == 0 ) {
F_4 ( V_2 , V_7 , V_4 ) ;
V_4 = 0 ;
} else
V_4 = - V_11 ;
F_5 ( ( unsigned long ) V_7 ) ;
return V_4 ;
}
static int F_6 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_1 , F_8 ( V_12 ) ) ;
}
static T_1 F_9 ( struct V_13 * V_13 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
int V_17 ;
unsigned long V_5 = ( unsigned long ) F_8 ( F_10 ( V_13 ) ) ;
char * V_18 = ( char * ) F_2 ( V_8 ) ;
unsigned long V_19 , V_20 ;
if ( ! V_18 )
return - V_9 ;
V_17 = - V_21 ;
if ( V_15 >= V_10 )
goto V_22;
V_17 = - V_11 ;
if ( F_11 ( V_18 , V_14 , V_15 ) )
goto V_22;
V_18 [ V_15 ] = '\0' ;
V_19 = F_12 ( V_5 , V_18 , V_15 ) ;
if ( ( V_19 >> 61 ) == 0 ) {
do
V_20 = F_13 () ;
while( ( V_20 >> 61 ) == 1 );
V_17 = ( int ) V_19 ;
}
V_22:
F_5 ( ( unsigned long ) V_18 ) ;
return V_17 ;
}
static int T_5
F_14 ( void )
{
T_6 * V_23 ;
unsigned long V_24 ;
if ( ! V_25 ) {
F_15 ( V_26 L_1
L_2
L_3
L_4 , V_27 ) ;
return - V_28 ;
}
V_29 = F_16 ( V_30 , NULL ) ;
if ( ! V_29 ) {
F_15 ( V_31 L_5 ,
V_30 ) ;
return - V_9 ;
}
V_32 = F_16 ( V_33 , V_29 ) ;
if ( ! V_32 ) {
F_15 ( V_31 L_6 ,
V_30 , V_33 ) ;
goto V_34;
}
V_35 = F_16 ( V_36 , V_29 ) ;
if ( ! V_35 ) {
F_15 ( V_31 L_6 ,
V_30 , V_36 ) ;
goto V_34;
}
V_23 = V_37 ;
while ( V_23 -> V_38 && V_23 -> V_5 ) {
if ( ! F_17 ( V_23 -> V_38 , 0644 , V_32 ,
& V_39 , ( void * ) V_23 -> V_5 ) )
goto V_34;
V_23 ++ ;
}
for ( V_24 = 0 ; V_24 <= 255 ; V_24 ++ ) {
char V_38 [ 4 ] ;
sprintf ( V_38 , L_7 , V_24 ) ;
if ( ! F_17 ( V_38 , 0644 , V_35 ,
& V_39 , ( void * ) V_24 ) )
goto V_34;
}
F_15 ( V_26 L_8 , V_40 ,
V_41 ) ;
return 0 ;
V_34:
F_18 ( V_30 , NULL ) ;
return - V_9 ;
}
static void T_7
F_19 ( void )
{
F_18 ( V_30 , NULL ) ;
F_15 ( V_26 L_9 , V_40 ) ;
}
