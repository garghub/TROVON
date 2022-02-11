static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
const T_1 * V_8 ;
int V_9 ;
T_2 V_10 ;
unsigned int V_11 , V_12 [] = {
V_13 ,
V_14 ,
V_15 ,
} ;
if ( ! V_6 )
return - V_16 ;
if ( V_4 -> V_17 & V_18 ) {
V_8 = ( const T_1 * ) V_6 -> V_19 ;
if ( ! F_2 ( V_8 ) )
return - V_20 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
F_3 ( V_2 , V_21 ,
V_22 ) ;
F_3 ( V_2 , V_23 ,
V_12 [ V_11 ] ) ;
F_3 ( V_2 , V_21 ,
V_24 ) ;
F_3 ( V_2 , V_23 ,
V_8 [ ( V_11 * 2 ) + 1 ] | ( V_8 [ ( V_11 * 2 ) ] << 8 ) ) ;
}
V_10 = F_4 ( V_2 , V_25 ) ;
V_10 |= V_26 ;
V_9 = F_3 ( V_2 , V_25 , V_10 ) ;
if ( V_9 )
return V_9 ;
V_10 = F_4 ( V_2 , V_27 ) ;
} else {
V_10 = F_4 ( V_2 , V_25 ) ;
V_10 &= ( ~ V_26 ) ;
V_9 = F_3 ( V_2 , V_25 , V_10 ) ;
if ( V_9 )
return V_9 ;
V_10 = F_4 ( V_2 , V_27 ) ;
}
return V_9 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_10 ;
V_4 -> V_28 = V_18 ;
V_4 -> V_17 = 0 ;
V_10 = F_4 ( V_2 , V_25 ) ;
if ( V_10 & V_26 )
V_4 -> V_17 |= V_18 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_29 ;
int V_9 ;
T_2 V_30 ;
V_30 = V_31 | V_32 | V_33 |
V_34 | V_35 ;
V_29 = F_4 ( V_2 , V_36 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_29 & V_37 )
V_30 |= V_38 ;
if ( V_29 & V_39 )
V_30 |= V_40 ;
if ( V_29 & V_41 )
V_30 |= V_42 ;
if ( V_29 & V_43 )
V_30 |= V_44 ;
if ( V_29 & V_45 )
V_30 |= V_46 ;
if ( V_29 & V_47 ) {
V_29 = F_4 ( V_2 , V_48 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_29 & V_49 )
V_30 |= V_50 ;
if ( V_29 & V_51 )
V_30 |= V_52 ;
}
V_2 -> V_28 = V_30 ;
V_2 -> V_53 = V_30 ;
if ( V_2 -> V_54 == V_55 ) {
V_9 = F_3 ( V_2 , V_56 ,
V_57 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_2 , V_58 ,
V_59 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int T_3 F_7 ( void )
{
return F_8 ( V_60 ,
F_9 ( V_60 ) ) ;
}
static void T_4 F_10 ( void )
{
return F_11 ( V_60 ,
F_9 ( V_60 ) ) ;
}
