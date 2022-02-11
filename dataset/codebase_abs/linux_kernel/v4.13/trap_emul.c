static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 ;
T_2 V_3 = F_2 ( V_1 ) ;
T_2 V_4 = F_3 ( V_1 ) ;
if ( ( V_3 == V_5 ) || ( V_3 == V_6 ) )
V_2 = F_4 ( V_1 ) ;
else if ( V_4 == V_7 )
V_2 = F_5 ( V_1 ) ;
else {
F_6 ( L_1 , V_8 , V_1 ) ;
F_7 () ;
V_2 = V_9 ;
}
F_8 ( L_2 , V_8 , V_1 , V_2 ) ;
return V_2 ;
}
static int F_9 ( struct V_10 * V_11 )
{
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
T_3 V_17 = ( V_15 & V_18 ) >> V_19 ;
unsigned long V_20 = V_11 -> V_13 . V_21 ;
T_3 V_22 = 0 ;
if ( V_15 & V_23 )
V_12 += 1 ;
F_10 ( V_12 , V_11 , & V_22 ) ;
F_6 ( L_3 ,
V_17 , V_12 , V_22 , V_20 ,
F_11 ( V_11 -> V_13 . V_24 ) ) ;
F_12 ( V_11 ) ;
V_11 -> V_25 -> V_26 = V_27 ;
return V_28 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_29 * V_24 = V_11 -> V_13 . V_24 ;
struct V_30 * V_25 = V_11 -> V_25 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
enum V_31 V_32 = V_33 ;
int V_34 = V_35 ;
if ( ( ( V_15 & V_36 ) >> V_37 ) == 1 ) {
if ( ! F_14 ( & V_11 -> V_13 ) ||
( F_11 ( V_24 ) & V_38 ) == 0 ) {
V_32 = F_15 ( V_15 , V_12 , V_25 , V_11 ) ;
} else {
F_16 ( V_11 ) ;
V_32 = V_33 ;
}
} else {
V_32 = F_17 ( V_15 , V_12 , V_25 , V_11 ) ;
}
switch ( V_32 ) {
case V_33 :
V_34 = V_35 ;
break;
case V_39 :
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
break;
case V_40 :
V_25 -> V_26 = V_41 ;
V_34 = V_28 ;
break;
case V_42 :
V_34 = F_18 ( V_11 ) ;
break;
default:
F_19 () ;
}
return V_34 ;
}
static int F_20 ( T_3 V_15 , T_3 * V_12 , struct V_30 * V_25 ,
struct V_10 * V_11 )
{
enum V_31 V_32 ;
union V_43 V_22 ;
int V_44 ;
if ( F_21 ( & V_11 -> V_13 ) ) {
V_25 -> V_26 = V_27 ;
return V_28 ;
}
if ( V_15 & V_23 )
V_12 += 1 ;
V_44 = F_10 ( V_12 , V_11 , & V_22 . V_45 ) ;
if ( V_44 ) {
V_25 -> V_26 = V_27 ;
return V_28 ;
}
V_32 = F_22 ( V_22 , V_15 , V_25 , V_11 ) ;
if ( V_32 == V_39 ) {
F_6 ( L_4 ) ;
V_25 -> V_26 = V_27 ;
} else {
V_25 -> V_26 = V_46 ;
}
return V_28 ;
}
static int F_23 ( T_3 V_15 , T_3 * V_12 , struct V_30 * V_25 ,
struct V_10 * V_11 )
{
enum V_31 V_32 ;
union V_43 V_22 ;
int V_44 ;
if ( V_15 & V_23 )
V_12 += 1 ;
V_44 = F_10 ( V_12 , V_11 , & V_22 . V_45 ) ;
if ( V_44 ) {
V_25 -> V_26 = V_27 ;
return V_28 ;
}
V_32 = F_24 ( V_22 , V_15 , V_25 , V_11 ) ;
if ( V_32 == V_39 ) {
F_6 ( L_5 ) ;
V_25 -> V_26 = V_27 ;
} else {
V_25 -> V_26 = V_46 ;
}
return V_28 ;
}
static int F_25 ( T_3 V_15 , T_3 * V_12 , struct V_30 * V_25 ,
struct V_10 * V_11 , bool V_47 )
{
if ( V_47 )
return F_23 ( V_15 , V_12 , V_25 , V_11 ) ;
else
return F_20 ( V_15 , V_12 , V_25 , V_11 ) ;
}
static int F_26 ( struct V_10 * V_11 )
{
struct V_29 * V_24 = V_11 -> V_13 . V_24 ;
struct V_30 * V_25 = V_11 -> V_25 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
unsigned long V_20 = V_11 -> V_13 . V_21 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
struct V_48 * V_49 ;
unsigned long V_50 ;
int V_51 ;
if ( F_3 ( V_20 ) < V_7
|| F_3 ( V_20 ) == V_52 ) {
V_50 = ( V_20 & V_53 ) |
( F_27 ( V_24 ) & V_54 ) ;
V_51 = F_28 ( V_11 , V_50 ) ;
if ( F_29 ( V_51 < 0 ) ) {
V_25 -> V_26 = V_27 ;
return V_28 ;
}
V_49 = V_11 -> V_13 . V_55 + V_51 ;
if ( F_29 ( ! F_30 ( * V_49 , V_20 ) ) ) {
V_25 -> V_26 = V_27 ;
return V_28 ;
}
if ( ! F_31 ( * V_49 , V_20 ) ) {
F_32 ( V_15 , V_12 , V_25 , V_11 ) ;
return V_35 ;
}
if ( F_33 ( V_11 , V_49 , V_20 ,
true ) )
return F_23 ( V_15 , V_12 , V_25 , V_11 ) ;
return V_35 ;
} else if ( F_3 ( V_20 ) == V_7 ) {
if ( F_34 ( V_20 , V_11 , true ) < 0 )
return F_23 ( V_15 , V_12 , V_25 , V_11 ) ;
return V_35 ;
} else {
return F_23 ( V_15 , V_12 , V_25 , V_11 ) ;
}
}
static int F_35 ( struct V_10 * V_11 , bool V_47 )
{
struct V_30 * V_25 = V_11 -> V_25 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
unsigned long V_20 = V_11 -> V_13 . V_21 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
enum V_31 V_32 = V_33 ;
int V_34 = V_35 ;
if ( ( ( V_20 & V_56 ) == V_57 )
&& F_36 ( V_11 ) ) {
if ( F_37 ( V_20 , V_11 ) < 0 ) {
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
}
} else if ( F_3 ( V_20 ) < V_7
|| F_3 ( V_20 ) == V_52 ) {
F_8 ( L_6 ,
V_47 ? L_7 : L_8 , V_15 , V_12 , V_20 ) ;
V_32 = F_38 ( V_15 , V_12 , V_25 , V_11 , V_47 ) ;
if ( V_32 == V_33 )
V_34 = V_35 ;
else {
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
}
} else if ( F_3 ( V_20 ) == V_7 ) {
if ( F_34 ( V_20 , V_11 , V_47 ) < 0 )
V_34 = F_25 ( V_15 , V_12 , V_25 , V_11 , V_47 ) ;
} else if ( F_36 ( V_11 )
&& ( F_2 ( V_20 ) == V_5 || F_2 ( V_20 ) == V_6 ) ) {
V_34 = F_25 ( V_15 , V_12 , V_25 , V_11 , V_47 ) ;
} else {
F_6 ( L_9 ,
V_47 ? L_7 : L_8 , V_15 , V_12 , V_20 ) ;
F_7 () ;
F_12 ( V_11 ) ;
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
}
return V_34 ;
}
static int F_39 ( struct V_10 * V_11 )
{
return F_35 ( V_11 , true ) ;
}
static int F_40 ( struct V_10 * V_11 )
{
return F_35 ( V_11 , false ) ;
}
static int F_41 ( struct V_10 * V_11 )
{
struct V_30 * V_25 = V_11 -> V_25 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
unsigned long V_20 = V_11 -> V_13 . V_21 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
int V_34 = V_35 ;
if ( F_36 ( V_11 )
&& ( F_2 ( V_20 ) == V_5 || F_2 ( V_20 ) == V_6 ) ) {
V_34 = F_23 ( V_15 , V_12 , V_25 , V_11 ) ;
} else {
F_6 ( L_10 ,
V_15 , V_12 , V_20 ) ;
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
}
return V_34 ;
}
static int F_42 ( struct V_10 * V_11 )
{
struct V_30 * V_25 = V_11 -> V_25 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
unsigned long V_20 = V_11 -> V_13 . V_21 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
int V_34 = V_35 ;
if ( F_2 ( V_20 ) == V_5 || F_2 ( V_20 ) == V_6 ) {
V_34 = F_20 ( V_15 , V_12 , V_25 , V_11 ) ;
} else {
F_6 ( L_11 ,
V_15 , V_12 , V_20 ) ;
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
}
return V_34 ;
}
static int F_43 ( struct V_10 * V_11 )
{
struct V_30 * V_25 = V_11 -> V_25 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
enum V_31 V_32 = V_33 ;
int V_34 = V_35 ;
V_32 = F_44 ( V_15 , V_12 , V_25 , V_11 ) ;
if ( V_32 == V_33 )
V_34 = V_35 ;
else {
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
}
return V_34 ;
}
static int F_45 ( struct V_10 * V_11 )
{
struct V_30 * V_25 = V_11 -> V_25 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
enum V_31 V_32 = V_33 ;
int V_34 = V_35 ;
V_32 = F_46 ( V_15 , V_12 , V_25 , V_11 ) ;
if ( V_32 == V_33 )
V_34 = V_35 ;
else {
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
}
return V_34 ;
}
static int F_47 ( struct V_10 * V_11 )
{
struct V_30 * V_25 = V_11 -> V_25 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
enum V_31 V_32 = V_33 ;
int V_34 = V_35 ;
V_32 = F_48 ( V_15 , V_12 , V_25 , V_11 ) ;
if ( V_32 == V_33 )
V_34 = V_35 ;
else {
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
}
return V_34 ;
}
static int F_49 ( struct V_10 * V_11 )
{
struct V_30 * V_25 = V_11 -> V_25 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
enum V_31 V_32 = V_33 ;
int V_34 = V_35 ;
V_32 = F_50 ( V_15 , V_12 , V_25 , V_11 ) ;
if ( V_32 == V_33 ) {
V_34 = V_35 ;
} else {
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
}
return V_34 ;
}
static int F_51 ( struct V_10 * V_11 )
{
struct V_30 * V_25 = V_11 -> V_25 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
enum V_31 V_32 = V_33 ;
int V_34 = V_35 ;
V_32 = F_52 ( V_15 , V_12 , V_25 , V_11 ) ;
if ( V_32 == V_33 ) {
V_34 = V_35 ;
} else {
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
}
return V_34 ;
}
static int F_53 ( struct V_10 * V_11 )
{
struct V_30 * V_25 = V_11 -> V_25 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
enum V_31 V_32 = V_33 ;
int V_34 = V_35 ;
V_32 = F_54 ( V_15 , V_12 , V_25 , V_11 ) ;
if ( V_32 == V_33 ) {
V_34 = V_35 ;
} else {
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
}
return V_34 ;
}
static int F_55 ( struct V_10 * V_11 )
{
struct V_29 * V_24 = V_11 -> V_13 . V_24 ;
struct V_30 * V_25 = V_11 -> V_25 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_11 -> V_13 . V_14 ;
T_3 V_15 = V_11 -> V_13 . V_16 ;
enum V_31 V_32 = V_33 ;
int V_34 = V_35 ;
if ( ! F_56 ( & V_11 -> V_13 ) ||
( F_11 ( V_24 ) & ( V_38 | V_58 ) ) == V_38 ) {
V_32 = F_57 ( V_15 , V_12 , V_25 , V_11 ) ;
} else if ( ! ( F_58 ( V_24 ) & V_59 ) ) {
V_32 = F_59 ( V_15 , V_12 , V_25 , V_11 ) ;
} else {
F_60 ( V_11 ) ;
V_32 = V_33 ;
}
switch ( V_32 ) {
case V_33 :
V_34 = V_35 ;
break;
case V_39 :
V_25 -> V_26 = V_27 ;
V_34 = V_28 ;
break;
default:
F_19 () ;
}
return V_34 ;
}
static int F_61 ( void )
{
return 0 ;
}
static void F_62 ( void )
{
}
static int F_63 ( struct V_60 * V_60 , long V_61 )
{
int V_62 ;
switch ( V_61 ) {
case V_63 :
V_62 = 1 ;
break;
default:
V_62 = 0 ;
break;
}
return V_62 ;
}
static int F_64 ( struct V_10 * V_11 )
{
struct V_64 * V_65 = & V_11 -> V_13 . V_66 ;
struct V_64 * V_67 = & V_11 -> V_13 . V_68 ;
V_65 -> V_69 = F_65 ( V_65 ) ;
if ( ! V_65 -> V_69 )
return - V_70 ;
V_67 -> V_69 = F_65 ( V_67 ) ;
if ( ! V_67 -> V_69 ) {
F_66 ( V_65 , V_65 -> V_69 ) ;
return - V_70 ;
}
return 0 ;
}
static void F_67 ( T_5 * V_69 )
{
const unsigned long V_71 = 0x80000000 ;
unsigned long V_72 , V_73 , V_74 ;
T_6 * V_75 ;
T_7 * V_76 ;
T_8 * V_77 ;
int V_78 , V_79 , V_80 ;
for ( V_78 = 0 ; V_78 < V_81 ; V_78 ++ ) {
if ( F_68 ( V_69 [ V_78 ] ) )
continue;
V_72 = ( unsigned long ) V_78 << V_82 ;
if ( V_72 >= V_71 )
break;
V_75 = F_69 ( V_69 + V_78 , 0 ) ;
for ( V_79 = 0 ; V_79 < V_83 ; V_79 ++ ) {
if ( F_70 ( V_75 [ V_79 ] ) )
continue;
V_73 = V_72 | ( ( unsigned long ) V_79 << V_84 ) ;
if ( V_73 >= V_71 )
break;
V_76 = F_71 ( V_75 + V_79 , 0 ) ;
for ( V_80 = 0 ; V_80 < V_85 ; V_80 ++ ) {
if ( F_72 ( V_76 [ V_80 ] ) )
continue;
V_74 = V_73 | ( V_80 << V_86 ) ;
if ( V_74 >= V_71 )
break;
V_77 = F_73 ( V_76 + V_80 , 0 ) ;
F_74 ( NULL , V_77 ) ;
}
F_75 ( NULL , V_76 ) ;
}
F_76 ( NULL , V_75 ) ;
}
F_66 ( NULL , V_69 ) ;
}
static void F_77 ( struct V_10 * V_11 )
{
F_67 ( V_11 -> V_13 . V_66 . V_69 ) ;
F_67 ( V_11 -> V_13 . V_68 . V_69 ) ;
}
static int F_78 ( struct V_10 * V_11 )
{
struct V_29 * V_24 = V_11 -> V_13 . V_24 ;
T_3 V_87 , V_88 ;
int V_89 = V_11 -> V_89 ;
F_79 ( V_11 , 100 * 1000 * 1000 ) ;
#ifndef F_80
F_81 ( V_24 , 0x00019300 ) ;
#else
F_81 ( V_24 , 0x00010000 ) ;
#endif
V_87 = F_82 () & V_90 ;
V_87 |= V_91 | V_92 | V_93 ;
#ifdef F_83
V_87 |= V_94 ;
#endif
if ( V_95 )
V_87 |= V_96 ;
F_84 ( V_24 , V_87 ) ;
V_88 = ( F_85 () & ~ 0x7f ) ;
if ( F_86 () ) {
V_88 &= ~ V_97 ;
V_88 |= ( ( F_87 ( F_86 () ) - 1 ) <<
V_98 ) & V_97 ;
}
V_88 &= ~ ( 0x3f << 25 ) ;
V_88 |= ( ( V_99 - 1 ) << 25 ) ;
V_88 &= ~ ( V_100 | V_101 | V_102 |
V_103 | V_104 ) ;
F_88 ( V_24 , V_88 ) ;
F_89 ( V_24 , V_91 ) ;
F_90 ( V_24 , V_91 | V_105 ) ;
F_91 ( V_24 , V_91 ) ;
F_92 ( V_24 , 0 ) ;
F_93 ( V_24 , ( V_106 ) | ( 1 << 10 ) ) ;
F_94 ( V_24 , V_107 | V_108 ) ;
F_95 ( V_24 , 0xFC000000 ) ;
F_96 ( V_24 , V_7 |
( V_89 & V_109 ) ) ;
V_11 -> V_13 . V_14 = F_97 ( 0x1fc00000 ) ;
return 0 ;
}
static void F_98 ( struct V_60 * V_60 )
{
F_99 ( V_60 ) ;
}
static void F_100 ( struct V_60 * V_60 ,
const struct V_110 * V_111 )
{
F_98 ( V_60 ) ;
}
static unsigned long F_101 ( struct V_10 * V_11 )
{
return F_102 ( V_112 ) ;
}
static int F_103 ( struct V_10 * V_11 ,
T_9 T_4 * V_113 )
{
if ( F_104 ( V_113 , V_112 ,
sizeof( V_112 ) ) )
return - V_114 ;
V_113 += F_102 ( V_112 ) ;
return 0 ;
}
static int F_105 ( struct V_10 * V_11 ,
const struct V_115 * V_116 ,
T_10 * V_117 )
{
struct V_29 * V_24 = V_11 -> V_13 . V_24 ;
switch ( V_116 -> V_118 ) {
case V_119 :
* V_117 = ( long ) F_106 ( V_24 ) ;
break;
case V_120 :
* V_117 = F_107 ( V_24 ) ;
break;
case V_121 :
* V_117 = F_108 ( V_24 ) ;
break;
case V_122 :
* V_117 = ( long ) F_109 ( V_24 ) ;
break;
case V_123 :
* V_117 = ( long ) F_110 ( V_24 ) ;
break;
case V_124 :
* V_117 = ( long ) F_111 ( V_24 ) ;
break;
case V_125 :
* V_117 = ( long ) F_112 ( V_24 ) ;
break;
case V_126 :
* V_117 = ( long ) F_113 ( V_24 ) ;
break;
case V_127 :
* V_117 = ( long ) F_114 ( V_24 ) ;
break;
case V_128 :
* V_117 = ( long ) F_27 ( V_24 ) ;
break;
case V_129 :
* V_117 = ( long ) F_115 ( V_24 ) ;
break;
case V_130 :
* V_117 = ( long ) F_11 ( V_24 ) ;
break;
case V_131 :
* V_117 = ( long ) F_116 ( V_24 ) ;
break;
case V_132 :
* V_117 = ( long ) F_117 ( V_24 ) ;
break;
case V_133 :
* V_117 = ( long ) F_118 ( V_24 ) ;
break;
case V_134 :
* V_117 = ( long ) F_119 ( V_24 ) ;
break;
case V_135 :
* V_117 = ( long ) F_120 ( V_24 ) ;
break;
case V_136 :
* V_117 = ( long ) F_121 ( V_24 ) ;
break;
case V_137 :
* V_117 = ( long ) F_122 ( V_24 ) ;
break;
case V_138 :
* V_117 = ( long ) F_123 ( V_24 ) ;
break;
case V_139 :
* V_117 = ( long ) F_124 ( V_24 ) ;
break;
case V_140 :
* V_117 = ( long ) F_125 ( V_24 ) ;
break;
case V_141 :
* V_117 = ( long ) F_58 ( V_24 ) ;
break;
case V_142 :
* V_117 = ( long ) F_126 ( V_24 ) ;
break;
case V_143 :
* V_117 = F_127 ( V_11 ) ;
break;
case V_144 :
* V_117 = V_11 -> V_13 . V_145 ;
break;
case V_146 :
* V_117 = F_128 ( V_11 -> V_13 . V_147 ) ;
break;
case V_148 :
* V_117 = V_11 -> V_13 . V_149 ;
break;
case V_150 :
* V_117 = ( long ) F_129 ( V_24 ) ;
break;
case V_151 :
* V_117 = ( long ) F_130 ( V_24 ) ;
break;
case V_152 :
* V_117 = ( long ) F_131 ( V_24 ) ;
break;
case V_153 :
* V_117 = ( long ) F_132 ( V_24 ) ;
break;
case V_154 :
* V_117 = ( long ) F_133 ( V_24 ) ;
break;
case V_155 :
* V_117 = ( long ) F_134 ( V_24 ) ;
break;
case V_156 :
* V_117 = ( long ) F_135 ( V_24 ) ;
break;
default:
return - V_157 ;
}
return 0 ;
}
static int F_136 ( struct V_10 * V_11 ,
const struct V_115 * V_116 ,
T_10 V_117 )
{
struct V_29 * V_24 = V_11 -> V_13 . V_24 ;
int V_34 = 0 ;
unsigned int V_158 , V_159 ;
switch ( V_116 -> V_118 ) {
case V_119 :
F_137 ( V_24 , V_117 ) ;
break;
case V_120 :
F_138 ( V_24 , V_117 ) ;
break;
case V_121 :
F_139 ( V_24 , V_117 ) ;
break;
case V_122 :
F_140 ( V_24 , V_117 ) ;
break;
case V_123 :
F_141 ( V_24 , V_117 ) ;
break;
case V_124 :
F_142 ( V_24 , V_117 ) ;
break;
case V_125 :
F_143 ( V_24 , V_117 ) ;
break;
case V_126 :
F_144 ( V_24 , V_117 ) ;
break;
case V_127 :
F_145 ( V_24 , V_117 ) ;
break;
case V_128 :
F_146 ( V_24 , V_117 ) ;
break;
case V_130 :
F_94 ( V_24 , V_117 ) ;
break;
case V_131 :
break;
case V_133 :
F_147 ( V_24 , V_117 ) ;
break;
case V_134 :
F_81 ( V_24 , V_117 ) ;
break;
case V_135 :
F_148 ( V_24 , 0x1ffff000 | V_109 ,
V_117 ) ;
break;
case V_143 :
F_149 ( V_11 , V_117 ) ;
break;
case V_129 :
F_150 ( V_11 , V_117 , false ) ;
break;
case V_132 :
if ( ( F_117 ( V_24 ) ^ V_117 ) & V_160 ) {
if ( V_117 & V_160 ) {
F_151 ( V_11 ) ;
F_152 ( V_24 , ( T_3 ) ~ V_160 ,
V_117 ) ;
} else {
F_152 ( V_24 , ( T_3 ) ~ V_160 ,
V_117 ) ;
F_153 ( V_11 ) ;
}
} else {
F_154 ( V_24 , V_117 ) ;
}
break;
case V_136 :
break;
case V_137 :
V_158 = F_122 ( V_24 ) ;
V_159 = ( V_158 ^ V_117 ) & F_155 ( V_11 ) ;
if ( V_159 ) {
V_117 = V_158 ^ V_159 ;
F_88 ( V_24 , V_117 ) ;
}
break;
case V_138 :
break;
case V_139 :
V_158 = F_124 ( V_24 ) ;
V_159 = ( V_158 ^ V_117 ) & F_156 ( V_11 ) ;
if ( V_159 ) {
V_117 = V_158 ^ V_159 ;
F_90 ( V_24 , V_117 ) ;
}
break;
case V_140 :
V_158 = F_125 ( V_24 ) ;
V_159 = ( V_158 ^ V_117 ) & F_157 ( V_11 ) ;
if ( V_159 ) {
V_117 = V_158 ^ V_159 ;
F_91 ( V_24 , V_117 ) ;
}
break;
case V_141 :
V_158 = F_58 ( V_24 ) ;
V_159 = ( V_158 ^ V_117 ) & F_158 ( V_11 ) ;
if ( V_159 ) {
V_117 = V_158 ^ V_159 ;
F_92 ( V_24 , V_117 ) ;
}
break;
case V_142 :
break;
case V_144 :
V_34 = F_159 ( V_11 , V_117 ) ;
break;
case V_146 :
V_34 = F_160 ( V_11 , V_117 ) ;
break;
case V_148 :
V_34 = F_161 ( V_11 , V_117 ) ;
break;
case V_150 :
F_162 ( V_24 , V_117 ) ;
break;
case V_151 :
F_163 ( V_24 , V_117 ) ;
break;
case V_152 :
F_164 ( V_24 , V_117 ) ;
break;
case V_153 :
F_165 ( V_24 , V_117 ) ;
break;
case V_154 :
F_166 ( V_24 , V_117 ) ;
break;
case V_155 :
F_167 ( V_24 , V_117 ) ;
break;
case V_156 :
F_168 ( V_24 , V_117 ) ;
break;
default:
return - V_157 ;
}
return V_34 ;
}
static int F_169 ( struct V_10 * V_11 , int V_161 )
{
struct V_64 * V_65 = & V_11 -> V_13 . V_66 ;
struct V_64 * V_67 = & V_11 -> V_13 . V_68 ;
struct V_64 * V_162 ;
if ( V_163 -> V_164 & V_165 ) {
V_162 = F_36 ( V_11 ) ? V_65 : V_67 ;
if ( ( F_170 ( V_161 , V_162 ) ^ F_171 ( V_161 ) ) &
F_172 ( V_161 ) )
F_173 ( V_162 , V_161 ) ;
F_174 ( F_175 ( V_161 , V_162 ) ) ;
F_176 ( V_162 -> V_69 ) ;
F_177 ( V_161 ) ;
F_178 () ;
}
return 0 ;
}
static int F_179 ( struct V_10 * V_11 , int V_161 )
{
F_180 ( V_11 ) ;
if ( V_163 -> V_164 & V_165 ) {
if ( ( ( F_170 ( V_161 , V_163 -> V_162 ) ^ F_171 ( V_161 ) ) &
F_172 ( V_161 ) ) )
F_173 ( V_163 -> V_162 , V_161 ) ;
F_174 ( F_175 ( V_161 , V_163 -> V_162 ) ) ;
F_176 ( V_163 -> V_162 -> V_69 ) ;
F_181 ( V_161 ) ;
F_178 () ;
}
return 0 ;
}
static void F_182 ( struct V_10 * V_11 , int V_161 ,
bool V_166 )
{
struct V_64 * V_65 = & V_11 -> V_13 . V_66 ;
struct V_64 * V_67 = & V_11 -> V_13 . V_68 ;
struct V_64 * V_162 ;
int V_78 ;
if ( F_183 ( ! F_184 ( V_11 ) ) )
return;
if ( F_185 ( V_167 , V_11 ) ) {
F_186 ( V_65 -> V_69 , V_168 | V_169 ) ;
F_186 ( V_67 -> V_69 , V_168 | V_170 ) ;
F_187 (i) {
F_170 ( V_78 , V_65 ) = 0 ;
F_170 ( V_78 , V_67 ) = 0 ;
}
if ( V_166 ) {
V_162 = F_36 ( V_11 ) ? V_65 : V_67 ;
F_173 ( V_162 , V_161 ) ;
F_188 () ;
F_174 ( F_175 ( V_161 , V_162 ) ) ;
F_176 ( V_162 -> V_69 ) ;
F_189 () ;
}
}
}
void F_190 ( struct V_10 * V_11 )
{
F_191 ( F_192 () ) ;
F_193 () ;
F_194 ( V_11 -> V_171 , V_172 ) ;
F_182 ( V_11 , F_195 () , true ) ;
}
void F_196 ( struct V_10 * V_11 )
{
F_197 ( & V_11 -> V_171 , V_173 ) ;
F_198 () ;
}
static void F_199 ( struct V_30 * V_25 ,
struct V_10 * V_11 )
{
struct V_64 * V_65 = & V_11 -> V_13 . V_66 ;
struct V_64 * V_67 = & V_11 -> V_13 . V_68 ;
struct V_64 * V_162 ;
struct V_29 * V_24 = V_11 -> V_13 . V_24 ;
int V_78 , V_161 = F_195 () ;
unsigned int V_174 ;
F_182 ( V_11 , V_161 , false ) ;
if ( F_36 ( V_11 ) ) {
V_162 = V_65 ;
} else {
V_162 = V_67 ;
V_174 = F_27 ( V_24 ) & V_54 ;
if ( V_174 != V_11 -> V_13 . V_175 ) {
F_186 ( V_67 -> V_69 , V_170 ) ;
F_187 (i)
F_170 ( V_78 , V_67 ) = 0 ;
V_11 -> V_13 . V_175 = V_174 ;
}
}
if ( ( F_170 ( V_161 , V_162 ) ^ F_171 ( V_161 ) ) &
F_172 ( V_161 ) )
F_173 ( V_162 , V_161 ) ;
}
static int F_200 ( struct V_30 * V_25 , struct V_10 * V_11 )
{
int V_161 = F_195 () ;
int V_62 ;
F_201 ( V_11 ,
F_117 ( V_11 -> V_13 . V_24 ) ) ;
F_199 ( V_25 , V_11 ) ;
F_202 () ;
F_188 () ;
F_177 ( V_161 ) ;
V_62 = V_11 -> V_13 . V_176 ( V_25 , V_11 ) ;
V_161 = F_195 () ;
if ( ( ( F_170 ( V_161 , V_163 -> V_162 ) ^ F_171 ( V_161 ) ) &
F_172 ( V_161 ) ) )
F_173 ( V_163 -> V_162 , V_161 ) ;
F_174 ( F_175 ( V_161 , V_163 -> V_162 ) ) ;
F_176 ( V_163 -> V_162 -> V_69 ) ;
F_181 ( V_161 ) ;
F_189 () ;
F_203 () ;
return V_62 ;
}
int F_204 ( struct V_177 * * V_178 )
{
* V_178 = & V_179 ;
return 0 ;
}
