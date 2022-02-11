int F_1 ( char * * V_1 , char * * V_2 )
{
if ( ! strncmp ( * V_1 , L_1 , 4 ) ) {
* V_2 = L_2 ;
* V_1 += 4 ;
} else if ( ! strncmp ( * V_1 , L_3 , 4 ) ) {
* V_2 = * V_1 + 4 ;
* V_1 = strchr ( * V_2 , ',' ) ;
if ( ! * V_1 ) {
F_2 ( L_4 ) ;
return - V_3 ;
}
* ( ( * V_1 ) ++ ) = 0 ;
}
return 0 ;
}
int
F_3 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
int V_7 = 0 ;
if ( V_6 -> V_2 ) {
V_4 -> V_8 |= V_9 ;
V_7 = F_4 ( V_4 , V_6 -> V_10 , V_6 -> V_11 ,
V_6 -> V_2 ) ;
}
return V_7 ;
}
int
F_5 ( struct V_4 * V_4 )
{
if ( V_4 -> V_8 & V_9 )
return F_6 ( V_4 ) ;
return 0 ;
}
