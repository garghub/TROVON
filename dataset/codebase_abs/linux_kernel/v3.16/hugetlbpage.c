int F_1 ( struct V_1 * V_2 , unsigned long * V_3 , T_1 * V_4 )
{
return 0 ;
}
struct V_5 * F_2 ( struct V_1 * V_2 , unsigned long V_6 ,
int V_7 )
{
return F_3 ( - V_8 ) ;
}
int F_4 ( T_2 V_9 )
{
return ! ( F_5 ( V_9 ) & V_10 ) ;
}
int F_6 ( T_3 V_11 )
{
#ifndef F_7
return ! ( F_8 ( V_11 ) & V_12 ) ;
#else
return 0 ;
#endif
}
static T_4 int F_9 ( char * V_13 )
{
unsigned long V_14 = F_10 ( V_13 , & V_13 ) ;
if ( V_14 == V_15 ) {
F_11 ( V_16 - V_17 ) ;
} else if ( V_14 == V_18 ) {
F_11 ( V_19 - V_17 ) ;
} else {
F_12 ( L_1 , V_14 >> 20 ) ;
return 0 ;
}
return 1 ;
}
