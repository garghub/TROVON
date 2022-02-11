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
static struct V_1 * F_13 ( struct V_18 * V_19 ,
struct V_8 * V_16 ,
unsigned int V_40 ,
bool V_41 )
{
struct V_1 * V_2 ;
struct V_42 * V_42 ;
F_14 ( & V_43 ) ;
V_42 = F_15 ( V_19 -> V_44 ) ;
if ( F_16 ( V_41 ) ) {
struct V_1 * V_45 ;
V_45 = F_17 ( V_42 -> V_46 . V_47 [ V_40 ] . V_48 ) ;
for ( V_2 = F_17 ( V_45 -> V_49 ) ; V_2 ;
V_2 = F_17 ( V_2 -> V_49 ) ) {
if ( F_18 ( V_2 -> V_21 , V_45 -> V_21 ) )
V_45 = V_2 ;
}
V_2 = V_45 ;
} else {
V_2 = F_19 ( sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 )
goto V_51;
}
V_2 -> V_52 = * V_16 ;
F_10 ( V_2 , V_19 , true ) ;
if ( F_20 ( ! V_41 ) ) {
V_2 -> V_49 = V_42 -> V_46 . V_47 [ V_40 ] . V_48 ;
F_21 ( V_42 -> V_46 . V_47 [ V_40 ] . V_48 , V_2 ) ;
}
V_51:
F_22 ( & V_43 ) ;
return V_2 ;
}
static void F_23 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
if ( V_2 && F_16 ( F_24 ( V_22 , V_2 -> V_21 + V_53 ) ) )
F_10 ( V_2 , V_19 , false ) ;
}
static struct V_1 * F_25 ( struct V_1 * V_2 , int V_54 )
{
if ( V_2 )
return V_2 ;
if ( V_54 > V_55 )
return V_56 ;
return NULL ;
}
static struct V_1 * F_26 ( const struct V_8 * V_16 ,
struct V_42 * V_42 , unsigned int V_40 )
{
struct V_1 * V_2 ;
int V_54 = 0 ;
for ( V_2 = F_17 ( V_42 -> V_46 . V_47 [ V_40 ] . V_48 ) ; V_2 ;
V_2 = F_17 ( V_2 -> V_49 ) ) {
if ( F_8 ( & V_2 -> V_52 , V_16 ) )
break;
V_54 ++ ;
}
return F_25 ( V_2 , V_54 ) ;
}
static struct V_1 * F_27 ( struct V_57 * V_58 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_8 V_16 ;
unsigned int V_40 ;
struct V_42 * V_42 ;
V_16 . V_14 = V_58 -> V_59 -> V_14 ;
switch ( V_16 . V_14 ) {
case V_15 :
V_16 . V_16 . V_17 = F_28 ( V_58 ) -> V_60 ;
V_40 = ( V_61 unsigned int ) V_16 . V_16 . V_17 ;
break;
case V_62 :
* (struct V_11 * ) V_16 . V_16 . V_12 = F_29 ( V_58 ) -> V_60 ;
V_40 = F_30 ( & F_29 ( V_58 ) -> V_60 ) ;
break;
default:
return NULL ;
}
V_42 = F_15 ( V_19 -> V_44 ) ;
V_40 = F_31 ( V_40 , V_42 -> V_46 . V_63 ) ;
for ( V_2 = F_17 ( V_42 -> V_46 . V_47 [ V_40 ] . V_48 ) ; V_2 ;
V_2 = F_17 ( V_2 -> V_49 ) ) {
if ( F_8 ( & V_2 -> V_52 , & V_16 ) )
break;
}
F_23 ( V_2 , V_19 ) ;
return V_2 ;
}
static struct V_1 * F_32 ( struct V_64 * V_65 )
{
struct V_66 * V_67 ;
struct V_1 * V_2 ;
struct V_8 V_16 ;
unsigned int V_40 ;
struct V_42 * V_42 ;
V_16 . V_14 = V_65 -> V_68 ;
switch ( V_16 . V_14 ) {
case V_15 :
V_16 . V_16 . V_17 = V_65 -> V_69 ;
V_40 = ( V_61 unsigned int ) V_16 . V_16 . V_17 ;
break;
case V_62 :
V_67 = F_33 ( (struct V_70 * ) V_65 ) ;
* (struct V_11 * ) V_16 . V_16 . V_12 = V_67 -> V_71 ;
V_40 = F_30 ( & V_67 -> V_71 ) ;
break;
default:
return NULL ;
}
V_42 = F_34 ( V_65 ) ;
V_40 = F_31 ( V_40 , V_42 -> V_46 . V_63 ) ;
for ( V_2 = F_17 ( V_42 -> V_46 . V_47 [ V_40 ] . V_48 ) ; V_2 ;
V_2 = F_17 ( V_2 -> V_49 ) ) {
if ( F_8 ( & V_2 -> V_52 , & V_16 ) )
break;
}
return V_2 ;
}
static struct V_1 * F_35 ( struct V_70 * V_72 ,
struct V_18 * V_19 ,
bool V_73 )
{
struct V_1 * V_2 ;
struct V_8 V_16 ;
unsigned int V_40 ;
struct V_42 * V_42 ;
bool V_41 ;
V_16 . V_14 = V_72 -> V_74 ;
switch ( V_16 . V_14 ) {
case V_15 :
V_16 . V_16 . V_17 = F_36 ( V_72 ) -> V_75 ;
V_40 = ( V_61 unsigned int ) V_16 . V_16 . V_17 ;
break;
case V_62 :
* (struct V_11 * ) V_16 . V_16 . V_12 = F_37 ( V_72 ) -> V_76 ;
V_40 = F_30 ( & F_37 ( V_72 ) -> V_76 ) ;
break;
default:
return NULL ;
}
V_42 = F_15 ( V_19 -> V_44 ) ;
V_40 = F_31 ( V_40 , V_42 -> V_46 . V_63 ) ;
V_2 = F_26 ( & V_16 , V_42 , V_40 ) ;
V_41 = false ;
if ( V_2 == V_56 ) {
V_41 = true ;
V_2 = NULL ;
}
if ( ! V_2 && V_73 )
V_2 = F_13 ( V_19 , & V_16 , V_40 , V_41 ) ;
else
F_23 ( V_2 , V_19 ) ;
return V_2 ;
}
void F_38 ( struct V_70 * V_72 )
{
const struct V_77 * V_78 = F_39 ( V_72 ) ;
struct V_18 * V_19 = F_40 ( V_72 ) ;
struct V_79 * V_80 = F_41 ( V_72 ) ;
struct V_1 * V_2 ;
unsigned long V_81 ;
T_1 V_7 ;
int V_82 ;
if ( V_83 || ! V_19 )
return;
if ( V_19 -> V_84 & V_85 )
F_42 ( V_19 ) ;
F_43 () ;
if ( V_78 -> V_86 || ! V_80 -> V_87 ) {
V_2 = F_35 ( V_72 , V_19 , false ) ;
if ( V_2 && ! F_1 ( V_2 , V_24 ) )
F_5 ( V_2 , V_24 , 0 ) ;
goto V_51;
} else
V_2 = F_35 ( V_72 , V_19 , true ) ;
if ( ! V_2 )
goto V_51;
V_81 = F_3 ( V_2 , V_24 ) ;
V_82 = V_81 - V_80 -> V_87 ;
if ( ! F_1 ( V_2 , V_24 ) ) {
if ( V_82 <= 0 )
V_81 = V_80 -> V_87 ;
else
V_81 -= ( V_82 >> 3 ) ;
F_6 ( V_2 , V_24 , V_81 ) ;
}
if ( ! F_1 ( V_2 , V_26 ) ) {
unsigned long V_88 ;
if ( V_82 < 0 )
V_82 = - V_82 ;
V_82 >>= 1 ;
if ( V_82 < V_80 -> V_89 )
V_82 = V_80 -> V_89 ;
V_88 = F_3 ( V_2 , V_26 ) ;
if ( V_82 >= V_88 )
V_88 = V_82 ;
else
V_88 -= ( V_88 - V_82 ) >> 2 ;
F_6 ( V_2 , V_26 , V_88 ) ;
}
if ( F_44 ( V_80 ) ) {
if ( ! F_1 ( V_2 , V_28 ) ) {
V_7 = F_2 ( V_2 , V_28 ) ;
if ( V_7 && ( V_80 -> V_90 >> 1 ) > V_7 )
F_5 ( V_2 , V_28 ,
V_80 -> V_90 >> 1 ) ;
}
if ( ! F_1 ( V_2 , V_30 ) ) {
V_7 = F_2 ( V_2 , V_30 ) ;
if ( V_80 -> V_90 > V_7 )
F_5 ( V_2 , V_30 ,
V_80 -> V_90 ) ;
}
} else if ( V_80 -> V_90 > V_80 -> V_91 &&
V_78 -> V_92 == V_93 ) {
if ( ! F_1 ( V_2 , V_28 ) )
F_5 ( V_2 , V_28 ,
F_45 ( V_80 -> V_90 >> 1 , V_80 -> V_91 ) ) ;
if ( ! F_1 ( V_2 , V_30 ) ) {
V_7 = F_2 ( V_2 , V_30 ) ;
F_5 ( V_2 , V_30 , ( V_7 + V_80 -> V_90 ) >> 1 ) ;
}
} else {
if ( ! F_1 ( V_2 , V_30 ) ) {
V_7 = F_2 ( V_2 , V_30 ) ;
F_5 ( V_2 , V_30 ,
( V_7 + V_80 -> V_91 ) >> 1 ) ;
}
if ( ! F_1 ( V_2 , V_28 ) ) {
V_7 = F_2 ( V_2 , V_28 ) ;
if ( V_7 && V_80 -> V_91 > V_7 )
F_5 ( V_2 , V_28 ,
V_80 -> V_91 ) ;
}
if ( ! F_1 ( V_2 , V_32 ) ) {
V_7 = F_2 ( V_2 , V_32 ) ;
if ( V_7 < V_80 -> V_94 &&
V_80 -> V_94 != V_95 )
F_5 ( V_2 , V_32 ,
V_80 -> V_94 ) ;
}
}
V_2 -> V_21 = V_22 ;
V_51:
F_46 () ;
}
void F_47 ( struct V_70 * V_72 )
{
struct V_18 * V_19 = F_40 ( V_72 ) ;
struct V_79 * V_80 = F_41 ( V_72 ) ;
struct V_1 * V_2 ;
T_1 V_7 ;
if ( V_19 == NULL )
goto V_96;
F_42 ( V_19 ) ;
F_43 () ;
V_2 = F_35 ( V_72 , V_19 , true ) ;
if ( ! V_2 ) {
F_46 () ;
goto V_96;
}
if ( F_1 ( V_2 , V_30 ) )
V_80 -> V_97 = F_2 ( V_2 , V_30 ) ;
V_7 = F_2 ( V_2 , V_28 ) ;
if ( V_7 ) {
V_80 -> V_91 = V_7 ;
if ( V_80 -> V_91 > V_80 -> V_97 )
V_80 -> V_91 = V_80 -> V_97 ;
} else {
V_80 -> V_91 = V_98 ;
}
V_7 = F_2 ( V_2 , V_32 ) ;
if ( V_7 && V_80 -> V_94 != V_7 ) {
F_48 ( V_80 ) ;
F_49 ( V_80 ) ;
V_80 -> V_94 = V_7 ;
}
V_7 = F_2 ( V_2 , V_24 ) ;
if ( V_7 == 0 || V_80 -> V_87 == 0 ) {
F_46 () ;
goto V_96;
}
V_7 = F_4 ( V_7 ) ;
if ( V_7 > V_80 -> V_87 ) {
V_80 -> V_87 = V_7 ;
V_80 -> V_99 = V_80 -> V_100 ;
}
V_7 = F_3 ( V_2 , V_26 ) ;
if ( V_7 > V_80 -> V_89 ) {
V_80 -> V_89 = V_7 ;
V_80 -> V_101 = V_80 -> V_102 = F_45 ( V_80 -> V_89 , F_50 ( V_72 ) ) ;
}
F_46 () ;
F_51 ( V_72 ) ;
V_96:
if ( V_80 -> V_87 == 0 ) {
V_80 -> V_89 = V_80 -> V_101 = V_80 -> V_102 = V_103 ;
F_39 ( V_72 ) -> V_104 = V_103 ;
}
if ( V_80 -> V_105 > 1 )
V_80 -> V_90 = 1 ;
else
V_80 -> V_90 = F_52 ( V_80 , V_19 ) ;
V_80 -> V_106 = V_107 ;
}
bool F_53 ( struct V_57 * V_58 , struct V_18 * V_19 , bool V_108 )
{
struct V_1 * V_2 ;
bool V_109 ;
if ( ! V_19 )
return false ;
F_43 () ;
V_2 = F_27 ( V_58 , V_19 ) ;
if ( V_108 ) {
if ( V_2 &&
( T_1 ) F_54 () - V_2 -> V_34 < V_110 &&
( V_111 ) ( V_2 -> V_33 - V_58 -> V_112 ) > V_113 )
V_109 = false ;
else
V_109 = true ;
} else {
if ( V_2 && F_2 ( V_2 , V_24 ) && V_2 -> V_34 )
V_109 = true ;
else
V_109 = false ;
}
F_46 () ;
return V_109 ;
}
void F_55 ( struct V_70 * V_72 , struct V_18 * V_19 )
{
struct V_1 * V_2 ;
F_43 () ;
V_2 = F_35 ( V_72 , V_19 , true ) ;
if ( V_2 ) {
struct V_79 * V_80 = F_41 ( V_72 ) ;
if ( ( T_1 ) F_54 () - V_2 -> V_34 <= V_110 ) {
V_80 -> V_114 . V_115 = V_2 -> V_34 ;
V_80 -> V_114 . V_112 = V_2 -> V_33 ;
}
}
F_46 () ;
}
bool F_56 ( struct V_70 * V_72 )
{
struct V_18 * V_19 = F_40 ( V_72 ) ;
bool V_109 = false ;
if ( V_19 ) {
struct V_1 * V_2 ;
F_43 () ;
V_2 = F_35 ( V_72 , V_19 , true ) ;
if ( V_2 ) {
struct V_79 * V_80 = F_41 ( V_72 ) ;
if ( ( V_111 ) ( V_2 -> V_33 - V_80 -> V_114 . V_112 ) <= 0 ||
( ( T_1 ) F_54 () - V_2 -> V_34 > V_110 &&
V_2 -> V_34 <= ( T_1 ) V_80 -> V_114 . V_115 ) ) {
V_2 -> V_34 = ( T_1 ) V_80 -> V_114 . V_115 ;
V_2 -> V_33 = V_80 -> V_114 . V_112 ;
}
V_109 = true ;
}
F_46 () ;
}
return V_109 ;
}
bool F_57 ( struct V_64 * V_65 )
{
struct V_1 * V_2 ;
bool V_109 = false ;
F_43 () ;
V_2 = F_32 ( V_65 ) ;
if ( V_2 ) {
const struct V_116 * V_117 ;
struct V_70 * V_72 = (struct V_70 * ) V_65 ;
V_117 = F_58 ( V_72 ) ;
if ( ( V_111 ) ( V_2 -> V_33 - V_117 -> V_118 ) <= 0 ||
( ( T_1 ) F_54 () - V_2 -> V_34 > V_110 &&
V_2 -> V_34 <= ( T_1 ) V_117 -> V_119 ) ) {
V_2 -> V_34 = ( T_1 ) V_117 -> V_119 ;
V_2 -> V_33 = V_117 -> V_118 ;
}
V_109 = true ;
}
F_46 () ;
return V_109 ;
}
void F_59 ( struct V_70 * V_72 , T_2 * V_36 ,
struct V_120 * V_38 ,
int * V_37 , unsigned long * V_121 )
{
struct V_1 * V_2 ;
F_43 () ;
V_2 = F_35 ( V_72 , F_40 ( V_72 ) , false ) ;
if ( V_2 ) {
struct V_122 * V_123 = & V_2 -> V_35 ;
unsigned int V_124 ;
do {
V_124 = F_60 ( & V_125 ) ;
if ( V_123 -> V_36 )
* V_36 = V_123 -> V_36 ;
* V_38 = V_123 -> V_38 ;
* V_37 = V_123 -> V_37 ;
* V_121 = * V_37 ? V_123 -> V_121 : 0 ;
} while ( F_61 ( & V_125 , V_124 ) );
}
F_46 () ;
}
void F_62 ( struct V_70 * V_72 , T_2 V_36 ,
struct V_120 * V_38 , bool V_126 )
{
struct V_1 * V_2 ;
F_43 () ;
V_2 = F_35 ( V_72 , F_40 ( V_72 ) , true ) ;
if ( V_2 ) {
struct V_122 * V_123 = & V_2 -> V_35 ;
F_63 ( & V_125 ) ;
V_123 -> V_36 = V_36 ;
if ( V_38 -> V_39 > 0 )
V_123 -> V_38 = * V_38 ;
if ( V_126 ) {
++ V_123 -> V_37 ;
V_123 -> V_121 = V_22 ;
} else
V_123 -> V_37 = 0 ;
F_64 ( & V_125 ) ;
}
F_46 () ;
}
static int F_65 ( struct V_127 * V_128 ,
struct V_1 * V_2 )
{
struct V_129 * V_130 ;
int V_131 ;
switch ( V_2 -> V_52 . V_14 ) {
case V_15 :
if ( F_66 ( V_128 , V_132 ,
V_2 -> V_52 . V_16 . V_17 ) < 0 )
goto V_133;
break;
case V_62 :
if ( F_67 ( V_128 , V_134 , 16 ,
V_2 -> V_52 . V_16 . V_12 ) < 0 )
goto V_133;
break;
default:
return - V_135 ;
}
if ( F_68 ( V_128 , V_136 ,
V_22 - V_2 -> V_21 ) < 0 )
goto V_133;
if ( V_2 -> V_34 ) {
if ( F_69 ( V_128 , V_137 ,
( V_111 ) ( F_54 () - V_2 -> V_34 ) ) < 0 )
goto V_133;
if ( F_70 ( V_128 , V_138 ,
V_2 -> V_33 ) < 0 )
goto V_133;
}
{
int V_139 = 0 ;
V_130 = F_71 ( V_128 , V_140 ) ;
if ( ! V_130 )
goto V_133;
for ( V_131 = 0 ; V_131 < V_141 + 1 ; V_131 ++ ) {
if ( ! V_2 -> V_6 [ V_131 ] )
continue;
if ( F_70 ( V_128 , V_131 + 1 , V_2 -> V_6 [ V_131 ] ) < 0 )
goto V_133;
V_139 ++ ;
}
if ( V_139 )
F_72 ( V_128 , V_130 ) ;
else
F_73 ( V_128 , V_130 ) ;
}
{
struct V_122 V_142 [ 1 ] , * V_123 ;
unsigned int V_124 ;
do {
V_124 = F_60 ( & V_125 ) ;
V_142 [ 0 ] = V_2 -> V_35 ;
} while ( F_61 ( & V_125 , V_124 ) );
V_123 = V_142 ;
if ( V_123 -> V_36 &&
F_74 ( V_128 , V_143 ,
V_123 -> V_36 ) < 0 )
goto V_133;
if ( V_123 -> V_37 &&
( F_74 ( V_128 , V_144 ,
V_123 -> V_37 ) < 0 ||
F_68 ( V_128 , V_145 ,
V_22 - V_123 -> V_121 ) < 0 ) )
goto V_133;
if ( V_123 -> V_38 . V_39 > 0 &&
F_67 ( V_128 , V_146 ,
V_123 -> V_38 . V_39 , V_123 -> V_38 . V_7 ) < 0 )
goto V_133;
}
return 0 ;
V_133:
return - V_147 ;
}
static int F_75 ( struct V_127 * V_148 ,
struct V_149 * V_150 ,
struct V_1 * V_2 )
{
void * V_151 ;
V_151 = F_76 ( V_148 , F_77 ( V_150 -> V_148 ) . V_152 , V_150 -> V_153 -> V_154 ,
& V_155 , V_156 ,
V_157 ) ;
if ( ! V_151 )
return - V_147 ;
if ( F_65 ( V_148 , V_2 ) < 0 )
goto V_133;
return F_78 ( V_148 , V_151 ) ;
V_133:
F_79 ( V_148 , V_151 ) ;
return - V_147 ;
}
static int F_80 ( struct V_127 * V_148 ,
struct V_149 * V_150 )
{
struct V_42 * V_42 = F_81 ( V_148 -> V_72 ) ;
unsigned int V_158 = 1U << V_42 -> V_46 . V_63 ;
unsigned int V_159 , V_160 = V_150 -> args [ 0 ] ;
int V_161 = V_150 -> args [ 1 ] , V_162 = V_161 ;
for ( V_159 = V_160 ; V_159 < V_158 ; V_159 ++ , V_161 = 0 ) {
struct V_1 * V_2 ;
struct V_163 * V_164 = V_42 -> V_46 . V_47 + V_159 ;
F_43 () ;
for ( V_162 = 0 , V_2 = F_17 ( V_164 -> V_48 ) ; V_2 ;
V_2 = F_17 ( V_2 -> V_49 ) , V_162 ++ ) {
if ( V_162 < V_161 )
continue;
if ( F_75 ( V_148 , V_150 , V_2 ) < 0 ) {
F_46 () ;
goto V_165;
}
}
F_46 () ;
}
V_165:
V_150 -> args [ 0 ] = V_159 ;
V_150 -> args [ 1 ] = V_162 ;
return V_148 -> V_39 ;
}
static int F_82 ( struct V_166 * V_167 , struct V_8 * V_16 ,
unsigned int * V_40 , int V_168 )
{
struct V_129 * V_9 ;
V_9 = V_167 -> V_169 [ V_132 ] ;
if ( V_9 ) {
V_16 -> V_14 = V_15 ;
V_16 -> V_16 . V_17 = F_83 ( V_9 ) ;
* V_40 = ( V_61 unsigned int ) V_16 -> V_16 . V_17 ;
return 0 ;
}
V_9 = V_167 -> V_169 [ V_134 ] ;
if ( V_9 ) {
if ( F_84 ( V_9 ) != sizeof( struct V_11 ) )
return - V_170 ;
V_16 -> V_14 = V_62 ;
memcpy ( V_16 -> V_16 . V_12 , F_85 ( V_9 ) , sizeof( V_16 -> V_16 . V_12 ) ) ;
* V_40 = F_30 ( (struct V_11 * ) V_16 -> V_16 . V_12 ) ;
return 0 ;
}
return V_168 ? 1 : - V_135 ;
}
static int F_86 ( struct V_127 * V_148 , struct V_166 * V_167 )
{
struct V_1 * V_2 ;
struct V_8 V_16 ;
unsigned int V_40 ;
struct V_127 * V_128 ;
struct V_42 * V_42 = F_87 ( V_167 ) ;
void * V_171 ;
int V_109 ;
V_109 = F_82 ( V_167 , & V_16 , & V_40 , 0 ) ;
if ( V_109 < 0 )
return V_109 ;
V_128 = F_88 ( V_172 , V_173 ) ;
if ( ! V_128 )
return - V_174 ;
V_171 = F_89 ( V_128 , V_167 , & V_155 , 0 ,
V_167 -> V_175 -> V_176 ) ;
if ( ! V_171 )
goto V_133;
V_40 = F_31 ( V_40 , V_42 -> V_46 . V_63 ) ;
V_109 = - V_177 ;
F_43 () ;
for ( V_2 = F_17 ( V_42 -> V_46 . V_47 [ V_40 ] . V_48 ) ; V_2 ;
V_2 = F_17 ( V_2 -> V_49 ) ) {
if ( F_8 ( & V_2 -> V_52 , & V_16 ) ) {
V_109 = F_65 ( V_128 , V_2 ) ;
break;
}
}
F_46 () ;
if ( V_109 < 0 )
goto V_178;
F_78 ( V_128 , V_171 ) ;
return F_90 ( V_128 , V_167 ) ;
V_133:
V_109 = - V_147 ;
V_178:
F_91 ( V_128 ) ;
return V_109 ;
}
static int F_92 ( struct V_42 * V_42 )
{
unsigned int V_158 = 1U << V_42 -> V_46 . V_63 ;
struct V_163 * V_164 = V_42 -> V_46 . V_47 ;
struct V_1 * V_2 ;
unsigned int V_159 ;
for ( V_159 = 0 ; V_159 < V_158 ; V_159 ++ , V_164 ++ ) {
F_14 ( & V_43 ) ;
V_2 = F_93 ( V_164 -> V_48 ) ;
if ( V_2 )
V_164 -> V_48 = NULL ;
F_22 ( & V_43 ) ;
while ( V_2 ) {
struct V_1 * V_179 ;
V_179 = F_94 ( V_2 -> V_49 ) ;
F_95 ( V_2 , V_180 ) ;
V_2 = V_179 ;
}
}
return 0 ;
}
static int F_96 ( struct V_127 * V_148 , struct V_166 * V_167 )
{
struct V_163 * V_164 ;
struct V_1 * V_2 ;
struct V_1 T_3 * * V_181 ;
struct V_8 V_16 ;
unsigned int V_40 ;
struct V_42 * V_42 = F_87 ( V_167 ) ;
int V_109 ;
V_109 = F_82 ( V_167 , & V_16 , & V_40 , 1 ) ;
if ( V_109 < 0 )
return V_109 ;
if ( V_109 > 0 )
return F_92 ( V_42 ) ;
V_40 = F_31 ( V_40 , V_42 -> V_46 . V_63 ) ;
V_164 = V_42 -> V_46 . V_47 + V_40 ;
V_181 = & V_164 -> V_48 ;
F_14 ( & V_43 ) ;
for ( V_2 = F_93 ( * V_181 ) ; V_2 ;
V_181 = & V_2 -> V_49 , V_2 = F_93 ( * V_181 ) ) {
if ( F_8 ( & V_2 -> V_52 , & V_16 ) ) {
* V_181 = V_2 -> V_49 ;
break;
}
}
F_22 ( & V_43 ) ;
if ( ! V_2 )
return - V_177 ;
F_95 ( V_2 , V_180 ) ;
return 0 ;
}
static int T_4 F_97 ( char * V_182 )
{
T_5 V_109 ;
if ( ! V_182 )
return 0 ;
V_109 = F_98 ( V_182 , 0 , & V_183 ) ;
if ( V_109 )
return 0 ;
return 1 ;
}
static int T_6 F_99 ( struct V_42 * V_42 )
{
T_7 V_184 ;
unsigned int V_185 ;
V_185 = V_183 ;
if ( ! V_185 ) {
if ( V_186 >= 128 * 1024 )
V_185 = 16 * 1024 ;
else
V_185 = 8 * 1024 ;
}
V_42 -> V_46 . V_63 = F_100 ( V_185 ) ;
V_184 = sizeof( struct V_163 ) << V_42 -> V_46 . V_63 ;
V_42 -> V_46 . V_47 = F_101 ( V_184 , V_173 | V_187 ) ;
if ( ! V_42 -> V_46 . V_47 )
V_42 -> V_46 . V_47 = F_102 ( V_184 ) ;
if ( ! V_42 -> V_46 . V_47 )
return - V_174 ;
return 0 ;
}
static void T_8 F_103 ( struct V_42 * V_42 )
{
unsigned int V_131 ;
for ( V_131 = 0 ; V_131 < ( 1U << V_42 -> V_46 . V_63 ) ; V_131 ++ ) {
struct V_1 * V_2 , * V_179 ;
V_2 = F_104 ( V_42 -> V_46 . V_47 [ V_131 ] . V_48 , 1 ) ;
while ( V_2 ) {
V_179 = F_104 ( V_2 -> V_49 , 1 ) ;
F_105 ( V_2 ) ;
V_2 = V_179 ;
}
}
if ( F_106 ( V_42 -> V_46 . V_47 ) )
F_107 ( V_42 -> V_46 . V_47 ) ;
else
F_105 ( V_42 -> V_46 . V_47 ) ;
}
void T_4 F_108 ( void )
{
int V_109 ;
V_109 = F_109 ( & V_188 ) ;
if ( V_109 < 0 )
goto V_189;
V_109 = F_110 ( & V_155 ,
V_190 ,
F_111 ( V_190 ) ) ;
if ( V_109 < 0 )
goto V_191;
return;
V_191:
F_112 ( & V_188 ) ;
V_189:
return;
}
