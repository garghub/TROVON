static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
switch ( V_5 ) {
case V_6 ... V_7 :
return V_3 -> V_8 ;
case V_9 :
return NULL ;
case V_10 ... V_11 :
return V_3 -> V_12 ;
case V_13 ... V_14 :
return V_3 -> V_8 ;
case V_15 :
return V_3 -> V_8 ;
default:
return F_2 ( - V_16 ) ;
}
}
static void F_3 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_4 ( V_18 ) ;
F_5 ( & V_3 -> V_19 ) ;
}
static void F_6 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_4 ( V_18 ) ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
T_1 V_22 = V_23 [ V_20 ] ;
struct V_1 * V_8 = F_1 ( V_3 , V_20 ) ;
if ( V_22 == V_24 ||
F_7 ( V_8 ) )
continue;
V_3 -> V_25 [ V_20 ] = V_3 -> V_26 [ V_20 ] ;
F_8 ( V_8 , V_23 [ V_20 ] ,
V_3 -> V_26 [ V_20 ] ) ;
}
F_9 ( & V_3 -> V_19 ) ;
}
inline static const struct V_27 *
F_10 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
return & V_28 [ V_18 -> V_29 ] ;
}
static void F_11 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_4 ( V_18 ) ;
const struct V_27 * V_17 = F_10 ( V_3 ,
V_18 ) ;
V_3 -> V_26 [ V_17 -> V_30 ] |= V_17 -> V_31 ;
}
static void F_12 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_4 ( V_18 ) ;
const struct V_27 * V_17 = F_10 ( V_3 ,
V_18 ) ;
V_3 -> V_26 [ V_17 -> V_30 ] &= ~ V_17 -> V_31 ;
}
static T_2 F_13 ( int V_32 , void * V_18 )
{
struct V_2 * V_3 = V_18 ;
T_1 V_33 [ V_21 ] = {} ;
T_1 V_34 ;
int V_35 ;
int V_20 , V_36 ;
V_35 = F_14 ( V_3 -> V_8 , V_37 , & V_34 ) ;
if ( V_35 < 0 ) {
F_15 ( V_3 -> V_38 , L_1 ,
V_35 ) ;
return V_39 ;
}
if ( V_34 & V_40 ) {
F_16 ( V_3 -> V_8 , V_41 , 4 ,
& V_33 [ V_6 ] ) ;
}
if ( V_34 & V_42 ) {
V_33 [ V_9 ] = 0 ;
}
if ( V_34 & V_43 ) {
F_16 ( V_3 -> V_12 , V_44 , 3 ,
& V_33 [ V_10 ] ) ;
}
if ( V_34 & V_45 ) {
T_1 V_46 [ V_47 ] ;
V_33 [ V_13 ] = 0 ;
V_33 [ V_14 ] = 0 ;
F_16 ( V_3 -> V_8 , V_48 ,
V_47 , V_46 ) ;
for ( V_20 = 0 ; V_20 < V_47 ; V_20 ++ ) {
bool V_49 = false ;
switch ( V_46 [ V_20 ] & V_50 ) {
case V_51 :
if ( V_3 -> V_52 [ V_20 ] != V_46 [ V_20 ] )
V_49 = true ;
break;
case V_53 :
if ( ( V_3 -> V_52 [ V_20 ] != V_46 [ V_20 ] ) &&
( V_46 [ V_20 ] & V_54 ) )
V_49 = true ;
break;
case V_55 :
if ( ( V_3 -> V_52 [ V_20 ] != V_46 [ V_20 ] ) &&
! ( V_46 [ V_20 ] & V_54 ) )
V_49 = true ;
break;
default:
break;
}
if ( V_49 ) {
if ( V_20 < 8 )
V_33 [ V_13 ] |= ( 1 << V_20 ) ;
else
V_33 [ V_14 ] |= ( 1 << ( V_20 - 8 ) ) ;
}
}
}
if ( V_34 & V_56 ) {
V_35 = F_14 ( V_3 -> V_8 , V_57 ,
& V_33 [ V_15 ] ) ;
}
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ )
V_33 [ V_20 ] &= ~ V_3 -> V_26 [ V_20 ] ;
for ( V_20 = 0 ; V_20 < V_58 ; V_20 ++ ) {
if ( V_33 [ V_28 [ V_20 ] . V_30 ] & V_28 [ V_20 ] . V_31 ) {
V_36 = F_17 ( V_3 -> V_59 , V_20 ) ;
if ( V_36 )
F_18 ( V_36 ) ;
}
}
return V_60 ;
}
int F_19 ( struct V_2 * V_3 )
{
if ( V_3 -> V_32 && V_3 -> V_59 )
F_13 ( 0 , V_3 ) ;
return 0 ;
}
static int F_20 ( struct V_59 * V_61 , unsigned int V_32 ,
T_3 V_62 )
{
struct V_2 * V_3 = V_61 -> V_63 ;
F_21 ( V_32 , V_3 ) ;
F_22 ( V_32 , & V_64 , V_65 ) ;
F_23 ( V_32 , 1 ) ;
F_24 ( V_32 ) ;
return 0 ;
}
int F_25 ( struct V_2 * V_3 )
{
struct V_59 * V_66 ;
int V_20 ;
int V_35 ;
T_1 V_67 ;
if ( ! V_3 -> V_32 ) {
F_26 ( V_3 -> V_38 , L_2 ) ;
return 0 ;
}
F_27 ( & V_3 -> V_19 ) ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_1 * V_8 ;
V_3 -> V_26 [ V_20 ] = 0xff ;
V_3 -> V_25 [ V_20 ] = 0xff ;
V_8 = F_1 ( V_3 , V_20 ) ;
if ( F_7 ( V_8 ) )
continue;
if ( V_23 [ V_20 ] == V_24 )
continue;
F_8 ( V_8 , V_23 [ V_20 ] , 0xff ) ;
}
for ( V_20 = 0 ; V_20 < V_47 ; V_20 ++ ) {
V_3 -> V_52 [ V_20 ] = ( F_14 ( V_3 -> V_8 ,
V_48 + V_20 ,
& V_67 )
& V_54 ) ?
true : false ;
}
V_66 = F_28 ( NULL , V_58 ,
& V_68 , V_3 ) ;
if ( ! V_66 ) {
F_15 ( V_3 -> V_38 , L_3 ) ;
return - V_69 ;
}
V_3 -> V_59 = V_66 ;
V_35 = F_29 ( V_3 -> V_32 , NULL , F_13 ,
V_70 | V_71 ,
L_4 , V_3 ) ;
if ( V_35 ) {
F_15 ( V_3 -> V_38 , L_5 ,
V_3 -> V_32 , V_35 ) ;
return V_35 ;
}
if ( ! V_3 -> V_72 )
return 0 ;
V_35 = F_29 ( V_3 -> V_72 , NULL , F_13 ,
V_70 | V_73 |
V_71 , L_6 , V_3 ) ;
if ( V_35 )
F_15 ( V_3 -> V_38 , L_7 ,
V_3 -> V_72 , V_35 ) ;
return 0 ;
}
void F_30 ( struct V_2 * V_3 )
{
if ( V_3 -> V_72 )
F_31 ( V_3 -> V_72 , V_3 ) ;
if ( V_3 -> V_32 )
F_31 ( V_3 -> V_32 , V_3 ) ;
}
