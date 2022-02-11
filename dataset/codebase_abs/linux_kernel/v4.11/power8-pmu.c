static int F_1 ( T_1 V_1 , unsigned int V_2 , T_1 V_3 [] )
{
int V_4 , V_5 , V_6 = 0 ;
V_6 = F_2 ( V_1 , V_3 , V_7 ,
( int ) F_3 ( V_7 ) ) ;
if ( V_2 & V_8 ) {
V_5 = V_6 ;
for ( V_4 = 0 ; V_4 < V_6 ; ++ V_4 ) {
switch ( V_3 [ V_4 ] ) {
case V_9 :
V_3 [ V_5 ++ ] = V_10 ;
break;
case V_10 :
V_3 [ V_5 ++ ] = V_9 ;
break;
case V_11 :
V_3 [ V_5 ++ ] = V_12 ;
break;
case V_12 :
V_3 [ V_5 ++ ] = V_11 ;
break;
}
}
V_6 = V_5 ;
}
return V_6 ;
}
static T_1 F_4 ( T_1 V_13 )
{
T_1 V_14 = 0 ;
if ( V_13 & V_15 )
return V_14 ;
if ( V_13 & V_16 )
return - 1 ;
if ( V_13 & V_17 )
return - 1 ;
if ( V_13 & V_18 )
return - 1 ;
if ( V_13 & V_19 ) {
V_14 |= V_20 ;
return V_14 ;
}
return - 1 ;
}
static void F_5 ( T_1 V_14 )
{
F_6 ( V_21 , ( F_7 ( V_21 ) | V_14 ) ) ;
}
static int T_2 F_8 ( void )
{
int V_22 ;
if ( ! V_23 -> V_24 ||
strcmp ( V_23 -> V_24 , L_1 ) )
return - V_25 ;
V_22 = F_9 ( & V_26 ) ;
if ( V_22 )
return V_22 ;
V_23 -> V_27 |= V_28 ;
if ( F_10 ( V_29 ) )
F_11 ( L_2 ) ;
return 0 ;
}
