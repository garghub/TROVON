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
T_1 * V_5 = F_8 ( V_14 -> V_20 . V_21 -> V_22 ) -> V_15 ;
char * V_23 = ( char * ) F_2 ( V_8 ) ;
unsigned long V_24 , V_25 ;
if ( ! V_23 )
return - V_9 ;
V_19 = - V_26 ;
if ( V_17 >= V_11 )
goto V_27;
V_19 = - V_12 ;
if ( F_10 ( V_23 , V_16 , V_17 ) )
goto V_27;
V_23 [ V_17 ] = '\0' ;
V_24 = F_11 ( V_5 -> V_10 , V_23 , V_17 ) ;
if ( ( V_24 >> 61 ) == 0 ) {
do
V_25 = F_12 () ;
while( ( V_25 >> 61 ) == 1 );
V_19 = ( int ) V_24 ;
}
V_27:
F_5 ( ( unsigned long ) V_23 ) ;
return V_19 ;
}
static void
F_13 ( void )
{
T_1 * V_5 ;
unsigned long V_28 ;
if ( V_29 ) {
if ( V_30 ) {
V_5 = V_31 ;
while ( V_5 -> V_32 != NULL && V_5 -> V_10 != 0 ) {
if ( V_5 -> V_33 ) {
F_14 ( V_5 -> V_32 ,
V_30 ) ;
V_5 -> V_33 = NULL ;
}
V_5 ++ ;
}
F_14 ( V_34 , V_29 ) ;
}
if ( V_35 ) {
for ( V_28 = 0 ; V_28 <= 255 ; V_28 ++ ) {
V_5 = & V_36 [ V_28 ] ;
if ( V_5 -> V_33 ) {
F_14 ( V_5 -> V_32 ,
V_35 ) ;
V_5 -> V_33 = NULL ;
V_5 -> V_32 = NULL ;
}
}
F_14 ( V_37 , V_29 ) ;
}
F_14 ( V_38 , NULL ) ;
}
return;
}
static int T_6
F_15 ( void )
{
T_1 * V_5 ;
unsigned long V_28 ;
if ( ! V_39 ) {
F_16 ( V_40 L_1
L_2
L_3
L_4 , V_41 ) ;
return - V_42 ;
}
for ( V_28 = 0 ; V_28 <= 255 ; V_28 ++ )
sprintf ( V_43 [ V_28 ] , L_5 , V_28 ) ;
V_29 = F_17 ( V_38 , NULL ) ;
if ( ! V_29 ) {
F_16 ( V_44 L_6 ,
V_38 ) ;
goto V_45;
}
V_30 = F_17 ( V_34 , V_29 ) ;
if ( ! V_30 ) {
F_16 ( V_44 L_7 ,
V_38 , V_34 ) ;
goto V_45;
}
V_35 = F_17 ( V_37 , V_29 ) ;
if ( ! V_35 ) {
F_16 ( V_44 L_7 ,
V_38 , V_37 ) ;
goto V_45;
}
V_5 = V_31 ;
while ( V_5 -> V_32 && V_5 -> V_10 ) {
V_5 -> V_33 = F_18 ( V_5 -> V_32 , 0644 , V_30 ,
& V_46 , V_5 ) ;
if ( ! V_5 -> V_33 )
goto V_45;
V_5 ++ ;
}
for ( V_28 = 0 ; V_28 <= 255 ; V_28 ++ ) {
V_5 = & V_36 [ V_28 ] ;
V_5 -> V_32 = V_43 [ V_28 ] ;
V_5 -> V_33 = F_18 ( V_5 -> V_32 , 0644 , V_35 ,
& V_46 , V_5 ) ;
if ( ! V_5 -> V_33 )
goto V_45;
V_5 -> V_10 = V_28 ;
}
F_16 ( V_40 L_8 , V_47 ,
V_48 ) ;
return 0 ;
V_45:
F_13 () ;
return - V_9 ;
}
static void T_7
F_19 ( void )
{
F_13 () ;
F_16 ( V_40 L_9 , V_47 ) ;
return;
}
