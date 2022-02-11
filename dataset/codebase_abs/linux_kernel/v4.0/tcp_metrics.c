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
static void F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
T_1 V_7 )
{
V_2 -> V_6 [ V_4 ] = V_7 ;
}
static bool F_4 ( const struct V_8 * V_9 ,
const struct V_8 * V_10 )
{
const struct V_11 * V_12 , * V_13 ;
if ( V_9 -> V_14 != V_10 -> V_14 )
return false ;
if ( V_9 -> V_14 == V_15 )
return V_9 -> V_16 . V_17 == V_10 -> V_16 . V_17 ;
V_12 = ( const struct V_11 * ) & V_9 -> V_16 . V_12 [ 0 ] ;
V_13 = ( const struct V_11 * ) & V_10 -> V_16 . V_12 [ 0 ] ;
return F_5 ( V_12 , V_13 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
const struct V_18 * V_19 ,
bool V_20 )
{
T_1 V_21 ;
T_1 V_7 ;
V_2 -> V_22 = V_23 ;
V_7 = 0 ;
if ( F_7 ( V_19 , V_24 ) )
V_7 |= 1 << V_25 ;
if ( F_7 ( V_19 , V_26 ) )
V_7 |= 1 << V_27 ;
if ( F_7 ( V_19 , V_28 ) )
V_7 |= 1 << V_29 ;
if ( F_7 ( V_19 , V_30 ) )
V_7 |= 1 << V_31 ;
if ( F_7 ( V_19 , V_32 ) )
V_7 |= 1 << V_33 ;
V_2 -> V_5 = V_7 ;
V_21 = F_8 ( V_19 , V_24 ) ;
V_2 -> V_6 [ V_25 ] = V_21 * V_34 ;
V_21 = F_8 ( V_19 , V_26 ) ;
V_2 -> V_6 [ V_27 ] = V_21 * V_34 ;
V_2 -> V_6 [ V_29 ] = F_8 ( V_19 , V_28 ) ;
V_2 -> V_6 [ V_31 ] = F_8 ( V_19 , V_30 ) ;
V_2 -> V_6 [ V_33 ] = F_8 ( V_19 , V_32 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = 0 ;
if ( V_20 ) {
V_2 -> V_37 . V_38 = 0 ;
V_2 -> V_37 . V_39 = 0 ;
V_2 -> V_37 . V_40 . V_41 = 0 ;
}
}
static void F_9 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
if ( V_2 && F_10 ( F_11 ( V_23 , V_2 -> V_22 + V_42 ) ) )
F_6 ( V_2 , V_19 , false ) ;
}
static struct V_1 * F_12 ( struct V_18 * V_19 ,
struct V_8 * V_43 ,
struct V_8 * V_44 ,
unsigned int V_45 )
{
struct V_1 * V_2 ;
struct V_46 * V_46 ;
bool V_47 = false ;
F_13 ( & V_48 ) ;
V_46 = F_14 ( V_19 -> V_49 ) ;
V_2 = F_15 ( V_43 , V_44 , V_46 , V_45 ) ;
if ( V_2 == V_50 ) {
V_47 = true ;
V_2 = NULL ;
}
if ( V_2 ) {
F_9 ( V_2 , V_19 ) ;
goto V_51;
}
if ( F_10 ( V_47 ) ) {
struct V_1 * V_52 ;
V_52 = F_16 ( V_46 -> V_53 . V_54 [ V_45 ] . V_55 ) ;
for ( V_2 = F_16 ( V_52 -> V_56 ) ; V_2 ;
V_2 = F_16 ( V_2 -> V_56 ) ) {
if ( F_17 ( V_2 -> V_22 , V_52 -> V_22 ) )
V_52 = V_2 ;
}
V_2 = V_52 ;
} else {
V_2 = F_18 ( sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 )
goto V_51;
}
V_2 -> V_58 = * V_43 ;
V_2 -> V_59 = * V_44 ;
F_6 ( V_2 , V_19 , true ) ;
if ( F_19 ( ! V_47 ) ) {
V_2 -> V_56 = V_46 -> V_53 . V_54 [ V_45 ] . V_55 ;
F_20 ( V_46 -> V_53 . V_54 [ V_45 ] . V_55 , V_2 ) ;
}
V_51:
F_21 ( & V_48 ) ;
return V_2 ;
}
static struct V_1 * F_22 ( struct V_1 * V_2 , int V_60 )
{
if ( V_2 )
return V_2 ;
if ( V_60 > V_61 )
return V_50 ;
return NULL ;
}
static struct V_1 * F_15 ( const struct V_8 * V_43 ,
const struct V_8 * V_44 ,
struct V_46 * V_46 , unsigned int V_45 )
{
struct V_1 * V_2 ;
int V_60 = 0 ;
for ( V_2 = F_16 ( V_46 -> V_53 . V_54 [ V_45 ] . V_55 ) ; V_2 ;
V_2 = F_16 ( V_2 -> V_56 ) ) {
if ( F_4 ( & V_2 -> V_58 , V_43 ) &&
F_4 ( & V_2 -> V_59 , V_44 ) )
break;
V_60 ++ ;
}
return F_22 ( V_2 , V_60 ) ;
}
static struct V_1 * F_23 ( struct V_62 * V_63 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_8 V_43 , V_44 ;
unsigned int V_45 ;
struct V_46 * V_46 ;
V_43 . V_14 = V_63 -> V_64 -> V_14 ;
V_44 . V_14 = V_63 -> V_64 -> V_14 ;
switch ( V_44 . V_14 ) {
case V_15 :
V_43 . V_16 . V_17 = F_24 ( V_63 ) -> V_65 ;
V_44 . V_16 . V_17 = F_24 ( V_63 ) -> V_66 ;
V_45 = ( V_67 unsigned int ) V_44 . V_16 . V_17 ;
break;
#if F_25 ( V_68 )
case V_69 :
* (struct V_11 * ) V_43 . V_16 . V_12 = F_24 ( V_63 ) -> V_70 ;
* (struct V_11 * ) V_44 . V_16 . V_12 = F_24 ( V_63 ) -> V_71 ;
V_45 = F_26 ( & F_24 ( V_63 ) -> V_71 ) ;
break;
#endif
default:
return NULL ;
}
V_46 = F_14 ( V_19 -> V_49 ) ;
V_45 = F_27 ( V_45 , V_46 -> V_53 . V_72 ) ;
for ( V_2 = F_16 ( V_46 -> V_53 . V_54 [ V_45 ] . V_55 ) ; V_2 ;
V_2 = F_16 ( V_2 -> V_56 ) ) {
if ( F_4 ( & V_2 -> V_58 , & V_43 ) &&
F_4 ( & V_2 -> V_59 , & V_44 ) )
break;
}
F_9 ( V_2 , V_19 ) ;
return V_2 ;
}
static struct V_1 * F_28 ( struct V_73 * V_74 )
{
struct V_1 * V_2 ;
struct V_8 V_43 , V_44 ;
unsigned int V_45 ;
struct V_46 * V_46 ;
if ( V_74 -> V_75 == V_15 ) {
V_43 . V_14 = V_15 ;
V_43 . V_16 . V_17 = V_74 -> V_76 ;
V_44 . V_14 = V_15 ;
V_44 . V_16 . V_17 = V_74 -> V_77 ;
V_45 = ( V_67 unsigned int ) V_44 . V_16 . V_17 ;
}
#if F_25 ( V_68 )
else if ( V_74 -> V_75 == V_69 ) {
if ( F_29 ( & V_74 -> V_78 ) ) {
V_43 . V_14 = V_15 ;
V_43 . V_16 . V_17 = V_74 -> V_76 ;
V_44 . V_14 = V_15 ;
V_44 . V_16 . V_17 = V_74 -> V_77 ;
V_45 = ( V_67 unsigned int ) V_44 . V_16 . V_17 ;
} else {
V_43 . V_14 = V_69 ;
* (struct V_11 * ) V_43 . V_16 . V_12 = V_74 -> V_79 ;
V_44 . V_14 = V_69 ;
* (struct V_11 * ) V_44 . V_16 . V_12 = V_74 -> V_78 ;
V_45 = F_26 ( & V_74 -> V_78 ) ;
}
}
#endif
else
return NULL ;
V_46 = F_30 ( V_74 ) ;
V_45 = F_27 ( V_45 , V_46 -> V_53 . V_72 ) ;
for ( V_2 = F_16 ( V_46 -> V_53 . V_54 [ V_45 ] . V_55 ) ; V_2 ;
V_2 = F_16 ( V_2 -> V_56 ) ) {
if ( F_4 ( & V_2 -> V_58 , & V_43 ) &&
F_4 ( & V_2 -> V_59 , & V_44 ) )
break;
}
return V_2 ;
}
static struct V_1 * F_31 ( struct V_80 * V_81 ,
struct V_18 * V_19 ,
bool V_82 )
{
struct V_1 * V_2 ;
struct V_8 V_43 , V_44 ;
unsigned int V_45 ;
struct V_46 * V_46 ;
if ( V_81 -> V_83 == V_15 ) {
V_43 . V_14 = V_15 ;
V_43 . V_16 . V_17 = F_32 ( V_81 ) -> V_84 ;
V_44 . V_14 = V_15 ;
V_44 . V_16 . V_17 = F_32 ( V_81 ) -> V_85 ;
V_45 = ( V_67 unsigned int ) V_44 . V_16 . V_17 ;
}
#if F_25 ( V_68 )
else if ( V_81 -> V_83 == V_69 ) {
if ( F_29 ( & V_81 -> V_86 ) ) {
V_43 . V_14 = V_15 ;
V_43 . V_16 . V_17 = F_32 ( V_81 ) -> V_84 ;
V_44 . V_14 = V_15 ;
V_44 . V_16 . V_17 = F_32 ( V_81 ) -> V_85 ;
V_45 = ( V_67 unsigned int ) V_44 . V_16 . V_17 ;
} else {
V_43 . V_14 = V_69 ;
* (struct V_11 * ) V_43 . V_16 . V_12 = V_81 -> V_87 ;
V_44 . V_14 = V_69 ;
* (struct V_11 * ) V_44 . V_16 . V_12 = V_81 -> V_86 ;
V_45 = F_26 ( & V_81 -> V_86 ) ;
}
}
#endif
else
return NULL ;
V_46 = F_14 ( V_19 -> V_49 ) ;
V_45 = F_27 ( V_45 , V_46 -> V_53 . V_72 ) ;
V_2 = F_15 ( & V_43 , & V_44 , V_46 , V_45 ) ;
if ( V_2 == V_50 )
V_2 = NULL ;
if ( ! V_2 && V_82 )
V_2 = F_12 ( V_19 , & V_43 , & V_44 , V_45 ) ;
else
F_9 ( V_2 , V_19 ) ;
return V_2 ;
}
void F_33 ( struct V_80 * V_81 )
{
const struct V_88 * V_89 = F_34 ( V_81 ) ;
struct V_18 * V_19 = F_35 ( V_81 ) ;
struct V_90 * V_91 = F_36 ( V_81 ) ;
struct V_1 * V_2 ;
unsigned long V_92 ;
T_1 V_7 ;
int V_93 ;
if ( V_94 || ! V_19 )
return;
if ( V_19 -> V_95 & V_96 )
F_37 ( V_19 ) ;
F_38 () ;
if ( V_89 -> V_97 || ! V_91 -> V_98 ) {
V_2 = F_31 ( V_81 , V_19 , false ) ;
if ( V_2 && ! F_1 ( V_2 , V_25 ) )
F_3 ( V_2 , V_25 , 0 ) ;
goto V_51;
} else
V_2 = F_31 ( V_81 , V_19 , true ) ;
if ( ! V_2 )
goto V_51;
V_92 = F_2 ( V_2 , V_25 ) ;
V_93 = V_92 - V_91 -> V_98 ;
if ( ! F_1 ( V_2 , V_25 ) ) {
if ( V_93 <= 0 )
V_92 = V_91 -> V_98 ;
else
V_92 -= ( V_93 >> 3 ) ;
F_3 ( V_2 , V_25 , V_92 ) ;
}
if ( ! F_1 ( V_2 , V_27 ) ) {
unsigned long V_99 ;
if ( V_93 < 0 )
V_93 = - V_93 ;
V_93 >>= 1 ;
if ( V_93 < V_91 -> V_100 )
V_93 = V_91 -> V_100 ;
V_99 = F_2 ( V_2 , V_27 ) ;
if ( V_93 >= V_99 )
V_99 = V_93 ;
else
V_99 -= ( V_99 - V_93 ) >> 2 ;
F_3 ( V_2 , V_27 , V_99 ) ;
}
if ( F_39 ( V_91 ) ) {
if ( ! F_1 ( V_2 , V_29 ) ) {
V_7 = F_2 ( V_2 , V_29 ) ;
if ( V_7 && ( V_91 -> V_101 >> 1 ) > V_7 )
F_3 ( V_2 , V_29 ,
V_91 -> V_101 >> 1 ) ;
}
if ( ! F_1 ( V_2 , V_31 ) ) {
V_7 = F_2 ( V_2 , V_31 ) ;
if ( V_91 -> V_101 > V_7 )
F_3 ( V_2 , V_31 ,
V_91 -> V_101 ) ;
}
} else if ( V_91 -> V_101 > V_91 -> V_102 &&
V_89 -> V_103 == V_104 ) {
if ( ! F_1 ( V_2 , V_29 ) )
F_3 ( V_2 , V_29 ,
F_40 ( V_91 -> V_101 >> 1 , V_91 -> V_102 ) ) ;
if ( ! F_1 ( V_2 , V_31 ) ) {
V_7 = F_2 ( V_2 , V_31 ) ;
F_3 ( V_2 , V_31 , ( V_7 + V_91 -> V_101 ) >> 1 ) ;
}
} else {
if ( ! F_1 ( V_2 , V_31 ) ) {
V_7 = F_2 ( V_2 , V_31 ) ;
F_3 ( V_2 , V_31 ,
( V_7 + V_91 -> V_102 ) >> 1 ) ;
}
if ( ! F_1 ( V_2 , V_29 ) ) {
V_7 = F_2 ( V_2 , V_29 ) ;
if ( V_7 && V_91 -> V_102 > V_7 )
F_3 ( V_2 , V_29 ,
V_91 -> V_102 ) ;
}
if ( ! F_1 ( V_2 , V_33 ) ) {
V_7 = F_2 ( V_2 , V_33 ) ;
if ( V_7 < V_91 -> V_105 &&
V_91 -> V_105 != V_106 )
F_3 ( V_2 , V_33 ,
V_91 -> V_105 ) ;
}
}
V_2 -> V_22 = V_23 ;
V_51:
F_41 () ;
}
void F_42 ( struct V_80 * V_81 )
{
struct V_18 * V_19 = F_35 ( V_81 ) ;
struct V_90 * V_91 = F_36 ( V_81 ) ;
struct V_1 * V_2 ;
T_1 V_7 , V_107 = 0 ;
if ( V_19 == NULL )
goto V_108;
F_37 ( V_19 ) ;
F_38 () ;
V_2 = F_31 ( V_81 , V_19 , true ) ;
if ( ! V_2 ) {
F_41 () ;
goto V_108;
}
if ( F_1 ( V_2 , V_31 ) )
V_91 -> V_109 = F_2 ( V_2 , V_31 ) ;
V_7 = F_2 ( V_2 , V_29 ) ;
if ( V_7 ) {
V_91 -> V_102 = V_7 ;
if ( V_91 -> V_102 > V_91 -> V_109 )
V_91 -> V_102 = V_91 -> V_109 ;
} else {
V_91 -> V_102 = V_110 ;
}
V_7 = F_2 ( V_2 , V_33 ) ;
if ( V_7 && V_91 -> V_105 != V_7 ) {
F_43 ( V_91 ) ;
F_44 ( V_91 ) ;
V_91 -> V_105 = V_7 ;
}
V_107 = F_2 ( V_2 , V_25 ) ;
F_41 () ;
V_108:
if ( V_107 > V_91 -> V_98 ) {
V_107 /= 8 * V_34 ;
F_34 ( V_81 ) -> V_111 = V_107 + F_40 ( 2 * V_107 , F_45 ( V_81 ) ) ;
} else if ( V_91 -> V_98 == 0 ) {
V_91 -> V_112 = F_46 ( V_113 ) ;
V_91 -> V_100 = V_91 -> V_114 = V_91 -> V_112 ;
F_34 ( V_81 ) -> V_111 = V_113 ;
}
if ( V_91 -> V_115 > 1 )
V_91 -> V_101 = 1 ;
else
V_91 -> V_101 = F_47 ( V_91 , V_19 ) ;
V_91 -> V_116 = V_117 ;
}
bool F_48 ( struct V_62 * V_63 , struct V_18 * V_19 ,
bool V_118 , bool V_119 )
{
struct V_1 * V_2 ;
bool V_120 ;
if ( ! V_19 )
return false ;
F_38 () ;
V_2 = F_23 ( V_63 , V_19 ) ;
if ( V_118 ) {
if ( V_2 &&
( T_1 ) F_49 () - V_2 -> V_36 < V_121 &&
( ( V_122 ) ( V_2 -> V_35 - V_63 -> V_123 ) > V_124 ||
! V_119 ) )
V_120 = false ;
else
V_120 = true ;
} else {
if ( V_2 && F_2 ( V_2 , V_25 ) && V_2 -> V_36 )
V_120 = true ;
else
V_120 = false ;
}
F_41 () ;
return V_120 ;
}
void F_50 ( struct V_80 * V_81 , struct V_18 * V_19 )
{
struct V_1 * V_2 ;
F_38 () ;
V_2 = F_31 ( V_81 , V_19 , true ) ;
if ( V_2 ) {
struct V_90 * V_91 = F_36 ( V_81 ) ;
if ( ( T_1 ) F_49 () - V_2 -> V_36 <= V_121 ) {
V_91 -> V_125 . V_126 = V_2 -> V_36 ;
V_91 -> V_125 . V_123 = V_2 -> V_35 ;
}
}
F_41 () ;
}
bool F_51 ( struct V_80 * V_81 )
{
struct V_18 * V_19 = F_35 ( V_81 ) ;
bool V_120 = false ;
if ( V_19 ) {
struct V_1 * V_2 ;
F_38 () ;
V_2 = F_31 ( V_81 , V_19 , true ) ;
if ( V_2 ) {
struct V_90 * V_91 = F_36 ( V_81 ) ;
if ( ( V_122 ) ( V_2 -> V_35 - V_91 -> V_125 . V_123 ) <= 0 ||
( ( T_1 ) F_49 () - V_2 -> V_36 > V_121 &&
V_2 -> V_36 <= ( T_1 ) V_91 -> V_125 . V_126 ) ) {
V_2 -> V_36 = ( T_1 ) V_91 -> V_125 . V_126 ;
V_2 -> V_35 = V_91 -> V_125 . V_123 ;
}
V_120 = true ;
}
F_41 () ;
}
return V_120 ;
}
bool F_52 ( struct V_73 * V_74 )
{
struct V_1 * V_2 ;
bool V_120 = false ;
F_38 () ;
V_2 = F_28 ( V_74 ) ;
if ( V_2 ) {
const struct V_127 * V_128 ;
struct V_80 * V_81 = (struct V_80 * ) V_74 ;
V_128 = F_53 ( V_81 ) ;
if ( ( V_122 ) ( V_2 -> V_35 - V_128 -> V_129 ) <= 0 ||
( ( T_1 ) F_49 () - V_2 -> V_36 > V_121 &&
V_2 -> V_36 <= ( T_1 ) V_128 -> V_130 ) ) {
V_2 -> V_36 = ( T_1 ) V_128 -> V_130 ;
V_2 -> V_35 = V_128 -> V_129 ;
}
V_120 = true ;
}
F_41 () ;
return V_120 ;
}
void F_54 ( struct V_80 * V_81 , T_2 * V_38 ,
struct V_131 * V_40 ,
int * V_39 , unsigned long * V_132 )
{
struct V_1 * V_2 ;
F_38 () ;
V_2 = F_31 ( V_81 , F_35 ( V_81 ) , false ) ;
if ( V_2 ) {
struct V_133 * V_134 = & V_2 -> V_37 ;
unsigned int V_135 ;
do {
V_135 = F_55 ( & V_136 ) ;
if ( V_134 -> V_38 )
* V_38 = V_134 -> V_38 ;
* V_40 = V_134 -> V_40 ;
* V_39 = V_134 -> V_39 ;
* V_132 = * V_39 ? V_134 -> V_132 : 0 ;
} while ( F_56 ( & V_136 , V_135 ) );
}
F_41 () ;
}
void F_57 ( struct V_80 * V_81 , T_2 V_38 ,
struct V_131 * V_40 , bool V_137 )
{
struct V_18 * V_19 = F_35 ( V_81 ) ;
struct V_1 * V_2 ;
if ( ! V_19 )
return;
F_38 () ;
V_2 = F_31 ( V_81 , V_19 , true ) ;
if ( V_2 ) {
struct V_133 * V_134 = & V_2 -> V_37 ;
F_58 ( & V_136 ) ;
if ( V_38 )
V_134 -> V_38 = V_38 ;
if ( V_40 && V_40 -> V_41 > 0 )
V_134 -> V_40 = * V_40 ;
if ( V_137 ) {
++ V_134 -> V_39 ;
V_134 -> V_132 = V_23 ;
} else
V_134 -> V_39 = 0 ;
F_59 ( & V_136 ) ;
}
F_41 () ;
}
static int F_60 ( struct V_138 * V_139 ,
struct V_1 * V_2 )
{
struct V_140 * V_141 ;
int V_142 ;
switch ( V_2 -> V_59 . V_14 ) {
case V_15 :
if ( F_61 ( V_139 , V_143 ,
V_2 -> V_59 . V_16 . V_17 ) < 0 )
goto V_144;
if ( F_61 ( V_139 , V_145 ,
V_2 -> V_58 . V_16 . V_17 ) < 0 )
goto V_144;
break;
case V_69 :
if ( F_62 ( V_139 , V_146 , 16 ,
V_2 -> V_59 . V_16 . V_12 ) < 0 )
goto V_144;
if ( F_62 ( V_139 , V_147 , 16 ,
V_2 -> V_58 . V_16 . V_12 ) < 0 )
goto V_144;
break;
default:
return - V_148 ;
}
if ( F_63 ( V_139 , V_149 ,
V_23 - V_2 -> V_22 ) < 0 )
goto V_144;
if ( V_2 -> V_36 ) {
if ( F_64 ( V_139 , V_150 ,
( V_122 ) ( F_49 () - V_2 -> V_36 ) ) < 0 )
goto V_144;
if ( F_65 ( V_139 , V_151 ,
V_2 -> V_35 ) < 0 )
goto V_144;
}
{
int V_152 = 0 ;
V_141 = F_66 ( V_139 , V_153 ) ;
if ( ! V_141 )
goto V_144;
for ( V_142 = 0 ; V_142 < V_154 + 1 ; V_142 ++ ) {
T_1 V_7 = V_2 -> V_6 [ V_142 ] ;
if ( ! V_7 )
continue;
if ( V_142 == V_25 ) {
if ( F_65 ( V_139 , V_155 + 1 ,
V_7 ) < 0 )
goto V_144;
V_152 ++ ;
V_7 = F_40 ( V_7 / 1000 , 1U ) ;
}
if ( V_142 == V_27 ) {
if ( F_65 ( V_139 , V_156 + 1 ,
V_7 ) < 0 )
goto V_144;
V_152 ++ ;
V_7 = F_40 ( V_7 / 1000 , 1U ) ;
}
if ( F_65 ( V_139 , V_142 + 1 , V_7 ) < 0 )
goto V_144;
V_152 ++ ;
}
if ( V_152 )
F_67 ( V_139 , V_141 ) ;
else
F_68 ( V_139 , V_141 ) ;
}
{
struct V_133 V_157 [ 1 ] , * V_134 ;
unsigned int V_135 ;
do {
V_135 = F_55 ( & V_136 ) ;
V_157 [ 0 ] = V_2 -> V_37 ;
} while ( F_56 ( & V_136 , V_135 ) );
V_134 = V_157 ;
if ( V_134 -> V_38 &&
F_69 ( V_139 , V_158 ,
V_134 -> V_38 ) < 0 )
goto V_144;
if ( V_134 -> V_39 &&
( F_69 ( V_139 , V_159 ,
V_134 -> V_39 ) < 0 ||
F_63 ( V_139 , V_160 ,
V_23 - V_134 -> V_132 ) < 0 ) )
goto V_144;
if ( V_134 -> V_40 . V_41 > 0 &&
F_62 ( V_139 , V_161 ,
V_134 -> V_40 . V_41 , V_134 -> V_40 . V_7 ) < 0 )
goto V_144;
}
return 0 ;
V_144:
return - V_162 ;
}
static int F_70 ( struct V_138 * V_163 ,
struct V_164 * V_165 ,
struct V_1 * V_2 )
{
void * V_166 ;
V_166 = F_71 ( V_163 , F_72 ( V_165 -> V_163 ) . V_167 , V_165 -> V_168 -> V_169 ,
& V_170 , V_171 ,
V_172 ) ;
if ( ! V_166 )
return - V_162 ;
if ( F_60 ( V_163 , V_2 ) < 0 )
goto V_144;
F_73 ( V_163 , V_166 ) ;
return 0 ;
V_144:
F_74 ( V_163 , V_166 ) ;
return - V_162 ;
}
static int F_75 ( struct V_138 * V_163 ,
struct V_164 * V_165 )
{
struct V_46 * V_46 = F_76 ( V_163 -> V_81 ) ;
unsigned int V_173 = 1U << V_46 -> V_53 . V_72 ;
unsigned int V_174 , V_175 = V_165 -> args [ 0 ] ;
int V_176 = V_165 -> args [ 1 ] , V_177 = V_176 ;
for ( V_174 = V_175 ; V_174 < V_173 ; V_174 ++ , V_176 = 0 ) {
struct V_1 * V_2 ;
struct V_178 * V_179 = V_46 -> V_53 . V_54 + V_174 ;
F_38 () ;
for ( V_177 = 0 , V_2 = F_16 ( V_179 -> V_55 ) ; V_2 ;
V_2 = F_16 ( V_2 -> V_56 ) , V_177 ++ ) {
if ( V_177 < V_176 )
continue;
if ( F_70 ( V_163 , V_165 , V_2 ) < 0 ) {
F_41 () ;
goto V_180;
}
}
F_41 () ;
}
V_180:
V_165 -> args [ 0 ] = V_174 ;
V_165 -> args [ 1 ] = V_177 ;
return V_163 -> V_41 ;
}
static int F_77 ( struct V_181 * V_182 , struct V_8 * V_16 ,
unsigned int * V_45 , int V_183 , int V_184 , int V_185 )
{
struct V_140 * V_9 ;
V_9 = V_182 -> V_186 [ V_184 ] ;
if ( V_9 ) {
V_16 -> V_14 = V_15 ;
V_16 -> V_16 . V_17 = F_78 ( V_9 ) ;
if ( V_45 )
* V_45 = ( V_67 unsigned int ) V_16 -> V_16 . V_17 ;
return 0 ;
}
V_9 = V_182 -> V_186 [ V_185 ] ;
if ( V_9 ) {
if ( F_79 ( V_9 ) != sizeof( struct V_11 ) )
return - V_187 ;
V_16 -> V_14 = V_69 ;
memcpy ( V_16 -> V_16 . V_12 , F_80 ( V_9 ) , sizeof( V_16 -> V_16 . V_12 ) ) ;
if ( V_45 )
* V_45 = F_26 ( (struct V_11 * ) V_16 -> V_16 . V_12 ) ;
return 0 ;
}
return V_183 ? 1 : - V_148 ;
}
static int F_81 ( struct V_181 * V_182 , struct V_8 * V_16 ,
unsigned int * V_45 , int V_183 )
{
return F_77 ( V_182 , V_16 , V_45 , V_183 ,
V_143 ,
V_146 ) ;
}
static int F_82 ( struct V_181 * V_182 , struct V_8 * V_16 )
{
return F_77 ( V_182 , V_16 , NULL , 0 ,
V_145 ,
V_147 ) ;
}
static int F_83 ( struct V_138 * V_163 , struct V_181 * V_182 )
{
struct V_1 * V_2 ;
struct V_8 V_43 , V_44 ;
unsigned int V_45 ;
struct V_138 * V_139 ;
struct V_46 * V_46 = F_84 ( V_182 ) ;
void * V_188 ;
int V_120 ;
bool V_189 = true ;
V_120 = F_81 ( V_182 , & V_44 , & V_45 , 0 ) ;
if ( V_120 < 0 )
return V_120 ;
V_120 = F_82 ( V_182 , & V_43 ) ;
if ( V_120 < 0 )
V_189 = false ;
V_139 = F_85 ( V_190 , V_191 ) ;
if ( ! V_139 )
return - V_192 ;
V_188 = F_86 ( V_139 , V_182 , & V_170 , 0 ,
V_182 -> V_193 -> V_194 ) ;
if ( ! V_188 )
goto V_144;
V_45 = F_27 ( V_45 , V_46 -> V_53 . V_72 ) ;
V_120 = - V_195 ;
F_38 () ;
for ( V_2 = F_16 ( V_46 -> V_53 . V_54 [ V_45 ] . V_55 ) ; V_2 ;
V_2 = F_16 ( V_2 -> V_56 ) ) {
if ( F_4 ( & V_2 -> V_59 , & V_44 ) &&
( ! V_189 || F_4 ( & V_2 -> V_58 , & V_43 ) ) ) {
V_120 = F_60 ( V_139 , V_2 ) ;
break;
}
}
F_41 () ;
if ( V_120 < 0 )
goto V_196;
F_73 ( V_139 , V_188 ) ;
return F_87 ( V_139 , V_182 ) ;
V_144:
V_120 = - V_162 ;
V_196:
F_88 ( V_139 ) ;
return V_120 ;
}
static int F_89 ( struct V_46 * V_46 )
{
unsigned int V_173 = 1U << V_46 -> V_53 . V_72 ;
struct V_178 * V_179 = V_46 -> V_53 . V_54 ;
struct V_1 * V_2 ;
unsigned int V_174 ;
for ( V_174 = 0 ; V_174 < V_173 ; V_174 ++ , V_179 ++ ) {
F_13 ( & V_48 ) ;
V_2 = F_90 ( V_179 -> V_55 ) ;
if ( V_2 )
V_179 -> V_55 = NULL ;
F_21 ( & V_48 ) ;
while ( V_2 ) {
struct V_1 * V_197 ;
V_197 = F_91 ( V_2 -> V_56 ) ;
F_92 ( V_2 , V_198 ) ;
V_2 = V_197 ;
}
}
return 0 ;
}
static int F_93 ( struct V_138 * V_163 , struct V_181 * V_182 )
{
struct V_178 * V_179 ;
struct V_1 * V_2 ;
struct V_1 T_3 * * V_199 ;
struct V_8 V_43 , V_44 ;
unsigned int V_45 ;
struct V_46 * V_46 = F_84 ( V_182 ) ;
int V_120 ;
bool V_189 = true , V_200 = false ;
V_120 = F_81 ( V_182 , & V_44 , & V_45 , 1 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( V_120 > 0 )
return F_89 ( V_46 ) ;
V_120 = F_82 ( V_182 , & V_43 ) ;
if ( V_120 < 0 )
V_189 = false ;
V_45 = F_27 ( V_45 , V_46 -> V_53 . V_72 ) ;
V_179 = V_46 -> V_53 . V_54 + V_45 ;
V_199 = & V_179 -> V_55 ;
F_13 ( & V_48 ) ;
for ( V_2 = F_90 ( * V_199 ) ; V_2 ; V_2 = F_90 ( * V_199 ) ) {
if ( F_4 ( & V_2 -> V_59 , & V_44 ) &&
( ! V_189 || F_4 ( & V_2 -> V_58 , & V_43 ) ) ) {
* V_199 = V_2 -> V_56 ;
F_92 ( V_2 , V_198 ) ;
V_200 = true ;
} else {
V_199 = & V_2 -> V_56 ;
}
}
F_21 ( & V_48 ) ;
if ( ! V_200 )
return - V_195 ;
return 0 ;
}
static int T_4 F_94 ( char * V_201 )
{
T_5 V_120 ;
if ( ! V_201 )
return 0 ;
V_120 = F_95 ( V_201 , 0 , & V_202 ) ;
if ( V_120 )
return 0 ;
return 1 ;
}
static int T_6 F_96 ( struct V_46 * V_46 )
{
T_7 V_203 ;
unsigned int V_204 ;
V_204 = V_202 ;
if ( ! V_204 ) {
if ( V_205 >= 128 * 1024 )
V_204 = 16 * 1024 ;
else
V_204 = 8 * 1024 ;
}
V_46 -> V_53 . V_72 = F_97 ( V_204 ) ;
V_203 = sizeof( struct V_178 ) << V_46 -> V_53 . V_72 ;
V_46 -> V_53 . V_54 = F_98 ( V_203 , V_191 | V_206 ) ;
if ( ! V_46 -> V_53 . V_54 )
V_46 -> V_53 . V_54 = F_99 ( V_203 ) ;
if ( ! V_46 -> V_53 . V_54 )
return - V_192 ;
return 0 ;
}
static void T_8 F_100 ( struct V_46 * V_46 )
{
unsigned int V_142 ;
for ( V_142 = 0 ; V_142 < ( 1U << V_46 -> V_53 . V_72 ) ; V_142 ++ ) {
struct V_1 * V_2 , * V_197 ;
V_2 = F_101 ( V_46 -> V_53 . V_54 [ V_142 ] . V_55 , 1 ) ;
while ( V_2 ) {
V_197 = F_101 ( V_2 -> V_56 , 1 ) ;
F_102 ( V_2 ) ;
V_2 = V_197 ;
}
}
F_103 ( V_46 -> V_53 . V_54 ) ;
}
void T_4 F_104 ( void )
{
int V_120 ;
V_120 = F_105 ( & V_207 ) ;
if ( V_120 < 0 )
goto V_208;
V_120 = F_106 ( & V_170 ,
V_209 ) ;
if ( V_120 < 0 )
goto V_210;
return;
V_210:
F_107 ( & V_207 ) ;
V_208:
return;
}
