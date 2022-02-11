void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 , struct V_2 , V_1 ) ;
F_3 ( F_4 ( V_3 ) ) ;
F_5 ( V_3 ) ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_5 ;
T_1 V_6 ;
#define F_7 16224
#define F_8 312
V_6 = F_9 ( T_1 , V_5 -> V_7 - F_8 ,
F_7 - F_8 ) ;
V_6 = F_9 ( T_1 , V_6 , 8192 ) ;
V_6 = F_9 ( T_1 , V_6 , ( V_8 - 1 ) * V_9 ) ;
V_3 -> V_6 = V_6 ;
}
static void * F_10 ( const struct V_4 * V_5 )
{
struct V_2 * V_3 ;
if ( F_11 ( V_5 -> V_10 ) )
return F_12 ( - V_11 ) ;
V_3 = F_13 ( sizeof( * V_3 ) , V_12 ) ;
if ( ! V_3 )
return F_12 ( - V_13 ) ;
F_14 ( & V_3 -> V_1 ) ;
V_3 -> V_5 = * V_5 ;
F_6 ( V_3 ) ;
if ( F_15 ( V_3 ) < 0 ) {
F_5 ( V_3 ) ;
return F_12 ( - V_14 ) ;
}
if ( ! F_16 ( V_15 , & V_3 -> V_16 ) )
F_17 ( L_1 ,
F_18 ( V_5 -> V_17 ) ) ;
if ( V_5 -> V_18 >= 0x10d2b00 )
F_19 ( V_19 , & V_3 -> V_16 ) ;
F_20 ( & V_3 -> V_20 . V_21 ) ;
F_21 ( & V_3 -> V_20 . V_22 ) ;
F_22 ( & V_23 ) ;
F_23 ( & V_3 -> V_22 , & V_24 ) ;
F_24 ( & V_23 ) ;
F_17 ( L_2 ,
F_18 ( V_5 -> V_17 ) ) ;
return V_3 ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
bool V_29 = false ;
F_26 ( & V_3 -> V_20 . V_21 ) ;
F_27 (csk, &cdev->cskq.list, list) {
V_28 = F_28 ( 0 , V_30 ) ;
if ( ! V_28 )
continue;
F_26 ( & V_26 -> V_31 . V_21 ) ;
F_29 ( & V_26 -> V_31 , V_28 ) ;
if ( F_30 ( & V_26 -> V_31 ) == 1 )
V_29 = true ;
F_31 ( & V_26 -> V_31 . V_21 ) ;
if ( V_29 ) {
F_32 ( & V_26 -> V_32 ) ;
V_29 = false ;
}
}
F_31 ( & V_3 -> V_20 . V_21 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
bool V_33 = false ;
F_26 ( & V_3 -> V_20 . V_21 ) ;
if ( F_34 ( & V_3 -> V_20 . V_22 ) )
V_33 = true ;
F_31 ( & V_3 -> V_20 . V_21 ) ;
if ( V_33 ) {
F_22 ( & V_23 ) ;
F_35 ( & V_3 -> V_22 ) ;
F_24 ( & V_23 ) ;
F_36 ( V_3 ) ;
} else {
F_25 ( V_3 ) ;
}
}
static int F_37 ( void * V_34 , enum V_35 V_36 )
{
struct V_2 * V_3 = V_34 ;
switch ( V_36 ) {
case V_37 :
F_19 ( V_38 , & V_3 -> V_16 ) ;
F_17 ( L_3 , F_18 ( V_3 -> V_5 . V_17 ) ) ;
break;
case V_39 :
F_38 ( V_38 , & V_3 -> V_16 ) ;
F_25 ( V_3 ) ;
F_17 ( L_4 , F_18 ( V_3 -> V_5 . V_17 ) ) ;
break;
case V_40 :
F_17 ( L_5 , F_18 ( V_3 -> V_5 . V_17 ) ) ;
break;
case V_41 :
F_38 ( V_38 , & V_3 -> V_16 ) ;
F_17 ( L_6 , F_18 ( V_3 -> V_5 . V_17 ) ) ;
F_33 ( V_3 ) ;
break;
default:
F_17 ( L_7 ,
F_18 ( V_3 -> V_5 . V_17 ) , V_36 ) ;
break;
}
return 0 ;
}
static void
F_39 ( struct V_25 * V_26 , struct V_42 * V_43 ,
T_1 V_44 )
{
if ( V_44 & ( 1 << V_45 ) ) {
F_17 ( L_8 , V_26 -> V_46 , V_44 ) ;
V_43 -> V_16 |= V_47 ;
}
if ( V_44 & ( 1 << V_48 ) ) {
F_17 ( L_9 , V_26 -> V_46 , V_44 ) ;
V_43 -> V_16 |= V_49 ;
}
if ( V_44 & ( 1 << V_50 ) )
F_17 ( L_10 , V_26 -> V_46 , V_44 ) ;
if ( ( V_44 & ( 1 << V_51 ) ) &&
( ! ( V_43 -> V_16 & V_52 ) ) ) {
V_43 -> V_16 |= V_53 ;
}
}
static void
F_40 ( struct V_27 * V_28 , T_2 V_54 , const T_3 * V_55 )
{
struct V_56 * V_57 = F_41 ( V_28 ) ;
struct V_42 * V_43 = F_42 ( V_28 ,
V_57 -> V_58 ) ;
struct V_59 * V_60 = (struct V_59 * ) ( V_55 + 1 ) ;
F_39 ( V_57 -> V_26 , V_43 , F_43 ( V_60 -> V_44 ) ) ;
V_43 -> V_16 |= V_61 ;
V_43 -> V_62 = F_44 ( V_60 -> V_63 ) ;
V_43 -> V_64 = F_45 ( V_60 -> V_65 ) ;
if ( V_43 -> V_16 & V_66 )
V_43 -> V_67 = true ;
V_57 -> V_68 += V_43 -> V_64 ;
V_57 -> V_67 = true ;
V_57 -> V_58 ++ ;
}
static void
F_46 ( struct V_27 * V_28 , const struct V_69 * V_70 ,
unsigned int V_71 )
{
T_2 V_72 = F_47 ( V_28 ) -> V_73 ;
T_2 V_74 ;
F_48 ( V_28 , V_72 , V_70 -> V_75 [ 0 ] . V_76 ,
V_70 -> V_75 [ 0 ] . V_71 + V_71 ,
V_70 -> V_75 [ 0 ] . V_77 - V_71 ) ;
for ( V_74 = 1 ; V_74 < V_70 -> V_78 ; V_74 ++ )
F_48 ( V_28 , V_72 + V_74 ,
V_70 -> V_75 [ V_74 ] . V_76 ,
V_70 -> V_75 [ V_74 ] . V_71 ,
V_70 -> V_75 [ V_74 ] . V_77 ) ;
F_47 ( V_28 ) -> V_73 += V_70 -> V_78 ;
F_49 ( V_70 -> V_75 [ V_70 -> V_78 - 1 ] . V_76 ) ;
}
static void
F_50 ( struct V_27 * V_28 , T_2 V_54 , const struct V_69 * V_70 )
{
struct V_56 * V_57 = F_41 ( V_28 ) ;
struct V_42 * V_43 = F_42 ( V_28 ,
V_57 -> V_58 ) ;
T_1 V_65 , V_71 ;
if ( V_54 == V_79 ) {
struct V_80 * V_60 = (struct V_80 * ) V_70 -> V_81 ;
V_71 = sizeof( struct V_80 ) ;
V_43 -> V_16 |= V_66 ;
V_43 -> V_82 = F_44 ( V_60 -> V_82 ) ;
V_65 = F_45 ( V_60 -> V_65 ) ;
V_43 -> V_83 = V_70 -> V_81 + V_71 ;
V_43 -> V_84 = V_65 ;
V_43 -> V_85 = F_47 ( V_28 ) -> V_73 ;
if ( F_51 ( V_70 -> V_78 > 1 ) )
F_52 ( V_28 ) = 0 ;
V_57 -> V_67 = false ;
} else if ( V_54 == V_86 ) {
struct V_87 * V_60 = (struct V_87 * ) V_70 -> V_81 ;
V_71 = sizeof( struct V_87 ) ;
V_43 -> V_16 |= V_52 ;
V_65 = F_45 ( V_60 -> V_65 ) ;
V_43 -> V_88 = V_65 ;
V_43 -> V_89 = V_57 -> V_71 ;
V_43 -> V_90 = V_70 -> V_78 ;
V_43 -> V_91 = F_47 ( V_28 ) -> V_73 ;
V_57 -> V_67 = false ;
} else {
struct V_92 * V_60 ;
V_60 = (struct V_92 * ) V_70 -> V_81 ;
V_71 = sizeof( struct V_92 ) ;
V_43 -> V_16 |= ( V_66 | V_61 ) ;
V_65 = F_53 ( V_60 -> V_65 ) ;
V_43 -> V_83 = V_70 -> V_81 + V_71 ;
V_43 -> V_84 = V_65 ;
V_43 -> V_85 = F_47 ( V_28 ) -> V_73 ;
V_43 -> V_62 = F_43 ( V_60 -> V_63 ) ;
V_43 -> V_64 = F_45 ( V_60 -> V_65 ) ;
if ( F_51 ( V_70 -> V_78 > 1 ) )
F_52 ( V_28 ) = 0 ;
F_39 ( V_57 -> V_26 , V_43 ,
F_43 ( V_60 -> V_44 ) ) ;
if ( V_43 -> V_16 & V_53 ) {
V_43 -> V_16 |= V_93 ;
V_43 -> V_67 = true ;
} else if ( V_43 -> V_16 & V_52 ) {
V_43 -> V_67 = true ;
}
V_57 -> V_68 += V_43 -> V_84 + V_43 -> V_88 ;
V_57 -> V_67 = true ;
V_57 -> V_58 ++ ;
}
F_46 ( V_28 , V_70 , V_71 ) ;
V_43 -> V_75 += V_70 -> V_78 ;
V_57 -> V_71 += V_65 ;
V_28 -> V_65 += V_65 ;
V_28 -> V_94 += V_65 ;
V_28 -> V_95 += V_65 ;
}
static struct V_27 *
F_54 ( struct V_25 * V_26 , T_2 V_54 , const struct V_69 * V_70 ,
const T_3 * V_55 , struct V_96 * V_97 )
{
struct V_27 * V_28 ;
struct V_56 * V_57 ;
V_28 = F_55 ( V_97 , V_98 ) ;
if ( F_51 ( ! V_28 ) )
return NULL ;
memset ( V_28 -> V_99 , 0 , V_98 ) ;
F_52 ( V_28 ) |= V_100 ;
V_57 = F_41 ( V_28 ) ;
F_56 ( V_26 ) ;
V_57 -> V_26 = V_26 ;
return V_28 ;
}
static void F_57 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
bool V_29 = false ;
F_58 ( & V_26 -> V_31 . V_21 ) ;
F_29 ( & V_26 -> V_31 , V_28 ) ;
if ( F_30 ( & V_26 -> V_31 ) == 1 )
V_29 = true ;
F_59 ( & V_26 -> V_31 . V_21 ) ;
if ( V_29 )
F_32 ( & V_26 -> V_32 ) ;
}
static void F_60 ( struct V_101 * V_102 , struct V_27 * V_28 )
{
struct V_56 * V_57 = F_41 ( V_28 ) ;
struct V_25 * V_26 = V_57 -> V_26 ;
V_26 -> V_103 = NULL ;
F_61 ( V_28 , & V_102 -> V_104 ) ;
F_57 ( V_26 , V_28 ) ;
F_62 ( V_26 ) ;
V_102 -> V_105 ++ ;
V_102 -> V_106 -- ;
}
static void F_63 ( struct V_101 * V_102 )
{
struct V_27 * V_28 ;
while ( ( V_28 = F_64 ( & V_102 -> V_104 ) ) )
F_60 ( V_102 , V_28 ) ;
}
static int
F_65 ( struct V_25 * V_26 , T_2 V_54 , const T_3 * V_55 ,
const struct V_69 * V_70 , struct V_101 * V_102 ,
struct V_96 * V_97 )
{
struct V_27 * V_28 ;
struct V_56 * V_57 ;
if ( ! V_26 ) {
F_66 ( L_11 , V_107 , V_54 ) ;
goto V_108;
}
if ( V_26 -> V_103 )
goto V_109;
V_110:
if ( V_102 -> V_106 >= V_111 ) {
F_63 ( V_102 ) ;
goto V_110;
}
V_28 = F_54 ( V_26 , V_54 , V_70 , V_55 , V_97 ) ;
if ( F_51 ( ! V_28 ) )
goto V_108;
V_26 -> V_103 = V_28 ;
F_29 ( & V_102 -> V_104 , V_28 ) ;
V_102 -> V_106 ++ ;
V_109:
V_28 = V_26 -> V_103 ;
V_57 = F_41 ( V_28 ) ;
if ( ( V_70 && ( ( ( F_47 ( V_28 ) -> V_73 + V_70 -> V_78 ) >
V_8 ) || ( V_57 -> V_68 >= V_112 ) ) ) ||
( V_57 -> V_58 >= V_8 ) ) {
F_60 ( V_102 , V_28 ) ;
goto V_110;
}
if ( V_70 )
F_50 ( V_28 , V_54 , V_70 ) ;
else
F_40 ( V_28 , V_54 , V_55 ) ;
V_102 -> V_113 ++ ;
return 0 ;
V_108:
return - 1 ;
}
static int
F_67 ( void * V_114 , const T_3 * V_55 ,
const struct V_69 * V_70 , struct V_101 * V_102 ,
struct V_96 * V_97 )
{
struct V_2 * V_3 = V_114 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
struct V_115 * V_116 = NULL ;
struct V_25 * V_26 = NULL ;
unsigned int V_46 = 0 ;
struct V_27 * V_28 ;
unsigned int V_54 = * ( T_2 * ) V_55 ;
bool V_117 = true ;
switch ( V_54 ) {
case V_79 :
case V_86 :
case V_118 :
case V_119 :
case V_120 :
V_117 = false ;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
V_116 = V_70 ? (struct V_115 * ) V_70 -> V_81 :
(struct V_115 * ) ( V_55 + 1 ) ;
V_46 = F_68 ( V_116 ) ;
V_26 = F_69 ( V_5 -> V_128 , V_46 ) ;
break;
default:
break;
}
if ( V_26 && V_26 -> V_103 && V_117 )
F_60 ( V_102 , V_26 -> V_103 ) ;
if ( ! V_70 ) {
unsigned int V_65 ;
if ( V_54 == V_119 ) {
if ( ! F_65 ( V_26 , V_54 , V_55 , NULL , V_102 ,
V_97 ) )
return 0 ;
}
V_65 = 64 - sizeof( struct V_129 ) - 8 ;
V_28 = F_55 ( V_97 , V_65 ) ;
if ( ! V_28 )
goto V_130;
F_70 ( V_28 , V_65 ) ;
F_71 ( V_28 , & V_55 [ 1 ] , V_65 ) ;
} else {
if ( F_51 ( V_54 != * ( T_2 * ) V_70 -> V_81 ) ) {
F_17 ( L_12 ,
V_70 -> V_81 , F_72 ( * V_55 ) ,
F_73 ( V_70 -> V_81 ) ,
V_70 -> V_131 ) ;
return 0 ;
}
if ( ( V_54 == V_79 ) || ( V_54 == V_86 ) ||
( V_54 == V_118 ) ) {
if ( ! F_65 ( V_26 , V_54 , V_55 , V_70 , V_102 ,
V_97 ) )
return 0 ;
}
#define F_74 128
V_28 = F_75 ( V_70 , F_74 , F_74 ) ;
if ( F_51 ( ! V_28 ) )
goto V_130;
}
V_116 = (struct V_115 * ) V_28 -> V_99 ;
V_54 = V_116 -> V_132 . V_133 ;
F_76 ( V_28 ) = V_54 ;
F_77 ( L_13 ,
V_3 , V_54 , V_116 -> V_132 . V_134 ,
F_44 ( V_116 -> V_132 . V_134 ) , V_28 ) ;
if ( V_54 < V_135 && V_136 [ V_54 ] ) {
V_136 [ V_54 ] ( V_3 , V_28 ) ;
} else {
F_66 ( L_14 , V_54 ) ;
F_78 ( V_28 ) ;
}
return 0 ;
V_130:
F_66 ( L_15 , V_107 ) ;
return 1 ;
}
static void
F_79 ( struct V_2 * V_3 , T_2 V_137 ,
T_2 V_138 , T_4 V_139 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
T_4 V_140 ;
bool V_29 = false ;
F_26 ( & V_3 -> V_20 . V_21 ) ;
F_27 (csk, &cdev->cskq.list, list) {
if ( V_26 -> V_137 != V_137 )
continue;
if ( V_26 -> V_141 . V_142 . V_143 == V_144 ) {
struct V_145 * V_146 ;
V_146 = (struct V_145 * ) & V_26 -> V_141 . V_142 ;
V_140 = F_45 ( V_146 -> V_147 ) ;
} else {
struct V_148 * V_149 ;
V_149 = (struct V_148 * ) & V_26 -> V_141 . V_142 ;
V_140 = F_45 ( V_149 -> V_150 ) ;
}
if ( V_140 != V_139 )
continue;
if ( V_26 -> V_138 == V_138 )
continue;
V_28 = F_28 ( 0 , V_30 ) ;
if ( ! V_28 )
continue;
F_58 ( & V_26 -> V_31 . V_21 ) ;
F_29 ( & V_26 -> V_31 , V_28 ) ;
if ( F_30 ( & V_26 -> V_31 ) == 1 )
V_29 = true ;
F_59 ( & V_26 -> V_31 . V_21 ) ;
if ( V_29 ) {
F_32 ( & V_26 -> V_32 ) ;
V_29 = false ;
}
}
F_31 ( & V_3 -> V_20 . V_21 ) ;
}
static void F_80 ( struct V_151 * V_152 )
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
goto V_108;
V_159 = V_158 -> V_163 . V_159 ;
} else if ( V_158 -> V_161 & V_166 ) {
if ( V_158 -> V_163 . V_164 != V_167 )
goto V_108;
if ( ! V_158 -> V_163 . V_159 )
goto V_108;
V_159 = F_81 ( V_158 -> V_163 . V_159 ) - 1 ;
} else {
goto V_108;
}
F_77 ( L_16 ,
V_158 -> V_168 , V_159 ) ;
V_156 = F_82 ( & V_169 , V_158 -> V_168 ) ;
if ( ! V_156 )
goto V_108;
F_22 ( & V_23 ) ;
V_3 = F_83 ( V_156 , & V_137 ) ;
F_84 ( V_156 ) ;
if ( ! V_3 ) {
F_24 ( & V_23 ) ;
goto V_108;
}
F_79 ( V_3 , V_137 , V_159 ,
V_158 -> V_163 . V_170 ) ;
F_24 ( & V_23 ) ;
V_108:
F_5 ( V_154 ) ;
}
static int
F_85 ( struct V_171 * V_172 , unsigned long V_173 ,
void * V_99 )
{
struct V_153 * V_154 ;
struct V_157 * V_160 = V_99 ;
V_154 = F_13 ( sizeof( * V_154 ) , V_30 ) ;
if ( ! V_154 )
return V_174 ;
V_154 -> V_160 = * V_160 ;
F_86 ( & V_154 -> V_152 , F_80 ) ;
F_87 ( & V_154 -> V_152 ) ;
return V_175 ;
}
static enum V_176 F_88 ( struct V_177 * V_178 )
{
return V_179 ;
}
static int T_5 F_89 ( void )
{
F_90 ( V_180 , & V_181 ) ;
F_91 ( & V_182 ) ;
#ifdef F_92
F_17 ( L_17 , V_183 ) ;
F_93 ( & V_184 ) ;
#endif
F_94 ( F_95 ( struct V_27 , V_185 ) <
sizeof( union V_186 ) ) ;
return 0 ;
}
static void T_6 F_96 ( void )
{
struct V_2 * V_3 , * V_187 ;
#ifdef F_92
F_97 ( & V_184 ) ;
#endif
F_22 ( & V_23 ) ;
F_98 (cdev, tmp, &cdev_list_head, list) {
F_35 ( & V_3 -> V_22 ) ;
F_36 ( V_3 ) ;
}
F_24 ( & V_23 ) ;
F_99 ( & V_182 ) ;
F_100 ( V_180 ) ;
}
