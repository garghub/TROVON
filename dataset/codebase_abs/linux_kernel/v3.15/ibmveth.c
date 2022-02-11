static inline T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_6 ) ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return ( F_1 ( V_2 ) & V_7 ) >>
V_8 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) == V_2 -> V_3 . V_9 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) & V_10 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) & V_11 ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_12 ) ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) & V_13 ;
}
static void F_9 ( struct V_14 * V_15 ,
T_1 V_16 , T_1 V_17 ,
T_1 V_18 , T_1 V_19 )
{
V_15 -> V_20 = V_17 ;
V_15 -> V_5 = V_16 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_21 = V_17 * 7 / 8 ;
V_15 -> V_22 = V_19 ;
}
static int F_10 ( struct V_14 * V_15 )
{
int V_23 ;
V_15 -> V_24 = F_11 ( sizeof( V_25 ) * V_15 -> V_20 , V_26 ) ;
if ( ! V_15 -> V_24 )
return - 1 ;
V_15 -> V_27 = F_11 ( sizeof( V_28 ) * V_15 -> V_20 , V_26 ) ;
if ( ! V_15 -> V_27 ) {
F_12 ( V_15 -> V_24 ) ;
V_15 -> V_24 = NULL ;
return - 1 ;
}
V_15 -> V_29 = F_13 ( V_15 -> V_20 , sizeof( void * ) , V_26 ) ;
if ( ! V_15 -> V_29 ) {
F_12 ( V_15 -> V_27 ) ;
V_15 -> V_27 = NULL ;
F_12 ( V_15 -> V_24 ) ;
V_15 -> V_24 = NULL ;
return - 1 ;
}
memset ( V_15 -> V_27 , 0 , sizeof( V_28 ) * V_15 -> V_20 ) ;
for ( V_23 = 0 ; V_23 < V_15 -> V_20 ; ++ V_23 )
V_15 -> V_24 [ V_23 ] = V_23 ;
F_14 ( & V_15 -> V_30 , 0 ) ;
V_15 -> V_31 = 0 ;
V_15 -> V_32 = 0 ;
return 0 ;
}
static inline void F_15 ( void * V_33 , unsigned long V_12 )
{
unsigned long V_34 ;
for ( V_34 = 0 ; V_34 < V_12 ; V_34 += V_35 )
asm("dcbfl %0,%1" :: "b" (addr), "r" (offset));
}
static void F_16 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
T_1 V_23 ;
T_1 V_36 = V_15 -> V_20 - F_17 ( & V_15 -> V_30 ) ;
T_1 V_37 = 0 ;
struct V_38 * V_39 ;
unsigned int V_40 , V_5 ;
T_2 V_41 ;
unsigned long V_42 ;
V_28 V_27 ;
F_18 () ;
for ( V_23 = 0 ; V_23 < V_36 ; ++ V_23 ) {
union V_43 V_44 ;
V_39 = F_19 ( V_2 -> V_45 , V_15 -> V_18 ) ;
if ( ! V_39 ) {
F_20 ( V_2 -> V_45 ,
L_1 ) ;
V_2 -> V_46 ++ ;
break;
}
V_40 = V_15 -> V_32 ;
V_15 -> V_32 ++ ;
if ( V_15 -> V_32 >= V_15 -> V_20 )
V_15 -> V_32 = 0 ;
V_5 = V_15 -> V_24 [ V_40 ] ;
F_21 ( V_5 == V_47 ) ;
F_21 ( V_15 -> V_29 [ V_5 ] != NULL ) ;
V_27 = F_22 ( & V_2 -> V_48 -> V_49 , V_39 -> V_50 ,
V_15 -> V_18 , V_51 ) ;
if ( F_23 ( & V_2 -> V_48 -> V_49 , V_27 ) )
goto V_52;
V_15 -> V_24 [ V_40 ] = V_47 ;
V_15 -> V_27 [ V_5 ] = V_27 ;
V_15 -> V_29 [ V_5 ] = V_39 ;
V_41 = ( ( T_2 ) V_15 -> V_5 << 32 ) | V_5 ;
* ( T_2 * ) V_39 -> V_50 = V_41 ;
V_44 . V_53 . V_54 = V_55 | V_15 -> V_18 ;
V_44 . V_53 . V_56 = V_27 ;
if ( V_57 ) {
unsigned int V_58 = F_24 ( V_15 -> V_18 ,
V_2 -> V_45 -> V_59 +
V_60 ) ;
F_15 ( V_39 -> V_50 , V_58 ) ;
}
V_42 = F_25 ( V_2 -> V_48 -> V_61 ,
V_44 . V_44 ) ;
if ( V_42 != V_62 ) {
goto V_52;
} else {
V_37 ++ ;
V_2 -> V_63 ++ ;
}
}
F_18 () ;
F_26 ( V_37 , & ( V_15 -> V_30 ) ) ;
return;
V_52:
V_15 -> V_24 [ V_40 ] = V_5 ;
V_15 -> V_29 [ V_5 ] = NULL ;
if ( V_15 -> V_32 == 0 )
V_15 -> V_32 = V_15 -> V_20 - 1 ;
else
V_15 -> V_32 -- ;
if ( ! F_23 ( & V_2 -> V_48 -> V_49 , V_27 ) )
F_27 ( & V_2 -> V_48 -> V_49 ,
V_15 -> V_27 [ V_5 ] , V_15 -> V_18 ,
V_51 ) ;
F_28 ( V_39 ) ;
V_2 -> V_64 ++ ;
F_18 () ;
F_26 ( V_37 , & ( V_15 -> V_30 ) ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_23 ;
V_2 -> V_65 ++ ;
for ( V_23 = ( V_66 - 1 ) ; V_23 >= 0 ; V_23 -- ) {
struct V_14 * V_15 = & V_2 -> V_67 [ V_23 ] ;
if ( V_15 -> V_22 &&
( F_17 ( & V_15 -> V_30 ) < V_15 -> V_21 ) )
F_16 ( V_2 , V_15 ) ;
}
V_2 -> V_68 = * ( T_2 * ) ( ( ( char * ) V_2 -> V_69 ) +
4096 - 8 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_23 ;
F_12 ( V_15 -> V_24 ) ;
V_15 -> V_24 = NULL ;
if ( V_15 -> V_29 && V_15 -> V_27 ) {
for ( V_23 = 0 ; V_23 < V_15 -> V_20 ; ++ V_23 ) {
struct V_38 * V_39 = V_15 -> V_29 [ V_23 ] ;
if ( V_39 ) {
F_27 ( & V_2 -> V_48 -> V_49 ,
V_15 -> V_27 [ V_23 ] ,
V_15 -> V_18 ,
V_51 ) ;
F_28 ( V_39 ) ;
V_15 -> V_29 [ V_23 ] = NULL ;
}
}
}
if ( V_15 -> V_27 ) {
F_12 ( V_15 -> V_27 ) ;
V_15 -> V_27 = NULL ;
}
if ( V_15 -> V_29 ) {
F_12 ( V_15 -> V_29 ) ;
V_15 -> V_29 = NULL ;
}
}
static void F_31 ( struct V_1 * V_2 ,
T_2 V_41 )
{
unsigned int V_15 = V_41 >> 32 ;
unsigned int V_5 = V_41 & 0xffffffffUL ;
unsigned int V_40 ;
struct V_38 * V_39 ;
F_21 ( V_15 >= V_66 ) ;
F_21 ( V_5 >= V_2 -> V_67 [ V_15 ] . V_20 ) ;
V_39 = V_2 -> V_67 [ V_15 ] . V_29 [ V_5 ] ;
F_21 ( V_39 == NULL ) ;
V_2 -> V_67 [ V_15 ] . V_29 [ V_5 ] = NULL ;
F_27 ( & V_2 -> V_48 -> V_49 ,
V_2 -> V_67 [ V_15 ] . V_27 [ V_5 ] ,
V_2 -> V_67 [ V_15 ] . V_18 ,
V_51 ) ;
V_40 = V_2 -> V_67 [ V_15 ] . V_31 ;
V_2 -> V_67 [ V_15 ] . V_31 ++ ;
if ( V_2 -> V_67 [ V_15 ] . V_31 >=
V_2 -> V_67 [ V_15 ] . V_20 )
V_2 -> V_67 [ V_15 ] . V_31 = 0 ;
V_2 -> V_67 [ V_15 ] . V_24 [ V_40 ] = V_5 ;
F_18 () ;
F_32 ( & ( V_2 -> V_67 [ V_15 ] . V_30 ) ) ;
}
static inline struct V_38 * F_33 ( struct V_1 * V_2 )
{
T_2 V_41 = V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_41 ;
unsigned int V_15 = V_41 >> 32 ;
unsigned int V_5 = V_41 & 0xffffffffUL ;
F_21 ( V_15 >= V_66 ) ;
F_21 ( V_5 >= V_2 -> V_67 [ V_15 ] . V_20 ) ;
return V_2 -> V_67 [ V_15 ] . V_29 [ V_5 ] ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_1 V_70 = V_2 -> V_3 . V_5 ;
T_2 V_41 = V_2 -> V_3 . V_4 [ V_70 ] . V_41 ;
unsigned int V_15 = V_41 >> 32 ;
unsigned int V_5 = V_41 & 0xffffffffUL ;
union V_43 V_44 ;
unsigned long V_42 ;
int V_71 = 1 ;
F_21 ( V_15 >= V_66 ) ;
F_21 ( V_5 >= V_2 -> V_67 [ V_15 ] . V_20 ) ;
if ( ! V_2 -> V_67 [ V_15 ] . V_22 ) {
F_35 ( V_2 ) ;
F_30 ( V_2 , & V_2 -> V_67 [ V_15 ] ) ;
goto V_72;
}
V_44 . V_53 . V_54 = V_55 |
V_2 -> V_67 [ V_15 ] . V_18 ;
V_44 . V_53 . V_56 = V_2 -> V_67 [ V_15 ] . V_27 [ V_5 ] ;
V_42 = F_25 ( V_2 -> V_48 -> V_61 , V_44 . V_44 ) ;
if ( V_42 != V_62 ) {
F_20 ( V_2 -> V_45 , L_2
L_3 , V_42 ) ;
F_31 ( V_2 , V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_41 ) ;
V_71 = 0 ;
}
if ( ++ V_2 -> V_3 . V_5 == V_2 -> V_3 . V_73 ) {
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_9 = ! V_2 -> V_3 . V_9 ;
}
V_72:
return V_71 ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_31 ( V_2 , V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_41 ) ;
if ( ++ V_2 -> V_3 . V_5 == V_2 -> V_3 . V_73 ) {
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_9 = ! V_2 -> V_3 . V_9 ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
int V_23 ;
struct V_74 * V_49 = & V_2 -> V_48 -> V_49 ;
if ( V_2 -> V_69 != NULL ) {
if ( ! F_23 ( V_49 , V_2 -> V_75 ) ) {
F_27 ( V_49 , V_2 -> V_75 , 4096 ,
V_76 ) ;
V_2 -> V_75 = V_77 ;
}
F_37 ( ( unsigned long ) V_2 -> V_69 ) ;
V_2 -> V_69 = NULL ;
}
if ( V_2 -> V_78 != NULL ) {
if ( ! F_23 ( V_49 , V_2 -> V_79 ) ) {
F_27 ( V_49 , V_2 -> V_79 , 4096 ,
V_76 ) ;
V_2 -> V_79 = V_77 ;
}
F_37 ( ( unsigned long ) V_2 -> V_78 ) ;
V_2 -> V_78 = NULL ;
}
if ( V_2 -> V_3 . V_4 != NULL ) {
F_38 ( V_49 , V_2 -> V_3 . V_80 ,
V_2 -> V_3 . V_4 ,
V_2 -> V_3 . V_81 ) ;
V_2 -> V_3 . V_4 = NULL ;
}
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ )
if ( V_2 -> V_67 [ V_23 ] . V_22 )
F_30 ( V_2 ,
& V_2 -> V_67 [ V_23 ] ) ;
if ( V_2 -> V_82 != NULL ) {
if ( ! F_23 ( V_49 , V_2 -> V_83 ) ) {
F_27 ( & V_2 -> V_48 -> V_49 ,
V_2 -> V_83 ,
V_2 -> V_45 -> V_59 + V_60 ,
V_76 ) ;
V_2 -> V_83 = V_77 ;
}
F_12 ( V_2 -> V_82 ) ;
V_2 -> V_82 = NULL ;
}
}
static int F_39 ( struct V_1 * V_2 ,
union V_43 V_84 , T_2 V_85 )
{
int V_86 , V_87 = 1 ;
V_88:
V_86 = F_40 ( V_2 -> V_48 -> V_61 ,
V_2 -> V_75 , V_84 . V_44 ,
V_2 -> V_79 , V_85 ) ;
if ( V_86 != V_62 && V_87 ) {
do {
V_86 = F_41 ( V_2 -> V_48 -> V_61 ) ;
} while ( F_42 ( V_86 ) || ( V_86 == V_89 ) );
V_87 = 0 ;
goto V_88;
}
return V_86 ;
}
static T_2 F_43 ( T_3 * V_90 )
{
int V_23 ;
T_2 V_91 = 0 ;
for ( V_23 = 0 ; V_23 < V_92 ; V_23 ++ )
V_91 = ( V_91 << 8 ) | V_90 [ V_23 ] ;
return V_91 ;
}
static int F_44 ( struct V_93 * V_45 )
{
struct V_1 * V_2 = F_45 ( V_45 ) ;
T_2 V_85 ;
int V_94 = 1 ;
unsigned long V_42 ;
int V_86 ;
union V_43 V_84 ;
int V_23 ;
struct V_74 * V_49 ;
F_20 ( V_45 , L_4 ) ;
F_46 ( & V_2 -> V_95 ) ;
for( V_23 = 0 ; V_23 < V_66 ; V_23 ++ )
V_94 += V_2 -> V_67 [ V_23 ] . V_20 ;
V_2 -> V_69 = ( void * ) F_47 ( V_26 ) ;
V_2 -> V_78 = ( void * ) F_47 ( V_26 ) ;
if ( ! V_2 -> V_69 || ! V_2 -> V_78 ) {
F_48 ( V_45 , L_5
L_6 ) ;
V_86 = - V_96 ;
goto V_97;
}
V_49 = & V_2 -> V_48 -> V_49 ;
V_2 -> V_3 . V_80 = sizeof( struct V_98 ) *
V_94 ;
V_2 -> V_3 . V_4 =
F_49 ( V_49 , V_2 -> V_3 . V_80 ,
& V_2 -> V_3 . V_81 , V_26 ) ;
if ( ! V_2 -> V_3 . V_4 ) {
V_86 = - V_96 ;
goto V_97;
}
V_2 -> V_75 = F_22 ( V_49 ,
V_2 -> V_69 , 4096 , V_76 ) ;
V_2 -> V_79 = F_22 ( V_49 ,
V_2 -> V_78 , 4096 , V_76 ) ;
if ( ( F_23 ( V_49 , V_2 -> V_75 ) ) ||
( F_23 ( V_49 , V_2 -> V_79 ) ) ) {
F_48 ( V_45 , L_7
L_6 ) ;
V_86 = - V_96 ;
goto V_97;
}
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_73 = V_94 ;
V_2 -> V_3 . V_9 = 1 ;
V_85 = F_43 ( V_45 -> V_99 ) ;
V_84 . V_53 . V_54 = V_55 |
V_2 -> V_3 . V_80 ;
V_84 . V_53 . V_56 = V_2 -> V_3 . V_81 ;
F_20 ( V_45 , L_8 , V_2 -> V_69 ) ;
F_20 ( V_45 , L_9 , V_2 -> V_78 ) ;
F_20 ( V_45 , L_10 , V_2 -> V_3 . V_4 ) ;
F_50 ( V_2 -> V_48 -> V_61 , V_100 ) ;
V_42 = F_39 ( V_2 , V_84 , V_85 ) ;
if ( V_42 != V_62 ) {
F_48 ( V_45 , L_11 ,
V_42 ) ;
F_48 ( V_45 , L_12
L_13 ,
V_2 -> V_75 ,
V_2 -> V_79 ,
V_84 . V_44 ,
V_85 ) ;
V_86 = - V_101 ;
goto V_97;
}
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
if ( ! V_2 -> V_67 [ V_23 ] . V_22 )
continue;
if ( F_10 ( & V_2 -> V_67 [ V_23 ] ) ) {
F_48 ( V_45 , L_14 ) ;
V_2 -> V_67 [ V_23 ] . V_22 = 0 ;
V_86 = - V_96 ;
goto V_97;
}
}
F_20 ( V_45 , L_15 , V_45 -> V_102 ) ;
V_86 = F_51 ( V_45 -> V_102 , V_103 , 0 , V_45 -> V_104 ,
V_45 ) ;
if ( V_86 != 0 ) {
F_48 ( V_45 , L_16 ,
V_45 -> V_102 , V_86 ) ;
do {
V_42 = F_41 ( V_2 -> V_48 -> V_61 ) ;
} while ( F_42 ( V_42 ) || ( V_42 == V_89 ) );
goto V_97;
}
V_2 -> V_82 =
F_11 ( V_45 -> V_59 + V_60 , V_26 ) ;
if ( ! V_2 -> V_82 ) {
V_86 = - V_96 ;
goto V_105;
}
V_2 -> V_83 =
F_22 ( & V_2 -> V_48 -> V_49 , V_2 -> V_82 ,
V_45 -> V_59 + V_60 , V_76 ) ;
if ( F_23 ( V_49 , V_2 -> V_83 ) ) {
F_48 ( V_45 , L_17 ) ;
V_86 = - V_96 ;
goto V_105;
}
F_20 ( V_45 , L_18 ) ;
V_103 ( V_45 -> V_102 , V_45 ) ;
F_52 ( V_45 ) ;
F_20 ( V_45 , L_19 ) ;
return 0 ;
V_105:
F_53 ( V_45 -> V_102 , V_45 ) ;
V_97:
F_36 ( V_2 ) ;
F_54 ( & V_2 -> V_95 ) ;
return V_86 ;
}
static int F_55 ( struct V_93 * V_45 )
{
struct V_1 * V_2 = F_45 ( V_45 ) ;
long V_42 ;
F_20 ( V_45 , L_20 ) ;
F_54 ( & V_2 -> V_95 ) ;
if ( ! V_2 -> V_106 )
F_56 ( V_45 ) ;
F_50 ( V_2 -> V_48 -> V_61 , V_100 ) ;
do {
V_42 = F_41 ( V_2 -> V_48 -> V_61 ) ;
} while ( F_42 ( V_42 ) || ( V_42 == V_89 ) );
if ( V_42 != V_62 ) {
F_48 ( V_45 , L_21
L_22 , V_42 ) ;
}
F_53 ( V_45 -> V_102 , V_45 ) ;
V_2 -> V_68 = * ( T_2 * ) ( ( ( char * ) V_2 -> V_69 ) +
4096 - 8 ) ;
F_36 ( V_2 ) ;
F_20 ( V_45 , L_23 ) ;
return 0 ;
}
static int F_57 ( struct V_93 * V_49 , struct V_107 * V_108 )
{
V_108 -> V_109 = ( V_110 | V_111 |
V_112 ) ;
V_108 -> V_113 = ( V_114 | V_115 |
V_116 ) ;
F_58 ( V_108 , V_117 ) ;
V_108 -> V_118 = V_119 ;
V_108 -> V_120 = V_121 ;
V_108 -> V_122 = 0 ;
V_108 -> V_123 = V_124 ;
V_108 -> V_125 = V_126 ;
V_108 -> V_127 = 0 ;
V_108 -> V_128 = 1 ;
return 0 ;
}
static void F_59 ( struct V_93 * V_49 ,
struct V_129 * V_130 )
{
F_60 ( V_130 -> V_131 , V_132 , sizeof( V_130 -> V_131 ) ) ;
F_60 ( V_130 -> V_133 , V_134 , sizeof( V_130 -> V_133 ) ) ;
}
static T_4 F_61 ( struct V_93 * V_49 ,
T_4 V_135 )
{
if ( ! ( V_135 & V_136 ) )
V_135 &= ~ V_137 ;
return V_135 ;
}
static int F_62 ( struct V_93 * V_49 , T_1 V_50 )
{
struct V_1 * V_2 = F_45 ( V_49 ) ;
unsigned long V_138 , V_139 , V_140 ;
unsigned long V_141 , V_142 ;
long V_71 , V_143 , V_144 ;
int V_145 = 0 , V_146 = 0 ;
int V_147 = 0 ;
if ( F_63 ( V_49 ) ) {
V_147 = 1 ;
V_2 -> V_106 = 1 ;
F_55 ( V_49 ) ;
V_2 -> V_106 = 0 ;
}
V_138 = 0 ;
V_139 = 0 ;
V_141 = 0 ;
V_142 = 0 ;
if ( V_50 ) {
V_138 = V_148 ;
V_141 = V_149 ;
} else {
V_139 = V_148 ;
V_142 = V_149 ;
}
V_71 = F_64 ( V_2 -> V_48 -> V_61 , 0 , 0 , & V_140 ) ;
if ( V_71 == V_62 && ! ( V_140 & V_150 ) &&
! ( V_140 & V_151 ) &&
( V_140 & V_152 ) ) {
V_143 = F_64 ( V_2 -> V_48 -> V_61 , V_139 ,
V_138 , & V_140 ) ;
if ( V_143 != V_62 ) {
F_48 ( V_49 , L_24
L_25 ,
V_50 , V_143 ) ;
F_64 ( V_2 -> V_48 -> V_61 ,
V_138 , V_139 , & V_140 ) ;
if ( V_50 == 1 )
V_49 -> V_135 &= ~ V_153 ;
} else {
V_2 -> V_154 = V_50 ;
}
V_144 = F_64 ( V_2 -> V_48 -> V_61 ,
V_142 , V_141 , & V_140 ) ;
if ( V_144 != V_62 ) {
F_48 ( V_49 , L_26
L_25 ,
V_50 , V_144 ) ;
F_64 ( V_2 -> V_48 -> V_61 ,
V_141 , V_142 , & V_140 ) ;
if ( V_50 == 1 )
V_49 -> V_135 &= ~ V_155 ;
} else
V_2 -> V_156 = V_50 ;
if ( V_143 == V_62 || V_144 == V_62 )
V_2 -> V_157 = V_50 ;
else
V_145 = - V_158 ;
} else {
V_145 = - V_158 ;
F_48 ( V_49 , L_27
L_28 , V_50 , V_71 ,
V_140 ) ;
}
if ( V_147 )
V_146 = F_44 ( V_49 ) ;
return V_145 ? V_145 : V_146 ;
}
static int F_65 ( struct V_93 * V_49 ,
T_4 V_135 )
{
struct V_1 * V_2 = F_45 ( V_49 ) ;
int V_157 = ! ! ( V_135 & V_136 ) ;
int V_86 ;
if ( V_157 == V_2 -> V_157 )
return 0 ;
V_86 = F_62 ( V_49 , V_157 ) ;
if ( V_86 && ! V_2 -> V_157 )
V_49 -> V_135 = V_135 & ~ ( V_137 | V_136 ) ;
return V_86 ;
}
static void F_66 ( struct V_93 * V_49 , T_1 V_159 , T_3 * V_50 )
{
int V_23 ;
if ( V_159 != V_160 )
return;
for ( V_23 = 0 ; V_23 < F_67 ( V_161 ) ; V_23 ++ , V_50 += V_162 )
memcpy ( V_50 , V_161 [ V_23 ] . V_104 , V_162 ) ;
}
static int F_68 ( struct V_93 * V_49 , int V_163 )
{
switch ( V_163 ) {
case V_160 :
return F_67 ( V_161 ) ;
default:
return - V_164 ;
}
}
static void F_69 ( struct V_93 * V_49 ,
struct V_165 * V_166 , T_2 * V_50 )
{
int V_23 ;
struct V_1 * V_2 = F_45 ( V_49 ) ;
for ( V_23 = 0 ; V_23 < F_67 ( V_161 ) ; V_23 ++ )
V_50 [ V_23 ] = F_70 ( V_2 , V_161 [ V_23 ] . V_34 ) ;
}
static int F_71 ( struct V_93 * V_49 , struct V_167 * V_168 , int V_108 )
{
return - V_164 ;
}
static int F_72 ( struct V_1 * V_2 ,
union V_43 * V_169 )
{
unsigned long V_41 ;
unsigned int V_170 ;
unsigned long V_71 ;
V_170 = 1024 ;
V_41 = 0 ;
do {
V_71 = F_73 ( V_2 -> V_48 -> V_61 ,
V_169 [ 0 ] . V_44 , V_169 [ 1 ] . V_44 ,
V_169 [ 2 ] . V_44 , V_169 [ 3 ] . V_44 ,
V_169 [ 4 ] . V_44 , V_169 [ 5 ] . V_44 ,
V_41 , & V_41 ) ;
} while ( ( V_71 == V_89 ) && ( V_170 -- ) );
if ( V_71 != V_62 && V_71 != V_171 ) {
F_48 ( V_2 -> V_45 , L_29
L_30 , V_71 ) ;
return 1 ;
}
return 0 ;
}
static T_5 F_74 ( struct V_38 * V_39 ,
struct V_93 * V_45 )
{
struct V_1 * V_2 = F_45 ( V_45 ) ;
unsigned int V_172 ;
union V_43 V_169 [ 6 ] ;
int V_173 , V_23 ;
int V_174 = 0 ;
V_28 V_27 ;
if ( F_75 ( V_39 ) -> V_175 > 5 && F_76 ( V_39 ) ) {
V_45 -> V_166 . V_176 ++ ;
goto V_72;
}
if ( V_39 -> V_177 == V_178 &&
( ( V_39 -> V_179 == F_77 ( V_180 ) &&
F_78 ( V_39 ) -> V_179 != V_181 ) ||
( V_39 -> V_179 == F_77 ( V_182 ) &&
F_79 ( V_39 ) -> V_183 != V_181 ) ) &&
F_80 ( V_39 ) ) {
F_48 ( V_45 , L_31 ) ;
V_45 -> V_166 . V_176 ++ ;
goto V_72;
}
V_172 = V_55 ;
if ( V_39 -> V_177 == V_178 ) {
unsigned char * V_184 = F_81 ( V_39 ) +
V_39 -> V_185 ;
V_172 |= ( V_186 | V_187 ) ;
V_184 [ 0 ] = 0 ;
V_184 [ 1 ] = 0 ;
}
V_188:
memset ( V_169 , 0 , sizeof( V_169 ) ) ;
if ( V_174 || ( ! F_82 ( V_39 ) &&
( V_39 -> V_58 < V_189 ) ) ) {
F_83 ( V_39 , V_2 -> V_82 ,
V_39 -> V_58 ) ;
V_169 [ 0 ] . V_53 . V_54 = V_172 | V_39 -> V_58 ;
V_169 [ 0 ] . V_53 . V_56 = V_2 -> V_83 ;
if ( F_72 ( V_2 , V_169 ) ) {
V_2 -> V_190 ++ ;
V_45 -> V_166 . V_176 ++ ;
} else {
V_45 -> V_166 . V_191 ++ ;
V_45 -> V_166 . V_192 += V_39 -> V_58 ;
}
goto V_72;
}
V_27 = F_22 ( & V_2 -> V_48 -> V_49 , V_39 -> V_50 ,
F_84 ( V_39 ) , V_193 ) ;
if ( F_23 ( & V_2 -> V_48 -> V_49 , V_27 ) )
goto V_194;
V_169 [ 0 ] . V_53 . V_54 = V_172 | F_84 ( V_39 ) ;
V_169 [ 0 ] . V_53 . V_56 = V_27 ;
for ( V_23 = 0 ; V_23 < F_75 ( V_39 ) -> V_175 ; V_23 ++ ) {
const T_6 * V_195 = & F_75 ( V_39 ) -> V_196 [ V_23 ] ;
V_27 = F_85 ( & V_2 -> V_48 -> V_49 , V_195 , 0 ,
F_86 ( V_195 ) , V_193 ) ;
if ( F_23 ( & V_2 -> V_48 -> V_49 , V_27 ) )
goto V_197;
V_169 [ V_23 + 1 ] . V_53 . V_54 = V_172 | F_86 ( V_195 ) ;
V_169 [ V_23 + 1 ] . V_53 . V_56 = V_27 ;
}
if ( F_72 ( V_2 , V_169 ) ) {
V_2 -> V_190 ++ ;
V_45 -> V_166 . V_176 ++ ;
} else {
V_45 -> V_166 . V_191 ++ ;
V_45 -> V_166 . V_192 += V_39 -> V_58 ;
}
F_27 ( & V_2 -> V_48 -> V_49 ,
V_169 [ 0 ] . V_53 . V_56 ,
V_169 [ 0 ] . V_53 . V_54 & V_198 ,
V_193 ) ;
for ( V_23 = 1 ; V_23 < F_75 ( V_39 ) -> V_175 + 1 ; V_23 ++ )
F_87 ( & V_2 -> V_48 -> V_49 , V_169 [ V_23 ] . V_53 . V_56 ,
V_169 [ V_23 ] . V_53 . V_54 & V_198 ,
V_193 ) ;
V_72:
F_88 ( V_39 ) ;
return V_199 ;
V_197:
V_173 = V_23 + 1 ;
for ( V_23 = 0 ; V_23 < V_173 ; V_23 ++ )
F_87 ( & V_2 -> V_48 -> V_49 , V_169 [ V_23 ] . V_53 . V_56 ,
V_169 [ V_23 ] . V_53 . V_54 & V_198 ,
V_193 ) ;
V_194:
if ( ! F_89 ( V_200 ) )
F_48 ( V_45 , L_32 ) ;
V_2 -> V_201 ++ ;
F_90 ( V_39 ) ;
V_174 = 1 ;
goto V_188;
}
static int F_91 ( struct V_202 * V_95 , int V_203 )
{
struct V_1 * V_2 =
F_92 ( V_95 , struct V_1 , V_95 ) ;
struct V_93 * V_45 = V_2 -> V_45 ;
int V_204 = 0 ;
unsigned long V_42 ;
V_205:
while ( V_204 < V_203 ) {
if ( ! F_4 ( V_2 ) )
break;
F_93 () ;
if ( ! F_5 ( V_2 ) ) {
F_94 () ;
V_2 -> V_206 ++ ;
F_20 ( V_45 , L_33 ) ;
F_34 ( V_2 ) ;
} else {
struct V_38 * V_39 , * V_207 ;
int V_12 = F_7 ( V_2 ) ;
int V_34 = F_6 ( V_2 ) ;
int V_208 = F_8 ( V_2 ) ;
V_39 = F_33 ( V_2 ) ;
V_207 = NULL ;
if ( V_12 < V_209 )
V_207 = F_19 ( V_45 , V_12 ) ;
if ( V_207 ) {
F_95 ( V_207 ,
V_39 -> V_50 + V_34 ,
V_12 ) ;
if ( V_57 )
F_15 ( V_39 -> V_50 ,
V_12 + V_34 ) ;
if ( ! F_34 ( V_2 ) )
F_96 ( V_39 ) ;
V_39 = V_207 ;
} else {
F_35 ( V_2 ) ;
F_97 ( V_39 , V_34 ) ;
}
F_98 ( V_39 , V_12 ) ;
V_39 -> V_179 = F_99 ( V_39 , V_45 ) ;
if ( V_208 )
V_39 -> V_177 = V_210 ;
F_100 ( V_39 ) ;
V_45 -> V_166 . V_211 ++ ;
V_45 -> V_166 . V_212 += V_12 ;
V_204 ++ ;
}
}
F_29 ( V_2 ) ;
if ( V_204 < V_203 ) {
V_42 = F_50 ( V_2 -> V_48 -> V_61 ,
V_213 ) ;
F_21 ( V_42 != V_62 ) ;
F_101 ( V_95 ) ;
if ( F_4 ( V_2 ) &&
F_102 ( V_95 ) ) {
V_42 = F_50 ( V_2 -> V_48 -> V_61 ,
V_100 ) ;
goto V_205;
}
}
return V_204 ;
}
static T_7 V_103 ( int V_102 , void * V_214 )
{
struct V_93 * V_45 = V_214 ;
struct V_1 * V_2 = F_45 ( V_45 ) ;
unsigned long V_42 ;
if ( F_103 ( & V_2 -> V_95 ) ) {
V_42 = F_50 ( V_2 -> V_48 -> V_61 ,
V_100 ) ;
F_21 ( V_42 != V_62 ) ;
F_104 ( & V_2 -> V_95 ) ;
}
return V_215 ;
}
static void F_105 ( struct V_93 * V_45 )
{
struct V_1 * V_2 = F_45 ( V_45 ) ;
unsigned long V_42 ;
if ( ( V_45 -> V_216 & V_217 ) ||
( F_106 ( V_45 ) > V_2 -> V_218 ) ) {
V_42 = F_107 ( V_2 -> V_48 -> V_61 ,
V_219 |
V_220 ,
0 ) ;
if ( V_42 != V_62 ) {
F_48 ( V_45 , L_34
L_35 , V_42 ) ;
}
} else {
struct V_221 * V_222 ;
V_42 = F_107 ( V_2 -> V_48 -> V_61 ,
V_219 |
V_220 |
V_223 ,
0 ) ;
if ( V_42 != V_62 ) {
F_48 ( V_45 , L_34
L_36 ,
V_42 ) ;
}
F_108 (ha, netdev) {
T_2 V_224 ;
V_224 = F_43 ( V_222 -> V_33 ) ;
V_42 = F_107 ( V_2 -> V_48 -> V_61 ,
V_225 ,
V_224 ) ;
if ( V_42 != V_62 ) {
F_48 ( V_45 , L_37
L_38
L_39 , V_42 ) ;
}
}
V_42 = F_107 ( V_2 -> V_48 -> V_61 ,
V_226 ,
0 ) ;
if ( V_42 != V_62 ) {
F_48 ( V_45 , L_34
L_40 , V_42 ) ;
}
}
}
static int F_109 ( struct V_93 * V_49 , int V_227 )
{
struct V_1 * V_2 = F_45 ( V_49 ) ;
struct V_228 * V_229 = V_2 -> V_48 ;
int V_230 = V_227 + V_60 ;
int V_23 , V_86 ;
int V_231 = 0 ;
if ( V_227 < V_232 )
return - V_233 ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ )
if ( V_230 < V_2 -> V_67 [ V_23 ] . V_18 )
break;
if ( V_23 == V_66 )
return - V_233 ;
if ( F_63 ( V_2 -> V_45 ) ) {
V_231 = 1 ;
V_2 -> V_106 = 1 ;
F_55 ( V_2 -> V_45 ) ;
V_2 -> V_106 = 0 ;
}
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
V_2 -> V_67 [ V_23 ] . V_22 = 1 ;
if ( V_230 < V_2 -> V_67 [ V_23 ] . V_18 ) {
V_49 -> V_59 = V_227 ;
F_110 ( V_229 ,
F_111
( V_229 ) ) ;
if ( V_231 ) {
return F_44 ( V_2 -> V_45 ) ;
}
return 0 ;
}
}
if ( V_231 && ( V_86 = F_44 ( V_2 -> V_45 ) ) )
return V_86 ;
return - V_233 ;
}
static void F_112 ( struct V_93 * V_49 )
{
F_29 ( F_45 ( V_49 ) ) ;
V_103 ( V_49 -> V_102 , V_49 ) ;
}
static unsigned long F_111 ( struct V_228 * V_48 )
{
struct V_93 * V_45 = F_113 ( & V_48 -> V_49 ) ;
struct V_1 * V_2 ;
struct V_234 * V_235 ;
unsigned long V_71 ;
int V_23 ;
int V_236 = 1 ;
V_235 = F_114 ( & V_48 -> V_49 ) ;
if ( V_45 == NULL )
return F_115 ( V_237 , V_235 ) ;
V_2 = F_45 ( V_45 ) ;
V_71 = V_238 + V_239 ;
V_71 += F_115 ( V_45 -> V_59 , V_235 ) ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
if ( V_2 -> V_67 [ V_23 ] . V_22 )
V_71 +=
V_2 -> V_67 [ V_23 ] . V_20 *
F_115 ( V_2 -> V_67 [ V_23 ] .
V_18 , V_235 ) ;
V_236 += V_2 -> V_67 [ V_23 ] . V_20 ;
}
V_71 += F_115 (
V_236 * sizeof( struct V_98 ) , V_235 ) ;
return V_71 ;
}
static int F_116 ( struct V_228 * V_49 , const struct V_240 * V_241 )
{
int V_86 , V_23 , V_242 ;
struct V_93 * V_45 ;
struct V_1 * V_2 ;
unsigned char * V_243 ;
unsigned int * V_244 ;
F_117 ( & V_49 -> V_49 , L_41 ,
V_49 -> V_61 ) ;
V_243 = ( unsigned char * ) F_118 ( V_49 , V_245 ,
& V_242 ) ;
if ( ! V_243 ) {
F_119 ( & V_49 -> V_49 , L_42 ) ;
return - V_233 ;
}
if ( V_242 == 8 )
V_243 += 2 ;
else if ( V_242 != 6 ) {
F_119 ( & V_49 -> V_49 , L_43 ,
V_242 ) ;
return - V_233 ;
}
V_244 = ( unsigned int * ) F_118 ( V_49 ,
V_246 , NULL ) ;
if ( ! V_244 ) {
F_119 ( & V_49 -> V_49 , L_44
L_45 ) ;
return - V_233 ;
}
V_45 = F_120 ( sizeof( struct V_1 ) ) ;
if ( ! V_45 )
return - V_96 ;
V_2 = F_45 ( V_45 ) ;
F_121 ( & V_49 -> V_49 , V_45 ) ;
V_2 -> V_48 = V_49 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_218 = * V_244 ;
V_2 -> V_106 = 0 ;
F_122 ( V_45 , & V_2 -> V_95 , F_91 , 16 ) ;
V_45 -> V_102 = V_49 -> V_102 ;
V_45 -> V_247 = & V_248 ;
V_45 -> V_249 = & V_250 ;
F_123 ( V_45 , & V_49 -> V_49 ) ;
V_45 -> V_251 = V_252 | V_136 |
V_153 | V_155 ;
V_45 -> V_135 |= V_45 -> V_251 ;
memcpy ( V_45 -> V_99 , V_243 , V_92 ) ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
struct V_253 * V_254 = & V_2 -> V_67 [ V_23 ] . V_254 ;
int error ;
F_9 ( & V_2 -> V_67 [ V_23 ] , V_23 ,
V_255 [ V_23 ] , V_17 [ V_23 ] ,
V_19 [ V_23 ] ) ;
error = F_124 ( V_254 , & V_256 ,
& V_49 -> V_49 . V_254 , L_46 , V_23 ) ;
if ( ! error )
F_125 ( V_254 , V_257 ) ;
}
F_20 ( V_45 , L_47 , V_2 ) ;
V_2 -> V_75 = V_77 ;
V_2 -> V_79 = V_77 ;
V_2 -> V_3 . V_81 = V_77 ;
F_20 ( V_45 , L_48 ) ;
F_65 ( V_45 , V_45 -> V_135 ) ;
V_86 = F_126 ( V_45 ) ;
if ( V_86 ) {
F_20 ( V_45 , L_49 , V_86 ) ;
F_127 ( V_45 ) ;
return V_86 ;
}
F_20 ( V_45 , L_50 ) ;
return 0 ;
}
static int F_128 ( struct V_228 * V_49 )
{
struct V_93 * V_45 = F_113 ( & V_49 -> V_49 ) ;
struct V_1 * V_2 = F_45 ( V_45 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ )
F_129 ( & V_2 -> V_67 [ V_23 ] . V_254 ) ;
F_130 ( V_45 ) ;
F_127 ( V_45 ) ;
F_121 ( & V_49 -> V_49 , NULL ) ;
return 0 ;
}
static T_8 F_131 ( struct V_253 * V_254 ,
struct V_258 * V_259 , char * V_184 )
{
struct V_14 * V_15 = F_92 ( V_254 ,
struct V_14 ,
V_254 ) ;
if ( V_259 == & V_260 )
return sprintf ( V_184 , L_51 , V_15 -> V_22 ) ;
else if ( V_259 == & V_261 )
return sprintf ( V_184 , L_51 , V_15 -> V_20 ) ;
else if ( V_259 == & V_262 )
return sprintf ( V_184 , L_51 , V_15 -> V_18 ) ;
return 0 ;
}
static T_8 F_132 ( struct V_253 * V_254 , struct V_258 * V_259 ,
const char * V_184 , T_9 V_36 )
{
struct V_14 * V_15 = F_92 ( V_254 ,
struct V_14 ,
V_254 ) ;
struct V_93 * V_45 = F_113 (
F_92 ( V_254 -> V_263 , struct V_74 , V_254 ) ) ;
struct V_1 * V_2 = F_45 ( V_45 ) ;
long V_264 = F_133 ( V_184 , NULL , 10 ) ;
long V_86 ;
if ( V_259 == & V_260 ) {
if ( V_264 && ! V_15 -> V_22 ) {
if ( F_63 ( V_45 ) ) {
if ( F_10 ( V_15 ) ) {
F_48 ( V_45 ,
L_14 ) ;
return - V_96 ;
}
V_15 -> V_22 = 1 ;
V_2 -> V_106 = 1 ;
F_55 ( V_45 ) ;
V_2 -> V_106 = 0 ;
if ( ( V_86 = F_44 ( V_45 ) ) )
return V_86 ;
} else {
V_15 -> V_22 = 1 ;
}
} else if ( ! V_264 && V_15 -> V_22 ) {
int V_59 = V_45 -> V_59 + V_60 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
if ( V_15 == & V_2 -> V_67 [ V_23 ] )
continue;
if ( ! V_2 -> V_67 [ V_23 ] . V_22 )
continue;
if ( V_59 <= V_2 -> V_67 [ V_23 ] . V_18 )
break;
}
if ( V_23 == V_66 ) {
F_48 ( V_45 , L_52 ) ;
return - V_265 ;
}
if ( F_63 ( V_45 ) ) {
V_2 -> V_106 = 1 ;
F_55 ( V_45 ) ;
V_15 -> V_22 = 0 ;
V_2 -> V_106 = 0 ;
if ( ( V_86 = F_44 ( V_45 ) ) )
return V_86 ;
}
V_15 -> V_22 = 0 ;
}
} else if ( V_259 == & V_261 ) {
if ( V_264 <= 0 || V_264 > V_266 ) {
return - V_233 ;
} else {
if ( F_63 ( V_45 ) ) {
V_2 -> V_106 = 1 ;
F_55 ( V_45 ) ;
V_2 -> V_106 = 0 ;
V_15 -> V_20 = V_264 ;
if ( ( V_86 = F_44 ( V_45 ) ) )
return V_86 ;
} else {
V_15 -> V_20 = V_264 ;
}
}
} else if ( V_259 == & V_262 ) {
if ( V_264 <= V_60 || V_264 > V_267 ) {
return - V_233 ;
} else {
if ( F_63 ( V_45 ) ) {
V_2 -> V_106 = 1 ;
F_55 ( V_45 ) ;
V_2 -> V_106 = 0 ;
V_15 -> V_18 = V_264 ;
if ( ( V_86 = F_44 ( V_45 ) ) )
return V_86 ;
} else {
V_15 -> V_18 = V_264 ;
}
}
}
V_103 ( V_45 -> V_102 , V_45 ) ;
return V_36 ;
}
static int F_134 ( struct V_74 * V_49 )
{
struct V_93 * V_45 = F_113 ( V_49 ) ;
V_103 ( V_45 -> V_102 , V_45 ) ;
return 0 ;
}
static int T_10 F_135 ( void )
{
F_136 ( V_268 L_53 , V_132 ,
V_269 , V_134 ) ;
return F_137 ( & V_270 ) ;
}
static void T_11 F_138 ( void )
{
F_139 ( & V_270 ) ;
}
