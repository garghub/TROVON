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
static T_1 F_6 ( T_2 V_24 , T_3 V_25 ,
void * V_26 , void * * V_27 )
{
F_7 ( L_3 , V_28 ) ;
* ( bool * ) V_26 = true ;
return V_29 ;
}
static int F_8 ( void )
{
T_1 V_30 ;
bool V_31 = false ;
V_30 = F_9 ( V_28 , F_6 ,
& V_31 , NULL ) ;
if ( F_10 ( V_30 ) || ! V_31 )
return 0 ;
return - 1 ;
}
static int F_11 ( struct V_32 * V_33 )
{
if ( F_8 () ) {
F_7 ( L_4
L_5 ) ;
F_7 ( L_6
L_7 ) ;
F_7 ( L_8
L_9 ) ;
return - V_34 ;
}
return 0 ;
}
static void F_12 ( struct V_15 * V_35 )
{
V_6 = & V_36 ;
V_6 -> V_37 = V_37 ;
F_13 ( V_38 ) ;
V_35 -> V_6 = V_6 ;
V_35 -> V_6 -> V_39 = - 1 ;
V_35 -> V_40 = V_41 ;
}
static int T_4 F_14 ( void )
{
return F_15 ( & V_15 ) ;
}
static void T_5 F_16 ( void )
{
F_17 ( & V_15 ) ;
}
