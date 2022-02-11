static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
unsigned long V_4 ;
T_1 * V_5 ;
char * V_6 ;
V_5 = V_2 -> V_7 ;
V_6 = ( char * ) F_2 ( V_8 ) ;
if ( ! V_6 )
return - V_9 ;
V_4 = F_3 ( V_5 -> V_10 , V_6 , V_11 ) ;
if ( ( V_4 >> 61 ) == 0 ) {
F_4 ( V_2 , V_6 , V_4 ) ;
V_4 = 0 ;
} else
V_4 = - V_12 ;
F_5 ( ( unsigned long ) V_6 ) ;
return V_4 ;
}
static int F_6 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
return F_7 ( V_14 , F_1 , F_8 ( V_13 ) -> V_15 ) ;
}
static T_2 F_9 ( struct V_14 * V_14 , const char T_3 * V_16 ,
T_4 V_17 , T_5 * V_18 )
{
int V_19 ;
T_1 * V_5 = F_8 ( F_10 ( V_14 ) ) -> V_15 ;
char * V_20 = ( char * ) F_2 ( V_8 ) ;
unsigned long V_21 , V_22 ;
if ( ! V_20 )
return - V_9 ;
V_19 = - V_23 ;
if ( V_17 >= V_11 )
goto V_24;
V_19 = - V_12 ;
if ( F_11 ( V_20 , V_16 , V_17 ) )
goto V_24;
V_20 [ V_17 ] = '\0' ;
V_21 = F_12 ( V_5 -> V_10 , V_20 , V_17 ) ;
if ( ( V_21 >> 61 ) == 0 ) {
do
V_22 = F_13 () ;
while( ( V_22 >> 61 ) == 1 );
V_19 = ( int ) V_21 ;
}
V_24:
F_5 ( ( unsigned long ) V_20 ) ;
return V_19 ;
}
static void
F_14 ( void )
{
T_1 * V_5 ;
unsigned long V_25 ;
if ( V_26 ) {
if ( V_27 ) {
V_5 = V_28 ;
while ( V_5 -> V_29 != NULL && V_5 -> V_10 != 0 ) {
if ( V_5 -> V_30 ) {
F_15 ( V_5 -> V_29 ,
V_27 ) ;
V_5 -> V_30 = NULL ;
}
V_5 ++ ;
}
F_15 ( V_31 , V_26 ) ;
}
if ( V_32 ) {
for ( V_25 = 0 ; V_25 <= 255 ; V_25 ++ ) {
V_5 = & V_33 [ V_25 ] ;
if ( V_5 -> V_30 ) {
F_15 ( V_5 -> V_29 ,
V_32 ) ;
V_5 -> V_30 = NULL ;
V_5 -> V_29 = NULL ;
}
}
F_15 ( V_34 , V_26 ) ;
}
F_15 ( V_35 , NULL ) ;
}
return;
}
static int T_6
F_16 ( void )
{
T_1 * V_5 ;
unsigned long V_25 ;
if ( ! V_36 ) {
F_17 ( V_37 L_1
L_2
L_3
L_4 , V_38 ) ;
return - V_39 ;
}
for ( V_25 = 0 ; V_25 <= 255 ; V_25 ++ )
sprintf ( V_40 [ V_25 ] , L_5 , V_25 ) ;
V_26 = F_18 ( V_35 , NULL ) ;
if ( ! V_26 ) {
F_17 ( V_41 L_6 ,
V_35 ) ;
goto V_42;
}
V_27 = F_18 ( V_31 , V_26 ) ;
if ( ! V_27 ) {
F_17 ( V_41 L_7 ,
V_35 , V_31 ) ;
goto V_42;
}
V_32 = F_18 ( V_34 , V_26 ) ;
if ( ! V_32 ) {
F_17 ( V_41 L_7 ,
V_35 , V_34 ) ;
goto V_42;
}
V_5 = V_28 ;
while ( V_5 -> V_29 && V_5 -> V_10 ) {
V_5 -> V_30 = F_19 ( V_5 -> V_29 , 0644 , V_27 ,
& V_43 , V_5 ) ;
if ( ! V_5 -> V_30 )
goto V_42;
V_5 ++ ;
}
for ( V_25 = 0 ; V_25 <= 255 ; V_25 ++ ) {
V_5 = & V_33 [ V_25 ] ;
V_5 -> V_29 = V_40 [ V_25 ] ;
V_5 -> V_30 = F_19 ( V_5 -> V_29 , 0644 , V_32 ,
& V_43 , V_5 ) ;
if ( ! V_5 -> V_30 )
goto V_42;
V_5 -> V_10 = V_25 ;
}
F_17 ( V_37 L_8 , V_44 ,
V_45 ) ;
return 0 ;
V_42:
F_14 () ;
return - V_9 ;
}
static void T_7
F_20 ( void )
{
F_14 () ;
F_17 ( V_37 L_9 , V_44 ) ;
return;
}
