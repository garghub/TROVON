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
bool F_48 ( struct V_62 * V_63 , struct V_18 * V_19 , bool V_118 )
{
struct V_1 * V_2 ;
bool V_119 ;
if ( ! V_19 )
return false ;
F_38 () ;
V_2 = F_23 ( V_63 , V_19 ) ;
if ( V_118 ) {
if ( V_2 &&
( T_1 ) F_49 () - V_2 -> V_36 < V_120 &&
( V_121 ) ( V_2 -> V_35 - V_63 -> V_122 ) > V_123 )
V_119 = false ;
else
V_119 = true ;
} else {
if ( V_2 && F_2 ( V_2 , V_25 ) && V_2 -> V_36 )
V_119 = true ;
else
V_119 = false ;
}
F_41 () ;
return V_119 ;
}
void F_50 ( struct V_80 * V_81 , struct V_18 * V_19 )
{
struct V_1 * V_2 ;
F_38 () ;
V_2 = F_31 ( V_81 , V_19 , true ) ;
if ( V_2 ) {
struct V_90 * V_91 = F_36 ( V_81 ) ;
if ( ( T_1 ) F_49 () - V_2 -> V_36 <= V_120 ) {
V_91 -> V_124 . V_125 = V_2 -> V_36 ;
V_91 -> V_124 . V_122 = V_2 -> V_35 ;
}
}
F_41 () ;
}
bool F_51 ( struct V_80 * V_81 )
{
struct V_18 * V_19 = F_35 ( V_81 ) ;
bool V_119 = false ;
if ( V_19 ) {
struct V_1 * V_2 ;
F_38 () ;
V_2 = F_31 ( V_81 , V_19 , true ) ;
if ( V_2 ) {
struct V_90 * V_91 = F_36 ( V_81 ) ;
if ( ( V_121 ) ( V_2 -> V_35 - V_91 -> V_124 . V_122 ) <= 0 ||
( ( T_1 ) F_49 () - V_2 -> V_36 > V_120 &&
V_2 -> V_36 <= ( T_1 ) V_91 -> V_124 . V_125 ) ) {
V_2 -> V_36 = ( T_1 ) V_91 -> V_124 . V_125 ;
V_2 -> V_35 = V_91 -> V_124 . V_122 ;
}
V_119 = true ;
}
F_41 () ;
}
return V_119 ;
}
bool F_52 ( struct V_73 * V_74 )
{
struct V_1 * V_2 ;
bool V_119 = false ;
F_38 () ;
V_2 = F_28 ( V_74 ) ;
if ( V_2 ) {
const struct V_126 * V_127 ;
struct V_80 * V_81 = (struct V_80 * ) V_74 ;
V_127 = F_53 ( V_81 ) ;
if ( ( V_121 ) ( V_2 -> V_35 - V_127 -> V_128 ) <= 0 ||
( ( T_1 ) F_49 () - V_2 -> V_36 > V_120 &&
V_2 -> V_36 <= ( T_1 ) V_127 -> V_129 ) ) {
V_2 -> V_36 = ( T_1 ) V_127 -> V_129 ;
V_2 -> V_35 = V_127 -> V_128 ;
}
V_119 = true ;
}
F_41 () ;
return V_119 ;
}
void F_54 ( struct V_80 * V_81 , T_2 * V_38 ,
struct V_130 * V_40 ,
int * V_39 , unsigned long * V_131 )
{
struct V_1 * V_2 ;
F_38 () ;
V_2 = F_31 ( V_81 , F_35 ( V_81 ) , false ) ;
if ( V_2 ) {
struct V_132 * V_133 = & V_2 -> V_37 ;
unsigned int V_134 ;
do {
V_134 = F_55 ( & V_135 ) ;
if ( V_133 -> V_38 )
* V_38 = V_133 -> V_38 ;
* V_40 = V_133 -> V_40 ;
* V_39 = V_133 -> V_39 ;
* V_131 = * V_39 ? V_133 -> V_131 : 0 ;
} while ( F_56 ( & V_135 , V_134 ) );
}
F_41 () ;
}
void F_57 ( struct V_80 * V_81 , T_2 V_38 ,
struct V_130 * V_40 , bool V_136 )
{
struct V_18 * V_19 = F_35 ( V_81 ) ;
struct V_1 * V_2 ;
if ( ! V_19 )
return;
F_38 () ;
V_2 = F_31 ( V_81 , V_19 , true ) ;
if ( V_2 ) {
struct V_132 * V_133 = & V_2 -> V_37 ;
F_58 ( & V_135 ) ;
if ( V_38 )
V_133 -> V_38 = V_38 ;
if ( V_40 && V_40 -> V_41 > 0 )
V_133 -> V_40 = * V_40 ;
if ( V_136 ) {
++ V_133 -> V_39 ;
V_133 -> V_131 = V_23 ;
} else
V_133 -> V_39 = 0 ;
F_59 ( & V_135 ) ;
}
F_41 () ;
}
static int F_60 ( struct V_137 * V_138 ,
struct V_1 * V_2 )
{
struct V_139 * V_140 ;
int V_141 ;
switch ( V_2 -> V_59 . V_14 ) {
case V_15 :
if ( F_61 ( V_138 , V_142 ,
V_2 -> V_59 . V_16 . V_17 ) < 0 )
goto V_143;
if ( F_61 ( V_138 , V_144 ,
V_2 -> V_58 . V_16 . V_17 ) < 0 )
goto V_143;
break;
case V_69 :
if ( F_62 ( V_138 , V_145 , 16 ,
V_2 -> V_59 . V_16 . V_12 ) < 0 )
goto V_143;
if ( F_62 ( V_138 , V_146 , 16 ,
V_2 -> V_58 . V_16 . V_12 ) < 0 )
goto V_143;
break;
default:
return - V_147 ;
}
if ( F_63 ( V_138 , V_148 ,
V_23 - V_2 -> V_22 ) < 0 )
goto V_143;
if ( V_2 -> V_36 ) {
if ( F_64 ( V_138 , V_149 ,
( V_121 ) ( F_49 () - V_2 -> V_36 ) ) < 0 )
goto V_143;
if ( F_65 ( V_138 , V_150 ,
V_2 -> V_35 ) < 0 )
goto V_143;
}
{
int V_151 = 0 ;
V_140 = F_66 ( V_138 , V_152 ) ;
if ( ! V_140 )
goto V_143;
for ( V_141 = 0 ; V_141 < V_153 + 1 ; V_141 ++ ) {
T_1 V_7 = V_2 -> V_6 [ V_141 ] ;
if ( ! V_7 )
continue;
if ( V_141 == V_25 ) {
if ( F_65 ( V_138 , V_154 + 1 ,
V_7 ) < 0 )
goto V_143;
V_151 ++ ;
V_7 = F_40 ( V_7 / 1000 , 1U ) ;
}
if ( V_141 == V_27 ) {
if ( F_65 ( V_138 , V_155 + 1 ,
V_7 ) < 0 )
goto V_143;
V_151 ++ ;
V_7 = F_40 ( V_7 / 1000 , 1U ) ;
}
if ( F_65 ( V_138 , V_141 + 1 , V_7 ) < 0 )
goto V_143;
V_151 ++ ;
}
if ( V_151 )
F_67 ( V_138 , V_140 ) ;
else
F_68 ( V_138 , V_140 ) ;
}
{
struct V_132 V_156 [ 1 ] , * V_133 ;
unsigned int V_134 ;
do {
V_134 = F_55 ( & V_135 ) ;
V_156 [ 0 ] = V_2 -> V_37 ;
} while ( F_56 ( & V_135 , V_134 ) );
V_133 = V_156 ;
if ( V_133 -> V_38 &&
F_69 ( V_138 , V_157 ,
V_133 -> V_38 ) < 0 )
goto V_143;
if ( V_133 -> V_39 &&
( F_69 ( V_138 , V_158 ,
V_133 -> V_39 ) < 0 ||
F_63 ( V_138 , V_159 ,
V_23 - V_133 -> V_131 ) < 0 ) )
goto V_143;
if ( V_133 -> V_40 . V_41 > 0 &&
F_62 ( V_138 , V_160 ,
V_133 -> V_40 . V_41 , V_133 -> V_40 . V_7 ) < 0 )
goto V_143;
}
return 0 ;
V_143:
return - V_161 ;
}
static int F_70 ( struct V_137 * V_162 ,
struct V_163 * V_164 ,
struct V_1 * V_2 )
{
void * V_165 ;
V_165 = F_71 ( V_162 , F_72 ( V_164 -> V_162 ) . V_166 , V_164 -> V_167 -> V_168 ,
& V_169 , V_170 ,
V_171 ) ;
if ( ! V_165 )
return - V_161 ;
if ( F_60 ( V_162 , V_2 ) < 0 )
goto V_143;
return F_73 ( V_162 , V_165 ) ;
V_143:
F_74 ( V_162 , V_165 ) ;
return - V_161 ;
}
static int F_75 ( struct V_137 * V_162 ,
struct V_163 * V_164 )
{
struct V_46 * V_46 = F_76 ( V_162 -> V_81 ) ;
unsigned int V_172 = 1U << V_46 -> V_53 . V_72 ;
unsigned int V_173 , V_174 = V_164 -> args [ 0 ] ;
int V_175 = V_164 -> args [ 1 ] , V_176 = V_175 ;
for ( V_173 = V_174 ; V_173 < V_172 ; V_173 ++ , V_175 = 0 ) {
struct V_1 * V_2 ;
struct V_177 * V_178 = V_46 -> V_53 . V_54 + V_173 ;
F_38 () ;
for ( V_176 = 0 , V_2 = F_16 ( V_178 -> V_55 ) ; V_2 ;
V_2 = F_16 ( V_2 -> V_56 ) , V_176 ++ ) {
if ( V_176 < V_175 )
continue;
if ( F_70 ( V_162 , V_164 , V_2 ) < 0 ) {
F_41 () ;
goto V_179;
}
}
F_41 () ;
}
V_179:
V_164 -> args [ 0 ] = V_173 ;
V_164 -> args [ 1 ] = V_176 ;
return V_162 -> V_41 ;
}
static int F_77 ( struct V_180 * V_181 , struct V_8 * V_16 ,
unsigned int * V_45 , int V_182 , int V_183 , int V_184 )
{
struct V_139 * V_9 ;
V_9 = V_181 -> V_185 [ V_183 ] ;
if ( V_9 ) {
V_16 -> V_14 = V_15 ;
V_16 -> V_16 . V_17 = F_78 ( V_9 ) ;
if ( V_45 )
* V_45 = ( V_67 unsigned int ) V_16 -> V_16 . V_17 ;
return 0 ;
}
V_9 = V_181 -> V_185 [ V_184 ] ;
if ( V_9 ) {
if ( F_79 ( V_9 ) != sizeof( struct V_11 ) )
return - V_186 ;
V_16 -> V_14 = V_69 ;
memcpy ( V_16 -> V_16 . V_12 , F_80 ( V_9 ) , sizeof( V_16 -> V_16 . V_12 ) ) ;
if ( V_45 )
* V_45 = F_26 ( (struct V_11 * ) V_16 -> V_16 . V_12 ) ;
return 0 ;
}
return V_182 ? 1 : - V_147 ;
}
static int F_81 ( struct V_180 * V_181 , struct V_8 * V_16 ,
unsigned int * V_45 , int V_182 )
{
return F_77 ( V_181 , V_16 , V_45 , V_182 ,
V_142 ,
V_145 ) ;
}
static int F_82 ( struct V_180 * V_181 , struct V_8 * V_16 )
{
return F_77 ( V_181 , V_16 , NULL , 0 ,
V_144 ,
V_146 ) ;
}
static int F_83 ( struct V_137 * V_162 , struct V_180 * V_181 )
{
struct V_1 * V_2 ;
struct V_8 V_43 , V_44 ;
unsigned int V_45 ;
struct V_137 * V_138 ;
struct V_46 * V_46 = F_84 ( V_181 ) ;
void * V_187 ;
int V_119 ;
bool V_188 = true ;
V_119 = F_81 ( V_181 , & V_44 , & V_45 , 0 ) ;
if ( V_119 < 0 )
return V_119 ;
V_119 = F_82 ( V_181 , & V_43 ) ;
if ( V_119 < 0 )
V_188 = false ;
V_138 = F_85 ( V_189 , V_190 ) ;
if ( ! V_138 )
return - V_191 ;
V_187 = F_86 ( V_138 , V_181 , & V_169 , 0 ,
V_181 -> V_192 -> V_193 ) ;
if ( ! V_187 )
goto V_143;
V_45 = F_27 ( V_45 , V_46 -> V_53 . V_72 ) ;
V_119 = - V_194 ;
F_38 () ;
for ( V_2 = F_16 ( V_46 -> V_53 . V_54 [ V_45 ] . V_55 ) ; V_2 ;
V_2 = F_16 ( V_2 -> V_56 ) ) {
if ( F_4 ( & V_2 -> V_59 , & V_44 ) &&
( ! V_188 || F_4 ( & V_2 -> V_58 , & V_43 ) ) ) {
V_119 = F_60 ( V_138 , V_2 ) ;
break;
}
}
F_41 () ;
if ( V_119 < 0 )
goto V_195;
F_73 ( V_138 , V_187 ) ;
return F_87 ( V_138 , V_181 ) ;
V_143:
V_119 = - V_161 ;
V_195:
F_88 ( V_138 ) ;
return V_119 ;
}
static int F_89 ( struct V_46 * V_46 )
{
unsigned int V_172 = 1U << V_46 -> V_53 . V_72 ;
struct V_177 * V_178 = V_46 -> V_53 . V_54 ;
struct V_1 * V_2 ;
unsigned int V_173 ;
for ( V_173 = 0 ; V_173 < V_172 ; V_173 ++ , V_178 ++ ) {
F_13 ( & V_48 ) ;
V_2 = F_90 ( V_178 -> V_55 ) ;
if ( V_2 )
V_178 -> V_55 = NULL ;
F_21 ( & V_48 ) ;
while ( V_2 ) {
struct V_1 * V_196 ;
V_196 = F_91 ( V_2 -> V_56 ) ;
F_92 ( V_2 , V_197 ) ;
V_2 = V_196 ;
}
}
return 0 ;
}
static int F_93 ( struct V_137 * V_162 , struct V_180 * V_181 )
{
struct V_177 * V_178 ;
struct V_1 * V_2 ;
struct V_1 T_3 * * V_198 ;
struct V_8 V_43 , V_44 ;
unsigned int V_45 ;
struct V_46 * V_46 = F_84 ( V_181 ) ;
int V_119 ;
bool V_188 = true , V_199 = false ;
V_119 = F_81 ( V_181 , & V_44 , & V_45 , 1 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( V_119 > 0 )
return F_89 ( V_46 ) ;
V_119 = F_82 ( V_181 , & V_43 ) ;
if ( V_119 < 0 )
V_188 = false ;
V_45 = F_27 ( V_45 , V_46 -> V_53 . V_72 ) ;
V_178 = V_46 -> V_53 . V_54 + V_45 ;
V_198 = & V_178 -> V_55 ;
F_13 ( & V_48 ) ;
for ( V_2 = F_90 ( * V_198 ) ; V_2 ; V_2 = F_90 ( * V_198 ) ) {
if ( F_4 ( & V_2 -> V_59 , & V_44 ) &&
( ! V_188 || F_4 ( & V_2 -> V_58 , & V_43 ) ) ) {
* V_198 = V_2 -> V_56 ;
F_92 ( V_2 , V_197 ) ;
V_199 = true ;
} else {
V_198 = & V_2 -> V_56 ;
}
}
F_21 ( & V_48 ) ;
if ( ! V_199 )
return - V_194 ;
return 0 ;
}
static int T_4 F_94 ( char * V_200 )
{
T_5 V_119 ;
if ( ! V_200 )
return 0 ;
V_119 = F_95 ( V_200 , 0 , & V_201 ) ;
if ( V_119 )
return 0 ;
return 1 ;
}
static int T_6 F_96 ( struct V_46 * V_46 )
{
T_7 V_202 ;
unsigned int V_203 ;
V_203 = V_201 ;
if ( ! V_203 ) {
if ( V_204 >= 128 * 1024 )
V_203 = 16 * 1024 ;
else
V_203 = 8 * 1024 ;
}
V_46 -> V_53 . V_72 = F_97 ( V_203 ) ;
V_202 = sizeof( struct V_177 ) << V_46 -> V_53 . V_72 ;
V_46 -> V_53 . V_54 = F_98 ( V_202 , V_190 | V_205 ) ;
if ( ! V_46 -> V_53 . V_54 )
V_46 -> V_53 . V_54 = F_99 ( V_202 ) ;
if ( ! V_46 -> V_53 . V_54 )
return - V_191 ;
return 0 ;
}
static void T_8 F_100 ( struct V_46 * V_46 )
{
unsigned int V_141 ;
for ( V_141 = 0 ; V_141 < ( 1U << V_46 -> V_53 . V_72 ) ; V_141 ++ ) {
struct V_1 * V_2 , * V_196 ;
V_2 = F_101 ( V_46 -> V_53 . V_54 [ V_141 ] . V_55 , 1 ) ;
while ( V_2 ) {
V_196 = F_101 ( V_2 -> V_56 , 1 ) ;
F_102 ( V_2 ) ;
V_2 = V_196 ;
}
}
if ( F_103 ( V_46 -> V_53 . V_54 ) )
F_104 ( V_46 -> V_53 . V_54 ) ;
else
F_102 ( V_46 -> V_53 . V_54 ) ;
}
void T_4 F_105 ( void )
{
int V_119 ;
V_119 = F_106 ( & V_206 ) ;
if ( V_119 < 0 )
goto V_207;
V_119 = F_107 ( & V_169 ,
V_208 ) ;
if ( V_119 < 0 )
goto V_209;
return;
V_209:
F_108 ( & V_206 ) ;
V_207:
return;
}
