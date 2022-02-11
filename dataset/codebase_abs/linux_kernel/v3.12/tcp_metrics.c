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
T_1 V_7 , V_96 = 0 ;
if ( V_19 == NULL )
goto V_97;
F_42 ( V_19 ) ;
F_43 () ;
V_2 = F_35 ( V_72 , V_19 , true ) ;
if ( ! V_2 ) {
F_46 () ;
goto V_97;
}
if ( F_1 ( V_2 , V_30 ) )
V_80 -> V_98 = F_2 ( V_2 , V_30 ) ;
V_7 = F_2 ( V_2 , V_28 ) ;
if ( V_7 ) {
V_80 -> V_91 = V_7 ;
if ( V_80 -> V_91 > V_80 -> V_98 )
V_80 -> V_91 = V_80 -> V_98 ;
} else {
V_80 -> V_91 = V_99 ;
}
V_7 = F_2 ( V_2 , V_32 ) ;
if ( V_7 && V_80 -> V_94 != V_7 ) {
F_48 ( V_80 ) ;
F_49 ( V_80 ) ;
V_80 -> V_94 = V_7 ;
}
V_96 = F_3 ( V_2 , V_24 ) ;
F_46 () ;
V_97:
if ( V_96 > V_80 -> V_87 ) {
V_96 >>= 3 ;
F_39 ( V_72 ) -> V_100 = V_96 + F_45 ( 2 * V_96 , F_50 ( V_72 ) ) ;
} else if ( V_80 -> V_87 == 0 ) {
V_80 -> V_89 = V_80 -> V_101 = V_80 -> V_102 = V_103 ;
F_39 ( V_72 ) -> V_100 = V_103 ;
}
if ( V_80 -> V_104 > 1 )
V_80 -> V_90 = 1 ;
else
V_80 -> V_90 = F_51 ( V_80 , V_19 ) ;
V_80 -> V_105 = V_106 ;
}
bool F_52 ( struct V_57 * V_58 , struct V_18 * V_19 , bool V_107 )
{
struct V_1 * V_2 ;
bool V_108 ;
if ( ! V_19 )
return false ;
F_43 () ;
V_2 = F_27 ( V_58 , V_19 ) ;
if ( V_107 ) {
if ( V_2 &&
( T_1 ) F_53 () - V_2 -> V_34 < V_109 &&
( V_110 ) ( V_2 -> V_33 - V_58 -> V_111 ) > V_112 )
V_108 = false ;
else
V_108 = true ;
} else {
if ( V_2 && F_2 ( V_2 , V_24 ) && V_2 -> V_34 )
V_108 = true ;
else
V_108 = false ;
}
F_46 () ;
return V_108 ;
}
void F_54 ( struct V_70 * V_72 , struct V_18 * V_19 )
{
struct V_1 * V_2 ;
F_43 () ;
V_2 = F_35 ( V_72 , V_19 , true ) ;
if ( V_2 ) {
struct V_79 * V_80 = F_41 ( V_72 ) ;
if ( ( T_1 ) F_53 () - V_2 -> V_34 <= V_109 ) {
V_80 -> V_113 . V_114 = V_2 -> V_34 ;
V_80 -> V_113 . V_111 = V_2 -> V_33 ;
}
}
F_46 () ;
}
bool F_55 ( struct V_70 * V_72 )
{
struct V_18 * V_19 = F_40 ( V_72 ) ;
bool V_108 = false ;
if ( V_19 ) {
struct V_1 * V_2 ;
F_43 () ;
V_2 = F_35 ( V_72 , V_19 , true ) ;
if ( V_2 ) {
struct V_79 * V_80 = F_41 ( V_72 ) ;
if ( ( V_110 ) ( V_2 -> V_33 - V_80 -> V_113 . V_111 ) <= 0 ||
( ( T_1 ) F_53 () - V_2 -> V_34 > V_109 &&
V_2 -> V_34 <= ( T_1 ) V_80 -> V_113 . V_114 ) ) {
V_2 -> V_34 = ( T_1 ) V_80 -> V_113 . V_114 ;
V_2 -> V_33 = V_80 -> V_113 . V_111 ;
}
V_108 = true ;
}
F_46 () ;
}
return V_108 ;
}
bool F_56 ( struct V_64 * V_65 )
{
struct V_1 * V_2 ;
bool V_108 = false ;
F_43 () ;
V_2 = F_32 ( V_65 ) ;
if ( V_2 ) {
const struct V_115 * V_116 ;
struct V_70 * V_72 = (struct V_70 * ) V_65 ;
V_116 = F_57 ( V_72 ) ;
if ( ( V_110 ) ( V_2 -> V_33 - V_116 -> V_117 ) <= 0 ||
( ( T_1 ) F_53 () - V_2 -> V_34 > V_109 &&
V_2 -> V_34 <= ( T_1 ) V_116 -> V_118 ) ) {
V_2 -> V_34 = ( T_1 ) V_116 -> V_118 ;
V_2 -> V_33 = V_116 -> V_117 ;
}
V_108 = true ;
}
F_46 () ;
return V_108 ;
}
void F_58 ( struct V_70 * V_72 , T_2 * V_36 ,
struct V_119 * V_38 ,
int * V_37 , unsigned long * V_120 )
{
struct V_1 * V_2 ;
F_43 () ;
V_2 = F_35 ( V_72 , F_40 ( V_72 ) , false ) ;
if ( V_2 ) {
struct V_121 * V_122 = & V_2 -> V_35 ;
unsigned int V_123 ;
do {
V_123 = F_59 ( & V_124 ) ;
if ( V_122 -> V_36 )
* V_36 = V_122 -> V_36 ;
* V_38 = V_122 -> V_38 ;
* V_37 = V_122 -> V_37 ;
* V_120 = * V_37 ? V_122 -> V_120 : 0 ;
} while ( F_60 ( & V_124 , V_123 ) );
}
F_46 () ;
}
void F_61 ( struct V_70 * V_72 , T_2 V_36 ,
struct V_119 * V_38 , bool V_125 )
{
struct V_1 * V_2 ;
F_43 () ;
V_2 = F_35 ( V_72 , F_40 ( V_72 ) , true ) ;
if ( V_2 ) {
struct V_121 * V_122 = & V_2 -> V_35 ;
F_62 ( & V_124 ) ;
V_122 -> V_36 = V_36 ;
if ( V_38 -> V_39 > 0 )
V_122 -> V_38 = * V_38 ;
if ( V_125 ) {
++ V_122 -> V_37 ;
V_122 -> V_120 = V_22 ;
} else
V_122 -> V_37 = 0 ;
F_63 ( & V_124 ) ;
}
F_46 () ;
}
static int F_64 ( struct V_126 * V_127 ,
struct V_1 * V_2 )
{
struct V_128 * V_129 ;
int V_130 ;
switch ( V_2 -> V_52 . V_14 ) {
case V_15 :
if ( F_65 ( V_127 , V_131 ,
V_2 -> V_52 . V_16 . V_17 ) < 0 )
goto V_132;
break;
case V_62 :
if ( F_66 ( V_127 , V_133 , 16 ,
V_2 -> V_52 . V_16 . V_12 ) < 0 )
goto V_132;
break;
default:
return - V_134 ;
}
if ( F_67 ( V_127 , V_135 ,
V_22 - V_2 -> V_21 ) < 0 )
goto V_132;
if ( V_2 -> V_34 ) {
if ( F_68 ( V_127 , V_136 ,
( V_110 ) ( F_53 () - V_2 -> V_34 ) ) < 0 )
goto V_132;
if ( F_69 ( V_127 , V_137 ,
V_2 -> V_33 ) < 0 )
goto V_132;
}
{
int V_138 = 0 ;
V_129 = F_70 ( V_127 , V_139 ) ;
if ( ! V_129 )
goto V_132;
for ( V_130 = 0 ; V_130 < V_140 + 1 ; V_130 ++ ) {
if ( ! V_2 -> V_6 [ V_130 ] )
continue;
if ( F_69 ( V_127 , V_130 + 1 , V_2 -> V_6 [ V_130 ] ) < 0 )
goto V_132;
V_138 ++ ;
}
if ( V_138 )
F_71 ( V_127 , V_129 ) ;
else
F_72 ( V_127 , V_129 ) ;
}
{
struct V_121 V_141 [ 1 ] , * V_122 ;
unsigned int V_123 ;
do {
V_123 = F_59 ( & V_124 ) ;
V_141 [ 0 ] = V_2 -> V_35 ;
} while ( F_60 ( & V_124 , V_123 ) );
V_122 = V_141 ;
if ( V_122 -> V_36 &&
F_73 ( V_127 , V_142 ,
V_122 -> V_36 ) < 0 )
goto V_132;
if ( V_122 -> V_37 &&
( F_73 ( V_127 , V_143 ,
V_122 -> V_37 ) < 0 ||
F_67 ( V_127 , V_144 ,
V_22 - V_122 -> V_120 ) < 0 ) )
goto V_132;
if ( V_122 -> V_38 . V_39 > 0 &&
F_66 ( V_127 , V_145 ,
V_122 -> V_38 . V_39 , V_122 -> V_38 . V_7 ) < 0 )
goto V_132;
}
return 0 ;
V_132:
return - V_146 ;
}
static int F_74 ( struct V_126 * V_147 ,
struct V_148 * V_149 ,
struct V_1 * V_2 )
{
void * V_150 ;
V_150 = F_75 ( V_147 , F_76 ( V_149 -> V_147 ) . V_151 , V_149 -> V_152 -> V_153 ,
& V_154 , V_155 ,
V_156 ) ;
if ( ! V_150 )
return - V_146 ;
if ( F_64 ( V_147 , V_2 ) < 0 )
goto V_132;
return F_77 ( V_147 , V_150 ) ;
V_132:
F_78 ( V_147 , V_150 ) ;
return - V_146 ;
}
static int F_79 ( struct V_126 * V_147 ,
struct V_148 * V_149 )
{
struct V_42 * V_42 = F_80 ( V_147 -> V_72 ) ;
unsigned int V_157 = 1U << V_42 -> V_46 . V_63 ;
unsigned int V_158 , V_159 = V_149 -> args [ 0 ] ;
int V_160 = V_149 -> args [ 1 ] , V_161 = V_160 ;
for ( V_158 = V_159 ; V_158 < V_157 ; V_158 ++ , V_160 = 0 ) {
struct V_1 * V_2 ;
struct V_162 * V_163 = V_42 -> V_46 . V_47 + V_158 ;
F_43 () ;
for ( V_161 = 0 , V_2 = F_17 ( V_163 -> V_48 ) ; V_2 ;
V_2 = F_17 ( V_2 -> V_49 ) , V_161 ++ ) {
if ( V_161 < V_160 )
continue;
if ( F_74 ( V_147 , V_149 , V_2 ) < 0 ) {
F_46 () ;
goto V_164;
}
}
F_46 () ;
}
V_164:
V_149 -> args [ 0 ] = V_158 ;
V_149 -> args [ 1 ] = V_161 ;
return V_147 -> V_39 ;
}
static int F_81 ( struct V_165 * V_166 , struct V_8 * V_16 ,
unsigned int * V_40 , int V_167 )
{
struct V_128 * V_9 ;
V_9 = V_166 -> V_168 [ V_131 ] ;
if ( V_9 ) {
V_16 -> V_14 = V_15 ;
V_16 -> V_16 . V_17 = F_82 ( V_9 ) ;
* V_40 = ( V_61 unsigned int ) V_16 -> V_16 . V_17 ;
return 0 ;
}
V_9 = V_166 -> V_168 [ V_133 ] ;
if ( V_9 ) {
if ( F_83 ( V_9 ) != sizeof( struct V_11 ) )
return - V_169 ;
V_16 -> V_14 = V_62 ;
memcpy ( V_16 -> V_16 . V_12 , F_84 ( V_9 ) , sizeof( V_16 -> V_16 . V_12 ) ) ;
* V_40 = F_30 ( (struct V_11 * ) V_16 -> V_16 . V_12 ) ;
return 0 ;
}
return V_167 ? 1 : - V_134 ;
}
static int F_85 ( struct V_126 * V_147 , struct V_165 * V_166 )
{
struct V_1 * V_2 ;
struct V_8 V_16 ;
unsigned int V_40 ;
struct V_126 * V_127 ;
struct V_42 * V_42 = F_86 ( V_166 ) ;
void * V_170 ;
int V_108 ;
V_108 = F_81 ( V_166 , & V_16 , & V_40 , 0 ) ;
if ( V_108 < 0 )
return V_108 ;
V_127 = F_87 ( V_171 , V_172 ) ;
if ( ! V_127 )
return - V_173 ;
V_170 = F_88 ( V_127 , V_166 , & V_154 , 0 ,
V_166 -> V_174 -> V_175 ) ;
if ( ! V_170 )
goto V_132;
V_40 = F_31 ( V_40 , V_42 -> V_46 . V_63 ) ;
V_108 = - V_176 ;
F_43 () ;
for ( V_2 = F_17 ( V_42 -> V_46 . V_47 [ V_40 ] . V_48 ) ; V_2 ;
V_2 = F_17 ( V_2 -> V_49 ) ) {
if ( F_8 ( & V_2 -> V_52 , & V_16 ) ) {
V_108 = F_64 ( V_127 , V_2 ) ;
break;
}
}
F_46 () ;
if ( V_108 < 0 )
goto V_177;
F_77 ( V_127 , V_170 ) ;
return F_89 ( V_127 , V_166 ) ;
V_132:
V_108 = - V_146 ;
V_177:
F_90 ( V_127 ) ;
return V_108 ;
}
static int F_91 ( struct V_42 * V_42 )
{
unsigned int V_157 = 1U << V_42 -> V_46 . V_63 ;
struct V_162 * V_163 = V_42 -> V_46 . V_47 ;
struct V_1 * V_2 ;
unsigned int V_158 ;
for ( V_158 = 0 ; V_158 < V_157 ; V_158 ++ , V_163 ++ ) {
F_14 ( & V_43 ) ;
V_2 = F_92 ( V_163 -> V_48 ) ;
if ( V_2 )
V_163 -> V_48 = NULL ;
F_22 ( & V_43 ) ;
while ( V_2 ) {
struct V_1 * V_178 ;
V_178 = F_93 ( V_2 -> V_49 ) ;
F_94 ( V_2 , V_179 ) ;
V_2 = V_178 ;
}
}
return 0 ;
}
static int F_95 ( struct V_126 * V_147 , struct V_165 * V_166 )
{
struct V_162 * V_163 ;
struct V_1 * V_2 ;
struct V_1 T_3 * * V_180 ;
struct V_8 V_16 ;
unsigned int V_40 ;
struct V_42 * V_42 = F_86 ( V_166 ) ;
int V_108 ;
V_108 = F_81 ( V_166 , & V_16 , & V_40 , 1 ) ;
if ( V_108 < 0 )
return V_108 ;
if ( V_108 > 0 )
return F_91 ( V_42 ) ;
V_40 = F_31 ( V_40 , V_42 -> V_46 . V_63 ) ;
V_163 = V_42 -> V_46 . V_47 + V_40 ;
V_180 = & V_163 -> V_48 ;
F_14 ( & V_43 ) ;
for ( V_2 = F_92 ( * V_180 ) ; V_2 ;
V_180 = & V_2 -> V_49 , V_2 = F_92 ( * V_180 ) ) {
if ( F_8 ( & V_2 -> V_52 , & V_16 ) ) {
* V_180 = V_2 -> V_49 ;
break;
}
}
F_22 ( & V_43 ) ;
if ( ! V_2 )
return - V_176 ;
F_94 ( V_2 , V_179 ) ;
return 0 ;
}
static int T_4 F_96 ( char * V_181 )
{
T_5 V_108 ;
if ( ! V_181 )
return 0 ;
V_108 = F_97 ( V_181 , 0 , & V_182 ) ;
if ( V_108 )
return 0 ;
return 1 ;
}
static int T_6 F_98 ( struct V_42 * V_42 )
{
T_7 V_183 ;
unsigned int V_184 ;
V_184 = V_182 ;
if ( ! V_184 ) {
if ( V_185 >= 128 * 1024 )
V_184 = 16 * 1024 ;
else
V_184 = 8 * 1024 ;
}
V_42 -> V_46 . V_63 = F_99 ( V_184 ) ;
V_183 = sizeof( struct V_162 ) << V_42 -> V_46 . V_63 ;
V_42 -> V_46 . V_47 = F_100 ( V_183 , V_172 | V_186 ) ;
if ( ! V_42 -> V_46 . V_47 )
V_42 -> V_46 . V_47 = F_101 ( V_183 ) ;
if ( ! V_42 -> V_46 . V_47 )
return - V_173 ;
return 0 ;
}
static void T_8 F_102 ( struct V_42 * V_42 )
{
unsigned int V_130 ;
for ( V_130 = 0 ; V_130 < ( 1U << V_42 -> V_46 . V_63 ) ; V_130 ++ ) {
struct V_1 * V_2 , * V_178 ;
V_2 = F_103 ( V_42 -> V_46 . V_47 [ V_130 ] . V_48 , 1 ) ;
while ( V_2 ) {
V_178 = F_103 ( V_2 -> V_49 , 1 ) ;
F_104 ( V_2 ) ;
V_2 = V_178 ;
}
}
if ( F_105 ( V_42 -> V_46 . V_47 ) )
F_106 ( V_42 -> V_46 . V_47 ) ;
else
F_104 ( V_42 -> V_46 . V_47 ) ;
}
void T_4 F_107 ( void )
{
int V_108 ;
V_108 = F_108 ( & V_187 ) ;
if ( V_108 < 0 )
goto V_188;
V_108 = F_109 ( & V_154 ,
V_189 ,
F_110 ( V_189 ) ) ;
if ( V_108 < 0 )
goto V_190;
return;
V_190:
F_111 ( & V_187 ) ;
V_188:
return;
}
