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
}
static void F_15 ( struct V_10 * V_10 , int V_26 )
{
struct V_3 * V_4 = F_16 ( V_10 -> V_27 -> V_28 ) ;
if ( V_26 ) {
F_7 ( V_16 , & V_4 -> V_8 ) ;
V_10 -> V_17 -> V_18 -> V_20 = V_21 ;
} else {
F_9 ( V_16 , & V_4 -> V_8 ) ;
}
F_17 ( & V_4 -> V_2 ) ;
}
static void F_18 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_16 ( V_10 -> V_27 -> V_28 ) ;
F_19 ( V_4 -> V_25 , false ) ;
}
static void F_20 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_16 ( V_10 -> V_27 -> V_28 ) ;
F_19 ( V_4 -> V_25 , true ) ;
}
static T_2 F_21 ( int V_29 , void * V_30 )
{
struct V_10 * V_10 = V_30 ;
unsigned long V_8 ;
F_5 ( & V_10 -> V_12 , V_8 ) ;
V_10 -> V_31 = F_6 ( V_10 -> V_13 + V_32 ) ;
if ( V_10 -> V_31 )
F_11 ( V_10 -> V_31 , V_10 -> V_13 + V_32 ) ;
if ( ( V_10 -> V_31 & V_33 ) && F_22 ( V_10 ) ) {
V_10 -> V_31 &= ~ V_33 ;
V_10 -> V_31 |= V_34 ;
}
if ( ( V_10 -> V_31 & V_35 ) && ! F_22 ( V_10 ) ) {
F_23 ( V_10 -> V_13 , 0 ) ;
F_24 ( V_10 -> V_13 , V_36 , 0 ) ;
}
V_10 -> V_37 = F_25 ( V_10 -> V_13 + V_38 ) ;
if ( V_10 -> V_37 )
F_26 ( V_10 -> V_37 , V_10 -> V_13 + V_38 ) ;
V_10 -> V_39 = F_25 ( V_10 -> V_13 + V_40 ) ;
if ( V_10 -> V_39 )
F_26 ( V_10 -> V_39 , V_10 -> V_13 + V_40 ) ;
F_27 ( V_10 ) ;
F_12 ( & V_10 -> V_12 , V_8 ) ;
return V_41 ;
}
static int F_28 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
struct V_3 * V_4 = F_2 ( V_43 , struct V_3 , V_46 ) ;
if ( V_44 )
F_7 ( V_15 , & V_4 -> V_8 ) ;
else
F_9 ( V_15 , & V_4 -> V_8 ) ;
F_7 ( V_9 , & V_4 -> V_8 ) ;
F_17 ( & V_4 -> V_2 ) ;
return V_47 ;
}
static int F_29 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_16 ( V_10 -> V_27 -> V_28 ) ;
int V_48 ;
V_49 = V_10 ;
V_10 -> V_25 = V_4 -> V_25 ;
V_10 -> V_17 = V_4 -> V_17 ;
if ( F_3 ( V_50 , & V_4 -> V_8 ) ) {
V_48 = F_30 ( V_10 -> V_27 -> V_28 ) ;
if ( V_48 )
return V_48 ;
}
V_48 = F_31 ( V_4 -> V_51 ) ;
if ( V_48 )
goto V_52;
if ( F_3 ( V_53 , & V_4 -> V_8 ) ) {
V_48 = F_32 ( V_4 -> V_54 ) ;
if ( V_48 )
goto V_55;
}
F_11 ( V_56 , V_10 -> V_13 + V_57 ) ;
V_48 = F_33 ( V_4 -> V_58 , V_59 ,
& V_4 -> V_46 ) ;
if ( V_48 )
goto V_60;
V_48 = F_34 ( V_4 -> V_25 ) ;
if ( V_48 )
goto V_61;
V_10 -> V_62 = F_21 ;
F_35 ( V_10 -> V_27 ) ;
return 0 ;
V_61:
F_36 ( V_4 -> V_58 , V_59 ,
& V_4 -> V_46 ) ;
V_60:
if ( F_3 ( V_53 , & V_4 -> V_8 ) )
F_37 ( V_4 -> V_54 ) ;
V_55:
F_38 ( V_4 -> V_51 ) ;
V_52:
if ( F_3 ( V_50 , & V_4 -> V_8 ) )
F_39 ( V_10 -> V_27 -> V_28 ) ;
return V_48 ;
}
static int F_40 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_16 ( V_10 -> V_27 -> V_28 ) ;
F_41 ( V_10 -> V_27 ) ;
F_42 ( & V_4 -> V_2 ) ;
if ( F_3 ( V_24 , & V_4 -> V_8 ) )
F_14 ( V_4 -> V_25 ) ;
F_43 ( V_4 -> V_25 ) ;
F_36 ( V_4 -> V_58 , V_59 ,
& V_4 -> V_46 ) ;
if ( F_3 ( V_53 , & V_4 -> V_8 ) )
F_37 ( V_4 -> V_54 ) ;
F_38 ( V_4 -> V_51 ) ;
if ( F_3 ( V_50 , & V_4 -> V_8 ) )
F_39 ( V_10 -> V_27 -> V_28 ) ;
return 0 ;
}
static void F_44 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_16 ( V_10 -> V_27 -> V_28 ) ;
V_4 -> V_10 = V_10 ;
if ( F_45 ( V_7 , & V_4 -> V_8 ) )
return;
F_17 ( & V_4 -> V_2 ) ;
}
static void F_46 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_16 ( V_10 -> V_27 -> V_28 ) ;
F_9 ( V_7 , & V_4 -> V_8 ) ;
}
static struct V_63 *
F_47 ( struct V_10 * V_10 , void T_3 * V_64 )
{
return NULL ;
}
static void F_48 ( struct V_63 * V_65 )
{
}
static T_4 F_49 ( T_1 V_66 )
{
return ( V_66 * 4 ) ;
}
static T_4 F_50 ( T_1 V_66 , T_5 V_67 )
{
F_51 ( V_67 != 0 ,
L_1 ) ;
return 0x80 ;
}
static T_4 F_52 ( T_1 V_66 , T_5 V_67 )
{
return V_68 + V_67 ;
}
static T_1 F_53 ( const void T_3 * V_69 , unsigned V_67 )
{
struct V_3 * V_4 ;
if ( V_69 == V_49 -> V_13 ) {
switch ( V_67 ) {
case V_36 :
return F_6 ( V_69 + V_70 ) ;
case V_71 :
return F_6 ( V_69 + V_72 ) ;
case V_73 :
return F_6 ( V_69 + V_32 ) ;
case V_74 :
return F_6 ( V_69 + V_75 ) ;
case V_76 :
return F_6 ( V_69 + V_77 ) ;
case V_78 :
return 0 ;
case V_79 :
return F_6 ( V_69 + V_14 ) ;
case V_80 :
return F_6 ( V_69 + V_81 ) ;
case V_82 :
return F_6 ( V_69 + V_83 ) ;
case V_84 + 0x10 :
V_4 = F_16 ( V_49 -> V_27 -> V_28 ) ;
if ( F_3 ( V_85 ,
& V_4 -> V_8 ) )
return 0xde ;
return F_6 ( V_69 + V_86 ) ;
case V_68 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
return F_6 ( V_69 + V_67 ) ;
default:
F_54 ( V_49 -> V_27 -> V_28 ,
L_2 , V_67 ) ;
return 0 ;
}
} else if ( V_69 == ( V_49 -> V_13 + 0x80 ) ) {
if ( V_67 >= V_92 )
V_67 += 2 ;
return F_6 ( V_69 + V_67 ) ;
}
F_54 ( V_49 -> V_27 -> V_28 ,
L_3 ,
( int ) ( V_69 - V_49 -> V_13 ) ) ;
return 0 ;
}
static void F_55 ( void T_3 * V_69 , unsigned V_67 , T_1 V_93 )
{
if ( V_69 == V_49 -> V_13 ) {
switch ( V_67 ) {
case V_36 :
return F_11 ( V_93 , V_69 + V_70 ) ;
case V_71 :
return F_11 ( V_93 , V_69 + V_72 ) ;
case V_73 :
return F_11 ( V_93 , V_69 + V_32 ) ;
case V_74 :
return F_11 ( V_93 , V_69 + V_75 ) ;
case V_76 :
return F_11 ( V_93 , V_69 + V_77 ) ;
case V_78 :
if ( V_93 )
F_56 ( V_49 -> V_27 -> V_28 ,
L_4 ) ;
return;
case V_79 :
return F_11 ( V_93 , V_69 + V_14 ) ;
case V_80 :
return F_11 ( V_93 , V_69 + V_81 ) ;
case V_82 :
return F_11 ( V_93 , V_69 + V_83 ) ;
case V_68 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
return F_11 ( V_93 , V_69 + V_67 ) ;
default:
F_54 ( V_49 -> V_27 -> V_28 ,
L_5 , V_67 ) ;
return;
}
} else if ( V_69 == ( V_49 -> V_13 + 0x80 ) ) {
if ( V_67 >= V_92 )
V_67 += 2 ;
return F_11 ( V_93 , V_69 + V_67 ) ;
}
F_54 ( V_49 -> V_27 -> V_28 ,
L_6 ,
( int ) ( V_69 - V_49 -> V_13 ) ) ;
}
static T_5 F_57 ( const void T_3 * V_69 , unsigned V_67 )
{
if ( V_69 == V_49 -> V_13 ) {
switch ( V_67 ) {
case V_94 :
return F_25 ( V_69 + V_38 ) ;
case V_95 :
return F_25 ( V_69 + V_40 ) ;
case V_96 :
return F_25 ( V_69 + V_97 ) ;
case V_98 :
return F_25 ( V_69 + V_99 ) ;
case V_100 :
return F_25 ( V_69 + V_101 ) ;
case V_102 :
return F_25 ( V_69 + V_103 ) ;
case V_104 :
return F_25 ( V_69 + V_105 ) ;
case V_106 :
return 0 ;
default:
F_54 ( V_49 -> V_27 -> V_28 ,
L_7 , V_67 ) ;
return 0 ;
}
} else if ( V_69 == ( V_49 -> V_13 + 0x80 ) ) {
return F_25 ( V_69 + V_67 ) ;
}
F_54 ( V_49 -> V_27 -> V_28 ,
L_8 ,
( int ) ( V_69 - V_49 -> V_13 ) ) ;
return 0 ;
}
static void F_58 ( void T_3 * V_69 , unsigned V_67 , T_5 V_93 )
{
if ( V_69 == V_49 -> V_13 ) {
switch ( V_67 ) {
case V_94 :
return F_26 ( V_93 , V_69 + V_38 ) ;
case V_95 :
return F_26 ( V_93 , V_69 + V_40 ) ;
case V_96 :
return F_26 ( V_93 , V_69 + V_97 ) ;
case V_98 :
return F_26 ( V_93 , V_69 + V_99 ) ;
case V_100 :
return F_26 ( V_93 , V_69 + V_101 ) ;
case V_102 :
return F_26 ( V_93 , V_69 + V_103 ) ;
case V_104 :
return F_26 ( V_93 , V_69 + V_105 ) ;
default:
F_54 ( V_49 -> V_27 -> V_28 ,
L_9 , V_67 ) ;
return;
}
} else if ( V_69 == ( V_49 -> V_13 + 0x80 ) ) {
return F_26 ( V_93 , V_69 + V_67 ) ;
}
F_54 ( V_49 -> V_27 -> V_28 ,
L_10 ,
( int ) ( V_69 - V_49 -> V_13 ) ) ;
}
static int F_59 ( struct V_107 * V_108 )
{
struct V_109 V_110 ;
struct V_111 V_112 ;
struct V_3 * V_4 ;
struct V_113 * V_114 = V_108 -> V_115 . V_116 ;
int V_48 ;
if ( ! V_114 ) {
F_54 ( & V_108 -> V_115 , L_11 ) ;
return - V_117 ;
}
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
switch ( F_60 ( & V_108 -> V_115 ) ) {
#if V_118 V_119 || V_118 V_120
case V_121 :
V_110 . V_122 = V_123 ;
break;
#endif
#if V_118 V_119 || V_118 V_124
case V_125 :
V_110 . V_122 = V_126 ;
break;
#endif
#ifdef V_119
case V_127 :
V_110 . V_122 = V_128 ;
break;
#endif
default:
F_54 ( & V_108 -> V_115 , L_12 ) ;
return - V_117 ;
}
V_110 . V_129 = & V_130 ;
V_110 . V_131 = & V_132 ;
V_4 = F_61 ( & V_108 -> V_115 , sizeof( * V_4 ) , V_133 ) ;
if ( ! V_4 )
return - V_134 ;
V_4 -> V_115 = & V_108 -> V_115 ;
F_62 ( & V_4 -> V_2 , F_1 ) ;
V_4 -> V_46 . V_135 = F_28 ;
if ( F_63 ( V_114 , L_13 ) )
F_7 ( V_50 , & V_4 -> V_8 ) ;
if ( F_63 ( V_114 , L_14 ) )
F_7 ( V_53 , & V_4 -> V_8 ) ;
if ( F_63 ( V_114 , L_15 ) ) {
F_7 ( V_53 , & V_4 -> V_8 ) ;
F_7 ( V_85 , & V_4 -> V_8 ) ;
}
V_4 -> V_51 = F_64 ( & V_108 -> V_115 , NULL ) ;
if ( F_65 ( V_4 -> V_51 ) ) {
F_54 ( & V_108 -> V_115 , L_16 ,
F_66 ( V_4 -> V_51 ) ) ;
return F_66 ( V_4 -> V_51 ) ;
}
if ( F_3 ( V_53 , & V_4 -> V_8 ) ) {
V_4 -> V_54 = F_67 ( & V_108 -> V_115 , NULL ) ;
if ( F_65 ( V_4 -> V_54 ) ) {
if ( F_66 ( V_4 -> V_54 ) == - V_136 )
return - V_136 ;
F_54 ( & V_108 -> V_115 , L_17 ,
F_66 ( V_4 -> V_54 ) ) ;
return F_66 ( V_4 -> V_54 ) ;
}
}
V_4 -> V_58 = F_68 ( & V_108 -> V_115 , 0 ) ;
if ( F_65 ( V_4 -> V_58 ) ) {
if ( F_66 ( V_4 -> V_58 ) == - V_136 )
return - V_136 ;
F_54 ( & V_108 -> V_115 , L_18 ) ;
return F_66 ( V_4 -> V_58 ) ;
}
V_4 -> V_25 = F_69 ( & V_108 -> V_115 , L_19 ) ;
if ( F_65 ( V_4 -> V_25 ) ) {
if ( F_66 ( V_4 -> V_25 ) == - V_136 )
return - V_136 ;
F_54 ( & V_108 -> V_115 , L_20 ,
F_66 ( V_4 -> V_25 ) ) ;
return F_66 ( V_4 -> V_25 ) ;
}
V_4 -> V_137 = F_70 () ;
if ( F_65 ( V_4 -> V_137 ) ) {
F_54 ( & V_108 -> V_115 , L_21 ,
F_66 ( V_4 -> V_137 ) ) ;
return F_66 ( V_4 -> V_137 ) ;
}
V_4 -> V_17 = F_71 ( & V_108 -> V_115 , V_138 ) ;
if ( F_65 ( V_4 -> V_17 ) ) {
V_48 = F_66 ( V_4 -> V_17 ) ;
F_54 ( & V_108 -> V_115 , L_22 , V_48 ) ;
goto V_139;
}
F_72 ( V_108 , V_4 ) ;
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
V_112 . V_140 = L_23 ;
V_112 . V_141 = V_142 ;
V_112 . V_28 = & V_108 -> V_115 ;
V_112 . V_143 = V_108 -> V_144 ;
V_112 . V_145 = V_108 -> V_146 ;
V_112 . V_93 = & V_110 ;
V_112 . V_147 = sizeof( V_110 ) ;
V_4 -> V_148 = F_73 ( & V_112 ) ;
if ( F_65 ( V_4 -> V_148 ) ) {
V_48 = F_66 ( V_4 -> V_148 ) ;
F_54 ( & V_108 -> V_115 , L_24 , V_48 ) ;
goto V_139;
}
return 0 ;
V_139:
F_74 ( V_4 -> V_137 ) ;
return V_48 ;
}
static int F_75 ( struct V_107 * V_108 )
{
struct V_3 * V_4 = F_76 ( V_108 ) ;
struct V_107 * V_137 = V_4 -> V_137 ;
F_77 ( V_4 -> V_148 ) ;
F_74 ( V_137 ) ;
return 0 ;
}
