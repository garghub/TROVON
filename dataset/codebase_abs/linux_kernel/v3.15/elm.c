static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
int F_5 ( struct V_6 * V_7 , enum V_8 V_9 ,
int V_10 , int V_11 , int V_12 )
{
T_1 V_13 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( ! V_2 ) {
F_7 ( V_7 , L_1 ) ;
return - V_14 ;
}
if ( V_11 > ( ( V_15 + 1 ) / 2 ) ) {
F_7 ( V_7 , L_2 , V_11 ) ;
return - V_16 ;
}
if ( V_10 > V_17 ) {
F_7 ( V_7 , L_3 , V_10 ) ;
return - V_16 ;
}
V_13 = ( V_9 & V_18 ) | ( V_15 << 16 ) ;
F_1 ( V_2 , V_19 , V_13 ) ;
V_2 -> V_9 = V_9 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_12 = V_12 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , int V_20 ,
bool V_21 )
{
T_1 V_13 ;
V_13 = F_3 ( V_2 , V_22 ) ;
if ( V_21 )
V_13 |= F_9 ( V_20 ) ;
else
V_13 &= ~ F_9 ( V_20 ) ;
F_1 ( V_2 , V_22 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_23 * V_24 , T_2 * V_25 )
{
int V_26 , V_3 ;
T_1 V_4 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_10 ; V_26 ++ ) {
if ( V_24 [ V_26 ] . V_27 ) {
F_8 ( V_2 , V_26 , true ) ;
V_3 = V_28 +
V_29 * V_26 ;
switch ( V_2 -> V_9 ) {
case V_30 :
V_4 = F_11 ( * ( T_1 * ) & V_25 [ 9 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_11 ( * ( T_1 * ) & V_25 [ 5 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_11 ( * ( T_1 * ) & V_25 [ 1 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = V_25 [ 0 ] ;
F_1 ( V_2 , V_3 , V_4 ) ;
break;
case V_31 :
V_4 = ( F_11 ( * ( T_1 * ) & V_25 [ 3 ] ) >> 4 ) |
( ( V_25 [ 2 ] & 0xf ) << 28 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_11 ( * ( T_1 * ) & V_25 [ 0 ] ) >> 12 ;
F_1 ( V_2 , V_3 , V_4 ) ;
break;
default:
F_12 ( L_4 ) ;
}
}
V_25 += V_2 -> V_12 ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
int V_26 , V_3 ;
T_1 V_13 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_10 ; V_26 ++ ) {
if ( V_24 [ V_26 ] . V_27 ) {
V_3 = V_32 +
V_29 * V_26 ;
V_13 = F_3 ( V_2 , V_3 ) ;
V_13 |= V_33 ;
F_1 ( V_2 , V_3 , V_13 ) ;
}
}
}
static void F_14 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
int V_26 , V_34 , V_35 = 0 ;
int V_3 ;
T_1 V_13 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_10 ; V_26 ++ ) {
if ( V_24 [ V_26 ] . V_27 ) {
V_3 = V_36 + V_37 * V_26 ;
V_13 = F_3 ( V_2 , V_3 ) ;
if ( V_13 & V_38 ) {
V_3 = V_39 +
V_37 * V_26 ;
V_24 [ V_26 ] . V_40 = V_13 &
V_41 ;
for ( V_34 = 0 ; V_34 < V_24 [ V_26 ] . V_40 ; V_34 ++ ) {
V_13 = F_3 ( V_2 , V_3 ) ;
V_24 [ V_26 ] . V_42 [ V_34 ] = V_13 &
V_43 ;
V_3 += 4 ;
}
V_35 += V_24 [ V_26 ] . V_40 ;
} else {
V_24 [ V_26 ] . V_44 = true ;
}
F_1 ( V_2 , V_45 , F_9 ( V_26 ) ) ;
F_8 ( V_2 , V_26 , false ) ;
}
}
}
void F_15 ( struct V_6 * V_7 , T_2 * V_46 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_13 ;
V_13 = F_3 ( V_2 , V_45 ) ;
F_1 ( V_2 , V_45 , V_13 & V_47 ) ;
F_1 ( V_2 , V_48 , V_49 ) ;
F_10 ( V_2 , V_24 , V_46 ) ;
F_13 ( V_2 , V_24 ) ;
F_16 ( & V_2 -> V_50 ) ;
V_13 = F_3 ( V_2 , V_48 ) ;
F_1 ( V_2 , V_48 , V_13 & ~ V_49 ) ;
F_14 ( V_2 , V_24 ) ;
}
static T_3 F_17 ( int V_51 , void * V_52 )
{
T_1 V_13 ;
struct V_1 * V_2 = V_52 ;
V_13 = F_3 ( V_2 , V_45 ) ;
if ( V_13 & V_47 ) {
F_1 ( V_2 , V_45 ,
V_13 & V_47 ) ;
F_18 ( & V_2 -> V_50 ) ;
return V_53 ;
}
return V_54 ;
}
static int F_19 ( struct V_55 * V_56 )
{
int V_57 = 0 ;
struct V_58 * V_59 , * V_60 ;
struct V_1 * V_2 ;
V_2 = F_20 ( & V_56 -> V_7 , sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 )
return - V_62 ;
V_2 -> V_7 = & V_56 -> V_7 ;
V_60 = F_21 ( V_56 , V_63 , 0 ) ;
if ( ! V_60 ) {
F_7 ( & V_56 -> V_7 , L_5 ) ;
return - V_14 ;
}
V_59 = F_21 ( V_56 , V_64 , 0 ) ;
V_2 -> V_5 = F_22 ( & V_56 -> V_7 , V_59 ) ;
if ( F_23 ( V_2 -> V_5 ) )
return F_24 ( V_2 -> V_5 ) ;
V_57 = F_25 ( & V_56 -> V_7 , V_60 -> V_65 , F_17 , 0 ,
V_56 -> V_66 , V_2 ) ;
if ( V_57 ) {
F_7 ( & V_56 -> V_7 , L_6 , V_60 -> V_65 ) ;
return V_57 ;
}
F_26 ( & V_56 -> V_7 ) ;
if ( F_27 ( & V_56 -> V_7 ) < 0 ) {
V_57 = - V_16 ;
F_28 ( & V_56 -> V_7 ) ;
F_7 ( & V_56 -> V_7 , L_7 ) ;
return V_57 ;
}
F_29 ( & V_2 -> V_50 ) ;
F_30 ( & V_2 -> V_67 ) ;
F_31 ( & V_2 -> V_67 , & V_68 ) ;
F_32 ( V_56 , V_2 ) ;
return V_57 ;
}
static int F_33 ( struct V_55 * V_56 )
{
F_34 ( & V_56 -> V_7 ) ;
F_28 ( & V_56 -> V_7 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = & V_2 -> V_71 ;
enum V_8 V_9 = V_2 -> V_9 ;
T_1 V_3 = 0 , V_26 ;
V_70 -> V_72 = F_3 ( V_2 , V_48 ) ;
V_70 -> V_73 = F_3 ( V_2 , V_74 ) ;
V_70 -> V_75 = F_3 ( V_2 , V_19 ) ;
V_70 -> V_76 = F_3 ( V_2 , V_22 ) ;
for ( V_26 = 0 ; V_26 < V_17 ; V_26 ++ ) {
V_3 = V_26 * V_29 ;
switch ( V_9 ) {
case V_30 :
V_70 -> V_77 [ V_26 ] = F_3 ( V_2 ,
V_78 + V_3 ) ;
V_70 -> V_79 [ V_26 ] = F_3 ( V_2 ,
V_80 + V_3 ) ;
case V_31 :
V_70 -> V_81 [ V_26 ] = F_3 ( V_2 ,
V_82 + V_3 ) ;
V_70 -> V_83 [ V_26 ] = F_3 ( V_2 ,
V_28 + V_3 ) ;
default:
return - V_16 ;
}
V_70 -> V_84 [ V_26 ] = F_3 ( V_2 ,
V_32 + V_3 ) ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = & V_2 -> V_71 ;
enum V_8 V_9 = V_2 -> V_9 ;
T_1 V_3 = 0 , V_26 ;
F_1 ( V_2 , V_48 , V_70 -> V_72 ) ;
F_1 ( V_2 , V_74 , V_70 -> V_73 ) ;
F_1 ( V_2 , V_19 , V_70 -> V_75 ) ;
F_1 ( V_2 , V_22 , V_70 -> V_76 ) ;
for ( V_26 = 0 ; V_26 < V_17 ; V_26 ++ ) {
V_3 = V_26 * V_29 ;
switch ( V_9 ) {
case V_30 :
F_1 ( V_2 , V_78 + V_3 ,
V_70 -> V_77 [ V_26 ] ) ;
F_1 ( V_2 , V_80 + V_3 ,
V_70 -> V_79 [ V_26 ] ) ;
case V_31 :
F_1 ( V_2 , V_82 + V_3 ,
V_70 -> V_81 [ V_26 ] ) ;
F_1 ( V_2 , V_28 + V_3 ,
V_70 -> V_83 [ V_26 ] ) ;
default:
return - V_16 ;
}
F_1 ( V_2 , V_32 + V_3 ,
V_70 -> V_84 [ V_26 ] &
V_33 ) ;
}
return 0 ;
}
static int F_37 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_35 ( V_2 ) ;
F_34 ( V_7 ) ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_27 ( V_7 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
