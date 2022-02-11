static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = F_2 ( V_2 , V_6 ) ;
V_4 -> V_7 = F_2 ( V_2 , V_8 ) ;
V_4 -> V_9 = F_2 ( V_2 , V_10 ) ;
V_4 -> V_11 = F_2 ( V_2 , V_12 ) ;
V_4 -> V_13 = F_2 ( V_2 , V_14 ) ;
V_4 -> V_15 = F_2 ( V_2 , V_16 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
F_4 ( V_2 , V_6 , V_4 -> V_5 ) ;
F_4 ( V_2 , V_8 , V_4 -> V_7 ) ;
F_4 ( V_2 , V_10 , V_4 -> V_9 ) ;
F_4 ( V_2 , V_12 , V_4 -> V_11 ) ;
F_4 ( V_2 , V_14 , V_4 -> V_13 ) ;
F_4 ( V_2 , V_16 , V_4 -> V_15 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
const T_1 * V_22 ;
int V_23 ;
T_2 V_24 ;
unsigned int V_25 , V_26 [] = {
V_27 ,
V_28 ,
V_29 ,
} ;
if ( ! V_20 )
return - V_30 ;
if ( V_18 -> V_31 & V_32 ) {
V_22 = ( const T_1 * ) V_20 -> V_33 ;
if ( ! F_6 ( V_22 ) )
return - V_34 ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ ) {
F_4 ( V_2 , V_35 ,
V_36 ) ;
F_4 ( V_2 , V_37 ,
V_26 [ V_25 ] ) ;
F_4 ( V_2 , V_35 ,
V_38 ) ;
F_4 ( V_2 , V_37 ,
V_22 [ ( V_25 * 2 ) + 1 ] | ( V_22 [ ( V_25 * 2 ) ] << 8 ) ) ;
}
V_24 = F_2 ( V_2 , V_12 ) ;
V_24 |= V_39 ;
V_23 = F_4 ( V_2 , V_12 , V_24 ) ;
if ( V_23 )
return V_23 ;
V_24 = F_2 ( V_2 , V_40 ) ;
} else {
V_24 = F_2 ( V_2 , V_12 ) ;
V_24 &= ( ~ V_39 ) ;
V_23 = F_4 ( V_2 , V_12 , V_24 ) ;
if ( V_23 )
return V_23 ;
V_24 = F_2 ( V_2 , V_40 ) ;
}
return V_23 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
T_2 V_24 ;
V_18 -> V_41 = V_32 ;
V_18 -> V_31 = 0 ;
V_24 = F_2 ( V_2 , V_12 ) ;
if ( V_24 & V_39 )
V_18 -> V_31 |= V_32 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_24 ;
int V_42 ;
F_9 ( & V_2 -> V_43 ) ;
V_24 = F_2 ( V_2 , V_12 ) ;
V_42 = V_24 & V_39 ;
V_24 = F_2 ( V_2 , V_6 ) ;
if ( V_42 )
V_24 |= V_44 ;
else
V_24 |= V_45 ;
F_4 ( V_2 , V_6 , V_24 ) ;
F_10 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_24 ;
F_9 ( & V_2 -> V_43 ) ;
V_24 = F_2 ( V_2 , V_6 ) ;
V_24 &= ~ ( V_45 | V_44 ) ;
F_4 ( V_2 , V_6 , V_24 ) ;
F_10 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = & V_2 -> V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
V_49 = F_13 ( V_47 , sizeof( * V_49 ) , V_52 ) ;
if ( ! V_49 )
return - V_53 ;
V_51 = F_14 ( V_47 , L_1 , V_54 ) ;
if ( F_15 ( V_51 ) )
return F_16 ( V_51 ) ;
V_49 -> V_51 = V_51 ;
V_2 -> V_49 = V_49 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_23 ;
V_23 = F_18 ( V_2 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_2 -> V_55 == V_56 ) {
V_23 = F_4 ( V_2 , V_57 ,
V_58 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_4 ( V_2 , V_59 ,
V_60 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_61 ;
V_61 = F_2 ( V_2 , V_62 ) ;
return ( V_61 < 0 ) ? V_61 : 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_61 ;
int V_24 ;
V_24 = F_2 ( V_2 , V_63 ) ;
if ( V_2 -> V_64 == V_65 )
V_61 = F_4 ( V_2 , V_63 ,
V_24 | V_66 ) ;
else
V_61 = F_4 ( V_2 , V_63 , 0 ) ;
return V_61 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
if ( V_2 -> V_67 -> V_68 == V_69 ) {
if ( V_2 -> V_70 == V_71 ) {
if ( V_49 -> V_51 && ! V_49 -> V_72 ) {
struct V_3 V_4 ;
F_1 ( V_2 , & V_4 ) ;
F_22 ( V_49 -> V_51 , 0 ) ;
F_23 ( 1 ) ;
F_22 ( V_49 -> V_51 , 1 ) ;
F_23 ( 1 ) ;
F_3 ( V_2 , & V_4 ) ;
F_24 ( & V_2 -> V_47 , L_2 ,
V_73 ) ;
V_49 -> V_72 = true ;
}
} else {
V_49 -> V_72 = false ;
}
}
}
