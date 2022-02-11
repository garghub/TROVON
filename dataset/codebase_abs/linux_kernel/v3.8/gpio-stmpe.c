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
return F_11 ( V_1 -> V_16 , V_4 ) ;
}
static int F_12 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
if ( V_1 -> V_17 & ( 1 << V_4 ) )
return - V_18 ;
return F_13 ( V_5 , 1 << V_4 , V_19 ) ;
}
static int F_14 ( struct V_20 * V_21 , unsigned int type )
{
struct V_1 * V_1 = F_15 ( V_21 ) ;
int V_4 = V_21 -> V_22 ;
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
static void F_16 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_15 ( V_21 ) ;
F_17 ( & V_1 -> V_32 ) ;
}
static void F_18 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_15 ( V_21 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
int V_33 = F_19 ( V_5 -> V_34 , 8 ) ;
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
F_20 ( & V_1 -> V_32 ) ;
}
static void F_21 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_15 ( V_21 ) ;
int V_4 = V_21 -> V_22 ;
int V_23 = V_4 / 8 ;
int V_9 = 1 << ( V_4 % 8 ) ;
V_1 -> V_7 [ V_38 ] [ V_23 ] &= ~ V_9 ;
}
static void F_22 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_15 ( V_21 ) ;
int V_4 = V_21 -> V_22 ;
int V_23 = V_4 / 8 ;
int V_9 = 1 << ( V_4 % 8 ) ;
V_1 -> V_7 [ V_38 ] [ V_23 ] |= V_9 ;
}
static T_2 F_23 ( int V_46 , void * V_47 )
{
struct V_1 * V_1 = V_47 ;
struct V_5 * V_5 = V_1 -> V_5 ;
T_1 V_48 = V_5 -> V_7 [ V_49 ] ;
int V_33 = F_19 ( V_5 -> V_34 , 8 ) ;
T_1 V_50 [ V_33 ] ;
int V_10 ;
int V_40 ;
V_10 = F_24 ( V_5 , V_48 , V_33 , V_50 ) ;
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
int V_55 = F_25 ( V_54 ) ;
int line = V_52 * 8 + V_55 ;
int V_56 = F_26 ( V_1 -> V_16 , line ) ;
F_27 ( V_56 ) ;
V_54 &= ~ ( 1 << V_55 ) ;
}
F_7 ( V_5 , V_48 + V_40 , V_50 [ V_40 ] ) ;
if ( V_5 -> V_26 != V_27 )
F_7 ( V_5 , V_5 -> V_7 [ V_57 ]
+ V_40 , V_50 [ V_40 ] ) ;
}
return V_58 ;
}
int F_28 ( struct V_59 * V_21 , unsigned int V_56 ,
T_3 V_22 )
{
struct V_1 * V_1 = V_21 -> V_60 ;
if ( ! V_1 )
return - V_18 ;
F_29 ( V_22 , V_1 ) ;
F_30 ( V_22 , & V_61 ,
V_62 ) ;
F_31 ( V_22 , 1 ) ;
#ifdef F_32
F_33 ( V_22 , V_63 ) ;
#else
F_34 ( V_22 ) ;
#endif
return 0 ;
}
void F_35 ( struct V_59 * V_21 , unsigned int V_56 )
{
#ifdef F_32
F_33 ( V_56 , 0 ) ;
#endif
F_30 ( V_56 , NULL , NULL ) ;
F_29 ( V_56 , NULL ) ;
}
static int F_36 ( struct V_1 * V_1 )
{
int V_64 = V_1 -> V_65 ;
V_1 -> V_16 = F_37 ( NULL ,
V_1 -> V_3 . V_66 , V_64 ,
& V_67 , V_1 ) ;
if ( ! V_1 -> V_16 ) {
F_38 ( V_1 -> V_47 , L_1 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_39 ( struct V_69 * V_70 )
{
struct V_5 * V_5 = F_40 ( V_70 -> V_47 . V_71 ) ;
struct V_72 * V_73 = V_70 -> V_47 . V_74 ;
struct V_75 * V_76 ;
struct V_1 * V_1 ;
int V_10 ;
int V_46 = 0 ;
V_76 = V_5 -> V_76 -> V_77 ;
V_46 = F_41 ( V_70 , 0 ) ;
V_1 = F_42 ( sizeof( struct V_1 ) , V_78 ) ;
if ( ! V_1 )
return - V_79 ;
F_43 ( & V_1 -> V_32 ) ;
V_1 -> V_47 = & V_70 -> V_47 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_3 = V_80 ;
V_1 -> V_3 . V_66 = V_5 -> V_34 ;
V_1 -> V_3 . V_47 = & V_70 -> V_47 ;
V_1 -> V_3 . V_64 = V_76 ? V_76 -> V_81 : - 1 ;
if ( V_76 )
V_1 -> V_17 = V_76 -> V_17 ;
else if ( V_73 )
F_44 ( V_73 , L_2 ,
& V_1 -> V_17 ) ;
if ( V_46 >= 0 )
V_1 -> V_65 = V_5 -> V_65 + F_45 ( 0 ) ;
else
F_46 ( & V_70 -> V_47 ,
L_3
L_4 ) ;
V_10 = F_47 ( V_5 , V_19 ) ;
if ( V_10 )
goto V_82;
if ( V_46 >= 0 ) {
V_10 = F_36 ( V_1 ) ;
if ( V_10 )
goto V_83;
V_10 = F_48 ( V_46 , NULL , F_23 ,
V_84 , L_5 , V_1 ) ;
if ( V_10 ) {
F_38 ( & V_70 -> V_47 , L_6 , V_10 ) ;
goto V_83;
}
}
V_10 = F_49 ( & V_1 -> V_3 ) ;
if ( V_10 ) {
F_38 ( & V_70 -> V_47 , L_7 , V_10 ) ;
goto V_85;
}
if ( V_76 && V_76 -> V_86 )
V_76 -> V_86 ( V_5 , V_1 -> V_3 . V_64 ) ;
F_50 ( V_70 , V_1 ) ;
return 0 ;
V_85:
if ( V_46 >= 0 )
F_51 ( V_46 , V_1 ) ;
V_83:
F_52 ( V_5 , V_19 ) ;
V_82:
F_53 ( V_1 ) ;
return V_10 ;
}
static int F_54 ( struct V_69 * V_70 )
{
struct V_1 * V_1 = F_55 ( V_70 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
struct V_75 * V_76 = V_5 -> V_76 -> V_77 ;
int V_46 = F_41 ( V_70 , 0 ) ;
int V_10 ;
if ( V_76 && V_76 -> remove )
V_76 -> remove ( V_5 , V_1 -> V_3 . V_64 ) ;
V_10 = F_56 ( & V_1 -> V_3 ) ;
if ( V_10 < 0 ) {
F_38 ( V_1 -> V_47 ,
L_8 , V_10 ) ;
return V_10 ;
}
F_52 ( V_5 , V_19 ) ;
if ( V_46 >= 0 )
F_51 ( V_46 , V_1 ) ;
F_50 ( V_70 , NULL ) ;
F_53 ( V_1 ) ;
return 0 ;
}
static int T_4 F_57 ( void )
{
return F_58 ( & V_87 ) ;
}
static void T_5 F_59 ( void )
{
F_60 ( & V_87 ) ;
}
