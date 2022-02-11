static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , bool V_7 )
{
struct V_1 * V_8 , * V_9 = NULL ;
F_2 (b, &chip->smbus_blocks, node) {
if ( V_8 -> V_6 == V_6 ) {
V_9 = V_8 ;
break;
}
}
if ( V_9 == NULL && V_7 ) {
V_9 = F_3 ( V_3 , sizeof( * V_9 ) , V_10 ) ;
if ( V_9 == NULL )
return V_9 ;
V_9 -> V_6 = V_6 ;
F_4 ( & V_9 -> V_11 , & V_5 -> V_12 ) ;
}
return V_9 ;
}
static T_2 * F_5 ( struct V_4 * V_5 , T_1 V_13 )
{
if ( V_5 -> V_14 &&
V_13 >= V_5 -> V_15 && V_13 <= V_5 -> V_16 )
return V_5 -> V_17 +
( V_5 -> V_14 - 1 ) * V_5 -> V_18 +
V_13 - V_5 -> V_15 ;
else
return V_5 -> V_19 + V_13 ;
}
static T_3 F_6 ( struct V_20 * V_21 , T_2 V_22 , unsigned short V_23 ,
char V_24 , T_1 V_6 , int V_25 , union V_26 * V_27 )
{
T_3 V_28 ;
int V_29 , V_30 ;
struct V_4 * V_5 = NULL ;
struct V_1 * V_8 ;
T_2 * V_31 ;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ ) {
if ( V_22 == V_33 [ V_29 ] ) {
V_5 = V_34 + V_29 ;
break;
}
}
if ( ! V_5 )
return - V_35 ;
switch ( V_25 ) {
case V_36 :
F_7 ( & V_21 -> V_3 , L_1 , V_22 ) ;
V_28 = 0 ;
break;
case V_37 :
if ( V_24 == V_38 ) {
V_5 -> V_39 = V_6 ;
F_7 ( & V_21 -> V_3 ,
L_2 ,
V_22 , V_6 ) ;
} else {
V_31 = F_5 ( V_5 , V_5 -> V_39 ++ ) ;
V_27 -> V_40 = * V_31 & 0xff ;
F_7 ( & V_21 -> V_3 ,
L_3 ,
V_22 , V_27 -> V_40 ) ;
}
V_28 = 0 ;
break;
case V_41 :
V_31 = F_5 ( V_5 , V_6 ) ;
if ( V_24 == V_38 ) {
* V_31 &= 0xff00 ;
* V_31 |= V_27 -> V_40 ;
F_7 ( & V_21 -> V_3 ,
L_4 ,
V_22 , V_27 -> V_40 , V_6 ) ;
if ( V_5 -> V_17 && V_6 == V_5 -> V_42 ) {
V_5 -> V_14 =
( V_27 -> V_40 >> V_5 -> V_43 )
& V_5 -> V_44 ;
F_7 ( & V_21 -> V_3 ,
L_5 ,
V_5 -> V_14 ) ;
}
} else {
V_27 -> V_40 = * V_31 & 0xff ;
F_7 ( & V_21 -> V_3 ,
L_6 ,
V_22 , V_27 -> V_40 , V_6 ) ;
}
V_5 -> V_39 = V_6 + 1 ;
V_28 = 0 ;
break;
case V_45 :
V_31 = F_5 ( V_5 , V_6 ) ;
if ( V_24 == V_38 ) {
* V_31 = V_27 -> V_46 ;
F_7 ( & V_21 -> V_3 ,
L_7 ,
V_22 , V_27 -> V_46 , V_6 ) ;
} else {
V_27 -> V_46 = * V_31 ;
F_7 ( & V_21 -> V_3 ,
L_8 ,
V_22 , V_27 -> V_46 , V_6 ) ;
}
V_28 = 0 ;
break;
case V_47 :
if ( V_27 -> V_48 [ 0 ] > 256 - V_6 )
V_27 -> V_48 [ 0 ] = 256 - V_6 ;
V_30 = V_27 -> V_48 [ 0 ] ;
if ( V_24 == V_38 ) {
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_5 -> V_19 [ V_6 + V_29 ] &= 0xff00 ;
V_5 -> V_19 [ V_6 + V_29 ] |= V_27 -> V_48 [ 1 + V_29 ] ;
}
F_7 ( & V_21 -> V_3 ,
L_9 ,
V_22 , V_30 , V_6 ) ;
} else {
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_27 -> V_48 [ 1 + V_29 ] =
V_5 -> V_19 [ V_6 + V_29 ] & 0xff ;
}
F_7 ( & V_21 -> V_3 ,
L_10 ,
V_22 , V_30 , V_6 ) ;
}
V_28 = 0 ;
break;
case V_49 :
V_8 = F_1 ( & V_21 -> V_3 , V_5 , V_6 , false ) ;
if ( V_24 == V_38 ) {
V_30 = V_27 -> V_48 [ 0 ] ;
if ( V_30 == 0 || V_30 > V_50 ) {
V_28 = - V_51 ;
break;
}
if ( V_8 == NULL ) {
V_8 = F_1 ( & V_21 -> V_3 , V_5 , V_6 ,
true ) ;
if ( V_8 == NULL ) {
V_28 = - V_52 ;
break;
}
}
if ( V_30 > V_8 -> V_30 )
V_8 -> V_30 = V_30 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ )
V_8 -> V_48 [ V_29 ] = V_27 -> V_48 [ V_29 + 1 ] ;
V_5 -> V_19 [ V_6 ] = ( V_8 -> V_48 [ 0 ] << 8 ) | V_8 -> V_30 ;
F_7 ( & V_21 -> V_3 ,
L_11 ,
V_22 , V_30 , V_6 ) ;
} else {
if ( V_8 == NULL ) {
F_7 ( & V_21 -> V_3 ,
L_12 ) ;
V_28 = - V_53 ;
break;
}
V_30 = V_8 -> V_30 ;
V_27 -> V_48 [ 0 ] = V_30 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ )
V_27 -> V_48 [ V_29 + 1 ] = V_8 -> V_48 [ V_29 ] ;
F_7 ( & V_21 -> V_3 ,
L_13 ,
V_22 , V_30 , V_6 ) ;
}
V_28 = 0 ;
break;
default:
F_7 ( & V_21 -> V_3 , L_14 ) ;
V_28 = - V_53 ;
break;
}
return V_28 ;
}
static T_4 F_8 ( struct V_20 * V_54 )
{
return V_55 & V_56 ;
}
static int T_5 F_9 ( int V_29 )
{
struct V_4 * V_5 = V_34 + V_29 ;
V_5 -> V_42 = V_42 [ V_29 ] ;
V_5 -> V_15 = V_15 [ V_29 ] ;
V_5 -> V_16 = V_16 [ V_29 ] ;
V_5 -> V_18 = V_16 [ V_29 ] - V_15 [ V_29 ] + 1 ;
V_5 -> V_44 = V_44 [ V_29 ] ;
while ( ! ( V_5 -> V_44 & 1 ) ) {
V_5 -> V_43 ++ ;
V_5 -> V_44 >>= 1 ;
}
V_5 -> V_17 = F_10 ( V_5 -> V_44 * V_5 -> V_18 *
sizeof( T_2 ) , V_10 ) ;
if ( ! V_5 -> V_17 )
return - V_52 ;
F_11 ( L_15 ,
V_5 -> V_44 , V_5 -> V_18 , V_5 -> V_15 ,
V_5 -> V_16 ) ;
return 0 ;
}
static void F_12 ( void )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ )
F_13 ( V_34 [ V_29 ] . V_17 ) ;
F_13 ( V_34 ) ;
}
static int T_5 F_14 ( void )
{
int V_29 , V_28 ;
if ( ! V_33 [ 0 ] ) {
F_15 ( L_16 ) ;
return - V_35 ;
}
for ( V_29 = 0 ; V_29 < V_57 && V_33 [ V_29 ] ; V_29 ++ ) {
if ( V_33 [ V_29 ] < 0x03 || V_33 [ V_29 ] > 0x77 ) {
F_15 ( L_17 ,
V_33 [ V_29 ] ) ;
return - V_51 ;
}
F_16 ( L_18 , V_33 [ V_29 ] ) ;
}
V_32 = V_29 ;
V_34 = F_17 ( V_32 , sizeof( struct V_4 ) ,
V_10 ) ;
if ( ! V_34 )
return - V_52 ;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ ) {
F_18 ( & V_34 [ V_29 ] . V_12 ) ;
if ( V_44 [ V_29 ] ) {
V_28 = F_9 ( V_29 ) ;
if ( V_28 )
goto V_58;
}
}
V_28 = F_19 ( & V_59 ) ;
if ( V_28 )
goto V_58;
return 0 ;
V_58:
F_12 () ;
return V_28 ;
}
static void T_6 F_20 ( void )
{
F_21 ( & V_59 ) ;
F_12 () ;
}
