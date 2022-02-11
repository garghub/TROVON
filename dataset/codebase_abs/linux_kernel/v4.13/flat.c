unsigned long F_1 ( T_1 * V_1 ,
T_1 V_2 ,
T_1 V_3 ,
T_1 * V_4 )
{
unsigned short * V_5 = ( unsigned short * ) V_1 ;
int type = ( V_2 >> 26 ) & 7 ;
T_1 V_6 ;
switch ( type ) {
case V_7 :
case V_8 :
V_5 = ( unsigned short * ) V_1 ;
F_2 ( L_1 , F_3 ( V_5 ) ) ;
V_6 = F_3 ( V_5 ) ;
V_6 += * V_4 ;
break;
case V_9 :
F_2 ( L_2 , F_3 ( V_1 ) ) ;
V_6 = F_3 ( V_1 ) ;
break;
default:
F_2 ( L_3 , type ) ;
return 0 ;
}
if ( V_2 & ( 1 << 29 ) )
return V_6 + V_10 -> V_11 -> V_12 . V_13 ;
if ( ( V_3 & V_14 ) == 0 )
V_6 = F_4 ( V_6 ) ;
return V_6 ;
}
void F_5 ( T_1 * V_1 , T_1 V_15 , T_1 V_2 )
{
unsigned short * V_5 = ( unsigned short * ) V_1 ;
int type = ( V_2 >> 26 ) & 7 ;
switch ( type ) {
case V_7 :
F_6 ( V_15 , V_5 ) ;
F_2 ( L_4 , F_3 ( V_5 ) , V_5 ) ;
break;
case V_8 :
F_6 ( V_15 >> 16 , V_5 ) ;
F_2 ( L_5 , F_3 ( V_5 ) ) ;
break;
case V_9 :
F_6 ( V_15 , V_1 ) ;
F_2 ( L_6 , F_3 ( V_1 ) ) ;
break;
}
}
