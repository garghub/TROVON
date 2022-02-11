T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
struct V_7 V_8 ;
if ( ! V_7 ( V_2 , 'd' , & V_8 ) ) {
if ( V_8 . V_9 == 1 ) {
T_1 V_10 = F_2 ( V_2 , V_8 . V_11 ) ;
if ( V_10 ) {
* V_3 = F_3 ( V_2 , V_10 + 0 ) ;
* V_4 = F_3 ( V_2 , V_10 + 1 ) ;
* V_6 = F_3 ( V_2 , V_10 + 2 ) ;
* V_5 = F_3 ( V_2 , V_10 + 3 ) ;
return V_10 ;
}
}
}
return 0x0000 ;
}
T_1
F_4 ( struct V_1 * V_2 , T_2 V_12 , T_2 * V_3 , T_2 * V_6 )
{
T_2 V_4 , V_5 ;
T_1 V_13 = F_1 ( V_2 , V_3 , & V_4 , & V_5 , V_6 ) ;
if ( V_13 && V_12 < V_5 )
return F_2 ( V_2 , V_13 + V_4 + ( V_12 * * V_6 ) ) ;
return 0xffff ;
}
T_1
F_5 ( struct V_1 * V_2 , struct V_14 * V_15 ,
T_2 * V_3 , T_2 * V_6 )
{
T_2 V_12 = 0 ;
T_1 V_10 ;
while ( ( V_10 = F_4 ( V_2 , V_12 ++ , V_3 , V_6 ) ) != 0xffff ) {
if ( V_10 ) {
T_3 V_16 = F_6 ( V_2 , V_10 ) ;
if ( F_7 ( V_15 , V_16 ) )
return V_10 ;
}
}
return 0x0000 ;
}
