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
int V_3 , V_12 ;
char V_2 [ V_5 ] ;
T_1 V_13 = 0 ;
V_12 = F_1 ( V_1 , V_2 ) ;
if ( V_12 < 0 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ )
V_13 += sprintf ( & V_11 [ V_13 ] , L_1 , V_11 [ V_3 ] ) ;
V_13 += sprintf ( & V_11 [ V_13 ] , L_2 ) ;
return V_13 ;
}
int F_5 ( struct V_1 * V_1 )
{
char V_14 [ V_5 ] ;
int V_13 ;
V_13 = F_6 ( V_1 -> V_8 , & V_15 ) ;
if ( V_13 != 0 )
F_7 ( V_1 -> V_8 , L_3 ,
V_13 ) ;
V_13 = F_1 ( V_1 , V_14 ) ;
if ( V_13 == 0 )
F_8 ( V_14 , sizeof( V_14 ) ) ;
else
F_7 ( V_1 -> V_8 , L_4 , V_13 ) ;
return V_13 ;
}
void F_9 ( struct V_1 * V_1 )
{
F_10 ( V_1 -> V_8 , & V_15 ) ;
}
