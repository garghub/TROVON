bool F_1 ( T_1 V_1 )
{
if ( F_2 ( V_1 ) )
return F_3 ( F_4 ( V_1 ) ) ;
return true ;
}
int F_5 ( struct V_2 * V_3 )
{
int V_4 ;
if ( F_6 ( & V_3 -> V_5 ) )
return - V_6 ;
V_4 = F_7 () ;
F_8 ( & V_3 -> V_7 ) ;
F_9 ( V_3 , V_4 ) ;
F_10 () ;
return 0 ;
}
void F_11 ( struct V_2 * V_3 )
{
F_12 () ;
F_13 ( V_3 ) ;
F_14 ( & V_3 -> V_7 ) ;
F_15 () ;
F_16 ( & V_3 -> V_5 ) ;
}
static void F_17 ( void * V_8 )
{
}
bool F_18 ( struct V_9 * V_9 , unsigned int V_10 )
{
int V_11 , V_4 , V_12 ;
T_2 V_13 ;
bool V_14 = true ;
struct V_2 * V_3 ;
F_19 ( & V_13 , V_15 ) ;
V_12 = F_7 () ;
F_20 (i, vcpu, kvm) {
F_21 ( V_10 , V_3 ) ;
V_4 = V_3 -> V_4 ;
F_22 () ;
if ( V_13 != NULL && V_4 != - 1 && V_4 != V_12 &&
F_23 ( V_3 ) != V_16 )
F_24 ( V_4 , V_13 ) ;
}
if ( F_25 ( V_13 == NULL ) )
F_26 ( V_17 , F_17 , NULL , 1 ) ;
else if ( ! F_27 ( V_13 ) )
F_26 ( V_13 , F_17 , NULL , 1 ) ;
else
V_14 = false ;
F_10 () ;
F_28 ( V_13 ) ;
return V_14 ;
}
void F_29 ( struct V_9 * V_9 )
{
long V_18 = V_9 -> V_19 ;
F_22 () ;
if ( F_18 ( V_9 , V_20 ) )
++ V_9 -> V_21 . V_22 ;
F_30 ( & V_9 -> V_19 , V_18 , 0 ) ;
}
void F_31 ( struct V_9 * V_9 )
{
F_18 ( V_9 , V_23 ) ;
}
void F_32 ( struct V_9 * V_9 )
{
F_18 ( V_9 , V_24 ) ;
}
void F_33 ( struct V_9 * V_9 )
{
F_18 ( V_9 , V_25 ) ;
}
int F_34 ( struct V_2 * V_3 , struct V_9 * V_9 , unsigned V_26 )
{
struct V_27 * V_27 ;
int V_28 ;
F_35 ( & V_3 -> V_5 ) ;
V_3 -> V_4 = - 1 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_29 = V_26 ;
V_3 -> V_30 = NULL ;
F_36 ( & V_3 -> V_31 ) ;
F_37 ( V_3 ) ;
V_27 = F_38 ( V_32 | V_33 ) ;
if ( ! V_27 ) {
V_28 = - V_34 ;
goto V_35;
}
V_3 -> V_36 = F_39 ( V_27 ) ;
F_40 ( V_3 , false ) ;
F_41 ( V_3 , false ) ;
V_3 -> V_37 = false ;
V_28 = F_42 ( V_3 ) ;
if ( V_28 < 0 )
goto V_38;
return 0 ;
V_38:
F_43 ( ( unsigned long ) V_3 -> V_36 ) ;
V_35:
return V_28 ;
}
void F_44 ( struct V_2 * V_3 )
{
F_45 ( V_3 -> V_30 ) ;
F_46 ( V_3 ) ;
F_43 ( ( unsigned long ) V_3 -> V_36 ) ;
}
static inline struct V_9 * F_47 ( struct V_39 * V_40 )
{
return F_48 ( V_40 , struct V_9 , V_39 ) ;
}
static void F_49 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_43 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_44 , V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_9 -> V_48 ++ ;
V_44 = F_52 ( V_9 , V_43 ) | V_9 -> V_19 ;
if ( V_44 )
F_29 ( V_9 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_54 ( V_9 , V_43 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
}
static void F_56 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_43 ,
T_3 V_49 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_9 -> V_48 ++ ;
F_57 ( V_9 , V_43 , V_49 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
}
static void F_58 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_50 ,
unsigned long V_51 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_44 = 0 , V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_9 -> V_52 ++ ;
V_44 = F_59 ( V_9 , V_50 , V_51 ) ;
V_44 |= V_9 -> V_19 ;
if ( V_44 )
F_29 ( V_9 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
}
static void F_60 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_50 ,
unsigned long V_51 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_9 -> V_48 ++ ;
F_61 () ;
V_9 -> V_52 -- ;
F_53 ( & V_9 -> V_47 ) ;
F_62 ( V_9 -> V_52 < 0 ) ;
}
static int F_63 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_50 ,
unsigned long V_51 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_53 , V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_53 = F_64 ( V_9 , V_50 , V_51 ) ;
if ( V_53 )
F_29 ( V_9 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
return V_53 ;
}
static int F_65 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_43 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_53 , V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_53 = F_66 ( V_9 , V_43 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
return V_53 ;
}
static void F_67 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_68 ( V_9 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
}
static int F_69 ( struct V_9 * V_9 )
{
V_9 -> V_39 . V_54 = & V_55 ;
return F_70 ( & V_9 -> V_39 , V_56 -> V_42 ) ;
}
static int F_69 ( struct V_9 * V_9 )
{
return 0 ;
}
static struct V_57 * F_71 ( void )
{
int V_11 ;
struct V_57 * V_58 ;
V_58 = F_72 ( sizeof( struct V_57 ) ) ;
if ( ! V_58 )
return NULL ;
V_58 -> V_59 = - 150 ;
for ( V_11 = 0 ; V_11 < V_60 ; V_11 ++ )
V_58 -> V_61 [ V_11 ] = V_58 -> V_62 [ V_11 ] . V_26 = V_11 ;
return V_58 ;
}
static void F_73 ( struct V_63 * V_64 )
{
if ( ! V_64 -> V_65 )
return;
F_74 ( V_64 -> V_65 ) ;
V_64 -> V_65 = NULL ;
}
static void F_75 ( struct V_9 * V_9 , struct V_63 * free ,
struct V_63 * V_66 )
{
if ( ! V_66 || free -> V_65 != V_66 -> V_65 )
F_73 ( free ) ;
F_76 ( V_9 , free , V_66 ) ;
free -> V_67 = 0 ;
}
static void F_77 ( struct V_9 * V_9 , struct V_57 * V_58 )
{
struct V_63 * V_64 ;
if ( ! V_58 )
return;
F_78 (memslot, slots)
F_75 ( V_9 , V_64 , NULL ) ;
F_74 ( V_58 ) ;
}
static struct V_9 * F_79 ( unsigned long type )
{
int V_28 , V_11 ;
struct V_9 * V_9 = F_80 () ;
if ( ! V_9 )
return F_81 ( - V_34 ) ;
V_28 = F_82 ( V_9 , type ) ;
if ( V_28 )
goto V_68;
V_28 = F_83 () ;
if ( V_28 )
goto V_68;
#ifdef F_84
F_85 ( & V_9 -> V_69 ) ;
#endif
F_86 ( V_60 > V_70 ) ;
V_28 = - V_34 ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ ) {
V_9 -> V_62 [ V_11 ] = F_71 () ;
if ( ! V_9 -> V_62 [ V_11 ] )
goto V_72;
}
if ( F_87 ( & V_9 -> V_46 ) )
goto V_72;
if ( F_87 ( & V_9 -> V_73 ) )
goto V_74;
for ( V_11 = 0 ; V_11 < V_75 ; V_11 ++ ) {
V_9 -> V_76 [ V_11 ] = F_88 ( sizeof( struct V_77 ) ,
V_32 ) ;
if ( ! V_9 -> V_76 [ V_11 ] )
goto V_78;
}
F_89 ( & V_9 -> V_47 ) ;
V_9 -> V_42 = V_56 -> V_42 ;
F_90 ( & V_9 -> V_42 -> V_79 ) ;
F_91 ( V_9 ) ;
F_35 ( & V_9 -> V_80 ) ;
F_35 ( & V_9 -> V_81 ) ;
F_35 ( & V_9 -> V_82 ) ;
F_92 ( & V_9 -> V_83 , 1 ) ;
F_93 ( & V_9 -> V_84 ) ;
V_28 = F_69 ( V_9 ) ;
if ( V_28 )
goto V_78;
F_51 ( & V_85 ) ;
F_94 ( & V_9 -> V_86 , & V_86 ) ;
F_53 ( & V_85 ) ;
F_95 () ;
return V_9 ;
V_78:
F_96 ( & V_9 -> V_73 ) ;
V_74:
F_96 ( & V_9 -> V_46 ) ;
V_72:
F_97 () ;
V_68:
for ( V_11 = 0 ; V_11 < V_75 ; V_11 ++ )
F_98 ( V_9 -> V_76 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ )
F_77 ( V_9 , V_9 -> V_62 [ V_11 ] ) ;
F_99 ( V_9 ) ;
return F_81 ( V_28 ) ;
}
void * F_72 ( unsigned long V_87 )
{
if ( V_87 > V_88 )
return F_100 ( V_87 ) ;
else
return F_88 ( V_87 , V_32 ) ;
}
static void F_101 ( struct V_9 * V_9 )
{
struct V_89 * V_90 , * V_91 ;
F_102 (node, tmp, &kvm->devices) {
struct V_92 * V_93 =
F_103 ( V_90 , struct V_92 , V_94 ) ;
F_104 ( V_90 ) ;
V_93 -> V_54 -> V_95 ( V_93 ) ;
}
}
static void F_105 ( struct V_9 * V_9 )
{
int V_11 ;
struct V_41 * V_42 = V_9 -> V_42 ;
F_106 ( V_9 ) ;
F_51 ( & V_85 ) ;
F_104 ( & V_9 -> V_86 ) ;
F_53 ( & V_85 ) ;
F_107 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_75 ; V_11 ++ )
F_108 ( V_9 -> V_76 [ V_11 ] ) ;
F_109 ( V_9 ) ;
#if F_110 ( V_96 ) && F_110 ( V_97 )
F_111 ( & V_9 -> V_39 , V_9 -> V_42 ) ;
#else
F_68 ( V_9 ) ;
#endif
F_112 ( V_9 ) ;
F_101 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ )
F_77 ( V_9 , V_9 -> V_62 [ V_11 ] ) ;
F_96 ( & V_9 -> V_73 ) ;
F_96 ( & V_9 -> V_46 ) ;
F_99 ( V_9 ) ;
F_113 () ;
F_97 () ;
F_114 ( V_42 ) ;
}
void F_115 ( struct V_9 * V_9 )
{
F_90 ( & V_9 -> V_83 ) ;
}
void F_116 ( struct V_9 * V_9 )
{
if ( F_117 ( & V_9 -> V_83 ) )
F_105 ( V_9 ) ;
}
static int F_118 ( struct V_98 * V_98 , struct V_99 * V_100 )
{
struct V_9 * V_9 = V_100 -> V_101 ;
F_119 ( V_9 ) ;
F_116 ( V_9 ) ;
return 0 ;
}
static int F_120 ( struct V_63 * V_64 )
{
unsigned long V_102 = 2 * F_121 ( V_64 ) ;
V_64 -> V_65 = F_72 ( V_102 ) ;
if ( ! V_64 -> V_65 )
return - V_34 ;
return 0 ;
}
static void F_122 ( struct V_57 * V_58 ,
struct V_63 * V_103 )
{
int V_26 = V_103 -> V_26 ;
int V_11 = V_58 -> V_61 [ V_26 ] ;
struct V_63 * V_104 = V_58 -> V_62 ;
F_123 ( V_104 [ V_11 ] . V_26 != V_26 ) ;
if ( ! V_103 -> V_67 ) {
F_123 ( ! V_104 [ V_11 ] . V_67 ) ;
if ( V_104 [ V_11 ] . V_67 )
V_58 -> V_105 -- ;
} else {
if ( ! V_104 [ V_11 ] . V_67 )
V_58 -> V_105 ++ ;
}
while ( V_11 < V_60 - 1 &&
V_103 -> V_106 <= V_104 [ V_11 + 1 ] . V_106 ) {
if ( ! V_104 [ V_11 + 1 ] . V_67 )
break;
V_104 [ V_11 ] = V_104 [ V_11 + 1 ] ;
V_58 -> V_61 [ V_104 [ V_11 ] . V_26 ] = V_11 ;
V_11 ++ ;
}
if ( V_103 -> V_67 ) {
while ( V_11 > 0 &&
V_103 -> V_106 >= V_104 [ V_11 - 1 ] . V_106 ) {
V_104 [ V_11 ] = V_104 [ V_11 - 1 ] ;
V_58 -> V_61 [ V_104 [ V_11 ] . V_26 ] = V_11 ;
V_11 -- ;
}
} else
F_124 ( V_11 != V_58 -> V_105 ) ;
V_104 [ V_11 ] = * V_103 ;
V_58 -> V_61 [ V_104 [ V_11 ] . V_26 ] = V_11 ;
}
static int F_125 ( const struct V_107 * V_108 )
{
T_4 V_109 = V_110 ;
#ifdef F_126
V_109 |= V_111 ;
#endif
if ( V_108 -> V_112 & ~ V_109 )
return - V_113 ;
return 0 ;
}
static struct V_57 * F_127 ( struct V_9 * V_9 ,
int V_114 , struct V_57 * V_58 )
{
struct V_57 * V_115 = F_128 ( V_9 , V_114 ) ;
F_123 ( V_115 -> V_59 & 1 ) ;
V_58 -> V_59 = V_115 -> V_59 + 1 ;
F_129 ( V_9 -> V_62 [ V_114 ] , V_58 ) ;
F_130 ( & V_9 -> V_46 ) ;
V_58 -> V_59 ++ ;
F_131 ( V_9 , V_58 ) ;
return V_115 ;
}
int F_132 ( struct V_9 * V_9 ,
const struct V_107 * V_108 )
{
int V_28 ;
T_5 V_106 ;
unsigned long V_67 ;
struct V_63 * V_116 ;
struct V_63 V_117 , V_103 ;
struct V_57 * V_58 = NULL , * V_115 ;
int V_114 , V_26 ;
enum V_118 V_119 ;
V_28 = F_125 ( V_108 ) ;
if ( V_28 )
goto V_120;
V_28 = - V_113 ;
V_114 = V_108 -> V_116 >> 16 ;
V_26 = ( V_121 ) V_108 -> V_116 ;
if ( V_108 -> V_122 & ( V_88 - 1 ) )
goto V_120;
if ( V_108 -> V_123 & ( V_88 - 1 ) )
goto V_120;
if ( ( V_26 < V_124 ) &&
( ( V_108 -> V_125 & ( V_88 - 1 ) ) ||
! F_133 ( V_126 ,
( void V_127 * ) ( unsigned long ) V_108 -> V_125 ,
V_108 -> V_122 ) ) )
goto V_120;
if ( V_114 >= V_71 || V_26 >= V_60 )
goto V_120;
if ( V_108 -> V_123 + V_108 -> V_122 < V_108 -> V_123 )
goto V_120;
V_116 = F_134 ( F_128 ( V_9 , V_114 ) , V_26 ) ;
V_106 = V_108 -> V_123 >> V_128 ;
V_67 = V_108 -> V_122 >> V_128 ;
if ( V_67 > V_129 )
goto V_120;
V_103 = V_117 = * V_116 ;
V_103 . V_26 = V_26 ;
V_103 . V_106 = V_106 ;
V_103 . V_67 = V_67 ;
V_103 . V_112 = V_108 -> V_112 ;
if ( V_67 ) {
if ( ! V_117 . V_67 )
V_119 = V_130 ;
else {
if ( ( V_108 -> V_125 != V_117 . V_125 ) ||
( V_67 != V_117 . V_67 ) ||
( ( V_103 . V_112 ^ V_117 . V_112 ) & V_111 ) )
goto V_120;
if ( V_106 != V_117 . V_106 )
V_119 = V_131 ;
else if ( V_103 . V_112 != V_117 . V_112 )
V_119 = V_132 ;
else {
V_28 = 0 ;
goto V_120;
}
}
} else {
if ( ! V_117 . V_67 )
goto V_120;
V_119 = V_133 ;
V_103 . V_106 = 0 ;
V_103 . V_112 = 0 ;
}
if ( ( V_119 == V_130 ) || ( V_119 == V_131 ) ) {
V_28 = - V_134 ;
F_78 (slot, __kvm_memslots(kvm, as_id)) {
if ( ( V_116 -> V_26 >= V_124 ) ||
( V_116 -> V_26 == V_26 ) )
continue;
if ( ! ( ( V_106 + V_67 <= V_116 -> V_106 ) ||
( V_106 >= V_116 -> V_106 + V_116 -> V_67 ) ) )
goto V_120;
}
}
if ( ! ( V_103 . V_112 & V_110 ) )
V_103 . V_65 = NULL ;
V_28 = - V_34 ;
if ( V_119 == V_130 ) {
V_103 . V_125 = V_108 -> V_125 ;
if ( F_135 ( V_9 , & V_103 , V_67 ) )
goto V_135;
}
if ( ( V_103 . V_112 & V_110 ) && ! V_103 . V_65 ) {
if ( F_120 ( & V_103 ) < 0 )
goto V_135;
}
V_58 = F_72 ( sizeof( struct V_57 ) ) ;
if ( ! V_58 )
goto V_135;
memcpy ( V_58 , F_128 ( V_9 , V_114 ) , sizeof( struct V_57 ) ) ;
if ( ( V_119 == V_133 ) || ( V_119 == V_131 ) ) {
V_116 = F_134 ( V_58 , V_26 ) ;
V_116 -> V_112 |= V_136 ;
V_115 = F_127 ( V_9 , V_114 , V_58 ) ;
F_136 ( V_9 , & V_117 ) ;
F_137 ( V_9 , V_116 ) ;
V_58 = V_115 ;
}
V_28 = F_138 ( V_9 , & V_103 , V_108 , V_119 ) ;
if ( V_28 )
goto V_137;
if ( V_119 == V_133 ) {
V_103 . V_65 = NULL ;
memset ( & V_103 . V_138 , 0 , sizeof( V_103 . V_138 ) ) ;
}
F_122 ( V_58 , & V_103 ) ;
V_115 = F_127 ( V_9 , V_114 , V_58 ) ;
F_139 ( V_9 , V_108 , & V_117 , & V_103 , V_119 ) ;
F_75 ( V_9 , & V_117 , & V_103 ) ;
F_74 ( V_115 ) ;
if ( ( V_119 == V_130 ) || ( V_119 == V_131 ) ) {
V_28 = F_140 ( V_9 , & V_103 ) ;
return V_28 ;
}
return 0 ;
V_137:
F_74 ( V_58 ) ;
V_135:
F_75 ( V_9 , & V_103 , & V_117 ) ;
V_120:
return V_28 ;
}
int F_141 ( struct V_9 * V_9 ,
const struct V_107 * V_108 )
{
int V_28 ;
F_142 ( & V_9 -> V_82 ) ;
V_28 = F_132 ( V_9 , V_108 ) ;
F_16 ( & V_9 -> V_82 ) ;
return V_28 ;
}
static int F_143 ( struct V_9 * V_9 ,
struct V_107 * V_108 )
{
if ( ( V_121 ) V_108 -> V_116 >= V_124 )
return - V_113 ;
return F_141 ( V_9 , V_108 ) ;
}
int F_144 ( struct V_9 * V_9 ,
struct V_139 * log , int * V_140 )
{
struct V_57 * V_58 ;
struct V_63 * V_64 ;
int V_28 , V_11 , V_114 , V_26 ;
unsigned long V_141 ;
unsigned long V_142 = 0 ;
V_28 = - V_113 ;
V_114 = log -> V_116 >> 16 ;
V_26 = ( V_121 ) log -> V_116 ;
if ( V_114 >= V_71 || V_26 >= V_124 )
goto V_120;
V_58 = F_128 ( V_9 , V_114 ) ;
V_64 = F_134 ( V_58 , V_26 ) ;
V_28 = - V_143 ;
if ( ! V_64 -> V_65 )
goto V_120;
V_141 = F_121 ( V_64 ) ;
for ( V_11 = 0 ; ! V_142 && V_11 < V_141 / sizeof( long ) ; ++ V_11 )
V_142 = V_64 -> V_65 [ V_11 ] ;
V_28 = - V_144 ;
if ( F_145 ( log -> V_65 , V_64 -> V_65 , V_141 ) )
goto V_120;
if ( V_142 )
* V_140 = 1 ;
V_28 = 0 ;
V_120:
return V_28 ;
}
int F_146 ( struct V_9 * V_9 ,
struct V_139 * log , bool * V_140 )
{
struct V_57 * V_58 ;
struct V_63 * V_64 ;
int V_28 , V_11 , V_114 , V_26 ;
unsigned long V_141 ;
unsigned long * V_65 ;
unsigned long * V_145 ;
V_28 = - V_113 ;
V_114 = log -> V_116 >> 16 ;
V_26 = ( V_121 ) log -> V_116 ;
if ( V_114 >= V_71 || V_26 >= V_124 )
goto V_120;
V_58 = F_128 ( V_9 , V_114 ) ;
V_64 = F_134 ( V_58 , V_26 ) ;
V_65 = V_64 -> V_65 ;
V_28 = - V_143 ;
if ( ! V_65 )
goto V_120;
V_141 = F_121 ( V_64 ) ;
V_145 = V_65 + V_141 / sizeof( long ) ;
memset ( V_145 , 0 , V_141 ) ;
F_51 ( & V_9 -> V_47 ) ;
* V_140 = false ;
for ( V_11 = 0 ; V_11 < V_141 / sizeof( long ) ; V_11 ++ ) {
unsigned long V_146 ;
T_5 V_147 ;
if ( ! V_65 [ V_11 ] )
continue;
* V_140 = true ;
V_146 = F_147 ( & V_65 [ V_11 ] , 0 ) ;
V_145 [ V_11 ] = V_146 ;
if ( V_146 ) {
V_147 = V_11 * V_148 ;
F_148 ( V_9 , V_64 ,
V_147 , V_146 ) ;
}
}
F_53 ( & V_9 -> V_47 ) ;
V_28 = - V_144 ;
if ( F_145 ( log -> V_65 , V_145 , V_141 ) )
goto V_120;
V_28 = 0 ;
V_120:
return V_28 ;
}
bool F_149 ( void )
{
return V_149 ;
}
void F_150 ( void )
{
V_149 = false ;
}
struct V_63 * F_151 ( struct V_9 * V_9 , T_5 V_150 )
{
return F_152 ( V_57 ( V_9 ) , V_150 ) ;
}
struct V_63 * F_153 ( struct V_2 * V_3 , T_5 V_150 )
{
return F_152 ( F_154 ( V_3 ) , V_150 ) ;
}
int F_155 ( struct V_9 * V_9 , T_5 V_150 )
{
struct V_63 * V_64 = F_151 ( V_9 , V_150 ) ;
if ( ! V_64 || V_64 -> V_26 >= V_124 ||
V_64 -> V_112 & V_136 )
return 0 ;
return 1 ;
}
unsigned long F_156 ( struct V_9 * V_9 , T_5 V_150 )
{
struct V_151 * V_152 ;
unsigned long V_153 , V_87 ;
V_87 = V_88 ;
V_153 = F_157 ( V_9 , V_150 ) ;
if ( F_158 ( V_153 ) )
return V_88 ;
F_159 ( & V_56 -> V_42 -> V_154 ) ;
V_152 = F_160 ( V_56 -> V_42 , V_153 ) ;
if ( ! V_152 )
goto V_120;
V_87 = F_161 ( V_152 ) ;
V_120:
F_162 ( & V_56 -> V_42 -> V_154 ) ;
return V_87 ;
}
static bool F_163 ( struct V_63 * V_116 )
{
return V_116 -> V_112 & V_111 ;
}
static unsigned long F_164 ( struct V_63 * V_116 , T_5 V_150 ,
T_5 * V_155 , bool V_156 )
{
if ( ! V_116 || V_116 -> V_112 & V_136 )
return V_157 ;
if ( F_163 ( V_116 ) && V_156 )
return V_158 ;
if ( V_155 )
* V_155 = V_116 -> V_67 - ( V_150 - V_116 -> V_106 ) ;
return F_165 ( V_116 , V_150 ) ;
}
static unsigned long F_166 ( struct V_63 * V_116 , T_5 V_150 ,
T_5 * V_155 )
{
return F_164 ( V_116 , V_150 , V_155 , true ) ;
}
unsigned long F_167 ( struct V_63 * V_116 ,
T_5 V_150 )
{
return F_166 ( V_116 , V_150 , NULL ) ;
}
unsigned long F_157 ( struct V_9 * V_9 , T_5 V_150 )
{
return F_166 ( F_151 ( V_9 , V_150 ) , V_150 , NULL ) ;
}
unsigned long F_168 ( struct V_2 * V_3 , T_5 V_150 )
{
return F_166 ( F_153 ( V_3 , V_150 ) , V_150 , NULL ) ;
}
unsigned long F_169 ( struct V_63 * V_116 ,
T_5 V_150 , bool * V_159 )
{
unsigned long V_160 = F_164 ( V_116 , V_150 , NULL , false ) ;
if ( ! F_158 ( V_160 ) && V_159 )
* V_159 = ! F_163 ( V_116 ) ;
return V_160 ;
}
unsigned long F_170 ( struct V_9 * V_9 , T_5 V_150 , bool * V_159 )
{
struct V_63 * V_116 = F_151 ( V_9 , V_150 ) ;
return F_169 ( V_116 , V_150 , V_159 ) ;
}
unsigned long F_171 ( struct V_2 * V_3 , T_5 V_150 , bool * V_159 )
{
struct V_63 * V_116 = F_153 ( V_3 , V_150 ) ;
return F_169 ( V_116 , V_150 , V_159 ) ;
}
static int F_172 ( struct V_161 * V_162 , struct V_41 * V_42 ,
unsigned long V_50 , int V_156 , struct V_27 * * V_27 )
{
int V_112 = V_163 | V_164 | V_165 | V_166 ;
if ( V_156 )
V_112 |= V_167 ;
return F_173 ( V_162 , V_42 , V_50 , 1 , V_112 , V_27 , NULL , NULL ) ;
}
static inline int F_174 ( unsigned long V_153 )
{
int V_168 , V_112 = V_163 | V_165 | V_167 ;
V_168 = F_173 ( V_56 , V_56 -> V_42 , V_153 , 1 ,
V_112 , NULL , NULL , NULL ) ;
return V_168 == - V_169 ;
}
static bool F_175 ( unsigned long V_153 , bool V_170 , bool * V_171 ,
bool V_172 , bool * V_159 , T_1 * V_1 )
{
struct V_27 * V_27 [ 1 ] ;
int V_67 ;
if ( ! ( V_171 || V_170 ) )
return false ;
if ( ! ( V_172 || V_159 ) )
return false ;
V_67 = F_176 ( V_153 , 1 , 1 , V_27 ) ;
if ( V_67 == 1 ) {
* V_1 = F_177 ( V_27 [ 0 ] ) ;
if ( V_159 )
* V_159 = true ;
return true ;
}
return false ;
}
static int F_178 ( unsigned long V_153 , bool * V_171 , bool V_172 ,
bool * V_159 , T_1 * V_1 )
{
struct V_27 * V_27 [ 1 ] ;
int V_67 = 0 ;
F_179 () ;
if ( V_159 )
* V_159 = V_172 ;
if ( V_171 ) {
F_159 ( & V_56 -> V_42 -> V_154 ) ;
V_67 = F_172 ( V_56 , V_56 -> V_42 ,
V_153 , V_172 , V_27 ) ;
F_162 ( & V_56 -> V_42 -> V_154 ) ;
} else
V_67 = F_180 ( V_56 , V_56 -> V_42 , V_153 , 1 ,
V_172 , 0 , V_27 ,
V_163 | V_165 ) ;
if ( V_67 != 1 )
return V_67 ;
if ( F_25 ( ! V_172 ) && V_159 ) {
struct V_27 * V_173 [ 1 ] ;
V_67 = F_176 ( V_153 , 1 , 1 , V_173 ) ;
if ( V_67 == 1 ) {
* V_159 = true ;
F_181 ( V_27 [ 0 ] ) ;
V_27 [ 0 ] = V_173 [ 0 ] ;
}
V_67 = 1 ;
}
* V_1 = F_177 ( V_27 [ 0 ] ) ;
return V_67 ;
}
static bool F_182 ( struct V_151 * V_152 , bool V_172 )
{
if ( F_25 ( ! ( V_152 -> V_174 & V_175 ) ) )
return false ;
if ( V_172 && ( F_25 ( ! ( V_152 -> V_174 & V_176 ) ) ) )
return false ;
return true ;
}
static T_1 F_183 ( unsigned long V_153 , bool V_170 , bool * V_171 ,
bool V_172 , bool * V_159 )
{
struct V_151 * V_152 ;
T_1 V_1 = 0 ;
int V_67 ;
F_62 ( V_170 && V_171 ) ;
if ( F_175 ( V_153 , V_170 , V_171 , V_172 , V_159 , & V_1 ) )
return V_1 ;
if ( V_170 )
return V_177 ;
V_67 = F_178 ( V_153 , V_171 , V_172 , V_159 , & V_1 ) ;
if ( V_67 == 1 )
return V_1 ;
F_159 ( & V_56 -> V_42 -> V_154 ) ;
if ( V_67 == - V_169 ||
( ! V_171 && F_174 ( V_153 ) ) ) {
V_1 = V_178 ;
goto exit;
}
V_152 = F_184 ( V_56 -> V_42 , V_153 , V_153 + 1 ) ;
if ( V_152 == NULL )
V_1 = V_177 ;
else if ( ( V_152 -> V_174 & V_179 ) ) {
V_1 = ( ( V_153 - V_152 -> V_180 ) >> V_128 ) +
V_152 -> V_181 ;
F_62 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_171 && F_182 ( V_152 , V_172 ) )
* V_171 = true ;
V_1 = V_177 ;
}
exit:
F_162 ( & V_56 -> V_42 -> V_154 ) ;
return V_1 ;
}
T_1 F_185 ( struct V_63 * V_116 , T_5 V_150 , bool V_170 ,
bool * V_171 , bool V_172 , bool * V_159 )
{
unsigned long V_153 = F_164 ( V_116 , V_150 , NULL , V_172 ) ;
if ( V_153 == V_158 )
return V_182 ;
if ( F_158 ( V_153 ) )
return V_183 ;
if ( V_159 && F_163 ( V_116 ) ) {
* V_159 = false ;
V_159 = NULL ;
}
return F_183 ( V_153 , V_170 , V_171 , V_172 ,
V_159 ) ;
}
T_1 F_186 ( struct V_9 * V_9 , T_5 V_150 , bool V_172 ,
bool * V_159 )
{
return F_185 ( F_151 ( V_9 , V_150 ) , V_150 , false , NULL ,
V_172 , V_159 ) ;
}
T_1 F_187 ( struct V_63 * V_116 , T_5 V_150 )
{
return F_185 ( V_116 , V_150 , false , NULL , true , NULL ) ;
}
T_1 F_188 ( struct V_63 * V_116 , T_5 V_150 )
{
return F_185 ( V_116 , V_150 , true , NULL , true , NULL ) ;
}
T_1 F_189 ( struct V_9 * V_9 , T_5 V_150 )
{
return F_188 ( F_151 ( V_9 , V_150 ) , V_150 ) ;
}
T_1 F_190 ( struct V_2 * V_3 , T_5 V_150 )
{
return F_188 ( F_153 ( V_3 , V_150 ) , V_150 ) ;
}
T_1 F_191 ( struct V_9 * V_9 , T_5 V_150 )
{
return F_187 ( F_151 ( V_9 , V_150 ) , V_150 ) ;
}
T_1 F_192 ( struct V_2 * V_3 , T_5 V_150 )
{
return F_187 ( F_153 ( V_3 , V_150 ) , V_150 ) ;
}
int F_193 ( struct V_63 * V_116 , T_5 V_150 ,
struct V_27 * * V_184 , int V_155 )
{
unsigned long V_153 ;
T_5 V_185 ;
V_153 = F_166 ( V_116 , V_150 , & V_185 ) ;
if ( F_158 ( V_153 ) )
return - 1 ;
if ( V_185 < V_155 )
return 0 ;
return F_176 ( V_153 , V_155 , 1 , V_184 ) ;
}
static struct V_27 * F_194 ( T_1 V_1 )
{
if ( F_195 ( V_1 ) )
return V_186 ;
if ( F_1 ( V_1 ) ) {
F_123 ( 1 ) ;
return V_186 ;
}
return F_4 ( V_1 ) ;
}
struct V_27 * F_196 ( struct V_9 * V_9 , T_5 V_150 )
{
T_1 V_1 ;
V_1 = F_191 ( V_9 , V_150 ) ;
return F_194 ( V_1 ) ;
}
struct V_27 * F_197 ( struct V_2 * V_3 , T_5 V_150 )
{
T_1 V_1 ;
V_1 = F_192 ( V_3 , V_150 ) ;
return F_194 ( V_1 ) ;
}
void F_198 ( struct V_27 * V_27 )
{
F_123 ( F_199 ( V_27 ) ) ;
F_200 ( F_177 ( V_27 ) ) ;
}
void F_200 ( T_1 V_1 )
{
if ( ! F_195 ( V_1 ) && ! F_1 ( V_1 ) )
F_181 ( F_4 ( V_1 ) ) ;
}
void F_201 ( struct V_27 * V_27 )
{
F_123 ( F_199 ( V_27 ) ) ;
F_202 ( F_177 ( V_27 ) ) ;
}
static void F_202 ( T_1 V_1 )
{
F_203 ( V_1 ) ;
F_200 ( V_1 ) ;
}
void F_203 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_27 * V_27 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_27 ) )
F_204 ( V_27 ) ;
}
}
void F_205 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_206 ( F_4 ( V_1 ) ) ;
}
void F_207 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_208 ( F_4 ( V_1 ) ) ;
}
static int F_209 ( unsigned long V_187 , int V_147 )
{
if ( V_187 > V_88 - V_147 )
return V_88 - V_147 ;
else
return V_187 ;
}
static int F_210 ( struct V_63 * V_116 , T_5 V_150 ,
void * V_188 , int V_147 , int V_187 )
{
int V_28 ;
unsigned long V_153 ;
V_153 = F_169 ( V_116 , V_150 , NULL ) ;
if ( F_158 ( V_153 ) )
return - V_144 ;
V_28 = F_211 ( V_188 , ( void V_127 * ) V_153 + V_147 , V_187 ) ;
if ( V_28 )
return - V_144 ;
return 0 ;
}
int F_212 ( struct V_9 * V_9 , T_5 V_150 , void * V_188 , int V_147 ,
int V_187 )
{
struct V_63 * V_116 = F_151 ( V_9 , V_150 ) ;
return F_210 ( V_116 , V_150 , V_188 , V_147 , V_187 ) ;
}
int F_213 ( struct V_2 * V_3 , T_5 V_150 , void * V_188 ,
int V_147 , int V_187 )
{
struct V_63 * V_116 = F_153 ( V_3 , V_150 ) ;
return F_210 ( V_116 , V_150 , V_188 , V_147 , V_187 ) ;
}
int F_214 ( struct V_9 * V_9 , T_6 V_189 , void * V_188 , unsigned long V_187 )
{
T_5 V_150 = V_189 >> V_128 ;
int V_190 ;
int V_147 = F_215 ( V_189 ) ;
int V_191 ;
while ( ( V_190 = F_209 ( V_187 , V_147 ) ) != 0 ) {
V_191 = F_212 ( V_9 , V_150 , V_188 , V_147 , V_190 ) ;
if ( V_191 < 0 )
return V_191 ;
V_147 = 0 ;
V_187 -= V_190 ;
V_188 += V_190 ;
++ V_150 ;
}
return 0 ;
}
int F_216 ( struct V_2 * V_3 , T_6 V_189 , void * V_188 , unsigned long V_187 )
{
T_5 V_150 = V_189 >> V_128 ;
int V_190 ;
int V_147 = F_215 ( V_189 ) ;
int V_191 ;
while ( ( V_190 = F_209 ( V_187 , V_147 ) ) != 0 ) {
V_191 = F_213 ( V_3 , V_150 , V_188 , V_147 , V_190 ) ;
if ( V_191 < 0 )
return V_191 ;
V_147 = 0 ;
V_187 -= V_190 ;
V_188 += V_190 ;
++ V_150 ;
}
return 0 ;
}
static int F_217 ( struct V_63 * V_116 , T_5 V_150 ,
void * V_188 , int V_147 , unsigned long V_187 )
{
int V_28 ;
unsigned long V_153 ;
V_153 = F_169 ( V_116 , V_150 , NULL ) ;
if ( F_158 ( V_153 ) )
return - V_144 ;
F_218 () ;
V_28 = F_219 ( V_188 , ( void V_127 * ) V_153 + V_147 , V_187 ) ;
F_220 () ;
if ( V_28 )
return - V_144 ;
return 0 ;
}
int F_221 ( struct V_9 * V_9 , T_6 V_189 , void * V_188 ,
unsigned long V_187 )
{
T_5 V_150 = V_189 >> V_128 ;
struct V_63 * V_116 = F_151 ( V_9 , V_150 ) ;
int V_147 = F_215 ( V_189 ) ;
return F_217 ( V_116 , V_150 , V_188 , V_147 , V_187 ) ;
}
int F_222 ( struct V_2 * V_3 , T_6 V_189 ,
void * V_188 , unsigned long V_187 )
{
T_5 V_150 = V_189 >> V_128 ;
struct V_63 * V_116 = F_153 ( V_3 , V_150 ) ;
int V_147 = F_215 ( V_189 ) ;
return F_217 ( V_116 , V_150 , V_188 , V_147 , V_187 ) ;
}
static int F_223 ( struct V_63 * V_64 , T_5 V_150 ,
const void * V_188 , int V_147 , int V_187 )
{
int V_28 ;
unsigned long V_153 ;
V_153 = F_167 ( V_64 , V_150 ) ;
if ( F_158 ( V_153 ) )
return - V_144 ;
V_28 = F_224 ( ( void V_127 * ) V_153 + V_147 , V_188 , V_187 ) ;
if ( V_28 )
return - V_144 ;
F_225 ( V_64 , V_150 ) ;
return 0 ;
}
int F_226 ( struct V_9 * V_9 , T_5 V_150 ,
const void * V_188 , int V_147 , int V_187 )
{
struct V_63 * V_116 = F_151 ( V_9 , V_150 ) ;
return F_223 ( V_116 , V_150 , V_188 , V_147 , V_187 ) ;
}
int F_227 ( struct V_2 * V_3 , T_5 V_150 ,
const void * V_188 , int V_147 , int V_187 )
{
struct V_63 * V_116 = F_153 ( V_3 , V_150 ) ;
return F_223 ( V_116 , V_150 , V_188 , V_147 , V_187 ) ;
}
int F_228 ( struct V_9 * V_9 , T_6 V_189 , const void * V_188 ,
unsigned long V_187 )
{
T_5 V_150 = V_189 >> V_128 ;
int V_190 ;
int V_147 = F_215 ( V_189 ) ;
int V_191 ;
while ( ( V_190 = F_209 ( V_187 , V_147 ) ) != 0 ) {
V_191 = F_226 ( V_9 , V_150 , V_188 , V_147 , V_190 ) ;
if ( V_191 < 0 )
return V_191 ;
V_147 = 0 ;
V_187 -= V_190 ;
V_188 += V_190 ;
++ V_150 ;
}
return 0 ;
}
int F_229 ( struct V_2 * V_3 , T_6 V_189 , const void * V_188 ,
unsigned long V_187 )
{
T_5 V_150 = V_189 >> V_128 ;
int V_190 ;
int V_147 = F_215 ( V_189 ) ;
int V_191 ;
while ( ( V_190 = F_209 ( V_187 , V_147 ) ) != 0 ) {
V_191 = F_227 ( V_3 , V_150 , V_188 , V_147 , V_190 ) ;
if ( V_191 < 0 )
return V_191 ;
V_147 = 0 ;
V_187 -= V_190 ;
V_188 += V_190 ;
++ V_150 ;
}
return 0 ;
}
int F_230 ( struct V_9 * V_9 , struct V_192 * V_193 ,
T_6 V_189 , unsigned long V_187 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_147 = F_215 ( V_189 ) ;
T_5 V_194 = V_189 >> V_128 ;
T_5 V_195 = ( V_189 + V_187 - 1 ) >> V_128 ;
T_5 V_196 = V_195 - V_194 + 1 ;
T_5 V_197 ;
V_193 -> V_189 = V_189 ;
V_193 -> V_59 = V_58 -> V_59 ;
V_193 -> V_187 = V_187 ;
V_193 -> V_64 = F_151 ( V_9 , V_194 ) ;
V_193 -> V_160 = F_166 ( V_193 -> V_64 , V_194 , NULL ) ;
if ( ! F_158 ( V_193 -> V_160 ) && V_196 <= 1 ) {
V_193 -> V_160 += V_147 ;
} else {
while ( V_194 <= V_195 ) {
V_193 -> V_64 = F_151 ( V_9 , V_194 ) ;
V_193 -> V_160 = F_166 ( V_193 -> V_64 , V_194 ,
& V_197 ) ;
if ( F_158 ( V_193 -> V_160 ) )
return - V_144 ;
V_194 += V_197 ;
}
V_193 -> V_64 = NULL ;
}
return 0 ;
}
int F_231 ( struct V_9 * V_9 , struct V_192 * V_193 ,
void * V_188 , unsigned long V_187 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_28 ;
F_62 ( V_187 > V_193 -> V_187 ) ;
if ( V_58 -> V_59 != V_193 -> V_59 )
F_230 ( V_9 , V_193 , V_193 -> V_189 , V_193 -> V_187 ) ;
if ( F_25 ( ! V_193 -> V_64 ) )
return F_228 ( V_9 , V_193 -> V_189 , V_188 , V_187 ) ;
if ( F_158 ( V_193 -> V_160 ) )
return - V_144 ;
V_28 = F_224 ( ( void V_127 * ) V_193 -> V_160 , V_188 , V_187 ) ;
if ( V_28 )
return - V_144 ;
F_225 ( V_193 -> V_64 , V_193 -> V_189 >> V_128 ) ;
return 0 ;
}
int F_232 ( struct V_9 * V_9 , struct V_192 * V_193 ,
void * V_188 , unsigned long V_187 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_28 ;
F_62 ( V_187 > V_193 -> V_187 ) ;
if ( V_58 -> V_59 != V_193 -> V_59 )
F_230 ( V_9 , V_193 , V_193 -> V_189 , V_193 -> V_187 ) ;
if ( F_25 ( ! V_193 -> V_64 ) )
return F_214 ( V_9 , V_193 -> V_189 , V_188 , V_187 ) ;
if ( F_158 ( V_193 -> V_160 ) )
return - V_144 ;
V_28 = F_211 ( V_188 , ( void V_127 * ) V_193 -> V_160 , V_187 ) ;
if ( V_28 )
return - V_144 ;
return 0 ;
}
int F_233 ( struct V_9 * V_9 , T_5 V_150 , int V_147 , int V_187 )
{
const void * V_198 = ( const void * ) F_234 ( F_235 ( F_236 ( 0 ) ) ) ;
return F_226 ( V_9 , V_150 , V_198 , V_147 , V_187 ) ;
}
int F_237 ( struct V_9 * V_9 , T_6 V_189 , unsigned long V_187 )
{
T_5 V_150 = V_189 >> V_128 ;
int V_190 ;
int V_147 = F_215 ( V_189 ) ;
int V_191 ;
while ( ( V_190 = F_209 ( V_187 , V_147 ) ) != 0 ) {
V_191 = F_233 ( V_9 , V_150 , V_147 , V_190 ) ;
if ( V_191 < 0 )
return V_191 ;
V_147 = 0 ;
V_187 -= V_190 ;
++ V_150 ;
}
return 0 ;
}
static void F_225 ( struct V_63 * V_64 ,
T_5 V_150 )
{
if ( V_64 && V_64 -> V_65 ) {
unsigned long V_199 = V_150 - V_64 -> V_106 ;
F_238 ( V_199 , V_64 -> V_65 ) ;
}
}
void F_239 ( struct V_9 * V_9 , T_5 V_150 )
{
struct V_63 * V_64 ;
V_64 = F_151 ( V_9 , V_150 ) ;
F_225 ( V_64 , V_150 ) ;
}
void F_240 ( struct V_2 * V_3 , T_5 V_150 )
{
struct V_63 * V_64 ;
V_64 = F_153 ( V_3 , V_150 ) ;
F_225 ( V_64 , V_150 ) ;
}
static int F_241 ( struct V_2 * V_3 )
{
if ( F_242 ( V_3 ) ) {
F_21 ( V_200 , V_3 ) ;
return - V_6 ;
}
if ( F_243 ( V_3 ) )
return - V_6 ;
if ( F_244 ( V_56 ) )
return - V_6 ;
return 0 ;
}
void F_245 ( struct V_2 * V_3 )
{
T_7 V_50 , V_201 ;
F_246 ( V_202 ) ;
bool V_203 = false ;
V_50 = V_201 = F_247 () ;
if ( V_204 ) {
T_7 V_205 = F_248 ( F_247 () , V_204 ) ;
do {
if ( F_241 ( V_3 ) < 0 ) {
++ V_3 -> V_21 . V_206 ;
goto V_120;
}
V_201 = F_247 () ;
} while ( F_249 () && F_250 ( V_201 , V_205 ) );
}
for (; ; ) {
F_251 ( & V_3 -> V_31 , & V_202 , V_207 ) ;
if ( F_241 ( V_3 ) < 0 )
break;
V_203 = true ;
F_252 () ;
}
F_253 ( & V_3 -> V_31 , & V_202 ) ;
V_201 = F_247 () ;
V_120:
F_254 ( F_255 ( V_201 ) - F_255 ( V_50 ) , V_203 ) ;
}
void F_256 ( struct V_2 * V_3 )
{
int V_12 ;
int V_4 = V_3 -> V_4 ;
T_8 * V_208 ;
V_208 = F_257 ( V_3 ) ;
if ( F_258 ( V_208 ) ) {
F_259 ( V_208 ) ;
++ V_3 -> V_21 . V_209 ;
}
V_12 = F_7 () ;
if ( V_4 != V_12 && ( unsigned ) V_4 < V_210 && F_260 ( V_4 ) )
if ( F_261 ( V_3 ) )
F_262 ( V_4 ) ;
F_10 () ;
}
int F_263 ( struct V_2 * V_211 )
{
struct V_30 * V_30 ;
struct V_161 * V_212 = NULL ;
int V_191 = 0 ;
F_264 () ;
V_30 = F_265 ( V_211 -> V_30 ) ;
if ( V_30 )
V_212 = F_266 ( V_30 , V_213 ) ;
F_267 () ;
if ( ! V_212 )
return V_191 ;
V_191 = F_268 ( V_212 , 1 ) ;
F_269 ( V_212 ) ;
return V_191 ;
}
static bool F_270 ( struct V_2 * V_3 )
{
#ifdef F_271
bool V_214 ;
V_214 = ! V_3 -> V_215 . V_216 ||
V_3 -> V_215 . V_217 ;
if ( V_3 -> V_215 . V_216 )
F_41 ( V_3 , ! V_3 -> V_215 . V_217 ) ;
return V_214 ;
#else
return true ;
#endif
}
void F_272 ( struct V_2 * V_12 )
{
struct V_9 * V_9 = V_12 -> V_9 ;
struct V_2 * V_3 ;
int V_218 = V_12 -> V_9 -> V_218 ;
int V_219 = 0 ;
int V_220 = 3 ;
int V_221 ;
int V_11 ;
F_40 ( V_12 , true ) ;
for ( V_221 = 0 ; V_221 < 2 && ! V_219 && V_220 ; V_221 ++ ) {
F_20 (i, vcpu, kvm) {
if ( ! V_221 && V_11 <= V_218 ) {
V_11 = V_218 ;
continue;
} else if ( V_221 && V_11 > V_218 )
break;
if ( ! F_273 ( V_3 -> V_37 ) )
continue;
if ( V_3 == V_12 )
continue;
if ( F_258 ( & V_3 -> V_31 ) && ! F_242 ( V_3 ) )
continue;
if ( ! F_270 ( V_3 ) )
continue;
V_219 = F_263 ( V_3 ) ;
if ( V_219 > 0 ) {
V_9 -> V_218 = V_11 ;
break;
} else if ( V_219 < 0 ) {
V_220 -- ;
if ( ! V_220 )
break;
}
}
}
F_40 ( V_12 , false ) ;
F_41 ( V_12 , false ) ;
}
static int F_274 ( struct V_151 * V_152 , struct V_222 * V_223 )
{
struct V_2 * V_3 = V_152 -> V_224 -> V_101 ;
struct V_27 * V_27 ;
if ( V_223 -> V_225 == 0 )
V_27 = F_275 ( V_3 -> V_36 ) ;
#ifdef F_276
else if ( V_223 -> V_225 == V_226 )
V_27 = F_275 ( V_3 -> V_138 . V_227 ) ;
#endif
#ifdef F_277
else if ( V_223 -> V_225 == F_277 )
V_27 = F_275 ( V_3 -> V_9 -> V_228 ) ;
#endif
else
return F_278 ( V_3 , V_223 ) ;
F_208 ( V_27 ) ;
V_223 -> V_27 = V_27 ;
return 0 ;
}
static int F_279 ( struct V_99 * V_99 , struct V_151 * V_152 )
{
V_152 -> V_229 = & V_230 ;
return 0 ;
}
static int F_280 ( struct V_98 * V_98 , struct V_99 * V_100 )
{
struct V_2 * V_3 = V_100 -> V_101 ;
F_116 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_281 ( struct V_2 * V_3 )
{
return F_282 ( L_1 , & V_231 , V_3 , V_232 | V_233 ) ;
}
static int F_283 ( struct V_9 * V_9 , T_4 V_26 )
{
int V_28 ;
struct V_2 * V_3 , * V_234 ;
if ( V_26 >= V_235 )
return - V_113 ;
V_3 = F_284 ( V_9 , V_26 ) ;
if ( F_285 ( V_3 ) )
return F_286 ( V_3 ) ;
F_287 ( & V_3 -> V_7 , & V_236 ) ;
V_28 = F_288 ( V_3 ) ;
if ( V_28 )
goto V_237;
F_142 ( & V_9 -> V_80 ) ;
if ( ! F_289 ( V_3 ) ) {
V_28 = - V_113 ;
goto V_238;
}
if ( F_290 ( & V_9 -> V_239 ) == V_235 ) {
V_28 = - V_113 ;
goto V_238;
}
F_20 (r, v, kvm)
if ( V_234 -> V_29 == V_26 ) {
V_28 = - V_134 ;
goto V_238;
}
F_62 ( V_9 -> V_240 [ F_290 ( & V_9 -> V_239 ) ] ) ;
F_115 ( V_9 ) ;
V_28 = F_281 ( V_3 ) ;
if ( V_28 < 0 ) {
F_116 ( V_9 ) ;
goto V_238;
}
V_9 -> V_240 [ F_290 ( & V_9 -> V_239 ) ] = V_3 ;
F_61 () ;
F_90 ( & V_9 -> V_239 ) ;
F_16 ( & V_9 -> V_80 ) ;
F_291 ( V_3 ) ;
return V_28 ;
V_238:
F_16 ( & V_9 -> V_80 ) ;
V_237:
F_292 ( V_3 ) ;
return V_28 ;
}
static int F_293 ( struct V_2 * V_3 , T_9 * V_241 )
{
if ( V_241 ) {
F_294 ( V_241 , F_295 ( V_242 ) | F_295 ( V_243 ) ) ;
V_3 -> V_244 = 1 ;
V_3 -> V_241 = * V_241 ;
} else
V_3 -> V_244 = 0 ;
return 0 ;
}
static long F_296 ( struct V_99 * V_100 ,
unsigned int V_245 , unsigned long V_246 )
{
struct V_2 * V_3 = V_100 -> V_101 ;
void V_127 * V_247 = ( void V_127 * ) V_246 ;
int V_28 ;
struct V_248 * V_249 = NULL ;
struct V_250 * V_250 = NULL ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_251 ;
if ( F_25 ( F_297 ( V_245 ) != V_252 ) )
return - V_113 ;
#if F_110 ( V_253 ) || F_110 ( V_254 ) || F_110 ( V_255 )
if ( V_245 == V_256 || V_245 == V_257 || V_245 == V_258 )
return F_298 ( V_100 , V_245 , V_246 ) ;
#endif
V_28 = F_5 ( V_3 ) ;
if ( V_28 )
return V_28 ;
switch ( V_245 ) {
case V_259 :
V_28 = - V_113 ;
if ( V_246 )
goto V_120;
if ( F_25 ( V_3 -> V_30 != V_56 -> V_260 [ V_213 ] . V_30 ) ) {
struct V_30 * V_261 = V_3 -> V_30 ;
struct V_30 * V_262 = F_299 ( V_56 , V_213 ) ;
F_129 ( V_3 -> V_30 , V_262 ) ;
if ( V_261 )
F_300 () ;
F_45 ( V_261 ) ;
}
V_28 = F_301 ( V_3 , V_3 -> V_36 ) ;
F_302 ( V_3 -> V_36 -> V_263 , V_28 ) ;
break;
case V_264 : {
struct V_265 * V_265 ;
V_28 = - V_34 ;
V_265 = F_88 ( sizeof( struct V_265 ) , V_32 ) ;
if ( ! V_265 )
goto V_120;
V_28 = F_303 ( V_3 , V_265 ) ;
if ( V_28 )
goto V_266;
V_28 = - V_144 ;
if ( F_145 ( V_247 , V_265 , sizeof( struct V_265 ) ) )
goto V_266;
V_28 = 0 ;
V_266:
F_98 ( V_265 ) ;
break;
}
case V_267 : {
struct V_265 * V_265 ;
V_28 = - V_34 ;
V_265 = F_304 ( V_247 , sizeof( * V_265 ) ) ;
if ( F_285 ( V_265 ) ) {
V_28 = F_286 ( V_265 ) ;
goto V_120;
}
V_28 = F_305 ( V_3 , V_265 ) ;
F_98 ( V_265 ) ;
break;
}
case V_268 : {
V_250 = F_88 ( sizeof( struct V_250 ) , V_32 ) ;
V_28 = - V_34 ;
if ( ! V_250 )
goto V_120;
V_28 = F_306 ( V_3 , V_250 ) ;
if ( V_28 )
goto V_120;
V_28 = - V_144 ;
if ( F_145 ( V_247 , V_250 , sizeof( struct V_250 ) ) )
goto V_120;
V_28 = 0 ;
break;
}
case V_269 : {
V_250 = F_304 ( V_247 , sizeof( * V_250 ) ) ;
if ( F_285 ( V_250 ) ) {
V_28 = F_286 ( V_250 ) ;
V_250 = NULL ;
goto V_120;
}
V_28 = F_307 ( V_3 , V_250 ) ;
break;
}
case V_270 : {
struct V_271 V_272 ;
V_28 = F_308 ( V_3 , & V_272 ) ;
if ( V_28 )
goto V_120;
V_28 = - V_144 ;
if ( F_145 ( V_247 , & V_272 , sizeof( V_272 ) ) )
goto V_120;
V_28 = 0 ;
break;
}
case V_273 : {
struct V_271 V_272 ;
V_28 = - V_144 ;
if ( F_309 ( & V_272 , V_247 , sizeof( V_272 ) ) )
goto V_120;
V_28 = F_310 ( V_3 , & V_272 ) ;
break;
}
case V_274 : {
struct V_275 V_276 ;
V_28 = - V_144 ;
if ( F_309 ( & V_276 , V_247 , sizeof( V_276 ) ) )
goto V_120;
V_28 = F_311 ( V_3 , & V_276 ) ;
if ( V_28 )
goto V_120;
V_28 = - V_144 ;
if ( F_145 ( V_247 , & V_276 , sizeof( V_276 ) ) )
goto V_120;
V_28 = 0 ;
break;
}
case V_277 : {
struct V_278 V_279 ;
V_28 = - V_144 ;
if ( F_309 ( & V_279 , V_247 , sizeof( V_279 ) ) )
goto V_120;
V_28 = F_312 ( V_3 , & V_279 ) ;
break;
}
case V_280 : {
struct V_281 V_127 * V_282 = V_247 ;
struct V_281 V_283 ;
T_9 V_241 , * V_284 ;
V_284 = NULL ;
if ( V_247 ) {
V_28 = - V_144 ;
if ( F_309 ( & V_283 , V_247 ,
sizeof( V_283 ) ) )
goto V_120;
V_28 = - V_113 ;
if ( V_283 . V_187 != sizeof( V_241 ) )
goto V_120;
V_28 = - V_144 ;
if ( F_309 ( & V_241 , V_282 -> V_241 ,
sizeof( V_241 ) ) )
goto V_120;
V_284 = & V_241 ;
}
V_28 = F_293 ( V_3 , V_284 ) ;
break;
}
case V_285 : {
V_249 = F_88 ( sizeof( struct V_248 ) , V_32 ) ;
V_28 = - V_34 ;
if ( ! V_249 )
goto V_120;
V_28 = F_313 ( V_3 , V_249 ) ;
if ( V_28 )
goto V_120;
V_28 = - V_144 ;
if ( F_145 ( V_247 , V_249 , sizeof( struct V_248 ) ) )
goto V_120;
V_28 = 0 ;
break;
}
case V_286 : {
V_249 = F_304 ( V_247 , sizeof( * V_249 ) ) ;
if ( F_285 ( V_249 ) ) {
V_28 = F_286 ( V_249 ) ;
V_249 = NULL ;
goto V_120;
}
V_28 = F_314 ( V_3 , V_249 ) ;
break;
}
default:
V_28 = F_298 ( V_100 , V_245 , V_246 ) ;
}
V_120:
F_11 ( V_3 ) ;
F_98 ( V_249 ) ;
F_98 ( V_250 ) ;
return V_28 ;
}
static long F_315 ( struct V_99 * V_100 ,
unsigned int V_245 , unsigned long V_246 )
{
struct V_2 * V_3 = V_100 -> V_101 ;
void V_127 * V_247 = F_316 ( V_246 ) ;
int V_28 ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_251 ;
switch ( V_245 ) {
case V_280 : {
struct V_281 V_127 * V_282 = V_247 ;
struct V_281 V_283 ;
T_10 V_287 ;
T_9 V_241 ;
if ( V_247 ) {
V_28 = - V_144 ;
if ( F_309 ( & V_283 , V_247 ,
sizeof( V_283 ) ) )
goto V_120;
V_28 = - V_113 ;
if ( V_283 . V_187 != sizeof( V_287 ) )
goto V_120;
V_28 = - V_144 ;
if ( F_309 ( & V_287 , V_282 -> V_241 ,
sizeof( V_287 ) ) )
goto V_120;
F_317 ( & V_241 , & V_287 ) ;
V_28 = F_293 ( V_3 , & V_241 ) ;
} else
V_28 = F_293 ( V_3 , NULL ) ;
break;
}
default:
V_28 = F_296 ( V_100 , V_245 , V_246 ) ;
}
V_120:
return V_28 ;
}
static int F_318 ( struct V_92 * V_93 ,
int (* F_319)( struct V_92 * V_93 ,
struct V_288 * V_289 ) ,
unsigned long V_246 )
{
struct V_288 V_289 ;
if ( ! F_319 )
return - V_290 ;
if ( F_309 ( & V_289 , ( void V_127 * ) V_246 , sizeof( V_289 ) ) )
return - V_144 ;
return F_319 ( V_93 , & V_289 ) ;
}
static long F_320 ( struct V_99 * V_100 , unsigned int V_245 ,
unsigned long V_246 )
{
struct V_92 * V_93 = V_100 -> V_101 ;
switch ( V_245 ) {
case V_291 :
return F_318 ( V_93 , V_93 -> V_54 -> V_292 , V_246 ) ;
case V_293 :
return F_318 ( V_93 , V_93 -> V_54 -> V_294 , V_246 ) ;
case V_295 :
return F_318 ( V_93 , V_93 -> V_54 -> V_296 , V_246 ) ;
default:
if ( V_93 -> V_54 -> V_245 )
return V_93 -> V_54 -> V_245 ( V_93 , V_245 , V_246 ) ;
return - V_297 ;
}
}
static int F_321 ( struct V_98 * V_98 , struct V_99 * V_100 )
{
struct V_92 * V_93 = V_100 -> V_101 ;
struct V_9 * V_9 = V_93 -> V_9 ;
F_116 ( V_9 ) ;
return 0 ;
}
struct V_92 * F_322 ( struct V_99 * V_100 )
{
if ( V_100 -> V_298 != & V_299 )
return NULL ;
return V_100 -> V_101 ;
}
int F_323 ( struct V_300 * V_54 , T_4 type )
{
if ( type >= F_324 ( V_301 ) )
return - V_302 ;
if ( V_301 [ type ] != NULL )
return - V_134 ;
V_301 [ type ] = V_54 ;
return 0 ;
}
void F_325 ( T_4 type )
{
if ( V_301 [ type ] != NULL )
V_301 [ type ] = NULL ;
}
static int F_326 ( struct V_9 * V_9 ,
struct V_303 * V_304 )
{
struct V_300 * V_54 = NULL ;
struct V_92 * V_93 ;
bool V_305 = V_304 -> V_112 & V_306 ;
int V_191 ;
if ( V_304 -> type >= F_324 ( V_301 ) )
return - V_307 ;
V_54 = V_301 [ V_304 -> type ] ;
if ( V_54 == NULL )
return - V_307 ;
if ( V_305 )
return 0 ;
V_93 = F_88 ( sizeof( * V_93 ) , V_32 ) ;
if ( ! V_93 )
return - V_34 ;
V_93 -> V_54 = V_54 ;
V_93 -> V_9 = V_9 ;
V_191 = V_54 -> V_308 ( V_93 , V_304 -> type ) ;
if ( V_191 < 0 ) {
F_98 ( V_93 ) ;
return V_191 ;
}
V_191 = F_282 ( V_54 -> V_309 , & V_299 , V_93 , V_232 | V_233 ) ;
if ( V_191 < 0 ) {
V_54 -> V_95 ( V_93 ) ;
return V_191 ;
}
F_94 ( & V_93 -> V_94 , & V_9 -> V_84 ) ;
F_115 ( V_9 ) ;
V_304 -> V_310 = V_191 ;
return 0 ;
}
static long F_327 ( struct V_9 * V_9 , long V_246 )
{
switch ( V_246 ) {
case V_311 :
case V_312 :
case V_313 :
#ifdef F_328
case V_314 :
#endif
case V_315 :
#ifdef F_329
case V_316 :
#endif
#ifdef F_84
case V_317 :
case V_318 :
#endif
case V_319 :
return 1 ;
#ifdef F_330
case V_320 :
return V_321 ;
#endif
#if V_71 > 1
case V_322 :
return V_71 ;
#endif
default:
break;
}
return F_331 ( V_9 , V_246 ) ;
}
static long F_332 ( struct V_99 * V_100 ,
unsigned int V_245 , unsigned long V_246 )
{
struct V_9 * V_9 = V_100 -> V_101 ;
void V_127 * V_247 = ( void V_127 * ) V_246 ;
int V_28 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_251 ;
switch ( V_245 ) {
case V_323 :
V_28 = F_283 ( V_9 , V_246 ) ;
break;
case V_324 : {
struct V_107 V_325 ;
V_28 = - V_144 ;
if ( F_309 ( & V_325 , V_247 ,
sizeof( V_325 ) ) )
goto V_120;
V_28 = F_143 ( V_9 , & V_325 ) ;
break;
}
case V_326 : {
struct V_139 log ;
V_28 = - V_144 ;
if ( F_309 ( & log , V_247 , sizeof( log ) ) )
goto V_120;
V_28 = F_333 ( V_9 , & log ) ;
break;
}
#ifdef F_277
case V_327 : {
struct V_328 V_329 ;
V_28 = - V_144 ;
if ( F_309 ( & V_329 , V_247 , sizeof( V_329 ) ) )
goto V_120;
V_28 = F_334 ( V_9 , & V_329 ) ;
break;
}
case V_330 : {
struct V_328 V_329 ;
V_28 = - V_144 ;
if ( F_309 ( & V_329 , V_247 , sizeof( V_329 ) ) )
goto V_120;
V_28 = F_335 ( V_9 , & V_329 ) ;
break;
}
#endif
case V_331 : {
struct V_332 V_188 ;
V_28 = - V_144 ;
if ( F_309 ( & V_188 , V_247 , sizeof( V_188 ) ) )
goto V_120;
V_28 = V_332 ( V_9 , & V_188 ) ;
break;
}
case V_333 : {
struct V_334 V_188 ;
V_28 = - V_144 ;
if ( F_309 ( & V_188 , V_247 , sizeof( V_188 ) ) )
goto V_120;
V_28 = V_334 ( V_9 , & V_188 ) ;
break;
}
#ifdef F_328
case V_335 :
V_28 = 0 ;
F_142 ( & V_9 -> V_80 ) ;
if ( F_290 ( & V_9 -> V_239 ) != 0 )
V_28 = - V_336 ;
else
V_9 -> V_337 = V_246 ;
F_16 ( & V_9 -> V_80 ) ;
break;
#endif
#ifdef F_329
case V_338 : {
struct V_339 V_340 ;
V_28 = - V_144 ;
if ( F_309 ( & V_340 , V_247 , sizeof( V_340 ) ) )
goto V_120;
V_28 = F_336 ( V_9 , & V_340 ) ;
break;
}
#endif
#ifdef F_337
case V_341 :
case V_342 : {
struct V_343 V_344 ;
V_28 = - V_144 ;
if ( F_309 ( & V_344 , V_247 , sizeof( V_344 ) ) )
goto V_120;
V_28 = F_338 ( V_9 , & V_344 ,
V_245 == V_341 ) ;
if ( V_28 )
goto V_120;
V_28 = - V_144 ;
if ( V_245 == V_341 ) {
if ( F_145 ( V_247 , & V_344 , sizeof( V_344 ) ) )
goto V_120;
}
V_28 = 0 ;
break;
}
#endif
#ifdef F_330
case V_345 : {
struct V_346 V_347 ;
struct V_346 V_127 * V_348 ;
struct V_349 * V_350 ;
V_28 = - V_144 ;
if ( F_309 ( & V_347 , V_247 , sizeof( V_347 ) ) )
goto V_120;
V_28 = - V_113 ;
if ( V_347 . V_351 >= V_321 )
goto V_120;
if ( V_347 . V_112 )
goto V_120;
V_28 = - V_34 ;
V_350 = F_339 ( V_347 . V_351 * sizeof( * V_350 ) ) ;
if ( ! V_350 )
goto V_120;
V_28 = - V_144 ;
V_348 = V_247 ;
if ( F_309 ( V_350 , V_348 -> V_350 ,
V_347 . V_351 * sizeof( * V_350 ) ) )
goto V_352;
V_28 = F_340 ( V_9 , V_350 , V_347 . V_351 ,
V_347 . V_112 ) ;
V_352:
F_341 ( V_350 ) ;
break;
}
#endif
case V_353 : {
struct V_303 V_304 ;
V_28 = - V_144 ;
if ( F_309 ( & V_304 , V_247 , sizeof( V_304 ) ) )
goto V_120;
V_28 = F_326 ( V_9 , & V_304 ) ;
if ( V_28 )
goto V_120;
V_28 = - V_144 ;
if ( F_145 ( V_247 , & V_304 , sizeof( V_304 ) ) )
goto V_120;
V_28 = 0 ;
break;
}
case V_354 :
V_28 = F_327 ( V_9 , V_246 ) ;
break;
default:
V_28 = F_342 ( V_100 , V_245 , V_246 ) ;
}
V_120:
return V_28 ;
}
static long F_343 ( struct V_99 * V_100 ,
unsigned int V_245 , unsigned long V_246 )
{
struct V_9 * V_9 = V_100 -> V_101 ;
int V_28 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_251 ;
switch ( V_245 ) {
case V_326 : {
struct V_355 V_356 ;
struct V_139 log ;
V_28 = - V_144 ;
if ( F_309 ( & V_356 , ( void V_127 * ) V_246 ,
sizeof( V_356 ) ) )
goto V_120;
log . V_116 = V_356 . V_116 ;
log . V_357 = V_356 . V_357 ;
log . V_358 = V_356 . V_358 ;
log . V_65 = F_316 ( V_356 . V_65 ) ;
V_28 = F_333 ( V_9 , & log ) ;
break;
}
default:
V_28 = F_332 ( V_100 , V_245 , V_246 ) ;
}
V_120:
return V_28 ;
}
static int F_344 ( unsigned long type )
{
int V_28 ;
struct V_9 * V_9 ;
V_9 = F_79 ( type ) ;
if ( F_285 ( V_9 ) )
return F_286 ( V_9 ) ;
#ifdef F_277
V_28 = F_345 ( V_9 ) ;
if ( V_28 < 0 ) {
F_116 ( V_9 ) ;
return V_28 ;
}
#endif
V_28 = F_282 ( L_2 , & V_359 , V_9 , V_232 | V_233 ) ;
if ( V_28 < 0 )
F_116 ( V_9 ) ;
return V_28 ;
}
static long F_346 ( struct V_99 * V_100 ,
unsigned int V_245 , unsigned long V_246 )
{
long V_28 = - V_113 ;
switch ( V_245 ) {
case V_360 :
if ( V_246 )
goto V_120;
V_28 = V_361 ;
break;
case V_362 :
V_28 = F_344 ( V_246 ) ;
break;
case V_354 :
V_28 = F_327 ( NULL , V_246 ) ;
break;
case V_363 :
if ( V_246 )
goto V_120;
V_28 = V_88 ;
#ifdef F_276
V_28 += V_88 ;
#endif
#ifdef F_277
V_28 += V_88 ;
#endif
break;
case V_364 :
case V_365 :
case V_366 :
V_28 = - V_367 ;
break;
default:
return F_347 ( V_100 , V_245 , V_246 ) ;
}
V_120:
return V_28 ;
}
static void F_348 ( void * V_368 )
{
int V_4 = F_349 () ;
int V_28 ;
if ( F_350 ( V_4 , V_369 ) )
return;
F_24 ( V_4 , V_369 ) ;
V_28 = F_351 () ;
if ( V_28 ) {
F_352 ( V_4 , V_369 ) ;
F_90 ( & V_370 ) ;
F_353 ( L_3 , V_4 ) ;
}
}
static void F_354 ( void )
{
F_355 ( & V_371 ) ;
if ( V_372 )
F_348 ( NULL ) ;
F_356 ( & V_371 ) ;
}
static void F_357 ( void * V_368 )
{
int V_4 = F_349 () ;
if ( ! F_350 ( V_4 , V_369 ) )
return;
F_352 ( V_4 , V_369 ) ;
F_358 () ;
}
static void F_359 ( void )
{
F_355 ( & V_371 ) ;
if ( V_372 )
F_357 ( NULL ) ;
F_356 ( & V_371 ) ;
}
static void F_360 ( void )
{
F_62 ( ! V_372 ) ;
V_372 -- ;
if ( ! V_372 )
F_361 ( F_357 , NULL , 1 ) ;
}
static void F_97 ( void )
{
F_355 ( & V_371 ) ;
F_360 () ;
F_356 ( & V_371 ) ;
}
static int F_83 ( void )
{
int V_28 = 0 ;
F_355 ( & V_371 ) ;
V_372 ++ ;
if ( V_372 == 1 ) {
F_92 ( & V_370 , 0 ) ;
F_361 ( F_348 , NULL , 1 ) ;
if ( F_290 ( & V_370 ) ) {
F_360 () ;
V_28 = - V_336 ;
}
}
F_356 ( & V_371 ) ;
return V_28 ;
}
static int F_362 ( struct V_373 * V_374 , unsigned long V_375 ,
void * V_234 )
{
V_375 &= ~ V_376 ;
switch ( V_375 ) {
case V_377 :
F_359 () ;
break;
case V_378 :
F_354 () ;
break;
}
return V_379 ;
}
static int F_363 ( struct V_373 * V_374 , unsigned long V_375 ,
void * V_234 )
{
F_353 ( L_4 ) ;
V_380 = true ;
F_361 ( F_357 , NULL , 1 ) ;
return V_379 ;
}
static void F_108 ( struct V_77 * V_381 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_381 -> V_382 ; V_11 ++ ) {
struct V_383 * V_384 = V_381 -> V_385 [ V_11 ] . V_93 ;
F_364 ( V_384 ) ;
}
F_98 ( V_381 ) ;
}
static inline int F_365 ( const struct V_386 * V_387 ,
const struct V_386 * V_388 )
{
if ( V_387 -> V_153 < V_388 -> V_153 )
return - 1 ;
if ( V_387 -> V_153 + V_387 -> V_187 > V_388 -> V_153 + V_388 -> V_187 )
return 1 ;
return 0 ;
}
static int F_366 ( const void * V_389 , const void * V_390 )
{
return F_365 ( V_389 , V_390 ) ;
}
static int F_367 ( struct V_77 * V_381 , struct V_383 * V_93 ,
T_6 V_153 , int V_187 )
{
V_381 -> V_385 [ V_381 -> V_382 ++ ] = (struct V_386 ) {
. V_153 = V_153 ,
. V_187 = V_187 ,
. V_93 = V_93 ,
} ;
F_368 ( V_381 -> V_385 , V_381 -> V_382 , sizeof( struct V_386 ) ,
F_366 , NULL ) ;
return 0 ;
}
static int F_369 ( struct V_77 * V_381 ,
T_6 V_153 , int V_187 )
{
struct V_386 * V_385 , V_391 ;
int V_392 ;
V_391 = (struct V_386 ) {
. V_153 = V_153 ,
. V_187 = V_187 ,
} ;
V_385 = bsearch ( & V_391 , V_381 -> V_385 , V_381 -> V_382 ,
sizeof( struct V_386 ) , F_366 ) ;
if ( V_385 == NULL )
return - V_143 ;
V_392 = V_385 - V_381 -> V_385 ;
while ( V_392 > 0 && F_365 ( & V_391 , & V_381 -> V_385 [ V_392 - 1 ] ) == 0 )
V_392 -- ;
return V_392 ;
}
static int F_370 ( struct V_2 * V_3 , struct V_77 * V_381 ,
struct V_386 * V_385 , const void * V_375 )
{
int V_45 ;
V_45 = F_369 ( V_381 , V_385 -> V_153 , V_385 -> V_187 ) ;
if ( V_45 < 0 )
return - V_367 ;
while ( V_45 < V_381 -> V_382 &&
F_365 ( V_385 , & V_381 -> V_385 [ V_45 ] ) == 0 ) {
if ( ! F_371 ( V_3 , V_381 -> V_385 [ V_45 ] . V_93 , V_385 -> V_153 ,
V_385 -> V_187 , V_375 ) )
return V_45 ;
V_45 ++ ;
}
return - V_367 ;
}
int F_372 ( struct V_2 * V_3 , enum V_393 V_394 , T_6 V_153 ,
int V_187 , const void * V_375 )
{
struct V_77 * V_381 ;
struct V_386 V_385 ;
int V_28 ;
V_385 = (struct V_386 ) {
. V_153 = V_153 ,
. V_187 = V_187 ,
} ;
V_381 = F_373 ( V_3 -> V_9 -> V_76 [ V_394 ] , & V_3 -> V_9 -> V_46 ) ;
V_28 = F_370 ( V_3 , V_381 , & V_385 , V_375 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
int F_374 ( struct V_2 * V_3 , enum V_393 V_394 ,
T_6 V_153 , int V_187 , const void * V_375 , long V_395 )
{
struct V_77 * V_381 ;
struct V_386 V_385 ;
V_385 = (struct V_386 ) {
. V_153 = V_153 ,
. V_187 = V_187 ,
} ;
V_381 = F_373 ( V_3 -> V_9 -> V_76 [ V_394 ] , & V_3 -> V_9 -> V_46 ) ;
if ( ( V_395 >= 0 ) && ( V_395 < V_381 -> V_382 ) &&
( F_365 ( & V_385 , & V_381 -> V_385 [ V_395 ] ) == 0 ) )
if ( ! F_371 ( V_3 , V_381 -> V_385 [ V_395 ] . V_93 , V_153 , V_187 ,
V_375 ) )
return V_395 ;
return F_370 ( V_3 , V_381 , & V_385 , V_375 ) ;
}
static int F_375 ( struct V_2 * V_3 , struct V_77 * V_381 ,
struct V_386 * V_385 , void * V_375 )
{
int V_45 ;
V_45 = F_369 ( V_381 , V_385 -> V_153 , V_385 -> V_187 ) ;
if ( V_45 < 0 )
return - V_367 ;
while ( V_45 < V_381 -> V_382 &&
F_365 ( V_385 , & V_381 -> V_385 [ V_45 ] ) == 0 ) {
if ( ! F_376 ( V_3 , V_381 -> V_385 [ V_45 ] . V_93 , V_385 -> V_153 ,
V_385 -> V_187 , V_375 ) )
return V_45 ;
V_45 ++ ;
}
return - V_367 ;
}
int F_377 ( struct V_2 * V_3 , enum V_393 V_394 , T_6 V_153 ,
int V_187 , void * V_375 )
{
struct V_77 * V_381 ;
struct V_386 V_385 ;
int V_28 ;
V_385 = (struct V_386 ) {
. V_153 = V_153 ,
. V_187 = V_187 ,
} ;
V_381 = F_373 ( V_3 -> V_9 -> V_76 [ V_394 ] , & V_3 -> V_9 -> V_46 ) ;
V_28 = F_375 ( V_3 , V_381 , & V_385 , V_375 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
int F_378 ( struct V_9 * V_9 , enum V_393 V_394 , T_6 V_153 ,
int V_187 , struct V_383 * V_93 )
{
struct V_77 * V_396 , * V_381 ;
V_381 = V_9 -> V_76 [ V_394 ] ;
if ( V_381 -> V_382 - V_381 -> V_397 > V_398 - 1 )
return - V_302 ;
V_396 = F_88 ( sizeof( * V_381 ) + ( ( V_381 -> V_382 + 1 ) *
sizeof( struct V_386 ) ) , V_32 ) ;
if ( ! V_396 )
return - V_34 ;
memcpy ( V_396 , V_381 , sizeof( * V_381 ) + ( V_381 -> V_382 *
sizeof( struct V_386 ) ) ) ;
F_367 ( V_396 , V_93 , V_153 , V_187 ) ;
F_129 ( V_9 -> V_76 [ V_394 ] , V_396 ) ;
F_130 ( & V_9 -> V_46 ) ;
F_98 ( V_381 ) ;
return 0 ;
}
int F_379 ( struct V_9 * V_9 , enum V_393 V_394 ,
struct V_383 * V_93 )
{
int V_11 , V_28 ;
struct V_77 * V_396 , * V_381 ;
V_381 = V_9 -> V_76 [ V_394 ] ;
V_28 = - V_143 ;
for ( V_11 = 0 ; V_11 < V_381 -> V_382 ; V_11 ++ )
if ( V_381 -> V_385 [ V_11 ] . V_93 == V_93 ) {
V_28 = 0 ;
break;
}
if ( V_28 )
return V_28 ;
V_396 = F_88 ( sizeof( * V_381 ) + ( ( V_381 -> V_382 - 1 ) *
sizeof( struct V_386 ) ) , V_32 ) ;
if ( ! V_396 )
return - V_34 ;
memcpy ( V_396 , V_381 , sizeof( * V_381 ) + V_11 * sizeof( struct V_386 ) ) ;
V_396 -> V_382 -- ;
memcpy ( V_396 -> V_385 + V_11 , V_381 -> V_385 + V_11 + 1 ,
( V_396 -> V_382 - V_11 ) * sizeof( struct V_386 ) ) ;
F_129 ( V_9 -> V_76 [ V_394 ] , V_396 ) ;
F_130 ( & V_9 -> V_46 ) ;
F_98 ( V_381 ) ;
return V_28 ;
}
static int F_380 ( void * V_399 , T_11 * V_375 )
{
unsigned V_147 = ( long ) V_399 ;
struct V_9 * V_9 ;
* V_375 = 0 ;
F_51 ( & V_85 ) ;
F_381 ( V_9 , & V_86 , V_86 )
* V_375 += * ( T_4 * ) ( ( void * ) V_9 + V_147 ) ;
F_53 ( & V_85 ) ;
return 0 ;
}
static int F_382 ( void * V_399 , T_11 * V_375 )
{
unsigned V_147 = ( long ) V_399 ;
struct V_9 * V_9 ;
struct V_2 * V_3 ;
int V_11 ;
* V_375 = 0 ;
F_51 ( & V_85 ) ;
F_381 (kvm, &vm_list, vm_list)
F_20 ( V_11 , V_3 , V_9 )
* V_375 += * ( T_4 * ) ( ( void * ) V_3 + V_147 ) ;
F_53 ( & V_85 ) ;
return 0 ;
}
static int F_383 ( void )
{
int V_28 = - V_134 ;
struct V_400 * V_284 ;
V_401 = F_384 ( L_5 , NULL ) ;
if ( V_401 == NULL )
goto V_120;
for ( V_284 = V_402 ; V_284 -> V_309 ; ++ V_284 ) {
V_284 -> V_403 = F_385 ( V_284 -> V_309 , 0444 , V_401 ,
( void * ) ( long ) V_284 -> V_147 ,
V_404 [ V_284 -> V_405 ] ) ;
if ( V_284 -> V_403 == NULL )
goto V_406;
}
return 0 ;
V_406:
F_386 ( V_401 ) ;
V_120:
return V_28 ;
}
static void F_387 ( void )
{
struct V_400 * V_284 ;
for ( V_284 = V_402 ; V_284 -> V_309 ; ++ V_284 )
F_388 ( V_284 -> V_403 ) ;
F_388 ( V_401 ) ;
}
static int F_389 ( void )
{
if ( V_372 )
F_357 ( NULL ) ;
return 0 ;
}
static void F_390 ( void )
{
if ( V_372 ) {
F_123 ( F_391 ( & V_371 ) ) ;
F_348 ( NULL ) ;
}
}
static inline
struct V_2 * F_392 ( struct V_7 * V_407 )
{
return F_48 ( V_407 , struct V_2 , V_7 ) ;
}
static void F_393 ( struct V_7 * V_407 , int V_4 )
{
struct V_2 * V_3 = F_392 ( V_407 ) ;
if ( V_3 -> V_37 )
V_3 -> V_37 = false ;
F_394 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_395 ( struct V_7 * V_407 ,
struct V_161 * V_408 )
{
struct V_2 * V_3 = F_392 ( V_407 ) ;
if ( V_56 -> V_409 == V_410 )
V_3 -> V_37 = true ;
F_13 ( V_3 ) ;
}
int F_396 ( void * V_411 , unsigned V_412 , unsigned V_413 ,
struct V_414 * V_414 )
{
int V_28 ;
int V_4 ;
V_28 = F_397 ( V_411 ) ;
if ( V_28 )
goto V_415;
V_28 = F_398 () ;
if ( V_28 )
goto V_416;
if ( ! F_19 ( & V_369 , V_32 ) ) {
V_28 = - V_34 ;
goto V_417;
}
V_28 = F_399 () ;
if ( V_28 < 0 )
goto V_418;
F_400 (cpu) {
F_401 ( V_4 ,
V_419 ,
& V_28 , 1 ) ;
if ( V_28 < 0 )
goto V_420;
}
V_28 = F_402 ( & V_421 ) ;
if ( V_28 )
goto V_422;
F_403 ( & V_423 ) ;
if ( ! V_413 )
V_413 = F_404 ( struct V_2 ) ;
V_424 = F_405 ( L_6 , V_412 , V_413 ,
0 , NULL ) ;
if ( ! V_424 ) {
V_28 = - V_34 ;
goto V_425;
}
V_28 = F_406 () ;
if ( V_28 )
goto V_135;
V_426 . V_427 = V_414 ;
V_359 . V_427 = V_414 ;
V_231 . V_427 = V_414 ;
V_28 = F_407 ( & V_428 ) ;
if ( V_28 ) {
F_408 ( L_7 ) ;
goto V_429;
}
F_409 ( & V_430 ) ;
V_236 . V_431 = F_393 ;
V_236 . V_432 = F_395 ;
V_28 = F_383 () ;
if ( V_28 ) {
F_408 ( L_8 ) ;
goto V_433;
}
V_28 = F_410 () ;
F_123 ( V_28 ) ;
return 0 ;
V_433:
F_411 ( & V_430 ) ;
F_412 ( & V_428 ) ;
V_429:
F_413 () ;
V_135:
F_414 ( V_424 ) ;
V_425:
F_415 ( & V_423 ) ;
F_416 ( & V_421 ) ;
V_422:
V_420:
F_417 () ;
V_418:
F_28 ( V_369 ) ;
V_417:
F_418 () ;
V_416:
F_419 () ;
V_415:
return V_28 ;
}
void F_420 ( void )
{
F_387 () ;
F_412 ( & V_428 ) ;
F_414 ( V_424 ) ;
F_413 () ;
F_411 ( & V_430 ) ;
F_415 ( & V_423 ) ;
F_416 ( & V_421 ) ;
F_361 ( F_357 , NULL , 1 ) ;
F_417 () ;
F_419 () ;
F_418 () ;
F_28 ( V_369 ) ;
F_421 () ;
}
