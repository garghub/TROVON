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
struct V_13 * V_13 = F_5 ( & V_14 ) ;
F_6 ( 4 , L_1 ) ;
F_1 ( 4 , V_13 , sizeof( * V_13 ) ) ;
F_7 ( V_15 ) ;
if ( ! V_12 ) {
F_8 ( 0 , L_2 ,
V_7 -> V_16 . V_17 , V_7 -> V_16 . V_18 ) ;
return;
}
V_9 -> V_12 = NULL ;
memcpy ( & V_12 -> V_13 , V_13 , sizeof( * V_13 ) ) ;
F_9 ( V_7 ) ;
F_10 ( & V_12 -> V_19 ) ;
F_11 ( & V_7 -> V_10 ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_20 ;
F_8 ( 6 , L_3 ,
V_7 -> V_16 . V_17 , V_7 -> V_16 . V_18 ) ;
V_7 -> V_21 = V_22 ;
V_9 = F_13 ( sizeof( * V_9 ) , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
F_14 ( & V_7 -> V_10 , V_9 ) ;
V_20 = F_15 ( V_7 , ( V_25 ) ( unsigned long ) V_7 ) ;
if ( V_20 ) {
F_8 ( 0 , L_4 ,
V_7 -> V_16 . V_17 , V_7 -> V_16 . V_18 , V_20 ) ;
F_14 ( & V_7 -> V_10 , NULL ) ;
F_16 ( V_9 ) ;
} else {
if ( F_17 ( & V_7 -> V_10 ) ) {
F_18 ( & V_7 -> V_10 , 0 ) ;
F_19 ( & V_7 -> V_10 . V_26 , V_27 ) ;
}
}
return V_20 ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
F_21 ( V_7 ) ;
V_9 = F_4 ( & V_7 -> V_10 ) ;
F_14 ( & V_7 -> V_10 , NULL ) ;
if ( V_9 -> V_12 ) {
F_10 ( & V_9 -> V_12 -> V_19 ) ;
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
int V_28 ;
struct V_29 V_29 ;
V_28 = F_24 ( V_7 -> V_16 , & V_29 ) ;
if ( ! V_28 && F_25 ( & V_29 . V_30 ) )
return - V_31 ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 )
{
return F_21 ( V_7 ) ;
}
static int F_27 ( struct V_6 * V_7 )
{
return F_15 ( V_7 , ( V_25 ) ( unsigned long ) V_7 ) ;
}
static int T_1 F_28 ( void )
{
V_32 = F_29 ( L_5 , 8 , 1 , 4 * sizeof( long ) ) ;
if ( ! V_32 )
goto V_33;
F_30 ( V_32 , & V_34 ) ;
F_31 ( V_32 , 2 ) ;
V_4 = F_29 ( L_6 , 16 , 1 , 16 ) ;
if ( ! V_4 )
goto V_33;
F_30 ( V_4 , & V_35 ) ;
F_31 ( V_4 , 2 ) ;
return 0 ;
V_33:
F_32 ( V_32 ) ;
return - V_24 ;
}
static void F_33 ( void )
{
F_32 ( V_4 ) ;
F_32 ( V_32 ) ;
}
static int T_1 F_34 ( void )
{
return F_35 ( & V_36 ) ;
}
static void F_36 ( void )
{
F_37 ( & V_36 ) ;
}
static int F_38 ( struct V_37 * V_10 , void * V_2 )
{
struct V_6 * V_7 = F_39 ( V_10 ) ;
return V_7 -> V_29 . V_38 . V_39 && ! F_40 ( & V_7 -> V_29 . V_30 ) ;
}
static struct V_6 * F_41 ( struct V_6 * V_7 )
{
struct V_37 * V_10 ;
V_10 = F_42 ( & V_36 . V_40 ,
V_7 ? & V_7 -> V_10 : NULL , NULL ,
F_38 ) ;
return V_10 ? F_39 ( V_10 ) : NULL ;
}
static int F_43 ( struct V_41 * V_42 ,
struct V_11 * V_12 )
{
int V_28 ;
struct V_8 * V_9 ;
struct V_6 * V_7 = NULL ;
int V_20 = - V_43 ;
char V_44 [ 10 ] ;
V_42 -> V_45 . V_46 = V_47 >> 4 ;
while ( ( V_7 = F_41 ( V_7 ) ) ) {
F_44 ( V_7 -> V_48 ) ;
V_9 = F_4 ( & V_7 -> V_10 ) ;
if ( V_9 -> V_12 ) {
F_45 ( V_7 -> V_48 ) ;
V_20 = - V_49 ;
continue;
}
V_42 -> V_45 . V_50 = V_7 -> V_16 ;
F_6 ( 2 , L_7 ) ;
F_1 ( 2 , & V_7 -> V_16 , sizeof( V_7 -> V_16 ) ) ;
V_28 = F_46 ( V_42 ) ;
snprintf ( V_44 , sizeof( V_44 ) , L_8 , V_28 ) ;
F_6 ( 2 , V_44 ) ;
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
F_45 ( V_7 -> V_48 ) ;
F_8 ( 2 , L_9 ,
V_7 -> V_16 . V_17 , V_7 -> V_16 . V_18 , V_28 ) ;
if ( V_20 == - V_54 )
return - V_54 ;
F_11 ( & V_7 -> V_10 ) ;
if ( V_20 == 0 )
return 0 ;
}
return V_20 ;
}
static void F_47 ( void * V_42 )
{
char V_44 [ 10 ] ;
snprintf ( V_44 , sizeof( V_44 ) , L_10 , ( ( V_55 * ) V_42 ) [ 1 ] ) ;
F_6 ( 0 , V_44 ) ;
F_1 ( 0 , V_42 , 32 ) ;
}
static int F_48 ( struct V_11 * V_12 )
{
int V_56 ;
if ( ! ( F_25 ( & V_12 -> V_13 . V_30 ) & V_57 ) )
return - V_58 ;
V_56 = F_49 ( & V_12 -> V_13 . V_30 ) & V_59 ;
V_12 -> V_13 . V_30 . V_51 . V_60 &= ~ V_59 ;
if ( F_49 ( & V_12 -> V_13 . V_30 ) == 0 )
return 0 ;
if ( ! V_56 )
return 0 ;
if ( F_49 ( & V_12 -> V_13 . V_30 ) & V_61 )
return - V_58 ;
if ( F_49 ( & V_12 -> V_13 . V_30 ) & V_62 )
return - V_63 ;
if ( F_49 ( & V_12 -> V_13 . V_30 ) & V_64 )
return - V_31 ;
if ( F_49 ( & V_12 -> V_13 . V_30 ) & V_65 )
return - V_31 ;
return - V_58 ;
}
static int F_50 ( void T_2 * V_66 )
{
struct V_11 * V_12 ;
struct V_41 * V_42 ;
int V_20 ;
char V_44 [ 10 ] ;
if ( ! V_67 . V_68 )
return - V_69 ;
V_42 = ( void * ) F_51 ( V_70 | V_23 ) ;
if ( ! V_42 )
return - V_24 ;
V_12 = F_13 ( sizeof( * V_12 ) , V_23 ) ;
if ( ! V_12 ) {
V_20 = - V_24 ;
goto V_71;
}
F_52 ( & V_12 -> V_19 ) ;
if ( F_53 ( V_42 , V_66 , V_72 ) ) {
V_20 = - V_73 ;
goto V_71;
}
F_47 ( V_42 ) ;
F_54 ( & V_74 ) ;
V_20 = F_43 ( V_42 , V_12 ) ;
F_55 ( & V_74 ) ;
if ( V_20 == - V_54 ) {
F_56 ( & V_12 -> V_19 ) ;
V_20 = F_48 ( V_12 ) ;
}
if ( ! V_20 )
if ( F_57 ( V_66 , V_42 , V_72 ) )
V_20 = - V_73 ;
V_71:
snprintf ( V_44 , sizeof( V_44 ) , L_11 , V_20 ) ;
F_6 ( 0 , V_44 ) ;
F_16 ( V_12 ) ;
F_58 ( ( unsigned long ) V_42 ) ;
return V_20 ;
}
static int F_59 ( void T_2 * V_66 )
{
char V_44 [ 13 ] ;
int V_20 ;
F_60 ( & V_75 ) ;
if ( V_76 ) {
V_20 = - V_49 ;
goto V_77;
}
V_78 = F_13 ( sizeof( * V_78 ) , V_23 ) ;
if ( ! V_78 ) {
V_20 = - V_24 ;
goto V_77;
}
V_76 = ( void * ) F_51 ( V_70 | V_23 ) ;
if ( ! V_76 ) {
V_20 = - V_24 ;
goto V_79;
}
if ( F_53 ( V_76 , V_66 , V_72 ) ) {
V_20 = - V_73 ;
goto V_80;
}
V_20 = 0 ;
goto V_77;
V_80:
F_58 ( ( unsigned long ) V_76 ) ;
V_76 = NULL ;
V_79:
F_16 ( V_78 ) ;
V_78 = NULL ;
V_77:
F_61 ( & V_75 ) ;
snprintf ( V_44 , sizeof( V_44 ) , L_12 , V_20 ) ;
F_6 ( 0 , V_44 ) ;
return V_20 ;
}
static int F_62 ( void )
{
char V_44 [ 13 ] ;
int V_20 ;
F_60 ( & V_75 ) ;
if ( ! V_76 ) {
V_20 = - V_81 ;
goto V_77;
}
F_58 ( ( unsigned long ) V_76 ) ;
V_76 = NULL ;
F_16 ( V_78 ) ;
V_78 = NULL ;
V_20 = 0 ;
V_77:
F_61 ( & V_75 ) ;
snprintf ( V_44 , sizeof( V_44 ) , L_13 , V_20 ) ;
F_6 ( 0 , V_44 ) ;
return V_20 ;
}
static int F_63 ( void T_2 * V_66 )
{
struct V_82 * V_42 ;
int V_20 , V_83 ;
V_42 = ( void * ) F_51 ( V_23 | V_70 ) ;
if ( ! V_42 )
return - V_24 ;
if ( F_53 ( V_42 , V_66 , V_72 ) ) {
V_20 = - V_73 ;
goto V_71;
}
if ( V_42 -> V_45 . V_84 & 0x4000 ) {
V_20 = - V_85 ;
goto V_71;
}
F_47 ( V_42 ) ;
V_83 = F_46 ( V_42 ) ;
if ( V_83 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( F_57 ( V_66 , V_42 , V_72 ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_58 ( ( unsigned long ) V_42 ) ;
return V_20 ;
}
static int F_64 ( void T_2 * V_86 )
{
struct V_87 * V_88 ;
int V_20 , V_83 ;
struct {
struct V_89 V_12 ;
V_25 : 2 ;
V_25 V_90 : 1 ;
V_25 : 1 ;
V_25 V_91 : 4 ;
V_25 V_92 : 8 ;
V_25 : 8 ;
V_25 V_93 : 8 ;
V_25 : 24 ;
V_25 V_94 : 8 ;
V_25 : 32 ;
struct V_89 V_95 ;
T_3 V_2 [ V_72 - 20 ] ;
} V_96 ( ( V_97 ) ) * V_98 ;
V_98 = ( void * ) F_51 ( V_23 | V_70 ) ;
if ( ! V_98 )
return - V_24 ;
V_88 = F_13 ( sizeof( * V_88 ) , V_23 ) ;
if ( ! V_88 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_53 ( V_88 , V_86 , sizeof( * V_88 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_98 -> V_12 . V_3 = 0x0010 ;
V_98 -> V_12 . V_84 = 0x0028 ;
V_98 -> V_90 = V_88 -> V_90 ;
V_98 -> V_91 = V_88 -> V_99 ;
V_98 -> V_92 = V_88 -> V_100 . V_92 ;
V_98 -> V_93 = V_88 -> V_100 . V_101 ;
V_98 -> V_94 = V_88 -> V_100 . V_101 ;
V_83 = F_46 ( V_98 ) ;
if ( V_83 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( V_98 -> V_95 . V_84 != 0x0001 ) {
V_20 = - V_58 ;
F_8 ( 0 , L_14 ,
V_98 -> V_95 . V_84 ) ;
goto V_71;
}
memcpy ( & V_88 -> V_102 , & V_98 -> V_95 , V_98 -> V_95 . V_3 ) ;
if ( F_57 ( V_86 , V_88 , sizeof( * V_88 ) ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_16 ( V_88 ) ;
F_58 ( ( unsigned long ) V_98 ) ;
return V_20 ;
}
static int F_65 ( void T_2 * V_86 )
{
struct V_103 * V_88 ;
int V_20 , V_83 ;
struct {
struct V_89 V_12 ;
V_25 : 2 ;
V_25 V_90 : 1 ;
V_25 : 1 ;
V_25 V_91 : 4 ;
V_25 V_92 : 8 ;
V_25 : 8 ;
V_25 V_104 : 8 ;
V_25 : 24 ;
V_25 V_105 : 8 ;
V_25 : 32 ;
struct V_89 V_95 ;
T_3 V_2 [ V_72 - 20 ] ;
} V_96 ( ( V_97 ) ) * V_106 ;
V_106 = ( void * ) F_51 ( V_23 | V_70 ) ;
if ( ! V_106 )
return - V_24 ;
V_88 = F_13 ( sizeof( * V_88 ) , V_23 ) ;
if ( ! V_88 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_53 ( V_88 , V_86 , sizeof( * V_88 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_106 -> V_12 . V_3 = 0x0010 ;
V_106 -> V_12 . V_84 = 0x0026 ;
V_106 -> V_90 = V_88 -> V_90 ;
V_106 -> V_91 = V_88 -> V_99 ;
V_106 -> V_92 = V_88 -> V_92 ;
V_106 -> V_104 = V_88 -> V_107 ;
V_106 -> V_105 = V_88 -> V_107 ;
V_83 = F_46 ( V_106 ) ;
if ( V_83 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( V_106 -> V_95 . V_84 != 0x0001 ) {
V_20 = - V_58 ;
F_8 ( 0 , L_15 ,
V_106 -> V_95 . V_84 ) ;
goto V_71;
}
memcpy ( & V_88 -> V_108 , & V_106 -> V_95 , V_106 -> V_95 . V_3 ) ;
if ( F_57 ( V_86 , V_88 , sizeof( * V_88 ) ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_16 ( V_88 ) ;
F_58 ( ( unsigned long ) V_106 ) ;
return V_20 ;
}
static int F_66 ( void T_2 * V_109 )
{
struct V_110 * V_111 ;
int V_20 , V_83 ;
struct {
struct V_89 V_12 ;
V_25 : 2 ;
V_25 V_90 : 1 ;
V_25 : 5 ;
V_25 V_91 : 4 ;
V_25 : 2 ;
V_25 V_17 : 2 ;
V_25 V_112 : 16 ;
V_25 : 8 ;
V_25 V_92 : 8 ;
V_25 V_113 : 16 ;
V_25 : 32 ;
struct V_89 V_95 ;
T_3 V_2 [ V_72 - 20 ] ;
} V_96 ( ( V_97 ) ) * V_114 ;
V_114 = ( void * ) F_51 ( V_23 | V_70 ) ;
if ( ! V_114 )
return - V_24 ;
V_111 = F_13 ( sizeof( * V_111 ) , V_23 ) ;
if ( ! V_111 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_53 ( V_111 , V_109 , sizeof( * V_111 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_114 -> V_12 . V_3 = 0x0010 ;
V_114 -> V_12 . V_84 = 0x0006 ;
V_114 -> V_90 = V_111 -> V_16 . V_90 ;
V_114 -> V_91 = V_111 -> V_99 ;
V_114 -> V_17 = V_111 -> V_16 . V_17 ;
V_114 -> V_112 = V_111 -> V_16 . V_18 ;
V_114 -> V_92 = V_111 -> V_16 . V_92 ;
V_114 -> V_113 = V_111 -> V_16 . V_18 ;
V_83 = F_46 ( V_114 ) ;
if ( V_83 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( V_114 -> V_95 . V_84 != 0x0001 ) {
V_20 = - V_58 ;
F_8 ( 0 , L_16 ,
V_114 -> V_95 . V_84 ) ;
goto V_71;
}
memcpy ( & V_111 -> V_115 , & V_114 -> V_95 , V_114 -> V_95 . V_3 ) ;
if ( F_57 ( V_109 , V_111 , sizeof( * V_111 ) ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_16 ( V_111 ) ;
F_58 ( ( unsigned long ) V_114 ) ;
return V_20 ;
}
static int F_67 ( void T_2 * V_116 )
{
struct V_117 * V_118 ;
int V_20 , V_83 ;
struct {
struct V_89 V_12 ;
V_25 : 2 ;
V_25 V_90 : 1 ;
V_25 : 1 ;
V_25 V_91 : 4 ;
V_25 V_92 : 8 ;
V_25 : 6 ;
V_25 V_17 : 2 ;
V_25 : 8 ;
V_119 : 64 ;
struct V_89 V_95 ;
T_3 V_2 [ V_72 - 20 ] ;
} V_96 ( ( V_97 ) ) * V_120 ;
V_120 = ( void * ) F_51 ( V_23 | V_70 ) ;
if ( ! V_120 )
return - V_24 ;
V_118 = F_13 ( sizeof( * V_118 ) , V_23 ) ;
if ( ! V_118 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_53 ( V_118 , V_116 , sizeof( * V_118 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_120 -> V_12 . V_3 = 0x0010 ;
V_120 -> V_12 . V_84 = 0x0012 ;
V_120 -> V_90 = V_118 -> V_101 . V_90 ;
V_120 -> V_91 = V_118 -> V_99 ;
V_120 -> V_92 = V_118 -> V_101 . V_92 ;
V_120 -> V_17 = V_118 -> V_101 . V_17 ;
V_83 = F_46 ( V_120 ) ;
if ( V_83 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( V_120 -> V_95 . V_84 != 0x0001 ) {
V_20 = - V_58 ;
F_8 ( 0 , L_17 ,
V_120 -> V_95 . V_84 ) ;
goto V_71;
}
memcpy ( & V_118 -> V_121 , & V_120 -> V_95 , V_120 -> V_95 . V_3 ) ;
if ( F_57 ( V_116 , V_118 , sizeof( * V_118 ) ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_16 ( V_118 ) ;
F_58 ( ( unsigned long ) V_120 ) ;
return V_20 ;
}
static int F_68 ( void T_2 * V_122 )
{
struct V_123 * V_124 ;
int V_20 , V_83 ;
struct {
struct V_89 V_12 ;
V_25 V_125 : 8 ;
V_25 : 4 ;
V_25 V_99 : 4 ;
V_25 : 16 ;
V_119 : 64 ;
V_25 V_126 [ 2 ] ;
V_119 : 64 ;
struct V_89 V_95 ;
T_3 V_2 [ V_72 - 36 ] ;
} V_96 ( ( V_97 ) ) * V_127 ;
struct {
V_25 V_90 : 1 ;
V_25 : 31 ;
V_25 V_92 : 8 ;
V_25 : 16 ;
V_25 V_100 : 8 ;
} V_96 ( ( V_97 ) ) * V_128 ;
struct {
V_25 V_129 : 8 ;
V_25 V_130 : 8 ;
V_25 : 16 ;
V_25 V_131 ;
} V_96 ( ( V_97 ) ) * V_132 ;
V_127 = ( void * ) F_51 ( V_23 | V_70 ) ;
if ( ! V_127 )
return - V_24 ;
V_124 = F_13 ( sizeof( * V_124 ) , V_23 ) ;
if ( ! V_124 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_53 ( V_124 , V_122 , sizeof( * V_124 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_127 -> V_12 . V_3 = 0x0020 ;
V_127 -> V_12 . V_84 = 0x0030 ;
V_127 -> V_99 = V_124 -> V_133 . V_99 ;
V_127 -> V_125 = V_124 -> V_133 . V_125 ;
switch ( V_127 -> V_125 ) {
case V_134 :
case V_135 :
V_128 = ( void * ) & V_127 -> V_126 ;
V_128 -> V_90 = V_124 -> V_133 . V_100 . V_90 ;
V_128 -> V_92 = V_124 -> V_133 . V_100 . V_136 . V_92 ;
V_128 -> V_100 = V_124 -> V_133 . V_100 . V_136 . V_101 ;
break;
case V_137 :
case V_138 :
V_132 = ( void * ) & V_127 -> V_126 ;
V_132 -> V_129 = V_124 -> V_133 . V_139 . V_129 ;
V_132 -> V_130 = V_124 -> V_133 . V_139 . V_130 ;
break;
}
V_83 = F_46 ( V_127 ) ;
if ( V_83 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( V_127 -> V_95 . V_84 != 0x0001 ) {
V_20 = - V_58 ;
F_8 ( 0 , L_18 ,
V_127 -> V_95 . V_84 ) ;
goto V_71;
}
memcpy ( & V_124 -> V_140 , & V_127 -> V_95 , V_127 -> V_95 . V_3 ) ;
if ( F_57 ( V_122 , V_124 , sizeof( * V_124 ) ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_16 ( V_124 ) ;
F_58 ( ( unsigned long ) V_127 ) ;
return V_20 ;
}
static int F_69 ( void T_2 * V_141 )
{
struct V_142 * V_143 ;
struct V_144 * V_145 ;
int V_20 ;
V_145 = F_13 ( sizeof( * V_145 ) , V_23 ) ;
V_143 = ( void * ) F_51 ( V_23 | V_70 ) ;
if ( ! V_143 || ! V_145 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_53 ( V_145 , V_141 , sizeof( * V_145 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_20 = F_70 ( V_145 -> V_100 , V_145 -> V_99 ,
V_145 -> V_146 , V_145 -> V_147 , V_145 -> V_90 ,
V_143 ) ;
if ( V_20 )
goto V_71;
memcpy ( & V_145 -> V_148 , & V_143 -> V_95 , V_143 -> V_95 . V_3 ) ;
if ( F_57 ( V_141 , V_145 , sizeof( * V_145 ) ) )
V_20 = - V_73 ;
V_71:
F_16 ( V_145 ) ;
F_58 ( ( unsigned long ) V_143 ) ;
return V_20 ;
}
static int F_71 ( void T_2 * V_149 )
{
struct V_150 * V_151 ;
int V_20 , V_83 ;
struct {
struct V_89 V_12 ;
V_25 V_152 : 8 ;
V_25 : 4 ;
V_25 V_99 : 4 ;
V_25 : 16 ;
V_25 V_153 [ 2 ] ;
V_25 V_126 [ 2 ] ;
V_25 V_154 [ 2 ] ;
struct V_89 V_95 ;
T_3 V_2 [ V_72 - 36 ] ;
} V_96 ( ( V_97 ) ) * V_155 ;
V_155 = ( void * ) F_51 ( V_23 | V_70 ) ;
if ( ! V_155 )
return - V_24 ;
V_151 = F_13 ( sizeof( * V_151 ) , V_23 ) ;
if ( ! V_151 ) {
V_20 = - V_24 ;
goto V_71;
}
if ( F_53 ( V_151 , V_149 , sizeof( * V_151 ) ) ) {
V_20 = - V_73 ;
goto V_71;
}
V_155 -> V_12 . V_3 = 0x0020 ;
V_155 -> V_12 . V_84 = 0x0034 ;
V_155 -> V_152 = V_151 -> V_133 . V_152 ;
V_155 -> V_99 = V_151 -> V_133 . V_99 ;
memcpy ( & V_155 -> V_126 , & V_151 -> V_133 . V_126 ,
sizeof( V_155 -> V_126 ) ) ;
V_83 = F_46 ( V_155 ) ;
if ( V_83 != 0 ) {
V_20 = - V_58 ;
goto V_71;
}
if ( V_155 -> V_95 . V_84 != 0x0001 ) {
V_20 = - V_58 ;
F_8 ( 0 , L_19 ,
V_155 -> V_95 . V_84 ) ;
goto V_71;
}
memcpy ( & V_151 -> V_156 , & V_155 -> V_95 ,
V_155 -> V_95 . V_3 ) ;
if ( F_57 ( V_149 , V_151 , sizeof( * V_151 ) ) )
V_20 = - V_73 ;
else
V_20 = 0 ;
V_71:
F_16 ( V_151 ) ;
F_58 ( ( unsigned long ) V_155 ) ;
return V_20 ;
}
static long F_72 ( struct V_157 * V_158 , unsigned int V_51 ,
unsigned long V_159 )
{
void T_2 * V_160 ;
F_8 ( 2 , L_20 , V_51 ) ;
if ( F_73 () )
V_160 = F_74 ( V_159 ) ;
else
V_160 = ( void T_2 * ) V_159 ;
switch ( V_51 ) {
case V_161 :
return F_50 ( V_160 ) ;
case V_162 :
return F_63 ( V_160 ) ;
case V_163 :
return F_64 ( V_160 ) ;
case V_164 :
return F_65 ( V_160 ) ;
case V_165 :
return F_66 ( V_160 ) ;
case V_166 :
return F_67 ( V_160 ) ;
case V_167 :
return F_68 ( V_160 ) ;
case V_168 :
return F_69 ( V_160 ) ;
case V_169 :
return F_71 ( V_160 ) ;
case V_170 :
return F_59 ( V_160 ) ;
case V_171 :
return F_62 () ;
default:
return - V_172 ;
}
}
static int F_75 ( struct V_173 * V_173 , struct V_157 * V_157 )
{
if ( ! F_76 ( & V_174 ) ) {
F_77 ( & V_174 ) ;
return - V_49 ;
}
return F_78 ( V_173 , V_157 ) ;
}
static int F_79 ( struct V_173 * V_173 , struct V_157 * V_158 )
{
char V_44 [ 13 ] ;
int V_20 ;
F_60 ( & V_75 ) ;
if ( ! V_76 )
goto V_77;
F_52 ( & V_78 -> V_19 ) ;
F_6 ( 0 , L_21 ) ;
F_47 ( V_76 ) ;
F_54 ( & V_74 ) ;
V_20 = F_43 ( V_76 , V_78 ) ;
F_55 ( & V_74 ) ;
if ( V_20 == - V_54 ) {
F_56 ( & V_78 -> V_19 ) ;
V_20 = F_48 ( V_78 ) ;
}
snprintf ( V_44 , sizeof( V_44 ) , L_22 , V_20 ) ;
F_6 ( 0 , V_44 ) ;
F_58 ( ( unsigned long ) V_76 ) ;
V_76 = NULL ;
F_16 ( V_78 ) ;
V_78 = NULL ;
V_77:
F_61 ( & V_75 ) ;
F_77 ( & V_174 ) ;
return 0 ;
}
static int T_1 F_80 ( void )
{
return F_81 ( & V_175 ) ;
}
static void F_82 ( void )
{
F_83 ( & V_175 ) ;
}
static int T_1 F_84 ( void )
{
int V_20 ;
V_20 = F_28 () ;
if ( V_20 )
return V_20 ;
F_85 ( V_22 ) ;
V_20 = F_34 () ;
if ( V_20 )
goto V_176;
V_20 = F_80 () ;
if ( V_20 )
goto V_177;
return V_20 ;
V_177:
F_36 () ;
V_176:
F_86 ( V_22 ) ;
F_33 () ;
return V_20 ;
}
static void T_4 F_87 ( void )
{
F_82 () ;
F_36 () ;
F_86 ( V_22 ) ;
F_33 () ;
}
