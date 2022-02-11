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
return V_10 & V_9 ;
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
return V_1 -> V_16 + V_4 ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
if ( V_1 -> V_17 & ( 1 << V_4 ) )
return - V_18 ;
return F_12 ( V_5 , 1 << V_4 , V_19 ) ;
}
static int F_13 ( struct V_20 * V_21 , unsigned int type )
{
struct V_1 * V_1 = F_14 ( V_21 ) ;
int V_4 = V_21 -> V_22 - V_1 -> V_16 ;
int V_23 = V_4 / 8 ;
int V_9 = 1 << ( V_4 % 8 ) ;
if ( type == V_24 || type == V_25 )
return - V_18 ;
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
static void F_15 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_14 ( V_21 ) ;
F_16 ( & V_1 -> V_32 ) ;
}
static void F_17 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_14 ( V_21 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
int V_33 = F_18 ( V_5 -> V_34 , 8 ) ;
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
F_19 ( & V_1 -> V_32 ) ;
}
static void F_20 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_14 ( V_21 ) ;
int V_4 = V_21 -> V_22 - V_1 -> V_16 ;
int V_23 = V_4 / 8 ;
int V_9 = 1 << ( V_4 % 8 ) ;
V_1 -> V_7 [ V_38 ] [ V_23 ] &= ~ V_9 ;
}
static void F_21 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_14 ( V_21 ) ;
int V_4 = V_21 -> V_22 - V_1 -> V_16 ;
int V_23 = V_4 / 8 ;
int V_9 = 1 << ( V_4 % 8 ) ;
V_1 -> V_7 [ V_38 ] [ V_23 ] |= V_9 ;
}
static T_2 F_22 ( int V_22 , void * V_46 )
{
struct V_1 * V_1 = V_46 ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_47 = V_5 -> V_7 [ V_48 ] ;
int V_33 = F_18 ( V_5 -> V_34 , 8 ) ;
T_1 V_49 [ V_33 ] ;
int V_10 ;
int V_40 ;
V_10 = F_23 ( V_5 , V_47 , V_33 , V_49 ) ;
if ( V_10 < 0 )
return V_50 ;
for ( V_40 = 0 ; V_40 < V_33 ; V_40 ++ ) {
int V_51 = V_33 - V_40 - 1 ;
unsigned int V_52 = V_1 -> V_7 [ V_38 ] [ V_51 ] ;
unsigned int V_53 = V_49 [ V_40 ] ;
V_53 &= V_52 ;
if ( ! V_53 )
continue;
while ( V_53 ) {
int V_54 = F_24 ( V_53 ) ;
int line = V_51 * 8 + V_54 ;
F_25 ( V_1 -> V_16 + line ) ;
V_53 &= ~ ( 1 << V_54 ) ;
}
F_7 ( V_5 , V_47 + V_40 , V_49 [ V_40 ] ) ;
if ( V_5 -> V_26 != V_27 )
F_7 ( V_5 , V_5 -> V_7 [ V_55 ]
+ V_40 , V_49 [ V_40 ] ) ;
}
return V_56 ;
}
static int T_3 F_26 ( struct V_1 * V_1 )
{
int V_57 = V_1 -> V_16 ;
int V_22 ;
for ( V_22 = V_57 ; V_22 < V_57 + V_1 -> V_3 . V_58 ; V_22 ++ ) {
F_27 ( V_22 , V_1 ) ;
F_28 ( V_22 , & V_59 ,
V_60 ) ;
F_29 ( V_22 , 1 ) ;
#ifdef F_30
F_31 ( V_22 , V_61 ) ;
#else
F_32 ( V_22 ) ;
#endif
}
return 0 ;
}
static void F_33 ( struct V_1 * V_1 )
{
int V_57 = V_1 -> V_16 ;
int V_22 ;
for ( V_22 = V_57 ; V_22 < V_57 + V_1 -> V_3 . V_58 ; V_22 ++ ) {
#ifdef F_30
F_31 ( V_22 , 0 ) ;
#endif
F_28 ( V_22 , NULL , NULL ) ;
F_27 ( V_22 , NULL ) ;
}
}
static int T_3 F_34 ( struct V_62 * V_63 )
{
struct V_5 * V_5 = F_35 ( V_63 -> V_46 . V_64 ) ;
struct V_65 * V_66 ;
struct V_1 * V_1 ;
int V_10 ;
int V_22 ;
V_66 = V_5 -> V_66 -> V_67 ;
V_22 = F_36 ( V_63 , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
V_1 = F_37 ( sizeof( struct V_1 ) , V_68 ) ;
if ( ! V_1 )
return - V_69 ;
F_38 ( & V_1 -> V_32 ) ;
V_1 -> V_46 = & V_63 -> V_46 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_17 = V_66 ? V_66 -> V_17 : 0 ;
V_1 -> V_3 = V_70 ;
V_1 -> V_3 . V_58 = V_5 -> V_34 ;
V_1 -> V_3 . V_46 = & V_63 -> V_46 ;
V_1 -> V_3 . V_57 = V_66 ? V_66 -> V_71 : - 1 ;
V_1 -> V_16 = V_5 -> V_16 + F_39 ( 0 ) ;
V_10 = F_40 ( V_5 , V_19 ) ;
if ( V_10 )
goto V_72;
V_10 = F_26 ( V_1 ) ;
if ( V_10 )
goto V_73;
V_10 = F_41 ( V_22 , NULL , F_22 , V_74 ,
L_1 , V_1 ) ;
if ( V_10 ) {
F_42 ( & V_63 -> V_46 , L_2 , V_10 ) ;
goto V_75;
}
V_10 = F_43 ( & V_1 -> V_3 ) ;
if ( V_10 ) {
F_42 ( & V_63 -> V_46 , L_3 , V_10 ) ;
goto V_76;
}
if ( V_66 && V_66 -> V_77 )
V_66 -> V_77 ( V_5 , V_1 -> V_3 . V_57 ) ;
F_44 ( V_63 , V_1 ) ;
return 0 ;
V_76:
F_45 ( V_22 , V_1 ) ;
V_75:
F_33 ( V_1 ) ;
V_73:
F_46 ( V_5 , V_19 ) ;
V_72:
F_47 ( V_1 ) ;
return V_10 ;
}
static int T_4 F_48 ( struct V_62 * V_63 )
{
struct V_1 * V_1 = F_49 ( V_63 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
struct V_65 * V_66 = V_5 -> V_66 -> V_67 ;
int V_22 = F_36 ( V_63 , 0 ) ;
int V_10 ;
if ( V_66 && V_66 -> remove )
V_66 -> remove ( V_5 , V_1 -> V_3 . V_57 ) ;
V_10 = F_50 ( & V_1 -> V_3 ) ;
if ( V_10 < 0 ) {
F_42 ( V_1 -> V_46 ,
L_4 , V_10 ) ;
return V_10 ;
}
F_46 ( V_5 , V_19 ) ;
F_45 ( V_22 , V_1 ) ;
F_33 ( V_1 ) ;
F_44 ( V_63 , NULL ) ;
F_47 ( V_1 ) ;
return 0 ;
}
static int T_5 F_51 ( void )
{
return F_52 ( & V_78 ) ;
}
static void T_6 F_53 ( void )
{
F_54 ( & V_78 ) ;
}
