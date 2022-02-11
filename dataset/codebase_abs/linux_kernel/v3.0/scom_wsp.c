static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
struct V_5 V_6 ;
T_2 V_7 ;
if ( ! F_2 ( V_2 , L_1 , NULL ) ) {
F_3 ( L_2 ,
V_8 , V_2 -> V_9 ) ;
return V_10 ;
}
if ( F_4 ( V_2 , 0 , & V_6 ) ) {
F_5 ( L_3 ) ;
return 0 ;
}
V_7 = ( ( V_3 & 0x7f000000 ) >> 1 ) | ( ( V_3 & 0xfffff ) << 3 ) ;
return ( T_1 ) F_6 ( V_6 . V_11 + V_7 , V_4 << 3 ) ;
}
static void F_7 ( T_1 V_12 )
{
F_8 ( ( void * ) V_12 ) ;
}
static T_2 F_9 ( T_1 V_12 , T_3 V_3 )
{
T_2 T_4 * V_13 = ( T_2 T_4 * ) V_12 ;
return F_10 ( V_13 + V_3 ) ;
}
static void F_11 ( T_1 V_12 , T_3 V_3 , T_2 V_14 )
{
T_2 T_4 * V_13 = ( T_2 T_4 * ) V_12 ;
return F_12 ( V_13 + V_3 , V_14 ) ;
}
void F_13 ( void )
{
F_14 ( & V_15 ) ;
}
