static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
bool V_5 , V_6 ;
if ( ! F_3 ( V_7 , & V_4 -> V_8 ) )
return;
if ( F_4 ( V_9 , & V_4 -> V_8 ) ) {
struct V_10 * V_10 = F_5 ( V_4 -> V_10 ) ;
unsigned long V_8 ;
T_1 V_11 ;
F_6 ( & V_10 -> V_12 , V_8 ) ;
V_11 = F_7 ( V_10 -> V_13 + V_14 ) ;
if ( F_3 ( V_15 , & V_4 -> V_8 ) ) {
F_8 ( V_16 , & V_4 -> V_8 ) ;
V_10 -> V_17 -> V_18 -> V_19 = 1 ;
V_10 -> V_17 -> V_18 -> V_20 = V_21 ;
F_9 ( V_10 ) ;
V_11 |= V_22 ;
} else {
F_10 ( V_16 , & V_4 -> V_8 ) ;
V_10 -> V_17 -> V_18 -> V_19 = 0 ;
V_10 -> V_17 -> V_18 -> V_20 = V_23 ;
F_11 ( V_10 ) ;
V_11 &= ~ V_22 ;
}
F_12 ( V_11 , V_10 -> V_13 + V_14 ) ;
F_13 ( & V_10 -> V_12 , V_8 ) ;
}
V_5 = F_3 ( V_16 , & V_4 -> V_8 ) ;
V_6 = F_3 ( V_24 , & V_4 -> V_8 ) ;
if ( V_6 != V_5 ) {
if ( V_5 ) {
F_14 ( V_4 -> V_25 ) ;
F_8 ( V_24 , & V_4 -> V_8 ) ;
} else {
F_15 ( V_4 -> V_25 ) ;
F_10 ( V_24 , & V_4 -> V_8 ) ;
}
}
}
static void F_16 ( struct V_10 * V_10 , int V_26 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_27 -> V_28 ) ;
if ( V_26 )
F_8 ( V_16 , & V_4 -> V_8 ) ;
else
F_10 ( V_16 , & V_4 -> V_8 ) ;
F_18 ( & V_4 -> V_2 ) ;
}
static void F_19 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_27 -> V_28 ) ;
F_20 ( V_4 -> V_25 , false ) ;
}
static void F_21 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_27 -> V_28 ) ;
F_20 ( V_4 -> V_25 , true ) ;
}
static T_2 F_22 ( int V_29 , void * V_30 )
{
struct V_10 * V_10 = V_30 ;
unsigned long V_8 ;
F_6 ( & V_10 -> V_12 , V_8 ) ;
V_10 -> V_31 = F_7 ( V_10 -> V_13 + V_32 ) ;
if ( V_10 -> V_31 )
F_12 ( V_10 -> V_31 , V_10 -> V_13 + V_32 ) ;
if ( ( V_10 -> V_31 & V_33 ) && F_23 ( V_10 ) ) {
V_10 -> V_31 &= ~ V_33 ;
V_10 -> V_31 |= V_34 ;
}
if ( ( V_10 -> V_31 & V_35 ) && ! F_23 ( V_10 ) ) {
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
F_13 ( & V_10 -> V_12 , V_8 ) ;
return V_41 ;
}
static int F_29 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
struct V_3 * V_4 = F_2 ( V_43 , struct V_3 , V_46 ) ;
if ( V_44 )
F_8 ( V_15 , & V_4 -> V_8 ) ;
else
F_10 ( V_15 , & V_4 -> V_8 ) ;
F_8 ( V_9 , & V_4 -> V_8 ) ;
F_18 ( & V_4 -> V_2 ) ;
return V_47 ;
}
static int F_30 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_27 -> V_28 ) ;
int V_48 ;
V_49 = V_10 ;
V_10 -> V_25 = V_4 -> V_25 ;
V_10 -> V_17 = V_4 -> V_17 ;
if ( F_3 ( V_50 , & V_4 -> V_8 ) ) {
V_48 = F_31 ( V_10 -> V_27 -> V_28 ) ;
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
F_12 ( V_56 , V_10 -> V_13 + V_57 ) ;
if ( V_10 -> V_58 == V_59 ) {
V_48 = F_34 ( V_4 -> V_60 , V_61 ,
& V_4 -> V_46 ) ;
if ( V_48 )
goto V_62;
}
V_48 = F_35 ( V_4 -> V_25 ) ;
if ( V_48 )
goto V_63;
if ( V_10 -> V_58 == V_64 ) {
V_48 = F_14 ( V_4 -> V_25 ) ;
if ( V_48 )
goto V_65;
F_8 ( V_24 , & V_4 -> V_8 ) ;
F_8 ( V_16 , & V_4 -> V_8 ) ;
}
V_10 -> V_66 = F_22 ;
F_36 ( V_10 -> V_27 ) ;
return 0 ;
V_65:
F_37 ( V_4 -> V_25 ) ;
V_63:
if ( V_10 -> V_58 == V_59 )
F_38 ( V_4 -> V_60 , V_61 ,
& V_4 -> V_46 ) ;
V_62:
if ( F_3 ( V_53 , & V_4 -> V_8 ) )
F_39 ( V_4 -> V_54 ) ;
V_55:
F_40 ( V_4 -> V_51 ) ;
V_52:
if ( F_3 ( V_50 , & V_4 -> V_8 ) )
F_41 ( V_10 -> V_27 -> V_28 ) ;
return V_48 ;
}
static int F_42 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_27 -> V_28 ) ;
F_43 ( V_10 -> V_27 ) ;
F_44 ( & V_4 -> V_2 ) ;
if ( F_3 ( V_24 , & V_4 -> V_8 ) )
F_15 ( V_4 -> V_25 ) ;
F_37 ( V_4 -> V_25 ) ;
if ( V_10 -> V_58 == V_59 )
F_38 ( V_4 -> V_60 , V_61 ,
& V_4 -> V_46 ) ;
if ( F_3 ( V_53 , & V_4 -> V_8 ) )
F_39 ( V_4 -> V_54 ) ;
F_40 ( V_4 -> V_51 ) ;
if ( F_3 ( V_50 , & V_4 -> V_8 ) )
F_41 ( V_10 -> V_27 -> V_28 ) ;
return 0 ;
}
static void F_45 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_27 -> V_28 ) ;
if ( F_46 ( V_7 , & V_4 -> V_8 ) )
return;
F_18 ( & V_4 -> V_2 ) ;
}
static void F_47 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 -> V_27 -> V_28 ) ;
F_10 ( V_7 , & V_4 -> V_8 ) ;
}
static T_3 F_48 ( T_1 V_67 )
{
return ( V_67 * 4 ) ;
}
static T_3 F_49 ( T_1 V_67 , T_4 V_68 )
{
F_50 ( V_68 != 0 ,
L_1 ) ;
return 0x80 ;
}
static T_3 F_51 ( T_1 V_67 , T_4 V_68 )
{
return V_69 + V_68 ;
}
static T_1 F_52 ( const void T_5 * V_70 , unsigned V_68 )
{
struct V_3 * V_4 ;
if ( V_70 == V_49 -> V_13 ) {
switch ( V_68 ) {
case V_36 :
return F_7 ( V_70 + V_71 ) ;
case V_72 :
return F_7 ( V_70 + V_73 ) ;
case V_74 :
return F_7 ( V_70 + V_32 ) ;
case V_75 :
return F_7 ( V_70 + V_76 ) ;
case V_77 :
return F_7 ( V_70 + V_78 ) ;
case V_79 :
return 0 ;
case V_80 :
return F_7 ( V_70 + V_14 ) ;
case V_81 :
return F_7 ( V_70 + V_82 ) ;
case V_83 :
return F_7 ( V_70 + V_84 ) ;
case V_85 + 0x10 :
V_4 = F_17 ( V_49 -> V_27 -> V_28 ) ;
if ( F_3 ( V_86 ,
& V_4 -> V_8 ) )
return 0xde ;
return F_7 ( V_70 + V_87 ) ;
case V_69 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
return F_7 ( V_70 + V_68 ) ;
default:
F_53 ( V_49 -> V_27 -> V_28 ,
L_2 , V_68 ) ;
return 0 ;
}
} else if ( V_70 == ( V_49 -> V_13 + 0x80 ) ) {
if ( V_68 >= V_93 )
V_68 += 2 ;
return F_7 ( V_70 + V_68 ) ;
}
F_53 ( V_49 -> V_27 -> V_28 ,
L_3 ,
( int ) ( V_70 - V_49 -> V_13 ) ) ;
return 0 ;
}
static void F_54 ( void T_5 * V_70 , unsigned V_68 , T_1 V_94 )
{
if ( V_70 == V_49 -> V_13 ) {
switch ( V_68 ) {
case V_36 :
return F_12 ( V_94 , V_70 + V_71 ) ;
case V_72 :
return F_12 ( V_94 , V_70 + V_73 ) ;
case V_74 :
return F_12 ( V_94 , V_70 + V_32 ) ;
case V_75 :
return F_12 ( V_94 , V_70 + V_76 ) ;
case V_77 :
return F_12 ( V_94 , V_70 + V_78 ) ;
case V_79 :
if ( V_94 )
F_55 ( V_49 -> V_27 -> V_28 ,
L_4 ) ;
return;
case V_80 :
return F_12 ( V_94 , V_70 + V_14 ) ;
case V_81 :
return F_12 ( V_94 , V_70 + V_82 ) ;
case V_83 :
return F_12 ( V_94 , V_70 + V_84 ) ;
case V_69 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
return F_12 ( V_94 , V_70 + V_68 ) ;
default:
F_53 ( V_49 -> V_27 -> V_28 ,
L_5 , V_68 ) ;
return;
}
} else if ( V_70 == ( V_49 -> V_13 + 0x80 ) ) {
if ( V_68 >= V_93 )
V_68 += 2 ;
return F_12 ( V_94 , V_70 + V_68 ) ;
}
F_53 ( V_49 -> V_27 -> V_28 ,
L_6 ,
( int ) ( V_70 - V_49 -> V_13 ) ) ;
}
static T_4 F_56 ( const void T_5 * V_70 , unsigned V_68 )
{
if ( V_70 == V_49 -> V_13 ) {
switch ( V_68 ) {
case V_95 :
return F_26 ( V_70 + V_38 ) ;
case V_96 :
return F_26 ( V_70 + V_40 ) ;
case V_97 :
return F_26 ( V_70 + V_98 ) ;
case V_99 :
return F_26 ( V_70 + V_100 ) ;
case V_101 :
return F_26 ( V_70 + V_102 ) ;
case V_103 :
return F_26 ( V_70 + V_104 ) ;
case V_105 :
return F_26 ( V_70 + V_106 ) ;
case V_107 :
return 0 ;
default:
F_53 ( V_49 -> V_27 -> V_28 ,
L_7 , V_68 ) ;
return 0 ;
}
} else if ( V_70 == ( V_49 -> V_13 + 0x80 ) ) {
return F_26 ( V_70 + V_68 ) ;
}
F_53 ( V_49 -> V_27 -> V_28 ,
L_8 ,
( int ) ( V_70 - V_49 -> V_13 ) ) ;
return 0 ;
}
static void F_57 ( void T_5 * V_70 , unsigned V_68 , T_4 V_94 )
{
if ( V_70 == V_49 -> V_13 ) {
switch ( V_68 ) {
case V_95 :
return F_27 ( V_94 , V_70 + V_38 ) ;
case V_96 :
return F_27 ( V_94 , V_70 + V_40 ) ;
case V_97 :
return F_27 ( V_94 , V_70 + V_98 ) ;
case V_99 :
return F_27 ( V_94 , V_70 + V_100 ) ;
case V_101 :
return F_27 ( V_94 , V_70 + V_102 ) ;
case V_103 :
return F_27 ( V_94 , V_70 + V_104 ) ;
case V_105 :
return F_27 ( V_94 , V_70 + V_106 ) ;
default:
F_53 ( V_49 -> V_27 -> V_28 ,
L_9 , V_68 ) ;
return;
}
} else if ( V_70 == ( V_49 -> V_13 + 0x80 ) ) {
return F_27 ( V_94 , V_70 + V_68 ) ;
}
F_53 ( V_49 -> V_27 -> V_28 ,
L_10 ,
( int ) ( V_70 - V_49 -> V_13 ) ) ;
}
static int F_58 ( struct V_108 * V_109 )
{
struct V_110 V_111 ;
struct V_112 V_113 ;
struct V_3 * V_4 ;
struct V_114 * V_115 = V_109 -> V_116 . V_117 ;
int V_48 ;
if ( ! V_115 ) {
F_53 ( & V_109 -> V_116 , L_11 ) ;
return - V_118 ;
}
V_4 = F_59 ( & V_109 -> V_116 , sizeof( * V_4 ) , V_119 ) ;
if ( ! V_4 )
return - V_120 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
switch ( F_60 ( V_115 ) ) {
#if V_121 V_122 || V_121 V_123
case V_124 :
V_111 . V_125 = V_64 ;
break;
#endif
#ifdef V_122
case V_126 :
V_4 -> V_60 = F_61 ( & V_109 -> V_116 , 0 ) ;
if ( F_62 ( V_4 -> V_60 ) ) {
if ( F_63 ( V_4 -> V_60 ) == - V_127 )
return - V_127 ;
F_53 ( & V_109 -> V_116 , L_12 ) ;
return F_63 ( V_4 -> V_60 ) ;
}
V_111 . V_125 = V_59 ;
break;
#endif
default:
F_53 ( & V_109 -> V_116 , L_13 ) ;
return - V_118 ;
}
V_111 . V_128 = & V_129 ;
V_111 . V_130 = & V_131 ;
V_4 -> V_116 = & V_109 -> V_116 ;
F_64 ( & V_4 -> V_2 , F_1 ) ;
V_4 -> V_46 . V_132 = F_29 ;
if ( F_65 ( V_115 , L_14 ) )
F_8 ( V_50 , & V_4 -> V_8 ) ;
if ( F_65 ( V_115 , L_15 ) )
F_8 ( V_53 , & V_4 -> V_8 ) ;
if ( F_65 ( V_115 , L_16 ) ) {
F_8 ( V_53 , & V_4 -> V_8 ) ;
F_8 ( V_86 , & V_4 -> V_8 ) ;
}
V_4 -> V_51 = F_66 ( & V_109 -> V_116 , NULL ) ;
if ( F_62 ( V_4 -> V_51 ) ) {
F_53 ( & V_109 -> V_116 , L_17 ,
F_63 ( V_4 -> V_51 ) ) ;
return F_63 ( V_4 -> V_51 ) ;
}
if ( F_3 ( V_53 , & V_4 -> V_8 ) ) {
V_4 -> V_54 = F_67 ( & V_109 -> V_116 , NULL ) ;
if ( F_62 ( V_4 -> V_54 ) ) {
if ( F_63 ( V_4 -> V_54 ) == - V_127 )
return - V_127 ;
F_53 ( & V_109 -> V_116 , L_18 ,
F_63 ( V_4 -> V_54 ) ) ;
return F_63 ( V_4 -> V_54 ) ;
}
}
V_4 -> V_25 = F_68 ( & V_109 -> V_116 , L_19 ) ;
if ( F_62 ( V_4 -> V_25 ) ) {
if ( F_63 ( V_4 -> V_25 ) == - V_127 )
return - V_127 ;
F_53 ( & V_109 -> V_116 , L_20 ,
F_63 ( V_4 -> V_25 ) ) ;
return F_63 ( V_4 -> V_25 ) ;
}
V_4 -> V_133 = F_69 () ;
if ( F_62 ( V_4 -> V_133 ) ) {
F_53 ( & V_109 -> V_116 , L_21 ,
F_63 ( V_4 -> V_133 ) ) ;
return F_63 ( V_4 -> V_133 ) ;
}
V_4 -> V_17 = F_70 ( & V_109 -> V_116 , V_134 ) ;
if ( F_62 ( V_4 -> V_17 ) ) {
V_48 = F_63 ( V_4 -> V_17 ) ;
F_53 ( & V_109 -> V_116 , L_22 , V_48 ) ;
goto V_135;
}
F_71 ( V_109 , V_4 ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_136 = L_23 ;
V_113 . V_137 = V_138 ;
V_113 . V_28 = & V_109 -> V_116 ;
V_113 . V_139 = V_109 -> V_140 ;
V_113 . V_141 = V_109 -> V_142 ;
V_113 . V_94 = & V_111 ;
V_113 . V_143 = sizeof( V_111 ) ;
V_4 -> V_10 = F_72 ( & V_113 ) ;
if ( F_62 ( V_4 -> V_10 ) ) {
V_48 = F_63 ( V_4 -> V_10 ) ;
F_53 ( & V_109 -> V_116 , L_24 , V_48 ) ;
goto V_135;
}
return 0 ;
V_135:
F_73 ( V_4 -> V_133 ) ;
return V_48 ;
}
static int F_74 ( struct V_108 * V_109 )
{
struct V_3 * V_4 = F_5 ( V_109 ) ;
struct V_108 * V_133 = V_4 -> V_133 ;
F_75 ( V_4 -> V_10 ) ;
F_73 ( V_133 ) ;
return 0 ;
}
