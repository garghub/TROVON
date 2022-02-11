static void F_1 ( char * V_1 , T_1 * V_2 , unsigned int V_3 )
{
T_2 * V_4 = ( T_2 * ) V_2 ;
int V_5 ;
F_2 ( L_1 , V_1 ) ;
for ( V_5 = 0 ; V_5 < V_3 && V_5 < 128 ; V_5 += 4 ) {
if ( ! ( V_5 & 31 ) ) {
if ( V_5 )
F_2 ( L_2 ) ;
F_2 ( L_3 , V_5 ) ;
}
F_2 ( L_4 ,
V_4 [ V_5 ] , V_4 [ V_5 + 1 ] , V_4 [ V_5 + 2 ] , V_4 [ V_5 + 3 ] ) ;
}
F_2 ( L_2 ) ;
}
static inline void F_1 ( char * V_1 , T_1 * V_2 , unsigned int V_3 )
{
}
static inline struct V_6 * F_3 ( struct V_7 * V_8 )
{
return (struct V_6 * ) V_8 -> V_9 ;
}
static inline struct V_10 * F_4 ( struct V_6 * V_11 )
{
return (struct V_10 * ) & V_11 -> V_12 ;
}
static inline struct V_13 * F_5 ( struct V_6 * V_11 )
{
return (struct V_13 * ) & V_11 -> V_12 ;
}
static inline struct V_14 * F_6 ( struct V_6 * V_11 )
{
return (struct V_14 * ) & V_11 -> V_12 ;
}
static inline struct V_15 * F_7 ( struct V_6 * V_11 )
{
return (struct V_15 * ) & V_11 -> V_12 ;
}
static void F_8 ( struct V_6 * V_11 )
{
struct V_10 * V_16 = F_4 ( V_11 ) ;
struct V_15 * V_17 ;
struct V_14 * sin ;
struct V_13 * V_18 ;
char V_4 [ 128 ] ;
switch ( V_16 -> V_19 ) {
case V_20 :
V_18 = F_5 ( V_11 ) ;
F_9 ( V_4 , V_18 -> V_21 , sizeof( V_4 ) ) ;
V_11 -> V_22 [ V_23 ] =
F_10 ( V_4 , V_24 ) ;
break;
case V_25 :
( void ) F_11 ( V_16 , V_4 , sizeof( V_4 ) ) ;
V_11 -> V_22 [ V_23 ] =
F_10 ( V_4 , V_24 ) ;
sin = F_6 ( V_11 ) ;
snprintf ( V_4 , sizeof( V_4 ) , L_5 , F_12 ( sin -> V_26 . V_27 ) ) ;
break;
case V_28 :
( void ) F_11 ( V_16 , V_4 , sizeof( V_4 ) ) ;
V_11 -> V_22 [ V_23 ] =
F_10 ( V_4 , V_24 ) ;
V_17 = F_7 ( V_11 ) ;
snprintf ( V_4 , sizeof( V_4 ) , L_6 , & V_17 -> V_29 ) ;
break;
default:
F_13 () ;
}
V_11 -> V_22 [ V_30 ] = F_10 ( V_4 , V_24 ) ;
}
static void F_14 ( struct V_6 * V_11 )
{
struct V_10 * V_16 = F_4 ( V_11 ) ;
char V_4 [ 128 ] ;
snprintf ( V_4 , sizeof( V_4 ) , L_7 , F_15 ( V_16 ) ) ;
V_11 -> V_22 [ V_31 ] = F_10 ( V_4 , V_24 ) ;
snprintf ( V_4 , sizeof( V_4 ) , L_8 , F_15 ( V_16 ) ) ;
V_11 -> V_22 [ V_32 ] = F_10 ( V_4 , V_24 ) ;
}
static void F_16 ( struct V_6 * V_11 ,
const char * V_33 ,
const char * V_34 )
{
V_11 -> V_22 [ V_35 ] = V_33 ;
V_11 -> V_22 [ V_36 ] = V_34 ;
F_8 ( V_11 ) ;
F_14 ( V_11 ) ;
}
static void F_17 ( struct V_6 * V_11 )
{
F_18 ( V_11 -> V_22 [ V_32 ] ) ;
F_18 ( V_11 -> V_22 [ V_31 ] ) ;
F_14 ( V_11 ) ;
}
static void F_19 ( struct V_6 * V_11 )
{
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
switch ( V_37 ) {
case V_35 :
case V_36 :
continue;
default:
F_18 ( V_11 -> V_22 [ V_37 ] ) ;
}
}
static int F_20 ( struct V_39 * V_7 , struct V_10 * V_12 , int V_40 , struct V_41 * V_42 , unsigned int V_43 , int V_44 )
{
struct V_45 V_1 = {
. V_46 = V_12 ,
. V_47 = V_40 ,
. V_48 = V_49 | ( V_44 ? V_50 : 0 ) ,
} ;
struct V_41 V_51 = {
. V_52 = V_42 -> V_52 + V_43 ,
. V_53 = V_42 -> V_53 - V_43 ,
} ;
if ( V_51 . V_53 != 0 )
return F_21 ( V_7 , & V_1 , & V_51 , 1 , V_51 . V_53 ) ;
return F_21 ( V_7 , & V_1 , NULL , 0 , 0 ) ;
}
static int F_22 ( struct V_39 * V_7 , struct V_54 * V_55 , unsigned int V_43 , int V_44 , bool V_56 , int * V_57 )
{
T_3 (* F_23)( struct V_39 * V_7 , struct V_58 * V_58 ,
int V_59 , T_4 V_60 , int V_61 );
struct V_58 * * V_62 ;
unsigned int V_63 ;
int V_64 ;
V_63 = V_55 -> V_65 - V_43 ;
V_43 += V_55 -> V_66 ;
V_62 = V_55 -> V_67 + ( V_43 >> V_68 ) ;
V_43 &= ~ V_69 ;
F_23 = V_7 -> V_70 -> V_71 ;
if ( ! V_56 )
F_23 = V_72 ;
for(; ; ) {
unsigned int V_73 = F_24 (unsigned int, PAGE_SIZE - base, remainder) ;
int V_61 = V_49 ;
V_63 -= V_73 ;
if ( V_63 != 0 || V_44 )
V_61 |= V_50 ;
V_64 = F_23 ( V_7 , * V_62 , V_43 , V_73 , V_61 ) ;
if ( V_63 == 0 || V_64 != V_73 )
break;
* V_57 += V_64 ;
V_62 ++ ;
V_43 = 0 ;
}
if ( V_64 > 0 ) {
* V_57 += V_64 ;
V_64 = 0 ;
}
return V_64 ;
}
static int F_25 ( struct V_39 * V_7 , struct V_10 * V_12 , int V_40 , struct V_54 * V_55 , unsigned int V_43 , bool V_56 , int * V_57 )
{
unsigned int V_63 = V_55 -> V_73 - V_43 ;
int V_64 = 0 ;
int V_74 = 0 ;
if ( F_26 ( ! V_7 ) )
return - V_75 ;
F_27 ( V_76 , & V_7 -> V_61 ) ;
if ( V_43 != 0 ) {
V_12 = NULL ;
V_40 = 0 ;
}
if ( V_43 < V_55 -> V_77 [ 0 ] . V_53 || V_12 != NULL ) {
unsigned int V_73 = V_55 -> V_77 [ 0 ] . V_53 - V_43 ;
V_63 -= V_73 ;
V_64 = F_20 ( V_7 , V_12 , V_40 , & V_55 -> V_77 [ 0 ] , V_43 , V_63 != 0 ) ;
if ( V_63 == 0 || V_64 != V_73 )
goto V_78;
* V_57 += V_64 ;
V_43 = 0 ;
} else
V_43 -= V_55 -> V_77 [ 0 ] . V_53 ;
if ( V_43 < V_55 -> V_65 ) {
unsigned int V_73 = V_55 -> V_65 - V_43 ;
V_63 -= V_73 ;
V_64 = F_22 ( V_7 , V_55 , V_43 , V_63 != 0 , V_56 , & V_74 ) ;
* V_57 += V_74 ;
if ( V_63 == 0 || V_74 != V_73 )
goto V_78;
V_43 = 0 ;
} else
V_43 -= V_55 -> V_65 ;
if ( V_43 >= V_55 -> V_79 [ 0 ] . V_53 )
return 0 ;
V_64 = F_20 ( V_7 , NULL , 0 , & V_55 -> V_79 [ 0 ] , V_43 , 0 ) ;
V_78:
if ( V_64 > 0 ) {
* V_57 += V_64 ;
V_64 = 0 ;
}
return V_64 ;
}
static void F_28 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_29 ( V_81 -> V_84 -> V_85 , struct V_82 , V_11 ) ;
V_83 -> V_86 -> V_87 -- ;
F_27 ( V_76 , & V_83 -> V_7 -> V_61 ) ;
}
static int F_30 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_7 * V_8 = V_83 -> V_86 ;
int V_90 = - V_91 ;
F_2 ( L_9 ,
V_81 -> V_92 , V_89 -> V_93 - V_89 -> V_94 ,
V_89 -> V_93 ) ;
F_31 ( & V_11 -> V_95 ) ;
if ( F_32 ( V_11 ) ) {
if ( F_33 ( V_76 , & V_83 -> V_7 -> V_61 ) ) {
F_34 ( V_96 , & V_83 -> V_7 -> V_61 ) ;
V_8 -> V_87 ++ ;
F_35 ( V_81 , F_28 ) ;
}
} else {
F_27 ( V_76 , & V_83 -> V_7 -> V_61 ) ;
V_90 = - V_97 ;
}
F_36 ( & V_11 -> V_95 ) ;
V_8 -> V_98 ( V_8 ) ;
return V_90 ;
}
static inline void F_37 ( struct V_54 * V_4 )
{
T_1 V_99 = V_4 -> V_73 - sizeof( V_100 ) ;
V_100 * V_43 = V_4 -> V_77 [ 0 ] . V_52 ;
* V_43 = F_38 ( V_101 | V_99 ) ;
}
static int F_39 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_55 = & V_89 -> V_102 ;
int V_103 ;
int V_74 = 0 ;
F_37 ( & V_89 -> V_102 ) ;
F_1 ( L_10 ,
V_89 -> V_104 -> V_52 , V_89 -> V_104 -> V_53 ) ;
V_103 = F_25 ( V_83 -> V_7 , NULL , 0 , V_55 , V_89 -> V_94 ,
true , & V_74 ) ;
F_2 ( L_11 ,
V_105 , V_55 -> V_73 - V_89 -> V_94 , V_103 ) ;
if ( V_103 == - V_91 && F_40 ( V_83 -> V_86 ) )
V_103 = - V_106 ;
if ( F_41 ( V_74 > 0 ) || V_103 == 0 ) {
V_89 -> V_94 += V_74 ;
V_89 -> V_107 += V_74 ;
if ( F_41 ( V_89 -> V_94 >= V_89 -> V_93 ) ) {
V_89 -> V_94 = 0 ;
return 0 ;
}
V_103 = - V_91 ;
}
switch ( V_103 ) {
case - V_106 :
break;
case - V_91 :
V_103 = F_30 ( V_81 ) ;
break;
default:
F_2 ( L_12 ,
- V_103 ) ;
case - V_108 :
F_42 ( V_11 ) ;
V_103 = - V_97 ;
}
return V_103 ;
}
static int F_43 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_55 = & V_89 -> V_102 ;
int V_74 = 0 ;
int V_103 ;
F_1 ( L_10 ,
V_89 -> V_104 -> V_52 ,
V_89 -> V_104 -> V_53 ) ;
if ( ! F_44 ( V_11 ) )
return - V_97 ;
V_103 = F_25 ( V_83 -> V_7 , F_4 ( V_11 ) , V_11 -> V_40 ,
V_55 , V_89 -> V_94 , true , & V_74 ) ;
F_2 ( L_13 ,
V_55 -> V_73 - V_89 -> V_94 , V_103 ) ;
if ( V_103 == - V_109 )
goto V_110;
if ( V_103 == - V_91 && F_40 ( V_83 -> V_86 ) )
V_103 = - V_106 ;
if ( V_74 > 0 || V_103 == 0 ) {
V_89 -> V_107 += V_74 ;
if ( V_74 >= V_89 -> V_93 )
return 0 ;
V_103 = - V_91 ;
}
V_110:
switch ( V_103 ) {
case - V_75 :
V_103 = - V_97 ;
break;
case - V_91 :
V_103 = F_30 ( V_81 ) ;
break;
default:
F_2 ( L_12 ,
- V_103 ) ;
case - V_111 :
case - V_106 :
case - V_108 :
case - V_112 :
case - V_109 :
F_27 ( V_76 , & V_83 -> V_7 -> V_61 ) ;
}
return V_103 ;
}
static int F_45 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_55 = & V_89 -> V_102 ;
bool V_56 = true ;
int V_103 ;
int V_74 ;
F_37 ( & V_89 -> V_102 ) ;
F_1 ( L_10 ,
V_89 -> V_104 -> V_52 ,
V_89 -> V_104 -> V_53 ) ;
if ( V_81 -> V_113 & V_114 )
V_56 = false ;
while ( 1 ) {
V_74 = 0 ;
V_103 = F_25 ( V_83 -> V_7 , NULL , 0 , V_55 ,
V_89 -> V_94 , V_56 , & V_74 ) ;
F_2 ( L_14 ,
V_55 -> V_73 - V_89 -> V_94 , V_103 ) ;
V_89 -> V_94 += V_74 ;
V_89 -> V_107 += V_74 ;
if ( F_41 ( V_89 -> V_94 >= V_89 -> V_93 ) ) {
V_89 -> V_94 = 0 ;
return 0 ;
}
if ( V_103 < 0 )
break;
if ( V_74 == 0 ) {
V_103 = - V_91 ;
break;
}
}
if ( V_103 == - V_91 && F_46 ( V_83 -> V_86 ) )
V_103 = - V_106 ;
switch ( V_103 ) {
case - V_75 :
V_103 = - V_97 ;
break;
case - V_91 :
V_103 = F_30 ( V_81 ) ;
break;
default:
F_2 ( L_12 ,
- V_103 ) ;
case - V_115 :
case - V_112 :
case - V_97 :
case - V_116 :
case - V_106 :
case - V_108 :
F_27 ( V_76 , & V_83 -> V_7 -> V_61 ) ;
}
return V_103 ;
}
static void F_47 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_88 * V_89 ;
if ( V_81 != V_11 -> V_117 )
return;
if ( V_81 == NULL )
goto V_118;
V_89 = V_81 -> V_84 ;
if ( V_89 == NULL )
goto V_118;
if ( V_89 -> V_94 == 0 )
goto V_118;
if ( V_89 -> V_94 == V_89 -> V_102 . V_73 )
goto V_118;
F_34 ( V_119 , & V_11 -> V_120 ) ;
V_118:
F_48 ( V_11 , V_81 ) ;
}
static void F_49 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_83 -> V_121 = V_8 -> V_122 ;
V_83 -> V_123 = V_8 -> V_124 ;
V_83 -> V_125 = V_8 -> V_98 ;
V_83 -> V_126 = V_8 -> V_127 ;
}
static void F_50 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_8 -> V_122 = V_83 -> V_121 ;
V_8 -> V_124 = V_83 -> V_123 ;
V_8 -> V_98 = V_83 -> V_125 ;
V_8 -> V_127 = V_83 -> V_126 ;
}
static void F_51 ( struct V_6 * V_11 )
{
F_52 () ;
F_27 ( V_119 , & V_11 -> V_120 ) ;
F_27 ( V_128 , & V_11 -> V_120 ) ;
F_53 () ;
}
static void F_54 ( struct V_6 * V_11 )
{
F_51 ( V_11 ) ;
F_55 ( V_11 ) ;
}
static void F_56 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
int V_64 ;
F_57 ( & V_8 -> V_129 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
V_64 = - V_8 -> V_130 ;
if ( V_64 == 0 )
goto V_78;
if ( V_8 -> V_131 == V_132 )
F_54 ( V_11 ) ;
F_2 ( L_15 ,
V_11 , - V_64 ) ;
F_58 ( V_11 , V_8 -> V_133 , V_64 ) ;
F_59 ( V_11 , V_64 ) ;
V_78:
F_60 ( & V_8 -> V_129 ) ;
}
static void F_61 ( struct V_82 * V_83 )
{
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_7 * V_8 = V_83 -> V_86 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
if ( V_8 == NULL )
return;
if ( F_62 ( & V_83 -> V_11 . V_134 ) )
F_63 ( V_8 ) ;
F_64 ( V_7 , V_135 ) ;
F_65 ( & V_8 -> V_129 ) ;
V_83 -> V_86 = NULL ;
V_83 -> V_7 = NULL ;
V_8 -> V_9 = NULL ;
F_50 ( V_83 , V_8 ) ;
F_66 ( V_11 ) ;
F_67 ( & V_8 -> V_129 ) ;
F_51 ( V_11 ) ;
F_68 ( V_11 , V_7 ) ;
F_69 ( V_7 ) ;
}
static void F_42 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_2 ( L_16 , V_11 ) ;
F_61 ( V_83 ) ;
V_11 -> V_136 = 0 ;
F_55 ( V_11 ) ;
}
static void F_70 ( struct V_6 * V_11 )
{
F_2 ( L_17 ,
V_11 ) ;
F_55 ( V_11 ) ;
}
static void F_71 ( struct V_6 * V_11 )
{
F_19 ( V_11 ) ;
F_72 ( V_11 ) ;
}
static void F_73 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 ,
struct V_82 , V_11 ) ;
F_2 ( L_18 , V_11 ) ;
F_74 ( & V_83 -> V_137 ) ;
F_42 ( V_11 ) ;
F_71 ( V_11 ) ;
F_75 ( V_138 ) ;
}
static int F_76 ( struct V_54 * V_55 , struct V_139 * V_140 )
{
struct V_141 V_142 = {
. V_140 = V_140 ,
. V_59 = sizeof( V_100 ) ,
. V_3 = V_140 -> V_73 - sizeof( V_100 ) ,
} ;
if ( F_77 ( V_55 , 0 , & V_142 , V_143 ) < 0 )
return - 1 ;
if ( V_142 . V_3 )
return - 1 ;
return 0 ;
}
static void F_78 ( struct V_7 * V_8 )
{
struct V_80 * V_81 ;
struct V_6 * V_11 ;
struct V_88 * V_144 ;
struct V_139 * V_140 ;
int V_64 , V_145 , V_146 ;
T_1 V_147 ;
T_5 * V_148 ;
F_57 ( & V_8 -> V_129 ) ;
F_2 ( L_19 , V_105 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 == NULL )
goto V_78;
V_140 = F_79 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_140 == NULL )
goto V_78;
V_145 = V_140 -> V_73 - sizeof( V_100 ) ;
if ( V_145 < 4 ) {
F_2 ( L_20 , V_145 ) ;
goto V_149;
}
V_148 = F_80 ( V_140 , sizeof( V_100 ) , sizeof( V_147 ) , & V_147 ) ;
if ( V_148 == NULL )
goto V_149;
F_81 ( & V_11 -> V_95 ) ;
V_144 = F_82 ( V_11 , * V_148 ) ;
if ( ! V_144 )
goto V_150;
V_81 = V_144 -> V_151 ;
V_146 = V_144 -> V_152 . V_153 ;
if ( V_146 > V_145 )
V_146 = V_145 ;
if ( F_76 ( & V_144 -> V_152 , V_140 ) ) {
F_2 ( L_21 ) ;
goto V_150;
}
F_83 ( V_81 , V_146 ) ;
V_150:
F_84 ( & V_11 -> V_95 ) ;
V_149:
F_85 ( V_8 , V_140 ) ;
V_78:
F_60 ( & V_8 -> V_129 ) ;
}
static void F_86 ( struct V_7 * V_8 )
{
struct V_80 * V_81 ;
struct V_6 * V_11 ;
struct V_88 * V_144 ;
struct V_139 * V_140 ;
int V_64 , V_145 , V_146 ;
T_1 V_147 ;
T_5 * V_148 ;
F_57 ( & V_8 -> V_129 ) ;
F_2 ( L_22 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
if ( ( V_140 = F_79 ( V_8 , 0 , 1 , & V_64 ) ) == NULL )
goto V_78;
V_145 = V_140 -> V_73 - sizeof( struct V_154 ) ;
if ( V_145 < 4 ) {
F_2 ( L_23 , V_145 ) ;
goto V_149;
}
V_148 = F_80 ( V_140 , sizeof( struct V_154 ) ,
sizeof( V_147 ) , & V_147 ) ;
if ( V_148 == NULL )
goto V_149;
F_81 ( & V_11 -> V_95 ) ;
V_144 = F_82 ( V_11 , * V_148 ) ;
if ( ! V_144 )
goto V_150;
V_81 = V_144 -> V_151 ;
if ( ( V_146 = V_144 -> V_152 . V_153 ) > V_145 )
V_146 = V_145 ;
if ( F_87 ( & V_144 -> V_152 , V_140 ) ) {
F_88 ( V_8 , V_155 ) ;
goto V_150;
}
F_88 ( V_8 , V_156 ) ;
F_89 ( V_11 , V_81 , V_146 ) ;
F_83 ( V_81 , V_146 ) ;
V_150:
F_84 ( & V_11 -> V_95 ) ;
V_149:
F_85 ( V_8 , V_140 ) ;
V_78:
F_60 ( & V_8 -> V_129 ) ;
}
static void F_90 ( struct V_6 * V_11 )
{
F_91 ( V_11 ) ;
}
static inline void F_92 ( struct V_6 * V_11 , struct V_141 * V_142 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
T_4 V_73 , V_157 ;
char * V_158 ;
V_158 = ( ( char * ) & V_83 -> V_159 ) + V_83 -> V_160 ;
V_73 = sizeof( V_83 -> V_159 ) - V_83 -> V_160 ;
V_157 = V_143 ( V_142 , V_158 , V_73 ) ;
V_83 -> V_160 += V_157 ;
if ( V_157 != V_73 )
return;
V_83 -> V_161 = F_12 ( V_83 -> V_159 ) ;
if ( V_83 -> V_161 & V_101 )
V_83 -> V_162 |= V_163 ;
else
V_83 -> V_162 &= ~ V_163 ;
V_83 -> V_161 &= V_164 ;
V_83 -> V_162 &= ~ V_165 ;
V_83 -> V_160 = 0 ;
if ( F_26 ( V_83 -> V_161 < 8 ) ) {
F_2 ( L_24 ) ;
F_90 ( V_11 ) ;
return;
}
F_2 ( L_25 ,
V_83 -> V_161 ) ;
}
static void F_93 ( struct V_82 * V_83 )
{
if ( V_83 -> V_160 == V_83 -> V_161 ) {
V_83 -> V_162 |= V_165 ;
V_83 -> V_160 = 0 ;
if ( V_83 -> V_162 & V_163 ) {
V_83 -> V_162 &= ~ V_166 ;
V_83 -> V_162 |= V_167 ;
V_83 -> V_168 = 0 ;
}
}
}
static inline void F_94 ( struct V_82 * V_83 , struct V_141 * V_142 )
{
T_4 V_73 , V_157 ;
char * V_158 ;
V_73 = sizeof( V_83 -> V_169 ) - V_83 -> V_160 ;
F_2 ( L_26 , V_73 ) ;
V_158 = ( ( char * ) & V_83 -> V_169 ) + V_83 -> V_160 ;
V_157 = V_143 ( V_142 , V_158 , V_73 ) ;
V_83 -> V_160 += V_157 ;
if ( V_157 != V_73 )
return;
V_83 -> V_162 &= ~ V_167 ;
V_83 -> V_162 |= V_170 ;
V_83 -> V_168 = 4 ;
F_2 ( L_27 ,
( V_83 -> V_162 & V_171 ) ? L_28
: L_29 ,
F_12 ( V_83 -> V_169 ) ) ;
F_93 ( V_83 ) ;
}
static inline void F_95 ( struct V_82 * V_83 ,
struct V_141 * V_142 )
{
T_4 V_73 , V_157 ;
T_1 V_59 ;
char * V_158 ;
V_59 = V_83 -> V_160 - sizeof( V_83 -> V_169 ) ;
V_73 = sizeof( V_83 -> V_172 ) - V_59 ;
F_2 ( L_30 , V_73 ) ;
V_158 = ( ( char * ) & V_83 -> V_172 ) + V_59 ;
V_157 = V_143 ( V_142 , V_158 , V_73 ) ;
V_83 -> V_160 += V_157 ;
if ( V_157 != V_73 )
return;
V_83 -> V_162 &= ~ V_170 ;
switch ( F_12 ( V_83 -> V_172 ) ) {
case V_173 :
V_83 -> V_162 |= V_174 ;
V_83 -> V_162 |= V_166 ;
V_83 -> V_162 |= V_171 ;
break;
case V_175 :
V_83 -> V_162 |= V_174 ;
V_83 -> V_162 |= V_166 ;
V_83 -> V_162 &= ~ V_171 ;
break;
default:
F_2 ( L_31 ) ;
F_90 ( & V_83 -> V_11 ) ;
}
F_93 ( V_83 ) ;
}
static inline void F_96 ( struct V_6 * V_11 ,
struct V_141 * V_142 ,
struct V_88 * V_89 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_176 ;
T_4 V_73 ;
T_3 V_177 ;
V_176 = & V_89 -> V_152 ;
if ( V_83 -> V_162 & V_174 ) {
memcpy ( V_176 -> V_77 [ 0 ] . V_52 + V_83 -> V_168 ,
& V_83 -> V_172 ,
sizeof( V_83 -> V_172 ) ) ;
V_83 -> V_168 += sizeof( V_83 -> V_172 ) ;
V_83 -> V_162 &= ~ V_174 ;
}
V_73 = V_142 -> V_3 ;
if ( V_73 > V_83 -> V_161 - V_83 -> V_160 ) {
struct V_141 V_178 ;
V_73 = V_83 -> V_161 - V_83 -> V_160 ;
memcpy ( & V_178 , V_142 , sizeof( V_178 ) ) ;
V_178 . V_3 = V_73 ;
V_177 = F_77 ( V_176 , V_83 -> V_168 ,
& V_178 , V_143 ) ;
V_142 -> V_3 -= V_177 ;
V_142 -> V_59 += V_177 ;
} else
V_177 = F_77 ( V_176 , V_83 -> V_168 ,
V_142 , V_143 ) ;
if ( V_177 > 0 ) {
V_83 -> V_168 += V_177 ;
V_83 -> V_160 += V_177 ;
}
if ( V_177 != V_73 ) {
V_83 -> V_162 &= ~ V_166 ;
F_2 ( L_32 ,
F_12 ( V_83 -> V_169 ) ) ;
F_2 ( L_33
L_34 ,
V_11 , V_83 -> V_168 ,
V_83 -> V_160 , V_83 -> V_161 ) ;
return;
}
F_2 ( L_35 ,
F_12 ( V_83 -> V_169 ) , V_177 ) ;
F_2 ( L_36
L_37 , V_11 , V_83 -> V_168 ,
V_83 -> V_160 , V_83 -> V_161 ) ;
if ( V_83 -> V_168 == V_89 -> V_152 . V_153 )
V_83 -> V_162 &= ~ V_166 ;
else if ( V_83 -> V_160 == V_83 -> V_161 ) {
if ( V_83 -> V_162 & V_163 )
V_83 -> V_162 &= ~ V_166 ;
}
}
static inline int F_97 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_2 ( L_38 , F_12 ( V_83 -> V_169 ) ) ;
F_81 ( & V_11 -> V_95 ) ;
V_89 = F_82 ( V_11 , V_83 -> V_169 ) ;
if ( ! V_89 ) {
F_2 ( L_39 ,
F_12 ( V_83 -> V_169 ) ) ;
F_84 ( & V_11 -> V_95 ) ;
return - 1 ;
}
F_96 ( V_11 , V_142 , V_89 ) ;
if ( ! ( V_83 -> V_162 & V_166 ) )
F_83 ( V_89 -> V_151 , V_83 -> V_168 ) ;
F_84 ( & V_11 -> V_95 ) ;
return 0 ;
}
static int F_98 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_81 ( & V_11 -> V_95 ) ;
V_89 = F_99 ( V_11 , V_83 -> V_169 ) ;
if ( V_89 == NULL ) {
F_84 ( & V_11 -> V_95 ) ;
F_100 ( V_179 L_40 ) ;
F_91 ( V_11 ) ;
return - 1 ;
}
F_2 ( L_41 , F_12 ( V_89 -> V_180 ) ) ;
F_96 ( V_11 , V_142 , V_89 ) ;
if ( ! ( V_83 -> V_162 & V_166 ) )
F_101 ( V_89 , V_83 -> V_168 ) ;
F_84 ( & V_11 -> V_95 ) ;
return 0 ;
}
static inline int F_102 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
return ( V_83 -> V_162 & V_171 ) ?
F_97 ( V_11 , V_142 ) :
F_98 ( V_11 , V_142 ) ;
}
static inline int F_102 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
return F_97 ( V_11 , V_142 ) ;
}
static void F_103 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( F_102 ( V_11 , V_142 ) == 0 )
F_93 ( V_83 ) ;
else {
V_83 -> V_162 &= ~ V_166 ;
}
}
static inline void F_104 ( struct V_82 * V_83 , struct V_141 * V_142 )
{
T_4 V_73 ;
V_73 = V_83 -> V_161 - V_83 -> V_160 ;
if ( V_73 > V_142 -> V_3 )
V_73 = V_142 -> V_3 ;
V_142 -> V_3 -= V_73 ;
V_142 -> V_59 += V_73 ;
V_83 -> V_160 += V_73 ;
F_2 ( L_42 , V_73 ) ;
F_93 ( V_83 ) ;
}
static int F_105 ( T_6 * V_181 , struct V_139 * V_140 , unsigned int V_59 , T_4 V_73 )
{
struct V_6 * V_11 = V_181 -> V_182 . V_183 ;
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_141 V_142 = {
. V_140 = V_140 ,
. V_59 = V_59 ,
. V_3 = V_73 ,
} ;
F_2 ( L_43 ) ;
do {
F_106 ( V_83 ) ;
if ( V_83 -> V_162 & V_165 ) {
F_92 ( V_11 , & V_142 ) ;
continue;
}
if ( V_83 -> V_162 & V_167 ) {
F_94 ( V_83 , & V_142 ) ;
continue;
}
if ( V_83 -> V_162 & V_170 ) {
F_95 ( V_83 , & V_142 ) ;
continue;
}
if ( V_83 -> V_162 & V_166 ) {
F_103 ( V_11 , & V_142 ) ;
continue;
}
F_104 ( V_83 , & V_142 ) ;
} while ( V_142 . V_3 );
F_106 ( V_83 ) ;
F_2 ( L_44 ) ;
return V_73 - V_142 . V_3 ;
}
static void F_107 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
T_6 V_181 ;
int V_184 ;
unsigned long V_185 = 0 ;
F_2 ( L_45 ) ;
F_57 ( & V_8 -> V_129 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) ) {
V_184 = 0 ;
goto V_78;
}
if ( V_11 -> V_136 )
V_11 -> V_136 = 0 ;
V_181 . V_182 . V_183 = V_11 ;
do {
V_181 . V_3 = 65536 ;
V_184 = F_108 ( V_8 , & V_181 , F_105 ) ;
if ( V_184 > 0 )
V_185 += V_184 ;
} while ( V_184 > 0 );
V_78:
F_109 ( V_11 , V_184 , V_185 ) ;
F_60 ( & V_8 -> V_129 ) ;
}
static void F_110 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
struct V_82 * V_83 ;
F_57 ( & V_8 -> V_129 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
F_2 ( L_46 , V_11 ) ;
F_2 ( L_47 ,
V_8 -> V_131 , F_32 ( V_11 ) ,
F_111 ( V_8 , V_186 ) ,
F_111 ( V_8 , V_187 ) ,
V_8 -> V_188 ) ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_112 ( V_11 , V_8 -> V_133 ) ;
switch ( V_8 -> V_131 ) {
case V_189 :
F_81 ( & V_11 -> V_95 ) ;
if ( ! F_113 ( V_11 ) ) {
V_83 -> V_160 = 0 ;
V_83 -> V_161 = 0 ;
V_83 -> V_168 = 0 ;
V_83 -> V_162 =
V_165 | V_167 ;
V_11 -> V_190 ++ ;
F_27 ( V_191 , & V_83 -> V_192 ) ;
F_114 ( V_11 ) ;
F_59 ( V_11 , - V_91 ) ;
}
F_84 ( & V_11 -> V_95 ) ;
break;
case V_193 :
V_11 -> V_190 ++ ;
V_11 -> V_136 = 0 ;
F_34 ( V_128 , & V_11 -> V_120 ) ;
F_52 () ;
F_27 ( V_194 , & V_11 -> V_120 ) ;
F_27 ( V_119 , & V_11 -> V_120 ) ;
F_53 () ;
break;
case V_195 :
V_11 -> V_190 ++ ;
F_27 ( V_194 , & V_11 -> V_120 ) ;
F_90 ( V_11 ) ;
case V_196 :
if ( V_11 -> V_136 < V_197 )
V_11 -> V_136 = V_197 ;
break;
case V_198 :
F_34 ( V_128 , & V_11 -> V_120 ) ;
F_52 () ;
F_27 ( V_194 , & V_11 -> V_120 ) ;
F_53 () ;
break;
case V_132 :
if ( F_115 ( V_191 ,
& V_83 -> V_192 ) )
F_114 ( V_11 ) ;
F_54 ( V_11 ) ;
}
V_78:
F_60 ( & V_8 -> V_129 ) ;
}
static void F_116 ( struct V_7 * V_8 )
{
struct V_39 * V_7 ;
struct V_6 * V_11 ;
if ( F_26 ( ! ( V_7 = V_8 -> V_133 ) ) )
return;
F_27 ( V_96 , & V_7 -> V_61 ) ;
if ( F_26 ( ! ( V_11 = F_3 ( V_8 ) ) ) )
return;
if ( F_115 ( V_76 , & V_7 -> V_61 ) == 0 )
return;
F_117 ( V_11 ) ;
}
static void F_118 ( struct V_7 * V_8 )
{
F_57 ( & V_8 -> V_129 ) ;
if ( F_40 ( V_8 ) )
F_116 ( V_8 ) ;
F_60 ( & V_8 -> V_129 ) ;
}
static void F_119 ( struct V_7 * V_8 )
{
F_57 ( & V_8 -> V_129 ) ;
if ( F_46 ( V_8 ) )
F_116 ( V_8 ) ;
F_60 ( & V_8 -> V_129 ) ;
}
static void F_120 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_7 * V_8 = V_83 -> V_86 ;
if ( V_83 -> V_199 ) {
V_8 -> V_200 |= V_201 ;
V_8 -> V_202 = V_83 -> V_199 * V_11 -> V_203 * 2 ;
}
if ( V_83 -> V_204 ) {
V_8 -> V_200 |= V_205 ;
V_8 -> V_206 = V_83 -> V_204 * V_11 -> V_203 * 2 ;
V_8 -> V_98 ( V_8 ) ;
}
}
static void F_121 ( struct V_6 * V_11 , T_4 V_204 , T_4 V_199 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_83 -> V_204 = 0 ;
if ( V_204 )
V_83 -> V_204 = V_204 + 1024 ;
V_83 -> V_199 = 0 ;
if ( V_199 )
V_83 -> V_199 = V_199 + 1024 ;
F_120 ( V_11 ) ;
}
static void F_122 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
F_89 ( V_11 , V_81 , - V_207 ) ;
}
static unsigned short F_123 ( void )
{
unsigned short V_208 = V_209 - V_210 ;
unsigned short rand = ( unsigned short ) F_124 () % V_208 ;
return rand + V_210 ;
}
static void F_125 ( struct V_39 * V_7 )
{
int V_211 = 1 ;
F_126 ( V_7 , V_212 , V_213 ,
( char * ) & V_211 , sizeof( V_211 ) ) ;
}
static unsigned short F_127 ( struct V_39 * V_7 )
{
struct V_214 V_4 ;
int V_153 ;
unsigned short V_215 = 0 ;
if ( F_128 ( V_7 , (struct V_10 * ) & V_4 , & V_153 ) < 0 )
goto V_78;
switch ( V_4 . V_216 ) {
case V_28 :
V_215 = F_129 ( ( (struct V_15 * ) & V_4 ) -> V_217 ) ;
break;
case V_25 :
V_215 = F_129 ( ( (struct V_14 * ) & V_4 ) -> V_218 ) ;
}
V_78:
return V_215 ;
}
static void F_130 ( struct V_6 * V_11 , unsigned short V_215 )
{
F_2 ( L_48 , V_11 , V_215 ) ;
F_131 ( F_4 ( V_11 ) , V_215 ) ;
F_17 ( V_11 ) ;
}
static void F_132 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
if ( V_83 -> V_219 == 0 )
V_83 -> V_219 = F_127 ( V_7 ) ;
}
static unsigned short F_133 ( struct V_82 * V_83 )
{
unsigned short V_215 = V_83 -> V_219 ;
if ( V_215 == 0 && V_83 -> V_11 . V_220 )
V_215 = F_123 () ;
return V_215 ;
}
static unsigned short F_134 ( struct V_82 * V_83 , unsigned short V_215 )
{
if ( V_83 -> V_219 != 0 )
V_83 -> V_219 = 0 ;
if ( ! V_83 -> V_11 . V_220 )
return 0 ;
if ( V_215 <= V_210 || V_215 > V_209 )
return V_209 ;
return -- V_215 ;
}
static int F_135 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
struct V_214 V_221 ;
int V_64 , V_222 = 0 ;
unsigned short V_215 = F_133 ( V_83 ) ;
unsigned short V_223 ;
if ( V_215 == 0 )
return 0 ;
memcpy ( & V_221 , & V_83 -> V_224 , V_83 -> V_11 . V_40 ) ;
do {
F_131 ( (struct V_10 * ) & V_221 , V_215 ) ;
V_64 = F_136 ( V_7 , (struct V_10 * ) & V_221 ,
V_83 -> V_11 . V_40 ) ;
if ( V_64 == 0 ) {
V_83 -> V_219 = V_215 ;
break;
}
V_223 = V_215 ;
V_215 = F_134 ( V_83 , V_215 ) ;
if ( V_215 > V_223 )
V_222 ++ ;
} while ( V_64 == - V_116 && V_222 != 2 );
if ( V_221 . V_216 == V_25 )
F_2 ( L_49 , V_105 ,
& ( (struct V_14 * ) & V_221 ) -> V_26 ,
V_215 , V_64 ? L_50 : L_51 , V_64 ) ;
else
F_2 ( L_52 , V_105 ,
& ( (struct V_15 * ) & V_221 ) -> V_29 ,
V_215 , V_64 ? L_50 : L_51 , V_64 ) ;
return V_64 ;
}
static void F_137 ( struct V_80 * V_81 )
{
F_138 () ;
F_139 ( F_140 ( V_81 -> V_225 -> V_226 ) ) ;
F_141 () ;
}
static void F_142 ( struct V_6 * V_11 , unsigned short V_215 )
{
}
static inline void F_143 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_144 ( V_8 , L_53 ,
& V_227 [ 1 ] , L_54 , & V_228 [ 1 ] ) ;
}
static inline void F_145 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_144 ( V_8 , L_55 ,
& V_227 [ 0 ] , L_56 , & V_228 [ 0 ] ) ;
}
static inline void F_146 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_144 ( V_8 , L_57 ,
& V_227 [ 1 ] , L_58 , & V_228 [ 1 ] ) ;
}
static inline void F_147 ( int V_229 , struct V_39 * V_7 )
{
F_148 ( F_149 ( V_7 -> V_8 ) ) ;
if ( F_149 ( V_7 -> V_8 ) )
return;
switch ( V_229 ) {
case V_20 :
F_143 ( V_7 ) ;
break;
case V_25 :
F_145 ( V_7 ) ;
break;
case V_28 :
F_146 ( V_7 ) ;
break;
}
}
static inline void F_143 ( struct V_39 * V_7 )
{
}
static inline void F_145 ( struct V_39 * V_7 )
{
}
static inline void F_146 ( struct V_39 * V_7 )
{
}
static inline void F_147 ( int V_229 , struct V_39 * V_7 )
{
}
static void F_150 ( struct V_230 * V_231 )
{
}
static struct V_39 * F_151 ( struct V_6 * V_11 ,
struct V_82 * V_83 , int V_229 , int type ,
int V_33 , bool V_232 )
{
struct V_39 * V_7 ;
int V_64 ;
V_64 = F_152 ( V_11 -> V_233 , V_229 , type , V_33 , & V_7 , 1 ) ;
if ( V_64 < 0 ) {
F_2 ( L_59 ,
V_33 , - V_64 ) ;
goto V_78;
}
F_147 ( V_229 , V_7 ) ;
if ( V_232 )
F_125 ( V_7 ) ;
V_64 = F_135 ( V_83 , V_7 ) ;
if ( V_64 ) {
F_69 ( V_7 ) ;
goto V_78;
}
return V_7 ;
V_78:
return F_153 ( V_64 ) ;
}
static int F_154 ( struct V_6 * V_11 ,
struct V_39 * V_7 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_65 ( & V_8 -> V_129 ) ;
F_49 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_122 = F_78 ;
V_8 -> V_98 = F_118 ;
V_8 -> V_127 = F_56 ;
V_8 -> V_234 = V_235 ;
F_66 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_67 ( & V_8 -> V_129 ) ;
}
V_11 -> V_236 . V_237 ++ ;
V_11 -> V_236 . V_238 = V_239 ;
return F_155 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , 0 ) ;
}
static int F_156 ( struct V_82 * V_83 )
{
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 ;
int V_103 = - V_240 ;
V_103 = F_152 ( V_11 -> V_233 , V_20 ,
V_241 , 0 , & V_7 , 1 ) ;
if ( V_103 < 0 ) {
F_2 ( L_60
L_61 , - V_103 ) ;
goto V_78;
}
F_143 ( V_7 ) ;
F_2 ( L_62 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
V_103 = F_154 ( V_11 , V_7 ) ;
F_157 ( V_11 , V_7 , V_103 ) ;
switch ( V_103 ) {
case 0 :
F_2 ( L_63 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
F_158 ( V_11 ) ;
case - V_106 :
break;
case - V_242 :
F_2 ( L_64 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
case - V_112 :
F_2 ( L_65 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
default:
F_100 ( V_243 L_66 ,
V_105 , - V_103 ,
V_11 -> V_22 [ V_23 ] ) ;
}
V_78:
F_114 ( V_11 ) ;
F_59 ( V_11 , V_103 ) ;
return V_103 ;
}
static void F_159 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
int V_90 ;
if ( F_160 ( V_81 ) ) {
F_161 ( V_81 , - V_97 ) ;
return;
}
V_90 = F_156 ( V_83 ) ;
if ( V_90 && ! F_162 ( V_81 ) )
F_163 ( 15000 ) ;
}
static void F_164 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 )
return;
if ( F_62 ( & V_11 -> V_134 ) )
F_165 ( V_83 -> V_86 ) ;
}
static int
F_166 ( struct V_6 * V_11 )
{
struct V_82 * V_244 = F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( F_167 ( & V_11 -> V_134 ) != 1 )
return 0 ;
if ( F_168 ( & V_11 -> V_120 , V_245 , V_246 ) )
return - V_247 ;
if ( V_244 -> V_86 )
F_165 ( V_244 -> V_86 ) ;
F_48 ( V_11 , NULL ) ;
return 0 ;
}
static void
F_169 ( struct V_6 * V_11 )
{
struct V_82 * V_244 = F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( ! F_170 ( & V_11 -> V_134 ) )
return;
if ( F_168 ( & V_11 -> V_120 , V_245 , V_246 ) )
return;
if ( V_244 -> V_86 )
F_63 ( V_244 -> V_86 ) ;
F_48 ( V_11 , NULL ) ;
}
static void F_164 ( struct V_6 * V_11 )
{
}
static int
F_166 ( struct V_6 * V_11 )
{
return - V_248 ;
}
static void
F_169 ( struct V_6 * V_11 )
{
}
static void F_171 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_65 ( & V_8 -> V_129 ) ;
F_49 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_122 = F_86 ;
V_8 -> V_98 = F_118 ;
V_8 -> V_234 = V_235 ;
F_158 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_164 ( V_11 ) ;
F_67 ( & V_8 -> V_129 ) ;
}
F_120 ( V_11 ) ;
}
static void F_172 ( struct V_230 * V_231 )
{
struct V_82 * V_83 =
F_29 ( V_231 , struct V_82 , V_137 . V_231 ) ;
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 = V_83 -> V_7 ;
int V_103 = - V_240 ;
V_7 = F_151 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_249 ,
V_250 , false ) ;
if ( F_173 ( V_7 ) )
goto V_78;
F_2 ( L_67
L_68 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
F_171 ( V_11 , V_7 ) ;
F_157 ( V_11 , V_7 , 0 ) ;
V_103 = 0 ;
V_78:
F_174 ( V_11 , V_83 ) ;
F_114 ( V_11 ) ;
F_59 ( V_11 , V_103 ) ;
}
static void F_175 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
if ( V_7 == NULL )
return;
if ( F_32 ( V_11 ) ) {
F_64 ( V_7 , V_135 ) ;
F_176 ( V_11 , V_7 ) ;
} else
F_61 ( V_83 ) ;
}
static int F_177 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
int V_90 = - V_97 ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
unsigned int V_251 = V_11 -> V_252 -> V_253 / V_254 ;
unsigned int V_255 = V_11 -> V_252 -> V_256 + 1 ;
unsigned int V_257 = 1 ;
unsigned int V_258 ;
F_126 ( V_7 , V_212 , V_259 ,
( char * ) & V_257 , sizeof( V_257 ) ) ;
F_126 ( V_7 , V_260 , V_261 ,
( char * ) & V_251 , sizeof( V_251 ) ) ;
F_126 ( V_7 , V_260 , V_262 ,
( char * ) & V_251 , sizeof( V_251 ) ) ;
F_126 ( V_7 , V_260 , V_263 ,
( char * ) & V_255 , sizeof( V_255 ) ) ;
V_258 = F_178 ( V_11 -> V_252 -> V_253 ) *
( V_11 -> V_252 -> V_256 + 1 ) ;
F_126 ( V_7 , V_260 , V_264 ,
( char * ) & V_258 , sizeof( V_258 ) ) ;
F_65 ( & V_8 -> V_129 ) ;
F_49 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_122 = F_107 ;
V_8 -> V_124 = F_110 ;
V_8 -> V_98 = F_119 ;
V_8 -> V_127 = F_56 ;
V_8 -> V_234 = V_235 ;
F_179 ( V_8 , V_265 ) ;
F_180 ( V_8 ) -> V_266 |= V_267 ;
F_66 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_67 ( & V_8 -> V_129 ) ;
}
if ( ! F_44 ( V_11 ) )
goto V_78;
F_164 ( V_11 ) ;
V_11 -> V_236 . V_237 ++ ;
V_11 -> V_236 . V_238 = V_239 ;
F_34 ( V_191 , & V_83 -> V_192 ) ;
V_90 = F_155 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , V_268 ) ;
switch ( V_90 ) {
case 0 :
F_132 ( V_83 , V_7 ) ;
case - V_269 :
if ( V_11 -> V_136 < V_197 )
V_11 -> V_136 = V_197 ;
}
V_78:
return V_90 ;
}
static void F_181 ( struct V_230 * V_231 )
{
struct V_82 * V_83 =
F_29 ( V_231 , struct V_82 , V_137 . V_231 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
int V_103 = - V_240 ;
if ( ! V_7 ) {
V_7 = F_151 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_241 ,
V_270 , true ) ;
if ( F_173 ( V_7 ) ) {
V_103 = F_182 ( V_7 ) ;
goto V_78;
}
}
F_2 ( L_67
L_68 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
V_103 = F_177 ( V_11 , V_7 ) ;
F_157 ( V_11 , V_7 , V_103 ) ;
F_2 ( L_69 ,
V_11 , - V_103 , F_32 ( V_11 ) ,
V_7 -> V_8 -> V_131 ) ;
switch ( V_103 ) {
default:
F_100 ( L_70 ,
V_105 , V_103 ) ;
case - V_271 :
F_90 ( V_11 ) ;
break;
case 0 :
case - V_269 :
case - V_272 :
F_174 ( V_11 , V_83 ) ;
return;
case - V_248 :
case - V_112 :
case - V_115 :
case - V_111 :
case - V_116 :
case - V_106 :
F_90 ( V_11 ) ;
goto V_78;
}
V_103 = - V_91 ;
V_78:
F_174 ( V_11 , V_83 ) ;
F_114 ( V_11 ) ;
F_59 ( V_11 , V_103 ) ;
}
static void F_183 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_148 ( ! F_184 ( V_11 , V_81 , V_83 ) ) ;
if ( V_83 -> V_7 != NULL ) {
F_2 ( L_71
L_72 ,
V_11 , V_11 -> V_136 / V_254 ) ;
F_61 ( V_83 ) ;
F_185 ( V_273 ,
& V_83 -> V_137 ,
V_11 -> V_136 ) ;
V_11 -> V_136 <<= 1 ;
if ( V_11 -> V_136 < V_197 )
V_11 -> V_136 = V_197 ;
if ( V_11 -> V_136 > V_274 )
V_11 -> V_136 = V_274 ;
} else {
F_2 ( L_73 , V_11 ) ;
F_185 ( V_273 ,
& V_83 -> V_137 , 0 ) ;
}
}
static void F_186 ( struct V_6 * V_11 , struct V_275 * V_276 )
{
long V_277 = 0 ;
if ( F_32 ( V_11 ) )
V_277 = ( long ) ( V_239 - V_11 -> V_278 ) / V_254 ;
F_187 ( V_276 , L_74
L_75 ,
V_11 -> V_236 . V_279 ,
V_11 -> V_236 . V_237 ,
V_11 -> V_236 . V_280 ,
V_277 ,
V_11 -> V_236 . V_281 ,
V_11 -> V_236 . V_282 ,
V_11 -> V_236 . V_283 ,
V_11 -> V_236 . V_284 ,
V_11 -> V_236 . V_285 ,
V_11 -> V_236 . V_286 ,
V_11 -> V_236 . V_287 ,
V_11 -> V_236 . V_288 ) ;
}
static void F_188 ( struct V_6 * V_11 , struct V_275 * V_276 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_187 ( V_276 , L_76
L_77 ,
V_83 -> V_219 ,
V_11 -> V_236 . V_279 ,
V_11 -> V_236 . V_281 ,
V_11 -> V_236 . V_282 ,
V_11 -> V_236 . V_283 ,
V_11 -> V_236 . V_284 ,
V_11 -> V_236 . V_285 ,
V_11 -> V_236 . V_286 ,
V_11 -> V_236 . V_287 ,
V_11 -> V_236 . V_288 ) ;
}
static void F_189 ( struct V_6 * V_11 , struct V_275 * V_276 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
long V_277 = 0 ;
if ( F_32 ( V_11 ) )
V_277 = ( long ) ( V_239 - V_11 -> V_278 ) / V_254 ;
F_187 ( V_276 , L_78
L_75 ,
V_83 -> V_219 ,
V_11 -> V_236 . V_279 ,
V_11 -> V_236 . V_237 ,
V_11 -> V_236 . V_280 ,
V_277 ,
V_11 -> V_236 . V_281 ,
V_11 -> V_236 . V_282 ,
V_11 -> V_236 . V_283 ,
V_11 -> V_236 . V_284 ,
V_11 -> V_236 . V_285 ,
V_11 -> V_236 . V_286 ,
V_11 -> V_236 . V_287 ,
V_11 -> V_236 . V_288 ) ;
}
static void * F_190 ( struct V_80 * V_81 , T_4 V_60 )
{
struct V_58 * V_58 ;
struct V_289 * V_4 ;
F_148 ( V_60 > V_290 - sizeof( struct V_289 ) ) ;
if ( V_60 > V_290 - sizeof( struct V_289 ) )
return NULL ;
V_58 = F_191 ( V_24 ) ;
if ( ! V_58 )
return NULL ;
V_4 = F_192 ( V_58 ) ;
V_4 -> V_73 = V_290 ;
return V_4 -> V_183 ;
}
static void F_193 ( void * V_291 )
{
struct V_289 * V_4 ;
if ( ! V_291 )
return;
V_4 = F_29 ( V_291 , struct V_289 , V_183 ) ;
F_194 ( ( unsigned long ) V_4 ) ;
}
static int F_195 ( struct V_88 * V_89 )
{
int V_73 ;
struct V_54 * V_292 = & V_89 -> V_102 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
unsigned long V_293 ;
unsigned long V_294 ;
F_37 ( V_292 ) ;
V_294 = ( unsigned long ) V_292 -> V_79 [ 0 ] . V_52 & ~ V_69 ;
V_293 = ( unsigned long ) V_292 -> V_77 [ 0 ] . V_52 & ~ V_69 ;
V_73 = F_196 ( V_7 , V_292 ,
F_197 ( V_292 -> V_77 [ 0 ] . V_52 ) , V_293 ,
V_292 -> V_79 [ 0 ] . V_52 , V_294 ) ;
if ( V_73 != V_292 -> V_73 ) {
F_100 ( V_295 L_79 ) ;
V_73 = - V_91 ;
}
return V_73 ;
}
static int F_198 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_296 * V_11 ;
T_1 V_73 ;
F_2 ( L_80 , F_12 ( V_89 -> V_180 ) ) ;
V_11 = V_89 -> V_85 -> V_297 ;
if ( ! F_199 ( & V_11 -> V_298 ) ) {
F_200 ( & V_11 -> V_299 , V_81 , NULL ) ;
if ( ! F_199 ( & V_11 -> V_298 ) )
return - V_91 ;
F_201 ( & V_11 -> V_299 , V_81 ) ;
}
if ( F_33 ( V_300 , & V_11 -> V_301 ) )
V_73 = - V_97 ;
else
V_73 = F_195 ( V_89 ) ;
F_202 ( & V_11 -> V_298 ) ;
if ( V_73 > 0 )
V_73 = 0 ;
return V_73 ;
}
static void F_203 ( struct V_6 * V_11 )
{
}
static void F_204 ( struct V_6 * V_11 )
{
F_2 ( L_81 , V_11 ) ;
F_71 ( V_11 ) ;
F_75 ( V_138 ) ;
}
static int F_205 ( const int V_229 , struct V_10 * V_16 )
{
static const struct V_14 sin = {
. V_302 = V_25 ,
. V_26 . V_27 = F_206 ( V_303 ) ,
} ;
static const struct V_15 V_17 = {
. V_304 = V_28 ,
. V_29 = V_305 ,
} ;
switch ( V_229 ) {
case V_20 :
break;
case V_25 :
memcpy ( V_16 , & sin , sizeof( sin ) ) ;
break;
case V_28 :
memcpy ( V_16 , & V_17 , sizeof( V_17 ) ) ;
break;
default:
F_2 ( L_82 , V_105 ) ;
return - V_306 ;
}
return 0 ;
}
static struct V_6 * F_207 ( struct V_307 * args ,
unsigned int V_308 ,
unsigned int V_309 )
{
struct V_6 * V_11 ;
struct V_82 * V_310 ;
if ( args -> V_40 > sizeof( V_11 -> V_12 ) ) {
F_2 ( L_83 ) ;
return F_153 ( - V_311 ) ;
}
V_11 = F_208 ( args -> V_312 , sizeof( * V_310 ) , V_308 ,
V_309 ) ;
if ( V_11 == NULL ) {
F_2 ( L_84
L_85 ) ;
return F_153 ( - V_313 ) ;
}
V_310 = F_29 ( V_11 , struct V_82 , V_11 ) ;
memcpy ( & V_11 -> V_12 , args -> V_314 , args -> V_40 ) ;
V_11 -> V_40 = args -> V_40 ;
if ( args -> V_224 )
memcpy ( & V_310 -> V_224 , args -> V_224 , args -> V_40 ) ;
else {
int V_64 ;
V_64 = F_205 ( args -> V_314 -> V_19 ,
(struct V_10 * ) & V_310 -> V_224 ) ;
if ( V_64 != 0 ) {
F_72 ( V_11 ) ;
return F_153 ( V_64 ) ;
}
}
return V_11 ;
}
static struct V_6 * F_209 ( struct V_307 * args )
{
struct V_13 * V_18 = (struct V_13 * ) args -> V_314 ;
struct V_82 * V_83 ;
struct V_6 * V_11 ;
struct V_6 * V_90 ;
V_11 = F_207 ( args , V_315 ,
V_316 ) ;
if ( F_173 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_317 = 0 ;
V_11 -> V_318 = sizeof( V_100 ) / sizeof( T_1 ) ;
V_11 -> V_319 = V_320 ;
V_11 -> V_321 = V_322 ;
V_11 -> V_136 = V_197 ;
V_11 -> V_323 = V_324 ;
V_11 -> V_70 = & V_325 ;
V_11 -> V_252 = & V_326 ;
F_210 ( & V_83 -> V_137 ,
F_150 ) ;
switch ( V_18 -> V_327 ) {
case V_20 :
if ( V_18 -> V_21 [ 0 ] != '/' ) {
F_2 ( L_86 ,
V_18 -> V_21 ) ;
V_90 = F_153 ( - V_248 ) ;
goto V_328;
}
F_139 ( V_11 ) ;
F_16 ( V_11 , L_87 , V_329 ) ;
V_90 = F_153 ( F_156 ( V_83 ) ) ;
if ( V_90 )
goto V_328;
break;
default:
V_90 = F_153 ( - V_306 ) ;
goto V_328;
}
F_2 ( L_88 ,
V_11 -> V_22 [ V_23 ] ) ;
if ( F_211 ( V_138 ) )
return V_11 ;
V_90 = F_153 ( - V_248 ) ;
V_328:
F_71 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_212 ( struct V_307 * args )
{
struct V_10 * V_12 = args -> V_314 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
V_11 = F_207 ( args , V_330 ,
V_330 ) ;
if ( F_173 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_317 = V_250 ;
V_11 -> V_318 = 0 ;
V_11 -> V_319 = ( 1U << 16 ) - ( V_331 << 3 ) ;
V_11 -> V_321 = V_322 ;
V_11 -> V_136 = V_332 ;
V_11 -> V_323 = V_324 ;
V_11 -> V_70 = & V_333 ;
V_11 -> V_252 = & V_334 ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_218 != F_213 ( 0 ) )
F_139 ( V_11 ) ;
F_210 ( & V_83 -> V_137 ,
F_172 ) ;
F_16 ( V_11 , L_89 , V_335 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_217 != F_213 ( 0 ) )
F_139 ( V_11 ) ;
F_210 ( & V_83 -> V_137 ,
F_172 ) ;
F_16 ( V_11 , L_89 , V_336 ) ;
break;
default:
V_90 = F_153 ( - V_306 ) ;
goto V_328;
}
if ( F_44 ( V_11 ) )
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_91 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_211 ( V_138 ) )
return V_11 ;
V_90 = F_153 ( - V_248 ) ;
V_328:
F_71 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_214 ( struct V_307 * args )
{
struct V_10 * V_12 = args -> V_314 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
unsigned int V_309 = V_316 ;
if ( args -> V_61 & V_337 )
V_309 = V_338 ;
V_11 = F_207 ( args , V_315 ,
V_309 ) ;
if ( F_173 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_317 = V_270 ;
V_11 -> V_318 = sizeof( V_100 ) / sizeof( T_1 ) ;
V_11 -> V_319 = V_320 ;
V_11 -> V_321 = V_322 ;
V_11 -> V_136 = V_197 ;
V_11 -> V_323 = V_324 ;
V_11 -> V_70 = & V_339 ;
V_11 -> V_252 = & V_340 ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_218 != F_213 ( 0 ) )
F_139 ( V_11 ) ;
F_210 ( & V_83 -> V_137 ,
F_181 ) ;
F_16 ( V_11 , L_92 , V_341 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_217 != F_213 ( 0 ) )
F_139 ( V_11 ) ;
F_210 ( & V_83 -> V_137 ,
F_181 ) ;
F_16 ( V_11 , L_92 , V_342 ) ;
break;
default:
V_90 = F_153 ( - V_306 ) ;
goto V_328;
}
if ( F_44 ( V_11 ) )
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_91 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_211 ( V_138 ) )
return V_11 ;
V_90 = F_153 ( - V_248 ) ;
V_328:
F_71 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_215 ( struct V_307 * args )
{
struct V_10 * V_12 = args -> V_314 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_343 * V_344 ;
struct V_6 * V_90 ;
V_11 = F_207 ( args , V_315 ,
V_315 ) ;
if ( F_173 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_317 = V_270 ;
V_11 -> V_318 = sizeof( V_100 ) / sizeof( T_1 ) ;
V_11 -> V_319 = V_320 ;
V_11 -> V_252 = & V_340 ;
F_139 ( V_11 ) ;
V_11 -> V_321 = 0 ;
V_11 -> V_136 = 0 ;
V_11 -> V_323 = 0 ;
V_11 -> V_70 = & V_345 ;
switch ( V_12 -> V_19 ) {
case V_25 :
F_16 ( V_11 , L_92 ,
V_341 ) ;
break;
case V_28 :
F_16 ( V_11 , L_92 ,
V_342 ) ;
break;
default:
V_90 = F_153 ( - V_306 ) ;
goto V_328;
}
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
F_216 ( V_11 ) ;
args -> V_297 -> V_346 = V_11 ;
V_11 -> V_297 = args -> V_297 ;
V_344 = F_29 ( args -> V_297 , struct V_343 , V_347 ) ;
V_83 -> V_7 = V_344 -> V_348 ;
V_83 -> V_86 = V_344 -> V_349 ;
F_158 ( V_11 ) ;
if ( F_211 ( V_138 ) )
return V_11 ;
args -> V_297 -> V_346 = NULL ;
F_217 ( V_11 ) ;
V_90 = F_153 ( - V_248 ) ;
V_328:
F_71 ( V_11 ) ;
return V_90 ;
}
int F_218 ( void )
{
#if F_219 ( V_350 )
if ( ! V_351 )
V_351 = F_220 ( V_352 ) ;
#endif
F_221 ( & V_353 ) ;
F_221 ( & V_354 ) ;
F_221 ( & V_355 ) ;
F_221 ( & V_356 ) ;
return 0 ;
}
void F_222 ( void )
{
#if F_219 ( V_350 )
if ( V_351 ) {
F_223 ( V_351 ) ;
V_351 = NULL ;
}
#endif
F_224 ( & V_353 ) ;
F_224 ( & V_354 ) ;
F_224 ( & V_355 ) ;
F_224 ( & V_356 ) ;
}
static int F_225 ( const char * V_357 ,
const struct V_358 * V_359 ,
unsigned int V_360 , unsigned int V_361 )
{
unsigned int V_362 ;
int V_90 ;
if ( ! V_357 )
return - V_248 ;
V_90 = F_226 ( V_357 , 0 , & V_362 ) ;
if ( V_90 == - V_248 || V_362 < V_360 || V_362 > V_361 )
return - V_248 ;
* ( ( unsigned int * ) V_359 -> V_182 ) = V_362 ;
return 0 ;
}
static int F_227 ( const char * V_357 , const struct V_358 * V_359 )
{
return F_225 ( V_357 , V_359 ,
V_363 ,
V_364 ) ;
}
static int F_228 ( const char * V_357 ,
const struct V_358 * V_359 )
{
return F_225 ( V_357 , V_359 ,
V_365 ,
V_366 ) ;
}
static int F_229 ( const char * V_357 ,
const struct V_358 * V_359 )
{
return F_225 ( V_357 , V_359 ,
V_365 ,
V_338 ) ;
}
