static int F_1 ( struct V_1 * V_1 , char * V_2 )
{
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < V_5 / 2 ; V_3 ++ ) {
V_4 = F_2 ( V_1 , V_6 + V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 [ V_3 * 2 ] = ( V_4 >> 8 ) & 0xff ;
V_2 [ ( V_3 * 2 ) + 1 ] = V_4 & 0xff ;
}
return 0 ;
}
static T_1 F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_1 = F_4 ( V_8 ) ;
int V_12 ;
char V_2 [ V_5 ] ;
V_12 = F_1 ( V_1 , V_2 ) ;
if ( V_12 < 0 )
return 0 ;
return sprintf ( V_11 , L_1 , V_5 , V_2 ) ;
}
int F_5 ( struct V_1 * V_1 )
{
char V_13 [ V_5 ] ;
int V_14 ;
V_14 = F_6 ( V_1 -> V_8 , & V_15 ) ;
if ( V_14 != 0 )
F_7 ( V_1 -> V_8 , L_2 ,
V_14 ) ;
V_14 = F_1 ( V_1 , V_13 ) ;
if ( V_14 == 0 )
F_8 ( V_13 , sizeof( V_13 ) ) ;
else
F_7 ( V_1 -> V_8 , L_3 , V_14 ) ;
return V_14 ;
}
void F_9 ( struct V_1 * V_1 )
{
F_10 ( V_1 -> V_8 , & V_15 ) ;
}
