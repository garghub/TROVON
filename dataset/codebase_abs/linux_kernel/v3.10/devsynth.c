static T_1 F_1 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_4 , T_3 * V_5 )
{
T_2 V_6 = V_4 ;
const char * V_7 = V_3 ;
T_2 V_8 ;
unsigned long V_9 ;
T_4 V_10 [ 256 ] ;
if ( V_11 == NULL )
return - V_12 ;
while ( V_6 > 0 ) {
V_8 = F_2 ( V_6 , sizeof( V_10 ) ) ;
if ( F_3 ( V_10 , V_7 , V_8 ) )
return - V_13 ;
V_6 -= V_8 ;
V_7 += V_8 ;
F_4 ( V_9 ) ;
F_5 ( V_10 , V_8 ) ;
F_6 ( V_9 ) ;
}
return ( T_1 ) V_4 ;
}
static T_1 F_7 ( struct V_1 * V_2 , char * V_10 , T_2 V_4 ,
T_3 * V_5 )
{
return 0 ;
}
static int F_8 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
if ( V_11 == NULL )
return - V_12 ;
if ( F_9 ( & V_16 , 1 ) )
return - V_17 ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
V_16 = 0 ;
return 0 ;
}
void F_11 ( void )
{
if ( V_18 != 0 )
return;
if ( F_12 ( & V_19 ) )
F_13 ( L_1 ) ;
else {
F_14 ( L_2 ,
V_20 , V_21 ) ;
V_18 = 1 ;
}
}
void F_15 ( void )
{
if ( ! V_18 )
return;
F_14 ( L_3 ) ;
F_16 ( & V_19 ) ;
V_18 = 0 ;
}
