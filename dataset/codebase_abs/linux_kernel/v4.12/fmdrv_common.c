static inline void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 . V_3 [ V_1 -> V_2 . V_4 ] ( V_1 ) ;
}
static inline void F_2 ( struct V_1 * V_1 , T_1 V_4 )
{
V_1 -> V_2 . V_4 = V_4 ;
F_1 ( V_1 ) ;
}
static inline void F_3 ( struct V_1 * V_1 , T_1 V_4 )
{
V_1 -> V_2 . V_4 = V_4 ;
F_4 ( & V_1 -> V_2 . V_5 , V_6 + V_7 ) ;
}
inline void F_5 ( struct V_8 * V_9 )
{
int V_10 , V_11 ;
T_1 V_12 ;
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) V_9 -> V_15 ;
F_6 ( V_16 L_1 ,
F_7 ( V_9 ) -> V_17 ? L_2 : L_3 , V_14 -> V_18 ,
V_14 -> V_10 , V_14 -> V_19 ,
V_14 -> V_20 ? L_4 : L_5 , V_14 -> V_21 ) ;
V_11 = V_9 -> V_10 - V_22 ;
if ( V_11 > 0 ) {
F_6 ( V_23 L_6 , V_14 -> V_21 ) ;
V_10 = F_8 ( V_11 , 14 ) ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ )
F_6 ( V_23 L_7 ,
V_9 -> V_15 [ V_22 + V_12 ] ) ;
F_6 ( V_23 L_8 , ( V_11 > 14 ) ? L_9 : L_10 ) ;
}
F_6 ( V_23 L_11 ) ;
}
inline void F_9 ( struct V_8 * V_9 )
{
int V_10 , V_11 ;
T_1 V_12 ;
struct V_24 * V_25 ;
V_25 = (struct V_24 * ) V_9 -> V_15 ;
F_6 ( V_16 L_12 ,
V_25 -> V_18 , V_25 -> V_10 ,
V_25 -> V_26 , V_25 -> V_27 , V_25 -> V_19 ,
( V_25 -> V_20 ) ? L_4 : L_5 , V_25 -> V_21 ) ;
V_11 = V_9 -> V_10 - V_28 ;
if ( V_11 > 0 ) {
F_6 ( V_23 L_6 , V_25 -> V_21 ) ;
V_10 = F_8 ( V_11 , 14 ) ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ )
F_6 ( V_23 L_7 ,
V_9 -> V_15 [ V_28 + V_12 ] ) ;
F_6 ( V_23 L_8 , ( V_11 > 14 ) ? L_9 : L_10 ) ;
}
F_6 ( V_23 L_11 ) ;
}
void F_10 ( struct V_1 * V_1 , T_1 V_29 )
{
V_1 -> V_30 . V_31 = V_32 [ V_29 ] ;
}
static void F_11 ( unsigned long V_33 )
{
struct V_1 * V_1 ;
struct V_34 * V_2 ;
struct V_24 * V_25 ;
struct V_8 * V_9 ;
T_1 V_27 ;
unsigned long V_35 ;
V_1 = (struct V_1 * ) V_33 ;
V_2 = & V_1 -> V_2 ;
while ( ( V_9 = F_12 ( & V_1 -> V_36 ) ) ) {
if ( V_9 -> V_10 < sizeof( struct V_24 ) ) {
F_13 ( L_13 ,
V_9 ,
V_9 -> V_10 , sizeof( struct V_24 ) ) ;
F_14 ( V_9 ) ;
continue;
}
V_25 = ( void * ) V_9 -> V_15 ;
V_27 = V_25 -> V_27 ;
if ( V_25 -> V_19 == V_37 ) {
if ( ! F_15 ( V_38 , & V_1 -> V_39 ) ) {
F_16 ( V_38 , & V_1 -> V_39 ) ;
if ( V_2 -> V_4 != 0 ) {
F_13 ( L_14 ) ;
V_2 -> V_4 = 0 ;
}
V_2 -> V_3 [ V_2 -> V_4 ] ( V_1 ) ;
} else {
F_16 ( V_40 , & V_1 -> V_39 ) ;
}
F_14 ( V_9 ) ;
}
else if ( V_25 -> V_19 == V_1 -> V_41 && V_1 -> V_42 != NULL ) {
F_17 ( & V_1 -> V_43 , V_35 ) ;
V_1 -> V_44 = V_9 ;
F_18 ( & V_1 -> V_43 , V_35 ) ;
F_19 ( V_1 -> V_42 ) ;
V_1 -> V_42 = NULL ;
F_20 ( & V_1 -> V_45 , 1 ) ;
}
else if ( V_25 -> V_19 == V_1 -> V_41 && V_1 -> V_42 == NULL ) {
if ( V_1 -> V_44 != NULL )
F_13 ( L_15 ) ;
F_17 ( & V_1 -> V_43 , V_35 ) ;
V_1 -> V_44 = V_9 ;
F_18 ( & V_1 -> V_43 , V_35 ) ;
V_2 -> V_3 [ V_2 -> V_4 ] ( V_1 ) ;
F_14 ( V_9 ) ;
F_20 ( & V_1 -> V_45 , 1 ) ;
} else {
F_13 ( L_16 , V_9 ) ;
}
if ( V_27 && F_21 ( & V_1 -> V_45 ) )
if ( ! F_22 ( & V_1 -> V_46 ) )
F_23 ( & V_1 -> V_47 ) ;
}
}
static void F_24 ( unsigned long V_33 )
{
struct V_1 * V_1 ;
struct V_8 * V_9 ;
int V_10 ;
V_1 = (struct V_1 * ) V_33 ;
if ( ! F_21 ( & V_1 -> V_45 ) )
return;
if ( ( V_6 - V_1 -> V_48 ) > V_7 ) {
F_13 ( L_17 ) ;
F_20 ( & V_1 -> V_45 , 1 ) ;
}
V_9 = F_12 ( & V_1 -> V_46 ) ;
if ( ! V_9 )
return;
F_25 ( & V_1 -> V_45 ) ;
V_1 -> V_41 = F_7 ( V_9 ) -> V_49 ;
if ( V_1 -> V_42 != NULL )
F_13 ( L_18 ) ;
V_1 -> V_42 = F_7 ( V_9 ) -> V_17 ;
V_10 = F_26 ( V_9 ) ;
if ( V_10 < 0 ) {
F_14 ( V_9 ) ;
V_1 -> V_42 = NULL ;
F_13 ( L_19 , V_9 ) ;
F_20 ( & V_1 -> V_45 , 1 ) ;
} else {
V_1 -> V_48 = V_6 ;
}
}
static int F_27 ( struct V_1 * V_1 , T_1 V_49 , T_2 type , void * V_50 ,
int V_51 , struct V_17 * V_52 )
{
struct V_8 * V_9 ;
struct V_13 * V_18 ;
int V_53 ;
if ( V_49 >= V_37 ) {
F_13 ( L_20 , V_49 ) ;
return - V_54 ;
}
if ( F_15 ( V_55 , & V_1 -> V_39 ) && V_50 == NULL ) {
F_13 ( L_21 ) ;
return - V_54 ;
}
if ( ! F_15 ( V_55 , & V_1 -> V_39 ) )
V_53 =
V_22 + ( ( V_50 == NULL ) ? 0 : V_51 ) ;
else
V_53 = V_51 ;
V_9 = F_28 ( V_53 , V_56 ) ;
if ( ! V_9 ) {
F_13 ( L_22 ) ;
return - V_57 ;
}
if ( ! F_15 ( V_55 , & V_1 -> V_39 ) ||
F_15 ( V_38 , & V_1 -> V_39 ) ) {
V_18 = (struct V_13 * ) F_29 ( V_9 , V_22 ) ;
V_18 -> V_18 = V_58 ;
V_18 -> V_10 = ( ( V_50 == NULL ) ? 0 : V_51 ) + 3 ;
V_18 -> V_19 = V_49 ;
V_18 -> V_20 = type ;
V_18 -> V_21 = V_51 ;
F_7 ( V_9 ) -> V_49 = V_49 ;
if ( V_50 != NULL )
* ( V_59 * ) V_50 = F_30 ( * ( T_2 * ) V_50 ) ;
} else if ( V_50 != NULL ) {
F_7 ( V_9 ) -> V_49 = * ( ( T_1 * ) V_50 + 2 ) ;
}
if ( V_50 != NULL )
memcpy ( F_29 ( V_9 , V_51 ) , V_50 , V_51 ) ;
F_7 ( V_9 ) -> V_17 = V_52 ;
F_31 ( & V_1 -> V_46 , V_9 ) ;
F_23 ( & V_1 -> V_47 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_1 , T_1 V_49 , T_2 type , void * V_50 ,
unsigned int V_51 , void * V_60 , int * V_61 )
{
struct V_8 * V_9 ;
struct V_24 * V_25 ;
unsigned long V_35 ;
int V_62 ;
F_33 ( & V_1 -> V_63 ) ;
V_62 = F_27 ( V_1 , V_49 , type , V_50 , V_51 ,
& V_1 -> V_63 ) ;
if ( V_62 )
return V_62 ;
if ( ! F_34 ( & V_1 -> V_63 ,
V_7 ) ) {
F_13 ( L_23 ,
F_35 ( V_7 ) / 1000 ) ;
return - V_64 ;
}
if ( ! V_1 -> V_44 ) {
F_13 ( L_24 ) ;
return - V_65 ;
}
F_17 ( & V_1 -> V_43 , V_35 ) ;
V_9 = V_1 -> V_44 ;
V_1 -> V_44 = NULL ;
F_18 ( & V_1 -> V_43 , V_35 ) ;
V_25 = ( void * ) V_9 -> V_15 ;
if ( V_25 -> V_26 != 0 ) {
F_13 ( L_25 ,
V_25 -> V_26 ) ;
F_14 ( V_9 ) ;
return - V_66 ;
}
if ( V_60 != NULL && V_61 != NULL && V_25 -> V_21 ) {
F_36 ( V_9 , sizeof( struct V_24 ) ) ;
memcpy ( V_60 , V_9 -> V_15 , V_25 -> V_21 ) ;
* V_61 = V_25 -> V_21 ;
} else if ( V_61 != NULL && V_25 -> V_21 == 0 ) {
* V_61 = 0 ;
}
F_14 ( V_9 ) ;
return 0 ;
}
static inline int F_37 ( struct V_1 * V_1 ,
struct V_8 * * V_9 )
{
struct V_24 * V_67 ;
unsigned long V_35 ;
F_38 ( & V_1 -> V_2 . V_5 ) ;
F_17 ( & V_1 -> V_43 , V_35 ) ;
* V_9 = V_1 -> V_44 ;
V_1 -> V_44 = NULL ;
F_18 ( & V_1 -> V_43 , V_35 ) ;
V_67 = ( void * ) ( * V_9 ) -> V_15 ;
if ( V_67 -> V_26 != 0 ) {
F_13 ( L_26 ,
V_67 -> V_19 ) ;
F_4 ( & V_1 -> V_2 . V_5 , V_6 + V_7 ) ;
return - 1 ;
}
return 0 ;
}
static inline void F_39 ( struct V_1 * V_1 , T_1 V_4 )
{
struct V_8 * V_9 ;
if ( ! F_37 ( V_1 , & V_9 ) )
F_2 ( V_1 , V_4 ) ;
}
static void F_40 ( unsigned long V_15 )
{
struct V_1 * V_1 ;
struct V_34 * V_68 ;
F_41 ( L_27 ) ;
V_1 = (struct V_1 * ) V_15 ;
V_68 = & V_1 -> V_2 ;
V_68 -> V_69 ++ ;
if ( V_68 -> V_69 > V_70 ) {
V_68 -> V_4 = 0 ;
V_68 -> V_69 = 0 ;
F_13 ( L_28 ) ;
return;
}
F_2 ( V_1 , V_71 ) ;
}
static void F_42 ( struct V_1 * V_1 )
{
T_2 V_39 ;
if ( ! F_27 ( V_1 , V_72 , V_73 , NULL , sizeof( V_39 ) , NULL ) )
F_3 ( V_1 , V_74 ) ;
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
struct V_24 * V_67 ;
if ( F_37 ( V_1 , & V_9 ) )
return;
V_67 = ( void * ) V_9 -> V_15 ;
F_36 ( V_9 , sizeof( struct V_24 ) ) ;
memcpy ( & V_1 -> V_2 . V_39 , V_9 -> V_15 , V_67 -> V_21 ) ;
V_1 -> V_2 . V_39 = F_44 ( ( V_75 V_59 ) V_1 -> V_2 . V_39 ) ;
F_41 ( L_29 , V_1 -> V_2 . V_39 ) ;
F_2 ( V_1 , V_76 ) ;
}
static void F_45 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 . V_39 & V_77 & V_1 -> V_2 . V_78 )
F_13 ( L_30 ) ;
F_2 ( V_1 , V_79 ) ;
}
static void F_46 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 . V_39 & V_80 & V_1 -> V_2 . V_78 ) {
F_41 ( L_31 ) ;
V_1 -> V_2 . V_4 = V_81 ;
} else {
V_1 -> V_2 . V_4 = V_82 ;
}
F_1 ( V_1 ) ;
}
static void F_47 ( struct V_1 * V_1 )
{
if ( ! F_27 ( V_1 , V_83 , V_73 , NULL ,
( V_84 * 3 ) , NULL ) )
F_3 ( V_1 , V_85 ) ;
}
static void F_48 ( struct V_1 * V_1 , T_1 V_86 )
{
struct V_87 * V_88 = & V_1 -> V_30 . V_88 ;
T_1 V_89 = V_1 -> V_30 . V_31 . V_90 ;
T_1 V_12 ;
T_3 V_91 ;
if ( ( V_86 >= V_92 ) && ( V_86 <= V_93 ) ) {
V_1 -> V_30 . V_88 . V_94 = ( V_86 - V_92 + 1 ) ;
V_1 -> V_30 . V_88 . V_95 = 0 ;
F_41 ( L_32 , V_1 -> V_30 . V_88 . V_94 ) ;
return;
}
if ( V_86 < V_96 )
return;
if ( V_89 == V_97 && V_86 > V_98 )
return;
if ( V_89 == V_99 && V_86 > V_100 )
return;
V_91 = V_1 -> V_30 . V_31 . V_101 + ( V_86 * 100 ) ;
if ( V_91 == V_1 -> V_30 . V_91 ) {
F_41 ( L_33 ,
V_1 -> V_30 . V_91 , V_91 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_88 -> V_95 ; V_12 ++ ) {
if ( V_88 -> V_102 [ V_12 ] == V_91 )
break;
}
if ( V_12 == V_88 -> V_94 ) {
F_41 ( L_34 ) ;
return;
}
if ( V_12 == V_88 -> V_95 ) {
F_41 ( L_35 , V_91 , V_12 ) ;
V_88 -> V_102 [ V_12 ] = V_91 ;
V_88 -> V_95 ++ ;
}
}
static void F_49 ( struct V_1 * V_1 ,
struct V_103 * V_104 )
{
T_1 V_12 = 0 ;
T_1 * V_105 ;
if ( V_1 -> V_106 != 0x6350 ) {
V_105 = & V_104 -> V_15 . V_107 . V_108 [ 0 ] ;
while ( V_12 + 1 < V_109 ) {
F_50 ( V_105 [ V_12 ] , V_105 [ V_12 + 1 ] ) ;
V_12 += 2 ;
}
}
}
static void F_51 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
struct V_103 V_110 ;
struct V_111 * V_112 = & V_1 -> V_30 . V_112 ;
unsigned long V_113 , V_35 ;
T_1 * V_114 , V_115 , V_116 [ V_117 ] ;
T_1 type , V_118 ;
T_2 V_119 ;
T_3 V_120 ;
if ( F_37 ( V_1 , & V_9 ) )
return;
F_36 ( V_9 , sizeof( struct V_24 ) ) ;
V_114 = V_9 -> V_15 ;
V_120 = V_9 -> V_10 ;
while ( V_120 >= V_117 ) {
V_115 = V_114 [ 2 ] ;
type = ( V_115 & 0x07 ) ;
V_118 = ( type <= V_121 ? type : ( type - 1 ) ) ;
F_41 ( L_36 , V_118 ,
( V_115 & V_122 ) ? L_37 : L_38 ) ;
if ( ( V_115 & V_122 ) != 0 )
break;
if ( V_118 > V_123 ) {
F_41 ( L_39 ) ;
V_112 -> V_124 = - 1 ;
break;
}
memcpy ( & V_110 . V_15 . V_107 .
V_108 [ V_118 * ( V_117 - 1 ) ] ,
V_114 , ( V_117 - 1 ) ) ;
V_112 -> V_124 = V_118 ;
if ( V_118 == V_123 ) {
F_41 ( L_40 ) ;
F_49 ( V_1 , & V_110 ) ;
V_119 = F_44 ( ( V_75 V_59 ) V_110 . V_15 . V_125 . V_126 ) ;
if ( V_1 -> V_30 . V_88 . V_127 != V_119 )
V_1 -> V_30 . V_88 . V_127 = V_119 ;
F_41 ( L_41 , V_119 ) ;
V_113 = ( V_110 . V_15 . V_125 . V_128 [ 0 ] >> 3 ) ;
F_41 ( L_42 , V_113 / 2 ,
( V_113 % 2 ) ? L_43 : L_44 ) ;
V_113 = 1 << ( V_110 . V_15 . V_125 . V_128 [ 0 ] >> 3 ) ;
if ( V_113 == V_129 ) {
F_48 ( V_1 , V_110 . V_15 . V_130 . V_86 [ 0 ] ) ;
F_48 ( V_1 , V_110 . V_15 . V_130 . V_86 [ 1 ] ) ;
}
}
V_120 -= V_117 ;
V_114 += V_117 ;
}
V_114 = V_9 -> V_15 ;
V_120 = V_9 -> V_10 ;
F_17 ( & V_1 -> V_131 , V_35 ) ;
while ( V_120 > 0 ) {
type = ( V_114 [ 2 ] & 0x07 ) ;
V_118 = ( type <= V_121 ? type : ( type - 1 ) ) ;
V_116 [ 2 ] = V_118 ;
V_116 [ 2 ] |= V_118 << 3 ;
V_116 [ 0 ] = V_114 [ 0 ] ;
V_116 [ 1 ] = V_114 [ 1 ] ;
memcpy ( & V_112 -> V_108 [ V_112 -> V_132 ] , & V_116 , V_117 ) ;
V_112 -> V_132 = ( V_112 -> V_132 + V_117 ) % V_112 -> V_133 ;
if ( V_112 -> V_132 == V_112 -> V_134 ) {
F_41 ( L_45 ) ;
V_112 -> V_132 = 0 ;
V_112 -> V_134 = 0 ;
break;
}
V_120 -= V_117 ;
V_114 += V_117 ;
}
F_18 ( & V_1 -> V_131 , V_35 ) ;
if ( V_112 -> V_132 != V_112 -> V_134 )
F_52 ( & V_112 -> V_135 ) ;
F_2 ( V_1 , V_136 ) ;
}
static void F_53 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_82 ) ;
}
static void F_54 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 . V_39 & ( V_137 | V_138 ) & V_1 ->
V_2 . V_78 ) {
F_41 ( L_46 ) ;
if ( F_55 ( V_139 , & V_1 -> V_39 ) ) {
V_1 -> V_2 . V_4 = V_140 ;
} else {
F_19 ( & V_1 -> V_63 ) ;
V_1 -> V_2 . V_4 = V_141 ;
}
} else
V_1 -> V_2 . V_4 = V_141 ;
F_1 ( V_1 ) ;
}
static void F_56 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 . V_39 & V_142 ) {
F_41 ( L_47 ) ;
F_19 ( & V_1 -> V_63 ) ;
}
F_2 ( V_1 , V_143 ) ;
}
static void F_57 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_30 . V_144 == V_145 ) &&
( V_1 -> V_2 . V_39 & V_146 & V_1 -> V_2 . V_78 ) &&
( V_1 -> V_30 . V_91 != V_147 ) &&
( V_1 -> V_30 . V_88 . V_95 != 0 ) ) {
F_41 ( L_48 ) ;
V_1 -> V_2 . V_78 &= ~ V_146 ;
V_1 -> V_30 . V_148 = 0 ;
V_1 -> V_30 . V_149 = V_1 -> V_30 . V_91 ;
V_1 -> V_2 . V_4 = V_150 ;
} else {
V_1 -> V_2 . V_4 = V_71 ;
}
F_1 ( V_1 ) ;
}
static void F_58 ( struct V_1 * V_1 )
{
T_2 V_50 ;
V_50 = V_1 -> V_30 . V_88 . V_127 ;
if ( ! F_27 ( V_1 , V_151 , V_152 , & V_50 , sizeof( V_50 ) , NULL ) )
F_3 ( V_1 , V_153 ) ;
}
static void F_59 ( struct V_1 * V_1 )
{
F_39 ( V_1 , V_154 ) ;
}
static void F_60 ( struct V_1 * V_1 )
{
T_2 V_50 ;
V_50 = 0x0000 ;
if ( ! F_27 ( V_1 , V_155 , V_152 , & V_50 , sizeof( V_50 ) , NULL ) )
F_3 ( V_1 , V_156 ) ;
}
static void F_61 ( struct V_1 * V_1 )
{
F_39 ( V_1 , V_157 ) ;
}
static void F_62 ( struct V_1 * V_1 )
{
T_2 V_158 ;
T_2 V_50 ;
F_41 ( L_49 , V_1 -> V_30 . V_88 . V_102 [ V_1 -> V_30 . V_148 ] ) ;
V_158 = ( V_1 -> V_30 . V_88 . V_102 [ V_1 -> V_30 . V_148 ] -
V_1 -> V_30 . V_31 . V_101 ) / V_159 ;
V_50 = V_158 ;
if ( ! F_27 ( V_1 , V_160 , V_152 , & V_50 , sizeof( V_50 ) , NULL ) )
F_3 ( V_1 , V_161 ) ;
}
static void F_63 ( struct V_1 * V_1 )
{
F_39 ( V_1 , V_162 ) ;
}
static void F_64 ( struct V_1 * V_1 )
{
T_2 V_50 ;
V_50 = V_137 ;
if ( ! F_27 ( V_1 , V_163 , V_152 , & V_50 , sizeof( V_50 ) , NULL ) )
F_3 ( V_1 , V_164 ) ;
}
static void F_65 ( struct V_1 * V_1 )
{
F_39 ( V_1 , V_165 ) ;
}
static void F_66 ( struct V_1 * V_1 )
{
T_2 V_50 ;
V_50 = V_166 ;
if ( ! F_27 ( V_1 , V_167 , V_152 , & V_50 ,
sizeof( V_50 ) , NULL ) )
F_3 ( V_1 , V_168 ) ;
}
static void F_67 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
if ( F_37 ( V_1 , & V_9 ) )
return;
V_1 -> V_2 . V_4 = V_169 ;
F_16 ( V_139 , & V_1 -> V_39 ) ;
F_68 ( V_38 , & V_1 -> V_39 ) ;
}
static void F_69 ( struct V_1 * V_1 )
{
T_2 V_50 ;
if ( ! F_27 ( V_1 , V_170 , V_73 , NULL , sizeof( V_50 ) , NULL ) )
F_3 ( V_1 , V_171 ) ;
}
static void F_70 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
T_2 V_172 ;
T_3 V_173 , V_174 ;
if ( F_37 ( V_1 , & V_9 ) )
return;
F_36 ( V_9 , sizeof( struct V_24 ) ) ;
memcpy ( & V_172 , V_9 -> V_15 , sizeof( V_172 ) ) ;
V_172 = F_44 ( ( V_75 V_59 ) V_172 ) ;
V_173 = V_1 -> V_30 . V_31 . V_101 + ( ( T_3 ) V_172 * V_159 ) ;
V_174 = V_1 -> V_30 . V_88 . V_102 [ V_1 -> V_30 . V_148 ] ;
if ( ( V_173 != V_1 -> V_30 . V_149 ) && ( V_173 == V_174 ) ) {
F_41 ( L_50 , V_173 ) ;
V_1 -> V_30 . V_91 = V_173 ;
F_71 ( V_1 ) ;
if ( V_1 -> V_30 . V_144 == V_145 )
V_1 -> V_2 . V_78 |= V_146 ;
V_1 -> V_2 . V_4 = V_175 ;
} else {
V_1 -> V_30 . V_148 ++ ;
if ( V_1 -> V_30 . V_148 >= V_1 -> V_30 . V_88 . V_95 ) {
F_41 ( L_51 ) ;
V_1 -> V_2 . V_4 = V_175 ;
} else {
F_41 ( L_52 ) ;
V_1 -> V_2 . V_4 = V_150 ;
}
}
F_1 ( V_1 ) ;
}
static void F_72 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_71 ) ;
}
static void F_73 ( struct V_1 * V_1 )
{
T_2 V_50 ;
V_50 = V_1 -> V_2 . V_78 ;
if ( ! F_27 ( V_1 , V_163 , V_152 , & V_50 ,
sizeof( V_50 ) , NULL ) )
F_3 ( V_1 , V_176 ) ;
}
static void F_74 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
if ( F_37 ( V_1 , & V_9 ) )
return;
V_1 -> V_2 . V_4 = V_169 ;
if ( F_55 ( V_40 , & V_1 -> V_39 ) )
V_1 -> V_2 . V_3 [ V_1 -> V_2 . V_4 ] ( V_1 ) ;
else
F_68 ( V_38 , & V_1 -> V_39 ) ;
}
int F_75 ( struct V_1 * V_1 , struct V_177 * V_177 ,
struct V_178 * V_179 )
{
F_76 ( V_177 , & V_1 -> V_30 . V_112 . V_135 , V_179 ) ;
if ( V_1 -> V_30 . V_112 . V_134 != V_1 -> V_30 . V_112 . V_132 )
return 0 ;
return - V_180 ;
}
int F_77 ( struct V_1 * V_1 , struct V_177 * V_177 ,
T_1 T_4 * V_181 , T_5 V_182 )
{
T_3 V_183 ;
T_1 V_116 [ V_117 ] ;
unsigned long V_35 ;
int V_62 ;
if ( V_1 -> V_30 . V_112 . V_132 == V_1 -> V_30 . V_112 . V_134 ) {
if ( V_177 -> V_184 & V_185 )
return - V_186 ;
V_62 = F_78 ( V_1 -> V_30 . V_112 . V_135 ,
( V_1 -> V_30 . V_112 . V_132 != V_1 -> V_30 . V_112 . V_134 ) ) ;
if ( V_62 )
return - V_187 ;
}
V_182 /= V_117 ;
V_183 = 0 ;
V_62 = 0 ;
while ( V_183 < V_182 ) {
F_17 ( & V_1 -> V_131 , V_35 ) ;
if ( V_1 -> V_30 . V_112 . V_132 == V_1 -> V_30 . V_112 . V_134 ) {
F_18 ( & V_1 -> V_131 , V_35 ) ;
break;
}
memcpy ( V_116 , & V_1 -> V_30 . V_112 . V_108 [ V_1 -> V_30 . V_112 . V_134 ] ,
V_117 ) ;
V_1 -> V_30 . V_112 . V_134 += V_117 ;
if ( V_1 -> V_30 . V_112 . V_134 >= V_1 -> V_30 . V_112 . V_133 )
V_1 -> V_30 . V_112 . V_134 = 0 ;
F_18 ( & V_1 -> V_131 , V_35 ) ;
if ( F_79 ( V_181 , V_116 , V_117 ) )
break;
V_183 ++ ;
V_181 += V_117 ;
V_62 += V_117 ;
}
return V_62 ;
}
int F_80 ( struct V_1 * V_1 , T_3 V_188 )
{
switch ( V_1 -> V_189 ) {
case V_190 :
return F_81 ( V_1 , V_188 ) ;
case V_191 :
return F_82 ( V_1 , V_188 ) ;
default:
return - V_54 ;
}
}
int F_83 ( struct V_1 * V_1 , T_3 * V_192 )
{
if ( V_1 -> V_30 . V_91 == V_147 ) {
F_13 ( L_53 ) ;
return - V_193 ;
}
if ( V_192 == NULL ) {
F_13 ( L_54 ) ;
return - V_57 ;
}
switch ( V_1 -> V_189 ) {
case V_190 :
* V_192 = V_1 -> V_30 . V_91 ;
return 0 ;
case V_191 :
* V_192 = 0 ;
return 0 ;
default:
return - V_54 ;
}
}
int F_84 ( struct V_1 * V_1 , T_1 V_29 )
{
switch ( V_1 -> V_189 ) {
case V_190 :
return F_85 ( V_1 , V_29 ) ;
case V_191 :
return F_86 ( V_1 , V_29 ) ;
default:
return - V_54 ;
}
}
int F_87 ( struct V_1 * V_1 , T_1 V_194 )
{
switch ( V_1 -> V_189 ) {
case V_190 :
return F_88 ( V_1 , V_194 ) ;
case V_191 :
return F_89 ( V_1 , V_194 ) ;
default:
return - V_54 ;
}
}
int F_90 ( struct V_1 * V_1 , T_2 V_195 )
{
switch ( V_1 -> V_189 ) {
case V_190 :
return F_91 ( V_1 , V_195 ) ;
case V_191 :
return F_92 ( V_1 , V_195 ) ;
default:
return - V_54 ;
}
}
int F_93 ( struct V_1 * V_1 , T_1 V_196 )
{
switch ( V_1 -> V_189 ) {
case V_190 :
return F_94 ( V_1 , V_196 ) ;
case V_191 :
return F_95 ( V_1 , V_196 ) ;
default:
return - V_54 ;
}
}
static int F_96 ( struct V_1 * V_1 )
{
T_2 V_50 ;
int V_62 ;
if ( ! F_15 ( V_197 , & V_1 -> V_39 ) ) {
F_13 ( L_55 ) ;
return - V_193 ;
}
if ( V_1 -> V_189 == V_198 ) {
F_41 ( L_56 ) ;
return 0 ;
}
V_50 = 0x0 ;
V_62 = F_32 ( V_1 , V_199 , V_152 , & V_50 ,
sizeof( V_50 ) , NULL , NULL ) ;
if ( V_62 < 0 )
return V_62 ;
return F_97 ( V_1 ) ;
}
static int F_98 ( struct V_1 * V_1 , const T_1 * V_200 )
{
const struct V_201 * V_202 ;
struct V_203 * V_204 ;
struct V_205 * V_206 ;
struct V_207 * V_208 ;
T_1 * V_209 ;
int V_62 , V_210 , V_211 ;
V_211 = 0 ;
F_16 ( V_55 , & V_1 -> V_39 ) ;
V_62 = F_99 ( & V_202 , V_200 ,
& V_1 -> V_212 -> V_213 ) ;
if ( V_62 < 0 ) {
F_13 ( L_57 , V_200 ) ;
return V_62 ;
}
F_41 ( L_58 , V_200 , V_202 -> V_53 ) ;
V_209 = ( void * ) V_202 -> V_15 ;
V_210 = V_202 -> V_53 ;
V_204 = (struct V_203 * ) V_209 ;
if ( V_204 -> V_214 != V_215 ) {
F_13 ( L_59 , V_200 ) ;
V_62 = - V_54 ;
goto V_216;
}
F_41 ( L_60 , V_200 , V_204 -> V_214 ) ;
V_209 += sizeof( struct V_203 ) ;
V_210 -= sizeof( struct V_203 ) ;
while ( V_209 && V_210 > 0 ) {
V_206 = (struct V_205 * ) V_209 ;
switch ( V_206 -> type ) {
case V_217 :
if ( F_32 ( V_1 , 0 , 0 , V_206 -> V_15 ,
V_206 -> V_53 , NULL , NULL ) )
goto V_216;
V_211 ++ ;
break;
case V_218 :
V_208 = (struct V_207 * ) V_206 -> V_15 ;
F_100 ( V_208 -> V_219 ) ;
break;
}
V_209 += ( sizeof( struct V_205 ) + ( V_206 -> V_53 ) ) ;
V_210 -= ( sizeof( struct V_205 ) + ( V_206 -> V_53 ) ) ;
}
F_41 ( L_61 , V_211 ) ;
V_216:
F_101 ( V_202 ) ;
F_68 ( V_55 , & V_1 -> V_39 ) ;
return V_62 ;
}
static int F_102 ( struct V_1 * V_1 )
{
int V_62 ;
V_62 = F_103 ( V_1 , V_220 ) ;
if ( V_62 < 0 )
return V_62 ;
return F_104 ( V_1 , V_221 ) ;
}
static int F_105 ( struct V_1 * V_1 , T_1 V_195 )
{
T_2 V_50 ;
V_59 V_222 , V_223 ;
int V_224 , V_62 ;
T_1 V_200 [ 50 ] ;
if ( V_195 >= V_225 ) {
F_13 ( L_62 ) ;
return - V_54 ;
}
V_62 = F_106 ( V_1 ) ;
if ( V_62 < 0 ) {
F_13 ( L_63 ) ;
return V_62 ;
}
V_50 = V_226 ;
if ( F_32 ( V_1 , V_199 , V_152 , & V_50 ,
sizeof( V_50 ) , NULL , NULL ) )
goto V_227;
F_107 ( 20 ) ;
if ( F_32 ( V_1 , V_228 , V_73 , NULL ,
sizeof( V_222 ) , & V_222 , & V_224 ) )
goto V_227;
if ( F_32 ( V_1 , V_229 , V_73 , NULL ,
sizeof( V_223 ) , & V_223 , & V_224 ) )
goto V_227;
F_41 ( L_64 ,
F_44 ( V_222 ) , F_44 ( V_223 ) ) ;
sprintf ( V_200 , L_65 , V_230 ,
F_44 ( V_222 ) , F_44 ( V_223 ) ) ;
V_62 = F_98 ( V_1 , V_200 ) ;
if ( V_62 < 0 ) {
F_41 ( L_66 , V_200 ) ;
goto V_227;
}
sprintf ( V_200 , L_65 , ( V_195 == V_190 ) ?
V_231 : V_232 ,
F_44 ( V_222 ) , F_44 ( V_223 ) ) ;
V_62 = F_98 ( V_1 , V_200 ) ;
if ( V_62 < 0 ) {
F_41 ( L_66 , V_200 ) ;
goto V_227;
} else
return V_62 ;
V_227:
return F_97 ( V_1 ) ;
}
int F_108 ( struct V_1 * V_1 , T_1 V_233 )
{
int V_62 = 0 ;
if ( V_233 >= V_225 ) {
F_13 ( L_67 ) ;
return - V_54 ;
}
if ( V_1 -> V_189 == V_233 ) {
F_41 ( L_68 , V_233 ) ;
return V_62 ;
}
switch ( V_233 ) {
case V_198 :
V_62 = F_96 ( V_1 ) ;
if ( V_62 < 0 ) {
F_13 ( L_69 ) ;
return V_62 ;
}
break;
case V_191 :
case V_190 :
if ( V_1 -> V_189 != V_198 ) {
V_62 = F_96 ( V_1 ) ;
if ( V_62 < 0 ) {
F_13 ( L_69 ) ;
return V_62 ;
}
F_107 ( 30 ) ;
}
V_62 = F_105 ( V_1 , V_233 ) ;
if ( V_62 < 0 ) {
F_13 ( L_70 ) ;
return V_62 ;
}
}
V_1 -> V_189 = V_233 ;
if ( V_1 -> V_189 == V_190 ) {
F_41 ( L_71 ) ;
V_62 = F_102 ( V_1 ) ;
if ( V_62 < 0 )
F_13 ( L_72 ) ;
}
return V_62 ;
}
int F_109 ( struct V_1 * V_1 , T_1 * V_234 )
{
if ( ! F_15 ( V_197 , & V_1 -> V_39 ) ) {
F_13 ( L_55 ) ;
return - V_193 ;
}
if ( V_234 == NULL ) {
F_13 ( L_54 ) ;
return - V_57 ;
}
* V_234 = V_1 -> V_189 ;
return 0 ;
}
static long F_110 ( void * V_33 , struct V_8 * V_9 )
{
struct V_1 * V_1 ;
V_1 = (struct V_1 * ) V_33 ;
if ( V_9 == NULL ) {
F_13 ( L_73 ) ;
return - V_65 ;
}
if ( V_9 -> V_235 [ 0 ] != V_58 ) {
F_13 ( L_74 , V_9 ) ;
return - V_54 ;
}
memcpy ( F_111 ( V_9 , 1 ) , & V_9 -> V_235 [ 0 ] , 1 ) ;
F_31 ( & V_1 -> V_36 , V_9 ) ;
F_23 ( & V_1 -> V_236 ) ;
return 0 ;
}
static void F_112 ( void * V_33 , int V_15 )
{
struct V_1 * V_1 ;
V_1 = (struct V_1 * ) V_33 ;
V_1 -> V_237 = V_15 ;
F_19 ( & V_238 ) ;
}
int F_106 ( struct V_1 * V_1 )
{
static struct V_239 V_240 ;
int V_62 ;
if ( F_15 ( V_197 , & V_1 -> V_39 ) ) {
F_41 ( L_75 ) ;
return 0 ;
}
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
V_240 . V_241 = F_110 ;
V_240 . V_242 = NULL ;
V_240 . V_243 = F_112 ;
V_240 . V_244 = NULL ;
V_240 . V_245 = V_1 ;
V_240 . V_246 = 0x08 ;
V_240 . V_247 = 0xff ;
V_240 . V_248 = 1 ;
V_240 . V_249 = 0 ;
V_240 . V_250 = 1 ;
V_240 . V_251 = 1 ;
V_62 = F_113 ( & V_240 ) ;
if ( V_62 == - V_252 ) {
F_33 ( & V_238 ) ;
V_1 -> V_237 = - V_252 ;
F_41 ( L_76 , V_253 ) ;
if ( ! F_34 ( & V_238 ,
V_254 ) ) {
F_13 ( L_77 ,
F_35 ( V_254 ) / 1000 ) ;
return - V_64 ;
}
if ( V_1 -> V_237 != 0 ) {
F_13 ( L_78 ,
V_1 -> V_237 ) ;
return - V_180 ;
}
V_62 = 0 ;
} else if ( V_62 == - 1 ) {
F_13 ( L_79 , V_62 ) ;
return - V_180 ;
}
if ( V_240 . V_244 != NULL ) {
F_26 = V_240 . V_244 ;
} else {
F_13 ( L_80 ) ;
V_62 = F_114 ( & V_240 ) ;
if ( V_62 < 0 )
F_13 ( L_81 , V_62 ) ;
return - V_180 ;
}
F_115 ( & V_1 -> V_131 ) ;
F_115 ( & V_1 -> V_43 ) ;
F_116 ( & V_1 -> V_46 ) ;
F_117 ( & V_1 -> V_47 , F_24 , ( unsigned long ) V_1 ) ;
F_116 ( & V_1 -> V_36 ) ;
F_117 ( & V_1 -> V_236 , F_11 , ( unsigned long ) V_1 ) ;
V_1 -> V_2 . V_4 = 0 ;
F_20 ( & V_1 -> V_45 , 1 ) ;
V_1 -> V_42 = NULL ;
F_118 ( & V_1 -> V_2 . V_5 , & F_40 ,
( unsigned long ) V_1 ) ;
V_1 -> V_2 . V_78 = V_77 ;
V_1 -> V_30 . V_31 = V_32 [ V_255 ] ;
V_1 -> V_30 . V_256 = V_257 ;
V_1 -> V_30 . V_258 = V_259 ;
V_1 -> V_30 . V_112 . V_39 = V_260 ;
V_1 -> V_30 . V_91 = V_147 ;
V_1 -> V_30 . V_261 = V_262 ;
V_1 -> V_30 . V_144 = V_263 ;
V_1 -> V_2 . V_69 = 0 ;
F_71 ( V_1 ) ;
F_119 ( & V_1 -> V_30 . V_112 . V_135 ) ;
F_120 ( V_1 ) ;
F_16 ( V_197 , & V_1 -> V_39 ) ;
return V_62 ;
}
int F_97 ( struct V_1 * V_1 )
{
static struct V_239 V_240 ;
int V_62 ;
if ( ! F_15 ( V_197 , & V_1 -> V_39 ) ) {
F_41 ( L_82 ) ;
return 0 ;
}
F_52 ( & V_1 -> V_30 . V_112 . V_135 ) ;
F_121 ( & V_1 -> V_47 ) ;
F_121 ( & V_1 -> V_236 ) ;
F_122 ( & V_1 -> V_46 ) ;
F_122 ( & V_1 -> V_36 ) ;
V_1 -> V_42 = NULL ;
V_1 -> V_30 . V_91 = 0 ;
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
V_240 . V_246 = 0x08 ;
V_62 = F_114 ( & V_240 ) ;
if ( V_62 < 0 )
F_13 ( L_83 , V_62 ) ;
else
F_41 ( L_84 ) ;
F_68 ( V_197 , & V_1 -> V_39 ) ;
return V_62 ;
}
static int T_6 F_123 ( void )
{
struct V_1 * V_1 = NULL ;
int V_62 = - V_57 ;
F_41 ( L_85 , V_264 ) ;
V_1 = F_124 ( sizeof( struct V_1 ) , V_265 ) ;
if ( NULL == V_1 ) {
F_13 ( L_86 ) ;
return V_62 ;
}
V_1 -> V_30 . V_112 . V_133 = V_266 * V_117 ;
V_1 -> V_30 . V_112 . V_108 = F_124 ( V_1 -> V_30 . V_112 . V_133 , V_265 ) ;
if ( NULL == V_1 -> V_30 . V_112 . V_108 ) {
F_13 ( L_87 ) ;
goto V_267;
}
V_62 = F_125 ( V_1 , V_268 ) ;
if ( V_62 < 0 )
goto V_269;
V_1 -> V_2 . V_3 = V_270 ;
V_1 -> V_189 = V_198 ;
V_1 -> V_271 . V_272 = V_273 ;
V_1 -> V_271 . V_274 = V_275 ;
return V_62 ;
V_269:
F_126 ( V_1 -> V_30 . V_112 . V_108 ) ;
V_267:
F_126 ( V_1 ) ;
return V_62 ;
}
static void T_7 F_127 ( void )
{
struct V_1 * V_1 = NULL ;
V_1 = F_128 () ;
if ( V_1 != NULL ) {
F_126 ( V_1 -> V_30 . V_112 . V_108 ) ;
F_126 ( V_1 ) ;
}
}
