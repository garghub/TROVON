static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , 1 ) ;
F_3 ( V_2 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , 0 ) ;
F_5 ( V_2 ) ;
}
void F_6 ( struct V_4 * V_5 )
{
F_7 ( L_1 ) ;
F_1 ( V_5 -> V_6 -> V_7 ) ;
}
void F_8 ( struct V_4 * V_5 )
{
F_7 ( L_2 ) ;
F_4 ( V_5 -> V_6 -> V_7 ) ;
}
int F_9 ( struct V_1 * V_8 , T_1 V_9 )
{
struct V_4 * V_5 = F_10 ( V_8 ) ;
F_7 ( L_3 , V_10 , V_9 . V_11 ) ;
F_11 ( & V_5 -> V_6 -> V_12 ) ;
V_5 -> V_13 = V_5 -> V_14 ;
F_12 ( V_5 ) ;
if ( V_9 . V_11 == V_15 ) {
F_7 ( L_4 ) ;
V_5 -> V_16 = 0 ;
F_13 ( V_5 , V_17 ) ;
} else {
F_7 ( L_5 ) ;
F_13 ( V_5 , V_18 ) ;
}
F_14 ( & V_5 -> V_6 -> V_12 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_8 )
{
struct V_4 * V_5 = F_10 ( V_8 ) ;
F_7 ( L_6 , V_10 ) ;
if ( ! F_16 ( V_5 , V_17 ) || ! V_5 -> V_16 ) {
F_11 ( & V_5 -> V_6 -> V_12 ) ;
if ( V_5 -> V_19 . V_20 ) {
if ( F_17 ( V_5 ) <= 0 ) {
F_7 ( L_7 ) ;
F_18 ( V_5 , 1 ) ;
}
}
F_13 ( V_5 , V_21 ) ;
F_19 ( V_5 ) ;
F_20 ( V_5 ) ;
F_14 ( & V_5 -> V_6 -> V_12 ) ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_8 )
{
struct V_4 * V_5 = F_10 ( V_8 ) ;
F_7 ( L_6 , V_10 ) ;
F_11 ( & V_5 -> V_6 -> V_12 ) ;
F_13 ( V_5 , V_21 ) ;
if ( V_5 -> V_19 . V_20 )
F_18 ( V_5 , 1 ) ;
F_19 ( V_5 ) ;
F_20 ( V_5 ) ;
F_14 ( & V_5 -> V_6 -> V_12 ) ;
return 0 ;
}
void F_6 ( struct V_4 * V_5 )
{
}
void F_8 ( struct V_4 * V_5 )
{
}
int F_22 ( struct V_1 * V_8 )
{
struct V_4 * V_5 = F_10 ( V_8 ) ;
F_7 ( L_6 , V_10 ) ;
F_11 ( & V_5 -> V_6 -> V_12 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_8 )
{
struct V_4 * V_5 = F_10 ( V_8 ) ;
F_7 ( L_6 , V_10 ) ;
F_14 ( & V_5 -> V_6 -> V_12 ) ;
return 0 ;
}
static int F_24 ( void * V_22 )
{
struct V_4 * V_5 = (struct V_4 * ) V_22 ;
struct V_23 * V_24 = F_25 ( V_5 ) ;
for (; ; ) {
if ( F_26 ( & V_5 -> V_6 -> V_25 ) )
break;
if ( F_27 ( V_26 , & V_5 -> V_6 -> V_27 ) ) {
F_7 ( L_8 ) ;
break;
}
F_11 ( & ( V_5 -> V_6 -> V_12 ) ) ;
F_28 ( V_24 ) ;
if ( V_5 -> V_28 == NULL ) {
F_29 ( V_24 ) ;
F_14 ( & V_5 -> V_6 -> V_12 ) ;
F_7 ( L_9 ) ;
break;
}
if ( F_27 ( V_29 , & V_5 -> V_6 -> V_27 ) ) {
V_5 -> V_28 -> V_30 = V_31 << 16 ;
goto V_32;
}
F_29 ( V_24 ) ;
if ( V_5 -> V_28 -> V_33 == V_34 ) {
F_7 ( L_10 ) ;
V_5 -> V_28 -> V_30 = V_35 << 16 ;
}
else if ( V_5 -> V_28 -> V_36 -> V_37 ) {
F_7 ( L_11 ,
V_5 -> V_28 -> V_36 -> V_37 ,
V_5 -> V_28 -> V_36 -> V_38 ) ;
V_5 -> V_28 -> V_30 = V_39 << 16 ;
}
else if ( V_5 -> V_28 -> V_36 -> V_38 > V_5 -> V_40 ) {
F_7 ( L_12 ,
V_5 -> V_28 -> V_36 -> V_37 ,
V_5 -> V_28 -> V_36 -> V_38 ) ;
V_5 -> V_28 -> V_30 = V_39 << 16 ;
}
else {
F_30 ( F_31 ( V_5 -> V_28 ) ) ;
F_32 ( V_5 -> V_28 , V_5 ) ;
}
F_28 ( V_24 ) ;
if ( V_5 -> V_28 -> V_30 != V_31 << 16 )
V_5 -> V_28 -> V_41 ( V_5 -> V_28 ) ;
else
V_32 :
F_7 ( L_13 ) ;
if ( F_27 ( V_29 , & V_5 -> V_6 -> V_27 ) ) {
F_33 ( & ( V_5 -> V_6 -> V_42 ) ) ;
F_34 ( V_43 , & V_5 -> V_6 -> V_27 ) ;
F_34 ( V_29 , & V_5 -> V_6 -> V_27 ) ;
}
V_5 -> V_28 = NULL ;
F_29 ( V_24 ) ;
F_14 ( & V_5 -> V_6 -> V_12 ) ;
}
F_33 ( & V_5 -> V_6 -> V_44 ) ;
return 0 ;
}
static int F_35 ( void * V_22 )
{
struct V_4 * V_5 = (struct V_4 * ) V_22 ;
#ifdef F_36
F_37 ( ( V_45 + 5 ) * V_46 ) ;
#endif
for (; ; ) {
F_37 ( V_47 ) ;
if ( F_27 ( V_26 , & V_5 -> V_6 -> V_27 ) ) {
F_7 ( L_14 ) ;
break;
}
#ifdef F_38
if ( F_16 ( V_5 , V_17 ) ||
F_16 ( V_5 , V_48 ) ||
F_16 ( V_5 , V_18 ) ) {
continue;
}
if ( V_20 ) {
if ( F_16 ( V_5 , V_49 ) ) {
if ( V_5 -> V_50 <
( V_51 * 1000 / V_47 ) ) {
V_5 -> V_50 ++ ;
} else {
F_13 ( V_5 , V_48 ) ;
F_6 ( V_5 ) ;
continue;
}
} else {
V_5 -> V_50 = 0 ;
}
}
#endif
F_39 ( V_5 ) ;
F_11 ( & ( V_5 -> V_6 -> V_12 ) ) ;
F_40 ( V_5 ) ;
F_14 ( & V_5 -> V_6 -> V_12 ) ;
}
F_33 ( & V_5 -> V_6 -> V_52 ) ;
return 0 ;
}
static int F_41 ( void * V_22 )
{
struct V_4 * V_5 = (struct V_4 * ) V_22 ;
F_42 ( V_53
L_15 , V_5 -> V_6 -> V_54 -> V_55 ) ;
F_43 () ;
if ( V_45 > 0 ) {
F_42 ( V_53 L_16
L_17 ) ;
F_44 ( V_5 -> V_6 -> V_56 ,
F_27 ( V_57 ,
& V_5 -> V_6 -> V_27 ) ,
V_45 * V_46 ) ;
}
if ( ! F_27 ( V_57 , & V_5 -> V_6 -> V_27 ) ) {
F_45 ( F_25 ( V_5 ) ) ;
F_42 ( V_53 L_18 ) ;
}
F_46 ( & V_5 -> V_6 -> V_58 , 0 ) ;
}
static int F_47 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_59 * V_60 = V_5 -> V_6 ;
#ifdef F_48
int V_61 ;
#endif
V_60 -> V_54 = F_49 ( V_2 ) ;
V_60 -> V_7 = V_2 ;
V_60 -> V_62 = V_2 -> V_63 -> V_64 . V_65 ;
F_7 ( L_19 ,
F_50 ( V_60 -> V_54 -> V_66 . V_67 ) ,
F_50 ( V_60 -> V_54 -> V_66 . V_68 ) ,
F_50 ( V_60 -> V_54 -> V_66 . V_69 ) ) ;
F_7 ( L_20 ,
V_2 -> V_63 -> V_64 . V_70 ,
V_2 -> V_63 -> V_64 . V_71 ) ;
F_51 ( V_2 , V_5 ) ;
#ifdef F_48
V_61 = F_52 ( V_2 , & V_72 ) ;
if ( V_61 ) {
F_7 ( L_21 ) ;
F_51 ( V_2 , NULL ) ;
return - V_73 ;
}
#endif
V_60 -> V_74 = F_53 ( V_60 -> V_54 , sizeof( * V_60 -> V_74 ) ,
V_75 , & V_60 -> V_76 ) ;
if ( ! V_60 -> V_74 ) {
F_7 ( L_22 ) ;
F_51 ( V_2 , NULL ) ;
return - V_73 ;
}
V_60 -> V_77 = F_53 ( V_60 -> V_54 , V_78 ,
V_75 , & V_60 -> V_79 ) ;
if ( ! V_60 -> V_77 ) {
F_7 ( L_23 ) ;
F_51 ( V_2 , NULL ) ;
return - V_73 ;
}
return 0 ;
}
static void F_54 ( struct V_4 * V_5 )
{
struct V_80 * V_19 = & ( V_5 -> V_19 ) ;
V_19 -> V_81 = 7 ;
V_19 -> V_82 = 1 ;
V_19 -> V_83 = V_84 ;
V_19 -> V_85 = V_84 ;
V_19 -> V_86 = V_84 ;
V_19 -> V_87 = V_84 ;
V_19 -> V_88 = V_89 ;
V_19 -> V_90 = V_89 ;
V_19 -> V_91 = V_89 ;
V_19 -> V_92 = 98 ;
V_19 -> V_93 = 98 ;
V_19 -> V_94 = 98 ;
V_19 -> V_95 = 97 ;
V_19 -> V_96 = 95 ;
V_19 -> V_97 = 116 ;
V_19 -> V_98 = 77 ;
V_19 -> V_99 = 0 ;
V_19 -> V_100 = 1 ;
V_19 -> V_101 = 0 ;
V_19 -> V_102 =
V_103 | V_104 | V_105 ;
V_19 -> V_20 = V_20 ;
V_19 -> V_51 = V_51 ;
V_19 -> V_106 = V_106 ;
V_19 -> V_107 = V_107 ;
V_19 -> V_108 = 0 ;
V_19 -> V_109 = 800 ;
V_19 -> V_110 = 0 ;
V_19 -> V_111 = 50 ;
V_19 -> V_112 = 100 ;
V_19 -> V_113 = 0 ;
V_19 -> V_114 = 0 ;
V_19 -> V_115 = 1 ;
V_19 -> V_116 = 0 ;
V_19 -> V_117 = 1 ;
V_19 -> V_118 = 2 ;
V_19 -> V_119 = 100 ;
V_19 -> V_120 = 6 ;
V_19 -> V_121 = 0 ;
V_19 -> V_122 = 0 ;
V_19 -> V_123 = 0x01 ;
V_19 -> V_124 = 0x05 ;
V_19 -> V_125 = 0x09 ;
V_19 -> V_126 = 0x06 ;
V_19 -> V_127 = 0 ;
V_19 -> V_128 = 1 ;
V_19 -> V_129 = 0 ;
V_19 -> V_130 = 0 ;
V_19 -> V_131 = 1 ;
V_19 -> V_132 = 0 ;
}
static int F_55 ( struct V_4 * V_5 )
{
struct V_59 * V_60 = V_5 -> V_6 ;
struct V_133 * V_134 =
V_60 -> V_7 -> V_63 ;
int V_135 ;
struct V_136 * V_137 ;
struct V_136 * V_138 = NULL ;
struct V_136 * V_139 = NULL ;
struct V_136 * V_140 = NULL ;
for ( V_135 = 0 ; V_135 < V_134 -> V_64 . V_141 ; V_135 ++ ) {
V_137 = & V_134 -> V_142 [ V_135 ] . V_64 ;
if ( F_56 ( V_137 ) ) {
if ( F_57 ( V_137 ) ) {
if ( ! V_138 )
V_138 = V_137 ;
} else {
if ( ! V_139 )
V_139 = V_137 ;
}
}
else if ( F_58 ( V_137 ) ) {
if ( ! V_140 )
V_140 = V_137 ;
}
}
if ( ! V_138 || ! V_139 ) {
F_7 ( L_24
L_25 ) ;
return - V_143 ;
}
V_60 -> V_144 = F_59 ( V_60 -> V_54 , 0 ) ;
V_60 -> V_145 = F_60 ( V_60 -> V_54 , 0 ) ;
V_60 -> V_146 = F_61 ( V_60 -> V_54 ,
F_62 ( V_139 ) ) ;
V_60 -> V_147 = F_63 ( V_60 -> V_54 ,
F_62 ( V_138 ) ) ;
if ( V_140 ) {
V_60 -> V_148 = F_64 ( V_60 -> V_54 ,
F_62
( V_140 ) ) ;
V_60 -> V_149 = V_140 -> V_150 ;
}
return 0 ;
}
static int F_65 ( struct V_4 * V_5 )
{
struct V_59 * V_60 = V_5 -> V_6 ;
int V_61 ;
V_60 -> V_151 = F_66 ( 0 , V_75 ) ;
if ( ! V_60 -> V_151 ) {
F_7 ( L_26 ) ;
return - V_73 ;
}
V_60 -> V_152 = F_66 ( 0 , V_75 ) ;
if ( ! V_60 -> V_152 ) {
F_7 ( L_26 ) ;
return - V_73 ;
}
V_5 -> V_153 = V_5 -> V_154 = V_60 -> V_77 ;
F_54 ( V_5 ) ;
V_61 = F_19 ( V_5 ) ;
if ( V_61 != V_155 )
return - V_143 ;
return 0 ;
}
static void F_67 ( struct V_4 * V_5 )
{
F_7 ( L_27 , V_10 ) ;
F_7 ( L_28 ) ;
F_33 ( & V_5 -> V_6 -> V_25 ) ;
if ( V_5 -> V_6 -> V_156 )
F_68 ( & V_5 -> V_6 -> V_44 ) ;
if ( V_5 -> V_6 -> V_157 )
F_68 ( & V_5 -> V_6 -> V_52 ) ;
F_37 ( 200 ) ;
F_69 ( V_5 ) ;
F_70 ( V_5 -> V_6 -> V_151 ) ;
F_70 ( V_5 -> V_6 -> V_152 ) ;
}
static void F_71 ( struct V_4 * V_5 )
{
struct V_59 * V_60 = V_5 -> V_6 ;
F_7 ( L_27 , V_10 ) ;
if ( V_60 -> V_74 )
F_72 ( V_60 -> V_54 , sizeof( * V_60 -> V_74 ) ,
V_60 -> V_74 , V_60 -> V_76 ) ;
if ( V_60 -> V_77 )
F_72 ( V_60 -> V_54 , V_78 ,
V_60 -> V_77 , V_60 -> V_79 ) ;
F_51 ( V_60 -> V_7 , NULL ) ;
#ifdef F_48
F_73 ( V_60 -> V_7 , & V_72 ) ;
#endif
F_74 ( V_60 ) ;
V_5 -> V_6 = NULL ;
}
static void F_75 ( struct V_4 * V_5 )
{
struct V_59 * V_60 = V_5 -> V_6 ;
struct V_23 * V_24 = F_25 ( V_5 ) ;
if ( V_60 -> V_54 -> V_158 == V_159 )
F_76 ( V_26 , & V_60 -> V_27 ) ;
#ifdef F_36
F_76 ( V_57 , & V_60 -> V_27 ) ;
F_77 ( & V_60 -> V_56 ) ;
F_68 ( & V_60 -> V_58 ) ;
#endif
F_78 ( V_24 ) ;
F_28 ( V_24 ) ;
F_76 ( V_26 , & V_60 -> V_27 ) ;
F_29 ( V_24 ) ;
#ifdef F_36
F_77 ( & V_60 -> V_56 ) ;
#endif
}
static void F_79 ( struct V_4 * V_5 )
{
F_67 ( V_5 ) ;
F_71 ( V_5 ) ;
F_80 ( F_25 ( V_5 ) ) ;
}
static int F_81 ( struct V_1 * V_2 ,
const struct V_160 * V_37 )
{
struct V_23 * V_24 ;
struct V_4 * V_5 ;
struct V_59 * V_60 ;
int V_30 ;
struct V_161 * V_162 ;
F_7 ( L_29 , V_163 ) ;
V_60 = F_82 ( sizeof( struct V_59 ) , V_75 ) ;
if ( ! V_60 ) {
F_42 (KERN_WARNING RTS51X_TIP
L_30 ) ;
return - V_73 ;
}
V_24 = F_83 ( & V_164 , sizeof( * V_5 ) ) ;
if ( ! V_24 ) {
F_42 (KERN_WARNING RTS51X_TIP
L_31 ) ;
F_74 ( V_60 ) ;
return - V_73 ;
}
V_24 -> V_165 = 16 ;
V_5 = F_84 ( V_24 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_166 = V_37 -> V_67 ;
V_5 -> V_167 = V_37 -> V_68 ;
F_85 ( & ( V_60 -> V_12 ) ) ;
F_86 ( & V_60 -> V_25 ) ;
F_86 ( & V_60 -> V_44 ) ;
F_86 ( & V_60 -> V_52 ) ;
F_86 ( & ( V_60 -> V_42 ) ) ;
#ifdef F_36
F_87 ( & V_60 -> V_56 ) ;
F_86 ( & V_60 -> V_58 ) ;
#endif
V_5 -> V_6 = V_60 ;
V_30 = F_47 ( V_5 , V_2 ) ;
if ( V_30 )
goto V_168;
V_30 = F_55 ( V_5 ) ;
if ( V_30 )
goto V_168;
V_30 = F_65 ( V_5 ) ;
if ( V_30 )
goto V_168;
V_162 = F_88 ( F_24 , V_5 , V_169 ) ;
if ( F_89 ( V_162 ) ) {
F_42 (KERN_WARNING RTS51X_TIP
L_32 ) ;
V_30 = F_90 ( V_162 ) ;
goto V_168;
}
V_60 -> V_156 = V_162 ;
V_30 = F_91 ( F_25 ( V_5 ) , & V_60 -> V_7 -> V_170 ) ;
if ( V_30 ) {
F_42 (KERN_WARNING RTS51X_TIP L_33 ) ;
goto V_168;
}
#ifdef F_36
V_162 = F_92 ( F_41 , V_5 , V_171 ) ;
if ( F_89 ( V_162 ) ) {
F_42 (KERN_WARNING RTS51X_TIP
L_34 ) ;
F_33 ( & V_60 -> V_58 ) ;
F_75 ( V_5 ) ;
V_30 = F_90 ( V_162 ) ;
goto V_168;
}
F_93 ( V_162 ) ;
#else
F_45 ( F_25 ( V_5 ) ) ;
#endif
V_162 = F_88 ( F_35 , V_5 , V_172 ) ;
if ( F_89 ( V_162 ) ) {
F_42 (KERN_WARNING RTS51X_TIP
L_35 ) ;
V_30 = F_90 ( V_162 ) ;
goto V_168;
}
V_60 -> V_157 = V_162 ;
#ifdef F_38
if ( V_20 ) {
V_60 -> V_7 -> V_106 = V_106 ;
F_18 ( V_5 , 1 ) ;
F_7 ( L_36 , F_17 ( V_5 ) ) ;
}
#endif
return 0 ;
V_168:
F_7 ( L_37 ) ;
F_79 ( V_5 ) ;
return V_30 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) F_10 ( V_2 ) ;
F_7 ( L_38 ) ;
F_75 ( V_5 ) ;
F_79 ( V_5 ) ;
}
static int T_2 F_95 ( void )
{
int V_61 ;
F_42 ( V_173 L_39 ,
V_163 ) ;
V_61 = F_96 ( & V_174 ) ;
if ( V_61 == 0 ) {
F_42 ( V_173
L_40 ,
V_163 ) ;
}
return V_61 ;
}
static void T_3 F_97 ( void )
{
F_7 ( L_41 ) ;
F_7 ( L_42 ) ;
F_98 ( & V_174 ) ;
}
