static bool F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
unsigned int V_7 ;
unsigned int V_8 ;
unsigned int V_9 ;
unsigned int V_10 ;
T_1 V_11 ;
T_2 V_12 ;
T_2 V_13 ;
T_2 V_14 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; ++ V_7 ) {
V_6 = & V_2 -> V_16 [ V_7 ] ;
V_14 = 0 ;
V_12 = V_6 -> V_17 [ 0 ] . V_18 ;
if ( V_4 -> V_19 < 4 || V_12 > V_4 -> V_19 - 4 )
return false ;
if ( F_2 ( V_4 , V_12 , & V_11 , sizeof( V_11 ) ) < 0 )
F_3 () ;
V_13 = F_4 ( V_11 ) ;
V_8 = V_6 -> V_8 ;
for ( V_10 = 1 ; V_10 < V_8 ; ++ V_10 ) {
T_2 V_18 = V_6 -> V_17 [ V_10 ] . V_18 ;
switch ( V_6 -> V_17 [ V_10 ] . V_20 ) {
case V_21 :
V_13 &= V_18 ;
break;
case V_22 :
V_13 <<= V_18 ;
break;
case V_23 :
V_13 >>= V_18 ;
break;
case V_24 :
if ( V_14 + V_13 < V_14 )
return false ;
V_14 += V_13 ;
V_12 = V_18 ;
if ( V_14 + 4 < V_14 || V_4 -> V_19 < V_14 + 4 ||
V_12 > V_4 -> V_19 - V_14 - 4 )
return false ;
if ( F_2 ( V_4 , V_14 + V_12 , & V_11 ,
sizeof( V_11 ) ) < 0 )
F_3 () ;
V_13 = F_4 ( V_11 ) ;
break;
}
}
V_9 = V_6 -> V_25 ;
for ( V_10 = 0 ; V_10 < V_9 ; ++ V_10 )
if ( V_6 -> V_26 [ V_10 ] . V_27 <= V_13 && V_13 <= V_6 -> V_26 [ V_10 ] . V_28 )
break;
if ( V_10 >= V_6 -> V_25 )
return false ;
}
return true ;
}
static bool F_5 ( const struct V_3 * V_4 , struct V_29 * V_30 )
{
const struct V_1 * V_2 = V_30 -> V_31 ;
bool V_32 ;
V_32 = F_1 ( V_2 , V_4 ) ;
return V_32 ^ V_2 -> V_33 ;
}
static int T_3 F_6 ( void )
{
return F_7 ( & V_34 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_34 ) ;
}
