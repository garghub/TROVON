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
if ( V_2 -> V_30 -> V_31 -> V_32 )
V_4 -> V_28 |= V_33 ;
else
V_4 -> V_28 &= ~ V_33 ;
if ( F_5 ( V_2 ) ) {
if ( ! V_2 -> V_15 -> V_34 -> V_35 )
V_4 -> V_28 |= V_36 ;
else
V_4 -> V_28 &= ~ V_36 ;
}
V_14 = F_3 ( V_4 -> V_27 [ V_11 - 1 ] ) ;
if ( V_14 > V_37 )
V_4 -> V_27 [ V_11 - 1 ] =
F_4 ( V_37 ) ;
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
if ( V_2 -> V_38 . V_39 )
V_4 -> V_28 |= V_40 ;
else
V_4 -> V_28 &= ~ V_40 ;
F_6 ( V_2 , L_1 ,
V_13 , V_7 ) ;
F_6 ( V_2 , L_2 , V_6 + 1 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
if ( V_2 -> V_38 . V_39 )
V_4 -> V_28 |= V_40 ;
F_6 ( V_2 , L_3 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_6 ( V_2 , L_4 ) ;
F_6 ( V_2 , L_5 , V_4 -> V_28 ) ;
F_6 ( V_2 , L_6 , F_3 ( V_4 -> V_41 ) ) ;
F_6 ( V_2 , L_7 , F_3 ( V_4 -> V_42 ) ) ;
F_6 ( V_2 , L_8 ,
F_3 ( V_4 -> V_27 [ 0 ] ) ,
F_3 ( V_4 -> V_27 [ 1 ] ) ,
F_3 ( V_4 -> V_27 [ 2 ] ) ,
F_3 ( V_4 -> V_27 [ 3 ] ) ,
F_3 ( V_4 -> V_27 [ 4 ] ) ) ;
return F_9 ( V_2 , V_43 , 0 ,
sizeof( struct V_3 ) , V_4 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_44 = V_2 -> V_45 -> V_46 . V_28 & V_47 ;
int V_48 ;
if ( V_49 ) {
F_7 ( V_2 , V_4 ) ;
return;
}
V_48 = V_2 -> V_45 -> V_46 . V_50 ? : 1 ;
if ( V_2 -> V_51 )
F_1 ( V_2 , V_4 , V_52 , V_48 ) ;
else if ( ! V_2 -> V_15 -> V_53 &&
V_2 -> V_45 -> V_46 . V_28 & V_54 )
F_1 ( V_2 , V_4 , V_52 , 20 ) ;
else if ( F_11 ( V_2 ) ) {
F_1 ( V_2 , V_4 ,
F_12 ( V_2 ) , V_48 ) ;
} else if ( ! V_44 )
F_7 ( V_2 , V_4 ) ;
else if ( V_2 -> V_38 . V_55 >= 0 )
F_1 ( V_2 , V_4 ,
V_2 -> V_38 . V_55 ,
V_48 ) ;
else {
if ( V_56 . V_57 > V_58 &&
V_56 . V_57 <= V_25 )
F_1 ( V_2 , V_4 ,
V_56 . V_57 - 1 , V_48 ) ;
else
F_1 ( V_2 , V_4 ,
V_58 , V_48 ) ;
}
}
int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool V_59 )
{
int V_60 ;
bool V_61 ;
F_14 ( & V_2 -> V_62 ) ;
V_61 = V_2 -> V_63 . V_64 == V_65 ||
V_2 -> V_63 . V_64 == V_66 ;
if ( ! memcmp ( & V_2 -> V_38 . V_67 , V_4 , sizeof( * V_4 ) ) && ! V_59 )
return 0 ;
if ( ! F_15 ( V_2 ) )
return - V_68 ;
memcpy ( & V_2 -> V_38 . V_69 , V_4 , sizeof( * V_4 ) ) ;
if ( F_16 ( V_70 , & V_2 -> V_71 ) && ! V_59 ) {
F_17 ( V_2 , L_9 ) ;
return 0 ;
}
if ( V_4 -> V_28 & V_72 )
F_18 ( V_2 , true ) ;
V_60 = F_8 ( V_2 , V_4 ) ;
if ( ! V_60 ) {
if ( ! ( V_4 -> V_28 & V_72 ) )
F_18 ( V_2 , false ) ;
if ( V_61 )
F_19 ( V_2 ) ;
else
F_6 ( V_2 ,
L_10
L_11 ,
V_2 -> V_63 . V_64 ) ;
memcpy ( & V_2 -> V_38 . V_67 , V_4 , sizeof( * V_4 ) ) ;
} else
F_20 ( V_2 , L_12 , V_60 ) ;
return V_60 ;
}
int F_21 ( struct V_1 * V_2 , bool V_59 )
{
struct V_3 V_4 ;
F_10 ( V_2 , & V_4 ) ;
return F_13 ( V_2 , & V_4 , V_59 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
V_2 -> V_38 . V_39 = V_2 -> V_73 -> V_74 ;
V_2 -> V_38 . V_55 = - 1 ;
memset ( & V_2 -> V_38 . V_67 , 0 ,
sizeof( V_2 -> V_38 . V_67 ) ) ;
}
