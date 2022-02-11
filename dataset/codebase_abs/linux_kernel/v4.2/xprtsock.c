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
F_56 ( V_11 ) ;
}
static void F_57 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
int V_64 ;
F_58 ( & V_8 -> V_129 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
V_64 = - V_8 -> V_130 ;
if ( V_64 == 0 )
goto V_78;
if ( V_8 -> V_131 == V_132 )
F_54 ( V_11 ) ;
F_2 ( L_15 ,
V_11 , - V_64 ) ;
F_59 ( V_11 , V_8 -> V_133 , V_64 ) ;
F_60 ( V_11 , V_64 ) ;
V_78:
F_61 ( & V_8 -> V_129 ) ;
}
static void F_62 ( struct V_82 * V_83 )
{
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_7 * V_8 = V_83 -> V_86 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
if ( V_8 == NULL )
return;
if ( F_63 ( & V_83 -> V_11 . V_134 ) )
F_64 ( V_8 ) ;
F_65 ( & V_8 -> V_129 ) ;
V_83 -> V_86 = NULL ;
V_83 -> V_7 = NULL ;
V_8 -> V_9 = NULL ;
F_50 ( V_83 , V_8 ) ;
F_66 ( & V_8 -> V_129 ) ;
F_51 ( V_11 ) ;
F_67 ( V_11 , V_7 ) ;
F_68 ( V_7 ) ;
}
static void F_42 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_2 ( L_16 , V_11 ) ;
F_62 ( V_83 ) ;
V_11 -> V_135 = 0 ;
F_55 ( V_11 ) ;
}
static void F_69 ( struct V_6 * V_11 )
{
F_2 ( L_17 ,
V_11 ) ;
F_55 ( V_11 ) ;
}
static void F_70 ( struct V_6 * V_11 )
{
F_19 ( V_11 ) ;
F_71 ( V_11 ) ;
}
static void F_72 ( struct V_6 * V_11 )
{
F_2 ( L_18 , V_11 ) ;
F_42 ( V_11 ) ;
F_70 ( V_11 ) ;
F_73 ( V_136 ) ;
}
static int F_74 ( struct V_54 * V_55 , struct V_137 * V_138 )
{
struct V_139 V_140 = {
. V_138 = V_138 ,
. V_59 = sizeof( V_100 ) ,
. V_3 = V_138 -> V_73 - sizeof( V_100 ) ,
} ;
if ( F_75 ( V_55 , 0 , & V_140 , V_141 ) < 0 )
return - 1 ;
if ( V_140 . V_3 )
return - 1 ;
return 0 ;
}
static void F_76 ( struct V_7 * V_8 )
{
struct V_80 * V_81 ;
struct V_6 * V_11 ;
struct V_88 * V_142 ;
struct V_137 * V_138 ;
int V_64 , V_143 , V_144 ;
T_1 V_145 ;
T_5 * V_146 ;
F_58 ( & V_8 -> V_129 ) ;
F_2 ( L_19 , V_105 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 == NULL )
goto V_78;
V_138 = F_77 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_138 == NULL )
goto V_78;
V_143 = V_138 -> V_73 - sizeof( V_100 ) ;
if ( V_143 < 4 ) {
F_2 ( L_20 , V_143 ) ;
goto V_147;
}
V_146 = F_78 ( V_138 , sizeof( V_100 ) , sizeof( V_145 ) , & V_145 ) ;
if ( V_146 == NULL )
goto V_147;
F_79 ( & V_11 -> V_95 ) ;
V_142 = F_80 ( V_11 , * V_146 ) ;
if ( ! V_142 )
goto V_148;
V_81 = V_142 -> V_149 ;
V_144 = V_142 -> V_150 . V_151 ;
if ( V_144 > V_143 )
V_144 = V_143 ;
if ( F_74 ( & V_142 -> V_150 , V_138 ) ) {
F_2 ( L_21 ) ;
goto V_148;
}
F_81 ( V_81 , V_144 ) ;
V_148:
F_82 ( & V_11 -> V_95 ) ;
V_147:
F_83 ( V_8 , V_138 ) ;
V_78:
F_61 ( & V_8 -> V_129 ) ;
}
static void F_84 ( struct V_7 * V_8 )
{
struct V_80 * V_81 ;
struct V_6 * V_11 ;
struct V_88 * V_142 ;
struct V_137 * V_138 ;
int V_64 , V_143 , V_144 ;
T_1 V_145 ;
T_5 * V_146 ;
F_58 ( & V_8 -> V_129 ) ;
F_2 ( L_22 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
if ( ( V_138 = F_77 ( V_8 , 0 , 1 , & V_64 ) ) == NULL )
goto V_78;
V_143 = V_138 -> V_73 - sizeof( struct V_152 ) ;
if ( V_143 < 4 ) {
F_2 ( L_23 , V_143 ) ;
goto V_147;
}
V_146 = F_78 ( V_138 , sizeof( struct V_152 ) ,
sizeof( V_145 ) , & V_145 ) ;
if ( V_146 == NULL )
goto V_147;
F_79 ( & V_11 -> V_95 ) ;
V_142 = F_80 ( V_11 , * V_146 ) ;
if ( ! V_142 )
goto V_148;
V_81 = V_142 -> V_149 ;
if ( ( V_144 = V_142 -> V_150 . V_151 ) > V_143 )
V_144 = V_143 ;
if ( F_85 ( & V_142 -> V_150 , V_138 ) ) {
F_86 ( V_8 , V_153 ) ;
goto V_148;
}
F_86 ( V_8 , V_154 ) ;
F_87 ( V_11 , V_81 , V_144 ) ;
F_81 ( V_81 , V_144 ) ;
V_148:
F_82 ( & V_11 -> V_95 ) ;
V_147:
F_83 ( V_8 , V_138 ) ;
V_78:
F_61 ( & V_8 -> V_129 ) ;
}
static void F_88 ( struct V_6 * V_11 )
{
F_56 ( V_11 ) ;
}
static inline void F_89 ( struct V_6 * V_11 , struct V_139 * V_140 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
T_4 V_73 , V_155 ;
char * V_156 ;
V_156 = ( ( char * ) & V_83 -> V_157 ) + V_83 -> V_158 ;
V_73 = sizeof( V_83 -> V_157 ) - V_83 -> V_158 ;
V_155 = V_141 ( V_140 , V_156 , V_73 ) ;
V_83 -> V_158 += V_155 ;
if ( V_155 != V_73 )
return;
V_83 -> V_159 = F_12 ( V_83 -> V_157 ) ;
if ( V_83 -> V_159 & V_101 )
V_83 -> V_160 |= V_161 ;
else
V_83 -> V_160 &= ~ V_161 ;
V_83 -> V_159 &= V_162 ;
V_83 -> V_160 &= ~ V_163 ;
V_83 -> V_158 = 0 ;
if ( F_26 ( V_83 -> V_159 < 8 ) ) {
F_2 ( L_24 ) ;
F_88 ( V_11 ) ;
return;
}
F_2 ( L_25 ,
V_83 -> V_159 ) ;
}
static void F_90 ( struct V_82 * V_83 )
{
if ( V_83 -> V_158 == V_83 -> V_159 ) {
V_83 -> V_160 |= V_163 ;
V_83 -> V_158 = 0 ;
if ( V_83 -> V_160 & V_161 ) {
V_83 -> V_160 &= ~ V_164 ;
V_83 -> V_160 |= V_165 ;
V_83 -> V_166 = 0 ;
}
}
}
static inline void F_91 ( struct V_82 * V_83 , struct V_139 * V_140 )
{
T_4 V_73 , V_155 ;
char * V_156 ;
V_73 = sizeof( V_83 -> V_167 ) - V_83 -> V_158 ;
F_2 ( L_26 , V_73 ) ;
V_156 = ( ( char * ) & V_83 -> V_167 ) + V_83 -> V_158 ;
V_155 = V_141 ( V_140 , V_156 , V_73 ) ;
V_83 -> V_158 += V_155 ;
if ( V_155 != V_73 )
return;
V_83 -> V_160 &= ~ V_165 ;
V_83 -> V_160 |= V_168 ;
V_83 -> V_166 = 4 ;
F_2 ( L_27 ,
( V_83 -> V_160 & V_169 ) ? L_28
: L_29 ,
F_12 ( V_83 -> V_167 ) ) ;
F_90 ( V_83 ) ;
}
static inline void F_92 ( struct V_82 * V_83 ,
struct V_139 * V_140 )
{
T_4 V_73 , V_155 ;
T_1 V_59 ;
char * V_156 ;
V_59 = V_83 -> V_158 - sizeof( V_83 -> V_167 ) ;
V_73 = sizeof( V_83 -> V_170 ) - V_59 ;
F_2 ( L_30 , V_73 ) ;
V_156 = ( ( char * ) & V_83 -> V_170 ) + V_59 ;
V_155 = V_141 ( V_140 , V_156 , V_73 ) ;
V_83 -> V_158 += V_155 ;
if ( V_155 != V_73 )
return;
V_83 -> V_160 &= ~ V_168 ;
switch ( F_12 ( V_83 -> V_170 ) ) {
case V_171 :
V_83 -> V_160 |= V_172 ;
V_83 -> V_160 |= V_164 ;
V_83 -> V_160 |= V_169 ;
break;
case V_173 :
V_83 -> V_160 |= V_172 ;
V_83 -> V_160 |= V_164 ;
V_83 -> V_160 &= ~ V_169 ;
break;
default:
F_2 ( L_31 ) ;
F_88 ( & V_83 -> V_11 ) ;
}
F_90 ( V_83 ) ;
}
static inline void F_93 ( struct V_6 * V_11 ,
struct V_139 * V_140 ,
struct V_88 * V_89 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_174 ;
T_4 V_73 ;
T_3 V_175 ;
V_174 = & V_89 -> V_150 ;
if ( V_83 -> V_160 & V_172 ) {
memcpy ( V_174 -> V_77 [ 0 ] . V_52 + V_83 -> V_166 ,
& V_83 -> V_170 ,
sizeof( V_83 -> V_170 ) ) ;
V_83 -> V_166 += sizeof( V_83 -> V_170 ) ;
V_83 -> V_160 &= ~ V_172 ;
}
V_73 = V_140 -> V_3 ;
if ( V_73 > V_83 -> V_159 - V_83 -> V_158 ) {
struct V_139 V_176 ;
V_73 = V_83 -> V_159 - V_83 -> V_158 ;
memcpy ( & V_176 , V_140 , sizeof( V_176 ) ) ;
V_176 . V_3 = V_73 ;
V_175 = F_75 ( V_174 , V_83 -> V_166 ,
& V_176 , V_141 ) ;
V_140 -> V_3 -= V_175 ;
V_140 -> V_59 += V_175 ;
} else
V_175 = F_75 ( V_174 , V_83 -> V_166 ,
V_140 , V_141 ) ;
if ( V_175 > 0 ) {
V_83 -> V_166 += V_175 ;
V_83 -> V_158 += V_175 ;
}
if ( V_175 != V_73 ) {
V_83 -> V_160 &= ~ V_164 ;
F_2 ( L_32 ,
F_12 ( V_83 -> V_167 ) ) ;
F_2 ( L_33
L_34 ,
V_11 , V_83 -> V_166 ,
V_83 -> V_158 , V_83 -> V_159 ) ;
return;
}
F_2 ( L_35 ,
F_12 ( V_83 -> V_167 ) , V_175 ) ;
F_2 ( L_36
L_37 , V_11 , V_83 -> V_166 ,
V_83 -> V_158 , V_83 -> V_159 ) ;
if ( V_83 -> V_166 == V_89 -> V_150 . V_151 )
V_83 -> V_160 &= ~ V_164 ;
else if ( V_83 -> V_158 == V_83 -> V_159 ) {
if ( V_83 -> V_160 & V_161 )
V_83 -> V_160 &= ~ V_164 ;
}
}
static inline int F_94 ( struct V_6 * V_11 ,
struct V_139 * V_140 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_2 ( L_38 , F_12 ( V_83 -> V_167 ) ) ;
F_79 ( & V_11 -> V_95 ) ;
V_89 = F_80 ( V_11 , V_83 -> V_167 ) ;
if ( ! V_89 ) {
F_2 ( L_39 ,
F_12 ( V_83 -> V_167 ) ) ;
F_82 ( & V_11 -> V_95 ) ;
return - 1 ;
}
F_93 ( V_11 , V_140 , V_89 ) ;
if ( ! ( V_83 -> V_160 & V_164 ) )
F_81 ( V_89 -> V_149 , V_83 -> V_166 ) ;
F_82 ( & V_11 -> V_95 ) ;
return 0 ;
}
static int F_95 ( struct V_6 * V_11 ,
struct V_139 * V_140 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_79 ( & V_11 -> V_95 ) ;
V_89 = F_96 ( V_11 , V_83 -> V_167 ) ;
if ( V_89 == NULL ) {
F_82 ( & V_11 -> V_95 ) ;
F_97 ( V_177 L_40 ) ;
F_56 ( V_11 ) ;
return - 1 ;
}
F_2 ( L_41 , F_12 ( V_89 -> V_178 ) ) ;
F_93 ( V_11 , V_140 , V_89 ) ;
if ( ! ( V_83 -> V_160 & V_164 ) )
F_98 ( V_89 , V_83 -> V_166 ) ;
F_82 ( & V_11 -> V_95 ) ;
return 0 ;
}
static inline int F_99 ( struct V_6 * V_11 ,
struct V_139 * V_140 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
return ( V_83 -> V_160 & V_169 ) ?
F_94 ( V_11 , V_140 ) :
F_95 ( V_11 , V_140 ) ;
}
static inline int F_99 ( struct V_6 * V_11 ,
struct V_139 * V_140 )
{
return F_94 ( V_11 , V_140 ) ;
}
static void F_100 ( struct V_6 * V_11 ,
struct V_139 * V_140 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( F_99 ( V_11 , V_140 ) == 0 )
F_90 ( V_83 ) ;
else {
V_83 -> V_160 &= ~ V_164 ;
}
}
static inline void F_101 ( struct V_82 * V_83 , struct V_139 * V_140 )
{
T_4 V_73 ;
V_73 = V_83 -> V_159 - V_83 -> V_158 ;
if ( V_73 > V_140 -> V_3 )
V_73 = V_140 -> V_3 ;
V_140 -> V_3 -= V_73 ;
V_140 -> V_59 += V_73 ;
V_83 -> V_158 += V_73 ;
F_2 ( L_42 , V_73 ) ;
F_90 ( V_83 ) ;
}
static int F_102 ( T_6 * V_179 , struct V_137 * V_138 , unsigned int V_59 , T_4 V_73 )
{
struct V_6 * V_11 = V_179 -> V_180 . V_181 ;
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_139 V_140 = {
. V_138 = V_138 ,
. V_59 = V_59 ,
. V_3 = V_73 ,
} ;
F_2 ( L_43 ) ;
do {
F_103 ( V_83 ) ;
if ( V_83 -> V_160 & V_163 ) {
F_89 ( V_11 , & V_140 ) ;
continue;
}
if ( V_83 -> V_160 & V_165 ) {
F_91 ( V_83 , & V_140 ) ;
continue;
}
if ( V_83 -> V_160 & V_168 ) {
F_92 ( V_83 , & V_140 ) ;
continue;
}
if ( V_83 -> V_160 & V_164 ) {
F_100 ( V_11 , & V_140 ) ;
continue;
}
F_101 ( V_83 , & V_140 ) ;
} while ( V_140 . V_3 );
F_103 ( V_83 ) ;
F_2 ( L_44 ) ;
return V_73 - V_140 . V_3 ;
}
static void F_104 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
T_6 V_179 ;
int V_182 ;
unsigned long V_183 = 0 ;
F_2 ( L_45 ) ;
F_58 ( & V_8 -> V_129 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) ) {
V_182 = 0 ;
goto V_78;
}
if ( V_11 -> V_135 )
V_11 -> V_135 = 0 ;
V_179 . V_180 . V_181 = V_11 ;
do {
V_179 . V_3 = 65536 ;
V_182 = F_105 ( V_8 , & V_179 , F_102 ) ;
if ( V_182 > 0 )
V_183 += V_182 ;
} while ( V_182 > 0 );
V_78:
F_106 ( V_11 , V_182 , V_183 ) ;
F_61 ( & V_8 -> V_129 ) ;
}
static void F_107 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
F_58 ( & V_8 -> V_129 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
F_2 ( L_46 , V_11 ) ;
F_2 ( L_47 ,
V_8 -> V_131 , F_32 ( V_11 ) ,
F_108 ( V_8 , V_184 ) ,
F_108 ( V_8 , V_185 ) ,
V_8 -> V_186 ) ;
F_109 ( V_11 , V_8 -> V_133 ) ;
switch ( V_8 -> V_131 ) {
case V_187 :
F_79 ( & V_11 -> V_95 ) ;
if ( ! F_110 ( V_11 ) ) {
struct V_82 * V_83 = F_29 ( V_11 ,
struct V_82 , V_11 ) ;
V_83 -> V_158 = 0 ;
V_83 -> V_159 = 0 ;
V_83 -> V_166 = 0 ;
V_83 -> V_160 =
V_163 | V_165 ;
V_11 -> V_188 ++ ;
F_60 ( V_11 , - V_91 ) ;
}
F_82 ( & V_11 -> V_95 ) ;
break;
case V_189 :
V_11 -> V_188 ++ ;
V_11 -> V_135 = 0 ;
F_34 ( V_128 , & V_11 -> V_120 ) ;
F_52 () ;
F_27 ( V_190 , & V_11 -> V_120 ) ;
F_27 ( V_119 , & V_11 -> V_120 ) ;
F_53 () ;
break;
case V_191 :
V_11 -> V_188 ++ ;
F_27 ( V_190 , & V_11 -> V_120 ) ;
F_88 ( V_11 ) ;
case V_192 :
if ( V_11 -> V_135 < V_193 )
V_11 -> V_135 = V_193 ;
break;
case V_194 :
F_34 ( V_128 , & V_11 -> V_120 ) ;
F_52 () ;
F_27 ( V_190 , & V_11 -> V_120 ) ;
F_53 () ;
break;
case V_132 :
F_54 ( V_11 ) ;
}
V_78:
F_61 ( & V_8 -> V_129 ) ;
}
static void F_111 ( struct V_7 * V_8 )
{
struct V_39 * V_7 ;
struct V_6 * V_11 ;
if ( F_26 ( ! ( V_7 = V_8 -> V_133 ) ) )
return;
F_27 ( V_96 , & V_7 -> V_61 ) ;
if ( F_26 ( ! ( V_11 = F_3 ( V_8 ) ) ) )
return;
if ( F_112 ( V_76 , & V_7 -> V_61 ) == 0 )
return;
F_113 ( V_11 ) ;
}
static void F_114 ( struct V_7 * V_8 )
{
F_58 ( & V_8 -> V_129 ) ;
if ( F_40 ( V_8 ) )
F_111 ( V_8 ) ;
F_61 ( & V_8 -> V_129 ) ;
}
static void F_115 ( struct V_7 * V_8 )
{
F_58 ( & V_8 -> V_129 ) ;
if ( F_46 ( V_8 ) )
F_111 ( V_8 ) ;
F_61 ( & V_8 -> V_129 ) ;
}
static void F_116 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_7 * V_8 = V_83 -> V_86 ;
if ( V_83 -> V_195 ) {
V_8 -> V_196 |= V_197 ;
V_8 -> V_198 = V_83 -> V_195 * V_11 -> V_199 * 2 ;
}
if ( V_83 -> V_200 ) {
V_8 -> V_196 |= V_201 ;
V_8 -> V_202 = V_83 -> V_200 * V_11 -> V_199 * 2 ;
V_8 -> V_98 ( V_8 ) ;
}
}
static void F_117 ( struct V_6 * V_11 , T_4 V_200 , T_4 V_195 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_83 -> V_200 = 0 ;
if ( V_200 )
V_83 -> V_200 = V_200 + 1024 ;
V_83 -> V_195 = 0 ;
if ( V_195 )
V_83 -> V_195 = V_195 + 1024 ;
F_116 ( V_11 ) ;
}
static void F_118 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
F_87 ( V_11 , V_81 , - V_203 ) ;
}
static unsigned short F_119 ( void )
{
unsigned short V_204 = V_205 - V_206 ;
unsigned short rand = ( unsigned short ) F_120 () % V_204 ;
return rand + V_206 ;
}
static void F_121 ( struct V_39 * V_7 )
{
int V_207 = 1 ;
F_122 ( V_7 , V_208 , V_209 ,
( char * ) & V_207 , sizeof( V_207 ) ) ;
}
static unsigned short F_123 ( struct V_39 * V_7 )
{
struct V_210 V_4 ;
int V_151 ;
unsigned short V_211 = 0 ;
if ( F_124 ( V_7 , (struct V_10 * ) & V_4 , & V_151 ) < 0 )
goto V_78;
switch ( V_4 . V_212 ) {
case V_28 :
V_211 = F_125 ( ( (struct V_15 * ) & V_4 ) -> V_213 ) ;
break;
case V_25 :
V_211 = F_125 ( ( (struct V_14 * ) & V_4 ) -> V_214 ) ;
}
V_78:
return V_211 ;
}
static void F_126 ( struct V_6 * V_11 , unsigned short V_211 )
{
F_2 ( L_48 , V_11 , V_211 ) ;
F_127 ( F_4 ( V_11 ) , V_211 ) ;
F_17 ( V_11 ) ;
}
static void F_128 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
if ( V_83 -> V_215 == 0 )
V_83 -> V_215 = F_123 ( V_7 ) ;
}
static unsigned short F_129 ( struct V_82 * V_83 )
{
unsigned short V_211 = V_83 -> V_215 ;
if ( V_211 == 0 && V_83 -> V_11 . V_216 )
V_211 = F_119 () ;
return V_211 ;
}
static unsigned short F_130 ( struct V_82 * V_83 , unsigned short V_211 )
{
if ( V_83 -> V_215 != 0 )
V_83 -> V_215 = 0 ;
if ( ! V_83 -> V_11 . V_216 )
return 0 ;
if ( V_211 <= V_206 || V_211 > V_205 )
return V_205 ;
return -- V_211 ;
}
static int F_131 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
struct V_210 V_217 ;
int V_64 , V_218 = 0 ;
unsigned short V_211 = F_129 ( V_83 ) ;
unsigned short V_219 ;
if ( V_211 == 0 )
return 0 ;
memcpy ( & V_217 , & V_83 -> V_220 , V_83 -> V_11 . V_40 ) ;
do {
F_127 ( (struct V_10 * ) & V_217 , V_211 ) ;
V_64 = F_132 ( V_7 , (struct V_10 * ) & V_217 ,
V_83 -> V_11 . V_40 ) ;
if ( V_64 == 0 ) {
V_83 -> V_215 = V_211 ;
break;
}
V_219 = V_211 ;
V_211 = F_130 ( V_83 , V_211 ) ;
if ( V_211 > V_219 )
V_218 ++ ;
} while ( V_64 == - V_116 && V_218 != 2 );
if ( V_217 . V_212 == V_25 )
F_2 ( L_49 , V_105 ,
& ( (struct V_14 * ) & V_217 ) -> V_26 ,
V_211 , V_64 ? L_50 : L_51 , V_64 ) ;
else
F_2 ( L_52 , V_105 ,
& ( (struct V_15 * ) & V_217 ) -> V_29 ,
V_211 , V_64 ? L_50 : L_51 , V_64 ) ;
return V_64 ;
}
static void F_133 ( struct V_80 * V_81 )
{
F_134 () ;
F_135 ( F_136 ( V_81 -> V_221 -> V_222 ) ) ;
F_137 () ;
}
static void F_138 ( struct V_6 * V_11 , unsigned short V_211 )
{
}
static inline void F_139 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_140 ( V_8 , L_53 ,
& V_223 [ 1 ] , L_54 , & V_224 [ 1 ] ) ;
}
static inline void F_141 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_140 ( V_8 , L_55 ,
& V_223 [ 0 ] , L_56 , & V_224 [ 0 ] ) ;
}
static inline void F_142 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_140 ( V_8 , L_57 ,
& V_223 [ 1 ] , L_58 , & V_224 [ 1 ] ) ;
}
static inline void F_143 ( int V_225 , struct V_39 * V_7 )
{
F_144 ( F_145 ( V_7 -> V_8 ) ) ;
if ( F_145 ( V_7 -> V_8 ) )
return;
switch ( V_225 ) {
case V_20 :
F_139 ( V_7 ) ;
break;
case V_25 :
F_141 ( V_7 ) ;
break;
case V_28 :
F_142 ( V_7 ) ;
break;
}
}
static inline void F_139 ( struct V_39 * V_7 )
{
}
static inline void F_141 ( struct V_39 * V_7 )
{
}
static inline void F_142 ( struct V_39 * V_7 )
{
}
static inline void F_143 ( int V_225 , struct V_39 * V_7 )
{
}
static void F_146 ( struct V_226 * V_227 )
{
}
static struct V_39 * F_147 ( struct V_6 * V_11 ,
struct V_82 * V_83 , int V_225 , int type ,
int V_33 , bool V_228 )
{
struct V_39 * V_7 ;
int V_64 ;
V_64 = F_148 ( V_11 -> V_229 , V_225 , type , V_33 , & V_7 , 1 ) ;
if ( V_64 < 0 ) {
F_2 ( L_59 ,
V_33 , - V_64 ) ;
goto V_78;
}
F_143 ( V_225 , V_7 ) ;
if ( V_228 )
F_121 ( V_7 ) ;
V_64 = F_131 ( V_83 , V_7 ) ;
if ( V_64 ) {
F_68 ( V_7 ) ;
goto V_78;
}
return V_7 ;
V_78:
return F_149 ( V_64 ) ;
}
static int F_150 ( struct V_6 * V_11 ,
struct V_39 * V_7 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_65 ( & V_8 -> V_129 ) ;
F_49 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_122 = F_76 ;
V_8 -> V_98 = F_114 ;
V_8 -> V_127 = F_57 ;
V_8 -> V_230 = V_231 ;
F_151 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_66 ( & V_8 -> V_129 ) ;
}
V_11 -> V_232 . V_233 ++ ;
V_11 -> V_232 . V_234 = V_235 ;
return F_152 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , 0 ) ;
}
static int F_153 ( struct V_82 * V_83 )
{
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 ;
int V_103 = - V_236 ;
V_103 = F_148 ( V_11 -> V_229 , V_20 ,
V_237 , 0 , & V_7 , 1 ) ;
if ( V_103 < 0 ) {
F_2 ( L_60
L_61 , - V_103 ) ;
goto V_78;
}
F_139 ( V_7 ) ;
F_2 ( L_62 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
V_103 = F_150 ( V_11 , V_7 ) ;
F_154 ( V_11 , V_7 , V_103 ) ;
switch ( V_103 ) {
case 0 :
F_2 ( L_63 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
F_155 ( V_11 ) ;
case - V_106 :
break;
case - V_238 :
F_2 ( L_64 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
case - V_112 :
F_2 ( L_65 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
default:
F_97 ( V_239 L_66 ,
V_105 , - V_103 ,
V_11 -> V_22 [ V_23 ] ) ;
}
V_78:
F_156 ( V_11 ) ;
F_60 ( V_11 , V_103 ) ;
return V_103 ;
}
static void F_157 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
int V_90 ;
if ( F_158 ( V_81 ) ) {
F_159 ( V_81 , - V_97 ) ;
return;
}
V_90 = F_153 ( V_83 ) ;
if ( V_90 && ! F_160 ( V_81 ) )
F_161 ( 15000 ) ;
}
static void F_162 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 )
return;
if ( F_63 ( & V_11 -> V_134 ) )
F_163 ( V_83 -> V_86 ) ;
}
static int
F_164 ( struct V_6 * V_11 )
{
struct V_82 * V_240 = F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( F_165 ( & V_11 -> V_134 ) != 1 )
return 0 ;
if ( F_166 ( & V_11 -> V_120 , V_241 , V_242 ) )
return - V_243 ;
if ( V_240 -> V_86 )
F_163 ( V_240 -> V_86 ) ;
F_48 ( V_11 , NULL ) ;
return 0 ;
}
static void
F_167 ( struct V_6 * V_11 )
{
struct V_82 * V_240 = F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( ! F_168 ( & V_11 -> V_134 ) )
return;
if ( F_166 ( & V_11 -> V_120 , V_241 , V_242 ) )
return;
if ( V_240 -> V_86 )
F_64 ( V_240 -> V_86 ) ;
F_48 ( V_11 , NULL ) ;
}
static void F_162 ( struct V_6 * V_11 )
{
}
static int
F_164 ( struct V_6 * V_11 )
{
return - V_244 ;
}
static void
F_167 ( struct V_6 * V_11 )
{
}
static void F_169 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_65 ( & V_8 -> V_129 ) ;
F_49 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_122 = F_84 ;
V_8 -> V_98 = F_114 ;
V_8 -> V_230 = V_231 ;
F_155 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_162 ( V_11 ) ;
F_66 ( & V_8 -> V_129 ) ;
}
F_116 ( V_11 ) ;
}
static void F_170 ( struct V_226 * V_227 )
{
struct V_82 * V_83 =
F_29 ( V_227 , struct V_82 , V_245 . V_227 ) ;
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 = V_83 -> V_7 ;
int V_103 = - V_236 ;
V_7 = F_147 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_246 ,
V_247 , false ) ;
if ( F_171 ( V_7 ) )
goto V_78;
F_2 ( L_67
L_68 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
F_169 ( V_11 , V_7 ) ;
F_154 ( V_11 , V_7 , 0 ) ;
V_103 = 0 ;
V_78:
F_172 ( V_11 , V_83 ) ;
F_156 ( V_11 ) ;
F_60 ( V_11 , V_103 ) ;
}
static void F_173 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
if ( V_7 == NULL )
return;
if ( F_32 ( V_11 ) ) {
F_174 ( V_7 , V_248 ) ;
F_175 ( V_11 , V_7 ) ;
} else
F_62 ( V_83 ) ;
}
static int F_176 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
int V_90 = - V_97 ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
unsigned int V_249 = V_11 -> V_250 -> V_251 / V_252 ;
unsigned int V_253 = V_11 -> V_250 -> V_254 + 1 ;
unsigned int V_255 = 1 ;
unsigned int V_256 ;
F_122 ( V_7 , V_208 , V_257 ,
( char * ) & V_255 , sizeof( V_255 ) ) ;
F_122 ( V_7 , V_258 , V_259 ,
( char * ) & V_249 , sizeof( V_249 ) ) ;
F_122 ( V_7 , V_258 , V_260 ,
( char * ) & V_249 , sizeof( V_249 ) ) ;
F_122 ( V_7 , V_258 , V_261 ,
( char * ) & V_253 , sizeof( V_253 ) ) ;
V_256 = F_177 ( V_11 -> V_250 -> V_251 ) *
( V_11 -> V_250 -> V_254 + 1 ) ;
F_122 ( V_7 , V_258 , V_262 ,
( char * ) & V_256 , sizeof( V_256 ) ) ;
F_65 ( & V_8 -> V_129 ) ;
F_49 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_122 = F_104 ;
V_8 -> V_124 = F_107 ;
V_8 -> V_98 = F_115 ;
V_8 -> V_127 = F_57 ;
V_8 -> V_230 = V_231 ;
F_178 ( V_8 , V_263 ) ;
F_179 ( V_8 ) -> V_264 |= V_265 ;
F_151 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_66 ( & V_8 -> V_129 ) ;
}
if ( ! F_44 ( V_11 ) )
goto V_78;
F_162 ( V_11 ) ;
V_11 -> V_232 . V_233 ++ ;
V_11 -> V_232 . V_234 = V_235 ;
V_90 = F_152 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , V_266 ) ;
switch ( V_90 ) {
case 0 :
F_128 ( V_83 , V_7 ) ;
case - V_267 :
if ( V_11 -> V_135 < V_193 )
V_11 -> V_135 = V_193 ;
}
V_78:
return V_90 ;
}
static void F_180 ( struct V_226 * V_227 )
{
struct V_82 * V_83 =
F_29 ( V_227 , struct V_82 , V_245 . V_227 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
int V_103 = - V_236 ;
if ( ! V_7 ) {
V_7 = F_147 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_237 ,
V_268 , true ) ;
if ( F_171 ( V_7 ) ) {
V_103 = F_181 ( V_7 ) ;
goto V_78;
}
}
F_2 ( L_67
L_68 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
V_103 = F_176 ( V_11 , V_7 ) ;
F_154 ( V_11 , V_7 , V_103 ) ;
F_2 ( L_69 ,
V_11 , - V_103 , F_32 ( V_11 ) ,
V_7 -> V_8 -> V_131 ) ;
switch ( V_103 ) {
default:
F_97 ( L_70 ,
V_105 , V_103 ) ;
case - V_269 :
F_88 ( V_11 ) ;
break;
case 0 :
case - V_267 :
case - V_270 :
F_172 ( V_11 , V_83 ) ;
F_156 ( V_11 ) ;
return;
case - V_244 :
case - V_112 :
case - V_115 :
case - V_111 :
case - V_116 :
case - V_106 :
F_88 ( V_11 ) ;
goto V_78;
}
V_103 = - V_91 ;
V_78:
F_172 ( V_11 , V_83 ) ;
F_156 ( V_11 ) ;
F_60 ( V_11 , V_103 ) ;
}
static void F_182 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_144 ( ! F_183 ( V_11 , V_81 , V_83 ) ) ;
F_62 ( V_83 ) ;
if ( V_83 -> V_7 != NULL && ! F_160 ( V_81 ) ) {
F_2 ( L_71
L_72 ,
V_11 , V_11 -> V_135 / V_252 ) ;
F_184 ( V_271 ,
& V_83 -> V_245 ,
V_11 -> V_135 ) ;
V_11 -> V_135 <<= 1 ;
if ( V_11 -> V_135 < V_193 )
V_11 -> V_135 = V_193 ;
if ( V_11 -> V_135 > V_272 )
V_11 -> V_135 = V_272 ;
} else {
F_2 ( L_73 , V_11 ) ;
F_184 ( V_271 ,
& V_83 -> V_245 , 0 ) ;
}
}
static void F_185 ( struct V_6 * V_11 , struct V_273 * V_274 )
{
long V_275 = 0 ;
if ( F_32 ( V_11 ) )
V_275 = ( long ) ( V_235 - V_11 -> V_276 ) / V_252 ;
F_186 ( V_274 , L_74
L_75 ,
V_11 -> V_232 . V_277 ,
V_11 -> V_232 . V_233 ,
V_11 -> V_232 . V_278 ,
V_275 ,
V_11 -> V_232 . V_279 ,
V_11 -> V_232 . V_280 ,
V_11 -> V_232 . V_281 ,
V_11 -> V_232 . V_282 ,
V_11 -> V_232 . V_283 ,
V_11 -> V_232 . V_284 ,
V_11 -> V_232 . V_285 ,
V_11 -> V_232 . V_286 ) ;
}
static void F_187 ( struct V_6 * V_11 , struct V_273 * V_274 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_186 ( V_274 , L_76
L_77 ,
V_83 -> V_215 ,
V_11 -> V_232 . V_277 ,
V_11 -> V_232 . V_279 ,
V_11 -> V_232 . V_280 ,
V_11 -> V_232 . V_281 ,
V_11 -> V_232 . V_282 ,
V_11 -> V_232 . V_283 ,
V_11 -> V_232 . V_284 ,
V_11 -> V_232 . V_285 ,
V_11 -> V_232 . V_286 ) ;
}
static void F_188 ( struct V_6 * V_11 , struct V_273 * V_274 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
long V_275 = 0 ;
if ( F_32 ( V_11 ) )
V_275 = ( long ) ( V_235 - V_11 -> V_276 ) / V_252 ;
F_186 ( V_274 , L_78
L_75 ,
V_83 -> V_215 ,
V_11 -> V_232 . V_277 ,
V_11 -> V_232 . V_233 ,
V_11 -> V_232 . V_278 ,
V_275 ,
V_11 -> V_232 . V_279 ,
V_11 -> V_232 . V_280 ,
V_11 -> V_232 . V_281 ,
V_11 -> V_232 . V_282 ,
V_11 -> V_232 . V_283 ,
V_11 -> V_232 . V_284 ,
V_11 -> V_232 . V_285 ,
V_11 -> V_232 . V_286 ) ;
}
static void * F_189 ( struct V_80 * V_81 , T_4 V_60 )
{
struct V_58 * V_58 ;
struct V_287 * V_4 ;
F_144 ( V_60 > V_288 - sizeof( struct V_287 ) ) ;
if ( V_60 > V_288 - sizeof( struct V_287 ) )
return NULL ;
V_58 = F_190 ( V_24 ) ;
if ( ! V_58 )
return NULL ;
V_4 = F_191 ( V_58 ) ;
V_4 -> V_73 = V_288 ;
return V_4 -> V_181 ;
}
static void F_192 ( void * V_289 )
{
struct V_287 * V_4 ;
if ( ! V_289 )
return;
V_4 = F_29 ( V_289 , struct V_287 , V_181 ) ;
F_193 ( ( unsigned long ) V_4 ) ;
}
static int F_194 ( struct V_88 * V_89 )
{
int V_73 ;
struct V_54 * V_290 = & V_89 -> V_102 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
unsigned long V_291 ;
unsigned long V_292 ;
F_37 ( V_290 ) ;
V_292 = ( unsigned long ) V_290 -> V_79 [ 0 ] . V_52 & ~ V_69 ;
V_291 = ( unsigned long ) V_290 -> V_77 [ 0 ] . V_52 & ~ V_69 ;
V_73 = F_195 ( V_7 , V_290 ,
F_196 ( V_290 -> V_77 [ 0 ] . V_52 ) , V_291 ,
V_290 -> V_79 [ 0 ] . V_52 , V_292 ) ;
if ( V_73 != V_290 -> V_73 ) {
F_97 ( V_293 L_79 ) ;
V_73 = - V_91 ;
}
return V_73 ;
}
static int F_197 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_294 * V_11 ;
T_1 V_73 ;
F_2 ( L_80 , F_12 ( V_89 -> V_178 ) ) ;
V_11 = V_89 -> V_85 -> V_295 ;
if ( ! F_198 ( & V_11 -> V_296 ) ) {
F_199 ( & V_11 -> V_297 , V_81 , NULL ) ;
if ( ! F_198 ( & V_11 -> V_296 ) )
return - V_91 ;
F_200 ( & V_11 -> V_297 , V_81 ) ;
}
if ( F_33 ( V_298 , & V_11 -> V_299 ) )
V_73 = - V_97 ;
else
V_73 = F_194 ( V_89 ) ;
F_201 ( & V_11 -> V_296 ) ;
if ( V_73 > 0 )
V_73 = 0 ;
return V_73 ;
}
static void F_202 ( struct V_6 * V_11 )
{
}
static void F_203 ( struct V_6 * V_11 )
{
F_2 ( L_81 , V_11 ) ;
F_70 ( V_11 ) ;
F_73 ( V_136 ) ;
}
static int F_204 ( const int V_225 , struct V_10 * V_16 )
{
static const struct V_14 sin = {
. V_300 = V_25 ,
. V_26 . V_27 = F_205 ( V_301 ) ,
} ;
static const struct V_15 V_17 = {
. V_302 = V_28 ,
. V_29 = V_303 ,
} ;
switch ( V_225 ) {
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
return - V_304 ;
}
return 0 ;
}
static struct V_6 * F_206 ( struct V_305 * args ,
unsigned int V_306 ,
unsigned int V_307 )
{
struct V_6 * V_11 ;
struct V_82 * V_308 ;
if ( args -> V_40 > sizeof( V_11 -> V_12 ) ) {
F_2 ( L_83 ) ;
return F_149 ( - V_309 ) ;
}
V_11 = F_207 ( args -> V_310 , sizeof( * V_308 ) , V_306 ,
V_307 ) ;
if ( V_11 == NULL ) {
F_2 ( L_84
L_85 ) ;
return F_149 ( - V_311 ) ;
}
V_308 = F_29 ( V_11 , struct V_82 , V_11 ) ;
memcpy ( & V_11 -> V_12 , args -> V_312 , args -> V_40 ) ;
V_11 -> V_40 = args -> V_40 ;
if ( args -> V_220 )
memcpy ( & V_308 -> V_220 , args -> V_220 , args -> V_40 ) ;
else {
int V_64 ;
V_64 = F_204 ( args -> V_312 -> V_19 ,
(struct V_10 * ) & V_308 -> V_220 ) ;
if ( V_64 != 0 ) {
F_71 ( V_11 ) ;
return F_149 ( V_64 ) ;
}
}
return V_11 ;
}
static struct V_6 * F_208 ( struct V_305 * args )
{
struct V_13 * V_18 = (struct V_13 * ) args -> V_312 ;
struct V_82 * V_83 ;
struct V_6 * V_11 ;
struct V_6 * V_90 ;
V_11 = F_206 ( args , V_313 ,
V_314 ) ;
if ( F_171 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_315 = 0 ;
V_11 -> V_316 = sizeof( V_100 ) / sizeof( T_1 ) ;
V_11 -> V_317 = V_318 ;
V_11 -> V_319 = V_320 ;
V_11 -> V_135 = V_193 ;
V_11 -> V_321 = V_322 ;
V_11 -> V_70 = & V_323 ;
V_11 -> V_250 = & V_324 ;
F_209 ( & V_83 -> V_245 ,
F_146 ) ;
switch ( V_18 -> V_325 ) {
case V_20 :
if ( V_18 -> V_21 [ 0 ] != '/' ) {
F_2 ( L_86 ,
V_18 -> V_21 ) ;
V_90 = F_149 ( - V_244 ) ;
goto V_326;
}
F_135 ( V_11 ) ;
F_16 ( V_11 , L_87 , V_327 ) ;
V_90 = F_149 ( F_153 ( V_83 ) ) ;
if ( V_90 )
goto V_326;
break;
default:
V_90 = F_149 ( - V_304 ) ;
goto V_326;
}
F_2 ( L_88 ,
V_11 -> V_22 [ V_23 ] ) ;
if ( F_210 ( V_136 ) )
return V_11 ;
V_90 = F_149 ( - V_244 ) ;
V_326:
F_70 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_211 ( struct V_305 * args )
{
struct V_10 * V_12 = args -> V_312 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
V_11 = F_206 ( args , V_328 ,
V_328 ) ;
if ( F_171 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_315 = V_247 ;
V_11 -> V_316 = 0 ;
V_11 -> V_317 = ( 1U << 16 ) - ( V_329 << 3 ) ;
V_11 -> V_319 = V_320 ;
V_11 -> V_135 = V_330 ;
V_11 -> V_321 = V_322 ;
V_11 -> V_70 = & V_331 ;
V_11 -> V_250 = & V_332 ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_214 != F_212 ( 0 ) )
F_135 ( V_11 ) ;
F_209 ( & V_83 -> V_245 ,
F_170 ) ;
F_16 ( V_11 , L_89 , V_333 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_213 != F_212 ( 0 ) )
F_135 ( V_11 ) ;
F_209 ( & V_83 -> V_245 ,
F_170 ) ;
F_16 ( V_11 , L_89 , V_334 ) ;
break;
default:
V_90 = F_149 ( - V_304 ) ;
goto V_326;
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
if ( F_210 ( V_136 ) )
return V_11 ;
V_90 = F_149 ( - V_244 ) ;
V_326:
F_70 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_213 ( struct V_305 * args )
{
struct V_10 * V_12 = args -> V_312 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
unsigned int V_307 = V_314 ;
if ( args -> V_61 & V_335 )
V_307 = V_336 ;
V_11 = F_206 ( args , V_313 ,
V_307 ) ;
if ( F_171 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_315 = V_268 ;
V_11 -> V_316 = sizeof( V_100 ) / sizeof( T_1 ) ;
V_11 -> V_317 = V_318 ;
V_11 -> V_319 = V_320 ;
V_11 -> V_135 = V_193 ;
V_11 -> V_321 = V_322 ;
V_11 -> V_70 = & V_337 ;
V_11 -> V_250 = & V_338 ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_214 != F_212 ( 0 ) )
F_135 ( V_11 ) ;
F_209 ( & V_83 -> V_245 ,
F_180 ) ;
F_16 ( V_11 , L_92 , V_339 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_213 != F_212 ( 0 ) )
F_135 ( V_11 ) ;
F_209 ( & V_83 -> V_245 ,
F_180 ) ;
F_16 ( V_11 , L_92 , V_340 ) ;
break;
default:
V_90 = F_149 ( - V_304 ) ;
goto V_326;
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
if ( F_210 ( V_136 ) )
return V_11 ;
V_90 = F_149 ( - V_244 ) ;
V_326:
F_70 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_214 ( struct V_305 * args )
{
struct V_10 * V_12 = args -> V_312 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_341 * V_342 ;
struct V_6 * V_90 ;
V_11 = F_206 ( args , V_313 ,
V_313 ) ;
if ( F_171 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_315 = V_268 ;
V_11 -> V_316 = sizeof( V_100 ) / sizeof( T_1 ) ;
V_11 -> V_317 = V_318 ;
V_11 -> V_250 = & V_338 ;
F_135 ( V_11 ) ;
V_11 -> V_319 = 0 ;
V_11 -> V_135 = 0 ;
V_11 -> V_321 = 0 ;
V_11 -> V_70 = & V_343 ;
switch ( V_12 -> V_19 ) {
case V_25 :
F_16 ( V_11 , L_92 ,
V_339 ) ;
break;
case V_28 :
F_16 ( V_11 , L_92 ,
V_340 ) ;
break;
default:
V_90 = F_149 ( - V_304 ) ;
goto V_326;
}
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
F_215 ( V_11 ) ;
args -> V_295 -> V_344 = V_11 ;
V_11 -> V_295 = args -> V_295 ;
V_342 = F_29 ( args -> V_295 , struct V_341 , V_345 ) ;
V_83 -> V_7 = V_342 -> V_346 ;
V_83 -> V_86 = V_342 -> V_347 ;
F_155 ( V_11 ) ;
if ( F_210 ( V_136 ) )
return V_11 ;
args -> V_295 -> V_344 = NULL ;
F_216 ( V_11 ) ;
V_90 = F_149 ( - V_244 ) ;
V_326:
F_70 ( V_11 ) ;
return V_90 ;
}
int F_217 ( void )
{
#if F_218 ( V_348 )
if ( ! V_349 )
V_349 = F_219 ( V_350 ) ;
#endif
F_220 ( & V_351 ) ;
F_220 ( & V_352 ) ;
F_220 ( & V_353 ) ;
F_220 ( & V_354 ) ;
return 0 ;
}
void F_221 ( void )
{
#if F_218 ( V_348 )
if ( V_349 ) {
F_222 ( V_349 ) ;
V_349 = NULL ;
}
#endif
F_223 ( & V_351 ) ;
F_223 ( & V_352 ) ;
F_223 ( & V_353 ) ;
F_223 ( & V_354 ) ;
}
static int F_224 ( const char * V_355 ,
const struct V_356 * V_357 ,
unsigned int V_358 , unsigned int V_359 )
{
unsigned int V_360 ;
int V_90 ;
if ( ! V_355 )
return - V_244 ;
V_90 = F_225 ( V_355 , 0 , & V_360 ) ;
if ( V_90 == - V_244 || V_360 < V_358 || V_360 > V_359 )
return - V_244 ;
* ( ( unsigned int * ) V_357 -> V_180 ) = V_360 ;
return 0 ;
}
static int F_226 ( const char * V_355 , const struct V_356 * V_357 )
{
return F_224 ( V_355 , V_357 ,
V_361 ,
V_362 ) ;
}
static int F_227 ( const char * V_355 ,
const struct V_356 * V_357 )
{
return F_224 ( V_355 , V_357 ,
V_363 ,
V_364 ) ;
}
static int F_228 ( const char * V_355 ,
const struct V_356 * V_357 )
{
return F_224 ( V_355 , V_357 ,
V_363 ,
V_336 ) ;
}
