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
int V_10 ;
int V_29 ;
F_7 ( & V_2 -> V_30 ) ;
V_10 = F_4 ( V_2 , V_25 ) ;
V_29 = V_10 & V_26 ;
V_10 = F_4 ( V_2 , V_31 ) ;
if ( V_29 )
V_10 |= V_32 ;
else
V_10 |= V_33 ;
F_3 ( V_2 , V_31 , V_10 ) ;
F_8 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_10 ;
F_7 ( & V_2 -> V_30 ) ;
V_10 = F_4 ( V_2 , V_31 ) ;
V_10 &= ~ ( V_33 | V_32 ) ;
F_3 ( V_2 , V_31 , V_10 ) ;
F_8 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_34 ;
int V_9 ;
T_2 V_35 ;
V_35 = V_36 | V_37 | V_38 |
V_39 | V_40 ;
V_34 = F_4 ( V_2 , V_41 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 & V_42 )
V_35 |= V_43 ;
if ( V_34 & V_44 )
V_35 |= V_45 ;
if ( V_34 & V_46 )
V_35 |= V_47 ;
if ( V_34 & V_48 )
V_35 |= V_49 ;
if ( V_34 & V_50 )
V_35 |= V_51 ;
if ( V_34 & V_52 ) {
V_34 = F_4 ( V_2 , V_53 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 & V_54 )
V_35 |= V_55 ;
if ( V_34 & V_56 )
V_35 |= V_57 ;
}
V_2 -> V_28 = V_35 ;
V_2 -> V_58 = V_35 ;
if ( V_2 -> V_59 == V_60 ) {
V_9 = F_3 ( V_2 , V_61 ,
V_62 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_2 , V_63 ,
V_64 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_65 ;
V_65 = F_4 ( V_2 , V_66 ) ;
return ( V_65 < 0 ) ? V_65 : 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_65 ;
int V_10 ;
V_10 = F_4 ( V_2 , V_67 ) ;
if ( V_2 -> V_68 == V_69 )
V_65 = F_3 ( V_2 , V_67 ,
V_10 | V_70 ) ;
else
V_65 = F_3 ( V_2 , V_67 , 0 ) ;
return V_65 ;
}
static int T_3 F_13 ( void )
{
return F_14 ( V_71 ,
F_15 ( V_71 ) ) ;
}
static void T_4 F_16 ( void )
{
return F_17 ( V_71 ,
F_15 ( V_71 ) ) ;
}
