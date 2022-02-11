static T_1 F_1 ( T_2 V_1 )
{
return F_2 ( V_2 ) + ( V_1 * 8 ) ;
}
static T_2 F_3 ( const void T_3 * V_3 , unsigned V_4 )
{
return ( T_2 ) ( F_4 ( V_3 + V_4 ) ) ;
}
static T_4 F_5 ( const void T_3 * V_3 , unsigned V_4 )
{
return F_4 ( V_3 + V_4 ) ;
}
static T_1 F_6 ( const void T_3 * V_3 , unsigned V_4 )
{
return ( T_1 ) ( F_4 ( V_3 + V_4 ) ) ;
}
static void F_7 ( void T_3 * V_3 , unsigned V_4 , T_2 V_5 )
{
F_8 ( V_3 + V_4 , ( T_4 ) V_5 ) ;
}
static void F_9 ( void T_3 * V_3 , unsigned V_4 , T_4 V_5 )
{
F_8 ( V_3 + V_4 , V_5 ) ;
}
static void F_10 ( void T_3 * V_3 , unsigned V_4 , T_1 V_5 )
{
F_8 ( V_3 + V_4 , ( T_4 ) V_5 ) ;
}
static void F_11 ( struct V_6 * V_7 , T_4 V_8 , const T_2 * V_9 )
{
struct V_10 * V_10 = V_7 -> V_10 ;
void T_3 * V_11 = V_7 -> V_11 ;
void T_3 * V_12 = V_7 -> V_13 ;
T_2 V_1 = V_7 -> V_1 ;
F_12 ( ( T_2 * ) V_9 ) ;
F_13 ( V_12 , V_14 , V_8 ) ;
F_14 ( V_10 -> V_15 , L_1 ,
V_7 -> V_1 , V_11 , V_8 , V_9 , V_12 ) ;
F_15 ( V_9 , V_8 ) ;
if ( ! V_16 && V_1 != 0 ) {
T_4 V_17 ;
F_16 ( ( unsigned long ) V_9 ,
( unsigned long ) ( V_9 + V_8 ) ) ;
V_17 = ( T_1 ) V_9 ;
F_8 ( F_17 ( V_1 , V_18 ) , V_17 ) ;
F_18 () ;
V_17 = ( T_1 ) V_9 >> 16 ;
F_8 ( F_17 ( V_1 , V_19 ) , V_17 ) ;
F_18 () ;
F_8 ( F_17 ( V_1 , V_20 ) , V_8 ) ;
F_8 ( F_17 ( V_1 , V_21 ) , 0 ) ;
F_18 () ;
V_17 = ( V_1 << 4 ) | V_22 | V_23 | V_24 ;
F_8 ( F_17 ( V_1 , V_25 ) , V_17 ) ;
F_18 () ;
while ( ! ( F_19 () & ( 1 << V_1 ) ) )
F_20 () ;
F_21 ( 1 << V_1 ) ;
F_18 () ;
F_8 ( F_17 ( V_1 , V_25 ) , 0 ) ;
F_18 () ;
} else {
F_18 () ;
if ( F_22 ( ( unsigned long ) V_9 & 0x01 ) )
F_23 ( ( unsigned long ) V_11 , V_9 , ( V_8 + 1 ) >> 1 ) ;
else
F_24 ( ( unsigned long ) V_11 , V_9 , ( V_8 + 1 ) >> 1 ) ;
}
}
static void F_25 ( struct V_6 * V_7 , T_4 V_8 , T_2 * V_26 )
{
struct V_10 * V_10 = V_7 -> V_10 ;
void T_3 * V_11 = V_7 -> V_11 ;
T_2 V_1 = V_7 -> V_1 ;
if ( V_27 && V_1 != 0 ) {
T_4 V_17 ;
F_26 ( ( unsigned long ) V_26 ,
( unsigned long ) ( V_26 + V_8 ) ) ;
V_17 = ( T_1 ) V_26 ;
F_8 ( F_17 ( V_1 , V_18 ) , V_17 ) ;
F_18 () ;
V_17 = ( T_1 ) V_26 >> 16 ;
F_8 ( F_17 ( V_1 , V_19 ) , V_17 ) ;
F_18 () ;
F_8 ( F_17 ( V_1 , V_20 ) , V_8 ) ;
F_8 ( F_17 ( V_1 , V_21 ) , 0 ) ;
F_18 () ;
V_17 = ( V_1 << 4 ) | V_22 | V_23 ;
F_8 ( F_17 ( V_1 , V_25 ) , V_17 ) ;
F_18 () ;
while ( ! ( F_19 () & ( 1 << V_1 ) ) )
F_20 () ;
F_21 ( 1 << V_1 ) ;
F_18 () ;
F_8 ( F_17 ( V_1 , V_25 ) , 0 ) ;
F_18 () ;
} else {
F_18 () ;
if ( V_8 == 1 )
* V_26 = ( T_2 ) F_27 ( ( unsigned long ) V_11 + 4 ) ;
else {
if ( F_22 ( ( unsigned long ) V_26 & 0x01 ) )
F_28 ( ( unsigned long ) V_11 , V_26 , V_8 >> 1 ) ;
else
F_29 ( ( unsigned long ) V_11 , V_26 , V_8 >> 1 ) ;
if ( V_8 & 0x01 )
* ( V_26 + V_8 - 1 ) = ( T_2 ) F_27 ( ( unsigned long ) V_11 + 4 ) ;
}
}
F_14 ( V_10 -> V_15 , L_2 ,
'R' , V_7 -> V_1 , V_11 , V_8 , V_26 ) ;
F_15 ( V_26 , V_8 ) ;
}
static T_5 F_30 ( int V_28 , void * V_29 )
{
unsigned long V_30 ;
T_5 V_31 = V_32 ;
struct V_10 * V_10 = V_29 ;
F_31 ( & V_10 -> V_33 , V_30 ) ;
V_10 -> V_34 = F_32 ( V_10 -> V_35 , V_36 ) ;
V_10 -> V_37 = F_33 ( V_10 -> V_35 , V_38 ) ;
V_10 -> V_39 = F_33 ( V_10 -> V_35 , V_40 ) ;
if ( V_10 -> V_34 || V_10 -> V_37 || V_10 -> V_39 ) {
F_34 ( V_10 -> V_35 , V_36 , V_10 -> V_34 ) ;
F_13 ( V_10 -> V_35 , V_38 , V_10 -> V_37 ) ;
F_13 ( V_10 -> V_35 , V_40 , V_10 -> V_39 ) ;
V_31 = F_35 ( V_10 ) ;
}
if ( ( V_10 -> V_41 -> V_42 -> V_43 == V_44
|| V_10 -> V_41 -> V_42 -> V_43 == V_45 ) ||
( V_10 -> V_34 & V_46 && F_36 ( V_10 ) ) ) {
F_37 ( & V_47 , V_48 + V_49 ) ;
V_10 -> V_50 = V_49 ;
}
F_38 ( & V_10 -> V_33 , V_30 ) ;
return V_31 ;
}
static void F_39 ( unsigned long V_51 )
{
struct V_10 * V_10 = ( void * ) V_51 ;
unsigned long V_30 ;
T_4 V_52 ;
static T_2 V_53 ;
F_31 ( & V_10 -> V_33 , V_30 ) ;
switch ( V_10 -> V_41 -> V_42 -> V_43 ) {
case V_54 :
case V_45 :
V_52 = F_33 ( V_10 -> V_35 , V_55 ) ;
V_52 &= ~ V_56 ;
F_13 ( V_10 -> V_35 , V_55 , V_52 ) ;
V_52 |= V_56 ;
F_13 ( V_10 -> V_35 , V_55 , V_52 ) ;
V_52 = F_33 ( V_10 -> V_35 , V_55 ) ;
if ( ! ( V_52 & V_57 ) ) {
F_40 ( V_10 -> V_58 -> V_59 , 1 ) ;
V_10 -> V_41 -> V_42 -> V_43 = V_45 ;
} else {
F_40 ( V_10 -> V_58 -> V_59 , 0 ) ;
V_52 = F_32 ( V_10 -> V_35 , V_60 ) ;
V_52 &= ~ V_61 ;
F_34 ( V_10 -> V_35 , V_60 , V_52 ) ;
V_52 = V_62 | V_61 ;
F_34 ( V_10 -> V_35 , V_36 , V_52 ) ;
V_10 -> V_41 -> V_42 -> V_43 = V_44 ;
}
F_37 ( & V_47 , V_48 + V_49 ) ;
break;
case V_44 :
V_52 = F_33 ( V_10 -> V_35 , V_55 ) ;
V_52 |= V_56 ;
F_13 ( V_10 -> V_35 , V_55 , V_52 ) ;
V_52 = F_33 ( V_10 -> V_35 , V_55 ) ;
if ( ! ( V_52 & V_57 ) ) {
F_40 ( V_10 -> V_58 -> V_59 , 1 ) ;
V_10 -> V_41 -> V_42 -> V_43 = V_45 ;
} else {
F_40 ( V_10 -> V_58 -> V_59 , 0 ) ;
V_52 = F_32 ( V_10 -> V_35 , V_60 ) ;
V_52 &= ~ V_61 ;
F_34 ( V_10 -> V_35 , V_60 , V_52 ) ;
V_52 = V_62 | V_61 ;
F_34 ( V_10 -> V_35 , V_36 , V_52 ) ;
if ( V_53 ) {
V_52 = F_32 ( V_10 -> V_35 , V_63 ) ;
V_52 &= ~ V_64 ;
F_34 ( V_10 -> V_35 , V_63 , V_52 ) ;
V_53 = 0 ;
} else {
V_52 = F_32 ( V_10 -> V_35 , V_63 ) ;
V_52 |= V_64 ;
F_34 ( V_10 -> V_35 , V_63 , V_52 ) ;
V_53 = 1 ;
}
F_37 ( & V_47 , V_48 + V_49 / 4 ) ;
}
break;
default:
F_14 ( V_10 -> V_15 , L_3 ,
F_41 ( V_10 -> V_41 -> V_42 -> V_43 ) ) ;
break;
}
F_38 ( & V_10 -> V_33 , V_30 ) ;
F_14 ( V_10 -> V_15 , L_4 ,
F_41 ( V_10 -> V_41 -> V_42 -> V_43 ) ) ;
}
static void F_42 ( struct V_10 * V_10 )
{
}
static void F_43 ( struct V_10 * V_10 )
{
}
static void F_44 ( struct V_10 * V_10 , int V_65 )
{
int V_66 = V_10 -> V_58 -> V_67 ;
if ( ! V_65 )
V_66 = ! V_66 ;
F_40 ( V_10 -> V_58 -> V_59 , V_66 ) ;
F_14 ( V_10 -> V_15 , L_5
L_6 ,
F_41 ( V_10 -> V_41 -> V_42 -> V_43 ) ,
F_32 ( V_10 -> V_35 , V_55 ) ) ;
}
static int F_45 ( struct V_68 * V_69 , unsigned V_70 )
{
return 0 ;
}
static int F_46 ( struct V_10 * V_10 )
{
return 0 ;
}
static int F_47 ( struct V_10 * V_10 , T_2 V_71 )
{
return - V_72 ;
}
static int F_48 ( struct V_73 * V_74 ,
T_4 V_75 , T_2 * V_76 ,
T_6 * V_77 , T_1 * V_8 )
{
struct V_78 * V_79 = V_74 -> V_80 ;
if ( V_81 ) {
if ( V_79 -> V_82 && * V_76 == 1 )
* V_8 = * V_8 - ( * V_8 % V_75 ) ;
}
return 0 ;
}
static void F_49 ( struct V_10 * V_10 )
{
if ( V_83 ) {
F_50 ( V_84 ) ;
F_18 () ;
}
if ( V_85 ) {
F_51 ( 0x0 ) ;
F_18 () ;
}
F_52 ( 0x3080 |
( ( 480 / V_10 -> V_58 -> V_86 ) << 1 ) ) ;
F_18 () ;
F_53 ( ( F_54 () / 1000 ) / 32 - 1 ) ;
F_18 () ;
F_55 ( 64 ) ;
F_18 () ;
F_56 ( 64 ) ;
F_18 () ;
F_57 ( 0x7 ) ;
F_18 () ;
F_58 ( V_87 | V_88 | V_89 |
V_90 | V_91 | V_92 |
V_93 | V_94 | V_95 |
V_96 | V_97 | V_98 |
V_99 | V_100 | V_101 ) ;
F_18 () ;
}
static int F_59 ( struct V_10 * V_10 )
{
if ( F_60 ( V_10 -> V_58 -> V_59 , L_7 ) ) {
F_61 ( V_102 L_8 ,
V_10 -> V_58 -> V_59 ) ;
return - V_103 ;
}
F_62 ( V_10 -> V_58 -> V_59 , 0 ) ;
V_10 -> V_41 = F_63 ( V_104 ) ;
if ( F_64 ( V_10 -> V_41 ) ) {
F_65 ( V_10 -> V_58 -> V_59 ) ;
return - V_105 ;
}
F_49 ( V_10 ) ;
F_66 ( & V_47 , F_39 ,
( unsigned long ) V_10 ) ;
V_10 -> V_41 -> V_106 = F_45 ;
V_10 -> V_107 = F_30 ;
V_10 -> V_108 = true ;
return 0 ;
}
static int F_67 ( struct V_10 * V_10 )
{
F_65 ( V_10 -> V_58 -> V_59 ) ;
F_68 ( V_10 -> V_41 ) ;
return 0 ;
}
static int F_69 ( struct V_109 * V_110 )
{
struct V_111 V_112 [ 2 ] ;
struct V_113 * V_114 = F_70 ( & V_110 -> V_115 ) ;
struct V_109 * V_10 ;
struct V_116 * V_117 ;
int V_118 = - V_119 ;
V_117 = F_71 ( & V_110 -> V_115 , sizeof( * V_117 ) , V_120 ) ;
if ( ! V_117 )
goto V_121;
V_10 = F_72 ( L_9 , V_122 ) ;
if ( ! V_10 )
goto V_121;
V_10 -> V_115 . V_123 = & V_110 -> V_115 ;
V_10 -> V_115 . V_124 = & V_125 ;
V_10 -> V_115 . V_126 = V_125 ;
V_117 -> V_115 = & V_110 -> V_115 ;
V_117 -> V_10 = V_10 ;
V_114 -> V_127 = & V_128 ;
V_117 -> V_129 = F_73 () ;
if ( F_74 ( V_117 -> V_129 ) )
goto V_130;
F_75 ( V_110 , V_117 ) ;
memset ( V_112 , 0x00 , sizeof( * V_112 ) *
F_76 ( V_112 ) ) ;
V_112 [ 0 ] . V_131 = V_110 -> V_111 [ 0 ] . V_131 ;
V_112 [ 0 ] . V_132 = V_110 -> V_111 [ 0 ] . V_132 ;
V_112 [ 0 ] . V_133 = V_110 -> V_111 [ 0 ] . V_133 ;
V_112 [ 0 ] . V_30 = V_110 -> V_111 [ 0 ] . V_30 ;
V_112 [ 1 ] . V_131 = V_110 -> V_111 [ 1 ] . V_131 ;
V_112 [ 1 ] . V_132 = V_110 -> V_111 [ 1 ] . V_132 ;
V_112 [ 1 ] . V_133 = V_110 -> V_111 [ 1 ] . V_133 ;
V_112 [ 1 ] . V_30 = V_110 -> V_111 [ 1 ] . V_30 ;
V_118 = F_77 ( V_10 , V_112 ,
F_76 ( V_112 ) ) ;
if ( V_118 ) {
F_78 ( & V_110 -> V_115 , L_10 ) ;
goto V_134;
}
V_118 = F_79 ( V_10 , V_114 , sizeof( * V_114 ) ) ;
if ( V_118 ) {
F_78 ( & V_110 -> V_115 , L_11 ) ;
goto V_134;
}
V_118 = F_80 ( V_10 ) ;
if ( V_118 ) {
F_78 ( & V_110 -> V_115 , L_12 ) ;
goto V_134;
}
return 0 ;
V_134:
F_81 ( V_117 -> V_129 ) ;
V_130:
F_82 ( V_10 ) ;
V_121:
return V_118 ;
}
static int F_83 ( struct V_109 * V_110 )
{
struct V_116 * V_117 = F_84 ( V_110 ) ;
F_85 ( V_117 -> V_10 ) ;
F_81 ( V_117 -> V_129 ) ;
return 0 ;
}
static int F_86 ( struct V_135 * V_115 )
{
struct V_116 * V_117 = F_87 ( V_115 ) ;
struct V_10 * V_10 = F_88 ( V_117 ) ;
if ( F_36 ( V_10 ) )
F_40 ( V_10 -> V_58 -> V_59 , 0 ) ;
return 0 ;
}
static int F_89 ( struct V_135 * V_115 )
{
struct V_116 * V_117 = F_87 ( V_115 ) ;
struct V_10 * V_10 = F_88 ( V_117 ) ;
F_49 ( V_10 ) ;
return 0 ;
}
