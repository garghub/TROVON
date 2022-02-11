static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_7 ) {
V_2 -> V_4 -> V_8 = V_9 ;
F_2 ( & V_2 -> V_4 -> V_5 . V_10 ) ;
}
F_3 ( V_2 -> V_4 ) ;
while ( V_2 -> V_4 -> V_11 ) {
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_1 ) ;
F_5 ( 100 ) ;
}
F_6 ( V_2 -> V_15 ) ;
for ( V_3 = 0 ; V_3 < V_16 ; V_3 ++ ) {
if ( V_2 -> V_17 [ V_3 ] . V_18 != NULL ) {
F_6 ( V_2 -> V_17 [ V_3 ] . V_18 ) ;
V_2 -> V_17 [ V_3 ] . V_18 = NULL ;
}
}
for ( V_3 = 0 ; V_3 < V_19 ; V_3 ++ ) {
if ( V_2 -> V_20 [ V_3 ] . V_18 != NULL ) {
F_7 ( V_2 -> V_20 [ V_3 ] . V_18 -> V_21 ) ;
F_6 ( V_2 -> V_20 [ V_3 ] . V_18 ) ;
V_2 -> V_20 [ V_3 ] . V_18 = NULL ;
}
}
F_8 ( V_2 -> V_4 ) ;
}
static void F_9 ( struct V_22 * V_23 )
{
unsigned long V_24 = 0 ;
int V_25 ;
V_24 = F_10 ( V_26 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x128 , 4 , TRUE ) ;
V_24 = F_10 ( V_28 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x12C , 4 , TRUE ) ;
V_24 = F_10 ( V_29 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x132 , 4 , TRUE ) ;
if ( ( (struct V_1 * ) ( V_23 -> V_30 ) ) -> V_31 == TRUE ) {
V_24 = F_10 ( V_32 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x136 , 4 , TRUE ) ;
} else {
V_24 = F_10 ( V_33 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x136 , 4 , TRUE ) ;
}
V_24 = F_10 ( V_34 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x13C , 4 , TRUE ) ;
V_24 = F_10 ( V_35 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x140 , 4 , TRUE ) ;
V_25 = F_12 ( V_23 , 0x0F0110F8 , ( V_36 * ) & V_24 , sizeof( V_36 ) ) ;
if ( V_25 < 0 ) {
F_4 ( V_23 , V_12 , V_13 , V_14 ,
L_2 ) ;
return;
}
V_24 |= 0x6 ;
V_24 = F_10 ( V_24 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x1CC , 4 , TRUE ) ;
V_24 = F_10 ( V_37 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x1C8 , 4 , TRUE ) ;
V_24 = F_10 ( V_38 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x1D2 , 4 , TRUE ) ;
V_24 = F_10 ( V_39 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x1D6 , 4 , TRUE ) ;
F_13 ( V_23 , 0x1FC , ( V_40 ) & V_24 ) ;
V_24 &= 0x0101FFFF ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x1FC , 4 , TRUE ) ;
F_13 ( V_23 , 0xA8 , ( V_40 ) & V_24 ) ;
if ( ( V_24 & 0x00FF0000 ) >> 16 > 0x30 ) {
V_24 = ( V_24 & 0xFF00FFFF ) | ( 0x30 << 16 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0xA8 , 4 , TRUE ) ;
}
F_13 ( V_23 , 0x148 , ( V_40 ) & V_24 ) ;
if ( ( V_24 & 0x00FF0000 ) >> 16 > 0x30 ) {
V_24 = ( V_24 & 0xFF00FFFF ) | ( 0x30 << 16 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x148 , 4 , TRUE ) ;
}
V_24 = 0 ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x122 , 4 , TRUE ) ;
V_24 = 0 ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x1C2 , 4 , TRUE ) ;
}
static int F_14 ( struct V_41 * V_42 , const struct V_43 * V_44 )
{
struct V_45 * V_46 = F_15 ( V_42 ) ;
int V_47 ;
struct V_22 * V_4 ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
V_49 = F_16 ( sizeof( struct V_22 ) , V_50 + 1 ) ;
if ( V_49 == NULL ) {
F_17 ( & V_46 -> V_51 , V_52 L_3 ) ;
return - V_53 ;
}
F_18 ( V_49 , & V_42 -> V_51 ) ;
V_4 = F_19 ( V_49 ) ;
V_4 -> V_51 = V_49 ;
V_4 -> V_54 = F_20 ( V_55 , V_56 ) ;
V_4 -> V_57 . V_58 = V_59 ;
V_4 -> V_57 . type = V_12 ;
V_4 -> V_57 . V_60 [ V_12 ] = 0xff ;
F_21 ( V_4 ) ;
V_47 = F_22 ( V_4 ) ;
if ( V_47 ) {
F_17 ( & V_46 -> V_51 , V_52 L_4 ) ;
F_8 ( V_4 ) ;
return V_47 ;
}
V_2 = F_23 ( sizeof( struct V_1 ) ,
V_61 ) ;
if ( V_2 == NULL ) {
F_8 ( V_4 ) ;
return - V_53 ;
}
V_4 -> V_30 = V_2 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_62 = V_42 ;
F_24 ( V_42 , V_2 ) ;
F_4 ( V_4 , V_12 , V_13 , V_14 ,
L_5 , V_2 ) ;
V_47 = F_25 ( V_2 ) ;
if ( V_47 ) {
if ( - V_63 == V_47 ) {
F_4 ( V_4 , V_12 , V_13 , V_14 ,
L_6 ) ;
return V_64 ;
}
F_4 ( V_4 , V_12 , V_13 , V_14 ,
L_7 ) ;
F_24 ( V_42 , NULL ) ;
V_46 = F_15 ( V_42 ) ;
F_26 ( V_46 ) ;
F_1 ( V_2 ) ;
return V_47 ;
}
if ( V_4 -> V_65 > V_66 ) {
T_1 V_67 = 4 ;
V_47 = F_27 ( V_4 , V_68 , & V_67 , sizeof( V_67 ) ) ;
if ( V_47 )
return V_47 ;
}
if ( V_69 & V_46 -> V_70 -> V_71 . V_72 ) {
if ( V_4 -> V_73 ) {
#ifdef F_28
F_29 ( & V_46 -> V_51 , 0 ) ;
V_42 -> V_74 = 1 ;
F_30 ( V_46 ) ;
F_31 ( & V_42 -> V_51 , 1 ) ;
F_32 ( & V_2 -> V_75 , V_76 ) ;
F_4 ( V_4 , V_12 , V_13 , V_14 ,
L_8 ) ;
#endif
} else {
V_42 -> V_74 = 0 ;
F_33 ( V_46 ) ;
}
}
V_4 -> V_57 . V_60 [ V_12 ] = 0x0 ;
return V_47 ;
}
static void F_34 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_35 ( V_42 ) ;
struct V_22 * V_4 ;
struct V_45 * V_46 = F_15 ( V_42 ) ;
if ( V_2 == NULL )
return;
V_4 = V_2 -> V_4 ;
F_36 ( V_4 -> V_51 ) ;
if ( V_4 -> V_73 )
V_42 -> V_74 = 0 ;
V_4 -> V_77 = TRUE ;
F_24 ( V_42 , NULL ) ;
F_1 ( V_2 ) ;
F_26 ( V_46 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
for ( V_3 = 0 ; V_3 < V_16 ; V_3 ++ ) {
V_2 -> V_17 [ V_3 ] . V_18 = F_38 ( 0 , V_61 ) ;
if ( V_2 -> V_17 [ V_3 ] . V_18 == NULL ) {
F_4 ( V_2 -> V_4 , V_78 , 0 , 0 ,
L_9 , V_3 ) ;
return - V_53 ;
}
}
for ( V_3 = 0 ; V_3 < V_19 ; V_3 ++ ) {
V_2 -> V_20 [ V_3 ] . V_18 = F_38 ( 0 , V_61 ) ;
if ( V_2 -> V_20 [ V_3 ] . V_18 == NULL ) {
F_4 ( V_2 -> V_4 , V_78 , 0 , 0 ,
L_10 , V_3 ) ;
return - V_53 ;
}
V_2 -> V_20 [ V_3 ] . V_18 -> V_21 = F_39 ( V_79 , V_61 ) ;
if ( V_2 -> V_20 [ V_3 ] . V_18 -> V_21 == NULL ) {
F_4 ( V_2 -> V_4 , V_78 , 0 , 0 ,
L_11 , V_3 ) ;
return - V_53 ;
}
V_2 -> V_20 [ V_3 ] . V_18 -> V_80 = V_79 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_81 = 0 ;
T_2 V_82 = V_64 ;
V_82 = F_41 ( V_2 -> V_4 ) ;
if ( V_82 != V_64 ) {
F_42 ( V_52 L_12 ) ;
return V_82 ;
}
if ( TRUE == V_2 -> V_4 -> V_83 ) {
if ( F_43 ( V_2 ) ) {
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_13 ) ;
}
V_2 -> V_4 -> V_84 = false ;
V_81 = F_44 ( V_2 -> V_4 -> V_85 ,
V_2 -> V_4 -> V_84 , 5 * V_86 ) ;
if ( V_81 == 0 )
F_42 ( V_52 L_14 ) ;
if ( F_45 ( V_2 -> V_4 ) < 0 ) {
F_42 ( V_52 L_15 ) ;
return - V_87 ;
}
}
return 0 ;
}
static inline int F_46 ( const struct V_88 * V_89 )
{
return V_89 -> V_90 & V_91 ;
}
static inline int F_47 ( const struct V_88 * V_89 )
{
return V_89 -> V_72 & V_92 ;
}
static inline int F_48 ( const struct V_88 * V_89 )
{
return ( ( V_89 -> V_90 & V_93 ) == V_94 ) ;
}
static inline int F_49 ( const struct V_88 * V_89 )
{
return ( ( V_89 -> V_90 & V_93 ) == V_95 ) ;
}
static inline int F_50 ( const struct V_88 * V_89 )
{
return ( ( V_89 -> V_72 & V_92 ) ==
V_96 ) ;
}
static inline int F_51 ( const struct V_88 * V_89 )
{
return ( ( V_89 -> V_72 & V_92 ) ==
V_97 ) ;
}
static inline int F_52 ( const struct V_88 * V_89 )
{
return ( ( V_89 -> V_72 & V_92 ) ==
V_98 ) ;
}
static inline int F_53 ( const struct V_88 * V_89 )
{
return ( ( V_89 -> V_72 & V_92 ) ==
V_99 ) ;
}
static inline int F_54 ( const struct V_88 * V_89 )
{
return F_50 ( V_89 ) && F_48 ( V_89 ) ;
}
static inline int F_55 ( const struct V_88 * V_89 )
{
return F_50 ( V_89 ) && F_49 ( V_89 ) ;
}
static inline int F_56 ( const struct V_88 * V_89 )
{
return F_52 ( V_89 ) && F_48 ( V_89 ) ;
}
static inline int F_57 ( const struct V_88 * V_89 )
{
return F_52 ( V_89 ) && F_49 ( V_89 ) ;
}
static inline int F_58 ( const struct V_88 * V_89 )
{
return F_53 ( V_89 ) && F_48 ( V_89 ) ;
}
static inline int F_59 ( const struct V_88 * V_89 )
{
return F_53 ( V_89 ) && F_49 ( V_89 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_100 * V_101 ;
struct V_88 * V_102 ;
T_3 V_103 ;
unsigned long V_81 ;
int V_47 = 0 ;
int V_104 = 0 ;
bool V_105 = false ;
T_2 V_106 = 0 ;
int V_25 ;
V_2 -> V_46 = F_60 ( F_15 ( V_2 -> V_62 ) ) ;
V_2 -> V_31 = ( V_2 -> V_46 -> V_107 == V_108 ) ;
V_2 -> V_4 -> V_109 = V_110 ;
V_2 -> V_4 -> V_111 = V_112 ;
V_25 = F_12 ( V_2 -> V_4 , V_113 ,
( V_36 * ) & ( V_2 -> V_4 -> V_65 ) , sizeof( V_36 ) ) ;
if ( V_25 < 0 ) {
V_47 = V_25 ;
F_4 ( V_2 -> V_4 , V_78 , 0 , 0 , L_16 ) ;
return V_47 ;
}
if ( 0xbece3200 == ( V_2 -> V_4 -> V_65 & ~ ( 0xF0 ) ) )
V_2 -> V_4 -> V_65 &= ~ 0xF0 ;
F_61 ( & V_2 -> V_46 -> V_51 , L_17 ,
V_2 -> V_4 -> V_65 ) ;
V_101 = V_2 -> V_62 -> V_114 ;
if ( V_2 -> V_4 -> V_65 == V_115 ) {
F_62 ( V_2 -> V_4 , & V_106 , 0x0 , 4 ) ;
if ( V_106 == V_116 )
V_105 = TRUE ;
F_61 ( & V_2 -> V_46 -> V_51 , L_18 ,
V_2 -> V_62 -> V_117 ) ;
if ( V_105 == TRUE ) {
if ( V_2 -> V_31 )
V_47 = F_63 ( V_2 -> V_46 , V_118 , V_119 ) ;
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_19 ) ;
if ( V_47 || ( V_2 -> V_31 == false ) ) {
V_104 = V_120 ;
V_102 = & V_101 -> V_102 [ V_120 ] . V_71 ;
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_20 ) ;
if ( ( ( V_2 -> V_31 == TRUE ) && ( F_57 ( V_102 ) == false ) )
|| ( ( V_2 -> V_31 == false ) && ( F_55 ( V_102 ) == false ) ) ) {
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_21 ) ;
F_9 ( V_2 -> V_4 ) ;
V_47 = F_64 ( V_2 -> V_46 ) ;
if ( V_47 ) {
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_22 ) ;
return V_47 ;
}
}
if ( ( V_2 -> V_31 == false ) && F_55 ( V_102 ) ) {
T_2 V_121 = F_10 ( V_32 ) ;
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_23 ) ;
F_11 ( V_2 -> V_4 , ( V_27 ) & V_121 , 0x136 , 4 , TRUE ) ;
}
} else {
V_104 = V_122 ;
V_102 = & V_101 -> V_102 [ V_122 ] . V_71 ;
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_24 ) ;
if ( F_57 ( V_102 ) == false ) {
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_25 ) ;
F_9 ( V_2 -> V_4 ) ;
V_47 = F_64 ( V_2 -> V_46 ) ;
if ( V_47 ) {
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_22 ) ;
return V_47 ;
}
}
}
}
}
V_101 = V_2 -> V_62 -> V_114 ;
for ( V_81 = 0 ; V_81 < V_101 -> V_71 . V_123 ; ++ V_81 ) {
V_102 = & V_101 -> V_102 [ V_81 ] . V_71 ;
if ( ! V_2 -> V_124 . V_125 && F_54 ( V_102 ) ) {
V_103 = F_65 ( V_102 -> V_126 ) ;
V_2 -> V_124 . V_127 = V_103 ;
V_2 -> V_124 . V_125 = V_102 -> V_90 ;
V_2 -> V_124 . V_128 =
F_66 ( V_2 -> V_46 ,
V_2 -> V_124 . V_125 ) ;
}
if ( ! V_2 -> V_129 . V_130 && F_55 ( V_102 ) ) {
V_2 -> V_129 . V_130 = V_102 -> V_90 ;
V_2 -> V_129 . V_131 =
F_67 ( V_2 -> V_46 ,
V_2 -> V_129 . V_130 ) ;
}
if ( ! V_2 -> V_132 . V_133 && F_56 ( V_102 ) ) {
V_103 = F_65 ( V_102 -> V_126 ) ;
V_2 -> V_132 . V_134 = V_103 ;
V_2 -> V_132 . V_133 = V_102 -> V_90 ;
V_2 -> V_132 . V_135 = V_102 -> V_136 ;
V_2 -> V_132 . V_137 =
F_39 ( V_103 , V_61 ) ;
if ( ! V_2 -> V_132 . V_137 )
return - V_138 ;
}
if ( ! V_2 -> V_139 . V_140 && F_57 ( V_102 ) ) {
if ( ! V_2 -> V_129 . V_130 &&
( V_2 -> V_4 -> V_65 == V_115 ) && ( V_81 == V_104 ) ) {
V_103 = F_65 ( V_102 -> V_126 ) ;
V_2 -> V_129 . V_141 = V_103 ;
V_2 -> V_129 . V_130 = V_102 -> V_90 ;
V_2 -> V_129 . V_131 = F_68 ( V_2 -> V_46 ,
V_2 -> V_129 . V_130 ) ;
V_2 -> V_129 . V_142 = V_102 -> V_136 ;
} else if ( V_81 == V_143 ) {
V_103 = F_65 ( V_102 -> V_126 ) ;
V_2 -> V_139 . V_144 = V_103 ;
V_2 -> V_139 . V_140 = V_102 -> V_90 ;
V_2 -> V_139 . V_142 = V_102 -> V_136 ;
V_2 -> V_139 . V_145 = F_39 ( V_103 , V_61 ) ;
if ( ! V_2 -> V_139 . V_145 )
return - V_138 ;
}
}
}
F_24 ( V_2 -> V_62 , V_2 ) ;
V_2 -> V_4 -> V_146 = V_147 ;
V_2 -> V_4 -> V_148 =
V_149 ;
V_2 -> V_4 -> V_150 = V_151 ;
V_47 = F_69 ( V_2 ) ;
if ( V_47 ) {
F_4 ( V_2 -> V_4 , V_78 , 0 , 0 ,
L_26 ) ;
return V_47 ;
}
V_47 = F_37 ( V_2 ) ;
if ( V_47 )
return V_47 ;
return F_40 ( V_2 ) ;
}
static int F_70 ( struct V_41 * V_42 , T_4 V_152 )
{
struct V_1 * V_2 = F_35 ( V_42 ) ;
V_2 -> V_153 = TRUE ;
if ( TRUE == V_2 -> V_154 ) {
V_2 -> V_154 = false ;
if ( V_2 -> V_4 -> V_155 == V_156 ) {
V_2 -> V_4 -> V_157 = TRUE ;
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_27 ) ;
} else {
V_2 -> V_4 -> V_158 = TRUE ;
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_28 ) ;
}
}
V_2 -> V_4 -> V_159 = false ;
F_2 ( & V_2 -> V_4 -> V_160 ) ;
return 0 ;
}
static int F_71 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_35 ( V_42 ) ;
F_72 ( 100 ) ;
V_2 -> V_153 = false ;
F_43 ( V_2 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
static T_5 int F_74 ( void )
{
int V_47 ;
F_75 ( L_29 , V_52 , V_161 , V_162 ) ;
F_75 ( L_30 , V_163 ) ;
V_164 = F_76 ( V_165 , V_52 ) ;
if ( F_77 ( V_164 ) ) {
F_42 ( V_52 L_31 ) ;
return F_78 ( V_164 ) ;
}
V_47 = F_79 ( & V_166 ) ;
if ( V_47 < 0 ) {
F_42 ( V_52 L_32 ) ;
F_80 ( V_164 ) ;
return V_47 ;
}
return 0 ;
}
static T_6 void F_81 ( void )
{
F_82 ( & V_166 ) ;
F_80 ( V_164 ) ;
}
