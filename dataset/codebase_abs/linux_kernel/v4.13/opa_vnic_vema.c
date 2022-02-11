static inline T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_4 ) & 0xff ;
}
static inline struct V_5 *
F_3 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_8 = F_1 ( V_2 ) ;
return F_4 ( & V_7 -> V_9 , V_8 ) ;
}
static inline bool F_5 ( struct V_10 * V_11 )
{
T_2 V_12 , V_13 ;
T_2 V_14 = ( ( V_15 - sizeof( * V_11 ) ) /
sizeof( V_11 -> V_16 [ 0 ] ) ) ;
V_12 = F_6 ( V_11 -> V_12 ) ;
V_13 = F_6 ( V_11 -> V_13 ) ;
return ( ( V_13 <= V_14 ) &&
( V_12 + V_13 <= V_17 ) ) ;
}
static inline void F_7 ( struct V_18 * V_19 )
{
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_20 . V_21 =
F_8 ( V_17 ) ;
V_19 -> V_20 . V_22 =
F_8 ( V_23 ) ;
V_19 -> V_20 . V_24 = V_25 ;
V_19 -> V_20 . V_26 = V_25 ;
}
static struct V_5 * F_9 ( struct V_6 * V_7 ,
T_1 V_8 )
{
struct V_27 * V_28 = V_7 -> V_28 ;
struct V_5 * V_29 ;
V_29 = F_10 ( V_28 -> V_30 , V_7 -> V_31 , V_8 ) ;
if ( ! F_11 ( V_29 ) ) {
int V_32 ;
V_29 -> V_28 = V_28 ;
V_32 = F_12 ( & V_7 -> V_9 , V_29 , V_8 ,
V_8 + 1 , V_33 ) ;
if ( V_32 < 0 ) {
F_13 ( V_29 ) ;
V_29 = F_14 ( V_32 ) ;
}
}
return V_29 ;
}
static void F_15 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_1 * V_34 )
{
struct V_35 * V_19 ;
V_19 = (struct V_35 * ) V_34 -> V_36 ;
memcpy ( V_19 , & V_7 -> V_37 , sizeof( * V_19 ) ) ;
V_19 -> V_38 = V_39 ,
V_19 -> V_40 = V_41 ;
V_19 -> V_42 = F_8 ( ( V_43 |
( V_44 << 8 ) ) ) ;
V_19 -> V_45 = F_16 ( 18 ) ;
}
static void F_17 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_1 * V_34 )
{
memcpy ( & V_7 -> V_37 , V_2 -> V_36 ,
sizeof( V_7 -> V_37 ) ) ;
F_15 ( V_7 , V_2 , V_34 ) ;
}
static void F_18 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_1 * V_34 )
{
struct V_18 * V_19 =
(struct V_18 * ) V_34 -> V_36 ;
struct V_5 * V_29 ;
V_29 = F_3 ( V_2 , V_7 ) ;
if ( V_29 ) {
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_19 ( V_29 , & V_19 -> V_46 ) ;
F_20 ( V_29 ,
& V_19 -> V_20 ) ;
} else {
F_7 ( V_19 ) ;
}
}
static void F_21 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_1 * V_34 )
{
struct V_27 * V_28 = V_7 -> V_28 ;
struct V_18 * V_19 ;
struct V_5 * V_29 ;
T_1 V_8 ;
V_8 = F_1 ( V_2 ) ;
V_29 = F_3 ( V_2 , V_7 ) ;
if ( ! V_29 ) {
V_29 = F_9 ( V_7 , V_8 ) ;
if ( F_11 ( V_29 ) ) {
F_22 ( L_1 ,
V_8 , F_23 ( V_29 ) ) ;
goto V_47;
}
}
V_19 = (struct V_18 * ) V_2 -> V_36 ;
F_24 ( V_29 , & V_19 -> V_46 ) ;
F_25 ( V_29 , & V_19 -> V_20 ) ;
F_26 ( V_29 ) ;
F_18 ( V_7 , V_2 , V_34 ) ;
return;
V_47:
V_34 -> V_3 . V_48 = V_49 ;
}
static void F_27 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_1 * V_34 )
{
struct V_10 * V_50 , * V_51 ;
struct V_5 * V_29 ;
V_29 = F_3 ( V_2 , V_7 ) ;
if ( ! V_29 ) {
V_34 -> V_3 . V_48 = V_49 ;
return;
}
V_50 = (struct V_10 * ) V_2 -> V_36 ;
V_51 = (struct V_10 * ) V_34 -> V_36 ;
if ( F_5 ( V_50 ) ) {
V_51 -> V_12 = V_50 -> V_12 ;
V_51 -> V_13 = V_50 -> V_13 ;
F_28 ( V_29 , V_51 ) ;
} else {
V_34 -> V_3 . V_48 = V_49 ;
}
}
static void F_29 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_1 * V_34 )
{
struct V_10 * V_11 ;
struct V_5 * V_29 ;
V_29 = F_3 ( V_2 , V_7 ) ;
if ( ! V_29 ) {
V_34 -> V_3 . V_48 = V_49 ;
return;
}
V_11 = (struct V_10 * ) V_2 -> V_36 ;
if ( F_5 ( V_11 ) ) {
if ( F_30 ( V_29 , V_11 ) )
V_34 -> V_3 . V_48 = V_52 ;
} else {
V_34 -> V_3 . V_48 = V_52 ;
}
F_27 ( V_7 , V_2 , V_34 ) ;
}
static void F_31 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_1 * V_34 )
{
struct V_18 * V_19 =
(struct V_18 * ) V_34 -> V_36 ;
struct V_5 * V_29 ;
V_29 = F_3 ( V_2 , V_7 ) ;
if ( ! V_29 ) {
V_34 -> V_3 . V_48 = V_49 ;
return;
}
F_7 ( V_19 ) ;
F_24 ( V_29 , & V_19 -> V_46 ) ;
F_25 ( V_29 , & V_19 -> V_20 ) ;
F_26 ( V_29 ) ;
F_32 ( V_29 ) ;
F_18 ( V_7 , V_2 , V_34 ) ;
}
static void F_33 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_1 * V_34 ,
T_2 V_53 )
{
struct V_54 * V_55 , * V_56 ;
int V_57 = ( V_15 - sizeof( * V_56 ) ) / V_58 ;
struct V_5 * V_29 ;
V_29 = F_3 ( V_2 , V_7 ) ;
if ( ! V_29 ) {
V_34 -> V_3 . V_48 = V_49 ;
return;
}
V_55 = (struct V_54 * ) V_2 -> V_36 ;
V_56 = (struct V_54 * ) V_34 -> V_36 ;
V_56 -> V_59 = V_55 -> V_59 ;
if ( V_55 -> V_60 )
V_56 -> V_60 = V_55 -> V_60 ;
else
V_56 -> V_60 = F_8 ( V_57 ) ;
if ( V_53 == V_61 )
F_34 ( V_29 , V_56 ) ;
else
F_35 ( V_29 , V_56 ) ;
}
static void F_36 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_1 * V_34 )
{
struct V_62 * V_63 ;
struct V_5 * V_29 ;
V_29 = F_3 ( V_2 , V_7 ) ;
if ( V_29 ) {
V_63 = (struct V_62 * ) V_34 -> V_36 ;
F_37 ( V_29 , V_63 ) ;
} else {
V_34 -> V_3 . V_48 = V_49 ;
}
}
static void F_38 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_1 * V_34 )
{
struct V_64 * V_63 ;
struct V_5 * V_29 ;
V_29 = F_3 ( V_2 , V_7 ) ;
if ( V_29 ) {
V_63 = (struct V_64 * ) V_34 -> V_36 ;
F_39 ( V_29 , V_63 ) ;
} else {
V_34 -> V_3 . V_48 = V_49 ;
}
}
static void F_40 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_1 * V_34 )
{
T_2 V_53 = F_6 ( V_2 -> V_3 . V_53 ) ;
switch ( V_53 ) {
case V_65 :
F_15 ( V_7 , V_2 , V_34 ) ;
break;
case V_66 :
F_18 ( V_7 , V_2 , V_34 ) ;
break;
case V_67 :
F_27 ( V_7 , V_2 , V_34 ) ;
break;
case V_68 :
case V_61 :
F_33 ( V_7 , V_2 , V_34 , V_53 ) ;
break;
case V_69 :
F_36 ( V_7 , V_2 , V_34 ) ;
break;
case V_70 :
F_38 ( V_7 , V_2 , V_34 ) ;
break;
default:
V_34 -> V_3 . V_48 = V_52 ;
break;
}
}
static void F_41 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_1 * V_34 )
{
T_2 V_53 = F_6 ( V_2 -> V_3 . V_53 ) ;
switch ( V_53 ) {
case V_65 :
F_17 ( V_7 , V_2 , V_34 ) ;
break;
case V_66 :
F_21 ( V_7 , V_2 , V_34 ) ;
break;
case V_67 :
F_29 ( V_7 , V_2 , V_34 ) ;
break;
case V_71 :
F_31 ( V_7 , V_2 , V_34 ) ;
break;
default:
V_34 -> V_3 . V_48 = V_52 ;
break;
}
}
static void F_42 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
F_43 ( V_75 -> V_76 -> V_77 ) ;
F_44 ( V_75 -> V_76 ) ;
}
static void F_45 ( struct V_72 * V_73 ,
struct V_78 * V_76 ,
struct V_79 * V_75 )
{
struct V_6 * V_7 ;
struct V_80 * V_77 ;
struct V_78 * V_81 ;
struct V_1 * V_82 ;
if ( ! V_75 || ! V_75 -> V_83 . V_84 )
return;
V_7 = V_73 -> V_85 ;
V_77 = F_46 ( V_73 -> V_86 -> V_87 , V_75 -> V_88 ,
V_75 -> V_83 . V_89 , V_73 -> V_31 ) ;
if ( F_11 ( V_77 ) )
goto V_90;
V_81 = F_47 ( V_73 , V_75 -> V_88 -> V_91 ,
V_75 -> V_88 -> V_92 , 0 ,
V_93 , V_15 ,
V_94 , V_39 ) ;
if ( F_11 ( V_81 ) )
goto V_95;
V_81 -> V_77 = V_77 ;
V_82 = V_81 -> V_84 ;
memcpy ( V_82 , V_75 -> V_83 . V_84 , V_93 ) ;
V_82 -> V_3 . V_96 = V_97 ;
V_82 -> V_3 . V_48 = 0 ;
F_48 ( & V_7 -> V_98 ) ;
switch ( V_75 -> V_83 . V_84 -> V_3 . V_96 ) {
case V_99 :
F_40 ( V_7 , (struct V_1 * ) V_75 -> V_83 . V_84 ,
V_82 ) ;
break;
case V_100 :
F_41 ( V_7 , (struct V_1 * ) V_75 -> V_83 . V_84 ,
V_82 ) ;
break;
default:
V_82 -> V_3 . V_48 = V_52 ;
break;
}
F_49 ( & V_7 -> V_98 ) ;
if ( ! F_50 ( V_81 , NULL ) ) {
goto V_90;
}
F_44 ( V_81 ) ;
V_95:
F_43 ( V_77 ) ;
V_90:
F_51 ( V_75 ) ;
}
static struct V_6 *
F_52 ( struct V_27 * V_28 , T_1 V_31 )
{
struct V_6 * V_7 = ( void * ) V_28 + sizeof( * V_28 ) ;
if ( V_31 > V_28 -> V_101 )
return NULL ;
return V_7 + ( V_31 - 1 ) ;
}
void F_53 ( struct V_5 * V_29 ,
struct V_102 * V_36 , T_3 V_103 )
{
struct V_27 * V_28 = V_29 -> V_28 ;
struct V_78 * V_76 ;
struct V_6 * V_7 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_35 * V_108 ;
struct V_109 V_110 ;
struct V_80 * V_77 ;
struct V_111 * V_112 ;
T_3 V_113 ;
T_2 V_114 ;
if ( ! V_28 )
goto V_47;
V_105 = V_28 -> V_30 ;
V_7 = F_52 ( V_28 , V_36 -> V_115 ) ;
if ( ! V_7 || ! V_7 -> V_73 )
goto V_47;
if ( F_54 ( V_116 , V_29 -> V_117 ) ) {
if ( V_29 -> V_118 == V_119 ) {
F_55 ( L_2 ) ;
goto V_47;
} else {
V_29 -> V_118 ++ ;
}
} else {
V_29 -> V_118 = 0 ;
}
V_108 = & V_7 -> V_37 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . type = F_56 ( V_105 , V_7 -> V_31 ) ;
F_57 ( & V_110 ,
F_58 ( V_108 -> V_120 ) ) ;
F_59 ( & V_110 , V_7 -> V_31 ) ;
V_113 = F_2 ( V_108 -> V_113 ) ;
if ( ! V_113 ) {
F_22 ( L_3 , V_121 ) ;
goto V_47;
}
F_60 ( & V_110 , V_113 ) ;
V_77 = F_61 ( V_7 -> V_73 -> V_86 -> V_87 , & V_110 ) ;
if ( F_11 ( V_77 ) ) {
F_22 ( L_4 , V_121 , V_77 ) ;
F_22 ( L_5 , V_121 ,
F_62 ( & V_110 ) , F_63 ( & V_110 ) ,
F_64 ( & V_110 ) ) ;
goto V_47;
}
if ( F_65 ( V_105 , V_36 -> V_115 , V_122 ,
& V_114 ) < 0 ) {
F_22 ( L_6 ,
V_121 ) ;
if ( F_65 ( V_105 , V_36 -> V_115 , V_123 ,
& V_114 ) < 0 )
V_114 = 1 ;
}
V_76 = F_47 ( V_7 -> V_73 , 1 , V_114 , 0 ,
V_93 , V_124 ,
V_125 , V_39 ) ;
if ( F_11 ( V_76 ) ) {
F_22 ( L_7 , V_121 ) ;
goto V_126;
}
V_76 -> V_77 = V_77 ;
V_107 = V_76 -> V_84 ;
V_107 -> V_3 . V_38 = V_39 ;
V_107 -> V_3 . V_127 = V_128 ;
V_107 -> V_3 . V_40 = V_41 ;
V_107 -> V_3 . V_96 = V_129 ;
V_7 -> V_130 ++ ;
V_107 -> V_3 . V_130 = F_66 ( V_7 -> V_130 ) ;
V_107 -> V_3 . V_53 = V_131 ;
V_107 -> V_132 [ 0 ] = V_133 ;
V_107 -> V_132 [ 1 ] = V_134 ;
V_107 -> V_132 [ 2 ] = V_135 ;
V_107 -> V_136 . V_137 = V_138 << 1 ;
V_107 -> V_136 . V_139 = V_133 ;
V_107 -> V_136 . V_140 = V_134 ;
V_107 -> V_136 . V_141 = V_135 ;
V_107 -> V_136 . V_142 = F_16 ( V_103 ) ;
V_112 = (struct V_111 * ) V_107 -> V_136 . V_143 ;
V_112 -> V_144 = F_8 ( V_36 -> V_144 ) ;
V_112 -> V_145 = F_8 ( V_36 -> V_145 ) ;
V_112 -> V_146 = F_16 ( V_36 -> V_146 ) ;
V_112 -> V_115 = F_8 ( V_36 -> V_115 ) ;
V_112 -> V_147 = V_36 -> V_147 ;
V_112 -> V_148 = V_36 -> V_148 ;
if ( F_50 ( V_76 , NULL ) ) {
F_44 ( V_76 ) ;
} else {
if ( V_29 -> V_118 )
return;
V_29 -> V_117 = V_116 +
F_67 ( V_149 ) ;
return;
}
V_126:
F_43 ( V_77 ) ;
V_47:
F_68 ( L_8 ) ;
}
static int F_69 ( int V_150 , void * V_151 , void * V_36 )
{
struct V_5 * V_29 = V_151 ;
F_13 ( V_29 ) ;
return 0 ;
}
static int F_70 ( int V_150 , void * V_151 , void * V_36 )
{
struct V_5 * V_29 = V_151 ;
F_71 ( V_29 -> V_152 ) ;
return 0 ;
}
static int F_72 ( int V_150 , void * V_151 , void * V_36 )
{
struct V_5 * V_29 = V_151 ;
F_73 ( V_29 -> V_152 ) ;
return 0 ;
}
static void F_74 ( struct V_153 * V_154 ,
struct V_155 * V_156 )
{
struct V_6 * V_7 =
F_75 ( V_154 , struct V_6 , V_157 ) ;
struct V_27 * V_28 = V_7 -> V_28 ;
if ( V_156 -> V_158 . V_31 != V_7 -> V_31 )
return;
F_76 ( L_9 ,
V_156 -> V_159 , V_156 -> V_160 -> V_161 , V_156 -> V_158 . V_31 ) ;
if ( V_156 -> V_159 == V_162 )
F_77 ( & V_7 -> V_9 , F_72 , NULL ) ;
if ( V_156 -> V_159 == V_163 )
F_77 ( & V_7 -> V_9 , F_70 , NULL ) ;
}
static void F_78 ( struct V_27 * V_28 )
{
int V_164 ;
for ( V_164 = 1 ; V_164 <= V_28 -> V_101 ; V_164 ++ ) {
struct V_6 * V_7 = F_52 ( V_28 , V_164 ) ;
if ( ! V_7 -> V_73 )
continue;
F_48 ( & V_7 -> V_98 ) ;
F_77 ( & V_7 -> V_9 , F_69 , NULL ) ;
F_49 ( & V_7 -> V_98 ) ;
F_79 ( V_7 -> V_73 ) ;
V_7 -> V_73 = NULL ;
F_80 ( & V_7 -> V_98 ) ;
F_81 ( & V_7 -> V_9 ) ;
F_82 ( & V_7 -> V_157 ) ;
}
}
static int F_83 ( struct V_27 * V_28 )
{
struct V_165 V_166 = {
. V_127 = V_128 ,
. V_167 = V_39 ,
. V_132 = { V_133 , V_134 , V_135 }
} ;
int V_164 ;
F_84 ( V_99 , V_166 . V_168 ) ;
F_84 ( V_100 , V_166 . V_168 ) ;
for ( V_164 = 1 ; V_164 <= V_28 -> V_101 ; V_164 ++ ) {
struct V_6 * V_7 = F_52 ( V_28 , V_164 ) ;
int V_169 ;
V_7 -> V_28 = V_28 ;
V_7 -> V_31 = V_164 ;
F_85 ( & V_7 -> V_157 ,
V_28 -> V_30 , F_74 ) ;
V_169 = F_86 ( & V_7 -> V_157 ) ;
if ( V_169 ) {
F_22 ( L_10 , V_164 ) ;
F_78 ( V_28 ) ;
return V_169 ;
}
F_87 ( & V_7 -> V_9 ) ;
F_88 ( & V_7 -> V_98 ) ;
V_7 -> V_73 = F_89 ( V_28 -> V_30 , V_164 ,
V_170 , & V_166 ,
V_171 ,
F_42 , F_45 ,
V_7 , 0 ) ;
if ( F_11 ( V_7 -> V_73 ) ) {
V_169 = F_23 ( V_7 -> V_73 ) ;
V_7 -> V_73 = NULL ;
F_80 ( & V_7 -> V_98 ) ;
F_81 ( & V_7 -> V_9 ) ;
F_78 ( V_28 ) ;
return V_169 ;
}
}
return 0 ;
}
static void F_90 ( struct V_104 * V_160 )
{
struct V_27 * V_28 ;
int V_32 , V_172 = sizeof( * V_28 ) ;
if ( ! F_91 ( V_160 ) )
return;
V_172 += V_160 -> V_173 * sizeof( struct V_6 ) ;
V_28 = F_92 ( V_172 , V_94 ) ;
if ( ! V_28 )
return;
V_28 -> V_101 = V_160 -> V_173 ;
V_28 -> V_30 = V_160 ;
V_32 = F_83 ( V_28 ) ;
if ( ! V_32 )
F_93 ( L_11 ) ;
F_94 ( V_160 , & V_174 , V_28 ) ;
}
static void F_95 ( struct V_104 * V_160 ,
void * V_175 )
{
struct V_27 * V_28 = V_175 ;
if ( ! V_28 )
return;
F_93 ( L_12 ) ;
F_78 ( V_28 ) ;
F_96 ( V_28 ) ;
}
static int T_4 F_97 ( void )
{
int V_32 ;
F_98 ( L_13 ,
V_176 ) ;
V_32 = F_99 ( & V_174 ) ;
if ( V_32 )
F_100 ( L_14 , V_32 ) ;
return V_32 ;
}
static void F_101 ( void )
{
F_102 ( & V_174 ) ;
}
