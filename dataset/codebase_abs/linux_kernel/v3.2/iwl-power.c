static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 , int V_7 )
{
const struct V_8 * V_9 ;
int V_10 [ V_11 ] = { 0 } ;
int V_12 ;
T_1 V_13 ;
T_2 V_14 ;
if ( V_2 -> V_15 -> V_16 ) {
V_9 = V_17 ;
if ( V_7 <= V_18 )
V_9 = V_19 ;
if ( V_7 <= V_20 )
V_9 = V_21 ;
} else {
V_9 = V_22 ;
if ( V_7 <= V_18 )
V_9 = V_23 ;
if ( V_7 <= V_20 )
V_9 = V_24 ;
}
if ( F_2 ( V_6 < 0 || V_6 >= V_25 ) )
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
else
* V_4 = V_9 [ V_6 ] . V_4 ;
if ( V_7 == 0 ) {
V_13 = 0 ;
V_7 = 1 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_10 [ V_12 ] = 1 ;
} else {
V_13 = V_9 [ V_6 ] . V_26 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_10 [ V_12 ] = F_3 ( V_4 -> V_27 [ V_12 ] ) ;
V_10 [ V_11 - 1 ] = V_13 + 1 ;
}
V_14 = F_3 ( V_4 -> V_27 [ V_11 - 1 ] ) ;
if ( V_14 == 0xFF )
V_4 -> V_27 [ V_11 - 1 ] =
F_4 ( V_7 * ( V_13 + 1 ) ) ;
V_14 = F_3 ( V_4 -> V_27 [ V_11 - 1 ] ) ;
if ( V_14 > V_7 )
V_4 -> V_27 [ V_11 - 1 ] =
F_4 ( ( V_14 / V_7 ) * V_7 ) ;
if ( V_13 )
V_4 -> V_28 |= V_29 ;
else
V_4 -> V_28 &= ~ V_29 ;
if ( F_5 ( V_2 ) . V_30 )
V_4 -> V_28 |= V_31 ;
else
V_4 -> V_28 &= ~ V_31 ;
if ( F_6 ( V_2 ) ) {
if ( ! V_2 -> V_15 -> V_32 -> V_33 )
V_4 -> V_28 |= V_34 ;
else
V_4 -> V_28 &= ~ V_34 ;
}
V_14 = F_3 ( V_4 -> V_27 [ V_11 - 1 ] ) ;
if ( V_14 > V_35 )
V_4 -> V_27 [ V_11 - 1 ] =
F_4 ( V_35 ) ;
for ( V_12 = V_11 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( F_3 ( V_4 -> V_27 [ V_12 ] ) >
( V_10 [ V_12 ] * V_7 ) )
V_4 -> V_27 [ V_12 ] =
F_4 ( V_10 [ V_12 ] * V_7 ) ;
if ( V_12 != ( V_11 - 1 ) ) {
if ( F_3 ( V_4 -> V_27 [ V_12 ] ) >
F_3 ( V_4 -> V_27 [ V_12 + 1 ] ) )
V_4 -> V_27 [ V_12 ] =
V_4 -> V_27 [ V_12 + 1 ] ;
}
}
if ( V_2 -> V_36 . V_37 )
V_4 -> V_28 |= V_38 ;
else
V_4 -> V_28 &= ~ V_38 ;
F_7 ( V_2 , L_1 ,
V_13 , V_7 ) ;
F_7 ( V_2 , L_2 , V_6 + 1 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
if ( V_2 -> V_36 . V_37 )
V_4 -> V_28 |= V_38 ;
F_7 ( V_2 , L_3 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_39 , int V_40 )
{
static const T_1 V_41 [ V_11 ] = { 2 , 2 , 2 , 2 , 2 } ;
static const T_1 V_42 [ V_11 ] = { 2 , 4 , 6 , 7 , 9 } ;
static const T_1 V_43 [ V_11 ] = { 2 , 7 , 9 , 9 , 0xFF } ;
const T_1 * V_44 = V_41 ;
int V_12 ;
if ( V_40 > V_20 )
V_44 = V_42 ;
if ( V_40 > V_18 )
V_44 = V_43 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_28 = V_45 |
V_46 ;
if ( V_2 -> V_36 . V_37 )
V_4 -> V_28 |= V_38 ;
if ( F_5 ( V_2 ) . V_30 )
V_4 -> V_28 |= V_31 ;
else
V_4 -> V_28 &= ~ V_31 ;
if ( F_6 ( V_2 ) ) {
if ( ! V_2 -> V_15 -> V_32 -> V_33 )
V_4 -> V_28 |= V_34 ;
else
V_4 -> V_28 &= ~ V_34 ;
}
V_4 -> V_47 = F_4 ( 1000 * V_39 ) ;
V_4 -> V_48 = F_4 ( 1000 * V_39 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_4 -> V_27 [ V_12 ] =
F_4 ( F_10 ( int , V_44 [ V_12 ] , V_40 ) ) ;
F_7 ( V_2 , L_4 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_7 ( V_2 , L_5 ) ;
F_7 ( V_2 , L_6 , V_4 -> V_28 ) ;
F_7 ( V_2 , L_7 , F_3 ( V_4 -> V_48 ) ) ;
F_7 ( V_2 , L_8 , F_3 ( V_4 -> V_47 ) ) ;
F_7 ( V_2 , L_9 ,
F_3 ( V_4 -> V_27 [ 0 ] ) ,
F_3 ( V_4 -> V_27 [ 1 ] ) ,
F_3 ( V_4 -> V_27 [ 2 ] ) ,
F_3 ( V_4 -> V_27 [ 3 ] ) ,
F_3 ( V_4 -> V_27 [ 4 ] ) ) ;
return F_12 ( F_13 ( V_2 ) , V_49 , V_50 ,
sizeof( struct V_3 ) , V_4 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_51 = V_2 -> V_52 -> V_53 . V_28 & V_54 ;
int V_55 ;
V_55 = V_2 -> V_52 -> V_53 . V_56 ? : 1 ;
if ( V_2 -> V_57 -> V_58 )
F_1 ( V_2 , V_4 , V_59 , V_55 ) ;
else if ( ! V_2 -> V_15 -> V_60 -> V_61 &&
V_2 -> V_52 -> V_53 . V_28 & V_62 )
F_1 ( V_2 , V_4 , V_59 , 20 ) ;
else if ( F_15 ( V_2 ) ) {
F_1 ( V_2 , V_4 ,
F_16 ( V_2 ) , V_55 ) ;
} else if ( ! V_51 )
F_8 ( V_2 , V_4 ) ;
else if ( V_2 -> V_36 . V_63 >= 0 )
F_1 ( V_2 , V_4 ,
V_2 -> V_36 . V_63 ,
V_55 ) ;
else if ( V_64 . V_65 ) {
if ( V_64 . V_66 > V_67 &&
V_64 . V_66 <= V_59 )
F_1 ( V_2 , V_4 ,
V_64 . V_66 , V_55 ) ;
else
F_1 ( V_2 , V_4 ,
V_67 , V_55 ) ;
} else
F_9 ( V_2 , V_4 ,
V_2 -> V_52 -> V_53 . V_68 ,
V_2 -> V_52 -> V_53 . V_69 ) ;
}
int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool V_70 )
{
int V_71 ;
bool V_72 ;
F_18 ( & V_2 -> V_57 -> V_73 ) ;
V_72 = V_2 -> V_74 . V_75 == V_76 ||
V_2 -> V_74 . V_75 == V_77 ;
if ( ! memcmp ( & V_2 -> V_36 . V_78 , V_4 , sizeof( * V_4 ) ) && ! V_70 )
return 0 ;
if ( ! F_19 ( V_2 -> V_57 ) )
return - V_79 ;
memcpy ( & V_2 -> V_36 . V_80 , V_4 , sizeof( * V_4 ) ) ;
if ( F_20 ( V_81 , & V_2 -> V_57 -> V_82 ) && ! V_70 ) {
F_21 ( V_2 , L_10 ) ;
return 0 ;
}
if ( V_4 -> V_28 & V_45 )
F_22 ( V_83 , & V_2 -> V_57 -> V_82 ) ;
V_71 = F_11 ( V_2 , V_4 ) ;
if ( ! V_71 ) {
if ( ! ( V_4 -> V_28 & V_45 ) )
F_23 ( V_83 , & V_2 -> V_57 -> V_82 ) ;
if ( V_72 )
F_24 ( V_2 ) ;
else
F_7 ( V_2 ,
L_11
L_12 ,
V_2 -> V_74 . V_75 ) ;
memcpy ( & V_2 -> V_36 . V_78 , V_4 , sizeof( * V_4 ) ) ;
} else
F_25 ( V_2 , L_13 , V_71 ) ;
return V_71 ;
}
int F_26 ( struct V_1 * V_2 , bool V_70 )
{
struct V_3 V_4 ;
F_14 ( V_2 , & V_4 ) ;
return F_17 ( V_2 , & V_4 , V_70 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_36 . V_37 = F_28 ( F_29 ( V_2 ) ) ;
V_2 -> V_36 . V_63 = - 1 ;
memset ( & V_2 -> V_36 . V_78 , 0 ,
sizeof( V_2 -> V_36 . V_78 ) ) ;
}
