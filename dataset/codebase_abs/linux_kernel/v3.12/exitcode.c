static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
V_4 = V_5 ;
F_2 ( V_2 , L_1 , V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
return F_4 ( V_7 , F_1 , NULL ) ;
}
static T_1 F_5 ( struct V_7 * V_7 ,
const char T_2 * V_8 , T_3 V_9 , T_4 * V_10 )
{
char * V_11 , V_12 [ sizeof( L_2 ) ] ;
T_3 V_13 ;
int V_14 ;
V_13 = F_6 ( V_9 , sizeof( V_12 ) ) ;
if ( F_7 ( V_12 , V_8 , V_13 ) )
return - V_15 ;
V_14 = F_8 ( V_12 , & V_11 , 0 ) ;
if ( ( * V_11 != '\0' ) && ! isspace ( * V_11 ) )
return - V_16 ;
V_5 = V_14 ;
return V_9 ;
}
static int F_9 ( void )
{
struct V_17 * V_18 ;
V_18 = F_10 ( L_3 , 0600 , NULL , & V_19 ) ;
if ( V_18 == NULL ) {
F_11 ( V_20 L_4
L_5 ) ;
return 0 ;
}
return 0 ;
}
