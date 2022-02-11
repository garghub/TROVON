static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
const struct V_3 * V_4 ,
unsigned long * V_5 ,
struct V_6 * V_7 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ) ,
unsigned int log )
{
struct V_6 * V_9 ;
struct V_10 * V_11 ;
F_3 (sk2, node, &hslot->head)
if ( F_4 ( F_5 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
( V_5 || F_6 ( V_9 ) -> V_12 == V_2 ) &&
( ! V_9 -> V_13 || ! V_7 -> V_13 ) &&
( ! V_9 -> V_14 || ! V_7 -> V_14 ||
V_9 -> V_14 == V_7 -> V_14 ) &&
(* F_2)( V_7 , V_9 ) ) {
if ( V_5 )
F_7 ( F_6 ( V_9 ) -> V_12 >> log ,
V_5 ) ;
else
return 1 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_1 , T_1 V_2 ,
struct V_3 * V_15 ,
struct V_6 * V_7 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ) )
{
struct V_6 * V_9 ;
struct V_10 * V_11 ;
int V_16 = 0 ;
F_9 ( & V_15 -> V_17 ) ;
F_10 (sk2, node, &hslot2->head)
if ( F_4 ( F_5 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
( F_6 ( V_9 ) -> V_12 == V_2 ) &&
( ! V_9 -> V_13 || ! V_7 -> V_13 ) &&
( ! V_9 -> V_14 || ! V_7 -> V_14 ||
V_9 -> V_14 == V_7 -> V_14 ) &&
(* F_2)( V_7 , V_9 ) ) {
V_16 = 1 ;
break;
}
F_11 ( & V_15 -> V_17 ) ;
return V_16 ;
}
int F_12 ( struct V_6 * V_7 , unsigned short V_18 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ) ,
unsigned int V_19 )
{
struct V_3 * V_4 , * V_15 ;
struct V_20 * V_21 = V_7 -> V_22 -> V_23 . V_20 ;
int error = 1 ;
struct V_1 * V_1 = F_5 ( V_7 ) ;
if ( ! V_18 ) {
int V_24 , V_25 , V_26 ;
unsigned rand ;
unsigned short V_27 , V_28 ;
F_13 ( V_5 , V_29 ) ;
F_14 ( & V_24 , & V_25 ) ;
V_26 = ( V_25 - V_24 ) + 1 ;
rand = F_15 () ;
V_27 = ( ( ( V_30 ) rand * V_26 ) >> 32 ) + V_24 ;
rand = ( rand | 1 ) * ( V_21 -> V_31 + 1 ) ;
V_28 = V_27 + V_21 -> V_31 + 1 ;
do {
V_4 = F_16 ( V_21 , V_1 , V_27 ) ;
F_17 ( V_5 , V_29 ) ;
F_18 ( & V_4 -> V_17 ) ;
F_1 ( V_1 , V_18 , V_4 , V_5 , V_7 ,
F_2 , V_21 -> log ) ;
V_18 = V_27 ;
do {
if ( V_24 <= V_18 && V_18 <= V_25 &&
! F_19 ( V_18 >> V_21 -> log , V_5 ) &&
! F_20 ( V_18 ) )
goto V_32;
V_18 += rand ;
} while ( V_18 != V_27 );
F_21 ( & V_4 -> V_17 ) ;
} while ( ++ V_27 != V_28 );
goto V_33;
} else {
V_4 = F_16 ( V_21 , V_1 , V_18 ) ;
F_18 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_34 > 10 ) {
int V_35 ;
unsigned int V_36 = F_6 ( V_7 ) -> V_37 ^ V_18 ;
V_36 &= V_21 -> V_31 ;
V_19 &= V_21 -> V_31 ;
V_15 = F_22 ( V_21 , V_36 ) ;
if ( V_4 -> V_34 < V_15 -> V_34 )
goto V_38;
V_35 = F_8 ( V_1 , V_18 , V_15 ,
V_7 , F_2 ) ;
if ( ! V_35 && ( V_19 != V_36 ) ) {
V_15 = F_22 ( V_21 , V_19 ) ;
V_35 = F_8 ( V_1 , V_18 , V_15 ,
V_7 , F_2 ) ;
}
if ( V_35 )
goto V_39;
else
goto V_32;
}
V_38:
if ( F_1 ( V_1 , V_18 , V_4 , NULL , V_7 ,
F_2 , 0 ) )
goto V_39;
}
V_32:
F_23 ( V_7 ) -> V_40 = V_18 ;
F_6 ( V_7 ) -> V_12 = V_18 ;
F_6 ( V_7 ) -> V_37 ^= V_18 ;
if ( F_24 ( V_7 ) ) {
F_25 ( V_7 , & V_4 -> V_41 ) ;
V_4 -> V_34 ++ ;
F_26 ( F_5 ( V_7 ) , V_7 -> V_22 , 1 ) ;
V_15 = F_22 ( V_21 , F_6 ( V_7 ) -> V_37 ) ;
F_9 ( & V_15 -> V_17 ) ;
F_27 ( & F_6 ( V_7 ) -> V_42 ,
& V_15 -> V_41 ) ;
V_15 -> V_34 ++ ;
F_11 ( & V_15 -> V_17 ) ;
}
error = 0 ;
V_39:
F_21 ( & V_4 -> V_17 ) ;
V_33:
return error ;
}
static int F_28 ( const struct V_6 * V_8 , const struct V_6 * V_9 )
{
struct V_43 * V_44 = F_23 ( V_8 ) , * V_45 = F_23 ( V_9 ) ;
return ( ! F_29 ( V_9 ) &&
( ! V_44 -> V_46 || ! V_45 -> V_46 ||
V_44 -> V_46 == V_45 -> V_46 ) ) ;
}
static unsigned int F_30 ( struct V_1 * V_1 , T_2 V_47 ,
unsigned int V_48 )
{
return F_31 ( ( V_49 V_50 ) V_47 , F_32 ( V_1 ) ) ^ V_48 ;
}
int F_33 ( struct V_6 * V_7 , unsigned short V_18 )
{
unsigned int V_19 =
F_30 ( F_5 ( V_7 ) , F_34 ( V_51 ) , V_18 ) ;
unsigned int V_52 =
F_30 ( F_5 ( V_7 ) , F_23 ( V_7 ) -> V_46 , 0 ) ;
F_6 ( V_7 ) -> V_37 = V_52 ;
return F_12 ( V_7 , V_18 , F_28 , V_19 ) ;
}
static inline int F_35 ( struct V_6 * V_7 , struct V_1 * V_1 , T_2 V_47 ,
unsigned short V_53 ,
T_3 V_54 , T_2 V_55 , T_3 V_56 , int V_57 )
{
int V_58 = - 1 ;
if ( F_4 ( F_5 ( V_7 ) , V_1 ) && F_6 ( V_7 ) -> V_12 == V_53 &&
! F_29 ( V_7 ) ) {
struct V_43 * V_59 = F_23 ( V_7 ) ;
V_58 = ( V_7 -> V_60 == V_61 ? 1 : 0 ) ;
if ( V_59 -> V_46 ) {
if ( V_59 -> V_46 != V_55 )
return - 1 ;
V_58 += 2 ;
}
if ( V_59 -> V_62 ) {
if ( V_59 -> V_62 != V_47 )
return - 1 ;
V_58 += 2 ;
}
if ( V_59 -> V_63 ) {
if ( V_59 -> V_63 != V_54 )
return - 1 ;
V_58 += 2 ;
}
if ( V_7 -> V_14 ) {
if ( V_7 -> V_14 != V_57 )
return - 1 ;
V_58 += 2 ;
}
}
return V_58 ;
}
static inline int F_36 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_2 V_47 , T_3 V_54 ,
T_2 V_55 , unsigned int V_53 , int V_57 )
{
int V_58 = - 1 ;
if ( F_4 ( F_5 ( V_7 ) , V_1 ) && ! F_29 ( V_7 ) ) {
struct V_43 * V_59 = F_23 ( V_7 ) ;
if ( V_59 -> V_46 != V_55 )
return - 1 ;
if ( V_59 -> V_40 != V_53 )
return - 1 ;
V_58 = ( V_7 -> V_60 == V_61 ? 1 : 0 ) ;
if ( V_59 -> V_62 ) {
if ( V_59 -> V_62 != V_47 )
return - 1 ;
V_58 += 2 ;
}
if ( V_59 -> V_63 ) {
if ( V_59 -> V_63 != V_54 )
return - 1 ;
V_58 += 2 ;
}
if ( V_7 -> V_14 ) {
if ( V_7 -> V_14 != V_57 )
return - 1 ;
V_58 += 2 ;
}
}
return V_58 ;
}
static struct V_6 * F_37 ( struct V_1 * V_1 ,
T_2 V_47 , T_3 V_54 ,
T_2 V_55 , unsigned int V_53 , int V_57 ,
struct V_3 * V_15 , unsigned int V_36 )
{
struct V_6 * V_7 , * V_64 ;
struct V_10 * V_11 ;
int V_58 , V_65 ;
V_66:
V_64 = NULL ;
V_65 = - 1 ;
F_38 (sk, node, &hslot2->head) {
V_58 = F_36 ( V_7 , V_1 , V_47 , V_54 ,
V_55 , V_53 , V_57 ) ;
if ( V_58 > V_65 ) {
V_64 = V_7 ;
V_65 = V_58 ;
if ( V_58 == V_67 )
goto V_68;
}
}
if ( F_39 ( V_11 ) != V_36 )
goto V_66;
if ( V_64 ) {
V_68:
if ( F_40 ( ! F_41 ( & V_64 -> V_69 , 2 ) ) )
V_64 = NULL ;
else if ( F_40 ( F_36 ( V_64 , V_1 , V_47 , V_54 ,
V_55 , V_53 , V_57 ) < V_65 ) ) {
F_42 ( V_64 ) ;
goto V_66;
}
}
return V_64 ;
}
struct V_6 * F_43 ( struct V_1 * V_1 , T_2 V_47 ,
T_3 V_54 , T_2 V_55 , T_3 V_56 ,
int V_57 , struct V_20 * V_21 )
{
struct V_6 * V_7 , * V_64 ;
struct V_10 * V_11 ;
unsigned short V_53 = F_44 ( V_56 ) ;
unsigned int V_70 , V_36 , V_71 = F_45 ( V_1 , V_53 , V_21 -> V_31 ) ;
struct V_3 * V_15 , * V_4 = & V_21 -> V_72 [ V_71 ] ;
int V_58 , V_65 ;
F_46 () ;
if ( V_4 -> V_34 > 10 ) {
V_70 = F_30 ( V_1 , V_55 , V_53 ) ;
V_36 = V_70 & V_21 -> V_31 ;
V_15 = & V_21 -> V_70 [ V_36 ] ;
if ( V_4 -> V_34 < V_15 -> V_34 )
goto V_66;
V_64 = F_37 ( V_1 , V_47 , V_54 ,
V_55 , V_53 , V_57 ,
V_15 , V_36 ) ;
if ( ! V_64 ) {
V_70 = F_30 ( V_1 , F_34 ( V_51 ) , V_53 ) ;
V_36 = V_70 & V_21 -> V_31 ;
V_15 = & V_21 -> V_70 [ V_36 ] ;
if ( V_4 -> V_34 < V_15 -> V_34 )
goto V_66;
V_64 = F_37 ( V_1 , V_47 , V_54 ,
F_34 ( V_51 ) , V_53 , V_57 ,
V_15 , V_36 ) ;
}
F_47 () ;
return V_64 ;
}
V_66:
V_64 = NULL ;
V_65 = - 1 ;
F_48 (sk, node, &hslot->head) {
V_58 = F_35 ( V_7 , V_1 , V_47 , V_53 , V_54 ,
V_55 , V_56 , V_57 ) ;
if ( V_58 > V_65 ) {
V_64 = V_7 ;
V_65 = V_58 ;
}
}
if ( F_39 ( V_11 ) != V_71 )
goto V_66;
if ( V_64 ) {
if ( F_40 ( ! F_41 ( & V_64 -> V_69 , 2 ) ) )
V_64 = NULL ;
else if ( F_40 ( F_35 ( V_64 , V_1 , V_47 , V_53 , V_54 ,
V_55 , V_56 , V_57 ) < V_65 ) ) {
F_42 ( V_64 ) ;
goto V_66;
}
}
F_47 () ;
return V_64 ;
}
static inline struct V_6 * F_49 ( struct V_73 * V_74 ,
T_3 V_54 , T_3 V_56 ,
struct V_20 * V_21 )
{
struct V_6 * V_7 ;
const struct V_75 * V_76 = F_50 ( V_74 ) ;
if ( F_40 ( V_7 = F_51 ( V_74 ) ) )
return V_7 ;
else
return F_43 ( F_52 ( F_53 ( V_74 ) -> V_77 ) , V_76 -> V_47 , V_54 ,
V_76 -> V_55 , V_56 , F_54 ( V_74 ) ,
V_21 ) ;
}
struct V_6 * F_55 ( struct V_1 * V_1 , T_2 V_47 , T_3 V_54 ,
T_2 V_55 , T_3 V_56 , int V_57 )
{
return F_43 ( V_1 , V_47 , V_54 , V_55 , V_56 , V_57 , & V_20 ) ;
}
static inline struct V_6 * F_56 ( struct V_1 * V_1 , struct V_6 * V_7 ,
T_3 V_78 , T_2 V_79 ,
T_3 V_80 , T_2 V_81 ,
int V_57 )
{
struct V_10 * V_11 ;
struct V_6 * V_82 = V_7 ;
unsigned short V_53 = F_44 ( V_78 ) ;
F_57 (s, node) {
struct V_43 * V_59 = F_23 ( V_82 ) ;
if ( ! F_4 ( F_5 ( V_82 ) , V_1 ) ||
F_6 ( V_82 ) -> V_12 != V_53 ||
( V_59 -> V_62 && V_59 -> V_62 != V_81 ) ||
( V_59 -> V_63 != V_80 && V_59 -> V_63 ) ||
( V_59 -> V_46 &&
V_59 -> V_46 != V_79 ) ||
F_29 ( V_82 ) ||
( V_82 -> V_14 && V_82 -> V_14 != V_57 ) )
continue;
if ( ! F_58 ( V_82 , V_79 , V_81 , V_57 ) )
continue;
goto V_32;
}
V_82 = NULL ;
V_32:
return V_82 ;
}
void F_59 ( struct V_73 * V_74 , V_50 V_83 , struct V_20 * V_21 )
{
struct V_43 * V_59 ;
const struct V_75 * V_76 = ( const struct V_75 * ) V_74 -> V_84 ;
struct V_85 * V_86 = (struct V_85 * ) ( V_74 -> V_84 + ( V_76 -> V_87 << 2 ) ) ;
const int type = F_60 ( V_74 ) -> type ;
const int V_88 = F_60 ( V_74 ) -> V_88 ;
struct V_6 * V_7 ;
int V_89 ;
int V_90 ;
struct V_1 * V_1 = F_52 ( V_74 -> V_77 ) ;
V_7 = F_43 ( V_1 , V_76 -> V_55 , V_86 -> V_91 ,
V_76 -> V_47 , V_86 -> V_92 , V_74 -> V_77 -> V_93 , V_21 ) ;
if ( V_7 == NULL ) {
F_61 ( V_1 , V_94 ) ;
return;
}
V_90 = 0 ;
V_89 = 0 ;
V_59 = F_23 ( V_7 ) ;
switch ( type ) {
default:
case V_95 :
V_90 = V_96 ;
break;
case V_97 :
goto V_98;
case V_99 :
V_90 = V_100 ;
V_89 = 1 ;
break;
case V_101 :
if ( V_88 == V_102 ) {
if ( V_59 -> V_103 != V_104 ) {
V_90 = V_105 ;
V_89 = 1 ;
break;
}
goto V_98;
}
V_90 = V_96 ;
if ( V_88 <= V_106 ) {
V_89 = V_107 [ V_88 ] . V_108 ;
V_90 = V_107 [ V_88 ] . V_109 ;
}
break;
}
if ( ! V_59 -> V_110 ) {
if ( ! V_89 || V_7 -> V_111 != V_112 )
goto V_98;
} else
F_62 ( V_7 , V_74 , V_90 , V_86 -> V_91 , V_83 , ( V_113 * ) ( V_86 + 1 ) ) ;
V_7 -> V_114 = V_90 ;
V_7 -> V_115 ( V_7 ) ;
V_98:
F_42 ( V_7 ) ;
}
void F_63 ( struct V_73 * V_74 , V_50 V_83 )
{
F_59 ( V_74 , V_83 , & V_20 ) ;
}
void F_64 ( struct V_6 * V_7 )
{
struct V_116 * V_117 = F_6 ( V_7 ) ;
if ( V_117 -> V_118 ) {
V_117 -> V_119 = 0 ;
V_117 -> V_118 = 0 ;
F_65 ( V_7 ) ;
}
}
static void F_66 ( struct V_73 * V_74 , T_2 V_120 , T_2 V_121 )
{
struct V_85 * V_86 = F_67 ( V_74 ) ;
struct V_73 * V_122 = F_68 ( V_74 ) -> V_123 ;
int V_124 = F_69 ( V_74 ) ;
int V_119 = V_74 -> V_119 - V_124 ;
int V_125 = V_119 ;
T_4 V_126 = 0 ;
if ( ! V_122 ) {
V_74 -> V_127 = F_70 ( V_74 ) - V_74 -> V_41 ;
V_74 -> V_128 = F_71 ( struct V_85 , V_129 ) ;
V_86 -> V_129 = ~ F_72 ( V_120 , V_121 , V_119 ,
V_130 , 0 ) ;
} else {
do {
V_126 = F_73 ( V_126 , V_122 -> V_126 ) ;
V_125 -= V_122 -> V_119 ;
} while ( ( V_122 = V_122 -> V_131 ) );
V_126 = F_74 ( V_74 , V_124 , V_125 , V_126 ) ;
V_74 -> V_132 = V_133 ;
V_86 -> V_129 = F_72 ( V_120 , V_121 , V_119 , V_130 , V_126 ) ;
if ( V_86 -> V_129 == 0 )
V_86 -> V_129 = V_134 ;
}
}
static int F_75 ( struct V_73 * V_74 , struct V_135 * V_136 )
{
struct V_6 * V_7 = V_74 -> V_7 ;
struct V_43 * V_59 = F_23 ( V_7 ) ;
struct V_85 * V_86 ;
int V_90 = 0 ;
int V_137 = F_76 ( V_7 ) ;
int V_124 = F_69 ( V_74 ) ;
int V_119 = V_74 -> V_119 - V_124 ;
T_4 V_126 = 0 ;
V_86 = F_67 ( V_74 ) ;
V_86 -> V_92 = V_59 -> V_138 ;
V_86 -> V_91 = V_136 -> V_139 ;
V_86 -> V_119 = F_77 ( V_119 ) ;
V_86 -> V_129 = 0 ;
if ( V_137 )
V_126 = F_78 ( V_74 ) ;
else if ( V_7 -> V_140 == V_141 ) {
V_74 -> V_132 = V_133 ;
goto V_142;
} else if ( V_74 -> V_132 == V_143 ) {
F_66 ( V_74 , V_136 -> V_47 , V_136 -> V_55 ) ;
goto V_142;
} else
V_126 = F_79 ( V_74 ) ;
V_86 -> V_129 = F_72 ( V_136 -> V_47 , V_136 -> V_55 , V_119 ,
V_7 -> V_144 , V_126 ) ;
if ( V_86 -> V_129 == 0 )
V_86 -> V_129 = V_134 ;
V_142:
V_90 = F_80 ( V_74 ) ;
if ( V_90 ) {
if ( V_90 == - V_145 && ! V_59 -> V_110 ) {
F_81 ( F_5 ( V_7 ) ,
V_146 , V_137 ) ;
V_90 = 0 ;
}
} else
F_81 ( F_5 ( V_7 ) ,
V_147 , V_137 ) ;
return V_90 ;
}
static int F_82 ( struct V_6 * V_7 )
{
struct V_116 * V_117 = F_6 ( V_7 ) ;
struct V_43 * V_59 = F_23 ( V_7 ) ;
struct V_135 * V_136 = & V_59 -> V_148 . V_149 . V_150 . V_151 ;
struct V_73 * V_74 ;
int V_90 = 0 ;
V_74 = F_83 ( V_7 , V_136 ) ;
if ( ! V_74 )
goto V_98;
V_90 = F_75 ( V_74 , V_136 ) ;
V_98:
V_117 -> V_119 = 0 ;
V_117 -> V_118 = 0 ;
return V_90 ;
}
int F_84 ( struct V_152 * V_153 , struct V_6 * V_7 , struct V_154 * V_155 ,
T_5 V_119 )
{
struct V_43 * V_59 = F_23 ( V_7 ) ;
struct V_116 * V_117 = F_6 ( V_7 ) ;
struct V_135 V_156 ;
struct V_135 * V_136 ;
int V_157 = V_119 ;
struct V_158 V_159 ;
struct V_160 * V_161 = NULL ;
int free = 0 ;
int V_162 = 0 ;
T_2 V_55 , V_163 , V_47 ;
T_3 V_56 ;
V_113 V_164 ;
int V_90 , V_137 = F_76 ( V_7 ) ;
int V_165 = V_117 -> V_166 || V_155 -> V_167 & V_168 ;
int (* F_85)( void * , char * , int , int , int , struct V_73 * );
struct V_73 * V_74 ;
struct V_169 V_170 ;
if ( V_119 > 0xFFFF )
return - V_105 ;
if ( V_155 -> V_167 & V_171 )
return - V_172 ;
V_159 . V_173 = NULL ;
V_159 . V_174 = 0 ;
F_85 = V_137 ? V_175 : V_176 ;
V_136 = & V_59 -> V_148 . V_149 . V_150 . V_151 ;
if ( V_117 -> V_118 ) {
F_86 ( V_7 ) ;
if ( F_87 ( V_117 -> V_118 ) ) {
if ( F_40 ( V_117 -> V_118 != V_177 ) ) {
F_88 ( V_7 ) ;
return - V_178 ;
}
goto V_179;
}
F_88 ( V_7 ) ;
}
V_157 += sizeof( struct V_85 ) ;
if ( V_155 -> V_180 ) {
struct V_181 * V_182 = (struct V_181 * ) V_155 -> V_180 ;
if ( V_155 -> V_183 < sizeof( * V_182 ) )
return - V_178 ;
if ( V_182 -> V_184 != V_177 ) {
if ( V_182 -> V_184 != V_185 )
return - V_186 ;
}
V_55 = V_182 -> V_187 . V_188 ;
V_56 = V_182 -> V_189 ;
if ( V_56 == 0 )
return - V_178 ;
} else {
if ( V_7 -> V_111 != V_112 )
return - V_190 ;
V_55 = V_59 -> V_62 ;
V_56 = V_59 -> V_63 ;
V_162 = 1 ;
}
V_159 . V_191 = V_59 -> V_192 ;
V_159 . V_193 = V_7 -> V_14 ;
V_90 = F_89 ( V_7 , & V_159 . V_174 ) ;
if ( V_90 )
return V_90 ;
if ( V_155 -> V_194 ) {
V_90 = F_90 ( F_5 ( V_7 ) , V_155 , & V_159 ) ;
if ( V_90 )
return V_90 ;
if ( V_159 . V_173 )
free = 1 ;
V_162 = 0 ;
}
if ( ! V_159 . V_173 ) {
struct V_195 * V_196 ;
F_46 () ;
V_196 = F_91 ( V_59 -> V_196 ) ;
if ( V_196 ) {
memcpy ( & V_170 , V_196 ,
sizeof( * V_196 ) + V_196 -> V_173 . V_197 ) ;
V_159 . V_173 = & V_170 . V_173 ;
}
F_47 () ;
}
V_47 = V_159 . V_191 ;
V_159 . V_191 = V_163 = V_55 ;
if ( V_159 . V_173 && V_159 . V_173 -> V_173 . V_198 ) {
if ( ! V_55 )
return - V_178 ;
V_163 = V_159 . V_173 -> V_173 . V_163 ;
V_162 = 0 ;
}
V_164 = F_92 ( V_59 -> V_164 ) ;
if ( F_93 ( V_7 , V_199 ) ||
( V_155 -> V_167 & V_200 ) ||
( V_159 . V_173 && V_159 . V_173 -> V_173 . V_201 ) ) {
V_164 |= V_202 ;
V_162 = 0 ;
}
if ( F_94 ( V_55 ) ) {
if ( ! V_159 . V_193 )
V_159 . V_193 = V_59 -> V_203 ;
if ( ! V_47 )
V_47 = V_59 -> V_204 ;
V_162 = 0 ;
}
if ( V_162 )
V_161 = (struct V_160 * ) F_95 ( V_7 , 0 ) ;
if ( V_161 == NULL ) {
struct V_1 * V_1 = F_5 ( V_7 ) ;
V_136 = & V_156 ;
F_96 ( V_136 , V_159 . V_193 , V_7 -> V_205 , V_164 ,
V_206 , V_7 -> V_144 ,
F_97 ( V_7 ) | V_207 ,
V_163 , V_47 , V_56 , V_59 -> V_138 ) ;
F_98 ( V_7 , F_99 ( V_136 ) ) ;
V_161 = F_100 ( V_1 , V_136 , V_7 ) ;
if ( F_101 ( V_161 ) ) {
V_90 = F_102 ( V_161 ) ;
V_161 = NULL ;
if ( V_90 == - V_208 )
F_103 ( V_1 , V_209 ) ;
goto V_98;
}
V_90 = - V_210 ;
if ( ( V_161 -> V_211 & V_212 ) &&
! F_93 ( V_7 , V_213 ) )
goto V_98;
if ( V_162 )
F_104 ( V_7 , F_105 ( & V_161 -> V_121 ) ) ;
}
if ( V_155 -> V_167 & V_214 )
goto V_215;
V_216:
V_47 = V_136 -> V_47 ;
if ( ! V_159 . V_191 )
V_55 = V_159 . V_191 = V_136 -> V_55 ;
if ( ! V_165 ) {
V_74 = F_106 ( V_7 , V_136 , F_85 , V_155 -> V_217 , V_157 ,
sizeof( struct V_85 ) , & V_159 , & V_161 ,
V_155 -> V_167 ) ;
V_90 = F_102 ( V_74 ) ;
if ( V_74 && ! F_101 ( V_74 ) )
V_90 = F_75 ( V_74 , V_136 ) ;
goto V_98;
}
F_86 ( V_7 ) ;
if ( F_40 ( V_117 -> V_118 ) ) {
F_88 ( V_7 ) ;
F_107 ( V_218 L_1 ) ;
V_90 = - V_178 ;
goto V_98;
}
V_136 = & V_59 -> V_148 . V_149 . V_150 . V_151 ;
V_136 -> V_55 = V_55 ;
V_136 -> V_47 = V_47 ;
V_136 -> V_139 = V_56 ;
V_136 -> V_219 = V_59 -> V_138 ;
V_117 -> V_118 = V_177 ;
V_179:
V_117 -> V_119 += V_157 ;
V_90 = F_108 ( V_7 , V_136 , F_85 , V_155 -> V_217 , V_157 ,
sizeof( struct V_85 ) , & V_159 , & V_161 ,
V_165 ? V_155 -> V_167 | V_168 : V_155 -> V_167 ) ;
if ( V_90 )
F_64 ( V_7 ) ;
else if ( ! V_165 )
V_90 = F_82 ( V_7 ) ;
else if ( F_40 ( F_109 ( & V_7 -> V_220 ) ) )
V_117 -> V_118 = 0 ;
F_88 ( V_7 ) ;
V_98:
F_110 ( V_161 ) ;
if ( free )
F_111 ( V_159 . V_173 ) ;
if ( ! V_90 )
return V_119 ;
if ( V_90 == - V_145 || F_19 ( V_221 , & V_7 -> V_222 -> V_223 ) ) {
F_81 ( F_5 ( V_7 ) ,
V_146 , V_137 ) ;
}
return V_90 ;
V_215:
F_112 ( & V_161 -> V_121 ) ;
if ( ! ( V_155 -> V_167 & V_224 ) || V_119 )
goto V_216;
V_90 = 0 ;
goto V_98;
}
int F_113 ( struct V_6 * V_7 , struct V_225 * V_225 , int V_124 ,
T_5 V_226 , int V_223 )
{
struct V_43 * V_59 = F_23 ( V_7 ) ;
struct V_116 * V_117 = F_6 ( V_7 ) ;
int V_227 ;
if ( ! V_117 -> V_118 ) {
struct V_154 V_155 = { . V_167 = V_223 | V_168 } ;
V_227 = F_84 ( NULL , V_7 , & V_155 , 0 ) ;
if ( V_227 < 0 )
return V_227 ;
}
F_86 ( V_7 ) ;
if ( F_40 ( ! V_117 -> V_118 ) ) {
F_88 ( V_7 ) ;
F_107 ( V_218 L_2 ) ;
return - V_178 ;
}
V_227 = F_114 ( V_7 , & V_59 -> V_148 . V_149 . V_150 . V_151 ,
V_225 , V_124 , V_226 , V_223 ) ;
if ( V_227 == - V_172 ) {
F_88 ( V_7 ) ;
return F_115 ( V_7 -> V_222 , V_225 , V_124 ,
V_226 , V_223 ) ;
}
if ( V_227 < 0 ) {
F_64 ( V_7 ) ;
goto V_98;
}
V_117 -> V_119 += V_226 ;
if ( ! ( V_117 -> V_166 || ( V_223 & V_168 ) ) )
V_227 = F_82 ( V_7 ) ;
if ( ! V_227 )
V_227 = V_226 ;
V_98:
F_88 ( V_7 ) ;
return V_227 ;
}
static unsigned int F_116 ( struct V_6 * V_7 )
{
struct V_228 V_229 , * V_230 = & V_7 -> V_231 ;
struct V_73 * V_74 ;
unsigned int V_16 ;
F_117 ( & V_229 ) ;
F_18 ( & V_230 -> V_17 ) ;
while ( ( V_74 = F_118 ( V_230 ) ) != NULL &&
F_119 ( V_74 ) ) {
F_120 ( F_5 ( V_7 ) , V_232 ,
F_76 ( V_7 ) ) ;
F_121 ( & V_7 -> V_233 ) ;
F_122 ( V_74 , V_230 ) ;
F_123 ( & V_229 , V_74 ) ;
}
V_16 = V_74 ? V_74 -> V_119 : 0 ;
F_21 ( & V_230 -> V_17 ) ;
if ( ! F_109 ( & V_229 ) ) {
bool V_234 = F_124 ( V_7 ) ;
F_125 ( & V_229 ) ;
F_126 ( V_7 ) ;
F_127 ( V_7 , V_234 ) ;
}
return V_16 ;
}
int F_128 ( struct V_6 * V_7 , int V_235 , unsigned long V_236 )
{
switch ( V_235 ) {
case V_237 :
{
int V_238 = F_129 ( V_7 ) ;
return F_130 ( V_238 , ( int V_239 * ) V_236 ) ;
}
case V_240 :
{
unsigned int V_238 = F_116 ( V_7 ) ;
if ( V_238 )
V_238 -= sizeof( struct V_85 ) ;
return F_130 ( V_238 , ( int V_239 * ) V_236 ) ;
}
default:
return - V_241 ;
}
return 0 ;
}
int F_131 ( struct V_152 * V_153 , struct V_6 * V_7 , struct V_154 * V_155 ,
T_5 V_119 , int V_242 , int V_223 , int * V_243 )
{
struct V_43 * V_59 = F_23 ( V_7 ) ;
struct V_181 * sin = (struct V_181 * ) V_155 -> V_180 ;
struct V_73 * V_74 ;
unsigned int V_157 , V_244 ;
int V_245 ;
int V_90 ;
int V_137 = F_76 ( V_7 ) ;
bool V_234 ;
if ( V_243 )
* V_243 = sizeof( * sin ) ;
if ( V_223 & V_246 )
return F_132 ( V_7 , V_155 , V_119 ) ;
V_247:
V_74 = F_133 ( V_7 , V_223 | ( V_242 ? V_248 : 0 ) ,
& V_245 , & V_90 ) ;
if ( ! V_74 )
goto V_98;
V_157 = V_74 -> V_119 - sizeof( struct V_85 ) ;
V_244 = V_119 ;
if ( V_244 > V_157 )
V_244 = V_157 ;
else if ( V_244 < V_157 )
V_155 -> V_167 |= V_249 ;
if ( V_244 < V_157 || F_134 ( V_74 ) -> V_250 ) {
if ( F_119 ( V_74 ) )
goto V_251;
}
if ( F_135 ( V_74 ) )
V_90 = F_136 ( V_74 , sizeof( struct V_85 ) ,
V_155 -> V_217 , V_244 ) ;
else {
V_90 = F_137 ( V_74 ,
sizeof( struct V_85 ) ,
V_155 -> V_217 ) ;
if ( V_90 == - V_178 )
goto V_251;
}
if ( V_90 )
goto V_252;
if ( ! V_245 )
F_81 ( F_5 ( V_7 ) ,
V_253 , V_137 ) ;
F_138 ( V_155 , V_7 , V_74 ) ;
if ( sin ) {
sin -> V_184 = V_177 ;
sin -> V_189 = F_67 ( V_74 ) -> V_92 ;
sin -> V_187 . V_188 = F_50 ( V_74 ) -> V_47 ;
memset ( sin -> V_254 , 0 , sizeof( sin -> V_254 ) ) ;
}
if ( V_59 -> V_255 )
F_139 ( V_155 , V_74 ) ;
V_90 = V_244 ;
if ( V_223 & V_249 )
V_90 = V_157 ;
V_252:
F_140 ( V_7 , V_74 ) ;
V_98:
return V_90 ;
V_251:
V_234 = F_124 ( V_7 ) ;
if ( ! F_141 ( V_7 , V_74 , V_223 ) )
F_81 ( F_5 ( V_7 ) , V_232 , V_137 ) ;
F_127 ( V_7 , V_234 ) ;
if ( V_242 )
return - V_256 ;
V_155 -> V_167 &= ~ V_249 ;
goto V_247;
}
int F_142 ( struct V_6 * V_7 , int V_223 )
{
struct V_43 * V_59 = F_23 ( V_7 ) ;
V_7 -> V_111 = V_257 ;
V_59 -> V_62 = 0 ;
V_59 -> V_63 = 0 ;
F_143 ( V_7 ) ;
V_7 -> V_14 = 0 ;
if ( ! ( V_7 -> V_258 & V_259 ) )
F_144 ( V_7 ) ;
if ( ! ( V_7 -> V_258 & V_260 ) ) {
V_7 -> V_22 -> V_261 ( V_7 ) ;
V_59 -> V_138 = 0 ;
}
F_145 ( V_7 ) ;
return 0 ;
}
void F_146 ( struct V_6 * V_7 )
{
if ( F_147 ( V_7 ) ) {
struct V_20 * V_21 = V_7 -> V_22 -> V_23 . V_20 ;
struct V_3 * V_4 , * V_15 ;
V_4 = F_16 ( V_21 , F_5 ( V_7 ) ,
F_6 ( V_7 ) -> V_12 ) ;
V_15 = F_22 ( V_21 , F_6 ( V_7 ) -> V_37 ) ;
F_18 ( & V_4 -> V_17 ) ;
if ( F_148 ( V_7 ) ) {
V_4 -> V_34 -- ;
F_23 ( V_7 ) -> V_40 = 0 ;
F_26 ( F_5 ( V_7 ) , V_7 -> V_22 , - 1 ) ;
F_9 ( & V_15 -> V_17 ) ;
F_149 ( & F_6 ( V_7 ) -> V_42 ) ;
V_15 -> V_34 -- ;
F_11 ( & V_15 -> V_17 ) ;
}
F_21 ( & V_4 -> V_17 ) ;
}
}
void F_150 ( struct V_6 * V_7 , T_6 V_262 )
{
if ( F_147 ( V_7 ) ) {
struct V_20 * V_21 = V_7 -> V_22 -> V_23 . V_20 ;
struct V_3 * V_4 , * V_15 , * V_263 ;
V_15 = F_22 ( V_21 , F_6 ( V_7 ) -> V_37 ) ;
V_263 = F_22 ( V_21 , V_262 ) ;
F_6 ( V_7 ) -> V_37 = V_262 ;
if ( V_15 != V_263 ) {
V_4 = F_16 ( V_21 , F_5 ( V_7 ) ,
F_6 ( V_7 ) -> V_12 ) ;
F_18 ( & V_4 -> V_17 ) ;
F_9 ( & V_15 -> V_17 ) ;
F_149 ( & F_6 ( V_7 ) -> V_42 ) ;
V_15 -> V_34 -- ;
F_11 ( & V_15 -> V_17 ) ;
F_9 ( & V_263 -> V_17 ) ;
F_27 ( & F_6 ( V_7 ) -> V_42 ,
& V_263 -> V_41 ) ;
V_263 -> V_34 ++ ;
F_11 ( & V_263 -> V_17 ) ;
F_21 ( & V_4 -> V_17 ) ;
}
}
}
static void F_151 ( struct V_6 * V_7 )
{
T_6 V_264 = F_30 ( F_5 ( V_7 ) ,
F_23 ( V_7 ) -> V_46 ,
F_23 ( V_7 ) -> V_40 ) ;
F_150 ( V_7 , V_264 ) ;
}
static int F_152 ( struct V_6 * V_7 , struct V_73 * V_74 )
{
int V_265 ;
if ( F_23 ( V_7 ) -> V_62 )
F_153 ( V_7 , V_74 ) ;
V_265 = F_154 ( V_7 , V_74 ) ;
if ( V_265 < 0 ) {
int V_137 = F_76 ( V_7 ) ;
if ( V_265 == - V_266 )
F_120 ( F_5 ( V_7 ) , V_267 ,
V_137 ) ;
F_120 ( F_5 ( V_7 ) , V_232 , V_137 ) ;
F_155 ( V_74 ) ;
F_156 ( V_265 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
int F_157 ( struct V_6 * V_7 , struct V_73 * V_74 )
{
struct V_116 * V_117 = F_6 ( V_7 ) ;
int V_265 ;
int V_137 = F_76 ( V_7 ) ;
if ( ! F_158 ( V_7 , V_268 , V_74 ) )
goto V_269;
F_159 ( V_74 ) ;
if ( V_117 -> V_270 ) {
int (* F_160)( struct V_6 * V_7 , struct V_73 * V_74 );
F_160 = F_161 ( V_117 -> F_160 ) ;
if ( V_74 -> V_119 > sizeof( struct V_85 ) && F_160 != NULL ) {
int V_227 ;
V_227 = F_160 ( V_7 , V_74 ) ;
if ( V_227 <= 0 ) {
F_120 ( F_5 ( V_7 ) ,
V_253 ,
V_137 ) ;
return - V_227 ;
}
}
}
if ( ( V_137 & V_271 ) && F_134 ( V_74 ) -> V_250 ) {
if ( V_117 -> V_272 == 0 ) {
F_107 ( V_273 L_3
L_4 ,
F_134 ( V_74 ) -> V_274 , V_74 -> V_119 ) ;
goto V_269;
}
if ( F_134 ( V_74 ) -> V_274 < V_117 -> V_272 ) {
F_107 ( V_273
L_5 ,
F_134 ( V_74 ) -> V_274 , V_117 -> V_272 ) ;
goto V_269;
}
}
if ( F_162 ( V_7 -> V_275 ) &&
F_119 ( V_74 ) )
goto V_269;
if ( F_163 ( V_7 , V_74 ) )
goto V_269;
V_265 = 0 ;
F_164 ( V_74 ) ;
F_165 ( V_7 ) ;
if ( ! F_166 ( V_7 ) )
V_265 = F_152 ( V_7 , V_74 ) ;
else if ( F_167 ( V_7 , V_74 ) ) {
F_168 ( V_7 ) ;
goto V_269;
}
F_168 ( V_7 ) ;
return V_265 ;
V_269:
F_120 ( F_5 ( V_7 ) , V_232 , V_137 ) ;
F_121 ( & V_7 -> V_233 ) ;
F_155 ( V_74 ) ;
return - 1 ;
}
static void F_169 ( struct V_6 * * V_276 , unsigned int V_34 ,
struct V_73 * V_74 , unsigned int V_277 )
{
unsigned int V_278 ;
struct V_73 * V_279 = NULL ;
struct V_6 * V_7 ;
for ( V_278 = 0 ; V_278 < V_34 ; V_278 ++ ) {
V_7 = V_276 [ V_278 ] ;
if ( F_87 ( V_279 == NULL ) )
V_279 = ( V_278 == V_277 ) ? V_74 : F_170 ( V_74 , V_280 ) ;
if ( ! V_279 ) {
F_121 ( & V_7 -> V_233 ) ;
F_120 ( F_5 ( V_7 ) , V_267 ,
F_76 ( V_7 ) ) ;
F_120 ( F_5 ( V_7 ) , V_232 ,
F_76 ( V_7 ) ) ;
}
if ( V_279 && F_157 ( V_7 , V_279 ) <= 0 )
V_279 = NULL ;
}
if ( F_40 ( V_279 ) )
F_155 ( V_279 ) ;
}
static int F_171 ( struct V_1 * V_1 , struct V_73 * V_74 ,
struct V_85 * V_86 ,
T_2 V_47 , T_2 V_55 ,
struct V_20 * V_21 )
{
struct V_6 * V_7 , * V_276 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_3 * V_4 = F_16 ( V_21 , V_1 , F_44 ( V_86 -> V_91 ) ) ;
int V_57 ;
unsigned int V_278 , V_34 = 0 ;
F_9 ( & V_4 -> V_17 ) ;
V_7 = F_172 ( & V_4 -> V_41 ) ;
V_57 = V_74 -> V_77 -> V_93 ;
V_7 = F_56 ( V_1 , V_7 , V_86 -> V_91 , V_55 , V_86 -> V_92 , V_47 , V_57 ) ;
while ( V_7 ) {
V_276 [ V_34 ++ ] = V_7 ;
V_7 = F_56 ( V_1 , F_173 ( V_7 ) , V_86 -> V_91 ,
V_55 , V_86 -> V_92 , V_47 , V_57 ) ;
if ( F_40 ( V_34 == F_174 ( V_276 ) ) ) {
if ( ! V_7 )
break;
F_169 ( V_276 , V_34 , V_74 , ~ 0 ) ;
V_34 = 0 ;
}
}
for ( V_278 = 0 ; V_278 < V_34 ; V_278 ++ )
F_175 ( V_276 [ V_278 ] ) ;
F_11 ( & V_4 -> V_17 ) ;
if ( V_34 ) {
F_169 ( V_276 , V_34 , V_74 , V_34 - 1 ) ;
for ( V_278 = 0 ; V_278 < V_34 ; V_278 ++ )
F_42 ( V_276 [ V_278 ] ) ;
} else {
F_155 ( V_74 ) ;
}
return 0 ;
}
static inline int F_176 ( struct V_73 * V_74 , struct V_85 * V_86 ,
int V_281 )
{
const struct V_75 * V_76 ;
int V_90 ;
F_134 ( V_74 ) -> V_250 = 0 ;
F_134 ( V_74 ) -> V_274 = V_74 -> V_119 ;
if ( V_281 == V_282 ) {
V_90 = F_177 ( V_74 , V_86 ) ;
if ( V_90 )
return V_90 ;
}
V_76 = F_50 ( V_74 ) ;
if ( V_86 -> V_129 == 0 ) {
V_74 -> V_132 = V_283 ;
} else if ( V_74 -> V_132 == V_284 ) {
if ( ! F_72 ( V_76 -> V_47 , V_76 -> V_55 , V_74 -> V_119 ,
V_281 , V_74 -> V_126 ) )
V_74 -> V_132 = V_283 ;
}
if ( ! F_135 ( V_74 ) )
V_74 -> V_126 = F_178 ( V_76 -> V_47 , V_76 -> V_55 ,
V_74 -> V_119 , V_281 , 0 ) ;
return 0 ;
}
int F_179 ( struct V_73 * V_74 , struct V_20 * V_21 ,
int V_281 )
{
struct V_6 * V_7 ;
struct V_85 * V_86 ;
unsigned short V_157 ;
struct V_160 * V_161 = F_180 ( V_74 ) ;
T_2 V_47 , V_55 ;
struct V_1 * V_1 = F_52 ( V_74 -> V_77 ) ;
if ( ! F_181 ( V_74 , sizeof( struct V_85 ) ) )
goto V_269;
V_86 = F_67 ( V_74 ) ;
V_157 = F_44 ( V_86 -> V_119 ) ;
V_47 = F_50 ( V_74 ) -> V_47 ;
V_55 = F_50 ( V_74 ) -> V_55 ;
if ( V_157 > V_74 -> V_119 )
goto V_285;
if ( V_281 == V_130 ) {
if ( V_157 < sizeof( * V_86 ) || F_182 ( V_74 , V_157 ) )
goto V_285;
V_86 = F_67 ( V_74 ) ;
}
if ( F_176 ( V_74 , V_86 , V_281 ) )
goto V_286;
if ( V_161 -> V_211 & ( V_212 | V_287 ) )
return F_171 ( V_1 , V_74 , V_86 ,
V_47 , V_55 , V_21 ) ;
V_7 = F_49 ( V_74 , V_86 -> V_92 , V_86 -> V_91 , V_21 ) ;
if ( V_7 != NULL ) {
int V_227 = F_157 ( V_7 , V_74 ) ;
F_42 ( V_7 ) ;
if ( V_227 > 0 )
return - V_227 ;
return 0 ;
}
if ( ! F_158 ( NULL , V_268 , V_74 ) )
goto V_269;
F_159 ( V_74 ) ;
if ( F_119 ( V_74 ) )
goto V_286;
F_120 ( V_1 , V_288 , V_281 == V_282 ) ;
F_183 ( V_74 , V_101 , V_289 , 0 ) ;
F_155 ( V_74 ) ;
return 0 ;
V_285:
F_107 ( V_218 L_6 ,
V_281 == V_282 ? L_7 : L_8 ,
& V_47 ,
F_44 ( V_86 -> V_92 ) ,
V_157 ,
V_74 -> V_119 ,
& V_55 ,
F_44 ( V_86 -> V_91 ) ) ;
goto V_269;
V_286:
F_107 ( V_218 L_9 ,
V_281 == V_282 ? L_7 : L_8 ,
& V_47 ,
F_44 ( V_86 -> V_92 ) ,
& V_55 ,
F_44 ( V_86 -> V_91 ) ,
V_157 ) ;
V_269:
F_120 ( V_1 , V_232 , V_281 == V_282 ) ;
F_155 ( V_74 ) ;
return 0 ;
}
int F_184 ( struct V_73 * V_74 )
{
return F_179 ( V_74 , & V_20 , V_130 ) ;
}
void F_185 ( struct V_6 * V_7 )
{
bool V_234 = F_124 ( V_7 ) ;
F_64 ( V_7 ) ;
F_127 ( V_7 , V_234 ) ;
}
int F_186 ( struct V_6 * V_7 , int V_290 , int V_291 ,
char V_239 * V_292 , unsigned int V_197 ,
int (* F_187)( struct V_6 * ) )
{
struct V_116 * V_117 = F_6 ( V_7 ) ;
int V_293 ;
int V_90 = 0 ;
int V_137 = F_76 ( V_7 ) ;
if ( V_197 < sizeof( int ) )
return - V_178 ;
if ( F_188 ( V_293 , ( int V_239 * ) V_292 ) )
return - V_294 ;
switch ( V_291 ) {
case V_295 :
if ( V_293 != 0 ) {
V_117 -> V_166 = 1 ;
} else {
V_117 -> V_166 = 0 ;
F_86 ( V_7 ) ;
(* F_187)( V_7 ) ;
F_88 ( V_7 ) ;
}
break;
case V_296 :
switch ( V_293 ) {
case 0 :
case V_297 :
case V_298 :
V_117 -> F_160 = V_299 ;
case V_300 :
V_117 -> V_270 = V_293 ;
break;
default:
V_90 = - V_301 ;
break;
}
break;
case V_302 :
if ( ! V_137 )
return - V_301 ;
if ( V_293 != 0 && V_293 < 8 )
V_293 = 8 ;
else if ( V_293 > V_303 )
V_293 = V_303 ;
V_117 -> V_304 = V_293 ;
V_117 -> V_305 |= V_306 ;
break;
case V_307 :
if ( ! V_137 )
return - V_301 ;
if ( V_293 != 0 && V_293 < 8 )
V_293 = 8 ;
else if ( V_293 > V_303 )
V_293 = V_303 ;
V_117 -> V_272 = V_293 ;
V_117 -> V_305 |= V_271 ;
break;
default:
V_90 = - V_301 ;
break;
}
return V_90 ;
}
int F_189 ( struct V_6 * V_7 , int V_290 , int V_291 ,
char V_239 * V_292 , unsigned int V_197 )
{
if ( V_290 == V_308 || V_290 == V_309 )
return F_186 ( V_7 , V_290 , V_291 , V_292 , V_197 ,
F_82 ) ;
return F_190 ( V_7 , V_290 , V_291 , V_292 , V_197 ) ;
}
int F_191 ( struct V_6 * V_7 , int V_290 , int V_291 ,
char V_239 * V_292 , unsigned int V_197 )
{
if ( V_290 == V_308 || V_290 == V_309 )
return F_186 ( V_7 , V_290 , V_291 , V_292 , V_197 ,
F_82 ) ;
return F_192 ( V_7 , V_290 , V_291 , V_292 , V_197 ) ;
}
int F_193 ( struct V_6 * V_7 , int V_290 , int V_291 ,
char V_239 * V_292 , int V_239 * V_197 )
{
struct V_116 * V_117 = F_6 ( V_7 ) ;
int V_293 , V_119 ;
if ( F_188 ( V_119 , V_197 ) )
return - V_294 ;
V_119 = F_194 (unsigned int, len, sizeof(int)) ;
if ( V_119 < 0 )
return - V_178 ;
switch ( V_291 ) {
case V_295 :
V_293 = V_117 -> V_166 ;
break;
case V_296 :
V_293 = V_117 -> V_270 ;
break;
case V_302 :
V_293 = V_117 -> V_304 ;
break;
case V_307 :
V_293 = V_117 -> V_272 ;
break;
default:
return - V_301 ;
}
if ( F_130 ( V_119 , V_197 ) )
return - V_294 ;
if ( F_195 ( V_292 , & V_293 , V_119 ) )
return - V_294 ;
return 0 ;
}
int F_196 ( struct V_6 * V_7 , int V_290 , int V_291 ,
char V_239 * V_292 , int V_239 * V_197 )
{
if ( V_290 == V_308 || V_290 == V_309 )
return F_193 ( V_7 , V_290 , V_291 , V_292 , V_197 ) ;
return F_197 ( V_7 , V_290 , V_291 , V_292 , V_197 ) ;
}
int F_198 ( struct V_6 * V_7 , int V_290 , int V_291 ,
char V_239 * V_292 , int V_239 * V_197 )
{
if ( V_290 == V_308 || V_290 == V_309 )
return F_193 ( V_7 , V_290 , V_291 , V_292 , V_197 ) ;
return F_199 ( V_7 , V_290 , V_291 , V_292 , V_197 ) ;
}
unsigned int F_200 ( struct V_310 * V_310 , struct V_311 * V_6 , T_7 * V_312 )
{
unsigned int V_31 = F_201 ( V_310 , V_6 , V_312 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
if ( ( V_31 & V_313 ) && ! ( V_310 -> V_314 & V_315 ) &&
! ( V_7 -> V_316 & V_317 ) && ! F_116 ( V_7 ) )
V_31 &= ~ ( V_318 | V_313 ) ;
return V_31 ;
}
static struct V_6 * F_202 ( struct V_319 * V_320 , int V_321 )
{
struct V_6 * V_7 ;
struct V_322 * V_323 = V_320 -> V_324 ;
struct V_1 * V_1 = F_203 ( V_320 ) ;
for ( V_323 -> V_325 = V_321 ; V_323 -> V_325 <= V_323 -> V_20 -> V_31 ;
++ V_323 -> V_325 ) {
struct V_10 * V_11 ;
struct V_3 * V_4 = & V_323 -> V_20 -> V_72 [ V_323 -> V_325 ] ;
if ( F_204 ( & V_4 -> V_41 ) )
continue;
F_18 ( & V_4 -> V_17 ) ;
F_3 (sk, node, &hslot->head) {
if ( ! F_4 ( F_5 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_60 == V_323 -> V_326 )
goto V_32;
}
F_21 ( & V_4 -> V_17 ) ;
}
V_7 = NULL ;
V_32:
return V_7 ;
}
static struct V_6 * F_205 ( struct V_319 * V_320 , struct V_6 * V_7 )
{
struct V_322 * V_323 = V_320 -> V_324 ;
struct V_1 * V_1 = F_203 ( V_320 ) ;
do {
V_7 = F_173 ( V_7 ) ;
} while ( V_7 && ( ! F_4 ( F_5 ( V_7 ) , V_1 ) || V_7 -> V_60 != V_323 -> V_326 ) );
if ( ! V_7 ) {
if ( V_323 -> V_325 <= V_323 -> V_20 -> V_31 )
F_21 ( & V_323 -> V_20 -> V_72 [ V_323 -> V_325 ] . V_17 ) ;
return F_202 ( V_320 , V_323 -> V_325 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_206 ( struct V_319 * V_320 , T_8 V_327 )
{
struct V_6 * V_7 = F_202 ( V_320 , 0 ) ;
if ( V_7 )
while ( V_327 && ( V_7 = F_205 ( V_320 , V_7 ) ) != NULL )
-- V_327 ;
return V_327 ? NULL : V_7 ;
}
static void * F_207 ( struct V_319 * V_320 , T_8 * V_327 )
{
struct V_322 * V_323 = V_320 -> V_324 ;
V_323 -> V_325 = V_328 ;
return * V_327 ? F_206 ( V_320 , * V_327 - 1 ) : V_329 ;
}
static void * F_208 ( struct V_319 * V_320 , void * V_330 , T_8 * V_327 )
{
struct V_6 * V_7 ;
if ( V_330 == V_329 )
V_7 = F_206 ( V_320 , 0 ) ;
else
V_7 = F_205 ( V_320 , V_330 ) ;
++ * V_327 ;
return V_7 ;
}
static void F_209 ( struct V_319 * V_320 , void * V_330 )
{
struct V_322 * V_323 = V_320 -> V_324 ;
if ( V_323 -> V_325 <= V_323 -> V_20 -> V_31 )
F_21 ( & V_323 -> V_20 -> V_72 [ V_323 -> V_325 ] . V_17 ) ;
}
int F_210 ( struct V_331 * V_331 , struct V_310 * V_310 )
{
struct V_332 * V_333 = F_211 ( V_331 ) -> V_84 ;
struct V_322 * V_82 ;
int V_90 ;
V_90 = F_212 ( V_331 , V_310 , & V_333 -> V_334 ,
sizeof( struct V_322 ) ) ;
if ( V_90 < 0 )
return V_90 ;
V_82 = ( (struct V_319 * ) V_310 -> V_335 ) -> V_324 ;
V_82 -> V_326 = V_333 -> V_326 ;
V_82 -> V_20 = V_333 -> V_20 ;
return V_90 ;
}
int F_213 ( struct V_1 * V_1 , struct V_332 * V_333 )
{
struct V_336 * V_337 ;
int V_265 = 0 ;
V_333 -> V_334 . V_321 = F_207 ;
V_333 -> V_334 . V_131 = F_208 ;
V_333 -> V_334 . V_338 = F_209 ;
V_337 = F_214 ( V_333 -> V_339 , V_340 , V_1 -> V_341 ,
V_333 -> V_342 , V_333 ) ;
if ( ! V_337 )
V_265 = - V_266 ;
return V_265 ;
}
void F_215 ( struct V_1 * V_1 , struct V_332 * V_333 )
{
F_216 ( V_1 , V_333 -> V_339 ) ;
}
static void F_217 ( struct V_6 * V_343 , struct V_319 * V_344 ,
int V_325 , int * V_119 )
{
struct V_43 * V_59 = F_23 ( V_343 ) ;
T_2 V_91 = V_59 -> V_62 ;
T_2 V_120 = V_59 -> V_46 ;
T_1 V_345 = F_44 ( V_59 -> V_63 ) ;
T_1 V_346 = F_44 ( V_59 -> V_138 ) ;
F_218 ( V_344 , L_10
L_11 ,
V_325 , V_120 , V_346 , V_91 , V_345 , V_343 -> V_111 ,
F_129 ( V_343 ) ,
F_219 ( V_343 ) ,
0 , 0L , 0 , F_220 ( V_343 ) , 0 , F_221 ( V_343 ) ,
F_222 ( & V_343 -> V_69 ) , V_343 ,
F_222 ( & V_343 -> V_233 ) , V_119 ) ;
}
int F_223 ( struct V_319 * V_320 , void * V_330 )
{
if ( V_330 == V_329 )
F_218 ( V_320 , L_12 ,
L_13
L_14
L_15 ) ;
else {
struct V_322 * V_323 = V_320 -> V_324 ;
int V_119 ;
F_217 ( V_330 , V_320 , V_323 -> V_325 , & V_119 ) ;
F_218 ( V_320 , L_16 , 127 - V_119 , L_8 ) ;
}
return 0 ;
}
static int T_9 F_224 ( struct V_1 * V_1 )
{
return F_213 ( V_1 , & V_347 ) ;
}
static void T_10 F_225 ( struct V_1 * V_1 )
{
F_215 ( V_1 , & V_347 ) ;
}
int T_11 F_226 ( void )
{
return F_227 ( & V_348 ) ;
}
void F_228 ( void )
{
F_229 ( & V_348 ) ;
}
static int T_11 F_230 ( char * V_349 )
{
if ( ! V_349 )
return 0 ;
V_350 = F_231 ( V_349 , & V_349 , 0 ) ;
if ( V_350 && V_350 < V_351 )
V_350 = V_351 ;
return 1 ;
}
void T_11 F_232 ( struct V_20 * V_352 , const char * V_339 )
{
unsigned int V_278 ;
if ( ! V_353 )
V_352 -> V_72 = F_233 ( V_339 ,
2 * sizeof( struct V_3 ) ,
V_350 ,
21 ,
0 ,
& V_352 -> log ,
& V_352 -> V_31 ,
64 * 1024 ) ;
if ( V_353 || V_352 -> V_31 < V_351 - 1 ) {
V_352 -> V_72 = F_234 ( V_351 *
2 * sizeof( struct V_3 ) , V_354 ) ;
if ( ! V_352 -> V_72 )
F_235 ( V_339 ) ;
V_352 -> log = F_236 ( V_351 ) ;
V_352 -> V_31 = V_351 - 1 ;
}
V_352 -> V_70 = V_352 -> V_72 + ( V_352 -> V_31 + 1 ) ;
for ( V_278 = 0 ; V_278 <= V_352 -> V_31 ; V_278 ++ ) {
F_237 ( & V_352 -> V_72 [ V_278 ] . V_41 , V_278 ) ;
V_352 -> V_72 [ V_278 ] . V_34 = 0 ;
F_238 ( & V_352 -> V_72 [ V_278 ] . V_17 ) ;
}
for ( V_278 = 0 ; V_278 <= V_352 -> V_31 ; V_278 ++ ) {
F_237 ( & V_352 -> V_70 [ V_278 ] . V_41 , V_278 ) ;
V_352 -> V_70 [ V_278 ] . V_34 = 0 ;
F_238 ( & V_352 -> V_70 [ V_278 ] . V_17 ) ;
}
}
void T_11 F_239 ( void )
{
unsigned long V_355 ;
F_232 ( & V_20 , L_17 ) ;
V_355 = F_240 () / 8 ;
V_355 = F_241 ( V_355 , 128UL ) ;
V_356 [ 0 ] = V_355 / 4 * 3 ;
V_356 [ 1 ] = V_355 ;
V_356 [ 2 ] = V_356 [ 0 ] * 2 ;
V_357 = V_358 ;
V_359 = V_358 ;
}
int F_242 ( struct V_73 * V_74 )
{
const struct V_75 * V_76 ;
struct V_85 * V_86 ;
if ( ! F_181 ( V_74 , sizeof( * V_86 ) ) )
return - V_178 ;
V_76 = F_50 ( V_74 ) ;
V_86 = F_67 ( V_74 ) ;
V_86 -> V_129 = ~ F_72 ( V_76 -> V_47 , V_76 -> V_55 , V_74 -> V_119 ,
V_130 , 0 ) ;
V_74 -> V_127 = F_70 ( V_74 ) - V_74 -> V_41 ;
V_74 -> V_128 = F_71 ( struct V_85 , V_129 ) ;
V_74 -> V_132 = V_143 ;
return 0 ;
}
struct V_73 * F_243 ( struct V_73 * V_74 ,
T_12 V_360 )
{
struct V_73 * V_361 = F_244 ( - V_178 ) ;
unsigned int V_362 ;
int V_124 ;
T_4 V_126 ;
V_362 = F_68 ( V_74 ) -> V_363 ;
if ( F_40 ( V_74 -> V_119 <= V_362 ) )
goto V_98;
if ( F_245 ( V_74 , V_360 | V_364 ) ) {
int type = F_68 ( V_74 ) -> V_365 ;
if ( F_40 ( type & ~ ( V_366 | V_367 ) ||
! ( type & ( V_366 ) ) ) )
goto V_98;
F_68 ( V_74 ) -> V_368 = F_246 ( V_74 -> V_119 , V_362 ) ;
V_361 = NULL ;
goto V_98;
}
V_124 = F_247 ( V_74 ) ;
V_126 = F_74 ( V_74 , V_124 , V_74 -> V_119 - V_124 , 0 ) ;
V_124 += V_74 -> V_128 ;
* ( V_369 * ) ( V_74 -> V_84 + V_124 ) = F_248 ( V_126 ) ;
V_74 -> V_132 = V_133 ;
V_361 = F_249 ( V_74 , V_360 ) ;
V_98:
return V_361 ;
}
