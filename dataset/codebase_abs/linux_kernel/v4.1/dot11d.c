void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
V_3 -> V_4 = false ;
V_3 -> V_5 = V_6 ;
V_3 -> V_7 = 0 ;
memset ( V_3 -> V_8 , 0 , V_9 + 1 ) ;
memset ( V_3 -> V_10 , 0xFF , V_9 + 1 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_11 , L_1 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
T_2 V_12 ;
T_1 V_3 = F_2 ( V_2 ) ;
memset ( V_3 -> V_8 , 0 , V_9 + 1 ) ;
memset ( V_3 -> V_10 , 0xFF , V_9 + 1 ) ;
for ( V_12 = 1 ; V_12 <= 11 ; V_12 ++ )
( V_3 -> V_8 ) [ V_12 ] = 1 ;
for ( V_12 = 12 ; V_12 <= 14 ; V_12 ++ )
( V_3 -> V_8 ) [ V_12 ] = 2 ;
V_3 -> V_5 = V_6 ;
V_3 -> V_7 = 0 ;
F_3 ( V_2 ) ;
}
void F_6 ( struct V_1 * V_11 , T_3 * V_13 ,
T_4 V_14 , T_3 * V_15 )
{
T_1 V_3 = F_2 ( V_11 ) ;
T_3 V_12 , V_16 , V_17 , V_18 ;
T_5 V_19 ;
memset ( V_3 -> V_8 , 0 , V_9 + 1 ) ;
memset ( V_3 -> V_10 , 0xFF , V_9 + 1 ) ;
V_18 = 0 ;
V_17 = ( V_14 - 3 ) / 3 ;
V_19 = ( T_5 ) ( V_15 + 3 ) ;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
if ( V_18 >= V_19 -> V_20 ) {
F_7 ( V_11 -> V_11 , L_2 ) ;
return;
}
if ( V_9 < ( V_19 -> V_20 + V_19 -> V_21 ) ) {
F_7 ( V_11 -> V_11 , L_3 ) ;
return;
}
for ( V_16 = 0 ; V_16 < V_19 -> V_21 ; V_16 ++ ) {
V_3 -> V_8 [ V_19 -> V_20 + V_16 ] = 1 ;
V_3 -> V_10 [ V_19 -> V_20 + V_16 ] = V_19 -> V_22 ;
V_18 = V_19 -> V_20 + V_16 ;
}
V_19 = ( T_5 ) ( ( T_3 * ) V_19 + 3 ) ;
}
F_4 ( V_11 -> V_11 , L_4 ) ;
for ( V_12 = 1 ; V_12 <= V_9 ; V_12 ++ )
if ( V_3 -> V_8 [ V_12 ] > 0 )
F_4 ( V_11 -> V_11 , L_5 , V_12 ) ;
F_4 ( V_11 -> V_11 , L_6 ) ;
F_8 ( V_11 , V_13 ) ;
V_3 -> V_7 = V_14 ;
memcpy ( V_3 -> V_23 , V_15 , V_14 ) ;
V_3 -> V_5 = V_24 ;
}
T_3 F_9 ( struct V_1 * V_11 , T_3 V_25 )
{
T_1 V_3 = F_2 ( V_11 ) ;
T_3 V_26 = 255 ;
if ( V_9 < V_25 ) {
F_7 ( V_11 -> V_11 , L_7 ) ;
return V_26 ;
}
if ( V_3 -> V_8 [ V_25 ] )
V_26 = V_3 -> V_10 [ V_25 ] ;
return V_26 ;
}
void F_10 ( struct V_1 * V_11 )
{
T_1 V_3 = F_2 ( V_11 ) ;
switch ( V_3 -> V_5 ) {
case V_24 :
V_3 -> V_5 = V_27 ;
break;
case V_27 :
if ( F_11 ( V_11 ) == 0 ) {
F_5 ( V_11 ) ;
}
break;
case V_6 :
break;
}
}
int F_12 ( struct V_1 * V_11 , T_3 V_28 )
{
T_1 V_3 = F_2 ( V_11 ) ;
if ( V_9 < V_28 ) {
F_7 ( V_11 -> V_11 , L_8 ) ;
return 0 ;
}
if ( V_3 -> V_8 [ V_28 ] > 0 )
return 1 ;
return 0 ;
}
int F_13 ( struct V_1 * V_11 , T_3 V_28 )
{
T_1 V_3 = F_2 ( V_11 ) ;
T_3 V_29 = 0 ;
T_2 V_12 = 0 ;
for ( V_12 = 1 ; V_12 <= V_9 ; V_12 ++ ) {
if ( V_3 -> V_8 [ V_12 ] > 0 ) {
V_29 = V_12 ;
break;
}
}
if ( V_9 < V_28 ) {
F_7 ( V_11 -> V_11 , L_8 ) ;
return V_29 ;
}
if ( V_3 -> V_8 [ V_28 ] > 0 )
return V_28 ;
return V_29 ;
}
