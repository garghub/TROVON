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
V_102 /= 8 * V_29 ;
F_43 ( V_76 ) -> V_106 = V_102 + F_50 ( 2 * V_102 , F_55 ( V_76 ) ) ;
} else if ( V_86 -> V_93 == 0 ) {
V_86 -> V_107 = F_56 ( V_108 ) ;
V_86 -> V_95 = V_86 -> V_109 = V_86 -> V_107 ;
F_43 ( V_76 ) -> V_106 = V_108 ;
}
if ( V_86 -> V_110 > 1 )
V_86 -> V_96 = 1 ;
else
V_86 -> V_96 = F_57 ( V_86 , V_14 ) ;
V_86 -> V_111 = V_112 ;
}
bool F_58 ( struct V_56 * V_57 , struct V_13 * V_14 ,
bool V_113 , bool V_114 )
{
struct V_2 * V_3 ;
bool V_115 ;
if ( ! V_14 )
return false ;
F_47 () ;
V_3 = F_28 ( V_57 , V_14 ) ;
if ( V_113 ) {
if ( V_3 &&
( T_1 ) F_59 () - V_3 -> V_31 < V_116 &&
( ( V_117 ) ( V_3 -> V_30 - V_57 -> V_118 ) > V_119 ||
! V_114 ) )
V_115 = false ;
else
V_115 = true ;
} else {
if ( V_3 && F_4 ( V_3 , V_20 ) && V_3 -> V_31 )
V_115 = true ;
else
V_115 = false ;
}
F_51 () ;
return V_115 ;
}
void F_60 ( struct V_75 * V_76 , struct V_13 * V_14 )
{
struct V_2 * V_3 ;
F_47 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( V_3 ) {
struct V_85 * V_86 = F_45 ( V_76 ) ;
if ( ( T_1 ) F_59 () - V_3 -> V_31 <= V_116 ) {
V_86 -> V_120 . V_121 = V_3 -> V_31 ;
V_86 -> V_120 . V_118 = V_3 -> V_30 ;
}
}
F_51 () ;
}
bool F_61 ( struct V_75 * V_76 )
{
struct V_13 * V_14 = F_44 ( V_76 ) ;
bool V_115 = false ;
if ( V_14 ) {
struct V_2 * V_3 ;
F_47 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( V_3 ) {
struct V_85 * V_86 = F_45 ( V_76 ) ;
if ( ( V_117 ) ( V_3 -> V_30 - V_86 -> V_120 . V_118 ) <= 0 ||
( ( T_1 ) F_59 () - V_3 -> V_31 > V_116 &&
V_3 -> V_31 <= ( T_1 ) V_86 -> V_120 . V_121 ) ) {
V_3 -> V_31 = ( T_1 ) V_86 -> V_120 . V_121 ;
V_3 -> V_30 = V_86 -> V_120 . V_118 ;
}
V_115 = true ;
}
F_51 () ;
}
return V_115 ;
}
bool F_62 ( struct V_68 * V_69 )
{
struct V_2 * V_3 ;
bool V_115 = false ;
F_47 () ;
V_3 = F_37 ( V_69 ) ;
if ( V_3 ) {
const struct V_122 * V_123 ;
struct V_75 * V_76 = (struct V_75 * ) V_69 ;
V_123 = F_63 ( V_76 ) ;
if ( ( V_117 ) ( V_3 -> V_30 - V_123 -> V_124 ) <= 0 ||
( ( T_1 ) F_59 () - V_3 -> V_31 > V_116 &&
V_3 -> V_31 <= ( T_1 ) V_123 -> V_125 ) ) {
V_3 -> V_31 = ( T_1 ) V_123 -> V_125 ;
V_3 -> V_30 = V_123 -> V_124 ;
}
V_115 = true ;
}
F_51 () ;
return V_115 ;
}
void F_64 ( struct V_75 * V_76 , T_2 * V_33 ,
struct V_126 * V_36 ,
int * V_34 , unsigned long * V_127 )
{
struct V_2 * V_3 ;
F_47 () ;
V_3 = F_40 ( V_76 , F_44 ( V_76 ) , false ) ;
if ( V_3 ) {
struct V_128 * V_129 = & V_3 -> V_32 ;
unsigned int V_130 ;
do {
V_130 = F_65 ( & V_131 ) ;
if ( V_129 -> V_33 )
* V_33 = V_129 -> V_33 ;
* V_36 = V_129 -> V_36 ;
if ( V_36 -> V_37 <= 0 && V_129 -> V_35 == 1 )
V_36 -> exp = true ;
* V_34 = V_129 -> V_34 ;
* V_127 = * V_34 ? V_129 -> V_127 : 0 ;
} while ( F_66 ( & V_131 , V_130 ) );
}
F_51 () ;
}
void F_67 ( struct V_75 * V_76 , T_2 V_33 ,
struct V_126 * V_36 , bool V_132 ,
T_2 V_35 )
{
struct V_13 * V_14 = F_44 ( V_76 ) ;
struct V_2 * V_3 ;
if ( ! V_14 )
return;
F_47 () ;
V_3 = F_40 ( V_76 , V_14 , true ) ;
if ( V_3 ) {
struct V_128 * V_129 = & V_3 -> V_32 ;
F_68 ( & V_131 ) ;
if ( V_33 )
V_129 -> V_33 = V_33 ;
if ( V_36 && V_36 -> V_37 > 0 )
V_129 -> V_36 = * V_36 ;
else if ( V_35 > V_129 -> V_35 &&
V_129 -> V_36 . V_37 <= 0 && ! V_129 -> V_36 . exp )
V_129 -> V_35 = V_35 ;
if ( V_132 ) {
++ V_129 -> V_34 ;
V_129 -> V_127 = V_18 ;
} else
V_129 -> V_34 = 0 ;
F_69 ( & V_131 ) ;
}
F_51 () ;
}
static int F_70 ( struct V_133 * V_134 ,
struct V_2 * V_3 )
{
struct V_135 * V_136 ;
int V_137 ;
switch ( V_3 -> V_53 . V_58 ) {
case V_60 :
if ( F_71 ( V_134 , V_138 ,
F_72 ( & V_3 -> V_53 ) ) < 0 )
goto V_139;
if ( F_71 ( V_134 , V_140 ,
F_72 ( & V_3 -> V_52 ) ) < 0 )
goto V_139;
break;
case V_64 :
if ( F_73 ( V_134 , V_141 ,
F_74 ( & V_3 -> V_53 ) ) < 0 )
goto V_139;
if ( F_73 ( V_134 , V_142 ,
F_74 ( & V_3 -> V_52 ) ) < 0 )
goto V_139;
break;
default:
return - V_143 ;
}
if ( F_75 ( V_134 , V_144 ,
V_18 - V_3 -> V_17 ) < 0 )
goto V_139;
if ( V_3 -> V_31 ) {
if ( F_76 ( V_134 , V_145 ,
( V_117 ) ( F_59 () - V_3 -> V_31 ) ) < 0 )
goto V_139;
if ( F_77 ( V_134 , V_146 ,
V_3 -> V_30 ) < 0 )
goto V_139;
}
{
int V_147 = 0 ;
V_136 = F_78 ( V_134 , V_148 ) ;
if ( ! V_136 )
goto V_139;
for ( V_137 = 0 ; V_137 < V_149 + 1 ; V_137 ++ ) {
T_1 V_9 = V_3 -> V_8 [ V_137 ] ;
if ( ! V_9 )
continue;
if ( V_137 == V_20 ) {
if ( F_77 ( V_134 , V_150 + 1 ,
V_9 ) < 0 )
goto V_139;
V_147 ++ ;
V_9 = F_50 ( V_9 / 1000 , 1U ) ;
}
if ( V_137 == V_22 ) {
if ( F_77 ( V_134 , V_151 + 1 ,
V_9 ) < 0 )
goto V_139;
V_147 ++ ;
V_9 = F_50 ( V_9 / 1000 , 1U ) ;
}
if ( F_77 ( V_134 , V_137 + 1 , V_9 ) < 0 )
goto V_139;
V_147 ++ ;
}
if ( V_147 )
F_79 ( V_134 , V_136 ) ;
else
F_80 ( V_134 , V_136 ) ;
}
{
struct V_128 V_152 [ 1 ] , * V_129 ;
unsigned int V_130 ;
do {
V_130 = F_65 ( & V_131 ) ;
V_152 [ 0 ] = V_3 -> V_32 ;
} while ( F_66 ( & V_131 , V_130 ) );
V_129 = V_152 ;
if ( V_129 -> V_33 &&
F_81 ( V_134 , V_153 ,
V_129 -> V_33 ) < 0 )
goto V_139;
if ( V_129 -> V_34 &&
( F_81 ( V_134 , V_154 ,
V_129 -> V_34 ) < 0 ||
F_75 ( V_134 , V_155 ,
V_18 - V_129 -> V_127 ) < 0 ) )
goto V_139;
if ( V_129 -> V_36 . V_37 > 0 &&
F_82 ( V_134 , V_156 ,
V_129 -> V_36 . V_37 , V_129 -> V_36 . V_9 ) < 0 )
goto V_139;
}
return 0 ;
V_139:
return - V_157 ;
}
static int F_83 ( struct V_133 * V_158 ,
struct V_159 * V_160 ,
struct V_2 * V_3 )
{
void * V_161 ;
V_161 = F_84 ( V_158 , F_85 ( V_160 -> V_158 ) . V_162 , V_160 -> V_163 -> V_164 ,
& V_165 , V_166 ,
V_167 ) ;
if ( ! V_161 )
return - V_157 ;
if ( F_70 ( V_158 , V_3 ) < 0 )
goto V_139;
F_86 ( V_158 , V_161 ) ;
return 0 ;
V_139:
F_87 ( V_158 , V_161 ) ;
return - V_157 ;
}
static int F_88 ( struct V_133 * V_158 ,
struct V_159 * V_160 )
{
struct V_1 * V_1 = F_89 ( V_158 -> V_76 ) ;
unsigned int V_168 = 1U << V_67 ;
unsigned int V_169 , V_170 = V_160 -> args [ 0 ] ;
int V_171 = V_160 -> args [ 1 ] , V_172 = V_171 ;
for ( V_169 = V_170 ; V_169 < V_168 ; V_169 ++ , V_171 = 0 ) {
struct V_2 * V_3 ;
struct V_173 * V_174 = V_48 + V_169 ;
F_47 () ;
for ( V_172 = 0 , V_3 = F_26 ( V_174 -> V_49 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_50 ) , V_172 ++ ) {
if ( ! F_27 ( F_1 ( V_3 ) , V_1 ) )
continue;
if ( V_172 < V_171 )
continue;
if ( F_83 ( V_158 , V_160 , V_3 ) < 0 ) {
F_51 () ;
goto V_175;
}
}
F_51 () ;
}
V_175:
V_160 -> args [ 0 ] = V_169 ;
V_160 -> args [ 1 ] = V_172 ;
return V_158 -> V_37 ;
}
static int F_90 ( struct V_176 * V_177 , struct V_10 * V_178 ,
unsigned int * V_41 , int V_179 , int V_180 , int V_181 )
{
struct V_135 * V_11 ;
V_11 = V_177 -> V_182 [ V_180 ] ;
if ( V_11 ) {
F_29 ( V_178 , F_91 ( V_11 ) ) ;
if ( V_41 )
* V_41 = F_31 ( F_72 ( V_178 ) ) ;
return 0 ;
}
V_11 = V_177 -> V_182 [ V_181 ] ;
if ( V_11 ) {
struct V_183 V_184 ;
if ( F_92 ( V_11 ) != sizeof( struct V_183 ) )
return - V_185 ;
V_184 = F_93 ( V_11 ) ;
F_33 ( V_178 , & V_184 ) ;
if ( V_41 )
* V_41 = F_34 ( F_74 ( V_178 ) ) ;
return 0 ;
}
return V_179 ? 1 : - V_143 ;
}
static int F_94 ( struct V_176 * V_177 , struct V_10 * V_178 ,
unsigned int * V_41 , int V_179 )
{
return F_90 ( V_177 , V_178 , V_41 , V_179 ,
V_138 ,
V_141 ) ;
}
static int F_95 ( struct V_176 * V_177 , struct V_10 * V_178 )
{
return F_90 ( V_177 , V_178 , NULL , 0 ,
V_140 ,
V_142 ) ;
}
static int F_96 ( struct V_133 * V_158 , struct V_176 * V_177 )
{
struct V_2 * V_3 ;
struct V_10 V_39 , V_40 ;
unsigned int V_41 ;
struct V_133 * V_134 ;
struct V_1 * V_1 = F_97 ( V_177 ) ;
void * V_186 ;
int V_115 ;
bool V_187 = true ;
V_115 = F_94 ( V_177 , & V_40 , & V_41 , 0 ) ;
if ( V_115 < 0 )
return V_115 ;
V_115 = F_95 ( V_177 , & V_39 ) ;
if ( V_115 < 0 )
V_187 = false ;
V_134 = F_98 ( V_188 , V_189 ) ;
if ( ! V_134 )
return - V_190 ;
V_186 = F_99 ( V_134 , V_177 , & V_165 , 0 ,
V_177 -> V_191 -> V_192 ) ;
if ( ! V_186 )
goto V_139;
V_41 ^= F_35 ( V_1 ) ;
V_41 = F_36 ( V_41 , V_67 ) ;
V_115 = - V_193 ;
F_47 () ;
for ( V_3 = F_26 ( V_48 [ V_41 ] . V_49 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_50 ) ) {
if ( F_6 ( & V_3 -> V_53 , & V_40 ) &&
( ! V_187 || F_6 ( & V_3 -> V_52 , & V_39 ) ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) ) {
V_115 = F_70 ( V_134 , V_3 ) ;
break;
}
}
F_51 () ;
if ( V_115 < 0 )
goto V_194;
F_86 ( V_134 , V_186 ) ;
return F_100 ( V_134 , V_177 ) ;
V_139:
V_115 = - V_157 ;
V_194:
F_101 ( V_134 ) ;
return V_115 ;
}
static void F_102 ( struct V_1 * V_1 )
{
unsigned int V_168 = 1U << V_67 ;
struct V_173 * V_174 = V_48 ;
struct V_2 * V_3 ;
unsigned int V_169 ;
for ( V_169 = 0 ; V_169 < V_168 ; V_169 ++ , V_174 ++ ) {
struct V_2 T_3 * * V_195 ;
F_15 ( & V_43 ) ;
V_195 = & V_174 -> V_49 ;
for ( V_3 = F_18 ( * V_195 ) ; V_3 ; V_3 = F_18 ( * V_195 ) ) {
if ( F_27 ( F_1 ( V_3 ) , V_1 ) ) {
* V_195 = V_3 -> V_50 ;
F_103 ( V_3 , V_196 ) ;
} else {
V_195 = & V_3 -> V_50 ;
}
}
F_24 ( & V_43 ) ;
}
}
static int F_104 ( struct V_133 * V_158 , struct V_176 * V_177 )
{
struct V_173 * V_174 ;
struct V_2 * V_3 ;
struct V_2 T_3 * * V_195 ;
struct V_10 V_39 , V_40 ;
unsigned int V_41 ;
struct V_1 * V_1 = F_97 ( V_177 ) ;
int V_115 ;
bool V_187 = true , V_197 = false ;
V_115 = F_94 ( V_177 , & V_40 , & V_41 , 1 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( V_115 > 0 ) {
F_102 ( V_1 ) ;
return 0 ;
}
V_115 = F_95 ( V_177 , & V_39 ) ;
if ( V_115 < 0 )
V_187 = false ;
V_41 ^= F_35 ( V_1 ) ;
V_41 = F_36 ( V_41 , V_67 ) ;
V_174 = V_48 + V_41 ;
V_195 = & V_174 -> V_49 ;
F_15 ( & V_43 ) ;
for ( V_3 = F_18 ( * V_195 ) ; V_3 ; V_3 = F_18 ( * V_195 ) ) {
if ( F_6 ( & V_3 -> V_53 , & V_40 ) &&
( ! V_187 || F_6 ( & V_3 -> V_52 , & V_39 ) ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) ) {
* V_195 = V_3 -> V_50 ;
F_103 ( V_3 , V_196 ) ;
V_197 = true ;
} else {
V_195 = & V_3 -> V_50 ;
}
}
F_24 ( & V_43 ) ;
if ( ! V_197 )
return - V_193 ;
return 0 ;
}
static int T_4 F_105 ( char * V_198 )
{
T_5 V_115 ;
if ( ! V_198 )
return 0 ;
V_115 = F_106 ( V_198 , 0 , & V_199 ) ;
if ( V_115 )
return 0 ;
return 1 ;
}
static int T_6 F_107 ( struct V_1 * V_1 )
{
T_7 V_200 ;
unsigned int V_201 ;
if ( ! F_27 ( V_1 , & V_202 ) )
return 0 ;
V_201 = V_199 ;
if ( ! V_201 ) {
if ( V_203 >= 128 * 1024 )
V_201 = 16 * 1024 ;
else
V_201 = 8 * 1024 ;
}
V_67 = F_108 ( V_201 ) ;
V_200 = sizeof( struct V_173 ) << V_67 ;
V_48 = F_109 ( V_200 , V_189 | V_204 ) ;
if ( ! V_48 )
V_48 = F_110 ( V_200 ) ;
if ( ! V_48 )
return - V_190 ;
return 0 ;
}
static void T_8 F_111 ( struct V_1 * V_1 )
{
F_102 ( V_1 ) ;
}
void T_4 F_112 ( void )
{
int V_115 ;
V_115 = F_113 ( & V_205 ) ;
if ( V_115 < 0 )
F_114 ( L_1 ) ;
V_115 = F_115 ( & V_165 ,
V_206 ) ;
if ( V_115 < 0 )
F_114 ( L_2 ) ;
}
