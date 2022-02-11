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
static bool F_62 ( struct V_70 * V_70 , struct V_3 * V_4 ,
int * V_108 , T_5 V_101 ,
T_1 V_68 , T_1 V_69 ,
unsigned char * V_109 , unsigned char * V_110 )
{
bool V_111 = V_69 == V_68 ;
if ( V_111 && V_101 == F_56 ( V_112 ) )
V_111 =
V_110 &&
! memcmp ( V_110 , V_109 , V_4 -> V_12 ) ;
if ( V_111 ) {
* V_108 = F_13 ( V_70 , V_4 , V_68 ) ;
if ( * V_108 != V_113 )
V_111 = false ;
}
return V_111 ;
}
static int F_63 ( struct V_70 * V_70 , struct V_104 * V_105 , struct V_44 * V_45 )
{
struct V_3 * V_4 = V_45 -> V_4 ;
struct V_19 * V_20 = F_11 ( V_4 ) ;
struct V_80 * V_81 ;
unsigned char * V_82 ;
struct V_73 * V_74 ;
unsigned char * V_109 ;
unsigned char * V_110 = NULL ;
T_1 V_68 , V_69 ;
T_6 V_114 = V_4 -> type ;
int V_108 ;
struct V_16 * V_115 ;
struct V_52 * V_116 = NULL ;
bool V_111 = false ;
if ( ! V_20 )
goto V_117;
V_81 = F_64 ( V_45 ) ;
switch ( V_114 ) {
default:
if ( V_81 -> V_91 != F_56 ( V_92 ) ||
F_56 ( V_114 ) != V_81 -> V_90 )
goto V_117;
break;
case V_6 :
case V_7 :
case V_8 :
if ( ( V_81 -> V_90 != F_56 ( V_6 ) &&
V_81 -> V_90 != F_56 ( V_8 ) ) ||
V_81 -> V_91 != F_56 ( V_92 ) )
goto V_117;
break;
case V_94 :
if ( V_81 -> V_91 != F_56 ( V_95 ) ||
V_81 -> V_90 != F_56 ( V_94 ) )
goto V_117;
break;
case V_97 :
if ( V_81 -> V_91 != F_56 ( V_95 ) ||
V_81 -> V_90 != F_56 ( V_97 ) )
goto V_117;
break;
}
if ( V_81 -> V_101 != F_56 ( V_112 ) &&
V_81 -> V_101 != F_56 ( V_66 ) )
goto V_117;
V_82 = ( unsigned char * ) ( V_81 + 1 ) ;
V_109 = V_82 ;
V_82 += V_4 -> V_12 ;
memcpy ( & V_68 , V_82 , 4 ) ;
V_82 += 4 ;
switch ( V_114 ) {
#if F_58 ( V_102 )
case V_103 :
break;
#endif
default:
V_110 = V_82 ;
V_82 += V_4 -> V_12 ;
}
memcpy ( & V_69 , V_82 , 4 ) ;
if ( F_65 ( V_69 ) ||
( ! F_66 ( V_20 ) && F_67 ( V_69 ) ) )
goto V_117;
if ( V_68 == V_69 && F_68 ( V_20 , V_118 ) )
goto V_117;
if ( V_114 == V_119 )
V_109 = V_4 -> V_10 ;
if ( V_81 -> V_101 == F_56 ( V_66 ) && F_69 ( V_45 ) )
V_116 = (struct V_52 * )
F_70 ( F_69 ( V_45 ) ,
V_86 ) ;
if ( V_68 == 0 ) {
if ( V_81 -> V_101 == F_56 ( V_66 ) &&
F_13 ( V_70 , V_4 , V_69 ) == V_60 &&
! F_37 ( V_20 , V_68 , V_69 ) )
F_20 ( V_112 , V_67 , V_68 , V_4 , V_69 ,
V_109 , V_4 -> V_36 , V_109 , V_116 ) ;
goto V_120;
}
if ( V_81 -> V_101 == F_56 ( V_66 ) &&
F_71 ( V_45 , V_69 , V_68 , 0 , V_4 ) == 0 ) {
V_74 = F_72 ( V_45 ) ;
V_108 = V_74 -> V_121 ;
if ( V_108 == V_60 ) {
int V_122 ;
V_122 = F_37 ( V_20 , V_68 , V_69 ) ;
if ( ! V_122 && F_73 ( V_20 ) )
V_122 = F_40 ( V_68 , V_69 , V_4 ) ;
if ( ! V_122 ) {
V_115 = F_74 ( & V_123 , V_109 , & V_68 , V_4 ) ;
if ( V_115 ) {
F_20 ( V_112 , V_67 ,
V_68 , V_4 , V_69 , V_109 ,
V_4 -> V_36 , V_109 ,
V_116 ) ;
F_75 ( V_115 ) ;
}
}
goto V_120;
} else if ( F_76 ( V_20 ) ) {
if ( V_108 == V_113 &&
( F_45 ( V_20 , V_4 , V_74 ) ||
F_48 ( V_20 , V_4 , V_74 , V_68 , V_69 ) ||
( V_74 -> V_53 . V_4 != V_4 &&
F_77 ( & V_123 , V_70 , & V_69 , V_4 , 0 ) ) ) ) {
V_115 = F_74 ( & V_123 , V_109 , & V_68 , V_4 ) ;
if ( V_115 )
F_75 ( V_115 ) ;
if ( F_78 ( V_45 ) -> V_33 & V_124 ||
V_45 -> V_125 == V_126 ||
F_32 ( V_20 -> V_23 , V_127 ) == 0 ) {
F_20 ( V_112 , V_67 ,
V_68 , V_4 , V_69 , V_109 ,
V_4 -> V_36 , V_109 ,
V_116 ) ;
} else {
F_79 ( & V_123 ,
V_20 -> V_23 , V_45 ) ;
goto V_128;
}
goto V_120;
}
}
}
V_115 = F_80 ( & V_123 , & V_68 , V_4 , 0 ) ;
V_108 = - 1 ;
if ( V_115 || F_81 ( V_20 ) ) {
V_111 = F_62 ( V_70 , V_4 , & V_108 , V_81 -> V_101 ,
V_68 , V_69 , V_109 , V_110 ) ;
}
if ( F_81 ( V_20 ) ) {
if ( ! V_115 &&
( V_111 ||
( V_81 -> V_101 == F_56 ( V_112 ) &&
( V_108 == V_113 ||
( V_108 < 0 &&
F_13 ( V_70 , V_4 , V_68 ) ==
V_113 ) ) ) ) )
V_115 = F_80 ( & V_123 , & V_68 , V_4 , 1 ) ;
}
if ( V_115 ) {
int V_129 = V_130 ;
int V_131 ;
V_131 = F_82 ( V_132 ,
V_115 -> V_133 +
F_32 ( V_115 -> V_22 , V_134 ) ) ||
V_111 ;
if ( V_81 -> V_101 != F_56 ( V_112 ) ||
V_45 -> V_125 != V_126 )
V_129 = V_135 ;
F_83 ( V_115 , V_109 , V_129 ,
V_131 ? V_136 : 0 , 0 ) ;
F_75 ( V_115 ) ;
}
V_120:
F_84 ( V_45 ) ;
V_128:
F_85 ( V_116 ) ;
return V_137 ;
V_117:
F_19 ( V_45 ) ;
return V_138 ;
}
static void F_86 ( struct V_44 * V_45 )
{
F_63 ( F_14 ( V_45 -> V_4 ) , NULL , V_45 ) ;
}
static int F_87 ( struct V_44 * V_45 , struct V_3 * V_4 ,
struct V_139 * V_140 , struct V_3 * V_141 )
{
const struct V_80 * V_81 ;
if ( V_4 -> V_33 & V_34 ||
V_45 -> V_125 == V_142 ||
V_45 -> V_125 == V_143 )
goto V_144;
V_45 = F_88 ( V_45 , V_86 ) ;
if ( ! V_45 )
goto V_145;
if ( ! F_89 ( V_45 , F_52 ( V_4 ) ) )
goto V_146;
V_81 = F_64 ( V_45 ) ;
if ( V_81 -> V_99 != V_4 -> V_12 || V_81 -> V_100 != 4 )
goto V_146;
memset ( F_78 ( V_45 ) , 0 , sizeof( struct V_147 ) ) ;
return F_61 ( V_106 , V_148 ,
F_14 ( V_4 ) , NULL , V_45 , V_4 , NULL ,
F_63 ) ;
V_144:
F_84 ( V_45 ) ;
return V_137 ;
V_146:
F_19 ( V_45 ) ;
V_145:
return V_138 ;
}
static int F_90 ( struct V_70 * V_70 , struct V_3 * V_4 , int V_149 )
{
if ( ! V_4 ) {
F_91 ( V_70 , V_150 ) = V_149 ;
return 0 ;
}
if ( F_92 ( V_4 ) ) {
F_93 ( F_92 ( V_4 ) , V_150 , V_149 ) ;
return 0 ;
}
return - V_151 ;
}
static int F_94 ( struct V_70 * V_70 , struct V_152 * V_153 ,
struct V_3 * V_4 )
{
T_1 V_154 = ( (struct V_155 * ) & V_153 -> V_156 ) -> V_157 . V_158 ;
T_1 V_159 = ( (struct V_155 * ) & V_153 -> V_160 ) -> V_157 . V_158 ;
if ( V_159 && V_159 != F_95 ( 0xFFFFFFFF ) )
return - V_13 ;
if ( ! V_4 && ( V_153 -> V_161 & V_162 ) ) {
V_4 = F_96 ( V_70 , V_153 -> V_163 . V_164 ,
V_153 -> V_163 . V_165 ) ;
if ( ! V_4 )
return - V_166 ;
}
if ( V_159 ) {
if ( ! F_77 ( & V_123 , V_70 , & V_154 , V_4 , 1 ) )
return - V_167 ;
return 0 ;
}
return F_90 ( V_70 , V_4 , 1 ) ;
}
static int F_97 ( struct V_70 * V_70 , struct V_152 * V_153 ,
struct V_3 * V_4 )
{
T_1 V_154 ;
struct V_16 * V_17 ;
int V_168 ;
if ( V_153 -> V_161 & V_169 )
return F_94 ( V_70 , V_153 , V_4 ) ;
V_154 = ( (struct V_155 * ) & V_153 -> V_156 ) -> V_157 . V_158 ;
if ( V_153 -> V_161 & V_170 )
V_153 -> V_161 |= V_162 ;
if ( ! V_4 ) {
struct V_73 * V_74 = F_41 ( V_70 , V_154 , 0 , V_171 , 0 ) ;
if ( F_42 ( V_74 ) )
return F_98 ( V_74 ) ;
V_4 = V_74 -> V_53 . V_4 ;
F_44 ( V_74 ) ;
if ( ! V_4 )
return - V_13 ;
}
switch ( V_4 -> type ) {
#if F_58 ( V_98 )
case V_7 :
if ( V_153 -> V_163 . V_164 != V_7 &&
V_153 -> V_163 . V_164 != V_6 &&
V_153 -> V_163 . V_164 != V_8 )
return - V_13 ;
break;
#endif
default:
if ( V_153 -> V_163 . V_164 != V_4 -> type )
return - V_13 ;
break;
}
V_17 = F_99 ( & V_123 , & V_154 , V_4 ) ;
V_168 = F_98 ( V_17 ) ;
if ( ! F_42 ( V_17 ) ) {
unsigned int V_129 = V_135 ;
if ( V_153 -> V_161 & V_170 )
V_129 = V_172 ;
V_168 = F_83 ( V_17 , ( V_153 -> V_161 & V_162 ) ?
V_153 -> V_163 . V_165 : NULL , V_129 ,
V_136 |
V_173 , 0 ) ;
F_75 ( V_17 ) ;
}
return V_168 ;
}
static unsigned int F_100 ( struct V_16 * V_17 )
{
if ( V_17 -> V_25 & V_172 )
return V_170 | V_162 ;
else if ( V_17 -> V_25 & V_42 )
return V_162 ;
else
return 0 ;
}
static int F_101 ( struct V_152 * V_153 , struct V_3 * V_4 )
{
T_1 V_154 = ( (struct V_155 * ) & V_153 -> V_156 ) -> V_157 . V_158 ;
struct V_16 * V_17 ;
int V_168 = - V_151 ;
V_17 = F_102 ( & V_123 , & V_154 , V_4 ) ;
if ( V_17 ) {
if ( ! ( V_17 -> V_25 & V_26 ) ) {
F_103 ( & V_17 -> V_174 ) ;
memcpy ( V_153 -> V_163 . V_165 , V_17 -> V_32 , V_4 -> V_12 ) ;
V_153 -> V_161 = F_100 ( V_17 ) ;
F_104 ( & V_17 -> V_174 ) ;
V_153 -> V_163 . V_164 = V_4 -> type ;
F_105 ( V_153 -> V_175 , V_4 -> V_176 , sizeof( V_153 -> V_175 ) ) ;
V_168 = 0 ;
}
F_75 ( V_17 ) ;
}
return V_168 ;
}
static int F_106 ( struct V_3 * V_4 , T_1 V_154 )
{
struct V_16 * V_17 = F_102 ( & V_123 , & V_154 , V_4 ) ;
int V_168 = - V_151 ;
if ( V_17 ) {
if ( V_17 -> V_25 & ~ V_26 )
V_168 = F_83 ( V_17 , NULL , V_177 ,
V_136 |
V_173 , 0 ) ;
F_75 ( V_17 ) ;
}
return V_168 ;
}
static int F_107 ( struct V_70 * V_70 , struct V_152 * V_153 ,
struct V_3 * V_4 )
{
T_1 V_154 = ( (struct V_155 * ) & V_153 -> V_156 ) -> V_157 . V_158 ;
T_1 V_159 = ( (struct V_155 * ) & V_153 -> V_160 ) -> V_157 . V_158 ;
if ( V_159 == F_95 ( 0xFFFFFFFF ) )
return F_108 ( & V_123 , V_70 , & V_154 , V_4 ) ;
if ( V_159 )
return - V_13 ;
return F_90 ( V_70 , V_4 , 0 ) ;
}
static int F_109 ( struct V_70 * V_70 , struct V_152 * V_153 ,
struct V_3 * V_4 )
{
T_1 V_154 ;
if ( V_153 -> V_161 & V_169 )
return F_107 ( V_70 , V_153 , V_4 ) ;
V_154 = ( (struct V_155 * ) & V_153 -> V_156 ) -> V_157 . V_158 ;
if ( ! V_4 ) {
struct V_73 * V_74 = F_41 ( V_70 , V_154 , 0 , V_171 , 0 ) ;
if ( F_42 ( V_74 ) )
return F_98 ( V_74 ) ;
V_4 = V_74 -> V_53 . V_4 ;
F_44 ( V_74 ) ;
if ( ! V_4 )
return - V_13 ;
}
return F_106 ( V_4 , V_154 ) ;
}
int F_110 ( struct V_70 * V_70 , unsigned int V_178 , void T_7 * V_179 )
{
int V_168 ;
struct V_152 V_153 ;
struct V_3 * V_4 = NULL ;
switch ( V_178 ) {
case V_180 :
case V_181 :
if ( ! F_111 ( V_70 -> V_182 , V_183 ) )
return - V_184 ;
case V_185 :
V_168 = F_112 ( & V_153 , V_179 , sizeof( struct V_152 ) ) ;
if ( V_168 )
return - V_186 ;
break;
default:
return - V_13 ;
}
if ( V_153 . V_156 . V_164 != V_187 )
return - V_188 ;
if ( ! ( V_153 . V_161 & V_169 ) &&
( V_153 . V_161 & ( V_189 | V_190 ) ) )
return - V_13 ;
if ( ! ( V_153 . V_161 & V_189 ) )
( (struct V_155 * ) & V_153 . V_160 ) -> V_157 . V_158 =
F_95 ( 0xFFFFFFFFUL ) ;
F_113 () ;
if ( V_153 . V_175 [ 0 ] ) {
V_168 = - V_166 ;
V_4 = F_114 ( V_70 , V_153 . V_175 ) ;
if ( ! V_4 )
goto V_89;
if ( ! V_153 . V_163 . V_164 )
V_153 . V_163 . V_164 = V_4 -> type ;
V_168 = - V_13 ;
if ( ( V_153 . V_161 & V_162 ) && V_153 . V_163 . V_164 != V_4 -> type )
goto V_89;
} else if ( V_178 == V_185 ) {
V_168 = - V_166 ;
goto V_89;
}
switch ( V_178 ) {
case V_180 :
V_168 = F_109 ( V_70 , & V_153 , V_4 ) ;
break;
case V_181 :
V_168 = F_97 ( V_70 , & V_153 , V_4 ) ;
break;
case V_185 :
V_168 = F_101 ( & V_153 , V_4 ) ;
break;
}
V_89:
F_115 () ;
if ( V_178 == V_185 && ! V_168 && F_116 ( V_179 , & V_153 , sizeof( V_153 ) ) )
V_168 = - V_186 ;
return V_168 ;
}
static int F_117 ( struct V_191 * V_192 , unsigned long V_193 ,
void * V_194 )
{
struct V_3 * V_4 = F_118 ( V_194 ) ;
struct V_195 * V_196 ;
switch ( V_193 ) {
case V_197 :
F_119 ( & V_123 , V_4 ) ;
F_120 ( F_14 ( V_4 ) ) ;
break;
case V_198 :
V_196 = V_194 ;
if ( V_196 -> V_199 & V_34 )
F_119 ( & V_123 , V_4 ) ;
break;
default:
break;
}
return V_200 ;
}
void F_121 ( struct V_3 * V_4 )
{
F_122 ( & V_123 , V_4 ) ;
}
void T_8 F_123 ( void )
{
F_124 ( V_201 , & V_123 ) ;
F_125 ( & V_202 ) ;
F_126 () ;
#ifdef F_127
F_128 ( NULL , & V_123 . V_22 , NULL ) ;
#endif
F_129 ( & V_203 ) ;
}
static void F_130 ( T_9 * V_204 , char * V_205 )
{
char V_206 , * V_207 ;
int V_115 ;
for ( V_115 = 0 , V_207 = V_205 ; V_115 < 6 ; V_115 ++ ) {
V_206 = ( V_204 -> V_208 [ V_115 ] >> 1 ) & 0x7F ;
if ( V_206 != ' ' )
* V_207 ++ = V_206 ;
}
* V_207 ++ = '-' ;
V_115 = ( V_204 -> V_208 [ 6 ] >> 1 ) & 0x0F ;
if ( V_115 > 9 ) {
* V_207 ++ = '1' ;
V_115 -= 10 ;
}
* V_207 ++ = V_115 + '0' ;
* V_207 ++ = '\0' ;
if ( * V_205 == '\0' || * V_205 == '-' ) {
V_205 [ 0 ] = '*' ;
V_205 [ 1 ] = '\0' ;
}
}
static void F_131 ( struct V_209 * V_210 ,
struct V_16 * V_115 )
{
char V_211 [ V_212 ] ;
int V_213 , V_214 ;
char V_215 [ 16 ] ;
struct V_3 * V_4 = V_115 -> V_4 ;
int V_216 = V_4 -> type ;
F_132 ( & V_115 -> V_174 ) ;
#if F_58 ( V_93 )
if ( V_216 == V_94 || V_216 == V_97 )
F_130 ( ( T_9 * ) V_115 -> V_32 , V_211 ) ;
else {
#endif
for ( V_213 = 0 , V_214 = 0 ; V_213 < V_212 - 3 && V_214 < V_4 -> V_12 ; V_214 ++ ) {
V_211 [ V_213 ++ ] = F_133 ( V_115 -> V_32 [ V_214 ] ) ;
V_211 [ V_213 ++ ] = F_134 ( V_115 -> V_32 [ V_214 ] ) ;
V_211 [ V_213 ++ ] = ':' ;
}
if ( V_213 != 0 )
-- V_213 ;
V_211 [ V_213 ] = 0 ;
#if F_58 ( V_93 )
}
#endif
sprintf ( V_215 , L_2 , V_115 -> V_18 ) ;
F_135 ( V_210 , L_3 ,
V_215 , V_216 , F_100 ( V_115 ) , V_211 , V_4 -> V_176 ) ;
F_136 ( & V_115 -> V_174 ) ;
}
static void F_137 ( struct V_209 * V_210 ,
struct V_217 * V_115 )
{
struct V_3 * V_4 = V_115 -> V_4 ;
int V_216 = V_4 ? V_4 -> type : 0 ;
char V_215 [ 16 ] ;
sprintf ( V_215 , L_2 , V_115 -> V_218 ) ;
F_135 ( V_210 , L_4 ,
V_215 , V_216 , V_169 | V_170 , L_5 ,
V_4 ? V_4 -> V_176 : L_6 ) ;
}
static int F_138 ( struct V_209 * V_210 , void * V_219 )
{
if ( V_219 == V_220 ) {
F_139 ( V_210 , L_7
L_8 ) ;
} else {
struct V_221 * V_129 = V_210 -> V_222 ;
if ( V_129 -> V_33 & V_223 )
F_137 ( V_210 , V_219 ) ;
else
F_131 ( V_210 , V_219 ) ;
}
return 0 ;
}
static void * F_140 ( struct V_209 * V_210 , T_10 * V_224 )
{
return F_141 ( V_210 , V_224 , & V_123 , V_225 ) ;
}
static int F_142 ( struct V_226 * V_226 , struct V_227 * V_227 )
{
return F_143 ( V_226 , V_227 , & V_228 ,
sizeof( struct V_221 ) ) ;
}
static int T_11 F_144 ( struct V_70 * V_70 )
{
if ( ! F_145 ( L_9 , V_229 , V_70 -> V_230 , & V_231 ) )
return - V_232 ;
return 0 ;
}
static void T_12 F_146 ( struct V_70 * V_70 )
{
F_147 ( L_9 , V_70 -> V_230 ) ;
}
static int T_8 F_126 ( void )
{
return F_148 ( & V_233 ) ;
}
static int T_8 F_126 ( void )
{
return 0 ;
}
