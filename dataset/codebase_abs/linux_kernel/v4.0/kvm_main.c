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
void F_95 ( const void * V_83 )
{
if ( F_96 ( V_83 ) )
F_97 ( V_83 ) ;
else
F_91 ( V_83 ) ;
}
static void F_98 ( struct V_84 * V_85 )
{
if ( ! V_85 -> V_86 )
return;
F_95 ( V_85 -> V_86 ) ;
V_85 -> V_86 = NULL ;
}
static void F_99 ( struct V_9 * V_9 , struct V_84 * free ,
struct V_84 * V_87 )
{
if ( ! V_87 || free -> V_86 != V_87 -> V_86 )
F_98 ( free ) ;
F_100 ( V_9 , free , V_87 ) ;
free -> V_88 = 0 ;
}
static void F_101 ( struct V_9 * V_9 )
{
struct V_57 * V_58 = V_9 -> V_59 ;
struct V_84 * V_85 ;
F_102 (memslot, slots)
F_99 ( V_9 , V_85 , NULL ) ;
F_92 ( V_9 -> V_59 ) ;
}
static void F_103 ( struct V_9 * V_9 )
{
struct V_89 * V_90 , * V_91 ;
F_104 (node, tmp, &kvm->devices) {
struct V_92 * V_93 =
F_105 ( V_90 , struct V_92 , V_94 ) ;
F_106 ( V_90 ) ;
V_93 -> V_54 -> V_95 ( V_93 ) ;
}
}
static void F_107 ( struct V_9 * V_9 )
{
int V_11 ;
struct V_41 * V_42 = V_9 -> V_42 ;
F_108 ( V_9 ) ;
F_51 ( & V_79 ) ;
F_106 ( & V_9 -> V_80 ) ;
F_53 ( & V_79 ) ;
F_109 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_69 ; V_11 ++ )
F_110 ( V_9 -> V_70 [ V_11 ] ) ;
F_111 ( V_9 ) ;
#if F_112 ( V_96 ) && F_112 ( V_97 )
F_113 ( & V_9 -> V_39 , V_9 -> V_42 ) ;
#else
F_68 ( V_9 ) ;
#endif
F_114 ( V_9 ) ;
F_103 ( V_9 ) ;
F_101 ( V_9 ) ;
F_89 ( & V_9 -> V_67 ) ;
F_89 ( & V_9 -> V_46 ) ;
F_93 ( V_9 ) ;
F_90 () ;
F_115 ( V_42 ) ;
}
void F_116 ( struct V_9 * V_9 )
{
F_84 ( & V_9 -> V_77 ) ;
}
void F_117 ( struct V_9 * V_9 )
{
if ( F_118 ( & V_9 -> V_77 ) )
F_107 ( V_9 ) ;
}
static int F_119 ( struct V_98 * V_98 , struct V_99 * V_100 )
{
struct V_9 * V_9 = V_100 -> V_101 ;
F_120 ( V_9 ) ;
F_117 ( V_9 ) ;
return 0 ;
}
static int F_121 ( struct V_84 * V_85 )
{
unsigned long V_102 = 2 * F_122 ( V_85 ) ;
V_85 -> V_86 = F_80 ( V_102 ) ;
if ( ! V_85 -> V_86 )
return - V_34 ;
return 0 ;
}
static void F_123 ( struct V_57 * V_58 ,
struct V_84 * V_103 )
{
int V_26 = V_103 -> V_26 ;
int V_11 = V_58 -> V_61 [ V_26 ] ;
struct V_84 * V_104 = V_58 -> V_59 ;
F_124 ( V_104 [ V_11 ] . V_26 != V_26 ) ;
if ( ! V_103 -> V_88 ) {
F_124 ( ! V_104 [ V_11 ] . V_88 ) ;
V_103 -> V_105 = 0 ;
V_103 -> V_106 = 0 ;
if ( V_104 [ V_11 ] . V_88 )
V_58 -> V_107 -- ;
} else {
if ( ! V_104 [ V_11 ] . V_88 )
V_58 -> V_107 ++ ;
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
F_125 ( V_11 != V_58 -> V_107 ) ;
V_104 [ V_11 ] = * V_103 ;
V_58 -> V_61 [ V_104 [ V_11 ] . V_26 ] = V_11 ;
}
static int F_126 ( struct V_108 * V_109 )
{
T_4 V_110 = V_111 ;
#ifdef F_127
V_110 |= V_112 ;
#endif
if ( V_109 -> V_106 & ~ V_110 )
return - V_113 ;
return 0 ;
}
static struct V_57 * F_128 ( struct V_9 * V_9 ,
struct V_57 * V_58 )
{
struct V_57 * V_114 = V_9 -> V_59 ;
F_124 ( V_114 -> V_66 & 1 ) ;
V_58 -> V_66 = V_114 -> V_66 + 1 ;
F_129 ( V_9 -> V_59 , V_58 ) ;
F_130 ( & V_9 -> V_46 ) ;
V_58 -> V_66 ++ ;
F_131 ( V_9 ) ;
return V_114 ;
}
int F_132 ( struct V_9 * V_9 ,
struct V_108 * V_109 )
{
int V_28 ;
T_5 V_105 ;
unsigned long V_88 ;
struct V_84 * V_115 ;
struct V_84 V_116 , V_103 ;
struct V_57 * V_58 = NULL , * V_114 ;
enum V_117 V_118 ;
V_28 = F_126 ( V_109 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_113 ;
if ( V_109 -> V_120 & ( V_82 - 1 ) )
goto V_119;
if ( V_109 -> V_121 & ( V_82 - 1 ) )
goto V_119;
if ( ( V_109 -> V_115 < V_122 ) &&
( ( V_109 -> V_123 & ( V_82 - 1 ) ) ||
! F_133 ( V_124 ,
( void V_125 * ) ( unsigned long ) V_109 -> V_123 ,
V_109 -> V_120 ) ) )
goto V_119;
if ( V_109 -> V_115 >= V_60 )
goto V_119;
if ( V_109 -> V_121 + V_109 -> V_120 < V_109 -> V_121 )
goto V_119;
V_115 = F_134 ( V_9 -> V_59 , V_109 -> V_115 ) ;
V_105 = V_109 -> V_121 >> V_126 ;
V_88 = V_109 -> V_120 >> V_126 ;
if ( V_88 > V_127 )
goto V_119;
if ( ! V_88 )
V_109 -> V_106 &= ~ V_111 ;
V_103 = V_116 = * V_115 ;
V_103 . V_26 = V_109 -> V_115 ;
V_103 . V_105 = V_105 ;
V_103 . V_88 = V_88 ;
V_103 . V_106 = V_109 -> V_106 ;
if ( V_88 ) {
if ( ! V_116 . V_88 )
V_118 = V_128 ;
else {
if ( ( V_109 -> V_123 != V_116 . V_123 ) ||
( V_88 != V_116 . V_88 ) ||
( ( V_103 . V_106 ^ V_116 . V_106 ) & V_112 ) )
goto V_119;
if ( V_105 != V_116 . V_105 )
V_118 = V_129 ;
else if ( V_103 . V_106 != V_116 . V_106 )
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
F_102 (slot, kvm->memslots) {
if ( ( V_115 -> V_26 >= V_122 ) ||
( V_115 -> V_26 == V_109 -> V_115 ) )
continue;
if ( ! ( ( V_105 + V_88 <= V_115 -> V_105 ) ||
( V_105 >= V_115 -> V_105 + V_115 -> V_88 ) ) )
goto V_119;
}
}
if ( ! ( V_103 . V_106 & V_111 ) )
V_103 . V_86 = NULL ;
V_28 = - V_34 ;
if ( V_118 == V_128 ) {
V_103 . V_123 = V_109 -> V_123 ;
if ( F_135 ( V_9 , & V_103 , V_88 ) )
goto V_133;
}
if ( ( V_103 . V_106 & V_111 ) && ! V_103 . V_86 ) {
if ( F_121 ( & V_103 ) < 0 )
goto V_133;
}
V_58 = F_80 ( sizeof( struct V_57 ) ) ;
if ( ! V_58 )
goto V_133;
memcpy ( V_58 , V_9 -> V_59 , sizeof( struct V_57 ) ) ;
if ( ( V_118 == V_131 ) || ( V_118 == V_129 ) ) {
V_115 = F_134 ( V_58 , V_109 -> V_115 ) ;
V_115 -> V_106 |= V_134 ;
V_114 = F_128 ( V_9 , V_58 ) ;
F_136 ( V_9 , & V_116 ) ;
F_137 ( V_9 , V_115 ) ;
V_58 = V_114 ;
}
V_28 = F_138 ( V_9 , & V_103 , V_109 , V_118 ) ;
if ( V_28 )
goto V_135;
if ( V_118 == V_131 ) {
V_103 . V_86 = NULL ;
memset ( & V_103 . V_136 , 0 , sizeof( V_103 . V_136 ) ) ;
}
F_123 ( V_58 , & V_103 ) ;
V_114 = F_128 ( V_9 , V_58 ) ;
F_139 ( V_9 , V_109 , & V_116 , V_118 ) ;
F_99 ( V_9 , & V_116 , & V_103 ) ;
F_92 ( V_114 ) ;
if ( ( V_118 == V_128 ) || ( V_118 == V_129 ) ) {
V_28 = F_140 ( V_9 , & V_103 ) ;
return V_28 ;
}
return 0 ;
V_135:
F_92 ( V_58 ) ;
V_133:
F_99 ( V_9 , & V_103 , & V_116 ) ;
V_119:
return V_28 ;
}
int F_141 ( struct V_9 * V_9 ,
struct V_108 * V_109 )
{
int V_28 ;
F_142 ( & V_9 -> V_76 ) ;
V_28 = F_132 ( V_9 , V_109 ) ;
F_16 ( & V_9 -> V_76 ) ;
return V_28 ;
}
static int F_143 ( struct V_9 * V_9 ,
struct V_108 * V_109 )
{
if ( V_109 -> V_115 >= V_122 )
return - V_113 ;
return F_141 ( V_9 , V_109 ) ;
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
V_85 = F_134 ( V_9 -> V_59 , log -> V_115 ) ;
V_28 = - V_141 ;
if ( ! V_85 -> V_86 )
goto V_119;
V_139 = F_122 ( V_85 ) ;
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
int F_146 ( struct V_9 * V_9 ,
struct V_137 * log , bool * V_138 )
{
struct V_84 * V_85 ;
int V_28 , V_11 ;
unsigned long V_139 ;
unsigned long * V_86 ;
unsigned long * V_143 ;
V_28 = - V_113 ;
if ( log -> V_115 >= V_122 )
goto V_119;
V_85 = F_134 ( V_9 -> V_59 , log -> V_115 ) ;
V_86 = V_85 -> V_86 ;
V_28 = - V_141 ;
if ( ! V_86 )
goto V_119;
V_139 = F_122 ( V_85 ) ;
V_143 = V_86 + V_139 / sizeof( long ) ;
memset ( V_143 , 0 , V_139 ) ;
F_51 ( & V_9 -> V_47 ) ;
* V_138 = false ;
for ( V_11 = 0 ; V_11 < V_139 / sizeof( long ) ; V_11 ++ ) {
unsigned long V_144 ;
T_5 V_145 ;
if ( ! V_86 [ V_11 ] )
continue;
* V_138 = true ;
V_144 = F_147 ( & V_86 [ V_11 ] , 0 ) ;
V_143 [ V_11 ] = V_144 ;
V_145 = V_11 * V_146 ;
F_148 ( V_9 , V_85 , V_145 ,
V_144 ) ;
}
F_53 ( & V_9 -> V_47 ) ;
V_28 = - V_142 ;
if ( F_145 ( log -> V_86 , V_143 , V_139 ) )
goto V_119;
V_28 = 0 ;
V_119:
return V_28 ;
}
bool F_149 ( void )
{
return V_147 ;
}
void F_150 ( void )
{
V_147 = false ;
}
struct V_84 * F_151 ( struct V_9 * V_9 , T_5 V_148 )
{
return F_152 ( V_57 ( V_9 ) , V_148 ) ;
}
int F_153 ( struct V_9 * V_9 , T_5 V_148 )
{
struct V_84 * V_85 = F_151 ( V_9 , V_148 ) ;
if ( ! V_85 || V_85 -> V_26 >= V_122 ||
V_85 -> V_106 & V_134 )
return 0 ;
return 1 ;
}
unsigned long F_154 ( struct V_9 * V_9 , T_5 V_148 )
{
struct V_149 * V_150 ;
unsigned long V_83 , V_81 ;
V_81 = V_82 ;
V_83 = F_155 ( V_9 , V_148 ) ;
if ( F_156 ( V_83 ) )
return V_82 ;
F_157 ( & V_56 -> V_42 -> V_151 ) ;
V_150 = F_158 ( V_56 -> V_42 , V_83 ) ;
if ( ! V_150 )
goto V_119;
V_81 = F_159 ( V_150 ) ;
V_119:
F_160 ( & V_56 -> V_42 -> V_151 ) ;
return V_81 ;
}
static bool F_161 ( struct V_84 * V_115 )
{
return V_115 -> V_106 & V_112 ;
}
static unsigned long F_162 ( struct V_84 * V_115 , T_5 V_148 ,
T_5 * V_152 , bool V_153 )
{
if ( ! V_115 || V_115 -> V_106 & V_134 )
return V_154 ;
if ( F_161 ( V_115 ) && V_153 )
return V_155 ;
if ( V_152 )
* V_152 = V_115 -> V_88 - ( V_148 - V_115 -> V_105 ) ;
return F_163 ( V_115 , V_148 ) ;
}
static unsigned long F_164 ( struct V_84 * V_115 , T_5 V_148 ,
T_5 * V_152 )
{
return F_162 ( V_115 , V_148 , V_152 , true ) ;
}
unsigned long F_165 ( struct V_84 * V_115 ,
T_5 V_148 )
{
return F_164 ( V_115 , V_148 , NULL ) ;
}
unsigned long F_155 ( struct V_9 * V_9 , T_5 V_148 )
{
return F_164 ( F_151 ( V_9 , V_148 ) , V_148 , NULL ) ;
}
unsigned long F_166 ( struct V_84 * V_115 ,
T_5 V_148 , bool * V_156 )
{
unsigned long V_157 = F_162 ( V_115 , V_148 , NULL , false ) ;
if ( ! F_156 ( V_157 ) && V_156 )
* V_156 = ! F_161 ( V_115 ) ;
return V_157 ;
}
unsigned long F_167 ( struct V_9 * V_9 , T_5 V_148 , bool * V_156 )
{
struct V_84 * V_115 = F_151 ( V_9 , V_148 ) ;
return F_166 ( V_115 , V_148 , V_156 ) ;
}
static int F_168 ( void * V_158 , void V_125 * V_157 , int V_159 )
{
return F_169 ( V_158 , V_157 , V_159 ) ;
}
static int F_170 ( void * V_158 , void V_125 * V_157 , int V_159 )
{
return F_171 ( V_158 , V_157 , V_159 ) ;
}
static int F_172 ( struct V_160 * V_161 , struct V_41 * V_42 ,
unsigned long V_50 , int V_153 , struct V_27 * * V_27 )
{
int V_106 = V_162 | V_163 | V_164 | V_165 ;
if ( V_153 )
V_106 |= V_166 ;
return F_173 ( V_161 , V_42 , V_50 , 1 , V_106 , V_27 , NULL , NULL ) ;
}
static inline int F_174 ( unsigned long V_83 )
{
int V_167 , V_106 = V_162 | V_164 | V_166 ;
V_167 = F_173 ( V_56 , V_56 -> V_42 , V_83 , 1 ,
V_106 , NULL , NULL , NULL ) ;
return V_167 == - V_168 ;
}
static bool F_175 ( unsigned long V_83 , bool V_169 , bool * V_170 ,
bool V_171 , bool * V_156 , T_1 * V_1 )
{
struct V_27 * V_27 [ 1 ] ;
int V_88 ;
if ( ! ( V_170 || V_169 ) )
return false ;
if ( ! ( V_171 || V_156 ) )
return false ;
V_88 = F_176 ( V_83 , 1 , 1 , V_27 ) ;
if ( V_88 == 1 ) {
* V_1 = F_177 ( V_27 [ 0 ] ) ;
if ( V_156 )
* V_156 = true ;
return true ;
}
return false ;
}
static int F_178 ( unsigned long V_83 , bool * V_170 , bool V_171 ,
bool * V_156 , T_1 * V_1 )
{
struct V_27 * V_27 [ 1 ] ;
int V_88 = 0 ;
F_179 () ;
if ( V_156 )
* V_156 = V_171 ;
if ( V_170 ) {
F_157 ( & V_56 -> V_42 -> V_151 ) ;
V_88 = F_172 ( V_56 , V_56 -> V_42 ,
V_83 , V_171 , V_27 ) ;
F_160 ( & V_56 -> V_42 -> V_151 ) ;
} else
V_88 = F_180 ( V_56 , V_56 -> V_42 , V_83 , 1 ,
V_171 , 0 , V_27 ,
V_162 | V_164 ) ;
if ( V_88 != 1 )
return V_88 ;
if ( F_25 ( ! V_171 ) && V_156 ) {
struct V_27 * V_172 [ 1 ] ;
V_88 = F_176 ( V_83 , 1 , 1 , V_172 ) ;
if ( V_88 == 1 ) {
* V_156 = true ;
F_181 ( V_27 [ 0 ] ) ;
V_27 [ 0 ] = V_172 [ 0 ] ;
}
V_88 = 1 ;
}
* V_1 = F_177 ( V_27 [ 0 ] ) ;
return V_88 ;
}
static bool F_182 ( struct V_149 * V_150 , bool V_171 )
{
if ( F_25 ( ! ( V_150 -> V_173 & V_174 ) ) )
return false ;
if ( V_171 && ( F_25 ( ! ( V_150 -> V_173 & V_175 ) ) ) )
return false ;
return true ;
}
static T_1 F_183 ( unsigned long V_83 , bool V_169 , bool * V_170 ,
bool V_171 , bool * V_156 )
{
struct V_149 * V_150 ;
T_1 V_1 = 0 ;
int V_88 ;
F_62 ( V_169 && V_170 ) ;
if ( F_175 ( V_83 , V_169 , V_170 , V_171 , V_156 , & V_1 ) )
return V_1 ;
if ( V_169 )
return V_176 ;
V_88 = F_178 ( V_83 , V_170 , V_171 , V_156 , & V_1 ) ;
if ( V_88 == 1 )
return V_1 ;
F_157 ( & V_56 -> V_42 -> V_151 ) ;
if ( V_88 == - V_168 ||
( ! V_170 && F_174 ( V_83 ) ) ) {
V_1 = V_177 ;
goto exit;
}
V_150 = F_184 ( V_56 -> V_42 , V_83 , V_83 + 1 ) ;
if ( V_150 == NULL )
V_1 = V_176 ;
else if ( ( V_150 -> V_173 & V_178 ) ) {
V_1 = ( ( V_83 - V_150 -> V_179 ) >> V_126 ) +
V_150 -> V_180 ;
F_62 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_170 && F_182 ( V_150 , V_171 ) )
* V_170 = true ;
V_1 = V_176 ;
}
exit:
F_160 ( & V_56 -> V_42 -> V_151 ) ;
return V_1 ;
}
static T_1
F_185 ( struct V_84 * V_115 , T_5 V_148 , bool V_169 ,
bool * V_170 , bool V_171 , bool * V_156 )
{
unsigned long V_83 = F_162 ( V_115 , V_148 , NULL , V_171 ) ;
if ( V_83 == V_155 )
return V_181 ;
if ( F_156 ( V_83 ) )
return V_182 ;
if ( V_156 && F_161 ( V_115 ) ) {
* V_156 = false ;
V_156 = NULL ;
}
return F_183 ( V_83 , V_169 , V_170 , V_171 ,
V_156 ) ;
}
static T_1 F_186 ( struct V_9 * V_9 , T_5 V_148 , bool V_169 , bool * V_170 ,
bool V_171 , bool * V_156 )
{
struct V_84 * V_115 ;
if ( V_170 )
* V_170 = false ;
V_115 = F_151 ( V_9 , V_148 ) ;
return F_185 ( V_115 , V_148 , V_169 , V_170 , V_171 ,
V_156 ) ;
}
T_1 F_187 ( struct V_9 * V_9 , T_5 V_148 )
{
return F_186 ( V_9 , V_148 , true , NULL , true , NULL ) ;
}
T_1 F_188 ( struct V_9 * V_9 , T_5 V_148 , bool * V_170 ,
bool V_171 , bool * V_156 )
{
return F_186 ( V_9 , V_148 , false , V_170 , V_171 , V_156 ) ;
}
T_1 F_189 ( struct V_9 * V_9 , T_5 V_148 )
{
return F_186 ( V_9 , V_148 , false , NULL , true , NULL ) ;
}
T_1 F_190 ( struct V_9 * V_9 , T_5 V_148 , bool V_171 ,
bool * V_156 )
{
return F_186 ( V_9 , V_148 , false , NULL , V_171 , V_156 ) ;
}
T_1 F_191 ( struct V_84 * V_115 , T_5 V_148 )
{
return F_185 ( V_115 , V_148 , false , NULL , true , NULL ) ;
}
T_1 F_192 ( struct V_84 * V_115 , T_5 V_148 )
{
return F_185 ( V_115 , V_148 , true , NULL , true , NULL ) ;
}
int F_193 ( struct V_9 * V_9 , T_5 V_148 , struct V_27 * * V_183 ,
int V_152 )
{
unsigned long V_83 ;
T_5 V_184 ;
V_83 = F_164 ( F_151 ( V_9 , V_148 ) , V_148 , & V_184 ) ;
if ( F_156 ( V_83 ) )
return - 1 ;
if ( V_184 < V_152 )
return 0 ;
return F_176 ( V_83 , V_152 , 1 , V_183 ) ;
}
static struct V_27 * F_194 ( T_1 V_1 )
{
if ( F_195 ( V_1 ) )
return V_185 ;
if ( F_1 ( V_1 ) ) {
F_124 ( 1 ) ;
return V_185 ;
}
return F_4 ( V_1 ) ;
}
struct V_27 * F_196 ( struct V_9 * V_9 , T_5 V_148 )
{
T_1 V_1 ;
V_1 = F_189 ( V_9 , V_148 ) ;
return F_194 ( V_1 ) ;
}
void F_197 ( struct V_27 * V_27 )
{
F_124 ( F_198 ( V_27 ) ) ;
F_199 ( F_177 ( V_27 ) ) ;
}
void F_199 ( T_1 V_1 )
{
if ( ! F_195 ( V_1 ) && ! F_1 ( V_1 ) )
F_181 ( F_4 ( V_1 ) ) ;
}
void F_200 ( struct V_27 * V_27 )
{
F_124 ( F_198 ( V_27 ) ) ;
F_201 ( F_177 ( V_27 ) ) ;
}
static void F_201 ( T_1 V_1 )
{
F_202 ( V_1 ) ;
F_199 ( V_1 ) ;
}
void F_202 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_27 * V_27 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_27 ) )
F_203 ( V_27 ) ;
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
static int F_208 ( unsigned long V_159 , int V_145 )
{
if ( V_159 > V_82 - V_145 )
return V_82 - V_145 ;
else
return V_159 ;
}
int F_209 ( struct V_9 * V_9 , T_5 V_148 , void * V_158 , int V_145 ,
int V_159 )
{
int V_28 ;
unsigned long V_83 ;
V_83 = F_167 ( V_9 , V_148 , NULL ) ;
if ( F_156 ( V_83 ) )
return - V_142 ;
V_28 = F_168 ( V_158 , ( void V_125 * ) V_83 + V_145 , V_159 ) ;
if ( V_28 )
return - V_142 ;
return 0 ;
}
int F_210 ( struct V_9 * V_9 , T_6 V_186 , void * V_158 , unsigned long V_159 )
{
T_5 V_148 = V_186 >> V_126 ;
int V_187 ;
int V_145 = F_211 ( V_186 ) ;
int V_188 ;
while ( ( V_187 = F_208 ( V_159 , V_145 ) ) != 0 ) {
V_188 = F_209 ( V_9 , V_148 , V_158 , V_145 , V_187 ) ;
if ( V_188 < 0 )
return V_188 ;
V_145 = 0 ;
V_159 -= V_187 ;
V_158 += V_187 ;
++ V_148 ;
}
return 0 ;
}
int F_212 ( struct V_9 * V_9 , T_6 V_186 , void * V_158 ,
unsigned long V_159 )
{
int V_28 ;
unsigned long V_83 ;
T_5 V_148 = V_186 >> V_126 ;
int V_145 = F_211 ( V_186 ) ;
V_83 = F_167 ( V_9 , V_148 , NULL ) ;
if ( F_156 ( V_83 ) )
return - V_142 ;
F_213 () ;
V_28 = F_170 ( V_158 , ( void V_125 * ) V_83 + V_145 , V_159 ) ;
F_214 () ;
if ( V_28 )
return - V_142 ;
return 0 ;
}
int F_215 ( struct V_9 * V_9 , T_5 V_148 , const void * V_158 ,
int V_145 , int V_159 )
{
int V_28 ;
unsigned long V_83 ;
V_83 = F_155 ( V_9 , V_148 ) ;
if ( F_156 ( V_83 ) )
return - V_142 ;
V_28 = F_216 ( ( void V_125 * ) V_83 + V_145 , V_158 , V_159 ) ;
if ( V_28 )
return - V_142 ;
F_217 ( V_9 , V_148 ) ;
return 0 ;
}
int F_218 ( struct V_9 * V_9 , T_6 V_186 , const void * V_158 ,
unsigned long V_159 )
{
T_5 V_148 = V_186 >> V_126 ;
int V_187 ;
int V_145 = F_211 ( V_186 ) ;
int V_188 ;
while ( ( V_187 = F_208 ( V_159 , V_145 ) ) != 0 ) {
V_188 = F_215 ( V_9 , V_148 , V_158 , V_145 , V_187 ) ;
if ( V_188 < 0 )
return V_188 ;
V_145 = 0 ;
V_159 -= V_187 ;
V_158 += V_187 ;
++ V_148 ;
}
return 0 ;
}
int F_219 ( struct V_9 * V_9 , struct V_189 * V_190 ,
T_6 V_186 , unsigned long V_159 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_145 = F_211 ( V_186 ) ;
T_5 V_191 = V_186 >> V_126 ;
T_5 V_192 = ( V_186 + V_159 - 1 ) >> V_126 ;
T_5 V_193 = V_192 - V_191 + 1 ;
T_5 V_194 ;
V_190 -> V_186 = V_186 ;
V_190 -> V_66 = V_58 -> V_66 ;
V_190 -> V_159 = V_159 ;
V_190 -> V_85 = F_151 ( V_9 , V_191 ) ;
V_190 -> V_157 = F_164 ( V_190 -> V_85 , V_191 , & V_194 ) ;
if ( ! F_156 ( V_190 -> V_157 ) && V_194 >= V_193 ) {
V_190 -> V_157 += V_145 ;
} else {
while ( V_191 <= V_192 ) {
V_190 -> V_85 = F_151 ( V_9 , V_191 ) ;
V_190 -> V_157 = F_164 ( V_190 -> V_85 , V_191 ,
& V_194 ) ;
if ( F_156 ( V_190 -> V_157 ) )
return - V_142 ;
V_191 += V_194 ;
}
V_190 -> V_85 = NULL ;
}
return 0 ;
}
int F_220 ( struct V_9 * V_9 , struct V_189 * V_190 ,
void * V_158 , unsigned long V_159 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_28 ;
F_62 ( V_159 > V_190 -> V_159 ) ;
if ( V_58 -> V_66 != V_190 -> V_66 )
F_219 ( V_9 , V_190 , V_190 -> V_186 , V_190 -> V_159 ) ;
if ( F_25 ( ! V_190 -> V_85 ) )
return F_218 ( V_9 , V_190 -> V_186 , V_158 , V_159 ) ;
if ( F_156 ( V_190 -> V_157 ) )
return - V_142 ;
V_28 = F_216 ( ( void V_125 * ) V_190 -> V_157 , V_158 , V_159 ) ;
if ( V_28 )
return - V_142 ;
F_221 ( V_9 , V_190 -> V_85 , V_190 -> V_186 >> V_126 ) ;
return 0 ;
}
int F_222 ( struct V_9 * V_9 , struct V_189 * V_190 ,
void * V_158 , unsigned long V_159 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_28 ;
F_62 ( V_159 > V_190 -> V_159 ) ;
if ( V_58 -> V_66 != V_190 -> V_66 )
F_219 ( V_9 , V_190 , V_190 -> V_186 , V_190 -> V_159 ) ;
if ( F_25 ( ! V_190 -> V_85 ) )
return F_210 ( V_9 , V_190 -> V_186 , V_158 , V_159 ) ;
if ( F_156 ( V_190 -> V_157 ) )
return - V_142 ;
V_28 = F_169 ( V_158 , ( void V_125 * ) V_190 -> V_157 , V_159 ) ;
if ( V_28 )
return - V_142 ;
return 0 ;
}
int F_223 ( struct V_9 * V_9 , T_5 V_148 , int V_145 , int V_159 )
{
const void * V_195 = ( const void * ) F_224 ( F_225 ( F_226 ( 0 ) ) ) ;
return F_215 ( V_9 , V_148 , V_195 , V_145 , V_159 ) ;
}
int F_227 ( struct V_9 * V_9 , T_6 V_186 , unsigned long V_159 )
{
T_5 V_148 = V_186 >> V_126 ;
int V_187 ;
int V_145 = F_211 ( V_186 ) ;
int V_188 ;
while ( ( V_187 = F_208 ( V_159 , V_145 ) ) != 0 ) {
V_188 = F_223 ( V_9 , V_148 , V_145 , V_187 ) ;
if ( V_188 < 0 )
return V_188 ;
V_145 = 0 ;
V_159 -= V_187 ;
++ V_148 ;
}
return 0 ;
}
static void F_221 ( struct V_9 * V_9 ,
struct V_84 * V_85 ,
T_5 V_148 )
{
if ( V_85 && V_85 -> V_86 ) {
unsigned long V_196 = V_148 - V_85 -> V_105 ;
F_228 ( V_196 , V_85 -> V_86 ) ;
}
}
void F_217 ( struct V_9 * V_9 , T_5 V_148 )
{
struct V_84 * V_85 ;
V_85 = F_151 ( V_9 , V_148 ) ;
F_221 ( V_9 , V_85 , V_148 ) ;
}
static int F_229 ( struct V_2 * V_3 )
{
if ( F_230 ( V_3 ) ) {
F_21 ( V_197 , V_3 ) ;
return - V_6 ;
}
if ( F_231 ( V_3 ) )
return - V_6 ;
if ( F_232 ( V_56 ) )
return - V_6 ;
return 0 ;
}
void F_233 ( struct V_2 * V_3 )
{
T_7 V_50 , V_198 ;
F_234 ( V_199 ) ;
bool V_200 = false ;
V_50 = V_198 = F_235 () ;
if ( V_201 ) {
T_7 V_202 = F_236 ( F_235 () , V_201 ) ;
do {
if ( F_229 ( V_3 ) < 0 ) {
++ V_3 -> V_21 . V_203 ;
goto V_119;
}
V_198 = F_235 () ;
} while ( F_237 () && F_238 ( V_198 , V_202 ) );
}
for (; ; ) {
F_239 ( & V_3 -> V_31 , & V_199 , V_204 ) ;
if ( F_229 ( V_3 ) < 0 )
break;
V_200 = true ;
F_240 () ;
}
F_241 ( & V_3 -> V_31 , & V_199 ) ;
V_198 = F_235 () ;
V_119:
F_242 ( F_243 ( V_198 ) - F_243 ( V_50 ) , V_200 ) ;
}
void F_244 ( struct V_2 * V_3 )
{
int V_12 ;
int V_4 = V_3 -> V_4 ;
T_8 * V_205 ;
V_205 = F_245 ( V_3 ) ;
if ( F_246 ( V_205 ) ) {
F_247 ( V_205 ) ;
++ V_3 -> V_21 . V_206 ;
}
V_12 = F_7 () ;
if ( V_4 != V_12 && ( unsigned ) V_4 < V_207 && F_248 ( V_4 ) )
if ( F_249 ( V_3 ) )
F_250 ( V_4 ) ;
F_10 () ;
}
int F_251 ( struct V_2 * V_208 )
{
struct V_30 * V_30 ;
struct V_160 * V_209 = NULL ;
int V_188 = 0 ;
F_252 () ;
V_30 = F_253 ( V_208 -> V_30 ) ;
if ( V_30 )
V_209 = F_254 ( V_30 , V_210 ) ;
F_255 () ;
if ( ! V_209 )
return V_188 ;
V_188 = F_256 ( V_209 , 1 ) ;
F_257 ( V_209 ) ;
return V_188 ;
}
static bool F_258 ( struct V_2 * V_3 )
{
#ifdef F_259
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
void F_260 ( struct V_2 * V_12 )
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
if ( ! F_261 ( V_3 -> V_37 ) )
continue;
if ( V_3 == V_12 )
continue;
if ( F_246 ( & V_3 -> V_31 ) && ! F_230 ( V_3 ) )
continue;
if ( ! F_258 ( V_3 ) )
continue;
V_216 = F_251 ( V_3 ) ;
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
static int F_262 ( struct V_149 * V_150 , struct V_219 * V_220 )
{
struct V_2 * V_3 = V_150 -> V_221 -> V_101 ;
struct V_27 * V_27 ;
if ( V_220 -> V_222 == 0 )
V_27 = F_263 ( V_3 -> V_36 ) ;
#ifdef F_264
else if ( V_220 -> V_222 == V_223 )
V_27 = F_263 ( V_3 -> V_136 . V_224 ) ;
#endif
#ifdef F_265
else if ( V_220 -> V_222 == F_265 )
V_27 = F_263 ( V_3 -> V_9 -> V_225 ) ;
#endif
else
return F_266 ( V_3 , V_220 ) ;
F_207 ( V_27 ) ;
V_220 -> V_27 = V_27 ;
return 0 ;
}
static int F_267 ( struct V_99 * V_99 , struct V_149 * V_150 )
{
V_150 -> V_226 = & V_227 ;
return 0 ;
}
static int F_268 ( struct V_98 * V_98 , struct V_99 * V_100 )
{
struct V_2 * V_3 = V_100 -> V_101 ;
F_117 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_269 ( struct V_2 * V_3 )
{
return F_270 ( L_1 , & V_228 , V_3 , V_229 | V_230 ) ;
}
static int F_271 ( struct V_9 * V_9 , T_4 V_26 )
{
int V_28 ;
struct V_2 * V_3 , * V_231 ;
if ( V_26 >= V_232 )
return - V_113 ;
V_3 = F_272 ( V_9 , V_26 ) ;
if ( F_273 ( V_3 ) )
return F_274 ( V_3 ) ;
F_275 ( & V_3 -> V_7 , & V_233 ) ;
V_28 = F_276 ( V_3 ) ;
if ( V_28 )
goto V_234;
F_142 ( & V_9 -> V_74 ) ;
if ( ! F_277 ( V_3 ) ) {
V_28 = - V_113 ;
goto V_235;
}
if ( F_278 ( & V_9 -> V_236 ) == V_232 ) {
V_28 = - V_113 ;
goto V_235;
}
F_20 (r, v, kvm)
if ( V_231 -> V_29 == V_26 ) {
V_28 = - V_132 ;
goto V_235;
}
F_62 ( V_9 -> V_237 [ F_278 ( & V_9 -> V_236 ) ] ) ;
F_116 ( V_9 ) ;
V_28 = F_269 ( V_3 ) ;
if ( V_28 < 0 ) {
F_117 ( V_9 ) ;
goto V_235;
}
V_9 -> V_237 [ F_278 ( & V_9 -> V_236 ) ] = V_3 ;
F_61 () ;
F_84 ( & V_9 -> V_236 ) ;
F_16 ( & V_9 -> V_74 ) ;
F_279 ( V_3 ) ;
return V_28 ;
V_235:
F_16 ( & V_9 -> V_74 ) ;
V_234:
F_280 ( V_3 ) ;
return V_28 ;
}
static int F_281 ( struct V_2 * V_3 , T_9 * V_238 )
{
if ( V_238 ) {
F_282 ( V_238 , F_283 ( V_239 ) | F_283 ( V_240 ) ) ;
V_3 -> V_241 = 1 ;
V_3 -> V_238 = * V_238 ;
} else
V_3 -> V_241 = 0 ;
return 0 ;
}
static long F_284 ( struct V_99 * V_100 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_2 * V_3 = V_100 -> V_101 ;
void V_125 * V_244 = ( void V_125 * ) V_243 ;
int V_28 ;
struct V_245 * V_246 = NULL ;
struct V_247 * V_247 = NULL ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_248 ;
if ( F_25 ( F_285 ( V_242 ) != V_249 ) )
return - V_113 ;
#if F_112 ( V_250 ) || F_112 ( V_251 ) || F_112 ( V_252 )
if ( V_242 == V_253 || V_242 == V_254 )
return F_286 ( V_100 , V_242 , V_243 ) ;
#endif
V_28 = F_5 ( V_3 ) ;
if ( V_28 )
return V_28 ;
switch ( V_242 ) {
case V_255 :
V_28 = - V_113 ;
if ( V_243 )
goto V_119;
if ( F_25 ( V_3 -> V_30 != V_56 -> V_256 [ V_210 ] . V_30 ) ) {
struct V_30 * V_257 = V_3 -> V_30 ;
struct V_30 * V_258 = F_287 ( V_56 , V_210 ) ;
F_129 ( V_3 -> V_30 , V_258 ) ;
if ( V_257 )
F_288 () ;
F_45 ( V_257 ) ;
}
V_28 = F_289 ( V_3 , V_3 -> V_36 ) ;
F_290 ( V_3 -> V_36 -> V_259 , V_28 ) ;
break;
case V_260 : {
struct V_261 * V_261 ;
V_28 = - V_34 ;
V_261 = F_82 ( sizeof( struct V_261 ) , V_32 ) ;
if ( ! V_261 )
goto V_119;
V_28 = F_291 ( V_3 , V_261 ) ;
if ( V_28 )
goto V_262;
V_28 = - V_142 ;
if ( F_145 ( V_244 , V_261 , sizeof( struct V_261 ) ) )
goto V_262;
V_28 = 0 ;
V_262:
F_91 ( V_261 ) ;
break;
}
case V_263 : {
struct V_261 * V_261 ;
V_28 = - V_34 ;
V_261 = F_292 ( V_244 , sizeof( * V_261 ) ) ;
if ( F_273 ( V_261 ) ) {
V_28 = F_274 ( V_261 ) ;
goto V_119;
}
V_28 = F_293 ( V_3 , V_261 ) ;
F_91 ( V_261 ) ;
break;
}
case V_264 : {
V_247 = F_82 ( sizeof( struct V_247 ) , V_32 ) ;
V_28 = - V_34 ;
if ( ! V_247 )
goto V_119;
V_28 = F_294 ( V_3 , V_247 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_142 ;
if ( F_145 ( V_244 , V_247 , sizeof( struct V_247 ) ) )
goto V_119;
V_28 = 0 ;
break;
}
case V_265 : {
V_247 = F_292 ( V_244 , sizeof( * V_247 ) ) ;
if ( F_273 ( V_247 ) ) {
V_28 = F_274 ( V_247 ) ;
V_247 = NULL ;
goto V_119;
}
V_28 = F_295 ( V_3 , V_247 ) ;
break;
}
case V_266 : {
struct V_267 V_268 ;
V_28 = F_296 ( V_3 , & V_268 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_142 ;
if ( F_145 ( V_244 , & V_268 , sizeof V_268 ) )
goto V_119;
V_28 = 0 ;
break;
}
case V_269 : {
struct V_267 V_268 ;
V_28 = - V_142 ;
if ( F_297 ( & V_268 , V_244 , sizeof V_268 ) )
goto V_119;
V_28 = F_298 ( V_3 , & V_268 ) ;
break;
}
case V_270 : {
struct V_271 V_272 ;
V_28 = - V_142 ;
if ( F_297 ( & V_272 , V_244 , sizeof V_272 ) )
goto V_119;
V_28 = F_299 ( V_3 , & V_272 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_142 ;
if ( F_145 ( V_244 , & V_272 , sizeof V_272 ) )
goto V_119;
V_28 = 0 ;
break;
}
case V_273 : {
struct V_274 V_275 ;
V_28 = - V_142 ;
if ( F_297 ( & V_275 , V_244 , sizeof V_275 ) )
goto V_119;
V_28 = F_300 ( V_3 , & V_275 ) ;
break;
}
case V_276 : {
struct V_277 V_125 * V_278 = V_244 ;
struct V_277 V_279 ;
T_9 V_238 , * V_280 ;
V_280 = NULL ;
if ( V_244 ) {
V_28 = - V_142 ;
if ( F_297 ( & V_279 , V_244 ,
sizeof V_279 ) )
goto V_119;
V_28 = - V_113 ;
if ( V_279 . V_159 != sizeof V_238 )
goto V_119;
V_28 = - V_142 ;
if ( F_297 ( & V_238 , V_278 -> V_238 ,
sizeof V_238 ) )
goto V_119;
V_280 = & V_238 ;
}
V_28 = F_281 ( V_3 , V_280 ) ;
break;
}
case V_281 : {
V_246 = F_82 ( sizeof( struct V_245 ) , V_32 ) ;
V_28 = - V_34 ;
if ( ! V_246 )
goto V_119;
V_28 = F_301 ( V_3 , V_246 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_142 ;
if ( F_145 ( V_244 , V_246 , sizeof( struct V_245 ) ) )
goto V_119;
V_28 = 0 ;
break;
}
case V_282 : {
V_246 = F_292 ( V_244 , sizeof( * V_246 ) ) ;
if ( F_273 ( V_246 ) ) {
V_28 = F_274 ( V_246 ) ;
V_246 = NULL ;
goto V_119;
}
V_28 = F_302 ( V_3 , V_246 ) ;
break;
}
default:
V_28 = F_286 ( V_100 , V_242 , V_243 ) ;
}
V_119:
F_11 ( V_3 ) ;
F_91 ( V_246 ) ;
F_91 ( V_247 ) ;
return V_28 ;
}
static long F_303 ( struct V_99 * V_100 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_2 * V_3 = V_100 -> V_101 ;
void V_125 * V_244 = F_304 ( V_243 ) ;
int V_28 ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_248 ;
switch ( V_242 ) {
case V_276 : {
struct V_277 V_125 * V_278 = V_244 ;
struct V_277 V_279 ;
T_10 V_283 ;
T_9 V_238 ;
if ( V_244 ) {
V_28 = - V_142 ;
if ( F_297 ( & V_279 , V_244 ,
sizeof V_279 ) )
goto V_119;
V_28 = - V_113 ;
if ( V_279 . V_159 != sizeof V_283 )
goto V_119;
V_28 = - V_142 ;
if ( F_297 ( & V_283 , V_278 -> V_238 ,
sizeof V_283 ) )
goto V_119;
F_305 ( & V_238 , & V_283 ) ;
V_28 = F_281 ( V_3 , & V_238 ) ;
} else
V_28 = F_281 ( V_3 , NULL ) ;
break;
}
default:
V_28 = F_284 ( V_100 , V_242 , V_243 ) ;
}
V_119:
return V_28 ;
}
static int F_306 ( struct V_92 * V_93 ,
int (* F_307)( struct V_92 * V_93 ,
struct V_284 * V_285 ) ,
unsigned long V_243 )
{
struct V_284 V_285 ;
if ( ! F_307 )
return - V_286 ;
if ( F_297 ( & V_285 , ( void V_125 * ) V_243 , sizeof( V_285 ) ) )
return - V_142 ;
return F_307 ( V_93 , & V_285 ) ;
}
static long F_308 ( struct V_99 * V_100 , unsigned int V_242 ,
unsigned long V_243 )
{
struct V_92 * V_93 = V_100 -> V_101 ;
switch ( V_242 ) {
case V_287 :
return F_306 ( V_93 , V_93 -> V_54 -> V_288 , V_243 ) ;
case V_289 :
return F_306 ( V_93 , V_93 -> V_54 -> V_290 , V_243 ) ;
case V_291 :
return F_306 ( V_93 , V_93 -> V_54 -> V_292 , V_243 ) ;
default:
if ( V_93 -> V_54 -> V_242 )
return V_93 -> V_54 -> V_242 ( V_93 , V_242 , V_243 ) ;
return - V_293 ;
}
}
static int F_309 ( struct V_98 * V_98 , struct V_99 * V_100 )
{
struct V_92 * V_93 = V_100 -> V_101 ;
struct V_9 * V_9 = V_93 -> V_9 ;
F_117 ( V_9 ) ;
return 0 ;
}
struct V_92 * F_310 ( struct V_99 * V_100 )
{
if ( V_100 -> V_294 != & V_295 )
return NULL ;
return V_100 -> V_101 ;
}
int F_311 ( struct V_296 * V_54 , T_4 type )
{
if ( type >= F_312 ( V_297 ) )
return - V_298 ;
if ( V_297 [ type ] != NULL )
return - V_132 ;
V_297 [ type ] = V_54 ;
return 0 ;
}
void F_313 ( T_4 type )
{
if ( V_297 [ type ] != NULL )
V_297 [ type ] = NULL ;
}
static int F_314 ( struct V_9 * V_9 ,
struct V_299 * V_300 )
{
struct V_296 * V_54 = NULL ;
struct V_92 * V_93 ;
bool V_301 = V_300 -> V_106 & V_302 ;
int V_188 ;
if ( V_300 -> type >= F_312 ( V_297 ) )
return - V_303 ;
V_54 = V_297 [ V_300 -> type ] ;
if ( V_54 == NULL )
return - V_303 ;
if ( V_301 )
return 0 ;
V_93 = F_82 ( sizeof( * V_93 ) , V_32 ) ;
if ( ! V_93 )
return - V_34 ;
V_93 -> V_54 = V_54 ;
V_93 -> V_9 = V_9 ;
V_188 = V_54 -> V_304 ( V_93 , V_300 -> type ) ;
if ( V_188 < 0 ) {
F_91 ( V_93 ) ;
return V_188 ;
}
V_188 = F_270 ( V_54 -> V_305 , & V_295 , V_93 , V_229 | V_230 ) ;
if ( V_188 < 0 ) {
V_54 -> V_95 ( V_93 ) ;
return V_188 ;
}
F_88 ( & V_93 -> V_94 , & V_9 -> V_78 ) ;
F_116 ( V_9 ) ;
V_300 -> V_306 = V_188 ;
return 0 ;
}
static long F_315 ( struct V_9 * V_9 , long V_243 )
{
switch ( V_243 ) {
case V_307 :
case V_308 :
case V_309 :
#ifdef F_316
case V_310 :
#endif
case V_311 :
#ifdef F_317
case V_312 :
#endif
#ifdef F_77
case V_313 :
case V_314 :
#endif
case V_315 :
return 1 ;
#ifdef F_318
case V_316 :
return V_317 ;
#endif
default:
break;
}
return F_319 ( V_9 , V_243 ) ;
}
static long F_320 ( struct V_99 * V_100 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_9 * V_9 = V_100 -> V_101 ;
void V_125 * V_244 = ( void V_125 * ) V_243 ;
int V_28 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_248 ;
switch ( V_242 ) {
case V_318 :
V_28 = F_271 ( V_9 , V_243 ) ;
break;
case V_319 : {
struct V_108 V_320 ;
V_28 = - V_142 ;
if ( F_297 ( & V_320 , V_244 ,
sizeof V_320 ) )
goto V_119;
V_28 = F_143 ( V_9 , & V_320 ) ;
break;
}
case V_321 : {
struct V_137 log ;
V_28 = - V_142 ;
if ( F_297 ( & log , V_244 , sizeof log ) )
goto V_119;
V_28 = F_321 ( V_9 , & log ) ;
break;
}
#ifdef F_265
case V_322 : {
struct V_323 V_324 ;
V_28 = - V_142 ;
if ( F_297 ( & V_324 , V_244 , sizeof V_324 ) )
goto V_119;
V_28 = F_322 ( V_9 , & V_324 ) ;
break;
}
case V_325 : {
struct V_323 V_324 ;
V_28 = - V_142 ;
if ( F_297 ( & V_324 , V_244 , sizeof V_324 ) )
goto V_119;
V_28 = F_323 ( V_9 , & V_324 ) ;
break;
}
#endif
case V_326 : {
struct V_327 V_158 ;
V_28 = - V_142 ;
if ( F_297 ( & V_158 , V_244 , sizeof V_158 ) )
goto V_119;
V_28 = V_327 ( V_9 , & V_158 ) ;
break;
}
case V_328 : {
struct V_329 V_158 ;
V_28 = - V_142 ;
if ( F_297 ( & V_158 , V_244 , sizeof V_158 ) )
goto V_119;
V_28 = V_329 ( V_9 , & V_158 ) ;
break;
}
#ifdef F_316
case V_330 :
V_28 = 0 ;
F_142 ( & V_9 -> V_74 ) ;
if ( F_278 ( & V_9 -> V_236 ) != 0 )
V_28 = - V_331 ;
else
V_9 -> V_332 = V_243 ;
F_16 ( & V_9 -> V_74 ) ;
break;
#endif
#ifdef F_317
case V_333 : {
struct V_334 V_335 ;
V_28 = - V_142 ;
if ( F_297 ( & V_335 , V_244 , sizeof V_335 ) )
goto V_119;
V_28 = F_324 ( V_9 , & V_335 ) ;
break;
}
#endif
#ifdef F_325
case V_336 :
case V_337 : {
struct V_338 V_339 ;
V_28 = - V_142 ;
if ( F_297 ( & V_339 , V_244 , sizeof V_339 ) )
goto V_119;
V_28 = F_326 ( V_9 , & V_339 ,
V_242 == V_336 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_142 ;
if ( V_242 == V_336 ) {
if ( F_145 ( V_244 , & V_339 , sizeof V_339 ) )
goto V_119;
}
V_28 = 0 ;
break;
}
#endif
#ifdef F_318
case V_340 : {
struct V_341 V_342 ;
struct V_341 V_125 * V_343 ;
struct V_344 * V_345 ;
V_28 = - V_142 ;
if ( F_297 ( & V_342 , V_244 , sizeof( V_342 ) ) )
goto V_119;
V_28 = - V_113 ;
if ( V_342 . V_346 >= V_317 )
goto V_119;
if ( V_342 . V_106 )
goto V_119;
V_28 = - V_34 ;
V_345 = F_327 ( V_342 . V_346 * sizeof( * V_345 ) ) ;
if ( ! V_345 )
goto V_119;
V_28 = - V_142 ;
V_343 = V_244 ;
if ( F_297 ( V_345 , V_343 -> V_345 ,
V_342 . V_346 * sizeof( * V_345 ) ) )
goto V_347;
V_28 = F_328 ( V_9 , V_345 , V_342 . V_346 ,
V_342 . V_106 ) ;
V_347:
F_97 ( V_345 ) ;
break;
}
#endif
case V_348 : {
struct V_299 V_300 ;
V_28 = - V_142 ;
if ( F_297 ( & V_300 , V_244 , sizeof( V_300 ) ) )
goto V_119;
V_28 = F_314 ( V_9 , & V_300 ) ;
if ( V_28 )
goto V_119;
V_28 = - V_142 ;
if ( F_145 ( V_244 , & V_300 , sizeof( V_300 ) ) )
goto V_119;
V_28 = 0 ;
break;
}
case V_349 :
V_28 = F_315 ( V_9 , V_243 ) ;
break;
default:
V_28 = F_329 ( V_100 , V_242 , V_243 ) ;
}
V_119:
return V_28 ;
}
static long F_330 ( struct V_99 * V_100 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_9 * V_9 = V_100 -> V_101 ;
int V_28 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_248 ;
switch ( V_242 ) {
case V_321 : {
struct V_350 V_351 ;
struct V_137 log ;
V_28 = - V_142 ;
if ( F_297 ( & V_351 , ( void V_125 * ) V_243 ,
sizeof( V_351 ) ) )
goto V_119;
log . V_115 = V_351 . V_115 ;
log . V_352 = V_351 . V_352 ;
log . V_353 = V_351 . V_353 ;
log . V_86 = F_304 ( V_351 . V_86 ) ;
V_28 = F_321 ( V_9 , & log ) ;
break;
}
default:
V_28 = F_320 ( V_100 , V_242 , V_243 ) ;
}
V_119:
return V_28 ;
}
static int F_331 ( unsigned long type )
{
int V_28 ;
struct V_9 * V_9 ;
V_9 = F_72 ( type ) ;
if ( F_273 ( V_9 ) )
return F_274 ( V_9 ) ;
#ifdef F_265
V_28 = F_332 ( V_9 ) ;
if ( V_28 < 0 ) {
F_117 ( V_9 ) ;
return V_28 ;
}
#endif
V_28 = F_270 ( L_2 , & V_354 , V_9 , V_229 | V_230 ) ;
if ( V_28 < 0 )
F_117 ( V_9 ) ;
return V_28 ;
}
static long F_333 ( struct V_99 * V_100 ,
unsigned int V_242 , unsigned long V_243 )
{
long V_28 = - V_113 ;
switch ( V_242 ) {
case V_355 :
if ( V_243 )
goto V_119;
V_28 = V_356 ;
break;
case V_357 :
V_28 = F_331 ( V_243 ) ;
break;
case V_349 :
V_28 = F_315 ( NULL , V_243 ) ;
break;
case V_358 :
if ( V_243 )
goto V_119;
V_28 = V_82 ;
#ifdef F_264
V_28 += V_82 ;
#endif
#ifdef F_265
V_28 += V_82 ;
#endif
break;
case V_359 :
case V_360 :
case V_361 :
V_28 = - V_362 ;
break;
default:
return F_334 ( V_100 , V_242 , V_243 ) ;
}
V_119:
return V_28 ;
}
static void F_335 ( void * V_363 )
{
int V_4 = F_336 () ;
int V_28 ;
if ( F_337 ( V_4 , V_364 ) )
return;
F_24 ( V_4 , V_364 ) ;
V_28 = F_338 () ;
if ( V_28 ) {
F_339 ( V_4 , V_364 ) ;
F_84 ( & V_365 ) ;
F_340 ( V_366 L_3
L_4 , V_4 ) ;
}
}
static void F_341 ( void )
{
F_342 ( & V_367 ) ;
if ( V_368 )
F_335 ( NULL ) ;
F_343 ( & V_367 ) ;
}
static void F_344 ( void * V_363 )
{
int V_4 = F_336 () ;
if ( ! F_337 ( V_4 , V_364 ) )
return;
F_339 ( V_4 , V_364 ) ;
F_345 () ;
}
static void F_346 ( void )
{
F_342 ( & V_367 ) ;
if ( V_368 )
F_344 ( NULL ) ;
F_343 ( & V_367 ) ;
}
static void F_347 ( void )
{
F_62 ( ! V_368 ) ;
V_368 -- ;
if ( ! V_368 )
F_348 ( F_344 , NULL , 1 ) ;
}
static void F_90 ( void )
{
F_342 ( & V_367 ) ;
F_347 () ;
F_343 ( & V_367 ) ;
}
static int F_76 ( void )
{
int V_28 = 0 ;
F_342 ( & V_367 ) ;
V_368 ++ ;
if ( V_368 == 1 ) {
F_86 ( & V_365 , 0 ) ;
F_348 ( F_335 , NULL , 1 ) ;
if ( F_278 ( & V_365 ) ) {
F_347 () ;
V_28 = - V_331 ;
}
}
F_343 ( & V_367 ) ;
return V_28 ;
}
static int F_349 ( struct V_369 * V_370 , unsigned long V_371 ,
void * V_231 )
{
int V_4 = ( long ) V_231 ;
V_371 &= ~ V_372 ;
switch ( V_371 ) {
case V_373 :
F_340 ( V_366 L_5 ,
V_4 ) ;
F_346 () ;
break;
case V_374 :
F_340 ( V_366 L_6 ,
V_4 ) ;
F_341 () ;
break;
}
return V_375 ;
}
static int F_350 ( struct V_369 * V_370 , unsigned long V_371 ,
void * V_231 )
{
F_340 ( V_366 L_7 ) ;
V_376 = true ;
F_348 ( F_344 , NULL , 1 ) ;
return V_375 ;
}
static void F_110 ( struct V_71 * V_377 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_377 -> V_378 ; V_11 ++ ) {
struct V_379 * V_380 = V_377 -> V_381 [ V_11 ] . V_93 ;
F_351 ( V_380 ) ;
}
F_91 ( V_377 ) ;
}
static inline int F_352 ( const struct V_382 * V_383 ,
const struct V_382 * V_384 )
{
if ( V_383 -> V_83 < V_384 -> V_83 )
return - 1 ;
if ( V_383 -> V_83 + V_383 -> V_159 > V_384 -> V_83 + V_384 -> V_159 )
return 1 ;
return 0 ;
}
static int F_353 ( const void * V_385 , const void * V_386 )
{
return F_352 ( V_385 , V_386 ) ;
}
static int F_354 ( struct V_71 * V_377 , struct V_379 * V_93 ,
T_6 V_83 , int V_159 )
{
V_377 -> V_381 [ V_377 -> V_378 ++ ] = (struct V_382 ) {
. V_83 = V_83 ,
. V_159 = V_159 ,
. V_93 = V_93 ,
} ;
F_355 ( V_377 -> V_381 , V_377 -> V_378 , sizeof( struct V_382 ) ,
F_353 , NULL ) ;
return 0 ;
}
static int F_356 ( struct V_71 * V_377 ,
T_6 V_83 , int V_159 )
{
struct V_382 * V_381 , V_387 ;
int V_388 ;
V_387 = (struct V_382 ) {
. V_83 = V_83 ,
. V_159 = V_159 ,
} ;
V_381 = bsearch ( & V_387 , V_377 -> V_381 , V_377 -> V_378 ,
sizeof( struct V_382 ) , F_353 ) ;
if ( V_381 == NULL )
return - V_141 ;
V_388 = V_381 - V_377 -> V_381 ;
while ( V_388 > 0 && F_352 ( & V_387 , & V_377 -> V_381 [ V_388 - 1 ] ) == 0 )
V_388 -- ;
return V_388 ;
}
static int F_357 ( struct V_71 * V_377 ,
struct V_382 * V_381 , const void * V_371 )
{
int V_45 ;
V_45 = F_356 ( V_377 , V_381 -> V_83 , V_381 -> V_159 ) ;
if ( V_45 < 0 )
return - V_362 ;
while ( V_45 < V_377 -> V_378 &&
F_352 ( V_381 , & V_377 -> V_381 [ V_45 ] ) == 0 ) {
if ( ! F_358 ( V_377 -> V_381 [ V_45 ] . V_93 , V_381 -> V_83 ,
V_381 -> V_159 , V_371 ) )
return V_45 ;
V_45 ++ ;
}
return - V_362 ;
}
int F_359 ( struct V_9 * V_9 , enum V_389 V_390 , T_6 V_83 ,
int V_159 , const void * V_371 )
{
struct V_71 * V_377 ;
struct V_382 V_381 ;
int V_28 ;
V_381 = (struct V_382 ) {
. V_83 = V_83 ,
. V_159 = V_159 ,
} ;
V_377 = F_360 ( V_9 -> V_70 [ V_390 ] , & V_9 -> V_46 ) ;
V_28 = F_357 ( V_377 , & V_381 , V_371 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
int F_361 ( struct V_9 * V_9 , enum V_389 V_390 , T_6 V_83 ,
int V_159 , const void * V_371 , long V_391 )
{
struct V_71 * V_377 ;
struct V_382 V_381 ;
V_381 = (struct V_382 ) {
. V_83 = V_83 ,
. V_159 = V_159 ,
} ;
V_377 = F_360 ( V_9 -> V_70 [ V_390 ] , & V_9 -> V_46 ) ;
if ( ( V_391 >= 0 ) && ( V_391 < V_377 -> V_378 ) &&
( F_352 ( & V_381 , & V_377 -> V_381 [ V_391 ] ) == 0 ) )
if ( ! F_358 ( V_377 -> V_381 [ V_391 ] . V_93 , V_83 , V_159 ,
V_371 ) )
return V_391 ;
return F_357 ( V_377 , & V_381 , V_371 ) ;
}
static int F_362 ( struct V_71 * V_377 , struct V_382 * V_381 ,
void * V_371 )
{
int V_45 ;
V_45 = F_356 ( V_377 , V_381 -> V_83 , V_381 -> V_159 ) ;
if ( V_45 < 0 )
return - V_362 ;
while ( V_45 < V_377 -> V_378 &&
F_352 ( V_381 , & V_377 -> V_381 [ V_45 ] ) == 0 ) {
if ( ! F_363 ( V_377 -> V_381 [ V_45 ] . V_93 , V_381 -> V_83 ,
V_381 -> V_159 , V_371 ) )
return V_45 ;
V_45 ++ ;
}
return - V_362 ;
}
int F_364 ( struct V_9 * V_9 , enum V_389 V_390 , T_6 V_83 ,
int V_159 , void * V_371 )
{
struct V_71 * V_377 ;
struct V_382 V_381 ;
int V_28 ;
V_381 = (struct V_382 ) {
. V_83 = V_83 ,
. V_159 = V_159 ,
} ;
V_377 = F_360 ( V_9 -> V_70 [ V_390 ] , & V_9 -> V_46 ) ;
V_28 = F_362 ( V_377 , & V_381 , V_371 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
int F_365 ( struct V_9 * V_9 , enum V_389 V_390 , T_6 V_83 ,
int V_159 , struct V_379 * V_93 )
{
struct V_71 * V_392 , * V_377 ;
V_377 = V_9 -> V_70 [ V_390 ] ;
if ( V_377 -> V_378 - V_377 -> V_393 > V_394 - 1 )
return - V_298 ;
V_392 = F_82 ( sizeof( * V_377 ) + ( ( V_377 -> V_378 + 1 ) *
sizeof( struct V_382 ) ) , V_32 ) ;
if ( ! V_392 )
return - V_34 ;
memcpy ( V_392 , V_377 , sizeof( * V_377 ) + ( V_377 -> V_378 *
sizeof( struct V_382 ) ) ) ;
F_354 ( V_392 , V_93 , V_83 , V_159 ) ;
F_129 ( V_9 -> V_70 [ V_390 ] , V_392 ) ;
F_130 ( & V_9 -> V_46 ) ;
F_91 ( V_377 ) ;
return 0 ;
}
int F_366 ( struct V_9 * V_9 , enum V_389 V_390 ,
struct V_379 * V_93 )
{
int V_11 , V_28 ;
struct V_71 * V_392 , * V_377 ;
V_377 = V_9 -> V_70 [ V_390 ] ;
V_28 = - V_141 ;
for ( V_11 = 0 ; V_11 < V_377 -> V_378 ; V_11 ++ )
if ( V_377 -> V_381 [ V_11 ] . V_93 == V_93 ) {
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
F_129 ( V_9 -> V_70 [ V_390 ] , V_392 ) ;
F_130 ( & V_9 -> V_46 ) ;
F_91 ( V_377 ) ;
return V_28 ;
}
static int F_367 ( void * V_395 , T_11 * V_371 )
{
unsigned V_145 = ( long ) V_395 ;
struct V_9 * V_9 ;
* V_371 = 0 ;
F_51 ( & V_79 ) ;
F_368 ( V_9 , & V_80 , V_80 )
* V_371 += * ( T_4 * ) ( ( void * ) V_9 + V_145 ) ;
F_53 ( & V_79 ) ;
return 0 ;
}
static int F_369 ( void * V_395 , T_11 * V_371 )
{
unsigned V_145 = ( long ) V_395 ;
struct V_9 * V_9 ;
struct V_2 * V_3 ;
int V_11 ;
* V_371 = 0 ;
F_51 ( & V_79 ) ;
F_368 (kvm, &vm_list, vm_list)
F_20 ( V_11 , V_3 , V_9 )
* V_371 += * ( T_4 * ) ( ( void * ) V_3 + V_145 ) ;
F_53 ( & V_79 ) ;
return 0 ;
}
static int F_370 ( void )
{
int V_28 = - V_132 ;
struct V_396 * V_280 ;
V_397 = F_371 ( L_8 , NULL ) ;
if ( V_397 == NULL )
goto V_119;
for ( V_280 = V_398 ; V_280 -> V_305 ; ++ V_280 ) {
V_280 -> V_399 = F_372 ( V_280 -> V_305 , 0444 , V_397 ,
( void * ) ( long ) V_280 -> V_145 ,
V_400 [ V_280 -> V_401 ] ) ;
if ( V_280 -> V_399 == NULL )
goto V_402;
}
return 0 ;
V_402:
F_373 ( V_397 ) ;
V_119:
return V_28 ;
}
static void F_374 ( void )
{
struct V_396 * V_280 ;
for ( V_280 = V_398 ; V_280 -> V_305 ; ++ V_280 )
F_375 ( V_280 -> V_399 ) ;
F_375 ( V_397 ) ;
}
static int F_376 ( void )
{
if ( V_368 )
F_344 ( NULL ) ;
return 0 ;
}
static void F_377 ( void )
{
if ( V_368 ) {
F_124 ( F_378 ( & V_367 ) ) ;
F_335 ( NULL ) ;
}
}
static inline
struct V_2 * F_379 ( struct V_7 * V_403 )
{
return F_48 ( V_403 , struct V_2 , V_7 ) ;
}
static void F_380 ( struct V_7 * V_403 , int V_4 )
{
struct V_2 * V_3 = F_379 ( V_403 ) ;
if ( V_3 -> V_37 )
V_3 -> V_37 = false ;
F_381 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_382 ( struct V_7 * V_403 ,
struct V_160 * V_404 )
{
struct V_2 * V_3 = F_379 ( V_403 ) ;
if ( V_56 -> V_405 == V_406 )
V_3 -> V_37 = true ;
F_13 ( V_3 ) ;
}
int F_383 ( void * V_407 , unsigned V_408 , unsigned V_409 ,
struct V_410 * V_410 )
{
int V_28 ;
int V_4 ;
V_28 = F_384 ( V_407 ) ;
if ( V_28 )
goto V_411;
V_28 = F_385 () ;
if ( V_28 )
goto V_412;
if ( ! F_19 ( & V_364 , V_32 ) ) {
V_28 = - V_34 ;
goto V_413;
}
V_28 = F_386 () ;
if ( V_28 < 0 )
goto V_414;
F_387 (cpu) {
F_388 ( V_4 ,
V_415 ,
& V_28 , 1 ) ;
if ( V_28 < 0 )
goto V_416;
}
V_28 = F_389 ( & V_417 ) ;
if ( V_28 )
goto V_418;
F_390 ( & V_419 ) ;
if ( ! V_409 )
V_409 = F_391 ( struct V_2 ) ;
V_420 = F_392 ( L_9 , V_408 , V_409 ,
0 , NULL ) ;
if ( ! V_420 ) {
V_28 = - V_34 ;
goto V_421;
}
V_28 = F_393 () ;
if ( V_28 )
goto V_133;
V_422 . V_423 = V_410 ;
V_354 . V_423 = V_410 ;
V_228 . V_423 = V_410 ;
V_28 = F_394 ( & V_424 ) ;
if ( V_28 ) {
F_340 ( V_425 L_10 ) ;
goto V_426;
}
F_395 ( & V_427 ) ;
V_233 . V_428 = F_380 ;
V_233 . V_429 = F_382 ;
V_28 = F_370 () ;
if ( V_28 ) {
F_340 ( V_425 L_11 ) ;
goto V_430;
}
V_28 = F_396 () ;
F_124 ( V_28 ) ;
return 0 ;
V_430:
F_397 ( & V_427 ) ;
F_398 ( & V_424 ) ;
V_426:
F_399 () ;
V_133:
F_400 ( V_420 ) ;
V_421:
F_401 ( & V_419 ) ;
F_402 ( & V_417 ) ;
V_418:
V_416:
F_403 () ;
V_414:
F_28 ( V_364 ) ;
V_413:
F_404 () ;
V_412:
F_405 () ;
V_411:
return V_28 ;
}
void F_406 ( void )
{
F_374 () ;
F_398 ( & V_424 ) ;
F_400 ( V_420 ) ;
F_399 () ;
F_397 ( & V_427 ) ;
F_401 ( & V_419 ) ;
F_402 ( & V_417 ) ;
F_348 ( F_344 , NULL , 1 ) ;
F_403 () ;
F_405 () ;
F_404 () ;
F_28 ( V_364 ) ;
F_407 () ;
}
