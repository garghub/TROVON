static int F_1 ( int V_1 )
{
if ( F_2 ( V_1 < V_2 && V_1 >
F_3 ( V_3 ) ) )
return - V_4 ;
return V_3 [ V_1 ] ;
}
static void F_4 ( struct V_5 * V_6 )
{
F_5 ( L_1 ,
V_6 -> V_7 ?
V_6 -> V_7 -> V_8 : - 1 ,
V_6 -> V_9 ?
V_6 -> V_9 -> V_10 : 0 ,
V_6 -> V_11 ?
V_6 -> V_11 -> V_8 : - 1 ) ;
V_6 -> V_7 = V_6 -> V_11 ;
V_6 -> V_11 = NULL ;
V_6 -> V_9 = V_6 -> V_9 ?
& V_6 -> V_7 -> V_12 [ 0 ] : NULL ;
F_5 ( L_2 ,
V_6 -> V_7 ?
V_6 -> V_7 -> V_8 : - 1 ,
V_6 -> V_9 ?
V_6 -> V_9 -> V_10 : 0 ,
V_6 -> V_11 ?
V_6 -> V_11 -> V_8 : - 1 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = V_6 -> V_7 ;
struct V_13 * V_15 = V_6 -> V_11 ;
struct V_16 * V_17 = V_6 -> V_9 ;
struct V_18 * V_19 = V_6 -> V_19 ;
struct V_20 V_21 ;
int V_1 = V_6 -> V_1 ;
T_1 V_22 = F_7 ( V_19 -> V_23 ,
V_1 , V_24 ) ;
V_21 . V_25 = F_8 ( V_19 , V_22 ) ;
V_21 . V_26 = F_8 ( V_19 , V_22 + 4 ) ;
if ( V_14 ) {
V_21 . V_27 = ! ! V_14 -> V_8 ;
V_21 . V_28 = ! ! ! V_14 -> V_8 ;
V_21 . V_29 = V_21 . V_30 =
! ! ! ( V_14 -> V_8 ) ;
V_21 . V_31 = V_21 . V_32 =
! ! ( V_14 -> V_8 ) ;
} else {
V_21 . V_10 = 0 ;
V_21 . V_29 = V_21 . V_30 = 0 ;
V_21 . V_31 = V_21 . V_32 = 0 ;
}
V_21 . V_10 = V_17 ? V_17 -> V_10 : 0 ;
V_21 . V_33 = ! ! ( V_15 ) ;
F_8 ( V_19 , V_22 ) = V_21 . V_25 ;
F_8 ( V_19 , V_22 + 4 ) = V_21 . V_26 ;
F_5 ( L_3 ,
V_19 -> V_34 , V_22 , V_21 . V_25 , V_21 . V_26 ) ;
}
static void F_9 ( struct V_5 * V_6 ,
struct V_35 * V_21 ,
bool V_36 )
{
struct V_18 * V_19 = V_6 -> V_19 ;
int V_1 = V_6 -> V_1 ;
struct V_37 V_38 ;
T_1 V_39 ;
T_1 V_40 , V_41 , V_42 ;
V_40 = F_7 ( V_19 -> V_23 , V_1 ,
V_43 ) ;
V_41 = F_7 ( V_19 -> V_23 , V_1 ,
V_44 ) ;
V_38 . V_45 = F_8 ( V_19 , V_40 ) ;
V_39 = V_38 . V_46 ;
if ( V_39 == 0x7 )
V_39 = 0 ;
else {
++ V_39 ;
V_39 %= 0x6 ;
}
V_42 = V_41 + V_39 * 8 ;
F_8 ( V_19 , V_42 ) = V_21 -> V_25 ;
F_8 ( V_19 , V_42 + 4 ) = V_21 -> V_26 ;
V_38 . V_46 = V_39 ;
F_8 ( V_19 , V_40 ) = V_38 . V_45 ;
F_5 ( L_4 ,
V_19 -> V_34 , V_39 , V_42 , V_21 -> V_25 , V_21 -> V_26 ) ;
if ( V_36 )
return;
F_10 ( V_19 ,
F_1 ( V_6 -> V_1 ) ) ;
}
static int F_11 (
struct V_5 * V_6 ,
struct V_16 * V_12 )
{
struct V_13 * V_14 = V_6 -> V_7 ;
struct V_13 * V_15 = V_6 -> V_11 ;
struct V_16 * V_47 = & V_14 -> V_12 [ 0 ] ;
struct V_16 * V_48 = & V_14 -> V_12 [ 1 ] ;
struct V_35 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_5 ( L_5 , V_12 -> V_10 ) ;
if ( F_2 ( ! F_12 ( V_12 , V_6 -> V_9 ) ) ) {
F_13 ( L_6
L_7 ,
V_12 -> V_10 ,
V_6 -> V_9 -> V_10 ) ;
return - V_4 ;
}
if ( F_14 ( V_48 ) && F_12 ( V_47 , V_12 ) ) {
F_5 ( L_8 ) ;
V_6 -> V_9 = V_48 ;
F_6 ( V_6 ) ;
V_21 . V_49 = V_21 . V_50 = 1 ;
V_21 . V_10 = V_12 -> V_10 ;
F_9 ( V_6 , & V_21 , false ) ;
} else if ( ( ! F_14 ( V_48 ) && F_12 ( V_47 , V_12 ) )
|| ( F_14 ( V_48 ) && F_12 ( V_48 , V_12 ) ) ) {
F_5 ( L_9 ) ;
F_4 ( V_6 ) ;
F_6 ( V_6 ) ;
V_21 . V_49 = V_21 . V_51 = 1 ;
V_21 . V_10 = V_12 -> V_10 ;
if ( ! V_15 ) {
F_9 ( V_6 , & V_21 , false ) ;
} else {
F_9 ( V_6 , & V_21 , true ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_52 = 1 ;
V_21 . V_10 = 0 ;
F_9 ( V_6 , & V_21 , false ) ;
}
} else {
F_2 ( 1 ) ;
return - V_4 ;
}
return 0 ;
}
static struct V_13 * F_15 (
struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_19 ;
int V_1 = V_6 -> V_1 ;
T_1 V_22 = F_7 ( V_19 -> V_23 , V_1 ,
V_24 ) ;
struct V_20 V_21 ;
V_21 . V_25 = F_8 ( V_19 , V_22 ) ;
V_21 . V_26 = F_8 ( V_19 , V_22 + 4 ) ;
if ( V_21 . V_33 ) {
F_13 ( L_10 ) ;
return NULL ;
}
return & V_6 -> V_53 [ V_21 . V_28 ] ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_16 V_12 [ 2 ] )
{
struct V_13 * V_14 = V_6 -> V_7 ;
struct V_13 * V_53 =
F_15 ( V_6 ) ;
struct V_16 * V_47 , * V_48 ;
struct V_35 V_21 ;
F_5 ( L_11 ) ;
if ( ! V_53 ) {
F_13 ( L_12 ) ;
return - V_4 ;
}
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
memset ( V_53 -> V_12 , 0 , sizeof( V_53 -> V_12 ) ) ;
V_53 -> V_12 [ 0 ] = V_12 [ 0 ] ;
V_53 -> V_12 [ 1 ] = V_12 [ 1 ] ;
F_5 ( L_13 ,
V_53 -> V_8 , V_12 [ 0 ] . V_10 ,
V_12 [ 1 ] . V_10 ) ;
if ( ! V_14 ) {
F_5 ( L_14 ) ;
V_6 -> V_7 = V_53 ;
V_6 -> V_11 = NULL ;
V_6 -> V_9 = & V_53 -> V_12 [ 0 ] ;
F_5 ( L_15 ,
V_6 -> V_7 -> V_8 ,
V_6 -> V_9 -> V_10 ) ;
F_6 ( V_6 ) ;
V_21 . V_52 = 1 ;
V_21 . V_10 = 0 ;
F_9 ( V_6 , & V_21 , false ) ;
return 0 ;
}
V_47 = & V_14 -> V_12 [ 0 ] ;
V_48 = & V_14 -> V_12 [ 1 ] ;
F_5 ( L_16 ,
V_14 -> V_8 , V_47 -> V_10 , V_48 -> V_10 ) ;
if ( ( F_14 ( V_48 ) && F_12 ( V_48 , & V_53 -> V_12 [ 0 ] ) &&
( ! F_12 ( V_47 , V_6 -> V_9 ) ) ) ||
( ! F_14 ( V_48 ) &&
F_12 ( V_47 , & V_53 -> V_12 [ 0 ] ) ) ) {
F_5 ( L_9 ) ;
V_6 -> V_11 = V_53 ;
F_4 ( V_6 ) ;
F_6 ( V_6 ) ;
V_21 . V_54 = V_21 . V_55 = 1 ;
V_21 . V_10 = V_12 [ 0 ] . V_10 ;
F_9 ( V_6 , & V_21 , false ) ;
} else {
F_5 ( L_17 ) ;
V_6 -> V_11 = V_53 ;
F_6 ( V_6 ) ;
}
return 0 ;
}
static void F_17 ( struct V_56 * V_57 )
{
F_18 ( V_57 -> V_58 ) ;
F_19 ( V_57 -> V_58 ) ;
F_20 ( V_57 -> V_19 -> V_59 , V_57 ) ;
}
static void F_21 ( struct V_56 * V_57 )
{
const int V_60 = V_57 -> V_19 -> V_23 -> V_61 . V_62 ;
struct V_63 * V_64 ;
F_22 (entry_obj, &workload->shadow_bb, list) {
struct V_65 * V_66 ;
V_66 = F_23 ( V_64 -> V_67 , NULL , 0 , 4 , 0 ) ;
if ( F_24 ( V_66 ) ) {
F_13 ( L_18 ) ;
return;
}
V_64 -> V_68 [ 1 ] = F_25 ( V_66 ) ;
if ( V_60 == 8 )
V_64 -> V_68 [ 2 ] = 0 ;
}
}
static int F_26 ( struct V_69 * V_70 )
{
int V_1 = V_70 -> V_57 -> V_1 ;
struct V_71 * V_72 =
V_70 -> V_57 -> V_19 -> V_72 ;
struct V_73 * V_74 =
V_72 -> V_75 [ V_1 ] . V_76 -> V_67 ;
struct V_77 * V_78 ;
struct V_79 * V_79 ;
V_79 = F_27 ( V_74 , V_80 ) ;
V_78 = F_28 ( V_79 ) ;
V_78 -> V_81 . V_82 =
( V_78 -> V_81 . V_82 &
( ~ V_83 ) ) | V_70 -> V_84 . V_85 ;
V_78 -> V_86 . V_82 =
( V_78 -> V_86 . V_82 &
( ~ V_87 ) ) | V_70 -> V_88 . V_85 ;
F_29 ( V_78 ) ;
return 0 ;
}
static void F_30 ( struct V_69 * V_70 )
{
struct V_65 * V_66 ;
unsigned char * V_89 =
( unsigned char * ) V_70 -> V_88 . V_90 +
V_70 -> V_88 . V_91 ;
if ( V_70 -> V_88 . V_91 == 0 )
return;
V_66 = F_23 ( V_70 -> V_88 . V_67 , NULL ,
0 , V_92 , 0 ) ;
if ( F_24 ( V_66 ) ) {
F_13 ( L_19 ) ;
return;
}
V_70 -> V_88 . V_85 = F_25 ( V_66 ) ;
V_70 -> V_84 . V_85 = * ( ( unsigned int * ) V_89 + 1 ) ;
memset ( V_89 , 0 , V_92 ) ;
F_26 ( V_70 ) ;
}
static int F_31 ( struct V_56 * V_57 )
{
struct V_18 * V_19 = V_57 -> V_19 ;
struct V_16 V_12 [ 2 ] ;
int V_1 = V_57 -> V_1 ;
F_32 ( V_57 -> V_58 ) ;
F_33 ( V_57 -> V_19 ) ;
F_34 ( V_57 -> V_19 ) ;
F_21 ( V_57 ) ;
F_30 ( & V_57 -> V_70 ) ;
if ( ! V_57 -> V_93 )
return 0 ;
V_12 [ 0 ] = * F_35 ( & V_57 -> V_94 , 1 ) ;
V_12 [ 1 ] = * F_35 ( & V_57 -> V_94 , 0 ) ;
return F_16 ( & V_19 -> V_6 [ V_1 ] , V_12 ) ;
}
static void F_36 ( struct V_56 * V_57 )
{
if ( ! F_37 ( & V_57 -> V_95 ) ) {
struct V_63 * V_64 =
F_38 ( & V_57 -> V_95 ,
struct V_63 ,
V_96 ) ;
struct V_63 * V_97 ;
F_39 (entry_obj, temp, &workload->shadow_bb,
list) {
F_40 ( V_64 -> V_67 ) ;
F_41 ( V_64 -> V_67 ) ;
F_42 ( & V_64 -> V_96 ) ;
F_43 ( V_64 ) ;
}
}
}
static void F_44 ( struct V_69 * V_70 )
{
if ( V_70 -> V_88 . V_91 == 0 )
return;
F_40 ( V_70 -> V_88 . V_67 ) ;
F_41 ( V_70 -> V_88 . V_67 ) ;
}
static int F_45 ( struct V_56 * V_57 )
{
struct V_18 * V_19 = V_57 -> V_19 ;
struct V_5 * V_6 =
& V_19 -> V_6 [ V_57 -> V_1 ] ;
struct V_56 * V_98 ;
struct V_99 * V_100 = F_46 ( V_19 , V_57 -> V_1 ) -> V_100 ;
bool V_54 = false ;
int V_101 ;
F_5 ( L_20 , V_57 ,
V_57 -> V_21 ) ;
F_36 ( V_57 ) ;
F_44 ( & V_57 -> V_70 ) ;
if ( V_57 -> V_21 || V_19 -> V_102 )
goto V_103;
if ( ! F_37 ( F_46 ( V_19 , V_57 -> V_1 ) ) ) {
struct V_16 * V_104 , * V_105 ;
V_98 = F_47 ( V_100 ,
struct V_56 , V_96 ) ;
V_104 = & V_57 -> V_106 ;
V_105 = & V_98 -> V_106 ;
V_54 = F_12 ( V_104 , V_105 ) ;
}
if ( V_54 ) {
F_5 ( L_21 ) ;
F_17 ( V_57 ) ;
return 0 ;
}
V_101 = F_11 ( V_6 , & V_57 -> V_106 ) ;
if ( V_101 )
goto V_107;
V_103:
F_17 ( V_57 ) ;
return 0 ;
V_107:
F_17 ( V_57 ) ;
return V_101 ;
}
static void F_48 ( struct V_18 * V_19 ,
T_2 V_108 , T_1 V_109 [ 8 ] )
{
T_2 V_110 ;
int V_111 ;
V_110 = V_108 + F_49 ( V_112 . V_82 ) ;
for ( V_111 = 0 ; V_111 < 8 ; V_111 ++ )
F_50 ( V_19 ,
V_110 + V_111 * 8 , & V_109 [ 7 - V_111 ] , 4 ) ;
}
static int F_51 ( struct V_56 * V_57 )
{
struct V_16 * V_17 = & V_57 -> V_106 ;
struct V_113 * V_114 ;
int V_115 ;
T_1 V_109 [ 8 ] ;
if ( V_17 -> V_116 == 1 ) {
V_115 = 3 ;
} else if ( V_17 -> V_116 == 3 ) {
V_115 = 4 ;
} else {
F_13 ( L_22 ) ;
return - V_4 ;
}
F_48 ( V_57 -> V_19 , V_57 -> V_108 , V_109 ) ;
V_114 = F_52 ( V_57 -> V_19 , V_115 , V_109 ) ;
if ( V_114 ) {
F_53 ( V_114 ) ;
} else {
V_114 = F_54 ( V_57 -> V_19 , V_117 ,
V_109 , V_115 , 0 ) ;
if ( F_24 ( V_114 ) ) {
F_13 ( L_23 ) ;
return F_55 ( V_114 ) ;
}
}
V_57 -> V_58 = V_114 ;
return 0 ;
}
static int F_56 ( struct V_18 * V_19 , int V_1 ,
struct V_16 * V_17 ,
bool V_93 )
{
struct V_99 * V_118 = F_46 ( V_19 , V_1 ) ;
struct V_56 * V_119 = F_57 ( V_118 ) ;
struct V_56 * V_57 = NULL ;
T_2 V_108 ;
T_1 V_120 , V_121 , V_122 , V_123 , V_124 , V_84 , V_88 ;
int V_101 ;
V_108 = F_58 ( V_19 -> V_125 . V_126 ,
( T_1 ) ( ( V_17 -> V_127 + 1 ) << V_128 ) ) ;
if ( V_108 == V_129 ) {
F_13 ( L_24 , V_17 -> V_127 ) ;
return - V_4 ;
}
F_50 ( V_19 , V_108 +
F_49 ( V_130 . V_82 ) , & V_120 , 4 ) ;
F_50 ( V_19 , V_108 +
F_49 ( V_131 . V_82 ) , & V_121 , 4 ) ;
V_120 &= V_132 ;
V_121 &= V_133 ;
if ( V_119 && F_12 ( & V_119 -> V_106 , V_17 ) ) {
F_5 ( L_25 , V_1 ) ;
F_5 ( L_26 , V_120 ,
V_119 -> V_134 ) ;
V_120 = V_119 -> V_134 ;
}
F_5 ( L_27 , V_1 ) ;
V_57 = F_59 ( V_19 -> V_59 , V_135 ) ;
if ( ! V_57 )
return - V_136 ;
F_50 ( V_19 , V_108 +
F_49 ( V_137 . V_82 ) , & V_122 , 4 ) ;
F_50 ( V_19 , V_108 +
F_49 ( V_138 . V_82 ) , & V_123 , 4 ) ;
F_50 ( V_19 , V_108 +
F_49 ( V_139 . V_82 ) , & V_124 , 4 ) ;
F_60 ( & V_57 -> V_96 ) ;
F_60 ( & V_57 -> V_95 ) ;
F_61 ( & V_57 -> V_140 ) ;
F_62 ( & V_57 -> V_141 , 0 ) ;
V_57 -> V_19 = V_19 ;
V_57 -> V_1 = V_1 ;
V_57 -> V_106 = * V_17 ;
V_57 -> V_108 = V_108 ;
V_57 -> V_142 = V_120 ;
V_57 -> V_134 = V_121 ;
V_57 -> V_137 = V_122 ;
V_57 -> V_143 = V_123 ;
V_57 -> V_144 = F_31 ;
V_57 -> V_145 = F_45 ;
V_57 -> V_21 = - V_146 ;
V_57 -> V_93 = V_93 ;
if ( V_1 == V_2 ) {
F_50 ( V_19 , V_108 +
F_49 ( V_81 . V_82 ) , & V_84 , 4 ) ;
F_50 ( V_19 , V_108 +
F_49 ( V_86 . V_82 ) , & V_88 , 4 ) ;
V_57 -> V_70 . V_88 . V_147 =
V_88 & V_87 ;
V_57 -> V_70 . V_88 . V_91 =
( V_88 & V_148 ) *
V_92 ;
V_57 -> V_70 . V_84 . V_147 =
V_84 & V_83 ;
V_57 -> V_70 . V_57 = V_57 ;
F_2 ( V_57 -> V_70 . V_88 . V_91 && ! ( V_84 & 0x1 ) ) ;
}
if ( V_93 )
memcpy ( & V_57 -> V_94 ,
& V_19 -> V_6 [ V_1 ] . V_94 ,
sizeof( V_57 -> V_94 ) ) ;
F_5 ( L_28 ,
V_57 , V_1 , V_120 , V_121 , V_122 , V_123 ) ;
F_5 ( L_29 , V_57 ,
V_93 ) ;
V_101 = F_51 ( V_57 ) ;
if ( V_101 ) {
F_20 ( V_19 -> V_59 , V_57 ) ;
return V_101 ;
}
F_63 ( V_57 ) ;
return 0 ;
}
int F_64 ( struct V_18 * V_19 , int V_1 )
{
struct V_5 * V_6 = & V_19 -> V_6 [ V_1 ] ;
struct V_16 * V_17 [ 2 ] , V_149 [ 2 ] ;
unsigned long V_150 = 0 ;
bool V_93 = true ;
int V_101 ;
int V_111 ;
memset ( V_149 , 0 , sizeof( V_149 ) ) ;
V_17 [ 0 ] = F_35 ( & V_6 -> V_94 , 1 ) ;
V_17 [ 1 ] = F_35 ( & V_6 -> V_94 , 0 ) ;
for ( V_111 = 0 ; V_111 < 2 ; V_111 ++ ) {
if ( ! V_17 [ V_111 ] -> V_151 )
continue;
if ( ! V_17 [ V_111 ] -> V_152 ) {
F_13 ( L_30 ,
V_19 -> V_34 ) ;
return - V_4 ;
}
F_65 ( V_111 , & V_150 ) ;
V_149 [ V_111 ] = * V_17 [ V_111 ] ;
}
if ( ! V_150 ) {
F_13 ( L_31 ,
V_19 -> V_34 ) ;
return - V_4 ;
}
if ( ! F_66 ( 0 , ( void * ) & V_150 ) &&
F_66 ( 1 , ( void * ) & V_150 ) ) {
F_13 ( L_32 ,
V_19 -> V_34 ) ;
return - V_4 ;
}
F_67 (i, (void *)&valid_desc_bitmap, 2 ) {
V_101 = F_56 ( V_19 , V_1 , & V_149 [ V_111 ] ,
V_93 ) ;
if ( V_101 ) {
F_13 ( L_33 ,
V_19 -> V_34 ) ;
return V_101 ;
}
V_93 = false ;
}
return 0 ;
}
static void F_68 ( struct V_18 * V_19 , int V_1 )
{
struct V_5 * V_6 = & V_19 -> V_6 [ V_1 ] ;
struct V_37 V_38 ;
T_1 V_40 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_19 = V_19 ;
V_6 -> V_1 = V_1 ;
V_6 -> V_53 [ 0 ] . V_8 = 0 ;
V_6 -> V_53 [ 1 ] . V_8 = 1 ;
V_40 = F_7 ( V_19 -> V_23 , V_1 ,
V_43 ) ;
V_38 . V_45 = F_8 ( V_19 , V_40 ) ;
V_38 . V_153 = V_38 . V_46 = 0x7 ;
F_8 ( V_19 , V_40 ) = V_38 . V_45 ;
}
void F_69 ( struct V_18 * V_19 )
{
F_70 ( V_19 -> V_59 ) ;
}
int F_71 ( struct V_18 * V_19 )
{
enum V_154 V_111 ;
struct V_155 * V_75 ;
F_72 (engine, vgpu->gvt->dev_priv, i) {
F_68 ( V_19 , V_111 ) ;
F_60 ( & V_19 -> F_46 [ V_111 ] ) ;
}
V_19 -> V_59 = F_73 ( L_34 ,
sizeof( struct V_56 ) , 0 ,
V_156 ,
NULL ) ;
if ( ! V_19 -> V_59 )
return - V_136 ;
return 0 ;
}
void F_74 ( struct V_18 * V_19 ,
unsigned long V_157 )
{
struct V_158 * V_159 = V_19 -> V_23 -> V_159 ;
struct V_155 * V_75 ;
struct V_56 * V_160 , * V_161 ;
unsigned int V_162 ;
F_75 (engine, dev_priv, engine_mask, tmp) {
F_39 (pos, n,
&vgpu->workload_q_head[engine->id], list) {
F_76 ( & V_160 -> V_96 ) ;
F_17 ( V_160 ) ;
}
F_68 ( V_19 , V_75 -> V_34 ) ;
}
}
