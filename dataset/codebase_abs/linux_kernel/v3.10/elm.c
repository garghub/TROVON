static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
int F_5 ( struct V_6 * V_7 , enum V_8 V_9 )
{
T_1 V_10 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( ! V_2 ) {
F_7 ( V_7 , L_1 ) ;
return - V_11 ;
}
V_10 = ( V_9 & V_12 ) | ( V_13 << 16 ) ;
F_1 ( V_2 , V_14 , V_10 ) ;
V_2 -> V_9 = V_9 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , int V_15 ,
bool V_16 )
{
T_1 V_10 ;
V_10 = F_3 ( V_2 , V_17 ) ;
if ( V_16 )
V_10 |= F_9 ( V_15 ) ;
else
V_10 &= ~ F_9 ( V_15 ) ;
F_1 ( V_2 , V_17 , V_10 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_18 * V_19 , T_2 * V_20 )
{
int V_21 , V_3 ;
T_1 V_4 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_19 [ V_21 ] . V_23 ) {
F_8 ( V_2 , V_21 , true ) ;
V_3 = V_24 +
V_25 * V_21 ;
if ( V_2 -> V_9 ) {
V_4 = F_11 ( * ( T_1 * ) & V_20 [ 9 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_11 ( * ( T_1 * ) & V_20 [ 5 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_11 ( * ( T_1 * ) & V_20 [ 1 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = V_20 [ 0 ] ;
F_1 ( V_2 , V_3 , V_4 ) ;
} else {
V_4 = ( F_11 ( * ( T_1 * ) & V_20 [ 3 ] ) >> 4 ) |
( ( V_20 [ 2 ] & 0xf ) << 28 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_11 ( * ( T_1 * ) & V_20 [ 0 ] ) >> 12 ;
F_1 ( V_2 , V_3 , V_4 ) ;
}
}
V_20 += V_2 -> V_9 ? V_26 : V_27 ;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
int V_21 , V_3 ;
T_1 V_10 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_19 [ V_21 ] . V_23 ) {
V_3 = V_28 +
V_25 * V_21 ;
V_10 = F_3 ( V_2 , V_3 ) ;
V_10 |= V_29 ;
F_1 ( V_2 , V_3 , V_10 ) ;
}
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
int V_21 , V_30 , V_31 = 0 ;
int V_3 ;
T_1 V_10 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_19 [ V_21 ] . V_23 ) {
V_3 = V_32 + V_33 * V_21 ;
V_10 = F_3 ( V_2 , V_3 ) ;
if ( V_10 & V_34 ) {
V_3 = V_35 +
V_33 * V_21 ;
V_19 [ V_21 ] . V_36 = V_10 &
V_37 ;
for ( V_30 = 0 ; V_30 < V_19 [ V_21 ] . V_36 ; V_30 ++ ) {
V_10 = F_3 ( V_2 , V_3 ) ;
V_19 [ V_21 ] . V_38 [ V_30 ] = V_10 &
V_39 ;
V_3 += 4 ;
}
V_31 += V_19 [ V_21 ] . V_36 ;
} else {
V_19 [ V_21 ] . V_40 = true ;
}
F_1 ( V_2 , V_41 , F_9 ( V_21 ) ) ;
F_8 ( V_2 , V_21 , false ) ;
}
}
}
void F_14 ( struct V_6 * V_7 , T_2 * V_42 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_10 ;
V_10 = F_3 ( V_2 , V_41 ) ;
F_1 ( V_2 , V_41 , V_10 & V_43 ) ;
F_1 ( V_2 , V_44 , V_45 ) ;
F_10 ( V_2 , V_19 , V_42 ) ;
F_12 ( V_2 , V_19 ) ;
F_15 ( & V_2 -> V_46 ) ;
V_10 = F_3 ( V_2 , V_44 ) ;
F_1 ( V_2 , V_44 , V_10 & ~ V_45 ) ;
F_13 ( V_2 , V_19 ) ;
}
static T_3 F_16 ( int V_47 , void * V_48 )
{
T_1 V_10 ;
struct V_1 * V_2 = V_48 ;
V_10 = F_3 ( V_2 , V_41 ) ;
if ( V_10 & V_43 ) {
F_1 ( V_2 , V_41 ,
V_10 & V_43 ) ;
F_17 ( & V_2 -> V_46 ) ;
return V_49 ;
}
return V_50 ;
}
static int F_18 ( struct V_51 * V_52 )
{
int V_53 = 0 ;
struct V_54 * V_55 , * V_56 ;
struct V_1 * V_2 ;
V_2 = F_19 ( & V_52 -> V_7 , sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 ) {
F_7 ( & V_52 -> V_7 , L_2 ) ;
return - V_58 ;
}
V_2 -> V_7 = & V_52 -> V_7 ;
V_56 = F_20 ( V_52 , V_59 , 0 ) ;
if ( ! V_56 ) {
F_7 ( & V_52 -> V_7 , L_3 ) ;
return - V_11 ;
}
V_55 = F_20 ( V_52 , V_60 , 0 ) ;
if ( ! V_55 ) {
F_7 ( & V_52 -> V_7 , L_4 ) ;
return - V_11 ;
}
V_2 -> V_5 = F_21 ( & V_52 -> V_7 , V_55 ) ;
if ( ! V_2 -> V_5 )
return - V_61 ;
V_53 = F_22 ( & V_52 -> V_7 , V_56 -> V_62 , F_16 , 0 ,
V_52 -> V_63 , V_2 ) ;
if ( V_53 ) {
F_7 ( & V_52 -> V_7 , L_5 , V_56 -> V_62 ) ;
return V_53 ;
}
F_23 ( & V_52 -> V_7 ) ;
if ( F_24 ( & V_52 -> V_7 ) ) {
V_53 = - V_64 ;
F_25 ( & V_52 -> V_7 ) ;
F_7 ( & V_52 -> V_7 , L_6 ) ;
return V_53 ;
}
F_26 ( & V_2 -> V_46 ) ;
F_27 ( & V_2 -> V_65 ) ;
F_28 ( & V_2 -> V_65 , & V_66 ) ;
F_29 ( V_52 , V_2 ) ;
return V_53 ;
}
static int F_30 ( struct V_51 * V_52 )
{
F_31 ( & V_52 -> V_7 ) ;
F_25 ( & V_52 -> V_7 ) ;
F_29 ( V_52 , NULL ) ;
return 0 ;
}
