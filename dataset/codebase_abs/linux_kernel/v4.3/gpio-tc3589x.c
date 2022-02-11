static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_7 + ( V_4 / 8 ) * 2 ;
T_1 V_8 = 1 << ( V_4 % 8 ) ;
int V_9 ;
V_9 = F_4 ( V_5 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_9 & V_8 ;
}
static void F_5 ( struct V_2 * V_3 , unsigned V_4 , int V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_7 + ( V_4 / 8 ) * 2 ;
unsigned V_11 = V_4 % 8 ;
T_1 V_12 [] = { ! ! V_10 << V_11 , 1 << V_11 } ;
F_6 ( V_5 , V_6 , F_7 ( V_12 ) , V_12 ) ;
}
static int F_8 ( struct V_2 * V_3 ,
unsigned V_4 , int V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_13 + V_4 / 8 ;
unsigned V_11 = V_4 % 8 ;
F_5 ( V_3 , V_4 , V_10 ) ;
return F_9 ( V_5 , V_6 , 1 << V_11 , 1 << V_11 ) ;
}
static int F_10 ( struct V_2 * V_3 ,
unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_13 + V_4 / 8 ;
unsigned V_11 = V_4 % 8 ;
return F_9 ( V_5 , V_6 , 1 << V_11 , 0 ) ;
}
static int F_11 ( struct V_14 * V_15 , unsigned int type )
{
struct V_2 * V_16 = F_12 ( V_15 ) ;
struct V_1 * V_1 = F_1 ( V_16 ) ;
int V_4 = V_15 -> V_17 ;
int V_18 = V_4 / 8 ;
int V_8 = 1 << ( V_4 % 8 ) ;
if ( type == V_19 ) {
V_1 -> V_20 [ V_21 ] [ V_18 ] |= V_8 ;
return 0 ;
}
V_1 -> V_20 [ V_21 ] [ V_18 ] &= ~ V_8 ;
if ( type == V_22 || type == V_23 )
V_1 -> V_20 [ V_24 ] [ V_18 ] |= V_8 ;
else
V_1 -> V_20 [ V_24 ] [ V_18 ] &= ~ V_8 ;
if ( type == V_25 || type == V_23 )
V_1 -> V_20 [ V_26 ] [ V_18 ] |= V_8 ;
else
V_1 -> V_20 [ V_26 ] [ V_18 ] &= ~ V_8 ;
return 0 ;
}
static void F_13 ( struct V_14 * V_15 )
{
struct V_2 * V_16 = F_12 ( V_15 ) ;
struct V_1 * V_1 = F_1 ( V_16 ) ;
F_14 ( & V_1 -> V_27 ) ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_2 * V_16 = F_12 ( V_15 ) ;
struct V_1 * V_1 = F_1 ( V_16 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
static const T_1 V_28 [] = {
[ V_21 ] = V_29 ,
[ V_26 ] = V_30 ,
[ V_24 ] = V_31 ,
[ V_32 ] = V_33 ,
} ;
int V_34 , V_35 ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ ) {
for ( V_35 = 0 ; V_35 < V_37 ; V_35 ++ ) {
T_1 V_38 = V_1 -> V_39 [ V_34 ] [ V_35 ] ;
T_1 V_40 = V_1 -> V_20 [ V_34 ] [ V_35 ] ;
if ( V_40 == V_38 )
continue;
V_1 -> V_39 [ V_34 ] [ V_35 ] = V_40 ;
F_16 ( V_5 , V_28 [ V_34 ] + V_35 * 8 , V_40 ) ;
}
}
F_17 ( & V_1 -> V_27 ) ;
}
static void F_18 ( struct V_14 * V_15 )
{
struct V_2 * V_16 = F_12 ( V_15 ) ;
struct V_1 * V_1 = F_1 ( V_16 ) ;
int V_4 = V_15 -> V_17 ;
int V_18 = V_4 / 8 ;
int V_8 = 1 << ( V_4 % 8 ) ;
V_1 -> V_20 [ V_32 ] [ V_18 ] &= ~ V_8 ;
}
static void F_19 ( struct V_14 * V_15 )
{
struct V_2 * V_16 = F_12 ( V_15 ) ;
struct V_1 * V_1 = F_1 ( V_16 ) ;
int V_4 = V_15 -> V_17 ;
int V_18 = V_4 / 8 ;
int V_8 = 1 << ( V_4 % 8 ) ;
V_1 -> V_20 [ V_32 ] [ V_18 ] |= V_8 ;
}
static T_2 F_20 ( int V_41 , void * V_42 )
{
struct V_1 * V_1 = V_42 ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_43 [ V_37 ] ;
int V_9 ;
int V_34 ;
V_9 = F_21 ( V_5 , V_44 ,
F_7 ( V_43 ) , V_43 ) ;
if ( V_9 < 0 )
return V_45 ;
for ( V_34 = 0 ; V_34 < F_7 ( V_43 ) ; V_34 ++ ) {
unsigned int V_46 = V_43 [ V_34 ] ;
if ( ! V_46 )
continue;
while ( V_46 ) {
int V_47 = F_22 ( V_46 ) ;
int line = V_34 * 8 + V_47 ;
int V_41 = F_23 ( V_1 -> V_3 . V_48 ,
line ) ;
F_24 ( V_41 ) ;
V_46 &= ~ ( 1 << V_47 ) ;
}
F_16 ( V_5 , V_49 + V_34 , V_43 [ V_34 ] ) ;
}
return V_50 ;
}
static int F_25 ( struct V_51 * V_52 )
{
struct V_5 * V_5 = F_26 ( V_52 -> V_42 . V_53 ) ;
struct V_54 * V_55 = V_52 -> V_42 . V_56 ;
struct V_1 * V_1 ;
int V_9 ;
int V_41 ;
if ( ! V_55 ) {
F_27 ( & V_52 -> V_42 , L_1 ) ;
return - V_57 ;
}
V_41 = F_28 ( V_52 , 0 ) ;
if ( V_41 < 0 )
return V_41 ;
V_1 = F_29 ( & V_52 -> V_42 , sizeof( struct V_1 ) ,
V_58 ) ;
if ( ! V_1 )
return - V_59 ;
F_30 ( & V_1 -> V_27 ) ;
V_1 -> V_42 = & V_52 -> V_42 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_3 = V_60 ;
V_1 -> V_3 . V_61 = V_5 -> V_62 ;
V_1 -> V_3 . V_42 = & V_52 -> V_42 ;
V_1 -> V_3 . V_63 = - 1 ;
V_1 -> V_3 . V_56 = V_55 ;
V_9 = F_9 ( V_5 , V_64 ,
V_65 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_31 ( & V_52 -> V_42 ,
V_41 , NULL , F_20 ,
V_66 , L_2 ,
V_1 ) ;
if ( V_9 ) {
F_27 ( & V_52 -> V_42 , L_3 , V_9 ) ;
return V_9 ;
}
V_9 = F_32 ( & V_1 -> V_3 ) ;
if ( V_9 ) {
F_27 ( & V_52 -> V_42 , L_4 , V_9 ) ;
return V_9 ;
}
V_9 = F_33 ( & V_1 -> V_3 ,
& V_67 ,
0 ,
V_68 ,
V_69 ) ;
if ( V_9 ) {
F_27 ( & V_52 -> V_42 ,
L_5 ) ;
return V_9 ;
}
F_34 ( & V_1 -> V_3 ,
& V_67 ,
V_41 ,
NULL ) ;
F_35 ( V_52 , V_1 ) ;
return 0 ;
}
static int F_36 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_37 ( V_52 ) ;
F_38 ( & V_1 -> V_3 ) ;
return 0 ;
}
static int T_3 F_39 ( void )
{
return F_40 ( & V_70 ) ;
}
static void T_4 F_41 ( void )
{
F_42 ( & V_70 ) ;
}
