static T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_2 -> clock == V_4 [ V_3 ] . clock )
break;
}
if ( V_3 == F_2 ( V_4 ) ) {
F_3 ( L_1 , V_2 -> clock ) ;
V_3 = 1 ;
}
F_3 ( L_2 ,
V_4 [ V_3 ] . clock ,
V_4 [ V_3 ] . V_5 ) ;
return V_4 [ V_3 ] . V_5 ;
}
static bool F_4 ( struct V_6 * V_7 ,
int V_8 , T_2 V_9 ,
int V_10 , T_2 V_11 ,
int V_12 )
{
struct V_13 * V_14 = V_7 -> V_15 -> V_16 ;
T_3 * V_17 = V_7 -> V_17 ;
T_2 V_18 ;
int V_3 ;
V_18 = F_5 ( V_8 ) ;
V_18 &= V_9 ;
if ( ! V_18 )
return false ;
V_18 = F_5 ( V_10 ) ;
V_18 &= ~ V_11 ;
F_6 ( V_10 , V_18 ) ;
for ( V_3 = 0 ; V_3 < F_7 ( V_17 ) / 4 ; V_3 ++ )
if ( F_5 ( V_12 ) != * ( ( T_2 * ) V_17 + V_3 ) )
return false ;
return true ;
}
static void F_8 ( struct V_19 * V_20 )
{
struct V_13 * V_14 = V_20 -> V_21 . V_15 -> V_16 ;
T_2 V_22 , V_18 ;
F_3 ( L_3 ) ;
V_18 = F_5 ( V_23 ) ;
if ( V_18 == V_24 || V_18 == V_25 )
V_22 = V_26 ;
else
V_22 = V_27 ;
V_18 = F_5 ( V_28 ) ;
V_18 &= ~ V_22 ;
F_6 ( V_28 , V_18 ) ;
}
static void F_9 ( struct V_6 * V_7 ,
struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_7 -> V_15 -> V_16 ;
T_3 * V_17 = V_7 -> V_17 ;
T_2 V_22 ;
T_2 V_18 ;
int V_29 , V_3 ;
F_3 ( L_4 , V_17 [ 2 ] ) ;
V_18 = F_5 ( V_23 ) ;
if ( V_18 == V_24 || V_18 == V_25 )
V_22 = V_26 ;
else
V_22 = V_27 ;
if ( F_4 ( V_7 ,
V_28 , V_22 ,
V_28 , V_30 ,
V_31 ) )
return;
V_18 = F_5 ( V_28 ) ;
V_18 &= ~ ( V_22 | V_30 ) ;
V_29 = ( V_18 >> 9 ) & 0x1f ;
F_6 ( V_28 , V_18 ) ;
V_29 = F_10 ( F_7 ( V_17 ) / 4 , V_29 ) ;
F_11 ( L_5 , V_29 ) ;
for ( V_3 = 0 ; V_3 < V_29 ; V_3 ++ )
F_6 ( V_31 , * ( ( T_2 * ) V_17 + V_3 ) ) ;
V_18 = F_5 ( V_28 ) ;
V_18 |= V_22 ;
F_6 ( V_28 , V_18 ) ;
}
static void F_12 ( struct V_19 * V_20 )
{
struct V_13 * V_14 = V_20 -> V_21 . V_15 -> V_16 ;
struct V_32 * V_32 = F_13 ( V_20 -> V_21 . V_33 ) ;
enum V_34 V_34 = V_32 -> V_34 ;
T_2 V_18 ;
F_3 ( L_6 , F_14 ( V_34 ) ) ;
V_18 = F_5 ( F_15 ( V_34 ) ) ;
V_18 &= ~ V_35 ;
V_18 |= V_36 ;
V_18 &= ~ V_37 ;
V_18 &= ~ V_38 ;
if ( F_16 ( V_32 , V_39 ) )
V_18 |= V_35 ;
F_6 ( F_15 ( V_34 ) , V_18 ) ;
V_18 = F_5 ( V_40 ) ;
V_18 &= ~ F_17 ( V_34 ) ;
V_18 &= ~ F_18 ( V_34 ) ;
F_6 ( V_40 , V_18 ) ;
}
static void F_19 ( struct V_6 * V_7 ,
struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_7 -> V_15 -> V_16 ;
struct V_32 * V_32 = F_13 ( V_20 -> V_21 . V_33 ) ;
enum V_34 V_34 = V_32 -> V_34 ;
const T_3 * V_17 = V_7 -> V_17 ;
T_2 V_18 ;
int V_29 , V_3 ;
F_3 ( L_7 ,
F_14 ( V_34 ) , F_7 ( V_17 ) ) ;
V_18 = F_5 ( V_40 ) ;
V_18 |= F_18 ( V_34 ) ;
V_18 &= ~ F_17 ( V_34 ) ;
F_6 ( V_40 , V_18 ) ;
V_18 = F_5 ( F_20 ( V_34 ) ) ;
V_18 &= ~ V_41 ;
F_6 ( F_20 ( V_34 ) , V_18 ) ;
V_29 = F_10 ( F_7 ( V_17 ) , 84 ) ;
for ( V_3 = 0 ; V_3 < V_29 / 4 ; V_3 ++ )
F_6 ( F_21 ( V_34 ) , * ( ( T_2 * ) V_17 + V_3 ) ) ;
V_18 = F_5 ( V_40 ) ;
V_18 |= F_17 ( V_34 ) ;
F_6 ( V_40 , V_18 ) ;
V_18 = F_5 ( F_15 ( V_34 ) ) ;
V_18 &= ~ V_35 ;
V_18 &= ~ V_36 ;
V_18 &= ~ V_42 ;
if ( F_16 ( V_32 , V_39 ) )
V_18 |= V_35 ;
else
V_18 |= F_1 ( V_2 ) ;
F_6 ( F_15 ( V_34 ) , V_18 ) ;
}
static void F_22 ( struct V_19 * V_20 )
{
struct V_13 * V_14 = V_20 -> V_21 . V_15 -> V_16 ;
struct V_32 * V_32 = F_13 ( V_20 -> V_21 . V_33 ) ;
struct V_43 * V_44 =
F_23 ( & V_20 -> V_21 ) ;
enum V_45 V_45 = V_44 -> V_45 ;
enum V_34 V_34 = V_32 -> V_34 ;
T_2 V_18 , V_22 ;
int V_46 ;
int V_47 ;
F_3 ( L_8 ,
F_24 ( V_45 ) , F_14 ( V_34 ) ) ;
if ( F_25 ( V_14 -> V_15 ) ) {
V_46 = F_26 ( V_34 ) ;
V_47 = V_48 ;
} else if ( F_27 ( V_14 ) ) {
V_46 = F_28 ( V_34 ) ;
V_47 = V_49 ;
} else {
V_46 = F_29 ( V_34 ) ;
V_47 = V_50 ;
}
V_18 = F_5 ( V_46 ) ;
V_18 &= ~ V_35 ;
V_18 |= V_36 ;
V_18 &= ~ V_37 ;
V_18 &= ~ V_38 ;
if ( F_16 ( V_32 , V_39 ) )
V_18 |= V_35 ;
F_6 ( V_46 , V_18 ) ;
if ( F_30 ( ! V_45 ) ) {
V_22 = F_31 ( V_51 ) | F_31 ( V_52 ) |
F_31 ( V_53 ) ;
} else {
V_22 = F_31 ( V_45 ) ;
}
V_18 = F_5 ( V_47 ) ;
V_18 &= ~ V_22 ;
F_6 ( V_47 , V_18 ) ;
}
static void F_32 ( struct V_6 * V_7 ,
struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_7 -> V_15 -> V_16 ;
struct V_32 * V_32 = F_13 ( V_20 -> V_21 . V_33 ) ;
struct V_43 * V_44 =
F_23 ( & V_20 -> V_21 ) ;
enum V_45 V_45 = V_44 -> V_45 ;
enum V_34 V_34 = V_32 -> V_34 ;
T_3 * V_17 = V_7 -> V_17 ;
T_2 V_22 ;
T_2 V_18 ;
int V_29 , V_3 ;
int V_54 ;
int V_46 ;
int V_55 ;
int V_47 ;
F_3 ( L_9 ,
F_24 ( V_45 ) , F_14 ( V_34 ) , F_7 ( V_17 ) ) ;
if ( F_25 ( V_7 -> V_15 ) ) {
V_54 = F_33 ( V_34 ) ;
V_46 = F_26 ( V_34 ) ;
V_55 = F_34 ( V_34 ) ;
V_47 = V_48 ;
} else if ( F_27 ( V_7 -> V_15 ) ) {
V_54 = F_35 ( V_34 ) ;
V_46 = F_28 ( V_34 ) ;
V_55 = F_36 ( V_34 ) ;
V_47 = V_49 ;
} else {
V_54 = F_37 ( V_34 ) ;
V_46 = F_29 ( V_34 ) ;
V_55 = F_38 ( V_34 ) ;
V_47 = V_50 ;
}
if ( F_30 ( ! V_45 ) ) {
V_22 = F_31 ( V_51 ) | F_31 ( V_52 ) |
F_31 ( V_53 ) ;
} else {
V_22 = F_31 ( V_45 ) ;
}
V_18 = F_5 ( V_47 ) ;
V_18 &= ~ V_22 ;
F_6 ( V_47 , V_18 ) ;
V_18 = F_5 ( V_55 ) ;
V_18 &= ~ V_41 ;
F_6 ( V_55 , V_18 ) ;
V_29 = F_10 ( F_7 ( V_17 ) , 84 ) ;
for ( V_3 = 0 ; V_3 < V_29 / 4 ; V_3 ++ )
F_6 ( V_54 , * ( ( T_2 * ) V_17 + V_3 ) ) ;
V_18 = F_5 ( V_47 ) ;
V_18 |= V_22 ;
F_6 ( V_47 , V_18 ) ;
V_18 = F_5 ( V_46 ) ;
V_18 &= ~ V_35 ;
V_18 &= ~ V_36 ;
V_18 &= ~ V_42 ;
if ( F_16 ( V_32 , V_39 ) )
V_18 |= V_35 ;
else
V_18 |= F_1 ( V_2 ) ;
F_6 ( V_46 , V_18 ) ;
}
void F_39 ( struct V_19 * V_19 )
{
struct V_56 * V_20 = & V_19 -> V_21 ;
struct V_32 * V_33 = F_13 ( V_20 -> V_33 ) ;
struct V_1 * V_2 = & V_33 -> V_5 . V_57 ;
struct V_6 * V_7 ;
struct V_58 * V_15 = V_20 -> V_15 ;
struct V_13 * V_14 = V_15 -> V_16 ;
V_7 = F_40 ( V_20 , V_2 ) ;
if ( ! V_7 )
return;
F_11 ( L_10 ,
V_7 -> V_21 . V_59 ,
V_7 -> V_60 ,
V_7 -> V_20 -> V_21 . V_59 ,
V_7 -> V_20 -> V_60 ) ;
V_7 -> V_17 [ 5 ] &= ~ ( 3 << 2 ) ;
if ( F_16 ( V_33 , V_39 ) )
V_7 -> V_17 [ 5 ] |= ( 1 << 2 ) ;
V_7 -> V_17 [ 6 ] = F_41 ( V_7 , V_2 ) / 2 ;
if ( V_14 -> V_61 . V_62 )
V_14 -> V_61 . V_62 ( V_7 , V_19 , V_2 ) ;
}
void F_42 ( struct V_19 * V_20 )
{
struct V_58 * V_15 = V_20 -> V_21 . V_15 ;
struct V_13 * V_14 = V_15 -> V_16 ;
if ( V_14 -> V_61 . V_63 )
V_14 -> V_61 . V_63 ( V_20 ) ;
}
void F_43 ( struct V_58 * V_15 )
{
struct V_13 * V_14 = V_15 -> V_16 ;
if ( F_44 ( V_15 ) ) {
V_14 -> V_61 . V_62 = F_9 ;
V_14 -> V_61 . V_63 = F_8 ;
} else if ( F_27 ( V_15 ) ) {
V_14 -> V_61 . V_62 = F_32 ;
V_14 -> V_61 . V_63 = F_22 ;
} else if ( F_45 ( V_15 ) || F_46 ( V_15 ) -> V_64 >= 8 ) {
V_14 -> V_61 . V_62 = F_19 ;
V_14 -> V_61 . V_63 = F_12 ;
} else if ( F_47 ( V_15 ) ) {
V_14 -> V_61 . V_62 = F_32 ;
V_14 -> V_61 . V_63 = F_22 ;
}
}
