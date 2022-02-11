static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 -> V_3 + V_2 ) ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_4 )
{
F_4 ( V_4 , V_1 -> V_3 + V_2 ) ;
}
static void F_5 ( struct V_1 * V_1 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ V_7 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_1 , unsigned int V_8 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_9 ) ;
V_5 |= ( V_10 << V_8 ) ;
F_3 ( V_1 , V_9 , V_5 ) ;
}
static void F_7 ( struct V_1 * V_1 ,
unsigned int V_8 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_9 ) ;
V_5 &= ~ ( V_10 << V_8 ) ;
F_3 ( V_1 , V_9 , V_5 ) ;
}
static int F_8 ( struct V_1 * V_1 ,
unsigned int V_11 , bool V_12 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ ( V_13 | V_14 ) ;
V_5 &= ~ ( V_15 | V_16 ) ;
switch ( V_11 ) {
case V_17 :
break;
case V_18 :
V_5 |= V_15 ;
break;
case V_19 :
V_5 |= V_16 ;
if ( V_12 )
V_5 |= V_14 ;
break;
default:
F_9 ( & V_1 -> V_20 -> V_21 , L_1 , V_11 ) ;
return - V_22 ;
}
F_3 ( V_1 , V_6 , V_5 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_1 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_23 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_11 ( struct V_1 * V_1 ,
unsigned int V_24 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
if ( V_24 & V_25 )
V_5 |= V_26 ;
else
V_5 &= ~ V_26 ;
if ( V_24 & V_27 )
V_5 |= V_28 ;
else
V_5 &= ~ V_28 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_12 ( struct V_1 * V_1 ,
unsigned int V_29 , T_2 V_30 )
{
T_1 V_5 ;
T_1 V_31 ;
V_31 = F_13 ( F_14 ( V_1 -> V_32 ) , V_29 ) ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 = V_5 & ~ V_33 ;
V_5 = V_5 | ( V_31 & V_33 ) ;
F_3 ( V_1 , V_6 , V_5 ) ;
if ( V_31 <= 2 ) {
V_5 = F_1 ( V_1 , V_34 ) ;
V_5 |= V_35 ;
F_3 ( V_1 , V_34 , V_5 ) ;
}
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ ( V_26 | V_28 ) ;
if ( V_30 & V_25 )
V_5 |= V_26 ;
if ( V_30 & V_27 )
V_5 |= V_28 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_15 ( struct V_1 * V_1 , unsigned int V_36 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
if ( V_36 == 4 )
V_5 |= V_37 ;
else
V_5 &= ~ V_37 ;
F_3 ( V_1 , V_6 , V_5 ) ;
V_1 -> V_38 = V_36 ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_39 = V_40 ;
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_41 ;
F_3 ( V_1 , V_6 , V_5 ) ;
while ( -- V_39 ) {
V_5 = F_1 ( V_1 , V_6 ) ;
if ( ! ( V_5 & V_41 ) )
return 0 ;
F_17 ( 1 ) ;
}
return - V_42 ;
}
static int F_18 ( struct V_1 * V_1 )
{
struct V_43 * V_20 = V_1 -> V_20 ;
T_1 V_5 ;
int V_44 , V_45 = 0 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_46 ;
F_3 ( V_1 , V_6 , V_5 ) ;
F_17 ( V_40 ) ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ V_46 ;
F_3 ( V_1 , V_6 , V_5 ) ;
F_5 ( V_1 ) ;
for ( V_44 = 0 ; V_44 < V_20 -> V_47 ; V_44 ++ )
F_7 ( V_1 , V_44 ) ;
F_10 ( V_1 ) ;
F_11 ( V_1 , V_20 -> V_24 ) ;
F_3 ( V_1 , V_48 , 0 ) ;
F_3 ( V_1 , V_49 , 0 ) ;
F_3 ( V_1 , V_50 , 0 ) ;
F_3 ( V_1 , V_51 , ~ 0U ) ;
return V_45 ;
}
static T_3 F_19 ( int V_52 , void * V_53 )
{
struct V_43 * V_20 = V_53 ;
struct V_1 * V_1 ;
T_1 V_54 ;
V_1 = F_20 ( V_20 ) ;
V_54 = F_1 ( V_1 , V_51 ) ;
if ( ! V_54 || ! ( V_1 -> V_55 & V_54 ) )
return V_56 ;
F_3 ( V_1 , V_50 , 0 ) ;
F_3 ( V_1 , V_51 , V_54 ) ;
F_21 ( & V_1 -> V_57 ) ;
return V_58 ;
}
static bool F_22 ( struct V_59 * V_60 )
{
struct V_1 * V_1 ;
unsigned int V_39 ;
unsigned int V_61 ;
unsigned long V_62 ;
V_1 = F_20 ( V_60 -> V_20 ) ;
V_61 = F_1 ( V_1 , V_9 ) ;
if ( V_1 -> V_55 & V_61 )
return true ;
F_23 ( & V_1 -> V_57 ) ;
F_3 ( V_1 , V_50 ,
V_1 -> V_55 ) ;
V_62 = F_24 ( V_40 ) ;
V_39 = F_25 ( & V_1 -> V_57 ,
V_62 ) ;
V_1 -> V_55 = 0 ;
if ( V_39 )
return true ;
V_61 = F_1 ( V_1 , V_9 ) ;
if ( V_1 -> V_55 & V_61 )
return true ;
F_3 ( V_1 , V_50 , 0 ) ;
return false ;
}
static bool F_26 ( struct V_59 * V_60 ,
unsigned int V_63 )
{
struct V_1 * V_1 ;
V_1 = F_20 ( V_60 -> V_20 ) ;
V_1 -> V_55 = V_63 ;
return F_22 ( V_60 ) ;
}
static void F_27 ( struct V_1 * V_1 ,
unsigned int V_64 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ ( V_65 << V_66 ) ;
V_5 |= ( V_64 - 1 ) << V_66 ;
V_5 &= ~ ( V_65 << V_67 ) ;
V_5 |= ( 7 - V_64 ) << V_67 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_28 ( struct V_59 * V_60 ,
struct V_68 * V_69 )
{
struct V_1 * V_1 ;
unsigned int V_38 ;
V_1 = F_20 ( V_60 -> V_20 ) ;
F_12 ( V_1 , V_69 -> V_29 , V_60 -> V_30 ) ;
V_38 = V_69 -> V_70 >> 3 ;
F_27 ( V_1 , V_38 ) ;
}
static void F_29 ( struct V_59 * V_60 , bool V_71 )
{
struct V_1 * V_1 = F_20 ( V_60 -> V_20 ) ;
if ( ! V_71 )
F_6 ( V_1 , V_60 -> V_72 ) ;
else
F_7 ( V_1 , V_60 -> V_72 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
unsigned int V_73 ;
T_1 V_5 = 0 ;
F_3 ( V_1 , V_74 , 0 ) ;
F_3 ( V_1 , V_75 , 0 ) ;
F_3 ( V_1 , V_76 , 0 ) ;
F_3 ( V_1 , V_48 , 0 ) ;
if ( V_1 -> V_77 ) {
V_73 = V_1 -> V_78 % 4 ;
if ( V_73 ) {
V_5 = ( V_73 & V_79 )
<< V_80 ;
F_3 ( V_1 , V_48 , V_5 ) ;
V_1 -> V_78 -= V_73 ;
V_5 = 0 ;
while ( V_73 -- ) {
V_5 = ( V_5 << 8 ) | V_1 -> V_77 [ 0 ] ;
V_1 -> V_77 ++ ;
}
F_3 ( V_1 , V_75 , V_5 ) ;
}
}
}
static int F_31 ( struct V_1 * V_1 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_9 ) ;
return ( V_5 & V_81 ) ;
}
static int F_32 ( struct V_1 * V_1 )
{
T_1 V_5 ;
while ( ! F_31 ( V_1 ) && V_1 -> V_78 ) {
V_5 = F_33 ( * ( T_1 * ) V_1 -> V_77 ) ;
F_3 ( V_1 , V_82 , V_5 ) ;
V_1 -> V_78 -= 4 ;
V_1 -> V_77 += 4 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_1 )
{
T_1 V_5 = F_1 ( V_1 , V_9 ) ;
return ( V_5 & V_83 ) ;
}
static int F_35 ( struct V_1 * V_1 )
{
T_1 V_5 ;
while ( ! F_34 ( V_1 ) && V_1 -> V_78 ) {
V_5 = F_1 ( V_1 , V_84 ) ;
if ( V_1 -> V_78 >= 4 ) {
T_1 V_4 = F_36 ( V_5 ) ;
memcpy ( V_1 -> V_85 , & V_4 , 4 ) ;
V_1 -> V_78 -= 4 ;
V_1 -> V_85 += 4 ;
} else {
while ( V_1 -> V_78 ) {
* V_1 -> V_85 = V_5 & 0xff ;
V_5 >>= 8 ;
V_1 -> V_78 -- ;
V_1 -> V_85 ++ ;
}
}
}
return 0 ;
}
static void F_37 ( struct V_1 * V_1 )
{
int V_39 = V_40 ;
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_86 ;
F_3 ( V_1 , V_6 , V_5 ) ;
while ( -- V_39 ) {
V_5 = F_1 ( V_1 , V_6 ) ;
if ( ! ( V_5 & V_87 ) )
break;
F_17 ( 1 ) ;
}
F_16 ( V_1 ) ;
V_5 &= ~ V_86 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static int F_38 ( struct V_43 * V_20 ,
struct V_88 * V_89 )
{
struct V_1 * V_1 = F_20 ( V_20 ) ;
struct V_59 * V_60 = V_89 -> V_60 ;
int V_45 ;
V_45 = F_39 ( V_1 -> V_32 ) ;
if ( V_45 ) {
F_9 ( & V_60 -> V_21 , L_2 , V_45 ) ;
return V_45 ;
}
V_45 = F_16 ( V_1 ) ;
if ( V_45 )
return V_45 ;
F_15 ( V_1 , 4 ) ;
return 0 ;
}
static int F_40 ( struct V_43 * V_20 ,
struct V_59 * V_60 ,
struct V_68 * V_69 )
{
struct V_1 * V_1 = F_20 ( V_20 ) ;
int V_45 = 0 , V_39 = V_40 ;
unsigned int V_90 = 0 ;
T_1 V_5 ;
F_28 ( V_60 , V_69 ) ;
V_1 -> V_77 = V_69 -> V_77 ;
V_1 -> V_85 = V_69 -> V_85 ;
V_1 -> V_78 = V_69 -> V_36 ;
if ( V_69 -> V_77 )
V_90 = V_69 -> V_91 ;
else if ( V_69 -> V_85 )
V_90 = V_69 -> V_92 ;
F_8 ( V_1 , V_90 , V_69 -> V_85 ? true : false ) ;
F_16 ( V_1 ) ;
F_30 ( V_1 ) ;
if ( V_69 -> V_85 ) {
F_3 ( V_1 , V_49 ,
V_1 -> V_78 ) ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ V_93 ;
V_5 |= V_87 ;
F_3 ( V_1 , V_6 , V_5 ) ;
} else if ( V_69 -> V_77 ) {
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= ( V_87 | V_93 ) ;
F_3 ( V_1 , V_6 , V_5 ) ;
V_1 -> V_94 = ( V_1 -> V_78 != 0 ) ;
}
while ( V_1 -> V_78 ) {
if ( V_1 -> V_77 ) {
if ( ! F_26 ( V_60 ,
V_95 ) ) {
F_9 ( & V_60 -> V_21 ,
L_3 ) ;
V_45 = - V_42 ;
goto error;
}
V_45 = F_32 ( V_1 ) ;
if ( V_45 )
goto error;
} else if ( V_1 -> V_85 ) {
if ( ! F_26 ( V_60 ,
V_96 ) ) {
F_9 ( & V_60 -> V_21 ,
L_4 ) ;
V_45 = - V_42 ;
goto error;
}
V_45 = F_35 ( V_1 ) ;
if ( V_45 )
goto error;
}
}
if ( V_1 -> V_77 ) {
if ( V_1 -> V_94 ) {
if ( ! F_26 ( V_60 ,
V_97 ) ) {
F_9 ( & V_60 -> V_21 , L_5 ) ;
return - V_42 ;
}
}
if ( ! F_26 ( V_60 , V_98 ) ) {
F_9 ( & V_60 -> V_21 , L_6 ) ;
return - V_42 ;
}
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_86 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
while ( -- V_39 ) {
V_5 = F_1 ( V_1 , V_6 ) ;
if ( ! ( V_5 & V_87 ) )
break;
F_17 ( 1 ) ;
}
if ( V_39 == 0 ) {
F_9 ( & V_60 -> V_21 , L_7 ) ;
V_45 = - V_42 ;
goto error;
}
V_5 &= ~ V_86 ;
F_3 ( V_1 , V_6 , V_5 ) ;
goto V_99;
error:
F_37 ( V_1 ) ;
V_99:
F_41 ( V_20 ) ;
return V_45 ;
}
static int F_42 ( struct V_43 * V_20 ,
struct V_88 * V_89 )
{
struct V_1 * V_1 = F_20 ( V_20 ) ;
F_43 ( V_1 -> V_32 ) ;
return 0 ;
}
static int F_44 ( struct V_100 * V_101 )
{
struct V_102 * V_21 = & V_101 -> V_21 ;
struct V_103 * V_104 = V_21 -> V_104 ;
struct V_105 * V_106 ;
struct V_43 * V_20 ;
struct V_1 * V_60 ;
T_1 V_107 = 0 ;
int V_52 , V_45 = 0 ;
V_20 = F_45 ( V_21 , sizeof( * V_60 ) ) ;
if ( ! V_20 ) {
F_9 ( V_21 , L_8 ) ;
V_45 = - V_108 ;
goto V_99;
}
if ( F_46 ( V_104 , L_9 , & V_107 ) ) {
F_9 ( V_21 , L_10 ) ;
V_45 = - V_109 ;
goto error;
}
V_20 -> V_110 = V_101 -> V_111 ;
V_20 -> V_21 . V_104 = V_104 ;
V_20 -> V_24 = V_112 ;
V_20 -> V_47 = V_107 ;
V_20 -> V_113 = F_47 ( 8 ) | F_47 ( 32 ) ;
V_20 -> V_114 = F_38 ;
V_20 -> V_115 = F_40 ;
V_20 -> V_116 = F_42 ;
V_20 -> V_117 = F_29 ;
V_20 -> V_118 = V_119 ;
V_20 -> V_24 |= ( V_120 | V_121 |
V_122 | V_123 ) ;
F_48 ( V_101 , V_20 ) ;
V_60 = F_20 ( V_20 ) ;
memset ( V_60 , 0 , sizeof( struct V_1 ) ) ;
V_60 -> V_20 = V_20 ;
V_106 = F_49 ( V_101 , V_124 , 0 ) ;
V_60 -> V_3 = F_50 ( V_21 , V_106 ) ;
if ( F_51 ( V_60 -> V_3 ) ) {
V_45 = F_52 ( V_60 -> V_3 ) ;
goto error;
}
V_52 = F_53 ( V_101 , 0 ) ;
if ( V_52 < 0 ) {
F_9 ( V_21 , L_11 , V_52 ) ;
V_45 = - V_109 ;
goto error;
}
V_60 -> V_52 = V_52 ;
F_54 ( & V_60 -> V_57 ) ;
V_60 -> V_32 = F_55 ( V_21 , NULL ) ;
if ( F_51 ( V_60 -> V_32 ) ) {
F_9 ( V_21 , L_12 , F_52 ( V_60 -> V_32 ) ) ;
goto error;
}
V_45 = F_56 ( V_60 -> V_32 ) ;
if ( V_45 ) {
F_9 ( V_21 , L_13 , V_45 ) ;
goto error;
}
V_45 = F_18 ( V_60 ) ;
if ( V_45 )
goto V_125;
V_45 = F_57 ( V_21 , V_60 -> V_52 , F_19 , 0 ,
F_58 ( V_21 ) , V_20 ) ;
if ( V_45 ) {
F_9 ( V_21 , L_14 , V_45 ) ;
goto V_125;
}
V_45 = F_59 ( V_21 , V_20 ) ;
if ( V_45 ) {
F_9 ( V_21 , L_15 ) ;
goto V_125;
}
return 0 ;
V_125:
F_60 ( V_60 -> V_32 ) ;
error:
F_61 ( V_20 ) ;
V_99:
return V_45 ;
}
static int F_62 ( struct V_100 * V_101 )
{
struct V_43 * V_20 = F_63 ( V_101 ) ;
struct V_1 * V_60 = F_20 ( V_20 ) ;
F_64 ( V_60 -> V_32 ) ;
return 0 ;
}
