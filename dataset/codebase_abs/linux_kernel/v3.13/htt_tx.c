void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -- ;
if ( V_2 -> V_3 == V_2 -> V_4 - 1 )
F_2 ( V_2 -> V_5 -> V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_7 ) ;
F_1 ( V_2 ) ;
F_5 ( & V_2 -> V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
F_4 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_3 >= V_2 -> V_4 ) {
V_8 = - V_9 ;
goto exit;
}
V_2 -> V_3 ++ ;
if ( V_2 -> V_3 == V_2 -> V_4 )
F_7 ( V_2 -> V_5 -> V_6 ) ;
exit:
F_5 ( & V_2 -> V_7 ) ;
return V_8 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_10 ;
F_9 ( & V_2 -> V_7 ) ;
V_10 = F_10 ( V_2 -> V_11 ,
V_2 -> V_4 ) ;
if ( V_10 == V_2 -> V_4 )
return - V_12 ;
F_11 ( V_13 , L_1 , V_10 ) ;
F_12 ( V_10 , V_2 -> V_11 ) ;
return V_10 ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_10 )
{
F_9 ( & V_2 -> V_7 ) ;
if ( ! F_14 ( V_10 , V_2 -> V_11 ) )
F_15 ( L_2 , V_10 ) ;
F_11 ( V_13 , L_3 , V_10 ) ;
F_16 ( V_10 , V_2 -> V_11 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
T_2 V_14 ;
F_18 ( & V_2 -> V_7 ) ;
F_19 ( & V_2 -> V_15 ) ;
V_14 = V_2 -> V_5 -> V_16 . V_17 [ V_2 -> V_18 ] . V_19 ;
V_2 -> V_4 = F_20 ( V_2 -> V_5 ,
V_14 ) ;
F_11 ( V_20 , L_4 ,
V_2 -> V_4 ) ;
V_2 -> V_21 = F_21 ( sizeof( * V_2 -> V_21 ) *
V_2 -> V_4 , V_22 ) ;
if ( ! V_2 -> V_21 )
return - V_23 ;
V_2 -> V_11 = F_21 ( sizeof( unsigned long ) *
F_22 ( V_2 -> V_4 ) ,
V_22 ) ;
if ( ! V_2 -> V_11 ) {
F_23 ( V_2 -> V_21 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_24 V_25 = { 0 } ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_4 ; V_10 ++ ) {
if ( ! F_14 ( V_10 , V_2 -> V_11 ) )
continue;
F_11 ( V_13 , L_5 ,
V_10 ) ;
V_25 . V_26 = 1 ;
V_25 . V_10 = V_10 ;
F_25 ( V_2 , & V_25 ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
F_23 ( V_2 -> V_21 ) ;
F_23 ( V_2 -> V_11 ) ;
return;
}
void F_27 ( struct V_27 * V_5 , struct V_28 * V_29 )
{
F_28 ( V_29 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
int V_32 = 0 ;
int V_8 ;
V_32 += sizeof( V_31 -> V_33 ) ;
V_32 += sizeof( V_31 -> V_34 ) ;
V_29 = F_30 ( V_32 ) ;
if ( ! V_29 )
return - V_23 ;
F_31 ( V_29 , V_32 ) ;
V_31 = (struct V_30 * ) V_29 -> V_35 ;
V_31 -> V_33 . V_36 = V_37 ;
V_8 = F_32 ( & V_2 -> V_5 -> V_16 , V_2 -> V_18 , V_29 ) ;
if ( V_8 ) {
F_28 ( V_29 ) ;
return V_8 ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 , T_2 V_38 , T_3 V_39 )
{
struct V_40 * V_41 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
int V_32 = 0 , V_8 ;
V_32 += sizeof( V_31 -> V_33 ) ;
V_32 += sizeof( V_31 -> V_42 ) ;
V_29 = F_30 ( V_32 ) ;
if ( ! V_29 )
return - V_23 ;
F_31 ( V_29 , V_32 ) ;
V_31 = (struct V_30 * ) V_29 -> V_35 ;
V_31 -> V_33 . V_36 = V_43 ;
V_41 = & V_31 -> V_42 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_44 [ 0 ] = V_38 ;
V_41 -> V_45 [ 0 ] = V_38 ;
V_41 -> V_46 = V_47 ;
V_41 -> V_48 = F_34 ( V_39 & 0xffffffff ) ;
V_41 -> V_49 = F_34 ( ( V_39 & 0xffffffff00000000ULL ) >> 32 ) ;
V_8 = F_32 ( & V_2 -> V_5 -> V_16 , V_2 -> V_18 , V_29 ) ;
if ( V_8 ) {
F_15 ( L_6 , V_8 ) ;
F_28 ( V_29 ) ;
return V_8 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_50 * V_51 ;
const int V_52 = 1 ;
T_1 V_53 ;
T_4 V_54 ;
int V_32 ;
int V_8 ;
F_36 ( ! F_37 ( V_55 , 4 ) ) ;
F_36 ( ( V_55 & V_56 ) != 0 ) ;
V_32 = sizeof( V_31 -> V_33 ) + sizeof( V_31 -> V_57 . V_33 )
+ ( sizeof( * V_51 ) * V_52 ) ;
V_29 = F_30 ( V_32 ) ;
if ( ! V_29 )
return - V_23 ;
F_31 ( V_29 , V_32 ) ;
V_31 = (struct V_30 * ) V_29 -> V_35 ;
V_51 = & V_31 -> V_57 . V_58 [ 0 ] ;
V_31 -> V_33 . V_36 = V_59 ;
V_31 -> V_57 . V_33 . V_60 = 1 ;
V_53 = 0 ;
V_53 |= V_61 ;
V_53 |= V_62 ;
V_53 |= V_63 ;
V_53 |= V_64 ;
V_53 |= V_65 ;
V_53 |= V_66 ;
V_53 |= V_67 ;
V_53 |= V_68 ;
V_53 |= V_69 ;
V_53 |= V_70 ;
V_53 |= V_71 ;
V_53 |= V_72 ;
V_53 |= V_73 ;
V_53 |= V_74 ;
V_53 |= V_75 ;
V_53 |= V_76 ;
V_54 = F_38 ( * V_2 -> V_77 . V_78 . V_79 ) ;
V_51 -> V_80 =
F_39 ( V_2 -> V_77 . V_78 . V_81 ) ;
V_51 -> V_82 = F_39 ( V_2 -> V_77 . V_83 ) ;
V_51 -> V_84 = F_40 ( V_2 -> V_77 . V_85 ) ;
V_51 -> V_86 = F_40 ( V_55 ) ;
V_51 -> V_53 = F_40 ( V_53 ) ;
V_51 -> V_87 = F_40 ( V_54 ) ;
#define F_41 ( T_5 ) (offsetof(struct htt_rx_desc, x) / 4)
V_51 -> V_88 = F_40 ( F_41 ( V_89 ) ) ;
V_51 -> V_90 = F_40 ( F_41 ( V_91 ) ) ;
V_51 -> V_92 = F_40 ( F_41 ( V_93 ) ) ;
V_51 -> V_94 = F_40 ( F_41 ( V_95 ) ) ;
V_51 -> V_96 = F_40 ( F_41 ( V_97 ) ) ;
V_51 -> V_98 = F_40 ( F_41 ( V_99 ) ) ;
V_51 -> V_100 = F_40 ( F_41 ( V_101 ) ) ;
V_51 -> V_102 = F_40 ( F_41 ( V_103 ) ) ;
V_51 -> V_104 = F_40 ( F_41 ( V_105 ) ) ;
V_51 -> V_106 = F_40 ( F_41 ( V_107 ) ) ;
#undef F_41
V_8 = F_32 ( & V_2 -> V_5 -> V_16 , V_2 -> V_18 , V_29 ) ;
if ( V_8 ) {
F_28 ( V_29 ) ;
return V_8 ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 , struct V_28 * V_108 )
{
struct V_109 * V_110 = V_2 -> V_5 -> V_110 ;
struct V_28 * V_111 = NULL ;
struct V_30 * V_31 ;
struct V_112 * V_113 = F_43 ( V_108 ) ;
T_2 V_114 = V_113 -> V_114 ;
int V_32 = 0 ;
int V_10 = - 1 ;
int V_115 ;
V_115 = F_6 ( V_2 ) ;
if ( V_115 )
goto V_116;
V_32 += sizeof( V_31 -> V_33 ) ;
V_32 += sizeof( V_31 -> V_117 ) ;
F_4 ( & V_2 -> V_7 ) ;
V_115 = F_8 ( V_2 ) ;
if ( V_115 < 0 ) {
F_5 ( & V_2 -> V_7 ) ;
goto V_118;
}
V_10 = V_115 ;
V_2 -> V_21 [ V_10 ] = V_108 ;
F_5 ( & V_2 -> V_7 ) ;
V_111 = F_30 ( V_32 ) ;
if ( ! V_111 ) {
V_115 = - V_23 ;
goto V_119;
}
V_115 = F_44 ( V_110 , V_108 ) ;
if ( V_115 )
goto V_120;
F_31 ( V_111 , V_32 ) ;
V_31 = (struct V_30 * ) V_111 -> V_35 ;
V_31 -> V_33 . V_36 = V_121 ;
V_31 -> V_117 . V_122 = F_39 ( F_43 ( V_108 ) -> V_81 ) ;
V_31 -> V_117 . V_32 = F_39 ( V_108 -> V_32 ) ;
V_31 -> V_117 . V_123 = F_39 ( V_10 ) ;
V_31 -> V_117 . V_114 = F_39 ( V_114 ) ;
memcpy ( V_31 -> V_117 . V_33 , V_108 -> V_35 ,
F_45 ( int , V_108 -> V_32 , V_124 ) ) ;
V_113 -> V_2 . V_125 = 0 ;
V_113 -> V_2 . V_126 = 0 ;
V_115 = F_32 ( & V_2 -> V_5 -> V_16 , V_2 -> V_18 , V_111 ) ;
if ( V_115 )
goto V_127;
return 0 ;
V_127:
F_46 ( V_110 , V_108 ) ;
V_120:
F_28 ( V_111 ) ;
V_119:
F_4 ( & V_2 -> V_7 ) ;
V_2 -> V_21 [ V_10 ] = NULL ;
F_13 ( V_2 , V_10 ) ;
F_5 ( & V_2 -> V_7 ) ;
V_118:
F_3 ( V_2 ) ;
V_116:
return V_115 ;
}
int F_47 ( struct V_1 * V_2 , struct V_28 * V_108 )
{
struct V_109 * V_110 = V_2 -> V_5 -> V_110 ;
struct V_30 * V_31 ;
struct V_128 * V_129 ;
struct V_130 * V_33 = (struct V_130 * ) V_108 -> V_35 ;
struct V_112 * V_113 = F_43 ( V_108 ) ;
struct V_28 * V_111 = NULL ;
bool V_131 ;
T_2 V_114 = F_43 ( V_108 ) -> V_114 ;
T_2 V_132 ;
int V_133 , V_134 ;
int V_10 = - 1 ;
int V_115 ;
T_2 V_135 ;
T_1 V_136 ;
V_115 = F_6 ( V_2 ) ;
if ( V_115 )
goto V_116;
F_4 ( & V_2 -> V_7 ) ;
V_115 = F_8 ( V_2 ) ;
if ( V_115 < 0 ) {
F_5 ( & V_2 -> V_7 ) ;
goto V_118;
}
V_10 = V_115 ;
V_2 -> V_21 [ V_10 ] = V_108 ;
F_5 ( & V_2 -> V_7 ) ;
V_133 = F_48 ( V_2 -> V_133 , V_108 -> V_32 ) ;
V_133 = F_49 ( V_133 , 4 ) ;
V_134 = sizeof( V_31 -> V_33 ) + sizeof( V_31 -> V_137 ) + V_133 ;
V_111 = F_30 ( V_134 ) ;
if ( ! V_111 ) {
V_115 = - V_23 ;
goto V_119;
}
V_131 = V_2 -> V_138 < 3 ||
! F_50 ( V_33 -> V_139 ) ;
if ( ! F_37 ( ( unsigned long ) V_111 -> V_35 , 4 ) ) {
F_15 ( L_7 ) ;
V_115 = - V_140 ;
goto V_120;
}
if ( V_131 ) {
V_113 -> V_2 . V_125 = sizeof( * V_129 ) * 2 ;
V_113 -> V_2 . V_126 = ( unsigned long ) V_108 -> V_35 -
F_51 ( ( unsigned long ) V_108 -> V_35 , 4 ) ;
F_52 ( V_108 , V_113 -> V_2 . V_125 + V_113 -> V_2 . V_126 ) ;
} else {
V_113 -> V_2 . V_125 = 0 ;
V_113 -> V_2 . V_126 = 0 ;
}
V_115 = F_44 ( V_110 , V_108 ) ;
if ( V_115 )
goto V_141;
if ( V_131 ) {
F_53 ( V_110 , V_113 -> V_81 , V_108 -> V_32 ,
V_142 ) ;
V_129 = (struct V_128 * ) V_108 -> V_35 ;
V_129 [ 0 ] . V_81 = F_39 ( V_113 -> V_81 +
V_113 -> V_2 . V_125 +
V_113 -> V_2 . V_126 ) ;
V_129 [ 0 ] . V_32 = F_39 ( V_108 -> V_32 -
V_113 -> V_2 . V_125 -
V_113 -> V_2 . V_126 ) ;
V_129 [ 1 ] . V_81 = F_39 ( 0 ) ;
V_129 [ 1 ] . V_32 = F_39 ( 0 ) ;
F_54 ( V_110 , V_113 -> V_81 , V_108 -> V_32 ,
V_142 ) ;
}
F_11 ( V_13 , L_8 ,
( unsigned long long ) F_43 ( V_108 ) -> V_81 ) ;
F_55 ( V_143 , NULL , L_9 ,
V_108 -> V_35 , V_108 -> V_32 ) ;
F_31 ( V_111 , V_134 ) ;
V_31 = (struct V_30 * ) V_111 -> V_35 ;
V_132 = F_43 ( V_108 ) -> V_2 . V_132 ;
F_11 ( V_13 , L_10 , V_132 ) ;
V_135 = 0 ;
if ( ! F_56 ( V_33 -> V_139 ) )
V_135 |= V_144 ;
V_135 |= V_145 ;
if ( V_131 )
V_135 |= F_57 ( V_146 ,
V_147 ) ;
else
V_135 |= F_57 ( V_148 ,
V_147 ) ;
V_136 = 0 ;
V_136 |= F_57 ( ( T_1 ) V_114 , V_149 ) ;
V_136 |= F_57 ( ( T_1 ) V_132 , V_150 ) ;
V_136 |= V_151 ;
V_136 |= V_152 ;
V_31 -> V_33 . V_36 = V_153 ;
V_31 -> V_137 . V_135 = V_135 ;
V_31 -> V_137 . V_136 = F_40 ( V_136 ) ;
V_31 -> V_137 . V_32 = F_40 ( V_108 -> V_32 -
V_113 -> V_2 . V_125 -
V_113 -> V_2 . V_126 ) ;
V_31 -> V_137 . V_154 = F_40 ( V_10 ) ;
V_31 -> V_137 . V_155 = F_39 ( V_113 -> V_81 ) ;
V_31 -> V_137 . V_156 = F_39 ( V_157 ) ;
memcpy ( V_31 -> V_137 . V_158 , V_33 , V_133 ) ;
V_115 = F_32 ( & V_2 -> V_5 -> V_16 , V_2 -> V_18 , V_111 ) ;
if ( V_115 )
goto V_127;
return 0 ;
V_127:
F_46 ( V_110 , V_108 ) ;
V_141:
F_58 ( V_108 , V_113 -> V_2 . V_125 + V_113 -> V_2 . V_126 ) ;
V_120:
F_28 ( V_111 ) ;
V_119:
F_4 ( & V_2 -> V_7 ) ;
V_2 -> V_21 [ V_10 ] = NULL ;
F_13 ( V_2 , V_10 ) ;
F_5 ( & V_2 -> V_7 ) ;
V_118:
F_3 ( V_2 ) ;
V_116:
return V_115 ;
}
