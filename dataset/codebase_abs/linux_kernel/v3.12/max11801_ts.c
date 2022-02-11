static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 , V_3 << 1 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
return F_4 ( V_2 , V_3 << 1 , V_4 ) ;
}
static T_2 F_5 ( int V_5 , void * V_6 )
{
struct V_7 * V_4 = V_6 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_8 , V_9 , V_10 ;
T_1 V_11 [ V_12 ] ;
int V_13 = - 1 ;
int V_14 = - 1 ;
V_8 = F_1 ( V_4 -> V_2 , V_15 ) ;
if ( V_8 & ( V_16 | V_17 ) ) {
V_8 = F_1 ( V_4 -> V_2 , V_15 ) ;
V_10 = F_6 ( V_2 , V_18 ,
V_12 , V_11 ) ;
if ( V_10 < V_12 )
goto V_19;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 += V_12 / 2 ) {
if ( ( V_11 [ V_9 + 1 ] & V_20 ) == V_21 )
V_13 = ( V_11 [ V_9 ] << V_22 ) +
( V_11 [ V_9 + 1 ] >> V_22 ) ;
else if ( ( V_11 [ V_9 + 1 ] & V_20 ) == V_23 )
V_14 = ( V_11 [ V_9 ] << V_22 ) +
( V_11 [ V_9 + 1 ] >> V_22 ) ;
}
if ( ( V_11 [ 1 ] & V_24 ) != ( V_11 [ 3 ] & V_24 ) )
goto V_19;
switch ( V_11 [ 1 ] & V_24 ) {
case V_25 :
case V_26 :
F_7 ( V_4 -> V_27 , V_28 , V_13 ) ;
F_7 ( V_4 -> V_27 , V_29 , V_14 ) ;
F_8 ( V_4 -> V_27 , V_30 , V_31 , 1 ) ;
F_9 ( V_4 -> V_27 ) ;
break;
case V_32 :
F_8 ( V_4 -> V_27 , V_30 , V_31 , 0 ) ;
F_9 ( V_4 -> V_27 ) ;
break;
case V_33 :
break;
}
}
V_19:
return V_34 ;
}
static void F_10 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_3 ( V_2 , V_35 , 0xff ) ;
F_3 ( V_2 , V_36 , 0x11 ) ;
F_3 ( V_2 , V_37 , 0x10 ) ;
F_3 ( V_2 , V_38 , 0xaa ) ;
F_3 ( V_2 , V_39 , 0x33 ) ;
F_3 ( V_2 , V_40 , 0x36 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_41 * V_42 )
{
struct V_7 * V_4 ;
struct V_27 * V_27 ;
int error ;
V_4 = F_12 ( & V_2 -> V_43 , sizeof( * V_4 ) , V_44 ) ;
V_27 = F_13 ( & V_2 -> V_43 ) ;
if ( ! V_4 || ! V_27 ) {
F_14 ( & V_2 -> V_43 , L_1 ) ;
return - V_45 ;
}
V_4 -> V_2 = V_2 ;
V_4 -> V_27 = V_27 ;
V_27 -> V_46 = L_2 ;
V_27 -> V_42 . V_47 = V_48 ;
V_27 -> V_43 . V_49 = & V_2 -> V_43 ;
F_15 ( V_50 , V_27 -> V_51 ) ;
F_15 ( V_30 , V_27 -> V_51 ) ;
F_15 ( V_31 , V_27 -> V_52 ) ;
F_16 ( V_27 , V_28 , 0 , V_53 , 0 , 0 ) ;
F_16 ( V_27 , V_29 , 0 , V_54 , 0 , 0 ) ;
F_17 ( V_27 , V_4 ) ;
F_10 ( V_4 ) ;
error = F_18 ( & V_2 -> V_43 , V_2 -> V_5 , NULL ,
F_5 ,
V_55 | V_56 ,
L_2 , V_4 ) ;
if ( error ) {
F_14 ( & V_2 -> V_43 , L_3 ) ;
return error ;
}
error = F_19 ( V_4 -> V_27 ) ;
if ( error )
return error ;
F_20 ( V_2 , V_4 ) ;
return 0 ;
}
