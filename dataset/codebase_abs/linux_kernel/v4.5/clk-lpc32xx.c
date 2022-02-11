static inline bool F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
return ( V_1 >= ( V_2 * V_3 ) && V_1 <= ( V_2 * V_4 ) ) ;
}
static inline T_2 F_2 ( struct V_5 * V_6 )
{
return F_3 ( V_7 + V_8 ) ;
}
static inline void F_4 ( struct V_5 * V_6 , T_2 V_9 )
{
F_5 ( V_9 , V_7 + V_10 ) ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_6 = F_7 ( V_12 ) ;
T_2 V_9 ;
F_8 ( V_14 , V_6 -> V_15 , & V_9 ) ;
if ( V_6 -> V_16 && ( V_9 & V_6 -> V_16 ) == V_6 -> V_17 )
return - V_18 ;
return F_9 ( V_14 , V_6 -> V_15 ,
V_6 -> V_19 , V_6 -> V_20 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
struct V_13 * V_6 = F_7 ( V_12 ) ;
F_9 ( V_14 , V_6 -> V_15 ,
V_6 -> V_21 , V_6 -> V_22 ) ;
}
static int F_11 ( struct V_11 * V_12 )
{
struct V_13 * V_6 = F_7 ( V_12 ) ;
T_2 V_9 ;
F_8 ( V_14 , V_6 -> V_15 , & V_9 ) ;
return ( ( V_9 & V_6 -> V_19 ) == V_6 -> V_20 ) ;
}
static int F_12 ( struct V_11 * V_12 )
{
struct V_23 * V_6 = F_13 ( V_12 ) ;
T_2 V_9 , V_24 ;
F_9 ( V_14 , V_6 -> V_15 , V_6 -> V_20 , V_6 -> V_20 ) ;
for ( V_24 = 0 ; V_24 < 1000 ; V_24 ++ ) {
F_8 ( V_14 , V_6 -> V_15 , & V_9 ) ;
if ( V_9 & V_25 )
break;
}
if ( V_9 & V_25 )
return 0 ;
return - V_26 ;
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_23 * V_6 = F_13 ( V_12 ) ;
F_9 ( V_14 , V_6 -> V_15 , V_6 -> V_20 , 0x0 ) ;
}
static int F_15 ( struct V_11 * V_12 )
{
struct V_23 * V_6 = F_13 ( V_12 ) ;
T_2 V_9 ;
F_8 ( V_14 , V_6 -> V_15 , & V_9 ) ;
V_9 &= V_6 -> V_20 | V_25 ;
if ( V_9 == ( V_6 -> V_20 | V_25 ) )
return 1 ;
return 0 ;
}
static unsigned long F_16 ( struct V_11 * V_12 ,
unsigned long V_27 )
{
return V_27 * 397 ;
}
static unsigned long F_17 ( struct V_11 * V_12 ,
unsigned long V_27 )
{
struct V_23 * V_6 = F_13 ( V_12 ) ;
bool V_28 , V_29 , V_30 ;
unsigned long V_31 , V_32 , V_33 ;
T_2 V_9 ;
F_8 ( V_14 , V_6 -> V_15 , & V_9 ) ;
V_28 = V_9 & V_34 ;
V_29 = V_9 & V_35 ;
V_30 = V_9 & V_36 ;
V_6 -> V_37 = ( ( V_9 & V_38 ) >> 1 ) + 1 ;
V_6 -> V_39 = ( ( V_9 & V_40 ) >> 9 ) + 1 ;
V_6 -> V_41 = ( ( V_9 & V_42 ) >> 11 ) + 1 ;
if ( V_28 && V_29 ) {
V_6 -> V_41 = 0 ;
V_6 -> V_43 = V_44 ;
return V_27 ;
}
if ( V_29 ) {
V_6 -> V_43 = V_45 ;
return V_27 / ( 1 << V_6 -> V_41 ) ;
}
if ( V_28 ) {
V_6 -> V_41 = 0 ;
V_6 -> V_43 = V_46 ;
}
V_33 = V_27 / V_6 -> V_39 ;
V_31 = V_32 = V_33 * V_6 -> V_37 ;
if ( ! V_28 ) {
if ( V_30 ) {
V_32 *= ( 1 << V_6 -> V_41 ) ;
V_6 -> V_43 = V_47 ;
} else {
V_31 /= ( 1 << V_6 -> V_41 ) ;
V_6 -> V_43 = V_48 ;
}
}
F_18 ( L_1 ,
F_19 ( V_12 ) ,
V_27 , V_9 , V_28 , V_29 , V_30 ,
V_6 -> V_39 , V_6 -> V_37 , ( 1 << V_6 -> V_41 ) , V_31 ) ;
if ( F_15 ( V_12 ) &&
! ( F_1 ( V_27 , 1 , 1000000 , 20000000 )
&& F_1 ( V_32 , 1 , 156000000 , 320000000 )
&& F_1 ( V_33 , 1 , 1000000 , 27000000 ) ) )
F_20 ( L_2 ,
F_19 ( V_12 ) ,
V_27 , V_32 , V_33 ) ;
return V_31 ;
}
static int F_21 ( struct V_11 * V_12 , unsigned long V_31 ,
unsigned long V_27 )
{
struct V_23 * V_6 = F_13 ( V_12 ) ;
T_2 V_9 ;
unsigned long V_49 ;
switch ( V_6 -> V_43 ) {
case V_46 :
V_9 = V_34 ;
V_9 |= ( V_6 -> V_37 - 1 ) << 1 ;
V_9 |= ( V_6 -> V_39 - 1 ) << 9 ;
V_49 = ( V_27 * V_6 -> V_37 ) / V_6 -> V_39 ;
break;
case V_45 :
V_9 = V_35 ;
V_9 |= ( V_6 -> V_41 - 1 ) << 11 ;
V_49 = V_27 / ( 1 << ( V_6 -> V_41 ) ) ;
break;
case V_44 :
V_9 = V_34 | V_35 ;
V_49 = V_27 ;
break;
case V_47 :
V_9 = V_36 ;
V_9 |= ( V_6 -> V_37 - 1 ) << 1 ;
V_9 |= ( V_6 -> V_39 - 1 ) << 9 ;
V_9 |= ( V_6 -> V_41 - 1 ) << 11 ;
V_49 = ( V_27 * V_6 -> V_37 ) / V_6 -> V_39 ;
break;
case V_48 :
V_9 = 0x0 ;
V_9 |= ( V_6 -> V_37 - 1 ) << 1 ;
V_9 |= ( V_6 -> V_39 - 1 ) << 9 ;
V_9 |= ( V_6 -> V_41 - 1 ) << 11 ;
V_49 = ( V_27 * V_6 -> V_37 ) /
( V_6 -> V_39 * ( 1 << V_6 -> V_41 ) ) ;
break;
default:
return - V_50 ;
}
if ( V_49 != V_31 )
return - V_50 ;
return F_9 ( V_14 , V_6 -> V_15 , 0x1FFFF , V_9 ) ;
}
static long F_22 ( struct V_11 * V_12 , unsigned long V_31 ,
unsigned long * V_27 )
{
struct V_23 * V_6 = F_13 ( V_12 ) ;
T_1 V_51 , V_52 , V_53 , V_54 , V_55 = V_31 , V_56 = * V_27 , V_57 = ( T_1 ) V_31 << 6 ;
int V_58 , V_59 ;
F_18 ( L_3 , F_19 ( V_12 ) , * V_27 , V_31 ) ;
if ( V_31 > 266500000 )
return - V_50 ;
for ( V_58 = 4 ; V_58 >= 0 ; V_58 -- ) {
for ( V_59 = 4 ; V_59 > 0 ; V_59 -- ) {
V_51 = F_23 ( V_55 * V_59 * ( 1 << V_58 ) , V_56 ) ;
if ( ! ( V_51 && V_51 <= 256
&& F_1 ( V_56 , V_59 , 1000000 , 27000000 )
&& F_1 ( V_56 * V_51 * ( 1 << V_58 ) , V_59 ,
156000000 , 320000000 ) ) )
continue;
if ( V_55 * V_59 * ( 1 << V_58 ) - V_56 * V_51 <= V_57 ) {
V_52 = V_51 ;
V_53 = V_59 ;
V_54 = V_58 ;
V_57 = V_55 * V_59 * ( 1 << V_58 ) - V_56 * V_51 ;
}
}
}
if ( V_57 == ( T_1 ) V_31 << 6 ) {
F_20 ( L_4 ,
F_19 ( V_12 ) , V_31 ) ;
return - V_50 ;
}
V_6 -> V_37 = V_52 ;
V_6 -> V_39 = V_53 ;
V_6 -> V_41 = V_54 ;
if ( ! V_54 )
V_6 -> V_43 = V_46 ;
else
V_6 -> V_43 = V_48 ;
V_55 = F_23 ( V_56 * V_52 , V_53 * ( 1 << V_54 ) ) ;
if ( ! V_57 )
F_18 ( L_5 ,
F_19 ( V_12 ) , V_31 , V_52 , V_53 , V_54 ) ;
else
F_18 ( L_6 ,
F_19 ( V_12 ) , V_31 , V_52 , V_53 , V_54 , V_55 ) ;
return V_55 ;
}
static long F_24 ( struct V_11 * V_12 , unsigned long V_31 ,
unsigned long * V_27 )
{
struct V_23 * V_6 = F_13 ( V_12 ) ;
struct V_11 * V_60 , * V_61 ;
T_1 V_62 , V_59 , V_52 , V_55 ;
F_18 ( L_3 , F_19 ( V_12 ) , * V_27 , V_31 ) ;
if ( V_31 != 48000000 )
return - V_50 ;
V_60 = F_25 ( V_12 , 0 ) ;
if ( ! V_60 )
return - V_50 ;
V_61 = F_25 ( V_60 , 0 ) ;
if ( ! V_61 )
return - V_50 ;
V_55 = F_26 ( V_61 ) ;
for ( V_62 = 16 ; V_62 >= 1 ; V_62 -- ) {
for ( V_59 = 1 ; V_59 <= 4 ; V_59 ++ ) {
V_52 = F_23 ( 192000000 * V_62 * V_59 , V_55 ) ;
if ( ! ( V_52 && V_52 <= 256
&& V_52 * V_55 == 192000000 * V_62 * V_59
&& F_1 ( V_55 , V_62 , 1000000 , 20000000 )
&& F_1 ( V_55 , V_62 * V_59 , 1000000 , 27000000 ) ) )
continue;
V_6 -> V_39 = V_59 ;
V_6 -> V_37 = V_52 ;
V_6 -> V_41 = 2 ;
V_6 -> V_43 = V_48 ;
* V_27 = F_23 ( V_55 , V_62 ) ;
return V_31 ;
}
}
return - V_50 ;
}
static int F_27 ( struct V_11 * V_12 )
{
struct V_13 * V_6 = F_7 ( V_12 ) ;
T_2 V_9 ;
F_8 ( V_14 , V_6 -> V_15 , & V_9 ) ;
V_9 &= V_6 -> V_19 | V_6 -> V_16 ;
return ( V_9 == ( F_28 ( 7 ) | F_28 ( 0 ) ) ||
V_9 == ( F_28 ( 8 ) | F_28 ( 1 ) ) ) ;
}
static int F_29 ( struct V_11 * V_12 )
{
struct V_13 * V_6 = F_7 ( V_12 ) ;
T_2 V_9 , V_63 ;
F_8 ( V_14 , V_6 -> V_15 , & V_9 ) ;
V_63 = V_9 & V_6 -> V_16 ;
if ( V_63 == 0x0 || V_63 == ( F_28 ( 1 ) | F_28 ( 0 ) ) )
return - V_50 ;
return F_9 ( V_14 , V_6 -> V_15 ,
V_6 -> V_19 , V_63 << 7 ) ;
}
static unsigned long F_30 ( struct V_11 * V_12 ,
unsigned long V_27 )
{
struct V_13 * V_6 = F_7 ( V_12 ) ;
T_2 V_9 ;
if ( ! F_27 ( V_12 ) )
return 0 ;
F_8 ( V_14 , V_6 -> V_15 , & V_9 ) ;
V_9 &= V_6 -> V_19 ;
return V_27 / ( V_9 >> 7 ) ;
}
static unsigned long F_31 ( struct V_11 * V_12 ,
unsigned long V_27 )
{
struct V_13 * V_6 = F_7 ( V_12 ) ;
T_2 V_9 , V_64 , V_65 ;
F_8 ( V_14 , V_6 -> V_15 , & V_9 ) ;
V_64 = ( V_9 & 0xFF00 ) >> 8 ;
V_65 = V_9 & 0xFF ;
if ( V_64 && V_65 )
return ( V_27 * V_64 ) / V_65 ;
else
return 0 ;
}
static int F_32 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = F_33 ( V_12 ) ;
T_2 V_9 , V_66 , V_24 ;
F_18 ( L_7 , F_19 ( V_12 ) , V_6 -> V_20 ) ;
if ( V_6 -> V_67 ) {
F_8 ( V_14 , V_68 , & V_66 ) ;
F_9 ( V_14 , V_68 ,
V_6 -> V_67 , V_6 -> V_69 ) ;
}
V_9 = F_2 ( V_6 ) ;
if ( V_6 -> V_17 && ( V_9 & V_6 -> V_17 ) == V_6 -> V_17 ) {
if ( V_6 -> V_67 )
F_34 ( V_14 , V_68 ,
V_66 ) ;
return - V_18 ;
}
V_9 |= V_6 -> V_20 ;
F_4 ( V_6 , V_9 ) ;
for ( V_24 = 0 ; V_24 < 1000 ; V_24 ++ ) {
V_9 = F_2 ( V_6 ) ;
if ( ( V_9 & V_6 -> V_20 ) == V_6 -> V_20 )
break;
}
if ( ( V_9 & V_6 -> V_20 ) == V_6 -> V_20 )
return 0 ;
if ( V_6 -> V_67 )
F_34 ( V_14 , V_68 , V_66 ) ;
return - V_26 ;
}
static void F_35 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = F_33 ( V_12 ) ;
T_2 V_9 = F_2 ( V_6 ) ;
V_9 &= ~ V_6 -> V_20 ;
F_4 ( V_6 , V_9 ) ;
if ( V_6 -> V_67 )
F_9 ( V_14 , V_68 ,
V_6 -> V_67 , V_6 -> V_70 ) ;
}
static int F_36 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = F_33 ( V_12 ) ;
T_2 V_66 , V_9 ;
if ( V_6 -> V_67 ) {
F_8 ( V_14 , V_68 , & V_66 ) ;
if ( ( V_66 & V_6 -> V_67 ) != V_6 -> V_69 )
return 0 ;
}
V_9 = F_2 ( V_6 ) ;
return ( ( V_9 & V_6 -> V_20 ) == V_6 -> V_20 ) ;
}
static unsigned long F_37 ( struct V_11 * V_12 ,
unsigned long V_27 )
{
return F_38 ( V_6 [ V_71 ] ) ;
}
static int F_39 ( struct V_11 * V_12 )
{
struct V_72 * V_6 = F_40 ( V_12 ) ;
T_2 V_73 = F_28 ( V_6 -> V_74 ) ;
T_2 V_9 = ( V_6 -> V_75 & V_76 ? 0x0 : V_73 ) ;
return F_9 ( V_14 , V_6 -> V_15 , V_73 , V_9 ) ;
}
static void F_41 ( struct V_11 * V_12 )
{
struct V_72 * V_6 = F_40 ( V_12 ) ;
T_2 V_73 = F_28 ( V_6 -> V_74 ) ;
T_2 V_9 = ( V_6 -> V_75 & V_76 ? V_73 : 0x0 ) ;
F_9 ( V_14 , V_6 -> V_15 , V_73 , V_9 ) ;
}
static int F_42 ( struct V_11 * V_12 )
{
struct V_72 * V_6 = F_40 ( V_12 ) ;
T_2 V_9 ;
bool V_77 ;
F_8 ( V_14 , V_6 -> V_15 , & V_9 ) ;
V_77 = V_9 & F_28 ( V_6 -> V_74 ) ;
return ( V_6 -> V_75 & V_76 ? ! V_77 : V_77 ) ;
}
static unsigned int F_43 ( const struct V_78 * V_79 ,
unsigned int V_9 )
{
const struct V_78 * V_80 ;
for ( V_80 = V_79 ; V_80 -> div ; V_80 ++ )
if ( V_80 -> V_9 == V_9 )
return V_80 -> div ;
return 0 ;
}
static unsigned int F_44 ( const struct V_78 * V_79 ,
unsigned int V_9 , unsigned long V_75 , T_3 V_81 )
{
if ( V_75 & V_82 )
return V_9 ;
if ( V_79 )
return F_43 ( V_79 , V_9 ) ;
return V_9 + 1 ;
}
static unsigned long F_45 ( struct V_11 * V_12 ,
unsigned long V_27 )
{
struct V_83 * V_84 = F_46 ( V_12 ) ;
unsigned int V_9 ;
F_8 ( V_14 , V_84 -> V_15 , & V_9 ) ;
V_9 >>= V_84 -> V_85 ;
V_9 &= F_47 ( V_84 -> V_81 ) ;
return F_48 ( V_12 , V_27 , V_9 , V_84 -> V_79 ,
V_84 -> V_75 ) ;
}
static long F_49 ( struct V_11 * V_12 , unsigned long V_31 ,
unsigned long * V_86 )
{
struct V_83 * V_84 = F_46 ( V_12 ) ;
unsigned int V_87 ;
if ( V_84 -> V_75 & V_88 ) {
F_8 ( V_14 , V_84 -> V_15 , & V_87 ) ;
V_87 >>= V_84 -> V_85 ;
V_87 &= F_47 ( V_84 -> V_81 ) ;
V_87 = F_44 ( V_84 -> V_79 , V_87 , V_84 -> V_75 ,
V_84 -> V_81 ) ;
return F_50 ( * V_86 , V_87 ) ;
}
return F_51 ( V_12 , V_31 , V_86 , V_84 -> V_79 ,
V_84 -> V_81 , V_84 -> V_75 ) ;
}
static int F_52 ( struct V_11 * V_12 , unsigned long V_31 ,
unsigned long V_27 )
{
struct V_83 * V_84 = F_46 ( V_12 ) ;
unsigned int V_89 ;
V_89 = F_53 ( V_31 , V_27 , V_84 -> V_79 ,
V_84 -> V_81 , V_84 -> V_75 ) ;
return F_9 ( V_14 , V_84 -> V_15 ,
F_47 ( V_84 -> V_81 ) << V_84 -> V_85 ,
V_89 << V_84 -> V_85 ) ;
}
static T_3 F_54 ( struct V_11 * V_12 )
{
struct V_90 * V_91 = F_55 ( V_12 ) ;
T_2 V_92 = F_56 ( V_12 ) ;
T_2 V_9 ;
F_8 ( V_14 , V_91 -> V_15 , & V_9 ) ;
V_9 >>= V_91 -> V_85 ;
V_9 &= V_91 -> V_73 ;
if ( V_91 -> V_79 ) {
T_2 V_56 ;
for ( V_56 = 0 ; V_56 < V_92 ; V_56 ++ )
if ( V_91 -> V_79 [ V_56 ] == V_9 )
return V_56 ;
return - V_50 ;
}
if ( V_9 >= V_92 )
return - V_50 ;
return V_9 ;
}
static int F_57 ( struct V_11 * V_12 , T_3 V_93 )
{
struct V_90 * V_91 = F_55 ( V_12 ) ;
if ( V_91 -> V_79 )
V_93 = V_91 -> V_79 [ V_93 ] ;
return F_9 ( V_14 , V_91 -> V_15 ,
V_91 -> V_73 << V_91 -> V_85 , V_93 << V_91 -> V_85 ) ;
}
static struct V_6 * T_4 F_58 ( T_2 V_94 )
{
const struct V_95 * V_13 = & V_96 [ V_94 ] ;
struct V_97 * V_11 = & V_97 [ V_94 ] ;
const char * V_98 [ V_99 ] ;
struct V_6 * V_6 ;
unsigned int V_56 ;
for ( V_56 = 0 ; V_56 < V_13 -> V_92 ; V_56 ++ )
V_98 [ V_56 ] = V_96 [ V_13 -> V_98 [ V_56 ] ] . V_100 ;
F_18 ( L_8 , V_13 -> V_100 ,
V_98 [ 0 ] , V_11 -> type ) ;
switch ( V_11 -> type ) {
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
{
struct V_107 V_108 = {
. V_100 = V_13 -> V_100 ,
. V_109 = V_98 ,
. V_92 = V_13 -> V_92 ,
. V_75 = V_13 -> V_75 ,
. V_110 = V_11 -> V_111 . V_110 ,
} ;
struct V_11 * V_12 ;
if ( V_11 -> type == V_101 )
V_12 = & V_11 -> V_111 . V_6 . V_12 ;
else if ( V_11 -> type == V_102 )
V_12 = & V_11 -> V_111 . V_112 . V_12 ;
else if ( V_11 -> type == V_103 )
V_12 = & V_11 -> V_111 . V_113 . V_12 ;
else if ( V_11 -> type == V_104 )
V_12 = & V_11 -> V_111 . V_91 . V_12 ;
else if ( V_11 -> type == V_105 )
V_12 = & V_11 -> V_111 . div . V_12 ;
else if ( V_11 -> type == V_106 )
V_12 = & V_11 -> V_111 . V_114 . V_12 ;
V_12 -> V_115 = & V_108 ;
V_6 = F_59 ( NULL , V_12 ) ;
break;
}
case V_116 :
{
struct V_11 * V_117 = NULL , * V_118 = NULL , * V_119 = NULL ;
const struct V_120 * V_121 = NULL , * V_122 = NULL , * V_123 = NULL ;
struct V_124 * V_125 , * V_126 , * V_127 ;
V_125 = V_11 -> V_128 . V_91 ;
V_126 = V_11 -> V_128 . div ;
V_127 = V_11 -> V_128 . V_114 ;
if ( V_125 ) {
V_121 = V_125 -> V_110 ;
V_117 = & V_125 -> V_6 . V_12 ;
}
if ( V_126 ) {
V_122 = V_126 -> V_110 ;
V_118 = & V_126 -> V_6 . V_12 ;
}
if ( V_127 ) {
V_123 = V_127 -> V_110 ;
V_119 = & V_127 -> V_6 . V_12 ;
}
V_6 = F_60 ( NULL , V_13 -> V_100 ,
V_98 , V_13 -> V_92 ,
V_117 , V_121 , V_118 , V_122 ,
V_119 , V_123 , V_13 -> V_75 ) ;
break;
}
case V_129 :
{
struct V_130 * V_131 = & V_11 -> V_132 ;
V_6 = F_61 ( NULL , V_13 -> V_100 ,
V_98 [ 0 ] , V_131 -> V_75 , V_131 -> V_133 ) ;
break;
}
default:
V_6 = F_62 ( - V_50 ) ;
}
return V_6 ;
}
static void T_4 F_63 ( struct V_134 * V_135 )
{
unsigned int V_56 ;
struct V_6 * V_136 , * V_137 ;
void T_5 * V_138 = NULL ;
V_137 = F_64 ( V_135 , V_96 [ V_139 ] . V_100 ) ;
if ( F_65 ( V_137 ) ) {
F_20 ( L_9 ,
F_66 ( V_137 ) ) ;
return;
}
if ( F_38 ( V_137 ) != 32768 ) {
F_20 ( L_10 ) ;
return;
}
V_136 = F_64 ( V_135 , V_96 [ V_140 ] . V_100 ) ;
if ( F_65 ( V_136 ) ) {
F_20 ( L_11 ,
F_66 ( V_136 ) ) ;
return;
}
V_138 = F_67 ( V_135 , 0 ) ;
if ( ! V_138 ) {
F_20 ( L_12 ) ;
return;
}
V_14 = F_68 ( NULL , V_138 , & V_141 ) ;
if ( F_65 ( V_14 ) ) {
F_20 ( L_13 ,
F_66 ( V_14 ) ) ;
return;
}
for ( V_56 = 0 ; V_56 < V_142 ; V_56 ++ ) {
V_6 [ V_56 ] = F_58 ( V_56 ) ;
if ( F_65 ( V_6 [ V_56 ] ) ) {
F_20 ( L_14 ,
V_96 [ V_56 ] . V_100 , F_66 ( V_6 [ V_56 ] ) ) ;
V_6 [ V_56 ] = NULL ;
}
}
F_69 ( V_135 , V_143 , & V_144 ) ;
F_70 ( V_6 [ V_145 ] , 208000000 ) ;
F_70 ( V_6 [ V_146 ] , 48000000 ) ;
F_71 ( V_6 [ V_147 ] ) ;
F_71 ( V_6 [ V_148 ] ) ;
F_71 ( V_6 [ V_149 ] ) ;
F_10 ( & V_97 [ V_150 ] . V_111 . V_6 . V_12 ) ;
F_10 ( & V_97 [ V_151 ] . V_111 . V_6 . V_12 ) ;
}
static void T_4 F_72 ( struct V_134 * V_135 )
{
unsigned int V_56 ;
V_7 = F_67 ( V_135 , 0 ) ;
if ( ! V_7 ) {
F_20 ( L_15 ) ;
return;
}
for ( V_56 = 0 ; V_56 < V_152 ; V_56 ++ ) {
V_113 [ V_56 ] = F_58 ( V_56 + V_153 ) ;
if ( F_65 ( V_113 [ V_56 ] ) ) {
F_20 ( L_14 ,
V_96 [ V_56 ] . V_100 , F_66 ( V_113 [ V_56 ] ) ) ;
V_113 [ V_56 ] = NULL ;
}
}
F_69 ( V_135 , V_143 , & V_154 ) ;
}
