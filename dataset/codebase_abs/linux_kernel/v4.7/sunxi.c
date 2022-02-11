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
if ( V_10 -> V_58 == V_59 ) {
V_48 = F_33 ( V_4 -> V_60 , V_61 ,
& V_4 -> V_46 ) ;
if ( V_48 )
goto V_62;
}
V_48 = F_34 ( V_4 -> V_25 ) ;
if ( V_48 )
goto V_63;
V_10 -> V_64 = F_21 ;
F_35 ( V_10 -> V_27 ) ;
return 0 ;
V_63:
if ( V_10 -> V_58 == V_59 )
F_36 ( V_4 -> V_60 , V_61 ,
& V_4 -> V_46 ) ;
V_62:
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
if ( V_10 -> V_58 == V_59 )
F_36 ( V_4 -> V_60 , V_61 ,
& V_4 -> V_46 ) ;
if ( F_3 ( V_53 , & V_4 -> V_8 ) )
F_37 ( V_4 -> V_54 ) ;
F_38 ( V_4 -> V_51 ) ;
if ( F_3 ( V_50 , & V_4 -> V_8 ) )
F_39 ( V_10 -> V_27 -> V_28 ) ;
return 0 ;
}
static int F_44 ( struct V_10 * V_10 , T_1 V_65 )
{
struct V_3 * V_4 = F_16 ( V_10 -> V_27 -> V_28 ) ;
int V_48 ;
if ( V_65 == V_66 ) {
V_48 = F_13 ( V_4 -> V_25 ) ;
if ( V_48 )
return V_48 ;
F_7 ( V_24 , & V_4 -> V_8 ) ;
F_7 ( V_16 , & V_4 -> V_8 ) ;
V_10 -> V_17 -> V_18 -> V_20 = V_21 ;
}
return 0 ;
}
static void F_45 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_16 ( V_10 -> V_27 -> V_28 ) ;
V_4 -> V_10 = V_10 ;
if ( F_46 ( V_7 , & V_4 -> V_8 ) )
return;
F_17 ( & V_4 -> V_2 ) ;
}
static void F_47 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = F_16 ( V_10 -> V_27 -> V_28 ) ;
F_9 ( V_7 , & V_4 -> V_8 ) ;
}
struct V_67 * F_48 ( struct V_10 * V_10 ,
void T_3 * V_68 )
{
return NULL ;
}
void F_49 ( struct V_67 * V_69 )
{
}
static T_4 F_50 ( T_1 V_70 )
{
return ( V_70 * 4 ) ;
}
static T_4 F_51 ( T_1 V_70 , T_5 V_71 )
{
F_52 ( V_71 != 0 ,
L_1 ) ;
return 0x80 ;
}
static T_4 F_53 ( T_1 V_70 , T_5 V_71 )
{
return V_72 + V_71 ;
}
static T_1 F_54 ( const void T_3 * V_73 , unsigned V_71 )
{
struct V_3 * V_4 ;
if ( V_73 == V_49 -> V_13 ) {
switch ( V_71 ) {
case V_36 :
return F_6 ( V_73 + V_74 ) ;
case V_75 :
return F_6 ( V_73 + V_76 ) ;
case V_77 :
return F_6 ( V_73 + V_32 ) ;
case V_78 :
return F_6 ( V_73 + V_79 ) ;
case V_80 :
return F_6 ( V_73 + V_81 ) ;
case V_82 :
return 0 ;
case V_83 :
return F_6 ( V_73 + V_14 ) ;
case V_84 :
return F_6 ( V_73 + V_85 ) ;
case V_86 :
return F_6 ( V_73 + V_87 ) ;
case V_88 + 0x10 :
V_4 = F_16 ( V_49 -> V_27 -> V_28 ) ;
if ( F_3 ( V_89 ,
& V_4 -> V_8 ) )
return 0xde ;
return F_6 ( V_73 + V_90 ) ;
case V_72 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
return F_6 ( V_73 + V_71 ) ;
default:
F_55 ( V_49 -> V_27 -> V_28 ,
L_2 , V_71 ) ;
return 0 ;
}
} else if ( V_73 == ( V_49 -> V_13 + 0x80 ) ) {
if ( V_71 >= V_96 )
V_71 += 2 ;
return F_6 ( V_73 + V_71 ) ;
}
F_55 ( V_49 -> V_27 -> V_28 ,
L_3 ,
( int ) ( V_73 - V_49 -> V_13 ) ) ;
return 0 ;
}
static void F_56 ( void T_3 * V_73 , unsigned V_71 , T_1 V_97 )
{
if ( V_73 == V_49 -> V_13 ) {
switch ( V_71 ) {
case V_36 :
return F_11 ( V_97 , V_73 + V_74 ) ;
case V_75 :
return F_11 ( V_97 , V_73 + V_76 ) ;
case V_77 :
return F_11 ( V_97 , V_73 + V_32 ) ;
case V_78 :
return F_11 ( V_97 , V_73 + V_79 ) ;
case V_80 :
return F_11 ( V_97 , V_73 + V_81 ) ;
case V_82 :
if ( V_97 )
F_57 ( V_49 -> V_27 -> V_28 ,
L_4 ) ;
return;
case V_83 :
return F_11 ( V_97 , V_73 + V_14 ) ;
case V_84 :
return F_11 ( V_97 , V_73 + V_85 ) ;
case V_86 :
return F_11 ( V_97 , V_73 + V_87 ) ;
case V_72 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
return F_11 ( V_97 , V_73 + V_71 ) ;
default:
F_55 ( V_49 -> V_27 -> V_28 ,
L_5 , V_71 ) ;
return;
}
} else if ( V_73 == ( V_49 -> V_13 + 0x80 ) ) {
if ( V_71 >= V_96 )
V_71 += 2 ;
return F_11 ( V_97 , V_73 + V_71 ) ;
}
F_55 ( V_49 -> V_27 -> V_28 ,
L_6 ,
( int ) ( V_73 - V_49 -> V_13 ) ) ;
}
static T_5 F_58 ( const void T_3 * V_73 , unsigned V_71 )
{
if ( V_73 == V_49 -> V_13 ) {
switch ( V_71 ) {
case V_98 :
return F_25 ( V_73 + V_38 ) ;
case V_99 :
return F_25 ( V_73 + V_40 ) ;
case V_100 :
return F_25 ( V_73 + V_101 ) ;
case V_102 :
return F_25 ( V_73 + V_103 ) ;
case V_104 :
return F_25 ( V_73 + V_105 ) ;
case V_106 :
return F_25 ( V_73 + V_107 ) ;
case V_108 :
return F_25 ( V_73 + V_109 ) ;
case V_110 :
return 0 ;
default:
F_55 ( V_49 -> V_27 -> V_28 ,
L_7 , V_71 ) ;
return 0 ;
}
} else if ( V_73 == ( V_49 -> V_13 + 0x80 ) ) {
return F_25 ( V_73 + V_71 ) ;
}
F_55 ( V_49 -> V_27 -> V_28 ,
L_8 ,
( int ) ( V_73 - V_49 -> V_13 ) ) ;
return 0 ;
}
static void F_59 ( void T_3 * V_73 , unsigned V_71 , T_5 V_97 )
{
if ( V_73 == V_49 -> V_13 ) {
switch ( V_71 ) {
case V_98 :
return F_26 ( V_97 , V_73 + V_38 ) ;
case V_99 :
return F_26 ( V_97 , V_73 + V_40 ) ;
case V_100 :
return F_26 ( V_97 , V_73 + V_101 ) ;
case V_102 :
return F_26 ( V_97 , V_73 + V_103 ) ;
case V_104 :
return F_26 ( V_97 , V_73 + V_105 ) ;
case V_106 :
return F_26 ( V_97 , V_73 + V_107 ) ;
case V_108 :
return F_26 ( V_97 , V_73 + V_109 ) ;
default:
F_55 ( V_49 -> V_27 -> V_28 ,
L_9 , V_71 ) ;
return;
}
} else if ( V_73 == ( V_49 -> V_13 + 0x80 ) ) {
return F_26 ( V_97 , V_73 + V_71 ) ;
}
F_55 ( V_49 -> V_27 -> V_28 ,
L_10 ,
( int ) ( V_73 - V_49 -> V_13 ) ) ;
}
static int F_60 ( struct V_111 * V_112 )
{
struct V_113 V_114 ;
struct V_115 V_116 ;
struct V_3 * V_4 ;
struct V_117 * V_118 = V_112 -> V_119 . V_120 ;
int V_48 ;
if ( ! V_118 ) {
F_55 ( & V_112 -> V_119 , L_11 ) ;
return - V_121 ;
}
V_4 = F_61 ( & V_112 -> V_119 , sizeof( * V_4 ) , V_122 ) ;
if ( ! V_4 )
return - V_123 ;
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
switch ( F_62 ( & V_112 -> V_119 ) ) {
#if V_124 V_125 || V_124 V_126
case V_127 :
V_114 . V_65 = V_128 ;
break;
#endif
#ifdef V_125
case V_129 :
V_4 -> V_60 = F_63 ( & V_112 -> V_119 , 0 ) ;
if ( F_64 ( V_4 -> V_60 ) ) {
if ( F_65 ( V_4 -> V_60 ) == - V_130 )
return - V_130 ;
F_55 ( & V_112 -> V_119 , L_12 ) ;
return F_65 ( V_4 -> V_60 ) ;
}
V_114 . V_65 = V_59 ;
break;
#endif
default:
F_55 ( & V_112 -> V_119 , L_13 ) ;
return - V_121 ;
}
V_114 . V_131 = & V_132 ;
V_114 . V_133 = & V_134 ;
V_4 -> V_119 = & V_112 -> V_119 ;
F_66 ( & V_4 -> V_2 , F_1 ) ;
V_4 -> V_46 . V_135 = F_28 ;
if ( F_67 ( V_118 , L_14 ) )
F_7 ( V_50 , & V_4 -> V_8 ) ;
if ( F_67 ( V_118 , L_15 ) )
F_7 ( V_53 , & V_4 -> V_8 ) ;
if ( F_67 ( V_118 , L_16 ) ) {
F_7 ( V_53 , & V_4 -> V_8 ) ;
F_7 ( V_89 , & V_4 -> V_8 ) ;
}
V_4 -> V_51 = F_68 ( & V_112 -> V_119 , NULL ) ;
if ( F_64 ( V_4 -> V_51 ) ) {
F_55 ( & V_112 -> V_119 , L_17 ,
F_65 ( V_4 -> V_51 ) ) ;
return F_65 ( V_4 -> V_51 ) ;
}
if ( F_3 ( V_53 , & V_4 -> V_8 ) ) {
V_4 -> V_54 = F_69 ( & V_112 -> V_119 , NULL ) ;
if ( F_64 ( V_4 -> V_54 ) ) {
if ( F_65 ( V_4 -> V_54 ) == - V_130 )
return - V_130 ;
F_55 ( & V_112 -> V_119 , L_18 ,
F_65 ( V_4 -> V_54 ) ) ;
return F_65 ( V_4 -> V_54 ) ;
}
}
V_4 -> V_25 = F_70 ( & V_112 -> V_119 , L_19 ) ;
if ( F_64 ( V_4 -> V_25 ) ) {
if ( F_65 ( V_4 -> V_25 ) == - V_130 )
return - V_130 ;
F_55 ( & V_112 -> V_119 , L_20 ,
F_65 ( V_4 -> V_25 ) ) ;
return F_65 ( V_4 -> V_25 ) ;
}
V_4 -> V_136 = F_71 () ;
if ( F_64 ( V_4 -> V_136 ) ) {
F_55 ( & V_112 -> V_119 , L_21 ,
F_65 ( V_4 -> V_136 ) ) ;
return F_65 ( V_4 -> V_136 ) ;
}
V_4 -> V_17 = F_72 ( & V_112 -> V_119 , V_137 ) ;
if ( F_64 ( V_4 -> V_17 ) ) {
V_48 = F_65 ( V_4 -> V_17 ) ;
F_55 ( & V_112 -> V_119 , L_22 , V_48 ) ;
goto V_138;
}
F_73 ( V_112 , V_4 ) ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_139 = L_23 ;
V_116 . V_140 = V_141 ;
V_116 . V_28 = & V_112 -> V_119 ;
V_116 . V_142 = V_112 -> V_143 ;
V_116 . V_144 = V_112 -> V_145 ;
V_116 . V_97 = & V_114 ;
V_116 . V_146 = sizeof( V_114 ) ;
V_4 -> V_147 = F_74 ( & V_116 ) ;
if ( F_64 ( V_4 -> V_147 ) ) {
V_48 = F_65 ( V_4 -> V_147 ) ;
F_55 ( & V_112 -> V_119 , L_24 , V_48 ) ;
goto V_138;
}
return 0 ;
V_138:
F_75 ( V_4 -> V_136 ) ;
return V_48 ;
}
static int F_76 ( struct V_111 * V_112 )
{
struct V_3 * V_4 = F_77 ( V_112 ) ;
struct V_111 * V_136 = V_4 -> V_136 ;
F_78 ( V_4 -> V_147 ) ;
F_75 ( V_136 ) ;
return 0 ;
}
