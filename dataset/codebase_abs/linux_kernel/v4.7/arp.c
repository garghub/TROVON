int F_1 ( T_1 V_1 , T_2 * V_2 , struct V_3 * V_4 , int V_5 )
{
switch ( V_4 -> type ) {
case V_6 :
case V_7 :
case V_8 :
F_2 ( V_1 , V_2 ) ;
return 0 ;
case V_9 :
F_3 ( V_1 , V_4 -> V_10 , V_2 ) ;
return 0 ;
case V_11 :
F_4 ( V_1 , V_4 -> V_10 , V_2 ) ;
return 0 ;
default:
if ( V_5 ) {
memcpy ( V_2 , V_4 -> V_10 , V_4 -> V_12 ) ;
return 0 ;
}
}
return - V_13 ;
}
static T_3 F_5 ( const void * V_14 ,
const struct V_3 * V_4 ,
T_4 * V_15 )
{
return F_6 ( V_14 , V_4 , V_15 ) ;
}
static bool F_7 ( const struct V_16 * V_17 , const void * V_14 )
{
return F_8 ( V_17 , V_14 ) ;
}
static int F_9 ( struct V_16 * V_17 )
{
T_1 V_1 = * ( T_1 * ) V_17 -> V_18 ;
struct V_3 * V_4 = V_17 -> V_4 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
F_10 () ;
V_20 = F_11 ( V_4 ) ;
if ( ! V_20 ) {
F_12 () ;
return - V_13 ;
}
V_17 -> type = F_13 ( F_14 ( V_4 ) , V_4 , V_1 ) ;
V_22 = V_20 -> V_23 ;
F_15 ( V_17 -> V_22 ) ;
V_17 -> V_22 = F_16 ( V_22 ) ;
F_12 () ;
if ( ! V_4 -> V_24 ) {
V_17 -> V_25 = V_26 ;
V_17 -> V_27 = & V_28 ;
V_17 -> V_29 = V_30 ;
} else {
if ( V_17 -> type == V_31 ) {
V_17 -> V_25 = V_26 ;
F_1 ( V_1 , V_17 -> V_32 , V_4 , 1 ) ;
} else if ( V_4 -> V_33 & ( V_34 | V_35 ) ) {
V_17 -> V_25 = V_26 ;
memcpy ( V_17 -> V_32 , V_4 -> V_36 , V_4 -> V_12 ) ;
} else if ( V_17 -> type == V_37 ||
( V_4 -> V_33 & V_38 ) ) {
V_17 -> V_25 = V_26 ;
memcpy ( V_17 -> V_32 , V_4 -> V_10 , V_4 -> V_12 ) ;
}
if ( V_4 -> V_24 -> V_39 )
V_17 -> V_27 = & V_40 ;
else
V_17 -> V_27 = & V_41 ;
if ( V_17 -> V_25 & V_42 )
V_17 -> V_29 = V_17 -> V_27 -> V_43 ;
else
V_17 -> V_29 = V_17 -> V_27 -> V_29 ;
}
return 0 ;
}
static void F_17 ( struct V_16 * V_17 , struct V_44 * V_45 )
{
F_18 ( V_45 ) ;
F_19 ( V_45 ) ;
}
static void F_20 ( int type , int V_46 , T_1 V_47 ,
struct V_3 * V_4 , T_1 V_48 ,
const unsigned char * V_49 ,
const unsigned char * V_50 ,
const unsigned char * V_51 ,
struct V_52 * V_53 )
{
struct V_44 * V_45 ;
if ( V_4 -> V_33 & V_34 )
return;
V_45 = F_21 ( type , V_46 , V_47 , V_4 , V_48 ,
V_49 , V_50 , V_51 ) ;
if ( ! V_45 )
return;
F_22 ( V_45 , F_23 ( V_53 ) ) ;
F_24 ( V_45 ) ;
}
void F_25 ( int type , int V_46 , T_1 V_47 ,
struct V_3 * V_4 , T_1 V_48 ,
const unsigned char * V_49 , const unsigned char * V_50 ,
const unsigned char * V_51 )
{
F_20 ( type , V_46 , V_47 , V_4 , V_48 , V_49 , V_50 ,
V_51 , NULL ) ;
}
static void F_26 ( struct V_16 * V_17 , struct V_44 * V_45 )
{
T_1 V_54 = 0 ;
T_2 V_55 [ V_56 ] , * V_57 = NULL ;
struct V_3 * V_4 = V_17 -> V_4 ;
T_1 V_58 = * ( T_1 * ) V_17 -> V_18 ;
int V_59 = F_27 ( & V_17 -> V_59 ) ;
struct V_19 * V_20 ;
struct V_52 * V_53 = NULL ;
F_10 () ;
V_20 = F_11 ( V_4 ) ;
if ( ! V_20 ) {
F_12 () ;
return;
}
switch ( F_28 ( V_20 ) ) {
default:
case 0 :
if ( V_45 && F_13 ( F_14 ( V_4 ) , V_4 ,
F_29 ( V_45 ) -> V_54 ) == V_60 )
V_54 = F_29 ( V_45 ) -> V_54 ;
break;
case 1 :
if ( ! V_45 )
break;
V_54 = F_29 ( V_45 ) -> V_54 ;
if ( F_13 ( F_14 ( V_4 ) , V_4 ,
V_54 ) == V_60 ) {
if ( F_30 ( V_20 , V_58 , V_54 ) )
break;
}
V_54 = 0 ;
break;
case 2 :
break;
}
F_12 () ;
if ( ! V_54 )
V_54 = F_31 ( V_4 , V_58 , V_61 ) ;
V_59 -= F_32 ( V_17 -> V_22 , V_62 ) ;
if ( V_59 < 0 ) {
if ( ! ( V_17 -> V_25 & V_42 ) )
F_33 ( L_1 ) ;
F_34 ( V_55 , V_17 , V_4 ) ;
V_57 = V_55 ;
} else {
V_59 -= F_32 ( V_17 -> V_22 , V_63 ) ;
if ( V_59 < 0 ) {
F_35 ( V_17 ) ;
return;
}
}
if ( V_45 && ! ( V_4 -> V_64 & V_65 ) )
V_53 = F_36 ( V_45 ) ;
F_20 ( V_66 , V_67 , V_58 , V_4 , V_54 ,
V_57 , V_4 -> V_36 , NULL , V_53 ) ;
}
static int F_37 ( struct V_19 * V_20 , T_1 V_68 , T_1 V_69 )
{
struct V_70 * V_70 = F_14 ( V_20 -> V_4 ) ;
int V_71 ;
switch ( F_38 ( V_20 ) ) {
case 0 :
return 0 ;
case 1 :
V_68 = 0 ;
V_71 = V_72 ;
break;
case 2 :
V_71 = V_72 ;
break;
case 3 :
V_68 = 0 ;
V_71 = V_61 ;
V_20 = NULL ;
break;
case 4 :
case 5 :
case 6 :
case 7 :
return 0 ;
case 8 :
return 1 ;
default:
return 0 ;
}
return ! F_39 ( V_70 , V_20 , V_68 , V_69 , V_71 ) ;
}
static int F_40 ( T_1 V_68 , T_1 V_69 , struct V_3 * V_4 )
{
struct V_73 * V_74 ;
int V_75 = 0 ;
struct V_70 * V_70 = F_14 ( V_4 ) ;
V_74 = F_41 ( V_70 , V_68 , V_69 , 0 , 0 ) ;
if ( F_42 ( V_74 ) )
return 1 ;
if ( V_74 -> V_53 . V_4 != V_4 ) {
F_43 ( V_70 , V_76 ) ;
V_75 = 1 ;
}
F_44 ( V_74 ) ;
return V_75 ;
}
static inline int F_45 ( struct V_19 * V_20 ,
struct V_3 * V_4 , struct V_73 * V_74 )
{
struct V_19 * V_77 ;
int V_78 , V_79 = - 1 ;
if ( V_74 -> V_53 . V_4 == V_4 )
return 0 ;
if ( ! F_46 ( V_20 ) )
return 0 ;
V_78 = F_47 ( V_20 ) ;
if ( V_78 == 0 )
return 1 ;
if ( V_78 == - 1 )
return 0 ;
V_77 = F_11 ( V_74 -> V_53 . V_4 ) ;
if ( V_77 )
V_79 = F_47 ( V_77 ) ;
return V_79 != V_78 && V_79 != - 1 ;
}
static inline int F_48 ( struct V_19 * V_20 ,
struct V_3 * V_4 , struct V_73 * V_74 ,
T_1 V_68 , T_1 V_69 )
{
if ( V_74 -> V_53 . V_4 != V_4 )
return 0 ;
if ( V_68 == V_69 )
return 0 ;
if ( F_49 ( V_20 ) )
return 1 ;
else
return 0 ;
}
struct V_44 * F_21 ( int type , int V_46 , T_1 V_47 ,
struct V_3 * V_4 , T_1 V_48 ,
const unsigned char * V_49 ,
const unsigned char * V_50 ,
const unsigned char * V_51 )
{
struct V_44 * V_45 ;
struct V_80 * V_81 ;
unsigned char * V_82 ;
int V_83 = F_50 ( V_4 ) ;
int V_84 = V_4 -> V_85 ;
V_45 = F_51 ( F_52 ( V_4 ) + V_83 + V_84 , V_86 ) ;
if ( ! V_45 )
return NULL ;
F_53 ( V_45 , V_83 ) ;
F_54 ( V_45 ) ;
V_81 = (struct V_80 * ) F_55 ( V_45 , F_52 ( V_4 ) ) ;
V_45 -> V_4 = V_4 ;
V_45 -> V_87 = F_56 ( V_67 ) ;
if ( ! V_50 )
V_50 = V_4 -> V_36 ;
if ( ! V_49 )
V_49 = V_4 -> V_10 ;
if ( F_57 ( V_45 , V_4 , V_46 , V_49 , V_50 , V_45 -> V_88 ) < 0 )
goto V_89;
switch ( V_4 -> type ) {
default:
V_81 -> V_90 = F_56 ( V_4 -> type ) ;
V_81 -> V_91 = F_56 ( V_92 ) ;
break;
#if F_58 ( V_93 )
case V_94 :
V_81 -> V_90 = F_56 ( V_94 ) ;
V_81 -> V_91 = F_56 ( V_95 ) ;
break;
#if F_58 ( V_96 )
case V_97 :
V_81 -> V_90 = F_56 ( V_97 ) ;
V_81 -> V_91 = F_56 ( V_95 ) ;
break;
#endif
#endif
#if F_58 ( V_98 )
case V_7 :
V_81 -> V_90 = F_56 ( V_6 ) ;
V_81 -> V_91 = F_56 ( V_92 ) ;
break;
#endif
}
V_81 -> V_99 = V_4 -> V_12 ;
V_81 -> V_100 = 4 ;
V_81 -> V_101 = F_56 ( type ) ;
V_82 = ( unsigned char * ) ( V_81 + 1 ) ;
memcpy ( V_82 , V_50 , V_4 -> V_12 ) ;
V_82 += V_4 -> V_12 ;
memcpy ( V_82 , & V_48 , 4 ) ;
V_82 += 4 ;
switch ( V_4 -> type ) {
#if F_58 ( V_102 )
case V_103 :
break;
#endif
default:
if ( V_51 )
memcpy ( V_82 , V_51 , V_4 -> V_12 ) ;
else
memset ( V_82 , 0 , V_4 -> V_12 ) ;
V_82 += V_4 -> V_12 ;
}
memcpy ( V_82 , & V_47 , 4 ) ;
return V_45 ;
V_89:
F_19 ( V_45 ) ;
return NULL ;
}
static int F_59 ( struct V_70 * V_70 , struct V_104 * V_105 , struct V_44 * V_45 )
{
return F_60 ( V_45 ) ;
}
void F_24 ( struct V_44 * V_45 )
{
F_61 ( V_106 , V_107 ,
F_14 ( V_45 -> V_4 ) , NULL , V_45 , NULL , V_45 -> V_4 ,
F_59 ) ;
}
static int F_62 ( struct V_70 * V_70 , struct V_104 * V_105 , struct V_44 * V_45 )
{
struct V_3 * V_4 = V_45 -> V_4 ;
struct V_19 * V_20 = F_11 ( V_4 ) ;
struct V_80 * V_81 ;
unsigned char * V_82 ;
struct V_73 * V_74 ;
unsigned char * V_108 ;
T_1 V_68 , V_69 ;
T_5 V_109 = V_4 -> type ;
int V_110 ;
struct V_16 * V_111 ;
struct V_52 * V_112 = NULL ;
bool V_113 = false ;
if ( ! V_20 )
goto V_114;
V_81 = F_63 ( V_45 ) ;
switch ( V_109 ) {
default:
if ( V_81 -> V_91 != F_56 ( V_92 ) ||
F_56 ( V_109 ) != V_81 -> V_90 )
goto V_114;
break;
case V_6 :
case V_7 :
case V_8 :
if ( ( V_81 -> V_90 != F_56 ( V_6 ) &&
V_81 -> V_90 != F_56 ( V_8 ) ) ||
V_81 -> V_91 != F_56 ( V_92 ) )
goto V_114;
break;
case V_94 :
if ( V_81 -> V_91 != F_56 ( V_95 ) ||
V_81 -> V_90 != F_56 ( V_94 ) )
goto V_114;
break;
case V_97 :
if ( V_81 -> V_91 != F_56 ( V_95 ) ||
V_81 -> V_90 != F_56 ( V_97 ) )
goto V_114;
break;
}
if ( V_81 -> V_101 != F_56 ( V_115 ) &&
V_81 -> V_101 != F_56 ( V_66 ) )
goto V_114;
V_82 = ( unsigned char * ) ( V_81 + 1 ) ;
V_108 = V_82 ;
V_82 += V_4 -> V_12 ;
memcpy ( & V_68 , V_82 , 4 ) ;
V_82 += 4 ;
switch ( V_109 ) {
#if F_58 ( V_102 )
case V_103 :
break;
#endif
default:
V_82 += V_4 -> V_12 ;
}
memcpy ( & V_69 , V_82 , 4 ) ;
if ( F_64 ( V_69 ) ||
( ! F_65 ( V_20 ) && F_66 ( V_69 ) ) )
goto V_114;
if ( V_68 == V_69 && F_67 ( V_20 , V_116 ) )
goto V_114;
if ( V_109 == V_117 )
V_108 = V_4 -> V_10 ;
if ( V_81 -> V_101 == F_56 ( V_66 ) && F_68 ( V_45 ) )
V_112 = (struct V_52 * )
F_69 ( F_68 ( V_45 ) ,
V_86 ) ;
if ( V_68 == 0 ) {
if ( V_81 -> V_101 == F_56 ( V_66 ) &&
F_13 ( V_70 , V_4 , V_69 ) == V_60 &&
! F_37 ( V_20 , V_68 , V_69 ) )
F_20 ( V_115 , V_67 , V_68 , V_4 , V_69 ,
V_108 , V_4 -> V_36 , V_108 , V_112 ) ;
goto V_118;
}
if ( V_81 -> V_101 == F_56 ( V_66 ) &&
F_70 ( V_45 , V_69 , V_68 , 0 , V_4 ) == 0 ) {
V_74 = F_71 ( V_45 ) ;
V_110 = V_74 -> V_119 ;
if ( V_110 == V_60 ) {
int V_120 ;
V_120 = F_37 ( V_20 , V_68 , V_69 ) ;
if ( ! V_120 && F_72 ( V_20 ) )
V_120 = F_40 ( V_68 , V_69 , V_4 ) ;
if ( ! V_120 ) {
V_111 = F_73 ( & V_121 , V_108 , & V_68 , V_4 ) ;
if ( V_111 ) {
F_20 ( V_115 , V_67 ,
V_68 , V_4 , V_69 , V_108 ,
V_4 -> V_36 , V_108 ,
V_112 ) ;
F_74 ( V_111 ) ;
}
}
goto V_118;
} else if ( F_75 ( V_20 ) ) {
if ( V_110 == V_122 &&
( F_45 ( V_20 , V_4 , V_74 ) ||
F_48 ( V_20 , V_4 , V_74 , V_68 , V_69 ) ||
( V_74 -> V_53 . V_4 != V_4 &&
F_76 ( & V_121 , V_70 , & V_69 , V_4 , 0 ) ) ) ) {
V_111 = F_73 ( & V_121 , V_108 , & V_68 , V_4 ) ;
if ( V_111 )
F_74 ( V_111 ) ;
if ( F_77 ( V_45 ) -> V_33 & V_123 ||
V_45 -> V_124 == V_125 ||
F_32 ( V_20 -> V_23 , V_126 ) == 0 ) {
F_20 ( V_115 , V_67 ,
V_68 , V_4 , V_69 , V_108 ,
V_4 -> V_36 , V_108 ,
V_112 ) ;
} else {
F_78 ( & V_121 ,
V_20 -> V_23 , V_45 ) ;
goto V_127;
}
goto V_118;
}
}
}
V_111 = F_79 ( & V_121 , & V_68 , V_4 , 0 ) ;
if ( F_80 ( V_20 ) ) {
unsigned int V_110 = F_13 ( V_70 , V_4 , V_68 ) ;
V_113 = V_81 -> V_101 == F_56 ( V_66 ) && V_69 == V_68 &&
V_110 == V_122 ;
if ( ! V_111 &&
( ( V_81 -> V_101 == F_56 ( V_115 ) &&
V_110 == V_122 ) || V_113 ) )
V_111 = F_79 ( & V_121 , & V_68 , V_4 , 1 ) ;
}
if ( V_111 ) {
int V_128 = V_129 ;
int V_130 ;
V_130 = F_81 ( V_131 ,
V_111 -> V_132 +
F_32 ( V_111 -> V_22 , V_133 ) ) ||
V_113 ;
if ( V_81 -> V_101 != F_56 ( V_115 ) ||
V_45 -> V_124 != V_125 )
V_128 = V_134 ;
F_82 ( V_111 , V_108 , V_128 ,
V_130 ? V_135 : 0 ) ;
F_74 ( V_111 ) ;
}
V_118:
F_83 ( V_45 ) ;
V_127:
F_84 ( V_112 ) ;
return V_136 ;
V_114:
F_19 ( V_45 ) ;
return V_137 ;
}
static void F_85 ( struct V_44 * V_45 )
{
F_62 ( F_14 ( V_45 -> V_4 ) , NULL , V_45 ) ;
}
static int F_86 ( struct V_44 * V_45 , struct V_3 * V_4 ,
struct V_138 * V_139 , struct V_3 * V_140 )
{
const struct V_80 * V_81 ;
if ( V_4 -> V_33 & V_34 ||
V_45 -> V_124 == V_141 ||
V_45 -> V_124 == V_142 )
goto V_143;
V_45 = F_87 ( V_45 , V_86 ) ;
if ( ! V_45 )
goto V_144;
if ( ! F_88 ( V_45 , F_52 ( V_4 ) ) )
goto V_145;
V_81 = F_63 ( V_45 ) ;
if ( V_81 -> V_99 != V_4 -> V_12 || V_81 -> V_100 != 4 )
goto V_145;
memset ( F_77 ( V_45 ) , 0 , sizeof( struct V_146 ) ) ;
return F_61 ( V_106 , V_147 ,
F_14 ( V_4 ) , NULL , V_45 , V_4 , NULL ,
F_62 ) ;
V_143:
F_83 ( V_45 ) ;
return V_136 ;
V_145:
F_19 ( V_45 ) ;
V_144:
return V_137 ;
}
static int F_89 ( struct V_70 * V_70 , struct V_3 * V_4 , int V_148 )
{
if ( ! V_4 ) {
F_90 ( V_70 , V_149 ) = V_148 ;
return 0 ;
}
if ( F_91 ( V_4 ) ) {
F_92 ( F_91 ( V_4 ) , V_149 , V_148 ) ;
return 0 ;
}
return - V_150 ;
}
static int F_93 ( struct V_70 * V_70 , struct V_151 * V_152 ,
struct V_3 * V_4 )
{
T_1 V_153 = ( (struct V_154 * ) & V_152 -> V_155 ) -> V_156 . V_157 ;
T_1 V_158 = ( (struct V_154 * ) & V_152 -> V_159 ) -> V_156 . V_157 ;
if ( V_158 && V_158 != F_94 ( 0xFFFFFFFF ) )
return - V_13 ;
if ( ! V_4 && ( V_152 -> V_160 & V_161 ) ) {
V_4 = F_95 ( V_70 , V_152 -> V_162 . V_163 ,
V_152 -> V_162 . V_164 ) ;
if ( ! V_4 )
return - V_165 ;
}
if ( V_158 ) {
if ( ! F_76 ( & V_121 , V_70 , & V_153 , V_4 , 1 ) )
return - V_166 ;
return 0 ;
}
return F_89 ( V_70 , V_4 , 1 ) ;
}
static int F_96 ( struct V_70 * V_70 , struct V_151 * V_152 ,
struct V_3 * V_4 )
{
T_1 V_153 ;
struct V_16 * V_17 ;
int V_167 ;
if ( V_152 -> V_160 & V_168 )
return F_93 ( V_70 , V_152 , V_4 ) ;
V_153 = ( (struct V_154 * ) & V_152 -> V_155 ) -> V_156 . V_157 ;
if ( V_152 -> V_160 & V_169 )
V_152 -> V_160 |= V_161 ;
if ( ! V_4 ) {
struct V_73 * V_74 = F_41 ( V_70 , V_153 , 0 , V_170 , 0 ) ;
if ( F_42 ( V_74 ) )
return F_97 ( V_74 ) ;
V_4 = V_74 -> V_53 . V_4 ;
F_44 ( V_74 ) ;
if ( ! V_4 )
return - V_13 ;
}
switch ( V_4 -> type ) {
#if F_58 ( V_98 )
case V_7 :
if ( V_152 -> V_162 . V_163 != V_7 &&
V_152 -> V_162 . V_163 != V_6 &&
V_152 -> V_162 . V_163 != V_8 )
return - V_13 ;
break;
#endif
default:
if ( V_152 -> V_162 . V_163 != V_4 -> type )
return - V_13 ;
break;
}
V_17 = F_98 ( & V_121 , & V_153 , V_4 ) ;
V_167 = F_97 ( V_17 ) ;
if ( ! F_42 ( V_17 ) ) {
unsigned int V_128 = V_134 ;
if ( V_152 -> V_160 & V_169 )
V_128 = V_171 ;
V_167 = F_82 ( V_17 , ( V_152 -> V_160 & V_161 ) ?
V_152 -> V_162 . V_164 : NULL , V_128 ,
V_135 |
V_172 ) ;
F_74 ( V_17 ) ;
}
return V_167 ;
}
static unsigned int F_99 ( struct V_16 * V_17 )
{
if ( V_17 -> V_25 & V_171 )
return V_169 | V_161 ;
else if ( V_17 -> V_25 & V_42 )
return V_161 ;
else
return 0 ;
}
static int F_100 ( struct V_151 * V_152 , struct V_3 * V_4 )
{
T_1 V_153 = ( (struct V_154 * ) & V_152 -> V_155 ) -> V_156 . V_157 ;
struct V_16 * V_17 ;
int V_167 = - V_150 ;
V_17 = F_101 ( & V_121 , & V_153 , V_4 ) ;
if ( V_17 ) {
if ( ! ( V_17 -> V_25 & V_26 ) ) {
F_102 ( & V_17 -> V_173 ) ;
memcpy ( V_152 -> V_162 . V_164 , V_17 -> V_32 , V_4 -> V_12 ) ;
V_152 -> V_160 = F_99 ( V_17 ) ;
F_103 ( & V_17 -> V_173 ) ;
V_152 -> V_162 . V_163 = V_4 -> type ;
F_104 ( V_152 -> V_174 , V_4 -> V_175 , sizeof( V_152 -> V_174 ) ) ;
V_167 = 0 ;
}
F_74 ( V_17 ) ;
}
return V_167 ;
}
static int F_105 ( struct V_3 * V_4 , T_1 V_153 )
{
struct V_16 * V_17 = F_101 ( & V_121 , & V_153 , V_4 ) ;
int V_167 = - V_150 ;
if ( V_17 ) {
if ( V_17 -> V_25 & ~ V_26 )
V_167 = F_82 ( V_17 , NULL , V_176 ,
V_135 |
V_172 ) ;
F_74 ( V_17 ) ;
}
return V_167 ;
}
static int F_106 ( struct V_70 * V_70 , struct V_151 * V_152 ,
struct V_3 * V_4 )
{
T_1 V_153 = ( (struct V_154 * ) & V_152 -> V_155 ) -> V_156 . V_157 ;
T_1 V_158 = ( (struct V_154 * ) & V_152 -> V_159 ) -> V_156 . V_157 ;
if ( V_158 == F_94 ( 0xFFFFFFFF ) )
return F_107 ( & V_121 , V_70 , & V_153 , V_4 ) ;
if ( V_158 )
return - V_13 ;
return F_89 ( V_70 , V_4 , 0 ) ;
}
static int F_108 ( struct V_70 * V_70 , struct V_151 * V_152 ,
struct V_3 * V_4 )
{
T_1 V_153 ;
if ( V_152 -> V_160 & V_168 )
return F_106 ( V_70 , V_152 , V_4 ) ;
V_153 = ( (struct V_154 * ) & V_152 -> V_155 ) -> V_156 . V_157 ;
if ( ! V_4 ) {
struct V_73 * V_74 = F_41 ( V_70 , V_153 , 0 , V_170 , 0 ) ;
if ( F_42 ( V_74 ) )
return F_97 ( V_74 ) ;
V_4 = V_74 -> V_53 . V_4 ;
F_44 ( V_74 ) ;
if ( ! V_4 )
return - V_13 ;
}
return F_105 ( V_4 , V_153 ) ;
}
int F_109 ( struct V_70 * V_70 , unsigned int V_177 , void T_6 * V_178 )
{
int V_167 ;
struct V_151 V_152 ;
struct V_3 * V_4 = NULL ;
switch ( V_177 ) {
case V_179 :
case V_180 :
if ( ! F_110 ( V_70 -> V_181 , V_182 ) )
return - V_183 ;
case V_184 :
V_167 = F_111 ( & V_152 , V_178 , sizeof( struct V_151 ) ) ;
if ( V_167 )
return - V_185 ;
break;
default:
return - V_13 ;
}
if ( V_152 . V_155 . V_163 != V_186 )
return - V_187 ;
if ( ! ( V_152 . V_160 & V_168 ) &&
( V_152 . V_160 & ( V_188 | V_189 ) ) )
return - V_13 ;
if ( ! ( V_152 . V_160 & V_188 ) )
( (struct V_154 * ) & V_152 . V_159 ) -> V_156 . V_157 =
F_94 ( 0xFFFFFFFFUL ) ;
F_112 () ;
if ( V_152 . V_174 [ 0 ] ) {
V_167 = - V_165 ;
V_4 = F_113 ( V_70 , V_152 . V_174 ) ;
if ( ! V_4 )
goto V_89;
if ( ! V_152 . V_162 . V_163 )
V_152 . V_162 . V_163 = V_4 -> type ;
V_167 = - V_13 ;
if ( ( V_152 . V_160 & V_161 ) && V_152 . V_162 . V_163 != V_4 -> type )
goto V_89;
} else if ( V_177 == V_184 ) {
V_167 = - V_165 ;
goto V_89;
}
switch ( V_177 ) {
case V_179 :
V_167 = F_108 ( V_70 , & V_152 , V_4 ) ;
break;
case V_180 :
V_167 = F_96 ( V_70 , & V_152 , V_4 ) ;
break;
case V_184 :
V_167 = F_100 ( & V_152 , V_4 ) ;
break;
}
V_89:
F_114 () ;
if ( V_177 == V_184 && ! V_167 && F_115 ( V_178 , & V_152 , sizeof( V_152 ) ) )
V_167 = - V_185 ;
return V_167 ;
}
static int F_116 ( struct V_190 * V_191 , unsigned long V_192 ,
void * V_193 )
{
struct V_3 * V_4 = F_117 ( V_193 ) ;
struct V_194 * V_195 ;
switch ( V_192 ) {
case V_196 :
F_118 ( & V_121 , V_4 ) ;
F_119 ( F_14 ( V_4 ) ) ;
break;
case V_197 :
V_195 = V_193 ;
if ( V_195 -> V_198 & V_34 )
F_118 ( & V_121 , V_4 ) ;
break;
default:
break;
}
return V_199 ;
}
void F_120 ( struct V_3 * V_4 )
{
F_121 ( & V_121 , V_4 ) ;
}
void T_7 F_122 ( void )
{
F_123 ( V_200 , & V_121 ) ;
F_124 ( & V_201 ) ;
F_125 () ;
#ifdef F_126
F_127 ( NULL , & V_121 . V_22 , NULL ) ;
#endif
F_128 ( & V_202 ) ;
}
static char * F_129 ( T_8 * V_203 , char * V_204 )
{
char V_205 , * V_206 ;
int V_111 ;
for ( V_111 = 0 , V_206 = V_204 ; V_111 < 6 ; V_111 ++ ) {
V_205 = ( V_203 -> V_207 [ V_111 ] >> 1 ) & 0x7F ;
if ( V_205 != ' ' )
* V_206 ++ = V_205 ;
}
* V_206 ++ = '-' ;
V_111 = ( V_203 -> V_207 [ 6 ] >> 1 ) & 0x0F ;
if ( V_111 > 9 ) {
* V_206 ++ = '1' ;
V_111 -= 10 ;
}
* V_206 ++ = V_111 + '0' ;
* V_206 ++ = '\0' ;
if ( * V_204 == '\0' || * V_204 == '-' )
return L_2 ;
return V_204 ;
}
static void F_130 ( struct V_208 * V_209 ,
struct V_16 * V_111 )
{
char V_210 [ V_211 ] ;
int V_212 , V_213 ;
char V_214 [ 16 ] ;
struct V_3 * V_4 = V_111 -> V_4 ;
int V_215 = V_4 -> type ;
F_131 ( & V_111 -> V_173 ) ;
#if F_58 ( V_93 )
if ( V_215 == V_94 || V_215 == V_97 )
F_129 ( ( T_8 * ) V_111 -> V_32 , V_210 ) ;
else {
#endif
for ( V_212 = 0 , V_213 = 0 ; V_212 < V_211 - 3 && V_213 < V_4 -> V_12 ; V_213 ++ ) {
V_210 [ V_212 ++ ] = F_132 ( V_111 -> V_32 [ V_213 ] ) ;
V_210 [ V_212 ++ ] = F_133 ( V_111 -> V_32 [ V_213 ] ) ;
V_210 [ V_212 ++ ] = ':' ;
}
if ( V_212 != 0 )
-- V_212 ;
V_210 [ V_212 ] = 0 ;
#if F_58 ( V_93 )
}
#endif
sprintf ( V_214 , L_3 , V_111 -> V_18 ) ;
F_134 ( V_209 , L_4 ,
V_214 , V_215 , F_99 ( V_111 ) , V_210 , V_4 -> V_175 ) ;
F_135 ( & V_111 -> V_173 ) ;
}
static void F_136 ( struct V_208 * V_209 ,
struct V_216 * V_111 )
{
struct V_3 * V_4 = V_111 -> V_4 ;
int V_215 = V_4 ? V_4 -> type : 0 ;
char V_214 [ 16 ] ;
sprintf ( V_214 , L_3 , V_111 -> V_217 ) ;
F_134 ( V_209 , L_4 ,
V_214 , V_215 , V_168 | V_169 , L_5 ,
V_4 ? V_4 -> V_175 : L_2 ) ;
}
static int F_137 ( struct V_208 * V_209 , void * V_218 )
{
if ( V_218 == V_219 ) {
F_138 ( V_209 , L_6
L_7 ) ;
} else {
struct V_220 * V_128 = V_209 -> V_221 ;
if ( V_128 -> V_33 & V_222 )
F_136 ( V_209 , V_218 ) ;
else
F_130 ( V_209 , V_218 ) ;
}
return 0 ;
}
static void * F_139 ( struct V_208 * V_209 , T_9 * V_223 )
{
return F_140 ( V_209 , V_223 , & V_121 , V_224 ) ;
}
static int F_141 ( struct V_225 * V_225 , struct V_226 * V_226 )
{
return F_142 ( V_225 , V_226 , & V_227 ,
sizeof( struct V_220 ) ) ;
}
static int T_10 F_143 ( struct V_70 * V_70 )
{
if ( ! F_144 ( L_8 , V_228 , V_70 -> V_229 , & V_230 ) )
return - V_231 ;
return 0 ;
}
static void T_11 F_145 ( struct V_70 * V_70 )
{
F_146 ( L_8 , V_70 -> V_229 ) ;
}
static int T_7 F_125 ( void )
{
return F_147 ( & V_232 ) ;
}
static int T_7 F_125 ( void )
{
return 0 ;
}
