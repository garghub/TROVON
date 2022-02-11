void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 , struct V_2 , V_1 ) ;
F_3 ( V_3 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_5 ;
T_1 V_6 ;
#define F_5 16224
#define F_6 312
V_6 = F_7 ( T_1 , V_5 -> V_7 - F_6 ,
F_5 - F_6 ) ;
V_6 = F_7 ( T_1 , V_6 , 8192 ) ;
V_6 = F_7 ( T_1 , V_6 , ( V_8 - 1 ) * V_9 ) ;
V_3 -> V_6 = V_6 ;
}
static void * F_8 ( const struct V_4 * V_5 )
{
struct V_2 * V_3 ;
if ( F_9 ( V_5 -> V_10 ) )
return F_10 ( - V_11 ) ;
V_3 = F_11 ( sizeof( * V_3 ) , V_12 ) ;
if ( ! V_3 )
return F_10 ( - V_13 ) ;
F_12 ( & V_3 -> V_1 ) ;
V_3 -> V_5 = * V_5 ;
F_4 ( V_3 ) ;
if ( F_13 ( V_3 ) < 0 ) {
F_3 ( V_3 ) ;
return F_10 ( - V_14 ) ;
}
if ( ! F_14 ( V_15 , & V_3 -> V_16 ) )
F_15 ( L_1 ,
F_16 ( V_5 -> V_17 ) ) ;
if ( V_5 -> V_18 >= 0x10d2b00 )
F_17 ( V_19 , & V_3 -> V_16 ) ;
F_18 ( & V_3 -> V_20 . V_21 ) ;
F_19 ( & V_3 -> V_20 . V_22 ) ;
F_20 ( & V_23 ) ;
F_21 ( & V_3 -> V_22 , & V_24 ) ;
F_22 ( & V_23 ) ;
F_15 ( L_2 ,
F_16 ( V_5 -> V_17 ) ) ;
return V_3 ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
bool V_29 = false ;
F_24 ( & V_3 -> V_20 . V_21 ) ;
F_25 (csk, &cdev->cskq.list, list) {
V_28 = F_26 ( 0 , V_30 ) ;
if ( ! V_28 )
continue;
F_24 ( & V_26 -> V_31 . V_21 ) ;
F_27 ( & V_26 -> V_31 , V_28 ) ;
if ( F_28 ( & V_26 -> V_31 ) == 1 )
V_29 = true ;
F_29 ( & V_26 -> V_31 . V_21 ) ;
if ( V_29 ) {
F_30 ( & V_26 -> V_32 ) ;
V_29 = false ;
}
}
F_29 ( & V_3 -> V_20 . V_21 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
bool V_33 = false ;
F_24 ( & V_3 -> V_20 . V_21 ) ;
if ( F_32 ( & V_3 -> V_20 . V_22 ) )
V_33 = true ;
F_29 ( & V_3 -> V_20 . V_21 ) ;
if ( V_33 ) {
F_20 ( & V_23 ) ;
F_33 ( & V_3 -> V_22 ) ;
F_22 ( & V_23 ) ;
F_34 ( V_3 ) ;
} else {
F_23 ( V_3 ) ;
}
}
static int F_35 ( void * V_34 , enum V_35 V_36 )
{
struct V_2 * V_3 = V_34 ;
switch ( V_36 ) {
case V_37 :
F_17 ( V_38 , & V_3 -> V_16 ) ;
F_15 ( L_3 , F_16 ( V_3 -> V_5 . V_17 ) ) ;
break;
case V_39 :
F_36 ( V_38 , & V_3 -> V_16 ) ;
F_23 ( V_3 ) ;
F_15 ( L_4 , F_16 ( V_3 -> V_5 . V_17 ) ) ;
break;
case V_40 :
F_15 ( L_5 , F_16 ( V_3 -> V_5 . V_17 ) ) ;
break;
case V_41 :
F_36 ( V_38 , & V_3 -> V_16 ) ;
F_15 ( L_6 , F_16 ( V_3 -> V_5 . V_17 ) ) ;
F_31 ( V_3 ) ;
break;
default:
F_15 ( L_7 ,
F_16 ( V_3 -> V_5 . V_17 ) , V_36 ) ;
break;
}
return 0 ;
}
static void
F_37 ( unsigned int V_42 , struct V_43 * V_44 ,
struct V_45 * V_46 )
{
unsigned int V_47 = F_38 ( V_44 -> V_48 ) ;
V_46 -> V_16 |= V_49 ;
V_46 -> V_50 = F_38 ( V_44 -> V_51 ) ;
V_46 -> V_52 = F_39 ( V_44 -> V_53 ) ;
if ( V_47 & ( 1 << V_54 ) ) {
F_15 ( L_8 , V_42 , V_47 ) ;
V_46 -> V_16 |= V_55 ;
}
if ( V_47 & ( 1 << V_56 ) ) {
F_15 ( L_9 , V_42 , V_47 ) ;
V_46 -> V_16 |= V_57 ;
}
if ( V_47 & ( 1 << V_58 ) )
F_15 ( L_10 , V_42 , V_47 ) ;
if ( ( V_47 & ( 1 << V_59 ) ) &&
( ! ( V_46 -> V_16 & V_60 ) ) ) {
V_46 -> V_16 |= V_61 ;
}
}
static void
F_40 ( struct V_27 * V_28 , T_2 V_62 , const T_3 * V_63 )
{
struct V_64 * V_65 = F_41 ( V_28 ) ;
struct V_45 * V_46 = F_42 ( V_28 ,
V_65 -> V_66 ) ;
struct V_67 * V_44 = (struct V_67 * ) ( V_63 + 1 ) ;
F_37 ( V_65 -> V_26 -> V_42 , V_44 , V_46 ) ;
if ( V_46 -> V_16 & V_68 )
V_46 -> V_69 = true ;
V_65 -> V_69 = true ;
V_65 -> V_70 += V_46 -> V_52 ;
V_65 -> V_66 ++ ;
}
static void
F_43 ( struct V_27 * V_28 , const struct V_71 * V_72 ,
unsigned int V_73 )
{
T_2 V_74 = F_44 ( V_28 ) -> V_75 ;
T_2 V_76 ;
F_45 ( V_28 , V_74 , V_72 -> V_77 [ 0 ] . V_78 ,
V_72 -> V_77 [ 0 ] . V_73 + V_73 ,
V_72 -> V_77 [ 0 ] . V_79 - V_73 ) ;
for ( V_76 = 1 ; V_76 < V_72 -> V_80 ; V_76 ++ )
F_45 ( V_28 , V_74 + V_76 ,
V_72 -> V_77 [ V_76 ] . V_78 ,
V_72 -> V_77 [ V_76 ] . V_73 ,
V_72 -> V_77 [ V_76 ] . V_79 ) ;
F_44 ( V_28 ) -> V_75 += V_72 -> V_80 ;
F_46 ( V_72 -> V_77 [ V_72 -> V_80 - 1 ] . V_78 ) ;
}
static void
F_47 ( struct V_27 * V_28 , T_2 V_62 , const struct V_71 * V_72 )
{
struct V_64 * V_65 = F_41 ( V_28 ) ;
struct V_45 * V_46 = F_42 ( V_28 ,
V_65 -> V_66 ) ;
T_1 V_53 , V_73 ;
if ( V_62 == V_81 ) {
struct V_82 * V_44 = (struct V_82 * ) V_72 -> V_83 ;
V_73 = sizeof( struct V_82 ) ;
V_46 -> V_16 |= V_68 ;
V_46 -> V_84 = F_38 ( V_44 -> V_84 ) ;
V_53 = F_39 ( V_44 -> V_53 ) ;
V_46 -> V_85 = V_72 -> V_83 + V_73 ;
V_46 -> V_86 = V_53 ;
V_46 -> V_87 = F_44 ( V_28 ) -> V_75 ;
if ( F_48 ( V_72 -> V_80 > 1 ) )
F_49 ( V_28 ) = 0 ;
V_65 -> V_69 = false ;
} else {
struct V_88 * V_44 = (struct V_88 * ) V_72 -> V_83 ;
V_73 = sizeof( struct V_88 ) ;
V_46 -> V_16 |= V_60 ;
V_53 = F_39 ( V_44 -> V_53 ) ;
V_46 -> V_89 = V_53 ;
V_46 -> V_90 = V_65 -> V_73 ;
V_46 -> V_91 = V_72 -> V_80 ;
V_46 -> V_92 = F_44 ( V_28 ) -> V_75 ;
}
F_43 ( V_28 , V_72 , V_73 ) ;
V_46 -> V_77 += V_72 -> V_80 ;
V_65 -> V_73 += V_53 ;
V_28 -> V_53 += V_53 ;
V_28 -> V_93 += V_53 ;
V_28 -> V_94 += V_53 ;
}
static struct V_27 *
F_50 ( struct V_25 * V_26 , T_2 V_62 , const struct V_71 * V_72 ,
const T_3 * V_63 , struct V_95 * V_96 )
{
struct V_27 * V_28 ;
struct V_64 * V_65 ;
V_28 = F_51 ( V_96 , V_97 ) ;
if ( F_48 ( ! V_28 ) )
return NULL ;
memset ( V_28 -> V_98 , 0 , V_97 ) ;
F_49 ( V_28 ) |= V_99 ;
V_65 = F_41 ( V_28 ) ;
F_52 ( V_26 ) ;
V_65 -> V_26 = V_26 ;
return V_28 ;
}
static void F_53 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
bool V_29 = false ;
F_54 ( & V_26 -> V_31 . V_21 ) ;
F_27 ( & V_26 -> V_31 , V_28 ) ;
if ( F_28 ( & V_26 -> V_31 ) == 1 )
V_29 = true ;
F_55 ( & V_26 -> V_31 . V_21 ) ;
if ( V_29 )
F_30 ( & V_26 -> V_32 ) ;
}
static void F_56 ( struct V_100 * V_101 , struct V_27 * V_28 )
{
struct V_64 * V_65 = F_41 ( V_28 ) ;
struct V_25 * V_26 = V_65 -> V_26 ;
V_26 -> V_102 = NULL ;
F_57 ( V_28 , & V_101 -> V_103 ) ;
F_53 ( V_26 , V_28 ) ;
F_58 ( V_26 ) ;
V_101 -> V_104 ++ ;
V_101 -> V_105 -- ;
}
static void F_59 ( struct V_100 * V_101 )
{
struct V_27 * V_28 ;
while ( ( V_28 = F_60 ( & V_101 -> V_103 ) ) )
F_56 ( V_101 , V_28 ) ;
}
static int
F_61 ( struct V_25 * V_26 , T_2 V_62 , const T_3 * V_63 ,
const struct V_71 * V_72 , struct V_100 * V_101 ,
struct V_95 * V_96 )
{
struct V_27 * V_28 ;
struct V_64 * V_65 ;
if ( ! V_26 ) {
F_62 ( L_11 , V_106 , V_62 ) ;
goto V_107;
}
if ( V_26 -> V_102 )
goto V_108;
V_109:
if ( V_101 -> V_105 >= V_110 ) {
F_59 ( V_101 ) ;
goto V_109;
}
V_28 = F_50 ( V_26 , V_62 , V_72 , V_63 , V_96 ) ;
if ( F_48 ( ! V_28 ) )
goto V_107;
V_26 -> V_102 = V_28 ;
F_27 ( & V_101 -> V_103 , V_28 ) ;
V_101 -> V_105 ++ ;
V_108:
V_28 = V_26 -> V_102 ;
V_65 = F_41 ( V_28 ) ;
if ( ( V_72 && ( ( ( F_44 ( V_28 ) -> V_75 + V_72 -> V_80 ) >
V_8 ) || ( V_65 -> V_70 >= V_111 ) ) ) ||
( V_65 -> V_66 >= V_8 ) ) {
F_56 ( V_101 , V_28 ) ;
goto V_109;
}
if ( V_72 )
F_47 ( V_28 , V_62 , V_72 ) ;
else
F_40 ( V_28 , V_62 , V_63 ) ;
V_101 -> V_112 ++ ;
return 0 ;
V_107:
return - 1 ;
}
static int
F_63 ( void * V_113 , const T_3 * V_63 ,
const struct V_71 * V_72 , struct V_100 * V_101 ,
struct V_95 * V_96 )
{
struct V_2 * V_3 = V_113 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
struct V_114 * V_115 = NULL ;
struct V_25 * V_26 = NULL ;
unsigned int V_42 = 0 ;
struct V_27 * V_28 ;
unsigned int V_62 = * ( T_2 * ) V_63 ;
bool V_116 = true ;
switch ( V_62 ) {
case V_81 :
case V_117 :
case V_118 :
case V_119 :
V_116 = false ;
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
V_115 = V_72 ? (struct V_114 * ) V_72 -> V_83 :
(struct V_114 * ) ( V_63 + 1 ) ;
V_42 = F_64 ( V_115 ) ;
V_26 = F_65 ( V_5 -> V_127 , V_42 ) ;
break;
default:
break;
}
if ( V_26 && V_26 -> V_102 && V_116 )
F_56 ( V_101 , V_26 -> V_102 ) ;
if ( ! V_72 ) {
unsigned int V_53 ;
if ( V_62 == V_118 ) {
if ( ! F_61 ( V_26 , V_62 , V_63 , NULL , V_101 ,
V_96 ) )
return 0 ;
}
V_53 = 64 - sizeof( struct V_128 ) - 8 ;
V_28 = F_51 ( V_96 , V_53 ) ;
if ( ! V_28 )
goto V_129;
F_66 ( V_28 , V_53 ) ;
F_67 ( V_28 , & V_63 [ 1 ] , V_53 ) ;
} else {
if ( F_48 ( V_62 != * ( T_2 * ) V_72 -> V_83 ) ) {
F_15 ( L_12 ,
V_72 -> V_83 , F_68 ( * V_63 ) ,
F_68 ( * ( V_130 * ) V_72 -> V_83 ) ,
V_72 -> V_131 ) ;
return 0 ;
}
if ( V_62 == V_81 || V_62 == V_117 ) {
if ( ! F_61 ( V_26 , V_62 , V_63 , V_72 , V_101 ,
V_96 ) )
return 0 ;
}
#define F_69 128
V_28 = F_70 ( V_72 , F_69 , F_69 ) ;
if ( F_48 ( ! V_28 ) )
goto V_129;
}
V_115 = (struct V_114 * ) V_28 -> V_98 ;
V_62 = V_115 -> V_132 . V_133 ;
F_71 ( V_28 ) = V_62 ;
F_72 ( L_13 ,
V_3 , V_62 , V_115 -> V_132 . V_134 ,
F_38 ( V_115 -> V_132 . V_134 ) , V_28 ) ;
if ( V_62 < V_135 && V_136 [ V_62 ] ) {
V_136 [ V_62 ] ( V_3 , V_28 ) ;
} else {
F_62 ( L_14 , V_62 ) ;
F_73 ( V_28 ) ;
}
return 0 ;
V_129:
F_62 ( L_15 , V_106 ) ;
return 1 ;
}
static void
F_74 ( struct V_2 * V_3 , T_2 V_137 ,
T_2 V_138 , T_4 V_139 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
T_4 V_140 ;
bool V_29 = false ;
F_24 ( & V_3 -> V_20 . V_21 ) ;
F_25 (csk, &cdev->cskq.list, list) {
if ( V_26 -> V_137 != V_137 )
continue;
if ( V_26 -> V_141 . V_142 . V_143 == V_144 ) {
struct V_145 * V_146 ;
V_146 = (struct V_145 * ) & V_26 -> V_141 . V_142 ;
V_140 = F_39 ( V_146 -> V_147 ) ;
} else {
struct V_148 * V_149 ;
V_149 = (struct V_148 * ) & V_26 -> V_141 . V_142 ;
V_140 = F_39 ( V_149 -> V_150 ) ;
}
if ( V_140 != V_139 )
continue;
if ( V_26 -> V_138 == V_138 )
continue;
V_28 = F_26 ( 0 , V_30 ) ;
if ( ! V_28 )
continue;
F_54 ( & V_26 -> V_31 . V_21 ) ;
F_27 ( & V_26 -> V_31 , V_28 ) ;
if ( F_28 ( & V_26 -> V_31 ) == 1 )
V_29 = true ;
F_55 ( & V_26 -> V_31 . V_21 ) ;
if ( V_29 ) {
F_30 ( & V_26 -> V_32 ) ;
V_29 = false ;
}
}
F_29 ( & V_3 -> V_20 . V_21 ) ;
}
static void F_75 ( struct V_151 * V_152 )
{
struct V_153 * V_154 ;
struct V_155 * V_156 ;
struct V_2 * V_3 = NULL ;
struct V_157 * V_158 ;
T_2 V_159 , V_137 = 0xff ;
V_154 = F_2 ( V_152 , struct V_153 , V_152 ) ;
V_158 = & V_154 -> V_160 ;
if ( V_158 -> V_161 & V_162 ) {
if ( V_158 -> V_163 . V_164 != V_165 )
goto V_107;
V_159 = V_158 -> V_163 . V_159 ;
} else if ( V_158 -> V_161 & V_166 ) {
if ( V_158 -> V_163 . V_164 != V_167 )
goto V_107;
if ( ! V_158 -> V_163 . V_159 )
goto V_107;
V_159 = F_76 ( V_158 -> V_163 . V_159 ) - 1 ;
} else {
goto V_107;
}
F_72 ( L_16 ,
V_158 -> V_168 , V_159 ) ;
V_156 = F_77 ( & V_169 , V_158 -> V_168 ) ;
if ( ! V_156 )
goto V_107;
F_20 ( & V_23 ) ;
V_3 = F_78 ( V_156 , & V_137 ) ;
F_79 ( V_156 ) ;
if ( ! V_3 ) {
F_22 ( & V_23 ) ;
goto V_107;
}
F_74 ( V_3 , V_137 , V_159 ,
V_158 -> V_163 . V_170 ) ;
F_22 ( & V_23 ) ;
V_107:
F_3 ( V_154 ) ;
}
static int
F_80 ( struct V_171 * V_172 , unsigned long V_173 ,
void * V_98 )
{
struct V_153 * V_154 ;
struct V_157 * V_160 = V_98 ;
V_154 = F_11 ( sizeof( * V_154 ) , V_30 ) ;
if ( ! V_154 )
return V_174 ;
V_154 -> V_160 = * V_160 ;
F_81 ( & V_154 -> V_152 , F_75 ) ;
F_82 ( & V_154 -> V_152 ) ;
return V_175 ;
}
static enum V_176 F_83 ( struct V_177 * V_178 )
{
return V_179 ;
}
static int T_5 F_84 ( void )
{
F_85 ( V_180 , & V_181 ) ;
F_86 ( & V_182 ) ;
#ifdef F_87
F_15 ( L_17 , V_183 ) ;
F_88 ( & V_184 ) ;
#endif
F_89 ( F_90 ( struct V_27 , V_185 ) <
sizeof( union V_186 ) ) ;
return 0 ;
}
static void T_6 F_91 ( void )
{
struct V_2 * V_3 , * V_187 ;
#ifdef F_87
F_92 ( & V_184 ) ;
#endif
F_20 ( & V_23 ) ;
F_93 (cdev, tmp, &cdev_list_head, list) {
F_33 ( & V_3 -> V_22 ) ;
F_34 ( V_3 ) ;
}
F_22 ( & V_23 ) ;
F_94 ( & V_182 ) ;
F_95 ( V_180 ) ;
}
