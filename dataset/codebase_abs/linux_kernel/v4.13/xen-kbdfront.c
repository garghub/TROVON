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
if ( F_7 ( V_19 -> V_22 , V_2 -> V_5 -> V_23 ) ) {
V_21 = V_2 -> V_5 ;
} else if ( F_7 ( V_19 -> V_22 , V_2 -> V_24 -> V_23 ) ) {
V_21 = V_2 -> V_24 ;
} else {
F_8 ( L_1 , V_19 -> V_22 ) ;
return;
}
F_9 ( V_21 , V_19 -> V_22 , V_19 -> V_25 ) ;
F_3 ( V_21 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
if ( F_11 ( ! V_2 -> V_27 ) )
return;
if ( V_27 -> V_28 != V_2 -> V_29 ) {
V_2 -> V_29 = V_27 -> V_28 ;
F_12 ( V_2 -> V_27 , V_27 -> V_28 ) ;
}
switch ( V_27 -> V_30 ) {
case V_31 :
F_13 ( V_2 -> V_27 , V_32 , true ) ;
case V_33 :
F_5 ( V_2 -> V_27 , V_34 ,
V_27 -> V_35 . V_13 . V_15 ) ;
F_5 ( V_2 -> V_27 , V_36 ,
V_27 -> V_35 . V_13 . V_17 ) ;
break;
case V_37 :
F_5 ( V_2 -> V_27 , V_38 ,
V_27 -> V_35 . V_39 . V_40 ) ;
F_5 ( V_2 -> V_27 , V_41 ,
V_27 -> V_35 . V_39 . V_42 ) ;
break;
case V_43 :
F_5 ( V_2 -> V_27 , V_44 ,
V_27 -> V_35 . V_45 ) ;
break;
case V_46 :
F_13 ( V_2 -> V_27 , V_32 , false ) ;
break;
case V_47 :
F_14 ( V_2 -> V_27 ) ;
F_3 ( V_2 -> V_27 ) ;
break;
}
}
static void F_15 ( struct V_1 * V_2 ,
union V_48 * V_49 )
{
switch ( V_49 -> type ) {
case V_50 :
F_1 ( V_2 , & V_49 -> V_4 ) ;
break;
case V_51 :
F_6 ( V_2 , & V_49 -> V_19 ) ;
break;
case V_52 :
F_4 ( V_2 , & V_49 -> V_13 ) ;
break;
case V_53 :
F_10 ( V_2 , & V_49 -> V_27 ) ;
break;
}
}
static T_1 F_16 ( int V_54 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
struct V_56 * V_57 = V_2 -> V_57 ;
T_2 V_58 , V_59 ;
V_59 = V_57 -> V_60 ;
if ( V_59 == V_57 -> V_61 )
return V_62 ;
F_17 () ;
for ( V_58 = V_57 -> V_61 ; V_58 != V_59 ; V_58 ++ )
F_15 ( V_2 , & F_18 ( V_57 , V_58 ) ) ;
F_19 () ;
V_57 -> V_61 = V_58 ;
F_20 ( V_2 -> V_63 ) ;
return V_62 ;
}
static int F_21 ( struct V_64 * V_21 ,
const struct V_65 * V_66 )
{
int V_67 , V_68 ;
unsigned int abs , V_69 ;
struct V_1 * V_2 ;
struct V_20 * V_24 , * V_5 , * V_27 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 ) {
F_23 ( V_21 , - V_71 , L_2 ) ;
return - V_71 ;
}
F_24 ( & V_21 -> V_21 , V_2 ) ;
V_2 -> V_72 = V_21 ;
V_2 -> V_63 = - 1 ;
V_2 -> V_73 = - 1 ;
snprintf ( V_2 -> V_74 , sizeof( V_2 -> V_74 ) , L_3 , V_21 -> V_75 ) ;
V_2 -> V_57 = ( void * ) F_25 ( V_70 | V_76 ) ;
if ( ! V_2 -> V_57 )
goto V_77;
abs = F_26 ( V_21 -> V_78 ,
V_79 , 0 ) ;
V_80 [ V_81 ] = F_26 ( V_21 -> V_78 ,
V_82 ,
V_80 [ V_81 ] ) ;
V_80 [ V_83 ] = F_26 ( V_21 -> V_78 ,
V_84 ,
V_80 [ V_83 ] ) ;
if ( abs ) {
V_67 = F_27 ( V_85 , V_21 -> V_75 ,
V_86 , L_4 ) ;
if ( V_67 ) {
F_8 ( L_5 ) ;
abs = 0 ;
}
}
V_69 = F_26 ( V_21 -> V_75 ,
V_87 , 0 ) ;
if ( V_69 ) {
V_67 = F_27 ( V_85 , V_21 -> V_75 ,
V_88 , L_4 ) ;
if ( V_67 ) {
F_8 ( L_6 ) ;
V_69 = 0 ;
}
}
V_24 = F_28 () ;
if ( ! V_24 )
goto V_77;
V_24 -> V_89 = L_7 ;
V_24 -> V_74 = V_2 -> V_74 ;
V_24 -> V_66 . V_90 = V_91 ;
V_24 -> V_66 . V_92 = 0x5853 ;
V_24 -> V_66 . V_93 = 0xffff ;
F_29 ( V_94 , V_24 -> V_95 ) ;
for ( V_68 = V_96 ; V_68 < V_97 ; V_68 ++ )
F_29 ( V_68 , V_24 -> V_23 ) ;
for ( V_68 = V_98 ; V_68 < V_99 ; V_68 ++ )
F_29 ( V_68 , V_24 -> V_23 ) ;
V_67 = F_30 ( V_24 ) ;
if ( V_67 ) {
F_31 ( V_24 ) ;
F_23 ( V_21 , V_67 , L_8 ) ;
goto error;
}
V_2 -> V_24 = V_24 ;
V_5 = F_28 () ;
if ( ! V_5 )
goto V_77;
V_5 -> V_89 = L_9 ;
V_5 -> V_74 = V_2 -> V_74 ;
V_5 -> V_66 . V_90 = V_91 ;
V_5 -> V_66 . V_92 = 0x5853 ;
V_5 -> V_66 . V_93 = 0xfffe ;
if ( abs ) {
F_29 ( V_100 , V_5 -> V_95 ) ;
F_32 ( V_5 , V_14 , 0 , V_80 [ V_81 ] , 0 , 0 ) ;
F_32 ( V_5 , V_16 , 0 , V_80 [ V_83 ] , 0 , 0 ) ;
} else {
F_33 ( V_5 , V_101 , V_6 ) ;
F_33 ( V_5 , V_101 , V_8 ) ;
}
F_33 ( V_5 , V_101 , V_11 ) ;
F_29 ( V_94 , V_5 -> V_95 ) ;
for ( V_68 = V_102 ; V_68 <= V_103 ; V_68 ++ )
F_29 ( V_68 , V_5 -> V_23 ) ;
V_67 = F_30 ( V_5 ) ;
if ( V_67 ) {
F_31 ( V_5 ) ;
F_23 ( V_21 , V_67 , L_10 ) ;
goto error;
}
V_2 -> V_5 = V_5 ;
if ( V_69 ) {
int V_104 , V_105 , V_106 ;
V_27 = F_28 () ;
if ( ! V_27 )
goto V_77;
V_104 = F_26 ( V_2 -> V_72 -> V_75 ,
V_107 ,
1 ) ;
V_105 = F_26 ( V_2 -> V_72 -> V_75 ,
V_108 ,
V_109 ) ;
V_106 = F_26 ( V_2 -> V_72 -> V_75 ,
V_110 ,
V_111 ) ;
V_27 -> V_89 = L_11 ;
V_27 -> V_74 = V_2 -> V_74 ;
V_27 -> V_66 . V_90 = V_91 ;
V_27 -> V_66 . V_92 = 0x5853 ;
V_27 -> V_66 . V_93 = 0xfffd ;
F_32 ( V_27 , V_38 ,
0 , 255 , 0 , 0 ) ;
F_32 ( V_27 , V_34 ,
0 , V_105 , 0 , 0 ) ;
F_32 ( V_27 , V_36 ,
0 , V_106 , 0 , 0 ) ;
F_32 ( V_27 , V_112 ,
0 , 255 , 0 , 0 ) ;
V_67 = F_34 ( V_27 , V_104 , V_113 ) ;
if ( V_67 ) {
F_31 ( V_27 ) ;
F_23 ( V_2 -> V_72 , V_67 ,
L_12 ) ;
goto error;
}
V_67 = F_30 ( V_27 ) ;
if ( V_67 ) {
F_31 ( V_27 ) ;
F_23 ( V_2 -> V_72 , V_67 ,
L_13 ) ;
goto error;
}
V_2 -> V_29 = - 1 ;
V_2 -> V_27 = V_27 ;
}
V_67 = F_35 ( V_21 , V_2 ) ;
if ( V_67 < 0 )
goto error;
return 0 ;
V_77:
V_67 = - V_71 ;
F_23 ( V_21 , V_67 , L_14 ) ;
error:
F_36 ( V_21 ) ;
return V_67 ;
}
static int F_37 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = F_38 ( & V_21 -> V_21 ) ;
F_39 ( V_2 ) ;
memset ( V_2 -> V_57 , 0 , V_114 ) ;
return F_35 ( V_21 , V_2 ) ;
}
static int F_36 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = F_38 ( & V_21 -> V_21 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_24 )
F_40 ( V_2 -> V_24 ) ;
if ( V_2 -> V_5 )
F_40 ( V_2 -> V_5 ) ;
if ( V_2 -> V_27 )
F_40 ( V_2 -> V_27 ) ;
F_41 ( ( unsigned long ) V_2 -> V_57 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_64 * V_21 ,
struct V_1 * V_2 )
{
int V_67 , V_115 ;
struct V_116 V_117 ;
V_67 = F_43 ( V_21 -> V_118 ,
F_44 ( V_2 -> V_57 ) , 0 ) ;
if ( V_67 < 0 )
return V_67 ;
V_2 -> V_73 = V_67 ;
V_67 = F_45 ( V_21 , & V_115 ) ;
if ( V_67 )
goto V_119;
V_67 = F_46 ( V_115 , F_16 ,
0 , V_21 -> V_120 , V_2 ) ;
if ( V_67 < 0 ) {
F_23 ( V_21 , V_67 , L_15 ) ;
goto V_121;
}
V_2 -> V_63 = V_67 ;
V_122:
V_67 = F_47 ( & V_117 ) ;
if ( V_67 ) {
F_23 ( V_21 , V_67 , L_16 ) ;
goto V_123;
}
V_67 = F_48 ( V_117 , V_21 -> V_75 , V_124 , L_17 ,
F_44 ( V_2 -> V_57 ) ) ;
if ( V_67 )
goto V_125;
V_67 = F_48 ( V_117 , V_21 -> V_75 , V_126 ,
L_18 , V_2 -> V_73 ) ;
if ( V_67 )
goto V_125;
V_67 = F_48 ( V_117 , V_21 -> V_75 , V_127 , L_18 ,
V_115 ) ;
if ( V_67 )
goto V_125;
V_67 = F_49 ( V_117 , 0 ) ;
if ( V_67 ) {
if ( V_67 == - V_128 )
goto V_122;
F_23 ( V_21 , V_67 , L_19 ) ;
goto V_123;
}
F_50 ( V_21 , V_129 ) ;
return 0 ;
V_125:
F_49 ( V_117 , 1 ) ;
F_23 ( V_21 , V_67 , L_20 ) ;
V_123:
F_51 ( V_2 -> V_63 , V_2 ) ;
V_2 -> V_63 = - 1 ;
V_121:
F_52 ( V_21 , V_115 ) ;
V_119:
F_53 ( V_2 -> V_73 , 0 , 0UL ) ;
V_2 -> V_73 = - 1 ;
return V_67 ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_63 >= 0 )
F_51 ( V_2 -> V_63 , V_2 ) ;
V_2 -> V_63 = - 1 ;
if ( V_2 -> V_73 >= 0 )
F_53 ( V_2 -> V_73 , 0 , 0UL ) ;
V_2 -> V_73 = - 1 ;
}
static void F_54 ( struct V_64 * V_21 ,
enum V_130 V_131 )
{
switch ( V_131 ) {
case V_132 :
case V_129 :
case V_133 :
case V_134 :
case V_135 :
break;
case V_136 :
F_50 ( V_21 , V_137 ) ;
break;
case V_137 :
if ( V_21 -> V_138 != V_137 )
F_50 ( V_21 , V_137 ) ;
break;
case V_139 :
if ( V_21 -> V_138 == V_139 )
break;
case V_140 :
F_55 ( V_21 ) ;
break;
}
}
static int T_3 F_56 ( void )
{
if ( ! F_57 () )
return - V_141 ;
if ( F_58 () )
return - V_141 ;
if ( ! F_59 () )
return - V_141 ;
return F_60 ( & V_142 ) ;
}
static void T_4 F_61 ( void )
{
F_62 ( & V_142 ) ;
}
