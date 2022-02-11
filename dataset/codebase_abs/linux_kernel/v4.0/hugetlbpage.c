int F_1 ( struct V_1 * V_2 , unsigned long * V_3 , T_1 * V_4 )
{
return 0 ;
}
int F_2 ( T_2 V_5 )
{
return ! ( F_3 ( V_5 ) & V_6 ) ;
}
int F_4 ( T_3 V_7 )
{
#ifndef F_5
return ! ( F_6 ( V_7 ) & V_8 ) ;
#else
return 0 ;
#endif
}
static T_4 int F_7 ( char * V_9 )
{
unsigned long V_10 = F_8 ( V_9 , & V_9 ) ;
if ( V_10 == V_11 ) {
F_9 ( V_12 - V_13 ) ;
} else if ( V_10 == V_14 ) {
F_9 ( V_15 - V_13 ) ;
} else {
F_10 ( L_1 , V_10 >> 20 ) ;
return 0 ;
}
return 1 ;
}
