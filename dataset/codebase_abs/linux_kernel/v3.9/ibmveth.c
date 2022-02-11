static inline T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_6 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return ( F_1 ( V_2 ) & V_7 ) >>
V_8 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) == V_2 -> V_3 . V_9 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) & V_10 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) & V_11 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_12 ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) & V_13 ;
}
static void F_8 ( struct V_14 * V_15 ,
T_1 V_16 , T_1 V_17 ,
T_1 V_18 , T_1 V_19 )
{
V_15 -> V_20 = V_17 ;
V_15 -> V_5 = V_16 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_21 = V_17 * 7 / 8 ;
V_15 -> V_22 = V_19 ;
}
static int F_9 ( struct V_14 * V_15 )
{
int V_23 ;
V_15 -> V_24 = F_10 ( sizeof( V_25 ) * V_15 -> V_20 , V_26 ) ;
if ( ! V_15 -> V_24 )
return - 1 ;
V_15 -> V_27 = F_10 ( sizeof( V_28 ) * V_15 -> V_20 , V_26 ) ;
if ( ! V_15 -> V_27 ) {
F_11 ( V_15 -> V_24 ) ;
V_15 -> V_24 = NULL ;
return - 1 ;
}
V_15 -> V_29 = F_12 ( V_15 -> V_20 , sizeof( void * ) , V_26 ) ;
if ( ! V_15 -> V_29 ) {
F_11 ( V_15 -> V_27 ) ;
V_15 -> V_27 = NULL ;
F_11 ( V_15 -> V_24 ) ;
V_15 -> V_24 = NULL ;
return - 1 ;
}
memset ( V_15 -> V_27 , 0 , sizeof( V_28 ) * V_15 -> V_20 ) ;
for ( V_23 = 0 ; V_23 < V_15 -> V_20 ; ++ V_23 )
V_15 -> V_24 [ V_23 ] = V_23 ;
F_13 ( & V_15 -> V_30 , 0 ) ;
V_15 -> V_31 = 0 ;
V_15 -> V_32 = 0 ;
return 0 ;
}
static inline void F_14 ( void * V_33 , unsigned long V_12 )
{
unsigned long V_34 ;
for ( V_34 = 0 ; V_34 < V_12 ; V_34 += V_35 )
asm("dcbfl %0,%1" :: "b" (addr), "r" (offset));
}
static void F_15 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
T_1 V_23 ;
T_1 V_36 = V_15 -> V_20 - F_16 ( & V_15 -> V_30 ) ;
T_1 V_37 = 0 ;
struct V_38 * V_39 ;
unsigned int V_40 , V_5 ;
T_2 V_41 ;
unsigned long V_42 ;
V_28 V_27 ;
F_17 () ;
for ( V_23 = 0 ; V_23 < V_36 ; ++ V_23 ) {
union V_43 V_44 ;
V_39 = F_18 ( V_2 -> V_45 , V_15 -> V_18 ) ;
if ( ! V_39 ) {
F_19 ( V_2 -> V_45 ,
L_1 ) ;
V_2 -> V_46 ++ ;
break;
}
V_40 = V_15 -> V_32 ;
V_15 -> V_32 ++ ;
if ( V_15 -> V_32 >= V_15 -> V_20 )
V_15 -> V_32 = 0 ;
V_5 = V_15 -> V_24 [ V_40 ] ;
F_20 ( V_5 == V_47 ) ;
F_20 ( V_15 -> V_29 [ V_5 ] != NULL ) ;
V_27 = F_21 ( & V_2 -> V_48 -> V_49 , V_39 -> V_50 ,
V_15 -> V_18 , V_51 ) ;
if ( F_22 ( & V_2 -> V_48 -> V_49 , V_27 ) )
goto V_52;
V_15 -> V_24 [ V_40 ] = V_47 ;
V_15 -> V_27 [ V_5 ] = V_27 ;
V_15 -> V_29 [ V_5 ] = V_39 ;
V_41 = ( ( T_2 ) V_15 -> V_5 << 32 ) | V_5 ;
* ( T_2 * ) V_39 -> V_50 = V_41 ;
V_44 . V_53 . V_54 = V_55 | V_15 -> V_18 ;
V_44 . V_53 . V_56 = V_27 ;
if ( V_57 ) {
unsigned int V_58 = F_23 ( V_15 -> V_18 ,
V_2 -> V_45 -> V_59 +
V_60 ) ;
F_14 ( V_39 -> V_50 , V_58 ) ;
}
V_42 = F_24 ( V_2 -> V_48 -> V_61 ,
V_44 . V_44 ) ;
if ( V_42 != V_62 ) {
goto V_52;
} else {
V_37 ++ ;
V_2 -> V_63 ++ ;
}
}
F_17 () ;
F_25 ( V_37 , & ( V_15 -> V_30 ) ) ;
return;
V_52:
V_15 -> V_24 [ V_40 ] = V_5 ;
V_15 -> V_29 [ V_5 ] = NULL ;
if ( V_15 -> V_32 == 0 )
V_15 -> V_32 = V_15 -> V_20 - 1 ;
else
V_15 -> V_32 -- ;
if ( ! F_22 ( & V_2 -> V_48 -> V_49 , V_27 ) )
F_26 ( & V_2 -> V_48 -> V_49 ,
V_15 -> V_27 [ V_5 ] , V_15 -> V_18 ,
V_51 ) ;
F_27 ( V_39 ) ;
V_2 -> V_64 ++ ;
F_17 () ;
F_25 ( V_37 , & ( V_15 -> V_30 ) ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
int V_23 ;
V_2 -> V_65 ++ ;
for ( V_23 = ( V_66 - 1 ) ; V_23 >= 0 ; V_23 -- ) {
struct V_14 * V_15 = & V_2 -> V_67 [ V_23 ] ;
if ( V_15 -> V_22 &&
( F_16 ( & V_15 -> V_30 ) < V_15 -> V_21 ) )
F_15 ( V_2 , V_15 ) ;
}
V_2 -> V_68 = * ( T_2 * ) ( ( ( char * ) V_2 -> V_69 ) +
4096 - 8 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_23 ;
F_11 ( V_15 -> V_24 ) ;
V_15 -> V_24 = NULL ;
if ( V_15 -> V_29 && V_15 -> V_27 ) {
for ( V_23 = 0 ; V_23 < V_15 -> V_20 ; ++ V_23 ) {
struct V_38 * V_39 = V_15 -> V_29 [ V_23 ] ;
if ( V_39 ) {
F_26 ( & V_2 -> V_48 -> V_49 ,
V_15 -> V_27 [ V_23 ] ,
V_15 -> V_18 ,
V_51 ) ;
F_27 ( V_39 ) ;
V_15 -> V_29 [ V_23 ] = NULL ;
}
}
}
if ( V_15 -> V_27 ) {
F_11 ( V_15 -> V_27 ) ;
V_15 -> V_27 = NULL ;
}
if ( V_15 -> V_29 ) {
F_11 ( V_15 -> V_29 ) ;
V_15 -> V_29 = NULL ;
}
}
static void F_30 ( struct V_1 * V_2 ,
T_2 V_41 )
{
unsigned int V_15 = V_41 >> 32 ;
unsigned int V_5 = V_41 & 0xffffffffUL ;
unsigned int V_40 ;
struct V_38 * V_39 ;
F_20 ( V_15 >= V_66 ) ;
F_20 ( V_5 >= V_2 -> V_67 [ V_15 ] . V_20 ) ;
V_39 = V_2 -> V_67 [ V_15 ] . V_29 [ V_5 ] ;
F_20 ( V_39 == NULL ) ;
V_2 -> V_67 [ V_15 ] . V_29 [ V_5 ] = NULL ;
F_26 ( & V_2 -> V_48 -> V_49 ,
V_2 -> V_67 [ V_15 ] . V_27 [ V_5 ] ,
V_2 -> V_67 [ V_15 ] . V_18 ,
V_51 ) ;
V_40 = V_2 -> V_67 [ V_15 ] . V_31 ;
V_2 -> V_67 [ V_15 ] . V_31 ++ ;
if ( V_2 -> V_67 [ V_15 ] . V_31 >=
V_2 -> V_67 [ V_15 ] . V_20 )
V_2 -> V_67 [ V_15 ] . V_31 = 0 ;
V_2 -> V_67 [ V_15 ] . V_24 [ V_40 ] = V_5 ;
F_17 () ;
F_31 ( & ( V_2 -> V_67 [ V_15 ] . V_30 ) ) ;
}
static inline struct V_38 * F_32 ( struct V_1 * V_2 )
{
T_2 V_41 = V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_41 ;
unsigned int V_15 = V_41 >> 32 ;
unsigned int V_5 = V_41 & 0xffffffffUL ;
F_20 ( V_15 >= V_66 ) ;
F_20 ( V_5 >= V_2 -> V_67 [ V_15 ] . V_20 ) ;
return V_2 -> V_67 [ V_15 ] . V_29 [ V_5 ] ;
}
static int F_33 ( struct V_1 * V_2 )
{
T_1 V_70 = V_2 -> V_3 . V_5 ;
T_2 V_41 = V_2 -> V_3 . V_4 [ V_70 ] . V_41 ;
unsigned int V_15 = V_41 >> 32 ;
unsigned int V_5 = V_41 & 0xffffffffUL ;
union V_43 V_44 ;
unsigned long V_42 ;
int V_71 = 1 ;
F_20 ( V_15 >= V_66 ) ;
F_20 ( V_5 >= V_2 -> V_67 [ V_15 ] . V_20 ) ;
if ( ! V_2 -> V_67 [ V_15 ] . V_22 ) {
F_34 ( V_2 ) ;
F_29 ( V_2 , & V_2 -> V_67 [ V_15 ] ) ;
goto V_72;
}
V_44 . V_53 . V_54 = V_55 |
V_2 -> V_67 [ V_15 ] . V_18 ;
V_44 . V_53 . V_56 = V_2 -> V_67 [ V_15 ] . V_27 [ V_5 ] ;
V_42 = F_24 ( V_2 -> V_48 -> V_61 , V_44 . V_44 ) ;
if ( V_42 != V_62 ) {
F_19 ( V_2 -> V_45 , L_2
L_3 , V_42 ) ;
F_30 ( V_2 , V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_41 ) ;
V_71 = 0 ;
}
if ( ++ V_2 -> V_3 . V_5 == V_2 -> V_3 . V_73 ) {
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_9 = ! V_2 -> V_3 . V_9 ;
}
V_72:
return V_71 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_41 ) ;
if ( ++ V_2 -> V_3 . V_5 == V_2 -> V_3 . V_73 ) {
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_9 = ! V_2 -> V_3 . V_9 ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
int V_23 ;
struct V_74 * V_49 = & V_2 -> V_48 -> V_49 ;
if ( V_2 -> V_69 != NULL ) {
if ( ! F_22 ( V_49 , V_2 -> V_75 ) ) {
F_26 ( V_49 , V_2 -> V_75 , 4096 ,
V_76 ) ;
V_2 -> V_75 = V_77 ;
}
F_36 ( ( unsigned long ) V_2 -> V_69 ) ;
V_2 -> V_69 = NULL ;
}
if ( V_2 -> V_78 != NULL ) {
if ( ! F_22 ( V_49 , V_2 -> V_79 ) ) {
F_26 ( V_49 , V_2 -> V_79 , 4096 ,
V_76 ) ;
V_2 -> V_79 = V_77 ;
}
F_36 ( ( unsigned long ) V_2 -> V_78 ) ;
V_2 -> V_78 = NULL ;
}
if ( V_2 -> V_3 . V_4 != NULL ) {
F_37 ( V_49 , V_2 -> V_3 . V_80 ,
V_2 -> V_3 . V_4 ,
V_2 -> V_3 . V_81 ) ;
V_2 -> V_3 . V_4 = NULL ;
}
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ )
if ( V_2 -> V_67 [ V_23 ] . V_22 )
F_29 ( V_2 ,
& V_2 -> V_67 [ V_23 ] ) ;
if ( V_2 -> V_82 != NULL ) {
if ( ! F_22 ( V_49 , V_2 -> V_83 ) ) {
F_26 ( & V_2 -> V_48 -> V_49 ,
V_2 -> V_83 ,
V_2 -> V_45 -> V_59 + V_60 ,
V_76 ) ;
V_2 -> V_83 = V_77 ;
}
F_11 ( V_2 -> V_82 ) ;
V_2 -> V_82 = NULL ;
}
}
static int F_38 ( struct V_1 * V_2 ,
union V_43 V_84 , T_2 V_85 )
{
int V_86 , V_87 = 1 ;
V_88:
V_86 = F_39 ( V_2 -> V_48 -> V_61 ,
V_2 -> V_75 , V_84 . V_44 ,
V_2 -> V_79 , V_85 ) ;
if ( V_86 != V_62 && V_87 ) {
do {
V_86 = F_40 ( V_2 -> V_48 -> V_61 ) ;
} while ( F_41 ( V_86 ) || ( V_86 == V_89 ) );
V_87 = 0 ;
goto V_88;
}
return V_86 ;
}
static int F_42 ( struct V_90 * V_45 )
{
struct V_1 * V_2 = F_43 ( V_45 ) ;
T_2 V_85 = 0 ;
int V_91 = 1 ;
unsigned long V_42 ;
int V_86 ;
union V_43 V_84 ;
int V_23 ;
struct V_74 * V_49 ;
F_19 ( V_45 , L_4 ) ;
F_44 ( & V_2 -> V_92 ) ;
for( V_23 = 0 ; V_23 < V_66 ; V_23 ++ )
V_91 += V_2 -> V_67 [ V_23 ] . V_20 ;
V_2 -> V_69 = ( void * ) F_45 ( V_26 ) ;
V_2 -> V_78 = ( void * ) F_45 ( V_26 ) ;
if ( ! V_2 -> V_69 || ! V_2 -> V_78 ) {
F_46 ( V_45 , L_5
L_6 ) ;
V_86 = - V_93 ;
goto V_94;
}
V_49 = & V_2 -> V_48 -> V_49 ;
V_2 -> V_3 . V_80 = sizeof( struct V_95 ) *
V_91 ;
V_2 -> V_3 . V_4 =
F_47 ( V_49 , V_2 -> V_3 . V_80 ,
& V_2 -> V_3 . V_81 , V_26 ) ;
if ( ! V_2 -> V_3 . V_4 ) {
F_46 ( V_45 , L_7 ) ;
V_86 = - V_93 ;
goto V_94;
}
V_2 -> V_75 = F_21 ( V_49 ,
V_2 -> V_69 , 4096 , V_76 ) ;
V_2 -> V_79 = F_21 ( V_49 ,
V_2 -> V_78 , 4096 , V_76 ) ;
if ( ( F_22 ( V_49 , V_2 -> V_75 ) ) ||
( F_22 ( V_49 , V_2 -> V_79 ) ) ) {
F_46 ( V_45 , L_8
L_6 ) ;
V_86 = - V_93 ;
goto V_94;
}
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_73 = V_91 ;
V_2 -> V_3 . V_9 = 1 ;
memcpy ( & V_85 , V_45 -> V_96 , V_45 -> V_97 ) ;
V_85 = V_85 >> 16 ;
V_84 . V_53 . V_54 = V_55 |
V_2 -> V_3 . V_80 ;
V_84 . V_53 . V_56 = V_2 -> V_3 . V_81 ;
F_19 ( V_45 , L_9 , V_2 -> V_69 ) ;
F_19 ( V_45 , L_10 , V_2 -> V_78 ) ;
F_19 ( V_45 , L_11 , V_2 -> V_3 . V_4 ) ;
F_48 ( V_2 -> V_48 -> V_61 , V_98 ) ;
V_42 = F_38 ( V_2 , V_84 , V_85 ) ;
if ( V_42 != V_62 ) {
F_46 ( V_45 , L_12 ,
V_42 ) ;
F_46 ( V_45 , L_13
L_14 ,
V_2 -> V_75 ,
V_2 -> V_79 ,
V_84 . V_44 ,
V_85 ) ;
V_86 = - V_99 ;
goto V_94;
}
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
if ( ! V_2 -> V_67 [ V_23 ] . V_22 )
continue;
if ( F_9 ( & V_2 -> V_67 [ V_23 ] ) ) {
F_46 ( V_45 , L_15 ) ;
V_2 -> V_67 [ V_23 ] . V_22 = 0 ;
V_86 = - V_93 ;
goto V_94;
}
}
F_19 ( V_45 , L_16 , V_45 -> V_100 ) ;
V_86 = F_49 ( V_45 -> V_100 , V_101 , 0 , V_45 -> V_102 ,
V_45 ) ;
if ( V_86 != 0 ) {
F_46 ( V_45 , L_17 ,
V_45 -> V_100 , V_86 ) ;
do {
V_42 = F_40 ( V_2 -> V_48 -> V_61 ) ;
} while ( F_41 ( V_42 ) || ( V_42 == V_89 ) );
goto V_94;
}
V_2 -> V_82 =
F_10 ( V_45 -> V_59 + V_60 , V_26 ) ;
if ( ! V_2 -> V_82 ) {
V_86 = - V_93 ;
goto V_103;
}
V_2 -> V_83 =
F_21 ( & V_2 -> V_48 -> V_49 , V_2 -> V_82 ,
V_45 -> V_59 + V_60 , V_76 ) ;
if ( F_22 ( V_49 , V_2 -> V_83 ) ) {
F_46 ( V_45 , L_18 ) ;
V_86 = - V_93 ;
goto V_103;
}
F_19 ( V_45 , L_19 ) ;
V_101 ( V_45 -> V_100 , V_45 ) ;
F_50 ( V_45 ) ;
F_19 ( V_45 , L_20 ) ;
return 0 ;
V_103:
F_51 ( V_45 -> V_100 , V_45 ) ;
V_94:
F_35 ( V_2 ) ;
F_52 ( & V_2 -> V_92 ) ;
return V_86 ;
}
static int F_53 ( struct V_90 * V_45 )
{
struct V_1 * V_2 = F_43 ( V_45 ) ;
long V_42 ;
F_19 ( V_45 , L_21 ) ;
F_52 ( & V_2 -> V_92 ) ;
if ( ! V_2 -> V_104 )
F_54 ( V_45 ) ;
F_48 ( V_2 -> V_48 -> V_61 , V_98 ) ;
do {
V_42 = F_40 ( V_2 -> V_48 -> V_61 ) ;
} while ( F_41 ( V_42 ) || ( V_42 == V_89 ) );
if ( V_42 != V_62 ) {
F_46 ( V_45 , L_22
L_23 , V_42 ) ;
}
F_51 ( V_45 -> V_100 , V_45 ) ;
V_2 -> V_68 = * ( T_2 * ) ( ( ( char * ) V_2 -> V_69 ) +
4096 - 8 ) ;
F_35 ( V_2 ) ;
F_19 ( V_45 , L_24 ) ;
return 0 ;
}
static int F_55 ( struct V_90 * V_49 , struct V_105 * V_106 )
{
V_106 -> V_107 = ( V_108 | V_109 |
V_110 ) ;
V_106 -> V_111 = ( V_112 | V_113 |
V_114 ) ;
F_56 ( V_106 , V_115 ) ;
V_106 -> V_116 = V_117 ;
V_106 -> V_118 = V_119 ;
V_106 -> V_120 = 0 ;
V_106 -> V_121 = V_122 ;
V_106 -> V_123 = V_124 ;
V_106 -> V_125 = 0 ;
V_106 -> V_126 = 1 ;
return 0 ;
}
static void F_57 ( struct V_90 * V_49 ,
struct V_127 * V_128 )
{
F_58 ( V_128 -> V_129 , V_130 , sizeof( V_128 -> V_129 ) ) ;
F_58 ( V_128 -> V_131 , V_132 , sizeof( V_128 -> V_131 ) ) ;
}
static T_3 F_59 ( struct V_90 * V_49 ,
T_3 V_133 )
{
if ( ! ( V_133 & V_134 ) )
V_133 &= ~ V_135 ;
return V_133 ;
}
static int F_60 ( struct V_90 * V_49 , T_1 V_50 )
{
struct V_1 * V_2 = F_43 ( V_49 ) ;
unsigned long V_136 , V_137 , V_138 ;
unsigned long V_139 , V_140 ;
long V_71 , V_141 , V_142 ;
int V_143 = 0 , V_144 = 0 ;
int V_145 = 0 ;
if ( F_61 ( V_49 ) ) {
V_145 = 1 ;
V_2 -> V_104 = 1 ;
F_53 ( V_49 ) ;
V_2 -> V_104 = 0 ;
}
V_136 = 0 ;
V_137 = 0 ;
V_139 = 0 ;
V_140 = 0 ;
if ( V_50 ) {
V_136 = V_146 ;
V_139 = V_147 ;
} else {
V_137 = V_146 ;
V_140 = V_147 ;
}
V_71 = F_62 ( V_2 -> V_48 -> V_61 , 0 , 0 , & V_138 ) ;
if ( V_71 == V_62 && ! ( V_138 & V_148 ) &&
! ( V_138 & V_149 ) &&
( V_138 & V_150 ) ) {
V_141 = F_62 ( V_2 -> V_48 -> V_61 , V_137 ,
V_136 , & V_138 ) ;
if ( V_141 != V_62 ) {
F_46 ( V_49 , L_25
L_26 ,
V_50 , V_141 ) ;
F_62 ( V_2 -> V_48 -> V_61 ,
V_136 , V_137 , & V_138 ) ;
if ( V_50 == 1 )
V_49 -> V_133 &= ~ V_151 ;
} else {
V_2 -> V_152 = V_50 ;
}
V_142 = F_62 ( V_2 -> V_48 -> V_61 ,
V_140 , V_139 , & V_138 ) ;
if ( V_142 != V_62 ) {
F_46 ( V_49 , L_27
L_26 ,
V_50 , V_142 ) ;
F_62 ( V_2 -> V_48 -> V_61 ,
V_139 , V_140 , & V_138 ) ;
if ( V_50 == 1 )
V_49 -> V_133 &= ~ V_153 ;
} else
V_2 -> V_154 = V_50 ;
if ( V_141 == V_62 || V_142 == V_62 )
V_2 -> V_155 = V_50 ;
else
V_143 = - V_156 ;
} else {
V_143 = - V_156 ;
F_46 ( V_49 , L_28
L_29 , V_50 , V_71 ,
V_138 ) ;
}
if ( V_145 )
V_144 = F_42 ( V_49 ) ;
return V_143 ? V_143 : V_144 ;
}
static int F_63 ( struct V_90 * V_49 ,
T_3 V_133 )
{
struct V_1 * V_2 = F_43 ( V_49 ) ;
int V_155 = ! ! ( V_133 & V_134 ) ;
int V_86 ;
if ( V_155 == V_2 -> V_155 )
return 0 ;
V_86 = F_60 ( V_49 , V_155 ) ;
if ( V_86 && ! V_2 -> V_155 )
V_49 -> V_133 = V_133 & ~ ( V_135 | V_134 ) ;
return V_86 ;
}
static void F_64 ( struct V_90 * V_49 , T_1 V_157 , T_4 * V_50 )
{
int V_23 ;
if ( V_157 != V_158 )
return;
for ( V_23 = 0 ; V_23 < F_65 ( V_159 ) ; V_23 ++ , V_50 += V_160 )
memcpy ( V_50 , V_159 [ V_23 ] . V_102 , V_160 ) ;
}
static int F_66 ( struct V_90 * V_49 , int V_161 )
{
switch ( V_161 ) {
case V_158 :
return F_65 ( V_159 ) ;
default:
return - V_162 ;
}
}
static void F_67 ( struct V_90 * V_49 ,
struct V_163 * V_164 , T_2 * V_50 )
{
int V_23 ;
struct V_1 * V_2 = F_43 ( V_49 ) ;
for ( V_23 = 0 ; V_23 < F_65 ( V_159 ) ; V_23 ++ )
V_50 [ V_23 ] = F_68 ( V_2 , V_159 [ V_23 ] . V_34 ) ;
}
static int F_69 ( struct V_90 * V_49 , struct V_165 * V_166 , int V_106 )
{
return - V_162 ;
}
static int F_70 ( struct V_1 * V_2 ,
union V_43 * V_167 )
{
unsigned long V_41 ;
unsigned int V_168 ;
unsigned long V_71 ;
V_168 = 1024 ;
V_41 = 0 ;
do {
V_71 = F_71 ( V_2 -> V_48 -> V_61 ,
V_167 [ 0 ] . V_44 , V_167 [ 1 ] . V_44 ,
V_167 [ 2 ] . V_44 , V_167 [ 3 ] . V_44 ,
V_167 [ 4 ] . V_44 , V_167 [ 5 ] . V_44 ,
V_41 , & V_41 ) ;
} while ( ( V_71 == V_89 ) && ( V_168 -- ) );
if ( V_71 != V_62 && V_71 != V_169 ) {
F_46 ( V_2 -> V_45 , L_30
L_31 , V_71 ) ;
return 1 ;
}
return 0 ;
}
static T_5 F_72 ( struct V_38 * V_39 ,
struct V_90 * V_45 )
{
struct V_1 * V_2 = F_43 ( V_45 ) ;
unsigned int V_170 ;
union V_43 V_167 [ 6 ] ;
int V_171 , V_23 ;
int V_172 = 0 ;
V_28 V_27 ;
if ( F_73 ( V_39 ) -> V_173 > 5 && F_74 ( V_39 ) ) {
V_45 -> V_164 . V_174 ++ ;
goto V_72;
}
if ( V_39 -> V_175 == V_176 &&
( ( V_39 -> V_177 == F_75 ( V_178 ) &&
F_76 ( V_39 ) -> V_177 != V_179 ) ||
( V_39 -> V_177 == F_75 ( V_180 ) &&
F_77 ( V_39 ) -> V_181 != V_179 ) ) &&
F_78 ( V_39 ) ) {
F_46 ( V_45 , L_32 ) ;
V_45 -> V_164 . V_174 ++ ;
goto V_72;
}
V_170 = V_55 ;
if ( V_39 -> V_175 == V_176 ) {
unsigned char * V_182 = F_79 ( V_39 ) +
V_39 -> V_183 ;
V_170 |= ( V_184 | V_185 ) ;
V_182 [ 0 ] = 0 ;
V_182 [ 1 ] = 0 ;
}
V_186:
memset ( V_167 , 0 , sizeof( V_167 ) ) ;
if ( V_172 || ( ! F_80 ( V_39 ) &&
( V_39 -> V_58 < V_187 ) ) ) {
F_81 ( V_39 , V_2 -> V_82 ,
V_39 -> V_58 ) ;
V_167 [ 0 ] . V_53 . V_54 = V_170 | V_39 -> V_58 ;
V_167 [ 0 ] . V_53 . V_56 = V_2 -> V_83 ;
if ( F_70 ( V_2 , V_167 ) ) {
V_2 -> V_188 ++ ;
V_45 -> V_164 . V_174 ++ ;
} else {
V_45 -> V_164 . V_189 ++ ;
V_45 -> V_164 . V_190 += V_39 -> V_58 ;
}
goto V_72;
}
V_27 = F_21 ( & V_2 -> V_48 -> V_49 , V_39 -> V_50 ,
F_82 ( V_39 ) , V_191 ) ;
if ( F_22 ( & V_2 -> V_48 -> V_49 , V_27 ) )
goto V_192;
V_167 [ 0 ] . V_53 . V_54 = V_170 | F_82 ( V_39 ) ;
V_167 [ 0 ] . V_53 . V_56 = V_27 ;
for ( V_23 = 0 ; V_23 < F_73 ( V_39 ) -> V_173 ; V_23 ++ ) {
const T_6 * V_193 = & F_73 ( V_39 ) -> V_194 [ V_23 ] ;
V_27 = F_83 ( & V_2 -> V_48 -> V_49 , V_193 , 0 ,
F_84 ( V_193 ) , V_191 ) ;
if ( F_22 ( & V_2 -> V_48 -> V_49 , V_27 ) )
goto V_195;
V_167 [ V_23 + 1 ] . V_53 . V_54 = V_170 | F_84 ( V_193 ) ;
V_167 [ V_23 + 1 ] . V_53 . V_56 = V_27 ;
}
if ( F_70 ( V_2 , V_167 ) ) {
V_2 -> V_188 ++ ;
V_45 -> V_164 . V_174 ++ ;
} else {
V_45 -> V_164 . V_189 ++ ;
V_45 -> V_164 . V_190 += V_39 -> V_58 ;
}
F_26 ( & V_2 -> V_48 -> V_49 ,
V_167 [ 0 ] . V_53 . V_56 ,
V_167 [ 0 ] . V_53 . V_54 & V_196 ,
V_191 ) ;
for ( V_23 = 1 ; V_23 < F_73 ( V_39 ) -> V_173 + 1 ; V_23 ++ )
F_85 ( & V_2 -> V_48 -> V_49 , V_167 [ V_23 ] . V_53 . V_56 ,
V_167 [ V_23 ] . V_53 . V_54 & V_196 ,
V_191 ) ;
V_72:
F_86 ( V_39 ) ;
return V_197 ;
V_195:
V_171 = V_23 + 1 ;
for ( V_23 = 0 ; V_23 < V_171 ; V_23 ++ )
F_85 ( & V_2 -> V_48 -> V_49 , V_167 [ V_23 ] . V_53 . V_56 ,
V_167 [ V_23 ] . V_53 . V_54 & V_196 ,
V_191 ) ;
V_192:
if ( ! F_87 ( V_198 ) )
F_46 ( V_45 , L_33 ) ;
V_2 -> V_199 ++ ;
F_88 ( V_39 ) ;
V_172 = 1 ;
goto V_186;
}
static int F_89 ( struct V_200 * V_92 , int V_201 )
{
struct V_1 * V_2 =
F_90 ( V_92 , struct V_1 , V_92 ) ;
struct V_90 * V_45 = V_2 -> V_45 ;
int V_202 = 0 ;
unsigned long V_42 ;
V_203:
do {
if ( ! F_3 ( V_2 ) )
break;
F_91 () ;
if ( ! F_4 ( V_2 ) ) {
F_92 () ;
V_2 -> V_204 ++ ;
F_19 ( V_45 , L_34 ) ;
F_33 ( V_2 ) ;
} else {
struct V_38 * V_39 , * V_205 ;
int V_12 = F_6 ( V_2 ) ;
int V_34 = F_5 ( V_2 ) ;
int V_206 = F_7 ( V_2 ) ;
V_39 = F_32 ( V_2 ) ;
V_205 = NULL ;
if ( V_12 < V_207 )
V_205 = F_18 ( V_45 , V_12 ) ;
if ( V_205 ) {
F_93 ( V_205 ,
V_39 -> V_50 + V_34 ,
V_12 ) ;
if ( V_57 )
F_14 ( V_39 -> V_50 ,
V_12 + V_34 ) ;
if ( ! F_33 ( V_2 ) )
F_94 ( V_39 ) ;
V_39 = V_205 ;
} else {
F_34 ( V_2 ) ;
F_95 ( V_39 , V_34 ) ;
}
F_96 ( V_39 , V_12 ) ;
V_39 -> V_177 = F_97 ( V_39 , V_45 ) ;
if ( V_206 )
V_39 -> V_175 = V_208 ;
F_98 ( V_39 ) ;
V_45 -> V_164 . V_209 ++ ;
V_45 -> V_164 . V_210 += V_12 ;
V_202 ++ ;
}
} while ( V_202 < V_201 );
F_28 ( V_2 ) ;
if ( V_202 < V_201 ) {
V_42 = F_48 ( V_2 -> V_48 -> V_61 ,
V_211 ) ;
F_20 ( V_42 != V_62 ) ;
F_99 ( V_92 ) ;
if ( F_3 ( V_2 ) &&
F_100 ( V_92 ) ) {
V_42 = F_48 ( V_2 -> V_48 -> V_61 ,
V_98 ) ;
goto V_203;
}
}
return V_202 ;
}
static T_7 V_101 ( int V_100 , void * V_212 )
{
struct V_90 * V_45 = V_212 ;
struct V_1 * V_2 = F_43 ( V_45 ) ;
unsigned long V_42 ;
if ( F_101 ( & V_2 -> V_92 ) ) {
V_42 = F_48 ( V_2 -> V_48 -> V_61 ,
V_98 ) ;
F_20 ( V_42 != V_62 ) ;
F_102 ( & V_2 -> V_92 ) ;
}
return V_213 ;
}
static void F_103 ( struct V_90 * V_45 )
{
struct V_1 * V_2 = F_43 ( V_45 ) ;
unsigned long V_42 ;
if ( ( V_45 -> V_214 & V_215 ) ||
( F_104 ( V_45 ) > V_2 -> V_216 ) ) {
V_42 = F_105 ( V_2 -> V_48 -> V_61 ,
V_217 |
V_218 ,
0 ) ;
if ( V_42 != V_62 ) {
F_46 ( V_45 , L_35
L_36 , V_42 ) ;
}
} else {
struct V_219 * V_220 ;
V_42 = F_105 ( V_2 -> V_48 -> V_61 ,
V_217 |
V_218 |
V_221 ,
0 ) ;
if ( V_42 != V_62 ) {
F_46 ( V_45 , L_35
L_37 ,
V_42 ) ;
}
F_106 (ha, netdev) {
unsigned long V_222 = 0 ;
memcpy ( ( ( char * ) & V_222 ) + 2 , V_220 -> V_33 , 6 ) ;
V_42 = F_105 ( V_2 -> V_48 -> V_61 ,
V_223 ,
V_222 ) ;
if ( V_42 != V_62 ) {
F_46 ( V_45 , L_38
L_39
L_40 , V_42 ) ;
}
}
V_42 = F_105 ( V_2 -> V_48 -> V_61 ,
V_224 ,
0 ) ;
if ( V_42 != V_62 ) {
F_46 ( V_45 , L_35
L_41 , V_42 ) ;
}
}
}
static int F_107 ( struct V_90 * V_49 , int V_225 )
{
struct V_1 * V_2 = F_43 ( V_49 ) ;
struct V_226 * V_227 = V_2 -> V_48 ;
int V_228 = V_225 + V_60 ;
int V_23 , V_86 ;
int V_229 = 0 ;
if ( V_225 < V_230 )
return - V_231 ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ )
if ( V_228 < V_2 -> V_67 [ V_23 ] . V_18 )
break;
if ( V_23 == V_66 )
return - V_231 ;
if ( F_61 ( V_2 -> V_45 ) ) {
V_229 = 1 ;
V_2 -> V_104 = 1 ;
F_53 ( V_2 -> V_45 ) ;
V_2 -> V_104 = 0 ;
}
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
V_2 -> V_67 [ V_23 ] . V_22 = 1 ;
if ( V_228 < V_2 -> V_67 [ V_23 ] . V_18 ) {
V_49 -> V_59 = V_225 ;
F_108 ( V_227 ,
F_109
( V_227 ) ) ;
if ( V_229 ) {
return F_42 ( V_2 -> V_45 ) ;
}
return 0 ;
}
}
if ( V_229 && ( V_86 = F_42 ( V_2 -> V_45 ) ) )
return V_86 ;
return - V_231 ;
}
static void F_110 ( struct V_90 * V_49 )
{
F_28 ( F_43 ( V_49 ) ) ;
V_101 ( V_49 -> V_100 , V_49 ) ;
}
static unsigned long F_109 ( struct V_226 * V_48 )
{
struct V_90 * V_45 = F_111 ( & V_48 -> V_49 ) ;
struct V_1 * V_2 ;
unsigned long V_71 ;
int V_23 ;
int V_232 = 1 ;
if ( V_45 == NULL )
return F_112 ( V_233 ) ;
V_2 = F_43 ( V_45 ) ;
V_71 = V_234 + V_235 ;
V_71 += F_112 ( V_45 -> V_59 ) ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
if ( V_2 -> V_67 [ V_23 ] . V_22 )
V_71 +=
V_2 -> V_67 [ V_23 ] . V_20 *
F_112 ( V_2 -> V_67 [ V_23 ] .
V_18 ) ;
V_232 += V_2 -> V_67 [ V_23 ] . V_20 ;
}
V_71 += F_112 ( V_232 * sizeof( struct V_95 ) ) ;
return V_71 ;
}
static int F_113 ( struct V_226 * V_49 , const struct V_236 * V_237 )
{
int V_86 , V_23 ;
struct V_90 * V_45 ;
struct V_1 * V_2 ;
unsigned char * V_238 ;
unsigned int * V_239 ;
F_114 ( & V_49 -> V_49 , L_42 ,
V_49 -> V_61 ) ;
V_238 = ( unsigned char * ) F_115 ( V_49 , V_240 ,
NULL ) ;
if ( ! V_238 ) {
F_116 ( & V_49 -> V_49 , L_43 ) ;
return - V_231 ;
}
V_239 = ( unsigned int * ) F_115 ( V_49 ,
V_241 , NULL ) ;
if ( ! V_239 ) {
F_116 ( & V_49 -> V_49 , L_44
L_45 ) ;
return - V_231 ;
}
V_45 = F_117 ( sizeof( struct V_1 ) ) ;
if ( ! V_45 )
return - V_93 ;
V_2 = F_43 ( V_45 ) ;
F_118 ( & V_49 -> V_49 , V_45 ) ;
V_2 -> V_48 = V_49 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_216 = * V_239 ;
V_2 -> V_104 = 0 ;
F_119 ( V_45 , & V_2 -> V_92 , F_89 , 16 ) ;
if ( ( * V_238 & 0x3 ) != 0x02 )
V_238 += 2 ;
V_2 -> V_242 = 0 ;
memcpy ( & V_2 -> V_242 , V_238 , 6 ) ;
V_45 -> V_100 = V_49 -> V_100 ;
V_45 -> V_243 = & V_244 ;
V_45 -> V_245 = & V_246 ;
F_120 ( V_45 , & V_49 -> V_49 ) ;
V_45 -> V_247 = V_248 | V_134 |
V_151 | V_153 ;
V_45 -> V_133 |= V_45 -> V_247 ;
memcpy ( V_45 -> V_96 , & V_2 -> V_242 , V_45 -> V_97 ) ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
struct V_249 * V_250 = & V_2 -> V_67 [ V_23 ] . V_250 ;
int error ;
F_8 ( & V_2 -> V_67 [ V_23 ] , V_23 ,
V_251 [ V_23 ] , V_17 [ V_23 ] ,
V_19 [ V_23 ] ) ;
error = F_121 ( V_250 , & V_252 ,
& V_49 -> V_49 . V_250 , L_46 , V_23 ) ;
if ( ! error )
F_122 ( V_250 , V_253 ) ;
}
F_19 ( V_45 , L_47 , V_2 ) ;
V_2 -> V_75 = V_77 ;
V_2 -> V_79 = V_77 ;
V_2 -> V_3 . V_81 = V_77 ;
F_19 ( V_45 , L_48 ) ;
F_63 ( V_45 , V_45 -> V_133 ) ;
V_86 = F_123 ( V_45 ) ;
if ( V_86 ) {
F_19 ( V_45 , L_49 , V_86 ) ;
F_124 ( V_45 ) ;
return V_86 ;
}
F_19 ( V_45 , L_50 ) ;
return 0 ;
}
static int F_125 ( struct V_226 * V_49 )
{
struct V_90 * V_45 = F_111 ( & V_49 -> V_49 ) ;
struct V_1 * V_2 = F_43 ( V_45 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ )
F_126 ( & V_2 -> V_67 [ V_23 ] . V_250 ) ;
F_127 ( V_45 ) ;
F_124 ( V_45 ) ;
F_118 ( & V_49 -> V_49 , NULL ) ;
return 0 ;
}
static T_8 F_128 ( struct V_249 * V_250 ,
struct V_254 * V_255 , char * V_182 )
{
struct V_14 * V_15 = F_90 ( V_250 ,
struct V_14 ,
V_250 ) ;
if ( V_255 == & V_256 )
return sprintf ( V_182 , L_51 , V_15 -> V_22 ) ;
else if ( V_255 == & V_257 )
return sprintf ( V_182 , L_51 , V_15 -> V_20 ) ;
else if ( V_255 == & V_258 )
return sprintf ( V_182 , L_51 , V_15 -> V_18 ) ;
return 0 ;
}
static T_8 F_129 ( struct V_249 * V_250 , struct V_254 * V_255 ,
const char * V_182 , T_9 V_36 )
{
struct V_14 * V_15 = F_90 ( V_250 ,
struct V_14 ,
V_250 ) ;
struct V_90 * V_45 = F_111 (
F_90 ( V_250 -> V_259 , struct V_74 , V_250 ) ) ;
struct V_1 * V_2 = F_43 ( V_45 ) ;
long V_260 = F_130 ( V_182 , NULL , 10 ) ;
long V_86 ;
if ( V_255 == & V_256 ) {
if ( V_260 && ! V_15 -> V_22 ) {
if ( F_61 ( V_45 ) ) {
if ( F_9 ( V_15 ) ) {
F_46 ( V_45 ,
L_15 ) ;
return - V_93 ;
}
V_15 -> V_22 = 1 ;
V_2 -> V_104 = 1 ;
F_53 ( V_45 ) ;
V_2 -> V_104 = 0 ;
if ( ( V_86 = F_42 ( V_45 ) ) )
return V_86 ;
} else {
V_15 -> V_22 = 1 ;
}
} else if ( ! V_260 && V_15 -> V_22 ) {
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
F_46 ( V_45 , L_52 ) ;
return - V_261 ;
}
if ( F_61 ( V_45 ) ) {
V_2 -> V_104 = 1 ;
F_53 ( V_45 ) ;
V_15 -> V_22 = 0 ;
V_2 -> V_104 = 0 ;
if ( ( V_86 = F_42 ( V_45 ) ) )
return V_86 ;
}
V_15 -> V_22 = 0 ;
}
} else if ( V_255 == & V_257 ) {
if ( V_260 <= 0 || V_260 > V_262 ) {
return - V_231 ;
} else {
if ( F_61 ( V_45 ) ) {
V_2 -> V_104 = 1 ;
F_53 ( V_45 ) ;
V_2 -> V_104 = 0 ;
V_15 -> V_20 = V_260 ;
if ( ( V_86 = F_42 ( V_45 ) ) )
return V_86 ;
} else {
V_15 -> V_20 = V_260 ;
}
}
} else if ( V_255 == & V_258 ) {
if ( V_260 <= V_60 || V_260 > V_263 ) {
return - V_231 ;
} else {
if ( F_61 ( V_45 ) ) {
V_2 -> V_104 = 1 ;
F_53 ( V_45 ) ;
V_2 -> V_104 = 0 ;
V_15 -> V_18 = V_260 ;
if ( ( V_86 = F_42 ( V_45 ) ) )
return V_86 ;
} else {
V_15 -> V_18 = V_260 ;
}
}
}
V_101 ( V_45 -> V_100 , V_45 ) ;
return V_36 ;
}
static int F_131 ( struct V_74 * V_49 )
{
struct V_90 * V_45 = F_111 ( V_49 ) ;
V_101 ( V_45 -> V_100 , V_45 ) ;
return 0 ;
}
static int T_10 F_132 ( void )
{
F_133 ( V_264 L_53 , V_130 ,
V_265 , V_132 ) ;
return F_134 ( & V_266 ) ;
}
static void T_11 F_135 ( void )
{
F_136 ( & V_266 ) ;
}
