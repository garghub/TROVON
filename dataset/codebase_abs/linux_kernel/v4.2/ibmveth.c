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
T_3 * V_65 = V_2 -> V_66 + 4096 - 8 ;
V_2 -> V_67 = F_30 ( V_65 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
int V_23 ;
V_2 -> V_68 ++ ;
for ( V_23 = ( V_69 - 1 ) ; V_23 >= 0 ; V_23 -- ) {
struct V_14 * V_15 = & V_2 -> V_70 [ V_23 ] ;
if ( V_15 -> V_22 &&
( F_17 ( & V_15 -> V_30 ) < V_15 -> V_21 ) )
F_16 ( V_2 , V_15 ) ;
}
F_29 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
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
static void F_33 ( struct V_1 * V_2 ,
T_2 V_41 )
{
unsigned int V_15 = V_41 >> 32 ;
unsigned int V_5 = V_41 & 0xffffffffUL ;
unsigned int V_40 ;
struct V_38 * V_39 ;
F_21 ( V_15 >= V_69 ) ;
F_21 ( V_5 >= V_2 -> V_70 [ V_15 ] . V_20 ) ;
V_39 = V_2 -> V_70 [ V_15 ] . V_29 [ V_5 ] ;
F_21 ( V_39 == NULL ) ;
V_2 -> V_70 [ V_15 ] . V_29 [ V_5 ] = NULL ;
F_27 ( & V_2 -> V_48 -> V_49 ,
V_2 -> V_70 [ V_15 ] . V_27 [ V_5 ] ,
V_2 -> V_70 [ V_15 ] . V_18 ,
V_51 ) ;
V_40 = V_2 -> V_70 [ V_15 ] . V_31 ;
V_2 -> V_70 [ V_15 ] . V_31 ++ ;
if ( V_2 -> V_70 [ V_15 ] . V_31 >=
V_2 -> V_70 [ V_15 ] . V_20 )
V_2 -> V_70 [ V_15 ] . V_31 = 0 ;
V_2 -> V_70 [ V_15 ] . V_24 [ V_40 ] = V_5 ;
F_18 () ;
F_34 ( & ( V_2 -> V_70 [ V_15 ] . V_30 ) ) ;
}
static inline struct V_38 * F_35 ( struct V_1 * V_2 )
{
T_2 V_41 = V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_41 ;
unsigned int V_15 = V_41 >> 32 ;
unsigned int V_5 = V_41 & 0xffffffffUL ;
F_21 ( V_15 >= V_69 ) ;
F_21 ( V_5 >= V_2 -> V_70 [ V_15 ] . V_20 ) ;
return V_2 -> V_70 [ V_15 ] . V_29 [ V_5 ] ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_1 V_71 = V_2 -> V_3 . V_5 ;
T_2 V_41 = V_2 -> V_3 . V_4 [ V_71 ] . V_41 ;
unsigned int V_15 = V_41 >> 32 ;
unsigned int V_5 = V_41 & 0xffffffffUL ;
union V_43 V_44 ;
unsigned long V_42 ;
int V_72 = 1 ;
F_21 ( V_15 >= V_69 ) ;
F_21 ( V_5 >= V_2 -> V_70 [ V_15 ] . V_20 ) ;
if ( ! V_2 -> V_70 [ V_15 ] . V_22 ) {
F_37 ( V_2 ) ;
F_32 ( V_2 , & V_2 -> V_70 [ V_15 ] ) ;
goto V_73;
}
V_44 . V_53 . V_54 = V_55 |
V_2 -> V_70 [ V_15 ] . V_18 ;
V_44 . V_53 . V_56 = V_2 -> V_70 [ V_15 ] . V_27 [ V_5 ] ;
V_42 = F_25 ( V_2 -> V_48 -> V_61 , V_44 . V_44 ) ;
if ( V_42 != V_62 ) {
F_20 ( V_2 -> V_45 , L_2
L_3 , V_42 ) ;
F_33 ( V_2 , V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_41 ) ;
V_72 = 0 ;
}
if ( ++ V_2 -> V_3 . V_5 == V_2 -> V_3 . V_74 ) {
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_9 = ! V_2 -> V_3 . V_9 ;
}
V_73:
return V_72 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_41 ) ;
if ( ++ V_2 -> V_3 . V_5 == V_2 -> V_3 . V_74 ) {
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_9 = ! V_2 -> V_3 . V_9 ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
int V_23 ;
struct V_75 * V_49 = & V_2 -> V_48 -> V_49 ;
if ( V_2 -> V_66 != NULL ) {
if ( ! F_23 ( V_49 , V_2 -> V_76 ) ) {
F_27 ( V_49 , V_2 -> V_76 , 4096 ,
V_77 ) ;
V_2 -> V_76 = V_78 ;
}
F_39 ( ( unsigned long ) V_2 -> V_66 ) ;
V_2 -> V_66 = NULL ;
}
if ( V_2 -> V_79 != NULL ) {
if ( ! F_23 ( V_49 , V_2 -> V_80 ) ) {
F_27 ( V_49 , V_2 -> V_80 , 4096 ,
V_77 ) ;
V_2 -> V_80 = V_78 ;
}
F_39 ( ( unsigned long ) V_2 -> V_79 ) ;
V_2 -> V_79 = NULL ;
}
if ( V_2 -> V_3 . V_4 != NULL ) {
F_40 ( V_49 , V_2 -> V_3 . V_81 ,
V_2 -> V_3 . V_4 ,
V_2 -> V_3 . V_82 ) ;
V_2 -> V_3 . V_4 = NULL ;
}
for ( V_23 = 0 ; V_23 < V_69 ; V_23 ++ )
if ( V_2 -> V_70 [ V_23 ] . V_22 )
F_32 ( V_2 ,
& V_2 -> V_70 [ V_23 ] ) ;
if ( V_2 -> V_83 != NULL ) {
if ( ! F_23 ( V_49 , V_2 -> V_84 ) ) {
F_27 ( & V_2 -> V_48 -> V_49 ,
V_2 -> V_84 ,
V_2 -> V_45 -> V_59 + V_60 ,
V_77 ) ;
V_2 -> V_84 = V_78 ;
}
F_12 ( V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
}
}
static int F_41 ( struct V_1 * V_2 ,
union V_43 V_85 , T_2 V_86 )
{
int V_87 , V_88 = 1 ;
V_89:
V_87 = F_42 ( V_2 -> V_48 -> V_61 ,
V_2 -> V_76 , V_85 . V_44 ,
V_2 -> V_80 , V_86 ) ;
if ( V_87 != V_62 && V_88 ) {
do {
V_87 = F_43 ( V_2 -> V_48 -> V_61 ) ;
} while ( F_44 ( V_87 ) || ( V_87 == V_90 ) );
V_88 = 0 ;
goto V_89;
}
return V_87 ;
}
static T_2 F_45 ( T_4 * V_91 )
{
int V_23 ;
T_2 V_92 = 0 ;
for ( V_23 = 0 ; V_23 < V_93 ; V_23 ++ )
V_92 = ( V_92 << 8 ) | V_91 [ V_23 ] ;
return V_92 ;
}
static int F_46 ( struct V_94 * V_45 )
{
struct V_1 * V_2 = F_47 ( V_45 ) ;
T_2 V_86 ;
int V_95 = 1 ;
unsigned long V_42 ;
int V_87 ;
union V_43 V_85 ;
int V_23 ;
struct V_75 * V_49 ;
F_20 ( V_45 , L_4 ) ;
F_48 ( & V_2 -> V_96 ) ;
for( V_23 = 0 ; V_23 < V_69 ; V_23 ++ )
V_95 += V_2 -> V_70 [ V_23 ] . V_20 ;
V_2 -> V_66 = ( void * ) F_49 ( V_26 ) ;
V_2 -> V_79 = ( void * ) F_49 ( V_26 ) ;
if ( ! V_2 -> V_66 || ! V_2 -> V_79 ) {
F_50 ( V_45 , L_5
L_6 ) ;
V_87 = - V_97 ;
goto V_98;
}
V_49 = & V_2 -> V_48 -> V_49 ;
V_2 -> V_3 . V_81 = sizeof( struct V_99 ) *
V_95 ;
V_2 -> V_3 . V_4 =
F_51 ( V_49 , V_2 -> V_3 . V_81 ,
& V_2 -> V_3 . V_82 , V_26 ) ;
if ( ! V_2 -> V_3 . V_4 ) {
V_87 = - V_97 ;
goto V_98;
}
V_2 -> V_76 = F_22 ( V_49 ,
V_2 -> V_66 , 4096 , V_77 ) ;
V_2 -> V_80 = F_22 ( V_49 ,
V_2 -> V_79 , 4096 , V_77 ) ;
if ( ( F_23 ( V_49 , V_2 -> V_76 ) ) ||
( F_23 ( V_49 , V_2 -> V_80 ) ) ) {
F_50 ( V_45 , L_7
L_6 ) ;
V_87 = - V_97 ;
goto V_98;
}
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_74 = V_95 ;
V_2 -> V_3 . V_9 = 1 ;
V_86 = F_45 ( V_45 -> V_100 ) ;
V_85 . V_53 . V_54 = V_55 |
V_2 -> V_3 . V_81 ;
V_85 . V_53 . V_56 = V_2 -> V_3 . V_82 ;
F_20 ( V_45 , L_8 , V_2 -> V_66 ) ;
F_20 ( V_45 , L_9 , V_2 -> V_79 ) ;
F_20 ( V_45 , L_10 , V_2 -> V_3 . V_4 ) ;
F_52 ( V_2 -> V_48 -> V_61 , V_101 ) ;
V_42 = F_41 ( V_2 , V_85 , V_86 ) ;
if ( V_42 != V_62 ) {
F_50 ( V_45 , L_11 ,
V_42 ) ;
F_50 ( V_45 , L_12
L_13 ,
V_2 -> V_76 ,
V_2 -> V_80 ,
V_85 . V_44 ,
V_86 ) ;
V_87 = - V_102 ;
goto V_98;
}
for ( V_23 = 0 ; V_23 < V_69 ; V_23 ++ ) {
if ( ! V_2 -> V_70 [ V_23 ] . V_22 )
continue;
if ( F_10 ( & V_2 -> V_70 [ V_23 ] ) ) {
F_50 ( V_45 , L_14 ) ;
V_2 -> V_70 [ V_23 ] . V_22 = 0 ;
V_87 = - V_97 ;
goto V_98;
}
}
F_20 ( V_45 , L_15 , V_45 -> V_103 ) ;
V_87 = F_53 ( V_45 -> V_103 , V_104 , 0 , V_45 -> V_105 ,
V_45 ) ;
if ( V_87 != 0 ) {
F_50 ( V_45 , L_16 ,
V_45 -> V_103 , V_87 ) ;
do {
V_42 = F_43 ( V_2 -> V_48 -> V_61 ) ;
} while ( F_44 ( V_42 ) || ( V_42 == V_90 ) );
goto V_98;
}
V_2 -> V_83 =
F_11 ( V_45 -> V_59 + V_60 , V_26 ) ;
if ( ! V_2 -> V_83 ) {
V_87 = - V_97 ;
goto V_106;
}
V_2 -> V_84 =
F_22 ( & V_2 -> V_48 -> V_49 , V_2 -> V_83 ,
V_45 -> V_59 + V_60 , V_77 ) ;
if ( F_23 ( V_49 , V_2 -> V_84 ) ) {
F_50 ( V_45 , L_17 ) ;
V_87 = - V_97 ;
goto V_106;
}
F_20 ( V_45 , L_18 ) ;
V_104 ( V_45 -> V_103 , V_45 ) ;
F_54 ( V_45 ) ;
F_20 ( V_45 , L_19 ) ;
return 0 ;
V_106:
F_55 ( V_45 -> V_103 , V_45 ) ;
V_98:
F_38 ( V_2 ) ;
F_56 ( & V_2 -> V_96 ) ;
return V_87 ;
}
static int F_57 ( struct V_94 * V_45 )
{
struct V_1 * V_2 = F_47 ( V_45 ) ;
long V_42 ;
F_20 ( V_45 , L_20 ) ;
F_56 ( & V_2 -> V_96 ) ;
if ( ! V_2 -> V_107 )
F_58 ( V_45 ) ;
F_52 ( V_2 -> V_48 -> V_61 , V_101 ) ;
do {
V_42 = F_43 ( V_2 -> V_48 -> V_61 ) ;
} while ( F_44 ( V_42 ) || ( V_42 == V_90 ) );
if ( V_42 != V_62 ) {
F_50 ( V_45 , L_21
L_22 , V_42 ) ;
}
F_55 ( V_45 -> V_103 , V_45 ) ;
F_29 ( V_2 ) ;
F_38 ( V_2 ) ;
F_20 ( V_45 , L_23 ) ;
return 0 ;
}
static int F_59 ( struct V_94 * V_49 , struct V_108 * V_109 )
{
V_109 -> V_110 = ( V_111 | V_112 |
V_113 ) ;
V_109 -> V_114 = ( V_115 | V_116 |
V_117 ) ;
F_60 ( V_109 , V_118 ) ;
V_109 -> V_119 = V_120 ;
V_109 -> V_121 = V_122 ;
V_109 -> V_123 = 0 ;
V_109 -> V_124 = V_125 ;
V_109 -> V_126 = V_127 ;
V_109 -> V_128 = 0 ;
V_109 -> V_129 = 1 ;
return 0 ;
}
static void F_61 ( struct V_94 * V_49 ,
struct V_130 * V_131 )
{
F_62 ( V_131 -> V_132 , V_133 , sizeof( V_131 -> V_132 ) ) ;
F_62 ( V_131 -> V_134 , V_135 , sizeof( V_131 -> V_134 ) ) ;
}
static T_5 F_63 ( struct V_94 * V_49 ,
T_5 V_136 )
{
if ( ! ( V_136 & V_137 ) )
V_136 &= ~ V_138 ;
return V_136 ;
}
static int F_64 ( struct V_94 * V_49 , T_1 V_50 )
{
struct V_1 * V_2 = F_47 ( V_49 ) ;
unsigned long V_139 , V_140 , V_141 ;
unsigned long V_142 , V_143 ;
long V_72 , V_144 , V_145 ;
int V_146 = 0 , V_147 = 0 ;
int V_148 = 0 ;
if ( F_65 ( V_49 ) ) {
V_148 = 1 ;
V_2 -> V_107 = 1 ;
F_57 ( V_49 ) ;
V_2 -> V_107 = 0 ;
}
V_139 = 0 ;
V_140 = 0 ;
V_142 = 0 ;
V_143 = 0 ;
if ( V_50 ) {
V_139 = V_149 ;
V_142 = V_150 ;
} else {
V_140 = V_149 ;
V_143 = V_150 ;
}
V_72 = F_66 ( V_2 -> V_48 -> V_61 , 0 , 0 , & V_141 ) ;
if ( V_72 == V_62 && ! ( V_141 & V_151 ) &&
! ( V_141 & V_152 ) &&
( V_141 & V_153 ) ) {
V_144 = F_66 ( V_2 -> V_48 -> V_61 , V_140 ,
V_139 , & V_141 ) ;
if ( V_144 != V_62 ) {
F_50 ( V_49 , L_24
L_25 ,
V_50 , V_144 ) ;
F_66 ( V_2 -> V_48 -> V_61 ,
V_139 , V_140 , & V_141 ) ;
if ( V_50 == 1 )
V_49 -> V_136 &= ~ V_154 ;
} else {
V_2 -> V_155 = V_50 ;
}
V_145 = F_66 ( V_2 -> V_48 -> V_61 ,
V_143 , V_142 , & V_141 ) ;
if ( V_145 != V_62 ) {
F_50 ( V_49 , L_26
L_25 ,
V_50 , V_145 ) ;
F_66 ( V_2 -> V_48 -> V_61 ,
V_142 , V_143 , & V_141 ) ;
if ( V_50 == 1 )
V_49 -> V_136 &= ~ V_156 ;
} else
V_2 -> V_157 = V_50 ;
if ( V_144 == V_62 || V_145 == V_62 )
V_2 -> V_158 = V_50 ;
else
V_146 = - V_159 ;
} else {
V_146 = - V_159 ;
F_50 ( V_49 , L_27
L_28 , V_50 , V_72 ,
V_141 ) ;
}
if ( V_148 )
V_147 = F_46 ( V_49 ) ;
return V_146 ? V_146 : V_147 ;
}
static int F_67 ( struct V_94 * V_49 ,
T_5 V_136 )
{
struct V_1 * V_2 = F_47 ( V_49 ) ;
int V_158 = ! ! ( V_136 & V_137 ) ;
int V_87 ;
T_5 V_160 = V_136 ^ V_49 -> V_136 ;
if ( V_136 & V_161 & V_160 )
F_68 ( V_49 , L_29 ) ;
if ( V_158 == V_2 -> V_158 )
return 0 ;
V_87 = F_64 ( V_49 , V_158 ) ;
if ( V_87 && ! V_2 -> V_158 )
V_49 -> V_136 = V_136 & ~ ( V_138 | V_137 ) ;
return V_87 ;
}
static void F_69 ( struct V_94 * V_49 , T_1 V_162 , T_4 * V_50 )
{
int V_23 ;
if ( V_162 != V_163 )
return;
for ( V_23 = 0 ; V_23 < F_70 ( V_164 ) ; V_23 ++ , V_50 += V_165 )
memcpy ( V_50 , V_164 [ V_23 ] . V_105 , V_165 ) ;
}
static int F_71 ( struct V_94 * V_49 , int V_166 )
{
switch ( V_166 ) {
case V_163 :
return F_70 ( V_164 ) ;
default:
return - V_167 ;
}
}
static void F_72 ( struct V_94 * V_49 ,
struct V_168 * V_169 , T_2 * V_50 )
{
int V_23 ;
struct V_1 * V_2 = F_47 ( V_49 ) ;
for ( V_23 = 0 ; V_23 < F_70 ( V_164 ) ; V_23 ++ )
V_50 [ V_23 ] = F_73 ( V_2 , V_164 [ V_23 ] . V_34 ) ;
}
static int F_74 ( struct V_94 * V_49 , struct V_170 * V_171 , int V_109 )
{
return - V_167 ;
}
static int F_75 ( struct V_1 * V_2 ,
union V_43 * V_172 )
{
unsigned long V_41 ;
unsigned int V_173 ;
unsigned long V_72 ;
V_173 = 1024 ;
V_41 = 0 ;
do {
V_72 = F_76 ( V_2 -> V_48 -> V_61 ,
V_172 [ 0 ] . V_44 , V_172 [ 1 ] . V_44 ,
V_172 [ 2 ] . V_44 , V_172 [ 3 ] . V_44 ,
V_172 [ 4 ] . V_44 , V_172 [ 5 ] . V_44 ,
V_41 , & V_41 ) ;
} while ( ( V_72 == V_90 ) && ( V_173 -- ) );
if ( V_72 != V_62 && V_72 != V_174 ) {
F_50 ( V_2 -> V_45 , L_30
L_31 , V_72 ) ;
return 1 ;
}
return 0 ;
}
static T_6 F_77 ( struct V_38 * V_39 ,
struct V_94 * V_45 )
{
struct V_1 * V_2 = F_47 ( V_45 ) ;
unsigned int V_175 ;
union V_43 V_172 [ 6 ] ;
int V_176 , V_23 ;
int V_177 = 0 ;
V_28 V_27 ;
if ( F_78 ( V_39 ) -> V_178 > 5 && F_79 ( V_39 ) ) {
V_45 -> V_169 . V_179 ++ ;
goto V_73;
}
if ( V_39 -> V_180 == V_181 &&
( ( V_39 -> V_182 == F_80 ( V_183 ) &&
F_81 ( V_39 ) -> V_182 != V_184 ) ||
( V_39 -> V_182 == F_80 ( V_185 ) &&
F_82 ( V_39 ) -> V_186 != V_184 ) ) &&
F_83 ( V_39 ) ) {
F_50 ( V_45 , L_32 ) ;
V_45 -> V_169 . V_179 ++ ;
goto V_73;
}
V_175 = V_55 ;
if ( V_39 -> V_180 == V_181 ) {
unsigned char * V_187 = F_84 ( V_39 ) +
V_39 -> V_188 ;
V_175 |= ( V_189 | V_190 ) ;
V_187 [ 0 ] = 0 ;
V_187 [ 1 ] = 0 ;
}
V_191:
memset ( V_172 , 0 , sizeof( V_172 ) ) ;
if ( V_177 || ( ! F_85 ( V_39 ) &&
( V_39 -> V_58 < V_192 ) ) ) {
F_86 ( V_39 , V_2 -> V_83 ,
V_39 -> V_58 ) ;
V_172 [ 0 ] . V_53 . V_54 = V_175 | V_39 -> V_58 ;
V_172 [ 0 ] . V_53 . V_56 = V_2 -> V_84 ;
if ( F_75 ( V_2 , V_172 ) ) {
V_2 -> V_193 ++ ;
V_45 -> V_169 . V_179 ++ ;
} else {
V_45 -> V_169 . V_194 ++ ;
V_45 -> V_169 . V_195 += V_39 -> V_58 ;
}
goto V_73;
}
V_27 = F_22 ( & V_2 -> V_48 -> V_49 , V_39 -> V_50 ,
F_87 ( V_39 ) , V_196 ) ;
if ( F_23 ( & V_2 -> V_48 -> V_49 , V_27 ) )
goto V_197;
V_172 [ 0 ] . V_53 . V_54 = V_175 | F_87 ( V_39 ) ;
V_172 [ 0 ] . V_53 . V_56 = V_27 ;
for ( V_23 = 0 ; V_23 < F_78 ( V_39 ) -> V_178 ; V_23 ++ ) {
const T_7 * V_198 = & F_78 ( V_39 ) -> V_199 [ V_23 ] ;
V_27 = F_88 ( & V_2 -> V_48 -> V_49 , V_198 , 0 ,
F_89 ( V_198 ) , V_196 ) ;
if ( F_23 ( & V_2 -> V_48 -> V_49 , V_27 ) )
goto V_200;
V_172 [ V_23 + 1 ] . V_53 . V_54 = V_175 | F_89 ( V_198 ) ;
V_172 [ V_23 + 1 ] . V_53 . V_56 = V_27 ;
}
if ( F_90 ( V_39 ) && ! F_91 ( V_39 ) ) {
F_81 ( V_39 ) -> V_201 = 0xffff ;
F_92 ( V_39 ) -> V_201 = F_93 ( F_78 ( V_39 ) -> V_202 ) ;
V_2 -> V_203 ++ ;
}
if ( F_75 ( V_2 , V_172 ) ) {
V_2 -> V_193 ++ ;
V_45 -> V_169 . V_179 ++ ;
} else {
V_45 -> V_169 . V_194 ++ ;
V_45 -> V_169 . V_195 += V_39 -> V_58 ;
}
F_27 ( & V_2 -> V_48 -> V_49 ,
V_172 [ 0 ] . V_53 . V_56 ,
V_172 [ 0 ] . V_53 . V_54 & V_204 ,
V_196 ) ;
for ( V_23 = 1 ; V_23 < F_78 ( V_39 ) -> V_178 + 1 ; V_23 ++ )
F_94 ( & V_2 -> V_48 -> V_49 , V_172 [ V_23 ] . V_53 . V_56 ,
V_172 [ V_23 ] . V_53 . V_54 & V_204 ,
V_196 ) ;
V_73:
F_95 ( V_39 ) ;
return V_205 ;
V_200:
V_176 = V_23 + 1 ;
for ( V_23 = 0 ; V_23 < V_176 ; V_23 ++ )
F_94 ( & V_2 -> V_48 -> V_49 , V_172 [ V_23 ] . V_53 . V_56 ,
V_172 [ V_23 ] . V_53 . V_54 & V_204 ,
V_196 ) ;
V_197:
if ( ! F_96 ( V_206 ) )
F_50 ( V_45 , L_33 ) ;
V_2 -> V_207 ++ ;
F_97 ( V_39 ) ;
V_177 = 1 ;
goto V_191;
}
static int F_98 ( struct V_208 * V_96 , int V_209 )
{
struct V_1 * V_2 =
F_99 ( V_96 , struct V_1 , V_96 ) ;
struct V_94 * V_45 = V_2 -> V_45 ;
int V_210 = 0 ;
unsigned long V_42 ;
struct V_211 * V_212 ;
V_213:
while ( V_210 < V_209 ) {
if ( ! F_4 ( V_2 ) )
break;
F_100 () ;
if ( ! F_5 ( V_2 ) ) {
F_101 () ;
V_2 -> V_214 ++ ;
F_20 ( V_45 , L_34 ) ;
F_36 ( V_2 ) ;
} else {
struct V_38 * V_39 , * V_215 ;
int V_12 = F_7 ( V_2 ) ;
int V_34 = F_6 ( V_2 ) ;
int V_216 = F_8 ( V_2 ) ;
V_39 = F_35 ( V_2 ) ;
V_215 = NULL ;
if ( V_12 < V_217 )
V_215 = F_19 ( V_45 , V_12 ) ;
if ( V_215 ) {
F_102 ( V_215 ,
V_39 -> V_50 + V_34 ,
V_12 ) ;
if ( V_57 )
F_15 ( V_39 -> V_50 ,
V_12 + V_34 ) ;
if ( ! F_36 ( V_2 ) )
F_103 ( V_39 ) ;
V_39 = V_215 ;
} else {
F_37 ( V_2 ) ;
F_104 ( V_39 , V_34 ) ;
}
F_105 ( V_39 , V_12 ) ;
V_39 -> V_182 = F_106 ( V_39 , V_45 ) ;
if ( V_216 ) {
V_39 -> V_180 = V_218 ;
if ( F_107 ( V_39 -> V_182 ) == V_183 ) {
V_212 = (struct V_211 * ) V_39 -> V_50 ;
if ( V_212 -> V_201 == 0xffff ) {
V_212 -> V_201 = 0 ;
V_212 -> V_201 = F_108 ( ( unsigned char * ) V_212 , V_212 -> V_219 ) ;
V_2 -> V_220 ++ ;
}
}
}
F_109 ( V_96 , V_39 ) ;
V_45 -> V_169 . V_221 ++ ;
V_45 -> V_169 . V_222 += V_12 ;
V_210 ++ ;
}
}
F_31 ( V_2 ) ;
if ( V_210 < V_209 ) {
F_110 ( V_96 ) ;
V_42 = F_52 ( V_2 -> V_48 -> V_61 ,
V_223 ) ;
F_21 ( V_42 != V_62 ) ;
if ( F_4 ( V_2 ) &&
F_111 ( V_96 ) ) {
V_42 = F_52 ( V_2 -> V_48 -> V_61 ,
V_101 ) ;
goto V_213;
}
}
return V_210 ;
}
static T_8 V_104 ( int V_103 , void * V_224 )
{
struct V_94 * V_45 = V_224 ;
struct V_1 * V_2 = F_47 ( V_45 ) ;
unsigned long V_42 ;
if ( F_112 ( & V_2 -> V_96 ) ) {
V_42 = F_52 ( V_2 -> V_48 -> V_61 ,
V_101 ) ;
F_21 ( V_42 != V_62 ) ;
F_113 ( & V_2 -> V_96 ) ;
}
return V_225 ;
}
static void F_114 ( struct V_94 * V_45 )
{
struct V_1 * V_2 = F_47 ( V_45 ) ;
unsigned long V_42 ;
if ( ( V_45 -> V_226 & V_227 ) ||
( F_115 ( V_45 ) > V_2 -> V_228 ) ) {
V_42 = F_116 ( V_2 -> V_48 -> V_61 ,
V_229 |
V_230 ,
0 ) ;
if ( V_42 != V_62 ) {
F_50 ( V_45 , L_35
L_36 , V_42 ) ;
}
} else {
struct V_231 * V_232 ;
V_42 = F_116 ( V_2 -> V_48 -> V_61 ,
V_229 |
V_230 |
V_233 ,
0 ) ;
if ( V_42 != V_62 ) {
F_50 ( V_45 , L_35
L_37 ,
V_42 ) ;
}
F_117 (ha, netdev) {
T_2 V_234 ;
V_234 = F_45 ( V_232 -> V_33 ) ;
V_42 = F_116 ( V_2 -> V_48 -> V_61 ,
V_235 ,
V_234 ) ;
if ( V_42 != V_62 ) {
F_50 ( V_45 , L_38
L_39
L_40 , V_42 ) ;
}
}
V_42 = F_116 ( V_2 -> V_48 -> V_61 ,
V_236 ,
0 ) ;
if ( V_42 != V_62 ) {
F_50 ( V_45 , L_35
L_41 , V_42 ) ;
}
}
}
static int F_118 ( struct V_94 * V_49 , int V_237 )
{
struct V_1 * V_2 = F_47 ( V_49 ) ;
struct V_238 * V_239 = V_2 -> V_48 ;
int V_240 = V_237 + V_60 ;
int V_23 , V_87 ;
int V_241 = 0 ;
if ( V_237 < V_242 )
return - V_243 ;
for ( V_23 = 0 ; V_23 < V_69 ; V_23 ++ )
if ( V_240 <= V_2 -> V_70 [ V_23 ] . V_18 )
break;
if ( V_23 == V_69 )
return - V_243 ;
if ( F_65 ( V_2 -> V_45 ) ) {
V_241 = 1 ;
V_2 -> V_107 = 1 ;
F_57 ( V_2 -> V_45 ) ;
V_2 -> V_107 = 0 ;
}
for ( V_23 = 0 ; V_23 < V_69 ; V_23 ++ ) {
V_2 -> V_70 [ V_23 ] . V_22 = 1 ;
if ( V_240 <= V_2 -> V_70 [ V_23 ] . V_18 ) {
V_49 -> V_59 = V_237 ;
F_119 ( V_239 ,
F_120
( V_239 ) ) ;
if ( V_241 ) {
return F_46 ( V_2 -> V_45 ) ;
}
return 0 ;
}
}
if ( V_241 && ( V_87 = F_46 ( V_2 -> V_45 ) ) )
return V_87 ;
return - V_243 ;
}
static void F_121 ( struct V_94 * V_49 )
{
F_31 ( F_47 ( V_49 ) ) ;
V_104 ( V_49 -> V_103 , V_49 ) ;
}
static unsigned long F_120 ( struct V_238 * V_48 )
{
struct V_94 * V_45 = F_122 ( & V_48 -> V_49 ) ;
struct V_1 * V_2 ;
struct V_244 * V_245 ;
unsigned long V_72 ;
int V_23 ;
int V_246 = 1 ;
V_245 = F_123 ( & V_48 -> V_49 ) ;
if ( V_45 == NULL )
return F_124 ( V_247 , V_245 ) ;
V_2 = F_47 ( V_45 ) ;
V_72 = V_248 + V_249 ;
V_72 += F_124 ( V_45 -> V_59 , V_245 ) ;
for ( V_23 = 0 ; V_23 < V_69 ; V_23 ++ ) {
if ( V_2 -> V_70 [ V_23 ] . V_22 )
V_72 +=
V_2 -> V_70 [ V_23 ] . V_20 *
F_124 ( V_2 -> V_70 [ V_23 ] .
V_18 , V_245 ) ;
V_246 += V_2 -> V_70 [ V_23 ] . V_20 ;
}
V_72 += F_124 (
V_246 * sizeof( struct V_99 ) , V_245 ) ;
return V_72 ;
}
static int F_125 ( struct V_94 * V_49 , void * V_65 )
{
struct V_1 * V_2 = F_47 ( V_49 ) ;
struct V_250 * V_33 = V_65 ;
T_2 V_86 ;
int V_87 ;
if ( ! F_126 ( V_33 -> V_251 ) )
return - V_252 ;
V_86 = F_45 ( V_33 -> V_251 ) ;
V_87 = F_127 ( V_2 -> V_48 -> V_61 , V_86 ) ;
if ( V_87 ) {
F_50 ( V_2 -> V_45 , L_42 , V_87 ) ;
return V_87 ;
}
F_128 ( V_49 -> V_100 , V_33 -> V_251 ) ;
return 0 ;
}
static int F_129 ( struct V_238 * V_49 , const struct V_253 * V_254 )
{
int V_87 , V_23 , V_255 ;
struct V_94 * V_45 ;
struct V_1 * V_2 ;
unsigned char * V_256 ;
unsigned int * V_257 ;
F_130 ( & V_49 -> V_49 , L_43 ,
V_49 -> V_61 ) ;
V_256 = ( unsigned char * ) F_131 ( V_49 , V_258 ,
& V_255 ) ;
if ( ! V_256 ) {
F_132 ( & V_49 -> V_49 , L_44 ) ;
return - V_243 ;
}
if ( V_255 == 8 )
V_256 += 2 ;
else if ( V_255 != 6 ) {
F_132 ( & V_49 -> V_49 , L_45 ,
V_255 ) ;
return - V_243 ;
}
V_257 = ( unsigned int * ) F_131 ( V_49 ,
V_259 , NULL ) ;
if ( ! V_257 ) {
F_132 ( & V_49 -> V_49 , L_46
L_47 ) ;
return - V_243 ;
}
V_45 = F_133 ( sizeof( struct V_1 ) ) ;
if ( ! V_45 )
return - V_97 ;
V_2 = F_47 ( V_45 ) ;
F_134 ( & V_49 -> V_49 , V_45 ) ;
V_2 -> V_48 = V_49 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_228 = * V_257 ;
V_2 -> V_107 = 0 ;
F_135 ( V_45 , & V_2 -> V_96 , F_98 , 16 ) ;
V_45 -> V_103 = V_49 -> V_103 ;
V_45 -> V_260 = & V_261 ;
V_45 -> V_262 = & V_263 ;
F_136 ( V_45 , & V_49 -> V_49 ) ;
V_45 -> V_264 = V_265 | V_137 |
V_154 | V_156 ;
V_45 -> V_136 |= V_45 -> V_264 ;
V_45 -> V_264 |= V_161 ;
memcpy ( V_45 -> V_100 , V_256 , V_93 ) ;
if ( F_96 ( V_206 ) )
memcpy ( V_266 , V_267 , sizeof( V_266 ) ) ;
for ( V_23 = 0 ; V_23 < V_69 ; V_23 ++ ) {
struct V_268 * V_269 = & V_2 -> V_70 [ V_23 ] . V_269 ;
int error ;
F_9 ( & V_2 -> V_70 [ V_23 ] , V_23 ,
V_266 [ V_23 ] , V_17 [ V_23 ] ,
V_19 [ V_23 ] ) ;
error = F_137 ( V_269 , & V_270 ,
& V_49 -> V_49 . V_269 , L_48 , V_23 ) ;
if ( ! error )
F_138 ( V_269 , V_271 ) ;
}
F_20 ( V_45 , L_49 , V_2 ) ;
V_2 -> V_76 = V_78 ;
V_2 -> V_80 = V_78 ;
V_2 -> V_3 . V_82 = V_78 ;
F_20 ( V_45 , L_50 ) ;
F_67 ( V_45 , V_45 -> V_136 ) ;
V_87 = F_139 ( V_45 ) ;
if ( V_87 ) {
F_20 ( V_45 , L_51 , V_87 ) ;
F_140 ( V_45 ) ;
return V_87 ;
}
F_20 ( V_45 , L_52 ) ;
return 0 ;
}
static int F_141 ( struct V_238 * V_49 )
{
struct V_94 * V_45 = F_122 ( & V_49 -> V_49 ) ;
struct V_1 * V_2 = F_47 ( V_45 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_69 ; V_23 ++ )
F_142 ( & V_2 -> V_70 [ V_23 ] . V_269 ) ;
F_143 ( V_45 ) ;
F_140 ( V_45 ) ;
F_134 ( & V_49 -> V_49 , NULL ) ;
return 0 ;
}
static T_9 F_144 ( struct V_268 * V_269 ,
struct V_272 * V_273 , char * V_187 )
{
struct V_14 * V_15 = F_99 ( V_269 ,
struct V_14 ,
V_269 ) ;
if ( V_273 == & V_274 )
return sprintf ( V_187 , L_53 , V_15 -> V_22 ) ;
else if ( V_273 == & V_275 )
return sprintf ( V_187 , L_53 , V_15 -> V_20 ) ;
else if ( V_273 == & V_276 )
return sprintf ( V_187 , L_53 , V_15 -> V_18 ) ;
return 0 ;
}
static T_9 F_145 ( struct V_268 * V_269 , struct V_272 * V_273 ,
const char * V_187 , T_10 V_36 )
{
struct V_14 * V_15 = F_99 ( V_269 ,
struct V_14 ,
V_269 ) ;
struct V_94 * V_45 = F_122 (
F_99 ( V_269 -> V_277 , struct V_75 , V_269 ) ) ;
struct V_1 * V_2 = F_47 ( V_45 ) ;
long V_278 = F_146 ( V_187 , NULL , 10 ) ;
long V_87 ;
if ( V_273 == & V_274 ) {
if ( V_278 && ! V_15 -> V_22 ) {
if ( F_65 ( V_45 ) ) {
if ( F_10 ( V_15 ) ) {
F_50 ( V_45 ,
L_14 ) ;
return - V_97 ;
}
V_15 -> V_22 = 1 ;
V_2 -> V_107 = 1 ;
F_57 ( V_45 ) ;
V_2 -> V_107 = 0 ;
if ( ( V_87 = F_46 ( V_45 ) ) )
return V_87 ;
} else {
V_15 -> V_22 = 1 ;
}
} else if ( ! V_278 && V_15 -> V_22 ) {
int V_59 = V_45 -> V_59 + V_60 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_69 ; V_23 ++ ) {
if ( V_15 == & V_2 -> V_70 [ V_23 ] )
continue;
if ( ! V_2 -> V_70 [ V_23 ] . V_22 )
continue;
if ( V_59 <= V_2 -> V_70 [ V_23 ] . V_18 )
break;
}
if ( V_23 == V_69 ) {
F_50 ( V_45 , L_54 ) ;
return - V_279 ;
}
if ( F_65 ( V_45 ) ) {
V_2 -> V_107 = 1 ;
F_57 ( V_45 ) ;
V_15 -> V_22 = 0 ;
V_2 -> V_107 = 0 ;
if ( ( V_87 = F_46 ( V_45 ) ) )
return V_87 ;
}
V_15 -> V_22 = 0 ;
}
} else if ( V_273 == & V_275 ) {
if ( V_278 <= 0 || V_278 > V_280 ) {
return - V_243 ;
} else {
if ( F_65 ( V_45 ) ) {
V_2 -> V_107 = 1 ;
F_57 ( V_45 ) ;
V_2 -> V_107 = 0 ;
V_15 -> V_20 = V_278 ;
if ( ( V_87 = F_46 ( V_45 ) ) )
return V_87 ;
} else {
V_15 -> V_20 = V_278 ;
}
}
} else if ( V_273 == & V_276 ) {
if ( V_278 <= V_60 || V_278 > V_281 ) {
return - V_243 ;
} else {
if ( F_65 ( V_45 ) ) {
V_2 -> V_107 = 1 ;
F_57 ( V_45 ) ;
V_2 -> V_107 = 0 ;
V_15 -> V_18 = V_278 ;
if ( ( V_87 = F_46 ( V_45 ) ) )
return V_87 ;
} else {
V_15 -> V_18 = V_278 ;
}
}
}
V_104 ( V_45 -> V_103 , V_45 ) ;
return V_36 ;
}
static int F_147 ( struct V_75 * V_49 )
{
struct V_94 * V_45 = F_122 ( V_49 ) ;
V_104 ( V_45 -> V_103 , V_45 ) ;
return 0 ;
}
static int T_11 F_148 ( void )
{
F_149 ( V_282 L_55 , V_133 ,
V_283 , V_135 ) ;
return F_150 ( & V_284 ) ;
}
static void T_12 F_151 ( void )
{
F_152 ( & V_284 ) ;
}
