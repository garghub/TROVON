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
}
void F_43 ( struct V_3 * V_34 ,
enum V_41 type ,
unsigned int V_43 ,
struct V_27 * V_27 )
{
struct V_71 * V_72 ;
switch( type ) {
case V_23 :
V_72 = & V_93 ;
break;
case V_22 :
V_72 = & V_94 ;
break;
case V_24 :
V_72 = & V_95 ;
break;
default:
F_44 ( 1 , L_9 , type ) ;
V_72 = NULL ;
break;
} ;
F_18 ( type , F_45 ( V_27 ) -> V_96 ,
V_43 , V_34 -> V_8 ) ;
F_36 ( F_46 ( V_27 -> V_97 ) , V_34 , type , V_72 , V_27 ) ;
}
static struct V_36 * F_47 ( struct V_3 * V_4 )
{
struct V_27 * V_27 = F_10 ( V_4 ) ;
return F_46 ( V_27 -> V_97 ) ;
}
static struct V_36 * F_48 ( struct V_3 * V_4 )
{
struct V_31 * V_98 = V_4 -> V_28 ;
return F_46 ( V_98 -> V_99 . V_100 ) ;
}
static struct V_36 * F_49 ( struct V_3 * V_4 )
{
struct V_101 * V_102 = V_4 -> V_28 ;
return F_46 ( V_102 -> V_103 -> V_104 -> V_105 -> V_97 ) ;
}
static T_4 F_50 ( struct V_3 * V_4 )
{
T_5 V_106 ;
memcpy ( & V_106 , & V_4 -> V_8 [ V_107 ] ,
sizeof( T_5 ) ) ;
return F_5 ( V_106 ) ;
}
static struct V_36 * F_51 ( struct V_3 * V_4 )
{
struct V_29 * V_108 = V_4 -> V_28 ;
return F_46 ( V_108 -> V_109 -> V_97 ) ;
}
void F_52 ( struct V_29 * V_108 ,
T_1 V_110 , struct V_27 * V_27 )
{
int V_45 ;
T_1 V_111 = F_45 ( V_27 ) -> V_96 ;
T_5 V_106 = F_53 ( V_111 ) ;
struct V_3 * V_4 = & V_108 -> V_112 ;
F_39 ( V_4 ) ;
V_45 = snprintf ( V_4 -> V_8 , V_107 ,
L_10 ,
F_19 ( V_30 ) ,
( long long ) V_110 ) ;
F_11 ( V_45 != ( V_107 - 1 ) ) ;
memcpy ( & V_4 -> V_8 [ V_107 ] , & V_106 ,
sizeof( T_5 ) ) ;
F_36 ( F_46 ( V_27 -> V_97 ) , V_4 ,
V_30 , & V_113 ,
V_108 ) ;
}
static void F_54 ( struct V_3 * V_34 ,
struct V_36 * V_39 )
{
F_39 ( V_34 ) ;
F_18 ( V_114 , V_115 ,
0 , V_34 -> V_8 ) ;
F_36 ( V_39 , V_34 , V_114 ,
& V_116 , V_39 ) ;
}
static void F_55 ( struct V_3 * V_34 ,
struct V_36 * V_39 )
{
F_39 ( V_34 ) ;
F_18 ( V_117 , 0 , 0 , V_34 -> V_8 ) ;
F_36 ( V_39 , V_34 , V_117 ,
& V_118 , V_39 ) ;
}
static void F_56 ( struct V_3 * V_34 ,
struct V_36 * V_39 )
{
F_39 ( V_34 ) ;
F_18 ( V_119 , 0 , 0 , V_34 -> V_8 ) ;
F_36 ( V_39 , V_34 , V_119 ,
& V_120 , V_39 ) ;
}
static void F_57 ( struct V_3 * V_34 ,
struct V_36 * V_39 )
{
F_39 ( V_34 ) ;
F_18 ( V_121 , 0 , 0 , V_34 -> V_8 ) ;
F_36 ( V_39 , V_34 , V_121 ,
& V_122 , V_39 ) ;
}
void F_58 ( struct V_3 * V_4 ,
struct V_101 * V_102 )
{
struct V_27 * V_27 = V_102 -> V_103 -> V_104 -> V_105 ;
struct V_123 * V_124 = F_45 ( V_27 ) ;
F_39 ( V_4 ) ;
F_18 ( V_125 , V_124 -> V_96 ,
V_27 -> V_126 , V_4 -> V_8 ) ;
F_36 ( F_46 ( V_27 -> V_97 ) , V_4 ,
V_125 , & V_127 ,
V_102 ) ;
V_4 -> V_82 |= V_128 ;
}
void F_59 ( struct V_3 * V_4 ,
struct V_31 * V_98 )
{
F_39 ( V_4 ) ;
F_18 ( V_32 , V_98 -> V_99 . V_129 ,
0 , V_4 -> V_8 ) ;
F_36 ( F_46 ( V_98 -> V_99 . V_100 ) , V_4 ,
V_32 , & V_130 ,
V_98 ) ;
}
void F_60 ( struct V_3 * V_4 ,
struct V_36 * V_39 , T_1 V_131 ,
unsigned int V_43 )
{
F_39 ( V_4 ) ;
F_18 ( V_132 , V_131 ,
V_43 , V_4 -> V_8 ) ;
F_36 ( V_39 , V_4 , V_132 ,
& V_133 , V_39 ) ;
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
F_44 ( V_34 -> V_134 ,
L_14 ,
V_34 -> V_8 , V_34 -> V_134 ) ;
F_44 ( V_34 -> V_135 ,
L_15 ,
V_34 -> V_8 , V_34 -> V_135 ) ;
memset ( & V_34 -> V_7 , 0 , sizeof( V_34 -> V_7 ) ) ;
V_34 -> V_82 = 0UL ;
}
static inline void F_63 ( struct V_3 * V_4 ,
int V_1 )
{
F_11 ( ! V_4 ) ;
switch( V_1 ) {
case V_136 :
V_4 -> V_135 ++ ;
break;
case V_137 :
V_4 -> V_134 ++ ;
break;
default:
F_64 () ;
}
}
static inline void F_65 ( struct V_3 * V_4 ,
int V_1 )
{
F_11 ( ! V_4 ) ;
switch( V_1 ) {
case V_136 :
F_11 ( ! V_4 -> V_135 ) ;
V_4 -> V_135 -- ;
break;
case V_137 :
F_11 ( ! V_4 -> V_134 ) ;
V_4 -> V_134 -- ;
break;
default:
F_64 () ;
}
}
static inline int F_66 ( int V_1 )
{
int V_138 = V_136 ;
if ( V_1 == V_136 )
V_138 = V_139 ;
else if ( V_1 == V_137 )
V_138 = V_137 ;
return V_138 ;
}
static void F_67 ( struct V_3 * V_4 ,
unsigned long V_140 )
{
struct V_58 * V_59 , * V_141 ;
F_68 ( & V_4 -> V_89 ) ;
V_4 -> V_82 = V_140 ;
F_69 (mw, tmp, &lockres->l_mask_waiters, mw_item) {
if ( ( V_4 -> V_82 & V_59 -> V_142 ) != V_59 -> V_143 )
continue;
F_26 ( & V_59 -> V_144 ) ;
V_59 -> V_145 = 0 ;
F_70 ( & V_59 -> V_146 ) ;
}
}
static void F_71 ( struct V_3 * V_4 , unsigned long V_147 )
{
F_67 ( V_4 , V_4 -> V_82 | V_147 ) ;
}
static void F_72 ( struct V_3 * V_4 ,
unsigned long V_148 )
{
F_67 ( V_4 , V_4 -> V_82 & ~ V_148 ) ;
}
static inline void F_73 ( struct V_3 * V_4 )
{
F_11 ( ! ( V_4 -> V_82 & V_149 ) ) ;
F_11 ( ! ( V_4 -> V_82 & V_150 ) ) ;
F_11 ( ! ( V_4 -> V_82 & V_151 ) ) ;
F_11 ( V_4 -> V_77 <= V_139 ) ;
V_4 -> V_74 = V_4 -> V_76 ;
if ( V_4 -> V_74 <=
F_66 ( V_4 -> V_77 ) ) {
V_4 -> V_77 = V_139 ;
F_72 ( V_4 , V_151 ) ;
}
F_72 ( V_4 , V_149 ) ;
}
static inline void F_74 ( struct V_3 * V_4 )
{
F_11 ( ! ( V_4 -> V_82 & V_149 ) ) ;
F_11 ( ! ( V_4 -> V_82 & V_150 ) ) ;
if ( V_4 -> V_74 == V_139 &&
V_4 -> V_37 -> V_152 & V_153 )
F_71 ( V_4 , V_154 ) ;
V_4 -> V_74 = V_4 -> V_76 ;
if ( ! ( V_4 -> V_82 & V_155 ) )
F_71 ( V_4 , V_156 ) ;
else
F_72 ( V_4 , V_155 ) ;
F_72 ( V_4 , V_149 ) ;
}
static inline void F_75 ( struct V_3 * V_4 )
{
F_11 ( ( ! ( V_4 -> V_82 & V_149 ) ) ) ;
F_11 ( V_4 -> V_82 & V_150 ) ;
if ( V_4 -> V_76 > V_139 &&
! ( V_4 -> V_82 & V_157 ) &&
V_4 -> V_37 -> V_152 & V_153 )
F_71 ( V_4 , V_154 ) ;
V_4 -> V_74 = V_4 -> V_76 ;
F_71 ( V_4 , V_150 ) ;
F_72 ( V_4 , V_149 ) ;
}
static int F_76 ( struct V_3 * V_4 ,
int V_1 )
{
int V_158 = 0 ;
F_68 ( & V_4 -> V_89 ) ;
if ( V_1 > V_4 -> V_77 ) {
if ( F_66 ( V_1 ) <
F_66 ( V_4 -> V_77 ) )
V_158 = 1 ;
V_4 -> V_77 = V_1 ;
}
F_3 ( V_159 , L_16 ,
V_4 -> V_8 , V_1 , V_4 -> V_74 , V_4 -> V_77 ,
V_158 ) ;
if ( V_158 )
F_71 ( V_4 , V_151 ) ;
F_3 ( 0 , L_17 , V_158 ) ;
return V_158 ;
}
static void F_77 ( struct V_3 * V_4 ,
unsigned int V_43 ,
struct V_36 * V_39 )
{
F_68 ( & V_4 -> V_89 ) ;
if ( ! ( V_4 -> V_82 & V_160 ) ||
( V_4 -> V_161 != V_43 ) )
return;
F_72 ( V_4 , V_160 ) ;
V_4 -> V_161 ++ ;
if ( V_4 -> V_82 & V_151 )
F_78 ( V_39 ) ;
}
static void F_79 ( struct V_3 * V_4 ,
unsigned int V_43 ,
struct V_36 * V_39 )
{
unsigned long V_152 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_77 ( V_4 , V_43 , V_39 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
}
static unsigned int F_82 ( struct V_3 * V_4 )
{
F_68 ( & V_4 -> V_89 ) ;
F_11 ( ! ( V_4 -> V_82 & V_149 ) ) ;
F_71 ( V_4 , V_160 ) ;
return V_4 -> V_161 ;
}
static void F_83 ( struct V_25 * V_26 , int V_1 )
{
struct V_3 * V_4 = F_8 ( V_26 ) ;
struct V_36 * V_39 = F_15 ( V_4 ) ;
int V_158 ;
unsigned long V_152 ;
F_11 ( V_1 <= V_139 ) ;
F_3 ( V_159 , L_18
L_19 , V_4 -> V_8 , V_1 , V_4 -> V_74 ,
F_84 ( V_4 -> V_21 ) ) ;
if ( V_4 -> V_82 & V_128 )
return;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_158 = F_76 ( V_4 , V_1 ) ;
if ( V_158 )
F_85 ( V_39 , V_4 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_86 ( & V_4 -> V_90 ) ;
F_78 ( V_39 ) ;
}
static void F_87 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_8 ( V_26 ) ;
struct V_36 * V_39 = F_15 ( V_4 ) ;
unsigned long V_152 ;
int V_162 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_162 = F_88 ( & V_4 -> V_7 ) ;
if ( V_162 == - V_163 ) {
F_72 ( V_4 , V_149 ) ;
goto V_164;
}
if ( V_162 ) {
F_3 ( V_165 , L_20 ,
V_4 -> V_8 , V_162 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
return;
}
F_3 ( V_159 , L_21
L_22 , V_4 -> V_8 , V_4 -> V_78 ,
V_4 -> V_80 , V_4 -> V_74 , V_4 -> V_76 ) ;
switch( V_4 -> V_78 ) {
case V_166 :
F_75 ( V_4 ) ;
F_72 ( V_4 , V_157 ) ;
break;
case V_167 :
F_74 ( V_4 ) ;
break;
case V_168 :
F_73 ( V_4 ) ;
break;
default:
F_3 ( V_165 , L_23
L_24 ,
V_4 -> V_8 , V_4 -> V_78 , V_4 -> V_82 ,
V_4 -> V_80 ) ;
F_64 () ;
}
V_164:
V_4 -> V_78 = V_79 ;
if ( V_4 -> V_80 == V_169 )
V_4 -> V_80 = V_81 ;
F_77 ( V_4 , V_4 -> V_161 , V_39 ) ;
F_86 ( & V_4 -> V_90 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
}
static void F_89 ( struct V_25 * V_26 , int error )
{
struct V_3 * V_4 = F_8 ( V_26 ) ;
unsigned long V_152 ;
F_3 ( V_159 , L_25 ,
V_4 -> V_8 , V_4 -> V_80 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( error ) {
F_3 ( V_165 , L_26
L_27 , error , V_4 -> V_8 ,
V_4 -> V_80 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
return;
}
switch( V_4 -> V_80 ) {
case V_169 :
F_3 ( 0 , L_28 , V_4 -> V_8 ) ;
V_4 -> V_78 = V_79 ;
if ( V_4 -> V_82 & V_151 )
F_78 ( F_15 ( V_4 ) ) ;
break;
case V_170 :
V_4 -> V_74 = V_75 ;
break;
default:
F_64 () ;
}
F_72 ( V_4 , V_149 ) ;
V_4 -> V_80 = V_81 ;
F_86 ( & V_4 -> V_90 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
}
void F_90 ( void )
{
F_91 ( & V_171 . V_172 ) ;
}
static inline void F_92 ( struct V_3 * V_4 ,
int V_173 )
{
unsigned long V_152 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_72 ( V_4 , V_149 ) ;
F_72 ( V_4 , V_156 ) ;
if ( V_173 )
V_4 -> V_78 = V_79 ;
else
V_4 -> V_80 = V_81 ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_86 ( & V_4 -> V_90 ) ;
}
static int F_93 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 ,
T_2 V_174 )
{
int V_60 = 0 ;
unsigned long V_152 ;
unsigned int V_175 ;
F_3 ( 0 , L_29 , V_4 -> V_8 , V_1 ,
V_174 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( ( V_4 -> V_82 & V_150 ) ||
( V_4 -> V_82 & V_149 ) ) {
F_81 ( & V_4 -> V_89 , V_152 ) ;
goto V_176;
}
V_4 -> V_78 = V_166 ;
V_4 -> V_76 = V_1 ;
F_71 ( V_4 , V_149 ) ;
V_175 = F_82 ( V_4 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_94 ( V_39 -> V_177 ,
V_1 ,
& V_4 -> V_7 ,
V_174 ,
V_4 -> V_8 ,
V_47 - 1 ) ;
F_79 ( V_4 , V_175 , V_39 ) ;
if ( V_60 ) {
F_95 ( L_30 , V_60 , V_4 ) ;
F_92 ( V_4 , 1 ) ;
}
F_3 ( 0 , L_31 , V_4 -> V_8 ) ;
V_176:
return V_60 ;
}
static inline int F_96 ( struct V_3 * V_4 ,
int V_178 )
{
unsigned long V_152 ;
int V_60 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_60 = V_4 -> V_82 & V_178 ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
return V_60 ;
}
static inline void F_97 ( struct V_3 * V_4 )
{
F_98 ( V_4 -> V_90 ,
! F_96 ( V_4 , V_149 ) ) ;
}
static inline void F_99 ( struct V_3 * V_4 )
{
F_98 ( V_4 -> V_90 ,
! F_96 ( V_4 , V_179 ) ) ;
}
static inline int F_100 ( struct V_3 * V_4 ,
int V_180 )
{
F_11 ( ! ( V_4 -> V_82 & V_151 ) ) ;
return V_180 <= F_66 ( V_4 -> V_77 ) ;
}
static void F_101 ( struct V_58 * V_59 )
{
F_42 ( & V_59 -> V_144 ) ;
F_102 ( & V_59 -> V_146 ) ;
F_35 ( V_59 ) ;
}
static int F_103 ( struct V_58 * V_59 )
{
F_104 ( & V_59 -> V_146 ) ;
F_105 ( & V_59 -> V_146 ) ;
return V_59 -> V_145 ;
}
static void F_106 ( struct V_3 * V_4 ,
struct V_58 * V_59 ,
unsigned long V_181 ,
unsigned long V_182 )
{
F_11 ( ! F_25 ( & V_59 -> V_144 ) ) ;
F_68 ( & V_4 -> V_89 ) ;
F_107 ( & V_59 -> V_144 , & V_4 -> V_92 ) ;
V_59 -> V_142 = V_181 ;
V_59 -> V_143 = V_182 ;
}
static int F_108 ( struct V_3 * V_4 ,
struct V_58 * V_59 )
{
int V_60 = 0 ;
F_68 ( & V_4 -> V_89 ) ;
if ( ! F_25 ( & V_59 -> V_144 ) ) {
if ( ( V_4 -> V_82 & V_59 -> V_142 ) != V_59 -> V_143 )
V_60 = - V_183 ;
F_26 ( & V_59 -> V_144 ) ;
F_102 ( & V_59 -> V_146 ) ;
}
return V_60 ;
}
static int F_109 ( struct V_3 * V_4 ,
struct V_58 * V_59 )
{
unsigned long V_152 ;
int V_60 = 0 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_108 ( V_4 , V_59 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
return V_60 ;
}
static int F_110 ( struct V_58 * V_59 ,
struct V_3 * V_4 )
{
int V_60 ;
V_60 = F_111 ( & V_59 -> V_146 ) ;
if ( V_60 )
F_109 ( V_4 , V_59 ) ;
else
V_60 = V_59 -> V_145 ;
F_105 ( & V_59 -> V_146 ) ;
return V_60 ;
}
static int F_112 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 ,
T_2 V_184 ,
int V_185 ,
int V_186 ,
unsigned long V_187 )
{
struct V_58 V_59 ;
int V_188 , V_189 = ! ( V_39 -> V_190 & V_191 ) ;
int V_60 = 0 ;
unsigned long V_152 ;
unsigned int V_175 ;
int V_192 = 0 ;
int V_193 = 0 ;
if ( ! ( V_4 -> V_82 & V_83 ) ) {
F_113 ( - V_194 ) ;
return - V_194 ;
}
F_101 ( & V_59 ) ;
if ( V_4 -> V_37 -> V_152 & V_195 )
V_184 |= V_196 ;
V_197:
V_188 = 0 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( V_189 && F_114 ( V_198 ) ) {
V_60 = - V_199 ;
goto V_200;
}
F_44 ( V_4 -> V_82 & V_201 ,
L_32
L_33 , V_4 -> V_8 , V_4 -> V_82 ) ;
if ( V_4 -> V_82 & V_149 &&
V_1 > V_4 -> V_74 ) {
F_106 ( V_4 , & V_59 , V_149 , 0 ) ;
V_188 = 1 ;
goto V_200;
}
if ( V_4 -> V_82 & V_156 ) {
if ( V_1 <= V_4 -> V_74 )
goto V_202;
}
if ( V_4 -> V_82 & V_151 &&
! F_100 ( V_4 , V_1 ) ) {
F_106 ( V_4 , & V_59 , V_151 , 0 ) ;
V_188 = 1 ;
goto V_200;
}
if ( V_1 > V_4 -> V_74 ) {
if ( V_192 > 0 ) {
V_60 = - V_163 ;
goto V_200;
}
if ( V_184 & V_203 )
V_192 = 1 ;
if ( V_4 -> V_78 != V_79 )
F_3 ( V_165 , L_34 ,
V_4 -> V_8 , V_4 -> V_78 ) ;
if ( ! ( V_4 -> V_82 & V_150 ) ) {
V_4 -> V_78 = V_166 ;
V_184 &= ~ V_204 ;
} else {
V_4 -> V_78 = V_167 ;
V_184 |= V_204 ;
}
V_4 -> V_76 = V_1 ;
F_71 ( V_4 , V_149 ) ;
V_175 = F_82 ( V_4 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_11 ( V_1 == V_75 ) ;
F_11 ( V_1 == V_139 ) ;
F_3 ( V_159 , L_35 ,
V_4 -> V_8 , V_4 -> V_74 , V_1 ) ;
V_60 = F_94 ( V_39 -> V_177 ,
V_1 ,
& V_4 -> V_7 ,
V_184 ,
V_4 -> V_8 ,
V_47 - 1 ) ;
F_79 ( V_4 , V_175 , V_39 ) ;
if ( V_60 ) {
if ( ! ( V_184 & V_203 ) ||
( V_60 != - V_163 ) ) {
F_95 ( L_30 ,
V_60 , V_4 ) ;
}
F_92 ( V_4 , 1 ) ;
goto V_164;
}
V_193 = 1 ;
F_3 ( 0 , L_36 ,
V_4 -> V_8 ) ;
V_189 = 0 ;
goto V_197;
}
V_202:
F_63 ( V_4 , V_1 ) ;
V_60 = 0 ;
V_200:
F_72 ( V_4 , V_156 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_164:
if ( V_188 && V_185 & V_205 &&
V_59 . V_142 & ( V_149 | V_151 ) ) {
V_188 = 0 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( F_108 ( V_4 , & V_59 ) ) {
if ( V_193 )
F_71 ( V_4 ,
V_155 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = - V_163 ;
} else {
F_81 ( & V_4 -> V_89 , V_152 ) ;
goto V_197;
}
}
if ( V_188 ) {
V_60 = F_103 ( & V_59 ) ;
if ( V_60 == 0 )
goto V_197;
F_113 ( V_60 ) ;
}
F_28 ( V_4 , V_1 , & V_59 , V_60 ) ;
#ifdef F_37
if ( ! V_60 && V_4 -> V_85 . V_88 != NULL ) {
if ( V_1 == V_137 )
F_115 ( & V_4 -> V_85 , V_186 ,
! ! ( V_185 & V_206 ) ,
V_187 ) ;
else
F_116 ( & V_4 -> V_85 , V_186 ,
! ! ( V_185 & V_206 ) ,
V_187 ) ;
}
#endif
return V_60 ;
}
static inline int F_117 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 ,
T_2 V_184 ,
int V_185 )
{
return F_112 ( V_39 , V_4 , V_1 , V_184 , V_185 ,
0 , V_40 ) ;
}
static void F_17 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 ,
unsigned long V_187 )
{
unsigned long V_152 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_65 ( V_4 , V_1 ) ;
F_118 ( V_39 , V_4 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
#ifdef F_37
if ( V_4 -> V_85 . V_88 != NULL )
F_119 ( & V_4 -> V_85 , 1 , V_187 ) ;
#endif
}
static int F_120 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_207 ,
int V_208 )
{
int V_1 = V_207 ? V_136 : V_137 ;
unsigned long V_152 ;
T_2 V_184 = V_208 ? V_209 : 0 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_11 ( V_4 -> V_82 & V_150 ) ;
F_71 ( V_4 , V_157 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
return F_93 ( V_39 , V_4 , V_1 , V_184 ) ;
}
int F_121 ( struct V_27 * V_27 )
{
int V_60 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_11 ( ! V_27 ) ;
F_11 ( ! F_122 ( V_27 ) ) ;
F_3 ( 0 , L_37 , ( unsigned long long ) F_45 ( V_27 ) -> V_96 ) ;
V_60 = F_120 ( V_39 , & F_45 ( V_27 ) -> V_210 , 1 , 1 ) ;
if ( V_60 ) {
F_113 ( V_60 ) ;
goto V_176;
}
V_60 = F_120 ( V_39 , & F_45 ( V_27 ) -> V_211 , 1 , 0 ) ;
if ( V_60 ) {
F_113 ( V_60 ) ;
goto V_176;
}
V_60 = F_120 ( V_39 , & F_45 ( V_27 ) -> V_212 , 0 , 0 ) ;
if ( V_60 ) {
F_113 ( V_60 ) ;
goto V_176;
}
V_176:
return V_60 ;
}
int F_123 ( struct V_27 * V_27 , int V_213 )
{
int V_162 , V_1 ;
struct V_3 * V_4 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_11 ( ! V_27 ) ;
F_3 ( 0 , L_38 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ,
V_213 ? L_39 : L_40 ) ;
if ( F_124 ( V_39 ) )
return 0 ;
V_4 = & F_45 ( V_27 ) -> V_210 ;
V_1 = V_213 ? V_136 : V_137 ;
V_162 = F_117 ( F_46 ( V_27 -> V_97 ) , V_4 , V_1 , 0 ,
0 ) ;
if ( V_162 < 0 )
F_113 ( V_162 ) ;
return V_162 ;
}
void F_125 ( struct V_27 * V_27 , int V_213 )
{
int V_1 = V_213 ? V_136 : V_137 ;
struct V_3 * V_4 = & F_45 ( V_27 ) -> V_210 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_3 ( 0 , L_41 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ,
V_213 ? L_39 : L_40 ) ;
if ( ! F_124 ( V_39 ) )
F_16 ( F_46 ( V_27 -> V_97 ) , V_4 , V_1 ) ;
}
int F_126 ( struct V_27 * V_27 )
{
int V_162 = 0 ;
struct V_3 * V_4 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_11 ( ! V_27 ) ;
F_3 ( 0 , L_42 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ) ;
if ( F_127 ( V_39 ) || F_124 ( V_39 ) )
goto V_164;
V_4 = & F_45 ( V_27 ) -> V_212 ;
V_162 = F_117 ( F_46 ( V_27 -> V_97 ) , V_4 ,
V_137 , 0 , 0 ) ;
if ( V_162 < 0 )
F_113 ( V_162 ) ;
V_164:
return V_162 ;
}
int F_128 ( struct V_27 * V_27 , int V_213 )
{
int V_162 = 0 , V_1 ;
struct V_3 * V_4 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_11 ( ! V_27 ) ;
F_3 ( 0 , L_43 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ,
V_213 ? L_39 : L_40 ) ;
if ( F_127 ( V_39 ) ) {
if ( V_213 )
V_162 = - V_214 ;
goto V_164;
}
if ( F_124 ( V_39 ) )
goto V_164;
V_4 = & F_45 ( V_27 ) -> V_212 ;
V_1 = V_213 ? V_136 : V_137 ;
V_162 = F_117 ( F_46 ( V_27 -> V_97 ) , V_4 ,
V_1 , V_203 , 0 ) ;
V_164:
return V_162 ;
}
void F_129 ( struct V_27 * V_27 )
{
struct V_3 * V_4 = & F_45 ( V_27 ) -> V_212 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_3 ( 0 , L_44 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ) ;
if ( F_124 ( V_39 ) )
goto V_164;
if( V_4 -> V_134 )
F_16 ( F_46 ( V_27 -> V_97 ) , V_4 ,
V_137 ) ;
if( V_4 -> V_135 )
F_16 ( F_46 ( V_27 -> V_97 ) , V_4 ,
V_136 ) ;
V_164:
return;
}
static int F_130 ( struct V_3 * V_4 ,
int V_1 )
{
int V_60 ;
struct V_36 * V_39 = F_15 ( V_4 ) ;
unsigned long V_152 ;
struct V_58 V_59 ;
F_101 ( & V_59 ) ;
V_215:
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( V_4 -> V_82 & V_149 ) {
V_60 = F_131 ( V_39 , V_4 ) ;
if ( V_60 ) {
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_132 ( V_39 , V_4 ) ;
if ( V_60 < 0 ) {
F_113 ( V_60 ) ;
goto V_164;
}
goto V_215;
}
F_106 ( V_4 , & V_59 , V_149 , 0 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_103 ( & V_59 ) ;
goto V_215;
}
V_60 = - V_199 ;
if ( V_4 -> V_74 == V_1 )
V_60 = 0 ;
F_3 ( 0 , L_45 , V_60 ,
V_4 -> V_82 , V_4 -> V_74 , V_4 -> V_78 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_164:
return V_60 ;
}
int F_133 ( struct V_216 * V_216 , int V_207 , int V_217 )
{
int V_60 , V_1 = V_207 ? V_136 : V_137 ;
unsigned int V_184 = V_217 ? V_203 : 0 ;
unsigned long V_152 ;
struct V_101 * V_102 = V_216 -> V_218 ;
struct V_3 * V_4 = & V_102 -> V_219 ;
struct V_36 * V_39 = F_46 ( V_216 -> V_104 -> V_105 -> V_97 ) ;
struct V_58 V_59 ;
F_101 ( & V_59 ) ;
if ( ( V_4 -> V_82 & V_149 ) ||
( V_4 -> V_74 > V_139 ) ) {
F_3 ( V_165 ,
L_46
L_47 , V_4 -> V_8 , V_4 -> V_82 ,
V_4 -> V_74 ) ;
return - V_194 ;
}
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( ! ( V_4 -> V_82 & V_150 ) ) {
F_106 ( V_4 , & V_59 , V_149 , 0 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_93 ( V_39 , V_4 , V_139 , 0 ) ;
if ( V_60 < 0 ) {
F_113 ( V_60 ) ;
goto V_164;
}
V_60 = F_103 ( & V_59 ) ;
if ( V_60 ) {
F_113 ( V_60 ) ;
goto V_164;
}
F_80 ( & V_4 -> V_89 , V_152 ) ;
}
V_4 -> V_78 = V_167 ;
V_184 |= V_204 ;
V_4 -> V_76 = V_1 ;
F_71 ( V_4 , V_149 ) ;
F_106 ( V_4 , & V_59 , V_149 , 0 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_94 ( V_39 -> V_177 , V_1 , & V_4 -> V_7 , V_184 ,
V_4 -> V_8 , V_47 - 1 ) ;
if ( V_60 ) {
if ( ! V_217 || ( V_60 != - V_163 ) ) {
F_95 ( L_30 , V_60 , V_4 ) ;
V_60 = - V_194 ;
}
F_92 ( V_4 , 1 ) ;
F_109 ( V_4 , & V_59 ) ;
goto V_164;
}
V_60 = F_110 ( & V_59 , V_4 ) ;
if ( V_60 == - V_199 ) {
V_60 = F_130 ( V_4 , V_1 ) ;
} else if ( ! V_60 && ( V_1 > V_4 -> V_74 ) ) {
F_11 ( ! V_217 ) ;
V_60 = - V_163 ;
}
V_164:
F_3 ( 0 , L_48 ,
V_4 -> V_8 , V_207 , V_217 , V_60 ) ;
return V_60 ;
}
void F_134 ( struct V_216 * V_216 )
{
int V_60 ;
unsigned int V_175 ;
unsigned long V_152 ;
struct V_101 * V_102 = V_216 -> V_218 ;
struct V_3 * V_4 = & V_102 -> V_219 ;
struct V_36 * V_39 = F_46 ( V_216 -> V_104 -> V_105 -> V_97 ) ;
struct V_58 V_59 ;
F_101 ( & V_59 ) ;
if ( ! ( V_4 -> V_82 & V_150 ) )
return;
if ( V_4 -> V_74 == V_139 )
return;
F_3 ( 0 , L_49 ,
V_4 -> V_8 , V_4 -> V_82 , V_4 -> V_74 ,
V_4 -> V_78 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_71 ( V_4 , V_151 ) ;
V_4 -> V_77 = V_136 ;
V_175 = F_135 ( V_4 , V_139 ) ;
F_106 ( V_4 , & V_59 , V_149 , 0 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_136 ( V_39 , V_4 , V_139 , 0 , V_175 ) ;
if ( V_60 ) {
F_113 ( V_60 ) ;
return;
}
V_60 = F_103 ( & V_59 ) ;
if ( V_60 )
F_113 ( V_60 ) ;
}
static void F_118 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_220 = 0 ;
if ( V_4 -> V_82 & V_151 ) {
switch( V_4 -> V_77 ) {
case V_136 :
if ( ! V_4 -> V_135 && ! V_4 -> V_134 )
V_220 = 1 ;
break;
case V_137 :
if ( ! V_4 -> V_135 )
V_220 = 1 ;
break;
default:
F_64 () ;
}
}
if ( V_220 )
F_78 ( V_39 ) ;
}
static T_1 F_137 ( struct V_221 * V_222 )
{
T_1 V_34 ;
T_1 V_223 = V_222 -> V_224 ;
T_2 V_225 = V_222 -> V_226 ;
V_34 = ( V_223 << V_227 ) | ( V_225 & V_228 ) ;
return V_34 ;
}
static void F_138 ( struct V_27 * V_27 )
{
struct V_123 * V_124 = F_45 ( V_27 ) ;
struct V_3 * V_4 = & V_124 -> V_211 ;
struct V_5 * V_6 ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
if ( V_124 -> V_229 & V_230 ) {
V_6 -> V_9 = 0 ;
goto V_164;
}
V_6 -> V_9 = V_231 ;
V_6 -> V_12 = F_53 ( F_139 ( V_27 ) ) ;
V_6 -> V_10 = F_140 ( V_124 -> V_232 ) ;
V_6 -> V_13 = F_140 ( F_141 ( V_27 ) ) ;
V_6 -> V_14 = F_140 ( F_142 ( V_27 ) ) ;
V_6 -> V_15 = F_143 ( V_27 -> V_233 ) ;
V_6 -> V_16 = F_143 ( V_27 -> V_234 ) ;
V_6 -> V_17 =
F_53 ( F_137 ( & V_27 -> V_235 ) ) ;
V_6 -> V_18 =
F_53 ( F_137 ( & V_27 -> V_236 ) ) ;
V_6 -> V_19 =
F_53 ( F_137 ( & V_27 -> V_237 ) ) ;
V_6 -> V_20 = F_140 ( V_124 -> V_238 ) ;
V_6 -> V_239 = F_143 ( V_124 -> V_240 ) ;
V_6 -> V_11 = F_140 ( V_27 -> V_126 ) ;
V_164:
F_144 ( 0 , V_4 ) ;
}
static void F_145 ( struct V_221 * V_222 ,
T_1 V_241 )
{
V_222 -> V_224 = V_241 >> V_227 ;
V_222 -> V_226 = V_241 & V_228 ;
}
static void F_146 ( struct V_27 * V_27 )
{
struct V_123 * V_124 = F_45 ( V_27 ) ;
struct V_3 * V_4 = & V_124 -> V_211 ;
struct V_5 * V_6 ;
F_144 ( 0 , V_4 ) ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
F_21 ( & V_124 -> V_242 ) ;
V_124 -> V_232 = F_4 ( V_6 -> V_10 ) ;
F_147 ( V_27 , F_5 ( V_6 -> V_12 ) ) ;
V_124 -> V_238 = F_4 ( V_6 -> V_20 ) ;
V_124 -> V_240 = F_6 ( V_6 -> V_239 ) ;
F_148 ( V_27 ) ;
if ( F_149 ( V_27 -> V_233 ) && ! V_124 -> V_232 )
V_27 -> V_243 = 0 ;
else
V_27 -> V_243 = F_150 ( V_27 ) ;
F_151 ( V_27 , F_4 ( V_6 -> V_13 ) ) ;
F_152 ( V_27 , F_4 ( V_6 -> V_14 ) ) ;
V_27 -> V_233 = F_6 ( V_6 -> V_15 ) ;
F_153 ( V_27 , F_6 ( V_6 -> V_16 ) ) ;
F_145 ( & V_27 -> V_235 ,
F_5 ( V_6 -> V_17 ) ) ;
F_145 ( & V_27 -> V_237 ,
F_5 ( V_6 -> V_19 ) ) ;
F_145 ( & V_27 -> V_236 ,
F_5 ( V_6 -> V_18 ) ) ;
F_23 ( & V_124 -> V_242 ) ;
}
static inline int F_154 ( struct V_27 * V_27 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_4 -> V_7 ) ;
if ( F_155 ( & V_4 -> V_7 )
&& V_6 -> V_9 == V_231
&& F_4 ( V_6 -> V_11 ) == V_27 -> V_126 )
return 1 ;
return 0 ;
}
static int F_156 ( struct V_3 * V_4 )
{
unsigned long V_152 ;
int V_162 = 0 ;
V_244:
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( ! ( V_4 -> V_82 & V_154 ) ) {
F_81 ( & V_4 -> V_89 , V_152 ) ;
goto V_176;
}
if ( V_4 -> V_82 & V_179 ) {
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_99 ( V_4 ) ;
goto V_244;
}
F_71 ( V_4 , V_179 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_162 = 1 ;
V_176:
F_3 ( 0 , L_50 , V_162 ) ;
return V_162 ;
}
static inline void F_157 ( struct V_3 * V_4 ,
int V_162 )
{
unsigned long V_152 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_72 ( V_4 , V_179 ) ;
if ( ! V_162 )
F_72 ( V_4 , V_154 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_86 ( & V_4 -> V_90 ) ;
}
static int F_158 ( struct V_27 * V_27 ,
struct V_245 * * V_246 )
{
int V_162 = 0 ;
struct V_123 * V_124 = F_45 ( V_27 ) ;
struct V_3 * V_4 = & V_124 -> V_211 ;
struct V_247 * V_248 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
if ( F_124 ( V_39 ) )
goto V_176;
F_21 ( & V_124 -> V_242 ) ;
if ( V_124 -> V_229 & V_230 ) {
F_3 ( 0 , L_51
L_52 ,
( unsigned long long ) V_124 -> V_96 , V_124 -> V_229 ) ;
F_23 ( & V_124 -> V_242 ) ;
V_162 = - V_249 ;
goto V_176;
}
F_23 ( & V_124 -> V_242 ) ;
if ( ! F_156 ( V_4 ) )
goto V_176;
F_159 ( F_160 ( V_27 ) ) ;
F_161 ( V_27 , 0 ) ;
if ( F_154 ( V_27 , V_4 ) ) {
F_3 ( 0 , L_53 ,
( unsigned long long ) V_124 -> V_96 ) ;
F_146 ( V_27 ) ;
} else {
V_162 = F_162 ( V_27 , V_246 ) ;
if ( V_162 < 0 ) {
F_113 ( V_162 ) ;
goto V_250;
}
V_248 = (struct V_247 * ) ( * V_246 ) -> V_251 ;
F_44 ( V_27 -> V_126 !=
F_163 ( V_248 -> V_126 ) ,
L_54
L_55 ,
( unsigned long long ) V_124 -> V_96 ,
F_163 ( V_248 -> V_126 ) ,
V_27 -> V_126 ) ;
F_44 ( F_164 ( V_248 -> V_252 ) ||
! ( V_248 -> V_253 & F_165 ( V_254 ) ) ,
L_56 ,
( unsigned long long ) V_124 -> V_96 ,
( unsigned long long ) F_164 ( V_248 -> V_252 ) ,
F_163 ( V_248 -> V_253 ) ) ;
F_166 ( V_27 , V_248 ) ;
F_34 ( V_4 ) ;
}
V_162 = 0 ;
V_250:
F_157 ( V_4 , V_162 ) ;
V_176:
return V_162 ;
}
static int F_167 ( struct V_27 * V_27 ,
struct V_245 * * V_255 ,
struct V_245 * V_256 )
{
int V_162 ;
if ( V_256 ) {
* V_255 = V_256 ;
F_168 ( * V_255 ) ;
return 0 ;
}
V_162 = F_162 ( V_27 , V_255 ) ;
if ( V_162 < 0 )
F_113 ( V_162 ) ;
return V_162 ;
}
int F_169 ( struct V_27 * V_27 ,
struct V_245 * * V_255 ,
int V_207 ,
int V_185 ,
int V_257 )
{
int V_162 , V_1 , V_258 ;
T_2 V_174 ;
struct V_3 * V_4 = NULL ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
struct V_245 * V_259 = NULL ;
F_11 ( ! V_27 ) ;
F_3 ( 0 , L_57 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ,
V_207 ? L_39 : L_40 ) ;
V_162 = 0 ;
V_258 = 0 ;
if ( F_127 ( V_39 ) ) {
if ( V_207 )
V_162 = - V_214 ;
goto V_260;
}
if ( F_124 ( V_39 ) )
goto V_208;
if ( ! ( V_185 & V_261 ) )
F_170 ( V_39 ) ;
V_4 = & F_45 ( V_27 ) -> V_211 ;
V_1 = V_207 ? V_136 : V_137 ;
V_174 = 0 ;
if ( V_185 & V_206 )
V_174 |= V_203 ;
V_162 = F_112 ( V_39 , V_4 , V_1 , V_174 ,
V_185 , V_257 , V_40 ) ;
if ( V_162 < 0 ) {
if ( V_162 != - V_163 )
F_113 ( V_162 ) ;
goto V_176;
}
V_258 = 1 ;
if ( ! ( V_185 & V_261 ) )
F_170 ( V_39 ) ;
V_208:
if ( V_27 -> V_262 & V_263 ) {
V_162 = 0 ;
if ( V_4 )
F_157 ( V_4 , 0 ) ;
goto V_176;
}
V_162 = F_158 ( V_27 , & V_259 ) ;
if ( V_162 < 0 ) {
if ( V_162 != - V_249 )
F_113 ( V_162 ) ;
goto V_176;
}
V_260:
if ( V_255 ) {
V_162 = F_167 ( V_27 , V_255 , V_259 ) ;
if ( V_162 < 0 ) {
F_113 ( V_162 ) ;
goto V_176;
}
}
V_176:
if ( V_162 < 0 ) {
if ( V_255 && ( * V_255 ) ) {
F_171 ( * V_255 ) ;
* V_255 = NULL ;
}
if ( V_258 )
F_172 ( V_27 , V_207 ) ;
}
if ( V_259 )
F_171 ( V_259 ) ;
return V_162 ;
}
int F_173 ( struct V_27 * V_27 ,
struct V_245 * * V_255 ,
int V_207 ,
struct V_264 * V_264 )
{
int V_60 ;
V_60 = F_174 ( V_27 , V_255 , V_207 , V_205 ) ;
if ( V_60 == - V_163 ) {
F_175 ( V_264 ) ;
if ( F_176 ( V_27 , V_255 , V_207 ) == 0 )
F_172 ( V_27 , V_207 ) ;
V_60 = V_265 ;
}
return V_60 ;
}
int F_177 ( struct V_27 * V_27 ,
struct V_266 * V_267 ,
int * V_1 )
{
int V_60 ;
V_60 = F_176 ( V_27 , NULL , 0 ) ;
if ( V_60 < 0 ) {
F_113 ( V_60 ) ;
return V_60 ;
}
if ( F_178 ( V_27 , V_267 ) ) {
struct V_245 * V_246 = NULL ;
F_172 ( V_27 , 0 ) ;
V_60 = F_176 ( V_27 , & V_246 , 1 ) ;
if ( V_60 < 0 ) {
F_113 ( V_60 ) ;
return V_60 ;
}
* V_1 = 1 ;
if ( F_178 ( V_27 , V_267 ) )
F_179 ( V_27 , V_246 ) ;
if ( V_246 )
F_171 ( V_246 ) ;
} else
* V_1 = 0 ;
return V_60 ;
}
void F_172 ( struct V_27 * V_27 ,
int V_207 )
{
int V_1 = V_207 ? V_136 : V_137 ;
struct V_3 * V_4 = & F_45 ( V_27 ) -> V_211 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_3 ( 0 , L_58 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ,
V_207 ? L_39 : L_40 ) ;
if ( ! F_127 ( F_46 ( V_27 -> V_97 ) ) &&
! F_124 ( V_39 ) )
F_16 ( F_46 ( V_27 -> V_97 ) , V_4 , V_1 ) ;
}
int F_180 ( struct V_36 * V_39 , T_2 * V_268 )
{
struct V_3 * V_4 ;
struct V_269 * V_6 ;
int V_162 = 0 ;
if ( F_127 ( V_39 ) )
return - V_214 ;
if ( F_124 ( V_39 ) )
return 0 ;
V_4 = & V_39 -> V_270 . V_271 ;
V_162 = F_117 ( V_39 , V_4 , V_136 , 0 , 0 ) ;
if ( V_162 < 0 )
return V_162 ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
if ( F_155 ( & V_4 -> V_7 ) &&
V_6 -> V_9 == V_272 )
* V_268 = F_4 ( V_6 -> V_273 ) ;
else
* V_268 = V_39 -> V_270 . V_274 + 1 ;
return V_162 ;
}
void F_181 ( struct V_36 * V_39 , T_2 V_268 )
{
struct V_3 * V_4 ;
struct V_269 * V_6 ;
if ( ! F_127 ( V_39 ) && ! F_124 ( V_39 ) ) {
V_4 = & V_39 -> V_270 . V_271 ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
V_6 -> V_9 = V_272 ;
V_6 -> V_273 = F_140 ( V_268 ) ;
F_16 ( V_39 , V_4 , V_136 ) ;
}
}
int F_182 ( struct V_36 * V_39 ,
int V_207 )
{
int V_162 = 0 ;
int V_1 = V_207 ? V_136 : V_137 ;
struct V_3 * V_4 = & V_39 -> V_275 ;
if ( F_127 ( V_39 ) )
return - V_214 ;
if ( F_124 ( V_39 ) )
goto V_176;
V_162 = F_117 ( V_39 , V_4 , V_1 , 0 , 0 ) ;
if ( V_162 < 0 ) {
F_113 ( V_162 ) ;
goto V_176;
}
V_162 = F_156 ( V_4 ) ;
if ( V_162 ) {
V_162 = F_183 ( V_39 ) ;
F_157 ( V_4 , V_162 ) ;
if ( V_162 < 0 ) {
F_16 ( V_39 , V_4 , V_1 ) ;
F_113 ( V_162 ) ;
}
F_34 ( V_4 ) ;
}
V_176:
return V_162 ;
}
void F_184 ( struct V_36 * V_39 ,
int V_207 )
{
int V_1 = V_207 ? V_136 : V_137 ;
struct V_3 * V_4 = & V_39 -> V_275 ;
if ( ! F_124 ( V_39 ) )
F_16 ( V_39 , V_4 , V_1 ) ;
}
int F_185 ( struct V_36 * V_39 )
{
int V_162 ;
struct V_3 * V_4 = & V_39 -> V_276 ;
if ( F_127 ( V_39 ) )
return - V_214 ;
if ( F_124 ( V_39 ) )
return 0 ;
V_162 = F_117 ( V_39 , V_4 , V_136 , 0 , 0 ) ;
if ( V_162 < 0 )
F_113 ( V_162 ) ;
return V_162 ;
}
void F_186 ( struct V_36 * V_39 )
{
struct V_3 * V_4 = & V_39 -> V_276 ;
if ( ! F_124 ( V_39 ) )
F_16 ( V_39 , V_4 , V_136 ) ;
}
int F_187 ( struct V_36 * V_39 , int V_207 )
{
int V_162 ;
struct V_3 * V_4 = & V_39 -> V_277 ;
if ( F_127 ( V_39 ) )
return - V_214 ;
if ( F_124 ( V_39 ) )
return 0 ;
V_162 = F_117 ( V_39 , V_4 , V_207 ? V_65 : V_64 ,
0 , 0 ) ;
if ( V_162 < 0 )
F_3 ( V_165 , L_59 , V_162 ) ;
return V_162 ;
}
void F_188 ( struct V_36 * V_39 , int V_207 )
{
struct V_3 * V_4 = & V_39 -> V_277 ;
if ( ! F_124 ( V_39 ) )
F_16 ( V_39 , V_4 ,
V_207 ? V_65 : V_64 ) ;
}
int V_29 ( struct V_278 * V_278 , int V_207 )
{
int V_60 ;
int V_1 = V_207 ? V_136 : V_137 ;
struct V_29 * V_108 = V_278 -> V_279 ;
struct V_36 * V_39 = F_46 ( V_278 -> V_280 ) ;
F_11 ( ! V_108 ) ;
if ( F_127 ( V_39 ) ) {
if ( V_207 )
return - V_214 ;
return 0 ;
}
if ( F_124 ( V_39 ) )
return 0 ;
V_60 = F_117 ( V_39 , & V_108 -> V_112 , V_1 , 0 , 0 ) ;
if ( V_60 < 0 )
F_113 ( V_60 ) ;
return V_60 ;
}
void F_189 ( struct V_278 * V_278 , int V_207 )
{
int V_1 = V_207 ? V_136 : V_137 ;
struct V_29 * V_108 = V_278 -> V_279 ;
struct V_36 * V_39 = F_46 ( V_278 -> V_280 ) ;
if ( ! F_127 ( V_39 ) && ! F_124 ( V_39 ) )
F_16 ( V_39 , & V_108 -> V_112 , V_1 ) ;
}
static void F_190 ( struct V_281 * V_281 )
{
struct V_49 * V_50 ;
V_50 = F_9 ( V_281 , struct V_49 , V_282 ) ;
F_191 ( V_50 ) ;
}
void F_192 ( struct V_49 * V_50 )
{
if ( V_50 )
F_193 ( & V_50 -> V_282 , F_190 ) ;
}
static void F_194 ( struct V_49 * V_283 )
{
F_195 ( & V_283 -> V_282 ) ;
}
struct V_49 * F_196 ( void )
{
struct V_49 * V_50 ;
V_50 = F_197 ( sizeof( struct V_49 ) , V_284 ) ;
if ( ! V_50 ) {
F_113 ( - V_285 ) ;
goto V_164;
}
F_198 ( & V_50 -> V_282 ) ;
F_42 ( & V_50 -> V_53 ) ;
V_50 -> V_286 = NULL ;
V_164:
return V_50 ;
}
static struct V_3 * F_199 ( struct V_3 * V_287 ,
struct V_288 * V_73 )
{
struct V_3 * V_289 , * V_60 = NULL ;
struct V_49 * V_50 = V_73 -> V_290 ;
F_68 ( & V_51 ) ;
F_200 (iter, &start->l_debug_list, l_debug_list) {
if ( & V_289 -> V_52 == & V_50 -> V_53 ) {
F_3 ( 0 , L_60 , V_60 ) ;
break;
}
if ( V_289 -> V_37 != NULL ) {
V_60 = V_289 ;
break;
}
}
return V_60 ;
}
static void * F_201 ( struct V_291 * V_292 , T_6 * V_293 )
{
struct V_288 * V_73 = V_292 -> V_294 ;
struct V_3 * V_289 ;
F_21 ( & V_51 ) ;
V_289 = F_199 ( & V_73 -> V_295 , V_73 ) ;
if ( V_289 ) {
V_73 -> V_296 = * V_289 ;
V_289 = & V_73 -> V_296 ;
}
F_23 ( & V_51 ) ;
return V_289 ;
}
static void F_202 ( struct V_291 * V_292 , void * V_297 )
{
}
static void * F_203 ( struct V_291 * V_292 , void * V_297 , T_6 * V_293 )
{
struct V_288 * V_73 = V_292 -> V_294 ;
struct V_3 * V_289 = V_297 ;
struct V_3 * V_298 = & V_73 -> V_295 ;
F_21 ( & V_51 ) ;
V_289 = F_199 ( V_289 , V_73 ) ;
F_26 ( & V_298 -> V_52 ) ;
if ( V_289 ) {
F_22 ( & V_298 -> V_52 , & V_289 -> V_52 ) ;
V_73 -> V_296 = * V_289 ;
V_289 = & V_73 -> V_296 ;
}
F_23 ( & V_51 ) ;
return V_289 ;
}
static int F_204 ( struct V_291 * V_292 , void * V_297 )
{
int V_299 ;
char * V_6 ;
struct V_3 * V_4 = V_297 ;
if ( ! V_4 )
return - V_194 ;
F_205 ( V_292 , L_61 , V_300 ) ;
if ( V_4 -> V_21 == V_30 )
F_205 ( V_292 , L_62 , V_107 - 1 ,
V_4 -> V_8 ,
( unsigned int ) F_50 ( V_4 ) ) ;
else
F_205 ( V_292 , L_63 , V_47 , V_4 -> V_8 ) ;
F_205 ( V_292 , L_64
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
V_4 -> V_134 ,
V_4 -> V_135 ,
V_4 -> V_76 ,
V_4 -> V_77 ) ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
for( V_299 = 0 ; V_299 < V_301 ; V_299 ++ )
F_205 ( V_292 , L_61 , V_6 [ V_299 ] ) ;
#ifdef F_206
# define F_207 ( T_7 ) ((_l)->l_lock_prmode.ls_gets)
# define F_208 ( T_7 ) ((_l)->l_lock_exmode.ls_gets)
# define F_209 ( T_7 ) ((_l)->l_lock_prmode.ls_fail)
# define F_210 ( T_7 ) ((_l)->l_lock_exmode.ls_fail)
# define F_211 ( T_7 ) ((_l)->l_lock_prmode.ls_total)
# define F_212 ( T_7 ) ((_l)->l_lock_exmode.ls_total)
# define F_213 ( T_7 ) ((_l)->l_lock_prmode.ls_max)
# define F_214 ( T_7 ) ((_l)->l_lock_exmode.ls_max)
# define F_215 ( T_7 ) ((_l)->l_lock_refresh)
#else
# define F_207 ( T_7 ) (0)
# define F_208 ( T_7 ) (0)
# define F_209 ( T_7 ) (0)
# define F_210 ( T_7 ) (0)
# define F_211 ( T_7 ) (0ULL)
# define F_212 ( T_7 ) (0ULL)
# define F_213 ( T_7 ) (0)
# define F_214 ( T_7 ) (0)
# define F_215 ( T_7 ) (0)
#endif
F_205 ( V_292 , L_66
L_66
L_66
L_66
L_67
L_67
L_66
L_66
L_66 ,
F_207 ( V_4 ) ,
F_208 ( V_4 ) ,
F_209 ( V_4 ) ,
F_210 ( V_4 ) ,
F_211 ( V_4 ) ,
F_212 ( V_4 ) ,
F_213 ( V_4 ) ,
F_214 ( V_4 ) ,
F_215 ( V_4 ) ) ;
F_205 ( V_292 , L_68 ) ;
return 0 ;
}
static int F_216 ( struct V_27 * V_27 , struct V_216 * V_216 )
{
struct V_291 * V_302 = V_216 -> V_218 ;
struct V_288 * V_73 = V_302 -> V_294 ;
struct V_3 * V_34 = & V_73 -> V_295 ;
F_24 ( V_34 ) ;
F_192 ( V_73 -> V_290 ) ;
return F_217 ( V_27 , V_216 ) ;
}
static int F_218 ( struct V_27 * V_27 , struct V_216 * V_216 )
{
struct V_288 * V_73 ;
struct V_36 * V_39 ;
V_73 = F_219 ( V_216 , & V_303 , sizeof( * V_73 ) ) ;
if ( ! V_73 ) {
F_113 ( - V_285 ) ;
return - V_285 ;
}
V_39 = V_27 -> V_304 ;
F_194 ( V_39 -> V_84 ) ;
V_73 -> V_290 = V_39 -> V_84 ;
F_42 ( & V_73 -> V_295 . V_52 ) ;
F_20 ( & V_73 -> V_295 ,
V_73 -> V_290 ) ;
return 0 ;
}
static int F_220 ( struct V_36 * V_39 )
{
int V_60 = 0 ;
struct V_49 * V_50 = V_39 -> V_84 ;
V_50 -> V_286 = F_221 ( L_69 ,
V_305 | V_306 ,
V_39 -> V_307 ,
V_39 ,
& V_308 ) ;
if ( ! V_50 -> V_286 ) {
V_60 = - V_194 ;
F_3 ( V_165 ,
L_70 ) ;
goto V_164;
}
F_194 ( V_50 ) ;
V_164:
return V_60 ;
}
static void F_222 ( struct V_36 * V_39 )
{
struct V_49 * V_50 = V_39 -> V_84 ;
if ( V_50 ) {
F_223 ( V_50 -> V_286 ) ;
F_192 ( V_50 ) ;
}
}
int F_224 ( struct V_36 * V_39 )
{
int V_162 = 0 ;
struct V_309 * V_310 = NULL ;
if ( F_124 ( V_39 ) ) {
V_39 -> V_311 = 0 ;
goto V_208;
}
V_162 = F_220 ( V_39 ) ;
if ( V_162 < 0 ) {
F_113 ( V_162 ) ;
goto V_176;
}
V_39 -> V_312 = F_225 ( V_313 , V_39 , L_71 ,
V_39 -> V_314 ) ;
if ( F_226 ( V_39 -> V_312 ) ) {
V_162 = F_227 ( V_39 -> V_312 ) ;
V_39 -> V_312 = NULL ;
F_113 ( V_162 ) ;
goto V_176;
}
V_162 = F_228 ( V_39 -> V_315 ,
V_39 -> V_316 ,
strlen ( V_39 -> V_316 ) ,
V_39 -> V_314 ,
strlen ( V_39 -> V_314 ) ,
& V_171 , V_317 , V_39 ,
& V_310 ) ;
if ( V_162 ) {
F_113 ( V_162 ) ;
goto V_176;
}
V_162 = F_229 ( V_310 , & V_39 -> V_311 ) ;
if ( V_162 < 0 ) {
F_113 ( V_162 ) ;
F_3 ( V_165 ,
L_72 ) ;
F_230 ( V_310 , 0 ) ;
goto V_176;
}
V_208:
F_54 ( & V_39 -> V_275 , V_39 ) ;
F_55 ( & V_39 -> V_276 , V_39 ) ;
F_56 ( & V_39 -> V_277 , V_39 ) ;
F_57 ( & V_39 -> V_270 . V_271 , V_39 ) ;
V_39 -> V_177 = V_310 ;
V_176:
if ( V_162 < 0 ) {
F_222 ( V_39 ) ;
if ( V_39 -> V_312 )
F_231 ( V_39 -> V_312 ) ;
}
return V_162 ;
}
void F_232 ( struct V_36 * V_39 ,
int V_318 )
{
F_233 ( V_39 ) ;
if ( V_39 -> V_312 ) {
F_231 ( V_39 -> V_312 ) ;
V_39 -> V_312 = NULL ;
}
F_61 ( & V_39 -> V_275 ) ;
F_61 ( & V_39 -> V_276 ) ;
F_61 ( & V_39 -> V_277 ) ;
F_61 ( & V_39 -> V_270 . V_271 ) ;
F_230 ( V_39 -> V_177 , V_318 ) ;
V_39 -> V_177 = NULL ;
F_222 ( V_39 ) ;
}
static int F_234 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_60 ;
unsigned long V_152 ;
T_2 V_184 = 0 ;
if ( ! ( V_4 -> V_82 & V_83 ) )
goto V_164;
if ( V_4 -> V_37 -> V_152 & V_195 )
V_184 |= V_196 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_44 ( ! ( V_4 -> V_82 & V_201 ) ,
L_73 ,
V_4 -> V_8 , V_4 -> V_82 ) ;
while ( V_4 -> V_82 & V_149 ) {
F_3 ( 0 , L_74
L_75 ,
V_4 -> V_8 , V_4 -> V_82 , V_4 -> V_78 ,
V_4 -> V_80 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_97 ( V_4 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
}
if ( V_4 -> V_37 -> V_152 & V_195 ) {
if ( V_4 -> V_82 & V_150 &&
V_4 -> V_74 == V_136 &&
! ( V_4 -> V_82 & V_154 ) )
V_4 -> V_37 -> V_319 ( V_4 ) ;
}
if ( V_4 -> V_82 & V_149 )
F_3 ( V_165 , L_76 ,
V_4 -> V_8 ) ;
if ( V_4 -> V_82 & V_151 )
F_3 ( 0 , L_77 , V_4 -> V_8 ) ;
if ( ! ( V_4 -> V_82 & V_150 ) ) {
F_81 ( & V_4 -> V_89 , V_152 ) ;
goto V_164;
}
F_72 ( V_4 , V_150 ) ;
F_11 ( V_4 -> V_78 != V_79 ) ;
F_71 ( V_4 , V_149 ) ;
V_4 -> V_80 = V_170 ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_3 ( 0 , L_78 , V_4 -> V_8 ) ;
V_60 = F_235 ( V_39 -> V_177 , & V_4 -> V_7 , V_184 ) ;
if ( V_60 ) {
F_95 ( L_79 , V_60 , V_4 ) ;
F_3 ( V_165 , L_80 , V_4 -> V_82 ) ;
F_236 ( & V_4 -> V_7 ) ;
F_64 () ;
}
F_3 ( 0 , L_81 ,
V_4 -> V_8 ) ;
F_97 ( V_4 ) ;
V_164:
return 0 ;
}
void F_237 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_162 ;
struct V_58 V_59 ;
unsigned long V_152 , V_320 ;
F_101 ( & V_59 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_4 -> V_82 |= V_201 ;
if ( V_4 -> V_82 & V_321 && V_198 == V_39 -> V_312 ) {
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_80 ( & V_39 -> V_322 , V_320 ) ;
F_26 ( & V_4 -> V_91 ) ;
V_39 -> V_323 -- ;
F_81 ( & V_39 -> V_322 , V_320 ) ;
F_238 ( V_4 -> V_37 -> V_324 ) ;
F_239 ( V_39 , V_4 ) ;
return;
}
while ( V_4 -> V_82 & V_321 ) {
F_106 ( V_4 , & V_59 , V_321 , 0 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_3 ( 0 , L_82 , V_4 -> V_8 ) ;
V_162 = F_103 ( & V_59 ) ;
if ( V_162 )
F_113 ( V_162 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
}
F_81 ( & V_4 -> V_89 , V_152 ) ;
}
void F_240 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_60 ;
F_237 ( V_39 , V_4 ) ;
V_60 = F_234 ( V_39 , V_4 ) ;
if ( V_60 )
F_113 ( V_60 ) ;
}
static void F_233 ( struct V_36 * V_39 )
{
F_240 ( V_39 , & V_39 -> V_275 ) ;
F_240 ( V_39 , & V_39 -> V_276 ) ;
F_240 ( V_39 , & V_39 -> V_277 ) ;
F_240 ( V_39 , & V_39 -> V_270 . V_271 ) ;
}
int F_241 ( struct V_27 * V_27 )
{
int V_162 , V_325 ;
V_325 = F_234 ( F_46 ( V_27 -> V_97 ) ,
& F_45 ( V_27 ) -> V_212 ) ;
if ( V_325 < 0 )
F_113 ( V_325 ) ;
V_162 = V_325 ;
V_325 = F_234 ( F_46 ( V_27 -> V_97 ) ,
& F_45 ( V_27 ) -> V_211 ) ;
if ( V_325 < 0 )
F_113 ( V_325 ) ;
if ( V_325 < 0 && ! V_162 )
V_162 = V_325 ;
V_325 = F_234 ( F_46 ( V_27 -> V_97 ) ,
& F_45 ( V_27 ) -> V_210 ) ;
if ( V_325 < 0 )
F_113 ( V_325 ) ;
if ( V_325 < 0 && ! V_162 )
V_162 = V_325 ;
return V_162 ;
}
static unsigned int F_135 ( struct V_3 * V_4 ,
int V_138 )
{
F_68 ( & V_4 -> V_89 ) ;
F_11 ( V_4 -> V_77 <= V_139 ) ;
if ( V_4 -> V_74 <= V_138 ) {
F_3 ( V_165 , L_83
L_84
L_85 , V_4 -> V_8 , V_4 -> V_74 ,
V_138 , F_25 ( & V_4 -> V_91 ) ,
F_25 ( & V_4 -> V_92 ) , V_4 -> V_21 ,
V_4 -> V_82 , V_4 -> V_134 ,
V_4 -> V_135 , V_4 -> V_78 ,
V_4 -> V_80 , V_4 -> V_76 ,
V_4 -> V_77 , V_4 -> V_161 ) ;
F_64 () ;
}
F_3 ( V_159 , L_86 ,
V_4 -> V_8 , V_4 -> V_74 , V_138 , V_4 -> V_77 ) ;
V_4 -> V_78 = V_168 ;
V_4 -> V_76 = V_138 ;
F_71 ( V_4 , V_149 ) ;
return F_82 ( V_4 ) ;
}
static int F_136 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_138 ,
int V_6 ,
unsigned int V_43 )
{
int V_60 ;
T_2 V_174 = V_204 ;
F_3 ( V_159 , L_87 , V_4 -> V_8 ,
V_4 -> V_74 , V_138 ) ;
if ( V_6 )
V_174 |= V_196 ;
V_60 = F_94 ( V_39 -> V_177 ,
V_138 ,
& V_4 -> V_7 ,
V_174 ,
V_4 -> V_8 ,
V_47 - 1 ) ;
F_79 ( V_4 , V_43 , V_39 ) ;
if ( V_60 ) {
F_95 ( L_30 , V_60 , V_4 ) ;
F_92 ( V_4 , 1 ) ;
goto V_176;
}
V_60 = 0 ;
V_176:
return V_60 ;
}
static int F_131 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
F_68 ( & V_4 -> V_89 ) ;
if ( V_4 -> V_80 == V_169 ) {
F_3 ( V_159 , L_88 , V_4 -> V_8 ) ;
return 0 ;
}
F_11 ( V_4 -> V_78 != V_167 &&
V_4 -> V_78 != V_168 ) ;
V_4 -> V_80 = V_169 ;
F_44 ( ! ( V_4 -> V_82 & V_149 ) ,
L_89 ,
V_4 -> V_8 , V_4 -> V_82 ) ;
F_3 ( V_159 , L_90 , V_4 -> V_8 ) ;
return 1 ;
}
static int F_132 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_60 ;
V_60 = F_235 ( V_39 -> V_177 , & V_4 -> V_7 ,
V_326 ) ;
if ( V_60 ) {
F_95 ( L_79 , V_60 , V_4 ) ;
F_92 ( V_4 , 0 ) ;
}
F_3 ( V_159 , L_90 , V_4 -> V_8 ) ;
return V_60 ;
}
static int F_242 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
struct V_327 * V_328 )
{
unsigned long V_152 ;
int V_329 ;
int V_138 ;
int V_1 ;
int V_60 = 0 ;
int V_319 = 0 ;
unsigned int V_175 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_330:
if ( ! ( V_4 -> V_82 & V_151 ) ) {
F_11 ( V_4 -> V_77 != V_139 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = 0 ;
goto V_331;
}
if ( V_4 -> V_82 & V_149 ) {
if ( V_4 -> V_82 & V_160 ) {
F_3 ( V_159 , L_91 ,
V_4 -> V_8 ) ;
goto V_332;
}
V_328 -> V_333 = 1 ;
V_60 = F_131 ( V_39 , V_4 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
if ( V_60 ) {
V_60 = F_132 ( V_39 , V_4 ) ;
if ( V_60 < 0 )
F_113 ( V_60 ) ;
}
goto V_331;
}
if ( V_4 -> V_82 & V_156 )
goto V_332;
if ( V_4 -> V_74 == V_139 ) {
F_11 ( V_4 -> V_135 || V_4 -> V_134 ) ;
F_3 ( V_159 , L_92 , V_4 -> V_8 ) ;
V_4 -> V_77 = V_139 ;
F_72 ( V_4 , V_151 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
goto V_331;
}
if ( ( V_4 -> V_77 == V_136 )
&& ( V_4 -> V_135 || V_4 -> V_134 ) ) {
F_3 ( V_159 , L_93 ,
V_4 -> V_8 , V_4 -> V_135 ,
V_4 -> V_134 ) ;
goto V_332;
}
if ( V_4 -> V_77 == V_137 &&
V_4 -> V_135 ) {
F_3 ( V_159 , L_94 ,
V_4 -> V_8 , V_4 -> V_135 ) ;
goto V_332;
}
if ( ( V_4 -> V_37 -> V_152 & V_153 )
&& ( V_4 -> V_82 & V_179 ) ) {
F_3 ( V_159 , L_95 ,
V_4 -> V_8 ) ;
goto V_332;
}
V_138 = F_66 ( V_4 -> V_77 ) ;
if ( V_4 -> V_37 -> V_334
&& ! V_4 -> V_37 -> V_334 ( V_4 , V_138 ) ) {
F_3 ( V_159 , L_96 ,
V_4 -> V_8 ) ;
goto V_332;
}
if ( ! V_4 -> V_37 -> V_335 )
goto V_336;
V_329 = V_4 -> V_77 ;
V_1 = V_4 -> V_74 ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_328 -> V_337 = V_4 -> V_37 -> V_335 ( V_4 , V_329 ) ;
if ( V_328 -> V_337 == V_338 ) {
F_3 ( V_159 , L_97 ,
V_4 -> V_8 ) ;
goto V_331;
}
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( ( V_329 != V_4 -> V_77 ) || ( V_1 != V_4 -> V_74 ) ) {
F_3 ( V_159 , L_98
L_99 , V_4 -> V_8 , V_329 ,
V_4 -> V_77 , V_1 , V_4 -> V_74 ) ;
goto V_330;
}
V_336:
V_328 -> V_333 = 0 ;
if ( V_4 -> V_37 -> V_152 & V_195 ) {
if ( V_4 -> V_74 == V_136 )
V_319 = 1 ;
if ( V_319 && ! ( V_4 -> V_82 & V_154 ) )
V_4 -> V_37 -> V_319 ( V_4 ) ;
}
V_175 = F_135 ( V_4 , V_138 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_136 ( V_39 , V_4 , V_138 , V_319 ,
V_175 ) ;
V_331:
if ( V_60 )
F_113 ( V_60 ) ;
return V_60 ;
V_332:
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_328 -> V_333 = 1 ;
return 0 ;
}
static int F_243 ( struct V_3 * V_4 ,
int V_329 )
{
struct V_27 * V_27 ;
struct V_339 * V_340 ;
struct V_123 * V_124 ;
V_27 = F_10 ( V_4 ) ;
V_340 = V_27 -> V_341 ;
if ( F_244 ( V_27 -> V_233 ) ) {
V_124 = F_45 ( V_27 ) ;
V_124 -> V_342 ++ ;
F_3 ( 0 , L_100 , V_124 -> V_342 ) ;
goto V_164;
}
if ( ! F_245 ( V_27 -> V_233 ) )
goto V_164;
F_246 ( V_340 , 0 , 0 , 0 ) ;
if ( F_247 ( V_340 ) ) {
F_3 ( V_165 , L_101 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ) ;
}
F_248 ( V_340 ) ;
if ( V_329 == V_136 ) {
F_249 ( V_340 , 0 ) ;
} else {
F_250 ( V_340 ) ;
}
V_164:
return V_343 ;
}
static int F_251 ( struct V_344 * V_345 ,
struct V_3 * V_4 ,
int V_138 )
{
int V_346 = F_252 ( V_345 ) ;
F_11 ( V_138 != V_139 && V_138 != V_137 ) ;
F_11 ( V_4 -> V_74 != V_136 && ! V_346 ) ;
if ( V_346 )
return 1 ;
F_253 ( F_46 ( F_254 ( V_345 ) ) ) ;
return 0 ;
}
static int F_255 ( struct V_3 * V_4 ,
int V_138 )
{
struct V_27 * V_27 = F_10 ( V_4 ) ;
return F_251 ( F_160 ( V_27 ) , V_4 , V_138 ) ;
}
static void F_256 ( struct V_3 * V_4 )
{
struct V_27 * V_27 = F_10 ( V_4 ) ;
F_138 ( V_27 ) ;
}
static void F_257 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
struct V_29 * V_108 = F_12 ( V_4 ) ;
F_258 ( V_39 , V_108 ) ;
}
static int F_259 ( struct V_3 * V_4 ,
int V_329 )
{
struct V_29 * V_108 = F_12 ( V_4 ) ;
struct V_123 * V_124 = F_45 ( V_108 -> V_109 ) ;
struct V_278 * V_278 ;
unsigned long V_152 ;
int V_347 = 0 ;
if ( V_329 == V_137 )
return V_343 ;
F_21 ( & V_124 -> V_242 ) ;
V_124 -> V_229 |= V_348 ;
F_23 ( & V_124 -> V_242 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_21 ( & V_349 ) ;
if ( ! ( V_4 -> V_82 & V_201 )
&& V_108 -> V_350 ) {
V_108 -> V_350 ++ ;
V_347 = 1 ;
}
F_23 ( & V_349 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_3 ( 0 , L_102 , V_347 ) ;
if ( ! V_347 )
return V_343 ;
F_21 ( & V_349 ) ;
while ( 1 ) {
V_278 = F_260 ( V_108 -> V_109 ,
V_108 -> V_351 , 1 ) ;
if ( ! V_278 )
break;
F_23 ( & V_349 ) ;
if ( F_244 ( V_108 -> V_109 -> V_233 ) )
F_261 ( V_278 ) ;
F_3 ( 0 , L_103 , V_278 ) ;
F_262 ( V_278 ) ;
F_263 ( V_278 ) ;
F_21 ( & V_349 ) ;
}
F_23 ( & V_349 ) ;
if ( V_108 -> V_350 == 1 )
return V_338 ;
return V_352 ;
}
static int F_264 ( struct V_3 * V_4 ,
int V_138 )
{
struct V_33 * V_353 =
F_14 ( V_4 ) ;
return F_251 ( & V_353 -> V_354 , V_4 , V_138 ) ;
}
static int F_265 ( struct V_3 * V_4 ,
int V_329 )
{
struct V_33 * V_353 =
F_14 ( V_4 ) ;
F_159 ( & V_353 -> V_354 ) ;
return V_343 ;
}
static void F_266 ( struct V_3 * V_4 )
{
struct V_355 * V_6 ;
struct V_31 * V_356 = F_13 ( V_4 ) ;
struct V_357 * V_98 = F_267 ( V_356 -> V_99 . V_100 ,
V_356 -> V_99 . V_129 ) ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
V_6 -> V_9 = V_358 ;
V_6 -> V_359 = F_140 ( V_98 -> V_360 ) ;
V_6 -> V_361 = F_140 ( V_98 -> V_362 ) ;
V_6 -> V_363 = F_140 ( V_356 -> V_364 ) ;
V_6 -> V_365 = F_140 ( V_356 -> V_99 . V_366 ) ;
V_6 -> V_367 = F_140 ( V_356 -> V_99 . V_368 ) ;
V_6 -> V_369 = F_140 ( V_356 -> V_99 . V_370 ) ;
}
void F_268 ( struct V_31 * V_356 , int V_207 )
{
struct V_3 * V_4 = & V_356 -> V_371 ;
struct V_36 * V_39 = F_46 ( V_356 -> V_99 . V_100 ) ;
int V_1 = V_207 ? V_136 : V_137 ;
if ( ! F_127 ( V_39 ) && ! F_124 ( V_39 ) )
F_16 ( V_39 , V_4 , V_1 ) ;
}
static int F_269 ( struct V_31 * V_356 )
{
struct V_357 * V_98 = F_267 ( V_356 -> V_99 . V_100 ,
V_356 -> V_99 . V_129 ) ;
struct V_3 * V_4 = & V_356 -> V_371 ;
struct V_355 * V_6 = F_2 ( & V_4 -> V_7 ) ;
struct V_245 * V_246 = NULL ;
struct V_372 * V_373 ;
int V_162 = 0 ;
if ( F_155 ( & V_4 -> V_7 ) &&
V_6 -> V_9 == V_358 ) {
V_98 -> V_360 = F_4 ( V_6 -> V_359 ) ;
V_98 -> V_362 = F_4 ( V_6 -> V_361 ) ;
V_356 -> V_364 = F_4 ( V_6 -> V_363 ) ;
V_356 -> V_99 . V_366 = F_4 ( V_6 -> V_365 ) ;
V_356 -> V_99 . V_368 = F_4 ( V_6 -> V_367 ) ;
V_356 -> V_99 . V_370 =
F_4 ( V_6 -> V_369 ) ;
} else {
V_162 = F_270 ( V_356 -> V_374 ,
V_356 -> V_375 , & V_246 ) ;
if ( V_162 ) {
F_113 ( V_162 ) ;
goto V_176;
}
V_373 = (struct V_372 * )
( V_246 -> V_251 + V_376 ) ;
V_98 -> V_360 = F_163 ( V_373 -> V_360 ) ;
V_98 -> V_362 = F_163 ( V_373 -> V_362 ) ;
V_356 -> V_364 = F_163 ( V_373 -> V_364 ) ;
V_356 -> V_99 . V_366 = F_163 ( V_373 -> V_366 ) ;
V_356 -> V_99 . V_368 = F_163 ( V_373 -> V_368 ) ;
V_356 -> V_99 . V_370 =
F_163 ( V_373 -> V_370 ) ;
F_171 ( V_246 ) ;
F_34 ( V_4 ) ;
}
V_176:
return V_162 ;
}
int F_271 ( struct V_31 * V_356 , int V_207 )
{
struct V_3 * V_4 = & V_356 -> V_371 ;
struct V_36 * V_39 = F_46 ( V_356 -> V_99 . V_100 ) ;
int V_1 = V_207 ? V_136 : V_137 ;
int V_162 = 0 ;
if ( F_127 ( V_39 ) ) {
if ( V_207 )
V_162 = - V_214 ;
goto V_176;
}
if ( F_124 ( V_39 ) )
goto V_176;
V_162 = F_117 ( V_39 , V_4 , V_1 , 0 , 0 ) ;
if ( V_162 < 0 ) {
F_113 ( V_162 ) ;
goto V_176;
}
if ( ! F_156 ( V_4 ) )
goto V_176;
V_162 = F_269 ( V_356 ) ;
if ( V_162 )
F_268 ( V_356 , V_207 ) ;
F_157 ( V_4 , V_162 ) ;
V_176:
return V_162 ;
}
int F_272 ( struct V_33 * V_377 , int V_207 )
{
int V_162 ;
int V_1 = V_207 ? V_136 : V_137 ;
struct V_3 * V_4 = & V_377 -> V_35 ;
struct V_36 * V_39 = V_4 -> V_28 ;
if ( F_127 ( V_39 ) )
return - V_214 ;
if ( F_124 ( V_39 ) )
return 0 ;
V_162 = F_117 ( V_39 , V_4 , V_1 , 0 , 0 ) ;
if ( V_162 < 0 )
F_113 ( V_162 ) ;
return V_162 ;
}
void F_273 ( struct V_33 * V_377 , int V_207 )
{
int V_1 = V_207 ? V_136 : V_137 ;
struct V_3 * V_4 = & V_377 -> V_35 ;
struct V_36 * V_39 = V_4 -> V_28 ;
if ( ! F_124 ( V_39 ) )
F_16 ( V_39 , V_4 , V_1 ) ;
}
static void F_239 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_162 ;
struct V_327 V_328 = { 0 , 0 ,} ;
unsigned long V_152 ;
F_11 ( ! V_4 ) ;
F_11 ( ! V_4 -> V_37 ) ;
F_3 ( V_159 , L_104 , V_4 -> V_8 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( V_4 -> V_82 & V_201 )
goto V_378;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_162 = F_242 ( V_39 , V_4 , & V_328 ) ;
if ( V_162 < 0 )
F_113 ( V_162 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_378:
if ( V_4 -> V_82 & V_201 || ! V_328 . V_333 ) {
F_72 ( V_4 , V_321 ) ;
} else
F_85 ( V_39 , V_4 ) ;
F_3 ( V_159 , L_105 , V_4 -> V_8 ,
V_328 . V_333 ? L_106 : L_107 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
if ( V_328 . V_337 != V_343
&& V_4 -> V_37 -> V_324 )
V_4 -> V_37 -> V_324 ( V_39 , V_4 ) ;
}
static void F_85 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
unsigned long V_152 ;
F_68 ( & V_4 -> V_89 ) ;
if ( V_4 -> V_82 & V_201 ) {
F_3 ( V_159 , L_108 ,
V_4 -> V_8 , V_4 -> V_82 ) ;
return;
}
F_71 ( V_4 , V_321 ) ;
F_80 ( & V_39 -> V_322 , V_152 ) ;
if ( F_25 ( & V_4 -> V_91 ) ) {
F_107 ( & V_4 -> V_91 ,
& V_39 -> V_379 ) ;
V_39 -> V_323 ++ ;
}
F_81 ( & V_39 -> V_322 , V_152 ) ;
}
static void F_274 ( struct V_36 * V_39 )
{
unsigned long V_380 ;
unsigned long V_152 ;
struct V_3 * V_4 ;
F_80 ( & V_39 -> V_322 , V_152 ) ;
V_39 -> V_381 = V_39 -> V_382 ;
V_380 = V_39 -> V_323 ;
while ( V_380 && ! F_25 ( & V_39 -> V_379 ) ) {
V_4 = F_275 ( V_39 -> V_379 . V_383 ,
struct V_3 , V_91 ) ;
F_26 ( & V_4 -> V_91 ) ;
V_39 -> V_323 -- ;
F_81 ( & V_39 -> V_322 , V_152 ) ;
F_11 ( ! V_380 ) ;
V_380 -- ;
F_239 ( V_39 , V_4 ) ;
F_80 ( & V_39 -> V_322 , V_152 ) ;
}
F_81 ( & V_39 -> V_322 , V_152 ) ;
}
static int F_276 ( struct V_36 * V_39 )
{
int V_384 = 0 ;
unsigned long V_152 ;
F_80 ( & V_39 -> V_322 , V_152 ) ;
if ( F_25 ( & V_39 -> V_379 ) )
V_384 = 1 ;
F_81 ( & V_39 -> V_322 , V_152 ) ;
return V_384 ;
}
static int F_277 ( struct V_36 * V_39 )
{
int V_385 = 0 ;
unsigned long V_152 ;
F_80 ( & V_39 -> V_322 , V_152 ) ;
if ( V_39 -> V_381 != V_39 -> V_382 )
V_385 = 1 ;
F_81 ( & V_39 -> V_322 , V_152 ) ;
return V_385 ;
}
static int V_313 ( void * V_386 )
{
int V_162 = 0 ;
struct V_36 * V_39 = V_386 ;
while ( ! ( F_278 () &&
F_276 ( V_39 ) ) ) {
F_279 ( V_39 -> V_387 ,
F_277 ( V_39 ) ||
F_278 () ) ;
F_3 ( 0 , L_109 ) ;
F_274 ( V_39 ) ;
}
V_39 -> V_312 = NULL ;
return V_162 ;
}
void F_78 ( struct V_36 * V_39 )
{
unsigned long V_152 ;
F_80 ( & V_39 -> V_322 , V_152 ) ;
V_39 -> V_382 ++ ;
F_81 ( & V_39 -> V_322 , V_152 ) ;
F_86 ( & V_39 -> V_387 ) ;
}
