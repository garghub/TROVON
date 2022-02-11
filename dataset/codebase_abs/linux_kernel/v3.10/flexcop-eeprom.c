static T_1 F_1 ( T_1 * V_1 , int V_2 )
{
int V_3 ;
T_1 V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
V_4 = V_4 ^ V_1 [ V_3 ] ;
return V_4 ;
}
static int F_2 ( struct V_5 * V_6 ,
T_2 V_7 , T_3 V_8 , T_1 * V_1 , T_3 V_2 , int V_9 )
{
int V_3 , V_10 = 0 ;
T_1 V_11 = 0x50 | ( ( V_8 >> 8 ) & 3 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
V_10 = V_6 -> V_12 ( & V_6 -> V_13 [ 1 ] , V_7 , V_11 ,
V_8 & 0xff , V_1 , V_2 ) ;
if ( V_10 == 0 )
break;
}
return V_10 ;
}
static int F_3 ( struct V_5 * V_6 , T_3 V_8 ,
T_1 * V_1 , T_3 V_2 , int V_9 )
{
int V_10 = F_2 ( V_6 , V_14 , V_8 , V_1 , V_2 , V_9 ) ;
if ( V_10 == 0 )
if ( F_1 ( V_1 , V_2 - 1 ) != V_1 [ V_2 - 1 ] )
V_10 = - V_15 ;
return V_10 ;
}
int F_4 ( struct V_5 * V_6 , int V_16 )
{
T_1 V_1 [ 8 ] ;
int V_10 = 0 ;
if ( ( V_10 = F_3 ( V_6 , 0x3f8 , V_1 , 8 , 4 ) ) == 0 ) {
if ( V_16 != 0 ) {
F_5 ( L_1
L_2 ) ;
V_10 = - V_15 ;
} else
memcpy ( V_6 -> V_17 . V_18 , V_1 , 6 ) ;
}
return V_10 ;
}
