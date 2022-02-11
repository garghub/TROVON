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
return F_6 ( * ( T_3 * ) V_14 , V_4 , * V_15 ) ;
}
static int F_7 ( struct V_16 * V_17 )
{
T_1 V_1 = * ( T_1 * ) V_17 -> V_18 ;
struct V_3 * V_4 = V_17 -> V_4 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
F_8 () ;
V_20 = F_9 ( V_4 ) ;
if ( V_20 == NULL ) {
F_10 () ;
return - V_13 ;
}
V_17 -> type = F_11 ( F_12 ( V_4 ) , V_1 ) ;
V_22 = V_20 -> V_23 ;
F_13 ( V_17 -> V_22 ) ;
V_17 -> V_22 = F_14 ( V_22 ) ;
F_10 () ;
if ( ! V_4 -> V_24 ) {
V_17 -> V_25 = V_26 ;
V_17 -> V_27 = & V_28 ;
V_17 -> V_29 = V_30 ;
} else {
#if 1
switch ( V_4 -> type ) {
default:
break;
case V_31 :
#if F_15 ( V_32 )
case V_33 :
#if F_15 ( V_34 )
case V_35 :
#endif
V_17 -> V_27 = & V_36 ;
V_17 -> V_29 = V_17 -> V_27 -> V_29 ;
return 0 ;
#else
break;
#endif
}
#endif
if ( V_17 -> type == V_37 ) {
V_17 -> V_25 = V_26 ;
F_1 ( V_1 , V_17 -> V_38 , V_4 , 1 ) ;
} else if ( V_4 -> V_39 & ( V_40 | V_41 ) ) {
V_17 -> V_25 = V_26 ;
memcpy ( V_17 -> V_38 , V_4 -> V_42 , V_4 -> V_12 ) ;
} else if ( V_17 -> type == V_43 ||
( V_4 -> V_39 & V_44 ) ) {
V_17 -> V_25 = V_26 ;
memcpy ( V_17 -> V_38 , V_4 -> V_10 , V_4 -> V_12 ) ;
}
if ( V_4 -> V_24 -> V_45 )
V_17 -> V_27 = & V_46 ;
else
V_17 -> V_27 = & V_47 ;
if ( V_17 -> V_25 & V_48 )
V_17 -> V_29 = V_17 -> V_27 -> V_49 ;
else
V_17 -> V_29 = V_17 -> V_27 -> V_29 ;
}
return 0 ;
}
static void F_16 ( struct V_16 * V_17 , struct V_50 * V_51 )
{
F_17 ( V_51 ) ;
F_18 ( V_51 ) ;
}
static void F_19 ( struct V_16 * V_17 , struct V_50 * V_51 )
{
T_1 V_52 = 0 ;
T_2 V_53 [ V_54 ] , * V_55 = NULL ;
struct V_3 * V_4 = V_17 -> V_4 ;
T_1 V_56 = * ( T_1 * ) V_17 -> V_18 ;
int V_57 = F_20 ( & V_17 -> V_57 ) ;
struct V_19 * V_20 ;
F_8 () ;
V_20 = F_9 ( V_4 ) ;
if ( ! V_20 ) {
F_10 () ;
return;
}
switch ( F_21 ( V_20 ) ) {
default:
case 0 :
if ( V_51 && F_11 ( F_12 ( V_4 ) ,
F_22 ( V_51 ) -> V_52 ) == V_58 )
V_52 = F_22 ( V_51 ) -> V_52 ;
break;
case 1 :
if ( ! V_51 )
break;
V_52 = F_22 ( V_51 ) -> V_52 ;
if ( F_11 ( F_12 ( V_4 ) , V_52 ) == V_58 ) {
if ( F_23 ( V_20 , V_56 , V_52 ) )
break;
}
V_52 = 0 ;
break;
case 2 :
break;
}
F_10 () ;
if ( ! V_52 )
V_52 = F_24 ( V_4 , V_56 , V_59 ) ;
V_57 -= V_17 -> V_22 -> V_60 ;
if ( V_57 < 0 ) {
if ( ! ( V_17 -> V_25 & V_48 ) )
F_25 ( L_1 ) ;
F_26 ( V_53 , V_17 , V_4 ) ;
V_55 = V_53 ;
} else {
V_57 -= V_17 -> V_22 -> V_61 ;
if ( V_57 < 0 ) {
#ifdef F_27
F_28 ( V_17 ) ;
#endif
return;
}
}
F_29 ( V_62 , V_63 , V_56 , V_4 , V_52 ,
V_55 , V_4 -> V_42 , NULL ) ;
}
static int F_30 ( struct V_19 * V_20 , T_1 V_64 , T_1 V_65 )
{
int V_66 ;
switch ( F_31 ( V_20 ) ) {
case 0 :
return 0 ;
case 1 :
V_64 = 0 ;
V_66 = V_67 ;
break;
case 2 :
V_66 = V_67 ;
break;
case 3 :
V_64 = 0 ;
V_66 = V_59 ;
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
return ! F_32 ( V_20 , V_64 , V_65 , V_66 ) ;
}
static int F_33 ( T_1 V_64 , T_1 V_65 , struct V_3 * V_4 )
{
struct V_68 * V_69 ;
int V_70 = 0 ;
struct V_71 * V_71 = F_12 ( V_4 ) ;
V_69 = F_34 ( V_71 , V_64 , V_65 , 0 , 0 ) ;
if ( F_35 ( V_69 ) )
return 1 ;
if ( V_69 -> V_72 . V_4 != V_4 ) {
F_36 ( V_71 , V_73 ) ;
V_70 = 1 ;
}
F_37 ( V_69 ) ;
return V_70 ;
}
static int F_38 ( int V_74 , unsigned char * V_2 ,
T_1 V_75 , struct V_3 * V_4 )
{
switch ( V_74 ) {
case V_58 :
F_25 ( L_2 ) ;
memcpy ( V_2 , V_4 -> V_42 , V_4 -> V_12 ) ;
return 1 ;
case V_37 :
F_1 ( V_75 , V_2 , V_4 , 1 ) ;
return 1 ;
case V_43 :
memcpy ( V_2 , V_4 -> V_10 , V_4 -> V_12 ) ;
return 1 ;
}
return 0 ;
}
int F_39 ( unsigned char * V_2 , struct V_50 * V_51 )
{
struct V_3 * V_4 = V_51 -> V_4 ;
T_1 V_75 ;
struct V_16 * V_76 ;
if ( ! F_40 ( V_51 ) ) {
F_25 ( L_3 ) ;
F_18 ( V_51 ) ;
return 1 ;
}
V_75 = F_41 ( F_42 ( V_51 ) , F_22 ( V_51 ) -> V_77 ) ;
if ( F_38 ( F_11 ( F_12 ( V_4 ) , V_75 ) , V_2 ,
V_75 , V_4 ) )
return 0 ;
V_76 = F_43 ( & V_78 , & V_75 , V_4 , 1 ) ;
if ( V_76 ) {
V_76 -> V_79 = V_80 ;
if ( V_76 -> V_25 & V_48 || F_44 ( V_76 , V_51 ) == 0 ) {
F_26 ( V_2 , V_76 , V_4 ) ;
F_45 ( V_76 ) ;
return 0 ;
}
F_45 ( V_76 ) ;
} else
F_18 ( V_51 ) ;
return 1 ;
}
static inline int F_46 ( struct V_19 * V_20 ,
struct V_3 * V_4 , struct V_68 * V_69 )
{
struct V_19 * V_81 ;
int V_82 , V_83 = - 1 ;
if ( V_69 -> V_72 . V_4 == V_4 )
return 0 ;
if ( ! F_47 ( V_20 ) )
return 0 ;
V_82 = F_48 ( V_20 ) ;
if ( V_82 == 0 )
return 1 ;
if ( V_82 == - 1 )
return 0 ;
V_81 = F_9 ( V_69 -> V_72 . V_4 ) ;
if ( V_81 )
V_83 = F_48 ( V_81 ) ;
return V_83 != V_82 && V_83 != - 1 ;
}
static inline int F_49 ( struct V_19 * V_20 ,
struct V_3 * V_4 , struct V_68 * V_69 ,
T_1 V_64 , T_1 V_65 )
{
if ( V_69 -> V_72 . V_4 != V_4 )
return 0 ;
if ( V_64 == V_65 )
return 0 ;
if ( F_50 ( V_20 ) )
return 1 ;
else
return 0 ;
}
struct V_50 * F_51 ( int type , int V_84 , T_1 V_85 ,
struct V_3 * V_4 , T_1 V_86 ,
const unsigned char * V_87 ,
const unsigned char * V_88 ,
const unsigned char * V_89 )
{
struct V_50 * V_51 ;
struct V_90 * V_91 ;
unsigned char * V_92 ;
int V_93 = F_52 ( V_4 ) ;
int V_94 = V_4 -> V_95 ;
V_51 = F_53 ( F_54 ( V_4 ) + V_93 + V_94 , V_96 ) ;
if ( V_51 == NULL )
return NULL ;
F_55 ( V_51 , V_93 ) ;
F_56 ( V_51 ) ;
V_91 = (struct V_90 * ) F_57 ( V_51 , F_54 ( V_4 ) ) ;
V_51 -> V_4 = V_4 ;
V_51 -> V_97 = F_58 ( V_63 ) ;
if ( V_88 == NULL )
V_88 = V_4 -> V_42 ;
if ( V_87 == NULL )
V_87 = V_4 -> V_10 ;
if ( F_59 ( V_51 , V_4 , V_84 , V_87 , V_88 , V_51 -> V_98 ) < 0 )
goto V_99;
switch ( V_4 -> type ) {
default:
V_91 -> V_100 = F_58 ( V_4 -> type ) ;
V_91 -> V_101 = F_58 ( V_102 ) ;
break;
#if F_15 ( V_32 )
case V_33 :
V_91 -> V_100 = F_58 ( V_33 ) ;
V_91 -> V_101 = F_58 ( V_103 ) ;
break;
#if F_15 ( V_34 )
case V_35 :
V_91 -> V_100 = F_58 ( V_35 ) ;
V_91 -> V_101 = F_58 ( V_103 ) ;
break;
#endif
#endif
#if F_15 ( V_104 )
case V_7 :
V_91 -> V_100 = F_58 ( V_6 ) ;
V_91 -> V_101 = F_58 ( V_102 ) ;
break;
#endif
}
V_91 -> V_105 = V_4 -> V_12 ;
V_91 -> V_106 = 4 ;
V_91 -> V_107 = F_58 ( type ) ;
V_92 = ( unsigned char * ) ( V_91 + 1 ) ;
memcpy ( V_92 , V_88 , V_4 -> V_12 ) ;
V_92 += V_4 -> V_12 ;
memcpy ( V_92 , & V_86 , 4 ) ;
V_92 += 4 ;
if ( V_89 != NULL )
memcpy ( V_92 , V_89 , V_4 -> V_12 ) ;
else
memset ( V_92 , 0 , V_4 -> V_12 ) ;
V_92 += V_4 -> V_12 ;
memcpy ( V_92 , & V_85 , 4 ) ;
return V_51 ;
V_99:
F_18 ( V_51 ) ;
return NULL ;
}
void F_60 ( struct V_50 * V_51 )
{
F_61 ( V_108 , V_109 , V_51 , NULL , V_51 -> V_4 , V_110 ) ;
}
void F_29 ( int type , int V_84 , T_1 V_85 ,
struct V_3 * V_4 , T_1 V_86 ,
const unsigned char * V_87 , const unsigned char * V_88 ,
const unsigned char * V_89 )
{
struct V_50 * V_51 ;
if ( V_4 -> V_39 & V_40 )
return;
V_51 = F_51 ( type , V_84 , V_85 , V_4 , V_86 ,
V_87 , V_88 , V_89 ) ;
if ( V_51 == NULL )
return;
F_60 ( V_51 ) ;
}
static int F_62 ( struct V_50 * V_51 )
{
struct V_3 * V_4 = V_51 -> V_4 ;
struct V_19 * V_20 = F_9 ( V_4 ) ;
struct V_90 * V_91 ;
unsigned char * V_92 ;
struct V_68 * V_69 ;
unsigned char * V_111 ;
T_1 V_64 , V_65 ;
T_5 V_112 = V_4 -> type ;
int V_113 ;
struct V_16 * V_76 ;
struct V_71 * V_71 = F_12 ( V_4 ) ;
if ( V_20 == NULL )
goto V_99;
V_91 = F_63 ( V_51 ) ;
switch ( V_112 ) {
default:
if ( V_91 -> V_101 != F_58 ( V_102 ) ||
F_58 ( V_112 ) != V_91 -> V_100 )
goto V_99;
break;
case V_6 :
case V_7 :
case V_8 :
if ( ( V_91 -> V_100 != F_58 ( V_6 ) &&
V_91 -> V_100 != F_58 ( V_8 ) ) ||
V_91 -> V_101 != F_58 ( V_102 ) )
goto V_99;
break;
case V_33 :
if ( V_91 -> V_101 != F_58 ( V_103 ) ||
V_91 -> V_100 != F_58 ( V_33 ) )
goto V_99;
break;
case V_35 :
if ( V_91 -> V_101 != F_58 ( V_103 ) ||
V_91 -> V_100 != F_58 ( V_35 ) )
goto V_99;
break;
}
if ( V_91 -> V_107 != F_58 ( V_114 ) &&
V_91 -> V_107 != F_58 ( V_62 ) )
goto V_99;
V_92 = ( unsigned char * ) ( V_91 + 1 ) ;
V_111 = V_92 ;
V_92 += V_4 -> V_12 ;
memcpy ( & V_64 , V_92 , 4 ) ;
V_92 += 4 ;
V_92 += V_4 -> V_12 ;
memcpy ( & V_65 , V_92 , 4 ) ;
if ( F_64 ( V_65 ) ||
( ! F_65 ( V_20 ) && F_66 ( V_65 ) ) )
goto V_99;
if ( V_112 == V_115 )
V_111 = V_4 -> V_10 ;
if ( V_64 == 0 ) {
if ( V_91 -> V_107 == F_58 ( V_62 ) &&
F_11 ( V_71 , V_65 ) == V_58 &&
! F_30 ( V_20 , V_64 , V_65 ) )
F_29 ( V_114 , V_63 , V_64 , V_4 , V_65 , V_111 ,
V_4 -> V_42 , V_111 ) ;
goto V_99;
}
if ( V_91 -> V_107 == F_58 ( V_62 ) &&
F_67 ( V_51 , V_65 , V_64 , 0 , V_4 ) == 0 ) {
V_69 = F_42 ( V_51 ) ;
V_113 = V_69 -> V_116 ;
if ( V_113 == V_58 ) {
int V_117 ;
V_117 = F_30 ( V_20 , V_64 , V_65 ) ;
if ( ! V_117 && F_68 ( V_20 ) )
V_117 = F_33 ( V_64 , V_65 , V_4 ) ;
if ( ! V_117 ) {
V_76 = F_69 ( & V_78 , V_111 , & V_64 , V_4 ) ;
if ( V_76 ) {
F_29 ( V_114 , V_63 , V_64 ,
V_4 , V_65 , V_111 , V_4 -> V_42 ,
V_111 ) ;
F_45 ( V_76 ) ;
}
}
goto V_99;
} else if ( F_70 ( V_20 ) ) {
if ( V_113 == V_118 &&
( F_46 ( V_20 , V_4 , V_69 ) ||
F_49 ( V_20 , V_4 , V_69 , V_64 , V_65 ) ||
( V_69 -> V_72 . V_4 != V_4 &&
F_71 ( & V_78 , V_71 , & V_65 , V_4 , 0 ) ) ) ) {
V_76 = F_69 ( & V_78 , V_111 , & V_64 , V_4 ) ;
if ( V_76 )
F_45 ( V_76 ) ;
if ( F_72 ( V_51 ) -> V_39 & V_119 ||
V_51 -> V_120 == V_121 ||
V_20 -> V_23 -> V_122 == 0 ) {
F_29 ( V_114 , V_63 , V_64 ,
V_4 , V_65 , V_111 , V_4 -> V_42 ,
V_111 ) ;
} else {
F_73 ( & V_78 ,
V_20 -> V_23 , V_51 ) ;
return 0 ;
}
goto V_99;
}
}
}
V_76 = F_43 ( & V_78 , & V_64 , V_4 , 0 ) ;
if ( F_74 ( V_20 ) ) {
if ( V_76 == NULL &&
( V_91 -> V_107 == F_58 ( V_114 ) ||
( V_91 -> V_107 == F_58 ( V_62 ) && V_65 == V_64 ) ) &&
F_11 ( V_71 , V_64 ) == V_118 )
V_76 = F_43 ( & V_78 , & V_64 , V_4 , 1 ) ;
}
if ( V_76 ) {
int V_123 = V_124 ;
int V_125 ;
V_125 = F_75 ( V_80 , V_76 -> V_126 + V_76 -> V_22 -> V_127 ) ;
if ( V_91 -> V_107 != F_58 ( V_114 ) ||
V_51 -> V_120 != V_121 )
V_123 = V_128 ;
F_76 ( V_76 , V_111 , V_123 ,
V_125 ? V_129 : 0 ) ;
F_45 ( V_76 ) ;
}
V_99:
F_77 ( V_51 ) ;
return 0 ;
}
static void F_78 ( struct V_50 * V_51 )
{
F_62 ( V_51 ) ;
}
static int F_79 ( struct V_50 * V_51 , struct V_3 * V_4 ,
struct V_130 * V_131 , struct V_3 * V_132 )
{
const struct V_90 * V_91 ;
if ( V_4 -> V_39 & V_40 ||
V_51 -> V_120 == V_133 ||
V_51 -> V_120 == V_134 )
goto V_135;
V_51 = F_80 ( V_51 , V_96 ) ;
if ( ! V_51 )
goto V_136;
if ( ! F_81 ( V_51 , F_54 ( V_4 ) ) )
goto V_135;
V_91 = F_63 ( V_51 ) ;
if ( V_91 -> V_105 != V_4 -> V_12 || V_91 -> V_106 != 4 )
goto V_135;
memset ( F_72 ( V_51 ) , 0 , sizeof( struct V_137 ) ) ;
return F_61 ( V_108 , V_138 , V_51 , V_4 , NULL , F_62 ) ;
V_135:
F_18 ( V_51 ) ;
V_136:
return 0 ;
}
static int F_82 ( struct V_71 * V_71 , struct V_3 * V_4 , int V_139 )
{
if ( V_4 == NULL ) {
F_83 ( V_71 , V_140 ) = V_139 ;
return 0 ;
}
if ( F_84 ( V_4 ) ) {
F_85 ( F_84 ( V_4 ) , V_140 , V_139 ) ;
return 0 ;
}
return - V_141 ;
}
static int F_86 ( struct V_71 * V_71 , struct V_142 * V_143 ,
struct V_3 * V_4 )
{
T_1 V_144 = ( (struct V_145 * ) & V_143 -> V_146 ) -> V_147 . V_148 ;
T_1 V_149 = ( (struct V_145 * ) & V_143 -> V_150 ) -> V_147 . V_148 ;
if ( V_149 && V_149 != F_87 ( 0xFFFFFFFF ) )
return - V_13 ;
if ( ! V_4 && ( V_143 -> V_151 & V_152 ) ) {
V_4 = F_88 ( V_71 , V_143 -> V_153 . V_154 ,
V_143 -> V_153 . V_155 ) ;
if ( ! V_4 )
return - V_156 ;
}
if ( V_149 ) {
if ( F_71 ( & V_78 , V_71 , & V_144 , V_4 , 1 ) == NULL )
return - V_157 ;
return 0 ;
}
return F_82 ( V_71 , V_4 , 1 ) ;
}
static int F_89 ( struct V_71 * V_71 , struct V_142 * V_143 ,
struct V_3 * V_4 )
{
T_1 V_144 ;
struct V_16 * V_17 ;
int V_158 ;
if ( V_143 -> V_151 & V_159 )
return F_86 ( V_71 , V_143 , V_4 ) ;
V_144 = ( (struct V_145 * ) & V_143 -> V_146 ) -> V_147 . V_148 ;
if ( V_143 -> V_151 & V_160 )
V_143 -> V_151 |= V_152 ;
if ( V_4 == NULL ) {
struct V_68 * V_69 = F_34 ( V_71 , V_144 , 0 , V_161 , 0 ) ;
if ( F_35 ( V_69 ) )
return F_90 ( V_69 ) ;
V_4 = V_69 -> V_72 . V_4 ;
F_37 ( V_69 ) ;
if ( ! V_4 )
return - V_13 ;
}
switch ( V_4 -> type ) {
#if F_15 ( V_104 )
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
V_17 = F_91 ( & V_78 , & V_144 , V_4 ) ;
V_158 = F_90 ( V_17 ) ;
if ( ! F_35 ( V_17 ) ) {
unsigned int V_123 = V_128 ;
if ( V_143 -> V_151 & V_160 )
V_123 = V_162 ;
V_158 = F_76 ( V_17 , ( V_143 -> V_151 & V_152 ) ?
V_143 -> V_153 . V_155 : NULL , V_123 ,
V_129 |
V_163 ) ;
F_45 ( V_17 ) ;
}
return V_158 ;
}
static unsigned int F_92 ( struct V_16 * V_17 )
{
if ( V_17 -> V_25 & V_162 )
return V_160 | V_152 ;
else if ( V_17 -> V_25 & V_48 )
return V_152 ;
else
return 0 ;
}
static int F_93 ( struct V_142 * V_143 , struct V_3 * V_4 )
{
T_1 V_144 = ( (struct V_145 * ) & V_143 -> V_146 ) -> V_147 . V_148 ;
struct V_16 * V_17 ;
int V_158 = - V_141 ;
V_17 = F_94 ( & V_78 , & V_144 , V_4 ) ;
if ( V_17 ) {
F_95 ( & V_17 -> V_164 ) ;
memcpy ( V_143 -> V_153 . V_155 , V_17 -> V_38 , V_4 -> V_12 ) ;
V_143 -> V_151 = F_92 ( V_17 ) ;
F_96 ( & V_17 -> V_164 ) ;
V_143 -> V_153 . V_154 = V_4 -> type ;
F_97 ( V_143 -> V_165 , V_4 -> V_166 , sizeof( V_143 -> V_165 ) ) ;
F_45 ( V_17 ) ;
V_158 = 0 ;
}
return V_158 ;
}
int F_98 ( struct V_3 * V_4 , T_1 V_144 )
{
struct V_16 * V_17 = F_94 ( & V_78 , & V_144 , V_4 ) ;
int V_158 = - V_141 ;
if ( V_17 ) {
if ( V_17 -> V_25 & ~ V_26 )
V_158 = F_76 ( V_17 , NULL , V_167 ,
V_129 |
V_163 ) ;
F_45 ( V_17 ) ;
}
return V_158 ;
}
static int F_99 ( struct V_71 * V_71 , struct V_142 * V_143 ,
struct V_3 * V_4 )
{
T_1 V_144 = ( (struct V_145 * ) & V_143 -> V_146 ) -> V_147 . V_148 ;
T_1 V_149 = ( (struct V_145 * ) & V_143 -> V_150 ) -> V_147 . V_148 ;
if ( V_149 == F_87 ( 0xFFFFFFFF ) )
return F_100 ( & V_78 , V_71 , & V_144 , V_4 ) ;
if ( V_149 )
return - V_13 ;
return F_82 ( V_71 , V_4 , 0 ) ;
}
static int F_101 ( struct V_71 * V_71 , struct V_142 * V_143 ,
struct V_3 * V_4 )
{
T_1 V_144 ;
if ( V_143 -> V_151 & V_159 )
return F_99 ( V_71 , V_143 , V_4 ) ;
V_144 = ( (struct V_145 * ) & V_143 -> V_146 ) -> V_147 . V_148 ;
if ( V_4 == NULL ) {
struct V_68 * V_69 = F_34 ( V_71 , V_144 , 0 , V_161 , 0 ) ;
if ( F_35 ( V_69 ) )
return F_90 ( V_69 ) ;
V_4 = V_69 -> V_72 . V_4 ;
F_37 ( V_69 ) ;
if ( ! V_4 )
return - V_13 ;
}
return F_98 ( V_4 , V_144 ) ;
}
int F_102 ( struct V_71 * V_71 , unsigned int V_168 , void T_6 * V_169 )
{
int V_158 ;
struct V_142 V_143 ;
struct V_3 * V_4 = NULL ;
switch ( V_168 ) {
case V_170 :
case V_171 :
if ( ! F_103 ( V_71 -> V_172 , V_173 ) )
return - V_174 ;
case V_175 :
V_158 = F_104 ( & V_143 , V_169 , sizeof( struct V_142 ) ) ;
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
F_87 ( 0xFFFFFFFFUL ) ;
F_105 () ;
if ( V_143 . V_165 [ 0 ] ) {
V_158 = - V_156 ;
V_4 = F_106 ( V_71 , V_143 . V_165 ) ;
if ( V_4 == NULL )
goto V_99;
if ( ! V_143 . V_153 . V_154 )
V_143 . V_153 . V_154 = V_4 -> type ;
V_158 = - V_13 ;
if ( ( V_143 . V_151 & V_152 ) && V_143 . V_153 . V_154 != V_4 -> type )
goto V_99;
} else if ( V_168 == V_175 ) {
V_158 = - V_156 ;
goto V_99;
}
switch ( V_168 ) {
case V_170 :
V_158 = F_101 ( V_71 , & V_143 , V_4 ) ;
break;
case V_171 :
V_158 = F_89 ( V_71 , & V_143 , V_4 ) ;
break;
case V_175 :
V_158 = F_93 ( & V_143 , V_4 ) ;
break;
}
V_99:
F_107 () ;
if ( V_168 == V_175 && ! V_158 && F_108 ( V_169 , & V_143 , sizeof( V_143 ) ) )
V_158 = - V_176 ;
return V_158 ;
}
static int F_109 ( struct V_181 * V_182 , unsigned long V_183 ,
void * V_184 )
{
struct V_3 * V_4 = V_184 ;
switch ( V_183 ) {
case V_185 :
F_110 ( & V_78 , V_4 ) ;
F_111 ( F_12 ( V_4 ) ) ;
break;
default:
break;
}
return V_186 ;
}
void F_112 ( struct V_3 * V_4 )
{
F_113 ( & V_78 , V_4 ) ;
}
void T_7 F_114 ( void )
{
F_115 ( & V_78 ) ;
F_116 ( & V_187 ) ;
F_117 () ;
#ifdef F_118
F_119 ( NULL , & V_78 . V_22 , L_4 , NULL ) ;
#endif
F_120 ( & V_188 ) ;
}
static char * F_121 ( T_8 * V_189 , char * V_190 )
{
char V_191 , * V_192 ;
int V_76 ;
for ( V_76 = 0 , V_192 = V_190 ; V_76 < 6 ; V_76 ++ ) {
V_191 = ( V_189 -> V_193 [ V_76 ] >> 1 ) & 0x7F ;
if ( V_191 != ' ' )
* V_192 ++ = V_191 ;
}
* V_192 ++ = '-' ;
V_76 = ( V_189 -> V_193 [ 6 ] >> 1 ) & 0x0F ;
if ( V_76 > 9 ) {
* V_192 ++ = '1' ;
V_76 -= 10 ;
}
* V_192 ++ = V_76 + '0' ;
* V_192 ++ = '\0' ;
if ( * V_190 == '\0' || * V_190 == '-' )
return L_5 ;
return V_190 ;
}
static void F_122 ( struct V_194 * V_195 ,
struct V_16 * V_76 )
{
char V_196 [ V_197 ] ;
int V_198 , V_199 ;
char V_200 [ 16 ] ;
struct V_3 * V_4 = V_76 -> V_4 ;
int V_201 = V_4 -> type ;
F_123 ( & V_76 -> V_164 ) ;
#if F_15 ( V_32 )
if ( V_201 == V_33 || V_201 == V_35 )
F_121 ( ( T_8 * ) V_76 -> V_38 , V_196 ) ;
else {
#endif
for ( V_198 = 0 , V_199 = 0 ; V_198 < V_197 - 3 && V_199 < V_4 -> V_12 ; V_199 ++ ) {
V_196 [ V_198 ++ ] = F_124 ( V_76 -> V_38 [ V_199 ] ) ;
V_196 [ V_198 ++ ] = F_125 ( V_76 -> V_38 [ V_199 ] ) ;
V_196 [ V_198 ++ ] = ':' ;
}
if ( V_198 != 0 )
-- V_198 ;
V_196 [ V_198 ] = 0 ;
#if F_15 ( V_32 )
}
#endif
sprintf ( V_200 , L_6 , V_76 -> V_18 ) ;
F_126 ( V_195 , L_7 ,
V_200 , V_201 , F_92 ( V_76 ) , V_196 , V_4 -> V_166 ) ;
F_127 ( & V_76 -> V_164 ) ;
}
static void F_128 ( struct V_194 * V_195 ,
struct V_202 * V_76 )
{
struct V_3 * V_4 = V_76 -> V_4 ;
int V_201 = V_4 ? V_4 -> type : 0 ;
char V_200 [ 16 ] ;
sprintf ( V_200 , L_6 , V_76 -> V_203 ) ;
F_126 ( V_195 , L_7 ,
V_200 , V_201 , V_159 | V_160 , L_8 ,
V_4 ? V_4 -> V_166 : L_5 ) ;
}
static int F_129 ( struct V_194 * V_195 , void * V_204 )
{
if ( V_204 == V_205 ) {
F_130 ( V_195 , L_9
L_10 ) ;
} else {
struct V_206 * V_123 = V_195 -> V_207 ;
if ( V_123 -> V_39 & V_208 )
F_128 ( V_195 , V_204 ) ;
else
F_122 ( V_195 , V_204 ) ;
}
return 0 ;
}
static void * F_131 ( struct V_194 * V_195 , T_9 * V_209 )
{
return F_132 ( V_195 , V_209 , & V_78 , V_210 ) ;
}
static int F_133 ( struct V_211 * V_211 , struct V_212 * V_212 )
{
return F_134 ( V_211 , V_212 , & V_213 ,
sizeof( struct V_206 ) ) ;
}
static int T_10 F_135 ( struct V_71 * V_71 )
{
if ( ! F_136 ( L_11 , V_214 , V_71 -> V_215 , & V_216 ) )
return - V_217 ;
return 0 ;
}
static void T_11 F_137 ( struct V_71 * V_71 )
{
F_138 ( L_11 , V_71 -> V_215 ) ;
}
static int T_7 F_117 ( void )
{
return F_139 ( & V_218 ) ;
}
static int T_7 F_117 ( void )
{
return 0 ;
}
