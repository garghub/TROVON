T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 ,
T_2 * V_5 , T_2 * V_6 , T_2 * V_7 , T_2 * V_8 )
{
struct V_9 V_10 ;
T_1 V_11 = 0x0000 ;
if ( ! V_9 ( V_2 , 'P' , & V_10 ) ) {
if ( V_10 . V_12 == 2 )
V_11 = F_2 ( V_2 , V_10 . V_13 + 4 ) ;
if ( V_11 ) {
* V_3 = F_3 ( V_2 , V_11 + 0 ) ;
switch ( * V_3 ) {
case 0x10 :
case 0x11 :
* V_4 = F_3 ( V_2 , V_11 + 1 ) ;
* V_5 = F_3 ( V_2 , V_11 + 5 ) ;
* V_6 = F_3 ( V_2 , V_11 + 2 ) ;
* V_7 = F_3 ( V_2 , V_11 + 4 ) ;
* V_8 = F_3 ( V_2 , V_11 + 3 ) ;
return V_11 ;
default:
break;
}
}
}
return 0x0000 ;
}
T_1
F_4 ( struct V_1 * V_2 , int V_14 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 V_7 , V_8 ;
T_1 V_11 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , & V_7 , & V_8 ) ;
if ( V_11 && V_14 < * V_5 ) {
V_11 = V_11 + * V_4 + ( V_14 * ( * V_6 + ( V_7 * V_8 ) ) ) ;
* V_4 = * V_6 ;
* V_5 = V_7 ;
* V_6 = V_8 ;
return V_11 ;
}
return 0x0000 ;
}
T_1
F_5 ( struct V_1 * V_2 , T_1 V_15 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
int V_14 = 0 ;
T_3 V_16 ;
while ( ( V_16 = F_4 ( V_2 , V_14 ++ , V_3 , V_4 , V_5 , V_6 ) ) ) {
if ( V_15 >= F_2 ( V_2 , V_16 + 0x00 ) &&
V_15 <= F_2 ( V_2 , V_16 + 0x02 ) )
break;
}
return V_16 ;
}
