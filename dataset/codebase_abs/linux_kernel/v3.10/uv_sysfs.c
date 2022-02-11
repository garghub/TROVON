static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , V_7 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , F_3 () ) ;
}
static int T_2 F_4 ( void )
{
unsigned long V_8 ;
if ( ! F_5 () )
return - V_9 ;
if ( ! V_10 )
V_10 = F_6 ( L_2 , V_11 ) ;
if ( ! V_10 ) {
F_7 ( V_12 L_3 ) ;
return - V_13 ;
}
V_8 = F_8 ( V_10 , & V_14 . V_4 ) ;
if ( V_8 ) {
F_7 ( V_12 L_4 ) ;
return V_8 ;
}
V_8 = F_8 ( V_10 , & V_15 . V_4 ) ;
if ( V_8 ) {
F_7 ( V_12 L_5 ) ;
return V_8 ;
}
return 0 ;
}
