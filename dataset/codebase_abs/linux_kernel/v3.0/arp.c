int F_1 ( T_1 V_1 , T_2 * V_2 , struct V_3 * V_4 , int V_5 )
{
switch ( V_4 -> type ) {
case V_6 :
case V_7 :
case V_8 :
F_2 ( V_1 , V_2 ) ;
return 0 ;
case V_9 :
F_3 ( V_1 , V_2 ) ;
return 0 ;
case V_10 :
F_4 ( V_1 , V_4 -> V_11 , V_2 ) ;
return 0 ;
case V_12 :
F_5 ( V_1 , V_4 -> V_11 , V_2 ) ;
return 0 ;
default:
if ( V_5 ) {
memcpy ( V_2 , V_4 -> V_11 , V_4 -> V_13 ) ;
return 0 ;
}
}
return - V_14 ;
}
static T_3 F_6 ( const void * V_15 ,
const struct V_3 * V_4 ,
T_4 V_16 )
{
return F_7 ( * ( T_3 * ) V_15 , V_4 -> V_17 , V_16 ) ;
}
static int F_8 ( struct V_18 * V_19 )
{
T_1 V_1 = * ( T_1 * ) V_19 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
F_9 () ;
V_22 = F_10 ( V_4 ) ;
if ( V_22 == NULL ) {
F_11 () ;
return - V_14 ;
}
V_19 -> type = F_12 ( F_13 ( V_4 ) , V_1 ) ;
V_24 = V_22 -> V_25 ;
F_14 ( V_19 -> V_24 ) ;
V_19 -> V_24 = F_15 ( V_24 ) ;
F_11 () ;
if ( ! V_4 -> V_26 ) {
V_19 -> V_27 = V_28 ;
V_19 -> V_29 = & V_30 ;
V_19 -> V_31 = V_19 -> V_29 -> V_32 ;
} else {
#if 1
switch ( V_4 -> type ) {
default:
break;
case V_33 :
#if F_16 ( V_34 ) || F_16 ( V_35 )
case V_36 :
#if F_16 ( V_37 ) || F_16 ( V_38 )
case V_39 :
#endif
V_19 -> V_29 = & V_40 ;
V_19 -> V_31 = V_19 -> V_29 -> V_31 ;
return 0 ;
#else
break;
#endif
}
#endif
if ( V_19 -> type == V_41 ) {
V_19 -> V_27 = V_28 ;
F_1 ( V_1 , V_19 -> V_42 , V_4 , 1 ) ;
} else if ( V_4 -> V_43 & ( V_44 | V_45 ) ) {
V_19 -> V_27 = V_28 ;
memcpy ( V_19 -> V_42 , V_4 -> V_46 , V_4 -> V_13 ) ;
} else if ( V_19 -> type == V_47 ||
( V_4 -> V_43 & V_48 ) ) {
V_19 -> V_27 = V_28 ;
memcpy ( V_19 -> V_42 , V_4 -> V_11 , V_4 -> V_13 ) ;
}
if ( V_4 -> V_26 -> V_49 )
V_19 -> V_29 = & V_50 ;
else
V_19 -> V_29 = & V_51 ;
if ( V_19 -> V_27 & V_52 )
V_19 -> V_31 = V_19 -> V_29 -> V_53 ;
else
V_19 -> V_31 = V_19 -> V_29 -> V_31 ;
}
return 0 ;
}
static void F_17 ( struct V_18 * V_19 , struct V_54 * V_55 )
{
F_18 ( V_55 ) ;
F_19 ( V_55 ) ;
}
static void F_20 ( struct V_18 * V_19 , struct V_54 * V_55 )
{
T_1 V_56 = 0 ;
T_2 * V_57 = NULL ;
struct V_3 * V_4 = V_19 -> V_4 ;
T_1 V_58 = * ( T_1 * ) V_19 -> V_20 ;
int V_59 = F_21 ( & V_19 -> V_59 ) ;
struct V_21 * V_22 ;
F_9 () ;
V_22 = F_10 ( V_4 ) ;
if ( ! V_22 ) {
F_11 () ;
return;
}
switch ( F_22 ( V_22 ) ) {
default:
case 0 :
if ( V_55 && F_12 ( F_13 ( V_4 ) ,
F_23 ( V_55 ) -> V_56 ) == V_60 )
V_56 = F_23 ( V_55 ) -> V_56 ;
break;
case 1 :
if ( ! V_55 )
break;
V_56 = F_23 ( V_55 ) -> V_56 ;
if ( F_12 ( F_13 ( V_4 ) , V_56 ) == V_60 ) {
if ( F_24 ( V_22 , V_58 , V_56 ) )
break;
}
V_56 = 0 ;
break;
case 2 :
break;
}
F_11 () ;
if ( ! V_56 )
V_56 = F_25 ( V_4 , V_58 , V_61 ) ;
V_59 -= V_19 -> V_24 -> V_62 ;
if ( V_59 < 0 ) {
if ( ! ( V_19 -> V_27 & V_52 ) )
F_26 ( V_63
L_1 ) ;
V_57 = V_19 -> V_42 ;
F_27 ( & V_19 -> V_64 ) ;
} else {
V_59 -= V_19 -> V_24 -> V_65 ;
if ( V_59 < 0 ) {
#ifdef F_28
F_29 ( V_19 ) ;
#endif
return;
}
}
F_30 ( V_66 , V_67 , V_58 , V_4 , V_56 ,
V_57 , V_4 -> V_46 , NULL ) ;
if ( V_57 )
F_31 ( & V_19 -> V_64 ) ;
}
static int F_32 ( struct V_21 * V_22 , T_1 V_68 , T_1 V_69 )
{
int V_70 ;
switch ( F_33 ( V_22 ) ) {
case 0 :
return 0 ;
case 1 :
V_68 = 0 ;
V_70 = V_71 ;
break;
case 2 :
V_70 = V_71 ;
break;
case 3 :
V_68 = 0 ;
V_70 = V_61 ;
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
return ! F_34 ( V_22 , V_68 , V_69 , V_70 ) ;
}
static int F_35 ( T_1 V_68 , T_1 V_69 , struct V_3 * V_4 )
{
struct V_72 * V_73 ;
int V_74 = 0 ;
struct V_75 * V_75 = F_13 ( V_4 ) ;
V_73 = F_36 ( V_75 , V_68 , V_69 , 0 , 0 ) ;
if ( F_37 ( V_73 ) )
return 1 ;
if ( V_73 -> V_76 . V_4 != V_4 ) {
F_38 ( V_75 , V_77 ) ;
V_74 = 1 ;
}
F_39 ( V_73 ) ;
return V_74 ;
}
static int F_40 ( int V_78 , unsigned char * V_2 ,
T_1 V_79 , struct V_3 * V_4 )
{
switch ( V_78 ) {
case V_60 :
F_26 ( V_63 L_2 ) ;
memcpy ( V_2 , V_4 -> V_46 , V_4 -> V_13 ) ;
return 1 ;
case V_41 :
F_1 ( V_79 , V_2 , V_4 , 1 ) ;
return 1 ;
case V_47 :
memcpy ( V_2 , V_4 -> V_11 , V_4 -> V_13 ) ;
return 1 ;
}
return 0 ;
}
int F_41 ( unsigned char * V_2 , struct V_54 * V_55 )
{
struct V_3 * V_4 = V_55 -> V_4 ;
T_1 V_79 ;
struct V_18 * V_80 ;
if ( ! F_42 ( V_55 ) ) {
F_26 ( V_63 L_3 ) ;
F_19 ( V_55 ) ;
return 1 ;
}
V_79 = F_43 ( V_55 ) -> V_81 ;
if ( F_40 ( F_12 ( F_13 ( V_4 ) , V_79 ) , V_2 ,
V_79 , V_4 ) )
return 0 ;
V_80 = F_44 ( & V_82 , & V_79 , V_4 , 1 ) ;
if ( V_80 ) {
V_80 -> V_83 = V_84 ;
if ( V_80 -> V_27 & V_52 || F_45 ( V_80 , V_55 ) == 0 ) {
F_46 ( V_2 , V_80 , V_4 ) ;
F_47 ( V_80 ) ;
return 0 ;
}
F_47 ( V_80 ) ;
} else
F_19 ( V_55 ) ;
return 1 ;
}
int F_48 ( struct V_85 * V_76 )
{
struct V_3 * V_4 = V_76 -> V_4 ;
struct V_18 * V_80 = V_76 -> V_18 ;
if ( V_4 == NULL )
return - V_14 ;
if ( V_80 == NULL ) {
T_1 V_86 = ( (struct V_72 * ) V_76 ) -> V_81 ;
if ( V_4 -> V_43 & ( V_45 | V_48 ) )
V_86 = 0 ;
V_80 = F_49 (
#if F_16 ( V_87 ) || F_16 ( V_88 )
V_4 -> type == V_89 ?
V_90 :
#endif
& V_82 , & V_86 , V_4 ) ;
if ( F_37 ( V_80 ) )
return F_50 ( V_80 ) ;
V_76 -> V_18 = V_80 ;
}
return 0 ;
}
static inline int F_51 ( struct V_21 * V_22 ,
struct V_3 * V_4 , struct V_72 * V_73 )
{
struct V_21 * V_91 ;
int V_92 , V_93 = - 1 ;
if ( V_73 -> V_76 . V_4 == V_4 )
return 0 ;
if ( ! F_52 ( V_22 ) )
return 0 ;
V_92 = F_53 ( V_22 ) ;
if ( V_92 == 0 )
return 1 ;
if ( V_92 == - 1 )
return 0 ;
V_91 = F_10 ( V_73 -> V_76 . V_4 ) ;
if ( V_91 )
V_93 = F_53 ( V_91 ) ;
return V_93 != V_92 && V_93 != - 1 ;
}
static inline int F_54 ( struct V_21 * V_22 ,
struct V_3 * V_4 , struct V_72 * V_73 ,
T_1 V_68 , T_1 V_69 )
{
if ( V_73 -> V_76 . V_4 != V_4 )
return 0 ;
if ( V_68 == V_69 )
return 0 ;
if ( F_55 ( V_22 ) )
return 1 ;
else
return 0 ;
}
struct V_54 * F_56 ( int type , int V_94 , T_1 V_95 ,
struct V_3 * V_4 , T_1 V_96 ,
const unsigned char * V_97 ,
const unsigned char * V_98 ,
const unsigned char * V_99 )
{
struct V_54 * V_55 ;
struct V_100 * V_101 ;
unsigned char * V_102 ;
V_55 = F_57 ( F_58 ( V_4 ) + F_59 ( V_4 ) , V_103 ) ;
if ( V_55 == NULL )
return NULL ;
F_60 ( V_55 , F_61 ( V_4 ) ) ;
F_62 ( V_55 ) ;
V_101 = (struct V_100 * ) F_63 ( V_55 , F_58 ( V_4 ) ) ;
V_55 -> V_4 = V_4 ;
V_55 -> V_104 = F_64 ( V_67 ) ;
if ( V_98 == NULL )
V_98 = V_4 -> V_46 ;
if ( V_97 == NULL )
V_97 = V_4 -> V_11 ;
if ( F_65 ( V_55 , V_4 , V_94 , V_97 , V_98 , V_55 -> V_105 ) < 0 )
goto V_106;
switch ( V_4 -> type ) {
default:
V_101 -> V_107 = F_64 ( V_4 -> type ) ;
V_101 -> V_108 = F_64 ( V_109 ) ;
break;
#if F_16 ( V_34 ) || F_16 ( V_35 )
case V_36 :
V_101 -> V_107 = F_64 ( V_36 ) ;
V_101 -> V_108 = F_64 ( V_110 ) ;
break;
#if F_16 ( V_37 ) || F_16 ( V_38 )
case V_39 :
V_101 -> V_107 = F_64 ( V_39 ) ;
V_101 -> V_108 = F_64 ( V_110 ) ;
break;
#endif
#endif
#if F_16 ( V_111 ) || F_16 ( V_112 )
case V_7 :
V_101 -> V_107 = F_64 ( V_6 ) ;
V_101 -> V_108 = F_64 ( V_109 ) ;
break;
#endif
#if F_16 ( V_113 ) || F_16 ( V_114 )
case V_9 :
V_101 -> V_107 = F_64 ( V_8 ) ;
V_101 -> V_108 = F_64 ( V_109 ) ;
break;
#endif
}
V_101 -> V_115 = V_4 -> V_13 ;
V_101 -> V_116 = 4 ;
V_101 -> V_117 = F_64 ( type ) ;
V_102 = ( unsigned char * ) ( V_101 + 1 ) ;
memcpy ( V_102 , V_98 , V_4 -> V_13 ) ;
V_102 += V_4 -> V_13 ;
memcpy ( V_102 , & V_96 , 4 ) ;
V_102 += 4 ;
if ( V_99 != NULL )
memcpy ( V_102 , V_99 , V_4 -> V_13 ) ;
else
memset ( V_102 , 0 , V_4 -> V_13 ) ;
V_102 += V_4 -> V_13 ;
memcpy ( V_102 , & V_95 , 4 ) ;
return V_55 ;
V_106:
F_19 ( V_55 ) ;
return NULL ;
}
void F_66 ( struct V_54 * V_55 )
{
F_67 ( V_118 , V_119 , V_55 , NULL , V_55 -> V_4 , V_120 ) ;
}
void F_30 ( int type , int V_94 , T_1 V_95 ,
struct V_3 * V_4 , T_1 V_96 ,
const unsigned char * V_97 , const unsigned char * V_98 ,
const unsigned char * V_99 )
{
struct V_54 * V_55 ;
if ( V_4 -> V_43 & V_44 )
return;
V_55 = F_56 ( type , V_94 , V_95 , V_4 , V_96 ,
V_97 , V_98 , V_99 ) ;
if ( V_55 == NULL )
return;
F_66 ( V_55 ) ;
}
static int F_68 ( struct V_54 * V_55 )
{
struct V_3 * V_4 = V_55 -> V_4 ;
struct V_21 * V_22 = F_10 ( V_4 ) ;
struct V_100 * V_101 ;
unsigned char * V_102 ;
struct V_72 * V_73 ;
unsigned char * V_121 ;
T_1 V_68 , V_69 ;
T_5 V_122 = V_4 -> type ;
int V_123 ;
struct V_18 * V_80 ;
struct V_75 * V_75 = F_13 ( V_4 ) ;
if ( V_22 == NULL )
goto V_106;
V_101 = F_69 ( V_55 ) ;
switch ( V_122 ) {
default:
if ( V_101 -> V_108 != F_64 ( V_109 ) ||
F_64 ( V_122 ) != V_101 -> V_107 )
goto V_106;
break;
case V_6 :
case V_9 :
case V_7 :
case V_8 :
if ( ( V_101 -> V_107 != F_64 ( V_6 ) &&
V_101 -> V_107 != F_64 ( V_8 ) ) ||
V_101 -> V_108 != F_64 ( V_109 ) )
goto V_106;
break;
case V_36 :
if ( V_101 -> V_108 != F_64 ( V_110 ) ||
V_101 -> V_107 != F_64 ( V_36 ) )
goto V_106;
break;
case V_39 :
if ( V_101 -> V_108 != F_64 ( V_110 ) ||
V_101 -> V_107 != F_64 ( V_39 ) )
goto V_106;
break;
}
if ( V_101 -> V_117 != F_64 ( V_124 ) &&
V_101 -> V_117 != F_64 ( V_66 ) )
goto V_106;
V_102 = ( unsigned char * ) ( V_101 + 1 ) ;
V_121 = V_102 ;
V_102 += V_4 -> V_13 ;
memcpy ( & V_68 , V_102 , 4 ) ;
V_102 += 4 ;
V_102 += V_4 -> V_13 ;
memcpy ( & V_69 , V_102 , 4 ) ;
if ( F_70 ( V_69 ) || F_71 ( V_69 ) )
goto V_106;
if ( V_122 == V_125 )
V_121 = V_4 -> V_11 ;
if ( V_68 == 0 ) {
if ( V_101 -> V_117 == F_64 ( V_66 ) &&
F_12 ( V_75 , V_69 ) == V_60 &&
! F_32 ( V_22 , V_68 , V_69 ) )
F_30 ( V_124 , V_67 , V_68 , V_4 , V_69 , V_121 ,
V_4 -> V_46 , V_121 ) ;
goto V_106;
}
if ( V_101 -> V_117 == F_64 ( V_66 ) &&
F_72 ( V_55 , V_69 , V_68 , 0 , V_4 ) == 0 ) {
V_73 = F_43 ( V_55 ) ;
V_123 = V_73 -> V_126 ;
if ( V_123 == V_60 ) {
int V_127 ;
V_127 = F_32 ( V_22 , V_68 , V_69 ) ;
if ( ! V_127 && F_73 ( V_22 ) )
V_127 = F_35 ( V_68 , V_69 , V_4 ) ;
if ( ! V_127 ) {
V_80 = F_74 ( & V_82 , V_121 , & V_68 , V_4 ) ;
if ( V_80 ) {
F_30 ( V_124 , V_67 , V_68 ,
V_4 , V_69 , V_121 , V_4 -> V_46 ,
V_121 ) ;
F_47 ( V_80 ) ;
}
}
goto V_106;
} else if ( F_75 ( V_22 ) ) {
if ( V_123 == V_128 &&
( F_51 ( V_22 , V_4 , V_73 ) ||
F_54 ( V_22 , V_4 , V_73 , V_68 , V_69 ) ||
F_76 ( & V_82 , V_75 , & V_69 , V_4 , 0 ) ) ) {
V_80 = F_74 ( & V_82 , V_121 , & V_68 , V_4 ) ;
if ( V_80 )
F_47 ( V_80 ) ;
if ( F_77 ( V_55 ) -> V_43 & V_129 ||
V_55 -> V_130 == V_131 ||
V_22 -> V_25 -> V_132 == 0 ) {
F_30 ( V_124 , V_67 , V_68 ,
V_4 , V_69 , V_121 , V_4 -> V_46 ,
V_121 ) ;
} else {
F_78 ( & V_82 ,
V_22 -> V_25 , V_55 ) ;
return 0 ;
}
goto V_106;
}
}
}
V_80 = F_44 ( & V_82 , & V_68 , V_4 , 0 ) ;
if ( F_79 ( F_13 ( V_4 ) , V_133 ) ) {
if ( V_80 == NULL &&
( V_101 -> V_117 == F_64 ( V_124 ) ||
( V_101 -> V_117 == F_64 ( V_66 ) && V_69 == V_68 ) ) &&
F_12 ( V_75 , V_68 ) == V_128 )
V_80 = F_44 ( & V_82 , & V_68 , V_4 , 1 ) ;
}
if ( V_80 ) {
int V_134 = V_135 ;
int V_136 ;
V_136 = F_80 ( V_84 , V_80 -> V_137 + V_80 -> V_24 -> V_138 ) ;
if ( V_101 -> V_117 != F_64 ( V_124 ) ||
V_55 -> V_130 != V_131 )
V_134 = V_139 ;
F_81 ( V_80 , V_121 , V_134 ,
V_136 ? V_140 : 0 ) ;
F_47 ( V_80 ) ;
}
V_106:
F_82 ( V_55 ) ;
return 0 ;
}
static void F_83 ( struct V_54 * V_55 )
{
F_68 ( V_55 ) ;
}
static int F_84 ( struct V_54 * V_55 , struct V_3 * V_4 ,
struct V_141 * V_142 , struct V_3 * V_143 )
{
struct V_100 * V_101 ;
if ( ! F_85 ( V_55 , F_58 ( V_4 ) ) )
goto V_144;
V_101 = F_69 ( V_55 ) ;
if ( V_101 -> V_115 != V_4 -> V_13 ||
V_4 -> V_43 & V_44 ||
V_55 -> V_130 == V_145 ||
V_55 -> V_130 == V_146 ||
V_101 -> V_116 != 4 )
goto V_144;
V_55 = F_86 ( V_55 , V_103 ) ;
if ( V_55 == NULL )
goto V_147;
memset ( F_77 ( V_55 ) , 0 , sizeof( struct V_148 ) ) ;
return F_67 ( V_118 , V_149 , V_55 , V_4 , NULL , F_68 ) ;
V_144:
F_19 ( V_55 ) ;
V_147:
return 0 ;
}
static int F_87 ( struct V_75 * V_75 , struct V_3 * V_4 , int V_150 )
{
if ( V_4 == NULL ) {
F_79 ( V_75 , V_151 ) = V_150 ;
return 0 ;
}
if ( F_88 ( V_4 ) ) {
F_89 ( F_88 ( V_4 ) , V_151 , V_150 ) ;
return 0 ;
}
return - V_152 ;
}
static int F_90 ( struct V_75 * V_75 , struct V_153 * V_154 ,
struct V_3 * V_4 )
{
T_1 V_155 = ( (struct V_156 * ) & V_154 -> V_157 ) -> V_158 . V_159 ;
T_1 V_160 = ( (struct V_156 * ) & V_154 -> V_161 ) -> V_158 . V_159 ;
if ( V_160 && V_160 != F_91 ( 0xFFFFFFFF ) )
return - V_14 ;
if ( ! V_4 && ( V_154 -> V_162 & V_163 ) ) {
V_4 = F_92 ( V_75 , V_154 -> V_164 . V_165 ,
V_154 -> V_164 . V_166 ) ;
if ( ! V_4 )
return - V_167 ;
}
if ( V_160 ) {
if ( F_76 ( & V_82 , V_75 , & V_155 , V_4 , 1 ) == NULL )
return - V_168 ;
return 0 ;
}
return F_87 ( V_75 , V_4 , 1 ) ;
}
static int F_93 ( struct V_75 * V_75 , struct V_153 * V_154 ,
struct V_3 * V_4 )
{
T_1 V_155 ;
struct V_18 * V_19 ;
int V_169 ;
if ( V_154 -> V_162 & V_170 )
return F_90 ( V_75 , V_154 , V_4 ) ;
V_155 = ( (struct V_156 * ) & V_154 -> V_157 ) -> V_158 . V_159 ;
if ( V_154 -> V_162 & V_171 )
V_154 -> V_162 |= V_163 ;
if ( V_4 == NULL ) {
struct V_72 * V_73 = F_36 ( V_75 , V_155 , 0 , V_172 , 0 ) ;
if ( F_37 ( V_73 ) )
return F_50 ( V_73 ) ;
V_4 = V_73 -> V_76 . V_4 ;
F_39 ( V_73 ) ;
if ( ! V_4 )
return - V_14 ;
}
switch ( V_4 -> type ) {
#if F_16 ( V_111 ) || F_16 ( V_112 )
case V_7 :
if ( V_154 -> V_164 . V_165 != V_7 &&
V_154 -> V_164 . V_165 != V_6 &&
V_154 -> V_164 . V_165 != V_8 )
return - V_14 ;
break;
#endif
default:
if ( V_154 -> V_164 . V_165 != V_4 -> type )
return - V_14 ;
break;
}
V_19 = F_49 ( & V_82 , & V_155 , V_4 ) ;
V_169 = F_50 ( V_19 ) ;
if ( ! F_37 ( V_19 ) ) {
unsigned V_134 = V_139 ;
if ( V_154 -> V_162 & V_171 )
V_134 = V_173 ;
V_169 = F_81 ( V_19 , ( V_154 -> V_162 & V_163 ) ?
V_154 -> V_164 . V_166 : NULL , V_134 ,
V_140 |
V_174 ) ;
F_47 ( V_19 ) ;
}
return V_169 ;
}
static unsigned F_94 ( struct V_18 * V_19 )
{
if ( V_19 -> V_27 & V_173 )
return V_171 | V_163 ;
else if ( V_19 -> V_27 & V_52 )
return V_163 ;
else
return 0 ;
}
static int F_95 ( struct V_153 * V_154 , struct V_3 * V_4 )
{
T_1 V_155 = ( (struct V_156 * ) & V_154 -> V_157 ) -> V_158 . V_159 ;
struct V_18 * V_19 ;
int V_169 = - V_152 ;
V_19 = F_96 ( & V_82 , & V_155 , V_4 ) ;
if ( V_19 ) {
F_27 ( & V_19 -> V_64 ) ;
memcpy ( V_154 -> V_164 . V_166 , V_19 -> V_42 , V_4 -> V_13 ) ;
V_154 -> V_162 = F_94 ( V_19 ) ;
F_31 ( & V_19 -> V_64 ) ;
V_154 -> V_164 . V_165 = V_4 -> type ;
F_97 ( V_154 -> V_175 , V_4 -> V_176 , sizeof( V_154 -> V_175 ) ) ;
F_47 ( V_19 ) ;
V_169 = 0 ;
}
return V_169 ;
}
int F_98 ( struct V_3 * V_4 , T_1 V_155 )
{
struct V_18 * V_19 = F_96 ( & V_82 , & V_155 , V_4 ) ;
int V_169 = - V_152 ;
if ( V_19 ) {
if ( V_19 -> V_27 & ~ V_28 )
V_169 = F_81 ( V_19 , NULL , V_177 ,
V_140 |
V_174 ) ;
F_47 ( V_19 ) ;
}
return V_169 ;
}
static int F_99 ( struct V_75 * V_75 , struct V_153 * V_154 ,
struct V_3 * V_4 )
{
T_1 V_155 = ( (struct V_156 * ) & V_154 -> V_157 ) -> V_158 . V_159 ;
T_1 V_160 = ( (struct V_156 * ) & V_154 -> V_161 ) -> V_158 . V_159 ;
if ( V_160 == F_91 ( 0xFFFFFFFF ) )
return F_100 ( & V_82 , V_75 , & V_155 , V_4 ) ;
if ( V_160 )
return - V_14 ;
return F_87 ( V_75 , V_4 , 0 ) ;
}
static int F_101 ( struct V_75 * V_75 , struct V_153 * V_154 ,
struct V_3 * V_4 )
{
T_1 V_155 ;
if ( V_154 -> V_162 & V_170 )
return F_99 ( V_75 , V_154 , V_4 ) ;
V_155 = ( (struct V_156 * ) & V_154 -> V_157 ) -> V_158 . V_159 ;
if ( V_4 == NULL ) {
struct V_72 * V_73 = F_36 ( V_75 , V_155 , 0 , V_172 , 0 ) ;
if ( F_37 ( V_73 ) )
return F_50 ( V_73 ) ;
V_4 = V_73 -> V_76 . V_4 ;
F_39 ( V_73 ) ;
if ( ! V_4 )
return - V_14 ;
}
return F_98 ( V_4 , V_155 ) ;
}
int F_102 ( struct V_75 * V_75 , unsigned int V_178 , void T_6 * V_179 )
{
int V_169 ;
struct V_153 V_154 ;
struct V_3 * V_4 = NULL ;
switch ( V_178 ) {
case V_180 :
case V_181 :
if ( ! F_103 ( V_182 ) )
return - V_183 ;
case V_184 :
V_169 = F_104 ( & V_154 , V_179 , sizeof( struct V_153 ) ) ;
if ( V_169 )
return - V_185 ;
break;
default:
return - V_14 ;
}
if ( V_154 . V_157 . V_165 != V_186 )
return - V_187 ;
if ( ! ( V_154 . V_162 & V_170 ) &&
( V_154 . V_162 & ( V_188 | V_189 ) ) )
return - V_14 ;
if ( ! ( V_154 . V_162 & V_188 ) )
( (struct V_156 * ) & V_154 . V_161 ) -> V_158 . V_159 =
F_91 ( 0xFFFFFFFFUL ) ;
F_105 () ;
if ( V_154 . V_175 [ 0 ] ) {
V_169 = - V_167 ;
V_4 = F_106 ( V_75 , V_154 . V_175 ) ;
if ( V_4 == NULL )
goto V_106;
if ( ! V_154 . V_164 . V_165 )
V_154 . V_164 . V_165 = V_4 -> type ;
V_169 = - V_14 ;
if ( ( V_154 . V_162 & V_163 ) && V_154 . V_164 . V_165 != V_4 -> type )
goto V_106;
} else if ( V_178 == V_184 ) {
V_169 = - V_167 ;
goto V_106;
}
switch ( V_178 ) {
case V_180 :
V_169 = F_101 ( V_75 , & V_154 , V_4 ) ;
break;
case V_181 :
V_169 = F_93 ( V_75 , & V_154 , V_4 ) ;
break;
case V_184 :
V_169 = F_95 ( & V_154 , V_4 ) ;
break;
}
V_106:
F_107 () ;
if ( V_178 == V_184 && ! V_169 && F_108 ( V_179 , & V_154 , sizeof( V_154 ) ) )
V_169 = - V_185 ;
return V_169 ;
}
static int F_109 ( struct V_190 * V_191 , unsigned long V_192 ,
void * V_193 )
{
struct V_3 * V_4 = V_193 ;
switch ( V_192 ) {
case V_194 :
F_110 ( & V_82 , V_4 ) ;
F_111 ( F_13 ( V_4 ) , 0 ) ;
break;
default:
break;
}
return V_195 ;
}
void F_112 ( struct V_3 * V_4 )
{
F_113 ( & V_82 , V_4 ) ;
}
void T_7 F_114 ( void )
{
F_115 ( & V_82 ) ;
F_116 ( & V_196 ) ;
F_117 () ;
#ifdef F_118
F_119 ( NULL , & V_82 . V_24 , L_4 , NULL ) ;
#endif
F_120 ( & V_197 ) ;
}
static char * F_121 ( T_8 * V_198 , char * V_199 )
{
char V_200 , * V_201 ;
int V_80 ;
for ( V_80 = 0 , V_201 = V_199 ; V_80 < 6 ; V_80 ++ ) {
V_200 = ( V_198 -> V_202 [ V_80 ] >> 1 ) & 0x7F ;
if ( V_200 != ' ' )
* V_201 ++ = V_200 ;
}
* V_201 ++ = '-' ;
V_80 = ( V_198 -> V_202 [ 6 ] >> 1 ) & 0x0F ;
if ( V_80 > 9 ) {
* V_201 ++ = '1' ;
V_80 -= 10 ;
}
* V_201 ++ = V_80 + '0' ;
* V_201 ++ = '\0' ;
if ( * V_199 == '\0' || * V_199 == '-' )
return L_5 ;
return V_199 ;
}
static void F_122 ( struct V_203 * V_204 ,
struct V_18 * V_80 )
{
char V_205 [ V_206 ] ;
int V_207 , V_208 ;
char V_209 [ 16 ] ;
struct V_3 * V_4 = V_80 -> V_4 ;
int V_210 = V_4 -> type ;
F_123 ( & V_80 -> V_64 ) ;
#if F_16 ( V_34 ) || F_16 ( V_35 )
if ( V_210 == V_36 || V_210 == V_39 )
F_121 ( ( T_8 * ) V_80 -> V_42 , V_205 ) ;
else {
#endif
for ( V_207 = 0 , V_208 = 0 ; V_207 < V_206 - 3 && V_208 < V_4 -> V_13 ; V_208 ++ ) {
V_205 [ V_207 ++ ] = F_124 ( V_80 -> V_42 [ V_208 ] ) ;
V_205 [ V_207 ++ ] = F_125 ( V_80 -> V_42 [ V_208 ] ) ;
V_205 [ V_207 ++ ] = ':' ;
}
if ( V_207 != 0 )
-- V_207 ;
V_205 [ V_207 ] = 0 ;
#if F_16 ( V_34 ) || F_16 ( V_35 )
}
#endif
sprintf ( V_209 , L_6 , V_80 -> V_20 ) ;
F_126 ( V_204 , L_7 ,
V_209 , V_210 , F_94 ( V_80 ) , V_205 , V_4 -> V_176 ) ;
F_127 ( & V_80 -> V_64 ) ;
}
static void F_128 ( struct V_203 * V_204 ,
struct V_211 * V_80 )
{
struct V_3 * V_4 = V_80 -> V_4 ;
int V_210 = V_4 ? V_4 -> type : 0 ;
char V_209 [ 16 ] ;
sprintf ( V_209 , L_6 , V_80 -> V_212 ) ;
F_126 ( V_204 , L_7 ,
V_209 , V_210 , V_170 | V_171 , L_8 ,
V_4 ? V_4 -> V_176 : L_5 ) ;
}
static int F_129 ( struct V_203 * V_204 , void * V_213 )
{
if ( V_213 == V_214 ) {
F_130 ( V_204 , L_9
L_10 ) ;
} else {
struct V_215 * V_134 = V_204 -> V_216 ;
if ( V_134 -> V_43 & V_217 )
F_128 ( V_204 , V_213 ) ;
else
F_122 ( V_204 , V_213 ) ;
}
return 0 ;
}
static void * F_131 ( struct V_203 * V_204 , T_9 * V_218 )
{
return F_132 ( V_204 , V_218 , & V_82 , V_219 ) ;
}
static int F_133 ( struct V_220 * V_220 , struct V_221 * V_221 )
{
return F_134 ( V_220 , V_221 , & V_222 ,
sizeof( struct V_215 ) ) ;
}
static int T_10 F_135 ( struct V_75 * V_75 )
{
if ( ! F_136 ( V_75 , L_11 , V_223 , & V_224 ) )
return - V_225 ;
return 0 ;
}
static void T_11 F_137 ( struct V_75 * V_75 )
{
F_138 ( V_75 , L_11 ) ;
}
static int T_7 F_117 ( void )
{
return F_139 ( & V_226 ) ;
}
static int T_7 F_117 ( void )
{
return 0 ;
}
