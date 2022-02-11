static void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
T_2 V_5 = V_2 -> V_6 ;
if ( F_2 ( V_2 -> V_7 ) == V_8 ) {
V_3 [ 0 ] |= F_3 ( V_9 , V_2 -> V_7 & V_10 ) ;
V_3 [ 3 ] |= F_4 ( V_11 ) ;
}
V_3 [ 0 ] |= F_3 ( V_12 , 1 ) ;
V_5 >>= 8 ;
V_3 [ 2 ] |= V_13 | F_3 ( V_14 , V_5 ) ;
V_5 >>= 27 ;
V_3 [ 3 ] |= F_3 ( V_15 , V_2 -> V_16 )
| V_17
| F_3 ( V_18 , V_5 ) ;
V_3 [ 4 ] |= F_3 ( V_19 , 1 ) ;
V_3 [ 5 ] |= F_4 ( V_20 ) | F_4 ( V_21 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
bool V_22 ;
T_1 V_23 ;
V_22 = F_6 ( V_2 -> V_7 ) ;
V_23 = ( V_22 ) ? V_24 : V_25 ;
V_3 [ 4 ] |= F_3 ( V_26 , V_23 ) ;
if ( V_22 )
V_3 [ 3 ] |= F_3 ( V_27 , V_28 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
V_3 [ 3 ] |= V_29 ;
V_3 [ 4 ] |= F_3 ( V_30 , 0x7 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
T_1 V_31 , T_1 V_32 )
{
struct V_33 * V_34 = F_9 ( V_2 -> V_35 ) ;
F_10 ( V_32 , V_34 -> V_36 + V_31 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_9 ( V_2 -> V_35 ) ;
int V_37 ;
F_8 ( V_2 , V_38 , V_2 -> V_39 ) ;
for ( V_37 = 0 ; V_37 < V_34 -> V_40 -> V_41 ; V_37 ++ ) {
F_8 ( V_2 , V_42 + ( V_37 * 4 ) ,
V_2 -> V_4 [ V_37 ] ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
F_11 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
enum V_43 V_44 ;
F_5 ( V_2 ) ;
V_44 = F_2 ( V_2 -> V_7 ) ;
if ( V_44 == V_45 || V_44 == V_46 )
F_7 ( V_2 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_47 , V_48 ;
bool V_22 ;
if ( F_2 ( V_2 -> V_7 ) == V_8 )
return;
V_22 = F_6 ( V_2 -> V_7 ) ;
V_47 = V_2 -> V_7 & F_15 ( 9 , 0 ) ;
V_47 |= V_49 ;
V_48 = ( V_2 -> V_39 << 9 ) & F_15 ( 18 , 9 ) ;
V_48 |= V_50 ;
if ( V_22 )
V_48 |= V_51 ;
F_8 ( V_2 , V_52 , V_47 ) ;
F_8 ( V_2 , V_53 , V_48 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_54 ;
V_54 = V_2 -> V_7 | V_49 ;
F_8 ( V_2 , V_52 , V_54 ) ;
F_8 ( V_2 , V_53 , 0 ) ;
}
static struct V_1 * F_17 (
struct V_1 * V_2 )
{
bool V_22 ;
T_1 V_5 , V_37 ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
V_2 -> V_55 = F_18 ( V_2 -> V_7 , V_2 -> V_56 ) ;
V_22 = F_6 ( V_2 -> V_7 ) ;
if ( V_22 || F_2 ( V_2 -> V_7 ) != V_8 )
return V_2 ;
V_5 = V_57 + ( 4 * ( V_2 -> V_7 & V_10 ) ) ;
F_8 ( V_2 , V_5 , V_2 -> V_58 >> 10 ) ;
for ( V_37 = 0 ; V_37 < V_2 -> V_55 ; V_37 ++ )
F_19 ( & V_2 -> V_59 [ V_37 ] ) ;
return V_2 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_60 )
{
T_1 V_32 = 0 ;
if ( F_2 ( V_2 -> V_7 ) == V_8 ) {
V_32 = F_3 ( V_9 , V_2 -> V_7 & V_10 ) |
V_61 ;
}
V_32 |= ( V_60 & F_15 ( 16 , 0 ) ) ;
F_10 ( V_32 , V_2 -> V_62 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
T_1 T_3 * V_63 = V_2 -> V_63 ;
T_1 V_64 , V_65 ;
V_64 = F_23 ( & V_63 [ 1 ] ) ;
V_65 = F_24 ( V_66 , V_64 ) ;
return V_65 ;
}
