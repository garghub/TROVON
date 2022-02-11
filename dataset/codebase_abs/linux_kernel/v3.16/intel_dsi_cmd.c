static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_3 -> V_11 ) ;
enum V_12 V_12 = V_10 -> V_12 ;
T_1 V_13 ;
V_13 = F_3 ( F_4 ( V_12 ) ) ;
#define F_5 ( V_13 , T_2 ) (val) & (bit) ? " " #bit : ""
F_6 ( L_1
L_2
L_3 , V_12 , V_13 ,
F_5 ( V_13 , V_14 ) ,
F_5 ( V_13 , V_15 ) ,
F_5 ( V_13 , V_16 ) ,
F_5 ( V_13 , V_17 ) ,
F_5 ( V_13 , V_18 ) ,
F_5 ( V_13 , V_19 ) ,
F_5 ( V_13 , V_20 ) ,
F_5 ( V_13 , V_21 ) ,
F_5 ( V_13 , V_22 ) ,
F_5 ( V_13 , V_23 ) ,
F_5 ( V_13 , V_24 ) ,
F_5 ( V_13 , V_25 ) ,
F_5 ( V_13 , V_26 ) ,
F_5 ( V_13 , V_27 ) ,
F_5 ( V_13 , V_28 ) ,
F_5 ( V_13 , V_29 ) ,
F_5 ( V_13 , V_30 ) ,
F_5 ( V_13 , V_31 ) ,
F_5 ( V_13 , V_32 ) ,
F_5 ( V_13 , V_33 ) ,
F_5 ( V_13 , V_34 ) ,
F_5 ( V_13 , V_35 ) ,
F_5 ( V_13 , V_36 ) ,
F_5 ( V_13 , V_37 ) ,
F_5 ( V_13 , V_38 ) ,
F_5 ( V_13 , V_39 ) ,
F_5 ( V_13 , V_40 ) ,
F_5 ( V_13 , V_41 ) ,
F_5 ( V_13 , V_42 ) ,
F_5 ( V_13 , V_43 ) ,
F_5 ( V_13 , V_44 ) ,
F_5 ( V_13 , V_45 ) ) ;
#undef F_5
}
void F_7 ( struct V_1 * V_1 , bool V_46 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_3 -> V_11 ) ;
enum V_12 V_12 = V_10 -> V_12 ;
T_1 V_47 ;
T_1 V_48 = V_49 ;
if ( F_8 ( ( F_3 ( F_9 ( V_12 ) ) & V_48 ) == V_48 , 50 ) )
F_10 ( L_4 ) ;
V_47 = F_3 ( F_11 ( V_12 ) ) ;
V_47 &= V_50 ;
F_12 ( F_11 ( V_12 ) , V_46 ? V_51 : V_52 ) ;
V_1 -> V_53 = V_46 ;
}
static int F_13 ( struct V_1 * V_1 , int V_54 ,
T_3 V_55 , T_4 V_56 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_3 -> V_11 ) ;
enum V_12 V_12 = V_10 -> V_12 ;
T_1 V_57 ;
T_1 V_58 ;
T_1 V_48 ;
F_6 ( L_5 ,
V_54 , V_55 , V_56 ) ;
if ( V_1 -> V_53 ) {
V_57 = F_14 ( V_12 ) ;
V_48 = V_59 ;
} else {
V_57 = F_15 ( V_12 ) ;
V_48 = V_60 ;
}
if ( F_8 ( ( F_3 ( F_9 ( V_12 ) ) & V_48 ) == 0 , 50 ) ) {
F_10 ( L_6 ) ;
F_1 ( V_1 ) ;
}
V_58 = V_56 << V_61 |
V_54 << V_62 |
V_55 << V_63 ;
F_12 ( V_57 , V_58 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 , int V_54 ,
T_3 V_55 , const T_3 * V_56 , int V_64 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_3 -> V_11 ) ;
enum V_12 V_12 = V_10 -> V_12 ;
T_1 V_65 ;
int V_66 , V_67 , V_68 ;
T_1 V_48 ;
F_6 ( L_7 ,
V_54 , V_55 , V_64 ) ;
if ( V_1 -> V_53 ) {
V_65 = F_17 ( V_12 ) ;
V_48 = V_69 ;
} else {
V_65 = F_18 ( V_12 ) ;
V_48 = V_70 ;
}
if ( F_8 ( ( F_3 ( F_9 ( V_12 ) ) & V_48 ) == 0 , 50 ) )
F_10 ( L_8 ) ;
for ( V_66 = 0 ; V_66 < V_64 ; V_66 += V_68 ) {
T_1 V_13 = 0 ;
V_68 = F_19 ( int , V_64 - V_66 , 4 ) ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ )
V_13 |= * V_56 ++ << 8 * V_67 ;
F_12 ( V_65 , V_13 ) ;
}
return F_13 ( V_1 , V_54 , V_55 , V_64 ) ;
}
static int F_20 ( struct V_1 * V_1 ,
int V_54 , const T_3 * V_56 , int V_64 ,
enum V_71 type )
{
int V_72 ;
if ( V_64 == 0 ) {
F_21 ( type == V_73 ) ;
V_72 = F_13 ( V_1 , V_54 ,
V_74 ,
0 ) ;
} else if ( V_64 == 1 ) {
V_72 = F_13 ( V_1 , V_54 ,
type == V_73 ?
V_75 :
V_76 , V_56 [ 0 ] ) ;
} else if ( V_64 == 2 ) {
V_72 = F_13 ( V_1 , V_54 ,
type == V_73 ?
V_77 :
V_78 ,
( V_56 [ 1 ] << 8 ) | V_56 [ 0 ] ) ;
} else {
V_72 = F_16 ( V_1 , V_54 ,
type == V_73 ?
V_79 :
V_80 , V_56 , V_64 ) ;
}
return V_72 ;
}
int F_22 ( struct V_1 * V_1 , int V_54 ,
const T_3 * V_56 , int V_64 )
{
return F_20 ( V_1 , V_54 , V_56 , V_64 , V_81 ) ;
}
int F_23 ( struct V_1 * V_1 , int V_54 ,
const T_3 * V_56 , int V_64 )
{
return F_20 ( V_1 , V_54 , V_56 , V_64 , V_73 ) ;
}
static int F_24 ( struct V_1 * V_1 ,
int V_54 , T_3 V_82 )
{
return F_13 ( V_1 , V_54 , V_83 ,
V_82 ) ;
}
static int F_25 ( struct V_1 * V_1 ,
int V_54 , T_3 * V_84 ,
int V_85 )
{
T_4 V_56 ;
T_3 V_55 ;
switch ( V_85 ) {
case 0 :
V_55 = V_86 ;
V_56 = 0 ;
break;
case 1 :
V_55 = V_87 ;
V_56 = V_84 [ 0 ] ;
break;
case 2 :
V_55 = V_88 ;
V_56 = ( V_84 [ 1 ] << 8 ) | V_84 [ 0 ] ;
break;
default:
F_26 () ;
}
return F_13 ( V_1 , V_54 , V_55 , V_56 ) ;
}
static int F_27 ( struct V_1 * V_1 ,
T_3 * V_89 , int V_90 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_3 -> V_11 ) ;
enum V_12 V_12 = V_10 -> V_12 ;
int V_66 , V_64 = 0 ;
T_1 V_65 , V_13 ;
if ( V_1 -> V_53 ) {
V_65 = F_17 ( V_12 ) ;
} else {
V_65 = F_18 ( V_12 ) ;
}
while ( V_64 < V_90 ) {
V_13 = F_3 ( V_65 ) ;
for ( V_66 = 0 ; V_66 < 4 && V_64 < V_90 ; V_66 ++ , V_64 ++ )
V_89 [ V_64 ] = V_13 >> 8 * V_66 ;
}
return V_64 ;
}
int F_28 ( struct V_1 * V_1 , int V_54 , T_3 V_82 ,
T_3 * V_89 , int V_90 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_3 -> V_11 ) ;
enum V_12 V_12 = V_10 -> V_12 ;
T_1 V_48 ;
int V_72 ;
F_12 ( F_4 ( V_12 ) , V_16 ) ;
V_72 = F_24 ( V_1 , V_54 , V_82 ) ;
if ( V_72 )
return V_72 ;
V_48 = V_16 ;
if ( F_8 ( ( F_3 ( F_4 ( V_12 ) ) & V_48 ) == V_48 , 50 ) )
F_10 ( L_9 ) ;
V_72 = F_27 ( V_1 , V_89 , V_90 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_72 != V_90 )
return - V_91 ;
return 0 ;
}
int F_29 ( struct V_1 * V_1 , int V_54 ,
T_3 * V_84 , int V_85 , T_3 * V_89 , int V_90 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_3 -> V_11 ) ;
enum V_12 V_12 = V_10 -> V_12 ;
T_1 V_48 ;
int V_72 ;
F_12 ( F_4 ( V_12 ) , V_16 ) ;
V_72 = F_25 ( V_1 , V_54 , V_84 ,
V_85 ) ;
if ( V_72 )
return V_72 ;
V_48 = V_16 ;
if ( F_8 ( ( F_3 ( F_4 ( V_12 ) ) & V_48 ) == V_48 , 50 ) )
F_10 ( L_9 ) ;
V_72 = F_27 ( V_1 , V_89 , V_90 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_72 != V_90 )
return - V_91 ;
return 0 ;
}
int F_30 ( struct V_1 * V_1 , T_1 V_92 , bool V_53 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_3 -> V_11 ) ;
enum V_12 V_12 = V_10 -> V_12 ;
T_1 V_48 ;
if ( V_53 )
V_92 &= ~ V_93 ;
else
V_92 |= V_93 ;
F_12 ( F_4 ( V_12 ) , V_15 ) ;
if ( V_92 == F_3 ( F_31 ( V_12 ) ) )
F_10 ( L_10 , V_92 ) ;
F_12 ( F_31 ( V_12 ) , V_92 ) ;
V_48 = V_15 ;
if ( F_8 ( ( F_3 ( F_4 ( V_12 ) ) & V_48 ) == V_48 , 100 ) )
F_10 ( L_11 , V_92 ) ;
return 0 ;
}
