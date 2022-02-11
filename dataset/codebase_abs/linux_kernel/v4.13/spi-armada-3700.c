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
case V_16 :
break;
case V_17 :
V_5 |= V_14 ;
break;
case V_18 :
V_5 |= V_15 ;
break;
default:
F_9 ( & V_1 -> V_19 -> V_20 , L_1 , V_11 ) ;
return - V_21 ;
}
F_3 ( V_1 , V_6 , V_5 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_1 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_22 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_11 ( struct V_1 * V_1 ,
unsigned int V_23 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
if ( V_23 & V_24 )
V_5 |= V_25 ;
else
V_5 &= ~ V_25 ;
if ( V_23 & V_26 )
V_5 |= V_27 ;
else
V_5 &= ~ V_27 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_12 ( struct V_1 * V_1 ,
unsigned int V_28 , T_2 V_29 )
{
T_1 V_5 ;
T_1 V_30 ;
V_30 = F_13 ( F_14 ( V_1 -> V_31 ) , V_28 ) ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 = V_5 & ~ V_32 ;
V_5 = V_5 | ( V_30 & V_32 ) ;
F_3 ( V_1 , V_6 , V_5 ) ;
if ( V_30 <= 2 ) {
V_5 = F_1 ( V_1 , V_33 ) ;
V_5 |= V_34 ;
F_3 ( V_1 , V_33 , V_5 ) ;
}
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ ( V_25 | V_27 ) ;
if ( V_29 & V_24 )
V_5 |= V_25 ;
if ( V_29 & V_26 )
V_5 |= V_27 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_15 ( struct V_1 * V_1 , unsigned int V_35 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
if ( V_35 == 4 )
V_5 |= V_36 ;
else
V_5 &= ~ V_36 ;
F_3 ( V_1 , V_6 , V_5 ) ;
V_1 -> V_37 = V_35 ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_38 = V_39 ;
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_40 ;
F_3 ( V_1 , V_6 , V_5 ) ;
while ( -- V_38 ) {
V_5 = F_1 ( V_1 , V_6 ) ;
if ( ! ( V_5 & V_40 ) )
return 0 ;
F_17 ( 1 ) ;
}
return - V_41 ;
}
static int F_18 ( struct V_1 * V_1 )
{
struct V_42 * V_19 = V_1 -> V_19 ;
T_1 V_5 ;
int V_43 , V_44 = 0 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_45 ;
F_3 ( V_1 , V_6 , V_5 ) ;
F_17 ( V_39 ) ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ V_45 ;
F_3 ( V_1 , V_6 , V_5 ) ;
F_5 ( V_1 ) ;
for ( V_43 = 0 ; V_43 < V_19 -> V_46 ; V_43 ++ )
F_7 ( V_1 , V_43 ) ;
F_10 ( V_1 ) ;
F_11 ( V_1 , V_19 -> V_23 ) ;
F_3 ( V_1 , V_47 , 0 ) ;
F_3 ( V_1 , V_48 , 0 ) ;
F_3 ( V_1 , V_49 , 0 ) ;
F_3 ( V_1 , V_50 , ~ 0U ) ;
return V_44 ;
}
static T_3 F_19 ( int V_51 , void * V_52 )
{
struct V_42 * V_19 = V_52 ;
struct V_1 * V_1 ;
T_1 V_53 ;
V_1 = F_20 ( V_19 ) ;
V_53 = F_1 ( V_1 , V_50 ) ;
if ( ! V_53 || ! ( V_1 -> V_54 & V_53 ) )
return V_55 ;
F_3 ( V_1 , V_49 , 0 ) ;
F_3 ( V_1 , V_50 , V_53 ) ;
F_21 ( & V_1 -> V_56 ) ;
return V_57 ;
}
static bool F_22 ( struct V_58 * V_59 )
{
struct V_1 * V_1 ;
unsigned int V_38 ;
unsigned int V_60 ;
unsigned long V_61 ;
V_1 = F_20 ( V_59 -> V_19 ) ;
V_60 = F_1 ( V_1 , V_9 ) ;
if ( V_1 -> V_54 & V_60 )
return true ;
F_23 ( & V_1 -> V_56 ) ;
F_3 ( V_1 , V_49 ,
V_1 -> V_54 ) ;
V_61 = F_24 ( V_39 ) ;
V_38 = F_25 ( & V_1 -> V_56 ,
V_61 ) ;
V_1 -> V_54 = 0 ;
if ( V_38 )
return true ;
V_60 = F_1 ( V_1 , V_9 ) ;
if ( V_1 -> V_54 & V_60 )
return true ;
F_3 ( V_1 , V_49 , 0 ) ;
return true ;
}
static bool F_26 ( struct V_58 * V_59 ,
unsigned int V_62 )
{
struct V_1 * V_1 ;
V_1 = F_20 ( V_59 -> V_19 ) ;
V_1 -> V_54 = V_62 ;
return F_22 ( V_59 ) ;
}
static void F_27 ( struct V_1 * V_1 ,
unsigned int V_63 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ ( V_64 << V_65 ) ;
V_5 |= ( V_63 - 1 ) << V_65 ;
V_5 &= ~ ( V_64 << V_66 ) ;
V_5 |= ( 7 - V_63 ) << V_66 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static void F_28 ( struct V_58 * V_59 ,
struct V_67 * V_68 )
{
struct V_1 * V_1 ;
unsigned int V_37 ;
V_1 = F_20 ( V_59 -> V_19 ) ;
F_12 ( V_1 , V_68 -> V_28 , V_59 -> V_29 ) ;
V_37 = V_68 -> V_69 >> 3 ;
F_27 ( V_1 , V_37 ) ;
}
static void F_29 ( struct V_58 * V_59 , bool V_70 )
{
struct V_1 * V_1 = F_20 ( V_59 -> V_19 ) ;
if ( ! V_70 )
F_6 ( V_1 , V_59 -> V_71 ) ;
else
F_7 ( V_1 , V_59 -> V_71 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
T_1 V_72 = 0 , V_73 = 0 , V_74 = 0 ;
T_1 V_5 = 0 ;
F_3 ( V_1 , V_75 , 0 ) ;
F_3 ( V_1 , V_76 , 0 ) ;
F_3 ( V_1 , V_77 , 0 ) ;
if ( V_1 -> V_78 ) {
if ( V_1 -> V_79 <= V_1 -> V_72 ) {
V_72 = V_1 -> V_79 ;
} else if ( V_1 -> V_79 <= ( V_1 -> V_72 +
V_1 -> V_73 ) ) {
V_72 = V_1 -> V_72 ;
V_73 = V_1 -> V_79 - V_72 ;
} else if ( V_1 -> V_79 <= V_1 -> V_80 ) {
V_72 = V_1 -> V_72 ;
V_73 = V_1 -> V_73 ;
if ( ! V_1 -> V_78 [ V_72 + V_73 ] )
V_74 = V_1 -> V_79 - V_72 -
V_73 ;
}
V_5 |= ( ( V_72 & V_81 )
<< V_82 ) ;
V_5 |= ( ( V_73 & V_83 )
<< V_84 ) ;
V_5 |= ( ( V_74 & V_85 )
<< V_86 ) ;
}
F_3 ( V_1 , V_47 , V_5 ) ;
V_1 -> V_79 -= ( V_72 + V_73 + V_74 ) ;
V_5 = 0 ;
while ( V_72 -- ) {
V_5 = ( V_5 << 8 ) | V_1 -> V_78 [ 0 ] ;
V_1 -> V_78 ++ ;
}
F_3 ( V_1 , V_75 , V_5 ) ;
V_5 = 0 ;
while ( V_73 -- ) {
V_5 = ( V_5 << 8 ) | V_1 -> V_78 [ 0 ] ;
V_1 -> V_78 ++ ;
}
F_3 ( V_1 , V_76 , V_5 ) ;
}
static int F_31 ( struct V_1 * V_1 )
{
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_9 ) ;
return ( V_5 & V_87 ) ;
}
static int F_32 ( struct V_1 * V_1 )
{
T_1 V_5 ;
int V_43 = 0 ;
while ( ! F_31 ( V_1 ) && V_1 -> V_79 ) {
V_5 = 0 ;
if ( V_1 -> V_79 >= 4 ) {
V_5 = F_33 ( * ( T_1 * ) V_1 -> V_78 ) ;
F_3 ( V_1 , V_88 , V_5 ) ;
V_1 -> V_79 -= 4 ;
V_1 -> V_78 += 4 ;
} else {
V_5 = F_34 ( 31 , 0 ) ;
while ( V_1 -> V_79 ) {
V_5 &= ~ ( 0xff << ( 8 * V_43 ) ) ;
V_5 |= * V_1 -> V_78 ++ << ( 8 * V_43 ) ;
V_43 ++ ;
V_1 -> V_79 -- ;
F_3 ( V_1 , V_88 ,
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
return ( V_5 & V_89 ) ;
}
static int F_36 ( struct V_1 * V_1 )
{
T_1 V_5 ;
while ( ! F_35 ( V_1 ) && V_1 -> V_79 ) {
V_5 = F_1 ( V_1 , V_90 ) ;
if ( V_1 -> V_79 >= 4 ) {
T_1 V_4 = F_37 ( V_5 ) ;
memcpy ( V_1 -> V_91 , & V_4 , 4 ) ;
V_1 -> V_79 -= 4 ;
V_1 -> V_91 += 4 ;
} else {
while ( V_1 -> V_79 ) {
* V_1 -> V_91 = V_5 & 0xff ;
V_5 >>= 8 ;
V_1 -> V_79 -- ;
V_1 -> V_91 ++ ;
}
}
}
return 0 ;
}
static void F_38 ( struct V_1 * V_1 )
{
int V_38 = V_39 ;
T_1 V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_92 ;
F_3 ( V_1 , V_6 , V_5 ) ;
while ( -- V_38 ) {
V_5 = F_1 ( V_1 , V_6 ) ;
if ( ! ( V_5 & V_93 ) )
break;
F_17 ( 1 ) ;
}
F_16 ( V_1 ) ;
V_5 &= ~ V_92 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
static int F_39 ( struct V_42 * V_19 ,
struct V_94 * V_95 )
{
struct V_1 * V_1 = F_20 ( V_19 ) ;
struct V_58 * V_59 = V_95 -> V_59 ;
int V_44 ;
V_44 = F_40 ( V_1 -> V_31 ) ;
if ( V_44 ) {
F_9 ( & V_59 -> V_20 , L_2 , V_44 ) ;
return V_44 ;
}
V_44 = F_16 ( V_1 ) ;
if ( V_44 )
return V_44 ;
F_15 ( V_1 , 4 ) ;
return 0 ;
}
static int F_41 ( struct V_42 * V_19 ,
struct V_58 * V_59 ,
struct V_67 * V_68 )
{
struct V_1 * V_1 = F_20 ( V_19 ) ;
int V_44 = 0 , V_38 = V_39 ;
unsigned int V_96 = 0 ;
T_1 V_5 ;
F_28 ( V_59 , V_68 ) ;
V_1 -> V_78 = V_68 -> V_78 ;
V_1 -> V_91 = V_68 -> V_91 ;
V_1 -> V_79 = V_68 -> V_35 ;
F_30 ( V_1 ) ;
if ( V_68 -> V_78 )
V_96 = V_68 -> V_97 ;
else if ( V_68 -> V_91 )
V_96 = V_68 -> V_98 ;
F_8 ( V_1 , V_96 ) ;
if ( V_68 -> V_91 ) {
F_3 ( V_1 , V_48 ,
V_1 -> V_79 ) ;
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 &= ~ V_99 ;
V_5 |= V_93 ;
F_3 ( V_1 , V_6 , V_5 ) ;
} else if ( V_68 -> V_78 ) {
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= ( V_93 | V_99 ) ;
F_3 ( V_1 , V_6 , V_5 ) ;
V_1 -> V_100 = ( V_1 -> V_79 != 0 ) ;
}
while ( V_1 -> V_79 ) {
if ( V_1 -> V_78 ) {
if ( ! F_26 ( V_59 ,
V_101 ) ) {
F_9 ( & V_59 -> V_20 ,
L_3 ) ;
V_44 = - V_41 ;
goto error;
}
V_44 = F_32 ( V_1 ) ;
if ( V_44 )
goto error;
} else if ( V_1 -> V_91 ) {
if ( ! F_26 ( V_59 ,
V_102 ) ) {
F_9 ( & V_59 -> V_20 ,
L_4 ) ;
V_44 = - V_41 ;
goto error;
}
V_44 = F_36 ( V_1 ) ;
if ( V_44 )
goto error;
}
}
if ( V_1 -> V_78 ) {
if ( V_1 -> V_100 ) {
if ( ! F_26 ( V_59 ,
V_103 ) ) {
F_9 ( & V_59 -> V_20 , L_5 ) ;
return - V_41 ;
}
} else {
if ( ! F_26 ( V_59 , V_104 ) ) {
F_9 ( & V_59 -> V_20 , L_6 ) ;
return - V_41 ;
}
}
V_5 = F_1 ( V_1 , V_6 ) ;
V_5 |= V_92 ;
F_3 ( V_1 , V_6 , V_5 ) ;
}
while ( -- V_38 ) {
V_5 = F_1 ( V_1 , V_6 ) ;
if ( ! ( V_5 & V_93 ) )
break;
F_17 ( 1 ) ;
}
if ( V_38 == 0 ) {
F_9 ( & V_59 -> V_20 , L_7 ) ;
V_44 = - V_41 ;
goto error;
}
V_5 &= ~ V_92 ;
F_3 ( V_1 , V_6 , V_5 ) ;
goto V_105;
error:
F_38 ( V_1 ) ;
V_105:
F_42 ( V_19 ) ;
return V_44 ;
}
static int F_43 ( struct V_42 * V_19 ,
struct V_94 * V_95 )
{
struct V_1 * V_1 = F_20 ( V_19 ) ;
F_44 ( V_1 -> V_31 ) ;
return 0 ;
}
static int F_45 ( struct V_106 * V_107 )
{
struct V_108 * V_20 = & V_107 -> V_20 ;
struct V_109 * V_110 = V_20 -> V_110 ;
struct V_111 * V_112 ;
struct V_42 * V_19 ;
struct V_1 * V_59 ;
T_1 V_113 = 0 ;
int V_51 , V_44 = 0 ;
V_19 = F_46 ( V_20 , sizeof( * V_59 ) ) ;
if ( ! V_19 ) {
F_9 ( V_20 , L_8 ) ;
V_44 = - V_114 ;
goto V_105;
}
if ( F_47 ( V_110 , L_9 , & V_113 ) ) {
F_9 ( V_20 , L_10 ) ;
V_44 = - V_115 ;
goto error;
}
V_19 -> V_116 = V_107 -> V_117 ;
V_19 -> V_20 . V_110 = V_110 ;
V_19 -> V_23 = V_118 ;
V_19 -> V_46 = V_113 ;
V_19 -> V_119 = F_48 ( 8 ) | F_48 ( 32 ) ;
V_19 -> V_120 = F_39 ;
V_19 -> V_121 = F_41 ;
V_19 -> V_122 = F_43 ;
V_19 -> V_123 = F_29 ;
V_19 -> V_124 = V_125 ;
V_19 -> V_23 |= ( V_126 | V_127 |
V_128 | V_129 ) ;
F_49 ( V_107 , V_19 ) ;
V_59 = F_20 ( V_19 ) ;
memset ( V_59 , 0 , sizeof( struct V_1 ) ) ;
V_59 -> V_19 = V_19 ;
V_59 -> V_72 = V_130 ;
V_59 -> V_73 = V_131 ;
V_59 -> V_80 = V_130 + V_131 +
V_132 ;
V_112 = F_50 ( V_107 , V_133 , 0 ) ;
V_59 -> V_3 = F_51 ( V_20 , V_112 ) ;
if ( F_52 ( V_59 -> V_3 ) ) {
V_44 = F_53 ( V_59 -> V_3 ) ;
goto error;
}
V_51 = F_54 ( V_107 , 0 ) ;
if ( V_51 < 0 ) {
F_9 ( V_20 , L_11 , V_51 ) ;
V_44 = - V_115 ;
goto error;
}
V_59 -> V_51 = V_51 ;
F_55 ( & V_59 -> V_56 ) ;
V_59 -> V_31 = F_56 ( V_20 , NULL ) ;
if ( F_52 ( V_59 -> V_31 ) ) {
F_9 ( V_20 , L_12 , F_53 ( V_59 -> V_31 ) ) ;
goto error;
}
V_44 = F_57 ( V_59 -> V_31 ) ;
if ( V_44 ) {
F_9 ( V_20 , L_13 , V_44 ) ;
goto error;
}
V_44 = F_18 ( V_59 ) ;
if ( V_44 )
goto V_134;
V_44 = F_58 ( V_20 , V_59 -> V_51 , F_19 , 0 ,
F_59 ( V_20 ) , V_19 ) ;
if ( V_44 ) {
F_9 ( V_20 , L_14 , V_44 ) ;
goto V_134;
}
V_44 = F_60 ( V_20 , V_19 ) ;
if ( V_44 ) {
F_9 ( V_20 , L_15 ) ;
goto V_134;
}
return 0 ;
V_134:
F_61 ( V_59 -> V_31 ) ;
error:
F_62 ( V_19 ) ;
V_105:
return V_44 ;
}
static int F_63 ( struct V_106 * V_107 )
{
struct V_42 * V_19 = F_64 ( V_107 ) ;
struct V_1 * V_59 = F_20 ( V_19 ) ;
F_65 ( V_59 -> V_31 ) ;
return 0 ;
}
