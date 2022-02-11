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
F_6 ( L_6 , V_14 -> V_21 ) ;
V_10 = F_8 ( V_11 , 14 ) ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ )
F_6 ( L_7 ,
V_9 -> V_15 [ V_22 + V_12 ] ) ;
F_6 ( L_8 , ( V_11 > 14 ) ? L_9 : L_10 ) ;
}
F_6 ( L_11 ) ;
}
inline void F_9 ( struct V_8 * V_9 )
{
int V_10 , V_11 ;
T_1 V_12 ;
struct V_23 * V_24 ;
V_24 = (struct V_23 * ) V_9 -> V_15 ;
F_6 ( V_16 L_12
L_13 , V_24 -> V_18 , V_24 -> V_10 ,
V_24 -> V_25 , V_24 -> V_26 , V_24 -> V_19 ,
( V_24 -> V_20 ) ? L_4 : L_5 , V_24 -> V_21 ) ;
V_11 = V_9 -> V_10 - V_27 ;
if ( V_11 > 0 ) {
F_6 ( L_6 , V_24 -> V_21 ) ;
V_10 = F_8 ( V_11 , 14 ) ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ )
F_6 ( L_7 ,
V_9 -> V_15 [ V_27 + V_12 ] ) ;
F_6 ( L_8 , ( V_11 > 14 ) ? L_9 : L_10 ) ;
}
F_6 ( L_11 ) ;
}
void F_10 ( struct V_1 * V_1 , T_1 V_28 )
{
V_1 -> V_29 . V_30 = V_31 [ V_28 ] ;
}
static void F_11 ( unsigned long V_32 )
{
struct V_1 * V_1 ;
struct V_33 * V_2 ;
struct V_23 * V_24 ;
struct V_8 * V_9 ;
T_1 V_26 ;
unsigned long V_34 ;
V_1 = (struct V_1 * ) V_32 ;
V_2 = & V_1 -> V_2 ;
while ( ( V_9 = F_12 ( & V_1 -> V_35 ) ) ) {
if ( V_9 -> V_10 < sizeof( struct V_23 ) ) {
F_13 ( L_14
L_15 , V_9 ,
V_9 -> V_10 , sizeof( struct V_23 ) ) ;
F_14 ( V_9 ) ;
continue;
}
V_24 = ( void * ) V_9 -> V_15 ;
V_26 = V_24 -> V_26 ;
if ( V_24 -> V_19 == V_36 ) {
if ( ! F_15 ( V_37 , & V_1 -> V_38 ) ) {
F_16 ( V_37 , & V_1 -> V_38 ) ;
if ( V_2 -> V_4 != 0 ) {
F_13 ( L_16 ) ;
V_2 -> V_4 = 0 ;
}
V_2 -> V_3 [ V_2 -> V_4 ] ( V_1 ) ;
} else {
F_16 ( V_39 , & V_1 -> V_38 ) ;
}
F_14 ( V_9 ) ;
}
else if ( V_24 -> V_19 == V_1 -> V_40 && V_1 -> V_41 != NULL ) {
F_17 ( & V_1 -> V_42 , V_34 ) ;
V_1 -> V_43 = V_9 ;
F_18 ( & V_1 -> V_42 , V_34 ) ;
F_19 ( V_1 -> V_41 ) ;
V_1 -> V_41 = NULL ;
F_20 ( & V_1 -> V_44 , 1 ) ;
}
else if ( V_24 -> V_19 == V_1 -> V_40 && V_1 -> V_41 == NULL ) {
if ( V_1 -> V_43 != NULL )
F_13 ( L_17 ) ;
F_17 ( & V_1 -> V_42 , V_34 ) ;
V_1 -> V_43 = V_9 ;
F_18 ( & V_1 -> V_42 , V_34 ) ;
V_2 -> V_3 [ V_2 -> V_4 ] ( V_1 ) ;
F_14 ( V_9 ) ;
F_20 ( & V_1 -> V_44 , 1 ) ;
} else {
F_13 ( L_18 , V_9 ) ;
}
if ( V_26 && F_21 ( & V_1 -> V_44 ) )
if ( ! F_22 ( & V_1 -> V_45 ) )
F_23 ( & V_1 -> V_46 ) ;
}
}
static void F_24 ( unsigned long V_32 )
{
struct V_1 * V_1 ;
struct V_8 * V_9 ;
int V_10 ;
V_1 = (struct V_1 * ) V_32 ;
if ( ! F_21 ( & V_1 -> V_44 ) )
return;
if ( ( V_6 - V_1 -> V_47 ) > V_7 ) {
F_13 ( L_19 ) ;
F_20 ( & V_1 -> V_44 , 1 ) ;
}
V_9 = F_12 ( & V_1 -> V_45 ) ;
if ( ! V_9 )
return;
F_25 ( & V_1 -> V_44 ) ;
V_1 -> V_40 = F_7 ( V_9 ) -> V_48 ;
if ( V_1 -> V_41 != NULL )
F_13 ( L_20 ) ;
V_1 -> V_41 = F_7 ( V_9 ) -> V_17 ;
V_10 = F_26 ( V_9 ) ;
if ( V_10 < 0 ) {
F_14 ( V_9 ) ;
V_1 -> V_41 = NULL ;
F_13 ( L_21 , V_9 ) ;
F_20 ( & V_1 -> V_44 , 1 ) ;
} else {
V_1 -> V_47 = V_6 ;
}
}
static T_2 F_27 ( struct V_1 * V_1 , T_1 V_48 , T_3 type , void * V_49 ,
int V_50 , struct V_17 * V_51 )
{
struct V_8 * V_9 ;
struct V_13 * V_18 ;
int V_52 ;
if ( V_48 >= V_36 ) {
F_13 ( L_22 , V_48 ) ;
return - V_53 ;
}
if ( F_15 ( V_54 , & V_1 -> V_38 ) && V_49 == NULL ) {
F_13 ( L_23 ) ;
return - V_53 ;
}
if ( ! F_15 ( V_54 , & V_1 -> V_38 ) )
V_52 =
V_22 + ( ( V_49 == NULL ) ? 0 : V_50 ) ;
else
V_52 = V_50 ;
V_9 = F_28 ( V_52 , V_55 ) ;
if ( ! V_9 ) {
F_13 ( L_24 ) ;
return - V_56 ;
}
if ( ! F_15 ( V_54 , & V_1 -> V_38 ) ||
F_15 ( V_37 , & V_1 -> V_38 ) ) {
V_18 = (struct V_13 * ) F_29 ( V_9 , V_22 ) ;
V_18 -> V_18 = V_57 ;
V_18 -> V_10 = ( ( V_49 == NULL ) ? 0 : V_50 ) + 3 ;
V_18 -> V_19 = V_48 ;
V_18 -> V_20 = type ;
V_18 -> V_21 = V_50 ;
F_7 ( V_9 ) -> V_48 = V_48 ;
if ( V_49 != NULL )
* ( T_3 * ) V_49 = F_30 ( * ( T_3 * ) V_49 ) ;
} else if ( V_49 != NULL ) {
F_7 ( V_9 ) -> V_48 = * ( ( T_1 * ) V_49 + 2 ) ;
}
if ( V_49 != NULL )
memcpy ( F_29 ( V_9 , V_50 ) , V_49 , V_50 ) ;
F_7 ( V_9 ) -> V_17 = V_51 ;
F_31 ( & V_1 -> V_45 , V_9 ) ;
F_23 ( & V_1 -> V_46 ) ;
return 0 ;
}
T_2 F_32 ( struct V_1 * V_1 , T_1 V_48 , T_3 type , void * V_49 ,
unsigned int V_50 , void * V_58 , int * V_59 )
{
struct V_8 * V_9 ;
struct V_23 * V_24 ;
unsigned long V_34 ;
T_2 V_60 ;
F_33 ( & V_1 -> V_61 ) ;
V_60 = F_27 ( V_1 , V_48 , type , V_49 , V_50 ,
& V_1 -> V_61 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_34 ( & V_1 -> V_61 , V_7 ) ;
if ( ! V_60 ) {
F_13 ( L_25
L_26 ,
F_35 ( V_7 ) / 1000 ) ;
return - V_62 ;
}
if ( ! V_1 -> V_43 ) {
F_13 ( L_27 ) ;
return - V_63 ;
}
F_17 ( & V_1 -> V_42 , V_34 ) ;
V_9 = V_1 -> V_43 ;
V_1 -> V_43 = NULL ;
F_18 ( & V_1 -> V_42 , V_34 ) ;
V_24 = ( void * ) V_9 -> V_15 ;
if ( V_24 -> V_25 != 0 ) {
F_13 ( L_28 ,
V_24 -> V_25 ) ;
F_14 ( V_9 ) ;
return - V_64 ;
}
if ( V_58 != NULL && V_59 != NULL && V_24 -> V_21 ) {
F_36 ( V_9 , sizeof( struct V_23 ) ) ;
memcpy ( V_58 , V_9 -> V_15 , V_24 -> V_21 ) ;
* V_59 = V_24 -> V_21 ;
} else if ( V_59 != NULL && V_24 -> V_21 == 0 ) {
* V_59 = 0 ;
}
F_14 ( V_9 ) ;
return 0 ;
}
static inline T_2 F_37 ( struct V_1 * V_1 ,
struct V_8 * * V_9 )
{
struct V_23 * V_65 ;
unsigned long V_34 ;
F_38 ( & V_1 -> V_2 . V_5 ) ;
F_17 ( & V_1 -> V_42 , V_34 ) ;
* V_9 = V_1 -> V_43 ;
V_1 -> V_43 = NULL ;
F_18 ( & V_1 -> V_42 , V_34 ) ;
V_65 = ( void * ) ( * V_9 ) -> V_15 ;
if ( V_65 -> V_25 != 0 ) {
F_13 ( L_29
L_30 ,
V_65 -> V_19 ) ;
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
struct V_33 * V_66 ;
F_41 ( L_31 ) ;
V_1 = (struct V_1 * ) V_15 ;
V_66 = & V_1 -> V_2 ;
V_66 -> V_67 ++ ;
if ( V_66 -> V_67 > V_68 ) {
V_66 -> V_4 = 0 ;
V_66 -> V_67 = 0 ;
F_13 ( L_32
L_33 ) ;
return;
}
F_2 ( V_1 , V_69 ) ;
}
static void F_42 ( struct V_1 * V_1 )
{
T_3 V_38 ;
if ( ! F_27 ( V_1 , V_70 , V_71 , NULL , sizeof( V_38 ) , NULL ) )
F_3 ( V_1 , V_72 ) ;
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
struct V_23 * V_65 ;
if ( F_37 ( V_1 , & V_9 ) )
return;
V_65 = ( void * ) V_9 -> V_15 ;
F_36 ( V_9 , sizeof( struct V_23 ) ) ;
memcpy ( & V_1 -> V_2 . V_38 , V_9 -> V_15 , V_65 -> V_21 ) ;
V_1 -> V_2 . V_38 = F_44 ( V_1 -> V_2 . V_38 ) ;
F_41 ( L_34 , V_1 -> V_2 . V_38 ) ;
F_2 ( V_1 , V_73 ) ;
}
static void F_45 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 . V_38 & V_74 & V_1 -> V_2 . V_75 )
F_13 ( L_35 ) ;
F_2 ( V_1 , V_76 ) ;
}
static void F_46 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 . V_38 & V_77 & V_1 -> V_2 . V_75 ) {
F_41 ( L_36 ) ;
V_1 -> V_2 . V_4 = V_78 ;
} else {
V_1 -> V_2 . V_4 = V_79 ;
}
F_1 ( V_1 ) ;
}
static void F_47 ( struct V_1 * V_1 )
{
if ( ! F_27 ( V_1 , V_80 , V_71 , NULL ,
( V_81 * 3 ) , NULL ) )
F_3 ( V_1 , V_82 ) ;
}
static void F_48 ( struct V_1 * V_1 , T_1 V_83 )
{
struct V_84 * V_85 = & V_1 -> V_29 . V_85 ;
T_1 V_86 = V_1 -> V_29 . V_30 . V_87 ;
T_1 V_12 ;
T_2 V_88 ;
if ( ( V_83 >= V_89 ) && ( V_83 <= V_90 ) ) {
V_1 -> V_29 . V_85 . V_91 = ( V_83 - V_89 + 1 ) ;
V_1 -> V_29 . V_85 . V_92 = 0 ;
F_41 ( L_37 , V_1 -> V_29 . V_85 . V_91 ) ;
return;
}
if ( V_83 < V_93 )
return;
if ( V_86 == V_94 && V_83 > V_95 )
return;
if ( V_86 == V_96 && V_83 > V_97 )
return;
V_88 = V_1 -> V_29 . V_30 . V_98 + ( V_83 * 100 ) ;
if ( V_88 == V_1 -> V_29 . V_88 ) {
F_41 ( L_38 ,
V_1 -> V_29 . V_88 , V_88 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_85 -> V_92 ; V_12 ++ ) {
if ( V_85 -> V_99 [ V_12 ] == V_88 )
break;
}
if ( V_12 == V_85 -> V_91 ) {
F_41 ( L_39 ) ;
return;
}
if ( V_12 == V_85 -> V_92 ) {
F_41 ( L_40 , V_88 , V_12 ) ;
V_85 -> V_99 [ V_12 ] = V_88 ;
V_85 -> V_92 ++ ;
}
}
static void F_49 ( struct V_1 * V_1 ,
struct V_100 * V_101 )
{
T_1 V_102 ;
T_1 V_12 = 0 ;
T_1 * V_103 ;
if ( V_1 -> V_104 != 0x6350 ) {
V_103 = & V_101 -> V_15 . V_105 . V_106 [ 0 ] ;
while ( V_12 + 1 < V_107 ) {
V_102 = V_103 [ V_12 ] ;
V_103 [ V_12 ] = V_103 [ V_12 + 1 ] ;
V_103 [ V_12 + 1 ] = V_102 ;
V_12 += 2 ;
}
}
}
static void F_50 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
struct V_100 V_108 ;
struct V_109 * V_110 = & V_1 -> V_29 . V_110 ;
unsigned long V_111 , V_34 ;
T_1 * V_112 , V_113 , V_114 [ 3 ] ;
T_1 type , V_115 ;
T_3 V_116 ;
T_2 V_117 ;
if ( F_37 ( V_1 , & V_9 ) )
return;
F_36 ( V_9 , sizeof( struct V_23 ) ) ;
V_112 = V_9 -> V_15 ;
V_117 = V_9 -> V_10 ;
while ( V_117 >= V_118 ) {
V_113 = V_112 [ 2 ] ;
type = ( V_113 & 0x07 ) ;
V_115 = ( type <= V_119 ? type : ( type - 1 ) ) ;
F_41 ( L_41 , V_115 ,
( V_113 & V_120 ) ? L_42 : L_43 ) ;
if ( ( V_113 & V_120 ) != 0 )
break;
if ( V_115 < V_121 || V_115 > V_122 ) {
F_41 ( L_44 ) ;
V_110 -> V_123 = - 1 ;
break;
}
memcpy ( & V_108 . V_15 . V_105 .
V_106 [ V_115 * ( V_118 - 1 ) ] ,
V_112 , ( V_118 - 1 ) ) ;
V_110 -> V_123 = V_115 ;
if ( V_115 == V_122 ) {
F_41 ( L_45 ) ;
F_49 ( V_1 , & V_108 ) ;
V_116 = F_44 ( V_108 . V_15 . V_124 . V_125 ) ;
if ( V_1 -> V_29 . V_85 . V_126 != V_116 )
V_1 -> V_29 . V_85 . V_126 = V_116 ;
F_41 ( L_46 , V_116 ) ;
V_111 = ( V_108 . V_15 . V_124 . V_127 [ 0 ] >> 3 ) ;
F_41 ( L_47 , V_111 / 2 ,
( V_111 % 2 ) ? L_48 : L_49 ) ;
V_111 = 1 << ( V_108 . V_15 . V_124 . V_127 [ 0 ] >> 3 ) ;
if ( V_111 == V_128 ) {
F_48 ( V_1 , V_108 . V_15 . V_129 . V_83 [ 0 ] ) ;
F_48 ( V_1 , V_108 . V_15 . V_129 . V_83 [ 1 ] ) ;
}
}
V_117 -= V_118 ;
V_112 += V_118 ;
}
V_112 = V_9 -> V_15 ;
V_117 = V_9 -> V_10 ;
F_17 ( & V_1 -> V_130 , V_34 ) ;
while ( V_117 > 0 ) {
type = ( V_112 [ 2 ] & 0x07 ) ;
V_115 = ( type <= V_119 ? type : ( type - 1 ) ) ;
V_114 [ 2 ] = V_115 ;
V_114 [ 2 ] |= V_115 << 3 ;
V_114 [ 0 ] = V_112 [ 0 ] ;
V_114 [ 1 ] = V_112 [ 1 ] ;
memcpy ( & V_110 -> V_106 [ V_110 -> V_131 ] , & V_114 , V_118 ) ;
V_110 -> V_131 = ( V_110 -> V_131 + V_118 ) % V_110 -> V_132 ;
if ( V_110 -> V_131 == V_110 -> V_133 ) {
F_41 ( L_50 ) ;
V_110 -> V_131 = 0 ;
V_110 -> V_133 = 0 ;
break;
}
V_117 -= V_118 ;
V_112 += V_118 ;
}
F_18 ( & V_1 -> V_130 , V_34 ) ;
if ( V_110 -> V_131 != V_110 -> V_133 )
F_51 ( & V_110 -> V_134 ) ;
F_2 ( V_1 , V_135 ) ;
}
static void F_52 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_79 ) ;
}
static void F_53 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 . V_38 & ( V_136 | V_137 ) & V_1 ->
V_2 . V_75 ) {
F_41 ( L_51 ) ;
if ( F_54 ( V_138 , & V_1 -> V_38 ) ) {
V_1 -> V_2 . V_4 = V_139 ;
} else {
F_19 ( & V_1 -> V_61 ) ;
V_1 -> V_2 . V_4 = V_140 ;
}
} else
V_1 -> V_2 . V_4 = V_140 ;
F_1 ( V_1 ) ;
}
static void F_55 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 . V_38 & V_141 ) {
F_41 ( L_52 ) ;
F_19 ( & V_1 -> V_61 ) ;
}
F_2 ( V_1 , V_142 ) ;
}
static void F_56 ( struct V_1 * V_1 )
{
if ( ( V_1 -> V_29 . V_143 == V_144 ) &&
( V_1 -> V_2 . V_38 & V_145 & V_1 -> V_2 . V_75 ) &&
( V_1 -> V_29 . V_88 != V_146 ) &&
( V_1 -> V_29 . V_85 . V_92 != 0 ) ) {
F_41 ( L_53 ) ;
V_1 -> V_2 . V_75 &= ~ V_145 ;
V_1 -> V_29 . V_147 = 0 ;
V_1 -> V_29 . V_148 = V_1 -> V_29 . V_88 ;
V_1 -> V_2 . V_4 = V_149 ;
} else {
V_1 -> V_2 . V_4 = V_69 ;
}
F_1 ( V_1 ) ;
}
static void F_57 ( struct V_1 * V_1 )
{
T_3 V_49 ;
V_49 = V_1 -> V_29 . V_85 . V_126 ;
if ( ! F_27 ( V_1 , V_150 , V_151 , & V_49 , sizeof( V_49 ) , NULL ) )
F_3 ( V_1 , V_152 ) ;
}
static void F_58 ( struct V_1 * V_1 )
{
F_39 ( V_1 , V_153 ) ;
}
static void F_59 ( struct V_1 * V_1 )
{
T_3 V_49 ;
V_49 = 0x0000 ;
if ( ! F_27 ( V_1 , V_154 , V_151 , & V_49 , sizeof( V_49 ) , NULL ) )
F_3 ( V_1 , V_155 ) ;
}
static void F_60 ( struct V_1 * V_1 )
{
F_39 ( V_1 , V_156 ) ;
}
static void F_61 ( struct V_1 * V_1 )
{
T_3 V_157 ;
T_3 V_49 ;
F_41 ( L_54 , V_1 -> V_29 . V_85 . V_99 [ V_1 -> V_29 . V_147 ] ) ;
V_157 = ( V_1 -> V_29 . V_85 . V_99 [ V_1 -> V_29 . V_147 ] -
V_1 -> V_29 . V_30 . V_98 ) / V_158 ;
V_49 = V_157 ;
if ( ! F_27 ( V_1 , V_159 , V_151 , & V_49 , sizeof( V_49 ) , NULL ) )
F_3 ( V_1 , V_160 ) ;
}
static void F_62 ( struct V_1 * V_1 )
{
F_39 ( V_1 , V_161 ) ;
}
static void F_63 ( struct V_1 * V_1 )
{
T_3 V_49 ;
V_49 = V_136 ;
if ( ! F_27 ( V_1 , V_162 , V_151 , & V_49 , sizeof( V_49 ) , NULL ) )
F_3 ( V_1 , V_163 ) ;
}
static void F_64 ( struct V_1 * V_1 )
{
F_39 ( V_1 , V_164 ) ;
}
static void F_65 ( struct V_1 * V_1 )
{
T_3 V_49 ;
V_49 = V_165 ;
if ( ! F_27 ( V_1 , V_166 , V_151 , & V_49 ,
sizeof( V_49 ) , NULL ) )
F_3 ( V_1 , V_167 ) ;
}
static void F_66 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
if ( F_37 ( V_1 , & V_9 ) )
return;
V_1 -> V_2 . V_4 = V_168 ;
F_16 ( V_138 , & V_1 -> V_38 ) ;
F_67 ( V_37 , & V_1 -> V_38 ) ;
}
static void F_68 ( struct V_1 * V_1 )
{
T_3 V_49 ;
if ( ! F_27 ( V_1 , V_169 , V_71 , NULL , sizeof( V_49 ) , NULL ) )
F_3 ( V_1 , V_170 ) ;
}
static void F_69 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
T_3 V_171 ;
T_2 V_172 , V_173 ;
if ( F_37 ( V_1 , & V_9 ) )
return;
F_36 ( V_9 , sizeof( struct V_23 ) ) ;
memcpy ( & V_171 , V_9 -> V_15 , sizeof( V_171 ) ) ;
V_171 = F_44 ( V_171 ) ;
V_172 = V_1 -> V_29 . V_30 . V_98 + ( ( T_2 ) V_171 * V_158 ) ;
V_173 = V_1 -> V_29 . V_85 . V_99 [ V_1 -> V_29 . V_147 ] ;
if ( ( V_172 != V_1 -> V_29 . V_148 ) && ( V_172 == V_173 ) ) {
F_41 ( L_55 , V_172 ) ;
V_1 -> V_29 . V_88 = V_172 ;
F_70 ( V_1 ) ;
if ( V_1 -> V_29 . V_143 == V_144 )
V_1 -> V_2 . V_75 |= V_145 ;
V_1 -> V_2 . V_4 = V_174 ;
} else {
V_1 -> V_29 . V_147 ++ ;
if ( V_1 -> V_29 . V_147 >= V_1 -> V_29 . V_85 . V_92 ) {
F_41 ( L_56 ) ;
V_1 -> V_2 . V_4 = V_174 ;
} else {
F_41 ( L_57 ) ;
V_1 -> V_2 . V_4 = V_149 ;
}
}
F_1 ( V_1 ) ;
}
static void F_71 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_69 ) ;
}
static void F_72 ( struct V_1 * V_1 )
{
T_3 V_49 ;
V_49 = V_1 -> V_2 . V_75 ;
if ( ! F_27 ( V_1 , V_162 , V_151 , & V_49 ,
sizeof( V_49 ) , NULL ) )
F_3 ( V_1 , V_175 ) ;
}
static void F_73 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
if ( F_37 ( V_1 , & V_9 ) )
return;
V_1 -> V_2 . V_4 = V_168 ;
if ( F_54 ( V_39 , & V_1 -> V_38 ) )
V_1 -> V_2 . V_3 [ V_1 -> V_2 . V_4 ] ( V_1 ) ;
else
F_67 ( V_37 , & V_1 -> V_38 ) ;
}
T_2 F_74 ( struct V_1 * V_1 , struct V_176 * V_176 ,
struct V_177 * V_178 )
{
F_75 ( V_176 , & V_1 -> V_29 . V_110 . V_134 , V_178 ) ;
if ( V_1 -> V_29 . V_110 . V_133 != V_1 -> V_29 . V_110 . V_131 )
return 0 ;
return - V_179 ;
}
T_2 F_76 ( struct V_1 * V_1 , struct V_176 * V_176 ,
T_1 T_4 * V_180 , T_5 V_181 )
{
T_2 V_182 ;
unsigned long V_34 ;
int V_60 ;
if ( V_1 -> V_29 . V_110 . V_131 == V_1 -> V_29 . V_110 . V_133 ) {
if ( V_176 -> V_183 & V_184 )
return - V_185 ;
V_60 = F_77 ( V_1 -> V_29 . V_110 . V_134 ,
( V_1 -> V_29 . V_110 . V_131 != V_1 -> V_29 . V_110 . V_133 ) ) ;
if ( V_60 )
return - V_186 ;
}
V_181 /= 3 ;
V_182 = 0 ;
V_60 = 0 ;
F_17 ( & V_1 -> V_130 , V_34 ) ;
while ( V_182 < V_181 ) {
if ( V_1 -> V_29 . V_110 . V_131 == V_1 -> V_29 . V_110 . V_133 )
break;
if ( F_78 ( V_180 , & V_1 -> V_29 . V_110 . V_106 [ V_1 -> V_29 . V_110 . V_133 ] ,
V_118 ) )
break;
V_1 -> V_29 . V_110 . V_133 += V_118 ;
if ( V_1 -> V_29 . V_110 . V_133 >= V_1 -> V_29 . V_110 . V_132 )
V_1 -> V_29 . V_110 . V_133 = 0 ;
V_182 ++ ;
V_180 += V_118 ;
V_60 += V_118 ;
}
F_18 ( & V_1 -> V_130 , V_34 ) ;
return V_60 ;
}
T_2 F_79 ( struct V_1 * V_1 , T_2 V_187 )
{
switch ( V_1 -> V_188 ) {
case V_189 :
return F_80 ( V_1 , V_187 ) ;
case V_190 :
return F_81 ( V_1 , V_187 ) ;
default:
return - V_53 ;
}
}
T_2 F_82 ( struct V_1 * V_1 , T_2 * V_191 )
{
if ( V_1 -> V_29 . V_88 == V_146 ) {
F_13 ( L_58 ) ;
return - V_192 ;
}
if ( V_191 == NULL ) {
F_13 ( L_59 ) ;
return - V_56 ;
}
switch ( V_1 -> V_188 ) {
case V_189 :
* V_191 = V_1 -> V_29 . V_88 ;
return 0 ;
case V_190 :
* V_191 = 0 ;
return 0 ;
default:
return - V_53 ;
}
}
T_2 F_83 ( struct V_1 * V_1 , T_1 V_28 )
{
switch ( V_1 -> V_188 ) {
case V_189 :
return F_84 ( V_1 , V_28 ) ;
case V_190 :
return F_85 ( V_1 , V_28 ) ;
default:
return - V_53 ;
}
}
T_2 F_86 ( struct V_1 * V_1 , T_1 V_193 )
{
switch ( V_1 -> V_188 ) {
case V_189 :
return F_87 ( V_1 , V_193 ) ;
case V_190 :
return F_88 ( V_1 , V_193 ) ;
default:
return - V_53 ;
}
}
T_2 F_89 ( struct V_1 * V_1 , T_3 V_194 )
{
switch ( V_1 -> V_188 ) {
case V_189 :
return F_90 ( V_1 , V_194 ) ;
case V_190 :
return F_91 ( V_1 , V_194 ) ;
default:
return - V_53 ;
}
}
T_2 F_92 ( struct V_1 * V_1 , T_1 V_195 )
{
switch ( V_1 -> V_188 ) {
case V_189 :
return F_93 ( V_1 , V_195 ) ;
case V_190 :
return F_94 ( V_1 , V_195 ) ;
default:
return - V_53 ;
}
}
static T_2 F_95 ( struct V_1 * V_1 )
{
T_3 V_49 ;
T_2 V_60 ;
if ( ! F_15 ( V_196 , & V_1 -> V_38 ) ) {
F_13 ( L_60 ) ;
return - V_192 ;
}
if ( V_1 -> V_188 == V_197 ) {
F_41 ( L_61 ) ;
return 0 ;
}
V_49 = 0x0 ;
V_60 = F_32 ( V_1 , V_198 , V_151 , & V_49 ,
sizeof( V_49 ) , NULL , NULL ) ;
if ( V_60 < 0 )
return V_60 ;
return F_96 ( V_1 ) ;
}
static T_2 F_97 ( struct V_1 * V_1 , const T_1 * V_199 )
{
const struct V_200 * V_201 ;
struct V_202 * V_203 ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
T_1 * V_208 ;
int V_60 , V_209 , V_210 ;
V_210 = 0 ;
F_16 ( V_54 , & V_1 -> V_38 ) ;
V_60 = F_98 ( & V_201 , V_199 ,
& V_1 -> V_211 -> V_212 ) ;
if ( V_60 < 0 ) {
F_13 ( L_62 , V_199 ) ;
return V_60 ;
}
F_41 ( L_63 , V_199 , V_201 -> V_52 ) ;
V_208 = ( void * ) V_201 -> V_15 ;
V_209 = V_201 -> V_52 ;
V_203 = (struct V_202 * ) V_208 ;
if ( V_203 -> V_213 != V_214 ) {
F_13 ( L_64 , V_199 ) ;
V_60 = - V_53 ;
goto V_215;
}
F_41 ( L_65 , V_199 , V_203 -> V_213 ) ;
V_208 += sizeof( struct V_202 ) ;
V_209 -= sizeof( struct V_202 ) ;
while ( V_208 && V_209 > 0 ) {
V_205 = (struct V_204 * ) V_208 ;
switch ( V_205 -> type ) {
case V_216 :
if ( F_32 ( V_1 , 0 , 0 , V_205 -> V_15 ,
V_205 -> V_52 , NULL , NULL ) )
goto V_215;
V_210 ++ ;
break;
case V_217 :
V_207 = (struct V_206 * ) V_205 -> V_15 ;
F_99 ( V_207 -> V_218 ) ;
break;
}
V_208 += ( sizeof( struct V_204 ) + ( V_205 -> V_52 ) ) ;
V_209 -= ( sizeof( struct V_204 ) + ( V_205 -> V_52 ) ) ;
}
F_41 ( L_66 , V_210 ) ;
V_215:
F_100 ( V_201 ) ;
F_67 ( V_54 , & V_1 -> V_38 ) ;
return V_60 ;
}
static T_2 F_101 ( struct V_1 * V_1 )
{
int V_60 ;
V_60 = F_102 ( V_1 , V_219 ) ;
if ( V_60 < 0 )
return V_60 ;
return F_103 ( V_1 , V_220 ) ;
}
static T_2 F_104 ( struct V_1 * V_1 , T_1 V_194 )
{
T_3 V_49 , V_221 , V_222 ;
int V_223 , V_60 ;
T_1 V_199 [ 50 ] ;
if ( V_194 >= V_224 ) {
F_13 ( L_67 ) ;
return - V_53 ;
}
V_60 = F_105 ( V_1 ) ;
if ( V_60 < 0 ) {
F_13 ( L_68 ) ;
return V_60 ;
}
V_49 = V_225 ;
if ( F_32 ( V_1 , V_198 , V_151 , & V_49 ,
sizeof( V_49 ) , NULL , NULL ) )
goto V_226;
F_106 ( 20 ) ;
if ( F_32 ( V_1 , V_227 , V_71 , NULL ,
sizeof( V_221 ) , & V_221 , & V_223 ) )
goto V_226;
if ( F_32 ( V_1 , V_228 , V_71 , NULL ,
sizeof( V_222 ) , & V_222 , & V_223 ) )
goto V_226;
F_41 ( L_69 ,
F_44 ( V_221 ) , F_44 ( V_222 ) ) ;
sprintf ( V_199 , L_70 , V_229 ,
F_44 ( V_221 ) , F_44 ( V_222 ) ) ;
V_60 = F_97 ( V_1 , V_199 ) ;
if ( V_60 < 0 ) {
F_41 ( L_71 , V_199 ) ;
goto V_226;
}
sprintf ( V_199 , L_70 , ( V_194 == V_189 ) ?
V_230 : V_231 ,
F_44 ( V_221 ) , F_44 ( V_222 ) ) ;
V_60 = F_97 ( V_1 , V_199 ) ;
if ( V_60 < 0 ) {
F_41 ( L_71 , V_199 ) ;
goto V_226;
} else
return V_60 ;
V_226:
return F_96 ( V_1 ) ;
}
T_2 F_107 ( struct V_1 * V_1 , T_1 V_232 )
{
int V_60 = 0 ;
if ( V_232 >= V_224 ) {
F_13 ( L_72 ) ;
return - V_53 ;
}
if ( V_1 -> V_188 == V_232 ) {
F_41 ( L_73 , V_232 ) ;
return V_60 ;
}
switch ( V_232 ) {
case V_197 :
V_60 = F_95 ( V_1 ) ;
if ( V_60 < 0 ) {
F_13 ( L_74 ) ;
return V_60 ;
}
break;
case V_190 :
case V_189 :
if ( V_1 -> V_188 != V_197 ) {
V_60 = F_95 ( V_1 ) ;
if ( V_60 < 0 ) {
F_13 ( L_74 ) ;
return V_60 ;
}
F_106 ( 30 ) ;
}
V_60 = F_104 ( V_1 , V_232 ) ;
if ( V_60 < 0 ) {
F_13 ( L_75 ) ;
return V_60 ;
}
}
V_1 -> V_188 = V_232 ;
if ( V_1 -> V_188 == V_189 ) {
F_41 ( L_76 ) ;
V_60 = F_101 ( V_1 ) ;
if ( V_60 < 0 )
F_13 ( L_77 ) ;
}
return V_60 ;
}
T_2 F_108 ( struct V_1 * V_1 , T_1 * V_233 )
{
if ( ! F_15 ( V_196 , & V_1 -> V_38 ) ) {
F_13 ( L_60 ) ;
return - V_192 ;
}
if ( V_233 == NULL ) {
F_13 ( L_59 ) ;
return - V_56 ;
}
* V_233 = V_1 -> V_188 ;
return 0 ;
}
static long F_109 ( void * V_32 , struct V_8 * V_9 )
{
struct V_1 * V_1 ;
V_1 = (struct V_1 * ) V_32 ;
if ( V_9 == NULL ) {
F_13 ( L_78 ) ;
return - V_63 ;
}
if ( V_9 -> V_234 [ 0 ] != V_57 ) {
F_13 ( L_79 , V_9 ) ;
return - V_53 ;
}
memcpy ( F_110 ( V_9 , 1 ) , & V_9 -> V_234 [ 0 ] , 1 ) ;
F_31 ( & V_1 -> V_35 , V_9 ) ;
F_23 ( & V_1 -> V_235 ) ;
return 0 ;
}
static void F_111 ( void * V_32 , char V_15 )
{
struct V_1 * V_1 ;
V_1 = (struct V_1 * ) V_32 ;
V_1 -> V_236 = V_15 ;
F_19 ( & V_237 ) ;
}
T_2 F_105 ( struct V_1 * V_1 )
{
static struct V_238 V_239 ;
T_2 V_60 ;
if ( F_15 ( V_196 , & V_1 -> V_38 ) ) {
F_41 ( L_80 ) ;
return 0 ;
}
memset ( & V_239 , 0 , sizeof( V_239 ) ) ;
V_239 . V_240 = F_109 ;
V_239 . V_241 = NULL ;
V_239 . V_242 = F_111 ;
V_239 . V_243 = NULL ;
V_239 . V_244 = V_1 ;
V_239 . V_245 = 0x08 ;
V_239 . V_246 = 0xff ;
V_239 . V_247 = 1 ;
V_239 . V_248 = 0 ;
V_239 . V_249 = 1 ;
V_239 . V_250 = 1 ;
V_60 = F_112 ( & V_239 ) ;
if ( V_60 == - V_251 ) {
F_33 ( & V_237 ) ;
V_1 -> V_236 = - V_251 ;
F_41 ( L_81 , V_252 ) ;
V_60 = F_34 ( & V_237 ,
V_253 ) ;
if ( ! V_60 ) {
F_13 ( L_82
L_83 ,
F_35 ( V_253 ) / 1000 ) ;
return - V_62 ;
}
if ( V_1 -> V_236 != 0 ) {
F_13 ( L_84
L_85 , V_1 -> V_236 ) ;
return - V_179 ;
}
V_60 = 0 ;
} else if ( V_60 == - 1 ) {
F_13 ( L_86 , V_60 ) ;
return - V_179 ;
}
if ( V_239 . V_243 != NULL ) {
F_26 = V_239 . V_243 ;
} else {
F_13 ( L_87 ) ;
V_60 = F_113 ( & V_239 ) ;
if ( V_60 < 0 )
F_13 ( L_88 , V_60 ) ;
return - V_179 ;
}
F_114 ( & V_1 -> V_130 ) ;
F_114 ( & V_1 -> V_42 ) ;
F_115 ( & V_1 -> V_45 ) ;
F_116 ( & V_1 -> V_46 , F_24 , ( unsigned long ) V_1 ) ;
F_115 ( & V_1 -> V_35 ) ;
F_116 ( & V_1 -> V_235 , F_11 , ( unsigned long ) V_1 ) ;
V_1 -> V_2 . V_4 = 0 ;
F_20 ( & V_1 -> V_44 , 1 ) ;
V_1 -> V_41 = NULL ;
F_117 ( & V_1 -> V_2 . V_5 ) ;
V_1 -> V_2 . V_5 . V_254 = & F_40 ;
V_1 -> V_2 . V_5 . V_15 = ( unsigned long ) V_1 ;
V_1 -> V_2 . V_75 = V_74 ;
memcpy ( & V_1 -> V_29 . V_30 , & V_31 [ V_255 ] ,
sizeof( struct V_256 ) ) ;
V_1 -> V_29 . V_257 = V_258 ;
V_1 -> V_29 . V_259 = V_260 ;
V_1 -> V_29 . V_110 . V_38 = V_261 ;
V_1 -> V_29 . V_88 = V_146 ;
V_1 -> V_29 . V_262 = V_263 ;
V_1 -> V_29 . V_143 = V_264 ;
V_1 -> V_2 . V_67 = 0 ;
F_70 ( V_1 ) ;
F_118 ( & V_1 -> V_29 . V_110 . V_134 ) ;
F_119 ( V_1 ) ;
F_16 ( V_196 , & V_1 -> V_38 ) ;
return V_60 ;
}
T_2 F_96 ( struct V_1 * V_1 )
{
static struct V_238 V_239 ;
T_2 V_60 ;
if ( ! F_15 ( V_196 , & V_1 -> V_38 ) ) {
F_41 ( L_89 ) ;
return 0 ;
}
F_51 ( & V_1 -> V_29 . V_110 . V_134 ) ;
F_120 ( & V_1 -> V_46 ) ;
F_120 ( & V_1 -> V_235 ) ;
F_121 ( & V_1 -> V_45 ) ;
F_121 ( & V_1 -> V_35 ) ;
V_1 -> V_41 = NULL ;
V_1 -> V_29 . V_88 = 0 ;
memset ( & V_239 , 0 , sizeof( V_239 ) ) ;
V_239 . V_245 = 0x08 ;
V_60 = F_113 ( & V_239 ) ;
if ( V_60 < 0 )
F_13 ( L_90 , V_60 ) ;
else
F_41 ( L_91 ) ;
F_67 ( V_196 , & V_1 -> V_38 ) ;
return V_60 ;
}
static int T_6 F_122 ( void )
{
struct V_1 * V_1 = NULL ;
T_2 V_60 = - V_56 ;
F_41 ( L_92 , V_265 ) ;
V_1 = F_123 ( sizeof( struct V_1 ) , V_266 ) ;
if ( NULL == V_1 ) {
F_13 ( L_93 ) ;
return V_60 ;
}
V_1 -> V_29 . V_110 . V_132 = V_267 * V_118 ;
V_1 -> V_29 . V_110 . V_106 = F_123 ( V_1 -> V_29 . V_110 . V_132 , V_266 ) ;
if ( NULL == V_1 -> V_29 . V_110 . V_106 ) {
F_13 ( L_94 ) ;
goto V_268;
}
V_60 = F_124 ( V_1 , V_269 ) ;
if ( V_60 < 0 )
goto V_270;
V_1 -> V_2 . V_3 = V_271 ;
V_1 -> V_188 = V_197 ;
V_1 -> V_272 . V_273 = V_274 ;
V_1 -> V_272 . V_275 = V_276 ;
return V_60 ;
V_270:
F_125 ( V_1 -> V_29 . V_110 . V_106 ) ;
V_268:
F_125 ( V_1 ) ;
return V_60 ;
}
static void T_7 F_126 ( void )
{
struct V_1 * V_1 = NULL ;
V_1 = F_127 () ;
if ( V_1 != NULL ) {
F_125 ( V_1 -> V_29 . V_110 . V_106 ) ;
F_125 ( V_1 ) ;
}
}
