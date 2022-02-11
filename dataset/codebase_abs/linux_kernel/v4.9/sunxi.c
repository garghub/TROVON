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
if ( ( V_10 -> V_33 & V_35 ) && F_23 ( V_10 ) ) {
V_10 -> V_33 &= ~ V_35 ;
V_10 -> V_33 |= V_36 ;
}
if ( ( V_10 -> V_33 & V_37 ) && ! F_23 ( V_10 ) ) {
F_24 ( V_10 -> V_13 , 0 ) ;
F_25 ( V_10 -> V_13 , V_38 , 0 ) ;
}
V_10 -> V_39 = F_26 ( V_10 -> V_13 + V_40 ) ;
if ( V_10 -> V_39 )
F_27 ( V_10 -> V_39 , V_10 -> V_13 + V_40 ) ;
V_10 -> V_41 = F_26 ( V_10 -> V_13 + V_42 ) ;
if ( V_10 -> V_41 )
F_27 ( V_10 -> V_41 , V_10 -> V_13 + V_42 ) ;
F_28 ( V_10 ) ;
F_12 ( & V_10 -> V_12 , V_8 ) ;
return V_43 ;
}
static int F_29 ( struct V_44 * V_45 ,
unsigned long V_46 , void * V_47 )
{
struct V_3 * V_4 = F_2 ( V_45 , struct V_3 , V_48 ) ;
if ( V_46 )
F_7 ( V_15 , & V_4 -> V_8 ) ;
else
F_9 ( V_15 , & V_4 -> V_8 ) ;
F_7 ( V_9 , & V_4 -> V_8 ) ;
F_18 ( & V_4 -> V_2 ) ;
return V_49 ;
}
static int F_30 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_29 -> V_30 ) ;
int V_50 ;
V_51 = V_10 ;
V_10 -> V_25 = V_4 -> V_25 ;
V_10 -> V_17 = V_4 -> V_17 ;
if ( F_3 ( V_52 , & V_4 -> V_8 ) ) {
V_50 = F_31 ( V_10 -> V_29 -> V_30 ) ;
if ( V_50 )
return V_50 ;
}
V_50 = F_32 ( V_4 -> V_53 ) ;
if ( V_50 )
goto V_54;
if ( F_3 ( V_55 , & V_4 -> V_8 ) ) {
V_50 = F_33 ( V_4 -> V_56 ) ;
if ( V_50 )
goto V_57;
}
F_11 ( V_58 , V_10 -> V_13 + V_59 ) ;
V_50 = F_34 ( V_4 -> V_60 , V_61 ,
& V_4 -> V_48 ) ;
if ( V_50 )
goto V_62;
V_50 = F_35 ( V_4 -> V_25 ) ;
if ( V_50 )
goto V_63;
V_10 -> V_64 = F_22 ;
F_36 ( V_10 -> V_29 ) ;
return 0 ;
V_63:
F_37 ( V_4 -> V_60 , V_61 ,
& V_4 -> V_48 ) ;
V_62:
if ( F_3 ( V_55 , & V_4 -> V_8 ) )
F_38 ( V_4 -> V_56 ) ;
V_57:
F_39 ( V_4 -> V_53 ) ;
V_54:
if ( F_3 ( V_52 , & V_4 -> V_8 ) )
F_40 ( V_10 -> V_29 -> V_30 ) ;
return V_50 ;
}
static int F_41 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_29 -> V_30 ) ;
F_42 ( V_10 -> V_29 ) ;
F_43 ( & V_4 -> V_2 ) ;
if ( F_3 ( V_24 , & V_4 -> V_8 ) )
F_14 ( V_4 -> V_25 ) ;
F_44 ( V_4 -> V_25 ) ;
F_37 ( V_4 -> V_60 , V_61 ,
& V_4 -> V_48 ) ;
if ( F_3 ( V_55 , & V_4 -> V_8 ) )
F_38 ( V_4 -> V_56 ) ;
F_39 ( V_4 -> V_53 ) ;
if ( F_3 ( V_52 , & V_4 -> V_8 ) )
F_40 ( V_10 -> V_29 -> V_30 ) ;
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
static struct V_65 *
F_48 ( struct V_10 * V_10 , void T_3 * V_66 )
{
return NULL ;
}
static void F_49 ( struct V_65 * V_67 )
{
}
static int F_50 ( struct V_10 * V_10 , T_1 V_68 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_29 -> V_30 ) ;
enum V_27 V_69 ;
switch ( V_68 ) {
case V_70 :
V_69 = V_71 ;
break;
case V_72 :
V_69 = V_73 ;
break;
case V_74 :
V_69 = V_75 ;
break;
default:
F_51 ( V_10 -> V_29 -> V_30 ,
L_1 ) ;
return - V_76 ;
}
if ( V_4 -> V_27 == V_69 )
return 0 ;
if ( V_10 -> V_77 != V_78 ) {
F_51 ( V_10 -> V_29 -> V_30 ,
L_2 ) ;
return - V_76 ;
}
if ( V_10 -> V_79 & V_80 )
F_52 ( V_10 ) ;
V_4 -> V_27 = V_69 ;
F_7 ( V_26 , & V_4 -> V_8 ) ;
F_18 ( & V_4 -> V_2 ) ;
return 0 ;
}
static T_4 F_53 ( T_1 V_81 )
{
return ( V_81 * 4 ) ;
}
static T_4 F_54 ( T_1 V_81 , T_5 V_82 )
{
F_55 ( V_82 != 0 ,
L_3 ) ;
return 0x80 ;
}
static T_4 F_56 ( T_1 V_81 , T_5 V_82 )
{
return V_83 + V_82 ;
}
static T_1 F_57 ( const void T_3 * V_84 , unsigned V_82 )
{
struct V_3 * V_4 ;
if ( V_84 == V_51 -> V_13 ) {
switch ( V_82 ) {
case V_38 :
return F_6 ( V_84 + V_85 ) ;
case V_86 :
return F_6 ( V_84 + V_87 ) ;
case V_88 :
return F_6 ( V_84 + V_34 ) ;
case V_89 :
return F_6 ( V_84 + V_90 ) ;
case V_91 :
return F_6 ( V_84 + V_92 ) ;
case V_93 :
return 0 ;
case V_94 :
return F_6 ( V_84 + V_14 ) ;
case V_95 :
return F_6 ( V_84 + V_96 ) ;
case V_97 :
return F_6 ( V_84 + V_98 ) ;
case V_99 + 0x10 :
V_4 = F_17 ( V_51 -> V_29 -> V_30 ) ;
if ( F_3 ( V_100 ,
& V_4 -> V_8 ) )
return 0xde ;
return F_6 ( V_84 + V_101 ) ;
case V_83 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
return F_6 ( V_84 + V_82 ) ;
default:
F_51 ( V_51 -> V_29 -> V_30 ,
L_4 , V_82 ) ;
return 0 ;
}
} else if ( V_84 == ( V_51 -> V_13 + 0x80 ) ) {
if ( V_82 >= V_107 )
V_82 += 2 ;
return F_6 ( V_84 + V_82 ) ;
}
F_51 ( V_51 -> V_29 -> V_30 ,
L_5 ,
( int ) ( V_84 - V_51 -> V_13 ) ) ;
return 0 ;
}
static void F_58 ( void T_3 * V_84 , unsigned V_82 , T_1 V_108 )
{
if ( V_84 == V_51 -> V_13 ) {
switch ( V_82 ) {
case V_38 :
return F_11 ( V_108 , V_84 + V_85 ) ;
case V_86 :
return F_11 ( V_108 , V_84 + V_87 ) ;
case V_88 :
return F_11 ( V_108 , V_84 + V_34 ) ;
case V_89 :
return F_11 ( V_108 , V_84 + V_90 ) ;
case V_91 :
return F_11 ( V_108 , V_84 + V_92 ) ;
case V_93 :
if ( V_108 )
F_59 ( V_51 -> V_29 -> V_30 ,
L_6 ) ;
return;
case V_94 :
return F_11 ( V_108 , V_84 + V_14 ) ;
case V_95 :
return F_11 ( V_108 , V_84 + V_96 ) ;
case V_97 :
return F_11 ( V_108 , V_84 + V_98 ) ;
case V_83 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
return F_11 ( V_108 , V_84 + V_82 ) ;
default:
F_51 ( V_51 -> V_29 -> V_30 ,
L_7 , V_82 ) ;
return;
}
} else if ( V_84 == ( V_51 -> V_13 + 0x80 ) ) {
if ( V_82 >= V_107 )
V_82 += 2 ;
return F_11 ( V_108 , V_84 + V_82 ) ;
}
F_51 ( V_51 -> V_29 -> V_30 ,
L_8 ,
( int ) ( V_84 - V_51 -> V_13 ) ) ;
}
static T_5 F_60 ( const void T_3 * V_84 , unsigned V_82 )
{
if ( V_84 == V_51 -> V_13 ) {
switch ( V_82 ) {
case V_109 :
return F_26 ( V_84 + V_40 ) ;
case V_110 :
return F_26 ( V_84 + V_42 ) ;
case V_111 :
return F_26 ( V_84 + V_112 ) ;
case V_113 :
return F_26 ( V_84 + V_114 ) ;
case V_115 :
return F_26 ( V_84 + V_116 ) ;
case V_117 :
return F_26 ( V_84 + V_118 ) ;
case V_119 :
return F_26 ( V_84 + V_120 ) ;
case V_121 :
return 0 ;
default:
F_51 ( V_51 -> V_29 -> V_30 ,
L_9 , V_82 ) ;
return 0 ;
}
} else if ( V_84 == ( V_51 -> V_13 + 0x80 ) ) {
return F_26 ( V_84 + V_82 ) ;
}
F_51 ( V_51 -> V_29 -> V_30 ,
L_10 ,
( int ) ( V_84 - V_51 -> V_13 ) ) ;
return 0 ;
}
static void F_61 ( void T_3 * V_84 , unsigned V_82 , T_5 V_108 )
{
if ( V_84 == V_51 -> V_13 ) {
switch ( V_82 ) {
case V_109 :
return F_27 ( V_108 , V_84 + V_40 ) ;
case V_110 :
return F_27 ( V_108 , V_84 + V_42 ) ;
case V_111 :
return F_27 ( V_108 , V_84 + V_112 ) ;
case V_113 :
return F_27 ( V_108 , V_84 + V_114 ) ;
case V_115 :
return F_27 ( V_108 , V_84 + V_116 ) ;
case V_117 :
return F_27 ( V_108 , V_84 + V_118 ) ;
case V_119 :
return F_27 ( V_108 , V_84 + V_120 ) ;
default:
F_51 ( V_51 -> V_29 -> V_30 ,
L_11 , V_82 ) ;
return;
}
} else if ( V_84 == ( V_51 -> V_13 + 0x80 ) ) {
return F_27 ( V_108 , V_84 + V_82 ) ;
}
F_51 ( V_51 -> V_29 -> V_30 ,
L_12 ,
( int ) ( V_84 - V_51 -> V_13 ) ) ;
}
static int F_62 ( struct V_122 * V_123 )
{
struct V_124 V_125 ;
struct V_126 V_127 ;
struct V_3 * V_4 ;
struct V_128 * V_129 = V_123 -> V_130 . V_131 ;
int V_50 ;
if ( ! V_129 ) {
F_51 ( & V_123 -> V_130 , L_13 ) ;
return - V_76 ;
}
V_4 = F_63 ( & V_123 -> V_130 , sizeof( * V_4 ) , V_132 ) ;
if ( ! V_4 )
return - V_133 ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
switch ( F_64 ( & V_123 -> V_130 ) ) {
#if V_134 V_135 || V_134 V_136
case V_137 :
V_125 . V_68 = V_138 ;
V_4 -> V_27 = V_71 ;
break;
#endif
#if V_134 V_135 || V_134 V_139
case V_140 :
V_125 . V_68 = V_141 ;
V_4 -> V_27 = V_73 ;
break;
#endif
#ifdef V_135
case V_142 :
V_125 . V_68 = V_78 ;
V_4 -> V_27 = V_75 ;
break;
#endif
default:
F_51 ( & V_123 -> V_130 , L_14 ) ;
return - V_76 ;
}
V_125 . V_143 = & V_144 ;
V_125 . V_145 = & V_146 ;
V_4 -> V_130 = & V_123 -> V_130 ;
F_65 ( & V_4 -> V_2 , F_1 ) ;
V_4 -> V_48 . V_147 = F_29 ;
if ( F_66 ( V_129 , L_15 ) )
F_7 ( V_52 , & V_4 -> V_8 ) ;
if ( F_66 ( V_129 , L_16 ) )
F_7 ( V_55 , & V_4 -> V_8 ) ;
if ( F_66 ( V_129 , L_17 ) ) {
F_7 ( V_55 , & V_4 -> V_8 ) ;
F_7 ( V_100 , & V_4 -> V_8 ) ;
}
V_4 -> V_53 = F_67 ( & V_123 -> V_130 , NULL ) ;
if ( F_68 ( V_4 -> V_53 ) ) {
F_51 ( & V_123 -> V_130 , L_18 ,
F_69 ( V_4 -> V_53 ) ) ;
return F_69 ( V_4 -> V_53 ) ;
}
if ( F_3 ( V_55 , & V_4 -> V_8 ) ) {
V_4 -> V_56 = F_70 ( & V_123 -> V_130 , NULL ) ;
if ( F_68 ( V_4 -> V_56 ) ) {
if ( F_69 ( V_4 -> V_56 ) == - V_148 )
return - V_148 ;
F_51 ( & V_123 -> V_130 , L_19 ,
F_69 ( V_4 -> V_56 ) ) ;
return F_69 ( V_4 -> V_56 ) ;
}
}
V_4 -> V_60 = F_71 ( & V_123 -> V_130 , 0 ) ;
if ( F_68 ( V_4 -> V_60 ) ) {
if ( F_69 ( V_4 -> V_60 ) == - V_148 )
return - V_148 ;
F_51 ( & V_123 -> V_130 , L_20 ) ;
return F_69 ( V_4 -> V_60 ) ;
}
V_4 -> V_25 = F_72 ( & V_123 -> V_130 , L_21 ) ;
if ( F_68 ( V_4 -> V_25 ) ) {
if ( F_69 ( V_4 -> V_25 ) == - V_148 )
return - V_148 ;
F_51 ( & V_123 -> V_130 , L_22 ,
F_69 ( V_4 -> V_25 ) ) ;
return F_69 ( V_4 -> V_25 ) ;
}
V_4 -> V_149 = F_73 () ;
if ( F_68 ( V_4 -> V_149 ) ) {
F_51 ( & V_123 -> V_130 , L_23 ,
F_69 ( V_4 -> V_149 ) ) ;
return F_69 ( V_4 -> V_149 ) ;
}
V_4 -> V_17 = F_74 ( & V_123 -> V_130 , V_150 ) ;
if ( F_68 ( V_4 -> V_17 ) ) {
V_50 = F_69 ( V_4 -> V_17 ) ;
F_51 ( & V_123 -> V_130 , L_24 , V_50 ) ;
goto V_151;
}
F_75 ( V_123 , V_4 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_152 = L_25 ;
V_127 . V_153 = V_154 ;
V_127 . V_30 = & V_123 -> V_130 ;
V_127 . V_155 = V_123 -> V_156 ;
V_127 . V_157 = V_123 -> V_158 ;
V_127 . V_108 = & V_125 ;
V_127 . V_159 = sizeof( V_125 ) ;
V_4 -> V_160 = F_76 ( & V_127 ) ;
if ( F_68 ( V_4 -> V_160 ) ) {
V_50 = F_69 ( V_4 -> V_160 ) ;
F_51 ( & V_123 -> V_130 , L_26 , V_50 ) ;
goto V_151;
}
return 0 ;
V_151:
F_77 ( V_4 -> V_149 ) ;
return V_50 ;
}
static int F_78 ( struct V_122 * V_123 )
{
struct V_3 * V_4 = F_79 ( V_123 ) ;
struct V_122 * V_149 = V_4 -> V_149 ;
F_80 ( V_4 -> V_160 ) ;
F_77 ( V_149 ) ;
return 0 ;
}
