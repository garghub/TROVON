static void F_1 ( T_1 V_1 )
{
int V_2 = 0 ;
if ( V_1 -> V_3 -> V_4 . V_5 & V_6 ) {
V_1 -> V_3 -> V_7 = V_8 ;
F_2 ( & V_1 -> V_3 -> V_4 . V_9 ) ;
}
F_3 ( V_1 -> V_3 ) ;
while ( V_1 -> V_3 -> V_10 ) {
F_4 ( V_1 -> V_3 , V_11 , V_12 , V_13 ,
L_1 ) ;
F_5 ( 100 ) ;
}
F_6 ( V_1 -> V_14 ) ;
for ( V_2 = 0 ; V_2 < V_15 ; V_2 ++ ) {
if ( V_1 -> V_16 [ V_2 ] . V_17 != NULL ) {
F_6 ( V_1 -> V_16 [ V_2 ] . V_17 ) ;
V_1 -> V_16 [ V_2 ] . V_17 = NULL ;
}
}
for ( V_2 = 0 ; V_2 < V_18 ; V_2 ++ ) {
if ( V_1 -> V_19 [ V_2 ] . V_17 != NULL ) {
F_7 ( V_1 -> V_19 [ V_2 ] . V_17 -> V_20 ) ;
F_6 ( V_1 -> V_19 [ V_2 ] . V_17 ) ;
V_1 -> V_19 [ V_2 ] . V_17 = NULL ;
}
}
F_8 ( V_1 -> V_3 ) ;
}
static void F_9 ( T_2 V_21 )
{
unsigned long V_22 = 0 ;
int V_23 ;
V_22 = F_10 ( V_24 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x128 , 4 , TRUE ) ;
V_22 = F_10 ( V_26 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x12C , 4 , TRUE ) ;
V_22 = F_10 ( V_27 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x132 , 4 , TRUE ) ;
if ( ( ( T_1 ) ( V_21 -> V_28 ) ) -> V_29 == TRUE ) {
V_22 = F_10 ( V_30 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x136 , 4 , TRUE ) ;
} else {
V_22 = F_10 ( V_31 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x136 , 4 , TRUE ) ;
}
V_22 = F_10 ( V_32 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x13C , 4 , TRUE ) ;
V_22 = F_10 ( V_33 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x140 , 4 , TRUE ) ;
V_23 = F_12 ( V_21 , 0x0F0110F8 , ( V_34 * ) & V_22 , sizeof( V_34 ) ) ;
if ( V_23 ) {
F_4 ( V_21 , V_11 , V_12 , V_13 ,
L_2 ) ;
return;
}
V_22 |= 0x6 ;
V_22 = F_10 ( V_22 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x1CC , 4 , TRUE ) ;
V_22 = F_10 ( V_35 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x1C8 , 4 , TRUE ) ;
V_22 = F_10 ( V_36 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x1D2 , 4 , TRUE ) ;
V_22 = F_10 ( V_37 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x1D6 , 4 , TRUE ) ;
F_13 ( V_21 , 0x1FC , ( V_38 ) & V_22 ) ;
V_22 &= 0x0101FFFF ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x1FC , 4 , TRUE ) ;
F_13 ( V_21 , 0xA8 , ( V_38 ) & V_22 ) ;
if ( ( V_22 & 0x00FF0000 ) >> 16 > 0x30 ) {
V_22 = ( V_22 & 0xFF00FFFF ) | ( 0x30 << 16 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0xA8 , 4 , TRUE ) ;
}
F_13 ( V_21 , 0x148 , ( V_38 ) & V_22 ) ;
if ( ( V_22 & 0x00FF0000 ) >> 16 > 0x30 ) {
V_22 = ( V_22 & 0xFF00FFFF ) | ( 0x30 << 16 ) ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x148 , 4 , TRUE ) ;
}
V_22 = 0 ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x122 , 4 , TRUE ) ;
V_22 = 0 ;
F_11 ( V_21 , ( V_25 ) & V_22 , 0x1C2 , 4 , TRUE ) ;
}
static int F_14 ( struct V_39 * V_40 , const struct V_41 * V_42 )
{
struct V_43 * V_44 = F_15 ( V_40 ) ;
int V_45 ;
T_2 V_3 ;
T_1 V_1 ;
struct V_46 * V_47 ;
V_47 = F_16 ( sizeof( V_48 ) , V_49 + 1 ) ;
if ( V_47 == NULL ) {
F_17 ( & V_44 -> V_50 , V_51 L_3 ) ;
return - V_52 ;
}
F_18 ( V_47 , & V_40 -> V_50 ) ;
V_3 = F_19 ( V_47 ) ;
V_3 -> V_50 = V_47 ;
V_3 -> V_53 = F_20 ( V_54 , V_55 ) ;
V_3 -> V_56 . V_57 = V_58 ;
V_3 -> V_56 . type = V_11 ;
V_3 -> V_56 . V_59 [ V_11 ] = 0xff ;
F_21 ( V_3 ) ;
V_45 = F_22 ( V_3 ) ;
if ( V_45 ) {
F_17 ( & V_44 -> V_50 , V_51 L_4 ) ;
F_8 ( V_3 ) ;
return V_45 ;
}
V_1 = F_23 ( sizeof( V_60 ) , V_61 ) ;
if ( V_1 == NULL ) {
F_17 ( & V_44 -> V_50 , V_51 L_5 ) ;
F_8 ( V_3 ) ;
return - V_52 ;
}
V_3 -> V_28 = V_1 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_62 = V_40 ;
F_24 ( V_40 , V_1 ) ;
F_4 ( V_3 , V_11 , V_12 , V_13 ,
L_6 , V_1 ) ;
V_45 = F_25 ( V_1 ) ;
if ( V_45 ) {
if ( - V_63 == V_45 ) {
F_4 ( V_3 , V_11 , V_12 , V_13 ,
L_7 ) ;
return V_64 ;
}
F_4 ( V_3 , V_11 , V_12 , V_13 ,
L_8 ) ;
F_24 ( V_40 , NULL ) ;
V_44 = F_15 ( V_40 ) ;
F_26 ( V_44 ) ;
F_1 ( V_1 ) ;
return V_45 ;
}
if ( V_3 -> V_65 > V_66 ) {
T_3 V_67 = 4 ;
V_45 = F_27 ( V_3 , V_68 , & V_67 , sizeof( V_67 ) ) ;
if ( V_45 )
return V_45 ;
}
if ( V_69 & V_44 -> V_70 -> V_71 . V_72 ) {
if ( V_3 -> V_73 ) {
#ifdef F_28
F_29 ( & V_44 -> V_50 , 0 ) ;
V_40 -> V_74 = 1 ;
F_30 ( V_44 ) ;
F_31 ( & V_40 -> V_50 , 1 ) ;
F_32 ( & V_1 -> V_75 , V_76 ) ;
F_4 ( V_3 , V_11 , V_12 , V_13 ,
L_9 ) ;
#endif
} else {
V_40 -> V_74 = 0 ;
F_33 ( V_44 ) ;
}
}
V_3 -> V_56 . V_59 [ V_11 ] = 0x0 ;
return V_45 ;
}
static void F_34 ( struct V_39 * V_40 )
{
T_1 V_1 = F_35 ( V_40 ) ;
T_2 V_3 ;
struct V_43 * V_44 = F_15 ( V_40 ) ;
if ( V_1 == NULL )
return;
V_3 = V_1 -> V_3 ;
F_36 ( V_3 -> V_50 ) ;
if ( V_3 -> V_73 )
V_40 -> V_74 = 0 ;
V_3 -> V_77 = TRUE ;
F_24 ( V_40 , NULL ) ;
F_1 ( V_1 ) ;
F_26 ( V_44 ) ;
}
static int F_37 ( T_1 V_1 )
{
int V_2 = 0 ;
for ( V_2 = 0 ; V_2 < V_15 ; V_2 ++ ) {
V_1 -> V_16 [ V_2 ] . V_17 = F_38 ( 0 , V_61 ) ;
if ( V_1 -> V_16 [ V_2 ] . V_17 == NULL ) {
F_4 ( V_1 -> V_3 , V_78 , 0 , 0 ,
L_10 , V_2 ) ;
return - V_52 ;
}
}
for ( V_2 = 0 ; V_2 < V_18 ; V_2 ++ ) {
V_1 -> V_19 [ V_2 ] . V_17 = F_38 ( 0 , V_61 ) ;
if ( V_1 -> V_19 [ V_2 ] . V_17 == NULL ) {
F_4 ( V_1 -> V_3 , V_78 , 0 , 0 ,
L_11 , V_2 ) ;
return - V_52 ;
}
V_1 -> V_19 [ V_2 ] . V_17 -> V_20 = F_39 ( V_79 , V_61 ) ;
if ( V_1 -> V_19 [ V_2 ] . V_17 -> V_20 == NULL ) {
F_4 ( V_1 -> V_3 , V_78 , 0 , 0 ,
L_12 , V_2 ) ;
return - V_52 ;
}
V_1 -> V_19 [ V_2 ] . V_17 -> V_80 = V_79 ;
}
return 0 ;
}
static int F_40 ( T_1 V_1 )
{
int V_81 = 0 ;
T_4 V_82 = V_64 ;
V_82 = F_41 ( V_1 -> V_3 ) ;
if ( V_82 != V_64 ) {
F_42 ( V_51 L_13 ) ;
return V_82 ;
}
if ( TRUE == V_1 -> V_3 -> V_83 ) {
if ( F_43 ( V_1 ) ) {
F_4 ( V_1 -> V_3 , V_11 , V_12 , V_13 ,
L_14 ) ;
}
V_1 -> V_3 -> V_84 = FALSE ;
V_81 = F_44 ( V_1 -> V_3 -> V_85 ,
V_1 -> V_3 -> V_84 , 5 * V_86 ) ;
if ( V_81 == 0 )
F_42 ( V_51 L_15 ) ;
if ( F_45 ( V_1 -> V_3 ) < 0 ) {
F_42 ( V_51 L_16 ) ;
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
static int F_25 ( T_1 V_1 )
{
struct V_100 * V_101 ;
struct V_88 * V_102 ;
T_5 V_103 ;
unsigned long V_81 ;
int V_45 = 0 ;
int V_104 = 0 ;
BOOLEAN V_105 = FALSE ;
T_4 V_106 = 0 ;
V_1 -> V_44 = F_60 ( F_15 ( V_1 -> V_62 ) ) ;
V_1 -> V_29 = ( V_1 -> V_44 -> V_107 == V_108 ) ;
V_1 -> V_3 -> V_109 = V_110 ;
V_1 -> V_3 -> V_111 = V_112 ;
V_45 = F_12 ( V_1 -> V_3 , V_113 ,
( V_34 * ) & ( V_1 -> V_3 -> V_65 ) , sizeof( V_34 ) ) ;
if ( V_45 ) {
F_4 ( V_1 -> V_3 , V_78 , 0 , 0 , L_17 ) ;
return V_45 ;
}
if ( 0xbece3200 == ( V_1 -> V_3 -> V_65 & ~ ( 0xF0 ) ) )
V_1 -> V_3 -> V_65 &= ~ 0xF0 ;
F_61 ( & V_1 -> V_44 -> V_50 , L_18 ,
V_1 -> V_3 -> V_65 ) ;
V_101 = V_1 -> V_62 -> V_114 ;
if ( V_1 -> V_3 -> V_65 == V_115 ) {
F_62 ( V_1 -> V_3 , & V_106 , 0x0 , 4 ) ;
if ( V_106 == V_116 )
V_105 = TRUE ;
F_61 ( & V_1 -> V_44 -> V_50 , L_19 ,
V_1 -> V_62 -> V_117 ) ;
if ( V_105 == TRUE ) {
if ( V_1 -> V_29 )
V_45 = F_63 ( V_1 -> V_44 , V_118 , V_119 ) ;
F_4 ( V_1 -> V_3 , V_11 , V_12 , V_13 ,
L_20 ) ;
if ( V_45 || ( V_1 -> V_29 == FALSE ) ) {
V_104 = V_120 ;
V_102 = & V_101 -> V_102 [ V_120 ] . V_71 ;
F_4 ( V_1 -> V_3 , V_11 , V_12 , V_13 ,
L_21 ) ;
if ( ( ( V_1 -> V_29 == TRUE ) && ( F_57 ( V_102 ) == FALSE ) )
|| ( ( V_1 -> V_29 == FALSE ) && ( F_55 ( V_102 ) == FALSE ) ) ) {
F_4 ( V_1 -> V_3 , V_11 , V_12 , V_13 ,
L_22 ) ;
F_9 ( V_1 -> V_3 ) ;
V_45 = F_64 ( V_1 -> V_44 ) ;
if ( V_45 ) {
F_4 ( V_1 -> V_3 , V_11 , V_12 , V_13 ,
L_23 ) ;
return V_45 ;
}
}
if ( ( V_1 -> V_29 == FALSE ) && F_55 ( V_102 ) ) {
T_4 V_121 = F_10 ( V_30 ) ;
F_4 ( V_1 -> V_3 , V_11 , V_12 , V_13 ,
L_24 ) ;
F_11 ( V_1 -> V_3 , ( V_25 ) & V_121 , 0x136 , 4 , TRUE ) ;
}
} else {
V_104 = V_122 ;
V_102 = & V_101 -> V_102 [ V_122 ] . V_71 ;
F_4 ( V_1 -> V_3 , V_11 , V_12 , V_13 ,
L_25 ) ;
if ( F_57 ( V_102 ) == FALSE ) {
F_4 ( V_1 -> V_3 , V_11 , V_12 , V_13 ,
L_26 ) ;
F_9 ( V_1 -> V_3 ) ;
V_45 = F_64 ( V_1 -> V_44 ) ;
if ( V_45 ) {
F_4 ( V_1 -> V_3 , V_11 , V_12 , V_13 ,
L_23 ) ;
return V_45 ;
}
}
}
}
}
V_101 = V_1 -> V_62 -> V_114 ;
for ( V_81 = 0 ; V_81 < V_101 -> V_71 . V_123 ; ++ V_81 ) {
V_102 = & V_101 -> V_102 [ V_81 ] . V_71 ;
if ( ! V_1 -> V_124 . V_125 && F_54 ( V_102 ) ) {
V_103 = F_65 ( V_102 -> V_126 ) ;
V_1 -> V_124 . V_127 = V_103 ;
V_1 -> V_124 . V_125 = V_102 -> V_90 ;
V_1 -> V_124 . V_128 =
F_66 ( V_1 -> V_44 ,
V_1 -> V_124 . V_125 ) ;
}
if ( ! V_1 -> V_129 . V_130 && F_55 ( V_102 ) ) {
V_1 -> V_129 . V_130 = V_102 -> V_90 ;
V_1 -> V_129 . V_131 =
F_67 ( V_1 -> V_44 ,
V_1 -> V_129 . V_130 ) ;
}
if ( ! V_1 -> V_132 . V_133 && F_56 ( V_102 ) ) {
V_103 = F_65 ( V_102 -> V_126 ) ;
V_1 -> V_132 . V_134 = V_103 ;
V_1 -> V_132 . V_133 = V_102 -> V_90 ;
V_1 -> V_132 . V_135 = V_102 -> V_136 ;
V_1 -> V_132 . V_137 =
F_39 ( V_103 , V_61 ) ;
if ( ! V_1 -> V_132 . V_137 ) {
F_17 ( & V_1 -> V_44 -> V_50 ,
L_27 ) ;
return - V_138 ;
}
}
if ( ! V_1 -> V_139 . V_140 && F_57 ( V_102 ) ) {
if ( ! V_1 -> V_129 . V_130 &&
( V_1 -> V_3 -> V_65 == V_115 ) && ( V_81 == V_104 ) ) {
V_103 = F_65 ( V_102 -> V_126 ) ;
V_1 -> V_129 . V_141 = V_103 ;
V_1 -> V_129 . V_130 = V_102 -> V_90 ;
V_1 -> V_129 . V_131 = F_68 ( V_1 -> V_44 ,
V_1 -> V_129 . V_130 ) ;
V_1 -> V_129 . V_142 = V_102 -> V_136 ;
} else if ( V_81 == V_143 ) {
V_103 = F_65 ( V_102 -> V_126 ) ;
V_1 -> V_139 . V_144 = V_103 ;
V_1 -> V_139 . V_140 = V_102 -> V_90 ;
V_1 -> V_139 . V_142 = V_102 -> V_136 ;
V_1 -> V_139 . V_145 = F_39 ( V_103 , V_61 ) ;
if ( ! V_1 -> V_139 . V_145 ) {
F_17 ( & V_1 -> V_44 -> V_50 ,
L_28 ) ;
return - V_138 ;
}
}
}
}
F_24 ( V_1 -> V_62 , V_1 ) ;
V_1 -> V_3 -> V_146 = V_147 ;
V_1 -> V_3 -> V_148 =
V_149 ;
V_1 -> V_3 -> V_150 = V_151 ;
V_45 = F_69 ( V_1 ) ;
if ( V_45 ) {
F_4 ( V_1 -> V_3 , V_78 , 0 , 0 ,
L_29 ) ;
return V_45 ;
}
V_45 = F_37 ( V_1 ) ;
if ( V_45 )
return V_45 ;
return F_40 ( V_1 ) ;
}
static int F_70 ( struct V_39 * V_40 , T_6 V_152 )
{
T_1 V_1 = F_35 ( V_40 ) ;
V_1 -> V_153 = TRUE ;
if ( TRUE == V_1 -> V_154 ) {
V_1 -> V_154 = FALSE ;
if ( V_1 -> V_3 -> V_155 == V_156 ) {
V_1 -> V_3 -> V_157 = TRUE ;
F_4 ( V_1 -> V_3 , V_11 , V_12 , V_13 ,
L_30 ) ;
} else {
V_1 -> V_3 -> V_158 = TRUE ;
F_4 ( V_1 -> V_3 , V_11 , V_12 , V_13 ,
L_31 ) ;
}
}
V_1 -> V_3 -> V_159 = FALSE ;
F_2 ( & V_1 -> V_3 -> V_160 ) ;
return 0 ;
}
static int F_71 ( struct V_39 * V_40 )
{
T_1 V_1 = F_35 ( V_40 ) ;
F_72 ( 100 ) ;
V_1 -> V_153 = FALSE ;
F_43 ( V_1 ) ;
F_73 ( V_1 ) ;
return 0 ;
}
static T_7 int F_74 ( void )
{
F_75 ( V_161 L_32 , V_51 , V_162 , V_163 ) ;
F_75 ( V_161 L_33 , V_164 ) ;
V_165 = F_76 ( V_166 , V_51 ) ;
if ( F_77 ( V_165 ) ) {
F_75 (KERN_ERR DRV_NAME L_34 ) ;
return F_78 ( V_165 ) ;
}
return F_79 ( & V_167 ) ;
}
static T_8 void F_80 ( void )
{
F_81 ( & V_167 ) ;
F_82 ( V_165 ) ;
}
