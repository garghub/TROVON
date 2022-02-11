static int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_2 -> V_4 ;
}
static int F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= V_2 -> V_4 )
return V_2 -> V_3 - V_2 -> V_4 ;
return V_2 -> V_5 - ( V_2 -> V_4 - V_2 -> V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_6 = V_2 -> V_5 - F_2 ( V_2 ) - 1 ;
if ( F_4 ( V_6 < 0 ) ) {
return 0 ;
}
return V_6 ;
}
static inline void F_5 ( struct V_7 * V_8 )
{
V_8 -> V_9 [ 7 ] = 0xbb ;
}
static inline void F_6 ( struct V_7 * V_8 )
{
V_8 -> V_9 [ 7 ] = 0xaa ;
}
static inline void F_7 ( struct V_7 * V_8 )
{
V_8 -> V_9 [ 6 ] = 0xcc ;
}
static inline void F_8 ( struct V_7 * V_8 )
{
V_8 -> V_9 [ 6 ] = 0xff ;
}
static inline void F_9 ( struct V_7 * V_8 )
{
V_8 -> V_10 = F_10 ( 0 ) ;
}
static inline T_1 F_11 ( const T_2 * V_11 , T_3 V_12 , T_1 V_13 )
{
return F_12 ( V_13 , V_11 , V_12 ) ;
}
static void F_13 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
int V_16 ;
struct V_7 * V_8 ;
unsigned long V_17 ;
struct V_18 * V_18 = V_15 -> V_18 ;
F_14 ( & V_15 -> V_19 , V_17 ) ;
F_15 ( & V_18 -> V_20 ,
L_1 ,
V_15 -> V_21 , V_2 -> V_4 , V_2 -> V_3 ) ;
V_8 = V_2 -> V_22 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ ) {
F_16 ( & V_18 -> V_20 ,
L_2 ,
V_16 == V_2 -> V_4 ? '>' : ' ' ,
V_16 ,
F_17 ( V_8 -> V_23 ) ,
F_17 ( V_8 -> V_24 ) ,
V_8 -> V_25 ,
V_8 -> V_26 ,
F_18 ( V_8 -> V_10 ) ,
V_8 -> V_27 ) ;
V_8 ++ ;
}
F_19 ( & V_15 -> V_19 , V_17 ) ;
}
struct V_28 * F_20 ( void )
{
struct V_29 * V_30 ;
V_30 = F_21 ( sizeof( * V_30 ) , V_31 ) ;
if ( ! V_30 )
return NULL ;
return & V_30 -> V_27 ;
}
void F_22 ( struct V_28 * V_27 )
{
struct V_29 * V_30 = F_23 ( V_27 , struct V_29 , V_27 ) ;
F_24 ( V_30 ) ;
}
static inline enum V_32 F_25 ( struct V_29 * V_30 )
{
return V_30 -> V_33 ;
}
static inline void F_26 ( struct V_29 * V_30 ,
enum V_32 V_34 )
{
V_30 -> V_33 = V_34 ;
}
static inline int F_27 ( struct V_29 * V_30 )
{
return V_30 -> V_27 . V_35 != 0x0 ;
}
static int F_28 ( struct V_14 * V_15 , struct V_29 * V_30 )
{
return ( F_25 ( V_30 ) == V_36 ) ||
( V_15 -> V_37 != V_38 ) ;
}
static int F_29 ( struct V_14 * V_15 , struct V_1 * V_2 ,
struct V_7 * V_8 , int V_39 )
{
unsigned int V_40 ;
int V_41 ;
struct V_7 * V_42 ;
T_4 V_43 , V_44 , V_45 ;
T_5 V_46 ;
F_9 ( V_8 ) ;
V_41 = ( V_39 == 0 ) ? V_2 -> V_5 - 1 : V_39 - 1 ;
V_42 = & V_2 -> V_22 [ V_41 ] ;
F_6 ( V_8 ) ;
for ( V_40 = 0 ; V_40 < 2 ; V_40 ++ ) {
V_43 = V_42 -> V_47 ;
if ( ( V_43 & V_48 ) != 0x00000000 )
break;
V_44 = ( V_43 | V_49 ) ;
F_30 () ;
V_45 = F_31 ( & V_42 -> V_47 , V_43 , V_44 ) ;
if ( V_45 == V_43 )
return V_50 ;
}
F_5 ( V_8 ) ;
V_46 = ( T_5 ) V_39 << 8 ;
F_30 () ;
F_32 ( V_15 , V_2 -> V_51 , V_46 ) ;
return V_52 ;
}
static void F_33 ( struct V_29 * V_30 , int V_39 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_7 * V_8 = & V_2 -> V_22 [ V_30 -> V_46 ] ;
memcpy ( & V_30 -> V_27 . V_53 [ 0 ] , & V_8 -> V_53 [ 0 ] , V_54 ) ;
V_30 -> V_27 . V_55 = F_17 ( V_8 -> V_56 ) ;
V_30 -> V_27 . V_57 = F_18 ( V_8 -> V_58 ) ;
V_30 -> V_27 . V_59 = F_18 ( V_8 -> V_60 ) ;
V_30 -> V_27 . V_61 = F_17 ( V_8 -> V_62 ) ;
V_30 -> V_27 . V_63 = F_34 ( V_8 -> V_64 ) ;
V_30 -> V_27 . V_65 = F_17 ( V_8 -> V_23 ) ;
if ( F_27 ( V_30 ) ) {
int V_41 = ( V_39 == 0 ) ?
V_2 -> V_5 - 1 : V_39 - 1 ;
struct V_7 * V_66 = & V_2 -> V_22 [ V_41 ] ;
memcpy ( & V_30 -> V_67 . V_68 , V_8 ,
sizeof( V_30 -> V_67 . V_68 ) ) ;
memcpy ( & V_30 -> V_67 . V_69 , V_66 ,
sizeof( V_30 -> V_67 . V_69 ) ) ;
}
}
static int F_35 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
unsigned long V_17 ;
int V_70 = 0 ;
struct V_18 * V_18 = V_15 -> V_18 ;
F_14 ( & V_2 -> V_71 , V_17 ) ;
while ( ! F_1 ( V_2 ) && ( V_70 < V_2 -> V_5 ) ) {
struct V_7 * V_8 ;
struct V_29 * V_30 ;
T_1 V_55 , V_56 , V_23 ;
V_8 = & V_2 -> V_22 [ V_2 -> V_4 ] ;
if ( ( V_8 -> V_47 & V_48 ) ==
0x00000000 )
goto V_72;
F_30 () ;
V_30 = V_2 -> V_73 [ V_2 -> V_4 ] ;
if ( V_30 == NULL ) {
goto V_74;
}
V_23 = F_17 ( V_8 -> V_23 ) ;
if ( ( V_8 -> V_25 == 0x44 ) && ( V_23 <= 0x101 ) ) {
T_5 V_75 , V_76 ;
T_5 V_77 = ( T_5 ) V_8 - ( T_5 ) V_2 -> V_22 ;
V_75 = F_36 ( V_15 , V_2 -> V_78 ) ;
V_76 = F_36 ( V_15 , V_2 -> V_79 ) ;
F_16 ( & V_18 -> V_20 ,
L_3 ,
V_80 , F_17 ( V_8 -> V_24 ) ,
V_8 -> V_25 , V_23 , V_75 , V_76 ,
V_2 -> V_81 + V_77 ) ;
}
F_33 ( V_30 , V_2 -> V_4 ) ;
V_2 -> V_73 [ V_2 -> V_4 ] = NULL ;
F_37 ( & V_18 -> V_20 , L_4 , V_30 -> V_46 ) ;
F_38 ( V_18 , V_8 , sizeof( * V_8 ) ) ;
F_8 ( V_8 ) ;
V_55 = F_11 ( V_8 -> V_53 ,
F_39 ( V_30 -> V_27 . V_82 ) ,
0xffff ) ;
V_56 = F_17 ( V_8 -> V_56 ) ;
if ( V_55 != V_56 ) {
F_40 ( V_83
L_5 ,
V_84 , F_41 ( & V_18 -> V_20 ) ,
V_8 -> V_85 , F_39 ( V_30 -> V_27 . V_82 ) ,
V_55 , V_56 ) ;
}
F_26 ( V_30 , V_36 ) ;
V_2 -> V_86 ++ ;
V_2 -> V_87 -- ;
F_42 ( & V_2 -> V_88 [ V_2 -> V_4 ] ) ;
F_42 ( & V_2 -> V_89 ) ;
V_74:
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) % V_2 -> V_5 ;
V_70 ++ ;
}
V_72:
F_19 ( & V_2 -> V_71 , V_17 ) ;
return V_70 ;
}
int F_43 ( struct V_14 * V_15 , struct V_29 * V_30 )
{
int V_90 ;
unsigned int V_39 ;
struct V_1 * V_2 ;
struct V_18 * V_18 = V_15 -> V_18 ;
if ( V_30 == NULL )
return - V_91 ;
V_2 = V_30 -> V_2 ;
if ( V_2 == NULL )
return - V_91 ;
V_39 = V_30 -> V_46 ;
if ( V_39 >= V_2 -> V_5 )
return - V_91 ;
V_90 = F_44 ( V_2 -> V_88 [ V_39 ] ,
F_28 ( V_15 , V_30 ) ,
V_92 * V_93 ) ;
if ( V_90 == 0 ) {
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_7 * V_8 ;
F_35 ( V_15 , V_30 -> V_2 ) ;
if ( F_28 ( V_15 , V_30 ) )
return V_90 ;
F_16 ( & V_18 -> V_20 ,
L_6 ,
V_80 , V_30 -> V_46 , V_90 , F_25 ( V_30 ) ,
V_30 ) ;
F_16 ( & V_18 -> V_20 ,
L_7 , V_80 ,
F_36 ( V_15 , V_2 -> V_79 ) ) ;
V_8 = & V_2 -> V_22 [ V_30 -> V_46 ] ;
F_38 ( V_18 , V_8 , sizeof( * V_8 ) ) ;
F_13 ( V_15 , V_30 -> V_2 ) ;
return - V_94 ;
} else if ( V_90 == - V_95 ) {
return V_90 ;
} else if ( V_90 < 0 ) {
F_16 ( & V_18 -> V_20 ,
L_8 ,
V_80 , V_30 -> V_46 , V_90 , F_25 ( V_30 ) ) ;
return - V_91 ;
}
if ( V_15 -> V_37 != V_38 ) {
F_16 ( & V_18 -> V_20 ,
L_9 ,
V_80 , V_30 -> V_46 , V_90 ) ;
return - V_96 ;
}
return V_90 ;
}
static struct V_7 * F_45 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
int * V_46 )
{
T_5 * V_97 ;
struct V_7 * V_8 ;
if ( F_3 ( V_2 ) == 0 )
return NULL ;
V_8 = & V_2 -> V_22 [ V_2 -> V_3 ] ;
if ( ( V_8 -> V_47 & V_48 ) == 0x00000000 )
return NULL ;
* V_46 = V_2 -> V_3 ;
V_2 -> V_3 = ( V_2 -> V_3 + 1 ) % V_2 -> V_5 ;
V_97 = ( T_5 * ) V_8 ;
V_97 [ 0 ] = 0ULL ;
V_97 [ 1 ] = 0ULL ;
V_97 [ 0x80 / 8 ] = 0ULL ;
V_97 [ 0x88 / 8 ] = 0ULL ;
V_97 [ 0x90 / 8 ] = 0ULL ;
V_97 [ 0x98 / 8 ] = 0ULL ;
V_97 [ 0xd0 / 8 ] = 0ULL ;
V_8 -> V_85 = V_98 ;
V_8 -> V_24 = F_46 ( V_2 -> V_99 ++ ) ;
return V_8 ;
}
int F_47 ( struct V_14 * V_15 , struct V_29 * V_30 )
{
struct V_7 * V_8 = NULL ;
unsigned int V_100 ;
unsigned long V_17 ;
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_18 * V_18 = V_15 -> V_18 ;
T_5 V_101 ;
T_4 V_45 = 0x0000 ;
T_4 V_43 , V_44 ;
if ( V_92 <= 0 ) {
F_16 ( & V_18 -> V_20 ,
L_10 , V_80 ) ;
return - V_102 ;
}
V_8 = & V_2 -> V_22 [ V_30 -> V_46 ] ;
for ( V_100 = 0 ; V_100 < V_92 * 10 ; V_100 ++ ) {
F_14 ( & V_2 -> V_71 , V_17 ) ;
if ( F_25 ( V_30 ) == V_36 )
goto V_72;
V_43 = V_8 -> V_47 ;
if ( ( V_43 & V_103 ) == 0x00000000 ) {
V_44 = ( V_43 | V_104 ) ;
V_45 = F_31 ( & V_8 -> V_47 ,
V_43 , V_44 ) ;
if ( V_45 == V_43 )
goto V_105;
}
F_48 () ;
V_45 = V_8 -> V_47 ;
if ( V_45 & V_48 )
goto V_105;
F_19 ( & V_2 -> V_71 , V_17 ) ;
F_33 ( V_30 , V_30 -> V_46 ) ;
F_49 ( 100 ) ;
continue;
V_105:
F_33 ( V_30 , V_30 -> V_46 ) ;
F_26 ( V_30 , V_36 ) ;
V_2 -> V_87 -- ;
V_2 -> V_73 [ V_30 -> V_46 ] = NULL ;
F_7 ( V_8 ) ;
V_45 = V_8 -> V_47 ;
if ( ( V_45 & V_48 ) &&
( V_2 -> V_4 == V_30 -> V_46 ) ) {
V_2 -> V_4 = ( ( V_2 -> V_4 + 1 ) %
V_2 -> V_5 ) ;
}
V_72:
F_19 ( & V_2 -> V_71 , V_17 ) ;
return 0 ;
}
V_101 = F_36 ( V_15 , V_2 -> V_79 ) ;
F_37 ( & V_18 -> V_20 , L_11 , V_30 -> V_46 ) ;
F_38 ( V_18 , V_8 , sizeof( * V_8 ) ) ;
F_16 ( & V_18 -> V_20 ,
L_12 ,
V_80 , V_30 -> V_46 , V_92 ,
V_101 ) ;
F_13 ( V_15 , V_30 -> V_2 ) ;
return - V_102 ;
}
int F_50 ( struct V_14 * V_15 , struct V_106 * V_107 )
{
int V_12 ;
struct V_18 * V_18 = V_15 -> V_18 ;
if ( V_107 == NULL ) {
F_16 ( & V_18 -> V_20 ,
L_13 ,
V_80 ) ;
return - V_102 ;
}
V_12 = sizeof( V_107 -> V_108 ) ;
snprintf ( V_107 -> V_108 , V_12 , L_14 , V_109 ) ;
V_107 -> V_110 = V_15 -> V_110 ;
V_107 -> V_111 = V_15 -> V_111 ;
return 0 ;
}
int F_51 ( struct V_14 * V_15 , struct V_29 * V_30 ,
unsigned int V_112 )
{
struct V_7 * V_8 ;
unsigned long V_17 ;
struct V_1 * V_2 ;
struct V_18 * V_18 = V_15 -> V_18 ;
T_1 V_113 ;
V_114:
if ( V_15 -> V_37 != V_38 ) {
F_40 ( V_83
L_15 ,
V_84 , F_41 ( & V_18 -> V_20 ) ,
V_80 , V_30 -> V_46 ) ;
return - V_96 ;
}
V_2 = V_30 -> V_2 = & V_15 -> V_2 ;
if ( V_115 )
F_35 ( V_15 , V_2 ) ;
F_14 ( & V_2 -> V_71 , V_17 ) ;
V_8 = F_45 ( V_15 , V_2 , & V_30 -> V_46 ) ;
if ( V_8 == NULL ) {
int V_90 ;
F_19 ( & V_2 -> V_71 , V_17 ) ;
if ( V_112 & V_116 ) {
V_2 -> V_117 ++ ;
return - V_118 ;
}
V_2 -> V_119 ++ ;
V_90 = F_52 ( V_2 -> V_89 ,
F_3 ( V_2 ) != 0 ) ;
F_37 ( & V_18 -> V_20 , L_16 ,
V_80 , V_90 ) ;
if ( V_90 == - V_95 )
return V_90 ;
goto V_114;
}
if ( V_2 -> V_73 [ V_30 -> V_46 ] != NULL ) {
F_19 ( & V_2 -> V_71 , V_17 ) ;
F_16 ( & V_18 -> V_20 ,
L_17 ,
V_80 , V_30 -> V_46 , V_30 ) ;
return - V_102 ;
}
F_26 ( V_30 , V_120 ) ;
V_2 -> V_73 [ V_30 -> V_46 ] = V_30 ;
V_8 -> V_121 = F_46 ( V_30 -> V_27 . V_122 ) ;
V_8 -> V_27 = V_30 -> V_27 . V_27 ;
V_8 -> V_123 = V_30 -> V_27 . V_123 ;
if ( ( V_15 -> V_110 & 0xFFFF0ull ) > 0x34199ull )
V_8 -> V_124 = 0x1 ;
else
V_8 -> V_124 = 0x0 ;
V_8 -> V_125 = ( ( ( V_30 -> V_27 . V_126 / 8 ) << 4 ) |
( ( V_30 -> V_27 . V_82 / 8 ) ) ) ;
V_8 -> V_127 = F_10 ( V_30 -> V_27 . V_128 ) ;
if ( F_53 ( V_15 ) <= 0x2 ) {
memcpy ( & V_8 -> V_129 [ 0 ] ,
& V_30 -> V_27 . V_129 [ 0 ] ,
V_130 ) ;
} else {
V_8 -> V_131 . V_132 = F_10 ( V_30 -> V_27 . V_133 ) ;
memcpy ( & V_8 -> V_131 . V_134 [ 0 ] ,
& V_30 -> V_27 . V_134 [ 0 ] ,
V_135 ) ;
}
V_8 -> V_47 = F_54 ( 0x00000000 ) ;
V_113 = F_11 ( ( const T_2 * ) V_8 ,
F_55 ( V_30 -> V_27 . V_126 ) , 0xffff ) ;
V_8 -> V_47 = F_54 ( ( V_136 ) V_113 << 16 ) ;
if ( ! V_115 )
V_8 -> V_47 |= V_137 ;
F_37 ( & V_18 -> V_20 , L_18 , V_30 -> V_46 ) ;
F_38 ( V_18 , V_8 , sizeof( * V_8 ) ) ;
if ( F_27 ( V_30 ) ) {
F_50 ( V_15 , & V_30 -> V_67 ) ;
memcpy ( & V_30 -> V_67 . V_138 , V_8 ,
sizeof( V_30 -> V_67 . V_138 ) ) ;
}
F_29 ( V_15 , V_2 , V_8 , V_30 -> V_46 ) ;
V_2 -> V_87 ++ ;
if ( V_2 -> V_87 > V_2 -> V_139 )
V_2 -> V_139 = V_2 -> V_87 ;
F_26 ( V_30 , V_140 ) ;
F_19 ( & V_2 -> V_71 , V_17 ) ;
F_42 ( & V_15 -> V_141 ) ;
return 0 ;
}
int F_56 ( struct V_14 * V_15 ,
struct V_28 * V_27 ,
unsigned int V_112 )
{
int V_90 = 0 ;
struct V_18 * V_18 = V_15 -> V_18 ;
struct V_29 * V_30 = F_23 ( V_27 , struct V_29 , V_27 ) ;
if ( V_27 -> V_126 > V_130 ) {
F_16 ( & V_18 -> V_20 , L_19 ,
V_80 , V_27 -> V_126 ) ;
return - V_91 ;
}
if ( V_27 -> V_82 > V_54 ) {
F_16 ( & V_18 -> V_20 , L_20 ,
V_80 , V_27 -> V_126 ) ;
return - V_91 ;
}
V_90 = F_51 ( V_15 , V_30 , V_112 ) ;
if ( V_90 != 0 )
return V_90 ;
V_90 = F_43 ( V_15 , V_30 ) ;
if ( V_90 < 0 )
goto V_142;
if ( F_27 ( V_30 ) ) {
if ( F_57 ( (struct V_106 V_143 * )
( unsigned long ) V_27 -> V_35 ,
& V_30 -> V_67 ,
sizeof( struct V_106 ) ) )
return - V_102 ;
}
if ( V_27 -> V_65 != V_144 ) {
V_90 = - V_145 ;
}
return V_90 ;
V_142:
F_47 ( V_15 , V_30 ) ;
if ( F_27 ( V_30 ) ) {
if ( F_57 ( (struct V_106 V_143 * )
( unsigned long ) V_27 -> V_35 ,
& V_30 -> V_67 ,
sizeof( struct V_106 ) ) )
return - V_102 ;
}
return V_90 ;
}
static int F_58 ( struct V_14 * V_15 )
{
unsigned long V_17 ;
struct V_7 * V_8 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
F_14 ( & V_2 -> V_71 , V_17 ) ;
if ( F_1 ( V_2 ) ) {
F_19 ( & V_2 -> V_71 , V_17 ) ;
return 0 ;
}
V_8 = & V_2 -> V_22 [ V_2 -> V_4 ] ;
if ( V_8 -> V_47 & V_48 ) {
F_19 ( & V_2 -> V_71 , V_17 ) ;
return 1 ;
}
F_19 ( & V_2 -> V_71 , V_17 ) ;
return 0 ;
}
int F_59 ( struct V_14 * V_15 )
{
unsigned long V_17 ;
int V_87 = 0 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
F_14 ( & V_2 -> V_71 , V_17 ) ;
V_87 += V_2 -> V_87 ;
F_19 ( & V_2 -> V_71 , V_17 ) ;
return V_87 ;
}
static int F_60 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
int V_90 , V_16 ;
struct V_7 * V_8 ;
T_5 V_146 ;
unsigned int V_147 ;
struct V_18 * V_18 = V_15 -> V_18 ;
if ( V_148 < 2 )
return - V_91 ;
V_147 = F_61 ( V_148 * sizeof( struct V_7 ) , V_149 ) ;
V_2 -> V_87 = 0 ;
V_2 -> V_139 = 0 ;
V_2 -> V_86 = 0 ;
V_2 -> V_117 = 0 ;
V_2 -> V_119 = 0 ;
V_2 -> V_99 = 0x100 ;
V_2 -> V_5 = V_148 ;
V_2 -> V_22 = F_62 ( V_15 , V_147 ,
& V_2 -> V_81 ) ;
if ( V_2 -> V_22 == NULL ) {
F_16 ( & V_18 -> V_20 ,
L_21 , V_80 ) ;
return - V_150 ;
}
V_2 -> V_73 = F_21 ( sizeof( struct V_29 * ) *
V_2 -> V_5 , V_31 ) ;
if ( ! V_2 -> V_73 ) {
V_90 = - V_150 ;
goto V_6;
}
V_2 -> V_88 = F_21 ( sizeof( V_151 ) *
V_2 -> V_5 , V_31 ) ;
if ( ! V_2 -> V_88 ) {
V_90 = - V_150 ;
goto V_152;
}
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ ) {
V_8 = & V_2 -> V_22 [ V_16 ] ;
V_8 -> V_47 = V_48 ;
V_8 -> V_23 = F_46 ( 0xfff ) ;
V_2 -> V_73 [ V_16 ] = NULL ;
F_63 ( & V_2 -> V_88 [ V_16 ] ) ;
}
V_2 -> V_4 = 0 ;
V_2 -> V_3 = 0 ;
F_64 ( & V_2 -> V_71 ) ;
F_63 ( & V_2 -> V_89 ) ;
V_146 = ( ( T_5 ) ( V_2 -> V_5 - 1 ) << 8 ) ;
F_32 ( V_15 , V_2 -> V_153 , 0x07 ) ;
F_32 ( V_15 , V_2 -> V_154 , V_2 -> V_81 ) ;
F_32 ( V_15 , V_2 -> V_155 , V_2 -> V_99 ) ;
F_32 ( V_15 , V_2 -> V_156 , V_146 ) ;
return 0 ;
V_152:
F_24 ( V_2 -> V_73 ) ;
V_2 -> V_73 = NULL ;
V_6:
F_65 ( V_15 , V_147 , V_2 -> V_22 ,
V_2 -> V_81 ) ;
V_2 -> V_22 = NULL ;
V_2 -> V_81 = 0ull ;
return - V_157 ;
}
static int F_66 ( struct V_1 * V_2 )
{
return V_2 -> V_22 != NULL ;
}
static void F_67 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
unsigned int V_147 ;
V_147 = F_61 ( V_2 -> V_5 * sizeof( struct V_7 ) , V_149 ) ;
F_24 ( V_2 -> V_73 ) ;
V_2 -> V_73 = NULL ;
if ( V_2 -> V_22 ) {
F_65 ( V_15 , V_147 , V_2 -> V_22 ,
V_2 -> V_81 ) ;
V_2 -> V_22 = NULL ;
V_2 -> V_81 = 0ull ;
}
}
static T_6 F_68 ( int V_158 , void * V_159 )
{
T_5 V_160 ;
struct V_14 * V_15 = (struct V_14 * ) V_159 ;
struct V_18 * V_18 = V_15 -> V_18 ;
V_15 -> V_161 ++ ;
F_42 ( & V_15 -> V_141 ) ;
V_160 = F_36 ( V_15 , V_162 ) ;
if ( ( ( V_160 & V_163 ) != 0x0 ) &&
! F_69 ( V_18 ) ) {
if ( V_15 -> V_164 ) {
F_70 ( V_15 -> V_165 + V_162 ) ;
if ( F_69 ( V_18 ) )
goto exit;
}
F_42 ( & V_15 -> V_166 ) ;
F_71 ( & V_18 -> V_20 ,
L_22 ,
V_80 , V_160 ) ;
}
exit:
return V_167 ;
}
static T_6 F_72 ( int V_158 , void * V_159 )
{
struct V_14 * V_15 = (struct V_14 * ) V_159 ;
V_15 -> V_161 ++ ;
F_42 ( & V_15 -> V_141 ) ;
return V_167 ;
}
static int F_73 ( void * V_168 )
{
int V_169 = 0 , V_90 = 0 ;
struct V_14 * V_15 = (struct V_14 * ) V_168 ;
while ( ! F_74 () ) {
F_35 ( V_15 , & V_15 -> V_2 ) ;
if ( V_115 ) {
V_90 = F_44 (
V_15 -> V_141 ,
F_59 ( V_15 ) ||
( V_169 = F_74 () ) , 1 ) ;
} else {
V_90 = F_44 (
V_15 -> V_141 ,
F_58 ( V_15 ) ||
( V_169 = F_74 () ) , V_93 ) ;
}
if ( V_169 )
break;
F_75 () ;
}
return 0 ;
}
int F_76 ( struct V_14 * V_15 )
{
int V_90 ;
struct V_1 * V_2 ;
struct V_18 * V_18 = V_15 -> V_18 ;
if ( F_77 ( V_15 ) ) {
V_90 = F_78 ( V_15 ) ;
if ( V_90 < 0 ) {
F_16 ( & V_18 -> V_20 ,
L_23 , V_80 ) ;
return V_90 ;
}
F_79 ( V_15 ) ;
}
V_2 = & V_15 -> V_2 ;
V_2 -> V_153 = V_170 ;
V_2 -> V_79 = V_171 ;
V_2 -> V_154 = V_172 ;
V_2 -> V_155 = V_173 ;
V_2 -> V_51 = V_174 ;
V_2 -> V_156 = V_175 ;
V_2 -> V_176 = V_177 ;
V_2 -> V_78 = V_178 ;
V_2 -> V_179 = V_180 ;
V_90 = F_60 ( V_15 , V_2 ) ;
if ( V_90 != 0 ) {
V_90 = - V_157 ;
goto V_181;
}
F_63 ( & V_15 -> V_141 ) ;
V_15 -> V_182 = F_80 ( F_73 , V_15 ,
V_84 L_24 ,
V_15 -> V_21 ) ;
if ( F_81 ( V_15 -> V_182 ) ) {
V_90 = F_82 ( V_15 -> V_182 ) ;
V_15 -> V_182 = NULL ;
goto V_183;
}
V_90 = F_83 ( V_15 , V_184 ) ;
if ( V_90 )
goto V_185;
F_63 ( & V_15 -> V_166 ) ;
if ( F_77 ( V_15 ) ) {
V_90 = F_84 ( V_18 -> V_158 , F_68 , V_186 ,
V_84 , V_15 ) ;
} else {
V_90 = F_84 ( V_18 -> V_158 , F_72 , V_186 ,
V_84 , V_15 ) ;
}
if ( V_90 < 0 ) {
F_16 ( & V_18 -> V_20 , L_25 , V_18 -> V_158 ) ;
goto V_187;
}
V_15 -> V_37 = V_38 ;
return 0 ;
V_187:
F_85 ( V_15 ) ;
V_185:
F_86 ( V_15 -> V_182 ) ;
V_15 -> V_182 = NULL ;
V_183:
F_67 ( V_15 , V_2 ) ;
V_181:
return V_90 ;
}
static int F_87 ( struct V_14 * V_15 )
{
unsigned int V_16 ;
unsigned long V_17 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
F_14 ( & V_2 -> V_71 , V_17 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ )
F_42 ( & V_2 -> V_88 [ V_2 -> V_4 ] ) ;
F_42 ( & V_2 -> V_89 ) ;
F_19 ( & V_2 -> V_71 , V_17 ) ;
return 0 ;
}
int F_88 ( struct V_14 * V_15 )
{
int V_16 , V_90 = 0 , V_188 ;
int V_189 = V_92 ;
struct V_18 * V_18 = V_15 -> V_18 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
if ( ! F_66 ( V_2 ) )
return 0 ;
if ( V_15 -> V_37 == V_38 )
V_15 -> V_37 = V_190 ;
F_87 ( V_15 ) ;
for ( V_16 = 0 ; V_16 < V_189 ; V_16 ++ ) {
V_188 = F_59 ( V_15 ) ;
if ( V_188 == 0 )
break;
F_37 ( & V_18 -> V_20 ,
L_26 ,
V_16 , V_189 , V_188 ) ;
F_49 ( 1000 ) ;
}
if ( V_16 == V_189 ) {
F_16 ( & V_18 -> V_20 , L_27 ,
V_80 ) ;
V_90 = - V_96 ;
}
return V_90 ;
}
int F_89 ( struct V_14 * V_15 )
{
struct V_18 * V_18 = V_15 -> V_18 ;
if ( ! F_66 ( & V_15 -> V_2 ) )
return 1 ;
F_90 ( V_18 -> V_158 , V_15 ) ;
F_85 ( V_15 ) ;
if ( V_15 -> V_182 != NULL ) {
F_86 ( V_15 -> V_182 ) ;
V_15 -> V_182 = NULL ;
}
F_67 ( V_15 , & V_15 -> V_2 ) ;
return 0 ;
}
