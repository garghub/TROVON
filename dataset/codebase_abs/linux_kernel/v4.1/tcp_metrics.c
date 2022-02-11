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
if ( V_11 -> V_13 != V_12 -> V_13 )
return false ;
if ( V_11 -> V_13 == V_14 )
return V_11 -> V_15 . V_16 == V_12 -> V_15 . V_16 ;
return F_7 ( & V_11 -> V_15 . V_17 , & V_12 -> V_15 . V_17 ) ;
}
static void F_8 ( struct V_2 * V_3 ,
const struct V_18 * V_19 ,
bool V_20 )
{
T_1 V_21 ;
T_1 V_9 ;
V_3 -> V_22 = V_23 ;
V_9 = 0 ;
if ( F_9 ( V_19 , V_24 ) )
V_9 |= 1 << V_25 ;
if ( F_9 ( V_19 , V_26 ) )
V_9 |= 1 << V_27 ;
if ( F_9 ( V_19 , V_28 ) )
V_9 |= 1 << V_29 ;
if ( F_9 ( V_19 , V_30 ) )
V_9 |= 1 << V_31 ;
if ( F_9 ( V_19 , V_32 ) )
V_9 |= 1 << V_33 ;
V_3 -> V_7 = V_9 ;
V_21 = F_10 ( V_19 , V_24 ) ;
V_3 -> V_8 [ V_25 ] = V_21 * V_34 ;
V_21 = F_10 ( V_19 , V_26 ) ;
V_3 -> V_8 [ V_27 ] = V_21 * V_34 ;
V_3 -> V_8 [ V_29 ] = F_10 ( V_19 , V_28 ) ;
V_3 -> V_8 [ V_31 ] = F_10 ( V_19 , V_30 ) ;
V_3 -> V_8 [ V_33 ] = F_10 ( V_19 , V_32 ) ;
V_3 -> V_35 = 0 ;
V_3 -> V_36 = 0 ;
if ( V_20 ) {
V_3 -> V_37 . V_38 = 0 ;
V_3 -> V_37 . V_39 = 0 ;
V_3 -> V_37 . V_40 = 0 ;
V_3 -> V_37 . V_41 . exp = false ;
V_3 -> V_37 . V_41 . V_42 = 0 ;
}
}
static void F_11 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
if ( V_3 && F_12 ( F_13 ( V_23 , V_3 -> V_22 + V_43 ) ) )
F_8 ( V_3 , V_19 , false ) ;
}
static struct V_2 * F_14 ( struct V_18 * V_19 ,
struct V_10 * V_44 ,
struct V_10 * V_45 ,
unsigned int V_46 )
{
struct V_2 * V_3 ;
struct V_1 * V_1 ;
bool V_47 = false ;
F_15 ( & V_48 ) ;
V_1 = F_16 ( V_19 -> V_49 ) ;
V_3 = F_17 ( V_44 , V_45 , V_1 , V_46 ) ;
if ( V_3 == V_50 ) {
V_47 = true ;
V_3 = NULL ;
}
if ( V_3 ) {
F_11 ( V_3 , V_19 ) ;
goto V_51;
}
if ( F_12 ( V_47 ) ) {
struct V_2 * V_52 ;
V_52 = F_18 ( V_53 [ V_46 ] . V_54 ) ;
for ( V_3 = F_18 ( V_52 -> V_55 ) ; V_3 ;
V_3 = F_18 ( V_3 -> V_55 ) ) {
if ( F_19 ( V_3 -> V_22 , V_52 -> V_22 ) )
V_52 = V_3 ;
}
V_3 = V_52 ;
} else {
V_3 = F_20 ( sizeof( * V_3 ) , V_56 ) ;
if ( ! V_3 )
goto V_51;
}
F_21 ( & V_3 -> V_4 , V_1 ) ;
V_3 -> V_57 = * V_44 ;
V_3 -> V_58 = * V_45 ;
F_8 ( V_3 , V_19 , true ) ;
if ( F_22 ( ! V_47 ) ) {
V_3 -> V_55 = V_53 [ V_46 ] . V_54 ;
F_23 ( V_53 [ V_46 ] . V_54 , V_3 ) ;
}
V_51:
F_24 ( & V_48 ) ;
return V_3 ;
}
static struct V_2 * F_25 ( struct V_2 * V_3 , int V_59 )
{
if ( V_3 )
return V_3 ;
if ( V_59 > V_60 )
return V_50 ;
return NULL ;
}
static struct V_2 * F_17 ( const struct V_10 * V_44 ,
const struct V_10 * V_45 ,
struct V_1 * V_1 , unsigned int V_46 )
{
struct V_2 * V_3 ;
int V_59 = 0 ;
for ( V_3 = F_26 ( V_53 [ V_46 ] . V_54 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_55 ) ) {
if ( F_6 ( & V_3 -> V_57 , V_44 ) &&
F_6 ( & V_3 -> V_58 , V_45 ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) )
break;
V_59 ++ ;
}
return F_25 ( V_3 , V_59 ) ;
}
static struct V_2 * F_28 ( struct V_61 * V_62 ,
struct V_18 * V_19 )
{
struct V_2 * V_3 ;
struct V_10 V_44 , V_45 ;
unsigned int V_46 ;
struct V_1 * V_1 ;
V_44 . V_13 = V_62 -> V_63 -> V_13 ;
V_45 . V_13 = V_62 -> V_63 -> V_13 ;
switch ( V_45 . V_13 ) {
case V_14 :
V_44 . V_15 . V_16 = F_29 ( V_62 ) -> V_64 ;
V_45 . V_15 . V_16 = F_29 ( V_62 ) -> V_65 ;
V_46 = ( V_66 unsigned int ) V_45 . V_15 . V_16 ;
break;
#if F_30 ( V_67 )
case V_68 :
V_44 . V_15 . V_17 = F_29 ( V_62 ) -> V_69 ;
V_45 . V_15 . V_17 = F_29 ( V_62 ) -> V_70 ;
V_46 = F_31 ( & F_29 ( V_62 ) -> V_70 ) ;
break;
#endif
default:
return NULL ;
}
V_1 = F_16 ( V_19 -> V_49 ) ;
V_46 ^= F_32 ( V_1 ) ;
V_46 = F_33 ( V_46 , V_71 ) ;
for ( V_3 = F_26 ( V_53 [ V_46 ] . V_54 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_55 ) ) {
if ( F_6 ( & V_3 -> V_57 , & V_44 ) &&
F_6 ( & V_3 -> V_58 , & V_45 ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) )
break;
}
F_11 ( V_3 , V_19 ) ;
return V_3 ;
}
static struct V_2 * F_34 ( struct V_72 * V_73 )
{
struct V_2 * V_3 ;
struct V_10 V_44 , V_45 ;
unsigned int V_46 ;
struct V_1 * V_1 ;
if ( V_73 -> V_74 == V_14 ) {
V_44 . V_13 = V_14 ;
V_44 . V_15 . V_16 = V_73 -> V_75 ;
V_45 . V_13 = V_14 ;
V_45 . V_15 . V_16 = V_73 -> V_76 ;
V_46 = ( V_66 unsigned int ) V_45 . V_15 . V_16 ;
}
#if F_30 ( V_67 )
else if ( V_73 -> V_74 == V_68 ) {
if ( F_35 ( & V_73 -> V_77 ) ) {
V_44 . V_13 = V_14 ;
V_44 . V_15 . V_16 = V_73 -> V_75 ;
V_45 . V_13 = V_14 ;
V_45 . V_15 . V_16 = V_73 -> V_76 ;
V_46 = ( V_66 unsigned int ) V_45 . V_15 . V_16 ;
} else {
V_44 . V_13 = V_68 ;
V_44 . V_15 . V_17 = V_73 -> V_78 ;
V_45 . V_13 = V_68 ;
V_45 . V_15 . V_17 = V_73 -> V_77 ;
V_46 = F_31 ( & V_73 -> V_77 ) ;
}
}
#endif
else
return NULL ;
V_1 = F_36 ( V_73 ) ;
V_46 ^= F_32 ( V_1 ) ;
V_46 = F_33 ( V_46 , V_71 ) ;
for ( V_3 = F_26 ( V_53 [ V_46 ] . V_54 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_55 ) ) {
if ( F_6 ( & V_3 -> V_57 , & V_44 ) &&
F_6 ( & V_3 -> V_58 , & V_45 ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) )
break;
}
return V_3 ;
}
static struct V_2 * F_37 ( struct V_79 * V_80 ,
struct V_18 * V_19 ,
bool V_81 )
{
struct V_2 * V_3 ;
struct V_10 V_44 , V_45 ;
unsigned int V_46 ;
struct V_1 * V_1 ;
if ( V_80 -> V_82 == V_14 ) {
V_44 . V_13 = V_14 ;
V_44 . V_15 . V_16 = F_38 ( V_80 ) -> V_83 ;
V_45 . V_13 = V_14 ;
V_45 . V_15 . V_16 = F_38 ( V_80 ) -> V_84 ;
V_46 = ( V_66 unsigned int ) V_45 . V_15 . V_16 ;
}
#if F_30 ( V_67 )
else if ( V_80 -> V_82 == V_68 ) {
if ( F_35 ( & V_80 -> V_85 ) ) {
V_44 . V_13 = V_14 ;
V_44 . V_15 . V_16 = F_38 ( V_80 ) -> V_83 ;
V_45 . V_13 = V_14 ;
V_45 . V_15 . V_16 = F_38 ( V_80 ) -> V_84 ;
V_46 = ( V_66 unsigned int ) V_45 . V_15 . V_16 ;
} else {
V_44 . V_13 = V_68 ;
V_44 . V_15 . V_17 = V_80 -> V_86 ;
V_45 . V_13 = V_68 ;
V_45 . V_15 . V_17 = V_80 -> V_85 ;
V_46 = F_31 ( & V_80 -> V_85 ) ;
}
}
#endif
else
return NULL ;
V_1 = F_16 ( V_19 -> V_49 ) ;
V_46 ^= F_32 ( V_1 ) ;
V_46 = F_33 ( V_46 , V_71 ) ;
V_3 = F_17 ( & V_44 , & V_45 , V_1 , V_46 ) ;
if ( V_3 == V_50 )
V_3 = NULL ;
if ( ! V_3 && V_81 )
V_3 = F_14 ( V_19 , & V_44 , & V_45 , V_46 ) ;
else
F_11 ( V_3 , V_19 ) ;
return V_3 ;
}
void F_39 ( struct V_79 * V_80 )
{
const struct V_87 * V_88 = F_40 ( V_80 ) ;
struct V_18 * V_19 = F_41 ( V_80 ) ;
struct V_89 * V_90 = F_42 ( V_80 ) ;
struct V_2 * V_3 ;
unsigned long V_91 ;
T_1 V_9 ;
int V_92 ;
if ( V_93 || ! V_19 )
return;
if ( V_19 -> V_94 & V_95 )
F_43 ( V_19 ) ;
F_44 () ;
if ( V_88 -> V_96 || ! V_90 -> V_97 ) {
V_3 = F_37 ( V_80 , V_19 , false ) ;
if ( V_3 && ! F_3 ( V_3 , V_25 ) )
F_5 ( V_3 , V_25 , 0 ) ;
goto V_51;
} else
V_3 = F_37 ( V_80 , V_19 , true ) ;
if ( ! V_3 )
goto V_51;
V_91 = F_4 ( V_3 , V_25 ) ;
V_92 = V_91 - V_90 -> V_97 ;
if ( ! F_3 ( V_3 , V_25 ) ) {
if ( V_92 <= 0 )
V_91 = V_90 -> V_97 ;
else
V_91 -= ( V_92 >> 3 ) ;
F_5 ( V_3 , V_25 , V_91 ) ;
}
if ( ! F_3 ( V_3 , V_27 ) ) {
unsigned long V_98 ;
if ( V_92 < 0 )
V_92 = - V_92 ;
V_92 >>= 1 ;
if ( V_92 < V_90 -> V_99 )
V_92 = V_90 -> V_99 ;
V_98 = F_4 ( V_3 , V_27 ) ;
if ( V_92 >= V_98 )
V_98 = V_92 ;
else
V_98 -= ( V_98 - V_92 ) >> 2 ;
F_5 ( V_3 , V_27 , V_98 ) ;
}
if ( F_45 ( V_90 ) ) {
if ( ! F_3 ( V_3 , V_29 ) ) {
V_9 = F_4 ( V_3 , V_29 ) ;
if ( V_9 && ( V_90 -> V_100 >> 1 ) > V_9 )
F_5 ( V_3 , V_29 ,
V_90 -> V_100 >> 1 ) ;
}
if ( ! F_3 ( V_3 , V_31 ) ) {
V_9 = F_4 ( V_3 , V_31 ) ;
if ( V_90 -> V_100 > V_9 )
F_5 ( V_3 , V_31 ,
V_90 -> V_100 ) ;
}
} else if ( V_90 -> V_100 > V_90 -> V_101 &&
V_88 -> V_102 == V_103 ) {
if ( ! F_3 ( V_3 , V_29 ) )
F_5 ( V_3 , V_29 ,
F_46 ( V_90 -> V_100 >> 1 , V_90 -> V_101 ) ) ;
if ( ! F_3 ( V_3 , V_31 ) ) {
V_9 = F_4 ( V_3 , V_31 ) ;
F_5 ( V_3 , V_31 , ( V_9 + V_90 -> V_100 ) >> 1 ) ;
}
} else {
if ( ! F_3 ( V_3 , V_31 ) ) {
V_9 = F_4 ( V_3 , V_31 ) ;
F_5 ( V_3 , V_31 ,
( V_9 + V_90 -> V_101 ) >> 1 ) ;
}
if ( ! F_3 ( V_3 , V_29 ) ) {
V_9 = F_4 ( V_3 , V_29 ) ;
if ( V_9 && V_90 -> V_101 > V_9 )
F_5 ( V_3 , V_29 ,
V_90 -> V_101 ) ;
}
if ( ! F_3 ( V_3 , V_33 ) ) {
V_9 = F_4 ( V_3 , V_33 ) ;
if ( V_9 < V_90 -> V_104 &&
V_90 -> V_104 != V_105 )
F_5 ( V_3 , V_33 ,
V_90 -> V_104 ) ;
}
}
V_3 -> V_22 = V_23 ;
V_51:
F_47 () ;
}
void F_48 ( struct V_79 * V_80 )
{
struct V_18 * V_19 = F_41 ( V_80 ) ;
struct V_89 * V_90 = F_42 ( V_80 ) ;
struct V_2 * V_3 ;
T_1 V_9 , V_106 = 0 ;
if ( ! V_19 )
goto V_107;
F_43 ( V_19 ) ;
F_44 () ;
V_3 = F_37 ( V_80 , V_19 , true ) ;
if ( ! V_3 ) {
F_47 () ;
goto V_107;
}
if ( F_3 ( V_3 , V_31 ) )
V_90 -> V_108 = F_4 ( V_3 , V_31 ) ;
V_9 = F_4 ( V_3 , V_29 ) ;
if ( V_9 ) {
V_90 -> V_101 = V_9 ;
if ( V_90 -> V_101 > V_90 -> V_108 )
V_90 -> V_101 = V_90 -> V_108 ;
} else {
V_90 -> V_101 = V_109 ;
}
V_9 = F_4 ( V_3 , V_33 ) ;
if ( V_9 && V_90 -> V_104 != V_9 ) {
F_49 ( V_90 ) ;
F_50 ( V_90 ) ;
V_90 -> V_104 = V_9 ;
}
V_106 = F_4 ( V_3 , V_25 ) ;
F_47 () ;
V_107:
if ( V_106 > V_90 -> V_97 ) {
V_106 /= 8 * V_34 ;
F_40 ( V_80 ) -> V_110 = V_106 + F_46 ( 2 * V_106 , F_51 ( V_80 ) ) ;
} else if ( V_90 -> V_97 == 0 ) {
V_90 -> V_111 = F_52 ( V_112 ) ;
V_90 -> V_99 = V_90 -> V_113 = V_90 -> V_111 ;
F_40 ( V_80 ) -> V_110 = V_112 ;
}
if ( V_90 -> V_114 > 1 )
V_90 -> V_100 = 1 ;
else
V_90 -> V_100 = F_53 ( V_90 , V_19 ) ;
V_90 -> V_115 = V_116 ;
}
bool F_54 ( struct V_61 * V_62 , struct V_18 * V_19 ,
bool V_117 , bool V_118 )
{
struct V_2 * V_3 ;
bool V_119 ;
if ( ! V_19 )
return false ;
F_44 () ;
V_3 = F_28 ( V_62 , V_19 ) ;
if ( V_117 ) {
if ( V_3 &&
( T_1 ) F_55 () - V_3 -> V_36 < V_120 &&
( ( V_121 ) ( V_3 -> V_35 - V_62 -> V_122 ) > V_123 ||
! V_118 ) )
V_119 = false ;
else
V_119 = true ;
} else {
if ( V_3 && F_4 ( V_3 , V_25 ) && V_3 -> V_36 )
V_119 = true ;
else
V_119 = false ;
}
F_47 () ;
return V_119 ;
}
void F_56 ( struct V_79 * V_80 , struct V_18 * V_19 )
{
struct V_2 * V_3 ;
F_44 () ;
V_3 = F_37 ( V_80 , V_19 , true ) ;
if ( V_3 ) {
struct V_89 * V_90 = F_42 ( V_80 ) ;
if ( ( T_1 ) F_55 () - V_3 -> V_36 <= V_120 ) {
V_90 -> V_124 . V_125 = V_3 -> V_36 ;
V_90 -> V_124 . V_122 = V_3 -> V_35 ;
}
}
F_47 () ;
}
bool F_57 ( struct V_79 * V_80 )
{
struct V_18 * V_19 = F_41 ( V_80 ) ;
bool V_119 = false ;
if ( V_19 ) {
struct V_2 * V_3 ;
F_44 () ;
V_3 = F_37 ( V_80 , V_19 , true ) ;
if ( V_3 ) {
struct V_89 * V_90 = F_42 ( V_80 ) ;
if ( ( V_121 ) ( V_3 -> V_35 - V_90 -> V_124 . V_122 ) <= 0 ||
( ( T_1 ) F_55 () - V_3 -> V_36 > V_120 &&
V_3 -> V_36 <= ( T_1 ) V_90 -> V_124 . V_125 ) ) {
V_3 -> V_36 = ( T_1 ) V_90 -> V_124 . V_125 ;
V_3 -> V_35 = V_90 -> V_124 . V_122 ;
}
V_119 = true ;
}
F_47 () ;
}
return V_119 ;
}
bool F_58 ( struct V_72 * V_73 )
{
struct V_2 * V_3 ;
bool V_119 = false ;
F_44 () ;
V_3 = F_34 ( V_73 ) ;
if ( V_3 ) {
const struct V_126 * V_127 ;
struct V_79 * V_80 = (struct V_79 * ) V_73 ;
V_127 = F_59 ( V_80 ) ;
if ( ( V_121 ) ( V_3 -> V_35 - V_127 -> V_128 ) <= 0 ||
( ( T_1 ) F_55 () - V_3 -> V_36 > V_120 &&
V_3 -> V_36 <= ( T_1 ) V_127 -> V_129 ) ) {
V_3 -> V_36 = ( T_1 ) V_127 -> V_129 ;
V_3 -> V_35 = V_127 -> V_128 ;
}
V_119 = true ;
}
F_47 () ;
return V_119 ;
}
void F_60 ( struct V_79 * V_80 , T_2 * V_38 ,
struct V_130 * V_41 ,
int * V_39 , unsigned long * V_131 )
{
struct V_2 * V_3 ;
F_44 () ;
V_3 = F_37 ( V_80 , F_41 ( V_80 ) , false ) ;
if ( V_3 ) {
struct V_132 * V_133 = & V_3 -> V_37 ;
unsigned int V_134 ;
do {
V_134 = F_61 ( & V_135 ) ;
if ( V_133 -> V_38 )
* V_38 = V_133 -> V_38 ;
* V_41 = V_133 -> V_41 ;
if ( V_41 -> V_42 <= 0 && V_133 -> V_40 == 1 )
V_41 -> exp = true ;
* V_39 = V_133 -> V_39 ;
* V_131 = * V_39 ? V_133 -> V_131 : 0 ;
} while ( F_62 ( & V_135 , V_134 ) );
}
F_47 () ;
}
void F_63 ( struct V_79 * V_80 , T_2 V_38 ,
struct V_130 * V_41 , bool V_136 ,
T_2 V_40 )
{
struct V_18 * V_19 = F_41 ( V_80 ) ;
struct V_2 * V_3 ;
if ( ! V_19 )
return;
F_44 () ;
V_3 = F_37 ( V_80 , V_19 , true ) ;
if ( V_3 ) {
struct V_132 * V_133 = & V_3 -> V_37 ;
F_64 ( & V_135 ) ;
if ( V_38 )
V_133 -> V_38 = V_38 ;
if ( V_41 && V_41 -> V_42 > 0 )
V_133 -> V_41 = * V_41 ;
else if ( V_40 > V_133 -> V_40 &&
V_133 -> V_41 . V_42 <= 0 && ! V_133 -> V_41 . exp )
V_133 -> V_40 = V_40 ;
if ( V_136 ) {
++ V_133 -> V_39 ;
V_133 -> V_131 = V_23 ;
} else
V_133 -> V_39 = 0 ;
F_65 ( & V_135 ) ;
}
F_47 () ;
}
static int F_66 ( struct V_137 * V_138 ,
struct V_2 * V_3 )
{
struct V_139 * V_140 ;
int V_141 ;
switch ( V_3 -> V_58 . V_13 ) {
case V_14 :
if ( F_67 ( V_138 , V_142 ,
V_3 -> V_58 . V_15 . V_16 ) < 0 )
goto V_143;
if ( F_67 ( V_138 , V_144 ,
V_3 -> V_57 . V_15 . V_16 ) < 0 )
goto V_143;
break;
case V_68 :
if ( F_68 ( V_138 , V_145 ,
& V_3 -> V_58 . V_15 . V_17 ) < 0 )
goto V_143;
if ( F_68 ( V_138 , V_146 ,
& V_3 -> V_57 . V_15 . V_17 ) < 0 )
goto V_143;
break;
default:
return - V_147 ;
}
if ( F_69 ( V_138 , V_148 ,
V_23 - V_3 -> V_22 ) < 0 )
goto V_143;
if ( V_3 -> V_36 ) {
if ( F_70 ( V_138 , V_149 ,
( V_121 ) ( F_55 () - V_3 -> V_36 ) ) < 0 )
goto V_143;
if ( F_71 ( V_138 , V_150 ,
V_3 -> V_35 ) < 0 )
goto V_143;
}
{
int V_151 = 0 ;
V_140 = F_72 ( V_138 , V_152 ) ;
if ( ! V_140 )
goto V_143;
for ( V_141 = 0 ; V_141 < V_153 + 1 ; V_141 ++ ) {
T_1 V_9 = V_3 -> V_8 [ V_141 ] ;
if ( ! V_9 )
continue;
if ( V_141 == V_25 ) {
if ( F_71 ( V_138 , V_154 + 1 ,
V_9 ) < 0 )
goto V_143;
V_151 ++ ;
V_9 = F_46 ( V_9 / 1000 , 1U ) ;
}
if ( V_141 == V_27 ) {
if ( F_71 ( V_138 , V_155 + 1 ,
V_9 ) < 0 )
goto V_143;
V_151 ++ ;
V_9 = F_46 ( V_9 / 1000 , 1U ) ;
}
if ( F_71 ( V_138 , V_141 + 1 , V_9 ) < 0 )
goto V_143;
V_151 ++ ;
}
if ( V_151 )
F_73 ( V_138 , V_140 ) ;
else
F_74 ( V_138 , V_140 ) ;
}
{
struct V_132 V_156 [ 1 ] , * V_133 ;
unsigned int V_134 ;
do {
V_134 = F_61 ( & V_135 ) ;
V_156 [ 0 ] = V_3 -> V_37 ;
} while ( F_62 ( & V_135 , V_134 ) );
V_133 = V_156 ;
if ( V_133 -> V_38 &&
F_75 ( V_138 , V_157 ,
V_133 -> V_38 ) < 0 )
goto V_143;
if ( V_133 -> V_39 &&
( F_75 ( V_138 , V_158 ,
V_133 -> V_39 ) < 0 ||
F_69 ( V_138 , V_159 ,
V_23 - V_133 -> V_131 ) < 0 ) )
goto V_143;
if ( V_133 -> V_41 . V_42 > 0 &&
F_76 ( V_138 , V_160 ,
V_133 -> V_41 . V_42 , V_133 -> V_41 . V_9 ) < 0 )
goto V_143;
}
return 0 ;
V_143:
return - V_161 ;
}
static int F_77 ( struct V_137 * V_162 ,
struct V_163 * V_164 ,
struct V_2 * V_3 )
{
void * V_165 ;
V_165 = F_78 ( V_162 , F_79 ( V_164 -> V_162 ) . V_166 , V_164 -> V_167 -> V_168 ,
& V_169 , V_170 ,
V_171 ) ;
if ( ! V_165 )
return - V_161 ;
if ( F_66 ( V_162 , V_3 ) < 0 )
goto V_143;
F_80 ( V_162 , V_165 ) ;
return 0 ;
V_143:
F_81 ( V_162 , V_165 ) ;
return - V_161 ;
}
static int F_82 ( struct V_137 * V_162 ,
struct V_163 * V_164 )
{
struct V_1 * V_1 = F_83 ( V_162 -> V_80 ) ;
unsigned int V_172 = 1U << V_71 ;
unsigned int V_173 , V_174 = V_164 -> args [ 0 ] ;
int V_175 = V_164 -> args [ 1 ] , V_176 = V_175 ;
for ( V_173 = V_174 ; V_173 < V_172 ; V_173 ++ , V_175 = 0 ) {
struct V_2 * V_3 ;
struct V_177 * V_178 = V_53 + V_173 ;
F_44 () ;
for ( V_176 = 0 , V_3 = F_26 ( V_178 -> V_54 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_55 ) , V_176 ++ ) {
if ( ! F_27 ( F_1 ( V_3 ) , V_1 ) )
continue;
if ( V_176 < V_175 )
continue;
if ( F_77 ( V_162 , V_164 , V_3 ) < 0 ) {
F_47 () ;
goto V_179;
}
}
F_47 () ;
}
V_179:
V_164 -> args [ 0 ] = V_173 ;
V_164 -> args [ 1 ] = V_176 ;
return V_162 -> V_42 ;
}
static int F_84 ( struct V_180 * V_181 , struct V_10 * V_15 ,
unsigned int * V_46 , int V_182 , int V_183 , int V_184 )
{
struct V_139 * V_11 ;
V_11 = V_181 -> V_185 [ V_183 ] ;
if ( V_11 ) {
V_15 -> V_13 = V_14 ;
V_15 -> V_15 . V_16 = F_85 ( V_11 ) ;
if ( V_46 )
* V_46 = ( V_66 unsigned int ) V_15 -> V_15 . V_16 ;
return 0 ;
}
V_11 = V_181 -> V_185 [ V_184 ] ;
if ( V_11 ) {
if ( F_86 ( V_11 ) != sizeof( struct V_186 ) )
return - V_187 ;
V_15 -> V_13 = V_68 ;
V_15 -> V_15 . V_17 = F_87 ( V_11 ) ;
if ( V_46 )
* V_46 = F_31 ( & V_15 -> V_15 . V_17 ) ;
return 0 ;
}
return V_182 ? 1 : - V_147 ;
}
static int F_88 ( struct V_180 * V_181 , struct V_10 * V_15 ,
unsigned int * V_46 , int V_182 )
{
return F_84 ( V_181 , V_15 , V_46 , V_182 ,
V_142 ,
V_145 ) ;
}
static int F_89 ( struct V_180 * V_181 , struct V_10 * V_15 )
{
return F_84 ( V_181 , V_15 , NULL , 0 ,
V_144 ,
V_146 ) ;
}
static int F_90 ( struct V_137 * V_162 , struct V_180 * V_181 )
{
struct V_2 * V_3 ;
struct V_10 V_44 , V_45 ;
unsigned int V_46 ;
struct V_137 * V_138 ;
struct V_1 * V_1 = F_91 ( V_181 ) ;
void * V_188 ;
int V_119 ;
bool V_189 = true ;
V_119 = F_88 ( V_181 , & V_45 , & V_46 , 0 ) ;
if ( V_119 < 0 )
return V_119 ;
V_119 = F_89 ( V_181 , & V_44 ) ;
if ( V_119 < 0 )
V_189 = false ;
V_138 = F_92 ( V_190 , V_191 ) ;
if ( ! V_138 )
return - V_192 ;
V_188 = F_93 ( V_138 , V_181 , & V_169 , 0 ,
V_181 -> V_193 -> V_194 ) ;
if ( ! V_188 )
goto V_143;
V_46 ^= F_32 ( V_1 ) ;
V_46 = F_33 ( V_46 , V_71 ) ;
V_119 = - V_195 ;
F_44 () ;
for ( V_3 = F_26 ( V_53 [ V_46 ] . V_54 ) ; V_3 ;
V_3 = F_26 ( V_3 -> V_55 ) ) {
if ( F_6 ( & V_3 -> V_58 , & V_45 ) &&
( ! V_189 || F_6 ( & V_3 -> V_57 , & V_44 ) ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) ) {
V_119 = F_66 ( V_138 , V_3 ) ;
break;
}
}
F_47 () ;
if ( V_119 < 0 )
goto V_196;
F_80 ( V_138 , V_188 ) ;
return F_94 ( V_138 , V_181 ) ;
V_143:
V_119 = - V_161 ;
V_196:
F_95 ( V_138 ) ;
return V_119 ;
}
static void F_96 ( struct V_1 * V_1 )
{
unsigned int V_172 = 1U << V_71 ;
struct V_177 * V_178 = V_53 ;
struct V_2 * V_3 ;
unsigned int V_173 ;
for ( V_173 = 0 ; V_173 < V_172 ; V_173 ++ , V_178 ++ ) {
struct V_2 T_3 * * V_197 ;
F_15 ( & V_48 ) ;
V_197 = & V_178 -> V_54 ;
for ( V_3 = F_18 ( * V_197 ) ; V_3 ; V_3 = F_18 ( * V_197 ) ) {
if ( F_27 ( F_1 ( V_3 ) , V_1 ) ) {
* V_197 = V_3 -> V_55 ;
F_97 ( V_3 , V_198 ) ;
} else {
V_197 = & V_3 -> V_55 ;
}
}
F_24 ( & V_48 ) ;
}
}
static int F_98 ( struct V_137 * V_162 , struct V_180 * V_181 )
{
struct V_177 * V_178 ;
struct V_2 * V_3 ;
struct V_2 T_3 * * V_197 ;
struct V_10 V_44 , V_45 ;
unsigned int V_46 ;
struct V_1 * V_1 = F_91 ( V_181 ) ;
int V_119 ;
bool V_189 = true , V_199 = false ;
V_119 = F_88 ( V_181 , & V_45 , & V_46 , 1 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( V_119 > 0 ) {
F_96 ( V_1 ) ;
return 0 ;
}
V_119 = F_89 ( V_181 , & V_44 ) ;
if ( V_119 < 0 )
V_189 = false ;
V_46 ^= F_32 ( V_1 ) ;
V_46 = F_33 ( V_46 , V_71 ) ;
V_178 = V_53 + V_46 ;
V_197 = & V_178 -> V_54 ;
F_15 ( & V_48 ) ;
for ( V_3 = F_18 ( * V_197 ) ; V_3 ; V_3 = F_18 ( * V_197 ) ) {
if ( F_6 ( & V_3 -> V_58 , & V_45 ) &&
( ! V_189 || F_6 ( & V_3 -> V_57 , & V_44 ) ) &&
F_27 ( F_1 ( V_3 ) , V_1 ) ) {
* V_197 = V_3 -> V_55 ;
F_97 ( V_3 , V_198 ) ;
V_199 = true ;
} else {
V_197 = & V_3 -> V_55 ;
}
}
F_24 ( & V_48 ) ;
if ( ! V_199 )
return - V_195 ;
return 0 ;
}
static int T_4 F_99 ( char * V_200 )
{
T_5 V_119 ;
if ( ! V_200 )
return 0 ;
V_119 = F_100 ( V_200 , 0 , & V_201 ) ;
if ( V_119 )
return 0 ;
return 1 ;
}
static int T_6 F_101 ( struct V_1 * V_1 )
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
V_71 = F_102 ( V_203 ) ;
V_202 = sizeof( struct V_177 ) << V_71 ;
V_53 = F_103 ( V_202 , V_191 | V_206 ) ;
if ( ! V_53 )
V_53 = F_104 ( V_202 ) ;
if ( ! V_53 )
return - V_192 ;
return 0 ;
}
static void T_8 F_105 ( struct V_1 * V_1 )
{
F_96 ( V_1 ) ;
}
void T_4 F_106 ( void )
{
int V_119 ;
V_119 = F_107 ( & V_207 ) ;
if ( V_119 < 0 )
F_108 ( L_1 ) ;
V_119 = F_109 ( & V_169 ,
V_208 ) ;
if ( V_119 < 0 )
F_108 ( L_2 ) ;
}
