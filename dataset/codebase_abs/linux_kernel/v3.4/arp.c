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
if ( F_75 ( V_21 ) ) {
if ( V_77 == NULL &&
( V_92 -> V_109 == F_60 ( V_116 ) ||
( V_92 -> V_109 == F_60 ( V_63 ) && V_66 == V_65 ) ) &&
F_12 ( V_72 , V_65 ) == V_120 )
V_77 = F_44 ( & V_79 , & V_65 , V_4 , 1 ) ;
}
if ( V_77 ) {
int V_125 = V_126 ;
int V_127 ;
V_127 = F_76 ( V_81 , V_77 -> V_128 + V_77 -> V_23 -> V_129 ) ;
if ( V_92 -> V_109 != F_60 ( V_116 ) ||
V_52 -> V_122 != V_123 )
V_125 = V_130 ;
F_77 ( V_77 , V_113 , V_125 ,
V_127 ? V_131 : 0 ) ;
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
struct V_132 * V_133 , struct V_3 * V_134 )
{
struct V_91 * V_92 ;
if ( ! F_81 ( V_52 , F_56 ( V_4 ) ) )
goto V_135;
V_92 = F_65 ( V_52 ) ;
if ( V_92 -> V_107 != V_4 -> V_13 ||
V_4 -> V_40 & V_41 ||
V_52 -> V_122 == V_136 ||
V_52 -> V_122 == V_137 ||
V_92 -> V_108 != 4 )
goto V_135;
V_52 = F_82 ( V_52 , V_97 ) ;
if ( V_52 == NULL )
goto V_138;
memset ( F_73 ( V_52 ) , 0 , sizeof( struct V_139 ) ) ;
return F_63 ( V_110 , V_140 , V_52 , V_4 , NULL , F_64 ) ;
V_135:
F_19 ( V_52 ) ;
V_138:
return 0 ;
}
static int F_83 ( struct V_72 * V_72 , struct V_3 * V_4 , int V_141 )
{
if ( V_4 == NULL ) {
F_84 ( V_72 , V_142 ) = V_141 ;
return 0 ;
}
if ( F_85 ( V_4 ) ) {
F_86 ( F_85 ( V_4 ) , V_142 , V_141 ) ;
return 0 ;
}
return - V_143 ;
}
static int F_87 ( struct V_72 * V_72 , struct V_144 * V_145 ,
struct V_3 * V_4 )
{
T_1 V_146 = ( (struct V_147 * ) & V_145 -> V_148 ) -> V_149 . V_150 ;
T_1 V_151 = ( (struct V_147 * ) & V_145 -> V_152 ) -> V_149 . V_150 ;
if ( V_151 && V_151 != F_88 ( 0xFFFFFFFF ) )
return - V_14 ;
if ( ! V_4 && ( V_145 -> V_153 & V_154 ) ) {
V_4 = F_89 ( V_72 , V_145 -> V_155 . V_156 ,
V_145 -> V_155 . V_157 ) ;
if ( ! V_4 )
return - V_158 ;
}
if ( V_151 ) {
if ( F_72 ( & V_79 , V_72 , & V_146 , V_4 , 1 ) == NULL )
return - V_159 ;
return 0 ;
}
return F_83 ( V_72 , V_4 , 1 ) ;
}
static int F_90 ( struct V_72 * V_72 , struct V_144 * V_145 ,
struct V_3 * V_4 )
{
T_1 V_146 ;
struct V_17 * V_18 ;
int V_160 ;
if ( V_145 -> V_153 & V_161 )
return F_87 ( V_72 , V_145 , V_4 ) ;
V_146 = ( (struct V_147 * ) & V_145 -> V_148 ) -> V_149 . V_150 ;
if ( V_145 -> V_153 & V_162 )
V_145 -> V_153 |= V_154 ;
if ( V_4 == NULL ) {
struct V_69 * V_70 = F_36 ( V_72 , V_146 , 0 , V_163 , 0 ) ;
if ( F_37 ( V_70 ) )
return F_91 ( V_70 ) ;
V_4 = V_70 -> V_73 . V_4 ;
F_39 ( V_70 ) ;
if ( ! V_4 )
return - V_14 ;
}
switch ( V_4 -> type ) {
#if F_16 ( V_105 )
case V_7 :
if ( V_145 -> V_155 . V_156 != V_7 &&
V_145 -> V_155 . V_156 != V_6 &&
V_145 -> V_155 . V_156 != V_8 )
return - V_14 ;
break;
#endif
default:
if ( V_145 -> V_155 . V_156 != V_4 -> type )
return - V_14 ;
break;
}
V_18 = F_92 ( & V_79 , & V_146 , V_4 ) ;
V_160 = F_91 ( V_18 ) ;
if ( ! F_37 ( V_18 ) ) {
unsigned V_125 = V_130 ;
if ( V_145 -> V_153 & V_162 )
V_125 = V_164 ;
V_160 = F_77 ( V_18 , ( V_145 -> V_153 & V_154 ) ?
V_145 -> V_155 . V_157 : NULL , V_125 ,
V_131 |
V_165 ) ;
F_47 ( V_18 ) ;
}
return V_160 ;
}
static unsigned F_93 ( struct V_17 * V_18 )
{
if ( V_18 -> V_26 & V_164 )
return V_162 | V_154 ;
else if ( V_18 -> V_26 & V_49 )
return V_154 ;
else
return 0 ;
}
static int F_94 ( struct V_144 * V_145 , struct V_3 * V_4 )
{
T_1 V_146 = ( (struct V_147 * ) & V_145 -> V_148 ) -> V_149 . V_150 ;
struct V_17 * V_18 ;
int V_160 = - V_143 ;
V_18 = F_95 ( & V_79 , & V_146 , V_4 ) ;
if ( V_18 ) {
F_27 ( & V_18 -> V_61 ) ;
memcpy ( V_145 -> V_155 . V_157 , V_18 -> V_39 , V_4 -> V_13 ) ;
V_145 -> V_153 = F_93 ( V_18 ) ;
F_31 ( & V_18 -> V_61 ) ;
V_145 -> V_155 . V_156 = V_4 -> type ;
F_96 ( V_145 -> V_166 , V_4 -> V_167 , sizeof( V_145 -> V_166 ) ) ;
F_47 ( V_18 ) ;
V_160 = 0 ;
}
return V_160 ;
}
int F_97 ( struct V_3 * V_4 , T_1 V_146 )
{
struct V_17 * V_18 = F_95 ( & V_79 , & V_146 , V_4 ) ;
int V_160 = - V_143 ;
if ( V_18 ) {
if ( V_18 -> V_26 & ~ V_27 )
V_160 = F_77 ( V_18 , NULL , V_168 ,
V_131 |
V_165 ) ;
F_47 ( V_18 ) ;
}
return V_160 ;
}
static int F_98 ( struct V_72 * V_72 , struct V_144 * V_145 ,
struct V_3 * V_4 )
{
T_1 V_146 = ( (struct V_147 * ) & V_145 -> V_148 ) -> V_149 . V_150 ;
T_1 V_151 = ( (struct V_147 * ) & V_145 -> V_152 ) -> V_149 . V_150 ;
if ( V_151 == F_88 ( 0xFFFFFFFF ) )
return F_99 ( & V_79 , V_72 , & V_146 , V_4 ) ;
if ( V_151 )
return - V_14 ;
return F_83 ( V_72 , V_4 , 0 ) ;
}
static int F_100 ( struct V_72 * V_72 , struct V_144 * V_145 ,
struct V_3 * V_4 )
{
T_1 V_146 ;
if ( V_145 -> V_153 & V_161 )
return F_98 ( V_72 , V_145 , V_4 ) ;
V_146 = ( (struct V_147 * ) & V_145 -> V_148 ) -> V_149 . V_150 ;
if ( V_4 == NULL ) {
struct V_69 * V_70 = F_36 ( V_72 , V_146 , 0 , V_163 , 0 ) ;
if ( F_37 ( V_70 ) )
return F_91 ( V_70 ) ;
V_4 = V_70 -> V_73 . V_4 ;
F_39 ( V_70 ) ;
if ( ! V_4 )
return - V_14 ;
}
return F_97 ( V_4 , V_146 ) ;
}
int F_101 ( struct V_72 * V_72 , unsigned int V_169 , void T_6 * V_170 )
{
int V_160 ;
struct V_144 V_145 ;
struct V_3 * V_4 = NULL ;
switch ( V_169 ) {
case V_171 :
case V_172 :
if ( ! F_102 ( V_173 ) )
return - V_174 ;
case V_175 :
V_160 = F_103 ( & V_145 , V_170 , sizeof( struct V_144 ) ) ;
if ( V_160 )
return - V_176 ;
break;
default:
return - V_14 ;
}
if ( V_145 . V_148 . V_156 != V_177 )
return - V_178 ;
if ( ! ( V_145 . V_153 & V_161 ) &&
( V_145 . V_153 & ( V_179 | V_180 ) ) )
return - V_14 ;
if ( ! ( V_145 . V_153 & V_179 ) )
( (struct V_147 * ) & V_145 . V_152 ) -> V_149 . V_150 =
F_88 ( 0xFFFFFFFFUL ) ;
F_104 () ;
if ( V_145 . V_166 [ 0 ] ) {
V_160 = - V_158 ;
V_4 = F_105 ( V_72 , V_145 . V_166 ) ;
if ( V_4 == NULL )
goto V_100;
if ( ! V_145 . V_155 . V_156 )
V_145 . V_155 . V_156 = V_4 -> type ;
V_160 = - V_14 ;
if ( ( V_145 . V_153 & V_154 ) && V_145 . V_155 . V_156 != V_4 -> type )
goto V_100;
} else if ( V_169 == V_175 ) {
V_160 = - V_158 ;
goto V_100;
}
switch ( V_169 ) {
case V_171 :
V_160 = F_100 ( V_72 , & V_145 , V_4 ) ;
break;
case V_172 :
V_160 = F_90 ( V_72 , & V_145 , V_4 ) ;
break;
case V_175 :
V_160 = F_94 ( & V_145 , V_4 ) ;
break;
}
V_100:
F_106 () ;
if ( V_169 == V_175 && ! V_160 && F_107 ( V_170 , & V_145 , sizeof( V_145 ) ) )
V_160 = - V_176 ;
return V_160 ;
}
static int F_108 ( struct V_181 * V_182 , unsigned long V_183 ,
void * V_184 )
{
struct V_3 * V_4 = V_184 ;
switch ( V_183 ) {
case V_185 :
F_109 ( & V_79 , V_4 ) ;
F_110 ( F_13 ( V_4 ) , 0 ) ;
break;
default:
break;
}
return V_186 ;
}
void F_111 ( struct V_3 * V_4 )
{
F_112 ( & V_79 , V_4 ) ;
}
void T_7 F_113 ( void )
{
F_114 ( & V_79 ) ;
F_115 ( & V_187 ) ;
F_116 () ;
#ifdef F_117
F_118 ( NULL , & V_79 . V_23 , L_4 , NULL ) ;
#endif
F_119 ( & V_188 ) ;
}
static char * F_120 ( T_8 * V_189 , char * V_190 )
{
char V_191 , * V_192 ;
int V_77 ;
for ( V_77 = 0 , V_192 = V_190 ; V_77 < 6 ; V_77 ++ ) {
V_191 = ( V_189 -> V_193 [ V_77 ] >> 1 ) & 0x7F ;
if ( V_191 != ' ' )
* V_192 ++ = V_191 ;
}
* V_192 ++ = '-' ;
V_77 = ( V_189 -> V_193 [ 6 ] >> 1 ) & 0x0F ;
if ( V_77 > 9 ) {
* V_192 ++ = '1' ;
V_77 -= 10 ;
}
* V_192 ++ = V_77 + '0' ;
* V_192 ++ = '\0' ;
if ( * V_190 == '\0' || * V_190 == '-' )
return L_5 ;
return V_190 ;
}
static void F_121 ( struct V_194 * V_195 ,
struct V_17 * V_77 )
{
char V_196 [ V_197 ] ;
int V_198 , V_199 ;
char V_200 [ 16 ] ;
struct V_3 * V_4 = V_77 -> V_4 ;
int V_201 = V_4 -> type ;
F_122 ( & V_77 -> V_61 ) ;
#if F_16 ( V_33 )
if ( V_201 == V_34 || V_201 == V_36 )
F_120 ( ( T_8 * ) V_77 -> V_39 , V_196 ) ;
else {
#endif
for ( V_198 = 0 , V_199 = 0 ; V_198 < V_197 - 3 && V_199 < V_4 -> V_13 ; V_199 ++ ) {
V_196 [ V_198 ++ ] = F_123 ( V_77 -> V_39 [ V_199 ] ) ;
V_196 [ V_198 ++ ] = F_124 ( V_77 -> V_39 [ V_199 ] ) ;
V_196 [ V_198 ++ ] = ':' ;
}
if ( V_198 != 0 )
-- V_198 ;
V_196 [ V_198 ] = 0 ;
#if F_16 ( V_33 )
}
#endif
sprintf ( V_200 , L_6 , V_77 -> V_19 ) ;
F_125 ( V_195 , L_7 ,
V_200 , V_201 , F_93 ( V_77 ) , V_196 , V_4 -> V_167 ) ;
F_126 ( & V_77 -> V_61 ) ;
}
static void F_127 ( struct V_194 * V_195 ,
struct V_202 * V_77 )
{
struct V_3 * V_4 = V_77 -> V_4 ;
int V_201 = V_4 ? V_4 -> type : 0 ;
char V_200 [ 16 ] ;
sprintf ( V_200 , L_6 , V_77 -> V_203 ) ;
F_125 ( V_195 , L_7 ,
V_200 , V_201 , V_161 | V_162 , L_8 ,
V_4 ? V_4 -> V_167 : L_5 ) ;
}
static int F_128 ( struct V_194 * V_195 , void * V_204 )
{
if ( V_204 == V_205 ) {
F_129 ( V_195 , L_9
L_10 ) ;
} else {
struct V_206 * V_125 = V_195 -> V_207 ;
if ( V_125 -> V_40 & V_208 )
F_127 ( V_195 , V_204 ) ;
else
F_121 ( V_195 , V_204 ) ;
}
return 0 ;
}
static void * F_130 ( struct V_194 * V_195 , T_9 * V_209 )
{
return F_131 ( V_195 , V_209 , & V_79 , V_210 ) ;
}
static int F_132 ( struct V_211 * V_211 , struct V_212 * V_212 )
{
return F_133 ( V_211 , V_212 , & V_213 ,
sizeof( struct V_206 ) ) ;
}
static int T_10 F_134 ( struct V_72 * V_72 )
{
if ( ! F_135 ( V_72 , L_11 , V_214 , & V_215 ) )
return - V_216 ;
return 0 ;
}
static void T_11 F_136 ( struct V_72 * V_72 )
{
F_137 ( V_72 , L_11 ) ;
}
static int T_7 F_116 ( void )
{
return F_138 ( & V_217 ) ;
}
static int T_7 F_116 ( void )
{
return 0 ;
}
