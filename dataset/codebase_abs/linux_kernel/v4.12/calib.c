static T_1 F_1 ( T_1 * V_1 )
{
T_1 V_2 ;
T_1 V_3 [ V_4 ] ;
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
V_3 [ V_5 ] = V_1 [ V_5 ] ;
for ( V_5 = 0 ; V_5 < V_4 - 1 ; V_5 ++ ) {
for ( V_6 = 1 ; V_6 < V_4 - V_5 ; V_6 ++ ) {
if ( V_3 [ V_6 ] > V_3 [ V_6 - 1 ] ) {
V_2 = V_3 [ V_6 ] ;
V_3 [ V_6 ] = V_3 [ V_6 - 1 ] ;
V_3 [ V_6 - 1 ] = V_2 ;
}
}
}
V_2 = V_3 [ ( V_4 - 1 ) >> 1 ] ;
return V_2 ;
}
static struct V_7 * F_2 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_7 * V_12 ;
if ( ! V_11 || F_3 ( V_11 ) )
V_12 = & V_9 -> V_13 ;
else
V_12 = & V_9 -> V_14 ;
return V_12 ;
}
static T_2 F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
return F_2 ( V_9 , V_11 ) -> V_15 ;
}
T_2 F_5 ( struct V_8 * V_9 , struct V_10 * V_11 ,
T_2 V_16 )
{
T_3 V_17 = V_18 ;
if ( V_16 ) {
T_3 V_19 = V_16 - V_20 -
F_4 ( V_9 , V_11 ) ;
if ( V_19 > 0 )
V_17 += V_19 ;
}
return V_17 ;
}
static void F_6 ( struct V_8 * V_9 ,
struct V_21 * V_22 ,
T_1 * V_23 )
{
struct V_24 * V_25 = F_7 ( V_9 ) ;
struct V_7 * V_12 ;
struct V_26 * V_27 ;
bool V_28 = false ;
T_4 V_29 = ( V_9 -> V_30 << 3 ) | V_9 -> V_30 ;
int V_5 ;
V_27 = V_22 -> V_31 ;
V_12 = F_2 ( V_9 , V_9 -> V_32 ) ;
for ( V_5 = 0 ; V_5 < V_33 ; V_5 ++ ) {
if ( ! ( V_29 & ( 1 << V_5 ) ) ||
( ( V_5 >= V_34 ) && ! F_8 ( V_9 -> V_32 ) ) )
continue;
V_27 [ V_5 ] . V_1 [ V_27 [ V_5 ] . V_35 ] = V_23 [ V_5 ] ;
if ( ++ V_27 [ V_5 ] . V_35 >= V_4 )
V_27 [ V_5 ] . V_35 = 0 ;
if ( V_27 [ V_5 ] . V_36 > 0 ) {
V_27 [ V_5 ] . V_36 -- ;
V_27 [ V_5 ] . V_37 = V_23 [ V_5 ] ;
} else {
V_27 [ V_5 ] . V_37 =
F_1 ( V_27 [ V_5 ] . V_1 ) ;
}
if ( ! V_27 [ V_5 ] . V_37 )
continue;
if ( V_27 [ V_5 ] . V_37 > V_12 -> V_38 ) {
V_28 = true ;
F_9 ( V_25 , V_39 ,
L_1 ,
V_5 , V_27 [ V_5 ] . V_37 , V_12 -> V_38 ,
( F_10 ( V_40 , & V_22 -> V_41 ) ?
L_2 :
L_3 ) ) ;
if ( ! F_10 ( V_40 , & V_22 -> V_41 ) )
V_27 [ V_5 ] . V_37 = V_12 -> V_38 ;
}
}
if ( ! V_28 )
F_11 ( V_40 , & V_22 -> V_41 ) ;
}
static bool F_12 ( struct V_8 * V_9 ,
enum V_42 V_43 ,
T_1 * V_44 )
{
switch ( V_43 ) {
case V_45 :
* V_44 = ( V_46 ) V_9 -> V_47 -> V_48 ( V_9 , V_49 ) ;
break;
case V_50 :
* V_44 = ( V_46 ) V_9 -> V_47 -> V_48 ( V_9 , V_51 ) ;
break;
default:
F_13 ( 1 ) ;
return false ;
}
return true ;
}
void F_14 ( struct V_8 * V_9 ,
struct V_52 * V_53 )
{
int V_5 ;
F_15 ( V_9 , V_53 ) ;
V_53 -> V_54 = V_55 ;
for ( V_5 = 0 ; V_5 < V_34 ; V_5 ++ ) {
V_9 -> V_56 . V_57 [ V_5 ] = 0 ;
V_9 -> V_58 . V_57 [ V_5 ] = 0 ;
V_9 -> V_59 . V_57 [ V_5 ] = 0 ;
V_9 -> V_60 . V_57 [ V_5 ] = 0 ;
}
V_9 -> V_61 = 0 ;
}
bool F_16 ( struct V_8 * V_9 )
{
struct V_24 * V_25 = F_7 ( V_9 ) ;
struct V_52 * V_53 = V_9 -> V_62 ;
if ( ! V_9 -> V_63 )
return true ;
if ( ! F_17 ( V_9 ) && ! F_18 ( V_9 ) )
return true ;
if ( V_53 == NULL )
return true ;
if ( V_53 -> V_54 != V_64 ) {
F_9 ( V_25 , V_39 , L_4 ,
V_53 -> V_54 ) ;
return true ;
}
if ( ! ( V_9 -> V_65 & V_53 -> V_66 -> V_67 ) )
return true ;
F_9 ( V_25 , V_39 , L_5 ,
V_53 -> V_66 -> V_67 , V_9 -> V_32 -> V_11 -> V_68 ) ;
V_9 -> V_63 -> V_69 &= ~ V_53 -> V_66 -> V_67 ;
V_53 -> V_54 = V_70 ;
return false ;
}
void F_19 ( struct V_8 * V_9 , bool V_71 )
{
if ( V_9 -> V_63 )
F_20 ( V_72 , & V_9 -> V_63 -> V_41 ) ;
F_21 ( V_9 , V_73 ,
V_74 ) ;
if ( V_71 )
F_22 ( V_9 , V_73 ,
V_75 ) ;
else
F_21 ( V_9 , V_73 ,
V_75 ) ;
F_21 ( V_9 , V_73 , V_76 ) ;
}
int F_23 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_26 * V_27 = NULL ;
unsigned V_5 , V_6 ;
T_4 V_29 = ( V_9 -> V_30 << 3 ) | V_9 -> V_30 ;
struct V_24 * V_25 = F_7 ( V_9 ) ;
T_2 V_77 = F_4 ( V_9 , V_11 ) ;
T_5 V_78 = F_24 ( V_9 , V_73 ) ;
if ( V_9 -> V_63 )
V_27 = V_9 -> V_63 -> V_31 ;
F_25 ( V_9 ) ;
for ( V_5 = 0 ; V_5 < V_33 ; V_5 ++ ) {
if ( V_29 & ( 1 << V_5 ) ) {
T_2 V_2 ;
if ( ( V_5 >= V_34 ) && ! F_8 ( V_11 ) )
continue;
if ( V_9 -> V_79 )
V_2 = V_9 -> V_79 ;
else if ( V_27 )
V_2 = V_27 [ V_5 ] . V_37 ;
else
V_2 = V_77 ;
F_26 ( V_9 , V_9 -> V_80 [ V_5 ] ,
( ( ( T_5 ) V_2 << 1 ) & 0x1ff ) , 0x1ff ) ;
}
}
if ( V_78 & V_76 ) {
F_22 ( V_9 , V_73 , V_76 ) ;
F_27 ( V_9 ) ;
F_25 ( V_9 ) ;
}
F_22 ( V_9 , V_73 ,
V_74 ) ;
F_22 ( V_9 , V_73 ,
V_75 ) ;
F_21 ( V_9 , V_73 , V_76 ) ;
F_27 ( V_9 ) ;
for ( V_6 = 0 ; V_6 < 22200 ; V_6 ++ ) {
if ( ( F_24 ( V_9 , V_73 ) &
V_76 ) == 0 )
break;
F_28 ( 10 ) ;
}
if ( V_78 & V_76 ) {
F_25 ( V_9 ) ;
if ( V_78 & V_74 )
F_21 ( V_9 , V_73 ,
V_74 ) ;
if ( V_78 & V_75 )
F_21 ( V_9 , V_73 ,
V_75 ) ;
F_21 ( V_9 , V_73 , V_76 ) ;
F_27 ( V_9 ) ;
}
if ( V_6 == 22200 ) {
F_9 ( V_25 , V_81 ,
L_6 ,
F_24 ( V_9 , V_73 ) ) ;
return - V_82 ;
}
F_25 ( V_9 ) ;
for ( V_5 = 0 ; V_5 < V_33 ; V_5 ++ ) {
if ( V_29 & ( 1 << V_5 ) ) {
if ( ( V_5 >= V_34 ) && ! F_8 ( V_11 ) )
continue;
F_26 ( V_9 , V_9 -> V_80 [ V_5 ] ,
( ( ( T_5 ) ( - 50 ) << 1 ) & 0x1ff ) , 0x1ff ) ;
}
}
F_27 ( V_9 ) ;
return 0 ;
}
static void F_29 ( struct V_8 * V_9 , T_2 * V_16 )
{
struct V_24 * V_25 = F_7 ( V_9 ) ;
struct V_7 * V_12 ;
int V_5 ;
if ( F_3 ( V_9 -> V_32 ) )
V_12 = & V_9 -> V_13 ;
else
V_12 = & V_9 -> V_14 ;
for ( V_5 = 0 ; V_5 < V_33 ; V_5 ++ ) {
if ( ! V_16 [ V_5 ] )
continue;
F_9 ( V_25 , V_39 ,
L_7 ,
( V_5 >= 3 ? L_8 : L_9 ) , V_5 % 3 , V_16 [ V_5 ] ) ;
if ( V_16 [ V_5 ] > V_12 -> V_38 ) {
F_9 ( V_25 , V_39 ,
L_10 ,
V_5 , V_16 [ V_5 ] , V_12 -> V_38 ) ;
V_16 [ V_5 ] = V_12 -> V_38 ;
} else if ( V_16 [ V_5 ] < V_12 -> V_83 ) {
F_9 ( V_25 , V_39 ,
L_11 ,
V_5 , V_16 [ V_5 ] , V_12 -> V_83 ) ;
V_16 [ V_5 ] = V_12 -> V_15 ;
}
}
}
bool F_30 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_24 * V_25 = F_7 ( V_9 ) ;
T_1 V_16 , V_84 ;
T_1 V_23 [ V_33 ] = { 0 } ;
struct V_26 * V_27 ;
struct V_85 * V_86 = V_11 -> V_11 ;
struct V_21 * V_63 = V_9 -> V_63 ;
if ( F_24 ( V_9 , V_73 ) & V_76 ) {
F_9 ( V_25 , V_39 ,
L_12 ) ;
return false ;
}
F_31 ( V_9 , V_23 ) ;
F_29 ( V_9 , V_23 ) ;
V_16 = V_23 [ 0 ] ;
if ( F_12 ( V_9 , V_86 -> V_43 , & V_84 )
&& V_16 > V_84 ) {
F_9 ( V_25 , V_39 ,
L_13 ,
V_16 , V_84 ) ;
}
if ( ! V_63 ) {
V_11 -> V_87 = V_16 ;
return false ;
}
V_27 = V_63 -> V_31 ;
F_11 ( V_72 , & V_63 -> V_41 ) ;
F_6 ( V_9 , V_63 , V_23 ) ;
V_11 -> V_87 = V_27 [ 0 ] . V_37 ;
V_9 -> V_17 = F_5 ( V_9 , V_11 , V_11 -> V_87 ) ;
return true ;
}
void F_32 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_26 * V_27 ;
T_2 V_77 ;
int V_5 , V_6 ;
V_9 -> V_63 -> V_88 = V_11 -> V_88 ;
V_9 -> V_63 -> V_89 = V_11 -> V_89 ;
V_27 = V_9 -> V_63 -> V_31 ;
V_77 = F_4 ( V_9 , V_11 ) ;
for ( V_5 = 0 ; V_5 < V_33 ; V_5 ++ ) {
V_27 [ V_5 ] . V_35 = 0 ;
V_27 [ V_5 ] . V_37 = V_77 ;
V_27 [ V_5 ] . V_36 = V_90 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
V_27 [ V_5 ] . V_1 [ V_6 ] = V_77 ;
}
}
}
void F_33 ( struct V_8 * V_9 )
{
struct V_21 * V_63 = V_9 -> V_63 ;
if ( F_34 ( ! V_63 ) )
return;
if ( ! F_10 ( V_72 , & V_63 -> V_41 ) )
F_19 ( V_9 , true ) ;
else if ( ! ( F_24 ( V_9 , V_73 ) & V_76 ) )
F_30 ( V_9 , V_9 -> V_32 ) ;
F_20 ( V_40 , & V_63 -> V_41 ) ;
}
