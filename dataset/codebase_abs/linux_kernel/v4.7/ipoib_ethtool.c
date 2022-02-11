static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
snprintf ( V_4 -> V_7 , sizeof( V_4 -> V_7 ) ,
L_1 , ( int ) ( V_6 -> V_8 -> V_9 . V_10 >> 32 ) ,
( int ) ( V_6 -> V_8 -> V_9 . V_10 >> 16 ) & 0xffff ,
( int ) V_6 -> V_8 -> V_9 . V_10 & 0xffff ) ;
F_3 ( V_4 -> V_11 , F_4 ( V_6 -> V_8 -> V_12 ) ,
sizeof( V_4 -> V_11 ) ) ;
F_3 ( V_4 -> V_13 , V_14 ,
sizeof( V_4 -> V_13 ) ) ;
F_3 ( V_4 -> V_15 , L_2 , sizeof( V_4 -> V_15 ) ) ;
}
static int F_5 ( struct V_1 * V_16 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_16 ) ;
V_18 -> V_19 = V_6 -> V_20 . V_21 ;
V_18 -> V_22 = V_6 -> V_20 . V_23 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_16 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_16 ) ;
int V_24 ;
if ( V_18 -> V_19 > 0xffff ||
V_18 -> V_22 > 0xffff )
return - V_25 ;
V_24 = F_7 ( V_6 -> V_26 , V_18 -> V_22 ,
V_18 -> V_19 ) ;
if ( V_24 && V_24 != - V_27 ) {
F_8 ( V_6 , L_3 , V_24 ) ;
return V_24 ;
}
V_6 -> V_20 . V_21 = V_18 -> V_19 ;
V_6 -> V_20 . V_23 = V_18 -> V_22 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_16 ,
struct V_28 T_1 * V_29 ,
T_2 * V_30 )
{
int V_31 ;
struct V_32 * V_33 = & V_16 -> V_29 ;
T_3 * V_34 = ( T_3 * ) V_33 ;
for ( V_31 = 0 ; V_31 < V_35 ; V_31 ++ )
V_30 [ V_31 ] = * ( T_2 * ) ( V_34 + V_36 [ V_31 ] . V_37 ) ;
}
static void F_10 ( struct V_1 T_1 * V_16 ,
T_4 V_38 , T_3 * V_30 )
{
T_3 * V_34 = V_30 ;
int V_31 ;
switch ( V_38 ) {
case V_39 :
for ( V_31 = 0 ; V_31 < V_35 ; V_31 ++ ) {
memcpy ( V_34 , V_36 [ V_31 ] . V_40 ,
V_41 ) ;
V_34 += V_41 ;
}
break;
case V_42 :
default:
break;
}
}
static int F_11 ( struct V_1 T_1 * V_16 ,
int V_43 )
{
switch ( V_43 ) {
case V_39 :
return V_35 ;
case V_42 :
default:
break;
}
return - V_44 ;
}
void F_12 ( struct V_1 * V_16 )
{
V_16 -> V_45 = & V_46 ;
}
