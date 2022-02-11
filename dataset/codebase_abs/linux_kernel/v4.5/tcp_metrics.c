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
struct V_2 * V_3 ;
unsigned long V_87 ;
T_1 V_9 ;
int V_88 ;
if ( V_89 || ! V_14 )
return;
if ( V_14 -> V_90 & V_91 )
F_46 ( V_14 ) ;
F_47 () ;
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
if ( F_48 ( V_86 ) ) {
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
} else if ( ! F_49 ( V_86 ) &&
V_84 -> V_97 == V_98 ) {
if ( ! F_3 ( V_3 , V_24 ) )
F_5 ( V_3 , V_24 ,
F_50 ( V_86 -> V_96 >> 1 , V_86 -> V_99 ) ) ;
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
V_86 -> V_100 != V_101 )
F_5 ( V_3 , V_28 ,
V_86 -> V_100 ) ;
}
}
V_3 -> V_17 = V_18 ;
V_46:
F_51 () ;
}
void F_52 ( struct V_75 * V_76 )
{
struct V_13 * V_14 = F_44 ( V_76 ) ;
struct V_85 * V_86 = F_45 ( V_76 ) ;
struct V_2 * V_3 ;
T_1 V_9 , V_102 = 0 ;
if ( ! V_14 )
goto V_103;
F_46 ( V_14 ) ;
F_47 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( ! V_3 ) {
F_51 () ;
goto V_103;
}
if ( F_3 ( V_3 , V_26 ) )
V_86 -> V_104 = F_4 ( V_3 , V_26 ) ;
V_9 = F_4 ( V_3 , V_24 ) ;
if ( V_9 ) {
V_86 -> V_99 = V_9 ;
if ( V_86 -> V_99 > V_86 -> V_104 )
V_86 -> V_99 = V_86 -> V_104 ;
} else {
V_86 -> V_99 = V_105 ;
}
V_9 = F_4 ( V_3 , V_28 ) ;
if ( V_9 && V_86 -> V_100 != V_9 ) {
F_53 ( V_86 ) ;
F_54 ( V_86 ) ;
V_86 -> V_100 = V_9 ;
}
V_102 = F_4 ( V_3 , V_20 ) ;
F_51 () ;
V_103:
if ( V_102 > V_86 -> V_93 ) {
V_102 /= 8 * V_106 / V_107 ;
F_43 ( V_76 ) -> V_108 = V_102 + F_50 ( 2 * V_102 , F_55 ( V_76 ) ) ;
} else if ( V_86 -> V_93 == 0 ) {
V_86 -> V_109 = F_56 ( V_110 ) ;
V_86 -> V_95 = V_86 -> V_111 = V_86 -> V_109 ;
F_43 ( V_76 ) -> V_108 = V_110 ;
}
if ( V_86 -> V_112 > 1 )
V_86 -> V_96 = 1 ;
else
V_86 -> V_96 = F_57 ( V_86 , V_14 ) ;
V_86 -> V_113 = V_114 ;
}
bool F_58 ( struct V_56 * V_57 , struct V_13 * V_14 ,
bool V_115 , bool V_116 )
{
struct V_2 * V_3 ;
bool V_117 ;
if ( ! V_14 )
return false ;
F_47 () ;
V_3 = F_28 ( V_57 , V_14 ) ;
if ( V_115 ) {
if ( V_3 &&
( T_1 ) F_59 () - V_3 -> V_31 < V_118 &&
( ( V_119 ) ( V_3 -> V_30 - V_57 -> V_120 ) > V_121 ||
! V_116 ) )
V_117 = false ;
else
V_117 = true ;
} else {
if ( V_3 && F_4 ( V_3 , V_20 ) && V_3 -> V_31 )
V_117 = true ;
else
V_117 = false ;
}
F_51 () ;
return V_117 ;
}
void F_60 ( struct V_75 * V_76 , struct V_13 * V_14 )
{
struct V_2 * V_3 ;
F_47 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( V_3 ) {
struct V_85 * V_86 = F_45 ( V_76 ) ;
if ( ( T_1 ) F_59 () - V_3 -> V_31 <= V_118 ) {
V_86 -> V_122 . V_123 = V_3 -> V_31 ;
V_86 -> V_122 . V_120 = V_3 -> V_30 ;
}
}
F_51 () ;
}
bool F_61 ( struct V_75 * V_76 )
{
struct V_13 * V_14 = F_44 ( V_76 ) ;
bool V_117 = false ;
if ( V_14 ) {
struct V_2 * V_3 ;
F_47 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( V_3 ) {
struct V_85 * V_86 = F_45 ( V_76 ) ;
if ( ( V_119 ) ( V_3 -> V_30 - V_86 -> V_122 . V_120 ) <= 0 ||
( ( T_1 ) F_59 () - V_3 -> V_31 > V_118 &&
V_3 -> V_31 <= ( T_1 ) V_86 -> V_122 . V_123 ) ) {
V_3 -> V_31 = ( T_1 ) V_86 -> V_122 . V_123 ;
V_3 -> V_30 = V_86 -> V_122 . V_120 ;
}
V_117 = true ;
}
F_51 () ;
}
return V_117 ;
}
bool F_62 ( struct V_68 * V_69 )
{
struct V_2 * V_3 ;
bool V_117 = false ;
F_47 () ;
V_3 = F_37 ( V_69 ) ;
if ( V_3 ) {
const struct V_124 * V_125 ;
struct V_75 * V_76 = (struct V_75 * ) V_69 ;
V_125 = F_63 ( V_76 ) ;
if ( ( V_119 ) ( V_3 -> V_30 - V_125 -> V_126 ) <= 0 ||
( ( T_1 ) F_59 () - V_3 -> V_31 > V_118 &&
V_3 -> V_31 <= ( T_1 ) V_125 -> V_127 ) ) {
V_3 -> V_31 = ( T_1 ) V_125 -> V_127 ;
V_3 -> V_30 = V_125 -> V_126 ;
}
V_117 = true ;
}
F_51 () ;
return V_117 ;
}
void F_64 ( struct V_75 * V_76 , T_2 * V_33 ,
struct V_128 * V_36 ,
int * V_34 , unsigned long * V_129 )
{
struct V_2 * V_3 ;
F_47 () ;
V_3 = F_40 ( V_76 , F_44 ( V_76 ) , false ) ;
if ( V_3 ) {
struct V_130 * V_131 = & V_3 -> V_32 ;
unsigned int V_132 ;
do {
V_132 = F_65 ( & V_133 ) ;
if ( V_131 -> V_33 )
* V_33 = V_131 -> V_33 ;
* V_36 = V_131 -> V_36 ;
if ( V_36 -> V_37 <= 0 && V_131 -> V_35 == 1 )
V_36 -> exp = true ;
* V_34 = V_131 -> V_34 ;
* V_129 = * V_34 ? V_131 -> V_129 : 0 ;
} while ( F_66 ( & V_133 , V_132 ) );
}
F_51 () ;
}
void F_67 ( struct V_75 * V_76 , T_2 V_33 ,
struct V_128 * V_36 , bool V_134 ,
T_2 V_35 )
{
struct V_13 * V_14 = F_44 ( V_76 ) ;
struct V_2 * V_3 ;
if ( ! V_14 )
return;
F_47 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( V_3 ) {
struct V_130 * V_131 = & V_3 -> V_32 ;
F_68 ( & V_133 ) ;
if ( V_33 )
V_131 -> V_33 = V_33 ;
if ( V_36 && V_36 -> V_37 > 0 )
V_131 -> V_36 = * V_36 ;
else if ( V_35 > V_131 -> V_35 &&
V_131 -> V_36 . V_37 <= 0 && ! V_131 -> V_36 . exp )
V_131 -> V_35 = V_35 ;
if ( V_134 ) {
++ V_131 -> V_34 ;
V_131 -> V_129 = V_18 ;
} else
V_131 -> V_34 = 0 ;
F_69 ( & V_133 ) ;
}
F_51 () ;
}
static int F_70 ( struct V_135 * V_136 ,
struct V_2 * V_3 )
{
struct V_137 * V_138 ;
int V_139 ;
switch ( V_3 -> V_53 . V_58 ) {
case V_60 :
if ( F_71 ( V_136 , V_140 ,
F_72 ( & V_3 -> V_53 ) ) < 0 )
goto V_141;
if ( F_71 ( V_136 , V_142 ,
F_72 ( & V_3 -> V_52 ) ) < 0 )
goto V_141;
break;
case V_64 :
if ( F_73 ( V_136 , V_143 ,
F_74 ( & V_3 -> V_53 ) ) < 0 )
goto V_141;
if ( F_73 ( V_136 , V_144 ,
F_74 ( & V_3 -> V_52 ) ) < 0 )
goto V_141;
break;
default:
return - V_145 ;
}
if ( F_75 ( V_136 , V_146 ,
V_18 - V_3 -> V_17 ) < 0 )
goto V_141;
if ( V_3 -> V_31 ) {
if ( F_76 ( V_136 , V_147 ,
( V_119 ) ( F_59 () - V_3 -> V_31 ) ) < 0 )
goto V_141;
if ( F_77 ( V_136 , V_148 ,
V_3 -> V_30 ) < 0 )
goto V_141;
}
{
int V_149 = 0 ;
V_138 = F_78 ( V_136 , V_150 ) ;
if ( ! V_138 )
goto V_141;
for ( V_139 = 0 ; V_139 < V_151 + 1 ; V_139 ++ ) {
T_1 V_9 = V_3 -> V_8 [ V_139 ] ;
if ( ! V_9 )
continue;
if ( V_139 == V_20 ) {
if ( F_77 ( V_136 , V_152 + 1 ,
V_9 ) < 0 )
goto V_141;
V_149 ++ ;
V_9 = F_50 ( V_9 / 1000 , 1U ) ;
}
if ( V_139 == V_22 ) {
if ( F_77 ( V_136 , V_153 + 1 ,
V_9 ) < 0 )
goto V_141;
V_149 ++ ;
V_9 = F_50 ( V_9 / 1000 , 1U ) ;
}
if ( F_77 ( V_136 , V_139 + 1 , V_9 ) < 0 )
goto V_141;
V_149 ++ ;
}
if ( V_149 )
F_79 ( V_136 , V_138 ) ;
else
F_80 ( V_136 , V_138 ) ;
}
{
struct V_130 V_154 [ 1 ] , * V_131 ;
unsigned int V_132 ;
do {
V_132 = F_65 ( & V_133 ) ;
V_154 [ 0 ] = V_3 -> V_32 ;
} while ( F_66 ( & V_133 , V_132 ) );
V_131 = V_154 ;
if ( V_131 -> V_33 &&
F_81 ( V_136 , V_155 ,
V_131 -> V_33 ) < 0 )
goto V_141;
if ( V_131 -> V_34 &&
( F_81 ( V_136 , V_156 ,
V_131 -> V_34 ) < 0 ||
F_75 ( V_136 , V_157 ,
V_18 - V_131 -> V_129 ) < 0 ) )
goto V_141;
if ( V_131 -> V_36 . V_37 > 0 &&
F_82 ( V_136 , V_158 ,
V_131 -> V_36 . V_37 , V_131 -> V_36 . V_9 ) < 0 )
goto V_141;
}
return 0 ;
V_141:
return - V_159 ;
}
static int F_83 ( struct V_135 * V_160 ,
struct V_161 * V_162 ,
struct V_2 * V_3 )
{
void * V_163 ;
V_163 = F_84 ( V_160 , F_85 ( V_162 -> V_160 ) . V_164 , V_162 -> V_165 -> V_166 ,
& V_167 , V_168 ,
V_169 ) ;
if ( ! V_163 )
return - V_159 ;
if ( F_70 ( V_160 , V_3 ) < 0 )
goto V_141;
F_86 ( V_160 , V_163 ) ;
return 0 ;
V_141:
F_87 ( V_160 , V_163 ) ;
return - V_159 ;
}
static int F_88 ( struct V_135 * V_160 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_89 ( V_160 -> V_76 ) ;
unsigned int V_170 = 1U << V_67 ;
unsigned int V_171 , V_172 = V_162 -> args [ 0 ] ;
int V_173 = V_162 -> args [ 1 ] , V_174 = V_173 ;
for ( V_171 = V_172 ; V_171 < V_170 ; V_171 ++ , V_173 = 0 ) {
struct V_2 * V_3 ;
struct V_175 * V_176 = V_48 + V_171 ;
F_47 () ;
for ( V_174 = 0 , V_3 = F_26 ( V_176 -> V_49 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_50 ) , V_174 ++ ) {
if ( ! F_27 ( F_1 ( V_3 ) , V_1 ) )
continue;
if ( V_174 < V_173 )
continue;
if ( F_83 ( V_160 , V_162 , V_3 ) < 0 ) {
F_51 () ;
goto V_177;
}
}
F_51 () ;
}
V_177:
V_162 -> args [ 0 ] = V_171 ;
V_162 -> args [ 1 ] = V_174 ;
return V_160 -> V_37 ;
}
static int F_90 ( struct V_178 * V_179 , struct V_10 * V_180 ,
unsigned int * V_41 , int V_181 , int V_182 , int V_183 )
{
struct V_137 * V_11 ;
V_11 = V_179 -> V_184 [ V_182 ] ;
if ( V_11 ) {
F_29 ( V_180 , F_91 ( V_11 ) ) ;
if ( V_41 )
* V_41 = F_31 ( F_72 ( V_180 ) ) ;
return 0 ;
}
V_11 = V_179 -> V_184 [ V_183 ] ;
if ( V_11 ) {
struct V_185 V_186 ;
if ( F_92 ( V_11 ) != sizeof( struct V_185 ) )
return - V_187 ;
V_186 = F_93 ( V_11 ) ;
F_33 ( V_180 , & V_186 ) ;
if ( V_41 )
* V_41 = F_34 ( F_74 ( V_180 ) ) ;
return 0 ;
}
return V_181 ? 1 : - V_145 ;
}
static int F_94 ( struct V_178 * V_179 , struct V_10 * V_180 ,
unsigned int * V_41 , int V_181 )
{
return F_90 ( V_179 , V_180 , V_41 , V_181 ,
V_140 ,
V_143 ) ;
}
static int F_95 ( struct V_178 * V_179 , struct V_10 * V_180 )
{
return F_90 ( V_179 , V_180 , NULL , 0 ,
V_142 ,
V_144 ) ;
}
static int F_96 ( struct V_135 * V_160 , struct V_178 * V_179 )
{
struct V_2 * V_3 ;
struct V_10 V_39 , V_40 ;
unsigned int V_41 ;
struct V_135 * V_136 ;
struct V_1 * V_1 = F_97 ( V_179 ) ;
void * V_188 ;
int V_117 ;
bool V_189 = true ;
V_117 = F_94 ( V_179 , & V_40 , & V_41 , 0 ) ;
if ( V_117 < 0 )
return V_117 ;
V_117 = F_95 ( V_179 , & V_39 ) ;
if ( V_117 < 0 )
V_189 = false ;
V_136 = F_98 ( V_190 , V_191 ) ;
if ( ! V_136 )
return - V_192 ;
V_188 = F_99 ( V_136 , V_179 , & V_167 , 0 ,
V_179 -> V_193 -> V_194 ) ;
if ( ! V_188 )
goto V_141;
V_41 ^= F_35 ( V_1 ) ;
V_41 = F_36 ( V_41 , V_67 ) ;
V_117 = - V_195 ;
F_47 () ;
for ( V_3 = F_26 ( V_48 [ V_41 ] . V_49 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_50 ) ) {
if ( F_6 ( & V_3 -> V_53 , & V_40 ) &&
( ! V_189 || F_6 ( & V_3 -> V_52 , & V_39 ) ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) ) {
V_117 = F_70 ( V_136 , V_3 ) ;
break;
}
}
F_51 () ;
if ( V_117 < 0 )
goto V_196;
F_86 ( V_136 , V_188 ) ;
return F_100 ( V_136 , V_179 ) ;
V_141:
V_117 = - V_159 ;
V_196:
F_101 ( V_136 ) ;
return V_117 ;
}
static void F_102 ( struct V_1 * V_1 )
{
unsigned int V_170 = 1U << V_67 ;
struct V_175 * V_176 = V_48 ;
struct V_2 * V_3 ;
unsigned int V_171 ;
for ( V_171 = 0 ; V_171 < V_170 ; V_171 ++ , V_176 ++ ) {
struct V_2 T_3 * * V_197 ;
F_15 ( & V_43 ) ;
V_197 = & V_176 -> V_49 ;
for ( V_3 = F_18 ( * V_197 ) ; V_3 ; V_3 = F_18 ( * V_197 ) ) {
if ( F_27 ( F_1 ( V_3 ) , V_1 ) ) {
* V_197 = V_3 -> V_50 ;
F_103 ( V_3 , V_198 ) ;
} else {
V_197 = & V_3 -> V_50 ;
}
}
F_24 ( & V_43 ) ;
}
}
static int F_104 ( struct V_135 * V_160 , struct V_178 * V_179 )
{
struct V_175 * V_176 ;
struct V_2 * V_3 ;
struct V_2 T_3 * * V_197 ;
struct V_10 V_39 , V_40 ;
unsigned int V_41 ;
struct V_1 * V_1 = F_97 ( V_179 ) ;
int V_117 ;
bool V_189 = true , V_199 = false ;
V_117 = F_94 ( V_179 , & V_40 , & V_41 , 1 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( V_117 > 0 ) {
F_102 ( V_1 ) ;
return 0 ;
}
V_117 = F_95 ( V_179 , & V_39 ) ;
if ( V_117 < 0 )
V_189 = false ;
V_41 ^= F_35 ( V_1 ) ;
V_41 = F_36 ( V_41 , V_67 ) ;
V_176 = V_48 + V_41 ;
V_197 = & V_176 -> V_49 ;
F_15 ( & V_43 ) ;
for ( V_3 = F_18 ( * V_197 ) ; V_3 ; V_3 = F_18 ( * V_197 ) ) {
if ( F_6 ( & V_3 -> V_53 , & V_40 ) &&
( ! V_189 || F_6 ( & V_3 -> V_52 , & V_39 ) ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) ) {
* V_197 = V_3 -> V_50 ;
F_103 ( V_3 , V_198 ) ;
V_199 = true ;
} else {
V_197 = & V_3 -> V_50 ;
}
}
F_24 ( & V_43 ) ;
if ( ! V_199 )
return - V_195 ;
return 0 ;
}
static int T_4 F_105 ( char * V_200 )
{
T_5 V_117 ;
if ( ! V_200 )
return 0 ;
V_117 = F_106 ( V_200 , 0 , & V_201 ) ;
if ( V_117 )
return 0 ;
return 1 ;
}
static int T_6 F_107 ( struct V_1 * V_1 )
{
T_7 V_202 ;
unsigned int V_203 ;
if ( ! F_27 ( V_1 , & V_204 ) )
return 0 ;
V_203 = V_201 ;
if ( ! V_203 ) {
if ( V_205 >= 128 * 1024 )
V_203 = 16 * 1024 ;
else
V_203 = 8 * 1024 ;
}
V_67 = F_108 ( V_203 ) ;
V_202 = sizeof( struct V_175 ) << V_67 ;
V_48 = F_109 ( V_202 , V_191 | V_206 ) ;
if ( ! V_48 )
V_48 = F_110 ( V_202 ) ;
if ( ! V_48 )
return - V_192 ;
return 0 ;
}
static void T_8 F_111 ( struct V_1 * V_1 )
{
F_102 ( V_1 ) ;
}
void T_4 F_112 ( void )
{
int V_117 ;
V_117 = F_113 ( & V_207 ) ;
if ( V_117 < 0 )
F_114 ( L_1 ) ;
V_117 = F_115 ( & V_167 ,
V_208 ) ;
if ( V_117 < 0 )
F_114 ( L_2 ) ;
}
