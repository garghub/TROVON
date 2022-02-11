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
int V_44 = ( V_35 -> V_45 == V_46 ) ?
( ( V_43 -> V_47 == V_48 ) ?
sizeof( V_49 ) : sizeof( V_50 ) ) :
( ( V_43 -> V_47 == V_48 ) ? V_51 : 0 ) ;
if ( F_25 ( V_2 ) < V_44 ) {
struct V_1 * V_52 = F_26 ( V_2 , V_44 ) ;
V_35 -> V_53 ++ ;
F_27 ( V_2 ) ;
if ( V_52 == NULL ) {
V_35 -> V_54 ++ ;
return 0 ;
}
V_2 = V_52 ;
}
if ( V_35 -> V_45 == V_46 ) {
if ( V_43 -> V_47 == V_48 ) {
F_28 ( V_2 , sizeof( V_49 ) ) ;
F_29 ( V_2 , V_49 ,
sizeof( V_49 ) ) ;
} else if ( V_43 -> V_47 == V_55 ) {
unsigned short V_56 = F_30 ( V_2 -> V_57 ) ;
F_28 ( V_2 , sizeof( V_50 ) ) ;
switch ( V_56 ) {
case V_58 :
F_29 ( V_2 , V_50 ,
sizeof( V_50 ) ) ;
break;
case V_59 :
F_29 ( V_2 , V_60 ,
sizeof( V_60 ) ) ;
break;
default:
F_27 ( V_2 ) ;
return 0 ;
}
}
} else {
if ( V_43 -> V_47 == V_48 ) {
F_28 ( V_2 , 2 ) ;
memset ( V_2 -> V_5 , 0 , 2 ) ;
}
}
F_1 ( V_2 ) ;
F_31 ( V_2 ) -> V_41 = V_15 = V_35 -> V_15 ;
F_15 ( L_4 , V_2 , V_15 , V_15 -> V_38 ) ;
F_32 ( V_2 -> V_61 , & F_33 ( V_15 ) -> V_62 ) ;
F_31 ( V_2 ) -> V_63 = V_15 -> V_63 ;
V_38 -> V_64 . V_65 ++ ;
V_38 -> V_64 . V_66 += V_2 -> V_6 ;
V_15 -> V_67 ( V_15 , V_2 ) ;
if ( ! F_22 ( V_15 , 0 ) ) {
F_34 ( V_35 -> V_68 ) ;
if ( F_22 ( V_15 , 0 ) )
F_35 ( V_35 -> V_68 ) ;
}
return 1 ;
}
static inline struct V_13 * F_36 ( const struct V_1 * V_2 ,
const struct V_7 * V_43 )
{
return F_37 ( & V_43 -> V_17 ) ? NULL : F_11 ( V_43 -> V_17 . V_69 ) ;
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
V_38 -> V_64 . V_70 ++ ;
V_38 -> V_64 . V_71 ++ ;
F_27 ( V_2 ) ;
F_41 ( & V_37 ) ;
return V_72 ;
}
if ( ! F_24 ( V_2 , V_38 , V_35 ) ) {
V_38 -> V_64 . V_70 ++ ;
V_38 -> V_64 . V_73 ++ ;
}
F_41 ( & V_37 ) ;
return V_72 ;
}
static int F_42 ( struct V_8 * V_38 , void * V_74 )
{
int V_75 = F_43 ( V_38 , V_74 ) ;
if ( ! V_75 )
F_6 ( V_38 ) -> V_76 = 1 ;
return V_75 ;
}
static int F_44 ( struct V_14 * V_15 , void T_2 * V_33 )
{
struct V_13 * V_35 ;
struct V_77 V_78 ;
if ( F_45 ( & V_78 , V_33 , sizeof V_78 ) )
return - V_79 ;
if ( V_78 . V_80 . V_21 != V_81 ) {
struct V_7 * V_43 ;
F_40 ( & V_37 ) ;
V_43 = F_6 ( F_12 ( & V_78 . V_80 ) ) ;
if ( V_43 == NULL || F_37 ( & V_43 -> V_17 ) ||
V_43 -> V_17 . V_69 != V_43 -> V_17 . V_82 )
V_35 = NULL ;
else
V_35 = F_11 ( V_43 -> V_17 . V_69 ) ;
F_41 ( & V_37 ) ;
if ( V_35 == NULL )
return - V_83 ;
} else
V_35 = F_10 ( V_15 ) ;
memcpy ( & V_35 -> V_84 , & V_78 . V_84 , sizeof( V_35 -> V_84 ) ) ;
return 0 ;
}
static inline int
F_46 ( T_3 type , struct V_13 * V_35 , struct V_1 * V_2 )
{
if ( V_35 -> V_84 . V_85 == 0 )
return 0 ;
if ( type == F_47 ( V_58 ) &&
( ( (struct V_86 * ) ( V_2 -> V_5 ) ) -> V_87 & V_35 -> V_84 .
V_85 ) == V_35 -> V_84 . V_88 )
return 0 ;
if ( type == F_47 ( V_89 ) )
return 0 ;
return 1 ;
}
static void F_48 ( struct V_13 * V_35 )
{
F_15 ( L_7 , V_35 , V_35 -> V_68 ) ;
F_49 ( & V_37 ) ;
F_50 ( & V_35 -> V_17 ) ;
F_51 ( & V_37 ) ;
V_35 -> V_15 -> V_16 = NULL ;
V_35 -> V_90 ( V_35 -> V_15 , NULL ) ;
F_52 ( V_35 ) ;
F_53 ( V_91 ) ;
}
static void F_54 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_13 * V_35 = F_10 ( V_15 ) ;
struct V_8 * V_9 = V_35 -> V_68 ;
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
F_58 ( V_15 , V_2 -> V_61 ) ;
F_15 ( L_9 , V_43 ) ;
if ( V_35 -> V_45 == V_46 ) {
if ( V_2 -> V_6 > 7 && V_2 -> V_5 [ 7 ] == 0x01 )
F_59 ( V_2 , V_2 -> V_6 - 4 ) ;
if ( ( V_2 -> V_6 >= ( sizeof( V_50 ) ) ) &&
( memcmp ( V_2 -> V_5 , V_50 ,
sizeof( V_50 ) - V_92 ) == 0 ) ) {
if ( memcmp ( V_2 -> V_5 + 6 , V_93 ,
sizeof( V_93 ) ) == 0 )
V_2 -> V_57 = F_47 ( V_59 ) ;
else if ( memcmp ( V_2 -> V_5 + 6 , V_94 ,
sizeof( V_94 ) ) == 0 )
V_2 -> V_57 = F_47 ( V_58 ) ;
else
goto error;
F_60 ( V_2 , sizeof( V_50 ) ) ;
F_61 ( V_2 ) ;
V_2 -> V_95 = V_96 ;
} else if ( ( V_2 -> V_6 >= sizeof( V_49 ) ) &&
( memcmp ( V_2 -> V_5 , V_49 , 7 ) == 0 ) ) {
F_60 ( V_2 , sizeof( V_49 ) ) ;
V_2 -> V_57 = F_62 ( V_2 , V_9 ) ;
} else
goto error;
} else {
if ( V_43 -> V_47 == V_55 ) {
struct V_86 * V_97 ;
F_61 ( V_2 ) ;
V_97 = F_63 ( V_2 ) ;
if ( V_97 -> V_98 == 4 )
V_2 -> V_57 = F_47 ( V_58 ) ;
else if ( V_97 -> V_98 == 6 )
V_2 -> V_57 = F_47 ( V_59 ) ;
else
goto error;
V_2 -> V_95 = V_96 ;
} else {
if ( memcmp ( V_2 -> V_5 , V_99 , V_51 ) != 0 )
goto error;
F_60 ( V_2 , V_51 ) ;
V_2 -> V_57 = F_62 ( V_2 , V_9 ) ;
}
}
#ifdef F_64
if ( F_55 ( F_46 ( V_2 -> V_57 , V_35 , V_2 ) ) )
goto V_100;
#endif
V_2 -> V_38 = V_9 ;
F_31 ( V_2 ) -> V_41 = V_15 ;
F_15 ( L_10 , F_30 ( V_2 -> V_57 ) ) ;
F_1 ( V_2 ) ;
if ( F_55 ( ! ( V_9 -> V_36 & V_101 ) ) )
goto V_100;
V_9 -> V_64 . V_102 ++ ;
V_9 -> V_64 . V_103 += V_2 -> V_6 ;
memset ( F_31 ( V_2 ) , 0 , sizeof( struct V_104 ) ) ;
F_65 ( V_2 ) ;
return;
V_100:
V_9 -> V_64 . V_105 ++ ;
goto V_106;
error:
V_9 -> V_64 . V_107 ++ ;
V_106:
F_27 ( V_2 ) ;
}
static int F_66 ( struct V_14 * V_15 , void T_2 * V_33 )
{
struct V_13 * V_35 ;
struct V_7 * V_43 ;
struct V_8 * V_9 ;
struct V_108 V_109 ;
int V_75 ;
if ( F_45 ( & V_109 , V_33 , sizeof V_109 ) )
return - V_79 ;
V_35 = F_67 ( sizeof( struct V_13 ) , V_110 ) ;
if ( ! V_35 )
return - V_111 ;
F_49 ( & V_37 ) ;
V_9 = F_12 ( & V_109 . V_80 ) ;
if ( V_9 == NULL ) {
F_68 ( L_11 ) ;
V_75 = - V_112 ;
goto error;
}
V_43 = F_6 ( V_9 ) ;
if ( V_15 -> V_113 == NULL ) {
V_75 = - V_114 ;
goto error;
}
if ( ! F_37 ( & V_43 -> V_17 ) ) {
V_75 = - V_115 ;
goto error;
}
if ( V_109 . V_116 != V_117 ||
V_109 . V_118 != V_119 ||
V_109 . V_120 || V_109 . V_121 || V_109 . V_122 ||
( V_109 . V_45 != V_123 &&
V_109 . V_45 != V_124 ) ||
V_109 . V_125 != 0 ) {
V_75 = - V_126 ;
goto error;
}
F_15 ( L_12 , V_15 , V_109 . V_45 , V_35 ) ;
if ( F_37 ( & V_43 -> V_17 ) && ! V_43 -> V_76 ) {
unsigned char * V_127 = V_15 -> V_38 -> V_127 ;
if ( V_127 [ 0 ] | V_127 [ 1 ] | V_127 [ 2 ] | V_127 [ 3 ] | V_127 [ 4 ] | V_127 [ 5 ] )
memcpy ( V_9 -> V_128 , V_127 , V_9 -> V_129 ) ;
else
V_9 -> V_128 [ 2 ] = 1 ;
}
F_69 ( & V_35 -> V_17 , & V_43 -> V_17 ) ;
F_51 ( & V_37 ) ;
V_35 -> V_68 = V_9 ;
V_35 -> V_15 = V_15 ;
V_15 -> V_16 = V_35 ;
V_35 -> V_45 = (enum V_130 ) V_109 . V_45 ;
V_35 -> V_90 = V_15 -> V_113 ;
V_35 -> V_42 = V_15 -> V_131 ;
F_70 () ;
V_15 -> V_113 = F_54 ;
V_15 -> V_131 = F_21 ;
if ( V_15 -> V_38 -> signal == V_39 )
F_18 ( V_9 ) ;
else
F_19 ( V_9 ) ;
F_71 ( V_91 ) ;
F_72 ( V_15 ) ;
return 0 ;
error:
F_51 ( & V_37 ) ;
F_52 ( V_35 ) ;
return V_75 ;
}
static void F_73 ( struct V_8 * V_132 )
{
struct V_7 * V_43 = F_6 ( V_132 ) ;
F_74 ( V_132 ) ;
V_132 -> V_133 += sizeof( V_49 ) ;
V_43 -> V_9 = V_132 ;
V_132 -> V_134 = & V_135 ;
F_75 ( & V_43 -> V_17 ) ;
}
static void F_76 ( struct V_8 * V_132 )
{
struct V_7 * V_43 = F_6 ( V_132 ) ;
V_43 -> V_9 = V_132 ;
V_132 -> V_133 = sizeof( V_50 ) ;
V_132 -> V_134 = & V_136 ;
V_132 -> V_129 = 0 ;
V_132 -> V_137 = 1500 ;
V_132 -> type = V_138 ;
V_132 -> V_36 = V_139 | V_140 | V_141 ;
V_132 -> V_142 = 100 ;
F_75 ( & V_43 -> V_17 ) ;
}
static int F_77 ( void T_2 * V_33 )
{
int V_75 ;
struct V_8 * V_132 ;
struct V_7 * V_43 ;
struct V_143 V_144 ;
enum V_145 V_47 ;
F_15 ( L_8 ) ;
if ( F_45 ( & V_144 , V_33 , sizeof V_144 ) )
return - V_79 ;
if ( V_144 . V_146 & V_147 )
V_47 = V_55 ;
else
V_47 = V_48 ;
V_144 . V_146 &= 0xffff ;
if ( V_144 . V_146 != V_148 || V_144 . V_137 != 1500 )
return - V_126 ;
V_132 = F_78 ( sizeof( struct V_7 ) ,
V_144 . V_28 [ 0 ] ? V_144 . V_28 : L_13 ,
( V_47 == V_55 ) ?
F_76 : F_73 ) ;
if ( ! V_132 )
return - V_111 ;
V_43 = F_6 ( V_132 ) ;
F_15 ( L_14 , V_132 -> V_27 ) ;
V_75 = F_79 ( V_132 ) ;
if ( V_75 < 0 ) {
F_68 ( L_15 ) ;
F_57 ( V_132 ) ;
return V_75 ;
}
F_49 ( & V_37 ) ;
V_43 -> V_47 = V_47 ;
if ( F_37 ( & V_12 ) ) {
V_43 -> V_23 = 1 ;
} else
V_43 -> V_23 = F_6 ( F_8 ( V_12 . V_82 ) ) -> V_23 + 1 ;
F_80 ( & V_43 -> V_12 , & V_12 ) ;
F_51 ( & V_37 ) ;
return 0 ;
}
static int F_81 ( struct V_149 * V_150 , unsigned int V_151 ,
unsigned long V_33 )
{
struct V_14 * V_15 = F_82 ( V_150 ) ;
void T_2 * V_152 = ( void T_2 * ) V_33 ;
T_4 V_153 ;
int V_75 ;
switch ( V_151 ) {
case V_154 :
case V_155 :
V_75 = F_83 ( V_153 , ( T_4 T_2 * ) V_152 ) ;
if ( V_75 )
return - V_79 ;
if ( V_153 != V_156 )
return - V_157 ;
if ( ! F_84 ( V_158 ) )
return - V_159 ;
if ( V_151 == V_154 )
return F_66 ( V_15 , V_152 ) ;
else
return F_77 ( V_152 ) ;
#ifdef F_64
case V_160 :
if ( V_15 -> V_113 != F_54 )
return - V_157 ;
if ( ! F_84 ( V_158 ) )
return - V_159 ;
V_75 = F_44 ( V_15 , V_152 ) ;
return V_75 ;
#endif
}
return - V_157 ;
}
static void * F_85 ( struct V_161 * V_162 , T_5 * V_163 )
__acquires( V_37 )
{
F_40 ( & V_37 ) ;
return F_86 ( & V_12 , * V_163 ) ;
}
static void * F_87 ( struct V_161 * V_162 , void * V_164 , T_5 * V_163 )
{
return F_88 ( V_164 , & V_12 , V_163 ) ;
}
static void F_89 ( struct V_161 * V_162 , void * V_164 )
__releases( V_37 )
{
F_41 ( & V_37 ) ;
}
static int F_90 ( struct V_161 * V_162 , void * V_164 )
{
const struct V_7 * V_43 = F_9 ( V_164 , struct V_7 ,
V_12 ) ;
const struct V_8 * V_9 = V_43 -> V_9 ;
const struct V_13 * V_35 ;
F_91 ( V_162 , L_16 ,
V_9 -> V_27 ,
V_43 -> V_23 ,
V_9 -> V_128 ,
V_43 -> V_76 ? L_17 : L_18 ) ;
F_17 (brvcc, &brdev->brvccs, brvccs) {
F_91 ( V_162 , L_19
L_20
L_8 , V_35 -> V_15 -> V_38 -> V_23 ,
V_35 -> V_15 -> V_165 , V_35 -> V_15 -> V_166 ,
( V_35 -> V_45 == V_46 ) ? L_21 : L_22 ,
( V_43 -> V_47 == V_48 ) ? L_23 : L_24 ,
V_35 -> V_54 , V_35 -> V_53 ) ;
#ifdef F_64
#define F_92 ( T_6 , T_7 ) ((u8 *) &brvcc->filter.var)[byte]
#define F_93 ( T_6 ) b1(var, 0), b1(var, 1), b1(var, 2), b1(var, 3)
if ( V_35 -> V_84 . V_85 != 0 )
F_91 ( V_162 , L_25
L_26 , F_93 ( V_88 ) , F_93 ( V_85 ) ) ;
#undef F_93
#undef F_92
#endif
}
return 0 ;
}
static int F_94 ( struct V_167 * V_167 , struct V_168 * V_168 )
{
return F_95 ( V_168 , & V_169 ) ;
}
static int T_8 F_96 ( void )
{
#ifdef F_97
struct V_170 * V_74 ;
V_74 = F_98 ( L_27 , 0 , V_171 , & V_172 ) ;
if ( V_74 == NULL )
return - V_111 ;
#endif
F_99 ( & V_173 ) ;
F_100 ( & V_174 ) ;
return 0 ;
}
static void T_9 F_101 ( void )
{
struct V_8 * V_9 ;
struct V_7 * V_43 ;
struct V_13 * V_35 ;
F_102 ( & V_173 ) ;
#ifdef F_97
F_103 ( L_27 , V_171 ) ;
#endif
F_104 ( & V_174 ) ;
while ( ! F_37 ( & V_12 ) ) {
V_9 = F_8 ( V_12 . V_69 ) ;
V_43 = F_6 ( V_9 ) ;
while ( ! F_37 ( & V_43 -> V_17 ) ) {
V_35 = F_11 ( V_43 -> V_17 . V_69 ) ;
F_48 ( V_35 ) ;
}
F_50 ( & V_43 -> V_12 ) ;
F_56 ( V_9 ) ;
F_57 ( V_9 ) ;
}
}
