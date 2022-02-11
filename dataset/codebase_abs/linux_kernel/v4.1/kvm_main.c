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
static void F_71 ( struct V_9 * V_9 )
{
int V_11 ;
struct V_57 * V_58 = V_9 -> V_59 ;
for ( V_11 = 0 ; V_11 < V_60 ; V_11 ++ )
V_58 -> V_61 [ V_11 ] = V_58 -> V_59 [ V_11 ] . V_26 = V_11 ;
}
static struct V_9 * F_72 ( unsigned long type )
{
int V_28 , V_11 ;
struct V_9 * V_9 = F_73 () ;
if ( ! V_9 )
return F_74 ( - V_34 ) ;
V_28 = F_75 ( V_9 , type ) ;
if ( V_28 )
goto V_62;
V_28 = F_76 () ;
if ( V_28 )
goto V_62;
#ifdef F_77
F_78 ( & V_9 -> V_63 ) ;
#endif
F_79 ( V_60 > V_64 ) ;
V_28 = - V_34 ;
V_9 -> V_59 = F_80 ( sizeof( struct V_57 ) ) ;
if ( ! V_9 -> V_59 )
goto V_65;
V_9 -> V_59 -> V_66 = - 150 ;
F_71 ( V_9 ) ;
if ( F_81 ( & V_9 -> V_46 ) )
goto V_65;
if ( F_81 ( & V_9 -> V_67 ) )
goto V_68;
for ( V_11 = 0 ; V_11 < V_69 ; V_11 ++ ) {
V_9 -> V_70 [ V_11 ] = F_82 ( sizeof( struct V_71 ) ,
V_32 ) ;
if ( ! V_9 -> V_70 [ V_11 ] )
goto V_72;
}
F_83 ( & V_9 -> V_47 ) ;
V_9 -> V_42 = V_56 -> V_42 ;
F_84 ( & V_9 -> V_42 -> V_73 ) ;
F_85 ( V_9 ) ;
F_35 ( & V_9 -> V_74 ) ;
F_35 ( & V_9 -> V_75 ) ;
F_35 ( & V_9 -> V_76 ) ;
F_86 ( & V_9 -> V_77 , 1 ) ;
F_87 ( & V_9 -> V_78 ) ;
V_28 = F_69 ( V_9 ) ;
if ( V_28 )
goto V_72;
F_51 ( & V_79 ) ;
F_88 ( & V_9 -> V_80 , & V_80 ) ;
F_53 ( & V_79 ) ;
return V_9 ;
V_72:
F_89 ( & V_9 -> V_67 ) ;
V_68:
F_89 ( & V_9 -> V_46 ) ;
V_65:
F_90 () ;
V_62:
for ( V_11 = 0 ; V_11 < V_69 ; V_11 ++ )
F_91 ( V_9 -> V_70 [ V_11 ] ) ;
F_92 ( V_9 -> V_59 ) ;
F_93 ( V_9 ) ;
return F_74 ( V_28 ) ;
}
void * F_80 ( unsigned long V_81 )
{
if ( V_81 > V_82 )
return F_94 ( V_81 ) ;
else
return F_82 ( V_81 , V_32 ) ;
}
static void F_95 ( struct V_83 * V_84 )
{
if ( ! V_84 -> V_85 )
return;
F_92 ( V_84 -> V_85 ) ;
V_84 -> V_85 = NULL ;
}
static void F_96 ( struct V_9 * V_9 , struct V_83 * free ,
struct V_83 * V_86 )
{
if ( ! V_86 || free -> V_85 != V_86 -> V_85 )
F_95 ( free ) ;
F_97 ( V_9 , free , V_86 ) ;
free -> V_87 = 0 ;
}
static void F_98 ( struct V_9 * V_9 )
{
struct V_57 * V_58 = V_9 -> V_59 ;
struct V_83 * V_84 ;
F_99 (memslot, slots)
F_96 ( V_9 , V_84 , NULL ) ;
F_92 ( V_9 -> V_59 ) ;
}
static void F_100 ( struct V_9 * V_9 )
{
struct V_88 * V_89 , * V_90 ;
F_101 (node, tmp, &kvm->devices) {
struct V_91 * V_92 =
F_102 ( V_89 , struct V_91 , V_93 ) ;
F_103 ( V_89 ) ;
V_92 -> V_54 -> V_94 ( V_92 ) ;
}
}
static void F_104 ( struct V_9 * V_9 )
{
int V_11 ;
struct V_41 * V_42 = V_9 -> V_42 ;
F_105 ( V_9 ) ;
F_51 ( & V_79 ) ;
F_103 ( & V_9 -> V_80 ) ;
F_53 ( & V_79 ) ;
F_106 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_69 ; V_11 ++ )
F_107 ( V_9 -> V_70 [ V_11 ] ) ;
F_108 ( V_9 ) ;
#if F_109 ( V_95 ) && F_109 ( V_96 )
F_110 ( & V_9 -> V_39 , V_9 -> V_42 ) ;
#else
F_68 ( V_9 ) ;
#endif
F_111 ( V_9 ) ;
F_100 ( V_9 ) ;
F_98 ( V_9 ) ;
F_89 ( & V_9 -> V_67 ) ;
F_89 ( & V_9 -> V_46 ) ;
F_93 ( V_9 ) ;
F_90 () ;
F_112 ( V_42 ) ;
}
void F_113 ( struct V_9 * V_9 )
{
F_84 ( & V_9 -> V_77 ) ;
}
void F_114 ( struct V_9 * V_9 )
{
if ( F_115 ( & V_9 -> V_77 ) )
F_104 ( V_9 ) ;
}
static int F_116 ( struct V_97 * V_97 , struct V_98 * V_99 )
{
struct V_9 * V_9 = V_99 -> V_100 ;
F_117 ( V_9 ) ;
F_114 ( V_9 ) ;
return 0 ;
}
static int F_118 ( struct V_83 * V_84 )
{
unsigned long V_101 = 2 * F_119 ( V_84 ) ;
V_84 -> V_85 = F_80 ( V_101 ) ;
if ( ! V_84 -> V_85 )
return - V_34 ;
return 0 ;
}
static void F_120 ( struct V_57 * V_58 ,
struct V_83 * V_102 )
{
int V_26 = V_102 -> V_26 ;
int V_11 = V_58 -> V_61 [ V_26 ] ;
struct V_83 * V_103 = V_58 -> V_59 ;
F_121 ( V_103 [ V_11 ] . V_26 != V_26 ) ;
if ( ! V_102 -> V_87 ) {
F_121 ( ! V_103 [ V_11 ] . V_87 ) ;
V_102 -> V_104 = 0 ;
V_102 -> V_105 = 0 ;
if ( V_103 [ V_11 ] . V_87 )
V_58 -> V_106 -- ;
} else {
if ( ! V_103 [ V_11 ] . V_87 )
V_58 -> V_106 ++ ;
}
while ( V_11 < V_60 - 1 &&
V_102 -> V_104 <= V_103 [ V_11 + 1 ] . V_104 ) {
if ( ! V_103 [ V_11 + 1 ] . V_87 )
break;
V_103 [ V_11 ] = V_103 [ V_11 + 1 ] ;
V_58 -> V_61 [ V_103 [ V_11 ] . V_26 ] = V_11 ;
V_11 ++ ;
}
if ( V_102 -> V_87 ) {
while ( V_11 > 0 &&
V_102 -> V_104 >= V_103 [ V_11 - 1 ] . V_104 ) {
V_103 [ V_11 ] = V_103 [ V_11 - 1 ] ;
V_58 -> V_61 [ V_103 [ V_11 ] . V_26 ] = V_11 ;
V_11 -- ;
}
} else
F_122 ( V_11 != V_58 -> V_106 ) ;
V_103 [ V_11 ] = * V_102 ;
V_58 -> V_61 [ V_103 [ V_11 ] . V_26 ] = V_11 ;
}
static int F_123 ( struct V_107 * V_108 )
{
T_4 V_109 = V_110 ;
#ifdef F_124
V_109 |= V_111 ;
#endif
if ( V_108 -> V_105 & ~ V_109 )
return - V_112 ;
return 0 ;
}
static struct V_57 * F_125 ( struct V_9 * V_9 ,
struct V_57 * V_58 )
{
struct V_57 * V_113 = V_9 -> V_59 ;
F_121 ( V_113 -> V_66 & 1 ) ;
V_58 -> V_66 = V_113 -> V_66 + 1 ;
F_126 ( V_9 -> V_59 , V_58 ) ;
F_127 ( & V_9 -> V_46 ) ;
V_58 -> V_66 ++ ;
F_128 ( V_9 ) ;
return V_113 ;
}
int F_129 ( struct V_9 * V_9 ,
struct V_107 * V_108 )
{
int V_28 ;
T_5 V_104 ;
unsigned long V_87 ;
struct V_83 * V_114 ;
struct V_83 V_115 , V_102 ;
struct V_57 * V_58 = NULL , * V_113 ;
enum V_116 V_117 ;
V_28 = F_123 ( V_108 ) ;
if ( V_28 )
goto V_118;
V_28 = - V_112 ;
if ( V_108 -> V_119 & ( V_82 - 1 ) )
goto V_118;
if ( V_108 -> V_120 & ( V_82 - 1 ) )
goto V_118;
if ( ( V_108 -> V_114 < V_121 ) &&
( ( V_108 -> V_122 & ( V_82 - 1 ) ) ||
! F_130 ( V_123 ,
( void V_124 * ) ( unsigned long ) V_108 -> V_122 ,
V_108 -> V_119 ) ) )
goto V_118;
if ( V_108 -> V_114 >= V_60 )
goto V_118;
if ( V_108 -> V_120 + V_108 -> V_119 < V_108 -> V_120 )
goto V_118;
V_114 = F_131 ( V_9 -> V_59 , V_108 -> V_114 ) ;
V_104 = V_108 -> V_120 >> V_125 ;
V_87 = V_108 -> V_119 >> V_125 ;
if ( V_87 > V_126 )
goto V_118;
if ( ! V_87 )
V_108 -> V_105 &= ~ V_110 ;
V_102 = V_115 = * V_114 ;
V_102 . V_26 = V_108 -> V_114 ;
V_102 . V_104 = V_104 ;
V_102 . V_87 = V_87 ;
V_102 . V_105 = V_108 -> V_105 ;
if ( V_87 ) {
if ( ! V_115 . V_87 )
V_117 = V_127 ;
else {
if ( ( V_108 -> V_122 != V_115 . V_122 ) ||
( V_87 != V_115 . V_87 ) ||
( ( V_102 . V_105 ^ V_115 . V_105 ) & V_111 ) )
goto V_118;
if ( V_104 != V_115 . V_104 )
V_117 = V_128 ;
else if ( V_102 . V_105 != V_115 . V_105 )
V_117 = V_129 ;
else {
V_28 = 0 ;
goto V_118;
}
}
} else if ( V_115 . V_87 ) {
V_117 = V_130 ;
} else
goto V_118;
if ( ( V_117 == V_127 ) || ( V_117 == V_128 ) ) {
V_28 = - V_131 ;
F_99 (slot, kvm->memslots) {
if ( ( V_114 -> V_26 >= V_121 ) ||
( V_114 -> V_26 == V_108 -> V_114 ) )
continue;
if ( ! ( ( V_104 + V_87 <= V_114 -> V_104 ) ||
( V_104 >= V_114 -> V_104 + V_114 -> V_87 ) ) )
goto V_118;
}
}
if ( ! ( V_102 . V_105 & V_110 ) )
V_102 . V_85 = NULL ;
V_28 = - V_34 ;
if ( V_117 == V_127 ) {
V_102 . V_122 = V_108 -> V_122 ;
if ( F_132 ( V_9 , & V_102 , V_87 ) )
goto V_132;
}
if ( ( V_102 . V_105 & V_110 ) && ! V_102 . V_85 ) {
if ( F_118 ( & V_102 ) < 0 )
goto V_132;
}
V_58 = F_80 ( sizeof( struct V_57 ) ) ;
if ( ! V_58 )
goto V_132;
memcpy ( V_58 , V_9 -> V_59 , sizeof( struct V_57 ) ) ;
if ( ( V_117 == V_130 ) || ( V_117 == V_128 ) ) {
V_114 = F_131 ( V_58 , V_108 -> V_114 ) ;
V_114 -> V_105 |= V_133 ;
V_113 = F_125 ( V_9 , V_58 ) ;
F_133 ( V_9 , & V_115 ) ;
F_134 ( V_9 , V_114 ) ;
V_58 = V_113 ;
}
V_28 = F_135 ( V_9 , & V_102 , V_108 , V_117 ) ;
if ( V_28 )
goto V_134;
if ( V_117 == V_130 ) {
V_102 . V_85 = NULL ;
memset ( & V_102 . V_135 , 0 , sizeof( V_102 . V_135 ) ) ;
}
F_120 ( V_58 , & V_102 ) ;
V_113 = F_125 ( V_9 , V_58 ) ;
F_136 ( V_9 , V_108 , & V_115 , V_117 ) ;
F_96 ( V_9 , & V_115 , & V_102 ) ;
F_92 ( V_113 ) ;
if ( ( V_117 == V_127 ) || ( V_117 == V_128 ) ) {
V_28 = F_137 ( V_9 , & V_102 ) ;
return V_28 ;
}
return 0 ;
V_134:
F_92 ( V_58 ) ;
V_132:
F_96 ( V_9 , & V_102 , & V_115 ) ;
V_118:
return V_28 ;
}
int F_138 ( struct V_9 * V_9 ,
struct V_107 * V_108 )
{
int V_28 ;
F_139 ( & V_9 -> V_76 ) ;
V_28 = F_129 ( V_9 , V_108 ) ;
F_16 ( & V_9 -> V_76 ) ;
return V_28 ;
}
static int F_140 ( struct V_9 * V_9 ,
struct V_107 * V_108 )
{
if ( V_108 -> V_114 >= V_121 )
return - V_112 ;
return F_138 ( V_9 , V_108 ) ;
}
int F_141 ( struct V_9 * V_9 ,
struct V_136 * log , int * V_137 )
{
struct V_83 * V_84 ;
int V_28 , V_11 ;
unsigned long V_138 ;
unsigned long V_139 = 0 ;
V_28 = - V_112 ;
if ( log -> V_114 >= V_121 )
goto V_118;
V_84 = F_131 ( V_9 -> V_59 , log -> V_114 ) ;
V_28 = - V_140 ;
if ( ! V_84 -> V_85 )
goto V_118;
V_138 = F_119 ( V_84 ) ;
for ( V_11 = 0 ; ! V_139 && V_11 < V_138 / sizeof( long ) ; ++ V_11 )
V_139 = V_84 -> V_85 [ V_11 ] ;
V_28 = - V_141 ;
if ( F_142 ( log -> V_85 , V_84 -> V_85 , V_138 ) )
goto V_118;
if ( V_139 )
* V_137 = 1 ;
V_28 = 0 ;
V_118:
return V_28 ;
}
int F_143 ( struct V_9 * V_9 ,
struct V_136 * log , bool * V_137 )
{
struct V_83 * V_84 ;
int V_28 , V_11 ;
unsigned long V_138 ;
unsigned long * V_85 ;
unsigned long * V_142 ;
V_28 = - V_112 ;
if ( log -> V_114 >= V_121 )
goto V_118;
V_84 = F_131 ( V_9 -> V_59 , log -> V_114 ) ;
V_85 = V_84 -> V_85 ;
V_28 = - V_140 ;
if ( ! V_85 )
goto V_118;
V_138 = F_119 ( V_84 ) ;
V_142 = V_85 + V_138 / sizeof( long ) ;
memset ( V_142 , 0 , V_138 ) ;
F_51 ( & V_9 -> V_47 ) ;
* V_137 = false ;
for ( V_11 = 0 ; V_11 < V_138 / sizeof( long ) ; V_11 ++ ) {
unsigned long V_143 ;
T_5 V_144 ;
if ( ! V_85 [ V_11 ] )
continue;
* V_137 = true ;
V_143 = F_144 ( & V_85 [ V_11 ] , 0 ) ;
V_142 [ V_11 ] = V_143 ;
if ( V_143 ) {
V_144 = V_11 * V_145 ;
F_145 ( V_9 , V_84 ,
V_144 , V_143 ) ;
}
}
F_53 ( & V_9 -> V_47 ) ;
V_28 = - V_141 ;
if ( F_142 ( log -> V_85 , V_142 , V_138 ) )
goto V_118;
V_28 = 0 ;
V_118:
return V_28 ;
}
bool F_146 ( void )
{
return V_146 ;
}
void F_147 ( void )
{
V_146 = false ;
}
struct V_83 * F_148 ( struct V_9 * V_9 , T_5 V_147 )
{
return F_149 ( V_57 ( V_9 ) , V_147 ) ;
}
int F_150 ( struct V_9 * V_9 , T_5 V_147 )
{
struct V_83 * V_84 = F_148 ( V_9 , V_147 ) ;
if ( ! V_84 || V_84 -> V_26 >= V_121 ||
V_84 -> V_105 & V_133 )
return 0 ;
return 1 ;
}
unsigned long F_151 ( struct V_9 * V_9 , T_5 V_147 )
{
struct V_148 * V_149 ;
unsigned long V_150 , V_81 ;
V_81 = V_82 ;
V_150 = F_152 ( V_9 , V_147 ) ;
if ( F_153 ( V_150 ) )
return V_82 ;
F_154 ( & V_56 -> V_42 -> V_151 ) ;
V_149 = F_155 ( V_56 -> V_42 , V_150 ) ;
if ( ! V_149 )
goto V_118;
V_81 = F_156 ( V_149 ) ;
V_118:
F_157 ( & V_56 -> V_42 -> V_151 ) ;
return V_81 ;
}
static bool F_158 ( struct V_83 * V_114 )
{
return V_114 -> V_105 & V_111 ;
}
static unsigned long F_159 ( struct V_83 * V_114 , T_5 V_147 ,
T_5 * V_152 , bool V_153 )
{
if ( ! V_114 || V_114 -> V_105 & V_133 )
return V_154 ;
if ( F_158 ( V_114 ) && V_153 )
return V_155 ;
if ( V_152 )
* V_152 = V_114 -> V_87 - ( V_147 - V_114 -> V_104 ) ;
return F_160 ( V_114 , V_147 ) ;
}
static unsigned long F_161 ( struct V_83 * V_114 , T_5 V_147 ,
T_5 * V_152 )
{
return F_159 ( V_114 , V_147 , V_152 , true ) ;
}
unsigned long F_162 ( struct V_83 * V_114 ,
T_5 V_147 )
{
return F_161 ( V_114 , V_147 , NULL ) ;
}
unsigned long F_152 ( struct V_9 * V_9 , T_5 V_147 )
{
return F_161 ( F_148 ( V_9 , V_147 ) , V_147 , NULL ) ;
}
unsigned long F_163 ( struct V_83 * V_114 ,
T_5 V_147 , bool * V_156 )
{
unsigned long V_157 = F_159 ( V_114 , V_147 , NULL , false ) ;
if ( ! F_153 ( V_157 ) && V_156 )
* V_156 = ! F_158 ( V_114 ) ;
return V_157 ;
}
unsigned long F_164 ( struct V_9 * V_9 , T_5 V_147 , bool * V_156 )
{
struct V_83 * V_114 = F_148 ( V_9 , V_147 ) ;
return F_163 ( V_114 , V_147 , V_156 ) ;
}
static int F_165 ( struct V_158 * V_159 , struct V_41 * V_42 ,
unsigned long V_50 , int V_153 , struct V_27 * * V_27 )
{
int V_105 = V_160 | V_161 | V_162 | V_163 ;
if ( V_153 )
V_105 |= V_164 ;
return F_166 ( V_159 , V_42 , V_50 , 1 , V_105 , V_27 , NULL , NULL ) ;
}
static inline int F_167 ( unsigned long V_150 )
{
int V_165 , V_105 = V_160 | V_162 | V_164 ;
V_165 = F_166 ( V_56 , V_56 -> V_42 , V_150 , 1 ,
V_105 , NULL , NULL , NULL ) ;
return V_165 == - V_166 ;
}
static bool F_168 ( unsigned long V_150 , bool V_167 , bool * V_168 ,
bool V_169 , bool * V_156 , T_1 * V_1 )
{
struct V_27 * V_27 [ 1 ] ;
int V_87 ;
if ( ! ( V_168 || V_167 ) )
return false ;
if ( ! ( V_169 || V_156 ) )
return false ;
V_87 = F_169 ( V_150 , 1 , 1 , V_27 ) ;
if ( V_87 == 1 ) {
* V_1 = F_170 ( V_27 [ 0 ] ) ;
if ( V_156 )
* V_156 = true ;
return true ;
}
return false ;
}
static int F_171 ( unsigned long V_150 , bool * V_168 , bool V_169 ,
bool * V_156 , T_1 * V_1 )
{
struct V_27 * V_27 [ 1 ] ;
int V_87 = 0 ;
F_172 () ;
if ( V_156 )
* V_156 = V_169 ;
if ( V_168 ) {
F_154 ( & V_56 -> V_42 -> V_151 ) ;
V_87 = F_165 ( V_56 , V_56 -> V_42 ,
V_150 , V_169 , V_27 ) ;
F_157 ( & V_56 -> V_42 -> V_151 ) ;
} else
V_87 = F_173 ( V_56 , V_56 -> V_42 , V_150 , 1 ,
V_169 , 0 , V_27 ,
V_160 | V_162 ) ;
if ( V_87 != 1 )
return V_87 ;
if ( F_25 ( ! V_169 ) && V_156 ) {
struct V_27 * V_170 [ 1 ] ;
V_87 = F_169 ( V_150 , 1 , 1 , V_170 ) ;
if ( V_87 == 1 ) {
* V_156 = true ;
F_174 ( V_27 [ 0 ] ) ;
V_27 [ 0 ] = V_170 [ 0 ] ;
}
V_87 = 1 ;
}
* V_1 = F_170 ( V_27 [ 0 ] ) ;
return V_87 ;
}
static bool F_175 ( struct V_148 * V_149 , bool V_169 )
{
if ( F_25 ( ! ( V_149 -> V_171 & V_172 ) ) )
return false ;
if ( V_169 && ( F_25 ( ! ( V_149 -> V_171 & V_173 ) ) ) )
return false ;
return true ;
}
static T_1 F_176 ( unsigned long V_150 , bool V_167 , bool * V_168 ,
bool V_169 , bool * V_156 )
{
struct V_148 * V_149 ;
T_1 V_1 = 0 ;
int V_87 ;
F_62 ( V_167 && V_168 ) ;
if ( F_168 ( V_150 , V_167 , V_168 , V_169 , V_156 , & V_1 ) )
return V_1 ;
if ( V_167 )
return V_174 ;
V_87 = F_171 ( V_150 , V_168 , V_169 , V_156 , & V_1 ) ;
if ( V_87 == 1 )
return V_1 ;
F_154 ( & V_56 -> V_42 -> V_151 ) ;
if ( V_87 == - V_166 ||
( ! V_168 && F_167 ( V_150 ) ) ) {
V_1 = V_175 ;
goto exit;
}
V_149 = F_177 ( V_56 -> V_42 , V_150 , V_150 + 1 ) ;
if ( V_149 == NULL )
V_1 = V_174 ;
else if ( ( V_149 -> V_171 & V_176 ) ) {
V_1 = ( ( V_150 - V_149 -> V_177 ) >> V_125 ) +
V_149 -> V_178 ;
F_62 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_168 && F_175 ( V_149 , V_169 ) )
* V_168 = true ;
V_1 = V_174 ;
}
exit:
F_157 ( & V_56 -> V_42 -> V_151 ) ;
return V_1 ;
}
static T_1
F_178 ( struct V_83 * V_114 , T_5 V_147 , bool V_167 ,
bool * V_168 , bool V_169 , bool * V_156 )
{
unsigned long V_150 = F_159 ( V_114 , V_147 , NULL , V_169 ) ;
if ( V_150 == V_155 )
return V_179 ;
if ( F_153 ( V_150 ) )
return V_180 ;
if ( V_156 && F_158 ( V_114 ) ) {
* V_156 = false ;
V_156 = NULL ;
}
return F_176 ( V_150 , V_167 , V_168 , V_169 ,
V_156 ) ;
}
static T_1 F_179 ( struct V_9 * V_9 , T_5 V_147 , bool V_167 , bool * V_168 ,
bool V_169 , bool * V_156 )
{
struct V_83 * V_114 ;
if ( V_168 )
* V_168 = false ;
V_114 = F_148 ( V_9 , V_147 ) ;
return F_178 ( V_114 , V_147 , V_167 , V_168 , V_169 ,
V_156 ) ;
}
T_1 F_180 ( struct V_9 * V_9 , T_5 V_147 )
{
return F_179 ( V_9 , V_147 , true , NULL , true , NULL ) ;
}
T_1 F_181 ( struct V_9 * V_9 , T_5 V_147 , bool * V_168 ,
bool V_169 , bool * V_156 )
{
return F_179 ( V_9 , V_147 , false , V_168 , V_169 , V_156 ) ;
}
T_1 F_182 ( struct V_9 * V_9 , T_5 V_147 )
{
return F_179 ( V_9 , V_147 , false , NULL , true , NULL ) ;
}
T_1 F_183 ( struct V_9 * V_9 , T_5 V_147 , bool V_169 ,
bool * V_156 )
{
return F_179 ( V_9 , V_147 , false , NULL , V_169 , V_156 ) ;
}
T_1 F_184 ( struct V_83 * V_114 , T_5 V_147 )
{
return F_178 ( V_114 , V_147 , false , NULL , true , NULL ) ;
}
T_1 F_185 ( struct V_83 * V_114 , T_5 V_147 )
{
return F_178 ( V_114 , V_147 , true , NULL , true , NULL ) ;
}
int F_186 ( struct V_9 * V_9 , T_5 V_147 , struct V_27 * * V_181 ,
int V_152 )
{
unsigned long V_150 ;
T_5 V_182 ;
V_150 = F_161 ( F_148 ( V_9 , V_147 ) , V_147 , & V_182 ) ;
if ( F_153 ( V_150 ) )
return - 1 ;
if ( V_182 < V_152 )
return 0 ;
return F_169 ( V_150 , V_152 , 1 , V_181 ) ;
}
static struct V_27 * F_187 ( T_1 V_1 )
{
if ( F_188 ( V_1 ) )
return V_183 ;
if ( F_1 ( V_1 ) ) {
F_121 ( 1 ) ;
return V_183 ;
}
return F_4 ( V_1 ) ;
}
struct V_27 * F_189 ( struct V_9 * V_9 , T_5 V_147 )
{
T_1 V_1 ;
V_1 = F_182 ( V_9 , V_147 ) ;
return F_187 ( V_1 ) ;
}
void F_190 ( struct V_27 * V_27 )
{
F_121 ( F_191 ( V_27 ) ) ;
F_192 ( F_170 ( V_27 ) ) ;
}
void F_192 ( T_1 V_1 )
{
if ( ! F_188 ( V_1 ) && ! F_1 ( V_1 ) )
F_174 ( F_4 ( V_1 ) ) ;
}
void F_193 ( struct V_27 * V_27 )
{
F_121 ( F_191 ( V_27 ) ) ;
F_194 ( F_170 ( V_27 ) ) ;
}
static void F_194 ( T_1 V_1 )
{
F_195 ( V_1 ) ;
F_192 ( V_1 ) ;
}
void F_195 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_27 * V_27 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_27 ) )
F_196 ( V_27 ) ;
}
}
void F_197 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_198 ( F_4 ( V_1 ) ) ;
}
void F_199 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_200 ( F_4 ( V_1 ) ) ;
}
static int F_201 ( unsigned long V_184 , int V_144 )
{
if ( V_184 > V_82 - V_144 )
return V_82 - V_144 ;
else
return V_184 ;
}
int F_202 ( struct V_9 * V_9 , T_5 V_147 , void * V_185 , int V_144 ,
int V_184 )
{
int V_28 ;
unsigned long V_150 ;
V_150 = F_164 ( V_9 , V_147 , NULL ) ;
if ( F_153 ( V_150 ) )
return - V_141 ;
V_28 = F_203 ( V_185 , ( void V_124 * ) V_150 + V_144 , V_184 ) ;
if ( V_28 )
return - V_141 ;
return 0 ;
}
int F_204 ( struct V_9 * V_9 , T_6 V_186 , void * V_185 , unsigned long V_184 )
{
T_5 V_147 = V_186 >> V_125 ;
int V_187 ;
int V_144 = F_205 ( V_186 ) ;
int V_188 ;
while ( ( V_187 = F_201 ( V_184 , V_144 ) ) != 0 ) {
V_188 = F_202 ( V_9 , V_147 , V_185 , V_144 , V_187 ) ;
if ( V_188 < 0 )
return V_188 ;
V_144 = 0 ;
V_184 -= V_187 ;
V_185 += V_187 ;
++ V_147 ;
}
return 0 ;
}
int F_206 ( struct V_9 * V_9 , T_6 V_186 , void * V_185 ,
unsigned long V_184 )
{
int V_28 ;
unsigned long V_150 ;
T_5 V_147 = V_186 >> V_125 ;
int V_144 = F_205 ( V_186 ) ;
V_150 = F_164 ( V_9 , V_147 , NULL ) ;
if ( F_153 ( V_150 ) )
return - V_141 ;
F_207 () ;
V_28 = F_208 ( V_185 , ( void V_124 * ) V_150 + V_144 , V_184 ) ;
F_209 () ;
if ( V_28 )
return - V_141 ;
return 0 ;
}
int F_210 ( struct V_9 * V_9 , T_5 V_147 , const void * V_185 ,
int V_144 , int V_184 )
{
int V_28 ;
unsigned long V_150 ;
V_150 = F_152 ( V_9 , V_147 ) ;
if ( F_153 ( V_150 ) )
return - V_141 ;
V_28 = F_211 ( ( void V_124 * ) V_150 + V_144 , V_185 , V_184 ) ;
if ( V_28 )
return - V_141 ;
F_212 ( V_9 , V_147 ) ;
return 0 ;
}
int F_213 ( struct V_9 * V_9 , T_6 V_186 , const void * V_185 ,
unsigned long V_184 )
{
T_5 V_147 = V_186 >> V_125 ;
int V_187 ;
int V_144 = F_205 ( V_186 ) ;
int V_188 ;
while ( ( V_187 = F_201 ( V_184 , V_144 ) ) != 0 ) {
V_188 = F_210 ( V_9 , V_147 , V_185 , V_144 , V_187 ) ;
if ( V_188 < 0 )
return V_188 ;
V_144 = 0 ;
V_184 -= V_187 ;
V_185 += V_187 ;
++ V_147 ;
}
return 0 ;
}
int F_214 ( struct V_9 * V_9 , struct V_189 * V_190 ,
T_6 V_186 , unsigned long V_184 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_144 = F_205 ( V_186 ) ;
T_5 V_191 = V_186 >> V_125 ;
T_5 V_192 = ( V_186 + V_184 - 1 ) >> V_125 ;
T_5 V_193 = V_192 - V_191 + 1 ;
T_5 V_194 ;
V_190 -> V_186 = V_186 ;
V_190 -> V_66 = V_58 -> V_66 ;
V_190 -> V_184 = V_184 ;
V_190 -> V_84 = F_148 ( V_9 , V_191 ) ;
V_190 -> V_157 = F_161 ( V_190 -> V_84 , V_191 , NULL ) ;
if ( ! F_153 ( V_190 -> V_157 ) && V_193 <= 1 ) {
V_190 -> V_157 += V_144 ;
} else {
while ( V_191 <= V_192 ) {
V_190 -> V_84 = F_148 ( V_9 , V_191 ) ;
V_190 -> V_157 = F_161 ( V_190 -> V_84 , V_191 ,
& V_194 ) ;
if ( F_153 ( V_190 -> V_157 ) )
return - V_141 ;
V_191 += V_194 ;
}
V_190 -> V_84 = NULL ;
}
return 0 ;
}
int F_215 ( struct V_9 * V_9 , struct V_189 * V_190 ,
void * V_185 , unsigned long V_184 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_28 ;
F_62 ( V_184 > V_190 -> V_184 ) ;
if ( V_58 -> V_66 != V_190 -> V_66 )
F_214 ( V_9 , V_190 , V_190 -> V_186 , V_190 -> V_184 ) ;
if ( F_25 ( ! V_190 -> V_84 ) )
return F_213 ( V_9 , V_190 -> V_186 , V_185 , V_184 ) ;
if ( F_153 ( V_190 -> V_157 ) )
return - V_141 ;
V_28 = F_211 ( ( void V_124 * ) V_190 -> V_157 , V_185 , V_184 ) ;
if ( V_28 )
return - V_141 ;
F_216 ( V_9 , V_190 -> V_84 , V_190 -> V_186 >> V_125 ) ;
return 0 ;
}
int F_217 ( struct V_9 * V_9 , struct V_189 * V_190 ,
void * V_185 , unsigned long V_184 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_28 ;
F_62 ( V_184 > V_190 -> V_184 ) ;
if ( V_58 -> V_66 != V_190 -> V_66 )
F_214 ( V_9 , V_190 , V_190 -> V_186 , V_190 -> V_184 ) ;
if ( F_25 ( ! V_190 -> V_84 ) )
return F_204 ( V_9 , V_190 -> V_186 , V_185 , V_184 ) ;
if ( F_153 ( V_190 -> V_157 ) )
return - V_141 ;
V_28 = F_203 ( V_185 , ( void V_124 * ) V_190 -> V_157 , V_184 ) ;
if ( V_28 )
return - V_141 ;
return 0 ;
}
int F_218 ( struct V_9 * V_9 , T_5 V_147 , int V_144 , int V_184 )
{
const void * V_195 = ( const void * ) F_219 ( F_220 ( F_221 ( 0 ) ) ) ;
return F_210 ( V_9 , V_147 , V_195 , V_144 , V_184 ) ;
}
int F_222 ( struct V_9 * V_9 , T_6 V_186 , unsigned long V_184 )
{
T_5 V_147 = V_186 >> V_125 ;
int V_187 ;
int V_144 = F_205 ( V_186 ) ;
int V_188 ;
while ( ( V_187 = F_201 ( V_184 , V_144 ) ) != 0 ) {
V_188 = F_218 ( V_9 , V_147 , V_144 , V_187 ) ;
if ( V_188 < 0 )
return V_188 ;
V_144 = 0 ;
V_184 -= V_187 ;
++ V_147 ;
}
return 0 ;
}
static void F_216 ( struct V_9 * V_9 ,
struct V_83 * V_84 ,
T_5 V_147 )
{
if ( V_84 && V_84 -> V_85 ) {
unsigned long V_196 = V_147 - V_84 -> V_104 ;
F_223 ( V_196 , V_84 -> V_85 ) ;
}
}
void F_212 ( struct V_9 * V_9 , T_5 V_147 )
{
struct V_83 * V_84 ;
V_84 = F_148 ( V_9 , V_147 ) ;
F_216 ( V_9 , V_84 , V_147 ) ;
}
static int F_224 ( struct V_2 * V_3 )
{
if ( F_225 ( V_3 ) ) {
F_21 ( V_197 , V_3 ) ;
return - V_6 ;
}
if ( F_226 ( V_3 ) )
return - V_6 ;
if ( F_227 ( V_56 ) )
return - V_6 ;
return 0 ;
}
void F_228 ( struct V_2 * V_3 )
{
T_7 V_50 , V_198 ;
F_229 ( V_199 ) ;
bool V_200 = false ;
V_50 = V_198 = F_230 () ;
if ( V_201 ) {
T_7 V_202 = F_231 ( F_230 () , V_201 ) ;
do {
if ( F_224 ( V_3 ) < 0 ) {
++ V_3 -> V_21 . V_203 ;
goto V_118;
}
V_198 = F_230 () ;
} while ( F_232 () && F_233 ( V_198 , V_202 ) );
}
for (; ; ) {
F_234 ( & V_3 -> V_31 , & V_199 , V_204 ) ;
if ( F_224 ( V_3 ) < 0 )
break;
V_200 = true ;
F_235 () ;
}
F_236 ( & V_3 -> V_31 , & V_199 ) ;
V_198 = F_230 () ;
V_118:
F_237 ( F_238 ( V_198 ) - F_238 ( V_50 ) , V_200 ) ;
}
void F_239 ( struct V_2 * V_3 )
{
int V_12 ;
int V_4 = V_3 -> V_4 ;
T_8 * V_205 ;
V_205 = F_240 ( V_3 ) ;
if ( F_241 ( V_205 ) ) {
F_242 ( V_205 ) ;
++ V_3 -> V_21 . V_206 ;
}
V_12 = F_7 () ;
if ( V_4 != V_12 && ( unsigned ) V_4 < V_207 && F_243 ( V_4 ) )
if ( F_244 ( V_3 ) )
F_245 ( V_4 ) ;
F_10 () ;
}
int F_246 ( struct V_2 * V_208 )
{
struct V_30 * V_30 ;
struct V_158 * V_209 = NULL ;
int V_188 = 0 ;
F_247 () ;
V_30 = F_248 ( V_208 -> V_30 ) ;
if ( V_30 )
V_209 = F_249 ( V_30 , V_210 ) ;
F_250 () ;
if ( ! V_209 )
return V_188 ;
V_188 = F_251 ( V_209 , 1 ) ;
F_252 ( V_209 ) ;
return V_188 ;
}
static bool F_253 ( struct V_2 * V_3 )
{
#ifdef F_254
bool V_211 ;
V_211 = ! V_3 -> V_212 . V_213 ||
V_3 -> V_212 . V_214 ;
if ( V_3 -> V_212 . V_213 )
F_41 ( V_3 , ! V_3 -> V_212 . V_214 ) ;
return V_211 ;
#else
return true ;
#endif
}
void F_255 ( struct V_2 * V_12 )
{
struct V_9 * V_9 = V_12 -> V_9 ;
struct V_2 * V_3 ;
int V_215 = V_12 -> V_9 -> V_215 ;
int V_216 = 0 ;
int V_217 = 3 ;
int V_218 ;
int V_11 ;
F_40 ( V_12 , true ) ;
for ( V_218 = 0 ; V_218 < 2 && ! V_216 && V_217 ; V_218 ++ ) {
F_20 (i, vcpu, kvm) {
if ( ! V_218 && V_11 <= V_215 ) {
V_11 = V_215 ;
continue;
} else if ( V_218 && V_11 > V_215 )
break;
if ( ! F_256 ( V_3 -> V_37 ) )
continue;
if ( V_3 == V_12 )
continue;
if ( F_241 ( & V_3 -> V_31 ) && ! F_225 ( V_3 ) )
continue;
if ( ! F_253 ( V_3 ) )
continue;
V_216 = F_246 ( V_3 ) ;
if ( V_216 > 0 ) {
V_9 -> V_215 = V_11 ;
break;
} else if ( V_216 < 0 ) {
V_217 -- ;
if ( ! V_217 )
break;
}
}
}
F_40 ( V_12 , false ) ;
F_41 ( V_12 , false ) ;
}
static int F_257 ( struct V_148 * V_149 , struct V_219 * V_220 )
{
struct V_2 * V_3 = V_149 -> V_221 -> V_100 ;
struct V_27 * V_27 ;
if ( V_220 -> V_222 == 0 )
V_27 = F_258 ( V_3 -> V_36 ) ;
#ifdef F_259
else if ( V_220 -> V_222 == V_223 )
V_27 = F_258 ( V_3 -> V_135 . V_224 ) ;
#endif
#ifdef F_260
else if ( V_220 -> V_222 == F_260 )
V_27 = F_258 ( V_3 -> V_9 -> V_225 ) ;
#endif
else
return F_261 ( V_3 , V_220 ) ;
F_200 ( V_27 ) ;
V_220 -> V_27 = V_27 ;
return 0 ;
}
static int F_262 ( struct V_98 * V_98 , struct V_148 * V_149 )
{
V_149 -> V_226 = & V_227 ;
return 0 ;
}
static int F_263 ( struct V_97 * V_97 , struct V_98 * V_99 )
{
struct V_2 * V_3 = V_99 -> V_100 ;
F_114 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_264 ( struct V_2 * V_3 )
{
return F_265 ( L_1 , & V_228 , V_3 , V_229 | V_230 ) ;
}
static int F_266 ( struct V_9 * V_9 , T_4 V_26 )
{
int V_28 ;
struct V_2 * V_3 , * V_231 ;
if ( V_26 >= V_232 )
return - V_112 ;
V_3 = F_267 ( V_9 , V_26 ) ;
if ( F_268 ( V_3 ) )
return F_269 ( V_3 ) ;
F_270 ( & V_3 -> V_7 , & V_233 ) ;
V_28 = F_271 ( V_3 ) ;
if ( V_28 )
goto V_234;
F_139 ( & V_9 -> V_74 ) ;
if ( ! F_272 ( V_3 ) ) {
V_28 = - V_112 ;
goto V_235;
}
if ( F_273 ( & V_9 -> V_236 ) == V_232 ) {
V_28 = - V_112 ;
goto V_235;
}
F_20 (r, v, kvm)
if ( V_231 -> V_29 == V_26 ) {
V_28 = - V_131 ;
goto V_235;
}
F_62 ( V_9 -> V_237 [ F_273 ( & V_9 -> V_236 ) ] ) ;
F_113 ( V_9 ) ;
V_28 = F_264 ( V_3 ) ;
if ( V_28 < 0 ) {
F_114 ( V_9 ) ;
goto V_235;
}
V_9 -> V_237 [ F_273 ( & V_9 -> V_236 ) ] = V_3 ;
F_61 () ;
F_84 ( & V_9 -> V_236 ) ;
F_16 ( & V_9 -> V_74 ) ;
F_274 ( V_3 ) ;
return V_28 ;
V_235:
F_16 ( & V_9 -> V_74 ) ;
V_234:
F_275 ( V_3 ) ;
return V_28 ;
}
static int F_276 ( struct V_2 * V_3 , T_9 * V_238 )
{
if ( V_238 ) {
F_277 ( V_238 , F_278 ( V_239 ) | F_278 ( V_240 ) ) ;
V_3 -> V_241 = 1 ;
V_3 -> V_238 = * V_238 ;
} else
V_3 -> V_241 = 0 ;
return 0 ;
}
static long F_279 ( struct V_98 * V_99 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_2 * V_3 = V_99 -> V_100 ;
void V_124 * V_244 = ( void V_124 * ) V_243 ;
int V_28 ;
struct V_245 * V_246 = NULL ;
struct V_247 * V_247 = NULL ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_248 ;
if ( F_25 ( F_280 ( V_242 ) != V_249 ) )
return - V_112 ;
#if F_109 ( V_250 ) || F_109 ( V_251 ) || F_109 ( V_252 )
if ( V_242 == V_253 || V_242 == V_254 || V_242 == V_255 )
return F_281 ( V_99 , V_242 , V_243 ) ;
#endif
V_28 = F_5 ( V_3 ) ;
if ( V_28 )
return V_28 ;
switch ( V_242 ) {
case V_256 :
V_28 = - V_112 ;
if ( V_243 )
goto V_118;
if ( F_25 ( V_3 -> V_30 != V_56 -> V_257 [ V_210 ] . V_30 ) ) {
struct V_30 * V_258 = V_3 -> V_30 ;
struct V_30 * V_259 = F_282 ( V_56 , V_210 ) ;
F_126 ( V_3 -> V_30 , V_259 ) ;
if ( V_258 )
F_283 () ;
F_45 ( V_258 ) ;
}
V_28 = F_284 ( V_3 , V_3 -> V_36 ) ;
F_285 ( V_3 -> V_36 -> V_260 , V_28 ) ;
break;
case V_261 : {
struct V_262 * V_262 ;
V_28 = - V_34 ;
V_262 = F_82 ( sizeof( struct V_262 ) , V_32 ) ;
if ( ! V_262 )
goto V_118;
V_28 = F_286 ( V_3 , V_262 ) ;
if ( V_28 )
goto V_263;
V_28 = - V_141 ;
if ( F_142 ( V_244 , V_262 , sizeof( struct V_262 ) ) )
goto V_263;
V_28 = 0 ;
V_263:
F_91 ( V_262 ) ;
break;
}
case V_264 : {
struct V_262 * V_262 ;
V_28 = - V_34 ;
V_262 = F_287 ( V_244 , sizeof( * V_262 ) ) ;
if ( F_268 ( V_262 ) ) {
V_28 = F_269 ( V_262 ) ;
goto V_118;
}
V_28 = F_288 ( V_3 , V_262 ) ;
F_91 ( V_262 ) ;
break;
}
case V_265 : {
V_247 = F_82 ( sizeof( struct V_247 ) , V_32 ) ;
V_28 = - V_34 ;
if ( ! V_247 )
goto V_118;
V_28 = F_289 ( V_3 , V_247 ) ;
if ( V_28 )
goto V_118;
V_28 = - V_141 ;
if ( F_142 ( V_244 , V_247 , sizeof( struct V_247 ) ) )
goto V_118;
V_28 = 0 ;
break;
}
case V_266 : {
V_247 = F_287 ( V_244 , sizeof( * V_247 ) ) ;
if ( F_268 ( V_247 ) ) {
V_28 = F_269 ( V_247 ) ;
V_247 = NULL ;
goto V_118;
}
V_28 = F_290 ( V_3 , V_247 ) ;
break;
}
case V_267 : {
struct V_268 V_269 ;
V_28 = F_291 ( V_3 , & V_269 ) ;
if ( V_28 )
goto V_118;
V_28 = - V_141 ;
if ( F_142 ( V_244 , & V_269 , sizeof( V_269 ) ) )
goto V_118;
V_28 = 0 ;
break;
}
case V_270 : {
struct V_268 V_269 ;
V_28 = - V_141 ;
if ( F_292 ( & V_269 , V_244 , sizeof( V_269 ) ) )
goto V_118;
V_28 = F_293 ( V_3 , & V_269 ) ;
break;
}
case V_271 : {
struct V_272 V_273 ;
V_28 = - V_141 ;
if ( F_292 ( & V_273 , V_244 , sizeof( V_273 ) ) )
goto V_118;
V_28 = F_294 ( V_3 , & V_273 ) ;
if ( V_28 )
goto V_118;
V_28 = - V_141 ;
if ( F_142 ( V_244 , & V_273 , sizeof( V_273 ) ) )
goto V_118;
V_28 = 0 ;
break;
}
case V_274 : {
struct V_275 V_276 ;
V_28 = - V_141 ;
if ( F_292 ( & V_276 , V_244 , sizeof( V_276 ) ) )
goto V_118;
V_28 = F_295 ( V_3 , & V_276 ) ;
break;
}
case V_277 : {
struct V_278 V_124 * V_279 = V_244 ;
struct V_278 V_280 ;
T_9 V_238 , * V_281 ;
V_281 = NULL ;
if ( V_244 ) {
V_28 = - V_141 ;
if ( F_292 ( & V_280 , V_244 ,
sizeof( V_280 ) ) )
goto V_118;
V_28 = - V_112 ;
if ( V_280 . V_184 != sizeof( V_238 ) )
goto V_118;
V_28 = - V_141 ;
if ( F_292 ( & V_238 , V_279 -> V_238 ,
sizeof( V_238 ) ) )
goto V_118;
V_281 = & V_238 ;
}
V_28 = F_276 ( V_3 , V_281 ) ;
break;
}
case V_282 : {
V_246 = F_82 ( sizeof( struct V_245 ) , V_32 ) ;
V_28 = - V_34 ;
if ( ! V_246 )
goto V_118;
V_28 = F_296 ( V_3 , V_246 ) ;
if ( V_28 )
goto V_118;
V_28 = - V_141 ;
if ( F_142 ( V_244 , V_246 , sizeof( struct V_245 ) ) )
goto V_118;
V_28 = 0 ;
break;
}
case V_283 : {
V_246 = F_287 ( V_244 , sizeof( * V_246 ) ) ;
if ( F_268 ( V_246 ) ) {
V_28 = F_269 ( V_246 ) ;
V_246 = NULL ;
goto V_118;
}
V_28 = F_297 ( V_3 , V_246 ) ;
break;
}
default:
V_28 = F_281 ( V_99 , V_242 , V_243 ) ;
}
V_118:
F_11 ( V_3 ) ;
F_91 ( V_246 ) ;
F_91 ( V_247 ) ;
return V_28 ;
}
static long F_298 ( struct V_98 * V_99 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_2 * V_3 = V_99 -> V_100 ;
void V_124 * V_244 = F_299 ( V_243 ) ;
int V_28 ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_248 ;
switch ( V_242 ) {
case V_277 : {
struct V_278 V_124 * V_279 = V_244 ;
struct V_278 V_280 ;
T_10 V_284 ;
T_9 V_238 ;
if ( V_244 ) {
V_28 = - V_141 ;
if ( F_292 ( & V_280 , V_244 ,
sizeof( V_280 ) ) )
goto V_118;
V_28 = - V_112 ;
if ( V_280 . V_184 != sizeof( V_284 ) )
goto V_118;
V_28 = - V_141 ;
if ( F_292 ( & V_284 , V_279 -> V_238 ,
sizeof( V_284 ) ) )
goto V_118;
F_300 ( & V_238 , & V_284 ) ;
V_28 = F_276 ( V_3 , & V_238 ) ;
} else
V_28 = F_276 ( V_3 , NULL ) ;
break;
}
default:
V_28 = F_279 ( V_99 , V_242 , V_243 ) ;
}
V_118:
return V_28 ;
}
static int F_301 ( struct V_91 * V_92 ,
int (* F_302)( struct V_91 * V_92 ,
struct V_285 * V_286 ) ,
unsigned long V_243 )
{
struct V_285 V_286 ;
if ( ! F_302 )
return - V_287 ;
if ( F_292 ( & V_286 , ( void V_124 * ) V_243 , sizeof( V_286 ) ) )
return - V_141 ;
return F_302 ( V_92 , & V_286 ) ;
}
static long F_303 ( struct V_98 * V_99 , unsigned int V_242 ,
unsigned long V_243 )
{
struct V_91 * V_92 = V_99 -> V_100 ;
switch ( V_242 ) {
case V_288 :
return F_301 ( V_92 , V_92 -> V_54 -> V_289 , V_243 ) ;
case V_290 :
return F_301 ( V_92 , V_92 -> V_54 -> V_291 , V_243 ) ;
case V_292 :
return F_301 ( V_92 , V_92 -> V_54 -> V_293 , V_243 ) ;
default:
if ( V_92 -> V_54 -> V_242 )
return V_92 -> V_54 -> V_242 ( V_92 , V_242 , V_243 ) ;
return - V_294 ;
}
}
static int F_304 ( struct V_97 * V_97 , struct V_98 * V_99 )
{
struct V_91 * V_92 = V_99 -> V_100 ;
struct V_9 * V_9 = V_92 -> V_9 ;
F_114 ( V_9 ) ;
return 0 ;
}
struct V_91 * F_305 ( struct V_98 * V_99 )
{
if ( V_99 -> V_295 != & V_296 )
return NULL ;
return V_99 -> V_100 ;
}
int F_306 ( struct V_297 * V_54 , T_4 type )
{
if ( type >= F_307 ( V_298 ) )
return - V_299 ;
if ( V_298 [ type ] != NULL )
return - V_131 ;
V_298 [ type ] = V_54 ;
return 0 ;
}
void F_308 ( T_4 type )
{
if ( V_298 [ type ] != NULL )
V_298 [ type ] = NULL ;
}
static int F_309 ( struct V_9 * V_9 ,
struct V_300 * V_301 )
{
struct V_297 * V_54 = NULL ;
struct V_91 * V_92 ;
bool V_302 = V_301 -> V_105 & V_303 ;
int V_188 ;
if ( V_301 -> type >= F_307 ( V_298 ) )
return - V_304 ;
V_54 = V_298 [ V_301 -> type ] ;
if ( V_54 == NULL )
return - V_304 ;
if ( V_302 )
return 0 ;
V_92 = F_82 ( sizeof( * V_92 ) , V_32 ) ;
if ( ! V_92 )
return - V_34 ;
V_92 -> V_54 = V_54 ;
V_92 -> V_9 = V_9 ;
V_188 = V_54 -> V_305 ( V_92 , V_301 -> type ) ;
if ( V_188 < 0 ) {
F_91 ( V_92 ) ;
return V_188 ;
}
V_188 = F_265 ( V_54 -> V_306 , & V_296 , V_92 , V_229 | V_230 ) ;
if ( V_188 < 0 ) {
V_54 -> V_94 ( V_92 ) ;
return V_188 ;
}
F_88 ( & V_92 -> V_93 , & V_9 -> V_78 ) ;
F_113 ( V_9 ) ;
V_301 -> V_307 = V_188 ;
return 0 ;
}
static long F_310 ( struct V_9 * V_9 , long V_243 )
{
switch ( V_243 ) {
case V_308 :
case V_309 :
case V_310 :
#ifdef F_311
case V_311 :
#endif
case V_312 :
#ifdef F_312
case V_313 :
#endif
#ifdef F_77
case V_314 :
case V_315 :
#endif
case V_316 :
return 1 ;
#ifdef F_313
case V_317 :
return V_318 ;
#endif
default:
break;
}
return F_314 ( V_9 , V_243 ) ;
}
static long F_315 ( struct V_98 * V_99 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_9 * V_9 = V_99 -> V_100 ;
void V_124 * V_244 = ( void V_124 * ) V_243 ;
int V_28 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_248 ;
switch ( V_242 ) {
case V_319 :
V_28 = F_266 ( V_9 , V_243 ) ;
break;
case V_320 : {
struct V_107 V_321 ;
V_28 = - V_141 ;
if ( F_292 ( & V_321 , V_244 ,
sizeof( V_321 ) ) )
goto V_118;
V_28 = F_140 ( V_9 , & V_321 ) ;
break;
}
case V_322 : {
struct V_136 log ;
V_28 = - V_141 ;
if ( F_292 ( & log , V_244 , sizeof( log ) ) )
goto V_118;
V_28 = F_316 ( V_9 , & log ) ;
break;
}
#ifdef F_260
case V_323 : {
struct V_324 V_325 ;
V_28 = - V_141 ;
if ( F_292 ( & V_325 , V_244 , sizeof( V_325 ) ) )
goto V_118;
V_28 = F_317 ( V_9 , & V_325 ) ;
break;
}
case V_326 : {
struct V_324 V_325 ;
V_28 = - V_141 ;
if ( F_292 ( & V_325 , V_244 , sizeof( V_325 ) ) )
goto V_118;
V_28 = F_318 ( V_9 , & V_325 ) ;
break;
}
#endif
case V_327 : {
struct V_328 V_185 ;
V_28 = - V_141 ;
if ( F_292 ( & V_185 , V_244 , sizeof( V_185 ) ) )
goto V_118;
V_28 = V_328 ( V_9 , & V_185 ) ;
break;
}
case V_329 : {
struct V_330 V_185 ;
V_28 = - V_141 ;
if ( F_292 ( & V_185 , V_244 , sizeof( V_185 ) ) )
goto V_118;
V_28 = V_330 ( V_9 , & V_185 ) ;
break;
}
#ifdef F_311
case V_331 :
V_28 = 0 ;
F_139 ( & V_9 -> V_74 ) ;
if ( F_273 ( & V_9 -> V_236 ) != 0 )
V_28 = - V_332 ;
else
V_9 -> V_333 = V_243 ;
F_16 ( & V_9 -> V_74 ) ;
break;
#endif
#ifdef F_312
case V_334 : {
struct V_335 V_336 ;
V_28 = - V_141 ;
if ( F_292 ( & V_336 , V_244 , sizeof( V_336 ) ) )
goto V_118;
V_28 = F_319 ( V_9 , & V_336 ) ;
break;
}
#endif
#ifdef F_320
case V_337 :
case V_338 : {
struct V_339 V_340 ;
V_28 = - V_141 ;
if ( F_292 ( & V_340 , V_244 , sizeof( V_340 ) ) )
goto V_118;
V_28 = F_321 ( V_9 , & V_340 ,
V_242 == V_337 ) ;
if ( V_28 )
goto V_118;
V_28 = - V_141 ;
if ( V_242 == V_337 ) {
if ( F_142 ( V_244 , & V_340 , sizeof( V_340 ) ) )
goto V_118;
}
V_28 = 0 ;
break;
}
#endif
#ifdef F_313
case V_341 : {
struct V_342 V_343 ;
struct V_342 V_124 * V_344 ;
struct V_345 * V_346 ;
V_28 = - V_141 ;
if ( F_292 ( & V_343 , V_244 , sizeof( V_343 ) ) )
goto V_118;
V_28 = - V_112 ;
if ( V_343 . V_347 >= V_318 )
goto V_118;
if ( V_343 . V_105 )
goto V_118;
V_28 = - V_34 ;
V_346 = F_322 ( V_343 . V_347 * sizeof( * V_346 ) ) ;
if ( ! V_346 )
goto V_118;
V_28 = - V_141 ;
V_344 = V_244 ;
if ( F_292 ( V_346 , V_344 -> V_346 ,
V_343 . V_347 * sizeof( * V_346 ) ) )
goto V_348;
V_28 = F_323 ( V_9 , V_346 , V_343 . V_347 ,
V_343 . V_105 ) ;
V_348:
F_324 ( V_346 ) ;
break;
}
#endif
case V_349 : {
struct V_300 V_301 ;
V_28 = - V_141 ;
if ( F_292 ( & V_301 , V_244 , sizeof( V_301 ) ) )
goto V_118;
V_28 = F_309 ( V_9 , & V_301 ) ;
if ( V_28 )
goto V_118;
V_28 = - V_141 ;
if ( F_142 ( V_244 , & V_301 , sizeof( V_301 ) ) )
goto V_118;
V_28 = 0 ;
break;
}
case V_350 :
V_28 = F_310 ( V_9 , V_243 ) ;
break;
default:
V_28 = F_325 ( V_99 , V_242 , V_243 ) ;
}
V_118:
return V_28 ;
}
static long F_326 ( struct V_98 * V_99 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_9 * V_9 = V_99 -> V_100 ;
int V_28 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_248 ;
switch ( V_242 ) {
case V_322 : {
struct V_351 V_352 ;
struct V_136 log ;
V_28 = - V_141 ;
if ( F_292 ( & V_352 , ( void V_124 * ) V_243 ,
sizeof( V_352 ) ) )
goto V_118;
log . V_114 = V_352 . V_114 ;
log . V_353 = V_352 . V_353 ;
log . V_354 = V_352 . V_354 ;
log . V_85 = F_299 ( V_352 . V_85 ) ;
V_28 = F_316 ( V_9 , & log ) ;
break;
}
default:
V_28 = F_315 ( V_99 , V_242 , V_243 ) ;
}
V_118:
return V_28 ;
}
static int F_327 ( unsigned long type )
{
int V_28 ;
struct V_9 * V_9 ;
V_9 = F_72 ( type ) ;
if ( F_268 ( V_9 ) )
return F_269 ( V_9 ) ;
#ifdef F_260
V_28 = F_328 ( V_9 ) ;
if ( V_28 < 0 ) {
F_114 ( V_9 ) ;
return V_28 ;
}
#endif
V_28 = F_265 ( L_2 , & V_355 , V_9 , V_229 | V_230 ) ;
if ( V_28 < 0 )
F_114 ( V_9 ) ;
return V_28 ;
}
static long F_329 ( struct V_98 * V_99 ,
unsigned int V_242 , unsigned long V_243 )
{
long V_28 = - V_112 ;
switch ( V_242 ) {
case V_356 :
if ( V_243 )
goto V_118;
V_28 = V_357 ;
break;
case V_358 :
V_28 = F_327 ( V_243 ) ;
break;
case V_350 :
V_28 = F_310 ( NULL , V_243 ) ;
break;
case V_359 :
if ( V_243 )
goto V_118;
V_28 = V_82 ;
#ifdef F_259
V_28 += V_82 ;
#endif
#ifdef F_260
V_28 += V_82 ;
#endif
break;
case V_360 :
case V_361 :
case V_362 :
V_28 = - V_363 ;
break;
default:
return F_330 ( V_99 , V_242 , V_243 ) ;
}
V_118:
return V_28 ;
}
static void F_331 ( void * V_364 )
{
int V_4 = F_332 () ;
int V_28 ;
if ( F_333 ( V_4 , V_365 ) )
return;
F_24 ( V_4 , V_365 ) ;
V_28 = F_334 () ;
if ( V_28 ) {
F_335 ( V_4 , V_365 ) ;
F_84 ( & V_366 ) ;
F_336 ( L_3 , V_4 ) ;
}
}
static void F_337 ( void )
{
F_338 ( & V_367 ) ;
if ( V_368 )
F_331 ( NULL ) ;
F_339 ( & V_367 ) ;
}
static void F_340 ( void * V_364 )
{
int V_4 = F_332 () ;
if ( ! F_333 ( V_4 , V_365 ) )
return;
F_335 ( V_4 , V_365 ) ;
F_341 () ;
}
static void F_342 ( void )
{
F_338 ( & V_367 ) ;
if ( V_368 )
F_340 ( NULL ) ;
F_339 ( & V_367 ) ;
}
static void F_343 ( void )
{
F_62 ( ! V_368 ) ;
V_368 -- ;
if ( ! V_368 )
F_344 ( F_340 , NULL , 1 ) ;
}
static void F_90 ( void )
{
F_338 ( & V_367 ) ;
F_343 () ;
F_339 ( & V_367 ) ;
}
static int F_76 ( void )
{
int V_28 = 0 ;
F_338 ( & V_367 ) ;
V_368 ++ ;
if ( V_368 == 1 ) {
F_86 ( & V_366 , 0 ) ;
F_344 ( F_331 , NULL , 1 ) ;
if ( F_273 ( & V_366 ) ) {
F_343 () ;
V_28 = - V_332 ;
}
}
F_339 ( & V_367 ) ;
return V_28 ;
}
static int F_345 ( struct V_369 * V_370 , unsigned long V_371 ,
void * V_231 )
{
int V_4 = ( long ) V_231 ;
V_371 &= ~ V_372 ;
switch ( V_371 ) {
case V_373 :
F_336 ( L_4 ,
V_4 ) ;
F_342 () ;
break;
case V_374 :
F_336 ( L_5 ,
V_4 ) ;
F_337 () ;
break;
}
return V_375 ;
}
static int F_346 ( struct V_369 * V_370 , unsigned long V_371 ,
void * V_231 )
{
F_336 ( L_6 ) ;
V_376 = true ;
F_344 ( F_340 , NULL , 1 ) ;
return V_375 ;
}
static void F_107 ( struct V_71 * V_377 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_377 -> V_378 ; V_11 ++ ) {
struct V_379 * V_380 = V_377 -> V_381 [ V_11 ] . V_92 ;
F_347 ( V_380 ) ;
}
F_91 ( V_377 ) ;
}
static inline int F_348 ( const struct V_382 * V_383 ,
const struct V_382 * V_384 )
{
if ( V_383 -> V_150 < V_384 -> V_150 )
return - 1 ;
if ( V_383 -> V_150 + V_383 -> V_184 > V_384 -> V_150 + V_384 -> V_184 )
return 1 ;
return 0 ;
}
static int F_349 ( const void * V_385 , const void * V_386 )
{
return F_348 ( V_385 , V_386 ) ;
}
static int F_350 ( struct V_71 * V_377 , struct V_379 * V_92 ,
T_6 V_150 , int V_184 )
{
V_377 -> V_381 [ V_377 -> V_378 ++ ] = (struct V_382 ) {
. V_150 = V_150 ,
. V_184 = V_184 ,
. V_92 = V_92 ,
} ;
F_351 ( V_377 -> V_381 , V_377 -> V_378 , sizeof( struct V_382 ) ,
F_349 , NULL ) ;
return 0 ;
}
static int F_352 ( struct V_71 * V_377 ,
T_6 V_150 , int V_184 )
{
struct V_382 * V_381 , V_387 ;
int V_388 ;
V_387 = (struct V_382 ) {
. V_150 = V_150 ,
. V_184 = V_184 ,
} ;
V_381 = bsearch ( & V_387 , V_377 -> V_381 , V_377 -> V_378 ,
sizeof( struct V_382 ) , F_349 ) ;
if ( V_381 == NULL )
return - V_140 ;
V_388 = V_381 - V_377 -> V_381 ;
while ( V_388 > 0 && F_348 ( & V_387 , & V_377 -> V_381 [ V_388 - 1 ] ) == 0 )
V_388 -- ;
return V_388 ;
}
static int F_353 ( struct V_2 * V_3 , struct V_71 * V_377 ,
struct V_382 * V_381 , const void * V_371 )
{
int V_45 ;
V_45 = F_352 ( V_377 , V_381 -> V_150 , V_381 -> V_184 ) ;
if ( V_45 < 0 )
return - V_363 ;
while ( V_45 < V_377 -> V_378 &&
F_348 ( V_381 , & V_377 -> V_381 [ V_45 ] ) == 0 ) {
if ( ! F_354 ( V_3 , V_377 -> V_381 [ V_45 ] . V_92 , V_381 -> V_150 ,
V_381 -> V_184 , V_371 ) )
return V_45 ;
V_45 ++ ;
}
return - V_363 ;
}
int F_355 ( struct V_2 * V_3 , enum V_389 V_390 , T_6 V_150 ,
int V_184 , const void * V_371 )
{
struct V_71 * V_377 ;
struct V_382 V_381 ;
int V_28 ;
V_381 = (struct V_382 ) {
. V_150 = V_150 ,
. V_184 = V_184 ,
} ;
V_377 = F_356 ( V_3 -> V_9 -> V_70 [ V_390 ] , & V_3 -> V_9 -> V_46 ) ;
V_28 = F_353 ( V_3 , V_377 , & V_381 , V_371 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
int F_357 ( struct V_2 * V_3 , enum V_389 V_390 ,
T_6 V_150 , int V_184 , const void * V_371 , long V_391 )
{
struct V_71 * V_377 ;
struct V_382 V_381 ;
V_381 = (struct V_382 ) {
. V_150 = V_150 ,
. V_184 = V_184 ,
} ;
V_377 = F_356 ( V_3 -> V_9 -> V_70 [ V_390 ] , & V_3 -> V_9 -> V_46 ) ;
if ( ( V_391 >= 0 ) && ( V_391 < V_377 -> V_378 ) &&
( F_348 ( & V_381 , & V_377 -> V_381 [ V_391 ] ) == 0 ) )
if ( ! F_354 ( V_3 , V_377 -> V_381 [ V_391 ] . V_92 , V_150 , V_184 ,
V_371 ) )
return V_391 ;
return F_353 ( V_3 , V_377 , & V_381 , V_371 ) ;
}
static int F_358 ( struct V_2 * V_3 , struct V_71 * V_377 ,
struct V_382 * V_381 , void * V_371 )
{
int V_45 ;
V_45 = F_352 ( V_377 , V_381 -> V_150 , V_381 -> V_184 ) ;
if ( V_45 < 0 )
return - V_363 ;
while ( V_45 < V_377 -> V_378 &&
F_348 ( V_381 , & V_377 -> V_381 [ V_45 ] ) == 0 ) {
if ( ! F_359 ( V_3 , V_377 -> V_381 [ V_45 ] . V_92 , V_381 -> V_150 ,
V_381 -> V_184 , V_371 ) )
return V_45 ;
V_45 ++ ;
}
return - V_363 ;
}
int F_360 ( struct V_2 * V_3 , enum V_389 V_390 , T_6 V_150 ,
int V_184 , void * V_371 )
{
struct V_71 * V_377 ;
struct V_382 V_381 ;
int V_28 ;
V_381 = (struct V_382 ) {
. V_150 = V_150 ,
. V_184 = V_184 ,
} ;
V_377 = F_356 ( V_3 -> V_9 -> V_70 [ V_390 ] , & V_3 -> V_9 -> V_46 ) ;
V_28 = F_358 ( V_3 , V_377 , & V_381 , V_371 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
int F_361 ( struct V_9 * V_9 , enum V_389 V_390 , T_6 V_150 ,
int V_184 , struct V_379 * V_92 )
{
struct V_71 * V_392 , * V_377 ;
V_377 = V_9 -> V_70 [ V_390 ] ;
if ( V_377 -> V_378 - V_377 -> V_393 > V_394 - 1 )
return - V_299 ;
V_392 = F_82 ( sizeof( * V_377 ) + ( ( V_377 -> V_378 + 1 ) *
sizeof( struct V_382 ) ) , V_32 ) ;
if ( ! V_392 )
return - V_34 ;
memcpy ( V_392 , V_377 , sizeof( * V_377 ) + ( V_377 -> V_378 *
sizeof( struct V_382 ) ) ) ;
F_350 ( V_392 , V_92 , V_150 , V_184 ) ;
F_126 ( V_9 -> V_70 [ V_390 ] , V_392 ) ;
F_127 ( & V_9 -> V_46 ) ;
F_91 ( V_377 ) ;
return 0 ;
}
int F_362 ( struct V_9 * V_9 , enum V_389 V_390 ,
struct V_379 * V_92 )
{
int V_11 , V_28 ;
struct V_71 * V_392 , * V_377 ;
V_377 = V_9 -> V_70 [ V_390 ] ;
V_28 = - V_140 ;
for ( V_11 = 0 ; V_11 < V_377 -> V_378 ; V_11 ++ )
if ( V_377 -> V_381 [ V_11 ] . V_92 == V_92 ) {
V_28 = 0 ;
break;
}
if ( V_28 )
return V_28 ;
V_392 = F_82 ( sizeof( * V_377 ) + ( ( V_377 -> V_378 - 1 ) *
sizeof( struct V_382 ) ) , V_32 ) ;
if ( ! V_392 )
return - V_34 ;
memcpy ( V_392 , V_377 , sizeof( * V_377 ) + V_11 * sizeof( struct V_382 ) ) ;
V_392 -> V_378 -- ;
memcpy ( V_392 -> V_381 + V_11 , V_377 -> V_381 + V_11 + 1 ,
( V_392 -> V_378 - V_11 ) * sizeof( struct V_382 ) ) ;
F_126 ( V_9 -> V_70 [ V_390 ] , V_392 ) ;
F_127 ( & V_9 -> V_46 ) ;
F_91 ( V_377 ) ;
return V_28 ;
}
static int F_363 ( void * V_395 , T_11 * V_371 )
{
unsigned V_144 = ( long ) V_395 ;
struct V_9 * V_9 ;
* V_371 = 0 ;
F_51 ( & V_79 ) ;
F_364 ( V_9 , & V_80 , V_80 )
* V_371 += * ( T_4 * ) ( ( void * ) V_9 + V_144 ) ;
F_53 ( & V_79 ) ;
return 0 ;
}
static int F_365 ( void * V_395 , T_11 * V_371 )
{
unsigned V_144 = ( long ) V_395 ;
struct V_9 * V_9 ;
struct V_2 * V_3 ;
int V_11 ;
* V_371 = 0 ;
F_51 ( & V_79 ) ;
F_364 (kvm, &vm_list, vm_list)
F_20 ( V_11 , V_3 , V_9 )
* V_371 += * ( T_4 * ) ( ( void * ) V_3 + V_144 ) ;
F_53 ( & V_79 ) ;
return 0 ;
}
static int F_366 ( void )
{
int V_28 = - V_131 ;
struct V_396 * V_281 ;
V_397 = F_367 ( L_7 , NULL ) ;
if ( V_397 == NULL )
goto V_118;
for ( V_281 = V_398 ; V_281 -> V_306 ; ++ V_281 ) {
V_281 -> V_399 = F_368 ( V_281 -> V_306 , 0444 , V_397 ,
( void * ) ( long ) V_281 -> V_144 ,
V_400 [ V_281 -> V_401 ] ) ;
if ( V_281 -> V_399 == NULL )
goto V_402;
}
return 0 ;
V_402:
F_369 ( V_397 ) ;
V_118:
return V_28 ;
}
static void F_370 ( void )
{
struct V_396 * V_281 ;
for ( V_281 = V_398 ; V_281 -> V_306 ; ++ V_281 )
F_371 ( V_281 -> V_399 ) ;
F_371 ( V_397 ) ;
}
static int F_372 ( void )
{
if ( V_368 )
F_340 ( NULL ) ;
return 0 ;
}
static void F_373 ( void )
{
if ( V_368 ) {
F_121 ( F_374 ( & V_367 ) ) ;
F_331 ( NULL ) ;
}
}
static inline
struct V_2 * F_375 ( struct V_7 * V_403 )
{
return F_48 ( V_403 , struct V_2 , V_7 ) ;
}
static void F_376 ( struct V_7 * V_403 , int V_4 )
{
struct V_2 * V_3 = F_375 ( V_403 ) ;
if ( V_3 -> V_37 )
V_3 -> V_37 = false ;
F_377 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_378 ( struct V_7 * V_403 ,
struct V_158 * V_404 )
{
struct V_2 * V_3 = F_375 ( V_403 ) ;
if ( V_56 -> V_405 == V_406 )
V_3 -> V_37 = true ;
F_13 ( V_3 ) ;
}
int F_379 ( void * V_407 , unsigned V_408 , unsigned V_409 ,
struct V_410 * V_410 )
{
int V_28 ;
int V_4 ;
V_28 = F_380 ( V_407 ) ;
if ( V_28 )
goto V_411;
V_28 = F_381 () ;
if ( V_28 )
goto V_412;
if ( ! F_19 ( & V_365 , V_32 ) ) {
V_28 = - V_34 ;
goto V_413;
}
V_28 = F_382 () ;
if ( V_28 < 0 )
goto V_414;
F_383 (cpu) {
F_384 ( V_4 ,
V_415 ,
& V_28 , 1 ) ;
if ( V_28 < 0 )
goto V_416;
}
V_28 = F_385 ( & V_417 ) ;
if ( V_28 )
goto V_418;
F_386 ( & V_419 ) ;
if ( ! V_409 )
V_409 = F_387 ( struct V_2 ) ;
V_420 = F_388 ( L_8 , V_408 , V_409 ,
0 , NULL ) ;
if ( ! V_420 ) {
V_28 = - V_34 ;
goto V_421;
}
V_28 = F_389 () ;
if ( V_28 )
goto V_132;
V_422 . V_423 = V_410 ;
V_355 . V_423 = V_410 ;
V_228 . V_423 = V_410 ;
V_28 = F_390 ( & V_424 ) ;
if ( V_28 ) {
F_391 ( L_9 ) ;
goto V_425;
}
F_392 ( & V_426 ) ;
V_233 . V_427 = F_376 ;
V_233 . V_428 = F_378 ;
V_28 = F_366 () ;
if ( V_28 ) {
F_391 ( L_10 ) ;
goto V_429;
}
V_28 = F_393 () ;
F_121 ( V_28 ) ;
return 0 ;
V_429:
F_394 ( & V_426 ) ;
F_395 ( & V_424 ) ;
V_425:
F_396 () ;
V_132:
F_397 ( V_420 ) ;
V_421:
F_398 ( & V_419 ) ;
F_399 ( & V_417 ) ;
V_418:
V_416:
F_400 () ;
V_414:
F_28 ( V_365 ) ;
V_413:
F_401 () ;
V_412:
F_402 () ;
V_411:
return V_28 ;
}
void F_403 ( void )
{
F_370 () ;
F_395 ( & V_424 ) ;
F_397 ( V_420 ) ;
F_396 () ;
F_394 ( & V_426 ) ;
F_398 ( & V_419 ) ;
F_399 ( & V_417 ) ;
F_344 ( F_340 , NULL , 1 ) ;
F_400 () ;
F_402 () ;
F_401 () ;
F_28 ( V_365 ) ;
F_404 () ;
}
