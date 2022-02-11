const char * F_1 ( void )
{
return L_1 ;
}
static T_1 F_2 ( void )
{
int V_1 = 0 ;
char * V_2 = V_3 ;
char * V_4 = L_2 ;
V_2 = strstr ( V_2 , V_4 ) ;
if ( V_2 ) {
V_2 += strlen ( V_4 ) ;
V_1 = F_3 ( V_2 , NULL ) ;
}
return V_1 ;
}
static T_1 F_4 ( void )
{
int V_1 = 0 ;
char * V_2 ;
V_2 = F_5 ( L_3 ) ;
if ( V_2 )
V_1 = F_3 ( V_2 , NULL ) ;
return V_1 ;
}
static T_1 F_6 ( void )
{
T_1 V_1 ;
V_1 = F_2 () ;
if ( V_1 )
return V_1 ;
return F_4 () ;
}
static void T_2 F_7 ( void )
{
int V_5 ;
const T_3 * V_6 ;
int V_7 ;
T_1 V_1 = F_6 () ;
if ( ! V_1 )
return;
V_5 = F_8 ( V_8 , L_4 ) ;
if ( V_5 > 0 ) {
T_3 V_9 ;
V_6 = F_9 ( V_8 , V_5 , L_5 , & V_7 ) ;
V_9 = F_10 ( * V_6 ) ;
V_9 = ( V_9 & ~ 0xffffffffllu ) | V_1 ;
F_11 ( V_8 , V_5 , L_5 , V_9 ) ;
}
}
void T_2 * F_12 ( void )
{
return ( void * ) V_8 ;
}
void T_2 F_13 ( void )
{
F_7 () ;
F_14 ( V_8 ) ;
}
void T_2 F_15 ( void )
{
if ( ! V_10 )
return;
F_16 () ;
}
