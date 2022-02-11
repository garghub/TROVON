static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_1 F_5 ( T_1 V_6 , T_1 V_7 )
{
return ( V_6 & V_8 ) | V_7 ;
}
static void T_2 * F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
if ( V_10 -> V_12 >= ( V_10 -> V_13 + 1 ) )
return V_2 -> V_14 + V_15 ;
return V_2 -> V_14 ;
}
static void F_7 ( struct V_9 * V_10 , T_3 V_16 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
unsigned int V_17 , V_18 , V_19 ;
T_1 V_20 = 0 ;
V_17 = V_10 -> V_12 ;
V_18 = F_8 ( V_16 ) ;
V_19 = F_9 ( V_16 ) ;
if ( ! F_10 ( V_10 ) )
V_20 = ( V_17 << 8 ) | ( V_18 << 3 ) | V_19 ;
F_3 ( V_2 , V_21 , V_20 ) ;
F_1 ( V_2 , V_21 ) ;
}
static bool F_11 ( struct V_9 * V_10 , int V_22 )
{
if ( F_10 ( V_10 ) && ( ( V_22 == V_23 ) ||
( V_22 == V_24 ) ) )
return true ;
return false ;
}
static void T_2 * F_12 ( struct V_9 * V_10 , unsigned int V_16 ,
int V_22 )
{
if ( ( F_10 ( V_10 ) && V_16 != 0 ) ||
F_11 ( V_10 , V_22 ) )
return NULL ;
F_7 ( V_10 , V_16 ) ;
return F_6 ( V_10 ) + V_22 ;
}
static int F_13 ( struct V_9 * V_10 , unsigned int V_16 ,
int V_25 , int V_26 , T_1 * V_5 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
if ( F_14 ( V_10 , V_16 , V_25 & ~ 0x3 , 4 , V_5 ) !=
V_27 )
return V_28 ;
if ( F_10 ( V_10 ) && ( V_2 -> V_29 == V_30 ) &&
( ( V_25 & ~ 0x3 ) == V_31 ) )
* V_5 &= ~ ( V_32 << 16 ) ;
if ( V_26 <= 2 )
* V_5 = ( * V_5 >> ( 8 * ( V_25 & 3 ) ) ) & ( ( 1 << ( V_26 * 8 ) ) - 1 ) ;
return V_27 ;
}
static T_4 F_15 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_7 , T_4 V_26 )
{
T_4 V_33 = ( ~ ( V_26 - 1 ) & V_8 ) | V_7 ;
T_1 V_34 = 0 ;
T_1 V_5 ;
V_34 = F_1 ( V_2 , V_6 ) ;
V_5 = ( V_34 & 0x0000ffff ) | ( F_16 ( V_33 ) << 16 ) ;
F_3 ( V_2 , V_6 , V_5 ) ;
V_34 = F_1 ( V_2 , V_6 + 0x04 ) ;
V_5 = ( V_34 & 0xffff0000 ) | ( F_16 ( V_33 ) >> 16 ) ;
F_3 ( V_2 , V_6 + 0x04 , V_5 ) ;
V_34 = F_1 ( V_2 , V_6 + 0x04 ) ;
V_5 = ( V_34 & 0x0000ffff ) | ( F_17 ( V_33 ) << 16 ) ;
F_3 ( V_2 , V_6 + 0x04 , V_5 ) ;
V_34 = F_1 ( V_2 , V_6 + 0x08 ) ;
V_5 = ( V_34 & 0xffff0000 ) | ( F_17 ( V_33 ) >> 16 ) ;
F_3 ( V_2 , V_6 + 0x08 , V_5 ) ;
return V_33 ;
}
static void F_18 ( struct V_1 * V_2 ,
T_1 * V_35 , T_1 * V_36 )
{
T_1 V_34 ;
V_2 -> V_37 = false ;
V_34 = F_1 ( V_2 , V_38 ) ;
if ( V_34 & V_39 ) {
V_2 -> V_37 = true ;
* V_36 = F_19 ( V_34 ) ;
V_34 = F_1 ( V_2 , V_40 ) ;
* V_35 = V_34 >> 26 ;
}
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
int V_43 ;
V_2 -> V_44 = F_21 ( V_42 , NULL ) ;
if ( F_22 ( V_2 -> V_44 ) ) {
F_23 ( V_42 , L_1 ) ;
return - V_45 ;
}
V_43 = F_24 ( V_2 -> V_44 ) ;
if ( V_43 ) {
F_23 ( V_42 , L_2 ) ;
return V_43 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
struct V_48 * V_49 ;
V_49 = F_26 ( V_47 , V_50 , L_3 ) ;
V_2 -> V_4 = F_27 ( V_42 , V_49 ) ;
if ( F_22 ( V_2 -> V_4 ) )
return F_28 ( V_2 -> V_4 ) ;
V_49 = F_26 ( V_47 , V_50 , L_4 ) ;
V_2 -> V_14 = F_27 ( V_42 , V_49 ) ;
if ( F_22 ( V_2 -> V_14 ) )
return F_28 ( V_2 -> V_14 ) ;
V_2 -> V_51 = V_49 -> V_52 ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_48 * V_49 , T_1 V_22 ,
T_4 V_53 , T_4 V_54 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
T_5 V_26 = F_30 ( V_49 ) ;
T_4 V_55 = F_31 ( V_49 ) ;
T_4 V_33 = 0 ;
T_1 V_56 ;
T_1 V_57 = V_58 ;
if ( V_55 == V_50 ) {
V_56 = V_59 ;
} else {
V_56 = 128 ;
V_57 |= V_60 ;
}
if ( V_26 >= V_56 )
V_33 = ~ ( V_26 - 1 ) | V_57 ;
else
F_32 ( V_42 , L_5 ,
( T_4 ) V_26 , V_56 ) ;
F_3 ( V_2 , V_22 , F_16 ( V_53 ) ) ;
F_3 ( V_2 , V_22 + 0x04 , F_17 ( V_53 ) ) ;
F_3 ( V_2 , V_22 + 0x08 , F_16 ( V_33 ) ) ;
F_3 ( V_2 , V_22 + 0x0c , F_17 ( V_33 ) ) ;
F_3 ( V_2 , V_22 + 0x10 , F_16 ( V_54 ) ) ;
F_3 ( V_2 , V_22 + 0x14 , F_17 ( V_54 ) ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_4 V_6 = V_2 -> V_51 ;
F_3 ( V_2 , V_61 , F_16 ( V_6 ) ) ;
F_3 ( V_2 , V_62 , F_17 ( V_6 ) ) ;
F_3 ( V_2 , V_63 , V_58 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_64 * V_49 ,
T_5 V_65 )
{
struct V_66 * V_67 ;
struct V_41 * V_42 = V_2 -> V_42 ;
int V_68 ;
F_35 (window, res) {
struct V_48 * V_49 = V_67 -> V_49 ;
T_4 V_55 = F_31 ( V_49 ) ;
F_36 ( V_42 , L_6 , V_49 ) ;
switch ( V_55 ) {
case V_69 :
F_29 ( V_2 , V_49 , V_70 , V_65 ,
V_49 -> V_52 - V_67 -> V_22 ) ;
V_68 = F_37 ( V_49 , V_65 ) ;
if ( V_68 < 0 )
return V_68 ;
break;
case V_50 :
if ( V_49 -> V_7 & V_71 )
F_29 ( V_2 , V_49 , V_72 ,
V_49 -> V_52 ,
V_49 -> V_52 -
V_67 -> V_22 ) ;
else
F_29 ( V_2 , V_49 , V_73 ,
V_49 -> V_52 ,
V_49 -> V_52 -
V_67 -> V_22 ) ;
break;
case V_74 :
break;
default:
F_23 ( V_42 , L_7 , V_49 ) ;
return - V_75 ;
}
}
F_33 ( V_2 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , T_1 V_76 ,
T_4 V_77 , T_4 V_26 )
{
F_3 ( V_2 , V_76 , F_16 ( V_77 ) ) ;
F_3 ( V_2 , V_76 + 0x04 ,
F_17 ( V_77 ) | V_78 ) ;
F_3 ( V_2 , V_76 + 0x10 , F_16 ( V_26 ) ) ;
F_3 ( V_2 , V_76 + 0x14 , F_17 ( V_26 ) ) ;
}
static int F_39 ( T_6 * V_79 , T_4 V_26 )
{
if ( ( V_26 > 4 ) && ( V_26 < V_80 ) && ! ( * V_79 & ( 1 << 1 ) ) ) {
* V_79 |= ( 1 << 1 ) ;
return 1 ;
}
if ( ( V_26 > V_81 ) && ( V_26 < V_82 ) && ! ( * V_79 & ( 1 << 0 ) ) ) {
* V_79 |= ( 1 << 0 ) ;
return 0 ;
}
if ( ( V_26 > V_83 ) && ( V_26 < V_82 ) && ! ( * V_79 & ( 1 << 2 ) ) ) {
* V_79 |= ( 1 << 2 ) ;
return 2 ;
}
return - V_75 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_84 * V_85 , T_6 * V_79 )
{
void T_2 * V_14 = V_2 -> V_14 ;
struct V_41 * V_42 = V_2 -> V_42 ;
void * V_86 ;
T_1 V_76 ;
T_4 V_53 = V_85 -> V_53 ;
T_4 V_54 = V_85 -> V_54 ;
T_4 V_26 = V_85 -> V_26 ;
T_4 V_33 = ~ ( V_26 - 1 ) | V_58 ;
T_1 V_7 = V_87 ;
T_1 V_88 ;
int V_89 ;
V_89 = F_39 ( V_79 , V_85 -> V_26 ) ;
if ( V_89 < 0 ) {
F_32 ( V_42 , L_8 ) ;
return;
}
if ( V_85 -> V_7 & V_71 )
V_7 |= V_90 ;
V_88 = F_5 ( ( T_1 ) V_53 , V_7 ) ;
switch ( V_89 ) {
case 0 :
F_15 ( V_2 , V_91 , V_7 , V_26 ) ;
V_86 = V_14 + V_23 ;
F_4 ( V_88 , V_86 ) ;
F_4 ( F_17 ( V_53 ) , V_86 + 0x4 ) ;
V_76 = V_92 ;
break;
case 1 :
F_3 ( V_2 , V_93 , V_88 ) ;
F_3 ( V_2 , V_94 , F_16 ( V_33 ) ) ;
V_76 = V_95 ;
break;
case 2 :
F_3 ( V_2 , V_96 , V_88 ) ;
F_3 ( V_2 , V_96 + 0x4 , F_17 ( V_53 ) ) ;
F_3 ( V_2 , V_97 , F_16 ( V_33 ) ) ;
F_3 ( V_2 , V_97 + 0x4 , F_17 ( V_33 ) ) ;
V_76 = V_98 ;
break;
}
F_38 ( V_2 , V_76 , V_54 , ~ ( V_26 - 1 ) ) ;
}
static int F_41 ( struct V_99 * V_100 ,
struct V_101 * V_102 )
{
const int V_103 = 3 , V_104 = 2 ;
int V_105 ;
V_100 -> V_102 = V_102 ;
V_100 -> V_106 = F_42 ( V_102 ) ;
V_100 -> V_107 = V_100 -> V_106 + V_103 + V_104 ;
V_100 -> V_85 = F_43 ( V_102 , L_9 , & V_105 ) ;
if ( ! V_100 -> V_85 )
return - V_108 ;
V_100 -> V_109 = V_100 -> V_85 + V_105 / sizeof( V_110 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_101 * V_107 = V_2 -> V_102 ;
struct V_84 V_85 ;
struct V_99 V_100 ;
struct V_41 * V_42 = V_2 -> V_42 ;
T_6 V_79 = 0 ;
if ( F_41 ( & V_100 , V_107 ) ) {
F_23 ( V_42 , L_10 ) ;
return - V_75 ;
}
F_45 (&parser, &range) {
T_4 V_109 = V_85 . V_53 + V_85 . V_26 - 1 ;
F_36 ( V_42 , L_11 ,
V_85 . V_7 , V_85 . V_53 , V_109 , V_85 . V_54 ) ;
F_40 ( V_2 , & V_85 , & V_79 ) ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_111 ;
for ( V_111 = V_92 ; V_111 <= V_63 ; V_111 += 4 )
F_3 ( V_2 , V_111 , 0 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_64 * V_49 ,
T_5 V_65 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
T_1 V_5 , V_35 = 0 , V_36 = 0 ;
int V_68 ;
F_46 ( V_2 ) ;
V_5 = ( V_112 << 16 ) | V_113 ;
F_3 ( V_2 , V_114 , V_5 ) ;
V_68 = F_34 ( V_2 , V_49 , V_65 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_44 ( V_2 ) ;
if ( V_68 )
return V_68 ;
F_18 ( V_2 , & V_35 , & V_36 ) ;
if ( ! V_2 -> V_37 )
F_48 ( V_42 , L_12 ) ;
else
F_48 ( V_42 , L_13 , V_35 , V_36 + 1 ) ;
return 0 ;
}
static int F_49 ( struct V_46 * V_47 )
{
struct V_41 * V_42 = & V_47 -> V_42 ;
struct V_101 * V_115 = V_42 -> V_116 ;
struct V_1 * V_2 ;
T_5 V_117 = 0 ;
struct V_9 * V_10 ;
int V_68 ;
F_50 ( V_49 ) ;
V_2 = F_51 ( V_42 , sizeof( * V_2 ) , V_118 ) ;
if ( ! V_2 )
return - V_119 ;
V_2 -> V_102 = F_52 ( V_115 ) ;
V_2 -> V_42 = V_42 ;
V_2 -> V_29 = V_120 ;
if ( F_53 ( V_2 -> V_102 , L_14 ) )
V_2 -> V_29 = V_30 ;
V_68 = F_25 ( V_2 , V_47 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_20 ( V_2 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_54 ( V_115 , 0 , 0xff , & V_49 , & V_117 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_55 ( V_42 , & V_49 ) ;
if ( V_68 )
goto error;
V_68 = F_47 ( V_2 , & V_49 , V_117 ) ;
if ( V_68 )
goto error;
V_10 = F_56 ( V_42 , 0 , & V_121 , V_2 , & V_49 ) ;
if ( ! V_10 ) {
V_68 = - V_119 ;
goto error;
}
F_57 ( V_10 ) ;
F_58 ( V_10 ) ;
F_59 ( V_10 ) ;
return 0 ;
error:
F_60 ( & V_49 ) ;
return V_68 ;
}
