static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
bool V_5 = F_2 () ;
char V_6 [ 3 ] ;
V_6 [ 0 ] = V_5 ? 'Y' : 'N' ;
V_6 [ 1 ] = '\n' ;
V_6 [ 2 ] = 0 ;
return F_3 ( V_2 , V_3 , V_4 , V_6 , 2 ) ;
}
static T_1 F_4 ( struct V_1 * V_1 ,
const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_6 [ 32 ] ;
T_1 V_7 ;
bool V_5 ;
int V_8 ;
V_7 = F_5 ( V_3 , sizeof( V_6 ) - 1 ) ;
if ( F_6 ( V_6 , V_2 , V_7 ) )
return - V_9 ;
V_6 [ V_7 ] = '\0' ;
V_8 = F_7 ( V_6 , & V_5 ) ;
if ( V_8 )
return V_8 ;
if ( V_5 )
F_8 () ;
else
F_9 () ;
return V_3 ;
}
static int T_5 F_10 ( void )
{
struct V_10 * V_11 , * V_1 ;
if ( ! V_12 )
return - V_13 ;
V_11 = F_11 ( L_1 , V_12 ) ;
if ( F_12 ( V_11 ) )
return F_13 ( V_11 ) ;
V_1 = F_14 ( L_2 , V_14 | V_15 , V_11 ,
NULL , & V_16 ) ;
if ( ! V_1 )
return - V_17 ;
return 0 ;
}
