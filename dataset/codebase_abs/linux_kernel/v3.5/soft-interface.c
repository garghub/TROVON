int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
F_3 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 )
{
F_5 ( V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
F_7 ( V_6 ) ;
return 0 ;
}
static struct V_7 * F_8 ( struct V_5 * V_6 )
{
struct V_8 * V_8 = F_9 ( V_6 ) ;
return & V_8 -> V_9 ;
}
static int F_10 ( struct V_5 * V_6 , void * V_10 )
{
struct V_8 * V_8 = F_9 ( V_6 ) ;
struct V_11 * V_12 = V_10 ;
if ( ! F_11 ( V_12 -> V_13 ) )
return - V_14 ;
if ( F_12 ( & V_8 -> V_15 ) == V_16 ) {
F_13 ( V_8 , V_6 -> V_17 ,
L_1 , false ) ;
F_14 ( V_6 , V_12 -> V_13 , V_18 ) ;
}
memcpy ( V_6 -> V_17 , V_12 -> V_13 , V_19 ) ;
V_6 -> V_20 &= ~ V_21 ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 , int V_22 )
{
if ( ( V_22 < 68 ) || ( V_22 > F_16 ( V_6 ) ) )
return - V_23 ;
V_6 -> V_24 = V_22 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_5 * V_25 )
{
struct V_26 * V_26 = (struct V_26 * ) V_2 -> V_27 ;
struct V_8 * V_8 = F_9 ( V_25 ) ;
struct V_28 * V_29 = NULL ;
struct V_30 * V_30 ;
struct V_31 * V_32 ;
static const T_1 V_33 [ V_19 ] = { 0x01 , 0x80 , 0xC2 , 0x00 , 0x00 ,
0x00 } ;
unsigned int V_34 = 0 ;
int V_35 = V_2 -> V_3 , V_36 ;
short T_2 V_37 = - 1 ;
bool V_38 = false ;
if ( F_12 ( & V_8 -> V_15 ) != V_16 )
goto V_39;
V_25 -> V_40 = V_41 ;
switch ( F_18 ( V_26 -> V_42 ) ) {
case V_43 :
V_32 = (struct V_31 * ) V_2 -> V_27 ;
T_2 = F_18 ( V_32 -> V_44 ) & V_45 ;
if ( F_18 ( V_32 -> V_46 ) != V_47 )
break;
case V_47 :
goto V_39;
}
if ( F_19 ( V_8 , V_2 , T_2 ) )
goto V_39;
F_14 ( V_25 , V_26 -> V_48 , V_2 -> V_49 ) ;
if ( F_20 ( V_26 -> V_50 , V_33 ) )
goto V_39;
if ( F_21 ( V_26 -> V_50 ) ) {
V_38 = true ;
switch ( F_12 ( & V_8 -> V_51 ) ) {
case V_52 :
V_36 = F_22 ( V_2 , & V_34 ) ;
if ( V_36 )
goto V_39;
break;
case V_53 :
V_36 = F_22 ( V_2 , & V_34 ) ;
if ( V_36 )
V_38 = false ;
break;
case V_54 :
default:
break;
}
}
if ( V_38 ) {
V_29 = F_23 ( V_8 ) ;
if ( ! V_29 )
goto V_39;
if ( F_1 ( V_2 , sizeof( * V_30 ) ) < 0 )
goto V_39;
V_30 = (struct V_30 * ) V_2 -> V_27 ;
V_30 -> V_55 . V_56 = V_57 ;
V_30 -> V_55 . V_58 = V_59 ;
V_30 -> V_55 . V_60 = V_61 ;
memcpy ( V_30 -> V_62 ,
V_29 -> V_63 -> V_17 , V_19 ) ;
V_30 -> V_64 =
F_24 ( F_25 ( & V_8 -> V_65 ) ) ;
F_26 ( V_8 , V_2 , 1 ) ;
F_27 ( V_2 ) ;
} else {
if ( F_12 ( & V_8 -> V_51 ) != V_54 ) {
V_36 = F_28 ( V_8 , V_2 , V_26 ) ;
if ( V_36 )
goto V_39;
}
V_36 = F_29 ( V_2 , V_8 ) ;
if ( V_36 != 0 )
goto V_66;
}
V_8 -> V_9 . V_67 ++ ;
V_8 -> V_9 . V_68 += V_35 ;
goto V_69;
V_39:
F_27 ( V_2 ) ;
V_66:
V_8 -> V_9 . V_70 ++ ;
V_69:
if ( V_29 )
F_30 ( V_29 ) ;
return V_71 ;
}
void F_31 ( struct V_5 * V_25 ,
struct V_1 * V_2 , struct V_28 * V_72 ,
int V_73 )
{
struct V_8 * V_8 = F_9 ( V_25 ) ;
struct V_26 * V_26 ;
struct V_31 * V_32 ;
struct V_74 * V_75 = (struct V_74 * ) V_2 -> V_27 ;
short T_2 V_37 = - 1 ;
bool V_76 ;
V_76 = ( V_75 -> V_60 == V_61 ) ;
if ( ! F_32 ( V_2 , V_73 ) )
goto V_39;
F_33 ( V_2 , V_73 ) ;
F_34 ( V_2 ) ;
V_26 = (struct V_26 * ) F_35 ( V_2 ) ;
switch ( F_18 ( V_26 -> V_42 ) ) {
case V_43 :
V_32 = (struct V_31 * ) V_2 -> V_27 ;
T_2 = F_18 ( V_32 -> V_44 ) & V_45 ;
if ( F_18 ( V_32 -> V_46 ) != V_47 )
break;
case V_47 :
goto V_39;
}
if ( F_36 ( ! F_32 ( V_2 , V_77 ) ) )
goto V_39;
V_2 -> V_78 = F_37 ( V_2 , V_25 ) ;
V_8 -> V_9 . V_79 ++ ;
V_8 -> V_9 . V_80 += V_2 -> V_3 + V_77 ;
V_25 -> V_81 = V_41 ;
if ( F_38 ( V_8 , V_26 -> V_48 , V_26 -> V_50 ) )
goto V_39;
if ( F_39 ( V_8 , V_2 , T_2 , V_76 ) )
goto V_82;
F_40 ( V_2 ) ;
goto V_82;
V_39:
F_27 ( V_2 ) ;
V_82:
return;
}
static void F_41 ( struct V_5 * V_6 )
{
struct V_8 * V_83 = F_9 ( V_6 ) ;
F_42 ( V_6 ) ;
V_6 -> V_84 = & V_85 ;
V_6 -> V_86 = V_87 ;
V_6 -> V_88 = 0 ;
V_6 -> V_24 = V_89 ;
V_6 -> V_90 = V_91 ;
F_43 ( V_6 ) ;
F_44 ( V_6 , & V_92 ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
}
struct V_5 * F_45 ( const char * V_93 )
{
struct V_5 * V_25 ;
struct V_8 * V_8 ;
int V_36 ;
V_25 = F_46 ( sizeof( * V_8 ) , V_93 , F_41 ) ;
if ( ! V_25 )
goto V_82;
V_36 = F_47 ( V_25 ) ;
if ( V_36 < 0 ) {
F_48 ( L_2 ,
V_93 , V_36 ) ;
goto V_94;
}
V_8 = F_9 ( V_25 ) ;
F_49 ( & V_8 -> V_95 , 1 ) ;
F_49 ( & V_8 -> V_96 , 0 ) ;
F_49 ( & V_8 -> V_97 , 0 ) ;
F_49 ( & V_8 -> V_98 , 0 ) ;
F_49 ( & V_8 -> V_99 , V_100 ) ;
F_49 ( & V_8 -> V_51 , V_54 ) ;
F_49 ( & V_8 -> V_101 , 20 ) ;
F_49 ( & V_8 -> V_102 , 41 ) ;
F_49 ( & V_8 -> V_103 , 1000 ) ;
F_49 ( & V_8 -> V_104 , 30 ) ;
F_49 ( & V_8 -> V_105 , 0 ) ;
F_49 ( & V_8 -> V_106 , 1 ) ;
F_49 ( & V_8 -> V_107 , V_108 ) ;
F_49 ( & V_8 -> V_109 , V_110 ) ;
F_49 ( & V_8 -> V_15 , V_111 ) ;
F_49 ( & V_8 -> V_65 , 1 ) ;
F_49 ( & V_8 -> V_112 , 0 ) ;
F_49 ( & V_8 -> V_113 , 0 ) ;
F_49 ( & V_8 -> V_114 , 0 ) ;
F_49 ( & V_8 -> V_115 , 0 ) ;
V_8 -> V_116 = NULL ;
V_8 -> V_117 = 0 ;
V_8 -> V_118 = false ;
V_8 -> V_29 = NULL ;
V_8 -> V_119 = 0 ;
V_36 = F_50 ( V_8 , V_120 ) ;
if ( V_36 < 0 )
goto V_121;
V_36 = F_51 ( V_25 ) ;
if ( V_36 < 0 )
goto V_121;
V_36 = F_52 ( V_25 ) ;
if ( V_36 < 0 )
goto V_122;
V_36 = F_53 ( V_25 ) ;
if ( V_36 < 0 )
goto V_123;
return V_25 ;
V_123:
F_54 ( V_25 ) ;
V_122:
F_55 ( V_25 ) ;
V_121:
F_56 ( V_25 ) ;
return NULL ;
V_94:
V_87 ( V_25 ) ;
V_82:
return NULL ;
}
void F_57 ( struct V_5 * V_25 )
{
F_54 ( V_25 ) ;
F_55 ( V_25 ) ;
F_58 ( V_25 ) ;
F_56 ( V_25 ) ;
}
int F_59 ( const struct V_5 * V_63 )
{
if ( V_63 -> V_84 -> V_124 == F_17 )
return 1 ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 , struct V_125 * V_126 )
{
V_126 -> V_127 = 0 ;
V_126 -> V_128 = 0 ;
F_61 ( V_126 , V_129 ) ;
V_126 -> V_130 = V_131 ;
V_126 -> V_132 = V_133 ;
V_126 -> V_134 = 0 ;
V_126 -> V_135 = V_136 ;
V_126 -> V_137 = V_138 ;
V_126 -> V_139 = 0 ;
V_126 -> V_140 = 0 ;
return 0 ;
}
static void F_62 ( struct V_5 * V_6 ,
struct V_141 * V_142 )
{
strcpy ( V_142 -> V_143 , L_3 ) ;
strcpy ( V_142 -> V_56 , V_144 ) ;
strcpy ( V_142 -> V_145 , L_4 ) ;
strcpy ( V_142 -> V_146 , L_5 ) ;
}
static T_3 F_63 ( struct V_5 * V_6 )
{
return - V_147 ;
}
static void F_64 ( struct V_5 * V_6 , T_3 V_148 )
{
}
static T_3 F_65 ( struct V_5 * V_6 )
{
return 1 ;
}
