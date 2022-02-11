static int F_1 ( T_1 V_1 )
{
int V_2 , V_3 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_4 ) ; ++ V_2 ) {
if ( V_1 < V_4 [ V_2 ] [ 0 ] )
break;
for ( V_3 = 0 ; V_3 < V_5 && V_4 [ V_2 ] [ V_3 ] ; ++ V_3 )
if ( V_1 == V_4 [ V_2 ] [ V_3 ] )
return V_2 ;
}
return - 1 ;
}
static int F_3 ( T_1 V_1 , unsigned int V_6 , T_1 V_7 [] )
{
int V_2 , V_3 , V_8 = 0 ;
T_1 V_9 ;
V_7 [ V_8 ++ ] = V_1 ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 >= 0 ) {
for ( V_3 = 0 ; V_3 < V_5 ; ++ V_3 ) {
V_9 = V_4 [ V_2 ] [ V_3 ] ;
if ( V_9 && V_9 != V_1 )
V_7 [ V_8 ++ ] = V_9 ;
}
}
if ( V_6 & V_10 ) {
V_3 = V_8 ;
for ( V_2 = 0 ; V_2 < V_8 ; ++ V_2 ) {
switch ( V_7 [ V_2 ] ) {
case V_11 :
V_7 [ V_3 ++ ] = V_12 ;
break;
case V_12 :
V_7 [ V_3 ++ ] = V_11 ;
break;
case V_13 :
V_7 [ V_3 ++ ] = V_14 ;
break;
case V_14 :
V_7 [ V_3 ++ ] = V_13 ;
break;
}
}
V_8 = V_3 ;
}
return V_8 ;
}
static T_1 F_4 ( T_1 V_15 )
{
T_1 V_16 = 0 ;
if ( V_15 & V_17 )
return V_16 ;
if ( V_15 & V_18 )
return - 1 ;
if ( V_15 & V_19 )
return - 1 ;
if ( V_15 & V_20 )
return - 1 ;
if ( V_15 & V_21 ) {
V_16 |= V_22 ;
return V_16 ;
}
return - 1 ;
}
static void F_5 ( T_1 V_16 )
{
F_6 ( V_23 , ( F_7 ( V_23 ) | V_16 ) ) ;
}
static int T_2 F_8 ( void )
{
int V_24 ;
if ( ! V_25 -> V_26 ||
strcmp ( V_25 -> V_26 , L_1 ) )
return - V_27 ;
V_24 = F_9 ( & V_28 ) ;
if ( V_24 )
return V_24 ;
V_25 -> V_29 |= V_30 ;
if ( F_10 ( V_31 ) )
F_11 ( L_2 ) ;
return 0 ;
}
