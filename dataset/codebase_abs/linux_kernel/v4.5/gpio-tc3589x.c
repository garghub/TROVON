static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_7 + ( V_3 / 8 ) * 2 ;
T_1 V_8 = 1 << ( V_3 % 8 ) ;
int V_9 ;
V_9 = F_3 ( V_5 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
return ! ! ( V_9 & V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 , int V_10 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_7 + ( V_3 / 8 ) * 2 ;
unsigned V_11 = V_3 % 8 ;
T_1 V_12 [] = { ! ! V_10 << V_11 , 1 << V_11 } ;
F_5 ( V_5 , V_6 , F_6 ( V_12 ) , V_12 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_3 , int V_10 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_13 + V_3 / 8 ;
unsigned V_11 = V_3 % 8 ;
F_4 ( V_2 , V_3 , V_10 ) ;
return F_8 ( V_5 , V_6 , 1 << V_11 , 1 << V_11 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_13 + V_3 / 8 ;
unsigned V_11 = V_3 % 8 ;
return F_8 ( V_5 , V_6 , 1 << V_11 , 0 ) ;
}
static int F_10 ( struct V_14 * V_15 , unsigned int type )
{
struct V_1 * V_16 = F_11 ( V_15 ) ;
struct V_4 * V_4 = F_2 ( V_16 ) ;
int V_3 = V_15 -> V_17 ;
int V_18 = V_3 / 8 ;
int V_8 = 1 << ( V_3 % 8 ) ;
if ( type == V_19 ) {
V_4 -> V_20 [ V_21 ] [ V_18 ] |= V_8 ;
return 0 ;
}
V_4 -> V_20 [ V_21 ] [ V_18 ] &= ~ V_8 ;
if ( type == V_22 || type == V_23 )
V_4 -> V_20 [ V_24 ] [ V_18 ] |= V_8 ;
else
V_4 -> V_20 [ V_24 ] [ V_18 ] &= ~ V_8 ;
if ( type == V_25 || type == V_23 )
V_4 -> V_20 [ V_26 ] [ V_18 ] |= V_8 ;
else
V_4 -> V_20 [ V_26 ] [ V_18 ] &= ~ V_8 ;
return 0 ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_1 * V_16 = F_11 ( V_15 ) ;
struct V_4 * V_4 = F_2 ( V_16 ) ;
F_13 ( & V_4 -> V_27 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_1 * V_16 = F_11 ( V_15 ) ;
struct V_4 * V_4 = F_2 ( V_16 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
static const T_1 V_28 [] = {
[ V_21 ] = V_29 ,
[ V_26 ] = V_30 ,
[ V_24 ] = V_31 ,
[ V_32 ] = V_33 ,
} ;
int V_34 , V_35 ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ ) {
for ( V_35 = 0 ; V_35 < V_37 ; V_35 ++ ) {
T_1 V_38 = V_4 -> V_39 [ V_34 ] [ V_35 ] ;
T_1 V_40 = V_4 -> V_20 [ V_34 ] [ V_35 ] ;
if ( V_40 == V_38 )
continue;
V_4 -> V_39 [ V_34 ] [ V_35 ] = V_40 ;
F_15 ( V_5 , V_28 [ V_34 ] + V_35 * 8 , V_40 ) ;
}
}
F_16 ( & V_4 -> V_27 ) ;
}
static void F_17 ( struct V_14 * V_15 )
{
struct V_1 * V_16 = F_11 ( V_15 ) ;
struct V_4 * V_4 = F_2 ( V_16 ) ;
int V_3 = V_15 -> V_17 ;
int V_18 = V_3 / 8 ;
int V_8 = 1 << ( V_3 % 8 ) ;
V_4 -> V_20 [ V_32 ] [ V_18 ] &= ~ V_8 ;
}
static void F_18 ( struct V_14 * V_15 )
{
struct V_1 * V_16 = F_11 ( V_15 ) ;
struct V_4 * V_4 = F_2 ( V_16 ) ;
int V_3 = V_15 -> V_17 ;
int V_18 = V_3 / 8 ;
int V_8 = 1 << ( V_3 % 8 ) ;
V_4 -> V_20 [ V_32 ] [ V_18 ] |= V_8 ;
}
static T_2 F_19 ( int V_41 , void * V_42 )
{
struct V_4 * V_4 = V_42 ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_43 [ V_37 ] ;
int V_9 ;
int V_34 ;
V_9 = F_20 ( V_5 , V_44 ,
F_6 ( V_43 ) , V_43 ) ;
if ( V_9 < 0 )
return V_45 ;
for ( V_34 = 0 ; V_34 < F_6 ( V_43 ) ; V_34 ++ ) {
unsigned int V_46 = V_43 [ V_34 ] ;
if ( ! V_46 )
continue;
while ( V_46 ) {
int V_47 = F_21 ( V_46 ) ;
int line = V_34 * 8 + V_47 ;
int V_41 = F_22 ( V_4 -> V_2 . V_48 ,
line ) ;
F_23 ( V_41 ) ;
V_46 &= ~ ( 1 << V_47 ) ;
}
F_15 ( V_5 , V_49 + V_34 , V_43 [ V_34 ] ) ;
}
return V_50 ;
}
static int F_24 ( struct V_51 * V_52 )
{
struct V_5 * V_5 = F_25 ( V_52 -> V_42 . V_53 ) ;
struct V_54 * V_55 = V_52 -> V_42 . V_56 ;
struct V_4 * V_4 ;
int V_9 ;
int V_41 ;
if ( ! V_55 ) {
F_26 ( & V_52 -> V_42 , L_1 ) ;
return - V_57 ;
}
V_41 = F_27 ( V_52 , 0 ) ;
if ( V_41 < 0 )
return V_41 ;
V_4 = F_28 ( & V_52 -> V_42 , sizeof( struct V_4 ) ,
V_58 ) ;
if ( ! V_4 )
return - V_59 ;
F_29 ( & V_4 -> V_27 ) ;
V_4 -> V_42 = & V_52 -> V_42 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_2 = V_60 ;
V_4 -> V_2 . V_61 = V_5 -> V_62 ;
V_4 -> V_2 . V_53 = & V_52 -> V_42 ;
V_4 -> V_2 . V_63 = - 1 ;
V_4 -> V_2 . V_56 = V_55 ;
V_9 = F_8 ( V_5 , V_64 ,
V_65 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_30 ( & V_52 -> V_42 ,
V_41 , NULL , F_19 ,
V_66 , L_2 ,
V_4 ) ;
if ( V_9 ) {
F_26 ( & V_52 -> V_42 , L_3 , V_9 ) ;
return V_9 ;
}
V_9 = F_31 ( & V_4 -> V_2 , V_4 ) ;
if ( V_9 ) {
F_26 ( & V_52 -> V_42 , L_4 , V_9 ) ;
return V_9 ;
}
V_9 = F_32 ( & V_4 -> V_2 ,
& V_67 ,
0 ,
V_68 ,
V_69 ) ;
if ( V_9 ) {
F_26 ( & V_52 -> V_42 ,
L_5 ) ;
return V_9 ;
}
F_33 ( & V_4 -> V_2 ,
& V_67 ,
V_41 ,
NULL ) ;
F_34 ( V_52 , V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_51 * V_52 )
{
struct V_4 * V_4 = F_36 ( V_52 ) ;
F_37 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_70 ) ;
}
static void T_4 F_40 ( void )
{
F_41 ( & V_70 ) ;
}
