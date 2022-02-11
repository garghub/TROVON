static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
struct V_6 * V_7 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_5 = V_4 -> V_5 ;
V_7 = F_3 ( V_4 -> V_8 , 0 , 0 , V_5 ) ;
if ( ! V_7 )
goto V_9;
F_4 ( & V_7 -> V_10 ) ;
F_5 ( V_7 ) ;
V_9:
F_6 ( V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_11 , V_12 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
for ( V_11 = 0 ; V_11 < V_4 -> V_8 -> V_13 ; ++ V_11 ) {
if ( V_4 -> V_8 -> V_14 )
V_12 = V_4 -> V_8 -> V_13 - V_11 - 1 ;
else
V_12 = V_11 ;
F_8 ( & V_4 -> V_8 -> V_15 , 0 ,
V_12 , V_16 , 1 ) ;
}
F_6 ( V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( ! F_10 ( V_4 -> V_8 ) )
goto V_9;
V_7 = F_3 ( V_4 -> V_8 , 0 , 0 , V_4 -> V_5 ) ;
if ( V_7 ) {
F_11 ( V_7 ) ;
F_5 ( V_7 ) ;
}
F_12 ( V_4 -> V_8 ) ;
V_9:
F_6 ( V_4 ) ;
}
static inline T_2 F_13 ( T_3 V_17 , T_3 V_18 )
{
T_2 V_19 ;
V_19 = ( ( V_17 << 8 ) | V_18 ) ;
return V_19 ;
}
static inline struct V_20 * F_14 (
struct V_21 * V_22 )
{
struct V_20 * V_23 ;
V_23 = F_15 ( V_22 ) ;
if ( V_23 && V_23 -> V_24 )
V_23 = NULL ;
return V_23 ;
}
static inline void F_16 ( struct V_20 * V_25 )
{
V_25 -> V_26 = true ;
F_17 ( V_25 -> V_27 ,
F_18 ( & V_25 -> V_28 ) == 0 ) ;
V_25 -> V_26 = false ;
}
static inline struct V_20 * F_19 (
struct V_21 * V_22 )
{
struct V_20 * V_23 ;
V_23 = F_15 ( V_22 ) ;
if ( ! V_23 )
goto V_29;
if ( V_23 -> V_24 &&
( F_18 ( & V_23 -> V_28 ) == 0 ) )
V_23 = NULL ;
V_29:
return V_23 ;
}
static void F_20 ( struct V_30 * V_31 ,
unsigned int V_32 )
{
int V_33 ;
struct V_34 * V_35 ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
V_35 = F_21 ( ( & V_31 [ V_33 ] ) ) ;
if ( V_35 != NULL )
F_22 ( V_35 ) ;
}
F_6 ( V_31 ) ;
}
static int F_23 ( struct V_30 * V_31 , unsigned int V_32 )
{
int V_33 ;
if ( V_32 < 2 )
return - 1 ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
if ( V_33 == 0 ) {
if ( V_31 [ V_33 ] . V_36 + V_31 [ V_33 ] . V_37 != V_38 )
return V_33 ;
} else if ( V_33 == V_32 - 1 ) {
if ( V_31 [ V_33 ] . V_36 != 0 )
return V_33 ;
} else {
if ( V_31 [ V_33 ] . V_37 != V_38 || V_31 [ V_33 ] . V_36 != 0 )
return V_33 ;
}
}
return - 1 ;
}
static struct V_30 * F_24 ( struct V_30 * V_31 ,
unsigned int V_32 ,
unsigned int V_39 ,
int V_40 )
{
int V_33 ;
int V_41 ;
struct V_30 * V_42 ;
struct V_34 * V_35 ;
unsigned int V_43 = ( ( V_40 == V_44 ) ? 0 : V_38 ) ;
V_41 = F_25 ( V_39 , V_38 ) >> V_45 ;
V_42 = F_26 ( V_41 , sizeof( struct V_30 ) , V_46 ) ;
if ( ! V_42 )
return NULL ;
F_27 ( V_42 , V_41 ) ;
for ( V_33 = 0 ; V_33 < V_41 ; V_33 ++ ) {
V_35 = F_28 ( V_46 ) ;
if ( ! V_35 )
goto V_47;
F_29 ( & V_42 [ V_33 ] , V_35 , V_43 , 0 ) ;
}
return V_42 ;
V_47:
F_20 ( V_42 , V_41 ) ;
return NULL ;
}
static inline unsigned long F_30 ( struct V_30 * V_31 , int V_48 )
{
void * V_49 = F_31 ( F_21 ( V_31 + V_48 ) ) ;
return ( unsigned long ) V_49 ;
}
static inline void F_32 ( unsigned long V_49 )
{
F_33 ( ( void * ) V_49 ) ;
}
static unsigned int F_34 ( struct V_30 * V_50 ,
struct V_30 * V_42 ,
unsigned int V_51 ,
unsigned int V_52 )
{
int V_33 ;
int V_53 = 0 ;
unsigned long V_54 , V_55 ;
unsigned int V_56 , V_57 , V_58 ;
unsigned int V_59 = 0 ;
unsigned long V_60 = 0 ;
unsigned long V_61 = 0 ;
unsigned long V_62 ;
F_35 ( V_62 ) ;
for ( V_33 = 0 ; V_33 < V_51 ; V_33 ++ ) {
V_61 = F_30 ( V_50 , V_33 ) + V_50 [ V_33 ] . V_36 ;
V_55 = V_61 ;
V_57 = V_50 [ V_33 ] . V_37 ;
if ( V_60 == 0 )
V_60 = F_30 ( V_42 , V_53 ) ;
while ( V_57 ) {
V_54 = V_60 + V_42 [ V_53 ] . V_36 ;
V_56 = V_42 [ V_53 ] . V_37 - V_42 [ V_53 ] . V_36 ;
V_58 = F_36 ( V_56 , V_57 ) ;
memcpy ( ( void * ) V_55 , ( void * ) V_54 , V_58 ) ;
V_59 += V_58 ;
V_42 [ V_53 ] . V_36 += V_58 ;
V_57 -= V_58 ;
V_55 += V_58 ;
if ( V_42 [ V_53 ] . V_36 == V_42 [ V_53 ] . V_37 ) {
F_32 ( V_60 ) ;
V_53 ++ ;
if ( V_53 == V_52 ) {
F_32 ( V_61 - V_50 [ V_33 ] . V_36 ) ;
F_37 ( V_62 ) ;
return V_59 ;
}
if ( V_57 || V_33 != V_51 - 1 )
V_60 = F_30 ( V_42 , V_53 ) ;
} else if ( V_57 == 0 && V_33 == V_51 - 1 ) {
F_32 ( V_60 ) ;
}
}
F_32 ( V_61 - V_50 [ V_33 ] . V_36 ) ;
}
F_37 ( V_62 ) ;
return V_59 ;
}
static unsigned int F_38 ( struct V_30 * V_50 ,
struct V_30 * V_42 ,
unsigned int V_51 )
{
int V_33 ;
int V_53 = 0 ;
unsigned long V_54 , V_55 ;
unsigned int V_56 , V_57 , V_58 ;
unsigned int V_59 = 0 ;
unsigned long V_60 = 0 ;
unsigned long V_63 = 0 ;
unsigned long V_62 ;
F_35 ( V_62 ) ;
for ( V_33 = 0 ; V_33 < V_51 ; V_33 ++ ) {
V_63 = F_30 ( V_50 , V_33 ) + V_50 [ V_33 ] . V_36 ;
V_54 = V_63 ;
V_56 = V_50 [ V_33 ] . V_37 ;
if ( V_60 == 0 )
V_60 = F_30 ( V_42 , V_53 ) ;
while ( V_56 ) {
V_55 = V_60 + V_42 [ V_53 ] . V_37 ;
V_57 = V_38 - V_42 [ V_53 ] . V_37 ;
V_58 = F_36 ( V_56 , V_57 ) ;
memcpy ( ( void * ) V_55 , ( void * ) V_54 , V_58 ) ;
V_59 += V_58 ;
V_42 [ V_53 ] . V_37 += V_58 ;
V_56 -= V_58 ;
V_54 += V_58 ;
if ( V_42 [ V_53 ] . V_37 == V_38 ) {
F_32 ( V_60 ) ;
V_53 ++ ;
if ( V_56 || V_33 != V_51 - 1 )
V_60 = F_30 ( V_42 , V_53 ) ;
} else if ( V_56 == 0 && V_33 == V_51 - 1 ) {
F_32 ( V_60 ) ;
}
}
F_32 ( V_63 - V_50 [ V_33 ] . V_36 ) ;
}
F_37 ( V_62 ) ;
return V_59 ;
}
static void F_39 ( struct V_64 * V_65 )
{
struct V_21 * V_22 = V_65 -> V_66 -> V_67 ;
struct V_20 * V_23 ;
struct V_68 V_69 ;
V_23 = F_14 ( V_22 ) ;
if ( ! V_23 )
return;
if ( V_23 -> V_70 == false )
return;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
F_40 ( V_65 ,
V_71 ,
V_71 ,
( void * ) & V_69 ,
sizeof( struct V_68 ) ,
V_72 , V_65 ) ;
}
static void F_41 ( struct V_21 * V_22 , int V_73 )
{
struct V_20 * V_23 ;
int V_74 = F_42 () ;
int V_75 ;
struct V_76 * V_77 ;
struct V_78 * V_78 ;
int V_79 , V_80 ;
V_75 = ( ( V_73 > V_74 ) ? V_74 : V_73 ) ;
V_23 = F_14 ( V_22 ) ;
if ( ! V_23 )
return;
V_77 = & V_23 -> V_81 ;
V_78 = & V_77 -> V_78 ;
V_23 -> V_70 = true ;
F_43 ( V_22 -> V_82 , F_39 ) ;
if ( F_44 ( V_22 -> V_82 ) )
return;
V_23 -> V_70 = false ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
F_45 ( & V_77 -> F_17 ) ;
V_78 -> V_83 = V_84 ;
V_78 -> V_62 = V_85 ;
V_78 -> V_86 = V_75 ;
V_79 = F_46 ( V_22 -> V_82 , V_78 ,
( sizeof( struct V_78 ) -
V_87 ) ,
( unsigned long ) V_77 ,
V_88 ,
V_89 ) ;
if ( V_79 != 0 )
return;
V_80 = F_47 ( & V_77 -> F_17 , 10 * V_90 ) ;
if ( V_80 == 0 )
return;
if ( V_78 -> V_83 != V_91 ||
V_78 -> V_92 != 0 )
return;
V_23 -> V_70 = true ;
F_44 ( V_22 -> V_82 ) ;
}
static int F_48 ( struct V_21 * V_22 )
{
struct V_20 * V_23 ;
struct V_76 * V_77 ;
struct V_78 * V_78 ;
int V_79 , V_80 ;
int V_73 ;
bool V_93 = false ;
V_23 = F_14 ( V_22 ) ;
if ( ! V_23 )
return - V_94 ;
V_77 = & V_23 -> V_81 ;
V_78 = & V_77 -> V_78 ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
F_45 ( & V_77 -> F_17 ) ;
V_78 -> V_83 = V_95 ;
V_78 -> V_62 = V_85 ;
V_79 = F_46 ( V_22 -> V_82 , V_78 ,
( sizeof( struct V_78 ) -
V_87 ) ,
( unsigned long ) V_77 ,
V_88 ,
V_89 ) ;
if ( V_79 != 0 )
goto V_47;
V_80 = F_47 ( & V_77 -> F_17 , 5 * V_90 ) ;
if ( V_80 == 0 ) {
V_79 = - V_96 ;
goto V_47;
}
if ( V_78 -> V_83 != V_91 ||
V_78 -> V_92 != 0 )
goto V_47;
memset ( V_78 , 0 , sizeof( struct V_78 ) ) ;
V_78 -> V_83 = V_97 ;
V_78 -> V_62 = V_85 ;
V_78 -> V_19 . V_98 =
F_13 ( V_99 , V_100 ) ;
V_78 -> V_19 . V_101 = 0 ;
V_79 = F_46 ( V_22 -> V_82 , V_78 ,
( sizeof( struct V_78 ) -
V_87 ) ,
( unsigned long ) V_77 ,
V_88 ,
V_89 ) ;
if ( V_79 != 0 )
goto V_47;
V_80 = F_47 ( & V_77 -> F_17 , 5 * V_90 ) ;
if ( V_80 == 0 ) {
V_79 = - V_96 ;
goto V_47;
}
if ( V_78 -> V_83 != V_91 ||
V_78 -> V_92 != 0 )
goto V_47;
memset ( V_78 , 0 , sizeof( struct V_78 ) ) ;
V_78 -> V_83 = V_102 ;
V_78 -> V_62 = V_85 ;
V_79 = F_46 ( V_22 -> V_82 , V_78 ,
( sizeof( struct V_78 ) -
V_87 ) ,
( unsigned long ) V_77 ,
V_88 ,
V_89 ) ;
if ( V_79 != 0 )
goto V_47;
V_80 = F_47 ( & V_77 -> F_17 , 5 * V_90 ) ;
if ( V_80 == 0 ) {
V_79 = - V_96 ;
goto V_47;
}
if ( V_78 -> V_83 != V_91 ||
V_78 -> V_92 != 0 )
goto V_47;
V_73 = V_78 -> V_103 . V_104 ;
if ( ( V_105 != V_106 ) &&
( V_105 != V_107 ) ) {
if ( V_78 -> V_103 . V_62 &
V_108 )
V_93 = true ;
}
memset ( V_78 , 0 , sizeof( struct V_78 ) ) ;
V_78 -> V_83 = V_109 ;
V_78 -> V_62 = V_85 ;
V_79 = F_46 ( V_22 -> V_82 , V_78 ,
( sizeof( struct V_78 ) -
V_87 ) ,
( unsigned long ) V_77 ,
V_88 ,
V_89 ) ;
if ( V_79 != 0 )
goto V_47;
V_80 = F_47 ( & V_77 -> F_17 , 5 * V_90 ) ;
if ( V_80 == 0 ) {
V_79 = - V_96 ;
goto V_47;
}
if ( V_78 -> V_83 != V_91 ||
V_78 -> V_92 != 0 )
goto V_47;
if ( V_93 )
F_41 ( V_22 , V_73 ) ;
V_47:
return V_79 ;
}
static void F_49 ( struct V_110 * V_111 ,
struct V_112 * V_113 ,
struct V_114 * V_8 ,
T_3 V_115 , T_3 V_116 )
{
struct V_3 * V_4 ;
void (* F_50)( struct V_1 * V_2 );
bool V_117 = false ;
switch ( V_111 -> V_118 ) {
case V_119 :
switch ( V_113 -> V_120 [ 0 ] ) {
case V_121 :
case V_122 :
F_51 ( V_113 , V_123 ) ;
break;
case V_124 :
break;
default:
F_51 ( V_113 , V_125 ) ;
}
break;
case V_126 :
V_117 = true ;
F_50 = F_9 ;
break;
case ( V_127 | V_128 ) :
if ( ( V_115 == 0x2a ) && ( V_116 == 0x9 ) ) {
V_117 = true ;
F_50 = F_1 ;
F_51 ( V_113 , V_129 ) ;
}
break;
}
if ( ! V_117 )
return;
V_4 = F_52 ( sizeof( struct V_3 ) , V_46 ) ;
if ( ! V_4 ) {
F_51 ( V_113 , V_125 ) ;
return;
}
V_4 -> V_8 = V_8 ;
V_4 -> V_5 = V_111 -> V_5 ;
F_53 ( & V_4 -> V_2 , F_50 ) ;
F_54 ( & V_4 -> V_2 ) ;
}
static void F_55 ( struct V_76 * V_130 )
{
struct V_112 * V_113 = V_130 -> V_131 ;
struct V_132 * V_133 = F_56 ( V_113 -> V_22 -> V_8 ) ;
void (* F_57)( struct V_112 * );
struct V_134 V_135 ;
struct V_110 * V_111 ;
struct V_136 * V_137 = V_113 -> V_22 -> V_138 ;
struct V_114 * V_8 ;
struct V_20 * V_139 ;
struct V_21 * V_25 = V_133 -> V_25 ;
V_139 = F_19 ( V_25 ) ;
V_8 = V_139 -> V_8 ;
V_111 = & V_130 -> V_78 . V_111 ;
if ( V_130 -> V_52 ) {
if ( V_111 -> V_140 == V_141 )
F_34 ( F_58 ( V_113 ) ,
V_130 -> V_42 ,
F_59 ( V_113 ) ,
V_130 -> V_52 ) ;
F_20 ( V_130 -> V_42 ,
V_130 -> V_52 ) ;
}
V_113 -> V_142 = V_111 -> V_143 ;
if ( V_113 -> V_142 ) {
if ( F_60 ( V_113 -> V_144 ,
V_145 , & V_135 ) )
F_61 ( L_1 , & V_135 ) ;
}
if ( V_111 -> V_118 != V_146 )
F_49 ( V_111 , V_113 , V_8 , V_135 . V_115 ,
V_135 . V_116 ) ;
F_62 ( V_113 ,
V_130 -> V_147 . V_39 -
V_111 -> V_148 ) ;
F_57 = V_113 -> V_149 ;
V_113 -> V_150 = NULL ;
V_113 -> V_149 = NULL ;
F_57 ( V_113 ) ;
F_63 ( V_130 , V_137 -> V_151 ) ;
}
static void F_64 ( struct V_21 * V_22 ,
struct V_78 * V_78 ,
struct V_76 * V_77 )
{
struct V_20 * V_23 ;
struct V_78 * V_152 ;
V_23 = F_15 ( V_22 ) ;
V_152 = & V_77 -> V_78 ;
if ( ( V_152 -> V_111 . V_153 [ 0 ] == V_154 ) ||
( V_152 -> V_111 . V_153 [ 0 ] == V_155 ) ) {
V_78 -> V_111 . V_143 = 0 ;
V_78 -> V_111 . V_118 = V_146 ;
}
V_152 -> V_111 . V_143 = V_78 -> V_111 . V_143 ;
V_152 -> V_111 . V_118 = V_78 -> V_111 . V_118 ;
V_152 -> V_111 . V_156 =
V_78 -> V_111 . V_156 ;
if ( V_78 -> V_111 . V_143 != 0 ||
V_78 -> V_111 . V_118 != V_146 ) {
F_65 ( & V_22 -> V_22 ,
L_2 ,
V_152 -> V_111 . V_153 [ 0 ] ,
V_78 -> V_111 . V_143 ,
V_78 -> V_111 . V_118 ) ;
}
if ( ( V_78 -> V_111 . V_143 & 0xFF ) == 0x02 ) {
if ( V_78 -> V_111 . V_118 &
V_128 ) {
F_65 ( & V_22 -> V_22 ,
L_3 ,
V_77 ,
V_78 -> V_111 . V_156 ) ;
memcpy ( V_77 -> V_144 ,
V_78 -> V_111 . V_157 ,
V_78 -> V_111 . V_156 ) ;
}
}
V_152 -> V_111 . V_148 =
V_78 -> V_111 . V_148 ;
F_55 ( V_77 ) ;
if ( F_66 ( & V_23 -> V_28 ) &&
V_23 -> V_26 )
F_67 ( & V_23 -> V_27 ) ;
}
static void F_68 ( struct V_21 * V_22 ,
struct V_78 * V_78 ,
struct V_76 * V_77 )
{
struct V_3 * V_2 ;
struct V_20 * V_23 ;
switch ( V_78 -> V_83 ) {
case V_91 :
F_64 ( V_22 , V_78 , V_77 ) ;
break;
case V_158 :
case V_159 :
V_23 = F_19 ( V_22 ) ;
V_2 = F_52 ( sizeof( struct V_3 ) , V_46 ) ;
if ( ! V_2 )
return;
F_53 ( & V_2 -> V_2 , F_7 ) ;
V_2 -> V_8 = V_23 -> V_8 ;
F_54 ( & V_2 -> V_2 ) ;
break;
default:
break;
}
}
static void V_72 ( void * V_160 )
{
struct V_64 * V_82 = (struct V_64 * ) V_160 ;
struct V_21 * V_22 ;
struct V_20 * V_23 ;
T_4 V_161 ;
T_5 V_162 ;
unsigned char V_163 [ F_25 ( sizeof( struct V_78 ) , 8 ) ] ;
struct V_76 * V_77 ;
int V_79 ;
if ( V_82 -> V_66 != NULL )
V_22 = V_82 -> V_66 -> V_67 ;
else
V_22 = V_82 -> V_67 ;
V_23 = F_19 ( V_22 ) ;
if ( ! V_23 )
return;
do {
V_79 = F_69 ( V_82 , V_163 ,
F_25 ( ( sizeof( struct V_78 ) -
V_87 ) , 8 ) ,
& V_161 , & V_162 ) ;
if ( V_79 == 0 && V_161 > 0 ) {
V_77 = (struct V_76 * )
( unsigned long ) V_162 ;
if ( ( V_77 == & V_23 -> V_81 ) ||
( V_77 == & V_23 -> V_164 ) ) {
memcpy ( & V_77 -> V_78 , V_163 ,
( sizeof( struct V_78 ) -
V_87 ) ) ;
F_70 ( & V_77 -> F_17 ) ;
} else {
F_68 ( V_22 ,
(struct V_78 * ) V_163 ,
V_77 ) ;
}
} else {
break;
}
} while ( 1 );
return;
}
static int F_71 ( struct V_21 * V_22 , T_4 V_165 )
{
struct V_68 V_69 ;
int V_79 ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
V_79 = F_40 ( V_22 -> V_82 ,
V_165 ,
V_165 ,
( void * ) & V_69 ,
sizeof( struct V_68 ) ,
V_72 , V_22 -> V_82 ) ;
if ( V_79 != 0 )
return V_79 ;
V_79 = F_48 ( V_22 ) ;
return V_79 ;
}
static int F_72 ( struct V_21 * V_22 )
{
struct V_20 * V_23 ;
unsigned long V_62 ;
V_23 = F_15 ( V_22 ) ;
F_73 ( & V_22 -> V_82 -> V_166 , V_62 ) ;
V_23 -> V_24 = true ;
F_74 ( & V_22 -> V_82 -> V_166 , V_62 ) ;
F_16 ( V_23 ) ;
F_73 ( & V_22 -> V_82 -> V_166 , V_62 ) ;
F_75 ( V_22 , NULL ) ;
F_74 ( & V_22 -> V_82 -> V_166 , V_62 ) ;
F_76 ( V_22 -> V_82 ) ;
F_6 ( V_23 ) ;
return 0 ;
}
static int F_77 ( struct V_21 * V_22 ,
struct V_76 * V_77 )
{
struct V_20 * V_23 ;
struct V_78 * V_78 ;
struct V_64 * V_167 ;
int V_79 = 0 ;
V_78 = & V_77 -> V_78 ;
V_23 = F_14 ( V_22 ) ;
if ( ! V_23 )
return - V_94 ;
V_77 -> V_22 = V_22 ;
V_167 = F_78 ( V_22 -> V_82 ) ;
V_78 -> V_62 |= V_85 ;
V_78 -> V_111 . V_37 = ( sizeof( struct V_110 ) -
V_87 ) ;
V_78 -> V_111 . V_156 = V_168 ;
V_78 -> V_111 . V_148 =
V_77 -> V_147 . V_39 ;
V_78 -> V_83 = V_169 ;
if ( V_77 -> V_147 . V_39 ) {
V_79 = F_79 ( V_167 ,
& V_77 -> V_147 ,
V_78 ,
( sizeof( struct V_78 ) -
V_87 ) ,
( unsigned long ) V_77 ) ;
} else {
V_79 = F_46 ( V_22 -> V_82 , V_78 ,
( sizeof( struct V_78 ) -
V_87 ) ,
( unsigned long ) V_77 ,
V_88 ,
V_89 ) ;
}
if ( V_79 != 0 )
return V_79 ;
F_80 ( & V_23 -> V_28 ) ;
return V_79 ;
}
static int F_81 ( struct V_6 * V_170 )
{
struct V_136 * V_137 ;
int V_171 = V_172 ;
V_137 = F_82 ( sizeof( struct V_136 ) , V_173 ) ;
if ( ! V_137 )
return - V_174 ;
V_137 -> V_175 =
F_83 ( F_84 ( & V_170 -> V_176 ) ,
sizeof( struct V_76 ) , 0 ,
V_177 , NULL ) ;
if ( ! V_137 -> V_175 )
goto V_178;
V_137 -> V_151 = F_85 ( V_171 , V_179 ,
V_180 ,
V_137 -> V_175 ) ;
if ( ! V_137 -> V_151 )
goto V_181;
V_170 -> V_138 = V_137 ;
return 0 ;
V_181:
F_86 ( V_137 -> V_175 ) ;
V_178:
F_6 ( V_137 ) ;
return - V_174 ;
}
static void F_87 ( struct V_6 * V_170 )
{
struct V_136 * V_137 = V_170 -> V_138 ;
if ( ! V_137 )
return;
F_88 ( V_137 -> V_151 ) ;
F_86 ( V_137 -> V_175 ) ;
F_6 ( V_137 ) ;
V_170 -> V_138 = NULL ;
}
static int F_89 ( struct V_6 * V_170 )
{
F_90 ( V_170 , V_182 ,
V_183 ) ;
F_91 ( V_170 -> V_184 , V_38 ) ;
F_92 ( V_170 -> V_184 , V_185 ) ;
F_93 ( V_170 -> V_184 , ( V_186 * V_90 ) ) ;
V_170 -> V_187 = 1 ;
V_170 -> V_188 |= V_189 ;
return 0 ;
}
static int F_94 ( struct V_6 * V_7 , struct V_190 * V_191 ,
T_6 V_192 , int * V_193 )
{
T_6 V_194 = V_192 ;
T_6 V_195 = V_194 ;
int V_196 , V_197 ;
V_196 = 0xff ;
V_197 = 0x3f ;
F_95 ( V_195 , V_196 * V_197 ) ;
if ( ( T_6 ) ( V_195 + 1 ) * V_196 * V_197 < V_194 )
V_195 = 0xffff ;
V_193 [ 0 ] = V_196 ;
V_193 [ 1 ] = V_197 ;
V_193 [ 2 ] = ( int ) V_195 ;
return 0 ;
}
static int F_96 ( struct V_112 * V_113 )
{
struct V_132 * V_133 = F_56 ( V_113 -> V_22 -> V_8 ) ;
struct V_21 * V_22 = V_133 -> V_25 ;
struct V_20 * V_23 ;
struct V_76 * V_77 ;
struct V_78 * V_78 ;
int V_79 , V_80 ;
V_23 = F_14 ( V_22 ) ;
if ( ! V_23 )
return V_198 ;
V_77 = & V_23 -> V_164 ;
V_78 = & V_77 -> V_78 ;
F_45 ( & V_77 -> F_17 ) ;
V_78 -> V_83 = V_199 ;
V_78 -> V_62 = V_85 ;
V_78 -> V_111 . V_200 = V_23 -> V_200 ;
V_79 = F_46 ( V_22 -> V_82 , V_78 ,
( sizeof( struct V_78 ) -
V_87 ) ,
( unsigned long ) & V_23 -> V_164 ,
V_88 ,
V_89 ) ;
if ( V_79 != 0 )
return V_198 ;
V_80 = F_47 ( & V_77 -> F_17 , 5 * V_90 ) ;
if ( V_80 == 0 )
return V_201 ;
F_16 ( V_23 ) ;
return V_202 ;
}
static enum V_203 F_97 ( struct V_112 * V_113 )
{
return V_204 ;
}
static bool F_98 ( struct V_112 * V_113 )
{
bool V_205 = true ;
T_3 V_206 = V_113 -> V_120 [ 0 ] ;
switch ( V_206 ) {
case V_207 :
case V_208 :
V_113 -> V_142 = V_209 << 16 ;
V_205 = false ;
break;
default:
break;
}
return V_205 ;
}
static int F_99 ( struct V_114 * V_8 , struct V_112 * V_113 )
{
int V_79 ;
struct V_132 * V_133 = F_56 ( V_8 ) ;
struct V_21 * V_25 = V_133 -> V_25 ;
struct V_76 * V_130 ;
unsigned int V_210 = 0 ;
int V_33 ;
struct V_30 * V_31 ;
unsigned int V_32 = 0 ;
struct V_110 * V_111 ;
struct V_136 * V_137 = V_113 -> V_22 -> V_138 ;
if ( V_99 <= V_211 ) {
if ( ! F_98 ( V_113 ) ) {
V_113 -> V_149 ( V_113 ) ;
return 0 ;
}
}
V_210 = sizeof( struct V_76 ) ;
V_130 = F_100 ( V_137 -> V_151 ,
V_46 ) ;
if ( ! V_130 )
return V_212 ;
memset ( V_130 , 0 , sizeof( struct V_76 ) ) ;
V_130 -> V_131 = V_113 ;
V_113 -> V_150 = ( unsigned char * ) V_130 ;
V_111 = & V_130 -> V_78 . V_111 ;
V_111 -> V_213 . V_214 = 60 ;
V_111 -> V_213 . V_215 |=
( V_216 |
V_217 ) ;
switch ( V_113 -> V_218 ) {
case V_219 :
V_111 -> V_140 = V_44 ;
V_111 -> V_213 . V_215 |= V_220 ;
break;
case V_221 :
V_111 -> V_140 = V_141 ;
V_111 -> V_213 . V_215 |= V_222 ;
break;
default:
V_111 -> V_140 = V_223 ;
V_111 -> V_213 . V_215 |= ( V_222 |
V_220 ) ;
break;
}
V_111 -> V_224 = V_133 -> V_225 ;
V_111 -> V_200 = V_113 -> V_22 -> V_82 ;
V_111 -> V_226 = V_113 -> V_22 -> V_11 ;
V_111 -> V_5 = V_113 -> V_22 -> V_5 ;
V_111 -> V_227 = V_113 -> V_228 ;
memcpy ( V_111 -> V_153 , V_113 -> V_120 , V_111 -> V_227 ) ;
V_130 -> V_144 = V_113 -> V_144 ;
V_130 -> V_147 . V_39 = F_101 ( V_113 ) ;
if ( F_59 ( V_113 ) ) {
V_31 = (struct V_30 * ) F_58 ( V_113 ) ;
V_32 = F_59 ( V_113 ) ;
if ( F_23 ( V_31 , F_59 ( V_113 ) ) != - 1 ) {
V_130 -> V_42 =
F_24 ( V_31 , F_59 ( V_113 ) ,
F_101 ( V_113 ) ,
V_111 -> V_140 ) ;
if ( ! V_130 -> V_42 ) {
V_79 = V_229 ;
goto V_230;
}
V_130 -> V_52 =
F_25 ( F_101 ( V_113 ) , V_38 ) >>
V_45 ;
if ( V_111 -> V_140 == V_44 )
F_38 ( V_31 ,
V_130 -> V_42 ,
F_59 ( V_113 ) ) ;
V_31 = V_130 -> V_42 ;
V_32 = V_130 -> V_52 ;
}
V_130 -> V_147 . V_36 = V_31 [ 0 ] . V_36 ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ )
V_130 -> V_147 . V_231 [ V_33 ] =
F_102 ( F_21 ( ( & V_31 [ V_33 ] ) ) ) ;
} else if ( F_58 ( V_113 ) ) {
V_130 -> V_147 . V_36 =
F_103 ( F_58 ( V_113 ) ) & ( V_38 - 1 ) ;
V_130 -> V_147 . V_231 [ 0 ] =
F_103 ( F_58 ( V_113 ) ) >> V_45 ;
}
V_79 = F_77 ( V_25 , V_130 ) ;
if ( V_79 == - V_232 ) {
if ( V_130 -> V_52 ) {
F_20 ( V_130 -> V_42 ,
V_130 -> V_52 ) ;
V_79 = V_212 ;
goto V_230;
}
}
return 0 ;
V_230:
F_63 ( V_130 , V_137 -> V_151 ) ;
V_113 -> V_150 = NULL ;
return V_79 ;
}
static int F_104 ( struct V_21 * V_22 ,
const struct V_233 * V_234 )
{
int V_79 ;
struct V_114 * V_8 ;
struct V_132 * V_133 ;
bool V_235 = ( ( V_234 -> V_236 == V_237 ) ? true : false ) ;
int V_238 = 0 ;
struct V_20 * V_23 ;
switch ( V_105 ) {
case V_107 :
case V_106 :
V_168 = V_239 ;
V_87 = sizeof( struct V_240 ) ;
V_99 = V_241 ;
V_100 = V_242 ;
break;
default:
V_168 = V_243 ;
V_87 = 0 ;
V_99 = V_211 ;
V_100 = V_244 ;
break;
}
if ( V_234 -> V_236 == V_245 )
V_246 . V_247 = ( V_183 *
V_248 ) ;
V_8 = F_105 ( & V_246 ,
sizeof( struct V_132 ) ) ;
if ( ! V_8 )
return - V_174 ;
V_133 = F_56 ( V_8 ) ;
memset ( V_133 , 0 , sizeof( struct V_132 ) ) ;
V_133 -> V_225 = V_8 -> V_249 ;
V_133 -> V_25 = V_22 ;
V_23 = F_82 ( sizeof( struct V_20 ) , V_173 ) ;
if ( ! V_23 ) {
V_79 = - V_174 ;
goto V_250;
}
V_23 -> V_24 = false ;
V_23 -> V_70 = false ;
F_106 ( & V_23 -> V_27 ) ;
V_23 -> V_22 = V_22 ;
V_23 -> V_8 = V_8 ;
F_75 ( V_22 , V_23 ) ;
V_23 -> V_224 = V_8 -> V_249 ;
V_79 = F_71 ( V_22 , V_71 ) ;
if ( V_79 )
goto V_251;
V_133 -> V_252 = V_23 -> V_200 ;
V_133 -> V_238 = V_23 -> V_226 ;
switch ( V_234 -> V_236 ) {
case V_245 :
V_8 -> V_253 = V_254 ;
V_8 -> V_13 = V_248 ;
V_8 -> V_255 = V_256 - 1 ;
break;
case V_257 :
V_8 -> V_253 = V_258 ;
V_8 -> V_13 = V_259 ;
V_8 -> V_255 = V_260 - 1 ;
break;
default:
V_8 -> V_253 = V_261 ;
V_8 -> V_13 = V_262 ;
V_8 -> V_255 = V_263 - 1 ;
break;
}
V_8 -> V_264 = V_265 ;
V_79 = F_107 ( V_8 , & V_22 -> V_22 ) ;
if ( V_79 != 0 )
goto V_266;
if ( ! V_235 ) {
F_108 ( V_8 ) ;
} else {
V_238 = ( V_22 -> V_267 . V_268 [ 5 ] << 8 |
V_22 -> V_267 . V_268 [ 4 ] ) ;
V_79 = F_109 ( V_8 , 0 , V_238 , 0 ) ;
if ( V_79 ) {
F_110 ( V_8 ) ;
goto V_266;
}
}
return 0 ;
V_266:
F_72 ( V_22 ) ;
goto V_250;
V_251:
F_6 ( V_23 ) ;
V_250:
F_12 ( V_8 ) ;
return V_79 ;
}
static int F_111 ( struct V_21 * V_25 )
{
struct V_20 * V_23 = F_15 ( V_25 ) ;
struct V_114 * V_8 = V_23 -> V_8 ;
F_110 ( V_8 ) ;
F_72 ( V_25 ) ;
F_12 ( V_8 ) ;
return 0 ;
}
static int T_7 F_112 ( void )
{
T_4 V_269 ;
V_269 =
( ( V_71 - V_38 ) /
F_25 ( V_270 +
sizeof( struct V_78 ) + sizeof( T_5 ) -
V_87 ,
sizeof( T_5 ) ) ) ;
if ( V_269 <
V_183 )
return - V_271 ;
return F_113 ( & V_272 ) ;
}
static void T_8 F_114 ( void )
{
F_115 ( & V_272 ) ;
}
