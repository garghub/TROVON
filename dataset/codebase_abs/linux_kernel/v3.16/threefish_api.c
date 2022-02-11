void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
T_1 * V_5 , T_1 * V_6 )
{
int V_7 = V_4 / 64 ;
int V_8 ;
T_1 V_9 = V_10 ;
V_2 -> V_6 [ 0 ] = V_6 [ 0 ] ;
V_2 -> V_6 [ 1 ] = V_6 [ 1 ] ;
V_2 -> V_6 [ 2 ] = V_6 [ 0 ] ^ V_6 [ 1 ] ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
V_2 -> V_11 [ V_8 ] = V_5 [ V_8 ] ;
V_9 ^= V_5 [ V_8 ] ;
}
V_2 -> V_11 [ V_8 ] = V_9 ;
V_2 -> V_4 = V_4 ;
}
void F_2 ( struct V_1 * V_2 , T_2 * V_12 ,
T_2 * V_13 )
{
T_1 V_14 [ V_15 ] ;
T_1 V_16 [ V_15 ] ;
F_3 ( V_14 , V_12 , V_2 -> V_4 / 64 ) ;
F_4 ( V_2 , V_14 , V_16 ) ;
F_5 ( V_13 , V_16 , V_2 -> V_4 / 8 ) ;
}
void F_4 ( struct V_1 * V_2 , T_1 * V_12 ,
T_1 * V_13 )
{
switch ( V_2 -> V_4 ) {
case V_17 :
F_6 ( V_2 , V_12 , V_13 ) ;
break;
case V_18 :
F_7 ( V_2 , V_12 , V_13 ) ;
break;
case V_19 :
F_8 ( V_2 , V_12 , V_13 ) ;
break;
}
}
void F_9 ( struct V_1 * V_2 , T_2 * V_12 ,
T_2 * V_13 )
{
T_1 V_14 [ V_15 ] ;
T_1 V_16 [ V_15 ] ;
F_3 ( V_16 , V_12 , V_2 -> V_4 / 64 ) ;
F_10 ( V_2 , V_16 , V_14 ) ;
F_5 ( V_13 , V_14 , V_2 -> V_4 / 8 ) ;
}
void F_10 ( struct V_1 * V_2 , T_1 * V_12 ,
T_1 * V_13 )
{
switch ( V_2 -> V_4 ) {
case V_17 :
F_11 ( V_2 , V_12 , V_13 ) ;
break;
case V_18 :
F_12 ( V_2 , V_12 , V_13 ) ;
break;
case V_19 :
F_13 ( V_2 , V_12 , V_13 ) ;
break;
}
}
