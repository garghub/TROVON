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
T_1 V_24 ;
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
V_25 = F_12 ( V_23 , 0x0F0110F8 , & V_24 , sizeof( T_1 ) ) ;
if ( V_25 < 0 ) {
F_4 ( V_23 , V_12 , V_13 , V_14 ,
L_2 ) ;
return;
}
V_24 |= 0x6 ;
V_24 = F_10 ( V_24 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x1CC , 4 , TRUE ) ;
V_24 = F_10 ( V_36 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x1C8 , 4 , TRUE ) ;
V_24 = F_10 ( V_37 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x1D2 , 4 , TRUE ) ;
V_24 = F_10 ( V_38 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x1D6 , 4 , TRUE ) ;
F_13 ( V_23 , 0x1FC , & V_24 ) ;
V_24 &= 0x0101FFFF ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x1FC , 4 , TRUE ) ;
F_13 ( V_23 , 0xA8 , & V_24 ) ;
if ( ( V_24 & 0x00FF0000 ) >> 16 > 0x30 ) {
V_24 = ( V_24 & 0xFF00FFFF ) | ( 0x30 << 16 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0xA8 , 4 , TRUE ) ;
}
F_13 ( V_23 , 0x148 , & V_24 ) ;
if ( ( V_24 & 0x00FF0000 ) >> 16 > 0x30 ) {
V_24 = ( V_24 & 0xFF00FFFF ) | ( 0x30 << 16 ) ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x148 , 4 , TRUE ) ;
}
V_24 = 0 ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x122 , 4 , TRUE ) ;
V_24 = 0 ;
F_11 ( V_23 , ( V_27 ) & V_24 , 0x1C2 , 4 , TRUE ) ;
}
static int F_14 ( struct V_39 * V_40 , const struct V_41 * V_42 )
{
struct V_43 * V_44 = F_15 ( V_40 ) ;
int V_45 ;
struct V_22 * V_4 ;
struct V_1 * V_2 ;
struct V_46 * V_47 ;
V_47 = F_16 ( sizeof( struct V_22 ) , V_48 + 1 ) ;
if ( V_47 == NULL ) {
F_17 ( & V_44 -> V_49 , V_50 L_3 ) ;
return - V_51 ;
}
F_18 ( V_47 , & V_40 -> V_49 ) ;
V_4 = F_19 ( V_47 ) ;
V_4 -> V_49 = V_47 ;
V_4 -> V_52 = F_20 ( V_53 , V_54 ) ;
V_4 -> V_55 . V_56 = V_57 ;
V_4 -> V_55 . type = V_12 ;
V_4 -> V_55 . V_58 [ V_12 ] = 0xff ;
F_21 ( V_4 ) ;
V_45 = F_22 ( V_4 ) ;
if ( V_45 ) {
F_17 ( & V_44 -> V_49 , V_50 L_4 ) ;
F_8 ( V_4 ) ;
return V_45 ;
}
V_2 = F_23 ( sizeof( struct V_1 ) ,
V_59 ) ;
if ( V_2 == NULL ) {
F_8 ( V_4 ) ;
return - V_51 ;
}
V_4 -> V_30 = V_2 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_60 = V_40 ;
F_24 ( V_40 , V_2 ) ;
F_4 ( V_4 , V_12 , V_13 , V_14 ,
L_5 , V_2 ) ;
V_45 = F_25 ( V_2 ) ;
if ( V_45 ) {
if ( - V_61 == V_45 ) {
F_4 ( V_4 , V_12 , V_13 , V_14 ,
L_6 ) ;
return V_62 ;
}
F_4 ( V_4 , V_12 , V_13 , V_14 ,
L_7 ) ;
F_24 ( V_40 , NULL ) ;
V_44 = F_15 ( V_40 ) ;
F_26 ( V_44 ) ;
F_1 ( V_2 ) ;
return V_45 ;
}
if ( V_4 -> V_63 > V_64 ) {
T_2 V_65 = 4 ;
V_45 = F_27 ( V_4 , V_66 , & V_65 , sizeof( V_65 ) ) ;
if ( V_45 )
return V_45 ;
}
if ( V_67 & V_44 -> V_68 -> V_69 . V_70 ) {
if ( V_4 -> V_71 ) {
#ifdef F_28
F_29 ( & V_44 -> V_49 , 0 ) ;
V_40 -> V_72 = 1 ;
F_30 ( V_44 ) ;
F_31 ( & V_40 -> V_49 , 1 ) ;
F_32 ( & V_2 -> V_73 , V_74 ) ;
F_4 ( V_4 , V_12 , V_13 , V_14 ,
L_8 ) ;
#endif
} else {
V_40 -> V_72 = 0 ;
F_33 ( V_44 ) ;
}
}
V_4 -> V_55 . V_58 [ V_12 ] = 0x0 ;
return V_45 ;
}
static void F_34 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
struct V_22 * V_4 ;
struct V_43 * V_44 = F_15 ( V_40 ) ;
if ( V_2 == NULL )
return;
V_4 = V_2 -> V_4 ;
F_36 ( V_4 -> V_49 ) ;
if ( V_4 -> V_71 )
V_40 -> V_72 = 0 ;
V_4 -> V_75 = TRUE ;
F_24 ( V_40 , NULL ) ;
F_1 ( V_2 ) ;
F_26 ( V_44 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
for ( V_3 = 0 ; V_3 < V_16 ; V_3 ++ ) {
V_2 -> V_17 [ V_3 ] . V_18 = F_38 ( 0 , V_59 ) ;
if ( V_2 -> V_17 [ V_3 ] . V_18 == NULL ) {
F_4 ( V_2 -> V_4 , V_76 , 0 , 0 ,
L_9 , V_3 ) ;
return - V_51 ;
}
}
for ( V_3 = 0 ; V_3 < V_19 ; V_3 ++ ) {
V_2 -> V_20 [ V_3 ] . V_18 = F_38 ( 0 , V_59 ) ;
if ( V_2 -> V_20 [ V_3 ] . V_18 == NULL ) {
F_4 ( V_2 -> V_4 , V_76 , 0 , 0 ,
L_10 , V_3 ) ;
return - V_51 ;
}
V_2 -> V_20 [ V_3 ] . V_18 -> V_21 = F_39 ( V_77 , V_59 ) ;
if ( V_2 -> V_20 [ V_3 ] . V_18 -> V_21 == NULL ) {
F_4 ( V_2 -> V_4 , V_76 , 0 , 0 ,
L_11 , V_3 ) ;
return - V_51 ;
}
V_2 -> V_20 [ V_3 ] . V_18 -> V_78 = V_77 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_79 = 0 ;
T_3 V_80 = V_62 ;
V_80 = F_41 ( V_2 -> V_4 ) ;
if ( V_80 != V_62 ) {
F_42 ( V_50 L_12 ) ;
return V_80 ;
}
if ( TRUE == V_2 -> V_4 -> V_81 ) {
if ( F_43 ( V_2 ) ) {
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_13 ) ;
}
V_2 -> V_4 -> V_82 = false ;
V_79 = F_44 ( V_2 -> V_4 -> V_83 ,
V_2 -> V_4 -> V_82 , 5 * V_84 ) ;
if ( V_79 == 0 )
F_42 ( V_50 L_14 ) ;
if ( F_45 ( V_2 -> V_4 ) < 0 ) {
F_42 ( V_50 L_15 ) ;
return - V_85 ;
}
}
return 0 ;
}
static inline int F_46 ( const struct V_86 * V_87 )
{
return V_87 -> V_88 & V_89 ;
}
static inline int F_47 ( const struct V_86 * V_87 )
{
return V_87 -> V_70 & V_90 ;
}
static inline int F_48 ( const struct V_86 * V_87 )
{
return ( ( V_87 -> V_88 & V_91 ) == V_92 ) ;
}
static inline int F_49 ( const struct V_86 * V_87 )
{
return ( ( V_87 -> V_88 & V_91 ) == V_93 ) ;
}
static inline int F_50 ( const struct V_86 * V_87 )
{
return ( ( V_87 -> V_70 & V_90 ) ==
V_94 ) ;
}
static inline int F_51 ( const struct V_86 * V_87 )
{
return ( ( V_87 -> V_70 & V_90 ) ==
V_95 ) ;
}
static inline int F_52 ( const struct V_86 * V_87 )
{
return ( ( V_87 -> V_70 & V_90 ) ==
V_96 ) ;
}
static inline int F_53 ( const struct V_86 * V_87 )
{
return ( ( V_87 -> V_70 & V_90 ) ==
V_97 ) ;
}
static inline int F_54 ( const struct V_86 * V_87 )
{
return F_50 ( V_87 ) && F_48 ( V_87 ) ;
}
static inline int F_55 ( const struct V_86 * V_87 )
{
return F_50 ( V_87 ) && F_49 ( V_87 ) ;
}
static inline int F_56 ( const struct V_86 * V_87 )
{
return F_52 ( V_87 ) && F_48 ( V_87 ) ;
}
static inline int F_57 ( const struct V_86 * V_87 )
{
return F_52 ( V_87 ) && F_49 ( V_87 ) ;
}
static inline int F_58 ( const struct V_86 * V_87 )
{
return F_53 ( V_87 ) && F_48 ( V_87 ) ;
}
static inline int F_59 ( const struct V_86 * V_87 )
{
return F_53 ( V_87 ) && F_49 ( V_87 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
struct V_86 * V_100 ;
T_4 V_101 ;
unsigned long V_79 ;
int V_45 = 0 ;
int V_102 = 0 ;
bool V_103 = false ;
T_3 V_104 = 0 ;
int V_25 ;
V_2 -> V_44 = F_60 ( F_15 ( V_2 -> V_60 ) ) ;
V_2 -> V_31 = ( V_2 -> V_44 -> V_105 == V_106 ) ;
V_2 -> V_4 -> V_107 = V_108 ;
V_2 -> V_4 -> V_109 = V_110 ;
V_25 = F_12 ( V_2 -> V_4 , V_111 ,
( T_1 * ) & ( V_2 -> V_4 -> V_63 ) , sizeof( T_1 ) ) ;
if ( V_25 < 0 ) {
V_45 = V_25 ;
F_4 ( V_2 -> V_4 , V_76 , 0 , 0 , L_16 ) ;
return V_45 ;
}
if ( 0xbece3200 == ( V_2 -> V_4 -> V_63 & ~ ( 0xF0 ) ) )
V_2 -> V_4 -> V_63 &= ~ 0xF0 ;
F_61 ( & V_2 -> V_44 -> V_49 , L_17 ,
V_2 -> V_4 -> V_63 ) ;
V_99 = V_2 -> V_60 -> V_112 ;
if ( V_2 -> V_4 -> V_63 == V_113 ) {
F_62 ( V_2 -> V_4 , & V_104 , 0x0 , 4 ) ;
if ( V_104 == V_114 )
V_103 = TRUE ;
F_61 ( & V_2 -> V_44 -> V_49 , L_18 ,
V_2 -> V_60 -> V_115 ) ;
if ( V_103 == TRUE ) {
if ( V_2 -> V_31 )
V_45 = F_63 ( V_2 -> V_44 , V_116 , V_117 ) ;
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_19 ) ;
if ( V_45 || ( V_2 -> V_31 == false ) ) {
V_102 = V_118 ;
V_100 = & V_99 -> V_100 [ V_118 ] . V_69 ;
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_20 ) ;
if ( ( ( V_2 -> V_31 == TRUE ) && ( F_57 ( V_100 ) == false ) )
|| ( ( V_2 -> V_31 == false ) && ( F_55 ( V_100 ) == false ) ) ) {
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_21 ) ;
F_9 ( V_2 -> V_4 ) ;
V_45 = F_64 ( V_2 -> V_44 ) ;
if ( V_45 ) {
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_22 ) ;
return V_45 ;
}
}
if ( ( V_2 -> V_31 == false ) && F_55 ( V_100 ) ) {
T_3 V_119 = F_10 ( V_32 ) ;
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_23 ) ;
F_11 ( V_2 -> V_4 , ( V_27 ) & V_119 , 0x136 , 4 , TRUE ) ;
}
} else {
V_102 = V_120 ;
V_100 = & V_99 -> V_100 [ V_120 ] . V_69 ;
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_24 ) ;
if ( F_57 ( V_100 ) == false ) {
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_25 ) ;
F_9 ( V_2 -> V_4 ) ;
V_45 = F_64 ( V_2 -> V_44 ) ;
if ( V_45 ) {
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_22 ) ;
return V_45 ;
}
}
}
}
}
V_99 = V_2 -> V_60 -> V_112 ;
for ( V_79 = 0 ; V_79 < V_99 -> V_69 . V_121 ; ++ V_79 ) {
V_100 = & V_99 -> V_100 [ V_79 ] . V_69 ;
if ( ! V_2 -> V_122 . V_123 && F_54 ( V_100 ) ) {
V_101 = F_65 ( V_100 -> V_124 ) ;
V_2 -> V_122 . V_125 = V_101 ;
V_2 -> V_122 . V_123 = V_100 -> V_88 ;
V_2 -> V_122 . V_126 =
F_66 ( V_2 -> V_44 ,
V_2 -> V_122 . V_123 ) ;
}
if ( ! V_2 -> V_127 . V_128 && F_55 ( V_100 ) ) {
V_2 -> V_127 . V_128 = V_100 -> V_88 ;
V_2 -> V_127 . V_129 =
F_67 ( V_2 -> V_44 ,
V_2 -> V_127 . V_128 ) ;
}
if ( ! V_2 -> V_130 . V_131 && F_56 ( V_100 ) ) {
V_101 = F_65 ( V_100 -> V_124 ) ;
V_2 -> V_130 . V_132 = V_101 ;
V_2 -> V_130 . V_131 = V_100 -> V_88 ;
V_2 -> V_130 . V_133 = V_100 -> V_134 ;
V_2 -> V_130 . V_135 =
F_39 ( V_101 , V_59 ) ;
if ( ! V_2 -> V_130 . V_135 )
return - V_136 ;
}
if ( ! V_2 -> V_137 . V_138 && F_57 ( V_100 ) ) {
if ( ! V_2 -> V_127 . V_128 &&
( V_2 -> V_4 -> V_63 == V_113 ) && ( V_79 == V_102 ) ) {
V_101 = F_65 ( V_100 -> V_124 ) ;
V_2 -> V_127 . V_139 = V_101 ;
V_2 -> V_127 . V_128 = V_100 -> V_88 ;
V_2 -> V_127 . V_129 = F_68 ( V_2 -> V_44 ,
V_2 -> V_127 . V_128 ) ;
V_2 -> V_127 . V_140 = V_100 -> V_134 ;
} else if ( V_79 == V_141 ) {
V_101 = F_65 ( V_100 -> V_124 ) ;
V_2 -> V_137 . V_142 = V_101 ;
V_2 -> V_137 . V_138 = V_100 -> V_88 ;
V_2 -> V_137 . V_140 = V_100 -> V_134 ;
V_2 -> V_137 . V_143 = F_39 ( V_101 , V_59 ) ;
if ( ! V_2 -> V_137 . V_143 )
return - V_136 ;
}
}
}
F_24 ( V_2 -> V_60 , V_2 ) ;
V_2 -> V_4 -> V_144 = V_145 ;
V_2 -> V_4 -> V_146 =
V_147 ;
V_2 -> V_4 -> V_148 = V_149 ;
V_45 = F_69 ( V_2 ) ;
if ( V_45 ) {
F_4 ( V_2 -> V_4 , V_76 , 0 , 0 ,
L_26 ) ;
return V_45 ;
}
V_45 = F_37 ( V_2 ) ;
if ( V_45 )
return V_45 ;
return F_40 ( V_2 ) ;
}
static int F_70 ( struct V_39 * V_40 , T_5 V_150 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
V_2 -> V_151 = TRUE ;
if ( TRUE == V_2 -> V_152 ) {
V_2 -> V_152 = false ;
if ( V_2 -> V_4 -> V_153 == V_154 ) {
V_2 -> V_4 -> V_155 = TRUE ;
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_27 ) ;
} else {
V_2 -> V_4 -> V_156 = TRUE ;
F_4 ( V_2 -> V_4 , V_12 , V_13 , V_14 ,
L_28 ) ;
}
}
V_2 -> V_4 -> V_157 = false ;
F_2 ( & V_2 -> V_4 -> V_158 ) ;
return 0 ;
}
static int F_71 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
F_72 ( 100 ) ;
V_2 -> V_151 = false ;
F_43 ( V_2 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
static T_6 int F_74 ( void )
{
int V_45 ;
F_75 ( L_29 , V_50 , V_159 , V_160 ) ;
F_75 ( L_30 , V_161 ) ;
V_162 = F_76 ( V_163 , V_50 ) ;
if ( F_77 ( V_162 ) ) {
F_42 ( V_50 L_31 ) ;
return F_78 ( V_162 ) ;
}
V_45 = F_79 ( & V_164 ) ;
if ( V_45 < 0 ) {
F_42 ( V_50 L_32 ) ;
F_80 ( V_162 ) ;
return V_45 ;
}
return 0 ;
}
static T_7 void F_81 ( void )
{
F_82 ( & V_164 ) ;
F_80 ( V_162 ) ;
}
