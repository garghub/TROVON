static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 )
{
unsigned int V_6 = F_2 ( V_4 ) ;
unsigned int V_7 , V_8 ;
T_1 V_9 ;
switch ( V_6 ) {
case 500000 :
case 1000000 :
case 2000000 :
case 4000000 :
V_7 = 64 ;
V_8 = 100 ;
V_2 -> V_10 = 64000000 ;
break;
case 3500000 :
V_7 = 56 ;
V_8 = 100 ;
V_2 -> V_10 = 56000000 ;
break;
case 1500000 :
case 3000000 :
V_7 = 48 ;
V_8 = 100 ;
V_2 -> V_10 = 48000000 ;
break;
case 2500000 :
V_7 = 40 ;
V_8 = 100 ;
V_2 -> V_10 = 40000000 ;
break;
default:
V_7 = 2304 ;
V_8 = 3125 ;
V_2 -> V_10 = 73728000 ;
}
V_9 = ( V_7 << V_11 ) | ( V_8 << V_12 ) ;
F_3 ( V_9 , V_2 -> V_13 + V_14 ) ;
V_9 |= V_15 | V_16 ;
F_3 ( V_9 , V_2 -> V_13 + V_14 ) ;
F_4 ( V_2 , V_4 , V_5 ) ;
}
static inline int F_5 ( struct V_1 * V_2 , int V_17 , int V_18 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
if ( V_17 == V_22 && V_20 -> V_23 & V_24 ) {
V_18 |= V_25 ;
V_18 &= ~ V_26 ;
}
return V_18 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( F_8
( V_2 , struct V_27 , V_28 ) ) ;
( void ) V_2 -> V_29 ( V_2 , V_30 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_17 , int V_18 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
if ( V_17 == V_31 )
V_20 -> V_23 = V_18 ;
F_10 ( V_18 , V_2 -> V_13 + ( V_17 << V_2 -> V_32 ) ) ;
if ( V_17 == V_33 ) {
int V_34 = 1000 ;
while ( V_34 -- ) {
unsigned int V_35 = V_2 -> V_29 ( V_2 , V_33 ) ;
if ( ( V_18 & ~ V_36 ) == ( V_35 & ~ V_36 ) )
return;
F_6 ( V_2 ) ;
F_10 ( V_18 , V_2 -> V_13 + ( V_33 << V_2 -> V_32 ) ) ;
}
F_11 ( V_2 -> V_37 , L_1 , V_18 ) ;
}
}
static unsigned int F_12 ( struct V_1 * V_2 , int V_17 )
{
unsigned int V_18 = F_13 ( V_2 -> V_13 + ( V_17 << V_2 -> V_32 ) ) ;
return F_5 ( V_2 , V_17 , V_18 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_17 , int V_18 )
{
F_9 ( V_2 , V_17 , V_18 ) ;
F_12 ( V_2 , V_33 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_17 , int V_18 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
if ( V_17 == V_31 )
V_20 -> V_23 = V_18 ;
F_3 ( V_18 , V_2 -> V_13 + ( V_17 << V_2 -> V_32 ) ) ;
if ( V_17 == V_33 ) {
int V_34 = 1000 ;
while ( V_34 -- ) {
unsigned int V_35 = V_2 -> V_29 ( V_2 , V_33 ) ;
if ( ( V_18 & ~ V_36 ) == ( V_35 & ~ V_36 ) )
return;
F_6 ( V_2 ) ;
F_3 ( V_18 , V_2 -> V_13 + ( V_33 << V_2 -> V_32 ) ) ;
}
F_11 ( V_2 -> V_37 , L_1 , V_18 ) ;
}
}
static unsigned int F_16 ( struct V_1 * V_2 , int V_17 )
{
unsigned int V_18 = F_17 ( V_2 -> V_13 + ( V_17 << V_2 -> V_32 ) ) ;
return F_5 ( V_2 , V_17 , V_18 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
unsigned int V_38 = V_2 -> V_29 ( V_2 , V_39 ) ;
if ( F_19 ( V_2 , V_38 ) ) {
return 1 ;
} else if ( ( V_38 & V_40 ) == V_40 ) {
( void ) V_2 -> V_29 ( V_2 , V_20 -> V_41 ) ;
return 1 ;
}
return 0 ;
}
static void
F_20 ( struct V_1 * V_28 , unsigned int V_42 , unsigned int V_5 )
{
if ( ! V_42 )
F_21 ( V_28 -> V_37 ) ;
F_22 ( V_28 , V_42 , V_5 ) ;
if ( V_42 )
F_23 ( V_28 -> V_37 ) ;
}
static bool F_24 ( struct V_43 * V_44 , void * V_45 )
{
struct V_19 * V_46 = V_45 ;
return V_44 -> V_47 == V_46 -> V_48 . V_49 ||
V_44 -> V_47 == V_46 -> V_48 . V_50 ;
}
static void F_25 ( struct V_27 * V_51 )
{
struct V_1 * V_2 = & V_51 -> V_28 ;
T_1 V_9 = F_17 ( V_2 -> V_13 + V_52 ) ;
if ( ! V_9 )
return;
F_26 ( V_2 -> V_37 , L_2 ,
( V_9 >> 24 ) & 0xff , ( V_9 >> 16 ) & 0xff , ( V_9 >> 8 ) & 0xff ) ;
V_9 = F_17 ( V_2 -> V_13 + V_53 ) ;
if ( ! V_9 )
return;
if ( V_9 & V_54 ) {
V_2 -> type = V_55 ;
V_2 -> V_56 |= V_57 ;
V_2 -> V_58 = F_27 ( V_9 ) ;
V_51 -> V_59 = V_2 -> V_58 ;
V_51 -> V_60 = V_61 ;
}
if ( V_9 & V_62 )
V_51 -> V_60 |= V_63 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_19 * V_46 )
{
struct V_64 * V_65 = V_2 -> V_37 -> V_66 ;
T_1 V_67 ;
bool V_68 = true ;
if ( F_29 ( V_65 , L_3 ) ) {
#ifdef F_30
V_2 -> V_13 += 7 ;
#endif
V_2 -> V_69 = F_14 ;
V_2 -> V_56 = V_70 | V_71 | V_57 ;
V_2 -> type = V_72 ;
V_46 -> V_41 = 0x27 ;
V_68 = false ;
} else if ( ! F_31 ( V_65 , L_4 , & V_67 ) ) {
switch ( V_67 ) {
case 1 :
break;
case 4 :
V_2 -> V_73 = V_74 ;
V_2 -> V_29 = F_16 ;
V_2 -> V_69 = F_15 ;
break;
default:
F_11 ( V_2 -> V_37 , L_5 , V_67 ) ;
return - V_75 ;
}
}
if ( V_68 )
F_25 ( F_8 ( V_2 , struct V_27 , V_28 ) ) ;
if ( ! F_31 ( V_65 , L_6 , & V_67 ) )
V_2 -> V_32 = V_67 ;
if ( V_2 -> V_10 )
return 0 ;
if ( F_31 ( V_65 , L_7 , & V_67 ) ) {
F_11 ( V_2 -> V_37 , L_8 ) ;
return - V_75 ;
}
V_2 -> V_10 = V_67 ;
return 0 ;
}
static int F_32 ( struct V_27 * V_51 ,
struct V_19 * V_46 )
{
const struct V_76 * V_77 ;
struct V_1 * V_2 = & V_51 -> V_28 ;
struct V_78 * V_79 ;
F_25 ( V_51 ) ;
V_77 = F_33 ( V_2 -> V_37 -> V_80 -> V_81 , V_2 -> V_37 ) ;
if ( ! V_77 )
return - V_82 ;
V_2 -> V_73 = V_74 ;
V_2 -> V_29 = F_16 ;
V_2 -> V_69 = F_15 ;
V_2 -> V_32 = 2 ;
V_51 -> V_48 = & V_46 -> V_48 ;
V_51 -> V_48 -> V_83 . V_84 = V_2 -> V_58 / 4 ;
V_51 -> V_48 -> V_85 . V_86 = V_2 -> V_58 / 4 ;
V_79 = (struct V_78 * ) V_77 -> V_87 ;
if ( ! V_79 )
return 0 ;
if ( V_79 -> V_88 )
V_2 -> V_88 = V_79 -> V_88 ;
return 0 ;
}
static int F_34 ( struct V_89 * V_90 )
{
struct V_27 V_91 = {} ;
struct V_92 * V_93 = F_35 ( V_90 , V_94 , 0 ) ;
struct V_92 * V_95 = F_35 ( V_90 , V_96 , 0 ) ;
struct V_19 * V_46 ;
int V_97 ;
if ( ! V_93 || ! V_95 ) {
F_11 ( & V_90 -> V_37 , L_9 ) ;
return - V_75 ;
}
F_36 ( & V_91 . V_28 . V_98 ) ;
V_91 . V_28 . V_99 = V_93 -> V_100 ;
V_91 . V_28 . V_95 = V_95 -> V_100 ;
V_91 . V_28 . V_101 = F_18 ;
V_91 . V_28 . V_102 = F_20 ;
V_91 . V_28 . type = V_103 ;
V_91 . V_28 . V_56 = V_71 | V_104 | V_105 ;
V_91 . V_28 . V_37 = & V_90 -> V_37 ;
V_91 . V_28 . V_13 = F_37 ( & V_90 -> V_37 , V_93 -> V_100 ,
F_38 ( V_93 ) ) ;
if ( ! V_91 . V_28 . V_13 )
return - V_106 ;
V_46 = F_39 ( & V_90 -> V_37 , sizeof( * V_46 ) , V_107 ) ;
if ( ! V_46 )
return - V_106 ;
V_46 -> V_41 = V_108 ;
V_46 -> V_109 = F_40 ( & V_90 -> V_37 , NULL ) ;
if ( ! F_41 ( V_46 -> V_109 ) ) {
F_42 ( V_46 -> V_109 ) ;
V_91 . V_28 . V_10 = F_43 ( V_46 -> V_109 ) ;
}
V_46 -> V_48 . V_50 = - 1 ;
V_46 -> V_48 . V_49 = - 1 ;
V_46 -> V_48 . V_110 = V_46 ;
V_46 -> V_48 . V_111 = V_46 ;
V_46 -> V_48 . V_112 = F_24 ;
V_91 . V_28 . V_73 = V_113 ;
V_91 . V_28 . V_29 = F_12 ;
V_91 . V_28 . V_69 = F_9 ;
V_91 . V_28 . V_21 = V_46 ;
if ( V_90 -> V_37 . V_66 ) {
V_97 = F_28 ( & V_91 . V_28 , V_46 ) ;
if ( V_97 )
return V_97 ;
} else if ( F_44 ( & V_90 -> V_37 ) ) {
V_97 = F_32 ( & V_91 , V_46 ) ;
if ( V_97 )
return V_97 ;
} else {
return - V_82 ;
}
V_46 -> line = F_45 ( & V_91 ) ;
if ( V_46 -> line < 0 )
return V_46 -> line ;
F_46 ( V_90 , V_46 ) ;
F_47 ( & V_90 -> V_37 ) ;
F_48 ( & V_90 -> V_37 ) ;
return 0 ;
}
static int F_49 ( struct V_89 * V_90 )
{
struct V_19 * V_46 = F_50 ( V_90 ) ;
F_21 ( & V_90 -> V_37 ) ;
F_51 ( V_46 -> line ) ;
if ( ! F_41 ( V_46 -> V_109 ) )
F_52 ( V_46 -> V_109 ) ;
F_53 ( & V_90 -> V_37 ) ;
F_54 ( & V_90 -> V_37 ) ;
return 0 ;
}
static int F_55 ( struct V_114 * V_37 )
{
struct V_19 * V_46 = F_56 ( V_37 ) ;
F_57 ( V_46 -> line ) ;
return 0 ;
}
static int F_58 ( struct V_114 * V_37 )
{
struct V_19 * V_46 = F_56 ( V_37 ) ;
F_59 ( V_46 -> line ) ;
return 0 ;
}
static int F_60 ( struct V_114 * V_37 )
{
struct V_19 * V_46 = F_56 ( V_37 ) ;
if ( ! F_41 ( V_46 -> V_109 ) )
F_52 ( V_46 -> V_109 ) ;
return 0 ;
}
static int F_61 ( struct V_114 * V_37 )
{
struct V_19 * V_46 = F_56 ( V_37 ) ;
if ( ! F_41 ( V_46 -> V_109 ) )
F_42 ( V_46 -> V_109 ) ;
return 0 ;
}
