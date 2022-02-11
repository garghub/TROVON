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
if ( F_40 ( V_74 > 0 ) || V_103 == 0 ) {
V_89 -> V_94 += V_74 ;
V_89 -> V_106 += V_74 ;
if ( F_40 ( V_89 -> V_94 >= V_89 -> V_93 ) ) {
V_89 -> V_94 = 0 ;
return 0 ;
}
V_103 = - V_91 ;
}
switch ( V_103 ) {
case - V_107 :
case - V_91 :
V_103 = F_30 ( V_81 ) ;
break;
default:
F_2 ( L_12 ,
- V_103 ) ;
case - V_108 :
F_41 ( V_11 ) ;
V_103 = - V_97 ;
}
return V_103 ;
}
static int F_42 ( struct V_80 * V_81 )
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
if ( ! F_43 ( V_11 ) )
return - V_97 ;
V_103 = F_25 ( V_83 -> V_7 , F_4 ( V_11 ) , V_11 -> V_40 ,
V_55 , V_89 -> V_94 , true , & V_74 ) ;
F_2 ( L_13 ,
V_55 -> V_73 - V_89 -> V_94 , V_103 ) ;
if ( V_103 == - V_109 )
goto V_110;
if ( V_74 > 0 || V_103 == 0 ) {
V_89 -> V_106 += V_74 ;
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
case - V_107 :
case - V_108 :
case - V_112 :
case - V_109 :
F_27 ( V_76 , & V_83 -> V_7 -> V_61 ) ;
}
return V_103 ;
}
static void F_44 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
if ( V_7 != NULL ) {
F_45 ( V_7 , V_113 ) ;
F_46 ( V_11 , V_7 ) ;
}
}
static int F_47 ( struct V_80 * V_81 )
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
if ( V_81 -> V_114 & V_115 )
V_56 = false ;
while ( 1 ) {
V_74 = 0 ;
V_103 = F_25 ( V_83 -> V_7 , NULL , 0 , V_55 ,
V_89 -> V_94 , V_56 , & V_74 ) ;
F_2 ( L_14 ,
V_55 -> V_73 - V_89 -> V_94 , V_103 ) ;
if ( F_26 ( V_74 == 0 && V_103 < 0 ) )
break;
V_89 -> V_94 += V_74 ;
V_89 -> V_106 += V_74 ;
if ( F_40 ( V_89 -> V_94 >= V_89 -> V_93 ) ) {
V_89 -> V_94 = 0 ;
return 0 ;
}
if ( V_74 != 0 )
continue;
V_103 = - V_91 ;
break;
}
switch ( V_103 ) {
case - V_75 :
V_103 = - V_97 ;
break;
case - V_107 :
case - V_91 :
V_103 = F_30 ( V_81 ) ;
break;
default:
F_2 ( L_12 ,
- V_103 ) ;
case - V_116 :
F_44 ( V_11 ) ;
case - V_112 :
case - V_97 :
case - V_108 :
F_27 ( V_76 , & V_83 -> V_7 -> V_61 ) ;
}
return V_103 ;
}
static void F_48 ( struct V_6 * V_11 , struct V_80 * V_81 )
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
F_49 ( V_11 , V_81 ) ;
}
static void F_50 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_83 -> V_121 = V_8 -> V_122 ;
V_83 -> V_123 = V_8 -> V_124 ;
V_83 -> V_125 = V_8 -> V_98 ;
V_83 -> V_126 = V_8 -> V_127 ;
}
static void F_51 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_8 -> V_122 = V_83 -> V_121 ;
V_8 -> V_124 = V_83 -> V_123 ;
V_8 -> V_98 = V_83 -> V_125 ;
V_8 -> V_127 = V_83 -> V_126 ;
}
static void F_52 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
int V_64 ;
F_53 ( & V_8 -> V_128 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
V_64 = - V_8 -> V_129 ;
if ( V_64 == 0 )
goto V_78;
F_2 ( L_15 ,
V_11 , - V_64 ) ;
F_54 ( V_11 , V_8 -> V_130 , V_64 ) ;
if ( F_33 ( V_131 , & V_11 -> V_120 ) )
goto V_78;
F_55 ( V_11 , V_64 ) ;
V_78:
F_56 ( & V_8 -> V_128 ) ;
}
static void F_57 ( struct V_82 * V_83 )
{
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_7 * V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
return;
V_83 -> V_132 = 0 ;
F_58 ( & V_8 -> V_128 ) ;
V_83 -> V_86 = NULL ;
V_83 -> V_7 = NULL ;
V_8 -> V_9 = NULL ;
F_51 ( V_83 , V_8 ) ;
F_59 ( & V_8 -> V_128 ) ;
F_60 ( & V_83 -> V_11 , V_7 ) ;
F_61 ( V_7 ) ;
}
static void F_41 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_2 ( L_16 , V_11 ) ;
F_62 ( & V_83 -> V_133 ) ;
F_57 ( V_83 ) ;
V_11 -> V_134 = 0 ;
F_63 () ;
F_27 ( V_135 , & V_11 -> V_120 ) ;
F_27 ( V_119 , & V_11 -> V_120 ) ;
F_27 ( V_136 , & V_11 -> V_120 ) ;
F_64 () ;
F_65 ( V_11 ) ;
}
static void F_66 ( struct V_6 * V_11 )
{
if ( F_67 ( V_137 , & V_11 -> V_120 ) )
F_41 ( V_11 ) ;
else
F_44 ( V_11 ) ;
}
static void F_68 ( struct V_6 * V_11 )
{
F_19 ( V_11 ) ;
F_69 ( V_11 ) ;
}
static void F_70 ( struct V_6 * V_11 )
{
F_2 ( L_17 , V_11 ) ;
F_41 ( V_11 ) ;
F_68 ( V_11 ) ;
F_71 ( V_138 ) ;
}
static int F_72 ( struct V_54 * V_55 , struct V_139 * V_140 )
{
struct V_141 V_142 = {
. V_140 = V_140 ,
. V_59 = sizeof( V_100 ) ,
. V_3 = V_140 -> V_73 - sizeof( V_100 ) ,
} ;
if ( F_73 ( V_55 , 0 , & V_142 , V_143 ) < 0 )
return - 1 ;
if ( V_142 . V_3 )
return - 1 ;
return 0 ;
}
static void F_74 ( struct V_7 * V_8 )
{
struct V_80 * V_81 ;
struct V_6 * V_11 ;
struct V_88 * V_144 ;
struct V_139 * V_140 ;
int V_64 , V_145 , V_146 ;
T_1 V_147 ;
T_5 * V_148 ;
F_53 ( & V_8 -> V_128 ) ;
F_2 ( L_18 , V_105 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 == NULL )
goto V_78;
V_140 = F_75 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_140 == NULL )
goto V_78;
V_145 = V_140 -> V_73 - sizeof( V_100 ) ;
if ( V_145 < 4 ) {
F_2 ( L_19 , V_145 ) ;
goto V_149;
}
V_148 = F_76 ( V_140 , sizeof( V_100 ) , sizeof( V_147 ) , & V_147 ) ;
if ( V_148 == NULL )
goto V_149;
F_77 ( & V_11 -> V_95 ) ;
V_144 = F_78 ( V_11 , * V_148 ) ;
if ( ! V_144 )
goto V_150;
V_81 = V_144 -> V_151 ;
V_146 = V_144 -> V_152 . V_153 ;
if ( V_146 > V_145 )
V_146 = V_145 ;
if ( F_72 ( & V_144 -> V_152 , V_140 ) ) {
F_2 ( L_20 ) ;
goto V_150;
}
F_79 ( V_81 , V_146 ) ;
V_150:
F_80 ( & V_11 -> V_95 ) ;
V_149:
F_81 ( V_8 , V_140 ) ;
V_78:
F_56 ( & V_8 -> V_128 ) ;
}
static void F_82 ( struct V_7 * V_8 )
{
struct V_80 * V_81 ;
struct V_6 * V_11 ;
struct V_88 * V_144 ;
struct V_139 * V_140 ;
int V_64 , V_145 , V_146 ;
T_1 V_147 ;
T_5 * V_148 ;
F_53 ( & V_8 -> V_128 ) ;
F_2 ( L_21 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
if ( ( V_140 = F_75 ( V_8 , 0 , 1 , & V_64 ) ) == NULL )
goto V_78;
V_145 = V_140 -> V_73 - sizeof( struct V_154 ) ;
if ( V_145 < 4 ) {
F_2 ( L_22 , V_145 ) ;
goto V_149;
}
V_148 = F_76 ( V_140 , sizeof( struct V_154 ) ,
sizeof( V_147 ) , & V_147 ) ;
if ( V_148 == NULL )
goto V_149;
F_77 ( & V_11 -> V_95 ) ;
V_144 = F_78 ( V_11 , * V_148 ) ;
if ( ! V_144 )
goto V_150;
V_81 = V_144 -> V_151 ;
if ( ( V_146 = V_144 -> V_152 . V_153 ) > V_145 )
V_146 = V_145 ;
if ( F_83 ( & V_144 -> V_152 , V_140 ) ) {
F_84 ( V_8 , V_155 ) ;
goto V_150;
}
F_84 ( V_8 , V_156 ) ;
F_85 ( V_11 , V_81 , V_146 ) ;
F_79 ( V_81 , V_146 ) ;
V_150:
F_80 ( & V_11 -> V_95 ) ;
V_149:
F_81 ( V_8 , V_140 ) ;
V_78:
F_56 ( & V_8 -> V_128 ) ;
}
static void F_86 ( struct V_6 * V_11 )
{
F_34 ( V_137 , & V_11 -> V_120 ) ;
F_87 ( V_11 ) ;
}
static inline void F_88 ( struct V_6 * V_11 , struct V_141 * V_142 )
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
F_2 ( L_23 ) ;
F_86 ( V_11 ) ;
return;
}
F_2 ( L_24 ,
V_83 -> V_161 ) ;
}
static void F_89 ( struct V_82 * V_83 )
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
static inline void F_90 ( struct V_82 * V_83 , struct V_141 * V_142 )
{
T_4 V_73 , V_157 ;
char * V_158 ;
V_73 = sizeof( V_83 -> V_169 ) - V_83 -> V_160 ;
F_2 ( L_25 , V_73 ) ;
V_158 = ( ( char * ) & V_83 -> V_169 ) + V_83 -> V_160 ;
V_157 = V_143 ( V_142 , V_158 , V_73 ) ;
V_83 -> V_160 += V_157 ;
if ( V_157 != V_73 )
return;
V_83 -> V_162 &= ~ V_167 ;
V_83 -> V_162 |= V_170 ;
V_83 -> V_168 = 4 ;
F_2 ( L_26 ,
( V_83 -> V_162 & V_171 ) ? L_27
: L_28 ,
F_12 ( V_83 -> V_169 ) ) ;
F_89 ( V_83 ) ;
}
static inline void F_91 ( struct V_82 * V_83 ,
struct V_141 * V_142 )
{
T_4 V_73 , V_157 ;
T_1 V_59 ;
char * V_158 ;
V_59 = V_83 -> V_160 - sizeof( V_83 -> V_169 ) ;
V_73 = sizeof( V_83 -> V_172 ) - V_59 ;
F_2 ( L_29 , V_73 ) ;
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
F_2 ( L_30 ) ;
F_86 ( & V_83 -> V_11 ) ;
}
F_89 ( V_83 ) ;
}
static inline void F_92 ( struct V_6 * V_11 ,
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
V_177 = F_73 ( V_176 , V_83 -> V_168 ,
& V_178 , V_143 ) ;
V_142 -> V_3 -= V_177 ;
V_142 -> V_59 += V_177 ;
} else
V_177 = F_73 ( V_176 , V_83 -> V_168 ,
V_142 , V_143 ) ;
if ( V_177 > 0 ) {
V_83 -> V_168 += V_177 ;
V_83 -> V_160 += V_177 ;
}
if ( V_177 != V_73 ) {
V_83 -> V_162 &= ~ V_166 ;
F_2 ( L_31 ,
F_12 ( V_83 -> V_169 ) ) ;
F_2 ( L_32
L_33 ,
V_11 , V_83 -> V_168 ,
V_83 -> V_160 , V_83 -> V_161 ) ;
return;
}
F_2 ( L_34 ,
F_12 ( V_83 -> V_169 ) , V_177 ) ;
F_2 ( L_35
L_36 , V_11 , V_83 -> V_168 ,
V_83 -> V_160 , V_83 -> V_161 ) ;
if ( V_83 -> V_168 == V_89 -> V_152 . V_153 )
V_83 -> V_162 &= ~ V_166 ;
else if ( V_83 -> V_160 == V_83 -> V_161 ) {
if ( V_83 -> V_162 & V_163 )
V_83 -> V_162 &= ~ V_166 ;
}
}
static inline int F_93 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_2 ( L_37 , F_12 ( V_83 -> V_169 ) ) ;
F_77 ( & V_11 -> V_95 ) ;
V_89 = F_78 ( V_11 , V_83 -> V_169 ) ;
if ( ! V_89 ) {
F_2 ( L_38 ,
F_12 ( V_83 -> V_169 ) ) ;
F_80 ( & V_11 -> V_95 ) ;
return - 1 ;
}
F_92 ( V_11 , V_142 , V_89 ) ;
if ( ! ( V_83 -> V_162 & V_166 ) )
F_79 ( V_89 -> V_151 , V_83 -> V_168 ) ;
F_80 ( & V_11 -> V_95 ) ;
return 0 ;
}
static int F_94 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_77 ( & V_11 -> V_95 ) ;
V_89 = F_95 ( V_11 , V_83 -> V_169 ) ;
if ( V_89 == NULL ) {
F_80 ( & V_11 -> V_95 ) ;
F_96 ( V_179 L_39 ) ;
F_87 ( V_11 ) ;
return - 1 ;
}
F_2 ( L_40 , F_12 ( V_89 -> V_180 ) ) ;
F_92 ( V_11 , V_142 , V_89 ) ;
if ( ! ( V_83 -> V_162 & V_166 ) )
F_97 ( V_89 , V_83 -> V_168 ) ;
F_80 ( & V_11 -> V_95 ) ;
return 0 ;
}
static inline int F_98 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
return ( V_83 -> V_162 & V_171 ) ?
F_93 ( V_11 , V_142 ) :
F_94 ( V_11 , V_142 ) ;
}
static inline int F_98 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
return F_93 ( V_11 , V_142 ) ;
}
static void F_99 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( F_98 ( V_11 , V_142 ) == 0 )
F_89 ( V_83 ) ;
else {
V_83 -> V_162 &= ~ V_166 ;
}
}
static inline void F_100 ( struct V_82 * V_83 , struct V_141 * V_142 )
{
T_4 V_73 ;
V_73 = V_83 -> V_161 - V_83 -> V_160 ;
if ( V_73 > V_142 -> V_3 )
V_73 = V_142 -> V_3 ;
V_142 -> V_3 -= V_73 ;
V_142 -> V_59 += V_73 ;
V_83 -> V_160 += V_73 ;
F_2 ( L_41 , V_73 ) ;
F_89 ( V_83 ) ;
}
static int F_101 ( T_6 * V_181 , struct V_139 * V_140 , unsigned int V_59 , T_4 V_73 )
{
struct V_6 * V_11 = V_181 -> V_182 . V_183 ;
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_141 V_142 = {
. V_140 = V_140 ,
. V_59 = V_59 ,
. V_3 = V_73 ,
} ;
F_2 ( L_42 ) ;
do {
F_102 ( V_83 ) ;
if ( V_83 -> V_162 & V_165 ) {
F_88 ( V_11 , & V_142 ) ;
continue;
}
if ( V_83 -> V_162 & V_167 ) {
F_90 ( V_83 , & V_142 ) ;
continue;
}
if ( V_83 -> V_162 & V_170 ) {
F_91 ( V_83 , & V_142 ) ;
continue;
}
if ( V_83 -> V_162 & V_166 ) {
F_99 ( V_11 , & V_142 ) ;
continue;
}
F_100 ( V_83 , & V_142 ) ;
} while ( V_142 . V_3 );
F_102 ( V_83 ) ;
F_2 ( L_43 ) ;
return V_73 - V_142 . V_3 ;
}
static void F_103 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
T_6 V_181 ;
int V_184 ;
unsigned long V_185 = 0 ;
F_2 ( L_44 ) ;
F_53 ( & V_8 -> V_128 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) ) {
V_184 = 0 ;
goto V_78;
}
if ( V_11 -> V_134 )
V_11 -> V_134 = 0 ;
V_181 . V_182 . V_183 = V_11 ;
do {
V_181 . V_3 = 65536 ;
V_184 = F_104 ( V_8 , & V_181 , F_101 ) ;
if ( V_184 > 0 )
V_185 += V_184 ;
} while ( V_184 > 0 );
V_78:
F_105 ( V_11 , V_184 , V_185 ) ;
F_56 ( & V_8 -> V_128 ) ;
}
static void F_106 ( struct V_6 * V_11 ,
unsigned long V_186 )
{
struct V_82 * V_83 ;
if ( F_107 ( V_11 ) )
return;
F_34 ( V_135 , & V_11 -> V_120 ) ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_108 ( V_187 , & V_83 -> V_133 ,
V_186 ) ;
}
static void F_109 ( struct V_6 * V_11 )
{
struct V_82 * V_83 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( ! F_33 ( V_135 , & V_11 -> V_120 ) ||
! F_110 ( & V_83 -> V_133 ) )
return;
F_27 ( V_135 , & V_11 -> V_120 ) ;
F_111 ( V_11 ) ;
}
static void F_112 ( struct V_6 * V_11 )
{
F_63 () ;
F_27 ( V_135 , & V_11 -> V_120 ) ;
F_27 ( V_137 , & V_11 -> V_120 ) ;
F_27 ( V_119 , & V_11 -> V_120 ) ;
F_27 ( V_136 , & V_11 -> V_120 ) ;
F_64 () ;
}
static void F_113 ( struct V_6 * V_11 )
{
F_112 ( V_11 ) ;
F_65 ( V_11 ) ;
}
static void F_114 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
F_53 ( & V_8 -> V_128 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
F_2 ( L_45 , V_11 ) ;
F_2 ( L_46 ,
V_8 -> V_188 , F_32 ( V_11 ) ,
F_115 ( V_8 , V_189 ) ,
F_115 ( V_8 , V_190 ) ,
V_8 -> V_191 ) ;
F_116 ( V_11 , V_8 -> V_130 ) ;
switch ( V_8 -> V_188 ) {
case V_192 :
F_77 ( & V_11 -> V_95 ) ;
if ( ! F_117 ( V_11 ) ) {
struct V_82 * V_83 = F_29 ( V_11 ,
struct V_82 , V_11 ) ;
V_83 -> V_160 = 0 ;
V_83 -> V_161 = 0 ;
V_83 -> V_168 = 0 ;
V_83 -> V_162 =
V_165 | V_167 ;
V_11 -> V_193 ++ ;
F_55 ( V_11 , - V_91 ) ;
}
F_80 ( & V_11 -> V_95 ) ;
break;
case V_194 :
V_11 -> V_193 ++ ;
V_11 -> V_134 = 0 ;
F_34 ( V_136 , & V_11 -> V_120 ) ;
F_63 () ;
F_27 ( V_195 , & V_11 -> V_120 ) ;
F_27 ( V_119 , & V_11 -> V_120 ) ;
F_64 () ;
F_106 ( V_11 , V_196 ) ;
break;
case V_197 :
V_11 -> V_193 ++ ;
F_27 ( V_195 , & V_11 -> V_120 ) ;
F_86 ( V_11 ) ;
case V_198 :
if ( V_11 -> V_134 < V_199 )
V_11 -> V_134 = V_199 ;
break;
case V_200 :
F_34 ( V_136 , & V_11 -> V_120 ) ;
F_106 ( V_11 , V_196 ) ;
F_63 () ;
F_27 ( V_195 , & V_11 -> V_120 ) ;
F_64 () ;
break;
case V_201 :
F_109 ( V_11 ) ;
F_113 ( V_11 ) ;
}
V_78:
F_56 ( & V_8 -> V_128 ) ;
}
static void F_118 ( struct V_7 * V_8 )
{
struct V_39 * V_7 ;
struct V_6 * V_11 ;
if ( F_26 ( ! ( V_7 = V_8 -> V_130 ) ) )
return;
F_27 ( V_96 , & V_7 -> V_61 ) ;
if ( F_26 ( ! ( V_11 = F_3 ( V_8 ) ) ) )
return;
if ( F_67 ( V_76 , & V_7 -> V_61 ) == 0 )
return;
F_119 ( V_11 ) ;
}
static void F_120 ( struct V_7 * V_8 )
{
F_53 ( & V_8 -> V_128 ) ;
if ( F_121 ( V_8 ) )
F_118 ( V_8 ) ;
F_56 ( & V_8 -> V_128 ) ;
}
static void F_122 ( struct V_7 * V_8 )
{
F_53 ( & V_8 -> V_128 ) ;
if ( F_123 ( V_8 ) )
F_118 ( V_8 ) ;
F_56 ( & V_8 -> V_128 ) ;
}
static void F_124 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_7 * V_8 = V_83 -> V_86 ;
if ( V_83 -> V_202 ) {
V_8 -> V_203 |= V_204 ;
V_8 -> V_205 = V_83 -> V_202 * V_11 -> V_206 * 2 ;
}
if ( V_83 -> V_207 ) {
V_8 -> V_203 |= V_208 ;
V_8 -> V_209 = V_83 -> V_207 * V_11 -> V_206 * 2 ;
V_8 -> V_98 ( V_8 ) ;
}
}
static void F_125 ( struct V_6 * V_11 , T_4 V_207 , T_4 V_202 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_83 -> V_207 = 0 ;
if ( V_207 )
V_83 -> V_207 = V_207 + 1024 ;
V_83 -> V_202 = 0 ;
if ( V_202 )
V_83 -> V_202 = V_202 + 1024 ;
F_124 ( V_11 ) ;
}
static void F_126 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
F_85 ( V_11 , V_81 , - V_210 ) ;
}
static unsigned short F_127 ( void )
{
unsigned short V_211 = V_212 - V_213 ;
unsigned short rand = ( unsigned short ) F_128 () % V_211 ;
return rand + V_213 ;
}
static void F_129 ( struct V_6 * V_11 , unsigned short V_214 )
{
F_2 ( L_47 , V_11 , V_214 ) ;
F_130 ( F_4 ( V_11 ) , V_214 ) ;
F_17 ( V_11 ) ;
}
static unsigned short F_131 ( struct V_82 * V_83 )
{
unsigned short V_214 = V_83 -> V_132 ;
if ( V_214 == 0 && V_83 -> V_11 . V_215 )
V_214 = F_127 () ;
return V_214 ;
}
static unsigned short F_132 ( struct V_82 * V_83 , unsigned short V_214 )
{
if ( V_83 -> V_132 != 0 )
V_83 -> V_132 = 0 ;
if ( ! V_83 -> V_11 . V_215 )
return 0 ;
if ( V_214 <= V_213 || V_214 > V_212 )
return V_212 ;
return -- V_214 ;
}
static int F_133 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
struct V_216 V_217 ;
int V_64 , V_218 = 0 ;
unsigned short V_214 = F_131 ( V_83 ) ;
unsigned short V_219 ;
if ( V_214 == 0 )
return 0 ;
memcpy ( & V_217 , & V_83 -> V_220 , V_83 -> V_11 . V_40 ) ;
do {
F_130 ( (struct V_10 * ) & V_217 , V_214 ) ;
V_64 = F_134 ( V_7 , (struct V_10 * ) & V_217 ,
V_83 -> V_11 . V_40 ) ;
if ( V_64 == 0 ) {
V_83 -> V_132 = V_214 ;
break;
}
V_219 = V_214 ;
V_214 = F_132 ( V_83 , V_214 ) ;
if ( V_214 > V_219 )
V_218 ++ ;
} while ( V_64 == - V_221 && V_218 != 2 );
if ( V_217 . V_222 == V_25 )
F_2 ( L_48 , V_105 ,
& ( (struct V_14 * ) & V_217 ) -> V_26 ,
V_214 , V_64 ? L_49 : L_50 , V_64 ) ;
else
F_2 ( L_51 , V_105 ,
& ( (struct V_15 * ) & V_217 ) -> V_29 ,
V_214 , V_64 ? L_49 : L_50 , V_64 ) ;
return V_64 ;
}
static void F_135 ( struct V_80 * V_81 )
{
F_136 () ;
F_137 ( F_138 ( V_81 -> V_223 -> V_224 ) ) ;
F_139 () ;
}
static void F_140 ( struct V_6 * V_11 , unsigned short V_214 )
{
}
static inline void F_141 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_142 ( V_8 , L_52 ,
& V_225 [ 1 ] , L_53 , & V_226 [ 1 ] ) ;
}
static inline void F_143 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_142 ( V_8 , L_54 ,
& V_225 [ 0 ] , L_55 , & V_226 [ 0 ] ) ;
}
static inline void F_144 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_142 ( V_8 , L_56 ,
& V_225 [ 1 ] , L_57 , & V_226 [ 1 ] ) ;
}
static inline void F_145 ( int V_227 , struct V_39 * V_7 )
{
F_146 ( F_147 ( V_7 -> V_8 ) ) ;
if ( F_147 ( V_7 -> V_8 ) )
return;
switch ( V_227 ) {
case V_20 :
F_141 ( V_7 ) ;
break;
case V_25 :
F_143 ( V_7 ) ;
break;
case V_28 :
F_144 ( V_7 ) ;
break;
}
}
static inline void F_141 ( struct V_39 * V_7 )
{
}
static inline void F_143 ( struct V_39 * V_7 )
{
}
static inline void F_144 ( struct V_39 * V_7 )
{
}
static inline void F_145 ( int V_227 , struct V_39 * V_7 )
{
}
static void F_148 ( struct V_228 * V_229 )
{
}
static struct V_39 * F_149 ( struct V_6 * V_11 ,
struct V_82 * V_83 , int V_227 , int type , int V_33 )
{
struct V_39 * V_7 ;
int V_64 ;
V_64 = F_150 ( V_11 -> V_230 , V_227 , type , V_33 , & V_7 , 1 ) ;
if ( V_64 < 0 ) {
F_2 ( L_58 ,
V_33 , - V_64 ) ;
goto V_78;
}
F_145 ( V_227 , V_7 ) ;
V_64 = F_133 ( V_83 , V_7 ) ;
if ( V_64 ) {
F_61 ( V_7 ) ;
goto V_78;
}
return V_7 ;
V_78:
return F_151 ( V_64 ) ;
}
static int F_152 ( struct V_6 * V_11 ,
struct V_39 * V_7 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_58 ( & V_8 -> V_128 ) ;
F_50 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_122 = F_74 ;
V_8 -> V_98 = F_120 ;
V_8 -> V_127 = F_52 ;
V_8 -> V_231 = V_232 ;
F_153 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_59 ( & V_8 -> V_128 ) ;
}
V_11 -> V_233 . V_234 ++ ;
V_11 -> V_233 . V_235 = V_236 ;
return F_154 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , 0 ) ;
}
static int F_155 ( struct V_82 * V_83 )
{
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 ;
int V_103 = - V_237 ;
F_27 ( V_135 , & V_11 -> V_120 ) ;
V_103 = F_150 ( V_11 -> V_230 , V_20 ,
V_238 , 0 , & V_7 , 1 ) ;
if ( V_103 < 0 ) {
F_2 ( L_59
L_60 , - V_103 ) ;
goto V_78;
}
F_141 ( V_7 ) ;
F_2 ( L_61 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
V_103 = F_152 ( V_11 , V_7 ) ;
F_156 ( V_11 , V_7 , V_103 ) ;
switch ( V_103 ) {
case 0 :
F_2 ( L_62 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
F_157 ( V_11 ) ;
case - V_107 :
break;
case - V_239 :
F_2 ( L_63 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
case - V_112 :
F_2 ( L_64 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
default:
F_96 ( V_240 L_65 ,
V_105 , - V_103 ,
V_11 -> V_22 [ V_23 ] ) ;
}
V_78:
F_111 ( V_11 ) ;
F_55 ( V_11 , V_103 ) ;
return V_103 ;
}
static void F_158 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
int V_90 ;
if ( F_159 ( V_81 ) ) {
F_160 ( V_81 , - V_97 ) ;
return;
}
V_90 = F_155 ( V_83 ) ;
if ( V_90 && ! F_161 ( V_81 ) )
F_162 ( 15000 ) ;
}
static void F_163 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 ,
V_11 ) ;
if ( V_11 -> V_241 )
F_164 ( V_83 -> V_86 ) ;
}
int F_165 ( struct V_6 * V_11 , int V_242 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 ,
V_11 ) ;
int V_64 = 0 ;
if ( V_242 ) {
V_11 -> V_241 ++ ;
F_163 ( V_11 ) ;
} else if ( V_11 -> V_241 ) {
V_11 -> V_241 -- ;
F_166 ( V_83 -> V_86 ) ;
}
return V_64 ;
}
static void F_163 ( struct V_6 * V_11 )
{
}
static void F_167 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_58 ( & V_8 -> V_128 ) ;
F_50 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_122 = F_82 ;
V_8 -> V_98 = F_120 ;
V_8 -> V_231 = V_232 ;
F_157 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_163 ( V_11 ) ;
F_59 ( & V_8 -> V_128 ) ;
}
F_124 ( V_11 ) ;
}
static void F_168 ( struct V_228 * V_229 )
{
struct V_82 * V_83 =
F_29 ( V_229 , struct V_82 , V_133 . V_229 ) ;
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 = V_83 -> V_7 ;
int V_103 = - V_237 ;
F_57 ( V_83 ) ;
V_7 = F_149 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_243 , V_244 ) ;
if ( F_169 ( V_7 ) )
goto V_78;
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
F_167 ( V_11 , V_7 ) ;
F_156 ( V_11 , V_7 , 0 ) ;
V_103 = 0 ;
V_78:
F_111 ( V_11 ) ;
F_55 ( V_11 , V_103 ) ;
}
static void F_170 ( struct V_82 * V_83 )
{
int V_245 ;
struct V_10 V_246 ;
F_2 ( L_68 , V_83 ) ;
memset ( & V_246 , 0 , sizeof( V_246 ) ) ;
V_246 . V_19 = V_247 ;
V_245 = F_154 ( V_83 -> V_7 , & V_246 , sizeof( V_246 ) , 0 ) ;
F_171 ( & V_83 -> V_11 ,
V_83 -> V_7 , V_245 ) ;
if ( ! V_245 )
F_112 ( & V_83 -> V_11 ) ;
F_2 ( L_69 , V_245 ) ;
}
static void F_172 ( struct V_82 * V_83 )
{
unsigned int V_120 = V_83 -> V_86 -> V_188 ;
if ( V_120 == V_201 && V_83 -> V_7 -> V_120 == V_248 ) {
if ( V_83 -> V_86 -> V_191 == 0 )
return;
F_2 ( L_70 ,
V_105 , V_83 -> V_86 -> V_191 ) ;
}
if ( ( 1 << V_120 ) & ( V_249 | V_250 ) ) {
if ( V_83 -> V_86 -> V_191 == 0 )
return;
F_2 ( L_71
L_72 ,
V_105 , V_83 -> V_86 -> V_191 ) ;
}
F_170 ( V_83 ) ;
}
static int F_173 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
int V_90 = - V_97 ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
unsigned int V_251 = V_11 -> V_186 -> V_252 / V_253 ;
unsigned int V_254 = V_11 -> V_186 -> V_255 + 1 ;
unsigned int V_256 = 1 ;
F_174 ( V_7 , V_257 , V_258 ,
( char * ) & V_256 , sizeof( V_256 ) ) ;
F_174 ( V_7 , V_259 , V_260 ,
( char * ) & V_251 , sizeof( V_251 ) ) ;
F_174 ( V_7 , V_259 , V_261 ,
( char * ) & V_251 , sizeof( V_251 ) ) ;
F_174 ( V_7 , V_259 , V_262 ,
( char * ) & V_254 , sizeof( V_254 ) ) ;
F_58 ( & V_8 -> V_128 ) ;
F_50 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_122 = F_103 ;
V_8 -> V_124 = F_114 ;
V_8 -> V_98 = F_122 ;
V_8 -> V_127 = F_52 ;
V_8 -> V_231 = V_232 ;
V_8 -> V_203 |= V_263 ;
F_175 ( V_8 , V_264 ) ;
F_176 ( V_8 ) -> V_265 = 0 ;
F_176 ( V_8 ) -> V_266 |= V_267 ;
F_153 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_59 ( & V_8 -> V_128 ) ;
}
if ( ! F_43 ( V_11 ) )
goto V_78;
F_163 ( V_11 ) ;
V_11 -> V_233 . V_234 ++ ;
V_11 -> V_233 . V_235 = V_236 ;
V_90 = F_154 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , V_268 ) ;
switch ( V_90 ) {
case 0 :
case - V_269 :
if ( V_11 -> V_134 < V_199 )
V_11 -> V_134 = V_199 ;
}
V_78:
return V_90 ;
}
static void F_177 ( struct V_228 * V_229 )
{
struct V_82 * V_83 =
F_29 ( V_229 , struct V_82 , V_133 . V_229 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
int V_103 = - V_237 ;
if ( ! V_7 ) {
F_27 ( V_135 , & V_11 -> V_120 ) ;
V_7 = F_149 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_238 , V_270 ) ;
if ( F_169 ( V_7 ) ) {
V_103 = F_178 ( V_7 ) ;
goto V_78;
}
} else {
int V_271 ;
V_271 = F_67 ( V_135 ,
& V_11 -> V_120 ) ;
F_34 ( V_131 , & V_11 -> V_120 ) ;
F_172 ( V_83 ) ;
F_27 ( V_131 , & V_11 -> V_120 ) ;
if ( V_271 )
goto V_272;
}
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
V_103 = F_173 ( V_11 , V_7 ) ;
F_156 ( V_11 , V_7 , V_103 ) ;
F_2 ( L_73 ,
V_11 , - V_103 , F_32 ( V_11 ) ,
V_7 -> V_8 -> V_188 ) ;
switch ( V_103 ) {
default:
F_96 ( L_74 ,
V_105 , V_103 ) ;
case - V_273 :
F_86 ( V_11 ) ;
break;
case 0 :
case - V_269 :
case - V_274 :
F_111 ( V_11 ) ;
return;
case - V_275 :
case - V_112 :
case - V_116 :
case - V_111 :
case - V_107 :
goto V_78;
}
V_272:
V_103 = - V_91 ;
V_78:
F_111 ( V_11 ) ;
F_55 ( V_11 , V_103 ) ;
}
static void F_179 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( V_83 -> V_7 != NULL && ! F_161 ( V_81 ) ) {
F_2 ( L_75
L_76 ,
V_11 , V_11 -> V_134 / V_253 ) ;
F_108 ( V_187 ,
& V_83 -> V_133 ,
V_11 -> V_134 ) ;
V_11 -> V_134 <<= 1 ;
if ( V_11 -> V_134 < V_199 )
V_11 -> V_134 = V_199 ;
if ( V_11 -> V_134 > V_276 )
V_11 -> V_134 = V_276 ;
} else {
F_2 ( L_77 , V_11 ) ;
F_108 ( V_187 ,
& V_83 -> V_133 , 0 ) ;
}
}
static void F_180 ( struct V_6 * V_11 , struct V_277 * V_278 )
{
long V_279 = 0 ;
if ( F_32 ( V_11 ) )
V_279 = ( long ) ( V_236 - V_11 -> V_280 ) / V_253 ;
F_181 ( V_278 , L_78
L_79 ,
V_11 -> V_233 . V_281 ,
V_11 -> V_233 . V_234 ,
V_11 -> V_233 . V_282 ,
V_279 ,
V_11 -> V_233 . V_283 ,
V_11 -> V_233 . V_284 ,
V_11 -> V_233 . V_285 ,
V_11 -> V_233 . V_286 ,
V_11 -> V_233 . V_287 ,
V_11 -> V_233 . V_288 ,
V_11 -> V_233 . V_289 ,
V_11 -> V_233 . V_290 ) ;
}
static void F_182 ( struct V_6 * V_11 , struct V_277 * V_278 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_181 ( V_278 , L_80
L_81 ,
V_83 -> V_132 ,
V_11 -> V_233 . V_281 ,
V_11 -> V_233 . V_283 ,
V_11 -> V_233 . V_284 ,
V_11 -> V_233 . V_285 ,
V_11 -> V_233 . V_286 ,
V_11 -> V_233 . V_287 ,
V_11 -> V_233 . V_288 ,
V_11 -> V_233 . V_289 ,
V_11 -> V_233 . V_290 ) ;
}
static void F_183 ( struct V_6 * V_11 , struct V_277 * V_278 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
long V_279 = 0 ;
if ( F_32 ( V_11 ) )
V_279 = ( long ) ( V_236 - V_11 -> V_280 ) / V_253 ;
F_181 ( V_278 , L_82
L_79 ,
V_83 -> V_132 ,
V_11 -> V_233 . V_281 ,
V_11 -> V_233 . V_234 ,
V_11 -> V_233 . V_282 ,
V_279 ,
V_11 -> V_233 . V_283 ,
V_11 -> V_233 . V_284 ,
V_11 -> V_233 . V_285 ,
V_11 -> V_233 . V_286 ,
V_11 -> V_233 . V_287 ,
V_11 -> V_233 . V_288 ,
V_11 -> V_233 . V_289 ,
V_11 -> V_233 . V_290 ) ;
}
static void * F_184 ( struct V_80 * V_81 , T_4 V_60 )
{
struct V_58 * V_58 ;
struct V_291 * V_4 ;
F_146 ( V_60 > V_292 - sizeof( struct V_291 ) ) ;
if ( V_60 > V_292 - sizeof( struct V_291 ) )
return NULL ;
V_58 = F_185 ( V_24 ) ;
if ( ! V_58 )
return NULL ;
V_4 = F_186 ( V_58 ) ;
V_4 -> V_73 = V_292 ;
return V_4 -> V_183 ;
}
static void F_187 ( void * V_293 )
{
struct V_291 * V_4 ;
if ( ! V_293 )
return;
V_4 = F_29 ( V_293 , struct V_291 , V_183 ) ;
F_188 ( ( unsigned long ) V_4 ) ;
}
static int F_189 ( struct V_88 * V_89 )
{
int V_73 ;
struct V_54 * V_294 = & V_89 -> V_102 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
unsigned long V_295 ;
unsigned long V_296 ;
F_37 ( V_294 ) ;
V_296 = ( unsigned long ) V_294 -> V_79 [ 0 ] . V_52 & ~ V_69 ;
V_295 = ( unsigned long ) V_294 -> V_77 [ 0 ] . V_52 & ~ V_69 ;
V_73 = F_190 ( V_7 , V_294 ,
F_191 ( V_294 -> V_77 [ 0 ] . V_52 ) , V_295 ,
V_294 -> V_79 [ 0 ] . V_52 , V_296 ) ;
if ( V_73 != V_294 -> V_73 ) {
F_96 ( V_297 L_83 ) ;
V_73 = - V_91 ;
}
return V_73 ;
}
static int F_192 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_298 * V_11 ;
T_1 V_73 ;
F_2 ( L_84 , F_12 ( V_89 -> V_180 ) ) ;
V_11 = V_89 -> V_85 -> V_299 ;
if ( ! F_193 ( & V_11 -> V_300 ) ) {
F_194 ( & V_11 -> V_301 , V_81 , NULL ) ;
if ( ! F_193 ( & V_11 -> V_300 ) )
return - V_91 ;
F_195 ( & V_11 -> V_301 , V_81 ) ;
}
if ( F_33 ( V_302 , & V_11 -> V_303 ) )
V_73 = - V_97 ;
else
V_73 = F_189 ( V_89 ) ;
F_196 ( & V_11 -> V_300 ) ;
if ( V_73 > 0 )
V_73 = 0 ;
return V_73 ;
}
static void F_197 ( struct V_6 * V_11 )
{
}
static void F_198 ( struct V_6 * V_11 )
{
F_2 ( L_85 , V_11 ) ;
F_68 ( V_11 ) ;
F_71 ( V_138 ) ;
}
static int F_199 ( const int V_227 , struct V_10 * V_16 )
{
static const struct V_14 sin = {
. V_304 = V_25 ,
. V_26 . V_27 = F_200 ( V_305 ) ,
} ;
static const struct V_15 V_17 = {
. V_306 = V_28 ,
. V_29 = V_307 ,
} ;
switch ( V_227 ) {
case V_20 :
break;
case V_25 :
memcpy ( V_16 , & sin , sizeof( sin ) ) ;
break;
case V_28 :
memcpy ( V_16 , & V_17 , sizeof( V_17 ) ) ;
break;
default:
F_2 ( L_86 , V_105 ) ;
return - V_308 ;
}
return 0 ;
}
static struct V_6 * F_201 ( struct V_309 * args ,
unsigned int V_310 ,
unsigned int V_311 )
{
struct V_6 * V_11 ;
struct V_82 * V_312 ;
if ( args -> V_40 > sizeof( V_11 -> V_12 ) ) {
F_2 ( L_87 ) ;
return F_151 ( - V_313 ) ;
}
V_11 = F_202 ( args -> V_314 , sizeof( * V_312 ) , V_310 ,
V_311 ) ;
if ( V_11 == NULL ) {
F_2 ( L_88
L_89 ) ;
return F_151 ( - V_315 ) ;
}
V_312 = F_29 ( V_11 , struct V_82 , V_11 ) ;
memcpy ( & V_11 -> V_12 , args -> V_316 , args -> V_40 ) ;
V_11 -> V_40 = args -> V_40 ;
if ( args -> V_220 )
memcpy ( & V_312 -> V_220 , args -> V_220 , args -> V_40 ) ;
else {
int V_64 ;
V_64 = F_199 ( args -> V_316 -> V_19 ,
(struct V_10 * ) & V_312 -> V_220 ) ;
if ( V_64 != 0 ) {
F_69 ( V_11 ) ;
return F_151 ( V_64 ) ;
}
}
return V_11 ;
}
static struct V_6 * F_203 ( struct V_309 * args )
{
struct V_13 * V_18 = (struct V_13 * ) args -> V_316 ;
struct V_82 * V_83 ;
struct V_6 * V_11 ;
struct V_6 * V_90 ;
V_11 = F_201 ( args , V_317 ,
V_318 ) ;
if ( F_169 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_319 = 0 ;
V_11 -> V_320 = sizeof( V_100 ) / sizeof( T_1 ) ;
V_11 -> V_321 = V_322 ;
V_11 -> V_323 = V_324 ;
V_11 -> V_134 = V_199 ;
V_11 -> V_325 = V_326 ;
V_11 -> V_70 = & V_327 ;
V_11 -> V_186 = & V_328 ;
F_204 ( & V_83 -> V_133 ,
F_148 ) ;
switch ( V_18 -> V_329 ) {
case V_20 :
if ( V_18 -> V_21 [ 0 ] != '/' ) {
F_2 ( L_90 ,
V_18 -> V_21 ) ;
V_90 = F_151 ( - V_275 ) ;
goto V_330;
}
F_137 ( V_11 ) ;
F_16 ( V_11 , L_91 , V_331 ) ;
V_90 = F_151 ( F_155 ( V_83 ) ) ;
if ( V_90 )
goto V_330;
break;
default:
V_90 = F_151 ( - V_308 ) ;
goto V_330;
}
F_2 ( L_92 ,
V_11 -> V_22 [ V_23 ] ) ;
if ( F_205 ( V_138 ) )
return V_11 ;
V_90 = F_151 ( - V_275 ) ;
V_330:
F_68 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_206 ( struct V_309 * args )
{
struct V_10 * V_12 = args -> V_316 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
V_11 = F_201 ( args , V_332 ,
V_332 ) ;
if ( F_169 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_319 = V_244 ;
V_11 -> V_320 = 0 ;
V_11 -> V_321 = ( 1U << 16 ) - ( V_333 << 3 ) ;
V_11 -> V_323 = V_324 ;
V_11 -> V_134 = V_334 ;
V_11 -> V_325 = V_326 ;
V_11 -> V_70 = & V_335 ;
V_11 -> V_186 = & V_336 ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_337 != F_207 ( 0 ) )
F_137 ( V_11 ) ;
F_204 ( & V_83 -> V_133 ,
F_168 ) ;
F_16 ( V_11 , L_93 , V_338 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_339 != F_207 ( 0 ) )
F_137 ( V_11 ) ;
F_204 ( & V_83 -> V_133 ,
F_168 ) ;
F_16 ( V_11 , L_93 , V_340 ) ;
break;
default:
V_90 = F_151 ( - V_308 ) ;
goto V_330;
}
if ( F_43 ( V_11 ) )
F_2 ( L_94 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_95 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_205 ( V_138 ) )
return V_11 ;
V_90 = F_151 ( - V_275 ) ;
V_330:
F_68 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_208 ( struct V_309 * args )
{
struct V_10 * V_12 = args -> V_316 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
unsigned int V_311 = V_318 ;
if ( args -> V_61 & V_341 )
V_311 = V_342 ;
V_11 = F_201 ( args , V_317 ,
V_311 ) ;
if ( F_169 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_319 = V_270 ;
V_11 -> V_320 = sizeof( V_100 ) / sizeof( T_1 ) ;
V_11 -> V_321 = V_322 ;
V_11 -> V_323 = V_324 ;
V_11 -> V_134 = V_199 ;
V_11 -> V_325 = V_326 ;
V_11 -> V_70 = & V_343 ;
V_11 -> V_186 = & V_344 ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_337 != F_207 ( 0 ) )
F_137 ( V_11 ) ;
F_204 ( & V_83 -> V_133 ,
F_177 ) ;
F_16 ( V_11 , L_96 , V_345 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_339 != F_207 ( 0 ) )
F_137 ( V_11 ) ;
F_204 ( & V_83 -> V_133 ,
F_177 ) ;
F_16 ( V_11 , L_96 , V_346 ) ;
break;
default:
V_90 = F_151 ( - V_308 ) ;
goto V_330;
}
if ( F_43 ( V_11 ) )
F_2 ( L_94 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_95 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_205 ( V_138 ) )
return V_11 ;
V_90 = F_151 ( - V_275 ) ;
V_330:
F_68 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_209 ( struct V_309 * args )
{
struct V_10 * V_12 = args -> V_316 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_347 * V_348 ;
struct V_6 * V_90 ;
V_11 = F_201 ( args , V_317 ,
V_317 ) ;
if ( F_169 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_319 = V_270 ;
V_11 -> V_320 = sizeof( V_100 ) / sizeof( T_1 ) ;
V_11 -> V_321 = V_322 ;
V_11 -> V_186 = & V_344 ;
F_137 ( V_11 ) ;
V_11 -> V_323 = 0 ;
V_11 -> V_134 = 0 ;
V_11 -> V_325 = 0 ;
V_11 -> V_70 = & V_349 ;
switch ( V_12 -> V_19 ) {
case V_25 :
F_16 ( V_11 , L_96 ,
V_345 ) ;
break;
case V_28 :
F_16 ( V_11 , L_96 ,
V_346 ) ;
break;
default:
V_90 = F_151 ( - V_308 ) ;
goto V_330;
}
F_2 ( L_94 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
F_210 ( V_11 ) ;
args -> V_299 -> V_350 = V_11 ;
V_11 -> V_299 = args -> V_299 ;
V_348 = F_29 ( args -> V_299 , struct V_347 , V_351 ) ;
V_83 -> V_7 = V_348 -> V_352 ;
V_83 -> V_86 = V_348 -> V_353 ;
F_157 ( V_11 ) ;
if ( F_205 ( V_138 ) )
return V_11 ;
args -> V_299 -> V_350 = NULL ;
F_211 ( V_11 ) ;
V_90 = F_151 ( - V_275 ) ;
V_330:
F_68 ( V_11 ) ;
return V_90 ;
}
int F_212 ( void )
{
#if F_213 ( V_354 )
if ( ! V_355 )
V_355 = F_214 ( V_356 ) ;
#endif
F_215 ( & V_357 ) ;
F_215 ( & V_358 ) ;
F_215 ( & V_359 ) ;
F_215 ( & V_360 ) ;
return 0 ;
}
void F_216 ( void )
{
#if F_213 ( V_354 )
if ( V_355 ) {
F_217 ( V_355 ) ;
V_355 = NULL ;
}
#endif
F_218 ( & V_357 ) ;
F_218 ( & V_358 ) ;
F_218 ( & V_359 ) ;
F_218 ( & V_360 ) ;
}
static int F_219 ( const char * V_361 ,
const struct V_362 * V_363 ,
unsigned int V_364 , unsigned int V_365 )
{
unsigned int V_366 ;
int V_90 ;
if ( ! V_361 )
return - V_275 ;
V_90 = F_220 ( V_361 , 0 , & V_366 ) ;
if ( V_90 == - V_275 || V_366 < V_364 || V_366 > V_365 )
return - V_275 ;
* ( ( unsigned int * ) V_363 -> V_182 ) = V_366 ;
return 0 ;
}
static int F_221 ( const char * V_361 , const struct V_362 * V_363 )
{
return F_219 ( V_361 , V_363 ,
V_367 ,
V_368 ) ;
}
static int F_222 ( const char * V_361 ,
const struct V_362 * V_363 )
{
return F_219 ( V_361 , V_363 ,
V_369 ,
V_370 ) ;
}
static int F_223 ( const char * V_361 ,
const struct V_362 * V_363 )
{
return F_219 ( V_361 , V_363 ,
V_369 ,
V_342 ) ;
}
