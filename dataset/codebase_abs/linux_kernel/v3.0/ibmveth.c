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
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_70 = V_2 -> V_3 . V_5 ;
T_2 V_41 = V_2 -> V_3 . V_4 [ V_70 ] . V_41 ;
unsigned int V_15 = V_41 >> 32 ;
unsigned int V_5 = V_41 & 0xffffffffUL ;
union V_43 V_44 ;
unsigned long V_42 ;
F_20 ( V_15 >= V_66 ) ;
F_20 ( V_5 >= V_2 -> V_67 [ V_15 ] . V_20 ) ;
if ( ! V_2 -> V_67 [ V_15 ] . V_22 ) {
F_34 ( V_2 ) ;
F_29 ( V_2 , & V_2 -> V_67 [ V_15 ] ) ;
return;
}
V_44 . V_53 . V_54 = V_55 |
V_2 -> V_67 [ V_15 ] . V_18 ;
V_44 . V_53 . V_56 = V_2 -> V_67 [ V_15 ] . V_27 [ V_5 ] ;
V_42 = F_24 ( V_2 -> V_48 -> V_61 , V_44 . V_44 ) ;
if ( V_42 != V_62 ) {
F_19 ( V_2 -> V_45 , L_2
L_3 , V_42 ) ;
F_30 ( V_2 , V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_41 ) ;
}
if ( ++ V_2 -> V_3 . V_5 == V_2 -> V_3 . V_71 ) {
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_9 = ! V_2 -> V_3 . V_9 ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_2 -> V_3 . V_4 [ V_2 -> V_3 . V_5 ] . V_41 ) ;
if ( ++ V_2 -> V_3 . V_5 == V_2 -> V_3 . V_71 ) {
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_9 = ! V_2 -> V_3 . V_9 ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
int V_23 ;
struct V_72 * V_49 = & V_2 -> V_48 -> V_49 ;
if ( V_2 -> V_69 != NULL ) {
if ( ! F_22 ( V_49 , V_2 -> V_73 ) ) {
F_26 ( V_49 , V_2 -> V_73 , 4096 ,
V_74 ) ;
V_2 -> V_73 = V_75 ;
}
F_36 ( ( unsigned long ) V_2 -> V_69 ) ;
V_2 -> V_69 = NULL ;
}
if ( V_2 -> V_76 != NULL ) {
if ( ! F_22 ( V_49 , V_2 -> V_77 ) ) {
F_26 ( V_49 , V_2 -> V_77 , 4096 ,
V_74 ) ;
V_2 -> V_77 = V_75 ;
}
F_36 ( ( unsigned long ) V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
}
if ( V_2 -> V_3 . V_4 != NULL ) {
if ( ! F_22 ( V_49 , V_2 -> V_3 . V_78 ) ) {
F_26 ( V_49 ,
V_2 -> V_3 . V_78 ,
V_2 -> V_3 . V_79 ,
V_74 ) ;
V_2 -> V_3 . V_78 = V_75 ;
}
F_11 ( V_2 -> V_3 . V_4 ) ;
V_2 -> V_3 . V_4 = NULL ;
}
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ )
if ( V_2 -> V_67 [ V_23 ] . V_22 )
F_29 ( V_2 ,
& V_2 -> V_67 [ V_23 ] ) ;
if ( V_2 -> V_80 != NULL ) {
if ( ! F_22 ( V_49 , V_2 -> V_81 ) ) {
F_26 ( & V_2 -> V_48 -> V_49 ,
V_2 -> V_81 ,
V_2 -> V_45 -> V_59 + V_60 ,
V_74 ) ;
V_2 -> V_81 = V_75 ;
}
F_11 ( V_2 -> V_80 ) ;
V_2 -> V_80 = NULL ;
}
}
static int F_37 ( struct V_1 * V_2 ,
union V_43 V_82 , T_2 V_83 )
{
int V_84 , V_85 = 1 ;
V_86:
V_84 = F_38 ( V_2 -> V_48 -> V_61 ,
V_2 -> V_73 , V_82 . V_44 ,
V_2 -> V_77 , V_83 ) ;
if ( V_84 != V_62 && V_85 ) {
do {
V_84 = F_39 ( V_2 -> V_48 -> V_61 ) ;
} while ( F_40 ( V_84 ) || ( V_84 == V_87 ) );
V_85 = 0 ;
goto V_86;
}
return V_84 ;
}
static int F_41 ( struct V_88 * V_45 )
{
struct V_1 * V_2 = F_42 ( V_45 ) ;
T_2 V_83 = 0 ;
int V_89 = 1 ;
unsigned long V_42 ;
int V_84 ;
union V_43 V_82 ;
int V_23 ;
struct V_72 * V_49 ;
F_19 ( V_45 , L_4 ) ;
F_43 ( & V_2 -> V_90 ) ;
for( V_23 = 0 ; V_23 < V_66 ; V_23 ++ )
V_89 += V_2 -> V_67 [ V_23 ] . V_20 ;
V_2 -> V_69 = ( void * ) F_44 ( V_26 ) ;
V_2 -> V_76 = ( void * ) F_44 ( V_26 ) ;
if ( ! V_2 -> V_69 || ! V_2 -> V_76 ) {
F_45 ( V_45 , L_5
L_6 ) ;
V_84 = - V_91 ;
goto V_92;
}
V_2 -> V_3 . V_79 = sizeof( struct V_93 ) *
V_89 ;
V_2 -> V_3 . V_4 = F_10 ( V_2 -> V_3 . V_79 ,
V_26 ) ;
if ( ! V_2 -> V_3 . V_4 ) {
F_45 ( V_45 , L_7 ) ;
V_84 = - V_91 ;
goto V_92;
}
V_49 = & V_2 -> V_48 -> V_49 ;
V_2 -> V_73 = F_21 ( V_49 ,
V_2 -> V_69 , 4096 , V_74 ) ;
V_2 -> V_77 = F_21 ( V_49 ,
V_2 -> V_76 , 4096 , V_74 ) ;
V_2 -> V_3 . V_78 = F_21 ( V_49 ,
V_2 -> V_3 . V_4 ,
V_2 -> V_3 . V_79 , V_74 ) ;
if ( ( F_22 ( V_49 , V_2 -> V_73 ) ) ||
( F_22 ( V_49 , V_2 -> V_77 ) ) ||
( F_22 ( V_49 , V_2 -> V_3 . V_78 ) ) ) {
F_45 ( V_45 , L_8
L_6 ) ;
V_84 = - V_91 ;
goto V_92;
}
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_71 = V_89 ;
V_2 -> V_3 . V_9 = 1 ;
memcpy ( & V_83 , V_45 -> V_94 , V_45 -> V_95 ) ;
V_83 = V_83 >> 16 ;
V_82 . V_53 . V_54 = V_55 |
V_2 -> V_3 . V_79 ;
V_82 . V_53 . V_56 = V_2 -> V_3 . V_78 ;
F_19 ( V_45 , L_9 , V_2 -> V_69 ) ;
F_19 ( V_45 , L_10 , V_2 -> V_76 ) ;
F_19 ( V_45 , L_11 , V_2 -> V_3 . V_4 ) ;
F_46 ( V_2 -> V_48 -> V_61 , V_96 ) ;
V_42 = F_37 ( V_2 , V_82 , V_83 ) ;
if ( V_42 != V_62 ) {
F_45 ( V_45 , L_12 ,
V_42 ) ;
F_45 ( V_45 , L_13
L_14 ,
V_2 -> V_73 ,
V_2 -> V_77 ,
V_82 . V_44 ,
V_83 ) ;
V_84 = - V_97 ;
goto V_92;
}
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
if ( ! V_2 -> V_67 [ V_23 ] . V_22 )
continue;
if ( F_9 ( & V_2 -> V_67 [ V_23 ] ) ) {
F_45 ( V_45 , L_15 ) ;
V_2 -> V_67 [ V_23 ] . V_22 = 0 ;
V_84 = - V_91 ;
goto V_92;
}
}
F_19 ( V_45 , L_16 , V_45 -> V_98 ) ;
V_84 = F_47 ( V_45 -> V_98 , V_99 , 0 , V_45 -> V_100 ,
V_45 ) ;
if ( V_84 != 0 ) {
F_45 ( V_45 , L_17 ,
V_45 -> V_98 , V_84 ) ;
do {
V_84 = F_39 ( V_2 -> V_48 -> V_61 ) ;
} while ( F_40 ( V_84 ) || ( V_84 == V_87 ) );
goto V_92;
}
V_2 -> V_80 =
F_10 ( V_45 -> V_59 + V_60 , V_26 ) ;
if ( ! V_2 -> V_80 ) {
F_45 ( V_45 , L_18 ) ;
V_84 = - V_91 ;
goto V_101;
}
V_2 -> V_81 =
F_21 ( & V_2 -> V_48 -> V_49 , V_2 -> V_80 ,
V_45 -> V_59 + V_60 , V_74 ) ;
if ( F_22 ( V_49 , V_2 -> V_81 ) ) {
F_45 ( V_45 , L_19 ) ;
V_84 = - V_91 ;
goto V_101;
}
F_19 ( V_45 , L_20 ) ;
V_99 ( V_45 -> V_98 , V_45 ) ;
F_48 ( V_45 ) ;
F_19 ( V_45 , L_21 ) ;
return 0 ;
V_101:
F_49 ( V_45 -> V_98 , V_45 ) ;
V_92:
F_35 ( V_2 ) ;
F_50 ( & V_2 -> V_90 ) ;
return V_84 ;
}
static int F_51 ( struct V_88 * V_45 )
{
struct V_1 * V_2 = F_42 ( V_45 ) ;
long V_42 ;
F_19 ( V_45 , L_22 ) ;
F_50 ( & V_2 -> V_90 ) ;
if ( ! V_2 -> V_102 )
F_52 ( V_45 ) ;
F_46 ( V_2 -> V_48 -> V_61 , V_96 ) ;
do {
V_42 = F_39 ( V_2 -> V_48 -> V_61 ) ;
} while ( F_40 ( V_42 ) || ( V_42 == V_87 ) );
if ( V_42 != V_62 ) {
F_45 ( V_45 , L_23
L_24 , V_42 ) ;
}
F_49 ( V_45 -> V_98 , V_45 ) ;
V_2 -> V_68 = * ( T_2 * ) ( ( ( char * ) V_2 -> V_69 ) +
4096 - 8 ) ;
F_35 ( V_2 ) ;
F_19 ( V_45 , L_25 ) ;
return 0 ;
}
static int F_53 ( struct V_88 * V_49 , struct V_103 * V_104 )
{
V_104 -> V_105 = ( V_106 | V_107 |
V_108 ) ;
V_104 -> V_109 = ( V_110 | V_111 |
V_112 ) ;
F_54 ( V_104 , V_113 ) ;
V_104 -> V_114 = V_115 ;
V_104 -> V_116 = V_117 ;
V_104 -> V_118 = 0 ;
V_104 -> V_119 = V_120 ;
V_104 -> V_121 = V_122 ;
V_104 -> V_123 = 0 ;
V_104 -> V_124 = 1 ;
return 0 ;
}
static void F_55 ( struct V_88 * V_49 ,
struct V_125 * V_126 )
{
strncpy ( V_126 -> V_127 , V_128 , sizeof( V_126 -> V_127 ) - 1 ) ;
strncpy ( V_126 -> V_129 , V_130 ,
sizeof( V_126 -> V_129 ) - 1 ) ;
}
static T_1 F_56 ( struct V_88 * V_49 , T_1 V_131 )
{
if ( ! ( V_131 & V_132 ) )
V_131 &= ~ V_133 ;
return V_131 ;
}
static int F_57 ( struct V_88 * V_49 , T_1 V_50 )
{
struct V_1 * V_2 = F_42 ( V_49 ) ;
unsigned long V_134 , V_135 , V_136 ;
unsigned long V_137 , V_138 ;
long V_139 , V_140 ;
int V_141 = 0 , V_142 = 0 ;
int V_143 = 0 ;
if ( F_58 ( V_49 ) ) {
V_143 = 1 ;
V_2 -> V_102 = 1 ;
F_51 ( V_49 ) ;
V_2 -> V_102 = 0 ;
}
V_134 = 0 ;
V_135 = 0 ;
if ( V_50 ) {
V_134 = V_144 ;
V_137 = V_145 ;
} else {
V_135 = V_144 ;
V_138 = V_145 ;
}
V_139 = F_59 ( V_2 -> V_48 -> V_61 , 0 , 0 , & V_136 ) ;
if ( V_139 == V_62 && ! ( V_136 & V_146 ) &&
! ( V_136 & V_147 ) &&
( V_136 & V_148 ) ) {
V_139 = F_59 ( V_2 -> V_48 -> V_61 , V_135 ,
V_134 , & V_136 ) ;
if ( V_139 != V_62 ) {
F_45 ( V_49 , L_26
L_27 ,
V_50 , V_139 ) ;
V_139 = F_59 ( V_2 -> V_48 -> V_61 ,
V_134 , V_135 , & V_136 ) ;
} else {
V_2 -> V_149 = V_50 ;
}
V_140 = F_59 ( V_2 -> V_48 -> V_61 ,
V_138 , V_137 , & V_136 ) ;
if ( V_140 != V_62 ) {
F_45 ( V_49 , L_28
L_27 ,
V_50 , V_139 ) ;
V_139 = F_59 ( V_2 -> V_48 -> V_61 ,
V_137 , V_138 ,
& V_136 ) ;
} else
V_2 -> V_150 = V_50 ;
if ( V_139 != V_62 || V_140 != V_62 )
V_2 -> V_151 = V_50 ;
else
V_141 = - V_152 ;
} else {
V_141 = - V_152 ;
F_45 ( V_49 , L_29
L_30 , V_50 , V_139 ,
V_136 ) ;
}
if ( V_143 )
V_142 = F_41 ( V_49 ) ;
return V_141 ? V_141 : V_142 ;
}
static int F_60 ( struct V_88 * V_49 , T_1 V_131 )
{
struct V_1 * V_2 = F_42 ( V_49 ) ;
int V_151 = ! ! ( V_131 & V_132 ) ;
int V_84 ;
if ( V_151 == V_2 -> V_151 )
return 0 ;
V_84 = F_57 ( V_49 , V_151 ) ;
if ( V_84 && ! V_2 -> V_151 )
V_49 -> V_131 = V_131 & ~ ( V_133 | V_132 ) ;
return V_84 ;
}
static void F_61 ( struct V_88 * V_49 , T_1 V_153 , T_3 * V_50 )
{
int V_23 ;
if ( V_153 != V_154 )
return;
for ( V_23 = 0 ; V_23 < F_62 ( V_155 ) ; V_23 ++ , V_50 += V_156 )
memcpy ( V_50 , V_155 [ V_23 ] . V_100 , V_156 ) ;
}
static int F_63 ( struct V_88 * V_49 , int V_157 )
{
switch ( V_157 ) {
case V_154 :
return F_62 ( V_155 ) ;
default:
return - V_158 ;
}
}
static void F_64 ( struct V_88 * V_49 ,
struct V_159 * V_160 , T_2 * V_50 )
{
int V_23 ;
struct V_1 * V_2 = F_42 ( V_49 ) ;
for ( V_23 = 0 ; V_23 < F_62 ( V_155 ) ; V_23 ++ )
V_50 [ V_23 ] = F_65 ( V_2 , V_155 [ V_23 ] . V_34 ) ;
}
static int F_66 ( struct V_88 * V_49 , struct V_161 * V_162 , int V_104 )
{
return - V_158 ;
}
static int F_67 ( struct V_1 * V_2 ,
union V_43 * V_163 )
{
unsigned long V_41 ;
unsigned int V_164 ;
unsigned long V_139 ;
V_164 = 1024 ;
V_41 = 0 ;
do {
V_139 = F_68 ( V_2 -> V_48 -> V_61 ,
V_163 [ 0 ] . V_44 , V_163 [ 1 ] . V_44 ,
V_163 [ 2 ] . V_44 , V_163 [ 3 ] . V_44 ,
V_163 [ 4 ] . V_44 , V_163 [ 5 ] . V_44 ,
V_41 , & V_41 ) ;
} while ( ( V_139 == V_87 ) && ( V_164 -- ) );
if ( V_139 != V_62 && V_139 != V_165 ) {
F_45 ( V_2 -> V_45 , L_31
L_32 , V_139 ) ;
return 1 ;
}
return 0 ;
}
static T_4 F_69 ( struct V_38 * V_39 ,
struct V_88 * V_45 )
{
struct V_1 * V_2 = F_42 ( V_45 ) ;
unsigned int V_166 ;
union V_43 V_163 [ 6 ] ;
int V_167 , V_23 ;
int V_168 = 0 ;
if ( F_70 ( V_39 ) -> V_169 > 5 && F_71 ( V_39 ) ) {
V_45 -> V_160 . V_170 ++ ;
goto V_171;
}
if ( V_39 -> V_172 == V_173 &&
( ( V_39 -> V_174 == F_72 ( V_175 ) &&
F_73 ( V_39 ) -> V_174 != V_176 ) ||
( V_39 -> V_174 == F_72 ( V_177 ) &&
F_74 ( V_39 ) -> V_178 != V_176 ) ) &&
F_75 ( V_39 ) ) {
F_45 ( V_45 , L_33 ) ;
V_45 -> V_160 . V_170 ++ ;
goto V_171;
}
V_166 = V_55 ;
if ( V_39 -> V_172 == V_173 ) {
unsigned char * V_179 = F_76 ( V_39 ) +
V_39 -> V_180 ;
V_166 |= ( V_181 | V_182 ) ;
V_179 [ 0 ] = 0 ;
V_179 [ 1 ] = 0 ;
}
V_183:
memset ( V_163 , 0 , sizeof( V_163 ) ) ;
if ( V_168 || ( ! F_77 ( V_39 ) &&
( V_39 -> V_58 < V_184 ) ) ) {
F_78 ( V_39 , V_2 -> V_80 ,
V_39 -> V_58 ) ;
V_163 [ 0 ] . V_53 . V_54 = V_166 | V_39 -> V_58 ;
V_163 [ 0 ] . V_53 . V_56 = V_2 -> V_81 ;
if ( F_67 ( V_2 , V_163 ) ) {
V_2 -> V_185 ++ ;
V_45 -> V_160 . V_170 ++ ;
} else {
V_45 -> V_160 . V_186 ++ ;
V_45 -> V_160 . V_187 += V_39 -> V_58 ;
}
goto V_171;
}
V_163 [ 0 ] . V_53 . V_56 = F_21 ( & V_2 -> V_48 -> V_49 , V_39 -> V_50 ,
F_79 ( V_39 ) ,
V_188 ) ;
if ( F_22 ( & V_2 -> V_48 -> V_49 , V_163 [ 0 ] . V_53 . V_56 ) )
goto V_189;
V_163 [ 0 ] . V_53 . V_54 = V_166 | F_79 ( V_39 ) ;
for ( V_23 = 0 ; V_23 < F_70 ( V_39 ) -> V_169 ; V_23 ++ ) {
unsigned long V_27 ;
T_5 * V_190 = & F_70 ( V_39 ) -> V_191 [ V_23 ] ;
V_27 = F_80 ( & V_2 -> V_48 -> V_49 , V_190 -> V_192 ,
V_190 -> V_193 , V_190 -> V_20 ,
V_188 ) ;
if ( F_22 ( & V_2 -> V_48 -> V_49 , V_27 ) )
goto V_194;
V_163 [ V_23 + 1 ] . V_53 . V_54 = V_166 | V_190 -> V_20 ;
V_163 [ V_23 + 1 ] . V_53 . V_56 = V_27 ;
}
if ( F_67 ( V_2 , V_163 ) ) {
V_2 -> V_185 ++ ;
V_45 -> V_160 . V_170 ++ ;
} else {
V_45 -> V_160 . V_186 ++ ;
V_45 -> V_160 . V_187 += V_39 -> V_58 ;
}
for ( V_23 = 0 ; V_23 < F_70 ( V_39 ) -> V_169 + 1 ; V_23 ++ )
F_81 ( & V_2 -> V_48 -> V_49 , V_163 [ V_23 ] . V_53 . V_56 ,
V_163 [ V_23 ] . V_53 . V_54 & V_195 ,
V_188 ) ;
V_171:
F_82 ( V_39 ) ;
return V_196 ;
V_194:
V_167 = V_23 + 1 ;
for ( V_23 = 0 ; V_23 < V_167 ; V_23 ++ )
F_81 ( & V_2 -> V_48 -> V_49 , V_163 [ V_23 ] . V_53 . V_56 ,
V_163 [ V_23 ] . V_53 . V_54 & V_195 ,
V_188 ) ;
V_189:
if ( ! F_83 ( V_197 ) )
F_45 ( V_45 , L_34 ) ;
V_2 -> V_198 ++ ;
F_84 ( V_39 ) ;
V_168 = 1 ;
goto V_183;
}
static int F_85 ( struct V_199 * V_90 , int V_200 )
{
struct V_1 * V_2 =
F_86 ( V_90 , struct V_1 , V_90 ) ;
struct V_88 * V_45 = V_2 -> V_45 ;
int V_201 = 0 ;
unsigned long V_42 ;
V_202:
do {
if ( ! F_3 ( V_2 ) )
break;
F_87 () ;
if ( ! F_4 ( V_2 ) ) {
F_88 () ;
V_2 -> V_203 ++ ;
F_19 ( V_45 , L_35 ) ;
F_33 ( V_2 ) ;
} else {
struct V_38 * V_39 , * V_204 ;
int V_12 = F_6 ( V_2 ) ;
int V_34 = F_5 ( V_2 ) ;
int V_205 = F_7 ( V_2 ) ;
V_39 = F_32 ( V_2 ) ;
V_204 = NULL ;
if ( V_12 < V_206 )
V_204 = F_18 ( V_45 , V_12 ) ;
if ( V_204 ) {
F_89 ( V_204 ,
V_39 -> V_50 + V_34 ,
V_12 ) ;
if ( V_57 )
F_14 ( V_39 -> V_50 ,
V_12 + V_34 ) ;
V_39 = V_204 ;
F_33 ( V_2 ) ;
} else {
F_34 ( V_2 ) ;
F_90 ( V_39 , V_34 ) ;
}
F_91 ( V_39 , V_12 ) ;
V_39 -> V_174 = F_92 ( V_39 , V_45 ) ;
if ( V_205 )
V_39 -> V_172 = V_207 ;
F_93 ( V_39 ) ;
V_45 -> V_160 . V_208 ++ ;
V_45 -> V_160 . V_209 += V_12 ;
V_201 ++ ;
}
} while ( V_201 < V_200 );
F_28 ( V_2 ) ;
if ( V_201 < V_200 ) {
V_42 = F_46 ( V_2 -> V_48 -> V_61 ,
V_210 ) ;
F_20 ( V_42 != V_62 ) ;
F_94 ( V_90 ) ;
if ( F_3 ( V_2 ) &&
F_95 ( V_90 ) ) {
V_42 = F_46 ( V_2 -> V_48 -> V_61 ,
V_96 ) ;
goto V_202;
}
}
return V_201 ;
}
static T_6 V_99 ( int V_98 , void * V_211 )
{
struct V_88 * V_45 = V_211 ;
struct V_1 * V_2 = F_42 ( V_45 ) ;
unsigned long V_42 ;
if ( F_96 ( & V_2 -> V_90 ) ) {
V_42 = F_46 ( V_2 -> V_48 -> V_61 ,
V_96 ) ;
F_20 ( V_42 != V_62 ) ;
F_97 ( & V_2 -> V_90 ) ;
}
return V_212 ;
}
static void F_98 ( struct V_88 * V_45 )
{
struct V_1 * V_2 = F_42 ( V_45 ) ;
unsigned long V_42 ;
if ( ( V_45 -> V_213 & V_214 ) ||
( F_99 ( V_45 ) > V_2 -> V_215 ) ) {
V_42 = F_100 ( V_2 -> V_48 -> V_61 ,
V_216 |
V_217 ,
0 ) ;
if ( V_42 != V_62 ) {
F_45 ( V_45 , L_36
L_37 , V_42 ) ;
}
} else {
struct V_218 * V_219 ;
V_42 = F_100 ( V_2 -> V_48 -> V_61 ,
V_216 |
V_217 |
V_220 ,
0 ) ;
if ( V_42 != V_62 ) {
F_45 ( V_45 , L_36
L_38 ,
V_42 ) ;
}
F_101 (ha, netdev) {
unsigned long V_221 = 0 ;
memcpy ( ( ( char * ) & V_221 ) + 2 , V_219 -> V_33 , 6 ) ;
V_42 = F_100 ( V_2 -> V_48 -> V_61 ,
V_222 ,
V_221 ) ;
if ( V_42 != V_62 ) {
F_45 ( V_45 , L_39
L_40
L_41 , V_42 ) ;
}
}
V_42 = F_100 ( V_2 -> V_48 -> V_61 ,
V_223 ,
0 ) ;
if ( V_42 != V_62 ) {
F_45 ( V_45 , L_36
L_42 , V_42 ) ;
}
}
}
static int F_102 ( struct V_88 * V_49 , int V_224 )
{
struct V_1 * V_2 = F_42 ( V_49 ) ;
struct V_225 * V_226 = V_2 -> V_48 ;
int V_227 = V_224 + V_60 ;
int V_23 , V_84 ;
int V_228 = 0 ;
if ( V_224 < V_229 )
return - V_230 ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ )
if ( V_227 < V_2 -> V_67 [ V_23 ] . V_18 )
break;
if ( V_23 == V_66 )
return - V_230 ;
if ( F_58 ( V_2 -> V_45 ) ) {
V_228 = 1 ;
V_2 -> V_102 = 1 ;
F_51 ( V_2 -> V_45 ) ;
V_2 -> V_102 = 0 ;
}
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
V_2 -> V_67 [ V_23 ] . V_22 = 1 ;
if ( V_227 < V_2 -> V_67 [ V_23 ] . V_18 ) {
V_49 -> V_59 = V_224 ;
F_103 ( V_226 ,
F_104
( V_226 ) ) ;
if ( V_228 ) {
return F_41 ( V_2 -> V_45 ) ;
}
return 0 ;
}
}
if ( V_228 && ( V_84 = F_41 ( V_2 -> V_45 ) ) )
return V_84 ;
return - V_230 ;
}
static void F_105 ( struct V_88 * V_49 )
{
F_28 ( F_42 ( V_49 ) ) ;
V_99 ( V_49 -> V_98 , V_49 ) ;
}
static unsigned long F_104 ( struct V_225 * V_48 )
{
struct V_88 * V_45 = F_106 ( & V_48 -> V_49 ) ;
struct V_1 * V_2 ;
unsigned long V_139 ;
int V_23 ;
int V_231 = 1 ;
if ( V_45 == NULL )
return F_107 ( V_232 ) ;
V_2 = F_42 ( V_45 ) ;
V_139 = V_233 + V_234 ;
V_139 += F_107 ( V_45 -> V_59 ) ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
if ( V_2 -> V_67 [ V_23 ] . V_22 )
V_139 +=
V_2 -> V_67 [ V_23 ] . V_20 *
F_107 ( V_2 -> V_67 [ V_23 ] .
V_18 ) ;
V_231 += V_2 -> V_67 [ V_23 ] . V_20 ;
}
V_139 += F_107 ( V_231 * sizeof( struct V_93 ) ) ;
return V_139 ;
}
static int T_7 F_108 ( struct V_225 * V_49 ,
const struct V_235 * V_236 )
{
int V_84 , V_23 ;
struct V_88 * V_45 ;
struct V_1 * V_2 ;
unsigned char * V_237 ;
unsigned int * V_238 ;
F_109 ( & V_49 -> V_49 , L_43 ,
V_49 -> V_61 ) ;
V_237 = ( unsigned char * ) F_110 ( V_49 , V_239 ,
NULL ) ;
if ( ! V_237 ) {
F_111 ( & V_49 -> V_49 , L_44 ) ;
return - V_230 ;
}
V_238 = ( unsigned int * ) F_110 ( V_49 ,
V_240 , NULL ) ;
if ( ! V_238 ) {
F_111 ( & V_49 -> V_49 , L_45
L_46 ) ;
return - V_230 ;
}
V_45 = F_112 ( sizeof( struct V_1 ) ) ;
if ( ! V_45 )
return - V_91 ;
V_2 = F_42 ( V_45 ) ;
F_113 ( & V_49 -> V_49 , V_45 ) ;
V_2 -> V_48 = V_49 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_215 = * V_238 ;
V_2 -> V_102 = 0 ;
F_114 ( V_45 , & V_2 -> V_90 , F_85 , 16 ) ;
if ( ( * V_237 & 0x3 ) != 0x02 )
V_237 += 2 ;
V_2 -> V_241 = 0 ;
memcpy ( & V_2 -> V_241 , V_237 , 6 ) ;
V_45 -> V_98 = V_49 -> V_98 ;
V_45 -> V_242 = & V_243 ;
V_45 -> V_244 = & V_245 ;
F_115 ( V_45 , & V_49 -> V_49 ) ;
V_45 -> V_246 = V_247 | V_132 |
V_248 | V_249 ;
V_45 -> V_131 |= V_45 -> V_246 ;
memcpy ( V_45 -> V_94 , & V_2 -> V_241 , V_45 -> V_95 ) ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ ) {
struct V_250 * V_251 = & V_2 -> V_67 [ V_23 ] . V_251 ;
int error ;
F_8 ( & V_2 -> V_67 [ V_23 ] , V_23 ,
V_252 [ V_23 ] , V_17 [ V_23 ] ,
V_19 [ V_23 ] ) ;
error = F_116 ( V_251 , & V_253 ,
& V_49 -> V_49 . V_251 , L_47 , V_23 ) ;
if ( ! error )
F_117 ( V_251 , V_254 ) ;
}
F_19 ( V_45 , L_48 , V_2 ) ;
V_2 -> V_73 = V_75 ;
V_2 -> V_77 = V_75 ;
V_2 -> V_3 . V_78 = V_75 ;
F_19 ( V_45 , L_49 ) ;
F_60 ( V_45 , V_45 -> V_131 ) ;
V_84 = F_118 ( V_45 ) ;
if ( V_84 ) {
F_19 ( V_45 , L_50 , V_84 ) ;
F_119 ( V_45 ) ;
return V_84 ;
}
F_19 ( V_45 , L_51 ) ;
return 0 ;
}
static int T_8 F_120 ( struct V_225 * V_49 )
{
struct V_88 * V_45 = F_106 ( & V_49 -> V_49 ) ;
struct V_1 * V_2 = F_42 ( V_45 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_66 ; V_23 ++ )
F_121 ( & V_2 -> V_67 [ V_23 ] . V_251 ) ;
F_122 ( V_45 ) ;
F_119 ( V_45 ) ;
F_113 ( & V_49 -> V_49 , NULL ) ;
return 0 ;
}
static T_9 F_123 ( struct V_250 * V_251 ,
struct V_255 * V_256 , char * V_179 )
{
struct V_14 * V_15 = F_86 ( V_251 ,
struct V_14 ,
V_251 ) ;
if ( V_256 == & V_257 )
return sprintf ( V_179 , L_52 , V_15 -> V_22 ) ;
else if ( V_256 == & V_258 )
return sprintf ( V_179 , L_52 , V_15 -> V_20 ) ;
else if ( V_256 == & V_259 )
return sprintf ( V_179 , L_52 , V_15 -> V_18 ) ;
return 0 ;
}
static T_9 F_124 ( struct V_250 * V_251 , struct V_255 * V_256 ,
const char * V_179 , T_10 V_36 )
{
struct V_14 * V_15 = F_86 ( V_251 ,
struct V_14 ,
V_251 ) ;
struct V_88 * V_45 = F_106 (
F_86 ( V_251 -> V_260 , struct V_72 , V_251 ) ) ;
struct V_1 * V_2 = F_42 ( V_45 ) ;
long V_261 = F_125 ( V_179 , NULL , 10 ) ;
long V_84 ;
if ( V_256 == & V_257 ) {
if ( V_261 && ! V_15 -> V_22 ) {
if ( F_58 ( V_45 ) ) {
if ( F_9 ( V_15 ) ) {
F_45 ( V_45 ,
L_15 ) ;
return - V_91 ;
}
V_15 -> V_22 = 1 ;
V_2 -> V_102 = 1 ;
F_51 ( V_45 ) ;
V_2 -> V_102 = 0 ;
if ( ( V_84 = F_41 ( V_45 ) ) )
return V_84 ;
} else {
V_15 -> V_22 = 1 ;
}
} else if ( ! V_261 && V_15 -> V_22 ) {
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
F_45 ( V_45 , L_53 ) ;
return - V_262 ;
}
if ( F_58 ( V_45 ) ) {
V_2 -> V_102 = 1 ;
F_51 ( V_45 ) ;
V_15 -> V_22 = 0 ;
V_2 -> V_102 = 0 ;
if ( ( V_84 = F_41 ( V_45 ) ) )
return V_84 ;
}
V_15 -> V_22 = 0 ;
}
} else if ( V_256 == & V_258 ) {
if ( V_261 <= 0 || V_261 > V_263 ) {
return - V_230 ;
} else {
if ( F_58 ( V_45 ) ) {
V_2 -> V_102 = 1 ;
F_51 ( V_45 ) ;
V_2 -> V_102 = 0 ;
V_15 -> V_20 = V_261 ;
if ( ( V_84 = F_41 ( V_45 ) ) )
return V_84 ;
} else {
V_15 -> V_20 = V_261 ;
}
}
} else if ( V_256 == & V_259 ) {
if ( V_261 <= V_60 || V_261 > V_264 ) {
return - V_230 ;
} else {
if ( F_58 ( V_45 ) ) {
V_2 -> V_102 = 1 ;
F_51 ( V_45 ) ;
V_2 -> V_102 = 0 ;
V_15 -> V_18 = V_261 ;
if ( ( V_84 = F_41 ( V_45 ) ) )
return V_84 ;
} else {
V_15 -> V_18 = V_261 ;
}
}
}
V_99 ( V_45 -> V_98 , V_45 ) ;
return V_36 ;
}
static int F_126 ( struct V_72 * V_49 )
{
struct V_88 * V_45 = F_106 ( V_49 ) ;
V_99 ( V_45 -> V_98 , V_45 ) ;
return 0 ;
}
static int T_11 F_127 ( void )
{
F_128 ( V_265 L_54 , V_128 ,
V_266 , V_130 ) ;
return F_129 ( & V_267 ) ;
}
static void T_12 F_130 ( void )
{
F_131 ( & V_267 ) ;
}
