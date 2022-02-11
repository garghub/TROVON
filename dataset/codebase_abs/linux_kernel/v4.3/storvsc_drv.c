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
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_8 = V_4 -> V_8 ;
F_8 ( & V_8 -> V_12 ) ;
F_9 (sdev, host)
F_10 ( V_7 , 1 , 1 , NULL ) ;
F_11 ( & V_8 -> V_12 ) ;
F_12 ( V_8 ) ;
F_6 ( V_4 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( ! F_14 ( V_4 -> V_8 ) )
goto V_9;
V_7 = F_3 ( V_4 -> V_8 , 0 , 0 , V_4 -> V_5 ) ;
if ( V_7 ) {
F_15 ( V_7 ) ;
F_5 ( V_7 ) ;
}
F_16 ( V_4 -> V_8 ) ;
V_9:
F_6 ( V_4 ) ;
}
static inline struct V_13 * F_17 (
struct V_14 * V_15 )
{
struct V_13 * V_16 ;
V_16 = F_18 ( V_15 ) ;
if ( V_16 && V_16 -> V_17 )
V_16 = NULL ;
return V_16 ;
}
static inline void F_19 ( struct V_13 * V_18 )
{
V_18 -> V_19 = true ;
F_20 ( V_18 -> V_20 ,
F_21 ( & V_18 -> V_21 ) == 0 ) ;
V_18 -> V_19 = false ;
}
static inline struct V_13 * F_22 (
struct V_14 * V_15 )
{
struct V_13 * V_16 ;
V_16 = F_18 ( V_15 ) ;
if ( ! V_16 )
goto V_22;
if ( V_16 -> V_17 &&
( F_21 ( & V_16 -> V_21 ) == 0 ) )
V_16 = NULL ;
V_22:
return V_16 ;
}
static void F_23 ( struct V_23 * V_24 ,
unsigned int V_25 )
{
int V_26 ;
struct V_27 * V_28 ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
V_28 = F_24 ( ( & V_24 [ V_26 ] ) ) ;
if ( V_28 != NULL )
F_25 ( V_28 ) ;
}
F_6 ( V_24 ) ;
}
static int F_26 ( struct V_23 * V_24 , unsigned int V_25 )
{
int V_26 ;
if ( V_25 < 2 )
return - 1 ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
if ( V_26 == 0 ) {
if ( V_24 [ V_26 ] . V_29 + V_24 [ V_26 ] . V_30 != V_31 )
return V_26 ;
} else if ( V_26 == V_25 - 1 ) {
if ( V_24 [ V_26 ] . V_29 != 0 )
return V_26 ;
} else {
if ( V_24 [ V_26 ] . V_30 != V_31 || V_24 [ V_26 ] . V_29 != 0 )
return V_26 ;
}
}
return - 1 ;
}
static struct V_23 * F_27 ( struct V_23 * V_24 ,
unsigned int V_25 ,
unsigned int V_32 ,
int V_33 )
{
int V_26 ;
int V_34 ;
struct V_23 * V_35 ;
struct V_27 * V_28 ;
unsigned int V_36 = ( ( V_33 == V_37 ) ? 0 : V_31 ) ;
V_34 = F_28 ( V_32 , V_31 ) >> V_38 ;
V_35 = F_29 ( V_34 , sizeof( struct V_23 ) , V_39 ) ;
if ( ! V_35 )
return NULL ;
F_30 ( V_35 , V_34 ) ;
for ( V_26 = 0 ; V_26 < V_34 ; V_26 ++ ) {
V_28 = F_31 ( V_39 ) ;
if ( ! V_28 )
goto V_40;
F_32 ( & V_35 [ V_26 ] , V_28 , V_36 , 0 ) ;
}
return V_35 ;
V_40:
F_23 ( V_35 , V_34 ) ;
return NULL ;
}
static unsigned int F_33 ( struct V_23 * V_41 ,
struct V_23 * V_35 ,
unsigned int V_42 ,
unsigned int V_43 )
{
int V_26 ;
int V_44 = 0 ;
unsigned long V_45 , V_46 ;
unsigned int V_47 , V_48 , V_49 ;
unsigned int V_50 = 0 ;
unsigned long V_51 = 0 ;
unsigned long V_52 = 0 ;
unsigned long V_53 ;
struct V_23 * V_54 ;
struct V_23 * V_55 ;
F_34 ( V_53 ) ;
V_54 = V_41 ;
V_55 = V_35 ;
for ( V_26 = 0 ; V_26 < V_42 ; V_26 ++ ) {
V_52 = ( unsigned long )
F_35 ( F_24 ( V_54 ) ) +
V_54 -> V_29 ;
V_46 = V_52 ;
V_48 = V_54 -> V_30 ;
if ( V_51 == 0 )
V_51 = ( unsigned long ) F_35 (
F_24 ( V_55 ) ) ;
while ( V_48 ) {
V_45 = V_51 + V_55 -> V_29 ;
V_47 = V_55 -> V_30 - V_55 -> V_29 ;
V_49 = F_36 ( V_47 , V_48 ) ;
memcpy ( ( void * ) V_46 , ( void * ) V_45 , V_49 ) ;
V_50 += V_49 ;
V_55 -> V_29 += V_49 ;
V_48 -= V_49 ;
V_46 += V_49 ;
if ( V_55 -> V_29 == V_55 -> V_30 ) {
F_37 ( ( void * ) V_51 ) ;
V_44 ++ ;
if ( V_44 == V_43 ) {
F_37 ( ( void * ) ( V_52 -
V_54 -> V_29 ) ) ;
F_38 ( V_53 ) ;
return V_50 ;
}
if ( V_48 || V_26 != V_42 - 1 ) {
V_55 = F_39 ( V_55 ) ;
V_51 = ( unsigned long )
F_35 (
F_24 ( V_55 ) ) ;
}
} else if ( V_48 == 0 && V_26 == V_42 - 1 ) {
F_37 ( ( void * ) V_51 ) ;
}
}
F_37 ( ( void * ) ( V_52 - V_54 -> V_29 ) ) ;
V_54 = F_39 ( V_54 ) ;
}
F_38 ( V_53 ) ;
return V_50 ;
}
static unsigned int F_40 ( struct V_23 * V_41 ,
struct V_23 * V_35 ,
unsigned int V_42 )
{
int V_26 ;
int V_44 = 0 ;
unsigned long V_45 , V_46 ;
unsigned int V_47 , V_48 , V_49 ;
unsigned int V_50 = 0 ;
unsigned long V_51 = 0 ;
unsigned long V_56 = 0 ;
unsigned long V_53 ;
struct V_23 * V_55 ;
struct V_23 * V_54 ;
F_34 ( V_53 ) ;
V_55 = V_41 ;
V_54 = V_35 ;
for ( V_26 = 0 ; V_26 < V_42 ; V_26 ++ ) {
V_56 = ( unsigned long )
F_35 ( F_24 ( V_55 ) ) +
V_55 -> V_29 ;
V_45 = V_56 ;
V_47 = V_55 -> V_30 ;
if ( V_51 == 0 )
V_51 = ( unsigned long )
F_35 ( F_24 ( V_54 ) ) ;
while ( V_47 ) {
V_46 = V_51 + V_54 -> V_30 ;
V_48 = V_31 - V_54 -> V_30 ;
V_49 = F_36 ( V_47 , V_48 ) ;
memcpy ( ( void * ) V_46 , ( void * ) V_45 , V_49 ) ;
V_50 += V_49 ;
V_54 -> V_30 += V_49 ;
V_47 -= V_49 ;
V_45 += V_49 ;
if ( V_54 -> V_30 == V_31 ) {
F_37 ( ( void * ) V_51 ) ;
V_51 = 0 ;
V_44 ++ ;
}
if ( V_47 && V_51 == 0 ) {
V_54 = F_39 ( V_54 ) ;
V_51 = ( unsigned long )
F_35 (
F_24 ( V_54 ) ) ;
}
}
F_37 ( ( void * ) ( V_56 - V_55 -> V_29 ) ) ;
V_55 = F_39 ( V_55 ) ;
}
if ( V_51 )
F_37 ( ( void * ) V_51 ) ;
F_38 ( V_53 ) ;
return V_50 ;
}
static void F_41 ( struct V_57 * V_58 )
{
struct V_14 * V_15 = V_58 -> V_59 -> V_60 ;
struct V_13 * V_16 ;
struct V_61 V_62 ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 )
return;
if ( V_16 -> V_63 == false )
return;
memset ( & V_62 , 0 , sizeof( struct V_61 ) ) ;
F_42 ( V_58 ,
V_64 ,
V_64 ,
( void * ) & V_62 ,
sizeof( struct V_61 ) ,
V_65 , V_58 ) ;
}
static void F_43 ( struct V_14 * V_15 , int V_66 )
{
struct V_13 * V_16 ;
int V_67 = F_44 () ;
int V_68 ;
struct V_69 * V_70 ;
struct V_71 * V_71 ;
int V_72 , V_73 ;
V_68 = ( ( V_66 > V_67 ) ? V_67 : V_66 ) ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 )
return;
V_70 = & V_16 -> V_74 ;
V_71 = & V_70 -> V_71 ;
V_16 -> V_63 = true ;
F_45 ( V_15 -> V_75 , F_41 ) ;
if ( F_46 ( V_15 -> V_75 ) )
return;
V_16 -> V_63 = false ;
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
F_47 ( & V_70 -> F_20 ) ;
V_71 -> V_76 = V_77 ;
V_71 -> V_53 = V_78 ;
V_71 -> V_79 = V_68 ;
V_72 = F_48 ( V_15 -> V_75 , V_71 ,
( sizeof( struct V_71 ) -
V_80 ) ,
( unsigned long ) V_70 ,
V_81 ,
V_82 ) ;
if ( V_72 != 0 )
return;
V_73 = F_49 ( & V_70 -> F_20 , 10 * V_83 ) ;
if ( V_73 == 0 )
return;
if ( V_71 -> V_76 != V_84 ||
V_71 -> V_85 != 0 )
return;
V_16 -> V_63 = true ;
F_46 ( V_15 -> V_75 ) ;
}
static int F_50 ( struct V_14 * V_15 )
{
struct V_13 * V_16 ;
struct V_69 * V_70 ;
struct V_71 * V_71 ;
int V_72 , V_73 , V_26 ;
int V_66 ;
bool V_86 = false ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 )
return - V_87 ;
V_70 = & V_16 -> V_74 ;
V_71 = & V_70 -> V_71 ;
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
F_47 ( & V_70 -> F_20 ) ;
V_71 -> V_76 = V_88 ;
V_71 -> V_53 = V_78 ;
V_72 = F_48 ( V_15 -> V_75 , V_71 ,
( sizeof( struct V_71 ) -
V_80 ) ,
( unsigned long ) V_70 ,
V_81 ,
V_82 ) ;
if ( V_72 != 0 )
goto V_40;
V_73 = F_49 ( & V_70 -> F_20 , 5 * V_83 ) ;
if ( V_73 == 0 ) {
V_72 = - V_89 ;
goto V_40;
}
if ( V_71 -> V_76 != V_84 ||
V_71 -> V_85 != 0 ) {
V_72 = - V_90 ;
goto V_40;
}
for ( V_26 = 0 ; V_26 < F_51 ( V_91 ) ; V_26 ++ ) {
memset ( V_71 , 0 , sizeof( struct V_71 ) ) ;
V_71 -> V_76 =
V_92 ;
V_71 -> V_53 = V_78 ;
V_71 -> V_93 . V_94 =
V_91 [ V_26 ] . V_95 ;
V_71 -> V_93 . V_96 = 0 ;
V_72 = F_48 ( V_15 -> V_75 , V_71 ,
( sizeof( struct V_71 ) -
V_80 ) ,
( unsigned long ) V_70 ,
V_81 ,
V_82 ) ;
if ( V_72 != 0 )
goto V_40;
V_73 = F_49 ( & V_70 -> F_20 , 5 * V_83 ) ;
if ( V_73 == 0 ) {
V_72 = - V_89 ;
goto V_40;
}
if ( V_71 -> V_76 != V_84 ) {
V_72 = - V_90 ;
goto V_40;
}
if ( V_71 -> V_85 == 0 ) {
V_97 =
V_91 [ V_26 ] . V_95 ;
V_98 =
V_91 [ V_26 ] . V_98 ;
V_80 =
V_91 [ V_26 ] . V_80 ;
break;
}
}
if ( V_71 -> V_85 != 0 ) {
V_72 = - V_90 ;
goto V_40;
}
memset ( V_71 , 0 , sizeof( struct V_71 ) ) ;
V_71 -> V_76 = V_99 ;
V_71 -> V_53 = V_78 ;
V_72 = F_48 ( V_15 -> V_75 , V_71 ,
( sizeof( struct V_71 ) -
V_80 ) ,
( unsigned long ) V_70 ,
V_81 ,
V_82 ) ;
if ( V_72 != 0 )
goto V_40;
V_73 = F_49 ( & V_70 -> F_20 , 5 * V_83 ) ;
if ( V_73 == 0 ) {
V_72 = - V_89 ;
goto V_40;
}
if ( V_71 -> V_76 != V_84 ||
V_71 -> V_85 != 0 ) {
V_72 = - V_90 ;
goto V_40;
}
V_66 = V_71 -> V_100 . V_101 ;
if ( V_97 >= V_102 ) {
if ( V_71 -> V_100 . V_53 &
V_103 )
V_86 = true ;
}
V_16 -> V_104 =
V_71 -> V_100 . V_104 ;
memset ( V_71 , 0 , sizeof( struct V_71 ) ) ;
V_71 -> V_76 = V_105 ;
V_71 -> V_53 = V_78 ;
V_72 = F_48 ( V_15 -> V_75 , V_71 ,
( sizeof( struct V_71 ) -
V_80 ) ,
( unsigned long ) V_70 ,
V_81 ,
V_82 ) ;
if ( V_72 != 0 )
goto V_40;
V_73 = F_49 ( & V_70 -> F_20 , 5 * V_83 ) ;
if ( V_73 == 0 ) {
V_72 = - V_89 ;
goto V_40;
}
if ( V_71 -> V_76 != V_84 ||
V_71 -> V_85 != 0 ) {
V_72 = - V_90 ;
goto V_40;
}
if ( V_86 )
F_43 ( V_15 , V_66 ) ;
V_40:
return V_72 ;
}
static void F_52 ( struct V_106 * V_107 ,
struct V_108 * V_109 ,
struct V_11 * V_8 ,
T_2 V_110 , T_2 V_111 )
{
struct V_3 * V_4 ;
void (* F_53)( struct V_1 * V_2 );
bool V_112 = false ;
switch ( V_107 -> V_113 ) {
case V_114 :
switch ( V_109 -> V_115 [ 0 ] ) {
case V_116 :
case V_117 :
F_54 ( V_109 , V_118 ) ;
break;
case V_119 :
break;
default:
F_54 ( V_109 , V_120 ) ;
}
break;
case V_121 :
V_112 = true ;
F_53 = F_13 ;
break;
case ( V_122 | V_123 ) :
if ( ( V_110 == 0x2a ) && ( V_111 == 0x9 ) ) {
V_112 = true ;
F_53 = F_1 ;
F_54 ( V_109 , V_124 ) ;
}
break;
}
if ( ! V_112 )
return;
V_4 = F_55 ( sizeof( struct V_3 ) , V_39 ) ;
if ( ! V_4 ) {
F_54 ( V_109 , V_120 ) ;
return;
}
V_4 -> V_8 = V_8 ;
V_4 -> V_5 = V_107 -> V_5 ;
F_56 ( & V_4 -> V_2 , F_53 ) ;
F_57 ( & V_4 -> V_2 ) ;
}
static void F_58 ( struct V_69 * V_125 )
{
struct V_108 * V_109 = V_125 -> V_126 ;
struct V_127 * V_128 = F_59 ( V_109 -> V_15 -> V_8 ) ;
struct V_129 V_130 ;
struct V_106 * V_107 ;
struct V_11 * V_8 ;
struct V_13 * V_131 ;
struct V_14 * V_18 = V_128 -> V_18 ;
T_3 V_132 = V_125 -> V_132 ;
void * V_133 = V_125 -> V_133 ;
V_131 = F_22 ( V_18 ) ;
V_8 = V_131 -> V_8 ;
V_107 = & V_125 -> V_71 . V_107 ;
if ( V_125 -> V_43 ) {
if ( V_107 -> V_134 == V_135 )
F_33 ( F_60 ( V_109 ) ,
V_125 -> V_35 ,
F_61 ( V_109 ) ,
V_125 -> V_43 ) ;
F_23 ( V_125 -> V_35 ,
V_125 -> V_43 ) ;
}
V_109 -> V_136 = V_107 -> V_137 ;
if ( V_109 -> V_136 ) {
if ( F_62 ( V_109 -> V_138 ,
V_139 , & V_130 ) )
F_63 ( V_109 -> V_15 , L_1 ,
& V_130 ) ;
}
if ( V_107 -> V_113 != V_140 )
F_52 ( V_107 , V_109 , V_8 , V_130 . V_110 ,
V_130 . V_111 ) ;
F_64 ( V_109 ,
V_125 -> V_133 -> V_141 . V_32 -
V_107 -> V_142 ) ;
V_109 -> V_143 ( V_109 ) ;
if ( V_132 >
sizeof( struct V_144 ) )
F_6 ( V_133 ) ;
}
static void F_65 ( struct V_14 * V_15 ,
struct V_71 * V_71 ,
struct V_69 * V_70 )
{
struct V_13 * V_16 ;
struct V_71 * V_145 ;
V_16 = F_18 ( V_15 ) ;
V_145 = & V_70 -> V_71 ;
if ( ( V_145 -> V_107 . V_146 [ 0 ] == V_147 ) ||
( V_145 -> V_107 . V_146 [ 0 ] == V_148 ) ) {
V_71 -> V_107 . V_137 = 0 ;
V_71 -> V_107 . V_113 = V_140 ;
}
V_145 -> V_107 . V_137 = V_71 -> V_107 . V_137 ;
V_145 -> V_107 . V_113 = V_71 -> V_107 . V_113 ;
V_145 -> V_107 . V_149 =
V_71 -> V_107 . V_149 ;
if ( ( V_71 -> V_107 . V_137 & 0xFF ) == 0x02 ) {
if ( V_71 -> V_107 . V_113 &
V_123 ) {
memcpy ( V_70 -> V_126 -> V_138 ,
V_71 -> V_107 . V_150 ,
V_71 -> V_107 . V_149 ) ;
}
}
V_145 -> V_107 . V_142 =
V_71 -> V_107 . V_142 ;
F_58 ( V_70 ) ;
if ( F_66 ( & V_16 -> V_21 ) &&
V_16 -> V_19 )
F_67 ( & V_16 -> V_20 ) ;
}
static void F_68 ( struct V_14 * V_15 ,
struct V_71 * V_71 ,
struct V_69 * V_70 )
{
struct V_3 * V_2 ;
struct V_13 * V_16 ;
switch ( V_71 -> V_76 ) {
case V_84 :
F_65 ( V_15 , V_71 , V_70 ) ;
break;
case V_151 :
case V_152 :
V_16 = F_22 ( V_15 ) ;
V_2 = F_55 ( sizeof( struct V_3 ) , V_39 ) ;
if ( ! V_2 )
return;
F_56 ( & V_2 -> V_2 , F_7 ) ;
V_2 -> V_8 = V_16 -> V_8 ;
F_57 ( & V_2 -> V_2 ) ;
break;
default:
break;
}
}
static void V_65 ( void * V_153 )
{
struct V_57 * V_75 = (struct V_57 * ) V_153 ;
struct V_14 * V_15 ;
struct V_13 * V_16 ;
T_3 V_154 ;
T_4 V_155 ;
unsigned char V_156 [ F_28 ( sizeof( struct V_71 ) , 8 ) ] ;
struct V_69 * V_70 ;
int V_72 ;
if ( V_75 -> V_59 != NULL )
V_15 = V_75 -> V_59 -> V_60 ;
else
V_15 = V_75 -> V_60 ;
V_16 = F_22 ( V_15 ) ;
if ( ! V_16 )
return;
do {
V_72 = F_69 ( V_75 , V_156 ,
F_28 ( ( sizeof( struct V_71 ) -
V_80 ) , 8 ) ,
& V_154 , & V_155 ) ;
if ( V_72 == 0 && V_154 > 0 ) {
V_70 = (struct V_69 * )
( unsigned long ) V_155 ;
if ( ( V_70 == & V_16 -> V_74 ) ||
( V_70 == & V_16 -> V_157 ) ) {
memcpy ( & V_70 -> V_71 , V_156 ,
( sizeof( struct V_71 ) -
V_80 ) ) ;
F_70 ( & V_70 -> F_20 ) ;
} else {
F_68 ( V_15 ,
(struct V_71 * ) V_156 ,
V_70 ) ;
}
} else {
break;
}
} while ( 1 );
return;
}
static int F_71 ( struct V_14 * V_15 , T_3 V_158 )
{
struct V_61 V_62 ;
int V_72 ;
memset ( & V_62 , 0 , sizeof( struct V_61 ) ) ;
V_72 = F_42 ( V_15 -> V_75 ,
V_158 ,
V_158 ,
( void * ) & V_62 ,
sizeof( struct V_61 ) ,
V_65 , V_15 -> V_75 ) ;
if ( V_72 != 0 )
return V_72 ;
V_72 = F_50 ( V_15 ) ;
return V_72 ;
}
static int F_72 ( struct V_14 * V_15 )
{
struct V_13 * V_16 ;
unsigned long V_53 ;
V_16 = F_18 ( V_15 ) ;
F_73 ( & V_15 -> V_75 -> V_159 , V_53 ) ;
V_16 -> V_17 = true ;
F_74 ( & V_15 -> V_75 -> V_159 , V_53 ) ;
F_19 ( V_16 ) ;
F_73 ( & V_15 -> V_75 -> V_159 , V_53 ) ;
F_75 ( V_15 , NULL ) ;
F_74 ( & V_15 -> V_75 -> V_159 , V_53 ) ;
F_76 ( V_15 -> V_75 ) ;
F_6 ( V_16 ) ;
return 0 ;
}
static int F_77 ( struct V_14 * V_15 ,
struct V_69 * V_70 )
{
struct V_13 * V_16 ;
struct V_71 * V_71 ;
struct V_57 * V_160 ;
int V_72 = 0 ;
V_71 = & V_70 -> V_71 ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 )
return - V_87 ;
V_70 -> V_15 = V_15 ;
V_160 = F_78 ( V_15 -> V_75 ) ;
V_71 -> V_53 |= V_78 ;
V_71 -> V_107 . V_30 = ( sizeof( struct V_106 ) -
V_80 ) ;
V_71 -> V_107 . V_149 = V_98 ;
V_71 -> V_107 . V_142 =
V_70 -> V_133 -> V_141 . V_32 ;
V_71 -> V_76 = V_161 ;
if ( V_70 -> V_133 -> V_141 . V_32 ) {
V_72 = F_79 ( V_160 ,
V_70 -> V_133 , V_70 -> V_132 ,
V_71 ,
( sizeof( struct V_71 ) -
V_80 ) ,
( unsigned long ) V_70 ) ;
} else {
V_72 = F_48 ( V_160 , V_71 ,
( sizeof( struct V_71 ) -
V_80 ) ,
( unsigned long ) V_70 ,
V_81 ,
V_82 ) ;
}
if ( V_72 != 0 )
return V_72 ;
F_80 ( & V_16 -> V_21 ) ;
return V_72 ;
}
static int F_81 ( struct V_6 * V_162 )
{
F_82 ( V_162 -> V_163 , V_31 ) ;
F_83 ( V_162 -> V_163 , V_164 ) ;
F_84 ( V_162 -> V_163 , ( V_165 * V_83 ) ) ;
V_162 -> V_166 = 1 ;
V_162 -> V_167 |= V_168 ;
if ( ! strncmp ( V_162 -> V_169 , L_2 , 4 ) ) {
switch ( V_97 ) {
case V_102 :
case V_170 :
V_162 -> V_171 = V_172 ;
break;
}
if ( V_97 >= V_173 )
V_162 -> V_166 = 0 ;
}
return 0 ;
}
static int F_85 ( struct V_6 * V_7 , struct V_174 * V_175 ,
T_5 V_176 , int * V_177 )
{
T_5 V_178 = V_176 ;
T_5 V_179 = V_178 ;
int V_180 , V_181 ;
V_180 = 0xff ;
V_181 = 0x3f ;
F_86 ( V_179 , V_180 * V_181 ) ;
if ( ( T_5 ) ( V_179 + 1 ) * V_180 * V_181 < V_178 )
V_179 = 0xffff ;
V_177 [ 0 ] = V_180 ;
V_177 [ 1 ] = V_181 ;
V_177 [ 2 ] = ( int ) V_179 ;
return 0 ;
}
static int F_87 ( struct V_108 * V_109 )
{
struct V_127 * V_128 = F_59 ( V_109 -> V_15 -> V_8 ) ;
struct V_14 * V_15 = V_128 -> V_18 ;
struct V_13 * V_16 ;
struct V_69 * V_70 ;
struct V_71 * V_71 ;
int V_72 , V_73 ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 )
return V_182 ;
V_70 = & V_16 -> V_157 ;
V_71 = & V_70 -> V_71 ;
F_47 ( & V_70 -> F_20 ) ;
V_71 -> V_76 = V_183 ;
V_71 -> V_53 = V_78 ;
V_71 -> V_107 . V_184 = V_16 -> V_184 ;
V_72 = F_48 ( V_15 -> V_75 , V_71 ,
( sizeof( struct V_71 ) -
V_80 ) ,
( unsigned long ) & V_16 -> V_157 ,
V_81 ,
V_82 ) ;
if ( V_72 != 0 )
return V_182 ;
V_73 = F_49 ( & V_70 -> F_20 , 5 * V_83 ) ;
if ( V_73 == 0 )
return V_185 ;
F_19 ( V_16 ) ;
return V_186 ;
}
static enum V_187 F_88 ( struct V_108 * V_109 )
{
return V_188 ;
}
static bool F_89 ( struct V_108 * V_109 )
{
bool V_189 = true ;
T_2 V_190 = V_109 -> V_115 [ 0 ] ;
switch ( V_190 ) {
case V_191 :
case V_192 :
V_109 -> V_136 = V_193 << 16 ;
V_189 = false ;
break;
default:
break;
}
return V_189 ;
}
static int F_90 ( struct V_11 * V_8 , struct V_108 * V_109 )
{
int V_72 ;
struct V_127 * V_128 = F_59 ( V_8 ) ;
struct V_14 * V_18 = V_128 -> V_18 ;
struct V_69 * V_125 = F_91 ( V_109 ) ;
int V_26 ;
struct V_23 * V_24 ;
unsigned int V_25 = 0 ;
struct V_106 * V_107 ;
struct V_23 * V_194 ;
struct V_195 * V_133 ;
T_3 V_132 ;
T_3 V_30 ;
if ( V_97 <= V_102 ) {
if ( ! F_89 ( V_109 ) ) {
V_109 -> V_143 ( V_109 ) ;
return 0 ;
}
}
V_125 -> V_126 = V_109 ;
V_107 = & V_125 -> V_71 . V_107 ;
V_107 -> V_196 . V_197 = 60 ;
V_107 -> V_196 . V_198 |=
( V_199 |
V_200 ) ;
switch ( V_109 -> V_201 ) {
case V_202 :
V_107 -> V_134 = V_37 ;
V_107 -> V_196 . V_198 |= V_203 ;
break;
case V_204 :
V_107 -> V_134 = V_135 ;
V_107 -> V_196 . V_198 |= V_205 ;
break;
case V_206 :
V_107 -> V_134 = V_207 ;
V_107 -> V_196 . V_198 |= V_208 ;
break;
default:
F_92 ( 1 , L_3 ,
V_109 -> V_201 ) ;
return - V_90 ;
}
V_107 -> V_209 = V_128 -> V_210 ;
V_107 -> V_184 = V_109 -> V_15 -> V_75 ;
V_107 -> V_211 = V_109 -> V_15 -> V_212 ;
V_107 -> V_5 = V_109 -> V_15 -> V_5 ;
V_107 -> V_213 = V_109 -> V_214 ;
memcpy ( V_107 -> V_146 , V_109 -> V_115 , V_107 -> V_213 ) ;
V_24 = (struct V_23 * ) F_60 ( V_109 ) ;
V_25 = F_61 ( V_109 ) ;
V_30 = F_93 ( V_109 ) ;
V_133 = (struct V_195 * ) & V_125 -> V_215 ;
V_132 = sizeof( V_125 -> V_215 ) ;
if ( V_25 ) {
if ( F_26 ( V_24 , F_61 ( V_109 ) ) != - 1 ) {
V_125 -> V_35 =
F_27 ( V_24 , V_25 ,
V_30 ,
V_107 -> V_134 ) ;
if ( ! V_125 -> V_35 )
return V_216 ;
V_125 -> V_43 =
F_28 ( V_30 , V_31 ) >> V_38 ;
if ( V_107 -> V_134 == V_37 )
F_40 ( V_24 ,
V_125 -> V_35 , V_25 ) ;
V_24 = V_125 -> V_35 ;
V_25 = V_125 -> V_43 ;
}
if ( V_25 > V_217 ) {
V_132 = ( V_25 * sizeof( void * ) +
sizeof( struct V_195 ) ) ;
V_133 = F_55 ( V_132 , V_39 ) ;
if ( ! V_133 ) {
if ( V_125 -> V_43 )
F_23 (
V_125 -> V_35 ,
V_125 -> V_43 ) ;
return V_218 ;
}
}
V_133 -> V_141 . V_32 = V_30 ;
V_133 -> V_141 . V_29 = V_24 [ 0 ] . V_29 ;
V_194 = V_24 ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
V_133 -> V_141 . V_219 [ V_26 ] =
F_94 ( F_24 ( ( V_194 ) ) ) ;
V_194 = F_39 ( V_194 ) ;
}
} else if ( F_60 ( V_109 ) ) {
V_133 -> V_141 . V_32 = V_30 ;
V_133 -> V_141 . V_29 =
F_95 ( F_60 ( V_109 ) ) & ( V_31 - 1 ) ;
V_133 -> V_141 . V_219 [ 0 ] =
F_95 ( F_60 ( V_109 ) ) >> V_38 ;
}
V_125 -> V_133 = V_133 ;
V_125 -> V_132 = V_132 ;
V_72 = F_77 ( V_18 , V_125 ) ;
if ( V_72 == - V_220 ) {
if ( V_125 -> V_43 )
F_23 ( V_125 -> V_35 ,
V_125 -> V_43 ) ;
return V_218 ;
}
return 0 ;
}
static int F_96 ( struct V_14 * V_15 ,
const struct V_221 * V_222 )
{
int V_72 ;
int V_67 = F_44 () ;
struct V_11 * V_8 ;
struct V_127 * V_128 ;
bool V_223 = ( ( V_222 -> V_224 == V_225 ) ? true : false ) ;
int V_226 = 0 ;
struct V_13 * V_16 ;
int V_227 ;
int V_228 ;
int V_229 ;
int V_230 = 0 ;
if ( V_231 < V_232 ) {
V_227 = V_233 ;
V_228 = V_234 ;
V_229 = V_235 ;
} else {
V_227 = V_236 ;
V_228 = V_237 ;
V_229 = V_238 ;
V_230 = ( V_67 / V_239 ) ;
}
V_240 . V_241 = ( V_242 *
( V_230 + 1 ) ) ;
V_8 = F_97 ( & V_240 ,
sizeof( struct V_127 ) ) ;
if ( ! V_8 )
return - V_243 ;
V_128 = F_59 ( V_8 ) ;
memset ( V_128 , 0 , sizeof( struct V_127 ) ) ;
V_128 -> V_210 = V_8 -> V_244 ;
V_128 -> V_18 = V_15 ;
V_16 = F_98 ( sizeof( struct V_13 ) , V_245 ) ;
if ( ! V_16 ) {
V_72 = - V_243 ;
goto V_246;
}
V_16 -> V_17 = false ;
V_16 -> V_63 = false ;
F_99 ( & V_16 -> V_20 ) ;
V_16 -> V_15 = V_15 ;
V_16 -> V_8 = V_8 ;
F_75 ( V_15 , V_16 ) ;
V_16 -> V_209 = V_8 -> V_244 ;
V_72 = F_71 ( V_15 , V_64 ) ;
if ( V_72 )
goto V_247;
V_128 -> V_248 = V_16 -> V_184 ;
V_128 -> V_226 = V_16 -> V_211 ;
switch ( V_222 -> V_224 ) {
case V_249 :
V_8 -> V_250 = V_251 ;
V_8 -> V_252 = V_253 ;
V_8 -> V_254 = V_255 - 1 ;
break;
case V_256 :
V_8 -> V_250 = V_227 ;
V_8 -> V_252 = V_228 ;
V_8 -> V_254 = V_229 - 1 ;
break;
default:
V_8 -> V_250 = V_233 ;
V_8 -> V_252 = V_234 ;
V_8 -> V_254 = V_235 - 1 ;
break;
}
V_8 -> V_257 = V_258 ;
V_8 -> V_259 = ( V_16 -> V_104 >> V_38 ) ;
V_72 = F_100 ( V_8 , & V_15 -> V_15 ) ;
if ( V_72 != 0 )
goto V_260;
if ( ! V_223 ) {
F_12 ( V_8 ) ;
} else {
V_226 = ( V_15 -> V_261 . V_262 [ 5 ] << 8 |
V_15 -> V_261 . V_262 [ 4 ] ) ;
V_72 = F_101 ( V_8 , 0 , V_226 , 0 ) ;
if ( V_72 ) {
F_102 ( V_8 ) ;
goto V_260;
}
}
return 0 ;
V_260:
F_72 ( V_15 ) ;
goto V_246;
V_247:
F_6 ( V_16 ) ;
V_246:
F_16 ( V_8 ) ;
return V_72 ;
}
static int F_103 ( struct V_14 * V_18 )
{
struct V_13 * V_16 = F_18 ( V_18 ) ;
struct V_11 * V_8 = V_16 -> V_8 ;
F_102 ( V_8 ) ;
F_72 ( V_18 ) ;
F_16 ( V_8 ) ;
return 0 ;
}
static int T_6 F_104 ( void )
{
V_242 =
( ( V_64 - V_31 ) /
F_28 ( V_263 +
sizeof( struct V_71 ) + sizeof( T_4 ) -
V_80 ,
sizeof( T_4 ) ) ) ;
return F_105 ( & V_264 ) ;
}
static void T_7 F_106 ( void )
{
F_107 ( & V_264 ) ;
}
