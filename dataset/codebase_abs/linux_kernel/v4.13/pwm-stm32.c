static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_4 )
{
T_1 V_5 ;
F_4 ( V_4 -> V_6 , V_7 , & V_5 ) ;
return V_5 & V_8 ;
}
static int F_5 ( struct V_1 * V_4 , int V_9 , T_1 V_10 )
{
switch ( V_9 ) {
case 0 :
return F_6 ( V_4 -> V_6 , V_11 , V_10 ) ;
case 1 :
return F_6 ( V_4 -> V_6 , V_12 , V_10 ) ;
case 2 :
return F_6 ( V_4 -> V_6 , V_13 , V_10 ) ;
case 3 :
return F_6 ( V_4 -> V_6 , V_14 , V_10 ) ;
}
return - V_15 ;
}
static int F_7 ( struct V_1 * V_16 , int V_9 ,
int V_17 , int V_18 )
{
unsigned long long V_19 , div , V_20 ;
unsigned int V_21 = 0 ;
T_1 V_22 , V_23 , V_24 ;
div = ( unsigned long long ) F_8 ( V_16 -> V_25 ) * V_18 ;
F_9 ( div , V_26 ) ;
V_19 = div ;
while ( div > V_16 -> V_27 ) {
V_21 ++ ;
div = V_19 ;
F_9 ( div , V_21 + 1 ) ;
}
V_19 = div ;
if ( V_21 > V_28 )
return - V_15 ;
if ( F_3 ( V_16 ) & ~ ( 1 << V_9 * 4 ) ) {
T_1 V_29 , V_30 ;
F_4 ( V_16 -> V_6 , V_31 , & V_29 ) ;
F_4 ( V_16 -> V_6 , V_32 , & V_30 ) ;
if ( ( V_29 != V_21 ) || ( V_30 != V_19 - 1 ) )
return - V_33 ;
}
F_6 ( V_16 -> V_6 , V_31 , V_21 ) ;
F_6 ( V_16 -> V_6 , V_32 , V_19 - 1 ) ;
F_10 ( V_16 -> V_6 , V_34 , V_35 , V_35 ) ;
V_20 = V_19 * V_17 ;
F_9 ( V_20 , V_18 ) ;
F_5 ( V_16 , V_9 , V_20 ) ;
V_24 = ( V_9 & 0x1 ) * V_36 ;
V_22 = ( V_37 | V_38 ) << V_24 ;
V_23 = V_39 << V_24 ;
if ( V_9 < 2 )
F_10 ( V_16 -> V_6 , V_40 , V_23 , V_22 ) ;
else
F_10 ( V_16 -> V_6 , V_41 , V_23 , V_22 ) ;
F_10 ( V_16 -> V_6 , V_42 ,
V_43 | V_44 ,
V_43 | V_44 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_16 , int V_9 ,
enum V_45 V_46 )
{
T_1 V_23 ;
V_23 = V_47 << ( V_9 * 4 ) ;
if ( V_16 -> V_48 )
V_23 |= V_49 << ( V_9 * 4 ) ;
F_10 ( V_16 -> V_6 , V_7 , V_23 ,
V_46 == V_50 ? 0 : V_23 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_16 , int V_9 )
{
T_1 V_23 ;
int V_51 ;
V_51 = F_13 ( V_16 -> V_25 ) ;
if ( V_51 )
return V_51 ;
V_23 = V_52 << ( V_9 * 4 ) ;
if ( V_16 -> V_48 )
V_23 |= V_53 << ( V_9 * 4 ) ;
F_10 ( V_16 -> V_6 , V_7 , V_23 , V_23 ) ;
F_10 ( V_16 -> V_6 , V_54 , V_55 , V_55 ) ;
F_10 ( V_16 -> V_6 , V_34 , V_56 , V_56 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_16 , int V_9 )
{
T_1 V_23 ;
V_23 = V_52 << ( V_9 * 4 ) ;
if ( V_16 -> V_48 )
V_23 |= V_53 << ( V_9 * 4 ) ;
F_10 ( V_16 -> V_6 , V_7 , V_23 , 0 ) ;
if ( ! F_3 ( V_16 ) )
F_10 ( V_16 -> V_6 , V_34 , V_56 , 0 ) ;
F_15 ( V_16 -> V_25 ) ;
}
static int F_16 ( struct V_2 * V_3 , struct V_57 * V_58 ,
struct V_59 * V_60 )
{
bool V_61 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_51 ;
V_61 = V_58 -> V_60 . V_61 ;
if ( V_61 && ! V_60 -> V_61 ) {
F_14 ( V_16 , V_58 -> V_62 ) ;
return 0 ;
}
if ( V_60 -> V_46 != V_58 -> V_60 . V_46 )
F_11 ( V_16 , V_58 -> V_62 , V_60 -> V_46 ) ;
V_51 = F_7 ( V_16 , V_58 -> V_62 ,
V_60 -> V_63 , V_60 -> V_64 ) ;
if ( V_51 )
return V_51 ;
if ( ! V_61 && V_60 -> V_61 )
V_51 = F_12 ( V_16 , V_58 -> V_62 ) ;
return V_51 ;
}
static int F_17 ( struct V_1 * V_16 ,
int V_65 , int V_66 , int V_67 )
{
T_1 V_68 = ( V_65 == 0 ) ? V_69 : V_70 ;
int V_24 = ( V_65 == 0 ) ? V_71 : V_72 ;
T_1 V_23 = ( V_65 == 0 ) ? V_69 | V_73 | V_74
: V_70 | V_75 | V_76 ;
T_1 V_77 = V_68 ;
if ( V_66 )
V_77 |= V_73 | V_75 ;
V_77 |= ( V_67 & V_78 ) << V_24 ;
F_10 ( V_16 -> V_6 , V_42 , V_23 , V_77 ) ;
F_4 ( V_16 -> V_6 , V_42 , & V_77 ) ;
return ( V_77 & V_68 ) ? 0 : - V_15 ;
}
static int F_18 ( struct V_1 * V_16 ,
struct V_79 * V_80 )
{
struct V_81 V_82 [ V_83 ] ;
int V_84 , V_51 , V_85 , V_86 ;
V_84 = F_19 ( V_80 , L_1 ,
sizeof( struct V_81 ) ) ;
if ( V_84 <= 0 )
return 0 ;
if ( V_84 > V_83 )
return - V_15 ;
V_86 = V_84 * sizeof( struct V_81 ) / sizeof( T_1 ) ;
V_51 = F_20 ( V_80 , L_1 ,
( T_1 * ) V_82 , V_86 ) ;
if ( V_51 )
return V_51 ;
for ( V_85 = 0 ; V_85 < V_84 && ! V_51 ; V_85 ++ ) {
V_51 = F_17 ( V_16 ,
V_82 [ V_85 ] . V_65 ,
V_82 [ V_85 ] . V_66 ,
V_82 [ V_85 ] . V_67 ) ;
}
return V_51 ;
}
static void F_21 ( struct V_1 * V_16 )
{
T_1 V_5 ;
F_10 ( V_16 -> V_6 ,
V_7 , V_53 , V_53 ) ;
F_4 ( V_16 -> V_6 , V_7 , & V_5 ) ;
F_10 ( V_16 -> V_6 , V_7 , V_53 , 0 ) ;
V_16 -> V_48 = ( V_5 != 0 ) ;
}
static int F_22 ( struct V_1 * V_16 )
{
T_1 V_5 ;
int V_87 = 0 ;
F_10 ( V_16 -> V_6 ,
V_7 , V_8 , V_8 ) ;
F_4 ( V_16 -> V_6 , V_7 , & V_5 ) ;
F_10 ( V_16 -> V_6 , V_7 , V_8 , 0 ) ;
if ( V_5 & V_52 )
V_87 ++ ;
if ( V_5 & V_88 )
V_87 ++ ;
if ( V_5 & V_89 )
V_87 ++ ;
if ( V_5 & V_90 )
V_87 ++ ;
return V_87 ;
}
static int F_23 ( struct V_91 * V_92 )
{
struct V_93 * V_4 = & V_92 -> V_4 ;
struct V_79 * V_80 = V_4 -> V_94 ;
struct V_95 * V_96 = F_24 ( V_92 -> V_4 . V_97 ) ;
struct V_1 * V_16 ;
int V_51 ;
V_16 = F_25 ( V_4 , sizeof( * V_16 ) , V_98 ) ;
if ( ! V_16 )
return - V_99 ;
V_16 -> V_6 = V_96 -> V_6 ;
V_16 -> V_25 = V_96 -> V_25 ;
V_16 -> V_27 = V_96 -> V_27 ;
if ( ! V_16 -> V_6 || ! V_16 -> V_25 )
return - V_15 ;
V_51 = F_18 ( V_16 , V_80 ) ;
if ( V_51 )
return V_51 ;
F_21 ( V_16 ) ;
V_16 -> V_3 . V_100 = - 1 ;
V_16 -> V_3 . V_4 = V_4 ;
V_16 -> V_3 . V_101 = & V_102 ;
V_16 -> V_3 . V_87 = F_22 ( V_16 ) ;
V_51 = F_26 ( & V_16 -> V_3 ) ;
if ( V_51 < 0 )
return V_51 ;
F_27 ( V_92 , V_16 ) ;
return 0 ;
}
static int F_28 ( struct V_91 * V_92 )
{
struct V_1 * V_16 = F_29 ( V_92 ) ;
unsigned int V_85 ;
for ( V_85 = 0 ; V_85 < V_16 -> V_3 . V_87 ; V_85 ++ )
F_30 ( & V_16 -> V_3 . V_103 [ V_85 ] ) ;
F_31 ( & V_16 -> V_3 ) ;
return 0 ;
}
