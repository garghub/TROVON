static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_8 ] - ( V_4 / 8 ) ;
T_1 V_9 = 1 << ( V_4 % 8 ) ;
int V_10 ;
V_10 = F_4 ( V_5 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
return ! ! ( V_10 & V_9 ) ;
}
static void F_5 ( struct V_2 * V_3 , unsigned V_4 , int V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
int V_12 = V_11 ? V_13 : V_14 ;
T_1 V_6 = V_5 -> V_7 [ V_12 ] - ( V_4 / 8 ) ;
T_1 V_9 = 1 << ( V_4 % 8 ) ;
if ( V_5 -> V_7 [ V_13 ] == V_5 -> V_7 [ V_14 ] )
F_6 ( V_5 , V_6 , V_9 , V_11 ? V_9 : 0 ) ;
else
F_7 ( V_5 , V_6 , V_9 ) ;
}
static int F_8 ( struct V_2 * V_3 ,
unsigned V_4 , int V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_15 ] - ( V_4 / 8 ) ;
T_1 V_9 = 1 << ( V_4 % 8 ) ;
F_5 ( V_3 , V_4 , V_11 ) ;
return F_6 ( V_5 , V_6 , V_9 , V_9 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_15 ] - ( V_4 / 8 ) ;
T_1 V_9 = 1 << ( V_4 % 8 ) ;
return F_6 ( V_5 , V_6 , V_9 , 0 ) ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
if ( V_1 -> V_16 & ( 1 << V_4 ) )
return - V_17 ;
return F_11 ( V_5 , 1 << V_4 , V_18 ) ;
}
static int F_12 ( struct V_19 * V_20 , unsigned int type )
{
struct V_2 * V_21 = F_13 ( V_20 ) ;
struct V_1 * V_1 = F_1 ( V_21 ) ;
int V_4 = V_20 -> V_22 ;
int V_23 = V_4 / 8 ;
int V_9 = 1 << ( V_4 % 8 ) ;
if ( type == V_24 || type == V_25 )
return - V_17 ;
if ( V_1 -> V_5 -> V_26 == V_27 )
return 0 ;
if ( type == V_28 )
V_1 -> V_7 [ V_29 ] [ V_23 ] |= V_9 ;
else
V_1 -> V_7 [ V_29 ] [ V_23 ] &= ~ V_9 ;
if ( type == V_30 )
V_1 -> V_7 [ V_31 ] [ V_23 ] |= V_9 ;
else
V_1 -> V_7 [ V_31 ] [ V_23 ] &= ~ V_9 ;
return 0 ;
}
static void F_14 ( struct V_19 * V_20 )
{
struct V_2 * V_21 = F_13 ( V_20 ) ;
struct V_1 * V_1 = F_1 ( V_21 ) ;
F_15 ( & V_1 -> V_32 ) ;
}
static void F_16 ( struct V_19 * V_20 )
{
struct V_2 * V_21 = F_13 ( V_20 ) ;
struct V_1 * V_1 = F_1 ( V_21 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
int V_33 = F_17 ( V_5 -> V_34 , 8 ) ;
static const T_1 V_35 [] = {
[ V_29 ] = V_36 ,
[ V_31 ] = V_37 ,
[ V_38 ] = V_39 ,
} ;
int V_40 , V_41 ;
for ( V_40 = 0 ; V_40 < V_42 ; V_40 ++ ) {
if ( ( V_5 -> V_26 == V_27 ) &&
( V_40 != V_38 ) )
continue;
for ( V_41 = 0 ; V_41 < V_33 ; V_41 ++ ) {
T_1 V_43 = V_1 -> V_44 [ V_40 ] [ V_41 ] ;
T_1 V_45 = V_1 -> V_7 [ V_40 ] [ V_41 ] ;
if ( V_45 == V_43 )
continue;
V_1 -> V_44 [ V_40 ] [ V_41 ] = V_45 ;
F_7 ( V_5 , V_5 -> V_7 [ V_35 [ V_40 ] ] - V_41 , V_45 ) ;
}
}
F_18 ( & V_1 -> V_32 ) ;
}
static void F_19 ( struct V_19 * V_20 )
{
struct V_2 * V_21 = F_13 ( V_20 ) ;
struct V_1 * V_1 = F_1 ( V_21 ) ;
int V_4 = V_20 -> V_22 ;
int V_23 = V_4 / 8 ;
int V_9 = 1 << ( V_4 % 8 ) ;
V_1 -> V_7 [ V_38 ] [ V_23 ] &= ~ V_9 ;
}
static void F_20 ( struct V_19 * V_20 )
{
struct V_2 * V_21 = F_13 ( V_20 ) ;
struct V_1 * V_1 = F_1 ( V_21 ) ;
int V_4 = V_20 -> V_22 ;
int V_23 = V_4 / 8 ;
int V_9 = 1 << ( V_4 % 8 ) ;
V_1 -> V_7 [ V_38 ] [ V_23 ] |= V_9 ;
}
static T_2 F_21 ( int V_46 , void * V_47 )
{
struct V_1 * V_1 = V_47 ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_48 = V_5 -> V_7 [ V_49 ] ;
int V_33 = F_17 ( V_5 -> V_34 , 8 ) ;
T_1 V_50 [ V_33 ] ;
int V_10 ;
int V_40 ;
V_10 = F_22 ( V_5 , V_48 , V_33 , V_50 ) ;
if ( V_10 < 0 )
return V_51 ;
for ( V_40 = 0 ; V_40 < V_33 ; V_40 ++ ) {
int V_52 = V_33 - V_40 - 1 ;
unsigned int V_53 = V_1 -> V_7 [ V_38 ] [ V_52 ] ;
unsigned int V_54 = V_50 [ V_40 ] ;
V_54 &= V_53 ;
if ( ! V_54 )
continue;
while ( V_54 ) {
int V_55 = F_23 ( V_54 ) ;
int line = V_52 * 8 + V_55 ;
int V_56 = F_24 ( V_1 -> V_3 . V_57 ,
line ) ;
F_25 ( V_56 ) ;
V_54 &= ~ ( 1 << V_55 ) ;
}
F_7 ( V_5 , V_48 + V_40 , V_50 [ V_40 ] ) ;
if ( V_5 -> V_26 != V_27 )
F_7 ( V_5 , V_5 -> V_7 [ V_58 ]
+ V_40 , V_50 [ V_40 ] ) ;
}
return V_59 ;
}
static int F_26 ( struct V_60 * V_61 )
{
struct V_5 * V_5 = F_27 ( V_61 -> V_47 . V_62 ) ;
struct V_63 * V_64 = V_61 -> V_47 . V_65 ;
struct V_66 * V_67 ;
struct V_1 * V_1 ;
int V_10 ;
int V_46 = 0 ;
V_67 = V_5 -> V_67 -> V_68 ;
V_46 = F_28 ( V_61 , 0 ) ;
V_1 = F_29 ( sizeof( struct V_1 ) , V_69 ) ;
if ( ! V_1 )
return - V_70 ;
F_30 ( & V_1 -> V_32 ) ;
V_1 -> V_47 = & V_61 -> V_47 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_3 = V_71 ;
V_1 -> V_3 . V_72 = V_5 -> V_34 ;
V_1 -> V_3 . V_47 = & V_61 -> V_47 ;
#ifdef F_31
V_1 -> V_3 . V_65 = V_64 ;
#endif
V_1 -> V_3 . V_73 = - 1 ;
if ( V_67 )
V_1 -> V_16 = V_67 -> V_16 ;
else if ( V_64 )
F_32 ( V_64 , L_1 ,
& V_1 -> V_16 ) ;
if ( V_46 < 0 )
F_33 ( & V_61 -> V_47 ,
L_2
L_3 ) ;
V_10 = F_34 ( V_5 , V_18 ) ;
if ( V_10 )
goto V_74;
if ( V_46 > 0 ) {
V_10 = F_35 ( & V_61 -> V_47 , V_46 , NULL ,
F_21 , V_75 ,
L_4 , V_1 ) ;
if ( V_10 ) {
F_36 ( & V_61 -> V_47 , L_5 , V_10 ) ;
goto V_76;
}
V_10 = F_37 ( & V_1 -> V_3 ,
& V_77 ,
0 ,
V_78 ,
V_79 ) ;
if ( V_10 ) {
F_36 ( & V_61 -> V_47 ,
L_6 ) ;
return V_10 ;
}
}
V_10 = F_38 ( & V_1 -> V_3 ) ;
if ( V_10 ) {
F_36 ( & V_61 -> V_47 , L_7 , V_10 ) ;
goto V_76;
}
if ( V_67 && V_67 -> V_80 )
V_67 -> V_80 ( V_5 , V_1 -> V_3 . V_73 ) ;
F_39 ( V_61 , V_1 ) ;
return 0 ;
V_76:
F_40 ( V_5 , V_18 ) ;
V_74:
F_41 ( V_1 ) ;
return V_10 ;
}
static int F_42 ( struct V_60 * V_61 )
{
struct V_1 * V_1 = F_43 ( V_61 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
struct V_66 * V_67 = V_5 -> V_67 -> V_68 ;
if ( V_67 && V_67 -> remove )
V_67 -> remove ( V_5 , V_1 -> V_3 . V_73 ) ;
F_44 ( & V_1 -> V_3 ) ;
F_40 ( V_5 , V_18 ) ;
F_41 ( V_1 ) ;
return 0 ;
}
static int T_3 F_45 ( void )
{
return F_46 ( & V_81 ) ;
}
static void T_4 F_47 ( void )
{
F_48 ( & V_81 ) ;
}
