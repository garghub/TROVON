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
T_4 * V_16 )
{
return F_7 ( * ( T_3 * ) V_15 , V_4 , * V_16 ) ;
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
#if F_16 ( V_33 )
case V_34 :
#if F_16 ( V_35 )
case V_36 :
#endif
V_18 -> V_28 = & V_37 ;
V_18 -> V_30 = V_18 -> V_28 -> V_30 ;
return 0 ;
#else
break;
#endif
}
#endif
if ( V_18 -> type == V_38 ) {
V_18 -> V_26 = V_27 ;
F_1 ( V_1 , V_18 -> V_39 , V_4 , 1 ) ;
} else if ( V_4 -> V_40 & ( V_41 | V_42 ) ) {
V_18 -> V_26 = V_27 ;
memcpy ( V_18 -> V_39 , V_4 -> V_43 , V_4 -> V_13 ) ;
} else if ( V_18 -> type == V_44 ||
( V_4 -> V_40 & V_45 ) ) {
V_18 -> V_26 = V_27 ;
memcpy ( V_18 -> V_39 , V_4 -> V_11 , V_4 -> V_13 ) ;
}
if ( V_4 -> V_25 -> V_46 )
V_18 -> V_28 = & V_47 ;
else
V_18 -> V_28 = & V_48 ;
if ( V_18 -> V_26 & V_49 )
V_18 -> V_30 = V_18 -> V_28 -> V_50 ;
else
V_18 -> V_30 = V_18 -> V_28 -> V_30 ;
}
return 0 ;
}
static void F_17 ( struct V_17 * V_18 , struct V_51 * V_52 )
{
F_18 ( V_52 ) ;
F_19 ( V_52 ) ;
}
static void F_20 ( struct V_17 * V_18 , struct V_51 * V_52 )
{
T_1 V_53 = 0 ;
T_2 * V_54 = NULL ;
struct V_3 * V_4 = V_18 -> V_4 ;
T_1 V_55 = * ( T_1 * ) V_18 -> V_19 ;
int V_56 = F_21 ( & V_18 -> V_56 ) ;
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
if ( V_52 && F_12 ( F_13 ( V_4 ) ,
F_23 ( V_52 ) -> V_53 ) == V_57 )
V_53 = F_23 ( V_52 ) -> V_53 ;
break;
case 1 :
if ( ! V_52 )
break;
V_53 = F_23 ( V_52 ) -> V_53 ;
if ( F_12 ( F_13 ( V_4 ) , V_53 ) == V_57 ) {
if ( F_24 ( V_21 , V_55 , V_53 ) )
break;
}
V_53 = 0 ;
break;
case 2 :
break;
}
F_11 () ;
if ( ! V_53 )
V_53 = F_25 ( V_4 , V_55 , V_58 ) ;
V_56 -= V_18 -> V_23 -> V_59 ;
if ( V_56 < 0 ) {
if ( ! ( V_18 -> V_26 & V_49 ) )
F_26 ( V_60
L_1 ) ;
V_54 = V_18 -> V_39 ;
F_27 ( & V_18 -> V_61 ) ;
} else {
V_56 -= V_18 -> V_23 -> V_62 ;
if ( V_56 < 0 ) {
#ifdef F_28
F_29 ( V_18 ) ;
#endif
return;
}
}
F_30 ( V_63 , V_64 , V_55 , V_4 , V_53 ,
V_54 , V_4 -> V_43 , NULL ) ;
if ( V_54 )
F_31 ( & V_18 -> V_61 ) ;
}
static int F_32 ( struct V_20 * V_21 , T_1 V_65 , T_1 V_66 )
{
int V_67 ;
switch ( F_33 ( V_21 ) ) {
case 0 :
return 0 ;
case 1 :
V_65 = 0 ;
V_67 = V_68 ;
break;
case 2 :
V_67 = V_68 ;
break;
case 3 :
V_65 = 0 ;
V_67 = V_58 ;
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
return ! F_34 ( V_21 , V_65 , V_66 , V_67 ) ;
}
static int F_35 ( T_1 V_65 , T_1 V_66 , struct V_3 * V_4 )
{
struct V_69 * V_70 ;
int V_71 = 0 ;
struct V_72 * V_72 = F_13 ( V_4 ) ;
V_70 = F_36 ( V_72 , V_65 , V_66 , 0 , 0 ) ;
if ( F_37 ( V_70 ) )
return 1 ;
if ( V_70 -> V_73 . V_4 != V_4 ) {
F_38 ( V_72 , V_74 ) ;
V_71 = 1 ;
}
F_39 ( V_70 ) ;
return V_71 ;
}
static int F_40 ( int V_75 , unsigned char * V_2 ,
T_1 V_76 , struct V_3 * V_4 )
{
switch ( V_75 ) {
case V_57 :
F_26 ( V_60 L_2 ) ;
memcpy ( V_2 , V_4 -> V_43 , V_4 -> V_13 ) ;
return 1 ;
case V_38 :
F_1 ( V_76 , V_2 , V_4 , 1 ) ;
return 1 ;
case V_44 :
memcpy ( V_2 , V_4 -> V_11 , V_4 -> V_13 ) ;
return 1 ;
}
return 0 ;
}
int F_41 ( unsigned char * V_2 , struct V_51 * V_52 )
{
struct V_3 * V_4 = V_52 -> V_4 ;
T_1 V_76 ;
struct V_17 * V_77 ;
if ( ! F_42 ( V_52 ) ) {
F_26 ( V_60 L_3 ) ;
F_19 ( V_52 ) ;
return 1 ;
}
V_76 = F_43 ( V_52 ) -> V_78 ;
if ( F_40 ( F_12 ( F_13 ( V_4 ) , V_76 ) , V_2 ,
V_76 , V_4 ) )
return 0 ;
V_77 = F_44 ( & V_79 , & V_76 , V_4 , 1 ) ;
if ( V_77 ) {
V_77 -> V_80 = V_81 ;
if ( V_77 -> V_26 & V_49 || F_45 ( V_77 , V_52 ) == 0 ) {
F_46 ( V_2 , V_77 , V_4 ) ;
F_47 ( V_77 ) ;
return 0 ;
}
F_47 ( V_77 ) ;
} else
F_19 ( V_52 ) ;
return 1 ;
}
static inline int F_48 ( struct V_20 * V_21 ,
struct V_3 * V_4 , struct V_69 * V_70 )
{
struct V_20 * V_82 ;
int V_83 , V_84 = - 1 ;
if ( V_70 -> V_73 . V_4 == V_4 )
return 0 ;
if ( ! F_49 ( V_21 ) )
return 0 ;
V_83 = F_50 ( V_21 ) ;
if ( V_83 == 0 )
return 1 ;
if ( V_83 == - 1 )
return 0 ;
V_82 = F_10 ( V_70 -> V_73 . V_4 ) ;
if ( V_82 )
V_84 = F_50 ( V_82 ) ;
return V_84 != V_83 && V_84 != - 1 ;
}
static inline int F_51 ( struct V_20 * V_21 ,
struct V_3 * V_4 , struct V_69 * V_70 ,
T_1 V_65 , T_1 V_66 )
{
if ( V_70 -> V_73 . V_4 != V_4 )
return 0 ;
if ( V_65 == V_66 )
return 0 ;
if ( F_52 ( V_21 ) )
return 1 ;
else
return 0 ;
}
struct V_51 * F_53 ( int type , int V_85 , T_1 V_86 ,
struct V_3 * V_4 , T_1 V_87 ,
const unsigned char * V_88 ,
const unsigned char * V_89 ,
const unsigned char * V_90 )
{
struct V_51 * V_52 ;
struct V_91 * V_92 ;
unsigned char * V_93 ;
int V_94 = F_54 ( V_4 ) ;
int V_95 = V_4 -> V_96 ;
V_52 = F_55 ( F_56 ( V_4 ) + V_94 + V_95 , V_97 ) ;
if ( V_52 == NULL )
return NULL ;
F_57 ( V_52 , V_94 ) ;
F_58 ( V_52 ) ;
V_92 = (struct V_91 * ) F_59 ( V_52 , F_56 ( V_4 ) ) ;
V_52 -> V_4 = V_4 ;
V_52 -> V_98 = F_60 ( V_64 ) ;
if ( V_89 == NULL )
V_89 = V_4 -> V_43 ;
if ( V_88 == NULL )
V_88 = V_4 -> V_11 ;
if ( F_61 ( V_52 , V_4 , V_85 , V_88 , V_89 , V_52 -> V_99 ) < 0 )
goto V_100;
switch ( V_4 -> type ) {
default:
V_92 -> V_101 = F_60 ( V_4 -> type ) ;
V_92 -> V_102 = F_60 ( V_103 ) ;
break;
#if F_16 ( V_33 )
case V_34 :
V_92 -> V_101 = F_60 ( V_34 ) ;
V_92 -> V_102 = F_60 ( V_104 ) ;
break;
#if F_16 ( V_35 )
case V_36 :
V_92 -> V_101 = F_60 ( V_36 ) ;
V_92 -> V_102 = F_60 ( V_104 ) ;
break;
#endif
#endif
#if F_16 ( V_105 )
case V_7 :
V_92 -> V_101 = F_60 ( V_6 ) ;
V_92 -> V_102 = F_60 ( V_103 ) ;
break;
#endif
#if F_16 ( V_106 )
case V_9 :
V_92 -> V_101 = F_60 ( V_8 ) ;
V_92 -> V_102 = F_60 ( V_103 ) ;
break;
#endif
}
V_92 -> V_107 = V_4 -> V_13 ;
V_92 -> V_108 = 4 ;
V_92 -> V_109 = F_60 ( type ) ;
V_93 = ( unsigned char * ) ( V_92 + 1 ) ;
memcpy ( V_93 , V_89 , V_4 -> V_13 ) ;
V_93 += V_4 -> V_13 ;
memcpy ( V_93 , & V_87 , 4 ) ;
V_93 += 4 ;
if ( V_90 != NULL )
memcpy ( V_93 , V_90 , V_4 -> V_13 ) ;
else
memset ( V_93 , 0 , V_4 -> V_13 ) ;
V_93 += V_4 -> V_13 ;
memcpy ( V_93 , & V_86 , 4 ) ;
return V_52 ;
V_100:
F_19 ( V_52 ) ;
return NULL ;
}
void F_62 ( struct V_51 * V_52 )
{
F_63 ( V_110 , V_111 , V_52 , NULL , V_52 -> V_4 , V_112 ) ;
}
void F_30 ( int type , int V_85 , T_1 V_86 ,
struct V_3 * V_4 , T_1 V_87 ,
const unsigned char * V_88 , const unsigned char * V_89 ,
const unsigned char * V_90 )
{
struct V_51 * V_52 ;
if ( V_4 -> V_40 & V_41 )
return;
V_52 = F_53 ( type , V_85 , V_86 , V_4 , V_87 ,
V_88 , V_89 , V_90 ) ;
if ( V_52 == NULL )
return;
F_62 ( V_52 ) ;
}
static int F_64 ( struct V_51 * V_52 )
{
struct V_3 * V_4 = V_52 -> V_4 ;
struct V_20 * V_21 = F_10 ( V_4 ) ;
struct V_91 * V_92 ;
unsigned char * V_93 ;
struct V_69 * V_70 ;
unsigned char * V_113 ;
T_1 V_65 , V_66 ;
T_5 V_114 = V_4 -> type ;
int V_115 ;
struct V_17 * V_77 ;
struct V_72 * V_72 = F_13 ( V_4 ) ;
if ( V_21 == NULL )
goto V_100;
V_92 = F_65 ( V_52 ) ;
switch ( V_114 ) {
default:
if ( V_92 -> V_102 != F_60 ( V_103 ) ||
F_60 ( V_114 ) != V_92 -> V_101 )
goto V_100;
break;
case V_6 :
case V_9 :
case V_7 :
case V_8 :
if ( ( V_92 -> V_101 != F_60 ( V_6 ) &&
V_92 -> V_101 != F_60 ( V_8 ) ) ||
V_92 -> V_102 != F_60 ( V_103 ) )
goto V_100;
break;
case V_34 :
if ( V_92 -> V_102 != F_60 ( V_104 ) ||
V_92 -> V_101 != F_60 ( V_34 ) )
goto V_100;
break;
case V_36 :
if ( V_92 -> V_102 != F_60 ( V_104 ) ||
V_92 -> V_101 != F_60 ( V_36 ) )
goto V_100;
break;
}
if ( V_92 -> V_109 != F_60 ( V_116 ) &&
V_92 -> V_109 != F_60 ( V_63 ) )
goto V_100;
V_93 = ( unsigned char * ) ( V_92 + 1 ) ;
V_113 = V_93 ;
V_93 += V_4 -> V_13 ;
memcpy ( & V_65 , V_93 , 4 ) ;
V_93 += 4 ;
V_93 += V_4 -> V_13 ;
memcpy ( & V_66 , V_93 , 4 ) ;
if ( F_66 ( V_66 ) || F_67 ( V_66 ) )
goto V_100;
if ( V_114 == V_117 )
V_113 = V_4 -> V_11 ;
if ( V_65 == 0 ) {
if ( V_92 -> V_109 == F_60 ( V_63 ) &&
F_12 ( V_72 , V_66 ) == V_57 &&
! F_32 ( V_21 , V_65 , V_66 ) )
F_30 ( V_116 , V_64 , V_65 , V_4 , V_66 , V_113 ,
V_4 -> V_43 , V_113 ) ;
goto V_100;
}
if ( V_92 -> V_109 == F_60 ( V_63 ) &&
F_68 ( V_52 , V_66 , V_65 , 0 , V_4 ) == 0 ) {
V_70 = F_43 ( V_52 ) ;
V_115 = V_70 -> V_118 ;
if ( V_115 == V_57 ) {
int V_119 ;
V_119 = F_32 ( V_21 , V_65 , V_66 ) ;
if ( ! V_119 && F_69 ( V_21 ) )
V_119 = F_35 ( V_65 , V_66 , V_4 ) ;
if ( ! V_119 ) {
V_77 = F_70 ( & V_79 , V_113 , & V_65 , V_4 ) ;
if ( V_77 ) {
F_30 ( V_116 , V_64 , V_65 ,
V_4 , V_66 , V_113 , V_4 -> V_43 ,
V_113 ) ;
F_47 ( V_77 ) ;
}
}
goto V_100;
} else if ( F_71 ( V_21 ) ) {
if ( V_115 == V_120 &&
( F_48 ( V_21 , V_4 , V_70 ) ||
F_51 ( V_21 , V_4 , V_70 , V_65 , V_66 ) ||
( V_70 -> V_73 . V_4 != V_4 &&
F_72 ( & V_79 , V_72 , & V_66 , V_4 , 0 ) ) ) ) {
V_77 = F_70 ( & V_79 , V_113 , & V_65 , V_4 ) ;
if ( V_77 )
F_47 ( V_77 ) ;
if ( F_73 ( V_52 ) -> V_40 & V_121 ||
V_52 -> V_122 == V_123 ||
V_21 -> V_24 -> V_124 == 0 ) {
F_30 ( V_116 , V_64 , V_65 ,
V_4 , V_66 , V_113 , V_4 -> V_43 ,
V_113 ) ;
} else {
F_74 ( & V_79 ,
V_21 -> V_24 , V_52 ) ;
return 0 ;
}
goto V_100;
}
}
}
V_77 = F_44 ( & V_79 , & V_65 , V_4 , 0 ) ;
if ( F_75 ( F_13 ( V_4 ) , V_125 ) ) {
if ( V_77 == NULL &&
( V_92 -> V_109 == F_60 ( V_116 ) ||
( V_92 -> V_109 == F_60 ( V_63 ) && V_66 == V_65 ) ) &&
F_12 ( V_72 , V_65 ) == V_120 )
V_77 = F_44 ( & V_79 , & V_65 , V_4 , 1 ) ;
}
if ( V_77 ) {
int V_126 = V_127 ;
int V_128 ;
V_128 = F_76 ( V_81 , V_77 -> V_129 + V_77 -> V_23 -> V_130 ) ;
if ( V_92 -> V_109 != F_60 ( V_116 ) ||
V_52 -> V_122 != V_123 )
V_126 = V_131 ;
F_77 ( V_77 , V_113 , V_126 ,
V_128 ? V_132 : 0 ) ;
F_47 ( V_77 ) ;
}
V_100:
F_78 ( V_52 ) ;
return 0 ;
}
static void F_79 ( struct V_51 * V_52 )
{
F_64 ( V_52 ) ;
}
static int F_80 ( struct V_51 * V_52 , struct V_3 * V_4 ,
struct V_133 * V_134 , struct V_3 * V_135 )
{
struct V_91 * V_92 ;
if ( ! F_81 ( V_52 , F_56 ( V_4 ) ) )
goto V_136;
V_92 = F_65 ( V_52 ) ;
if ( V_92 -> V_107 != V_4 -> V_13 ||
V_4 -> V_40 & V_41 ||
V_52 -> V_122 == V_137 ||
V_52 -> V_122 == V_138 ||
V_92 -> V_108 != 4 )
goto V_136;
V_52 = F_82 ( V_52 , V_97 ) ;
if ( V_52 == NULL )
goto V_139;
memset ( F_73 ( V_52 ) , 0 , sizeof( struct V_140 ) ) ;
return F_63 ( V_110 , V_141 , V_52 , V_4 , NULL , F_64 ) ;
V_136:
F_19 ( V_52 ) ;
V_139:
return 0 ;
}
static int F_83 ( struct V_72 * V_72 , struct V_3 * V_4 , int V_142 )
{
if ( V_4 == NULL ) {
F_75 ( V_72 , V_143 ) = V_142 ;
return 0 ;
}
if ( F_84 ( V_4 ) ) {
F_85 ( F_84 ( V_4 ) , V_143 , V_142 ) ;
return 0 ;
}
return - V_144 ;
}
static int F_86 ( struct V_72 * V_72 , struct V_145 * V_146 ,
struct V_3 * V_4 )
{
T_1 V_147 = ( (struct V_148 * ) & V_146 -> V_149 ) -> V_150 . V_151 ;
T_1 V_152 = ( (struct V_148 * ) & V_146 -> V_153 ) -> V_150 . V_151 ;
if ( V_152 && V_152 != F_87 ( 0xFFFFFFFF ) )
return - V_14 ;
if ( ! V_4 && ( V_146 -> V_154 & V_155 ) ) {
V_4 = F_88 ( V_72 , V_146 -> V_156 . V_157 ,
V_146 -> V_156 . V_158 ) ;
if ( ! V_4 )
return - V_159 ;
}
if ( V_152 ) {
if ( F_72 ( & V_79 , V_72 , & V_147 , V_4 , 1 ) == NULL )
return - V_160 ;
return 0 ;
}
return F_83 ( V_72 , V_4 , 1 ) ;
}
static int F_89 ( struct V_72 * V_72 , struct V_145 * V_146 ,
struct V_3 * V_4 )
{
T_1 V_147 ;
struct V_17 * V_18 ;
int V_161 ;
if ( V_146 -> V_154 & V_162 )
return F_86 ( V_72 , V_146 , V_4 ) ;
V_147 = ( (struct V_148 * ) & V_146 -> V_149 ) -> V_150 . V_151 ;
if ( V_146 -> V_154 & V_163 )
V_146 -> V_154 |= V_155 ;
if ( V_4 == NULL ) {
struct V_69 * V_70 = F_36 ( V_72 , V_147 , 0 , V_164 , 0 ) ;
if ( F_37 ( V_70 ) )
return F_90 ( V_70 ) ;
V_4 = V_70 -> V_73 . V_4 ;
F_39 ( V_70 ) ;
if ( ! V_4 )
return - V_14 ;
}
switch ( V_4 -> type ) {
#if F_16 ( V_105 )
case V_7 :
if ( V_146 -> V_156 . V_157 != V_7 &&
V_146 -> V_156 . V_157 != V_6 &&
V_146 -> V_156 . V_157 != V_8 )
return - V_14 ;
break;
#endif
default:
if ( V_146 -> V_156 . V_157 != V_4 -> type )
return - V_14 ;
break;
}
V_18 = F_91 ( & V_79 , & V_147 , V_4 ) ;
V_161 = F_90 ( V_18 ) ;
if ( ! F_37 ( V_18 ) ) {
unsigned V_126 = V_131 ;
if ( V_146 -> V_154 & V_163 )
V_126 = V_165 ;
V_161 = F_77 ( V_18 , ( V_146 -> V_154 & V_155 ) ?
V_146 -> V_156 . V_158 : NULL , V_126 ,
V_132 |
V_166 ) ;
F_47 ( V_18 ) ;
}
return V_161 ;
}
static unsigned F_92 ( struct V_17 * V_18 )
{
if ( V_18 -> V_26 & V_165 )
return V_163 | V_155 ;
else if ( V_18 -> V_26 & V_49 )
return V_155 ;
else
return 0 ;
}
static int F_93 ( struct V_145 * V_146 , struct V_3 * V_4 )
{
T_1 V_147 = ( (struct V_148 * ) & V_146 -> V_149 ) -> V_150 . V_151 ;
struct V_17 * V_18 ;
int V_161 = - V_144 ;
V_18 = F_94 ( & V_79 , & V_147 , V_4 ) ;
if ( V_18 ) {
F_27 ( & V_18 -> V_61 ) ;
memcpy ( V_146 -> V_156 . V_158 , V_18 -> V_39 , V_4 -> V_13 ) ;
V_146 -> V_154 = F_92 ( V_18 ) ;
F_31 ( & V_18 -> V_61 ) ;
V_146 -> V_156 . V_157 = V_4 -> type ;
F_95 ( V_146 -> V_167 , V_4 -> V_168 , sizeof( V_146 -> V_167 ) ) ;
F_47 ( V_18 ) ;
V_161 = 0 ;
}
return V_161 ;
}
int F_96 ( struct V_3 * V_4 , T_1 V_147 )
{
struct V_17 * V_18 = F_94 ( & V_79 , & V_147 , V_4 ) ;
int V_161 = - V_144 ;
if ( V_18 ) {
if ( V_18 -> V_26 & ~ V_27 )
V_161 = F_77 ( V_18 , NULL , V_169 ,
V_132 |
V_166 ) ;
F_47 ( V_18 ) ;
}
return V_161 ;
}
static int F_97 ( struct V_72 * V_72 , struct V_145 * V_146 ,
struct V_3 * V_4 )
{
T_1 V_147 = ( (struct V_148 * ) & V_146 -> V_149 ) -> V_150 . V_151 ;
T_1 V_152 = ( (struct V_148 * ) & V_146 -> V_153 ) -> V_150 . V_151 ;
if ( V_152 == F_87 ( 0xFFFFFFFF ) )
return F_98 ( & V_79 , V_72 , & V_147 , V_4 ) ;
if ( V_152 )
return - V_14 ;
return F_83 ( V_72 , V_4 , 0 ) ;
}
static int F_99 ( struct V_72 * V_72 , struct V_145 * V_146 ,
struct V_3 * V_4 )
{
T_1 V_147 ;
if ( V_146 -> V_154 & V_162 )
return F_97 ( V_72 , V_146 , V_4 ) ;
V_147 = ( (struct V_148 * ) & V_146 -> V_149 ) -> V_150 . V_151 ;
if ( V_4 == NULL ) {
struct V_69 * V_70 = F_36 ( V_72 , V_147 , 0 , V_164 , 0 ) ;
if ( F_37 ( V_70 ) )
return F_90 ( V_70 ) ;
V_4 = V_70 -> V_73 . V_4 ;
F_39 ( V_70 ) ;
if ( ! V_4 )
return - V_14 ;
}
return F_96 ( V_4 , V_147 ) ;
}
int F_100 ( struct V_72 * V_72 , unsigned int V_170 , void T_6 * V_171 )
{
int V_161 ;
struct V_145 V_146 ;
struct V_3 * V_4 = NULL ;
switch ( V_170 ) {
case V_172 :
case V_173 :
if ( ! F_101 ( V_174 ) )
return - V_175 ;
case V_176 :
V_161 = F_102 ( & V_146 , V_171 , sizeof( struct V_145 ) ) ;
if ( V_161 )
return - V_177 ;
break;
default:
return - V_14 ;
}
if ( V_146 . V_149 . V_157 != V_178 )
return - V_179 ;
if ( ! ( V_146 . V_154 & V_162 ) &&
( V_146 . V_154 & ( V_180 | V_181 ) ) )
return - V_14 ;
if ( ! ( V_146 . V_154 & V_180 ) )
( (struct V_148 * ) & V_146 . V_153 ) -> V_150 . V_151 =
F_87 ( 0xFFFFFFFFUL ) ;
F_103 () ;
if ( V_146 . V_167 [ 0 ] ) {
V_161 = - V_159 ;
V_4 = F_104 ( V_72 , V_146 . V_167 ) ;
if ( V_4 == NULL )
goto V_100;
if ( ! V_146 . V_156 . V_157 )
V_146 . V_156 . V_157 = V_4 -> type ;
V_161 = - V_14 ;
if ( ( V_146 . V_154 & V_155 ) && V_146 . V_156 . V_157 != V_4 -> type )
goto V_100;
} else if ( V_170 == V_176 ) {
V_161 = - V_159 ;
goto V_100;
}
switch ( V_170 ) {
case V_172 :
V_161 = F_99 ( V_72 , & V_146 , V_4 ) ;
break;
case V_173 :
V_161 = F_89 ( V_72 , & V_146 , V_4 ) ;
break;
case V_176 :
V_161 = F_93 ( & V_146 , V_4 ) ;
break;
}
V_100:
F_105 () ;
if ( V_170 == V_176 && ! V_161 && F_106 ( V_171 , & V_146 , sizeof( V_146 ) ) )
V_161 = - V_177 ;
return V_161 ;
}
static int F_107 ( struct V_182 * V_183 , unsigned long V_184 ,
void * V_185 )
{
struct V_3 * V_4 = V_185 ;
switch ( V_184 ) {
case V_186 :
F_108 ( & V_79 , V_4 ) ;
F_109 ( F_13 ( V_4 ) , 0 ) ;
break;
default:
break;
}
return V_187 ;
}
void F_110 ( struct V_3 * V_4 )
{
F_111 ( & V_79 , V_4 ) ;
}
void T_7 F_112 ( void )
{
F_113 ( & V_79 ) ;
F_114 ( & V_188 ) ;
F_115 () ;
#ifdef F_116
F_117 ( NULL , & V_79 . V_23 , L_4 , NULL ) ;
#endif
F_118 ( & V_189 ) ;
}
static char * F_119 ( T_8 * V_190 , char * V_191 )
{
char V_192 , * V_193 ;
int V_77 ;
for ( V_77 = 0 , V_193 = V_191 ; V_77 < 6 ; V_77 ++ ) {
V_192 = ( V_190 -> V_194 [ V_77 ] >> 1 ) & 0x7F ;
if ( V_192 != ' ' )
* V_193 ++ = V_192 ;
}
* V_193 ++ = '-' ;
V_77 = ( V_190 -> V_194 [ 6 ] >> 1 ) & 0x0F ;
if ( V_77 > 9 ) {
* V_193 ++ = '1' ;
V_77 -= 10 ;
}
* V_193 ++ = V_77 + '0' ;
* V_193 ++ = '\0' ;
if ( * V_191 == '\0' || * V_191 == '-' )
return L_5 ;
return V_191 ;
}
static void F_120 ( struct V_195 * V_196 ,
struct V_17 * V_77 )
{
char V_197 [ V_198 ] ;
int V_199 , V_200 ;
char V_201 [ 16 ] ;
struct V_3 * V_4 = V_77 -> V_4 ;
int V_202 = V_4 -> type ;
F_121 ( & V_77 -> V_61 ) ;
#if F_16 ( V_33 )
if ( V_202 == V_34 || V_202 == V_36 )
F_119 ( ( T_8 * ) V_77 -> V_39 , V_197 ) ;
else {
#endif
for ( V_199 = 0 , V_200 = 0 ; V_199 < V_198 - 3 && V_200 < V_4 -> V_13 ; V_200 ++ ) {
V_197 [ V_199 ++ ] = F_122 ( V_77 -> V_39 [ V_200 ] ) ;
V_197 [ V_199 ++ ] = F_123 ( V_77 -> V_39 [ V_200 ] ) ;
V_197 [ V_199 ++ ] = ':' ;
}
if ( V_199 != 0 )
-- V_199 ;
V_197 [ V_199 ] = 0 ;
#if F_16 ( V_33 )
}
#endif
sprintf ( V_201 , L_6 , V_77 -> V_19 ) ;
F_124 ( V_196 , L_7 ,
V_201 , V_202 , F_92 ( V_77 ) , V_197 , V_4 -> V_168 ) ;
F_125 ( & V_77 -> V_61 ) ;
}
static void F_126 ( struct V_195 * V_196 ,
struct V_203 * V_77 )
{
struct V_3 * V_4 = V_77 -> V_4 ;
int V_202 = V_4 ? V_4 -> type : 0 ;
char V_201 [ 16 ] ;
sprintf ( V_201 , L_6 , V_77 -> V_204 ) ;
F_124 ( V_196 , L_7 ,
V_201 , V_202 , V_162 | V_163 , L_8 ,
V_4 ? V_4 -> V_168 : L_5 ) ;
}
static int F_127 ( struct V_195 * V_196 , void * V_205 )
{
if ( V_205 == V_206 ) {
F_128 ( V_196 , L_9
L_10 ) ;
} else {
struct V_207 * V_126 = V_196 -> V_208 ;
if ( V_126 -> V_40 & V_209 )
F_126 ( V_196 , V_205 ) ;
else
F_120 ( V_196 , V_205 ) ;
}
return 0 ;
}
static void * F_129 ( struct V_195 * V_196 , T_9 * V_210 )
{
return F_130 ( V_196 , V_210 , & V_79 , V_211 ) ;
}
static int F_131 ( struct V_212 * V_212 , struct V_213 * V_213 )
{
return F_132 ( V_212 , V_213 , & V_214 ,
sizeof( struct V_207 ) ) ;
}
static int T_10 F_133 ( struct V_72 * V_72 )
{
if ( ! F_134 ( V_72 , L_11 , V_215 , & V_216 ) )
return - V_217 ;
return 0 ;
}
static void T_11 F_135 ( struct V_72 * V_72 )
{
F_136 ( V_72 , L_11 ) ;
}
static int T_7 F_115 ( void )
{
return F_137 ( & V_218 ) ;
}
static int T_7 F_115 ( void )
{
return 0 ;
}
