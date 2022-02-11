T_1
F_1 ( struct V_1 * V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 , T_2 * V_7 , T_2 * V_8 )
{
struct V_9 V_10 ;
T_1 V_11 = 0x00000000 ;
if ( ! V_9 ( V_2 , 'P' , & V_10 ) ) {
if ( V_10 . V_12 == 2 && V_10 . V_13 > 0x63 )
V_11 = F_2 ( V_2 , V_10 . V_14 + 0x60 ) ;
if ( V_11 ) {
* V_3 = F_3 ( V_2 , V_11 + 0 ) ;
switch ( * V_3 ) {
case 0x10 :
* V_4 = F_3 ( V_2 , V_11 + 1 ) ;
* V_5 = F_3 ( V_2 , V_11 + 2 ) ;
* V_6 = 4 ;
* V_7 = F_3 ( V_2 , V_11 + 3 ) ;
* V_8 = 4 ;
return V_11 ;
default:
break;
}
}
}
return 0x00000000 ;
}
T_1
F_4 ( struct V_1 * V_2 , int V_15 , T_2 * V_3 , T_2 * V_6 )
{
T_2 V_4 , V_5 , V_7 , V_8 ;
T_1 V_11 = F_1 ( V_2 , V_3 , & V_4 , & V_5 , V_6 , & V_7 , & V_8 ) ;
if ( V_11 && V_15 < V_5 )
return V_11 + V_4 + ( V_15 * * V_6 ) ;
return 0x00000000 ;
}
T_1
F_5 ( struct V_1 * V_2 , int V_15 , T_2 * V_3 , T_2 * V_6 ,
struct V_16 * V_17 )
{
T_1 V_11 = F_4 ( V_2 , V_15 , V_3 , V_6 ) ;
memset ( V_17 , 0x00 , sizeof( * V_17 ) ) ;
switch ( ! ! V_11 * * V_3 ) {
case 0x10 :
V_17 -> V_11 = F_2 ( V_2 , V_11 ) ;
return V_11 ;
default:
break;
}
return 0x00000000 ;
}
T_1
F_6 ( struct V_1 * V_2 , int V_15 , T_2 * V_3 , T_2 * V_8 )
{
T_2 V_4 , V_5 , V_6 , V_7 ;
T_1 V_11 = F_1 ( V_2 , V_3 , & V_4 , & V_5 , & V_6 , & V_7 , V_8 ) ;
if ( V_11 && V_15 < V_7 )
return V_11 + V_4 + ( V_5 * V_6 ) + ( V_15 * * V_8 ) ;
return 0x00000000 ;
}
T_1
F_7 ( struct V_1 * V_2 , int V_15 , T_2 * V_3 , T_2 * V_4 ,
struct V_18 * V_17 )
{
T_1 V_11 = F_6 ( V_2 , V_15 , V_3 , V_4 ) ;
memset ( V_17 , 0x00 , sizeof( * V_17 ) ) ;
switch ( ! ! V_11 * * V_3 ) {
case 0x10 :
V_17 -> V_11 = F_2 ( V_2 , V_11 ) ;
return V_11 ;
default:
break;
}
return 0x00000000 ;
}
