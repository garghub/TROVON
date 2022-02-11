static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , unsigned short V_4 ,
char V_5 , T_3 V_6 , int V_7 , union V_8 * V_9 )
{
T_1 V_10 ;
int V_11 , V_12 ;
struct V_13 * V_14 = NULL ;
for ( V_11 = 0 ; V_11 < V_15 && V_16 [ V_11 ] ; V_11 ++ ) {
if ( V_3 == V_16 [ V_11 ] ) {
V_14 = V_17 + V_11 ;
break;
}
}
if ( ! V_14 )
return - V_18 ;
switch ( V_7 ) {
case V_19 :
F_2 ( & V_2 -> V_20 , L_1 , V_3 ) ;
V_10 = 0 ;
break;
case V_21 :
if ( V_5 == V_22 ) {
V_14 -> V_23 = V_6 ;
F_2 ( & V_2 -> V_20 ,
L_2 ,
V_3 , V_6 ) ;
} else {
V_9 -> V_24 = V_14 -> V_25 [ V_14 -> V_23 ++ ] & 0xff ;
F_2 ( & V_2 -> V_20 ,
L_3 ,
V_3 , V_9 -> V_24 ) ;
}
V_10 = 0 ;
break;
case V_26 :
if ( V_5 == V_22 ) {
V_14 -> V_25 [ V_6 ] &= 0xff00 ;
V_14 -> V_25 [ V_6 ] |= V_9 -> V_24 ;
F_2 ( & V_2 -> V_20 ,
L_4 ,
V_3 , V_9 -> V_24 , V_6 ) ;
} else {
V_9 -> V_24 = V_14 -> V_25 [ V_6 ] & 0xff ;
F_2 ( & V_2 -> V_20 ,
L_5 ,
V_3 , V_9 -> V_24 , V_6 ) ;
}
V_14 -> V_23 = V_6 + 1 ;
V_10 = 0 ;
break;
case V_27 :
if ( V_5 == V_22 ) {
V_14 -> V_25 [ V_6 ] = V_9 -> V_28 ;
F_2 ( & V_2 -> V_20 ,
L_6 ,
V_3 , V_9 -> V_28 , V_6 ) ;
} else {
V_9 -> V_28 = V_14 -> V_25 [ V_6 ] ;
F_2 ( & V_2 -> V_20 ,
L_7 ,
V_3 , V_9 -> V_28 , V_6 ) ;
}
V_10 = 0 ;
break;
case V_29 :
V_12 = V_9 -> V_30 [ 0 ] ;
if ( V_5 == V_22 ) {
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
V_14 -> V_25 [ V_6 + V_11 ] &= 0xff00 ;
V_14 -> V_25 [ V_6 + V_11 ] |= V_9 -> V_30 [ 1 + V_11 ] ;
}
F_2 ( & V_2 -> V_20 ,
L_8 ,
V_3 , V_12 , V_6 ) ;
} else {
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
V_9 -> V_30 [ 1 + V_11 ] =
V_14 -> V_25 [ V_6 + V_11 ] & 0xff ;
}
F_2 ( & V_2 -> V_20 ,
L_9 ,
V_3 , V_12 , V_6 ) ;
}
V_10 = 0 ;
break;
default:
F_2 ( & V_2 -> V_20 , L_10 ) ;
V_10 = - V_31 ;
break;
}
return V_10 ;
}
static T_4 F_3 ( struct V_1 * V_32 )
{
return V_33 & V_34 ;
}
static int T_5 F_4 ( void )
{
int V_11 , V_10 ;
if ( ! V_16 [ 0 ] ) {
F_5 ( L_11 ) ;
return - V_18 ;
}
for ( V_11 = 0 ; V_11 < V_15 && V_16 [ V_11 ] ; V_11 ++ ) {
if ( V_16 [ V_11 ] < 0x03 || V_16 [ V_11 ] > 0x77 ) {
F_5 ( L_12 ,
V_16 [ V_11 ] ) ;
return - V_35 ;
}
F_6 ( L_13 , V_16 [ V_11 ] ) ;
}
V_17 = F_7 ( V_11 * sizeof( struct V_13 ) , V_36 ) ;
if ( ! V_17 ) {
F_5 ( L_14 ) ;
return - V_37 ;
}
V_10 = F_8 ( & V_38 ) ;
if ( V_10 )
F_9 ( V_17 ) ;
return V_10 ;
}
static void T_6 F_10 ( void )
{
F_11 ( & V_38 ) ;
F_9 ( V_17 ) ;
}
