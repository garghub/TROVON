static T_1
F_1 ( T_2 V_1 ,
T_3 V_2 ,
union V_3 * * V_4 )
{
struct V_5 * V_6 ;
union V_3 * V_7 ;
T_1 V_8 ;
if ( ! V_4 || ( ! V_1 && ! V_2 ) ) {
return ( V_9 ) ;
}
V_6 = V_1 ;
if ( V_2 != NULL ) {
V_8 = F_2 ( V_1 , V_2 ,
F_3 ( T_2 ,
& V_6 ) ) ;
if ( F_4 ( V_8 ) ) {
return ( V_8 ) ;
}
}
if ( ! V_6 || ( V_6 -> type != V_10 ) ) {
return ( V_11 ) ;
}
V_7 = F_5 ( V_6 ) ;
if ( ! V_7 ) {
return ( V_12 ) ;
}
* V_4 = V_7 ;
return ( V_13 ) ;
}
T_1
F_6 ( T_2 V_1 , T_3 V_2 , T_4 V_14 )
{
T_1 V_8 ;
union V_3 * V_7 ;
V_8 = F_1 ( V_1 , V_2 , & V_7 ) ;
if ( F_4 ( V_8 ) ) {
return ( V_8 ) ;
}
V_8 = F_7 ( V_7 -> V_15 . V_16 , V_14 ) ;
return ( V_8 ) ;
}
T_1 F_8 ( T_2 V_1 , T_3 V_2 )
{
T_1 V_8 ;
union V_3 * V_7 ;
V_8 = F_1 ( V_1 , V_2 , & V_7 ) ;
if ( F_4 ( V_8 ) ) {
return ( V_8 ) ;
}
F_9 ( V_7 -> V_15 . V_16 ) ;
return ( V_13 ) ;
}
