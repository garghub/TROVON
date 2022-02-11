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
unsigned int rand ;
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
} else if ( ! V_159 . V_193 )
V_159 . V_193 = V_59 -> V_205 ;
if ( V_162 )
V_161 = (struct V_160 * ) F_95 ( V_7 , 0 ) ;
if ( V_161 == NULL ) {
struct V_1 * V_1 = F_5 ( V_7 ) ;
V_136 = & V_156 ;
F_96 ( V_136 , V_159 . V_193 , V_7 -> V_206 , V_164 ,
V_207 , V_7 -> V_144 ,
F_97 ( V_7 ) | V_208 ,
V_163 , V_47 , V_56 , V_59 -> V_138 ) ;
F_98 ( V_7 , F_99 ( V_136 ) ) ;
V_161 = F_100 ( V_1 , V_136 , V_7 ) ;
if ( F_101 ( V_161 ) ) {
V_90 = F_102 ( V_161 ) ;
V_161 = NULL ;
if ( V_90 == - V_209 )
F_103 ( V_1 , V_210 ) ;
goto V_98;
}
V_90 = - V_211 ;
if ( ( V_161 -> V_212 & V_213 ) &&
! F_93 ( V_7 , V_214 ) )
goto V_98;
if ( V_162 )
F_104 ( V_7 , F_105 ( & V_161 -> V_121 ) ) ;
}
if ( V_155 -> V_167 & V_215 )
goto V_216;
V_217:
V_47 = V_136 -> V_47 ;
if ( ! V_159 . V_191 )
V_55 = V_159 . V_191 = V_136 -> V_55 ;
if ( ! V_165 ) {
V_74 = F_106 ( V_7 , V_136 , F_85 , V_155 -> V_218 , V_157 ,
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
F_107 (KERN_DEBUG pr_fmt(L_1)) ;
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
V_90 = F_108 ( V_7 , V_136 , F_85 , V_155 -> V_218 , V_157 ,
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
V_216:
F_112 ( & V_161 -> V_121 ) ;
if ( ! ( V_155 -> V_167 & V_224 ) || V_119 )
goto V_217;
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
F_107 (KERN_DEBUG pr_fmt(L_2)) ;
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
int V_245 , V_246 = 0 ;
int V_90 ;
int V_137 = F_76 ( V_7 ) ;
bool V_234 ;
if ( V_243 )
* V_243 = sizeof( * sin ) ;
if ( V_223 & V_247 )
return F_132 ( V_7 , V_155 , V_119 ) ;
V_248:
V_74 = F_133 ( V_7 , V_223 | ( V_242 ? V_249 : 0 ) ,
& V_245 , & V_246 , & V_90 ) ;
if ( ! V_74 )
goto V_98;
V_157 = V_74 -> V_119 - sizeof( struct V_85 ) ;
V_244 = V_119 ;
if ( V_244 > V_157 )
V_244 = V_157 ;
else if ( V_244 < V_157 )
V_155 -> V_167 |= V_250 ;
if ( V_244 < V_157 || F_134 ( V_74 ) -> V_251 ) {
if ( F_119 ( V_74 ) )
goto V_252;
}
if ( F_135 ( V_74 ) )
V_90 = F_136 ( V_74 , sizeof( struct V_85 ) ,
V_155 -> V_218 , V_244 ) ;
else {
V_90 = F_137 ( V_74 ,
sizeof( struct V_85 ) ,
V_155 -> V_218 ) ;
if ( V_90 == - V_178 )
goto V_252;
}
if ( V_90 )
goto V_253;
if ( ! V_245 )
F_81 ( F_5 ( V_7 ) ,
V_254 , V_137 ) ;
F_138 ( V_155 , V_7 , V_74 ) ;
if ( sin ) {
sin -> V_184 = V_177 ;
sin -> V_189 = F_67 ( V_74 ) -> V_92 ;
sin -> V_187 . V_188 = F_50 ( V_74 ) -> V_47 ;
memset ( sin -> V_255 , 0 , sizeof( sin -> V_255 ) ) ;
}
if ( V_59 -> V_256 )
F_139 ( V_155 , V_74 ) ;
V_90 = V_244 ;
if ( V_223 & V_250 )
V_90 = V_157 ;
V_253:
F_140 ( V_7 , V_74 ) ;
V_98:
return V_90 ;
V_252:
V_234 = F_124 ( V_7 ) ;
if ( ! F_141 ( V_7 , V_74 , V_223 ) )
F_81 ( F_5 ( V_7 ) , V_232 , V_137 ) ;
F_127 ( V_7 , V_234 ) ;
if ( V_242 )
return - V_257 ;
V_155 -> V_167 &= ~ V_250 ;
goto V_248;
}
int F_142 ( struct V_6 * V_7 , int V_223 )
{
struct V_43 * V_59 = F_23 ( V_7 ) ;
V_7 -> V_111 = V_258 ;
V_59 -> V_62 = 0 ;
V_59 -> V_63 = 0 ;
F_143 ( V_7 ) ;
V_7 -> V_14 = 0 ;
if ( ! ( V_7 -> V_259 & V_260 ) )
F_144 ( V_7 ) ;
if ( ! ( V_7 -> V_259 & V_261 ) ) {
V_7 -> V_22 -> V_262 ( V_7 ) ;
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
void F_150 ( struct V_6 * V_7 , T_6 V_263 )
{
if ( F_147 ( V_7 ) ) {
struct V_20 * V_21 = V_7 -> V_22 -> V_23 . V_20 ;
struct V_3 * V_4 , * V_15 , * V_264 ;
V_15 = F_22 ( V_21 , F_6 ( V_7 ) -> V_37 ) ;
V_264 = F_22 ( V_21 , V_263 ) ;
F_6 ( V_7 ) -> V_37 = V_263 ;
if ( V_15 != V_264 ) {
V_4 = F_16 ( V_21 , F_5 ( V_7 ) ,
F_6 ( V_7 ) -> V_12 ) ;
F_18 ( & V_4 -> V_17 ) ;
F_9 ( & V_15 -> V_17 ) ;
F_149 ( & F_6 ( V_7 ) -> V_42 ) ;
V_15 -> V_34 -- ;
F_11 ( & V_15 -> V_17 ) ;
F_9 ( & V_264 -> V_17 ) ;
F_27 ( & F_6 ( V_7 ) -> V_42 ,
& V_264 -> V_41 ) ;
V_264 -> V_34 ++ ;
F_11 ( & V_264 -> V_17 ) ;
F_21 ( & V_4 -> V_17 ) ;
}
}
}
static void F_151 ( struct V_6 * V_7 )
{
T_6 V_265 = F_30 ( F_5 ( V_7 ) ,
F_23 ( V_7 ) -> V_46 ,
F_23 ( V_7 ) -> V_40 ) ;
F_150 ( V_7 , V_265 ) ;
}
static int F_152 ( struct V_6 * V_7 , struct V_73 * V_74 )
{
int V_266 ;
if ( F_23 ( V_7 ) -> V_62 )
F_153 ( V_7 , V_74 ) ;
V_266 = F_154 ( V_7 , V_74 ) ;
if ( V_266 < 0 ) {
int V_137 = F_76 ( V_7 ) ;
if ( V_266 == - V_267 )
F_120 ( F_5 ( V_7 ) , V_268 ,
V_137 ) ;
F_120 ( F_5 ( V_7 ) , V_232 , V_137 ) ;
F_155 ( V_74 ) ;
F_156 ( V_266 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_157 ( void )
{
if ( ! F_158 ( & V_269 ) )
F_159 ( & V_269 ) ;
}
int F_160 ( struct V_6 * V_7 , struct V_73 * V_74 )
{
struct V_116 * V_117 = F_6 ( V_7 ) ;
int V_266 ;
int V_137 = F_76 ( V_7 ) ;
if ( ! F_161 ( V_7 , V_270 , V_74 ) )
goto V_271;
F_162 ( V_74 ) ;
if ( F_163 ( & V_269 ) && V_117 -> V_272 ) {
int (* F_164)( struct V_6 * V_7 , struct V_73 * V_74 );
F_164 = F_165 ( V_117 -> F_164 ) ;
if ( V_74 -> V_119 > sizeof( struct V_85 ) && F_164 != NULL ) {
int V_227 ;
V_227 = F_164 ( V_7 , V_74 ) ;
if ( V_227 <= 0 ) {
F_120 ( F_5 ( V_7 ) ,
V_254 ,
V_137 ) ;
return - V_227 ;
}
}
}
if ( ( V_137 & V_273 ) && F_134 ( V_74 ) -> V_251 ) {
if ( V_117 -> V_274 == 0 ) {
F_107 ( V_275 L_3 ,
F_134 ( V_74 ) -> V_276 , V_74 -> V_119 ) ;
goto V_271;
}
if ( F_134 ( V_74 ) -> V_276 < V_117 -> V_274 ) {
F_107 ( V_275 L_4 ,
F_134 ( V_74 ) -> V_276 , V_117 -> V_274 ) ;
goto V_271;
}
}
if ( F_166 ( V_7 -> V_277 ) &&
F_119 ( V_74 ) )
goto V_271;
if ( F_167 ( V_7 , V_74 , V_7 -> V_278 ) )
goto V_271;
V_266 = 0 ;
F_168 ( V_74 ) ;
F_169 ( V_7 ) ;
if ( ! F_170 ( V_7 ) )
V_266 = F_152 ( V_7 , V_74 ) ;
else if ( F_171 ( V_7 , V_74 , V_7 -> V_278 ) ) {
F_172 ( V_7 ) ;
goto V_271;
}
F_172 ( V_7 ) ;
return V_266 ;
V_271:
F_120 ( F_5 ( V_7 ) , V_232 , V_137 ) ;
F_121 ( & V_7 -> V_233 ) ;
F_155 ( V_74 ) ;
return - 1 ;
}
static void F_173 ( struct V_6 * * V_279 , unsigned int V_34 ,
struct V_73 * V_74 , unsigned int V_280 )
{
unsigned int V_281 ;
struct V_73 * V_282 = NULL ;
struct V_6 * V_7 ;
for ( V_281 = 0 ; V_281 < V_34 ; V_281 ++ ) {
V_7 = V_279 [ V_281 ] ;
if ( F_87 ( V_282 == NULL ) )
V_282 = ( V_281 == V_280 ) ? V_74 : F_174 ( V_74 , V_283 ) ;
if ( ! V_282 ) {
F_121 ( & V_7 -> V_233 ) ;
F_120 ( F_5 ( V_7 ) , V_268 ,
F_76 ( V_7 ) ) ;
F_120 ( F_5 ( V_7 ) , V_232 ,
F_76 ( V_7 ) ) ;
}
if ( V_282 && F_160 ( V_7 , V_282 ) <= 0 )
V_282 = NULL ;
}
if ( F_40 ( V_282 ) )
F_155 ( V_282 ) ;
}
static int F_175 ( struct V_1 * V_1 , struct V_73 * V_74 ,
struct V_85 * V_86 ,
T_2 V_47 , T_2 V_55 ,
struct V_20 * V_21 )
{
struct V_6 * V_7 , * V_279 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_3 * V_4 = F_16 ( V_21 , V_1 , F_44 ( V_86 -> V_91 ) ) ;
int V_57 ;
unsigned int V_281 , V_34 = 0 ;
F_9 ( & V_4 -> V_17 ) ;
V_7 = F_176 ( & V_4 -> V_41 ) ;
V_57 = V_74 -> V_77 -> V_93 ;
V_7 = F_56 ( V_1 , V_7 , V_86 -> V_91 , V_55 , V_86 -> V_92 , V_47 , V_57 ) ;
while ( V_7 ) {
V_279 [ V_34 ++ ] = V_7 ;
V_7 = F_56 ( V_1 , F_177 ( V_7 ) , V_86 -> V_91 ,
V_55 , V_86 -> V_92 , V_47 , V_57 ) ;
if ( F_40 ( V_34 == F_178 ( V_279 ) ) ) {
if ( ! V_7 )
break;
F_173 ( V_279 , V_34 , V_74 , ~ 0 ) ;
V_34 = 0 ;
}
}
for ( V_281 = 0 ; V_281 < V_34 ; V_281 ++ )
F_179 ( V_279 [ V_281 ] ) ;
F_11 ( & V_4 -> V_17 ) ;
if ( V_34 ) {
F_173 ( V_279 , V_34 , V_74 , V_34 - 1 ) ;
for ( V_281 = 0 ; V_281 < V_34 ; V_281 ++ )
F_42 ( V_279 [ V_281 ] ) ;
} else {
F_155 ( V_74 ) ;
}
return 0 ;
}
static inline int F_180 ( struct V_73 * V_74 , struct V_85 * V_86 ,
int V_284 )
{
const struct V_75 * V_76 ;
int V_90 ;
F_134 ( V_74 ) -> V_251 = 0 ;
F_134 ( V_74 ) -> V_276 = V_74 -> V_119 ;
if ( V_284 == V_285 ) {
V_90 = F_181 ( V_74 , V_86 ) ;
if ( V_90 )
return V_90 ;
}
V_76 = F_50 ( V_74 ) ;
if ( V_86 -> V_129 == 0 ) {
V_74 -> V_132 = V_286 ;
} else if ( V_74 -> V_132 == V_287 ) {
if ( ! F_72 ( V_76 -> V_47 , V_76 -> V_55 , V_74 -> V_119 ,
V_284 , V_74 -> V_126 ) )
V_74 -> V_132 = V_286 ;
}
if ( ! F_135 ( V_74 ) )
V_74 -> V_126 = F_182 ( V_76 -> V_47 , V_76 -> V_55 ,
V_74 -> V_119 , V_284 , 0 ) ;
return 0 ;
}
int F_183 ( struct V_73 * V_74 , struct V_20 * V_21 ,
int V_284 )
{
struct V_6 * V_7 ;
struct V_85 * V_86 ;
unsigned short V_157 ;
struct V_160 * V_161 = F_184 ( V_74 ) ;
T_2 V_47 , V_55 ;
struct V_1 * V_1 = F_52 ( V_74 -> V_77 ) ;
if ( ! F_185 ( V_74 , sizeof( struct V_85 ) ) )
goto V_271;
V_86 = F_67 ( V_74 ) ;
V_157 = F_44 ( V_86 -> V_119 ) ;
V_47 = F_50 ( V_74 ) -> V_47 ;
V_55 = F_50 ( V_74 ) -> V_55 ;
if ( V_157 > V_74 -> V_119 )
goto V_288;
if ( V_284 == V_130 ) {
if ( V_157 < sizeof( * V_86 ) || F_186 ( V_74 , V_157 ) )
goto V_288;
V_86 = F_67 ( V_74 ) ;
}
if ( F_180 ( V_74 , V_86 , V_284 ) )
goto V_289;
if ( V_161 -> V_212 & ( V_213 | V_290 ) )
return F_175 ( V_1 , V_74 , V_86 ,
V_47 , V_55 , V_21 ) ;
V_7 = F_49 ( V_74 , V_86 -> V_92 , V_86 -> V_91 , V_21 ) ;
if ( V_7 != NULL ) {
int V_227 = F_160 ( V_7 , V_74 ) ;
F_42 ( V_7 ) ;
if ( V_227 > 0 )
return - V_227 ;
return 0 ;
}
if ( ! F_161 ( NULL , V_270 , V_74 ) )
goto V_271;
F_162 ( V_74 ) ;
if ( F_119 ( V_74 ) )
goto V_289;
F_120 ( V_1 , V_291 , V_284 == V_285 ) ;
F_187 ( V_74 , V_101 , V_292 , 0 ) ;
F_155 ( V_74 ) ;
return 0 ;
V_288:
F_107 ( V_293 L_5 ,
V_284 == V_285 ? L_6 : L_7 ,
& V_47 , F_44 ( V_86 -> V_92 ) ,
V_157 , V_74 -> V_119 ,
& V_55 , F_44 ( V_86 -> V_91 ) ) ;
goto V_271;
V_289:
F_107 ( V_293 L_8 ,
V_284 == V_285 ? L_6 : L_7 ,
& V_47 , F_44 ( V_86 -> V_92 ) , & V_55 , F_44 ( V_86 -> V_91 ) ,
V_157 ) ;
V_271:
F_120 ( V_1 , V_232 , V_284 == V_285 ) ;
F_155 ( V_74 ) ;
return 0 ;
}
int F_188 ( struct V_73 * V_74 )
{
return F_183 ( V_74 , & V_20 , V_130 ) ;
}
void F_189 ( struct V_6 * V_7 )
{
bool V_234 = F_124 ( V_7 ) ;
F_64 ( V_7 ) ;
F_127 ( V_7 , V_234 ) ;
}
int F_190 ( struct V_6 * V_7 , int V_294 , int V_295 ,
char V_239 * V_296 , unsigned int V_197 ,
int (* F_191)( struct V_6 * ) )
{
struct V_116 * V_117 = F_6 ( V_7 ) ;
int V_297 ;
int V_90 = 0 ;
int V_137 = F_76 ( V_7 ) ;
if ( V_197 < sizeof( int ) )
return - V_178 ;
if ( F_192 ( V_297 , ( int V_239 * ) V_296 ) )
return - V_298 ;
switch ( V_295 ) {
case V_299 :
if ( V_297 != 0 ) {
V_117 -> V_166 = 1 ;
} else {
V_117 -> V_166 = 0 ;
F_86 ( V_7 ) ;
(* F_191)( V_7 ) ;
F_88 ( V_7 ) ;
}
break;
case V_300 :
switch ( V_297 ) {
case 0 :
case V_301 :
case V_302 :
V_117 -> F_164 = V_303 ;
case V_304 :
V_117 -> V_272 = V_297 ;
F_157 () ;
break;
default:
V_90 = - V_305 ;
break;
}
break;
case V_306 :
if ( ! V_137 )
return - V_305 ;
if ( V_297 != 0 && V_297 < 8 )
V_297 = 8 ;
else if ( V_297 > V_307 )
V_297 = V_307 ;
V_117 -> V_308 = V_297 ;
V_117 -> V_309 |= V_310 ;
break;
case V_311 :
if ( ! V_137 )
return - V_305 ;
if ( V_297 != 0 && V_297 < 8 )
V_297 = 8 ;
else if ( V_297 > V_307 )
V_297 = V_307 ;
V_117 -> V_274 = V_297 ;
V_117 -> V_309 |= V_273 ;
break;
default:
V_90 = - V_305 ;
break;
}
return V_90 ;
}
int F_193 ( struct V_6 * V_7 , int V_294 , int V_295 ,
char V_239 * V_296 , unsigned int V_197 )
{
if ( V_294 == V_312 || V_294 == V_313 )
return F_190 ( V_7 , V_294 , V_295 , V_296 , V_197 ,
F_82 ) ;
return F_194 ( V_7 , V_294 , V_295 , V_296 , V_197 ) ;
}
int F_195 ( struct V_6 * V_7 , int V_294 , int V_295 ,
char V_239 * V_296 , unsigned int V_197 )
{
if ( V_294 == V_312 || V_294 == V_313 )
return F_190 ( V_7 , V_294 , V_295 , V_296 , V_197 ,
F_82 ) ;
return F_196 ( V_7 , V_294 , V_295 , V_296 , V_197 ) ;
}
int F_197 ( struct V_6 * V_7 , int V_294 , int V_295 ,
char V_239 * V_296 , int V_239 * V_197 )
{
struct V_116 * V_117 = F_6 ( V_7 ) ;
int V_297 , V_119 ;
if ( F_192 ( V_119 , V_197 ) )
return - V_298 ;
V_119 = F_198 (unsigned int, len, sizeof(int)) ;
if ( V_119 < 0 )
return - V_178 ;
switch ( V_295 ) {
case V_299 :
V_297 = V_117 -> V_166 ;
break;
case V_300 :
V_297 = V_117 -> V_272 ;
break;
case V_306 :
V_297 = V_117 -> V_308 ;
break;
case V_311 :
V_297 = V_117 -> V_274 ;
break;
default:
return - V_305 ;
}
if ( F_130 ( V_119 , V_197 ) )
return - V_298 ;
if ( F_199 ( V_296 , & V_297 , V_119 ) )
return - V_298 ;
return 0 ;
}
int F_200 ( struct V_6 * V_7 , int V_294 , int V_295 ,
char V_239 * V_296 , int V_239 * V_197 )
{
if ( V_294 == V_312 || V_294 == V_313 )
return F_197 ( V_7 , V_294 , V_295 , V_296 , V_197 ) ;
return F_201 ( V_7 , V_294 , V_295 , V_296 , V_197 ) ;
}
int F_202 ( struct V_6 * V_7 , int V_294 , int V_295 ,
char V_239 * V_296 , int V_239 * V_197 )
{
if ( V_294 == V_312 || V_294 == V_313 )
return F_197 ( V_7 , V_294 , V_295 , V_296 , V_197 ) ;
return F_203 ( V_7 , V_294 , V_295 , V_296 , V_197 ) ;
}
unsigned int F_204 ( struct V_314 * V_314 , struct V_315 * V_6 , T_7 * V_316 )
{
unsigned int V_31 = F_205 ( V_314 , V_6 , V_316 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
if ( ( V_31 & V_317 ) && ! ( V_314 -> V_318 & V_319 ) &&
! ( V_7 -> V_320 & V_321 ) && ! F_116 ( V_7 ) )
V_31 &= ~ ( V_322 | V_317 ) ;
return V_31 ;
}
static struct V_6 * F_206 ( struct V_323 * V_324 , int V_325 )
{
struct V_6 * V_7 ;
struct V_326 * V_327 = V_324 -> V_328 ;
struct V_1 * V_1 = F_207 ( V_324 ) ;
for ( V_327 -> V_329 = V_325 ; V_327 -> V_329 <= V_327 -> V_20 -> V_31 ;
++ V_327 -> V_329 ) {
struct V_10 * V_11 ;
struct V_3 * V_4 = & V_327 -> V_20 -> V_72 [ V_327 -> V_329 ] ;
if ( F_208 ( & V_4 -> V_41 ) )
continue;
F_18 ( & V_4 -> V_17 ) ;
F_3 (sk, node, &hslot->head) {
if ( ! F_4 ( F_5 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_60 == V_327 -> V_330 )
goto V_32;
}
F_21 ( & V_4 -> V_17 ) ;
}
V_7 = NULL ;
V_32:
return V_7 ;
}
static struct V_6 * F_209 ( struct V_323 * V_324 , struct V_6 * V_7 )
{
struct V_326 * V_327 = V_324 -> V_328 ;
struct V_1 * V_1 = F_207 ( V_324 ) ;
do {
V_7 = F_177 ( V_7 ) ;
} while ( V_7 && ( ! F_4 ( F_5 ( V_7 ) , V_1 ) || V_7 -> V_60 != V_327 -> V_330 ) );
if ( ! V_7 ) {
if ( V_327 -> V_329 <= V_327 -> V_20 -> V_31 )
F_21 ( & V_327 -> V_20 -> V_72 [ V_327 -> V_329 ] . V_17 ) ;
return F_206 ( V_324 , V_327 -> V_329 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_210 ( struct V_323 * V_324 , T_8 V_331 )
{
struct V_6 * V_7 = F_206 ( V_324 , 0 ) ;
if ( V_7 )
while ( V_331 && ( V_7 = F_209 ( V_324 , V_7 ) ) != NULL )
-- V_331 ;
return V_331 ? NULL : V_7 ;
}
static void * F_211 ( struct V_323 * V_324 , T_8 * V_331 )
{
struct V_326 * V_327 = V_324 -> V_328 ;
V_327 -> V_329 = V_332 ;
return * V_331 ? F_210 ( V_324 , * V_331 - 1 ) : V_333 ;
}
static void * F_212 ( struct V_323 * V_324 , void * V_334 , T_8 * V_331 )
{
struct V_6 * V_7 ;
if ( V_334 == V_333 )
V_7 = F_210 ( V_324 , 0 ) ;
else
V_7 = F_209 ( V_324 , V_334 ) ;
++ * V_331 ;
return V_7 ;
}
static void F_213 ( struct V_323 * V_324 , void * V_334 )
{
struct V_326 * V_327 = V_324 -> V_328 ;
if ( V_327 -> V_329 <= V_327 -> V_20 -> V_31 )
F_21 ( & V_327 -> V_20 -> V_72 [ V_327 -> V_329 ] . V_17 ) ;
}
int F_214 ( struct V_335 * V_335 , struct V_314 * V_314 )
{
struct V_336 * V_337 = F_215 ( V_335 ) -> V_84 ;
struct V_326 * V_82 ;
int V_90 ;
V_90 = F_216 ( V_335 , V_314 , & V_337 -> V_338 ,
sizeof( struct V_326 ) ) ;
if ( V_90 < 0 )
return V_90 ;
V_82 = ( (struct V_323 * ) V_314 -> V_339 ) -> V_328 ;
V_82 -> V_330 = V_337 -> V_330 ;
V_82 -> V_20 = V_337 -> V_20 ;
return V_90 ;
}
int F_217 ( struct V_1 * V_1 , struct V_336 * V_337 )
{
struct V_340 * V_341 ;
int V_266 = 0 ;
V_337 -> V_338 . V_325 = F_211 ;
V_337 -> V_338 . V_131 = F_212 ;
V_337 -> V_338 . V_342 = F_213 ;
V_341 = F_218 ( V_337 -> V_343 , V_344 , V_1 -> V_345 ,
V_337 -> V_346 , V_337 ) ;
if ( ! V_341 )
V_266 = - V_267 ;
return V_266 ;
}
void F_219 ( struct V_1 * V_1 , struct V_336 * V_337 )
{
F_220 ( V_1 , V_337 -> V_343 ) ;
}
static void F_221 ( struct V_6 * V_347 , struct V_323 * V_348 ,
int V_329 , int * V_119 )
{
struct V_43 * V_59 = F_23 ( V_347 ) ;
T_2 V_91 = V_59 -> V_62 ;
T_2 V_120 = V_59 -> V_46 ;
T_1 V_349 = F_44 ( V_59 -> V_63 ) ;
T_1 V_350 = F_44 ( V_59 -> V_138 ) ;
F_222 ( V_348 , L_9
L_10 ,
V_329 , V_120 , V_350 , V_91 , V_349 , V_347 -> V_111 ,
F_129 ( V_347 ) ,
F_223 ( V_347 ) ,
0 , 0L , 0 , F_224 ( V_347 ) , 0 , F_225 ( V_347 ) ,
F_226 ( & V_347 -> V_69 ) , V_347 ,
F_226 ( & V_347 -> V_233 ) , V_119 ) ;
}
int F_227 ( struct V_323 * V_324 , void * V_334 )
{
if ( V_334 == V_333 )
F_222 ( V_324 , L_11 ,
L_12
L_13
L_14 ) ;
else {
struct V_326 * V_327 = V_324 -> V_328 ;
int V_119 ;
F_221 ( V_334 , V_324 , V_327 -> V_329 , & V_119 ) ;
F_222 ( V_324 , L_15 , 127 - V_119 , L_7 ) ;
}
return 0 ;
}
static int T_9 F_228 ( struct V_1 * V_1 )
{
return F_217 ( V_1 , & V_351 ) ;
}
static void T_10 F_229 ( struct V_1 * V_1 )
{
F_219 ( V_1 , & V_351 ) ;
}
int T_11 F_230 ( void )
{
return F_231 ( & V_352 ) ;
}
void F_232 ( void )
{
F_233 ( & V_352 ) ;
}
static int T_11 F_234 ( char * V_353 )
{
T_12 V_227 ;
if ( ! V_353 )
return 0 ;
V_227 = F_235 ( V_353 , 0 , & V_354 ) ;
if ( V_227 )
return 0 ;
if ( V_354 && V_354 < V_355 )
V_354 = V_355 ;
return 1 ;
}
void T_11 F_236 ( struct V_20 * V_356 , const char * V_343 )
{
unsigned int V_281 ;
V_356 -> V_72 = F_237 ( V_343 ,
2 * sizeof( struct V_3 ) ,
V_354 ,
21 ,
0 ,
& V_356 -> log ,
& V_356 -> V_31 ,
V_355 ,
64 * 1024 ) ;
V_356 -> V_70 = V_356 -> V_72 + ( V_356 -> V_31 + 1 ) ;
for ( V_281 = 0 ; V_281 <= V_356 -> V_31 ; V_281 ++ ) {
F_238 ( & V_356 -> V_72 [ V_281 ] . V_41 , V_281 ) ;
V_356 -> V_72 [ V_281 ] . V_34 = 0 ;
F_239 ( & V_356 -> V_72 [ V_281 ] . V_17 ) ;
}
for ( V_281 = 0 ; V_281 <= V_356 -> V_31 ; V_281 ++ ) {
F_238 ( & V_356 -> V_70 [ V_281 ] . V_41 , V_281 ) ;
V_356 -> V_70 [ V_281 ] . V_34 = 0 ;
F_239 ( & V_356 -> V_70 [ V_281 ] . V_17 ) ;
}
}
void T_11 F_240 ( void )
{
unsigned long V_357 ;
F_236 ( & V_20 , L_16 ) ;
V_357 = F_241 () / 8 ;
V_357 = F_242 ( V_357 , 128UL ) ;
V_358 [ 0 ] = V_357 / 4 * 3 ;
V_358 [ 1 ] = V_357 ;
V_358 [ 2 ] = V_358 [ 0 ] * 2 ;
V_359 = V_360 ;
V_361 = V_360 ;
}
int F_243 ( struct V_73 * V_74 )
{
const struct V_75 * V_76 ;
struct V_85 * V_86 ;
if ( ! F_185 ( V_74 , sizeof( * V_86 ) ) )
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
struct V_73 * F_244 ( struct V_73 * V_74 ,
T_13 V_362 )
{
struct V_73 * V_363 = F_245 ( - V_178 ) ;
unsigned int V_364 ;
int V_124 ;
T_4 V_126 ;
V_364 = F_68 ( V_74 ) -> V_365 ;
if ( F_40 ( V_74 -> V_119 <= V_364 ) )
goto V_98;
if ( F_246 ( V_74 , V_362 | V_366 ) ) {
int type = F_68 ( V_74 ) -> V_367 ;
if ( F_40 ( type & ~ ( V_368 | V_369 ) ||
! ( type & ( V_368 ) ) ) )
goto V_98;
F_68 ( V_74 ) -> V_370 = F_247 ( V_74 -> V_119 , V_364 ) ;
V_363 = NULL ;
goto V_98;
}
V_124 = F_248 ( V_74 ) ;
V_126 = F_74 ( V_74 , V_124 , V_74 -> V_119 - V_124 , 0 ) ;
V_124 += V_74 -> V_128 ;
* ( V_371 * ) ( V_74 -> V_84 + V_124 ) = F_249 ( V_126 ) ;
V_74 -> V_132 = V_133 ;
V_363 = F_250 ( V_74 , V_362 ) ;
V_98:
return V_363 ;
}
