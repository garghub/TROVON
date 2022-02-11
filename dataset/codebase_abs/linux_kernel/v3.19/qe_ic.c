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
static int F_15 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
return V_17 -> V_20 == NULL || V_17 -> V_20 == V_19 ;
}
static int F_16 ( struct V_16 * V_17 , unsigned int V_5 ,
T_4 V_21 )
{
struct V_4 * V_4 = V_17 -> V_22 ;
struct V_23 * V_24 ;
if ( V_13 [ V_21 ] . V_15 == 0 ) {
F_17 ( V_25 L_1 ) ;
return - V_26 ;
}
V_24 = & V_4 -> V_27 ;
F_18 ( V_5 , V_4 ) ;
F_19 ( V_5 , V_28 ) ;
F_20 ( V_5 , V_24 , V_29 ) ;
return 0 ;
}
unsigned int F_21 ( struct V_4 * V_4 )
{
int V_30 ;
F_22 ( V_4 == NULL ) ;
V_30 = F_1 ( V_4 -> V_12 , V_31 ) >> 26 ;
if ( V_30 == 0 )
return V_32 ;
return F_23 ( V_4 -> V_33 , V_30 ) ;
}
unsigned int F_24 ( struct V_4 * V_4 )
{
int V_30 ;
F_22 ( V_4 == NULL ) ;
V_30 = F_1 ( V_4 -> V_12 , V_34 ) >> 26 ;
if ( V_30 == 0 )
return V_32 ;
return F_23 ( V_4 -> V_33 , V_30 ) ;
}
void T_5 F_25 ( struct V_18 * V_19 , unsigned int V_9 ,
void (* F_26)( unsigned int V_30 , struct V_35 * V_36 ) ,
void (* F_27)( unsigned int V_30 , struct V_35 * V_36 ) )
{
struct V_4 * V_4 ;
struct V_37 V_38 ;
T_1 V_10 = 0 , V_39 , V_40 = 0 ;
V_39 = F_28 ( V_19 , 0 , & V_38 ) ;
if ( V_39 )
return;
V_4 = F_29 ( sizeof( * V_4 ) , V_41 ) ;
if ( V_4 == NULL )
return;
V_4 -> V_33 = F_30 ( V_19 , V_42 ,
& V_43 , V_4 ) ;
if ( V_4 -> V_33 == NULL ) {
F_31 ( V_4 ) ;
return;
}
V_4 -> V_12 = F_32 ( V_38 . V_44 , F_33 ( & V_38 ) ) ;
V_4 -> V_27 = V_45 ;
V_4 -> V_46 = F_34 ( V_19 , 0 ) ;
V_4 -> V_47 = F_34 ( V_19 , 1 ) ;
if ( V_4 -> V_47 == V_32 ) {
F_17 ( V_25 L_2 ) ;
F_31 ( V_4 ) ;
return;
}
if ( V_9 & V_48 )
V_10 |= V_49 ;
if ( V_9 & V_50 )
V_10 |= V_51 ;
if ( V_9 & V_52 )
V_10 |= V_53 ;
if ( V_9 & V_54 )
V_10 |= V_55 ;
if ( V_9 & V_56 )
V_10 |= V_57 ;
if ( V_9 & V_58 )
V_10 |= V_59 ;
if ( V_9 & V_60 ) {
V_10 |= ( V_61 << V_62 ) ;
V_40 = 1 ;
}
F_3 ( V_4 -> V_12 , V_63 , V_10 ) ;
F_35 ( V_4 -> V_47 , V_4 ) ;
F_36 ( V_4 -> V_47 , F_26 ) ;
if ( V_4 -> V_46 != V_32 &&
V_4 -> V_46 != V_4 -> V_47 ) {
F_35 ( V_4 -> V_46 , V_4 ) ;
F_36 ( V_4 -> V_46 , F_27 ) ;
}
}
void F_37 ( unsigned int V_5 , int V_64 )
{
struct V_4 * V_4 = F_5 ( V_5 ) ;
unsigned int V_8 = F_38 ( V_5 ) ;
T_1 V_10 = 0 ;
V_10 = F_1 ( V_4 -> V_12 , V_63 ) ;
V_10 &= ~ V_65 ;
V_10 |= V_8 << V_66 ;
V_10 &= ~ V_67 ;
V_10 |= ( V_64 ? V_61 : V_68 ) << V_62 ;
F_3 ( V_4 -> V_12 , V_63 , V_10 ) ;
}
int F_39 ( unsigned int V_5 , unsigned int V_69 )
{
struct V_4 * V_4 = F_5 ( V_5 ) ;
unsigned int V_8 = F_38 ( V_5 ) ;
T_1 V_10 ;
if ( V_69 > 8 || V_69 == 0 )
return - V_26 ;
if ( V_8 > 127 )
return - V_26 ;
if ( V_13 [ V_8 ] . V_70 == 0 )
return - V_26 ;
V_10 = F_1 ( V_4 -> V_12 , V_13 [ V_8 ] . V_70 ) ;
if ( V_69 < 4 ) {
V_10 &= ~ ( 0x7 << ( 32 - V_69 * 3 ) ) ;
V_10 |= V_13 [ V_8 ] . V_71 << ( 32 - V_69 * 3 ) ;
} else {
V_10 &= ~ ( 0x7 << ( 24 - V_69 * 3 ) ) ;
V_10 |= V_13 [ V_8 ] . V_71 << ( 24 - V_69 * 3 ) ;
}
F_3 ( V_4 -> V_12 , V_13 [ V_8 ] . V_70 , V_10 ) ;
return 0 ;
}
int F_40 ( unsigned int V_5 , unsigned int V_69 , int V_64 )
{
struct V_4 * V_4 = F_5 ( V_5 ) ;
unsigned int V_8 = F_38 ( V_5 ) ;
T_1 V_10 , V_72 = V_73 , V_74 = 0 ;
if ( V_69 > 2 || V_69 == 0 )
return - V_26 ;
switch ( V_13 [ V_8 ] . V_70 ) {
case V_75 :
V_74 = V_76 ;
break;
case V_77 :
V_74 = V_78 ;
break;
case V_79 :
V_74 = V_80 ;
break;
case V_81 :
V_74 = V_82 ;
break;
case V_83 :
V_74 = V_84 ;
V_72 = V_85 ;
break;
case V_86 :
V_74 = V_87 ;
V_72 = V_85 ;
break;
default:
return - V_26 ;
}
V_74 += ( 2 - V_69 ) * 2 ;
V_10 = F_1 ( V_4 -> V_12 , V_72 ) ;
V_10 &= ~ ( V_88 << V_74 ) ;
V_10 |= ( V_64 ? V_61 : V_68 ) << V_74 ;
F_3 ( V_4 -> V_12 , V_72 , V_10 ) ;
return 0 ;
}
static int T_5 F_41 ( void )
{
int V_89 ;
F_17 ( V_90 L_3 ) ;
V_89 = F_42 ( & V_91 , NULL ) ;
if ( V_89 ) {
F_17 ( V_25 L_4 ) ;
return - V_92 ;
}
V_89 = F_43 ( & V_93 ) ;
if ( V_89 ) {
F_17 ( V_25 L_5 ) ;
return - V_92 ;
}
return 0 ;
}
