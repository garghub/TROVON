static void F_1 ( int V_1 , void * V_2 , int V_3 )
{
while ( V_3 > 0 ) {
F_2 ( V_4 , V_1 , V_2 , V_3 ) ;
V_3 -= V_4 -> V_5 ;
V_2 += V_4 -> V_5 ;
}
}
static void F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_4 ( & V_7 -> V_10 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_13 * V_13 = (struct V_13 * ) & V_14 . V_13 ;
F_5 ( 4 , L_1 ) ;
F_1 ( 4 , V_13 , sizeof( * V_13 ) ) ;
F_6 ( V_15 ) ;
if ( ! V_12 ) {
F_7 ( 0 , L_2 ,
V_7 -> V_16 . V_17 , V_7 -> V_16 . V_18 ) ;
return;
}
V_9 -> V_12 = NULL ;
memcpy ( & V_12 -> V_13 , V_13 , sizeof( * V_13 ) ) ;
F_8 ( V_7 ) ;
F_9 ( & V_12 -> V_19 ) ;
F_10 ( & V_7 -> V_10 ) ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_20 ;
F_7 ( 6 , L_3 ,
V_7 -> V_16 . V_17 , V_7 -> V_16 . V_18 ) ;
V_7 -> V_21 = V_22 ;
V_9 = F_12 ( sizeof( * V_9 ) , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
F_13 ( & V_7 -> V_10 , V_9 ) ;
V_20 = F_14 ( V_7 , ( V_25 ) ( unsigned long ) V_7 ) ;
if ( V_20 ) {
F_7 ( 0 , L_4 ,
V_7 -> V_16 . V_17 , V_7 -> V_16 . V_18 , V_20 ) ;
F_13 ( & V_7 -> V_10 , NULL ) ;
F_15 ( V_9 ) ;
} else {
if ( F_16 ( & V_7 -> V_10 ) ) {
F_17 ( & V_7 -> V_10 , 0 ) ;
F_18 ( & V_7 -> V_10 . V_26 , V_27 ) ;
}
}
return V_20 ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
F_20 ( V_7 ) ;
V_9 = F_4 ( & V_7 -> V_10 ) ;
F_13 ( & V_7 -> V_10 , NULL ) ;
if ( V_9 -> V_12 ) {
F_9 ( & V_9 -> V_12 -> V_19 ) ;
F_10 ( & V_7 -> V_10 ) ;
}
F_15 ( V_9 ) ;
return 0 ;
}
static void F_21 ( struct V_6 * V_7 )
{
F_20 ( V_7 ) ;
}
static int F_22 ( struct V_6 * V_7 )
{
int V_28 ;
struct V_29 V_29 ;
V_28 = F_23 ( V_7 -> V_16 , & V_29 ) ;
if ( ! V_28 && F_24 ( & V_29 . V_30 ) )
return - V_31 ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 )
{
return F_20 ( V_7 ) ;
}
static int F_26 ( struct V_6 * V_7 )
{
return F_14 ( V_7 , ( V_25 ) ( unsigned long ) V_7 ) ;
}
static int T_1 F_27 ( void )
{
V_32 = F_28 ( L_5 , 16 , 1 ,
16 * sizeof( long ) ) ;
if ( ! V_32 )
goto V_33;
F_29 ( V_32 , & V_34 ) ;
F_30 ( V_32 , 2 ) ;
V_4 = F_28 ( L_6 , 16 , 1 , 16 ) ;
if ( ! V_4 )
goto V_33;
F_29 ( V_4 , & V_35 ) ;
F_30 ( V_4 , 2 ) ;
return 0 ;
V_33:
if ( V_32 )
F_31 ( V_32 ) ;
return - V_24 ;
}
static void F_32 ( void )
{
F_31 ( V_4 ) ;
F_31 ( V_32 ) ;
}
static int T_1 F_33 ( void )
{
return F_34 ( & V_36 ) ;
}
static void F_35 ( void )
{
F_36 ( & V_36 ) ;
}
static int F_37 ( struct V_37 * V_10 , void * V_2 )
{
struct V_6 * V_7 = F_38 ( V_10 ) ;
return V_7 -> V_29 . V_38 . V_39 && ! F_39 ( & V_7 -> V_29 . V_30 ) ;
}
static struct V_6 * F_40 ( struct V_6 * V_7 )
{
struct V_37 * V_10 ;
V_10 = F_41 ( & V_36 . V_40 ,
V_7 ? & V_7 -> V_10 : NULL , NULL ,
F_37 ) ;
return V_10 ? F_38 ( V_10 ) : NULL ;
}
static int F_42 ( struct V_41 * V_42 ,
struct V_11 * V_12 )
{
int V_28 ;
struct V_8 * V_9 ;
struct V_6 * V_7 = NULL ;
int V_20 = - V_43 ;
char V_44 [ 10 ] ;
V_42 -> V_45 . V_46 = V_47 >> 4 ;
while ( ( V_7 = F_40 ( V_7 ) ) ) {
F_43 ( V_7 -> V_48 ) ;
V_9 = F_4 ( & V_7 -> V_10 ) ;
if ( V_9 -> V_12 ) {
F_44 ( V_7 -> V_48 ) ;
V_20 = - V_49 ;
continue;
}
V_42 -> V_45 . V_50 = V_7 -> V_16 ;
F_5 ( 2 , L_7 ) ;
F_1 ( 2 , & V_7 -> V_16 , sizeof( V_7 -> V_16 ) ) ;
V_28 = F_45 ( V_42 ) ;
sprintf ( V_44 , L_8 , V_28 ) ;
F_5 ( 2 , V_44 ) ;
switch ( V_28 ) {
case 0 :
V_20 = 0 ;
break;
case 1 :
V_7 -> V_29 . V_30 . V_51 . V_52 |= V_53 ;
V_20 = - V_54 ;
V_9 -> V_12 = V_12 ;
break;
case 2 :
V_20 = - V_49 ;
break;
default:
V_20 = - V_43 ;
}
F_44 ( V_7 -> V_48 ) ;
F_7 ( 2 , L_9 ,
V_7 -> V_16 . V_17 , V_7 -> V_16 . V_18 , V_28 ) ;
if ( V_20 == - V_54 )
return - V_54 ;
F_10 ( & V_7 -> V_10 ) ;
if ( V_20 == 0 )
return 0 ;
}
return V_20 ;
}
static void F_46 ( struct V_41 * V_42 )
{
char V_44 [ 10 ] ;
sprintf ( V_44 , L_10 , V_42 -> V_45 . V_55 ) ;
F_5 ( 0 , V_44 ) ;
F_1 ( 0 , V_42 , 32 ) ;
}
static int F_47 ( struct V_11 * V_12 )
{
int V_56 ;
if ( ! ( F_24 ( & V_12 -> V_13 . V_30 ) & V_57 ) )
return - V_58 ;
V_56 = F_48 ( & V_12 -> V_13 . V_30 ) & V_59 ;
V_12 -> V_13 . V_30 . V_51 . V_60 &= ~ V_59 ;
if ( F_48 ( & V_12 -> V_13 . V_30 ) == 0 )
return 0 ;
if ( ! V_56 )
return 0 ;
if ( F_48 ( & V_12 -> V_13 . V_30 ) & V_61 )
return - V_58 ;
if ( F_48 ( & V_12 -> V_13 . V_30 ) & V_62 )
return - V_63 ;
if ( F_48 ( & V_12 -> V_13 . V_30 ) & V_64 )
return - V_31 ;
if ( F_48 ( & V_12 -> V_13 . V_30 ) & V_65 )
return - V_31 ;
return - V_58 ;
}
static int F_49 ( void T_2 * V_66 )
{
struct V_11 * V_12 ;
struct V_41 * V_42 ;
int V_20 ;
char V_44 [ 10 ] ;
if ( ! V_67 . V_68 )
return - V_69 ;
V_42 = ( void * ) F_50 ( V_70 | V_23 ) ;
if ( ! V_42 )
return - V_24 ;
V_12 = F_12 ( sizeof( * V_12 ) , V_23 ) ;
if ( ! V_12 ) {
V_20 = - V_24 ;
goto V_71;
}
F_51 ( & V_12 -> V_19 ) ;
if ( F_52 ( V_42 , V_66 , V_72 ) ) {
V_20 = - V_73 ;
goto V_71;
}
F_46 ( V_42 ) ;
F_53 ( & V_74 ) ;
V_20 = F_42 ( V_42 , V_12 ) ;
F_54 ( & V_74 ) ;
if ( V_20 == - V_54 ) {
F_55 ( & V_12 -> V_19 ) ;
V_20 = F_47 ( V_12 ) ;
}
if ( ! V_20 )
if ( F_56 ( V_66 , V_42 , V_72 ) )
V_20 = - V_73 ;
V_71:
sprintf ( V_44 , L_11 , V_20 ) ;
F_5 ( 0 , V_44 ) ;
F_15 ( V_12 ) ;
F_57 ( ( unsigned long ) V_42 ) ;
return V_20 ;
}
static int F_58 ( void T_2 * V_75 )
{
struct V_76 * V_77 ;
int V_20 , V_78 ;
struct {
struct V_79 V_12 ;
V_25 : 2 ;
V_25 V_80 : 1 ;
V_25 : 1 ;
V_25 V_81 : 4 ;
V_25 V_82 : 8 ;
V_25 : 8 ;
V_25 V_83 : 8 ;
V_25 : 24 ;
V_25 V_84 : 8 ;
V_25 : 32 ;
struct V_79 V_85 ;
T_3 V_2 [ V_72 - 20 ] ;
} V_86 ( ( V_87 ) ) * V_88 ;
V_88 = ( void * ) F_50 ( V_23 | V_70 ) ;
if ( ! V_88 )
return - V_24 ;
V_77 = F_12 ( sizeof( * V_77 ) , V_23 ) ;
if ( ! V_77 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_52 ( V_77 , V_75 , sizeof( * V_77 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_88 -> V_12 . V_3 = 0x0010 ;
V_88 -> V_12 . V_55 = 0x0028 ;
V_88 -> V_80 = V_77 -> V_80 ;
V_88 -> V_81 = V_77 -> V_89 ;
V_88 -> V_82 = V_77 -> V_90 . V_82 ;
V_88 -> V_83 = V_77 -> V_90 . V_91 ;
V_88 -> V_84 = V_77 -> V_90 . V_91 ;
V_78 = F_45 ( V_88 ) ;
if ( V_78 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( V_88 -> V_85 . V_55 != 0x0001 ) {
V_20 = - V_58 ;
F_7 ( 0 , L_12 ,
V_88 -> V_85 . V_55 ) ;
goto V_71;
}
memcpy ( & V_77 -> V_92 , & V_88 -> V_85 , V_88 -> V_85 . V_3 ) ;
if ( F_56 ( V_75 , V_77 , sizeof( * V_77 ) ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_15 ( V_77 ) ;
F_57 ( ( unsigned long ) V_88 ) ;
return V_20 ;
}
static int F_59 ( void T_2 * V_75 )
{
struct V_93 * V_77 ;
int V_20 , V_78 ;
struct {
struct V_79 V_12 ;
V_25 : 2 ;
V_25 V_80 : 1 ;
V_25 : 1 ;
V_25 V_81 : 4 ;
V_25 V_82 : 8 ;
V_25 : 8 ;
V_25 V_94 : 8 ;
V_25 : 24 ;
V_25 V_95 : 8 ;
V_25 : 32 ;
struct V_79 V_85 ;
T_3 V_2 [ V_72 - 20 ] ;
} V_86 ( ( V_87 ) ) * V_96 ;
V_96 = ( void * ) F_50 ( V_23 | V_70 ) ;
if ( ! V_96 )
return - V_24 ;
V_77 = F_12 ( sizeof( * V_77 ) , V_23 ) ;
if ( ! V_77 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_52 ( V_77 , V_75 , sizeof( * V_77 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_96 -> V_12 . V_3 = 0x0010 ;
V_96 -> V_12 . V_55 = 0x0028 ;
V_96 -> V_80 = V_77 -> V_80 ;
V_96 -> V_81 = V_77 -> V_89 ;
V_96 -> V_82 = V_77 -> V_82 ;
V_96 -> V_94 = V_77 -> V_97 ;
V_96 -> V_95 = V_77 -> V_97 ;
V_78 = F_45 ( V_96 ) ;
if ( V_78 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( V_96 -> V_85 . V_55 != 0x0001 ) {
V_20 = - V_58 ;
F_7 ( 0 , L_13 ,
V_96 -> V_85 . V_55 ) ;
goto V_71;
}
memcpy ( & V_77 -> V_98 , & V_96 -> V_85 , V_96 -> V_85 . V_3 ) ;
if ( F_56 ( V_75 , V_77 , sizeof( * V_77 ) ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_15 ( V_77 ) ;
F_57 ( ( unsigned long ) V_96 ) ;
return V_20 ;
}
static int F_60 ( void T_2 * V_99 )
{
struct V_100 * V_101 ;
int V_20 , V_78 ;
struct {
struct V_79 V_12 ;
V_25 : 2 ;
V_25 V_80 : 1 ;
V_25 : 5 ;
V_25 V_81 : 4 ;
V_25 : 2 ;
V_25 V_17 : 2 ;
V_25 V_102 : 16 ;
V_25 : 8 ;
V_25 V_82 : 8 ;
V_25 V_103 : 16 ;
V_25 : 32 ;
struct V_79 V_85 ;
T_3 V_2 [ V_72 - 20 ] ;
} V_86 ( ( V_87 ) ) * V_104 ;
V_104 = ( void * ) F_50 ( V_23 | V_70 ) ;
if ( ! V_104 )
return - V_24 ;
V_101 = F_12 ( sizeof( * V_101 ) , V_23 ) ;
if ( ! V_101 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_52 ( V_101 , V_99 , sizeof( * V_101 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_104 -> V_12 . V_3 = 0x0010 ;
V_104 -> V_12 . V_55 = 0x0006 ;
V_104 -> V_80 = V_101 -> V_16 . V_80 ;
V_104 -> V_81 = V_101 -> V_89 ;
V_104 -> V_17 = V_101 -> V_16 . V_17 ;
V_104 -> V_102 = V_101 -> V_16 . V_18 ;
V_104 -> V_82 = V_101 -> V_16 . V_82 ;
V_104 -> V_103 = V_101 -> V_16 . V_18 ;
V_78 = F_45 ( V_104 ) ;
if ( V_78 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( V_104 -> V_85 . V_55 != 0x0001 ) {
V_20 = - V_58 ;
F_7 ( 0 , L_14 ,
V_104 -> V_85 . V_55 ) ;
goto V_71;
}
memcpy ( & V_101 -> V_105 , & V_104 -> V_85 , V_104 -> V_85 . V_3 ) ;
if ( F_56 ( V_99 , V_101 , sizeof( * V_101 ) ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_15 ( V_101 ) ;
F_57 ( ( unsigned long ) V_104 ) ;
return V_20 ;
}
static int F_61 ( void T_2 * V_106 )
{
struct V_107 * V_108 ;
int V_20 , V_78 ;
struct {
struct V_79 V_12 ;
V_25 : 2 ;
V_25 V_80 : 1 ;
V_25 : 1 ;
V_25 V_81 : 4 ;
V_25 V_82 : 8 ;
V_25 : 6 ;
V_25 V_17 : 2 ;
V_25 : 8 ;
V_109 : 64 ;
struct V_79 V_85 ;
T_3 V_2 [ V_72 - 20 ] ;
} V_86 ( ( V_87 ) ) * V_110 ;
V_110 = ( void * ) F_50 ( V_23 | V_70 ) ;
if ( ! V_110 )
return - V_24 ;
V_108 = F_12 ( sizeof( * V_108 ) , V_23 ) ;
if ( ! V_108 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_52 ( V_108 , V_106 , sizeof( * V_108 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_110 -> V_12 . V_3 = 0x0010 ;
V_110 -> V_12 . V_55 = 0x0012 ;
V_110 -> V_80 = V_108 -> V_91 . V_80 ;
V_110 -> V_81 = V_108 -> V_89 ;
V_110 -> V_82 = V_108 -> V_91 . V_82 ;
V_110 -> V_17 = V_108 -> V_91 . V_17 ;
V_78 = F_45 ( V_110 ) ;
if ( V_78 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( V_110 -> V_85 . V_55 != 0x0001 ) {
V_20 = - V_58 ;
F_7 ( 0 , L_15 ,
V_110 -> V_85 . V_55 ) ;
goto V_71;
}
memcpy ( & V_108 -> V_111 , & V_110 -> V_85 , V_110 -> V_85 . V_3 ) ;
if ( F_56 ( V_106 , V_108 , sizeof( * V_108 ) ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_15 ( V_108 ) ;
F_57 ( ( unsigned long ) V_110 ) ;
return V_20 ;
}
static int F_62 ( void T_2 * V_112 )
{
struct V_113 * V_114 ;
int V_20 , V_78 ;
struct {
struct V_79 V_12 ;
V_25 V_115 : 8 ;
V_25 : 4 ;
V_25 V_89 : 4 ;
V_25 : 16 ;
V_109 : 64 ;
V_25 V_116 [ 2 ] ;
V_109 : 64 ;
struct V_79 V_85 ;
T_3 V_2 [ V_72 - 36 ] ;
} V_86 ( ( V_87 ) ) * V_117 ;
struct {
V_25 V_80 : 1 ;
V_25 : 31 ;
V_25 V_82 : 8 ;
V_25 : 16 ;
V_25 V_90 : 8 ;
} V_86 ( ( V_87 ) ) * V_118 ;
struct {
V_25 V_119 : 8 ;
V_25 V_120 : 8 ;
V_25 : 16 ;
V_25 V_121 ;
} V_86 ( ( V_87 ) ) * V_122 ;
V_117 = ( void * ) F_50 ( V_23 | V_70 ) ;
if ( ! V_117 )
return - V_24 ;
V_114 = F_12 ( sizeof( * V_114 ) , V_23 ) ;
if ( ! V_114 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_52 ( V_114 , V_112 , sizeof( * V_114 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_117 -> V_12 . V_3 = 0x0020 ;
V_117 -> V_12 . V_55 = 0x0030 ;
V_117 -> V_89 = V_114 -> V_123 . V_89 ;
V_117 -> V_115 = V_114 -> V_123 . V_115 ;
switch ( V_117 -> V_115 ) {
case V_124 :
case V_125 :
V_118 = ( void * ) & V_117 -> V_116 ;
V_118 -> V_80 = V_114 -> V_123 . V_90 . V_80 ;
V_118 -> V_82 = V_114 -> V_123 . V_90 . V_126 . V_82 ;
V_118 -> V_90 = V_114 -> V_123 . V_90 . V_126 . V_91 ;
break;
case V_127 :
case V_128 :
V_122 = ( void * ) & V_117 -> V_116 ;
V_122 -> V_119 = V_114 -> V_123 . V_129 . V_119 ;
V_122 -> V_120 = V_114 -> V_123 . V_129 . V_120 ;
break;
}
V_78 = F_45 ( V_117 ) ;
if ( V_78 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( V_117 -> V_85 . V_55 != 0x0001 ) {
V_20 = - V_58 ;
F_7 ( 0 , L_16 ,
V_117 -> V_85 . V_55 ) ;
goto V_71;
}
memcpy ( & V_114 -> V_130 , & V_117 -> V_85 , V_117 -> V_85 . V_3 ) ;
if ( F_56 ( V_112 , V_114 , sizeof( * V_114 ) ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_15 ( V_114 ) ;
F_57 ( ( unsigned long ) V_117 ) ;
return V_20 ;
}
static int F_63 ( void T_2 * V_131 )
{
struct V_132 * V_133 ;
struct V_134 * V_135 ;
int V_20 ;
V_135 = F_12 ( sizeof( * V_135 ) , V_23 ) ;
V_133 = ( void * ) F_50 ( V_23 | V_70 ) ;
if ( ! V_133 || ! V_135 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_52 ( V_135 , V_131 , sizeof( * V_135 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_20 = F_64 ( V_135 -> V_90 , V_135 -> V_89 ,
V_135 -> V_136 , V_135 -> V_137 , V_135 -> V_80 ,
V_133 ) ;
if ( V_20 )
goto V_71;
memcpy ( & V_135 -> V_138 , & V_133 -> V_85 , V_133 -> V_85 . V_3 ) ;
if ( F_56 ( V_131 , V_135 , sizeof( * V_135 ) ) )
V_20 = - V_73 ;
V_71:
F_15 ( V_135 ) ;
F_57 ( ( unsigned long ) V_133 ) ;
return V_20 ;
}
static int F_65 ( void T_2 * V_139 )
{
struct V_140 * V_141 ;
int V_20 , V_78 ;
struct {
struct V_79 V_12 ;
V_25 V_142 : 8 ;
V_25 : 4 ;
V_25 V_89 : 4 ;
V_25 : 16 ;
V_25 V_143 [ 2 ] ;
V_25 V_116 [ 2 ] ;
V_25 V_144 [ 2 ] ;
struct V_79 V_85 ;
T_3 V_2 [ V_72 - 36 ] ;
} V_86 ( ( V_87 ) ) * V_145 ;
V_145 = ( void * ) F_50 ( V_23 | V_70 ) ;
if ( ! V_145 )
return - V_24 ;
V_141 = F_12 ( sizeof( * V_141 ) , V_23 ) ;
if ( ! V_141 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_52 ( V_141 , V_139 , sizeof( * V_141 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_145 -> V_12 . V_3 = 0x0020 ;
V_145 -> V_12 . V_55 = 0x0034 ;
V_145 -> V_142 = V_141 -> V_123 . V_142 ;
V_145 -> V_89 = V_141 -> V_123 . V_89 ;
memcpy ( & V_145 -> V_116 , & V_141 -> V_123 . V_116 ,
sizeof( V_145 -> V_116 ) ) ;
V_78 = F_45 ( V_145 ) ;
if ( V_78 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( V_145 -> V_85 . V_55 != 0x0001 ) {
V_20 = - V_58 ;
F_7 ( 0 , L_17 ,
V_145 -> V_85 . V_55 ) ;
goto V_71;
}
memcpy ( & V_141 -> V_146 , & V_145 -> V_85 ,
V_145 -> V_85 . V_3 ) ;
if ( F_56 ( V_139 , V_141 , sizeof( * V_141 ) ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_15 ( V_141 ) ;
F_57 ( ( unsigned long ) V_145 ) ;
return V_20 ;
}
static long F_66 ( struct V_147 * V_148 , unsigned int V_51 ,
unsigned long V_149 )
{
void T_2 * V_150 ;
F_7 ( 2 , L_18 , V_51 ) ;
if ( F_67 () )
V_150 = F_68 ( V_149 ) ;
else
V_150 = ( void T_2 * ) V_149 ;
switch ( V_51 ) {
case V_151 :
return F_49 ( V_150 ) ;
case V_152 :
return F_58 ( V_150 ) ;
case V_153 :
return F_59 ( V_150 ) ;
case V_154 :
return F_60 ( V_150 ) ;
case V_155 :
return F_61 ( V_150 ) ;
case V_156 :
return F_62 ( V_150 ) ;
case V_157 :
return F_63 ( V_150 ) ;
case V_158 :
return F_65 ( V_150 ) ;
default:
return - V_159 ;
}
}
static int T_1 F_69 ( void )
{
return F_70 ( & V_160 ) ;
}
static void F_71 ( void )
{
F_72 ( & V_160 ) ;
}
static int T_1 F_73 ( void )
{
int V_20 ;
V_20 = F_27 () ;
if ( V_20 )
return V_20 ;
F_74 ( V_22 ) ;
V_20 = F_33 () ;
if ( V_20 )
goto V_161;
V_20 = F_69 () ;
if ( V_20 )
goto V_162;
return V_20 ;
V_162:
F_35 () ;
V_161:
F_75 ( V_22 ) ;
F_32 () ;
return V_20 ;
}
static void T_4 F_76 ( void )
{
F_71 () ;
F_35 () ;
F_75 ( V_22 ) ;
F_32 () ;
}
