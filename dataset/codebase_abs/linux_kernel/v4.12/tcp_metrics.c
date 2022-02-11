static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( & V_3 -> V_4 ) ;
}
static bool F_3 ( struct V_2 * V_3 ,
enum V_5 V_6 )
{
return V_3 -> V_7 & ( 1 << V_6 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
enum V_5 V_6 )
{
return V_3 -> V_8 [ V_6 ] ;
}
static void F_5 ( struct V_2 * V_3 ,
enum V_5 V_6 ,
T_1 V_9 )
{
V_3 -> V_8 [ V_6 ] = V_9 ;
}
static bool F_6 ( const struct V_10 * V_11 ,
const struct V_10 * V_12 )
{
return F_7 ( V_11 , V_12 ) == 0 ;
}
static void F_8 ( struct V_2 * V_3 ,
const struct V_13 * V_14 ,
bool V_15 )
{
T_1 V_16 ;
T_1 V_9 ;
V_3 -> V_17 = V_18 ;
V_9 = 0 ;
if ( F_9 ( V_14 , V_19 ) )
V_9 |= 1 << V_20 ;
if ( F_9 ( V_14 , V_21 ) )
V_9 |= 1 << V_22 ;
if ( F_9 ( V_14 , V_23 ) )
V_9 |= 1 << V_24 ;
if ( F_9 ( V_14 , V_25 ) )
V_9 |= 1 << V_26 ;
if ( F_9 ( V_14 , V_27 ) )
V_9 |= 1 << V_28 ;
V_3 -> V_7 = V_9 ;
V_16 = F_10 ( V_14 , V_19 ) ;
V_3 -> V_8 [ V_20 ] = V_16 * V_29 ;
V_16 = F_10 ( V_14 , V_21 ) ;
V_3 -> V_8 [ V_22 ] = V_16 * V_29 ;
V_3 -> V_8 [ V_24 ] = F_10 ( V_14 , V_23 ) ;
V_3 -> V_8 [ V_26 ] = F_10 ( V_14 , V_25 ) ;
V_3 -> V_8 [ V_28 ] = F_10 ( V_14 , V_27 ) ;
if ( V_15 ) {
V_3 -> V_30 . V_31 = 0 ;
V_3 -> V_30 . V_32 = 0 ;
V_3 -> V_30 . V_33 = 0 ;
V_3 -> V_30 . V_34 . exp = false ;
V_3 -> V_30 . V_34 . V_35 = 0 ;
}
}
static void F_11 ( struct V_2 * V_3 , struct V_13 * V_14 )
{
if ( V_3 && F_12 ( F_13 ( V_18 , V_3 -> V_17 + V_36 ) ) )
F_8 ( V_3 , V_14 , false ) ;
}
static struct V_2 * F_14 ( struct V_13 * V_14 ,
struct V_10 * V_37 ,
struct V_10 * V_38 ,
unsigned int V_39 )
{
struct V_2 * V_3 ;
struct V_1 * V_1 ;
bool V_40 = false ;
F_15 ( & V_41 ) ;
V_1 = F_16 ( V_14 -> V_42 ) ;
V_3 = F_17 ( V_37 , V_38 , V_1 , V_39 ) ;
if ( V_3 == V_43 ) {
V_40 = true ;
V_3 = NULL ;
}
if ( V_3 ) {
F_11 ( V_3 , V_14 ) ;
goto V_44;
}
if ( F_12 ( V_40 ) ) {
struct V_2 * V_45 ;
V_45 = F_18 ( V_46 [ V_39 ] . V_47 ) ;
for ( V_3 = F_18 ( V_45 -> V_48 ) ; V_3 ;
V_3 = F_18 ( V_3 -> V_48 ) ) {
if ( F_19 ( V_3 -> V_17 , V_45 -> V_17 ) )
V_45 = V_3 ;
}
V_3 = V_45 ;
} else {
V_3 = F_20 ( sizeof( * V_3 ) , V_49 ) ;
if ( ! V_3 )
goto V_44;
}
F_21 ( & V_3 -> V_4 , V_1 ) ;
V_3 -> V_50 = * V_37 ;
V_3 -> V_51 = * V_38 ;
F_8 ( V_3 , V_14 , true ) ;
if ( F_22 ( ! V_40 ) ) {
V_3 -> V_48 = V_46 [ V_39 ] . V_47 ;
F_23 ( V_46 [ V_39 ] . V_47 , V_3 ) ;
}
V_44:
F_24 ( & V_41 ) ;
return V_3 ;
}
static struct V_2 * F_25 ( struct V_2 * V_3 , int V_52 )
{
if ( V_3 )
return V_3 ;
if ( V_52 > V_53 )
return V_43 ;
return NULL ;
}
static struct V_2 * F_17 ( const struct V_10 * V_37 ,
const struct V_10 * V_38 ,
struct V_1 * V_1 , unsigned int V_39 )
{
struct V_2 * V_3 ;
int V_52 = 0 ;
for ( V_3 = F_26 ( V_46 [ V_39 ] . V_47 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_48 ) ) {
if ( F_6 ( & V_3 -> V_50 , V_37 ) &&
F_6 ( & V_3 -> V_51 , V_38 ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) )
break;
V_52 ++ ;
}
return F_25 ( V_3 , V_52 ) ;
}
static struct V_2 * F_28 ( struct V_54 * V_55 ,
struct V_13 * V_14 )
{
struct V_2 * V_3 ;
struct V_10 V_37 , V_38 ;
unsigned int V_39 ;
struct V_1 * V_1 ;
V_37 . V_56 = V_55 -> V_57 -> V_56 ;
V_38 . V_56 = V_55 -> V_57 -> V_56 ;
switch ( V_38 . V_56 ) {
case V_58 :
F_29 ( & V_37 , F_30 ( V_55 ) -> V_59 ) ;
F_29 ( & V_38 , F_30 ( V_55 ) -> V_60 ) ;
V_39 = F_31 ( F_30 ( V_55 ) -> V_60 ) ;
break;
#if F_32 ( V_61 )
case V_62 :
F_33 ( & V_37 , & F_30 ( V_55 ) -> V_63 ) ;
F_33 ( & V_38 , & F_30 ( V_55 ) -> V_64 ) ;
V_39 = F_34 ( & F_30 ( V_55 ) -> V_64 ) ;
break;
#endif
default:
return NULL ;
}
V_1 = F_16 ( V_14 -> V_42 ) ;
V_39 ^= F_35 ( V_1 ) ;
V_39 = F_36 ( V_39 , V_65 ) ;
for ( V_3 = F_26 ( V_46 [ V_39 ] . V_47 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_48 ) ) {
if ( F_6 ( & V_3 -> V_50 , & V_37 ) &&
F_6 ( & V_3 -> V_51 , & V_38 ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) )
break;
}
F_11 ( V_3 , V_14 ) ;
return V_3 ;
}
static struct V_2 * F_37 ( struct V_66 * V_67 ,
struct V_13 * V_14 ,
bool V_68 )
{
struct V_2 * V_3 ;
struct V_10 V_37 , V_38 ;
unsigned int V_39 ;
struct V_1 * V_1 ;
if ( V_67 -> V_69 == V_58 ) {
F_29 ( & V_37 , F_38 ( V_67 ) -> V_70 ) ;
F_29 ( & V_38 , F_38 ( V_67 ) -> V_71 ) ;
V_39 = F_31 ( F_38 ( V_67 ) -> V_71 ) ;
}
#if F_32 ( V_61 )
else if ( V_67 -> V_69 == V_62 ) {
if ( F_39 ( & V_67 -> V_72 ) ) {
F_29 ( & V_37 , F_38 ( V_67 ) -> V_70 ) ;
F_29 ( & V_38 , F_38 ( V_67 ) -> V_71 ) ;
V_39 = F_31 ( F_38 ( V_67 ) -> V_71 ) ;
} else {
F_33 ( & V_37 , & V_67 -> V_73 ) ;
F_33 ( & V_38 , & V_67 -> V_72 ) ;
V_39 = F_34 ( & V_67 -> V_72 ) ;
}
}
#endif
else
return NULL ;
V_1 = F_16 ( V_14 -> V_42 ) ;
V_39 ^= F_35 ( V_1 ) ;
V_39 = F_36 ( V_39 , V_65 ) ;
V_3 = F_17 ( & V_37 , & V_38 , V_1 , V_39 ) ;
if ( V_3 == V_43 )
V_3 = NULL ;
if ( ! V_3 && V_68 )
V_3 = F_14 ( V_14 , & V_37 , & V_38 , V_39 ) ;
else
F_11 ( V_3 , V_14 ) ;
return V_3 ;
}
void F_40 ( struct V_66 * V_67 )
{
const struct V_74 * V_75 = F_41 ( V_67 ) ;
struct V_13 * V_14 = F_42 ( V_67 ) ;
struct V_76 * V_77 = F_43 ( V_67 ) ;
struct V_1 * V_1 = F_44 ( V_67 ) ;
struct V_2 * V_3 ;
unsigned long V_78 ;
T_1 V_9 ;
int V_79 ;
F_45 ( V_67 ) ;
if ( V_80 || ! V_14 )
return;
F_46 () ;
if ( V_75 -> V_81 || ! V_77 -> V_82 ) {
V_3 = F_37 ( V_67 , V_14 , false ) ;
if ( V_3 && ! F_3 ( V_3 , V_20 ) )
F_5 ( V_3 , V_20 , 0 ) ;
goto V_44;
} else
V_3 = F_37 ( V_67 , V_14 , true ) ;
if ( ! V_3 )
goto V_44;
V_78 = F_4 ( V_3 , V_20 ) ;
V_79 = V_78 - V_77 -> V_82 ;
if ( ! F_3 ( V_3 , V_20 ) ) {
if ( V_79 <= 0 )
V_78 = V_77 -> V_82 ;
else
V_78 -= ( V_79 >> 3 ) ;
F_5 ( V_3 , V_20 , V_78 ) ;
}
if ( ! F_3 ( V_3 , V_22 ) ) {
unsigned long V_83 ;
if ( V_79 < 0 )
V_79 = - V_79 ;
V_79 >>= 1 ;
if ( V_79 < V_77 -> V_84 )
V_79 = V_77 -> V_84 ;
V_83 = F_4 ( V_3 , V_22 ) ;
if ( V_79 >= V_83 )
V_83 = V_79 ;
else
V_83 -= ( V_83 - V_79 ) >> 2 ;
F_5 ( V_3 , V_22 , V_83 ) ;
}
if ( F_47 ( V_77 ) ) {
if ( ! F_3 ( V_3 , V_24 ) ) {
V_9 = F_4 ( V_3 , V_24 ) ;
if ( V_9 && ( V_77 -> V_85 >> 1 ) > V_9 )
F_5 ( V_3 , V_24 ,
V_77 -> V_85 >> 1 ) ;
}
if ( ! F_3 ( V_3 , V_26 ) ) {
V_9 = F_4 ( V_3 , V_26 ) ;
if ( V_77 -> V_85 > V_9 )
F_5 ( V_3 , V_26 ,
V_77 -> V_85 ) ;
}
} else if ( ! F_48 ( V_77 ) &&
V_75 -> V_86 == V_87 ) {
if ( ! F_3 ( V_3 , V_24 ) )
F_5 ( V_3 , V_24 ,
F_49 ( V_77 -> V_85 >> 1 , V_77 -> V_88 ) ) ;
if ( ! F_3 ( V_3 , V_26 ) ) {
V_9 = F_4 ( V_3 , V_26 ) ;
F_5 ( V_3 , V_26 , ( V_9 + V_77 -> V_85 ) >> 1 ) ;
}
} else {
if ( ! F_3 ( V_3 , V_26 ) ) {
V_9 = F_4 ( V_3 , V_26 ) ;
F_5 ( V_3 , V_26 ,
( V_9 + V_77 -> V_88 ) >> 1 ) ;
}
if ( ! F_3 ( V_3 , V_24 ) ) {
V_9 = F_4 ( V_3 , V_24 ) ;
if ( V_9 && V_77 -> V_88 > V_9 )
F_5 ( V_3 , V_24 ,
V_77 -> V_88 ) ;
}
if ( ! F_3 ( V_3 , V_28 ) ) {
V_9 = F_4 ( V_3 , V_28 ) ;
if ( V_9 < V_77 -> V_89 &&
V_77 -> V_89 != V_1 -> V_90 . V_91 )
F_5 ( V_3 , V_28 ,
V_77 -> V_89 ) ;
}
}
V_3 -> V_17 = V_18 ;
V_44:
F_50 () ;
}
void F_51 ( struct V_66 * V_67 )
{
struct V_13 * V_14 = F_42 ( V_67 ) ;
struct V_76 * V_77 = F_43 ( V_67 ) ;
struct V_2 * V_3 ;
T_1 V_9 , V_92 = 0 ;
F_45 ( V_67 ) ;
if ( ! V_14 )
goto V_93;
F_46 () ;
V_3 = F_37 ( V_67 , V_14 , true ) ;
if ( ! V_3 ) {
F_50 () ;
goto V_93;
}
if ( F_3 ( V_3 , V_26 ) )
V_77 -> V_94 = F_4 ( V_3 , V_26 ) ;
V_9 = F_4 ( V_3 , V_24 ) ;
if ( V_9 ) {
V_77 -> V_88 = V_9 ;
if ( V_77 -> V_88 > V_77 -> V_94 )
V_77 -> V_88 = V_77 -> V_94 ;
} else {
V_77 -> V_88 = V_95 ;
}
V_9 = F_4 ( V_3 , V_28 ) ;
if ( V_9 && V_77 -> V_89 != V_9 ) {
F_52 ( V_77 ) ;
V_77 -> V_89 = V_9 ;
}
V_92 = F_4 ( V_3 , V_20 ) ;
F_50 () ;
V_93:
if ( V_92 > V_77 -> V_82 ) {
V_92 /= 8 * V_96 / V_97 ;
F_41 ( V_67 ) -> V_98 = V_92 + F_49 ( 2 * V_92 , F_53 ( V_67 ) ) ;
} else if ( V_77 -> V_82 == 0 ) {
V_77 -> V_99 = F_54 ( V_100 ) ;
V_77 -> V_84 = V_77 -> V_101 = V_77 -> V_99 ;
F_41 ( V_67 ) -> V_98 = V_100 ;
}
if ( V_77 -> V_102 > 1 )
V_77 -> V_85 = 1 ;
else
V_77 -> V_85 = F_55 ( V_77 , V_14 ) ;
V_77 -> V_103 = V_104 ;
}
bool F_56 ( struct V_54 * V_55 , struct V_13 * V_14 )
{
struct V_2 * V_3 ;
bool V_105 ;
if ( ! V_14 )
return false ;
F_46 () ;
V_3 = F_28 ( V_55 , V_14 ) ;
if ( V_3 && F_4 ( V_3 , V_20 ) )
V_105 = true ;
else
V_105 = false ;
F_50 () ;
return V_105 ;
}
void F_57 ( struct V_66 * V_67 , T_2 * V_31 ,
struct V_106 * V_34 ,
int * V_32 , unsigned long * V_107 )
{
struct V_2 * V_3 ;
F_46 () ;
V_3 = F_37 ( V_67 , F_42 ( V_67 ) , false ) ;
if ( V_3 ) {
struct V_108 * V_109 = & V_3 -> V_30 ;
unsigned int V_110 ;
do {
V_110 = F_58 ( & V_111 ) ;
if ( V_109 -> V_31 )
* V_31 = V_109 -> V_31 ;
* V_34 = V_109 -> V_34 ;
if ( V_34 -> V_35 <= 0 && V_109 -> V_33 == 1 )
V_34 -> exp = true ;
* V_32 = V_109 -> V_32 ;
* V_107 = * V_32 ? V_109 -> V_107 : 0 ;
} while ( F_59 ( & V_111 , V_110 ) );
}
F_50 () ;
}
void F_60 ( struct V_66 * V_67 , T_2 V_31 ,
struct V_106 * V_34 , bool V_112 ,
T_2 V_33 )
{
struct V_13 * V_14 = F_42 ( V_67 ) ;
struct V_2 * V_3 ;
if ( ! V_14 )
return;
F_46 () ;
V_3 = F_37 ( V_67 , V_14 , true ) ;
if ( V_3 ) {
struct V_108 * V_109 = & V_3 -> V_30 ;
F_61 ( & V_111 ) ;
if ( V_31 )
V_109 -> V_31 = V_31 ;
if ( V_34 && V_34 -> V_35 > 0 )
V_109 -> V_34 = * V_34 ;
else if ( V_33 > V_109 -> V_33 &&
V_109 -> V_34 . V_35 <= 0 && ! V_109 -> V_34 . exp )
V_109 -> V_33 = V_33 ;
if ( V_112 ) {
++ V_109 -> V_32 ;
V_109 -> V_107 = V_18 ;
} else
V_109 -> V_32 = 0 ;
F_62 ( & V_111 ) ;
}
F_50 () ;
}
static int F_63 ( struct V_113 * V_114 ,
struct V_2 * V_3 )
{
struct V_115 * V_116 ;
int V_117 ;
switch ( V_3 -> V_51 . V_56 ) {
case V_58 :
if ( F_64 ( V_114 , V_118 ,
F_65 ( & V_3 -> V_51 ) ) < 0 )
goto V_119;
if ( F_64 ( V_114 , V_120 ,
F_65 ( & V_3 -> V_50 ) ) < 0 )
goto V_119;
break;
case V_62 :
if ( F_66 ( V_114 , V_121 ,
F_67 ( & V_3 -> V_51 ) ) < 0 )
goto V_119;
if ( F_66 ( V_114 , V_122 ,
F_67 ( & V_3 -> V_50 ) ) < 0 )
goto V_119;
break;
default:
return - V_123 ;
}
if ( F_68 ( V_114 , V_124 ,
V_18 - V_3 -> V_17 ,
V_125 ) < 0 )
goto V_119;
{
int V_126 = 0 ;
V_116 = F_69 ( V_114 , V_127 ) ;
if ( ! V_116 )
goto V_119;
for ( V_117 = 0 ; V_117 < V_128 + 1 ; V_117 ++ ) {
T_1 V_9 = V_3 -> V_8 [ V_117 ] ;
if ( ! V_9 )
continue;
if ( V_117 == V_20 ) {
if ( F_70 ( V_114 , V_129 + 1 ,
V_9 ) < 0 )
goto V_119;
V_126 ++ ;
V_9 = F_49 ( V_9 / 1000 , 1U ) ;
}
if ( V_117 == V_22 ) {
if ( F_70 ( V_114 , V_130 + 1 ,
V_9 ) < 0 )
goto V_119;
V_126 ++ ;
V_9 = F_49 ( V_9 / 1000 , 1U ) ;
}
if ( F_70 ( V_114 , V_117 + 1 , V_9 ) < 0 )
goto V_119;
V_126 ++ ;
}
if ( V_126 )
F_71 ( V_114 , V_116 ) ;
else
F_72 ( V_114 , V_116 ) ;
}
{
struct V_108 V_131 [ 1 ] , * V_109 ;
unsigned int V_110 ;
do {
V_110 = F_58 ( & V_111 ) ;
V_131 [ 0 ] = V_3 -> V_30 ;
} while ( F_59 ( & V_111 , V_110 ) );
V_109 = V_131 ;
if ( V_109 -> V_31 &&
F_73 ( V_114 , V_132 ,
V_109 -> V_31 ) < 0 )
goto V_119;
if ( V_109 -> V_32 &&
( F_73 ( V_114 , V_133 ,
V_109 -> V_32 ) < 0 ||
F_68 ( V_114 , V_134 ,
V_18 - V_109 -> V_107 ,
V_125 ) < 0 ) )
goto V_119;
if ( V_109 -> V_34 . V_35 > 0 &&
F_74 ( V_114 , V_135 ,
V_109 -> V_34 . V_35 , V_109 -> V_34 . V_9 ) < 0 )
goto V_119;
}
return 0 ;
V_119:
return - V_136 ;
}
static int F_75 ( struct V_113 * V_137 ,
struct V_138 * V_139 ,
struct V_2 * V_3 )
{
void * V_140 ;
V_140 = F_76 ( V_137 , F_77 ( V_139 -> V_137 ) . V_141 , V_139 -> V_142 -> V_143 ,
& V_144 , V_145 ,
V_146 ) ;
if ( ! V_140 )
return - V_136 ;
if ( F_63 ( V_137 , V_3 ) < 0 )
goto V_119;
F_78 ( V_137 , V_140 ) ;
return 0 ;
V_119:
F_79 ( V_137 , V_140 ) ;
return - V_136 ;
}
static int F_80 ( struct V_113 * V_137 ,
struct V_138 * V_139 )
{
struct V_1 * V_1 = F_44 ( V_137 -> V_67 ) ;
unsigned int V_147 = 1U << V_65 ;
unsigned int V_148 , V_149 = V_139 -> args [ 0 ] ;
int V_150 = V_139 -> args [ 1 ] , V_151 = V_150 ;
for ( V_148 = V_149 ; V_148 < V_147 ; V_148 ++ , V_150 = 0 ) {
struct V_2 * V_3 ;
struct V_152 * V_153 = V_46 + V_148 ;
F_46 () ;
for ( V_151 = 0 , V_3 = F_26 ( V_153 -> V_47 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_48 ) , V_151 ++ ) {
if ( ! F_27 ( F_1 ( V_3 ) , V_1 ) )
continue;
if ( V_151 < V_150 )
continue;
if ( F_75 ( V_137 , V_139 , V_3 ) < 0 ) {
F_50 () ;
goto V_154;
}
}
F_50 () ;
}
V_154:
V_139 -> args [ 0 ] = V_148 ;
V_139 -> args [ 1 ] = V_151 ;
return V_137 -> V_35 ;
}
static int F_81 ( struct V_155 * V_156 , struct V_10 * V_157 ,
unsigned int * V_39 , int V_158 , int V_159 , int V_160 )
{
struct V_115 * V_11 ;
V_11 = V_156 -> V_161 [ V_159 ] ;
if ( V_11 ) {
F_29 ( V_157 , F_82 ( V_11 ) ) ;
if ( V_39 )
* V_39 = F_31 ( F_65 ( V_157 ) ) ;
return 0 ;
}
V_11 = V_156 -> V_161 [ V_160 ] ;
if ( V_11 ) {
struct V_162 V_163 ;
if ( F_83 ( V_11 ) != sizeof( struct V_162 ) )
return - V_164 ;
V_163 = F_84 ( V_11 ) ;
F_33 ( V_157 , & V_163 ) ;
if ( V_39 )
* V_39 = F_34 ( F_67 ( V_157 ) ) ;
return 0 ;
}
return V_158 ? 1 : - V_123 ;
}
static int F_85 ( struct V_155 * V_156 , struct V_10 * V_157 ,
unsigned int * V_39 , int V_158 )
{
return F_81 ( V_156 , V_157 , V_39 , V_158 ,
V_118 ,
V_121 ) ;
}
static int F_86 ( struct V_155 * V_156 , struct V_10 * V_157 )
{
return F_81 ( V_156 , V_157 , NULL , 0 ,
V_120 ,
V_122 ) ;
}
static int F_87 ( struct V_113 * V_137 , struct V_155 * V_156 )
{
struct V_2 * V_3 ;
struct V_10 V_37 , V_38 ;
unsigned int V_39 ;
struct V_113 * V_114 ;
struct V_1 * V_1 = F_88 ( V_156 ) ;
void * V_165 ;
int V_105 ;
bool V_166 = true ;
V_105 = F_85 ( V_156 , & V_38 , & V_39 , 0 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_86 ( V_156 , & V_37 ) ;
if ( V_105 < 0 )
V_166 = false ;
V_114 = F_89 ( V_167 , V_168 ) ;
if ( ! V_114 )
return - V_169 ;
V_165 = F_90 ( V_114 , V_156 , & V_144 , 0 ,
V_156 -> V_170 -> V_171 ) ;
if ( ! V_165 )
goto V_119;
V_39 ^= F_35 ( V_1 ) ;
V_39 = F_36 ( V_39 , V_65 ) ;
V_105 = - V_172 ;
F_46 () ;
for ( V_3 = F_26 ( V_46 [ V_39 ] . V_47 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_48 ) ) {
if ( F_6 ( & V_3 -> V_51 , & V_38 ) &&
( ! V_166 || F_6 ( & V_3 -> V_50 , & V_37 ) ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) ) {
V_105 = F_63 ( V_114 , V_3 ) ;
break;
}
}
F_50 () ;
if ( V_105 < 0 )
goto V_173;
F_78 ( V_114 , V_165 ) ;
return F_91 ( V_114 , V_156 ) ;
V_119:
V_105 = - V_136 ;
V_173:
F_92 ( V_114 ) ;
return V_105 ;
}
static void F_93 ( struct V_1 * V_1 )
{
unsigned int V_147 = 1U << V_65 ;
struct V_152 * V_153 = V_46 ;
struct V_2 * V_3 ;
unsigned int V_148 ;
for ( V_148 = 0 ; V_148 < V_147 ; V_148 ++ , V_153 ++ ) {
struct V_2 T_3 * * V_174 ;
F_15 ( & V_41 ) ;
V_174 = & V_153 -> V_47 ;
for ( V_3 = F_18 ( * V_174 ) ; V_3 ; V_3 = F_18 ( * V_174 ) ) {
if ( F_27 ( F_1 ( V_3 ) , V_1 ) ) {
* V_174 = V_3 -> V_48 ;
F_94 ( V_3 , V_175 ) ;
} else {
V_174 = & V_3 -> V_48 ;
}
}
F_24 ( & V_41 ) ;
}
}
static int F_95 ( struct V_113 * V_137 , struct V_155 * V_156 )
{
struct V_152 * V_153 ;
struct V_2 * V_3 ;
struct V_2 T_3 * * V_174 ;
struct V_10 V_37 , V_38 ;
unsigned int V_39 ;
struct V_1 * V_1 = F_88 ( V_156 ) ;
int V_105 ;
bool V_166 = true , V_176 = false ;
V_105 = F_85 ( V_156 , & V_38 , & V_39 , 1 ) ;
if ( V_105 < 0 )
return V_105 ;
if ( V_105 > 0 ) {
F_93 ( V_1 ) ;
return 0 ;
}
V_105 = F_86 ( V_156 , & V_37 ) ;
if ( V_105 < 0 )
V_166 = false ;
V_39 ^= F_35 ( V_1 ) ;
V_39 = F_36 ( V_39 , V_65 ) ;
V_153 = V_46 + V_39 ;
V_174 = & V_153 -> V_47 ;
F_15 ( & V_41 ) ;
for ( V_3 = F_18 ( * V_174 ) ; V_3 ; V_3 = F_18 ( * V_174 ) ) {
if ( F_6 ( & V_3 -> V_51 , & V_38 ) &&
( ! V_166 || F_6 ( & V_3 -> V_50 , & V_37 ) ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) ) {
* V_174 = V_3 -> V_48 ;
F_94 ( V_3 , V_175 ) ;
V_176 = true ;
} else {
V_174 = & V_3 -> V_48 ;
}
}
F_24 ( & V_41 ) ;
if ( ! V_176 )
return - V_172 ;
return 0 ;
}
static int T_4 F_96 ( char * V_177 )
{
T_5 V_105 ;
if ( ! V_177 )
return 0 ;
V_105 = F_97 ( V_177 , 0 , & V_178 ) ;
if ( V_105 )
return 0 ;
return 1 ;
}
static int T_6 F_98 ( struct V_1 * V_1 )
{
T_7 V_179 ;
unsigned int V_180 ;
if ( ! F_27 ( V_1 , & V_181 ) )
return 0 ;
V_180 = V_178 ;
if ( ! V_180 ) {
if ( V_182 >= 128 * 1024 )
V_180 = 16 * 1024 ;
else
V_180 = 8 * 1024 ;
}
V_65 = F_99 ( V_180 ) ;
V_179 = sizeof( struct V_152 ) << V_65 ;
V_46 = F_100 ( V_179 , V_168 ) ;
if ( ! V_46 )
return - V_169 ;
return 0 ;
}
static void T_8 F_101 ( struct V_1 * V_1 )
{
F_93 ( V_1 ) ;
}
void T_4 F_102 ( void )
{
int V_105 ;
V_105 = F_103 ( & V_183 ) ;
if ( V_105 < 0 )
F_104 ( L_1 ) ;
V_105 = F_105 ( & V_144 ) ;
if ( V_105 < 0 )
F_104 ( L_2 ) ;
}
