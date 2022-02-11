static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) ( V_3 -> V_4 ) ;
}
static inline struct V_2 * F_2 ( struct V_1 * V_5 )
{
return F_3 ( ( void * ) V_5 , struct V_2 , V_4 ) ;
}
static inline struct V_1 * F_4 ( struct V_6 * V_5 )
{
return F_3 ( V_5 , struct V_1 , V_7 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long V_9 ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
F_7 ( & V_8 -> V_7 ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
return V_11 ;
}
static void F_9 ( struct V_6 * V_7 ,
enum V_12 V_13 ,
enum V_14 V_15 ,
int V_16 ,
int V_17 ,
int V_18 ,
void * V_19 )
{
struct V_1 * V_8 = F_4 ( V_7 ) ;
F_10 ( & V_8 -> V_10 ) ;
F_11 ( F_2 ( V_8 ) ) ;
F_12 ( & V_8 -> V_10 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long V_9 ;
V_3 -> V_20 = V_21 ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
F_14 ( & V_8 -> V_7 , V_22 ,
F_9 , NULL ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
return 0 ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long V_9 ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
F_14 ( & V_8 -> V_7 , V_22 ,
NULL , NULL ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
V_3 -> V_20 = V_23 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return F_17 ( & V_8 -> V_7 ) ;
}
static void F_18 ( struct V_6 * V_7 ,
enum V_12 V_13 ,
enum V_14 V_15 ,
int V_16 ,
int V_17 ,
int V_18 ,
void * V_19 )
{
struct V_1 * V_8 = F_4 ( V_7 ) ;
struct V_2 * V_3 = F_2 ( V_8 ) ;
struct V_24 * V_25 = V_3 -> V_26 . V_27 ;
struct V_28 * V_28 = V_19 ;
V_28 -> V_29 = V_18 ;
V_28 -> V_30 = NULL ;
if ( ! F_19 ( & V_28 -> V_31 ) ) {
F_20 ( & V_28 -> V_31 ) ;
F_21 ( & V_28 -> V_31 ) ;
}
if ( F_22 ( V_28 -> V_32 ) == V_33 ) {
int V_34 ;
struct V_35 * V_36 =
(struct V_35 * ) V_28 -> V_37 ;
V_28 -> V_29 = 0 ;
for ( V_34 = 0 ; V_34 < V_28 -> V_38 ; V_34 ++ ) {
if ( V_36 [ V_34 ] . V_15 == V_39 ) {
V_28 -> V_40 [ V_34 ] . V_15 = 0 ;
V_28 -> V_40 [ V_34 ] . V_29 = V_36 [ V_34 ] . V_41 ;
V_28 -> V_29 += V_28 -> V_40 [ V_34 ] . V_29 ;
} else {
F_23 ( V_25 , L_1 ,
V_34 , V_28 -> V_38 ,
V_36 [ V_34 ] . V_15 , V_16 ,
V_17 , V_36 [ V_34 ] . V_41 ) ;
V_28 -> V_40 [ V_34 ] . V_15 = - V_42 ;
}
}
F_24 ( V_36 ) ;
V_28 -> V_37 = NULL ;
}
switch ( V_15 ) {
case V_39 :
V_28 -> V_15 = 0 ;
break;
case V_43 :
if ( V_28 -> V_15 == 0 )
V_28 -> V_15 = - V_44 ;
break;
case V_45 :
F_23 ( V_25 , L_2 ,
V_16 , V_17 , V_18 ) ;
V_28 -> V_15 = - V_46 ;
break;
case V_47 :
F_23 ( V_25 , L_3 ,
V_16 , V_17 , V_18 ) ;
V_28 -> V_15 = - V_46 ;
break;
case V_48 :
F_23 ( V_25 , L_4 ,
V_16 , V_17 , V_18 ) ;
V_28 -> V_15 = - V_42 ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_23 ( V_25 , L_5 ,
V_15 , V_16 , V_17 , V_18 ) ;
V_28 -> V_15 = - V_53 ;
break;
}
F_10 ( & V_8 -> V_10 ) ;
F_25 ( F_2 ( V_8 ) , V_28 , V_28 -> V_15 ) ;
F_12 ( & V_8 -> V_10 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_28 * V_28 ,
T_2 V_54 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_24 * V_25 = V_3 -> V_26 . V_27 ;
int V_17 = - 1 ;
int V_16 ;
unsigned long V_9 ;
struct V_35 * V_36 ;
struct V_55 * V_56 = V_28 -> V_56 ;
V_28 -> V_15 = 0 ;
F_21 ( & V_28 -> V_31 ) ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
if ( ! V_56 -> V_30 ) {
enum V_57 V_58 ;
enum V_59 V_60 ;
int V_61 = 0 ;
int V_62 = 0 ;
switch ( F_22 ( V_28 -> V_32 ) ) {
case V_33 :
V_58 = V_63 ;
break;
case V_64 :
V_58 = V_65 ;
break;
case V_66 :
V_58 = V_67 ;
break;
default:
V_58 = V_68 ;
break;
}
switch ( V_28 -> V_25 -> V_60 ) {
case V_69 :
V_60 = V_70 ;
break;
case V_71 :
V_60 = V_72 ;
break;
default:
V_60 = V_73 ;
break;
}
if ( V_60 != V_73 ) {
struct V_74 * V_25 = V_28 -> V_25 ;
while ( V_25 -> V_75 ) {
if ( V_25 -> V_75 -> V_60 == V_76 ) {
V_61 = V_25 -> V_75 -> V_77 ;
V_62 = V_25 -> V_78 ;
break;
}
V_25 = V_25 -> V_75 ;
}
}
V_16 = F_27 ( & V_8 -> V_7 ,
0 ,
F_28 ( V_28 -> V_32 ) ,
F_29 ( V_28 -> V_32 ) ,
V_60 ,
F_30 ( V_56 -> V_79 . V_80 ) & 0x7ff ,
V_58 ,
F_31 ( V_28 -> V_32 ) ? V_81 : V_82 ,
V_28 -> V_83 ,
( F_30 ( V_56 -> V_79 . V_80 ) >> 11 ) & 0x3 ,
V_61 ,
V_62 ) ;
if ( V_16 < 0 ) {
F_8 ( & V_8 -> V_10 , V_9 ) ;
F_23 ( V_25 , L_6 ) ;
return - V_84 ;
}
V_56 -> V_30 = ( void * ) ( 0x10000L + V_16 ) ;
} else {
V_16 = 0xffff & ( long ) V_56 -> V_30 ;
}
switch ( F_22 ( V_28 -> V_32 ) ) {
case V_33 :
F_23 ( V_25 , L_7 ,
F_28 ( V_28 -> V_32 ) , F_29 ( V_28 -> V_32 ) ) ;
V_36 = F_32 ( V_28 -> V_38 *
sizeof( struct V_35 ) ,
V_85 ) ;
if ( V_36 ) {
int V_34 ;
for ( V_34 = 0 ; V_34 < V_28 -> V_38 ; V_34 ++ ) {
V_36 [ V_34 ] . V_86 = V_28 -> V_40 [ V_34 ] . V_86 ;
V_36 [ V_34 ] . V_41 = V_28 -> V_40 [ V_34 ] . V_41 ;
V_36 [ V_34 ] . V_15 = V_49 ;
}
V_28 -> V_37 = ( char * ) V_36 ;
V_17 = F_33 ( & V_8 -> V_7 , V_16 ,
V_28 -> V_87 ,
0 ,
V_28 -> V_38 ,
V_36 ,
V_28 -> V_88 ,
V_28 -> V_89 ,
F_18 ,
V_28 ) ;
if ( V_17 < 0 ) {
V_28 -> V_37 = NULL ;
F_24 ( V_36 ) ;
}
}
break;
case V_64 :
F_23 ( V_25 , L_8 ,
F_28 ( V_28 -> V_32 ) , F_29 ( V_28 -> V_32 ) ) ;
V_17 = F_34 ( & V_8 -> V_7 , V_16 ,
V_28 -> V_88 ,
V_28 -> V_89 ,
F_18 ,
V_28 ) ;
break;
case V_66 :
F_23 ( V_25 , L_9 ,
F_28 ( V_28 -> V_32 ) , F_29 ( V_28 -> V_32 ) ) ;
V_17 = F_35 ( & V_8 -> V_7 , V_16 ,
V_28 -> V_90 ,
V_28 -> V_88 ,
V_28 -> V_89 ,
F_18 ,
V_28 ) ;
break;
case V_91 :
F_23 ( V_25 , L_10 ,
F_28 ( V_28 -> V_32 ) , F_29 ( V_28 -> V_32 ) ) ;
V_17 = F_36 ( & V_8 -> V_7 , V_16 ,
V_28 -> V_88 ,
V_28 -> V_89 ,
F_18 ,
V_28 ) ;
break;
}
if ( V_17 < 0 ) {
F_8 ( & V_8 -> V_10 , V_9 ) ;
F_23 ( V_25 , L_11 ) ;
return - V_84 ;
}
V_28 -> V_30 = ( void * ) ( long ) ( ( ( V_17 & 0xffff ) << 16 ) | V_16 ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
return 0 ;
}
static void F_37 ( unsigned long V_92 )
{
unsigned long V_9 ;
struct V_1 * V_8 = (struct V_1 * ) V_92 ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
while ( ! F_19 ( & V_8 -> V_93 ) ) {
int V_16 ;
int V_17 ;
struct V_28 * V_28 = F_3 ( V_8 -> V_93 . V_94 , struct V_28 , V_31 ) ;
F_20 ( & V_28 -> V_31 ) ;
F_21 ( & V_28 -> V_31 ) ;
V_16 = 0xffff & ( long ) V_28 -> V_30 ;
V_17 = ( ( long ) V_28 -> V_30 ) >> 16 ;
F_38 ( & V_8 -> V_7 , V_16 , V_17 ) ;
}
F_8 ( & V_8 -> V_10 , V_9 ) ;
}
static int F_39 ( struct V_2 * V_3 , struct V_28 * V_28 , int V_15 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long V_9 ;
if ( ! V_28 -> V_25 )
return - V_95 ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
V_28 -> V_15 = V_15 ;
F_40 ( & V_28 -> V_31 , & V_8 -> V_93 ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
F_41 ( & V_8 -> V_96 ) ;
return 0 ;
}
static void F_42 ( struct V_2 * V_3 , struct V_55 * V_56 )
{
struct V_24 * V_25 = V_3 -> V_26 . V_27 ;
if ( V_56 -> V_30 ) {
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_16 = 0xffff & ( long ) V_56 -> V_30 ;
unsigned long V_9 ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
F_43 ( & V_8 -> V_7 , V_16 ) ;
if ( F_44 ( & V_8 -> V_7 , V_16 ) )
F_23 ( V_25 , L_12 , V_16 ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
V_56 -> V_30 = NULL ;
}
}
static int F_45 ( struct V_2 * V_3 , char * V_97 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_98 V_99 ;
unsigned long V_9 ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
V_99 = F_46 ( & V_8 -> V_7 ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
V_97 [ 0 ] = 0 ;
V_97 [ 0 ] = V_99 . V_100 << 1 ;
return ( V_97 [ 0 ] != 0 ) ;
}
static int F_47 ( struct V_2 * V_3 , T_3 V_101 , T_3 V_102 , T_3 V_103 , char * V_97 , T_3 V_104 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_24 * V_25 = V_3 -> V_26 . V_27 ;
struct V_98 V_105 ;
int V_99 ;
struct V_106 * V_79 ;
unsigned long V_9 ;
switch ( V_101 ) {
case V_107 :
F_23 ( V_25 , L_13 ) ;
switch ( V_102 ) {
case V_108 :
case V_109 :
break;
default:
return - V_95 ;
}
break;
case V_110 :
F_23 ( V_25 , L_14 ) ;
if ( V_103 != 1 ) {
F_23 ( V_25 , L_15 ) ;
return - V_95 ;
}
switch ( V_102 ) {
case V_111 :
F_23 ( V_25 , L_16 ) ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
F_48 ( & V_8 -> V_7 ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
break;
case V_112 :
F_23 ( V_25 , L_17 ) ;
break;
case V_113 :
F_23 ( V_25 , L_18 ) ;
break;
case V_114 :
F_23 ( V_25 , L_19 ) ;
break;
case V_115 :
F_23 ( V_25 , L_20 ) ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
F_49 ( & V_8 -> V_7 , F_46 ( & V_8 -> V_7 ) ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
break;
case V_116 :
F_23 ( V_25 , L_21 ) ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
F_49 ( & V_8 -> V_7 , F_46 ( & V_8 -> V_7 ) ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
break;
case V_117 :
F_23 ( V_25 , L_22 ) ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
F_49 ( & V_8 -> V_7 , F_46 ( & V_8 -> V_7 ) ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
break;
case V_118 :
F_23 ( V_25 , L_23 ) ;
break;
case V_119 :
F_23 ( V_25 , L_24 ) ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
F_49 ( & V_8 -> V_7 , F_46 ( & V_8 -> V_7 ) ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
break;
default:
F_23 ( V_25 , L_25 ) ;
return - V_95 ;
}
break;
case V_120 :
F_23 ( V_25 , L_26 ) ;
V_79 = (struct V_106 * ) V_97 ;
V_79 -> V_121 = 9 ;
V_79 -> V_122 = 0x29 ;
V_79 -> V_123 = 1 ;
V_79 -> V_124 = 0x08 ;
V_79 -> V_125 = 1 ;
V_79 -> V_126 = 0 ;
V_79 -> V_127 . V_128 . V_129 [ 0 ] = 0 ;
V_79 -> V_127 . V_128 . V_129 [ 1 ] = 0xff ;
break;
case V_130 :
F_23 ( V_25 , L_27 ) ;
* ( V_131 * ) V_97 = 0 ;
break;
case V_132 :
F_23 ( V_25 , L_28 ) ;
if ( V_103 != 1 ) {
F_23 ( V_25 , L_15 ) ;
return - V_95 ;
}
F_6 ( & V_8 -> V_10 , V_9 ) ;
V_105 = F_46 ( & V_8 -> V_7 ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
V_99 = 0 ;
if ( V_105 . V_100 ) {
V_99 |= ( 1 << V_115 ) ;
F_23 ( V_25 , L_20 ) ;
}
if ( V_105 . V_133 ) {
V_99 |= ( 1 << V_117 ) ;
F_23 ( V_25 , L_22 ) ;
}
if ( V_105 . V_134 ) {
V_99 |= ( 1 << V_135 ) ;
F_23 ( V_25 , L_29 ) ;
}
if ( V_105 . V_133 ) {
V_99 |= ( 1 << V_111 ) ;
F_23 ( V_25 , L_16 ) ;
}
if ( V_105 . V_136 ) {
V_99 |= ( 1 << V_137 ) ;
F_23 ( V_25 , L_30 ) ;
}
if ( V_105 . V_138 ) {
V_99 |= ( 1 << V_113 ) ;
F_23 ( V_25 , L_18 ) ;
}
if ( V_105 . V_139 == V_73 ) {
V_99 |= V_140 ;
F_23 ( V_25 , L_31 ) ;
} else if ( V_105 . V_139 == V_70 ) {
V_99 |= ( 1 << V_141 ) ;
F_23 ( V_25 , L_32 ) ;
}
* ( ( V_131 * ) V_97 ) = F_50 ( V_99 ) ;
break;
case V_142 :
F_23 ( V_25 , L_33 ) ;
break;
case V_143 :
F_23 ( V_25 , L_34 ) ;
if ( V_103 != 1 ) {
F_23 ( V_25 , L_15 ) ;
return - V_95 ;
}
switch ( V_102 ) {
case V_112 :
F_23 ( V_25 , L_17 ) ;
return - V_95 ;
case V_113 :
F_23 ( V_25 , L_18 ) ;
return - V_95 ;
case V_144 :
F_23 ( V_25 , L_35 ) ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
F_48 ( & V_8 -> V_7 ) ;
if ( F_51 ( & V_8 -> V_7 ) )
F_23 ( V_25 , L_36 ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
return 0 ;
case V_114 :
F_23 ( V_25 , L_19 ) ;
break;
default:
F_23 ( V_25 , L_25 ) ;
return - V_95 ;
}
break;
default:
F_23 ( V_25 , L_37 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_52 ( struct V_24 * V_25 )
{
int V_15 ;
int V_145 = F_53 ( V_25 ) -> V_146 ;
int V_147 = F_54 ( F_53 ( V_25 ) , 0 ) ;
struct V_1 * V_8 ;
struct V_2 * V_3 ;
unsigned long V_9 ;
V_25 -> V_148 = ~ 0 ;
V_25 -> V_149 = & V_25 -> V_148 ;
V_3 = F_55 ( & V_150 , V_25 , F_56 ( V_25 ) ) ;
if ( ! V_3 ) {
F_23 ( V_25 , L_38 ) ;
return - 1 ;
}
V_3 -> V_151 = 1 ;
V_8 = (struct V_1 * ) V_3 -> V_4 ;
F_57 ( & V_8 -> V_10 ) ;
F_58 ( & V_8 -> V_96 , F_37 , ( unsigned long ) V_8 ) ;
F_21 ( & V_8 -> V_93 ) ;
V_15 = F_59 ( & V_8 -> V_7 , V_145 , V_152 ) ;
if ( V_15 ) {
F_23 ( V_25 , L_39 , V_15 ) ;
F_24 ( V_3 ) ;
return - 1 ;
}
F_60 ( 10 ) ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
F_7 ( & V_8 -> V_7 ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
V_15 = F_61 ( V_3 , V_147 , V_153 ) ;
if ( V_15 ) {
F_23 ( V_25 , L_40 , V_15 ) ;
F_24 ( V_3 ) ;
return - 1 ;
}
F_23 ( V_25 , L_41 , V_145 , V_147 ) ;
return 0 ;
}
static int F_62 ( struct V_24 * V_25 )
{
int V_15 ;
struct V_2 * V_3 = F_63 ( V_25 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long V_9 ;
F_64 ( V_3 ) ;
F_65 ( & V_8 -> V_96 ) ;
F_6 ( & V_8 -> V_10 , V_9 ) ;
V_15 = F_66 ( & V_8 -> V_7 ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
if ( V_15 )
F_23 ( V_25 , L_42 , V_15 ) ;
F_24 ( V_3 ) ;
return 0 ;
}
static int T_4 F_67 ( void )
{
int V_154 = F_68 () ;
int V_24 ;
if ( F_69 () || V_154 == 0 )
return - V_155 ;
if ( F_70 ( & V_156 ) )
return - V_84 ;
V_157 = 1 ;
if ( F_71 ( V_158 ) || F_71 ( V_159 ) ) {
union V_160 V_161 ;
V_161 . V_162 = 0 ;
V_161 . V_163 . V_164 = 1 ;
V_161 . V_163 . V_165 = 400 ;
F_72 ( V_166 , V_161 . V_162 ) ;
}
for ( V_24 = 0 ; V_24 < V_154 ; V_24 ++ ) {
struct V_167 V_168 ;
struct V_169 * V_170 ;
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
V_168 . V_171 = ( V_24 == 0 ) ? V_172 : V_173 ;
V_168 . V_174 = V_168 . V_171 ;
V_168 . V_9 = V_175 ;
V_170 = F_73 ( ( char * ) V_156 . V_176 , V_24 , & V_168 , 1 ) ;
if ( F_74 ( V_170 ) ) {
F_75 ( & V_156 ) ;
V_157 = 0 ;
return F_76 ( V_170 ) ;
}
if ( V_24 < V_177 )
V_178 [ V_24 ] = V_170 ;
}
return 0 ;
}
static void T_5 F_77 ( void )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_177 ; V_34 ++ )
if ( V_178 [ V_34 ] ) {
F_78 ( V_178 [ V_34 ] ) ;
V_178 [ V_34 ] = NULL ;
}
if ( V_157 )
F_75 ( & V_156 ) ;
}
