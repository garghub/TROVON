static inline void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 = ( unsigned long ) V_4 ;
V_2 -> V_6 [ 9 ] . V_7 = V_5 ;
V_2 -> V_6 [ 8 ] . V_7 = F_2 ( V_5 ) ;
}
static inline struct V_3 *
F_3 ( const struct V_1 * V_2 )
{
unsigned long V_5 ;
V_5 = V_2 -> V_6 [ 9 ] . V_7 ;
V_5 |= ( ( unsigned long ) V_2 -> V_6 [ 8 ] . V_7 << 16 ) << 16 ;
return (struct V_3 * ) V_5 ;
}
static inline void
F_4 ( struct V_8 * V_9 , T_1 V_10 , T_1 type )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
unsigned long V_13 = 0 ;
if ( ! F_6 () )
F_7 ( & V_12 -> V_14 , V_13 ) ;
if ( V_12 -> V_15 . V_16 != NULL &&
V_12 -> V_17 != V_18 ) {
if ( ! F_6 () )
F_8 ( & V_12 -> V_14 , V_13 ) ;
return;
}
V_12 -> V_15 . V_16 = V_19 ;
if ( ! F_6 () )
F_8 ( & V_12 -> V_14 , V_13 ) ;
V_12 -> V_15 . V_20 = ( unsigned long ) V_9 ;
V_12 -> V_21 = V_22 ;
V_12 -> V_17 = type ;
F_9 ( & V_12 -> V_15 , V_22 + V_10 ) ;
}
static void F_10 ( struct V_23 * V_24 )
{
struct V_8 * V_9 = F_11 ( V_24 ) ;
struct V_11 * V_12 = F_5 ( V_9 ) ;
F_12 ( V_9 ) ;
if ( V_12 -> V_25 ) {
F_13 ( V_12 -> V_23 ,
V_12 -> V_26 , V_12 -> V_25 ,
V_12 -> V_27 ) ;
}
#ifdef F_14
F_15 ( V_24 ) ;
#endif
F_16 ( V_9 ) ;
F_17 ( & V_12 -> V_28 ) ;
}
static void F_18 ( struct V_8 * V_9 )
{
F_19 ( V_9 ) ;
F_20 ( V_9 , V_29 ) ;
F_21 ( V_9 ) ;
F_22 ( V_9 ) ;
}
static void F_23 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
F_24 ( & V_12 -> V_30 ) ;
F_20 ( V_9 , V_31 ) ;
F_25 ( V_32 , V_9 -> V_33 + V_34 ) ;
F_21 ( V_9 ) ;
if ( V_12 -> V_15 . V_16 != NULL ) {
F_24 ( & V_12 -> V_15 ) ;
V_12 -> V_15 . V_16 = NULL ;
}
}
static int F_26 ( struct V_23 * V_24 , T_2 V_35 )
{
struct V_8 * V_9 = F_11 ( V_24 ) ;
if ( F_27 ( V_9 ) )
F_23 ( V_9 ) ;
F_28 ( V_9 ) ;
F_29 ( V_24 ) ;
F_30 ( V_24 ) ;
F_31 ( V_24 , false ) ;
F_32 ( V_24 , V_36 ) ;
return 0 ;
}
static int F_33 ( struct V_23 * V_24 )
{
struct V_8 * V_9 = F_11 ( V_24 ) ;
int V_37 = F_34 ( V_24 ) ;
if ( V_37 )
return V_37 ;
F_35 ( V_24 ) ;
F_36 ( V_24 , V_38 , 0 ) ;
F_37 ( V_9 ) ;
if ( F_27 ( V_9 ) )
F_18 ( V_9 ) ;
return 0 ;
}
static int T_3 F_38 ( void )
{
int V_37 = - V_39 ;
F_39 ( L_1 , V_40 ) ;
F_40 ( V_41 , L_2 ) ;
V_37 = F_41 ( & V_42 ) ;
if ( V_37 != 0 ) {
F_42 ( L_3 ) ;
goto V_43;
}
F_40 ( V_41 , L_4 ) ;
F_43 () ;
F_39 ( L_5 ,
V_44 , V_44 == 1 ? L_6 : L_7 ,
V_45 , V_46 ) ;
if ( V_44 == 0 ) {
V_37 = - V_39 ;
goto V_47;
}
return 0 ;
V_47:
F_44 ( & V_42 ) ;
V_43:
return V_37 ;
}
static int F_45 ( struct V_23 * V_24 ,
const struct V_48 * V_49 )
{
return F_46 ( V_24 , - 1 , - 1 , 0 , V_49 ) ;
}
static int F_46 ( struct V_23 * V_24 , long V_50 , int V_51 , int V_52 ,
const struct V_48 * V_49 )
{
struct V_8 * V_9 ;
struct V_11 * V_12 ;
T_4 V_53 ;
int V_54 , V_37 = - V_39 ;
#ifdef F_14
if ( V_24 ) {
V_37 = F_34 ( V_24 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_47 ( V_24 , V_55 ) ;
if ( V_37 ) {
F_42 ( L_8 ) ;
goto V_56;
}
}
#endif
V_9 = F_48 ( sizeof( struct V_11 ) ) ;
if ( V_9 == NULL ) {
V_37 = - V_57 ;
goto V_58;
}
F_49 ( V_9 , & V_24 -> V_9 ) ;
V_12 = F_5 ( V_9 ) ;
V_12 -> V_23 = V_24 ;
V_12 -> V_9 = V_9 ;
if ( V_24 ) {
T_1 V_59 = 0 ;
V_12 -> V_60 = & V_61 [ V_49 -> V_62 ] ;
V_37 = F_50 ( V_24 , F_51 ( 32 ) ) ;
if ( V_37 ) {
F_42 ( L_9 ) ;
goto V_63;
}
for ( V_54 = 0 ; V_54 <= 5 ; V_54 ++ ) {
if ( F_52 ( V_24 , V_54 ) & V_64 ) {
V_59 = F_53 ( V_24 , V_54 ) ;
F_40 ( V_65 ,
L_10 ,
V_59 ) ;
break;
}
}
if ( ! V_59 ) {
F_42 ( L_11 ) ;
V_37 = - V_66 ;
goto V_63;
}
V_9 -> V_33 = V_59 ;
V_9 -> V_51 = V_24 -> V_51 ;
V_12 -> V_67 = V_24 -> V_68 ;
F_54 ( V_24 ) ;
F_55 ( V_24 , V_9 ) ;
} else {
V_53 = F_56 ( V_50 + V_69 ) ;
if ( V_53 == 0x20F1 ) {
V_12 -> V_60 = & V_61 [ 13 ] ;
V_12 -> V_67 = 23 ;
} else {
V_12 -> V_60 = & V_61 [ 14 ] ;
V_12 -> V_67 = 10 ;
}
V_9 -> V_33 = V_50 ;
V_9 -> V_51 = V_51 ;
}
if ( V_9 -> V_70 ) {
V_12 -> V_71 = V_9 -> V_70 & 0x01 ;
V_12 -> V_72 = ( ( V_9 -> V_70 & 0x06 ) == 0x06 ) ? 0
: ( V_9 -> V_70 & 0x06 ) >> 1 ;
V_12 -> V_73 = ( ( V_9 -> V_70 & 0x18 ) == 0x18 ) ? 0
: ( V_9 -> V_70 & 0x18 ) >> 3 ;
if ( V_12 -> V_73 == 0x1 )
V_12 -> V_73 = V_74 ;
else if ( V_12 -> V_73 == 0x2 )
V_12 -> V_73 = V_75 ;
V_76 = V_12 -> V_76 = V_9 -> V_77 ;
} else {
V_12 -> V_71 = V_71 [ V_78 ] ;
V_12 -> V_73 = V_73 [ V_78 ] ;
V_12 -> V_72 = V_72 [ V_78 ] ;
V_12 -> V_76 = V_76 ;
}
F_57 ( & V_12 -> V_28 , V_79 ) ;
F_58 ( & V_12 -> V_14 ) ;
V_37 = F_59 ( V_9 ) ;
if ( V_37 ) {
F_42 ( L_12 ) ;
goto V_63;
}
V_37 = F_60 ( V_9 ) ;
if ( V_37 ) {
F_42 ( L_13 ) ;
goto V_80;
}
V_44 ++ ;
V_78 ++ ;
if ( V_24 )
V_45 ++ ;
else {
V_12 -> V_81 = V_82 ;
V_82 = V_9 ;
V_46 ++ ;
}
F_61 ( V_9 , L_14 ,
( int ) V_9 -> V_51 ,
( int ) V_9 -> V_33 ,
V_12 -> V_60 -> V_83 ,
V_12 -> V_67 ) ;
return 0 ;
V_80:
F_13 ( V_12 -> V_23 , V_12 -> V_26 , V_12 -> V_25 ,
V_12 -> V_27 ) ;
V_63:
F_16 ( V_9 ) ;
V_58:
#ifdef F_14
if ( V_24 )
F_15 ( V_24 ) ;
#endif
V_56:
if ( V_24 )
F_30 ( V_24 ) ;
return V_37 ;
}
static void F_62 ( void )
{
struct V_8 * V_9 ;
struct V_11 * V_12 ;
while ( V_46 ) {
V_9 = V_82 ;
V_12 = F_5 ( V_9 ) ;
if ( V_12 -> V_25 ) {
F_13 ( V_12 -> V_23 , V_12 -> V_26 ,
V_12 -> V_25 ,
V_12 -> V_27 ) ;
}
F_63 ( V_9 -> V_33 , 0x10 ) ;
F_12 ( V_9 ) ;
V_82 = V_12 -> V_81 ;
F_16 ( V_9 ) ;
V_46 -- ;
}
}
static void T_5 F_64 ( void )
{
F_44 ( & V_42 ) ;
if ( V_46 )
F_62 () ;
}
static void T_3 F_43 ( void )
{
long V_50 ;
int V_37 = - V_39 ;
int V_51 ;
T_4 V_53 ;
if ( ! V_84 ) {
F_40 ( V_41 , L_15 ) ;
return;
}
for ( V_50 = 0x1000 ; V_50 < 0x9000 ; V_50 += 0x1000 ) {
F_40 ( V_41 , L_16 ,
( int ) V_50 + 0xc80 , F_56 ( V_50 + V_85 ) ) ;
F_40 ( V_41 , L_16 ,
( int ) V_50 + 0xc82 , F_56 ( V_50 + V_69 ) ) ;
F_40 ( V_41 ,
L_17 ,
( int ) V_50 ) ;
if ( F_65 ( V_50 , 0x10 , V_55 ) == NULL )
goto V_86;
if ( F_56 ( V_50 + V_85 ) != 0x110E ) {
F_63 ( V_50 , 0x10 ) ;
goto V_86;
}
V_53 = F_56 ( V_50 + V_69 ) ;
if ( V_53 != 0x20F1 && V_53 != 0x40F1 ) {
F_63 ( V_50 , 0x10 ) ;
goto V_86;
}
if ( F_66 ( V_50 + V_87 ) != 0x1 ) {
F_63 ( V_50 , 0x10 ) ;
goto V_88;
}
if ( V_76 == 0x10 )
F_39 ( L_18 ) ;
switch ( F_66 ( V_50 + 0xcc0 ) ) {
case ( 0x10 ) :
V_51 = 5 ;
break;
case ( 0x20 ) :
V_51 = 9 ;
break;
case ( 0x40 ) :
V_51 = 10 ;
break;
case ( 0x80 ) :
V_51 = 11 ;
break;
default:
goto V_86;
}
V_37 = F_46 ( NULL , V_50 , V_51 ,
12 , NULL ) ;
continue;
V_86:
if ( V_76 == 0x10 )
F_39 ( L_19 ) ;
continue;
V_88:
if ( V_76 == 0x10 )
F_39 ( L_20 ) ;
continue;
}
}
static void F_67 ( struct V_8 * V_9 )
{
F_68 ( V_9 -> V_51 ) ;
F_69 ( V_9 -> V_51 , V_9 ) ;
F_70 ( V_9 -> V_51 ) ;
}
static void F_71 ( struct V_8 * V_9 ,
struct V_89 * V_90 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
F_72 ( V_90 -> V_91 , V_92 , sizeof( V_90 -> V_91 ) ) ;
if ( V_12 -> V_23 )
F_72 ( V_90 -> V_93 , F_73 ( V_12 -> V_23 ) ,
sizeof( V_90 -> V_93 ) ) ;
else
F_72 ( V_90 -> V_93 , L_21 , sizeof( V_90 -> V_93 ) ) ;
V_90 -> V_94 = V_95 ;
}
static int F_74 ( struct V_8 * V_9 )
{
return V_95 ;
}
static int F_75 ( struct V_8 * V_9 ,
struct V_96 * V_97 , T_6 * V_20 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_95 ; V_98 ++ )
if ( F_76 ( V_9 , V_98 , & V_20 [ V_98 ] ) )
return - V_66 ;
return 0 ;
}
static int F_59 ( struct V_8 * V_9 )
{
int V_26 ;
int V_99 ;
int V_98 ;
struct V_11 * V_12 ;
V_12 = F_5 ( V_9 ) ;
V_26 = ( V_100 + V_101 )
* ( sizeof( struct V_1 ) ) ;
V_12 -> V_25 = F_77 ( V_12 -> V_23 ,
V_26 ,
& V_12 -> V_27 ) ;
V_12 -> V_26 = V_26 ;
if ( V_12 -> V_25 == NULL ) {
F_42 ( L_22 ,
V_9 -> V_102 ) ;
return - V_57 ;
}
memset ( V_12 -> V_25 , 0 , V_26 ) ;
V_12 -> V_103 = (struct V_1 * )
F_78 ( ( unsigned long ) V_12 -> V_25 , 8 ) ;
V_12 -> V_104 = F_78 ( V_12 -> V_27 , 8 ) ;
V_12 -> V_105 = V_12 -> V_103 + V_100 ;
V_12 -> V_106 =
V_12 -> V_104 + sizeof( struct V_1 ) * V_100 ;
V_99 = 0 ;
for ( V_98 = 0 ; V_98 < V_107 ; V_98 ++ )
V_99 |= F_76 ( V_9 ,
( T_6 ) V_12 -> V_60 -> V_108 + V_98 ,
( T_6 * ) & V_9 -> V_109 [ V_98 ] ) ;
if ( V_99 ) {
F_42 ( L_23 ,
V_9 -> V_102 , V_99 ) ;
}
if ( V_12 -> V_60 -> V_108 == 0xf8 ) {
for ( V_98 = 0 ; V_98 < V_107 ; V_98 += 2 ) {
char V_110 = V_9 -> V_109 [ V_98 ] ;
V_9 -> V_109 [ V_98 ] = V_9 -> V_109 [ V_98 + 1 ] ;
V_9 -> V_109 [ V_98 + 1 ] = V_110 ;
}
}
F_79 ( V_9 ) ;
V_9 -> V_111 = & V_112 ;
V_9 -> V_113 = & V_114 ;
V_9 -> V_115 = V_116 ;
return 0 ;
}
static int F_80 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
int V_99 ;
V_12 -> V_117 = F_81 ( V_9 -> V_33 , V_118 ) ;
V_99 = F_82 ( V_9 -> V_51 , F_69 , V_119 ,
V_9 -> V_102 , V_9 ) ;
if ( V_99 ) {
F_83 ( V_9 , L_24 ,
V_9 -> V_51 ) ;
return V_99 ;
}
F_84 ( & V_12 -> V_15 ) ;
F_84 ( & V_12 -> V_30 ) ;
F_18 ( V_9 ) ;
F_40 ( V_65 , L_25 ,
V_9 -> V_102 , V_12 -> V_117 ) ;
return 0 ;
}
static int F_85 ( struct V_8 * V_9 , struct V_120 * V_121 , int V_122 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
struct V_123 * V_20 = F_86 ( V_121 ) ;
T_1 V_124 = V_12 -> V_124 [ V_12 -> V_125 ] ;
if ( ! V_12 -> V_126 )
return - V_127 ;
switch ( V_122 ) {
case V_128 :
V_20 -> V_129 = V_124 ;
case V_130 :
F_87 ( V_9 , V_20 -> V_129 & 0x1f ,
V_20 -> V_131 & 0x1f , & V_20 -> V_132 ) ;
return 0 ;
case V_133 :
F_88 ( V_9 , V_20 -> V_129 & 0x1f ,
V_20 -> V_131 & 0x1f , V_20 -> V_134 ) ;
return 0 ;
default:
return - V_135 ;
}
}
static void F_89 ( struct V_8 * V_9 )
{
F_40 ( V_65 , L_26 , V_9 -> V_102 ) ;
F_90 ( V_9 ) ;
F_19 ( V_9 ) ;
F_20 ( V_9 , V_29 ) ;
F_21 ( V_9 ) ;
V_9 -> V_136 = V_22 ;
F_22 ( V_9 ) ;
}
static void V_79 ( struct V_137 * V_138 )
{
struct V_11 * V_12 =
F_91 ( V_138 , struct V_11 , V_28 ) ;
F_89 ( V_12 -> V_9 ) ;
}
static T_7 F_92 ( struct V_3 * V_4 , struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_8 V_139 ;
struct V_1 * V_140 ;
unsigned long V_13 ;
unsigned int V_141 ;
if ( ! V_12 -> V_126 ) {
F_40 ( V_142 , L_27 ,
V_9 -> V_102 ) ;
F_93 ( V_4 ) ;
return V_143 ;
}
if ( F_94 ( V_4 , V_144 ) )
return V_143 ;
V_141 = F_95 ( V_4 -> V_145 , ( unsigned int ) V_144 ) ;
V_140 = V_12 -> V_105 + V_12 -> V_146 ;
V_139 =
V_12 -> V_106 + sizeof( struct V_1 ) * V_12 -> V_146 ;
if ( V_140 -> V_147 != V_148 ) {
F_40 ( V_142 ,
L_28 ,
V_9 -> V_102 , V_12 -> V_149 , V_12 -> V_146 ) ;
F_96 ( V_9 ) ;
V_12 -> V_150 ++ ;
return V_151 ;
}
V_140 -> V_152 = 0 ;
V_140 -> V_6 [ 0 ] . V_7 = F_97 ( V_12 -> V_23 ,
V_4 -> V_20 , V_141 ,
V_153 ) ;
F_1 ( V_140 , V_4 ) ;
V_140 -> V_154 = ( T_4 ) V_141 ;
V_140 -> V_6 [ 0 ] . V_155 = V_156 | ( T_1 ) V_141 ;
V_140 -> V_6 [ 1 ] . V_155 = 0 ;
V_140 -> V_6 [ 1 ] . V_7 = 0 ;
F_7 ( & V_12 -> V_14 , V_13 ) ;
V_140 -> V_147 = V_157 ;
if ( ! V_12 -> V_158 ) {
V_12 -> V_158 = 1 ;
F_40 ( V_142 ,
L_29 ,
V_12 -> V_146 ) ;
F_25 ( V_139 , V_9 -> V_33 + V_159 ) ;
F_25 ( V_160 , V_9 -> V_33 + V_34 ) ;
} else {
F_40 ( V_142 ,
L_30 ,
V_12 -> V_146 ) ;
if ( V_12 -> V_146 == 0 ) {
( V_12 -> V_105 + ( V_101 - 1 ) ) -> V_152
= V_139 ;
} else {
( V_12 -> V_105 + ( V_12 -> V_146 - 1 ) ) -> V_152
= V_139 ;
}
}
F_8 ( & V_12 -> V_14 , V_13 ) ;
F_98 ( V_12 -> V_146 , V_101 ) ;
return V_143 ;
}
static T_9 F_69 ( int V_51 , void * V_161 )
{
struct V_8 * V_9 = V_161 ;
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_4 V_162 ;
T_4 type ;
F_99 ( & V_12 -> V_14 ) ;
V_162 = F_56 ( V_9 -> V_33 + V_163 ) ;
type = ( V_162 & V_164 ) >> 2 ;
if ( type ) {
T_1 V_165 ;
T_1 V_166 ;
F_100 ( V_162 , V_9 -> V_33 + V_163 ) ;
V_165 = V_167 [ type ] ( V_9 , V_162 ) ;
if ( V_165 ) {
V_166 = V_168 | V_165 | ( type << 18 ) ;
F_25 ( V_166 , V_9 -> V_33 + V_34 ) ;
}
}
F_101 ( & V_12 -> V_14 ) ;
return F_102 ( type ) ;
}
static int F_103 ( struct V_8 * V_9 )
{
F_23 ( V_9 ) ;
F_104 ( V_9 -> V_51 , V_9 ) ;
F_90 ( V_9 ) ;
F_40 ( V_65 , L_31 , V_9 -> V_102 ) ;
return 0 ;
}
static struct V_169 * F_105 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
int V_98 ;
F_20 ( V_9 , V_31 ) ;
F_40 ( V_170 , L_32 , V_9 -> V_102 ,
V_12 -> V_171 ) ;
F_40 ( V_142 , L_33 , V_9 -> V_102 ,
V_12 -> V_150 ) ;
if ( V_76 & V_65 ) {
F_106 ( V_9 -> V_33 ) ;
F_107 ( V_9 ) ;
}
if ( V_76 & V_172 ) {
for ( V_98 = 0 ; V_98 < V_100 ; V_98 ++ )
F_108 ( V_12 -> V_103 + V_98 , L_34 , V_98 ) ;
for ( V_98 = 0 ; V_98 < V_101 ; V_98 ++ )
F_108 ( V_12 -> V_105 + V_98 , L_35 , V_98 ) ;
}
return & V_9 -> V_173 ;
}
static void F_109 ( struct V_8 * V_9 )
{
struct V_174 * V_175 ;
T_1 V_176 = 0 ;
T_1 V_177 = 0 ;
int V_98 ;
T_1 V_178 ;
T_6 V_110 ;
if ( V_9 -> V_13 & V_179 ) {
V_110 = F_81 ( V_9 -> V_33 , V_180 ) ;
F_110 ( V_9 -> V_33 ,
V_180 , V_110 | V_181 ) ;
} else {
V_110 = F_81 ( V_9 -> V_33 , V_180 ) ;
F_110 ( V_9 -> V_33 ,
V_180 , V_110 & ~ V_181 ) ;
if ( V_9 -> V_13 & V_182 ) {
for ( V_98 = 0 ; V_98 < 3 ; V_98 ++ )
F_111 ( V_9 , V_98 + 1 , NULL ) ;
F_112 ( V_9 -> V_33 , V_183 ,
0xffffffff ) ;
F_112 ( V_9 -> V_33 , V_184 ,
0xffffffff ) ;
} else {
V_98 = 0 ;
F_113 (ha, dev) {
if ( V_98 < 3 ) {
F_111 ( V_9 , V_98 + 1 ,
( char * ) & V_175 -> V_5 ) ;
} else {
V_178 =
F_114 ( ( T_6 * ) & V_175 -> V_5 ) ;
if ( V_178 < 32 )
V_176 |= ( 1 << V_178 ) ;
else
V_177 |= ( 1 << ( V_178 - 32 ) ) ;
}
V_98 ++ ;
}
for ( ; V_98 < 3 ; V_98 ++ )
F_111 ( V_9 , V_98 + 1 , NULL ) ;
F_112 ( V_9 -> V_33 , V_183 , V_176 ) ;
F_112 ( V_9 -> V_33 , V_184 , V_177 ) ;
}
}
}
static T_1 F_115 ( struct V_8 * V_9 , T_4 V_162 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
int V_185 = 0 ;
struct V_1 * V_186 ;
T_8 V_187 ;
T_1 V_165 = 0 ;
T_4 V_188 ;
F_40 ( V_142 ,
L_36 ,
V_12 -> V_149 , V_12 -> V_146 ) ;
V_186 = V_12 -> V_105 + V_12 -> V_149 ;
while ( ( ( V_188 = V_186 -> V_147 ) & V_189 )
&& ( V_165 < 255 ) ) {
struct V_3 * V_4 = F_3 ( V_186 ) ;
V_165 ++ ;
F_116 ( V_12 -> V_23 , V_186 -> V_6 [ 0 ] . V_7 ,
F_95 ( V_4 -> V_145 ,
( unsigned int ) V_144 ) ,
V_153 ) ;
F_93 ( V_4 ) ;
V_186 -> V_6 [ 8 ] . V_7 = 0 ;
V_186 -> V_6 [ 9 ] . V_7 = 0 ;
if ( V_188 & V_190 )
V_185 = 1 ;
V_9 -> V_173 . V_191 += V_186 -> V_154 ;
V_186 -> V_147 = V_148 ;
F_117 ( V_9 ) ;
F_98 ( V_12 -> V_149 , V_101 ) ;
V_186 = V_12 -> V_105 + V_12 -> V_149 ;
}
if ( ! V_165 )
F_61 ( V_9 ,
L_37 ) ;
if ( V_185 ) {
F_40 ( V_142 ,
L_38 ,
V_12 -> V_149 , V_12 -> V_146 ) ;
V_186 = V_12 -> V_105 + V_12 -> V_149 ;
V_187 = V_12 -> V_106
+ sizeof( struct V_1 ) * V_12 -> V_149 ;
if ( ( V_186 -> V_147 & V_157 )
== V_157 ) {
F_25 ( V_187 , V_9 -> V_33 + V_159 ) ;
V_165 |= V_160 ;
} else {
V_12 -> V_158 = 0 ;
}
}
if ( V_12 -> V_60 -> V_13 & V_192 ) {
F_110 ( V_9 -> V_33 ,
V_193 , V_194 | V_195 ) ;
if ( V_12 -> V_15 . V_16 == NULL ) {
V_12 -> V_15 . V_16 = V_19 ;
V_12 -> V_15 . V_20 = ( unsigned long ) V_9 ;
V_12 -> V_15 . V_196 = V_22 + V_197 ;
V_12 -> V_21 = V_22 ;
V_12 -> V_17 = V_18 ;
F_118 ( & V_12 -> V_15 ) ;
} else if ( V_12 -> V_17 == V_18 ) {
V_12 -> V_21 = V_22 ;
}
}
return V_165 ;
}
static T_1 F_119 ( struct V_8 * V_9 , T_4 V_162 )
{
F_20 ( V_9 , V_31 ) ;
return 1 ;
}
static T_1 F_120 ( struct V_8 * V_9 , T_4 V_162 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_1 V_165 = 0 ;
int V_185 = 0 ;
struct V_1 * V_186 ;
struct V_3 * V_4 ;
struct V_1 * V_140 ;
T_4 V_188 ;
T_8 V_187 ;
F_40 ( V_170 , L_39 ,
V_12 -> V_198 , V_12 -> V_199 ) ;
V_186 = V_12 -> V_103 + V_12 -> V_198 ;
V_187 =
V_12 -> V_104 + sizeof( struct V_1 ) * V_12 -> V_198 ;
while ( ( ( V_188 = V_186 -> V_147 ) & V_189 )
&& ( V_165 < 255 ) ) {
T_8 V_200 = V_186 -> V_6 [ 0 ] . V_7 ;
T_1 V_154 = V_186 -> V_154 ;
struct V_3 * V_201 ;
V_165 ++ ;
if ( V_188 & V_190 )
V_185 = 1 ;
V_201 = F_121 ( V_9 ,
V_202 + 5 ) ;
if ( ! V_201 )
goto V_203;
V_4 = F_3 ( V_186 ) ;
F_116 ( V_12 -> V_23 , V_200 ,
V_202 , V_204 ) ;
F_122 ( V_4 , V_154 ) ;
V_9 -> V_173 . V_205 += V_154 ;
V_4 -> V_206 = F_123 ( V_4 , V_9 ) ;
F_124 ( V_4 ) ;
V_186 -> V_6 [ 0 ] . V_7 =
F_97 ( V_12 -> V_23 , V_201 -> V_20 ,
V_202 , V_204 ) ;
F_1 ( V_186 , V_201 ) ;
V_203:
V_186 -> V_152 = 0 ;
V_186 -> V_147 = 0 ;
V_140 = V_12 -> V_103 + V_12 -> V_199 ;
V_140 -> V_152 = V_187 ;
F_98 ( V_12 -> V_198 , V_100 ) ;
F_98 ( V_12 -> V_199 , V_100 ) ;
V_186 = V_12 -> V_103 + V_12 -> V_198 ;
V_187 = V_12 -> V_104
+ sizeof( struct V_1 ) * V_12 -> V_198 ;
}
if ( ! V_165 )
F_61 ( V_9 ,
L_40 ) ;
if ( V_185 ) {
F_40 ( V_170 ,
L_41 ,
V_12 -> V_198 , V_12 -> V_199 ) ;
V_186 = V_12 -> V_103 + V_12 -> V_198 ;
V_187 = V_12 -> V_104
+ sizeof( struct V_1 ) * V_12 -> V_198 ;
F_25 ( V_187 , V_9 -> V_33 + V_159 ) ;
V_165 |= V_160 | V_207 ;
V_12 -> V_171 ++ ;
}
if ( V_12 -> V_60 -> V_13 & V_192 ) {
F_110 ( V_9 -> V_33 ,
V_193 , V_194 | V_195 ) ;
if ( V_12 -> V_15 . V_16 == NULL ) {
V_12 -> V_15 . V_16 = V_19 ;
V_12 -> V_15 . V_20 = ( unsigned long ) V_9 ;
V_12 -> V_15 . V_196 = V_22 + V_197 ;
V_12 -> V_21 = V_22 ;
V_12 -> V_17 = V_18 ;
F_118 ( & V_12 -> V_15 ) ;
} else if ( V_12 -> V_17 == V_18 ) {
V_12 -> V_21 = V_22 ;
}
}
return V_165 ;
}
static T_1 F_125 ( struct V_8 * V_9 , T_4 V_162 )
{
F_61 ( V_9 , L_42 ) ;
return 1 ;
}
static T_1 F_126 ( struct V_8 * V_9 , T_4 V_162 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
struct V_1 * V_186 ;
T_8 V_187 ;
T_1 V_165 = 1 ;
V_162 = 0 ;
if ( V_12 -> V_117 < 0x30 ) {
F_40 ( V_142 ,
L_43 ,
V_12 -> V_149 , V_12 -> V_146 ) ;
V_186 = V_12 -> V_105 + V_12 -> V_149 ;
V_187 = V_12 -> V_106
+ sizeof( struct V_1 ) * V_12 -> V_149 ;
if ( ( V_186 -> V_147 & V_157 )
== V_157 ) {
F_96 ( V_9 ) ;
F_25 ( V_187 , V_9 -> V_33 + V_159 ) ;
V_165 |= V_160 ;
} else {
V_12 -> V_158 = 0 ;
}
}
return V_165 ;
}
static T_1 F_127 ( struct V_8 * V_9 , T_4 V_162 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_1 V_165 ;
T_1 error ;
T_6 V_208 ;
T_1 V_124 ;
T_4 V_209 ;
T_4 V_210 ;
V_165 = 1 ;
if ( V_162 & V_211 ) {
F_96 ( V_9 ) ;
error = F_128 ( V_9 -> V_33 + V_159 ) ;
F_61 ( V_9 , L_44 , error ) ;
F_20 ( V_9 , V_31 ) ;
F_25 ( V_32 , V_9 -> V_33 + V_34 ) ;
F_129 ( & V_12 -> V_28 ) ;
F_22 ( V_9 ) ;
V_165 = 0 ;
} else {
F_40 ( V_65 , L_45 , V_9 -> V_102 ) ;
V_124 = V_12 -> V_124 [ V_12 -> V_125 ] ;
V_208 = F_81 ( V_9 -> V_33 , V_212 ) ;
if ( V_208 ) {
F_110 ( V_9 -> V_33 , V_212 , V_208 ) ;
F_40 ( V_65 , L_46 ,
V_9 -> V_102 , ( unsigned ) V_208 ) ;
}
if ( ( V_208 & V_213 ) && ( V_12 -> V_125 == 0 ) ) {
F_87 ( V_9 , V_124 , V_214 , & V_210 ) ;
F_87 ( V_9 , V_124 , V_215 , & V_209 ) ;
if ( ! ( V_210 & V_216 ) &&
! ( V_209 & V_217 ) ) {
V_209 |= V_217 ;
F_88 ( V_9 , V_124 , V_215 ,
V_209 ) ;
} else if ( ( V_210 & V_216 ) &&
( V_209 & V_217 ) ) {
V_209 &= ~ V_217 ;
F_88 ( V_9 , V_124 , V_215 ,
V_209 ) ;
}
if ( V_76 )
F_107 ( V_9 ) ;
}
}
return V_165 ;
}
static T_1 F_130 ( struct V_8 * V_9 , T_4 V_162 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_8 V_187 ;
T_1 V_165 = 1 ;
if ( V_12 -> V_117 < 0x30 ) {
F_40 ( V_170 ,
L_47 ,
V_12 -> V_198 , V_12 -> V_199 ) ;
V_187 = V_12 -> V_104
+ sizeof( struct V_1 ) * V_12 -> V_198 ;
F_25 ( V_187 , V_9 -> V_33 + V_159 ) ;
V_165 |= V_160 | V_207 ;
V_12 -> V_171 ++ ;
}
return V_165 ;
}
static void V_19 ( unsigned long V_20 )
{
struct V_8 * V_9 = (struct V_8 * ) V_20 ;
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_1 V_218 ;
unsigned long V_13 = 0 ;
V_12 -> V_15 . V_16 = NULL ;
switch ( V_12 -> V_17 ) {
case V_219 :
F_131 ( V_9 ) ;
break;
case V_220 :
F_132 ( V_9 ) ;
break;
case V_221 :
F_133 ( V_9 ) ;
break;
case V_222 :
F_134 ( V_9 ) ;
break;
case V_223 :
F_135 ( V_9 ) ;
break;
case V_224 :
F_136 ( V_9 ) ;
break;
case V_18 :
F_7 ( & V_12 -> V_14 , V_13 ) ;
if ( V_12 -> V_15 . V_16 == NULL ) {
V_218 = V_22 - V_12 -> V_21 ;
if ( V_218 >= V_197 ) {
F_110 ( V_9 -> V_33 ,
V_193 , V_194 ) ;
} else {
V_12 -> V_15 . V_16 = V_19 ;
V_12 -> V_15 . V_196 = V_12 -> V_21
+ V_197 ;
F_8 ( & V_12 -> V_14 , V_13 ) ;
F_118 ( & V_12 -> V_15 ) ;
break;
}
}
F_8 ( & V_12 -> V_14 , V_13 ) ;
break;
default:
break;
}
}
static void F_19 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
int V_98 ;
struct V_1 * V_225 ;
T_8 V_226 ;
struct V_3 * V_4 ;
V_12 -> V_149 = 0 ;
V_12 -> V_146 = 0 ;
for ( V_98 = 0 ; V_98 < V_101 ; V_98 ++ ) {
V_225 = V_12 -> V_105 + V_98 ;
V_225 -> V_147 = V_148 ;
V_225 -> V_6 [ 0 ] . V_7 = 0 ;
V_225 -> V_6 [ 2 ] . V_155 = 0 ;
V_225 -> V_6 [ 2 ] . V_7 = 0 ;
V_225 -> V_6 [ 8 ] . V_7 = 0 ;
V_225 -> V_6 [ 9 ] . V_7 = 0 ;
}
V_12 -> V_198 = 0 ;
V_12 -> V_199 = V_100 - 1 ;
for ( V_98 = 0 ; V_98 < V_100 ; V_98 ++ ) {
V_225 = V_12 -> V_103 + V_98 ;
V_226 = V_12 -> V_104 + sizeof( struct V_1 ) * V_98 ;
V_225 -> V_147 = V_157 ;
V_225 -> V_154 = V_202 ;
V_225 -> V_6 [ 0 ] . V_155 = V_202 | V_156 ;
V_4 = F_121 ( V_9 , V_202 + 5 ) ;
if ( ! V_4 )
break;
V_225 -> V_6 [ 0 ] . V_7 = F_97 ( V_12 -> V_23 ,
V_4 -> V_20 ,
V_202 ,
V_204 ) ;
F_1 ( V_225 , V_4 ) ;
V_225 -> V_6 [ 1 ] . V_155 = 0 ;
V_225 -> V_6 [ 1 ] . V_7 = 0 ;
V_225 -> V_152 = V_226 + sizeof( struct V_1 ) ;
}
while ( V_98 < V_100 ) {
F_1 ( V_12 -> V_103 + V_98 , NULL ) ;
++ V_98 ;
}
V_225 -> V_152 = 0 ;
}
static void F_90 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
int V_98 ;
struct V_1 * V_225 ;
struct V_3 * V_4 ;
for ( V_98 = 0 ; V_98 < V_101 ; V_98 ++ ) {
V_225 = V_12 -> V_105 + V_98 ;
V_4 = F_3 ( V_225 ) ;
if ( V_4 ) {
F_116 (
V_12 -> V_23 ,
V_225 -> V_6 [ 0 ] . V_7 ,
F_95 ( V_4 -> V_145 ,
( unsigned int ) V_144 ) ,
V_153 ) ;
F_93 ( V_4 ) ;
V_225 -> V_6 [ 8 ] . V_7 = 0 ;
V_225 -> V_6 [ 9 ] . V_7 = 0 ;
}
}
for ( V_98 = 0 ; V_98 < V_100 ; V_98 ++ ) {
V_225 = V_12 -> V_103 + V_98 ;
V_4 = F_3 ( V_225 ) ;
if ( V_4 ) {
F_116 ( V_12 -> V_23 ,
V_225 -> V_6 [ 0 ] . V_7 ,
V_202 ,
V_204 ) ;
F_93 ( V_4 ) ;
V_225 -> V_6 [ 8 ] . V_7 = 0 ;
V_225 -> V_6 [ 9 ] . V_7 = 0 ;
}
}
}
static void F_106 ( T_4 V_227 )
{
T_1 V_228 , V_229 ;
int V_98 ;
F_39 ( L_48 ,
V_227 ) ;
F_39 ( L_49 ) ;
for ( V_98 = 0 ; V_98 < 0x4C ; V_98 += 8 ) {
V_228 = F_137 ( V_227 , V_98 ) ;
V_229 = F_137 ( V_227 , V_98 + 0x4 ) ;
F_39 ( L_50 , V_98 , V_228 , V_229 ) ;
}
}
static void F_108 ( struct V_1 * V_225 , char * type , int V_230 )
{
int V_98 ;
F_39 ( L_51 , type , V_230 , V_225 ) ;
F_39 ( L_52 , V_225 -> V_152 ) ;
F_39 ( L_53 , V_225 -> V_147 ) ;
F_39 ( L_54 , V_225 -> V_154 ) ;
for ( V_98 = 0 ; V_98 < 2 ; V_98 ++ ) {
F_39 ( L_55 ,
V_98 , V_225 -> V_6 [ V_98 ] . V_155 , V_225 -> V_6 [ V_98 ] . V_7 ) ;
}
}
static void F_20 ( struct V_8 * V_9 , int V_231 )
{
T_1 V_232 , V_233 ;
T_1 V_234 , V_235 ;
T_1 V_236 , V_237 , V_238 ;
T_1 V_239 , V_240 ;
T_1 V_241 , V_242 , V_243 ;
F_100 ( V_244 , V_9 -> V_33 + V_245 ) ;
V_232 = F_66 ( V_9 -> V_33 + V_246 ) ;
V_232 += F_66 ( V_9 -> V_33 + V_246 + 1 ) << 8 ;
V_232 += F_66 ( V_9 -> V_33 + V_246 + 2 ) << 16 ;
V_233 = F_66 ( V_9 -> V_33 + V_246 + 3 ) ;
F_100 ( V_247 , V_9 -> V_33 + V_245 ) ;
V_234 = F_66 ( V_9 -> V_33 + V_246 ) ;
V_234 += F_66 ( V_9 -> V_33 + V_246 + 1 ) << 8 ;
V_234 += F_66 ( V_9 -> V_33 + V_246 + 2 ) << 16 ;
V_235 = F_66 ( V_9 -> V_33 + V_246 + 3 ) ;
F_100 ( V_248 , V_9 -> V_33 + V_245 ) ;
V_236 = F_66 ( V_9 -> V_33 + V_246 ) ;
V_236 += F_66 ( V_9 -> V_33 + V_246 + 1 ) << 8 ;
V_237 = F_66 ( V_9 -> V_33 + V_246 + 2 ) ;
V_238 = F_66 ( V_9 -> V_33 + V_246 + 3 ) ;
F_100 ( V_249 , V_9 -> V_33 + V_245 ) ;
V_239 = F_66 ( V_9 -> V_33 + V_246 ) ;
V_239 += F_66 ( V_9 -> V_33 + V_246 + 1 ) << 8 ;
V_240 = F_66 ( V_9 -> V_33 + V_246 + 2 ) ;
V_240 += F_66 ( V_9 -> V_33 + V_246 + 3 ) << 8 ;
F_100 ( V_250 , V_9 -> V_33 + V_245 ) ;
V_241 = F_66 ( V_9 -> V_33 + V_246 ) ;
V_242 = F_66 ( V_9 -> V_33 + V_246 + 1 ) ;
V_243 = F_66 ( V_9 -> V_33 + V_246 + 2 ) ;
if ( V_231 ) {
V_9 -> V_173 . V_251 += V_234 ;
V_9 -> V_173 . V_252 += V_235 + V_237 + V_238 ;
V_9 -> V_173 . V_253 += V_232 ;
V_9 -> V_173 . V_254 += V_233 + V_243 ;
V_9 -> V_173 . V_255 += V_239
+ V_240 + V_241 + V_242 ;
V_9 -> V_173 . V_256 += V_235 ;
V_9 -> V_173 . V_257 += V_237 ;
V_9 -> V_173 . V_258 += V_238 ;
V_9 -> V_173 . V_259 += V_233 ;
V_9 -> V_173 . V_260 += V_243 ;
}
}
static void
F_21 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
int V_98 ;
T_1 V_5 ;
T_1 V_20 ;
T_6 V_261 ;
V_12 -> V_262 = false ;
V_12 -> V_126 = 0 ;
F_79 ( V_9 ) ;
V_20 = F_128 ( V_9 -> V_33 + V_34 ) ;
V_20 |= V_32 ;
F_25 ( V_20 , V_9 -> V_33 + V_34 ) ;
F_138 ( 1000 ) ;
V_20 = F_128 ( V_9 -> V_33 + V_34 ) ;
V_20 |= V_263 ;
F_25 ( V_20 , V_9 -> V_33 + V_34 ) ;
for ( V_98 = V_264 ; V_98 <= V_184 ; V_98 += 4 )
F_112 ( V_9 -> V_33 , ( T_4 ) V_98 , 0 ) ;
V_20 = V_265 | V_266 | V_267 ;
F_139 ( V_9 -> V_33 , V_268 , ( T_4 ) V_20 ) ;
F_25 ( V_269 | 0x3f , V_9 -> V_33 + V_34 ) ;
F_25 ( V_270 | 0x9 , V_9 -> V_33 + V_34 ) ;
F_100 ( V_271 , V_9 -> V_33 + V_245 ) ;
V_5 = V_9 -> V_33 + V_246 + V_271 ;
F_140 ( V_272 , V_5 ) ;
if ( V_12 -> V_117 >= 0x30 ) {
V_261 = V_273 | V_274 ;
F_110 ( V_9 -> V_33 , V_275 , V_261 ) ;
}
F_141 ( V_9 ) ;
V_20 = V_265 | V_266 ;
if ( V_12 -> V_60 -> V_13 & V_276 ) {
V_20 |= V_277 ;
if ( V_12 -> V_71 == 1 ) {
F_110 ( V_9 -> V_33 , V_278 , 0x0a ) ;
} else if ( V_12 -> V_72 == V_279 ) {
F_110 ( V_9 -> V_33 , V_278 , 0x00 ) ;
V_12 -> V_262 = true ;
} else {
F_110 ( V_9 -> V_33 , V_278 , 0x08 ) ;
}
}
if ( V_12 -> V_125 == 0 ||
( V_12 -> V_60 -> V_13 & V_280 ) )
V_20 |= V_267 ;
F_139 ( V_9 -> V_33 , V_268 , ( T_4 ) V_20 ) ;
if ( V_12 -> V_60 -> V_13 & V_281 )
F_136 ( V_9 ) ;
else
F_131 ( V_9 ) ;
}
static void
F_136 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_6 V_20 ;
T_1 V_124 ;
T_6 V_282 ;
T_4 V_283 ;
T_4 V_284 ;
T_4 V_209 ;
T_4 V_285 ;
T_4 V_286 , V_287 ;
int V_98 ;
V_124 = V_12 -> V_124 [ V_12 -> V_125 ] ;
V_20 = V_288 | V_289 ;
if ( V_12 -> V_262 )
V_20 |= V_290 ;
F_110 ( V_9 -> V_33 , V_180 , V_20 ) ;
V_20 = V_291 | V_292 ;
if ( V_12 -> V_125 == 0 )
V_20 |= V_293 ;
F_110 ( V_9 -> V_33 , V_294 , V_20 ) ;
F_139 ( V_9 -> V_33 , V_295 , ( ( 1536 ) + 7 ) & ~ 7 ) ;
F_87 ( V_9 , V_124 , V_296 , & V_286 ) ;
F_87 ( V_9 , V_124 , V_297 , & V_287 ) ;
if ( ( V_12 -> V_60 -> V_13 & V_281 ) ||
( V_12 -> V_71 ) ) {
V_283 = V_298 ;
F_61 ( V_9 , L_56 ) ;
} else {
F_87 ( V_9 , V_124 , V_299 , & V_283 ) ;
F_138 ( 1000 ) ;
F_87 ( V_9 , V_124 , V_299 , & V_283 ) ;
if ( V_283 & V_298 ) {
if ( ( V_286 == V_300 ) &&
( V_287 == V_301 ) ) {
F_87 ( V_9 , V_124 , V_302 ,
& V_284 ) ;
F_87 ( V_9 , V_124 , V_303 ,
& V_285 ) ;
F_61 ( V_9 ,
L_57 ,
! ( V_285 & V_304 )
? L_58 : L_59 ,
V_285 & V_305
? 100 : 10 ,
V_285 & V_306
? L_60 : L_61 ) ;
if ( V_285 & V_304 ) {
F_61 ( V_9 , L_62 ) ;
for ( V_98 = 5 ; V_98 < 10 ; V_98 ++ )
if ( V_284 & ( 1 << V_98 ) )
F_142 ( L_63 ,
V_307 [ V_98 - 5 ] ) ;
F_142 ( L_64 ) ;
}
} else
F_61 ( V_9 , L_65 ) ;
V_12 -> V_30 . V_16 = V_308 ;
V_12 -> V_30 . V_20 = ( unsigned long ) V_9 ;
V_12 -> V_30 . V_196 = V_22 + V_309 ;
F_118 ( & V_12 -> V_30 ) ;
}
}
if ( V_12 -> V_125 == 0 ) {
F_87 ( V_9 , V_124 , V_215 , & V_209 ) ;
V_209 |= V_310 ;
F_88 ( V_9 , V_124 , V_215 , V_209 ) ;
V_282 = F_81 ( V_9 -> V_33 , V_271 ) ;
V_282 |= V_311 ;
F_110 ( V_9 -> V_33 , V_271 , V_282 ) ;
}
if ( V_283 & V_298 ) {
F_111 ( V_9 , 0 , V_9 -> V_109 ) ;
V_12 -> V_126 = 1 ;
F_143 ( ( V_312 >> 8 ) , V_9 -> V_33 + V_34 + 1 ) ;
if ( V_76 >= 1 && V_76 != V_41 )
F_143 ( ( V_313 >> 8 ) ,
V_9 -> V_33 + V_34 + 1 ) ;
F_25 ( V_12 -> V_104 , V_9 -> V_33 + V_159 ) ;
F_25 ( V_160 | V_207 , V_9 -> V_33 + V_34 ) ;
F_110 ( V_9 -> V_33 , V_193 , V_194 ) ;
F_144 ( V_9 ) ;
} else {
F_61 ( V_9 , L_66 ) ;
F_4 ( V_9 , ( 10 * V_309 ) , V_224 ) ;
return;
}
F_109 ( V_9 ) ;
}
static void F_111 ( struct V_8 * V_9 , int V_314 , char * V_315 )
{
int V_98 ;
V_314 *= 6 ;
if ( V_315 != NULL ) {
for ( V_98 = 0 ; V_98 < 6 ; V_98 ++ )
F_110 ( V_9 -> V_33 ,
V_264 + V_314 + V_98 , V_315 [ V_98 ] ) ;
} else {
for ( V_98 = 0 ; V_98 < 6 ; V_98 ++ )
F_110 ( V_9 -> V_33 ,
V_264 + V_314 + V_98 , 0 ) ;
}
}
static void F_107 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_4 V_98 , V_228 , V_229 , V_316 , V_317 , V_124 ;
V_124 = V_12 -> V_124 [ V_12 -> V_125 ] ;
if ( V_12 -> V_60 -> V_13 & V_281 ) {
F_61 ( V_9 , L_67 ) ;
} else if ( V_124 <= V_318 ) {
F_61 ( V_9 , L_68 , V_124 ) ;
F_39 ( L_69 ) ;
for ( V_98 = 0 ; V_98 < 0x20 ; V_98 += 4 ) {
F_87 ( V_9 , V_124 , V_98 , & V_228 ) ;
F_87 ( V_9 , V_124 , V_98 + 1 , & V_229 ) ;
F_87 ( V_9 , V_124 , V_98 + 2 , & V_316 ) ;
F_87 ( V_9 , V_124 , V_98 + 3 , & V_317 ) ;
F_39 ( L_70 ,
V_98 , V_228 , V_229 , V_316 , V_317 ) ;
}
} else {
F_61 ( V_9 , L_71 ) ;
}
}
static void F_141 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_4 V_319 ;
T_4 V_320 ;
T_4 V_321 ;
T_1 V_124 ;
if ( V_12 -> V_60 -> V_13 & V_281 ) {
V_12 -> V_125 = 0xffff ;
return;
}
F_87 ( V_9 , V_318 , V_296 , & V_320 ) ;
if ( V_320 != 0xffff )
V_12 -> V_124 [ 0 ] = V_318 ;
else
V_12 -> V_124 [ 0 ] = V_322 ;
V_12 -> V_124 [ 1 ] = V_322 ;
for ( V_124 = 0 ; V_124 <= V_318 ; V_124 ++ ) {
F_87 ( V_9 , V_124 , V_323 , & V_319 ) ;
F_87 ( V_9 , V_124 , V_296 , & V_320 ) ;
F_87 ( V_9 , V_124 , V_297 , & V_321 ) ;
if ( ( V_319 != 0xffff ) ||
( V_320 != 0xffff ) || ( V_321 != 0xffff ) ) {
F_40 ( V_65 ,
L_72 ,
V_124 , V_319 , V_320 , V_321 ) ;
if ( ( V_12 -> V_124 [ 1 ] == V_322 ) &&
( V_124 != V_318 ) ) {
V_12 -> V_124 [ 1 ] = V_124 ;
}
}
}
if ( V_12 -> V_124 [ 1 ] != V_322 )
V_12 -> V_125 = 1 ;
else if ( V_12 -> V_124 [ 0 ] != V_322 )
V_12 -> V_125 = 0 ;
else
F_61 ( V_9 , L_73 ) ;
}
static void F_131 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_4 V_324 ;
F_40 ( V_65 , L_74 , V_9 -> V_102 ) ;
V_324 = V_325 | V_326 | V_327 ;
F_145 ( V_9 -> V_33 ) ;
F_88 ( V_9 , V_12 -> V_124 [ V_12 -> V_125 ] , V_323 , V_324 ) ;
if ( ( V_12 -> V_125 == 0 ) && ( V_12 -> V_124 [ 1 ] != V_322 ) ) {
if ( V_12 -> V_60 -> V_13 & V_280 )
V_324 = V_327 ;
F_145 ( V_9 -> V_33 ) ;
F_88 ( V_9 , V_12 -> V_124 [ 1 ] , V_323 , V_324 ) ;
}
F_4 ( V_9 , F_146 ( 50 ) , V_220 ) ;
}
static void F_132 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_4 V_324 ;
F_40 ( V_65 , L_75 , V_9 -> V_102 ) ;
F_145 ( V_9 -> V_33 ) ;
V_324 = V_326 ;
F_88 ( V_9 , V_12 -> V_124 [ V_12 -> V_125 ] , V_323 , V_324 ) ;
F_145 ( V_9 -> V_33 ) ;
F_4 ( V_9 , F_146 ( 500 ) , V_221 ) ;
}
static void F_133 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_4 V_124 ;
T_4 V_324 ;
unsigned long V_328 = V_22 + V_309 ;
V_124 = V_12 -> V_124 [ V_12 -> V_125 ] ;
F_40 ( V_65 , L_76 , V_9 -> V_102 ) ;
F_145 ( V_9 -> V_33 ) ;
V_324 = V_326 | V_329 ;
F_88 ( V_9 , V_124 , V_323 , V_324 ) ;
do {
F_87 ( V_9 , V_124 , V_323 , & V_324 ) ;
if ( F_147 ( V_22 , V_328 ) ) {
F_83 ( V_9 , L_77 ) ;
return;
}
} while ( V_324 & V_329 );
F_4 ( V_9 , F_146 ( 50 ) , V_222 ) ;
}
static void F_134 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_4 V_330 ;
T_4 V_319 ;
T_4 V_20 ;
T_4 V_124 ;
T_4 V_283 ;
T_4 V_331 ;
V_124 = V_12 -> V_124 [ V_12 -> V_125 ] ;
F_40 ( V_65 , L_78 , V_9 -> V_102 ) ;
F_87 ( V_9 , V_124 , V_299 , & V_283 ) ;
F_87 ( V_9 , V_124 , V_299 , & V_330 ) ;
if ( ( V_283 & V_332 ) &&
( ! V_12 -> V_71 ) ) {
V_330 = V_283 >> 11 ;
if ( V_12 -> V_73 == V_74 &&
V_12 -> V_72 == V_333 ) {
F_88 ( V_9 , V_124 , V_323 , 0x0000 ) ;
} else if ( V_12 -> V_73 == V_74 &&
V_12 -> V_72 == V_279 ) {
V_12 -> V_262 = true ;
F_88 ( V_9 , V_124 , V_323 , 0x0100 ) ;
} else if ( V_12 -> V_73 == V_75 &&
V_12 -> V_72 == V_333 ) {
F_88 ( V_9 , V_124 , V_323 , 0x2000 ) ;
} else if ( V_12 -> V_73 == V_75 &&
V_12 -> V_72 == V_279 ) {
V_12 -> V_262 = true ;
F_88 ( V_9 , V_124 , V_323 , 0x2100 ) ;
} else {
F_88 ( V_9 , V_124 , V_334 ,
( V_330 << 5 ) | 1 ) ;
F_88 ( V_9 , V_124 , V_323 , 0x1000 ) ;
F_88 ( V_9 , V_124 , V_323 , 0x1200 ) ;
F_61 ( V_9 , L_79 ) ;
F_4 ( V_9 , ( 2 * V_309 ) , V_223 ) ;
return;
}
}
if ( ( V_12 -> V_71 ) && ( V_12 -> V_125 != 0 ) ) {
V_12 -> V_125 = 0 ;
V_20 = V_265 | V_266
| V_267 ;
F_139 ( V_9 -> V_33 , V_268 , V_20 ) ;
F_4 ( V_9 , F_146 ( 40 ) , V_219 ) ;
return;
} else if ( V_12 -> V_125 == 0 ) {
V_319 = 0 ;
F_87 ( V_9 , V_124 , V_215 , & V_331 ) ;
if ( V_12 -> V_71 ) {
V_331 |= V_335 ;
} else {
V_331 &= ~ V_335 ;
if ( V_12 -> V_72 == V_279 ) {
V_319 |= V_336 ;
V_12 -> V_262 = true ;
}
if ( V_12 -> V_73 == V_75 )
V_319 |= V_337 ;
}
F_88 ( V_9 , V_124 , V_323 , V_319 ) ;
F_88 ( V_9 , V_124 , V_215 , V_331 ) ;
}
F_4 ( V_9 , ( 4 * V_309 ) , V_224 ) ;
}
static void F_135 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_4 V_338 ;
T_4 V_339 ;
T_4 V_340 ;
T_4 V_124 ;
T_4 V_283 ;
V_124 = V_12 -> V_124 [ V_12 -> V_125 ] ;
F_87 ( V_9 , V_124 , V_299 , & V_283 ) ;
F_138 ( 1000 ) ;
F_87 ( V_9 , V_124 , V_299 , & V_283 ) ;
if ( ! ( V_283 & V_341 ) ) {
F_4 ( V_9 , 2 * V_309 , V_223 ) ;
return;
}
F_61 ( V_9 , L_80 ) ;
F_87 ( V_9 , V_124 , V_334 , & V_338 ) ;
F_87 ( V_9 , V_124 , V_302 , & V_339 ) ;
V_340 = V_338 & V_339 & 0x03E0 ;
if ( V_340 & 0x0100 )
V_12 -> V_262 = true ;
else if ( ! ( V_340 & 0x0080 ) && ( V_340 & 0x0040 ) )
V_12 -> V_262 = true ;
if ( ( ! ( V_340 & 0x0180 ) ) &&
( V_12 -> V_60 -> V_13 & V_280 ) &&
( V_12 -> V_125 != 0 ) ) {
V_12 -> V_125 = 0 ;
F_4 ( V_9 , F_146 ( 400 ) , V_219 ) ;
return;
}
if ( V_12 -> V_125 == 0 ) {
if ( ( V_12 -> V_72 == V_279 ) ||
( V_338 & V_339 & 0x0040 ) ) {
F_88 ( V_9 , V_124 , V_323 ,
V_342 | V_336 ) ;
F_61 ( V_9 , L_81 ) ;
} else {
F_88 ( V_9 , V_124 , V_323 ,
V_342 ) ;
F_61 ( V_9 , L_82 ) ;
}
}
F_4 ( V_9 , F_146 ( 100 ) , V_224 ) ;
}
static void V_308 ( unsigned long V_20 )
{
struct V_8 * V_9 = (struct V_8 * ) V_20 ;
struct V_11 * V_12 = F_5 ( V_9 ) ;
T_4 V_124 ;
T_4 V_343 ;
V_124 = V_12 -> V_124 [ V_12 -> V_125 ] ;
F_87 ( V_9 , V_124 , V_299 , & V_343 ) ;
if ( ! ( V_343 & V_298 ) ) {
if ( F_148 ( V_9 ) ) {
F_149 ( V_344 L_83 ,
V_9 -> V_102 ) ;
F_110 ( V_9 -> V_33 , V_193 , 0 ) ;
F_79 ( V_9 ) ;
if ( V_12 -> V_60 -> V_13 & V_280 ) {
T_4 V_20 = V_325 | V_326 |
V_327 ;
F_145 ( V_9 -> V_33 ) ;
F_88 ( V_9 , V_12 -> V_124 [ 0 ] ,
V_323 , V_20 ) ;
V_12 -> V_125 = 1 ;
F_4 ( V_9 , F_146 ( 400 ) ,
V_219 ) ;
return;
}
}
}
if ( ( V_343 & V_298 ) && ! F_148 ( V_9 ) ) {
F_110 ( V_9 -> V_33 , V_193 , V_194 ) ;
F_149 ( V_344 L_84 ,
V_9 -> V_102 ) ;
F_144 ( V_9 ) ;
}
V_12 -> V_30 . V_196 = V_22 + V_309 ;
F_118 ( & V_12 -> V_30 ) ;
}
static bool
F_87 ( struct V_8 * V_9 , T_4 V_124 , T_4 V_54 , T_4 * V_345 )
{
T_6 V_346 ;
T_4 V_282 , V_110 ;
T_1 V_98 ;
bool V_99 ;
int V_347 ;
struct V_11 * V_12 = F_5 ( V_9 ) ;
unsigned long V_13 = 0 ;
V_99 = false ;
F_100 ( V_271 , V_9 -> V_33 + V_245 ) ;
V_282 = V_9 -> V_33 + V_246 + V_271 ;
if ( ! F_6 () )
F_7 ( & V_12 -> V_14 , V_13 ) ;
F_145 ( V_9 -> V_33 ) ;
V_347 = F_150 ( V_311 , V_282 ) ;
if ( V_347 )
F_151 ( V_311 , V_282 ) ;
F_152 ( V_9 -> V_33 , 0x1 , 2 ) ;
F_152 ( V_9 -> V_33 , 0x2 , 2 ) ;
F_152 ( V_9 -> V_33 , V_124 , 5 ) ;
F_152 ( V_9 -> V_33 , V_54 , 5 ) ;
F_151 ( V_348 , V_282 ) ;
F_151 ( V_349 , V_282 ) ;
F_140 ( V_349 , V_282 ) ;
F_151 ( V_349 , V_282 ) ;
V_346 = F_150 ( V_350 , V_282 ) ;
F_140 ( V_349 , V_282 ) ;
if ( V_346 ) {
for ( V_98 = 0 ; V_98 < 16 ; V_98 ++ ) {
F_151 ( V_349 , V_282 ) ;
F_140 ( V_349 , V_282 ) ;
}
V_110 = 0xffff ;
V_99 = true ;
} else {
for ( V_110 = 0 , V_98 = 0x8000 ; V_98 ; V_98 >>= 1 ) {
F_151 ( V_349 , V_282 ) ;
if ( F_150 ( V_350 , V_282 ) )
V_110 |= V_98 ;
F_140 ( V_349 , V_282 ) ;
}
}
F_151 ( V_349 , V_282 ) ;
F_140 ( V_349 , V_282 ) ;
if ( V_347 )
F_140 ( V_311 , V_282 ) ;
* V_345 = V_110 ;
if ( ! F_6 () )
F_8 ( & V_12 -> V_14 , V_13 ) ;
return V_99 ;
}
static void F_152 ( T_4 V_351 , T_1 V_20 , unsigned V_352 )
{
T_4 V_282 ;
T_1 V_98 ;
if ( V_352 == 0 )
return;
F_100 ( V_271 , V_351 + V_245 ) ;
V_282 = V_351 + V_246 + V_271 ;
F_140 ( V_348 , V_282 ) ;
for ( V_98 = ( 0x1 << ( V_352 - 1 ) ) ; V_98 ; V_98 >>= 1 ) {
F_151 ( V_349 , V_282 ) ;
( void ) F_150 ( V_349 , V_282 ) ;
if ( V_20 & V_98 )
F_140 ( V_350 , V_282 ) ;
else
F_151 ( V_350 , V_282 ) ;
F_140 ( V_349 , V_282 ) ;
( void ) F_150 ( V_349 , V_282 ) ;
}
}
static void F_145 ( T_4 V_351 )
{
int V_98 ;
T_4 V_282 ;
F_100 ( V_271 , V_351 + V_245 ) ;
V_282 = V_351 + V_246 + V_271 ;
F_151 ( V_348 , V_282 ) ;
for ( V_98 = 0 ; V_98 < 32 ; V_98 ++ ) {
F_151 ( V_349 , V_282 ) ;
F_140 ( V_349 , V_282 ) ;
}
}
static void
F_88 ( struct V_8 * V_9 , T_4 V_124 , T_4 V_54 , T_4 V_345 )
{
T_4 V_282 ;
int V_347 ;
unsigned long V_13 = 0 ;
struct V_11 * V_12 = F_5 ( V_9 ) ;
F_100 ( V_271 , V_9 -> V_33 + V_245 ) ;
V_282 = V_9 -> V_33 + V_246 + V_271 ;
if ( ! F_6 () )
F_7 ( & V_12 -> V_14 , V_13 ) ;
F_145 ( V_9 -> V_33 ) ;
V_347 = F_150 ( V_311 , V_282 ) ;
if ( V_347 )
F_151 ( V_311 , V_282 ) ;
F_152 ( V_9 -> V_33 , 0x1 , 2 ) ;
F_152 ( V_9 -> V_33 , 0x1 , 2 ) ;
F_152 ( V_9 -> V_33 , V_124 , 5 ) ;
F_152 ( V_9 -> V_33 , V_54 , 5 ) ;
F_152 ( V_9 -> V_33 , 0x2 , 2 ) ;
F_152 ( V_9 -> V_33 , V_345 , 16 ) ;
F_151 ( V_349 , V_282 ) ;
F_140 ( V_349 , V_282 ) ;
if ( V_347 )
F_140 ( V_311 , V_282 ) ;
if ( ! F_6 () )
F_8 ( & V_12 -> V_14 , V_13 ) ;
}
static void F_153 ( T_4 V_227 )
{
T_4 V_282 ;
F_100 ( V_271 , V_227 + V_245 ) ;
V_282 = V_227 + V_246 + V_271 ;
F_140 ( V_353 , V_282 ) ;
F_140 ( V_354 , V_282 ) ;
F_140 ( V_355 , V_282 ) ;
F_151 ( V_354 , V_282 ) ;
F_151 ( V_353 , V_282 ) ;
}
static int F_154 ( T_4 V_227 , T_6 V_20 , int V_356 )
{
int V_99 ;
T_6 V_357 ;
T_4 V_282 ;
F_100 ( V_271 , V_227 + V_245 ) ;
V_282 = V_227 + V_246 + V_271 ;
for ( V_357 = 0x80 ; V_357 != 0 ; V_357 >>= 1 ) {
if ( V_357 & V_20 )
F_140 ( V_354 , V_282 ) ;
else
F_151 ( V_354 , V_282 ) ;
F_140 ( V_353 , V_282 ) ;
F_151 ( V_353 , V_282 ) ;
}
F_151 ( V_355 , V_282 ) ;
F_140 ( V_353 , V_282 ) ;
V_99 = F_150 ( V_354 , V_282 ) ;
F_151 ( V_353 , V_282 ) ;
F_140 ( V_355 , V_282 ) ;
if ( ( ! V_99 ) && V_356 ) {
F_151 ( V_354 , V_282 ) ;
F_140 ( V_353 , V_282 ) ;
F_140 ( V_354 , V_282 ) ;
}
return V_99 ;
}
static void F_155 ( T_4 V_227 , T_6 * V_20 , int V_356 )
{
T_6 V_357 ;
T_4 V_282 ;
F_100 ( V_271 , V_227 + V_245 ) ;
V_282 = V_227 + V_246 + V_271 ;
* V_20 = 0 ;
F_151 ( V_355 , V_282 ) ;
for ( V_357 = 0x80 ; V_357 ; V_357 >>= 1 ) {
F_140 ( V_353 , V_282 ) ;
if ( F_150 ( V_354 , V_282 ) )
* V_20 |= V_357 ;
F_151 ( V_353 , V_282 ) ;
}
F_140 ( V_355 , V_282 ) ;
if ( ! V_356 ) {
F_151 ( V_354 , V_282 ) ;
F_140 ( V_353 , V_282 ) ;
F_151 ( V_353 , V_282 ) ;
} else {
F_140 ( V_354 , V_282 ) ;
F_140 ( V_353 , V_282 ) ;
F_151 ( V_353 , V_282 ) ;
F_151 ( V_354 , V_282 ) ;
F_140 ( V_353 , V_282 ) ;
F_140 ( V_354 , V_282 ) ;
}
}
static int F_76 ( struct V_8 * V_9 , T_6 V_358 , T_6 * V_20 )
{
int V_99 ;
struct V_11 * V_12 = F_5 ( V_9 ) ;
unsigned long V_13 = 0 ;
int V_359 = 0 ;
F_7 ( & V_12 -> V_14 , V_13 ) ;
F_153 ( V_9 -> V_33 ) ;
V_99 = F_154 ( V_9 -> V_33 , 0xa0 , V_360 ) ;
if ( V_99 ) {
V_359 = 1 ;
goto V_361;
}
V_99 = F_154 ( V_9 -> V_33 , V_358 , V_360 ) ;
if ( V_99 ) {
V_359 = 2 ;
goto V_361;
}
F_153 ( V_9 -> V_33 ) ;
V_99 = F_154 ( V_9 -> V_33 , 0xa1 , V_360 ) ;
if ( V_99 ) {
V_359 = 3 ;
goto V_361;
}
F_155 ( V_9 -> V_33 , V_20 , V_362 ) ;
V_361:
F_8 ( & V_12 -> V_14 , V_13 ) ;
return V_359 ;
}
