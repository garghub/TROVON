static void F_1 ( void )
{
const struct V_1 * V_2 = NULL ;
char V_3 [ 30 ] ;
while ( ( V_2 = F_2 ( V_4 , NULL , V_2 ) ) ) {
if ( sscanf ( V_2 -> V_5 , L_1 , V_3 ) == 1 ) {
if ( V_3 [ 18 ] == '1' )
V_6 = & V_7 ;
else if ( V_3 [ 18 ] == '3' )
V_6 = & V_8 ;
break;
}
}
}
static int F_3 ( const struct V_9 * V_10 )
{
char * V_11 ;
V_6 = V_10 -> V_12 ;
V_11 = ( char * ) V_10 -> V_13 [ 1 ] . V_14 ;
if ( F_4 ( strncmp ( V_11 , L_2 , 6 ) == 0 ) )
F_1 () ;
return 1 ;
}
static void F_5 ( struct V_15 * V_16 , int * V_17 ,
unsigned int * V_18 , bool * V_19 )
{
switch ( * V_17 ) {
case V_20 :
* V_18 = 1 ;
* V_19 = 0 ;
break;
case V_21 :
* V_17 = V_22 ;
break;
case V_23 :
* V_17 = V_20 ;
* V_18 = 0 ;
* V_19 = 0 ;
break;
}
}
static int F_6 ( struct V_24 * V_25 )
{
if ( F_7 ( V_26 ) ) {
F_8 ( L_3 , V_26 ) ;
F_8 ( L_4
L_5 ) ;
F_8 ( L_6
L_7 ) ;
F_8 ( L_8
L_9 ) ;
return - V_27 ;
}
return 0 ;
}
static void F_9 ( struct V_15 * V_28 )
{
V_6 = & V_29 ;
V_6 -> V_30 = V_30 ;
F_10 ( V_31 ) ;
V_28 -> V_6 = V_6 ;
V_28 -> V_6 -> V_32 = - 1 ;
V_28 -> V_33 = V_34 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_15 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_15 ) ;
}
