bool F_1 ( unsigned int V_1 ,
const struct V_2 * V_3 ,
unsigned int V_4 )
{
const struct V_2 * V_5 ;
int V_6 ;
for ( V_6 = 0 , V_5 = V_3 ; V_6 < V_4 ; V_6 ++ , V_5 ++ )
if ( F_2 ( V_1 , V_5 ) )
return true ;
return false ;
}
bool F_3 ( struct V_7 * V_8 , unsigned int V_1 ,
const struct V_9 * V_10 )
{
if ( F_1 ( V_1 , V_10 -> V_11 , V_10 -> V_12 ) )
return false ;
if ( ! V_10 -> V_13 )
return true ;
return F_1 ( V_1 , V_10 -> V_14 ,
V_10 -> V_13 ) ;
}
bool F_4 ( struct V_7 * V_8 , unsigned int V_1 )
{
if ( V_8 -> V_15 && V_1 > V_8 -> V_15 )
return false ;
if ( V_8 -> V_16 )
return V_8 -> V_16 ( V_8 -> V_17 , V_1 ) ;
if ( V_8 -> V_18 )
return F_3 ( V_8 , V_1 , V_8 -> V_18 ) ;
return true ;
}
bool F_5 ( struct V_7 * V_8 , unsigned int V_1 )
{
int V_19 ;
unsigned int V_20 ;
if ( V_8 -> V_21 == V_22 )
return false ;
if ( ! V_8 -> V_23 )
return false ;
if ( V_8 -> V_15 && V_1 > V_8 -> V_15 )
return false ;
V_8 -> V_24 ( V_8 -> V_25 ) ;
V_19 = F_6 ( V_8 , V_1 , & V_20 ) ;
V_8 -> V_26 ( V_8 -> V_25 ) ;
if ( V_19 )
return false ;
return true ;
}
bool F_7 ( struct V_7 * V_8 , unsigned int V_1 )
{
if ( ! V_8 -> V_27 )
return false ;
if ( V_8 -> V_15 && V_1 > V_8 -> V_15 )
return false ;
if ( V_8 -> V_28 . V_29 )
return false ;
if ( V_8 -> V_30 )
return V_8 -> V_30 ( V_8 -> V_17 , V_1 ) ;
if ( V_8 -> V_31 )
return F_3 ( V_8 , V_1 , V_8 -> V_31 ) ;
return true ;
}
bool F_8 ( struct V_7 * V_8 , unsigned int V_1 )
{
if ( ! V_8 -> V_28 . V_29 && ! F_7 ( V_8 , V_1 ) )
return false ;
if ( V_8 -> V_32 )
return V_8 -> V_32 ( V_8 -> V_17 , V_1 ) ;
if ( V_8 -> V_33 )
return F_3 ( V_8 , V_1 , V_8 -> V_33 ) ;
if ( V_8 -> V_23 )
return false ;
else
return true ;
}
bool F_9 ( struct V_7 * V_8 , unsigned int V_1 )
{
if ( ! F_7 ( V_8 , V_1 ) )
return false ;
if ( V_8 -> V_34 )
return V_8 -> V_34 ( V_8 -> V_17 , V_1 ) ;
if ( V_8 -> V_35 )
return F_3 ( V_8 , V_1 , V_8 -> V_35 ) ;
return false ;
}
static bool F_10 ( struct V_7 * V_8 , unsigned int V_1 ,
T_1 V_36 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_36 ; V_6 ++ )
if ( ! F_8 ( V_8 , V_1 + V_6 ) )
return false ;
return true ;
}
static void F_11 ( struct V_7 * V_8 ,
unsigned int V_1 , unsigned int V_20 )
{
T_2 * V_37 = V_8 -> V_38 ;
* V_37 = ( V_1 << 6 ) | V_20 ;
}
static void F_12 ( struct V_7 * V_8 ,
unsigned int V_1 , unsigned int V_20 )
{
T_3 * V_37 = V_8 -> V_38 ;
* V_37 = F_13 ( ( V_1 << 12 ) | V_20 ) ;
}
static void F_14 ( struct V_7 * V_8 ,
unsigned int V_1 , unsigned int V_20 )
{
T_3 * V_37 = V_8 -> V_38 ;
* V_37 = F_13 ( ( V_1 << 9 ) | V_20 ) ;
}
static void F_15 ( struct V_7 * V_8 ,
unsigned int V_1 , unsigned int V_20 )
{
T_2 * V_37 = V_8 -> V_38 ;
V_37 [ 2 ] = V_20 ;
V_37 [ 1 ] = ( V_20 >> 8 ) | ( V_1 << 6 ) ;
V_37 [ 0 ] = V_1 >> 2 ;
}
static void F_16 ( void * V_39 , unsigned int V_20 , unsigned int V_40 )
{
T_2 * V_41 = V_39 ;
V_41 [ 0 ] = V_20 << V_40 ;
}
static void F_17 ( void * V_39 , unsigned int V_20 , unsigned int V_40 )
{
T_3 * V_41 = V_39 ;
V_41 [ 0 ] = F_13 ( V_20 << V_40 ) ;
}
static void F_18 ( void * V_39 , unsigned int V_20 , unsigned int V_40 )
{
T_4 * V_41 = V_39 ;
V_41 [ 0 ] = F_19 ( V_20 << V_40 ) ;
}
static void F_20 ( void * V_39 , unsigned int V_20 ,
unsigned int V_40 )
{
* ( V_42 * ) V_39 = V_20 << V_40 ;
}
static void F_21 ( void * V_39 , unsigned int V_20 , unsigned int V_40 )
{
T_2 * V_41 = V_39 ;
V_20 <<= V_40 ;
V_41 [ 0 ] = V_20 >> 16 ;
V_41 [ 1 ] = V_20 >> 8 ;
V_41 [ 2 ] = V_20 ;
}
static void F_22 ( void * V_39 , unsigned int V_20 , unsigned int V_40 )
{
T_5 * V_41 = V_39 ;
V_41 [ 0 ] = F_23 ( V_20 << V_40 ) ;
}
static void F_24 ( void * V_39 , unsigned int V_20 , unsigned int V_40 )
{
T_6 * V_41 = V_39 ;
V_41 [ 0 ] = F_25 ( V_20 << V_40 ) ;
}
static void F_26 ( void * V_39 , unsigned int V_20 ,
unsigned int V_40 )
{
* ( V_43 * ) V_39 = V_20 << V_40 ;
}
static void F_27 ( void * V_39 , unsigned int V_20 , unsigned int V_40 )
{
T_7 * V_41 = V_39 ;
V_41 [ 0 ] = F_28 ( ( V_44 ) V_20 << V_40 ) ;
}
static void F_29 ( void * V_39 , unsigned int V_20 , unsigned int V_40 )
{
T_8 * V_41 = V_39 ;
V_41 [ 0 ] = F_30 ( ( V_44 ) V_20 << V_40 ) ;
}
static void F_31 ( void * V_39 , unsigned int V_20 ,
unsigned int V_40 )
{
* ( V_44 * ) V_39 = ( V_44 ) V_20 << V_40 ;
}
static void F_32 ( void * V_39 )
{
}
static unsigned int F_33 ( const void * V_39 )
{
const T_2 * V_41 = V_39 ;
return V_41 [ 0 ] ;
}
static unsigned int F_34 ( const void * V_39 )
{
const T_3 * V_41 = V_39 ;
return F_35 ( V_41 [ 0 ] ) ;
}
static unsigned int F_36 ( const void * V_39 )
{
const T_4 * V_41 = V_39 ;
return F_37 ( V_41 [ 0 ] ) ;
}
static void F_38 ( void * V_39 )
{
T_3 * V_41 = V_39 ;
V_41 [ 0 ] = F_35 ( V_41 [ 0 ] ) ;
}
static void F_39 ( void * V_39 )
{
T_4 * V_41 = V_39 ;
V_41 [ 0 ] = F_37 ( V_41 [ 0 ] ) ;
}
static unsigned int F_40 ( const void * V_39 )
{
return * ( V_42 * ) V_39 ;
}
static unsigned int F_41 ( const void * V_39 )
{
const T_2 * V_41 = V_39 ;
unsigned int V_19 = V_41 [ 2 ] ;
V_19 |= ( ( unsigned int ) V_41 [ 1 ] ) << 8 ;
V_19 |= ( ( unsigned int ) V_41 [ 0 ] ) << 16 ;
return V_19 ;
}
static unsigned int F_42 ( const void * V_39 )
{
const T_5 * V_41 = V_39 ;
return F_43 ( V_41 [ 0 ] ) ;
}
static unsigned int F_44 ( const void * V_39 )
{
const T_6 * V_41 = V_39 ;
return F_45 ( V_41 [ 0 ] ) ;
}
static void F_46 ( void * V_39 )
{
T_5 * V_41 = V_39 ;
V_41 [ 0 ] = F_43 ( V_41 [ 0 ] ) ;
}
static void F_47 ( void * V_39 )
{
T_6 * V_41 = V_39 ;
V_41 [ 0 ] = F_45 ( V_41 [ 0 ] ) ;
}
static unsigned int F_48 ( const void * V_39 )
{
return * ( V_43 * ) V_39 ;
}
static unsigned int F_49 ( const void * V_39 )
{
const T_7 * V_41 = V_39 ;
return F_50 ( V_41 [ 0 ] ) ;
}
static unsigned int F_51 ( const void * V_39 )
{
const T_8 * V_41 = V_39 ;
return F_52 ( V_41 [ 0 ] ) ;
}
static void F_53 ( void * V_39 )
{
T_7 * V_41 = V_39 ;
V_41 [ 0 ] = F_50 ( V_41 [ 0 ] ) ;
}
static void F_54 ( void * V_39 )
{
T_8 * V_41 = V_39 ;
V_41 [ 0 ] = F_52 ( V_41 [ 0 ] ) ;
}
static unsigned int F_55 ( const void * V_39 )
{
return * ( V_44 * ) V_39 ;
}
static void F_56 ( void * V_45 )
{
struct V_7 * V_8 = V_45 ;
F_57 ( & V_8 -> V_46 ) ;
}
static void F_58 ( void * V_45 )
{
struct V_7 * V_8 = V_45 ;
F_59 ( & V_8 -> V_46 ) ;
}
static void F_60 ( void * V_45 )
__acquires( &map->spinlock
static void F_61 ( void * V_45 )
__releases( &map->spinlock
static void F_62 ( struct V_47 * V_17 , void * V_48 )
{
}
static bool F_63 ( struct V_7 * V_8 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = & V_8 -> V_53 ;
struct V_54 * * V_55 = & ( V_52 -> V_54 ) , * V_56 = NULL ;
while ( * V_55 ) {
struct V_49 * V_57 =
F_64 ( * V_55 , struct V_49 , V_58 ) ;
V_56 = * V_55 ;
if ( V_50 -> V_59 < V_57 -> V_60 )
V_55 = & ( ( * V_55 ) -> V_61 ) ;
else if ( V_50 -> V_60 > V_57 -> V_59 )
V_55 = & ( ( * V_55 ) -> V_62 ) ;
else
return false ;
}
F_65 ( & V_50 -> V_58 , V_56 , V_55 ) ;
F_66 ( & V_50 -> V_58 , V_52 ) ;
return true ;
}
static struct V_49 * F_67 ( struct V_7 * V_8 ,
unsigned int V_1 )
{
struct V_54 * V_58 = V_8 -> V_53 . V_54 ;
while ( V_58 ) {
struct V_49 * V_57 =
F_64 ( V_58 , struct V_49 , V_58 ) ;
if ( V_1 < V_57 -> V_60 )
V_58 = V_58 -> V_61 ;
else if ( V_1 > V_57 -> V_59 )
V_58 = V_58 -> V_62 ;
else
return V_57 ;
}
return NULL ;
}
static void F_68 ( struct V_7 * V_8 )
{
struct V_54 * V_63 ;
struct V_49 * V_64 ;
V_63 = F_69 ( & V_8 -> V_53 ) ;
while ( V_63 ) {
V_64 = F_64 ( V_63 , struct V_49 , V_58 ) ;
V_63 = F_70 ( & V_64 -> V_58 ) ;
F_71 ( & V_64 -> V_58 , & V_8 -> V_53 ) ;
F_72 ( V_64 ) ;
}
F_72 ( V_8 -> V_65 ) ;
}
int F_73 ( struct V_47 * V_17 , struct V_7 * V_8 ,
const struct V_66 * V_67 )
{
struct V_7 * * V_68 ;
V_8 -> V_17 = V_17 ;
F_74 ( V_8 , V_67 -> V_69 ) ;
V_68 = F_75 ( F_62 , sizeof( * V_68 ) , V_70 ) ;
if ( ! V_68 ) {
F_76 ( V_8 ) ;
return - V_71 ;
}
* V_68 = V_8 ;
F_77 ( V_17 , V_68 ) ;
return 0 ;
}
static enum V_72 F_78 ( const struct V_73 * V_74 ,
const struct V_66 * V_67 )
{
enum V_72 V_75 ;
V_75 = V_67 -> V_76 ;
if ( V_75 != V_77 )
return V_75 ;
if ( V_74 && V_74 -> V_78 )
V_75 = V_74 -> V_78 ;
if ( V_75 != V_77 )
return V_75 ;
return V_79 ;
}
enum V_72 F_79 ( struct V_47 * V_17 ,
const struct V_73 * V_74 ,
const struct V_66 * V_67 )
{
struct V_80 * V_81 ;
enum V_72 V_75 ;
V_75 = V_67 -> V_82 ;
if ( V_75 != V_77 )
return V_75 ;
if ( V_17 && V_17 -> V_83 ) {
V_81 = V_17 -> V_83 ;
if ( F_80 ( V_81 , L_1 ) )
V_75 = V_79 ;
else if ( F_80 ( V_81 , L_2 ) )
V_75 = V_84 ;
else if ( F_80 ( V_81 , L_3 ) )
V_75 = V_85 ;
if ( V_75 != V_77 )
return V_75 ;
}
if ( V_74 && V_74 -> V_86 )
V_75 = V_74 -> V_86 ;
if ( V_75 != V_77 )
return V_75 ;
return V_79 ;
}
struct V_7 * F_81 ( struct V_47 * V_17 ,
const struct V_73 * V_74 ,
void * V_87 ,
const struct V_66 * V_67 ,
struct V_88 * V_89 ,
const char * V_90 )
{
struct V_7 * V_8 ;
int V_19 = - V_91 ;
enum V_72 V_92 , V_93 ;
int V_6 , V_94 ;
if ( ! V_67 )
goto V_95;
V_8 = F_82 ( sizeof( * V_8 ) , V_70 ) ;
if ( V_8 == NULL ) {
V_19 = - V_71 ;
goto V_95;
}
if ( V_67 -> V_24 && V_67 -> V_26 ) {
V_8 -> V_24 = V_67 -> V_24 ;
V_8 -> V_26 = V_67 -> V_26 ;
V_8 -> V_25 = V_67 -> V_25 ;
} else {
if ( ( V_74 && V_74 -> V_96 ) ||
V_67 -> V_96 ) {
F_83 ( & V_8 -> V_97 ) ;
V_8 -> V_24 = F_60 ;
V_8 -> V_26 = F_61 ;
F_84 ( & V_8 -> V_97 ,
V_89 , V_90 ) ;
} else {
F_85 ( & V_8 -> V_46 ) ;
V_8 -> V_24 = F_56 ;
V_8 -> V_26 = F_58 ;
F_84 ( & V_8 -> V_46 ,
V_89 , V_90 ) ;
}
V_8 -> V_25 = V_8 ;
}
if ( ( V_74 && V_74 -> V_96 ) || V_67 -> V_96 )
V_8 -> V_98 = V_99 ;
else
V_8 -> V_98 = V_70 ;
V_8 -> V_28 . V_100 = F_86 ( V_67 -> V_101 , 8 ) ;
V_8 -> V_28 . V_102 = V_67 -> V_103 / 8 ;
V_8 -> V_28 . V_104 = F_86 ( V_67 -> V_105 , 8 ) ;
V_8 -> V_28 . V_106 = F_86 ( V_67 -> V_101 +
V_67 -> V_105 + V_67 -> V_103 , 8 ) ;
V_8 -> V_107 = V_67 -> V_103 % 8 ;
if ( V_67 -> V_108 )
V_8 -> V_108 = V_67 -> V_108 ;
else
V_8 -> V_108 = 1 ;
if ( F_87 ( V_8 -> V_108 ) )
V_8 -> V_109 = F_88 ( V_8 -> V_108 ) ;
else
V_8 -> V_109 = - 1 ;
V_8 -> V_110 = V_67 -> V_111 || ! V_74 || ! V_74 -> V_112 ;
V_8 -> V_113 = V_67 -> V_111 || ! V_74 || ! V_74 -> V_114 ;
V_8 -> V_115 = V_67 -> V_115 && V_74 && V_74 -> V_114 ;
if ( V_74 ) {
V_8 -> V_116 = V_74 -> V_116 ;
V_8 -> V_117 = V_74 -> V_117 ;
}
V_8 -> V_17 = V_17 ;
V_8 -> V_74 = V_74 ;
V_8 -> V_87 = V_87 ;
V_8 -> V_15 = V_67 -> V_15 ;
V_8 -> V_18 = V_67 -> V_18 ;
V_8 -> V_31 = V_67 -> V_31 ;
V_8 -> V_33 = V_67 -> V_33 ;
V_8 -> V_35 = V_67 -> V_35 ;
V_8 -> V_16 = V_67 -> V_16 ;
V_8 -> V_30 = V_67 -> V_30 ;
V_8 -> V_32 = V_67 -> V_32 ;
V_8 -> V_34 = V_67 -> V_34 ;
V_8 -> V_118 = V_67 -> V_118 ;
V_8 -> V_69 = V_67 -> V_69 ;
F_83 ( & V_8 -> V_119 ) ;
F_89 ( & V_8 -> V_120 ) ;
F_89 ( & V_8 -> V_121 ) ;
F_90 ( & V_8 -> V_122 ) ;
if ( V_67 -> V_123 || V_67 -> V_124 ) {
V_8 -> V_123 = V_67 -> V_123 ;
V_8 -> V_124 = V_67 -> V_124 ;
} else if ( V_74 ) {
V_8 -> V_123 = V_74 -> V_123 ;
}
if ( ! V_74 ) {
V_8 -> V_27 = V_67 -> V_27 ;
V_8 -> V_125 = V_67 -> V_125 ;
V_8 -> V_126 = false ;
goto V_127;
} else if ( ! V_74 -> V_112 || ! V_74 -> V_114 ) {
V_8 -> V_27 = V_128 ;
V_8 -> V_125 = V_129 ;
V_8 -> V_126 = false ;
goto V_127;
} else {
V_8 -> V_27 = V_130 ;
V_8 -> V_131 = V_74 -> V_131 ;
}
V_92 = F_78 ( V_74 , V_67 ) ;
V_93 = F_79 ( V_17 , V_74 , V_67 ) ;
switch ( V_67 -> V_101 + V_8 -> V_107 ) {
case 2 :
switch ( V_67 -> V_105 ) {
case 6 :
V_8 -> V_28 . V_29 = F_11 ;
break;
default:
goto V_132;
}
break;
case 4 :
switch ( V_67 -> V_105 ) {
case 12 :
V_8 -> V_28 . V_29 = F_12 ;
break;
default:
goto V_132;
}
break;
case 7 :
switch ( V_67 -> V_105 ) {
case 9 :
V_8 -> V_28 . V_29 = F_14 ;
break;
default:
goto V_132;
}
break;
case 10 :
switch ( V_67 -> V_105 ) {
case 14 :
V_8 -> V_28 . V_29 = F_15 ;
break;
default:
goto V_132;
}
break;
case 8 :
V_8 -> V_28 . V_133 = F_16 ;
break;
case 16 :
switch ( V_92 ) {
case V_79 :
V_8 -> V_28 . V_133 = F_17 ;
break;
case V_84 :
V_8 -> V_28 . V_133 = F_18 ;
break;
case V_85 :
V_8 -> V_28 . V_133 = F_20 ;
break;
default:
goto V_132;
}
break;
case 24 :
if ( V_92 != V_79 )
goto V_132;
V_8 -> V_28 . V_133 = F_21 ;
break;
case 32 :
switch ( V_92 ) {
case V_79 :
V_8 -> V_28 . V_133 = F_22 ;
break;
case V_84 :
V_8 -> V_28 . V_133 = F_24 ;
break;
case V_85 :
V_8 -> V_28 . V_133 = F_26 ;
break;
default:
goto V_132;
}
break;
#ifdef F_91
case 64 :
switch ( V_92 ) {
case V_79 :
V_8 -> V_28 . V_133 = F_27 ;
break;
case V_84 :
V_8 -> V_28 . V_133 = F_29 ;
break;
case V_85 :
V_8 -> V_28 . V_133 = F_31 ;
break;
default:
goto V_132;
}
break;
#endif
default:
goto V_132;
}
if ( V_93 == V_85 )
V_8 -> V_28 . V_134 = F_32 ;
switch ( V_67 -> V_105 ) {
case 8 :
V_8 -> V_28 . V_135 = F_16 ;
V_8 -> V_28 . V_136 = F_33 ;
V_8 -> V_28 . V_134 = F_32 ;
break;
case 16 :
switch ( V_93 ) {
case V_79 :
V_8 -> V_28 . V_135 = F_17 ;
V_8 -> V_28 . V_136 = F_34 ;
V_8 -> V_28 . V_134 = F_38 ;
break;
case V_84 :
V_8 -> V_28 . V_135 = F_18 ;
V_8 -> V_28 . V_136 = F_36 ;
V_8 -> V_28 . V_134 = F_39 ;
break;
case V_85 :
V_8 -> V_28 . V_135 = F_20 ;
V_8 -> V_28 . V_136 = F_40 ;
break;
default:
goto V_132;
}
break;
case 24 :
if ( V_93 != V_79 )
goto V_132;
V_8 -> V_28 . V_135 = F_21 ;
V_8 -> V_28 . V_136 = F_41 ;
break;
case 32 :
switch ( V_93 ) {
case V_79 :
V_8 -> V_28 . V_135 = F_22 ;
V_8 -> V_28 . V_136 = F_42 ;
V_8 -> V_28 . V_134 = F_46 ;
break;
case V_84 :
V_8 -> V_28 . V_135 = F_24 ;
V_8 -> V_28 . V_136 = F_44 ;
V_8 -> V_28 . V_134 = F_47 ;
break;
case V_85 :
V_8 -> V_28 . V_135 = F_26 ;
V_8 -> V_28 . V_136 = F_48 ;
break;
default:
goto V_132;
}
break;
#ifdef F_91
case 64 :
switch ( V_93 ) {
case V_79 :
V_8 -> V_28 . V_135 = F_27 ;
V_8 -> V_28 . V_136 = F_49 ;
V_8 -> V_28 . V_134 = F_53 ;
break;
case V_84 :
V_8 -> V_28 . V_135 = F_29 ;
V_8 -> V_28 . V_136 = F_51 ;
V_8 -> V_28 . V_134 = F_54 ;
break;
case V_85 :
V_8 -> V_28 . V_135 = F_31 ;
V_8 -> V_28 . V_136 = F_55 ;
break;
default:
goto V_132;
}
break;
#endif
}
if ( V_8 -> V_28 . V_29 ) {
if ( ( V_92 != V_79 ) ||
( V_93 != V_79 ) )
goto V_132;
V_8 -> V_113 = true ;
}
if ( ! V_8 -> V_28 . V_29 &&
! ( V_8 -> V_28 . V_133 && V_8 -> V_28 . V_135 ) )
goto V_132;
V_8 -> V_38 = F_82 ( V_8 -> V_28 . V_106 , V_70 ) ;
if ( V_8 -> V_38 == NULL ) {
V_19 = - V_71 ;
goto V_132;
}
if ( V_8 -> V_28 . V_29 ) {
V_8 -> V_126 = false ;
V_8 -> V_125 = V_137 ;
} else if ( V_8 -> V_28 . V_135 ) {
V_8 -> V_126 = true ;
V_8 -> V_125 = V_138 ;
}
V_127:
V_8 -> V_53 = V_139 ;
for ( V_6 = 0 ; V_6 < V_67 -> V_140 ; V_6 ++ ) {
const struct V_141 * V_142 = & V_67 -> V_3 [ V_6 ] ;
struct V_49 * V_55 ;
if ( V_142 -> V_59 < V_142 -> V_60 ) {
F_92 ( V_8 -> V_17 , L_4 , V_6 ,
V_142 -> V_59 , V_142 -> V_60 ) ;
goto V_143;
}
if ( V_142 -> V_59 > V_8 -> V_15 ) {
F_92 ( V_8 -> V_17 , L_5 , V_6 ,
V_142 -> V_59 , V_8 -> V_15 ) ;
goto V_143;
}
if ( V_142 -> V_144 > V_8 -> V_15 ) {
F_92 ( V_8 -> V_17 ,
L_6 , V_6 ) ;
goto V_143;
}
if ( V_142 -> V_145 == 0 ) {
F_92 ( V_8 -> V_17 , L_7 ,
V_6 ) ;
goto V_143;
}
for ( V_94 = 0 ; V_94 < V_67 -> V_140 ; V_94 ++ ) {
unsigned V_146 = V_67 -> V_3 [ V_94 ] . V_144 ;
unsigned V_147 = V_67 -> V_3 [ V_94 ] . V_148 ;
unsigned V_149 = V_147 +
V_67 -> V_3 [ V_94 ] . V_145 - 1 ;
if ( V_94 == V_6 )
continue;
if ( V_142 -> V_60 <= V_146 &&
V_146 <= V_142 -> V_59 ) {
F_92 ( V_8 -> V_17 ,
L_8 ,
V_6 , V_94 ) ;
goto V_143;
}
if ( ! ( V_149 < V_142 -> V_60 ||
V_147 > V_142 -> V_59 ) ) {
F_92 ( V_8 -> V_17 ,
L_9 ,
V_6 , V_94 ) ;
goto V_143;
}
}
V_55 = F_82 ( sizeof( * V_55 ) , V_70 ) ;
if ( V_55 == NULL ) {
V_19 = - V_71 ;
goto V_143;
}
V_55 -> V_8 = V_8 ;
V_55 -> V_69 = V_142 -> V_69 ;
V_55 -> V_60 = V_142 -> V_60 ;
V_55 -> V_59 = V_142 -> V_59 ;
V_55 -> V_144 = V_142 -> V_144 ;
V_55 -> V_150 = V_142 -> V_150 ;
V_55 -> V_151 = V_142 -> V_151 ;
V_55 -> V_148 = V_142 -> V_148 ;
V_55 -> V_145 = V_142 -> V_145 ;
if ( ! F_63 ( V_8 , V_55 ) ) {
F_92 ( V_8 -> V_17 , L_10 , V_6 ) ;
F_72 ( V_55 ) ;
goto V_143;
}
if ( V_8 -> V_65 == NULL ) {
V_8 -> V_65 =
F_82 ( V_8 -> V_28 . V_106 , V_70 ) ;
if ( V_8 -> V_65 == NULL ) {
V_19 = - V_71 ;
goto V_143;
}
}
}
V_19 = F_93 ( V_8 , V_67 ) ;
if ( V_19 != 0 )
goto V_143;
if ( V_17 ) {
V_19 = F_73 ( V_17 , V_8 , V_67 ) ;
if ( V_19 != 0 )
goto V_152;
}
return V_8 ;
V_152:
F_94 ( V_8 ) ;
V_143:
F_68 ( V_8 ) ;
F_72 ( V_8 -> V_38 ) ;
V_132:
F_72 ( V_8 ) ;
V_95:
return F_95 ( V_19 ) ;
}
static void F_96 ( struct V_47 * V_17 , void * V_48 )
{
F_97 ( * (struct V_7 * * ) V_48 ) ;
}
struct V_7 * F_98 ( struct V_47 * V_17 ,
const struct V_73 * V_74 ,
void * V_87 ,
const struct V_66 * V_67 ,
struct V_88 * V_89 ,
const char * V_90 )
{
struct V_7 * * V_153 , * V_7 ;
V_153 = F_75 ( F_96 , sizeof( * V_153 ) , V_70 ) ;
if ( ! V_153 )
return F_95 ( - V_71 ) ;
V_7 = F_81 ( V_17 , V_74 , V_87 , V_67 ,
V_89 , V_90 ) ;
if ( ! F_99 ( V_7 ) ) {
* V_153 = V_7 ;
F_77 ( V_17 , V_153 ) ;
} else {
F_100 ( V_153 ) ;
}
return V_7 ;
}
static void F_101 ( struct V_154 * V_155 ,
struct V_7 * V_7 , struct V_156 V_156 )
{
V_155 -> V_7 = V_7 ;
V_155 -> V_1 = V_156 . V_1 ;
V_155 -> V_40 = V_156 . V_157 ;
V_155 -> V_158 = F_102 ( V_156 . V_159 , V_156 . V_157 ) ;
V_155 -> V_160 = V_156 . V_160 ;
V_155 -> V_161 = V_156 . V_161 ;
}
struct V_154 * F_103 ( struct V_47 * V_17 ,
struct V_7 * V_7 , struct V_156 V_156 )
{
struct V_154 * V_155 = F_104 ( V_17 ,
sizeof( * V_155 ) , V_70 ) ;
if ( ! V_155 )
return F_95 ( - V_71 ) ;
F_101 ( V_155 , V_7 , V_156 ) ;
return V_155 ;
}
void F_105 ( struct V_47 * V_17 ,
struct V_154 * V_162 )
{
F_106 ( V_17 , V_162 ) ;
}
struct V_154 * F_107 ( struct V_7 * V_7 ,
struct V_156 V_156 )
{
struct V_154 * V_155 = F_82 ( sizeof( * V_155 ) , V_70 ) ;
if ( ! V_155 )
return F_95 ( - V_71 ) ;
F_101 ( V_155 , V_7 , V_156 ) ;
return V_155 ;
}
void F_108 ( struct V_154 * V_162 )
{
F_72 ( V_162 ) ;
}
int F_109 ( struct V_7 * V_8 , const struct V_66 * V_67 )
{
F_94 ( V_8 ) ;
F_76 ( V_8 ) ;
V_8 -> V_15 = V_67 -> V_15 ;
V_8 -> V_16 = V_67 -> V_16 ;
V_8 -> V_30 = V_67 -> V_30 ;
V_8 -> V_32 = V_67 -> V_32 ;
V_8 -> V_34 = V_67 -> V_34 ;
V_8 -> V_118 = V_67 -> V_118 ;
F_74 ( V_8 , V_67 -> V_69 ) ;
V_8 -> V_163 = false ;
V_8 -> V_164 = false ;
return F_93 ( V_8 , V_67 ) ;
}
void F_97 ( struct V_7 * V_8 )
{
struct V_165 * V_166 ;
F_94 ( V_8 ) ;
F_76 ( V_8 ) ;
F_68 ( V_8 ) ;
if ( V_8 -> V_74 && V_8 -> V_74 -> V_167 )
V_8 -> V_74 -> V_167 ( V_8 -> V_87 ) ;
F_72 ( V_8 -> V_38 ) ;
while ( ! F_110 ( & V_8 -> V_121 ) ) {
V_166 = F_111 ( & V_8 -> V_121 ,
struct V_165 ,
V_168 ) ;
F_112 ( & V_166 -> V_168 ) ;
F_72 ( V_166 -> V_38 ) ;
F_72 ( V_166 ) ;
}
F_72 ( V_8 ) ;
}
static int F_113 ( struct V_47 * V_17 , void * V_48 , void * V_50 )
{
struct V_7 * * V_5 = V_48 ;
if ( ! V_5 || ! * V_5 ) {
F_114 ( ! V_5 || ! * V_5 ) ;
return 0 ;
}
if ( V_50 )
return ( * V_5 ) -> V_69 == V_50 ;
else
return 1 ;
}
struct V_7 * F_115 ( struct V_47 * V_17 , const char * V_69 )
{
struct V_7 * * V_5 = F_116 ( V_17 , F_62 ,
F_113 , ( void * ) V_69 ) ;
if ( ! V_5 )
return NULL ;
return * V_5 ;
}
struct V_47 * F_117 ( struct V_7 * V_8 )
{
return V_8 -> V_17 ;
}
static int F_118 ( struct V_7 * V_8 , unsigned int * V_1 ,
struct V_49 * V_169 ,
unsigned int V_170 )
{
void * V_171 ;
unsigned int V_172 ;
unsigned int V_173 ;
bool V_174 ;
int V_19 ;
V_172 = ( * V_1 - V_169 -> V_60 ) % V_169 -> V_145 ;
V_173 = ( * V_1 - V_169 -> V_60 ) / V_169 -> V_145 ;
if ( V_170 > 1 ) {
if ( * V_1 + V_170 - 1 > V_169 -> V_59 )
return - V_91 ;
if ( V_170 > V_169 -> V_145 - V_172 )
return - V_91 ;
}
if ( V_170 > 1 ||
V_169 -> V_148 + V_172 != V_169 -> V_144 ) {
V_171 = V_8 -> V_38 ;
V_8 -> V_38 = V_8 -> V_65 ;
V_19 = F_119 ( V_8 , V_169 -> V_144 ,
V_169 -> V_150 ,
V_173 << V_169 -> V_151 ,
& V_174 , false ) ;
V_8 -> V_38 = V_171 ;
if ( V_19 != 0 )
return V_19 ;
}
* V_1 = V_169 -> V_148 + V_172 ;
return 0 ;
}
static void F_120 ( struct V_7 * V_8 , int V_175 ,
unsigned long V_158 )
{
T_2 * V_39 ;
int V_6 ;
if ( ! V_158 || ! V_8 -> V_38 )
return;
V_39 = V_8 -> V_38 ;
for ( V_6 = 0 ; V_6 < V_175 ; V_6 ++ )
V_39 [ V_6 ] |= ( V_158 >> ( 8 * V_6 ) ) & 0xff ;
}
int F_121 ( struct V_7 * V_8 , unsigned int V_1 ,
const void * V_20 , T_1 V_176 )
{
struct V_49 * V_169 ;
unsigned long V_177 ;
void * V_178 = V_8 -> V_38 + V_8 -> V_28 . V_100 +
V_8 -> V_28 . V_102 ;
void * V_39 ;
int V_19 = - V_179 ;
T_1 V_180 ;
int V_6 ;
F_114 ( ! V_8 -> V_74 ) ;
if ( V_8 -> V_16 )
for ( V_6 = 0 ; V_6 < V_176 / V_8 -> V_28 . V_104 ; V_6 ++ )
if ( ! V_8 -> V_16 ( V_8 -> V_17 ,
V_1 + F_122 ( V_8 , V_6 ) ) )
return - V_91 ;
if ( ! V_8 -> V_163 && V_8 -> V_28 . V_136 ) {
unsigned int V_181 ;
int V_104 = V_8 -> V_28 . V_104 ;
for ( V_6 = 0 ; V_6 < V_176 / V_104 ; V_6 ++ ) {
V_181 = V_8 -> V_28 . V_136 ( V_20 + ( V_6 * V_104 ) ) ;
V_19 = F_123 ( V_8 ,
V_1 + F_122 ( V_8 , V_6 ) ,
V_181 ) ;
if ( V_19 ) {
F_92 ( V_8 -> V_17 ,
L_11 ,
V_1 + V_6 , V_19 ) ;
return V_19 ;
}
}
if ( V_8 -> V_164 ) {
V_8 -> V_182 = true ;
return 0 ;
}
}
V_169 = F_67 ( V_8 , V_1 ) ;
if ( V_169 ) {
int V_170 = V_176 / V_8 -> V_28 . V_104 ;
int V_172 = ( V_1 - V_169 -> V_60 ) % V_169 -> V_145 ;
int V_183 = V_169 -> V_145 - V_172 ;
while ( V_170 > V_183 ) {
F_124 ( V_8 -> V_17 , L_12 ,
V_183 , V_176 / V_8 -> V_28 . V_104 ) ;
V_19 = F_121 ( V_8 , V_1 , V_20 , V_183 *
V_8 -> V_28 . V_104 ) ;
if ( V_19 != 0 )
return V_19 ;
V_1 += V_183 ;
V_170 -= V_183 ;
V_20 += V_183 * V_8 -> V_28 . V_104 ;
V_176 -= V_183 * V_8 -> V_28 . V_104 ;
V_172 = ( V_1 - V_169 -> V_60 ) %
V_169 -> V_145 ;
V_183 = V_169 -> V_145 - V_172 ;
}
V_19 = F_118 ( V_8 , & V_1 , V_169 , V_170 ) ;
if ( V_19 != 0 )
return V_19 ;
}
V_8 -> V_28 . V_133 ( V_8 -> V_38 , V_1 , V_8 -> V_107 ) ;
F_120 ( V_8 , V_8 -> V_28 . V_100 ,
V_8 -> V_124 ) ;
if ( V_20 != V_178 && V_176 == V_8 -> V_28 . V_104 ) {
memcpy ( V_178 , V_20 , V_8 -> V_28 . V_104 ) ;
V_20 = V_178 ;
}
if ( V_8 -> V_166 && V_8 -> V_74 -> V_184 ) {
struct V_165 * V_166 ;
F_125 ( V_8 , V_1 , V_176 ) ;
F_126 ( & V_8 -> V_119 , V_177 ) ;
V_166 = F_111 ( & V_8 -> V_121 ,
struct V_165 ,
V_168 ) ;
if ( V_166 )
F_112 ( & V_166 -> V_168 ) ;
F_127 ( & V_8 -> V_119 , V_177 ) ;
if ( ! V_166 ) {
V_166 = V_8 -> V_74 -> V_185 () ;
if ( ! V_166 )
return - V_71 ;
V_166 -> V_38 = F_82 ( V_8 -> V_28 . V_106 ,
V_70 | V_186 ) ;
if ( ! V_166 -> V_38 ) {
F_72 ( V_166 ) ;
return - V_71 ;
}
}
V_166 -> V_8 = V_8 ;
memcpy ( V_166 -> V_38 , V_8 -> V_38 , V_8 -> V_28 . V_102 +
V_8 -> V_28 . V_100 + V_8 -> V_28 . V_104 ) ;
F_126 ( & V_8 -> V_119 , V_177 ) ;
F_128 ( & V_166 -> V_168 , & V_8 -> V_120 ) ;
F_127 ( & V_8 -> V_119 , V_177 ) ;
if ( V_20 != V_178 )
V_19 = V_8 -> V_74 -> V_184 ( V_8 -> V_87 ,
V_166 -> V_38 ,
V_8 -> V_28 . V_100 +
V_8 -> V_28 . V_102 ,
V_20 , V_176 , V_166 ) ;
else
V_19 = V_8 -> V_74 -> V_184 ( V_8 -> V_87 ,
V_166 -> V_38 ,
V_8 -> V_28 . V_100 +
V_8 -> V_28 . V_102 +
V_176 , NULL , 0 , V_166 ) ;
if ( V_19 != 0 ) {
F_92 ( V_8 -> V_17 , L_13 ,
V_19 ) ;
F_126 ( & V_8 -> V_119 , V_177 ) ;
F_129 ( & V_166 -> V_168 , & V_8 -> V_121 ) ;
F_127 ( & V_8 -> V_119 , V_177 ) ;
}
return V_19 ;
}
F_130 ( V_8 , V_1 , V_176 / V_8 -> V_28 . V_104 ) ;
if ( V_20 == V_178 )
V_19 = V_8 -> V_74 -> V_114 ( V_8 -> V_87 , V_8 -> V_38 ,
V_8 -> V_28 . V_100 +
V_8 -> V_28 . V_102 +
V_176 ) ;
else if ( V_8 -> V_74 -> V_187 )
V_19 = V_8 -> V_74 -> V_187 ( V_8 -> V_87 , V_8 -> V_38 ,
V_8 -> V_28 . V_100 +
V_8 -> V_28 . V_102 ,
V_20 , V_176 ) ;
if ( V_19 == - V_179 ) {
V_180 = V_8 -> V_28 . V_100 + V_8 -> V_28 . V_102 + V_176 ;
V_39 = F_82 ( V_180 , V_70 ) ;
if ( ! V_39 )
return - V_71 ;
memcpy ( V_39 , V_8 -> V_38 , V_8 -> V_28 . V_100 ) ;
memcpy ( V_39 + V_8 -> V_28 . V_100 + V_8 -> V_28 . V_102 ,
V_20 , V_176 ) ;
V_19 = V_8 -> V_74 -> V_114 ( V_8 -> V_87 , V_39 , V_180 ) ;
F_72 ( V_39 ) ;
} else if ( V_19 != 0 && ! V_8 -> V_163 && V_8 -> V_28 . V_136 ) {
if ( V_8 -> V_23 && V_8 -> V_23 -> V_188 )
V_8 -> V_23 -> V_188 ( V_8 , V_1 , V_1 + 1 ) ;
}
F_131 ( V_8 , V_1 , V_176 / V_8 -> V_28 . V_104 ) ;
return V_19 ;
}
bool F_132 ( struct V_7 * V_8 )
{
return V_8 -> V_74 && V_8 -> V_74 -> V_114 && V_8 -> V_28 . V_135 &&
V_8 -> V_28 . V_133 ;
}
T_1 F_133 ( struct V_7 * V_8 )
{
return V_8 -> V_116 ;
}
T_1 F_134 ( struct V_7 * V_8 )
{
return V_8 -> V_117 ;
}
static int V_137 ( void * V_189 , unsigned int V_1 ,
unsigned int V_20 )
{
int V_19 ;
struct V_49 * V_169 ;
struct V_7 * V_8 = V_189 ;
F_114 ( ! V_8 -> V_74 || ! V_8 -> V_28 . V_29 ) ;
V_169 = F_67 ( V_8 , V_1 ) ;
if ( V_169 ) {
V_19 = F_118 ( V_8 , & V_1 , V_169 , 1 ) ;
if ( V_19 != 0 )
return V_19 ;
}
V_8 -> V_28 . V_29 ( V_8 , V_1 , V_20 ) ;
F_130 ( V_8 , V_1 , 1 ) ;
V_19 = V_8 -> V_74 -> V_114 ( V_8 -> V_87 , V_8 -> V_38 ,
V_8 -> V_28 . V_106 ) ;
F_131 ( V_8 , V_1 , 1 ) ;
return V_19 ;
}
static int V_129 ( void * V_189 , unsigned int V_1 ,
unsigned int V_20 )
{
struct V_7 * V_8 = V_189 ;
return V_8 -> V_74 -> V_125 ( V_8 -> V_87 , V_1 , V_20 ) ;
}
static int V_138 ( void * V_189 , unsigned int V_1 ,
unsigned int V_20 )
{
struct V_7 * V_8 = V_189 ;
F_114 ( ! V_8 -> V_74 || ! V_8 -> V_28 . V_135 ) ;
V_8 -> V_28 . V_135 ( V_8 -> V_38 + V_8 -> V_28 . V_100
+ V_8 -> V_28 . V_102 , V_20 , 0 ) ;
return F_121 ( V_8 , V_1 ,
V_8 -> V_38 +
V_8 -> V_28 . V_100 +
V_8 -> V_28 . V_102 ,
V_8 -> V_28 . V_104 ) ;
}
static inline void * F_135 ( struct V_7 * V_8 )
{
return ( V_8 -> V_74 ) ? V_8 : V_8 -> V_87 ;
}
int F_136 ( struct V_7 * V_8 , unsigned int V_1 ,
unsigned int V_20 )
{
int V_19 ;
void * V_189 = F_135 ( V_8 ) ;
if ( ! F_4 ( V_8 , V_1 ) )
return - V_190 ;
if ( ! V_8 -> V_163 && ! V_8 -> V_126 ) {
V_19 = F_123 ( V_8 , V_1 , V_20 ) ;
if ( V_19 != 0 )
return V_19 ;
if ( V_8 -> V_164 ) {
V_8 -> V_182 = true ;
return 0 ;
}
}
#ifdef F_137
if ( V_8 -> V_17 && strcmp ( F_138 ( V_8 -> V_17 ) , F_137 ) == 0 )
F_139 ( V_8 -> V_17 , L_14 , V_1 , V_20 ) ;
#endif
F_140 ( V_8 , V_1 , V_20 ) ;
return V_8 -> V_125 ( V_189 , V_1 , V_20 ) ;
}
int F_141 ( struct V_7 * V_8 , unsigned int V_1 , unsigned int V_20 )
{
int V_19 ;
if ( ! F_142 ( V_1 , V_8 -> V_108 ) )
return - V_91 ;
V_8 -> V_24 ( V_8 -> V_25 ) ;
V_19 = F_136 ( V_8 , V_1 , V_20 ) ;
V_8 -> V_26 ( V_8 -> V_25 ) ;
return V_19 ;
}
int F_143 ( struct V_7 * V_8 , unsigned int V_1 , unsigned int V_20 )
{
int V_19 ;
if ( ! F_142 ( V_1 , V_8 -> V_108 ) )
return - V_91 ;
V_8 -> V_24 ( V_8 -> V_25 ) ;
V_8 -> V_166 = true ;
V_19 = F_136 ( V_8 , V_1 , V_20 ) ;
V_8 -> V_166 = false ;
V_8 -> V_26 ( V_8 -> V_25 ) ;
return V_19 ;
}
int F_144 ( struct V_7 * V_8 , unsigned int V_1 ,
const void * V_20 , T_1 V_176 )
{
int V_19 ;
if ( ! F_132 ( V_8 ) )
return - V_91 ;
if ( V_176 % V_8 -> V_28 . V_104 )
return - V_91 ;
if ( V_8 -> V_117 && V_8 -> V_117 > V_176 )
return - V_191 ;
V_8 -> V_24 ( V_8 -> V_25 ) ;
V_19 = F_121 ( V_8 , V_1 , V_20 , V_176 ) ;
V_8 -> V_26 ( V_8 -> V_25 ) ;
return V_19 ;
}
int F_145 ( struct V_154 * V_162 ,
unsigned int V_158 , unsigned int V_20 ,
bool * V_192 , bool V_166 , bool V_193 )
{
V_158 = ( V_158 << V_162 -> V_40 ) & V_162 -> V_158 ;
return F_146 ( V_162 -> V_7 , V_162 -> V_1 ,
V_158 , V_20 << V_162 -> V_40 ,
V_192 , V_166 , V_193 ) ;
}
int F_147 ( struct V_154 * V_162 , unsigned int V_194 ,
unsigned int V_158 , unsigned int V_20 ,
bool * V_192 , bool V_166 , bool V_193 )
{
if ( V_194 >= V_162 -> V_160 )
return - V_91 ;
V_158 = ( V_158 << V_162 -> V_40 ) & V_162 -> V_158 ;
return F_146 ( V_162 -> V_7 ,
V_162 -> V_1 + ( V_162 -> V_161 * V_194 ) ,
V_158 , V_20 << V_162 -> V_40 ,
V_192 , V_166 , V_193 ) ;
}
int F_148 ( struct V_7 * V_8 , unsigned int V_1 , const void * V_20 ,
T_1 V_195 )
{
int V_19 = 0 , V_6 ;
T_1 V_104 = V_8 -> V_28 . V_104 ;
T_1 V_196 = V_104 * V_195 ;
if ( ! F_142 ( V_1 , V_8 -> V_108 ) )
return - V_91 ;
if ( ! V_8 -> V_74 ) {
V_8 -> V_24 ( V_8 -> V_25 ) ;
for ( V_6 = 0 ; V_6 < V_195 ; V_6 ++ ) {
unsigned int V_181 ;
switch ( V_104 ) {
case 1 :
V_181 = * ( T_2 * ) ( V_20 + ( V_6 * V_104 ) ) ;
break;
case 2 :
V_181 = * ( V_42 * ) ( V_20 + ( V_6 * V_104 ) ) ;
break;
case 4 :
V_181 = * ( V_43 * ) ( V_20 + ( V_6 * V_104 ) ) ;
break;
#ifdef F_91
case 8 :
V_181 = * ( V_44 * ) ( V_20 + ( V_6 * V_104 ) ) ;
break;
#endif
default:
V_19 = - V_91 ;
goto V_37;
}
V_19 = F_136 ( V_8 ,
V_1 + F_122 ( V_8 , V_6 ) ,
V_181 ) ;
if ( V_19 != 0 )
goto V_37;
}
V_37:
V_8 -> V_26 ( V_8 -> V_25 ) ;
} else if ( V_8 -> V_74 && ! V_8 -> V_28 . V_134 ) {
const T_2 * T_2 = V_20 ;
const V_42 * V_42 = V_20 ;
const V_43 * V_43 = V_20 ;
unsigned int V_181 ;
for ( V_6 = 0 ; V_6 < V_195 ; V_6 ++ ) {
switch ( V_8 -> V_28 . V_104 ) {
case 4 :
V_181 = V_43 [ V_6 ] ;
break;
case 2 :
V_181 = V_42 [ V_6 ] ;
break;
case 1 :
V_181 = T_2 [ V_6 ] ;
break;
default:
return - V_91 ;
}
V_19 = F_141 ( V_8 , V_1 + ( V_6 * V_8 -> V_108 ) ,
V_181 ) ;
if ( V_19 )
return V_19 ;
}
} else if ( V_8 -> V_113 ||
( V_8 -> V_117 && V_8 -> V_117 < V_196 ) ) {
int V_197 = V_8 -> V_108 ;
T_1 V_198 = V_104 ;
T_1 V_199 = V_195 ;
if ( ! V_8 -> V_113 ) {
V_198 = V_8 -> V_117 ;
if ( V_198 % V_104 )
V_198 -= V_198 % V_104 ;
V_199 = V_196 / V_198 ;
V_197 *= V_198 / V_104 ;
}
V_8 -> V_24 ( V_8 -> V_25 ) ;
for ( V_6 = 0 ; V_6 < V_199 ; V_6 ++ ) {
V_19 = F_121 ( V_8 ,
V_1 + ( V_6 * V_197 ) ,
V_20 + ( V_6 * V_198 ) ,
V_198 ) ;
if ( V_19 )
break;
}
if ( ! V_19 && V_198 * V_6 < V_196 ) {
V_19 = F_121 ( V_8 , V_1 + ( V_6 * V_197 ) ,
V_20 + ( V_6 * V_198 ) ,
V_196 - V_6 * V_198 ) ;
}
V_8 -> V_26 ( V_8 -> V_25 ) ;
} else {
void * V_200 ;
if ( ! V_195 )
return - V_91 ;
V_200 = F_149 ( V_20 , V_195 * V_104 , V_8 -> V_98 ) ;
if ( ! V_200 ) {
F_92 ( V_8 -> V_17 , L_15 ) ;
return - V_71 ;
}
for ( V_6 = 0 ; V_6 < V_195 * V_104 ; V_6 += V_104 )
V_8 -> V_28 . V_134 ( V_200 + V_6 ) ;
V_8 -> V_24 ( V_8 -> V_25 ) ;
V_19 = F_121 ( V_8 , V_1 , V_200 , V_104 * V_195 ) ;
V_8 -> V_26 ( V_8 -> V_25 ) ;
F_72 ( V_200 ) ;
}
return V_19 ;
}
static int F_150 ( struct V_7 * V_8 ,
const struct V_201 * V_202 ,
T_1 V_203 )
{
int V_19 ;
void * V_39 ;
int V_6 ;
T_2 * T_2 ;
T_1 V_104 = V_8 -> V_28 . V_104 ;
T_1 V_100 = V_8 -> V_28 . V_100 ;
T_1 V_102 = V_8 -> V_28 . V_102 ;
T_1 V_204 = V_100 + V_102 + V_104 ;
T_1 V_180 = V_204 * V_203 ;
if ( ! V_180 )
return - V_91 ;
V_39 = F_82 ( V_180 , V_70 ) ;
if ( ! V_39 )
return - V_71 ;
T_2 = V_39 ;
for ( V_6 = 0 ; V_6 < V_203 ; V_6 ++ ) {
unsigned int V_1 = V_202 [ V_6 ] . V_1 ;
unsigned int V_20 = V_202 [ V_6 ] . V_205 ;
F_130 ( V_8 , V_1 , 1 ) ;
V_8 -> V_28 . V_133 ( T_2 , V_1 , V_8 -> V_107 ) ;
T_2 += V_100 + V_102 ;
V_8 -> V_28 . V_135 ( T_2 , V_20 , 0 ) ;
T_2 += V_104 ;
}
T_2 = V_39 ;
* T_2 |= V_8 -> V_124 ;
V_19 = V_8 -> V_74 -> V_114 ( V_8 -> V_87 , V_39 , V_180 ) ;
F_72 ( V_39 ) ;
for ( V_6 = 0 ; V_6 < V_203 ; V_6 ++ ) {
int V_1 = V_202 [ V_6 ] . V_1 ;
F_131 ( V_8 , V_1 , 1 ) ;
}
return V_19 ;
}
static unsigned int F_151 ( struct V_7 * V_8 ,
unsigned int V_1 ,
struct V_49 * V_169 )
{
unsigned int V_173 = ( V_1 - V_169 -> V_60 ) / V_169 -> V_145 ;
return V_173 ;
}
static int F_152 ( struct V_7 * V_8 ,
struct V_201 * V_202 ,
T_1 V_203 )
{
int V_19 ;
int V_6 , V_206 ;
struct V_201 * V_207 ;
unsigned int V_208 = 0 ;
unsigned int V_209 = 0 ;
V_207 = V_202 ;
for ( V_6 = 0 , V_206 = 0 ; V_6 < V_203 ; V_6 ++ , V_206 ++ ) {
unsigned int V_1 = V_202 [ V_6 ] . V_1 ;
struct V_49 * V_169 ;
V_169 = F_67 ( V_8 , V_1 ) ;
if ( V_169 ) {
unsigned int V_173 = F_151 ( V_8 , V_1 ,
V_169 ) ;
if ( V_6 == 0 )
V_208 = V_173 ;
if ( V_173 != V_208 ) {
V_208 = V_173 ;
V_209 = 1 ;
}
}
if ( V_209 || V_202 [ V_6 ] . V_210 ) {
if ( V_202 [ V_6 ] . V_210 && V_6 == 0 )
V_206 = 1 ;
V_19 = F_150 ( V_8 , V_207 , V_206 ) ;
if ( V_19 != 0 )
return V_19 ;
if ( V_202 [ V_6 ] . V_210 )
F_153 ( V_202 [ V_6 ] . V_210 ) ;
V_207 += V_206 ;
V_206 = 0 ;
if ( V_209 ) {
V_19 = F_118 ( V_8 ,
& V_207 [ V_206 ] . V_1 ,
V_169 , 1 ) ;
if ( V_19 != 0 )
return V_19 ;
V_209 = 0 ;
}
}
}
if ( V_206 > 0 )
return F_150 ( V_8 , V_207 , V_206 ) ;
return 0 ;
}
static int F_154 ( struct V_7 * V_8 ,
const struct V_201 * V_202 ,
T_1 V_203 )
{
int V_6 ;
int V_19 ;
if ( ! V_8 -> V_115 ) {
for ( V_6 = 0 ; V_6 < V_203 ; V_6 ++ ) {
V_19 = F_136 ( V_8 , V_202 [ V_6 ] . V_1 , V_202 [ V_6 ] . V_205 ) ;
if ( V_19 != 0 )
return V_19 ;
if ( V_202 [ V_6 ] . V_210 )
F_153 ( V_202 [ V_6 ] . V_210 ) ;
}
return 0 ;
}
if ( ! V_8 -> V_28 . V_134 )
return - V_91 ;
if ( V_8 -> V_16 )
for ( V_6 = 0 ; V_6 < V_203 ; V_6 ++ ) {
int V_1 = V_202 [ V_6 ] . V_1 ;
if ( ! V_8 -> V_16 ( V_8 -> V_17 , V_1 ) )
return - V_91 ;
if ( ! F_142 ( V_1 , V_8 -> V_108 ) )
return - V_91 ;
}
if ( ! V_8 -> V_163 ) {
for ( V_6 = 0 ; V_6 < V_203 ; V_6 ++ ) {
unsigned int V_20 = V_202 [ V_6 ] . V_205 ;
unsigned int V_1 = V_202 [ V_6 ] . V_1 ;
V_19 = F_123 ( V_8 , V_1 , V_20 ) ;
if ( V_19 ) {
F_92 ( V_8 -> V_17 ,
L_11 ,
V_1 , V_19 ) ;
return V_19 ;
}
}
if ( V_8 -> V_164 ) {
V_8 -> V_182 = true ;
return 0 ;
}
}
F_114 ( ! V_8 -> V_74 ) ;
for ( V_6 = 0 ; V_6 < V_203 ; V_6 ++ ) {
unsigned int V_1 = V_202 [ V_6 ] . V_1 ;
struct V_49 * V_169 ;
V_169 = F_67 ( V_8 , V_1 ) ;
if ( V_169 || V_202 [ V_6 ] . V_210 ) {
T_1 V_180 = sizeof( struct V_201 ) * V_203 ;
struct V_201 * V_207 = F_149 ( V_202 , V_180 ,
V_70 ) ;
if ( ! V_207 )
return - V_71 ;
V_19 = F_152 ( V_8 , V_207 ,
V_203 ) ;
F_72 ( V_207 ) ;
return V_19 ;
}
}
return F_150 ( V_8 , V_202 , V_203 ) ;
}
int F_155 ( struct V_7 * V_8 , const struct V_201 * V_202 ,
int V_203 )
{
int V_19 ;
V_8 -> V_24 ( V_8 -> V_25 ) ;
V_19 = F_154 ( V_8 , V_202 , V_203 ) ;
V_8 -> V_26 ( V_8 -> V_25 ) ;
return V_19 ;
}
int F_156 ( struct V_7 * V_8 ,
const struct V_201 * V_202 ,
int V_203 )
{
int V_19 ;
bool V_211 ;
V_8 -> V_24 ( V_8 -> V_25 ) ;
V_211 = V_8 -> V_163 ;
V_8 -> V_163 = true ;
V_19 = F_154 ( V_8 , V_202 , V_203 ) ;
V_8 -> V_163 = V_211 ;
V_8 -> V_26 ( V_8 -> V_25 ) ;
return V_19 ;
}
int F_157 ( struct V_7 * V_8 , unsigned int V_1 ,
const void * V_20 , T_1 V_176 )
{
int V_19 ;
if ( V_176 % V_8 -> V_28 . V_104 )
return - V_91 ;
if ( ! F_142 ( V_1 , V_8 -> V_108 ) )
return - V_91 ;
V_8 -> V_24 ( V_8 -> V_25 ) ;
V_8 -> V_166 = true ;
V_19 = F_121 ( V_8 , V_1 , V_20 , V_176 ) ;
V_8 -> V_166 = false ;
V_8 -> V_26 ( V_8 -> V_25 ) ;
return V_19 ;
}
static int F_158 ( struct V_7 * V_8 , unsigned int V_1 , void * V_20 ,
unsigned int V_176 )
{
struct V_49 * V_169 ;
int V_19 ;
F_114 ( ! V_8 -> V_74 ) ;
if ( ! V_8 -> V_74 || ! V_8 -> V_74 -> V_112 )
return - V_91 ;
V_169 = F_67 ( V_8 , V_1 ) ;
if ( V_169 ) {
V_19 = F_118 ( V_8 , & V_1 , V_169 ,
V_176 / V_8 -> V_28 . V_104 ) ;
if ( V_19 != 0 )
return V_19 ;
}
V_8 -> V_28 . V_133 ( V_8 -> V_38 , V_1 , V_8 -> V_107 ) ;
F_120 ( V_8 , V_8 -> V_28 . V_100 ,
V_8 -> V_123 ) ;
F_159 ( V_8 , V_1 , V_176 / V_8 -> V_28 . V_104 ) ;
V_19 = V_8 -> V_74 -> V_112 ( V_8 -> V_87 , V_8 -> V_38 ,
V_8 -> V_28 . V_100 + V_8 -> V_28 . V_102 ,
V_20 , V_176 ) ;
F_160 ( V_8 , V_1 , V_176 / V_8 -> V_28 . V_104 ) ;
return V_19 ;
}
static int V_128 ( void * V_189 , unsigned int V_1 ,
unsigned int * V_20 )
{
struct V_7 * V_8 = V_189 ;
return V_8 -> V_74 -> V_27 ( V_8 -> V_87 , V_1 , V_20 ) ;
}
static int V_130 ( void * V_189 , unsigned int V_1 ,
unsigned int * V_20 )
{
int V_19 ;
struct V_7 * V_8 = V_189 ;
if ( ! V_8 -> V_28 . V_136 )
return - V_91 ;
V_19 = F_158 ( V_8 , V_1 , V_8 -> V_38 , V_8 -> V_28 . V_104 ) ;
if ( V_19 == 0 )
* V_20 = V_8 -> V_28 . V_136 ( V_8 -> V_38 ) ;
return V_19 ;
}
static int F_161 ( struct V_7 * V_8 , unsigned int V_1 ,
unsigned int * V_20 )
{
int V_19 ;
void * V_189 = F_135 ( V_8 ) ;
if ( ! V_8 -> V_163 ) {
V_19 = F_6 ( V_8 , V_1 , V_20 ) ;
if ( V_19 == 0 )
return 0 ;
}
if ( V_8 -> V_164 )
return - V_212 ;
if ( ! F_7 ( V_8 , V_1 ) )
return - V_190 ;
V_19 = V_8 -> V_27 ( V_189 , V_1 , V_20 ) ;
if ( V_19 == 0 ) {
#ifdef F_137
if ( V_8 -> V_17 && strcmp ( F_138 ( V_8 -> V_17 ) , F_137 ) == 0 )
F_139 ( V_8 -> V_17 , L_16 , V_1 , * V_20 ) ;
#endif
F_162 ( V_8 , V_1 , * V_20 ) ;
if ( ! V_8 -> V_163 )
F_123 ( V_8 , V_1 , * V_20 ) ;
}
return V_19 ;
}
int F_163 ( struct V_7 * V_8 , unsigned int V_1 , unsigned int * V_20 )
{
int V_19 ;
if ( ! F_142 ( V_1 , V_8 -> V_108 ) )
return - V_91 ;
V_8 -> V_24 ( V_8 -> V_25 ) ;
V_19 = F_161 ( V_8 , V_1 , V_20 ) ;
V_8 -> V_26 ( V_8 -> V_25 ) ;
return V_19 ;
}
int F_164 ( struct V_7 * V_8 , unsigned int V_1 , void * V_20 ,
T_1 V_176 )
{
T_1 V_104 = V_8 -> V_28 . V_104 ;
T_1 V_195 = V_176 / V_104 ;
unsigned int V_213 ;
int V_19 , V_6 ;
if ( ! V_8 -> V_74 )
return - V_91 ;
if ( V_176 % V_8 -> V_28 . V_104 )
return - V_91 ;
if ( ! F_142 ( V_1 , V_8 -> V_108 ) )
return - V_91 ;
if ( V_195 == 0 )
return - V_91 ;
V_8 -> V_24 ( V_8 -> V_25 ) ;
if ( F_10 ( V_8 , V_1 , V_195 ) || V_8 -> V_163 ||
V_8 -> V_118 == V_22 ) {
if ( ! V_8 -> V_74 -> V_112 ) {
V_19 = - V_179 ;
goto V_37;
}
if ( V_8 -> V_116 && V_8 -> V_116 < V_176 ) {
V_19 = - V_191 ;
goto V_37;
}
V_19 = F_158 ( V_8 , V_1 , V_20 , V_176 ) ;
} else {
for ( V_6 = 0 ; V_6 < V_195 ; V_6 ++ ) {
V_19 = F_161 ( V_8 , V_1 + F_122 ( V_8 , V_6 ) ,
& V_213 ) ;
if ( V_19 != 0 )
goto V_37;
V_8 -> V_28 . V_135 ( V_20 + ( V_6 * V_104 ) , V_213 , 0 ) ;
}
}
V_37:
V_8 -> V_26 ( V_8 -> V_25 ) ;
return V_19 ;
}
int F_165 ( struct V_154 * V_162 , unsigned int * V_20 )
{
int V_19 ;
unsigned int V_214 ;
V_19 = F_163 ( V_162 -> V_7 , V_162 -> V_1 , & V_214 ) ;
if ( V_19 != 0 )
return V_19 ;
V_214 &= V_162 -> V_158 ;
V_214 >>= V_162 -> V_40 ;
* V_20 = V_214 ;
return V_19 ;
}
int F_166 ( struct V_154 * V_162 , unsigned int V_194 ,
unsigned int * V_20 )
{
int V_19 ;
unsigned int V_214 ;
if ( V_194 >= V_162 -> V_160 )
return - V_91 ;
V_19 = F_163 ( V_162 -> V_7 ,
V_162 -> V_1 + ( V_162 -> V_161 * V_194 ) ,
& V_214 ) ;
if ( V_19 != 0 )
return V_19 ;
V_214 &= V_162 -> V_158 ;
V_214 >>= V_162 -> V_40 ;
* V_20 = V_214 ;
return V_19 ;
}
int F_167 ( struct V_7 * V_8 , unsigned int V_1 , void * V_20 ,
T_1 V_195 )
{
int V_19 , V_6 ;
T_1 V_104 = V_8 -> V_28 . V_104 ;
bool V_215 = F_10 ( V_8 , V_1 , V_195 ) ;
if ( ! F_142 ( V_1 , V_8 -> V_108 ) )
return - V_91 ;
if ( V_8 -> V_74 && V_8 -> V_28 . V_134 && ( V_215 || V_8 -> V_118 == V_22 ) ) {
T_1 V_196 = V_104 * V_195 ;
if ( ! V_8 -> V_110 &&
( ! V_8 -> V_116 || V_8 -> V_116 > V_196 ) ) {
V_19 = F_164 ( V_8 , V_1 , V_20 ,
V_104 * V_195 ) ;
if ( V_19 != 0 )
return V_19 ;
} else {
int V_197 = V_8 -> V_108 ;
T_1 V_198 = V_104 ;
T_1 V_199 = V_195 ;
if ( ! V_8 -> V_110 ) {
V_198 = V_8 -> V_116 ;
if ( V_198 % V_104 )
V_198 -= V_198 % V_104 ;
V_199 = V_196 / V_198 ;
V_197 *= V_198 / V_104 ;
}
for ( V_6 = 0 ; V_6 < V_199 ; V_6 ++ ) {
V_19 = F_164 ( V_8 ,
V_1 + ( V_6 * V_197 ) ,
V_20 + ( V_6 * V_198 ) ,
V_198 ) ;
if ( V_19 != 0 )
return V_19 ;
}
if ( V_198 * V_6 < V_196 ) {
V_19 = F_164 ( V_8 ,
V_1 + ( V_6 * V_197 ) ,
V_20 + ( V_6 * V_198 ) ,
V_196 - V_6 * V_198 ) ;
if ( V_19 != 0 )
return V_19 ;
}
}
for ( V_6 = 0 ; V_6 < V_195 * V_104 ; V_6 += V_104 )
V_8 -> V_28 . V_134 ( V_20 + V_6 ) ;
} else {
for ( V_6 = 0 ; V_6 < V_195 ; V_6 ++ ) {
unsigned int V_181 ;
V_19 = F_163 ( V_8 , V_1 + F_122 ( V_8 , V_6 ) ,
& V_181 ) ;
if ( V_19 != 0 )
return V_19 ;
if ( V_8 -> V_28 . V_135 ) {
V_8 -> V_28 . V_135 ( V_20 + ( V_6 * V_104 ) , V_181 , 0 ) ;
} else {
#ifdef F_91
V_44 * V_44 = V_20 ;
#endif
V_43 * V_43 = V_20 ;
V_42 * V_42 = V_20 ;
T_2 * T_2 = V_20 ;
switch ( V_8 -> V_28 . V_104 ) {
#ifdef F_91
case 8 :
V_44 [ V_6 ] = V_181 ;
break;
#endif
case 4 :
V_43 [ V_6 ] = V_181 ;
break;
case 2 :
V_42 [ V_6 ] = V_181 ;
break;
case 1 :
T_2 [ V_6 ] = V_181 ;
break;
default:
return - V_91 ;
}
}
}
}
return 0 ;
}
static int F_119 ( struct V_7 * V_8 , unsigned int V_1 ,
unsigned int V_158 , unsigned int V_20 ,
bool * V_192 , bool V_216 )
{
int V_19 ;
unsigned int V_217 , V_218 ;
if ( V_192 )
* V_192 = false ;
if ( F_8 ( V_8 , V_1 ) && V_8 -> V_131 ) {
V_19 = V_8 -> V_131 ( V_8 -> V_87 , V_1 , V_158 , V_20 ) ;
if ( V_19 == 0 && V_192 )
* V_192 = true ;
} else {
V_19 = F_161 ( V_8 , V_1 , & V_218 ) ;
if ( V_19 != 0 )
return V_19 ;
V_217 = V_218 & ~ V_158 ;
V_217 |= V_20 & V_158 ;
if ( V_216 || ( V_217 != V_218 ) ) {
V_19 = F_136 ( V_8 , V_1 , V_217 ) ;
if ( V_19 == 0 && V_192 )
* V_192 = true ;
}
}
return V_19 ;
}
int F_146 ( struct V_7 * V_8 , unsigned int V_1 ,
unsigned int V_158 , unsigned int V_20 ,
bool * V_192 , bool V_166 , bool V_193 )
{
int V_19 ;
V_8 -> V_24 ( V_8 -> V_25 ) ;
V_8 -> V_166 = V_166 ;
V_19 = F_119 ( V_8 , V_1 , V_158 , V_20 , V_192 , V_193 ) ;
V_8 -> V_166 = false ;
V_8 -> V_26 ( V_8 -> V_25 ) ;
return V_19 ;
}
void F_168 ( struct V_165 * V_166 , int V_19 )
{
struct V_7 * V_8 = V_166 -> V_8 ;
bool V_219 ;
F_169 ( V_8 ) ;
F_170 ( & V_8 -> V_119 ) ;
F_129 ( & V_166 -> V_168 , & V_8 -> V_121 ) ;
V_219 = F_110 ( & V_8 -> V_120 ) ;
if ( V_19 != 0 )
V_8 -> V_220 = V_19 ;
F_171 ( & V_8 -> V_119 ) ;
if ( V_219 )
F_172 ( & V_8 -> V_122 ) ;
}
static int F_173 ( struct V_7 * V_8 )
{
unsigned long V_177 ;
int V_19 ;
F_126 ( & V_8 -> V_119 , V_177 ) ;
V_19 = F_110 ( & V_8 -> V_120 ) ;
F_127 ( & V_8 -> V_119 , V_177 ) ;
return V_19 ;
}
int F_174 ( struct V_7 * V_8 )
{
unsigned long V_177 ;
int V_19 ;
if ( ! V_8 -> V_74 || ! V_8 -> V_74 -> V_184 )
return 0 ;
F_175 ( V_8 ) ;
F_176 ( V_8 -> V_122 , F_173 ( V_8 ) ) ;
F_126 ( & V_8 -> V_119 , V_177 ) ;
V_19 = V_8 -> V_220 ;
V_8 -> V_220 = 0 ;
F_127 ( & V_8 -> V_119 , V_177 ) ;
F_177 ( V_8 ) ;
return V_19 ;
}
int F_178 ( struct V_7 * V_8 , const struct V_201 * V_202 ,
int V_203 )
{
struct V_201 * V_221 ;
int V_19 ;
bool V_211 ;
if ( F_179 ( V_203 <= 0 , L_17 ,
V_203 ) )
return 0 ;
V_221 = F_180 ( V_8 -> V_222 ,
sizeof( struct V_201 ) * ( V_8 -> V_223 + V_203 ) ,
V_70 ) ;
if ( V_221 ) {
memcpy ( V_221 + V_8 -> V_223 , V_202 , V_203 * sizeof( * V_202 ) ) ;
V_8 -> V_222 = V_221 ;
V_8 -> V_223 += V_203 ;
} else {
return - V_71 ;
}
V_8 -> V_24 ( V_8 -> V_25 ) ;
V_211 = V_8 -> V_163 ;
V_8 -> V_163 = true ;
V_8 -> V_166 = true ;
V_19 = F_154 ( V_8 , V_202 , V_203 ) ;
V_8 -> V_166 = false ;
V_8 -> V_163 = V_211 ;
V_8 -> V_26 ( V_8 -> V_25 ) ;
F_174 ( V_8 ) ;
return V_19 ;
}
int F_181 ( struct V_7 * V_8 )
{
if ( V_8 -> V_28 . V_29 )
return - V_91 ;
return V_8 -> V_28 . V_104 ;
}
int F_182 ( struct V_7 * V_8 )
{
return V_8 -> V_15 ? V_8 -> V_15 : - V_91 ;
}
int F_183 ( struct V_7 * V_8 )
{
return V_8 -> V_108 ;
}
int F_184 ( struct V_7 * V_8 , const void * V_39 ,
unsigned int * V_20 )
{
if ( ! V_8 -> V_28 . V_136 )
return - V_91 ;
* V_20 = V_8 -> V_28 . V_136 ( V_39 ) ;
return 0 ;
}
static int T_9 F_185 ( void )
{
F_186 () ;
return 0 ;
}
