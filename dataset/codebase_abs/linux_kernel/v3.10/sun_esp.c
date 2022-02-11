static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
V_1 -> V_4 = V_3 ;
V_1 -> V_5 = F_2 ( & V_3 -> V_6 [ 0 ] , 0 ,
F_3 ( & V_3 -> V_6 [ 0 ] ) ,
L_1 ) ;
if ( ! V_1 -> V_5 )
return - V_7 ;
switch ( F_4 ( V_8 ) & V_9 ) {
case V_10 :
V_1 -> V_11 = V_12 ;
break;
case V_13 :
V_1 -> V_11 = V_14 ;
break;
case V_15 :
V_1 -> V_11 = V_16 ;
break;
case V_17 :
V_1 -> V_11 = V_18 ;
break;
case V_19 :
V_1 -> V_11 = V_20 ;
break;
case V_21 :
V_1 -> V_11 = V_22 ;
break;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , int V_23 )
{
struct V_2 * V_24 = V_1 -> V_25 ;
struct V_6 * V_26 ;
if ( V_23 )
V_26 = & V_24 -> V_6 [ 1 ] ;
else
V_26 = & V_24 -> V_6 [ 0 ] ;
V_1 -> V_27 = F_2 ( V_26 , 0 , V_28 , L_2 ) ;
if ( ! V_1 -> V_27 )
return - V_7 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_24 = V_1 -> V_25 ;
V_1 -> V_29 = F_7 ( & V_24 -> V_25 , 16 ,
& V_1 -> V_30 ,
V_31 ) ;
if ( ! V_1 -> V_29 )
return - V_7 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_32 * V_33 = V_1 -> V_33 ;
struct V_2 * V_24 = V_1 -> V_25 ;
V_33 -> V_34 = V_24 -> V_35 . V_36 [ 0 ] ;
return F_9 ( V_33 -> V_34 , V_37 , V_38 , L_2 , V_1 ) ;
}
static void F_10 ( struct V_1 * V_1 , struct V_2 * V_39 )
{
struct V_2 * V_24 = V_1 -> V_25 ;
struct V_40 * V_41 ;
V_41 = V_24 -> V_25 . V_42 ;
V_1 -> V_43 = F_11 ( V_41 , L_3 , 0xff ) ;
if ( V_1 -> V_43 != 0xff )
goto V_44;
V_1 -> V_43 = F_11 ( V_41 , L_4 , 0xff ) ;
if ( V_1 -> V_43 != 0xff )
goto V_44;
V_1 -> V_43 = F_11 ( V_39 -> V_25 . V_42 ,
L_4 , 7 ) ;
V_44:
V_1 -> V_33 -> V_45 = V_1 -> V_43 ;
V_1 -> V_46 = ( 1 << V_1 -> V_43 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_24 = V_1 -> V_25 ;
struct V_40 * V_41 ;
V_41 = V_24 -> V_25 . V_42 ;
if ( F_13 ( V_41 , L_5 , NULL ) )
V_1 -> V_47 |= V_48 ;
else
V_1 -> V_47 &= ~ V_48 ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_2 * V_24 = V_1 -> V_25 ;
struct V_40 * V_49 , * V_41 ;
int V_50 ;
V_41 = V_24 -> V_25 . V_42 ;
V_49 = V_41 -> V_51 ;
V_50 = F_11 ( V_41 , L_6 , 0 ) ;
if ( V_50 == 0 )
V_50 = F_11 ( V_49 , L_6 , 0 ) ;
V_1 -> V_52 = V_50 ;
}
static void F_15 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_40 * V_53 = V_3 -> V_25 . V_42 ;
struct V_2 * V_24 = V_1 -> V_25 ;
struct V_40 * V_41 ;
T_1 V_54 , V_55 ;
V_41 = V_24 -> V_25 . V_42 ;
V_54 = F_11 ( V_41 , L_7 , 0xff ) ;
V_55 = F_11 ( V_53 , L_7 , 0xff ) ;
if ( V_55 != 0xff )
V_54 &= V_55 ;
V_55 = F_11 ( V_53 -> V_51 , L_7 , 0xff ) ;
if ( V_55 != 0xff )
V_54 &= V_55 ;
if ( V_54 == 0xff ||
( V_54 & V_56 ) == 0 ||
( V_54 & V_57 ) == 0 )
V_54 = ( V_57 - 1 ) ;
V_1 -> V_54 = V_54 ;
}
static void F_16 ( struct V_1 * V_1 , struct V_2 * V_39 )
{
F_10 ( V_1 , V_39 ) ;
F_12 ( V_1 ) ;
F_14 ( V_1 ) ;
F_15 ( V_1 , V_39 ) ;
}
static void F_17 ( struct V_1 * V_1 , T_1 V_55 , unsigned long V_58 )
{
F_18 ( V_55 , V_1 -> V_27 + ( V_58 * 4UL ) ) ;
}
static T_1 F_19 ( struct V_1 * V_1 , unsigned long V_58 )
{
return F_20 ( V_1 -> V_27 + ( V_58 * 4UL ) ) ;
}
static T_2 F_21 ( struct V_1 * V_1 , void * V_59 ,
T_3 V_60 , int V_61 )
{
struct V_2 * V_24 = V_1 -> V_25 ;
return F_22 ( & V_24 -> V_25 , V_59 , V_60 , V_61 ) ;
}
static int F_23 ( struct V_1 * V_1 , struct V_62 * V_63 ,
int V_64 , int V_61 )
{
struct V_2 * V_24 = V_1 -> V_25 ;
return F_24 ( & V_24 -> V_25 , V_63 , V_64 , V_61 ) ;
}
static void F_25 ( struct V_1 * V_1 , T_2 V_65 ,
T_3 V_60 , int V_61 )
{
struct V_2 * V_24 = V_1 -> V_25 ;
F_26 ( & V_24 -> V_25 , V_65 , V_60 , V_61 ) ;
}
static void F_27 ( struct V_1 * V_1 , struct V_62 * V_63 ,
int V_64 , int V_61 )
{
struct V_2 * V_24 = V_1 -> V_25 ;
F_28 ( & V_24 -> V_25 , V_63 , V_64 , V_61 ) ;
}
static int F_29 ( struct V_1 * V_1 )
{
if ( F_4 ( V_8 ) & ( V_66 | V_67 ) )
return 1 ;
return 0 ;
}
static void F_30 ( struct V_1 * V_1 )
{
int V_68 , V_69 , V_70 ;
int V_71 , V_72 ;
struct V_2 * V_24 ;
T_4 V_55 ;
V_68 = ( V_1 -> V_54 & V_56 ) != 0 ;
V_69 = ( V_1 -> V_54 & V_57 ) != 0 ;
V_70 = 0 ;
V_71 = 0 ;
V_24 = V_1 -> V_25 ;
if ( F_31 () )
V_71 = 1 ;
if ( F_32 () )
V_70 = ( V_1 -> V_54 & V_73 ) != 0 ;
if ( V_1 -> V_11 != V_20 ) {
V_55 = F_4 ( V_8 ) ;
F_33 ( V_55 | V_74 , V_8 ) ;
F_33 ( V_55 & ~ V_74 , V_8 ) ;
}
switch ( V_1 -> V_11 ) {
case V_20 :
F_33 ( V_75 , V_8 ) ;
F_33 ( V_74 , V_8 ) ;
V_1 -> V_76 = ( V_77 | V_78 |
V_79 | V_80 ) ;
V_1 -> V_76 &= ~ ( V_81 | V_82 |
V_83 ) ;
if ( V_70 )
V_1 -> V_76 |= V_84 ;
else if ( V_69 )
V_1 -> V_76 |= V_85 ;
if ( V_71 ) {
V_1 -> V_76 |= V_86 ;
F_34 ( & V_24 -> V_25 , V_1 -> V_54 ) ;
}
V_72 = 1000 ;
while ( F_4 ( V_8 ) & V_87 ) {
if ( -- V_72 == 0 ) {
F_35 (KERN_ALERT PFX L_8
L_9 ,
esp->host->unique_id) ;
break;
}
F_36 ( 1 ) ;
}
F_33 ( 0 , V_8 ) ;
F_33 ( V_1 -> V_76 , V_8 ) ;
F_33 ( 0 , V_88 ) ;
break;
case V_18 :
if ( V_1 -> V_89 != V_90 ) {
V_55 = F_4 ( V_8 ) ;
F_33 ( V_55 | V_91 , V_8 ) ;
}
break;
case V_92 :
V_55 = F_4 ( V_8 ) ;
V_55 &= ~ V_91 ;
V_55 |= V_78 ;
if ( V_69 ) {
V_55 &= ~ V_83 ;
V_55 |= V_85 ;
}
F_33 ( V_55 , V_8 ) ;
break;
case V_14 :
V_55 = F_4 ( V_8 ) ;
V_55 |= V_93 ;
V_55 &= ~ V_94 ;
if ( ! V_69 && V_68 ) {
V_55 |= V_95 ;
} else {
V_55 &= ~ ( V_95 ) ;
}
F_33 ( V_55 , V_8 ) ;
break;
default:
break;
}
V_55 = F_4 ( V_8 ) ;
F_33 ( V_55 | V_80 , V_8 ) ;
}
static void F_37 ( struct V_1 * V_1 )
{
T_4 V_96 ;
int V_72 ;
if ( V_1 -> V_11 == V_20 )
return;
V_96 = F_4 ( V_8 ) ;
if ( ! ( V_96 & V_97 ) )
return;
if ( V_1 -> V_11 != V_92 && V_1 -> V_11 != V_14 )
F_33 ( V_96 | V_98 , V_8 ) ;
V_72 = 1000 ;
while ( F_4 ( V_8 ) & V_97 ) {
if ( -- V_72 == 0 ) {
F_35 (KERN_ALERT PFX L_10 ,
esp->host->unique_id) ;
break;
}
F_36 ( 1 ) ;
}
}
static void F_38 ( struct V_1 * V_1 )
{
if ( V_1 -> V_11 == V_20 ) {
F_33 ( V_74 , V_8 ) ;
V_1 -> V_76 = ( ( V_1 -> V_76 |
( V_77 | V_78 |
V_79 | V_80 ) ) &
~ ( V_82 | V_81 ) ) ;
F_33 ( 0 , V_8 ) ;
F_33 ( V_1 -> V_76 , V_8 ) ;
F_33 ( 0 , V_88 ) ;
} else {
T_4 V_55 ;
int V_72 ;
V_72 = 1000 ;
while ( ( V_55 = F_4 ( V_8 ) ) & V_87 ) {
if ( -- V_72 == 0 ) {
F_35 (KERN_ALERT PFX L_11
L_12 , esp->host->unique_id) ;
break;
}
F_36 ( 1 ) ;
}
V_55 &= ~ ( V_81 | V_82 | V_94 ) ;
V_55 |= V_99 ;
F_33 ( V_55 , V_8 ) ;
V_55 &= ~ V_99 ;
F_33 ( V_55 , V_8 ) ;
}
}
static void F_39 ( struct V_1 * V_1 , T_4 V_65 , T_4 V_100 ,
T_4 V_101 , int V_102 , T_1 V_103 )
{
T_4 V_96 ;
F_40 ( ! ( V_103 & V_104 ) ) ;
F_17 ( V_1 , ( V_100 >> 0 ) & 0xff , V_105 ) ;
F_17 ( V_1 , ( V_100 >> 8 ) & 0xff , V_106 ) ;
if ( V_1 -> V_89 == V_107 ) {
F_17 ( V_1 , ( V_100 >> 16 ) & 0xff , V_108 ) ;
F_17 ( V_1 , 0 , V_109 ) ;
F_41 ( V_1 , V_103 ) ;
V_96 = V_1 -> V_76 ;
V_96 |= V_79 | V_81 ;
if ( V_102 )
V_96 |= V_82 ;
else
V_96 &= ~ V_82 ;
V_1 -> V_76 = V_96 ;
F_33 ( V_101 , V_110 ) ;
F_33 ( V_65 , V_88 ) ;
F_33 ( V_96 , V_8 ) ;
} else {
V_96 = F_4 ( V_8 ) ;
V_96 |= V_81 ;
if ( V_102 )
V_96 |= V_82 ;
else
V_96 &= ~ V_82 ;
F_33 ( V_96 , V_8 ) ;
if ( V_1 -> V_11 == V_14 ) {
T_4 V_111 = F_42 ( V_65 + V_101 + 16U ) ;
F_33 ( V_111 - V_65 , V_110 ) ;
}
F_33 ( V_65 , V_88 ) ;
F_41 ( V_1 , V_103 ) ;
}
}
static int F_43 ( struct V_1 * V_1 )
{
T_4 V_96 = F_4 ( V_8 ) ;
if ( V_96 & V_67 )
return 1 ;
return 0 ;
}
static int F_44 ( struct V_2 * V_24 ,
struct V_2 * V_39 , int V_23 )
{
struct V_112 * V_113 = & V_114 ;
struct V_32 * V_33 ;
struct V_1 * V_1 ;
int V_115 ;
V_33 = F_45 ( V_113 , sizeof( struct V_1 ) ) ;
V_115 = - V_7 ;
if ( ! V_33 )
goto V_116;
V_33 -> V_117 = ( V_23 ? 16 : 8 ) ;
V_1 = F_46 ( V_33 ) ;
V_1 -> V_33 = V_33 ;
V_1 -> V_25 = V_24 ;
V_1 -> V_118 = & V_119 ;
if ( V_23 )
V_1 -> V_47 |= V_120 ;
V_115 = F_1 ( V_1 , V_39 ) ;
if ( V_115 < 0 )
goto V_121;
V_115 = F_5 ( V_1 , V_23 ) ;
if ( V_115 < 0 )
goto V_121;
V_115 = F_6 ( V_1 ) ;
if ( V_115 < 0 )
goto V_122;
V_115 = F_8 ( V_1 ) ;
if ( V_115 < 0 )
goto V_123;
F_16 ( V_1 , V_39 ) ;
if ( V_1 -> V_11 == V_14 ) {
T_4 V_55 = F_4 ( V_8 ) ;
F_33 ( V_55 & ~ V_74 , V_8 ) ;
}
F_47 ( & V_24 -> V_25 , V_1 ) ;
V_115 = F_48 ( V_1 , & V_24 -> V_25 ) ;
if ( V_115 )
goto V_124;
return 0 ;
V_124:
F_49 ( V_33 -> V_34 , V_1 ) ;
V_123:
F_50 ( & V_24 -> V_25 , 16 ,
V_1 -> V_29 ,
V_1 -> V_30 ) ;
V_122:
F_51 ( & V_24 -> V_6 [ ( V_23 ? 1 : 0 ) ] , V_1 -> V_27 , V_28 ) ;
V_121:
F_52 ( V_33 ) ;
V_116:
return V_115 ;
}
static int F_53 ( struct V_2 * V_24 )
{
struct V_40 * V_125 = NULL ;
struct V_40 * V_41 = V_24 -> V_25 . V_42 ;
struct V_2 * V_3 = NULL ;
int V_23 = 0 ;
if ( V_41 -> V_51 &&
( ! strcmp ( V_41 -> V_51 -> V_126 , L_1 ) ||
! strcmp ( V_41 -> V_51 -> V_126 , L_13 ) ) )
V_125 = V_41 -> V_51 ;
else if ( ! strcmp ( V_41 -> V_126 , L_14 ) ) {
V_125 = V_24 -> V_25 . V_42 ;
V_23 = 1 ;
}
if ( V_125 )
V_3 = F_54 ( V_125 ) ;
if ( ! V_3 )
return - V_127 ;
return F_44 ( V_24 , V_3 , V_23 ) ;
}
static int F_55 ( struct V_2 * V_24 )
{
struct V_1 * V_1 = F_56 ( & V_24 -> V_25 ) ;
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned int V_34 = V_1 -> V_33 -> V_34 ;
bool V_128 ;
T_4 V_55 ;
F_57 ( V_1 ) ;
V_55 = F_4 ( V_8 ) ;
F_33 ( V_55 & ~ V_80 , V_8 ) ;
F_49 ( V_34 , V_1 ) ;
V_128 = ( V_1 -> V_11 == V_20 ) ;
F_50 ( & V_24 -> V_25 , 16 ,
V_1 -> V_29 ,
V_1 -> V_30 ) ;
F_51 ( & V_24 -> V_6 [ ( V_128 ? 1 : 0 ) ] , V_1 -> V_27 ,
V_28 ) ;
F_51 ( & V_3 -> V_6 [ 0 ] , V_1 -> V_5 ,
F_3 ( & V_3 -> V_6 [ 0 ] ) ) ;
F_52 ( V_1 -> V_33 ) ;
F_47 ( & V_24 -> V_25 , NULL ) ;
return 0 ;
}
static int T_5 F_58 ( void )
{
return F_59 ( & V_129 ) ;
}
static void T_6 F_60 ( void )
{
F_61 ( & V_129 ) ;
}
