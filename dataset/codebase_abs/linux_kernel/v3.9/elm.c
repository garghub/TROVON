static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
void F_5 ( struct V_6 * V_7 , enum V_8 V_9 )
{
T_1 V_10 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
V_10 = ( V_9 & V_11 ) | ( V_12 << 16 ) ;
F_1 ( V_2 , V_13 , V_10 ) ;
V_2 -> V_9 = V_9 ;
}
static void F_7 ( struct V_1 * V_2 , int V_14 ,
bool V_15 )
{
T_1 V_10 ;
V_10 = F_3 ( V_2 , V_16 ) ;
if ( V_15 )
V_10 |= F_8 ( V_14 ) ;
else
V_10 &= ~ F_8 ( V_14 ) ;
F_1 ( V_2 , V_16 , V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_17 * V_18 , T_2 * V_19 )
{
int V_20 , V_3 ;
T_1 V_4 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
if ( V_18 [ V_20 ] . V_22 ) {
F_7 ( V_2 , V_20 , true ) ;
V_3 = V_23 +
V_24 * V_20 ;
if ( V_2 -> V_9 ) {
V_4 = F_10 ( * ( T_1 * ) & V_19 [ 9 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_10 ( * ( T_1 * ) & V_19 [ 5 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_10 ( * ( T_1 * ) & V_19 [ 1 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = V_19 [ 0 ] ;
F_1 ( V_2 , V_3 , V_4 ) ;
} else {
V_4 = ( F_10 ( * ( T_1 * ) & V_19 [ 3 ] ) >> 4 ) |
( ( V_19 [ 2 ] & 0xf ) << 28 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_10 ( * ( T_1 * ) & V_19 [ 0 ] ) >> 12 ;
F_1 ( V_2 , V_3 , V_4 ) ;
}
}
V_19 += V_2 -> V_9 ? V_25 : V_26 ;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_20 , V_3 ;
T_1 V_10 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
if ( V_18 [ V_20 ] . V_22 ) {
V_3 = V_27 +
V_24 * V_20 ;
V_10 = F_3 ( V_2 , V_3 ) ;
V_10 |= V_28 ;
F_1 ( V_2 , V_3 , V_10 ) ;
}
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_20 , V_29 , V_30 = 0 ;
int V_3 ;
T_1 V_10 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
if ( V_18 [ V_20 ] . V_22 ) {
V_3 = V_31 + V_32 * V_20 ;
V_10 = F_3 ( V_2 , V_3 ) ;
if ( V_10 & V_33 ) {
V_3 = V_34 +
V_32 * V_20 ;
V_18 [ V_20 ] . V_35 = V_10 &
V_36 ;
for ( V_29 = 0 ; V_29 < V_18 [ V_20 ] . V_35 ; V_29 ++ ) {
V_10 = F_3 ( V_2 , V_3 ) ;
V_18 [ V_20 ] . V_37 [ V_29 ] = V_10 &
V_38 ;
V_3 += 4 ;
}
V_30 += V_18 [ V_20 ] . V_35 ;
} else {
V_18 [ V_20 ] . V_39 = true ;
}
F_1 ( V_2 , V_40 , F_8 ( V_20 ) ) ;
F_7 ( V_2 , V_20 , false ) ;
}
}
}
void F_13 ( struct V_6 * V_7 , T_2 * V_41 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_10 ;
V_10 = F_3 ( V_2 , V_40 ) ;
F_1 ( V_2 , V_40 , V_10 & V_42 ) ;
F_1 ( V_2 , V_43 , V_44 ) ;
F_9 ( V_2 , V_18 , V_41 ) ;
F_11 ( V_2 , V_18 ) ;
F_14 ( & V_2 -> V_45 ) ;
V_10 = F_3 ( V_2 , V_43 ) ;
F_1 ( V_2 , V_43 , V_10 & ~ V_44 ) ;
F_12 ( V_2 , V_18 ) ;
}
static T_3 F_15 ( int V_46 , void * V_47 )
{
T_1 V_10 ;
struct V_1 * V_2 = V_47 ;
V_10 = F_3 ( V_2 , V_40 ) ;
if ( V_10 & V_42 ) {
F_1 ( V_2 , V_40 ,
V_10 & V_42 ) ;
F_16 ( & V_2 -> V_45 ) ;
return V_48 ;
}
return V_49 ;
}
static int F_17 ( struct V_50 * V_51 )
{
int V_52 = 0 ;
struct V_53 * V_54 , * V_55 ;
struct V_1 * V_2 ;
V_2 = F_18 ( & V_51 -> V_7 , sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 ) {
F_19 ( & V_51 -> V_7 , L_1 ) ;
return - V_57 ;
}
V_2 -> V_7 = & V_51 -> V_7 ;
V_55 = F_20 ( V_51 , V_58 , 0 ) ;
if ( ! V_55 ) {
F_19 ( & V_51 -> V_7 , L_2 ) ;
return - V_59 ;
}
V_54 = F_20 ( V_51 , V_60 , 0 ) ;
if ( ! V_54 ) {
F_19 ( & V_51 -> V_7 , L_3 ) ;
return - V_59 ;
}
V_2 -> V_5 = F_21 ( & V_51 -> V_7 , V_54 ) ;
if ( ! V_2 -> V_5 )
return - V_61 ;
V_52 = F_22 ( & V_51 -> V_7 , V_55 -> V_62 , F_15 , 0 ,
V_51 -> V_63 , V_2 ) ;
if ( V_52 ) {
F_19 ( & V_51 -> V_7 , L_4 , V_55 -> V_62 ) ;
return V_52 ;
}
F_23 ( & V_51 -> V_7 ) ;
if ( F_24 ( & V_51 -> V_7 ) ) {
V_52 = - V_64 ;
F_25 ( & V_51 -> V_7 ) ;
F_19 ( & V_51 -> V_7 , L_5 ) ;
return V_52 ;
}
F_26 ( & V_2 -> V_45 ) ;
F_27 ( & V_2 -> V_65 ) ;
F_28 ( & V_2 -> V_65 , & V_66 ) ;
F_29 ( V_51 , V_2 ) ;
return V_52 ;
}
static int F_30 ( struct V_50 * V_51 )
{
F_31 ( & V_51 -> V_7 ) ;
F_25 ( & V_51 -> V_7 ) ;
F_29 ( V_51 , NULL ) ;
return 0 ;
}
