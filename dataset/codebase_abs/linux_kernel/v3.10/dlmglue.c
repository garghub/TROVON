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
F_71 ( V_4 , V_155 ) ;
F_72 ( V_4 , V_149 ) ;
}
static inline void F_75 ( struct V_3 * V_4 )
{
F_11 ( ( ! ( V_4 -> V_82 & V_149 ) ) ) ;
F_11 ( V_4 -> V_82 & V_150 ) ;
if ( V_4 -> V_76 > V_139 &&
! ( V_4 -> V_82 & V_156 ) &&
V_4 -> V_37 -> V_152 & V_153 )
F_71 ( V_4 , V_154 ) ;
V_4 -> V_74 = V_4 -> V_76 ;
F_71 ( V_4 , V_150 ) ;
F_72 ( V_4 , V_149 ) ;
}
static int F_76 ( struct V_3 * V_4 ,
int V_1 )
{
int V_157 = 0 ;
F_68 ( & V_4 -> V_89 ) ;
if ( V_1 > V_4 -> V_77 ) {
if ( F_66 ( V_1 ) <
F_66 ( V_4 -> V_77 ) )
V_157 = 1 ;
V_4 -> V_77 = V_1 ;
}
F_3 ( V_158 , L_16 ,
V_4 -> V_8 , V_1 , V_4 -> V_74 , V_4 -> V_77 ,
V_157 ) ;
if ( V_157 )
F_71 ( V_4 , V_151 ) ;
F_3 ( 0 , L_17 , V_157 ) ;
return V_157 ;
}
static void F_77 ( struct V_3 * V_4 ,
unsigned int V_43 ,
struct V_36 * V_39 )
{
F_68 ( & V_4 -> V_89 ) ;
if ( ! ( V_4 -> V_82 & V_159 ) ||
( V_4 -> V_160 != V_43 ) )
return;
F_72 ( V_4 , V_159 ) ;
V_4 -> V_160 ++ ;
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
F_71 ( V_4 , V_159 ) ;
return V_4 -> V_160 ;
}
static void F_83 ( struct V_25 * V_26 , int V_1 )
{
struct V_3 * V_4 = F_8 ( V_26 ) ;
struct V_36 * V_39 = F_15 ( V_4 ) ;
int V_157 ;
unsigned long V_152 ;
F_11 ( V_1 <= V_139 ) ;
F_3 ( V_158 , L_18
L_19 , V_4 -> V_8 , V_1 , V_4 -> V_74 ,
F_84 ( V_4 -> V_21 ) ) ;
if ( V_4 -> V_82 & V_128 )
return;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_157 = F_76 ( V_4 , V_1 ) ;
if ( V_157 )
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
int V_161 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_161 = F_88 ( & V_4 -> V_7 ) ;
if ( V_161 == - V_162 ) {
F_72 ( V_4 , V_149 ) ;
goto V_163;
}
if ( V_161 ) {
F_3 ( V_164 , L_20 ,
V_4 -> V_8 , V_161 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
return;
}
F_3 ( V_158 , L_21
L_22 , V_4 -> V_8 , V_4 -> V_78 ,
V_4 -> V_80 , V_4 -> V_74 , V_4 -> V_76 ) ;
switch( V_4 -> V_78 ) {
case V_165 :
F_75 ( V_4 ) ;
F_72 ( V_4 , V_156 ) ;
break;
case V_166 :
F_74 ( V_4 ) ;
break;
case V_167 :
F_73 ( V_4 ) ;
break;
default:
F_3 ( V_164 , L_23
L_24 ,
V_4 -> V_8 , V_4 -> V_78 , V_4 -> V_82 ,
V_4 -> V_80 ) ;
F_64 () ;
}
V_163:
V_4 -> V_78 = V_79 ;
if ( V_4 -> V_80 == V_168 )
V_4 -> V_80 = V_81 ;
F_77 ( V_4 , V_4 -> V_160 , V_39 ) ;
F_86 ( & V_4 -> V_90 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
}
static void F_89 ( struct V_25 * V_26 , int error )
{
struct V_3 * V_4 = F_8 ( V_26 ) ;
unsigned long V_152 ;
F_3 ( V_158 , L_25 ,
V_4 -> V_8 , V_4 -> V_80 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( error ) {
F_3 ( V_164 , L_26
L_27 , error , V_4 -> V_8 ,
V_4 -> V_80 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
return;
}
switch( V_4 -> V_80 ) {
case V_168 :
F_3 ( 0 , L_28 , V_4 -> V_8 ) ;
V_4 -> V_78 = V_79 ;
if ( V_4 -> V_82 & V_151 )
F_78 ( F_15 ( V_4 ) ) ;
break;
case V_169 :
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
F_91 ( & V_170 . V_171 ) ;
}
static inline void F_92 ( struct V_3 * V_4 ,
int V_172 )
{
unsigned long V_152 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_72 ( V_4 , V_149 ) ;
F_72 ( V_4 , V_155 ) ;
if ( V_172 )
V_4 -> V_78 = V_79 ;
else
V_4 -> V_80 = V_81 ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_86 ( & V_4 -> V_90 ) ;
}
static int F_93 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 ,
T_2 V_173 )
{
int V_60 = 0 ;
unsigned long V_152 ;
unsigned int V_174 ;
F_3 ( 0 , L_29 , V_4 -> V_8 , V_1 ,
V_173 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( ( V_4 -> V_82 & V_150 ) ||
( V_4 -> V_82 & V_149 ) ) {
F_81 ( & V_4 -> V_89 , V_152 ) ;
goto V_175;
}
V_4 -> V_78 = V_165 ;
V_4 -> V_76 = V_1 ;
F_71 ( V_4 , V_149 ) ;
V_174 = F_82 ( V_4 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_94 ( V_39 -> V_176 ,
V_1 ,
& V_4 -> V_7 ,
V_173 ,
V_4 -> V_8 ,
V_47 - 1 ) ;
F_79 ( V_4 , V_174 , V_39 ) ;
if ( V_60 ) {
F_95 ( L_30 , V_60 , V_4 ) ;
F_92 ( V_4 , 1 ) ;
}
F_3 ( 0 , L_31 , V_4 -> V_8 ) ;
V_175:
return V_60 ;
}
static inline int F_96 ( struct V_3 * V_4 ,
int V_177 )
{
unsigned long V_152 ;
int V_60 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_60 = V_4 -> V_82 & V_177 ;
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
! F_96 ( V_4 , V_178 ) ) ;
}
static inline int F_100 ( struct V_3 * V_4 ,
int V_179 )
{
F_11 ( ! ( V_4 -> V_82 & V_151 ) ) ;
return V_179 <= F_66 ( V_4 -> V_77 ) ;
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
F_105 ( V_59 -> V_146 ) ;
return V_59 -> V_145 ;
}
static void F_106 ( struct V_3 * V_4 ,
struct V_58 * V_59 ,
unsigned long V_180 ,
unsigned long V_181 )
{
F_11 ( ! F_25 ( & V_59 -> V_144 ) ) ;
F_68 ( & V_4 -> V_89 ) ;
F_107 ( & V_59 -> V_144 , & V_4 -> V_92 ) ;
V_59 -> V_142 = V_180 ;
V_59 -> V_143 = V_181 ;
}
static int F_108 ( struct V_3 * V_4 ,
struct V_58 * V_59 )
{
unsigned long V_152 ;
int V_60 = 0 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( ! F_25 ( & V_59 -> V_144 ) ) {
if ( ( V_4 -> V_82 & V_59 -> V_142 ) != V_59 -> V_143 )
V_60 = - V_182 ;
F_26 ( & V_59 -> V_144 ) ;
F_102 ( & V_59 -> V_146 ) ;
}
F_81 ( & V_4 -> V_89 , V_152 ) ;
return V_60 ;
}
static int F_109 ( struct V_58 * V_59 ,
struct V_3 * V_4 )
{
int V_60 ;
V_60 = F_110 ( & V_59 -> V_146 ) ;
if ( V_60 )
F_108 ( V_4 , V_59 ) ;
else
V_60 = V_59 -> V_145 ;
F_105 ( V_59 -> V_146 ) ;
return V_60 ;
}
static int F_111 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 ,
T_2 V_183 ,
int V_184 ,
int V_185 ,
unsigned long V_186 )
{
struct V_58 V_59 ;
int V_187 , V_188 = ! ( V_39 -> V_189 & V_190 ) ;
int V_60 = 0 ;
unsigned long V_152 ;
unsigned int V_174 ;
int V_191 = 0 ;
F_101 ( & V_59 ) ;
if ( V_4 -> V_37 -> V_152 & V_192 )
V_183 |= V_193 ;
V_194:
V_187 = 0 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( V_188 && F_112 ( V_195 ) ) {
V_60 = - V_196 ;
goto V_197;
}
F_44 ( V_4 -> V_82 & V_198 ,
L_32
L_33 , V_4 -> V_8 , V_4 -> V_82 ) ;
if ( V_4 -> V_82 & V_149 &&
V_1 > V_4 -> V_74 ) {
F_106 ( V_4 , & V_59 , V_149 , 0 ) ;
V_187 = 1 ;
goto V_197;
}
if ( V_4 -> V_82 & V_155 ) {
if ( V_1 <= V_4 -> V_74 )
goto V_199;
}
if ( V_4 -> V_82 & V_151 &&
! F_100 ( V_4 , V_1 ) ) {
F_106 ( V_4 , & V_59 , V_151 , 0 ) ;
V_187 = 1 ;
goto V_197;
}
if ( V_1 > V_4 -> V_74 ) {
if ( V_191 > 0 ) {
V_60 = - V_162 ;
goto V_197;
}
if ( V_183 & V_200 )
V_191 = 1 ;
if ( V_4 -> V_78 != V_79 )
F_3 ( V_164 , L_34 ,
V_4 -> V_8 , V_4 -> V_78 ) ;
if ( ! ( V_4 -> V_82 & V_150 ) ) {
V_4 -> V_78 = V_165 ;
V_183 &= ~ V_201 ;
} else {
V_4 -> V_78 = V_166 ;
V_183 |= V_201 ;
}
V_4 -> V_76 = V_1 ;
F_71 ( V_4 , V_149 ) ;
V_174 = F_82 ( V_4 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_11 ( V_1 == V_75 ) ;
F_11 ( V_1 == V_139 ) ;
F_3 ( V_158 , L_35 ,
V_4 -> V_8 , V_4 -> V_74 , V_1 ) ;
V_60 = F_94 ( V_39 -> V_176 ,
V_1 ,
& V_4 -> V_7 ,
V_183 ,
V_4 -> V_8 ,
V_47 - 1 ) ;
F_79 ( V_4 , V_174 , V_39 ) ;
if ( V_60 ) {
if ( ! ( V_183 & V_200 ) ||
( V_60 != - V_162 ) ) {
F_95 ( L_30 ,
V_60 , V_4 ) ;
}
F_92 ( V_4 , 1 ) ;
goto V_163;
}
F_3 ( 0 , L_36 ,
V_4 -> V_8 ) ;
V_188 = 0 ;
goto V_194;
}
V_199:
F_63 ( V_4 , V_1 ) ;
V_60 = 0 ;
V_197:
F_72 ( V_4 , V_155 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_163:
if ( V_187 && V_184 & V_202 &&
V_59 . V_142 & ( V_149 | V_151 ) ) {
V_187 = 0 ;
if ( F_108 ( V_4 , & V_59 ) )
V_60 = - V_162 ;
else
goto V_194;
}
if ( V_187 ) {
V_60 = F_103 ( & V_59 ) ;
if ( V_60 == 0 )
goto V_194;
F_113 ( V_60 ) ;
}
F_28 ( V_4 , V_1 , & V_59 , V_60 ) ;
#ifdef F_37
if ( ! V_60 && V_4 -> V_85 . V_88 != NULL ) {
if ( V_1 == V_137 )
F_114 ( & V_4 -> V_85 , V_185 ,
! ! ( V_184 & V_203 ) ,
V_186 ) ;
else
F_115 ( & V_4 -> V_85 , V_185 ,
! ! ( V_184 & V_203 ) ,
V_186 ) ;
}
#endif
return V_60 ;
}
static inline int F_116 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 ,
T_2 V_183 ,
int V_184 )
{
return F_111 ( V_39 , V_4 , V_1 , V_183 , V_184 ,
0 , V_40 ) ;
}
static void F_17 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_1 ,
unsigned long V_186 )
{
unsigned long V_152 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_65 ( V_4 , V_1 ) ;
F_117 ( V_39 , V_4 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
#ifdef F_37
if ( V_4 -> V_85 . V_88 != NULL )
F_118 ( & V_4 -> V_85 , 1 , V_186 ) ;
#endif
}
static int F_119 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_204 ,
int V_205 )
{
int V_1 = V_204 ? V_136 : V_137 ;
unsigned long V_152 ;
T_2 V_183 = V_205 ? V_206 : 0 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_11 ( V_4 -> V_82 & V_150 ) ;
F_71 ( V_4 , V_156 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
return F_93 ( V_39 , V_4 , V_1 , V_183 ) ;
}
int F_120 ( struct V_27 * V_27 )
{
int V_60 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_11 ( ! V_27 ) ;
F_11 ( ! F_121 ( V_27 ) ) ;
F_3 ( 0 , L_37 , ( unsigned long long ) F_45 ( V_27 ) -> V_96 ) ;
V_60 = F_119 ( V_39 , & F_45 ( V_27 ) -> V_207 , 1 , 1 ) ;
if ( V_60 ) {
F_113 ( V_60 ) ;
goto V_175;
}
V_60 = F_119 ( V_39 , & F_45 ( V_27 ) -> V_208 , 1 , 0 ) ;
if ( V_60 ) {
F_113 ( V_60 ) ;
goto V_175;
}
V_60 = F_119 ( V_39 , & F_45 ( V_27 ) -> V_209 , 0 , 0 ) ;
if ( V_60 ) {
F_113 ( V_60 ) ;
goto V_175;
}
V_175:
return V_60 ;
}
int F_122 ( struct V_27 * V_27 , int V_210 )
{
int V_161 , V_1 ;
struct V_3 * V_4 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_11 ( ! V_27 ) ;
F_3 ( 0 , L_38 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ,
V_210 ? L_39 : L_40 ) ;
if ( F_123 ( V_39 ) )
return 0 ;
V_4 = & F_45 ( V_27 ) -> V_207 ;
V_1 = V_210 ? V_136 : V_137 ;
V_161 = F_116 ( F_46 ( V_27 -> V_97 ) , V_4 , V_1 , 0 ,
0 ) ;
if ( V_161 < 0 )
F_113 ( V_161 ) ;
return V_161 ;
}
void F_124 ( struct V_27 * V_27 , int V_210 )
{
int V_1 = V_210 ? V_136 : V_137 ;
struct V_3 * V_4 = & F_45 ( V_27 ) -> V_207 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_3 ( 0 , L_41 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ,
V_210 ? L_39 : L_40 ) ;
if ( ! F_123 ( V_39 ) )
F_16 ( F_46 ( V_27 -> V_97 ) , V_4 , V_1 ) ;
}
int F_125 ( struct V_27 * V_27 )
{
int V_161 = 0 ;
struct V_3 * V_4 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_11 ( ! V_27 ) ;
F_3 ( 0 , L_42 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ) ;
if ( F_126 ( V_39 ) || F_123 ( V_39 ) )
goto V_163;
V_4 = & F_45 ( V_27 ) -> V_209 ;
V_161 = F_116 ( F_46 ( V_27 -> V_97 ) , V_4 ,
V_137 , 0 , 0 ) ;
if ( V_161 < 0 )
F_113 ( V_161 ) ;
V_163:
return V_161 ;
}
int F_127 ( struct V_27 * V_27 , int V_210 )
{
int V_161 = 0 , V_1 ;
struct V_3 * V_4 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_11 ( ! V_27 ) ;
F_3 ( 0 , L_43 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ,
V_210 ? L_39 : L_40 ) ;
if ( F_126 ( V_39 ) ) {
if ( V_210 )
V_161 = - V_211 ;
goto V_163;
}
if ( F_123 ( V_39 ) )
goto V_163;
V_4 = & F_45 ( V_27 ) -> V_209 ;
V_1 = V_210 ? V_136 : V_137 ;
V_161 = F_116 ( F_46 ( V_27 -> V_97 ) , V_4 ,
V_1 , V_200 , 0 ) ;
V_163:
return V_161 ;
}
void F_128 ( struct V_27 * V_27 )
{
struct V_3 * V_4 = & F_45 ( V_27 ) -> V_209 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_3 ( 0 , L_44 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ) ;
if ( F_123 ( V_39 ) )
goto V_163;
if( V_4 -> V_134 )
F_16 ( F_46 ( V_27 -> V_97 ) , V_4 ,
V_137 ) ;
if( V_4 -> V_135 )
F_16 ( F_46 ( V_27 -> V_97 ) , V_4 ,
V_136 ) ;
V_163:
return;
}
static int F_129 ( struct V_3 * V_4 ,
int V_1 )
{
int V_60 ;
struct V_36 * V_39 = F_15 ( V_4 ) ;
unsigned long V_152 ;
struct V_58 V_59 ;
F_101 ( & V_59 ) ;
V_212:
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( V_4 -> V_82 & V_149 ) {
V_60 = F_130 ( V_39 , V_4 ) ;
if ( V_60 ) {
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_131 ( V_39 , V_4 ) ;
if ( V_60 < 0 ) {
F_113 ( V_60 ) ;
goto V_163;
}
goto V_212;
}
F_106 ( V_4 , & V_59 , V_149 , 0 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_103 ( & V_59 ) ;
goto V_212;
}
V_60 = - V_196 ;
if ( V_4 -> V_74 == V_1 )
V_60 = 0 ;
F_3 ( 0 , L_45 , V_60 ,
V_4 -> V_82 , V_4 -> V_74 , V_4 -> V_78 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_163:
return V_60 ;
}
int F_132 ( struct V_213 * V_213 , int V_204 , int V_214 )
{
int V_60 , V_1 = V_204 ? V_136 : V_137 ;
unsigned int V_183 = V_214 ? V_200 : 0 ;
unsigned long V_152 ;
struct V_101 * V_102 = V_213 -> V_215 ;
struct V_3 * V_4 = & V_102 -> V_216 ;
struct V_36 * V_39 = F_46 ( V_213 -> V_104 -> V_105 -> V_97 ) ;
struct V_58 V_59 ;
F_101 ( & V_59 ) ;
if ( ( V_4 -> V_82 & V_149 ) ||
( V_4 -> V_74 > V_139 ) ) {
F_3 ( V_164 ,
L_46
L_47 , V_4 -> V_8 , V_4 -> V_82 ,
V_4 -> V_74 ) ;
return - V_217 ;
}
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( ! ( V_4 -> V_82 & V_150 ) ) {
F_106 ( V_4 , & V_59 , V_149 , 0 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_93 ( V_39 , V_4 , V_139 , 0 ) ;
if ( V_60 < 0 ) {
F_113 ( V_60 ) ;
goto V_163;
}
V_60 = F_103 ( & V_59 ) ;
if ( V_60 ) {
F_113 ( V_60 ) ;
goto V_163;
}
F_80 ( & V_4 -> V_89 , V_152 ) ;
}
V_4 -> V_78 = V_166 ;
V_183 |= V_201 ;
V_4 -> V_76 = V_1 ;
F_71 ( V_4 , V_149 ) ;
F_106 ( V_4 , & V_59 , V_149 , 0 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_94 ( V_39 -> V_176 , V_1 , & V_4 -> V_7 , V_183 ,
V_4 -> V_8 , V_47 - 1 ) ;
if ( V_60 ) {
if ( ! V_214 || ( V_60 != - V_162 ) ) {
F_95 ( L_30 , V_60 , V_4 ) ;
V_60 = - V_217 ;
}
F_92 ( V_4 , 1 ) ;
F_108 ( V_4 , & V_59 ) ;
goto V_163;
}
V_60 = F_109 ( & V_59 , V_4 ) ;
if ( V_60 == - V_196 ) {
V_60 = F_129 ( V_4 , V_1 ) ;
} else if ( ! V_60 && ( V_1 > V_4 -> V_74 ) ) {
F_11 ( ! V_214 ) ;
V_60 = - V_162 ;
}
V_163:
F_3 ( 0 , L_48 ,
V_4 -> V_8 , V_204 , V_214 , V_60 ) ;
return V_60 ;
}
void F_133 ( struct V_213 * V_213 )
{
int V_60 ;
unsigned int V_174 ;
unsigned long V_152 ;
struct V_101 * V_102 = V_213 -> V_215 ;
struct V_3 * V_4 = & V_102 -> V_216 ;
struct V_36 * V_39 = F_46 ( V_213 -> V_104 -> V_105 -> V_97 ) ;
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
V_174 = F_134 ( V_4 , V_139 ) ;
F_106 ( V_4 , & V_59 , V_149 , 0 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_135 ( V_39 , V_4 , V_139 , 0 , V_174 ) ;
if ( V_60 ) {
F_113 ( V_60 ) ;
return;
}
V_60 = F_103 ( & V_59 ) ;
if ( V_60 )
F_113 ( V_60 ) ;
}
static void F_117 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_218 = 0 ;
if ( V_4 -> V_82 & V_151 ) {
switch( V_4 -> V_77 ) {
case V_136 :
if ( ! V_4 -> V_135 && ! V_4 -> V_134 )
V_218 = 1 ;
break;
case V_137 :
if ( ! V_4 -> V_135 )
V_218 = 1 ;
break;
default:
F_64 () ;
}
}
if ( V_218 )
F_78 ( V_39 ) ;
}
static T_1 F_136 ( struct V_219 * V_220 )
{
T_1 V_34 ;
T_1 V_221 = V_220 -> V_222 ;
T_2 V_223 = V_220 -> V_224 ;
V_34 = ( V_221 << V_225 ) | ( V_223 & V_226 ) ;
return V_34 ;
}
static void F_137 ( struct V_27 * V_27 )
{
struct V_123 * V_124 = F_45 ( V_27 ) ;
struct V_3 * V_4 = & V_124 -> V_208 ;
struct V_5 * V_6 ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
if ( V_124 -> V_227 & V_228 ) {
V_6 -> V_9 = 0 ;
goto V_163;
}
V_6 -> V_9 = V_229 ;
V_6 -> V_12 = F_53 ( F_138 ( V_27 ) ) ;
V_6 -> V_10 = F_139 ( V_124 -> V_230 ) ;
V_6 -> V_13 = F_139 ( F_140 ( V_27 ) ) ;
V_6 -> V_14 = F_139 ( F_141 ( V_27 ) ) ;
V_6 -> V_15 = F_142 ( V_27 -> V_231 ) ;
V_6 -> V_16 = F_142 ( V_27 -> V_232 ) ;
V_6 -> V_17 =
F_53 ( F_136 ( & V_27 -> V_233 ) ) ;
V_6 -> V_18 =
F_53 ( F_136 ( & V_27 -> V_234 ) ) ;
V_6 -> V_19 =
F_53 ( F_136 ( & V_27 -> V_235 ) ) ;
V_6 -> V_20 = F_139 ( V_124 -> V_236 ) ;
V_6 -> V_237 = F_142 ( V_124 -> V_238 ) ;
V_6 -> V_11 = F_139 ( V_27 -> V_126 ) ;
V_163:
F_143 ( 0 , V_4 ) ;
}
static void F_144 ( struct V_219 * V_220 ,
T_1 V_239 )
{
V_220 -> V_222 = V_239 >> V_225 ;
V_220 -> V_224 = V_239 & V_226 ;
}
static void F_145 ( struct V_27 * V_27 )
{
struct V_123 * V_124 = F_45 ( V_27 ) ;
struct V_3 * V_4 = & V_124 -> V_208 ;
struct V_5 * V_6 ;
F_143 ( 0 , V_4 ) ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
F_21 ( & V_124 -> V_240 ) ;
V_124 -> V_230 = F_4 ( V_6 -> V_10 ) ;
F_146 ( V_27 , F_5 ( V_6 -> V_12 ) ) ;
V_124 -> V_236 = F_4 ( V_6 -> V_20 ) ;
V_124 -> V_238 = F_6 ( V_6 -> V_237 ) ;
F_147 ( V_27 ) ;
if ( F_148 ( V_27 -> V_231 ) && ! V_124 -> V_230 )
V_27 -> V_241 = 0 ;
else
V_27 -> V_241 = F_149 ( V_27 ) ;
F_150 ( V_27 , F_4 ( V_6 -> V_13 ) ) ;
F_151 ( V_27 , F_4 ( V_6 -> V_14 ) ) ;
V_27 -> V_231 = F_6 ( V_6 -> V_15 ) ;
F_152 ( V_27 , F_6 ( V_6 -> V_16 ) ) ;
F_144 ( & V_27 -> V_233 ,
F_5 ( V_6 -> V_17 ) ) ;
F_144 ( & V_27 -> V_235 ,
F_5 ( V_6 -> V_19 ) ) ;
F_144 ( & V_27 -> V_234 ,
F_5 ( V_6 -> V_18 ) ) ;
F_23 ( & V_124 -> V_240 ) ;
}
static inline int F_153 ( struct V_27 * V_27 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_4 -> V_7 ) ;
if ( F_154 ( & V_4 -> V_7 )
&& V_6 -> V_9 == V_229
&& F_4 ( V_6 -> V_11 ) == V_27 -> V_126 )
return 1 ;
return 0 ;
}
static int F_155 ( struct V_3 * V_4 )
{
unsigned long V_152 ;
int V_161 = 0 ;
V_242:
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( ! ( V_4 -> V_82 & V_154 ) ) {
F_81 ( & V_4 -> V_89 , V_152 ) ;
goto V_175;
}
if ( V_4 -> V_82 & V_178 ) {
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_99 ( V_4 ) ;
goto V_242;
}
F_71 ( V_4 , V_178 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_161 = 1 ;
V_175:
F_3 ( 0 , L_50 , V_161 ) ;
return V_161 ;
}
static inline void F_156 ( struct V_3 * V_4 ,
int V_161 )
{
unsigned long V_152 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_72 ( V_4 , V_178 ) ;
if ( ! V_161 )
F_72 ( V_4 , V_154 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_86 ( & V_4 -> V_90 ) ;
}
static int F_157 ( struct V_27 * V_27 ,
struct V_243 * * V_244 )
{
int V_161 = 0 ;
struct V_123 * V_124 = F_45 ( V_27 ) ;
struct V_3 * V_4 = & V_124 -> V_208 ;
struct V_245 * V_246 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
if ( F_123 ( V_39 ) )
goto V_175;
F_21 ( & V_124 -> V_240 ) ;
if ( V_124 -> V_227 & V_228 ) {
F_3 ( 0 , L_51
L_52 ,
( unsigned long long ) V_124 -> V_96 , V_124 -> V_227 ) ;
F_23 ( & V_124 -> V_240 ) ;
V_161 = - V_247 ;
goto V_175;
}
F_23 ( & V_124 -> V_240 ) ;
if ( ! F_155 ( V_4 ) )
goto V_175;
F_158 ( F_159 ( V_27 ) ) ;
F_160 ( V_27 , 0 ) ;
if ( F_153 ( V_27 , V_4 ) ) {
F_3 ( 0 , L_53 ,
( unsigned long long ) V_124 -> V_96 ) ;
F_145 ( V_27 ) ;
} else {
V_161 = F_161 ( V_27 , V_244 ) ;
if ( V_161 < 0 ) {
F_113 ( V_161 ) ;
goto V_248;
}
V_246 = (struct V_245 * ) ( * V_244 ) -> V_249 ;
F_44 ( V_27 -> V_126 !=
F_162 ( V_246 -> V_126 ) ,
L_54
L_55 ,
( unsigned long long ) V_124 -> V_96 ,
F_162 ( V_246 -> V_126 ) ,
V_27 -> V_126 ) ;
F_44 ( F_163 ( V_246 -> V_250 ) ||
! ( V_246 -> V_251 & F_164 ( V_252 ) ) ,
L_56 ,
( unsigned long long ) V_124 -> V_96 ,
( unsigned long long ) F_163 ( V_246 -> V_250 ) ,
F_162 ( V_246 -> V_251 ) ) ;
F_165 ( V_27 , V_246 ) ;
F_34 ( V_4 ) ;
}
V_161 = 0 ;
V_248:
F_156 ( V_4 , V_161 ) ;
V_175:
return V_161 ;
}
static int F_166 ( struct V_27 * V_27 ,
struct V_243 * * V_253 ,
struct V_243 * V_254 )
{
int V_161 ;
if ( V_254 ) {
* V_253 = V_254 ;
F_167 ( * V_253 ) ;
return 0 ;
}
V_161 = F_161 ( V_27 , V_253 ) ;
if ( V_161 < 0 )
F_113 ( V_161 ) ;
return V_161 ;
}
int F_168 ( struct V_27 * V_27 ,
struct V_243 * * V_253 ,
int V_204 ,
int V_184 ,
int V_255 )
{
int V_161 , V_1 , V_256 ;
T_2 V_173 ;
struct V_3 * V_4 = NULL ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
struct V_243 * V_257 = NULL ;
F_11 ( ! V_27 ) ;
F_3 ( 0 , L_57 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ,
V_204 ? L_39 : L_40 ) ;
V_161 = 0 ;
V_256 = 0 ;
if ( F_126 ( V_39 ) ) {
if ( V_204 )
V_161 = - V_211 ;
goto V_258;
}
if ( F_123 ( V_39 ) )
goto V_205;
if ( ! ( V_184 & V_259 ) )
F_169 ( V_39 ) ;
V_4 = & F_45 ( V_27 ) -> V_208 ;
V_1 = V_204 ? V_136 : V_137 ;
V_173 = 0 ;
if ( V_184 & V_203 )
V_173 |= V_200 ;
V_161 = F_111 ( V_39 , V_4 , V_1 , V_173 ,
V_184 , V_255 , V_40 ) ;
if ( V_161 < 0 ) {
if ( V_161 != - V_162 )
F_113 ( V_161 ) ;
goto V_175;
}
V_256 = 1 ;
if ( ! ( V_184 & V_259 ) )
F_169 ( V_39 ) ;
V_205:
if ( V_27 -> V_260 & V_261 ) {
V_161 = 0 ;
if ( V_4 )
F_156 ( V_4 , 0 ) ;
goto V_175;
}
V_161 = F_157 ( V_27 , & V_257 ) ;
if ( V_161 < 0 ) {
if ( V_161 != - V_247 )
F_113 ( V_161 ) ;
goto V_175;
}
V_258:
if ( V_253 ) {
V_161 = F_166 ( V_27 , V_253 , V_257 ) ;
if ( V_161 < 0 ) {
F_113 ( V_161 ) ;
goto V_175;
}
}
V_175:
if ( V_161 < 0 ) {
if ( V_253 && ( * V_253 ) ) {
F_170 ( * V_253 ) ;
* V_253 = NULL ;
}
if ( V_256 )
F_171 ( V_27 , V_204 ) ;
}
if ( V_257 )
F_170 ( V_257 ) ;
return V_161 ;
}
int F_172 ( struct V_27 * V_27 ,
struct V_243 * * V_253 ,
int V_204 ,
struct V_262 * V_262 )
{
int V_60 ;
V_60 = F_173 ( V_27 , V_253 , V_204 , V_202 ) ;
if ( V_60 == - V_162 ) {
F_174 ( V_262 ) ;
if ( F_175 ( V_27 , V_253 , V_204 ) == 0 )
F_171 ( V_27 , V_204 ) ;
V_60 = V_263 ;
}
return V_60 ;
}
int F_176 ( struct V_27 * V_27 ,
struct V_264 * V_265 ,
int * V_1 )
{
int V_60 ;
V_60 = F_175 ( V_27 , NULL , 0 ) ;
if ( V_60 < 0 ) {
F_113 ( V_60 ) ;
return V_60 ;
}
if ( F_177 ( V_27 , V_265 ) ) {
struct V_243 * V_244 = NULL ;
F_171 ( V_27 , 0 ) ;
V_60 = F_175 ( V_27 , & V_244 , 1 ) ;
if ( V_60 < 0 ) {
F_113 ( V_60 ) ;
return V_60 ;
}
* V_1 = 1 ;
if ( F_177 ( V_27 , V_265 ) )
F_178 ( V_27 , V_244 ) ;
if ( V_244 )
F_170 ( V_244 ) ;
} else
* V_1 = 0 ;
return V_60 ;
}
void F_171 ( struct V_27 * V_27 ,
int V_204 )
{
int V_1 = V_204 ? V_136 : V_137 ;
struct V_3 * V_4 = & F_45 ( V_27 ) -> V_208 ;
struct V_36 * V_39 = F_46 ( V_27 -> V_97 ) ;
F_3 ( 0 , L_58 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ,
V_204 ? L_39 : L_40 ) ;
if ( ! F_126 ( F_46 ( V_27 -> V_97 ) ) &&
! F_123 ( V_39 ) )
F_16 ( F_46 ( V_27 -> V_97 ) , V_4 , V_1 ) ;
}
int F_179 ( struct V_36 * V_39 , T_2 * V_266 )
{
struct V_3 * V_4 ;
struct V_267 * V_6 ;
int V_161 = 0 ;
if ( F_126 ( V_39 ) )
return - V_211 ;
if ( F_123 ( V_39 ) )
return 0 ;
V_4 = & V_39 -> V_268 . V_269 ;
V_161 = F_116 ( V_39 , V_4 , V_136 , 0 , 0 ) ;
if ( V_161 < 0 )
return V_161 ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
if ( F_154 ( & V_4 -> V_7 ) &&
V_6 -> V_9 == V_270 )
* V_266 = F_4 ( V_6 -> V_271 ) ;
else
* V_266 = V_39 -> V_268 . V_272 + 1 ;
return V_161 ;
}
void F_180 ( struct V_36 * V_39 , T_2 V_266 )
{
struct V_3 * V_4 ;
struct V_267 * V_6 ;
if ( ! F_126 ( V_39 ) && ! F_123 ( V_39 ) ) {
V_4 = & V_39 -> V_268 . V_269 ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
V_6 -> V_9 = V_270 ;
V_6 -> V_271 = F_139 ( V_266 ) ;
F_16 ( V_39 , V_4 , V_136 ) ;
}
}
int F_181 ( struct V_36 * V_39 ,
int V_204 )
{
int V_161 = 0 ;
int V_1 = V_204 ? V_136 : V_137 ;
struct V_3 * V_4 = & V_39 -> V_273 ;
if ( F_126 ( V_39 ) )
return - V_211 ;
if ( F_123 ( V_39 ) )
goto V_175;
V_161 = F_116 ( V_39 , V_4 , V_1 , 0 , 0 ) ;
if ( V_161 < 0 ) {
F_113 ( V_161 ) ;
goto V_175;
}
V_161 = F_155 ( V_4 ) ;
if ( V_161 < 0 ) {
F_16 ( V_39 , V_4 , V_1 ) ;
F_113 ( V_161 ) ;
goto V_175;
}
if ( V_161 ) {
V_161 = F_182 ( V_39 ) ;
F_156 ( V_4 , V_161 ) ;
if ( V_161 < 0 ) {
F_16 ( V_39 , V_4 , V_1 ) ;
F_113 ( V_161 ) ;
}
F_34 ( V_4 ) ;
}
V_175:
return V_161 ;
}
void F_183 ( struct V_36 * V_39 ,
int V_204 )
{
int V_1 = V_204 ? V_136 : V_137 ;
struct V_3 * V_4 = & V_39 -> V_273 ;
if ( ! F_123 ( V_39 ) )
F_16 ( V_39 , V_4 , V_1 ) ;
}
int F_184 ( struct V_36 * V_39 )
{
int V_161 ;
struct V_3 * V_4 = & V_39 -> V_274 ;
if ( F_126 ( V_39 ) )
return - V_211 ;
if ( F_123 ( V_39 ) )
return 0 ;
V_161 = F_116 ( V_39 , V_4 , V_136 , 0 , 0 ) ;
if ( V_161 < 0 )
F_113 ( V_161 ) ;
return V_161 ;
}
void F_185 ( struct V_36 * V_39 )
{
struct V_3 * V_4 = & V_39 -> V_274 ;
if ( ! F_123 ( V_39 ) )
F_16 ( V_39 , V_4 , V_136 ) ;
}
int F_186 ( struct V_36 * V_39 , int V_204 )
{
int V_161 ;
struct V_3 * V_4 = & V_39 -> V_275 ;
if ( F_126 ( V_39 ) )
return - V_211 ;
if ( F_123 ( V_39 ) )
return 0 ;
V_161 = F_116 ( V_39 , V_4 , V_204 ? V_65 : V_64 ,
0 , 0 ) ;
if ( V_161 < 0 )
F_3 ( V_164 , L_59 , V_161 ) ;
return V_161 ;
}
void F_187 ( struct V_36 * V_39 , int V_204 )
{
struct V_3 * V_4 = & V_39 -> V_275 ;
if ( ! F_123 ( V_39 ) )
F_16 ( V_39 , V_4 ,
V_204 ? V_65 : V_64 ) ;
}
int V_29 ( struct V_276 * V_276 , int V_204 )
{
int V_60 ;
int V_1 = V_204 ? V_136 : V_137 ;
struct V_29 * V_108 = V_276 -> V_277 ;
struct V_36 * V_39 = F_46 ( V_276 -> V_278 ) ;
F_11 ( ! V_108 ) ;
if ( F_126 ( V_39 ) ) {
if ( V_204 )
return - V_211 ;
return 0 ;
}
if ( F_123 ( V_39 ) )
return 0 ;
V_60 = F_116 ( V_39 , & V_108 -> V_112 , V_1 , 0 , 0 ) ;
if ( V_60 < 0 )
F_113 ( V_60 ) ;
return V_60 ;
}
void F_188 ( struct V_276 * V_276 , int V_204 )
{
int V_1 = V_204 ? V_136 : V_137 ;
struct V_29 * V_108 = V_276 -> V_277 ;
struct V_36 * V_39 = F_46 ( V_276 -> V_278 ) ;
if ( ! F_126 ( V_39 ) && ! F_123 ( V_39 ) )
F_16 ( V_39 , & V_108 -> V_112 , V_1 ) ;
}
static void F_189 ( struct V_279 * V_279 )
{
struct V_49 * V_50 ;
V_50 = F_9 ( V_279 , struct V_49 , V_280 ) ;
F_190 ( V_50 ) ;
}
void F_191 ( struct V_49 * V_50 )
{
if ( V_50 )
F_192 ( & V_50 -> V_280 , F_189 ) ;
}
static void F_193 ( struct V_49 * V_281 )
{
F_194 ( & V_281 -> V_280 ) ;
}
struct V_49 * F_195 ( void )
{
struct V_49 * V_50 ;
V_50 = F_196 ( sizeof( struct V_49 ) , V_282 ) ;
if ( ! V_50 ) {
F_113 ( - V_283 ) ;
goto V_163;
}
F_197 ( & V_50 -> V_280 ) ;
F_42 ( & V_50 -> V_53 ) ;
V_50 -> V_284 = NULL ;
V_163:
return V_50 ;
}
static struct V_3 * F_198 ( struct V_3 * V_285 ,
struct V_286 * V_73 )
{
struct V_3 * V_287 , * V_60 = NULL ;
struct V_49 * V_50 = V_73 -> V_288 ;
F_68 ( & V_51 ) ;
F_199 (iter, &start->l_debug_list, l_debug_list) {
if ( & V_287 -> V_52 == & V_50 -> V_53 ) {
F_3 ( 0 , L_60 , V_60 ) ;
break;
}
if ( V_287 -> V_37 != NULL ) {
V_60 = V_287 ;
break;
}
}
return V_60 ;
}
static void * F_200 ( struct V_289 * V_290 , T_6 * V_291 )
{
struct V_286 * V_73 = V_290 -> V_292 ;
struct V_3 * V_287 ;
F_21 ( & V_51 ) ;
V_287 = F_198 ( & V_73 -> V_293 , V_73 ) ;
if ( V_287 ) {
V_73 -> V_294 = * V_287 ;
V_287 = & V_73 -> V_294 ;
}
F_23 ( & V_51 ) ;
return V_287 ;
}
static void F_201 ( struct V_289 * V_290 , void * V_295 )
{
}
static void * F_202 ( struct V_289 * V_290 , void * V_295 , T_6 * V_291 )
{
struct V_286 * V_73 = V_290 -> V_292 ;
struct V_3 * V_287 = V_295 ;
struct V_3 * V_296 = & V_73 -> V_293 ;
F_21 ( & V_51 ) ;
V_287 = F_198 ( V_287 , V_73 ) ;
F_26 ( & V_296 -> V_52 ) ;
if ( V_287 ) {
F_22 ( & V_296 -> V_52 , & V_287 -> V_52 ) ;
V_73 -> V_294 = * V_287 ;
V_287 = & V_73 -> V_294 ;
}
F_23 ( & V_51 ) ;
return V_287 ;
}
static int F_203 ( struct V_289 * V_290 , void * V_295 )
{
int V_297 ;
char * V_6 ;
struct V_3 * V_4 = V_295 ;
if ( ! V_4 )
return - V_217 ;
F_204 ( V_290 , L_61 , V_298 ) ;
if ( V_4 -> V_21 == V_30 )
F_204 ( V_290 , L_62 , V_107 - 1 ,
V_4 -> V_8 ,
( unsigned int ) F_50 ( V_4 ) ) ;
else
F_204 ( V_290 , L_63 , V_47 , V_4 -> V_8 ) ;
F_204 ( V_290 , L_64
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
for( V_297 = 0 ; V_297 < V_299 ; V_297 ++ )
F_204 ( V_290 , L_61 , V_6 [ V_297 ] ) ;
#ifdef F_205
# define F_206 ( T_7 ) ((_l)->l_lock_prmode.ls_gets)
# define F_207 ( T_7 ) ((_l)->l_lock_exmode.ls_gets)
# define F_208 ( T_7 ) ((_l)->l_lock_prmode.ls_fail)
# define F_209 ( T_7 ) ((_l)->l_lock_exmode.ls_fail)
# define F_210 ( T_7 ) ((_l)->l_lock_prmode.ls_total)
# define F_211 ( T_7 ) ((_l)->l_lock_exmode.ls_total)
# define F_212 ( T_7 ) ((_l)->l_lock_prmode.ls_max)
# define F_213 ( T_7 ) ((_l)->l_lock_exmode.ls_max)
# define F_214 ( T_7 ) ((_l)->l_lock_refresh)
#else
# define F_206 ( T_7 ) (0)
# define F_207 ( T_7 ) (0)
# define F_208 ( T_7 ) (0)
# define F_209 ( T_7 ) (0)
# define F_210 ( T_7 ) (0ULL)
# define F_211 ( T_7 ) (0ULL)
# define F_212 ( T_7 ) (0)
# define F_213 ( T_7 ) (0)
# define F_214 ( T_7 ) (0)
#endif
F_204 ( V_290 , L_66
L_66
L_66
L_66
L_67
L_67
L_66
L_66
L_66 ,
F_206 ( V_4 ) ,
F_207 ( V_4 ) ,
F_208 ( V_4 ) ,
F_209 ( V_4 ) ,
F_210 ( V_4 ) ,
F_211 ( V_4 ) ,
F_212 ( V_4 ) ,
F_213 ( V_4 ) ,
F_214 ( V_4 ) ) ;
F_204 ( V_290 , L_68 ) ;
return 0 ;
}
static int F_215 ( struct V_27 * V_27 , struct V_213 * V_213 )
{
struct V_289 * V_300 = V_213 -> V_215 ;
struct V_286 * V_73 = V_300 -> V_292 ;
struct V_3 * V_34 = & V_73 -> V_293 ;
F_24 ( V_34 ) ;
F_191 ( V_73 -> V_288 ) ;
return F_216 ( V_27 , V_213 ) ;
}
static int F_217 ( struct V_27 * V_27 , struct V_213 * V_213 )
{
int V_60 ;
struct V_286 * V_73 ;
struct V_289 * V_300 ;
struct V_36 * V_39 ;
V_73 = F_218 ( sizeof( struct V_286 ) , V_282 ) ;
if ( ! V_73 ) {
V_60 = - V_283 ;
F_113 ( V_60 ) ;
goto V_163;
}
V_39 = V_27 -> V_301 ;
F_193 ( V_39 -> V_84 ) ;
V_73 -> V_288 = V_39 -> V_84 ;
F_42 ( & V_73 -> V_293 . V_52 ) ;
V_60 = F_219 ( V_213 , & V_302 ) ;
if ( V_60 ) {
F_190 ( V_73 ) ;
F_113 ( V_60 ) ;
goto V_163;
}
V_300 = V_213 -> V_215 ;
V_300 -> V_292 = V_73 ;
F_20 ( & V_73 -> V_293 ,
V_73 -> V_288 ) ;
V_163:
return V_60 ;
}
static int F_220 ( struct V_36 * V_39 )
{
int V_60 = 0 ;
struct V_49 * V_50 = V_39 -> V_84 ;
V_50 -> V_284 = F_221 ( L_69 ,
V_303 | V_304 ,
V_39 -> V_305 ,
V_39 ,
& V_306 ) ;
if ( ! V_50 -> V_284 ) {
V_60 = - V_217 ;
F_3 ( V_164 ,
L_70 ) ;
goto V_163;
}
F_193 ( V_50 ) ;
V_163:
return V_60 ;
}
static void F_222 ( struct V_36 * V_39 )
{
struct V_49 * V_50 = V_39 -> V_84 ;
if ( V_50 ) {
F_223 ( V_50 -> V_284 ) ;
F_191 ( V_50 ) ;
}
}
int F_224 ( struct V_36 * V_39 )
{
int V_161 = 0 ;
struct V_307 * V_308 = NULL ;
if ( F_123 ( V_39 ) ) {
V_39 -> V_309 = 0 ;
goto V_205;
}
V_161 = F_220 ( V_39 ) ;
if ( V_161 < 0 ) {
F_113 ( V_161 ) ;
goto V_175;
}
V_39 -> V_310 = F_225 ( V_311 , V_39 , L_71 ) ;
if ( F_226 ( V_39 -> V_310 ) ) {
V_161 = F_227 ( V_39 -> V_310 ) ;
V_39 -> V_310 = NULL ;
F_113 ( V_161 ) ;
goto V_175;
}
V_161 = F_228 ( V_39 -> V_312 ,
V_39 -> V_313 ,
strlen ( V_39 -> V_313 ) ,
& V_170 , V_314 , V_39 ,
& V_308 ) ;
if ( V_161 ) {
F_113 ( V_161 ) ;
goto V_175;
}
V_161 = F_229 ( & V_39 -> V_309 ) ;
if ( V_161 < 0 ) {
F_113 ( V_161 ) ;
F_3 ( V_164 ,
L_72 ) ;
F_230 ( V_308 , 0 ) ;
goto V_175;
}
V_205:
F_54 ( & V_39 -> V_273 , V_39 ) ;
F_55 ( & V_39 -> V_274 , V_39 ) ;
F_56 ( & V_39 -> V_275 , V_39 ) ;
F_57 ( & V_39 -> V_268 . V_269 , V_39 ) ;
V_39 -> V_176 = V_308 ;
V_161 = 0 ;
V_175:
if ( V_161 < 0 ) {
F_222 ( V_39 ) ;
if ( V_39 -> V_310 )
F_231 ( V_39 -> V_310 ) ;
}
return V_161 ;
}
void F_232 ( struct V_36 * V_39 ,
int V_315 )
{
F_233 ( V_39 ) ;
if ( V_39 -> V_310 ) {
F_231 ( V_39 -> V_310 ) ;
V_39 -> V_310 = NULL ;
}
F_61 ( & V_39 -> V_273 ) ;
F_61 ( & V_39 -> V_274 ) ;
F_61 ( & V_39 -> V_275 ) ;
F_61 ( & V_39 -> V_268 . V_269 ) ;
F_230 ( V_39 -> V_176 , V_315 ) ;
V_39 -> V_176 = NULL ;
F_222 ( V_39 ) ;
}
static int F_234 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_60 ;
unsigned long V_152 ;
T_2 V_183 = 0 ;
if ( ! ( V_4 -> V_82 & V_83 ) )
goto V_163;
if ( V_4 -> V_37 -> V_152 & V_192 )
V_183 |= V_193 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_44 ( ! ( V_4 -> V_82 & V_198 ) ,
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
if ( V_4 -> V_37 -> V_152 & V_192 ) {
if ( V_4 -> V_82 & V_150 &&
V_4 -> V_74 == V_136 &&
! ( V_4 -> V_82 & V_154 ) )
V_4 -> V_37 -> V_316 ( V_4 ) ;
}
if ( V_4 -> V_82 & V_149 )
F_3 ( V_164 , L_76 ,
V_4 -> V_8 ) ;
if ( V_4 -> V_82 & V_151 )
F_3 ( 0 , L_77 , V_4 -> V_8 ) ;
if ( ! ( V_4 -> V_82 & V_150 ) ) {
F_81 ( & V_4 -> V_89 , V_152 ) ;
goto V_163;
}
F_72 ( V_4 , V_150 ) ;
F_11 ( V_4 -> V_78 != V_79 ) ;
F_71 ( V_4 , V_149 ) ;
V_4 -> V_80 = V_169 ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_3 ( 0 , L_78 , V_4 -> V_8 ) ;
V_60 = F_235 ( V_39 -> V_176 , & V_4 -> V_7 , V_183 ) ;
if ( V_60 ) {
F_95 ( L_79 , V_60 , V_4 ) ;
F_3 ( V_164 , L_80 , V_4 -> V_82 ) ;
F_236 ( & V_4 -> V_7 ) ;
F_64 () ;
}
F_3 ( 0 , L_81 ,
V_4 -> V_8 ) ;
F_97 ( V_4 ) ;
V_163:
return 0 ;
}
void F_237 ( struct V_3 * V_4 )
{
int V_161 ;
struct V_58 V_59 ;
unsigned long V_152 ;
F_101 ( & V_59 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_4 -> V_82 |= V_198 ;
while ( V_4 -> V_82 & V_317 ) {
F_106 ( V_4 , & V_59 , V_317 , 0 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_3 ( 0 , L_82 , V_4 -> V_8 ) ;
V_161 = F_103 ( & V_59 ) ;
if ( V_161 )
F_113 ( V_161 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
}
F_81 ( & V_4 -> V_89 , V_152 ) ;
}
void F_238 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_60 ;
F_237 ( V_4 ) ;
V_60 = F_234 ( V_39 , V_4 ) ;
if ( V_60 )
F_113 ( V_60 ) ;
}
static void F_233 ( struct V_36 * V_39 )
{
F_238 ( V_39 , & V_39 -> V_273 ) ;
F_238 ( V_39 , & V_39 -> V_274 ) ;
F_238 ( V_39 , & V_39 -> V_275 ) ;
F_238 ( V_39 , & V_39 -> V_268 . V_269 ) ;
}
int F_239 ( struct V_27 * V_27 )
{
int V_161 , V_318 ;
V_318 = F_234 ( F_46 ( V_27 -> V_97 ) ,
& F_45 ( V_27 ) -> V_209 ) ;
if ( V_318 < 0 )
F_113 ( V_318 ) ;
V_161 = V_318 ;
V_318 = F_234 ( F_46 ( V_27 -> V_97 ) ,
& F_45 ( V_27 ) -> V_208 ) ;
if ( V_318 < 0 )
F_113 ( V_318 ) ;
if ( V_318 < 0 && ! V_161 )
V_161 = V_318 ;
V_318 = F_234 ( F_46 ( V_27 -> V_97 ) ,
& F_45 ( V_27 ) -> V_207 ) ;
if ( V_318 < 0 )
F_113 ( V_318 ) ;
if ( V_318 < 0 && ! V_161 )
V_161 = V_318 ;
return V_161 ;
}
static unsigned int F_134 ( struct V_3 * V_4 ,
int V_138 )
{
F_68 ( & V_4 -> V_89 ) ;
F_11 ( V_4 -> V_77 <= V_139 ) ;
if ( V_4 -> V_74 <= V_138 ) {
F_3 ( V_164 , L_83
L_84
L_85 , V_4 -> V_8 , V_4 -> V_74 ,
V_138 , F_25 ( & V_4 -> V_91 ) ,
F_25 ( & V_4 -> V_92 ) , V_4 -> V_21 ,
V_4 -> V_82 , V_4 -> V_134 ,
V_4 -> V_135 , V_4 -> V_78 ,
V_4 -> V_80 , V_4 -> V_76 ,
V_4 -> V_77 , V_4 -> V_160 ) ;
F_64 () ;
}
F_3 ( V_158 , L_86 ,
V_4 -> V_8 , V_4 -> V_74 , V_138 , V_4 -> V_77 ) ;
V_4 -> V_78 = V_167 ;
V_4 -> V_76 = V_138 ;
F_71 ( V_4 , V_149 ) ;
return F_82 ( V_4 ) ;
}
static int F_135 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
int V_138 ,
int V_6 ,
unsigned int V_43 )
{
int V_60 ;
T_2 V_173 = V_201 ;
F_3 ( V_158 , L_87 , V_4 -> V_8 ,
V_4 -> V_74 , V_138 ) ;
if ( V_6 )
V_173 |= V_193 ;
V_60 = F_94 ( V_39 -> V_176 ,
V_138 ,
& V_4 -> V_7 ,
V_173 ,
V_4 -> V_8 ,
V_47 - 1 ) ;
F_79 ( V_4 , V_43 , V_39 ) ;
if ( V_60 ) {
F_95 ( L_30 , V_60 , V_4 ) ;
F_92 ( V_4 , 1 ) ;
goto V_175;
}
V_60 = 0 ;
V_175:
return V_60 ;
}
static int F_130 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
F_68 ( & V_4 -> V_89 ) ;
if ( V_4 -> V_80 == V_168 ) {
F_3 ( V_158 , L_88 , V_4 -> V_8 ) ;
return 0 ;
}
F_11 ( V_4 -> V_78 != V_166 &&
V_4 -> V_78 != V_167 ) ;
V_4 -> V_80 = V_168 ;
F_44 ( ! ( V_4 -> V_82 & V_149 ) ,
L_89 ,
V_4 -> V_8 , V_4 -> V_82 ) ;
F_3 ( V_158 , L_90 , V_4 -> V_8 ) ;
return 1 ;
}
static int F_131 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_60 ;
V_60 = F_235 ( V_39 -> V_176 , & V_4 -> V_7 ,
V_319 ) ;
if ( V_60 ) {
F_95 ( L_79 , V_60 , V_4 ) ;
F_92 ( V_4 , 0 ) ;
}
F_3 ( V_158 , L_90 , V_4 -> V_8 ) ;
return V_60 ;
}
static int F_240 ( struct V_36 * V_39 ,
struct V_3 * V_4 ,
struct V_320 * V_321 )
{
unsigned long V_152 ;
int V_322 ;
int V_138 ;
int V_1 ;
int V_60 = 0 ;
int V_316 = 0 ;
unsigned int V_174 ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_323:
if ( ! ( V_4 -> V_82 & V_151 ) ) {
F_11 ( V_4 -> V_77 != V_139 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = 0 ;
goto V_324;
}
if ( V_4 -> V_82 & V_149 ) {
if ( V_4 -> V_82 & V_159 ) {
F_3 ( V_158 , L_91 ,
V_4 -> V_8 ) ;
goto V_325;
}
V_321 -> V_326 = 1 ;
V_60 = F_130 ( V_39 , V_4 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
if ( V_60 ) {
V_60 = F_131 ( V_39 , V_4 ) ;
if ( V_60 < 0 )
F_113 ( V_60 ) ;
}
goto V_324;
}
if ( V_4 -> V_82 & V_155 )
goto V_325;
if ( V_4 -> V_74 == V_139 ) {
F_11 ( V_4 -> V_135 || V_4 -> V_134 ) ;
F_3 ( V_158 , L_92 , V_4 -> V_8 ) ;
V_4 -> V_77 = V_139 ;
F_72 ( V_4 , V_151 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
goto V_324;
}
if ( ( V_4 -> V_77 == V_136 )
&& ( V_4 -> V_135 || V_4 -> V_134 ) ) {
F_3 ( V_158 , L_93 ,
V_4 -> V_8 , V_4 -> V_135 ,
V_4 -> V_134 ) ;
goto V_325;
}
if ( V_4 -> V_77 == V_137 &&
V_4 -> V_135 ) {
F_3 ( V_158 , L_94 ,
V_4 -> V_8 , V_4 -> V_135 ) ;
goto V_325;
}
if ( ( V_4 -> V_37 -> V_152 & V_153 )
&& ( V_4 -> V_82 & V_178 ) ) {
F_3 ( V_158 , L_95 ,
V_4 -> V_8 ) ;
goto V_325;
}
V_138 = F_66 ( V_4 -> V_77 ) ;
if ( V_4 -> V_37 -> V_327
&& ! V_4 -> V_37 -> V_327 ( V_4 , V_138 ) ) {
F_3 ( V_158 , L_96 ,
V_4 -> V_8 ) ;
goto V_325;
}
if ( ! V_4 -> V_37 -> V_328 )
goto V_329;
V_322 = V_4 -> V_77 ;
V_1 = V_4 -> V_74 ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_321 -> V_330 = V_4 -> V_37 -> V_328 ( V_4 , V_322 ) ;
if ( V_321 -> V_330 == V_331 ) {
F_3 ( V_158 , L_97 ,
V_4 -> V_8 ) ;
goto V_324;
}
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( ( V_322 != V_4 -> V_77 ) || ( V_1 != V_4 -> V_74 ) ) {
F_3 ( V_158 , L_98
L_99 , V_4 -> V_8 , V_322 ,
V_4 -> V_77 , V_1 , V_4 -> V_74 ) ;
goto V_323;
}
V_329:
V_321 -> V_326 = 0 ;
if ( V_4 -> V_37 -> V_152 & V_192 ) {
if ( V_4 -> V_74 == V_136 )
V_316 = 1 ;
if ( V_316 && ! ( V_4 -> V_82 & V_154 ) )
V_4 -> V_37 -> V_316 ( V_4 ) ;
}
V_174 = F_134 ( V_4 , V_138 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_60 = F_135 ( V_39 , V_4 , V_138 , V_316 ,
V_174 ) ;
V_324:
if ( V_60 )
F_113 ( V_60 ) ;
return V_60 ;
V_325:
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_321 -> V_326 = 1 ;
return 0 ;
}
static int F_241 ( struct V_3 * V_4 ,
int V_322 )
{
struct V_27 * V_27 ;
struct V_332 * V_333 ;
struct V_123 * V_124 ;
V_27 = F_10 ( V_4 ) ;
V_333 = V_27 -> V_334 ;
if ( F_242 ( V_27 -> V_231 ) ) {
V_124 = F_45 ( V_27 ) ;
V_124 -> V_335 ++ ;
F_3 ( 0 , L_100 , V_124 -> V_335 ) ;
goto V_163;
}
if ( ! F_243 ( V_27 -> V_231 ) )
goto V_163;
F_244 ( V_333 , 0 , 0 , 0 ) ;
if ( F_245 ( V_333 ) ) {
F_3 ( V_164 , L_101 ,
( unsigned long long ) F_45 ( V_27 ) -> V_96 ) ;
}
F_246 ( V_333 ) ;
if ( V_322 == V_136 ) {
F_247 ( V_333 , 0 ) ;
} else {
F_248 ( V_333 ) ;
}
V_163:
return V_336 ;
}
static int F_249 ( struct V_337 * V_338 ,
struct V_3 * V_4 ,
int V_138 )
{
int V_339 = F_250 ( V_338 ) ;
F_11 ( V_138 != V_139 && V_138 != V_137 ) ;
F_11 ( V_4 -> V_74 != V_136 && ! V_339 ) ;
if ( V_339 )
return 1 ;
F_251 ( F_46 ( F_252 ( V_338 ) ) ) ;
return 0 ;
}
static int F_253 ( struct V_3 * V_4 ,
int V_138 )
{
struct V_27 * V_27 = F_10 ( V_4 ) ;
return F_249 ( F_159 ( V_27 ) , V_4 , V_138 ) ;
}
static void F_254 ( struct V_3 * V_4 )
{
struct V_27 * V_27 = F_10 ( V_4 ) ;
F_137 ( V_27 ) ;
}
static void F_255 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
struct V_29 * V_108 = F_12 ( V_4 ) ;
F_256 ( V_39 , V_108 ) ;
}
static int F_257 ( struct V_3 * V_4 ,
int V_322 )
{
struct V_29 * V_108 = F_12 ( V_4 ) ;
struct V_123 * V_124 = F_45 ( V_108 -> V_109 ) ;
struct V_276 * V_276 ;
unsigned long V_152 ;
int V_340 = 0 ;
if ( V_322 == V_137 )
return V_336 ;
F_21 ( & V_124 -> V_240 ) ;
V_124 -> V_227 |= V_341 ;
F_23 ( & V_124 -> V_240 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
F_21 ( & V_342 ) ;
if ( ! ( V_4 -> V_82 & V_198 )
&& V_108 -> V_343 ) {
V_108 -> V_343 ++ ;
V_340 = 1 ;
}
F_23 ( & V_342 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
F_3 ( 0 , L_102 , V_340 ) ;
if ( ! V_340 )
return V_336 ;
F_21 ( & V_342 ) ;
while ( 1 ) {
V_276 = F_258 ( V_108 -> V_109 ,
V_108 -> V_344 , 1 ) ;
if ( ! V_276 )
break;
F_23 ( & V_342 ) ;
F_3 ( 0 , L_103 , V_276 -> V_345 . V_45 ,
V_276 -> V_345 . V_44 ) ;
F_259 ( V_276 ) ;
F_260 ( V_276 ) ;
F_21 ( & V_342 ) ;
}
F_23 ( & V_342 ) ;
if ( V_108 -> V_343 == 1 )
return V_331 ;
return V_346 ;
}
static int F_261 ( struct V_3 * V_4 ,
int V_138 )
{
struct V_33 * V_347 =
F_14 ( V_4 ) ;
return F_249 ( & V_347 -> V_348 , V_4 , V_138 ) ;
}
static int F_262 ( struct V_3 * V_4 ,
int V_322 )
{
struct V_33 * V_347 =
F_14 ( V_4 ) ;
F_158 ( & V_347 -> V_348 ) ;
return V_336 ;
}
static void F_263 ( struct V_3 * V_4 )
{
struct V_349 * V_6 ;
struct V_31 * V_350 = F_13 ( V_4 ) ;
struct V_351 * V_98 = F_264 ( V_350 -> V_99 . V_100 ,
V_350 -> V_99 . V_129 ) ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
V_6 -> V_9 = V_352 ;
V_6 -> V_353 = F_139 ( V_98 -> V_354 ) ;
V_6 -> V_355 = F_139 ( V_98 -> V_356 ) ;
V_6 -> V_357 = F_139 ( V_350 -> V_358 ) ;
V_6 -> V_359 = F_139 ( V_350 -> V_99 . V_360 ) ;
V_6 -> V_361 = F_139 ( V_350 -> V_99 . V_362 ) ;
V_6 -> V_363 = F_139 ( V_350 -> V_99 . V_364 ) ;
}
void F_265 ( struct V_31 * V_350 , int V_204 )
{
struct V_3 * V_4 = & V_350 -> V_365 ;
struct V_36 * V_39 = F_46 ( V_350 -> V_99 . V_100 ) ;
int V_1 = V_204 ? V_136 : V_137 ;
if ( ! F_126 ( V_39 ) && ! F_123 ( V_39 ) )
F_16 ( V_39 , V_4 , V_1 ) ;
}
static int F_266 ( struct V_31 * V_350 )
{
struct V_351 * V_98 = F_264 ( V_350 -> V_99 . V_100 ,
V_350 -> V_99 . V_129 ) ;
struct V_3 * V_4 = & V_350 -> V_365 ;
struct V_349 * V_6 = F_2 ( & V_4 -> V_7 ) ;
struct V_243 * V_244 = NULL ;
struct V_366 * V_367 ;
int V_161 = 0 ;
if ( F_154 ( & V_4 -> V_7 ) &&
V_6 -> V_9 == V_352 ) {
V_98 -> V_354 = F_4 ( V_6 -> V_353 ) ;
V_98 -> V_356 = F_4 ( V_6 -> V_355 ) ;
V_350 -> V_358 = F_4 ( V_6 -> V_357 ) ;
V_350 -> V_99 . V_360 = F_4 ( V_6 -> V_359 ) ;
V_350 -> V_99 . V_362 = F_4 ( V_6 -> V_361 ) ;
V_350 -> V_99 . V_364 =
F_4 ( V_6 -> V_363 ) ;
} else {
V_161 = F_267 ( V_350 -> V_368 ,
V_350 -> V_369 , & V_244 ) ;
if ( V_161 ) {
F_113 ( V_161 ) ;
goto V_175;
}
V_367 = (struct V_366 * )
( V_244 -> V_249 + V_370 ) ;
V_98 -> V_354 = F_162 ( V_367 -> V_354 ) ;
V_98 -> V_356 = F_162 ( V_367 -> V_356 ) ;
V_350 -> V_358 = F_162 ( V_367 -> V_358 ) ;
V_350 -> V_99 . V_360 = F_162 ( V_367 -> V_360 ) ;
V_350 -> V_99 . V_362 = F_162 ( V_367 -> V_362 ) ;
V_350 -> V_99 . V_364 =
F_162 ( V_367 -> V_364 ) ;
F_170 ( V_244 ) ;
F_34 ( V_4 ) ;
}
V_175:
return V_161 ;
}
int F_268 ( struct V_31 * V_350 , int V_204 )
{
struct V_3 * V_4 = & V_350 -> V_365 ;
struct V_36 * V_39 = F_46 ( V_350 -> V_99 . V_100 ) ;
int V_1 = V_204 ? V_136 : V_137 ;
int V_161 = 0 ;
if ( F_126 ( V_39 ) ) {
if ( V_204 )
V_161 = - V_211 ;
goto V_175;
}
if ( F_123 ( V_39 ) )
goto V_175;
V_161 = F_116 ( V_39 , V_4 , V_1 , 0 , 0 ) ;
if ( V_161 < 0 ) {
F_113 ( V_161 ) ;
goto V_175;
}
if ( ! F_155 ( V_4 ) )
goto V_175;
V_161 = F_266 ( V_350 ) ;
if ( V_161 )
F_265 ( V_350 , V_204 ) ;
F_156 ( V_4 , V_161 ) ;
V_175:
return V_161 ;
}
int F_269 ( struct V_33 * V_371 , int V_204 )
{
int V_161 ;
int V_1 = V_204 ? V_136 : V_137 ;
struct V_3 * V_4 = & V_371 -> V_35 ;
struct V_36 * V_39 = V_4 -> V_28 ;
if ( F_126 ( V_39 ) )
return - V_211 ;
if ( F_123 ( V_39 ) )
return 0 ;
V_161 = F_116 ( V_39 , V_4 , V_1 , 0 , 0 ) ;
if ( V_161 < 0 )
F_113 ( V_161 ) ;
return V_161 ;
}
void F_270 ( struct V_33 * V_371 , int V_204 )
{
int V_1 = V_204 ? V_136 : V_137 ;
struct V_3 * V_4 = & V_371 -> V_35 ;
struct V_36 * V_39 = V_4 -> V_28 ;
if ( ! F_123 ( V_39 ) )
F_16 ( V_39 , V_4 , V_1 ) ;
}
static void F_271 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
int V_161 ;
struct V_320 V_321 = { 0 , 0 ,} ;
unsigned long V_152 ;
F_11 ( ! V_4 ) ;
F_11 ( ! V_4 -> V_37 ) ;
F_3 ( V_158 , L_104 , V_4 -> V_8 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
if ( V_4 -> V_82 & V_198 )
goto V_372;
F_81 ( & V_4 -> V_89 , V_152 ) ;
V_161 = F_240 ( V_39 , V_4 , & V_321 ) ;
if ( V_161 < 0 )
F_113 ( V_161 ) ;
F_80 ( & V_4 -> V_89 , V_152 ) ;
V_372:
if ( V_4 -> V_82 & V_198 || ! V_321 . V_326 ) {
F_72 ( V_4 , V_317 ) ;
} else
F_85 ( V_39 , V_4 ) ;
F_3 ( V_158 , L_105 , V_4 -> V_8 ,
V_321 . V_326 ? L_106 : L_107 ) ;
F_81 ( & V_4 -> V_89 , V_152 ) ;
if ( V_321 . V_330 != V_336
&& V_4 -> V_37 -> V_373 )
V_4 -> V_37 -> V_373 ( V_39 , V_4 ) ;
}
static void F_85 ( struct V_36 * V_39 ,
struct V_3 * V_4 )
{
unsigned long V_152 ;
F_68 ( & V_4 -> V_89 ) ;
if ( V_4 -> V_82 & V_198 ) {
F_3 ( V_158 , L_108 ,
V_4 -> V_8 , V_4 -> V_82 ) ;
return;
}
F_71 ( V_4 , V_317 ) ;
F_80 ( & V_39 -> V_374 , V_152 ) ;
if ( F_25 ( & V_4 -> V_91 ) ) {
F_107 ( & V_4 -> V_91 ,
& V_39 -> V_375 ) ;
V_39 -> V_376 ++ ;
}
F_81 ( & V_39 -> V_374 , V_152 ) ;
}
static void F_272 ( struct V_36 * V_39 )
{
unsigned long V_377 ;
unsigned long V_152 ;
struct V_3 * V_4 ;
F_80 ( & V_39 -> V_374 , V_152 ) ;
V_39 -> V_378 = V_39 -> V_379 ;
V_377 = V_39 -> V_376 ;
while ( V_377 ) {
F_11 ( F_25 ( & V_39 -> V_375 ) ) ;
V_4 = F_273 ( V_39 -> V_375 . V_380 ,
struct V_3 , V_91 ) ;
F_26 ( & V_4 -> V_91 ) ;
V_39 -> V_376 -- ;
F_81 ( & V_39 -> V_374 , V_152 ) ;
F_11 ( ! V_377 ) ;
V_377 -- ;
F_271 ( V_39 , V_4 ) ;
F_80 ( & V_39 -> V_374 , V_152 ) ;
}
F_81 ( & V_39 -> V_374 , V_152 ) ;
}
static int F_274 ( struct V_36 * V_39 )
{
int V_381 = 0 ;
unsigned long V_152 ;
F_80 ( & V_39 -> V_374 , V_152 ) ;
if ( F_25 ( & V_39 -> V_375 ) )
V_381 = 1 ;
F_81 ( & V_39 -> V_374 , V_152 ) ;
return V_381 ;
}
static int F_275 ( struct V_36 * V_39 )
{
int V_382 = 0 ;
unsigned long V_152 ;
F_80 ( & V_39 -> V_374 , V_152 ) ;
if ( V_39 -> V_378 != V_39 -> V_379 )
V_382 = 1 ;
F_81 ( & V_39 -> V_374 , V_152 ) ;
return V_382 ;
}
static int V_311 ( void * V_383 )
{
int V_161 = 0 ;
struct V_36 * V_39 = V_383 ;
while ( ! ( F_276 () &&
F_274 ( V_39 ) ) ) {
F_277 ( V_39 -> V_384 ,
F_275 ( V_39 ) ||
F_276 () ) ;
F_3 ( 0 , L_109 ) ;
F_272 ( V_39 ) ;
}
V_39 -> V_310 = NULL ;
return V_161 ;
}
void F_78 ( struct V_36 * V_39 )
{
unsigned long V_152 ;
F_80 ( & V_39 -> V_374 , V_152 ) ;
V_39 -> V_379 ++ ;
F_81 ( & V_39 -> V_374 , V_152 ) ;
F_86 ( & V_39 -> V_384 ) ;
}
