static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_10 ) ; V_9 ++ ) {
V_8 = ( char * ) V_7 + V_10 [ V_9 ] . V_11 ;
V_5 [ V_9 ] = ( V_10 [ V_9 ] . V_12 == sizeof( T_1 ) )
? * ( T_1 * ) V_8 : * ( V_13 * ) V_8 ;
}
}
static void F_4 ( struct V_1 * V_2 ,
V_13 V_14 , T_2 * V_5 )
{
T_2 * V_8 = V_5 ;
int V_9 ;
switch ( V_14 ) {
case V_15 :
for ( V_9 = 0 ; V_9 < F_3 ( V_10 ) ; V_9 ++ ) {
memcpy ( V_8 , V_10 [ V_9 ] . V_16 ,
V_17 ) ;
V_8 += V_17 ;
}
break;
}
}
static int F_5 ( struct V_1 * V_2 , int V_18 )
{
switch ( V_18 ) {
case V_15 :
return F_3 ( V_10 ) ;
default:
return - V_19 ;
}
}
static void F_6 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
V_23 = V_7 -> V_23 ;
F_7 ( V_21 -> V_24 , V_25 , sizeof( V_21 -> V_24 ) ) ;
F_7 ( V_21 -> V_26 , V_27 ,
sizeof( V_21 -> V_26 ) ) ;
F_7 ( V_21 -> V_28 , L_1 , sizeof( V_21 -> V_28 ) ) ;
snprintf ( V_21 -> V_29 , sizeof( V_21 -> V_29 ) ,
L_2 , V_23 -> V_30 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
V_32 -> V_33 = 0 ;
V_32 -> V_34 = 0 ;
V_32 -> V_35 = V_36 ;
V_32 -> V_37 = V_38 ;
V_32 -> V_39 = V_40 ;
V_32 -> V_41 = V_42 ;
F_9 ( V_32 , 20000 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_43 = & V_44 ;
}
