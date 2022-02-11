static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
T_1 V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 ,
L_1 ,
V_4 , V_3 , V_5 ) ;
return V_5 ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_2 V_3 , T_2 * V_4 )
{
T_1 V_5 = F_5 ( V_2 , V_3 ) ;
if ( V_5 >= 0 )
* V_4 = V_5 ;
else
F_3 ( & V_2 -> V_6 ,
L_2 ,
V_3 , V_5 ) ;
return V_5 ;
}
static inline bool F_6 ( struct V_7 * V_8 , unsigned V_9 )
{
return ( V_8 -> V_10 -> V_11 == V_9 ) ;
}
static inline void F_7 ( T_2 V_9 , T_2 V_12 ,
T_2 * V_3 , T_2 * V_13 , T_2 * V_14 )
{
* V_3 -= V_9 * V_12 / 8 ;
* V_13 = ( 1 << V_12 ) - 1 ;
* V_14 = ( V_9 * V_12 ) % 8 ;
* V_13 <<= * V_14 ;
}
static T_1 F_8 ( struct V_7 * V_8 ,
T_2 V_9 , T_2 V_12 , T_2 V_3 , T_2 V_4 )
{
T_2 V_13 ;
T_2 V_15 ;
T_2 V_14 ;
T_1 V_5 ;
F_7 ( V_9 , V_12 , & V_3 , & V_13 , & V_14 ) ;
V_5 = F_4 ( V_8 -> V_2 , V_3 , & V_15 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 &= ~ V_13 ;
V_15 |= ( V_4 << V_14 ) & V_13 ;
return F_1 ( V_8 -> V_2 , V_3 , V_15 ) ;
}
static int F_9 ( struct V_7 * V_8 , unsigned V_9 )
{
T_2 V_3 = V_8 -> V_10 -> V_16 ;
T_2 V_13 ;
T_2 V_15 ;
T_2 V_14 ;
T_1 V_5 ;
F_7 ( V_9 , 1 , & V_3 , & V_13 , & V_14 ) ;
V_5 = F_4 ( V_8 -> V_2 , V_3 , & V_15 ) ;
if ( V_5 >= 0 )
V_5 = ( V_15 & V_13 ) != 0 ? 1 : 0 ;
return V_5 ;
}
static void F_10 ( struct V_7 * V_8 , int V_4 )
{
F_1 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_17 ,
( V_4 ? 0x1f : 0x10 ) ) ;
}
static void F_11 ( struct V_7 * V_8 , unsigned V_9 , int V_4 )
{
F_8 ( V_8 ,
V_9 ,
1 ,
V_8 -> V_10 -> V_16 ,
( V_4 ? 1 : 0 ) ) ;
}
static int F_12 ( struct V_7 * V_8 , unsigned V_9 )
{
return F_8 ( V_8 ,
V_9 ,
1 ,
V_8 -> V_10 -> V_18 ,
1 ) ;
}
static int F_13 ( struct V_7 * V_8 , unsigned V_9 , int V_4 )
{
int V_5 ;
V_5 = F_8 ( V_8 ,
V_9 ,
1 ,
V_8 -> V_10 -> V_16 ,
( V_4 ? 1 : 0 ) ) ;
if ( V_5 >= 0 )
V_5 = F_8 ( V_8 ,
V_9 ,
1 ,
V_8 -> V_10 -> V_18 ,
0 ) ;
return V_5 ;
}
static int F_14 ( struct V_19 * V_20 , unsigned V_9 )
{
struct V_7 * V_8 ;
int V_21 = - V_22 ;
V_8 = F_15 ( V_20 , struct V_7 , V_19 ) ;
if ( ! F_6 ( V_8 , V_9 ) ) {
F_16 ( & V_8 -> V_23 ) ;
V_21 = F_9 ( V_8 , V_9 ) ;
F_17 ( & V_8 -> V_23 ) ;
}
return V_21 ;
}
static void F_18 ( struct V_19 * V_20 , unsigned V_9 , int V_4 )
{
struct V_7 * V_8 ;
V_8 = F_15 ( V_20 , struct V_7 , V_19 ) ;
F_16 ( & V_8 -> V_23 ) ;
if ( F_6 ( V_8 , V_9 ) )
F_10 ( V_8 , V_4 ) ;
else
F_11 ( V_8 , V_9 , V_4 ) ;
F_17 ( & V_8 -> V_23 ) ;
}
static int F_19 ( struct V_19 * V_20 , unsigned V_9 )
{
struct V_7 * V_8 ;
int V_21 = - V_22 ;
V_8 = F_15 ( V_20 , struct V_7 , V_19 ) ;
if ( ! F_6 ( V_8 , V_9 ) ) {
F_16 ( & V_8 -> V_23 ) ;
V_21 = F_12 ( V_8 , V_9 ) ;
F_17 ( & V_8 -> V_23 ) ;
}
return V_21 ;
}
static int F_20 ( struct V_19 * V_20 ,
unsigned V_9 ,
int V_4 )
{
struct V_7 * V_8 ;
int V_21 = 0 ;
V_8 = F_15 ( V_20 , struct V_7 , V_19 ) ;
if ( ! F_6 ( V_8 , V_9 ) ) {
F_16 ( & V_8 -> V_23 ) ;
V_21 = F_13 ( V_8 , V_9 , V_4 ) ;
F_17 ( & V_8 -> V_23 ) ;
}
return V_21 ;
}
static int F_21 ( struct V_19 * V_20 , unsigned V_9 )
{
struct V_7 * V_8 ;
V_8 = F_15 ( V_20 , struct V_7 , V_19 ) ;
if ( V_9 >= V_8 -> V_10 -> V_11 )
return - V_22 ;
if ( V_8 -> V_24 < 0 )
return - V_22 ;
return V_8 -> V_24 + V_9 ;
}
static void F_22 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_23 ( V_26 ) ;
struct V_7 * V_8 ;
unsigned V_29 ;
V_8 = F_15 ( V_28 , struct V_7 , V_27 ) ;
V_29 = V_26 -> V_30 - V_8 -> V_24 ;
V_8 -> V_31 |= ( 1 << V_29 ) ;
V_8 -> V_32 = V_29 ;
}
static void F_24 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_23 ( V_26 ) ;
struct V_7 * V_8 ;
unsigned V_29 ;
V_8 = F_15 ( V_28 , struct V_7 , V_27 ) ;
V_29 = V_26 -> V_30 - V_8 -> V_24 ;
V_8 -> V_31 &= ~ ( 1 << V_29 ) ;
V_8 -> V_32 = V_29 ;
}
static int F_25 ( struct V_25 * V_26 , unsigned int V_33 )
{
struct V_27 * V_28 = F_23 ( V_26 ) ;
struct V_7 * V_8 ;
unsigned V_29 , V_4 = 0 ;
if ( V_33 & ( V_34 | V_35 ) )
return - V_22 ;
V_8 = F_15 ( V_28 , struct V_7 , V_27 ) ;
V_29 = V_26 -> V_30 - V_8 -> V_24 ;
if ( V_33 & V_36 )
V_4 |= 0x1 ;
if ( V_33 & V_37 )
V_4 |= 0x2 ;
V_8 -> V_38 &= ~ ( 3UL << ( V_29 * 2 ) ) ;
V_8 -> V_38 |= V_4 << ( V_29 * 2 ) ;
V_8 -> V_32 = V_29 ;
return 0 ;
}
static T_3 F_26 ( int V_30 , void * V_39 )
{
struct V_7 * V_8 = (struct V_7 * ) V_39 ;
unsigned V_40 = 0 ;
unsigned V_41 ;
unsigned V_29 ;
T_1 V_5 ;
T_2 V_4 ;
int V_42 ;
for ( V_42 = ( V_8 -> V_10 -> V_11 / 8 ) - 1 ; V_42 >= 0 ; -- V_42 ) {
V_5 = F_4 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_43 - V_42 ,
& V_4 ) ;
if ( V_5 < 0 )
continue;
F_1 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_43 - V_42 ,
V_4 ) ;
for ( V_29 = 0 ; V_29 < 8 ; ++ V_29 ) {
if ( V_4 & ( 1 << V_29 ) ) {
V_41 = V_8 -> V_24 + ( V_42 * 8 ) + V_29 ;
F_27 ( V_41 ) ;
++ V_40 ;
}
}
}
return ( V_40 > 0 ? V_44 : V_45 ) ;
}
static void F_28 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_23 ( V_26 ) ;
struct V_7 * V_8 ;
V_8 = F_15 ( V_28 , struct V_7 , V_27 ) ;
F_16 ( & V_8 -> V_23 ) ;
}
static void F_29 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_23 ( V_26 ) ;
struct V_7 * V_8 ;
unsigned V_29 ;
V_8 = F_15 ( V_28 , struct V_7 , V_27 ) ;
if ( V_8 -> V_32 == V_46 )
goto V_47;
V_29 = V_8 -> V_32 ;
V_8 -> V_32 = V_46 ;
if ( V_8 -> V_48 == V_8 -> V_38 &&
V_8 -> V_48 == V_8 -> V_31 )
goto V_47;
V_8 -> V_48 = V_8 -> V_38 ;
V_8 -> V_49 = V_8 -> V_31 ;
if ( V_8 -> V_31 & ( 1 << V_29 ) ) {
F_8 ( V_8 , V_29 , 1 , V_8 -> V_10 -> V_50 , 1 ) ;
F_8 ( V_8 , V_29 , 2 , V_8 -> V_10 -> V_51 , 0 ) ;
} else {
F_8 ( V_8 , V_29 , 1 , V_8 -> V_10 -> V_50 , 0 ) ;
F_8 ( V_8 , V_29 , 2 , V_8 -> V_10 -> V_51 ,
V_8 -> V_38 >> ( V_29 * 2 ) ) ;
}
V_47:
F_17 ( & V_8 -> V_23 ) ;
}
static void F_30 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
T_4 V_52 ,
struct V_53 * V_54 )
{
F_31 ( & V_8 -> V_23 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_10 = & V_55 [ V_52 ] ;
V_8 -> V_19 . V_56 = V_2 -> V_57 ;
V_8 -> V_19 . V_58 = F_19 ;
V_8 -> V_19 . V_59 = F_20 ;
V_8 -> V_19 . V_60 = F_14 ;
V_8 -> V_19 . V_61 = F_18 ;
V_8 -> V_19 . V_62 = F_21 ;
V_8 -> V_19 . V_63 = V_54 -> V_64 ;
V_8 -> V_19 . V_65 = 1 ;
V_8 -> V_19 . V_66 = V_8 -> V_10 -> V_11 ;
if ( V_54 -> V_67 )
++ V_8 -> V_19 . V_66 ;
V_8 -> V_27 . V_57 = V_2 -> V_57 ;
V_8 -> V_27 . V_68 = F_22 ;
V_8 -> V_27 . V_69 = F_24 ;
V_8 -> V_27 . V_70 = F_25 ;
V_8 -> V_27 . V_71 = F_28 ;
V_8 -> V_27 . V_72 = F_29 ;
V_8 -> V_73 = - 1 ;
V_8 -> V_24 = - 1 ;
V_8 -> V_31 = ~ 0 ;
V_8 -> V_38 = 0 ;
V_8 -> V_49 = ~ 0 ;
V_8 -> V_48 = 0 ;
V_8 -> V_32 = V_46 ;
}
static int F_32 ( struct V_7 * V_8 , T_2 V_63 , T_5 V_74 )
{
int V_5 = 0 ;
unsigned V_29 ;
for ( V_29 = 0 ; V_5 >= 0 && V_29 < ( V_8 -> V_10 -> V_11 / 8 ) ; ++ V_29 )
V_5 = F_1 ( V_8 -> V_2 , V_63 - V_29 , V_74 >> ( V_29 * 8 ) ) ;
return V_5 ;
}
static int F_33 ( struct V_7 * V_8 )
{
int V_5 ;
V_5 = F_2 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_75 ,
0x12 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_75 ,
0x34 ) ;
return V_5 ;
}
static int F_34 ( struct V_7 * V_8 ,
struct V_53 * V_54 )
{
int V_5 = 0 ;
if ( V_54 -> V_76 ) {
V_5 = F_33 ( V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_5 = F_1 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_77 ,
0x01 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_32 ( V_8 , V_8 -> V_10 -> V_78 ,
V_54 -> V_79 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_32 ( V_8 , V_8 -> V_10 -> V_80 ,
V_54 -> V_81 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_32 ( V_8 , V_8 -> V_10 -> V_82 ,
V_54 -> V_83 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_32 ( V_8 , V_8 -> V_10 -> V_84 ,
V_54 -> V_85 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_54 -> V_67 )
F_10 ( V_8 , 0 ) ;
return V_5 ;
}
static int F_35 ( struct V_7 * V_8 ,
int V_73 ,
int V_24 )
{
int V_5 ;
unsigned V_29 ;
unsigned V_30 ;
V_8 -> V_73 = V_73 ;
V_8 -> V_24 = V_24 ;
for ( V_29 = 0 ; V_29 < V_8 -> V_10 -> V_11 ; ++ V_29 ) {
V_30 = V_24 + V_29 ;
F_36 ( V_30 , & V_8 -> V_27 , V_86 ) ;
F_37 ( V_30 , 1 ) ;
#ifdef F_38
F_39 ( V_30 , V_87 ) ;
#else
F_40 ( V_30 ) ;
#endif
}
V_5 = F_41 ( V_73 ,
NULL ,
F_26 ,
V_88 | V_89 ,
V_8 -> V_27 . V_57 ,
V_8 ) ;
if ( V_5 < 0 ) {
V_8 -> V_73 = - 1 ;
V_8 -> V_24 = - 1 ;
}
return V_5 ;
}
static void F_42 ( struct V_7 * V_8 )
{
unsigned V_29 ;
unsigned V_30 ;
F_43 ( V_8 -> V_73 , V_8 ) ;
for ( V_29 = 0 ; V_29 < V_8 -> V_10 -> V_11 ; ++ V_29 ) {
V_30 = V_8 -> V_24 + V_29 ;
F_36 ( V_30 , NULL , NULL ) ;
}
}
static int T_6 F_44 ( struct V_1 * V_2 ,
const struct V_90 * V_91 )
{
static const T_7 V_92 = V_93 |
V_94 ;
struct V_53 * V_54 ;
struct V_7 * V_8 ;
int V_95 ;
V_54 = V_2 -> V_6 . V_96 ;
if ( ! V_54 )
return - V_22 ;
if ( ! F_45 ( V_2 -> V_97 , V_92 ) )
return - V_98 ;
V_8 = F_46 ( sizeof( struct V_7 ) , V_99 ) ;
if ( ! V_8 )
return - V_100 ;
F_30 ( V_8 , V_2 , V_91 -> V_52 , V_54 ) ;
V_95 = F_34 ( V_8 , V_54 ) ;
if ( V_95 < 0 )
goto V_101;
V_95 = F_47 ( & V_8 -> V_19 ) ;
if ( V_95 < 0 )
goto V_101;
if ( V_54 -> V_73 >= 0 ) {
V_95 = F_35 ( V_8 ,
V_54 -> V_73 ,
V_54 -> V_24 ) ;
if ( V_95 < 0 )
goto V_102;
}
F_48 ( V_2 , V_8 ) ;
return 0 ;
V_102:
F_49 ( F_50 ( & V_8 -> V_19 ) < 0 ) ;
V_101:
F_51 ( V_8 ) ;
return V_95 ;
}
static int T_8 F_52 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_95 ;
V_8 = F_53 ( V_2 ) ;
V_95 = F_50 ( & V_8 -> V_19 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( V_8 -> V_73 >= 0 )
F_42 ( V_8 ) ;
F_51 ( V_8 ) ;
return 0 ;
}
static int T_9 F_54 ( void )
{
return F_55 ( & V_103 ) ;
}
static void T_10 F_56 ( void )
{
return F_57 ( & V_103 ) ;
}
