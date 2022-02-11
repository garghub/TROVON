static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_2 -> V_5 , V_6 , V_4 -> V_7 ) ;
F_2 ( V_2 -> V_5 , V_8 , V_4 -> V_9 ) ;
if ( V_4 -> V_10 )
F_2 ( V_2 -> V_5 , V_11 , - V_4 -> V_10 ) ;
F_3 ( V_2 -> V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
F_5 ( V_2 -> V_5 , V_14 , V_13 -> V_15 ) ;
F_5 ( V_2 -> V_5 , V_16 , V_13 -> V_17 ) ;
if ( V_13 -> V_10 )
F_2 ( V_2 -> V_5 , V_11 , - V_13 -> V_10 ) ;
F_3 ( V_2 -> V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 ;
int V_22 = V_19 -> V_23 ;
if ( F_7 ( V_19 -> V_24 , V_2 -> V_5 -> V_25 ) ) {
V_21 = V_2 -> V_5 ;
} else if ( F_7 ( V_19 -> V_24 , V_2 -> V_26 -> V_25 ) ) {
V_21 = V_2 -> V_26 ;
if ( V_19 -> V_23 && F_7 ( V_19 -> V_24 , V_2 -> V_26 -> V_19 ) )
V_22 = 2 ;
} else {
F_8 ( L_1 , V_19 -> V_24 ) ;
return;
}
F_9 ( V_21 , V_27 , V_19 -> V_24 , V_22 ) ;
F_3 ( V_21 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
if ( F_11 ( ! V_2 -> V_29 ) )
return;
if ( V_29 -> V_30 != V_2 -> V_31 ) {
V_2 -> V_31 = V_29 -> V_30 ;
F_12 ( V_2 -> V_29 , V_29 -> V_30 ) ;
}
switch ( V_29 -> V_32 ) {
case V_33 :
F_13 ( V_2 -> V_29 , V_34 , true ) ;
case V_35 :
F_5 ( V_2 -> V_29 , V_36 ,
V_29 -> V_37 . V_13 . V_15 ) ;
F_5 ( V_2 -> V_29 , V_38 ,
V_29 -> V_37 . V_13 . V_17 ) ;
break;
case V_39 :
F_5 ( V_2 -> V_29 , V_40 ,
V_29 -> V_37 . V_41 . V_42 ) ;
F_5 ( V_2 -> V_29 , V_43 ,
V_29 -> V_37 . V_41 . V_44 ) ;
break;
case V_45 :
F_5 ( V_2 -> V_29 , V_46 ,
V_29 -> V_37 . V_47 ) ;
break;
case V_48 :
F_13 ( V_2 -> V_29 , V_34 , false ) ;
break;
case V_49 :
F_14 ( V_2 -> V_29 ) ;
F_3 ( V_2 -> V_29 ) ;
break;
}
}
static void F_15 ( struct V_1 * V_2 ,
union V_50 * V_51 )
{
switch ( V_51 -> type ) {
case V_52 :
F_1 ( V_2 , & V_51 -> V_4 ) ;
break;
case V_53 :
F_6 ( V_2 , & V_51 -> V_19 ) ;
break;
case V_54 :
F_4 ( V_2 , & V_51 -> V_13 ) ;
break;
case V_55 :
F_10 ( V_2 , & V_51 -> V_29 ) ;
break;
}
}
static T_1 F_16 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
struct V_58 * V_59 = V_2 -> V_59 ;
T_2 V_60 , V_61 ;
V_61 = V_59 -> V_62 ;
if ( V_61 == V_59 -> V_63 )
return V_64 ;
F_17 () ;
for ( V_60 = V_59 -> V_63 ; V_60 != V_61 ; V_60 ++ )
F_15 ( V_2 , & F_18 ( V_59 , V_60 ) ) ;
F_19 () ;
V_59 -> V_63 = V_60 ;
F_20 ( V_2 -> V_65 ) ;
return V_64 ;
}
static int F_21 ( struct V_66 * V_21 ,
const struct V_67 * V_68 )
{
int V_69 , V_70 ;
unsigned int abs , V_71 ;
struct V_1 * V_2 ;
struct V_20 * V_26 , * V_5 , * V_29 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_72 ) ;
if ( ! V_2 ) {
F_23 ( V_21 , - V_73 , L_2 ) ;
return - V_73 ;
}
F_24 ( & V_21 -> V_21 , V_2 ) ;
V_2 -> V_74 = V_21 ;
V_2 -> V_65 = - 1 ;
V_2 -> V_75 = - 1 ;
snprintf ( V_2 -> V_76 , sizeof( V_2 -> V_76 ) , L_3 , V_21 -> V_77 ) ;
V_2 -> V_59 = ( void * ) F_25 ( V_72 | V_78 ) ;
if ( ! V_2 -> V_59 )
goto V_79;
abs = F_26 ( V_21 -> V_80 ,
V_81 , 0 ) ;
V_82 [ V_83 ] = F_26 ( V_21 -> V_80 ,
V_84 ,
V_82 [ V_83 ] ) ;
V_82 [ V_85 ] = F_26 ( V_21 -> V_80 ,
V_86 ,
V_82 [ V_85 ] ) ;
if ( abs ) {
V_69 = F_27 ( V_87 , V_21 -> V_77 ,
V_88 , L_4 ) ;
if ( V_69 ) {
F_8 ( L_5 ) ;
abs = 0 ;
}
}
V_71 = F_26 ( V_21 -> V_77 ,
V_89 , 0 ) ;
if ( V_71 ) {
V_69 = F_27 ( V_87 , V_21 -> V_77 ,
V_90 , L_4 ) ;
if ( V_69 ) {
F_8 ( L_6 ) ;
V_71 = 0 ;
}
}
V_26 = F_28 () ;
if ( ! V_26 )
goto V_79;
V_26 -> V_91 = L_7 ;
V_26 -> V_76 = V_2 -> V_76 ;
V_26 -> V_68 . V_92 = V_93 ;
V_26 -> V_68 . V_94 = 0x5853 ;
V_26 -> V_68 . V_95 = 0xffff ;
F_29 ( V_27 , V_26 -> V_96 ) ;
for ( V_70 = V_97 ; V_70 < V_98 ; V_70 ++ )
F_29 ( V_70 , V_26 -> V_25 ) ;
for ( V_70 = V_99 ; V_70 < V_100 ; V_70 ++ )
F_29 ( V_70 , V_26 -> V_25 ) ;
V_69 = F_30 ( V_26 ) ;
if ( V_69 ) {
F_31 ( V_26 ) ;
F_23 ( V_21 , V_69 , L_8 ) ;
goto error;
}
V_2 -> V_26 = V_26 ;
V_5 = F_28 () ;
if ( ! V_5 )
goto V_79;
V_5 -> V_91 = L_9 ;
V_5 -> V_76 = V_2 -> V_76 ;
V_5 -> V_68 . V_92 = V_93 ;
V_5 -> V_68 . V_94 = 0x5853 ;
V_5 -> V_68 . V_95 = 0xfffe ;
if ( abs ) {
F_29 ( V_101 , V_5 -> V_96 ) ;
F_32 ( V_5 , V_14 , 0 , V_82 [ V_83 ] , 0 , 0 ) ;
F_32 ( V_5 , V_16 , 0 , V_82 [ V_85 ] , 0 , 0 ) ;
} else {
F_33 ( V_5 , V_102 , V_6 ) ;
F_33 ( V_5 , V_102 , V_8 ) ;
}
F_33 ( V_5 , V_102 , V_11 ) ;
F_29 ( V_27 , V_5 -> V_96 ) ;
for ( V_70 = V_103 ; V_70 <= V_104 ; V_70 ++ )
F_29 ( V_70 , V_5 -> V_25 ) ;
V_69 = F_30 ( V_5 ) ;
if ( V_69 ) {
F_31 ( V_5 ) ;
F_23 ( V_21 , V_69 , L_10 ) ;
goto error;
}
V_2 -> V_5 = V_5 ;
if ( V_71 ) {
int V_105 , V_106 , V_107 ;
V_29 = F_28 () ;
if ( ! V_29 )
goto V_79;
V_105 = F_26 ( V_2 -> V_74 -> V_77 ,
V_108 ,
1 ) ;
V_106 = F_26 ( V_2 -> V_74 -> V_77 ,
V_109 ,
V_110 ) ;
V_107 = F_26 ( V_2 -> V_74 -> V_77 ,
V_111 ,
V_112 ) ;
V_29 -> V_91 = L_11 ;
V_29 -> V_76 = V_2 -> V_76 ;
V_29 -> V_68 . V_92 = V_93 ;
V_29 -> V_68 . V_94 = 0x5853 ;
V_29 -> V_68 . V_95 = 0xfffd ;
F_32 ( V_29 , V_40 ,
0 , 255 , 0 , 0 ) ;
F_32 ( V_29 , V_36 ,
0 , V_106 , 0 , 0 ) ;
F_32 ( V_29 , V_38 ,
0 , V_107 , 0 , 0 ) ;
F_32 ( V_29 , V_113 ,
0 , 255 , 0 , 0 ) ;
V_69 = F_34 ( V_29 , V_105 , V_114 ) ;
if ( V_69 ) {
F_31 ( V_29 ) ;
F_23 ( V_2 -> V_74 , V_69 ,
L_12 ) ;
goto error;
}
V_69 = F_30 ( V_29 ) ;
if ( V_69 ) {
F_31 ( V_29 ) ;
F_23 ( V_2 -> V_74 , V_69 ,
L_13 ) ;
goto error;
}
V_2 -> V_31 = - 1 ;
V_2 -> V_29 = V_29 ;
}
V_69 = F_35 ( V_21 , V_2 ) ;
if ( V_69 < 0 )
goto error;
return 0 ;
V_79:
V_69 = - V_73 ;
F_23 ( V_21 , V_69 , L_14 ) ;
error:
F_36 ( V_21 ) ;
return V_69 ;
}
static int F_37 ( struct V_66 * V_21 )
{
struct V_1 * V_2 = F_38 ( & V_21 -> V_21 ) ;
F_39 ( V_2 ) ;
memset ( V_2 -> V_59 , 0 , V_115 ) ;
return F_35 ( V_21 , V_2 ) ;
}
static int F_36 ( struct V_66 * V_21 )
{
struct V_1 * V_2 = F_38 ( & V_21 -> V_21 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_26 )
F_40 ( V_2 -> V_26 ) ;
if ( V_2 -> V_5 )
F_40 ( V_2 -> V_5 ) ;
if ( V_2 -> V_29 )
F_40 ( V_2 -> V_29 ) ;
F_41 ( ( unsigned long ) V_2 -> V_59 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_66 * V_21 ,
struct V_1 * V_2 )
{
int V_69 , V_116 ;
struct V_117 V_118 ;
V_69 = F_43 ( V_21 -> V_119 ,
F_44 ( V_2 -> V_59 ) , 0 ) ;
if ( V_69 < 0 )
return V_69 ;
V_2 -> V_75 = V_69 ;
V_69 = F_45 ( V_21 , & V_116 ) ;
if ( V_69 )
goto V_120;
V_69 = F_46 ( V_116 , F_16 ,
0 , V_21 -> V_121 , V_2 ) ;
if ( V_69 < 0 ) {
F_23 ( V_21 , V_69 , L_15 ) ;
goto V_122;
}
V_2 -> V_65 = V_69 ;
V_123:
V_69 = F_47 ( & V_118 ) ;
if ( V_69 ) {
F_23 ( V_21 , V_69 , L_16 ) ;
goto V_124;
}
V_69 = F_48 ( V_118 , V_21 -> V_77 , V_125 , L_17 ,
F_44 ( V_2 -> V_59 ) ) ;
if ( V_69 )
goto V_126;
V_69 = F_48 ( V_118 , V_21 -> V_77 , V_127 ,
L_18 , V_2 -> V_75 ) ;
if ( V_69 )
goto V_126;
V_69 = F_48 ( V_118 , V_21 -> V_77 , V_128 , L_18 ,
V_116 ) ;
if ( V_69 )
goto V_126;
V_69 = F_49 ( V_118 , 0 ) ;
if ( V_69 ) {
if ( V_69 == - V_129 )
goto V_123;
F_23 ( V_21 , V_69 , L_19 ) ;
goto V_124;
}
F_50 ( V_21 , V_130 ) ;
return 0 ;
V_126:
F_49 ( V_118 , 1 ) ;
F_23 ( V_21 , V_69 , L_20 ) ;
V_124:
F_51 ( V_2 -> V_65 , V_2 ) ;
V_2 -> V_65 = - 1 ;
V_122:
F_52 ( V_21 , V_116 ) ;
V_120:
F_53 ( V_2 -> V_75 , 0 , 0UL ) ;
V_2 -> V_75 = - 1 ;
return V_69 ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_65 >= 0 )
F_51 ( V_2 -> V_65 , V_2 ) ;
V_2 -> V_65 = - 1 ;
if ( V_2 -> V_75 >= 0 )
F_53 ( V_2 -> V_75 , 0 , 0UL ) ;
V_2 -> V_75 = - 1 ;
}
static void F_54 ( struct V_66 * V_21 ,
enum V_131 V_132 )
{
switch ( V_132 ) {
case V_133 :
case V_130 :
case V_134 :
case V_135 :
case V_136 :
break;
case V_137 :
F_50 ( V_21 , V_138 ) ;
break;
case V_138 :
if ( V_21 -> V_139 != V_138 )
F_50 ( V_21 , V_138 ) ;
break;
case V_140 :
if ( V_21 -> V_139 == V_140 )
break;
case V_141 :
F_55 ( V_21 ) ;
break;
}
}
static int T_3 F_56 ( void )
{
if ( ! F_57 () )
return - V_142 ;
if ( F_58 () )
return - V_142 ;
if ( ! F_59 () )
return - V_142 ;
return F_60 ( & V_143 ) ;
}
static void T_4 F_61 ( void )
{
F_62 ( & V_143 ) ;
}
