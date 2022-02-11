void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 )
{
void * V_6 ;
V_5 &= ~ ( V_7 | V_8 ) ;
if ( V_2 == NULL || ( * V_2 -> V_9 < 0xffffffff ) )
V_5 |= V_10 ;
V_6 = ( void * ) F_2 ( V_5 , F_3 ( V_3 ) ) ;
if ( V_6 != NULL ) {
memset ( V_6 , 0 , V_3 ) ;
* V_4 = F_4 ( V_6 ) ;
}
return V_6 ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_11 , T_2 V_4 )
{
F_6 ( ( unsigned long ) V_11 , F_3 ( V_3 ) ) ;
}
void F_7 ( struct V_1 * V_2 , T_2 V_12 ,
T_1 V_3 , enum V_13 V_14 )
{
switch ( V_14 ) {
case V_15 :
F_8 ( V_12 , V_3 ) ;
break;
case V_16 :
break;
default:
if ( F_9 () )
F_10 ( L_1 , V_14 ) ;
break;
}
}
T_2 F_11 ( struct V_1 * V_2 , void * V_17 , T_1 V_3 ,
enum V_13 V_14 )
{
T_2 V_12 = F_4 ( V_17 ) ;
F_8 ( V_12 , V_3 ) ;
return V_12 ;
}
T_2 F_12 ( struct V_1 * V_2 , struct V_18 * V_18 ,
unsigned long V_19 , T_1 V_3 ,
enum V_13 V_14 )
{
T_2 V_12 = F_13 ( V_18 ) + V_19 ;
F_7 ( V_2 , V_12 , V_3 , V_14 ) ;
return V_12 ;
}
