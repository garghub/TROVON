static void F_1 ( const struct V_1 * V_2 )
{
#ifdef F_2
#define F_3 50
F_4 ( V_3 , L_1 , V_4 ,
16 , 1 , V_2 -> V_5 , F_5 ( F_3 , V_2 -> V_6 ) , true ) ;
#endif
}
static inline struct V_7 * F_6 ( const struct V_8 * V_9 )
{
return F_7 ( V_9 ) ;
}
static inline struct V_8 * F_8 ( const struct V_10 * V_11 )
{
return F_9 ( V_11 , struct V_7 , V_12 ) -> V_9 ;
}
static inline struct V_13 * F_10 ( const struct V_14 * V_15 )
{
return (struct V_13 * ) ( V_15 -> V_16 ) ;
}
static inline struct V_13 * F_11 ( const struct V_10 * V_11 )
{
return F_9 ( V_11 , struct V_13 , V_17 ) ;
}
static struct V_8 * F_12 ( const struct V_18 * V_19 )
{
struct V_10 * V_20 ;
struct V_8 * V_9 ;
switch ( V_19 -> V_21 ) {
case V_22 :
F_13 (lh, &br2684_devs) {
V_9 = F_8 ( V_20 ) ;
if ( F_6 ( V_9 ) -> V_23 == V_19 -> V_24 . V_25 )
return V_9 ;
}
break;
case V_26 :
F_13 (lh, &br2684_devs) {
V_9 = F_8 ( V_20 ) ;
if ( ! strncmp ( V_9 -> V_27 , V_19 -> V_24 . V_28 , V_29 ) )
return V_9 ;
}
break;
}
return NULL ;
}
static int F_14 ( struct V_30 * V_31 , unsigned long V_32 ,
void * V_33 )
{
struct V_34 * V_34 = V_33 ;
struct V_10 * V_20 ;
struct V_8 * V_9 ;
struct V_13 * V_35 ;
struct V_14 * V_14 ;
unsigned long V_36 ;
F_15 ( L_2 , V_32 , V_34 ) ;
F_16 ( & V_37 , V_36 ) ;
F_13 (lh, &br2684_devs) {
V_9 = F_8 ( V_20 ) ;
F_17 (brvcc, &BRPRIV(net_dev)->brvccs, brvccs) {
V_14 = V_35 -> V_15 ;
if ( V_14 && V_35 -> V_15 -> V_38 == V_34 ) {
if ( V_14 -> V_38 -> signal == V_39 )
F_18 ( V_9 ) ;
else
F_19 ( V_9 ) ;
}
}
}
F_20 ( & V_37 , V_36 ) ;
return V_40 ;
}
static void F_21 ( struct V_14 * V_41 , struct V_1 * V_2 )
{
struct V_13 * V_35 = F_10 ( V_41 ) ;
F_15 ( L_3 , V_41 , V_35 -> V_42 ) ;
V_35 -> V_43 ( V_41 , V_2 ) ;
if ( F_22 ( & V_35 -> V_44 ) == 1 )
F_23 ( V_35 -> V_42 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_8 * V_38 ,
struct V_13 * V_35 )
{
struct V_7 * V_45 = F_6 ( V_38 ) ;
struct V_14 * V_15 ;
int V_46 = ( V_35 -> V_47 == V_48 ) ?
( ( V_45 -> V_49 == V_50 ) ?
sizeof( V_51 ) : sizeof( V_52 ) ) :
( ( V_45 -> V_49 == V_50 ) ? V_53 : 0 ) ;
if ( F_25 ( V_2 ) < V_46 ) {
struct V_1 * V_54 = F_26 ( V_2 , V_46 ) ;
V_35 -> V_55 ++ ;
F_27 ( V_2 ) ;
if ( V_54 == NULL ) {
V_35 -> V_56 ++ ;
return 0 ;
}
V_2 = V_54 ;
}
if ( V_35 -> V_47 == V_48 ) {
if ( V_45 -> V_49 == V_50 ) {
F_28 ( V_2 , sizeof( V_51 ) ) ;
F_29 ( V_2 , V_51 ,
sizeof( V_51 ) ) ;
} else if ( V_45 -> V_49 == V_57 ) {
unsigned short V_58 = F_30 ( V_2 -> V_59 ) ;
F_28 ( V_2 , sizeof( V_52 ) ) ;
switch ( V_58 ) {
case V_60 :
F_29 ( V_2 , V_52 ,
sizeof( V_52 ) ) ;
break;
case V_61 :
F_29 ( V_2 , V_62 ,
sizeof( V_62 ) ) ;
break;
default:
F_27 ( V_2 ) ;
return 0 ;
}
}
} else {
if ( V_45 -> V_49 == V_50 ) {
F_28 ( V_2 , 2 ) ;
memset ( V_2 -> V_5 , 0 , 2 ) ;
}
}
F_1 ( V_2 ) ;
F_31 ( V_2 ) -> V_41 = V_15 = V_35 -> V_15 ;
F_15 ( L_4 , V_2 , V_15 , V_15 -> V_38 ) ;
F_32 ( V_2 -> V_63 , & F_33 ( V_15 ) -> V_64 ) ;
F_31 ( V_2 ) -> V_65 = V_15 -> V_65 ;
V_38 -> V_66 . V_67 ++ ;
V_38 -> V_66 . V_68 += V_2 -> V_6 ;
if ( F_34 ( & V_35 -> V_44 ) < 1 ) {
F_35 ( V_35 -> V_42 ) ;
if ( F_36 ( F_37 ( & V_35 -> V_44 ) > 0 ) )
F_23 ( V_35 -> V_42 ) ;
}
return ! V_15 -> V_69 ( V_15 , V_2 ) ;
}
static void F_38 ( struct V_14 * V_15 )
{
struct V_13 * V_35 = F_10 ( V_15 ) ;
if ( F_37 ( & V_35 -> V_44 ) > 0 )
F_23 ( V_35 -> V_42 ) ;
if ( V_35 -> V_70 )
V_35 -> V_70 ( V_15 ) ;
}
static inline struct V_13 * F_39 ( const struct V_1 * V_2 ,
const struct V_7 * V_45 )
{
return F_40 ( & V_45 -> V_17 ) ? NULL : F_11 ( V_45 -> V_17 . V_71 ) ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_8 * V_38 )
{
struct V_7 * V_45 = F_6 ( V_38 ) ;
struct V_13 * V_35 ;
struct V_14 * V_15 ;
T_1 V_72 = V_73 ;
F_15 ( L_5 , F_42 ( V_2 ) ) ;
F_43 ( & V_37 ) ;
V_35 = F_39 ( V_2 , V_45 ) ;
if ( V_35 == NULL ) {
F_15 ( L_6 , V_38 -> V_27 ) ;
V_38 -> V_66 . V_74 ++ ;
V_38 -> V_66 . V_75 ++ ;
F_27 ( V_2 ) ;
goto V_76;
}
V_15 = V_35 -> V_15 ;
F_44 ( F_33 ( V_15 ) ) ;
if ( F_45 ( V_77 , & V_15 -> V_36 ) ||
F_45 ( V_78 , & V_15 -> V_36 ) ||
! F_45 ( V_79 , & V_15 -> V_36 ) ) {
V_38 -> V_66 . V_80 ++ ;
F_27 ( V_2 ) ;
goto V_81;
}
if ( F_46 ( F_33 ( V_15 ) ) ) {
F_35 ( V_35 -> V_42 ) ;
V_72 = V_82 ;
goto V_81;
}
if ( ! F_24 ( V_2 , V_38 , V_35 ) ) {
V_38 -> V_66 . V_74 ++ ;
V_38 -> V_66 . V_83 ++ ;
}
V_81:
F_47 ( F_33 ( V_15 ) ) ;
V_76:
F_48 ( & V_37 ) ;
return V_72 ;
}
static int F_49 ( struct V_8 * V_38 , void * V_84 )
{
int V_85 = F_50 ( V_38 , V_84 ) ;
if ( ! V_85 )
F_6 ( V_38 ) -> V_86 = 1 ;
return V_85 ;
}
static int F_51 ( struct V_14 * V_15 , void T_2 * V_33 )
{
struct V_13 * V_35 ;
struct V_87 V_88 ;
if ( F_52 ( & V_88 , V_33 , sizeof V_88 ) )
return - V_89 ;
if ( V_88 . V_90 . V_21 != V_91 ) {
struct V_7 * V_45 ;
F_43 ( & V_37 ) ;
V_45 = F_6 ( F_12 ( & V_88 . V_90 ) ) ;
if ( V_45 == NULL || F_40 ( & V_45 -> V_17 ) ||
V_45 -> V_17 . V_71 != V_45 -> V_17 . V_92 )
V_35 = NULL ;
else
V_35 = F_11 ( V_45 -> V_17 . V_71 ) ;
F_48 ( & V_37 ) ;
if ( V_35 == NULL )
return - V_93 ;
} else
V_35 = F_10 ( V_15 ) ;
memcpy ( & V_35 -> V_94 , & V_88 . V_94 , sizeof( V_35 -> V_94 ) ) ;
return 0 ;
}
static inline int
F_53 ( T_3 type , struct V_13 * V_35 , struct V_1 * V_2 )
{
if ( V_35 -> V_94 . V_95 == 0 )
return 0 ;
if ( type == F_54 ( V_60 ) &&
( ( (struct V_96 * ) ( V_2 -> V_5 ) ) -> V_97 & V_35 -> V_94 .
V_95 ) == V_35 -> V_94 . V_98 )
return 0 ;
if ( type == F_54 ( V_99 ) )
return 0 ;
return 1 ;
}
static void F_55 ( struct V_13 * V_35 )
{
F_15 ( L_7 , V_35 , V_35 -> V_42 ) ;
F_56 ( & V_37 ) ;
F_57 ( & V_35 -> V_17 ) ;
F_58 ( & V_37 ) ;
V_35 -> V_15 -> V_16 = NULL ;
V_35 -> V_15 -> V_100 = V_35 -> V_70 ;
V_35 -> V_101 ( V_35 -> V_15 , NULL ) ;
F_59 ( V_35 -> V_102 ) ;
F_60 ( V_35 ) ;
}
static void F_61 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_13 * V_35 = F_10 ( V_15 ) ;
struct V_8 * V_9 = V_35 -> V_42 ;
struct V_7 * V_45 = F_6 ( V_9 ) ;
F_15 ( L_8 ) ;
if ( F_36 ( V_2 == NULL ) ) {
F_55 ( V_35 ) ;
if ( F_40 ( & V_45 -> V_17 ) ) {
F_56 ( & V_37 ) ;
F_57 ( & V_45 -> V_12 ) ;
F_58 ( & V_37 ) ;
F_62 ( V_9 ) ;
F_63 ( V_9 ) ;
}
return;
}
F_1 ( V_2 ) ;
F_64 ( V_15 , V_2 -> V_63 ) ;
F_15 ( L_9 , V_45 ) ;
if ( V_35 -> V_47 == V_48 ) {
if ( V_2 -> V_6 > 7 && V_2 -> V_5 [ 7 ] == 0x01 )
F_65 ( V_2 , V_2 -> V_6 - 4 ) ;
if ( ( V_2 -> V_6 >= ( sizeof( V_52 ) ) ) &&
( memcmp ( V_2 -> V_5 , V_52 ,
sizeof( V_52 ) - V_103 ) == 0 ) ) {
if ( memcmp ( V_2 -> V_5 + 6 , V_104 ,
sizeof( V_104 ) ) == 0 )
V_2 -> V_59 = F_54 ( V_61 ) ;
else if ( memcmp ( V_2 -> V_5 + 6 , V_105 ,
sizeof( V_105 ) ) == 0 )
V_2 -> V_59 = F_54 ( V_60 ) ;
else
goto error;
F_66 ( V_2 , sizeof( V_52 ) ) ;
F_67 ( V_2 ) ;
V_2 -> V_106 = V_107 ;
} else if ( ( V_2 -> V_6 >= sizeof( V_51 ) ) &&
( memcmp ( V_2 -> V_5 , V_51 , 7 ) == 0 ) ) {
F_66 ( V_2 , sizeof( V_51 ) ) ;
V_2 -> V_59 = F_68 ( V_2 , V_9 ) ;
} else
goto error;
} else {
if ( V_45 -> V_49 == V_57 ) {
struct V_96 * V_108 ;
F_67 ( V_2 ) ;
V_108 = F_69 ( V_2 ) ;
if ( V_108 -> V_109 == 4 )
V_2 -> V_59 = F_54 ( V_60 ) ;
else if ( V_108 -> V_109 == 6 )
V_2 -> V_59 = F_54 ( V_61 ) ;
else
goto error;
V_2 -> V_106 = V_107 ;
} else {
if ( memcmp ( V_2 -> V_5 , V_110 , V_53 ) != 0 )
goto error;
F_66 ( V_2 , V_53 ) ;
V_2 -> V_59 = F_68 ( V_2 , V_9 ) ;
}
}
#ifdef F_70
if ( F_36 ( F_53 ( V_2 -> V_59 , V_35 , V_2 ) ) )
goto V_111;
#endif
V_2 -> V_38 = V_9 ;
F_31 ( V_2 ) -> V_41 = V_15 ;
F_15 ( L_10 , F_30 ( V_2 -> V_59 ) ) ;
F_1 ( V_2 ) ;
if ( F_36 ( ! ( V_9 -> V_36 & V_112 ) ) )
goto V_111;
V_9 -> V_66 . V_113 ++ ;
V_9 -> V_66 . V_114 += V_2 -> V_6 ;
memset ( F_31 ( V_2 ) , 0 , sizeof( struct V_115 ) ) ;
F_71 ( V_2 ) ;
return;
V_111:
V_9 -> V_66 . V_116 ++ ;
goto V_117;
error:
V_9 -> V_66 . V_118 ++ ;
V_117:
F_27 ( V_2 ) ;
}
static int F_72 ( struct V_14 * V_15 , void T_2 * V_33 )
{
struct V_13 * V_35 ;
struct V_7 * V_45 ;
struct V_8 * V_9 ;
struct V_119 V_120 ;
int V_85 ;
if ( F_52 ( & V_120 , V_33 , sizeof V_120 ) )
return - V_89 ;
V_35 = F_73 ( sizeof( struct V_13 ) , V_121 ) ;
if ( ! V_35 )
return - V_122 ;
F_74 ( & V_35 -> V_44 , 2 ) ;
F_56 ( & V_37 ) ;
V_9 = F_12 ( & V_120 . V_90 ) ;
if ( V_9 == NULL ) {
F_75 ( L_11 ) ;
V_85 = - V_123 ;
goto error;
}
V_45 = F_6 ( V_9 ) ;
if ( V_15 -> V_124 == NULL ) {
V_85 = - V_125 ;
goto error;
}
if ( ! F_40 ( & V_45 -> V_17 ) ) {
V_85 = - V_126 ;
goto error;
}
if ( V_120 . V_127 != V_128 ||
V_120 . V_129 != V_130 ||
V_120 . V_131 || V_120 . V_132 || V_120 . V_133 ||
( V_120 . V_47 != V_134 &&
V_120 . V_47 != V_135 ) ||
V_120 . V_136 != 0 ) {
V_85 = - V_137 ;
goto error;
}
F_15 ( L_12 , V_15 , V_120 . V_47 , V_35 ) ;
if ( F_40 ( & V_45 -> V_17 ) && ! V_45 -> V_86 ) {
unsigned char * V_138 = V_15 -> V_38 -> V_138 ;
if ( V_138 [ 0 ] | V_138 [ 1 ] | V_138 [ 2 ] | V_138 [ 3 ] | V_138 [ 4 ] | V_138 [ 5 ] )
memcpy ( V_9 -> V_139 , V_138 , V_9 -> V_140 ) ;
else
V_9 -> V_139 [ 2 ] = 1 ;
}
F_76 ( & V_35 -> V_17 , & V_45 -> V_17 ) ;
F_58 ( & V_37 ) ;
V_35 -> V_42 = V_9 ;
V_35 -> V_15 = V_15 ;
V_15 -> V_16 = V_35 ;
V_35 -> V_47 = (enum V_141 ) V_120 . V_47 ;
V_35 -> V_101 = V_15 -> V_124 ;
V_35 -> V_43 = V_15 -> V_142 ;
V_35 -> V_70 = V_15 -> V_100 ;
V_35 -> V_102 = V_15 -> V_143 ;
F_77 () ;
V_15 -> V_124 = F_61 ;
V_15 -> V_142 = F_21 ;
V_15 -> V_100 = F_38 ;
V_15 -> V_143 = V_144 ;
if ( V_15 -> V_38 -> signal == V_39 )
F_18 ( V_9 ) ;
else
F_19 ( V_9 ) ;
F_78 ( V_144 ) ;
F_79 ( V_15 ) ;
return 0 ;
error:
F_58 ( & V_37 ) ;
F_60 ( V_35 ) ;
return V_85 ;
}
static void F_80 ( struct V_8 * V_145 )
{
struct V_7 * V_45 = F_6 ( V_145 ) ;
F_81 ( V_145 ) ;
V_145 -> V_146 += sizeof( V_51 ) ;
V_45 -> V_9 = V_145 ;
V_145 -> V_147 = & V_148 ;
F_82 ( & V_45 -> V_17 ) ;
}
static void F_83 ( struct V_8 * V_145 )
{
struct V_7 * V_45 = F_6 ( V_145 ) ;
V_45 -> V_9 = V_145 ;
V_145 -> V_146 = sizeof( V_52 ) ;
V_145 -> V_147 = & V_149 ;
V_145 -> V_140 = 0 ;
V_145 -> V_150 = 1500 ;
V_145 -> type = V_151 ;
V_145 -> V_36 = V_152 | V_153 | V_154 ;
V_145 -> V_155 = 100 ;
F_82 ( & V_45 -> V_17 ) ;
}
static int F_84 ( void T_2 * V_33 )
{
int V_85 ;
struct V_8 * V_145 ;
struct V_7 * V_45 ;
struct V_156 V_157 ;
enum V_158 V_49 ;
F_15 ( L_8 ) ;
if ( F_52 ( & V_157 , V_33 , sizeof V_157 ) )
return - V_89 ;
if ( V_157 . V_159 & V_160 )
V_49 = V_57 ;
else
V_49 = V_50 ;
V_157 . V_159 &= 0xffff ;
if ( V_157 . V_159 != V_161 || V_157 . V_150 != 1500 )
return - V_137 ;
V_145 = F_85 ( sizeof( struct V_7 ) ,
V_157 . V_28 [ 0 ] ? V_157 . V_28 : L_13 ,
V_162 ,
( V_49 == V_57 ) ? F_83 : F_80 ) ;
if ( ! V_145 )
return - V_122 ;
V_45 = F_6 ( V_145 ) ;
F_15 ( L_14 , V_145 -> V_27 ) ;
V_85 = F_86 ( V_145 ) ;
if ( V_85 < 0 ) {
F_75 ( L_15 ) ;
F_63 ( V_145 ) ;
return V_85 ;
}
F_56 ( & V_37 ) ;
V_45 -> V_49 = V_49 ;
if ( F_40 ( & V_12 ) ) {
V_45 -> V_23 = 1 ;
} else
V_45 -> V_23 = F_6 ( F_8 ( V_12 . V_92 ) ) -> V_23 + 1 ;
F_87 ( & V_45 -> V_12 , & V_12 ) ;
F_58 ( & V_37 ) ;
return 0 ;
}
static int F_88 ( struct V_163 * V_164 , unsigned int V_165 ,
unsigned long V_33 )
{
struct V_14 * V_15 = F_89 ( V_164 ) ;
void T_2 * V_166 = ( void T_2 * ) V_33 ;
T_4 V_167 ;
int V_85 ;
switch ( V_165 ) {
case V_168 :
case V_169 :
V_85 = F_90 ( V_167 , ( T_4 T_2 * ) V_166 ) ;
if ( V_85 )
return - V_89 ;
if ( V_167 != V_170 )
return - V_171 ;
if ( ! F_91 ( V_172 ) )
return - V_173 ;
if ( V_165 == V_168 ) {
if ( V_164 -> V_174 != V_175 )
return - V_137 ;
return F_72 ( V_15 , V_166 ) ;
} else {
return F_84 ( V_166 ) ;
}
#ifdef F_70
case V_176 :
if ( V_15 -> V_124 != F_61 )
return - V_171 ;
if ( ! F_91 ( V_172 ) )
return - V_173 ;
V_85 = F_51 ( V_15 , V_166 ) ;
return V_85 ;
#endif
}
return - V_171 ;
}
static void * F_92 ( struct V_177 * V_178 , T_5 * V_179 )
__acquires( V_37 )
{
F_43 ( & V_37 ) ;
return F_93 ( & V_12 , * V_179 ) ;
}
static void * F_94 ( struct V_177 * V_178 , void * V_180 , T_5 * V_179 )
{
return F_95 ( V_180 , & V_12 , V_179 ) ;
}
static void F_96 ( struct V_177 * V_178 , void * V_180 )
__releases( V_37 )
{
F_48 ( & V_37 ) ;
}
static int F_97 ( struct V_177 * V_178 , void * V_180 )
{
const struct V_7 * V_45 = F_9 ( V_180 , struct V_7 ,
V_12 ) ;
const struct V_8 * V_9 = V_45 -> V_9 ;
const struct V_13 * V_35 ;
F_98 ( V_178 , L_16 ,
V_9 -> V_27 ,
V_45 -> V_23 ,
V_9 -> V_139 ,
V_45 -> V_86 ? L_17 : L_18 ) ;
F_17 (brvcc, &brdev->brvccs, brvccs) {
F_98 ( V_178 , L_19
L_20
L_8 , V_35 -> V_15 -> V_38 -> V_23 ,
V_35 -> V_15 -> V_181 , V_35 -> V_15 -> V_182 ,
( V_35 -> V_47 == V_48 ) ? L_21 : L_22 ,
( V_45 -> V_49 == V_50 ) ? L_23 : L_24 ,
V_35 -> V_56 , V_35 -> V_55 ) ;
#ifdef F_70
#define F_99 ( T_6 , T_7 ) ((u8 *) &brvcc->filter.var)[byte]
#define F_100 ( T_6 ) b1(var, 0), b1(var, 1), b1(var, 2), b1(var, 3)
if ( V_35 -> V_94 . V_95 != 0 )
F_98 ( V_178 , L_25
L_26 , F_100 ( V_98 ) , F_100 ( V_95 ) ) ;
#undef F_100
#undef F_99
#endif
}
return 0 ;
}
static int F_101 ( struct V_183 * V_183 , struct V_184 * V_184 )
{
return F_102 ( V_184 , & V_185 ) ;
}
static int T_8 F_103 ( void )
{
#ifdef F_104
struct V_186 * V_84 ;
V_84 = F_105 ( L_27 , 0 , V_187 , & V_188 ) ;
if ( V_84 == NULL )
return - V_122 ;
#endif
F_106 ( & V_189 ) ;
F_107 ( & V_190 ) ;
return 0 ;
}
static void T_9 F_108 ( void )
{
struct V_8 * V_9 ;
struct V_7 * V_45 ;
struct V_13 * V_35 ;
F_109 ( & V_189 ) ;
#ifdef F_104
F_110 ( L_27 , V_187 ) ;
#endif
F_111 ( & V_190 ) ;
while ( ! F_40 ( & V_12 ) ) {
V_9 = F_8 ( V_12 . V_71 ) ;
V_45 = F_6 ( V_9 ) ;
while ( ! F_40 ( & V_45 -> V_17 ) ) {
V_35 = F_11 ( V_45 -> V_17 . V_71 ) ;
F_55 ( V_35 ) ;
}
F_57 ( & V_45 -> V_12 ) ;
F_62 ( V_9 ) ;
F_63 ( V_9 ) ;
}
}
