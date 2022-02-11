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
static T_4
F_37 ( struct V_57 * V_57 , char T_5 * V_55 ,
T_6 V_58 , T_7 * V_59 )
{
static const char V_60 [] = L_2
L_3
L_4
L_5 ;
return F_38 ( V_55 , V_58 , V_59 , V_60 ,
sizeof( V_60 ) ) ;
}
static T_4
F_39 ( struct V_57 * V_57 , const char T_5 * V_61 ,
T_6 V_62 , T_7 * V_59 )
{
struct V_1 * V_2 = F_40 ( F_41 ( V_57 ) ) ;
unsigned int V_63 ;
int V_44 ;
V_44 = F_42 ( V_61 , V_62 , 0 , & V_63 ) ;
if ( V_44 )
return - V_64 ;
F_26 ( V_2 -> V_39 , V_63 >> 8 , V_63 & 0xff ) ;
return V_62 ;
}
static int F_43 ( struct V_38 * V_39 ,
const struct V_65 * V_66 )
{
int V_44 = 0 ;
struct V_67 * V_68 ;
int V_69 = F_44 ( V_70 ) ;
struct V_1 * V_2 = NULL ;
if ( V_71 > 2 ) {
F_45 ( & V_39 -> V_72 , L_6 ) ;
return - V_49 ;
}
if ( V_18 > V_69 ) {
F_45 ( & V_39 -> V_72 , L_7 , V_18 ) ;
return - V_64 ;
}
V_2 = F_46 ( sizeof( * V_2 ) , V_73 ) ;
if ( ! V_2 ) {
F_45 ( & V_39 -> V_72 , L_8 ) ;
return - V_74 ;
}
F_47 ( V_39 , V_2 ) ;
V_2 -> V_17 = V_70 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_75 =
V_71 * V_2 -> V_17 [ V_18 ] . V_19 * V_2 -> V_17 [ V_18 ] . V_19 *
( V_2 -> V_17 [ V_18 ] . V_26 / 8 ) ;
V_2 -> V_29 =
V_2 -> V_17 [ V_18 ] . V_19 * ( V_2 -> V_17 [ V_18 ] . V_26 / 8 ) ;
if ( V_76 ) {
V_44 = F_48 ( F_49 ( V_77 ) , V_78 ,
L_9 ) ;
if ( V_44 ) {
F_45 ( & V_39 -> V_72 , L_10 ) ;
V_44 = - V_79 ;
goto V_80;
}
}
if ( F_50 ( V_81 , V_82 ) ) {
F_45 ( & V_39 -> V_72 , L_11 ) ;
V_44 = - V_64 ;
goto V_83;
}
V_2 -> V_25 =
F_51 ( NULL , V_2 -> V_75 , & V_2 -> V_84 ,
V_73 ) ;
if ( NULL == V_2 -> V_25 ) {
F_45 ( & V_39 -> V_72 , L_12 ,
( V_85 ) V_2 -> V_75 ) ;
V_44 = - V_74 ;
goto V_86;
}
V_2 -> V_87 . V_88 = ( void * ) V_2 -> V_25 ;
V_89 . V_90 = ( int ) V_2 -> V_25 ;
V_89 . V_91 = V_2 -> V_75 ;
V_89 . V_92 = V_2 -> V_29 ;
if ( V_71 > 1 )
V_89 . V_93 = 1 ;
V_94 . V_95 . V_96 = 5 ;
V_94 . V_97 . V_96 = 6 ;
V_94 . V_98 . V_96 = 5 ;
V_94 . V_19 = V_2 -> V_17 [ V_18 ] . V_19 ;
V_94 . V_99 = V_2 -> V_17 [ V_18 ] . V_99 ;
V_94 . V_100 = V_2 -> V_17 [ V_18 ] . V_19 ;
V_94 . V_101 = V_71 * V_2 -> V_17 [ V_18 ] . V_99 ;
V_94 . V_102 = V_2 -> V_17 [ V_18 ] . V_26 ;
V_2 -> V_87 . V_103 = & V_104 ;
V_2 -> V_87 . V_105 = V_94 ;
V_2 -> V_87 . V_106 = V_89 ;
V_2 -> V_87 . V_107 = & V_108 ;
V_2 -> V_87 . V_109 = V_110 ;
V_2 -> V_87 . V_111 = F_46 ( sizeof( V_85 ) * 16 , V_73 ) ;
if ( ! V_2 -> V_87 . V_111 ) {
F_45 ( & V_39 -> V_72 , L_13 ) ;
V_44 = - V_74 ;
goto V_112;
}
if ( F_52 ( & V_2 -> V_87 . V_113 , V_114 , 0 ) < 0 ) {
F_45 ( & V_39 -> V_72 , L_14 ,
V_114 ) ;
V_44 = - V_64 ;
goto V_115;
}
if ( F_53 ( V_30 , L_15 ) < 0 ) {
F_45 ( & V_39 -> V_72 , L_16 ) ;
V_44 = - V_64 ;
goto V_116;
}
if ( F_54 ( V_117 , F_32 , 0 ,
L_17 , V_2 ) < 0 ) {
F_45 ( & V_39 -> V_72 , L_18 ) ;
V_44 = - V_64 ;
goto V_118;
}
V_2 -> V_119 = 0 ;
V_44 = F_30 ( V_39 , V_2 -> V_17 [ V_18 ] . V_120 ,
V_2 -> V_17 [ V_18 ] . V_121 ) ;
if ( V_44 ) {
F_45 ( & V_39 -> V_72 , L_19 ) ;
goto V_122;
}
if ( F_55 ( & V_2 -> V_87 ) < 0 ) {
F_45 ( & V_39 -> V_72 , L_20 ) ;
V_44 = - V_64 ;
goto V_122;
}
F_56 ( & V_39 -> V_72 , L_21 ,
V_2 -> V_87 . V_123 , V_2 -> V_87 . V_106 . V_66 ) ;
F_56 ( & V_39 -> V_72 , L_22 , V_2 -> V_25 ) ;
V_68 = F_57 ( L_23 , 0 , NULL , & V_124 , V_2 ) ;
if ( ! V_68 ) {
F_45 ( & V_39 -> V_72 , L_24 ) ;
V_44 = - V_64 ;
goto V_125;
}
return 0 ;
V_125:
F_58 ( & V_2 -> V_87 ) ;
V_122:
F_59 ( V_117 , V_2 ) ;
V_118:
F_60 ( V_30 ) ;
V_116:
F_61 ( & V_2 -> V_87 . V_113 ) ;
V_115:
F_62 ( V_2 -> V_87 . V_111 ) ;
V_112:
F_63 ( NULL , V_2 -> V_75 , V_2 -> V_25 ,
V_2 -> V_84 ) ;
V_86:
F_64 ( V_81 ) ;
V_83:
if ( V_76 )
F_65 ( F_49 ( V_77 ) ) ;
V_80:
F_62 ( V_2 ) ;
return V_44 ;
}
static int F_66 ( struct V_126 * V_87 , int V_127 )
{
struct V_1 * V_2 = F_67 ( V_87 ) ;
V_2 -> V_87 . V_88 = ( void * ) V_2 -> V_25 ;
if ( ! V_2 -> V_87 . V_88 ) {
F_45 ( & V_2 -> V_39 -> V_72 , L_25 ) ;
return - V_74 ;
}
V_2 -> V_119 = 1 ;
F_1 ( V_2 , V_4 ) ;
F_31 ( V_2 -> V_39 , V_47 ) ;
F_16 ( V_2 ) ;
F_4 ( V_2 ) ;
F_23 () ;
return 0 ;
}
static int F_68 ( struct V_126 * V_87 , int V_127 )
{
struct V_1 * V_2 = F_67 ( V_87 ) ;
F_31 ( V_2 -> V_39 , V_48 ) ;
F_13 () ;
F_25 () ;
F_1 ( V_2 , V_128 ) ;
V_2 -> V_119 = 0 ;
return 0 ;
}
static int
F_69 ( struct V_129 * V_105 , struct V_126 * V_87 )
{
switch ( V_105 -> V_102 ) {
case 16 :
V_105 -> V_95 . V_130 = V_87 -> V_105 . V_95 . V_130 ;
V_105 -> V_97 . V_130 = V_87 -> V_105 . V_97 . V_130 ;
V_105 -> V_98 . V_130 = V_87 -> V_105 . V_98 . V_130 ;
V_105 -> V_95 . V_96 = V_87 -> V_105 . V_95 . V_96 ;
V_105 -> V_97 . V_96 = V_87 -> V_105 . V_97 . V_96 ;
V_105 -> V_98 . V_96 = V_87 -> V_105 . V_98 . V_96 ;
V_105 -> V_131 . V_130 = 0 ;
V_105 -> V_131 . V_96 = 0 ;
V_105 -> V_131 . V_132 = 0 ;
V_105 -> V_95 . V_132 = 0 ;
V_105 -> V_97 . V_132 = 0 ;
V_105 -> V_98 . V_132 = 0 ;
break;
default:
F_34 ( L_26 , V_53 ,
V_105 -> V_102 ) ;
return - V_49 ;
}
if ( V_87 -> V_105 . V_19 != V_105 -> V_19 ||
V_87 -> V_105 . V_99 != V_105 -> V_99 ||
V_87 -> V_105 . V_100 != V_105 -> V_100 ||
V_87 -> V_105 . V_101 != V_105 -> V_101 ) {
F_34 ( L_27 ,
V_53 , V_105 -> V_19 , V_105 -> V_99 ) ;
return - V_49 ;
}
if ( ( V_87 -> V_106 . V_92 * V_105 -> V_101 ) > V_87 -> V_106 . V_91 ) {
F_34 ( L_28 ,
V_53 , V_105 -> V_101 ) ;
return - V_74 ;
}
return 0 ;
}
static int
F_70 ( struct V_129 * V_105 , struct V_126 * V_87 )
{
int V_133 ;
V_85 V_134 ;
struct V_1 * V_2 = F_67 ( V_87 ) ;
if ( ! V_105 || ! V_87 )
return - V_49 ;
if ( V_105 -> V_135 - V_87 -> V_105 . V_135 ) {
return - V_49 ;
}
V_133 = V_105 -> V_136 - V_87 -> V_105 . V_136 ;
if ( V_133 ) {
F_34 ( L_29 , V_53 , V_133 ) ;
V_134 = V_2 -> V_7 -> V_12 ;
V_134 += ( V_87 -> V_106 . V_92 * V_133 ) ;
V_2 -> V_7 -> V_12 = ( unsigned long ) V_134 ;
V_2 -> V_9 -> V_12 = ( unsigned long ) V_134 + V_2 -> V_29 ;
}
return 0 ;
}
static int F_71 ( int V_137 , struct V_126 * V_87 )
{
struct V_1 * V_2 = F_67 ( V_87 ) ;
switch ( V_137 ) {
case V_138 :
F_31 ( V_2 -> V_39 , V_47 ) ;
break;
case V_139 :
case V_140 :
case V_141 :
F_31 ( V_2 -> V_39 , V_48 ) ;
break;
default:
return - V_49 ;
break;
}
return 0 ;
}
int F_72 ( struct V_126 * V_87 , struct V_142 * V_143 )
{
if ( V_144 )
return 0 ;
else
return - V_49 ;
}
static int F_73 ( T_8 V_145 , T_8 V_95 , T_8 V_97 ,
T_8 V_98 , T_8 V_131 ,
struct V_126 * V_87 )
{
if ( V_145 >= V_114 )
return - V_49 ;
if ( V_87 -> V_105 . V_146 )
V_95 = V_97 = V_98 = ( V_95 * 77 + V_97 * 151 + V_98 * 28 ) >> 8 ;
if ( V_87 -> V_106 . V_147 == V_148 ) {
V_85 V_41 ;
if ( V_145 > 16 )
return - V_49 ;
V_95 >>= ( 16 - V_87 -> V_105 . V_95 . V_96 ) ;
V_97 >>= ( 16 - V_87 -> V_105 . V_97 . V_96 ) ;
V_98 >>= ( 16 - V_87 -> V_105 . V_98 . V_96 ) ;
V_41 = ( V_95 << V_87 -> V_105 . V_95 . V_130 ) |
( V_97 << V_87 -> V_105 . V_97 . V_130 ) |
( V_98 << V_87 -> V_105 . V_98 . V_130 ) ;
V_41 &= 0xFFFF ;
( ( V_85 * ) ( V_87 -> V_111 ) ) [ V_145 ] = V_41 ;
}
return 0 ;
}
static int F_74 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_75 ( V_39 ) ;
F_31 ( V_39 , V_46 ) ;
if ( V_2 -> V_25 )
F_63 ( NULL , V_2 -> V_75 , V_2 -> V_25 , V_2 -> V_84 ) ;
F_60 ( V_30 ) ;
F_59 ( V_117 , V_2 ) ;
F_58 ( & V_2 -> V_87 ) ;
F_76 ( L_23 , NULL ) ;
F_61 ( & V_2 -> V_87 . V_113 ) ;
F_62 ( V_2 -> V_87 . V_111 ) ;
if ( V_76 )
F_65 ( F_49 ( V_77 ) ) ;
F_64 ( V_81 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
static int F_77 ( struct V_149 * V_72 )
{
struct V_1 * V_2 = F_78 ( V_72 ) ;
if ( V_2 -> V_119 ) {
F_13 () ;
F_25 () ;
F_1 ( V_2 , V_128 ) ;
}
F_31 ( V_2 -> V_39 , V_46 ) ;
return 0 ;
}
static int F_79 ( struct V_149 * V_72 )
{
struct V_1 * V_2 = F_78 ( V_72 ) ;
F_31 ( V_2 -> V_39 , V_45 ) ;
if ( V_2 -> V_119 ) {
F_1 ( V_2 , V_4 ) ;
F_16 ( V_2 ) ;
F_4 ( V_2 ) ;
F_23 () ;
}
return 0 ;
}
static int T_9 F_80 ( void )
{
#if F_81 ( V_150 ) || F_81 ( V_151 )
F_82 ( L_30 ) ;
#else
F_82 ( L_31 ) ;
#endif
return F_83 ( & V_152 ) ;
}
static void T_10 F_84 ( void )
{
F_85 ( & V_152 ) ;
}
