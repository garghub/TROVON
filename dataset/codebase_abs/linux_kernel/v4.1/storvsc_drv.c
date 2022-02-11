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
struct V_11 * V_8 ;
struct V_6 * V_7 ;
unsigned long V_12 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_8 = V_4 -> V_8 ;
F_8 ( & V_8 -> V_13 ) ;
F_9 ( V_8 -> V_14 , V_12 ) ;
F_10 (sdev, &host->__devices, siblings) {
F_11 ( V_8 -> V_14 , V_12 ) ;
F_12 ( V_7 , 1 , 1 , NULL ) ;
F_9 ( V_8 -> V_14 , V_12 ) ;
continue;
}
F_11 ( V_8 -> V_14 , V_12 ) ;
F_13 ( & V_8 -> V_13 ) ;
F_14 ( V_8 ) ;
F_6 ( V_4 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( ! F_16 ( V_4 -> V_8 ) )
goto V_9;
V_7 = F_3 ( V_4 -> V_8 , 0 , 0 , V_4 -> V_5 ) ;
if ( V_7 ) {
F_17 ( V_7 ) ;
F_5 ( V_7 ) ;
}
F_18 ( V_4 -> V_8 ) ;
V_9:
F_6 ( V_4 ) ;
}
static inline T_2 F_19 ( T_3 V_15 , T_3 V_16 )
{
T_2 V_17 ;
V_17 = ( ( V_15 << 8 ) | V_16 ) ;
return V_17 ;
}
static inline struct V_18 * F_20 (
struct V_19 * V_20 )
{
struct V_18 * V_21 ;
V_21 = F_21 ( V_20 ) ;
if ( V_21 && V_21 -> V_22 )
V_21 = NULL ;
return V_21 ;
}
static inline void F_22 ( struct V_18 * V_23 )
{
V_23 -> V_24 = true ;
F_23 ( V_23 -> V_25 ,
F_24 ( & V_23 -> V_26 ) == 0 ) ;
V_23 -> V_24 = false ;
}
static inline struct V_18 * F_25 (
struct V_19 * V_20 )
{
struct V_18 * V_21 ;
V_21 = F_21 ( V_20 ) ;
if ( ! V_21 )
goto V_27;
if ( V_21 -> V_22 &&
( F_24 ( & V_21 -> V_26 ) == 0 ) )
V_21 = NULL ;
V_27:
return V_21 ;
}
static void F_26 ( struct V_28 * V_29 ,
unsigned int V_30 )
{
int V_31 ;
struct V_32 * V_33 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
V_33 = F_27 ( ( & V_29 [ V_31 ] ) ) ;
if ( V_33 != NULL )
F_28 ( V_33 ) ;
}
F_6 ( V_29 ) ;
}
static int F_29 ( struct V_28 * V_29 , unsigned int V_30 )
{
int V_31 ;
if ( V_30 < 2 )
return - 1 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
if ( V_31 == 0 ) {
if ( V_29 [ V_31 ] . V_34 + V_29 [ V_31 ] . V_35 != V_36 )
return V_31 ;
} else if ( V_31 == V_30 - 1 ) {
if ( V_29 [ V_31 ] . V_34 != 0 )
return V_31 ;
} else {
if ( V_29 [ V_31 ] . V_35 != V_36 || V_29 [ V_31 ] . V_34 != 0 )
return V_31 ;
}
}
return - 1 ;
}
static struct V_28 * F_30 ( struct V_28 * V_29 ,
unsigned int V_30 ,
unsigned int V_37 ,
int V_38 )
{
int V_31 ;
int V_39 ;
struct V_28 * V_40 ;
struct V_32 * V_33 ;
unsigned int V_41 = ( ( V_38 == V_42 ) ? 0 : V_36 ) ;
V_39 = F_31 ( V_37 , V_36 ) >> V_43 ;
V_40 = F_32 ( V_39 , sizeof( struct V_28 ) , V_44 ) ;
if ( ! V_40 )
return NULL ;
F_33 ( V_40 , V_39 ) ;
for ( V_31 = 0 ; V_31 < V_39 ; V_31 ++ ) {
V_33 = F_34 ( V_44 ) ;
if ( ! V_33 )
goto V_45;
F_35 ( & V_40 [ V_31 ] , V_33 , V_41 , 0 ) ;
}
return V_40 ;
V_45:
F_26 ( V_40 , V_39 ) ;
return NULL ;
}
static unsigned int F_36 ( struct V_28 * V_46 ,
struct V_28 * V_40 ,
unsigned int V_47 ,
unsigned int V_48 )
{
int V_31 ;
int V_49 = 0 ;
unsigned long V_50 , V_51 ;
unsigned int V_52 , V_53 , V_54 ;
unsigned int V_55 = 0 ;
unsigned long V_56 = 0 ;
unsigned long V_57 = 0 ;
unsigned long V_12 ;
struct V_28 * V_58 ;
struct V_28 * V_59 ;
F_37 ( V_12 ) ;
V_58 = V_46 ;
V_59 = V_40 ;
for ( V_31 = 0 ; V_31 < V_47 ; V_31 ++ ) {
V_57 = ( unsigned long )
F_38 ( F_27 ( V_58 ) ) +
V_58 -> V_34 ;
V_51 = V_57 ;
V_53 = V_58 -> V_35 ;
if ( V_56 == 0 )
V_56 = ( unsigned long ) F_38 (
F_27 ( V_59 ) ) ;
while ( V_53 ) {
V_50 = V_56 + V_59 -> V_34 ;
V_52 = V_59 -> V_35 - V_59 -> V_34 ;
V_54 = F_39 ( V_52 , V_53 ) ;
memcpy ( ( void * ) V_51 , ( void * ) V_50 , V_54 ) ;
V_55 += V_54 ;
V_59 -> V_34 += V_54 ;
V_53 -= V_54 ;
V_51 += V_54 ;
if ( V_59 -> V_34 == V_59 -> V_35 ) {
F_40 ( ( void * ) V_56 ) ;
V_49 ++ ;
if ( V_49 == V_48 ) {
F_40 ( ( void * ) ( V_57 -
V_58 -> V_34 ) ) ;
F_41 ( V_12 ) ;
return V_55 ;
}
if ( V_53 || V_31 != V_47 - 1 ) {
V_59 = F_42 ( V_59 ) ;
V_56 = ( unsigned long )
F_38 (
F_27 ( V_59 ) ) ;
}
} else if ( V_53 == 0 && V_31 == V_47 - 1 ) {
F_40 ( ( void * ) V_56 ) ;
}
}
F_40 ( ( void * ) ( V_57 - V_58 -> V_34 ) ) ;
V_58 = F_42 ( V_58 ) ;
}
F_41 ( V_12 ) ;
return V_55 ;
}
static unsigned int F_43 ( struct V_28 * V_46 ,
struct V_28 * V_40 ,
unsigned int V_47 )
{
int V_31 ;
int V_49 = 0 ;
unsigned long V_50 , V_51 ;
unsigned int V_52 , V_53 , V_54 ;
unsigned int V_55 = 0 ;
unsigned long V_56 = 0 ;
unsigned long V_60 = 0 ;
unsigned long V_12 ;
struct V_28 * V_59 ;
struct V_28 * V_58 ;
F_37 ( V_12 ) ;
V_59 = V_46 ;
V_58 = V_40 ;
for ( V_31 = 0 ; V_31 < V_47 ; V_31 ++ ) {
V_60 = ( unsigned long )
F_38 ( F_27 ( V_59 ) ) +
V_59 -> V_34 ;
V_50 = V_60 ;
V_52 = V_59 -> V_35 ;
if ( V_56 == 0 )
V_56 = ( unsigned long )
F_38 ( F_27 ( V_58 ) ) ;
while ( V_52 ) {
V_51 = V_56 + V_58 -> V_35 ;
V_53 = V_36 - V_58 -> V_35 ;
V_54 = F_39 ( V_52 , V_53 ) ;
memcpy ( ( void * ) V_51 , ( void * ) V_50 , V_54 ) ;
V_55 += V_54 ;
V_58 -> V_35 += V_54 ;
V_52 -= V_54 ;
V_50 += V_54 ;
if ( V_58 -> V_35 == V_36 ) {
F_40 ( ( void * ) V_56 ) ;
V_56 = 0 ;
V_49 ++ ;
}
if ( V_52 && V_56 == 0 ) {
V_58 = F_42 ( V_58 ) ;
V_56 = ( unsigned long )
F_38 (
F_27 ( V_58 ) ) ;
}
}
F_40 ( ( void * ) ( V_60 - V_59 -> V_34 ) ) ;
V_59 = F_42 ( V_59 ) ;
}
if ( V_56 )
F_40 ( ( void * ) V_56 ) ;
F_41 ( V_12 ) ;
return V_55 ;
}
static void F_44 ( struct V_61 * V_62 )
{
struct V_19 * V_20 = V_62 -> V_63 -> V_64 ;
struct V_18 * V_21 ;
struct V_65 V_66 ;
V_21 = F_20 ( V_20 ) ;
if ( ! V_21 )
return;
if ( V_21 -> V_67 == false )
return;
memset ( & V_66 , 0 , sizeof( struct V_65 ) ) ;
F_45 ( V_62 ,
V_68 ,
V_68 ,
( void * ) & V_66 ,
sizeof( struct V_65 ) ,
V_69 , V_62 ) ;
}
static void F_46 ( struct V_19 * V_20 , int V_70 )
{
struct V_18 * V_21 ;
int V_71 = F_47 () ;
int V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_75 ;
int V_76 , V_77 ;
V_72 = ( ( V_70 > V_71 ) ? V_71 : V_70 ) ;
V_21 = F_20 ( V_20 ) ;
if ( ! V_21 )
return;
V_74 = & V_21 -> V_78 ;
V_75 = & V_74 -> V_75 ;
V_21 -> V_67 = true ;
F_48 ( V_20 -> V_79 , F_44 ) ;
if ( F_49 ( V_20 -> V_79 ) )
return;
V_21 -> V_67 = false ;
memset ( V_74 , 0 , sizeof( struct V_73 ) ) ;
F_50 ( & V_74 -> F_23 ) ;
V_75 -> V_80 = V_81 ;
V_75 -> V_12 = V_82 ;
V_75 -> V_83 = V_72 ;
V_76 = F_51 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ,
V_85 ,
V_86 ) ;
if ( V_76 != 0 )
return;
V_77 = F_52 ( & V_74 -> F_23 , 10 * V_87 ) ;
if ( V_77 == 0 )
return;
if ( V_75 -> V_80 != V_88 ||
V_75 -> V_89 != 0 )
return;
V_21 -> V_67 = true ;
F_49 ( V_20 -> V_79 ) ;
}
static int F_53 ( struct V_19 * V_20 )
{
struct V_18 * V_21 ;
struct V_73 * V_74 ;
struct V_75 * V_75 ;
int V_76 , V_77 ;
int V_70 ;
bool V_90 = false ;
V_21 = F_20 ( V_20 ) ;
if ( ! V_21 )
return - V_91 ;
V_74 = & V_21 -> V_78 ;
V_75 = & V_74 -> V_75 ;
memset ( V_74 , 0 , sizeof( struct V_73 ) ) ;
F_50 ( & V_74 -> F_23 ) ;
V_75 -> V_80 = V_92 ;
V_75 -> V_12 = V_82 ;
V_76 = F_51 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ,
V_85 ,
V_86 ) ;
if ( V_76 != 0 )
goto V_45;
V_77 = F_52 ( & V_74 -> F_23 , 5 * V_87 ) ;
if ( V_77 == 0 ) {
V_76 = - V_93 ;
goto V_45;
}
if ( V_75 -> V_80 != V_88 ||
V_75 -> V_89 != 0 )
goto V_45;
memset ( V_75 , 0 , sizeof( struct V_75 ) ) ;
V_75 -> V_80 = V_94 ;
V_75 -> V_12 = V_82 ;
V_75 -> V_17 . V_95 =
F_19 ( V_96 , V_97 ) ;
V_75 -> V_17 . V_98 = 0 ;
V_76 = F_51 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ,
V_85 ,
V_86 ) ;
if ( V_76 != 0 )
goto V_45;
V_77 = F_52 ( & V_74 -> F_23 , 5 * V_87 ) ;
if ( V_77 == 0 ) {
V_76 = - V_93 ;
goto V_45;
}
if ( V_75 -> V_80 != V_88 ||
V_75 -> V_89 != 0 )
goto V_45;
memset ( V_75 , 0 , sizeof( struct V_75 ) ) ;
V_75 -> V_80 = V_99 ;
V_75 -> V_12 = V_82 ;
V_76 = F_51 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ,
V_85 ,
V_86 ) ;
if ( V_76 != 0 )
goto V_45;
V_77 = F_52 ( & V_74 -> F_23 , 5 * V_87 ) ;
if ( V_77 == 0 ) {
V_76 = - V_93 ;
goto V_45;
}
if ( V_75 -> V_80 != V_88 ||
V_75 -> V_89 != 0 )
goto V_45;
V_70 = V_75 -> V_100 . V_101 ;
if ( ( V_102 != V_103 ) &&
( V_102 != V_104 ) ) {
if ( V_75 -> V_100 . V_12 &
V_105 )
V_90 = true ;
}
V_21 -> V_106 =
V_75 -> V_100 . V_106 ;
memset ( V_75 , 0 , sizeof( struct V_75 ) ) ;
V_75 -> V_80 = V_107 ;
V_75 -> V_12 = V_82 ;
V_76 = F_51 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ,
V_85 ,
V_86 ) ;
if ( V_76 != 0 )
goto V_45;
V_77 = F_52 ( & V_74 -> F_23 , 5 * V_87 ) ;
if ( V_77 == 0 ) {
V_76 = - V_93 ;
goto V_45;
}
if ( V_75 -> V_80 != V_88 ||
V_75 -> V_89 != 0 )
goto V_45;
if ( V_90 )
F_46 ( V_20 , V_70 ) ;
V_45:
return V_76 ;
}
static void F_54 ( struct V_108 * V_109 ,
struct V_110 * V_111 ,
struct V_11 * V_8 ,
T_3 V_112 , T_3 V_113 )
{
struct V_3 * V_4 ;
void (* F_55)( struct V_1 * V_2 );
bool V_114 = false ;
switch ( V_109 -> V_115 ) {
case V_116 :
switch ( V_111 -> V_117 [ 0 ] ) {
case V_118 :
case V_119 :
F_56 ( V_111 , V_120 ) ;
break;
case V_121 :
break;
default:
F_56 ( V_111 , V_122 ) ;
}
break;
case V_123 :
V_114 = true ;
F_55 = F_15 ;
break;
case ( V_124 | V_125 ) :
if ( ( V_112 == 0x2a ) && ( V_113 == 0x9 ) ) {
V_114 = true ;
F_55 = F_1 ;
F_56 ( V_111 , V_126 ) ;
}
break;
}
if ( ! V_114 )
return;
V_4 = F_57 ( sizeof( struct V_3 ) , V_44 ) ;
if ( ! V_4 ) {
F_56 ( V_111 , V_122 ) ;
return;
}
V_4 -> V_8 = V_8 ;
V_4 -> V_5 = V_109 -> V_5 ;
F_58 ( & V_4 -> V_2 , F_55 ) ;
F_59 ( & V_4 -> V_2 ) ;
}
static void F_60 ( struct V_73 * V_127 )
{
struct V_110 * V_111 = V_127 -> V_128 ;
struct V_129 * V_130 = F_61 ( V_111 -> V_20 -> V_8 ) ;
struct V_131 V_132 ;
struct V_108 * V_109 ;
struct V_11 * V_8 ;
struct V_18 * V_133 ;
struct V_19 * V_23 = V_130 -> V_23 ;
T_4 V_134 = V_127 -> V_134 ;
void * V_135 = V_127 -> V_135 ;
V_133 = F_25 ( V_23 ) ;
V_8 = V_133 -> V_8 ;
V_109 = & V_127 -> V_75 . V_109 ;
if ( V_127 -> V_48 ) {
if ( V_109 -> V_136 == V_137 )
F_36 ( F_62 ( V_111 ) ,
V_127 -> V_40 ,
F_63 ( V_111 ) ,
V_127 -> V_48 ) ;
F_26 ( V_127 -> V_40 ,
V_127 -> V_48 ) ;
}
V_111 -> V_138 = V_109 -> V_139 ;
if ( V_111 -> V_138 ) {
if ( F_64 ( V_111 -> V_140 ,
V_141 , & V_132 ) )
F_65 ( V_111 -> V_20 , L_1 ,
& V_132 ) ;
}
if ( V_109 -> V_115 != V_142 )
F_54 ( V_109 , V_111 , V_8 , V_132 . V_112 ,
V_132 . V_113 ) ;
F_66 ( V_111 ,
V_127 -> V_135 -> V_143 . V_37 -
V_109 -> V_144 ) ;
V_111 -> V_145 ( V_111 ) ;
if ( V_134 >
sizeof( struct V_146 ) )
F_6 ( V_135 ) ;
}
static void F_67 ( struct V_19 * V_20 ,
struct V_75 * V_75 ,
struct V_73 * V_74 )
{
struct V_18 * V_21 ;
struct V_75 * V_147 ;
V_21 = F_21 ( V_20 ) ;
V_147 = & V_74 -> V_75 ;
if ( ( V_147 -> V_109 . V_148 [ 0 ] == V_149 ) ||
( V_147 -> V_109 . V_148 [ 0 ] == V_150 ) ) {
V_75 -> V_109 . V_139 = 0 ;
V_75 -> V_109 . V_115 = V_142 ;
}
V_147 -> V_109 . V_139 = V_75 -> V_109 . V_139 ;
V_147 -> V_109 . V_115 = V_75 -> V_109 . V_115 ;
V_147 -> V_109 . V_151 =
V_75 -> V_109 . V_151 ;
if ( ( V_75 -> V_109 . V_139 & 0xFF ) == 0x02 ) {
if ( V_75 -> V_109 . V_115 &
V_125 ) {
memcpy ( V_74 -> V_128 -> V_140 ,
V_75 -> V_109 . V_152 ,
V_75 -> V_109 . V_151 ) ;
}
}
V_147 -> V_109 . V_144 =
V_75 -> V_109 . V_144 ;
F_60 ( V_74 ) ;
if ( F_68 ( & V_21 -> V_26 ) &&
V_21 -> V_24 )
F_69 ( & V_21 -> V_25 ) ;
}
static void F_70 ( struct V_19 * V_20 ,
struct V_75 * V_75 ,
struct V_73 * V_74 )
{
struct V_3 * V_2 ;
struct V_18 * V_21 ;
switch ( V_75 -> V_80 ) {
case V_88 :
F_67 ( V_20 , V_75 , V_74 ) ;
break;
case V_153 :
case V_154 :
V_21 = F_25 ( V_20 ) ;
V_2 = F_57 ( sizeof( struct V_3 ) , V_44 ) ;
if ( ! V_2 )
return;
F_58 ( & V_2 -> V_2 , F_7 ) ;
V_2 -> V_8 = V_21 -> V_8 ;
F_59 ( & V_2 -> V_2 ) ;
break;
default:
break;
}
}
static void V_69 ( void * V_155 )
{
struct V_61 * V_79 = (struct V_61 * ) V_155 ;
struct V_19 * V_20 ;
struct V_18 * V_21 ;
T_4 V_156 ;
T_5 V_157 ;
unsigned char V_158 [ F_31 ( sizeof( struct V_75 ) , 8 ) ] ;
struct V_73 * V_74 ;
int V_76 ;
if ( V_79 -> V_63 != NULL )
V_20 = V_79 -> V_63 -> V_64 ;
else
V_20 = V_79 -> V_64 ;
V_21 = F_25 ( V_20 ) ;
if ( ! V_21 )
return;
do {
V_76 = F_71 ( V_79 , V_158 ,
F_31 ( ( sizeof( struct V_75 ) -
V_84 ) , 8 ) ,
& V_156 , & V_157 ) ;
if ( V_76 == 0 && V_156 > 0 ) {
V_74 = (struct V_73 * )
( unsigned long ) V_157 ;
if ( ( V_74 == & V_21 -> V_78 ) ||
( V_74 == & V_21 -> V_159 ) ) {
memcpy ( & V_74 -> V_75 , V_158 ,
( sizeof( struct V_75 ) -
V_84 ) ) ;
F_72 ( & V_74 -> F_23 ) ;
} else {
F_70 ( V_20 ,
(struct V_75 * ) V_158 ,
V_74 ) ;
}
} else {
break;
}
} while ( 1 );
return;
}
static int F_73 ( struct V_19 * V_20 , T_4 V_160 )
{
struct V_65 V_66 ;
int V_76 ;
memset ( & V_66 , 0 , sizeof( struct V_65 ) ) ;
V_76 = F_45 ( V_20 -> V_79 ,
V_160 ,
V_160 ,
( void * ) & V_66 ,
sizeof( struct V_65 ) ,
V_69 , V_20 -> V_79 ) ;
if ( V_76 != 0 )
return V_76 ;
V_76 = F_53 ( V_20 ) ;
return V_76 ;
}
static int F_74 ( struct V_19 * V_20 )
{
struct V_18 * V_21 ;
unsigned long V_12 ;
V_21 = F_21 ( V_20 ) ;
F_9 ( & V_20 -> V_79 -> V_161 , V_12 ) ;
V_21 -> V_22 = true ;
F_11 ( & V_20 -> V_79 -> V_161 , V_12 ) ;
F_22 ( V_21 ) ;
F_9 ( & V_20 -> V_79 -> V_161 , V_12 ) ;
F_75 ( V_20 , NULL ) ;
F_11 ( & V_20 -> V_79 -> V_161 , V_12 ) ;
F_76 ( V_20 -> V_79 ) ;
F_6 ( V_21 ) ;
return 0 ;
}
static int F_77 ( struct V_19 * V_20 ,
struct V_73 * V_74 )
{
struct V_18 * V_21 ;
struct V_75 * V_75 ;
struct V_61 * V_162 ;
int V_76 = 0 ;
V_75 = & V_74 -> V_75 ;
V_21 = F_20 ( V_20 ) ;
if ( ! V_21 )
return - V_91 ;
V_74 -> V_20 = V_20 ;
V_162 = F_78 ( V_20 -> V_79 ) ;
V_75 -> V_12 |= V_82 ;
V_75 -> V_109 . V_35 = ( sizeof( struct V_108 ) -
V_84 ) ;
V_75 -> V_109 . V_151 = V_163 ;
V_75 -> V_109 . V_144 =
V_74 -> V_135 -> V_143 . V_37 ;
V_75 -> V_80 = V_164 ;
if ( V_74 -> V_135 -> V_143 . V_37 ) {
V_76 = F_79 ( V_162 ,
V_74 -> V_135 , V_74 -> V_134 ,
V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ) ;
} else {
V_76 = F_51 ( V_162 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ,
V_85 ,
V_86 ) ;
}
if ( V_76 != 0 )
return V_76 ;
F_80 ( & V_21 -> V_26 ) ;
return V_76 ;
}
static int F_81 ( struct V_6 * V_165 )
{
F_82 ( V_165 -> V_166 , V_36 ) ;
F_83 ( V_165 -> V_166 , V_167 ) ;
F_84 ( V_165 -> V_166 , ( V_168 * V_87 ) ) ;
V_165 -> V_169 = 1 ;
V_165 -> V_170 |= V_171 ;
if ( ! strncmp ( V_165 -> V_172 , L_2 , 4 ) ) {
switch ( V_102 ) {
case V_173 :
case V_174 :
V_165 -> V_175 = V_176 ;
break;
}
}
return 0 ;
}
static int F_85 ( struct V_6 * V_7 , struct V_177 * V_178 ,
T_6 V_179 , int * V_180 )
{
T_6 V_181 = V_179 ;
T_6 V_182 = V_181 ;
int V_183 , V_184 ;
V_183 = 0xff ;
V_184 = 0x3f ;
F_86 ( V_182 , V_183 * V_184 ) ;
if ( ( T_6 ) ( V_182 + 1 ) * V_183 * V_184 < V_181 )
V_182 = 0xffff ;
V_180 [ 0 ] = V_183 ;
V_180 [ 1 ] = V_184 ;
V_180 [ 2 ] = ( int ) V_182 ;
return 0 ;
}
static int F_87 ( struct V_110 * V_111 )
{
struct V_129 * V_130 = F_61 ( V_111 -> V_20 -> V_8 ) ;
struct V_19 * V_20 = V_130 -> V_23 ;
struct V_18 * V_21 ;
struct V_73 * V_74 ;
struct V_75 * V_75 ;
int V_76 , V_77 ;
V_21 = F_20 ( V_20 ) ;
if ( ! V_21 )
return V_185 ;
V_74 = & V_21 -> V_159 ;
V_75 = & V_74 -> V_75 ;
F_50 ( & V_74 -> F_23 ) ;
V_75 -> V_80 = V_186 ;
V_75 -> V_12 = V_82 ;
V_75 -> V_109 . V_187 = V_21 -> V_187 ;
V_76 = F_51 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) & V_21 -> V_159 ,
V_85 ,
V_86 ) ;
if ( V_76 != 0 )
return V_185 ;
V_77 = F_52 ( & V_74 -> F_23 , 5 * V_87 ) ;
if ( V_77 == 0 )
return V_188 ;
F_22 ( V_21 ) ;
return V_189 ;
}
static enum V_190 F_88 ( struct V_110 * V_111 )
{
return V_191 ;
}
static bool F_89 ( struct V_110 * V_111 )
{
bool V_192 = true ;
T_3 V_193 = V_111 -> V_117 [ 0 ] ;
switch ( V_193 ) {
case V_194 :
case V_195 :
V_111 -> V_138 = V_196 << 16 ;
V_192 = false ;
break;
default:
break;
}
return V_192 ;
}
static int F_90 ( struct V_11 * V_8 , struct V_110 * V_111 )
{
int V_76 ;
struct V_129 * V_130 = F_61 ( V_8 ) ;
struct V_19 * V_23 = V_130 -> V_23 ;
struct V_73 * V_127 = F_91 ( V_111 ) ;
int V_31 ;
struct V_28 * V_29 ;
unsigned int V_30 = 0 ;
struct V_108 * V_109 ;
struct V_28 * V_197 ;
struct V_198 * V_135 ;
T_4 V_134 ;
T_4 V_35 ;
if ( V_96 <= V_199 ) {
if ( ! F_89 ( V_111 ) ) {
V_111 -> V_145 ( V_111 ) ;
return 0 ;
}
}
V_127 -> V_128 = V_111 ;
V_109 = & V_127 -> V_75 . V_109 ;
V_109 -> V_200 . V_201 = 60 ;
V_109 -> V_200 . V_202 |=
( V_203 |
V_204 ) ;
switch ( V_111 -> V_205 ) {
case V_206 :
V_109 -> V_136 = V_42 ;
V_109 -> V_200 . V_202 |= V_207 ;
break;
case V_208 :
V_109 -> V_136 = V_137 ;
V_109 -> V_200 . V_202 |= V_209 ;
break;
default:
V_109 -> V_136 = V_210 ;
V_109 -> V_200 . V_202 |= V_211 ;
break;
}
V_109 -> V_212 = V_130 -> V_213 ;
V_109 -> V_187 = V_111 -> V_20 -> V_79 ;
V_109 -> V_214 = V_111 -> V_20 -> V_215 ;
V_109 -> V_5 = V_111 -> V_20 -> V_5 ;
V_109 -> V_216 = V_111 -> V_217 ;
memcpy ( V_109 -> V_148 , V_111 -> V_117 , V_109 -> V_216 ) ;
V_29 = (struct V_28 * ) F_62 ( V_111 ) ;
V_30 = F_63 ( V_111 ) ;
V_35 = F_92 ( V_111 ) ;
V_135 = (struct V_198 * ) & V_127 -> V_218 ;
V_134 = sizeof( V_127 -> V_218 ) ;
if ( V_30 ) {
if ( F_29 ( V_29 , F_63 ( V_111 ) ) != - 1 ) {
V_127 -> V_40 =
F_30 ( V_29 , V_30 ,
V_35 ,
V_109 -> V_136 ) ;
if ( ! V_127 -> V_40 )
return V_219 ;
V_127 -> V_48 =
F_31 ( V_35 , V_36 ) >> V_43 ;
if ( V_109 -> V_136 == V_42 )
F_43 ( V_29 ,
V_127 -> V_40 , V_30 ) ;
V_29 = V_127 -> V_40 ;
V_30 = V_127 -> V_48 ;
}
if ( V_30 > V_220 ) {
V_134 = ( V_30 * sizeof( void * ) +
sizeof( struct V_198 ) ) ;
V_135 = F_57 ( V_134 , V_44 ) ;
if ( ! V_135 ) {
if ( V_127 -> V_48 )
F_26 (
V_127 -> V_40 ,
V_127 -> V_48 ) ;
return V_221 ;
}
}
V_135 -> V_143 . V_37 = V_35 ;
V_135 -> V_143 . V_34 = V_29 [ 0 ] . V_34 ;
V_197 = V_29 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
V_135 -> V_143 . V_222 [ V_31 ] =
F_93 ( F_27 ( ( V_197 ) ) ) ;
V_197 = F_42 ( V_197 ) ;
}
} else if ( F_62 ( V_111 ) ) {
V_135 -> V_143 . V_37 = V_35 ;
V_135 -> V_143 . V_34 =
F_94 ( F_62 ( V_111 ) ) & ( V_36 - 1 ) ;
V_135 -> V_143 . V_222 [ 0 ] =
F_94 ( F_62 ( V_111 ) ) >> V_43 ;
}
V_127 -> V_135 = V_135 ;
V_127 -> V_134 = V_134 ;
V_76 = F_77 ( V_23 , V_127 ) ;
if ( V_76 == - V_223 ) {
if ( V_127 -> V_48 )
F_26 ( V_127 -> V_40 ,
V_127 -> V_48 ) ;
return V_221 ;
}
return 0 ;
}
static int F_95 ( struct V_19 * V_20 ,
const struct V_224 * V_225 )
{
int V_76 ;
int V_71 = F_47 () ;
struct V_11 * V_8 ;
struct V_129 * V_130 ;
bool V_226 = ( ( V_225 -> V_227 == V_228 ) ? true : false ) ;
int V_229 = 0 ;
struct V_18 * V_21 ;
int V_230 ;
int V_231 ;
int V_232 ;
int V_233 = 0 ;
switch ( V_102 ) {
case V_104 :
case V_103 :
V_163 = V_234 ;
V_84 = sizeof( struct V_235 ) ;
V_96 = V_236 ;
V_97 = V_237 ;
V_230 = V_238 ;
V_231 = V_239 ;
V_232 = V_240 ;
break;
default:
V_163 = V_241 ;
V_84 = 0 ;
V_96 = V_199 ;
V_97 = V_242 ;
V_230 = V_243 ;
V_231 = V_244 ;
V_232 = V_245 ;
V_233 = ( V_71 / V_246 ) ;
break;
}
V_247 . V_248 = ( V_249 *
( V_233 + 1 ) ) ;
V_8 = F_96 ( & V_247 ,
sizeof( struct V_129 ) ) ;
if ( ! V_8 )
return - V_250 ;
V_130 = F_61 ( V_8 ) ;
memset ( V_130 , 0 , sizeof( struct V_129 ) ) ;
V_130 -> V_213 = V_8 -> V_251 ;
V_130 -> V_23 = V_20 ;
V_21 = F_97 ( sizeof( struct V_18 ) , V_252 ) ;
if ( ! V_21 ) {
V_76 = - V_250 ;
goto V_253;
}
V_21 -> V_22 = false ;
V_21 -> V_67 = false ;
F_98 ( & V_21 -> V_25 ) ;
V_21 -> V_20 = V_20 ;
V_21 -> V_8 = V_8 ;
F_75 ( V_20 , V_21 ) ;
V_21 -> V_212 = V_8 -> V_251 ;
V_76 = F_73 ( V_20 , V_68 ) ;
if ( V_76 )
goto V_254;
V_130 -> V_255 = V_21 -> V_187 ;
V_130 -> V_229 = V_21 -> V_214 ;
switch ( V_225 -> V_227 ) {
case V_256 :
V_8 -> V_257 = V_258 ;
V_8 -> V_259 = V_260 ;
V_8 -> V_261 = V_262 - 1 ;
break;
case V_263 :
V_8 -> V_257 = V_230 ;
V_8 -> V_259 = V_231 ;
V_8 -> V_261 = V_232 - 1 ;
break;
default:
V_8 -> V_257 = V_238 ;
V_8 -> V_259 = V_239 ;
V_8 -> V_261 = V_240 - 1 ;
break;
}
V_8 -> V_264 = V_265 ;
V_8 -> V_266 = ( V_21 -> V_106 >> V_43 ) ;
V_76 = F_99 ( V_8 , & V_20 -> V_20 ) ;
if ( V_76 != 0 )
goto V_267;
if ( ! V_226 ) {
F_14 ( V_8 ) ;
} else {
V_229 = ( V_20 -> V_268 . V_269 [ 5 ] << 8 |
V_20 -> V_268 . V_269 [ 4 ] ) ;
V_76 = F_100 ( V_8 , 0 , V_229 , 0 ) ;
if ( V_76 ) {
F_101 ( V_8 ) ;
goto V_267;
}
}
return 0 ;
V_267:
F_74 ( V_20 ) ;
goto V_253;
V_254:
F_6 ( V_21 ) ;
V_253:
F_18 ( V_8 ) ;
return V_76 ;
}
static int F_102 ( struct V_19 * V_23 )
{
struct V_18 * V_21 = F_21 ( V_23 ) ;
struct V_11 * V_8 = V_21 -> V_8 ;
F_101 ( V_8 ) ;
F_74 ( V_23 ) ;
F_18 ( V_8 ) ;
return 0 ;
}
static int T_7 F_103 ( void )
{
V_249 =
( ( V_68 - V_36 ) /
F_31 ( V_270 +
sizeof( struct V_75 ) + sizeof( T_5 ) -
V_84 ,
sizeof( T_5 ) ) ) ;
return F_104 ( & V_271 ) ;
}
static void T_8 F_105 ( void )
{
F_106 ( & V_271 ) ;
}
