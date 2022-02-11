static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 , V_6 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_7 -> V_8 ; ++ V_5 ) {
if ( V_4 -> V_7 -> V_9 )
V_6 = V_4 -> V_7 -> V_8 - V_5 - 1 ;
else
V_6 = V_5 ;
F_3 ( & V_4 -> V_7 -> V_10 , 0 ,
V_6 , V_11 , 1 ) ;
}
F_4 ( V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( ! F_6 ( V_4 -> V_7 ) )
goto V_14;
V_13 = F_7 ( V_4 -> V_7 , 0 , 0 , V_4 -> V_15 ) ;
if ( V_13 ) {
F_8 ( V_13 ) ;
F_9 ( V_13 ) ;
}
F_10 ( V_4 -> V_7 ) ;
V_14:
F_4 ( V_4 ) ;
}
static inline T_1 F_11 ( T_2 V_16 , T_2 V_17 )
{
T_1 V_18 ;
V_18 = ( ( V_16 << 8 ) | V_17 ) ;
return V_18 ;
}
static inline struct V_19 * F_12 (
struct V_20 * V_21 )
{
struct V_19 * V_22 ;
V_22 = F_13 ( V_21 ) ;
if ( V_22 && V_22 -> V_23 )
V_22 = NULL ;
return V_22 ;
}
static inline void F_14 ( struct V_19 * V_24 )
{
V_24 -> V_25 = true ;
F_15 ( V_24 -> V_26 ,
F_16 ( & V_24 -> V_27 ) == 0 ) ;
V_24 -> V_25 = false ;
}
static inline struct V_19 * F_17 (
struct V_20 * V_21 )
{
struct V_19 * V_22 ;
V_22 = F_13 ( V_21 ) ;
if ( ! V_22 )
goto V_28;
if ( V_22 -> V_23 &&
( F_16 ( & V_22 -> V_27 ) == 0 ) )
V_22 = NULL ;
V_28:
return V_22 ;
}
static void F_18 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
int V_32 ;
struct V_33 * V_34 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
V_34 = F_19 ( ( & V_30 [ V_32 ] ) ) ;
if ( V_34 != NULL )
F_20 ( V_34 ) ;
}
F_4 ( V_30 ) ;
}
static int F_21 ( struct V_29 * V_30 , unsigned int V_31 )
{
int V_32 ;
if ( V_31 < 2 )
return - 1 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
if ( V_32 == 0 ) {
if ( V_30 [ V_32 ] . V_35 + V_30 [ V_32 ] . V_36 != V_37 )
return V_32 ;
} else if ( V_32 == V_31 - 1 ) {
if ( V_30 [ V_32 ] . V_35 != 0 )
return V_32 ;
} else {
if ( V_30 [ V_32 ] . V_36 != V_37 || V_30 [ V_32 ] . V_35 != 0 )
return V_32 ;
}
}
return - 1 ;
}
static struct V_29 * F_22 ( struct V_29 * V_30 ,
unsigned int V_31 ,
unsigned int V_38 ,
int V_39 )
{
int V_32 ;
int V_40 ;
struct V_29 * V_41 ;
struct V_33 * V_34 ;
unsigned int V_42 = ( ( V_39 == V_43 ) ? 0 : V_37 ) ;
V_40 = F_23 ( V_38 , V_37 ) >> V_44 ;
V_41 = F_24 ( V_40 , sizeof( struct V_29 ) , V_45 ) ;
if ( ! V_41 )
return NULL ;
for ( V_32 = 0 ; V_32 < V_40 ; V_32 ++ ) {
V_34 = F_25 ( V_45 ) ;
if ( ! V_34 )
goto V_46;
F_26 ( & V_41 [ V_32 ] , V_34 , V_42 , 0 ) ;
}
return V_41 ;
V_46:
F_18 ( V_41 , V_40 ) ;
return NULL ;
}
static inline unsigned long F_27 ( struct V_29 * V_30 , int V_47 )
{
void * V_48 = F_28 ( F_19 ( V_30 + V_47 ) ) ;
return ( unsigned long ) V_48 ;
}
static inline void F_29 ( unsigned long V_48 )
{
F_30 ( ( void * ) V_48 ) ;
}
static unsigned int F_31 ( struct V_29 * V_49 ,
struct V_29 * V_41 ,
unsigned int V_50 ,
unsigned int V_51 )
{
int V_32 ;
int V_52 = 0 ;
unsigned long V_53 , V_54 ;
unsigned int V_55 , V_56 , V_57 ;
unsigned int V_58 = 0 ;
unsigned long V_59 = 0 ;
unsigned long V_60 = 0 ;
unsigned long V_61 ;
F_32 ( V_61 ) ;
for ( V_32 = 0 ; V_32 < V_50 ; V_32 ++ ) {
V_60 = F_27 ( V_49 , V_32 ) + V_49 [ V_32 ] . V_35 ;
V_54 = V_60 ;
V_56 = V_49 [ V_32 ] . V_36 ;
if ( V_59 == 0 )
V_59 = F_27 ( V_41 , V_52 ) ;
while ( V_56 ) {
V_53 = V_59 + V_41 [ V_52 ] . V_35 ;
V_55 = V_41 [ V_52 ] . V_36 - V_41 [ V_52 ] . V_35 ;
V_57 = F_33 ( V_55 , V_56 ) ;
memcpy ( ( void * ) V_54 , ( void * ) V_53 , V_57 ) ;
V_58 += V_57 ;
V_41 [ V_52 ] . V_35 += V_57 ;
V_56 -= V_57 ;
V_54 += V_57 ;
if ( V_41 [ V_52 ] . V_35 == V_41 [ V_52 ] . V_36 ) {
F_29 ( V_59 ) ;
V_52 ++ ;
if ( V_52 == V_51 ) {
F_29 ( V_60 - V_49 [ V_32 ] . V_35 ) ;
F_34 ( V_61 ) ;
return V_58 ;
}
if ( V_56 || V_32 != V_50 - 1 )
V_59 = F_27 ( V_41 , V_52 ) ;
} else if ( V_56 == 0 && V_32 == V_50 - 1 ) {
F_29 ( V_59 ) ;
}
}
F_29 ( V_60 - V_49 [ V_32 ] . V_35 ) ;
}
F_34 ( V_61 ) ;
return V_58 ;
}
static unsigned int F_35 ( struct V_29 * V_49 ,
struct V_29 * V_41 ,
unsigned int V_50 )
{
int V_32 ;
int V_52 = 0 ;
unsigned long V_53 , V_54 ;
unsigned int V_55 , V_56 , V_57 ;
unsigned int V_58 = 0 ;
unsigned long V_59 = 0 ;
unsigned long V_62 = 0 ;
unsigned long V_61 ;
F_32 ( V_61 ) ;
for ( V_32 = 0 ; V_32 < V_50 ; V_32 ++ ) {
V_62 = F_27 ( V_49 , V_32 ) + V_49 [ V_32 ] . V_35 ;
V_53 = V_62 ;
V_55 = V_49 [ V_32 ] . V_36 ;
if ( V_59 == 0 )
V_59 = F_27 ( V_41 , V_52 ) ;
while ( V_55 ) {
V_54 = V_59 + V_41 [ V_52 ] . V_36 ;
V_56 = V_37 - V_41 [ V_52 ] . V_36 ;
V_57 = F_33 ( V_55 , V_56 ) ;
memcpy ( ( void * ) V_54 , ( void * ) V_53 , V_57 ) ;
V_58 += V_57 ;
V_41 [ V_52 ] . V_36 += V_57 ;
V_55 -= V_57 ;
V_53 += V_57 ;
if ( V_41 [ V_52 ] . V_36 == V_37 ) {
F_29 ( V_59 ) ;
V_52 ++ ;
if ( V_55 || V_32 != V_50 - 1 )
V_59 = F_27 ( V_41 , V_52 ) ;
} else if ( V_55 == 0 && V_32 == V_50 - 1 ) {
F_29 ( V_59 ) ;
}
}
F_29 ( V_62 - V_49 [ V_32 ] . V_35 ) ;
}
F_34 ( V_61 ) ;
return V_58 ;
}
static int F_36 ( struct V_20 * V_21 )
{
struct V_19 * V_22 ;
struct V_63 * V_64 ;
struct V_65 * V_65 ;
int V_66 , V_67 ;
V_22 = F_12 ( V_21 ) ;
if ( ! V_22 )
return - V_68 ;
V_64 = & V_22 -> V_69 ;
V_65 = & V_64 -> V_65 ;
memset ( V_64 , 0 , sizeof( struct V_63 ) ) ;
F_37 ( & V_64 -> F_15 ) ;
V_65 -> V_70 = V_71 ;
V_65 -> V_61 = V_72 ;
V_66 = F_38 ( V_21 -> V_73 , V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) V_64 ,
V_74 ,
V_75 ) ;
if ( V_66 != 0 )
goto V_46;
V_67 = F_39 ( & V_64 -> F_15 , 5 * V_76 ) ;
if ( V_67 == 0 ) {
V_66 = - V_77 ;
goto V_46;
}
if ( V_65 -> V_70 != V_78 ||
V_65 -> V_79 != 0 )
goto V_46;
memset ( V_65 , 0 , sizeof( struct V_65 ) ) ;
V_65 -> V_70 = V_80 ;
V_65 -> V_61 = V_72 ;
V_65 -> V_18 . V_81 =
F_11 ( V_82 , V_83 ) ;
V_65 -> V_18 . V_84 = 0 ;
V_66 = F_38 ( V_21 -> V_73 , V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) V_64 ,
V_74 ,
V_75 ) ;
if ( V_66 != 0 )
goto V_46;
V_67 = F_39 ( & V_64 -> F_15 , 5 * V_76 ) ;
if ( V_67 == 0 ) {
V_66 = - V_77 ;
goto V_46;
}
if ( V_65 -> V_70 != V_78 ||
V_65 -> V_79 != 0 )
goto V_46;
memset ( V_65 , 0 , sizeof( struct V_65 ) ) ;
V_65 -> V_70 = V_85 ;
V_65 -> V_61 = V_72 ;
V_65 -> V_86 . V_87 =
V_22 -> V_87 ;
V_66 = F_38 ( V_21 -> V_73 , V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) V_64 ,
V_74 ,
V_75 ) ;
if ( V_66 != 0 )
goto V_46;
V_67 = F_39 ( & V_64 -> F_15 , 5 * V_76 ) ;
if ( V_67 == 0 ) {
V_66 = - V_77 ;
goto V_46;
}
if ( V_65 -> V_70 != V_78 ||
V_65 -> V_79 != 0 )
goto V_46;
V_22 -> V_88 = V_65 -> V_86 . V_88 ;
V_22 -> V_89
= V_65 -> V_86 . V_89 ;
memset ( V_65 , 0 , sizeof( struct V_65 ) ) ;
V_65 -> V_70 = V_90 ;
V_65 -> V_61 = V_72 ;
V_66 = F_38 ( V_21 -> V_73 , V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) V_64 ,
V_74 ,
V_75 ) ;
if ( V_66 != 0 )
goto V_46;
V_67 = F_39 ( & V_64 -> F_15 , 5 * V_76 ) ;
if ( V_67 == 0 ) {
V_66 = - V_77 ;
goto V_46;
}
if ( V_65 -> V_70 != V_78 ||
V_65 -> V_79 != 0 )
goto V_46;
V_46:
return V_66 ;
}
static void F_40 ( struct V_63 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
struct V_95 * V_96 = F_41 ( V_93 -> V_21 -> V_7 ) ;
void (* F_42)( struct V_92 * );
struct V_97 V_98 ;
struct V_99 * V_100 ;
struct V_3 * V_4 ;
struct V_101 * V_102 = V_93 -> V_21 -> V_103 ;
V_100 = & V_91 -> V_65 . V_100 ;
if ( V_91 -> V_51 ) {
if ( V_100 -> V_104 == V_105 )
F_31 ( F_43 ( V_93 ) ,
V_91 -> V_41 ,
F_44 ( V_93 ) ,
V_91 -> V_51 ) ;
F_18 ( V_91 -> V_41 ,
V_91 -> V_51 ) ;
}
V_93 -> V_106 = V_100 -> V_107 ;
if ( V_100 -> V_108 == V_109 ) {
switch ( V_93 -> V_110 [ 0 ] ) {
case V_111 :
case V_112 :
F_45 ( V_93 , V_113 ) ;
break;
default:
F_45 ( V_93 , V_114 ) ;
}
}
if ( V_100 -> V_108 == V_115 ) {
struct V_19 * V_116 ;
struct V_20 * V_24 = V_96 -> V_24 ;
struct V_117 * V_7 ;
V_116 = F_17 ( V_24 ) ;
V_7 = V_116 -> V_7 ;
V_4 = F_46 ( sizeof( struct V_3 ) ,
V_45 ) ;
if ( ! V_4 ) {
V_93 -> V_106 = V_114 << 16 ;
} else {
V_4 -> V_7 = V_7 ;
V_4 -> V_15 = V_100 -> V_15 ;
F_47 ( & V_4 -> V_2 , F_5 ) ;
F_48 ( & V_4 -> V_2 ) ;
}
}
if ( V_93 -> V_106 ) {
if ( F_49 ( V_93 -> V_118 ,
V_119 , & V_98 ) )
F_50 ( L_1 , & V_98 ) ;
}
F_51 ( V_93 ,
V_91 -> V_120 . V_38 -
V_100 -> V_121 ) ;
F_42 = V_93 -> V_122 ;
V_93 -> V_123 = NULL ;
V_93 -> V_122 = NULL ;
F_42 ( V_93 ) ;
F_52 ( V_91 , V_102 -> V_124 ) ;
}
static void F_53 ( struct V_20 * V_21 ,
struct V_65 * V_65 ,
struct V_63 * V_64 )
{
struct V_19 * V_22 ;
struct V_65 * V_125 ;
V_22 = F_13 ( V_21 ) ;
V_125 = & V_64 -> V_65 ;
if ( ( V_125 -> V_100 . V_126 [ 0 ] == V_127 ) ||
( V_125 -> V_100 . V_126 [ 0 ] == V_128 ) ) {
V_65 -> V_100 . V_107 = 0 ;
V_65 -> V_100 . V_108 = V_129 ;
}
V_125 -> V_100 . V_107 = V_65 -> V_100 . V_107 ;
V_125 -> V_100 . V_108 = V_65 -> V_100 . V_108 ;
V_125 -> V_100 . V_130 =
V_65 -> V_100 . V_130 ;
if ( V_65 -> V_100 . V_107 != 0 ||
V_65 -> V_100 . V_108 != V_129 ) {
F_54 ( & V_21 -> V_21 ,
L_2 ,
V_125 -> V_100 . V_126 [ 0 ] ,
V_65 -> V_100 . V_107 ,
V_65 -> V_100 . V_108 ) ;
}
if ( ( V_65 -> V_100 . V_107 & 0xFF ) == 0x02 ) {
if ( V_65 -> V_100 . V_108 &
V_131 ) {
F_54 ( & V_21 -> V_21 ,
L_3 ,
V_64 ,
V_65 -> V_100 . V_130 ) ;
memcpy ( V_64 -> V_118 ,
V_65 -> V_100 . V_132 ,
V_65 -> V_100 . V_130 ) ;
}
}
V_125 -> V_100 . V_121 =
V_65 -> V_100 . V_121 ;
F_40 ( V_64 ) ;
if ( F_55 ( & V_22 -> V_27 ) &&
V_22 -> V_25 )
F_56 ( & V_22 -> V_26 ) ;
}
static void F_57 ( struct V_20 * V_21 ,
struct V_65 * V_65 ,
struct V_63 * V_64 )
{
struct V_3 * V_2 ;
struct V_19 * V_22 ;
switch ( V_65 -> V_70 ) {
case V_78 :
F_53 ( V_21 , V_65 , V_64 ) ;
break;
case V_133 :
case V_134 :
V_22 = F_17 ( V_21 ) ;
V_2 = F_46 ( sizeof( struct V_3 ) , V_45 ) ;
if ( ! V_2 )
return;
F_47 ( & V_2 -> V_2 , F_1 ) ;
V_2 -> V_7 = V_22 -> V_7 ;
F_48 ( & V_2 -> V_2 ) ;
break;
default:
break;
}
}
static void F_58 ( void * V_135 )
{
struct V_20 * V_21 = (struct V_20 * ) V_135 ;
struct V_19 * V_22 ;
T_3 V_136 ;
T_4 V_137 ;
unsigned char V_138 [ F_23 ( sizeof( struct V_65 ) , 8 ) ] ;
struct V_63 * V_64 ;
int V_66 ;
V_22 = F_17 ( V_21 ) ;
if ( ! V_22 )
return;
do {
V_66 = F_59 ( V_21 -> V_73 , V_138 ,
F_23 ( sizeof( struct V_65 ) , 8 ) ,
& V_136 , & V_137 ) ;
if ( V_66 == 0 && V_136 > 0 ) {
V_64 = (struct V_63 * )
( unsigned long ) V_137 ;
if ( ( V_64 == & V_22 -> V_69 ) ||
( V_64 == & V_22 -> V_139 ) ) {
memcpy ( & V_64 -> V_65 , V_138 ,
sizeof( struct V_65 ) ) ;
F_60 ( & V_64 -> F_15 ) ;
} else {
F_57 ( V_21 ,
(struct V_65 * ) V_138 ,
V_64 ) ;
}
} else {
break;
}
} while ( 1 );
return;
}
static int F_61 ( struct V_20 * V_21 , T_3 V_140 )
{
struct V_141 V_142 ;
int V_66 ;
memset ( & V_142 , 0 , sizeof( struct V_141 ) ) ;
V_66 = F_62 ( V_21 -> V_73 ,
V_140 ,
V_140 ,
( void * ) & V_142 ,
sizeof( struct V_141 ) ,
F_58 , V_21 ) ;
if ( V_66 != 0 )
return V_66 ;
V_66 = F_36 ( V_21 ) ;
return V_66 ;
}
static int F_63 ( struct V_20 * V_21 )
{
struct V_19 * V_22 ;
unsigned long V_61 ;
V_22 = F_13 ( V_21 ) ;
F_64 ( & V_21 -> V_73 -> V_143 , V_61 ) ;
V_22 -> V_23 = true ;
F_65 ( & V_21 -> V_73 -> V_143 , V_61 ) ;
F_14 ( V_22 ) ;
F_64 ( & V_21 -> V_73 -> V_143 , V_61 ) ;
F_66 ( V_21 , NULL ) ;
F_65 ( & V_21 -> V_73 -> V_143 , V_61 ) ;
F_67 ( V_21 -> V_73 ) ;
F_4 ( V_22 ) ;
return 0 ;
}
static int F_68 ( struct V_20 * V_21 ,
struct V_63 * V_64 )
{
struct V_19 * V_22 ;
struct V_65 * V_65 ;
int V_66 = 0 ;
V_65 = & V_64 -> V_65 ;
V_22 = F_12 ( V_21 ) ;
if ( ! V_22 )
return - V_68 ;
V_64 -> V_21 = V_21 ;
V_65 -> V_61 |= V_72 ;
V_65 -> V_100 . V_36 = sizeof( struct V_99 ) ;
V_65 -> V_100 . V_130 = V_144 ;
V_65 -> V_100 . V_121 =
V_64 -> V_120 . V_38 ;
V_65 -> V_70 = V_145 ;
if ( V_64 -> V_120 . V_38 ) {
V_66 = F_69 ( V_21 -> V_73 ,
& V_64 -> V_120 ,
V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) V_64 ) ;
} else {
V_66 = F_38 ( V_21 -> V_73 , V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) V_64 ,
V_74 ,
V_75 ) ;
}
if ( V_66 != 0 )
return V_66 ;
F_70 ( & V_22 -> V_27 ) ;
return V_66 ;
}
static int F_71 ( struct V_12 * V_146 )
{
struct V_101 * V_102 ;
int V_147 = V_148 ;
V_102 = F_72 ( sizeof( struct V_101 ) , V_149 ) ;
if ( ! V_102 )
return - V_150 ;
V_102 -> V_151 =
F_73 ( F_74 ( & V_146 -> V_152 ) ,
sizeof( struct V_63 ) , 0 ,
V_153 , NULL ) ;
if ( ! V_102 -> V_151 )
goto V_154;
V_102 -> V_124 = F_75 ( V_147 , V_155 ,
V_156 ,
V_102 -> V_151 ) ;
if ( ! V_102 -> V_124 )
goto V_157;
V_146 -> V_103 = V_102 ;
return 0 ;
V_157:
F_76 ( V_102 -> V_151 ) ;
V_154:
F_4 ( V_102 ) ;
return - V_150 ;
}
static void F_77 ( struct V_12 * V_146 )
{
struct V_101 * V_102 = V_146 -> V_103 ;
F_78 ( V_102 -> V_124 ) ;
F_76 ( V_102 -> V_151 ) ;
F_4 ( V_102 ) ;
V_146 -> V_103 = NULL ;
}
static int F_79 ( struct V_12 * V_146 )
{
F_80 ( V_146 , V_158 ,
V_159 ) ;
F_81 ( V_146 -> V_160 , V_37 ) ;
F_82 ( V_146 -> V_160 , V_161 ) ;
return 0 ;
}
static int F_83 ( struct V_12 * V_13 , struct V_162 * V_163 ,
T_5 V_164 , int * V_165 )
{
T_5 V_166 = V_164 ;
T_5 V_167 = V_166 ;
int V_168 , V_169 ;
V_168 = 0xff ;
V_169 = 0x3f ;
F_84 ( V_167 , V_168 * V_169 ) ;
if ( ( T_5 ) ( V_167 + 1 ) * V_168 * V_169 < V_166 )
V_167 = 0xffff ;
V_165 [ 0 ] = V_168 ;
V_165 [ 1 ] = V_169 ;
V_165 [ 2 ] = ( int ) V_167 ;
return 0 ;
}
static int F_85 ( struct V_92 * V_93 )
{
struct V_95 * V_96 = F_41 ( V_93 -> V_21 -> V_7 ) ;
struct V_20 * V_21 = V_96 -> V_24 ;
struct V_19 * V_22 ;
struct V_63 * V_64 ;
struct V_65 * V_65 ;
int V_66 , V_67 ;
V_22 = F_12 ( V_21 ) ;
if ( ! V_22 )
return V_170 ;
V_64 = & V_22 -> V_139 ;
V_65 = & V_64 -> V_65 ;
F_37 ( & V_64 -> F_15 ) ;
V_65 -> V_70 = V_171 ;
V_65 -> V_61 = V_72 ;
V_65 -> V_100 . V_88 = V_22 -> V_88 ;
V_66 = F_38 ( V_21 -> V_73 , V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) & V_22 -> V_139 ,
V_74 ,
V_75 ) ;
if ( V_66 != 0 )
return V_170 ;
V_67 = F_39 ( & V_64 -> F_15 , 5 * V_76 ) ;
if ( V_67 == 0 )
return V_172 ;
F_14 ( V_22 ) ;
return V_173 ;
}
static bool F_86 ( struct V_92 * V_93 )
{
bool V_174 = true ;
T_2 V_175 = V_93 -> V_110 [ 0 ] ;
switch ( V_175 ) {
case V_176 :
V_93 -> V_106 = V_177 << 16 ;
V_174 = false ;
break;
default:
break;
}
return V_174 ;
}
static int F_87 ( struct V_117 * V_7 , struct V_92 * V_93 )
{
int V_66 ;
struct V_95 * V_96 = F_41 ( V_7 ) ;
struct V_20 * V_24 = V_96 -> V_24 ;
struct V_63 * V_91 ;
unsigned int V_178 = 0 ;
int V_32 ;
struct V_29 * V_30 ;
unsigned int V_31 = 0 ;
struct V_99 * V_100 ;
struct V_101 * V_102 = V_93 -> V_21 -> V_103 ;
if ( ! F_86 ( V_93 ) ) {
V_93 -> V_122 ( V_93 ) ;
return 0 ;
}
V_178 = sizeof( struct V_63 ) ;
V_91 = F_88 ( V_102 -> V_124 ,
V_45 ) ;
if ( ! V_91 )
return V_179 ;
memset ( V_91 , 0 , sizeof( struct V_63 ) ) ;
V_91 -> V_94 = V_93 ;
V_93 -> V_123 = ( unsigned char * ) V_91 ;
V_100 = & V_91 -> V_65 . V_100 ;
switch ( V_93 -> V_180 ) {
case V_181 :
V_100 -> V_104 = V_43 ;
break;
case V_182 :
V_100 -> V_104 = V_105 ;
break;
default:
V_100 -> V_104 = V_183 ;
break;
}
V_100 -> V_87 = V_96 -> V_184 ;
V_100 -> V_88 = V_93 -> V_21 -> V_73 ;
V_100 -> V_89 = V_93 -> V_21 -> V_5 ;
V_100 -> V_15 = V_93 -> V_21 -> V_15 ;
V_100 -> V_185 = V_93 -> V_186 ;
memcpy ( V_100 -> V_126 , V_93 -> V_110 , V_100 -> V_185 ) ;
V_91 -> V_118 = V_93 -> V_118 ;
V_91 -> V_120 . V_38 = F_89 ( V_93 ) ;
if ( F_44 ( V_93 ) ) {
V_30 = (struct V_29 * ) F_43 ( V_93 ) ;
V_31 = F_44 ( V_93 ) ;
if ( F_21 ( V_30 , F_44 ( V_93 ) ) != - 1 ) {
V_91 -> V_41 =
F_22 ( V_30 , F_44 ( V_93 ) ,
F_89 ( V_93 ) ,
V_100 -> V_104 ) ;
if ( ! V_91 -> V_41 ) {
V_66 = V_187 ;
goto V_188;
}
V_91 -> V_51 =
F_23 ( F_89 ( V_93 ) , V_37 ) >>
V_44 ;
if ( V_100 -> V_104 == V_43 )
F_35 ( V_30 ,
V_91 -> V_41 ,
F_44 ( V_93 ) ) ;
V_30 = V_91 -> V_41 ;
V_31 = V_91 -> V_51 ;
}
V_91 -> V_120 . V_35 = V_30 [ 0 ] . V_35 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ )
V_91 -> V_120 . V_189 [ V_32 ] =
F_90 ( F_19 ( ( & V_30 [ V_32 ] ) ) ) ;
} else if ( F_43 ( V_93 ) ) {
V_91 -> V_120 . V_35 =
F_91 ( F_43 ( V_93 ) ) & ( V_37 - 1 ) ;
V_91 -> V_120 . V_189 [ 0 ] =
F_91 ( F_43 ( V_93 ) ) >> V_44 ;
}
V_66 = F_68 ( V_24 , V_91 ) ;
if ( V_66 == - V_190 ) {
if ( V_91 -> V_51 ) {
F_18 ( V_91 -> V_41 ,
V_91 -> V_51 ) ;
V_66 = V_179 ;
goto V_188;
}
}
return 0 ;
V_188:
F_52 ( V_91 , V_102 -> V_124 ) ;
V_93 -> V_123 = NULL ;
return V_66 ;
}
static int F_92 ( struct V_20 * V_21 ,
const struct V_191 * V_192 )
{
int V_66 ;
struct V_117 * V_7 ;
struct V_95 * V_96 ;
bool V_193 = ( ( V_192 -> V_194 == V_195 ) ? true : false ) ;
int V_196 = 0 ;
struct V_19 * V_22 ;
V_7 = F_93 ( & V_197 ,
sizeof( struct V_95 ) ) ;
if ( ! V_7 )
return - V_150 ;
V_96 = F_41 ( V_7 ) ;
memset ( V_96 , 0 , sizeof( struct V_95 ) ) ;
V_96 -> V_184 = V_7 -> V_198 ;
V_96 -> V_24 = V_21 ;
V_22 = F_72 ( sizeof( struct V_19 ) , V_149 ) ;
if ( ! V_22 ) {
V_66 = - V_150 ;
goto V_199;
}
V_22 -> V_23 = false ;
F_94 ( & V_22 -> V_26 ) ;
V_22 -> V_21 = V_21 ;
V_22 -> V_7 = V_7 ;
F_66 ( V_21 , V_22 ) ;
V_22 -> V_87 = V_7 -> V_198 ;
V_66 = F_61 ( V_21 , V_200 ) ;
if ( V_66 )
goto V_201;
V_96 -> V_202 = V_22 -> V_88 ;
V_96 -> V_196 = V_22 -> V_89 ;
V_7 -> V_203 = V_204 ;
V_7 -> V_8 = V_205 ;
V_7 -> V_206 = V_207 - 1 ;
V_7 -> V_208 = V_209 ;
V_66 = F_95 ( V_7 , & V_21 -> V_21 ) ;
if ( V_66 != 0 )
goto V_210;
if ( ! V_193 ) {
F_96 ( V_7 ) ;
} else {
V_196 = ( V_21 -> V_211 . V_212 [ 5 ] << 8 |
V_21 -> V_211 . V_212 [ 4 ] ) ;
V_66 = F_97 ( V_7 , 0 , V_196 , 0 ) ;
if ( V_66 ) {
F_98 ( V_7 ) ;
goto V_210;
}
}
return 0 ;
V_210:
F_63 ( V_21 ) ;
goto V_199;
V_201:
F_4 ( V_22 ) ;
V_199:
F_10 ( V_7 ) ;
return V_66 ;
}
static int F_99 ( struct V_20 * V_24 )
{
struct V_19 * V_22 = F_13 ( V_24 ) ;
struct V_117 * V_7 = V_22 -> V_7 ;
F_98 ( V_7 ) ;
F_63 ( V_24 ) ;
F_10 ( V_7 ) ;
return 0 ;
}
static int T_6 F_100 ( void )
{
T_3 V_213 ;
V_213 =
( ( V_200 - V_37 ) /
F_23 ( V_214 +
sizeof( struct V_65 ) + sizeof( T_4 ) ,
sizeof( T_4 ) ) ) ;
if ( V_213 <
V_159 )
return - V_215 ;
return F_101 ( & V_216 ) ;
}
static void T_7 F_102 ( void )
{
F_103 ( & V_216 ) ;
}
