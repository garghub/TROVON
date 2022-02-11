static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 == V_4 ) {
V_2 -> V_5 = F_2 ( sizeof( struct V_6 ) ) ;
if ( V_2 -> V_5 == NULL )
goto error;
V_2 -> V_7 = F_2 ( sizeof( struct V_6 ) ) ;
if ( V_2 -> V_7 == NULL )
goto error;
V_2 -> V_8 = F_2 ( sizeof( struct V_6 ) ) ;
if ( V_2 -> V_8 == NULL )
goto error;
V_2 -> V_9 = F_2 ( sizeof( struct V_6 ) ) ;
if ( V_2 -> V_9 == NULL )
goto error;
V_2 -> V_5 -> V_10 = V_2 -> V_7 ;
V_2 -> V_7 -> V_10 = V_2 -> V_8 ;
V_2 -> V_8 -> V_10 = V_2 -> V_9 ;
V_2 -> V_9 -> V_10 = V_2 -> V_5 ;
V_2 -> V_11 = V_2 -> V_9 ;
V_2 -> V_5 -> V_12 = V_13 ;
V_2 -> V_5 -> V_14 = V_15 ;
V_2 -> V_5 -> V_16 =
V_2 -> V_17 [ V_18 ] . V_19 + V_2 -> V_17 [ V_18 ] . V_20 ;
V_2 -> V_5 -> V_21 = 0 ;
V_2 -> V_5 -> V_22 = V_2 -> V_17 [ V_18 ] . V_23 ;
V_2 -> V_5 -> V_24 = 0 ;
V_2 -> V_7 -> V_12 = ( unsigned long ) V_2 -> V_25 ;
V_2 -> V_7 -> V_14 = V_15 ;
V_2 -> V_7 -> V_16 =
V_2 -> V_17 [ V_18 ] . V_19 + V_2 -> V_17 [ V_18 ] . V_20 ;
V_2 -> V_7 -> V_21 = V_2 -> V_17 [ V_18 ] . V_26 / 8 ;
V_2 -> V_7 -> V_22 = V_2 -> V_17 [ V_18 ] . V_27 ;
V_2 -> V_7 -> V_24 =
( V_2 -> V_17 [ V_18 ] . V_19 - V_2 -> V_17 [ V_18 ] . V_20 +
1 ) * ( V_2 -> V_17 [ V_18 ] . V_26 / 8 ) ;
V_2 -> V_8 -> V_12 = V_13 ;
V_2 -> V_8 -> V_14 = V_15 ;
V_2 -> V_8 -> V_16 =
V_2 -> V_17 [ V_18 ] . V_19 + V_2 -> V_17 [ V_18 ] . V_20 ;
V_2 -> V_8 -> V_21 = 0 ;
V_2 -> V_8 -> V_22 = V_2 -> V_17 [ V_18 ] . V_28 ;
V_2 -> V_8 -> V_24 = 0 ;
V_2 -> V_9 -> V_12 =
( unsigned long ) V_2 -> V_25 + V_2 -> V_29 ;
V_2 -> V_9 -> V_14 = V_15 ;
V_2 -> V_9 -> V_16 =
V_2 -> V_17 [ V_18 ] . V_19 + V_2 -> V_17 [ V_18 ] . V_20 ;
V_2 -> V_9 -> V_21 = ( V_2 -> V_17 [ V_18 ] . V_26 / 8 ) ;
V_2 -> V_9 -> V_22 = V_2 -> V_17 [ V_18 ] . V_27 ;
V_2 -> V_9 -> V_24 =
( V_2 -> V_17 [ V_18 ] . V_19 - V_2 -> V_17 [ V_18 ] . V_20 +
1 ) * ( V_2 -> V_17 [ V_18 ] . V_26 / 8 ) ;
return 1 ;
}
error:
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_7 ) ;
F_3 ( V_2 -> V_8 ) ;
F_3 ( V_2 -> V_9 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
F_5 ( ! ( V_2 -> V_25 ) ) ;
F_6 ( V_30 , V_2 -> V_11 -> V_16 ) ;
F_7 ( V_30 , V_2 -> V_11 -> V_21 ) ;
F_8 ( V_30 , V_2 -> V_11 -> V_22 ) ;
F_9 ( V_30 , V_2 -> V_11 -> V_24 ) ;
F_10 ( V_30 , V_2 -> V_11 -> V_12 ) ;
F_11 ( V_30 ,
V_2 -> V_11 -> V_10 ) ;
F_12 ( V_30 , V_2 -> V_11 -> V_14 ) ;
return 1 ;
}
static void F_13 ( void )
{
F_14 ( F_15 () & ~ V_31 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( V_32 ) {
F_17 ( V_33 ) ;
F_18 ( V_34 ) ;
}
F_19 ( 0x381E ) ;
F_20 ( V_2 -> V_17 [ V_18 ] . V_35 ) ;
F_21 ( V_2 -> V_17 [ V_18 ] . V_19 +
V_2 -> V_17 [ V_18 ] . V_20 - 1 ) ;
F_22 ( V_2 -> V_17 [ V_18 ] . V_36 - 1 ) ;
}
static void F_23 ( void )
{
F_19 ( F_24 () | V_37 ) ;
}
static void F_25 ( void )
{
F_19 ( F_24 () & ~ V_37 ) ;
}
static inline int F_26 ( struct V_38 * V_39 , T_2 V_40 , T_2 V_41 )
{
return F_27 ( V_39 , V_40 , V_41 ) ;
}
static inline int F_28 ( struct V_38 * V_39 , T_2 V_40 )
{
return F_29 ( V_39 , V_40 ) ;
}
static int
F_30 ( struct V_38 * V_39 ,
const T_2 * V_42 , unsigned int V_43 )
{
int V_44 = - 1 ;
T_2 V_40 ;
while ( V_43 >= 2 ) {
V_40 = * V_42 ++ ;
V_44 = F_26 ( V_39 , V_40 , * V_42 ++ ) ;
if ( V_44 < 0 )
break;
V_43 -= 2 ;
}
return V_44 ;
}
static int F_31 ( struct V_38 * V_39 , T_1 V_18 )
{
switch ( V_18 ) {
case V_45 :
F_26 ( V_39 , 0x00 , 0x1E ) ;
break;
case V_46 :
F_26 ( V_39 , 0x00 , 0x1F ) ;
break;
case V_47 :
F_26 ( V_39 , 0x82 , 0xCB ) ;
break;
case V_48 :
F_26 ( V_39 , 0x82 , 0x8B ) ;
break;
default:
return - V_49 ;
break;
}
return 0 ;
}
static T_3 F_32 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = (struct V_1 * ) V_51 ;
T_1 V_52 = F_33 () ;
F_34 ( L_1 , V_53 , V_52 ) ;
if ( V_52 ) {
F_13 () ;
F_25 () ;
F_35 () ;
F_4 ( V_2 ) ;
F_23 () ;
}
return V_54 ;
}
static int F_36 ( char * V_55 )
{
char * V_56 = V_55 ;
V_56 += sprintf ( V_56 ,
L_2
L_3
L_4
L_5 ) ;
return V_56 - V_55 ;
}
static int
F_37 ( char * V_57 , char * * V_58 , T_4 V_59 ,
int V_60 , int * V_61 , void * V_42 )
{
int V_43 ;
V_43 = F_36 ( V_57 ) ;
if ( V_43 <= V_59 + V_60 )
* V_61 = 1 ;
* V_58 = V_57 + V_59 ;
V_43 -= V_59 ;
if ( V_43 > V_60 )
V_43 = V_60 ;
if ( V_43 < 0 )
V_43 = 0 ;
return V_43 ;
}
static int
F_38 ( struct V_62 * V_62 , const char T_5 * V_63 ,
unsigned long V_60 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
char line [ 8 ] ;
unsigned int V_64 ;
int V_44 ;
V_44 = F_39 ( line , V_63 , V_60 ) ;
if ( V_44 )
return - V_65 ;
V_64 = F_40 ( line , NULL , 0 ) ;
F_26 ( V_2 -> V_39 , V_64 >> 8 , V_64 & 0xff ) ;
return V_60 ;
}
static int T_6 F_41 ( struct V_38 * V_39 ,
const struct V_66 * V_67 )
{
int V_44 = 0 ;
struct V_68 * V_69 ;
int V_70 = F_42 ( V_71 ) ;
struct V_1 * V_2 = NULL ;
if ( V_72 > 2 ) {
F_43 ( & V_39 -> V_73 , L_6 ) ;
return - V_49 ;
}
if ( V_18 > V_70 ) {
F_43 ( & V_39 -> V_73 , L_7 , V_18 ) ;
return - V_65 ;
}
V_2 = F_44 ( sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 ) {
F_43 ( & V_39 -> V_73 , L_8 ) ;
return - V_75 ;
}
F_45 ( V_39 , V_2 ) ;
V_2 -> V_17 = V_71 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_76 =
V_72 * V_2 -> V_17 [ V_18 ] . V_19 * V_2 -> V_17 [ V_18 ] . V_19 *
( V_2 -> V_17 [ V_18 ] . V_26 / 8 ) ;
V_2 -> V_29 =
V_2 -> V_17 [ V_18 ] . V_19 * ( V_2 -> V_17 [ V_18 ] . V_26 / 8 ) ;
if ( V_77 ) {
if ( F_46 ( F_47 ( V_78 ) , L_9 ) ) {
F_43 ( & V_39 -> V_73 , L_10 ) ;
V_44 = - V_79 ;
goto V_80;
}
F_48 ( F_47 ( V_78 ) , 0 ) ;
}
if ( F_49 ( V_81 , V_82 ) ) {
F_43 ( & V_39 -> V_73 , L_11 ) ;
V_44 = - V_65 ;
goto V_80;
}
V_2 -> V_25 =
F_50 ( NULL , V_2 -> V_76 , & V_2 -> V_83 ,
V_74 ) ;
if ( NULL == V_2 -> V_25 ) {
F_43 ( & V_39 -> V_73 , L_12 ,
( V_84 ) V_2 -> V_76 ) ;
V_44 = - V_75 ;
goto V_85;
}
V_2 -> V_86 . V_87 = ( void * ) V_2 -> V_25 ;
V_88 . V_89 = ( int ) V_2 -> V_25 ;
V_88 . V_90 = V_2 -> V_76 ;
V_88 . V_91 = V_2 -> V_29 ;
if ( V_72 > 1 )
V_88 . V_92 = 1 ;
V_93 . V_94 . V_95 = 5 ;
V_93 . V_96 . V_95 = 6 ;
V_93 . V_97 . V_95 = 5 ;
V_93 . V_19 = V_2 -> V_17 [ V_18 ] . V_19 ;
V_93 . V_98 = V_2 -> V_17 [ V_18 ] . V_98 ;
V_93 . V_99 = V_2 -> V_17 [ V_18 ] . V_19 ;
V_93 . V_100 = V_72 * V_2 -> V_17 [ V_18 ] . V_98 ;
V_93 . V_101 = V_2 -> V_17 [ V_18 ] . V_26 ;
V_2 -> V_86 . V_102 = & V_103 ;
V_2 -> V_86 . V_104 = V_93 ;
V_2 -> V_86 . V_105 = V_88 ;
V_2 -> V_86 . V_106 = & V_107 ;
V_2 -> V_86 . V_108 = V_109 ;
V_2 -> V_86 . V_110 = F_44 ( sizeof( V_84 ) * 16 , V_74 ) ;
if ( ! V_2 -> V_86 . V_110 ) {
F_43 ( & V_39 -> V_73 , L_13 ) ;
V_44 = - V_75 ;
goto V_111;
}
if ( F_51 ( & V_2 -> V_86 . V_112 , V_113 , 0 ) < 0 ) {
F_43 ( & V_39 -> V_73 , L_14 ,
V_113 ) ;
V_44 = - V_65 ;
goto V_114;
}
if ( F_52 ( V_30 , L_15 ) < 0 ) {
F_43 ( & V_39 -> V_73 , L_16 ) ;
V_44 = - V_65 ;
goto V_115;
}
if ( F_53 ( V_116 , F_32 , V_117 ,
L_17 , V_2 ) < 0 ) {
F_43 ( & V_39 -> V_73 , L_18 ) ;
V_44 = - V_65 ;
goto V_118;
}
V_2 -> V_119 = 0 ;
V_44 = F_30 ( V_39 , V_2 -> V_17 [ V_18 ] . V_120 ,
V_2 -> V_17 [ V_18 ] . V_121 ) ;
if ( V_44 ) {
F_43 ( & V_39 -> V_73 , L_19 ) ;
goto V_122;
}
if ( F_54 ( & V_2 -> V_86 ) < 0 ) {
F_43 ( & V_39 -> V_73 , L_20 ) ;
V_44 = - V_65 ;
goto V_122;
}
F_55 ( & V_39 -> V_73 , L_21 ,
V_2 -> V_86 . V_123 , V_2 -> V_86 . V_105 . V_67 ) ;
F_55 ( & V_39 -> V_73 , L_22 , V_2 -> V_25 ) ;
V_69 = F_56 ( L_23 , 0 , NULL ) ;
if ( ! V_69 ) {
F_43 ( & V_39 -> V_73 , L_24 ) ;
V_44 = - V_65 ;
goto V_124;
}
V_69 -> V_125 = F_37 ;
V_69 -> V_126 = F_38 ;
V_69 -> V_42 = V_2 ;
return 0 ;
V_124:
F_57 ( & V_2 -> V_86 ) ;
V_122:
F_58 ( V_116 , V_2 ) ;
V_118:
F_59 ( V_30 ) ;
V_115:
F_60 ( NULL , V_2 -> V_76 , V_2 -> V_25 ,
V_2 -> V_83 ) ;
V_114:
F_61 ( & V_2 -> V_86 . V_112 ) ;
V_111:
F_62 ( V_2 -> V_86 . V_110 ) ;
V_85:
F_63 ( V_81 ) ;
V_80:
F_62 ( V_2 ) ;
return V_44 ;
}
static int F_64 ( struct V_127 * V_86 , int V_128 )
{
struct V_1 * V_2 = F_65 ( V_86 ) ;
V_2 -> V_86 . V_87 = ( void * ) V_2 -> V_25 ;
if ( ! V_2 -> V_86 . V_87 ) {
F_43 ( & V_2 -> V_39 -> V_73 , L_25 ) ;
return - V_75 ;
}
V_2 -> V_119 = 1 ;
F_1 ( V_2 , V_4 ) ;
F_31 ( V_2 -> V_39 , V_47 ) ;
F_16 ( V_2 ) ;
F_4 ( V_2 ) ;
F_23 () ;
return 0 ;
}
static int F_66 ( struct V_127 * V_86 , int V_128 )
{
struct V_1 * V_2 = F_65 ( V_86 ) ;
F_31 ( V_2 -> V_39 , V_48 ) ;
F_13 () ;
F_25 () ;
F_1 ( V_2 , V_129 ) ;
V_2 -> V_119 = 0 ;
return 0 ;
}
static int
F_67 ( struct V_130 * V_104 , struct V_127 * V_86 )
{
switch ( V_104 -> V_101 ) {
case 16 :
V_104 -> V_94 . V_131 = V_86 -> V_104 . V_94 . V_131 ;
V_104 -> V_96 . V_131 = V_86 -> V_104 . V_96 . V_131 ;
V_104 -> V_97 . V_131 = V_86 -> V_104 . V_97 . V_131 ;
V_104 -> V_94 . V_95 = V_86 -> V_104 . V_94 . V_95 ;
V_104 -> V_96 . V_95 = V_86 -> V_104 . V_96 . V_95 ;
V_104 -> V_97 . V_95 = V_86 -> V_104 . V_97 . V_95 ;
V_104 -> V_132 . V_131 = 0 ;
V_104 -> V_132 . V_95 = 0 ;
V_104 -> V_132 . V_133 = 0 ;
V_104 -> V_94 . V_133 = 0 ;
V_104 -> V_96 . V_133 = 0 ;
V_104 -> V_97 . V_133 = 0 ;
break;
default:
F_34 ( L_26 , V_53 ,
V_104 -> V_101 ) ;
return - V_49 ;
}
if ( V_86 -> V_104 . V_19 != V_104 -> V_19 ||
V_86 -> V_104 . V_98 != V_104 -> V_98 ||
V_86 -> V_104 . V_99 != V_104 -> V_99 ||
V_86 -> V_104 . V_100 != V_104 -> V_100 ) {
F_34 ( L_27 ,
V_53 , V_104 -> V_19 , V_104 -> V_98 ) ;
return - V_49 ;
}
if ( ( V_86 -> V_105 . V_91 * V_104 -> V_100 ) > V_86 -> V_105 . V_90 ) {
F_34 ( L_28 ,
V_53 , V_104 -> V_100 ) ;
return - V_75 ;
}
return 0 ;
}
static int
F_68 ( struct V_130 * V_104 , struct V_127 * V_86 )
{
int V_134 ;
V_84 V_135 ;
struct V_1 * V_2 = F_65 ( V_86 ) ;
if ( ! V_104 || ! V_86 )
return - V_49 ;
if ( V_104 -> V_136 - V_86 -> V_104 . V_136 ) {
return - V_49 ;
}
V_134 = V_104 -> V_137 - V_86 -> V_104 . V_137 ;
if ( V_134 ) {
F_34 ( L_29 , V_53 , V_134 ) ;
V_135 = V_2 -> V_7 -> V_12 ;
V_135 += ( V_86 -> V_105 . V_91 * V_134 ) ;
V_2 -> V_7 -> V_12 = ( unsigned long ) V_135 ;
V_2 -> V_9 -> V_12 = ( unsigned long ) V_135 + V_2 -> V_29 ;
}
return 0 ;
}
static int F_69 ( int V_138 , struct V_127 * V_86 )
{
struct V_1 * V_2 = F_65 ( V_86 ) ;
switch ( V_138 ) {
case V_139 :
F_31 ( V_2 -> V_39 , V_47 ) ;
break;
case V_140 :
case V_141 :
case V_142 :
F_31 ( V_2 -> V_39 , V_48 ) ;
break;
default:
return - V_49 ;
break;
}
return 0 ;
}
int F_70 ( struct V_127 * V_86 , struct V_143 * V_144 )
{
if ( V_145 )
return 0 ;
else
return - V_49 ;
}
static int F_71 ( T_7 V_146 , T_7 V_94 , T_7 V_96 ,
T_7 V_97 , T_7 V_132 ,
struct V_127 * V_86 )
{
if ( V_146 >= V_113 )
return - V_49 ;
if ( V_86 -> V_104 . V_147 )
V_94 = V_96 = V_97 = ( V_94 * 77 + V_96 * 151 + V_97 * 28 ) >> 8 ;
if ( V_86 -> V_105 . V_148 == V_149 ) {
V_84 V_41 ;
if ( V_146 > 16 )
return - V_49 ;
V_94 >>= ( 16 - V_86 -> V_104 . V_94 . V_95 ) ;
V_96 >>= ( 16 - V_86 -> V_104 . V_96 . V_95 ) ;
V_97 >>= ( 16 - V_86 -> V_104 . V_97 . V_95 ) ;
V_41 = ( V_94 << V_86 -> V_104 . V_94 . V_131 ) |
( V_96 << V_86 -> V_104 . V_96 . V_131 ) |
( V_97 << V_86 -> V_104 . V_97 . V_131 ) ;
V_41 &= 0xFFFF ;
( ( V_84 * ) ( V_86 -> V_110 ) ) [ V_146 ] = V_41 ;
}
return 0 ;
}
static int T_8 F_72 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_73 ( V_39 ) ;
F_31 ( V_39 , V_46 ) ;
if ( V_2 -> V_25 )
F_60 ( NULL , V_2 -> V_76 , V_2 -> V_25 , V_2 -> V_83 ) ;
F_59 ( V_30 ) ;
F_58 ( V_116 , V_2 ) ;
F_57 ( & V_2 -> V_86 ) ;
F_74 ( L_23 , NULL ) ;
F_61 ( & V_2 -> V_86 . V_112 ) ;
F_62 ( V_2 -> V_86 . V_110 ) ;
if ( V_77 )
F_75 ( F_47 ( V_78 ) ) ;
F_63 ( V_81 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
static int F_76 ( struct V_150 * V_73 )
{
struct V_1 * V_2 = F_77 ( V_73 ) ;
if ( V_2 -> V_119 ) {
F_13 () ;
F_25 () ;
F_1 ( V_2 , V_129 ) ;
}
F_31 ( V_2 -> V_39 , V_46 ) ;
return 0 ;
}
static int F_78 ( struct V_150 * V_73 )
{
struct V_1 * V_2 = F_77 ( V_73 ) ;
F_31 ( V_2 -> V_39 , V_45 ) ;
if ( V_2 -> V_119 ) {
F_1 ( V_2 , V_4 ) ;
F_16 ( V_2 ) ;
F_4 ( V_2 ) ;
F_23 () ;
}
return 0 ;
}
static int T_9 F_79 ( void )
{
#if F_80 ( V_151 ) || F_80 ( V_152 )
F_81 ( L_30 ) ;
#else
F_81 ( L_31 ) ;
#endif
return F_82 ( & V_153 ) ;
}
static void T_10 F_83 ( void )
{
F_84 ( & V_153 ) ;
}
