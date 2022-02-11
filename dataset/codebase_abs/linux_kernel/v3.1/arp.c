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
return F_7 ( * ( T_3 * ) V_15 , V_4 , V_16 ) ;
}
static int F_8 ( struct V_17 * V_18 )
{
T_1 V_1 = * ( T_1 * ) V_18 -> V_19 ;
struct V_3 * V_4 = V_18 -> V_4 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
F_9 () ;
V_21 = F_10 ( V_4 ) ;
if ( V_21 == NULL ) {
F_11 () ;
return - V_14 ;
}
V_18 -> type = F_12 ( F_13 ( V_4 ) , V_1 ) ;
V_23 = V_21 -> V_24 ;
F_14 ( V_18 -> V_23 ) ;
V_18 -> V_23 = F_15 ( V_23 ) ;
F_11 () ;
if ( ! V_4 -> V_25 ) {
V_18 -> V_26 = V_27 ;
V_18 -> V_28 = & V_29 ;
V_18 -> V_30 = V_31 ;
} else {
#if 1
switch ( V_4 -> type ) {
default:
break;
case V_32 :
#if F_16 ( V_33 ) || F_16 ( V_34 )
case V_35 :
#if F_16 ( V_36 ) || F_16 ( V_37 )
case V_38 :
#endif
V_18 -> V_28 = & V_39 ;
V_18 -> V_30 = V_18 -> V_28 -> V_30 ;
return 0 ;
#else
break;
#endif
}
#endif
if ( V_18 -> type == V_40 ) {
V_18 -> V_26 = V_27 ;
F_1 ( V_1 , V_18 -> V_41 , V_4 , 1 ) ;
} else if ( V_4 -> V_42 & ( V_43 | V_44 ) ) {
V_18 -> V_26 = V_27 ;
memcpy ( V_18 -> V_41 , V_4 -> V_45 , V_4 -> V_13 ) ;
} else if ( V_18 -> type == V_46 ||
( V_4 -> V_42 & V_47 ) ) {
V_18 -> V_26 = V_27 ;
memcpy ( V_18 -> V_41 , V_4 -> V_11 , V_4 -> V_13 ) ;
}
if ( V_4 -> V_25 -> V_48 )
V_18 -> V_28 = & V_49 ;
else
V_18 -> V_28 = & V_50 ;
if ( V_18 -> V_26 & V_51 )
V_18 -> V_30 = V_18 -> V_28 -> V_52 ;
else
V_18 -> V_30 = V_18 -> V_28 -> V_30 ;
}
return 0 ;
}
static void F_17 ( struct V_17 * V_18 , struct V_53 * V_54 )
{
F_18 ( V_54 ) ;
F_19 ( V_54 ) ;
}
static void F_20 ( struct V_17 * V_18 , struct V_53 * V_54 )
{
T_1 V_55 = 0 ;
T_2 * V_56 = NULL ;
struct V_3 * V_4 = V_18 -> V_4 ;
T_1 V_57 = * ( T_1 * ) V_18 -> V_19 ;
int V_58 = F_21 ( & V_18 -> V_58 ) ;
struct V_20 * V_21 ;
F_9 () ;
V_21 = F_10 ( V_4 ) ;
if ( ! V_21 ) {
F_11 () ;
return;
}
switch ( F_22 ( V_21 ) ) {
default:
case 0 :
if ( V_54 && F_12 ( F_13 ( V_4 ) ,
F_23 ( V_54 ) -> V_55 ) == V_59 )
V_55 = F_23 ( V_54 ) -> V_55 ;
break;
case 1 :
if ( ! V_54 )
break;
V_55 = F_23 ( V_54 ) -> V_55 ;
if ( F_12 ( F_13 ( V_4 ) , V_55 ) == V_59 ) {
if ( F_24 ( V_21 , V_57 , V_55 ) )
break;
}
V_55 = 0 ;
break;
case 2 :
break;
}
F_11 () ;
if ( ! V_55 )
V_55 = F_25 ( V_4 , V_57 , V_60 ) ;
V_58 -= V_18 -> V_23 -> V_61 ;
if ( V_58 < 0 ) {
if ( ! ( V_18 -> V_26 & V_51 ) )
F_26 ( V_62
L_1 ) ;
V_56 = V_18 -> V_41 ;
F_27 ( & V_18 -> V_63 ) ;
} else {
V_58 -= V_18 -> V_23 -> V_64 ;
if ( V_58 < 0 ) {
#ifdef F_28
F_29 ( V_18 ) ;
#endif
return;
}
}
F_30 ( V_65 , V_66 , V_57 , V_4 , V_55 ,
V_56 , V_4 -> V_45 , NULL ) ;
if ( V_56 )
F_31 ( & V_18 -> V_63 ) ;
}
static int F_32 ( struct V_20 * V_21 , T_1 V_67 , T_1 V_68 )
{
int V_69 ;
switch ( F_33 ( V_21 ) ) {
case 0 :
return 0 ;
case 1 :
V_67 = 0 ;
V_69 = V_70 ;
break;
case 2 :
V_69 = V_70 ;
break;
case 3 :
V_67 = 0 ;
V_69 = V_60 ;
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
return ! F_34 ( V_21 , V_67 , V_68 , V_69 ) ;
}
static int F_35 ( T_1 V_67 , T_1 V_68 , struct V_3 * V_4 )
{
struct V_71 * V_72 ;
int V_73 = 0 ;
struct V_74 * V_74 = F_13 ( V_4 ) ;
V_72 = F_36 ( V_74 , V_67 , V_68 , 0 , 0 ) ;
if ( F_37 ( V_72 ) )
return 1 ;
if ( V_72 -> V_75 . V_4 != V_4 ) {
F_38 ( V_74 , V_76 ) ;
V_73 = 1 ;
}
F_39 ( V_72 ) ;
return V_73 ;
}
static int F_40 ( int V_77 , unsigned char * V_2 ,
T_1 V_78 , struct V_3 * V_4 )
{
switch ( V_77 ) {
case V_59 :
F_26 ( V_62 L_2 ) ;
memcpy ( V_2 , V_4 -> V_45 , V_4 -> V_13 ) ;
return 1 ;
case V_40 :
F_1 ( V_78 , V_2 , V_4 , 1 ) ;
return 1 ;
case V_46 :
memcpy ( V_2 , V_4 -> V_11 , V_4 -> V_13 ) ;
return 1 ;
}
return 0 ;
}
int F_41 ( unsigned char * V_2 , struct V_53 * V_54 )
{
struct V_3 * V_4 = V_54 -> V_4 ;
T_1 V_78 ;
struct V_17 * V_79 ;
if ( ! F_42 ( V_54 ) ) {
F_26 ( V_62 L_3 ) ;
F_19 ( V_54 ) ;
return 1 ;
}
V_78 = F_43 ( V_54 ) -> V_80 ;
if ( F_40 ( F_12 ( F_13 ( V_4 ) , V_78 ) , V_2 ,
V_78 , V_4 ) )
return 0 ;
V_79 = F_44 ( & V_81 , & V_78 , V_4 , 1 ) ;
if ( V_79 ) {
V_79 -> V_82 = V_83 ;
if ( V_79 -> V_26 & V_51 || F_45 ( V_79 , V_54 ) == 0 ) {
F_46 ( V_2 , V_79 , V_4 ) ;
F_47 ( V_79 ) ;
return 0 ;
}
F_47 ( V_79 ) ;
} else
F_19 ( V_54 ) ;
return 1 ;
}
static inline int F_48 ( struct V_20 * V_21 ,
struct V_3 * V_4 , struct V_71 * V_72 )
{
struct V_20 * V_84 ;
int V_85 , V_86 = - 1 ;
if ( V_72 -> V_75 . V_4 == V_4 )
return 0 ;
if ( ! F_49 ( V_21 ) )
return 0 ;
V_85 = F_50 ( V_21 ) ;
if ( V_85 == 0 )
return 1 ;
if ( V_85 == - 1 )
return 0 ;
V_84 = F_10 ( V_72 -> V_75 . V_4 ) ;
if ( V_84 )
V_86 = F_50 ( V_84 ) ;
return V_86 != V_85 && V_86 != - 1 ;
}
static inline int F_51 ( struct V_20 * V_21 ,
struct V_3 * V_4 , struct V_71 * V_72 ,
T_1 V_67 , T_1 V_68 )
{
if ( V_72 -> V_75 . V_4 != V_4 )
return 0 ;
if ( V_67 == V_68 )
return 0 ;
if ( F_52 ( V_21 ) )
return 1 ;
else
return 0 ;
}
struct V_53 * F_53 ( int type , int V_87 , T_1 V_88 ,
struct V_3 * V_4 , T_1 V_89 ,
const unsigned char * V_90 ,
const unsigned char * V_91 ,
const unsigned char * V_92 )
{
struct V_53 * V_54 ;
struct V_93 * V_94 ;
unsigned char * V_95 ;
V_54 = F_54 ( F_55 ( V_4 ) + F_56 ( V_4 ) , V_96 ) ;
if ( V_54 == NULL )
return NULL ;
F_57 ( V_54 , F_58 ( V_4 ) ) ;
F_59 ( V_54 ) ;
V_94 = (struct V_93 * ) F_60 ( V_54 , F_55 ( V_4 ) ) ;
V_54 -> V_4 = V_4 ;
V_54 -> V_97 = F_61 ( V_66 ) ;
if ( V_91 == NULL )
V_91 = V_4 -> V_45 ;
if ( V_90 == NULL )
V_90 = V_4 -> V_11 ;
if ( F_62 ( V_54 , V_4 , V_87 , V_90 , V_91 , V_54 -> V_98 ) < 0 )
goto V_99;
switch ( V_4 -> type ) {
default:
V_94 -> V_100 = F_61 ( V_4 -> type ) ;
V_94 -> V_101 = F_61 ( V_102 ) ;
break;
#if F_16 ( V_33 ) || F_16 ( V_34 )
case V_35 :
V_94 -> V_100 = F_61 ( V_35 ) ;
V_94 -> V_101 = F_61 ( V_103 ) ;
break;
#if F_16 ( V_36 ) || F_16 ( V_37 )
case V_38 :
V_94 -> V_100 = F_61 ( V_38 ) ;
V_94 -> V_101 = F_61 ( V_103 ) ;
break;
#endif
#endif
#if F_16 ( V_104 ) || F_16 ( V_105 )
case V_7 :
V_94 -> V_100 = F_61 ( V_6 ) ;
V_94 -> V_101 = F_61 ( V_102 ) ;
break;
#endif
#if F_16 ( V_106 ) || F_16 ( V_107 )
case V_9 :
V_94 -> V_100 = F_61 ( V_8 ) ;
V_94 -> V_101 = F_61 ( V_102 ) ;
break;
#endif
}
V_94 -> V_108 = V_4 -> V_13 ;
V_94 -> V_109 = 4 ;
V_94 -> V_110 = F_61 ( type ) ;
V_95 = ( unsigned char * ) ( V_94 + 1 ) ;
memcpy ( V_95 , V_91 , V_4 -> V_13 ) ;
V_95 += V_4 -> V_13 ;
memcpy ( V_95 , & V_89 , 4 ) ;
V_95 += 4 ;
if ( V_92 != NULL )
memcpy ( V_95 , V_92 , V_4 -> V_13 ) ;
else
memset ( V_95 , 0 , V_4 -> V_13 ) ;
V_95 += V_4 -> V_13 ;
memcpy ( V_95 , & V_88 , 4 ) ;
return V_54 ;
V_99:
F_19 ( V_54 ) ;
return NULL ;
}
void F_63 ( struct V_53 * V_54 )
{
F_64 ( V_111 , V_112 , V_54 , NULL , V_54 -> V_4 , V_113 ) ;
}
void F_30 ( int type , int V_87 , T_1 V_88 ,
struct V_3 * V_4 , T_1 V_89 ,
const unsigned char * V_90 , const unsigned char * V_91 ,
const unsigned char * V_92 )
{
struct V_53 * V_54 ;
if ( V_4 -> V_42 & V_43 )
return;
V_54 = F_53 ( type , V_87 , V_88 , V_4 , V_89 ,
V_90 , V_91 , V_92 ) ;
if ( V_54 == NULL )
return;
F_63 ( V_54 ) ;
}
static int F_65 ( struct V_53 * V_54 )
{
struct V_3 * V_4 = V_54 -> V_4 ;
struct V_20 * V_21 = F_10 ( V_4 ) ;
struct V_93 * V_94 ;
unsigned char * V_95 ;
struct V_71 * V_72 ;
unsigned char * V_114 ;
T_1 V_67 , V_68 ;
T_5 V_115 = V_4 -> type ;
int V_116 ;
struct V_17 * V_79 ;
struct V_74 * V_74 = F_13 ( V_4 ) ;
if ( V_21 == NULL )
goto V_99;
V_94 = F_66 ( V_54 ) ;
switch ( V_115 ) {
default:
if ( V_94 -> V_101 != F_61 ( V_102 ) ||
F_61 ( V_115 ) != V_94 -> V_100 )
goto V_99;
break;
case V_6 :
case V_9 :
case V_7 :
case V_8 :
if ( ( V_94 -> V_100 != F_61 ( V_6 ) &&
V_94 -> V_100 != F_61 ( V_8 ) ) ||
V_94 -> V_101 != F_61 ( V_102 ) )
goto V_99;
break;
case V_35 :
if ( V_94 -> V_101 != F_61 ( V_103 ) ||
V_94 -> V_100 != F_61 ( V_35 ) )
goto V_99;
break;
case V_38 :
if ( V_94 -> V_101 != F_61 ( V_103 ) ||
V_94 -> V_100 != F_61 ( V_38 ) )
goto V_99;
break;
}
if ( V_94 -> V_110 != F_61 ( V_117 ) &&
V_94 -> V_110 != F_61 ( V_65 ) )
goto V_99;
V_95 = ( unsigned char * ) ( V_94 + 1 ) ;
V_114 = V_95 ;
V_95 += V_4 -> V_13 ;
memcpy ( & V_67 , V_95 , 4 ) ;
V_95 += 4 ;
V_95 += V_4 -> V_13 ;
memcpy ( & V_68 , V_95 , 4 ) ;
if ( F_67 ( V_68 ) || F_68 ( V_68 ) )
goto V_99;
if ( V_115 == V_118 )
V_114 = V_4 -> V_11 ;
if ( V_67 == 0 ) {
if ( V_94 -> V_110 == F_61 ( V_65 ) &&
F_12 ( V_74 , V_68 ) == V_59 &&
! F_32 ( V_21 , V_67 , V_68 ) )
F_30 ( V_117 , V_66 , V_67 , V_4 , V_68 , V_114 ,
V_4 -> V_45 , V_114 ) ;
goto V_99;
}
if ( V_94 -> V_110 == F_61 ( V_65 ) &&
F_69 ( V_54 , V_68 , V_67 , 0 , V_4 ) == 0 ) {
V_72 = F_43 ( V_54 ) ;
V_116 = V_72 -> V_119 ;
if ( V_116 == V_59 ) {
int V_120 ;
V_120 = F_32 ( V_21 , V_67 , V_68 ) ;
if ( ! V_120 && F_70 ( V_21 ) )
V_120 = F_35 ( V_67 , V_68 , V_4 ) ;
if ( ! V_120 ) {
V_79 = F_71 ( & V_81 , V_114 , & V_67 , V_4 ) ;
if ( V_79 ) {
F_30 ( V_117 , V_66 , V_67 ,
V_4 , V_68 , V_114 , V_4 -> V_45 ,
V_114 ) ;
F_47 ( V_79 ) ;
}
}
goto V_99;
} else if ( F_72 ( V_21 ) ) {
if ( V_116 == V_121 &&
( F_48 ( V_21 , V_4 , V_72 ) ||
F_51 ( V_21 , V_4 , V_72 , V_67 , V_68 ) ||
F_73 ( & V_81 , V_74 , & V_68 , V_4 , 0 ) ) ) {
V_79 = F_71 ( & V_81 , V_114 , & V_67 , V_4 ) ;
if ( V_79 )
F_47 ( V_79 ) ;
if ( F_74 ( V_54 ) -> V_42 & V_122 ||
V_54 -> V_123 == V_124 ||
V_21 -> V_24 -> V_125 == 0 ) {
F_30 ( V_117 , V_66 , V_67 ,
V_4 , V_68 , V_114 , V_4 -> V_45 ,
V_114 ) ;
} else {
F_75 ( & V_81 ,
V_21 -> V_24 , V_54 ) ;
return 0 ;
}
goto V_99;
}
}
}
V_79 = F_44 ( & V_81 , & V_67 , V_4 , 0 ) ;
if ( F_76 ( F_13 ( V_4 ) , V_126 ) ) {
if ( V_79 == NULL &&
( V_94 -> V_110 == F_61 ( V_117 ) ||
( V_94 -> V_110 == F_61 ( V_65 ) && V_68 == V_67 ) ) &&
F_12 ( V_74 , V_67 ) == V_121 )
V_79 = F_44 ( & V_81 , & V_67 , V_4 , 1 ) ;
}
if ( V_79 ) {
int V_127 = V_128 ;
int V_129 ;
V_129 = F_77 ( V_83 , V_79 -> V_130 + V_79 -> V_23 -> V_131 ) ;
if ( V_94 -> V_110 != F_61 ( V_117 ) ||
V_54 -> V_123 != V_124 )
V_127 = V_132 ;
F_78 ( V_79 , V_114 , V_127 ,
V_129 ? V_133 : 0 ) ;
F_47 ( V_79 ) ;
}
V_99:
F_79 ( V_54 ) ;
return 0 ;
}
static void F_80 ( struct V_53 * V_54 )
{
F_65 ( V_54 ) ;
}
static int F_81 ( struct V_53 * V_54 , struct V_3 * V_4 ,
struct V_134 * V_135 , struct V_3 * V_136 )
{
struct V_93 * V_94 ;
if ( ! F_82 ( V_54 , F_55 ( V_4 ) ) )
goto V_137;
V_94 = F_66 ( V_54 ) ;
if ( V_94 -> V_108 != V_4 -> V_13 ||
V_4 -> V_42 & V_43 ||
V_54 -> V_123 == V_138 ||
V_54 -> V_123 == V_139 ||
V_94 -> V_109 != 4 )
goto V_137;
V_54 = F_83 ( V_54 , V_96 ) ;
if ( V_54 == NULL )
goto V_140;
memset ( F_74 ( V_54 ) , 0 , sizeof( struct V_141 ) ) ;
return F_64 ( V_111 , V_142 , V_54 , V_4 , NULL , F_65 ) ;
V_137:
F_19 ( V_54 ) ;
V_140:
return 0 ;
}
static int F_84 ( struct V_74 * V_74 , struct V_3 * V_4 , int V_143 )
{
if ( V_4 == NULL ) {
F_76 ( V_74 , V_144 ) = V_143 ;
return 0 ;
}
if ( F_85 ( V_4 ) ) {
F_86 ( F_85 ( V_4 ) , V_144 , V_143 ) ;
return 0 ;
}
return - V_145 ;
}
static int F_87 ( struct V_74 * V_74 , struct V_146 * V_147 ,
struct V_3 * V_4 )
{
T_1 V_148 = ( (struct V_149 * ) & V_147 -> V_150 ) -> V_151 . V_152 ;
T_1 V_153 = ( (struct V_149 * ) & V_147 -> V_154 ) -> V_151 . V_152 ;
if ( V_153 && V_153 != F_88 ( 0xFFFFFFFF ) )
return - V_14 ;
if ( ! V_4 && ( V_147 -> V_155 & V_156 ) ) {
V_4 = F_89 ( V_74 , V_147 -> V_157 . V_158 ,
V_147 -> V_157 . V_159 ) ;
if ( ! V_4 )
return - V_160 ;
}
if ( V_153 ) {
if ( F_73 ( & V_81 , V_74 , & V_148 , V_4 , 1 ) == NULL )
return - V_161 ;
return 0 ;
}
return F_84 ( V_74 , V_4 , 1 ) ;
}
static int F_90 ( struct V_74 * V_74 , struct V_146 * V_147 ,
struct V_3 * V_4 )
{
T_1 V_148 ;
struct V_17 * V_18 ;
int V_162 ;
if ( V_147 -> V_155 & V_163 )
return F_87 ( V_74 , V_147 , V_4 ) ;
V_148 = ( (struct V_149 * ) & V_147 -> V_150 ) -> V_151 . V_152 ;
if ( V_147 -> V_155 & V_164 )
V_147 -> V_155 |= V_156 ;
if ( V_4 == NULL ) {
struct V_71 * V_72 = F_36 ( V_74 , V_148 , 0 , V_165 , 0 ) ;
if ( F_37 ( V_72 ) )
return F_91 ( V_72 ) ;
V_4 = V_72 -> V_75 . V_4 ;
F_39 ( V_72 ) ;
if ( ! V_4 )
return - V_14 ;
}
switch ( V_4 -> type ) {
#if F_16 ( V_104 ) || F_16 ( V_105 )
case V_7 :
if ( V_147 -> V_157 . V_158 != V_7 &&
V_147 -> V_157 . V_158 != V_6 &&
V_147 -> V_157 . V_158 != V_8 )
return - V_14 ;
break;
#endif
default:
if ( V_147 -> V_157 . V_158 != V_4 -> type )
return - V_14 ;
break;
}
V_18 = F_92 ( & V_81 , & V_148 , V_4 ) ;
V_162 = F_91 ( V_18 ) ;
if ( ! F_37 ( V_18 ) ) {
unsigned V_127 = V_132 ;
if ( V_147 -> V_155 & V_164 )
V_127 = V_166 ;
V_162 = F_78 ( V_18 , ( V_147 -> V_155 & V_156 ) ?
V_147 -> V_157 . V_159 : NULL , V_127 ,
V_133 |
V_167 ) ;
F_47 ( V_18 ) ;
}
return V_162 ;
}
static unsigned F_93 ( struct V_17 * V_18 )
{
if ( V_18 -> V_26 & V_166 )
return V_164 | V_156 ;
else if ( V_18 -> V_26 & V_51 )
return V_156 ;
else
return 0 ;
}
static int F_94 ( struct V_146 * V_147 , struct V_3 * V_4 )
{
T_1 V_148 = ( (struct V_149 * ) & V_147 -> V_150 ) -> V_151 . V_152 ;
struct V_17 * V_18 ;
int V_162 = - V_145 ;
V_18 = F_95 ( & V_81 , & V_148 , V_4 ) ;
if ( V_18 ) {
F_27 ( & V_18 -> V_63 ) ;
memcpy ( V_147 -> V_157 . V_159 , V_18 -> V_41 , V_4 -> V_13 ) ;
V_147 -> V_155 = F_93 ( V_18 ) ;
F_31 ( & V_18 -> V_63 ) ;
V_147 -> V_157 . V_158 = V_4 -> type ;
F_96 ( V_147 -> V_168 , V_4 -> V_169 , sizeof( V_147 -> V_168 ) ) ;
F_47 ( V_18 ) ;
V_162 = 0 ;
}
return V_162 ;
}
int F_97 ( struct V_3 * V_4 , T_1 V_148 )
{
struct V_17 * V_18 = F_95 ( & V_81 , & V_148 , V_4 ) ;
int V_162 = - V_145 ;
if ( V_18 ) {
if ( V_18 -> V_26 & ~ V_27 )
V_162 = F_78 ( V_18 , NULL , V_170 ,
V_133 |
V_167 ) ;
F_47 ( V_18 ) ;
}
return V_162 ;
}
static int F_98 ( struct V_74 * V_74 , struct V_146 * V_147 ,
struct V_3 * V_4 )
{
T_1 V_148 = ( (struct V_149 * ) & V_147 -> V_150 ) -> V_151 . V_152 ;
T_1 V_153 = ( (struct V_149 * ) & V_147 -> V_154 ) -> V_151 . V_152 ;
if ( V_153 == F_88 ( 0xFFFFFFFF ) )
return F_99 ( & V_81 , V_74 , & V_148 , V_4 ) ;
if ( V_153 )
return - V_14 ;
return F_84 ( V_74 , V_4 , 0 ) ;
}
static int F_100 ( struct V_74 * V_74 , struct V_146 * V_147 ,
struct V_3 * V_4 )
{
T_1 V_148 ;
if ( V_147 -> V_155 & V_163 )
return F_98 ( V_74 , V_147 , V_4 ) ;
V_148 = ( (struct V_149 * ) & V_147 -> V_150 ) -> V_151 . V_152 ;
if ( V_4 == NULL ) {
struct V_71 * V_72 = F_36 ( V_74 , V_148 , 0 , V_165 , 0 ) ;
if ( F_37 ( V_72 ) )
return F_91 ( V_72 ) ;
V_4 = V_72 -> V_75 . V_4 ;
F_39 ( V_72 ) ;
if ( ! V_4 )
return - V_14 ;
}
return F_97 ( V_4 , V_148 ) ;
}
int F_101 ( struct V_74 * V_74 , unsigned int V_171 , void T_6 * V_172 )
{
int V_162 ;
struct V_146 V_147 ;
struct V_3 * V_4 = NULL ;
switch ( V_171 ) {
case V_173 :
case V_174 :
if ( ! F_102 ( V_175 ) )
return - V_176 ;
case V_177 :
V_162 = F_103 ( & V_147 , V_172 , sizeof( struct V_146 ) ) ;
if ( V_162 )
return - V_178 ;
break;
default:
return - V_14 ;
}
if ( V_147 . V_150 . V_158 != V_179 )
return - V_180 ;
if ( ! ( V_147 . V_155 & V_163 ) &&
( V_147 . V_155 & ( V_181 | V_182 ) ) )
return - V_14 ;
if ( ! ( V_147 . V_155 & V_181 ) )
( (struct V_149 * ) & V_147 . V_154 ) -> V_151 . V_152 =
F_88 ( 0xFFFFFFFFUL ) ;
F_104 () ;
if ( V_147 . V_168 [ 0 ] ) {
V_162 = - V_160 ;
V_4 = F_105 ( V_74 , V_147 . V_168 ) ;
if ( V_4 == NULL )
goto V_99;
if ( ! V_147 . V_157 . V_158 )
V_147 . V_157 . V_158 = V_4 -> type ;
V_162 = - V_14 ;
if ( ( V_147 . V_155 & V_156 ) && V_147 . V_157 . V_158 != V_4 -> type )
goto V_99;
} else if ( V_171 == V_177 ) {
V_162 = - V_160 ;
goto V_99;
}
switch ( V_171 ) {
case V_173 :
V_162 = F_100 ( V_74 , & V_147 , V_4 ) ;
break;
case V_174 :
V_162 = F_90 ( V_74 , & V_147 , V_4 ) ;
break;
case V_177 :
V_162 = F_94 ( & V_147 , V_4 ) ;
break;
}
V_99:
F_106 () ;
if ( V_171 == V_177 && ! V_162 && F_107 ( V_172 , & V_147 , sizeof( V_147 ) ) )
V_162 = - V_178 ;
return V_162 ;
}
static int F_108 ( struct V_183 * V_184 , unsigned long V_185 ,
void * V_186 )
{
struct V_3 * V_4 = V_186 ;
switch ( V_185 ) {
case V_187 :
F_109 ( & V_81 , V_4 ) ;
F_110 ( F_13 ( V_4 ) , 0 ) ;
break;
default:
break;
}
return V_188 ;
}
void F_111 ( struct V_3 * V_4 )
{
F_112 ( & V_81 , V_4 ) ;
}
void T_7 F_113 ( void )
{
F_114 ( & V_81 ) ;
F_115 ( & V_189 ) ;
F_116 () ;
#ifdef F_117
F_118 ( NULL , & V_81 . V_23 , L_4 , NULL ) ;
#endif
F_119 ( & V_190 ) ;
}
static char * F_120 ( T_8 * V_191 , char * V_192 )
{
char V_193 , * V_194 ;
int V_79 ;
for ( V_79 = 0 , V_194 = V_192 ; V_79 < 6 ; V_79 ++ ) {
V_193 = ( V_191 -> V_195 [ V_79 ] >> 1 ) & 0x7F ;
if ( V_193 != ' ' )
* V_194 ++ = V_193 ;
}
* V_194 ++ = '-' ;
V_79 = ( V_191 -> V_195 [ 6 ] >> 1 ) & 0x0F ;
if ( V_79 > 9 ) {
* V_194 ++ = '1' ;
V_79 -= 10 ;
}
* V_194 ++ = V_79 + '0' ;
* V_194 ++ = '\0' ;
if ( * V_192 == '\0' || * V_192 == '-' )
return L_5 ;
return V_192 ;
}
static void F_121 ( struct V_196 * V_197 ,
struct V_17 * V_79 )
{
char V_198 [ V_199 ] ;
int V_200 , V_201 ;
char V_202 [ 16 ] ;
struct V_3 * V_4 = V_79 -> V_4 ;
int V_203 = V_4 -> type ;
F_122 ( & V_79 -> V_63 ) ;
#if F_16 ( V_33 ) || F_16 ( V_34 )
if ( V_203 == V_35 || V_203 == V_38 )
F_120 ( ( T_8 * ) V_79 -> V_41 , V_198 ) ;
else {
#endif
for ( V_200 = 0 , V_201 = 0 ; V_200 < V_199 - 3 && V_201 < V_4 -> V_13 ; V_201 ++ ) {
V_198 [ V_200 ++ ] = F_123 ( V_79 -> V_41 [ V_201 ] ) ;
V_198 [ V_200 ++ ] = F_124 ( V_79 -> V_41 [ V_201 ] ) ;
V_198 [ V_200 ++ ] = ':' ;
}
if ( V_200 != 0 )
-- V_200 ;
V_198 [ V_200 ] = 0 ;
#if F_16 ( V_33 ) || F_16 ( V_34 )
}
#endif
sprintf ( V_202 , L_6 , V_79 -> V_19 ) ;
F_125 ( V_197 , L_7 ,
V_202 , V_203 , F_93 ( V_79 ) , V_198 , V_4 -> V_169 ) ;
F_126 ( & V_79 -> V_63 ) ;
}
static void F_127 ( struct V_196 * V_197 ,
struct V_204 * V_79 )
{
struct V_3 * V_4 = V_79 -> V_4 ;
int V_203 = V_4 ? V_4 -> type : 0 ;
char V_202 [ 16 ] ;
sprintf ( V_202 , L_6 , V_79 -> V_205 ) ;
F_125 ( V_197 , L_7 ,
V_202 , V_203 , V_163 | V_164 , L_8 ,
V_4 ? V_4 -> V_169 : L_5 ) ;
}
static int F_128 ( struct V_196 * V_197 , void * V_206 )
{
if ( V_206 == V_207 ) {
F_129 ( V_197 , L_9
L_10 ) ;
} else {
struct V_208 * V_127 = V_197 -> V_209 ;
if ( V_127 -> V_42 & V_210 )
F_127 ( V_197 , V_206 ) ;
else
F_121 ( V_197 , V_206 ) ;
}
return 0 ;
}
static void * F_130 ( struct V_196 * V_197 , T_9 * V_211 )
{
return F_131 ( V_197 , V_211 , & V_81 , V_212 ) ;
}
static int F_132 ( struct V_213 * V_213 , struct V_214 * V_214 )
{
return F_133 ( V_213 , V_214 , & V_215 ,
sizeof( struct V_208 ) ) ;
}
static int T_10 F_134 ( struct V_74 * V_74 )
{
if ( ! F_135 ( V_74 , L_11 , V_216 , & V_217 ) )
return - V_218 ;
return 0 ;
}
static void T_11 F_136 ( struct V_74 * V_74 )
{
F_137 ( V_74 , L_11 ) ;
}
static int T_7 F_116 ( void )
{
return F_138 ( & V_219 ) ;
}
static int T_7 F_116 ( void )
{
return 0 ;
}
