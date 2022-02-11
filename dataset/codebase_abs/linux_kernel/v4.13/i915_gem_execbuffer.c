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
unsigned int V_5 ;
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
const struct V_18 * V_19 )
{
if ( ! ( V_17 -> V_5 & V_20 ) )
return true ;
if ( V_19 -> V_21 . V_7 < V_17 -> V_22 )
return true ;
if ( V_17 -> V_23 && ! F_10 ( V_19 -> V_21 . V_24 , V_17 -> V_23 ) )
return true ;
if ( V_17 -> V_5 & V_25 &&
V_19 -> V_21 . V_24 != V_17 -> V_26 )
return true ;
if ( V_17 -> V_5 & V_27 &&
V_19 -> V_21 . V_24 < V_28 )
return true ;
if ( ! ( V_17 -> V_5 & V_29 ) &&
( V_19 -> V_21 . V_24 + V_19 -> V_21 . V_7 - 1 ) >> 32 )
return true ;
return false ;
}
static inline void
F_11 ( struct V_3 * V_4 ,
struct V_16 * V_17 ,
struct V_18 * V_19 )
{
T_1 V_5 ;
if ( V_19 -> V_21 . V_7 )
V_5 = V_19 -> V_21 . V_24 ;
else
V_5 = V_17 -> V_26 & V_30 ;
V_5 |= V_31 | V_32 | V_33 ;
if ( F_8 ( V_17 -> V_5 & V_34 ) )
V_5 |= V_35 ;
if ( F_8 ( F_12 ( V_19 , 0 , 0 , V_5 ) ) )
return;
if ( F_8 ( V_17 -> V_5 & V_36 ) ) {
if ( F_8 ( F_13 ( V_19 ) ) ) {
F_14 ( V_19 ) ;
return;
}
if ( F_15 ( V_19 ) )
V_17 -> V_5 |= V_37 ;
}
V_17 -> V_5 |= V_20 ;
}
static inline void
F_16 ( struct V_18 * V_19 ,
const struct V_16 * V_17 )
{
F_17 ( ! ( V_17 -> V_5 & V_20 ) ) ;
if ( F_8 ( V_17 -> V_5 & V_37 ) )
F_18 ( V_19 ) ;
F_19 ( V_19 ) ;
}
static inline void
F_20 ( struct V_18 * V_19 ,
struct V_16 * V_17 )
{
if ( ! ( V_17 -> V_5 & V_20 ) )
return;
F_16 ( V_19 , V_17 ) ;
V_17 -> V_5 &= ~ V_38 ;
}
static int
F_21 ( struct V_3 * V_4 ,
struct V_16 * V_17 ,
struct V_18 * V_19 )
{
if ( F_8 ( V_17 -> V_5 & V_4 -> V_39 ) )
return - V_40 ;
if ( F_8 ( V_17 -> V_23 && ! F_22 ( V_17 -> V_23 ) ) )
return - V_40 ;
if ( F_8 ( V_17 -> V_5 & V_25 &&
V_17 -> V_26 != F_1 ( V_17 -> V_26 & V_41 ) ) )
return - V_40 ;
if ( V_17 -> V_5 & V_42 ) {
if ( F_8 ( F_23 ( V_17 -> V_22 ) ) )
return - V_40 ;
} else {
V_17 -> V_22 = 0 ;
}
if ( F_8 ( V_19 -> V_43 ) ) {
F_24 ( L_1 ,
V_17 -> V_44 , ( int ) ( V_17 - V_4 -> V_45 ) ) ;
return - V_40 ;
}
V_17 -> V_26 = F_3 ( V_17 -> V_26 ) ;
return 0 ;
}
static int
F_25 ( struct V_3 * V_4 ,
struct V_16 * V_17 ,
struct V_18 * V_19 )
{
int V_46 ;
F_17 ( F_26 ( V_19 ) ) ;
if ( ! ( V_4 -> args -> V_5 & V_47 ) ) {
V_46 = F_21 ( V_4 , V_17 , V_19 ) ;
if ( F_8 ( V_46 ) )
return V_46 ;
}
if ( V_4 -> V_15 > 0 ) {
V_19 -> V_48 = V_17 -> V_44 ;
F_27 ( & V_19 -> V_49 ,
& V_4 -> V_12 [ F_28 ( V_17 -> V_44 ,
V_4 -> V_15 ) ] ) ;
}
if ( V_17 -> V_50 )
F_29 ( & V_19 -> V_51 , & V_4 -> V_52 ) ;
if ( ! V_4 -> V_53 . V_54 ) {
V_17 -> V_5 &= ~ V_36 ;
} else {
if ( ( V_17 -> V_5 & V_36 ||
V_4 -> V_53 . V_55 ) &&
F_30 ( V_19 -> V_56 ) )
V_17 -> V_5 |= V_34 | V_57 ;
}
if ( ! ( V_17 -> V_5 & V_25 ) )
V_17 -> V_5 |= V_4 -> V_58 ;
V_19 -> V_43 = V_17 ;
F_31 ( V_17 ) = ( V_59 ) V_19 ;
V_46 = 0 ;
F_11 ( V_4 , V_17 , V_19 ) ;
if ( F_9 ( V_17 , V_19 ) ) {
F_20 ( V_19 , V_17 ) ;
F_29 ( & V_19 -> V_60 , & V_4 -> V_61 ) ;
if ( F_32 ( & V_19 -> V_21 ) )
V_46 = F_33 ( V_19 ) ;
} else {
if ( V_17 -> V_26 != V_19 -> V_21 . V_24 ) {
V_17 -> V_26 = V_19 -> V_21 . V_24 | V_62 ;
V_4 -> args -> V_5 |= V_63 ;
}
}
return V_46 ;
}
static inline int F_34 ( const struct V_53 * V_64 ,
const struct V_65 * V_56 )
{
if ( ! F_35 ( V_56 ) )
return false ;
if ( V_66 == V_67 )
return true ;
if ( V_66 == V_68 )
return false ;
return ( V_64 -> V_69 ||
V_56 -> V_70 ||
V_56 -> V_71 != V_72 ) ;
}
static int F_36 ( const struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_43 ;
T_1 V_5 ;
int V_46 ;
V_5 = V_31 | V_73 ;
if ( V_17 -> V_5 & V_34 )
V_5 |= V_35 ;
if ( ! ( V_17 -> V_5 & V_29 ) )
V_5 |= V_74 ;
if ( V_17 -> V_5 & V_57 )
V_5 |= V_75 ;
if ( V_17 -> V_5 & V_25 ) {
V_5 |= V_17 -> V_26 | V_33 ;
V_5 &= ~ V_73 ;
} else if ( V_17 -> V_5 & V_27 ) {
V_5 |= V_28 | V_76 ;
}
V_46 = F_12 ( V_19 , V_17 -> V_22 , V_17 -> V_23 , V_5 ) ;
if ( V_46 )
return V_46 ;
if ( V_17 -> V_26 != V_19 -> V_21 . V_24 ) {
V_17 -> V_26 = V_19 -> V_21 . V_24 | V_62 ;
V_4 -> args -> V_5 |= V_63 ;
}
if ( F_8 ( V_17 -> V_5 & V_36 ) ) {
V_46 = F_13 ( V_19 ) ;
if ( F_8 ( V_46 ) ) {
F_14 ( V_19 ) ;
return V_46 ;
}
if ( F_15 ( V_19 ) )
V_17 -> V_5 |= V_37 ;
}
V_17 -> V_5 |= V_20 ;
F_17 ( F_9 ( V_17 , V_19 ) ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 )
{
const unsigned int V_77 = V_4 -> V_8 ;
struct V_78 V_79 ;
struct V_18 * V_19 ;
unsigned int V_80 , V_81 ;
int V_46 ;
V_81 = 0 ;
V_46 = 0 ;
do {
F_38 (vma, &eb->unbound, exec_link) {
V_46 = F_36 ( V_4 , V_19 ) ;
if ( V_46 )
break;
}
if ( V_46 != - V_82 )
return V_46 ;
F_39 ( & V_4 -> V_61 ) ;
F_39 ( & V_79 ) ;
for ( V_80 = 0 ; V_80 < V_77 ; V_80 ++ ) {
struct V_16 * V_17 = & V_4 -> V_45 [ V_80 ] ;
if ( V_17 -> V_5 & V_25 &&
V_17 -> V_5 & V_20 )
continue;
V_19 = F_40 ( V_17 ) ;
F_20 ( V_19 , V_17 ) ;
if ( V_17 -> V_5 & V_25 )
F_41 ( & V_19 -> V_60 , & V_4 -> V_61 ) ;
else if ( V_17 -> V_5 & V_57 )
F_29 ( & V_19 -> V_60 , & V_4 -> V_61 ) ;
else
F_29 ( & V_19 -> V_60 , & V_79 ) ;
}
F_42 ( & V_79 , & V_4 -> V_61 ) ;
switch ( V_81 ++ ) {
case 0 :
break;
case 1 :
V_46 = F_43 ( V_4 -> V_83 ) ;
if ( V_46 )
return V_46 ;
break;
default:
return - V_82 ;
}
} while ( 1 );
}
static inline struct V_13 *
F_44 ( const struct V_84 * V_85 , T_2 V_44 )
{
return & V_85 -> V_86 [ F_28 ( V_44 , V_85 -> V_87 ) ] ;
}
static inline bool
F_45 ( const struct V_84 * V_85 )
{
return ( 4 * V_85 -> V_88 > 3 * V_85 -> V_89 ||
4 * V_85 -> V_88 + 1 < V_85 -> V_89 ) ;
}
static unsigned int F_46 ( const struct V_3 * V_4 )
{
if ( V_4 -> args -> V_5 & V_90 )
return 0 ;
else
return V_4 -> V_8 - 1 ;
}
static int F_47 ( struct V_3 * V_4 )
{
struct V_91 * V_92 ;
V_92 = F_48 ( V_4 -> V_93 -> V_94 , V_4 -> args -> V_95 ) ;
if ( F_8 ( F_49 ( V_92 ) ) )
return F_50 ( V_92 ) ;
if ( F_8 ( F_51 ( V_92 ) ) ) {
F_24 ( L_2 ,
V_92 -> V_96 ) ;
return - V_97 ;
}
V_4 -> V_92 = F_52 ( V_92 ) ;
V_4 -> V_83 = V_92 -> V_98 ? & V_92 -> V_98 -> V_99 : & V_4 -> V_100 -> V_101 . V_99 ;
V_4 -> V_58 = 0 ;
if ( V_92 -> V_5 & V_102 )
V_4 -> V_58 |= V_27 ;
return 0 ;
}
static int F_53 ( struct V_3 * V_4 )
{
#define F_54 BIT(0)
const unsigned int V_77 = V_4 -> V_8 ;
struct V_84 * V_85 = & V_4 -> V_92 -> V_103 ;
struct V_18 * V_19 ;
struct V_104 * V_104 ;
unsigned int V_80 ;
int V_105 = - 1 ;
int V_46 ;
F_39 ( & V_4 -> V_52 ) ;
F_39 ( & V_4 -> V_61 ) ;
if ( F_8 ( V_85 -> V_89 & V_106 ) )
F_55 ( & V_85 -> V_107 ) ;
F_17 ( V_85 -> V_89 & V_106 ) ;
for ( V_80 = 0 ; V_80 < V_77 ; V_80 ++ ) {
F_31 ( & V_4 -> V_45 [ V_80 ] ) = 0 ;
F_56 (vma,
ht_head(lut, eb->exec[i].handle),
ctx_node) {
if ( V_19 -> V_108 != V_4 -> V_45 [ V_80 ] . V_44 )
continue;
V_46 = F_25 ( V_4 , & V_4 -> V_45 [ V_80 ] , V_19 ) ;
if ( F_8 ( V_46 ) )
return V_46 ;
goto V_109;
}
if ( V_105 < 0 )
V_105 = V_80 ;
V_109: ;
}
if ( V_105 < 0 )
goto V_110;
F_57 ( & V_4 -> V_93 -> V_111 ) ;
V_104 = & V_4 -> V_93 -> V_112 ;
for ( V_80 = V_105 ; V_80 < V_77 ; V_80 ++ ) {
struct V_65 * V_56 ;
if ( F_31 ( & V_4 -> V_45 [ V_80 ] ) )
continue;
V_56 = F_58 ( F_59 ( V_104 , V_4 -> V_45 [ V_80 ] . V_44 ) ) ;
if ( F_8 ( ! V_56 ) ) {
F_60 ( & V_4 -> V_93 -> V_111 ) ;
F_24 ( L_3 ,
V_4 -> V_45 [ V_80 ] . V_44 , V_80 ) ;
V_46 = - V_113 ;
goto V_46;
}
F_31 ( & V_4 -> V_45 [ V_80 ] ) = F_54 | ( V_59 ) V_56 ;
}
F_60 ( & V_4 -> V_93 -> V_111 ) ;
for ( V_80 = V_105 ; V_80 < V_77 ; V_80 ++ ) {
struct V_65 * V_56 ;
if ( ! ( F_31 ( & V_4 -> V_45 [ V_80 ] ) & F_54 ) )
continue;
V_56 = F_61 ( F_62 ( * V_56 ) ,
F_31 ( & V_4 -> V_45 [ V_80 ] ) & ~ F_54 ) ;
V_19 = F_63 ( V_56 , V_4 -> V_83 , NULL ) ;
if ( F_8 ( F_49 ( V_19 ) ) ) {
F_24 ( L_4 ) ;
V_46 = F_50 ( V_19 ) ;
goto V_46;
}
if ( ! V_19 -> V_92 ) {
V_19 -> V_92 = V_4 -> V_92 ;
V_19 -> V_108 = V_4 -> V_45 [ V_80 ] . V_44 ;
F_27 ( & V_19 -> V_114 ,
F_44 ( V_85 , V_4 -> V_45 [ V_80 ] . V_44 ) ) ;
V_85 -> V_88 ++ ;
V_85 -> V_89 |= V_106 ;
if ( F_64 ( V_19 ) ) {
F_17 ( V_56 -> V_115 ) ;
V_56 -> V_115 = V_19 ;
}
F_65 ( V_19 ) ;
}
V_46 = F_25 ( V_4 , & V_4 -> V_45 [ V_80 ] , V_19 ) ;
if ( F_8 ( V_46 ) )
goto V_46;
if ( V_19 -> V_92 != V_4 -> V_92 ) {
F_65 ( V_19 ) ;
V_4 -> V_45 [ V_80 ] . V_5 |= V_116 ;
}
}
if ( V_85 -> V_89 & V_106 ) {
if ( F_45 ( V_85 ) )
F_66 ( V_117 , & V_85 -> V_107 ) ;
else
V_85 -> V_89 &= ~ V_106 ;
}
V_110:
V_80 = F_46 ( V_4 ) ;
V_4 -> V_118 = F_40 ( & V_4 -> V_45 [ V_80 ] ) ;
if ( ! ( V_4 -> V_45 [ V_80 ] . V_5 & V_25 ) )
V_4 -> V_45 [ V_80 ] . V_5 |= V_27 ;
if ( V_4 -> V_53 . V_54 )
V_4 -> V_45 [ V_80 ] . V_5 |= V_36 ;
V_4 -> args -> V_5 |= V_47 ;
return F_37 ( V_4 ) ;
V_46:
for ( V_80 = V_105 ; V_80 < V_77 ; V_80 ++ ) {
if ( F_31 ( & V_4 -> V_45 [ V_80 ] ) & F_54 )
F_31 ( & V_4 -> V_45 [ V_80 ] ) = 0 ;
}
V_85 -> V_89 &= ~ V_106 ;
return V_46 ;
#undef F_54
}
static struct V_18 *
F_67 ( const struct V_3 * V_4 , unsigned long V_44 )
{
if ( V_4 -> V_15 < 0 ) {
if ( V_44 >= - V_4 -> V_15 )
return NULL ;
return F_40 ( & V_4 -> V_45 [ V_44 ] ) ;
} else {
struct V_13 * V_119 ;
struct V_18 * V_19 ;
V_119 = & V_4 -> V_12 [ F_28 ( V_44 , V_4 -> V_15 ) ] ;
F_56 (vma, head, exec_node) {
if ( V_19 -> V_48 == V_44 )
return V_19 ;
}
return NULL ;
}
}
static void F_68 ( const struct V_3 * V_4 )
{
const unsigned int V_77 = V_4 -> V_8 ;
unsigned int V_80 ;
for ( V_80 = 0 ; V_80 < V_77 ; V_80 ++ ) {
struct V_16 * V_17 = & V_4 -> V_45 [ V_80 ] ;
struct V_18 * V_19 = F_40 ( V_17 ) ;
if ( ! V_19 )
continue;
F_17 ( V_19 -> V_43 != V_17 ) ;
V_19 -> V_43 = NULL ;
F_31 ( V_17 ) = 0 ;
if ( V_17 -> V_5 & V_20 )
F_16 ( V_19 , V_17 ) ;
if ( V_17 -> V_5 & V_116 )
F_69 ( V_19 ) ;
V_17 -> V_5 &=
~ ( V_38 | V_116 ) ;
}
}
static void F_70 ( const struct V_3 * V_4 )
{
F_68 ( V_4 ) ;
if ( V_4 -> V_15 > 0 )
memset ( V_4 -> V_12 , 0 ,
sizeof( struct V_13 ) << V_4 -> V_15 ) ;
}
static void F_71 ( const struct V_3 * V_4 )
{
F_17 ( V_4 -> V_53 . V_120 ) ;
if ( V_4 -> V_15 > 0 )
F_72 ( V_4 -> V_12 ) ;
}
static inline T_1
F_73 ( const struct V_121 * V_122 ,
const struct V_18 * V_123 )
{
return F_1 ( ( int ) V_122 -> V_124 + V_123 -> V_21 . V_24 ) ;
}
static void F_74 ( struct V_53 * V_64 ,
struct V_125 * V_100 )
{
V_64 -> V_126 = - 1 ;
V_64 -> V_127 = 0 ;
V_64 -> V_128 = F_75 ( V_100 ) ;
V_64 -> V_69 = F_76 ( V_100 ) ;
V_64 -> V_129 = F_77 ( V_100 ) ;
V_64 -> V_54 = V_64 -> V_128 < 4 ;
V_64 -> V_55 = F_78 ( V_100 ) -> V_130 ;
V_64 -> V_21 . V_131 = false ;
V_64 -> V_120 = NULL ;
V_64 -> V_132 = 0 ;
}
static inline void * F_79 ( unsigned long V_133 )
{
return ( void * ) ( V_59 ) ( V_133 & V_41 ) ;
}
static inline unsigned int F_80 ( unsigned long V_133 )
{
return V_133 & ~ V_41 ;
}
static inline struct V_134 * F_81 ( struct V_53 * V_64 )
{
struct V_125 * V_100 =
F_82 ( V_64 , struct V_3 , V_53 ) -> V_100 ;
return & V_100 -> V_101 ;
}
static void F_83 ( struct V_53 * V_64 )
{
F_17 ( V_64 -> V_132 >= V_64 -> V_120 -> V_118 -> V_56 -> V_99 . V_7 / sizeof( T_2 ) ) ;
V_64 -> V_135 [ V_64 -> V_132 ] = V_136 ;
F_84 ( V_64 -> V_120 -> V_118 -> V_56 ) ;
F_85 ( V_64 -> V_120 -> V_100 ) ;
F_86 ( V_64 -> V_120 , true ) ;
V_64 -> V_120 = NULL ;
}
static void F_87 ( struct V_53 * V_64 )
{
void * V_127 ;
if ( V_64 -> V_120 )
F_83 ( V_64 ) ;
if ( ! V_64 -> V_127 )
return;
V_127 = F_79 ( V_64 -> V_127 ) ;
if ( V_64 -> V_127 & V_137 ) {
if ( V_64 -> V_127 & V_138 )
F_88 () ;
F_89 ( V_127 ) ;
F_90 ( (struct V_65 * ) V_64 -> V_21 . V_139 ) ;
} else {
F_91 () ;
F_92 ( ( void V_140 * ) V_127 ) ;
if ( V_64 -> V_21 . V_131 ) {
struct V_134 * V_101 = F_81 ( V_64 ) ;
V_101 -> V_99 . V_141 ( & V_101 -> V_99 ,
V_64 -> V_21 . V_24 ,
V_64 -> V_21 . V_7 ) ;
F_93 ( & V_64 -> V_21 ) ;
} else {
F_14 ( (struct V_18 * ) V_64 -> V_21 . V_139 ) ;
}
}
V_64 -> V_127 = 0 ;
V_64 -> V_126 = - 1 ;
}
static void * F_94 ( struct V_65 * V_56 ,
struct V_53 * V_64 ,
unsigned long V_126 )
{
void * V_127 ;
if ( V_64 -> V_127 ) {
F_89 ( F_79 ( V_64 -> V_127 ) ) ;
} else {
unsigned int V_142 ;
int V_46 ;
V_46 = F_95 ( V_56 , & V_142 ) ;
if ( V_46 )
return F_96 ( V_46 ) ;
F_97 ( V_137 & V_143 ) ;
F_97 ( ( V_137 | V_143 ) & V_41 ) ;
V_64 -> V_127 = V_142 | V_137 ;
V_64 -> V_21 . V_139 = ( void * ) V_56 ;
if ( V_142 )
F_88 () ;
}
V_127 = F_98 ( F_99 ( V_56 , V_126 ) ) ;
V_64 -> V_127 = F_80 ( V_64 -> V_127 ) | ( unsigned long ) V_127 ;
V_64 -> V_126 = V_126 ;
return V_127 ;
}
static void * F_100 ( struct V_65 * V_56 ,
struct V_53 * V_64 ,
unsigned long V_126 )
{
struct V_134 * V_101 = F_81 ( V_64 ) ;
unsigned long V_26 ;
void * V_127 ;
if ( V_64 -> V_127 ) {
F_92 ( ( void V_144 V_140 * ) F_79 ( V_64 -> V_127 ) ) ;
} else {
struct V_18 * V_19 ;
int V_46 ;
if ( F_34 ( V_64 , V_56 ) )
return NULL ;
V_46 = F_101 ( V_56 , true ) ;
if ( V_46 )
return F_96 ( V_46 ) ;
V_19 = F_102 ( V_56 , NULL , 0 , 0 ,
V_75 | V_73 ) ;
if ( F_49 ( V_19 ) ) {
memset ( & V_64 -> V_21 , 0 , sizeof( V_64 -> V_21 ) ) ;
V_46 = F_103
( & V_101 -> V_99 . V_139 , & V_64 -> V_21 ,
V_145 , 0 , V_146 ,
0 , V_101 -> V_147 ,
V_148 ) ;
if ( V_46 )
return NULL ;
} else {
V_46 = F_104 ( V_19 ) ;
if ( V_46 ) {
F_14 ( V_19 ) ;
return F_96 ( V_46 ) ;
}
V_64 -> V_21 . V_24 = V_19 -> V_21 . V_24 ;
V_64 -> V_21 . V_139 = ( void * ) V_19 ;
}
}
V_26 = V_64 -> V_21 . V_24 ;
if ( V_64 -> V_21 . V_131 ) {
F_91 () ;
V_101 -> V_99 . V_149 ( & V_101 -> V_99 ,
F_105 ( V_56 , V_126 ) ,
V_26 , V_72 , 0 ) ;
} else {
V_26 += V_126 << V_150 ;
}
V_127 = ( void V_144 * ) F_106 ( & V_101 -> V_151 ,
V_26 ) ;
V_64 -> V_126 = V_126 ;
V_64 -> V_127 = ( unsigned long ) V_127 ;
return V_127 ;
}
static void * F_107 ( struct V_65 * V_56 ,
struct V_53 * V_64 ,
unsigned long V_126 )
{
void * V_127 ;
if ( V_64 -> V_126 == V_126 ) {
V_127 = F_79 ( V_64 -> V_127 ) ;
} else {
V_127 = NULL ;
if ( ( V_64 -> V_127 & V_137 ) == 0 )
V_127 = F_100 ( V_56 , V_64 , V_126 ) ;
if ( ! V_127 )
V_127 = F_94 ( V_56 , V_64 , V_126 ) ;
}
return V_127 ;
}
static void F_108 ( T_2 * V_152 , T_2 V_153 , unsigned int V_142 )
{
if ( F_8 ( V_142 & ( V_154 | V_138 ) ) ) {
if ( V_142 & V_154 ) {
F_109 ( V_152 ) ;
F_88 () ;
}
* V_152 = V_153 ;
if ( V_142 & V_138 )
F_109 ( V_152 ) ;
} else
* V_152 = V_153 ;
}
static int F_110 ( struct V_3 * V_4 ,
struct V_18 * V_19 ,
unsigned int V_155 )
{
struct V_53 * V_64 = & V_4 -> V_53 ;
struct V_65 * V_56 ;
struct V_156 * V_120 ;
struct V_18 * V_118 ;
T_2 * V_157 ;
int V_46 ;
F_17 ( V_19 -> V_56 -> V_99 . V_158 & V_159 ) ;
V_56 = F_111 ( & V_4 -> V_160 -> V_161 , V_145 ) ;
if ( F_49 ( V_56 ) )
return F_50 ( V_56 ) ;
V_157 = F_112 ( V_56 ,
V_64 -> V_69 ? V_162 : V_163 ) ;
F_113 ( V_56 ) ;
if ( F_49 ( V_157 ) )
return F_50 ( V_157 ) ;
V_46 = F_114 ( V_56 , false ) ;
if ( V_46 )
goto V_164;
V_118 = F_63 ( V_56 , V_19 -> V_83 , NULL ) ;
if ( F_49 ( V_118 ) ) {
V_46 = F_50 ( V_118 ) ;
goto V_164;
}
V_46 = F_12 ( V_118 , 0 , 0 , V_31 | V_73 ) ;
if ( V_46 )
goto V_164;
V_120 = F_115 ( V_4 -> V_160 , V_4 -> V_92 ) ;
if ( F_49 ( V_120 ) ) {
V_46 = F_50 ( V_120 ) ;
goto V_165;
}
V_46 = F_116 ( V_120 , V_19 -> V_56 , true ) ;
if ( V_46 )
goto V_166;
V_46 = V_4 -> V_160 -> V_167 ( V_120 , V_168 ) ;
if ( V_46 )
goto V_166;
V_46 = F_117 ( V_120 ) ;
if ( V_46 )
goto V_166;
V_46 = V_4 -> V_160 -> V_169 ( V_120 ,
V_118 -> V_21 . V_24 , V_145 ,
V_64 -> V_128 > 5 ? 0 : V_170 ) ;
if ( V_46 )
goto V_166;
F_17 ( ! F_118 ( V_118 -> V_171 , true ) ) ;
F_119 ( V_118 , V_120 , 0 ) ;
F_120 ( V_118 -> V_171 , NULL ) ;
F_121 ( V_118 -> V_171 , & V_120 -> V_172 ) ;
F_122 ( V_118 -> V_171 ) ;
F_14 ( V_118 ) ;
F_119 ( V_19 , V_120 , V_173 ) ;
F_120 ( V_19 -> V_171 , NULL ) ;
F_121 ( V_19 -> V_171 , & V_120 -> V_172 ) ;
F_122 ( V_19 -> V_171 ) ;
V_120 -> V_118 = V_118 ;
V_64 -> V_120 = V_120 ;
V_64 -> V_135 = V_157 ;
V_64 -> V_132 = 0 ;
return 0 ;
V_166:
F_123 ( V_120 ) ;
V_165:
F_14 ( V_118 ) ;
V_164:
F_84 ( V_56 ) ;
return V_46 ;
}
static T_2 * F_124 ( struct V_3 * V_4 ,
struct V_18 * V_19 ,
unsigned int V_155 )
{
struct V_53 * V_64 = & V_4 -> V_53 ;
T_2 * V_157 ;
if ( V_64 -> V_132 > V_145 / sizeof( T_2 ) - ( V_155 + 1 ) )
F_83 ( V_64 ) ;
if ( F_8 ( ! V_64 -> V_120 ) ) {
int V_46 ;
V_46 = F_110 ( V_4 , V_19 , V_155 ) ;
if ( F_8 ( V_46 ) )
return F_96 ( V_46 ) ;
}
V_157 = V_64 -> V_135 + V_64 -> V_132 ;
V_64 -> V_132 += V_155 ;
return V_157 ;
}
static T_1
F_125 ( struct V_18 * V_19 ,
const struct V_121 * V_122 ,
struct V_3 * V_4 ,
const struct V_18 * V_123 )
{
T_1 V_26 = V_122 -> V_26 ;
T_1 V_174 = F_73 ( V_122 , V_123 ) ;
bool V_175 = V_4 -> V_53 . V_129 ;
void * V_127 ;
if ( ! V_4 -> V_53 . V_127 &&
( V_66 == V_176 ||
! F_118 ( V_19 -> V_171 , true ) ) ) {
const unsigned int V_128 = V_4 -> V_53 . V_128 ;
unsigned int V_155 ;
T_2 * V_118 ;
T_1 V_152 ;
if ( V_175 )
V_155 = V_26 & 7 ? 8 : 5 ;
else if ( V_128 >= 4 )
V_155 = 4 ;
else if ( V_128 >= 3 )
V_155 = 3 ;
else
goto V_177;
V_118 = F_124 ( V_4 , V_19 , V_155 ) ;
if ( F_49 ( V_118 ) )
goto V_177;
V_152 = F_1 ( V_19 -> V_21 . V_24 + V_26 ) ;
if ( V_175 ) {
if ( V_26 & 7 ) {
* V_118 ++ = V_178 ;
* V_118 ++ = F_126 ( V_152 ) ;
* V_118 ++ = F_127 ( V_152 ) ;
* V_118 ++ = F_126 ( V_174 ) ;
V_152 = F_1 ( V_152 + 4 ) ;
* V_118 ++ = V_178 ;
* V_118 ++ = F_126 ( V_152 ) ;
* V_118 ++ = F_127 ( V_152 ) ;
* V_118 ++ = F_127 ( V_174 ) ;
} else {
* V_118 ++ = ( V_178 | ( 1 << 21 ) ) + 1 ;
* V_118 ++ = F_126 ( V_152 ) ;
* V_118 ++ = F_127 ( V_152 ) ;
* V_118 ++ = F_126 ( V_174 ) ;
* V_118 ++ = F_127 ( V_174 ) ;
}
} else if ( V_128 >= 6 ) {
* V_118 ++ = V_178 ;
* V_118 ++ = 0 ;
* V_118 ++ = V_152 ;
* V_118 ++ = V_174 ;
} else if ( V_128 >= 4 ) {
* V_118 ++ = V_178 | V_179 ;
* V_118 ++ = 0 ;
* V_118 ++ = V_152 ;
* V_118 ++ = V_174 ;
} else {
* V_118 ++ = V_180 | V_181 ;
* V_118 ++ = V_152 ;
* V_118 ++ = V_174 ;
}
goto V_110;
}
V_177:
V_127 = F_107 ( V_19 -> V_56 , & V_4 -> V_53 , V_26 >> V_150 ) ;
if ( F_49 ( V_127 ) )
return F_50 ( V_127 ) ;
F_108 ( V_127 + F_23 ( V_26 ) ,
F_126 ( V_174 ) ,
V_4 -> V_53 . V_127 ) ;
if ( V_175 ) {
V_26 += sizeof( T_2 ) ;
V_174 >>= 32 ;
V_175 = false ;
goto V_177;
}
V_110:
return V_123 -> V_21 . V_24 | V_62 ;
}
static T_1
F_128 ( struct V_3 * V_4 ,
struct V_18 * V_19 ,
const struct V_121 * V_122 )
{
struct V_18 * V_123 ;
int V_46 ;
V_123 = F_67 ( V_4 , V_122 -> V_182 ) ;
if ( F_8 ( ! V_123 ) )
return - V_113 ;
if ( F_8 ( V_122 -> V_158 & ( V_122 -> V_158 - 1 ) ) ) {
F_24 ( L_5
L_6
L_7 ,
V_122 -> V_182 ,
( int ) V_122 -> V_26 ,
V_122 -> V_183 ,
V_122 -> V_158 ) ;
return - V_40 ;
}
if ( F_8 ( ( V_122 -> V_158 | V_122 -> V_183 )
& ~ V_184 ) ) {
F_24 ( L_8
L_6
L_7 ,
V_122 -> V_182 ,
( int ) V_122 -> V_26 ,
V_122 -> V_183 ,
V_122 -> V_158 ) ;
return - V_40 ;
}
if ( V_122 -> V_158 ) {
V_123 -> V_43 -> V_5 |= V_173 ;
if ( V_122 -> V_158 == V_185 &&
F_129 ( V_4 -> V_100 ) ) {
V_46 = F_130 ( V_123 , V_123 -> V_56 -> V_71 ,
V_35 ) ;
if ( F_131 ( V_46 ,
L_9 ) )
return V_46 ;
}
}
if ( ! V_66 &&
F_1 ( V_123 -> V_21 . V_24 ) == V_122 -> V_186 )
return 0 ;
if ( F_8 ( V_122 -> V_26 >
V_19 -> V_7 - ( V_4 -> V_53 . V_129 ? 8 : 4 ) ) ) {
F_24 ( L_10
L_11 ,
V_122 -> V_182 ,
( int ) V_122 -> V_26 ,
( int ) V_19 -> V_7 ) ;
return - V_40 ;
}
if ( F_8 ( V_122 -> V_26 & 3 ) ) {
F_24 ( L_12
L_13 ,
V_122 -> V_182 ,
( int ) V_122 -> V_26 ) ;
return - V_40 ;
}
V_19 -> V_43 -> V_5 &= ~ V_187 ;
return F_125 ( V_19 , V_122 , V_4 , V_123 ) ;
}
static int F_132 ( struct V_3 * V_4 , struct V_18 * V_19 )
{
#define F_133 ( T_3 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_121 V_188 [ F_133 ( 512 ) ] ;
struct V_121 T_4 * V_189 ;
const struct V_16 * V_17 = V_19 -> V_43 ;
unsigned int V_190 ;
V_189 = F_134 ( V_17 -> V_191 ) ;
V_190 = V_17 -> V_50 ;
if ( F_8 ( V_190 > F_133 ( V_192 ) ) )
return - V_40 ;
if ( F_8 ( ! F_135 ( V_193 , V_189 , V_190 * sizeof( * V_189 ) ) ) )
return - V_194 ;
do {
struct V_121 * V_195 = V_188 ;
unsigned int V_77 =
F_136 (unsigned int, remain, ARRAY_SIZE(stack)) ;
unsigned int V_196 ;
F_137 () ;
V_196 = F_138 ( V_195 , V_189 , V_77 * sizeof( V_195 [ 0 ] ) ) ;
F_139 () ;
if ( F_8 ( V_196 ) ) {
V_190 = - V_194 ;
goto V_110;
}
V_190 -= V_77 ;
do {
T_1 V_26 = F_128 ( V_4 , V_19 , V_195 ) ;
if ( F_140 ( V_26 == 0 ) ) {
} else if ( ( V_197 ) V_26 < 0 ) {
V_190 = ( int ) V_26 ;
goto V_110;
} else {
V_26 = F_1 ( V_26 & ~ V_62 ) ;
F_141 ( V_26 ,
& V_189 [ V_195 - V_188 ] . V_186 ) ;
}
} while ( V_195 ++ , -- V_77 );
V_189 += F_142 ( V_188 ) ;
} while ( V_190 );
V_110:
F_87 ( & V_4 -> V_53 ) ;
return V_190 ;
}
static int
F_143 ( struct V_3 * V_4 , struct V_18 * V_19 )
{
const struct V_16 * V_17 = V_19 -> V_43 ;
struct V_121 * V_52 =
F_61 ( F_62 ( * V_52 ) , V_17 -> V_191 ) ;
unsigned int V_80 ;
int V_46 ;
for ( V_80 = 0 ; V_80 < V_17 -> V_50 ; V_80 ++ ) {
T_1 V_26 = F_128 ( V_4 , V_19 , & V_52 [ V_80 ] ) ;
if ( ( V_197 ) V_26 < 0 ) {
V_46 = ( int ) V_26 ;
goto V_46;
}
}
V_46 = 0 ;
V_46:
F_87 ( & V_4 -> V_53 ) ;
return V_46 ;
}
static int F_144 ( const struct V_16 * V_17 )
{
const char T_4 * V_152 , * V_198 ;
unsigned long V_7 ;
char T_5 V_199 ;
V_7 = V_17 -> V_50 ;
if ( V_7 == 0 )
return 0 ;
if ( V_7 > F_133 ( V_192 ) )
return - V_40 ;
V_152 = F_134 ( V_17 -> V_191 ) ;
V_7 *= sizeof( struct V_121 ) ;
if ( ! F_135 ( V_193 , V_152 , V_7 ) )
return - V_194 ;
V_198 = V_152 + V_7 ;
for (; V_152 < V_198 ; V_152 += V_145 ) {
int V_46 = F_145 ( V_199 , V_152 ) ;
if ( V_46 )
return V_46 ;
}
return F_145 ( V_199 , V_198 - 1 ) ;
}
static int F_146 ( const struct V_3 * V_4 )
{
const unsigned int V_77 = V_4 -> V_8 ;
unsigned int V_80 ;
int V_46 ;
for ( V_80 = 0 ; V_80 < V_77 ; V_80 ++ ) {
const unsigned int V_200 = V_4 -> V_45 [ V_80 ] . V_50 ;
struct V_121 T_4 * V_189 ;
struct V_121 * V_52 ;
unsigned long V_7 ;
unsigned long V_196 ;
if ( V_200 == 0 )
continue;
V_46 = F_144 ( & V_4 -> V_45 [ V_80 ] ) ;
if ( V_46 )
goto V_46;
V_189 = F_134 ( V_4 -> V_45 [ V_80 ] . V_191 ) ;
V_7 = V_200 * sizeof( * V_52 ) ;
V_52 = F_147 ( V_7 , 1 , V_9 ) ;
if ( ! V_52 ) {
F_148 ( V_52 ) ;
V_46 = - V_14 ;
goto V_46;
}
V_196 = 0 ;
do {
unsigned int V_155 =
F_136 ( T_1 , F_149 ( 31 ) , V_7 - V_196 ) ;
if ( F_150 ( ( char * ) V_52 + V_196 ,
( char * ) V_189 + V_196 ,
V_155 ) ) {
F_148 ( V_52 ) ;
V_46 = - V_194 ;
goto V_46;
}
V_196 += V_155 ;
} while ( V_196 < V_7 );
F_151 () ;
for ( V_196 = 0 ; V_196 < V_200 ; V_196 ++ )
F_152 ( - 1 ,
& V_189 [ V_196 ] . V_186 ,
V_201 ) ;
V_201:
F_153 () ;
V_4 -> V_45 [ V_80 ] . V_191 = ( V_59 ) V_52 ;
}
return 0 ;
V_46:
while ( V_80 -- ) {
struct V_121 * V_52 =
F_61 ( F_62 ( * V_52 ) , V_4 -> V_45 [ V_80 ] . V_191 ) ;
if ( V_4 -> V_45 [ V_80 ] . V_50 )
F_148 ( V_52 ) ;
}
return V_46 ;
}
static int F_154 ( const struct V_3 * V_4 )
{
const unsigned int V_77 = V_4 -> V_8 ;
unsigned int V_80 ;
if ( F_8 ( V_100 . V_202 ) )
return 0 ;
for ( V_80 = 0 ; V_80 < V_77 ; V_80 ++ ) {
int V_46 ;
V_46 = F_144 ( & V_4 -> V_45 [ V_80 ] ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static T_6 int F_155 ( struct V_3 * V_4 )
{
struct V_203 * V_204 = & V_4 -> V_100 -> V_205 ;
bool V_206 = false ;
struct V_18 * V_19 ;
int V_46 = 0 ;
V_177:
if ( F_156 ( V_207 ) ) {
V_46 = - V_208 ;
goto V_110;
}
F_70 ( V_4 ) ;
F_157 ( & V_204 -> V_209 ) ;
if ( ! V_46 ) {
V_46 = F_154 ( V_4 ) ;
} else if ( ! V_206 ) {
V_46 = F_146 ( V_4 ) ;
V_206 = V_46 == 0 ;
} else {
F_158 () ;
V_46 = 0 ;
}
if ( V_46 ) {
F_159 ( & V_204 -> V_209 ) ;
goto V_110;
}
F_160 ( V_4 -> V_100 -> V_139 . V_210 ) ;
V_46 = F_161 ( V_204 ) ;
if ( V_46 ) {
F_159 ( & V_204 -> V_209 ) ;
goto V_110;
}
V_46 = F_53 ( V_4 ) ;
if ( V_46 )
goto V_46;
F_38 (vma, &eb->relocs, reloc_link) {
if ( ! V_206 ) {
F_137 () ;
V_46 = F_132 ( V_4 , V_19 ) ;
F_139 () ;
if ( V_46 )
goto V_177;
} else {
V_46 = F_143 ( V_4 , V_19 ) ;
if ( V_46 )
goto V_46;
}
}
V_46:
if ( V_46 == - V_211 )
goto V_177;
V_110:
if ( V_206 ) {
const unsigned int V_77 = V_4 -> V_8 ;
unsigned int V_80 ;
for ( V_80 = 0 ; V_80 < V_77 ; V_80 ++ ) {
const struct V_16 * V_17 =
& V_4 -> V_45 [ V_80 ] ;
struct V_121 * V_52 ;
if ( ! V_17 -> V_50 )
continue;
V_52 = F_61 ( F_62 ( * V_52 ) , V_17 -> V_191 ) ;
F_148 ( V_52 ) ;
}
}
return V_46 ;
}
static int F_162 ( struct V_3 * V_4 )
{
if ( F_53 ( V_4 ) )
goto V_212;
if ( V_4 -> args -> V_5 & V_63 ) {
struct V_18 * V_19 ;
F_38 (vma, &eb->relocs, reloc_link) {
if ( F_132 ( V_4 , V_19 ) )
goto V_212;
}
}
return 0 ;
V_212:
return F_155 ( V_4 ) ;
}
static void F_163 ( struct V_18 * V_19 ,
struct V_156 * V_213 ,
unsigned int V_5 )
{
struct V_214 * V_171 = V_19 -> V_171 ;
F_120 ( V_171 , NULL ) ;
if ( V_5 & V_173 )
F_121 ( V_171 , & V_213 -> V_172 ) ;
else if ( F_164 ( V_171 ) == 0 )
F_165 ( V_171 , & V_213 -> V_172 ) ;
F_122 ( V_171 ) ;
}
static int F_166 ( struct V_3 * V_4 )
{
const unsigned int V_77 = V_4 -> V_8 ;
unsigned int V_80 ;
int V_46 ;
for ( V_80 = 0 ; V_80 < V_77 ; V_80 ++ ) {
struct V_16 * V_17 = & V_4 -> V_45 [ V_80 ] ;
struct V_18 * V_19 = F_40 ( V_17 ) ;
struct V_65 * V_56 = V_19 -> V_56 ;
if ( V_17 -> V_5 & V_215 ) {
struct V_216 * V_217 ;
V_217 = F_167 ( sizeof( * V_217 ) , V_218 ) ;
if ( F_8 ( ! V_217 ) )
return - V_14 ;
V_217 -> V_219 = V_4 -> V_220 -> V_221 ;
V_217 -> V_19 = V_19 ;
V_4 -> V_220 -> V_221 = V_217 ;
}
if ( F_8 ( V_56 -> V_70 && ! V_56 -> V_222 ) ) {
if ( F_168 ( V_56 , 0 ) )
V_17 -> V_5 &= ~ V_187 ;
}
if ( V_17 -> V_5 & V_187 )
goto V_223;
V_46 = F_116
( V_4 -> V_220 , V_56 , V_17 -> V_5 & V_173 ) ;
if ( V_46 )
return V_46 ;
V_223:
F_119 ( V_19 , V_4 -> V_220 , V_17 -> V_5 ) ;
F_16 ( V_19 , V_17 ) ;
V_19 -> V_43 = NULL ;
}
for ( V_80 = 0 ; V_80 < V_77 ; V_80 ++ ) {
const struct V_16 * V_17 = & V_4 -> V_45 [ V_80 ] ;
struct V_18 * V_19 = F_40 ( V_17 ) ;
F_163 ( V_19 , V_4 -> V_220 , V_17 -> V_5 ) ;
if ( F_8 ( V_17 -> V_5 & V_116 ) )
F_69 ( V_19 ) ;
}
V_4 -> V_45 = NULL ;
F_85 ( V_4 -> V_100 ) ;
return V_4 -> V_160 -> V_167 ( V_4 -> V_220 , V_168 ) ;
}
static bool F_169 ( struct V_224 * V_45 )
{
if ( V_45 -> V_5 & V_225 )
return false ;
if ( V_45 -> V_226 || V_45 -> V_227 )
return false ;
if ( V_45 -> V_228 == 0xffffffff ) {
F_24 ( L_14 ) ;
V_45 -> V_228 = 0 ;
}
if ( V_45 -> V_229 || V_45 -> V_228 )
return false ;
if ( ( V_45 -> V_230 | V_45 -> V_231 ) & 0x7 )
return false ;
return true ;
}
void F_119 ( struct V_18 * V_19 ,
struct V_156 * V_213 ,
unsigned int V_5 )
{
struct V_65 * V_56 = V_19 -> V_56 ;
const unsigned int V_232 = V_213 -> V_160 -> V_233 ;
F_170 ( & V_213 -> V_100 -> V_205 . V_209 ) ;
F_17 ( ! F_32 ( & V_19 -> V_21 ) ) ;
if ( ! F_171 ( V_19 ) )
V_56 -> V_234 ++ ;
F_172 ( V_19 , V_232 ) ;
F_173 ( & V_19 -> V_235 [ V_232 ] , V_213 ) ;
F_174 ( & V_19 -> V_236 , & V_19 -> V_83 -> V_237 ) ;
V_56 -> V_99 . V_158 = 0 ;
if ( V_5 & V_173 ) {
V_56 -> V_99 . V_158 = V_238 ;
if ( F_175 ( V_56 , V_239 ) )
F_173 ( & V_56 -> V_240 , V_213 ) ;
V_56 -> V_99 . V_183 = 0 ;
}
V_56 -> V_99 . V_183 |= V_184 ;
if ( V_5 & V_36 )
F_173 ( & V_19 -> V_241 , V_213 ) ;
}
static int F_176 ( struct V_156 * V_213 )
{
T_2 * V_242 ;
int V_80 ;
if ( ! F_177 ( V_213 -> V_100 ) || V_213 -> V_160 -> V_233 != V_243 ) {
F_24 ( L_15 ) ;
return - V_40 ;
}
V_242 = F_178 ( V_213 , 4 * 2 + 2 ) ;
if ( F_49 ( V_242 ) )
return F_50 ( V_242 ) ;
* V_242 ++ = F_179 ( 4 ) ;
for ( V_80 = 0 ; V_80 < 4 ; V_80 ++ ) {
* V_242 ++ = F_180 ( F_181 ( V_80 ) ) ;
* V_242 ++ = 0 ;
}
* V_242 ++ = V_244 ;
F_182 ( V_213 , V_242 ) ;
return 0 ;
}
static struct V_18 * F_183 ( struct V_3 * V_4 , bool V_245 )
{
struct V_65 * V_246 ;
struct V_18 * V_19 ;
int V_46 ;
V_246 = F_111 ( & V_4 -> V_160 -> V_161 ,
F_184 ( V_4 -> V_231 ) ) ;
if ( F_49 ( V_246 ) )
return F_185 ( V_246 ) ;
V_46 = F_186 ( V_4 -> V_160 ,
V_4 -> V_118 -> V_56 ,
V_246 ,
V_4 -> V_230 ,
V_4 -> V_231 ,
V_245 ) ;
if ( V_46 ) {
if ( V_46 == - V_247 )
V_19 = NULL ;
else
V_19 = F_96 ( V_46 ) ;
goto V_110;
}
V_19 = F_102 ( V_246 , NULL , 0 , 0 , 0 ) ;
if ( F_49 ( V_19 ) )
goto V_110;
V_19 -> V_43 =
memset ( & V_4 -> V_45 [ V_4 -> V_8 ++ ] ,
0 , sizeof( * V_19 -> V_43 ) ) ;
V_19 -> V_43 -> V_5 = V_20 | V_116 ;
F_31 ( V_19 -> V_43 ) = ( V_59 ) F_65 ( V_19 ) ;
V_110:
F_113 ( V_246 ) ;
return V_19 ;
}
static void
F_187 ( struct V_156 * V_213 , struct V_248 * V_93 )
{
V_213 -> V_249 = V_93 -> V_94 ;
F_29 ( & V_213 -> V_250 , & V_213 -> V_249 -> V_139 . V_251 ) ;
}
static int F_188 ( struct V_3 * V_4 )
{
int V_46 ;
V_46 = F_166 ( V_4 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_117 ( V_4 -> V_220 ) ;
if ( V_46 )
return V_46 ;
if ( V_4 -> args -> V_5 & V_252 ) {
V_46 = F_176 ( V_4 -> V_220 ) ;
if ( V_46 )
return V_46 ;
}
V_46 = V_4 -> V_160 -> V_169 ( V_4 -> V_220 ,
V_4 -> V_118 -> V_21 . V_24 +
V_4 -> V_230 ,
V_4 -> V_231 ,
V_4 -> V_253 ) ;
if ( V_46 )
return V_46 ;
return 0 ;
}
static unsigned int
F_189 ( struct V_125 * V_254 ,
struct V_248 * V_93 )
{
struct V_255 * V_249 = V_93 -> V_94 ;
if ( ( int ) V_249 -> V_256 < 0 )
V_249 -> V_256 = F_190 ( 1 ,
& V_254 -> V_139 . V_257 ) ;
return V_249 -> V_256 ;
}
static struct V_258 *
F_191 ( struct V_125 * V_254 ,
struct V_248 * V_93 ,
struct V_224 * args )
{
unsigned int V_259 = args -> V_5 & V_260 ;
struct V_258 * V_160 ;
if ( V_259 > V_261 ) {
F_24 ( L_16 , V_259 ) ;
return NULL ;
}
if ( ( V_259 != V_262 ) &&
( ( args -> V_5 & V_263 ) != 0 ) ) {
F_24 ( L_17
L_18 , ( int ) ( args -> V_5 ) ) ;
return NULL ;
}
if ( V_259 == V_262 && F_192 ( V_254 ) ) {
unsigned int V_264 = args -> V_5 & V_263 ;
if ( V_264 == V_265 ) {
V_264 = F_189 ( V_254 , V_93 ) ;
} else if ( V_264 >= V_266 &&
V_264 <= V_267 ) {
V_264 >>= V_268 ;
V_264 -- ;
} else {
F_24 ( L_19 ,
V_264 ) ;
return NULL ;
}
V_160 = V_254 -> V_160 [ F_193 ( V_264 ) ] ;
} else {
V_160 = V_254 -> V_160 [ V_269 [ V_259 ] ] ;
}
if ( ! V_160 ) {
F_24 ( L_20 , V_259 ) ;
return NULL ;
}
return V_160 ;
}
static int
F_194 ( struct V_203 * V_204 ,
struct V_248 * V_93 ,
struct V_224 * args ,
struct V_16 * V_45 )
{
struct V_3 V_4 ;
struct V_270 * V_271 = NULL ;
struct V_272 * V_273 = NULL ;
int V_274 = - 1 ;
int V_46 ;
F_97 ( V_275 &
~ V_276 ) ;
V_4 . V_100 = F_195 ( V_204 ) ;
V_4 . V_93 = V_93 ;
V_4 . args = args ;
if ( V_66 || ! ( args -> V_5 & V_277 ) )
args -> V_5 |= V_63 ;
V_4 . V_45 = V_45 ;
V_4 . V_92 = NULL ;
V_4 . V_39 = V_276 ;
if ( F_196 ( V_4 . V_100 ) )
V_4 . V_39 |= V_34 ;
F_74 ( & V_4 . V_53 , V_4 . V_100 ) ;
V_4 . V_8 = args -> V_8 ;
V_4 . V_230 = args -> V_230 ;
V_4 . V_231 = args -> V_231 ;
V_4 . V_253 = 0 ;
if ( args -> V_5 & V_278 ) {
if ( ! F_197 ( V_93 ) || ! F_198 ( V_279 ) )
return - V_280 ;
V_4 . V_253 |= V_170 ;
}
if ( args -> V_5 & V_281 )
V_4 . V_253 |= V_282 ;
V_4 . V_160 = F_191 ( V_4 . V_100 , V_93 , args ) ;
if ( ! V_4 . V_160 )
return - V_40 ;
if ( args -> V_5 & V_283 ) {
if ( ! F_199 ( V_4 . V_100 ) ) {
F_24 ( L_21 ) ;
return - V_40 ;
}
if ( V_4 . V_160 -> V_233 != V_243 ) {
F_24 ( L_22 ,
V_4 . V_160 -> V_284 ) ;
return - V_40 ;
}
V_4 . V_253 |= V_285 ;
}
if ( args -> V_5 & V_286 ) {
V_271 = F_200 ( F_126 ( args -> V_287 ) ) ;
if ( ! V_271 )
return - V_40 ;
}
if ( args -> V_5 & V_288 ) {
V_274 = F_201 ( V_289 ) ;
if ( V_274 < 0 ) {
V_46 = V_274 ;
goto V_290;
}
}
V_46 = F_5 ( & V_4 ) ;
if ( V_46 )
goto V_291;
F_17 ( ! V_4 . V_15 ) ;
F_202 ( V_4 . V_100 ) ;
V_46 = F_161 ( V_204 ) ;
if ( V_46 )
goto V_292;
V_46 = F_47 ( & V_4 ) ;
if ( F_8 ( V_46 ) )
goto V_293;
V_46 = F_162 ( & V_4 ) ;
if ( V_46 ) {
args -> V_5 &= ~ V_63 ;
goto V_294;
}
if ( F_8 ( V_4 . V_118 -> V_43 -> V_5 & V_173 ) ) {
F_24 ( L_23 ) ;
V_46 = - V_40 ;
goto V_294;
}
if ( V_4 . V_230 > V_4 . V_118 -> V_7 ||
V_4 . V_231 > V_4 . V_118 -> V_7 - V_4 . V_230 ) {
F_24 ( L_24 ) ;
V_46 = - V_40 ;
goto V_294;
}
if ( V_4 . V_160 -> V_295 && V_4 . V_231 ) {
struct V_18 * V_19 ;
V_19 = F_183 ( & V_4 , F_197 ( V_93 ) ) ;
if ( F_49 ( V_19 ) ) {
V_46 = F_50 ( V_19 ) ;
goto V_294;
}
if ( V_19 ) {
V_4 . V_253 |= V_170 ;
V_4 . V_230 = 0 ;
V_4 . V_118 = V_19 ;
}
}
if ( V_4 . V_231 == 0 )
V_4 . V_231 = V_4 . V_118 -> V_7 - V_4 . V_230 ;
if ( V_4 . V_253 & V_170 ) {
struct V_18 * V_19 ;
V_19 = F_102 ( V_4 . V_118 -> V_56 , NULL , 0 , 0 , 0 ) ;
if ( F_49 ( V_19 ) ) {
V_46 = F_50 ( V_19 ) ;
goto V_294;
}
V_4 . V_118 = V_19 ;
}
F_17 ( V_4 . V_53 . V_120 ) ;
V_4 . V_220 = F_115 ( V_4 . V_160 , V_4 . V_92 ) ;
if ( F_49 ( V_4 . V_220 ) ) {
V_46 = F_50 ( V_4 . V_220 ) ;
goto V_296;
}
if ( V_271 ) {
V_46 = F_203 ( V_4 . V_220 , V_271 ) ;
if ( V_46 < 0 )
goto V_166;
}
if ( V_274 != - 1 ) {
V_273 = F_204 ( & V_4 . V_220 -> V_172 ) ;
if ( ! V_273 ) {
V_46 = - V_14 ;
goto V_166;
}
}
V_4 . V_220 -> V_118 = V_4 . V_118 ;
F_205 ( V_4 . V_220 , V_4 . V_253 ) ;
V_46 = F_188 ( & V_4 ) ;
V_166:
F_86 ( V_4 . V_220 , V_46 == 0 ) ;
F_187 ( V_4 . V_220 , V_93 ) ;
if ( V_273 ) {
if ( V_46 == 0 ) {
F_206 ( V_274 , V_273 -> V_93 ) ;
args -> V_287 &= F_4 ( 0 , 31 ) ;
args -> V_287 |= ( T_1 ) V_274 << 32 ;
V_274 = - 1 ;
} else {
F_207 ( V_273 -> V_93 ) ;
}
}
V_296:
if ( V_4 . V_253 & V_170 )
F_14 ( V_4 . V_118 ) ;
V_294:
if ( V_4 . V_45 )
F_68 ( & V_4 ) ;
F_208 ( V_4 . V_92 ) ;
V_293:
F_157 ( & V_204 -> V_209 ) ;
V_292:
F_209 ( V_4 . V_100 ) ;
F_71 ( & V_4 ) ;
V_291:
if ( V_274 != - 1 )
F_210 ( V_274 ) ;
V_290:
F_211 ( V_271 ) ;
return V_46 ;
}
int
F_212 ( struct V_203 * V_204 , void * V_297 ,
struct V_248 * V_93 )
{
const T_7 V_298 = sizeof( struct V_16 ) ;
struct V_299 * args = V_297 ;
struct V_224 V_300 ;
struct V_301 * V_302 = NULL ;
struct V_16 * V_303 = NULL ;
unsigned int V_80 ;
int V_46 ;
if ( args -> V_8 < 1 || args -> V_8 > V_304 / V_298 - 1 ) {
F_24 ( L_25 , args -> V_8 ) ;
return - V_40 ;
}
V_300 . V_305 = args -> V_305 ;
V_300 . V_8 = args -> V_8 ;
V_300 . V_230 = args -> V_230 ;
V_300 . V_231 = args -> V_231 ;
V_300 . V_229 = args -> V_229 ;
V_300 . V_228 = args -> V_228 ;
V_300 . V_226 = args -> V_226 ;
V_300 . V_227 = args -> V_227 ;
V_300 . V_5 = V_306 ;
F_213 ( V_300 , 0 ) ;
if ( ! F_169 ( & V_300 ) )
return - V_40 ;
V_302 = F_147 ( args -> V_8 , sizeof( * V_302 ) ,
V_11 | V_9 ) ;
V_303 = F_147 ( args -> V_8 + 1 , V_298 ,
V_11 | V_9 ) ;
if ( V_302 == NULL || V_303 == NULL ) {
F_24 ( L_26 ,
args -> V_8 ) ;
F_148 ( V_302 ) ;
F_148 ( V_303 ) ;
return - V_14 ;
}
V_46 = F_214 ( V_302 ,
F_134 ( args -> V_305 ) ,
sizeof( * V_302 ) * args -> V_8 ) ;
if ( V_46 ) {
F_24 ( L_27 ,
args -> V_8 , V_46 ) ;
F_148 ( V_302 ) ;
F_148 ( V_303 ) ;
return - V_194 ;
}
for ( V_80 = 0 ; V_80 < args -> V_8 ; V_80 ++ ) {
V_303 [ V_80 ] . V_44 = V_302 [ V_80 ] . V_44 ;
V_303 [ V_80 ] . V_50 = V_302 [ V_80 ] . V_50 ;
V_303 [ V_80 ] . V_191 = V_302 [ V_80 ] . V_191 ;
V_303 [ V_80 ] . V_23 = V_302 [ V_80 ] . V_23 ;
V_303 [ V_80 ] . V_26 = V_302 [ V_80 ] . V_26 ;
if ( F_75 ( F_195 ( V_204 ) ) < 4 )
V_303 [ V_80 ] . V_5 = V_36 ;
else
V_303 [ V_80 ] . V_5 = 0 ;
}
V_46 = F_194 ( V_204 , V_93 , & V_300 , V_303 ) ;
if ( V_300 . V_5 & V_63 ) {
struct V_301 T_4 * V_307 =
F_134 ( args -> V_305 ) ;
for ( V_80 = 0 ; V_80 < args -> V_8 ; V_80 ++ ) {
if ( ! ( V_303 [ V_80 ] . V_26 & V_62 ) )
continue;
V_303 [ V_80 ] . V_26 =
F_1 ( V_303 [ V_80 ] . V_26 & V_30 ) ;
V_303 [ V_80 ] . V_26 &= V_30 ;
if ( F_215 ( & V_307 [ V_80 ] . V_26 ,
& V_303 [ V_80 ] . V_26 ,
sizeof( V_307 [ V_80 ] . V_26 ) ) )
break;
}
}
F_148 ( V_302 ) ;
F_148 ( V_303 ) ;
return V_46 ;
}
int
F_216 ( struct V_203 * V_204 , void * V_297 ,
struct V_248 * V_93 )
{
const T_7 V_298 = sizeof( struct V_16 ) ;
struct V_224 * args = V_297 ;
struct V_16 * V_303 ;
int V_46 ;
if ( args -> V_8 < 1 || args -> V_8 > V_304 / V_298 - 1 ) {
F_24 ( L_25 , args -> V_8 ) ;
return - V_40 ;
}
if ( ! F_169 ( args ) )
return - V_40 ;
V_303 = F_147 ( args -> V_8 + 1 , V_298 ,
V_11 | V_9 ) ;
if ( V_303 == NULL ) {
F_24 ( L_26 ,
args -> V_8 ) ;
return - V_14 ;
}
if ( F_214 ( V_303 ,
F_134 ( args -> V_305 ) ,
sizeof( * V_303 ) * args -> V_8 ) ) {
F_24 ( L_28 , args -> V_8 ) ;
F_148 ( V_303 ) ;
return - V_194 ;
}
V_46 = F_194 ( V_204 , V_93 , args , V_303 ) ;
if ( args -> V_5 & V_63 ) {
struct V_16 T_4 * V_307 =
F_134 ( args -> V_305 ) ;
unsigned int V_80 ;
F_151 () ;
for ( V_80 = 0 ; V_80 < args -> V_8 ; V_80 ++ ) {
if ( ! ( V_303 [ V_80 ] . V_26 & V_62 ) )
continue;
V_303 [ V_80 ] . V_26 =
F_1 ( V_303 [ V_80 ] . V_26 & V_30 ) ;
F_152 ( V_303 [ V_80 ] . V_26 ,
& V_307 [ V_80 ] . V_26 ,
V_201 ) ;
}
V_201:
F_153 () ;
}
args -> V_5 &= ~ V_308 ;
F_148 ( V_303 ) ;
return V_46 ;
}
