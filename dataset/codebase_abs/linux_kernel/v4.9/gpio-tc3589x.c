static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_7 + ( V_3 / 8 ) * 2 ;
T_1 V_8 = F_3 ( V_3 % 8 ) ;
int V_9 ;
V_9 = F_4 ( V_5 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
return ! ! ( V_9 & V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_3 , int V_10 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_7 + ( V_3 / 8 ) * 2 ;
unsigned int V_11 = V_3 % 8 ;
T_1 V_12 [] = { V_10 ? F_3 ( V_11 ) : 0 , F_3 (pos) } ;
F_6 ( V_5 , V_6 , F_7 ( V_12 ) , V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_10 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_13 + V_3 / 8 ;
unsigned int V_11 = V_3 % 8 ;
F_5 ( V_2 , V_3 , V_10 ) ;
return F_9 ( V_5 , V_6 , F_3 ( V_11 ) , F_3 ( V_11 ) ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_13 + V_3 / 8 ;
unsigned int V_11 = V_3 % 8 ;
return F_9 ( V_5 , V_6 , F_3 ( V_11 ) , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_13 + V_3 / 8 ;
unsigned int V_11 = V_3 % 8 ;
int V_9 ;
V_9 = F_4 ( V_5 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
return ! ( V_9 & F_3 ( V_11 ) ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_14 V_15 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_16 = V_17 + ( V_3 / 8 ) * 2 ;
T_1 V_18 = V_19 + ( V_3 / 8 ) * 2 ;
unsigned int V_11 = V_3 % 8 ;
int V_9 ;
switch( V_15 ) {
case V_20 :
V_9 = F_9 ( V_5 , V_16 , F_3 ( V_11 ) , 0 ) ;
if ( V_9 )
return V_9 ;
return F_9 ( V_5 , V_18 , F_3 ( V_11 ) , F_3 ( V_11 ) ) ;
case V_21 :
V_9 = F_9 ( V_5 , V_16 , F_3 ( V_11 ) , F_3 ( V_11 ) ) ;
if ( V_9 )
return V_9 ;
return F_9 ( V_5 , V_18 , F_3 ( V_11 ) , F_3 ( V_11 ) ) ;
case V_22 :
return F_9 ( V_5 , V_18 , F_3 ( V_11 ) , 0 ) ;
default:
break;
}
return - V_23 ;
}
static int F_13 ( struct V_24 * V_25 , unsigned int type )
{
struct V_1 * V_26 = F_14 ( V_25 ) ;
struct V_4 * V_4 = F_2 ( V_26 ) ;
int V_3 = V_25 -> V_27 ;
int V_28 = V_3 / 8 ;
int V_8 = F_3 ( V_3 % 8 ) ;
if ( type == V_29 ) {
V_4 -> V_30 [ V_31 ] [ V_28 ] |= V_8 ;
return 0 ;
}
V_4 -> V_30 [ V_31 ] [ V_28 ] &= ~ V_8 ;
if ( type == V_32 || type == V_33 )
V_4 -> V_30 [ V_34 ] [ V_28 ] |= V_8 ;
else
V_4 -> V_30 [ V_34 ] [ V_28 ] &= ~ V_8 ;
if ( type == V_35 || type == V_33 )
V_4 -> V_30 [ V_36 ] [ V_28 ] |= V_8 ;
else
V_4 -> V_30 [ V_36 ] [ V_28 ] &= ~ V_8 ;
return 0 ;
}
static void F_15 ( struct V_24 * V_25 )
{
struct V_1 * V_26 = F_14 ( V_25 ) ;
struct V_4 * V_4 = F_2 ( V_26 ) ;
F_16 ( & V_4 -> V_37 ) ;
}
static void F_17 ( struct V_24 * V_25 )
{
struct V_1 * V_26 = F_14 ( V_25 ) ;
struct V_4 * V_4 = F_2 ( V_26 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
static const T_1 V_38 [] = {
[ V_31 ] = V_39 ,
[ V_36 ] = V_40 ,
[ V_34 ] = V_41 ,
[ V_42 ] = V_43 ,
} ;
int V_44 , V_45 ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ ) {
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
T_1 V_48 = V_4 -> V_49 [ V_44 ] [ V_45 ] ;
T_1 V_50 = V_4 -> V_30 [ V_44 ] [ V_45 ] ;
if ( V_50 == V_48 )
continue;
V_4 -> V_49 [ V_44 ] [ V_45 ] = V_50 ;
F_18 ( V_5 , V_38 [ V_44 ] + V_45 * 8 , V_50 ) ;
}
}
F_19 ( & V_4 -> V_37 ) ;
}
static void F_20 ( struct V_24 * V_25 )
{
struct V_1 * V_26 = F_14 ( V_25 ) ;
struct V_4 * V_4 = F_2 ( V_26 ) ;
int V_3 = V_25 -> V_27 ;
int V_28 = V_3 / 8 ;
int V_8 = F_3 ( V_3 % 8 ) ;
V_4 -> V_30 [ V_42 ] [ V_28 ] &= ~ V_8 ;
}
static void F_21 ( struct V_24 * V_25 )
{
struct V_1 * V_26 = F_14 ( V_25 ) ;
struct V_4 * V_4 = F_2 ( V_26 ) ;
int V_3 = V_25 -> V_27 ;
int V_28 = V_3 / 8 ;
int V_8 = F_3 ( V_3 % 8 ) ;
V_4 -> V_30 [ V_42 ] [ V_28 ] |= V_8 ;
}
static T_2 F_22 ( int V_51 , void * V_52 )
{
struct V_4 * V_4 = V_52 ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_53 [ V_47 ] ;
int V_9 ;
int V_44 ;
V_9 = F_23 ( V_5 , V_54 ,
F_7 ( V_53 ) , V_53 ) ;
if ( V_9 < 0 )
return V_55 ;
for ( V_44 = 0 ; V_44 < F_7 ( V_53 ) ; V_44 ++ ) {
unsigned int V_56 = V_53 [ V_44 ] ;
if ( ! V_56 )
continue;
while ( V_56 ) {
int V_57 = F_24 ( V_56 ) ;
int line = V_44 * 8 + V_57 ;
int V_51 = F_25 ( V_4 -> V_2 . V_58 ,
line ) ;
F_26 ( V_51 ) ;
V_56 &= ~ ( 1 << V_57 ) ;
}
F_18 ( V_5 , V_59 + V_44 , V_53 [ V_44 ] ) ;
}
return V_60 ;
}
static int F_27 ( struct V_61 * V_62 )
{
struct V_5 * V_5 = F_28 ( V_62 -> V_52 . V_63 ) ;
struct V_64 * V_65 = V_62 -> V_52 . V_66 ;
struct V_4 * V_4 ;
int V_9 ;
int V_51 ;
if ( ! V_65 ) {
F_29 ( & V_62 -> V_52 , L_1 ) ;
return - V_67 ;
}
V_51 = F_30 ( V_62 , 0 ) ;
if ( V_51 < 0 )
return V_51 ;
V_4 = F_31 ( & V_62 -> V_52 , sizeof( struct V_4 ) ,
V_68 ) ;
if ( ! V_4 )
return - V_69 ;
F_32 ( & V_4 -> V_37 ) ;
V_4 -> V_52 = & V_62 -> V_52 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_2 = V_70 ;
V_4 -> V_2 . V_71 = V_5 -> V_72 ;
V_4 -> V_2 . V_63 = & V_62 -> V_52 ;
V_4 -> V_2 . V_73 = - 1 ;
V_4 -> V_2 . V_66 = V_65 ;
V_9 = F_9 ( V_5 , V_74 ,
V_75 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_33 ( & V_62 -> V_52 ,
V_51 , NULL , F_22 ,
V_76 , L_2 ,
V_4 ) ;
if ( V_9 ) {
F_29 ( & V_62 -> V_52 , L_3 , V_9 ) ;
return V_9 ;
}
V_9 = F_34 ( & V_62 -> V_52 , & V_4 -> V_2 ,
V_4 ) ;
if ( V_9 ) {
F_29 ( & V_62 -> V_52 , L_4 , V_9 ) ;
return V_9 ;
}
V_9 = F_35 ( & V_4 -> V_2 ,
& V_77 ,
0 ,
V_78 ,
V_79 ) ;
if ( V_9 ) {
F_29 ( & V_62 -> V_52 ,
L_5 ) ;
return V_9 ;
}
F_36 ( & V_4 -> V_2 ,
& V_77 ,
V_51 ,
NULL ) ;
F_37 ( V_62 , V_4 ) ;
return 0 ;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_80 ) ;
}
