static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
void * V_8 ;
int V_9 = - V_10 ;
F_2 ( V_2 -> V_11 , L_1 ,
V_3 , V_4 , V_5 , V_6 ) ;
V_8 = F_3 ( V_6 , V_12 ) ;
if ( ! V_8 )
goto V_13;
V_9 = F_4 (
V_2 -> V_14 ,
F_5 ( V_2 -> V_14 , 0 ) ,
V_3 ,
V_15 | V_16 | V_17 ,
V_4 ,
V_5 ,
V_8 ,
V_6 ,
V_18 ) ;
if ( V_9 == V_6 )
memcpy ( V_7 , V_8 , V_6 ) ;
else if ( V_9 >= 0 )
V_9 = - V_19 ;
F_6 ( V_8 ) ;
V_13:
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
void * V_8 = NULL ;
int V_9 = - V_10 ;
F_2 ( V_2 -> V_11 , L_2 ,
V_3 , V_4 , V_5 , V_6 ) ;
if ( V_7 ) {
V_8 = F_8 ( V_7 , V_6 , V_12 ) ;
if ( ! V_8 )
goto V_13;
}
V_9 = F_4 (
V_2 -> V_14 ,
F_9 ( V_2 -> V_14 , 0 ) ,
V_3 ,
V_20 | V_16 | V_17 ,
V_4 ,
V_5 ,
V_8 ,
V_6 ,
V_21 ) ;
F_6 ( V_8 ) ;
V_13:
return V_9 ;
}
static void F_10 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = (struct V_23 * ) V_22 -> V_25 ;
int V_26 = V_22 -> V_26 ;
if ( V_26 < 0 )
F_11 ( V_27 L_3 ,
V_26 ) ;
F_6 ( V_24 ) ;
F_12 ( V_22 ) ;
}
static void
F_13 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
struct V_23 * V_24 ;
int V_26 ;
struct V_22 * V_22 ;
F_2 ( V_2 -> V_11 , L_4 ,
V_3 , V_4 , V_5 , V_6 ) ;
V_22 = F_14 ( 0 , V_28 ) ;
if ( ! V_22 ) {
F_15 ( V_2 -> V_11 , L_5 ) ;
return;
}
V_24 = F_3 ( sizeof( struct V_23 ) , V_28 ) ;
if ( ! V_24 ) {
F_15 ( V_2 -> V_11 , L_6 ) ;
F_12 ( V_22 ) ;
return;
}
V_24 -> V_29 = V_20 | V_16 | V_17 ;
V_24 -> V_30 = V_3 ;
V_24 -> V_31 = F_16 ( V_4 ) ;
V_24 -> V_32 = F_16 ( V_5 ) ;
V_24 -> V_33 = F_16 ( V_6 ) ;
F_17 ( V_22 , V_2 -> V_14 ,
F_9 ( V_2 -> V_14 , 0 ) ,
( void * ) V_24 , V_7 , V_6 ,
F_10 , V_24 ) ;
V_26 = F_18 ( V_22 , V_28 ) ;
if ( V_26 < 0 ) {
F_15 ( V_2 -> V_11 , L_7 ,
V_26 ) ;
F_6 ( V_24 ) ;
F_12 ( V_22 ) ;
}
}
static int F_19 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
int V_36 = 0 ;
while ( V_36 + sizeof( V_37 ) < V_35 -> V_38 ) {
struct V_34 * V_39 ;
T_2 V_6 ;
V_37 V_40 = F_20 ( V_35 -> V_7 + V_36 ) ;
V_36 += sizeof( V_37 ) ;
V_6 = ( T_2 ) ( V_40 & 0x7ff ) ;
if ( V_6 != ( ( ~ V_40 >> 16 ) & 0x07ff ) ) {
F_15 ( V_2 -> V_11 , L_8 ) ;
return 0 ;
}
if ( ( V_6 > V_2 -> V_11 -> V_41 + V_42 ) ||
( V_6 + V_36 > V_35 -> V_38 ) ) {
F_15 ( V_2 -> V_11 , L_9 ,
V_6 ) ;
return 0 ;
}
V_39 = F_21 ( V_2 -> V_11 , V_6 ) ;
if ( ! V_39 )
return 0 ;
F_22 ( V_39 , V_6 ) ;
memcpy ( V_39 -> V_7 , V_35 -> V_7 + V_36 , V_6 ) ;
F_23 ( V_2 , V_39 ) ;
V_36 += ( V_6 + 1 ) & 0xfffe ;
}
if ( V_35 -> V_38 != V_36 ) {
F_15 ( V_2 -> V_11 , L_10 ,
V_35 -> V_38 ) ;
return 0 ;
}
return 1 ;
}
static struct V_34 * F_24 ( struct V_1 * V_2 , struct V_34 * V_35 ,
T_3 V_43 )
{
int V_44 ;
int V_45 = F_25 ( V_35 ) ;
int V_46 = F_26 ( V_35 ) ;
V_37 V_47 ;
V_37 V_48 = 0xffff0000 ;
V_44 = ( ( V_35 -> V_38 + 4 ) & ( V_2 -> V_49 - 1 ) ) ? 0 : 4 ;
if ( ( ! F_27 ( V_35 ) ) &&
( ( V_45 + V_46 ) >= ( 4 + V_44 ) ) ) {
if ( ( V_45 < 4 ) || ( V_46 < V_44 ) ) {
V_35 -> V_7 = memmove ( V_35 -> V_50 + 4 , V_35 -> V_7 , V_35 -> V_38 ) ;
F_28 ( V_35 , V_35 -> V_38 ) ;
}
} else {
struct V_34 * V_51 ;
V_51 = F_29 ( V_35 , 4 , V_44 , V_43 ) ;
F_30 ( V_35 ) ;
V_35 = V_51 ;
if ( ! V_35 )
return NULL ;
}
F_31 ( V_35 , 4 ) ;
V_47 = ( ( ( V_35 -> V_38 - 4 ) ^ 0x0000ffff ) << 16 ) + ( V_35 -> V_38 - 4 ) ;
F_32 ( & V_47 ) ;
F_33 ( V_35 , & V_47 , sizeof( V_47 ) ) ;
if ( V_44 ) {
F_32 ( & V_48 ) ;
memcpy ( F_34 ( V_35 ) , & V_48 , sizeof( V_48 ) ) ;
F_22 ( V_35 , sizeof( V_48 ) ) ;
}
return V_35 ;
}
static void F_35 ( struct V_1 * V_2 , struct V_22 * V_22 )
{
struct V_52 * V_53 ;
int V_54 ;
if ( V_22 -> V_55 < 8 )
return;
V_53 = V_22 -> V_56 ;
V_54 = V_53 -> V_54 & 0x01 ;
if ( F_36 ( V_2 -> V_11 ) != V_54 ) {
if ( V_54 ) {
F_37 ( V_2 -> V_11 ) ;
F_38 ( V_2 , V_57 ) ;
} else
F_39 ( V_2 -> V_11 ) ;
F_2 ( V_2 -> V_11 , L_11 , V_54 ) ;
}
}
static inline int F_40 ( struct V_1 * V_2 )
{
int V_58 ;
V_58 = F_7 ( V_2 , V_59 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
F_15 ( V_2 -> V_11 , L_12 ) ;
return V_58 ;
}
static inline int F_41 ( struct V_1 * V_2 )
{
int V_58 ;
V_58 = F_7 ( V_2 , V_60 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
F_15 ( V_2 -> V_11 , L_13 ) ;
return V_58 ;
}
static inline int F_42 ( struct V_1 * V_2 )
{
T_1 V_8 [ 2 ] ;
int V_58 = F_1 ( V_2 , V_61 , 0 , 0 , 2 , V_8 ) ;
F_2 ( V_2 -> V_11 , L_14 ) ;
if ( V_58 < 0 ) {
F_15 ( V_2 -> V_11 , L_15 , V_58 ) ;
goto V_13;
}
F_2 ( V_2 -> V_11 , L_16 ,
* ( ( V_62 * ) V_8 ) ) ;
V_58 = V_8 [ 1 ] ;
V_13:
return V_58 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_43 )
{
int V_58 ;
V_58 = F_7 ( V_2 , V_63 , V_43 , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
F_15 ( V_2 -> V_11 , L_17 , V_58 ) ;
return V_58 ;
}
static T_2 F_44 ( struct V_1 * V_2 )
{
V_62 V_64 ;
int V_58 = F_1 ( V_2 , V_65 , 0 , 0 , 2 , & V_64 ) ;
if ( V_58 < 0 ) {
F_15 ( V_2 -> V_11 , L_18 , V_58 ) ;
goto V_13;
}
V_58 = F_45 ( V_64 ) ;
V_13:
return V_58 ;
}
static int F_46 ( struct V_1 * V_2 , T_2 V_66 )
{
int V_58 ;
F_2 ( V_2 -> V_11 , L_19 , V_66 ) ;
V_58 = F_7 ( V_2 , V_67 , V_66 , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
F_15 ( V_2 -> V_11 , L_20 ,
V_66 , V_58 ) ;
return V_58 ;
}
static T_2 F_47 ( struct V_1 * V_2 )
{
V_62 V_64 ;
int V_58 = F_1 ( V_2 , V_68 , 0 , 0 , 2 , & V_64 ) ;
if ( V_58 < 0 ) {
F_15 ( V_2 -> V_11 , L_21 ,
V_58 ) ;
return V_58 ;
}
return F_45 ( V_64 ) ;
}
static int F_48 ( struct V_1 * V_2 , T_2 V_66 )
{
int V_58 ;
F_2 ( V_2 -> V_11 , L_22 , V_66 ) ;
V_58 = F_7 ( V_2 , V_69 , V_66 , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
F_15 ( V_2 -> V_11 , L_23 ,
V_66 , V_58 ) ;
return V_58 ;
}
static int F_49 ( struct V_1 * V_2 , T_2 V_4 , int V_70 )
{
int V_58 ;
F_2 ( V_2 -> V_11 , L_24 , V_4 ) ;
V_58 = F_7 ( V_2 , V_71 , V_4 , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
F_15 ( V_2 -> V_11 , L_25 ,
V_4 , V_58 ) ;
if ( V_70 )
F_50 ( V_70 ) ;
return V_58 ;
}
static void F_51 ( struct V_72 * V_11 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
T_2 V_74 = V_75 ;
if ( V_11 -> V_43 & V_76 ) {
V_74 |= V_77 ;
} else if ( V_11 -> V_43 & V_78 ||
F_53 ( V_11 ) > V_79 ) {
V_74 |= V_80 ;
} else if ( F_54 ( V_11 ) ) {
} else {
struct V_81 * V_82 ;
V_37 V_83 ;
memset ( V_7 -> V_84 , 0 , V_85 ) ;
F_55 (ha, net) {
V_83 = F_56 ( V_86 , V_82 -> V_87 ) >> 26 ;
V_7 -> V_84 [ V_83 >> 3 ] |=
1 << ( V_83 & 7 ) ;
}
F_13 ( V_2 , V_88 , 0 , 0 ,
V_85 , V_7 -> V_84 ) ;
V_74 |= V_89 ;
}
F_13 ( V_2 , V_67 , V_74 , 0 , 0 , NULL ) ;
}
static int F_57 ( struct V_72 * V_90 , int V_91 , int V_92 )
{
struct V_1 * V_2 = F_52 ( V_90 ) ;
V_62 V_93 ;
F_58 ( & V_2 -> V_94 ) ;
F_40 ( V_2 ) ;
F_1 ( V_2 , V_95 , V_91 ,
( V_96 ) V_92 , 2 , & V_93 ) ;
F_41 ( V_2 ) ;
F_59 ( & V_2 -> V_94 ) ;
F_2 ( V_2 -> V_11 , L_26 ,
V_91 , V_92 , F_45 ( V_93 ) ) ;
return F_45 ( V_93 ) ;
}
static void
F_60 ( struct V_72 * V_90 , int V_91 , int V_92 , int V_97 )
{
struct V_1 * V_2 = F_52 ( V_90 ) ;
V_62 V_93 = F_16 ( V_97 ) ;
F_2 ( V_2 -> V_11 , L_27 ,
V_91 , V_92 , V_97 ) ;
F_58 ( & V_2 -> V_94 ) ;
F_40 ( V_2 ) ;
F_7 ( V_2 , V_98 , V_91 , ( V_96 ) V_92 , 2 , & V_93 ) ;
F_41 ( V_2 ) ;
F_59 ( & V_2 -> V_94 ) ;
}
static V_37 F_61 ( struct V_1 * V_2 )
{
int V_99 ;
V_37 V_91 ;
int V_100 ;
for ( V_100 = 0 ; V_100 < 100 ; V_100 ++ ) {
V_99 = F_57 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_102 ) ;
if ( V_99 != 0 && V_99 != 0xFFFF )
break;
F_62 ( 1 ) ;
}
if ( V_99 <= 0 || V_99 == 0xFFFF )
return 0 ;
V_91 = ( V_99 & 0xffff ) << 16 ;
V_99 = F_57 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_103 ) ;
if ( V_99 < 0 )
return 0 ;
V_91 |= ( V_99 & 0xffff ) ;
return V_91 ;
}
static void
F_63 ( struct V_72 * V_11 , struct V_104 * V_105 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
T_1 V_106 ;
if ( F_1 ( V_2 , V_107 , 0 , 0 , 1 , & V_106 ) < 0 ) {
V_105 -> V_108 = 0 ;
V_105 -> V_109 = 0 ;
return;
}
V_105 -> V_108 = V_110 | V_111 ;
V_105 -> V_109 = 0 ;
if ( V_106 & V_112 )
V_105 -> V_109 |= V_110 ;
if ( V_106 & V_113 )
V_105 -> V_109 |= V_111 ;
}
static int
F_64 ( struct V_72 * V_11 , struct V_104 * V_105 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
T_1 V_106 = 0 ;
if ( V_105 -> V_109 & V_110 )
V_106 |= V_112 ;
if ( V_105 -> V_109 & V_111 )
V_106 |= V_113 ;
if ( F_7 ( V_2 , V_114 ,
V_106 , 0 , 0 , NULL ) < 0 )
return - V_19 ;
return 0 ;
}
static int F_65 ( struct V_72 * V_11 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
return V_7 -> V_115 ;
}
static int F_66 ( struct V_72 * V_11 ,
struct V_116 * V_117 , T_1 * V_7 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
V_62 * V_118 = ( V_62 * ) V_7 ;
int V_100 ;
if ( V_117 -> V_38 % 2 )
return - V_19 ;
V_117 -> V_119 = V_120 ;
for ( V_100 = 0 ; V_100 < V_117 -> V_38 / 2 ; V_100 ++ ) {
if ( F_1 ( V_2 , V_121 ,
V_117 -> V_36 + V_100 , 0 , 2 , & V_118 [ V_100 ] ) < 0 )
return - V_19 ;
}
return 0 ;
}
static void F_67 ( struct V_72 * V_11 ,
struct V_122 * V_123 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
F_68 ( V_11 , V_123 ) ;
strncpy ( V_123 -> V_124 , V_125 , sizeof V_123 -> V_124 ) ;
strncpy ( V_123 -> V_126 , V_127 , sizeof V_123 -> V_126 ) ;
V_123 -> V_128 = V_7 -> V_115 ;
}
static V_37 F_69 ( struct V_72 * V_11 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
return F_70 ( & V_2 -> V_101 ) ;
}
static int F_71 ( struct V_72 * V_11 , struct V_129 * V_130 , int V_3 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
return F_72 ( & V_2 -> V_101 , F_73 ( V_130 ) , V_3 , NULL ) ;
}
static int F_74 ( struct V_72 * V_11 , void * V_131 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
struct V_132 * V_87 = V_131 ;
if ( F_75 ( V_11 ) )
return - V_133 ;
if ( ! F_76 ( V_87 -> V_134 ) )
return - V_135 ;
memcpy ( V_11 -> V_136 , V_87 -> V_134 , V_86 ) ;
memcpy ( V_7 -> V_137 , V_87 -> V_134 , V_86 ) ;
F_13 ( V_2 , V_138 , 0 , 0 , V_86 ,
V_7 -> V_137 ) ;
return 0 ;
}
static void F_77 ( struct V_72 * V_11 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
T_1 V_74 = 0x8c ;
if ( V_11 -> V_43 & V_76 ) {
V_74 |= 0x01 ;
} else if ( V_11 -> V_43 & V_78 ||
F_53 ( V_11 ) > V_79 ) {
V_74 |= 0x02 ;
} else if ( F_54 ( V_11 ) ) {
} else {
struct V_81 * V_82 ;
V_37 V_83 ;
memset ( V_7 -> V_84 , 0 , V_85 ) ;
F_55 (ha, net) {
V_83 = F_56 ( V_86 , V_82 -> V_87 ) >> 26 ;
V_7 -> V_84 [ V_83 >> 3 ] |=
1 << ( V_83 & 7 ) ;
}
F_13 ( V_2 , V_88 , 0 , 0 ,
V_85 , V_7 -> V_84 ) ;
V_74 |= 0x10 ;
}
F_13 ( V_2 , V_67 , V_74 , 0 , 0 , NULL ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
T_1 V_66 ;
struct V_139 V_140 = { . V_3 = V_141 } ;
F_79 ( & V_2 -> V_101 , 1 , 1 ) ;
F_80 ( & V_2 -> V_101 , & V_140 ) ;
V_66 = V_142 ;
if ( V_140 . V_143 != V_144 )
V_66 |= ~ V_145 ;
F_2 ( V_2 -> V_11 , L_28 ,
F_81 ( & V_140 ) , V_140 . V_143 , V_66 ) ;
F_48 ( V_2 , V_66 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
int V_58 = 0 ;
T_1 V_8 [ V_86 ] ;
int V_100 ;
unsigned long V_148 = V_2 -> V_149 -> V_7 ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
V_7 -> V_115 = V_150 ;
F_83 ( V_2 , V_147 ) ;
for ( V_100 = 2 ; V_100 >= 0 ; V_100 -- ) {
V_58 = F_7 ( V_2 , V_71 ,
( V_148 >> ( V_100 * 8 ) ) & 0xff , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
goto V_13;
F_50 ( 5 ) ;
}
V_58 = F_46 ( V_2 , 0x80 ) ;
if ( V_58 < 0 )
goto V_13;
V_58 = F_1 ( V_2 , V_151 , 0 , 0 , V_86 , V_8 ) ;
if ( V_58 < 0 ) {
F_84 ( L_29 , V_58 ) ;
goto V_13;
}
memcpy ( V_2 -> V_11 -> V_136 , V_8 , V_86 ) ;
V_2 -> V_101 . V_2 = V_2 -> V_11 ;
V_2 -> V_101 . V_152 = F_57 ;
V_2 -> V_101 . V_153 = F_60 ;
V_2 -> V_101 . V_154 = 0x3f ;
V_2 -> V_101 . V_155 = 0x1f ;
V_2 -> V_101 . V_91 = F_42 ( V_2 ) ;
V_2 -> V_11 -> V_156 = & V_157 ;
V_2 -> V_11 -> V_158 = & V_159 ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_160 , V_161 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_162 ,
V_163 | V_164 | V_165 ) ;
F_85 ( & V_2 -> V_101 ) ;
return 0 ;
V_13:
return V_58 ;
}
static int F_86 ( struct V_1 * V_2 )
{
T_2 V_66 ;
struct V_139 V_140 = { . V_3 = V_141 } ;
F_79 ( & V_2 -> V_101 , 1 , 1 ) ;
F_80 ( & V_2 -> V_101 , & V_140 ) ;
V_66 = V_166 ;
if ( F_81 ( & V_140 ) != V_167 )
V_66 &= ~ V_168 ;
if ( V_140 . V_143 != V_144 )
V_66 &= ~ V_169 ;
F_2 ( V_2 -> V_11 , L_30 ,
F_81 ( & V_140 ) , V_140 . V_143 , V_66 ) ;
F_48 ( V_2 , V_66 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
int V_58 , V_170 ;
T_2 V_74 ;
V_58 = F_49 ( V_2 ,
V_171 | V_172 | V_173 , 5 ) ;
if ( V_58 < 0 )
goto V_13;
V_170 = ( ( F_42 ( V_2 ) & 0x1f ) == 0x10 ? 1 : 0 ) ;
V_58 = F_7 ( V_2 , V_174 , V_170 , 0 , 0 , NULL ) ;
if ( V_58 < 0 ) {
F_84 ( L_31 , V_58 ) ;
goto V_13;
}
V_58 = F_43 ( V_2 , V_175 | V_176 ) ;
if ( V_58 < 0 )
goto V_13;
F_50 ( 150 ) ;
V_58 = F_43 ( V_2 , V_177 ) ;
if ( V_58 < 0 )
goto V_13;
F_50 ( 150 ) ;
if ( V_170 ) {
V_58 = F_43 ( V_2 , V_178 ) ;
if ( V_58 < 0 )
goto V_13;
} else {
V_58 = F_43 ( V_2 , V_179 ) ;
if ( V_58 < 0 )
goto V_13;
}
F_50 ( 150 ) ;
V_74 = F_44 ( V_2 ) ;
F_84 ( L_32 , V_74 ) ;
V_58 = F_46 ( V_2 , 0x0000 ) ;
if ( V_58 < 0 )
goto V_13;
V_74 = F_44 ( V_2 ) ;
F_84 ( L_33 , V_74 ) ;
V_58 = F_43 ( V_2 , V_176 ) ;
if ( V_58 < 0 )
goto V_13;
F_50 ( 150 ) ;
V_58 = F_43 ( V_2 , V_178 | V_176 ) ;
if ( V_58 < 0 )
goto V_13;
F_50 ( 150 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_160 , V_161 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_162 ,
V_163 | V_164 ) ;
F_85 ( & V_2 -> V_101 ) ;
V_58 = F_48 ( V_2 , V_166 ) ;
if ( V_58 < 0 )
goto V_13;
V_58 = F_7 ( V_2 , V_180 ,
V_181 | V_182 ,
V_183 , 0 , NULL ) ;
if ( V_58 < 0 ) {
F_84 ( L_34 , V_58 ) ;
goto V_13;
}
memcpy ( V_7 -> V_137 , V_2 -> V_11 -> V_136 , V_86 ) ;
V_58 = F_7 ( V_2 , V_138 , 0 , 0 , V_86 ,
V_7 -> V_137 ) ;
if ( V_58 < 0 )
goto V_13;
V_58 = F_46 ( V_2 , V_75 ) ;
if ( V_58 < 0 )
goto V_13;
V_74 = F_44 ( V_2 ) ;
F_84 ( L_35 , V_74 ) ;
V_74 = F_47 ( V_2 ) ;
F_84 ( L_36 , V_74 ) ;
return 0 ;
V_13:
return V_58 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
int V_58 , V_170 ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
T_1 V_8 [ V_86 ] ;
V_37 V_184 ;
V_7 -> V_115 = V_185 ;
F_83 ( V_2 , V_147 ) ;
V_58 = F_1 ( V_2 , V_186 , 0 , 0 , V_86 , V_8 ) ;
if ( V_58 < 0 ) {
F_84 ( L_37 , V_58 ) ;
return V_58 ;
}
memcpy ( V_2 -> V_11 -> V_136 , V_8 , V_86 ) ;
V_2 -> V_101 . V_2 = V_2 -> V_11 ;
V_2 -> V_101 . V_152 = F_57 ;
V_2 -> V_101 . V_153 = F_60 ;
V_2 -> V_101 . V_154 = 0x1f ;
V_2 -> V_101 . V_155 = 0x1f ;
V_2 -> V_101 . V_91 = F_42 ( V_2 ) ;
V_2 -> V_11 -> V_156 = & V_187 ;
V_2 -> V_11 -> V_158 = & V_188 ;
V_170 = ( ( V_2 -> V_101 . V_91 & 0x1f ) == 0x10 ? 1 : 0 ) ;
V_58 = F_7 ( V_2 , V_174 , V_170 , 0 , 0 , NULL ) ;
if ( V_58 < 0 ) {
F_84 ( L_31 , V_58 ) ;
return V_58 ;
}
V_58 = F_43 ( V_2 , V_175 | V_176 ) ;
if ( V_58 < 0 )
return V_58 ;
F_50 ( 150 ) ;
V_58 = F_43 ( V_2 , V_177 ) ;
if ( V_58 < 0 )
return V_58 ;
F_50 ( 150 ) ;
V_58 = F_43 ( V_2 , V_170 ? V_178 : V_179 ) ;
V_184 = F_61 ( V_2 ) ;
F_84 ( L_38 , V_184 ) ;
if ( V_2 -> V_149 -> V_43 & V_189 ) {
V_2 -> V_190 = 2048 ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
T_2 V_191 ;
F_2 ( V_2 -> V_11 , L_39 ) ;
V_191 = F_57 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_192 ) ;
F_2 ( V_2 -> V_11 , L_40 , V_191 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_193 ,
V_194 | V_195 ) ;
if ( V_7 -> V_196 ) {
V_191 = F_57 ( V_2 -> V_11 , V_2 -> V_101 . V_91 ,
V_197 ) ;
F_2 ( V_2 -> V_11 , L_41 , V_191 ) ;
V_191 &= 0xf8ff ;
V_191 |= ( 1 + 0x0100 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 ,
V_197 , V_191 ) ;
V_191 = F_57 ( V_2 -> V_11 , V_2 -> V_101 . V_91 ,
V_197 ) ;
F_2 ( V_2 -> V_11 , L_42 , V_191 ) ;
V_191 &= 0xfc0f ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
F_2 ( V_2 -> V_11 , L_43 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , 0x1f , 0x0005 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , 0x0c , 0 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , 0x01 ,
F_57 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , 0x01 ) | 0x0080 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , 0x1f , 0 ) ;
if ( V_7 -> V_196 == 12 ) {
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , 0x1f , 0x0002 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , 0x1a , 0x00cb ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , 0x1f , 0 ) ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , T_2 V_198 )
{
T_2 V_191 = F_57 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_199 ) ;
F_2 ( V_2 -> V_11 , L_44 , V_191 ) ;
V_191 &= 0xfc0f ;
switch ( V_198 ) {
case V_200 :
V_191 |= 0x03e0 ;
break;
case V_167 :
V_191 |= 0x03b0 ;
break;
default:
V_191 |= 0x02f0 ;
}
F_2 ( V_2 -> V_11 , L_45 , V_191 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_199 , V_191 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
int V_58 ;
V_62 V_117 ;
T_1 V_26 ;
int V_201 = 0 ;
V_37 V_184 ;
F_1 ( V_2 , V_202 , 0 , 0 , 1 , & V_26 ) ;
F_84 ( L_46 , V_26 ) ;
F_7 ( V_2 , V_203 , 0 , 0 , 0 , NULL ) ;
F_1 ( V_2 , V_121 , 0x0017 , 0 , 2 , & V_117 ) ;
F_7 ( V_2 , V_204 , 0 , 0 , 0 , NULL ) ;
F_84 ( L_47 , V_117 ) ;
if ( V_117 == F_16 ( 0xffff ) ) {
V_7 -> V_205 = V_206 ;
V_7 -> V_196 = 0 ;
V_201 = 1 ;
} else {
V_7 -> V_205 = F_45 ( V_117 ) & 0x7F ;
V_7 -> V_196 = F_45 ( V_117 ) >> 8 ;
V_201 = ( F_45 ( V_117 ) & 0x80 ) ? 0 : 1 ;
}
F_84 ( L_48 , V_201 , V_7 -> V_205 ) ;
F_49 ( V_2 , V_171 | V_207 | V_208 , 40 ) ;
if ( ( F_45 ( V_117 ) >> 8 ) != 1 ) {
F_49 ( V_2 , 0x003c , 30 ) ;
F_49 ( V_2 , 0x001c , 300 ) ;
F_49 ( V_2 , 0x003c , 30 ) ;
} else {
F_84 ( L_49 ) ;
F_49 ( V_2 , V_208 , 30 ) ;
F_49 ( V_2 , V_208 | V_207 , 30 ) ;
}
V_184 = F_61 ( V_2 ) ;
F_84 ( L_38 , V_184 ) ;
F_7 ( V_2 , V_174 , 0 , 0 , 0 , NULL ) ;
F_43 ( V_2 , 0 ) ;
F_50 ( 150 ) ;
F_43 ( V_2 , V_176 | V_175 ) ;
F_50 ( 150 ) ;
F_46 ( V_2 , 0 ) ;
if ( V_7 -> V_205 == V_206 ) {
F_89 ( V_2 ) ;
F_50 ( 60 ) ;
} else if ( V_7 -> V_205 == V_209 )
F_90 ( V_2 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_160 ,
V_161 | V_210 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_162 ,
V_163 | V_164 | V_165 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_101 . V_91 , V_211 ,
V_212 ) ;
F_85 ( & V_2 -> V_101 ) ;
V_58 = F_48 ( V_2 , V_213 ) ;
if ( V_58 < 0 )
return V_58 ;
memcpy ( V_7 -> V_137 , V_2 -> V_11 -> V_136 , V_86 ) ;
V_58 = F_7 ( V_2 , V_138 , 0 , 0 , V_86 ,
V_7 -> V_137 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_46 ( V_2 , V_75 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 )
{
T_2 V_66 ;
struct V_139 V_140 = { . V_3 = V_141 } ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
V_37 V_198 ;
F_2 ( V_2 -> V_11 , L_50 ) ;
F_79 ( & V_2 -> V_101 , 1 , 1 ) ;
F_80 ( & V_2 -> V_101 , & V_140 ) ;
V_66 = V_213 ;
V_198 = F_81 ( & V_140 ) ;
if ( V_198 == V_200 )
V_66 |= V_214 ;
else if ( V_198 == V_167 )
V_66 |= V_168 ;
else
V_66 &= ~ ( V_168 | V_214 ) ;
V_66 |= V_215 ;
if ( V_140 . V_143 == V_144 )
V_66 |= V_169 ;
else
V_66 &= ~ V_169 ;
F_2 ( V_2 -> V_11 , L_51 ,
V_198 , V_140 . V_143 , V_66 ) ;
F_48 ( V_2 , V_66 ) ;
if ( V_7 -> V_205 == V_206 && V_7 -> V_196 )
F_91 ( V_2 , V_198 ) ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 )
{
T_2 V_216 = V_217 ;
T_2 V_218 ;
T_2 V_219 ;
int V_220 = V_2 -> V_190 ;
if ( V_2 -> V_221 < 2048 ) {
V_2 -> V_190 = 2048 ;
V_216 = V_222 ;
} else if ( V_2 -> V_221 < 4096 ) {
V_2 -> V_190 = 4096 ;
V_216 = V_223 ;
} else if ( V_2 -> V_221 < 8192 ) {
V_2 -> V_190 = 8192 ;
V_216 = V_224 ;
} else if ( V_2 -> V_221 < 16384 ) {
V_2 -> V_190 = 16384 ;
V_216 = V_217 ;
}
V_218 = F_44 ( V_2 ) ;
F_46 ( V_2 , ( V_218 & ~ V_217 ) | V_216 ) ;
V_219 = F_47 ( V_2 ) ;
if ( V_2 -> V_11 -> V_41 > 1500 )
V_219 |= V_225 ;
else
V_219 &= ~ V_225 ;
F_48 ( V_2 , V_219 ) ;
if ( V_2 -> V_190 > V_220 )
F_95 ( V_2 ) ;
}
static int F_96 ( struct V_72 * V_11 , int V_226 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
int V_227 = V_226 + V_11 -> V_228 + 4 ;
F_2 ( V_2 -> V_11 , L_52 , V_226 ) ;
if ( V_226 <= 0 || V_227 > 16384 )
return - V_19 ;
if ( ( V_227 % V_2 -> V_49 ) == 0 )
return - V_229 ;
V_11 -> V_41 = V_226 ;
V_2 -> V_221 = V_11 -> V_41 + V_11 -> V_228 ;
F_94 ( V_2 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
int V_58 ;
T_1 V_8 [ V_86 ] ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
V_7 -> V_115 = V_185 ;
F_83 ( V_2 , V_147 ) ;
V_58 = F_1 ( V_2 , V_186 , 0 , 0 , V_86 , V_8 ) ;
if ( V_58 < 0 ) {
F_84 ( L_37 , V_58 ) ;
return V_58 ;
}
memcpy ( V_2 -> V_11 -> V_136 , V_8 , V_86 ) ;
V_2 -> V_101 . V_2 = V_2 -> V_11 ;
V_2 -> V_101 . V_152 = F_57 ;
V_2 -> V_101 . V_153 = F_60 ;
V_2 -> V_101 . V_154 = 0x1f ;
V_2 -> V_101 . V_155 = 0xff ;
V_2 -> V_101 . V_230 = 1 ;
V_2 -> V_101 . V_91 = F_42 ( V_2 ) ;
V_2 -> V_11 -> V_156 = & V_231 ;
V_2 -> V_11 -> V_158 = & V_232 ;
F_43 ( V_2 , 0 ) ;
F_50 ( 150 ) ;
F_43 ( V_2 , V_176 | V_175 ) ;
F_50 ( 150 ) ;
if ( V_2 -> V_149 -> V_43 & V_189 ) {
V_2 -> V_190 = 2048 ;
}
return 0 ;
}
