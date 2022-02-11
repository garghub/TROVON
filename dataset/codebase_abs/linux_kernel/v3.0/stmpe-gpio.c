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
F_6 ( V_5 , V_6 , V_9 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
unsigned V_4 , int V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_15 ] - ( V_4 / 8 ) ;
T_1 V_9 = 1 << ( V_4 % 8 ) ;
F_5 ( V_3 , V_4 , V_11 ) ;
return F_8 ( V_5 , V_6 , V_9 , V_9 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_15 ] - ( V_4 / 8 ) ;
T_1 V_9 = 1 << ( V_4 % 8 ) ;
return F_8 ( V_5 , V_6 , V_9 , 0 ) ;
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
if ( type == V_26 )
V_1 -> V_7 [ V_27 ] [ V_23 ] |= V_9 ;
else
V_1 -> V_7 [ V_27 ] [ V_23 ] &= ~ V_9 ;
if ( type == V_28 )
V_1 -> V_7 [ V_29 ] [ V_23 ] |= V_9 ;
else
V_1 -> V_7 [ V_29 ] [ V_23 ] &= ~ V_9 ;
return 0 ;
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_14 ( V_21 ) ;
F_16 ( & V_1 -> V_30 ) ;
}
static void F_17 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_14 ( V_21 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
int V_31 = F_18 ( V_5 -> V_32 , 8 ) ;
static const T_1 V_33 [] = {
[ V_27 ] = V_34 ,
[ V_29 ] = V_35 ,
[ V_36 ] = V_37 ,
} ;
int V_38 , V_39 ;
for ( V_38 = 0 ; V_38 < V_40 ; V_38 ++ ) {
for ( V_39 = 0 ; V_39 < V_31 ; V_39 ++ ) {
T_1 V_41 = V_1 -> V_42 [ V_38 ] [ V_39 ] ;
T_1 V_43 = V_1 -> V_7 [ V_38 ] [ V_39 ] ;
if ( V_43 == V_41 )
continue;
V_1 -> V_42 [ V_38 ] [ V_39 ] = V_43 ;
F_6 ( V_5 , V_5 -> V_7 [ V_33 [ V_38 ] ] - V_39 , V_43 ) ;
}
}
F_19 ( & V_1 -> V_30 ) ;
}
static void F_20 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_14 ( V_21 ) ;
int V_4 = V_21 -> V_22 - V_1 -> V_16 ;
int V_23 = V_4 / 8 ;
int V_9 = 1 << ( V_4 % 8 ) ;
V_1 -> V_7 [ V_36 ] [ V_23 ] &= ~ V_9 ;
}
static void F_21 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_14 ( V_21 ) ;
int V_4 = V_21 -> V_22 - V_1 -> V_16 ;
int V_23 = V_4 / 8 ;
int V_9 = 1 << ( V_4 % 8 ) ;
V_1 -> V_7 [ V_36 ] [ V_23 ] |= V_9 ;
}
static T_2 F_22 ( int V_22 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_45 = V_5 -> V_7 [ V_46 ] ;
int V_31 = F_18 ( V_5 -> V_32 , 8 ) ;
T_1 V_47 [ V_31 ] ;
int V_10 ;
int V_38 ;
V_10 = F_23 ( V_5 , V_45 , V_31 , V_47 ) ;
if ( V_10 < 0 )
return V_48 ;
for ( V_38 = 0 ; V_38 < V_31 ; V_38 ++ ) {
int V_49 = V_31 - V_38 - 1 ;
unsigned int V_50 = V_1 -> V_7 [ V_36 ] [ V_49 ] ;
unsigned int V_51 = V_47 [ V_38 ] ;
V_51 &= V_50 ;
if ( ! V_51 )
continue;
while ( V_51 ) {
int V_52 = F_24 ( V_51 ) ;
int line = V_49 * 8 + V_52 ;
F_25 ( V_1 -> V_16 + line ) ;
V_51 &= ~ ( 1 << V_52 ) ;
}
F_6 ( V_5 , V_45 + V_38 , V_47 [ V_38 ] ) ;
F_6 ( V_5 , V_5 -> V_7 [ V_53 ] + V_38 ,
V_47 [ V_38 ] ) ;
}
return V_54 ;
}
static int T_3 F_26 ( struct V_1 * V_1 )
{
int V_55 = V_1 -> V_16 ;
int V_22 ;
for ( V_22 = V_55 ; V_22 < V_55 + V_1 -> V_3 . V_56 ; V_22 ++ ) {
F_27 ( V_22 , V_1 ) ;
F_28 ( V_22 , & V_57 ,
V_58 ) ;
F_29 ( V_22 , 1 ) ;
#ifdef F_30
F_31 ( V_22 , V_59 ) ;
#else
F_32 ( V_22 ) ;
#endif
}
return 0 ;
}
static void F_33 ( struct V_1 * V_1 )
{
int V_55 = V_1 -> V_16 ;
int V_22 ;
for ( V_22 = V_55 ; V_22 < V_55 + V_1 -> V_3 . V_56 ; V_22 ++ ) {
#ifdef F_30
F_31 ( V_22 , 0 ) ;
#endif
F_28 ( V_22 , NULL , NULL ) ;
F_27 ( V_22 , NULL ) ;
}
}
static int T_3 F_34 ( struct V_60 * V_61 )
{
struct V_5 * V_5 = F_35 ( V_61 -> V_44 . V_62 ) ;
struct V_63 * V_64 ;
struct V_1 * V_1 ;
int V_10 ;
int V_22 ;
V_64 = V_5 -> V_64 -> V_65 ;
V_22 = F_36 ( V_61 , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
V_1 = F_37 ( sizeof( struct V_1 ) , V_66 ) ;
if ( ! V_1 )
return - V_67 ;
F_38 ( & V_1 -> V_30 ) ;
V_1 -> V_44 = & V_61 -> V_44 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_17 = V_64 ? V_64 -> V_17 : 0 ;
V_1 -> V_3 = V_68 ;
V_1 -> V_3 . V_56 = V_5 -> V_32 ;
V_1 -> V_3 . V_44 = & V_61 -> V_44 ;
V_1 -> V_3 . V_55 = V_64 ? V_64 -> V_69 : - 1 ;
V_1 -> V_16 = V_5 -> V_16 + F_39 ( 0 ) ;
V_10 = F_40 ( V_5 , V_19 ) ;
if ( V_10 )
goto V_70;
V_10 = F_26 ( V_1 ) ;
if ( V_10 )
goto V_71;
V_10 = F_41 ( V_22 , NULL , F_22 , V_72 ,
L_1 , V_1 ) ;
if ( V_10 ) {
F_42 ( & V_61 -> V_44 , L_2 , V_10 ) ;
goto V_73;
}
V_10 = F_43 ( & V_1 -> V_3 ) ;
if ( V_10 ) {
F_42 ( & V_61 -> V_44 , L_3 , V_10 ) ;
goto V_74;
}
if ( V_64 && V_64 -> V_75 )
V_64 -> V_75 ( V_5 , V_1 -> V_3 . V_55 ) ;
F_44 ( V_61 , V_1 ) ;
return 0 ;
V_74:
F_45 ( V_22 , V_1 ) ;
V_73:
F_33 ( V_1 ) ;
V_71:
F_46 ( V_5 , V_19 ) ;
V_70:
F_47 ( V_1 ) ;
return V_10 ;
}
static int T_4 F_48 ( struct V_60 * V_61 )
{
struct V_1 * V_1 = F_49 ( V_61 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
struct V_63 * V_64 = V_5 -> V_64 -> V_65 ;
int V_22 = F_36 ( V_61 , 0 ) ;
int V_10 ;
if ( V_64 && V_64 -> remove )
V_64 -> remove ( V_5 , V_1 -> V_3 . V_55 ) ;
V_10 = F_50 ( & V_1 -> V_3 ) ;
if ( V_10 < 0 ) {
F_42 ( V_1 -> V_44 ,
L_4 , V_10 ) ;
return V_10 ;
}
F_46 ( V_5 , V_19 ) ;
F_45 ( V_22 , V_1 ) ;
F_33 ( V_1 ) ;
F_44 ( V_61 , NULL ) ;
F_47 ( V_1 ) ;
return 0 ;
}
static int T_5 F_51 ( void )
{
return F_52 ( & V_76 ) ;
}
static void T_6 F_53 ( void )
{
F_54 ( & V_76 ) ;
}
