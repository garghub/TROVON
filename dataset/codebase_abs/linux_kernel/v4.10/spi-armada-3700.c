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
unsigned int V_11 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ ( V_12 | V_13 ) ;
V_5 &= ~ ( V_14 | V_15 ) ;
switch ( V_11 ) {
case 1 :
break;
case 2 :
V_5 |= V_14 ;
break;
case 4 :
V_5 |= V_15 ;
break;
default:
F_9 ( & V_1 -> V_16 -> V_17 , L_1 , V_11 ) ;
return - V_18 ;
}
F_3 ( V_1 , V_6 , V_5 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_1 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_19 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_11 ( struct V_1 * V_1 ,
unsigned int V_20 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
if ( V_20 & V_21 )
V_5 |= V_22 ;
else
V_5 &= ~ V_22 ;
if ( V_20 & V_23 )
V_5 |= V_24 ;
else
V_5 &= ~ V_24 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_12 ( struct V_1 * V_1 ,
unsigned int V_25 , T_2 V_26 )
{
T_1 V_5 ;
T_1 V_27 ;
V_27 = F_13 ( F_14 ( V_1 -> V_28 ) , V_25 ) ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 = V_5 & ~ V_29 ;
V_5 = V_5 | ( V_27 & V_29 ) ;
F_3 ( V_1 , V_6 , V_5 ) ;
if ( V_27 <= 2 ) {
V_5 = F_1 ( V_1 , V_30 ) ;
V_5 |= V_31 ;
F_3 ( V_1 , V_30 , V_5 ) ;
}
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ ( V_22 | V_24 ) ;
if ( V_26 & V_21 )
V_5 |= V_22 ;
if ( V_26 & V_23 )
V_5 |= V_24 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_15 ( struct V_1 * V_1 , unsigned int V_32 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
if ( V_32 == 4 )
V_5 |= V_33 ;
else
V_5 &= ~ V_33 ;
F_3 ( V_1 , V_6 , V_5 ) ;
V_1 -> V_34 = V_32 ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_35 = V_36 ;
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_37 ;
F_3 ( V_1 , V_6 , V_5 ) ;
while ( -- V_35 ) {
V_5 = F_1 ( V_1 , V_6 ) ;
if ( ! ( V_5 & V_37 ) )
return 0 ;
F_17 ( 1 ) ;
}
return - V_38 ;
}
static int F_18 ( struct V_1 * V_1 )
{
struct V_39 * V_16 = V_1 -> V_16 ;
T_1 V_5 ;
int V_40 , V_41 = 0 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_42 ;
F_3 ( V_1 , V_6 , V_5 ) ;
F_17 ( V_36 ) ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ V_42 ;
F_3 ( V_1 , V_6 , V_5 ) ;
F_5 ( V_1 ) ;
for ( V_40 = 0 ; V_40 < V_16 -> V_43 ; V_40 ++ )
F_7 ( V_1 , V_40 ) ;
F_10 ( V_1 ) ;
F_11 ( V_1 , V_16 -> V_20 ) ;
F_3 ( V_1 , V_44 , 0 ) ;
F_3 ( V_1 , V_45 , 0 ) ;
F_3 ( V_1 , V_46 , 0 ) ;
F_3 ( V_1 , V_47 , ~ 0U ) ;
return V_41 ;
}
static T_3 F_19 ( int V_48 , void * V_49 )
{
struct V_39 * V_16 = V_49 ;
struct V_1 * V_1 ;
T_1 V_50 ;
V_1 = F_20 ( V_16 ) ;
V_50 = F_1 ( V_1 , V_47 ) ;
if ( ! V_50 || ! ( V_1 -> V_51 & V_50 ) )
return V_52 ;
F_3 ( V_1 , V_46 , 0 ) ;
F_3 ( V_1 , V_47 , V_50 ) ;
if ( V_1 -> V_51 & V_50 )
F_21 ( & V_1 -> V_53 ) ;
return V_54 ;
}
static bool F_22 ( struct V_55 * V_56 )
{
struct V_1 * V_1 ;
unsigned int V_35 ;
unsigned int V_57 ;
unsigned long V_58 ;
V_1 = F_20 ( V_56 -> V_16 ) ;
V_57 = F_1 ( V_1 , V_9 ) ;
if ( V_1 -> V_51 & V_57 )
return true ;
F_23 ( & V_1 -> V_53 ) ;
F_3 ( V_1 , V_46 ,
V_1 -> V_51 ) ;
V_58 = F_24 ( V_36 ) ;
V_35 = F_25 ( & V_1 -> V_53 ,
V_58 ) ;
V_1 -> V_51 = 0 ;
if ( V_35 )
return true ;
V_57 = F_1 ( V_1 , V_9 ) ;
if ( V_1 -> V_51 & V_57 )
return true ;
F_3 ( V_1 , V_46 , 0 ) ;
return true ;
}
static bool F_26 ( struct V_55 * V_56 ,
unsigned int V_59 )
{
struct V_1 * V_1 ;
V_1 = F_20 ( V_56 -> V_16 ) ;
V_1 -> V_51 = V_59 ;
return F_22 ( V_56 ) ;
}
static void F_27 ( struct V_1 * V_1 ,
unsigned int V_60 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ ( V_61 << V_62 ) ;
V_5 |= ( V_60 - 1 ) << V_62 ;
V_5 &= ~ ( V_61 << V_63 ) ;
V_5 |= ( 7 - V_60 ) << V_63 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_28 ( struct V_55 * V_56 ,
struct V_64 * V_65 )
{
struct V_1 * V_1 ;
unsigned int V_34 ;
V_1 = F_20 ( V_56 -> V_16 ) ;
F_12 ( V_1 , V_65 -> V_25 , V_56 -> V_26 ) ;
V_34 = V_65 -> V_66 >> 3 ;
F_27 ( V_1 , V_34 ) ;
}
static void F_29 ( struct V_55 * V_56 , bool V_67 )
{
struct V_1 * V_1 = F_20 ( V_56 -> V_16 ) ;
if ( ! V_67 )
F_6 ( V_1 , V_56 -> V_68 ) ;
else
F_7 ( V_1 , V_56 -> V_68 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
T_1 V_69 = 0 , V_70 = 0 , V_71 = 0 ;
T_1 V_5 = 0 ;
F_3 ( V_1 , V_72 , 0 ) ;
F_3 ( V_1 , V_73 , 0 ) ;
F_3 ( V_1 , V_74 , 0 ) ;
if ( V_1 -> V_75 ) {
if ( V_1 -> V_76 <= V_1 -> V_69 ) {
V_69 = V_1 -> V_76 ;
} else if ( V_1 -> V_76 <= ( V_1 -> V_69 +
V_1 -> V_70 ) ) {
V_69 = V_1 -> V_69 ;
V_70 = V_1 -> V_76 - V_69 ;
} else if ( V_1 -> V_76 <= V_1 -> V_77 ) {
V_69 = V_1 -> V_69 ;
V_70 = V_1 -> V_70 ;
if ( ! V_1 -> V_75 [ V_69 + V_70 ] )
V_71 = V_1 -> V_76 - V_69 -
V_70 ;
}
V_5 |= ( ( V_69 & V_78 )
<< V_79 ) ;
V_5 |= ( ( V_70 & V_80 )
<< V_81 ) ;
V_5 |= ( ( V_71 & V_82 )
<< V_83 ) ;
}
F_3 ( V_1 , V_44 , V_5 ) ;
V_1 -> V_76 -= ( V_69 + V_70 + V_71 ) ;
V_5 = 0 ;
while ( V_69 -- ) {
V_5 = ( V_5 << 8 ) | V_1 -> V_75 [ 0 ] ;
V_1 -> V_75 ++ ;
}
F_3 ( V_1 , V_72 , V_5 ) ;
V_5 = 0 ;
while ( V_70 -- ) {
V_5 = ( V_5 << 8 ) | V_1 -> V_75 [ 0 ] ;
V_1 -> V_75 ++ ;
}
F_3 ( V_1 , V_73 , V_5 ) ;
}
static int F_31 ( struct V_1 * V_1 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_9 ) ;
return ( V_5 & V_84 ) ;
}
static int F_32 ( struct V_1 * V_1 )
{
T_1 V_5 ;
int V_40 = 0 ;
while ( ! F_31 ( V_1 ) && V_1 -> V_76 ) {
V_5 = 0 ;
if ( V_1 -> V_76 >= 4 ) {
V_5 = F_33 ( * ( T_1 * ) V_1 -> V_75 ) ;
F_3 ( V_1 , V_85 , V_5 ) ;
V_1 -> V_76 -= 4 ;
V_1 -> V_75 += 4 ;
} else {
V_5 = F_34 ( 31 , 0 ) ;
while ( V_1 -> V_76 ) {
V_5 &= ~ ( 0xff << ( 8 * V_40 ) ) ;
V_5 |= * V_1 -> V_75 ++ << ( 8 * V_40 ) ;
V_40 ++ ;
V_1 -> V_76 -- ;
F_3 ( V_1 , V_85 ,
V_5 ) ;
}
break;
}
}
return 0 ;
}
static int F_35 ( struct V_1 * V_1 )
{
T_1 V_5 = F_1 ( V_1 , V_9 ) ;
return ( V_5 & V_86 ) ;
}
static int F_36 ( struct V_1 * V_1 )
{
T_1 V_5 ;
while ( ! F_35 ( V_1 ) && V_1 -> V_76 ) {
V_5 = F_1 ( V_1 , V_87 ) ;
if ( V_1 -> V_76 >= 4 ) {
T_1 V_4 = F_37 ( V_5 ) ;
memcpy ( V_1 -> V_88 , & V_4 , 4 ) ;
V_1 -> V_76 -= 4 ;
V_1 -> V_88 += 4 ;
} else {
while ( V_1 -> V_76 ) {
* V_1 -> V_88 = V_5 & 0xff ;
V_5 >>= 8 ;
V_1 -> V_76 -- ;
V_1 -> V_88 ++ ;
}
}
}
return 0 ;
}
static void F_38 ( struct V_1 * V_1 )
{
int V_35 = V_36 ;
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_89 ;
F_3 ( V_1 , V_6 , V_5 ) ;
while ( -- V_35 ) {
V_5 = F_1 ( V_1 , V_6 ) ;
if ( ! ( V_5 & V_90 ) )
break;
F_17 ( 1 ) ;
}
F_16 ( V_1 ) ;
V_5 &= ~ V_89 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static int F_39 ( struct V_39 * V_16 ,
struct V_91 * V_92 )
{
struct V_1 * V_1 = F_20 ( V_16 ) ;
struct V_55 * V_56 = V_92 -> V_56 ;
int V_41 ;
V_41 = F_40 ( V_1 -> V_28 ) ;
if ( V_41 ) {
F_9 ( & V_56 -> V_17 , L_2 , V_41 ) ;
return V_41 ;
}
V_41 = F_16 ( V_1 ) ;
if ( V_41 )
return V_41 ;
F_15 ( V_1 , 4 ) ;
return 0 ;
}
static int F_41 ( struct V_39 * V_16 ,
struct V_55 * V_56 ,
struct V_64 * V_65 )
{
struct V_1 * V_1 = F_20 ( V_16 ) ;
int V_41 = 0 , V_35 = V_36 ;
unsigned int V_93 = 0 ;
T_1 V_5 ;
F_28 ( V_56 , V_65 ) ;
V_1 -> V_75 = V_65 -> V_75 ;
V_1 -> V_88 = V_65 -> V_88 ;
V_1 -> V_76 = V_65 -> V_32 ;
F_30 ( V_1 ) ;
if ( V_65 -> V_75 )
V_93 = V_65 -> V_94 ;
else if ( V_65 -> V_88 )
V_93 = V_65 -> V_95 ;
F_8 ( V_1 , V_93 ) ;
if ( V_65 -> V_88 ) {
F_3 ( V_1 , V_45 ,
V_1 -> V_76 ) ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ V_96 ;
V_5 |= V_90 ;
F_3 ( V_1 , V_6 , V_5 ) ;
} else if ( V_65 -> V_75 ) {
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= ( V_90 | V_96 ) ;
F_3 ( V_1 , V_6 , V_5 ) ;
V_1 -> V_97 = ( V_1 -> V_76 != 0 ) ;
}
while ( V_1 -> V_76 ) {
if ( V_1 -> V_75 ) {
if ( ! F_26 ( V_56 ,
V_98 ) ) {
F_9 ( & V_56 -> V_17 ,
L_3 ) ;
V_41 = - V_38 ;
goto error;
}
V_41 = F_32 ( V_1 ) ;
if ( V_41 )
goto error;
} else if ( V_1 -> V_88 ) {
if ( ! F_26 ( V_56 ,
V_99 ) ) {
F_9 ( & V_56 -> V_17 ,
L_4 ) ;
V_41 = - V_38 ;
goto error;
}
V_41 = F_36 ( V_1 ) ;
if ( V_41 )
goto error;
}
}
if ( V_1 -> V_75 ) {
if ( V_1 -> V_97 ) {
if ( ! F_26 ( V_56 ,
V_100 ) ) {
F_9 ( & V_56 -> V_17 , L_5 ) ;
return - V_38 ;
}
} else {
if ( ! F_26 ( V_56 , V_101 ) ) {
F_9 ( & V_56 -> V_17 , L_6 ) ;
return - V_38 ;
}
}
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_89 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
while ( -- V_35 ) {
V_5 = F_1 ( V_1 , V_6 ) ;
if ( ! ( V_5 & V_90 ) )
break;
F_17 ( 1 ) ;
}
if ( V_35 == 0 ) {
F_9 ( & V_56 -> V_17 , L_7 ) ;
V_41 = - V_38 ;
goto error;
}
V_5 &= ~ V_89 ;
F_3 ( V_1 , V_6 , V_5 ) ;
goto V_102;
error:
F_38 ( V_1 ) ;
V_102:
F_42 ( V_16 ) ;
return V_41 ;
}
static int F_43 ( struct V_39 * V_16 ,
struct V_91 * V_92 )
{
struct V_1 * V_1 = F_20 ( V_16 ) ;
F_44 ( V_1 -> V_28 ) ;
return 0 ;
}
static int F_45 ( struct V_103 * V_104 )
{
struct V_105 * V_17 = & V_104 -> V_17 ;
struct V_106 * V_107 = V_17 -> V_107 ;
struct V_108 * V_109 ;
struct V_39 * V_16 ;
struct V_1 * V_56 ;
T_1 V_110 = 0 ;
int V_48 , V_41 = 0 ;
V_16 = F_46 ( V_17 , sizeof( * V_56 ) ) ;
if ( ! V_16 ) {
F_9 ( V_17 , L_8 ) ;
V_41 = - V_111 ;
goto V_102;
}
if ( F_47 ( V_107 , L_9 , & V_110 ) ) {
F_9 ( V_17 , L_10 ) ;
V_41 = - V_112 ;
goto error;
}
V_16 -> V_113 = V_104 -> V_114 ;
V_16 -> V_17 . V_107 = V_107 ;
V_16 -> V_20 = V_115 ;
V_16 -> V_43 = V_110 ;
V_16 -> V_116 = F_48 ( 8 ) | F_48 ( 32 ) ;
V_16 -> V_117 = F_39 ;
V_16 -> V_118 = F_41 ;
V_16 -> V_119 = F_43 ;
V_16 -> V_120 = F_29 ;
V_16 -> V_121 = V_122 ;
V_16 -> V_20 |= ( V_123 | V_124 |
V_125 | V_126 ) ;
F_49 ( V_104 , V_16 ) ;
V_56 = F_20 ( V_16 ) ;
memset ( V_56 , 0 , sizeof( struct V_1 ) ) ;
V_56 -> V_16 = V_16 ;
V_56 -> V_69 = V_127 ;
V_56 -> V_70 = V_128 ;
V_56 -> V_77 = V_127 + V_128 +
V_129 ;
V_109 = F_50 ( V_104 , V_130 , 0 ) ;
V_56 -> V_3 = F_51 ( V_17 , V_109 ) ;
if ( F_52 ( V_56 -> V_3 ) ) {
V_41 = F_53 ( V_56 -> V_3 ) ;
goto error;
}
V_48 = F_54 ( V_104 , 0 ) ;
if ( V_48 < 0 ) {
F_9 ( V_17 , L_11 , V_48 ) ;
V_41 = - V_112 ;
goto error;
}
V_56 -> V_48 = V_48 ;
F_55 ( & V_56 -> V_53 ) ;
V_56 -> V_28 = F_56 ( V_17 , NULL ) ;
if ( F_52 ( V_56 -> V_28 ) ) {
F_9 ( V_17 , L_12 , F_53 ( V_56 -> V_28 ) ) ;
goto error;
}
V_41 = F_57 ( V_56 -> V_28 ) ;
if ( V_41 ) {
F_9 ( V_17 , L_13 , V_41 ) ;
goto error;
}
V_41 = F_18 ( V_56 ) ;
if ( V_41 )
goto V_131;
V_41 = F_58 ( V_17 , V_56 -> V_48 , F_19 , 0 ,
F_59 ( V_17 ) , V_16 ) ;
if ( V_41 ) {
F_9 ( V_17 , L_14 , V_41 ) ;
goto V_131;
}
V_41 = F_60 ( V_17 , V_16 ) ;
if ( V_41 ) {
F_9 ( V_17 , L_15 ) ;
goto V_131;
}
return 0 ;
V_131:
F_61 ( V_56 -> V_28 ) ;
error:
F_62 ( V_16 ) ;
V_102:
return V_41 ;
}
static int F_63 ( struct V_103 * V_104 )
{
struct V_39 * V_16 = F_64 ( V_104 ) ;
struct V_1 * V_56 = F_20 ( V_16 ) ;
F_65 ( V_56 -> V_28 ) ;
F_62 ( V_16 ) ;
return 0 ;
}
