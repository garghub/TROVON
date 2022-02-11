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
if ( ! V_12 ) {
F_6 ( 0 , L_2 ,
V_7 -> V_15 . V_16 , V_7 -> V_15 . V_17 ) ;
return;
}
V_9 -> V_12 = NULL ;
memcpy ( & V_12 -> V_13 , V_13 , sizeof( * V_13 ) ) ;
F_7 ( V_7 ) ;
F_8 ( & V_12 -> V_18 ) ;
F_9 ( & V_7 -> V_10 ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_19 ;
F_6 ( 6 , L_3 ,
V_7 -> V_15 . V_16 , V_7 -> V_15 . V_17 ) ;
V_7 -> V_20 = V_21 ;
V_9 = F_11 ( sizeof( * V_9 ) , V_22 ) ;
if ( ! V_9 )
return - V_23 ;
F_12 ( & V_7 -> V_10 , V_9 ) ;
V_19 = F_13 ( V_7 , ( V_24 ) ( unsigned long ) V_7 ) ;
if ( V_19 ) {
F_6 ( 0 , L_4 ,
V_7 -> V_15 . V_16 , V_7 -> V_15 . V_17 , V_19 ) ;
F_12 ( & V_7 -> V_10 , NULL ) ;
F_14 ( V_9 ) ;
} else {
if ( F_15 ( & V_7 -> V_10 ) ) {
F_16 ( & V_7 -> V_10 , 0 ) ;
F_17 ( & V_7 -> V_10 . V_25 , V_26 ) ;
}
}
return V_19 ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
F_19 ( V_7 ) ;
V_9 = F_4 ( & V_7 -> V_10 ) ;
F_12 ( & V_7 -> V_10 , NULL ) ;
if ( V_9 -> V_12 ) {
F_8 ( & V_9 -> V_12 -> V_18 ) ;
F_9 ( & V_7 -> V_10 ) ;
}
F_14 ( V_9 ) ;
return 0 ;
}
static void F_20 ( struct V_6 * V_7 )
{
F_19 ( V_7 ) ;
}
static int F_21 ( struct V_6 * V_7 )
{
int V_27 ;
struct V_28 V_28 ;
V_27 = F_22 ( V_7 -> V_15 , & V_28 ) ;
if ( ! V_27 && F_23 ( & V_28 . V_29 ) )
return - V_30 ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
return F_19 ( V_7 ) ;
}
static int F_25 ( struct V_6 * V_7 )
{
return F_13 ( V_7 , ( V_24 ) ( unsigned long ) V_7 ) ;
}
static int T_1 F_26 ( void )
{
V_31 = F_27 ( L_5 , 16 , 1 ,
16 * sizeof( long ) ) ;
if ( ! V_31 )
goto V_32;
F_28 ( V_31 , & V_33 ) ;
F_29 ( V_31 , 2 ) ;
V_4 = F_27 ( L_6 , 16 , 1 , 16 ) ;
if ( ! V_4 )
goto V_32;
F_28 ( V_4 , & V_34 ) ;
F_29 ( V_4 , 2 ) ;
return 0 ;
V_32:
if ( V_31 )
F_30 ( V_31 ) ;
return - V_23 ;
}
static void F_31 ( void )
{
F_30 ( V_4 ) ;
F_30 ( V_31 ) ;
}
static int T_1 F_32 ( void )
{
return F_33 ( & V_35 ) ;
}
static void F_34 ( void )
{
F_35 ( & V_35 ) ;
}
static int F_36 ( struct V_36 * V_10 , void * V_2 )
{
struct V_6 * V_7 = F_37 ( V_10 ) ;
return V_7 -> V_28 . V_37 . V_38 && ! F_38 ( & V_7 -> V_28 . V_29 ) ;
}
static struct V_6 * F_39 ( struct V_6 * V_7 )
{
struct V_36 * V_10 ;
V_10 = F_40 ( & V_35 . V_39 ,
V_7 ? & V_7 -> V_10 : NULL , NULL ,
F_36 ) ;
return V_10 ? F_37 ( V_10 ) : NULL ;
}
static int F_41 ( struct V_40 * V_41 ,
struct V_11 * V_12 )
{
int V_27 ;
struct V_8 * V_9 ;
struct V_6 * V_7 = NULL ;
int V_19 = - V_42 ;
char V_43 [ 10 ] ;
V_41 -> V_44 . V_45 = V_46 >> 4 ;
while ( ( V_7 = F_39 ( V_7 ) ) ) {
F_42 ( V_7 -> V_47 ) ;
V_9 = F_4 ( & V_7 -> V_10 ) ;
if ( V_9 -> V_12 ) {
F_43 ( V_7 -> V_47 ) ;
V_19 = - V_48 ;
continue;
}
V_41 -> V_44 . V_49 = V_7 -> V_15 ;
F_5 ( 2 , L_7 ) ;
F_1 ( 2 , & V_7 -> V_15 , sizeof( V_7 -> V_15 ) ) ;
V_27 = F_44 ( V_41 ) ;
sprintf ( V_43 , L_8 , V_27 ) ;
F_5 ( 2 , V_43 ) ;
switch ( V_27 ) {
case 0 :
V_19 = 0 ;
break;
case 1 :
V_7 -> V_28 . V_29 . V_50 . V_51 |= V_52 ;
V_19 = - V_53 ;
V_9 -> V_12 = V_12 ;
break;
case 2 :
V_19 = - V_48 ;
break;
default:
V_19 = - V_42 ;
}
F_43 ( V_7 -> V_47 ) ;
F_6 ( 2 , L_9 ,
V_7 -> V_15 . V_16 , V_7 -> V_15 . V_17 , V_27 ) ;
if ( V_19 == - V_53 )
return - V_53 ;
F_9 ( & V_7 -> V_10 ) ;
if ( V_19 == 0 )
return 0 ;
}
return V_19 ;
}
static void F_45 ( struct V_40 * V_41 )
{
char V_43 [ 10 ] ;
sprintf ( V_43 , L_10 , V_41 -> V_44 . V_54 ) ;
F_5 ( 0 , V_43 ) ;
F_1 ( 0 , V_41 , 32 ) ;
}
static int F_46 ( struct V_11 * V_12 )
{
int V_55 ;
if ( ! ( F_23 ( & V_12 -> V_13 . V_29 ) & V_56 ) )
return - V_57 ;
V_55 = F_47 ( & V_12 -> V_13 . V_29 ) & V_58 ;
V_12 -> V_13 . V_29 . V_50 . V_59 &= ~ V_58 ;
if ( F_47 ( & V_12 -> V_13 . V_29 ) == 0 )
return 0 ;
if ( ! V_55 )
return 0 ;
if ( F_47 ( & V_12 -> V_13 . V_29 ) & V_60 )
return - V_57 ;
if ( F_47 ( & V_12 -> V_13 . V_29 ) & V_61 )
return - V_62 ;
if ( F_47 ( & V_12 -> V_13 . V_29 ) & V_63 )
return - V_30 ;
if ( F_47 ( & V_12 -> V_13 . V_29 ) & V_64 )
return - V_30 ;
return - V_57 ;
}
static int F_48 ( void T_2 * V_65 )
{
struct V_11 * V_12 ;
struct V_40 * V_41 ;
int V_19 ;
char V_43 [ 10 ] ;
if ( ! V_66 . V_67 )
return - V_68 ;
V_41 = ( void * ) F_49 ( V_69 | V_22 ) ;
if ( ! V_41 )
return - V_23 ;
V_12 = F_11 ( sizeof( * V_12 ) , V_22 ) ;
if ( ! V_12 ) {
V_19 = - V_23 ;
goto V_70;
}
F_50 ( & V_12 -> V_18 ) ;
if ( F_51 ( V_41 , V_65 , V_71 ) ) {
V_19 = - V_72 ;
goto V_70;
}
F_45 ( V_41 ) ;
F_52 ( & V_73 ) ;
V_19 = F_41 ( V_41 , V_12 ) ;
F_53 ( & V_73 ) ;
if ( V_19 == - V_53 ) {
F_54 ( & V_12 -> V_18 ) ;
V_19 = F_46 ( V_12 ) ;
}
if ( ! V_19 )
if ( F_55 ( V_65 , V_41 , V_71 ) )
V_19 = - V_72 ;
V_70:
sprintf ( V_43 , L_11 , V_19 ) ;
F_5 ( 0 , V_43 ) ;
F_14 ( V_12 ) ;
F_56 ( ( unsigned long ) V_41 ) ;
return V_19 ;
}
static int F_57 ( void T_2 * V_74 )
{
struct V_75 * V_76 ;
int V_19 , V_77 ;
struct {
struct V_78 V_12 ;
V_24 : 2 ;
V_24 V_79 : 1 ;
V_24 : 1 ;
V_24 V_80 : 4 ;
V_24 V_81 : 8 ;
V_24 : 8 ;
V_24 V_82 : 8 ;
V_24 : 24 ;
V_24 V_83 : 8 ;
V_24 : 32 ;
struct V_78 V_84 ;
T_3 V_2 [ V_71 - 20 ] ;
} V_85 ( ( V_86 ) ) * V_87 ;
V_87 = ( void * ) F_49 ( V_22 | V_69 ) ;
if ( ! V_87 )
return - V_23 ;
V_76 = F_11 ( sizeof( * V_76 ) , V_22 ) ;
if ( ! V_76 ) {
V_19 = - V_23 ;
goto V_70;
}
if ( F_51 ( V_76 , V_74 , sizeof( * V_76 ) ) ) {
V_19 = - V_72 ;
goto V_70;
}
V_87 -> V_12 . V_3 = 0x0010 ;
V_87 -> V_12 . V_54 = 0x0028 ;
V_87 -> V_79 = V_76 -> V_79 ;
V_87 -> V_80 = V_76 -> V_88 ;
V_87 -> V_81 = V_76 -> V_89 . V_81 ;
V_87 -> V_82 = V_76 -> V_89 . V_90 ;
V_87 -> V_83 = V_76 -> V_89 . V_90 ;
V_77 = F_44 ( V_87 ) ;
if ( V_77 != 0 ) {
V_19 = - V_57 ;
goto V_70;
}
if ( V_87 -> V_84 . V_54 != 0x0001 ) {
V_19 = - V_57 ;
F_6 ( 0 , L_12 ,
V_87 -> V_84 . V_54 ) ;
goto V_70;
}
memcpy ( & V_76 -> V_91 , & V_87 -> V_84 , V_87 -> V_84 . V_3 ) ;
if ( F_55 ( V_74 , V_76 , sizeof( * V_76 ) ) )
V_19 = - V_72 ;
else
V_19 = 0 ;
V_70:
F_14 ( V_76 ) ;
F_56 ( ( unsigned long ) V_87 ) ;
return V_19 ;
}
static int F_58 ( void T_2 * V_74 )
{
struct V_92 * V_76 ;
int V_19 , V_77 ;
struct {
struct V_78 V_12 ;
V_24 : 2 ;
V_24 V_79 : 1 ;
V_24 : 1 ;
V_24 V_80 : 4 ;
V_24 V_81 : 8 ;
V_24 : 8 ;
V_24 V_93 : 8 ;
V_24 : 24 ;
V_24 V_94 : 8 ;
V_24 : 32 ;
struct V_78 V_84 ;
T_3 V_2 [ V_71 - 20 ] ;
} V_85 ( ( V_86 ) ) * V_95 ;
V_95 = ( void * ) F_49 ( V_22 | V_69 ) ;
if ( ! V_95 )
return - V_23 ;
V_76 = F_11 ( sizeof( * V_76 ) , V_22 ) ;
if ( ! V_76 ) {
V_19 = - V_23 ;
goto V_70;
}
if ( F_51 ( V_76 , V_74 , sizeof( * V_76 ) ) ) {
V_19 = - V_72 ;
goto V_70;
}
V_95 -> V_12 . V_3 = 0x0010 ;
V_95 -> V_12 . V_54 = 0x0028 ;
V_95 -> V_79 = V_76 -> V_79 ;
V_95 -> V_80 = V_76 -> V_88 ;
V_95 -> V_81 = V_76 -> V_81 ;
V_95 -> V_93 = V_76 -> V_96 ;
V_95 -> V_94 = V_76 -> V_96 ;
V_77 = F_44 ( V_95 ) ;
if ( V_77 != 0 ) {
V_19 = - V_57 ;
goto V_70;
}
if ( V_95 -> V_84 . V_54 != 0x0001 ) {
V_19 = - V_57 ;
F_6 ( 0 , L_13 ,
V_95 -> V_84 . V_54 ) ;
goto V_70;
}
memcpy ( & V_76 -> V_97 , & V_95 -> V_84 , V_95 -> V_84 . V_3 ) ;
if ( F_55 ( V_74 , V_76 , sizeof( * V_76 ) ) )
V_19 = - V_72 ;
else
V_19 = 0 ;
V_70:
F_14 ( V_76 ) ;
F_56 ( ( unsigned long ) V_95 ) ;
return V_19 ;
}
static int F_59 ( void T_2 * V_98 )
{
struct V_99 * V_100 ;
int V_19 , V_77 ;
struct {
struct V_78 V_12 ;
V_24 : 2 ;
V_24 V_79 : 1 ;
V_24 : 5 ;
V_24 V_80 : 4 ;
V_24 : 2 ;
V_24 V_16 : 2 ;
V_24 V_101 : 16 ;
V_24 : 8 ;
V_24 V_81 : 8 ;
V_24 V_102 : 16 ;
V_24 : 32 ;
struct V_78 V_84 ;
T_3 V_2 [ V_71 - 20 ] ;
} V_85 ( ( V_86 ) ) * V_103 ;
V_103 = ( void * ) F_49 ( V_22 | V_69 ) ;
if ( ! V_103 )
return - V_23 ;
V_100 = F_11 ( sizeof( * V_100 ) , V_22 ) ;
if ( ! V_100 ) {
V_19 = - V_23 ;
goto V_70;
}
if ( F_51 ( V_100 , V_98 , sizeof( * V_100 ) ) ) {
V_19 = - V_72 ;
goto V_70;
}
V_103 -> V_12 . V_3 = 0x0010 ;
V_103 -> V_12 . V_54 = 0x0006 ;
V_103 -> V_79 = V_100 -> V_15 . V_79 ;
V_103 -> V_80 = V_100 -> V_88 ;
V_103 -> V_16 = V_100 -> V_15 . V_16 ;
V_103 -> V_101 = V_100 -> V_15 . V_17 ;
V_103 -> V_81 = V_100 -> V_15 . V_81 ;
V_103 -> V_102 = V_100 -> V_15 . V_17 ;
V_77 = F_44 ( V_103 ) ;
if ( V_77 != 0 ) {
V_19 = - V_57 ;
goto V_70;
}
if ( V_103 -> V_84 . V_54 != 0x0001 ) {
V_19 = - V_57 ;
F_6 ( 0 , L_14 ,
V_103 -> V_84 . V_54 ) ;
goto V_70;
}
memcpy ( & V_100 -> V_104 , & V_103 -> V_84 , V_103 -> V_84 . V_3 ) ;
if ( F_55 ( V_98 , V_100 , sizeof( * V_100 ) ) )
V_19 = - V_72 ;
else
V_19 = 0 ;
V_70:
F_14 ( V_100 ) ;
F_56 ( ( unsigned long ) V_103 ) ;
return V_19 ;
}
static int F_60 ( void T_2 * V_105 )
{
struct V_106 * V_107 ;
int V_19 , V_77 ;
struct {
struct V_78 V_12 ;
V_24 : 2 ;
V_24 V_79 : 1 ;
V_24 : 1 ;
V_24 V_80 : 4 ;
V_24 V_81 : 8 ;
V_24 : 6 ;
V_24 V_16 : 2 ;
V_24 : 8 ;
V_108 : 64 ;
struct V_78 V_84 ;
T_3 V_2 [ V_71 - 20 ] ;
} V_85 ( ( V_86 ) ) * V_109 ;
V_109 = ( void * ) F_49 ( V_22 | V_69 ) ;
if ( ! V_109 )
return - V_23 ;
V_107 = F_11 ( sizeof( * V_107 ) , V_22 ) ;
if ( ! V_107 ) {
V_19 = - V_23 ;
goto V_70;
}
if ( F_51 ( V_107 , V_105 , sizeof( * V_107 ) ) ) {
V_19 = - V_72 ;
goto V_70;
}
V_109 -> V_12 . V_3 = 0x0010 ;
V_109 -> V_12 . V_54 = 0x0012 ;
V_109 -> V_79 = V_107 -> V_90 . V_79 ;
V_109 -> V_80 = V_107 -> V_88 ;
V_109 -> V_81 = V_107 -> V_90 . V_81 ;
V_109 -> V_16 = V_107 -> V_90 . V_16 ;
V_77 = F_44 ( V_109 ) ;
if ( V_77 != 0 ) {
V_19 = - V_57 ;
goto V_70;
}
if ( V_109 -> V_84 . V_54 != 0x0001 ) {
V_19 = - V_57 ;
F_6 ( 0 , L_15 ,
V_109 -> V_84 . V_54 ) ;
goto V_70;
}
memcpy ( & V_107 -> V_110 , & V_109 -> V_84 , V_109 -> V_84 . V_3 ) ;
if ( F_55 ( V_105 , V_107 , sizeof( * V_107 ) ) )
V_19 = - V_72 ;
else
V_19 = 0 ;
V_70:
F_14 ( V_107 ) ;
F_56 ( ( unsigned long ) V_109 ) ;
return V_19 ;
}
static int F_61 ( void T_2 * V_111 )
{
struct V_112 * V_113 ;
int V_19 , V_77 ;
struct {
struct V_78 V_12 ;
V_24 V_114 : 8 ;
V_24 : 4 ;
V_24 V_88 : 4 ;
V_24 : 16 ;
V_108 : 64 ;
V_24 V_115 [ 2 ] ;
V_108 : 64 ;
struct V_78 V_84 ;
T_3 V_2 [ V_71 - 36 ] ;
} V_85 ( ( V_86 ) ) * V_116 ;
struct {
V_24 V_79 : 1 ;
V_24 : 31 ;
V_24 V_81 : 8 ;
V_24 : 16 ;
V_24 V_89 : 8 ;
} V_85 ( ( V_86 ) ) * V_117 ;
struct {
V_24 V_118 : 8 ;
V_24 V_119 : 8 ;
V_24 : 16 ;
V_24 V_120 ;
} V_85 ( ( V_86 ) ) * V_121 ;
V_116 = ( void * ) F_49 ( V_22 | V_69 ) ;
if ( ! V_116 )
return - V_23 ;
V_113 = F_11 ( sizeof( * V_113 ) , V_22 ) ;
if ( ! V_113 ) {
V_19 = - V_23 ;
goto V_70;
}
if ( F_51 ( V_113 , V_111 , sizeof( * V_113 ) ) ) {
V_19 = - V_72 ;
goto V_70;
}
V_116 -> V_12 . V_3 = 0x0020 ;
V_116 -> V_12 . V_54 = 0x0030 ;
V_116 -> V_88 = V_113 -> V_122 . V_88 ;
V_116 -> V_114 = V_113 -> V_122 . V_114 ;
switch ( V_116 -> V_114 ) {
case V_123 :
case V_124 :
V_117 = ( void * ) & V_116 -> V_115 ;
V_117 -> V_79 = V_113 -> V_122 . V_89 . V_79 ;
V_117 -> V_81 = V_113 -> V_122 . V_89 . V_125 . V_81 ;
V_117 -> V_89 = V_113 -> V_122 . V_89 . V_125 . V_90 ;
break;
case V_126 :
case V_127 :
V_121 = ( void * ) & V_116 -> V_115 ;
V_121 -> V_118 = V_113 -> V_122 . V_128 . V_118 ;
V_121 -> V_119 = V_113 -> V_122 . V_128 . V_119 ;
break;
}
V_77 = F_44 ( V_116 ) ;
if ( V_77 != 0 ) {
V_19 = - V_57 ;
goto V_70;
}
if ( V_116 -> V_84 . V_54 != 0x0001 ) {
V_19 = - V_57 ;
F_6 ( 0 , L_16 ,
V_116 -> V_84 . V_54 ) ;
goto V_70;
}
memcpy ( & V_113 -> V_129 , & V_116 -> V_84 , V_116 -> V_84 . V_3 ) ;
if ( F_55 ( V_111 , V_113 , sizeof( * V_113 ) ) )
V_19 = - V_72 ;
else
V_19 = 0 ;
V_70:
F_14 ( V_113 ) ;
F_56 ( ( unsigned long ) V_116 ) ;
return V_19 ;
}
static int F_62 ( void T_2 * V_130 )
{
struct V_131 * V_132 ;
struct V_133 * V_134 ;
int V_19 ;
V_134 = F_11 ( sizeof( * V_134 ) , V_22 ) ;
V_132 = ( void * ) F_49 ( V_22 | V_69 ) ;
if ( ! V_132 || ! V_134 ) {
V_19 = - V_23 ;
goto V_70;
}
if ( F_51 ( V_134 , V_130 , sizeof( * V_134 ) ) ) {
V_19 = - V_72 ;
goto V_70;
}
V_19 = F_63 ( V_134 -> V_89 , V_134 -> V_88 ,
V_134 -> V_135 , V_134 -> V_136 , V_134 -> V_79 ,
V_132 ) ;
if ( V_19 )
goto V_70;
memcpy ( & V_134 -> V_137 , & V_132 -> V_84 , V_132 -> V_84 . V_3 ) ;
if ( F_55 ( V_130 , V_134 , sizeof( * V_134 ) ) )
V_19 = - V_72 ;
V_70:
F_14 ( V_134 ) ;
F_56 ( ( unsigned long ) V_132 ) ;
return V_19 ;
}
static int F_64 ( void T_2 * V_138 )
{
struct V_139 * V_140 ;
int V_19 , V_77 ;
struct {
struct V_78 V_12 ;
V_24 V_141 : 8 ;
V_24 : 4 ;
V_24 V_88 : 4 ;
V_24 : 16 ;
V_24 V_142 [ 2 ] ;
V_24 V_115 [ 2 ] ;
V_24 V_143 [ 2 ] ;
struct V_78 V_84 ;
T_3 V_2 [ V_71 - 36 ] ;
} V_85 ( ( V_86 ) ) * V_144 ;
V_144 = ( void * ) F_49 ( V_22 | V_69 ) ;
if ( ! V_144 )
return - V_23 ;
V_140 = F_11 ( sizeof( * V_140 ) , V_22 ) ;
if ( ! V_140 ) {
V_19 = - V_23 ;
goto V_70;
}
if ( F_51 ( V_140 , V_138 , sizeof( * V_140 ) ) ) {
V_19 = - V_72 ;
goto V_70;
}
V_144 -> V_12 . V_3 = 0x0020 ;
V_144 -> V_12 . V_54 = 0x0034 ;
V_144 -> V_141 = V_140 -> V_122 . V_141 ;
V_144 -> V_88 = V_140 -> V_122 . V_88 ;
memcpy ( & V_144 -> V_115 , & V_140 -> V_122 . V_115 ,
sizeof( V_144 -> V_115 ) ) ;
V_77 = F_44 ( V_144 ) ;
if ( V_77 != 0 ) {
V_19 = - V_57 ;
goto V_70;
}
if ( V_144 -> V_84 . V_54 != 0x0001 ) {
V_19 = - V_57 ;
F_6 ( 0 , L_17 ,
V_144 -> V_84 . V_54 ) ;
goto V_70;
}
memcpy ( & V_140 -> V_145 , & V_144 -> V_84 ,
V_144 -> V_84 . V_3 ) ;
if ( F_55 ( V_138 , V_140 , sizeof( * V_140 ) ) )
V_19 = - V_72 ;
else
V_19 = 0 ;
V_70:
F_14 ( V_140 ) ;
F_56 ( ( unsigned long ) V_144 ) ;
return V_19 ;
}
static long F_65 ( struct V_146 * V_147 , unsigned int V_50 ,
unsigned long V_148 )
{
void T_2 * V_149 ;
F_6 ( 2 , L_18 , V_50 ) ;
if ( F_66 () )
V_149 = F_67 ( V_148 ) ;
else
V_149 = ( void T_2 * ) V_148 ;
switch ( V_50 ) {
case V_150 :
return F_48 ( V_149 ) ;
case V_151 :
return F_57 ( V_149 ) ;
case V_152 :
return F_58 ( V_149 ) ;
case V_153 :
return F_59 ( V_149 ) ;
case V_154 :
return F_60 ( V_149 ) ;
case V_155 :
return F_61 ( V_149 ) ;
case V_156 :
return F_62 ( V_149 ) ;
case V_157 :
return F_64 ( V_149 ) ;
default:
return - V_158 ;
}
}
static int T_1 F_68 ( void )
{
return F_69 ( & V_159 ) ;
}
static void F_70 ( void )
{
F_71 ( & V_159 ) ;
}
static int T_1 F_72 ( void )
{
int V_19 ;
V_19 = F_26 () ;
if ( V_19 )
return V_19 ;
F_73 ( V_21 ) ;
V_19 = F_32 () ;
if ( V_19 )
goto V_160;
V_19 = F_68 () ;
if ( V_19 )
goto V_161;
return V_19 ;
V_161:
F_34 () ;
V_160:
F_74 ( V_21 ) ;
F_31 () ;
return V_19 ;
}
static void T_4 F_75 ( void )
{
F_70 () ;
F_34 () ;
F_74 ( V_21 ) ;
F_31 () ;
}
