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
struct V_8 * V_9 = V_2 -> V_38 ;
F_15 ( L_3 , V_41 , V_9 ) ;
V_35 -> V_42 ( V_41 , V_2 ) ;
if ( ! V_9 )
return;
if ( F_22 ( V_41 , 0 ) )
F_23 ( V_9 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_8 * V_38 ,
struct V_13 * V_35 )
{
struct V_7 * V_43 = F_6 ( V_38 ) ;
struct V_14 * V_15 ;
int V_44 = ( V_35 -> V_45 == V_46 ) ? 10 : 2 ;
if ( F_25 ( V_2 ) < V_44 ) {
struct V_1 * V_47 = F_26 ( V_2 , V_44 ) ;
V_35 -> V_48 ++ ;
F_27 ( V_2 ) ;
if ( V_47 == NULL ) {
V_35 -> V_49 ++ ;
return 0 ;
}
V_2 = V_47 ;
}
if ( V_35 -> V_45 == V_46 ) {
if ( V_43 -> V_50 == V_51 ) {
F_28 ( V_2 , sizeof( V_52 ) ) ;
F_29 ( V_2 , V_52 ,
sizeof( V_52 ) ) ;
} else if ( V_43 -> V_50 == V_53 ) {
unsigned short V_54 = F_30 ( V_2 -> V_55 ) ;
F_28 ( V_2 , sizeof( V_56 ) ) ;
switch ( V_54 ) {
case V_57 :
F_29 ( V_2 , V_56 ,
sizeof( V_56 ) ) ;
break;
case V_58 :
F_29 ( V_2 , V_59 ,
sizeof( V_59 ) ) ;
break;
default:
F_27 ( V_2 ) ;
return 0 ;
}
}
} else {
if ( V_43 -> V_50 == V_51 ) {
F_28 ( V_2 , 2 ) ;
memset ( V_2 -> V_5 , 0 , 2 ) ;
}
}
F_1 ( V_2 ) ;
F_31 ( V_2 ) -> V_41 = V_15 = V_35 -> V_15 ;
F_15 ( L_4 , V_2 , V_15 , V_15 -> V_38 ) ;
F_32 ( V_2 -> V_60 , & F_33 ( V_15 ) -> V_61 ) ;
F_31 ( V_2 ) -> V_62 = V_15 -> V_62 ;
V_38 -> V_63 . V_64 ++ ;
V_38 -> V_63 . V_65 += V_2 -> V_6 ;
V_15 -> V_66 ( V_15 , V_2 ) ;
if ( ! F_22 ( V_15 , 0 ) ) {
F_34 ( V_35 -> V_67 ) ;
if ( F_22 ( V_15 , 0 ) )
F_35 ( V_35 -> V_67 ) ;
}
return 1 ;
}
static inline struct V_13 * F_36 ( const struct V_1 * V_2 ,
const struct V_7 * V_43 )
{
return F_37 ( & V_43 -> V_17 ) ? NULL : F_11 ( V_43 -> V_17 . V_68 ) ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_8 * V_38 )
{
struct V_7 * V_43 = F_6 ( V_38 ) ;
struct V_13 * V_35 ;
F_15 ( L_5 , F_39 ( V_2 ) ) ;
F_40 ( & V_37 ) ;
V_35 = F_36 ( V_2 , V_43 ) ;
if ( V_35 == NULL ) {
F_15 ( L_6 , V_38 -> V_27 ) ;
V_38 -> V_63 . V_69 ++ ;
V_38 -> V_63 . V_70 ++ ;
F_27 ( V_2 ) ;
F_41 ( & V_37 ) ;
return V_71 ;
}
if ( ! F_24 ( V_2 , V_38 , V_35 ) ) {
V_38 -> V_63 . V_69 ++ ;
V_38 -> V_63 . V_72 ++ ;
}
F_41 ( & V_37 ) ;
return V_71 ;
}
static int F_42 ( struct V_8 * V_38 , void * V_73 )
{
int V_74 = F_43 ( V_38 , V_73 ) ;
if ( ! V_74 )
F_6 ( V_38 ) -> V_75 = 1 ;
return V_74 ;
}
static int F_44 ( struct V_14 * V_15 , void T_2 * V_33 )
{
struct V_13 * V_35 ;
struct V_76 V_77 ;
if ( F_45 ( & V_77 , V_33 , sizeof V_77 ) )
return - V_78 ;
if ( V_77 . V_79 . V_21 != V_80 ) {
struct V_7 * V_43 ;
F_40 ( & V_37 ) ;
V_43 = F_6 ( F_12 ( & V_77 . V_79 ) ) ;
if ( V_43 == NULL || F_37 ( & V_43 -> V_17 ) ||
V_43 -> V_17 . V_68 != V_43 -> V_17 . V_81 )
V_35 = NULL ;
else
V_35 = F_11 ( V_43 -> V_17 . V_68 ) ;
F_41 ( & V_37 ) ;
if ( V_35 == NULL )
return - V_82 ;
} else
V_35 = F_10 ( V_15 ) ;
memcpy ( & V_35 -> V_83 , & V_77 . V_83 , sizeof( V_35 -> V_83 ) ) ;
return 0 ;
}
static inline int
F_46 ( T_3 type , struct V_13 * V_35 , struct V_1 * V_2 )
{
if ( V_35 -> V_83 . V_84 == 0 )
return 0 ;
if ( type == F_47 ( V_57 ) &&
( ( (struct V_85 * ) ( V_2 -> V_5 ) ) -> V_86 & V_35 -> V_83 .
V_84 ) == V_35 -> V_83 . V_87 )
return 0 ;
if ( type == F_47 ( V_88 ) )
return 0 ;
return 1 ;
}
static void F_48 ( struct V_13 * V_35 )
{
F_15 ( L_7 , V_35 , V_35 -> V_67 ) ;
F_49 ( & V_37 ) ;
F_50 ( & V_35 -> V_17 ) ;
F_51 ( & V_37 ) ;
V_35 -> V_15 -> V_16 = NULL ;
V_35 -> V_89 ( V_35 -> V_15 , NULL ) ;
F_52 ( V_35 ) ;
F_53 ( V_90 ) ;
}
static void F_54 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_13 * V_35 = F_10 ( V_15 ) ;
struct V_8 * V_9 = V_35 -> V_67 ;
struct V_7 * V_43 = F_6 ( V_9 ) ;
F_15 ( L_8 ) ;
if ( F_55 ( V_2 == NULL ) ) {
F_48 ( V_35 ) ;
if ( F_37 ( & V_43 -> V_17 ) ) {
F_49 ( & V_37 ) ;
F_50 ( & V_43 -> V_12 ) ;
F_51 ( & V_37 ) ;
F_56 ( V_9 ) ;
F_57 ( V_9 ) ;
}
return;
}
F_1 ( V_2 ) ;
F_58 ( V_15 , V_2 -> V_60 ) ;
F_15 ( L_9 , V_43 ) ;
if ( V_35 -> V_45 == V_46 ) {
if ( V_2 -> V_6 > 7 && V_2 -> V_5 [ 7 ] == 0x01 )
F_59 ( V_2 , V_2 -> V_6 - 4 ) ;
if ( ( V_2 -> V_6 >= ( sizeof( V_56 ) ) ) &&
( memcmp ( V_2 -> V_5 , V_56 ,
sizeof( V_56 ) - V_91 ) == 0 ) ) {
if ( memcmp ( V_2 -> V_5 + 6 , V_92 ,
sizeof( V_92 ) ) == 0 )
V_2 -> V_55 = F_47 ( V_58 ) ;
else if ( memcmp ( V_2 -> V_5 + 6 , V_93 ,
sizeof( V_93 ) ) == 0 )
V_2 -> V_55 = F_47 ( V_57 ) ;
else
goto error;
F_60 ( V_2 , sizeof( V_56 ) ) ;
F_61 ( V_2 ) ;
V_2 -> V_94 = V_95 ;
} else if ( ( V_2 -> V_6 >= sizeof( V_52 ) ) &&
( memcmp ( V_2 -> V_5 , V_52 , 7 ) == 0 ) ) {
F_60 ( V_2 , sizeof( V_52 ) ) ;
V_2 -> V_55 = F_62 ( V_2 , V_9 ) ;
} else
goto error;
} else {
if ( V_43 -> V_50 == V_53 ) {
struct V_85 * V_96 ;
F_61 ( V_2 ) ;
V_96 = F_63 ( V_2 ) ;
if ( V_96 -> V_97 == 4 )
V_2 -> V_55 = F_47 ( V_57 ) ;
else if ( V_96 -> V_97 == 6 )
V_2 -> V_55 = F_47 ( V_58 ) ;
else
goto error;
V_2 -> V_94 = V_95 ;
} else {
if ( * ( ( V_98 * ) ( V_2 -> V_5 ) ) != 0 )
goto error;
F_60 ( V_2 , V_99 ) ;
V_2 -> V_55 = F_62 ( V_2 , V_9 ) ;
}
}
#ifdef F_64
if ( F_55 ( F_46 ( V_2 -> V_55 , V_35 , V_2 ) ) )
goto V_100;
#endif
V_2 -> V_38 = V_9 ;
F_31 ( V_2 ) -> V_41 = V_15 ;
F_15 ( L_10 , F_30 ( V_2 -> V_55 ) ) ;
F_1 ( V_2 ) ;
if ( F_55 ( ! ( V_9 -> V_36 & V_101 ) ) )
goto V_100;
V_9 -> V_63 . V_102 ++ ;
V_9 -> V_63 . V_103 += V_2 -> V_6 ;
memset ( F_31 ( V_2 ) , 0 , sizeof( struct V_104 ) ) ;
F_65 ( V_2 ) ;
return;
V_100:
V_9 -> V_63 . V_105 ++ ;
goto V_106;
error:
V_9 -> V_63 . V_107 ++ ;
V_106:
F_27 ( V_2 ) ;
}
static int F_66 ( struct V_14 * V_15 , void T_2 * V_33 )
{
struct V_108 V_109 ;
int V_74 ;
struct V_13 * V_35 ;
struct V_1 * V_2 , * V_110 ;
struct V_108 * V_111 ;
struct V_7 * V_43 ;
struct V_8 * V_9 ;
struct V_112 V_113 ;
unsigned long V_36 ;
if ( F_45 ( & V_113 , V_33 , sizeof V_113 ) )
return - V_78 ;
V_35 = F_67 ( sizeof( struct V_13 ) , V_114 ) ;
if ( ! V_35 )
return - V_115 ;
F_49 ( & V_37 ) ;
V_9 = F_12 ( & V_113 . V_79 ) ;
if ( V_9 == NULL ) {
F_68 ( L_11 ) ;
V_74 = - V_116 ;
goto error;
}
V_43 = F_6 ( V_9 ) ;
if ( V_15 -> V_117 == NULL ) {
V_74 = - V_118 ;
goto error;
}
if ( ! F_37 ( & V_43 -> V_17 ) ) {
V_74 = - V_119 ;
goto error;
}
if ( V_113 . V_120 != V_121 ||
V_113 . V_122 != V_123 ||
V_113 . V_124 || V_113 . V_125 || V_113 . V_126 ||
( V_113 . V_45 != V_127 &&
V_113 . V_45 != V_128 ) ||
V_113 . V_129 != 0 ) {
V_74 = - V_130 ;
goto error;
}
F_15 ( L_12 , V_15 , V_113 . V_45 , V_35 ) ;
if ( F_37 ( & V_43 -> V_17 ) && ! V_43 -> V_75 ) {
unsigned char * V_131 = V_15 -> V_38 -> V_131 ;
if ( V_131 [ 0 ] | V_131 [ 1 ] | V_131 [ 2 ] | V_131 [ 3 ] | V_131 [ 4 ] | V_131 [ 5 ] )
memcpy ( V_9 -> V_132 , V_131 , V_9 -> V_133 ) ;
else
V_9 -> V_132 [ 2 ] = 1 ;
}
F_69 ( & V_35 -> V_17 , & V_43 -> V_17 ) ;
F_51 ( & V_37 ) ;
V_35 -> V_67 = V_9 ;
V_35 -> V_15 = V_15 ;
V_15 -> V_16 = V_35 ;
V_35 -> V_45 = (enum V_134 ) V_113 . V_45 ;
V_35 -> V_89 = V_15 -> V_117 ;
V_35 -> V_42 = V_15 -> V_135 ;
F_70 () ;
V_15 -> V_117 = F_54 ;
V_15 -> V_135 = F_21 ;
F_71 ( & V_109 ) ;
V_111 = & F_33 ( V_15 ) -> V_136 ;
F_72 ( & V_111 -> V_137 , V_36 ) ;
F_73 ( V_111 , & V_109 ) ;
F_74 ( & V_111 -> V_137 , V_36 ) ;
F_75 (&queue, skb, tmp) {
struct V_8 * V_38 ;
F_54 ( V_15 , V_2 ) ;
V_38 = V_2 -> V_38 ;
V_38 -> V_63 . V_103 -= V_2 -> V_6 ;
V_38 -> V_63 . V_102 -- ;
}
if ( V_15 -> V_38 -> signal == V_39 )
F_18 ( V_9 ) ;
else
F_19 ( V_9 ) ;
F_76 ( V_90 ) ;
return 0 ;
error:
F_51 ( & V_37 ) ;
F_52 ( V_35 ) ;
return V_74 ;
}
static void F_77 ( struct V_8 * V_138 )
{
struct V_7 * V_43 = F_6 ( V_138 ) ;
F_78 ( V_138 ) ;
V_43 -> V_9 = V_138 ;
V_138 -> V_139 = & V_140 ;
F_79 ( & V_43 -> V_17 ) ;
}
static void F_80 ( struct V_8 * V_138 )
{
struct V_7 * V_43 = F_6 ( V_138 ) ;
V_43 -> V_9 = V_138 ;
V_138 -> V_141 = 0 ;
V_138 -> V_139 = & V_142 ;
V_138 -> V_133 = 0 ;
V_138 -> V_143 = 1500 ;
V_138 -> type = V_144 ;
V_138 -> V_36 = V_145 | V_146 | V_147 ;
V_138 -> V_148 = 100 ;
F_79 ( & V_43 -> V_17 ) ;
}
static int F_81 ( void T_2 * V_33 )
{
int V_74 ;
struct V_8 * V_138 ;
struct V_7 * V_43 ;
struct V_149 V_150 ;
enum V_151 V_50 ;
F_15 ( L_8 ) ;
if ( F_45 ( & V_150 , V_33 , sizeof V_150 ) )
return - V_78 ;
if ( V_150 . V_152 & V_153 )
V_50 = V_53 ;
else
V_50 = V_51 ;
V_150 . V_152 &= 0xffff ;
if ( V_150 . V_152 != V_154 || V_150 . V_143 != 1500 )
return - V_130 ;
V_138 = F_82 ( sizeof( struct V_7 ) ,
V_150 . V_28 [ 0 ] ? V_150 . V_28 : L_13 ,
( V_50 == V_53 ) ?
F_80 : F_77 ) ;
if ( ! V_138 )
return - V_115 ;
V_43 = F_6 ( V_138 ) ;
F_15 ( L_14 , V_138 -> V_27 ) ;
V_74 = F_83 ( V_138 ) ;
if ( V_74 < 0 ) {
F_68 ( L_15 ) ;
F_57 ( V_138 ) ;
return V_74 ;
}
F_49 ( & V_37 ) ;
V_43 -> V_50 = V_50 ;
if ( F_37 ( & V_12 ) ) {
V_43 -> V_23 = 1 ;
} else
V_43 -> V_23 = F_6 ( F_8 ( V_12 . V_81 ) ) -> V_23 + 1 ;
F_84 ( & V_43 -> V_12 , & V_12 ) ;
F_51 ( & V_37 ) ;
return 0 ;
}
static int F_85 ( struct V_155 * V_156 , unsigned int V_157 ,
unsigned long V_33 )
{
struct V_14 * V_15 = F_86 ( V_156 ) ;
void T_2 * V_158 = ( void T_2 * ) V_33 ;
T_4 V_159 ;
int V_74 ;
switch ( V_157 ) {
case V_160 :
case V_161 :
V_74 = F_87 ( V_159 , ( T_4 T_2 * ) V_158 ) ;
if ( V_74 )
return - V_78 ;
if ( V_159 != V_162 )
return - V_163 ;
if ( ! F_88 ( V_164 ) )
return - V_165 ;
if ( V_157 == V_160 )
return F_66 ( V_15 , V_158 ) ;
else
return F_81 ( V_158 ) ;
#ifdef F_64
case V_166 :
if ( V_15 -> V_117 != F_54 )
return - V_163 ;
if ( ! F_88 ( V_164 ) )
return - V_165 ;
V_74 = F_44 ( V_15 , V_158 ) ;
return V_74 ;
#endif
}
return - V_163 ;
}
static void * F_89 ( struct V_167 * V_168 , T_5 * V_169 )
__acquires( V_37 )
{
F_40 ( & V_37 ) ;
return F_90 ( & V_12 , * V_169 ) ;
}
static void * F_91 ( struct V_167 * V_168 , void * V_170 , T_5 * V_169 )
{
return F_92 ( V_170 , & V_12 , V_169 ) ;
}
static void F_93 ( struct V_167 * V_168 , void * V_170 )
__releases( V_37 )
{
F_41 ( & V_37 ) ;
}
static int F_94 ( struct V_167 * V_168 , void * V_170 )
{
const struct V_7 * V_43 = F_9 ( V_170 , struct V_7 ,
V_12 ) ;
const struct V_8 * V_9 = V_43 -> V_9 ;
const struct V_13 * V_35 ;
F_95 ( V_168 , L_16 ,
V_9 -> V_27 ,
V_43 -> V_23 ,
V_9 -> V_132 ,
V_43 -> V_75 ? L_17 : L_18 ) ;
F_17 (brvcc, &brdev->brvccs, brvccs) {
F_95 ( V_168 , L_19
L_20
L_8 , V_35 -> V_15 -> V_38 -> V_23 ,
V_35 -> V_15 -> V_171 , V_35 -> V_15 -> V_172 ,
( V_35 -> V_45 == V_46 ) ? L_21 : L_22 ,
( V_43 -> V_50 == V_51 ) ? L_23 : L_24 ,
V_35 -> V_49 , V_35 -> V_48 ) ;
#ifdef F_64
#define F_96 ( T_6 , T_7 ) ((u8 *) &brvcc->filter.var)[byte]
#define F_97 ( T_6 ) b1(var, 0), b1(var, 1), b1(var, 2), b1(var, 3)
if ( V_35 -> V_83 . V_84 != 0 )
F_95 ( V_168 , L_25
L_26 , F_97 ( V_87 ) , F_97 ( V_84 ) ) ;
#undef F_97
#undef F_96
#endif
}
return 0 ;
}
static int F_98 ( struct V_173 * V_173 , struct V_174 * V_174 )
{
return F_99 ( V_174 , & V_175 ) ;
}
static int T_8 F_100 ( void )
{
#ifdef F_101
struct V_176 * V_73 ;
V_73 = F_102 ( L_27 , 0 , V_177 , & V_178 ) ;
if ( V_73 == NULL )
return - V_115 ;
#endif
F_103 ( & V_179 ) ;
F_104 ( & V_180 ) ;
return 0 ;
}
static void T_9 F_105 ( void )
{
struct V_8 * V_9 ;
struct V_7 * V_43 ;
struct V_13 * V_35 ;
F_106 ( & V_179 ) ;
#ifdef F_101
F_107 ( L_27 , V_177 ) ;
#endif
F_108 ( & V_180 ) ;
while ( ! F_37 ( & V_12 ) ) {
V_9 = F_8 ( V_12 . V_68 ) ;
V_43 = F_6 ( V_9 ) ;
while ( ! F_37 ( & V_43 -> V_17 ) ) {
V_35 = F_11 ( V_43 -> V_17 . V_68 ) ;
F_48 ( V_35 ) ;
}
F_50 ( & V_43 -> V_12 ) ;
F_56 ( V_9 ) ;
F_57 ( V_9 ) ;
}
}
