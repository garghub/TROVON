static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
bool V_5 , V_6 ;
if ( ! F_3 ( V_7 , & V_4 -> V_8 ) )
return;
if ( F_4 ( V_9 , & V_4 -> V_8 ) ) {
struct V_10 * V_10 = V_4 -> V_10 ;
unsigned long V_8 ;
T_1 V_11 ;
F_5 ( & V_10 -> V_12 , V_8 ) ;
V_11 = F_6 ( V_10 -> V_13 + V_14 ) ;
if ( F_3 ( V_15 , & V_4 -> V_8 ) ) {
F_7 ( V_16 , & V_4 -> V_8 ) ;
V_10 -> V_17 -> V_18 -> V_19 = 1 ;
V_10 -> V_17 -> V_18 -> V_20 = V_21 ;
F_8 ( V_10 ) ;
V_11 |= V_22 ;
} else {
F_9 ( V_16 , & V_4 -> V_8 ) ;
V_10 -> V_17 -> V_18 -> V_19 = 0 ;
V_10 -> V_17 -> V_18 -> V_20 = V_23 ;
F_10 ( V_10 ) ;
V_11 &= ~ V_22 ;
}
F_11 ( V_11 , V_10 -> V_13 + V_14 ) ;
F_12 ( & V_10 -> V_12 , V_8 ) ;
}
V_5 = F_3 ( V_16 , & V_4 -> V_8 ) ;
V_6 = F_3 ( V_24 , & V_4 -> V_8 ) ;
if ( V_6 != V_5 ) {
if ( V_5 ) {
F_13 ( V_4 -> V_25 ) ;
F_7 ( V_24 , & V_4 -> V_8 ) ;
} else {
F_14 ( V_4 -> V_25 ) ;
F_9 ( V_24 , & V_4 -> V_8 ) ;
}
}
if ( F_4 ( V_26 , & V_4 -> V_8 ) )
F_15 ( V_4 -> V_25 , V_4 -> V_27 ) ;
}
static void F_16 ( struct V_10 * V_10 , int V_28 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_29 -> V_30 ) ;
if ( V_28 ) {
F_7 ( V_16 , & V_4 -> V_8 ) ;
V_10 -> V_17 -> V_18 -> V_20 = V_21 ;
} else {
F_9 ( V_16 , & V_4 -> V_8 ) ;
}
F_18 ( & V_4 -> V_2 ) ;
}
static void F_19 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_29 -> V_30 ) ;
F_20 ( V_4 -> V_25 , false ) ;
}
static void F_21 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_29 -> V_30 ) ;
F_20 ( V_4 -> V_25 , true ) ;
}
static T_2 F_22 ( int V_31 , void * V_32 )
{
struct V_10 * V_10 = V_32 ;
unsigned long V_8 ;
F_5 ( & V_10 -> V_12 , V_8 ) ;
V_10 -> V_33 = F_6 ( V_10 -> V_13 + V_34 ) ;
if ( V_10 -> V_33 )
F_11 ( V_10 -> V_33 , V_10 -> V_13 + V_34 ) ;
if ( ( V_10 -> V_33 & V_35 ) && ! F_23 ( V_10 ) ) {
F_24 ( V_10 -> V_13 , 0 ) ;
F_25 ( V_10 -> V_13 , V_36 , 0 ) ;
}
V_10 -> V_37 = F_26 ( V_10 -> V_13 + V_38 ) ;
if ( V_10 -> V_37 )
F_27 ( V_10 -> V_37 , V_10 -> V_13 + V_38 ) ;
V_10 -> V_39 = F_26 ( V_10 -> V_13 + V_40 ) ;
if ( V_10 -> V_39 )
F_27 ( V_10 -> V_39 , V_10 -> V_13 + V_40 ) ;
F_28 ( V_10 ) ;
F_12 ( & V_10 -> V_12 , V_8 ) ;
return V_41 ;
}
static int F_29 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
struct V_3 * V_4 = F_2 ( V_43 , struct V_3 , V_46 ) ;
if ( V_44 )
F_7 ( V_15 , & V_4 -> V_8 ) ;
else
F_9 ( V_15 , & V_4 -> V_8 ) ;
F_7 ( V_9 , & V_4 -> V_8 ) ;
F_18 ( & V_4 -> V_2 ) ;
return V_47 ;
}
static int F_30 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_29 -> V_30 ) ;
int V_48 ;
V_49 = V_10 ;
V_10 -> V_25 = V_4 -> V_25 ;
V_10 -> V_17 = V_4 -> V_17 ;
if ( F_3 ( V_50 , & V_4 -> V_8 ) ) {
V_48 = F_31 ( V_10 -> V_29 -> V_30 ) ;
if ( V_48 )
return V_48 ;
}
V_48 = F_32 ( V_4 -> V_51 ) ;
if ( V_48 )
goto V_52;
if ( F_3 ( V_53 , & V_4 -> V_8 ) ) {
V_48 = F_33 ( V_4 -> V_54 ) ;
if ( V_48 )
goto V_55;
}
F_11 ( V_56 , V_10 -> V_13 + V_57 ) ;
V_48 = F_34 ( V_4 -> V_58 , V_4 -> V_59 ,
V_60 , & V_4 -> V_46 ) ;
if ( V_48 )
goto V_61;
V_48 = F_35 ( V_4 -> V_25 ) ;
if ( V_48 )
goto V_61;
V_10 -> V_62 = F_22 ;
F_36 ( V_10 -> V_29 ) ;
return 0 ;
V_61:
if ( F_3 ( V_53 , & V_4 -> V_8 ) )
F_37 ( V_4 -> V_54 ) ;
V_55:
F_38 ( V_4 -> V_51 ) ;
V_52:
if ( F_3 ( V_50 , & V_4 -> V_8 ) )
F_39 ( V_10 -> V_29 -> V_30 ) ;
return V_48 ;
}
static int F_40 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_29 -> V_30 ) ;
F_41 ( V_10 -> V_29 ) ;
F_42 ( & V_4 -> V_2 ) ;
if ( F_3 ( V_24 , & V_4 -> V_8 ) )
F_14 ( V_4 -> V_25 ) ;
F_43 ( V_4 -> V_25 ) ;
if ( F_3 ( V_53 , & V_4 -> V_8 ) )
F_37 ( V_4 -> V_54 ) ;
F_38 ( V_4 -> V_51 ) ;
if ( F_3 ( V_50 , & V_4 -> V_8 ) )
F_39 ( V_10 -> V_29 -> V_30 ) ;
F_44 ( V_4 -> V_58 , V_4 -> V_17 ) ;
return 0 ;
}
static void F_45 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_29 -> V_30 ) ;
V_4 -> V_10 = V_10 ;
if ( F_46 ( V_7 , & V_4 -> V_8 ) )
return;
F_18 ( & V_4 -> V_2 ) ;
}
static void F_47 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_29 -> V_30 ) ;
F_9 ( V_7 , & V_4 -> V_8 ) ;
}
static struct V_63 *
F_48 ( struct V_10 * V_10 , void T_3 * V_64 )
{
return NULL ;
}
static void F_49 ( struct V_63 * V_65 )
{
}
static int F_50 ( struct V_10 * V_10 , T_1 V_66 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_29 -> V_30 ) ;
enum V_27 V_67 ;
switch ( V_66 ) {
case V_68 :
V_67 = V_69 ;
break;
case V_70 :
V_67 = V_71 ;
break;
case V_72 :
V_67 = V_73 ;
break;
default:
F_51 ( V_10 -> V_29 -> V_30 ,
L_1 ) ;
return - V_74 ;
}
if ( V_4 -> V_27 == V_67 )
return 0 ;
if ( V_10 -> V_75 != V_76 ) {
F_51 ( V_10 -> V_29 -> V_30 ,
L_2 ) ;
return - V_74 ;
}
if ( V_10 -> V_77 & V_78 )
F_52 ( V_10 ) ;
V_4 -> V_27 = V_67 ;
F_7 ( V_26 , & V_4 -> V_8 ) ;
F_18 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_29 -> V_30 ) ;
F_7 ( V_26 , & V_4 -> V_8 ) ;
F_18 ( & V_4 -> V_2 ) ;
return 0 ;
}
static T_4 F_54 ( T_1 V_79 )
{
return ( V_79 * 4 ) ;
}
static T_4 F_55 ( T_1 V_79 , T_5 V_80 )
{
F_56 ( V_80 != 0 ,
L_3 ) ;
return 0x80 ;
}
static T_4 F_57 ( T_1 V_79 , T_5 V_80 )
{
return V_81 + V_80 ;
}
static T_1 F_58 ( const void T_3 * V_82 , unsigned V_80 )
{
struct V_3 * V_4 ;
if ( V_82 == V_49 -> V_13 ) {
switch ( V_80 ) {
case V_36 :
return F_6 ( V_82 + V_83 ) ;
case V_84 :
return F_6 ( V_82 + V_85 ) ;
case V_86 :
return F_6 ( V_82 + V_34 ) ;
case V_87 :
return F_6 ( V_82 + V_88 ) ;
case V_89 :
return F_6 ( V_82 + V_90 ) ;
case V_91 :
return 0 ;
case V_92 :
return F_6 ( V_82 + V_14 ) ;
case V_93 :
return F_6 ( V_82 + V_94 ) ;
case V_95 :
return F_6 ( V_82 + V_96 ) ;
case V_97 + 0x10 :
V_4 = F_17 ( V_49 -> V_29 -> V_30 ) ;
if ( F_3 ( V_98 ,
& V_4 -> V_8 ) )
return 0xde ;
return F_6 ( V_82 + V_99 ) ;
case V_81 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
return F_6 ( V_82 + V_80 ) ;
default:
F_51 ( V_49 -> V_29 -> V_30 ,
L_4 , V_80 ) ;
return 0 ;
}
} else if ( V_82 == ( V_49 -> V_13 + 0x80 ) ) {
if ( V_80 >= V_105 )
V_80 += 2 ;
return F_6 ( V_82 + V_80 ) ;
}
F_51 ( V_49 -> V_29 -> V_30 ,
L_5 ,
( int ) ( V_82 - V_49 -> V_13 ) ) ;
return 0 ;
}
static void F_59 ( void T_3 * V_82 , unsigned V_80 , T_1 V_106 )
{
if ( V_82 == V_49 -> V_13 ) {
switch ( V_80 ) {
case V_36 :
return F_11 ( V_106 , V_82 + V_83 ) ;
case V_84 :
return F_11 ( V_106 , V_82 + V_85 ) ;
case V_86 :
return F_11 ( V_106 , V_82 + V_34 ) ;
case V_87 :
return F_11 ( V_106 , V_82 + V_88 ) ;
case V_89 :
return F_11 ( V_106 , V_82 + V_90 ) ;
case V_91 :
if ( V_106 )
F_60 ( V_49 -> V_29 -> V_30 ,
L_6 ) ;
return;
case V_92 :
return F_11 ( V_106 , V_82 + V_14 ) ;
case V_93 :
return F_11 ( V_106 , V_82 + V_94 ) ;
case V_95 :
return F_11 ( V_106 , V_82 + V_96 ) ;
case V_81 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
return F_11 ( V_106 , V_82 + V_80 ) ;
default:
F_51 ( V_49 -> V_29 -> V_30 ,
L_7 , V_80 ) ;
return;
}
} else if ( V_82 == ( V_49 -> V_13 + 0x80 ) ) {
if ( V_80 >= V_105 )
V_80 += 2 ;
return F_11 ( V_106 , V_82 + V_80 ) ;
}
F_51 ( V_49 -> V_29 -> V_30 ,
L_8 ,
( int ) ( V_82 - V_49 -> V_13 ) ) ;
}
static T_5 F_61 ( const void T_3 * V_82 , unsigned V_80 )
{
if ( V_82 == V_49 -> V_13 ) {
switch ( V_80 ) {
case V_107 :
return F_26 ( V_82 + V_38 ) ;
case V_108 :
return F_26 ( V_82 + V_40 ) ;
case V_109 :
return F_26 ( V_82 + V_110 ) ;
case V_111 :
return F_26 ( V_82 + V_112 ) ;
case V_113 :
return F_26 ( V_82 + V_114 ) ;
case V_115 :
return F_26 ( V_82 + V_116 ) ;
case V_117 :
return F_26 ( V_82 + V_118 ) ;
case V_119 :
return 0 ;
default:
F_51 ( V_49 -> V_29 -> V_30 ,
L_9 , V_80 ) ;
return 0 ;
}
} else if ( V_82 == ( V_49 -> V_13 + 0x80 ) ) {
return F_26 ( V_82 + V_80 ) ;
}
F_51 ( V_49 -> V_29 -> V_30 ,
L_10 ,
( int ) ( V_82 - V_49 -> V_13 ) ) ;
return 0 ;
}
static void F_62 ( void T_3 * V_82 , unsigned V_80 , T_5 V_106 )
{
if ( V_82 == V_49 -> V_13 ) {
switch ( V_80 ) {
case V_107 :
return F_27 ( V_106 , V_82 + V_38 ) ;
case V_108 :
return F_27 ( V_106 , V_82 + V_40 ) ;
case V_109 :
return F_27 ( V_106 , V_82 + V_110 ) ;
case V_111 :
return F_27 ( V_106 , V_82 + V_112 ) ;
case V_113 :
return F_27 ( V_106 , V_82 + V_114 ) ;
case V_115 :
return F_27 ( V_106 , V_82 + V_116 ) ;
case V_117 :
return F_27 ( V_106 , V_82 + V_118 ) ;
default:
F_51 ( V_49 -> V_29 -> V_30 ,
L_11 , V_80 ) ;
return;
}
} else if ( V_82 == ( V_49 -> V_13 + 0x80 ) ) {
return F_27 ( V_106 , V_82 + V_80 ) ;
}
F_51 ( V_49 -> V_29 -> V_30 ,
L_12 ,
( int ) ( V_82 - V_49 -> V_13 ) ) ;
}
static int F_63 ( struct V_120 * V_121 )
{
struct V_122 V_123 ;
struct V_124 V_125 ;
struct V_3 * V_4 ;
struct V_126 * V_127 = V_121 -> V_58 . V_128 ;
int V_48 ;
if ( ! V_127 ) {
F_51 ( & V_121 -> V_58 , L_13 ) ;
return - V_74 ;
}
V_4 = F_64 ( & V_121 -> V_58 , sizeof( * V_4 ) , V_129 ) ;
if ( ! V_4 )
return - V_130 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
switch ( F_65 ( & V_121 -> V_58 ) ) {
#if V_131 V_132 || V_131 V_133
case V_134 :
V_123 . V_66 = V_135 ;
V_4 -> V_27 = V_69 ;
break;
#endif
#if V_131 V_132 || V_131 V_136
case V_137 :
V_123 . V_66 = V_138 ;
V_4 -> V_27 = V_71 ;
break;
#endif
#ifdef V_132
case V_139 :
V_123 . V_66 = V_76 ;
V_4 -> V_27 = V_73 ;
break;
#endif
default:
F_51 ( & V_121 -> V_58 , L_14 ) ;
return - V_74 ;
}
V_123 . V_140 = & V_141 ;
if ( ! F_66 ( V_127 , L_15 ) )
V_123 . V_142 = & V_143 ;
else
V_123 . V_142 = & V_144 ;
V_4 -> V_58 = & V_121 -> V_58 ;
F_67 ( & V_4 -> V_2 , F_1 ) ;
V_4 -> V_46 . V_145 = F_29 ;
if ( F_66 ( V_127 , L_16 ) )
F_7 ( V_50 , & V_4 -> V_8 ) ;
if ( F_66 ( V_127 , L_17 ) )
F_7 ( V_53 , & V_4 -> V_8 ) ;
if ( F_66 ( V_127 , L_18 ) ||
F_66 ( V_127 , L_15 ) ) {
F_7 ( V_53 , & V_4 -> V_8 ) ;
F_7 ( V_98 , & V_4 -> V_8 ) ;
}
V_4 -> V_51 = F_68 ( & V_121 -> V_58 , NULL ) ;
if ( F_69 ( V_4 -> V_51 ) ) {
F_51 ( & V_121 -> V_58 , L_19 ,
F_70 ( V_4 -> V_51 ) ) ;
return F_70 ( V_4 -> V_51 ) ;
}
if ( F_3 ( V_53 , & V_4 -> V_8 ) ) {
V_4 -> V_54 = F_71 ( & V_121 -> V_58 , NULL ) ;
if ( F_69 ( V_4 -> V_54 ) ) {
if ( F_70 ( V_4 -> V_54 ) == - V_146 )
return - V_146 ;
F_51 ( & V_121 -> V_58 , L_20 ,
F_70 ( V_4 -> V_54 ) ) ;
return F_70 ( V_4 -> V_54 ) ;
}
}
V_4 -> V_59 = F_72 ( & V_121 -> V_58 , 0 ) ;
if ( F_69 ( V_4 -> V_59 ) ) {
if ( F_70 ( V_4 -> V_59 ) == - V_146 )
return - V_146 ;
F_51 ( & V_121 -> V_58 , L_21 ) ;
return F_70 ( V_4 -> V_59 ) ;
}
V_4 -> V_25 = F_73 ( & V_121 -> V_58 , L_22 ) ;
if ( F_69 ( V_4 -> V_25 ) ) {
if ( F_70 ( V_4 -> V_25 ) == - V_146 )
return - V_146 ;
F_51 ( & V_121 -> V_58 , L_23 ,
F_70 ( V_4 -> V_25 ) ) ;
return F_70 ( V_4 -> V_25 ) ;
}
V_4 -> V_147 = F_74 () ;
if ( F_69 ( V_4 -> V_147 ) ) {
F_51 ( & V_121 -> V_58 , L_24 ,
F_70 ( V_4 -> V_147 ) ) ;
return F_70 ( V_4 -> V_147 ) ;
}
V_4 -> V_17 = F_75 ( & V_121 -> V_58 , V_148 ) ;
if ( F_69 ( V_4 -> V_17 ) ) {
V_48 = F_70 ( V_4 -> V_17 ) ;
F_51 ( & V_121 -> V_58 , L_25 , V_48 ) ;
goto V_149;
}
F_76 ( V_121 , V_4 ) ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_150 = L_26 ;
V_125 . V_151 = V_152 ;
V_125 . V_30 = & V_121 -> V_58 ;
V_125 . V_153 = V_121 -> V_154 ;
V_125 . V_155 = V_121 -> V_156 ;
V_125 . V_106 = & V_123 ;
V_125 . V_157 = sizeof( V_123 ) ;
V_4 -> V_158 = F_77 ( & V_125 ) ;
if ( F_69 ( V_4 -> V_158 ) ) {
V_48 = F_70 ( V_4 -> V_158 ) ;
F_51 ( & V_121 -> V_58 , L_27 , V_48 ) ;
goto V_149;
}
return 0 ;
V_149:
F_78 ( V_4 -> V_147 ) ;
return V_48 ;
}
static int F_79 ( struct V_120 * V_121 )
{
struct V_3 * V_4 = F_80 ( V_121 ) ;
struct V_120 * V_147 = V_4 -> V_147 ;
F_81 ( V_4 -> V_158 ) ;
F_78 ( V_147 ) ;
return 0 ;
}
