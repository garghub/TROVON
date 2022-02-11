static void F_1 ( struct V_1 * V_2 , int * V_3 ,
unsigned int * V_4 , bool * V_5 )
{
switch ( * V_3 ) {
case V_6 :
* V_4 = 1 ;
* V_5 = 0 ;
break;
case V_7 :
* V_3 = V_8 ;
break;
case V_9 :
* V_3 = V_6 ;
* V_4 = 0 ;
* V_5 = 0 ;
break;
}
}
static T_1 F_2 ( T_2 V_10 , T_3 V_11 ,
void * V_12 , void * * V_13 )
{
F_3 ( L_1 , V_14 ) ;
* ( bool * ) V_12 = true ;
return V_15 ;
}
static int F_4 ( void )
{
T_1 V_16 ;
bool V_17 = false ;
V_16 = F_5 ( V_14 , F_2 ,
& V_17 , NULL ) ;
if ( F_6 ( V_16 ) || ! V_17 )
return 0 ;
return - 1 ;
}
static int F_7 ( struct V_18 * V_19 )
{
if ( F_4 () ) {
F_3 ( L_2
L_3 ) ;
F_3 ( L_4
L_5 ) ;
F_3 ( L_6
L_7 ) ;
return - V_20 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_21 )
{
const char * V_22 ;
V_22 = F_9 ( V_23 ) ;
if ( ! V_22 )
return;
if ( strcmp ( V_22 , L_8 ) == 0 ) {
V_21 -> V_24 = true ;
F_10 ( L_9 ) ;
}
}
static void F_11 ( struct V_1 * V_21 )
{
V_21 -> V_24 = V_24 ;
V_21 -> V_25 = - 1 ;
F_8 ( V_21 ) ;
}
static int T_4 F_12 ( void )
{
return F_13 ( & V_1 ) ;
}
static void T_5 F_14 ( void )
{
F_15 ( & V_1 ) ;
}
