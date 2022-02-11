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
V_17 -> type = F_13 ( F_14 ( V_4 ) , V_1 ) ;
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
static void F_20 ( struct V_16 * V_17 , struct V_44 * V_45 )
{
T_1 V_46 = 0 ;
T_2 V_47 [ V_48 ] , * V_49 = NULL ;
struct V_3 * V_4 = V_17 -> V_4 ;
T_1 V_50 = * ( T_1 * ) V_17 -> V_18 ;
int V_51 = F_21 ( & V_17 -> V_51 ) ;
struct V_19 * V_20 ;
F_10 () ;
V_20 = F_11 ( V_4 ) ;
if ( ! V_20 ) {
F_12 () ;
return;
}
switch ( F_22 ( V_20 ) ) {
default:
case 0 :
if ( V_45 && F_13 ( F_14 ( V_4 ) ,
F_23 ( V_45 ) -> V_46 ) == V_52 )
V_46 = F_23 ( V_45 ) -> V_46 ;
break;
case 1 :
if ( ! V_45 )
break;
V_46 = F_23 ( V_45 ) -> V_46 ;
if ( F_13 ( F_14 ( V_4 ) , V_46 ) == V_52 ) {
if ( F_24 ( V_20 , V_50 , V_46 ) )
break;
}
V_46 = 0 ;
break;
case 2 :
break;
}
F_12 () ;
if ( ! V_46 )
V_46 = F_25 ( V_4 , V_50 , V_53 ) ;
V_51 -= F_26 ( V_17 -> V_22 , V_54 ) ;
if ( V_51 < 0 ) {
if ( ! ( V_17 -> V_25 & V_42 ) )
F_27 ( L_1 ) ;
F_28 ( V_47 , V_17 , V_4 ) ;
V_49 = V_47 ;
} else {
V_51 -= F_26 ( V_17 -> V_22 , V_55 ) ;
if ( V_51 < 0 ) {
F_29 ( V_17 ) ;
return;
}
}
F_30 ( V_56 , V_57 , V_50 , V_4 , V_46 ,
V_49 , V_4 -> V_36 , NULL ) ;
}
static int F_31 ( struct V_19 * V_20 , T_1 V_58 , T_1 V_59 )
{
struct V_60 * V_60 = F_14 ( V_20 -> V_4 ) ;
int V_61 ;
switch ( F_32 ( V_20 ) ) {
case 0 :
return 0 ;
case 1 :
V_58 = 0 ;
V_61 = V_62 ;
break;
case 2 :
V_61 = V_62 ;
break;
case 3 :
V_58 = 0 ;
V_61 = V_53 ;
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
return ! F_33 ( V_60 , V_20 , V_58 , V_59 , V_61 ) ;
}
static int F_34 ( T_1 V_58 , T_1 V_59 , struct V_3 * V_4 )
{
struct V_63 * V_64 ;
int V_65 = 0 ;
struct V_60 * V_60 = F_14 ( V_4 ) ;
V_64 = F_35 ( V_60 , V_58 , V_59 , 0 , 0 ) ;
if ( F_36 ( V_64 ) )
return 1 ;
if ( V_64 -> V_66 . V_4 != V_4 ) {
F_37 ( V_60 , V_67 ) ;
V_65 = 1 ;
}
F_38 ( V_64 ) ;
return V_65 ;
}
static inline int F_39 ( struct V_19 * V_20 ,
struct V_3 * V_4 , struct V_63 * V_64 )
{
struct V_19 * V_68 ;
int V_69 , V_70 = - 1 ;
if ( V_64 -> V_66 . V_4 == V_4 )
return 0 ;
if ( ! F_40 ( V_20 ) )
return 0 ;
V_69 = F_41 ( V_20 ) ;
if ( V_69 == 0 )
return 1 ;
if ( V_69 == - 1 )
return 0 ;
V_68 = F_11 ( V_64 -> V_66 . V_4 ) ;
if ( V_68 )
V_70 = F_41 ( V_68 ) ;
return V_70 != V_69 && V_70 != - 1 ;
}
static inline int F_42 ( struct V_19 * V_20 ,
struct V_3 * V_4 , struct V_63 * V_64 ,
T_1 V_58 , T_1 V_59 )
{
if ( V_64 -> V_66 . V_4 != V_4 )
return 0 ;
if ( V_58 == V_59 )
return 0 ;
if ( F_43 ( V_20 ) )
return 1 ;
else
return 0 ;
}
struct V_44 * F_44 ( int type , int V_71 , T_1 V_72 ,
struct V_3 * V_4 , T_1 V_73 ,
const unsigned char * V_74 ,
const unsigned char * V_75 ,
const unsigned char * V_76 )
{
struct V_44 * V_45 ;
struct V_77 * V_78 ;
unsigned char * V_79 ;
int V_80 = F_45 ( V_4 ) ;
int V_81 = V_4 -> V_82 ;
V_45 = F_46 ( F_47 ( V_4 ) + V_80 + V_81 , V_83 ) ;
if ( ! V_45 )
return NULL ;
F_48 ( V_45 , V_80 ) ;
F_49 ( V_45 ) ;
V_78 = (struct V_77 * ) F_50 ( V_45 , F_47 ( V_4 ) ) ;
V_45 -> V_4 = V_4 ;
V_45 -> V_84 = F_51 ( V_57 ) ;
if ( ! V_75 )
V_75 = V_4 -> V_36 ;
if ( ! V_74 )
V_74 = V_4 -> V_10 ;
if ( F_52 ( V_45 , V_4 , V_71 , V_74 , V_75 , V_45 -> V_85 ) < 0 )
goto V_86;
switch ( V_4 -> type ) {
default:
V_78 -> V_87 = F_51 ( V_4 -> type ) ;
V_78 -> V_88 = F_51 ( V_89 ) ;
break;
#if F_53 ( V_90 )
case V_91 :
V_78 -> V_87 = F_51 ( V_91 ) ;
V_78 -> V_88 = F_51 ( V_92 ) ;
break;
#if F_53 ( V_93 )
case V_94 :
V_78 -> V_87 = F_51 ( V_94 ) ;
V_78 -> V_88 = F_51 ( V_92 ) ;
break;
#endif
#endif
#if F_53 ( V_95 )
case V_7 :
V_78 -> V_87 = F_51 ( V_6 ) ;
V_78 -> V_88 = F_51 ( V_89 ) ;
break;
#endif
}
V_78 -> V_96 = V_4 -> V_12 ;
V_78 -> V_97 = 4 ;
V_78 -> V_98 = F_51 ( type ) ;
V_79 = ( unsigned char * ) ( V_78 + 1 ) ;
memcpy ( V_79 , V_75 , V_4 -> V_12 ) ;
V_79 += V_4 -> V_12 ;
memcpy ( V_79 , & V_73 , 4 ) ;
V_79 += 4 ;
switch ( V_4 -> type ) {
#if F_53 ( V_99 )
case V_100 :
break;
#endif
default:
if ( V_76 )
memcpy ( V_79 , V_76 , V_4 -> V_12 ) ;
else
memset ( V_79 , 0 , V_4 -> V_12 ) ;
V_79 += V_4 -> V_12 ;
}
memcpy ( V_79 , & V_72 , 4 ) ;
return V_45 ;
V_86:
F_19 ( V_45 ) ;
return NULL ;
}
void F_54 ( struct V_44 * V_45 )
{
F_55 ( V_101 , V_102 , NULL , V_45 ,
NULL , V_45 -> V_4 , V_103 ) ;
}
void F_30 ( int type , int V_71 , T_1 V_72 ,
struct V_3 * V_4 , T_1 V_73 ,
const unsigned char * V_74 , const unsigned char * V_75 ,
const unsigned char * V_76 )
{
struct V_44 * V_45 ;
if ( V_4 -> V_33 & V_34 )
return;
V_45 = F_44 ( type , V_71 , V_72 , V_4 , V_73 ,
V_74 , V_75 , V_76 ) ;
if ( ! V_45 )
return;
F_54 ( V_45 ) ;
}
static int F_56 ( struct V_104 * V_105 , struct V_44 * V_45 )
{
struct V_3 * V_4 = V_45 -> V_4 ;
struct V_19 * V_20 = F_11 ( V_4 ) ;
struct V_77 * V_78 ;
unsigned char * V_79 ;
struct V_63 * V_64 ;
unsigned char * V_106 ;
T_1 V_58 , V_59 ;
T_5 V_107 = V_4 -> type ;
int V_108 ;
struct V_16 * V_109 ;
struct V_60 * V_60 = F_14 ( V_4 ) ;
bool V_110 = false ;
if ( ! V_20 )
goto V_86;
V_78 = F_57 ( V_45 ) ;
switch ( V_107 ) {
default:
if ( V_78 -> V_88 != F_51 ( V_89 ) ||
F_51 ( V_107 ) != V_78 -> V_87 )
goto V_86;
break;
case V_6 :
case V_7 :
case V_8 :
if ( ( V_78 -> V_87 != F_51 ( V_6 ) &&
V_78 -> V_87 != F_51 ( V_8 ) ) ||
V_78 -> V_88 != F_51 ( V_89 ) )
goto V_86;
break;
case V_91 :
if ( V_78 -> V_88 != F_51 ( V_92 ) ||
V_78 -> V_87 != F_51 ( V_91 ) )
goto V_86;
break;
case V_94 :
if ( V_78 -> V_88 != F_51 ( V_92 ) ||
V_78 -> V_87 != F_51 ( V_94 ) )
goto V_86;
break;
}
if ( V_78 -> V_98 != F_51 ( V_111 ) &&
V_78 -> V_98 != F_51 ( V_56 ) )
goto V_86;
V_79 = ( unsigned char * ) ( V_78 + 1 ) ;
V_106 = V_79 ;
V_79 += V_4 -> V_12 ;
memcpy ( & V_58 , V_79 , 4 ) ;
V_79 += 4 ;
switch ( V_107 ) {
#if F_53 ( V_99 )
case V_100 :
break;
#endif
default:
V_79 += V_4 -> V_12 ;
}
memcpy ( & V_59 , V_79 , 4 ) ;
if ( F_58 ( V_59 ) ||
( ! F_59 ( V_20 ) && F_60 ( V_59 ) ) )
goto V_86;
if ( V_107 == V_112 )
V_106 = V_4 -> V_10 ;
if ( V_58 == 0 ) {
if ( V_78 -> V_98 == F_51 ( V_56 ) &&
F_13 ( V_60 , V_59 ) == V_52 &&
! F_31 ( V_20 , V_58 , V_59 ) )
F_30 ( V_111 , V_57 , V_58 , V_4 , V_59 , V_106 ,
V_4 -> V_36 , V_106 ) ;
goto V_86;
}
if ( V_78 -> V_98 == F_51 ( V_56 ) &&
F_61 ( V_45 , V_59 , V_58 , 0 , V_4 ) == 0 ) {
V_64 = F_62 ( V_45 ) ;
V_108 = V_64 -> V_113 ;
if ( V_108 == V_52 ) {
int V_114 ;
V_114 = F_31 ( V_20 , V_58 , V_59 ) ;
if ( ! V_114 && F_63 ( V_20 ) )
V_114 = F_34 ( V_58 , V_59 , V_4 ) ;
if ( ! V_114 ) {
V_109 = F_64 ( & V_115 , V_106 , & V_58 , V_4 ) ;
if ( V_109 ) {
F_30 ( V_111 , V_57 , V_58 ,
V_4 , V_59 , V_106 , V_4 -> V_36 ,
V_106 ) ;
F_65 ( V_109 ) ;
}
}
goto V_86;
} else if ( F_66 ( V_20 ) ) {
if ( V_108 == V_116 &&
( F_39 ( V_20 , V_4 , V_64 ) ||
F_42 ( V_20 , V_4 , V_64 , V_58 , V_59 ) ||
( V_64 -> V_66 . V_4 != V_4 &&
F_67 ( & V_115 , V_60 , & V_59 , V_4 , 0 ) ) ) ) {
V_109 = F_64 ( & V_115 , V_106 , & V_58 , V_4 ) ;
if ( V_109 )
F_65 ( V_109 ) ;
if ( F_68 ( V_45 ) -> V_33 & V_117 ||
V_45 -> V_118 == V_119 ||
F_26 ( V_20 -> V_23 , V_120 ) == 0 ) {
F_30 ( V_111 , V_57 , V_58 ,
V_4 , V_59 , V_106 , V_4 -> V_36 ,
V_106 ) ;
} else {
F_69 ( & V_115 ,
V_20 -> V_23 , V_45 ) ;
return 0 ;
}
goto V_86;
}
}
}
V_109 = F_70 ( & V_115 , & V_58 , V_4 , 0 ) ;
if ( F_71 ( V_20 ) ) {
V_110 = V_78 -> V_98 == F_51 ( V_56 ) && V_59 == V_58 &&
F_13 ( V_60 , V_58 ) == V_116 ;
if ( ! V_109 &&
( ( V_78 -> V_98 == F_51 ( V_111 ) &&
F_13 ( V_60 , V_58 ) == V_116 ) || V_110 ) )
V_109 = F_70 ( & V_115 , & V_58 , V_4 , 1 ) ;
}
if ( V_109 ) {
int V_121 = V_122 ;
int V_123 ;
V_123 = F_72 ( V_124 ,
V_109 -> V_125 +
F_26 ( V_109 -> V_22 , V_126 ) ) ||
V_110 ;
if ( V_78 -> V_98 != F_51 ( V_111 ) ||
V_45 -> V_118 != V_119 )
V_121 = V_127 ;
F_73 ( V_109 , V_106 , V_121 ,
V_123 ? V_128 : 0 ) ;
F_65 ( V_109 ) ;
}
V_86:
F_74 ( V_45 ) ;
return 0 ;
}
static void F_75 ( struct V_44 * V_45 )
{
F_56 ( NULL , V_45 ) ;
}
static int F_76 ( struct V_44 * V_45 , struct V_3 * V_4 ,
struct V_129 * V_130 , struct V_3 * V_131 )
{
const struct V_77 * V_78 ;
if ( V_4 -> V_33 & V_34 ||
V_45 -> V_118 == V_132 ||
V_45 -> V_118 == V_133 )
goto V_134;
V_45 = F_77 ( V_45 , V_83 ) ;
if ( ! V_45 )
goto V_135;
if ( ! F_78 ( V_45 , F_47 ( V_4 ) ) )
goto V_136;
V_78 = F_57 ( V_45 ) ;
if ( V_78 -> V_96 != V_4 -> V_12 || V_78 -> V_97 != 4 )
goto V_136;
memset ( F_68 ( V_45 ) , 0 , sizeof( struct V_137 ) ) ;
return F_55 ( V_101 , V_138 , NULL , V_45 ,
V_4 , NULL , F_56 ) ;
V_134:
F_74 ( V_45 ) ;
return 0 ;
V_136:
F_19 ( V_45 ) ;
V_135:
return 0 ;
}
static int F_79 ( struct V_60 * V_60 , struct V_3 * V_4 , int V_139 )
{
if ( ! V_4 ) {
F_80 ( V_60 , V_140 ) = V_139 ;
return 0 ;
}
if ( F_81 ( V_4 ) ) {
F_82 ( F_81 ( V_4 ) , V_140 , V_139 ) ;
return 0 ;
}
return - V_141 ;
}
static int F_83 ( struct V_60 * V_60 , struct V_142 * V_143 ,
struct V_3 * V_4 )
{
T_1 V_144 = ( (struct V_145 * ) & V_143 -> V_146 ) -> V_147 . V_148 ;
T_1 V_149 = ( (struct V_145 * ) & V_143 -> V_150 ) -> V_147 . V_148 ;
if ( V_149 && V_149 != F_84 ( 0xFFFFFFFF ) )
return - V_13 ;
if ( ! V_4 && ( V_143 -> V_151 & V_152 ) ) {
V_4 = F_85 ( V_60 , V_143 -> V_153 . V_154 ,
V_143 -> V_153 . V_155 ) ;
if ( ! V_4 )
return - V_156 ;
}
if ( V_149 ) {
if ( ! F_67 ( & V_115 , V_60 , & V_144 , V_4 , 1 ) )
return - V_157 ;
return 0 ;
}
return F_79 ( V_60 , V_4 , 1 ) ;
}
static int F_86 ( struct V_60 * V_60 , struct V_142 * V_143 ,
struct V_3 * V_4 )
{
T_1 V_144 ;
struct V_16 * V_17 ;
int V_158 ;
if ( V_143 -> V_151 & V_159 )
return F_83 ( V_60 , V_143 , V_4 ) ;
V_144 = ( (struct V_145 * ) & V_143 -> V_146 ) -> V_147 . V_148 ;
if ( V_143 -> V_151 & V_160 )
V_143 -> V_151 |= V_152 ;
if ( ! V_4 ) {
struct V_63 * V_64 = F_35 ( V_60 , V_144 , 0 , V_161 , 0 ) ;
if ( F_36 ( V_64 ) )
return F_87 ( V_64 ) ;
V_4 = V_64 -> V_66 . V_4 ;
F_38 ( V_64 ) ;
if ( ! V_4 )
return - V_13 ;
}
switch ( V_4 -> type ) {
#if F_53 ( V_95 )
case V_7 :
if ( V_143 -> V_153 . V_154 != V_7 &&
V_143 -> V_153 . V_154 != V_6 &&
V_143 -> V_153 . V_154 != V_8 )
return - V_13 ;
break;
#endif
default:
if ( V_143 -> V_153 . V_154 != V_4 -> type )
return - V_13 ;
break;
}
V_17 = F_88 ( & V_115 , & V_144 , V_4 ) ;
V_158 = F_87 ( V_17 ) ;
if ( ! F_36 ( V_17 ) ) {
unsigned int V_121 = V_127 ;
if ( V_143 -> V_151 & V_160 )
V_121 = V_162 ;
V_158 = F_73 ( V_17 , ( V_143 -> V_151 & V_152 ) ?
V_143 -> V_153 . V_155 : NULL , V_121 ,
V_128 |
V_163 ) ;
F_65 ( V_17 ) ;
}
return V_158 ;
}
static unsigned int F_89 ( struct V_16 * V_17 )
{
if ( V_17 -> V_25 & V_162 )
return V_160 | V_152 ;
else if ( V_17 -> V_25 & V_42 )
return V_152 ;
else
return 0 ;
}
static int F_90 ( struct V_142 * V_143 , struct V_3 * V_4 )
{
T_1 V_144 = ( (struct V_145 * ) & V_143 -> V_146 ) -> V_147 . V_148 ;
struct V_16 * V_17 ;
int V_158 = - V_141 ;
V_17 = F_91 ( & V_115 , & V_144 , V_4 ) ;
if ( V_17 ) {
if ( ! ( V_17 -> V_25 & V_26 ) ) {
F_92 ( & V_17 -> V_164 ) ;
memcpy ( V_143 -> V_153 . V_155 , V_17 -> V_32 , V_4 -> V_12 ) ;
V_143 -> V_151 = F_89 ( V_17 ) ;
F_93 ( & V_17 -> V_164 ) ;
V_143 -> V_153 . V_154 = V_4 -> type ;
F_94 ( V_143 -> V_165 , V_4 -> V_166 , sizeof( V_143 -> V_165 ) ) ;
V_158 = 0 ;
}
F_65 ( V_17 ) ;
}
return V_158 ;
}
static int F_95 ( struct V_3 * V_4 , T_1 V_144 )
{
struct V_16 * V_17 = F_91 ( & V_115 , & V_144 , V_4 ) ;
int V_158 = - V_141 ;
if ( V_17 ) {
if ( V_17 -> V_25 & ~ V_26 )
V_158 = F_73 ( V_17 , NULL , V_167 ,
V_128 |
V_163 ) ;
F_65 ( V_17 ) ;
}
return V_158 ;
}
static int F_96 ( struct V_60 * V_60 , struct V_142 * V_143 ,
struct V_3 * V_4 )
{
T_1 V_144 = ( (struct V_145 * ) & V_143 -> V_146 ) -> V_147 . V_148 ;
T_1 V_149 = ( (struct V_145 * ) & V_143 -> V_150 ) -> V_147 . V_148 ;
if ( V_149 == F_84 ( 0xFFFFFFFF ) )
return F_97 ( & V_115 , V_60 , & V_144 , V_4 ) ;
if ( V_149 )
return - V_13 ;
return F_79 ( V_60 , V_4 , 0 ) ;
}
static int F_98 ( struct V_60 * V_60 , struct V_142 * V_143 ,
struct V_3 * V_4 )
{
T_1 V_144 ;
if ( V_143 -> V_151 & V_159 )
return F_96 ( V_60 , V_143 , V_4 ) ;
V_144 = ( (struct V_145 * ) & V_143 -> V_146 ) -> V_147 . V_148 ;
if ( ! V_4 ) {
struct V_63 * V_64 = F_35 ( V_60 , V_144 , 0 , V_161 , 0 ) ;
if ( F_36 ( V_64 ) )
return F_87 ( V_64 ) ;
V_4 = V_64 -> V_66 . V_4 ;
F_38 ( V_64 ) ;
if ( ! V_4 )
return - V_13 ;
}
return F_95 ( V_4 , V_144 ) ;
}
int F_99 ( struct V_60 * V_60 , unsigned int V_168 , void T_6 * V_169 )
{
int V_158 ;
struct V_142 V_143 ;
struct V_3 * V_4 = NULL ;
switch ( V_168 ) {
case V_170 :
case V_171 :
if ( ! F_100 ( V_60 -> V_172 , V_173 ) )
return - V_174 ;
case V_175 :
V_158 = F_101 ( & V_143 , V_169 , sizeof( struct V_142 ) ) ;
if ( V_158 )
return - V_176 ;
break;
default:
return - V_13 ;
}
if ( V_143 . V_146 . V_154 != V_177 )
return - V_178 ;
if ( ! ( V_143 . V_151 & V_159 ) &&
( V_143 . V_151 & ( V_179 | V_180 ) ) )
return - V_13 ;
if ( ! ( V_143 . V_151 & V_179 ) )
( (struct V_145 * ) & V_143 . V_150 ) -> V_147 . V_148 =
F_84 ( 0xFFFFFFFFUL ) ;
F_102 () ;
if ( V_143 . V_165 [ 0 ] ) {
V_158 = - V_156 ;
V_4 = F_103 ( V_60 , V_143 . V_165 ) ;
if ( ! V_4 )
goto V_86;
if ( ! V_143 . V_153 . V_154 )
V_143 . V_153 . V_154 = V_4 -> type ;
V_158 = - V_13 ;
if ( ( V_143 . V_151 & V_152 ) && V_143 . V_153 . V_154 != V_4 -> type )
goto V_86;
} else if ( V_168 == V_175 ) {
V_158 = - V_156 ;
goto V_86;
}
switch ( V_168 ) {
case V_170 :
V_158 = F_98 ( V_60 , & V_143 , V_4 ) ;
break;
case V_171 :
V_158 = F_86 ( V_60 , & V_143 , V_4 ) ;
break;
case V_175 :
V_158 = F_90 ( & V_143 , V_4 ) ;
break;
}
V_86:
F_104 () ;
if ( V_168 == V_175 && ! V_158 && F_105 ( V_169 , & V_143 , sizeof( V_143 ) ) )
V_158 = - V_176 ;
return V_158 ;
}
static int F_106 ( struct V_181 * V_182 , unsigned long V_183 ,
void * V_184 )
{
struct V_3 * V_4 = F_107 ( V_184 ) ;
struct V_185 * V_186 ;
switch ( V_183 ) {
case V_187 :
F_108 ( & V_115 , V_4 ) ;
F_109 ( F_14 ( V_4 ) ) ;
break;
case V_188 :
V_186 = V_184 ;
if ( V_186 -> V_189 & V_34 )
F_108 ( & V_115 , V_4 ) ;
break;
default:
break;
}
return V_190 ;
}
void F_110 ( struct V_3 * V_4 )
{
F_111 ( & V_115 , V_4 ) ;
}
void T_7 F_112 ( void )
{
F_113 ( V_191 , & V_115 ) ;
F_114 ( & V_192 ) ;
F_115 () ;
#ifdef F_116
F_117 ( NULL , & V_115 . V_22 , NULL ) ;
#endif
F_118 ( & V_193 ) ;
}
static char * F_119 ( T_8 * V_194 , char * V_195 )
{
char V_196 , * V_197 ;
int V_109 ;
for ( V_109 = 0 , V_197 = V_195 ; V_109 < 6 ; V_109 ++ ) {
V_196 = ( V_194 -> V_198 [ V_109 ] >> 1 ) & 0x7F ;
if ( V_196 != ' ' )
* V_197 ++ = V_196 ;
}
* V_197 ++ = '-' ;
V_109 = ( V_194 -> V_198 [ 6 ] >> 1 ) & 0x0F ;
if ( V_109 > 9 ) {
* V_197 ++ = '1' ;
V_109 -= 10 ;
}
* V_197 ++ = V_109 + '0' ;
* V_197 ++ = '\0' ;
if ( * V_195 == '\0' || * V_195 == '-' )
return L_2 ;
return V_195 ;
}
static void F_120 ( struct V_199 * V_200 ,
struct V_16 * V_109 )
{
char V_201 [ V_202 ] ;
int V_203 , V_204 ;
char V_205 [ 16 ] ;
struct V_3 * V_4 = V_109 -> V_4 ;
int V_206 = V_4 -> type ;
F_121 ( & V_109 -> V_164 ) ;
#if F_53 ( V_90 )
if ( V_206 == V_91 || V_206 == V_94 )
F_119 ( ( T_8 * ) V_109 -> V_32 , V_201 ) ;
else {
#endif
for ( V_203 = 0 , V_204 = 0 ; V_203 < V_202 - 3 && V_204 < V_4 -> V_12 ; V_204 ++ ) {
V_201 [ V_203 ++ ] = F_122 ( V_109 -> V_32 [ V_204 ] ) ;
V_201 [ V_203 ++ ] = F_123 ( V_109 -> V_32 [ V_204 ] ) ;
V_201 [ V_203 ++ ] = ':' ;
}
if ( V_203 != 0 )
-- V_203 ;
V_201 [ V_203 ] = 0 ;
#if F_53 ( V_90 )
}
#endif
sprintf ( V_205 , L_3 , V_109 -> V_18 ) ;
F_124 ( V_200 , L_4 ,
V_205 , V_206 , F_89 ( V_109 ) , V_201 , V_4 -> V_166 ) ;
F_125 ( & V_109 -> V_164 ) ;
}
static void F_126 ( struct V_199 * V_200 ,
struct V_207 * V_109 )
{
struct V_3 * V_4 = V_109 -> V_4 ;
int V_206 = V_4 ? V_4 -> type : 0 ;
char V_205 [ 16 ] ;
sprintf ( V_205 , L_3 , V_109 -> V_208 ) ;
F_124 ( V_200 , L_4 ,
V_205 , V_206 , V_159 | V_160 , L_5 ,
V_4 ? V_4 -> V_166 : L_2 ) ;
}
static int F_127 ( struct V_199 * V_200 , void * V_209 )
{
if ( V_209 == V_210 ) {
F_128 ( V_200 , L_6
L_7 ) ;
} else {
struct V_211 * V_121 = V_200 -> V_212 ;
if ( V_121 -> V_33 & V_213 )
F_126 ( V_200 , V_209 ) ;
else
F_120 ( V_200 , V_209 ) ;
}
return 0 ;
}
static void * F_129 ( struct V_199 * V_200 , T_9 * V_214 )
{
return F_130 ( V_200 , V_214 , & V_115 , V_215 ) ;
}
static int F_131 ( struct V_216 * V_216 , struct V_217 * V_217 )
{
return F_132 ( V_216 , V_217 , & V_218 ,
sizeof( struct V_211 ) ) ;
}
static int T_10 F_133 ( struct V_60 * V_60 )
{
if ( ! F_134 ( L_8 , V_219 , V_60 -> V_220 , & V_221 ) )
return - V_222 ;
return 0 ;
}
static void T_11 F_135 ( struct V_60 * V_60 )
{
F_136 ( L_8 , V_60 -> V_220 ) ;
}
static int T_7 F_115 ( void )
{
return F_137 ( & V_223 ) ;
}
static int T_7 F_115 ( void )
{
return 0 ;
}
