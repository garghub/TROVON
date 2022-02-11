static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
return F_2 ( V_2 , V_3 , V_4 , V_5 ,
V_6 ) ;
}
void T_5 F_3 ( const struct V_7 * V_8 )
{
const void * V_9 = V_8 ;
T_3 V_10 = sizeof( V_8 -> V_11 ) ;
while ( F_4 ( V_8 -> V_11 ) != V_12 ) {
T_6 V_13 = F_4 ( V_8 -> V_10 ) ;
V_10 += V_13 ;
V_8 = (struct V_7 * ) ( ( unsigned long ) V_8 + V_13 ) ;
}
if ( V_10 > sizeof( V_14 ) ) {
F_5 ( L_1 , V_10 ) ;
return;
}
F_6 ( L_2 , V_10 ) ;
memcpy ( V_14 , V_9 , V_10 ) ;
V_6 = V_10 ;
}
static int T_5 F_7 ( void )
{
struct V_15 * V_16 ;
if ( ! V_6 )
return - V_17 ;
V_5 = F_8 ( V_6 , V_18 ) ;
if ( ! V_5 )
return - V_19 ;
memcpy ( V_5 , V_14 , V_6 ) ;
V_16 = F_9 ( L_3 , 0400 , NULL , & V_20 , NULL ) ;
if ( ! V_16 ) {
F_10 ( V_5 ) ;
return - V_19 ;
}
return 0 ;
}
