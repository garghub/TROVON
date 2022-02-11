int F_1 ( T_1 V_1 )
{
return F_2 ( V_1 ) && ! ( F_2 ( V_1 ) & V_2 ) ;
}
int F_3 ( T_2 V_3 )
{
#ifndef F_4
return F_5 ( V_3 ) && ! ( F_5 ( V_3 ) & V_4 ) ;
#else
return 0 ;
#endif
}
static T_3 int F_6 ( char * V_5 )
{
unsigned long V_6 = F_7 ( V_5 , & V_5 ) ;
if ( V_6 == V_7 ) {
F_8 ( V_8 - V_9 ) ;
} else if ( V_6 == V_10 ) {
F_8 ( V_11 - V_9 ) ;
} else {
F_9 ( L_1 , V_6 >> 20 ) ;
return 0 ;
}
return 1 ;
}
