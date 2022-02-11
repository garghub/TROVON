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
case V_32 :
V_4 = F_11 ( * ( T_1 * ) & V_25 [ 22 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_11 ( * ( T_1 * ) & V_25 [ 18 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_11 ( * ( T_1 * ) & V_25 [ 14 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_11 ( * ( T_1 * ) & V_25 [ 10 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_11 ( * ( T_1 * ) & V_25 [ 6 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_11 ( * ( T_1 * ) & V_25 [ 2 ] ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_3 += 4 ;
V_4 = F_11 ( * ( T_1 * ) & V_25 [ 0 ] ) >> 16 ;
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
V_3 = V_33 +
V_29 * V_26 ;
V_13 = F_3 ( V_2 , V_3 ) ;
V_13 |= V_34 ;
F_1 ( V_2 , V_3 , V_13 ) ;
}
}
}
static void F_14 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
int V_26 , V_35 , V_36 = 0 ;
int V_3 ;
T_1 V_13 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_10 ; V_26 ++ ) {
if ( V_24 [ V_26 ] . V_27 ) {
V_3 = V_37 + V_38 * V_26 ;
V_13 = F_3 ( V_2 , V_3 ) ;
if ( V_13 & V_39 ) {
V_3 = V_40 +
V_38 * V_26 ;
V_24 [ V_26 ] . V_41 = V_13 &
V_42 ;
for ( V_35 = 0 ; V_35 < V_24 [ V_26 ] . V_41 ; V_35 ++ ) {
V_13 = F_3 ( V_2 , V_3 ) ;
V_24 [ V_26 ] . V_43 [ V_35 ] = V_13 &
V_44 ;
V_3 += 4 ;
}
V_36 += V_24 [ V_26 ] . V_41 ;
} else {
V_24 [ V_26 ] . V_45 = true ;
}
F_1 ( V_2 , V_46 , F_9 ( V_26 ) ) ;
F_8 ( V_2 , V_26 , false ) ;
}
}
}
void F_15 ( struct V_6 * V_7 , T_2 * V_47 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_13 ;
V_13 = F_3 ( V_2 , V_46 ) ;
F_1 ( V_2 , V_46 , V_13 & V_48 ) ;
F_1 ( V_2 , V_49 , V_50 ) ;
F_10 ( V_2 , V_24 , V_47 ) ;
F_13 ( V_2 , V_24 ) ;
F_16 ( & V_2 -> V_51 ) ;
V_13 = F_3 ( V_2 , V_49 ) ;
F_1 ( V_2 , V_49 , V_13 & ~ V_50 ) ;
F_14 ( V_2 , V_24 ) ;
}
static T_3 F_17 ( int V_52 , void * V_53 )
{
T_1 V_13 ;
struct V_1 * V_2 = V_53 ;
V_13 = F_3 ( V_2 , V_46 ) ;
if ( V_13 & V_48 ) {
F_1 ( V_2 , V_46 ,
V_13 & V_48 ) ;
F_18 ( & V_2 -> V_51 ) ;
return V_54 ;
}
return V_55 ;
}
static int F_19 ( struct V_56 * V_57 )
{
int V_58 = 0 ;
struct V_59 * V_60 , * V_61 ;
struct V_1 * V_2 ;
V_2 = F_20 ( & V_57 -> V_7 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return - V_63 ;
V_2 -> V_7 = & V_57 -> V_7 ;
V_61 = F_21 ( V_57 , V_64 , 0 ) ;
if ( ! V_61 ) {
F_7 ( & V_57 -> V_7 , L_5 ) ;
return - V_14 ;
}
V_60 = F_21 ( V_57 , V_65 , 0 ) ;
V_2 -> V_5 = F_22 ( & V_57 -> V_7 , V_60 ) ;
if ( F_23 ( V_2 -> V_5 ) )
return F_24 ( V_2 -> V_5 ) ;
V_58 = F_25 ( & V_57 -> V_7 , V_61 -> V_66 , F_17 , 0 ,
V_57 -> V_67 , V_2 ) ;
if ( V_58 ) {
F_7 ( & V_57 -> V_7 , L_6 , V_61 -> V_66 ) ;
return V_58 ;
}
F_26 ( & V_57 -> V_7 ) ;
if ( F_27 ( & V_57 -> V_7 ) < 0 ) {
V_58 = - V_16 ;
F_28 ( & V_57 -> V_7 ) ;
F_7 ( & V_57 -> V_7 , L_7 ) ;
return V_58 ;
}
F_29 ( & V_2 -> V_51 ) ;
F_30 ( & V_2 -> V_68 ) ;
F_31 ( & V_2 -> V_68 , & V_69 ) ;
F_32 ( V_57 , V_2 ) ;
return V_58 ;
}
static int F_33 ( struct V_56 * V_57 )
{
F_34 ( & V_57 -> V_7 ) ;
F_28 ( & V_57 -> V_7 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_72 ;
enum V_8 V_9 = V_2 -> V_9 ;
T_1 V_3 = 0 , V_26 ;
V_71 -> V_73 = F_3 ( V_2 , V_49 ) ;
V_71 -> V_74 = F_3 ( V_2 , V_75 ) ;
V_71 -> V_76 = F_3 ( V_2 , V_19 ) ;
V_71 -> V_77 = F_3 ( V_2 , V_22 ) ;
for ( V_26 = 0 ; V_26 < V_17 ; V_26 ++ ) {
V_3 = V_26 * V_29 ;
switch ( V_9 ) {
case V_32 :
V_71 -> V_78 [ V_26 ] = F_3 ( V_2 ,
V_33 + V_3 ) ;
V_71 -> V_79 [ V_26 ] = F_3 ( V_2 ,
V_80 + V_3 ) ;
V_71 -> V_81 [ V_26 ] = F_3 ( V_2 ,
V_82 + V_3 ) ;
case V_30 :
V_71 -> V_83 [ V_26 ] = F_3 ( V_2 ,
V_84 + V_3 ) ;
V_71 -> V_85 [ V_26 ] = F_3 ( V_2 ,
V_86 + V_3 ) ;
case V_31 :
V_71 -> V_87 [ V_26 ] = F_3 ( V_2 ,
V_88 + V_3 ) ;
V_71 -> V_89 [ V_26 ] = F_3 ( V_2 ,
V_28 + V_3 ) ;
break;
default:
return - V_16 ;
}
V_71 -> V_78 [ V_26 ] = F_3 ( V_2 ,
V_33 + V_3 ) ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_72 ;
enum V_8 V_9 = V_2 -> V_9 ;
T_1 V_3 = 0 , V_26 ;
F_1 ( V_2 , V_49 , V_71 -> V_73 ) ;
F_1 ( V_2 , V_75 , V_71 -> V_74 ) ;
F_1 ( V_2 , V_19 , V_71 -> V_76 ) ;
F_1 ( V_2 , V_22 , V_71 -> V_77 ) ;
for ( V_26 = 0 ; V_26 < V_17 ; V_26 ++ ) {
V_3 = V_26 * V_29 ;
switch ( V_9 ) {
case V_32 :
F_1 ( V_2 , V_33 + V_3 ,
V_71 -> V_78 [ V_26 ] ) ;
F_1 ( V_2 , V_80 + V_3 ,
V_71 -> V_79 [ V_26 ] ) ;
F_1 ( V_2 , V_82 + V_3 ,
V_71 -> V_81 [ V_26 ] ) ;
case V_30 :
F_1 ( V_2 , V_84 + V_3 ,
V_71 -> V_83 [ V_26 ] ) ;
F_1 ( V_2 , V_86 + V_3 ,
V_71 -> V_85 [ V_26 ] ) ;
case V_31 :
F_1 ( V_2 , V_88 + V_3 ,
V_71 -> V_87 [ V_26 ] ) ;
F_1 ( V_2 , V_28 + V_3 ,
V_71 -> V_89 [ V_26 ] ) ;
break;
default:
return - V_16 ;
}
F_1 ( V_2 , V_33 + V_3 ,
V_71 -> V_78 [ V_26 ] &
V_34 ) ;
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
