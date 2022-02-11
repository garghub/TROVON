char * F_1 ( char * * V_1 , char * * V_2 )
{
if ( ! strncmp ( * V_1 , L_1 , 4 ) ) {
* V_2 = L_2 ;
* V_1 += 4 ;
} else if ( ! strncmp ( * V_1 , L_3 , 4 ) ) {
* V_2 = * V_1 + 4 ;
* V_1 = strchr ( * V_2 , ',' ) ;
if ( ! * V_1 )
F_2 ( L_4 ) ;
else
* ( ( * V_1 ) ++ ) = 0 ;
} else
return NULL ;
return * V_1 ;
}
int
F_3 ( struct V_3 * V_3 , struct V_4 * V_5 )
{
int V_6 = 0 ;
if ( V_5 -> V_2 ) {
V_3 -> V_7 |= V_8 ;
V_6 = F_4 ( V_3 , V_5 -> V_9 , V_5 -> V_10 ,
V_5 -> V_2 ) ;
}
return V_6 ;
}
int
F_5 ( struct V_3 * V_3 )
{
if ( V_3 -> V_7 & V_8 )
return F_6 ( V_3 ) ;
return 0 ;
}
