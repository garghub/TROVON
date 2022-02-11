T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_4 = 0 ;
V_3 = F_2 ( & V_2 -> V_5 ) ;
if ( F_3 ( V_3 ) ) {
return ( V_3 ) ;
}
V_3 = F_2 ( & V_2 -> V_6 ) ;
return ( V_3 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_5 ) ;
F_5 ( V_2 -> V_6 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = NULL ;
}
T_1 F_6 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_7 ( V_2 -> V_5 , V_7 ) ;
if ( F_3 ( V_3 ) ) {
return ( V_3 ) ;
}
V_2 -> V_4 ++ ;
if ( V_2 -> V_4 == 1 ) {
V_3 =
F_7 ( V_2 -> V_6 ,
V_7 ) ;
}
F_8 ( V_2 -> V_5 ) ;
return ( V_3 ) ;
}
T_1 F_9 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_7 ( V_2 -> V_5 , V_7 ) ;
if ( F_3 ( V_3 ) ) {
return ( V_3 ) ;
}
V_2 -> V_4 -- ;
if ( V_2 -> V_4 == 0 ) {
F_8 ( V_2 -> V_6 ) ;
}
F_8 ( V_2 -> V_5 ) ;
return ( V_3 ) ;
}
T_1 F_10 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_7 ( V_2 -> V_6 , V_7 ) ;
return ( V_3 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_6 ) ;
}
