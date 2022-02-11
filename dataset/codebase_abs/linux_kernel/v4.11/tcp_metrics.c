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
F_47 ( V_76 ) ;
if ( V_89 || ! V_14 )
return;
F_48 () ;
if ( V_84 -> V_90 || ! V_86 -> V_91 ) {
V_3 = F_40 ( V_76 , V_14 , false ) ;
if ( V_3 && ! F_3 ( V_3 , V_20 ) )
F_5 ( V_3 , V_20 , 0 ) ;
goto V_46;
} else
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( ! V_3 )
goto V_46;
V_87 = F_4 ( V_3 , V_20 ) ;
V_88 = V_87 - V_86 -> V_91 ;
if ( ! F_3 ( V_3 , V_20 ) ) {
if ( V_88 <= 0 )
V_87 = V_86 -> V_91 ;
else
V_87 -= ( V_88 >> 3 ) ;
F_5 ( V_3 , V_20 , V_87 ) ;
}
if ( ! F_3 ( V_3 , V_22 ) ) {
unsigned long V_92 ;
if ( V_88 < 0 )
V_88 = - V_88 ;
V_88 >>= 1 ;
if ( V_88 < V_86 -> V_93 )
V_88 = V_86 -> V_93 ;
V_92 = F_4 ( V_3 , V_22 ) ;
if ( V_88 >= V_92 )
V_92 = V_88 ;
else
V_92 -= ( V_92 - V_88 ) >> 2 ;
F_5 ( V_3 , V_22 , V_92 ) ;
}
if ( F_49 ( V_86 ) ) {
if ( ! F_3 ( V_3 , V_24 ) ) {
V_9 = F_4 ( V_3 , V_24 ) ;
if ( V_9 && ( V_86 -> V_94 >> 1 ) > V_9 )
F_5 ( V_3 , V_24 ,
V_86 -> V_94 >> 1 ) ;
}
if ( ! F_3 ( V_3 , V_26 ) ) {
V_9 = F_4 ( V_3 , V_26 ) ;
if ( V_86 -> V_94 > V_9 )
F_5 ( V_3 , V_26 ,
V_86 -> V_94 ) ;
}
} else if ( ! F_50 ( V_86 ) &&
V_84 -> V_95 == V_96 ) {
if ( ! F_3 ( V_3 , V_24 ) )
F_5 ( V_3 , V_24 ,
F_51 ( V_86 -> V_94 >> 1 , V_86 -> V_97 ) ) ;
if ( ! F_3 ( V_3 , V_26 ) ) {
V_9 = F_4 ( V_3 , V_26 ) ;
F_5 ( V_3 , V_26 , ( V_9 + V_86 -> V_94 ) >> 1 ) ;
}
} else {
if ( ! F_3 ( V_3 , V_26 ) ) {
V_9 = F_4 ( V_3 , V_26 ) ;
F_5 ( V_3 , V_26 ,
( V_9 + V_86 -> V_97 ) >> 1 ) ;
}
if ( ! F_3 ( V_3 , V_24 ) ) {
V_9 = F_4 ( V_3 , V_24 ) ;
if ( V_9 && V_86 -> V_97 > V_9 )
F_5 ( V_3 , V_24 ,
V_86 -> V_97 ) ;
}
if ( ! F_3 ( V_3 , V_28 ) ) {
V_9 = F_4 ( V_3 , V_28 ) ;
if ( V_9 < V_86 -> V_98 &&
V_86 -> V_98 != V_1 -> V_99 . V_100 )
F_5 ( V_3 , V_28 ,
V_86 -> V_98 ) ;
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
T_1 V_9 , V_101 = 0 ;
F_47 ( V_76 ) ;
if ( ! V_14 )
goto V_102;
F_48 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( ! V_3 ) {
F_52 () ;
goto V_102;
}
if ( F_3 ( V_3 , V_26 ) )
V_86 -> V_103 = F_4 ( V_3 , V_26 ) ;
V_9 = F_4 ( V_3 , V_24 ) ;
if ( V_9 ) {
V_86 -> V_97 = V_9 ;
if ( V_86 -> V_97 > V_86 -> V_103 )
V_86 -> V_97 = V_86 -> V_103 ;
} else {
V_86 -> V_97 = V_104 ;
}
V_9 = F_4 ( V_3 , V_28 ) ;
if ( V_9 && V_86 -> V_98 != V_9 ) {
F_54 ( V_86 ) ;
V_86 -> V_98 = V_9 ;
}
V_101 = F_4 ( V_3 , V_20 ) ;
F_52 () ;
V_102:
if ( V_101 > V_86 -> V_91 ) {
V_101 /= 8 * V_105 / V_106 ;
F_43 ( V_76 ) -> V_107 = V_101 + F_51 ( 2 * V_101 , F_55 ( V_76 ) ) ;
} else if ( V_86 -> V_91 == 0 ) {
V_86 -> V_108 = F_56 ( V_109 ) ;
V_86 -> V_93 = V_86 -> V_110 = V_86 -> V_108 ;
F_43 ( V_76 ) -> V_107 = V_109 ;
}
if ( V_86 -> V_111 > 1 )
V_86 -> V_94 = 1 ;
else
V_86 -> V_94 = F_57 ( V_86 , V_14 ) ;
V_86 -> V_112 = V_113 ;
}
bool F_58 ( struct V_56 * V_57 , struct V_13 * V_14 ,
bool V_114 , bool V_115 )
{
struct V_2 * V_3 ;
bool V_116 ;
if ( ! V_14 )
return false ;
F_48 () ;
V_3 = F_28 ( V_57 , V_14 ) ;
if ( V_114 ) {
if ( V_3 &&
( T_1 ) F_59 () - V_3 -> V_31 < V_117 &&
( ( V_118 ) ( V_3 -> V_30 - V_57 -> V_119 ) > V_120 ||
! V_115 ) )
V_116 = false ;
else
V_116 = true ;
} else {
if ( V_3 && F_4 ( V_3 , V_20 ) && V_3 -> V_31 )
V_116 = true ;
else
V_116 = false ;
}
F_52 () ;
return V_116 ;
}
void F_60 ( struct V_75 * V_76 , struct V_13 * V_14 )
{
struct V_2 * V_3 ;
F_48 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( V_3 ) {
struct V_85 * V_86 = F_45 ( V_76 ) ;
if ( ( T_1 ) F_59 () - V_3 -> V_31 <= V_117 ) {
V_86 -> V_121 . V_122 = V_3 -> V_31 ;
V_86 -> V_121 . V_119 = V_3 -> V_30 ;
}
}
F_52 () ;
}
bool F_61 ( struct V_75 * V_76 )
{
struct V_13 * V_14 = F_44 ( V_76 ) ;
bool V_116 = false ;
if ( V_14 ) {
struct V_2 * V_3 ;
F_48 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( V_3 ) {
struct V_85 * V_86 = F_45 ( V_76 ) ;
if ( ( V_118 ) ( V_3 -> V_30 - V_86 -> V_121 . V_119 ) <= 0 ||
( ( T_1 ) F_59 () - V_3 -> V_31 > V_117 &&
V_3 -> V_31 <= ( T_1 ) V_86 -> V_121 . V_122 ) ) {
V_3 -> V_31 = ( T_1 ) V_86 -> V_121 . V_122 ;
V_3 -> V_30 = V_86 -> V_121 . V_119 ;
}
V_116 = true ;
}
F_52 () ;
}
return V_116 ;
}
bool F_62 ( struct V_68 * V_69 )
{
struct V_2 * V_3 ;
bool V_116 = false ;
F_48 () ;
V_3 = F_37 ( V_69 ) ;
if ( V_3 ) {
const struct V_123 * V_124 ;
struct V_75 * V_76 = (struct V_75 * ) V_69 ;
V_124 = F_63 ( V_76 ) ;
if ( ( V_118 ) ( V_3 -> V_30 - V_124 -> V_125 ) <= 0 ||
( ( T_1 ) F_59 () - V_3 -> V_31 > V_117 &&
V_3 -> V_31 <= ( T_1 ) V_124 -> V_126 ) ) {
V_3 -> V_31 = ( T_1 ) V_124 -> V_126 ;
V_3 -> V_30 = V_124 -> V_125 ;
}
V_116 = true ;
}
F_52 () ;
return V_116 ;
}
void F_64 ( struct V_75 * V_76 , T_2 * V_33 ,
struct V_127 * V_36 ,
int * V_34 , unsigned long * V_128 )
{
struct V_2 * V_3 ;
F_48 () ;
V_3 = F_40 ( V_76 , F_44 ( V_76 ) , false ) ;
if ( V_3 ) {
struct V_129 * V_130 = & V_3 -> V_32 ;
unsigned int V_131 ;
do {
V_131 = F_65 ( & V_132 ) ;
if ( V_130 -> V_33 )
* V_33 = V_130 -> V_33 ;
* V_36 = V_130 -> V_36 ;
if ( V_36 -> V_37 <= 0 && V_130 -> V_35 == 1 )
V_36 -> exp = true ;
* V_34 = V_130 -> V_34 ;
* V_128 = * V_34 ? V_130 -> V_128 : 0 ;
} while ( F_66 ( & V_132 , V_131 ) );
}
F_52 () ;
}
void F_67 ( struct V_75 * V_76 , T_2 V_33 ,
struct V_127 * V_36 , bool V_133 ,
T_2 V_35 )
{
struct V_13 * V_14 = F_44 ( V_76 ) ;
struct V_2 * V_3 ;
if ( ! V_14 )
return;
F_48 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( V_3 ) {
struct V_129 * V_130 = & V_3 -> V_32 ;
F_68 ( & V_132 ) ;
if ( V_33 )
V_130 -> V_33 = V_33 ;
if ( V_36 && V_36 -> V_37 > 0 )
V_130 -> V_36 = * V_36 ;
else if ( V_35 > V_130 -> V_35 &&
V_130 -> V_36 . V_37 <= 0 && ! V_130 -> V_36 . exp )
V_130 -> V_35 = V_35 ;
if ( V_133 ) {
++ V_130 -> V_34 ;
V_130 -> V_128 = V_18 ;
} else
V_130 -> V_34 = 0 ;
F_69 ( & V_132 ) ;
}
F_52 () ;
}
static int F_70 ( struct V_134 * V_135 ,
struct V_2 * V_3 )
{
struct V_136 * V_137 ;
int V_138 ;
switch ( V_3 -> V_53 . V_58 ) {
case V_60 :
if ( F_71 ( V_135 , V_139 ,
F_72 ( & V_3 -> V_53 ) ) < 0 )
goto V_140;
if ( F_71 ( V_135 , V_141 ,
F_72 ( & V_3 -> V_52 ) ) < 0 )
goto V_140;
break;
case V_64 :
if ( F_73 ( V_135 , V_142 ,
F_74 ( & V_3 -> V_53 ) ) < 0 )
goto V_140;
if ( F_73 ( V_135 , V_143 ,
F_74 ( & V_3 -> V_52 ) ) < 0 )
goto V_140;
break;
default:
return - V_144 ;
}
if ( F_75 ( V_135 , V_145 ,
V_18 - V_3 -> V_17 ,
V_146 ) < 0 )
goto V_140;
if ( V_3 -> V_31 ) {
if ( F_76 ( V_135 , V_147 ,
( V_118 ) ( F_59 () - V_3 -> V_31 ) ) < 0 )
goto V_140;
if ( F_77 ( V_135 , V_148 ,
V_3 -> V_30 ) < 0 )
goto V_140;
}
{
int V_149 = 0 ;
V_137 = F_78 ( V_135 , V_150 ) ;
if ( ! V_137 )
goto V_140;
for ( V_138 = 0 ; V_138 < V_151 + 1 ; V_138 ++ ) {
T_1 V_9 = V_3 -> V_8 [ V_138 ] ;
if ( ! V_9 )
continue;
if ( V_138 == V_20 ) {
if ( F_77 ( V_135 , V_152 + 1 ,
V_9 ) < 0 )
goto V_140;
V_149 ++ ;
V_9 = F_51 ( V_9 / 1000 , 1U ) ;
}
if ( V_138 == V_22 ) {
if ( F_77 ( V_135 , V_153 + 1 ,
V_9 ) < 0 )
goto V_140;
V_149 ++ ;
V_9 = F_51 ( V_9 / 1000 , 1U ) ;
}
if ( F_77 ( V_135 , V_138 + 1 , V_9 ) < 0 )
goto V_140;
V_149 ++ ;
}
if ( V_149 )
F_79 ( V_135 , V_137 ) ;
else
F_80 ( V_135 , V_137 ) ;
}
{
struct V_129 V_154 [ 1 ] , * V_130 ;
unsigned int V_131 ;
do {
V_131 = F_65 ( & V_132 ) ;
V_154 [ 0 ] = V_3 -> V_32 ;
} while ( F_66 ( & V_132 , V_131 ) );
V_130 = V_154 ;
if ( V_130 -> V_33 &&
F_81 ( V_135 , V_155 ,
V_130 -> V_33 ) < 0 )
goto V_140;
if ( V_130 -> V_34 &&
( F_81 ( V_135 , V_156 ,
V_130 -> V_34 ) < 0 ||
F_75 ( V_135 , V_157 ,
V_18 - V_130 -> V_128 ,
V_146 ) < 0 ) )
goto V_140;
if ( V_130 -> V_36 . V_37 > 0 &&
F_82 ( V_135 , V_158 ,
V_130 -> V_36 . V_37 , V_130 -> V_36 . V_9 ) < 0 )
goto V_140;
}
return 0 ;
V_140:
return - V_159 ;
}
static int F_83 ( struct V_134 * V_160 ,
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
goto V_140;
F_86 ( V_160 , V_163 ) ;
return 0 ;
V_140:
F_87 ( V_160 , V_163 ) ;
return - V_159 ;
}
static int F_88 ( struct V_134 * V_160 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_46 ( V_160 -> V_76 ) ;
unsigned int V_170 = 1U << V_67 ;
unsigned int V_171 , V_172 = V_162 -> args [ 0 ] ;
int V_173 = V_162 -> args [ 1 ] , V_174 = V_173 ;
for ( V_171 = V_172 ; V_171 < V_170 ; V_171 ++ , V_173 = 0 ) {
struct V_2 * V_3 ;
struct V_175 * V_176 = V_48 + V_171 ;
F_48 () ;
for ( V_174 = 0 , V_3 = F_26 ( V_176 -> V_49 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_50 ) , V_174 ++ ) {
if ( ! F_27 ( F_1 ( V_3 ) , V_1 ) )
continue;
if ( V_174 < V_173 )
continue;
if ( F_83 ( V_160 , V_162 , V_3 ) < 0 ) {
F_52 () ;
goto V_177;
}
}
F_52 () ;
}
V_177:
V_162 -> args [ 0 ] = V_171 ;
V_162 -> args [ 1 ] = V_174 ;
return V_160 -> V_37 ;
}
static int F_89 ( struct V_178 * V_179 , struct V_10 * V_180 ,
unsigned int * V_41 , int V_181 , int V_182 , int V_183 )
{
struct V_136 * V_11 ;
V_11 = V_179 -> V_184 [ V_182 ] ;
if ( V_11 ) {
F_29 ( V_180 , F_90 ( V_11 ) ) ;
if ( V_41 )
* V_41 = F_31 ( F_72 ( V_180 ) ) ;
return 0 ;
}
V_11 = V_179 -> V_184 [ V_183 ] ;
if ( V_11 ) {
struct V_185 V_186 ;
if ( F_91 ( V_11 ) != sizeof( struct V_185 ) )
return - V_187 ;
V_186 = F_92 ( V_11 ) ;
F_33 ( V_180 , & V_186 ) ;
if ( V_41 )
* V_41 = F_34 ( F_74 ( V_180 ) ) ;
return 0 ;
}
return V_181 ? 1 : - V_144 ;
}
static int F_93 ( struct V_178 * V_179 , struct V_10 * V_180 ,
unsigned int * V_41 , int V_181 )
{
return F_89 ( V_179 , V_180 , V_41 , V_181 ,
V_139 ,
V_142 ) ;
}
static int F_94 ( struct V_178 * V_179 , struct V_10 * V_180 )
{
return F_89 ( V_179 , V_180 , NULL , 0 ,
V_141 ,
V_143 ) ;
}
static int F_95 ( struct V_134 * V_160 , struct V_178 * V_179 )
{
struct V_2 * V_3 ;
struct V_10 V_39 , V_40 ;
unsigned int V_41 ;
struct V_134 * V_135 ;
struct V_1 * V_1 = F_96 ( V_179 ) ;
void * V_188 ;
int V_116 ;
bool V_189 = true ;
V_116 = F_93 ( V_179 , & V_40 , & V_41 , 0 ) ;
if ( V_116 < 0 )
return V_116 ;
V_116 = F_94 ( V_179 , & V_39 ) ;
if ( V_116 < 0 )
V_189 = false ;
V_135 = F_97 ( V_190 , V_191 ) ;
if ( ! V_135 )
return - V_192 ;
V_188 = F_98 ( V_135 , V_179 , & V_167 , 0 ,
V_179 -> V_193 -> V_194 ) ;
if ( ! V_188 )
goto V_140;
V_41 ^= F_35 ( V_1 ) ;
V_41 = F_36 ( V_41 , V_67 ) ;
V_116 = - V_195 ;
F_48 () ;
for ( V_3 = F_26 ( V_48 [ V_41 ] . V_49 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_50 ) ) {
if ( F_6 ( & V_3 -> V_53 , & V_40 ) &&
( ! V_189 || F_6 ( & V_3 -> V_52 , & V_39 ) ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) ) {
V_116 = F_70 ( V_135 , V_3 ) ;
break;
}
}
F_52 () ;
if ( V_116 < 0 )
goto V_196;
F_86 ( V_135 , V_188 ) ;
return F_99 ( V_135 , V_179 ) ;
V_140:
V_116 = - V_159 ;
V_196:
F_100 ( V_135 ) ;
return V_116 ;
}
static void F_101 ( struct V_1 * V_1 )
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
F_102 ( V_3 , V_198 ) ;
} else {
V_197 = & V_3 -> V_50 ;
}
}
F_24 ( & V_43 ) ;
}
}
static int F_103 ( struct V_134 * V_160 , struct V_178 * V_179 )
{
struct V_175 * V_176 ;
struct V_2 * V_3 ;
struct V_2 T_3 * * V_197 ;
struct V_10 V_39 , V_40 ;
unsigned int V_41 ;
struct V_1 * V_1 = F_96 ( V_179 ) ;
int V_116 ;
bool V_189 = true , V_199 = false ;
V_116 = F_93 ( V_179 , & V_40 , & V_41 , 1 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( V_116 > 0 ) {
F_101 ( V_1 ) ;
return 0 ;
}
V_116 = F_94 ( V_179 , & V_39 ) ;
if ( V_116 < 0 )
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
F_102 ( V_3 , V_198 ) ;
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
static int T_4 F_104 ( char * V_200 )
{
T_5 V_116 ;
if ( ! V_200 )
return 0 ;
V_116 = F_105 ( V_200 , 0 , & V_201 ) ;
if ( V_116 )
return 0 ;
return 1 ;
}
static int T_6 F_106 ( struct V_1 * V_1 )
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
V_67 = F_107 ( V_203 ) ;
V_202 = sizeof( struct V_175 ) << V_67 ;
V_48 = F_108 ( V_202 , V_191 | V_206 ) ;
if ( ! V_48 )
V_48 = F_109 ( V_202 ) ;
if ( ! V_48 )
return - V_192 ;
return 0 ;
}
static void T_8 F_110 ( struct V_1 * V_1 )
{
F_101 ( V_1 ) ;
}
void T_4 F_111 ( void )
{
int V_116 ;
V_116 = F_112 ( & V_207 ) ;
if ( V_116 < 0 )
F_113 ( L_1 ) ;
V_116 = F_114 ( & V_167 ) ;
if ( V_116 < 0 )
F_113 ( L_2 ) ;
}
