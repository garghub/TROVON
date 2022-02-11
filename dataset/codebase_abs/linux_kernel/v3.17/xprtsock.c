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
static int F_22 ( struct V_39 * V_7 , struct V_54 * V_55 , unsigned int V_43 , int V_44 , bool V_56 )
{
T_3 (* F_23)( struct V_39 * V_7 , struct V_57 * V_57 ,
int V_58 , T_4 V_59 , int V_60 );
struct V_57 * * V_61 ;
unsigned int V_62 ;
int V_63 , V_64 = 0 ;
V_62 = V_55 -> V_65 - V_43 ;
V_43 += V_55 -> V_66 ;
V_61 = V_55 -> V_67 + ( V_43 >> V_68 ) ;
V_43 &= ~ V_69 ;
F_23 = V_7 -> V_70 -> V_71 ;
if ( ! V_56 )
F_23 = V_72 ;
for(; ; ) {
unsigned int V_73 = F_24 (unsigned int, PAGE_SIZE - base, remainder) ;
int V_60 = V_49 ;
V_62 -= V_73 ;
if ( V_62 != 0 || V_44 )
V_60 |= V_50 ;
V_63 = F_23 ( V_7 , * V_61 , V_43 , V_73 , V_60 ) ;
if ( V_62 == 0 || V_63 != V_73 )
break;
V_64 += V_63 ;
V_61 ++ ;
V_43 = 0 ;
}
if ( V_64 == 0 )
return V_63 ;
if ( V_63 > 0 )
V_64 += V_63 ;
return V_64 ;
}
static int F_25 ( struct V_39 * V_7 , struct V_10 * V_12 , int V_40 , struct V_54 * V_55 , unsigned int V_43 , bool V_56 )
{
unsigned int V_62 = V_55 -> V_73 - V_43 ;
int V_63 , V_64 = 0 ;
if ( F_26 ( ! V_7 ) )
return - V_74 ;
F_27 ( V_75 , & V_7 -> V_60 ) ;
if ( V_43 != 0 ) {
V_12 = NULL ;
V_40 = 0 ;
}
if ( V_43 < V_55 -> V_76 [ 0 ] . V_53 || V_12 != NULL ) {
unsigned int V_73 = V_55 -> V_76 [ 0 ] . V_53 - V_43 ;
V_62 -= V_73 ;
V_63 = F_20 ( V_7 , V_12 , V_40 , & V_55 -> V_76 [ 0 ] , V_43 , V_62 != 0 ) ;
if ( V_62 == 0 || V_63 != V_73 )
goto V_77;
V_64 += V_63 ;
V_43 = 0 ;
} else
V_43 -= V_55 -> V_76 [ 0 ] . V_53 ;
if ( V_43 < V_55 -> V_65 ) {
unsigned int V_73 = V_55 -> V_65 - V_43 ;
V_62 -= V_73 ;
V_63 = F_22 ( V_7 , V_55 , V_43 , V_62 != 0 , V_56 ) ;
if ( V_62 == 0 || V_63 != V_73 )
goto V_77;
V_64 += V_63 ;
V_43 = 0 ;
} else
V_43 -= V_55 -> V_65 ;
if ( V_43 >= V_55 -> V_78 [ 0 ] . V_53 )
return V_64 ;
V_63 = F_20 ( V_7 , NULL , 0 , & V_55 -> V_78 [ 0 ] , V_43 , 0 ) ;
V_77:
if ( V_64 == 0 )
return V_63 ;
if ( V_63 > 0 )
V_64 += V_63 ;
return V_64 ;
}
static void F_28 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = F_29 ( V_80 -> V_83 -> V_84 , struct V_81 , V_11 ) ;
V_82 -> V_85 -> V_86 -- ;
F_27 ( V_75 , & V_82 -> V_7 -> V_60 ) ;
}
static int F_30 ( struct V_79 * V_80 )
{
struct V_87 * V_88 = V_80 -> V_83 ;
struct V_6 * V_11 = V_88 -> V_84 ;
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_7 * V_8 = V_82 -> V_85 ;
int V_89 = - V_90 ;
F_2 ( L_9 ,
V_80 -> V_91 , V_88 -> V_92 - V_88 -> V_93 ,
V_88 -> V_92 ) ;
F_31 ( & V_11 -> V_94 ) ;
if ( F_32 ( V_11 ) ) {
if ( F_33 ( V_75 , & V_82 -> V_7 -> V_60 ) ) {
F_34 ( V_95 , & V_82 -> V_7 -> V_60 ) ;
V_8 -> V_86 ++ ;
F_35 ( V_80 , F_28 ) ;
}
} else {
F_27 ( V_75 , & V_82 -> V_7 -> V_60 ) ;
V_89 = - V_96 ;
}
F_36 ( & V_11 -> V_94 ) ;
V_8 -> V_97 ( V_8 ) ;
return V_89 ;
}
static inline void F_37 ( struct V_54 * V_4 )
{
T_1 V_98 = V_4 -> V_73 - sizeof( V_99 ) ;
V_99 * V_43 = V_4 -> V_76 [ 0 ] . V_52 ;
* V_43 = F_38 ( V_100 | V_98 ) ;
}
static int F_39 ( struct V_79 * V_80 )
{
struct V_87 * V_88 = V_80 -> V_83 ;
struct V_6 * V_11 = V_88 -> V_84 ;
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_54 * V_55 = & V_88 -> V_101 ;
int V_102 ;
F_37 ( & V_88 -> V_101 ) ;
F_1 ( L_10 ,
V_88 -> V_103 -> V_52 , V_88 -> V_103 -> V_53 ) ;
V_102 = F_25 ( V_82 -> V_7 , NULL , 0 ,
V_55 , V_88 -> V_93 , true ) ;
F_2 ( L_11 ,
V_104 , V_55 -> V_73 - V_88 -> V_93 , V_102 ) ;
if ( F_40 ( V_102 >= 0 ) ) {
V_88 -> V_93 += V_102 ;
V_88 -> V_105 += V_102 ;
if ( F_40 ( V_88 -> V_93 >= V_88 -> V_92 ) ) {
V_88 -> V_93 = 0 ;
return 0 ;
}
V_102 = - V_90 ;
}
switch ( V_102 ) {
case - V_106 :
case - V_90 :
V_102 = F_30 ( V_80 ) ;
break;
default:
F_2 ( L_12 ,
- V_102 ) ;
case - V_107 :
F_41 ( V_11 ) ;
V_102 = - V_96 ;
}
return V_102 ;
}
static int F_42 ( struct V_79 * V_80 )
{
struct V_87 * V_88 = V_80 -> V_83 ;
struct V_6 * V_11 = V_88 -> V_84 ;
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_54 * V_55 = & V_88 -> V_101 ;
int V_102 ;
F_1 ( L_10 ,
V_88 -> V_103 -> V_52 ,
V_88 -> V_103 -> V_53 ) ;
if ( ! F_43 ( V_11 ) )
return - V_96 ;
V_102 = F_25 ( V_82 -> V_7 ,
F_4 ( V_11 ) ,
V_11 -> V_40 , V_55 ,
V_88 -> V_93 , true ) ;
F_2 ( L_13 ,
V_55 -> V_73 - V_88 -> V_93 , V_102 ) ;
if ( V_102 >= 0 ) {
V_88 -> V_105 += V_102 ;
if ( V_102 >= V_88 -> V_92 )
return 0 ;
V_102 = - V_90 ;
}
switch ( V_102 ) {
case - V_74 :
V_102 = - V_96 ;
break;
case - V_90 :
V_102 = F_30 ( V_80 ) ;
break;
default:
F_2 ( L_12 ,
- V_102 ) ;
case - V_108 :
case - V_106 :
case - V_107 :
case - V_109 :
F_27 ( V_75 , & V_82 -> V_7 -> V_60 ) ;
}
return V_102 ;
}
static void F_44 ( struct V_6 * V_11 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_39 * V_7 = V_82 -> V_7 ;
if ( V_7 != NULL ) {
F_45 ( V_7 , V_110 ) ;
F_46 ( V_11 , V_7 ) ;
}
}
static int F_47 ( struct V_79 * V_80 )
{
struct V_87 * V_88 = V_80 -> V_83 ;
struct V_6 * V_11 = V_88 -> V_84 ;
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_54 * V_55 = & V_88 -> V_101 ;
bool V_56 = true ;
int V_102 ;
F_37 ( & V_88 -> V_101 ) ;
F_1 ( L_10 ,
V_88 -> V_103 -> V_52 ,
V_88 -> V_103 -> V_53 ) ;
if ( V_80 -> V_111 & V_112 )
V_56 = false ;
while ( 1 ) {
V_102 = F_25 ( V_82 -> V_7 ,
NULL , 0 , V_55 , V_88 -> V_93 ,
V_56 ) ;
F_2 ( L_14 ,
V_55 -> V_73 - V_88 -> V_93 , V_102 ) ;
if ( F_26 ( V_102 < 0 ) )
break;
V_88 -> V_93 += V_102 ;
V_88 -> V_105 += V_102 ;
if ( F_40 ( V_88 -> V_93 >= V_88 -> V_92 ) ) {
V_88 -> V_93 = 0 ;
return 0 ;
}
if ( V_102 != 0 )
continue;
V_102 = - V_90 ;
break;
}
switch ( V_102 ) {
case - V_74 :
V_102 = - V_96 ;
break;
case - V_106 :
case - V_90 :
V_102 = F_30 ( V_80 ) ;
break;
default:
F_2 ( L_12 ,
- V_102 ) ;
case - V_113 :
F_44 ( V_11 ) ;
case - V_109 :
case - V_96 :
case - V_107 :
F_27 ( V_75 , & V_82 -> V_7 -> V_60 ) ;
}
return V_102 ;
}
static void F_48 ( struct V_6 * V_11 , struct V_79 * V_80 )
{
struct V_87 * V_88 ;
if ( V_80 != V_11 -> V_114 )
return;
if ( V_80 == NULL )
goto V_115;
V_88 = V_80 -> V_83 ;
if ( V_88 == NULL )
goto V_115;
if ( V_88 -> V_93 == 0 )
goto V_115;
if ( V_88 -> V_93 == V_88 -> V_101 . V_73 )
goto V_115;
F_34 ( V_116 , & V_11 -> V_117 ) ;
V_115:
F_49 ( V_11 , V_80 ) ;
}
static void F_50 ( struct V_81 * V_82 , struct V_7 * V_8 )
{
V_82 -> V_118 = V_8 -> V_119 ;
V_82 -> V_120 = V_8 -> V_121 ;
V_82 -> V_122 = V_8 -> V_97 ;
V_82 -> V_123 = V_8 -> V_124 ;
}
static void F_51 ( struct V_81 * V_82 , struct V_7 * V_8 )
{
V_8 -> V_119 = V_82 -> V_118 ;
V_8 -> V_121 = V_82 -> V_120 ;
V_8 -> V_97 = V_82 -> V_122 ;
V_8 -> V_124 = V_82 -> V_123 ;
}
static void F_52 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
int V_63 ;
F_53 ( & V_8 -> V_125 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_77;
V_63 = - V_8 -> V_126 ;
if ( V_63 == 0 )
goto V_77;
F_2 ( L_15 ,
V_11 , - V_63 ) ;
F_54 ( V_11 , V_8 -> V_127 , V_63 ) ;
F_55 ( V_11 , V_63 ) ;
V_77:
F_56 ( & V_8 -> V_125 ) ;
}
static void F_57 ( struct V_81 * V_82 )
{
struct V_39 * V_7 = V_82 -> V_7 ;
struct V_7 * V_8 = V_82 -> V_85 ;
if ( V_8 == NULL )
return;
V_82 -> V_128 = 0 ;
F_58 ( & V_8 -> V_125 ) ;
V_82 -> V_85 = NULL ;
V_82 -> V_7 = NULL ;
V_8 -> V_9 = NULL ;
F_51 ( V_82 , V_8 ) ;
F_59 ( & V_8 -> V_125 ) ;
F_60 ( & V_82 -> V_11 , V_7 ) ;
F_61 ( V_7 ) ;
}
static void F_41 ( struct V_6 * V_11 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
F_2 ( L_16 , V_11 ) ;
F_62 ( & V_82 -> V_129 ) ;
F_57 ( V_82 ) ;
V_11 -> V_130 = 0 ;
F_63 () ;
F_27 ( V_131 , & V_11 -> V_117 ) ;
F_27 ( V_116 , & V_11 -> V_117 ) ;
F_27 ( V_132 , & V_11 -> V_117 ) ;
F_64 () ;
F_65 ( V_11 ) ;
}
static void F_66 ( struct V_6 * V_11 )
{
if ( F_67 ( V_133 , & V_11 -> V_117 ) )
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
F_71 ( V_134 ) ;
}
static int F_72 ( struct V_54 * V_55 , struct V_135 * V_136 )
{
struct V_137 V_138 = {
. V_136 = V_136 ,
. V_58 = sizeof( V_99 ) ,
. V_3 = V_136 -> V_73 - sizeof( V_99 ) ,
} ;
if ( F_73 ( V_55 , 0 , & V_138 , V_139 ) < 0 )
return - 1 ;
if ( V_138 . V_3 )
return - 1 ;
return 0 ;
}
static void F_74 ( struct V_7 * V_8 )
{
struct V_79 * V_80 ;
struct V_6 * V_11 ;
struct V_87 * V_140 ;
struct V_135 * V_136 ;
int V_63 , V_141 , V_142 ;
T_1 V_143 ;
T_5 * V_144 ;
F_53 ( & V_8 -> V_125 ) ;
F_2 ( L_18 , V_104 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 == NULL )
goto V_77;
V_136 = F_75 ( V_8 , 0 , 1 , & V_63 ) ;
if ( V_136 == NULL )
goto V_77;
V_141 = V_136 -> V_73 - sizeof( V_99 ) ;
if ( V_141 < 4 ) {
F_2 ( L_19 , V_141 ) ;
goto V_145;
}
V_144 = F_76 ( V_136 , sizeof( V_99 ) , sizeof( V_143 ) , & V_143 ) ;
if ( V_144 == NULL )
goto V_145;
F_77 ( & V_11 -> V_94 ) ;
V_140 = F_78 ( V_11 , * V_144 ) ;
if ( ! V_140 )
goto V_146;
V_80 = V_140 -> V_147 ;
V_142 = V_140 -> V_148 . V_149 ;
if ( V_142 > V_141 )
V_142 = V_141 ;
if ( F_72 ( & V_140 -> V_148 , V_136 ) ) {
F_2 ( L_20 ) ;
goto V_146;
}
F_79 ( V_80 , V_142 ) ;
V_146:
F_80 ( & V_11 -> V_94 ) ;
V_145:
F_81 ( V_8 , V_136 ) ;
V_77:
F_56 ( & V_8 -> V_125 ) ;
}
static void F_82 ( struct V_7 * V_8 )
{
struct V_79 * V_80 ;
struct V_6 * V_11 ;
struct V_87 * V_140 ;
struct V_135 * V_136 ;
int V_63 , V_141 , V_142 ;
T_1 V_143 ;
T_5 * V_144 ;
F_53 ( & V_8 -> V_125 ) ;
F_2 ( L_21 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_77;
if ( ( V_136 = F_75 ( V_8 , 0 , 1 , & V_63 ) ) == NULL )
goto V_77;
V_141 = V_136 -> V_73 - sizeof( struct V_150 ) ;
if ( V_141 < 4 ) {
F_2 ( L_22 , V_141 ) ;
goto V_145;
}
V_144 = F_76 ( V_136 , sizeof( struct V_150 ) ,
sizeof( V_143 ) , & V_143 ) ;
if ( V_144 == NULL )
goto V_145;
F_77 ( & V_11 -> V_94 ) ;
V_140 = F_78 ( V_11 , * V_144 ) ;
if ( ! V_140 )
goto V_146;
V_80 = V_140 -> V_147 ;
if ( ( V_142 = V_140 -> V_148 . V_149 ) > V_141 )
V_142 = V_141 ;
if ( F_83 ( & V_140 -> V_148 , V_136 ) ) {
F_84 ( V_8 , V_151 ) ;
goto V_146;
}
F_84 ( V_8 , V_152 ) ;
F_85 ( V_11 , V_80 , V_142 ) ;
F_79 ( V_80 , V_142 ) ;
V_146:
F_80 ( & V_11 -> V_94 ) ;
V_145:
F_81 ( V_8 , V_136 ) ;
V_77:
F_56 ( & V_8 -> V_125 ) ;
}
static void F_86 ( struct V_6 * V_11 )
{
F_34 ( V_133 , & V_11 -> V_117 ) ;
F_87 ( V_11 ) ;
}
static inline void F_88 ( struct V_6 * V_11 , struct V_137 * V_138 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
T_4 V_73 , V_153 ;
char * V_154 ;
V_154 = ( ( char * ) & V_82 -> V_155 ) + V_82 -> V_156 ;
V_73 = sizeof( V_82 -> V_155 ) - V_82 -> V_156 ;
V_153 = V_139 ( V_138 , V_154 , V_73 ) ;
V_82 -> V_156 += V_153 ;
if ( V_153 != V_73 )
return;
V_82 -> V_157 = F_12 ( V_82 -> V_155 ) ;
if ( V_82 -> V_157 & V_100 )
V_82 -> V_158 |= V_159 ;
else
V_82 -> V_158 &= ~ V_159 ;
V_82 -> V_157 &= V_160 ;
V_82 -> V_158 &= ~ V_161 ;
V_82 -> V_156 = 0 ;
if ( F_26 ( V_82 -> V_157 < 8 ) ) {
F_2 ( L_23 ) ;
F_86 ( V_11 ) ;
return;
}
F_2 ( L_24 ,
V_82 -> V_157 ) ;
}
static void F_89 ( struct V_81 * V_82 )
{
if ( V_82 -> V_156 == V_82 -> V_157 ) {
V_82 -> V_158 |= V_161 ;
V_82 -> V_156 = 0 ;
if ( V_82 -> V_158 & V_159 ) {
V_82 -> V_158 &= ~ V_162 ;
V_82 -> V_158 |= V_163 ;
V_82 -> V_164 = 0 ;
}
}
}
static inline void F_90 ( struct V_81 * V_82 , struct V_137 * V_138 )
{
T_4 V_73 , V_153 ;
char * V_154 ;
V_73 = sizeof( V_82 -> V_165 ) - V_82 -> V_156 ;
F_2 ( L_25 , V_73 ) ;
V_154 = ( ( char * ) & V_82 -> V_165 ) + V_82 -> V_156 ;
V_153 = V_139 ( V_138 , V_154 , V_73 ) ;
V_82 -> V_156 += V_153 ;
if ( V_153 != V_73 )
return;
V_82 -> V_158 &= ~ V_163 ;
V_82 -> V_158 |= V_166 ;
V_82 -> V_164 = 4 ;
F_2 ( L_26 ,
( V_82 -> V_158 & V_167 ) ? L_27
: L_28 ,
F_12 ( V_82 -> V_165 ) ) ;
F_89 ( V_82 ) ;
}
static inline void F_91 ( struct V_81 * V_82 ,
struct V_137 * V_138 )
{
T_4 V_73 , V_153 ;
T_1 V_58 ;
char * V_154 ;
V_58 = V_82 -> V_156 - sizeof( V_82 -> V_165 ) ;
V_73 = sizeof( V_82 -> V_168 ) - V_58 ;
F_2 ( L_29 , V_73 ) ;
V_154 = ( ( char * ) & V_82 -> V_168 ) + V_58 ;
V_153 = V_139 ( V_138 , V_154 , V_73 ) ;
V_82 -> V_156 += V_153 ;
if ( V_153 != V_73 )
return;
V_82 -> V_158 &= ~ V_166 ;
switch ( F_12 ( V_82 -> V_168 ) ) {
case V_169 :
V_82 -> V_158 |= V_170 ;
V_82 -> V_158 |= V_162 ;
V_82 -> V_158 |= V_167 ;
break;
case V_171 :
V_82 -> V_158 |= V_170 ;
V_82 -> V_158 |= V_162 ;
V_82 -> V_158 &= ~ V_167 ;
break;
default:
F_2 ( L_30 ) ;
F_86 ( & V_82 -> V_11 ) ;
}
F_89 ( V_82 ) ;
}
static inline void F_92 ( struct V_6 * V_11 ,
struct V_137 * V_138 ,
struct V_87 * V_88 )
{
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_54 * V_172 ;
T_4 V_73 ;
T_3 V_173 ;
V_172 = & V_88 -> V_148 ;
if ( V_82 -> V_158 & V_170 ) {
memcpy ( V_172 -> V_76 [ 0 ] . V_52 + V_82 -> V_164 ,
& V_82 -> V_168 ,
sizeof( V_82 -> V_168 ) ) ;
V_82 -> V_164 += sizeof( V_82 -> V_168 ) ;
V_82 -> V_158 &= ~ V_170 ;
}
V_73 = V_138 -> V_3 ;
if ( V_73 > V_82 -> V_157 - V_82 -> V_156 ) {
struct V_137 V_174 ;
V_73 = V_82 -> V_157 - V_82 -> V_156 ;
memcpy ( & V_174 , V_138 , sizeof( V_174 ) ) ;
V_174 . V_3 = V_73 ;
V_173 = F_73 ( V_172 , V_82 -> V_164 ,
& V_174 , V_139 ) ;
V_138 -> V_3 -= V_173 ;
V_138 -> V_58 += V_173 ;
} else
V_173 = F_73 ( V_172 , V_82 -> V_164 ,
V_138 , V_139 ) ;
if ( V_173 > 0 ) {
V_82 -> V_164 += V_173 ;
V_82 -> V_156 += V_173 ;
}
if ( V_173 != V_73 ) {
V_82 -> V_158 &= ~ V_162 ;
F_2 ( L_31 ,
F_12 ( V_82 -> V_165 ) ) ;
F_2 ( L_32
L_33 ,
V_11 , V_82 -> V_164 ,
V_82 -> V_156 , V_82 -> V_157 ) ;
return;
}
F_2 ( L_34 ,
F_12 ( V_82 -> V_165 ) , V_173 ) ;
F_2 ( L_35
L_36 , V_11 , V_82 -> V_164 ,
V_82 -> V_156 , V_82 -> V_157 ) ;
if ( V_82 -> V_164 == V_88 -> V_148 . V_149 )
V_82 -> V_158 &= ~ V_162 ;
else if ( V_82 -> V_156 == V_82 -> V_157 ) {
if ( V_82 -> V_158 & V_159 )
V_82 -> V_158 &= ~ V_162 ;
}
}
static inline int F_93 ( struct V_6 * V_11 ,
struct V_137 * V_138 )
{
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_87 * V_88 ;
F_2 ( L_37 , F_12 ( V_82 -> V_165 ) ) ;
F_77 ( & V_11 -> V_94 ) ;
V_88 = F_78 ( V_11 , V_82 -> V_165 ) ;
if ( ! V_88 ) {
F_2 ( L_38 ,
F_12 ( V_82 -> V_165 ) ) ;
F_80 ( & V_11 -> V_94 ) ;
return - 1 ;
}
F_92 ( V_11 , V_138 , V_88 ) ;
if ( ! ( V_82 -> V_158 & V_162 ) )
F_79 ( V_88 -> V_147 , V_82 -> V_164 ) ;
F_80 ( & V_11 -> V_94 ) ;
return 0 ;
}
static int F_94 ( struct V_6 * V_11 ,
struct V_137 * V_138 )
{
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_87 * V_88 ;
F_77 ( & V_11 -> V_94 ) ;
V_88 = F_95 ( V_11 , V_82 -> V_165 ) ;
if ( V_88 == NULL ) {
F_80 ( & V_11 -> V_94 ) ;
F_96 ( V_175 L_39 ) ;
F_87 ( V_11 ) ;
return - 1 ;
}
F_2 ( L_40 , F_12 ( V_88 -> V_176 ) ) ;
F_92 ( V_11 , V_138 , V_88 ) ;
if ( ! ( V_82 -> V_158 & V_162 ) )
F_97 ( V_88 , V_82 -> V_164 ) ;
F_80 ( & V_11 -> V_94 ) ;
return 0 ;
}
static inline int F_98 ( struct V_6 * V_11 ,
struct V_137 * V_138 )
{
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
return ( V_82 -> V_158 & V_167 ) ?
F_93 ( V_11 , V_138 ) :
F_94 ( V_11 , V_138 ) ;
}
static inline int F_98 ( struct V_6 * V_11 ,
struct V_137 * V_138 )
{
return F_93 ( V_11 , V_138 ) ;
}
static void F_99 ( struct V_6 * V_11 ,
struct V_137 * V_138 )
{
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
if ( F_98 ( V_11 , V_138 ) == 0 )
F_89 ( V_82 ) ;
else {
V_82 -> V_158 &= ~ V_162 ;
}
}
static inline void F_100 ( struct V_81 * V_82 , struct V_137 * V_138 )
{
T_4 V_73 ;
V_73 = V_82 -> V_157 - V_82 -> V_156 ;
if ( V_73 > V_138 -> V_3 )
V_73 = V_138 -> V_3 ;
V_138 -> V_3 -= V_73 ;
V_138 -> V_58 += V_73 ;
V_82 -> V_156 += V_73 ;
F_2 ( L_41 , V_73 ) ;
F_89 ( V_82 ) ;
}
static int F_101 ( T_6 * V_177 , struct V_135 * V_136 , unsigned int V_58 , T_4 V_73 )
{
struct V_6 * V_11 = V_177 -> V_178 . V_179 ;
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_137 V_138 = {
. V_136 = V_136 ,
. V_58 = V_58 ,
. V_3 = V_73 ,
} ;
F_2 ( L_42 ) ;
do {
if ( V_82 -> V_158 & V_161 ) {
F_88 ( V_11 , & V_138 ) ;
continue;
}
if ( V_82 -> V_158 & V_163 ) {
F_90 ( V_82 , & V_138 ) ;
continue;
}
if ( V_82 -> V_158 & V_166 ) {
F_91 ( V_82 , & V_138 ) ;
continue;
}
if ( V_82 -> V_158 & V_162 ) {
F_99 ( V_11 , & V_138 ) ;
continue;
}
F_100 ( V_82 , & V_138 ) ;
} while ( V_138 . V_3 );
F_2 ( L_43 ) ;
return V_73 - V_138 . V_3 ;
}
static void F_102 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
T_6 V_177 ;
int V_180 ;
F_2 ( L_44 ) ;
F_53 ( & V_8 -> V_125 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_77;
if ( V_11 -> V_130 )
V_11 -> V_130 = 0 ;
V_177 . V_178 . V_179 = V_11 ;
do {
V_177 . V_3 = 65536 ;
V_180 = F_103 ( V_8 , & V_177 , F_101 ) ;
} while ( V_180 > 0 );
V_77:
F_56 ( & V_8 -> V_125 ) ;
}
static void F_104 ( struct V_6 * V_11 ,
unsigned long V_181 )
{
struct V_81 * V_82 ;
if ( F_105 ( V_11 ) )
return;
F_34 ( V_131 , & V_11 -> V_117 ) ;
V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
F_106 ( V_182 , & V_82 -> V_129 ,
V_181 ) ;
}
static void F_107 ( struct V_6 * V_11 )
{
struct V_81 * V_82 ;
V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
if ( ! F_33 ( V_131 , & V_11 -> V_117 ) ||
! F_108 ( & V_82 -> V_129 ) )
return;
F_27 ( V_131 , & V_11 -> V_117 ) ;
F_109 ( V_11 ) ;
}
static void F_110 ( struct V_6 * V_11 )
{
F_63 () ;
F_27 ( V_131 , & V_11 -> V_117 ) ;
F_27 ( V_133 , & V_11 -> V_117 ) ;
F_27 ( V_116 , & V_11 -> V_117 ) ;
F_27 ( V_132 , & V_11 -> V_117 ) ;
F_64 () ;
}
static void F_111 ( struct V_6 * V_11 )
{
F_110 ( V_11 ) ;
F_65 ( V_11 ) ;
}
static void F_112 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
F_53 ( & V_8 -> V_125 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_77;
F_2 ( L_45 , V_11 ) ;
F_2 ( L_46 ,
V_8 -> V_183 , F_32 ( V_11 ) ,
F_113 ( V_8 , V_184 ) ,
F_113 ( V_8 , V_185 ) ,
V_8 -> V_186 ) ;
F_114 ( V_11 , V_8 -> V_127 ) ;
switch ( V_8 -> V_183 ) {
case V_187 :
F_77 ( & V_11 -> V_94 ) ;
if ( ! F_115 ( V_11 ) ) {
struct V_81 * V_82 = F_29 ( V_11 ,
struct V_81 , V_11 ) ;
V_82 -> V_156 = 0 ;
V_82 -> V_157 = 0 ;
V_82 -> V_164 = 0 ;
V_82 -> V_158 =
V_161 | V_163 ;
V_11 -> V_188 ++ ;
F_55 ( V_11 , - V_90 ) ;
}
F_80 ( & V_11 -> V_94 ) ;
break;
case V_189 :
V_11 -> V_188 ++ ;
V_11 -> V_130 = 0 ;
F_34 ( V_132 , & V_11 -> V_117 ) ;
F_63 () ;
F_27 ( V_190 , & V_11 -> V_117 ) ;
F_27 ( V_116 , & V_11 -> V_117 ) ;
F_64 () ;
F_104 ( V_11 , V_191 ) ;
break;
case V_192 :
V_11 -> V_188 ++ ;
F_27 ( V_190 , & V_11 -> V_117 ) ;
F_86 ( V_11 ) ;
case V_193 :
if ( V_11 -> V_130 < V_194 )
V_11 -> V_130 = V_194 ;
break;
case V_195 :
F_34 ( V_132 , & V_11 -> V_117 ) ;
F_104 ( V_11 , V_191 ) ;
F_63 () ;
F_27 ( V_190 , & V_11 -> V_117 ) ;
F_64 () ;
break;
case V_196 :
F_107 ( V_11 ) ;
F_111 ( V_11 ) ;
}
V_77:
F_56 ( & V_8 -> V_125 ) ;
}
static void F_116 ( struct V_7 * V_8 )
{
struct V_39 * V_7 ;
struct V_6 * V_11 ;
if ( F_26 ( ! ( V_7 = V_8 -> V_127 ) ) )
return;
F_27 ( V_95 , & V_7 -> V_60 ) ;
if ( F_26 ( ! ( V_11 = F_3 ( V_8 ) ) ) )
return;
if ( F_67 ( V_75 , & V_7 -> V_60 ) == 0 )
return;
F_117 ( V_11 ) ;
}
static void F_118 ( struct V_7 * V_8 )
{
F_53 ( & V_8 -> V_125 ) ;
if ( F_119 ( V_8 ) )
F_116 ( V_8 ) ;
F_56 ( & V_8 -> V_125 ) ;
}
static void F_120 ( struct V_7 * V_8 )
{
F_53 ( & V_8 -> V_125 ) ;
if ( F_121 ( V_8 ) )
F_116 ( V_8 ) ;
F_56 ( & V_8 -> V_125 ) ;
}
static void F_122 ( struct V_6 * V_11 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_7 * V_8 = V_82 -> V_85 ;
if ( V_82 -> V_197 ) {
V_8 -> V_198 |= V_199 ;
V_8 -> V_200 = V_82 -> V_197 * V_11 -> V_201 * 2 ;
}
if ( V_82 -> V_202 ) {
V_8 -> V_198 |= V_203 ;
V_8 -> V_204 = V_82 -> V_202 * V_11 -> V_201 * 2 ;
V_8 -> V_97 ( V_8 ) ;
}
}
static void F_123 ( struct V_6 * V_11 , T_4 V_202 , T_4 V_197 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
V_82 -> V_202 = 0 ;
if ( V_202 )
V_82 -> V_202 = V_202 + 1024 ;
V_82 -> V_197 = 0 ;
if ( V_197 )
V_82 -> V_197 = V_197 + 1024 ;
F_122 ( V_11 ) ;
}
static void F_124 ( struct V_6 * V_11 , struct V_79 * V_80 )
{
F_85 ( V_11 , V_80 , - V_205 ) ;
}
static unsigned short F_125 ( void )
{
unsigned short V_206 = V_207 - V_208 ;
unsigned short rand = ( unsigned short ) F_126 () % V_206 ;
return rand + V_208 ;
}
static void F_127 ( struct V_6 * V_11 , unsigned short V_209 )
{
F_2 ( L_47 , V_11 , V_209 ) ;
F_128 ( F_4 ( V_11 ) , V_209 ) ;
F_17 ( V_11 ) ;
}
static unsigned short F_129 ( struct V_81 * V_82 )
{
unsigned short V_209 = V_82 -> V_128 ;
if ( V_209 == 0 && V_82 -> V_11 . V_210 )
V_209 = F_125 () ;
return V_209 ;
}
static unsigned short F_130 ( struct V_81 * V_82 , unsigned short V_209 )
{
if ( V_82 -> V_128 != 0 )
V_82 -> V_128 = 0 ;
if ( ! V_82 -> V_11 . V_210 )
return 0 ;
if ( V_209 <= V_208 || V_209 > V_207 )
return V_207 ;
return -- V_209 ;
}
static int F_131 ( struct V_81 * V_82 , struct V_39 * V_7 )
{
struct V_211 V_212 ;
int V_63 , V_213 = 0 ;
unsigned short V_209 = F_129 ( V_82 ) ;
unsigned short V_214 ;
memcpy ( & V_212 , & V_82 -> V_215 , V_82 -> V_11 . V_40 ) ;
do {
F_128 ( (struct V_10 * ) & V_212 , V_209 ) ;
V_63 = F_132 ( V_7 , (struct V_10 * ) & V_212 ,
V_82 -> V_11 . V_40 ) ;
if ( V_209 == 0 )
break;
if ( V_63 == 0 ) {
V_82 -> V_128 = V_209 ;
break;
}
V_214 = V_209 ;
V_209 = F_130 ( V_82 , V_209 ) ;
if ( V_209 > V_214 )
V_213 ++ ;
} while ( V_63 == - V_216 && V_213 != 2 );
if ( V_212 . V_217 == V_25 )
F_2 ( L_48 , V_104 ,
& ( (struct V_14 * ) & V_212 ) -> V_26 ,
V_209 , V_63 ? L_49 : L_50 , V_63 ) ;
else
F_2 ( L_51 , V_104 ,
& ( (struct V_15 * ) & V_212 ) -> V_29 ,
V_209 , V_63 ? L_49 : L_50 , V_63 ) ;
return V_63 ;
}
static void F_133 ( struct V_79 * V_80 )
{
F_134 () ;
F_135 ( F_136 ( V_80 -> V_218 -> V_219 ) ) ;
F_137 () ;
}
static void F_138 ( struct V_6 * V_11 , unsigned short V_209 )
{
}
static inline void F_139 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_140 ( V_8 , L_52 ,
& V_220 [ 1 ] , L_53 , & V_221 [ 1 ] ) ;
}
static inline void F_141 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_140 ( V_8 , L_54 ,
& V_220 [ 0 ] , L_55 , & V_221 [ 0 ] ) ;
}
static inline void F_142 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_140 ( V_8 , L_56 ,
& V_220 [ 1 ] , L_57 , & V_221 [ 1 ] ) ;
}
static inline void F_143 ( int V_222 , struct V_39 * V_7 )
{
F_144 ( F_145 ( V_7 -> V_8 ) ) ;
if ( F_145 ( V_7 -> V_8 ) )
return;
switch ( V_222 ) {
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
static inline void F_143 ( int V_222 , struct V_39 * V_7 )
{
}
static void F_146 ( struct V_223 * V_224 )
{
}
static struct V_39 * F_147 ( struct V_6 * V_11 ,
struct V_81 * V_82 , int V_222 , int type , int V_33 )
{
struct V_39 * V_7 ;
int V_63 ;
V_63 = F_148 ( V_11 -> V_225 , V_222 , type , V_33 , & V_7 , 1 ) ;
if ( V_63 < 0 ) {
F_2 ( L_58 ,
V_33 , - V_63 ) ;
goto V_77;
}
F_143 ( V_222 , V_7 ) ;
V_63 = F_131 ( V_82 , V_7 ) ;
if ( V_63 ) {
F_61 ( V_7 ) ;
goto V_77;
}
return V_7 ;
V_77:
return F_149 ( V_63 ) ;
}
static int F_150 ( struct V_6 * V_11 ,
struct V_39 * V_7 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 ,
V_11 ) ;
if ( ! V_82 -> V_85 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_58 ( & V_8 -> V_125 ) ;
F_50 ( V_82 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_119 = F_74 ;
V_8 -> V_97 = F_118 ;
V_8 -> V_124 = F_52 ;
V_8 -> V_226 = V_227 ;
F_151 ( V_11 ) ;
V_82 -> V_7 = V_7 ;
V_82 -> V_85 = V_8 ;
F_59 ( & V_8 -> V_125 ) ;
}
V_11 -> V_228 . V_229 ++ ;
V_11 -> V_228 . V_230 = V_231 ;
return F_152 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , 0 ) ;
}
static int F_153 ( struct V_81 * V_82 )
{
struct V_6 * V_11 = & V_82 -> V_11 ;
struct V_39 * V_7 ;
int V_102 = - V_232 ;
V_233 -> V_60 |= V_234 ;
F_27 ( V_131 , & V_11 -> V_117 ) ;
V_102 = F_148 ( V_11 -> V_225 , V_20 ,
V_235 , 0 , & V_7 , 1 ) ;
if ( V_102 < 0 ) {
F_2 ( L_59
L_60 , - V_102 ) ;
goto V_77;
}
F_139 ( V_7 ) ;
F_2 ( L_61 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
V_102 = F_150 ( V_11 , V_7 ) ;
F_154 ( V_11 , V_7 , V_102 ) ;
switch ( V_102 ) {
case 0 :
F_2 ( L_62 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
F_155 ( V_11 ) ;
case - V_106 :
break;
case - V_236 :
F_2 ( L_63 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
case - V_109 :
F_2 ( L_64 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
default:
F_96 ( V_237 L_65 ,
V_104 , - V_102 ,
V_11 -> V_22 [ V_23 ] ) ;
}
V_77:
F_109 ( V_11 ) ;
F_55 ( V_11 , V_102 ) ;
V_233 -> V_60 &= ~ V_234 ;
return V_102 ;
}
static void F_156 ( struct V_6 * V_11 , struct V_79 * V_80 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
int V_89 ;
if ( F_157 ( V_80 ) ) {
F_158 ( V_80 , - V_96 ) ;
return;
}
V_89 = F_153 ( V_82 ) ;
if ( V_89 && ! F_159 ( V_80 ) )
F_160 ( 15000 ) ;
}
static void F_161 ( struct V_6 * V_11 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 ,
V_11 ) ;
if ( V_11 -> V_238 )
F_162 ( V_82 -> V_85 ) ;
}
int F_163 ( struct V_6 * V_11 , int V_239 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 ,
V_11 ) ;
int V_63 = 0 ;
if ( V_239 ) {
V_11 -> V_238 ++ ;
F_161 ( V_11 ) ;
} else if ( V_11 -> V_238 ) {
V_11 -> V_238 -- ;
F_164 ( V_82 -> V_85 ) ;
}
return V_63 ;
}
static void F_161 ( struct V_6 * V_11 )
{
}
static void F_165 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
if ( ! V_82 -> V_85 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_58 ( & V_8 -> V_125 ) ;
F_50 ( V_82 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_119 = F_82 ;
V_8 -> V_97 = F_118 ;
V_8 -> V_226 = V_227 ;
F_155 ( V_11 ) ;
V_82 -> V_7 = V_7 ;
V_82 -> V_85 = V_8 ;
F_161 ( V_11 ) ;
F_59 ( & V_8 -> V_125 ) ;
}
F_122 ( V_11 ) ;
}
static void F_166 ( struct V_223 * V_224 )
{
struct V_81 * V_82 =
F_29 ( V_224 , struct V_81 , V_129 . V_224 ) ;
struct V_6 * V_11 = & V_82 -> V_11 ;
struct V_39 * V_7 = V_82 -> V_7 ;
int V_102 = - V_232 ;
V_233 -> V_60 |= V_234 ;
F_57 ( V_82 ) ;
V_7 = F_147 ( V_11 , V_82 ,
F_4 ( V_11 ) -> V_19 , V_240 , V_241 ) ;
if ( F_167 ( V_7 ) )
goto V_77;
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
F_165 ( V_11 , V_7 ) ;
F_154 ( V_11 , V_7 , 0 ) ;
V_102 = 0 ;
V_77:
F_109 ( V_11 ) ;
F_55 ( V_11 , V_102 ) ;
V_233 -> V_60 &= ~ V_234 ;
}
static void F_168 ( struct V_81 * V_82 )
{
int V_242 ;
struct V_10 V_243 ;
F_2 ( L_68 , V_82 ) ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_243 . V_19 = V_244 ;
V_242 = F_152 ( V_82 -> V_7 , & V_243 , sizeof( V_243 ) , 0 ) ;
F_169 ( & V_82 -> V_11 ,
V_82 -> V_7 , V_242 ) ;
if ( ! V_242 )
F_110 ( & V_82 -> V_11 ) ;
F_2 ( L_69 , V_242 ) ;
}
static void F_170 ( struct V_81 * V_82 )
{
unsigned int V_117 = V_82 -> V_85 -> V_183 ;
if ( V_117 == V_196 && V_82 -> V_7 -> V_117 == V_245 ) {
if ( V_82 -> V_85 -> V_186 == 0 )
return;
F_2 ( L_70 ,
V_104 , V_82 -> V_85 -> V_186 ) ;
}
if ( ( 1 << V_117 ) & ( V_246 | V_247 ) ) {
if ( V_82 -> V_85 -> V_186 == 0 )
return;
F_2 ( L_71
L_72 ,
V_104 , V_82 -> V_85 -> V_186 ) ;
}
F_168 ( V_82 ) ;
}
static int F_171 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
int V_89 = - V_96 ;
if ( ! V_82 -> V_85 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
unsigned int V_248 = V_11 -> V_181 -> V_249 / V_250 ;
unsigned int V_251 = V_11 -> V_181 -> V_252 + 1 ;
unsigned int V_253 = 1 ;
F_172 ( V_7 , V_254 , V_255 ,
( char * ) & V_253 , sizeof( V_253 ) ) ;
F_172 ( V_7 , V_256 , V_257 ,
( char * ) & V_248 , sizeof( V_248 ) ) ;
F_172 ( V_7 , V_256 , V_258 ,
( char * ) & V_248 , sizeof( V_248 ) ) ;
F_172 ( V_7 , V_256 , V_259 ,
( char * ) & V_251 , sizeof( V_251 ) ) ;
F_58 ( & V_8 -> V_125 ) ;
F_50 ( V_82 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_119 = F_102 ;
V_8 -> V_121 = F_112 ;
V_8 -> V_97 = F_120 ;
V_8 -> V_124 = F_52 ;
V_8 -> V_226 = V_227 ;
V_8 -> V_198 |= V_260 ;
F_173 ( V_8 , V_261 ) ;
F_174 ( V_8 ) -> V_262 = 0 ;
F_174 ( V_8 ) -> V_263 |= V_264 ;
F_151 ( V_11 ) ;
V_82 -> V_7 = V_7 ;
V_82 -> V_85 = V_8 ;
F_59 ( & V_8 -> V_125 ) ;
}
if ( ! F_43 ( V_11 ) )
goto V_77;
F_161 ( V_11 ) ;
V_11 -> V_228 . V_229 ++ ;
V_11 -> V_228 . V_230 = V_231 ;
V_89 = F_152 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , V_265 ) ;
switch ( V_89 ) {
case 0 :
case - V_266 :
if ( V_11 -> V_130 < V_194 )
V_11 -> V_130 = V_194 ;
}
V_77:
return V_89 ;
}
static void F_175 ( struct V_223 * V_224 )
{
struct V_81 * V_82 =
F_29 ( V_224 , struct V_81 , V_129 . V_224 ) ;
struct V_39 * V_7 = V_82 -> V_7 ;
struct V_6 * V_11 = & V_82 -> V_11 ;
int V_102 = - V_232 ;
V_233 -> V_60 |= V_234 ;
if ( ! V_7 ) {
F_27 ( V_131 , & V_11 -> V_117 ) ;
V_7 = F_147 ( V_11 , V_82 ,
F_4 ( V_11 ) -> V_19 , V_235 , V_267 ) ;
if ( F_167 ( V_7 ) ) {
V_102 = F_176 ( V_7 ) ;
goto V_77;
}
} else {
int V_268 ;
V_268 = F_67 ( V_131 ,
& V_11 -> V_117 ) ;
F_170 ( V_82 ) ;
if ( V_268 )
goto V_269;
}
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
V_102 = F_171 ( V_11 , V_7 ) ;
F_154 ( V_11 , V_7 , V_102 ) ;
F_2 ( L_73 ,
V_11 , - V_102 , F_32 ( V_11 ) ,
V_7 -> V_8 -> V_183 ) ;
switch ( V_102 ) {
default:
F_96 ( L_74 ,
V_104 , V_102 ) ;
case - V_270 :
F_86 ( V_11 ) ;
break;
case 0 :
case - V_266 :
case - V_271 :
F_109 ( V_11 ) ;
V_233 -> V_60 &= ~ V_234 ;
return;
case - V_272 :
case - V_109 :
case - V_113 :
case - V_108 :
case - V_106 :
goto V_77;
}
V_269:
V_102 = - V_90 ;
V_77:
F_109 ( V_11 ) ;
F_55 ( V_11 , V_102 ) ;
V_233 -> V_60 &= ~ V_234 ;
}
static void F_177 ( struct V_6 * V_11 , struct V_79 * V_80 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
if ( V_82 -> V_7 != NULL && ! F_159 ( V_80 ) ) {
F_2 ( L_75
L_76 ,
V_11 , V_11 -> V_130 / V_250 ) ;
F_106 ( V_182 ,
& V_82 -> V_129 ,
V_11 -> V_130 ) ;
V_11 -> V_130 <<= 1 ;
if ( V_11 -> V_130 < V_194 )
V_11 -> V_130 = V_194 ;
if ( V_11 -> V_130 > V_273 )
V_11 -> V_130 = V_273 ;
} else {
F_2 ( L_77 , V_11 ) ;
F_106 ( V_182 ,
& V_82 -> V_129 , 0 ) ;
}
}
static void F_178 ( struct V_6 * V_11 , struct V_274 * V_275 )
{
long V_276 = 0 ;
if ( F_32 ( V_11 ) )
V_276 = ( long ) ( V_231 - V_11 -> V_277 ) / V_250 ;
F_179 ( V_275 , L_78
L_79 ,
V_11 -> V_228 . V_278 ,
V_11 -> V_228 . V_229 ,
V_11 -> V_228 . V_279 ,
V_276 ,
V_11 -> V_228 . V_280 ,
V_11 -> V_228 . V_281 ,
V_11 -> V_228 . V_282 ,
V_11 -> V_228 . V_283 ,
V_11 -> V_228 . V_284 ,
V_11 -> V_228 . V_285 ,
V_11 -> V_228 . V_286 ,
V_11 -> V_228 . V_287 ) ;
}
static void F_180 ( struct V_6 * V_11 , struct V_274 * V_275 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
F_179 ( V_275 , L_80
L_81 ,
V_82 -> V_128 ,
V_11 -> V_228 . V_278 ,
V_11 -> V_228 . V_280 ,
V_11 -> V_228 . V_281 ,
V_11 -> V_228 . V_282 ,
V_11 -> V_228 . V_283 ,
V_11 -> V_228 . V_284 ,
V_11 -> V_228 . V_285 ,
V_11 -> V_228 . V_286 ,
V_11 -> V_228 . V_287 ) ;
}
static void F_181 ( struct V_6 * V_11 , struct V_274 * V_275 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
long V_276 = 0 ;
if ( F_32 ( V_11 ) )
V_276 = ( long ) ( V_231 - V_11 -> V_277 ) / V_250 ;
F_179 ( V_275 , L_82
L_79 ,
V_82 -> V_128 ,
V_11 -> V_228 . V_278 ,
V_11 -> V_228 . V_229 ,
V_11 -> V_228 . V_279 ,
V_276 ,
V_11 -> V_228 . V_280 ,
V_11 -> V_228 . V_281 ,
V_11 -> V_228 . V_282 ,
V_11 -> V_228 . V_283 ,
V_11 -> V_228 . V_284 ,
V_11 -> V_228 . V_285 ,
V_11 -> V_228 . V_286 ,
V_11 -> V_228 . V_287 ) ;
}
static void * F_182 ( struct V_79 * V_80 , T_4 V_59 )
{
struct V_57 * V_57 ;
struct V_288 * V_4 ;
F_144 ( V_59 > V_289 - sizeof( struct V_288 ) ) ;
if ( V_59 > V_289 - sizeof( struct V_288 ) )
return NULL ;
V_57 = F_183 ( V_24 ) ;
if ( ! V_57 )
return NULL ;
V_4 = F_184 ( V_57 ) ;
V_4 -> V_73 = V_289 ;
return V_4 -> V_179 ;
}
static void F_185 ( void * V_290 )
{
struct V_288 * V_4 ;
if ( ! V_290 )
return;
V_4 = F_29 ( V_290 , struct V_288 , V_179 ) ;
F_186 ( ( unsigned long ) V_4 ) ;
}
static int F_187 ( struct V_87 * V_88 )
{
int V_73 ;
struct V_54 * V_291 = & V_88 -> V_101 ;
struct V_6 * V_11 = V_88 -> V_84 ;
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_39 * V_7 = V_82 -> V_7 ;
unsigned long V_292 ;
unsigned long V_293 ;
F_37 ( V_291 ) ;
V_293 = ( unsigned long ) V_291 -> V_78 [ 0 ] . V_52 & ~ V_69 ;
V_292 = ( unsigned long ) V_291 -> V_76 [ 0 ] . V_52 & ~ V_69 ;
V_73 = F_188 ( V_7 , V_291 ,
F_189 ( V_291 -> V_76 [ 0 ] . V_52 ) , V_292 ,
V_291 -> V_78 [ 0 ] . V_52 , V_293 ) ;
if ( V_73 != V_291 -> V_73 ) {
F_96 ( V_294 L_83 ) ;
V_73 = - V_90 ;
}
return V_73 ;
}
static int F_190 ( struct V_79 * V_80 )
{
struct V_87 * V_88 = V_80 -> V_83 ;
struct V_295 * V_11 ;
T_1 V_73 ;
F_2 ( L_84 , F_12 ( V_88 -> V_176 ) ) ;
V_11 = V_88 -> V_84 -> V_296 ;
if ( ! F_191 ( & V_11 -> V_297 ) ) {
F_192 ( & V_11 -> V_298 , V_80 , NULL ) ;
if ( ! F_191 ( & V_11 -> V_297 ) )
return - V_90 ;
F_193 ( & V_11 -> V_298 , V_80 ) ;
}
if ( F_33 ( V_299 , & V_11 -> V_300 ) )
V_73 = - V_96 ;
else
V_73 = F_187 ( V_88 ) ;
F_194 ( & V_11 -> V_297 ) ;
if ( V_73 > 0 )
V_73 = 0 ;
return V_73 ;
}
static void F_195 ( struct V_6 * V_11 )
{
}
static void F_196 ( struct V_6 * V_11 )
{
F_2 ( L_85 , V_11 ) ;
F_68 ( V_11 ) ;
F_71 ( V_134 ) ;
}
static int F_197 ( const int V_222 , struct V_10 * V_16 )
{
static const struct V_14 sin = {
. V_301 = V_25 ,
. V_26 . V_27 = F_198 ( V_302 ) ,
} ;
static const struct V_15 V_17 = {
. V_303 = V_28 ,
. V_29 = V_304 ,
} ;
switch ( V_222 ) {
case V_20 :
break;
case V_25 :
memcpy ( V_16 , & sin , sizeof( sin ) ) ;
break;
case V_28 :
memcpy ( V_16 , & V_17 , sizeof( V_17 ) ) ;
break;
default:
F_2 ( L_86 , V_104 ) ;
return - V_305 ;
}
return 0 ;
}
static struct V_6 * F_199 ( struct V_306 * args ,
unsigned int V_307 ,
unsigned int V_308 )
{
struct V_6 * V_11 ;
struct V_81 * V_309 ;
if ( args -> V_40 > sizeof( V_11 -> V_12 ) ) {
F_2 ( L_87 ) ;
return F_149 ( - V_310 ) ;
}
V_11 = F_200 ( args -> V_311 , sizeof( * V_309 ) , V_307 ,
V_308 ) ;
if ( V_11 == NULL ) {
F_2 ( L_88
L_89 ) ;
return F_149 ( - V_312 ) ;
}
V_309 = F_29 ( V_11 , struct V_81 , V_11 ) ;
memcpy ( & V_11 -> V_12 , args -> V_313 , args -> V_40 ) ;
V_11 -> V_40 = args -> V_40 ;
if ( args -> V_215 )
memcpy ( & V_309 -> V_215 , args -> V_215 , args -> V_40 ) ;
else {
int V_63 ;
V_63 = F_197 ( args -> V_313 -> V_19 ,
(struct V_10 * ) & V_309 -> V_215 ) ;
if ( V_63 != 0 ) {
F_69 ( V_11 ) ;
return F_149 ( V_63 ) ;
}
}
return V_11 ;
}
static struct V_6 * F_201 ( struct V_306 * args )
{
struct V_13 * V_18 = (struct V_13 * ) args -> V_313 ;
struct V_81 * V_82 ;
struct V_6 * V_11 ;
struct V_6 * V_89 ;
V_11 = F_199 ( args , V_314 ,
V_315 ) ;
if ( F_167 ( V_11 ) )
return V_11 ;
V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
V_11 -> V_316 = 0 ;
V_11 -> V_317 = sizeof( V_99 ) / sizeof( T_1 ) ;
V_11 -> V_318 = V_319 ;
V_11 -> V_320 = V_321 ;
V_11 -> V_130 = V_194 ;
V_11 -> V_322 = V_323 ;
V_11 -> V_70 = & V_324 ;
V_11 -> V_181 = & V_325 ;
F_202 ( & V_82 -> V_129 ,
F_146 ) ;
switch ( V_18 -> V_326 ) {
case V_20 :
if ( V_18 -> V_21 [ 0 ] != '/' ) {
F_2 ( L_90 ,
V_18 -> V_21 ) ;
V_89 = F_149 ( - V_272 ) ;
goto V_327;
}
F_135 ( V_11 ) ;
F_16 ( V_11 , L_91 , V_328 ) ;
V_89 = F_149 ( F_153 ( V_82 ) ) ;
if ( V_89 )
goto V_327;
break;
default:
V_89 = F_149 ( - V_305 ) ;
goto V_327;
}
F_2 ( L_92 ,
V_11 -> V_22 [ V_23 ] ) ;
if ( F_203 ( V_134 ) )
return V_11 ;
V_89 = F_149 ( - V_272 ) ;
V_327:
F_68 ( V_11 ) ;
return V_89 ;
}
static struct V_6 * F_204 ( struct V_306 * args )
{
struct V_10 * V_12 = args -> V_313 ;
struct V_6 * V_11 ;
struct V_81 * V_82 ;
struct V_6 * V_89 ;
V_11 = F_199 ( args , V_329 ,
V_329 ) ;
if ( F_167 ( V_11 ) )
return V_11 ;
V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
V_11 -> V_316 = V_241 ;
V_11 -> V_317 = 0 ;
V_11 -> V_318 = ( 1U << 16 ) - ( V_330 << 3 ) ;
V_11 -> V_320 = V_321 ;
V_11 -> V_130 = V_331 ;
V_11 -> V_322 = V_323 ;
V_11 -> V_70 = & V_332 ;
V_11 -> V_181 = & V_333 ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_334 != F_205 ( 0 ) )
F_135 ( V_11 ) ;
F_202 ( & V_82 -> V_129 ,
F_166 ) ;
F_16 ( V_11 , L_93 , V_335 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_336 != F_205 ( 0 ) )
F_135 ( V_11 ) ;
F_202 ( & V_82 -> V_129 ,
F_166 ) ;
F_16 ( V_11 , L_93 , V_337 ) ;
break;
default:
V_89 = F_149 ( - V_305 ) ;
goto V_327;
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
if ( F_203 ( V_134 ) )
return V_11 ;
V_89 = F_149 ( - V_272 ) ;
V_327:
F_68 ( V_11 ) ;
return V_89 ;
}
static struct V_6 * F_206 ( struct V_306 * args )
{
struct V_10 * V_12 = args -> V_313 ;
struct V_6 * V_11 ;
struct V_81 * V_82 ;
struct V_6 * V_89 ;
unsigned int V_308 = V_315 ;
if ( args -> V_60 & V_338 )
V_308 = V_339 ;
V_11 = F_199 ( args , V_314 ,
V_308 ) ;
if ( F_167 ( V_11 ) )
return V_11 ;
V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
V_11 -> V_316 = V_267 ;
V_11 -> V_317 = sizeof( V_99 ) / sizeof( T_1 ) ;
V_11 -> V_318 = V_319 ;
V_11 -> V_320 = V_321 ;
V_11 -> V_130 = V_194 ;
V_11 -> V_322 = V_323 ;
V_11 -> V_70 = & V_340 ;
V_11 -> V_181 = & V_341 ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_334 != F_205 ( 0 ) )
F_135 ( V_11 ) ;
F_202 ( & V_82 -> V_129 ,
F_175 ) ;
F_16 ( V_11 , L_96 , V_342 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_336 != F_205 ( 0 ) )
F_135 ( V_11 ) ;
F_202 ( & V_82 -> V_129 ,
F_175 ) ;
F_16 ( V_11 , L_96 , V_343 ) ;
break;
default:
V_89 = F_149 ( - V_305 ) ;
goto V_327;
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
if ( F_203 ( V_134 ) )
return V_11 ;
V_89 = F_149 ( - V_272 ) ;
V_327:
F_68 ( V_11 ) ;
return V_89 ;
}
static struct V_6 * F_207 ( struct V_306 * args )
{
struct V_10 * V_12 = args -> V_313 ;
struct V_6 * V_11 ;
struct V_81 * V_82 ;
struct V_344 * V_345 ;
struct V_6 * V_89 ;
V_11 = F_199 ( args , V_314 ,
V_314 ) ;
if ( F_167 ( V_11 ) )
return V_11 ;
V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
V_11 -> V_316 = V_267 ;
V_11 -> V_317 = sizeof( V_99 ) / sizeof( T_1 ) ;
V_11 -> V_318 = V_319 ;
V_11 -> V_181 = & V_341 ;
F_135 ( V_11 ) ;
V_11 -> V_320 = 0 ;
V_11 -> V_130 = 0 ;
V_11 -> V_322 = 0 ;
V_11 -> V_70 = & V_346 ;
switch ( V_12 -> V_19 ) {
case V_25 :
F_16 ( V_11 , L_96 ,
V_342 ) ;
break;
case V_28 :
F_16 ( V_11 , L_96 ,
V_343 ) ;
break;
default:
V_89 = F_149 ( - V_305 ) ;
goto V_327;
}
F_2 ( L_94 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
F_208 ( V_11 ) ;
args -> V_296 -> V_347 = V_11 ;
V_11 -> V_296 = args -> V_296 ;
V_345 = F_29 ( args -> V_296 , struct V_344 , V_348 ) ;
V_82 -> V_7 = V_345 -> V_349 ;
V_82 -> V_85 = V_345 -> V_350 ;
F_155 ( V_11 ) ;
if ( F_203 ( V_134 ) )
return V_11 ;
args -> V_296 -> V_347 = NULL ;
F_209 ( V_11 ) ;
V_89 = F_149 ( - V_272 ) ;
V_327:
F_68 ( V_11 ) ;
return V_89 ;
}
int F_210 ( void )
{
#ifdef F_211
if ( ! V_351 )
V_351 = F_212 ( V_352 ) ;
#endif
F_213 ( & V_353 ) ;
F_213 ( & V_354 ) ;
F_213 ( & V_355 ) ;
F_213 ( & V_356 ) ;
return 0 ;
}
void F_214 ( void )
{
#ifdef F_211
if ( V_351 ) {
F_215 ( V_351 ) ;
V_351 = NULL ;
}
#endif
F_216 ( & V_353 ) ;
F_216 ( & V_354 ) ;
F_216 ( & V_355 ) ;
F_216 ( & V_356 ) ;
}
static int F_217 ( const char * V_357 ,
const struct V_358 * V_359 ,
unsigned int V_360 , unsigned int V_361 )
{
unsigned int V_362 ;
int V_89 ;
if ( ! V_357 )
return - V_272 ;
V_89 = F_218 ( V_357 , 0 , & V_362 ) ;
if ( V_89 == - V_272 || V_362 < V_360 || V_362 > V_361 )
return - V_272 ;
* ( ( unsigned int * ) V_359 -> V_178 ) = V_362 ;
return 0 ;
}
static int F_219 ( const char * V_357 , const struct V_358 * V_359 )
{
return F_217 ( V_357 , V_359 ,
V_363 ,
V_364 ) ;
}
static int F_220 ( const char * V_357 ,
const struct V_358 * V_359 )
{
return F_217 ( V_357 , V_359 ,
V_365 ,
V_366 ) ;
}
static int F_221 ( const char * V_357 ,
const struct V_358 * V_359 )
{
return F_217 ( V_357 , V_359 ,
V_365 ,
V_339 ) ;
}
