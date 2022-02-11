static T_1
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 , ( F_2 ( V_6 ) >> 4 ) & 0xf ) ;
}
static T_1
F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_7 )
{
unsigned long V_8 ;
V_8 = F_4 ( V_5 , NULL , 10 ) ;
if ( V_8 >= F_5 () )
return - V_9 ;
F_6 ( 0xa5 << 24 | V_8 << 4 , V_6 ) ;
return V_7 ;
}
static int T_3 F_7 ( void )
{
if ( F_8 ( ! V_6 ) )
return - V_10 ;
return F_9 ( & V_11 , & V_12 ) ;
}
int F_10 ( unsigned long V_13 )
{
if ( F_8 ( V_6 ) )
return - V_14 ;
V_6 = F_11 ( V_13 , V_15 ) ;
if ( F_8 ( ! V_6 ) )
return - V_16 ;
F_12 ( L_2 ,
F_5 () - 1 ) ;
return 0 ;
}
