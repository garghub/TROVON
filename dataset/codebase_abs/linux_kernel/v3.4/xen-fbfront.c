static void F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 )
{
T_1 V_5 ;
V_5 = V_2 -> V_6 -> V_7 ;
F_2 () ;
F_3 ( V_2 -> V_6 , V_5 ) = * V_4 ;
F_4 () ;
V_2 -> V_6 -> V_7 = V_5 + 1 ;
F_5 ( V_2 -> V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
int V_9 , int V_10 , int V_11 , int V_12 )
{
union V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . type = V_13 ;
V_4 . V_14 . V_9 = V_9 ;
V_4 . V_14 . V_10 = V_10 ;
V_4 . V_14 . V_15 = V_11 ;
V_4 . V_14 . V_16 = V_12 ;
F_1 ( V_2 , & V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_17 = V_2 -> V_17 ;
F_1 ( V_2 , & V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_18 , V_5 ;
V_5 = V_2 -> V_6 -> V_7 ;
V_18 = V_2 -> V_6 -> V_19 ;
return V_5 - V_18 == V_20 ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned long V_21 ;
F_10 ( & V_2 -> V_22 , V_21 ) ;
if ( V_2 -> V_23 ) {
if ( ! F_8 ( V_2 ) ) {
V_2 -> V_23 = 0 ;
F_7 ( V_2 ) ;
}
}
F_11 ( & V_2 -> V_22 , V_21 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
int V_24 , int y1 , int V_11 , int V_12 )
{
unsigned long V_21 ;
int V_25 = V_24 + V_11 - 1 ;
int V_26 = y1 + V_12 - 1 ;
F_9 ( V_2 ) ;
if ( ! V_2 -> V_27 )
return;
F_10 ( & V_2 -> V_28 , V_21 ) ;
if ( V_2 -> y1 < y1 )
y1 = V_2 -> y1 ;
if ( V_2 -> V_26 > V_26 )
V_26 = V_2 -> V_26 ;
if ( V_2 -> V_24 < V_24 )
V_24 = V_2 -> V_24 ;
if ( V_2 -> V_25 > V_25 )
V_25 = V_2 -> V_25 ;
if ( F_8 ( V_2 ) ) {
V_2 -> V_24 = V_24 ;
V_2 -> V_25 = V_25 ;
V_2 -> y1 = y1 ;
V_2 -> V_26 = V_26 ;
F_11 ( & V_2 -> V_28 , V_21 ) ;
return;
}
V_2 -> V_24 = V_2 -> y1 = V_29 ;
V_2 -> V_25 = V_2 -> V_26 = 0 ;
F_11 ( & V_2 -> V_28 , V_21 ) ;
if ( V_24 <= V_25 && y1 <= V_26 )
F_6 ( V_2 , V_24 , y1 , V_25 - V_24 + 1 , V_26 - y1 + 1 ) ;
}
static void F_13 ( struct V_30 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = V_30 -> V_33 ;
struct V_6 * V_6 ;
unsigned long V_34 , V_35 ;
int y1 , V_26 , V_36 , V_37 ;
V_36 = V_29 ;
V_37 = 0 ;
F_14 (page, pagelist, lru) {
V_34 = V_6 -> V_38 << V_39 ;
V_35 = V_34 + V_40 - 1 ;
y1 = V_34 / V_30 -> V_41 . V_42 ;
V_26 = V_35 / V_30 -> V_41 . V_42 ;
if ( V_26 >= V_30 -> V_43 . V_44 )
V_26 = V_30 -> V_43 . V_44 - 1 ;
if ( V_36 > y1 )
V_36 = y1 ;
if ( V_37 < V_26 )
V_37 = V_26 ;
}
F_12 ( V_2 , 0 , V_36 , V_30 -> V_43 . V_45 , V_37 - V_36 + 1 ) ;
}
static int F_15 ( unsigned V_46 , unsigned V_47 , unsigned V_48 ,
unsigned V_49 , unsigned V_50 ,
struct V_30 * V_2 )
{
T_1 V_51 ;
if ( V_46 > V_2 -> V_52 . V_53 )
return 1 ;
#define F_16 ( T_2 , V_15 ) ((((val)<<(width))+0x7FFF-(val))>>16)
V_47 = F_16 ( V_47 , V_2 -> V_43 . V_47 . V_54 ) ;
V_48 = F_16 ( V_48 , V_2 -> V_43 . V_48 . V_54 ) ;
V_49 = F_16 ( V_49 , V_2 -> V_43 . V_49 . V_54 ) ;
V_50 = F_16 ( V_50 , V_2 -> V_43 . V_50 . V_54 ) ;
#undef F_16
V_51 = ( V_47 << V_2 -> V_43 . V_47 . V_55 ) |
( V_48 << V_2 -> V_43 . V_48 . V_55 ) |
( V_49 << V_2 -> V_43 . V_49 . V_55 ) ;
switch ( V_2 -> V_43 . V_56 ) {
case 16 :
case 24 :
case 32 :
( ( T_1 * ) V_2 -> V_57 ) [ V_46 ] = V_51 ;
break;
}
return 0 ;
}
static void F_17 ( struct V_30 * V_58 , const struct V_59 * V_60 )
{
struct V_1 * V_2 = V_58 -> V_33 ;
F_18 ( V_58 , V_60 ) ;
F_12 ( V_2 , V_60 -> V_61 , V_60 -> V_62 , V_60 -> V_15 , V_60 -> V_16 ) ;
}
static void F_19 ( struct V_30 * V_58 , const struct V_63 * V_64 )
{
struct V_1 * V_2 = V_58 -> V_33 ;
F_20 ( V_58 , V_64 ) ;
F_12 ( V_2 , V_64 -> V_61 , V_64 -> V_62 , V_64 -> V_15 , V_64 -> V_16 ) ;
}
static void F_21 ( struct V_30 * V_58 , const struct V_65 * V_66 )
{
struct V_1 * V_2 = V_58 -> V_33 ;
F_22 ( V_58 , V_66 ) ;
F_12 ( V_2 , V_66 -> V_61 , V_66 -> V_62 , V_66 -> V_15 , V_66 -> V_16 ) ;
}
static T_3 F_23 ( struct V_30 * V_58 , const char T_4 * V_67 ,
T_5 V_68 , T_6 * V_69 )
{
struct V_1 * V_2 = V_58 -> V_33 ;
T_3 V_70 ;
V_70 = F_24 ( V_58 , V_67 , V_68 , V_69 ) ;
F_12 ( V_2 , 0 , 0 , V_2 -> V_6 -> V_15 , V_2 -> V_6 -> V_16 ) ;
return V_70 ;
}
static int
F_25 ( struct V_71 * V_43 , struct V_30 * V_2 )
{
struct V_1 * V_1 ;
int V_72 ;
V_1 = V_2 -> V_33 ;
if ( ! V_1 -> V_73 ) {
if ( V_43 -> V_45 == V_74 [ V_75 ] &&
V_43 -> V_44 == V_74 [ V_76 ] &&
V_43 -> V_56 == V_1 -> V_6 -> V_77 ) {
return 0 ;
}
return - V_78 ;
}
if ( V_43 -> V_45 > V_74 [ V_75 ] || V_43 -> V_44 > V_74 [ V_76 ] )
return - V_78 ;
V_72 = V_43 -> V_45 * V_43 -> V_44 * V_1 -> V_6 -> V_77 / 8 ;
if ( V_43 -> V_56 == V_1 -> V_6 -> V_77 &&
V_43 -> V_45 <= V_2 -> V_41 . V_42 / ( V_79 / 8 ) &&
V_72 <= V_2 -> V_41 . V_80 ) {
V_43 -> V_81 = V_43 -> V_45 ;
V_43 -> V_82 = V_43 -> V_44 ;
return 0 ;
}
return - V_78 ;
}
static int F_26 ( struct V_30 * V_2 )
{
struct V_1 * V_1 ;
unsigned long V_21 ;
V_1 = V_2 -> V_33 ;
F_10 ( & V_1 -> V_22 , V_21 ) ;
V_1 -> V_17 . type = V_83 ;
V_1 -> V_17 . V_15 = V_2 -> V_43 . V_45 ;
V_1 -> V_17 . V_16 = V_2 -> V_43 . V_44 ;
V_1 -> V_17 . V_84 = V_2 -> V_41 . V_42 ;
V_1 -> V_17 . V_77 = V_2 -> V_43 . V_56 ;
V_1 -> V_17 . V_55 = 0 ;
V_1 -> V_23 = 1 ;
F_11 ( & V_1 -> V_22 , V_21 ) ;
return 0 ;
}
static T_7 F_27 ( int V_85 , void * V_86 )
{
struct V_1 * V_2 = V_86 ;
struct V_87 * V_6 = V_2 -> V_6 ;
if ( V_6 -> V_88 != V_6 -> V_89 ) {
V_2 -> V_6 -> V_88 = V_2 -> V_6 -> V_89 ;
F_5 ( V_2 -> V_8 ) ;
}
F_12 ( V_2 , V_29 , V_29 , - V_29 , - V_29 ) ;
return V_90 ;
}
static int T_8 F_28 ( struct V_91 * V_92 ,
const struct V_93 * V_94 )
{
struct V_1 * V_2 ;
struct V_30 * V_30 ;
int V_95 ;
int T_2 ;
int V_96 = 0 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_97 ) ;
if ( V_2 == NULL ) {
F_30 ( V_92 , - V_98 , L_1 ) ;
return - V_98 ;
}
if ( F_31 ( V_99 , V_92 -> V_100 , L_2 , L_3 , & T_2 ) == 1 ) {
if ( T_2 < V_74 [ V_101 ] )
V_74 [ V_101 ] = T_2 ;
}
V_95 = V_74 [ V_101 ] * 1024 * 1024 ;
if ( V_74 [ V_75 ] * V_74 [ V_76 ] * V_79 / 8
> V_95 ) {
V_74 [ V_75 ] = V_102 ;
V_74 [ V_76 ] = V_103 ;
V_95 = V_104 ;
}
F_32 ( & V_92 -> V_92 , V_2 ) ;
V_2 -> V_105 = V_92 ;
V_2 -> V_8 = - 1 ;
V_2 -> V_24 = V_2 -> y1 = V_29 ;
F_33 ( & V_2 -> V_28 ) ;
F_33 ( & V_2 -> V_22 ) ;
V_2 -> V_106 = F_34 ( V_95 ) ;
if ( V_2 -> V_106 == NULL )
goto V_107;
V_2 -> V_108 = ( V_95 + V_40 - 1 ) >> V_39 ;
V_2 -> V_109 = F_35 ( sizeof( unsigned long ) * V_2 -> V_108 ) ;
if ( ! V_2 -> V_109 )
goto V_107;
V_2 -> V_6 = ( void * ) F_36 ( V_97 | V_110 ) ;
if ( ! V_2 -> V_6 )
goto V_107;
V_30 = F_37 ( sizeof( T_1 ) * 256 , NULL ) ;
if ( V_30 == NULL )
goto V_107;
V_30 -> V_57 = V_30 -> V_33 ;
V_30 -> V_33 = V_2 ;
V_30 -> V_111 = V_2 -> V_106 ;
V_30 -> V_112 = & V_113 ;
V_30 -> V_43 . V_81 = V_30 -> V_43 . V_45 = V_74 [ V_75 ] ;
V_30 -> V_43 . V_82 = V_30 -> V_43 . V_44 = V_74 [ V_76 ] ;
V_30 -> V_43 . V_56 = V_79 ;
V_30 -> V_43 . V_47 = (struct V_114 ) { 16 , 8 , 0 } ;
V_30 -> V_43 . V_48 = (struct V_114 ) { 8 , 8 , 0 } ;
V_30 -> V_43 . V_49 = (struct V_114 ) { 0 , 8 , 0 } ;
V_30 -> V_43 . V_115 = V_116 ;
V_30 -> V_43 . V_16 = - 1 ;
V_30 -> V_43 . V_15 = - 1 ;
V_30 -> V_43 . V_117 = V_118 ;
V_30 -> V_41 . V_119 = V_120 ;
V_30 -> V_41 . V_42 = V_30 -> V_43 . V_45 * V_79 / 8 ;
V_30 -> V_41 . V_121 = 0 ;
V_30 -> V_41 . V_80 = V_95 ;
strcpy ( V_30 -> V_41 . V_94 , L_4 ) ;
V_30 -> V_41 . type = V_122 ;
V_30 -> V_41 . V_123 = V_124 ;
V_30 -> V_21 = V_125 | V_126 ;
V_96 = F_38 ( & V_30 -> V_52 , 256 , 0 ) ;
if ( V_96 < 0 ) {
F_39 ( V_30 ) ;
F_30 ( V_92 , V_96 , L_5 ) ;
goto error;
}
V_30 -> V_127 = & V_128 ;
F_40 ( V_30 ) ;
F_41 ( V_2 , V_30 ) ;
V_96 = F_42 ( V_92 , V_2 ) ;
if ( V_96 < 0 ) {
F_30 ( V_92 , V_96 , L_6 ) ;
goto V_129;
}
V_96 = F_43 ( V_30 ) ;
if ( V_96 ) {
F_30 ( V_92 , V_96 , L_7 ) ;
goto V_129;
}
V_2 -> V_30 = V_30 ;
F_44 () ;
return 0 ;
V_129:
F_45 ( V_30 ) ;
F_46 ( & V_30 -> V_52 ) ;
F_39 ( V_30 ) ;
V_107:
if ( ! V_96 ) {
V_96 = - V_98 ;
F_30 ( V_92 , V_96 , L_8 ) ;
}
error:
F_47 ( V_92 ) ;
return V_96 ;
}
static T_8 void
F_44 ( void )
{
struct V_130 * V_131 ;
if ( V_132 )
return;
F_48 () ;
F_49 (c) {
if ( ! strcmp ( V_131 -> V_133 , L_9 ) && V_131 -> V_38 == 0 )
break;
}
F_50 () ;
if ( V_131 ) {
F_51 ( V_131 ) ;
V_131 -> V_21 |= V_134 ;
V_131 -> V_21 &= ~ V_135 ;
F_52 ( V_131 ) ;
}
}
static int F_53 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_54 ( & V_92 -> V_92 ) ;
F_55 ( V_2 ) ;
F_41 ( V_2 , V_2 -> V_30 ) ;
return F_42 ( V_92 , V_2 ) ;
}
static int F_47 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_54 ( & V_92 -> V_92 ) ;
F_55 ( V_2 ) ;
if ( V_2 -> V_30 ) {
F_45 ( V_2 -> V_30 ) ;
F_56 ( V_2 -> V_30 ) ;
F_46 ( & V_2 -> V_30 -> V_52 ) ;
F_39 ( V_2 -> V_30 ) ;
}
F_57 ( ( unsigned long ) V_2 -> V_6 ) ;
F_58 ( V_2 -> V_109 ) ;
F_58 ( V_2 -> V_106 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static unsigned long F_60 ( void * V_136 )
{
return F_61 ( F_62 ( V_136 ) ) ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_30 * V_30 )
{
int V_137 ;
int V_138 = V_40 / sizeof( V_2 -> V_109 [ 0 ] ) ;
for ( V_137 = 0 ; V_137 < V_2 -> V_108 ; V_137 ++ )
V_2 -> V_109 [ V_137 ] = F_60 ( V_2 -> V_106 + V_137 * V_40 ) ;
for ( V_137 = 0 ; V_137 * V_138 < V_2 -> V_108 ; V_137 ++ )
V_2 -> V_6 -> V_139 [ V_137 ] = F_60 ( & V_2 -> V_109 [ V_137 * V_138 ] ) ;
V_2 -> V_6 -> V_15 = V_30 -> V_43 . V_45 ;
V_2 -> V_6 -> V_16 = V_30 -> V_43 . V_44 ;
V_2 -> V_6 -> V_77 = V_30 -> V_43 . V_56 ;
V_2 -> V_6 -> V_42 = V_30 -> V_41 . V_42 ;
V_2 -> V_6 -> V_140 = V_30 -> V_41 . V_80 ;
V_2 -> V_6 -> V_88 = V_2 -> V_6 -> V_89 = 0 ;
V_2 -> V_6 -> V_19 = V_2 -> V_6 -> V_7 = 0 ;
}
static int F_42 ( struct V_91 * V_92 ,
struct V_1 * V_2 )
{
int V_96 , V_141 , V_8 ;
struct V_142 V_143 ;
V_96 = F_63 ( V_92 , & V_141 ) ;
if ( V_96 )
return V_96 ;
V_8 = F_64 ( V_141 , F_27 ,
0 , V_92 -> V_144 , V_2 ) ;
if ( V_8 < 0 ) {
F_65 ( V_92 , V_141 ) ;
F_30 ( V_92 , V_96 , L_10 ) ;
return V_8 ;
}
V_145:
V_96 = F_66 ( & V_143 ) ;
if ( V_96 ) {
F_30 ( V_92 , V_96 , L_11 ) ;
goto V_146;
}
V_96 = F_67 ( V_143 , V_92 -> V_147 , L_12 , L_13 ,
F_68 ( V_2 -> V_6 ) ) ;
if ( V_96 )
goto V_148;
V_96 = F_67 ( V_143 , V_92 -> V_147 , L_14 , L_15 ,
V_141 ) ;
if ( V_96 )
goto V_148;
V_96 = F_67 ( V_143 , V_92 -> V_147 , L_16 , L_17 ,
V_149 ) ;
if ( V_96 )
goto V_148;
V_96 = F_67 ( V_143 , V_92 -> V_147 , L_18 , L_19 ) ;
if ( V_96 )
goto V_148;
V_96 = F_69 ( V_143 , 0 ) ;
if ( V_96 ) {
if ( V_96 == - V_150 )
goto V_145;
F_30 ( V_92 , V_96 , L_20 ) ;
goto V_146;
}
F_70 ( V_92 , V_151 ) ;
V_2 -> V_8 = V_8 ;
return 0 ;
V_148:
F_69 ( V_143 , 1 ) ;
F_30 ( V_92 , V_96 , L_21 ) ;
V_146:
F_71 ( V_8 , V_2 ) ;
return V_96 ;
}
static void F_55 ( struct V_1 * V_2 )
{
V_2 -> V_27 = 0 ;
if ( V_2 -> V_8 >= 0 )
F_71 ( V_2 -> V_8 , V_2 ) ;
V_2 -> V_8 = - 1 ;
}
static void F_72 ( struct V_91 * V_92 ,
enum V_152 V_153 )
{
struct V_1 * V_2 = F_54 ( & V_92 -> V_92 ) ;
int T_2 ;
switch ( V_153 ) {
case V_154 :
case V_151 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
break;
case V_159 :
V_160:
F_70 ( V_92 , V_161 ) ;
break;
case V_161 :
if ( V_92 -> V_162 != V_161 )
goto V_160;
if ( F_31 ( V_99 , V_2 -> V_105 -> V_100 ,
L_22 , L_3 , & T_2 ) < 0 )
T_2 = 0 ;
if ( T_2 )
V_2 -> V_27 = 1 ;
if ( F_31 ( V_99 , V_92 -> V_100 ,
L_23 , L_3 , & T_2 ) < 0 )
T_2 = 0 ;
V_2 -> V_73 = T_2 ;
break;
case V_163 :
F_73 ( V_92 ) ;
break;
}
}
static int T_9 F_74 ( void )
{
if ( ! F_75 () )
return - V_164 ;
if ( F_76 () )
return - V_164 ;
return F_77 ( & V_165 ) ;
}
static void T_10 F_78 ( void )
{
F_79 ( & V_165 ) ;
}
