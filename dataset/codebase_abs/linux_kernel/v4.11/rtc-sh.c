static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 = V_3 & V_7 ;
V_3 &= ~ V_7 ;
F_3 ( V_3 , V_2 -> V_5 + V_6 ) ;
if ( V_4 && V_2 -> V_8 & V_9 )
F_4 ( V_2 -> V_10 , 1 , V_11 | V_12 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 = V_3 & V_13 ;
V_3 &= ~ ( V_13 | V_14 ) ;
F_3 ( V_3 , V_2 -> V_5 + V_6 ) ;
if ( V_4 )
F_4 ( V_2 -> V_10 , 1 , V_15 | V_12 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_16 * V_10 = V_2 -> V_10 ;
struct V_17 * V_18 ;
unsigned int V_3 , V_4 ;
V_3 = F_2 ( V_2 -> V_5 + V_19 ) ;
V_4 = V_3 & V_20 ;
V_3 &= ~ V_20 ;
F_3 ( V_3 , V_2 -> V_5 + V_19 ) ;
if ( ! V_4 )
return 0 ;
if ( ( V_2 -> V_8 & V_21 ) && ( V_2 -> V_8 & V_22 ) )
V_2 -> V_8 &= ~ V_22 ;
else {
if ( V_2 -> V_8 & V_21 )
V_2 -> V_8 |= V_22 ;
if ( V_2 -> V_8 & V_23 ) {
F_7 ( & V_10 -> V_24 ) ;
V_18 = V_10 -> V_18 ;
if ( V_18 )
V_18 -> V_25 ( V_18 -> V_26 ) ;
F_8 ( & V_10 -> V_24 ) ;
} else
F_4 ( V_2 -> V_10 , 1 , V_27 | V_12 ) ;
}
return V_4 ;
}
static T_1 F_9 ( int V_28 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
int V_30 ;
F_7 ( & V_2 -> V_31 ) ;
V_30 = F_1 ( V_2 ) ;
F_8 ( & V_2 -> V_31 ) ;
return F_10 ( V_30 ) ;
}
static T_1 F_11 ( int V_28 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
int V_30 ;
F_7 ( & V_2 -> V_31 ) ;
V_30 = F_5 ( V_2 ) ;
F_8 ( & V_2 -> V_31 ) ;
return F_10 ( V_30 ) ;
}
static T_1 F_12 ( int V_28 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
int V_30 ;
F_7 ( & V_2 -> V_31 ) ;
V_30 = F_6 ( V_2 ) ;
F_8 ( & V_2 -> V_31 ) ;
return F_10 ( V_30 ) ;
}
static T_1 F_13 ( int V_28 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
int V_30 ;
F_7 ( & V_2 -> V_31 ) ;
V_30 = F_1 ( V_2 ) ;
V_30 |= F_5 ( V_2 ) ;
V_30 |= F_6 ( V_2 ) ;
F_8 ( & V_2 -> V_31 ) ;
return F_10 ( V_30 ) ;
}
static int F_14 ( struct V_32 * V_33 , int V_34 )
{
struct V_1 * V_2 = F_15 ( V_33 ) ;
unsigned int V_3 ;
F_16 ( & V_2 -> V_31 ) ;
V_3 = F_2 ( V_2 -> V_5 + V_19 ) ;
if ( V_34 ) {
V_2 -> V_8 |= V_23 ;
V_3 &= ~ V_20 ;
V_3 |= ( V_2 -> V_8 & ~ V_21 ) ;
} else {
V_2 -> V_8 &= ~ V_23 ;
V_3 &= ~ ( V_35 | V_20 ) ;
}
F_3 ( V_3 , V_2 -> V_5 + V_19 ) ;
F_17 ( & V_2 -> V_31 ) ;
return 0 ;
}
static int F_18 ( struct V_32 * V_33 , int V_36 )
{
struct V_1 * V_2 = F_15 ( V_33 ) ;
int V_3 , V_30 = 0 ;
F_16 ( & V_2 -> V_31 ) ;
V_3 = V_2 -> V_8 & V_37 ;
switch ( V_36 ) {
case 0 :
V_2 -> V_8 = 0x00 ;
break;
case 1 :
V_2 -> V_8 = 0x60 ;
break;
case 2 :
V_2 -> V_8 = 0x50 ;
break;
case 4 :
V_2 -> V_8 = 0x40 ;
break;
case 8 :
V_2 -> V_8 = 0x30 | V_21 ;
break;
case 16 :
V_2 -> V_8 = 0x30 ;
break;
case 32 :
V_2 -> V_8 = 0x20 | V_21 ;
break;
case 64 :
V_2 -> V_8 = 0x20 ;
break;
case 128 :
V_2 -> V_8 = 0x10 | V_21 ;
break;
case 256 :
V_2 -> V_8 = 0x10 ;
break;
default:
V_30 = - V_38 ;
}
if ( V_30 == 0 )
V_2 -> V_8 |= V_3 ;
F_17 ( & V_2 -> V_31 ) ;
return V_30 ;
}
static inline void F_19 ( struct V_32 * V_33 , unsigned int V_34 )
{
struct V_1 * V_2 = F_15 ( V_33 ) ;
unsigned int V_3 ;
F_16 ( & V_2 -> V_31 ) ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( V_34 )
V_3 |= V_14 ;
else
V_3 &= ~ V_14 ;
F_3 ( V_3 , V_2 -> V_5 + V_6 ) ;
F_17 ( & V_2 -> V_31 ) ;
}
static int F_20 ( struct V_32 * V_33 , struct V_39 * V_40 )
{
struct V_1 * V_2 = F_15 ( V_33 ) ;
unsigned int V_3 ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
F_21 ( V_40 , L_1 , ( V_3 & V_41 ) ? L_2 : L_3 ) ;
V_3 = F_2 ( V_2 -> V_5 + V_19 ) ;
F_21 ( V_40 , L_4 ,
( V_3 & V_35 ) ? L_2 : L_3 ) ;
return 0 ;
}
static inline void F_22 ( struct V_32 * V_33 , unsigned int V_34 )
{
struct V_1 * V_2 = F_15 ( V_33 ) ;
unsigned int V_3 ;
F_16 ( & V_2 -> V_31 ) ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( ! V_34 )
V_3 &= ~ V_41 ;
else
V_3 |= V_41 ;
F_3 ( V_3 , V_2 -> V_5 + V_6 ) ;
F_17 ( & V_2 -> V_31 ) ;
}
static int F_23 ( struct V_32 * V_33 , unsigned int V_42 )
{
F_19 ( V_33 , V_42 ) ;
return 0 ;
}
static int F_24 ( struct V_32 * V_33 , struct V_43 * V_44 )
{
struct V_45 * V_46 = F_25 ( V_33 ) ;
struct V_1 * V_2 = F_26 ( V_46 ) ;
unsigned int V_47 , V_48 , V_49 , V_50 , V_51 ;
do {
unsigned int V_3 ;
F_16 ( & V_2 -> V_31 ) ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_3 &= ~ V_7 ;
V_3 |= V_41 ;
F_3 ( V_3 , V_2 -> V_5 + V_6 ) ;
V_47 = F_2 ( V_2 -> V_5 + V_52 ) ;
V_44 -> V_53 = F_27 ( F_2 ( V_2 -> V_5 + V_54 ) ) ;
V_44 -> V_55 = F_27 ( F_2 ( V_2 -> V_5 + V_56 ) ) ;
V_44 -> V_57 = F_27 ( F_2 ( V_2 -> V_5 + V_58 ) ) ;
V_44 -> V_59 = F_27 ( F_2 ( V_2 -> V_5 + V_60 ) ) ;
V_44 -> V_61 = F_27 ( F_2 ( V_2 -> V_5 + V_62 ) ) ;
V_44 -> V_63 = F_27 ( F_2 ( V_2 -> V_5 + V_64 ) ) - 1 ;
if ( V_2 -> V_65 & V_66 ) {
V_49 = F_28 ( V_2 -> V_5 + V_67 ) ;
V_50 = F_27 ( V_49 >> 8 ) ;
V_49 &= 0xff ;
} else {
V_49 = F_2 ( V_2 -> V_5 + V_67 ) ;
V_50 = F_27 ( ( V_49 == 0x99 ) ? 0x19 : 0x20 ) ;
}
V_44 -> V_68 = ( V_50 * 100 + F_27 ( V_49 ) ) - 1900 ;
V_48 = F_2 ( V_2 -> V_5 + V_52 ) ;
V_51 = F_2 ( V_2 -> V_5 + V_6 ) & V_7 ;
F_17 ( & V_2 -> V_31 ) ;
} while ( V_51 != 0 || ( ( V_47 ^ V_48 ) & V_69 ) != 0 );
#if V_69 != 0
if ( ( V_47 & V_69 ) )
V_44 -> V_53 -- ;
#endif
if ( ! ( V_2 -> V_8 & V_9 ) )
F_22 ( V_33 , 0 ) ;
F_29 ( V_33 , L_5
L_6 ,
V_70 ,
V_44 -> V_53 , V_44 -> V_55 , V_44 -> V_57 ,
V_44 -> V_61 , V_44 -> V_63 + 1 , V_44 -> V_68 , V_44 -> V_59 ) ;
return F_30 ( V_44 ) ;
}
static int F_31 ( struct V_32 * V_33 , struct V_43 * V_44 )
{
struct V_45 * V_46 = F_25 ( V_33 ) ;
struct V_1 * V_2 = F_26 ( V_46 ) ;
unsigned int V_3 ;
int V_71 ;
F_16 ( & V_2 -> V_31 ) ;
V_3 = F_2 ( V_2 -> V_5 + V_19 ) ;
V_3 |= V_72 ;
V_3 &= ~ V_73 ;
F_3 ( V_3 , V_2 -> V_5 + V_19 ) ;
F_3 ( F_32 ( V_44 -> V_53 ) , V_2 -> V_5 + V_54 ) ;
F_3 ( F_32 ( V_44 -> V_55 ) , V_2 -> V_5 + V_56 ) ;
F_3 ( F_32 ( V_44 -> V_57 ) , V_2 -> V_5 + V_58 ) ;
F_3 ( F_32 ( V_44 -> V_59 ) , V_2 -> V_5 + V_60 ) ;
F_3 ( F_32 ( V_44 -> V_61 ) , V_2 -> V_5 + V_62 ) ;
F_3 ( F_32 ( V_44 -> V_63 + 1 ) , V_2 -> V_5 + V_64 ) ;
if ( V_2 -> V_65 & V_66 ) {
V_71 = ( F_32 ( ( V_44 -> V_68 + 1900 ) / 100 ) << 8 ) |
F_32 ( V_44 -> V_68 % 100 ) ;
F_33 ( V_71 , V_2 -> V_5 + V_67 ) ;
} else {
V_71 = V_44 -> V_68 % 100 ;
F_3 ( F_32 ( V_71 ) , V_2 -> V_5 + V_67 ) ;
}
V_3 = F_2 ( V_2 -> V_5 + V_19 ) ;
V_3 &= ~ V_72 ;
V_3 |= V_74 | V_73 ;
F_3 ( V_3 , V_2 -> V_5 + V_19 ) ;
F_17 ( & V_2 -> V_31 ) ;
return 0 ;
}
static inline int F_34 ( struct V_1 * V_2 , int V_75 )
{
unsigned int V_76 ;
int V_77 = 0xff ;
V_76 = F_2 ( V_2 -> V_5 + V_75 ) ;
if ( V_76 & V_78 ) {
V_76 &= ~ V_78 ;
V_77 = F_27 ( V_76 ) ;
}
return V_77 ;
}
static int F_35 ( struct V_32 * V_33 , struct V_79 * V_80 )
{
struct V_45 * V_46 = F_25 ( V_33 ) ;
struct V_1 * V_2 = F_26 ( V_46 ) ;
struct V_43 * V_44 = & V_80 -> time ;
F_16 ( & V_2 -> V_31 ) ;
V_44 -> V_53 = F_34 ( V_2 , V_81 ) ;
V_44 -> V_55 = F_34 ( V_2 , V_82 ) ;
V_44 -> V_57 = F_34 ( V_2 , V_83 ) ;
V_44 -> V_59 = F_34 ( V_2 , V_84 ) ;
V_44 -> V_61 = F_34 ( V_2 , V_85 ) ;
V_44 -> V_63 = F_34 ( V_2 , V_86 ) ;
if ( V_44 -> V_63 > 0 )
V_44 -> V_63 -= 1 ;
V_80 -> V_42 = ( F_2 ( V_2 -> V_5 + V_6 ) & V_14 ) ? 1 : 0 ;
F_17 ( & V_2 -> V_31 ) ;
return 0 ;
}
static inline void F_36 ( struct V_1 * V_2 ,
int V_77 , int V_75 )
{
if ( V_77 < 0 )
F_3 ( 0 , V_2 -> V_5 + V_75 ) ;
else
F_3 ( F_32 ( V_77 ) | V_78 , V_2 -> V_5 + V_75 ) ;
}
static int F_37 ( struct V_32 * V_33 , struct V_79 * V_80 )
{
struct V_45 * V_46 = F_25 ( V_33 ) ;
struct V_1 * V_2 = F_26 ( V_46 ) ;
unsigned int V_87 ;
struct V_43 * V_44 = & V_80 -> time ;
int V_88 ;
F_16 ( & V_2 -> V_31 ) ;
V_87 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_87 &= ~ ( V_13 | V_14 ) ;
F_3 ( V_87 , V_2 -> V_5 + V_6 ) ;
F_36 ( V_2 , V_44 -> V_53 , V_81 ) ;
F_36 ( V_2 , V_44 -> V_55 , V_82 ) ;
F_36 ( V_2 , V_44 -> V_57 , V_83 ) ;
F_36 ( V_2 , V_44 -> V_59 , V_84 ) ;
F_36 ( V_2 , V_44 -> V_61 , V_85 ) ;
V_88 = V_44 -> V_63 ;
if ( V_88 >= 0 )
V_88 += 1 ;
F_36 ( V_2 , V_88 , V_86 ) ;
if ( V_80 -> V_42 ) {
V_87 |= V_14 ;
F_3 ( V_87 , V_2 -> V_5 + V_6 ) ;
}
F_17 ( & V_2 -> V_31 ) ;
return 0 ;
}
static int T_2 F_38 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
struct V_89 * V_90 ;
struct V_43 V_91 ;
char V_92 [ 6 ] ;
int V_93 , V_30 ;
V_2 = F_39 ( & V_46 -> V_33 , sizeof( * V_2 ) , V_94 ) ;
if ( F_40 ( ! V_2 ) )
return - V_95 ;
F_41 ( & V_2 -> V_31 ) ;
V_30 = F_42 ( V_46 , 0 ) ;
if ( F_40 ( V_30 <= 0 ) ) {
F_43 ( & V_46 -> V_33 , L_7 ) ;
return - V_96 ;
}
V_2 -> V_97 = V_30 ;
V_2 -> V_98 = F_42 ( V_46 , 1 ) ;
V_2 -> V_99 = F_42 ( V_46 , 2 ) ;
V_90 = F_44 ( V_46 , V_100 , 0 ) ;
if ( F_40 ( V_90 == NULL ) ) {
F_43 ( & V_46 -> V_33 , L_8 ) ;
return - V_96 ;
}
V_2 -> V_101 = F_45 ( V_90 ) ;
V_2 -> V_90 = F_46 ( & V_46 -> V_33 , V_90 -> V_102 ,
V_2 -> V_101 , V_46 -> V_103 ) ;
if ( F_40 ( ! V_2 -> V_90 ) )
return - V_104 ;
V_2 -> V_5 = F_47 ( & V_46 -> V_33 , V_2 -> V_90 -> V_102 ,
V_2 -> V_101 ) ;
if ( F_40 ( ! V_2 -> V_5 ) )
return - V_105 ;
V_93 = V_46 -> V_106 ;
if ( V_93 < 0 )
V_93 = 0 ;
snprintf ( V_92 , sizeof( V_92 ) , L_9 , V_93 ) ;
V_2 -> V_107 = F_48 ( & V_46 -> V_33 , V_92 ) ;
if ( F_49 ( V_2 -> V_107 ) ) {
V_2 -> V_107 = NULL ;
}
F_50 ( V_2 -> V_107 ) ;
V_2 -> V_65 = V_108 ;
if ( F_51 ( & V_46 -> V_33 ) ) {
struct V_109 * V_110 =
F_51 ( & V_46 -> V_33 ) ;
V_2 -> V_65 |= V_110 -> V_65 ;
}
if ( V_2 -> V_98 <= 0 ) {
V_30 = F_52 ( & V_46 -> V_33 , V_2 -> V_97 ,
F_13 , 0 , L_10 , V_2 ) ;
if ( F_40 ( V_30 ) ) {
F_43 ( & V_46 -> V_33 ,
L_11 , V_30 ,
V_2 -> V_97 ) ;
goto V_111;
}
} else {
V_30 = F_52 ( & V_46 -> V_33 , V_2 -> V_97 ,
F_12 , 0 , L_12 , V_2 ) ;
if ( F_40 ( V_30 ) ) {
F_43 ( & V_46 -> V_33 ,
L_13 ,
V_30 , V_2 -> V_97 ) ;
goto V_111;
}
V_30 = F_52 ( & V_46 -> V_33 , V_2 -> V_98 ,
F_9 , 0 , L_14 , V_2 ) ;
if ( F_40 ( V_30 ) ) {
F_43 ( & V_46 -> V_33 ,
L_15 ,
V_30 , V_2 -> V_98 ) ;
goto V_111;
}
V_30 = F_52 ( & V_46 -> V_33 , V_2 -> V_99 ,
F_11 , 0 , L_16 , V_2 ) ;
if ( F_40 ( V_30 ) ) {
F_43 ( & V_46 -> V_33 ,
L_17 ,
V_30 , V_2 -> V_99 ) ;
goto V_111;
}
}
F_53 ( V_46 , V_2 ) ;
F_18 ( & V_46 -> V_33 , 0 ) ;
F_14 ( & V_46 -> V_33 , 0 ) ;
F_19 ( & V_46 -> V_33 , 0 ) ;
F_22 ( & V_46 -> V_33 , 0 ) ;
V_2 -> V_10 = F_54 ( & V_46 -> V_33 , L_18 ,
& V_112 , V_113 ) ;
if ( F_49 ( V_2 -> V_10 ) ) {
V_30 = F_55 ( V_2 -> V_10 ) ;
goto V_111;
}
V_2 -> V_10 -> V_114 = 256 ;
if ( F_56 ( V_2 -> V_10 , & V_91 ) < 0 ) {
F_57 ( 0 , & V_91 ) ;
F_58 ( V_2 -> V_10 , & V_91 ) ;
}
F_59 ( & V_46 -> V_33 , 1 ) ;
return 0 ;
V_111:
F_60 ( V_2 -> V_107 ) ;
return V_30 ;
}
static int T_3 F_61 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_26 ( V_46 ) ;
F_14 ( & V_46 -> V_33 , 0 ) ;
F_19 ( & V_46 -> V_33 , 0 ) ;
F_22 ( & V_46 -> V_33 , 0 ) ;
F_60 ( V_2 -> V_107 ) ;
return 0 ;
}
static void F_62 ( struct V_32 * V_33 , int V_42 )
{
struct V_45 * V_46 = F_25 ( V_33 ) ;
struct V_1 * V_2 = F_26 ( V_46 ) ;
F_63 ( V_2 -> V_97 , V_42 ) ;
if ( V_2 -> V_98 > 0 ) {
F_63 ( V_2 -> V_98 , V_42 ) ;
F_63 ( V_2 -> V_99 , V_42 ) ;
}
}
static int F_64 ( struct V_32 * V_33 )
{
if ( F_65 ( V_33 ) )
F_62 ( V_33 , 1 ) ;
return 0 ;
}
static int F_66 ( struct V_32 * V_33 )
{
if ( F_65 ( V_33 ) )
F_62 ( V_33 , 0 ) ;
return 0 ;
}
