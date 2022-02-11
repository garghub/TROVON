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
T_2 * V_53 = NULL ;
struct V_3 * V_4 = V_17 -> V_4 ;
T_1 V_54 = * ( T_1 * ) V_17 -> V_18 ;
int V_55 = F_20 ( & V_17 -> V_55 ) ;
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
F_22 ( V_51 ) -> V_52 ) == V_56 )
V_52 = F_22 ( V_51 ) -> V_52 ;
break;
case 1 :
if ( ! V_51 )
break;
V_52 = F_22 ( V_51 ) -> V_52 ;
if ( F_11 ( F_12 ( V_4 ) , V_52 ) == V_56 ) {
if ( F_23 ( V_20 , V_54 , V_52 ) )
break;
}
V_52 = 0 ;
break;
case 2 :
break;
}
F_10 () ;
if ( ! V_52 )
V_52 = F_24 ( V_4 , V_54 , V_57 ) ;
V_55 -= V_17 -> V_22 -> V_58 ;
if ( V_55 < 0 ) {
if ( ! ( V_17 -> V_25 & V_48 ) )
F_25 ( L_1 ) ;
V_53 = V_17 -> V_38 ;
F_26 ( & V_17 -> V_59 ) ;
} else {
V_55 -= V_17 -> V_22 -> V_60 ;
if ( V_55 < 0 ) {
#ifdef F_27
F_28 ( V_17 ) ;
#endif
return;
}
}
F_29 ( V_61 , V_62 , V_54 , V_4 , V_52 ,
V_53 , V_4 -> V_42 , NULL ) ;
if ( V_53 )
F_30 ( & V_17 -> V_59 ) ;
}
static int F_31 ( struct V_19 * V_20 , T_1 V_63 , T_1 V_64 )
{
int V_65 ;
switch ( F_32 ( V_20 ) ) {
case 0 :
return 0 ;
case 1 :
V_63 = 0 ;
V_65 = V_66 ;
break;
case 2 :
V_65 = V_66 ;
break;
case 3 :
V_63 = 0 ;
V_65 = V_57 ;
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
return ! F_33 ( V_20 , V_63 , V_64 , V_65 ) ;
}
static int F_34 ( T_1 V_63 , T_1 V_64 , struct V_3 * V_4 )
{
struct V_67 * V_68 ;
int V_69 = 0 ;
struct V_70 * V_70 = F_12 ( V_4 ) ;
V_68 = F_35 ( V_70 , V_63 , V_64 , 0 , 0 ) ;
if ( F_36 ( V_68 ) )
return 1 ;
if ( V_68 -> V_71 . V_4 != V_4 ) {
F_37 ( V_70 , V_72 ) ;
V_69 = 1 ;
}
F_38 ( V_68 ) ;
return V_69 ;
}
static int F_39 ( int V_73 , unsigned char * V_2 ,
T_1 V_74 , struct V_3 * V_4 )
{
switch ( V_73 ) {
case V_56 :
F_25 ( L_2 ) ;
memcpy ( V_2 , V_4 -> V_42 , V_4 -> V_12 ) ;
return 1 ;
case V_37 :
F_1 ( V_74 , V_2 , V_4 , 1 ) ;
return 1 ;
case V_43 :
memcpy ( V_2 , V_4 -> V_10 , V_4 -> V_12 ) ;
return 1 ;
}
return 0 ;
}
int F_40 ( unsigned char * V_2 , struct V_50 * V_51 )
{
struct V_3 * V_4 = V_51 -> V_4 ;
T_1 V_74 ;
struct V_16 * V_75 ;
if ( ! F_41 ( V_51 ) ) {
F_25 ( L_3 ) ;
F_18 ( V_51 ) ;
return 1 ;
}
V_74 = F_42 ( V_51 ) -> V_76 ;
if ( F_39 ( F_11 ( F_12 ( V_4 ) , V_74 ) , V_2 ,
V_74 , V_4 ) )
return 0 ;
V_75 = F_43 ( & V_77 , & V_74 , V_4 , 1 ) ;
if ( V_75 ) {
V_75 -> V_78 = V_79 ;
if ( V_75 -> V_25 & V_48 || F_44 ( V_75 , V_51 ) == 0 ) {
F_45 ( V_2 , V_75 , V_4 ) ;
F_46 ( V_75 ) ;
return 0 ;
}
F_46 ( V_75 ) ;
} else
F_18 ( V_51 ) ;
return 1 ;
}
static inline int F_47 ( struct V_19 * V_20 ,
struct V_3 * V_4 , struct V_67 * V_68 )
{
struct V_19 * V_80 ;
int V_81 , V_82 = - 1 ;
if ( V_68 -> V_71 . V_4 == V_4 )
return 0 ;
if ( ! F_48 ( V_20 ) )
return 0 ;
V_81 = F_49 ( V_20 ) ;
if ( V_81 == 0 )
return 1 ;
if ( V_81 == - 1 )
return 0 ;
V_80 = F_9 ( V_68 -> V_71 . V_4 ) ;
if ( V_80 )
V_82 = F_49 ( V_80 ) ;
return V_82 != V_81 && V_82 != - 1 ;
}
static inline int F_50 ( struct V_19 * V_20 ,
struct V_3 * V_4 , struct V_67 * V_68 ,
T_1 V_63 , T_1 V_64 )
{
if ( V_68 -> V_71 . V_4 != V_4 )
return 0 ;
if ( V_63 == V_64 )
return 0 ;
if ( F_51 ( V_20 ) )
return 1 ;
else
return 0 ;
}
struct V_50 * F_52 ( int type , int V_83 , T_1 V_84 ,
struct V_3 * V_4 , T_1 V_85 ,
const unsigned char * V_86 ,
const unsigned char * V_87 ,
const unsigned char * V_88 )
{
struct V_50 * V_51 ;
struct V_89 * V_90 ;
unsigned char * V_91 ;
int V_92 = F_53 ( V_4 ) ;
int V_93 = V_4 -> V_94 ;
V_51 = F_54 ( F_55 ( V_4 ) + V_92 + V_93 , V_95 ) ;
if ( V_51 == NULL )
return NULL ;
F_56 ( V_51 , V_92 ) ;
F_57 ( V_51 ) ;
V_90 = (struct V_89 * ) F_58 ( V_51 , F_55 ( V_4 ) ) ;
V_51 -> V_4 = V_4 ;
V_51 -> V_96 = F_59 ( V_62 ) ;
if ( V_87 == NULL )
V_87 = V_4 -> V_42 ;
if ( V_86 == NULL )
V_86 = V_4 -> V_10 ;
if ( F_60 ( V_51 , V_4 , V_83 , V_86 , V_87 , V_51 -> V_97 ) < 0 )
goto V_98;
switch ( V_4 -> type ) {
default:
V_90 -> V_99 = F_59 ( V_4 -> type ) ;
V_90 -> V_100 = F_59 ( V_101 ) ;
break;
#if F_15 ( V_32 )
case V_33 :
V_90 -> V_99 = F_59 ( V_33 ) ;
V_90 -> V_100 = F_59 ( V_102 ) ;
break;
#if F_15 ( V_34 )
case V_35 :
V_90 -> V_99 = F_59 ( V_35 ) ;
V_90 -> V_100 = F_59 ( V_102 ) ;
break;
#endif
#endif
#if F_15 ( V_103 )
case V_7 :
V_90 -> V_99 = F_59 ( V_6 ) ;
V_90 -> V_100 = F_59 ( V_101 ) ;
break;
#endif
}
V_90 -> V_104 = V_4 -> V_12 ;
V_90 -> V_105 = 4 ;
V_90 -> V_106 = F_59 ( type ) ;
V_91 = ( unsigned char * ) ( V_90 + 1 ) ;
memcpy ( V_91 , V_87 , V_4 -> V_12 ) ;
V_91 += V_4 -> V_12 ;
memcpy ( V_91 , & V_85 , 4 ) ;
V_91 += 4 ;
if ( V_88 != NULL )
memcpy ( V_91 , V_88 , V_4 -> V_12 ) ;
else
memset ( V_91 , 0 , V_4 -> V_12 ) ;
V_91 += V_4 -> V_12 ;
memcpy ( V_91 , & V_84 , 4 ) ;
return V_51 ;
V_98:
F_18 ( V_51 ) ;
return NULL ;
}
void F_61 ( struct V_50 * V_51 )
{
F_62 ( V_107 , V_108 , V_51 , NULL , V_51 -> V_4 , V_109 ) ;
}
void F_29 ( int type , int V_83 , T_1 V_84 ,
struct V_3 * V_4 , T_1 V_85 ,
const unsigned char * V_86 , const unsigned char * V_87 ,
const unsigned char * V_88 )
{
struct V_50 * V_51 ;
if ( V_4 -> V_39 & V_40 )
return;
V_51 = F_52 ( type , V_83 , V_84 , V_4 , V_85 ,
V_86 , V_87 , V_88 ) ;
if ( V_51 == NULL )
return;
F_61 ( V_51 ) ;
}
static int F_63 ( struct V_50 * V_51 )
{
struct V_3 * V_4 = V_51 -> V_4 ;
struct V_19 * V_20 = F_9 ( V_4 ) ;
struct V_89 * V_90 ;
unsigned char * V_91 ;
struct V_67 * V_68 ;
unsigned char * V_110 ;
T_1 V_63 , V_64 ;
T_5 V_111 = V_4 -> type ;
int V_112 ;
struct V_16 * V_75 ;
struct V_70 * V_70 = F_12 ( V_4 ) ;
if ( V_20 == NULL )
goto V_98;
V_90 = F_64 ( V_51 ) ;
switch ( V_111 ) {
default:
if ( V_90 -> V_100 != F_59 ( V_101 ) ||
F_59 ( V_111 ) != V_90 -> V_99 )
goto V_98;
break;
case V_6 :
case V_7 :
case V_8 :
if ( ( V_90 -> V_99 != F_59 ( V_6 ) &&
V_90 -> V_99 != F_59 ( V_8 ) ) ||
V_90 -> V_100 != F_59 ( V_101 ) )
goto V_98;
break;
case V_33 :
if ( V_90 -> V_100 != F_59 ( V_102 ) ||
V_90 -> V_99 != F_59 ( V_33 ) )
goto V_98;
break;
case V_35 :
if ( V_90 -> V_100 != F_59 ( V_102 ) ||
V_90 -> V_99 != F_59 ( V_35 ) )
goto V_98;
break;
}
if ( V_90 -> V_106 != F_59 ( V_113 ) &&
V_90 -> V_106 != F_59 ( V_61 ) )
goto V_98;
V_91 = ( unsigned char * ) ( V_90 + 1 ) ;
V_110 = V_91 ;
V_91 += V_4 -> V_12 ;
memcpy ( & V_63 , V_91 , 4 ) ;
V_91 += 4 ;
V_91 += V_4 -> V_12 ;
memcpy ( & V_64 , V_91 , 4 ) ;
if ( F_65 ( V_64 ) || F_66 ( V_64 ) )
goto V_98;
if ( V_111 == V_114 )
V_110 = V_4 -> V_10 ;
if ( V_63 == 0 ) {
if ( V_90 -> V_106 == F_59 ( V_61 ) &&
F_11 ( V_70 , V_64 ) == V_56 &&
! F_31 ( V_20 , V_63 , V_64 ) )
F_29 ( V_113 , V_62 , V_63 , V_4 , V_64 , V_110 ,
V_4 -> V_42 , V_110 ) ;
goto V_98;
}
if ( V_90 -> V_106 == F_59 ( V_61 ) &&
F_67 ( V_51 , V_64 , V_63 , 0 , V_4 ) == 0 ) {
V_68 = F_42 ( V_51 ) ;
V_112 = V_68 -> V_115 ;
if ( V_112 == V_56 ) {
int V_116 ;
V_116 = F_31 ( V_20 , V_63 , V_64 ) ;
if ( ! V_116 && F_68 ( V_20 ) )
V_116 = F_34 ( V_63 , V_64 , V_4 ) ;
if ( ! V_116 ) {
V_75 = F_69 ( & V_77 , V_110 , & V_63 , V_4 ) ;
if ( V_75 ) {
F_29 ( V_113 , V_62 , V_63 ,
V_4 , V_64 , V_110 , V_4 -> V_42 ,
V_110 ) ;
F_46 ( V_75 ) ;
}
}
goto V_98;
} else if ( F_70 ( V_20 ) ) {
if ( V_112 == V_117 &&
( F_47 ( V_20 , V_4 , V_68 ) ||
F_50 ( V_20 , V_4 , V_68 , V_63 , V_64 ) ||
( V_68 -> V_71 . V_4 != V_4 &&
F_71 ( & V_77 , V_70 , & V_64 , V_4 , 0 ) ) ) ) {
V_75 = F_69 ( & V_77 , V_110 , & V_63 , V_4 ) ;
if ( V_75 )
F_46 ( V_75 ) ;
if ( F_72 ( V_51 ) -> V_39 & V_118 ||
V_51 -> V_119 == V_120 ||
V_20 -> V_23 -> V_121 == 0 ) {
F_29 ( V_113 , V_62 , V_63 ,
V_4 , V_64 , V_110 , V_4 -> V_42 ,
V_110 ) ;
} else {
F_73 ( & V_77 ,
V_20 -> V_23 , V_51 ) ;
return 0 ;
}
goto V_98;
}
}
}
V_75 = F_43 ( & V_77 , & V_63 , V_4 , 0 ) ;
if ( F_74 ( V_20 ) ) {
if ( V_75 == NULL &&
( V_90 -> V_106 == F_59 ( V_113 ) ||
( V_90 -> V_106 == F_59 ( V_61 ) && V_64 == V_63 ) ) &&
F_11 ( V_70 , V_63 ) == V_117 )
V_75 = F_43 ( & V_77 , & V_63 , V_4 , 1 ) ;
}
if ( V_75 ) {
int V_122 = V_123 ;
int V_124 ;
V_124 = F_75 ( V_79 , V_75 -> V_125 + V_75 -> V_22 -> V_126 ) ;
if ( V_90 -> V_106 != F_59 ( V_113 ) ||
V_51 -> V_119 != V_120 )
V_122 = V_127 ;
F_76 ( V_75 , V_110 , V_122 ,
V_124 ? V_128 : 0 ) ;
F_46 ( V_75 ) ;
}
V_98:
F_77 ( V_51 ) ;
return 0 ;
}
static void F_78 ( struct V_50 * V_51 )
{
F_63 ( V_51 ) ;
}
static int F_79 ( struct V_50 * V_51 , struct V_3 * V_4 ,
struct V_129 * V_130 , struct V_3 * V_131 )
{
struct V_89 * V_90 ;
if ( ! F_80 ( V_51 , F_55 ( V_4 ) ) )
goto V_132;
V_90 = F_64 ( V_51 ) ;
if ( V_90 -> V_104 != V_4 -> V_12 ||
V_4 -> V_39 & V_40 ||
V_51 -> V_119 == V_133 ||
V_51 -> V_119 == V_134 ||
V_90 -> V_105 != 4 )
goto V_132;
V_51 = F_81 ( V_51 , V_95 ) ;
if ( V_51 == NULL )
goto V_135;
memset ( F_72 ( V_51 ) , 0 , sizeof( struct V_136 ) ) ;
return F_62 ( V_107 , V_137 , V_51 , V_4 , NULL , F_63 ) ;
V_132:
F_18 ( V_51 ) ;
V_135:
return 0 ;
}
static int F_82 ( struct V_70 * V_70 , struct V_3 * V_4 , int V_138 )
{
if ( V_4 == NULL ) {
F_83 ( V_70 , V_139 ) = V_138 ;
return 0 ;
}
if ( F_84 ( V_4 ) ) {
F_85 ( F_84 ( V_4 ) , V_139 , V_138 ) ;
return 0 ;
}
return - V_140 ;
}
static int F_86 ( struct V_70 * V_70 , struct V_141 * V_142 ,
struct V_3 * V_4 )
{
T_1 V_143 = ( (struct V_144 * ) & V_142 -> V_145 ) -> V_146 . V_147 ;
T_1 V_148 = ( (struct V_144 * ) & V_142 -> V_149 ) -> V_146 . V_147 ;
if ( V_148 && V_148 != F_87 ( 0xFFFFFFFF ) )
return - V_13 ;
if ( ! V_4 && ( V_142 -> V_150 & V_151 ) ) {
V_4 = F_88 ( V_70 , V_142 -> V_152 . V_153 ,
V_142 -> V_152 . V_154 ) ;
if ( ! V_4 )
return - V_155 ;
}
if ( V_148 ) {
if ( F_71 ( & V_77 , V_70 , & V_143 , V_4 , 1 ) == NULL )
return - V_156 ;
return 0 ;
}
return F_82 ( V_70 , V_4 , 1 ) ;
}
static int F_89 ( struct V_70 * V_70 , struct V_141 * V_142 ,
struct V_3 * V_4 )
{
T_1 V_143 ;
struct V_16 * V_17 ;
int V_157 ;
if ( V_142 -> V_150 & V_158 )
return F_86 ( V_70 , V_142 , V_4 ) ;
V_143 = ( (struct V_144 * ) & V_142 -> V_145 ) -> V_146 . V_147 ;
if ( V_142 -> V_150 & V_159 )
V_142 -> V_150 |= V_151 ;
if ( V_4 == NULL ) {
struct V_67 * V_68 = F_35 ( V_70 , V_143 , 0 , V_160 , 0 ) ;
if ( F_36 ( V_68 ) )
return F_90 ( V_68 ) ;
V_4 = V_68 -> V_71 . V_4 ;
F_38 ( V_68 ) ;
if ( ! V_4 )
return - V_13 ;
}
switch ( V_4 -> type ) {
#if F_15 ( V_103 )
case V_7 :
if ( V_142 -> V_152 . V_153 != V_7 &&
V_142 -> V_152 . V_153 != V_6 &&
V_142 -> V_152 . V_153 != V_8 )
return - V_13 ;
break;
#endif
default:
if ( V_142 -> V_152 . V_153 != V_4 -> type )
return - V_13 ;
break;
}
V_17 = F_91 ( & V_77 , & V_143 , V_4 ) ;
V_157 = F_90 ( V_17 ) ;
if ( ! F_36 ( V_17 ) ) {
unsigned int V_122 = V_127 ;
if ( V_142 -> V_150 & V_159 )
V_122 = V_161 ;
V_157 = F_76 ( V_17 , ( V_142 -> V_150 & V_151 ) ?
V_142 -> V_152 . V_154 : NULL , V_122 ,
V_128 |
V_162 ) ;
F_46 ( V_17 ) ;
}
return V_157 ;
}
static unsigned int F_92 ( struct V_16 * V_17 )
{
if ( V_17 -> V_25 & V_161 )
return V_159 | V_151 ;
else if ( V_17 -> V_25 & V_48 )
return V_151 ;
else
return 0 ;
}
static int F_93 ( struct V_141 * V_142 , struct V_3 * V_4 )
{
T_1 V_143 = ( (struct V_144 * ) & V_142 -> V_145 ) -> V_146 . V_147 ;
struct V_16 * V_17 ;
int V_157 = - V_140 ;
V_17 = F_94 ( & V_77 , & V_143 , V_4 ) ;
if ( V_17 ) {
F_26 ( & V_17 -> V_59 ) ;
memcpy ( V_142 -> V_152 . V_154 , V_17 -> V_38 , V_4 -> V_12 ) ;
V_142 -> V_150 = F_92 ( V_17 ) ;
F_30 ( & V_17 -> V_59 ) ;
V_142 -> V_152 . V_153 = V_4 -> type ;
F_95 ( V_142 -> V_163 , V_4 -> V_164 , sizeof( V_142 -> V_163 ) ) ;
F_46 ( V_17 ) ;
V_157 = 0 ;
}
return V_157 ;
}
int F_96 ( struct V_3 * V_4 , T_1 V_143 )
{
struct V_16 * V_17 = F_94 ( & V_77 , & V_143 , V_4 ) ;
int V_157 = - V_140 ;
if ( V_17 ) {
if ( V_17 -> V_25 & ~ V_26 )
V_157 = F_76 ( V_17 , NULL , V_165 ,
V_128 |
V_162 ) ;
F_46 ( V_17 ) ;
}
return V_157 ;
}
static int F_97 ( struct V_70 * V_70 , struct V_141 * V_142 ,
struct V_3 * V_4 )
{
T_1 V_143 = ( (struct V_144 * ) & V_142 -> V_145 ) -> V_146 . V_147 ;
T_1 V_148 = ( (struct V_144 * ) & V_142 -> V_149 ) -> V_146 . V_147 ;
if ( V_148 == F_87 ( 0xFFFFFFFF ) )
return F_98 ( & V_77 , V_70 , & V_143 , V_4 ) ;
if ( V_148 )
return - V_13 ;
return F_82 ( V_70 , V_4 , 0 ) ;
}
static int F_99 ( struct V_70 * V_70 , struct V_141 * V_142 ,
struct V_3 * V_4 )
{
T_1 V_143 ;
if ( V_142 -> V_150 & V_158 )
return F_97 ( V_70 , V_142 , V_4 ) ;
V_143 = ( (struct V_144 * ) & V_142 -> V_145 ) -> V_146 . V_147 ;
if ( V_4 == NULL ) {
struct V_67 * V_68 = F_35 ( V_70 , V_143 , 0 , V_160 , 0 ) ;
if ( F_36 ( V_68 ) )
return F_90 ( V_68 ) ;
V_4 = V_68 -> V_71 . V_4 ;
F_38 ( V_68 ) ;
if ( ! V_4 )
return - V_13 ;
}
return F_96 ( V_4 , V_143 ) ;
}
int F_100 ( struct V_70 * V_70 , unsigned int V_166 , void T_6 * V_167 )
{
int V_157 ;
struct V_141 V_142 ;
struct V_3 * V_4 = NULL ;
switch ( V_166 ) {
case V_168 :
case V_169 :
if ( ! F_101 ( V_170 ) )
return - V_171 ;
case V_172 :
V_157 = F_102 ( & V_142 , V_167 , sizeof( struct V_141 ) ) ;
if ( V_157 )
return - V_173 ;
break;
default:
return - V_13 ;
}
if ( V_142 . V_145 . V_153 != V_174 )
return - V_175 ;
if ( ! ( V_142 . V_150 & V_158 ) &&
( V_142 . V_150 & ( V_176 | V_177 ) ) )
return - V_13 ;
if ( ! ( V_142 . V_150 & V_176 ) )
( (struct V_144 * ) & V_142 . V_149 ) -> V_146 . V_147 =
F_87 ( 0xFFFFFFFFUL ) ;
F_103 () ;
if ( V_142 . V_163 [ 0 ] ) {
V_157 = - V_155 ;
V_4 = F_104 ( V_70 , V_142 . V_163 ) ;
if ( V_4 == NULL )
goto V_98;
if ( ! V_142 . V_152 . V_153 )
V_142 . V_152 . V_153 = V_4 -> type ;
V_157 = - V_13 ;
if ( ( V_142 . V_150 & V_151 ) && V_142 . V_152 . V_153 != V_4 -> type )
goto V_98;
} else if ( V_166 == V_172 ) {
V_157 = - V_155 ;
goto V_98;
}
switch ( V_166 ) {
case V_168 :
V_157 = F_99 ( V_70 , & V_142 , V_4 ) ;
break;
case V_169 :
V_157 = F_89 ( V_70 , & V_142 , V_4 ) ;
break;
case V_172 :
V_157 = F_93 ( & V_142 , V_4 ) ;
break;
}
V_98:
F_105 () ;
if ( V_166 == V_172 && ! V_157 && F_106 ( V_167 , & V_142 , sizeof( V_142 ) ) )
V_157 = - V_173 ;
return V_157 ;
}
static int F_107 ( struct V_178 * V_179 , unsigned long V_180 ,
void * V_181 )
{
struct V_3 * V_4 = V_181 ;
switch ( V_180 ) {
case V_182 :
F_108 ( & V_77 , V_4 ) ;
F_109 ( F_12 ( V_4 ) , 0 ) ;
break;
default:
break;
}
return V_183 ;
}
void F_110 ( struct V_3 * V_4 )
{
F_111 ( & V_77 , V_4 ) ;
}
void T_7 F_112 ( void )
{
F_113 ( & V_77 ) ;
F_114 ( & V_184 ) ;
F_115 () ;
#ifdef F_116
F_117 ( NULL , & V_77 . V_22 , L_4 , NULL ) ;
#endif
F_118 ( & V_185 ) ;
}
static char * F_119 ( T_8 * V_186 , char * V_187 )
{
char V_188 , * V_189 ;
int V_75 ;
for ( V_75 = 0 , V_189 = V_187 ; V_75 < 6 ; V_75 ++ ) {
V_188 = ( V_186 -> V_190 [ V_75 ] >> 1 ) & 0x7F ;
if ( V_188 != ' ' )
* V_189 ++ = V_188 ;
}
* V_189 ++ = '-' ;
V_75 = ( V_186 -> V_190 [ 6 ] >> 1 ) & 0x0F ;
if ( V_75 > 9 ) {
* V_189 ++ = '1' ;
V_75 -= 10 ;
}
* V_189 ++ = V_75 + '0' ;
* V_189 ++ = '\0' ;
if ( * V_187 == '\0' || * V_187 == '-' )
return L_5 ;
return V_187 ;
}
static void F_120 ( struct V_191 * V_192 ,
struct V_16 * V_75 )
{
char V_193 [ V_194 ] ;
int V_195 , V_196 ;
char V_197 [ 16 ] ;
struct V_3 * V_4 = V_75 -> V_4 ;
int V_198 = V_4 -> type ;
F_121 ( & V_75 -> V_59 ) ;
#if F_15 ( V_32 )
if ( V_198 == V_33 || V_198 == V_35 )
F_119 ( ( T_8 * ) V_75 -> V_38 , V_193 ) ;
else {
#endif
for ( V_195 = 0 , V_196 = 0 ; V_195 < V_194 - 3 && V_196 < V_4 -> V_12 ; V_196 ++ ) {
V_193 [ V_195 ++ ] = F_122 ( V_75 -> V_38 [ V_196 ] ) ;
V_193 [ V_195 ++ ] = F_123 ( V_75 -> V_38 [ V_196 ] ) ;
V_193 [ V_195 ++ ] = ':' ;
}
if ( V_195 != 0 )
-- V_195 ;
V_193 [ V_195 ] = 0 ;
#if F_15 ( V_32 )
}
#endif
sprintf ( V_197 , L_6 , V_75 -> V_18 ) ;
F_124 ( V_192 , L_7 ,
V_197 , V_198 , F_92 ( V_75 ) , V_193 , V_4 -> V_164 ) ;
F_125 ( & V_75 -> V_59 ) ;
}
static void F_126 ( struct V_191 * V_192 ,
struct V_199 * V_75 )
{
struct V_3 * V_4 = V_75 -> V_4 ;
int V_198 = V_4 ? V_4 -> type : 0 ;
char V_197 [ 16 ] ;
sprintf ( V_197 , L_6 , V_75 -> V_200 ) ;
F_124 ( V_192 , L_7 ,
V_197 , V_198 , V_158 | V_159 , L_8 ,
V_4 ? V_4 -> V_164 : L_5 ) ;
}
static int F_127 ( struct V_191 * V_192 , void * V_201 )
{
if ( V_201 == V_202 ) {
F_128 ( V_192 , L_9
L_10 ) ;
} else {
struct V_203 * V_122 = V_192 -> V_204 ;
if ( V_122 -> V_39 & V_205 )
F_126 ( V_192 , V_201 ) ;
else
F_120 ( V_192 , V_201 ) ;
}
return 0 ;
}
static void * F_129 ( struct V_191 * V_192 , T_9 * V_206 )
{
return F_130 ( V_192 , V_206 , & V_77 , V_207 ) ;
}
static int F_131 ( struct V_208 * V_208 , struct V_209 * V_209 )
{
return F_132 ( V_208 , V_209 , & V_210 ,
sizeof( struct V_203 ) ) ;
}
static int T_10 F_133 ( struct V_70 * V_70 )
{
if ( ! F_134 ( V_70 , L_11 , V_211 , & V_212 ) )
return - V_213 ;
return 0 ;
}
static void T_11 F_135 ( struct V_70 * V_70 )
{
F_136 ( V_70 , L_11 ) ;
}
static int T_7 F_115 ( void )
{
return F_137 ( & V_214 ) ;
}
static int T_7 F_115 ( void )
{
return 0 ;
}
