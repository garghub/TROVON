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
L_2
L_3 ,
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
L_4
L_5
L_6 ,
V_80 , F_17 ( V_8 -> V_24 ) ,
V_8 -> V_25 , V_23 , V_75 , V_76 ,
V_2 -> V_81 + V_77 ) ;
}
F_33 ( V_30 , V_2 -> V_4 ) ;
V_2 -> V_73 [ V_2 -> V_4 ] = NULL ;
F_37 ( & V_18 -> V_20 , L_7 , V_30 -> V_46 ) ;
F_38 ( V_18 , V_8 , sizeof( * V_8 ) ) ;
F_8 ( V_8 ) ;
V_55 = F_11 ( V_8 -> V_53 ,
F_39 ( V_30 -> V_27 . V_82 ) ,
0xffff ) ;
V_56 = F_17 ( V_8 -> V_56 ) ;
if ( V_55 != V_56 ) {
F_40 ( V_83
L_8
L_9 ,
V_84 , F_41 ( & V_18 -> V_20 ) ,
V_8 -> V_85 , F_39 ( V_30 -> V_27 . V_82 ) ,
V_55 , V_56 ) ;
}
F_26 ( V_30 , V_36 ) ;
V_2 -> V_86 ++ ;
V_2 -> V_87 -- ;
F_42 ( & V_2 -> V_88 [ V_2 -> V_4 ] ) ;
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
int V_89 ;
unsigned int V_39 ;
struct V_1 * V_2 ;
struct V_18 * V_18 = V_15 -> V_18 ;
if ( V_30 == NULL )
return - V_90 ;
V_2 = V_30 -> V_2 ;
if ( V_2 == NULL )
return - V_90 ;
V_39 = V_30 -> V_46 ;
if ( V_39 >= V_2 -> V_5 )
return - V_90 ;
V_89 = F_44 ( V_2 -> V_88 [ V_39 ] ,
F_28 ( V_15 , V_30 ) ,
V_91 * V_92 ) ;
if ( V_89 == 0 ) {
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_7 * V_8 ;
F_35 ( V_15 , V_30 -> V_2 ) ;
if ( F_28 ( V_15 , V_30 ) )
return V_89 ;
F_16 ( & V_18 -> V_20 ,
L_10 ,
V_80 , V_30 -> V_46 , V_89 , F_25 ( V_30 ) ,
V_30 ) ;
F_16 ( & V_18 -> V_20 ,
L_11 , V_80 ,
F_36 ( V_15 , V_2 -> V_79 ) ) ;
V_8 = & V_2 -> V_22 [ V_30 -> V_46 ] ;
F_38 ( V_18 , V_8 , sizeof( * V_8 ) ) ;
F_13 ( V_15 , V_30 -> V_2 ) ;
return - V_93 ;
} else if ( V_89 == - V_94 ) {
return V_89 ;
} else if ( V_89 < 0 ) {
F_16 ( & V_18 -> V_20 ,
L_12 ,
V_80 , V_30 -> V_46 , V_89 , F_25 ( V_30 ) ) ;
return - V_90 ;
}
if ( V_15 -> V_37 != V_38 ) {
F_16 ( & V_18 -> V_20 ,
L_13 ,
V_80 , V_30 -> V_46 , V_89 ) ;
return - V_95 ;
}
return V_89 ;
}
static struct V_7 * F_45 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
int * V_46 )
{
T_5 * V_96 ;
struct V_7 * V_8 ;
if ( F_3 ( V_2 ) == 0 )
return NULL ;
V_8 = & V_2 -> V_22 [ V_2 -> V_3 ] ;
if ( ( V_8 -> V_47 & V_48 ) == 0x00000000 )
return NULL ;
* V_46 = V_2 -> V_3 ;
V_2 -> V_3 = ( V_2 -> V_3 + 1 ) % V_2 -> V_5 ;
V_96 = ( T_5 * ) V_8 ;
V_96 [ 0 ] = 0ULL ;
V_96 [ 1 ] = 0ULL ;
V_96 [ 0x80 / 8 ] = 0ULL ;
V_96 [ 0x88 / 8 ] = 0ULL ;
V_96 [ 0x90 / 8 ] = 0ULL ;
V_96 [ 0x98 / 8 ] = 0ULL ;
V_96 [ 0xd0 / 8 ] = 0ULL ;
V_8 -> V_85 = V_97 ;
V_8 -> V_24 = F_46 ( V_2 -> V_98 ++ ) ;
return V_8 ;
}
int F_47 ( struct V_14 * V_15 , struct V_29 * V_30 )
{
struct V_7 * V_8 = NULL ;
unsigned int V_99 ;
unsigned long V_17 ;
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_18 * V_18 = V_15 -> V_18 ;
T_5 V_100 ;
T_4 V_45 = 0x0000 ;
T_4 V_43 , V_44 ;
if ( V_91 <= 0 ) {
F_16 ( & V_18 -> V_20 ,
L_14 , V_80 ) ;
return - V_101 ;
}
V_8 = & V_2 -> V_22 [ V_30 -> V_46 ] ;
for ( V_99 = 0 ; V_99 < V_91 * 10 ; V_99 ++ ) {
F_14 ( & V_2 -> V_71 , V_17 ) ;
if ( F_25 ( V_30 ) == V_36 )
goto V_72;
V_43 = V_8 -> V_47 ;
if ( ( V_43 & V_102 ) == 0x00000000 ) {
V_44 = ( V_43 | V_103 ) ;
V_45 = F_31 ( & V_8 -> V_47 ,
V_43 , V_44 ) ;
if ( V_45 == V_43 )
goto V_104;
}
F_48 () ;
V_45 = V_8 -> V_47 ;
if ( V_45 & V_48 )
goto V_104;
F_19 ( & V_2 -> V_71 , V_17 ) ;
F_33 ( V_30 , V_30 -> V_46 ) ;
F_49 ( 100 ) ;
continue;
V_104:
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
V_100 = F_36 ( V_15 , V_2 -> V_79 ) ;
F_37 ( & V_18 -> V_20 , L_15 , V_30 -> V_46 ) ;
F_38 ( V_18 , V_8 , sizeof( * V_8 ) ) ;
F_16 ( & V_18 -> V_20 ,
L_16
L_17 ,
V_80 , V_30 -> V_46 , V_91 ,
V_100 ) ;
F_13 ( V_15 , V_30 -> V_2 ) ;
return - V_101 ;
}
int F_50 ( struct V_14 * V_15 , struct V_105 * V_106 )
{
int V_12 ;
struct V_18 * V_18 = V_15 -> V_18 ;
if ( V_106 == NULL ) {
F_16 ( & V_18 -> V_20 ,
L_18 ,
V_80 ) ;
return - V_101 ;
}
V_12 = sizeof( V_106 -> V_107 ) ;
snprintf ( V_106 -> V_107 , V_12 , L_19 , V_108 ) ;
V_106 -> V_109 = V_15 -> V_109 ;
V_106 -> V_110 = V_15 -> V_110 ;
return 0 ;
}
int F_51 ( struct V_14 * V_15 , struct V_29 * V_30 )
{
struct V_7 * V_8 ;
unsigned long V_17 ;
struct V_1 * V_2 ;
struct V_18 * V_18 = V_15 -> V_18 ;
T_1 V_111 ;
if ( V_15 -> V_37 != V_38 ) {
F_40 ( V_83
L_20 ,
V_84 , F_41 ( & V_18 -> V_20 ) ,
V_80 , V_30 -> V_46 ) ;
return - V_95 ;
}
V_2 = V_30 -> V_2 = & V_15 -> V_2 ;
if ( V_112 )
F_35 ( V_15 , V_2 ) ;
F_14 ( & V_2 -> V_71 , V_17 ) ;
V_8 = F_45 ( V_15 , V_2 , & V_30 -> V_46 ) ;
if ( V_8 == NULL ) {
F_19 ( & V_2 -> V_71 , V_17 ) ;
V_2 -> V_113 ++ ;
return - V_114 ;
}
if ( V_2 -> V_73 [ V_30 -> V_46 ] != NULL ) {
F_19 ( & V_2 -> V_71 , V_17 ) ;
F_16 ( & V_18 -> V_20 ,
L_21 ,
V_80 , V_30 -> V_46 , V_30 ) ;
return - V_101 ;
}
F_26 ( V_30 , V_115 ) ;
V_2 -> V_73 [ V_30 -> V_46 ] = V_30 ;
V_8 -> V_116 = F_46 ( V_30 -> V_27 . V_117 ) ;
V_8 -> V_27 = V_30 -> V_27 . V_27 ;
V_8 -> V_118 = V_30 -> V_27 . V_118 ;
if ( ( V_15 -> V_109 & 0xFFFF0ull ) > 0x34199ull )
V_8 -> V_119 = 0x1 ;
else
V_8 -> V_119 = 0x0 ;
V_8 -> V_120 = ( ( ( V_30 -> V_27 . V_121 / 8 ) << 4 ) |
( ( V_30 -> V_27 . V_82 / 8 ) ) ) ;
V_8 -> V_122 = F_10 ( V_30 -> V_27 . V_123 ) ;
if ( F_52 ( V_15 ) <= 0x2 ) {
memcpy ( & V_8 -> V_124 [ 0 ] ,
& V_30 -> V_27 . V_124 [ 0 ] ,
V_125 ) ;
} else {
V_8 -> V_126 . V_127 = F_10 ( V_30 -> V_27 . V_128 ) ;
memcpy ( & V_8 -> V_126 . V_129 [ 0 ] ,
& V_30 -> V_27 . V_129 [ 0 ] ,
V_130 ) ;
}
V_8 -> V_47 = F_53 ( 0x00000000 ) ;
V_111 = F_11 ( ( const T_2 * ) V_8 ,
F_54 ( V_30 -> V_27 . V_121 ) , 0xffff ) ;
V_8 -> V_47 = F_53 ( ( V_131 ) V_111 << 16 ) ;
if ( ! V_112 )
V_8 -> V_47 |= V_132 ;
F_37 ( & V_18 -> V_20 , L_22 , V_30 -> V_46 ) ;
F_38 ( V_18 , V_8 , sizeof( * V_8 ) ) ;
if ( F_27 ( V_30 ) ) {
F_50 ( V_15 , & V_30 -> V_67 ) ;
memcpy ( & V_30 -> V_67 . V_133 , V_8 ,
sizeof( V_30 -> V_67 . V_133 ) ) ;
}
F_29 ( V_15 , V_2 , V_8 , V_30 -> V_46 ) ;
V_2 -> V_87 ++ ;
if ( V_2 -> V_87 > V_2 -> V_134 )
V_2 -> V_134 = V_2 -> V_87 ;
F_26 ( V_30 , V_135 ) ;
F_19 ( & V_2 -> V_71 , V_17 ) ;
F_42 ( & V_15 -> V_136 ) ;
return 0 ;
}
int F_55 ( struct V_14 * V_15 ,
struct V_28 * V_27 )
{
int V_89 = 0 ;
struct V_18 * V_18 = V_15 -> V_18 ;
struct V_29 * V_30 = F_23 ( V_27 , struct V_29 , V_27 ) ;
if ( V_27 -> V_121 > V_125 ) {
F_16 ( & V_18 -> V_20 , L_23 ,
V_80 , V_27 -> V_121 ) ;
return - V_90 ;
}
if ( V_27 -> V_82 > V_54 ) {
F_16 ( & V_18 -> V_20 , L_24 ,
V_80 , V_27 -> V_121 ) ;
return - V_90 ;
}
V_89 = F_51 ( V_15 , V_30 ) ;
if ( V_89 != 0 )
return V_89 ;
V_89 = F_43 ( V_15 , V_30 ) ;
if ( V_89 < 0 )
goto V_137;
if ( F_27 ( V_30 ) ) {
if ( F_56 ( (struct V_105 V_138 * )
( unsigned long ) V_27 -> V_35 ,
& V_30 -> V_67 ,
sizeof( struct V_105 ) ) )
return - V_101 ;
}
if ( V_27 -> V_65 != V_139 ) {
V_89 = - V_140 ;
}
return V_89 ;
V_137:
F_47 ( V_15 , V_30 ) ;
if ( F_27 ( V_30 ) ) {
if ( F_56 ( (struct V_105 V_138 * )
( unsigned long ) V_27 -> V_35 ,
& V_30 -> V_67 ,
sizeof( struct V_105 ) ) )
return - V_101 ;
}
return V_89 ;
}
static int F_57 ( struct V_14 * V_15 )
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
int F_58 ( struct V_14 * V_15 )
{
unsigned long V_17 ;
int V_87 = 0 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
F_14 ( & V_2 -> V_71 , V_17 ) ;
V_87 += V_2 -> V_87 ;
F_19 ( & V_2 -> V_71 , V_17 ) ;
return V_87 ;
}
static int F_59 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
int V_89 , V_16 ;
struct V_7 * V_8 ;
T_5 V_141 ;
unsigned int V_142 ;
struct V_18 * V_18 = V_15 -> V_18 ;
if ( V_143 < 2 )
return - V_90 ;
V_142 = F_60 ( V_143 * sizeof( struct V_7 ) , V_144 ) ;
V_2 -> V_87 = 0 ;
V_2 -> V_134 = 0 ;
V_2 -> V_86 = 0 ;
V_2 -> V_113 = 0 ;
V_2 -> V_98 = 0x100 ;
V_2 -> V_5 = V_143 ;
V_2 -> V_22 = F_61 ( V_15 , V_142 ,
& V_2 -> V_81 ) ;
if ( V_2 -> V_22 == NULL ) {
F_16 ( & V_18 -> V_20 ,
L_25 , V_80 ) ;
return - V_145 ;
}
memset ( V_2 -> V_22 , 0 , V_142 ) ;
V_2 -> V_73 = F_21 ( sizeof( struct V_29 * ) *
V_2 -> V_5 , V_146 ) ;
if ( ! V_2 -> V_73 ) {
V_89 = - V_145 ;
goto V_6;
}
V_2 -> V_88 = F_21 ( sizeof( V_147 ) *
V_2 -> V_5 , V_146 ) ;
if ( ! V_2 -> V_88 ) {
V_89 = - V_145 ;
goto V_148;
}
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ ) {
V_8 = & V_2 -> V_22 [ V_16 ] ;
V_8 -> V_47 = V_48 ;
V_8 -> V_23 = F_46 ( 0xfff ) ;
V_2 -> V_73 [ V_16 ] = NULL ;
F_62 ( & V_2 -> V_88 [ V_16 ] ) ;
}
V_2 -> V_4 = 0 ;
V_2 -> V_3 = 0 ;
F_63 ( & V_2 -> V_71 ) ;
F_62 ( & V_2 -> V_149 ) ;
V_141 = ( ( T_5 ) ( V_2 -> V_5 - 1 ) << 8 ) ;
F_32 ( V_15 , V_2 -> V_150 , 0x07 ) ;
F_32 ( V_15 , V_2 -> V_151 , V_2 -> V_81 ) ;
F_32 ( V_15 , V_2 -> V_152 , V_2 -> V_98 ) ;
F_32 ( V_15 , V_2 -> V_153 , V_141 ) ;
return 0 ;
V_148:
F_24 ( V_2 -> V_73 ) ;
V_2 -> V_73 = NULL ;
V_6:
F_64 ( V_15 , V_142 , V_2 -> V_22 ,
V_2 -> V_81 ) ;
V_2 -> V_22 = NULL ;
V_2 -> V_81 = 0ull ;
return - V_154 ;
}
static int F_65 ( struct V_1 * V_2 )
{
return V_2 -> V_22 != NULL ;
}
static void F_66 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
unsigned int V_142 ;
V_142 = F_60 ( V_2 -> V_5 * sizeof( struct V_7 ) , V_144 ) ;
F_24 ( V_2 -> V_73 ) ;
V_2 -> V_73 = NULL ;
if ( V_2 -> V_22 ) {
F_64 ( V_15 , V_142 , V_2 -> V_22 ,
V_2 -> V_81 ) ;
V_2 -> V_22 = NULL ;
V_2 -> V_81 = 0ull ;
}
}
static T_6 F_67 ( int V_155 , void * V_156 )
{
T_5 V_157 ;
struct V_14 * V_15 = (struct V_14 * ) V_156 ;
struct V_18 * V_18 = V_15 -> V_18 ;
V_15 -> V_158 ++ ;
F_42 ( & V_15 -> V_136 ) ;
V_157 = F_36 ( V_15 , V_159 ) ;
if ( ( ( V_157 & V_160 ) != 0x0 ) &&
! F_68 ( V_18 ) ) {
if ( V_15 -> V_161 ) {
F_69 ( V_15 -> V_162 + V_159 ) ;
if ( F_68 ( V_18 ) )
goto exit;
}
F_42 ( & V_15 -> V_163 ) ;
F_70 ( & V_18 -> V_20 ,
L_26 ,
V_80 , V_157 ) ;
}
exit:
return V_164 ;
}
static T_6 F_71 ( int V_155 , void * V_156 )
{
struct V_14 * V_15 = (struct V_14 * ) V_156 ;
V_15 -> V_158 ++ ;
F_42 ( & V_15 -> V_136 ) ;
return V_164 ;
}
static int F_72 ( void * V_165 )
{
int V_166 = 0 , V_89 = 0 ;
struct V_14 * V_15 = (struct V_14 * ) V_165 ;
while ( ! F_73 () ) {
F_35 ( V_15 , & V_15 -> V_2 ) ;
if ( V_112 ) {
V_89 = F_44 (
V_15 -> V_136 ,
F_58 ( V_15 ) ||
( V_166 = F_73 () ) , 1 ) ;
} else {
V_89 = F_44 (
V_15 -> V_136 ,
F_57 ( V_15 ) ||
( V_166 = F_73 () ) , V_92 ) ;
}
if ( V_166 )
break;
F_74 () ;
}
return 0 ;
}
int F_75 ( struct V_14 * V_15 )
{
int V_89 ;
struct V_1 * V_2 ;
struct V_18 * V_18 = V_15 -> V_18 ;
if ( F_76 ( V_15 ) ) {
V_89 = F_77 ( V_15 ) ;
if ( V_89 < 0 ) {
F_16 ( & V_18 -> V_20 ,
L_27 , V_80 ) ;
return V_89 ;
}
F_78 ( V_15 ) ;
}
V_2 = & V_15 -> V_2 ;
V_2 -> V_150 = V_167 ;
V_2 -> V_79 = V_168 ;
V_2 -> V_151 = V_169 ;
V_2 -> V_152 = V_170 ;
V_2 -> V_51 = V_171 ;
V_2 -> V_153 = V_172 ;
V_2 -> V_173 = V_174 ;
V_2 -> V_78 = V_175 ;
V_2 -> V_176 = V_177 ;
V_89 = F_59 ( V_15 , V_2 ) ;
if ( V_89 != 0 ) {
V_89 = - V_154 ;
goto V_178;
}
F_62 ( & V_15 -> V_136 ) ;
V_15 -> V_179 = F_79 ( F_72 , V_15 ,
V_84 L_28 ,
V_15 -> V_21 ) ;
if ( F_80 ( V_15 -> V_179 ) ) {
V_89 = F_81 ( V_15 -> V_179 ) ;
V_15 -> V_179 = NULL ;
goto V_180;
}
V_89 = F_82 ( V_15 , V_181 ) ;
if ( V_89 ) {
V_89 = - V_154 ;
goto V_182;
}
F_62 ( & V_15 -> V_163 ) ;
if ( F_76 ( V_15 ) ) {
V_89 = F_83 ( V_18 -> V_155 , F_67 , V_183 ,
V_84 , V_15 ) ;
} else {
V_89 = F_83 ( V_18 -> V_155 , F_71 , V_183 ,
V_84 , V_15 ) ;
}
if ( V_89 < 0 ) {
F_16 ( & V_18 -> V_20 , L_29 , V_18 -> V_155 ) ;
goto V_184;
}
V_15 -> V_37 = V_38 ;
return 0 ;
V_184:
F_84 ( V_15 ) ;
V_182:
F_85 ( V_15 -> V_179 ) ;
V_15 -> V_179 = NULL ;
V_180:
F_66 ( V_15 , V_2 ) ;
V_178:
return V_89 ;
}
static int F_86 ( struct V_14 * V_15 )
{
unsigned int V_16 ;
unsigned long V_17 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
F_14 ( & V_2 -> V_71 , V_17 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ )
F_42 ( & V_2 -> V_88 [ V_2 -> V_4 ] ) ;
F_19 ( & V_2 -> V_71 , V_17 ) ;
return 0 ;
}
int F_87 ( struct V_14 * V_15 )
{
int V_16 , V_89 = 0 , V_185 ;
int V_186 = V_91 ;
struct V_18 * V_18 = V_15 -> V_18 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
if ( ! F_65 ( V_2 ) )
return 0 ;
if ( V_15 -> V_37 == V_38 )
V_15 -> V_37 = V_187 ;
F_86 ( V_15 ) ;
for ( V_16 = 0 ; V_16 < V_186 ; V_16 ++ ) {
V_185 = F_58 ( V_15 ) ;
if ( V_185 == 0 )
break;
F_37 ( & V_18 -> V_20 ,
L_30
L_31 , V_16 , V_186 , V_185 ) ;
F_49 ( 1000 ) ;
}
if ( V_16 == V_186 ) {
F_16 ( & V_18 -> V_20 , L_32 ,
V_80 ) ;
V_89 = - V_95 ;
}
return V_89 ;
}
int F_88 ( struct V_14 * V_15 )
{
struct V_18 * V_18 = V_15 -> V_18 ;
if ( ! F_65 ( & V_15 -> V_2 ) )
return 1 ;
F_89 ( V_18 -> V_155 , V_15 ) ;
F_84 ( V_15 ) ;
if ( V_15 -> V_179 != NULL ) {
F_85 ( V_15 -> V_179 ) ;
V_15 -> V_179 = NULL ;
}
F_66 ( V_15 , & V_15 -> V_2 ) ;
return 0 ;
}
