static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) ( V_3 -> V_4 ) ;
}
static inline struct V_2 * F_2 ( struct V_1 * V_5 )
{
return F_3 ( ( void * ) V_5 , struct V_2 , V_4 ) ;
}
static inline struct V_1 * F_4 ( T_1 * V_5 )
{
return F_3 ( V_5 , struct V_1 , V_6 ) ;
}
static T_2 F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_8 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_7 ( & V_7 -> V_6 ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
return V_10 ;
}
static void F_9 ( T_1 * V_6 ,
T_3 V_11 ,
T_4 V_12 ,
int V_13 ,
int V_14 ,
int V_15 ,
void * V_16 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
F_10 ( & V_7 -> V_9 ) ;
F_11 ( F_2 ( V_7 ) ) ;
F_12 ( & V_7 -> V_9 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_8 ;
V_3 -> V_17 = V_18 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_14 ( & V_7 -> V_6 , V_19 ,
F_9 , NULL ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_8 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_14 ( & V_7 -> V_6 , V_19 ,
NULL , NULL ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
V_3 -> V_17 = V_20 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_17 ( & V_7 -> V_6 ) ;
}
static void F_18 ( T_1 * V_6 ,
T_3 V_11 ,
T_4 V_12 ,
int V_13 ,
int V_14 ,
int V_15 ,
void * V_16 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
struct V_2 * V_3 = F_2 ( V_7 ) ;
struct V_21 * V_22 = V_3 -> V_23 . V_24 ;
struct V_25 * V_25 = V_16 ;
V_25 -> V_26 = V_15 ;
V_25 -> V_27 = NULL ;
if ( ! F_19 ( & V_25 -> V_28 ) ) {
F_20 ( & V_25 -> V_28 ) ;
F_21 ( & V_25 -> V_28 ) ;
}
if ( F_22 ( V_25 -> V_29 ) == V_30 ) {
int V_31 ;
T_5 * V_32 = ( T_5 * ) V_25 -> V_33 ;
V_25 -> V_26 = 0 ;
for ( V_31 = 0 ; V_31 < V_25 -> V_34 ; V_31 ++ ) {
if ( V_32 [ V_31 ] . V_12 == V_35 ) {
V_25 -> V_36 [ V_31 ] . V_12 = 0 ;
V_25 -> V_36 [ V_31 ] . V_26 = V_32 [ V_31 ] . V_37 ;
V_25 -> V_26 += V_25 -> V_36 [ V_31 ] . V_26 ;
} else {
F_23 ( V_22 , L_1 ,
V_31 , V_25 -> V_34 ,
V_32 [ V_31 ] . V_12 , V_13 ,
V_14 , V_32 [ V_31 ] . V_37 ) ;
V_25 -> V_36 [ V_31 ] . V_12 = - V_38 ;
}
}
F_24 ( V_32 ) ;
V_25 -> V_33 = NULL ;
}
switch ( V_12 ) {
case V_35 :
V_25 -> V_12 = 0 ;
break;
case V_39 :
if ( V_25 -> V_12 == 0 )
V_25 -> V_12 = - V_40 ;
break;
case V_41 :
F_23 ( V_22 , L_2 ,
V_13 , V_14 , V_15 ) ;
V_25 -> V_12 = - V_42 ;
break;
case V_43 :
F_23 ( V_22 , L_3 ,
V_13 , V_14 , V_15 ) ;
V_25 -> V_12 = - V_42 ;
break;
case V_44 :
F_23 ( V_22 , L_4 ,
V_13 , V_14 , V_15 ) ;
V_25 -> V_12 = - V_38 ;
break;
case V_45 :
case V_46 :
case V_47 :
case V_48 :
F_23 ( V_22 , L_5 ,
V_12 , V_13 , V_14 , V_15 ) ;
V_25 -> V_12 = - V_49 ;
break;
}
F_10 ( & V_7 -> V_9 ) ;
F_25 ( F_2 ( V_7 ) , V_25 , V_25 -> V_12 ) ;
F_12 ( & V_7 -> V_9 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_25 * V_25 ,
T_6 V_50 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_3 -> V_23 . V_24 ;
int V_14 = - 1 ;
int V_13 ;
unsigned long V_8 ;
T_5 * V_32 ;
struct V_51 * V_52 = V_25 -> V_52 ;
V_25 -> V_12 = 0 ;
F_21 ( & V_25 -> V_28 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
if ( ! V_52 -> V_27 ) {
T_7 V_53 ;
T_8 V_54 ;
int V_55 = 0 ;
int V_56 = 0 ;
switch ( F_22 ( V_25 -> V_29 ) ) {
case V_30 :
V_53 = V_57 ;
break;
case V_58 :
V_53 = V_59 ;
break;
case V_60 :
V_53 = V_61 ;
break;
default:
V_53 = V_62 ;
break;
}
switch ( V_25 -> V_22 -> V_54 ) {
case V_63 :
V_54 = V_64 ;
break;
case V_65 :
V_54 = V_66 ;
break;
default:
V_54 = V_67 ;
break;
}
if ( V_54 != V_67 ) {
struct V_68 * V_22 = V_25 -> V_22 ;
while ( V_22 -> V_69 ) {
if ( V_22 -> V_69 -> V_54 == V_70 ) {
V_55 = V_22 -> V_69 -> V_71 ;
V_56 = V_22 -> V_72 ;
break;
}
V_22 = V_22 -> V_69 ;
}
}
V_13 = F_27 ( & V_7 -> V_6 ,
0 ,
F_28 ( V_25 -> V_29 ) ,
F_29 ( V_25 -> V_29 ) ,
V_54 ,
F_30 ( V_52 -> V_73 . V_74 ) & 0x7ff ,
V_53 ,
F_31 ( V_25 -> V_29 ) ? V_75 : V_76 ,
V_25 -> V_77 ,
( F_30 ( V_52 -> V_73 . V_74 ) >> 11 ) & 0x3 ,
V_55 ,
V_56 ) ;
if ( V_13 < 0 ) {
F_8 ( & V_7 -> V_9 , V_8 ) ;
F_23 ( V_22 , L_6 ) ;
return - V_78 ;
}
V_52 -> V_27 = ( void * ) ( 0x10000L + V_13 ) ;
} else {
V_13 = 0xffff & ( long ) V_52 -> V_27 ;
}
switch ( F_22 ( V_25 -> V_29 ) ) {
case V_30 :
F_23 ( V_22 , L_7 ,
F_28 ( V_25 -> V_29 ) , F_29 ( V_25 -> V_29 ) ) ;
V_32 = F_32 ( V_25 -> V_34 * sizeof( T_5 ) , V_79 ) ;
if ( V_32 ) {
int V_31 ;
for ( V_31 = 0 ; V_31 < V_25 -> V_34 ; V_31 ++ ) {
V_32 [ V_31 ] . V_80 = V_25 -> V_36 [ V_31 ] . V_80 ;
V_32 [ V_31 ] . V_37 = V_25 -> V_36 [ V_31 ] . V_37 ;
V_32 [ V_31 ] . V_12 = V_45 ;
}
V_25 -> V_33 = ( char * ) V_32 ;
V_14 = F_33 ( & V_7 -> V_6 , V_13 ,
V_25 -> V_81 ,
0 ,
V_25 -> V_34 ,
V_32 ,
V_25 -> V_82 ,
V_25 -> V_83 ,
F_18 ,
V_25 ) ;
if ( V_14 < 0 ) {
V_25 -> V_33 = NULL ;
F_24 ( V_32 ) ;
}
}
break;
case V_58 :
F_23 ( V_22 , L_8 ,
F_28 ( V_25 -> V_29 ) , F_29 ( V_25 -> V_29 ) ) ;
V_14 = F_34 ( & V_7 -> V_6 , V_13 ,
V_25 -> V_82 ,
V_25 -> V_83 ,
F_18 ,
V_25 ) ;
break;
case V_60 :
F_23 ( V_22 , L_9 ,
F_28 ( V_25 -> V_29 ) , F_29 ( V_25 -> V_29 ) ) ;
V_14 = F_35 ( & V_7 -> V_6 , V_13 ,
V_25 -> V_84 ,
V_25 -> V_82 ,
V_25 -> V_83 ,
F_18 ,
V_25 ) ;
break;
case V_85 :
F_23 ( V_22 , L_10 ,
F_28 ( V_25 -> V_29 ) , F_29 ( V_25 -> V_29 ) ) ;
V_14 = F_36 ( & V_7 -> V_6 , V_13 ,
V_25 -> V_82 ,
V_25 -> V_83 ,
F_18 ,
V_25 ) ;
break;
}
if ( V_14 < 0 ) {
F_8 ( & V_7 -> V_9 , V_8 ) ;
F_23 ( V_22 , L_11 ) ;
return - V_78 ;
}
V_25 -> V_27 = ( void * ) ( long ) ( ( ( V_14 & 0xffff ) << 16 ) | V_13 ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_37 ( unsigned long V_86 )
{
unsigned long V_8 ;
struct V_1 * V_7 = (struct V_1 * ) V_86 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
while ( ! F_19 ( & V_7 -> V_87 ) ) {
int V_13 ;
int V_14 ;
struct V_25 * V_25 = F_3 ( V_7 -> V_87 . V_88 , struct V_25 , V_28 ) ;
F_20 ( & V_25 -> V_28 ) ;
F_21 ( & V_25 -> V_28 ) ;
V_13 = 0xffff & ( long ) V_25 -> V_27 ;
V_14 = ( ( long ) V_25 -> V_27 ) >> 16 ;
F_38 ( & V_7 -> V_6 , V_13 , V_14 ) ;
}
F_8 ( & V_7 -> V_9 , V_8 ) ;
}
static int F_39 ( struct V_2 * V_3 , struct V_25 * V_25 , int V_12 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_8 ;
if ( ! V_25 -> V_22 )
return - V_89 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
V_25 -> V_12 = V_12 ;
F_40 ( & V_25 -> V_28 , & V_7 -> V_87 ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
F_41 ( & V_7 -> V_90 ) ;
return 0 ;
}
static void F_42 ( struct V_2 * V_3 , struct V_51 * V_52 )
{
struct V_21 * V_22 = V_3 -> V_23 . V_24 ;
if ( V_52 -> V_27 ) {
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_13 = 0xffff & ( long ) V_52 -> V_27 ;
unsigned long V_8 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_43 ( & V_7 -> V_6 , V_13 ) ;
if ( F_44 ( & V_7 -> V_6 , V_13 ) )
F_23 ( V_22 , L_12 , V_13 ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
V_52 -> V_27 = NULL ;
}
}
static int F_45 ( struct V_2 * V_3 , char * V_91 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_9 V_92 ;
unsigned long V_8 ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
V_92 = F_46 ( & V_7 -> V_6 ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
V_91 [ 0 ] = 0 ;
V_91 [ 0 ] = V_92 . V_93 << 1 ;
return ( V_91 [ 0 ] != 0 ) ;
}
static int F_47 ( struct V_2 * V_3 , T_10 V_94 , T_10 V_95 , T_10 V_96 , char * V_91 , T_10 V_97 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_3 -> V_23 . V_24 ;
T_9 V_98 ;
int V_92 ;
struct V_99 * V_73 ;
unsigned long V_8 ;
switch ( V_94 ) {
case V_100 :
F_23 ( V_22 , L_13 ) ;
switch ( V_95 ) {
case V_101 :
case V_102 :
break;
default:
return - V_89 ;
}
break;
case V_103 :
F_23 ( V_22 , L_14 ) ;
if ( V_96 != 1 ) {
F_23 ( V_22 , L_15 ) ;
return - V_89 ;
}
switch ( V_95 ) {
case V_104 :
F_23 ( V_22 , L_16 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_48 ( & V_7 -> V_6 ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
break;
case V_105 :
F_23 ( V_22 , L_17 ) ;
break;
case V_106 :
F_23 ( V_22 , L_18 ) ;
break;
case V_107 :
F_23 ( V_22 , L_19 ) ;
break;
case V_108 :
F_23 ( V_22 , L_20 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_49 ( & V_7 -> V_6 , F_46 ( & V_7 -> V_6 ) ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
break;
case V_109 :
F_23 ( V_22 , L_21 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_49 ( & V_7 -> V_6 , F_46 ( & V_7 -> V_6 ) ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
break;
case V_110 :
F_23 ( V_22 , L_22 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_49 ( & V_7 -> V_6 , F_46 ( & V_7 -> V_6 ) ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
break;
case V_111 :
F_23 ( V_22 , L_23 ) ;
break;
case V_112 :
F_23 ( V_22 , L_24 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_49 ( & V_7 -> V_6 , F_46 ( & V_7 -> V_6 ) ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
break;
default:
F_23 ( V_22 , L_25 ) ;
return - V_89 ;
}
break;
case V_113 :
F_23 ( V_22 , L_26 ) ;
V_73 = (struct V_99 * ) V_91 ;
V_73 -> V_114 = 9 ;
V_73 -> V_115 = 0x29 ;
V_73 -> V_116 = 1 ;
V_73 -> V_117 = 0x08 ;
V_73 -> V_118 = 1 ;
V_73 -> V_119 = 0 ;
V_73 -> V_120 . V_121 . V_122 [ 0 ] = 0 ;
V_73 -> V_120 . V_121 . V_122 [ 1 ] = 0xff ;
break;
case V_123 :
F_23 ( V_22 , L_27 ) ;
* ( V_124 * ) V_91 = 0 ;
break;
case V_125 :
F_23 ( V_22 , L_28 ) ;
if ( V_96 != 1 ) {
F_23 ( V_22 , L_15 ) ;
return - V_89 ;
}
F_6 ( & V_7 -> V_9 , V_8 ) ;
V_98 = F_46 ( & V_7 -> V_6 ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
V_92 = 0 ;
if ( V_98 . V_93 ) {
V_92 |= ( 1 << V_108 ) ;
F_23 ( V_22 , L_20 ) ;
}
if ( V_98 . V_126 ) {
V_92 |= ( 1 << V_110 ) ;
F_23 ( V_22 , L_22 ) ;
}
if ( V_98 . V_127 ) {
V_92 |= ( 1 << V_128 ) ;
F_23 ( V_22 , L_29 ) ;
}
if ( V_98 . V_126 ) {
V_92 |= ( 1 << V_104 ) ;
F_23 ( V_22 , L_16 ) ;
}
if ( V_98 . V_129 ) {
V_92 |= ( 1 << V_130 ) ;
F_23 ( V_22 , L_30 ) ;
}
if ( V_98 . V_131 ) {
V_92 |= ( 1 << V_106 ) ;
F_23 ( V_22 , L_18 ) ;
}
if ( V_98 . V_132 == V_67 ) {
V_92 |= V_133 ;
F_23 ( V_22 , L_31 ) ;
} else if ( V_98 . V_132 == V_64 ) {
V_92 |= ( 1 << V_134 ) ;
F_23 ( V_22 , L_32 ) ;
}
* ( ( V_124 * ) V_91 ) = F_50 ( V_92 ) ;
break;
case V_135 :
F_23 ( V_22 , L_33 ) ;
break;
case V_136 :
F_23 ( V_22 , L_34 ) ;
if ( V_96 != 1 ) {
F_23 ( V_22 , L_15 ) ;
return - V_89 ;
}
switch ( V_95 ) {
case V_105 :
F_23 ( V_22 , L_17 ) ;
return - V_89 ;
case V_106 :
F_23 ( V_22 , L_18 ) ;
return - V_89 ;
case V_137 :
F_23 ( V_22 , L_35 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_48 ( & V_7 -> V_6 ) ;
if ( F_51 ( & V_7 -> V_6 ) )
F_23 ( V_22 , L_36 ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
case V_107 :
F_23 ( V_22 , L_19 ) ;
break;
default:
F_23 ( V_22 , L_25 ) ;
return - V_89 ;
}
break;
default:
F_23 ( V_22 , L_37 ) ;
return - V_89 ;
}
return 0 ;
}
static int F_52 ( struct V_21 * V_22 )
{
int V_12 ;
int V_138 = F_53 ( V_22 ) -> V_139 ;
int V_140 = F_54 ( F_53 ( V_22 ) , 0 ) ;
struct V_1 * V_7 ;
struct V_2 * V_3 ;
unsigned long V_8 ;
V_22 -> V_141 = ~ 0 ;
V_22 -> V_142 = & V_22 -> V_141 ;
V_3 = F_55 ( & V_143 , V_22 , F_56 ( V_22 ) ) ;
if ( ! V_3 ) {
F_23 ( V_22 , L_38 ) ;
return - 1 ;
}
V_3 -> V_144 = 1 ;
V_7 = (struct V_1 * ) V_3 -> V_4 ;
F_57 ( & V_7 -> V_9 ) ;
F_58 ( & V_7 -> V_90 , F_37 , ( unsigned long ) V_7 ) ;
F_21 ( & V_7 -> V_87 ) ;
V_12 = F_59 ( & V_7 -> V_6 , V_138 , V_145 ) ;
if ( V_12 ) {
F_23 ( V_22 , L_39 , V_12 ) ;
F_24 ( V_3 ) ;
return - 1 ;
}
F_60 ( 10 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
F_7 ( & V_7 -> V_6 ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
V_12 = F_61 ( V_3 , V_140 , V_146 ) ;
if ( V_12 ) {
F_23 ( V_22 , L_40 , V_12 ) ;
F_24 ( V_3 ) ;
return - 1 ;
}
F_23 ( V_22 , L_41 , V_138 , V_140 ) ;
return 0 ;
}
static int F_62 ( struct V_21 * V_22 )
{
int V_12 ;
struct V_2 * V_3 = F_63 ( V_22 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_8 ;
F_64 ( V_3 ) ;
F_65 ( & V_7 -> V_90 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
V_12 = F_66 ( & V_7 -> V_6 ) ;
F_8 ( & V_7 -> V_9 , V_8 ) ;
if ( V_12 )
F_23 ( V_22 , L_42 , V_12 ) ;
F_24 ( V_3 ) ;
return 0 ;
}
static int T_11 F_67 ( void )
{
int V_147 = F_68 () ;
int V_21 ;
if ( F_69 () || V_147 == 0 )
return - V_148 ;
if ( F_70 ( & V_149 ) )
return - V_78 ;
V_150 = 1 ;
if ( F_71 ( V_151 ) || F_71 ( V_152 ) ) {
union V_153 V_154 ;
V_154 . V_155 = 0 ;
V_154 . V_156 . V_157 = 1 ;
V_154 . V_156 . V_158 = 400 ;
F_72 ( V_159 , V_154 . V_155 ) ;
}
for ( V_21 = 0 ; V_21 < V_147 ; V_21 ++ ) {
struct V_160 V_161 ;
struct V_162 * V_163 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_164 = ( V_21 == 0 ) ? V_165 : V_166 ;
V_161 . V_167 = V_161 . V_164 ;
V_161 . V_8 = V_168 ;
V_163 = F_73 ( ( char * ) V_149 . V_169 , V_21 , & V_161 , 1 ) ;
if ( F_74 ( V_163 ) ) {
F_75 ( & V_149 ) ;
V_150 = 0 ;
return F_76 ( V_163 ) ;
}
if ( V_21 < V_170 )
V_171 [ V_21 ] = V_163 ;
}
return 0 ;
}
static void T_12 F_77 ( void )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_170 ; V_31 ++ )
if ( V_171 [ V_31 ] ) {
F_78 ( V_171 [ V_31 ] ) ;
V_171 [ V_31 ] = NULL ;
}
if ( V_150 )
F_75 ( & V_149 ) ;
}
