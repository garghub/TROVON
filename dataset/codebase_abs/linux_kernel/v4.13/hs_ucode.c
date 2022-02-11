static void
F_1 ( const struct V_1 * V_2 , void * V_3 ,
bool V_4 )
{
struct V_5 * V_6 = V_3 ;
struct V_7 * V_8 = V_3 + V_6 -> V_9 ;
void * V_10 = V_3 + V_6 -> V_11 ;
void * V_12 ;
T_1 V_13 ;
T_1 V_14 , V_15 ;
if ( V_4 ) {
V_14 = V_8 -> V_14 ;
V_15 = V_8 -> V_15 ;
} else {
V_14 = * ( T_1 * ) ( V_3 + V_8 -> V_14 ) ;
V_15 = * ( T_1 * ) ( V_3 + V_8 -> V_15 ) ;
}
if ( V_2 -> V_16 ) {
V_12 = V_3 + V_8 -> V_17 ;
V_13 = V_8 -> V_18 ;
} else {
V_12 = V_3 + V_8 -> V_19 ;
V_13 = V_8 -> V_20 ;
}
memcpy ( V_10 + V_14 , V_12 + V_15 , V_13 ) ;
}
void *
F_2 ( struct V_21 * V_22 , const struct V_1 * V_2 ,
const char * V_23 )
{
void * V_3 ;
bool V_4 ;
V_3 = F_3 ( V_22 , V_23 , 0 ) ;
if ( F_4 ( V_3 ) )
return V_3 ;
switch ( ( ( T_1 * ) V_3 ) [ 0 ] ) {
case 0x3b1d14f0 :
V_4 = true ;
break;
case 0x000010de :
V_4 = false ;
break;
default:
F_5 ( V_22 , L_1 , V_23 ) ;
return F_6 ( - V_24 ) ;
}
F_1 ( V_2 , V_3 , V_4 ) ;
return V_3 ;
}
