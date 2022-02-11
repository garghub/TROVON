static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 -> V_7 , V_4 -> V_8 ,
sizeof( V_4 -> V_8 ) ) ;
F_4 ( V_4 -> V_9 , F_5 ( V_6 -> V_7 -> V_10 . V_11 ) ,
sizeof( V_4 -> V_9 ) ) ;
F_4 ( V_4 -> V_12 , V_13 ,
sizeof( V_4 -> V_12 ) ) ;
F_4 ( V_4 -> V_14 , L_1 , sizeof( V_4 -> V_14 ) ) ;
}
static int F_6 ( struct V_1 * V_10 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_10 ) ;
V_16 -> V_17 = V_6 -> V_18 . V_19 ;
V_16 -> V_20 = V_6 -> V_18 . V_21 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_10 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_10 ) ;
int V_22 ;
if ( V_16 -> V_17 > 0xffff ||
V_16 -> V_20 > 0xffff )
return - V_23 ;
V_22 = F_8 ( V_6 -> V_24 , V_16 -> V_20 ,
V_16 -> V_17 ) ;
if ( V_22 && V_22 != - V_25 ) {
F_9 ( V_6 , L_2 , V_22 ) ;
return V_22 ;
}
V_6 -> V_18 . V_19 = V_16 -> V_17 ;
V_6 -> V_18 . V_21 = V_16 -> V_20 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_10 ,
struct V_26 T_1 * V_27 ,
T_2 * V_28 )
{
int V_29 ;
struct V_30 * V_31 = & V_10 -> V_27 ;
T_3 * V_32 = ( T_3 * ) V_31 ;
for ( V_29 = 0 ; V_29 < V_33 ; V_29 ++ )
V_28 [ V_29 ] = * ( T_2 * ) ( V_32 + V_34 [ V_29 ] . V_35 ) ;
}
static void F_11 ( struct V_1 T_1 * V_10 ,
T_4 V_36 , T_3 * V_28 )
{
T_3 * V_32 = V_28 ;
int V_29 ;
switch ( V_36 ) {
case V_37 :
for ( V_29 = 0 ; V_29 < V_33 ; V_29 ++ ) {
memcpy ( V_32 , V_34 [ V_29 ] . V_38 ,
V_39 ) ;
V_32 += V_39 ;
}
break;
case V_40 :
default:
break;
}
}
static int F_12 ( struct V_1 T_1 * V_10 ,
int V_41 )
{
switch ( V_41 ) {
case V_37 :
return V_33 ;
case V_40 :
default:
break;
}
return - V_42 ;
}
void F_13 ( struct V_1 * V_10 )
{
V_10 -> V_43 = & V_44 ;
}
