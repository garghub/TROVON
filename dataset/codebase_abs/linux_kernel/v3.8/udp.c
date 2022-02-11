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
F_62 ( V_74 , V_7 , V_83 ) ;
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
case V_110 :
F_63 ( V_74 , V_7 ) ;
break;
}
if ( ! V_59 -> V_111 ) {
if ( ! V_89 || V_7 -> V_112 != V_113 )
goto V_98;
} else
F_64 ( V_7 , V_74 , V_90 , V_86 -> V_91 , V_83 , ( V_114 * ) ( V_86 + 1 ) ) ;
V_7 -> V_115 = V_90 ;
V_7 -> V_116 ( V_7 ) ;
V_98:
F_42 ( V_7 ) ;
}
void F_65 ( struct V_73 * V_74 , V_50 V_83 )
{
F_59 ( V_74 , V_83 , & V_20 ) ;
}
void F_66 ( struct V_6 * V_7 )
{
struct V_117 * V_118 = F_6 ( V_7 ) ;
if ( V_118 -> V_119 ) {
V_118 -> V_120 = 0 ;
V_118 -> V_119 = 0 ;
F_67 ( V_7 ) ;
}
}
static void F_68 ( struct V_73 * V_74 , T_2 V_121 , T_2 V_122 )
{
struct V_85 * V_86 = F_69 ( V_74 ) ;
struct V_73 * V_123 = F_70 ( V_74 ) -> V_124 ;
int V_125 = F_71 ( V_74 ) ;
int V_120 = V_74 -> V_120 - V_125 ;
int V_126 = V_120 ;
T_4 V_127 = 0 ;
if ( ! V_123 ) {
V_74 -> V_128 = F_72 ( V_74 ) - V_74 -> V_41 ;
V_74 -> V_129 = F_73 ( struct V_85 , V_130 ) ;
V_86 -> V_130 = ~ F_74 ( V_121 , V_122 , V_120 ,
V_131 , 0 ) ;
} else {
do {
V_127 = F_75 ( V_127 , V_123 -> V_127 ) ;
V_126 -= V_123 -> V_120 ;
} while ( ( V_123 = V_123 -> V_132 ) );
V_127 = F_76 ( V_74 , V_125 , V_126 , V_127 ) ;
V_74 -> V_133 = V_134 ;
V_86 -> V_130 = F_74 ( V_121 , V_122 , V_120 , V_131 , V_127 ) ;
if ( V_86 -> V_130 == 0 )
V_86 -> V_130 = V_135 ;
}
}
static int F_77 ( struct V_73 * V_74 , struct V_136 * V_137 )
{
struct V_6 * V_7 = V_74 -> V_7 ;
struct V_43 * V_59 = F_23 ( V_7 ) ;
struct V_85 * V_86 ;
int V_90 = 0 ;
int V_138 = F_78 ( V_7 ) ;
int V_125 = F_71 ( V_74 ) ;
int V_120 = V_74 -> V_120 - V_125 ;
T_4 V_127 = 0 ;
V_86 = F_69 ( V_74 ) ;
V_86 -> V_92 = V_59 -> V_139 ;
V_86 -> V_91 = V_137 -> V_140 ;
V_86 -> V_120 = F_79 ( V_120 ) ;
V_86 -> V_130 = 0 ;
if ( V_138 )
V_127 = F_80 ( V_74 ) ;
else if ( V_7 -> V_141 == V_142 ) {
V_74 -> V_133 = V_134 ;
goto V_143;
} else if ( V_74 -> V_133 == V_144 ) {
F_68 ( V_74 , V_137 -> V_47 , V_137 -> V_55 ) ;
goto V_143;
} else
V_127 = F_81 ( V_74 ) ;
V_86 -> V_130 = F_74 ( V_137 -> V_47 , V_137 -> V_55 , V_120 ,
V_7 -> V_145 , V_127 ) ;
if ( V_86 -> V_130 == 0 )
V_86 -> V_130 = V_135 ;
V_143:
V_90 = F_82 ( F_5 ( V_7 ) , V_74 ) ;
if ( V_90 ) {
if ( V_90 == - V_146 && ! V_59 -> V_111 ) {
F_83 ( F_5 ( V_7 ) ,
V_147 , V_138 ) ;
V_90 = 0 ;
}
} else
F_83 ( F_5 ( V_7 ) ,
V_148 , V_138 ) ;
return V_90 ;
}
static int F_84 ( struct V_6 * V_7 )
{
struct V_117 * V_118 = F_6 ( V_7 ) ;
struct V_43 * V_59 = F_23 ( V_7 ) ;
struct V_136 * V_137 = & V_59 -> V_149 . V_150 . V_151 . V_152 ;
struct V_73 * V_74 ;
int V_90 = 0 ;
V_74 = F_85 ( V_7 , V_137 ) ;
if ( ! V_74 )
goto V_98;
V_90 = F_77 ( V_74 , V_137 ) ;
V_98:
V_118 -> V_120 = 0 ;
V_118 -> V_119 = 0 ;
return V_90 ;
}
int F_86 ( struct V_153 * V_154 , struct V_6 * V_7 , struct V_155 * V_156 ,
T_5 V_120 )
{
struct V_43 * V_59 = F_23 ( V_7 ) ;
struct V_117 * V_118 = F_6 ( V_7 ) ;
struct V_136 V_157 ;
struct V_136 * V_137 ;
int V_158 = V_120 ;
struct V_159 V_160 ;
struct V_161 * V_162 = NULL ;
int free = 0 ;
int V_163 = 0 ;
T_2 V_55 , V_164 , V_47 ;
T_3 V_56 ;
V_114 V_165 ;
int V_90 , V_138 = F_78 ( V_7 ) ;
int V_166 = V_118 -> V_167 || V_156 -> V_168 & V_169 ;
int (* F_87)( void * , char * , int , int , int , struct V_73 * );
struct V_73 * V_74 ;
struct V_170 V_171 ;
if ( V_120 > 0xFFFF )
return - V_105 ;
if ( V_156 -> V_168 & V_172 )
return - V_173 ;
V_160 . V_174 = NULL ;
V_160 . V_175 = 0 ;
F_87 = V_138 ? V_176 : V_177 ;
V_137 = & V_59 -> V_149 . V_150 . V_151 . V_152 ;
if ( V_118 -> V_119 ) {
F_88 ( V_7 ) ;
if ( F_89 ( V_118 -> V_119 ) ) {
if ( F_40 ( V_118 -> V_119 != V_178 ) ) {
F_90 ( V_7 ) ;
return - V_179 ;
}
goto V_180;
}
F_90 ( V_7 ) ;
}
V_158 += sizeof( struct V_85 ) ;
if ( V_156 -> V_181 ) {
struct V_182 * V_183 = (struct V_182 * ) V_156 -> V_181 ;
if ( V_156 -> V_184 < sizeof( * V_183 ) )
return - V_179 ;
if ( V_183 -> V_185 != V_178 ) {
if ( V_183 -> V_185 != V_186 )
return - V_187 ;
}
V_55 = V_183 -> V_188 . V_189 ;
V_56 = V_183 -> V_190 ;
if ( V_56 == 0 )
return - V_179 ;
} else {
if ( V_7 -> V_112 != V_113 )
return - V_191 ;
V_55 = V_59 -> V_62 ;
V_56 = V_59 -> V_63 ;
V_163 = 1 ;
}
V_160 . V_192 = V_59 -> V_193 ;
V_160 . V_194 = V_7 -> V_14 ;
V_90 = F_91 ( V_7 , & V_160 . V_175 ) ;
if ( V_90 )
return V_90 ;
if ( V_156 -> V_195 ) {
V_90 = F_92 ( F_5 ( V_7 ) , V_156 , & V_160 ) ;
if ( V_90 )
return V_90 ;
if ( V_160 . V_174 )
free = 1 ;
V_163 = 0 ;
}
if ( ! V_160 . V_174 ) {
struct V_196 * V_197 ;
F_46 () ;
V_197 = F_93 ( V_59 -> V_197 ) ;
if ( V_197 ) {
memcpy ( & V_171 , V_197 ,
sizeof( * V_197 ) + V_197 -> V_174 . V_198 ) ;
V_160 . V_174 = & V_171 . V_174 ;
}
F_47 () ;
}
V_47 = V_160 . V_192 ;
V_160 . V_192 = V_164 = V_55 ;
if ( V_160 . V_174 && V_160 . V_174 -> V_174 . V_199 ) {
if ( ! V_55 )
return - V_179 ;
V_164 = V_160 . V_174 -> V_174 . V_164 ;
V_163 = 0 ;
}
V_165 = F_94 ( V_59 -> V_165 ) ;
if ( F_95 ( V_7 , V_200 ) ||
( V_156 -> V_168 & V_201 ) ||
( V_160 . V_174 && V_160 . V_174 -> V_174 . V_202 ) ) {
V_165 |= V_203 ;
V_163 = 0 ;
}
if ( F_96 ( V_55 ) ) {
if ( ! V_160 . V_194 )
V_160 . V_194 = V_59 -> V_204 ;
if ( ! V_47 )
V_47 = V_59 -> V_205 ;
V_163 = 0 ;
} else if ( ! V_160 . V_194 )
V_160 . V_194 = V_59 -> V_206 ;
if ( V_163 )
V_162 = (struct V_161 * ) F_97 ( V_7 , 0 ) ;
if ( V_162 == NULL ) {
struct V_1 * V_1 = F_5 ( V_7 ) ;
V_137 = & V_157 ;
F_98 ( V_137 , V_160 . V_194 , V_7 -> V_207 , V_165 ,
V_208 , V_7 -> V_145 ,
F_99 ( V_7 ) | V_209 ,
V_164 , V_47 , V_56 , V_59 -> V_139 ) ;
F_100 ( V_7 , F_101 ( V_137 ) ) ;
V_162 = F_102 ( V_1 , V_137 , V_7 ) ;
if ( F_103 ( V_162 ) ) {
V_90 = F_104 ( V_162 ) ;
V_162 = NULL ;
if ( V_90 == - V_210 )
F_105 ( V_1 , V_211 ) ;
goto V_98;
}
V_90 = - V_212 ;
if ( ( V_162 -> V_213 & V_214 ) &&
! F_95 ( V_7 , V_215 ) )
goto V_98;
if ( V_163 )
F_106 ( V_7 , F_107 ( & V_162 -> V_122 ) ) ;
}
if ( V_156 -> V_168 & V_216 )
goto V_217;
V_218:
V_47 = V_137 -> V_47 ;
if ( ! V_160 . V_192 )
V_55 = V_160 . V_192 = V_137 -> V_55 ;
if ( ! V_166 ) {
V_74 = F_108 ( V_7 , V_137 , F_87 , V_156 -> V_219 , V_158 ,
sizeof( struct V_85 ) , & V_160 , & V_162 ,
V_156 -> V_168 ) ;
V_90 = F_104 ( V_74 ) ;
if ( V_74 && ! F_103 ( V_74 ) )
V_90 = F_77 ( V_74 , V_137 ) ;
goto V_98;
}
F_88 ( V_7 ) ;
if ( F_40 ( V_118 -> V_119 ) ) {
F_90 ( V_7 ) ;
F_109 (KERN_DEBUG pr_fmt(L_1)) ;
V_90 = - V_179 ;
goto V_98;
}
V_137 = & V_59 -> V_149 . V_150 . V_151 . V_152 ;
V_137 -> V_55 = V_55 ;
V_137 -> V_47 = V_47 ;
V_137 -> V_140 = V_56 ;
V_137 -> V_220 = V_59 -> V_139 ;
V_118 -> V_119 = V_178 ;
V_180:
V_118 -> V_120 += V_158 ;
V_90 = F_110 ( V_7 , V_137 , F_87 , V_156 -> V_219 , V_158 ,
sizeof( struct V_85 ) , & V_160 , & V_162 ,
V_166 ? V_156 -> V_168 | V_169 : V_156 -> V_168 ) ;
if ( V_90 )
F_66 ( V_7 ) ;
else if ( ! V_166 )
V_90 = F_84 ( V_7 ) ;
else if ( F_40 ( F_111 ( & V_7 -> V_221 ) ) )
V_118 -> V_119 = 0 ;
F_90 ( V_7 ) ;
V_98:
F_112 ( V_162 ) ;
if ( free )
F_113 ( V_160 . V_174 ) ;
if ( ! V_90 )
return V_120 ;
if ( V_90 == - V_146 || F_19 ( V_222 , & V_7 -> V_223 -> V_224 ) ) {
F_83 ( F_5 ( V_7 ) ,
V_147 , V_138 ) ;
}
return V_90 ;
V_217:
F_114 ( & V_162 -> V_122 ) ;
if ( ! ( V_156 -> V_168 & V_225 ) || V_120 )
goto V_218;
V_90 = 0 ;
goto V_98;
}
int F_115 ( struct V_6 * V_7 , struct V_226 * V_226 , int V_125 ,
T_5 V_227 , int V_224 )
{
struct V_43 * V_59 = F_23 ( V_7 ) ;
struct V_117 * V_118 = F_6 ( V_7 ) ;
int V_228 ;
if ( ! V_118 -> V_119 ) {
struct V_155 V_156 = { . V_168 = V_224 | V_169 } ;
V_228 = F_86 ( NULL , V_7 , & V_156 , 0 ) ;
if ( V_228 < 0 )
return V_228 ;
}
F_88 ( V_7 ) ;
if ( F_40 ( ! V_118 -> V_119 ) ) {
F_90 ( V_7 ) ;
F_109 (KERN_DEBUG pr_fmt(L_2)) ;
return - V_179 ;
}
V_228 = F_116 ( V_7 , & V_59 -> V_149 . V_150 . V_151 . V_152 ,
V_226 , V_125 , V_227 , V_224 ) ;
if ( V_228 == - V_173 ) {
F_90 ( V_7 ) ;
return F_117 ( V_7 -> V_223 , V_226 , V_125 ,
V_227 , V_224 ) ;
}
if ( V_228 < 0 ) {
F_66 ( V_7 ) ;
goto V_98;
}
V_118 -> V_120 += V_227 ;
if ( ! ( V_118 -> V_167 || ( V_224 & V_169 ) ) )
V_228 = F_84 ( V_7 ) ;
if ( ! V_228 )
V_228 = V_227 ;
V_98:
F_90 ( V_7 ) ;
return V_228 ;
}
static unsigned int F_118 ( struct V_6 * V_7 )
{
struct V_229 V_230 , * V_231 = & V_7 -> V_232 ;
struct V_73 * V_74 ;
unsigned int V_16 ;
F_119 ( & V_230 ) ;
F_18 ( & V_231 -> V_17 ) ;
while ( ( V_74 = F_120 ( V_231 ) ) != NULL &&
F_121 ( V_74 ) ) {
F_122 ( F_5 ( V_7 ) , V_233 ,
F_78 ( V_7 ) ) ;
F_123 ( & V_7 -> V_234 ) ;
F_124 ( V_74 , V_231 ) ;
F_125 ( & V_230 , V_74 ) ;
}
V_16 = V_74 ? V_74 -> V_120 : 0 ;
F_21 ( & V_231 -> V_17 ) ;
if ( ! F_111 ( & V_230 ) ) {
bool V_235 = F_126 ( V_7 ) ;
F_127 ( & V_230 ) ;
F_128 ( V_7 ) ;
F_129 ( V_7 , V_235 ) ;
}
return V_16 ;
}
int F_130 ( struct V_6 * V_7 , int V_236 , unsigned long V_237 )
{
switch ( V_236 ) {
case V_238 :
{
int V_239 = F_131 ( V_7 ) ;
return F_132 ( V_239 , ( int V_240 * ) V_237 ) ;
}
case V_241 :
{
unsigned int V_239 = F_118 ( V_7 ) ;
if ( V_239 )
V_239 -= sizeof( struct V_85 ) ;
return F_132 ( V_239 , ( int V_240 * ) V_237 ) ;
}
default:
return - V_242 ;
}
return 0 ;
}
int F_133 ( struct V_153 * V_154 , struct V_6 * V_7 , struct V_155 * V_156 ,
T_5 V_120 , int V_243 , int V_224 , int * V_244 )
{
struct V_43 * V_59 = F_23 ( V_7 ) ;
struct V_182 * sin = (struct V_182 * ) V_156 -> V_181 ;
struct V_73 * V_74 ;
unsigned int V_158 , V_245 ;
int V_246 , V_247 = 0 ;
int V_90 ;
int V_138 = F_78 ( V_7 ) ;
bool V_235 ;
if ( V_244 )
* V_244 = sizeof( * sin ) ;
if ( V_224 & V_248 )
return F_134 ( V_7 , V_156 , V_120 ) ;
V_249:
V_74 = F_135 ( V_7 , V_224 | ( V_243 ? V_250 : 0 ) ,
& V_246 , & V_247 , & V_90 ) ;
if ( ! V_74 )
goto V_98;
V_158 = V_74 -> V_120 - sizeof( struct V_85 ) ;
V_245 = V_120 ;
if ( V_245 > V_158 )
V_245 = V_158 ;
else if ( V_245 < V_158 )
V_156 -> V_168 |= V_251 ;
if ( V_245 < V_158 || F_136 ( V_74 ) -> V_252 ) {
if ( F_121 ( V_74 ) )
goto V_253;
}
if ( F_137 ( V_74 ) )
V_90 = F_138 ( V_74 , sizeof( struct V_85 ) ,
V_156 -> V_219 , V_245 ) ;
else {
V_90 = F_139 ( V_74 ,
sizeof( struct V_85 ) ,
V_156 -> V_219 ) ;
if ( V_90 == - V_179 )
goto V_253;
}
if ( F_40 ( V_90 ) ) {
F_140 ( V_74 , F_133 ) ;
if ( ! V_246 ) {
F_123 ( & V_7 -> V_234 ) ;
F_83 ( F_5 ( V_7 ) ,
V_233 , V_138 ) ;
}
goto V_254;
}
if ( ! V_246 )
F_83 ( F_5 ( V_7 ) ,
V_255 , V_138 ) ;
F_141 ( V_156 , V_7 , V_74 ) ;
if ( sin ) {
sin -> V_185 = V_178 ;
sin -> V_190 = F_69 ( V_74 ) -> V_92 ;
sin -> V_188 . V_189 = F_50 ( V_74 ) -> V_47 ;
memset ( sin -> V_256 , 0 , sizeof( sin -> V_256 ) ) ;
}
if ( V_59 -> V_257 )
F_142 ( V_156 , V_74 ) ;
V_90 = V_245 ;
if ( V_224 & V_251 )
V_90 = V_158 ;
V_254:
F_143 ( V_7 , V_74 ) ;
V_98:
return V_90 ;
V_253:
V_235 = F_126 ( V_7 ) ;
if ( ! F_144 ( V_7 , V_74 , V_224 ) )
F_83 ( F_5 ( V_7 ) , V_233 , V_138 ) ;
F_129 ( V_7 , V_235 ) ;
if ( V_243 )
return - V_258 ;
V_156 -> V_168 &= ~ V_251 ;
goto V_249;
}
int F_145 ( struct V_6 * V_7 , int V_224 )
{
struct V_43 * V_59 = F_23 ( V_7 ) ;
V_7 -> V_112 = V_259 ;
V_59 -> V_62 = 0 ;
V_59 -> V_63 = 0 ;
F_146 ( V_7 ) ;
V_7 -> V_14 = 0 ;
if ( ! ( V_7 -> V_260 & V_261 ) )
F_147 ( V_7 ) ;
if ( ! ( V_7 -> V_260 & V_262 ) ) {
V_7 -> V_22 -> V_263 ( V_7 ) ;
V_59 -> V_139 = 0 ;
}
F_148 ( V_7 ) ;
return 0 ;
}
void F_149 ( struct V_6 * V_7 )
{
if ( F_150 ( V_7 ) ) {
struct V_20 * V_21 = V_7 -> V_22 -> V_23 . V_20 ;
struct V_3 * V_4 , * V_15 ;
V_4 = F_16 ( V_21 , F_5 ( V_7 ) ,
F_6 ( V_7 ) -> V_12 ) ;
V_15 = F_22 ( V_21 , F_6 ( V_7 ) -> V_37 ) ;
F_18 ( & V_4 -> V_17 ) ;
if ( F_151 ( V_7 ) ) {
V_4 -> V_34 -- ;
F_23 ( V_7 ) -> V_40 = 0 ;
F_26 ( F_5 ( V_7 ) , V_7 -> V_22 , - 1 ) ;
F_9 ( & V_15 -> V_17 ) ;
F_152 ( & F_6 ( V_7 ) -> V_42 ) ;
V_15 -> V_34 -- ;
F_11 ( & V_15 -> V_17 ) ;
}
F_21 ( & V_4 -> V_17 ) ;
}
}
void F_153 ( struct V_6 * V_7 , T_6 V_264 )
{
if ( F_150 ( V_7 ) ) {
struct V_20 * V_21 = V_7 -> V_22 -> V_23 . V_20 ;
struct V_3 * V_4 , * V_15 , * V_265 ;
V_15 = F_22 ( V_21 , F_6 ( V_7 ) -> V_37 ) ;
V_265 = F_22 ( V_21 , V_264 ) ;
F_6 ( V_7 ) -> V_37 = V_264 ;
if ( V_15 != V_265 ) {
V_4 = F_16 ( V_21 , F_5 ( V_7 ) ,
F_6 ( V_7 ) -> V_12 ) ;
F_18 ( & V_4 -> V_17 ) ;
F_9 ( & V_15 -> V_17 ) ;
F_152 ( & F_6 ( V_7 ) -> V_42 ) ;
V_15 -> V_34 -- ;
F_11 ( & V_15 -> V_17 ) ;
F_9 ( & V_265 -> V_17 ) ;
F_27 ( & F_6 ( V_7 ) -> V_42 ,
& V_265 -> V_41 ) ;
V_265 -> V_34 ++ ;
F_11 ( & V_265 -> V_17 ) ;
F_21 ( & V_4 -> V_17 ) ;
}
}
}
static void F_154 ( struct V_6 * V_7 )
{
T_6 V_266 = F_30 ( F_5 ( V_7 ) ,
F_23 ( V_7 ) -> V_46 ,
F_23 ( V_7 ) -> V_40 ) ;
F_153 ( V_7 , V_266 ) ;
}
static int F_155 ( struct V_6 * V_7 , struct V_73 * V_74 )
{
int V_267 ;
if ( F_23 ( V_7 ) -> V_62 )
F_156 ( V_7 , V_74 ) ;
V_267 = F_157 ( V_7 , V_74 ) ;
if ( V_267 < 0 ) {
int V_138 = F_78 ( V_7 ) ;
if ( V_267 == - V_268 )
F_122 ( F_5 ( V_7 ) , V_269 ,
V_138 ) ;
F_122 ( F_5 ( V_7 ) , V_233 , V_138 ) ;
F_158 ( V_74 ) ;
F_159 ( V_267 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_160 ( void )
{
if ( ! F_161 ( & V_270 ) )
F_162 ( & V_270 ) ;
}
int F_163 ( struct V_6 * V_7 , struct V_73 * V_74 )
{
struct V_117 * V_118 = F_6 ( V_7 ) ;
int V_267 ;
int V_138 = F_78 ( V_7 ) ;
if ( ! F_164 ( V_7 , V_271 , V_74 ) )
goto V_272;
F_165 ( V_74 ) ;
if ( F_166 ( & V_270 ) && V_118 -> V_273 ) {
int (* F_167)( struct V_6 * V_7 , struct V_73 * V_74 );
F_167 = F_168 ( V_118 -> F_167 ) ;
if ( V_74 -> V_120 > sizeof( struct V_85 ) && F_167 != NULL ) {
int V_228 ;
V_228 = F_167 ( V_7 , V_74 ) ;
if ( V_228 <= 0 ) {
F_122 ( F_5 ( V_7 ) ,
V_255 ,
V_138 ) ;
return - V_228 ;
}
}
}
if ( ( V_138 & V_274 ) && F_136 ( V_74 ) -> V_252 ) {
if ( V_118 -> V_275 == 0 ) {
F_109 ( V_276 L_3 ,
F_136 ( V_74 ) -> V_277 , V_74 -> V_120 ) ;
goto V_272;
}
if ( F_136 ( V_74 ) -> V_277 < V_118 -> V_275 ) {
F_109 ( V_276 L_4 ,
F_136 ( V_74 ) -> V_277 , V_118 -> V_275 ) ;
goto V_272;
}
}
if ( F_169 ( V_7 -> V_278 ) &&
F_121 ( V_74 ) )
goto V_272;
if ( F_170 ( V_7 , V_74 , V_7 -> V_279 ) )
goto V_272;
V_267 = 0 ;
F_171 ( V_74 ) ;
F_172 ( V_7 ) ;
if ( ! F_173 ( V_7 ) )
V_267 = F_155 ( V_7 , V_74 ) ;
else if ( F_174 ( V_7 , V_74 , V_7 -> V_279 ) ) {
F_175 ( V_7 ) ;
goto V_272;
}
F_175 ( V_7 ) ;
return V_267 ;
V_272:
F_122 ( F_5 ( V_7 ) , V_233 , V_138 ) ;
F_123 ( & V_7 -> V_234 ) ;
F_158 ( V_74 ) ;
return - 1 ;
}
static void F_176 ( struct V_6 * * V_280 , unsigned int V_34 ,
struct V_73 * V_74 , unsigned int V_281 )
{
unsigned int V_282 ;
struct V_73 * V_283 = NULL ;
struct V_6 * V_7 ;
for ( V_282 = 0 ; V_282 < V_34 ; V_282 ++ ) {
V_7 = V_280 [ V_282 ] ;
if ( F_89 ( V_283 == NULL ) )
V_283 = ( V_282 == V_281 ) ? V_74 : F_177 ( V_74 , V_284 ) ;
if ( ! V_283 ) {
F_123 ( & V_7 -> V_234 ) ;
F_122 ( F_5 ( V_7 ) , V_269 ,
F_78 ( V_7 ) ) ;
F_122 ( F_5 ( V_7 ) , V_233 ,
F_78 ( V_7 ) ) ;
}
if ( V_283 && F_163 ( V_7 , V_283 ) <= 0 )
V_283 = NULL ;
}
if ( F_40 ( V_283 ) )
F_158 ( V_283 ) ;
}
static int F_178 ( struct V_1 * V_1 , struct V_73 * V_74 ,
struct V_85 * V_86 ,
T_2 V_47 , T_2 V_55 ,
struct V_20 * V_21 )
{
struct V_6 * V_7 , * V_280 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_3 * V_4 = F_16 ( V_21 , V_1 , F_44 ( V_86 -> V_91 ) ) ;
int V_57 ;
unsigned int V_282 , V_34 = 0 ;
F_9 ( & V_4 -> V_17 ) ;
V_7 = F_179 ( & V_4 -> V_41 ) ;
V_57 = V_74 -> V_77 -> V_93 ;
V_7 = F_56 ( V_1 , V_7 , V_86 -> V_91 , V_55 , V_86 -> V_92 , V_47 , V_57 ) ;
while ( V_7 ) {
V_280 [ V_34 ++ ] = V_7 ;
V_7 = F_56 ( V_1 , F_180 ( V_7 ) , V_86 -> V_91 ,
V_55 , V_86 -> V_92 , V_47 , V_57 ) ;
if ( F_40 ( V_34 == F_181 ( V_280 ) ) ) {
if ( ! V_7 )
break;
F_176 ( V_280 , V_34 , V_74 , ~ 0 ) ;
V_34 = 0 ;
}
}
for ( V_282 = 0 ; V_282 < V_34 ; V_282 ++ )
F_182 ( V_280 [ V_282 ] ) ;
F_11 ( & V_4 -> V_17 ) ;
if ( V_34 ) {
F_176 ( V_280 , V_34 , V_74 , V_34 - 1 ) ;
for ( V_282 = 0 ; V_282 < V_34 ; V_282 ++ )
F_42 ( V_280 [ V_282 ] ) ;
} else {
F_158 ( V_74 ) ;
}
return 0 ;
}
static inline int F_183 ( struct V_73 * V_74 , struct V_85 * V_86 ,
int V_285 )
{
const struct V_75 * V_76 ;
int V_90 ;
F_136 ( V_74 ) -> V_252 = 0 ;
F_136 ( V_74 ) -> V_277 = V_74 -> V_120 ;
if ( V_285 == V_286 ) {
V_90 = F_184 ( V_74 , V_86 ) ;
if ( V_90 )
return V_90 ;
}
V_76 = F_50 ( V_74 ) ;
if ( V_86 -> V_130 == 0 ) {
V_74 -> V_133 = V_287 ;
} else if ( V_74 -> V_133 == V_288 ) {
if ( ! F_74 ( V_76 -> V_47 , V_76 -> V_55 , V_74 -> V_120 ,
V_285 , V_74 -> V_127 ) )
V_74 -> V_133 = V_287 ;
}
if ( ! F_137 ( V_74 ) )
V_74 -> V_127 = F_185 ( V_76 -> V_47 , V_76 -> V_55 ,
V_74 -> V_120 , V_285 , 0 ) ;
return 0 ;
}
int F_186 ( struct V_73 * V_74 , struct V_20 * V_21 ,
int V_285 )
{
struct V_6 * V_7 ;
struct V_85 * V_86 ;
unsigned short V_158 ;
struct V_161 * V_162 = F_187 ( V_74 ) ;
T_2 V_47 , V_55 ;
struct V_1 * V_1 = F_52 ( V_74 -> V_77 ) ;
if ( ! F_188 ( V_74 , sizeof( struct V_85 ) ) )
goto V_272;
V_86 = F_69 ( V_74 ) ;
V_158 = F_44 ( V_86 -> V_120 ) ;
V_47 = F_50 ( V_74 ) -> V_47 ;
V_55 = F_50 ( V_74 ) -> V_55 ;
if ( V_158 > V_74 -> V_120 )
goto V_289;
if ( V_285 == V_131 ) {
if ( V_158 < sizeof( * V_86 ) || F_189 ( V_74 , V_158 ) )
goto V_289;
V_86 = F_69 ( V_74 ) ;
}
if ( F_183 ( V_74 , V_86 , V_285 ) )
goto V_290;
if ( V_162 -> V_213 & ( V_214 | V_291 ) )
return F_178 ( V_1 , V_74 , V_86 ,
V_47 , V_55 , V_21 ) ;
V_7 = F_49 ( V_74 , V_86 -> V_92 , V_86 -> V_91 , V_21 ) ;
if ( V_7 != NULL ) {
int V_228 = F_163 ( V_7 , V_74 ) ;
F_42 ( V_7 ) ;
if ( V_228 > 0 )
return - V_228 ;
return 0 ;
}
if ( ! F_164 ( NULL , V_271 , V_74 ) )
goto V_272;
F_165 ( V_74 ) ;
if ( F_121 ( V_74 ) )
goto V_290;
F_122 ( V_1 , V_292 , V_285 == V_286 ) ;
F_190 ( V_74 , V_101 , V_293 , 0 ) ;
F_158 ( V_74 ) ;
return 0 ;
V_289:
F_109 ( V_294 L_5 ,
V_285 == V_286 ? L_6 : L_7 ,
& V_47 , F_44 ( V_86 -> V_92 ) ,
V_158 , V_74 -> V_120 ,
& V_55 , F_44 ( V_86 -> V_91 ) ) ;
goto V_272;
V_290:
F_109 ( V_294 L_8 ,
V_285 == V_286 ? L_6 : L_7 ,
& V_47 , F_44 ( V_86 -> V_92 ) , & V_55 , F_44 ( V_86 -> V_91 ) ,
V_158 ) ;
V_272:
F_122 ( V_1 , V_233 , V_285 == V_286 ) ;
F_158 ( V_74 ) ;
return 0 ;
}
int F_191 ( struct V_73 * V_74 )
{
return F_186 ( V_74 , & V_20 , V_131 ) ;
}
void F_192 ( struct V_6 * V_7 )
{
bool V_235 = F_126 ( V_7 ) ;
F_66 ( V_7 ) ;
F_129 ( V_7 , V_235 ) ;
}
int F_193 ( struct V_6 * V_7 , int V_295 , int V_296 ,
char V_240 * V_297 , unsigned int V_198 ,
int (* F_194)( struct V_6 * ) )
{
struct V_117 * V_118 = F_6 ( V_7 ) ;
int V_298 ;
int V_90 = 0 ;
int V_138 = F_78 ( V_7 ) ;
if ( V_198 < sizeof( int ) )
return - V_179 ;
if ( F_195 ( V_298 , ( int V_240 * ) V_297 ) )
return - V_299 ;
switch ( V_296 ) {
case V_300 :
if ( V_298 != 0 ) {
V_118 -> V_167 = 1 ;
} else {
V_118 -> V_167 = 0 ;
F_88 ( V_7 ) ;
(* F_194)( V_7 ) ;
F_90 ( V_7 ) ;
}
break;
case V_301 :
switch ( V_298 ) {
case 0 :
case V_302 :
case V_303 :
V_118 -> F_167 = V_304 ;
case V_305 :
V_118 -> V_273 = V_298 ;
F_160 () ;
break;
default:
V_90 = - V_306 ;
break;
}
break;
case V_307 :
if ( ! V_138 )
return - V_306 ;
if ( V_298 != 0 && V_298 < 8 )
V_298 = 8 ;
else if ( V_298 > V_308 )
V_298 = V_308 ;
V_118 -> V_309 = V_298 ;
V_118 -> V_310 |= V_311 ;
break;
case V_312 :
if ( ! V_138 )
return - V_306 ;
if ( V_298 != 0 && V_298 < 8 )
V_298 = 8 ;
else if ( V_298 > V_308 )
V_298 = V_308 ;
V_118 -> V_275 = V_298 ;
V_118 -> V_310 |= V_274 ;
break;
default:
V_90 = - V_306 ;
break;
}
return V_90 ;
}
int F_196 ( struct V_6 * V_7 , int V_295 , int V_296 ,
char V_240 * V_297 , unsigned int V_198 )
{
if ( V_295 == V_313 || V_295 == V_314 )
return F_193 ( V_7 , V_295 , V_296 , V_297 , V_198 ,
F_84 ) ;
return F_197 ( V_7 , V_295 , V_296 , V_297 , V_198 ) ;
}
int F_198 ( struct V_6 * V_7 , int V_295 , int V_296 ,
char V_240 * V_297 , unsigned int V_198 )
{
if ( V_295 == V_313 || V_295 == V_314 )
return F_193 ( V_7 , V_295 , V_296 , V_297 , V_198 ,
F_84 ) ;
return F_199 ( V_7 , V_295 , V_296 , V_297 , V_198 ) ;
}
int F_200 ( struct V_6 * V_7 , int V_295 , int V_296 ,
char V_240 * V_297 , int V_240 * V_198 )
{
struct V_117 * V_118 = F_6 ( V_7 ) ;
int V_298 , V_120 ;
if ( F_195 ( V_120 , V_198 ) )
return - V_299 ;
V_120 = F_201 (unsigned int, len, sizeof(int)) ;
if ( V_120 < 0 )
return - V_179 ;
switch ( V_296 ) {
case V_300 :
V_298 = V_118 -> V_167 ;
break;
case V_301 :
V_298 = V_118 -> V_273 ;
break;
case V_307 :
V_298 = V_118 -> V_309 ;
break;
case V_312 :
V_298 = V_118 -> V_275 ;
break;
default:
return - V_306 ;
}
if ( F_132 ( V_120 , V_198 ) )
return - V_299 ;
if ( F_202 ( V_297 , & V_298 , V_120 ) )
return - V_299 ;
return 0 ;
}
int F_203 ( struct V_6 * V_7 , int V_295 , int V_296 ,
char V_240 * V_297 , int V_240 * V_198 )
{
if ( V_295 == V_313 || V_295 == V_314 )
return F_200 ( V_7 , V_295 , V_296 , V_297 , V_198 ) ;
return F_204 ( V_7 , V_295 , V_296 , V_297 , V_198 ) ;
}
int F_205 ( struct V_6 * V_7 , int V_295 , int V_296 ,
char V_240 * V_297 , int V_240 * V_198 )
{
if ( V_295 == V_313 || V_295 == V_314 )
return F_200 ( V_7 , V_295 , V_296 , V_297 , V_198 ) ;
return F_206 ( V_7 , V_295 , V_296 , V_297 , V_198 ) ;
}
unsigned int F_207 ( struct V_315 * V_315 , struct V_316 * V_6 , T_7 * V_317 )
{
unsigned int V_31 = F_208 ( V_315 , V_6 , V_317 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
if ( ( V_31 & V_318 ) && ! ( V_315 -> V_319 & V_320 ) &&
! ( V_7 -> V_321 & V_322 ) && ! F_118 ( V_7 ) )
V_31 &= ~ ( V_323 | V_318 ) ;
return V_31 ;
}
static struct V_6 * F_209 ( struct V_324 * V_325 , int V_326 )
{
struct V_6 * V_7 ;
struct V_327 * V_328 = V_325 -> V_329 ;
struct V_1 * V_1 = F_210 ( V_325 ) ;
for ( V_328 -> V_330 = V_326 ; V_328 -> V_330 <= V_328 -> V_20 -> V_31 ;
++ V_328 -> V_330 ) {
struct V_10 * V_11 ;
struct V_3 * V_4 = & V_328 -> V_20 -> V_72 [ V_328 -> V_330 ] ;
if ( F_211 ( & V_4 -> V_41 ) )
continue;
F_18 ( & V_4 -> V_17 ) ;
F_3 (sk, node, &hslot->head) {
if ( ! F_4 ( F_5 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_60 == V_328 -> V_331 )
goto V_32;
}
F_21 ( & V_4 -> V_17 ) ;
}
V_7 = NULL ;
V_32:
return V_7 ;
}
static struct V_6 * F_212 ( struct V_324 * V_325 , struct V_6 * V_7 )
{
struct V_327 * V_328 = V_325 -> V_329 ;
struct V_1 * V_1 = F_210 ( V_325 ) ;
do {
V_7 = F_180 ( V_7 ) ;
} while ( V_7 && ( ! F_4 ( F_5 ( V_7 ) , V_1 ) || V_7 -> V_60 != V_328 -> V_331 ) );
if ( ! V_7 ) {
if ( V_328 -> V_330 <= V_328 -> V_20 -> V_31 )
F_21 ( & V_328 -> V_20 -> V_72 [ V_328 -> V_330 ] . V_17 ) ;
return F_209 ( V_325 , V_328 -> V_330 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_213 ( struct V_324 * V_325 , T_8 V_332 )
{
struct V_6 * V_7 = F_209 ( V_325 , 0 ) ;
if ( V_7 )
while ( V_332 && ( V_7 = F_212 ( V_325 , V_7 ) ) != NULL )
-- V_332 ;
return V_332 ? NULL : V_7 ;
}
static void * F_214 ( struct V_324 * V_325 , T_8 * V_332 )
{
struct V_327 * V_328 = V_325 -> V_329 ;
V_328 -> V_330 = V_333 ;
return * V_332 ? F_213 ( V_325 , * V_332 - 1 ) : V_334 ;
}
static void * F_215 ( struct V_324 * V_325 , void * V_335 , T_8 * V_332 )
{
struct V_6 * V_7 ;
if ( V_335 == V_334 )
V_7 = F_213 ( V_325 , 0 ) ;
else
V_7 = F_212 ( V_325 , V_335 ) ;
++ * V_332 ;
return V_7 ;
}
static void F_216 ( struct V_324 * V_325 , void * V_335 )
{
struct V_327 * V_328 = V_325 -> V_329 ;
if ( V_328 -> V_330 <= V_328 -> V_20 -> V_31 )
F_21 ( & V_328 -> V_20 -> V_72 [ V_328 -> V_330 ] . V_17 ) ;
}
int F_217 ( struct V_336 * V_336 , struct V_315 * V_315 )
{
struct V_337 * V_338 = F_218 ( V_336 ) -> V_84 ;
struct V_327 * V_82 ;
int V_90 ;
V_90 = F_219 ( V_336 , V_315 , & V_338 -> V_339 ,
sizeof( struct V_327 ) ) ;
if ( V_90 < 0 )
return V_90 ;
V_82 = ( (struct V_324 * ) V_315 -> V_340 ) -> V_329 ;
V_82 -> V_331 = V_338 -> V_331 ;
V_82 -> V_20 = V_338 -> V_20 ;
return V_90 ;
}
int F_220 ( struct V_1 * V_1 , struct V_337 * V_338 )
{
struct V_341 * V_342 ;
int V_267 = 0 ;
V_338 -> V_339 . V_326 = F_214 ;
V_338 -> V_339 . V_132 = F_215 ;
V_338 -> V_339 . V_343 = F_216 ;
V_342 = F_221 ( V_338 -> V_344 , V_345 , V_1 -> V_346 ,
V_338 -> V_347 , V_338 ) ;
if ( ! V_342 )
V_267 = - V_268 ;
return V_267 ;
}
void F_222 ( struct V_1 * V_1 , struct V_337 * V_338 )
{
F_223 ( V_1 , V_338 -> V_344 ) ;
}
static void F_224 ( struct V_6 * V_348 , struct V_324 * V_349 ,
int V_330 , int * V_120 )
{
struct V_43 * V_59 = F_23 ( V_348 ) ;
T_2 V_91 = V_59 -> V_62 ;
T_2 V_121 = V_59 -> V_46 ;
T_1 V_350 = F_44 ( V_59 -> V_63 ) ;
T_1 V_351 = F_44 ( V_59 -> V_139 ) ;
F_225 ( V_349 , L_9
L_10 ,
V_330 , V_121 , V_351 , V_91 , V_350 , V_348 -> V_112 ,
F_131 ( V_348 ) ,
F_226 ( V_348 ) ,
0 , 0L , 0 ,
F_227 ( F_228 ( V_349 ) , F_229 ( V_348 ) ) ,
0 , F_230 ( V_348 ) ,
F_231 ( & V_348 -> V_69 ) , V_348 ,
F_231 ( & V_348 -> V_234 ) , V_120 ) ;
}
int F_232 ( struct V_324 * V_325 , void * V_335 )
{
if ( V_335 == V_334 )
F_225 ( V_325 , L_11 ,
L_12
L_13
L_14 ) ;
else {
struct V_327 * V_328 = V_325 -> V_329 ;
int V_120 ;
F_224 ( V_335 , V_325 , V_328 -> V_330 , & V_120 ) ;
F_225 ( V_325 , L_15 , 127 - V_120 , L_7 ) ;
}
return 0 ;
}
static int T_9 F_233 ( struct V_1 * V_1 )
{
return F_220 ( V_1 , & V_352 ) ;
}
static void T_10 F_234 ( struct V_1 * V_1 )
{
F_222 ( V_1 , & V_352 ) ;
}
int T_11 F_235 ( void )
{
return F_236 ( & V_353 ) ;
}
void F_237 ( void )
{
F_238 ( & V_353 ) ;
}
static int T_11 F_239 ( char * V_354 )
{
T_12 V_228 ;
if ( ! V_354 )
return 0 ;
V_228 = F_240 ( V_354 , 0 , & V_355 ) ;
if ( V_228 )
return 0 ;
if ( V_355 && V_355 < V_356 )
V_355 = V_356 ;
return 1 ;
}
void T_11 F_241 ( struct V_20 * V_357 , const char * V_344 )
{
unsigned int V_282 ;
V_357 -> V_72 = F_242 ( V_344 ,
2 * sizeof( struct V_3 ) ,
V_355 ,
21 ,
0 ,
& V_357 -> log ,
& V_357 -> V_31 ,
V_356 ,
64 * 1024 ) ;
V_357 -> V_70 = V_357 -> V_72 + ( V_357 -> V_31 + 1 ) ;
for ( V_282 = 0 ; V_282 <= V_357 -> V_31 ; V_282 ++ ) {
F_243 ( & V_357 -> V_72 [ V_282 ] . V_41 , V_282 ) ;
V_357 -> V_72 [ V_282 ] . V_34 = 0 ;
F_244 ( & V_357 -> V_72 [ V_282 ] . V_17 ) ;
}
for ( V_282 = 0 ; V_282 <= V_357 -> V_31 ; V_282 ++ ) {
F_243 ( & V_357 -> V_70 [ V_282 ] . V_41 , V_282 ) ;
V_357 -> V_70 [ V_282 ] . V_34 = 0 ;
F_244 ( & V_357 -> V_70 [ V_282 ] . V_17 ) ;
}
}
void T_11 F_245 ( void )
{
unsigned long V_358 ;
F_241 ( & V_20 , L_16 ) ;
V_358 = F_246 () / 8 ;
V_358 = F_247 ( V_358 , 128UL ) ;
V_359 [ 0 ] = V_358 / 4 * 3 ;
V_359 [ 1 ] = V_358 ;
V_359 [ 2 ] = V_359 [ 0 ] * 2 ;
V_360 = V_361 ;
V_362 = V_361 ;
}
int F_248 ( struct V_73 * V_74 )
{
const struct V_75 * V_76 ;
struct V_85 * V_86 ;
if ( ! F_188 ( V_74 , sizeof( * V_86 ) ) )
return - V_179 ;
V_76 = F_50 ( V_74 ) ;
V_86 = F_69 ( V_74 ) ;
V_86 -> V_130 = ~ F_74 ( V_76 -> V_47 , V_76 -> V_55 , V_74 -> V_120 ,
V_131 , 0 ) ;
V_74 -> V_128 = F_72 ( V_74 ) - V_74 -> V_41 ;
V_74 -> V_129 = F_73 ( struct V_85 , V_130 ) ;
V_74 -> V_133 = V_144 ;
return 0 ;
}
struct V_73 * F_249 ( struct V_73 * V_74 ,
T_13 V_363 )
{
struct V_73 * V_364 = F_250 ( - V_179 ) ;
unsigned int V_365 ;
int V_125 ;
T_4 V_127 ;
V_365 = F_70 ( V_74 ) -> V_366 ;
if ( F_40 ( V_74 -> V_120 <= V_365 ) )
goto V_98;
if ( F_251 ( V_74 , V_363 | V_367 ) ) {
int type = F_70 ( V_74 ) -> V_368 ;
if ( F_40 ( type & ~ ( V_369 | V_370 ) ||
! ( type & ( V_369 ) ) ) )
goto V_98;
F_70 ( V_74 ) -> V_371 = F_252 ( V_74 -> V_120 , V_365 ) ;
V_364 = NULL ;
goto V_98;
}
V_125 = F_253 ( V_74 ) ;
V_127 = F_76 ( V_74 , V_125 , V_74 -> V_120 - V_125 , 0 ) ;
V_125 += V_74 -> V_129 ;
* ( V_372 * ) ( V_74 -> V_84 + V_125 ) = F_254 ( V_127 ) ;
V_74 -> V_133 = V_134 ;
V_364 = F_255 ( V_74 , V_363 ) ;
V_98:
return V_364 ;
}
