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
if ( ( V_6 > V_2 -> V_11 -> V_41 + V_42 + V_43 ) ||
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
T_3 V_44 )
{
int V_45 ;
int V_46 = F_25 ( V_35 ) ;
int V_47 = F_26 ( V_35 ) ;
V_37 V_48 ;
V_37 V_49 = 0xffff0000 ;
V_45 = ( ( V_35 -> V_38 + 4 ) & ( V_2 -> V_50 - 1 ) ) ? 0 : 4 ;
if ( ( ! F_27 ( V_35 ) ) &&
( ( V_46 + V_47 ) >= ( 4 + V_45 ) ) ) {
if ( ( V_46 < 4 ) || ( V_47 < V_45 ) ) {
V_35 -> V_7 = memmove ( V_35 -> V_51 + 4 , V_35 -> V_7 , V_35 -> V_38 ) ;
F_28 ( V_35 , V_35 -> V_38 ) ;
}
} else {
struct V_34 * V_52 ;
V_52 = F_29 ( V_35 , 4 , V_45 , V_44 ) ;
F_30 ( V_35 ) ;
V_35 = V_52 ;
if ( ! V_35 )
return NULL ;
}
F_31 ( V_35 , 4 ) ;
V_48 = ( ( ( V_35 -> V_38 - 4 ) ^ 0x0000ffff ) << 16 ) + ( V_35 -> V_38 - 4 ) ;
F_32 ( & V_48 ) ;
F_33 ( V_35 , & V_48 , sizeof( V_48 ) ) ;
if ( V_45 ) {
F_32 ( & V_49 ) ;
memcpy ( F_34 ( V_35 ) , & V_49 , sizeof( V_49 ) ) ;
F_22 ( V_35 , sizeof( V_49 ) ) ;
}
return V_35 ;
}
static void F_35 ( struct V_1 * V_2 , struct V_22 * V_22 )
{
struct V_53 * V_54 ;
int V_55 ;
if ( V_22 -> V_56 < 8 )
return;
V_54 = V_22 -> V_57 ;
V_55 = V_54 -> V_55 & 0x01 ;
if ( F_36 ( V_2 -> V_11 ) != V_55 ) {
if ( V_55 ) {
F_37 ( V_2 -> V_11 ) ;
F_38 ( V_2 , V_58 ) ;
} else
F_39 ( V_2 -> V_11 ) ;
F_2 ( V_2 -> V_11 , L_11 , V_55 ) ;
}
}
static inline int F_40 ( struct V_1 * V_2 )
{
int V_59 ;
V_59 = F_7 ( V_2 , V_60 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_59 < 0 )
F_15 ( V_2 -> V_11 , L_12 ) ;
return V_59 ;
}
static inline int F_41 ( struct V_1 * V_2 )
{
int V_59 ;
V_59 = F_7 ( V_2 , V_61 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_59 < 0 )
F_15 ( V_2 -> V_11 , L_13 ) ;
return V_59 ;
}
static inline int F_42 ( struct V_1 * V_2 )
{
T_1 V_8 [ 2 ] ;
int V_59 = F_1 ( V_2 , V_62 , 0 , 0 , 2 , V_8 ) ;
F_2 ( V_2 -> V_11 , L_14 ) ;
if ( V_59 < 0 ) {
F_15 ( V_2 -> V_11 , L_15 , V_59 ) ;
goto V_13;
}
F_2 ( V_2 -> V_11 , L_16 ,
* ( ( V_63 * ) V_8 ) ) ;
V_59 = V_8 [ 1 ] ;
V_13:
return V_59 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_44 )
{
int V_59 ;
V_59 = F_7 ( V_2 , V_64 , V_44 , 0 , 0 , NULL ) ;
if ( V_59 < 0 )
F_15 ( V_2 -> V_11 , L_17 , V_59 ) ;
return V_59 ;
}
static T_2 F_44 ( struct V_1 * V_2 )
{
V_63 V_65 ;
int V_59 = F_1 ( V_2 , V_66 , 0 , 0 , 2 , & V_65 ) ;
if ( V_59 < 0 ) {
F_15 ( V_2 -> V_11 , L_18 , V_59 ) ;
goto V_13;
}
V_59 = F_45 ( V_65 ) ;
V_13:
return V_59 ;
}
static int F_46 ( struct V_1 * V_2 , T_2 V_67 )
{
int V_59 ;
F_2 ( V_2 -> V_11 , L_19 , V_67 ) ;
V_59 = F_7 ( V_2 , V_68 , V_67 , 0 , 0 , NULL ) ;
if ( V_59 < 0 )
F_15 ( V_2 -> V_11 , L_20 ,
V_67 , V_59 ) ;
return V_59 ;
}
static T_2 F_47 ( struct V_1 * V_2 )
{
V_63 V_65 ;
int V_59 = F_1 ( V_2 , V_69 , 0 , 0 , 2 , & V_65 ) ;
if ( V_59 < 0 ) {
F_15 ( V_2 -> V_11 , L_21 ,
V_59 ) ;
return V_59 ;
}
return F_45 ( V_65 ) ;
}
static int F_48 ( struct V_1 * V_2 , T_2 V_67 )
{
int V_59 ;
F_2 ( V_2 -> V_11 , L_22 , V_67 ) ;
V_59 = F_7 ( V_2 , V_70 , V_67 , 0 , 0 , NULL ) ;
if ( V_59 < 0 )
F_15 ( V_2 -> V_11 , L_23 ,
V_67 , V_59 ) ;
return V_59 ;
}
static int F_49 ( struct V_1 * V_2 , T_2 V_4 , int V_71 )
{
int V_59 ;
F_2 ( V_2 -> V_11 , L_24 , V_4 ) ;
V_59 = F_7 ( V_2 , V_72 , V_4 , 0 , 0 , NULL ) ;
if ( V_59 < 0 )
F_15 ( V_2 -> V_11 , L_25 ,
V_4 , V_59 ) ;
if ( V_71 )
F_50 ( V_71 ) ;
return V_59 ;
}
static void F_51 ( struct V_73 * V_11 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
T_2 V_75 = V_76 ;
if ( V_11 -> V_44 & V_77 ) {
V_75 |= V_78 ;
} else if ( V_11 -> V_44 & V_79 ||
F_53 ( V_11 ) > V_80 ) {
V_75 |= V_81 ;
} else if ( F_54 ( V_11 ) ) {
} else {
struct V_82 * V_83 ;
V_37 V_84 ;
memset ( V_7 -> V_85 , 0 , V_86 ) ;
F_55 (ha, net) {
V_84 = F_56 ( V_87 , V_83 -> V_88 ) >> 26 ;
V_7 -> V_85 [ V_84 >> 3 ] |=
1 << ( V_84 & 7 ) ;
}
F_13 ( V_2 , V_89 , 0 , 0 ,
V_86 , V_7 -> V_85 ) ;
V_75 |= V_90 ;
}
F_13 ( V_2 , V_68 , V_75 , 0 , 0 , NULL ) ;
}
static int F_57 ( struct V_73 * V_91 , int V_92 , int V_93 )
{
struct V_1 * V_2 = F_52 ( V_91 ) ;
V_63 V_94 ;
F_58 ( & V_2 -> V_95 ) ;
F_40 ( V_2 ) ;
F_1 ( V_2 , V_96 , V_92 ,
( V_97 ) V_93 , 2 , & V_94 ) ;
F_41 ( V_2 ) ;
F_59 ( & V_2 -> V_95 ) ;
F_2 ( V_2 -> V_11 , L_26 ,
V_92 , V_93 , F_45 ( V_94 ) ) ;
return F_45 ( V_94 ) ;
}
static void
F_60 ( struct V_73 * V_91 , int V_92 , int V_93 , int V_98 )
{
struct V_1 * V_2 = F_52 ( V_91 ) ;
V_63 V_94 = F_16 ( V_98 ) ;
F_2 ( V_2 -> V_11 , L_27 ,
V_92 , V_93 , V_98 ) ;
F_58 ( & V_2 -> V_95 ) ;
F_40 ( V_2 ) ;
F_7 ( V_2 , V_99 , V_92 , ( V_97 ) V_93 , 2 , & V_94 ) ;
F_41 ( V_2 ) ;
F_59 ( & V_2 -> V_95 ) ;
}
static V_37 F_61 ( struct V_1 * V_2 )
{
int V_100 ;
V_37 V_92 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < 100 ; V_101 ++ ) {
V_100 = F_57 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_103 ) ;
if ( V_100 != 0 && V_100 != 0xFFFF )
break;
F_62 ( 1 ) ;
}
if ( V_100 <= 0 || V_100 == 0xFFFF )
return 0 ;
V_92 = ( V_100 & 0xffff ) << 16 ;
V_100 = F_57 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_104 ) ;
if ( V_100 < 0 )
return 0 ;
V_92 |= ( V_100 & 0xffff ) ;
return V_92 ;
}
static void
F_63 ( struct V_73 * V_11 , struct V_105 * V_106 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
T_1 V_107 ;
if ( F_1 ( V_2 , V_108 , 0 , 0 , 1 , & V_107 ) < 0 ) {
V_106 -> V_109 = 0 ;
V_106 -> V_110 = 0 ;
return;
}
V_106 -> V_109 = V_111 | V_112 ;
V_106 -> V_110 = 0 ;
if ( V_107 & V_113 )
V_106 -> V_110 |= V_111 ;
if ( V_107 & V_114 )
V_106 -> V_110 |= V_112 ;
}
static int
F_64 ( struct V_73 * V_11 , struct V_105 * V_106 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
T_1 V_107 = 0 ;
if ( V_106 -> V_110 & V_111 )
V_107 |= V_113 ;
if ( V_106 -> V_110 & V_112 )
V_107 |= V_114 ;
if ( F_7 ( V_2 , V_115 ,
V_107 , 0 , 0 , NULL ) < 0 )
return - V_19 ;
return 0 ;
}
static int F_65 ( struct V_73 * V_11 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
return V_7 -> V_116 ;
}
static int F_66 ( struct V_73 * V_11 ,
struct V_117 * V_118 , T_1 * V_7 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
V_63 * V_119 = ( V_63 * ) V_7 ;
int V_101 ;
if ( V_118 -> V_38 % 2 )
return - V_19 ;
V_118 -> V_120 = V_121 ;
for ( V_101 = 0 ; V_101 < V_118 -> V_38 / 2 ; V_101 ++ ) {
if ( F_1 ( V_2 , V_122 ,
V_118 -> V_36 + V_101 , 0 , 2 , & V_119 [ V_101 ] ) < 0 )
return - V_19 ;
}
return 0 ;
}
static void F_67 ( struct V_73 * V_11 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
F_68 ( V_11 , V_124 ) ;
strncpy ( V_124 -> V_125 , V_126 , sizeof V_124 -> V_125 ) ;
strncpy ( V_124 -> V_127 , V_128 , sizeof V_124 -> V_127 ) ;
V_124 -> V_129 = V_7 -> V_116 ;
}
static V_37 F_69 ( struct V_73 * V_11 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
return F_70 ( & V_2 -> V_102 ) ;
}
static int F_71 ( struct V_73 * V_11 , struct V_130 * V_131 , int V_3 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
return F_72 ( & V_2 -> V_102 , F_73 ( V_131 ) , V_3 , NULL ) ;
}
static int F_74 ( struct V_73 * V_11 , void * V_132 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
struct V_133 * V_88 = V_132 ;
if ( F_75 ( V_11 ) )
return - V_134 ;
if ( ! F_76 ( V_88 -> V_135 ) )
return - V_136 ;
memcpy ( V_11 -> V_137 , V_88 -> V_135 , V_87 ) ;
memcpy ( V_7 -> V_138 , V_88 -> V_135 , V_87 ) ;
F_13 ( V_2 , V_139 , 0 , 0 , V_87 ,
V_7 -> V_138 ) ;
return 0 ;
}
static void F_77 ( struct V_73 * V_11 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
T_1 V_75 = 0x8c ;
if ( V_11 -> V_44 & V_77 ) {
V_75 |= 0x01 ;
} else if ( V_11 -> V_44 & V_79 ||
F_53 ( V_11 ) > V_80 ) {
V_75 |= 0x02 ;
} else if ( F_54 ( V_11 ) ) {
} else {
struct V_82 * V_83 ;
V_37 V_84 ;
memset ( V_7 -> V_85 , 0 , V_86 ) ;
F_55 (ha, net) {
V_84 = F_56 ( V_87 , V_83 -> V_88 ) >> 26 ;
V_7 -> V_85 [ V_84 >> 3 ] |=
1 << ( V_84 & 7 ) ;
}
F_13 ( V_2 , V_89 , 0 , 0 ,
V_86 , V_7 -> V_85 ) ;
V_75 |= 0x10 ;
}
F_13 ( V_2 , V_68 , V_75 , 0 , 0 , NULL ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
T_1 V_67 ;
struct V_140 V_141 = { . V_3 = V_142 } ;
F_79 ( & V_2 -> V_102 , 1 , 1 ) ;
F_80 ( & V_2 -> V_102 , & V_141 ) ;
V_67 = V_143 ;
if ( V_141 . V_144 != V_145 )
V_67 |= ~ V_146 ;
F_2 ( V_2 -> V_11 , L_28 ,
F_81 ( & V_141 ) , V_141 . V_144 , V_67 ) ;
F_48 ( V_2 , V_67 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
int V_59 = 0 ;
T_1 V_8 [ V_87 ] ;
int V_101 ;
unsigned long V_149 = V_2 -> V_150 -> V_7 ;
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
V_7 -> V_116 = V_151 ;
F_83 ( V_2 , V_148 ) ;
for ( V_101 = 2 ; V_101 >= 0 ; V_101 -- ) {
V_59 = F_7 ( V_2 , V_72 ,
( V_149 >> ( V_101 * 8 ) ) & 0xff , 0 , 0 , NULL ) ;
if ( V_59 < 0 )
goto V_13;
F_50 ( 5 ) ;
}
V_59 = F_46 ( V_2 , 0x80 ) ;
if ( V_59 < 0 )
goto V_13;
V_59 = F_1 ( V_2 , V_152 , 0 , 0 , V_87 , V_8 ) ;
if ( V_59 < 0 ) {
F_84 ( L_29 , V_59 ) ;
goto V_13;
}
memcpy ( V_2 -> V_11 -> V_137 , V_8 , V_87 ) ;
V_2 -> V_102 . V_2 = V_2 -> V_11 ;
V_2 -> V_102 . V_153 = F_57 ;
V_2 -> V_102 . V_154 = F_60 ;
V_2 -> V_102 . V_155 = 0x3f ;
V_2 -> V_102 . V_156 = 0x1f ;
V_2 -> V_102 . V_92 = F_42 ( V_2 ) ;
V_2 -> V_11 -> V_157 = & V_158 ;
V_2 -> V_11 -> V_159 = & V_160 ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_161 , V_162 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_163 ,
V_164 | V_165 | V_166 ) ;
F_85 ( & V_2 -> V_102 ) ;
return 0 ;
V_13:
return V_59 ;
}
static int F_86 ( struct V_1 * V_2 )
{
T_2 V_67 ;
struct V_140 V_141 = { . V_3 = V_142 } ;
F_79 ( & V_2 -> V_102 , 1 , 1 ) ;
F_80 ( & V_2 -> V_102 , & V_141 ) ;
V_67 = V_167 ;
if ( F_81 ( & V_141 ) != V_168 )
V_67 &= ~ V_169 ;
if ( V_141 . V_144 != V_145 )
V_67 &= ~ V_170 ;
F_2 ( V_2 -> V_11 , L_30 ,
F_81 ( & V_141 ) , V_141 . V_144 , V_67 ) ;
F_48 ( V_2 , V_67 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
int V_59 , V_171 ;
T_2 V_75 ;
V_59 = F_49 ( V_2 ,
V_172 | V_173 | V_174 , 5 ) ;
if ( V_59 < 0 )
goto V_13;
V_171 = ( ( F_42 ( V_2 ) & 0x1f ) == 0x10 ? 1 : 0 ) ;
V_59 = F_7 ( V_2 , V_175 , V_171 , 0 , 0 , NULL ) ;
if ( V_59 < 0 ) {
F_84 ( L_31 , V_59 ) ;
goto V_13;
}
V_59 = F_43 ( V_2 , V_176 | V_177 ) ;
if ( V_59 < 0 )
goto V_13;
F_50 ( 150 ) ;
V_59 = F_43 ( V_2 , V_178 ) ;
if ( V_59 < 0 )
goto V_13;
F_50 ( 150 ) ;
if ( V_171 ) {
V_59 = F_43 ( V_2 , V_179 ) ;
if ( V_59 < 0 )
goto V_13;
} else {
V_59 = F_43 ( V_2 , V_180 ) ;
if ( V_59 < 0 )
goto V_13;
}
F_50 ( 150 ) ;
V_75 = F_44 ( V_2 ) ;
F_84 ( L_32 , V_75 ) ;
V_59 = F_46 ( V_2 , 0x0000 ) ;
if ( V_59 < 0 )
goto V_13;
V_75 = F_44 ( V_2 ) ;
F_84 ( L_33 , V_75 ) ;
V_59 = F_43 ( V_2 , V_177 ) ;
if ( V_59 < 0 )
goto V_13;
F_50 ( 150 ) ;
V_59 = F_43 ( V_2 , V_179 | V_177 ) ;
if ( V_59 < 0 )
goto V_13;
F_50 ( 150 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_161 , V_162 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_163 ,
V_164 | V_165 ) ;
F_85 ( & V_2 -> V_102 ) ;
V_59 = F_48 ( V_2 , V_167 ) ;
if ( V_59 < 0 )
goto V_13;
V_59 = F_7 ( V_2 , V_181 ,
V_182 | V_183 ,
V_184 , 0 , NULL ) ;
if ( V_59 < 0 ) {
F_84 ( L_34 , V_59 ) ;
goto V_13;
}
memcpy ( V_7 -> V_138 , V_2 -> V_11 -> V_137 , V_87 ) ;
V_59 = F_7 ( V_2 , V_139 , 0 , 0 , V_87 ,
V_7 -> V_138 ) ;
if ( V_59 < 0 )
goto V_13;
V_59 = F_46 ( V_2 , V_76 ) ;
if ( V_59 < 0 )
goto V_13;
V_75 = F_44 ( V_2 ) ;
F_84 ( L_35 , V_75 ) ;
V_75 = F_47 ( V_2 ) ;
F_84 ( L_36 , V_75 ) ;
return 0 ;
V_13:
return V_59 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
int V_59 , V_171 ;
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
T_1 V_8 [ V_87 ] ;
V_37 V_185 ;
V_7 -> V_116 = V_186 ;
F_83 ( V_2 , V_148 ) ;
V_59 = F_1 ( V_2 , V_187 , 0 , 0 , V_87 , V_8 ) ;
if ( V_59 < 0 ) {
F_84 ( L_37 , V_59 ) ;
return V_59 ;
}
memcpy ( V_2 -> V_11 -> V_137 , V_8 , V_87 ) ;
V_2 -> V_102 . V_2 = V_2 -> V_11 ;
V_2 -> V_102 . V_153 = F_57 ;
V_2 -> V_102 . V_154 = F_60 ;
V_2 -> V_102 . V_155 = 0x1f ;
V_2 -> V_102 . V_156 = 0x1f ;
V_2 -> V_102 . V_92 = F_42 ( V_2 ) ;
V_2 -> V_11 -> V_157 = & V_188 ;
V_2 -> V_11 -> V_159 = & V_189 ;
V_171 = ( ( V_2 -> V_102 . V_92 & 0x1f ) == 0x10 ? 1 : 0 ) ;
V_59 = F_7 ( V_2 , V_175 , V_171 , 0 , 0 , NULL ) ;
if ( V_59 < 0 ) {
F_84 ( L_31 , V_59 ) ;
return V_59 ;
}
V_59 = F_43 ( V_2 , V_176 | V_177 ) ;
if ( V_59 < 0 )
return V_59 ;
F_50 ( 150 ) ;
V_59 = F_43 ( V_2 , V_178 ) ;
if ( V_59 < 0 )
return V_59 ;
F_50 ( 150 ) ;
V_59 = F_43 ( V_2 , V_171 ? V_179 : V_180 ) ;
V_185 = F_61 ( V_2 ) ;
F_84 ( L_38 , V_185 ) ;
if ( V_2 -> V_150 -> V_44 & V_190 ) {
V_2 -> V_191 = 2048 ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
T_2 V_192 ;
F_2 ( V_2 -> V_11 , L_39 ) ;
V_192 = F_57 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_193 ) ;
F_2 ( V_2 -> V_11 , L_40 , V_192 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_194 ,
V_195 | V_196 ) ;
if ( V_7 -> V_197 ) {
V_192 = F_57 ( V_2 -> V_11 , V_2 -> V_102 . V_92 ,
V_198 ) ;
F_2 ( V_2 -> V_11 , L_41 , V_192 ) ;
V_192 &= 0xf8ff ;
V_192 |= ( 1 + 0x0100 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 ,
V_198 , V_192 ) ;
V_192 = F_57 ( V_2 -> V_11 , V_2 -> V_102 . V_92 ,
V_198 ) ;
F_2 ( V_2 -> V_11 , L_42 , V_192 ) ;
V_192 &= 0xfc0f ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
F_2 ( V_2 -> V_11 , L_43 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , 0x1f , 0x0005 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , 0x0c , 0 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , 0x01 ,
F_57 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , 0x01 ) | 0x0080 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , 0x1f , 0 ) ;
if ( V_7 -> V_197 == 12 ) {
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , 0x1f , 0x0002 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , 0x1a , 0x00cb ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , 0x1f , 0 ) ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , T_2 V_199 )
{
T_2 V_192 = F_57 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_200 ) ;
F_2 ( V_2 -> V_11 , L_44 , V_192 ) ;
V_192 &= 0xfc0f ;
switch ( V_199 ) {
case V_201 :
V_192 |= 0x03e0 ;
break;
case V_168 :
V_192 |= 0x03b0 ;
break;
default:
V_192 |= 0x02f0 ;
}
F_2 ( V_2 -> V_11 , L_45 , V_192 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_200 , V_192 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
int V_59 ;
V_63 V_118 ;
T_1 V_26 ;
int V_202 = 0 ;
V_37 V_185 ;
F_1 ( V_2 , V_203 , 0 , 0 , 1 , & V_26 ) ;
F_84 ( L_46 , V_26 ) ;
F_7 ( V_2 , V_204 , 0 , 0 , 0 , NULL ) ;
F_1 ( V_2 , V_122 , 0x0017 , 0 , 2 , & V_118 ) ;
F_7 ( V_2 , V_205 , 0 , 0 , 0 , NULL ) ;
F_84 ( L_47 , V_118 ) ;
if ( V_118 == F_16 ( 0xffff ) ) {
V_7 -> V_206 = V_207 ;
V_7 -> V_197 = 0 ;
V_202 = 1 ;
} else {
V_7 -> V_206 = F_45 ( V_118 ) & 0x7F ;
V_7 -> V_197 = F_45 ( V_118 ) >> 8 ;
V_202 = ( F_45 ( V_118 ) & 0x80 ) ? 0 : 1 ;
}
F_84 ( L_48 , V_202 , V_7 -> V_206 ) ;
F_49 ( V_2 , V_172 | V_208 | V_209 , 40 ) ;
if ( ( F_45 ( V_118 ) >> 8 ) != 1 ) {
F_49 ( V_2 , 0x003c , 30 ) ;
F_49 ( V_2 , 0x001c , 300 ) ;
F_49 ( V_2 , 0x003c , 30 ) ;
} else {
F_84 ( L_49 ) ;
F_49 ( V_2 , V_209 , 30 ) ;
F_49 ( V_2 , V_209 | V_208 , 30 ) ;
}
V_185 = F_61 ( V_2 ) ;
F_84 ( L_38 , V_185 ) ;
F_7 ( V_2 , V_175 , 0 , 0 , 0 , NULL ) ;
F_43 ( V_2 , 0 ) ;
F_50 ( 150 ) ;
F_43 ( V_2 , V_177 | V_176 ) ;
F_50 ( 150 ) ;
F_46 ( V_2 , 0 ) ;
if ( V_7 -> V_206 == V_207 ) {
F_89 ( V_2 ) ;
F_50 ( 60 ) ;
} else if ( V_7 -> V_206 == V_210 )
F_90 ( V_2 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_161 ,
V_162 | V_211 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_163 ,
V_164 | V_165 | V_166 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_102 . V_92 , V_212 ,
V_213 ) ;
F_85 ( & V_2 -> V_102 ) ;
V_59 = F_48 ( V_2 , V_214 ) ;
if ( V_59 < 0 )
return V_59 ;
memcpy ( V_7 -> V_138 , V_2 -> V_11 -> V_137 , V_87 ) ;
V_59 = F_7 ( V_2 , V_139 , 0 , 0 , V_87 ,
V_7 -> V_138 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_46 ( V_2 , V_76 ) ;
if ( V_59 < 0 )
return V_59 ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 )
{
T_2 V_67 ;
struct V_140 V_141 = { . V_3 = V_142 } ;
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
V_37 V_199 ;
F_2 ( V_2 -> V_11 , L_50 ) ;
F_79 ( & V_2 -> V_102 , 1 , 1 ) ;
F_80 ( & V_2 -> V_102 , & V_141 ) ;
V_67 = V_214 ;
V_199 = F_81 ( & V_141 ) ;
if ( V_199 == V_201 )
V_67 |= V_215 ;
else if ( V_199 == V_168 )
V_67 |= V_169 ;
else
V_67 &= ~ ( V_169 | V_215 ) ;
V_67 |= V_216 ;
if ( V_141 . V_144 == V_145 )
V_67 |= V_170 ;
else
V_67 &= ~ V_170 ;
F_2 ( V_2 -> V_11 , L_51 ,
V_199 , V_141 . V_144 , V_67 ) ;
F_48 ( V_2 , V_67 ) ;
if ( V_7 -> V_206 == V_207 && V_7 -> V_197 )
F_91 ( V_2 , V_199 ) ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 )
{
T_2 V_217 = V_218 ;
T_2 V_219 ;
T_2 V_220 ;
int V_221 = V_2 -> V_191 ;
if ( V_2 -> V_222 < 2048 ) {
V_2 -> V_191 = 2048 ;
V_217 = V_223 ;
} else if ( V_2 -> V_222 < 4096 ) {
V_2 -> V_191 = 4096 ;
V_217 = V_224 ;
} else if ( V_2 -> V_222 < 8192 ) {
V_2 -> V_191 = 8192 ;
V_217 = V_225 ;
} else if ( V_2 -> V_222 < 16384 ) {
V_2 -> V_191 = 16384 ;
V_217 = V_218 ;
}
V_219 = F_44 ( V_2 ) ;
F_46 ( V_2 , ( V_219 & ~ V_218 ) | V_217 ) ;
V_220 = F_47 ( V_2 ) ;
if ( V_2 -> V_11 -> V_41 > 1500 )
V_220 |= V_226 ;
else
V_220 &= ~ V_226 ;
F_48 ( V_2 , V_220 ) ;
if ( V_2 -> V_191 > V_221 )
F_95 ( V_2 ) ;
}
static int F_96 ( struct V_73 * V_11 , int V_227 )
{
struct V_1 * V_2 = F_52 ( V_11 ) ;
int V_228 = V_227 + V_11 -> V_229 + 4 ;
F_2 ( V_2 -> V_11 , L_52 , V_227 ) ;
if ( V_227 <= 0 || V_228 > 16384 )
return - V_19 ;
if ( ( V_228 % V_2 -> V_50 ) == 0 )
return - V_230 ;
V_11 -> V_41 = V_227 ;
V_2 -> V_222 = V_11 -> V_41 + V_11 -> V_229 ;
F_94 ( V_2 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
int V_59 ;
T_1 V_8 [ V_87 ] ;
struct V_74 * V_7 = (struct V_74 * ) & V_2 -> V_7 ;
V_7 -> V_116 = V_186 ;
F_83 ( V_2 , V_148 ) ;
V_59 = F_1 ( V_2 , V_187 , 0 , 0 , V_87 , V_8 ) ;
if ( V_59 < 0 ) {
F_84 ( L_37 , V_59 ) ;
return V_59 ;
}
memcpy ( V_2 -> V_11 -> V_137 , V_8 , V_87 ) ;
V_2 -> V_102 . V_2 = V_2 -> V_11 ;
V_2 -> V_102 . V_153 = F_57 ;
V_2 -> V_102 . V_154 = F_60 ;
V_2 -> V_102 . V_155 = 0x1f ;
V_2 -> V_102 . V_156 = 0xff ;
V_2 -> V_102 . V_231 = 1 ;
V_2 -> V_102 . V_92 = F_42 ( V_2 ) ;
V_2 -> V_11 -> V_157 = & V_232 ;
V_2 -> V_11 -> V_159 = & V_233 ;
F_43 ( V_2 , 0 ) ;
F_50 ( 150 ) ;
F_43 ( V_2 , V_177 | V_176 ) ;
F_50 ( 150 ) ;
if ( V_2 -> V_150 -> V_44 & V_190 ) {
V_2 -> V_191 = 2048 ;
}
return 0 ;
}
