static bool F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return V_2 -> V_5 & ( 1 << V_4 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return V_2 -> V_6 [ V_4 ] ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_4 ( V_2 -> V_6 [ V_4 ] ) ;
}
static void F_5 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
T_1 V_7 )
{
V_2 -> V_6 [ V_4 ] = V_7 ;
}
static void F_6 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
T_1 V_7 )
{
V_2 -> V_6 [ V_4 ] = F_7 ( V_7 ) ;
}
static bool F_8 ( const struct V_8 * V_9 ,
const struct V_8 * V_10 )
{
const struct V_11 * V_12 , * V_13 ;
if ( V_9 -> V_14 != V_10 -> V_14 )
return false ;
if ( V_9 -> V_14 == V_15 )
return V_9 -> V_16 . V_17 == V_10 -> V_16 . V_17 ;
V_12 = ( const struct V_11 * ) & V_9 -> V_16 . V_12 [ 0 ] ;
V_13 = ( const struct V_11 * ) & V_10 -> V_16 . V_12 [ 0 ] ;
return F_9 ( V_12 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_18 * V_19 ,
bool V_20 )
{
T_1 V_7 ;
V_2 -> V_21 = V_22 ;
V_7 = 0 ;
if ( F_11 ( V_19 , V_23 ) )
V_7 |= 1 << V_24 ;
if ( F_11 ( V_19 , V_25 ) )
V_7 |= 1 << V_26 ;
if ( F_11 ( V_19 , V_27 ) )
V_7 |= 1 << V_28 ;
if ( F_11 ( V_19 , V_29 ) )
V_7 |= 1 << V_30 ;
if ( F_11 ( V_19 , V_31 ) )
V_7 |= 1 << V_32 ;
V_2 -> V_5 = V_7 ;
V_2 -> V_6 [ V_24 ] = F_12 ( V_19 , V_23 ) ;
V_2 -> V_6 [ V_26 ] = F_12 ( V_19 , V_25 ) ;
V_2 -> V_6 [ V_28 ] = F_12 ( V_19 , V_27 ) ;
V_2 -> V_6 [ V_30 ] = F_12 ( V_19 , V_29 ) ;
V_2 -> V_6 [ V_32 ] = F_12 ( V_19 , V_31 ) ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = 0 ;
if ( V_20 ) {
V_2 -> V_35 . V_36 = 0 ;
V_2 -> V_35 . V_37 = 0 ;
V_2 -> V_35 . V_38 . V_39 = 0 ;
}
}
static void F_13 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
if ( V_2 && F_14 ( F_15 ( V_22 , V_2 -> V_21 + V_40 ) ) )
F_10 ( V_2 , V_19 , false ) ;
}
static struct V_1 * F_16 ( struct V_18 * V_19 ,
struct V_8 * V_41 ,
struct V_8 * V_42 ,
unsigned int V_43 )
{
struct V_1 * V_2 ;
struct V_44 * V_44 ;
bool V_45 = false ;
F_17 ( & V_46 ) ;
V_44 = F_18 ( V_19 -> V_47 ) ;
V_2 = F_19 ( V_41 , V_42 , V_44 , V_43 ) ;
if ( V_2 == V_48 ) {
V_45 = true ;
V_2 = NULL ;
}
if ( V_2 ) {
F_13 ( V_2 , V_19 ) ;
goto V_49;
}
if ( F_14 ( V_45 ) ) {
struct V_1 * V_50 ;
V_50 = F_20 ( V_44 -> V_51 . V_52 [ V_43 ] . V_53 ) ;
for ( V_2 = F_20 ( V_50 -> V_54 ) ; V_2 ;
V_2 = F_20 ( V_2 -> V_54 ) ) {
if ( F_21 ( V_2 -> V_21 , V_50 -> V_21 ) )
V_50 = V_2 ;
}
V_2 = V_50 ;
} else {
V_2 = F_22 ( sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
goto V_49;
}
V_2 -> V_56 = * V_41 ;
V_2 -> V_57 = * V_42 ;
F_10 ( V_2 , V_19 , true ) ;
if ( F_23 ( ! V_45 ) ) {
V_2 -> V_54 = V_44 -> V_51 . V_52 [ V_43 ] . V_53 ;
F_24 ( V_44 -> V_51 . V_52 [ V_43 ] . V_53 , V_2 ) ;
}
V_49:
F_25 ( & V_46 ) ;
return V_2 ;
}
static struct V_1 * F_26 ( struct V_1 * V_2 , int V_58 )
{
if ( V_2 )
return V_2 ;
if ( V_58 > V_59 )
return V_48 ;
return NULL ;
}
static struct V_1 * F_19 ( const struct V_8 * V_41 ,
const struct V_8 * V_42 ,
struct V_44 * V_44 , unsigned int V_43 )
{
struct V_1 * V_2 ;
int V_58 = 0 ;
for ( V_2 = F_20 ( V_44 -> V_51 . V_52 [ V_43 ] . V_53 ) ; V_2 ;
V_2 = F_20 ( V_2 -> V_54 ) ) {
if ( F_8 ( & V_2 -> V_56 , V_41 ) &&
F_8 ( & V_2 -> V_57 , V_42 ) )
break;
V_58 ++ ;
}
return F_26 ( V_2 , V_58 ) ;
}
static struct V_1 * F_27 ( struct V_60 * V_61 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_8 V_41 , V_42 ;
unsigned int V_43 ;
struct V_44 * V_44 ;
V_41 . V_14 = V_61 -> V_62 -> V_14 ;
V_42 . V_14 = V_61 -> V_62 -> V_14 ;
switch ( V_42 . V_14 ) {
case V_15 :
V_41 . V_16 . V_17 = F_28 ( V_61 ) -> V_63 ;
V_42 . V_16 . V_17 = F_28 ( V_61 ) -> V_64 ;
V_43 = ( V_65 unsigned int ) V_42 . V_16 . V_17 ;
break;
#if F_29 ( V_66 )
case V_67 :
* (struct V_11 * ) V_41 . V_16 . V_12 = F_28 ( V_61 ) -> V_68 ;
* (struct V_11 * ) V_42 . V_16 . V_12 = F_28 ( V_61 ) -> V_69 ;
V_43 = F_30 ( & F_28 ( V_61 ) -> V_69 ) ;
break;
#endif
default:
return NULL ;
}
V_44 = F_18 ( V_19 -> V_47 ) ;
V_43 = F_31 ( V_43 , V_44 -> V_51 . V_70 ) ;
for ( V_2 = F_20 ( V_44 -> V_51 . V_52 [ V_43 ] . V_53 ) ; V_2 ;
V_2 = F_20 ( V_2 -> V_54 ) ) {
if ( F_8 ( & V_2 -> V_56 , & V_41 ) &&
F_8 ( & V_2 -> V_57 , & V_42 ) )
break;
}
F_13 ( V_2 , V_19 ) ;
return V_2 ;
}
static struct V_1 * F_32 ( struct V_71 * V_72 )
{
struct V_1 * V_2 ;
struct V_8 V_41 , V_42 ;
unsigned int V_43 ;
struct V_44 * V_44 ;
if ( V_72 -> V_73 == V_15 ) {
V_41 . V_14 = V_15 ;
V_41 . V_16 . V_17 = V_72 -> V_74 ;
V_42 . V_14 = V_15 ;
V_42 . V_16 . V_17 = V_72 -> V_75 ;
V_43 = ( V_65 unsigned int ) V_42 . V_16 . V_17 ;
}
#if F_29 ( V_66 )
else if ( V_72 -> V_73 == V_67 ) {
if ( F_33 ( & V_72 -> V_76 ) ) {
V_41 . V_14 = V_15 ;
V_41 . V_16 . V_17 = V_72 -> V_74 ;
V_42 . V_14 = V_15 ;
V_42 . V_16 . V_17 = V_72 -> V_75 ;
V_43 = ( V_65 unsigned int ) V_42 . V_16 . V_17 ;
} else {
V_41 . V_14 = V_67 ;
* (struct V_11 * ) V_41 . V_16 . V_12 = V_72 -> V_77 ;
V_42 . V_14 = V_67 ;
* (struct V_11 * ) V_42 . V_16 . V_12 = V_72 -> V_76 ;
V_43 = F_30 ( & V_72 -> V_76 ) ;
}
}
#endif
else
return NULL ;
V_44 = F_34 ( V_72 ) ;
V_43 = F_31 ( V_43 , V_44 -> V_51 . V_70 ) ;
for ( V_2 = F_20 ( V_44 -> V_51 . V_52 [ V_43 ] . V_53 ) ; V_2 ;
V_2 = F_20 ( V_2 -> V_54 ) ) {
if ( F_8 ( & V_2 -> V_56 , & V_41 ) &&
F_8 ( & V_2 -> V_57 , & V_42 ) )
break;
}
return V_2 ;
}
static struct V_1 * F_35 ( struct V_78 * V_79 ,
struct V_18 * V_19 ,
bool V_80 )
{
struct V_1 * V_2 ;
struct V_8 V_41 , V_42 ;
unsigned int V_43 ;
struct V_44 * V_44 ;
if ( V_79 -> V_81 == V_15 ) {
V_41 . V_14 = V_15 ;
V_41 . V_16 . V_17 = F_36 ( V_79 ) -> V_82 ;
V_42 . V_14 = V_15 ;
V_42 . V_16 . V_17 = F_36 ( V_79 ) -> V_83 ;
V_43 = ( V_65 unsigned int ) V_42 . V_16 . V_17 ;
}
#if F_29 ( V_66 )
else if ( V_79 -> V_81 == V_67 ) {
if ( F_33 ( & V_79 -> V_84 ) ) {
V_41 . V_14 = V_15 ;
V_41 . V_16 . V_17 = F_36 ( V_79 ) -> V_82 ;
V_42 . V_14 = V_15 ;
V_42 . V_16 . V_17 = F_36 ( V_79 ) -> V_83 ;
V_43 = ( V_65 unsigned int ) V_42 . V_16 . V_17 ;
} else {
V_41 . V_14 = V_67 ;
* (struct V_11 * ) V_41 . V_16 . V_12 = V_79 -> V_85 ;
V_42 . V_14 = V_67 ;
* (struct V_11 * ) V_42 . V_16 . V_12 = V_79 -> V_84 ;
V_43 = F_30 ( & V_79 -> V_84 ) ;
}
}
#endif
else
return NULL ;
V_44 = F_18 ( V_19 -> V_47 ) ;
V_43 = F_31 ( V_43 , V_44 -> V_51 . V_70 ) ;
V_2 = F_19 ( & V_41 , & V_42 , V_44 , V_43 ) ;
if ( V_2 == V_48 )
V_2 = NULL ;
if ( ! V_2 && V_80 )
V_2 = F_16 ( V_19 , & V_41 , & V_42 , V_43 ) ;
else
F_13 ( V_2 , V_19 ) ;
return V_2 ;
}
void F_37 ( struct V_78 * V_79 )
{
const struct V_86 * V_87 = F_38 ( V_79 ) ;
struct V_18 * V_19 = F_39 ( V_79 ) ;
struct V_88 * V_89 = F_40 ( V_79 ) ;
struct V_1 * V_2 ;
unsigned long V_90 ;
T_1 V_7 ;
int V_91 ;
if ( V_92 || ! V_19 )
return;
if ( V_19 -> V_93 & V_94 )
F_41 ( V_19 ) ;
F_42 () ;
if ( V_87 -> V_95 || ! V_89 -> V_96 ) {
V_2 = F_35 ( V_79 , V_19 , false ) ;
if ( V_2 && ! F_1 ( V_2 , V_24 ) )
F_5 ( V_2 , V_24 , 0 ) ;
goto V_49;
} else
V_2 = F_35 ( V_79 , V_19 , true ) ;
if ( ! V_2 )
goto V_49;
V_90 = F_3 ( V_2 , V_24 ) ;
V_91 = V_90 - V_89 -> V_96 ;
if ( ! F_1 ( V_2 , V_24 ) ) {
if ( V_91 <= 0 )
V_90 = V_89 -> V_96 ;
else
V_90 -= ( V_91 >> 3 ) ;
F_6 ( V_2 , V_24 , V_90 ) ;
}
if ( ! F_1 ( V_2 , V_26 ) ) {
unsigned long V_97 ;
if ( V_91 < 0 )
V_91 = - V_91 ;
V_91 >>= 1 ;
if ( V_91 < V_89 -> V_98 )
V_91 = V_89 -> V_98 ;
V_97 = F_3 ( V_2 , V_26 ) ;
if ( V_91 >= V_97 )
V_97 = V_91 ;
else
V_97 -= ( V_97 - V_91 ) >> 2 ;
F_6 ( V_2 , V_26 , V_97 ) ;
}
if ( F_43 ( V_89 ) ) {
if ( ! F_1 ( V_2 , V_28 ) ) {
V_7 = F_2 ( V_2 , V_28 ) ;
if ( V_7 && ( V_89 -> V_99 >> 1 ) > V_7 )
F_5 ( V_2 , V_28 ,
V_89 -> V_99 >> 1 ) ;
}
if ( ! F_1 ( V_2 , V_30 ) ) {
V_7 = F_2 ( V_2 , V_30 ) ;
if ( V_89 -> V_99 > V_7 )
F_5 ( V_2 , V_30 ,
V_89 -> V_99 ) ;
}
} else if ( V_89 -> V_99 > V_89 -> V_100 &&
V_87 -> V_101 == V_102 ) {
if ( ! F_1 ( V_2 , V_28 ) )
F_5 ( V_2 , V_28 ,
F_44 ( V_89 -> V_99 >> 1 , V_89 -> V_100 ) ) ;
if ( ! F_1 ( V_2 , V_30 ) ) {
V_7 = F_2 ( V_2 , V_30 ) ;
F_5 ( V_2 , V_30 , ( V_7 + V_89 -> V_99 ) >> 1 ) ;
}
} else {
if ( ! F_1 ( V_2 , V_30 ) ) {
V_7 = F_2 ( V_2 , V_30 ) ;
F_5 ( V_2 , V_30 ,
( V_7 + V_89 -> V_100 ) >> 1 ) ;
}
if ( ! F_1 ( V_2 , V_28 ) ) {
V_7 = F_2 ( V_2 , V_28 ) ;
if ( V_7 && V_89 -> V_100 > V_7 )
F_5 ( V_2 , V_28 ,
V_89 -> V_100 ) ;
}
if ( ! F_1 ( V_2 , V_32 ) ) {
V_7 = F_2 ( V_2 , V_32 ) ;
if ( V_7 < V_89 -> V_103 &&
V_89 -> V_103 != V_104 )
F_5 ( V_2 , V_32 ,
V_89 -> V_103 ) ;
}
}
V_2 -> V_21 = V_22 ;
V_49:
F_45 () ;
}
void F_46 ( struct V_78 * V_79 )
{
struct V_18 * V_19 = F_39 ( V_79 ) ;
struct V_88 * V_89 = F_40 ( V_79 ) ;
struct V_1 * V_2 ;
T_1 V_7 , V_105 = 0 ;
if ( V_19 == NULL )
goto V_106;
F_41 ( V_19 ) ;
F_42 () ;
V_2 = F_35 ( V_79 , V_19 , true ) ;
if ( ! V_2 ) {
F_45 () ;
goto V_106;
}
if ( F_1 ( V_2 , V_30 ) )
V_89 -> V_107 = F_2 ( V_2 , V_30 ) ;
V_7 = F_2 ( V_2 , V_28 ) ;
if ( V_7 ) {
V_89 -> V_100 = V_7 ;
if ( V_89 -> V_100 > V_89 -> V_107 )
V_89 -> V_100 = V_89 -> V_107 ;
} else {
V_89 -> V_100 = V_108 ;
}
V_7 = F_2 ( V_2 , V_32 ) ;
if ( V_7 && V_89 -> V_103 != V_7 ) {
F_47 ( V_89 ) ;
F_48 ( V_89 ) ;
V_89 -> V_103 = V_7 ;
}
V_105 = F_3 ( V_2 , V_24 ) ;
F_45 () ;
V_106:
if ( V_105 > V_89 -> V_96 ) {
V_105 >>= 3 ;
F_38 ( V_79 ) -> V_109 = V_105 + F_44 ( 2 * V_105 , F_49 ( V_79 ) ) ;
} else if ( V_89 -> V_96 == 0 ) {
V_89 -> V_98 = V_89 -> V_110 = V_89 -> V_111 = V_112 ;
F_38 ( V_79 ) -> V_109 = V_112 ;
}
if ( V_89 -> V_113 > 1 )
V_89 -> V_99 = 1 ;
else
V_89 -> V_99 = F_50 ( V_89 , V_19 ) ;
V_89 -> V_114 = V_115 ;
}
bool F_51 ( struct V_60 * V_61 , struct V_18 * V_19 , bool V_116 )
{
struct V_1 * V_2 ;
bool V_117 ;
if ( ! V_19 )
return false ;
F_42 () ;
V_2 = F_27 ( V_61 , V_19 ) ;
if ( V_116 ) {
if ( V_2 &&
( T_1 ) F_52 () - V_2 -> V_34 < V_118 &&
( V_119 ) ( V_2 -> V_33 - V_61 -> V_120 ) > V_121 )
V_117 = false ;
else
V_117 = true ;
} else {
if ( V_2 && F_2 ( V_2 , V_24 ) && V_2 -> V_34 )
V_117 = true ;
else
V_117 = false ;
}
F_45 () ;
return V_117 ;
}
void F_53 ( struct V_78 * V_79 , struct V_18 * V_19 )
{
struct V_1 * V_2 ;
F_42 () ;
V_2 = F_35 ( V_79 , V_19 , true ) ;
if ( V_2 ) {
struct V_88 * V_89 = F_40 ( V_79 ) ;
if ( ( T_1 ) F_52 () - V_2 -> V_34 <= V_118 ) {
V_89 -> V_122 . V_123 = V_2 -> V_34 ;
V_89 -> V_122 . V_120 = V_2 -> V_33 ;
}
}
F_45 () ;
}
bool F_54 ( struct V_78 * V_79 )
{
struct V_18 * V_19 = F_39 ( V_79 ) ;
bool V_117 = false ;
if ( V_19 ) {
struct V_1 * V_2 ;
F_42 () ;
V_2 = F_35 ( V_79 , V_19 , true ) ;
if ( V_2 ) {
struct V_88 * V_89 = F_40 ( V_79 ) ;
if ( ( V_119 ) ( V_2 -> V_33 - V_89 -> V_122 . V_120 ) <= 0 ||
( ( T_1 ) F_52 () - V_2 -> V_34 > V_118 &&
V_2 -> V_34 <= ( T_1 ) V_89 -> V_122 . V_123 ) ) {
V_2 -> V_34 = ( T_1 ) V_89 -> V_122 . V_123 ;
V_2 -> V_33 = V_89 -> V_122 . V_120 ;
}
V_117 = true ;
}
F_45 () ;
}
return V_117 ;
}
bool F_55 ( struct V_71 * V_72 )
{
struct V_1 * V_2 ;
bool V_117 = false ;
F_42 () ;
V_2 = F_32 ( V_72 ) ;
if ( V_2 ) {
const struct V_124 * V_125 ;
struct V_78 * V_79 = (struct V_78 * ) V_72 ;
V_125 = F_56 ( V_79 ) ;
if ( ( V_119 ) ( V_2 -> V_33 - V_125 -> V_126 ) <= 0 ||
( ( T_1 ) F_52 () - V_2 -> V_34 > V_118 &&
V_2 -> V_34 <= ( T_1 ) V_125 -> V_127 ) ) {
V_2 -> V_34 = ( T_1 ) V_125 -> V_127 ;
V_2 -> V_33 = V_125 -> V_126 ;
}
V_117 = true ;
}
F_45 () ;
return V_117 ;
}
void F_57 ( struct V_78 * V_79 , T_2 * V_36 ,
struct V_128 * V_38 ,
int * V_37 , unsigned long * V_129 )
{
struct V_1 * V_2 ;
F_42 () ;
V_2 = F_35 ( V_79 , F_39 ( V_79 ) , false ) ;
if ( V_2 ) {
struct V_130 * V_131 = & V_2 -> V_35 ;
unsigned int V_132 ;
do {
V_132 = F_58 ( & V_133 ) ;
if ( V_131 -> V_36 )
* V_36 = V_131 -> V_36 ;
* V_38 = V_131 -> V_38 ;
* V_37 = V_131 -> V_37 ;
* V_129 = * V_37 ? V_131 -> V_129 : 0 ;
} while ( F_59 ( & V_133 , V_132 ) );
}
F_45 () ;
}
void F_60 ( struct V_78 * V_79 , T_2 V_36 ,
struct V_128 * V_38 , bool V_134 )
{
struct V_18 * V_19 = F_39 ( V_79 ) ;
struct V_1 * V_2 ;
if ( ! V_19 )
return;
F_42 () ;
V_2 = F_35 ( V_79 , V_19 , true ) ;
if ( V_2 ) {
struct V_130 * V_131 = & V_2 -> V_35 ;
F_61 ( & V_133 ) ;
if ( V_36 )
V_131 -> V_36 = V_36 ;
if ( V_38 && V_38 -> V_39 > 0 )
V_131 -> V_38 = * V_38 ;
if ( V_134 ) {
++ V_131 -> V_37 ;
V_131 -> V_129 = V_22 ;
} else
V_131 -> V_37 = 0 ;
F_62 ( & V_133 ) ;
}
F_45 () ;
}
static int F_63 ( struct V_135 * V_136 ,
struct V_1 * V_2 )
{
struct V_137 * V_138 ;
int V_139 ;
switch ( V_2 -> V_57 . V_14 ) {
case V_15 :
if ( F_64 ( V_136 , V_140 ,
V_2 -> V_57 . V_16 . V_17 ) < 0 )
goto V_141;
if ( F_64 ( V_136 , V_142 ,
V_2 -> V_56 . V_16 . V_17 ) < 0 )
goto V_141;
break;
case V_67 :
if ( F_65 ( V_136 , V_143 , 16 ,
V_2 -> V_57 . V_16 . V_12 ) < 0 )
goto V_141;
if ( F_65 ( V_136 , V_144 , 16 ,
V_2 -> V_56 . V_16 . V_12 ) < 0 )
goto V_141;
break;
default:
return - V_145 ;
}
if ( F_66 ( V_136 , V_146 ,
V_22 - V_2 -> V_21 ) < 0 )
goto V_141;
if ( V_2 -> V_34 ) {
if ( F_67 ( V_136 , V_147 ,
( V_119 ) ( F_52 () - V_2 -> V_34 ) ) < 0 )
goto V_141;
if ( F_68 ( V_136 , V_148 ,
V_2 -> V_33 ) < 0 )
goto V_141;
}
{
int V_149 = 0 ;
V_138 = F_69 ( V_136 , V_150 ) ;
if ( ! V_138 )
goto V_141;
for ( V_139 = 0 ; V_139 < V_151 + 1 ; V_139 ++ ) {
if ( ! V_2 -> V_6 [ V_139 ] )
continue;
if ( F_68 ( V_136 , V_139 + 1 , V_2 -> V_6 [ V_139 ] ) < 0 )
goto V_141;
V_149 ++ ;
}
if ( V_149 )
F_70 ( V_136 , V_138 ) ;
else
F_71 ( V_136 , V_138 ) ;
}
{
struct V_130 V_152 [ 1 ] , * V_131 ;
unsigned int V_132 ;
do {
V_132 = F_58 ( & V_133 ) ;
V_152 [ 0 ] = V_2 -> V_35 ;
} while ( F_59 ( & V_133 , V_132 ) );
V_131 = V_152 ;
if ( V_131 -> V_36 &&
F_72 ( V_136 , V_153 ,
V_131 -> V_36 ) < 0 )
goto V_141;
if ( V_131 -> V_37 &&
( F_72 ( V_136 , V_154 ,
V_131 -> V_37 ) < 0 ||
F_66 ( V_136 , V_155 ,
V_22 - V_131 -> V_129 ) < 0 ) )
goto V_141;
if ( V_131 -> V_38 . V_39 > 0 &&
F_65 ( V_136 , V_156 ,
V_131 -> V_38 . V_39 , V_131 -> V_38 . V_7 ) < 0 )
goto V_141;
}
return 0 ;
V_141:
return - V_157 ;
}
static int F_73 ( struct V_135 * V_158 ,
struct V_159 * V_160 ,
struct V_1 * V_2 )
{
void * V_161 ;
V_161 = F_74 ( V_158 , F_75 ( V_160 -> V_158 ) . V_162 , V_160 -> V_163 -> V_164 ,
& V_165 , V_166 ,
V_167 ) ;
if ( ! V_161 )
return - V_157 ;
if ( F_63 ( V_158 , V_2 ) < 0 )
goto V_141;
return F_76 ( V_158 , V_161 ) ;
V_141:
F_77 ( V_158 , V_161 ) ;
return - V_157 ;
}
static int F_78 ( struct V_135 * V_158 ,
struct V_159 * V_160 )
{
struct V_44 * V_44 = F_79 ( V_158 -> V_79 ) ;
unsigned int V_168 = 1U << V_44 -> V_51 . V_70 ;
unsigned int V_169 , V_170 = V_160 -> args [ 0 ] ;
int V_171 = V_160 -> args [ 1 ] , V_172 = V_171 ;
for ( V_169 = V_170 ; V_169 < V_168 ; V_169 ++ , V_171 = 0 ) {
struct V_1 * V_2 ;
struct V_173 * V_174 = V_44 -> V_51 . V_52 + V_169 ;
F_42 () ;
for ( V_172 = 0 , V_2 = F_20 ( V_174 -> V_53 ) ; V_2 ;
V_2 = F_20 ( V_2 -> V_54 ) , V_172 ++ ) {
if ( V_172 < V_171 )
continue;
if ( F_73 ( V_158 , V_160 , V_2 ) < 0 ) {
F_45 () ;
goto V_175;
}
}
F_45 () ;
}
V_175:
V_160 -> args [ 0 ] = V_169 ;
V_160 -> args [ 1 ] = V_172 ;
return V_158 -> V_39 ;
}
static int F_80 ( struct V_176 * V_177 , struct V_8 * V_16 ,
unsigned int * V_43 , int V_178 , int V_179 , int V_180 )
{
struct V_137 * V_9 ;
V_9 = V_177 -> V_181 [ V_179 ] ;
if ( V_9 ) {
V_16 -> V_14 = V_15 ;
V_16 -> V_16 . V_17 = F_81 ( V_9 ) ;
if ( V_43 )
* V_43 = ( V_65 unsigned int ) V_16 -> V_16 . V_17 ;
return 0 ;
}
V_9 = V_177 -> V_181 [ V_180 ] ;
if ( V_9 ) {
if ( F_82 ( V_9 ) != sizeof( struct V_11 ) )
return - V_182 ;
V_16 -> V_14 = V_67 ;
memcpy ( V_16 -> V_16 . V_12 , F_83 ( V_9 ) , sizeof( V_16 -> V_16 . V_12 ) ) ;
if ( V_43 )
* V_43 = F_30 ( (struct V_11 * ) V_16 -> V_16 . V_12 ) ;
return 0 ;
}
return V_178 ? 1 : - V_145 ;
}
static int F_84 ( struct V_176 * V_177 , struct V_8 * V_16 ,
unsigned int * V_43 , int V_178 )
{
return F_80 ( V_177 , V_16 , V_43 , V_178 ,
V_140 ,
V_143 ) ;
}
static int F_85 ( struct V_176 * V_177 , struct V_8 * V_16 )
{
return F_80 ( V_177 , V_16 , NULL , 0 ,
V_142 ,
V_144 ) ;
}
static int F_86 ( struct V_135 * V_158 , struct V_176 * V_177 )
{
struct V_1 * V_2 ;
struct V_8 V_41 , V_42 ;
unsigned int V_43 ;
struct V_135 * V_136 ;
struct V_44 * V_44 = F_87 ( V_177 ) ;
void * V_183 ;
int V_117 ;
bool V_184 = true ;
V_117 = F_84 ( V_177 , & V_42 , & V_43 , 0 ) ;
if ( V_117 < 0 )
return V_117 ;
V_117 = F_85 ( V_177 , & V_41 ) ;
if ( V_117 < 0 )
V_184 = false ;
V_136 = F_88 ( V_185 , V_186 ) ;
if ( ! V_136 )
return - V_187 ;
V_183 = F_89 ( V_136 , V_177 , & V_165 , 0 ,
V_177 -> V_188 -> V_189 ) ;
if ( ! V_183 )
goto V_141;
V_43 = F_31 ( V_43 , V_44 -> V_51 . V_70 ) ;
V_117 = - V_190 ;
F_42 () ;
for ( V_2 = F_20 ( V_44 -> V_51 . V_52 [ V_43 ] . V_53 ) ; V_2 ;
V_2 = F_20 ( V_2 -> V_54 ) ) {
if ( F_8 ( & V_2 -> V_57 , & V_42 ) &&
( ! V_184 || F_8 ( & V_2 -> V_56 , & V_41 ) ) ) {
V_117 = F_63 ( V_136 , V_2 ) ;
break;
}
}
F_45 () ;
if ( V_117 < 0 )
goto V_191;
F_76 ( V_136 , V_183 ) ;
return F_90 ( V_136 , V_177 ) ;
V_141:
V_117 = - V_157 ;
V_191:
F_91 ( V_136 ) ;
return V_117 ;
}
static int F_92 ( struct V_44 * V_44 )
{
unsigned int V_168 = 1U << V_44 -> V_51 . V_70 ;
struct V_173 * V_174 = V_44 -> V_51 . V_52 ;
struct V_1 * V_2 ;
unsigned int V_169 ;
for ( V_169 = 0 ; V_169 < V_168 ; V_169 ++ , V_174 ++ ) {
F_17 ( & V_46 ) ;
V_2 = F_93 ( V_174 -> V_53 ) ;
if ( V_2 )
V_174 -> V_53 = NULL ;
F_25 ( & V_46 ) ;
while ( V_2 ) {
struct V_1 * V_192 ;
V_192 = F_94 ( V_2 -> V_54 ) ;
F_95 ( V_2 , V_193 ) ;
V_2 = V_192 ;
}
}
return 0 ;
}
static int F_96 ( struct V_135 * V_158 , struct V_176 * V_177 )
{
struct V_173 * V_174 ;
struct V_1 * V_2 ;
struct V_1 T_3 * * V_194 ;
struct V_8 V_41 , V_42 ;
unsigned int V_43 ;
struct V_44 * V_44 = F_87 ( V_177 ) ;
int V_117 ;
bool V_184 = true , V_195 = false ;
V_117 = F_84 ( V_177 , & V_42 , & V_43 , 1 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( V_117 > 0 )
return F_92 ( V_44 ) ;
V_117 = F_85 ( V_177 , & V_41 ) ;
if ( V_117 < 0 )
V_184 = false ;
V_43 = F_31 ( V_43 , V_44 -> V_51 . V_70 ) ;
V_174 = V_44 -> V_51 . V_52 + V_43 ;
V_194 = & V_174 -> V_53 ;
F_17 ( & V_46 ) ;
for ( V_2 = F_93 ( * V_194 ) ; V_2 ; V_2 = F_93 ( * V_194 ) ) {
if ( F_8 ( & V_2 -> V_57 , & V_42 ) &&
( ! V_184 || F_8 ( & V_2 -> V_56 , & V_41 ) ) ) {
* V_194 = V_2 -> V_54 ;
F_95 ( V_2 , V_193 ) ;
V_195 = true ;
} else {
V_194 = & V_2 -> V_54 ;
}
}
F_25 ( & V_46 ) ;
if ( ! V_195 )
return - V_190 ;
return 0 ;
}
static int T_4 F_97 ( char * V_196 )
{
T_5 V_117 ;
if ( ! V_196 )
return 0 ;
V_117 = F_98 ( V_196 , 0 , & V_197 ) ;
if ( V_117 )
return 0 ;
return 1 ;
}
static int T_6 F_99 ( struct V_44 * V_44 )
{
T_7 V_198 ;
unsigned int V_199 ;
V_199 = V_197 ;
if ( ! V_199 ) {
if ( V_200 >= 128 * 1024 )
V_199 = 16 * 1024 ;
else
V_199 = 8 * 1024 ;
}
V_44 -> V_51 . V_70 = F_100 ( V_199 ) ;
V_198 = sizeof( struct V_173 ) << V_44 -> V_51 . V_70 ;
V_44 -> V_51 . V_52 = F_101 ( V_198 , V_186 | V_201 ) ;
if ( ! V_44 -> V_51 . V_52 )
V_44 -> V_51 . V_52 = F_102 ( V_198 ) ;
if ( ! V_44 -> V_51 . V_52 )
return - V_187 ;
return 0 ;
}
static void T_8 F_103 ( struct V_44 * V_44 )
{
unsigned int V_139 ;
for ( V_139 = 0 ; V_139 < ( 1U << V_44 -> V_51 . V_70 ) ; V_139 ++ ) {
struct V_1 * V_2 , * V_192 ;
V_2 = F_104 ( V_44 -> V_51 . V_52 [ V_139 ] . V_53 , 1 ) ;
while ( V_2 ) {
V_192 = F_104 ( V_2 -> V_54 , 1 ) ;
F_105 ( V_2 ) ;
V_2 = V_192 ;
}
}
if ( F_106 ( V_44 -> V_51 . V_52 ) )
F_107 ( V_44 -> V_51 . V_52 ) ;
else
F_105 ( V_44 -> V_51 . V_52 ) ;
}
void T_4 F_108 ( void )
{
int V_117 ;
V_117 = F_109 ( & V_202 ) ;
if ( V_117 < 0 )
goto V_203;
V_117 = F_110 ( & V_165 ,
V_204 ) ;
if ( V_117 < 0 )
goto V_205;
return;
V_205:
F_111 ( & V_202 ) ;
V_203:
return;
}
