static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_2 = ( void * ) V_1 ;
unsigned long V_3 ;
T_1 V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_3 ) ;
switch ( V_2 -> V_7 -> V_8 ) {
case V_9 :
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_5 & V_12 ) {
V_2 -> V_7 -> V_8 = V_13 ;
F_4 ( V_2 ) ;
} else {
V_2 -> V_7 -> V_8 = V_14 ;
F_5 ( V_2 ) ;
}
break;
case V_15 :
if ( V_2 -> V_16 & V_17 ) {
V_4 = F_3 ( V_2 -> V_10 , V_18 ) ;
V_4 &= ~ V_19 ;
F_6 ( V_2 -> V_20 , L_1 , V_4 ) ;
F_7 ( V_2 -> V_10 , V_18 , V_4 ) ;
V_2 -> V_21 = 1 ;
V_2 -> V_16 &= ~ ( V_22
| V_17 ) ;
V_2 -> V_16 |= V_23 << 16 ;
F_8 ( V_2 -> V_24 ) ;
V_2 -> V_7 -> V_8 = V_25 ;
}
break;
case V_25 :
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_5 & V_12 )
V_2 -> V_7 -> V_8 = V_13 ;
else
V_2 -> V_7 -> V_8 = V_9 ;
default:
break;
}
F_9 ( & V_2 -> V_6 , V_3 ) ;
}
static void F_10 ( struct V_2 * V_2 , unsigned long V_26 )
{
unsigned long V_27 = V_28 + F_11 ( 3 ) ;
static unsigned long V_29 ;
if ( V_26 == 0 )
V_26 = V_27 ;
if ( V_2 -> V_21 || ( ( V_2 -> V_30 == 0 )
&& ( V_2 -> V_7 -> V_8 == V_9 ) ) ) {
F_6 ( V_2 -> V_20 , L_2 ,
F_12 ( V_2 -> V_7 -> V_8 ) ) ;
F_13 ( & V_31 ) ;
V_29 = V_28 ;
return;
}
if ( F_14 ( V_29 , V_26 ) ) {
if ( ! F_15 ( & V_31 ) )
V_29 = V_26 ;
else {
F_6 ( V_2 -> V_20 , L_3 ) ;
return;
}
}
V_29 = V_26 ;
F_6 ( V_2 -> V_20 , L_4 ,
F_12 ( V_2 -> V_7 -> V_8 ) ,
( unsigned long ) F_16 ( V_26 - V_28 ) ) ;
F_17 ( & V_31 , V_26 ) ;
}
static void F_18 ( struct V_2 * V_2 , int V_32 )
{
struct V_33 * V_34 = V_2 -> V_7 -> V_34 ;
T_1 V_5 ;
unsigned long V_26 = V_28 + F_11 ( 1000 ) ;
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_32 ) {
if ( V_2 -> V_7 -> V_8 == V_14 ) {
int V_35 = 100 ;
V_5 |= V_36 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
while ( F_3 ( V_2 -> V_10 , V_11 ) & 0x80 ) {
F_19 ( 5 ) ;
F_20 () ;
if ( F_14 ( V_28 , V_26 )
|| V_35 -- <= 0 ) {
F_21 ( V_2 -> V_20 ,
L_5 ) ;
break;
}
}
F_22 ( V_34 , 1 ) ;
} else {
V_2 -> V_21 = 1 ;
V_34 -> V_37 = 1 ;
V_2 -> V_7 -> V_8 = V_38 ;
V_5 |= V_36 ;
F_5 ( V_2 ) ;
}
} else {
V_2 -> V_21 = 0 ;
V_34 -> V_37 = 0 ;
V_2 -> V_7 -> V_8 = V_13 ;
V_5 &= ~ V_36 ;
F_4 ( V_2 ) ;
}
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
F_6 ( V_2 -> V_20 , L_6
L_7 ,
F_12 ( V_2 -> V_7 -> V_8 ) ,
F_3 ( V_2 -> V_10 , V_11 ) ) ;
}
static int F_23 ( struct V_2 * V_2 , T_1 V_39 )
{
T_1 V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
V_5 |= V_36 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
return 0 ;
}
static inline void F_24 ( struct V_2 * V_2 )
{
T_2 V_40 ;
V_40 = F_25 ( V_2 -> V_10 , V_41 ) ;
V_40 |= V_42 ;
F_26 ( V_2 -> V_10 , V_41 , V_40 ) ;
}
static inline void F_27 ( struct V_2 * V_2 )
{
T_2 V_40 ;
V_40 = F_25 ( V_2 -> V_10 , V_41 ) ;
V_40 &= ~ V_42 ;
F_26 ( V_2 -> V_10 , V_41 , V_40 ) ;
}
void F_28 ( enum V_43 V_44 )
{
struct V_45 * V_46 = V_47 ;
if ( ! V_46 ) {
F_29 ( L_8 , V_48 ) ;
return;
}
V_46 -> V_44 = V_44 ;
if ( ! F_30 ( V_46 ) ) {
F_29 ( L_9 , V_48 ) ;
return;
}
F_31 ( & V_46 -> V_49 ) ;
}
static void F_32 ( struct V_45 * V_46 )
{
struct V_2 * V_2 = F_30 ( V_46 ) ;
struct V_50 * V_51 = V_2 -> V_20 ;
struct V_52 * V_53 = F_33 ( V_51 ) ;
struct V_54 * V_55 = V_53 -> V_56 ;
struct V_33 * V_34 = V_2 -> V_7 -> V_34 ;
switch ( V_46 -> V_44 ) {
case V_57 :
F_6 ( V_51 , L_10 ) ;
V_34 -> V_37 = true ;
V_2 -> V_7 -> V_8 = V_14 ;
V_2 -> V_7 -> V_58 = V_59 ;
if ( V_2 -> V_60 ) {
F_34 ( V_51 ) ;
F_35 ( V_46 -> V_61 ,
V_62 ) ;
F_18 ( V_2 , 1 ) ;
}
break;
case V_63 :
F_6 ( V_51 , L_11 ) ;
V_34 -> V_37 = false ;
V_2 -> V_7 -> V_8 = V_13 ;
V_2 -> V_7 -> V_58 = V_64 ;
if ( V_2 -> V_60 )
F_34 ( V_51 ) ;
F_35 ( V_46 -> V_61 , V_65 ) ;
break;
case V_66 :
case V_67 :
F_6 ( V_51 , L_12 ) ;
V_2 -> V_7 -> V_58 = V_68 ;
if ( V_2 -> V_60 ) {
F_18 ( V_2 , 0 ) ;
F_36 ( V_51 ) ;
F_37 ( V_51 ) ;
}
if ( V_55 -> V_69 == V_70 )
F_22 ( V_2 -> V_7 -> V_34 , 0 ) ;
F_35 ( V_46 -> V_61 ,
V_71 ) ;
break;
default:
F_6 ( V_51 , L_13 ) ;
}
F_38 ( & V_2 -> V_7 -> V_72 ,
V_2 -> V_7 -> V_58 , NULL ) ;
}
static void V_49 ( struct V_73 * V_74 )
{
struct V_45 * V_46 = F_39 ( V_74 ,
struct V_45 , V_49 ) ;
F_32 ( V_46 ) ;
}
static T_3 F_40 ( int V_75 , void * V_76 )
{
unsigned long V_3 ;
T_3 V_77 = V_78 ;
struct V_2 * V_2 = V_76 ;
F_2 ( & V_2 -> V_6 , V_3 ) ;
V_2 -> V_79 = F_3 ( V_2 -> V_10 , V_80 ) ;
V_2 -> V_81 = F_41 ( V_2 -> V_10 , V_82 ) ;
V_2 -> V_83 = F_41 ( V_2 -> V_10 , V_84 ) ;
if ( V_2 -> V_79 || V_2 -> V_81 || V_2 -> V_83 )
V_77 = F_42 ( V_2 ) ;
F_9 ( & V_2 -> V_6 , V_3 ) ;
return V_77 ;
}
static int F_43 ( struct V_2 * V_2 )
{
T_2 V_40 ;
int V_44 = 0 ;
struct V_50 * V_51 = V_2 -> V_20 ;
struct V_45 * V_46 = F_44 ( V_51 -> V_85 ) ;
struct V_52 * V_86 = F_33 ( V_51 ) ;
struct V_54 * V_55 = V_86 -> V_56 ;
if ( V_51 -> V_85 -> V_87 ) {
V_2 -> V_88 = F_45 ( V_51 -> V_85 , L_14 ) ;
V_2 -> V_7 = F_46 ( V_51 -> V_85 ,
L_15 , 0 ) ;
} else {
V_2 -> V_7 = F_47 ( V_51 , 0 ) ;
V_2 -> V_88 = F_45 ( V_51 , L_16 ) ;
}
if ( F_48 ( V_2 -> V_7 ) ) {
V_44 = F_49 ( V_2 -> V_7 ) ;
if ( V_44 == - V_89 )
return V_44 ;
F_29 ( L_17 ) ;
return - V_90 ;
}
if ( F_48 ( V_2 -> V_88 ) ) {
F_29 ( L_18 ) ;
return F_49 ( V_2 -> V_88 ) ;
}
V_2 -> V_91 = F_40 ;
V_44 = F_34 ( V_51 ) ;
if ( V_44 < 0 ) {
F_21 ( V_51 , L_19 , V_44 ) ;
goto V_92;
}
V_40 = F_25 ( V_2 -> V_10 , V_93 ) ;
if ( V_55 -> V_69 == V_70 ) {
V_40 &= ~ V_94 ;
V_40 |= V_95 ;
} else {
V_40 |= V_94 ;
}
F_26 ( V_2 -> V_10 , V_93 , V_40 ) ;
F_50 ( L_20
L_21 ,
F_25 ( V_2 -> V_10 , V_96 ) ,
F_25 ( V_2 -> V_10 , V_97 ) ,
F_25 ( V_2 -> V_10 , V_98 ) ,
F_25 ( V_2 -> V_10 , V_93 ) ,
F_25 ( V_2 -> V_10 , V_99 ) ) ;
F_51 ( & V_31 , F_1 , ( unsigned long ) V_2 ) ;
if ( V_46 -> V_44 != V_100 )
F_32 ( V_46 ) ;
F_52 ( V_2 -> V_88 ) ;
F_53 ( V_2 -> V_20 ) ;
return 0 ;
V_92:
return V_44 ;
}
static void F_54 ( struct V_2 * V_2 )
{
T_1 V_5 ;
unsigned long V_26 = V_28 + F_11 ( 1000 ) ;
struct V_50 * V_51 = V_2 -> V_20 ;
struct V_45 * V_46 = F_44 ( V_51 -> V_85 ) ;
struct V_52 * V_53 = F_33 ( V_51 ) ;
struct V_54 * V_55 = V_53 -> V_56 ;
switch ( V_46 -> V_44 ) {
case V_57 :
F_35 ( V_46 -> V_61 , V_62 ) ;
if ( V_55 -> V_69 != V_70 )
break;
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
V_5 |= V_36 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
while ( F_3 ( V_2 -> V_10 , V_11 ) &
V_12 ) {
F_20 () ;
if ( F_14 ( V_28 , V_26 ) ) {
F_21 ( V_51 , L_5 ) ;
break;
}
}
break;
case V_63 :
F_35 ( V_46 -> V_61 , V_65 ) ;
break;
default:
break;
}
}
static void F_55 ( struct V_2 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_20 ;
struct V_45 * V_46 = F_44 ( V_51 -> V_85 ) ;
if ( V_46 -> V_44 != V_100 )
F_35 ( V_46 -> V_61 ,
V_71 ) ;
}
static int F_56 ( struct V_2 * V_2 )
{
F_57 ( & V_31 ) ;
F_24 ( V_2 ) ;
F_58 ( V_2 -> V_88 ) ;
return 0 ;
}
static int F_59 ( struct V_101 * V_102 )
{
struct V_103 V_104 [ 3 ] ;
struct V_52 * V_53 = F_33 ( & V_102 -> V_51 ) ;
struct V_54 * V_55 ;
struct V_101 * V_2 ;
struct V_45 * V_46 ;
struct V_105 * V_106 = V_102 -> V_51 . V_87 ;
struct V_107 * V_108 ;
int V_109 = - V_110 ;
V_46 = F_60 ( & V_102 -> V_51 , sizeof( * V_46 ) , V_111 ) ;
if ( ! V_46 ) {
F_21 ( & V_102 -> V_51 , L_22 ) ;
goto V_112;
}
V_2 = F_61 ( L_23 , V_113 ) ;
if ( ! V_2 ) {
F_21 ( & V_102 -> V_51 , L_24 ) ;
goto V_112;
}
V_2 -> V_51 . V_85 = & V_102 -> V_51 ;
V_2 -> V_51 . V_114 = & V_115 ;
V_2 -> V_51 . V_116 = V_115 ;
V_46 -> V_51 = & V_102 -> V_51 ;
V_46 -> V_2 = V_2 ;
V_46 -> V_44 = V_100 ;
V_46 -> V_61 = F_62 ( - V_117 ) ;
if ( V_106 ) {
struct V_105 * V_118 ;
struct V_101 * V_119 ;
V_53 = F_60 ( & V_102 -> V_51 , sizeof( * V_53 ) , V_111 ) ;
if ( ! V_53 ) {
F_21 ( & V_102 -> V_51 ,
L_25 ) ;
goto V_120;
}
V_55 = F_60 ( & V_102 -> V_51 , sizeof( * V_55 ) , V_111 ) ;
if ( ! V_55 ) {
F_21 ( & V_102 -> V_51 ,
L_26 ) ;
goto V_120;
}
V_108 = F_60 ( & V_102 -> V_51 , sizeof( * V_108 ) , V_111 ) ;
if ( ! V_108 ) {
F_21 ( & V_102 -> V_51 ,
L_27 ) ;
goto V_120;
}
F_63 ( V_106 , L_28 , ( T_2 * ) & V_53 -> V_121 ) ;
F_63 ( V_106 , L_29 ,
( T_2 * ) & V_55 -> V_69 ) ;
F_63 ( V_106 , L_30 , ( T_2 * ) & V_108 -> V_122 ) ;
F_63 ( V_106 , L_31 , ( T_2 * ) & V_108 -> V_123 ) ;
F_63 ( V_106 , L_32 , ( T_2 * ) & V_53 -> V_4 ) ;
V_108 -> V_124 = F_64 ( V_106 , L_33 ) ;
V_53 -> V_56 = V_55 ;
V_53 -> V_108 = V_108 ;
V_118 = F_65 ( V_106 , L_34 , 0 ) ;
if ( V_118 ) {
V_119 = F_66 ( V_118 ) ;
if ( ! V_119 ) {
F_21 ( & V_102 -> V_51 , L_35 ) ;
V_109 = - V_125 ;
goto V_120;
}
V_46 -> V_61 = & V_119 -> V_51 ;
}
}
V_53 -> V_126 = & V_127 ;
F_67 ( V_102 , V_46 ) ;
V_47 = V_46 ;
F_68 ( & V_46 -> V_49 , V_49 ) ;
memset ( V_104 , 0x00 , sizeof( * V_104 ) *
F_69 ( V_104 ) ) ;
V_104 [ 0 ] . V_128 = V_102 -> V_103 [ 0 ] . V_128 ;
V_104 [ 0 ] . V_129 = V_102 -> V_103 [ 0 ] . V_129 ;
V_104 [ 0 ] . V_130 = V_102 -> V_103 [ 0 ] . V_130 ;
V_104 [ 0 ] . V_3 = V_102 -> V_103 [ 0 ] . V_3 ;
V_104 [ 1 ] . V_128 = V_102 -> V_103 [ 1 ] . V_128 ;
V_104 [ 1 ] . V_129 = V_102 -> V_103 [ 1 ] . V_129 ;
V_104 [ 1 ] . V_130 = V_102 -> V_103 [ 1 ] . V_130 ;
V_104 [ 1 ] . V_3 = V_102 -> V_103 [ 1 ] . V_3 ;
V_104 [ 2 ] . V_128 = V_102 -> V_103 [ 2 ] . V_128 ;
V_104 [ 2 ] . V_129 = V_102 -> V_103 [ 2 ] . V_129 ;
V_104 [ 2 ] . V_130 = V_102 -> V_103 [ 2 ] . V_130 ;
V_104 [ 2 ] . V_3 = V_102 -> V_103 [ 2 ] . V_3 ;
V_109 = F_70 ( V_2 , V_104 ,
F_69 ( V_104 ) ) ;
if ( V_109 ) {
F_21 ( & V_102 -> V_51 , L_36 ) ;
goto V_120;
}
V_109 = F_71 ( V_2 , V_53 , sizeof( * V_53 ) ) ;
if ( V_109 ) {
F_21 ( & V_102 -> V_51 , L_37 ) ;
goto V_120;
}
F_72 ( & V_102 -> V_51 ) ;
V_109 = F_73 ( V_2 ) ;
if ( V_109 ) {
F_21 ( & V_102 -> V_51 , L_38 ) ;
goto V_120;
}
return 0 ;
V_120:
F_74 ( V_2 ) ;
V_112:
return V_109 ;
}
static int F_75 ( struct V_101 * V_102 )
{
struct V_45 * V_46 = F_76 ( V_102 ) ;
F_77 ( & V_46 -> V_49 ) ;
F_78 ( V_46 -> V_2 ) ;
return 0 ;
}
static int F_79 ( struct V_50 * V_51 )
{
struct V_45 * V_46 = F_44 ( V_51 ) ;
struct V_2 * V_2 = F_30 ( V_46 ) ;
if ( V_2 ) {
V_2 -> V_131 . V_132 = F_25 ( V_2 -> V_10 ,
V_93 ) ;
F_24 ( V_2 ) ;
F_80 ( V_2 -> V_88 ) ;
}
return 0 ;
}
static int F_81 ( struct V_50 * V_51 )
{
struct V_45 * V_46 = F_44 ( V_51 ) ;
struct V_2 * V_2 = F_30 ( V_46 ) ;
if ( V_2 ) {
F_27 ( V_2 ) ;
F_26 ( V_2 -> V_10 , V_93 ,
V_2 -> V_131 . V_132 ) ;
F_82 ( V_2 -> V_88 ) ;
}
return 0 ;
}
static int T_4 F_83 ( void )
{
return F_84 ( & V_133 ) ;
}
static void T_5 F_85 ( void )
{
F_86 ( & V_133 ) ;
}
