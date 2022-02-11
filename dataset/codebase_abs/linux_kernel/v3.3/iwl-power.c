static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 , int V_7 )
{
const struct V_8 * V_9 ;
int V_10 [ V_11 ] = { 0 } ;
int V_12 ;
T_1 V_13 ;
T_2 V_14 ;
if ( F_2 ( V_2 ) -> V_15 ) {
V_9 = V_16 ;
if ( V_7 <= V_17 )
V_9 = V_18 ;
if ( V_7 <= V_19 )
V_9 = V_20 ;
} else {
V_9 = V_21 ;
if ( V_7 <= V_17 )
V_9 = V_22 ;
if ( V_7 <= V_19 )
V_9 = V_23 ;
}
if ( F_3 ( V_6 < 0 || V_6 >= V_24 ) )
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
else
* V_4 = V_9 [ V_6 ] . V_4 ;
if ( V_7 == 0 ) {
V_13 = 0 ;
V_7 = 1 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_10 [ V_12 ] = 1 ;
} else {
V_13 = V_9 [ V_6 ] . V_25 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_10 [ V_12 ] = F_4 ( V_4 -> V_26 [ V_12 ] ) ;
V_10 [ V_11 - 1 ] = V_13 + 1 ;
}
V_14 = F_4 ( V_4 -> V_26 [ V_11 - 1 ] ) ;
if ( V_14 == 0xFF )
V_4 -> V_26 [ V_11 - 1 ] =
F_5 ( V_7 * ( V_13 + 1 ) ) ;
V_14 = F_4 ( V_4 -> V_26 [ V_11 - 1 ] ) ;
if ( V_14 > V_7 )
V_4 -> V_26 [ V_11 - 1 ] =
F_5 ( ( V_14 / V_7 ) * V_7 ) ;
if ( V_13 )
V_4 -> V_27 |= V_28 ;
else
V_4 -> V_27 &= ~ V_28 ;
if ( F_6 ( V_2 ) . V_29 )
V_4 -> V_27 |= V_30 ;
else
V_4 -> V_27 &= ~ V_30 ;
if ( F_7 ( V_2 ) ) {
if ( ! F_2 ( V_2 ) -> V_31 -> V_32 )
V_4 -> V_27 |= V_33 ;
else
V_4 -> V_27 &= ~ V_33 ;
}
V_14 = F_4 ( V_4 -> V_26 [ V_11 - 1 ] ) ;
if ( V_14 > V_34 )
V_4 -> V_26 [ V_11 - 1 ] =
F_5 ( V_34 ) ;
for ( V_12 = V_11 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( F_4 ( V_4 -> V_26 [ V_12 ] ) >
( V_10 [ V_12 ] * V_7 ) )
V_4 -> V_26 [ V_12 ] =
F_5 ( V_10 [ V_12 ] * V_7 ) ;
if ( V_12 != ( V_11 - 1 ) ) {
if ( F_4 ( V_4 -> V_26 [ V_12 ] ) >
F_4 ( V_4 -> V_26 [ V_12 + 1 ] ) )
V_4 -> V_26 [ V_12 ] =
V_4 -> V_26 [ V_12 + 1 ] ;
}
}
if ( V_2 -> V_35 . V_36 )
V_4 -> V_27 |= V_37 ;
else
V_4 -> V_27 &= ~ V_37 ;
F_8 ( V_2 , L_1 ,
V_13 , V_7 ) ;
F_8 ( V_2 , L_2 , V_6 + 1 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
if ( V_2 -> V_35 . V_36 )
V_4 -> V_27 |= V_37 ;
F_8 ( V_2 , L_3 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_38 , int V_39 )
{
static const T_1 V_40 [ V_11 ] = { 2 , 2 , 2 , 2 , 2 } ;
static const T_1 V_41 [ V_11 ] = { 2 , 4 , 6 , 7 , 9 } ;
static const T_1 V_42 [ V_11 ] = { 2 , 7 , 9 , 9 , 0xFF } ;
const T_1 * V_43 = V_40 ;
int V_12 ;
if ( V_39 > V_19 )
V_43 = V_41 ;
if ( V_39 > V_17 )
V_43 = V_42 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_27 = V_44 |
V_45 ;
if ( V_2 -> V_35 . V_36 )
V_4 -> V_27 |= V_37 ;
if ( F_6 ( V_2 ) . V_29 )
V_4 -> V_27 |= V_30 ;
else
V_4 -> V_27 &= ~ V_30 ;
if ( F_7 ( V_2 ) ) {
if ( ! F_2 ( V_2 ) -> V_31 -> V_32 )
V_4 -> V_27 |= V_33 ;
else
V_4 -> V_27 &= ~ V_33 ;
}
V_4 -> V_46 = F_5 ( 1000 * V_38 ) ;
V_4 -> V_47 = F_5 ( 1000 * V_38 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_4 -> V_26 [ V_12 ] =
F_5 ( F_11 ( int , V_43 [ V_12 ] , V_39 ) ) ;
F_8 ( V_2 , L_4 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_8 ( V_2 , L_5 ) ;
F_8 ( V_2 , L_6 , V_4 -> V_27 ) ;
F_8 ( V_2 , L_7 , F_4 ( V_4 -> V_47 ) ) ;
F_8 ( V_2 , L_8 , F_4 ( V_4 -> V_46 ) ) ;
F_8 ( V_2 , L_9 ,
F_4 ( V_4 -> V_26 [ 0 ] ) ,
F_4 ( V_4 -> V_26 [ 1 ] ) ,
F_4 ( V_4 -> V_26 [ 2 ] ) ,
F_4 ( V_4 -> V_26 [ 3 ] ) ,
F_4 ( V_4 -> V_26 [ 4 ] ) ) ;
return F_13 ( F_14 ( V_2 ) , V_48 , V_49 ,
sizeof( struct V_3 ) , V_4 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_50 = V_2 -> V_51 -> V_52 . V_27 & V_53 ;
int V_54 ;
V_54 = V_2 -> V_51 -> V_52 . V_55 ? : 1 ;
if ( V_2 -> V_56 -> V_57 )
F_1 ( V_2 , V_4 , V_58 , V_54 ) ;
else if ( ! F_2 ( V_2 ) -> V_59 -> V_60 &&
V_2 -> V_51 -> V_52 . V_27 & V_61 )
F_1 ( V_2 , V_4 , V_58 , 20 ) ;
else if ( F_16 ( V_2 ) ) {
F_1 ( V_2 , V_4 ,
F_17 ( V_2 ) , V_54 ) ;
} else if ( ! V_50 )
F_9 ( V_2 , V_4 ) ;
else if ( V_2 -> V_35 . V_62 >= 0 )
F_1 ( V_2 , V_4 ,
V_2 -> V_35 . V_62 ,
V_54 ) ;
else if ( V_63 . V_64 ) {
if ( V_63 . V_65 > V_66 &&
V_63 . V_65 <= V_58 )
F_1 ( V_2 , V_4 ,
V_63 . V_65 , V_54 ) ;
else
F_1 ( V_2 , V_4 ,
V_66 , V_54 ) ;
} else
F_10 ( V_2 , V_4 ,
V_2 -> V_51 -> V_52 . V_67 ,
V_2 -> V_51 -> V_52 . V_68 ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool V_69 )
{
int V_70 ;
bool V_71 ;
F_19 ( & V_2 -> V_56 -> V_72 ) ;
V_71 = V_2 -> V_73 . V_74 == V_75 ||
V_2 -> V_73 . V_74 == V_76 ;
if ( ! memcmp ( & V_2 -> V_35 . V_77 , V_4 , sizeof( * V_4 ) ) && ! V_69 )
return 0 ;
if ( ! F_20 ( V_2 -> V_56 ) )
return - V_78 ;
memcpy ( & V_2 -> V_35 . V_79 , V_4 , sizeof( * V_4 ) ) ;
if ( F_21 ( V_80 , & V_2 -> V_56 -> V_81 ) && ! V_69 ) {
F_22 ( V_2 , L_10 ) ;
return 0 ;
}
if ( V_4 -> V_27 & V_44 )
F_23 ( V_82 , & V_2 -> V_56 -> V_81 ) ;
V_70 = F_12 ( V_2 , V_4 ) ;
if ( ! V_70 ) {
if ( ! ( V_4 -> V_27 & V_44 ) )
F_24 ( V_82 , & V_2 -> V_56 -> V_81 ) ;
if ( V_71 )
F_25 ( V_2 ) ;
else
F_8 ( V_2 ,
L_11
L_12 ,
V_2 -> V_73 . V_74 ) ;
memcpy ( & V_2 -> V_35 . V_77 , V_4 , sizeof( * V_4 ) ) ;
} else
F_26 ( V_2 , L_13 , V_70 ) ;
return V_70 ;
}
int F_27 ( struct V_1 * V_2 , bool V_69 )
{
struct V_3 V_4 ;
F_15 ( V_2 , & V_4 ) ;
return F_18 ( V_2 , & V_4 , V_69 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_35 . V_36 = F_29 ( F_30 ( V_2 ) ) ;
V_2 -> V_35 . V_62 = - 1 ;
memset ( & V_2 -> V_35 . V_77 , 0 ,
sizeof( V_2 -> V_35 . V_77 ) ) ;
}
