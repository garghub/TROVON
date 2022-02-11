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
static void F_10 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
T_1 V_7 ;
V_2 -> V_20 = V_21 ;
V_7 = 0 ;
if ( F_11 ( V_19 , V_22 ) )
V_7 |= 1 << V_23 ;
if ( F_11 ( V_19 , V_24 ) )
V_7 |= 1 << V_25 ;
if ( F_11 ( V_19 , V_26 ) )
V_7 |= 1 << V_27 ;
if ( F_11 ( V_19 , V_28 ) )
V_7 |= 1 << V_29 ;
if ( F_11 ( V_19 , V_30 ) )
V_7 |= 1 << V_31 ;
V_2 -> V_5 = V_7 ;
V_2 -> V_6 [ V_23 ] = F_12 ( V_19 , V_22 ) ;
V_2 -> V_6 [ V_25 ] = F_12 ( V_19 , V_24 ) ;
V_2 -> V_6 [ V_27 ] = F_12 ( V_19 , V_26 ) ;
V_2 -> V_6 [ V_29 ] = F_12 ( V_19 , V_28 ) ;
V_2 -> V_6 [ V_31 ] = F_12 ( V_19 , V_30 ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 . V_35 = 0 ;
V_2 -> V_34 . V_36 = 0 ;
V_2 -> V_34 . V_37 . V_38 = 0 ;
}
static struct V_1 * F_13 ( struct V_18 * V_19 ,
struct V_8 * V_16 ,
unsigned int V_39 ,
bool V_40 )
{
struct V_1 * V_2 ;
struct V_41 * V_41 ;
F_14 ( & V_42 ) ;
V_41 = F_15 ( V_19 -> V_43 ) ;
if ( F_16 ( V_40 ) ) {
struct V_1 * V_44 ;
V_44 = F_17 ( V_41 -> V_45 . V_46 [ V_39 ] . V_47 ) ;
for ( V_2 = F_17 ( V_44 -> V_48 ) ; V_2 ;
V_2 = F_17 ( V_2 -> V_48 ) ) {
if ( F_18 ( V_2 -> V_20 , V_44 -> V_20 ) )
V_44 = V_2 ;
}
V_2 = V_44 ;
} else {
V_2 = F_19 ( sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 )
goto V_50;
}
V_2 -> V_51 = * V_16 ;
F_10 ( V_2 , V_19 ) ;
if ( F_20 ( ! V_40 ) ) {
V_2 -> V_48 = V_41 -> V_45 . V_46 [ V_39 ] . V_47 ;
F_21 ( V_41 -> V_45 . V_46 [ V_39 ] . V_47 , V_2 ) ;
}
V_50:
F_22 ( & V_42 ) ;
return V_2 ;
}
static void F_23 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
if ( V_2 && F_16 ( F_24 ( V_21 , V_2 -> V_20 + V_52 ) ) )
F_10 ( V_2 , V_19 ) ;
}
static struct V_1 * F_25 ( struct V_1 * V_2 , int V_53 )
{
if ( V_2 )
return V_2 ;
if ( V_53 > V_54 )
return V_55 ;
return NULL ;
}
static struct V_1 * F_26 ( const struct V_8 * V_16 ,
struct V_41 * V_41 , unsigned int V_39 )
{
struct V_1 * V_2 ;
int V_53 = 0 ;
for ( V_2 = F_17 ( V_41 -> V_45 . V_46 [ V_39 ] . V_47 ) ; V_2 ;
V_2 = F_17 ( V_2 -> V_48 ) ) {
if ( F_8 ( & V_2 -> V_51 , V_16 ) )
break;
V_53 ++ ;
}
return F_25 ( V_2 , V_53 ) ;
}
static struct V_1 * F_27 ( struct V_56 * V_57 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_8 V_16 ;
unsigned int V_39 ;
struct V_41 * V_41 ;
V_16 . V_14 = V_57 -> V_58 -> V_14 ;
switch ( V_16 . V_14 ) {
case V_15 :
V_16 . V_16 . V_17 = F_28 ( V_57 ) -> V_59 ;
V_39 = ( V_60 unsigned int ) V_16 . V_16 . V_17 ;
break;
case V_61 :
* (struct V_11 * ) V_16 . V_16 . V_12 = F_29 ( V_57 ) -> V_59 ;
V_39 = F_30 ( & F_29 ( V_57 ) -> V_59 ) ;
break;
default:
return NULL ;
}
V_41 = F_15 ( V_19 -> V_43 ) ;
V_39 = F_31 ( V_39 , V_41 -> V_45 . V_62 ) ;
for ( V_2 = F_17 ( V_41 -> V_45 . V_46 [ V_39 ] . V_47 ) ; V_2 ;
V_2 = F_17 ( V_2 -> V_48 ) ) {
if ( F_8 ( & V_2 -> V_51 , & V_16 ) )
break;
}
F_23 ( V_2 , V_19 ) ;
return V_2 ;
}
static struct V_1 * F_32 ( struct V_63 * V_64 )
{
struct V_65 * V_66 ;
struct V_1 * V_2 ;
struct V_8 V_16 ;
unsigned int V_39 ;
struct V_41 * V_41 ;
V_16 . V_14 = V_64 -> V_67 ;
switch ( V_16 . V_14 ) {
case V_15 :
V_16 . V_16 . V_17 = V_64 -> V_68 ;
V_39 = ( V_60 unsigned int ) V_16 . V_16 . V_17 ;
break;
case V_61 :
V_66 = F_33 ( (struct V_69 * ) V_64 ) ;
* (struct V_11 * ) V_16 . V_16 . V_12 = V_66 -> V_70 ;
V_39 = F_30 ( & V_66 -> V_70 ) ;
break;
default:
return NULL ;
}
V_41 = F_34 ( V_64 ) ;
V_39 = F_31 ( V_39 , V_41 -> V_45 . V_62 ) ;
for ( V_2 = F_17 ( V_41 -> V_45 . V_46 [ V_39 ] . V_47 ) ; V_2 ;
V_2 = F_17 ( V_2 -> V_48 ) ) {
if ( F_8 ( & V_2 -> V_51 , & V_16 ) )
break;
}
return V_2 ;
}
static struct V_1 * F_35 ( struct V_69 * V_71 ,
struct V_18 * V_19 ,
bool V_72 )
{
struct V_1 * V_2 ;
struct V_8 V_16 ;
unsigned int V_39 ;
struct V_41 * V_41 ;
bool V_40 ;
V_16 . V_14 = V_71 -> V_73 ;
switch ( V_16 . V_14 ) {
case V_15 :
V_16 . V_16 . V_17 = F_36 ( V_71 ) -> V_74 ;
V_39 = ( V_60 unsigned int ) V_16 . V_16 . V_17 ;
break;
case V_61 :
* (struct V_11 * ) V_16 . V_16 . V_12 = F_37 ( V_71 ) -> V_75 ;
V_39 = F_30 ( & F_37 ( V_71 ) -> V_75 ) ;
break;
default:
return NULL ;
}
V_41 = F_15 ( V_19 -> V_43 ) ;
V_39 = F_31 ( V_39 , V_41 -> V_45 . V_62 ) ;
V_2 = F_26 ( & V_16 , V_41 , V_39 ) ;
V_40 = false ;
if ( V_2 == V_55 ) {
V_40 = true ;
V_2 = NULL ;
}
if ( ! V_2 && V_72 )
V_2 = F_13 ( V_19 , & V_16 , V_39 , V_40 ) ;
else
F_23 ( V_2 , V_19 ) ;
return V_2 ;
}
void F_38 ( struct V_69 * V_71 )
{
const struct V_76 * V_77 = F_39 ( V_71 ) ;
struct V_18 * V_19 = F_40 ( V_71 ) ;
struct V_78 * V_79 = F_41 ( V_71 ) ;
struct V_1 * V_2 ;
unsigned long V_80 ;
T_1 V_7 ;
int V_81 ;
if ( V_82 || ! V_19 )
return;
if ( V_19 -> V_83 & V_84 )
F_42 ( V_19 ) ;
F_43 () ;
if ( V_77 -> V_85 || ! V_79 -> V_86 ) {
V_2 = F_35 ( V_71 , V_19 , false ) ;
if ( V_2 && ! F_1 ( V_2 , V_23 ) )
F_5 ( V_2 , V_23 , 0 ) ;
goto V_50;
} else
V_2 = F_35 ( V_71 , V_19 , true ) ;
if ( ! V_2 )
goto V_50;
V_80 = F_3 ( V_2 , V_23 ) ;
V_81 = V_80 - V_79 -> V_86 ;
if ( ! F_1 ( V_2 , V_23 ) ) {
if ( V_81 <= 0 )
V_80 = V_79 -> V_86 ;
else
V_80 -= ( V_81 >> 3 ) ;
F_6 ( V_2 , V_23 , V_80 ) ;
}
if ( ! F_1 ( V_2 , V_25 ) ) {
unsigned long V_87 ;
if ( V_81 < 0 )
V_81 = - V_81 ;
V_81 >>= 1 ;
if ( V_81 < V_79 -> V_88 )
V_81 = V_79 -> V_88 ;
V_87 = F_3 ( V_2 , V_25 ) ;
if ( V_81 >= V_87 )
V_87 = V_81 ;
else
V_87 -= ( V_87 - V_81 ) >> 2 ;
F_6 ( V_2 , V_25 , V_87 ) ;
}
if ( F_44 ( V_79 ) ) {
if ( ! F_1 ( V_2 , V_27 ) ) {
V_7 = F_2 ( V_2 , V_27 ) ;
if ( V_7 && ( V_79 -> V_89 >> 1 ) > V_7 )
F_5 ( V_2 , V_27 ,
V_79 -> V_89 >> 1 ) ;
}
if ( ! F_1 ( V_2 , V_29 ) ) {
V_7 = F_2 ( V_2 , V_29 ) ;
if ( V_79 -> V_89 > V_7 )
F_5 ( V_2 , V_29 ,
V_79 -> V_89 ) ;
}
} else if ( V_79 -> V_89 > V_79 -> V_90 &&
V_77 -> V_91 == V_92 ) {
if ( ! F_1 ( V_2 , V_27 ) )
F_5 ( V_2 , V_27 ,
F_45 ( V_79 -> V_89 >> 1 , V_79 -> V_90 ) ) ;
if ( ! F_1 ( V_2 , V_29 ) ) {
V_7 = F_2 ( V_2 , V_29 ) ;
F_5 ( V_2 , V_29 , ( V_7 + V_79 -> V_89 ) >> 1 ) ;
}
} else {
if ( ! F_1 ( V_2 , V_29 ) ) {
V_7 = F_2 ( V_2 , V_29 ) ;
F_5 ( V_2 , V_29 ,
( V_7 + V_79 -> V_90 ) >> 1 ) ;
}
if ( ! F_1 ( V_2 , V_27 ) ) {
V_7 = F_2 ( V_2 , V_27 ) ;
if ( V_7 && V_79 -> V_90 > V_7 )
F_5 ( V_2 , V_27 ,
V_79 -> V_90 ) ;
}
if ( ! F_1 ( V_2 , V_31 ) ) {
V_7 = F_2 ( V_2 , V_31 ) ;
if ( V_7 < V_79 -> V_93 &&
V_79 -> V_93 != V_94 )
F_5 ( V_2 , V_31 ,
V_79 -> V_93 ) ;
}
}
V_2 -> V_20 = V_21 ;
V_50:
F_46 () ;
}
void F_47 ( struct V_69 * V_71 )
{
struct V_18 * V_19 = F_40 ( V_71 ) ;
struct V_78 * V_79 = F_41 ( V_71 ) ;
struct V_1 * V_2 ;
T_1 V_7 ;
if ( V_19 == NULL )
goto V_95;
F_42 ( V_19 ) ;
F_43 () ;
V_2 = F_35 ( V_71 , V_19 , true ) ;
if ( ! V_2 ) {
F_46 () ;
goto V_95;
}
if ( F_1 ( V_2 , V_29 ) )
V_79 -> V_96 = F_2 ( V_2 , V_29 ) ;
V_7 = F_2 ( V_2 , V_27 ) ;
if ( V_7 ) {
V_79 -> V_90 = V_7 ;
if ( V_79 -> V_90 > V_79 -> V_96 )
V_79 -> V_90 = V_79 -> V_96 ;
} else {
V_79 -> V_90 = V_97 ;
}
V_7 = F_2 ( V_2 , V_31 ) ;
if ( V_7 && V_79 -> V_93 != V_7 ) {
F_48 ( V_79 ) ;
F_49 ( V_79 ) ;
V_79 -> V_93 = V_7 ;
}
V_7 = F_2 ( V_2 , V_23 ) ;
if ( V_7 == 0 || V_79 -> V_86 == 0 ) {
F_46 () ;
goto V_95;
}
V_7 = F_4 ( V_7 ) ;
if ( V_7 > V_79 -> V_86 ) {
V_79 -> V_86 = V_7 ;
V_79 -> V_98 = V_79 -> V_99 ;
}
V_7 = F_3 ( V_2 , V_25 ) ;
if ( V_7 > V_79 -> V_88 ) {
V_79 -> V_88 = V_7 ;
V_79 -> V_100 = V_79 -> V_101 = F_45 ( V_79 -> V_88 , F_50 ( V_71 ) ) ;
}
F_46 () ;
F_51 ( V_71 ) ;
V_95:
if ( V_79 -> V_86 == 0 ) {
V_79 -> V_88 = V_79 -> V_100 = V_79 -> V_101 = V_102 ;
F_39 ( V_71 ) -> V_103 = V_102 ;
}
if ( V_79 -> V_104 > 1 )
V_79 -> V_89 = 1 ;
else
V_79 -> V_89 = F_52 ( V_79 , V_19 ) ;
V_79 -> V_105 = V_106 ;
}
bool F_53 ( struct V_56 * V_57 , struct V_18 * V_19 , bool V_107 )
{
struct V_1 * V_2 ;
bool V_108 ;
if ( ! V_19 )
return false ;
F_43 () ;
V_2 = F_27 ( V_57 , V_19 ) ;
if ( V_107 ) {
if ( V_2 &&
( T_1 ) F_54 () - V_2 -> V_33 < V_109 &&
( V_110 ) ( V_2 -> V_32 - V_57 -> V_111 ) > V_112 )
V_108 = false ;
else
V_108 = true ;
} else {
if ( V_2 && F_2 ( V_2 , V_23 ) && V_2 -> V_33 )
V_108 = true ;
else
V_108 = false ;
}
F_46 () ;
return V_108 ;
}
void F_55 ( struct V_69 * V_71 , struct V_18 * V_19 )
{
struct V_1 * V_2 ;
F_43 () ;
V_2 = F_35 ( V_71 , V_19 , true ) ;
if ( V_2 ) {
struct V_78 * V_79 = F_41 ( V_71 ) ;
if ( ( T_1 ) F_54 () - V_2 -> V_33 <= V_109 ) {
V_79 -> V_113 . V_114 = V_2 -> V_33 ;
V_79 -> V_113 . V_111 = V_2 -> V_32 ;
}
}
F_46 () ;
}
bool F_56 ( struct V_69 * V_71 )
{
struct V_18 * V_19 = F_40 ( V_71 ) ;
bool V_108 = false ;
if ( V_19 ) {
struct V_1 * V_2 ;
F_43 () ;
V_2 = F_35 ( V_71 , V_19 , true ) ;
if ( V_2 ) {
struct V_78 * V_79 = F_41 ( V_71 ) ;
if ( ( V_110 ) ( V_2 -> V_32 - V_79 -> V_113 . V_111 ) <= 0 ||
( ( T_1 ) F_54 () - V_2 -> V_33 > V_109 &&
V_2 -> V_33 <= ( T_1 ) V_79 -> V_113 . V_114 ) ) {
V_2 -> V_33 = ( T_1 ) V_79 -> V_113 . V_114 ;
V_2 -> V_32 = V_79 -> V_113 . V_111 ;
}
V_108 = true ;
}
F_46 () ;
}
return V_108 ;
}
bool F_57 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
bool V_108 = false ;
F_43 () ;
V_2 = F_32 ( V_64 ) ;
if ( V_2 ) {
const struct V_115 * V_116 ;
struct V_69 * V_71 = (struct V_69 * ) V_64 ;
V_116 = F_58 ( V_71 ) ;
if ( ( V_110 ) ( V_2 -> V_32 - V_116 -> V_117 ) <= 0 ||
( ( T_1 ) F_54 () - V_2 -> V_33 > V_109 &&
V_2 -> V_33 <= ( T_1 ) V_116 -> V_118 ) ) {
V_2 -> V_33 = ( T_1 ) V_116 -> V_118 ;
V_2 -> V_32 = V_116 -> V_117 ;
}
V_108 = true ;
}
F_46 () ;
return V_108 ;
}
void F_59 ( struct V_69 * V_71 , T_2 * V_35 ,
struct V_119 * V_37 ,
int * V_36 , unsigned long * V_120 )
{
struct V_1 * V_2 ;
F_43 () ;
V_2 = F_35 ( V_71 , F_40 ( V_71 ) , false ) ;
if ( V_2 ) {
struct V_121 * V_122 = & V_2 -> V_34 ;
unsigned int V_123 ;
do {
V_123 = F_60 ( & V_124 ) ;
if ( V_122 -> V_35 )
* V_35 = V_122 -> V_35 ;
* V_37 = V_122 -> V_37 ;
* V_36 = V_122 -> V_36 ;
* V_120 = * V_36 ? V_122 -> V_120 : 0 ;
} while ( F_61 ( & V_124 , V_123 ) );
}
F_46 () ;
}
void F_62 ( struct V_69 * V_71 , T_2 V_35 ,
struct V_119 * V_37 , bool V_125 )
{
struct V_1 * V_2 ;
F_43 () ;
V_2 = F_35 ( V_71 , F_40 ( V_71 ) , true ) ;
if ( V_2 ) {
struct V_121 * V_122 = & V_2 -> V_34 ;
F_63 ( & V_124 ) ;
V_122 -> V_35 = V_35 ;
if ( V_37 -> V_38 > 0 )
V_122 -> V_37 = * V_37 ;
if ( V_125 ) {
++ V_122 -> V_36 ;
V_122 -> V_120 = V_21 ;
} else
V_122 -> V_36 = 0 ;
F_64 ( & V_124 ) ;
}
F_46 () ;
}
static int T_3 F_65 ( char * V_126 )
{
T_4 V_108 ;
if ( ! V_126 )
return 0 ;
V_108 = F_66 ( V_126 , 0 , & V_127 ) ;
if ( V_108 )
return 0 ;
return 1 ;
}
static int T_5 F_67 ( struct V_41 * V_41 )
{
T_6 V_128 ;
unsigned int V_129 ;
V_129 = V_127 ;
if ( ! V_129 ) {
if ( V_130 >= 128 * 1024 )
V_129 = 16 * 1024 ;
else
V_129 = 8 * 1024 ;
}
V_41 -> V_45 . V_62 = F_68 ( V_129 ) ;
V_128 = sizeof( struct V_131 ) << V_41 -> V_45 . V_62 ;
V_41 -> V_45 . V_46 = F_69 ( V_128 , V_132 ) ;
if ( ! V_41 -> V_45 . V_46 )
return - V_133 ;
return 0 ;
}
static void T_7 F_70 ( struct V_41 * V_41 )
{
unsigned int V_134 ;
for ( V_134 = 0 ; V_134 < ( 1U << V_41 -> V_45 . V_62 ) ; V_134 ++ ) {
struct V_1 * V_2 , * V_135 ;
V_2 = F_71 ( V_41 -> V_45 . V_46 [ V_134 ] . V_47 , 1 ) ;
while ( V_2 ) {
V_135 = F_71 ( V_2 -> V_48 , 1 ) ;
F_72 ( V_2 ) ;
V_2 = V_135 ;
}
}
F_72 ( V_41 -> V_45 . V_46 ) ;
}
void T_3 F_73 ( void )
{
F_74 ( & V_136 ) ;
}
