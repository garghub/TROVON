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
V_3 -> V_30 = 0 ;
V_3 -> V_31 = 0 ;
if ( V_15 ) {
V_3 -> V_32 . V_33 = 0 ;
V_3 -> V_32 . V_34 = 0 ;
V_3 -> V_32 . V_35 = 0 ;
V_3 -> V_32 . V_36 . exp = false ;
V_3 -> V_32 . V_36 . V_37 = 0 ;
}
}
static void F_11 ( struct V_2 * V_3 , struct V_13 * V_14 )
{
if ( V_3 && F_12 ( F_13 ( V_18 , V_3 -> V_17 + V_38 ) ) )
F_8 ( V_3 , V_14 , false ) ;
}
static struct V_2 * F_14 ( struct V_13 * V_14 ,
struct V_10 * V_39 ,
struct V_10 * V_40 ,
unsigned int V_41 )
{
struct V_2 * V_3 ;
struct V_1 * V_1 ;
bool V_42 = false ;
F_15 ( & V_43 ) ;
V_1 = F_16 ( V_14 -> V_44 ) ;
V_3 = F_17 ( V_39 , V_40 , V_1 , V_41 ) ;
if ( V_3 == V_45 ) {
V_42 = true ;
V_3 = NULL ;
}
if ( V_3 ) {
F_11 ( V_3 , V_14 ) ;
goto V_46;
}
if ( F_12 ( V_42 ) ) {
struct V_2 * V_47 ;
V_47 = F_18 ( V_48 [ V_41 ] . V_49 ) ;
for ( V_3 = F_18 ( V_47 -> V_50 ) ; V_3 ;
V_3 = F_18 ( V_3 -> V_50 ) ) {
if ( F_19 ( V_3 -> V_17 , V_47 -> V_17 ) )
V_47 = V_3 ;
}
V_3 = V_47 ;
} else {
V_3 = F_20 ( sizeof( * V_3 ) , V_51 ) ;
if ( ! V_3 )
goto V_46;
}
F_21 ( & V_3 -> V_4 , V_1 ) ;
V_3 -> V_52 = * V_39 ;
V_3 -> V_53 = * V_40 ;
F_8 ( V_3 , V_14 , true ) ;
if ( F_22 ( ! V_42 ) ) {
V_3 -> V_50 = V_48 [ V_41 ] . V_49 ;
F_23 ( V_48 [ V_41 ] . V_49 , V_3 ) ;
}
V_46:
F_24 ( & V_43 ) ;
return V_3 ;
}
static struct V_2 * F_25 ( struct V_2 * V_3 , int V_54 )
{
if ( V_3 )
return V_3 ;
if ( V_54 > V_55 )
return V_45 ;
return NULL ;
}
static struct V_2 * F_17 ( const struct V_10 * V_39 ,
const struct V_10 * V_40 ,
struct V_1 * V_1 , unsigned int V_41 )
{
struct V_2 * V_3 ;
int V_54 = 0 ;
for ( V_3 = F_26 ( V_48 [ V_41 ] . V_49 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_50 ) ) {
if ( F_6 ( & V_3 -> V_52 , V_39 ) &&
F_6 ( & V_3 -> V_53 , V_40 ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) )
break;
V_54 ++ ;
}
return F_25 ( V_3 , V_54 ) ;
}
static struct V_2 * F_28 ( struct V_56 * V_57 ,
struct V_13 * V_14 )
{
struct V_2 * V_3 ;
struct V_10 V_39 , V_40 ;
unsigned int V_41 ;
struct V_1 * V_1 ;
V_39 . V_58 = V_57 -> V_59 -> V_58 ;
V_40 . V_58 = V_57 -> V_59 -> V_58 ;
switch ( V_40 . V_58 ) {
case V_60 :
F_29 ( & V_39 , F_30 ( V_57 ) -> V_61 ) ;
F_29 ( & V_40 , F_30 ( V_57 ) -> V_62 ) ;
V_41 = F_31 ( F_30 ( V_57 ) -> V_62 ) ;
break;
#if F_32 ( V_63 )
case V_64 :
F_33 ( & V_39 , & F_30 ( V_57 ) -> V_65 ) ;
F_33 ( & V_40 , & F_30 ( V_57 ) -> V_66 ) ;
V_41 = F_34 ( & F_30 ( V_57 ) -> V_66 ) ;
break;
#endif
default:
return NULL ;
}
V_1 = F_16 ( V_14 -> V_44 ) ;
V_41 ^= F_35 ( V_1 ) ;
V_41 = F_36 ( V_41 , V_67 ) ;
for ( V_3 = F_26 ( V_48 [ V_41 ] . V_49 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_50 ) ) {
if ( F_6 ( & V_3 -> V_52 , & V_39 ) &&
F_6 ( & V_3 -> V_53 , & V_40 ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) )
break;
}
F_11 ( V_3 , V_14 ) ;
return V_3 ;
}
static struct V_2 * F_37 ( struct V_68 * V_69 )
{
struct V_2 * V_3 ;
struct V_10 V_39 , V_40 ;
unsigned int V_41 ;
struct V_1 * V_1 ;
if ( V_69 -> V_70 == V_60 ) {
F_29 ( & V_39 , V_69 -> V_71 ) ;
F_29 ( & V_40 , V_69 -> V_72 ) ;
V_41 = F_31 ( V_69 -> V_72 ) ;
}
#if F_32 ( V_63 )
else if ( V_69 -> V_70 == V_64 ) {
if ( F_38 ( & V_69 -> V_73 ) ) {
F_29 ( & V_39 , V_69 -> V_71 ) ;
F_29 ( & V_40 , V_69 -> V_72 ) ;
V_41 = F_31 ( V_69 -> V_72 ) ;
} else {
F_33 ( & V_39 , & V_69 -> V_74 ) ;
F_33 ( & V_40 , & V_69 -> V_73 ) ;
V_41 = F_34 ( & V_69 -> V_73 ) ;
}
}
#endif
else
return NULL ;
V_1 = F_39 ( V_69 ) ;
V_41 ^= F_35 ( V_1 ) ;
V_41 = F_36 ( V_41 , V_67 ) ;
for ( V_3 = F_26 ( V_48 [ V_41 ] . V_49 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_50 ) ) {
if ( F_6 ( & V_3 -> V_52 , & V_39 ) &&
F_6 ( & V_3 -> V_53 , & V_40 ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) )
break;
}
return V_3 ;
}
static struct V_2 * F_40 ( struct V_75 * V_76 ,
struct V_13 * V_14 ,
bool V_77 )
{
struct V_2 * V_3 ;
struct V_10 V_39 , V_40 ;
unsigned int V_41 ;
struct V_1 * V_1 ;
if ( V_76 -> V_78 == V_60 ) {
F_29 ( & V_39 , F_41 ( V_76 ) -> V_79 ) ;
F_29 ( & V_40 , F_41 ( V_76 ) -> V_80 ) ;
V_41 = F_31 ( F_41 ( V_76 ) -> V_80 ) ;
}
#if F_32 ( V_63 )
else if ( V_76 -> V_78 == V_64 ) {
if ( F_38 ( & V_76 -> V_81 ) ) {
F_29 ( & V_39 , F_41 ( V_76 ) -> V_79 ) ;
F_29 ( & V_40 , F_41 ( V_76 ) -> V_80 ) ;
V_41 = F_31 ( F_41 ( V_76 ) -> V_80 ) ;
} else {
F_33 ( & V_39 , & V_76 -> V_82 ) ;
F_33 ( & V_40 , & V_76 -> V_81 ) ;
V_41 = F_34 ( & V_76 -> V_81 ) ;
}
}
#endif
else
return NULL ;
V_1 = F_16 ( V_14 -> V_44 ) ;
V_41 ^= F_35 ( V_1 ) ;
V_41 = F_36 ( V_41 , V_67 ) ;
V_3 = F_17 ( & V_39 , & V_40 , V_1 , V_41 ) ;
if ( V_3 == V_45 )
V_3 = NULL ;
if ( ! V_3 && V_77 )
V_3 = F_14 ( V_14 , & V_39 , & V_40 , V_41 ) ;
else
F_11 ( V_3 , V_14 ) ;
return V_3 ;
}
void F_42 ( struct V_75 * V_76 )
{
const struct V_83 * V_84 = F_43 ( V_76 ) ;
struct V_13 * V_14 = F_44 ( V_76 ) ;
struct V_85 * V_86 = F_45 ( V_76 ) ;
struct V_1 * V_1 = F_46 ( V_76 ) ;
struct V_2 * V_3 ;
unsigned long V_87 ;
T_1 V_9 ;
int V_88 ;
if ( V_89 || ! V_14 )
return;
if ( V_14 -> V_90 & V_91 )
F_47 ( V_14 ) ;
F_48 () ;
if ( V_84 -> V_92 || ! V_86 -> V_93 ) {
V_3 = F_40 ( V_76 , V_14 , false ) ;
if ( V_3 && ! F_3 ( V_3 , V_20 ) )
F_5 ( V_3 , V_20 , 0 ) ;
goto V_46;
} else
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( ! V_3 )
goto V_46;
V_87 = F_4 ( V_3 , V_20 ) ;
V_88 = V_87 - V_86 -> V_93 ;
if ( ! F_3 ( V_3 , V_20 ) ) {
if ( V_88 <= 0 )
V_87 = V_86 -> V_93 ;
else
V_87 -= ( V_88 >> 3 ) ;
F_5 ( V_3 , V_20 , V_87 ) ;
}
if ( ! F_3 ( V_3 , V_22 ) ) {
unsigned long V_94 ;
if ( V_88 < 0 )
V_88 = - V_88 ;
V_88 >>= 1 ;
if ( V_88 < V_86 -> V_95 )
V_88 = V_86 -> V_95 ;
V_94 = F_4 ( V_3 , V_22 ) ;
if ( V_88 >= V_94 )
V_94 = V_88 ;
else
V_94 -= ( V_94 - V_88 ) >> 2 ;
F_5 ( V_3 , V_22 , V_94 ) ;
}
if ( F_49 ( V_86 ) ) {
if ( ! F_3 ( V_3 , V_24 ) ) {
V_9 = F_4 ( V_3 , V_24 ) ;
if ( V_9 && ( V_86 -> V_96 >> 1 ) > V_9 )
F_5 ( V_3 , V_24 ,
V_86 -> V_96 >> 1 ) ;
}
if ( ! F_3 ( V_3 , V_26 ) ) {
V_9 = F_4 ( V_3 , V_26 ) ;
if ( V_86 -> V_96 > V_9 )
F_5 ( V_3 , V_26 ,
V_86 -> V_96 ) ;
}
} else if ( ! F_50 ( V_86 ) &&
V_84 -> V_97 == V_98 ) {
if ( ! F_3 ( V_3 , V_24 ) )
F_5 ( V_3 , V_24 ,
F_51 ( V_86 -> V_96 >> 1 , V_86 -> V_99 ) ) ;
if ( ! F_3 ( V_3 , V_26 ) ) {
V_9 = F_4 ( V_3 , V_26 ) ;
F_5 ( V_3 , V_26 , ( V_9 + V_86 -> V_96 ) >> 1 ) ;
}
} else {
if ( ! F_3 ( V_3 , V_26 ) ) {
V_9 = F_4 ( V_3 , V_26 ) ;
F_5 ( V_3 , V_26 ,
( V_9 + V_86 -> V_99 ) >> 1 ) ;
}
if ( ! F_3 ( V_3 , V_24 ) ) {
V_9 = F_4 ( V_3 , V_24 ) ;
if ( V_9 && V_86 -> V_99 > V_9 )
F_5 ( V_3 , V_24 ,
V_86 -> V_99 ) ;
}
if ( ! F_3 ( V_3 , V_28 ) ) {
V_9 = F_4 ( V_3 , V_28 ) ;
if ( V_9 < V_86 -> V_100 &&
V_86 -> V_100 != V_1 -> V_101 . V_102 )
F_5 ( V_3 , V_28 ,
V_86 -> V_100 ) ;
}
}
V_3 -> V_17 = V_18 ;
V_46:
F_52 () ;
}
void F_53 ( struct V_75 * V_76 )
{
struct V_13 * V_14 = F_44 ( V_76 ) ;
struct V_85 * V_86 = F_45 ( V_76 ) ;
struct V_2 * V_3 ;
T_1 V_9 , V_103 = 0 ;
if ( ! V_14 )
goto V_104;
F_47 ( V_14 ) ;
F_48 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( ! V_3 ) {
F_52 () ;
goto V_104;
}
if ( F_3 ( V_3 , V_26 ) )
V_86 -> V_105 = F_4 ( V_3 , V_26 ) ;
V_9 = F_4 ( V_3 , V_24 ) ;
if ( V_9 ) {
V_86 -> V_99 = V_9 ;
if ( V_86 -> V_99 > V_86 -> V_105 )
V_86 -> V_99 = V_86 -> V_105 ;
} else {
V_86 -> V_99 = V_106 ;
}
V_9 = F_4 ( V_3 , V_28 ) ;
if ( V_9 && V_86 -> V_100 != V_9 ) {
F_54 ( V_86 ) ;
F_55 ( V_86 ) ;
V_86 -> V_100 = V_9 ;
}
V_103 = F_4 ( V_3 , V_20 ) ;
F_52 () ;
V_104:
if ( V_103 > V_86 -> V_93 ) {
V_103 /= 8 * V_107 / V_108 ;
F_43 ( V_76 ) -> V_109 = V_103 + F_51 ( 2 * V_103 , F_56 ( V_76 ) ) ;
} else if ( V_86 -> V_93 == 0 ) {
V_86 -> V_110 = F_57 ( V_111 ) ;
V_86 -> V_95 = V_86 -> V_112 = V_86 -> V_110 ;
F_43 ( V_76 ) -> V_109 = V_111 ;
}
if ( V_86 -> V_113 > 1 )
V_86 -> V_96 = 1 ;
else
V_86 -> V_96 = F_58 ( V_86 , V_14 ) ;
V_86 -> V_114 = V_115 ;
}
bool F_59 ( struct V_56 * V_57 , struct V_13 * V_14 ,
bool V_116 , bool V_117 )
{
struct V_2 * V_3 ;
bool V_118 ;
if ( ! V_14 )
return false ;
F_48 () ;
V_3 = F_28 ( V_57 , V_14 ) ;
if ( V_116 ) {
if ( V_3 &&
( T_1 ) F_60 () - V_3 -> V_31 < V_119 &&
( ( V_120 ) ( V_3 -> V_30 - V_57 -> V_121 ) > V_122 ||
! V_117 ) )
V_118 = false ;
else
V_118 = true ;
} else {
if ( V_3 && F_4 ( V_3 , V_20 ) && V_3 -> V_31 )
V_118 = true ;
else
V_118 = false ;
}
F_52 () ;
return V_118 ;
}
void F_61 ( struct V_75 * V_76 , struct V_13 * V_14 )
{
struct V_2 * V_3 ;
F_48 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( V_3 ) {
struct V_85 * V_86 = F_45 ( V_76 ) ;
if ( ( T_1 ) F_60 () - V_3 -> V_31 <= V_119 ) {
V_86 -> V_123 . V_124 = V_3 -> V_31 ;
V_86 -> V_123 . V_121 = V_3 -> V_30 ;
}
}
F_52 () ;
}
bool F_62 ( struct V_75 * V_76 )
{
struct V_13 * V_14 = F_44 ( V_76 ) ;
bool V_118 = false ;
if ( V_14 ) {
struct V_2 * V_3 ;
F_48 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( V_3 ) {
struct V_85 * V_86 = F_45 ( V_76 ) ;
if ( ( V_120 ) ( V_3 -> V_30 - V_86 -> V_123 . V_121 ) <= 0 ||
( ( T_1 ) F_60 () - V_3 -> V_31 > V_119 &&
V_3 -> V_31 <= ( T_1 ) V_86 -> V_123 . V_124 ) ) {
V_3 -> V_31 = ( T_1 ) V_86 -> V_123 . V_124 ;
V_3 -> V_30 = V_86 -> V_123 . V_121 ;
}
V_118 = true ;
}
F_52 () ;
}
return V_118 ;
}
bool F_63 ( struct V_68 * V_69 )
{
struct V_2 * V_3 ;
bool V_118 = false ;
F_48 () ;
V_3 = F_37 ( V_69 ) ;
if ( V_3 ) {
const struct V_125 * V_126 ;
struct V_75 * V_76 = (struct V_75 * ) V_69 ;
V_126 = F_64 ( V_76 ) ;
if ( ( V_120 ) ( V_3 -> V_30 - V_126 -> V_127 ) <= 0 ||
( ( T_1 ) F_60 () - V_3 -> V_31 > V_119 &&
V_3 -> V_31 <= ( T_1 ) V_126 -> V_128 ) ) {
V_3 -> V_31 = ( T_1 ) V_126 -> V_128 ;
V_3 -> V_30 = V_126 -> V_127 ;
}
V_118 = true ;
}
F_52 () ;
return V_118 ;
}
void F_65 ( struct V_75 * V_76 , T_2 * V_33 ,
struct V_129 * V_36 ,
int * V_34 , unsigned long * V_130 )
{
struct V_2 * V_3 ;
F_48 () ;
V_3 = F_40 ( V_76 , F_44 ( V_76 ) , false ) ;
if ( V_3 ) {
struct V_131 * V_132 = & V_3 -> V_32 ;
unsigned int V_133 ;
do {
V_133 = F_66 ( & V_134 ) ;
if ( V_132 -> V_33 )
* V_33 = V_132 -> V_33 ;
* V_36 = V_132 -> V_36 ;
if ( V_36 -> V_37 <= 0 && V_132 -> V_35 == 1 )
V_36 -> exp = true ;
* V_34 = V_132 -> V_34 ;
* V_130 = * V_34 ? V_132 -> V_130 : 0 ;
} while ( F_67 ( & V_134 , V_133 ) );
}
F_52 () ;
}
void F_68 ( struct V_75 * V_76 , T_2 V_33 ,
struct V_129 * V_36 , bool V_135 ,
T_2 V_35 )
{
struct V_13 * V_14 = F_44 ( V_76 ) ;
struct V_2 * V_3 ;
if ( ! V_14 )
return;
F_48 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( V_3 ) {
struct V_131 * V_132 = & V_3 -> V_32 ;
F_69 ( & V_134 ) ;
if ( V_33 )
V_132 -> V_33 = V_33 ;
if ( V_36 && V_36 -> V_37 > 0 )
V_132 -> V_36 = * V_36 ;
else if ( V_35 > V_132 -> V_35 &&
V_132 -> V_36 . V_37 <= 0 && ! V_132 -> V_36 . exp )
V_132 -> V_35 = V_35 ;
if ( V_135 ) {
++ V_132 -> V_34 ;
V_132 -> V_130 = V_18 ;
} else
V_132 -> V_34 = 0 ;
F_70 ( & V_134 ) ;
}
F_52 () ;
}
static int F_71 ( struct V_136 * V_137 ,
struct V_2 * V_3 )
{
struct V_138 * V_139 ;
int V_140 ;
switch ( V_3 -> V_53 . V_58 ) {
case V_60 :
if ( F_72 ( V_137 , V_141 ,
F_73 ( & V_3 -> V_53 ) ) < 0 )
goto V_142;
if ( F_72 ( V_137 , V_143 ,
F_73 ( & V_3 -> V_52 ) ) < 0 )
goto V_142;
break;
case V_64 :
if ( F_74 ( V_137 , V_144 ,
F_75 ( & V_3 -> V_53 ) ) < 0 )
goto V_142;
if ( F_74 ( V_137 , V_145 ,
F_75 ( & V_3 -> V_52 ) ) < 0 )
goto V_142;
break;
default:
return - V_146 ;
}
if ( F_76 ( V_137 , V_147 ,
V_18 - V_3 -> V_17 ,
V_148 ) < 0 )
goto V_142;
if ( V_3 -> V_31 ) {
if ( F_77 ( V_137 , V_149 ,
( V_120 ) ( F_60 () - V_3 -> V_31 ) ) < 0 )
goto V_142;
if ( F_78 ( V_137 , V_150 ,
V_3 -> V_30 ) < 0 )
goto V_142;
}
{
int V_151 = 0 ;
V_139 = F_79 ( V_137 , V_152 ) ;
if ( ! V_139 )
goto V_142;
for ( V_140 = 0 ; V_140 < V_153 + 1 ; V_140 ++ ) {
T_1 V_9 = V_3 -> V_8 [ V_140 ] ;
if ( ! V_9 )
continue;
if ( V_140 == V_20 ) {
if ( F_78 ( V_137 , V_154 + 1 ,
V_9 ) < 0 )
goto V_142;
V_151 ++ ;
V_9 = F_51 ( V_9 / 1000 , 1U ) ;
}
if ( V_140 == V_22 ) {
if ( F_78 ( V_137 , V_155 + 1 ,
V_9 ) < 0 )
goto V_142;
V_151 ++ ;
V_9 = F_51 ( V_9 / 1000 , 1U ) ;
}
if ( F_78 ( V_137 , V_140 + 1 , V_9 ) < 0 )
goto V_142;
V_151 ++ ;
}
if ( V_151 )
F_80 ( V_137 , V_139 ) ;
else
F_81 ( V_137 , V_139 ) ;
}
{
struct V_131 V_156 [ 1 ] , * V_132 ;
unsigned int V_133 ;
do {
V_133 = F_66 ( & V_134 ) ;
V_156 [ 0 ] = V_3 -> V_32 ;
} while ( F_67 ( & V_134 , V_133 ) );
V_132 = V_156 ;
if ( V_132 -> V_33 &&
F_82 ( V_137 , V_157 ,
V_132 -> V_33 ) < 0 )
goto V_142;
if ( V_132 -> V_34 &&
( F_82 ( V_137 , V_158 ,
V_132 -> V_34 ) < 0 ||
F_76 ( V_137 , V_159 ,
V_18 - V_132 -> V_130 ,
V_148 ) < 0 ) )
goto V_142;
if ( V_132 -> V_36 . V_37 > 0 &&
F_83 ( V_137 , V_160 ,
V_132 -> V_36 . V_37 , V_132 -> V_36 . V_9 ) < 0 )
goto V_142;
}
return 0 ;
V_142:
return - V_161 ;
}
static int F_84 ( struct V_136 * V_162 ,
struct V_163 * V_164 ,
struct V_2 * V_3 )
{
void * V_165 ;
V_165 = F_85 ( V_162 , F_86 ( V_164 -> V_162 ) . V_166 , V_164 -> V_167 -> V_168 ,
& V_169 , V_170 ,
V_171 ) ;
if ( ! V_165 )
return - V_161 ;
if ( F_71 ( V_162 , V_3 ) < 0 )
goto V_142;
F_87 ( V_162 , V_165 ) ;
return 0 ;
V_142:
F_88 ( V_162 , V_165 ) ;
return - V_161 ;
}
static int F_89 ( struct V_136 * V_162 ,
struct V_163 * V_164 )
{
struct V_1 * V_1 = F_46 ( V_162 -> V_76 ) ;
unsigned int V_172 = 1U << V_67 ;
unsigned int V_173 , V_174 = V_164 -> args [ 0 ] ;
int V_175 = V_164 -> args [ 1 ] , V_176 = V_175 ;
for ( V_173 = V_174 ; V_173 < V_172 ; V_173 ++ , V_175 = 0 ) {
struct V_2 * V_3 ;
struct V_177 * V_178 = V_48 + V_173 ;
F_48 () ;
for ( V_176 = 0 , V_3 = F_26 ( V_178 -> V_49 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_50 ) , V_176 ++ ) {
if ( ! F_27 ( F_1 ( V_3 ) , V_1 ) )
continue;
if ( V_176 < V_175 )
continue;
if ( F_84 ( V_162 , V_164 , V_3 ) < 0 ) {
F_52 () ;
goto V_179;
}
}
F_52 () ;
}
V_179:
V_164 -> args [ 0 ] = V_173 ;
V_164 -> args [ 1 ] = V_176 ;
return V_162 -> V_37 ;
}
static int F_90 ( struct V_180 * V_181 , struct V_10 * V_182 ,
unsigned int * V_41 , int V_183 , int V_184 , int V_185 )
{
struct V_138 * V_11 ;
V_11 = V_181 -> V_186 [ V_184 ] ;
if ( V_11 ) {
F_29 ( V_182 , F_91 ( V_11 ) ) ;
if ( V_41 )
* V_41 = F_31 ( F_73 ( V_182 ) ) ;
return 0 ;
}
V_11 = V_181 -> V_186 [ V_185 ] ;
if ( V_11 ) {
struct V_187 V_188 ;
if ( F_92 ( V_11 ) != sizeof( struct V_187 ) )
return - V_189 ;
V_188 = F_93 ( V_11 ) ;
F_33 ( V_182 , & V_188 ) ;
if ( V_41 )
* V_41 = F_34 ( F_75 ( V_182 ) ) ;
return 0 ;
}
return V_183 ? 1 : - V_146 ;
}
static int F_94 ( struct V_180 * V_181 , struct V_10 * V_182 ,
unsigned int * V_41 , int V_183 )
{
return F_90 ( V_181 , V_182 , V_41 , V_183 ,
V_141 ,
V_144 ) ;
}
static int F_95 ( struct V_180 * V_181 , struct V_10 * V_182 )
{
return F_90 ( V_181 , V_182 , NULL , 0 ,
V_143 ,
V_145 ) ;
}
static int F_96 ( struct V_136 * V_162 , struct V_180 * V_181 )
{
struct V_2 * V_3 ;
struct V_10 V_39 , V_40 ;
unsigned int V_41 ;
struct V_136 * V_137 ;
struct V_1 * V_1 = F_97 ( V_181 ) ;
void * V_190 ;
int V_118 ;
bool V_191 = true ;
V_118 = F_94 ( V_181 , & V_40 , & V_41 , 0 ) ;
if ( V_118 < 0 )
return V_118 ;
V_118 = F_95 ( V_181 , & V_39 ) ;
if ( V_118 < 0 )
V_191 = false ;
V_137 = F_98 ( V_192 , V_193 ) ;
if ( ! V_137 )
return - V_194 ;
V_190 = F_99 ( V_137 , V_181 , & V_169 , 0 ,
V_181 -> V_195 -> V_196 ) ;
if ( ! V_190 )
goto V_142;
V_41 ^= F_35 ( V_1 ) ;
V_41 = F_36 ( V_41 , V_67 ) ;
V_118 = - V_197 ;
F_48 () ;
for ( V_3 = F_26 ( V_48 [ V_41 ] . V_49 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_50 ) ) {
if ( F_6 ( & V_3 -> V_53 , & V_40 ) &&
( ! V_191 || F_6 ( & V_3 -> V_52 , & V_39 ) ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) ) {
V_118 = F_71 ( V_137 , V_3 ) ;
break;
}
}
F_52 () ;
if ( V_118 < 0 )
goto V_198;
F_87 ( V_137 , V_190 ) ;
return F_100 ( V_137 , V_181 ) ;
V_142:
V_118 = - V_161 ;
V_198:
F_101 ( V_137 ) ;
return V_118 ;
}
static void F_102 ( struct V_1 * V_1 )
{
unsigned int V_172 = 1U << V_67 ;
struct V_177 * V_178 = V_48 ;
struct V_2 * V_3 ;
unsigned int V_173 ;
for ( V_173 = 0 ; V_173 < V_172 ; V_173 ++ , V_178 ++ ) {
struct V_2 T_3 * * V_199 ;
F_15 ( & V_43 ) ;
V_199 = & V_178 -> V_49 ;
for ( V_3 = F_18 ( * V_199 ) ; V_3 ; V_3 = F_18 ( * V_199 ) ) {
if ( F_27 ( F_1 ( V_3 ) , V_1 ) ) {
* V_199 = V_3 -> V_50 ;
F_103 ( V_3 , V_200 ) ;
} else {
V_199 = & V_3 -> V_50 ;
}
}
F_24 ( & V_43 ) ;
}
}
static int F_104 ( struct V_136 * V_162 , struct V_180 * V_181 )
{
struct V_177 * V_178 ;
struct V_2 * V_3 ;
struct V_2 T_3 * * V_199 ;
struct V_10 V_39 , V_40 ;
unsigned int V_41 ;
struct V_1 * V_1 = F_97 ( V_181 ) ;
int V_118 ;
bool V_191 = true , V_201 = false ;
V_118 = F_94 ( V_181 , & V_40 , & V_41 , 1 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( V_118 > 0 ) {
F_102 ( V_1 ) ;
return 0 ;
}
V_118 = F_95 ( V_181 , & V_39 ) ;
if ( V_118 < 0 )
V_191 = false ;
V_41 ^= F_35 ( V_1 ) ;
V_41 = F_36 ( V_41 , V_67 ) ;
V_178 = V_48 + V_41 ;
V_199 = & V_178 -> V_49 ;
F_15 ( & V_43 ) ;
for ( V_3 = F_18 ( * V_199 ) ; V_3 ; V_3 = F_18 ( * V_199 ) ) {
if ( F_6 ( & V_3 -> V_53 , & V_40 ) &&
( ! V_191 || F_6 ( & V_3 -> V_52 , & V_39 ) ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) ) {
* V_199 = V_3 -> V_50 ;
F_103 ( V_3 , V_200 ) ;
V_201 = true ;
} else {
V_199 = & V_3 -> V_50 ;
}
}
F_24 ( & V_43 ) ;
if ( ! V_201 )
return - V_197 ;
return 0 ;
}
static int T_4 F_105 ( char * V_202 )
{
T_5 V_118 ;
if ( ! V_202 )
return 0 ;
V_118 = F_106 ( V_202 , 0 , & V_203 ) ;
if ( V_118 )
return 0 ;
return 1 ;
}
static int T_6 F_107 ( struct V_1 * V_1 )
{
T_7 V_204 ;
unsigned int V_205 ;
if ( ! F_27 ( V_1 , & V_206 ) )
return 0 ;
V_205 = V_203 ;
if ( ! V_205 ) {
if ( V_207 >= 128 * 1024 )
V_205 = 16 * 1024 ;
else
V_205 = 8 * 1024 ;
}
V_67 = F_108 ( V_205 ) ;
V_204 = sizeof( struct V_177 ) << V_67 ;
V_48 = F_109 ( V_204 , V_193 | V_208 ) ;
if ( ! V_48 )
V_48 = F_110 ( V_204 ) ;
if ( ! V_48 )
return - V_194 ;
return 0 ;
}
static void T_8 F_111 ( struct V_1 * V_1 )
{
F_102 ( V_1 ) ;
}
void T_4 F_112 ( void )
{
int V_118 ;
V_118 = F_113 ( & V_209 ) ;
if ( V_118 < 0 )
F_114 ( L_1 ) ;
V_118 = F_115 ( & V_169 ,
V_210 ) ;
if ( V_118 < 0 )
F_114 ( L_2 ) ;
}
