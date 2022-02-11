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
F_6 ( F_7 () ) . V_15 [ V_16 ] ++ ;
if ( ! V_12 ) {
F_8 ( 0 , L_2 ,
V_7 -> V_17 . V_18 , V_7 -> V_17 . V_19 ) ;
return;
}
V_9 -> V_12 = NULL ;
memcpy ( & V_12 -> V_13 , V_13 , sizeof( * V_13 ) ) ;
F_9 ( V_7 ) ;
F_10 ( & V_12 -> V_20 ) ;
F_11 ( & V_7 -> V_10 ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_21 ;
F_8 ( 6 , L_3 ,
V_7 -> V_17 . V_18 , V_7 -> V_17 . V_19 ) ;
V_7 -> V_22 = V_23 ;
V_9 = F_13 ( sizeof( * V_9 ) , V_24 ) ;
if ( ! V_9 )
return - V_25 ;
F_14 ( & V_7 -> V_10 , V_9 ) ;
V_21 = F_15 ( V_7 , ( V_26 ) ( unsigned long ) V_7 ) ;
if ( V_21 ) {
F_8 ( 0 , L_4 ,
V_7 -> V_17 . V_18 , V_7 -> V_17 . V_19 , V_21 ) ;
F_14 ( & V_7 -> V_10 , NULL ) ;
F_16 ( V_9 ) ;
} else {
if ( F_17 ( & V_7 -> V_10 ) ) {
F_18 ( & V_7 -> V_10 , 0 ) ;
F_19 ( & V_7 -> V_10 . V_27 , V_28 ) ;
}
}
return V_21 ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
F_21 ( V_7 ) ;
V_9 = F_4 ( & V_7 -> V_10 ) ;
F_14 ( & V_7 -> V_10 , NULL ) ;
if ( V_9 -> V_12 ) {
F_10 ( & V_9 -> V_12 -> V_20 ) ;
F_11 ( & V_7 -> V_10 ) ;
}
F_16 ( V_9 ) ;
return 0 ;
}
static void F_22 ( struct V_6 * V_7 )
{
F_21 ( V_7 ) ;
}
static int F_23 ( struct V_6 * V_7 )
{
int V_29 ;
struct V_30 V_30 ;
V_29 = F_24 ( V_7 -> V_17 , & V_30 ) ;
if ( ! V_29 && F_25 ( & V_30 . V_31 ) )
return - V_32 ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 )
{
return F_21 ( V_7 ) ;
}
static int F_27 ( struct V_6 * V_7 )
{
return F_15 ( V_7 , ( V_26 ) ( unsigned long ) V_7 ) ;
}
static int T_1 F_28 ( void )
{
V_33 = F_29 ( L_5 , 16 , 1 ,
16 * sizeof( long ) ) ;
if ( ! V_33 )
goto V_34;
F_30 ( V_33 , & V_35 ) ;
F_31 ( V_33 , 2 ) ;
V_4 = F_29 ( L_6 , 16 , 1 , 16 ) ;
if ( ! V_4 )
goto V_34;
F_30 ( V_4 , & V_36 ) ;
F_31 ( V_4 , 2 ) ;
return 0 ;
V_34:
if ( V_33 )
F_32 ( V_33 ) ;
return - V_25 ;
}
static void F_33 ( void )
{
F_32 ( V_4 ) ;
F_32 ( V_33 ) ;
}
static int T_1 F_34 ( void )
{
return F_35 ( & V_37 ) ;
}
static void F_36 ( void )
{
F_37 ( & V_37 ) ;
}
static int F_38 ( struct V_38 * V_10 , void * V_2 )
{
struct V_6 * V_7 = F_39 ( V_10 ) ;
return V_7 -> V_30 . V_39 . V_40 && ! F_40 ( & V_7 -> V_30 . V_31 ) ;
}
static struct V_6 * F_41 ( struct V_6 * V_7 )
{
struct V_38 * V_10 ;
V_10 = F_42 ( & V_37 . V_41 ,
V_7 ? & V_7 -> V_10 : NULL , NULL ,
F_38 ) ;
return V_10 ? F_39 ( V_10 ) : NULL ;
}
static int F_43 ( struct V_42 * V_43 ,
struct V_11 * V_12 )
{
int V_29 ;
struct V_8 * V_9 ;
struct V_6 * V_7 = NULL ;
int V_21 = - V_44 ;
char V_45 [ 10 ] ;
V_43 -> V_46 . V_47 = V_48 >> 4 ;
while ( ( V_7 = F_41 ( V_7 ) ) ) {
F_44 ( V_7 -> V_49 ) ;
V_9 = F_4 ( & V_7 -> V_10 ) ;
if ( V_9 -> V_12 ) {
F_45 ( V_7 -> V_49 ) ;
V_21 = - V_50 ;
continue;
}
V_43 -> V_46 . V_51 = V_7 -> V_17 ;
F_5 ( 2 , L_7 ) ;
F_1 ( 2 , & V_7 -> V_17 , sizeof( V_7 -> V_17 ) ) ;
V_29 = F_46 ( V_43 ) ;
sprintf ( V_45 , L_8 , V_29 ) ;
F_5 ( 2 , V_45 ) ;
switch ( V_29 ) {
case 0 :
V_21 = 0 ;
break;
case 1 :
V_7 -> V_30 . V_31 . V_52 . V_53 |= V_54 ;
V_21 = - V_55 ;
V_9 -> V_12 = V_12 ;
break;
case 2 :
V_21 = - V_50 ;
break;
default:
V_21 = - V_44 ;
}
F_45 ( V_7 -> V_49 ) ;
F_8 ( 2 , L_9 ,
V_7 -> V_17 . V_18 , V_7 -> V_17 . V_19 , V_29 ) ;
if ( V_21 == - V_55 )
return - V_55 ;
F_11 ( & V_7 -> V_10 ) ;
if ( V_21 == 0 )
return 0 ;
}
return V_21 ;
}
static void F_47 ( struct V_42 * V_43 )
{
char V_45 [ 10 ] ;
sprintf ( V_45 , L_10 , V_43 -> V_46 . V_56 ) ;
F_5 ( 0 , V_45 ) ;
F_1 ( 0 , V_43 , 32 ) ;
}
static int F_48 ( struct V_11 * V_12 )
{
int V_57 ;
if ( ! ( F_25 ( & V_12 -> V_13 . V_31 ) & V_58 ) )
return - V_59 ;
V_57 = F_49 ( & V_12 -> V_13 . V_31 ) & V_60 ;
V_12 -> V_13 . V_31 . V_52 . V_61 &= ~ V_60 ;
if ( F_49 ( & V_12 -> V_13 . V_31 ) == 0 )
return 0 ;
if ( ! V_57 )
return 0 ;
if ( F_49 ( & V_12 -> V_13 . V_31 ) & V_62 )
return - V_59 ;
if ( F_49 ( & V_12 -> V_13 . V_31 ) & V_63 )
return - V_64 ;
if ( F_49 ( & V_12 -> V_13 . V_31 ) & V_65 )
return - V_32 ;
if ( F_49 ( & V_12 -> V_13 . V_31 ) & V_66 )
return - V_32 ;
return - V_59 ;
}
static int F_50 ( void T_2 * V_67 )
{
struct V_11 * V_12 ;
struct V_42 * V_43 ;
int V_21 ;
char V_45 [ 10 ] ;
if ( ! V_68 . V_69 )
return - V_70 ;
V_43 = ( void * ) F_51 ( V_71 | V_24 ) ;
if ( ! V_43 )
return - V_25 ;
V_12 = F_13 ( sizeof( * V_12 ) , V_24 ) ;
if ( ! V_12 ) {
V_21 = - V_25 ;
goto V_72;
}
F_52 ( & V_12 -> V_20 ) ;
if ( F_53 ( V_43 , V_67 , V_73 ) ) {
V_21 = - V_74 ;
goto V_72;
}
F_47 ( V_43 ) ;
F_54 ( & V_75 ) ;
V_21 = F_43 ( V_43 , V_12 ) ;
F_55 ( & V_75 ) ;
if ( V_21 == - V_55 ) {
F_56 ( & V_12 -> V_20 ) ;
V_21 = F_48 ( V_12 ) ;
}
if ( ! V_21 )
if ( F_57 ( V_67 , V_43 , V_73 ) )
V_21 = - V_74 ;
V_72:
sprintf ( V_45 , L_11 , V_21 ) ;
F_5 ( 0 , V_45 ) ;
F_16 ( V_12 ) ;
F_58 ( ( unsigned long ) V_43 ) ;
return V_21 ;
}
static int F_59 ( void T_2 * V_76 )
{
struct V_77 * V_78 ;
int V_21 , V_79 ;
struct {
struct V_80 V_12 ;
V_26 : 2 ;
V_26 V_81 : 1 ;
V_26 : 1 ;
V_26 V_82 : 4 ;
V_26 V_83 : 8 ;
V_26 : 8 ;
V_26 V_84 : 8 ;
V_26 : 24 ;
V_26 V_85 : 8 ;
V_26 : 32 ;
struct V_80 V_86 ;
T_3 V_2 [ V_73 - 20 ] ;
} V_87 ( ( V_88 ) ) * V_89 ;
V_89 = ( void * ) F_51 ( V_24 | V_71 ) ;
if ( ! V_89 )
return - V_25 ;
V_78 = F_13 ( sizeof( * V_78 ) , V_24 ) ;
if ( ! V_78 ) {
V_21 = - V_25 ;
goto V_72;
}
if ( F_53 ( V_78 , V_76 , sizeof( * V_78 ) ) ) {
V_21 = - V_74 ;
goto V_72;
}
V_89 -> V_12 . V_3 = 0x0010 ;
V_89 -> V_12 . V_56 = 0x0028 ;
V_89 -> V_81 = V_78 -> V_81 ;
V_89 -> V_82 = V_78 -> V_90 ;
V_89 -> V_83 = V_78 -> V_91 . V_83 ;
V_89 -> V_84 = V_78 -> V_91 . V_92 ;
V_89 -> V_85 = V_78 -> V_91 . V_92 ;
V_79 = F_46 ( V_89 ) ;
if ( V_79 != 0 ) {
V_21 = - V_59 ;
goto V_72;
}
if ( V_89 -> V_86 . V_56 != 0x0001 ) {
V_21 = - V_59 ;
F_8 ( 0 , L_12 ,
V_89 -> V_86 . V_56 ) ;
goto V_72;
}
memcpy ( & V_78 -> V_93 , & V_89 -> V_86 , V_89 -> V_86 . V_3 ) ;
if ( F_57 ( V_76 , V_78 , sizeof( * V_78 ) ) )
V_21 = - V_74 ;
else
V_21 = 0 ;
V_72:
F_16 ( V_78 ) ;
F_58 ( ( unsigned long ) V_89 ) ;
return V_21 ;
}
static int F_60 ( void T_2 * V_76 )
{
struct V_94 * V_78 ;
int V_21 , V_79 ;
struct {
struct V_80 V_12 ;
V_26 : 2 ;
V_26 V_81 : 1 ;
V_26 : 1 ;
V_26 V_82 : 4 ;
V_26 V_83 : 8 ;
V_26 : 8 ;
V_26 V_95 : 8 ;
V_26 : 24 ;
V_26 V_96 : 8 ;
V_26 : 32 ;
struct V_80 V_86 ;
T_3 V_2 [ V_73 - 20 ] ;
} V_87 ( ( V_88 ) ) * V_97 ;
V_97 = ( void * ) F_51 ( V_24 | V_71 ) ;
if ( ! V_97 )
return - V_25 ;
V_78 = F_13 ( sizeof( * V_78 ) , V_24 ) ;
if ( ! V_78 ) {
V_21 = - V_25 ;
goto V_72;
}
if ( F_53 ( V_78 , V_76 , sizeof( * V_78 ) ) ) {
V_21 = - V_74 ;
goto V_72;
}
V_97 -> V_12 . V_3 = 0x0010 ;
V_97 -> V_12 . V_56 = 0x0028 ;
V_97 -> V_81 = V_78 -> V_81 ;
V_97 -> V_82 = V_78 -> V_90 ;
V_97 -> V_83 = V_78 -> V_83 ;
V_97 -> V_95 = V_78 -> V_98 ;
V_97 -> V_96 = V_78 -> V_98 ;
V_79 = F_46 ( V_97 ) ;
if ( V_79 != 0 ) {
V_21 = - V_59 ;
goto V_72;
}
if ( V_97 -> V_86 . V_56 != 0x0001 ) {
V_21 = - V_59 ;
F_8 ( 0 , L_13 ,
V_97 -> V_86 . V_56 ) ;
goto V_72;
}
memcpy ( & V_78 -> V_99 , & V_97 -> V_86 , V_97 -> V_86 . V_3 ) ;
if ( F_57 ( V_76 , V_78 , sizeof( * V_78 ) ) )
V_21 = - V_74 ;
else
V_21 = 0 ;
V_72:
F_16 ( V_78 ) ;
F_58 ( ( unsigned long ) V_97 ) ;
return V_21 ;
}
static int F_61 ( void T_2 * V_100 )
{
struct V_101 * V_102 ;
int V_21 , V_79 ;
struct {
struct V_80 V_12 ;
V_26 : 2 ;
V_26 V_81 : 1 ;
V_26 : 5 ;
V_26 V_82 : 4 ;
V_26 : 2 ;
V_26 V_18 : 2 ;
V_26 V_103 : 16 ;
V_26 : 8 ;
V_26 V_83 : 8 ;
V_26 V_104 : 16 ;
V_26 : 32 ;
struct V_80 V_86 ;
T_3 V_2 [ V_73 - 20 ] ;
} V_87 ( ( V_88 ) ) * V_105 ;
V_105 = ( void * ) F_51 ( V_24 | V_71 ) ;
if ( ! V_105 )
return - V_25 ;
V_102 = F_13 ( sizeof( * V_102 ) , V_24 ) ;
if ( ! V_102 ) {
V_21 = - V_25 ;
goto V_72;
}
if ( F_53 ( V_102 , V_100 , sizeof( * V_102 ) ) ) {
V_21 = - V_74 ;
goto V_72;
}
V_105 -> V_12 . V_3 = 0x0010 ;
V_105 -> V_12 . V_56 = 0x0006 ;
V_105 -> V_81 = V_102 -> V_17 . V_81 ;
V_105 -> V_82 = V_102 -> V_90 ;
V_105 -> V_18 = V_102 -> V_17 . V_18 ;
V_105 -> V_103 = V_102 -> V_17 . V_19 ;
V_105 -> V_83 = V_102 -> V_17 . V_83 ;
V_105 -> V_104 = V_102 -> V_17 . V_19 ;
V_79 = F_46 ( V_105 ) ;
if ( V_79 != 0 ) {
V_21 = - V_59 ;
goto V_72;
}
if ( V_105 -> V_86 . V_56 != 0x0001 ) {
V_21 = - V_59 ;
F_8 ( 0 , L_14 ,
V_105 -> V_86 . V_56 ) ;
goto V_72;
}
memcpy ( & V_102 -> V_106 , & V_105 -> V_86 , V_105 -> V_86 . V_3 ) ;
if ( F_57 ( V_100 , V_102 , sizeof( * V_102 ) ) )
V_21 = - V_74 ;
else
V_21 = 0 ;
V_72:
F_16 ( V_102 ) ;
F_58 ( ( unsigned long ) V_105 ) ;
return V_21 ;
}
static int F_62 ( void T_2 * V_107 )
{
struct V_108 * V_109 ;
int V_21 , V_79 ;
struct {
struct V_80 V_12 ;
V_26 : 2 ;
V_26 V_81 : 1 ;
V_26 : 1 ;
V_26 V_82 : 4 ;
V_26 V_83 : 8 ;
V_26 : 6 ;
V_26 V_18 : 2 ;
V_26 : 8 ;
V_110 : 64 ;
struct V_80 V_86 ;
T_3 V_2 [ V_73 - 20 ] ;
} V_87 ( ( V_88 ) ) * V_111 ;
V_111 = ( void * ) F_51 ( V_24 | V_71 ) ;
if ( ! V_111 )
return - V_25 ;
V_109 = F_13 ( sizeof( * V_109 ) , V_24 ) ;
if ( ! V_109 ) {
V_21 = - V_25 ;
goto V_72;
}
if ( F_53 ( V_109 , V_107 , sizeof( * V_109 ) ) ) {
V_21 = - V_74 ;
goto V_72;
}
V_111 -> V_12 . V_3 = 0x0010 ;
V_111 -> V_12 . V_56 = 0x0012 ;
V_111 -> V_81 = V_109 -> V_92 . V_81 ;
V_111 -> V_82 = V_109 -> V_90 ;
V_111 -> V_83 = V_109 -> V_92 . V_83 ;
V_111 -> V_18 = V_109 -> V_92 . V_18 ;
V_79 = F_46 ( V_111 ) ;
if ( V_79 != 0 ) {
V_21 = - V_59 ;
goto V_72;
}
if ( V_111 -> V_86 . V_56 != 0x0001 ) {
V_21 = - V_59 ;
F_8 ( 0 , L_15 ,
V_111 -> V_86 . V_56 ) ;
goto V_72;
}
memcpy ( & V_109 -> V_112 , & V_111 -> V_86 , V_111 -> V_86 . V_3 ) ;
if ( F_57 ( V_107 , V_109 , sizeof( * V_109 ) ) )
V_21 = - V_74 ;
else
V_21 = 0 ;
V_72:
F_16 ( V_109 ) ;
F_58 ( ( unsigned long ) V_111 ) ;
return V_21 ;
}
static int F_63 ( void T_2 * V_113 )
{
struct V_114 * V_115 ;
int V_21 , V_79 ;
struct {
struct V_80 V_12 ;
V_26 V_116 : 8 ;
V_26 : 4 ;
V_26 V_90 : 4 ;
V_26 : 16 ;
V_110 : 64 ;
V_26 V_117 [ 2 ] ;
V_110 : 64 ;
struct V_80 V_86 ;
T_3 V_2 [ V_73 - 36 ] ;
} V_87 ( ( V_88 ) ) * V_118 ;
struct {
V_26 V_81 : 1 ;
V_26 : 31 ;
V_26 V_83 : 8 ;
V_26 : 16 ;
V_26 V_91 : 8 ;
} V_87 ( ( V_88 ) ) * V_119 ;
struct {
V_26 V_120 : 8 ;
V_26 V_121 : 8 ;
V_26 : 16 ;
V_26 V_122 ;
} V_87 ( ( V_88 ) ) * V_123 ;
V_118 = ( void * ) F_51 ( V_24 | V_71 ) ;
if ( ! V_118 )
return - V_25 ;
V_115 = F_13 ( sizeof( * V_115 ) , V_24 ) ;
if ( ! V_115 ) {
V_21 = - V_25 ;
goto V_72;
}
if ( F_53 ( V_115 , V_113 , sizeof( * V_115 ) ) ) {
V_21 = - V_74 ;
goto V_72;
}
V_118 -> V_12 . V_3 = 0x0020 ;
V_118 -> V_12 . V_56 = 0x0030 ;
V_118 -> V_90 = V_115 -> V_124 . V_90 ;
V_118 -> V_116 = V_115 -> V_124 . V_116 ;
switch ( V_118 -> V_116 ) {
case V_125 :
case V_126 :
V_119 = ( void * ) & V_118 -> V_117 ;
V_119 -> V_81 = V_115 -> V_124 . V_91 . V_81 ;
V_119 -> V_83 = V_115 -> V_124 . V_91 . V_127 . V_83 ;
V_119 -> V_91 = V_115 -> V_124 . V_91 . V_127 . V_92 ;
break;
case V_128 :
case V_129 :
V_123 = ( void * ) & V_118 -> V_117 ;
V_123 -> V_120 = V_115 -> V_124 . V_130 . V_120 ;
V_123 -> V_121 = V_115 -> V_124 . V_130 . V_121 ;
break;
}
V_79 = F_46 ( V_118 ) ;
if ( V_79 != 0 ) {
V_21 = - V_59 ;
goto V_72;
}
if ( V_118 -> V_86 . V_56 != 0x0001 ) {
V_21 = - V_59 ;
F_8 ( 0 , L_16 ,
V_118 -> V_86 . V_56 ) ;
goto V_72;
}
memcpy ( & V_115 -> V_131 , & V_118 -> V_86 , V_118 -> V_86 . V_3 ) ;
if ( F_57 ( V_113 , V_115 , sizeof( * V_115 ) ) )
V_21 = - V_74 ;
else
V_21 = 0 ;
V_72:
F_16 ( V_115 ) ;
F_58 ( ( unsigned long ) V_118 ) ;
return V_21 ;
}
static int F_64 ( void T_2 * V_132 )
{
struct V_133 * V_134 ;
struct V_135 * V_136 ;
int V_21 ;
V_136 = F_13 ( sizeof( * V_136 ) , V_24 ) ;
V_134 = ( void * ) F_51 ( V_24 | V_71 ) ;
if ( ! V_134 || ! V_136 ) {
V_21 = - V_25 ;
goto V_72;
}
if ( F_53 ( V_136 , V_132 , sizeof( * V_136 ) ) ) {
V_21 = - V_74 ;
goto V_72;
}
V_21 = F_65 ( V_136 -> V_91 , V_136 -> V_90 ,
V_136 -> V_137 , V_136 -> V_138 , V_136 -> V_81 ,
V_134 ) ;
if ( V_21 )
goto V_72;
memcpy ( & V_136 -> V_139 , & V_134 -> V_86 , V_134 -> V_86 . V_3 ) ;
if ( F_57 ( V_132 , V_136 , sizeof( * V_136 ) ) )
V_21 = - V_74 ;
V_72:
F_16 ( V_136 ) ;
F_58 ( ( unsigned long ) V_134 ) ;
return V_21 ;
}
static int F_66 ( void T_2 * V_140 )
{
struct V_141 * V_142 ;
int V_21 , V_79 ;
struct {
struct V_80 V_12 ;
V_26 V_143 : 8 ;
V_26 : 4 ;
V_26 V_90 : 4 ;
V_26 : 16 ;
V_26 V_144 [ 2 ] ;
V_26 V_117 [ 2 ] ;
V_26 V_145 [ 2 ] ;
struct V_80 V_86 ;
T_3 V_2 [ V_73 - 36 ] ;
} V_87 ( ( V_88 ) ) * V_146 ;
V_146 = ( void * ) F_51 ( V_24 | V_71 ) ;
if ( ! V_146 )
return - V_25 ;
V_142 = F_13 ( sizeof( * V_142 ) , V_24 ) ;
if ( ! V_142 ) {
V_21 = - V_25 ;
goto V_72;
}
if ( F_53 ( V_142 , V_140 , sizeof( * V_142 ) ) ) {
V_21 = - V_74 ;
goto V_72;
}
V_146 -> V_12 . V_3 = 0x0020 ;
V_146 -> V_12 . V_56 = 0x0034 ;
V_146 -> V_143 = V_142 -> V_124 . V_143 ;
V_146 -> V_90 = V_142 -> V_124 . V_90 ;
memcpy ( & V_146 -> V_117 , & V_142 -> V_124 . V_117 ,
sizeof( V_146 -> V_117 ) ) ;
V_79 = F_46 ( V_146 ) ;
if ( V_79 != 0 ) {
V_21 = - V_59 ;
goto V_72;
}
if ( V_146 -> V_86 . V_56 != 0x0001 ) {
V_21 = - V_59 ;
F_8 ( 0 , L_17 ,
V_146 -> V_86 . V_56 ) ;
goto V_72;
}
memcpy ( & V_142 -> V_147 , & V_146 -> V_86 ,
V_146 -> V_86 . V_3 ) ;
if ( F_57 ( V_140 , V_142 , sizeof( * V_142 ) ) )
V_21 = - V_74 ;
else
V_21 = 0 ;
V_72:
F_16 ( V_142 ) ;
F_58 ( ( unsigned long ) V_146 ) ;
return V_21 ;
}
static long F_67 ( struct V_148 * V_149 , unsigned int V_52 ,
unsigned long V_150 )
{
void T_2 * V_151 ;
F_8 ( 2 , L_18 , V_52 ) ;
if ( F_68 () )
V_151 = F_69 ( V_150 ) ;
else
V_151 = ( void T_2 * ) V_150 ;
switch ( V_52 ) {
case V_152 :
return F_50 ( V_151 ) ;
case V_153 :
return F_59 ( V_151 ) ;
case V_154 :
return F_60 ( V_151 ) ;
case V_155 :
return F_61 ( V_151 ) ;
case V_156 :
return F_62 ( V_151 ) ;
case V_157 :
return F_63 ( V_151 ) ;
case V_158 :
return F_64 ( V_151 ) ;
case V_159 :
return F_66 ( V_151 ) ;
default:
return - V_160 ;
}
}
static int T_1 F_70 ( void )
{
return F_71 ( & V_161 ) ;
}
static void F_72 ( void )
{
F_73 ( & V_161 ) ;
}
static int T_1 F_74 ( void )
{
int V_21 ;
V_21 = F_28 () ;
if ( V_21 )
return V_21 ;
F_75 ( V_23 ) ;
V_21 = F_34 () ;
if ( V_21 )
goto V_162;
V_21 = F_70 () ;
if ( V_21 )
goto V_163;
return V_21 ;
V_163:
F_36 () ;
V_162:
F_76 ( V_23 ) ;
F_33 () ;
return V_21 ;
}
static void T_4 F_77 ( void )
{
F_72 () ;
F_36 () ;
F_76 ( V_23 ) ;
F_33 () ;
}
