static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
F_3 ( L_1 , V_3 -> V_10 ) ;
F_4 ( V_11 + V_3 -> V_12 , 0 ) ;
F_4 ( V_13 + V_3 -> V_12 , 0 ) ;
F_4 ( V_14 + V_3 -> V_12 , 0 ) ;
F_4 ( V_15 + V_3 -> V_12 , 0 ) ;
F_4 ( V_16 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_17 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_18 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_19 , V_3 -> V_10 ) ;
F_4 ( V_20 , 0 ) ;
F_4 ( V_21 , 0x0000003f ) ;
F_5 ( V_22 , 0 ) ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
F_4 ( V_23 ,
( V_3 -> V_24 [ V_9 ] << 20 ) |
( V_3 -> V_25 [ V_9 ] << 10 ) |
( V_3 -> V_26 [ V_9 ] << 0 ) ) ;
}
F_6 ( V_27 + V_3 -> V_12 , V_3 -> V_10 , ~ 1 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
F_3 ( L_1 , V_3 -> V_10 ) ;
F_4 ( V_28 + V_3 -> V_12 , 0 ) ;
F_4 ( V_29 + V_3 -> V_12 , 0 ) ;
F_4 ( V_30 + V_3 -> V_12 , 0 ) ;
F_4 ( V_31 + V_3 -> V_12 , 0 ) ;
F_4 ( V_32 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_33 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_34 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_35 + V_3 -> V_12 , 0 ) ;
F_4 ( V_36 + V_3 -> V_12 , 0x00000007 ) ;
F_4 ( V_37 + V_3 -> V_12 , 0 ) ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
F_4 ( V_38 + V_3 -> V_12 ,
( V_3 -> V_24 [ V_9 ] << 20 ) |
( V_3 -> V_25 [ V_9 ] << 10 ) |
( V_3 -> V_26 [ V_9 ] << 0 ) ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
F_3 ( L_1 , V_3 -> V_10 ) ;
F_4 ( V_39 + V_3 -> V_12 ,
( F_9 ( V_40 ) |
F_10 ( V_40 ) ) ) ;
F_4 ( V_41 + V_3 -> V_12 ,
V_42 ) ;
F_4 ( V_43 + V_3 -> V_12 ,
V_44 ) ;
F_4 ( V_45 + V_3 -> V_12 ,
( F_11 ( V_46 ) |
F_12 ( V_46 ) ) ) ;
F_4 ( V_28 + V_3 -> V_12 , 0 ) ;
F_4 ( V_29 + V_3 -> V_12 , 0 ) ;
F_4 ( V_30 + V_3 -> V_12 , 0 ) ;
F_4 ( V_31 + V_3 -> V_12 , 0 ) ;
F_4 ( V_32 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_33 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_34 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_35 + V_3 -> V_12 , 0 ) ;
F_4 ( V_36 + V_3 -> V_12 , 0x00000007 ) ;
F_4 ( V_37 + V_3 -> V_12 , 0 ) ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
F_4 ( V_38 + V_3 -> V_12 ,
( V_3 -> V_24 [ V_9 ] << 20 ) |
( V_3 -> V_25 [ V_9 ] << 10 ) |
( V_3 -> V_26 [ V_9 ] << 0 ) ) ;
}
F_4 ( V_47 + V_3 -> V_12 ,
( F_13 ( V_48 ) |
F_14 ( V_48 ) |
F_15 ( V_48 ) |
F_16 ( V_48 ) ) ) ;
F_4 ( V_49 + V_3 -> V_12 ,
( F_17 ( V_50 ) |
F_18 ( V_50 ) ) ) ;
F_4 ( V_51 + V_3 -> V_12 ,
( F_19 ( V_52 ) |
F_20 ( V_52 ) ) ) ;
F_4 ( V_53 + V_3 -> V_12 ,
( F_21 ( V_3 -> V_54 ) |
F_22 ( V_55 ) ) ) ;
F_4 ( 0x6940 + V_3 -> V_12 , 0 ) ;
if ( F_23 ( V_7 ) ) {
F_4 ( V_56 + V_3 -> V_12 ,
V_57 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
T_1 V_58 ;
V_58 = F_25 ( V_59 ) ;
if ( V_3 -> V_10 == 0 )
V_58 &= ( T_1 ) ~ V_60 ;
else
V_58 |= V_60 ;
F_4 ( V_59 , V_58 ) ;
F_5 ( V_61 , 0 ) ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
F_4 ( V_62 ,
( V_3 -> V_24 [ V_9 ] << 20 ) |
( V_3 -> V_25 [ V_9 ] << 10 ) |
( V_3 -> V_26 [ V_9 ] << 0 ) ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! V_2 -> V_63 )
return;
if ( F_27 ( V_7 ) )
F_8 ( V_2 ) ;
else if ( F_28 ( V_7 ) )
F_7 ( V_2 ) ;
else if ( F_29 ( V_7 ) )
F_1 ( V_2 ) ;
else
F_24 ( V_2 ) ;
}
void F_30 ( struct V_1 * V_2 , T_2 V_64 , T_2 V_65 ,
T_2 V_66 , int V_67 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_24 [ V_67 ] = V_64 >> 6 ;
V_3 -> V_25 [ V_67 ] = V_65 >> 6 ;
V_3 -> V_26 [ V_67 ] = V_66 >> 6 ;
}
void F_31 ( struct V_1 * V_2 , T_2 * V_64 , T_2 * V_65 ,
T_2 * V_66 , int V_67 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_64 = V_3 -> V_24 [ V_67 ] << 6 ;
* V_65 = V_3 -> V_25 [ V_67 ] << 6 ;
* V_66 = V_3 -> V_26 [ V_67 ] << 6 ;
}
static int F_32 ( struct V_1 * V_2 , T_2 * V_64 , T_2 * V_65 ,
T_2 * V_66 , T_1 V_68 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_68 ; V_9 ++ ) {
V_3 -> V_24 [ V_9 ] = V_64 [ V_9 ] >> 6 ;
V_3 -> V_25 [ V_9 ] = V_65 [ V_9 ] >> 6 ;
V_3 -> V_26 [ V_9 ] = V_66 [ V_9 ] >> 6 ;
}
F_26 ( V_2 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_3 -> V_69 ) ;
F_36 ( V_3 ) ;
}
static void F_37 ( struct V_70 * V_71 )
{
struct V_72 * V_73 =
F_38 ( V_71 , struct V_72 , V_74 ) ;
int V_75 ;
V_75 = F_39 ( V_73 -> V_76 , false ) ;
if ( F_40 ( V_75 == 0 ) ) {
V_75 = F_41 ( V_73 -> V_76 ) ;
if ( F_42 ( V_75 != 0 ) ) {
F_43 ( L_2 ) ;
}
F_44 ( V_73 -> V_76 ) ;
} else
F_43 ( L_3 ) ;
F_45 ( & V_73 -> V_76 -> V_77 ) ;
F_36 ( V_73 ) ;
}
void F_46 ( struct V_6 * V_7 , int V_10 )
{
struct V_3 * V_3 = V_7 -> V_78 . V_79 [ V_10 ] ;
unsigned long V_80 ;
T_3 V_81 ;
int V_82 , V_83 ;
if ( V_3 == NULL )
return;
if ( ( V_84 == 2 ) && F_28 ( V_7 ) )
return;
F_47 ( & V_7 -> V_85 -> V_86 , V_80 ) ;
if ( V_3 -> V_87 != V_88 ) {
F_48 ( L_4
L_5 ,
V_3 -> V_87 ,
V_88 ) ;
F_49 ( & V_7 -> V_85 -> V_86 , V_80 ) ;
return;
}
V_81 = F_50 ( V_7 , V_10 ) ;
if ( V_81 &&
( V_89 & F_51 ( V_7 -> V_85 ,
V_10 ,
V_90 ,
& V_82 , & V_83 , NULL , NULL ,
& V_7 -> V_78 . V_79 [ V_10 ] -> V_91 . V_92 ) ) &&
( ( V_82 >= ( 99 * V_7 -> V_78 . V_79 [ V_10 ] -> V_91 . V_92 . V_93 ) / 100 ) ||
( V_82 < 0 && ! F_29 ( V_7 ) ) ) ) {
V_81 = 0 ;
}
F_49 ( & V_7 -> V_85 -> V_86 , V_80 ) ;
if ( ! V_81 )
F_52 ( V_7 , V_10 ) ;
}
void F_52 ( struct V_6 * V_7 , int V_10 )
{
struct V_3 * V_3 = V_7 -> V_78 . V_79 [ V_10 ] ;
struct V_72 * V_73 ;
unsigned long V_80 ;
if ( V_3 == NULL )
return;
F_47 ( & V_7 -> V_85 -> V_86 , V_80 ) ;
V_73 = V_3 -> V_94 ;
if ( V_3 -> V_87 != V_88 ) {
F_48 ( L_4
L_5 ,
V_3 -> V_87 ,
V_88 ) ;
F_49 ( & V_7 -> V_85 -> V_86 , V_80 ) ;
return;
}
V_3 -> V_87 = V_95 ;
V_3 -> V_94 = NULL ;
if ( V_73 -> V_96 )
F_53 ( & V_3 -> V_91 , V_73 -> V_96 ) ;
F_49 ( & V_7 -> V_85 -> V_86 , V_80 ) ;
F_54 ( & V_3 -> V_91 ) ;
F_55 ( V_7 , V_73 -> V_10 ) ;
F_56 ( V_3 -> V_69 , & V_73 -> V_74 ) ;
}
static void F_57 ( struct V_70 * V_71 )
{
struct V_72 * V_73 =
F_38 ( V_71 , struct V_72 , V_94 ) ;
struct V_6 * V_7 = V_73 -> V_7 ;
struct V_3 * V_3 = V_7 -> V_78 . V_79 [ V_73 -> V_10 ] ;
struct V_1 * V_2 = & V_3 -> V_91 ;
unsigned long V_80 ;
int V_75 ;
int V_82 , V_83 , V_97 , V_98 = 0 ;
unsigned V_99 = 4 ;
struct V_100 * V_101 = & V_2 -> V_5 -> V_101 [ V_73 -> V_10 ] ;
F_58 ( & V_7 -> V_102 ) ;
if ( V_73 -> V_103 ) {
struct V_104 * V_103 ;
V_103 = F_59 ( V_73 -> V_103 ) ;
if ( V_103 && V_103 -> V_7 == V_7 ) {
V_75 = F_60 ( V_103 , false ) ;
if ( V_75 == - V_105 ) {
F_61 ( & V_7 -> V_102 ) ;
do {
V_75 = F_62 ( V_7 ) ;
} while ( V_75 == - V_106 );
F_58 ( & V_7 -> V_102 ) ;
}
} else
V_75 = F_63 ( V_73 -> V_103 , false ) ;
if ( V_75 )
F_43 ( L_6 , V_75 ) ;
F_64 ( V_73 -> V_103 ) ;
V_73 -> V_103 = NULL ;
}
F_47 ( & V_2 -> V_5 -> V_86 , V_80 ) ;
F_65 ( V_7 , V_3 -> V_10 ) ;
while ( V_3 -> V_63 && -- V_99 ) {
V_97 = F_51 ( V_7 -> V_85 , V_73 -> V_10 ,
V_107 ,
& V_82 , & V_83 , NULL , NULL ,
& V_2 -> V_92 ) ;
if ( ( V_97 & ( V_89 | V_108 ) ) !=
( V_89 | V_108 ) ||
! ( V_82 >= 0 && V_83 <= 0 ) )
break;
V_98 = ( - V_83 + 1 ) * F_66 ( V_101 -> V_109 / 1000 , 5 ) ;
if ( V_98 > V_101 -> V_110 / 2000 ) {
V_99 = 0 ;
break;
}
F_49 ( & V_2 -> V_5 -> V_86 , V_80 ) ;
F_67 ( V_98 , 2 * V_98 ) ;
F_47 ( & V_2 -> V_5 -> V_86 , V_80 ) ;
} ;
if ( ! V_99 )
F_48 ( L_7
L_8
L_9 , V_73 -> V_10 , V_98 ,
V_101 -> V_110 / 1000 ,
V_101 -> V_109 / 1000 , V_97 , V_82 , V_83 ) ;
F_68 ( V_7 , V_3 -> V_10 , V_73 -> V_91 , V_73 -> V_111 ) ;
V_3 -> V_87 = V_88 ;
F_49 ( & V_2 -> V_5 -> V_86 , V_80 ) ;
F_61 ( & V_7 -> V_102 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_112 * V_113 ,
struct V_114 * V_96 ,
T_1 V_115 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_116 * V_117 ;
struct V_116 * V_118 ;
struct V_119 * V_120 ;
struct V_72 * V_73 ;
struct V_121 * V_122 ;
T_1 V_123 , V_124 ;
T_4 V_91 ;
unsigned long V_80 ;
int V_75 ;
V_73 = F_70 ( sizeof *V_73 , V_125 ) ;
if ( V_73 == NULL )
return - V_126 ;
F_71 ( & V_73 -> V_94 , F_57 ) ;
F_71 ( & V_73 -> V_74 , F_37 ) ;
V_73 -> V_7 = V_7 ;
V_73 -> V_10 = V_3 -> V_10 ;
V_73 -> V_96 = V_96 ;
V_73 -> V_111 = ( V_115 & V_127 ) != 0 ;
V_117 = F_72 ( V_2 -> V_128 -> V_113 ) ;
V_120 = V_117 -> V_120 ;
F_73 ( V_120 ) ;
V_73 -> V_76 = F_74 ( V_120 ) ;
V_118 = F_72 ( V_113 ) ;
V_120 = V_118 -> V_120 ;
V_122 = F_74 ( V_120 ) ;
F_48 ( L_10 ,
V_73 -> V_76 , V_122 ) ;
V_75 = F_39 ( V_122 , false ) ;
if ( F_42 ( V_75 != 0 ) ) {
F_43 ( L_11 ) ;
goto V_129;
}
V_75 = F_75 ( V_122 , V_130 ,
F_29 ( V_7 ) ? 0 : 1 << 27 , & V_91 ) ;
if ( F_42 ( V_75 != 0 ) ) {
F_44 ( V_122 ) ;
V_75 = - V_131 ;
F_43 ( L_12 ) ;
goto V_129;
}
V_73 -> V_103 = F_76 ( F_77 ( V_122 -> V_132 . V_133 ) ) ;
F_78 ( V_122 , & V_123 , NULL ) ;
F_44 ( V_122 ) ;
if ( ! F_29 ( V_7 ) ) {
V_91 -= V_3 -> V_134 ;
V_124 = V_113 -> V_135 [ 0 ] / ( V_113 -> V_136 / 8 ) ;
if ( V_123 & V_137 ) {
if ( F_79 ( V_7 ) ) {
V_91 &= ~ 0x7ff ;
} else {
int V_138 = V_113 -> V_136 >> 4 ;
int V_139 = ( ( ( V_2 -> V_140 >> 3 ) * V_124 + V_2 -> V_141 ) >> ( 8 - V_138 ) ) << 11 ;
V_91 += V_139 + ( ( V_2 -> V_141 << V_138 ) % 256 ) + ( ( V_2 -> V_140 % 8 ) << 8 ) ;
}
} else {
int V_142 = V_2 -> V_140 * V_124 + V_2 -> V_141 ;
switch ( V_113 -> V_136 ) {
case 8 :
default:
V_142 *= 1 ;
break;
case 15 :
case 16 :
V_142 *= 2 ;
break;
case 24 :
V_142 *= 3 ;
break;
case 32 :
V_142 *= 4 ;
break;
}
V_91 += V_142 ;
}
V_91 &= ~ 7 ;
}
V_73 -> V_91 = V_91 ;
V_75 = F_80 ( V_2 ) ;
if ( V_75 ) {
F_43 ( L_13 ) ;
goto V_143;
}
F_47 ( & V_2 -> V_5 -> V_86 , V_80 ) ;
if ( V_3 -> V_87 != V_95 ) {
F_48 ( L_14 ) ;
F_49 ( & V_2 -> V_5 -> V_86 , V_80 ) ;
V_75 = - V_144 ;
goto V_145;
}
V_3 -> V_87 = V_146 ;
V_3 -> V_94 = V_73 ;
V_2 -> V_128 -> V_113 = V_113 ;
F_49 ( & V_2 -> V_5 -> V_86 , V_80 ) ;
F_56 ( V_3 -> V_69 , & V_73 -> V_94 ) ;
return 0 ;
V_145:
F_54 ( V_2 ) ;
V_143:
if ( F_42 ( F_39 ( V_122 , false ) != 0 ) ) {
F_43 ( L_15 ) ;
goto V_129;
}
if ( F_42 ( F_41 ( V_122 ) != 0 ) ) {
F_43 ( L_16 ) ;
}
F_44 ( V_122 ) ;
V_129:
F_45 ( & V_73 -> V_76 -> V_77 ) ;
F_64 ( V_73 -> V_103 ) ;
F_36 ( V_73 ) ;
return V_75 ;
}
static int
F_81 ( struct V_147 * V_148 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
bool V_149 = false ;
int V_150 ;
if ( ! V_148 || ! V_148 -> V_2 )
return - V_131 ;
V_5 = V_148 -> V_2 -> V_5 ;
V_150 = F_82 ( V_5 -> V_5 ) ;
if ( V_150 < 0 )
return V_150 ;
V_150 = F_83 ( V_148 ) ;
F_84 (crtc, &dev->mode_config.crtc_list, head)
if ( V_2 -> V_63 )
V_149 = true ;
F_85 ( V_5 -> V_5 ) ;
V_7 = V_5 -> V_8 ;
if ( V_149 && ! V_7 -> V_151 ) {
V_7 -> V_151 = true ;
return V_150 ;
}
if ( ! V_149 && V_7 -> V_151 ) {
F_86 ( V_5 -> V_5 ) ;
V_7 -> V_151 = false ;
}
F_86 ( V_5 -> V_5 ) ;
return V_150 ;
}
static void F_87 ( struct V_4 * V_5 , int V_152 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_3 * V_3 ;
int V_9 ;
V_3 = F_70 ( sizeof( struct V_3 ) + ( V_153 * sizeof( struct V_154 * ) ) , V_125 ) ;
if ( V_3 == NULL )
return;
F_88 ( V_5 , & V_3 -> V_91 , & V_155 ) ;
F_89 ( & V_3 -> V_91 , 256 ) ;
V_3 -> V_10 = V_152 ;
V_3 -> V_69 = F_90 ( L_17 , V_156 , 0 ) ;
V_7 -> V_78 . V_79 [ V_152 ] = V_3 ;
if ( V_7 -> V_157 >= V_158 ) {
V_3 -> V_159 = V_160 ;
V_3 -> V_161 = V_162 ;
} else {
V_3 -> V_159 = V_163 ;
V_3 -> V_161 = V_164 ;
}
V_5 -> V_165 . V_166 = V_3 -> V_159 ;
V_5 -> V_165 . V_167 = V_3 -> V_161 ;
#if 0
radeon_crtc->mode_set.crtc = &radeon_crtc->base;
radeon_crtc->mode_set.connectors = (struct drm_connector **)(radeon_crtc + 1);
radeon_crtc->mode_set.num_connectors = 0;
#endif
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
V_3 -> V_24 [ V_9 ] = V_9 << 2 ;
V_3 -> V_25 [ V_9 ] = V_9 << 2 ;
V_3 -> V_26 [ V_9 ] = V_9 << 2 ;
}
if ( V_7 -> V_168 && ( F_29 ( V_7 ) || V_169 ) )
F_91 ( V_5 , V_3 ) ;
else
F_92 ( V_5 , V_3 ) ;
}
static void F_93 ( struct V_4 * V_5 )
{
struct V_154 * V_170 ;
struct V_171 * V_171 ;
struct V_172 * V_173 ;
struct V_174 * V_174 ;
T_1 V_175 ;
int V_9 = 0 ;
F_94 ( L_18 ) ;
F_84 (connector, &dev->mode_config.connector_list, head) {
V_171 = F_95 ( V_170 ) ;
F_94 ( L_19 , V_9 ) ;
F_94 ( L_20 , V_170 -> V_176 ) ;
if ( V_171 -> V_177 . V_177 != V_178 )
F_94 ( L_20 , V_179 [ V_171 -> V_177 . V_177 ] ) ;
if ( V_171 -> V_180 ) {
F_94 ( L_21 ,
V_171 -> V_180 -> V_181 . V_182 ,
V_171 -> V_180 -> V_181 . V_183 ,
V_171 -> V_180 -> V_181 . V_184 ,
V_171 -> V_180 -> V_181 . V_185 ,
V_171 -> V_180 -> V_181 . V_186 ,
V_171 -> V_180 -> V_181 . V_187 ,
V_171 -> V_180 -> V_181 . V_188 ,
V_171 -> V_180 -> V_181 . V_189 ) ;
if ( V_171 -> V_190 . V_191 )
F_94 ( L_22 ,
V_171 -> V_190 . V_192 ,
V_171 -> V_190 . V_193 ) ;
if ( V_171 -> V_190 . V_194 )
F_94 ( L_23 ,
V_171 -> V_190 . V_195 ,
V_171 -> V_190 . V_196 ) ;
} else {
if ( V_170 -> V_197 == V_198 ||
V_170 -> V_197 == V_199 ||
V_170 -> V_197 == V_200 ||
V_170 -> V_197 == V_201 ||
V_170 -> V_197 == V_202 ||
V_170 -> V_197 == V_203 )
F_94 ( L_24 ) ;
}
F_94 ( L_25 ) ;
F_84 (encoder, &dev->mode_config.encoder_list, head) {
V_174 = F_96 ( V_173 ) ;
V_175 = V_174 -> V_175 & V_171 -> V_175 ;
if ( V_175 ) {
if ( V_175 & V_204 )
F_94 ( L_26 , V_205 [ V_174 -> V_206 ] ) ;
if ( V_175 & V_207 )
F_94 ( L_27 , V_205 [ V_174 -> V_206 ] ) ;
if ( V_175 & V_208 )
F_94 ( L_28 , V_205 [ V_174 -> V_206 ] ) ;
if ( V_175 & V_209 )
F_94 ( L_29 , V_205 [ V_174 -> V_206 ] ) ;
if ( V_175 & V_210 )
F_94 ( L_30 , V_205 [ V_174 -> V_206 ] ) ;
if ( V_175 & V_211 )
F_94 ( L_31 , V_205 [ V_174 -> V_206 ] ) ;
if ( V_175 & V_212 )
F_94 ( L_32 , V_205 [ V_174 -> V_206 ] ) ;
if ( V_175 & V_213 )
F_94 ( L_33 , V_205 [ V_174 -> V_206 ] ) ;
if ( V_175 & V_214 )
F_94 ( L_34 , V_205 [ V_174 -> V_206 ] ) ;
if ( V_175 & V_215 )
F_94 ( L_35 , V_205 [ V_174 -> V_206 ] ) ;
if ( V_175 & V_216 )
F_94 ( L_36 , V_205 [ V_174 -> V_206 ] ) ;
}
}
V_9 ++ ;
}
}
static bool F_97 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
bool V_150 = false ;
if ( V_7 -> V_217 ) {
if ( V_7 -> V_168 ) {
V_150 = F_98 ( V_5 ) ;
if ( V_150 == false )
V_150 = F_99 ( V_5 ) ;
} else {
V_150 = F_100 ( V_5 ) ;
if ( V_150 == false )
V_150 = F_101 ( V_5 ) ;
}
} else {
if ( ! F_29 ( V_7 ) )
V_150 = F_101 ( V_5 ) ;
}
if ( V_150 ) {
F_102 ( V_5 ) ;
F_93 ( V_5 ) ;
}
return V_150 ;
}
static void F_103 ( unsigned * V_218 , unsigned * V_219 ,
unsigned V_220 , unsigned V_221 )
{
unsigned V_222 ;
V_222 = F_104 ( * V_218 , * V_219 ) ;
* V_218 /= V_222 ;
* V_219 /= V_222 ;
if ( * V_218 < V_220 ) {
V_222 = F_105 ( V_220 , * V_218 ) ;
* V_218 *= V_222 ;
* V_219 *= V_222 ;
}
if ( * V_219 < V_221 ) {
V_222 = F_105 ( V_221 , * V_219 ) ;
* V_218 *= V_222 ;
* V_219 *= V_222 ;
}
}
static void F_106 ( unsigned V_218 , unsigned V_219 , unsigned V_223 ,
unsigned V_224 , unsigned V_225 ,
unsigned * V_226 , unsigned * V_227 )
{
V_225 = F_66 ( F_107 ( 100 / V_223 , V_225 ) , 1u ) ;
* V_227 = F_107 ( F_66 ( F_108 ( V_219 , V_223 ) , 1u ) , V_225 ) ;
* V_226 = F_108 ( V_218 * * V_227 * V_223 , V_219 ) ;
if ( * V_226 > V_224 ) {
* V_227 = F_108 ( * V_227 * V_224 , * V_226 ) ;
* V_226 = V_224 ;
}
}
void F_109 ( struct V_228 * V_229 ,
T_3 V_230 ,
T_3 * V_231 ,
T_3 * V_232 ,
T_3 * V_233 ,
T_3 * V_234 ,
T_3 * V_235 )
{
unsigned V_236 = V_229 -> V_80 & V_237 ?
V_230 : V_230 / 10 ;
unsigned V_238 , V_224 , V_226 ;
unsigned V_239 , V_240 , V_223 ;
unsigned V_241 , V_225 , V_227 ;
unsigned V_242 , V_243 ;
unsigned V_218 , V_219 ;
V_238 = V_229 -> V_244 ;
V_224 = V_229 -> V_245 ;
if ( V_229 -> V_80 & V_237 ) {
V_238 *= 10 ;
V_224 *= 10 ;
}
if ( V_229 -> V_80 & V_246 )
V_241 = V_229 -> V_247 ;
else
V_241 = V_229 -> V_248 ;
if ( V_229 -> V_80 & V_237 &&
V_229 -> V_80 & V_246 )
V_225 = V_229 -> V_247 ;
else if ( V_229 -> V_80 & V_249 )
V_225 = F_107 ( V_229 -> V_250 , 7u ) ;
else
V_225 = V_229 -> V_250 ;
if ( V_229 -> V_80 & V_251 ) {
V_239 = V_229 -> V_223 ;
V_240 = V_229 -> V_223 ;
} else {
unsigned V_252 , V_253 ;
if ( V_229 -> V_80 & V_254 ) {
V_252 = V_229 -> V_255 ;
V_253 = V_229 -> V_256 ;
} else {
V_252 = V_229 -> V_257 ;
V_253 = V_229 -> V_258 ;
}
if ( V_229 -> V_80 & V_237 ) {
V_252 *= 10 ;
V_253 *= 10 ;
}
V_239 = V_252 / V_236 ;
if ( ( V_236 * V_239 ) < V_252 )
++ V_239 ;
if ( V_239 < V_229 -> V_259 )
V_239 = V_229 -> V_259 ;
V_240 = V_253 / V_236 ;
if ( ( V_236 * V_240 ) > V_253 )
-- V_240 ;
if ( V_240 > V_229 -> V_260 )
V_240 = V_229 -> V_260 ;
}
V_218 = V_236 ;
V_219 = V_229 -> V_261 ;
F_103 ( & V_218 , & V_219 , V_238 , V_239 ) ;
if ( V_229 -> V_80 & V_249 )
V_242 = V_239 ;
else
V_242 = V_240 ;
V_243 = ~ 0 ;
for ( V_223 = V_239 ; V_223 <= V_240 ; ++ V_223 ) {
unsigned V_262 ;
F_106 ( V_218 , V_219 , V_223 , V_224 ,
V_225 , & V_226 , & V_227 ) ;
V_262 = abs ( V_236 - ( V_229 -> V_261 * V_226 ) /
( V_227 * V_223 ) ) ;
if ( V_262 < V_243 || ( V_262 == V_243 &&
! ( V_229 -> V_80 & V_249 ) ) ) {
V_242 = V_223 ;
V_243 = V_262 ;
}
}
V_223 = V_242 ;
F_106 ( V_218 , V_219 , V_223 , V_224 , V_225 ,
& V_226 , & V_227 ) ;
F_103 ( & V_226 , & V_227 , V_238 , V_241 ) ;
if ( V_229 -> V_80 & V_237 && ( V_226 % 10 ) ) {
V_238 = F_66 ( V_238 , ( 9 - ( V_226 % 10 ) ) * 20 + 50 ) ;
if ( V_226 < V_238 ) {
unsigned V_222 = F_105 ( V_238 , V_226 ) ;
V_226 *= V_222 ;
V_227 *= V_222 ;
}
}
if ( V_229 -> V_80 & V_237 ) {
* V_232 = V_226 / 10 ;
* V_233 = V_226 % 10 ;
} else {
* V_232 = V_226 ;
* V_233 = 0 ;
}
* V_231 = ( ( V_229 -> V_261 * * V_232 * 10 ) +
( V_229 -> V_261 * * V_233 ) ) /
( V_227 * V_223 * 10 ) ;
* V_234 = V_227 ;
* V_235 = V_223 ;
F_3 ( L_37 ,
V_230 , * V_231 * 10 , * V_232 , * V_233 ,
V_227 , V_223 ) ;
}
static inline T_1 F_110 ( T_4 V_263 , T_1 V_264 )
{
T_4 V_265 ;
V_263 += V_264 / 2 ;
V_265 = F_111 ( V_263 , V_264 ) ;
return V_263 ;
}
void F_112 ( struct V_228 * V_229 ,
T_4 V_230 ,
T_1 * V_231 ,
T_1 * V_232 ,
T_1 * V_233 ,
T_1 * V_234 ,
T_1 * V_235 )
{
T_1 V_248 = V_229 -> V_248 ;
T_1 V_250 = V_229 -> V_250 ;
T_1 V_259 = V_229 -> V_259 ;
T_1 V_260 = V_229 -> V_260 ;
T_1 V_266 = 0 ;
T_1 V_267 = 0 ;
T_1 V_268 = V_229 -> V_268 ;
T_1 V_269 = 1 ;
T_1 V_270 = 1 ;
T_1 V_271 = 1 ;
T_1 V_272 = 0 ;
T_1 V_273 = - 1 ;
T_1 V_274 = 0xffffffff ;
T_1 V_275 = 1 ;
T_1 V_223 ;
T_3 V_257 , V_258 ;
F_3 ( L_38 , V_230 , V_229 -> V_248 , V_229 -> V_250 ) ;
V_230 = V_230 * 1000 ;
if ( V_229 -> V_80 & V_254 ) {
V_257 = V_229 -> V_255 ;
V_258 = V_229 -> V_256 ;
} else {
V_257 = V_229 -> V_257 ;
V_258 = V_229 -> V_258 ;
}
if ( V_257 > 64800 )
V_257 = 64800 ;
if ( V_229 -> V_80 & V_246 )
V_248 = V_250 = V_229 -> V_247 ;
else {
while ( V_248 < V_250 - 1 ) {
T_1 V_276 = ( V_248 + V_250 ) / 2 ;
T_1 V_277 = V_229 -> V_261 / V_276 ;
if ( V_277 < V_229 -> V_278 )
V_250 = V_276 ;
else if ( V_277 > V_229 -> V_279 )
V_248 = V_276 ;
else
break;
}
}
if ( V_229 -> V_80 & V_251 )
V_259 = V_260 = V_229 -> V_223 ;
if ( V_229 -> V_80 & V_237 ) {
V_266 = V_229 -> V_280 ;
V_267 = V_229 -> V_281 ;
}
for ( V_223 = V_260 ; V_223 >= V_259 ; -- V_223 ) {
T_1 V_227 ;
if ( ( V_229 -> V_80 & V_282 ) && ( V_223 & 1 ) )
continue;
if ( V_229 -> V_80 & V_283 ) {
if ( ( V_223 == 5 ) ||
( V_223 == 7 ) ||
( V_223 == 9 ) ||
( V_223 == 10 ) ||
( V_223 == 11 ) ||
( V_223 == 13 ) ||
( V_223 == 14 ) ||
( V_223 == 15 ) )
continue;
}
for ( V_227 = V_248 ; V_227 <= V_250 ; ++ V_227 ) {
T_1 V_284 , V_285 = 0 , error , V_286 ;
T_1 V_277 = V_229 -> V_261 / V_227 ;
T_1 V_287 = V_229 -> V_244 ;
T_1 V_288 = V_229 -> V_245 + 1 ;
if ( V_277 < V_229 -> V_278 || V_277 > V_229 -> V_279 )
continue;
while ( V_287 < V_288 ) {
T_1 V_289 ;
T_1 V_290 = V_266 ;
T_1 V_291 = V_267 + 1 ;
T_1 V_292 ;
T_4 V_222 ;
V_284 = ( V_287 + V_288 ) / 2 ;
V_222 = ( T_4 ) V_229 -> V_261 * V_284 ;
V_289 = F_110 ( V_222 , V_227 ) ;
if ( V_289 < V_257 ) {
V_287 = V_284 + 1 ;
continue;
} else if ( V_289 > V_258 ) {
V_288 = V_284 ;
continue;
}
while ( V_290 < V_291 ) {
V_292 = ( V_290 + V_291 ) / 2 ;
V_222 = ( T_4 ) V_229 -> V_261 * 10000 * V_284 ;
V_222 += ( T_4 ) V_229 -> V_261 * 1000 * V_292 ;
V_285 = F_110 ( V_222 , V_227 * V_223 ) ;
if ( V_229 -> V_80 & V_293 ) {
if ( V_230 < V_285 )
error = 0xffffffff ;
else
error = V_230 - V_285 ;
} else
error = abs ( V_285 - V_230 ) ;
V_286 = abs ( V_289 - V_268 ) ;
if ( ( V_268 == 0 && error < V_274 ) ||
( V_268 != 0 &&
( ( V_274 > 100 && error < V_274 - 100 ) ||
( abs ( error - V_274 ) < 100 && V_286 < V_275 ) ) ) ) {
V_269 = V_223 ;
V_270 = V_227 ;
V_271 = V_284 ;
V_272 = V_292 ;
V_273 = V_285 ;
V_274 = error ;
V_275 = V_286 ;
} else if ( V_285 == V_230 ) {
if ( V_273 == - 1 ) {
V_269 = V_223 ;
V_270 = V_227 ;
V_271 = V_284 ;
V_272 = V_292 ;
V_273 = V_285 ;
V_274 = error ;
V_275 = V_286 ;
} else if ( ( ( V_229 -> V_80 & V_294 ) && ( V_227 < V_270 ) ) ||
( ( V_229 -> V_80 & V_295 ) && ( V_227 > V_270 ) ) ||
( ( V_229 -> V_80 & V_296 ) && ( V_284 < V_271 ) ) ||
( ( V_229 -> V_80 & V_297 ) && ( V_284 > V_271 ) ) ||
( ( V_229 -> V_80 & V_298 ) && ( V_223 < V_269 ) ) ||
( ( V_229 -> V_80 & V_299 ) && ( V_223 > V_269 ) ) ) {
V_269 = V_223 ;
V_270 = V_227 ;
V_271 = V_284 ;
V_272 = V_292 ;
V_273 = V_285 ;
V_274 = error ;
V_275 = V_286 ;
}
}
if ( V_285 < V_230 )
V_290 = V_292 + 1 ;
else
V_291 = V_292 ;
}
if ( V_285 < V_230 )
V_287 = V_284 + 1 ;
else
V_288 = V_284 ;
}
}
}
* V_231 = V_273 / 10000 ;
* V_232 = V_271 ;
* V_233 = V_272 ;
* V_234 = V_270 ;
* V_235 = V_269 ;
F_3 ( L_39 ,
( long long ) V_230 ,
V_273 / 1000 , V_271 , V_272 ,
V_270 , V_269 ) ;
}
static void F_113 ( struct V_112 * V_113 )
{
struct V_116 * V_300 = F_72 ( V_113 ) ;
F_45 ( V_300 -> V_120 ) ;
F_114 ( V_113 ) ;
F_36 ( V_300 ) ;
}
static int F_115 ( struct V_112 * V_113 ,
struct V_301 * V_302 ,
unsigned int * V_303 )
{
struct V_116 * V_300 = F_72 ( V_113 ) ;
return F_116 ( V_302 , V_300 -> V_120 , V_303 ) ;
}
int
F_117 ( struct V_4 * V_5 ,
struct V_116 * V_304 ,
const struct V_305 * V_306 ,
struct V_119 * V_120 )
{
int V_150 ;
V_304 -> V_120 = V_120 ;
F_118 ( & V_304 -> V_91 , V_306 ) ;
V_150 = F_119 ( V_5 , & V_304 -> V_91 , & V_307 ) ;
if ( V_150 ) {
V_304 -> V_120 = NULL ;
return V_150 ;
}
return 0 ;
}
static struct V_112 *
F_120 ( struct V_4 * V_5 ,
struct V_301 * V_302 ,
const struct V_305 * V_306 )
{
struct V_119 * V_120 ;
struct V_116 * V_300 ;
int V_150 ;
V_120 = F_121 ( V_302 , V_306 -> V_308 [ 0 ] ) ;
if ( V_120 == NULL ) {
F_122 ( & V_5 -> V_309 -> V_5 , L_40
L_41 , V_306 -> V_308 [ 0 ] ) ;
return F_123 ( - V_310 ) ;
}
V_300 = F_70 ( sizeof( * V_300 ) , V_125 ) ;
if ( V_300 == NULL ) {
F_45 ( V_120 ) ;
return F_123 ( - V_126 ) ;
}
V_150 = F_117 ( V_5 , V_300 , V_306 , V_120 ) ;
if ( V_150 ) {
F_36 ( V_300 ) ;
F_45 ( V_120 ) ;
return F_123 ( V_150 ) ;
}
return & V_300 -> V_91 ;
}
static void F_124 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_125 ( V_7 ) ;
}
static int F_126 ( struct V_6 * V_7 )
{
int V_311 ;
if ( V_7 -> V_168 ) {
V_7 -> V_78 . V_312 =
F_127 ( V_7 -> V_85 , 0 , L_42 , 0 , 1 ) ;
if ( ! V_7 -> V_78 . V_312 )
return - V_126 ;
}
if ( ! F_29 ( V_7 ) ) {
V_311 = F_128 ( V_313 ) ;
V_7 -> V_78 . V_314 =
F_129 ( V_7 -> V_85 , 0 ,
L_43 ,
V_313 , V_311 ) ;
}
V_7 -> V_78 . V_315 =
F_127 ( V_7 -> V_85 , 0 , L_44 , 0 , 1 ) ;
if ( ! V_7 -> V_78 . V_315 )
return - V_126 ;
F_130 ( V_7 -> V_85 ) ;
V_311 = F_128 ( V_316 ) ;
V_7 -> V_78 . V_317 =
F_129 ( V_7 -> V_85 , 0 ,
L_45 ,
V_316 , V_311 ) ;
V_311 = F_128 ( V_318 ) ;
V_7 -> V_78 . V_319 =
F_129 ( V_7 -> V_85 , 0 ,
L_46 ,
V_318 , V_311 ) ;
V_7 -> V_78 . V_320 =
F_127 ( V_7 -> V_85 , 0 ,
L_47 , 0 , 128 ) ;
if ( ! V_7 -> V_78 . V_320 )
return - V_126 ;
V_7 -> V_78 . V_321 =
F_127 ( V_7 -> V_85 , 0 ,
L_48 , 0 , 128 ) ;
if ( ! V_7 -> V_78 . V_321 )
return - V_126 ;
V_311 = F_128 ( V_322 ) ;
V_7 -> V_78 . V_323 =
F_129 ( V_7 -> V_85 , 0 ,
L_49 ,
V_322 , V_311 ) ;
V_311 = F_128 ( V_324 ) ;
V_7 -> V_78 . V_325 =
F_129 ( V_7 -> V_85 , 0 ,
L_50 ,
V_324 , V_311 ) ;
V_311 = F_128 ( V_326 ) ;
V_7 -> V_78 . V_327 =
F_129 ( V_7 -> V_85 , 0 ,
L_51 ,
V_326 , V_311 ) ;
return 0 ;
}
void F_131 ( struct V_6 * V_7 )
{
if ( ( V_328 == 0 ) || ( V_328 > 2 ) ) {
if ( ( F_79 ( V_7 ) || ( V_7 -> V_157 == V_329 ) ) &&
! ( V_7 -> V_80 & V_330 ) )
V_7 -> V_331 = 2 ;
else
V_7 -> V_331 = 0 ;
} else
V_7 -> V_331 = V_328 ;
}
static void F_132 ( struct V_6 * V_7 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_332 ; V_9 ++ )
V_7 -> V_78 . V_333 [ V_9 ] = NULL ;
if ( F_133 ( V_7 ) ) {
} else if ( F_28 ( V_7 ) ) {
static T_1 V_334 [] = {
V_335 ,
V_336 ,
V_337 ,
V_338 ,
V_339 ,
V_340 ,
0x13830 - 0x7030 ,
} ;
int V_341 ;
if ( F_23 ( V_7 ) )
V_341 = 7 ;
else if ( F_134 ( V_7 ) )
V_341 = 6 ;
else if ( F_27 ( V_7 ) )
V_341 = 6 ;
else if ( F_135 ( V_7 ) )
V_341 = 2 ;
else
V_341 = 6 ;
F_136 ( V_341 > F_128 ( V_334 ) ) ;
for ( V_9 = 0 ; V_9 < V_341 ; V_9 ++ ) {
V_7 -> V_78 . V_333 [ V_9 ] = F_70 ( sizeof( struct V_342 ) , V_125 ) ;
if ( V_7 -> V_78 . V_333 [ V_9 ] ) {
V_7 -> V_78 . V_333 [ V_9 ] -> V_142 = V_334 [ V_9 ] ;
V_7 -> V_78 . V_333 [ V_9 ] -> V_343 = V_9 ;
}
}
} else if ( F_137 ( V_7 ) ) {
V_7 -> V_78 . V_333 [ 0 ] = F_70 ( sizeof( struct V_342 ) , V_125 ) ;
if ( V_7 -> V_78 . V_333 [ 0 ] ) {
V_7 -> V_78 . V_333 [ 0 ] -> V_142 = V_344 ;
V_7 -> V_78 . V_333 [ 0 ] -> V_343 = 0 ;
}
V_7 -> V_78 . V_333 [ 1 ] = F_70 ( sizeof( struct V_342 ) , V_125 ) ;
if ( V_7 -> V_78 . V_333 [ 1 ] ) {
V_7 -> V_78 . V_333 [ 1 ] -> V_142 = V_345 ;
V_7 -> V_78 . V_333 [ 1 ] -> V_343 = 1 ;
}
} else if ( F_138 ( V_7 ) ) {
V_7 -> V_78 . V_333 [ 0 ] = F_70 ( sizeof( struct V_342 ) , V_125 ) ;
if ( V_7 -> V_78 . V_333 [ 0 ] ) {
V_7 -> V_78 . V_333 [ 0 ] -> V_142 = V_346 ;
V_7 -> V_78 . V_333 [ 0 ] -> V_343 = 0 ;
}
if ( V_7 -> V_157 >= V_347 ) {
V_7 -> V_78 . V_333 [ 1 ] = F_70 ( sizeof( struct V_342 ) , V_125 ) ;
if ( V_7 -> V_78 . V_333 [ 1 ] ) {
V_7 -> V_78 . V_333 [ 1 ] -> V_142 = V_348 ;
V_7 -> V_78 . V_333 [ 1 ] -> V_343 = 1 ;
}
}
}
}
static void F_139 ( struct V_6 * V_7 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_332 ; V_9 ++ ) {
F_36 ( V_7 -> V_78 . V_333 [ V_9 ] ) ;
V_7 -> V_78 . V_333 [ V_9 ] = NULL ;
}
}
int F_140 ( struct V_6 * V_7 )
{
int V_9 ;
int V_150 ;
F_141 ( V_7 -> V_85 ) ;
V_7 -> V_78 . V_349 = true ;
V_7 -> V_85 -> V_165 . V_350 = & V_351 ;
if ( V_84 == 2 && V_7 -> V_157 >= V_347 )
V_7 -> V_85 -> V_165 . V_352 = true ;
if ( F_27 ( V_7 ) ) {
V_7 -> V_85 -> V_165 . V_353 = 16384 ;
V_7 -> V_85 -> V_165 . V_354 = 16384 ;
} else if ( F_29 ( V_7 ) ) {
V_7 -> V_85 -> V_165 . V_353 = 8192 ;
V_7 -> V_85 -> V_165 . V_354 = 8192 ;
} else {
V_7 -> V_85 -> V_165 . V_353 = 4096 ;
V_7 -> V_85 -> V_165 . V_354 = 4096 ;
}
V_7 -> V_85 -> V_165 . V_355 = 24 ;
V_7 -> V_85 -> V_165 . V_356 = 1 ;
V_7 -> V_85 -> V_165 . V_357 = V_7 -> V_358 . V_359 ;
V_150 = F_126 ( V_7 ) ;
if ( V_150 ) {
return V_150 ;
}
F_142 ( V_7 ) ;
if ( ! V_7 -> V_168 ) {
F_143 ( V_7 ) ;
}
for ( V_9 = 0 ; V_9 < V_7 -> V_360 ; V_9 ++ ) {
F_87 ( V_7 -> V_85 , V_9 ) ;
}
V_150 = F_97 ( V_7 -> V_85 ) ;
if ( ! V_150 ) {
return V_150 ;
}
if ( V_7 -> V_168 ) {
F_144 ( V_7 ) ;
F_145 ( V_7 ) ;
}
F_146 ( V_7 ) ;
F_132 ( V_7 ) ;
F_147 ( V_7 ) ;
F_148 ( V_7 -> V_85 ) ;
V_150 = F_149 ( V_7 ) ;
return 0 ;
}
void F_150 ( struct V_6 * V_7 )
{
F_151 ( V_7 ) ;
F_36 ( V_7 -> V_78 . V_361 ) ;
F_152 ( V_7 ) ;
if ( V_7 -> V_78 . V_349 ) {
F_139 ( V_7 ) ;
F_153 ( V_7 -> V_85 ) ;
F_154 ( V_7 ) ;
F_155 ( V_7 -> V_85 ) ;
F_156 ( V_7 -> V_85 ) ;
V_7 -> V_78 . V_349 = false ;
}
}
static bool F_157 ( const struct V_362 * V_363 )
{
if ( ( V_363 -> V_364 == 480 && V_363 -> V_365 == 720 ) ||
( V_363 -> V_364 == 576 ) ||
( V_363 -> V_364 == 720 ) ||
( V_363 -> V_364 == 1080 ) )
return true ;
else
return false ;
}
bool F_158 ( struct V_1 * V_2 ,
const struct V_362 * V_363 ,
struct V_362 * V_366 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_172 * V_173 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_174 * V_174 ;
struct V_154 * V_170 ;
struct V_171 * V_171 ;
bool V_367 = true ;
T_3 V_368 = 1 , V_369 = 1 ;
T_3 V_370 = 1 , V_371 = 1 ;
V_3 -> V_372 = 0 ;
V_3 -> V_373 = 0 ;
F_84 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_173 -> V_2 != V_2 )
continue;
V_174 = F_96 ( V_173 ) ;
V_170 = F_159 ( V_173 ) ;
V_171 = F_95 ( V_170 ) ;
if ( V_367 ) {
if ( V_174 -> V_374 == V_375 )
V_3 -> V_374 = V_375 ;
else if ( V_363 -> V_365 < V_174 -> V_376 . V_365 ||
V_363 -> V_364 < V_174 -> V_376 . V_364 )
V_3 -> V_374 = V_174 -> V_374 ;
else
V_3 -> V_374 = V_375 ;
memcpy ( & V_3 -> V_376 ,
& V_174 -> V_376 ,
sizeof( struct V_362 ) ) ;
V_368 = V_2 -> V_363 . V_364 ;
V_369 = V_3 -> V_376 . V_364 ;
V_370 = V_2 -> V_363 . V_365 ;
V_371 = V_3 -> V_376 . V_365 ;
if ( F_29 ( V_7 ) &&
( ! ( V_363 -> V_80 & V_377 ) ) &&
( ( V_174 -> V_378 == V_379 ) ||
( ( V_174 -> V_378 == V_380 ) &&
F_160 ( F_161 ( V_170 ) ) &&
F_157 ( V_363 ) ) ) ) {
if ( V_174 -> V_381 != 0 )
V_3 -> V_372 = V_174 -> V_381 ;
else
V_3 -> V_372 = ( V_363 -> V_365 >> 5 ) + 16 ;
if ( V_174 -> V_382 != 0 )
V_3 -> V_373 = V_174 -> V_382 ;
else
V_3 -> V_373 = ( V_363 -> V_364 >> 5 ) + 16 ;
V_3 -> V_374 = V_383 ;
V_368 = V_2 -> V_363 . V_364 ;
V_369 = V_2 -> V_363 . V_364 - ( V_3 -> V_373 * 2 ) ;
V_370 = V_2 -> V_363 . V_365 ;
V_371 = V_2 -> V_363 . V_365 - ( V_3 -> V_372 * 2 ) ;
}
V_367 = false ;
} else {
if ( V_3 -> V_374 != V_174 -> V_374 ) {
F_43 ( L_52 ) ;
return false ;
}
}
}
if ( V_3 -> V_374 != V_375 ) {
T_5 V_384 , V_385 ;
V_384 . V_386 = F_162 ( V_368 ) ;
V_385 . V_386 = F_162 ( V_369 ) ;
V_3 -> V_387 . V_386 = F_163 ( V_384 , V_385 ) ;
V_384 . V_386 = F_162 ( V_370 ) ;
V_385 . V_386 = F_162 ( V_371 ) ;
V_3 -> V_388 . V_386 = F_163 ( V_384 , V_385 ) ;
} else {
V_3 -> V_387 . V_386 = F_162 ( 1 ) ;
V_3 -> V_388 . V_386 = F_162 ( 1 ) ;
}
return true ;
}
int F_51 ( struct V_4 * V_5 , unsigned int V_389 ,
unsigned int V_80 , int * V_82 , int * V_83 ,
T_6 * V_390 , T_6 * V_391 ,
const struct V_362 * V_363 )
{
T_3 V_392 = 0 , V_393 = 0 , V_394 = 0 ;
int V_395 , V_396 , V_397 , V_150 = 0 ;
bool V_398 = true ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_390 )
* V_390 = F_164 () ;
if ( F_28 ( V_7 ) ) {
if ( V_389 == 0 ) {
V_393 = F_25 ( V_399 +
V_335 ) ;
V_394 = F_25 ( V_400 +
V_335 ) ;
V_150 |= V_89 ;
}
if ( V_389 == 1 ) {
V_393 = F_25 ( V_399 +
V_336 ) ;
V_394 = F_25 ( V_400 +
V_336 ) ;
V_150 |= V_89 ;
}
if ( V_389 == 2 ) {
V_393 = F_25 ( V_399 +
V_337 ) ;
V_394 = F_25 ( V_400 +
V_337 ) ;
V_150 |= V_89 ;
}
if ( V_389 == 3 ) {
V_393 = F_25 ( V_399 +
V_338 ) ;
V_394 = F_25 ( V_400 +
V_338 ) ;
V_150 |= V_89 ;
}
if ( V_389 == 4 ) {
V_393 = F_25 ( V_399 +
V_339 ) ;
V_394 = F_25 ( V_400 +
V_339 ) ;
V_150 |= V_89 ;
}
if ( V_389 == 5 ) {
V_393 = F_25 ( V_399 +
V_340 ) ;
V_394 = F_25 ( V_400 +
V_340 ) ;
V_150 |= V_89 ;
}
} else if ( F_29 ( V_7 ) ) {
if ( V_389 == 0 ) {
V_393 = F_25 ( V_401 ) ;
V_394 = F_25 ( V_402 ) ;
V_150 |= V_89 ;
}
if ( V_389 == 1 ) {
V_393 = F_25 ( V_403 ) ;
V_394 = F_25 ( V_404 ) ;
V_150 |= V_89 ;
}
} else {
if ( V_389 == 0 ) {
V_393 = ( F_25 ( V_405 ) &
V_406 ) >> V_407 ;
V_394 = ( F_25 ( V_408 ) >> 16 ) & V_409 ;
V_392 = F_25 ( V_410 ) ;
if ( ! ( V_392 & 1 ) )
V_398 = false ;
V_150 |= V_89 ;
}
if ( V_389 == 1 ) {
V_393 = ( F_25 ( V_411 ) &
V_406 ) >> V_407 ;
V_394 = ( F_25 ( V_412 ) >> 16 ) & V_409 ;
V_392 = F_25 ( V_413 ) ;
if ( ! ( V_392 & 1 ) )
V_398 = false ;
V_150 |= V_89 ;
}
}
if ( V_391 )
* V_391 = F_164 () ;
* V_82 = V_394 & 0x1fff ;
* V_83 = ( V_394 >> 16 ) & 0x1fff ;
if ( V_393 > 0 ) {
V_150 |= V_108 ;
V_395 = V_393 & 0x1fff ;
V_396 = ( V_393 >> 16 ) & 0x1fff ;
}
else {
V_395 = V_363 -> V_93 ;
V_396 = 0 ;
}
if ( V_80 & V_107 ) {
* V_83 = * V_82 - V_395 ;
}
if ( ! ( V_80 & V_90 ) )
V_395 -= V_7 -> V_78 . V_79 [ V_389 ] -> V_414 ;
if ( ( * V_82 < V_395 ) && ( * V_82 >= V_396 ) )
V_398 = false ;
if ( V_398 )
V_150 |= V_415 ;
if ( V_80 & V_107 ) {
* V_82 -= V_395 ;
return V_150 ;
}
if ( V_398 && ( * V_82 >= V_395 ) ) {
V_397 = V_363 -> V_416 ;
* V_82 = * V_82 - V_397 ;
}
* V_82 = * V_82 - V_396 ;
return V_150 ;
}
