static inline T_1 F_1 ( volatile T_2 T_3 * V_1 , unsigned int V_2 )
{
return F_2 ( V_1 + ( V_2 >> 2 ) ) ;
}
static inline void F_3 ( volatile T_2 T_3 * V_1 , unsigned int V_2 ,
T_1 V_3 )
{
F_4 ( V_1 + ( V_2 >> 2 ) , V_3 ) ;
}
static inline struct V_4 * F_5 ( unsigned int V_5 )
{
return F_6 ( V_5 ) ;
}
static inline struct V_4 * F_7 ( struct V_6 * V_7 )
{
return F_8 ( V_7 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_4 * V_4 = F_7 ( V_7 ) ;
unsigned int V_8 = F_10 ( V_7 ) ;
unsigned long V_9 ;
T_1 V_10 ;
F_11 ( & V_11 , V_9 ) ;
V_10 = F_1 ( V_4 -> V_12 , V_13 [ V_8 ] . V_14 ) ;
F_3 ( V_4 -> V_12 , V_13 [ V_8 ] . V_14 ,
V_10 | V_13 [ V_8 ] . V_15 ) ;
F_12 ( & V_11 , V_9 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_4 * V_4 = F_7 ( V_7 ) ;
unsigned int V_8 = F_10 ( V_7 ) ;
unsigned long V_9 ;
T_1 V_10 ;
F_11 ( & V_11 , V_9 ) ;
V_10 = F_1 ( V_4 -> V_12 , V_13 [ V_8 ] . V_14 ) ;
F_3 ( V_4 -> V_12 , V_13 [ V_8 ] . V_14 ,
V_10 & ~ V_13 [ V_8 ] . V_15 ) ;
F_14 () ;
F_12 ( & V_11 , V_9 ) ;
}
static int F_15 ( struct V_16 * V_17 , struct V_18 * V_19 ,
enum V_20 V_21 )
{
struct V_18 * V_22 = F_16 ( V_17 ) ;
return V_22 == NULL || V_22 == V_19 ;
}
static int F_17 ( struct V_16 * V_17 , unsigned int V_5 ,
T_4 V_23 )
{
struct V_4 * V_4 = V_17 -> V_24 ;
struct V_25 * V_26 ;
if ( V_23 >= F_18 ( V_13 ) ) {
F_19 ( L_1 , V_27 ) ;
return - V_28 ;
}
if ( V_13 [ V_23 ] . V_15 == 0 ) {
F_20 ( V_29 L_2 ) ;
return - V_28 ;
}
V_26 = & V_4 -> V_30 ;
F_21 ( V_5 , V_4 ) ;
F_22 ( V_5 , V_31 ) ;
F_23 ( V_5 , V_26 , V_32 ) ;
return 0 ;
}
unsigned int F_24 ( struct V_4 * V_4 )
{
int V_33 ;
F_25 ( V_4 == NULL ) ;
V_33 = F_1 ( V_4 -> V_12 , V_34 ) >> 26 ;
if ( V_33 == 0 )
return V_35 ;
return F_26 ( V_4 -> V_36 , V_33 ) ;
}
unsigned int F_27 ( struct V_4 * V_4 )
{
int V_33 ;
F_25 ( V_4 == NULL ) ;
V_33 = F_1 ( V_4 -> V_12 , V_37 ) >> 26 ;
if ( V_33 == 0 )
return V_35 ;
return F_26 ( V_4 -> V_36 , V_33 ) ;
}
void T_5 F_28 ( struct V_18 * V_19 , unsigned int V_9 ,
void (* F_29)( struct V_38 * V_39 ) ,
void (* F_30)( struct V_38 * V_39 ) )
{
struct V_4 * V_4 ;
struct V_40 V_41 ;
T_1 V_10 = 0 , V_42 , V_43 = 0 ;
V_42 = F_31 ( V_19 , 0 , & V_41 ) ;
if ( V_42 )
return;
V_4 = F_32 ( sizeof( * V_4 ) , V_44 ) ;
if ( V_4 == NULL )
return;
V_4 -> V_36 = F_33 ( V_19 , V_45 ,
& V_46 , V_4 ) ;
if ( V_4 -> V_36 == NULL ) {
F_34 ( V_4 ) ;
return;
}
V_4 -> V_12 = F_35 ( V_41 . V_47 , F_36 ( & V_41 ) ) ;
V_4 -> V_30 = V_48 ;
V_4 -> V_49 = F_37 ( V_19 , 0 ) ;
V_4 -> V_50 = F_37 ( V_19 , 1 ) ;
if ( V_4 -> V_50 == V_35 ) {
F_20 ( V_29 L_3 ) ;
F_34 ( V_4 ) ;
return;
}
if ( V_9 & V_51 )
V_10 |= V_52 ;
if ( V_9 & V_53 )
V_10 |= V_54 ;
if ( V_9 & V_55 )
V_10 |= V_56 ;
if ( V_9 & V_57 )
V_10 |= V_58 ;
if ( V_9 & V_59 )
V_10 |= V_60 ;
if ( V_9 & V_61 )
V_10 |= V_62 ;
if ( V_9 & V_63 ) {
V_10 |= ( V_64 << V_65 ) ;
V_43 = 1 ;
}
F_3 ( V_4 -> V_12 , V_66 , V_10 ) ;
F_38 ( V_4 -> V_50 , V_4 ) ;
F_39 ( V_4 -> V_50 , F_29 ) ;
if ( V_4 -> V_49 != V_35 &&
V_4 -> V_49 != V_4 -> V_50 ) {
F_38 ( V_4 -> V_49 , V_4 ) ;
F_39 ( V_4 -> V_49 , F_30 ) ;
}
}
void F_40 ( unsigned int V_5 , int V_67 )
{
struct V_4 * V_4 = F_5 ( V_5 ) ;
unsigned int V_8 = F_41 ( V_5 ) ;
T_1 V_10 = 0 ;
V_10 = F_1 ( V_4 -> V_12 , V_66 ) ;
V_10 &= ~ V_68 ;
V_10 |= V_8 << V_69 ;
V_10 &= ~ V_70 ;
V_10 |= ( V_67 ? V_64 : V_71 ) << V_65 ;
F_3 ( V_4 -> V_12 , V_66 , V_10 ) ;
}
int F_42 ( unsigned int V_5 , unsigned int V_72 )
{
struct V_4 * V_4 = F_5 ( V_5 ) ;
unsigned int V_8 = F_41 ( V_5 ) ;
T_1 V_10 ;
if ( V_72 > 8 || V_72 == 0 )
return - V_28 ;
if ( F_43 ( V_8 >= F_18 ( V_13 ) ,
L_1 , V_27 ) )
return - V_28 ;
if ( V_13 [ V_8 ] . V_73 == 0 )
return - V_28 ;
V_10 = F_1 ( V_4 -> V_12 , V_13 [ V_8 ] . V_73 ) ;
if ( V_72 < 4 ) {
V_10 &= ~ ( 0x7 << ( 32 - V_72 * 3 ) ) ;
V_10 |= V_13 [ V_8 ] . V_74 << ( 32 - V_72 * 3 ) ;
} else {
V_10 &= ~ ( 0x7 << ( 24 - V_72 * 3 ) ) ;
V_10 |= V_13 [ V_8 ] . V_74 << ( 24 - V_72 * 3 ) ;
}
F_3 ( V_4 -> V_12 , V_13 [ V_8 ] . V_73 , V_10 ) ;
return 0 ;
}
int F_44 ( unsigned int V_5 , unsigned int V_72 , int V_67 )
{
struct V_4 * V_4 = F_5 ( V_5 ) ;
unsigned int V_8 = F_41 ( V_5 ) ;
T_1 V_10 , V_75 = V_76 , V_77 = 0 ;
if ( V_72 > 2 || V_72 == 0 )
return - V_28 ;
if ( F_43 ( V_8 >= F_18 ( V_13 ) ,
L_1 , V_27 ) )
return - V_28 ;
switch ( V_13 [ V_8 ] . V_73 ) {
case V_78 :
V_77 = V_79 ;
break;
case V_80 :
V_77 = V_81 ;
break;
case V_82 :
V_77 = V_83 ;
break;
case V_84 :
V_77 = V_85 ;
break;
case V_86 :
V_77 = V_87 ;
V_75 = V_88 ;
break;
case V_89 :
V_77 = V_90 ;
V_75 = V_88 ;
break;
default:
return - V_28 ;
}
V_77 += ( 2 - V_72 ) * 2 ;
V_10 = F_1 ( V_4 -> V_12 , V_75 ) ;
V_10 &= ~ ( V_91 << V_77 ) ;
V_10 |= ( V_67 ? V_64 : V_71 ) << V_77 ;
F_3 ( V_4 -> V_12 , V_75 , V_10 ) ;
return 0 ;
}
static int T_5 F_45 ( void )
{
int V_92 ;
F_20 ( V_93 L_4 ) ;
V_92 = F_46 ( & V_94 , NULL ) ;
if ( V_92 ) {
F_20 ( V_29 L_5 ) ;
return - V_95 ;
}
V_92 = F_47 ( & V_96 ) ;
if ( V_92 ) {
F_20 ( V_29 L_6 ) ;
return - V_95 ;
}
return 0 ;
}
