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
V_9 -> V_59 = F_80 ( sizeof( struct V_57 ) , V_32 ) ;
if ( ! V_9 -> V_59 )
goto V_65;
V_9 -> V_59 -> V_66 = - 150 ;
F_71 ( V_9 ) ;
if ( F_81 ( & V_9 -> V_46 ) )
goto V_65;
if ( F_81 ( & V_9 -> V_67 ) )
goto V_68;
for ( V_11 = 0 ; V_11 < V_69 ; V_11 ++ ) {
V_9 -> V_70 [ V_11 ] = F_80 ( sizeof( struct V_71 ) ,
V_32 ) ;
if ( ! V_9 -> V_70 [ V_11 ] )
goto V_72;
}
F_82 ( & V_9 -> V_47 ) ;
V_9 -> V_42 = V_56 -> V_42 ;
F_83 ( & V_9 -> V_42 -> V_73 ) ;
F_84 ( V_9 ) ;
F_35 ( & V_9 -> V_74 ) ;
F_35 ( & V_9 -> V_75 ) ;
F_35 ( & V_9 -> V_76 ) ;
F_85 ( & V_9 -> V_77 , 1 ) ;
F_86 ( & V_9 -> V_78 ) ;
V_28 = F_69 ( V_9 ) ;
if ( V_28 )
goto V_72;
F_51 ( & V_79 ) ;
F_87 ( & V_9 -> V_80 , & V_80 ) ;
F_53 ( & V_79 ) ;
return V_9 ;
V_72:
F_88 ( & V_9 -> V_67 ) ;
V_68:
F_88 ( & V_9 -> V_46 ) ;
V_65:
F_89 () ;
V_62:
for ( V_11 = 0 ; V_11 < V_69 ; V_11 ++ )
F_90 ( V_9 -> V_70 [ V_11 ] ) ;
F_90 ( V_9 -> V_59 ) ;
F_91 ( V_9 ) ;
return F_74 ( V_28 ) ;
}
void * F_92 ( unsigned long V_81 )
{
if ( V_81 > V_82 )
return F_93 ( V_81 ) ;
else
return F_80 ( V_81 , V_32 ) ;
}
void F_94 ( const void * V_83 )
{
if ( F_95 ( V_83 ) )
F_96 ( V_83 ) ;
else
F_90 ( V_83 ) ;
}
static void F_97 ( struct V_84 * V_85 )
{
if ( ! V_85 -> V_86 )
return;
F_94 ( V_85 -> V_86 ) ;
V_85 -> V_86 = NULL ;
}
static void F_98 ( struct V_9 * V_9 , struct V_84 * free ,
struct V_84 * V_87 )
{
if ( ! V_87 || free -> V_86 != V_87 -> V_86 )
F_97 ( free ) ;
F_99 ( V_9 , free , V_87 ) ;
free -> V_88 = 0 ;
}
static void F_100 ( struct V_9 * V_9 )
{
struct V_57 * V_58 = V_9 -> V_59 ;
struct V_84 * V_85 ;
F_101 (memslot, slots)
F_98 ( V_9 , V_85 , NULL ) ;
F_90 ( V_9 -> V_59 ) ;
}
static void F_102 ( struct V_9 * V_9 )
{
struct V_89 * V_90 , * V_91 ;
F_103 (node, tmp, &kvm->devices) {
struct V_92 * V_93 =
F_104 ( V_90 , struct V_92 , V_94 ) ;
F_105 ( V_90 ) ;
V_93 -> V_54 -> V_95 ( V_93 ) ;
}
}
static void F_106 ( struct V_9 * V_9 )
{
int V_11 ;
struct V_41 * V_42 = V_9 -> V_42 ;
F_107 ( V_9 ) ;
F_51 ( & V_79 ) ;
F_105 ( & V_9 -> V_80 ) ;
F_53 ( & V_79 ) ;
F_108 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_69 ; V_11 ++ )
F_109 ( V_9 -> V_70 [ V_11 ] ) ;
F_110 ( V_9 ) ;
#if F_111 ( V_96 ) && F_111 ( V_97 )
F_112 ( & V_9 -> V_39 , V_9 -> V_42 ) ;
#else
F_68 ( V_9 ) ;
#endif
F_113 ( V_9 ) ;
F_102 ( V_9 ) ;
F_100 ( V_9 ) ;
F_88 ( & V_9 -> V_67 ) ;
F_88 ( & V_9 -> V_46 ) ;
F_91 ( V_9 ) ;
F_89 () ;
F_114 ( V_42 ) ;
}
void F_115 ( struct V_9 * V_9 )
{
F_83 ( & V_9 -> V_77 ) ;
}
void F_116 ( struct V_9 * V_9 )
{
if ( F_117 ( & V_9 -> V_77 ) )
F_106 ( V_9 ) ;
}
static int F_118 ( struct V_98 * V_98 , struct V_99 * V_100 )
{
struct V_9 * V_9 = V_100 -> V_101 ;
F_119 ( V_9 ) ;
F_116 ( V_9 ) ;
return 0 ;
}
static int F_120 ( struct V_84 * V_85 )
{
unsigned long V_102 = 2 * F_121 ( V_85 ) ;
V_85 -> V_86 = F_92 ( V_102 ) ;
if ( ! V_85 -> V_86 )
return - V_34 ;
return 0 ;
}
static void F_122 ( struct V_57 * V_58 ,
struct V_84 * V_103 )
{
int V_26 = V_103 -> V_26 ;
int V_11 = V_58 -> V_61 [ V_26 ] ;
struct V_84 * V_104 = V_58 -> V_59 ;
F_123 ( V_104 [ V_11 ] . V_26 != V_26 ) ;
if ( ! V_103 -> V_88 ) {
F_123 ( ! V_104 [ V_11 ] . V_88 ) ;
V_103 -> V_105 = 0 ;
if ( V_104 [ V_11 ] . V_88 )
V_58 -> V_106 -- ;
} else {
if ( ! V_104 [ V_11 ] . V_88 )
V_58 -> V_106 ++ ;
}
while ( V_11 < V_60 - 1 &&
V_103 -> V_105 <= V_104 [ V_11 + 1 ] . V_105 ) {
if ( ! V_104 [ V_11 + 1 ] . V_88 )
break;
V_104 [ V_11 ] = V_104 [ V_11 + 1 ] ;
V_58 -> V_61 [ V_104 [ V_11 ] . V_26 ] = V_11 ;
V_11 ++ ;
}
if ( V_103 -> V_88 ) {
while ( V_11 > 0 &&
V_103 -> V_105 >= V_104 [ V_11 - 1 ] . V_105 ) {
V_104 [ V_11 ] = V_104 [ V_11 - 1 ] ;
V_58 -> V_61 [ V_104 [ V_11 ] . V_26 ] = V_11 ;
V_11 -- ;
}
} else
F_124 ( V_11 != V_58 -> V_106 ) ;
V_104 [ V_11 ] = * V_103 ;
V_58 -> V_61 [ V_104 [ V_11 ] . V_26 ] = V_11 ;
}
static int F_125 ( struct V_107 * V_108 )
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
struct V_57 * V_58 )
{
struct V_57 * V_114 = V_9 -> V_59 ;
F_123 ( V_114 -> V_66 & 1 ) ;
V_58 -> V_66 = V_114 -> V_66 + 1 ;
F_128 ( V_9 -> V_59 , V_58 ) ;
F_129 ( & V_9 -> V_46 ) ;
V_58 -> V_66 ++ ;
F_130 ( V_9 ) ;
return V_114 ;
}
int F_131 ( struct V_9 * V_9 ,
struct V_107 * V_108 )
{
int V_28 ;
T_5 V_105 ;
unsigned long V_88 ;
struct V_84 * V_115 ;
struct V_84 V_116 , V_103 ;
struct V_57 * V_58 = NULL , * V_114 ;
enum V_117 V_118 ;
V_28 = F_125 ( V_108 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_113 ;
if ( V_108 -> V_120 & ( V_82 - 1 ) )
goto V_119;
if ( V_108 -> V_121 & ( V_82 - 1 ) )
goto V_119;
if ( ( V_108 -> V_115 < V_122 ) &&
( ( V_108 -> V_123 & ( V_82 - 1 ) ) ||
! F_132 ( V_124 ,
( void V_125 * ) ( unsigned long ) V_108 -> V_123 ,
V_108 -> V_120 ) ) )
goto V_119;
if ( V_108 -> V_115 >= V_60 )
goto V_119;
if ( V_108 -> V_121 + V_108 -> V_120 < V_108 -> V_121 )
goto V_119;
V_115 = F_133 ( V_9 -> V_59 , V_108 -> V_115 ) ;
V_105 = V_108 -> V_121 >> V_126 ;
V_88 = V_108 -> V_120 >> V_126 ;
if ( V_88 > V_127 )
goto V_119;
if ( ! V_88 )
V_108 -> V_112 &= ~ V_110 ;
V_103 = V_116 = * V_115 ;
V_103 . V_26 = V_108 -> V_115 ;
V_103 . V_105 = V_105 ;
V_103 . V_88 = V_88 ;
V_103 . V_112 = V_108 -> V_112 ;
if ( V_88 ) {
if ( ! V_116 . V_88 )
V_118 = V_128 ;
else {
if ( ( V_108 -> V_123 != V_116 . V_123 ) ||
( V_88 != V_116 . V_88 ) ||
( ( V_103 . V_112 ^ V_116 . V_112 ) & V_111 ) )
goto V_119;
if ( V_105 != V_116 . V_105 )
V_118 = V_129 ;
else if ( V_103 . V_112 != V_116 . V_112 )
V_118 = V_130 ;
else {
V_28 = 0 ;
goto V_119;
}
}
} else if ( V_116 . V_88 ) {
V_118 = V_131 ;
} else
goto V_119;
if ( ( V_118 == V_128 ) || ( V_118 == V_129 ) ) {
V_28 = - V_132 ;
F_101 (slot, kvm->memslots) {
if ( ( V_115 -> V_26 >= V_122 ) ||
( V_115 -> V_26 == V_108 -> V_115 ) )
continue;
if ( ! ( ( V_105 + V_88 <= V_115 -> V_105 ) ||
( V_105 >= V_115 -> V_105 + V_115 -> V_88 ) ) )
goto V_119;
}
}
if ( ! ( V_103 . V_112 & V_110 ) )
V_103 . V_86 = NULL ;
V_28 = - V_34 ;
if ( V_118 == V_128 ) {
V_103 . V_123 = V_108 -> V_123 ;
if ( F_134 ( V_9 , & V_103 , V_88 ) )
goto V_133;
}
if ( ( V_103 . V_112 & V_110 ) && ! V_103 . V_86 ) {
if ( F_120 ( & V_103 ) < 0 )
goto V_133;
}
V_58 = F_135 ( V_9 -> V_59 , sizeof( struct V_57 ) ,
V_32 ) ;
if ( ! V_58 )
goto V_133;
if ( ( V_118 == V_131 ) || ( V_118 == V_129 ) ) {
V_115 = F_133 ( V_58 , V_108 -> V_115 ) ;
V_115 -> V_112 |= V_134 ;
V_114 = F_127 ( V_9 , V_58 ) ;
F_136 ( V_9 , & V_116 ) ;
F_137 ( V_9 , V_115 ) ;
V_58 = V_114 ;
}
V_28 = F_138 ( V_9 , & V_103 , V_108 , V_118 ) ;
if ( V_28 )
goto V_135;
if ( V_118 == V_131 ) {
V_103 . V_86 = NULL ;
memset ( & V_103 . V_136 , 0 , sizeof( V_103 . V_136 ) ) ;
}
F_122 ( V_58 , & V_103 ) ;
V_114 = F_127 ( V_9 , V_58 ) ;
F_139 ( V_9 , V_108 , & V_116 , V_118 ) ;
F_98 ( V_9 , & V_116 , & V_103 ) ;
F_90 ( V_114 ) ;
if ( ( V_118 == V_128 ) || ( V_118 == V_129 ) ) {
V_28 = F_140 ( V_9 , & V_103 ) ;
return V_28 ;
}
return 0 ;
V_135:
F_90 ( V_58 ) ;
V_133:
F_98 ( V_9 , & V_103 , & V_116 ) ;
V_119:
return V_28 ;
}
int F_141 ( struct V_9 * V_9 ,
struct V_107 * V_108 )
{
int V_28 ;
F_142 ( & V_9 -> V_76 ) ;
V_28 = F_131 ( V_9 , V_108 ) ;
F_16 ( & V_9 -> V_76 ) ;
return V_28 ;
}
static int F_143 ( struct V_9 * V_9 ,
struct V_107 * V_108 )
{
if ( V_108 -> V_115 >= V_122 )
return - V_113 ;
return F_141 ( V_9 , V_108 ) ;
}
int F_144 ( struct V_9 * V_9 ,
struct V_137 * log , int * V_138 )
{
struct V_84 * V_85 ;
int V_28 , V_11 ;
unsigned long V_139 ;
unsigned long V_140 = 0 ;
V_28 = - V_113 ;
if ( log -> V_115 >= V_122 )
goto V_119;
V_85 = F_133 ( V_9 -> V_59 , log -> V_115 ) ;
V_28 = - V_141 ;
if ( ! V_85 -> V_86 )
goto V_119;
V_139 = F_121 ( V_85 ) ;
for ( V_11 = 0 ; ! V_140 && V_11 < V_139 / sizeof( long ) ; ++ V_11 )
V_140 = V_85 -> V_86 [ V_11 ] ;
V_28 = - V_142 ;
if ( F_145 ( log -> V_86 , V_85 -> V_86 , V_139 ) )
goto V_119;
if ( V_140 )
* V_138 = 1 ;
V_28 = 0 ;
V_119:
return V_28 ;
}
bool F_146 ( void )
{
return V_143 ;
}
void F_147 ( void )
{
V_143 = false ;
}
struct V_84 * F_148 ( struct V_9 * V_9 , T_5 V_144 )
{
return F_149 ( V_57 ( V_9 ) , V_144 ) ;
}
int F_150 ( struct V_9 * V_9 , T_5 V_144 )
{
struct V_84 * V_85 = F_148 ( V_9 , V_144 ) ;
if ( ! V_85 || V_85 -> V_26 >= V_122 ||
V_85 -> V_112 & V_134 )
return 0 ;
return 1 ;
}
unsigned long F_151 ( struct V_9 * V_9 , T_5 V_144 )
{
struct V_145 * V_146 ;
unsigned long V_83 , V_81 ;
V_81 = V_82 ;
V_83 = F_152 ( V_9 , V_144 ) ;
if ( F_153 ( V_83 ) )
return V_82 ;
F_154 ( & V_56 -> V_42 -> V_147 ) ;
V_146 = F_155 ( V_56 -> V_42 , V_83 ) ;
if ( ! V_146 )
goto V_119;
V_81 = F_156 ( V_146 ) ;
V_119:
F_157 ( & V_56 -> V_42 -> V_147 ) ;
return V_81 ;
}
static bool F_158 ( struct V_84 * V_115 )
{
return V_115 -> V_112 & V_111 ;
}
static unsigned long F_159 ( struct V_84 * V_115 , T_5 V_144 ,
T_5 * V_148 , bool V_149 )
{
if ( ! V_115 || V_115 -> V_112 & V_134 )
return V_150 ;
if ( F_158 ( V_115 ) && V_149 )
return V_151 ;
if ( V_148 )
* V_148 = V_115 -> V_88 - ( V_144 - V_115 -> V_105 ) ;
return F_160 ( V_115 , V_144 ) ;
}
static unsigned long F_161 ( struct V_84 * V_115 , T_5 V_144 ,
T_5 * V_148 )
{
return F_159 ( V_115 , V_144 , V_148 , true ) ;
}
unsigned long F_162 ( struct V_84 * V_115 ,
T_5 V_144 )
{
return F_161 ( V_115 , V_144 , NULL ) ;
}
unsigned long F_152 ( struct V_9 * V_9 , T_5 V_144 )
{
return F_161 ( F_148 ( V_9 , V_144 ) , V_144 , NULL ) ;
}
unsigned long F_163 ( struct V_84 * V_115 ,
T_5 V_144 , bool * V_152 )
{
unsigned long V_153 = F_159 ( V_115 , V_144 , NULL , false ) ;
if ( ! F_153 ( V_153 ) && V_152 )
* V_152 = ! F_158 ( V_115 ) ;
return V_153 ;
}
unsigned long F_164 ( struct V_9 * V_9 , T_5 V_144 , bool * V_152 )
{
struct V_84 * V_115 = F_148 ( V_9 , V_144 ) ;
return F_163 ( V_115 , V_144 , V_152 ) ;
}
static int F_165 ( void * V_154 , void V_125 * V_153 , int V_155 )
{
return F_166 ( V_154 , V_153 , V_155 ) ;
}
static int F_167 ( void * V_154 , void V_125 * V_153 , int V_155 )
{
return F_168 ( V_154 , V_153 , V_155 ) ;
}
static int F_169 ( struct V_156 * V_157 , struct V_41 * V_42 ,
unsigned long V_50 , int V_149 , struct V_27 * * V_27 )
{
int V_112 = V_158 | V_159 | V_160 | V_161 ;
if ( V_149 )
V_112 |= V_162 ;
return F_170 ( V_157 , V_42 , V_50 , 1 , V_112 , V_27 , NULL , NULL ) ;
}
int F_171 ( struct V_156 * V_157 , struct V_41 * V_42 ,
unsigned long V_83 , bool V_163 ,
struct V_27 * * V_164 )
{
int V_88 ;
int V_165 = 1 ;
int V_112 = V_158 | V_160 |
( V_164 ? V_161 : 0 ) |
( V_163 ? V_162 : 0 ) ;
F_154 ( & V_42 -> V_147 ) ;
V_88 = F_170 ( V_157 , V_42 , V_83 , 1 , V_112 , V_164 , NULL ,
& V_165 ) ;
if ( ! V_165 ) {
F_172 ( V_88 ) ;
if ( ! V_164 )
return 0 ;
F_154 ( & V_42 -> V_147 ) ;
V_88 = F_170 ( V_157 , V_42 , V_83 , 1 , V_112 | V_166 ,
V_164 , NULL , NULL ) ;
}
F_157 ( & V_42 -> V_147 ) ;
return V_88 ;
}
static inline int F_173 ( unsigned long V_83 )
{
int V_167 , V_112 = V_158 | V_160 | V_162 ;
V_167 = F_170 ( V_56 , V_56 -> V_42 , V_83 , 1 ,
V_112 , NULL , NULL , NULL ) ;
return V_167 == - V_168 ;
}
static bool F_174 ( unsigned long V_83 , bool V_169 , bool * V_170 ,
bool V_163 , bool * V_152 , T_1 * V_1 )
{
struct V_27 * V_27 [ 1 ] ;
int V_88 ;
if ( ! ( V_170 || V_169 ) )
return false ;
if ( ! ( V_163 || V_152 ) )
return false ;
V_88 = F_175 ( V_83 , 1 , 1 , V_27 ) ;
if ( V_88 == 1 ) {
* V_1 = F_176 ( V_27 [ 0 ] ) ;
if ( V_152 )
* V_152 = true ;
return true ;
}
return false ;
}
static int F_177 ( unsigned long V_83 , bool * V_170 , bool V_163 ,
bool * V_152 , T_1 * V_1 )
{
struct V_27 * V_27 [ 1 ] ;
int V_88 = 0 ;
F_178 () ;
if ( V_152 )
* V_152 = V_163 ;
if ( V_170 ) {
F_154 ( & V_56 -> V_42 -> V_147 ) ;
V_88 = F_169 ( V_56 , V_56 -> V_42 ,
V_83 , V_163 , V_27 ) ;
F_157 ( & V_56 -> V_42 -> V_147 ) ;
} else {
V_88 = F_171 ( V_56 , V_56 -> V_42 , V_83 ,
V_163 , V_27 ) ;
}
if ( V_88 != 1 )
return V_88 ;
if ( F_25 ( ! V_163 ) && V_152 ) {
struct V_27 * V_171 [ 1 ] ;
V_88 = F_175 ( V_83 , 1 , 1 , V_171 ) ;
if ( V_88 == 1 ) {
* V_152 = true ;
F_179 ( V_27 [ 0 ] ) ;
V_27 [ 0 ] = V_171 [ 0 ] ;
}
V_88 = 1 ;
}
* V_1 = F_176 ( V_27 [ 0 ] ) ;
return V_88 ;
}
static bool F_180 ( struct V_145 * V_146 , bool V_163 )
{
if ( F_25 ( ! ( V_146 -> V_172 & V_173 ) ) )
return false ;
if ( V_163 && ( F_25 ( ! ( V_146 -> V_172 & V_174 ) ) ) )
return false ;
return true ;
}
static T_1 F_181 ( unsigned long V_83 , bool V_169 , bool * V_170 ,
bool V_163 , bool * V_152 )
{
struct V_145 * V_146 ;
T_1 V_1 = 0 ;
int V_88 ;
F_62 ( V_169 && V_170 ) ;
if ( F_174 ( V_83 , V_169 , V_170 , V_163 , V_152 , & V_1 ) )
return V_1 ;
if ( V_169 )
return V_175 ;
V_88 = F_177 ( V_83 , V_170 , V_163 , V_152 , & V_1 ) ;
if ( V_88 == 1 )
return V_1 ;
F_154 ( & V_56 -> V_42 -> V_147 ) ;
if ( V_88 == - V_168 ||
( ! V_170 && F_173 ( V_83 ) ) ) {
V_1 = V_176 ;
goto exit;
}
V_146 = F_182 ( V_56 -> V_42 , V_83 , V_83 + 1 ) ;
if ( V_146 == NULL )
V_1 = V_175 ;
else if ( ( V_146 -> V_172 & V_177 ) ) {
V_1 = ( ( V_83 - V_146 -> V_178 ) >> V_126 ) +
V_146 -> V_179 ;
F_62 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_170 && F_180 ( V_146 , V_163 ) )
* V_170 = true ;
V_1 = V_175 ;
}
exit:
F_157 ( & V_56 -> V_42 -> V_147 ) ;
return V_1 ;
}
static T_1
F_183 ( struct V_84 * V_115 , T_5 V_144 , bool V_169 ,
bool * V_170 , bool V_163 , bool * V_152 )
{
unsigned long V_83 = F_159 ( V_115 , V_144 , NULL , V_163 ) ;
if ( V_83 == V_151 )
return V_180 ;
if ( F_153 ( V_83 ) )
return V_181 ;
if ( V_152 && F_158 ( V_115 ) ) {
* V_152 = false ;
V_152 = NULL ;
}
return F_181 ( V_83 , V_169 , V_170 , V_163 ,
V_152 ) ;
}
static T_1 F_184 ( struct V_9 * V_9 , T_5 V_144 , bool V_169 , bool * V_170 ,
bool V_163 , bool * V_152 )
{
struct V_84 * V_115 ;
if ( V_170 )
* V_170 = false ;
V_115 = F_148 ( V_9 , V_144 ) ;
return F_183 ( V_115 , V_144 , V_169 , V_170 , V_163 ,
V_152 ) ;
}
T_1 F_185 ( struct V_9 * V_9 , T_5 V_144 )
{
return F_184 ( V_9 , V_144 , true , NULL , true , NULL ) ;
}
T_1 F_186 ( struct V_9 * V_9 , T_5 V_144 , bool * V_170 ,
bool V_163 , bool * V_152 )
{
return F_184 ( V_9 , V_144 , false , V_170 , V_163 , V_152 ) ;
}
T_1 F_187 ( struct V_9 * V_9 , T_5 V_144 )
{
return F_184 ( V_9 , V_144 , false , NULL , true , NULL ) ;
}
T_1 F_188 ( struct V_9 * V_9 , T_5 V_144 , bool V_163 ,
bool * V_152 )
{
return F_184 ( V_9 , V_144 , false , NULL , V_163 , V_152 ) ;
}
T_1 F_189 ( struct V_84 * V_115 , T_5 V_144 )
{
return F_183 ( V_115 , V_144 , false , NULL , true , NULL ) ;
}
T_1 F_190 ( struct V_84 * V_115 , T_5 V_144 )
{
return F_183 ( V_115 , V_144 , true , NULL , true , NULL ) ;
}
int F_191 ( struct V_9 * V_9 , T_5 V_144 , struct V_27 * * V_182 ,
int V_148 )
{
unsigned long V_83 ;
T_5 V_183 ;
V_83 = F_161 ( F_148 ( V_9 , V_144 ) , V_144 , & V_183 ) ;
if ( F_153 ( V_83 ) )
return - 1 ;
if ( V_183 < V_148 )
return 0 ;
return F_175 ( V_83 , V_148 , 1 , V_182 ) ;
}
static struct V_27 * F_192 ( T_1 V_1 )
{
if ( F_193 ( V_1 ) )
return V_184 ;
if ( F_1 ( V_1 ) ) {
F_123 ( 1 ) ;
return V_184 ;
}
return F_4 ( V_1 ) ;
}
struct V_27 * F_194 ( struct V_9 * V_9 , T_5 V_144 )
{
T_1 V_1 ;
V_1 = F_187 ( V_9 , V_144 ) ;
return F_192 ( V_1 ) ;
}
void F_195 ( struct V_27 * V_27 )
{
F_123 ( F_196 ( V_27 ) ) ;
F_197 ( F_176 ( V_27 ) ) ;
}
void F_197 ( T_1 V_1 )
{
if ( ! F_193 ( V_1 ) && ! F_1 ( V_1 ) )
F_179 ( F_4 ( V_1 ) ) ;
}
void F_198 ( struct V_27 * V_27 )
{
F_123 ( F_196 ( V_27 ) ) ;
F_199 ( F_176 ( V_27 ) ) ;
}
static void F_199 ( T_1 V_1 )
{
F_200 ( V_1 ) ;
F_197 ( V_1 ) ;
}
void F_200 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_27 * V_27 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_27 ) )
F_201 ( V_27 ) ;
}
}
void F_202 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_203 ( F_4 ( V_1 ) ) ;
}
void F_204 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_205 ( F_4 ( V_1 ) ) ;
}
static int F_206 ( unsigned long V_155 , int V_185 )
{
if ( V_155 > V_82 - V_185 )
return V_82 - V_185 ;
else
return V_155 ;
}
int F_207 ( struct V_9 * V_9 , T_5 V_144 , void * V_154 , int V_185 ,
int V_155 )
{
int V_28 ;
unsigned long V_83 ;
V_83 = F_164 ( V_9 , V_144 , NULL ) ;
if ( F_153 ( V_83 ) )
return - V_142 ;
V_28 = F_165 ( V_154 , ( void V_125 * ) V_83 + V_185 , V_155 ) ;
if ( V_28 )
return - V_142 ;
return 0 ;
}
int F_208 ( struct V_9 * V_9 , T_6 V_186 , void * V_154 , unsigned long V_155 )
{
T_5 V_144 = V_186 >> V_126 ;
int V_187 ;
int V_185 = F_209 ( V_186 ) ;
int V_188 ;
while ( ( V_187 = F_206 ( V_155 , V_185 ) ) != 0 ) {
V_188 = F_207 ( V_9 , V_144 , V_154 , V_185 , V_187 ) ;
if ( V_188 < 0 )
return V_188 ;
V_185 = 0 ;
V_155 -= V_187 ;
V_154 += V_187 ;
++ V_144 ;
}
return 0 ;
}
int F_210 ( struct V_9 * V_9 , T_6 V_186 , void * V_154 ,
unsigned long V_155 )
{
int V_28 ;
unsigned long V_83 ;
T_5 V_144 = V_186 >> V_126 ;
int V_185 = F_209 ( V_186 ) ;
V_83 = F_164 ( V_9 , V_144 , NULL ) ;
if ( F_153 ( V_83 ) )
return - V_142 ;
F_211 () ;
V_28 = F_167 ( V_154 , ( void V_125 * ) V_83 + V_185 , V_155 ) ;
F_212 () ;
if ( V_28 )
return - V_142 ;
return 0 ;
}
int F_213 ( struct V_9 * V_9 , T_5 V_144 , const void * V_154 ,
int V_185 , int V_155 )
{
int V_28 ;
unsigned long V_83 ;
V_83 = F_152 ( V_9 , V_144 ) ;
if ( F_153 ( V_83 ) )
return - V_142 ;
V_28 = F_214 ( ( void V_125 * ) V_83 + V_185 , V_154 , V_155 ) ;
if ( V_28 )
return - V_142 ;
F_215 ( V_9 , V_144 ) ;
return 0 ;
}
int F_216 ( struct V_9 * V_9 , T_6 V_186 , const void * V_154 ,
unsigned long V_155 )
{
T_5 V_144 = V_186 >> V_126 ;
int V_187 ;
int V_185 = F_209 ( V_186 ) ;
int V_188 ;
while ( ( V_187 = F_206 ( V_155 , V_185 ) ) != 0 ) {
V_188 = F_213 ( V_9 , V_144 , V_154 , V_185 , V_187 ) ;
if ( V_188 < 0 )
return V_188 ;
V_185 = 0 ;
V_155 -= V_187 ;
V_154 += V_187 ;
++ V_144 ;
}
return 0 ;
}
int F_217 ( struct V_9 * V_9 , struct V_189 * V_190 ,
T_6 V_186 , unsigned long V_155 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_185 = F_209 ( V_186 ) ;
T_5 V_191 = V_186 >> V_126 ;
T_5 V_192 = ( V_186 + V_155 - 1 ) >> V_126 ;
T_5 V_193 = V_192 - V_191 + 1 ;
T_5 V_194 ;
V_190 -> V_186 = V_186 ;
V_190 -> V_66 = V_58 -> V_66 ;
V_190 -> V_155 = V_155 ;
V_190 -> V_85 = F_148 ( V_9 , V_191 ) ;
V_190 -> V_153 = F_161 ( V_190 -> V_85 , V_191 , & V_194 ) ;
if ( ! F_153 ( V_190 -> V_153 ) && V_194 >= V_193 ) {
V_190 -> V_153 += V_185 ;
} else {
while ( V_191 <= V_192 ) {
V_190 -> V_85 = F_148 ( V_9 , V_191 ) ;
V_190 -> V_153 = F_161 ( V_190 -> V_85 , V_191 ,
& V_194 ) ;
if ( F_153 ( V_190 -> V_153 ) )
return - V_142 ;
V_191 += V_194 ;
}
V_190 -> V_85 = NULL ;
}
return 0 ;
}
int F_218 ( struct V_9 * V_9 , struct V_189 * V_190 ,
void * V_154 , unsigned long V_155 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_28 ;
F_62 ( V_155 > V_190 -> V_155 ) ;
if ( V_58 -> V_66 != V_190 -> V_66 )
F_217 ( V_9 , V_190 , V_190 -> V_186 , V_190 -> V_155 ) ;
if ( F_25 ( ! V_190 -> V_85 ) )
return F_216 ( V_9 , V_190 -> V_186 , V_154 , V_155 ) ;
if ( F_153 ( V_190 -> V_153 ) )
return - V_142 ;
V_28 = F_214 ( ( void V_125 * ) V_190 -> V_153 , V_154 , V_155 ) ;
if ( V_28 )
return - V_142 ;
F_219 ( V_9 , V_190 -> V_85 , V_190 -> V_186 >> V_126 ) ;
return 0 ;
}
int F_220 ( struct V_9 * V_9 , struct V_189 * V_190 ,
void * V_154 , unsigned long V_155 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_28 ;
F_62 ( V_155 > V_190 -> V_155 ) ;
if ( V_58 -> V_66 != V_190 -> V_66 )
F_217 ( V_9 , V_190 , V_190 -> V_186 , V_190 -> V_155 ) ;
if ( F_25 ( ! V_190 -> V_85 ) )
return F_208 ( V_9 , V_190 -> V_186 , V_154 , V_155 ) ;
if ( F_153 ( V_190 -> V_153 ) )
return - V_142 ;
V_28 = F_166 ( V_154 , ( void V_125 * ) V_190 -> V_153 , V_155 ) ;
if ( V_28 )
return - V_142 ;
return 0 ;
}
int F_221 ( struct V_9 * V_9 , T_5 V_144 , int V_185 , int V_155 )
{
const void * V_195 = ( const void * ) F_222 ( F_223 ( F_224 ( 0 ) ) ) ;
return F_213 ( V_9 , V_144 , V_195 , V_185 , V_155 ) ;
}
int F_225 ( struct V_9 * V_9 , T_6 V_186 , unsigned long V_155 )
{
T_5 V_144 = V_186 >> V_126 ;
int V_187 ;
int V_185 = F_209 ( V_186 ) ;
int V_188 ;
while ( ( V_187 = F_206 ( V_155 , V_185 ) ) != 0 ) {
V_188 = F_221 ( V_9 , V_144 , V_185 , V_187 ) ;
if ( V_188 < 0 )
return V_188 ;
V_185 = 0 ;
V_155 -= V_187 ;
++ V_144 ;
}
return 0 ;
}
static void F_219 ( struct V_9 * V_9 ,
struct V_84 * V_85 ,
T_5 V_144 )
{
if ( V_85 && V_85 -> V_86 ) {
unsigned long V_196 = V_144 - V_85 -> V_105 ;
F_226 ( V_196 , V_85 -> V_86 ) ;
}
}
void F_215 ( struct V_9 * V_9 , T_5 V_144 )
{
struct V_84 * V_85 ;
V_85 = F_148 ( V_9 , V_144 ) ;
F_219 ( V_9 , V_85 , V_144 ) ;
}
void F_227 ( struct V_2 * V_3 )
{
F_228 ( V_197 ) ;
for (; ; ) {
F_229 ( & V_3 -> V_31 , & V_197 , V_198 ) ;
if ( F_230 ( V_3 ) ) {
F_21 ( V_199 , V_3 ) ;
break;
}
if ( F_231 ( V_3 ) )
break;
if ( F_232 ( V_56 ) )
break;
F_233 () ;
}
F_234 ( & V_3 -> V_31 , & V_197 ) ;
}
void F_235 ( struct V_2 * V_3 )
{
int V_12 ;
int V_4 = V_3 -> V_4 ;
T_7 * V_200 ;
V_200 = F_236 ( V_3 ) ;
if ( F_237 ( V_200 ) ) {
F_238 ( V_200 ) ;
++ V_3 -> V_21 . V_201 ;
}
V_12 = F_7 () ;
if ( V_4 != V_12 && ( unsigned ) V_4 < V_202 && F_239 ( V_4 ) )
if ( F_240 ( V_3 ) )
F_241 ( V_4 ) ;
F_10 () ;
}
int F_242 ( struct V_2 * V_203 )
{
struct V_30 * V_30 ;
struct V_156 * V_204 = NULL ;
int V_188 = 0 ;
F_243 () ;
V_30 = F_244 ( V_203 -> V_30 ) ;
if ( V_30 )
V_204 = F_245 ( V_30 , V_205 ) ;
F_246 () ;
if ( ! V_204 )
return V_188 ;
V_188 = F_247 ( V_204 , 1 ) ;
F_248 ( V_204 ) ;
return V_188 ;
}
static bool F_249 ( struct V_2 * V_3 )
{
#ifdef F_250
bool V_206 ;
V_206 = ! V_3 -> V_207 . V_208 ||
V_3 -> V_207 . V_209 ;
if ( V_3 -> V_207 . V_208 )
F_41 ( V_3 , ! V_3 -> V_207 . V_209 ) ;
return V_206 ;
#else
return true ;
#endif
}
void F_251 ( struct V_2 * V_12 )
{
struct V_9 * V_9 = V_12 -> V_9 ;
struct V_2 * V_3 ;
int V_210 = V_12 -> V_9 -> V_210 ;
int V_211 = 0 ;
int V_212 = 3 ;
int V_213 ;
int V_11 ;
F_40 ( V_12 , true ) ;
for ( V_213 = 0 ; V_213 < 2 && ! V_211 && V_212 ; V_213 ++ ) {
F_20 (i, vcpu, kvm) {
if ( ! V_213 && V_11 <= V_210 ) {
V_11 = V_210 ;
continue;
} else if ( V_213 && V_11 > V_210 )
break;
if ( ! F_252 ( V_3 -> V_37 ) )
continue;
if ( V_3 == V_12 )
continue;
if ( F_237 ( & V_3 -> V_31 ) && ! F_230 ( V_3 ) )
continue;
if ( ! F_249 ( V_3 ) )
continue;
V_211 = F_242 ( V_3 ) ;
if ( V_211 > 0 ) {
V_9 -> V_210 = V_11 ;
break;
} else if ( V_211 < 0 ) {
V_212 -- ;
if ( ! V_212 )
break;
}
}
}
F_40 ( V_12 , false ) ;
F_41 ( V_12 , false ) ;
}
static int F_253 ( struct V_145 * V_146 , struct V_214 * V_215 )
{
struct V_2 * V_3 = V_146 -> V_216 -> V_101 ;
struct V_27 * V_27 ;
if ( V_215 -> V_217 == 0 )
V_27 = F_254 ( V_3 -> V_36 ) ;
#ifdef F_255
else if ( V_215 -> V_217 == V_218 )
V_27 = F_254 ( V_3 -> V_136 . V_219 ) ;
#endif
#ifdef F_256
else if ( V_215 -> V_217 == F_256 )
V_27 = F_254 ( V_3 -> V_9 -> V_220 ) ;
#endif
else
return F_257 ( V_3 , V_215 ) ;
F_205 ( V_27 ) ;
V_215 -> V_27 = V_27 ;
return 0 ;
}
static int F_258 ( struct V_99 * V_99 , struct V_145 * V_146 )
{
V_146 -> V_221 = & V_222 ;
return 0 ;
}
static int F_259 ( struct V_98 * V_98 , struct V_99 * V_100 )
{
struct V_2 * V_3 = V_100 -> V_101 ;
F_116 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_260 ( struct V_2 * V_3 )
{
return F_261 ( L_1 , & V_223 , V_3 , V_224 | V_225 ) ;
}
static int F_262 ( struct V_9 * V_9 , T_4 V_26 )
{
int V_28 ;
struct V_2 * V_3 , * V_226 ;
if ( V_26 >= V_227 )
return - V_113 ;
V_3 = F_263 ( V_9 , V_26 ) ;
if ( F_264 ( V_3 ) )
return F_265 ( V_3 ) ;
F_266 ( & V_3 -> V_7 , & V_228 ) ;
V_28 = F_267 ( V_3 ) ;
if ( V_28 )
goto V_229;
F_142 ( & V_9 -> V_74 ) ;
if ( ! F_268 ( V_3 ) ) {
V_28 = - V_113 ;
goto V_230;
}
if ( F_269 ( & V_9 -> V_231 ) == V_227 ) {
V_28 = - V_113 ;
goto V_230;
}
F_20 (r, v, kvm)
if ( V_226 -> V_29 == V_26 ) {
V_28 = - V_132 ;
goto V_230;
}
F_62 ( V_9 -> V_232 [ F_269 ( & V_9 -> V_231 ) ] ) ;
F_115 ( V_9 ) ;
V_28 = F_260 ( V_3 ) ;
if ( V_28 < 0 ) {
F_116 ( V_9 ) ;
goto V_230;
}
V_9 -> V_232 [ F_269 ( & V_9 -> V_231 ) ] = V_3 ;
F_61 () ;
F_83 ( & V_9 -> V_231 ) ;
F_16 ( & V_9 -> V_74 ) ;
F_270 ( V_3 ) ;
return V_28 ;
V_230:
F_16 ( & V_9 -> V_74 ) ;
V_229:
F_271 ( V_3 ) ;
return V_28 ;
}
static int F_272 ( struct V_2 * V_3 , T_8 * V_233 )
{
if ( V_233 ) {
F_273 ( V_233 , F_274 ( V_234 ) | F_274 ( V_235 ) ) ;
V_3 -> V_236 = 1 ;
V_3 -> V_233 = * V_233 ;
} else
V_3 -> V_236 = 0 ;
return 0 ;
}
static long F_275 ( struct V_99 * V_100 ,
unsigned int V_237 , unsigned long V_238 )
{
struct V_2 * V_3 = V_100 -> V_101 ;
void V_125 * V_239 = ( void V_125 * ) V_238 ;
int V_28 ;
struct V_240 * V_241 = NULL ;
struct V_242 * V_242 = NULL ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_243 ;
if ( F_25 ( F_276 ( V_237 ) != V_244 ) )
return - V_113 ;
#if F_111 ( V_245 ) || F_111 ( V_246 ) || F_111 ( V_247 )
if ( V_237 == V_248 || V_237 == V_249 )
return F_277 ( V_100 , V_237 , V_238 ) ;
#endif
V_28 = F_5 ( V_3 ) ;
if ( V_28 )
return V_28 ;
switch ( V_237 ) {
case V_250 :
V_28 = - V_113 ;
if ( V_238 )
goto V_119;
if ( F_25 ( V_3 -> V_30 != V_56 -> V_251 [ V_205 ] . V_30 ) ) {
struct V_30 * V_252 = V_3 -> V_30 ;
struct V_30 * V_253 = F_278 ( V_56 , V_205 ) ;
F_128 ( V_3 -> V_30 , V_253 ) ;
if ( V_252 )
F_279 () ;
F_45 ( V_252 ) ;
}
V_28 = F_280 ( V_3 , V_3 -> V_36 ) ;
F_281 ( V_3 -> V_36 -> V_254 , V_28 ) ;
break;
case V_255 : {
struct V_256 * V_256 ;
V_28 = - V_34 ;
V_256 = F_80 ( sizeof( struct V_256 ) , V_32 ) ;
if ( ! V_256 )
goto V_119;
V_28 = F_282 ( V_3 , V_256 ) ;
if ( V_28 )
goto V_257;
V_28 = - V_142 ;
if ( F_145 ( V_239 , V_256 , sizeof( struct V_256 ) ) )
goto V_257;
V_28 = 0 ;
V_257:
F_90 ( V_256 ) ;
break;
}
case V_258 : {
struct V_256 * V_256 ;
V_28 = - V_34 ;
V_256 = F_283 ( V_239 , sizeof( * V_256 ) ) ;
if ( F_264 ( V_256 ) ) {
V_28 = F_265 ( V_256 ) ;
goto V_119;
}
V_28 = F_284 ( V_3 , V_256 ) ;
F_90 ( V_256 ) ;
break;
}
case V_259 : {
V_242 = F_80 ( sizeof( struct V_242 ) , V_32 ) ;
V_28 = - V_34 ;
if ( ! V_242 )
goto V_119;
V_28 = F_285 ( V_3 , V_242 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_142 ;
if ( F_145 ( V_239 , V_242 , sizeof( struct V_242 ) ) )
goto V_119;
V_28 = 0 ;
break;
}
case V_260 : {
V_242 = F_283 ( V_239 , sizeof( * V_242 ) ) ;
if ( F_264 ( V_242 ) ) {
V_28 = F_265 ( V_242 ) ;
V_242 = NULL ;
goto V_119;
}
V_28 = F_286 ( V_3 , V_242 ) ;
break;
}
case V_261 : {
struct V_262 V_263 ;
V_28 = F_287 ( V_3 , & V_263 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_142 ;
if ( F_145 ( V_239 , & V_263 , sizeof V_263 ) )
goto V_119;
V_28 = 0 ;
break;
}
case V_264 : {
struct V_262 V_263 ;
V_28 = - V_142 ;
if ( F_288 ( & V_263 , V_239 , sizeof V_263 ) )
goto V_119;
V_28 = F_289 ( V_3 , & V_263 ) ;
break;
}
case V_265 : {
struct V_266 V_267 ;
V_28 = - V_142 ;
if ( F_288 ( & V_267 , V_239 , sizeof V_267 ) )
goto V_119;
V_28 = F_290 ( V_3 , & V_267 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_142 ;
if ( F_145 ( V_239 , & V_267 , sizeof V_267 ) )
goto V_119;
V_28 = 0 ;
break;
}
case V_268 : {
struct V_269 V_270 ;
V_28 = - V_142 ;
if ( F_288 ( & V_270 , V_239 , sizeof V_270 ) )
goto V_119;
V_28 = F_291 ( V_3 , & V_270 ) ;
break;
}
case V_271 : {
struct V_272 V_125 * V_273 = V_239 ;
struct V_272 V_274 ;
T_8 V_233 , * V_275 ;
V_275 = NULL ;
if ( V_239 ) {
V_28 = - V_142 ;
if ( F_288 ( & V_274 , V_239 ,
sizeof V_274 ) )
goto V_119;
V_28 = - V_113 ;
if ( V_274 . V_155 != sizeof V_233 )
goto V_119;
V_28 = - V_142 ;
if ( F_288 ( & V_233 , V_273 -> V_233 ,
sizeof V_233 ) )
goto V_119;
V_275 = & V_233 ;
}
V_28 = F_272 ( V_3 , V_275 ) ;
break;
}
case V_276 : {
V_241 = F_80 ( sizeof( struct V_240 ) , V_32 ) ;
V_28 = - V_34 ;
if ( ! V_241 )
goto V_119;
V_28 = F_292 ( V_3 , V_241 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_142 ;
if ( F_145 ( V_239 , V_241 , sizeof( struct V_240 ) ) )
goto V_119;
V_28 = 0 ;
break;
}
case V_277 : {
V_241 = F_283 ( V_239 , sizeof( * V_241 ) ) ;
if ( F_264 ( V_241 ) ) {
V_28 = F_265 ( V_241 ) ;
V_241 = NULL ;
goto V_119;
}
V_28 = F_293 ( V_3 , V_241 ) ;
break;
}
default:
V_28 = F_277 ( V_100 , V_237 , V_238 ) ;
}
V_119:
F_11 ( V_3 ) ;
F_90 ( V_241 ) ;
F_90 ( V_242 ) ;
return V_28 ;
}
static long F_294 ( struct V_99 * V_100 ,
unsigned int V_237 , unsigned long V_238 )
{
struct V_2 * V_3 = V_100 -> V_101 ;
void V_125 * V_239 = F_295 ( V_238 ) ;
int V_28 ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_243 ;
switch ( V_237 ) {
case V_271 : {
struct V_272 V_125 * V_273 = V_239 ;
struct V_272 V_274 ;
T_9 V_278 ;
T_8 V_233 ;
if ( V_239 ) {
V_28 = - V_142 ;
if ( F_288 ( & V_274 , V_239 ,
sizeof V_274 ) )
goto V_119;
V_28 = - V_113 ;
if ( V_274 . V_155 != sizeof V_278 )
goto V_119;
V_28 = - V_142 ;
if ( F_288 ( & V_278 , V_273 -> V_233 ,
sizeof V_278 ) )
goto V_119;
F_296 ( & V_233 , & V_278 ) ;
V_28 = F_272 ( V_3 , & V_233 ) ;
} else
V_28 = F_272 ( V_3 , NULL ) ;
break;
}
default:
V_28 = F_275 ( V_100 , V_237 , V_238 ) ;
}
V_119:
return V_28 ;
}
static int F_297 ( struct V_92 * V_93 ,
int (* F_298)( struct V_92 * V_93 ,
struct V_279 * V_280 ) ,
unsigned long V_238 )
{
struct V_279 V_280 ;
if ( ! F_298 )
return - V_281 ;
if ( F_288 ( & V_280 , ( void V_125 * ) V_238 , sizeof( V_280 ) ) )
return - V_142 ;
return F_298 ( V_93 , & V_280 ) ;
}
static long F_299 ( struct V_99 * V_100 , unsigned int V_237 ,
unsigned long V_238 )
{
struct V_92 * V_93 = V_100 -> V_101 ;
switch ( V_237 ) {
case V_282 :
return F_297 ( V_93 , V_93 -> V_54 -> V_283 , V_238 ) ;
case V_284 :
return F_297 ( V_93 , V_93 -> V_54 -> V_285 , V_238 ) ;
case V_286 :
return F_297 ( V_93 , V_93 -> V_54 -> V_287 , V_238 ) ;
default:
if ( V_93 -> V_54 -> V_237 )
return V_93 -> V_54 -> V_237 ( V_93 , V_237 , V_238 ) ;
return - V_288 ;
}
}
static int F_300 ( struct V_98 * V_98 , struct V_99 * V_100 )
{
struct V_92 * V_93 = V_100 -> V_101 ;
struct V_9 * V_9 = V_93 -> V_9 ;
F_116 ( V_9 ) ;
return 0 ;
}
struct V_92 * F_301 ( struct V_99 * V_100 )
{
if ( V_100 -> V_289 != & V_290 )
return NULL ;
return V_100 -> V_101 ;
}
int F_302 ( struct V_291 * V_54 , T_4 type )
{
if ( type >= F_303 ( V_292 ) )
return - V_293 ;
if ( V_292 [ type ] != NULL )
return - V_132 ;
V_292 [ type ] = V_54 ;
return 0 ;
}
void F_304 ( T_4 type )
{
if ( V_292 [ type ] != NULL )
V_292 [ type ] = NULL ;
}
static int F_305 ( struct V_9 * V_9 ,
struct V_294 * V_295 )
{
struct V_291 * V_54 = NULL ;
struct V_92 * V_93 ;
bool V_296 = V_295 -> V_112 & V_297 ;
int V_188 ;
if ( V_295 -> type >= F_303 ( V_292 ) )
return - V_298 ;
V_54 = V_292 [ V_295 -> type ] ;
if ( V_54 == NULL )
return - V_298 ;
if ( V_296 )
return 0 ;
V_93 = F_80 ( sizeof( * V_93 ) , V_32 ) ;
if ( ! V_93 )
return - V_34 ;
V_93 -> V_54 = V_54 ;
V_93 -> V_9 = V_9 ;
V_188 = V_54 -> V_299 ( V_93 , V_295 -> type ) ;
if ( V_188 < 0 ) {
F_90 ( V_93 ) ;
return V_188 ;
}
V_188 = F_261 ( V_54 -> V_300 , & V_290 , V_93 , V_224 | V_225 ) ;
if ( V_188 < 0 ) {
V_54 -> V_95 ( V_93 ) ;
return V_188 ;
}
F_87 ( & V_93 -> V_94 , & V_9 -> V_78 ) ;
F_115 ( V_9 ) ;
V_295 -> V_301 = V_188 ;
return 0 ;
}
static long F_306 ( struct V_9 * V_9 , long V_238 )
{
switch ( V_238 ) {
case V_302 :
case V_303 :
case V_304 :
#ifdef F_307
case V_305 :
#endif
case V_306 :
#ifdef F_308
case V_307 :
#endif
#ifdef F_77
case V_308 :
#endif
case V_309 :
return 1 ;
#ifdef F_309
case V_310 :
return V_311 ;
#endif
default:
break;
}
return F_310 ( V_9 , V_238 ) ;
}
static long F_311 ( struct V_99 * V_100 ,
unsigned int V_237 , unsigned long V_238 )
{
struct V_9 * V_9 = V_100 -> V_101 ;
void V_125 * V_239 = ( void V_125 * ) V_238 ;
int V_28 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_243 ;
switch ( V_237 ) {
case V_312 :
V_28 = F_262 ( V_9 , V_238 ) ;
break;
case V_313 : {
struct V_107 V_314 ;
V_28 = - V_142 ;
if ( F_288 ( & V_314 , V_239 ,
sizeof V_314 ) )
goto V_119;
V_28 = F_143 ( V_9 , & V_314 ) ;
break;
}
case V_315 : {
struct V_137 log ;
V_28 = - V_142 ;
if ( F_288 ( & log , V_239 , sizeof log ) )
goto V_119;
V_28 = F_312 ( V_9 , & log ) ;
break;
}
#ifdef F_256
case V_316 : {
struct V_317 V_318 ;
V_28 = - V_142 ;
if ( F_288 ( & V_318 , V_239 , sizeof V_318 ) )
goto V_119;
V_28 = F_313 ( V_9 , & V_318 ) ;
break;
}
case V_319 : {
struct V_317 V_318 ;
V_28 = - V_142 ;
if ( F_288 ( & V_318 , V_239 , sizeof V_318 ) )
goto V_119;
V_28 = F_314 ( V_9 , & V_318 ) ;
break;
}
#endif
case V_320 : {
struct V_321 V_154 ;
V_28 = - V_142 ;
if ( F_288 ( & V_154 , V_239 , sizeof V_154 ) )
goto V_119;
V_28 = V_321 ( V_9 , & V_154 ) ;
break;
}
case V_322 : {
struct V_323 V_154 ;
V_28 = - V_142 ;
if ( F_288 ( & V_154 , V_239 , sizeof V_154 ) )
goto V_119;
V_28 = V_323 ( V_9 , & V_154 ) ;
break;
}
#ifdef F_307
case V_324 :
V_28 = 0 ;
F_142 ( & V_9 -> V_74 ) ;
if ( F_269 ( & V_9 -> V_231 ) != 0 )
V_28 = - V_325 ;
else
V_9 -> V_326 = V_238 ;
F_16 ( & V_9 -> V_74 ) ;
break;
#endif
#ifdef F_308
case V_327 : {
struct V_328 V_329 ;
V_28 = - V_142 ;
if ( F_288 ( & V_329 , V_239 , sizeof V_329 ) )
goto V_119;
V_28 = F_315 ( V_9 , & V_329 ) ;
break;
}
#endif
#ifdef F_316
case V_330 :
case V_331 : {
struct V_332 V_333 ;
V_28 = - V_142 ;
if ( F_288 ( & V_333 , V_239 , sizeof V_333 ) )
goto V_119;
V_28 = F_317 ( V_9 , & V_333 ,
V_237 == V_330 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_142 ;
if ( V_237 == V_330 ) {
if ( F_145 ( V_239 , & V_333 , sizeof V_333 ) )
goto V_119;
}
V_28 = 0 ;
break;
}
#endif
#ifdef F_309
case V_334 : {
struct V_335 V_336 ;
struct V_335 V_125 * V_337 ;
struct V_338 * V_339 ;
V_28 = - V_142 ;
if ( F_288 ( & V_336 , V_239 , sizeof( V_336 ) ) )
goto V_119;
V_28 = - V_113 ;
if ( V_336 . V_340 >= V_311 )
goto V_119;
if ( V_336 . V_112 )
goto V_119;
V_28 = - V_34 ;
V_339 = F_318 ( V_336 . V_340 * sizeof( * V_339 ) ) ;
if ( ! V_339 )
goto V_119;
V_28 = - V_142 ;
V_337 = V_239 ;
if ( F_288 ( V_339 , V_337 -> V_339 ,
V_336 . V_340 * sizeof( * V_339 ) ) )
goto V_341;
V_28 = F_319 ( V_9 , V_339 , V_336 . V_340 ,
V_336 . V_112 ) ;
V_341:
F_96 ( V_339 ) ;
break;
}
#endif
case V_342 : {
struct V_294 V_295 ;
V_28 = - V_142 ;
if ( F_288 ( & V_295 , V_239 , sizeof( V_295 ) ) )
goto V_119;
V_28 = F_305 ( V_9 , & V_295 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_142 ;
if ( F_145 ( V_239 , & V_295 , sizeof( V_295 ) ) )
goto V_119;
V_28 = 0 ;
break;
}
case V_343 :
V_28 = F_306 ( V_9 , V_238 ) ;
break;
default:
V_28 = F_320 ( V_100 , V_237 , V_238 ) ;
}
V_119:
return V_28 ;
}
static long F_321 ( struct V_99 * V_100 ,
unsigned int V_237 , unsigned long V_238 )
{
struct V_9 * V_9 = V_100 -> V_101 ;
int V_28 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_243 ;
switch ( V_237 ) {
case V_315 : {
struct V_344 V_345 ;
struct V_137 log ;
V_28 = - V_142 ;
if ( F_288 ( & V_345 , ( void V_125 * ) V_238 ,
sizeof( V_345 ) ) )
goto V_119;
log . V_115 = V_345 . V_115 ;
log . V_346 = V_345 . V_346 ;
log . V_347 = V_345 . V_347 ;
log . V_86 = F_295 ( V_345 . V_86 ) ;
V_28 = F_312 ( V_9 , & log ) ;
break;
}
default:
V_28 = F_311 ( V_100 , V_237 , V_238 ) ;
}
V_119:
return V_28 ;
}
static int F_322 ( unsigned long type )
{
int V_28 ;
struct V_9 * V_9 ;
V_9 = F_72 ( type ) ;
if ( F_264 ( V_9 ) )
return F_265 ( V_9 ) ;
#ifdef F_256
V_28 = F_323 ( V_9 ) ;
if ( V_28 < 0 ) {
F_116 ( V_9 ) ;
return V_28 ;
}
#endif
V_28 = F_261 ( L_2 , & V_348 , V_9 , V_224 | V_225 ) ;
if ( V_28 < 0 )
F_116 ( V_9 ) ;
return V_28 ;
}
static long F_324 ( struct V_99 * V_100 ,
unsigned int V_237 , unsigned long V_238 )
{
long V_28 = - V_113 ;
switch ( V_237 ) {
case V_349 :
if ( V_238 )
goto V_119;
V_28 = V_350 ;
break;
case V_351 :
V_28 = F_322 ( V_238 ) ;
break;
case V_343 :
V_28 = F_306 ( NULL , V_238 ) ;
break;
case V_352 :
if ( V_238 )
goto V_119;
V_28 = V_82 ;
#ifdef F_255
V_28 += V_82 ;
#endif
#ifdef F_256
V_28 += V_82 ;
#endif
break;
case V_353 :
case V_354 :
case V_355 :
V_28 = - V_356 ;
break;
default:
return F_325 ( V_100 , V_237 , V_238 ) ;
}
V_119:
return V_28 ;
}
static void F_326 ( void * V_357 )
{
int V_4 = F_327 () ;
int V_28 ;
if ( F_328 ( V_4 , V_358 ) )
return;
F_24 ( V_4 , V_358 ) ;
V_28 = F_329 () ;
if ( V_28 ) {
F_330 ( V_4 , V_358 ) ;
F_83 ( & V_359 ) ;
F_331 ( V_360 L_3
L_4 , V_4 ) ;
}
}
static void F_332 ( void )
{
F_333 ( & V_361 ) ;
if ( V_362 )
F_326 ( NULL ) ;
F_334 ( & V_361 ) ;
}
static void F_335 ( void * V_357 )
{
int V_4 = F_327 () ;
if ( ! F_328 ( V_4 , V_358 ) )
return;
F_330 ( V_4 , V_358 ) ;
F_336 () ;
}
static void F_337 ( void )
{
F_333 ( & V_361 ) ;
if ( V_362 )
F_335 ( NULL ) ;
F_334 ( & V_361 ) ;
}
static void F_338 ( void )
{
F_62 ( ! V_362 ) ;
V_362 -- ;
if ( ! V_362 )
F_339 ( F_335 , NULL , 1 ) ;
}
static void F_89 ( void )
{
F_333 ( & V_361 ) ;
F_338 () ;
F_334 ( & V_361 ) ;
}
static int F_76 ( void )
{
int V_28 = 0 ;
F_333 ( & V_361 ) ;
V_362 ++ ;
if ( V_362 == 1 ) {
F_85 ( & V_359 , 0 ) ;
F_339 ( F_326 , NULL , 1 ) ;
if ( F_269 ( & V_359 ) ) {
F_338 () ;
V_28 = - V_325 ;
}
}
F_334 ( & V_361 ) ;
return V_28 ;
}
static int F_340 ( struct V_363 * V_364 , unsigned long V_365 ,
void * V_226 )
{
int V_4 = ( long ) V_226 ;
V_365 &= ~ V_366 ;
switch ( V_365 ) {
case V_367 :
F_331 ( V_360 L_5 ,
V_4 ) ;
F_337 () ;
break;
case V_368 :
F_331 ( V_360 L_6 ,
V_4 ) ;
F_332 () ;
break;
}
return V_369 ;
}
static int F_341 ( struct V_363 * V_364 , unsigned long V_365 ,
void * V_226 )
{
F_331 ( V_360 L_7 ) ;
V_370 = true ;
F_339 ( F_335 , NULL , 1 ) ;
return V_369 ;
}
static void F_109 ( struct V_71 * V_371 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_371 -> V_372 ; V_11 ++ ) {
struct V_373 * V_374 = V_371 -> V_375 [ V_11 ] . V_93 ;
F_342 ( V_374 ) ;
}
F_90 ( V_371 ) ;
}
static inline int F_343 ( const struct V_376 * V_377 ,
const struct V_376 * V_378 )
{
if ( V_377 -> V_83 < V_378 -> V_83 )
return - 1 ;
if ( V_377 -> V_83 + V_377 -> V_155 > V_378 -> V_83 + V_378 -> V_155 )
return 1 ;
return 0 ;
}
static int F_344 ( const void * V_379 , const void * V_380 )
{
return F_343 ( V_379 , V_380 ) ;
}
static int F_345 ( struct V_71 * V_371 , struct V_373 * V_93 ,
T_6 V_83 , int V_155 )
{
V_371 -> V_375 [ V_371 -> V_372 ++ ] = (struct V_376 ) {
. V_83 = V_83 ,
. V_155 = V_155 ,
. V_93 = V_93 ,
} ;
F_346 ( V_371 -> V_375 , V_371 -> V_372 , sizeof( struct V_376 ) ,
F_344 , NULL ) ;
return 0 ;
}
static int F_347 ( struct V_71 * V_371 ,
T_6 V_83 , int V_155 )
{
struct V_376 * V_375 , V_381 ;
int V_382 ;
V_381 = (struct V_376 ) {
. V_83 = V_83 ,
. V_155 = V_155 ,
} ;
V_375 = bsearch ( & V_381 , V_371 -> V_375 , V_371 -> V_372 ,
sizeof( struct V_376 ) , F_344 ) ;
if ( V_375 == NULL )
return - V_141 ;
V_382 = V_375 - V_371 -> V_375 ;
while ( V_382 > 0 && F_343 ( & V_381 , & V_371 -> V_375 [ V_382 - 1 ] ) == 0 )
V_382 -- ;
return V_382 ;
}
static int F_348 ( struct V_71 * V_371 ,
struct V_376 * V_375 , const void * V_365 )
{
int V_45 ;
V_45 = F_347 ( V_371 , V_375 -> V_83 , V_375 -> V_155 ) ;
if ( V_45 < 0 )
return - V_356 ;
while ( V_45 < V_371 -> V_372 &&
F_343 ( V_375 , & V_371 -> V_375 [ V_45 ] ) == 0 ) {
if ( ! F_349 ( V_371 -> V_375 [ V_45 ] . V_93 , V_375 -> V_83 ,
V_375 -> V_155 , V_365 ) )
return V_45 ;
V_45 ++ ;
}
return - V_356 ;
}
int F_350 ( struct V_9 * V_9 , enum V_383 V_384 , T_6 V_83 ,
int V_155 , const void * V_365 )
{
struct V_71 * V_371 ;
struct V_376 V_375 ;
int V_28 ;
V_375 = (struct V_376 ) {
. V_83 = V_83 ,
. V_155 = V_155 ,
} ;
V_371 = F_351 ( V_9 -> V_70 [ V_384 ] , & V_9 -> V_46 ) ;
V_28 = F_348 ( V_371 , & V_375 , V_365 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
int F_352 ( struct V_9 * V_9 , enum V_383 V_384 , T_6 V_83 ,
int V_155 , const void * V_365 , long V_385 )
{
struct V_71 * V_371 ;
struct V_376 V_375 ;
V_375 = (struct V_376 ) {
. V_83 = V_83 ,
. V_155 = V_155 ,
} ;
V_371 = F_351 ( V_9 -> V_70 [ V_384 ] , & V_9 -> V_46 ) ;
if ( ( V_385 >= 0 ) && ( V_385 < V_371 -> V_372 ) &&
( F_343 ( & V_375 , & V_371 -> V_375 [ V_385 ] ) == 0 ) )
if ( ! F_349 ( V_371 -> V_375 [ V_385 ] . V_93 , V_83 , V_155 ,
V_365 ) )
return V_385 ;
return F_348 ( V_371 , & V_375 , V_365 ) ;
}
static int F_353 ( struct V_71 * V_371 , struct V_376 * V_375 ,
void * V_365 )
{
int V_45 ;
V_45 = F_347 ( V_371 , V_375 -> V_83 , V_375 -> V_155 ) ;
if ( V_45 < 0 )
return - V_356 ;
while ( V_45 < V_371 -> V_372 &&
F_343 ( V_375 , & V_371 -> V_375 [ V_45 ] ) == 0 ) {
if ( ! F_354 ( V_371 -> V_375 [ V_45 ] . V_93 , V_375 -> V_83 ,
V_375 -> V_155 , V_365 ) )
return V_45 ;
V_45 ++ ;
}
return - V_356 ;
}
int F_355 ( struct V_9 * V_9 , enum V_383 V_384 , T_6 V_83 ,
int V_155 , void * V_365 )
{
struct V_71 * V_371 ;
struct V_376 V_375 ;
int V_28 ;
V_375 = (struct V_376 ) {
. V_83 = V_83 ,
. V_155 = V_155 ,
} ;
V_371 = F_351 ( V_9 -> V_70 [ V_384 ] , & V_9 -> V_46 ) ;
V_28 = F_353 ( V_371 , & V_375 , V_365 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
int F_356 ( struct V_9 * V_9 , enum V_383 V_384 , T_6 V_83 ,
int V_155 , struct V_373 * V_93 )
{
struct V_71 * V_386 , * V_371 ;
V_371 = V_9 -> V_70 [ V_384 ] ;
if ( V_371 -> V_372 - V_371 -> V_387 > V_388 - 1 )
return - V_293 ;
V_386 = F_80 ( sizeof( * V_371 ) + ( ( V_371 -> V_372 + 1 ) *
sizeof( struct V_376 ) ) , V_32 ) ;
if ( ! V_386 )
return - V_34 ;
memcpy ( V_386 , V_371 , sizeof( * V_371 ) + ( V_371 -> V_372 *
sizeof( struct V_376 ) ) ) ;
F_345 ( V_386 , V_93 , V_83 , V_155 ) ;
F_128 ( V_9 -> V_70 [ V_384 ] , V_386 ) ;
F_129 ( & V_9 -> V_46 ) ;
F_90 ( V_371 ) ;
return 0 ;
}
int F_357 ( struct V_9 * V_9 , enum V_383 V_384 ,
struct V_373 * V_93 )
{
int V_11 , V_28 ;
struct V_71 * V_386 , * V_371 ;
V_371 = V_9 -> V_70 [ V_384 ] ;
V_28 = - V_141 ;
for ( V_11 = 0 ; V_11 < V_371 -> V_372 ; V_11 ++ )
if ( V_371 -> V_375 [ V_11 ] . V_93 == V_93 ) {
V_28 = 0 ;
break;
}
if ( V_28 )
return V_28 ;
V_386 = F_80 ( sizeof( * V_371 ) + ( ( V_371 -> V_372 - 1 ) *
sizeof( struct V_376 ) ) , V_32 ) ;
if ( ! V_386 )
return - V_34 ;
memcpy ( V_386 , V_371 , sizeof( * V_371 ) + V_11 * sizeof( struct V_376 ) ) ;
V_386 -> V_372 -- ;
memcpy ( V_386 -> V_375 + V_11 , V_371 -> V_375 + V_11 + 1 ,
( V_386 -> V_372 - V_11 ) * sizeof( struct V_376 ) ) ;
F_128 ( V_9 -> V_70 [ V_384 ] , V_386 ) ;
F_129 ( & V_9 -> V_46 ) ;
F_90 ( V_371 ) ;
return V_28 ;
}
static int F_358 ( void * V_389 , T_10 * V_365 )
{
unsigned V_185 = ( long ) V_389 ;
struct V_9 * V_9 ;
* V_365 = 0 ;
F_51 ( & V_79 ) ;
F_359 ( V_9 , & V_80 , V_80 )
* V_365 += * ( T_4 * ) ( ( void * ) V_9 + V_185 ) ;
F_53 ( & V_79 ) ;
return 0 ;
}
static int F_360 ( void * V_389 , T_10 * V_365 )
{
unsigned V_185 = ( long ) V_389 ;
struct V_9 * V_9 ;
struct V_2 * V_3 ;
int V_11 ;
* V_365 = 0 ;
F_51 ( & V_79 ) ;
F_359 (kvm, &vm_list, vm_list)
F_20 ( V_11 , V_3 , V_9 )
* V_365 += * ( T_4 * ) ( ( void * ) V_3 + V_185 ) ;
F_53 ( & V_79 ) ;
return 0 ;
}
static int F_361 ( void )
{
int V_28 = - V_132 ;
struct V_390 * V_275 ;
V_391 = F_362 ( L_8 , NULL ) ;
if ( V_391 == NULL )
goto V_119;
for ( V_275 = V_392 ; V_275 -> V_300 ; ++ V_275 ) {
V_275 -> V_393 = F_363 ( V_275 -> V_300 , 0444 , V_391 ,
( void * ) ( long ) V_275 -> V_185 ,
V_394 [ V_275 -> V_395 ] ) ;
if ( V_275 -> V_393 == NULL )
goto V_396;
}
return 0 ;
V_396:
F_364 ( V_391 ) ;
V_119:
return V_28 ;
}
static void F_365 ( void )
{
struct V_390 * V_275 ;
for ( V_275 = V_392 ; V_275 -> V_300 ; ++ V_275 )
F_366 ( V_275 -> V_393 ) ;
F_366 ( V_391 ) ;
}
static int F_367 ( void )
{
if ( V_362 )
F_335 ( NULL ) ;
return 0 ;
}
static void F_368 ( void )
{
if ( V_362 ) {
F_123 ( F_369 ( & V_361 ) ) ;
F_326 ( NULL ) ;
}
}
static inline
struct V_2 * F_370 ( struct V_7 * V_397 )
{
return F_48 ( V_397 , struct V_2 , V_7 ) ;
}
static void F_371 ( struct V_7 * V_397 , int V_4 )
{
struct V_2 * V_3 = F_370 ( V_397 ) ;
if ( V_3 -> V_37 )
V_3 -> V_37 = false ;
F_372 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_373 ( struct V_7 * V_397 ,
struct V_156 * V_398 )
{
struct V_2 * V_3 = F_370 ( V_397 ) ;
if ( V_56 -> V_399 == V_400 )
V_3 -> V_37 = true ;
F_13 ( V_3 ) ;
}
int F_374 ( void * V_401 , unsigned V_402 , unsigned V_403 ,
struct V_404 * V_404 )
{
int V_28 ;
int V_4 ;
V_28 = F_375 ( V_401 ) ;
if ( V_28 )
goto V_405;
V_28 = F_376 () ;
if ( V_28 )
goto V_406;
if ( ! F_19 ( & V_358 , V_32 ) ) {
V_28 = - V_34 ;
goto V_407;
}
V_28 = F_377 () ;
if ( V_28 < 0 )
goto V_408;
F_378 (cpu) {
F_379 ( V_4 ,
V_409 ,
& V_28 , 1 ) ;
if ( V_28 < 0 )
goto V_410;
}
V_28 = F_380 ( & V_411 ) ;
if ( V_28 )
goto V_412;
F_381 ( & V_413 ) ;
if ( ! V_403 )
V_403 = F_382 ( struct V_2 ) ;
V_414 = F_383 ( L_9 , V_402 , V_403 ,
0 , NULL ) ;
if ( ! V_414 ) {
V_28 = - V_34 ;
goto V_415;
}
V_28 = F_384 () ;
if ( V_28 )
goto V_133;
V_416 . V_417 = V_404 ;
V_348 . V_417 = V_404 ;
V_223 . V_417 = V_404 ;
V_28 = F_385 ( & V_418 ) ;
if ( V_28 ) {
F_331 ( V_419 L_10 ) ;
goto V_420;
}
F_386 ( & V_421 ) ;
V_228 . V_422 = F_371 ;
V_228 . V_423 = F_373 ;
V_28 = F_361 () ;
if ( V_28 ) {
F_331 ( V_419 L_11 ) ;
goto V_424;
}
V_28 = F_387 () ;
F_123 ( V_28 ) ;
return 0 ;
V_424:
F_388 ( & V_421 ) ;
F_389 ( & V_418 ) ;
V_420:
F_390 () ;
V_133:
F_391 ( V_414 ) ;
V_415:
F_392 ( & V_413 ) ;
F_393 ( & V_411 ) ;
V_412:
V_410:
F_394 () ;
V_408:
F_28 ( V_358 ) ;
V_407:
F_395 () ;
V_406:
F_396 () ;
V_405:
return V_28 ;
}
void F_397 ( void )
{
F_365 () ;
F_389 ( & V_418 ) ;
F_391 ( V_414 ) ;
F_390 () ;
F_388 ( & V_421 ) ;
F_392 ( & V_413 ) ;
F_393 ( & V_411 ) ;
F_339 ( F_335 , NULL , 1 ) ;
F_394 () ;
F_396 () ;
F_395 () ;
F_28 ( V_358 ) ;
F_398 () ;
}
