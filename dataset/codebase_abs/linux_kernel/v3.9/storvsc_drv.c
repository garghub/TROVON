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
static int F_39 ( struct V_21 * V_22 )
{
struct V_20 * V_23 ;
struct V_64 * V_65 ;
struct V_66 * V_66 ;
int V_67 , V_68 ;
V_23 = F_14 ( V_22 ) ;
if ( ! V_23 )
return - V_69 ;
V_65 = & V_23 -> V_70 ;
V_66 = & V_65 -> V_66 ;
memset ( V_65 , 0 , sizeof( struct V_64 ) ) ;
F_40 ( & V_65 -> F_17 ) ;
V_66 -> V_71 = V_72 ;
V_66 -> V_62 = V_73 ;
V_67 = F_41 ( V_22 -> V_74 , V_66 ,
sizeof( struct V_66 ) ,
( unsigned long ) V_65 ,
V_75 ,
V_76 ) ;
if ( V_67 != 0 )
goto V_47;
V_68 = F_42 ( & V_65 -> F_17 , 5 * V_77 ) ;
if ( V_68 == 0 ) {
V_67 = - V_78 ;
goto V_47;
}
if ( V_66 -> V_71 != V_79 ||
V_66 -> V_80 != 0 )
goto V_47;
memset ( V_66 , 0 , sizeof( struct V_66 ) ) ;
V_66 -> V_71 = V_81 ;
V_66 -> V_62 = V_73 ;
V_66 -> V_19 . V_82 =
F_13 ( V_83 , V_84 ) ;
V_66 -> V_19 . V_85 = 0 ;
V_67 = F_41 ( V_22 -> V_74 , V_66 ,
sizeof( struct V_66 ) ,
( unsigned long ) V_65 ,
V_75 ,
V_76 ) ;
if ( V_67 != 0 )
goto V_47;
V_68 = F_42 ( & V_65 -> F_17 , 5 * V_77 ) ;
if ( V_68 == 0 ) {
V_67 = - V_78 ;
goto V_47;
}
if ( V_66 -> V_71 != V_79 ||
V_66 -> V_80 != 0 )
goto V_47;
memset ( V_66 , 0 , sizeof( struct V_66 ) ) ;
V_66 -> V_71 = V_86 ;
V_66 -> V_62 = V_73 ;
V_66 -> V_87 . V_88 =
V_23 -> V_88 ;
V_67 = F_41 ( V_22 -> V_74 , V_66 ,
sizeof( struct V_66 ) ,
( unsigned long ) V_65 ,
V_75 ,
V_76 ) ;
if ( V_67 != 0 )
goto V_47;
V_68 = F_42 ( & V_65 -> F_17 , 5 * V_77 ) ;
if ( V_68 == 0 ) {
V_67 = - V_78 ;
goto V_47;
}
if ( V_66 -> V_71 != V_79 ||
V_66 -> V_80 != 0 )
goto V_47;
V_23 -> V_89 = V_66 -> V_87 . V_89 ;
V_23 -> V_90
= V_66 -> V_87 . V_90 ;
memset ( V_66 , 0 , sizeof( struct V_66 ) ) ;
V_66 -> V_71 = V_91 ;
V_66 -> V_62 = V_73 ;
V_67 = F_41 ( V_22 -> V_74 , V_66 ,
sizeof( struct V_66 ) ,
( unsigned long ) V_65 ,
V_75 ,
V_76 ) ;
if ( V_67 != 0 )
goto V_47;
V_68 = F_42 ( & V_65 -> F_17 , 5 * V_77 ) ;
if ( V_68 == 0 ) {
V_67 = - V_78 ;
goto V_47;
}
if ( V_66 -> V_71 != V_79 ||
V_66 -> V_80 != 0 )
goto V_47;
V_47:
return V_67 ;
}
static void F_43 ( struct V_92 * V_93 ,
struct V_94 * V_95 ,
struct V_96 * V_8 ,
T_3 V_97 , T_3 V_98 )
{
struct V_3 * V_4 ;
void (* F_44)( struct V_1 * V_2 );
bool V_99 = false ;
switch ( V_93 -> V_100 ) {
case V_101 :
switch ( V_95 -> V_102 [ 0 ] ) {
case V_103 :
case V_104 :
F_45 ( V_95 , V_105 ) ;
break;
default:
F_45 ( V_95 , V_106 ) ;
}
break;
case V_107 :
V_99 = true ;
F_44 = F_9 ;
break;
case ( V_108 | V_109 ) :
if ( ( V_97 == 0x2a ) && ( V_98 == 0x9 ) ) {
V_99 = true ;
F_44 = F_1 ;
F_45 ( V_95 , V_110 ) ;
}
break;
}
if ( ! V_99 )
return;
V_4 = F_46 ( sizeof( struct V_3 ) , V_46 ) ;
if ( ! V_4 ) {
F_45 ( V_95 , V_106 ) ;
return;
}
V_4 -> V_8 = V_8 ;
V_4 -> V_5 = V_93 -> V_5 ;
F_47 ( & V_4 -> V_2 , F_44 ) ;
F_48 ( & V_4 -> V_2 ) ;
}
static void F_49 ( struct V_64 * V_111 )
{
struct V_94 * V_95 = V_111 -> V_112 ;
struct V_113 * V_114 = F_50 ( V_95 -> V_22 -> V_8 ) ;
void (* F_51)( struct V_94 * );
struct V_115 V_116 ;
struct V_92 * V_93 ;
struct V_117 * V_118 = V_95 -> V_22 -> V_119 ;
struct V_96 * V_8 ;
struct V_20 * V_120 ;
struct V_21 * V_25 = V_114 -> V_25 ;
V_120 = F_19 ( V_25 ) ;
V_8 = V_120 -> V_8 ;
V_93 = & V_111 -> V_66 . V_93 ;
if ( V_111 -> V_52 ) {
if ( V_93 -> V_121 == V_122 )
F_34 ( F_52 ( V_95 ) ,
V_111 -> V_42 ,
F_53 ( V_95 ) ,
V_111 -> V_52 ) ;
F_20 ( V_111 -> V_42 ,
V_111 -> V_52 ) ;
}
V_95 -> V_123 = V_93 -> V_124 ;
if ( V_95 -> V_123 ) {
if ( F_54 ( V_95 -> V_125 ,
V_126 , & V_116 ) )
F_55 ( L_1 , & V_116 ) ;
}
if ( V_93 -> V_100 != V_127 )
F_43 ( V_93 , V_95 , V_8 , V_116 . V_97 ,
V_116 . V_98 ) ;
F_56 ( V_95 ,
V_111 -> V_128 . V_39 -
V_93 -> V_129 ) ;
F_51 = V_95 -> V_130 ;
V_95 -> V_131 = NULL ;
V_95 -> V_130 = NULL ;
F_51 ( V_95 ) ;
F_57 ( V_111 , V_118 -> V_132 ) ;
}
static void F_58 ( struct V_21 * V_22 ,
struct V_66 * V_66 ,
struct V_64 * V_65 )
{
struct V_20 * V_23 ;
struct V_66 * V_133 ;
V_23 = F_15 ( V_22 ) ;
V_133 = & V_65 -> V_66 ;
if ( ( V_133 -> V_93 . V_134 [ 0 ] == V_135 ) ||
( V_133 -> V_93 . V_134 [ 0 ] == V_136 ) ) {
V_66 -> V_93 . V_124 = 0 ;
V_66 -> V_93 . V_100 = V_127 ;
}
V_133 -> V_93 . V_124 = V_66 -> V_93 . V_124 ;
V_133 -> V_93 . V_100 = V_66 -> V_93 . V_100 ;
V_133 -> V_93 . V_137 =
V_66 -> V_93 . V_137 ;
if ( V_66 -> V_93 . V_124 != 0 ||
V_66 -> V_93 . V_100 != V_127 ) {
F_59 ( & V_22 -> V_22 ,
L_2 ,
V_133 -> V_93 . V_134 [ 0 ] ,
V_66 -> V_93 . V_124 ,
V_66 -> V_93 . V_100 ) ;
}
if ( ( V_66 -> V_93 . V_124 & 0xFF ) == 0x02 ) {
if ( V_66 -> V_93 . V_100 &
V_109 ) {
F_59 ( & V_22 -> V_22 ,
L_3 ,
V_65 ,
V_66 -> V_93 . V_137 ) ;
memcpy ( V_65 -> V_125 ,
V_66 -> V_93 . V_138 ,
V_66 -> V_93 . V_137 ) ;
}
}
V_133 -> V_93 . V_129 =
V_66 -> V_93 . V_129 ;
F_49 ( V_65 ) ;
if ( F_60 ( & V_23 -> V_28 ) &&
V_23 -> V_26 )
F_61 ( & V_23 -> V_27 ) ;
}
static void F_62 ( struct V_21 * V_22 ,
struct V_66 * V_66 ,
struct V_64 * V_65 )
{
struct V_3 * V_2 ;
struct V_20 * V_23 ;
switch ( V_66 -> V_71 ) {
case V_79 :
F_58 ( V_22 , V_66 , V_65 ) ;
break;
case V_139 :
case V_140 :
V_23 = F_19 ( V_22 ) ;
V_2 = F_46 ( sizeof( struct V_3 ) , V_46 ) ;
if ( ! V_2 )
return;
F_47 ( & V_2 -> V_2 , F_7 ) ;
V_2 -> V_8 = V_23 -> V_8 ;
F_48 ( & V_2 -> V_2 ) ;
break;
default:
break;
}
}
static void F_63 ( void * V_141 )
{
struct V_21 * V_22 = (struct V_21 * ) V_141 ;
struct V_20 * V_23 ;
T_4 V_142 ;
T_5 V_143 ;
unsigned char V_144 [ F_25 ( sizeof( struct V_66 ) , 8 ) ] ;
struct V_64 * V_65 ;
int V_67 ;
V_23 = F_19 ( V_22 ) ;
if ( ! V_23 )
return;
do {
V_67 = F_64 ( V_22 -> V_74 , V_144 ,
F_25 ( sizeof( struct V_66 ) , 8 ) ,
& V_142 , & V_143 ) ;
if ( V_67 == 0 && V_142 > 0 ) {
V_65 = (struct V_64 * )
( unsigned long ) V_143 ;
if ( ( V_65 == & V_23 -> V_70 ) ||
( V_65 == & V_23 -> V_145 ) ) {
memcpy ( & V_65 -> V_66 , V_144 ,
sizeof( struct V_66 ) ) ;
F_65 ( & V_65 -> F_17 ) ;
} else {
F_62 ( V_22 ,
(struct V_66 * ) V_144 ,
V_65 ) ;
}
} else {
break;
}
} while ( 1 );
return;
}
static int F_66 ( struct V_21 * V_22 , T_4 V_146 )
{
struct V_147 V_148 ;
int V_67 ;
memset ( & V_148 , 0 , sizeof( struct V_147 ) ) ;
V_67 = F_67 ( V_22 -> V_74 ,
V_146 ,
V_146 ,
( void * ) & V_148 ,
sizeof( struct V_147 ) ,
F_63 , V_22 ) ;
if ( V_67 != 0 )
return V_67 ;
V_67 = F_39 ( V_22 ) ;
return V_67 ;
}
static int F_68 ( struct V_21 * V_22 )
{
struct V_20 * V_23 ;
unsigned long V_62 ;
V_23 = F_15 ( V_22 ) ;
F_69 ( & V_22 -> V_74 -> V_149 , V_62 ) ;
V_23 -> V_24 = true ;
F_70 ( & V_22 -> V_74 -> V_149 , V_62 ) ;
F_16 ( V_23 ) ;
F_69 ( & V_22 -> V_74 -> V_149 , V_62 ) ;
F_71 ( V_22 , NULL ) ;
F_70 ( & V_22 -> V_74 -> V_149 , V_62 ) ;
F_72 ( V_22 -> V_74 ) ;
F_6 ( V_23 ) ;
return 0 ;
}
static int F_73 ( struct V_21 * V_22 ,
struct V_64 * V_65 )
{
struct V_20 * V_23 ;
struct V_66 * V_66 ;
int V_67 = 0 ;
V_66 = & V_65 -> V_66 ;
V_23 = F_14 ( V_22 ) ;
if ( ! V_23 )
return - V_69 ;
V_65 -> V_22 = V_22 ;
V_66 -> V_62 |= V_73 ;
V_66 -> V_93 . V_37 = sizeof( struct V_92 ) ;
V_66 -> V_93 . V_137 = V_150 ;
V_66 -> V_93 . V_129 =
V_65 -> V_128 . V_39 ;
V_66 -> V_71 = V_151 ;
if ( V_65 -> V_128 . V_39 ) {
V_67 = F_74 ( V_22 -> V_74 ,
& V_65 -> V_128 ,
V_66 ,
sizeof( struct V_66 ) ,
( unsigned long ) V_65 ) ;
} else {
V_67 = F_41 ( V_22 -> V_74 , V_66 ,
sizeof( struct V_66 ) ,
( unsigned long ) V_65 ,
V_75 ,
V_76 ) ;
}
if ( V_67 != 0 )
return V_67 ;
F_75 ( & V_23 -> V_28 ) ;
return V_67 ;
}
static int F_76 ( struct V_6 * V_152 )
{
struct V_117 * V_118 ;
int V_153 = V_154 ;
V_118 = F_77 ( sizeof( struct V_117 ) , V_155 ) ;
if ( ! V_118 )
return - V_156 ;
V_118 -> V_157 =
F_78 ( F_79 ( & V_152 -> V_158 ) ,
sizeof( struct V_64 ) , 0 ,
V_159 , NULL ) ;
if ( ! V_118 -> V_157 )
goto V_160;
V_118 -> V_132 = F_80 ( V_153 , V_161 ,
V_162 ,
V_118 -> V_157 ) ;
if ( ! V_118 -> V_132 )
goto V_163;
V_152 -> V_119 = V_118 ;
return 0 ;
V_163:
F_81 ( V_118 -> V_157 ) ;
V_160:
F_6 ( V_118 ) ;
return - V_156 ;
}
static void F_82 ( struct V_6 * V_152 )
{
struct V_117 * V_118 = V_152 -> V_119 ;
F_83 ( V_118 -> V_132 ) ;
F_81 ( V_118 -> V_157 ) ;
F_6 ( V_118 ) ;
V_152 -> V_119 = NULL ;
}
static int F_84 ( struct V_6 * V_152 )
{
F_85 ( V_152 , V_164 ,
V_165 ) ;
F_86 ( V_152 -> V_166 , V_38 ) ;
F_87 ( V_152 -> V_166 , V_167 ) ;
V_152 -> V_168 = 1 ;
return 0 ;
}
static int F_88 ( struct V_6 * V_7 , struct V_169 * V_170 ,
T_6 V_171 , int * V_172 )
{
T_6 V_173 = V_171 ;
T_6 V_174 = V_173 ;
int V_175 , V_176 ;
V_175 = 0xff ;
V_176 = 0x3f ;
F_89 ( V_174 , V_175 * V_176 ) ;
if ( ( T_6 ) ( V_174 + 1 ) * V_175 * V_176 < V_173 )
V_174 = 0xffff ;
V_172 [ 0 ] = V_175 ;
V_172 [ 1 ] = V_176 ;
V_172 [ 2 ] = ( int ) V_174 ;
return 0 ;
}
static int F_90 ( struct V_94 * V_95 )
{
struct V_113 * V_114 = F_50 ( V_95 -> V_22 -> V_8 ) ;
struct V_21 * V_22 = V_114 -> V_25 ;
struct V_20 * V_23 ;
struct V_64 * V_65 ;
struct V_66 * V_66 ;
int V_67 , V_68 ;
V_23 = F_14 ( V_22 ) ;
if ( ! V_23 )
return V_177 ;
V_65 = & V_23 -> V_145 ;
V_66 = & V_65 -> V_66 ;
F_40 ( & V_65 -> F_17 ) ;
V_66 -> V_71 = V_178 ;
V_66 -> V_62 = V_73 ;
V_66 -> V_93 . V_89 = V_23 -> V_89 ;
V_67 = F_41 ( V_22 -> V_74 , V_66 ,
sizeof( struct V_66 ) ,
( unsigned long ) & V_23 -> V_145 ,
V_75 ,
V_76 ) ;
if ( V_67 != 0 )
return V_177 ;
V_68 = F_42 ( & V_65 -> F_17 , 5 * V_77 ) ;
if ( V_68 == 0 )
return V_179 ;
F_16 ( V_23 ) ;
return V_180 ;
}
static bool F_91 ( struct V_94 * V_95 )
{
bool V_181 = true ;
T_3 V_182 = V_95 -> V_102 [ 0 ] ;
switch ( V_182 ) {
case V_183 :
case V_184 :
V_95 -> V_123 = V_185 << 16 ;
V_181 = false ;
break;
default:
break;
}
return V_181 ;
}
static int F_92 ( struct V_96 * V_8 , struct V_94 * V_95 )
{
int V_67 ;
struct V_113 * V_114 = F_50 ( V_8 ) ;
struct V_21 * V_25 = V_114 -> V_25 ;
struct V_64 * V_111 ;
unsigned int V_186 = 0 ;
int V_33 ;
struct V_30 * V_31 ;
unsigned int V_32 = 0 ;
struct V_92 * V_93 ;
struct V_117 * V_118 = V_95 -> V_22 -> V_119 ;
if ( ! F_91 ( V_95 ) ) {
V_95 -> V_130 ( V_95 ) ;
return 0 ;
}
V_186 = sizeof( struct V_64 ) ;
V_111 = F_93 ( V_118 -> V_132 ,
V_46 ) ;
if ( ! V_111 )
return V_187 ;
memset ( V_111 , 0 , sizeof( struct V_64 ) ) ;
V_111 -> V_112 = V_95 ;
V_95 -> V_131 = ( unsigned char * ) V_111 ;
V_93 = & V_111 -> V_66 . V_93 ;
switch ( V_95 -> V_188 ) {
case V_189 :
V_93 -> V_121 = V_44 ;
break;
case V_190 :
V_93 -> V_121 = V_122 ;
break;
default:
V_93 -> V_121 = V_191 ;
break;
}
V_93 -> V_88 = V_114 -> V_192 ;
V_93 -> V_89 = V_95 -> V_22 -> V_74 ;
V_93 -> V_90 = V_95 -> V_22 -> V_11 ;
V_93 -> V_5 = V_95 -> V_22 -> V_5 ;
V_93 -> V_193 = V_95 -> V_194 ;
memcpy ( V_93 -> V_134 , V_95 -> V_102 , V_93 -> V_193 ) ;
V_111 -> V_125 = V_95 -> V_125 ;
V_111 -> V_128 . V_39 = F_94 ( V_95 ) ;
if ( F_53 ( V_95 ) ) {
V_31 = (struct V_30 * ) F_52 ( V_95 ) ;
V_32 = F_53 ( V_95 ) ;
if ( F_23 ( V_31 , F_53 ( V_95 ) ) != - 1 ) {
V_111 -> V_42 =
F_24 ( V_31 , F_53 ( V_95 ) ,
F_94 ( V_95 ) ,
V_93 -> V_121 ) ;
if ( ! V_111 -> V_42 ) {
V_67 = V_195 ;
goto V_196;
}
V_111 -> V_52 =
F_25 ( F_94 ( V_95 ) , V_38 ) >>
V_45 ;
if ( V_93 -> V_121 == V_44 )
F_38 ( V_31 ,
V_111 -> V_42 ,
F_53 ( V_95 ) ) ;
V_31 = V_111 -> V_42 ;
V_32 = V_111 -> V_52 ;
}
V_111 -> V_128 . V_36 = V_31 [ 0 ] . V_36 ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ )
V_111 -> V_128 . V_197 [ V_33 ] =
F_95 ( F_21 ( ( & V_31 [ V_33 ] ) ) ) ;
} else if ( F_52 ( V_95 ) ) {
V_111 -> V_128 . V_36 =
F_96 ( F_52 ( V_95 ) ) & ( V_38 - 1 ) ;
V_111 -> V_128 . V_197 [ 0 ] =
F_96 ( F_52 ( V_95 ) ) >> V_45 ;
}
V_67 = F_73 ( V_25 , V_111 ) ;
if ( V_67 == - V_198 ) {
if ( V_111 -> V_52 ) {
F_20 ( V_111 -> V_42 ,
V_111 -> V_52 ) ;
V_67 = V_187 ;
goto V_196;
}
}
return 0 ;
V_196:
F_57 ( V_111 , V_118 -> V_132 ) ;
V_95 -> V_131 = NULL ;
return V_67 ;
}
static int F_97 ( struct V_21 * V_22 ,
const struct V_199 * V_200 )
{
int V_67 ;
struct V_96 * V_8 ;
struct V_113 * V_114 ;
bool V_201 = ( ( V_200 -> V_202 == V_203 ) ? true : false ) ;
int V_204 = 0 ;
struct V_20 * V_23 ;
V_8 = F_98 ( & V_205 ,
sizeof( struct V_113 ) ) ;
if ( ! V_8 )
return - V_156 ;
V_114 = F_50 ( V_8 ) ;
memset ( V_114 , 0 , sizeof( struct V_113 ) ) ;
V_114 -> V_192 = V_8 -> V_206 ;
V_114 -> V_25 = V_22 ;
V_23 = F_77 ( sizeof( struct V_20 ) , V_155 ) ;
if ( ! V_23 ) {
V_67 = - V_156 ;
goto V_207;
}
V_23 -> V_24 = false ;
F_99 ( & V_23 -> V_27 ) ;
V_23 -> V_22 = V_22 ;
V_23 -> V_8 = V_8 ;
F_71 ( V_22 , V_23 ) ;
V_23 -> V_88 = V_8 -> V_206 ;
V_67 = F_66 ( V_22 , V_208 ) ;
if ( V_67 )
goto V_209;
V_114 -> V_210 = V_23 -> V_89 ;
V_114 -> V_204 = V_23 -> V_90 ;
V_8 -> V_211 = V_212 ;
V_8 -> V_13 = V_213 ;
V_8 -> V_214 = V_215 - 1 ;
V_8 -> V_216 = V_217 ;
V_67 = F_100 ( V_8 , & V_22 -> V_22 ) ;
if ( V_67 != 0 )
goto V_218;
if ( ! V_201 ) {
F_101 ( V_8 ) ;
} else {
V_204 = ( V_22 -> V_219 . V_220 [ 5 ] << 8 |
V_22 -> V_219 . V_220 [ 4 ] ) ;
V_67 = F_102 ( V_8 , 0 , V_204 , 0 ) ;
if ( V_67 ) {
F_103 ( V_8 ) ;
goto V_218;
}
}
return 0 ;
V_218:
F_68 ( V_22 ) ;
goto V_207;
V_209:
F_6 ( V_23 ) ;
V_207:
F_12 ( V_8 ) ;
return V_67 ;
}
static int F_104 ( struct V_21 * V_25 )
{
struct V_20 * V_23 = F_15 ( V_25 ) ;
struct V_96 * V_8 = V_23 -> V_8 ;
F_103 ( V_8 ) ;
F_68 ( V_25 ) ;
F_12 ( V_8 ) ;
return 0 ;
}
static int T_7 F_105 ( void )
{
T_4 V_221 ;
V_221 =
( ( V_208 - V_38 ) /
F_25 ( V_222 +
sizeof( struct V_66 ) + sizeof( T_5 ) ,
sizeof( T_5 ) ) ) ;
if ( V_221 <
V_165 )
return - V_223 ;
return F_106 ( & V_224 ) ;
}
static void T_8 F_107 ( void )
{
F_108 ( & V_224 ) ;
}
