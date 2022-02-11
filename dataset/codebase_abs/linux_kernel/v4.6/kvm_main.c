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
long V_18 = F_30 ( & V_9 -> V_19 ) ;
if ( F_18 ( V_9 , V_20 ) )
++ V_9 -> V_21 . V_22 ;
F_31 ( & V_9 -> V_19 , V_18 , 0 ) ;
}
void F_32 ( struct V_9 * V_9 )
{
F_18 ( V_9 , V_23 ) ;
}
int F_33 ( struct V_2 * V_3 , struct V_9 * V_9 , unsigned V_24 )
{
struct V_25 * V_25 ;
int V_26 ;
F_34 ( & V_3 -> V_5 ) ;
V_3 -> V_4 = - 1 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_27 = V_24 ;
V_3 -> V_28 = NULL ;
F_35 ( & V_3 -> V_29 ) ;
F_36 ( V_3 ) ;
V_3 -> V_30 = - 1 ;
F_37 ( & V_3 -> V_31 ) ;
V_25 = F_38 ( V_32 | V_33 ) ;
if ( ! V_25 ) {
V_26 = - V_34 ;
goto V_35;
}
V_3 -> V_36 = F_39 ( V_25 ) ;
F_40 ( V_3 , false ) ;
F_41 ( V_3 , false ) ;
V_3 -> V_37 = false ;
V_26 = F_42 ( V_3 ) ;
if ( V_26 < 0 )
goto V_38;
return 0 ;
V_38:
F_43 ( ( unsigned long ) V_3 -> V_36 ) ;
V_35:
return V_26 ;
}
void F_44 ( struct V_2 * V_3 )
{
F_45 ( V_3 -> V_28 ) ;
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
unsigned long V_50 ,
unsigned long V_51 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_53 , V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_53 = F_64 ( V_9 , V_50 , V_51 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
return V_53 ;
}
static int F_66 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_43 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_53 , V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_53 = F_67 ( V_9 , V_43 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
return V_53 ;
}
static void F_68 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_69 ( V_9 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
}
static int F_70 ( struct V_9 * V_9 )
{
V_9 -> V_39 . V_54 = & V_55 ;
return F_71 ( & V_9 -> V_39 , V_56 -> V_42 ) ;
}
static int F_70 ( struct V_9 * V_9 )
{
return 0 ;
}
static struct V_57 * F_72 ( void )
{
int V_11 ;
struct V_57 * V_58 ;
V_58 = F_73 ( sizeof( struct V_57 ) ) ;
if ( ! V_58 )
return NULL ;
V_58 -> V_59 = - 150 ;
for ( V_11 = 0 ; V_11 < V_60 ; V_11 ++ )
V_58 -> V_61 [ V_11 ] = V_58 -> V_62 [ V_11 ] . V_24 = V_11 ;
return V_58 ;
}
static void F_74 ( struct V_63 * V_64 )
{
if ( ! V_64 -> V_65 )
return;
F_75 ( V_64 -> V_65 ) ;
V_64 -> V_65 = NULL ;
}
static void F_76 ( struct V_9 * V_9 , struct V_63 * free ,
struct V_63 * V_66 )
{
if ( ! V_66 || free -> V_65 != V_66 -> V_65 )
F_74 ( free ) ;
F_77 ( V_9 , free , V_66 ) ;
free -> V_67 = 0 ;
}
static void F_78 ( struct V_9 * V_9 , struct V_57 * V_58 )
{
struct V_63 * V_64 ;
if ( ! V_58 )
return;
F_79 (memslot, slots)
F_76 ( V_9 , V_64 , NULL ) ;
F_75 ( V_58 ) ;
}
static struct V_9 * F_80 ( unsigned long type )
{
int V_26 , V_11 ;
struct V_9 * V_9 = F_81 () ;
if ( ! V_9 )
return F_82 ( - V_34 ) ;
F_83 ( & V_9 -> V_47 ) ;
F_84 ( & V_56 -> V_42 -> V_68 ) ;
V_9 -> V_42 = V_56 -> V_42 ;
F_85 ( V_9 ) ;
F_34 ( & V_9 -> V_69 ) ;
F_34 ( & V_9 -> V_70 ) ;
F_34 ( & V_9 -> V_71 ) ;
F_86 ( & V_9 -> V_72 , 1 ) ;
F_37 ( & V_9 -> V_73 ) ;
V_26 = F_87 ( V_9 , type ) ;
if ( V_26 )
goto V_74;
V_26 = F_88 () ;
if ( V_26 )
goto V_74;
#ifdef F_89
F_90 ( & V_9 -> V_75 ) ;
#endif
F_91 ( V_60 > V_76 ) ;
V_26 = - V_34 ;
for ( V_11 = 0 ; V_11 < V_77 ; V_11 ++ ) {
V_9 -> V_62 [ V_11 ] = F_72 () ;
if ( ! V_9 -> V_62 [ V_11 ] )
goto V_78;
}
if ( F_92 ( & V_9 -> V_46 ) )
goto V_78;
if ( F_92 ( & V_9 -> V_79 ) )
goto V_80;
for ( V_11 = 0 ; V_11 < V_81 ; V_11 ++ ) {
V_9 -> V_82 [ V_11 ] = F_93 ( sizeof( struct V_83 ) ,
V_32 ) ;
if ( ! V_9 -> V_82 [ V_11 ] )
goto V_84;
}
V_26 = F_70 ( V_9 ) ;
if ( V_26 )
goto V_84;
F_51 ( & V_85 ) ;
F_94 ( & V_9 -> V_86 , & V_86 ) ;
F_53 ( & V_85 ) ;
F_95 () ;
return V_9 ;
V_84:
F_96 ( & V_9 -> V_79 ) ;
V_80:
F_96 ( & V_9 -> V_46 ) ;
V_78:
F_97 () ;
V_74:
for ( V_11 = 0 ; V_11 < V_81 ; V_11 ++ )
F_98 ( V_9 -> V_82 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < V_77 ; V_11 ++ )
F_78 ( V_9 , V_9 -> V_62 [ V_11 ] ) ;
F_99 ( V_9 ) ;
F_100 ( V_56 -> V_42 ) ;
return F_82 ( V_26 ) ;
}
void * F_73 ( unsigned long V_87 )
{
if ( V_87 > V_88 )
return F_101 ( V_87 ) ;
else
return F_93 ( V_87 , V_32 ) ;
}
static void F_102 ( struct V_9 * V_9 )
{
struct V_89 * V_90 , * V_91 ;
F_103 (dev, tmp, &kvm->devices, vm_node) {
F_104 ( & V_90 -> V_92 ) ;
V_90 -> V_54 -> V_93 ( V_90 ) ;
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
for ( V_11 = 0 ; V_11 < V_81 ; V_11 ++ )
F_108 ( V_9 -> V_82 [ V_11 ] ) ;
F_109 ( V_9 ) ;
#if F_110 ( V_94 ) && F_110 ( V_95 )
F_111 ( & V_9 -> V_39 , V_9 -> V_42 ) ;
#else
F_69 ( V_9 ) ;
#endif
F_112 ( V_9 ) ;
F_102 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_77 ; V_11 ++ )
F_78 ( V_9 , V_9 -> V_62 [ V_11 ] ) ;
F_96 ( & V_9 -> V_79 ) ;
F_96 ( & V_9 -> V_46 ) ;
F_99 ( V_9 ) ;
F_113 () ;
F_97 () ;
F_100 ( V_42 ) ;
}
void F_114 ( struct V_9 * V_9 )
{
F_84 ( & V_9 -> V_72 ) ;
}
void F_115 ( struct V_9 * V_9 )
{
if ( F_116 ( & V_9 -> V_72 ) )
F_105 ( V_9 ) ;
}
static int F_117 ( struct V_96 * V_96 , struct V_97 * V_98 )
{
struct V_9 * V_9 = V_98 -> V_99 ;
F_118 ( V_9 ) ;
F_115 ( V_9 ) ;
return 0 ;
}
static int F_119 ( struct V_63 * V_64 )
{
unsigned long V_100 = 2 * F_120 ( V_64 ) ;
V_64 -> V_65 = F_73 ( V_100 ) ;
if ( ! V_64 -> V_65 )
return - V_34 ;
return 0 ;
}
static void F_121 ( struct V_57 * V_58 ,
struct V_63 * V_101 )
{
int V_24 = V_101 -> V_24 ;
int V_11 = V_58 -> V_61 [ V_24 ] ;
struct V_63 * V_102 = V_58 -> V_62 ;
F_122 ( V_102 [ V_11 ] . V_24 != V_24 ) ;
if ( ! V_101 -> V_67 ) {
F_122 ( ! V_102 [ V_11 ] . V_67 ) ;
if ( V_102 [ V_11 ] . V_67 )
V_58 -> V_103 -- ;
} else {
if ( ! V_102 [ V_11 ] . V_67 )
V_58 -> V_103 ++ ;
}
while ( V_11 < V_60 - 1 &&
V_101 -> V_104 <= V_102 [ V_11 + 1 ] . V_104 ) {
if ( ! V_102 [ V_11 + 1 ] . V_67 )
break;
V_102 [ V_11 ] = V_102 [ V_11 + 1 ] ;
V_58 -> V_61 [ V_102 [ V_11 ] . V_24 ] = V_11 ;
V_11 ++ ;
}
if ( V_101 -> V_67 ) {
while ( V_11 > 0 &&
V_101 -> V_104 >= V_102 [ V_11 - 1 ] . V_104 ) {
V_102 [ V_11 ] = V_102 [ V_11 - 1 ] ;
V_58 -> V_61 [ V_102 [ V_11 ] . V_24 ] = V_11 ;
V_11 -- ;
}
} else
F_123 ( V_11 != V_58 -> V_103 ) ;
V_102 [ V_11 ] = * V_101 ;
V_58 -> V_61 [ V_102 [ V_11 ] . V_24 ] = V_11 ;
}
static int F_124 ( const struct V_105 * V_106 )
{
T_4 V_107 = V_108 ;
#ifdef F_125
V_107 |= V_109 ;
#endif
if ( V_106 -> V_110 & ~ V_107 )
return - V_111 ;
return 0 ;
}
static struct V_57 * F_126 ( struct V_9 * V_9 ,
int V_112 , struct V_57 * V_58 )
{
struct V_57 * V_113 = F_127 ( V_9 , V_112 ) ;
F_122 ( V_113 -> V_59 & 1 ) ;
V_58 -> V_59 = V_113 -> V_59 + 1 ;
F_128 ( V_9 -> V_62 [ V_112 ] , V_58 ) ;
F_129 ( & V_9 -> V_46 ) ;
V_58 -> V_59 ++ ;
F_130 ( V_9 , V_58 ) ;
return V_113 ;
}
int F_131 ( struct V_9 * V_9 ,
const struct V_105 * V_106 )
{
int V_26 ;
T_5 V_104 ;
unsigned long V_67 ;
struct V_63 * V_114 ;
struct V_63 V_115 , V_101 ;
struct V_57 * V_58 = NULL , * V_113 ;
int V_112 , V_24 ;
enum V_116 V_117 ;
V_26 = F_124 ( V_106 ) ;
if ( V_26 )
goto V_118;
V_26 = - V_111 ;
V_112 = V_106 -> V_114 >> 16 ;
V_24 = ( V_119 ) V_106 -> V_114 ;
if ( V_106 -> V_120 & ( V_88 - 1 ) )
goto V_118;
if ( V_106 -> V_121 & ( V_88 - 1 ) )
goto V_118;
if ( ( V_24 < V_122 ) &&
( ( V_106 -> V_123 & ( V_88 - 1 ) ) ||
! F_132 ( V_124 ,
( void V_125 * ) ( unsigned long ) V_106 -> V_123 ,
V_106 -> V_120 ) ) )
goto V_118;
if ( V_112 >= V_77 || V_24 >= V_60 )
goto V_118;
if ( V_106 -> V_121 + V_106 -> V_120 < V_106 -> V_121 )
goto V_118;
V_114 = F_133 ( F_127 ( V_9 , V_112 ) , V_24 ) ;
V_104 = V_106 -> V_121 >> V_126 ;
V_67 = V_106 -> V_120 >> V_126 ;
if ( V_67 > V_127 )
goto V_118;
V_101 = V_115 = * V_114 ;
V_101 . V_24 = V_24 ;
V_101 . V_104 = V_104 ;
V_101 . V_67 = V_67 ;
V_101 . V_110 = V_106 -> V_110 ;
if ( V_67 ) {
if ( ! V_115 . V_67 )
V_117 = V_128 ;
else {
if ( ( V_106 -> V_123 != V_115 . V_123 ) ||
( V_67 != V_115 . V_67 ) ||
( ( V_101 . V_110 ^ V_115 . V_110 ) & V_109 ) )
goto V_118;
if ( V_104 != V_115 . V_104 )
V_117 = V_129 ;
else if ( V_101 . V_110 != V_115 . V_110 )
V_117 = V_130 ;
else {
V_26 = 0 ;
goto V_118;
}
}
} else {
if ( ! V_115 . V_67 )
goto V_118;
V_117 = V_131 ;
V_101 . V_104 = 0 ;
V_101 . V_110 = 0 ;
}
if ( ( V_117 == V_128 ) || ( V_117 == V_129 ) ) {
V_26 = - V_132 ;
F_79 (slot, __kvm_memslots(kvm, as_id)) {
if ( ( V_114 -> V_24 >= V_122 ) ||
( V_114 -> V_24 == V_24 ) )
continue;
if ( ! ( ( V_104 + V_67 <= V_114 -> V_104 ) ||
( V_104 >= V_114 -> V_104 + V_114 -> V_67 ) ) )
goto V_118;
}
}
if ( ! ( V_101 . V_110 & V_108 ) )
V_101 . V_65 = NULL ;
V_26 = - V_34 ;
if ( V_117 == V_128 ) {
V_101 . V_123 = V_106 -> V_123 ;
if ( F_134 ( V_9 , & V_101 , V_67 ) )
goto V_133;
}
if ( ( V_101 . V_110 & V_108 ) && ! V_101 . V_65 ) {
if ( F_119 ( & V_101 ) < 0 )
goto V_133;
}
V_58 = F_73 ( sizeof( struct V_57 ) ) ;
if ( ! V_58 )
goto V_133;
memcpy ( V_58 , F_127 ( V_9 , V_112 ) , sizeof( struct V_57 ) ) ;
if ( ( V_117 == V_131 ) || ( V_117 == V_129 ) ) {
V_114 = F_133 ( V_58 , V_24 ) ;
V_114 -> V_110 |= V_134 ;
V_113 = F_126 ( V_9 , V_112 , V_58 ) ;
F_135 ( V_9 , & V_115 ) ;
F_136 ( V_9 , V_114 ) ;
V_58 = V_113 ;
}
V_26 = F_137 ( V_9 , & V_101 , V_106 , V_117 ) ;
if ( V_26 )
goto V_135;
if ( V_117 == V_131 ) {
V_101 . V_65 = NULL ;
memset ( & V_101 . V_136 , 0 , sizeof( V_101 . V_136 ) ) ;
}
F_121 ( V_58 , & V_101 ) ;
V_113 = F_126 ( V_9 , V_112 , V_58 ) ;
F_138 ( V_9 , V_106 , & V_115 , & V_101 , V_117 ) ;
F_76 ( V_9 , & V_115 , & V_101 ) ;
F_75 ( V_113 ) ;
if ( ( V_117 == V_128 ) || ( V_117 == V_129 ) ) {
V_26 = F_139 ( V_9 , & V_101 ) ;
return V_26 ;
}
return 0 ;
V_135:
F_75 ( V_58 ) ;
V_133:
F_76 ( V_9 , & V_101 , & V_115 ) ;
V_118:
return V_26 ;
}
int F_140 ( struct V_9 * V_9 ,
const struct V_105 * V_106 )
{
int V_26 ;
F_141 ( & V_9 -> V_71 ) ;
V_26 = F_131 ( V_9 , V_106 ) ;
F_16 ( & V_9 -> V_71 ) ;
return V_26 ;
}
static int F_142 ( struct V_9 * V_9 ,
struct V_105 * V_106 )
{
if ( ( V_119 ) V_106 -> V_114 >= V_122 )
return - V_111 ;
return F_140 ( V_9 , V_106 ) ;
}
int F_143 ( struct V_9 * V_9 ,
struct V_137 * log , int * V_138 )
{
struct V_57 * V_58 ;
struct V_63 * V_64 ;
int V_26 , V_11 , V_112 , V_24 ;
unsigned long V_139 ;
unsigned long V_140 = 0 ;
V_26 = - V_111 ;
V_112 = log -> V_114 >> 16 ;
V_24 = ( V_119 ) log -> V_114 ;
if ( V_112 >= V_77 || V_24 >= V_122 )
goto V_118;
V_58 = F_127 ( V_9 , V_112 ) ;
V_64 = F_133 ( V_58 , V_24 ) ;
V_26 = - V_141 ;
if ( ! V_64 -> V_65 )
goto V_118;
V_139 = F_120 ( V_64 ) ;
for ( V_11 = 0 ; ! V_140 && V_11 < V_139 / sizeof( long ) ; ++ V_11 )
V_140 = V_64 -> V_65 [ V_11 ] ;
V_26 = - V_142 ;
if ( F_144 ( log -> V_65 , V_64 -> V_65 , V_139 ) )
goto V_118;
if ( V_140 )
* V_138 = 1 ;
V_26 = 0 ;
V_118:
return V_26 ;
}
int F_145 ( struct V_9 * V_9 ,
struct V_137 * log , bool * V_138 )
{
struct V_57 * V_58 ;
struct V_63 * V_64 ;
int V_26 , V_11 , V_112 , V_24 ;
unsigned long V_139 ;
unsigned long * V_65 ;
unsigned long * V_143 ;
V_26 = - V_111 ;
V_112 = log -> V_114 >> 16 ;
V_24 = ( V_119 ) log -> V_114 ;
if ( V_112 >= V_77 || V_24 >= V_122 )
goto V_118;
V_58 = F_127 ( V_9 , V_112 ) ;
V_64 = F_133 ( V_58 , V_24 ) ;
V_65 = V_64 -> V_65 ;
V_26 = - V_141 ;
if ( ! V_65 )
goto V_118;
V_139 = F_120 ( V_64 ) ;
V_143 = V_65 + V_139 / sizeof( long ) ;
memset ( V_143 , 0 , V_139 ) ;
F_51 ( & V_9 -> V_47 ) ;
* V_138 = false ;
for ( V_11 = 0 ; V_11 < V_139 / sizeof( long ) ; V_11 ++ ) {
unsigned long V_144 ;
T_5 V_145 ;
if ( ! V_65 [ V_11 ] )
continue;
* V_138 = true ;
V_144 = F_146 ( & V_65 [ V_11 ] , 0 ) ;
V_143 [ V_11 ] = V_144 ;
if ( V_144 ) {
V_145 = V_11 * V_146 ;
F_147 ( V_9 , V_64 ,
V_145 , V_144 ) ;
}
}
F_53 ( & V_9 -> V_47 ) ;
V_26 = - V_142 ;
if ( F_144 ( log -> V_65 , V_143 , V_139 ) )
goto V_118;
V_26 = 0 ;
V_118:
return V_26 ;
}
bool F_148 ( void )
{
return V_147 ;
}
void F_149 ( void )
{
V_147 = false ;
}
struct V_63 * F_150 ( struct V_9 * V_9 , T_5 V_148 )
{
return F_151 ( V_57 ( V_9 ) , V_148 ) ;
}
struct V_63 * F_152 ( struct V_2 * V_3 , T_5 V_148 )
{
return F_151 ( F_153 ( V_3 ) , V_148 ) ;
}
bool F_154 ( struct V_9 * V_9 , T_5 V_148 )
{
struct V_63 * V_64 = F_150 ( V_9 , V_148 ) ;
if ( ! V_64 || V_64 -> V_24 >= V_122 ||
V_64 -> V_110 & V_134 )
return false ;
return true ;
}
unsigned long F_155 ( struct V_9 * V_9 , T_5 V_148 )
{
struct V_149 * V_150 ;
unsigned long V_151 , V_87 ;
V_87 = V_88 ;
V_151 = F_156 ( V_9 , V_148 ) ;
if ( F_157 ( V_151 ) )
return V_88 ;
F_158 ( & V_56 -> V_42 -> V_152 ) ;
V_150 = F_159 ( V_56 -> V_42 , V_151 ) ;
if ( ! V_150 )
goto V_118;
V_87 = F_160 ( V_150 ) ;
V_118:
F_161 ( & V_56 -> V_42 -> V_152 ) ;
return V_87 ;
}
static bool F_162 ( struct V_63 * V_114 )
{
return V_114 -> V_110 & V_109 ;
}
static unsigned long F_163 ( struct V_63 * V_114 , T_5 V_148 ,
T_5 * V_153 , bool V_154 )
{
if ( ! V_114 || V_114 -> V_110 & V_134 )
return V_155 ;
if ( F_162 ( V_114 ) && V_154 )
return V_156 ;
if ( V_153 )
* V_153 = V_114 -> V_67 - ( V_148 - V_114 -> V_104 ) ;
return F_164 ( V_114 , V_148 ) ;
}
static unsigned long F_165 ( struct V_63 * V_114 , T_5 V_148 ,
T_5 * V_153 )
{
return F_163 ( V_114 , V_148 , V_153 , true ) ;
}
unsigned long F_166 ( struct V_63 * V_114 ,
T_5 V_148 )
{
return F_165 ( V_114 , V_148 , NULL ) ;
}
unsigned long F_156 ( struct V_9 * V_9 , T_5 V_148 )
{
return F_165 ( F_150 ( V_9 , V_148 ) , V_148 , NULL ) ;
}
unsigned long F_167 ( struct V_2 * V_3 , T_5 V_148 )
{
return F_165 ( F_152 ( V_3 , V_148 ) , V_148 , NULL ) ;
}
unsigned long F_168 ( struct V_63 * V_114 ,
T_5 V_148 , bool * V_157 )
{
unsigned long V_158 = F_163 ( V_114 , V_148 , NULL , false ) ;
if ( ! F_157 ( V_158 ) && V_157 )
* V_157 = ! F_162 ( V_114 ) ;
return V_158 ;
}
unsigned long F_169 ( struct V_9 * V_9 , T_5 V_148 , bool * V_157 )
{
struct V_63 * V_114 = F_150 ( V_9 , V_148 ) ;
return F_168 ( V_114 , V_148 , V_157 ) ;
}
unsigned long F_170 ( struct V_2 * V_3 , T_5 V_148 , bool * V_157 )
{
struct V_63 * V_114 = F_152 ( V_3 , V_148 ) ;
return F_168 ( V_114 , V_148 , V_157 ) ;
}
static int F_171 ( unsigned long V_50 , int V_154 ,
struct V_25 * * V_25 )
{
int V_110 = V_159 | V_160 | V_161 | V_162 ;
if ( V_154 )
V_110 |= V_163 ;
return F_172 ( V_56 , V_56 -> V_42 , V_50 , 1 , V_110 , V_25 ,
NULL , NULL ) ;
}
static inline int F_173 ( unsigned long V_151 )
{
int V_164 , V_110 = V_159 | V_161 | V_163 ;
V_164 = F_172 ( V_56 , V_56 -> V_42 , V_151 , 1 ,
V_110 , NULL , NULL , NULL ) ;
return V_164 == - V_165 ;
}
static bool F_174 ( unsigned long V_151 , bool V_166 , bool * V_167 ,
bool V_168 , bool * V_157 , T_1 * V_1 )
{
struct V_25 * V_25 [ 1 ] ;
int V_67 ;
if ( ! ( V_167 || V_166 ) )
return false ;
if ( ! ( V_168 || V_157 ) )
return false ;
V_67 = F_175 ( V_151 , 1 , 1 , V_25 ) ;
if ( V_67 == 1 ) {
* V_1 = F_176 ( V_25 [ 0 ] ) ;
if ( V_157 )
* V_157 = true ;
return true ;
}
return false ;
}
static int F_177 ( unsigned long V_151 , bool * V_167 , bool V_168 ,
bool * V_157 , T_1 * V_1 )
{
struct V_25 * V_25 [ 1 ] ;
int V_67 = 0 ;
F_178 () ;
if ( V_157 )
* V_157 = V_168 ;
if ( V_167 ) {
F_158 ( & V_56 -> V_42 -> V_152 ) ;
V_67 = F_171 ( V_151 , V_168 , V_25 ) ;
F_161 ( & V_56 -> V_42 -> V_152 ) ;
} else
V_67 = F_179 ( V_56 , V_56 -> V_42 , V_151 , 1 ,
V_168 , 0 , V_25 ,
V_159 | V_161 ) ;
if ( V_67 != 1 )
return V_67 ;
if ( F_25 ( ! V_168 ) && V_157 ) {
struct V_25 * V_169 [ 1 ] ;
V_67 = F_175 ( V_151 , 1 , 1 , V_169 ) ;
if ( V_67 == 1 ) {
* V_157 = true ;
F_180 ( V_25 [ 0 ] ) ;
V_25 [ 0 ] = V_169 [ 0 ] ;
}
V_67 = 1 ;
}
* V_1 = F_176 ( V_25 [ 0 ] ) ;
return V_67 ;
}
static bool F_181 ( struct V_149 * V_150 , bool V_168 )
{
if ( F_25 ( ! ( V_150 -> V_170 & V_171 ) ) )
return false ;
if ( V_168 && ( F_25 ( ! ( V_150 -> V_170 & V_172 ) ) ) )
return false ;
return true ;
}
static T_1 F_182 ( unsigned long V_151 , bool V_166 , bool * V_167 ,
bool V_168 , bool * V_157 )
{
struct V_149 * V_150 ;
T_1 V_1 = 0 ;
int V_67 ;
F_62 ( V_166 && V_167 ) ;
if ( F_174 ( V_151 , V_166 , V_167 , V_168 , V_157 , & V_1 ) )
return V_1 ;
if ( V_166 )
return V_173 ;
V_67 = F_177 ( V_151 , V_167 , V_168 , V_157 , & V_1 ) ;
if ( V_67 == 1 )
return V_1 ;
F_158 ( & V_56 -> V_42 -> V_152 ) ;
if ( V_67 == - V_165 ||
( ! V_167 && F_173 ( V_151 ) ) ) {
V_1 = V_174 ;
goto exit;
}
V_150 = F_183 ( V_56 -> V_42 , V_151 , V_151 + 1 ) ;
if ( V_150 == NULL )
V_1 = V_173 ;
else if ( ( V_150 -> V_170 & V_175 ) ) {
V_1 = ( ( V_151 - V_150 -> V_176 ) >> V_126 ) +
V_150 -> V_177 ;
F_62 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_167 && F_181 ( V_150 , V_168 ) )
* V_167 = true ;
V_1 = V_173 ;
}
exit:
F_161 ( & V_56 -> V_42 -> V_152 ) ;
return V_1 ;
}
T_1 F_184 ( struct V_63 * V_114 , T_5 V_148 ,
bool V_166 , bool * V_167 , bool V_168 ,
bool * V_157 )
{
unsigned long V_151 = F_163 ( V_114 , V_148 , NULL , V_168 ) ;
if ( V_151 == V_156 ) {
if ( V_157 )
* V_157 = false ;
return V_178 ;
}
if ( F_157 ( V_151 ) ) {
if ( V_157 )
* V_157 = false ;
return V_179 ;
}
if ( V_157 && F_162 ( V_114 ) ) {
* V_157 = false ;
V_157 = NULL ;
}
return F_182 ( V_151 , V_166 , V_167 , V_168 ,
V_157 ) ;
}
T_1 F_185 ( struct V_9 * V_9 , T_5 V_148 , bool V_168 ,
bool * V_157 )
{
return F_184 ( F_150 ( V_9 , V_148 ) , V_148 , false , NULL ,
V_168 , V_157 ) ;
}
T_1 F_186 ( struct V_63 * V_114 , T_5 V_148 )
{
return F_184 ( V_114 , V_148 , false , NULL , true , NULL ) ;
}
T_1 F_187 ( struct V_63 * V_114 , T_5 V_148 )
{
return F_184 ( V_114 , V_148 , true , NULL , true , NULL ) ;
}
T_1 F_188 ( struct V_9 * V_9 , T_5 V_148 )
{
return F_187 ( F_150 ( V_9 , V_148 ) , V_148 ) ;
}
T_1 F_189 ( struct V_2 * V_3 , T_5 V_148 )
{
return F_187 ( F_152 ( V_3 , V_148 ) , V_148 ) ;
}
T_1 F_190 ( struct V_9 * V_9 , T_5 V_148 )
{
return F_186 ( F_150 ( V_9 , V_148 ) , V_148 ) ;
}
T_1 F_191 ( struct V_2 * V_3 , T_5 V_148 )
{
return F_186 ( F_152 ( V_3 , V_148 ) , V_148 ) ;
}
int F_192 ( struct V_63 * V_114 , T_5 V_148 ,
struct V_25 * * V_180 , int V_153 )
{
unsigned long V_151 ;
T_5 V_181 ;
V_151 = F_165 ( V_114 , V_148 , & V_181 ) ;
if ( F_157 ( V_151 ) )
return - 1 ;
if ( V_181 < V_153 )
return 0 ;
return F_175 ( V_151 , V_153 , 1 , V_180 ) ;
}
static struct V_25 * F_193 ( T_1 V_1 )
{
if ( F_194 ( V_1 ) )
return V_182 ;
if ( F_1 ( V_1 ) ) {
F_122 ( 1 ) ;
return V_182 ;
}
return F_4 ( V_1 ) ;
}
struct V_25 * F_195 ( struct V_9 * V_9 , T_5 V_148 )
{
T_1 V_1 ;
V_1 = F_190 ( V_9 , V_148 ) ;
return F_193 ( V_1 ) ;
}
struct V_25 * F_196 ( struct V_2 * V_3 , T_5 V_148 )
{
T_1 V_1 ;
V_1 = F_191 ( V_3 , V_148 ) ;
return F_193 ( V_1 ) ;
}
void F_197 ( struct V_25 * V_25 )
{
F_122 ( F_198 ( V_25 ) ) ;
F_199 ( F_176 ( V_25 ) ) ;
}
void F_199 ( T_1 V_1 )
{
if ( ! F_194 ( V_1 ) && ! F_1 ( V_1 ) )
F_180 ( F_4 ( V_1 ) ) ;
}
void F_200 ( struct V_25 * V_25 )
{
F_122 ( F_198 ( V_25 ) ) ;
F_201 ( F_176 ( V_25 ) ) ;
}
static void F_201 ( T_1 V_1 )
{
F_202 ( V_1 ) ;
F_199 ( V_1 ) ;
}
void F_202 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_25 * V_25 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_25 ) )
F_203 ( V_25 ) ;
}
}
void F_204 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_205 ( F_4 ( V_1 ) ) ;
}
void F_206 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_207 ( F_4 ( V_1 ) ) ;
}
static int F_208 ( unsigned long V_183 , int V_145 )
{
if ( V_183 > V_88 - V_145 )
return V_88 - V_145 ;
else
return V_183 ;
}
static int F_209 ( struct V_63 * V_114 , T_5 V_148 ,
void * V_184 , int V_145 , int V_183 )
{
int V_26 ;
unsigned long V_151 ;
V_151 = F_168 ( V_114 , V_148 , NULL ) ;
if ( F_157 ( V_151 ) )
return - V_142 ;
V_26 = F_210 ( V_184 , ( void V_125 * ) V_151 + V_145 , V_183 ) ;
if ( V_26 )
return - V_142 ;
return 0 ;
}
int F_211 ( struct V_9 * V_9 , T_5 V_148 , void * V_184 , int V_145 ,
int V_183 )
{
struct V_63 * V_114 = F_150 ( V_9 , V_148 ) ;
return F_209 ( V_114 , V_148 , V_184 , V_145 , V_183 ) ;
}
int F_212 ( struct V_2 * V_3 , T_5 V_148 , void * V_184 ,
int V_145 , int V_183 )
{
struct V_63 * V_114 = F_152 ( V_3 , V_148 ) ;
return F_209 ( V_114 , V_148 , V_184 , V_145 , V_183 ) ;
}
int F_213 ( struct V_9 * V_9 , T_6 V_185 , void * V_184 , unsigned long V_183 )
{
T_5 V_148 = V_185 >> V_126 ;
int V_186 ;
int V_145 = F_214 ( V_185 ) ;
int V_187 ;
while ( ( V_186 = F_208 ( V_183 , V_145 ) ) != 0 ) {
V_187 = F_211 ( V_9 , V_148 , V_184 , V_145 , V_186 ) ;
if ( V_187 < 0 )
return V_187 ;
V_145 = 0 ;
V_183 -= V_186 ;
V_184 += V_186 ;
++ V_148 ;
}
return 0 ;
}
int F_215 ( struct V_2 * V_3 , T_6 V_185 , void * V_184 , unsigned long V_183 )
{
T_5 V_148 = V_185 >> V_126 ;
int V_186 ;
int V_145 = F_214 ( V_185 ) ;
int V_187 ;
while ( ( V_186 = F_208 ( V_183 , V_145 ) ) != 0 ) {
V_187 = F_212 ( V_3 , V_148 , V_184 , V_145 , V_186 ) ;
if ( V_187 < 0 )
return V_187 ;
V_145 = 0 ;
V_183 -= V_186 ;
V_184 += V_186 ;
++ V_148 ;
}
return 0 ;
}
static int F_216 ( struct V_63 * V_114 , T_5 V_148 ,
void * V_184 , int V_145 , unsigned long V_183 )
{
int V_26 ;
unsigned long V_151 ;
V_151 = F_168 ( V_114 , V_148 , NULL ) ;
if ( F_157 ( V_151 ) )
return - V_142 ;
F_217 () ;
V_26 = F_218 ( V_184 , ( void V_125 * ) V_151 + V_145 , V_183 ) ;
F_219 () ;
if ( V_26 )
return - V_142 ;
return 0 ;
}
int F_220 ( struct V_9 * V_9 , T_6 V_185 , void * V_184 ,
unsigned long V_183 )
{
T_5 V_148 = V_185 >> V_126 ;
struct V_63 * V_114 = F_150 ( V_9 , V_148 ) ;
int V_145 = F_214 ( V_185 ) ;
return F_216 ( V_114 , V_148 , V_184 , V_145 , V_183 ) ;
}
int F_221 ( struct V_2 * V_3 , T_6 V_185 ,
void * V_184 , unsigned long V_183 )
{
T_5 V_148 = V_185 >> V_126 ;
struct V_63 * V_114 = F_152 ( V_3 , V_148 ) ;
int V_145 = F_214 ( V_185 ) ;
return F_216 ( V_114 , V_148 , V_184 , V_145 , V_183 ) ;
}
static int F_222 ( struct V_63 * V_64 , T_5 V_148 ,
const void * V_184 , int V_145 , int V_183 )
{
int V_26 ;
unsigned long V_151 ;
V_151 = F_166 ( V_64 , V_148 ) ;
if ( F_157 ( V_151 ) )
return - V_142 ;
V_26 = F_223 ( ( void V_125 * ) V_151 + V_145 , V_184 , V_183 ) ;
if ( V_26 )
return - V_142 ;
F_224 ( V_64 , V_148 ) ;
return 0 ;
}
int F_225 ( struct V_9 * V_9 , T_5 V_148 ,
const void * V_184 , int V_145 , int V_183 )
{
struct V_63 * V_114 = F_150 ( V_9 , V_148 ) ;
return F_222 ( V_114 , V_148 , V_184 , V_145 , V_183 ) ;
}
int F_226 ( struct V_2 * V_3 , T_5 V_148 ,
const void * V_184 , int V_145 , int V_183 )
{
struct V_63 * V_114 = F_152 ( V_3 , V_148 ) ;
return F_222 ( V_114 , V_148 , V_184 , V_145 , V_183 ) ;
}
int F_227 ( struct V_9 * V_9 , T_6 V_185 , const void * V_184 ,
unsigned long V_183 )
{
T_5 V_148 = V_185 >> V_126 ;
int V_186 ;
int V_145 = F_214 ( V_185 ) ;
int V_187 ;
while ( ( V_186 = F_208 ( V_183 , V_145 ) ) != 0 ) {
V_187 = F_225 ( V_9 , V_148 , V_184 , V_145 , V_186 ) ;
if ( V_187 < 0 )
return V_187 ;
V_145 = 0 ;
V_183 -= V_186 ;
V_184 += V_186 ;
++ V_148 ;
}
return 0 ;
}
int F_228 ( struct V_2 * V_3 , T_6 V_185 , const void * V_184 ,
unsigned long V_183 )
{
T_5 V_148 = V_185 >> V_126 ;
int V_186 ;
int V_145 = F_214 ( V_185 ) ;
int V_187 ;
while ( ( V_186 = F_208 ( V_183 , V_145 ) ) != 0 ) {
V_187 = F_226 ( V_3 , V_148 , V_184 , V_145 , V_186 ) ;
if ( V_187 < 0 )
return V_187 ;
V_145 = 0 ;
V_183 -= V_186 ;
V_184 += V_186 ;
++ V_148 ;
}
return 0 ;
}
int F_229 ( struct V_9 * V_9 , struct V_188 * V_189 ,
T_6 V_185 , unsigned long V_183 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_145 = F_214 ( V_185 ) ;
T_5 V_190 = V_185 >> V_126 ;
T_5 V_191 = ( V_185 + V_183 - 1 ) >> V_126 ;
T_5 V_192 = V_191 - V_190 + 1 ;
T_5 V_193 ;
V_189 -> V_185 = V_185 ;
V_189 -> V_59 = V_58 -> V_59 ;
V_189 -> V_183 = V_183 ;
V_189 -> V_64 = F_150 ( V_9 , V_190 ) ;
V_189 -> V_158 = F_165 ( V_189 -> V_64 , V_190 , NULL ) ;
if ( ! F_157 ( V_189 -> V_158 ) && V_192 <= 1 ) {
V_189 -> V_158 += V_145 ;
} else {
while ( V_190 <= V_191 ) {
V_189 -> V_64 = F_150 ( V_9 , V_190 ) ;
V_189 -> V_158 = F_165 ( V_189 -> V_64 , V_190 ,
& V_193 ) ;
if ( F_157 ( V_189 -> V_158 ) )
return - V_142 ;
V_190 += V_193 ;
}
V_189 -> V_64 = NULL ;
}
return 0 ;
}
int F_230 ( struct V_9 * V_9 , struct V_188 * V_189 ,
void * V_184 , unsigned long V_183 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_26 ;
F_62 ( V_183 > V_189 -> V_183 ) ;
if ( V_58 -> V_59 != V_189 -> V_59 )
F_229 ( V_9 , V_189 , V_189 -> V_185 , V_189 -> V_183 ) ;
if ( F_25 ( ! V_189 -> V_64 ) )
return F_227 ( V_9 , V_189 -> V_185 , V_184 , V_183 ) ;
if ( F_157 ( V_189 -> V_158 ) )
return - V_142 ;
V_26 = F_223 ( ( void V_125 * ) V_189 -> V_158 , V_184 , V_183 ) ;
if ( V_26 )
return - V_142 ;
F_224 ( V_189 -> V_64 , V_189 -> V_185 >> V_126 ) ;
return 0 ;
}
int F_231 ( struct V_9 * V_9 , struct V_188 * V_189 ,
void * V_184 , unsigned long V_183 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_26 ;
F_62 ( V_183 > V_189 -> V_183 ) ;
if ( V_58 -> V_59 != V_189 -> V_59 )
F_229 ( V_9 , V_189 , V_189 -> V_185 , V_189 -> V_183 ) ;
if ( F_25 ( ! V_189 -> V_64 ) )
return F_213 ( V_9 , V_189 -> V_185 , V_184 , V_183 ) ;
if ( F_157 ( V_189 -> V_158 ) )
return - V_142 ;
V_26 = F_210 ( V_184 , ( void V_125 * ) V_189 -> V_158 , V_183 ) ;
if ( V_26 )
return - V_142 ;
return 0 ;
}
int F_232 ( struct V_9 * V_9 , T_5 V_148 , int V_145 , int V_183 )
{
const void * V_194 = ( const void * ) F_233 ( F_234 ( F_235 ( 0 ) ) ) ;
return F_225 ( V_9 , V_148 , V_194 , V_145 , V_183 ) ;
}
int F_236 ( struct V_9 * V_9 , T_6 V_185 , unsigned long V_183 )
{
T_5 V_148 = V_185 >> V_126 ;
int V_186 ;
int V_145 = F_214 ( V_185 ) ;
int V_187 ;
while ( ( V_186 = F_208 ( V_183 , V_145 ) ) != 0 ) {
V_187 = F_232 ( V_9 , V_148 , V_145 , V_186 ) ;
if ( V_187 < 0 )
return V_187 ;
V_145 = 0 ;
V_183 -= V_186 ;
++ V_148 ;
}
return 0 ;
}
static void F_224 ( struct V_63 * V_64 ,
T_5 V_148 )
{
if ( V_64 && V_64 -> V_65 ) {
unsigned long V_195 = V_148 - V_64 -> V_104 ;
F_237 ( V_195 , V_64 -> V_65 ) ;
}
}
void F_238 ( struct V_9 * V_9 , T_5 V_148 )
{
struct V_63 * V_64 ;
V_64 = F_150 ( V_9 , V_148 ) ;
F_224 ( V_64 , V_148 ) ;
}
void F_239 ( struct V_2 * V_3 , T_5 V_148 )
{
struct V_63 * V_64 ;
V_64 = F_152 ( V_3 , V_148 ) ;
F_224 ( V_64 , V_148 ) ;
}
static void F_240 ( struct V_2 * V_3 )
{
unsigned int V_115 , V_196 , V_197 ;
V_115 = V_196 = V_3 -> V_198 ;
V_197 = F_241 ( V_199 ) ;
if ( V_196 == 0 && V_197 )
V_196 = 10000 ;
else
V_196 *= V_197 ;
if ( V_196 > V_198 )
V_196 = V_198 ;
V_3 -> V_198 = V_196 ;
F_242 ( V_3 -> V_27 , V_196 , V_115 ) ;
}
static void F_243 ( struct V_2 * V_3 )
{
unsigned int V_115 , V_196 , V_200 ;
V_115 = V_196 = V_3 -> V_198 ;
V_200 = F_241 ( V_201 ) ;
if ( V_200 == 0 )
V_196 = 0 ;
else
V_196 /= V_200 ;
V_3 -> V_198 = V_196 ;
F_244 ( V_3 -> V_27 , V_196 , V_115 ) ;
}
static int F_245 ( struct V_2 * V_3 )
{
if ( F_246 ( V_3 ) ) {
F_21 ( V_202 , V_3 ) ;
return - V_6 ;
}
if ( F_247 ( V_3 ) )
return - V_6 ;
if ( F_248 ( V_56 ) )
return - V_6 ;
return 0 ;
}
void F_249 ( struct V_2 * V_3 )
{
T_7 V_50 , V_203 ;
F_250 ( V_204 ) ;
bool V_205 = false ;
T_8 V_206 ;
V_50 = V_203 = F_251 () ;
if ( V_3 -> V_198 ) {
T_7 V_207 = F_252 ( F_251 () , V_3 -> V_198 ) ;
++ V_3 -> V_21 . V_208 ;
do {
if ( F_245 ( V_3 ) < 0 ) {
++ V_3 -> V_21 . V_209 ;
goto V_118;
}
V_203 = F_251 () ;
} while ( F_253 () && F_254 ( V_203 , V_207 ) );
}
F_255 ( V_3 ) ;
for (; ; ) {
F_256 ( & V_3 -> V_29 , & V_204 , V_210 ) ;
if ( F_245 ( V_3 ) < 0 )
break;
V_205 = true ;
F_257 () ;
}
F_258 ( & V_3 -> V_29 , & V_204 ) ;
V_203 = F_251 () ;
F_259 ( V_3 ) ;
V_118:
V_206 = F_260 ( V_203 ) - F_260 ( V_50 ) ;
if ( V_198 ) {
if ( V_206 <= V_3 -> V_198 )
;
else if ( V_3 -> V_198 && V_206 > V_198 )
F_243 ( V_3 ) ;
else if ( V_3 -> V_198 < V_198 &&
V_206 < V_198 )
F_240 ( V_3 ) ;
} else
V_3 -> V_198 = 0 ;
F_261 ( V_206 , V_205 ) ;
}
void F_262 ( struct V_2 * V_3 )
{
int V_12 ;
int V_4 = V_3 -> V_4 ;
struct V_211 * V_212 ;
V_212 = F_263 ( V_3 ) ;
if ( F_264 ( V_212 ) ) {
F_265 ( V_212 ) ;
++ V_3 -> V_21 . V_213 ;
}
V_12 = F_7 () ;
if ( V_4 != V_12 && ( unsigned ) V_4 < V_214 && F_266 ( V_4 ) )
if ( F_267 ( V_3 ) )
F_268 ( V_4 ) ;
F_10 () ;
}
int F_269 ( struct V_2 * V_215 )
{
struct V_28 * V_28 ;
struct V_216 * V_217 = NULL ;
int V_187 = 0 ;
F_270 () ;
V_28 = F_271 ( V_215 -> V_28 ) ;
if ( V_28 )
V_217 = F_272 ( V_28 , V_218 ) ;
F_273 () ;
if ( ! V_217 )
return V_187 ;
V_187 = F_274 ( V_217 , 1 ) ;
F_275 ( V_217 ) ;
return V_187 ;
}
static bool F_276 ( struct V_2 * V_3 )
{
#ifdef F_277
bool V_219 ;
V_219 = ! V_3 -> V_220 . V_221 ||
V_3 -> V_220 . V_222 ;
if ( V_3 -> V_220 . V_221 )
F_41 ( V_3 , ! V_3 -> V_220 . V_222 ) ;
return V_219 ;
#else
return true ;
#endif
}
void F_278 ( struct V_2 * V_12 )
{
struct V_9 * V_9 = V_12 -> V_9 ;
struct V_2 * V_3 ;
int V_223 = V_12 -> V_9 -> V_223 ;
int V_224 = 0 ;
int V_225 = 3 ;
int V_226 ;
int V_11 ;
F_40 ( V_12 , true ) ;
for ( V_226 = 0 ; V_226 < 2 && ! V_224 && V_225 ; V_226 ++ ) {
F_20 (i, vcpu, kvm) {
if ( ! V_226 && V_11 <= V_223 ) {
V_11 = V_223 ;
continue;
} else if ( V_226 && V_11 > V_223 )
break;
if ( ! F_279 ( V_3 -> V_37 ) )
continue;
if ( V_3 == V_12 )
continue;
if ( F_264 ( & V_3 -> V_29 ) && ! F_246 ( V_3 ) )
continue;
if ( ! F_276 ( V_3 ) )
continue;
V_224 = F_269 ( V_3 ) ;
if ( V_224 > 0 ) {
V_9 -> V_223 = V_11 ;
break;
} else if ( V_224 < 0 ) {
V_225 -- ;
if ( ! V_225 )
break;
}
}
}
F_40 ( V_12 , false ) ;
F_41 ( V_12 , false ) ;
}
static int F_280 ( struct V_149 * V_150 , struct V_227 * V_228 )
{
struct V_2 * V_3 = V_150 -> V_229 -> V_99 ;
struct V_25 * V_25 ;
if ( V_228 -> V_230 == 0 )
V_25 = F_281 ( V_3 -> V_36 ) ;
#ifdef F_282
else if ( V_228 -> V_230 == V_231 )
V_25 = F_281 ( V_3 -> V_136 . V_232 ) ;
#endif
#ifdef F_283
else if ( V_228 -> V_230 == F_283 )
V_25 = F_281 ( V_3 -> V_9 -> V_233 ) ;
#endif
else
return F_284 ( V_3 , V_228 ) ;
F_207 ( V_25 ) ;
V_228 -> V_25 = V_25 ;
return 0 ;
}
static int F_285 ( struct V_97 * V_97 , struct V_149 * V_150 )
{
V_150 -> V_234 = & V_235 ;
return 0 ;
}
static int F_286 ( struct V_96 * V_96 , struct V_97 * V_98 )
{
struct V_2 * V_3 = V_98 -> V_99 ;
F_115 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_287 ( struct V_2 * V_3 )
{
return F_288 ( L_1 , & V_236 , V_3 , V_237 | V_238 ) ;
}
static int F_289 ( struct V_9 * V_9 , T_4 V_24 )
{
int V_26 ;
struct V_2 * V_3 ;
if ( V_24 >= V_239 )
return - V_111 ;
V_3 = F_290 ( V_9 , V_24 ) ;
if ( F_291 ( V_3 ) )
return F_292 ( V_3 ) ;
F_293 ( & V_3 -> V_7 , & V_240 ) ;
V_26 = F_294 ( V_3 ) ;
if ( V_26 )
goto V_241;
F_141 ( & V_9 -> V_69 ) ;
if ( ! F_295 ( V_3 ) ) {
V_26 = - V_111 ;
goto V_242;
}
if ( F_296 ( & V_9 -> V_243 ) == V_239 ) {
V_26 = - V_111 ;
goto V_242;
}
if ( F_297 ( V_9 , V_24 ) ) {
V_26 = - V_132 ;
goto V_242;
}
F_62 ( V_9 -> V_244 [ F_296 ( & V_9 -> V_243 ) ] ) ;
F_114 ( V_9 ) ;
V_26 = F_287 ( V_3 ) ;
if ( V_26 < 0 ) {
F_115 ( V_9 ) ;
goto V_242;
}
V_9 -> V_244 [ F_296 ( & V_9 -> V_243 ) ] = V_3 ;
F_61 () ;
F_84 ( & V_9 -> V_243 ) ;
F_16 ( & V_9 -> V_69 ) ;
F_298 ( V_3 ) ;
return V_26 ;
V_242:
F_16 ( & V_9 -> V_69 ) ;
V_241:
F_299 ( V_3 ) ;
return V_26 ;
}
static int F_300 ( struct V_2 * V_3 , T_9 * V_245 )
{
if ( V_245 ) {
F_301 ( V_245 , F_302 ( V_246 ) | F_302 ( V_247 ) ) ;
V_3 -> V_248 = 1 ;
V_3 -> V_245 = * V_245 ;
} else
V_3 -> V_248 = 0 ;
return 0 ;
}
static long F_303 ( struct V_97 * V_98 ,
unsigned int V_249 , unsigned long V_250 )
{
struct V_2 * V_3 = V_98 -> V_99 ;
void V_125 * V_251 = ( void V_125 * ) V_250 ;
int V_26 ;
struct V_252 * V_253 = NULL ;
struct V_254 * V_254 = NULL ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_255 ;
if ( F_25 ( F_304 ( V_249 ) != V_256 ) )
return - V_111 ;
#if F_110 ( V_257 ) || F_110 ( V_258 ) || F_110 ( V_259 )
if ( V_249 == V_260 || V_249 == V_261 || V_249 == V_262 )
return F_305 ( V_98 , V_249 , V_250 ) ;
#endif
V_26 = F_5 ( V_3 ) ;
if ( V_26 )
return V_26 ;
switch ( V_249 ) {
case V_263 :
V_26 = - V_111 ;
if ( V_250 )
goto V_118;
if ( F_25 ( V_3 -> V_28 != V_56 -> V_264 [ V_218 ] . V_28 ) ) {
struct V_28 * V_265 = V_3 -> V_28 ;
struct V_28 * V_266 = F_306 ( V_56 , V_218 ) ;
F_128 ( V_3 -> V_28 , V_266 ) ;
if ( V_265 )
F_307 () ;
F_45 ( V_265 ) ;
}
V_26 = F_308 ( V_3 , V_3 -> V_36 ) ;
F_309 ( V_3 -> V_36 -> V_267 , V_26 ) ;
break;
case V_268 : {
struct V_269 * V_269 ;
V_26 = - V_34 ;
V_269 = F_93 ( sizeof( struct V_269 ) , V_32 ) ;
if ( ! V_269 )
goto V_118;
V_26 = F_310 ( V_3 , V_269 ) ;
if ( V_26 )
goto V_270;
V_26 = - V_142 ;
if ( F_144 ( V_251 , V_269 , sizeof( struct V_269 ) ) )
goto V_270;
V_26 = 0 ;
V_270:
F_98 ( V_269 ) ;
break;
}
case V_271 : {
struct V_269 * V_269 ;
V_26 = - V_34 ;
V_269 = F_311 ( V_251 , sizeof( * V_269 ) ) ;
if ( F_291 ( V_269 ) ) {
V_26 = F_292 ( V_269 ) ;
goto V_118;
}
V_26 = F_312 ( V_3 , V_269 ) ;
F_98 ( V_269 ) ;
break;
}
case V_272 : {
V_254 = F_93 ( sizeof( struct V_254 ) , V_32 ) ;
V_26 = - V_34 ;
if ( ! V_254 )
goto V_118;
V_26 = F_313 ( V_3 , V_254 ) ;
if ( V_26 )
goto V_118;
V_26 = - V_142 ;
if ( F_144 ( V_251 , V_254 , sizeof( struct V_254 ) ) )
goto V_118;
V_26 = 0 ;
break;
}
case V_273 : {
V_254 = F_311 ( V_251 , sizeof( * V_254 ) ) ;
if ( F_291 ( V_254 ) ) {
V_26 = F_292 ( V_254 ) ;
V_254 = NULL ;
goto V_118;
}
V_26 = F_314 ( V_3 , V_254 ) ;
break;
}
case V_274 : {
struct V_275 V_276 ;
V_26 = F_315 ( V_3 , & V_276 ) ;
if ( V_26 )
goto V_118;
V_26 = - V_142 ;
if ( F_144 ( V_251 , & V_276 , sizeof( V_276 ) ) )
goto V_118;
V_26 = 0 ;
break;
}
case V_277 : {
struct V_275 V_276 ;
V_26 = - V_142 ;
if ( F_316 ( & V_276 , V_251 , sizeof( V_276 ) ) )
goto V_118;
V_26 = F_317 ( V_3 , & V_276 ) ;
break;
}
case V_278 : {
struct V_279 V_280 ;
V_26 = - V_142 ;
if ( F_316 ( & V_280 , V_251 , sizeof( V_280 ) ) )
goto V_118;
V_26 = F_318 ( V_3 , & V_280 ) ;
if ( V_26 )
goto V_118;
V_26 = - V_142 ;
if ( F_144 ( V_251 , & V_280 , sizeof( V_280 ) ) )
goto V_118;
V_26 = 0 ;
break;
}
case V_281 : {
struct V_282 V_283 ;
V_26 = - V_142 ;
if ( F_316 ( & V_283 , V_251 , sizeof( V_283 ) ) )
goto V_118;
V_26 = F_319 ( V_3 , & V_283 ) ;
break;
}
case V_284 : {
struct V_285 V_125 * V_286 = V_251 ;
struct V_285 V_287 ;
T_9 V_245 , * V_288 ;
V_288 = NULL ;
if ( V_251 ) {
V_26 = - V_142 ;
if ( F_316 ( & V_287 , V_251 ,
sizeof( V_287 ) ) )
goto V_118;
V_26 = - V_111 ;
if ( V_287 . V_183 != sizeof( V_245 ) )
goto V_118;
V_26 = - V_142 ;
if ( F_316 ( & V_245 , V_286 -> V_245 ,
sizeof( V_245 ) ) )
goto V_118;
V_288 = & V_245 ;
}
V_26 = F_300 ( V_3 , V_288 ) ;
break;
}
case V_289 : {
V_253 = F_93 ( sizeof( struct V_252 ) , V_32 ) ;
V_26 = - V_34 ;
if ( ! V_253 )
goto V_118;
V_26 = F_320 ( V_3 , V_253 ) ;
if ( V_26 )
goto V_118;
V_26 = - V_142 ;
if ( F_144 ( V_251 , V_253 , sizeof( struct V_252 ) ) )
goto V_118;
V_26 = 0 ;
break;
}
case V_290 : {
V_253 = F_311 ( V_251 , sizeof( * V_253 ) ) ;
if ( F_291 ( V_253 ) ) {
V_26 = F_292 ( V_253 ) ;
V_253 = NULL ;
goto V_118;
}
V_26 = F_321 ( V_3 , V_253 ) ;
break;
}
default:
V_26 = F_305 ( V_98 , V_249 , V_250 ) ;
}
V_118:
F_11 ( V_3 ) ;
F_98 ( V_253 ) ;
F_98 ( V_254 ) ;
return V_26 ;
}
static long F_322 ( struct V_97 * V_98 ,
unsigned int V_249 , unsigned long V_250 )
{
struct V_2 * V_3 = V_98 -> V_99 ;
void V_125 * V_251 = F_323 ( V_250 ) ;
int V_26 ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_255 ;
switch ( V_249 ) {
case V_284 : {
struct V_285 V_125 * V_286 = V_251 ;
struct V_285 V_287 ;
T_10 V_291 ;
T_9 V_245 ;
if ( V_251 ) {
V_26 = - V_142 ;
if ( F_316 ( & V_287 , V_251 ,
sizeof( V_287 ) ) )
goto V_118;
V_26 = - V_111 ;
if ( V_287 . V_183 != sizeof( V_291 ) )
goto V_118;
V_26 = - V_142 ;
if ( F_316 ( & V_291 , V_286 -> V_245 ,
sizeof( V_291 ) ) )
goto V_118;
F_324 ( & V_245 , & V_291 ) ;
V_26 = F_300 ( V_3 , & V_245 ) ;
} else
V_26 = F_300 ( V_3 , NULL ) ;
break;
}
default:
V_26 = F_303 ( V_98 , V_249 , V_250 ) ;
}
V_118:
return V_26 ;
}
static int F_325 ( struct V_89 * V_90 ,
int (* F_326)( struct V_89 * V_90 ,
struct V_292 * V_293 ) ,
unsigned long V_250 )
{
struct V_292 V_293 ;
if ( ! F_326 )
return - V_294 ;
if ( F_316 ( & V_293 , ( void V_125 * ) V_250 , sizeof( V_293 ) ) )
return - V_142 ;
return F_326 ( V_90 , & V_293 ) ;
}
static long F_327 ( struct V_97 * V_98 , unsigned int V_249 ,
unsigned long V_250 )
{
struct V_89 * V_90 = V_98 -> V_99 ;
switch ( V_249 ) {
case V_295 :
return F_325 ( V_90 , V_90 -> V_54 -> V_296 , V_250 ) ;
case V_297 :
return F_325 ( V_90 , V_90 -> V_54 -> V_298 , V_250 ) ;
case V_299 :
return F_325 ( V_90 , V_90 -> V_54 -> V_300 , V_250 ) ;
default:
if ( V_90 -> V_54 -> V_249 )
return V_90 -> V_54 -> V_249 ( V_90 , V_249 , V_250 ) ;
return - V_301 ;
}
}
static int F_328 ( struct V_96 * V_96 , struct V_97 * V_98 )
{
struct V_89 * V_90 = V_98 -> V_99 ;
struct V_9 * V_9 = V_90 -> V_9 ;
F_115 ( V_9 ) ;
return 0 ;
}
struct V_89 * F_329 ( struct V_97 * V_98 )
{
if ( V_98 -> V_302 != & V_303 )
return NULL ;
return V_98 -> V_99 ;
}
int F_330 ( struct V_304 * V_54 , T_4 type )
{
if ( type >= F_331 ( V_305 ) )
return - V_306 ;
if ( V_305 [ type ] != NULL )
return - V_132 ;
V_305 [ type ] = V_54 ;
return 0 ;
}
void F_332 ( T_4 type )
{
if ( V_305 [ type ] != NULL )
V_305 [ type ] = NULL ;
}
static int F_333 ( struct V_9 * V_9 ,
struct V_307 * V_308 )
{
struct V_304 * V_54 = NULL ;
struct V_89 * V_90 ;
bool V_309 = V_308 -> V_110 & V_310 ;
int V_187 ;
if ( V_308 -> type >= F_331 ( V_305 ) )
return - V_311 ;
V_54 = V_305 [ V_308 -> type ] ;
if ( V_54 == NULL )
return - V_311 ;
if ( V_309 )
return 0 ;
V_90 = F_93 ( sizeof( * V_90 ) , V_32 ) ;
if ( ! V_90 )
return - V_34 ;
V_90 -> V_54 = V_54 ;
V_90 -> V_9 = V_9 ;
V_187 = V_54 -> V_312 ( V_90 , V_308 -> type ) ;
if ( V_187 < 0 ) {
F_98 ( V_90 ) ;
return V_187 ;
}
V_187 = F_288 ( V_54 -> V_313 , & V_303 , V_90 , V_237 | V_238 ) ;
if ( V_187 < 0 ) {
V_54 -> V_93 ( V_90 ) ;
return V_187 ;
}
F_94 ( & V_90 -> V_92 , & V_9 -> V_73 ) ;
F_114 ( V_9 ) ;
V_308 -> V_314 = V_187 ;
return 0 ;
}
static long F_334 ( struct V_9 * V_9 , long V_250 )
{
switch ( V_250 ) {
case V_315 :
case V_316 :
case V_317 :
case V_318 :
#ifdef F_335
case V_319 :
#endif
#ifdef F_89
case V_320 :
case V_321 :
#endif
case V_322 :
case V_323 :
return 1 ;
#ifdef F_336
case V_324 :
return V_325 ;
#endif
#if V_77 > 1
case V_326 :
return V_77 ;
#endif
default:
break;
}
return F_337 ( V_9 , V_250 ) ;
}
static long F_338 ( struct V_97 * V_98 ,
unsigned int V_249 , unsigned long V_250 )
{
struct V_9 * V_9 = V_98 -> V_99 ;
void V_125 * V_251 = ( void V_125 * ) V_250 ;
int V_26 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_255 ;
switch ( V_249 ) {
case V_327 :
V_26 = F_289 ( V_9 , V_250 ) ;
break;
case V_328 : {
struct V_105 V_329 ;
V_26 = - V_142 ;
if ( F_316 ( & V_329 , V_251 ,
sizeof( V_329 ) ) )
goto V_118;
V_26 = F_142 ( V_9 , & V_329 ) ;
break;
}
case V_330 : {
struct V_137 log ;
V_26 = - V_142 ;
if ( F_316 ( & log , V_251 , sizeof( log ) ) )
goto V_118;
V_26 = F_339 ( V_9 , & log ) ;
break;
}
#ifdef F_283
case V_331 : {
struct V_332 V_333 ;
V_26 = - V_142 ;
if ( F_316 ( & V_333 , V_251 , sizeof( V_333 ) ) )
goto V_118;
V_26 = F_340 ( V_9 , & V_333 ) ;
break;
}
case V_334 : {
struct V_332 V_333 ;
V_26 = - V_142 ;
if ( F_316 ( & V_333 , V_251 , sizeof( V_333 ) ) )
goto V_118;
V_26 = F_341 ( V_9 , & V_333 ) ;
break;
}
#endif
case V_335 : {
struct V_336 V_184 ;
V_26 = - V_142 ;
if ( F_316 ( & V_184 , V_251 , sizeof( V_184 ) ) )
goto V_118;
V_26 = V_336 ( V_9 , & V_184 ) ;
break;
}
case V_337 : {
struct V_338 V_184 ;
V_26 = - V_142 ;
if ( F_316 ( & V_184 , V_251 , sizeof( V_184 ) ) )
goto V_118;
V_26 = V_338 ( V_9 , & V_184 ) ;
break;
}
#ifdef F_335
case V_339 : {
struct V_340 V_341 ;
V_26 = - V_142 ;
if ( F_316 ( & V_341 , V_251 , sizeof( V_341 ) ) )
goto V_118;
V_26 = F_342 ( V_9 , & V_341 ) ;
break;
}
#endif
#ifdef F_343
case V_342 :
case V_343 : {
struct V_344 V_345 ;
V_26 = - V_142 ;
if ( F_316 ( & V_345 , V_251 , sizeof( V_345 ) ) )
goto V_118;
V_26 = F_344 ( V_9 , & V_345 ,
V_249 == V_342 ) ;
if ( V_26 )
goto V_118;
V_26 = - V_142 ;
if ( V_249 == V_342 ) {
if ( F_144 ( V_251 , & V_345 , sizeof( V_345 ) ) )
goto V_118;
}
V_26 = 0 ;
break;
}
#endif
#ifdef F_336
case V_346 : {
struct V_347 V_348 ;
struct V_347 V_125 * V_349 ;
struct V_350 * V_351 ;
V_26 = - V_142 ;
if ( F_316 ( & V_348 , V_251 , sizeof( V_348 ) ) )
goto V_118;
V_26 = - V_111 ;
if ( V_348 . V_352 >= V_325 )
goto V_118;
if ( V_348 . V_110 )
goto V_118;
V_26 = - V_34 ;
V_351 = F_345 ( V_348 . V_352 * sizeof( * V_351 ) ) ;
if ( ! V_351 )
goto V_118;
V_26 = - V_142 ;
V_349 = V_251 ;
if ( F_316 ( V_351 , V_349 -> V_351 ,
V_348 . V_352 * sizeof( * V_351 ) ) )
goto V_353;
V_26 = F_346 ( V_9 , V_351 , V_348 . V_352 ,
V_348 . V_110 ) ;
V_353:
F_347 ( V_351 ) ;
break;
}
#endif
case V_354 : {
struct V_307 V_308 ;
V_26 = - V_142 ;
if ( F_316 ( & V_308 , V_251 , sizeof( V_308 ) ) )
goto V_118;
V_26 = F_333 ( V_9 , & V_308 ) ;
if ( V_26 )
goto V_118;
V_26 = - V_142 ;
if ( F_144 ( V_251 , & V_308 , sizeof( V_308 ) ) )
goto V_118;
V_26 = 0 ;
break;
}
case V_355 :
V_26 = F_334 ( V_9 , V_250 ) ;
break;
default:
V_26 = F_348 ( V_98 , V_249 , V_250 ) ;
}
V_118:
return V_26 ;
}
static long F_349 ( struct V_97 * V_98 ,
unsigned int V_249 , unsigned long V_250 )
{
struct V_9 * V_9 = V_98 -> V_99 ;
int V_26 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_255 ;
switch ( V_249 ) {
case V_330 : {
struct V_356 V_357 ;
struct V_137 log ;
V_26 = - V_142 ;
if ( F_316 ( & V_357 , ( void V_125 * ) V_250 ,
sizeof( V_357 ) ) )
goto V_118;
log . V_114 = V_357 . V_114 ;
log . V_358 = V_357 . V_358 ;
log . V_359 = V_357 . V_359 ;
log . V_65 = F_323 ( V_357 . V_65 ) ;
V_26 = F_339 ( V_9 , & log ) ;
break;
}
default:
V_26 = F_338 ( V_98 , V_249 , V_250 ) ;
}
V_118:
return V_26 ;
}
static int F_350 ( unsigned long type )
{
int V_26 ;
struct V_9 * V_9 ;
V_9 = F_80 ( type ) ;
if ( F_291 ( V_9 ) )
return F_292 ( V_9 ) ;
#ifdef F_283
V_26 = F_351 ( V_9 ) ;
if ( V_26 < 0 ) {
F_115 ( V_9 ) ;
return V_26 ;
}
#endif
V_26 = F_288 ( L_2 , & V_360 , V_9 , V_237 | V_238 ) ;
if ( V_26 < 0 )
F_115 ( V_9 ) ;
return V_26 ;
}
static long F_352 ( struct V_97 * V_98 ,
unsigned int V_249 , unsigned long V_250 )
{
long V_26 = - V_111 ;
switch ( V_249 ) {
case V_361 :
if ( V_250 )
goto V_118;
V_26 = V_362 ;
break;
case V_363 :
V_26 = F_350 ( V_250 ) ;
break;
case V_355 :
V_26 = F_334 ( NULL , V_250 ) ;
break;
case V_364 :
if ( V_250 )
goto V_118;
V_26 = V_88 ;
#ifdef F_282
V_26 += V_88 ;
#endif
#ifdef F_283
V_26 += V_88 ;
#endif
break;
case V_365 :
case V_366 :
case V_367 :
V_26 = - V_368 ;
break;
default:
return F_353 ( V_98 , V_249 , V_250 ) ;
}
V_118:
return V_26 ;
}
static void F_354 ( void * V_369 )
{
int V_4 = F_355 () ;
int V_26 ;
if ( F_356 ( V_4 , V_370 ) )
return;
F_24 ( V_4 , V_370 ) ;
V_26 = F_357 () ;
if ( V_26 ) {
F_358 ( V_4 , V_370 ) ;
F_84 ( & V_371 ) ;
F_359 ( L_3 , V_4 ) ;
}
}
static void F_360 ( void )
{
F_361 ( & V_372 ) ;
if ( V_373 )
F_354 ( NULL ) ;
F_362 ( & V_372 ) ;
}
static void F_363 ( void * V_369 )
{
int V_4 = F_355 () ;
if ( ! F_356 ( V_4 , V_370 ) )
return;
F_358 ( V_4 , V_370 ) ;
F_364 () ;
}
static void F_365 ( void )
{
F_361 ( & V_372 ) ;
if ( V_373 )
F_363 ( NULL ) ;
F_362 ( & V_372 ) ;
}
static void F_366 ( void )
{
F_62 ( ! V_373 ) ;
V_373 -- ;
if ( ! V_373 )
F_367 ( F_363 , NULL , 1 ) ;
}
static void F_97 ( void )
{
F_361 ( & V_372 ) ;
F_366 () ;
F_362 ( & V_372 ) ;
}
static int F_88 ( void )
{
int V_26 = 0 ;
F_361 ( & V_372 ) ;
V_373 ++ ;
if ( V_373 == 1 ) {
F_86 ( & V_371 , 0 ) ;
F_367 ( F_354 , NULL , 1 ) ;
if ( F_296 ( & V_371 ) ) {
F_366 () ;
V_26 = - V_374 ;
}
}
F_362 ( & V_372 ) ;
return V_26 ;
}
static int F_368 ( struct V_375 * V_376 , unsigned long V_196 ,
void * V_377 )
{
V_196 &= ~ V_378 ;
switch ( V_196 ) {
case V_379 :
F_365 () ;
break;
case V_380 :
F_360 () ;
break;
}
return V_381 ;
}
static int F_369 ( struct V_375 * V_376 , unsigned long V_196 ,
void * V_377 )
{
F_359 ( L_4 ) ;
V_382 = true ;
F_367 ( F_363 , NULL , 1 ) ;
return V_381 ;
}
static void F_108 ( struct V_83 * V_383 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_383 -> V_384 ; V_11 ++ ) {
struct V_385 * V_386 = V_383 -> V_387 [ V_11 ] . V_90 ;
F_370 ( V_386 ) ;
}
F_98 ( V_383 ) ;
}
static inline int F_371 ( const struct V_388 * V_389 ,
const struct V_388 * V_390 )
{
T_6 V_391 = V_389 -> V_151 ;
T_6 V_392 = V_390 -> V_151 ;
if ( V_391 < V_392 )
return - 1 ;
if ( V_390 -> V_183 ) {
V_391 += V_389 -> V_183 ;
V_392 += V_390 -> V_183 ;
}
if ( V_391 > V_392 )
return 1 ;
return 0 ;
}
static int F_372 ( const void * V_393 , const void * V_394 )
{
return F_371 ( V_393 , V_394 ) ;
}
static int F_373 ( struct V_83 * V_383 , struct V_385 * V_90 ,
T_6 V_151 , int V_183 )
{
V_383 -> V_387 [ V_383 -> V_384 ++ ] = (struct V_388 ) {
. V_151 = V_151 ,
. V_183 = V_183 ,
. V_90 = V_90 ,
} ;
F_374 ( V_383 -> V_387 , V_383 -> V_384 , sizeof( struct V_388 ) ,
F_372 , NULL ) ;
return 0 ;
}
static int F_375 ( struct V_83 * V_383 ,
T_6 V_151 , int V_183 )
{
struct V_388 * V_387 , V_395 ;
int V_396 ;
V_395 = (struct V_388 ) {
. V_151 = V_151 ,
. V_183 = V_183 ,
} ;
V_387 = bsearch ( & V_395 , V_383 -> V_387 , V_383 -> V_384 ,
sizeof( struct V_388 ) , F_372 ) ;
if ( V_387 == NULL )
return - V_141 ;
V_396 = V_387 - V_383 -> V_387 ;
while ( V_396 > 0 && F_371 ( & V_395 , & V_383 -> V_387 [ V_396 - 1 ] ) == 0 )
V_396 -- ;
return V_396 ;
}
static int F_376 ( struct V_2 * V_3 , struct V_83 * V_383 ,
struct V_388 * V_387 , const void * V_196 )
{
int V_45 ;
V_45 = F_375 ( V_383 , V_387 -> V_151 , V_387 -> V_183 ) ;
if ( V_45 < 0 )
return - V_368 ;
while ( V_45 < V_383 -> V_384 &&
F_371 ( V_387 , & V_383 -> V_387 [ V_45 ] ) == 0 ) {
if ( ! F_377 ( V_3 , V_383 -> V_387 [ V_45 ] . V_90 , V_387 -> V_151 ,
V_387 -> V_183 , V_196 ) )
return V_45 ;
V_45 ++ ;
}
return - V_368 ;
}
int F_378 ( struct V_2 * V_3 , enum V_397 V_398 , T_6 V_151 ,
int V_183 , const void * V_196 )
{
struct V_83 * V_383 ;
struct V_388 V_387 ;
int V_26 ;
V_387 = (struct V_388 ) {
. V_151 = V_151 ,
. V_183 = V_183 ,
} ;
V_383 = F_379 ( V_3 -> V_9 -> V_82 [ V_398 ] , & V_3 -> V_9 -> V_46 ) ;
V_26 = F_376 ( V_3 , V_383 , & V_387 , V_196 ) ;
return V_26 < 0 ? V_26 : 0 ;
}
int F_380 ( struct V_2 * V_3 , enum V_397 V_398 ,
T_6 V_151 , int V_183 , const void * V_196 , long V_399 )
{
struct V_83 * V_383 ;
struct V_388 V_387 ;
V_387 = (struct V_388 ) {
. V_151 = V_151 ,
. V_183 = V_183 ,
} ;
V_383 = F_379 ( V_3 -> V_9 -> V_82 [ V_398 ] , & V_3 -> V_9 -> V_46 ) ;
if ( ( V_399 >= 0 ) && ( V_399 < V_383 -> V_384 ) &&
( F_371 ( & V_387 , & V_383 -> V_387 [ V_399 ] ) == 0 ) )
if ( ! F_377 ( V_3 , V_383 -> V_387 [ V_399 ] . V_90 , V_151 , V_183 ,
V_196 ) )
return V_399 ;
return F_376 ( V_3 , V_383 , & V_387 , V_196 ) ;
}
static int F_381 ( struct V_2 * V_3 , struct V_83 * V_383 ,
struct V_388 * V_387 , void * V_196 )
{
int V_45 ;
V_45 = F_375 ( V_383 , V_387 -> V_151 , V_387 -> V_183 ) ;
if ( V_45 < 0 )
return - V_368 ;
while ( V_45 < V_383 -> V_384 &&
F_371 ( V_387 , & V_383 -> V_387 [ V_45 ] ) == 0 ) {
if ( ! F_382 ( V_3 , V_383 -> V_387 [ V_45 ] . V_90 , V_387 -> V_151 ,
V_387 -> V_183 , V_196 ) )
return V_45 ;
V_45 ++ ;
}
return - V_368 ;
}
int F_383 ( struct V_2 * V_3 , enum V_397 V_398 , T_6 V_151 ,
int V_183 , void * V_196 )
{
struct V_83 * V_383 ;
struct V_388 V_387 ;
int V_26 ;
V_387 = (struct V_388 ) {
. V_151 = V_151 ,
. V_183 = V_183 ,
} ;
V_383 = F_379 ( V_3 -> V_9 -> V_82 [ V_398 ] , & V_3 -> V_9 -> V_46 ) ;
V_26 = F_381 ( V_3 , V_383 , & V_387 , V_196 ) ;
return V_26 < 0 ? V_26 : 0 ;
}
int F_384 ( struct V_9 * V_9 , enum V_397 V_398 , T_6 V_151 ,
int V_183 , struct V_385 * V_90 )
{
struct V_83 * V_400 , * V_383 ;
V_383 = V_9 -> V_82 [ V_398 ] ;
if ( V_383 -> V_384 - V_383 -> V_401 > V_402 - 1 )
return - V_306 ;
V_400 = F_385 ( sizeof( * V_383 ) + ( ( V_383 -> V_384 + 1 ) *
sizeof( struct V_388 ) ) , V_32 ) ;
if ( ! V_400 )
return - V_34 ;
memcpy ( V_400 , V_383 , sizeof( * V_383 ) + ( V_383 -> V_384 *
sizeof( struct V_388 ) ) ) ;
F_373 ( V_400 , V_90 , V_151 , V_183 ) ;
F_128 ( V_9 -> V_82 [ V_398 ] , V_400 ) ;
F_129 ( & V_9 -> V_46 ) ;
F_98 ( V_383 ) ;
return 0 ;
}
int F_386 ( struct V_9 * V_9 , enum V_397 V_398 ,
struct V_385 * V_90 )
{
int V_11 , V_26 ;
struct V_83 * V_400 , * V_383 ;
V_383 = V_9 -> V_82 [ V_398 ] ;
V_26 = - V_141 ;
for ( V_11 = 0 ; V_11 < V_383 -> V_384 ; V_11 ++ )
if ( V_383 -> V_387 [ V_11 ] . V_90 == V_90 ) {
V_26 = 0 ;
break;
}
if ( V_26 )
return V_26 ;
V_400 = F_385 ( sizeof( * V_383 ) + ( ( V_383 -> V_384 - 1 ) *
sizeof( struct V_388 ) ) , V_32 ) ;
if ( ! V_400 )
return - V_34 ;
memcpy ( V_400 , V_383 , sizeof( * V_383 ) + V_11 * sizeof( struct V_388 ) ) ;
V_400 -> V_384 -- ;
memcpy ( V_400 -> V_387 + V_11 , V_383 -> V_387 + V_11 + 1 ,
( V_400 -> V_384 - V_11 ) * sizeof( struct V_388 ) ) ;
F_128 ( V_9 -> V_82 [ V_398 ] , V_400 ) ;
F_129 ( & V_9 -> V_46 ) ;
F_98 ( V_383 ) ;
return V_26 ;
}
static int F_387 ( void * V_403 , T_8 * V_196 )
{
unsigned V_145 = ( long ) V_403 ;
struct V_9 * V_9 ;
* V_196 = 0 ;
F_51 ( & V_85 ) ;
F_388 ( V_9 , & V_86 , V_86 )
* V_196 += * ( T_4 * ) ( ( void * ) V_9 + V_145 ) ;
F_53 ( & V_85 ) ;
return 0 ;
}
static int F_389 ( void * V_403 , T_8 * V_196 )
{
unsigned V_145 = ( long ) V_403 ;
struct V_9 * V_9 ;
struct V_2 * V_3 ;
int V_11 ;
* V_196 = 0 ;
F_51 ( & V_85 ) ;
F_388 (kvm, &vm_list, vm_list)
F_20 ( V_11 , V_3 , V_9 )
* V_196 += * ( T_4 * ) ( ( void * ) V_3 + V_145 ) ;
F_53 ( & V_85 ) ;
return 0 ;
}
static int F_390 ( void )
{
int V_26 = - V_132 ;
struct V_404 * V_288 ;
V_405 = F_391 ( L_5 , NULL ) ;
if ( V_405 == NULL )
goto V_118;
for ( V_288 = V_406 ; V_288 -> V_313 ; ++ V_288 ) {
if ( ! F_392 ( V_288 -> V_313 , 0444 , V_405 ,
( void * ) ( long ) V_288 -> V_145 ,
V_407 [ V_288 -> V_408 ] ) )
goto V_409;
}
return 0 ;
V_409:
F_393 ( V_405 ) ;
V_118:
return V_26 ;
}
static int F_394 ( void )
{
if ( V_373 )
F_363 ( NULL ) ;
return 0 ;
}
static void F_395 ( void )
{
if ( V_373 ) {
F_122 ( F_396 ( & V_372 ) ) ;
F_354 ( NULL ) ;
}
}
static inline
struct V_2 * F_397 ( struct V_7 * V_410 )
{
return F_48 ( V_410 , struct V_2 , V_7 ) ;
}
static void F_398 ( struct V_7 * V_410 , int V_4 )
{
struct V_2 * V_3 = F_397 ( V_410 ) ;
if ( V_3 -> V_37 )
V_3 -> V_37 = false ;
F_399 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_400 ( struct V_7 * V_410 ,
struct V_216 * V_411 )
{
struct V_2 * V_3 = F_397 ( V_410 ) ;
if ( V_56 -> V_412 == V_413 )
V_3 -> V_37 = true ;
F_13 ( V_3 ) ;
}
int F_401 ( void * V_414 , unsigned V_415 , unsigned V_416 ,
struct V_417 * V_417 )
{
int V_26 ;
int V_4 ;
V_26 = F_402 ( V_414 ) ;
if ( V_26 )
goto V_418;
V_26 = F_403 () ;
if ( V_26 )
goto V_419;
if ( ! F_19 ( & V_370 , V_32 ) ) {
V_26 = - V_34 ;
goto V_420;
}
V_26 = F_404 () ;
if ( V_26 < 0 )
goto V_421;
F_405 (cpu) {
F_406 ( V_4 ,
V_422 ,
& V_26 , 1 ) ;
if ( V_26 < 0 )
goto V_423;
}
V_26 = F_407 ( & V_424 ) ;
if ( V_26 )
goto V_425;
F_408 ( & V_426 ) ;
if ( ! V_416 )
V_416 = F_409 ( struct V_2 ) ;
V_427 = F_410 ( L_6 , V_415 , V_416 ,
0 , NULL ) ;
if ( ! V_427 ) {
V_26 = - V_34 ;
goto V_428;
}
V_26 = F_411 () ;
if ( V_26 )
goto V_133;
V_429 . V_430 = V_417 ;
V_360 . V_430 = V_417 ;
V_236 . V_430 = V_417 ;
V_26 = F_412 ( & V_431 ) ;
if ( V_26 ) {
F_413 ( L_7 ) ;
goto V_432;
}
F_414 ( & V_433 ) ;
V_240 . V_434 = F_398 ;
V_240 . V_435 = F_400 ;
V_26 = F_390 () ;
if ( V_26 ) {
F_413 ( L_8 ) ;
goto V_436;
}
V_26 = F_415 () ;
F_122 ( V_26 ) ;
return 0 ;
V_436:
F_416 ( & V_433 ) ;
F_417 ( & V_431 ) ;
V_432:
F_418 () ;
V_133:
F_419 ( V_427 ) ;
V_428:
F_420 ( & V_426 ) ;
F_421 ( & V_424 ) ;
V_425:
V_423:
F_422 () ;
V_421:
F_28 ( V_370 ) ;
V_420:
F_423 () ;
V_419:
F_424 () ;
V_418:
return V_26 ;
}
void F_425 ( void )
{
F_393 ( V_405 ) ;
F_417 ( & V_431 ) ;
F_419 ( V_427 ) ;
F_418 () ;
F_416 ( & V_433 ) ;
F_420 ( & V_426 ) ;
F_421 ( & V_424 ) ;
F_367 ( F_363 , NULL , 1 ) ;
F_422 () ;
F_424 () ;
F_423 () ;
F_28 ( V_370 ) ;
F_426 () ;
}
