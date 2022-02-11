static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = (struct V_6 * )
F_2 ( V_2 ) ;
if ( V_7 -> V_8 ) {
int V_9 = V_7 -> V_8 ( V_7 , V_5 ) ;
if ( V_9 >= 0 )
return V_9 ;
}
return sprintf ( V_5 , L_1 , V_7 -> V_10 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = (struct V_6 * )
F_2 ( V_2 ) ;
if ( V_7 -> V_11 ) {
int V_9 = V_7 -> V_11 ( V_7 , V_5 ) ;
if ( V_9 >= 0 )
return V_9 ;
}
return sprintf ( V_5 , L_2 , V_7 -> V_12 ) ;
}
void F_4 ( struct V_6 * V_7 , int V_10 )
{
char V_13 [ 120 ] ;
char V_14 [ 120 ] ;
char * V_15 ;
char * V_16 [ 3 ] ;
int V_17 = 0 ;
int V_18 ;
if ( V_7 -> V_10 != V_10 ) {
V_7 -> V_10 = V_10 ;
V_15 = ( char * ) F_5 ( V_19 ) ;
if ( V_15 ) {
V_18 = F_3 ( V_7 -> V_2 , NULL , V_15 ) ;
if ( V_18 > 0 ) {
if ( V_15 [ V_18 - 1 ] == '\n' )
V_15 [ V_18 - 1 ] = 0 ;
snprintf ( V_13 , sizeof( V_13 ) ,
L_3 , V_15 ) ;
V_16 [ V_17 ++ ] = V_13 ;
}
V_18 = F_1 ( V_7 -> V_2 , NULL , V_15 ) ;
if ( V_18 > 0 ) {
if ( V_15 [ V_18 - 1 ] == '\n' )
V_15 [ V_18 - 1 ] = 0 ;
snprintf ( V_14 , sizeof( V_14 ) ,
L_4 , V_15 ) ;
V_16 [ V_17 ++ ] = V_14 ;
}
V_16 [ V_17 ] = NULL ;
F_6 ( & V_7 -> V_2 -> V_20 , V_21 , V_16 ) ;
F_7 ( ( unsigned long ) V_15 ) ;
} else {
F_8 ( V_22 L_5 ) ;
F_9 ( & V_7 -> V_2 -> V_20 , V_21 ) ;
}
}
}
static int F_10 ( void )
{
if ( ! V_23 ) {
V_23 = F_11 ( V_24 , L_6 ) ;
if ( F_12 ( V_23 ) )
return F_13 ( V_23 ) ;
F_14 ( & V_25 , 0 ) ;
}
return 0 ;
}
int F_15 ( struct V_6 * V_7 )
{
int V_9 ;
if ( ! V_23 ) {
V_9 = F_10 () ;
if ( V_9 < 0 )
return V_9 ;
}
V_7 -> V_26 = F_16 ( & V_25 ) ;
V_7 -> V_2 = F_17 ( V_23 , NULL ,
F_18 ( 0 , V_7 -> V_26 ) , NULL , V_7 -> V_12 ) ;
if ( F_12 ( V_7 -> V_2 ) )
return F_13 ( V_7 -> V_2 ) ;
V_9 = F_19 ( V_7 -> V_2 , & V_27 ) ;
if ( V_9 < 0 )
goto V_28;
V_9 = F_19 ( V_7 -> V_2 , & V_29 ) ;
if ( V_9 < 0 )
goto V_30;
F_20 ( V_7 -> V_2 , V_7 ) ;
V_7 -> V_10 = 0 ;
return 0 ;
V_30:
F_21 ( V_7 -> V_2 , & V_27 ) ;
V_28:
F_22 ( V_23 , F_18 ( 0 , V_7 -> V_26 ) ) ;
F_8 ( V_22 L_7 , V_7 -> V_12 ) ;
return V_9 ;
}
void F_23 ( struct V_6 * V_7 )
{
F_21 ( V_7 -> V_2 , & V_29 ) ;
F_21 ( V_7 -> V_2 , & V_27 ) ;
F_22 ( V_23 , F_18 ( 0 , V_7 -> V_26 ) ) ;
F_20 ( V_7 -> V_2 , NULL ) ;
}
static int T_2 F_24 ( void )
{
return F_10 () ;
}
static void T_3 F_25 ( void )
{
F_26 ( V_23 ) ;
}
