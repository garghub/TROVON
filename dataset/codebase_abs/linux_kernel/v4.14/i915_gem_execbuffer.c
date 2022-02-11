static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_1 , V_2 ) ;
}
static inline T_1 F_3 ( T_1 V_1 )
{
return V_1 & F_4 ( V_2 , 0 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> args -> V_5 & V_6 ) ) {
unsigned int V_7 = 1 + F_6 ( V_4 -> V_8 ) ;
do {
T_2 V_5 ;
V_5 = V_9 ;
if ( V_7 > 1 )
V_5 |= V_10 | V_11 ;
V_4 -> V_12 = F_7 ( sizeof( struct V_13 ) << V_7 ,
V_5 ) ;
if ( V_4 -> V_12 )
break;
} while ( -- V_7 );
if ( F_8 ( ! V_7 ) )
return - V_14 ;
V_4 -> V_15 = V_7 ;
} else {
V_4 -> V_15 = - V_4 -> V_8 ;
}
return 0 ;
}
static bool
F_9 ( const struct V_16 * V_17 ,
const struct V_18 * V_19 ,
unsigned int V_5 )
{
if ( V_19 -> V_20 . V_7 < V_17 -> V_21 )
return true ;
if ( V_17 -> V_22 && ! F_10 ( V_19 -> V_20 . V_23 , V_17 -> V_22 ) )
return true ;
if ( V_5 & V_24 &&
V_19 -> V_20 . V_23 != V_17 -> V_25 )
return true ;
if ( V_5 & V_26 &&
V_19 -> V_20 . V_23 < V_27 )
return true ;
if ( ! ( V_5 & V_28 ) &&
( V_19 -> V_20 . V_23 + V_19 -> V_20 . V_7 - 1 ) >> 32 )
return true ;
if ( V_5 & V_29 &&
! F_11 ( V_19 ) )
return true ;
return false ;
}
static inline bool
F_12 ( struct V_3 * V_4 ,
const struct V_16 * V_17 ,
struct V_18 * V_19 )
{
unsigned int V_30 = * V_19 -> V_30 ;
T_1 V_31 ;
if ( V_19 -> V_20 . V_7 )
V_31 = V_19 -> V_20 . V_23 ;
else
V_31 = V_17 -> V_25 & V_32 ;
V_31 |= V_33 | V_34 | V_35 ;
if ( F_8 ( V_30 & V_36 ) )
V_31 |= V_37 ;
if ( F_8 ( F_13 ( V_19 , 0 , 0 , V_31 ) ) )
return false ;
if ( F_8 ( V_30 & V_38 ) ) {
if ( F_8 ( F_14 ( V_19 ) ) ) {
F_15 ( V_19 ) ;
return false ;
}
if ( F_16 ( V_19 ) )
V_30 |= V_39 ;
}
* V_19 -> V_30 = V_30 | V_40 ;
return ! F_9 ( V_17 , V_19 , V_30 ) ;
}
static inline void F_17 ( struct V_18 * V_19 , unsigned int V_5 )
{
F_18 ( ! ( V_5 & V_40 ) ) ;
if ( F_8 ( V_5 & V_39 ) )
F_19 ( V_19 ) ;
F_20 ( V_19 ) ;
}
static inline void
F_21 ( struct V_18 * V_19 , unsigned int * V_5 )
{
if ( ! ( * V_5 & V_40 ) )
return;
F_17 ( V_19 , * V_5 ) ;
* V_5 &= ~ V_41 ;
}
static int
F_22 ( struct V_3 * V_4 ,
struct V_16 * V_17 ,
struct V_18 * V_19 )
{
if ( F_8 ( V_17 -> V_5 & V_4 -> V_42 ) )
return - V_43 ;
if ( F_8 ( V_17 -> V_22 && ! F_23 ( V_17 -> V_22 ) ) )
return - V_43 ;
if ( F_8 ( V_17 -> V_5 & V_24 &&
V_17 -> V_25 != F_1 ( V_17 -> V_25 & V_44 ) ) )
return - V_43 ;
if ( V_17 -> V_5 & V_45 ) {
if ( F_8 ( F_24 ( V_17 -> V_21 ) ) )
return - V_43 ;
} else {
V_17 -> V_21 = 0 ;
}
if ( F_8 ( V_19 -> V_30 ) ) {
F_25 ( L_1 ,
V_17 -> V_46 , ( int ) ( V_17 - V_4 -> V_47 ) ) ;
return - V_43 ;
}
V_17 -> V_25 = F_3 ( V_17 -> V_25 ) ;
if ( ! V_4 -> V_48 . V_49 ) {
V_17 -> V_5 &= ~ V_38 ;
} else {
if ( ( V_17 -> V_5 & V_38 ||
V_4 -> V_48 . V_50 ) &&
F_26 ( V_19 -> V_51 ) )
V_17 -> V_5 |= V_36 | V_29 ;
}
if ( ! ( V_17 -> V_5 & V_24 ) )
V_17 -> V_5 |= V_4 -> V_52 ;
return 0 ;
}
static int
F_27 ( struct V_3 * V_4 , unsigned int V_53 , struct V_18 * V_19 )
{
struct V_16 * V_17 = & V_4 -> V_47 [ V_53 ] ;
int V_54 ;
F_18 ( F_28 ( V_19 ) ) ;
if ( ! ( V_4 -> args -> V_5 & V_55 ) ) {
V_54 = F_22 ( V_4 , V_17 , V_19 ) ;
if ( F_8 ( V_54 ) )
return V_54 ;
}
if ( V_4 -> V_15 > 0 ) {
V_19 -> V_56 = V_17 -> V_46 ;
F_29 ( & V_19 -> V_57 ,
& V_4 -> V_12 [ F_30 ( V_17 -> V_46 ,
V_4 -> V_15 ) ] ) ;
}
if ( V_17 -> V_58 )
F_31 ( & V_19 -> V_59 , & V_4 -> V_60 ) ;
V_4 -> V_19 [ V_53 ] = V_19 ;
V_4 -> V_5 [ V_53 ] = V_17 -> V_5 ;
V_19 -> V_30 = & V_4 -> V_5 [ V_53 ] ;
V_54 = 0 ;
if ( F_12 ( V_4 , V_17 , V_19 ) ) {
if ( V_17 -> V_25 != V_19 -> V_20 . V_23 ) {
V_17 -> V_25 = V_19 -> V_20 . V_23 | V_61 ;
V_4 -> args -> V_5 |= V_62 ;
}
} else {
F_21 ( V_19 , V_19 -> V_30 ) ;
F_31 ( & V_19 -> V_63 , & V_4 -> V_64 ) ;
if ( F_32 ( & V_19 -> V_20 ) )
V_54 = F_33 ( V_19 ) ;
}
return V_54 ;
}
static inline int F_34 ( const struct V_48 * V_65 ,
const struct V_66 * V_51 )
{
if ( ! F_35 ( V_51 ) )
return false ;
if ( V_67 == V_68 )
return true ;
if ( V_67 == V_69 )
return false ;
return ( V_65 -> V_70 ||
V_51 -> V_71 ||
V_51 -> V_72 != V_73 ) ;
}
static int F_36 ( const struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_16 * V_17 = F_37 ( V_4 , V_19 ) ;
unsigned int V_30 = * V_19 -> V_30 ;
T_1 V_31 ;
int V_54 ;
V_31 = V_33 | V_74 ;
if ( V_30 & V_36 )
V_31 |= V_37 ;
if ( ! ( V_30 & V_28 ) )
V_31 |= V_75 ;
if ( V_30 & V_29 )
V_31 |= V_76 ;
if ( V_30 & V_24 ) {
V_31 |= V_17 -> V_25 | V_35 ;
V_31 &= ~ V_74 ;
} else if ( V_30 & V_26 ) {
V_31 |= V_27 | V_77 ;
}
V_54 = F_13 ( V_19 ,
V_17 -> V_21 , V_17 -> V_22 ,
V_31 ) ;
if ( V_54 )
return V_54 ;
if ( V_17 -> V_25 != V_19 -> V_20 . V_23 ) {
V_17 -> V_25 = V_19 -> V_20 . V_23 | V_61 ;
V_4 -> args -> V_5 |= V_62 ;
}
if ( F_8 ( V_30 & V_38 ) ) {
V_54 = F_14 ( V_19 ) ;
if ( F_8 ( V_54 ) ) {
F_15 ( V_19 ) ;
return V_54 ;
}
if ( F_16 ( V_19 ) )
V_30 |= V_39 ;
}
* V_19 -> V_30 = V_30 | V_40 ;
F_18 ( F_9 ( V_17 , V_19 , V_30 ) ) ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 )
{
const unsigned int V_78 = V_4 -> V_8 ;
struct V_79 V_80 ;
struct V_18 * V_19 ;
unsigned int V_53 , V_81 ;
int V_54 ;
V_81 = 0 ;
V_54 = 0 ;
do {
F_39 (vma, &eb->unbound, exec_link) {
V_54 = F_36 ( V_4 , V_19 ) ;
if ( V_54 )
break;
}
if ( V_54 != - V_82 )
return V_54 ;
F_40 ( & V_4 -> V_64 ) ;
F_40 ( & V_80 ) ;
for ( V_53 = 0 ; V_53 < V_78 ; V_53 ++ ) {
unsigned int V_5 = V_4 -> V_5 [ V_53 ] ;
struct V_18 * V_19 = V_4 -> V_19 [ V_53 ] ;
if ( V_5 & V_24 &&
V_5 & V_40 )
continue;
F_21 ( V_19 , & V_4 -> V_5 [ V_53 ] ) ;
if ( V_5 & V_24 )
F_41 ( & V_19 -> V_63 , & V_4 -> V_64 ) ;
else if ( V_5 & V_29 )
F_31 ( & V_19 -> V_63 , & V_4 -> V_64 ) ;
else
F_31 ( & V_19 -> V_63 , & V_80 ) ;
}
F_42 ( & V_80 , & V_4 -> V_64 ) ;
switch ( V_81 ++ ) {
case 0 :
break;
case 1 :
V_54 = F_43 ( V_4 -> V_83 ) ;
if ( V_54 )
return V_54 ;
break;
default:
return - V_82 ;
}
} while ( 1 );
}
static unsigned int F_44 ( const struct V_3 * V_4 )
{
if ( V_4 -> args -> V_5 & V_84 )
return 0 ;
else
return V_4 -> V_8 - 1 ;
}
static int F_45 ( struct V_3 * V_4 )
{
struct V_85 * V_86 ;
V_86 = F_46 ( V_4 -> V_87 -> V_88 , V_4 -> args -> V_89 ) ;
if ( F_8 ( ! V_86 ) )
return - V_90 ;
V_4 -> V_86 = V_86 ;
V_4 -> V_83 = V_86 -> V_91 ? & V_86 -> V_91 -> V_92 : & V_4 -> V_93 -> V_94 . V_92 ;
V_4 -> V_52 = 0 ;
if ( V_86 -> V_5 & V_95 )
V_4 -> V_52 |= V_26 ;
return 0 ;
}
static int F_47 ( struct V_3 * V_4 )
{
struct V_96 * V_97 = & V_4 -> V_86 -> V_97 ;
struct V_66 * V_98 ( V_51 ) ;
unsigned int V_53 ;
int V_54 ;
if ( F_8 ( F_48 ( V_4 -> V_86 ) ) )
return - V_90 ;
if ( F_8 ( F_49 ( V_4 -> V_86 ) ) )
return - V_99 ;
F_40 ( & V_4 -> V_60 ) ;
F_40 ( & V_4 -> V_64 ) ;
for ( V_53 = 0 ; V_53 < V_4 -> V_8 ; V_53 ++ ) {
T_3 V_46 = V_4 -> V_47 [ V_53 ] . V_46 ;
struct V_100 * V_101 ;
struct V_18 * V_19 ;
V_19 = F_50 ( V_97 , V_46 ) ;
if ( F_51 ( V_19 ) )
goto V_102;
V_51 = F_52 ( V_4 -> V_87 , V_46 ) ;
if ( F_8 ( ! V_51 ) ) {
V_54 = - V_90 ;
goto V_103;
}
V_19 = F_53 ( V_51 , V_4 -> V_83 , NULL ) ;
if ( F_8 ( F_54 ( V_19 ) ) ) {
V_54 = F_55 ( V_19 ) ;
goto V_104;
}
V_101 = F_56 ( V_4 -> V_93 -> V_105 , V_9 ) ;
if ( F_8 ( ! V_101 ) ) {
V_54 = - V_14 ;
goto V_104;
}
V_54 = F_57 ( V_97 , V_46 , V_19 ) ;
if ( F_8 ( V_54 ) ) {
F_58 ( V_101 ) ;
goto V_104;
}
V_19 -> V_106 ++ ;
F_41 ( & V_101 -> V_107 , & V_51 -> V_108 ) ;
F_41 ( & V_101 -> V_109 , & V_4 -> V_86 -> V_110 ) ;
V_101 -> V_86 = V_4 -> V_86 ;
V_101 -> V_46 = V_46 ;
V_51 = NULL ;
V_102:
V_54 = F_27 ( V_4 , V_53 , V_19 ) ;
if ( F_8 ( V_54 ) )
goto V_104;
F_18 ( V_19 != V_4 -> V_19 [ V_53 ] ) ;
F_18 ( V_19 -> V_30 != & V_4 -> V_5 [ V_53 ] ) ;
}
V_53 = F_44 ( V_4 ) ;
V_4 -> V_111 = V_4 -> V_19 [ V_53 ] ;
F_18 ( V_4 -> V_111 -> V_30 != & V_4 -> V_5 [ V_53 ] ) ;
if ( ! ( V_4 -> V_5 [ V_53 ] & V_24 ) )
V_4 -> V_5 [ V_53 ] |= V_26 ;
if ( V_4 -> V_48 . V_49 )
V_4 -> V_5 [ V_53 ] |= V_38 ;
V_4 -> args -> V_5 |= V_55 ;
return F_38 ( V_4 ) ;
V_104:
if ( V_51 )
F_59 ( V_51 ) ;
V_103:
V_4 -> V_19 [ V_53 ] = NULL ;
return V_54 ;
}
static struct V_18 *
F_60 ( const struct V_3 * V_4 , unsigned long V_46 )
{
if ( V_4 -> V_15 < 0 ) {
if ( V_46 >= - V_4 -> V_15 )
return NULL ;
return V_4 -> V_19 [ V_46 ] ;
} else {
struct V_13 * V_112 ;
struct V_18 * V_19 ;
V_112 = & V_4 -> V_12 [ F_30 ( V_46 , V_4 -> V_15 ) ] ;
F_61 (vma, head, exec_node) {
if ( V_19 -> V_56 == V_46 )
return V_19 ;
}
return NULL ;
}
}
static void F_62 ( const struct V_3 * V_4 )
{
const unsigned int V_78 = V_4 -> V_8 ;
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 < V_78 ; V_53 ++ ) {
struct V_18 * V_19 = V_4 -> V_19 [ V_53 ] ;
unsigned int V_5 = V_4 -> V_5 [ V_53 ] ;
if ( ! V_19 )
break;
F_18 ( V_19 -> V_30 != & V_4 -> V_5 [ V_53 ] ) ;
V_19 -> V_30 = NULL ;
V_4 -> V_19 [ V_53 ] = NULL ;
if ( V_5 & V_40 )
F_17 ( V_19 , V_5 ) ;
if ( V_5 & V_113 )
F_63 ( V_19 ) ;
}
}
static void F_64 ( const struct V_3 * V_4 )
{
F_62 ( V_4 ) ;
if ( V_4 -> V_15 > 0 )
memset ( V_4 -> V_12 , 0 ,
sizeof( struct V_13 ) << V_4 -> V_15 ) ;
}
static void F_65 ( const struct V_3 * V_4 )
{
F_18 ( V_4 -> V_48 . V_114 ) ;
if ( V_4 -> V_15 > 0 )
F_58 ( V_4 -> V_12 ) ;
}
static inline T_1
F_66 ( const struct V_115 * V_116 ,
const struct V_18 * V_117 )
{
return F_1 ( ( int ) V_116 -> V_118 + V_117 -> V_20 . V_23 ) ;
}
static void F_67 ( struct V_48 * V_65 ,
struct V_119 * V_93 )
{
V_65 -> V_120 = - 1 ;
V_65 -> V_121 = 0 ;
V_65 -> V_122 = F_68 ( V_93 ) ;
V_65 -> V_70 = F_69 ( V_93 ) ;
V_65 -> V_123 = F_70 ( V_93 ) ;
V_65 -> V_49 = V_65 -> V_122 < 4 ;
V_65 -> V_50 = F_71 ( V_93 ) -> V_124 ;
V_65 -> V_20 . V_125 = false ;
V_65 -> V_114 = NULL ;
V_65 -> V_126 = 0 ;
}
static inline void * F_72 ( unsigned long V_127 )
{
return ( void * ) ( V_128 ) ( V_127 & V_44 ) ;
}
static inline unsigned int F_73 ( unsigned long V_127 )
{
return V_127 & ~ V_44 ;
}
static inline struct V_129 * F_74 ( struct V_48 * V_65 )
{
struct V_119 * V_93 =
F_75 ( V_65 , struct V_3 , V_48 ) -> V_93 ;
return & V_93 -> V_94 ;
}
static void F_76 ( struct V_48 * V_65 )
{
F_18 ( V_65 -> V_126 >= V_65 -> V_114 -> V_111 -> V_51 -> V_92 . V_7 / sizeof( T_3 ) ) ;
V_65 -> V_130 [ V_65 -> V_126 ] = V_131 ;
F_77 ( V_65 -> V_114 -> V_111 -> V_51 ) ;
F_78 ( V_65 -> V_114 -> V_93 ) ;
F_79 ( V_65 -> V_114 , true ) ;
V_65 -> V_114 = NULL ;
}
static void F_80 ( struct V_48 * V_65 )
{
void * V_121 ;
if ( V_65 -> V_114 )
F_76 ( V_65 ) ;
if ( ! V_65 -> V_121 )
return;
V_121 = F_72 ( V_65 -> V_121 ) ;
if ( V_65 -> V_121 & V_132 ) {
if ( V_65 -> V_121 & V_133 )
F_81 () ;
F_82 ( V_121 ) ;
F_83 ( (struct V_66 * ) V_65 -> V_20 . V_134 ) ;
} else {
F_84 () ;
F_85 ( ( void V_135 * ) V_121 ) ;
if ( V_65 -> V_20 . V_125 ) {
struct V_129 * V_94 = F_74 ( V_65 ) ;
V_94 -> V_92 . V_136 ( & V_94 -> V_92 ,
V_65 -> V_20 . V_23 ,
V_65 -> V_20 . V_7 ) ;
F_86 ( & V_65 -> V_20 ) ;
} else {
F_15 ( (struct V_18 * ) V_65 -> V_20 . V_134 ) ;
}
}
V_65 -> V_121 = 0 ;
V_65 -> V_120 = - 1 ;
}
static void * F_87 ( struct V_66 * V_51 ,
struct V_48 * V_65 ,
unsigned long V_120 )
{
void * V_121 ;
if ( V_65 -> V_121 ) {
F_82 ( F_72 ( V_65 -> V_121 ) ) ;
} else {
unsigned int V_137 ;
int V_54 ;
V_54 = F_88 ( V_51 , & V_137 ) ;
if ( V_54 )
return F_89 ( V_54 ) ;
F_90 ( V_132 & V_138 ) ;
F_90 ( ( V_132 | V_138 ) & V_44 ) ;
V_65 -> V_121 = V_137 | V_132 ;
V_65 -> V_20 . V_134 = ( void * ) V_51 ;
if ( V_137 )
F_81 () ;
}
V_121 = F_91 ( F_92 ( V_51 , V_120 ) ) ;
V_65 -> V_121 = F_73 ( V_65 -> V_121 ) | ( unsigned long ) V_121 ;
V_65 -> V_120 = V_120 ;
return V_121 ;
}
static void * F_93 ( struct V_66 * V_51 ,
struct V_48 * V_65 ,
unsigned long V_120 )
{
struct V_129 * V_94 = F_74 ( V_65 ) ;
unsigned long V_25 ;
void * V_121 ;
if ( V_65 -> V_121 ) {
F_85 ( ( void V_139 V_135 * ) F_72 ( V_65 -> V_121 ) ) ;
} else {
struct V_18 * V_19 ;
int V_54 ;
if ( F_34 ( V_65 , V_51 ) )
return NULL ;
V_54 = F_94 ( V_51 , true ) ;
if ( V_54 )
return F_89 ( V_54 ) ;
V_19 = F_95 ( V_51 , NULL , 0 , 0 ,
V_76 | V_74 ) ;
if ( F_54 ( V_19 ) ) {
memset ( & V_65 -> V_20 , 0 , sizeof( V_65 -> V_20 ) ) ;
V_54 = F_96
( & V_94 -> V_92 . V_134 , & V_65 -> V_20 ,
V_140 , 0 , V_141 ,
0 , V_94 -> V_142 ,
V_143 ) ;
if ( V_54 )
return NULL ;
} else {
V_54 = F_97 ( V_19 ) ;
if ( V_54 ) {
F_15 ( V_19 ) ;
return F_89 ( V_54 ) ;
}
V_65 -> V_20 . V_23 = V_19 -> V_20 . V_23 ;
V_65 -> V_20 . V_134 = ( void * ) V_19 ;
}
}
V_25 = V_65 -> V_20 . V_23 ;
if ( V_65 -> V_20 . V_125 ) {
F_84 () ;
V_94 -> V_92 . V_144 ( & V_94 -> V_92 ,
F_98 ( V_51 , V_120 ) ,
V_25 , V_73 , 0 ) ;
} else {
V_25 += V_120 << V_145 ;
}
V_121 = ( void V_139 * ) F_99 ( & V_94 -> V_146 ,
V_25 ) ;
V_65 -> V_120 = V_120 ;
V_65 -> V_121 = ( unsigned long ) V_121 ;
return V_121 ;
}
static void * F_100 ( struct V_66 * V_51 ,
struct V_48 * V_65 ,
unsigned long V_120 )
{
void * V_121 ;
if ( V_65 -> V_120 == V_120 ) {
V_121 = F_72 ( V_65 -> V_121 ) ;
} else {
V_121 = NULL ;
if ( ( V_65 -> V_121 & V_132 ) == 0 )
V_121 = F_93 ( V_51 , V_65 , V_120 ) ;
if ( ! V_121 )
V_121 = F_87 ( V_51 , V_65 , V_120 ) ;
}
return V_121 ;
}
static void F_101 ( T_3 * V_147 , T_3 V_148 , unsigned int V_137 )
{
if ( F_8 ( V_137 & ( V_149 | V_133 ) ) ) {
if ( V_137 & V_149 ) {
F_102 ( V_147 ) ;
F_81 () ;
}
* V_147 = V_148 ;
if ( V_137 & V_133 )
F_102 ( V_147 ) ;
} else
* V_147 = V_148 ;
}
static int F_103 ( struct V_3 * V_4 ,
struct V_18 * V_19 ,
unsigned int V_150 )
{
struct V_48 * V_65 = & V_4 -> V_48 ;
struct V_66 * V_51 ;
struct V_151 * V_114 ;
struct V_18 * V_111 ;
T_3 * V_152 ;
int V_54 ;
F_18 ( V_19 -> V_51 -> V_92 . V_153 & V_154 ) ;
V_51 = F_104 ( & V_4 -> V_155 -> V_156 , V_140 ) ;
if ( F_54 ( V_51 ) )
return F_55 ( V_51 ) ;
V_152 = F_105 ( V_51 ,
V_65 -> V_70 ?
V_157 :
V_158 ) ;
F_106 ( V_51 ) ;
if ( F_54 ( V_152 ) )
return F_55 ( V_152 ) ;
V_54 = F_107 ( V_51 , false ) ;
if ( V_54 )
goto V_159;
V_111 = F_53 ( V_51 , V_19 -> V_83 , NULL ) ;
if ( F_54 ( V_111 ) ) {
V_54 = F_55 ( V_111 ) ;
goto V_159;
}
V_54 = F_13 ( V_111 , 0 , 0 , V_33 | V_74 ) ;
if ( V_54 )
goto V_159;
V_114 = F_108 ( V_4 -> V_155 , V_4 -> V_86 ) ;
if ( F_54 ( V_114 ) ) {
V_54 = F_55 ( V_114 ) ;
goto V_160;
}
V_54 = F_109 ( V_114 , V_19 -> V_51 , true ) ;
if ( V_54 )
goto V_161;
V_54 = V_4 -> V_155 -> V_162 ( V_114 , V_163 ) ;
if ( V_54 )
goto V_161;
V_54 = F_110 ( V_114 ) ;
if ( V_54 )
goto V_161;
V_54 = V_4 -> V_155 -> V_164 ( V_114 ,
V_111 -> V_20 . V_23 , V_140 ,
V_65 -> V_122 > 5 ? 0 : V_165 ) ;
if ( V_54 )
goto V_161;
F_18 ( ! F_111 ( V_111 -> V_166 , true ) ) ;
F_112 ( V_111 , V_114 , 0 ) ;
F_113 ( V_111 -> V_166 , NULL ) ;
F_114 ( V_111 -> V_166 , & V_114 -> V_167 ) ;
F_115 ( V_111 -> V_166 ) ;
F_15 ( V_111 ) ;
F_112 ( V_19 , V_114 , V_168 ) ;
F_113 ( V_19 -> V_166 , NULL ) ;
F_114 ( V_19 -> V_166 , & V_114 -> V_167 ) ;
F_115 ( V_19 -> V_166 ) ;
V_114 -> V_111 = V_111 ;
V_65 -> V_114 = V_114 ;
V_65 -> V_130 = V_152 ;
V_65 -> V_126 = 0 ;
return 0 ;
V_161:
F_116 ( V_114 ) ;
V_160:
F_15 ( V_111 ) ;
V_159:
F_77 ( V_51 ) ;
return V_54 ;
}
static T_3 * F_117 ( struct V_3 * V_4 ,
struct V_18 * V_19 ,
unsigned int V_150 )
{
struct V_48 * V_65 = & V_4 -> V_48 ;
T_3 * V_152 ;
if ( V_65 -> V_126 > V_140 / sizeof( T_3 ) - ( V_150 + 1 ) )
F_76 ( V_65 ) ;
if ( F_8 ( ! V_65 -> V_114 ) ) {
int V_54 ;
V_54 = F_103 ( V_4 , V_19 , V_150 ) ;
if ( F_8 ( V_54 ) )
return F_89 ( V_54 ) ;
}
V_152 = V_65 -> V_130 + V_65 -> V_126 ;
V_65 -> V_126 += V_150 ;
return V_152 ;
}
static T_1
F_118 ( struct V_18 * V_19 ,
const struct V_115 * V_116 ,
struct V_3 * V_4 ,
const struct V_18 * V_117 )
{
T_1 V_25 = V_116 -> V_25 ;
T_1 V_169 = F_66 ( V_116 , V_117 ) ;
bool V_170 = V_4 -> V_48 . V_123 ;
void * V_121 ;
if ( ! V_4 -> V_48 . V_121 &&
( V_67 == V_171 ||
! F_111 ( V_19 -> V_166 , true ) ) &&
F_119 ( V_4 -> V_48 . V_122 ,
V_4 -> V_155 -> V_172 ) ) {
const unsigned int V_122 = V_4 -> V_48 . V_122 ;
unsigned int V_150 ;
T_3 * V_111 ;
T_1 V_147 ;
if ( V_170 )
V_150 = V_25 & 7 ? 8 : 5 ;
else if ( V_122 >= 4 )
V_150 = 4 ;
else
V_150 = 3 ;
V_111 = F_117 ( V_4 , V_19 , V_150 ) ;
if ( F_54 ( V_111 ) )
goto V_173;
V_147 = F_1 ( V_19 -> V_20 . V_23 + V_25 ) ;
if ( V_170 ) {
if ( V_25 & 7 ) {
* V_111 ++ = V_174 ;
* V_111 ++ = F_120 ( V_147 ) ;
* V_111 ++ = F_121 ( V_147 ) ;
* V_111 ++ = F_120 ( V_169 ) ;
V_147 = F_1 ( V_147 + 4 ) ;
* V_111 ++ = V_174 ;
* V_111 ++ = F_120 ( V_147 ) ;
* V_111 ++ = F_121 ( V_147 ) ;
* V_111 ++ = F_121 ( V_169 ) ;
} else {
* V_111 ++ = ( V_174 | ( 1 << 21 ) ) + 1 ;
* V_111 ++ = F_120 ( V_147 ) ;
* V_111 ++ = F_121 ( V_147 ) ;
* V_111 ++ = F_120 ( V_169 ) ;
* V_111 ++ = F_121 ( V_169 ) ;
}
} else if ( V_122 >= 6 ) {
* V_111 ++ = V_174 ;
* V_111 ++ = 0 ;
* V_111 ++ = V_147 ;
* V_111 ++ = V_169 ;
} else if ( V_122 >= 4 ) {
* V_111 ++ = V_174 | V_175 ;
* V_111 ++ = 0 ;
* V_111 ++ = V_147 ;
* V_111 ++ = V_169 ;
} else {
* V_111 ++ = V_176 | V_177 ;
* V_111 ++ = V_147 ;
* V_111 ++ = V_169 ;
}
goto V_178;
}
V_173:
V_121 = F_100 ( V_19 -> V_51 , & V_4 -> V_48 , V_25 >> V_145 ) ;
if ( F_54 ( V_121 ) )
return F_55 ( V_121 ) ;
F_101 ( V_121 + F_24 ( V_25 ) ,
F_120 ( V_169 ) ,
V_4 -> V_48 . V_121 ) ;
if ( V_170 ) {
V_25 += sizeof( T_3 ) ;
V_169 >>= 32 ;
V_170 = false ;
goto V_173;
}
V_178:
return V_117 -> V_20 . V_23 | V_61 ;
}
static T_1
F_122 ( struct V_3 * V_4 ,
struct V_18 * V_19 ,
const struct V_115 * V_116 )
{
struct V_18 * V_117 ;
int V_54 ;
V_117 = F_60 ( V_4 , V_116 -> V_179 ) ;
if ( F_8 ( ! V_117 ) )
return - V_90 ;
if ( F_8 ( V_116 -> V_153 & ( V_116 -> V_153 - 1 ) ) ) {
F_25 ( L_2
L_3
L_4 ,
V_116 -> V_179 ,
( int ) V_116 -> V_25 ,
V_116 -> V_180 ,
V_116 -> V_153 ) ;
return - V_43 ;
}
if ( F_8 ( ( V_116 -> V_153 | V_116 -> V_180 )
& ~ V_181 ) ) {
F_25 ( L_5
L_3
L_4 ,
V_116 -> V_179 ,
( int ) V_116 -> V_25 ,
V_116 -> V_180 ,
V_116 -> V_153 ) ;
return - V_43 ;
}
if ( V_116 -> V_153 ) {
* V_117 -> V_30 |= V_168 ;
if ( V_116 -> V_153 == V_182 &&
F_123 ( V_4 -> V_93 ) ) {
V_54 = F_124 ( V_117 , V_117 -> V_51 -> V_72 ,
V_37 ) ;
if ( F_125 ( V_54 ,
L_6 ) )
return V_54 ;
}
}
if ( ! V_67 &&
F_1 ( V_117 -> V_20 . V_23 ) == V_116 -> V_183 )
return 0 ;
if ( F_8 ( V_116 -> V_25 >
V_19 -> V_7 - ( V_4 -> V_48 . V_123 ? 8 : 4 ) ) ) {
F_25 ( L_7
L_8 ,
V_116 -> V_179 ,
( int ) V_116 -> V_25 ,
( int ) V_19 -> V_7 ) ;
return - V_43 ;
}
if ( F_8 ( V_116 -> V_25 & 3 ) ) {
F_25 ( L_9
L_10 ,
V_116 -> V_179 ,
( int ) V_116 -> V_25 ) ;
return - V_43 ;
}
* V_19 -> V_30 &= ~ V_184 ;
return F_118 ( V_19 , V_116 , V_4 , V_117 ) ;
}
static int F_126 ( struct V_3 * V_4 , struct V_18 * V_19 )
{
#define F_127 ( T_4 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_115 V_185 [ F_127 ( 512 ) ] ;
struct V_115 T_5 * V_186 ;
const struct V_16 * V_17 = F_37 ( V_4 , V_19 ) ;
unsigned int V_187 ;
V_186 = F_128 ( V_17 -> V_188 ) ;
V_187 = V_17 -> V_58 ;
if ( F_8 ( V_187 > F_127 ( V_189 ) ) )
return - V_43 ;
if ( F_8 ( ! F_129 ( V_190 , V_186 , V_187 * sizeof( * V_186 ) ) ) )
return - V_191 ;
do {
struct V_115 * V_192 = V_185 ;
unsigned int V_78 =
F_130 (unsigned int, remain, ARRAY_SIZE(stack)) ;
unsigned int V_193 ;
F_131 () ;
V_193 = F_132 ( V_192 , V_186 , V_78 * sizeof( V_192 [ 0 ] ) ) ;
F_133 () ;
if ( F_8 ( V_193 ) ) {
V_187 = - V_191 ;
goto V_178;
}
V_187 -= V_78 ;
do {
T_1 V_25 = F_122 ( V_4 , V_19 , V_192 ) ;
if ( F_51 ( V_25 == 0 ) ) {
} else if ( ( V_194 ) V_25 < 0 ) {
V_187 = ( int ) V_25 ;
goto V_178;
} else {
V_25 = F_1 ( V_25 & ~ V_61 ) ;
F_134 ( V_25 ,
& V_186 [ V_192 - V_185 ] . V_183 ) ;
}
} while ( V_192 ++ , -- V_78 );
V_186 += F_135 ( V_185 ) ;
} while ( V_187 );
V_178:
F_80 ( & V_4 -> V_48 ) ;
return V_187 ;
}
static int
F_136 ( struct V_3 * V_4 , struct V_18 * V_19 )
{
const struct V_16 * V_17 = F_37 ( V_4 , V_19 ) ;
struct V_115 * V_60 =
F_137 ( F_138 ( * V_60 ) , V_17 -> V_188 ) ;
unsigned int V_53 ;
int V_54 ;
for ( V_53 = 0 ; V_53 < V_17 -> V_58 ; V_53 ++ ) {
T_1 V_25 = F_122 ( V_4 , V_19 , & V_60 [ V_53 ] ) ;
if ( ( V_194 ) V_25 < 0 ) {
V_54 = ( int ) V_25 ;
goto V_54;
}
}
V_54 = 0 ;
V_54:
F_80 ( & V_4 -> V_48 ) ;
return V_54 ;
}
static int F_139 ( const struct V_16 * V_17 )
{
const char T_5 * V_147 , * V_195 ;
unsigned long V_7 ;
char T_6 V_196 ;
V_7 = V_17 -> V_58 ;
if ( V_7 == 0 )
return 0 ;
if ( V_7 > F_127 ( V_189 ) )
return - V_43 ;
V_147 = F_128 ( V_17 -> V_188 ) ;
V_7 *= sizeof( struct V_115 ) ;
if ( ! F_129 ( V_190 , V_147 , V_7 ) )
return - V_191 ;
V_195 = V_147 + V_7 ;
for (; V_147 < V_195 ; V_147 += V_140 ) {
int V_54 = F_140 ( V_196 , V_147 ) ;
if ( V_54 )
return V_54 ;
}
return F_140 ( V_196 , V_195 - 1 ) ;
}
static int F_141 ( const struct V_3 * V_4 )
{
const unsigned int V_78 = V_4 -> V_8 ;
unsigned int V_53 ;
int V_54 ;
for ( V_53 = 0 ; V_53 < V_78 ; V_53 ++ ) {
const unsigned int V_197 = V_4 -> V_47 [ V_53 ] . V_58 ;
struct V_115 T_5 * V_186 ;
struct V_115 * V_60 ;
unsigned long V_7 ;
unsigned long V_193 ;
if ( V_197 == 0 )
continue;
V_54 = F_139 ( & V_4 -> V_47 [ V_53 ] ) ;
if ( V_54 )
goto V_54;
V_186 = F_128 ( V_4 -> V_47 [ V_53 ] . V_188 ) ;
V_7 = V_197 * sizeof( * V_60 ) ;
V_60 = F_142 ( V_7 , 1 , V_9 ) ;
if ( ! V_60 ) {
F_143 ( V_60 ) ;
V_54 = - V_14 ;
goto V_54;
}
V_193 = 0 ;
do {
unsigned int V_150 =
F_130 ( T_1 , F_144 ( 31 ) , V_7 - V_193 ) ;
if ( F_145 ( ( char * ) V_60 + V_193 ,
( char T_5 * ) V_186 + V_193 ,
V_150 ) ) {
F_143 ( V_60 ) ;
V_54 = - V_191 ;
goto V_54;
}
V_193 += V_150 ;
} while ( V_193 < V_7 );
F_146 () ;
for ( V_193 = 0 ; V_193 < V_197 ; V_193 ++ )
F_147 ( - 1 ,
& V_186 [ V_193 ] . V_183 ,
V_198 ) ;
V_198:
F_148 () ;
V_4 -> V_47 [ V_53 ] . V_188 = ( V_128 ) V_60 ;
}
return 0 ;
V_54:
while ( V_53 -- ) {
struct V_115 * V_60 =
F_137 ( F_138 ( * V_60 ) , V_4 -> V_47 [ V_53 ] . V_188 ) ;
if ( V_4 -> V_47 [ V_53 ] . V_58 )
F_143 ( V_60 ) ;
}
return V_54 ;
}
static int F_149 ( const struct V_3 * V_4 )
{
const unsigned int V_78 = V_4 -> V_8 ;
unsigned int V_53 ;
if ( F_8 ( V_93 . V_199 ) )
return 0 ;
for ( V_53 = 0 ; V_53 < V_78 ; V_53 ++ ) {
int V_54 ;
V_54 = F_139 ( & V_4 -> V_47 [ V_53 ] ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static T_7 int F_150 ( struct V_3 * V_4 )
{
struct V_200 * V_201 = & V_4 -> V_93 -> V_202 ;
bool V_203 = false ;
struct V_18 * V_19 ;
int V_54 = 0 ;
V_173:
if ( F_151 ( V_204 ) ) {
V_54 = - V_205 ;
goto V_178;
}
F_64 ( V_4 ) ;
F_152 ( & V_201 -> V_206 ) ;
if ( ! V_54 ) {
V_54 = F_149 ( V_4 ) ;
} else if ( ! V_203 ) {
V_54 = F_141 ( V_4 ) ;
V_203 = V_54 == 0 ;
} else {
F_153 () ;
V_54 = 0 ;
}
if ( V_54 ) {
F_154 ( & V_201 -> V_206 ) ;
goto V_178;
}
F_155 ( V_4 -> V_93 -> V_134 . V_207 ) ;
V_54 = F_156 ( V_201 ) ;
if ( V_54 ) {
F_154 ( & V_201 -> V_206 ) ;
goto V_178;
}
V_54 = F_47 ( V_4 ) ;
if ( V_54 )
goto V_54;
F_18 ( ! V_4 -> V_111 ) ;
F_39 (vma, &eb->relocs, reloc_link) {
if ( ! V_203 ) {
F_131 () ;
V_54 = F_126 ( V_4 , V_19 ) ;
F_133 () ;
if ( V_54 )
goto V_173;
} else {
V_54 = F_136 ( V_4 , V_19 ) ;
if ( V_54 )
goto V_54;
}
}
V_54:
if ( V_54 == - V_208 )
goto V_173;
V_178:
if ( V_203 ) {
const unsigned int V_78 = V_4 -> V_8 ;
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 < V_78 ; V_53 ++ ) {
const struct V_16 * V_17 =
& V_4 -> V_47 [ V_53 ] ;
struct V_115 * V_60 ;
if ( ! V_17 -> V_58 )
continue;
V_60 = F_137 ( F_138 ( * V_60 ) , V_17 -> V_188 ) ;
F_143 ( V_60 ) ;
}
}
return V_54 ;
}
static int F_157 ( struct V_3 * V_4 )
{
if ( F_47 ( V_4 ) )
goto V_209;
if ( V_4 -> args -> V_5 & V_62 ) {
struct V_18 * V_19 ;
F_39 (vma, &eb->relocs, reloc_link) {
if ( F_126 ( V_4 , V_19 ) )
goto V_209;
}
}
return 0 ;
V_209:
return F_150 ( V_4 ) ;
}
static void F_158 ( struct V_18 * V_19 ,
struct V_151 * V_210 ,
unsigned int V_5 )
{
struct V_211 * V_166 = V_19 -> V_166 ;
F_113 ( V_166 , NULL ) ;
if ( V_5 & V_168 )
F_114 ( V_166 , & V_210 -> V_167 ) ;
else if ( F_159 ( V_166 ) == 0 )
F_160 ( V_166 , & V_210 -> V_167 ) ;
F_115 ( V_166 ) ;
}
static int F_161 ( struct V_3 * V_4 )
{
const unsigned int V_78 = V_4 -> V_8 ;
unsigned int V_53 ;
int V_54 ;
for ( V_53 = 0 ; V_53 < V_78 ; V_53 ++ ) {
unsigned int V_5 = V_4 -> V_5 [ V_53 ] ;
struct V_18 * V_19 = V_4 -> V_19 [ V_53 ] ;
struct V_66 * V_51 = V_19 -> V_51 ;
if ( V_5 & V_212 ) {
struct V_213 * V_214 ;
V_214 = F_162 ( sizeof( * V_214 ) , V_9 ) ;
if ( F_8 ( ! V_214 ) )
return - V_14 ;
V_214 -> V_215 = V_4 -> V_216 -> V_217 ;
V_214 -> V_19 = V_4 -> V_19 [ V_53 ] ;
V_4 -> V_216 -> V_217 = V_214 ;
}
if ( F_8 ( V_51 -> V_71 & ~ V_51 -> V_218 ) ) {
if ( F_163 ( V_51 , 0 ) )
V_5 &= ~ V_184 ;
}
if ( V_5 & V_184 )
continue;
V_54 = F_109
( V_4 -> V_216 , V_51 , V_5 & V_168 ) ;
if ( V_54 )
return V_54 ;
}
for ( V_53 = 0 ; V_53 < V_78 ; V_53 ++ ) {
unsigned int V_5 = V_4 -> V_5 [ V_53 ] ;
struct V_18 * V_19 = V_4 -> V_19 [ V_53 ] ;
F_112 ( V_19 , V_4 -> V_216 , V_5 ) ;
F_158 ( V_19 , V_4 -> V_216 , V_5 ) ;
F_17 ( V_19 , V_5 ) ;
V_19 -> V_30 = NULL ;
if ( F_8 ( V_5 & V_113 ) )
F_63 ( V_19 ) ;
}
V_4 -> V_47 = NULL ;
F_78 ( V_4 -> V_93 ) ;
return V_4 -> V_155 -> V_162 ( V_4 -> V_216 , V_163 ) ;
}
static bool F_164 ( struct V_219 * V_47 )
{
if ( V_47 -> V_5 & V_220 )
return false ;
if ( ! ( V_47 -> V_5 & V_221 ) ) {
if ( V_47 -> V_222 || V_47 -> V_223 )
return false ;
}
if ( V_47 -> V_224 == 0xffffffff ) {
F_25 ( L_11 ) ;
V_47 -> V_224 = 0 ;
}
if ( V_47 -> V_225 || V_47 -> V_224 )
return false ;
if ( ( V_47 -> V_226 | V_47 -> V_227 ) & 0x7 )
return false ;
return true ;
}
void F_112 ( struct V_18 * V_19 ,
struct V_151 * V_210 ,
unsigned int V_5 )
{
struct V_66 * V_51 = V_19 -> V_51 ;
const unsigned int V_228 = V_210 -> V_155 -> V_229 ;
F_165 ( & V_210 -> V_93 -> V_202 . V_206 ) ;
F_18 ( ! F_32 ( & V_19 -> V_20 ) ) ;
if ( ! F_166 ( V_19 ) )
V_51 -> V_230 ++ ;
F_167 ( V_19 , V_228 ) ;
F_168 ( & V_19 -> V_231 [ V_228 ] , V_210 ) ;
F_169 ( & V_19 -> V_232 , & V_19 -> V_83 -> V_233 ) ;
V_51 -> V_92 . V_153 = 0 ;
if ( V_5 & V_168 ) {
V_51 -> V_92 . V_153 = V_234 ;
if ( F_170 ( V_51 , V_235 ) )
F_168 ( & V_51 -> V_236 , V_210 ) ;
V_51 -> V_92 . V_180 = 0 ;
}
V_51 -> V_92 . V_180 |= V_181 ;
if ( V_5 & V_38 )
F_168 ( & V_19 -> V_237 , V_210 ) ;
}
static int F_171 ( struct V_151 * V_210 )
{
T_3 * V_238 ;
int V_53 ;
if ( ! F_172 ( V_210 -> V_93 ) || V_210 -> V_155 -> V_229 != V_239 ) {
F_25 ( L_12 ) ;
return - V_43 ;
}
V_238 = F_173 ( V_210 , 4 * 2 + 2 ) ;
if ( F_54 ( V_238 ) )
return F_55 ( V_238 ) ;
* V_238 ++ = F_174 ( 4 ) ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
* V_238 ++ = F_175 ( F_176 ( V_53 ) ) ;
* V_238 ++ = 0 ;
}
* V_238 ++ = V_240 ;
F_177 ( V_210 , V_238 ) ;
return 0 ;
}
static struct V_18 * F_178 ( struct V_3 * V_4 , bool V_241 )
{
struct V_66 * V_242 ;
struct V_18 * V_19 ;
int V_54 ;
V_242 = F_104 ( & V_4 -> V_155 -> V_156 ,
F_179 ( V_4 -> V_227 ) ) ;
if ( F_54 ( V_242 ) )
return F_180 ( V_242 ) ;
V_54 = F_181 ( V_4 -> V_155 ,
V_4 -> V_111 -> V_51 ,
V_242 ,
V_4 -> V_226 ,
V_4 -> V_227 ,
V_241 ) ;
if ( V_54 ) {
if ( V_54 == - V_243 )
V_19 = NULL ;
else
V_19 = F_89 ( V_54 ) ;
goto V_178;
}
V_19 = F_95 ( V_242 , NULL , 0 , 0 , 0 ) ;
if ( F_54 ( V_19 ) )
goto V_178;
V_4 -> V_19 [ V_4 -> V_8 ] = F_182 ( V_19 ) ;
V_4 -> V_5 [ V_4 -> V_8 ] =
V_40 | V_113 ;
V_19 -> V_30 = & V_4 -> V_5 [ V_4 -> V_8 ] ;
V_4 -> V_8 ++ ;
V_178:
F_106 ( V_242 ) ;
return V_19 ;
}
static void
F_183 ( struct V_151 * V_210 , struct V_244 * V_87 )
{
V_210 -> V_245 = V_87 -> V_88 ;
F_31 ( & V_210 -> V_246 , & V_210 -> V_245 -> V_134 . V_247 ) ;
}
static int F_184 ( struct V_3 * V_4 )
{
int V_54 ;
V_54 = F_161 ( V_4 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_110 ( V_4 -> V_216 ) ;
if ( V_54 )
return V_54 ;
if ( V_4 -> args -> V_5 & V_248 ) {
V_54 = F_171 ( V_4 -> V_216 ) ;
if ( V_54 )
return V_54 ;
}
V_54 = V_4 -> V_155 -> V_164 ( V_4 -> V_216 ,
V_4 -> V_111 -> V_20 . V_23 +
V_4 -> V_226 ,
V_4 -> V_227 ,
V_4 -> V_249 ) ;
if ( V_54 )
return V_54 ;
return 0 ;
}
static unsigned int
F_185 ( struct V_119 * V_250 ,
struct V_244 * V_87 )
{
struct V_251 * V_245 = V_87 -> V_88 ;
if ( ( int ) V_245 -> V_252 < 0 )
V_245 -> V_252 = F_186 ( 1 ,
& V_250 -> V_134 . V_253 ) ;
return V_245 -> V_252 ;
}
static struct V_254 *
F_187 ( struct V_119 * V_250 ,
struct V_244 * V_87 ,
struct V_219 * args )
{
unsigned int V_255 = args -> V_5 & V_256 ;
struct V_254 * V_155 ;
if ( V_255 > V_257 ) {
F_25 ( L_13 , V_255 ) ;
return NULL ;
}
if ( ( V_255 != V_258 ) &&
( ( args -> V_5 & V_259 ) != 0 ) ) {
F_25 ( L_14
L_15 , ( int ) ( args -> V_5 ) ) ;
return NULL ;
}
if ( V_255 == V_258 && F_188 ( V_250 ) ) {
unsigned int V_260 = args -> V_5 & V_259 ;
if ( V_260 == V_261 ) {
V_260 = F_185 ( V_250 , V_87 ) ;
} else if ( V_260 >= V_262 &&
V_260 <= V_263 ) {
V_260 >>= V_264 ;
V_260 -- ;
} else {
F_25 ( L_16 ,
V_260 ) ;
return NULL ;
}
V_155 = V_250 -> V_155 [ F_189 ( V_260 ) ] ;
} else {
V_155 = V_250 -> V_155 [ V_265 [ V_255 ] ] ;
}
if ( ! V_155 ) {
F_25 ( L_17 , V_255 ) ;
return NULL ;
}
return V_155 ;
}
static void
F_190 ( struct V_266 * * V_267 , unsigned int V_268 )
{
while ( V_268 -- )
F_191 ( F_192 ( V_267 [ V_268 ] , 2 ) ) ;
F_143 ( V_267 ) ;
}
static struct V_266 * *
F_193 ( struct V_219 * args ,
struct V_244 * V_87 )
{
const unsigned int V_269 = args -> V_222 ;
struct V_270 T_5 * V_271 ;
struct V_266 * * V_267 ;
unsigned int V_268 ;
int V_54 ;
if ( ! ( args -> V_5 & V_221 ) )
return NULL ;
if ( V_269 > V_272 / sizeof( * V_267 ) )
return F_89 ( - V_43 ) ;
V_271 = F_128 ( args -> V_223 ) ;
if ( ! F_129 ( V_190 , V_271 , V_269 * 2 * sizeof( T_3 ) ) )
return F_89 ( - V_191 ) ;
V_267 = F_142 ( args -> V_222 , sizeof( * V_267 ) ,
V_11 | V_9 ) ;
if ( ! V_267 )
return F_89 ( - V_14 ) ;
for ( V_268 = 0 ; V_268 < V_269 ; V_268 ++ ) {
struct V_270 V_167 ;
struct V_266 * V_273 ;
if ( F_145 ( & V_167 , V_271 ++ , sizeof( V_167 ) ) ) {
V_54 = - V_191 ;
goto V_54;
}
if ( V_167 . V_5 & V_274 ) {
V_54 = - V_43 ;
goto V_54;
}
V_273 = F_194 ( V_87 , V_167 . V_46 ) ;
if ( ! V_273 ) {
F_25 ( L_18 ) ;
V_54 = - V_90 ;
goto V_54;
}
F_90 ( ~ ( V_275 - 1 ) &
~ V_274 ) ;
V_267 [ V_268 ] = F_195 ( V_273 , V_167 . V_5 , 2 ) ;
}
return V_267 ;
V_54:
F_190 ( V_267 , V_268 ) ;
return F_89 ( V_54 ) ;
}
static void
F_196 ( struct V_219 * args ,
struct V_266 * * V_267 )
{
if ( V_267 )
F_190 ( V_267 , args -> V_222 ) ;
}
static int
F_197 ( struct V_3 * V_4 ,
struct V_266 * * V_267 )
{
const unsigned int V_269 = V_4 -> args -> V_222 ;
unsigned int V_268 ;
int V_54 ;
for ( V_268 = 0 ; V_268 < V_269 ; V_268 ++ ) {
struct V_266 * V_273 ;
struct V_276 * V_167 ;
unsigned int V_5 ;
V_273 = F_198 ( V_267 [ V_268 ] , & V_5 , 2 ) ;
if ( ! ( V_5 & V_277 ) )
continue;
V_167 = F_199 ( V_273 ) ;
if ( ! V_167 )
return - V_43 ;
V_54 = F_200 ( V_4 -> V_216 , V_167 ) ;
F_201 ( V_167 ) ;
if ( V_54 < 0 )
return V_54 ;
}
return 0 ;
}
static void
F_202 ( struct V_3 * V_4 ,
struct V_266 * * V_267 )
{
const unsigned int V_269 = V_4 -> args -> V_222 ;
struct V_276 * const V_167 = & V_4 -> V_216 -> V_167 ;
unsigned int V_268 ;
for ( V_268 = 0 ; V_268 < V_269 ; V_268 ++ ) {
struct V_266 * V_273 ;
unsigned int V_5 ;
V_273 = F_198 ( V_267 [ V_268 ] , & V_5 , 2 ) ;
if ( ! ( V_5 & V_278 ) )
continue;
F_203 ( V_273 , V_167 ) ;
}
}
static int
F_204 ( struct V_200 * V_201 ,
struct V_244 * V_87 ,
struct V_219 * args ,
struct V_16 * V_47 ,
struct V_266 * * V_267 )
{
struct V_3 V_4 ;
struct V_276 * V_279 = NULL ;
struct V_280 * V_281 = NULL ;
int V_282 = - 1 ;
int V_54 ;
F_90 ( V_283 &
~ V_284 ) ;
V_4 . V_93 = F_205 ( V_201 ) ;
V_4 . V_87 = V_87 ;
V_4 . args = args ;
if ( V_67 || ! ( args -> V_5 & V_285 ) )
args -> V_5 |= V_62 ;
V_4 . V_47 = V_47 ;
V_4 . V_19 = (struct V_18 * * ) ( V_47 + args -> V_8 + 1 ) ;
V_4 . V_19 [ 0 ] = NULL ;
V_4 . V_5 = ( unsigned int * ) ( V_4 . V_19 + args -> V_8 + 1 ) ;
V_4 . V_42 = V_284 ;
if ( F_206 ( V_4 . V_93 ) )
V_4 . V_42 |= V_36 ;
F_67 ( & V_4 . V_48 , V_4 . V_93 ) ;
V_4 . V_8 = args -> V_8 ;
V_4 . V_226 = args -> V_226 ;
V_4 . V_227 = args -> V_227 ;
V_4 . V_249 = 0 ;
if ( args -> V_5 & V_286 ) {
if ( ! F_207 ( V_87 ) || ! F_208 ( V_287 ) )
return - V_288 ;
V_4 . V_249 |= V_165 ;
}
if ( args -> V_5 & V_289 )
V_4 . V_249 |= V_290 ;
V_4 . V_155 = F_187 ( V_4 . V_93 , V_87 , args ) ;
if ( ! V_4 . V_155 )
return - V_43 ;
if ( args -> V_5 & V_291 ) {
if ( ! F_209 ( V_4 . V_93 ) ) {
F_25 ( L_19 ) ;
return - V_43 ;
}
if ( V_4 . V_155 -> V_229 != V_239 ) {
F_25 ( L_20 ,
V_4 . V_155 -> V_292 ) ;
return - V_43 ;
}
V_4 . V_249 |= V_293 ;
}
if ( args -> V_5 & V_294 ) {
V_279 = F_210 ( F_120 ( args -> V_295 ) ) ;
if ( ! V_279 )
return - V_43 ;
}
if ( args -> V_5 & V_296 ) {
V_282 = F_211 ( V_297 ) ;
if ( V_282 < 0 ) {
V_54 = V_282 ;
goto V_298;
}
}
V_54 = F_5 ( & V_4 ) ;
if ( V_54 )
goto V_299;
F_18 ( ! V_4 . V_15 ) ;
V_54 = F_45 ( & V_4 ) ;
if ( F_8 ( V_54 ) )
goto V_300;
F_212 ( V_4 . V_93 ) ;
V_54 = F_156 ( V_201 ) ;
if ( V_54 )
goto V_301;
V_54 = F_157 ( & V_4 ) ;
if ( V_54 ) {
args -> V_5 &= ~ V_62 ;
goto V_103;
}
if ( F_8 ( * V_4 . V_111 -> V_30 & V_168 ) ) {
F_25 ( L_21 ) ;
V_54 = - V_43 ;
goto V_103;
}
if ( V_4 . V_226 > V_4 . V_111 -> V_7 ||
V_4 . V_227 > V_4 . V_111 -> V_7 - V_4 . V_226 ) {
F_25 ( L_22 ) ;
V_54 = - V_43 ;
goto V_103;
}
if ( V_4 . V_155 -> V_302 && V_4 . V_227 ) {
struct V_18 * V_19 ;
V_19 = F_178 ( & V_4 , F_207 ( V_87 ) ) ;
if ( F_54 ( V_19 ) ) {
V_54 = F_55 ( V_19 ) ;
goto V_103;
}
if ( V_19 ) {
V_4 . V_249 |= V_165 ;
V_4 . V_226 = 0 ;
V_4 . V_111 = V_19 ;
}
}
if ( V_4 . V_227 == 0 )
V_4 . V_227 = V_4 . V_111 -> V_7 - V_4 . V_226 ;
if ( V_4 . V_249 & V_165 ) {
struct V_18 * V_19 ;
V_19 = F_95 ( V_4 . V_111 -> V_51 , NULL , 0 , 0 , 0 ) ;
if ( F_54 ( V_19 ) ) {
V_54 = F_55 ( V_19 ) ;
goto V_103;
}
V_4 . V_111 = V_19 ;
}
F_18 ( V_4 . V_48 . V_114 ) ;
V_4 . V_216 = F_108 ( V_4 . V_155 , V_4 . V_86 ) ;
if ( F_54 ( V_4 . V_216 ) ) {
V_54 = F_55 ( V_4 . V_216 ) ;
goto V_303;
}
if ( V_279 ) {
V_54 = F_200 ( V_4 . V_216 , V_279 ) ;
if ( V_54 < 0 )
goto V_161;
}
if ( V_267 ) {
V_54 = F_197 ( & V_4 , V_267 ) ;
if ( V_54 )
goto V_161;
}
if ( V_282 != - 1 ) {
V_281 = F_213 ( & V_4 . V_216 -> V_167 ) ;
if ( ! V_281 ) {
V_54 = - V_14 ;
goto V_161;
}
}
V_4 . V_216 -> V_111 = V_4 . V_111 ;
F_214 ( V_4 . V_216 , V_4 . V_249 ) ;
V_54 = F_184 ( & V_4 ) ;
V_161:
F_79 ( V_4 . V_216 , V_54 == 0 ) ;
F_183 ( V_4 . V_216 , V_87 ) ;
if ( V_267 )
F_202 ( & V_4 , V_267 ) ;
if ( V_281 ) {
if ( V_54 == 0 ) {
F_215 ( V_282 , V_281 -> V_87 ) ;
args -> V_295 &= F_4 ( 0 , 31 ) ;
args -> V_295 |= ( T_1 ) V_282 << 32 ;
V_282 = - 1 ;
} else {
F_216 ( V_281 -> V_87 ) ;
}
}
V_303:
if ( V_4 . V_249 & V_165 )
F_15 ( V_4 . V_111 ) ;
V_103:
if ( V_4 . V_47 )
F_62 ( & V_4 ) ;
F_152 ( & V_201 -> V_206 ) ;
V_301:
F_217 ( V_4 . V_93 ) ;
F_218 ( V_4 . V_86 ) ;
V_300:
F_65 ( & V_4 ) ;
V_299:
if ( V_282 != - 1 )
F_219 ( V_282 ) ;
V_298:
F_201 ( V_279 ) ;
return V_54 ;
}
int
F_220 ( struct V_200 * V_201 , void * V_304 ,
struct V_244 * V_87 )
{
const T_8 V_305 = ( sizeof( struct V_16 ) +
sizeof( struct V_18 * ) +
sizeof( unsigned int ) ) ;
struct V_306 * args = V_304 ;
struct V_219 V_307 ;
struct V_308 * V_309 = NULL ;
struct V_16 * V_310 = NULL ;
unsigned int V_53 ;
int V_54 ;
if ( args -> V_8 < 1 || args -> V_8 > V_272 / V_305 - 1 ) {
F_25 ( L_23 , args -> V_8 ) ;
return - V_43 ;
}
V_307 . V_311 = args -> V_311 ;
V_307 . V_8 = args -> V_8 ;
V_307 . V_226 = args -> V_226 ;
V_307 . V_227 = args -> V_227 ;
V_307 . V_225 = args -> V_225 ;
V_307 . V_224 = args -> V_224 ;
V_307 . V_222 = args -> V_222 ;
V_307 . V_223 = args -> V_223 ;
V_307 . V_5 = V_312 ;
F_221 ( V_307 , 0 ) ;
if ( ! F_164 ( & V_307 ) )
return - V_43 ;
V_309 = F_142 ( args -> V_8 , sizeof( * V_309 ) ,
V_11 | V_9 ) ;
V_310 = F_142 ( args -> V_8 + 1 , V_305 ,
V_11 | V_9 ) ;
if ( V_309 == NULL || V_310 == NULL ) {
F_25 ( L_24 ,
args -> V_8 ) ;
F_143 ( V_309 ) ;
F_143 ( V_310 ) ;
return - V_14 ;
}
V_54 = F_222 ( V_309 ,
F_128 ( args -> V_311 ) ,
sizeof( * V_309 ) * args -> V_8 ) ;
if ( V_54 ) {
F_25 ( L_25 ,
args -> V_8 , V_54 ) ;
F_143 ( V_309 ) ;
F_143 ( V_310 ) ;
return - V_191 ;
}
for ( V_53 = 0 ; V_53 < args -> V_8 ; V_53 ++ ) {
V_310 [ V_53 ] . V_46 = V_309 [ V_53 ] . V_46 ;
V_310 [ V_53 ] . V_58 = V_309 [ V_53 ] . V_58 ;
V_310 [ V_53 ] . V_188 = V_309 [ V_53 ] . V_188 ;
V_310 [ V_53 ] . V_22 = V_309 [ V_53 ] . V_22 ;
V_310 [ V_53 ] . V_25 = V_309 [ V_53 ] . V_25 ;
if ( F_68 ( F_205 ( V_201 ) ) < 4 )
V_310 [ V_53 ] . V_5 = V_38 ;
else
V_310 [ V_53 ] . V_5 = 0 ;
}
V_54 = F_204 ( V_201 , V_87 , & V_307 , V_310 , NULL ) ;
if ( V_307 . V_5 & V_62 ) {
struct V_308 T_5 * V_313 =
F_128 ( args -> V_311 ) ;
for ( V_53 = 0 ; V_53 < args -> V_8 ; V_53 ++ ) {
if ( ! ( V_310 [ V_53 ] . V_25 & V_61 ) )
continue;
V_310 [ V_53 ] . V_25 =
F_1 ( V_310 [ V_53 ] . V_25 & V_32 ) ;
V_310 [ V_53 ] . V_25 &= V_32 ;
if ( F_223 ( & V_313 [ V_53 ] . V_25 ,
& V_310 [ V_53 ] . V_25 ,
sizeof( V_313 [ V_53 ] . V_25 ) ) )
break;
}
}
F_143 ( V_309 ) ;
F_143 ( V_310 ) ;
return V_54 ;
}
int
F_224 ( struct V_200 * V_201 , void * V_304 ,
struct V_244 * V_87 )
{
const T_8 V_305 = ( sizeof( struct V_16 ) +
sizeof( struct V_18 * ) +
sizeof( unsigned int ) ) ;
struct V_219 * args = V_304 ;
struct V_16 * V_310 ;
struct V_266 * * V_267 = NULL ;
int V_54 ;
if ( args -> V_8 < 1 || args -> V_8 > V_272 / V_305 - 1 ) {
F_25 ( L_23 , args -> V_8 ) ;
return - V_43 ;
}
if ( ! F_164 ( args ) )
return - V_43 ;
V_310 = F_142 ( args -> V_8 + 1 , V_305 ,
V_11 | V_9 ) ;
if ( V_310 == NULL ) {
F_25 ( L_24 ,
args -> V_8 ) ;
return - V_14 ;
}
if ( F_222 ( V_310 ,
F_128 ( args -> V_311 ) ,
sizeof( * V_310 ) * args -> V_8 ) ) {
F_25 ( L_26 , args -> V_8 ) ;
F_143 ( V_310 ) ;
return - V_191 ;
}
if ( args -> V_5 & V_221 ) {
V_267 = F_193 ( args , V_87 ) ;
if ( F_54 ( V_267 ) ) {
F_143 ( V_310 ) ;
return F_55 ( V_267 ) ;
}
}
V_54 = F_204 ( V_201 , V_87 , args , V_310 , V_267 ) ;
if ( args -> V_5 & V_62 ) {
struct V_16 T_5 * V_313 =
F_128 ( args -> V_311 ) ;
unsigned int V_53 ;
F_146 () ;
for ( V_53 = 0 ; V_53 < args -> V_8 ; V_53 ++ ) {
if ( ! ( V_310 [ V_53 ] . V_25 & V_61 ) )
continue;
V_310 [ V_53 ] . V_25 =
F_1 ( V_310 [ V_53 ] . V_25 & V_32 ) ;
F_147 ( V_310 [ V_53 ] . V_25 ,
& V_313 [ V_53 ] . V_25 ,
V_198 ) ;
}
V_198:
F_148 () ;
}
args -> V_5 &= ~ V_314 ;
F_196 ( args , V_267 ) ;
F_143 ( V_310 ) ;
return V_54 ;
}
