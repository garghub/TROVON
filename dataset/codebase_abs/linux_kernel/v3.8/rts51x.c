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
static void F_6 ( struct V_4 * V_5 )
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
static void F_6 ( struct V_4 * V_5 )
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
for (; ; ) {
F_36 ( V_45 ) ;
if ( F_27 ( V_26 , & V_5 -> V_6 -> V_27 ) ) {
F_7 ( L_14 ) ;
break;
}
#ifdef F_37
if ( F_16 ( V_5 , V_17 ) ||
F_16 ( V_5 , V_46 ) ||
F_16 ( V_5 , V_18 ) ) {
continue;
}
if ( V_20 ) {
if ( F_16 ( V_5 , V_47 ) ) {
if ( V_5 -> V_48 <
( V_49 * 1000 / V_45 ) ) {
V_5 -> V_48 ++ ;
} else {
F_13 ( V_5 , V_46 ) ;
F_6 ( V_5 ) ;
continue;
}
} else {
V_5 -> V_48 = 0 ;
}
}
#endif
F_38 ( V_5 ) ;
F_11 ( & ( V_5 -> V_6 -> V_12 ) ) ;
F_39 ( V_5 ) ;
F_14 ( & V_5 -> V_6 -> V_12 ) ;
}
F_33 ( & V_5 -> V_6 -> V_50 ) ;
return 0 ;
}
static int F_40 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_51 * V_52 = V_5 -> V_6 ;
#ifdef F_41
int V_53 ;
#endif
V_52 -> V_54 = F_42 ( V_2 ) ;
V_52 -> V_7 = V_2 ;
V_52 -> V_55 = V_2 -> V_56 -> V_57 . V_58 ;
F_7 ( L_15 ,
F_43 ( V_52 -> V_54 -> V_59 . V_60 ) ,
F_43 ( V_52 -> V_54 -> V_59 . V_61 ) ,
F_43 ( V_52 -> V_54 -> V_59 . V_62 ) ) ;
F_7 ( L_16 ,
V_2 -> V_56 -> V_57 . V_63 ,
V_2 -> V_56 -> V_57 . V_64 ) ;
F_44 ( V_2 , V_5 ) ;
#ifdef F_41
V_53 = F_45 ( V_2 , & V_65 ) ;
if ( V_53 ) {
F_7 ( L_17 ) ;
F_44 ( V_2 , NULL ) ;
return - V_66 ;
}
#endif
V_52 -> V_67 = F_46 ( V_52 -> V_54 , sizeof( * V_52 -> V_67 ) ,
V_68 , & V_52 -> V_69 ) ;
if ( ! V_52 -> V_67 ) {
F_7 ( L_18 ) ;
F_44 ( V_2 , NULL ) ;
return - V_66 ;
}
V_52 -> V_70 = F_46 ( V_52 -> V_54 , V_71 ,
V_68 , & V_52 -> V_72 ) ;
if ( ! V_52 -> V_70 ) {
F_7 ( L_19 ) ;
F_44 ( V_2 , NULL ) ;
return - V_66 ;
}
return 0 ;
}
static void F_47 ( struct V_4 * V_5 )
{
struct V_73 * V_19 = & ( V_5 -> V_19 ) ;
V_19 -> V_74 = 1 ;
V_19 -> V_75 = V_76 ;
V_19 -> V_77 = V_76 ;
V_19 -> V_78 = V_76 ;
V_19 -> V_79 = V_76 ;
V_19 -> V_80 = V_81 ;
V_19 -> V_82 = V_81 ;
V_19 -> V_83 = V_81 ;
V_19 -> V_84 = 98 ;
V_19 -> V_85 = 98 ;
V_19 -> V_86 = 98 ;
V_19 -> V_87 = 97 ;
V_19 -> V_88 = 95 ;
V_19 -> V_89 = 116 ;
V_19 -> V_90 = 77 ;
V_19 -> V_91 = 0 ;
V_19 -> V_92 = 1 ;
V_19 -> V_93 = 0 ;
V_19 -> V_94 =
V_95 | V_96 | V_97 ;
V_19 -> V_20 = V_20 ;
V_19 -> V_49 = V_49 ;
V_19 -> V_98 = V_98 ;
V_19 -> V_99 = 0 ;
V_19 -> V_100 = 800 ;
V_19 -> V_101 = 0 ;
V_19 -> V_102 = 50 ;
V_19 -> V_103 = 100 ;
V_19 -> V_104 = 0 ;
V_19 -> V_105 = 0 ;
V_19 -> V_106 = 1 ;
V_19 -> V_107 = 2 ;
V_19 -> V_108 = 6 ;
V_19 -> V_109 = 0 ;
V_19 -> V_110 = 0 ;
V_19 -> V_111 = 0x01 ;
V_19 -> V_112 = 0x05 ;
V_19 -> V_113 = 0x09 ;
V_19 -> V_114 = 0x06 ;
V_19 -> V_115 = 0 ;
V_19 -> V_116 = 1 ;
V_19 -> V_117 = 0 ;
V_19 -> V_118 = 0 ;
V_19 -> V_119 = 1 ;
V_19 -> V_120 = 0 ;
}
static int F_48 ( struct V_4 * V_5 )
{
struct V_51 * V_52 = V_5 -> V_6 ;
struct V_121 * V_122 =
V_52 -> V_7 -> V_56 ;
int V_123 ;
struct V_124 * V_125 ;
struct V_124 * V_126 = NULL ;
struct V_124 * V_127 = NULL ;
struct V_124 * V_128 = NULL ;
for ( V_123 = 0 ; V_123 < V_122 -> V_57 . V_129 ; V_123 ++ ) {
V_125 = & V_122 -> V_130 [ V_123 ] . V_57 ;
if ( F_49 ( V_125 ) ) {
if ( F_50 ( V_125 ) ) {
if ( ! V_126 )
V_126 = V_125 ;
} else {
if ( ! V_127 )
V_127 = V_125 ;
}
}
else if ( F_51 ( V_125 ) ) {
if ( ! V_128 )
V_128 = V_125 ;
}
}
if ( ! V_126 || ! V_127 ) {
F_7 ( L_20
L_21 ) ;
return - V_131 ;
}
V_52 -> V_132 = F_52 ( V_52 -> V_54 , 0 ) ;
V_52 -> V_133 = F_53 ( V_52 -> V_54 , 0 ) ;
V_52 -> V_134 = F_54 ( V_52 -> V_54 ,
F_55 ( V_127 ) ) ;
V_52 -> V_135 = F_56 ( V_52 -> V_54 ,
F_55 ( V_126 ) ) ;
if ( V_128 ) {
V_52 -> V_136 = F_57 ( V_52 -> V_54 ,
F_55
( V_128 ) ) ;
V_52 -> V_137 = V_128 -> V_138 ;
}
return 0 ;
}
static int F_58 ( struct V_4 * V_5 )
{
struct V_51 * V_52 = V_5 -> V_6 ;
int V_53 ;
V_52 -> V_139 = F_59 ( 0 , V_68 ) ;
if ( ! V_52 -> V_139 ) {
F_7 ( L_22 ) ;
return - V_66 ;
}
V_52 -> V_140 = F_59 ( 0 , V_68 ) ;
if ( ! V_52 -> V_140 ) {
F_7 ( L_22 ) ;
return - V_66 ;
}
V_5 -> V_141 = V_5 -> V_142 = V_52 -> V_70 ;
F_47 ( V_5 ) ;
V_53 = F_19 ( V_5 ) ;
if ( V_53 != V_143 )
return - V_131 ;
return 0 ;
}
static void F_60 ( struct V_4 * V_5 )
{
F_7 ( L_23 , V_10 ) ;
F_7 ( L_24 ) ;
F_33 ( & V_5 -> V_6 -> V_25 ) ;
if ( V_5 -> V_6 -> V_144 )
F_61 ( & V_5 -> V_6 -> V_44 ) ;
if ( V_5 -> V_6 -> V_145 )
F_61 ( & V_5 -> V_6 -> V_50 ) ;
F_36 ( 200 ) ;
F_62 ( V_5 ) ;
F_63 ( V_5 -> V_6 -> V_139 ) ;
F_63 ( V_5 -> V_6 -> V_140 ) ;
}
static void F_64 ( struct V_4 * V_5 )
{
struct V_51 * V_52 = V_5 -> V_6 ;
F_7 ( L_23 , V_10 ) ;
if ( V_52 -> V_67 )
F_65 ( V_52 -> V_54 , sizeof( * V_52 -> V_67 ) ,
V_52 -> V_67 , V_52 -> V_69 ) ;
if ( V_52 -> V_70 )
F_65 ( V_52 -> V_54 , V_71 ,
V_52 -> V_70 , V_52 -> V_72 ) ;
F_44 ( V_52 -> V_7 , NULL ) ;
#ifdef F_41
F_66 ( V_52 -> V_7 , & V_65 ) ;
#endif
F_67 ( V_52 ) ;
V_5 -> V_6 = NULL ;
}
static void F_68 ( struct V_4 * V_5 )
{
struct V_51 * V_52 = V_5 -> V_6 ;
struct V_23 * V_24 = F_25 ( V_5 ) ;
if ( V_52 -> V_54 -> V_146 == V_147 )
F_69 ( V_26 , & V_52 -> V_27 ) ;
F_70 ( V_24 ) ;
F_28 ( V_24 ) ;
F_69 ( V_26 , & V_52 -> V_27 ) ;
F_29 ( V_24 ) ;
}
static void F_71 ( struct V_4 * V_5 )
{
F_60 ( V_5 ) ;
F_64 ( V_5 ) ;
F_72 ( F_25 ( V_5 ) ) ;
}
static int F_73 ( struct V_1 * V_2 ,
const struct V_148 * V_37 )
{
struct V_23 * V_24 ;
struct V_4 * V_5 ;
struct V_51 * V_52 ;
int V_30 ;
struct V_149 * V_150 ;
F_7 ( L_25 , V_151 ) ;
V_52 = F_74 ( sizeof( struct V_51 ) , V_68 ) ;
if ( ! V_52 ) {
F_75 (KERN_WARNING RTS51X_TIP
L_26 ) ;
return - V_66 ;
}
V_24 = F_76 ( & V_152 , sizeof( * V_5 ) ) ;
if ( ! V_24 ) {
F_75 (KERN_WARNING RTS51X_TIP
L_27 ) ;
F_67 ( V_52 ) ;
return - V_66 ;
}
V_24 -> V_153 = 16 ;
V_5 = F_77 ( V_24 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_154 = V_37 -> V_60 ;
V_5 -> V_155 = V_37 -> V_61 ;
F_78 ( & ( V_52 -> V_12 ) ) ;
F_79 ( & V_52 -> V_25 ) ;
F_79 ( & V_52 -> V_44 ) ;
F_79 ( & V_52 -> V_50 ) ;
F_79 ( & ( V_52 -> V_42 ) ) ;
V_5 -> V_6 = V_52 ;
V_30 = F_40 ( V_5 , V_2 ) ;
if ( V_30 )
goto V_156;
V_30 = F_48 ( V_5 ) ;
if ( V_30 )
goto V_156;
V_30 = F_58 ( V_5 ) ;
if ( V_30 )
goto V_156;
V_150 = F_80 ( F_24 , V_5 , V_157 ) ;
if ( F_81 ( V_150 ) ) {
F_75 (KERN_WARNING RTS51X_TIP
L_28 ) ;
V_30 = F_82 ( V_150 ) ;
goto V_156;
}
V_52 -> V_144 = V_150 ;
V_30 = F_83 ( F_25 ( V_5 ) , & V_52 -> V_7 -> V_158 ) ;
if ( V_30 ) {
F_75 (KERN_WARNING RTS51X_TIP L_29 ) ;
goto V_156;
}
F_84 ( F_25 ( V_5 ) ) ;
V_150 = F_80 ( F_35 , V_5 , V_159 ) ;
if ( F_81 ( V_150 ) ) {
F_75 (KERN_WARNING RTS51X_TIP
L_30 ) ;
V_30 = F_82 ( V_150 ) ;
goto V_156;
}
V_52 -> V_145 = V_150 ;
#ifdef F_37
if ( V_20 ) {
V_52 -> V_7 -> V_160 = V_160 ;
F_18 ( V_5 , 1 ) ;
F_7 ( L_31 , F_17 ( V_5 ) ) ;
}
#endif
return 0 ;
V_156:
F_7 ( L_32 ) ;
F_71 ( V_5 ) ;
return V_30 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) F_10 ( V_2 ) ;
F_7 ( L_33 ) ;
F_68 ( V_5 ) ;
F_71 ( V_5 ) ;
}
