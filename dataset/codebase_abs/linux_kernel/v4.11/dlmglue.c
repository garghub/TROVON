static void F_1 ( T_1 V_1 ,
const char * V_2 ,
unsigned int line ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_4 -> V_7 ) ;
F_3 ( V_1 , L_1 ,
V_4 -> V_8 , V_2 , line ) ;
F_3 ( V_1 , L_2 ,
V_6 -> V_9 , F_4 ( V_6 -> V_10 ) ,
F_4 ( V_6 -> V_11 ) ) ;
F_3 ( V_1 , L_3 ,
( unsigned long long ) F_5 ( V_6 -> V_12 ) ,
F_4 ( V_6 -> V_13 ) , F_4 ( V_6 -> V_14 ) ,
F_6 ( V_6 -> V_15 ) ) ;
F_3 ( V_1 , L_4
L_5 , F_6 ( V_6 -> V_16 ) ,
( long long ) F_5 ( V_6 -> V_17 ) ,
( long long ) F_5 ( V_6 -> V_18 ) ,
( long long ) F_5 ( V_6 -> V_19 ) ,
F_4 ( V_6 -> V_20 ) ) ;
}
static inline int F_7 ( struct V_3 * V_4 )
{
return V_4 -> V_21 == V_22 ||
V_4 -> V_21 == V_23 ||
V_4 -> V_21 == V_24 ;
}
static inline struct V_3 * F_8 ( struct V_25 * V_26 )
{
return F_9 ( V_26 , struct V_3 , V_7 ) ;
}
static inline struct V_27 * F_10 ( struct V_3 * V_4 )
{
F_11 ( ! F_7 ( V_4 ) ) ;
return (struct V_27 * ) V_4 -> V_28 ;
}
static inline struct V_29 * F_12 ( struct V_3 * V_4 )
{
F_11 ( V_4 -> V_21 != V_30 ) ;
return (struct V_29 * ) V_4 -> V_28 ;
}
static inline struct V_31 * F_13 ( struct V_3 * V_4 )
{
F_11 ( V_4 -> V_21 != V_32 ) ;
return (struct V_31 * ) V_4 -> V_28 ;
}
static inline struct V_33 *
F_14 ( struct V_3 * V_34 )
{
return F_9 ( V_34 , struct V_33 , V_35 ) ;
}
static inline struct V_36 * F_15 ( struct V_3 * V_4 )
{
if ( V_4 -> V_37 -> V_38 )
return V_4 -> V_37 -> V_38 ( V_4 ) ;
return (struct V_36 * ) V_4 -> V_28 ;
}
static inline void F_16 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 )
{
F_17 ( V_39 , V_4 , V_1 , V_40 ) ;
}
static void F_18 ( enum V_41 type ,
T_1 V_42 ,
T_2 V_43 ,
char * V_44 )
{
int V_45 ;
F_11 ( type >= V_46 ) ;
V_45 = snprintf ( V_44 , V_47 , L_6 ,
F_19 ( type ) , V_48 ,
( long long ) V_42 , V_43 ) ;
F_11 ( V_45 != ( V_47 - 1 ) ) ;
F_3 ( 0 , L_7 , V_44 ) ;
}
static void F_20 ( struct V_3 * V_34 ,
struct V_49 * V_50 )
{
F_3 ( 0 , L_8 , V_34 -> V_8 ) ;
F_21 ( & V_51 ) ;
F_22 ( & V_34 -> V_52 , & V_50 -> V_53 ) ;
F_23 ( & V_51 ) ;
}
static void F_24 ( struct V_3 * V_34 )
{
F_21 ( & V_51 ) ;
if ( ! F_25 ( & V_34 -> V_52 ) )
F_26 ( & V_34 -> V_52 ) ;
F_23 ( & V_51 ) ;
}
static void F_27 ( struct V_3 * V_34 )
{
V_34 -> V_54 = 0 ;
memset ( & V_34 -> V_55 , 0 , sizeof( struct V_56 ) ) ;
memset ( & V_34 -> V_57 , 0 , sizeof( struct V_56 ) ) ;
}
static void F_28 ( struct V_3 * V_34 , int V_1 ,
struct V_58 * V_59 , int V_60 )
{
T_2 V_61 ;
T_3 V_62 ;
struct V_56 * V_63 ;
if ( V_1 == V_64 )
V_63 = & V_34 -> V_55 ;
else if ( V_1 == V_65 )
V_63 = & V_34 -> V_57 ;
else
return;
V_62 = F_29 ( F_30 () , V_59 -> V_66 ) ;
V_61 = F_31 ( V_62 ) ;
V_63 -> V_67 ++ ;
V_63 -> V_68 += F_32 ( V_62 ) ;
if ( F_33 ( V_63 -> V_67 == 0 ) ) {
V_63 -> V_67 ++ ;
V_63 -> V_68 = F_32 ( V_62 ) ;
}
if ( V_63 -> V_69 < V_61 )
V_63 -> V_69 = V_61 ;
if ( V_60 )
V_63 -> V_70 ++ ;
}
static inline void F_34 ( struct V_3 * V_4 )
{
V_4 -> V_54 ++ ;
}
static inline void F_35 ( struct V_58 * V_59 )
{
V_59 -> V_66 = F_30 () ;
}
static inline void F_27 ( struct V_3 * V_34 )
{
}
static inline void F_28 ( struct V_3 * V_34 ,
int V_1 , struct V_58 * V_59 , int V_60 )
{
}
static inline void F_34 ( struct V_3 * V_4 )
{
}
static inline void F_35 ( struct V_58 * V_59 )
{
}
static void F_36 ( struct V_36 * V_39 ,
struct V_3 * V_34 ,
enum V_41 type ,
struct V_71 * V_72 ,
void * V_73 )
{
V_34 -> V_21 = type ;
V_34 -> V_37 = V_72 ;
V_34 -> V_28 = V_73 ;
V_34 -> V_74 = V_75 ;
V_34 -> V_76 = V_75 ;
V_34 -> V_77 = V_75 ;
V_34 -> V_78 = V_79 ;
V_34 -> V_80 = V_81 ;
V_34 -> V_82 = V_83 ;
F_20 ( V_34 , V_39 -> V_84 ) ;
F_27 ( V_34 ) ;
#ifdef F_37
if ( type != V_24 )
F_38 ( & V_34 -> V_85 , V_86 [ type ] ,
& V_87 [ type ] , 0 ) ;
else
V_34 -> V_85 . V_88 = NULL ;
#endif
}
void F_39 ( struct V_3 * V_34 )
{
memset ( V_34 , 0 , sizeof( struct V_3 ) ) ;
F_40 ( & V_34 -> V_89 ) ;
F_41 ( & V_34 -> V_90 ) ;
F_42 ( & V_34 -> V_91 ) ;
F_42 ( & V_34 -> V_92 ) ;
F_42 ( & V_34 -> V_93 ) ;
}
void F_43 ( struct V_3 * V_34 ,
enum V_41 type ,
unsigned int V_43 ,
struct V_27 * V_27 )
{
struct V_71 * V_72 ;
switch( type ) {
case V_23 :
V_72 = & V_94 ;
break;
case V_22 :
V_72 = & V_95 ;
break;
case V_24 :
V_72 = & V_96 ;
break;
default:
F_44 ( 1 , L_9 , type ) ;
V_72 = NULL ;
break;
} ;
F_18 ( type , F_45 ( V_27 ) -> V_97 ,
V_43 , V_34 -> V_8 ) ;
F_36 ( F_46 ( V_27 -> V_98 ) , V_34 , type , V_72 , V_27 ) ;
}
static struct V_36 * F_47 ( struct V_3 * V_4 )
{
struct V_27 * V_27 = F_10 ( V_4 ) ;
return F_46 ( V_27 -> V_98 ) ;
}
static struct V_36 * F_48 ( struct V_3 * V_4 )
{
struct V_31 * V_99 = V_4 -> V_28 ;
return F_46 ( V_99 -> V_100 . V_101 ) ;
}
static struct V_36 * F_49 ( struct V_3 * V_4 )
{
struct V_102 * V_103 = V_4 -> V_28 ;
return F_46 ( V_103 -> V_104 -> V_105 -> V_106 -> V_98 ) ;
}
static T_4 F_50 ( struct V_3 * V_4 )
{
T_5 V_107 ;
memcpy ( & V_107 , & V_4 -> V_8 [ V_108 ] ,
sizeof( T_5 ) ) ;
return F_5 ( V_107 ) ;
}
static struct V_36 * F_51 ( struct V_3 * V_4 )
{
struct V_29 * V_109 = V_4 -> V_28 ;
return F_46 ( V_109 -> V_110 -> V_98 ) ;
}
void F_52 ( struct V_29 * V_109 ,
T_1 V_111 , struct V_27 * V_27 )
{
int V_45 ;
T_1 V_112 = F_45 ( V_27 ) -> V_97 ;
T_5 V_107 = F_53 ( V_112 ) ;
struct V_3 * V_4 = & V_109 -> V_113 ;
F_39 ( V_4 ) ;
V_45 = snprintf ( V_4 -> V_8 , V_108 ,
L_10 ,
F_19 ( V_30 ) ,
( long long ) V_111 ) ;
F_11 ( V_45 != ( V_108 - 1 ) ) ;
memcpy ( & V_4 -> V_8 [ V_108 ] , & V_107 ,
sizeof( T_5 ) ) ;
F_36 ( F_46 ( V_27 -> V_98 ) , V_4 ,
V_30 , & V_114 ,
V_109 ) ;
}
static void F_54 ( struct V_3 * V_34 ,
struct V_36 * V_39 )
{
F_39 ( V_34 ) ;
F_18 ( V_115 , V_116 ,
0 , V_34 -> V_8 ) ;
F_36 ( V_39 , V_34 , V_115 ,
& V_117 , V_39 ) ;
}
static void F_55 ( struct V_3 * V_34 ,
struct V_36 * V_39 )
{
F_39 ( V_34 ) ;
F_18 ( V_118 , 0 , 0 , V_34 -> V_8 ) ;
F_36 ( V_39 , V_34 , V_118 ,
& V_119 , V_39 ) ;
}
static void F_56 ( struct V_3 * V_34 ,
struct V_36 * V_39 )
{
F_39 ( V_34 ) ;
F_18 ( V_120 , 0 , 0 , V_34 -> V_8 ) ;
F_36 ( V_39 , V_34 , V_120 ,
& V_121 , V_39 ) ;
}
static void F_57 ( struct V_3 * V_34 ,
struct V_36 * V_39 )
{
F_39 ( V_34 ) ;
F_18 ( V_122 , 0 , 0 , V_34 -> V_8 ) ;
F_36 ( V_39 , V_34 , V_122 ,
& V_123 , V_39 ) ;
}
void F_58 ( struct V_3 * V_4 ,
struct V_102 * V_103 )
{
struct V_27 * V_27 = V_103 -> V_104 -> V_105 -> V_106 ;
struct V_124 * V_125 = F_45 ( V_27 ) ;
F_39 ( V_4 ) ;
F_18 ( V_126 , V_125 -> V_97 ,
V_27 -> V_127 , V_4 -> V_8 ) ;
F_36 ( F_46 ( V_27 -> V_98 ) , V_4 ,
V_126 , & V_128 ,
V_103 ) ;
V_4 -> V_82 |= V_129 ;
}
void F_59 ( struct V_3 * V_4 ,
struct V_31 * V_99 )
{
F_39 ( V_4 ) ;
F_18 ( V_32 , V_99 -> V_100 . V_130 ,
0 , V_4 -> V_8 ) ;
F_36 ( F_46 ( V_99 -> V_100 . V_101 ) , V_4 ,
V_32 , & V_131 ,
V_99 ) ;
}
void F_60 ( struct V_3 * V_4 ,
struct V_36 * V_39 , T_1 V_132 ,
unsigned int V_43 )
{
F_39 ( V_4 ) ;
F_18 ( V_133 , V_132 ,
V_43 , V_4 -> V_8 ) ;
F_36 ( V_39 , V_4 , V_133 ,
& V_134 , V_39 ) ;
}
void F_61 ( struct V_3 * V_34 )
{
if ( ! ( V_34 -> V_82 & V_83 ) )
return;
F_24 ( V_34 ) ;
F_44 ( ! F_25 ( & V_34 -> V_91 ) ,
L_11 ,
V_34 -> V_8 ) ;
F_44 ( ! F_25 ( & V_34 -> V_92 ) ,
L_12 ,
V_34 -> V_8 ) ;
F_44 ( F_62 ( & V_34 -> V_89 ) ,
L_13 ,
V_34 -> V_8 ) ;
F_44 ( V_34 -> V_135 ,
L_14 ,
V_34 -> V_8 , V_34 -> V_135 ) ;
F_44 ( V_34 -> V_136 ,
L_15 ,
V_34 -> V_8 , V_34 -> V_136 ) ;
memset ( & V_34 -> V_7 , 0 , sizeof( V_34 -> V_7 ) ) ;
V_34 -> V_82 = 0UL ;
}
static inline void F_63 ( struct V_3 * V_4 ,
struct V_137 * V_138 )
{
F_42 ( & V_138 -> V_139 ) ;
V_138 -> V_140 = F_64 ( F_65 ( V_141 ) ) ;
F_21 ( & V_4 -> V_89 ) ;
F_66 ( & V_138 -> V_139 , & V_4 -> V_93 ) ;
F_23 ( & V_4 -> V_89 ) ;
}
static inline void F_67 ( struct V_3 * V_4 ,
struct V_137 * V_138 )
{
F_21 ( & V_4 -> V_89 ) ;
F_68 ( & V_138 -> V_139 ) ;
F_23 ( & V_4 -> V_89 ) ;
F_69 ( V_138 -> V_140 ) ;
}
static inline int F_70 ( struct V_3 * V_4 )
{
struct V_137 * V_138 ;
struct V_142 * V_142 ;
F_21 ( & V_4 -> V_89 ) ;
V_142 = F_65 ( V_141 ) ;
F_71 (oh, &lockres->l_holders, oh_list) {
if ( V_138 -> V_140 == V_142 ) {
F_23 ( & V_4 -> V_89 ) ;
return 1 ;
}
}
F_23 ( & V_4 -> V_89 ) ;
return 0 ;
}
static inline void F_72 ( struct V_3 * V_4 ,
int V_1 )
{
F_11 ( ! V_4 ) ;
switch( V_1 ) {
case V_143 :
V_4 -> V_136 ++ ;
break;
case V_144 :
V_4 -> V_135 ++ ;
break;
default:
F_73 () ;
}
}
static inline void F_74 ( struct V_3 * V_4 ,
int V_1 )
{
F_11 ( ! V_4 ) ;
switch( V_1 ) {
case V_143 :
F_11 ( ! V_4 -> V_136 ) ;
V_4 -> V_136 -- ;
break;
case V_144 :
F_11 ( ! V_4 -> V_135 ) ;
V_4 -> V_135 -- ;
break;
default:
F_73 () ;
}
}
static inline int F_75 ( int V_1 )
{
int V_145 = V_143 ;
if ( V_1 == V_143 )
V_145 = V_146 ;
else if ( V_1 == V_144 )
V_145 = V_144 ;
return V_145 ;
}
static void F_76 ( struct V_3 * V_4 ,
unsigned long V_147 )
{
struct V_58 * V_59 , * V_148 ;
F_77 ( & V_4 -> V_89 ) ;
V_4 -> V_82 = V_147 ;
F_78 (mw, tmp, &lockres->l_mask_waiters, mw_item) {
if ( ( V_4 -> V_82 & V_59 -> V_149 ) != V_59 -> V_150 )
continue;
F_26 ( & V_59 -> V_151 ) ;
V_59 -> V_152 = 0 ;
F_79 ( & V_59 -> V_153 ) ;
}
}
static void F_80 ( struct V_3 * V_4 , unsigned long V_154 )
{
F_76 ( V_4 , V_4 -> V_82 | V_154 ) ;
}
static void F_81 ( struct V_3 * V_4 ,
unsigned long V_155 )
{
F_76 ( V_4 , V_4 -> V_82 & ~ V_155 ) ;
}
static inline void F_82 ( struct V_3 * V_4 )
{
F_11 ( ! ( V_4 -> V_82 & V_156 ) ) ;
F_11 ( ! ( V_4 -> V_82 & V_157 ) ) ;
F_11 ( ! ( V_4 -> V_82 & V_158 ) ) ;
F_11 ( V_4 -> V_77 <= V_146 ) ;
V_4 -> V_74 = V_4 -> V_76 ;
if ( V_4 -> V_74 <=
F_75 ( V_4 -> V_77 ) ) {
V_4 -> V_77 = V_146 ;
F_81 ( V_4 , V_158 ) ;
}
F_81 ( V_4 , V_156 ) ;
}
static inline void F_83 ( struct V_3 * V_4 )
{
F_11 ( ! ( V_4 -> V_82 & V_156 ) ) ;
F_11 ( ! ( V_4 -> V_82 & V_157 ) ) ;
if ( V_4 -> V_74 == V_146 &&
V_4 -> V_37 -> V_159 & V_160 )
F_80 ( V_4 , V_161 ) ;
V_4 -> V_74 = V_4 -> V_76 ;
if ( ! ( V_4 -> V_82 & V_162 ) )
F_80 ( V_4 , V_163 ) ;
else
F_81 ( V_4 , V_162 ) ;
F_81 ( V_4 , V_156 ) ;
}
static inline void F_84 ( struct V_3 * V_4 )
{
F_11 ( ( ! ( V_4 -> V_82 & V_156 ) ) ) ;
F_11 ( V_4 -> V_82 & V_157 ) ;
if ( V_4 -> V_76 > V_146 &&
! ( V_4 -> V_82 & V_164 ) &&
V_4 -> V_37 -> V_159 & V_160 )
F_80 ( V_4 , V_161 ) ;
V_4 -> V_74 = V_4 -> V_76 ;
F_80 ( V_4 , V_157 ) ;
F_81 ( V_4 , V_156 ) ;
}
static int F_85 ( struct V_3 * V_4 ,
int V_1 )
{
int V_165 = 0 ;
F_77 ( & V_4 -> V_89 ) ;
if ( V_1 > V_4 -> V_77 ) {
if ( F_75 ( V_1 ) <
F_75 ( V_4 -> V_77 ) )
V_165 = 1 ;
V_4 -> V_77 = V_1 ;
}
F_3 ( V_166 , L_16 ,
V_4 -> V_8 , V_1 , V_4 -> V_74 , V_4 -> V_77 ,
V_165 ) ;
if ( V_165 )
F_80 ( V_4 , V_158 ) ;
F_3 ( 0 , L_17 , V_165 ) ;
return V_165 ;
}
static void F_86 ( struct V_3 * V_4 ,
unsigned int V_43 ,
struct V_36 * V_39 )
{
F_77 ( & V_4 -> V_89 ) ;
if ( ! ( V_4 -> V_82 & V_167 ) ||
( V_4 -> V_168 != V_43 ) )
return;
F_81 ( V_4 , V_167 ) ;
V_4 -> V_168 ++ ;
if ( V_4 -> V_82 & V_158 )
F_87 ( V_39 ) ;
}
static void F_88 ( struct V_3 * V_4 ,
unsigned int V_43 ,
struct V_36 * V_39 )
{
unsigned long V_159 ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
F_86 ( V_4 , V_43 , V_39 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
}
static unsigned int F_91 ( struct V_3 * V_4 )
{
F_77 ( & V_4 -> V_89 ) ;
F_11 ( ! ( V_4 -> V_82 & V_156 ) ) ;
F_80 ( V_4 , V_167 ) ;
return V_4 -> V_168 ;
}
static void F_92 ( struct V_25 * V_26 , int V_1 )
{
struct V_3 * V_4 = F_8 ( V_26 ) ;
struct V_36 * V_39 = F_15 ( V_4 ) ;
int V_165 ;
unsigned long V_159 ;
F_11 ( V_1 <= V_146 ) ;
F_3 ( V_166 , L_18
L_19 , V_4 -> V_8 , V_1 , V_4 -> V_74 ,
F_93 ( V_4 -> V_21 ) ) ;
if ( V_4 -> V_82 & V_129 )
return;
F_89 ( & V_4 -> V_89 , V_159 ) ;
V_165 = F_85 ( V_4 , V_1 ) ;
if ( V_165 )
F_94 ( V_39 , V_4 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
F_95 ( & V_4 -> V_90 ) ;
F_87 ( V_39 ) ;
}
static void F_96 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_8 ( V_26 ) ;
struct V_36 * V_39 = F_15 ( V_4 ) ;
unsigned long V_159 ;
int V_169 ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
V_169 = F_97 ( & V_4 -> V_7 ) ;
if ( V_169 == - V_170 ) {
F_81 ( V_4 , V_156 ) ;
goto V_171;
}
if ( V_169 ) {
F_3 ( V_172 , L_20 ,
V_4 -> V_8 , V_169 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
return;
}
F_3 ( V_166 , L_21
L_22 , V_4 -> V_8 , V_4 -> V_78 ,
V_4 -> V_80 , V_4 -> V_74 , V_4 -> V_76 ) ;
switch( V_4 -> V_78 ) {
case V_173 :
F_84 ( V_4 ) ;
F_81 ( V_4 , V_164 ) ;
break;
case V_174 :
F_83 ( V_4 ) ;
break;
case V_175 :
F_82 ( V_4 ) ;
break;
default:
F_3 ( V_172 , L_23
L_24 ,
V_4 -> V_8 , V_4 -> V_78 , V_4 -> V_82 ,
V_4 -> V_80 ) ;
F_73 () ;
}
V_171:
V_4 -> V_78 = V_79 ;
if ( V_4 -> V_80 == V_176 )
V_4 -> V_80 = V_81 ;
F_86 ( V_4 , V_4 -> V_168 , V_39 ) ;
F_95 ( & V_4 -> V_90 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
}
static void F_98 ( struct V_25 * V_26 , int error )
{
struct V_3 * V_4 = F_8 ( V_26 ) ;
unsigned long V_159 ;
F_3 ( V_166 , L_25 ,
V_4 -> V_8 , V_4 -> V_80 ) ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
if ( error ) {
F_3 ( V_172 , L_26
L_27 , error , V_4 -> V_8 ,
V_4 -> V_80 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
return;
}
switch( V_4 -> V_80 ) {
case V_176 :
F_3 ( 0 , L_28 , V_4 -> V_8 ) ;
V_4 -> V_78 = V_79 ;
if ( V_4 -> V_82 & V_158 )
F_87 ( F_15 ( V_4 ) ) ;
break;
case V_177 :
V_4 -> V_74 = V_75 ;
break;
default:
F_73 () ;
}
F_81 ( V_4 , V_156 ) ;
V_4 -> V_80 = V_81 ;
F_95 ( & V_4 -> V_90 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
}
void F_99 ( void )
{
F_100 ( & V_178 . V_179 ) ;
}
static inline void F_101 ( struct V_3 * V_4 ,
int V_180 )
{
unsigned long V_159 ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
F_81 ( V_4 , V_156 ) ;
F_81 ( V_4 , V_163 ) ;
if ( V_180 )
V_4 -> V_78 = V_79 ;
else
V_4 -> V_80 = V_81 ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
F_95 ( & V_4 -> V_90 ) ;
}
static int F_102 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 ,
T_2 V_181 )
{
int V_60 = 0 ;
unsigned long V_159 ;
unsigned int V_182 ;
F_3 ( 0 , L_29 , V_4 -> V_8 , V_1 ,
V_181 ) ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
if ( ( V_4 -> V_82 & V_157 ) ||
( V_4 -> V_82 & V_156 ) ) {
F_90 ( & V_4 -> V_89 , V_159 ) ;
goto V_183;
}
V_4 -> V_78 = V_173 ;
V_4 -> V_76 = V_1 ;
F_80 ( V_4 , V_156 ) ;
V_182 = F_91 ( V_4 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_60 = F_103 ( V_39 -> V_184 ,
V_1 ,
& V_4 -> V_7 ,
V_181 ,
V_4 -> V_8 ,
V_47 - 1 ) ;
F_88 ( V_4 , V_182 , V_39 ) ;
if ( V_60 ) {
F_104 ( L_30 , V_60 , V_4 ) ;
F_101 ( V_4 , 1 ) ;
}
F_3 ( 0 , L_31 , V_4 -> V_8 ) ;
V_183:
return V_60 ;
}
static inline int F_105 ( struct V_3 * V_4 ,
int V_185 )
{
unsigned long V_159 ;
int V_60 ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
V_60 = V_4 -> V_82 & V_185 ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
return V_60 ;
}
static inline void F_106 ( struct V_3 * V_4 )
{
F_107 ( V_4 -> V_90 ,
! F_105 ( V_4 , V_156 ) ) ;
}
static inline void F_108 ( struct V_3 * V_4 )
{
F_107 ( V_4 -> V_90 ,
! F_105 ( V_4 , V_186 ) ) ;
}
static inline int F_109 ( struct V_3 * V_4 ,
int V_187 )
{
F_11 ( ! ( V_4 -> V_82 & V_158 ) ) ;
return V_187 <= F_75 ( V_4 -> V_77 ) ;
}
static void F_110 ( struct V_58 * V_59 )
{
F_42 ( & V_59 -> V_151 ) ;
F_111 ( & V_59 -> V_153 ) ;
F_35 ( V_59 ) ;
}
static int F_112 ( struct V_58 * V_59 )
{
F_113 ( & V_59 -> V_153 ) ;
F_114 ( & V_59 -> V_153 ) ;
return V_59 -> V_152 ;
}
static void F_115 ( struct V_3 * V_4 ,
struct V_58 * V_59 ,
unsigned long V_188 ,
unsigned long V_189 )
{
F_11 ( ! F_25 ( & V_59 -> V_151 ) ) ;
F_77 ( & V_4 -> V_89 ) ;
F_66 ( & V_59 -> V_151 , & V_4 -> V_92 ) ;
V_59 -> V_149 = V_188 ;
V_59 -> V_150 = V_189 ;
}
static int F_116 ( struct V_3 * V_4 ,
struct V_58 * V_59 )
{
int V_60 = 0 ;
F_77 ( & V_4 -> V_89 ) ;
if ( ! F_25 ( & V_59 -> V_151 ) ) {
if ( ( V_4 -> V_82 & V_59 -> V_149 ) != V_59 -> V_150 )
V_60 = - V_190 ;
F_26 ( & V_59 -> V_151 ) ;
F_111 ( & V_59 -> V_153 ) ;
}
return V_60 ;
}
static int F_117 ( struct V_3 * V_4 ,
struct V_58 * V_59 )
{
unsigned long V_159 ;
int V_60 = 0 ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
V_60 = F_116 ( V_4 , V_59 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
return V_60 ;
}
static int F_118 ( struct V_58 * V_59 ,
struct V_3 * V_4 )
{
int V_60 ;
V_60 = F_119 ( & V_59 -> V_153 ) ;
if ( V_60 )
F_117 ( V_4 , V_59 ) ;
else
V_60 = V_59 -> V_152 ;
F_114 ( & V_59 -> V_153 ) ;
return V_60 ;
}
static int F_120 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 ,
T_2 V_191 ,
int V_192 ,
int V_193 ,
unsigned long V_194 )
{
struct V_58 V_59 ;
int V_195 , V_196 = ! ( V_39 -> V_197 & V_198 ) ;
int V_60 = 0 ;
unsigned long V_159 ;
unsigned int V_182 ;
int V_199 = 0 ;
int V_200 = 0 ;
int V_201 = 0 ;
if ( ! ( V_4 -> V_82 & V_83 ) ) {
F_121 ( - V_202 ) ;
return - V_202 ;
}
F_110 ( & V_59 ) ;
if ( V_4 -> V_37 -> V_159 & V_203 )
V_191 |= V_204 ;
V_205:
V_195 = 0 ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
if ( V_196 && F_122 ( V_141 ) ) {
V_60 = - V_206 ;
goto V_207;
}
F_44 ( V_4 -> V_82 & V_208 ,
L_32
L_33 , V_4 -> V_8 , V_4 -> V_82 ) ;
if ( V_4 -> V_82 & V_156 &&
V_1 > V_4 -> V_74 ) {
F_115 ( V_4 , & V_59 , V_156 , 0 ) ;
V_195 = 1 ;
goto V_207;
}
if ( V_4 -> V_82 & V_163 ) {
if ( V_1 <= V_4 -> V_74 )
goto V_209;
}
if ( V_4 -> V_82 & V_158 &&
! F_109 ( V_4 , V_1 ) ) {
F_115 ( V_4 , & V_59 , V_158 , 0 ) ;
V_195 = 1 ;
goto V_207;
}
if ( V_1 > V_4 -> V_74 ) {
if ( V_199 > 0 ) {
V_60 = - V_170 ;
goto V_207;
}
if ( V_191 & V_210 )
V_199 = 1 ;
if ( V_4 -> V_78 != V_79 )
F_3 ( V_172 , L_34 ,
V_4 -> V_8 , V_4 -> V_78 ) ;
if ( ! ( V_4 -> V_82 & V_157 ) ) {
V_4 -> V_78 = V_173 ;
V_191 &= ~ V_211 ;
} else {
V_4 -> V_78 = V_174 ;
V_191 |= V_211 ;
}
V_4 -> V_76 = V_1 ;
F_80 ( V_4 , V_156 ) ;
V_182 = F_91 ( V_4 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
F_11 ( V_1 == V_75 ) ;
F_11 ( V_1 == V_146 ) ;
F_3 ( V_166 , L_35 ,
V_4 -> V_8 , V_4 -> V_74 , V_1 ) ;
V_60 = F_103 ( V_39 -> V_184 ,
V_1 ,
& V_4 -> V_7 ,
V_191 ,
V_4 -> V_8 ,
V_47 - 1 ) ;
F_88 ( V_4 , V_182 , V_39 ) ;
if ( V_60 ) {
if ( ! ( V_191 & V_210 ) ||
( V_60 != - V_170 ) ) {
F_104 ( L_30 ,
V_60 , V_4 ) ;
}
F_101 ( V_4 , 1 ) ;
goto V_171;
}
V_200 = 1 ;
F_3 ( 0 , L_36 ,
V_4 -> V_8 ) ;
V_196 = 0 ;
goto V_205;
}
V_209:
F_72 ( V_4 , V_1 ) ;
V_60 = 0 ;
V_207:
F_81 ( V_4 , V_163 ) ;
V_201 = ( V_4 -> V_82 & V_158 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
if ( V_201 )
F_87 ( V_39 ) ;
V_171:
if ( V_195 && V_192 & V_212 &&
V_59 . V_149 & ( V_156 | V_158 ) ) {
V_195 = 0 ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
if ( F_116 ( V_4 , & V_59 ) ) {
if ( V_200 )
F_80 ( V_4 ,
V_162 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_60 = - V_170 ;
} else {
F_90 ( & V_4 -> V_89 , V_159 ) ;
goto V_205;
}
}
if ( V_195 ) {
V_60 = F_112 ( & V_59 ) ;
if ( V_60 == 0 )
goto V_205;
F_121 ( V_60 ) ;
}
F_28 ( V_4 , V_1 , & V_59 , V_60 ) ;
#ifdef F_37
if ( ! V_60 && V_4 -> V_85 . V_88 != NULL ) {
if ( V_1 == V_144 )
F_123 ( & V_4 -> V_85 , V_193 ,
! ! ( V_192 & V_213 ) ,
V_194 ) ;
else
F_124 ( & V_4 -> V_85 , V_193 ,
! ! ( V_192 & V_213 ) ,
V_194 ) ;
}
#endif
return V_60 ;
}
static inline int F_125 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 ,
T_2 V_191 ,
int V_192 )
{
return F_120 ( V_39 , V_4 , V_1 , V_191 , V_192 ,
0 , V_40 ) ;
}
static void F_17 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 ,
unsigned long V_194 )
{
unsigned long V_159 ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
F_74 ( V_4 , V_1 ) ;
F_126 ( V_39 , V_4 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
#ifdef F_37
if ( V_4 -> V_85 . V_88 != NULL )
F_127 ( & V_4 -> V_85 , 1 , V_194 ) ;
#endif
}
static int F_128 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_214 ,
int V_215 )
{
int V_1 = V_214 ? V_143 : V_144 ;
unsigned long V_159 ;
T_2 V_191 = V_215 ? V_216 : 0 ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
F_11 ( V_4 -> V_82 & V_157 ) ;
F_80 ( V_4 , V_164 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
return F_102 ( V_39 , V_4 , V_1 , V_191 ) ;
}
int F_129 ( struct V_27 * V_27 )
{
int V_60 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_98 ) ;
F_11 ( ! F_130 ( V_27 ) ) ;
F_3 ( 0 , L_37 , ( unsigned long long ) F_45 ( V_27 ) -> V_97 ) ;
V_60 = F_128 ( V_39 , & F_45 ( V_27 ) -> V_217 , 1 , 1 ) ;
if ( V_60 ) {
F_121 ( V_60 ) ;
goto V_183;
}
V_60 = F_128 ( V_39 , & F_45 ( V_27 ) -> V_218 , 1 , 0 ) ;
if ( V_60 ) {
F_121 ( V_60 ) ;
goto V_183;
}
V_60 = F_128 ( V_39 , & F_45 ( V_27 ) -> V_219 , 0 , 0 ) ;
if ( V_60 )
F_121 ( V_60 ) ;
V_183:
return V_60 ;
}
int F_131 ( struct V_27 * V_27 , int V_220 )
{
int V_169 , V_1 ;
struct V_3 * V_4 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_98 ) ;
F_3 ( 0 , L_38 ,
( unsigned long long ) F_45 ( V_27 ) -> V_97 ,
V_220 ? L_39 : L_40 ) ;
if ( F_132 ( V_39 ) )
return 0 ;
V_4 = & F_45 ( V_27 ) -> V_217 ;
V_1 = V_220 ? V_143 : V_144 ;
V_169 = F_125 ( F_46 ( V_27 -> V_98 ) , V_4 , V_1 , 0 ,
0 ) ;
if ( V_169 < 0 )
F_121 ( V_169 ) ;
return V_169 ;
}
void F_133 ( struct V_27 * V_27 , int V_220 )
{
int V_1 = V_220 ? V_143 : V_144 ;
struct V_3 * V_4 = & F_45 ( V_27 ) -> V_217 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_98 ) ;
F_3 ( 0 , L_41 ,
( unsigned long long ) F_45 ( V_27 ) -> V_97 ,
V_220 ? L_39 : L_40 ) ;
if ( ! F_132 ( V_39 ) )
F_16 ( F_46 ( V_27 -> V_98 ) , V_4 , V_1 ) ;
}
int F_134 ( struct V_27 * V_27 )
{
int V_169 = 0 ;
struct V_3 * V_4 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_98 ) ;
F_3 ( 0 , L_42 ,
( unsigned long long ) F_45 ( V_27 ) -> V_97 ) ;
if ( F_135 ( V_39 ) || F_132 ( V_39 ) )
goto V_171;
V_4 = & F_45 ( V_27 ) -> V_219 ;
V_169 = F_125 ( F_46 ( V_27 -> V_98 ) , V_4 ,
V_144 , 0 , 0 ) ;
if ( V_169 < 0 )
F_121 ( V_169 ) ;
V_171:
return V_169 ;
}
int F_136 ( struct V_27 * V_27 , int V_220 )
{
int V_169 = 0 , V_1 ;
struct V_3 * V_4 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_98 ) ;
F_3 ( 0 , L_43 ,
( unsigned long long ) F_45 ( V_27 ) -> V_97 ,
V_220 ? L_39 : L_40 ) ;
if ( F_135 ( V_39 ) ) {
if ( V_220 )
V_169 = - V_221 ;
goto V_171;
}
if ( F_132 ( V_39 ) )
goto V_171;
V_4 = & F_45 ( V_27 ) -> V_219 ;
V_1 = V_220 ? V_143 : V_144 ;
V_169 = F_125 ( F_46 ( V_27 -> V_98 ) , V_4 ,
V_1 , V_210 , 0 ) ;
V_171:
return V_169 ;
}
void F_137 ( struct V_27 * V_27 )
{
struct V_3 * V_4 = & F_45 ( V_27 ) -> V_219 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_98 ) ;
F_3 ( 0 , L_44 ,
( unsigned long long ) F_45 ( V_27 ) -> V_97 ) ;
if ( F_132 ( V_39 ) )
goto V_171;
if( V_4 -> V_135 )
F_16 ( F_46 ( V_27 -> V_98 ) , V_4 ,
V_144 ) ;
if( V_4 -> V_136 )
F_16 ( F_46 ( V_27 -> V_98 ) , V_4 ,
V_143 ) ;
V_171:
return;
}
static int F_138 ( struct V_3 * V_4 ,
int V_1 )
{
int V_60 ;
struct V_36 * V_39 = F_15 ( V_4 ) ;
unsigned long V_159 ;
struct V_58 V_59 ;
F_110 ( & V_59 ) ;
V_222:
F_89 ( & V_4 -> V_89 , V_159 ) ;
if ( V_4 -> V_82 & V_156 ) {
V_60 = F_139 ( V_39 , V_4 ) ;
if ( V_60 ) {
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_60 = F_140 ( V_39 , V_4 ) ;
if ( V_60 < 0 ) {
F_121 ( V_60 ) ;
goto V_171;
}
goto V_222;
}
F_115 ( V_4 , & V_59 , V_156 , 0 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
F_112 ( & V_59 ) ;
goto V_222;
}
V_60 = - V_206 ;
if ( V_4 -> V_74 == V_1 )
V_60 = 0 ;
F_3 ( 0 , L_45 , V_60 ,
V_4 -> V_82 , V_4 -> V_74 , V_4 -> V_78 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_171:
return V_60 ;
}
int F_141 ( struct V_223 * V_223 , int V_214 , int V_224 )
{
int V_60 , V_1 = V_214 ? V_143 : V_144 ;
unsigned int V_191 = V_224 ? V_210 : 0 ;
unsigned long V_159 ;
struct V_102 * V_103 = V_223 -> V_225 ;
struct V_3 * V_4 = & V_103 -> V_226 ;
struct V_36 * V_39 = F_46 ( V_223 -> V_105 -> V_106 -> V_98 ) ;
struct V_58 V_59 ;
F_110 ( & V_59 ) ;
if ( ( V_4 -> V_82 & V_156 ) ||
( V_4 -> V_74 > V_146 ) ) {
F_3 ( V_172 ,
L_46
L_47 , V_4 -> V_8 , V_4 -> V_82 ,
V_4 -> V_74 ) ;
return - V_202 ;
}
F_89 ( & V_4 -> V_89 , V_159 ) ;
if ( ! ( V_4 -> V_82 & V_157 ) ) {
F_115 ( V_4 , & V_59 , V_156 , 0 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_60 = F_102 ( V_39 , V_4 , V_146 , 0 ) ;
if ( V_60 < 0 ) {
F_121 ( V_60 ) ;
goto V_171;
}
V_60 = F_112 ( & V_59 ) ;
if ( V_60 ) {
F_121 ( V_60 ) ;
goto V_171;
}
F_89 ( & V_4 -> V_89 , V_159 ) ;
}
V_4 -> V_78 = V_174 ;
V_191 |= V_211 ;
V_4 -> V_76 = V_1 ;
F_80 ( V_4 , V_156 ) ;
F_115 ( V_4 , & V_59 , V_156 , 0 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_60 = F_103 ( V_39 -> V_184 , V_1 , & V_4 -> V_7 , V_191 ,
V_4 -> V_8 , V_47 - 1 ) ;
if ( V_60 ) {
if ( ! V_224 || ( V_60 != - V_170 ) ) {
F_104 ( L_30 , V_60 , V_4 ) ;
V_60 = - V_202 ;
}
F_101 ( V_4 , 1 ) ;
F_117 ( V_4 , & V_59 ) ;
goto V_171;
}
V_60 = F_118 ( & V_59 , V_4 ) ;
if ( V_60 == - V_206 ) {
V_60 = F_138 ( V_4 , V_1 ) ;
} else if ( ! V_60 && ( V_1 > V_4 -> V_74 ) ) {
F_11 ( ! V_224 ) ;
V_60 = - V_170 ;
}
V_171:
F_3 ( 0 , L_48 ,
V_4 -> V_8 , V_214 , V_224 , V_60 ) ;
return V_60 ;
}
void F_142 ( struct V_223 * V_223 )
{
int V_60 ;
unsigned int V_182 ;
unsigned long V_159 ;
struct V_102 * V_103 = V_223 -> V_225 ;
struct V_3 * V_4 = & V_103 -> V_226 ;
struct V_36 * V_39 = F_46 ( V_223 -> V_105 -> V_106 -> V_98 ) ;
struct V_58 V_59 ;
F_110 ( & V_59 ) ;
if ( ! ( V_4 -> V_82 & V_157 ) )
return;
if ( V_4 -> V_74 == V_146 )
return;
F_3 ( 0 , L_49 ,
V_4 -> V_8 , V_4 -> V_82 , V_4 -> V_74 ,
V_4 -> V_78 ) ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
F_80 ( V_4 , V_158 ) ;
V_4 -> V_77 = V_143 ;
V_182 = F_143 ( V_4 , V_146 ) ;
F_115 ( V_4 , & V_59 , V_156 , 0 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_60 = F_144 ( V_39 , V_4 , V_146 , 0 , V_182 ) ;
if ( V_60 ) {
F_121 ( V_60 ) ;
return;
}
V_60 = F_112 ( & V_59 ) ;
if ( V_60 )
F_121 ( V_60 ) ;
}
static void F_126 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_227 = 0 ;
if ( V_4 -> V_82 & V_158 ) {
switch( V_4 -> V_77 ) {
case V_143 :
if ( ! V_4 -> V_136 && ! V_4 -> V_135 )
V_227 = 1 ;
break;
case V_144 :
if ( ! V_4 -> V_136 )
V_227 = 1 ;
break;
default:
F_73 () ;
}
}
if ( V_227 )
F_87 ( V_39 ) ;
}
static T_1 F_145 ( struct V_228 * V_229 )
{
T_1 V_34 ;
T_1 V_230 = V_229 -> V_231 ;
T_2 V_232 = V_229 -> V_233 ;
V_34 = ( V_230 << V_234 ) | ( V_232 & V_235 ) ;
return V_34 ;
}
static void F_146 ( struct V_27 * V_27 )
{
struct V_124 * V_125 = F_45 ( V_27 ) ;
struct V_3 * V_4 = & V_125 -> V_218 ;
struct V_5 * V_6 ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
if ( V_125 -> V_236 & V_237 ) {
V_6 -> V_9 = 0 ;
goto V_171;
}
V_6 -> V_9 = V_238 ;
V_6 -> V_12 = F_53 ( F_147 ( V_27 ) ) ;
V_6 -> V_10 = F_148 ( V_125 -> V_239 ) ;
V_6 -> V_13 = F_148 ( F_149 ( V_27 ) ) ;
V_6 -> V_14 = F_148 ( F_150 ( V_27 ) ) ;
V_6 -> V_15 = F_151 ( V_27 -> V_240 ) ;
V_6 -> V_16 = F_151 ( V_27 -> V_241 ) ;
V_6 -> V_17 =
F_53 ( F_145 ( & V_27 -> V_242 ) ) ;
V_6 -> V_18 =
F_53 ( F_145 ( & V_27 -> V_243 ) ) ;
V_6 -> V_19 =
F_53 ( F_145 ( & V_27 -> V_244 ) ) ;
V_6 -> V_20 = F_148 ( V_125 -> V_245 ) ;
V_6 -> V_246 = F_151 ( V_125 -> V_247 ) ;
V_6 -> V_11 = F_148 ( V_27 -> V_127 ) ;
V_171:
F_152 ( 0 , V_4 ) ;
}
static void F_153 ( struct V_228 * V_229 ,
T_1 V_248 )
{
V_229 -> V_231 = V_248 >> V_234 ;
V_229 -> V_233 = V_248 & V_235 ;
}
static void F_154 ( struct V_27 * V_27 )
{
struct V_124 * V_125 = F_45 ( V_27 ) ;
struct V_3 * V_4 = & V_125 -> V_218 ;
struct V_5 * V_6 ;
F_152 ( 0 , V_4 ) ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
F_21 ( & V_125 -> V_249 ) ;
V_125 -> V_239 = F_4 ( V_6 -> V_10 ) ;
F_155 ( V_27 , F_5 ( V_6 -> V_12 ) ) ;
V_125 -> V_245 = F_4 ( V_6 -> V_20 ) ;
V_125 -> V_247 = F_6 ( V_6 -> V_246 ) ;
F_156 ( V_27 ) ;
if ( F_157 ( V_27 -> V_240 ) && ! V_125 -> V_239 )
V_27 -> V_250 = 0 ;
else
V_27 -> V_250 = F_158 ( V_27 ) ;
F_159 ( V_27 , F_4 ( V_6 -> V_13 ) ) ;
F_160 ( V_27 , F_4 ( V_6 -> V_14 ) ) ;
V_27 -> V_240 = F_6 ( V_6 -> V_15 ) ;
F_161 ( V_27 , F_6 ( V_6 -> V_16 ) ) ;
F_153 ( & V_27 -> V_242 ,
F_5 ( V_6 -> V_17 ) ) ;
F_153 ( & V_27 -> V_244 ,
F_5 ( V_6 -> V_19 ) ) ;
F_153 ( & V_27 -> V_243 ,
F_5 ( V_6 -> V_18 ) ) ;
F_23 ( & V_125 -> V_249 ) ;
}
static inline int F_162 ( struct V_27 * V_27 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_4 -> V_7 ) ;
if ( F_163 ( & V_4 -> V_7 )
&& V_6 -> V_9 == V_238
&& F_4 ( V_6 -> V_11 ) == V_27 -> V_127 )
return 1 ;
return 0 ;
}
static int F_164 ( struct V_3 * V_4 )
{
unsigned long V_159 ;
int V_169 = 0 ;
V_251:
F_89 ( & V_4 -> V_89 , V_159 ) ;
if ( ! ( V_4 -> V_82 & V_161 ) ) {
F_90 ( & V_4 -> V_89 , V_159 ) ;
goto V_183;
}
if ( V_4 -> V_82 & V_186 ) {
F_90 ( & V_4 -> V_89 , V_159 ) ;
F_108 ( V_4 ) ;
goto V_251;
}
F_80 ( V_4 , V_186 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_169 = 1 ;
V_183:
F_3 ( 0 , L_50 , V_169 ) ;
return V_169 ;
}
static inline void F_165 ( struct V_3 * V_4 ,
int V_169 )
{
unsigned long V_159 ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
F_81 ( V_4 , V_186 ) ;
if ( ! V_169 )
F_81 ( V_4 , V_161 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
F_95 ( & V_4 -> V_90 ) ;
}
static int F_166 ( struct V_27 * V_27 ,
struct V_252 * * V_253 )
{
int V_169 = 0 ;
struct V_124 * V_125 = F_45 ( V_27 ) ;
struct V_3 * V_4 = & V_125 -> V_218 ;
struct V_254 * V_255 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_98 ) ;
if ( F_132 ( V_39 ) )
goto V_183;
F_21 ( & V_125 -> V_249 ) ;
if ( V_125 -> V_236 & V_237 ) {
F_3 ( 0 , L_51
L_52 ,
( unsigned long long ) V_125 -> V_97 , V_125 -> V_236 ) ;
F_23 ( & V_125 -> V_249 ) ;
V_169 = - V_256 ;
goto V_183;
}
F_23 ( & V_125 -> V_249 ) ;
if ( ! F_164 ( V_4 ) )
goto V_183;
F_167 ( F_168 ( V_27 ) ) ;
F_169 ( V_27 , 0 ) ;
if ( F_162 ( V_27 , V_4 ) ) {
F_3 ( 0 , L_53 ,
( unsigned long long ) V_125 -> V_97 ) ;
F_154 ( V_27 ) ;
} else {
V_169 = F_170 ( V_27 , V_253 ) ;
if ( V_169 < 0 ) {
F_121 ( V_169 ) ;
goto V_257;
}
V_255 = (struct V_254 * ) ( * V_253 ) -> V_258 ;
F_44 ( V_27 -> V_127 !=
F_171 ( V_255 -> V_127 ) ,
L_54
L_55 ,
( unsigned long long ) V_125 -> V_97 ,
F_171 ( V_255 -> V_127 ) ,
V_27 -> V_127 ) ;
F_44 ( F_172 ( V_255 -> V_259 ) ||
! ( V_255 -> V_260 & F_173 ( V_261 ) ) ,
L_56 ,
( unsigned long long ) V_125 -> V_97 ,
( unsigned long long ) F_172 ( V_255 -> V_259 ) ,
F_171 ( V_255 -> V_260 ) ) ;
F_174 ( V_27 , V_255 ) ;
F_34 ( V_4 ) ;
}
V_169 = 0 ;
V_257:
F_165 ( V_4 , V_169 ) ;
V_183:
return V_169 ;
}
static int F_175 ( struct V_27 * V_27 ,
struct V_252 * * V_262 ,
struct V_252 * V_263 )
{
int V_169 ;
if ( V_263 ) {
* V_262 = V_263 ;
F_176 ( * V_262 ) ;
return 0 ;
}
V_169 = F_170 ( V_27 , V_262 ) ;
if ( V_169 < 0 )
F_121 ( V_169 ) ;
return V_169 ;
}
int F_177 ( struct V_27 * V_27 ,
struct V_252 * * V_262 ,
int V_214 ,
int V_192 ,
int V_264 )
{
int V_169 , V_1 , V_265 ;
T_2 V_181 ;
struct V_3 * V_4 = NULL ;
struct V_36 * V_39 = F_46 ( V_27 -> V_98 ) ;
struct V_252 * V_266 = NULL ;
F_3 ( 0 , L_57 ,
( unsigned long long ) F_45 ( V_27 ) -> V_97 ,
V_214 ? L_39 : L_40 ) ;
V_169 = 0 ;
V_265 = 0 ;
if ( F_135 ( V_39 ) ) {
if ( V_214 )
V_169 = - V_221 ;
goto V_267;
}
if ( ( V_192 & V_268 ) ||
F_132 ( V_39 ) )
goto V_269;
if ( ! ( V_192 & V_270 ) )
F_178 ( V_39 ) ;
V_4 = & F_45 ( V_27 ) -> V_218 ;
V_1 = V_214 ? V_143 : V_144 ;
V_181 = 0 ;
if ( V_192 & V_213 )
V_181 |= V_210 ;
V_169 = F_120 ( V_39 , V_4 , V_1 , V_181 ,
V_192 , V_264 , V_40 ) ;
if ( V_169 < 0 ) {
if ( V_169 != - V_170 )
F_121 ( V_169 ) ;
goto V_183;
}
V_265 = 1 ;
if ( ! ( V_192 & V_270 ) )
F_178 ( V_39 ) ;
V_269:
if ( V_27 -> V_271 & V_272 ) {
V_169 = 0 ;
if ( V_4 )
F_165 ( V_4 , 0 ) ;
goto V_183;
}
V_169 = F_166 ( V_27 , & V_266 ) ;
if ( V_169 < 0 ) {
if ( V_169 != - V_256 )
F_121 ( V_169 ) ;
goto V_183;
}
V_267:
if ( V_262 ) {
V_169 = F_175 ( V_27 , V_262 , V_266 ) ;
if ( V_169 < 0 ) {
F_121 ( V_169 ) ;
goto V_183;
}
}
V_183:
if ( V_169 < 0 ) {
if ( V_262 && ( * V_262 ) ) {
F_179 ( * V_262 ) ;
* V_262 = NULL ;
}
if ( V_265 )
F_180 ( V_27 , V_214 ) ;
}
if ( V_266 )
F_179 ( V_266 ) ;
return V_169 ;
}
int F_181 ( struct V_27 * V_27 ,
struct V_252 * * V_262 ,
int V_214 ,
struct V_273 * V_273 )
{
int V_60 ;
V_60 = F_182 ( V_27 , V_262 , V_214 , V_212 ) ;
if ( V_60 == - V_170 ) {
F_183 ( V_273 ) ;
V_60 = V_274 ;
}
return V_60 ;
}
int F_184 ( struct V_27 * V_27 ,
struct V_275 * V_276 ,
int * V_1 )
{
int V_60 ;
V_60 = F_185 ( V_27 , NULL , 0 ) ;
if ( V_60 < 0 ) {
F_121 ( V_60 ) ;
return V_60 ;
}
if ( F_186 ( V_27 , V_276 ) ) {
struct V_252 * V_253 = NULL ;
F_180 ( V_27 , 0 ) ;
V_60 = F_185 ( V_27 , & V_253 , 1 ) ;
if ( V_60 < 0 ) {
F_121 ( V_60 ) ;
return V_60 ;
}
* V_1 = 1 ;
if ( F_186 ( V_27 , V_276 ) )
F_187 ( V_27 , V_253 ) ;
if ( V_253 )
F_179 ( V_253 ) ;
} else
* V_1 = 0 ;
return V_60 ;
}
void F_180 ( struct V_27 * V_27 ,
int V_214 )
{
int V_1 = V_214 ? V_143 : V_144 ;
struct V_3 * V_4 = & F_45 ( V_27 ) -> V_218 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_98 ) ;
F_3 ( 0 , L_58 ,
( unsigned long long ) F_45 ( V_27 ) -> V_97 ,
V_214 ? L_39 : L_40 ) ;
if ( ! F_135 ( F_46 ( V_27 -> V_98 ) ) &&
! F_132 ( V_39 ) )
F_16 ( F_46 ( V_27 -> V_98 ) , V_4 , V_1 ) ;
}
int F_188 ( struct V_27 * V_27 ,
struct V_252 * * V_262 ,
int V_214 ,
struct V_137 * V_138 )
{
int V_169 ;
int V_192 = 0 , V_277 ;
struct V_3 * V_4 ;
V_4 = & F_45 ( V_27 ) -> V_218 ;
V_277 = F_70 ( V_4 ) ;
if ( V_277 )
V_192 = V_268 ;
if ( F_189 ( ! V_277 || V_262 ) ) {
V_169 = F_182 ( V_27 , V_262 , V_214 , V_192 ) ;
if ( V_169 < 0 ) {
if ( V_169 != - V_256 )
F_121 ( V_169 ) ;
return V_169 ;
}
}
if ( ! V_277 )
F_63 ( V_4 , V_138 ) ;
return V_277 ;
}
void F_190 ( struct V_27 * V_27 ,
int V_214 ,
struct V_137 * V_138 ,
int V_278 )
{
struct V_3 * V_4 ;
V_4 = & F_45 ( V_27 ) -> V_218 ;
if ( ! V_278 ) {
F_67 ( V_4 , V_138 ) ;
F_180 ( V_27 , V_214 ) ;
}
}
int F_191 ( struct V_36 * V_39 , T_2 * V_279 )
{
struct V_3 * V_4 ;
struct V_280 * V_6 ;
int V_169 = 0 ;
if ( F_135 ( V_39 ) )
return - V_221 ;
if ( F_132 ( V_39 ) )
return 0 ;
V_4 = & V_39 -> V_281 . V_282 ;
V_169 = F_125 ( V_39 , V_4 , V_143 , 0 , 0 ) ;
if ( V_169 < 0 )
return V_169 ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
if ( F_163 ( & V_4 -> V_7 ) &&
V_6 -> V_9 == V_283 )
* V_279 = F_4 ( V_6 -> V_284 ) ;
else
* V_279 = V_39 -> V_281 . V_285 + 1 ;
return V_169 ;
}
void F_192 ( struct V_36 * V_39 , T_2 V_279 )
{
struct V_3 * V_4 ;
struct V_280 * V_6 ;
if ( ! F_135 ( V_39 ) && ! F_132 ( V_39 ) ) {
V_4 = & V_39 -> V_281 . V_282 ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
V_6 -> V_9 = V_283 ;
V_6 -> V_284 = F_148 ( V_279 ) ;
F_16 ( V_39 , V_4 , V_143 ) ;
}
}
int F_193 ( struct V_36 * V_39 ,
int V_214 )
{
int V_169 = 0 ;
int V_1 = V_214 ? V_143 : V_144 ;
struct V_3 * V_4 = & V_39 -> V_286 ;
if ( F_135 ( V_39 ) )
return - V_221 ;
if ( F_132 ( V_39 ) )
goto V_183;
V_169 = F_125 ( V_39 , V_4 , V_1 , 0 , 0 ) ;
if ( V_169 < 0 ) {
F_121 ( V_169 ) ;
goto V_183;
}
V_169 = F_164 ( V_4 ) ;
if ( V_169 ) {
V_169 = F_194 ( V_39 ) ;
F_165 ( V_4 , V_169 ) ;
if ( V_169 < 0 ) {
F_16 ( V_39 , V_4 , V_1 ) ;
F_121 ( V_169 ) ;
}
F_34 ( V_4 ) ;
}
V_183:
return V_169 ;
}
void F_195 ( struct V_36 * V_39 ,
int V_214 )
{
int V_1 = V_214 ? V_143 : V_144 ;
struct V_3 * V_4 = & V_39 -> V_286 ;
if ( ! F_132 ( V_39 ) )
F_16 ( V_39 , V_4 , V_1 ) ;
}
int F_196 ( struct V_36 * V_39 )
{
int V_169 ;
struct V_3 * V_4 = & V_39 -> V_287 ;
if ( F_135 ( V_39 ) )
return - V_221 ;
if ( F_132 ( V_39 ) )
return 0 ;
V_169 = F_125 ( V_39 , V_4 , V_143 , 0 , 0 ) ;
if ( V_169 < 0 )
F_121 ( V_169 ) ;
return V_169 ;
}
void F_197 ( struct V_36 * V_39 )
{
struct V_3 * V_4 = & V_39 -> V_287 ;
if ( ! F_132 ( V_39 ) )
F_16 ( V_39 , V_4 , V_143 ) ;
}
int F_198 ( struct V_36 * V_39 , int V_214 )
{
int V_169 ;
struct V_3 * V_4 = & V_39 -> V_288 ;
if ( F_135 ( V_39 ) )
return - V_221 ;
if ( F_132 ( V_39 ) )
return 0 ;
V_169 = F_125 ( V_39 , V_4 , V_214 ? V_65 : V_64 ,
0 , 0 ) ;
if ( V_169 < 0 )
F_3 ( V_172 , L_59 , V_169 ) ;
return V_169 ;
}
void F_199 ( struct V_36 * V_39 , int V_214 )
{
struct V_3 * V_4 = & V_39 -> V_288 ;
if ( ! F_132 ( V_39 ) )
F_16 ( V_39 , V_4 ,
V_214 ? V_65 : V_64 ) ;
}
int V_29 ( struct V_289 * V_289 , int V_214 )
{
int V_60 ;
int V_1 = V_214 ? V_143 : V_144 ;
struct V_29 * V_109 = V_289 -> V_290 ;
struct V_36 * V_39 = F_46 ( V_289 -> V_291 ) ;
F_11 ( ! V_109 ) ;
if ( F_135 ( V_39 ) ) {
if ( V_214 )
return - V_221 ;
return 0 ;
}
if ( F_132 ( V_39 ) )
return 0 ;
V_60 = F_125 ( V_39 , & V_109 -> V_113 , V_1 , 0 , 0 ) ;
if ( V_60 < 0 )
F_121 ( V_60 ) ;
return V_60 ;
}
void F_200 ( struct V_289 * V_289 , int V_214 )
{
int V_1 = V_214 ? V_143 : V_144 ;
struct V_29 * V_109 = V_289 -> V_290 ;
struct V_36 * V_39 = F_46 ( V_289 -> V_291 ) ;
if ( ! F_135 ( V_39 ) && ! F_132 ( V_39 ) )
F_16 ( V_39 , & V_109 -> V_113 , V_1 ) ;
}
static void F_201 ( struct V_292 * V_292 )
{
struct V_49 * V_50 ;
V_50 = F_9 ( V_292 , struct V_49 , V_293 ) ;
F_202 ( V_50 ) ;
}
void F_203 ( struct V_49 * V_50 )
{
if ( V_50 )
F_204 ( & V_50 -> V_293 , F_201 ) ;
}
static void F_205 ( struct V_49 * V_294 )
{
F_206 ( & V_294 -> V_293 ) ;
}
struct V_49 * F_207 ( void )
{
struct V_49 * V_50 ;
V_50 = F_208 ( sizeof( struct V_49 ) , V_295 ) ;
if ( ! V_50 ) {
F_121 ( - V_296 ) ;
goto V_171;
}
F_209 ( & V_50 -> V_293 ) ;
F_42 ( & V_50 -> V_53 ) ;
V_50 -> V_297 = NULL ;
V_171:
return V_50 ;
}
static struct V_3 * F_210 ( struct V_3 * V_298 ,
struct V_299 * V_73 )
{
struct V_3 * V_300 , * V_60 = NULL ;
struct V_49 * V_50 = V_73 -> V_301 ;
F_77 ( & V_51 ) ;
F_71 (iter, &start->l_debug_list, l_debug_list) {
if ( & V_300 -> V_52 == & V_50 -> V_53 ) {
F_3 ( 0 , L_60 , V_60 ) ;
break;
}
if ( V_300 -> V_37 != NULL ) {
V_60 = V_300 ;
break;
}
}
return V_60 ;
}
static void * F_211 ( struct V_302 * V_303 , T_6 * V_304 )
{
struct V_299 * V_73 = V_303 -> V_305 ;
struct V_3 * V_300 ;
F_21 ( & V_51 ) ;
V_300 = F_210 ( & V_73 -> V_306 , V_73 ) ;
if ( V_300 ) {
V_73 -> V_307 = * V_300 ;
V_300 = & V_73 -> V_307 ;
}
F_23 ( & V_51 ) ;
return V_300 ;
}
static void F_212 ( struct V_302 * V_303 , void * V_308 )
{
}
static void * F_213 ( struct V_302 * V_303 , void * V_308 , T_6 * V_304 )
{
struct V_299 * V_73 = V_303 -> V_305 ;
struct V_3 * V_300 = V_308 ;
struct V_3 * V_309 = & V_73 -> V_306 ;
F_21 ( & V_51 ) ;
V_300 = F_210 ( V_300 , V_73 ) ;
F_26 ( & V_309 -> V_52 ) ;
if ( V_300 ) {
F_22 ( & V_309 -> V_52 , & V_300 -> V_52 ) ;
V_73 -> V_307 = * V_300 ;
V_300 = & V_73 -> V_307 ;
}
F_23 ( & V_51 ) ;
return V_300 ;
}
static int F_214 ( struct V_302 * V_303 , void * V_308 )
{
int V_310 ;
char * V_6 ;
struct V_3 * V_4 = V_308 ;
if ( ! V_4 )
return - V_202 ;
F_215 ( V_303 , L_61 , V_311 ) ;
if ( V_4 -> V_21 == V_30 )
F_215 ( V_303 , L_62 , V_108 - 1 ,
V_4 -> V_8 ,
( unsigned int ) F_50 ( V_4 ) ) ;
else
F_215 ( V_303 , L_63 , V_47 , V_4 -> V_8 ) ;
F_215 ( V_303 , L_64
L_65
L_61
L_61
L_66
L_66
L_64
L_64 ,
V_4 -> V_74 ,
V_4 -> V_82 ,
V_4 -> V_78 ,
V_4 -> V_80 ,
V_4 -> V_135 ,
V_4 -> V_136 ,
V_4 -> V_76 ,
V_4 -> V_77 ) ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
for( V_310 = 0 ; V_310 < V_312 ; V_310 ++ )
F_215 ( V_303 , L_61 , V_6 [ V_310 ] ) ;
#ifdef F_216
# define F_217 ( T_7 ) ((_l)->l_lock_prmode.ls_gets)
# define F_218 ( T_7 ) ((_l)->l_lock_exmode.ls_gets)
# define F_219 ( T_7 ) ((_l)->l_lock_prmode.ls_fail)
# define F_220 ( T_7 ) ((_l)->l_lock_exmode.ls_fail)
# define F_221 ( T_7 ) ((_l)->l_lock_prmode.ls_total)
# define F_222 ( T_7 ) ((_l)->l_lock_exmode.ls_total)
# define F_223 ( T_7 ) ((_l)->l_lock_prmode.ls_max)
# define F_224 ( T_7 ) ((_l)->l_lock_exmode.ls_max)
# define F_225 ( T_7 ) ((_l)->l_lock_refresh)
#else
# define F_217 ( T_7 ) (0)
# define F_218 ( T_7 ) (0)
# define F_219 ( T_7 ) (0)
# define F_220 ( T_7 ) (0)
# define F_221 ( T_7 ) (0ULL)
# define F_222 ( T_7 ) (0ULL)
# define F_223 ( T_7 ) (0)
# define F_224 ( T_7 ) (0)
# define F_225 ( T_7 ) (0)
#endif
F_215 ( V_303 , L_66
L_66
L_66
L_66
L_67
L_67
L_66
L_66
L_66 ,
F_217 ( V_4 ) ,
F_218 ( V_4 ) ,
F_219 ( V_4 ) ,
F_220 ( V_4 ) ,
F_221 ( V_4 ) ,
F_222 ( V_4 ) ,
F_223 ( V_4 ) ,
F_224 ( V_4 ) ,
F_225 ( V_4 ) ) ;
F_215 ( V_303 , L_68 ) ;
return 0 ;
}
static int F_226 ( struct V_27 * V_27 , struct V_223 * V_223 )
{
struct V_302 * V_313 = V_223 -> V_225 ;
struct V_299 * V_73 = V_313 -> V_305 ;
struct V_3 * V_34 = & V_73 -> V_306 ;
F_24 ( V_34 ) ;
F_203 ( V_73 -> V_301 ) ;
return F_227 ( V_27 , V_223 ) ;
}
static int F_228 ( struct V_27 * V_27 , struct V_223 * V_223 )
{
struct V_299 * V_73 ;
struct V_36 * V_39 ;
V_73 = F_229 ( V_223 , & V_314 , sizeof( * V_73 ) ) ;
if ( ! V_73 ) {
F_121 ( - V_296 ) ;
return - V_296 ;
}
V_39 = V_27 -> V_315 ;
F_205 ( V_39 -> V_84 ) ;
V_73 -> V_301 = V_39 -> V_84 ;
F_42 ( & V_73 -> V_306 . V_52 ) ;
F_20 ( & V_73 -> V_306 ,
V_73 -> V_301 ) ;
return 0 ;
}
static int F_230 ( struct V_36 * V_39 )
{
int V_60 = 0 ;
struct V_49 * V_50 = V_39 -> V_84 ;
V_50 -> V_297 = F_231 ( L_69 ,
V_316 | V_317 ,
V_39 -> V_318 ,
V_39 ,
& V_319 ) ;
if ( ! V_50 -> V_297 ) {
V_60 = - V_202 ;
F_3 ( V_172 ,
L_70 ) ;
goto V_171;
}
F_205 ( V_50 ) ;
V_171:
return V_60 ;
}
static void F_232 ( struct V_36 * V_39 )
{
struct V_49 * V_50 = V_39 -> V_84 ;
if ( V_50 ) {
F_233 ( V_50 -> V_297 ) ;
F_203 ( V_50 ) ;
}
}
int F_234 ( struct V_36 * V_39 )
{
int V_169 = 0 ;
struct V_320 * V_321 = NULL ;
if ( F_132 ( V_39 ) ) {
V_39 -> V_322 = 0 ;
goto V_215;
}
V_169 = F_230 ( V_39 ) ;
if ( V_169 < 0 ) {
F_121 ( V_169 ) ;
goto V_183;
}
V_39 -> V_323 = F_235 ( V_324 , V_39 , L_71 ,
V_39 -> V_325 ) ;
if ( F_236 ( V_39 -> V_323 ) ) {
V_169 = F_237 ( V_39 -> V_323 ) ;
V_39 -> V_323 = NULL ;
F_121 ( V_169 ) ;
goto V_183;
}
V_169 = F_238 ( V_39 -> V_326 ,
V_39 -> V_327 ,
strlen ( V_39 -> V_327 ) ,
V_39 -> V_325 ,
strlen ( V_39 -> V_325 ) ,
& V_178 , V_328 , V_39 ,
& V_321 ) ;
if ( V_169 ) {
F_121 ( V_169 ) ;
goto V_183;
}
V_169 = F_239 ( V_321 , & V_39 -> V_322 ) ;
if ( V_169 < 0 ) {
F_121 ( V_169 ) ;
F_3 ( V_172 ,
L_72 ) ;
F_240 ( V_321 , 0 ) ;
goto V_183;
}
V_215:
F_54 ( & V_39 -> V_286 , V_39 ) ;
F_55 ( & V_39 -> V_287 , V_39 ) ;
F_56 ( & V_39 -> V_288 , V_39 ) ;
F_57 ( & V_39 -> V_281 . V_282 , V_39 ) ;
V_39 -> V_184 = V_321 ;
V_183:
if ( V_169 < 0 ) {
F_232 ( V_39 ) ;
if ( V_39 -> V_323 )
F_241 ( V_39 -> V_323 ) ;
}
return V_169 ;
}
void F_242 ( struct V_36 * V_39 ,
int V_329 )
{
F_243 ( V_39 ) ;
if ( V_39 -> V_323 ) {
F_241 ( V_39 -> V_323 ) ;
V_39 -> V_323 = NULL ;
}
F_61 ( & V_39 -> V_286 ) ;
F_61 ( & V_39 -> V_287 ) ;
F_61 ( & V_39 -> V_288 ) ;
F_61 ( & V_39 -> V_281 . V_282 ) ;
F_240 ( V_39 -> V_184 , V_329 ) ;
V_39 -> V_184 = NULL ;
F_232 ( V_39 ) ;
}
static int F_244 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_60 ;
unsigned long V_159 ;
T_2 V_191 = 0 ;
if ( ! ( V_4 -> V_82 & V_83 ) )
goto V_171;
if ( V_4 -> V_37 -> V_159 & V_203 )
V_191 |= V_204 ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
F_44 ( ! ( V_4 -> V_82 & V_208 ) ,
L_73 ,
V_4 -> V_8 , V_4 -> V_82 ) ;
while ( V_4 -> V_82 & V_156 ) {
F_3 ( 0 , L_74
L_75 ,
V_4 -> V_8 , V_4 -> V_82 , V_4 -> V_78 ,
V_4 -> V_80 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
F_106 ( V_4 ) ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
}
if ( V_4 -> V_37 -> V_159 & V_203 ) {
if ( V_4 -> V_82 & V_157 &&
V_4 -> V_74 == V_143 &&
! ( V_4 -> V_82 & V_161 ) )
V_4 -> V_37 -> V_330 ( V_4 ) ;
}
if ( V_4 -> V_82 & V_156 )
F_3 ( V_172 , L_76 ,
V_4 -> V_8 ) ;
if ( V_4 -> V_82 & V_158 )
F_3 ( 0 , L_77 , V_4 -> V_8 ) ;
if ( ! ( V_4 -> V_82 & V_157 ) ) {
F_90 ( & V_4 -> V_89 , V_159 ) ;
goto V_171;
}
F_81 ( V_4 , V_157 ) ;
F_11 ( V_4 -> V_78 != V_79 ) ;
F_80 ( V_4 , V_156 ) ;
V_4 -> V_80 = V_177 ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
F_3 ( 0 , L_78 , V_4 -> V_8 ) ;
V_60 = F_245 ( V_39 -> V_184 , & V_4 -> V_7 , V_191 ) ;
if ( V_60 ) {
F_104 ( L_79 , V_60 , V_4 ) ;
F_3 ( V_172 , L_80 , V_4 -> V_82 ) ;
F_246 ( & V_4 -> V_7 ) ;
F_73 () ;
}
F_3 ( 0 , L_81 ,
V_4 -> V_8 ) ;
F_106 ( V_4 ) ;
V_171:
return 0 ;
}
void F_247 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_169 ;
struct V_58 V_59 ;
unsigned long V_159 , V_331 ;
F_110 ( & V_59 ) ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
V_4 -> V_82 |= V_208 ;
if ( V_4 -> V_82 & V_332 && V_141 == V_39 -> V_323 ) {
F_90 ( & V_4 -> V_89 , V_159 ) ;
F_89 ( & V_39 -> V_333 , V_331 ) ;
F_26 ( & V_4 -> V_91 ) ;
V_39 -> V_334 -- ;
F_90 ( & V_39 -> V_333 , V_331 ) ;
F_248 ( V_4 -> V_37 -> V_335 ) ;
F_249 ( V_39 , V_4 ) ;
return;
}
while ( V_4 -> V_82 & V_332 ) {
F_115 ( V_4 , & V_59 , V_332 , 0 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
F_3 ( 0 , L_82 , V_4 -> V_8 ) ;
V_169 = F_112 ( & V_59 ) ;
if ( V_169 )
F_121 ( V_169 ) ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
}
F_90 ( & V_4 -> V_89 , V_159 ) ;
}
void F_250 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_60 ;
F_247 ( V_39 , V_4 ) ;
V_60 = F_244 ( V_39 , V_4 ) ;
if ( V_60 )
F_121 ( V_60 ) ;
}
static void F_243 ( struct V_36 * V_39 )
{
F_250 ( V_39 , & V_39 -> V_286 ) ;
F_250 ( V_39 , & V_39 -> V_287 ) ;
F_250 ( V_39 , & V_39 -> V_288 ) ;
F_250 ( V_39 , & V_39 -> V_281 . V_282 ) ;
}
int F_251 ( struct V_27 * V_27 )
{
int V_169 , V_336 ;
V_336 = F_244 ( F_46 ( V_27 -> V_98 ) ,
& F_45 ( V_27 ) -> V_219 ) ;
if ( V_336 < 0 )
F_121 ( V_336 ) ;
V_169 = V_336 ;
V_336 = F_244 ( F_46 ( V_27 -> V_98 ) ,
& F_45 ( V_27 ) -> V_218 ) ;
if ( V_336 < 0 )
F_121 ( V_336 ) ;
if ( V_336 < 0 && ! V_169 )
V_169 = V_336 ;
V_336 = F_244 ( F_46 ( V_27 -> V_98 ) ,
& F_45 ( V_27 ) -> V_217 ) ;
if ( V_336 < 0 )
F_121 ( V_336 ) ;
if ( V_336 < 0 && ! V_169 )
V_169 = V_336 ;
return V_169 ;
}
static unsigned int F_143 ( struct V_3 * V_4 ,
int V_145 )
{
F_77 ( & V_4 -> V_89 ) ;
F_11 ( V_4 -> V_77 <= V_146 ) ;
if ( V_4 -> V_74 <= V_145 ) {
F_3 ( V_172 , L_83
L_84
L_85 , V_4 -> V_8 , V_4 -> V_74 ,
V_145 , F_25 ( & V_4 -> V_91 ) ,
F_25 ( & V_4 -> V_92 ) , V_4 -> V_21 ,
V_4 -> V_82 , V_4 -> V_135 ,
V_4 -> V_136 , V_4 -> V_78 ,
V_4 -> V_80 , V_4 -> V_76 ,
V_4 -> V_77 , V_4 -> V_168 ) ;
F_73 () ;
}
F_3 ( V_166 , L_86 ,
V_4 -> V_8 , V_4 -> V_74 , V_145 , V_4 -> V_77 ) ;
V_4 -> V_78 = V_175 ;
V_4 -> V_76 = V_145 ;
F_80 ( V_4 , V_156 ) ;
return F_91 ( V_4 ) ;
}
static int F_144 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_145 ,
int V_6 ,
unsigned int V_43 )
{
int V_60 ;
T_2 V_181 = V_211 ;
F_3 ( V_166 , L_87 , V_4 -> V_8 ,
V_4 -> V_74 , V_145 ) ;
if ( ! F_252 () &&
V_4 -> V_37 -> V_159 & V_203 )
V_6 = 1 ;
if ( V_6 )
V_181 |= V_204 ;
V_60 = F_103 ( V_39 -> V_184 ,
V_145 ,
& V_4 -> V_7 ,
V_181 ,
V_4 -> V_8 ,
V_47 - 1 ) ;
F_88 ( V_4 , V_43 , V_39 ) ;
if ( V_60 ) {
F_104 ( L_30 , V_60 , V_4 ) ;
F_101 ( V_4 , 1 ) ;
goto V_183;
}
V_60 = 0 ;
V_183:
return V_60 ;
}
static int F_139 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
F_77 ( & V_4 -> V_89 ) ;
if ( V_4 -> V_80 == V_176 ) {
F_3 ( V_166 , L_88 , V_4 -> V_8 ) ;
return 0 ;
}
F_11 ( V_4 -> V_78 != V_174 &&
V_4 -> V_78 != V_175 ) ;
V_4 -> V_80 = V_176 ;
F_44 ( ! ( V_4 -> V_82 & V_156 ) ,
L_89 ,
V_4 -> V_8 , V_4 -> V_82 ) ;
F_3 ( V_166 , L_90 , V_4 -> V_8 ) ;
return 1 ;
}
static int F_140 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_60 ;
V_60 = F_245 ( V_39 -> V_184 , & V_4 -> V_7 ,
V_337 ) ;
if ( V_60 ) {
F_104 ( L_79 , V_60 , V_4 ) ;
F_101 ( V_4 , 0 ) ;
}
F_3 ( V_166 , L_90 , V_4 -> V_8 ) ;
return V_60 ;
}
static int F_253 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
struct V_338 * V_339 )
{
unsigned long V_159 ;
int V_340 ;
int V_145 ;
int V_1 ;
int V_60 = 0 ;
int V_330 = 0 ;
unsigned int V_182 ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
V_341:
if ( ! ( V_4 -> V_82 & V_158 ) ) {
F_11 ( V_4 -> V_77 != V_146 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_60 = 0 ;
goto V_342;
}
if ( V_4 -> V_82 & V_156 ) {
if ( V_4 -> V_82 & V_167 ) {
F_3 ( V_166 , L_91 ,
V_4 -> V_8 ) ;
goto V_343;
}
V_339 -> V_344 = 1 ;
V_60 = F_139 ( V_39 , V_4 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
if ( V_60 ) {
V_60 = F_140 ( V_39 , V_4 ) ;
if ( V_60 < 0 )
F_121 ( V_60 ) ;
}
goto V_342;
}
if ( V_4 -> V_82 & V_163 )
goto V_343;
if ( V_4 -> V_74 == V_146 ) {
F_11 ( V_4 -> V_136 || V_4 -> V_135 ) ;
F_3 ( V_166 , L_92 , V_4 -> V_8 ) ;
V_4 -> V_77 = V_146 ;
F_81 ( V_4 , V_158 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
goto V_342;
}
if ( ( V_4 -> V_77 == V_143 )
&& ( V_4 -> V_136 || V_4 -> V_135 ) ) {
F_3 ( V_166 , L_93 ,
V_4 -> V_8 , V_4 -> V_136 ,
V_4 -> V_135 ) ;
goto V_343;
}
if ( V_4 -> V_77 == V_144 &&
V_4 -> V_136 ) {
F_3 ( V_166 , L_94 ,
V_4 -> V_8 , V_4 -> V_136 ) ;
goto V_343;
}
if ( ( V_4 -> V_37 -> V_159 & V_160 )
&& ( V_4 -> V_82 & V_186 ) ) {
F_3 ( V_166 , L_95 ,
V_4 -> V_8 ) ;
goto V_343;
}
V_145 = F_75 ( V_4 -> V_77 ) ;
if ( V_4 -> V_37 -> V_345
&& ! V_4 -> V_37 -> V_345 ( V_4 , V_145 ) ) {
F_3 ( V_166 , L_96 ,
V_4 -> V_8 ) ;
goto V_343;
}
if ( ! V_4 -> V_37 -> V_346 )
goto V_347;
V_340 = V_4 -> V_77 ;
V_1 = V_4 -> V_74 ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_339 -> V_348 = V_4 -> V_37 -> V_346 ( V_4 , V_340 ) ;
if ( V_339 -> V_348 == V_349 ) {
F_3 ( V_166 , L_97 ,
V_4 -> V_8 ) ;
goto V_342;
}
F_89 ( & V_4 -> V_89 , V_159 ) ;
if ( ( V_340 != V_4 -> V_77 ) || ( V_1 != V_4 -> V_74 ) ) {
F_3 ( V_166 , L_98
L_99 , V_4 -> V_8 , V_340 ,
V_4 -> V_77 , V_1 , V_4 -> V_74 ) ;
goto V_341;
}
V_347:
V_339 -> V_344 = 0 ;
if ( V_4 -> V_37 -> V_159 & V_203 ) {
if ( V_4 -> V_74 == V_143 )
V_330 = 1 ;
if ( V_330 && ! ( V_4 -> V_82 & V_161 ) )
V_4 -> V_37 -> V_330 ( V_4 ) ;
}
V_182 = F_143 ( V_4 , V_145 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_60 = F_144 ( V_39 , V_4 , V_145 , V_330 ,
V_182 ) ;
V_342:
if ( V_60 )
F_121 ( V_60 ) ;
return V_60 ;
V_343:
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_339 -> V_344 = 1 ;
return 0 ;
}
static int F_254 ( struct V_3 * V_4 ,
int V_340 )
{
struct V_27 * V_27 ;
struct V_350 * V_351 ;
struct V_124 * V_125 ;
V_27 = F_10 ( V_4 ) ;
V_351 = V_27 -> V_352 ;
if ( F_255 ( V_27 -> V_240 ) ) {
V_125 = F_45 ( V_27 ) ;
V_125 -> V_353 ++ ;
F_3 ( 0 , L_100 , V_125 -> V_353 ) ;
goto V_171;
}
if ( ! F_256 ( V_27 -> V_240 ) )
goto V_171;
F_257 ( V_351 , 0 , 0 , 0 ) ;
if ( F_258 ( V_351 ) ) {
F_3 ( V_172 , L_101 ,
( unsigned long long ) F_45 ( V_27 ) -> V_97 ) ;
}
F_259 ( V_351 ) ;
if ( V_340 == V_143 ) {
F_260 ( V_351 , 0 ) ;
} else {
F_261 ( V_351 ) ;
}
F_262 ( V_27 ) ;
V_171:
return V_354 ;
}
static int F_263 ( struct V_355 * V_356 ,
struct V_3 * V_4 ,
int V_145 )
{
int V_357 = F_264 ( V_356 ) ;
F_11 ( V_145 != V_146 && V_145 != V_144 ) ;
F_11 ( V_4 -> V_74 != V_143 && ! V_357 ) ;
if ( V_357 )
return 1 ;
F_265 ( F_46 ( F_266 ( V_356 ) ) ) ;
return 0 ;
}
static int F_267 ( struct V_3 * V_4 ,
int V_145 )
{
struct V_27 * V_27 = F_10 ( V_4 ) ;
return F_263 ( F_168 ( V_27 ) , V_4 , V_145 ) ;
}
static void F_268 ( struct V_3 * V_4 )
{
struct V_27 * V_27 = F_10 ( V_4 ) ;
F_146 ( V_27 ) ;
}
static void F_269 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
struct V_29 * V_109 = F_12 ( V_4 ) ;
F_270 ( V_39 , V_109 ) ;
}
static int F_271 ( struct V_3 * V_4 ,
int V_340 )
{
struct V_29 * V_109 = F_12 ( V_4 ) ;
struct V_124 * V_125 = F_45 ( V_109 -> V_110 ) ;
struct V_289 * V_289 ;
unsigned long V_159 ;
int V_358 = 0 ;
if ( V_340 == V_144 )
return V_354 ;
F_21 ( & V_125 -> V_249 ) ;
V_125 -> V_236 |= V_359 ;
F_23 ( & V_125 -> V_249 ) ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
F_21 ( & V_360 ) ;
if ( ! ( V_4 -> V_82 & V_208 )
&& V_109 -> V_361 ) {
V_109 -> V_361 ++ ;
V_358 = 1 ;
}
F_23 ( & V_360 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
F_3 ( 0 , L_102 , V_358 ) ;
if ( ! V_358 )
return V_354 ;
F_21 ( & V_360 ) ;
while ( 1 ) {
V_289 = F_272 ( V_109 -> V_110 ,
V_109 -> V_362 , 1 ) ;
if ( ! V_289 )
break;
F_23 ( & V_360 ) ;
if ( F_255 ( V_109 -> V_110 -> V_240 ) )
F_273 ( V_289 ) ;
F_3 ( 0 , L_103 , V_289 ) ;
F_274 ( V_289 ) ;
F_275 ( V_289 ) ;
F_21 ( & V_360 ) ;
}
F_23 ( & V_360 ) ;
if ( V_109 -> V_361 == 1 )
return V_349 ;
return V_363 ;
}
static int F_276 ( struct V_3 * V_4 ,
int V_145 )
{
struct V_33 * V_364 =
F_14 ( V_4 ) ;
return F_263 ( & V_364 -> V_365 , V_4 , V_145 ) ;
}
static int F_277 ( struct V_3 * V_4 ,
int V_340 )
{
struct V_33 * V_364 =
F_14 ( V_4 ) ;
F_167 ( & V_364 -> V_365 ) ;
return V_354 ;
}
static void F_278 ( struct V_3 * V_4 )
{
struct V_366 * V_6 ;
struct V_31 * V_367 = F_13 ( V_4 ) ;
struct V_368 * V_99 = F_279 ( V_367 -> V_100 . V_101 ,
V_367 -> V_100 . V_130 ) ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
V_6 -> V_9 = V_369 ;
V_6 -> V_370 = F_148 ( V_99 -> V_371 ) ;
V_6 -> V_372 = F_148 ( V_99 -> V_373 ) ;
V_6 -> V_374 = F_148 ( V_367 -> V_375 ) ;
V_6 -> V_376 = F_148 ( V_367 -> V_100 . V_377 ) ;
V_6 -> V_378 = F_148 ( V_367 -> V_100 . V_379 ) ;
V_6 -> V_380 = F_148 ( V_367 -> V_100 . V_381 ) ;
}
void F_280 ( struct V_31 * V_367 , int V_214 )
{
struct V_3 * V_4 = & V_367 -> V_382 ;
struct V_36 * V_39 = F_46 ( V_367 -> V_100 . V_101 ) ;
int V_1 = V_214 ? V_143 : V_144 ;
if ( ! F_135 ( V_39 ) && ! F_132 ( V_39 ) )
F_16 ( V_39 , V_4 , V_1 ) ;
}
static int F_281 ( struct V_31 * V_367 )
{
struct V_368 * V_99 = F_279 ( V_367 -> V_100 . V_101 ,
V_367 -> V_100 . V_130 ) ;
struct V_3 * V_4 = & V_367 -> V_382 ;
struct V_366 * V_6 = F_2 ( & V_4 -> V_7 ) ;
struct V_252 * V_253 = NULL ;
struct V_383 * V_384 ;
int V_169 = 0 ;
if ( F_163 ( & V_4 -> V_7 ) &&
V_6 -> V_9 == V_369 ) {
V_99 -> V_371 = F_4 ( V_6 -> V_370 ) ;
V_99 -> V_373 = F_4 ( V_6 -> V_372 ) ;
V_367 -> V_375 = F_4 ( V_6 -> V_374 ) ;
V_367 -> V_100 . V_377 = F_4 ( V_6 -> V_376 ) ;
V_367 -> V_100 . V_379 = F_4 ( V_6 -> V_378 ) ;
V_367 -> V_100 . V_381 =
F_4 ( V_6 -> V_380 ) ;
} else {
V_169 = F_282 ( V_367 -> V_385 ,
V_367 -> V_386 , & V_253 ) ;
if ( V_169 ) {
F_121 ( V_169 ) ;
goto V_183;
}
V_384 = (struct V_383 * )
( V_253 -> V_258 + V_387 ) ;
V_99 -> V_371 = F_171 ( V_384 -> V_371 ) ;
V_99 -> V_373 = F_171 ( V_384 -> V_373 ) ;
V_367 -> V_375 = F_171 ( V_384 -> V_375 ) ;
V_367 -> V_100 . V_377 = F_171 ( V_384 -> V_377 ) ;
V_367 -> V_100 . V_379 = F_171 ( V_384 -> V_379 ) ;
V_367 -> V_100 . V_381 =
F_171 ( V_384 -> V_381 ) ;
F_179 ( V_253 ) ;
F_34 ( V_4 ) ;
}
V_183:
return V_169 ;
}
int F_283 ( struct V_31 * V_367 , int V_214 )
{
struct V_3 * V_4 = & V_367 -> V_382 ;
struct V_36 * V_39 = F_46 ( V_367 -> V_100 . V_101 ) ;
int V_1 = V_214 ? V_143 : V_144 ;
int V_169 = 0 ;
if ( F_135 ( V_39 ) ) {
if ( V_214 )
V_169 = - V_221 ;
goto V_183;
}
if ( F_132 ( V_39 ) )
goto V_183;
V_169 = F_125 ( V_39 , V_4 , V_1 , 0 , 0 ) ;
if ( V_169 < 0 ) {
F_121 ( V_169 ) ;
goto V_183;
}
if ( ! F_164 ( V_4 ) )
goto V_183;
V_169 = F_281 ( V_367 ) ;
if ( V_169 )
F_280 ( V_367 , V_214 ) ;
F_165 ( V_4 , V_169 ) ;
V_183:
return V_169 ;
}
int F_284 ( struct V_33 * V_388 , int V_214 )
{
int V_169 ;
int V_1 = V_214 ? V_143 : V_144 ;
struct V_3 * V_4 = & V_388 -> V_35 ;
struct V_36 * V_39 = V_4 -> V_28 ;
if ( F_135 ( V_39 ) )
return - V_221 ;
if ( F_132 ( V_39 ) )
return 0 ;
V_169 = F_125 ( V_39 , V_4 , V_1 , 0 , 0 ) ;
if ( V_169 < 0 )
F_121 ( V_169 ) ;
return V_169 ;
}
void F_285 ( struct V_33 * V_388 , int V_214 )
{
int V_1 = V_214 ? V_143 : V_144 ;
struct V_3 * V_4 = & V_388 -> V_35 ;
struct V_36 * V_39 = V_4 -> V_28 ;
if ( ! F_132 ( V_39 ) )
F_16 ( V_39 , V_4 , V_1 ) ;
}
static void F_249 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_169 ;
struct V_338 V_339 = { 0 , 0 ,} ;
unsigned long V_159 ;
F_11 ( ! V_4 ) ;
F_11 ( ! V_4 -> V_37 ) ;
F_3 ( V_166 , L_104 , V_4 -> V_8 ) ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
if ( V_4 -> V_82 & V_208 )
goto V_389;
F_90 ( & V_4 -> V_89 , V_159 ) ;
V_169 = F_253 ( V_39 , V_4 , & V_339 ) ;
if ( V_169 < 0 )
F_121 ( V_169 ) ;
F_89 ( & V_4 -> V_89 , V_159 ) ;
V_389:
if ( V_4 -> V_82 & V_208 || ! V_339 . V_344 ) {
F_81 ( V_4 , V_332 ) ;
} else
F_94 ( V_39 , V_4 ) ;
F_3 ( V_166 , L_105 , V_4 -> V_8 ,
V_339 . V_344 ? L_106 : L_107 ) ;
F_90 ( & V_4 -> V_89 , V_159 ) ;
if ( V_339 . V_348 != V_354
&& V_4 -> V_37 -> V_335 )
V_4 -> V_37 -> V_335 ( V_39 , V_4 ) ;
}
static void F_94 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
unsigned long V_159 ;
F_77 ( & V_4 -> V_89 ) ;
if ( V_4 -> V_82 & V_208 ) {
F_3 ( V_166 , L_108 ,
V_4 -> V_8 , V_4 -> V_82 ) ;
return;
}
F_80 ( V_4 , V_332 ) ;
F_89 ( & V_39 -> V_333 , V_159 ) ;
if ( F_25 ( & V_4 -> V_91 ) ) {
F_66 ( & V_4 -> V_91 ,
& V_39 -> V_390 ) ;
V_39 -> V_334 ++ ;
}
F_90 ( & V_39 -> V_333 , V_159 ) ;
}
static void F_286 ( struct V_36 * V_39 )
{
unsigned long V_391 ;
unsigned long V_159 ;
struct V_3 * V_4 ;
F_89 ( & V_39 -> V_333 , V_159 ) ;
V_39 -> V_392 = V_39 -> V_393 ;
V_391 = V_39 -> V_334 ;
while ( V_391 && ! F_25 ( & V_39 -> V_390 ) ) {
V_4 = F_287 ( V_39 -> V_390 . V_394 ,
struct V_3 , V_91 ) ;
F_26 ( & V_4 -> V_91 ) ;
V_39 -> V_334 -- ;
F_90 ( & V_39 -> V_333 , V_159 ) ;
F_11 ( ! V_391 ) ;
V_391 -- ;
F_249 ( V_39 , V_4 ) ;
F_89 ( & V_39 -> V_333 , V_159 ) ;
}
F_90 ( & V_39 -> V_333 , V_159 ) ;
}
static int F_288 ( struct V_36 * V_39 )
{
int V_395 = 0 ;
unsigned long V_159 ;
F_89 ( & V_39 -> V_333 , V_159 ) ;
if ( F_25 ( & V_39 -> V_390 ) )
V_395 = 1 ;
F_90 ( & V_39 -> V_333 , V_159 ) ;
return V_395 ;
}
static int F_289 ( struct V_36 * V_39 )
{
int V_396 = 0 ;
unsigned long V_159 ;
F_89 ( & V_39 -> V_333 , V_159 ) ;
if ( V_39 -> V_392 != V_39 -> V_393 )
V_396 = 1 ;
F_90 ( & V_39 -> V_333 , V_159 ) ;
return V_396 ;
}
static int V_324 ( void * V_397 )
{
int V_169 = 0 ;
struct V_36 * V_39 = V_397 ;
while ( ! ( F_290 () &&
F_288 ( V_39 ) ) ) {
F_291 ( V_39 -> V_398 ,
F_289 ( V_39 ) ||
F_290 () ) ;
F_3 ( 0 , L_109 ) ;
F_286 ( V_39 ) ;
}
V_39 -> V_323 = NULL ;
return V_169 ;
}
void F_87 ( struct V_36 * V_39 )
{
unsigned long V_159 ;
F_89 ( & V_39 -> V_333 , V_159 ) ;
V_39 -> V_393 ++ ;
F_90 ( & V_39 -> V_333 , V_159 ) ;
F_95 ( & V_39 -> V_398 ) ;
}
