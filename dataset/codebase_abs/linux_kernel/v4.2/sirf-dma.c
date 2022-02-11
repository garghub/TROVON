static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_2 ( V_6 , struct V_5 , V_7 [ V_3 -> V_8 ] ) ;
}
static void F_4 ( struct V_9 * V_10 ,
int V_11 , int V_12 , void T_1 * V_13 )
{
if ( V_10 -> V_14 ) {
F_5 ( ( V_10 -> V_15 << V_16 ) |
( V_10 -> V_14 <<
V_17 ) |
( 0x8 << V_18 ) | 0x3 ,
V_13 + V_19 ) ;
} else {
F_5 ( V_10 -> V_20 , V_13 + V_21 ) ;
F_5 ( V_10 -> V_22 , V_13 + V_23 ) ;
F_5 ( V_10 -> V_24 , V_13 + V_25 ) ;
F_5 ( ( V_10 -> V_24 * ( ( V_10 -> V_22 + 1 ) >> 1 ) ) ,
V_13 + V_26 ) ;
F_5 ( ( V_10 -> V_15 << V_16 ) |
( V_10 -> V_14 <<
V_17 ) |
0x3 , V_13 + V_19 ) ;
}
F_5 ( V_10 -> V_14 ? V_27 :
( V_28 |
V_29 ) ,
V_13 + V_30 ) ;
F_6 ( V_10 -> V_31 , V_13 + V_32 ) ;
if ( V_10 -> V_33 )
F_6 ( 0x10001 , V_13 + V_34 ) ;
}
static void F_7 ( struct V_9 * V_10 ,
int V_11 , int V_12 , void T_1 * V_13 )
{
F_5 ( 1 , V_13 + V_35 ) ;
F_5 ( ( 1 << V_11 ) , V_13 + V_36 ) ;
F_5 ( V_10 -> V_24 , V_13 + V_37 + V_11 * 4 ) ;
F_5 ( V_11 | ( V_12 << V_38 ) |
( V_10 -> V_15 << V_39 ) ,
V_13 + V_11 * 0x10 + V_19 ) ;
F_5 ( V_10 -> V_20 , V_13 + V_11 * 0x10 + V_21 ) ;
F_5 ( V_10 -> V_22 , V_13 + V_11 * 0x10 + V_23 ) ;
F_5 ( F_8 ( V_13 + V_40 ) |
( 1 << V_11 ) , V_13 + V_40 ) ;
F_6 ( V_10 -> V_31 >> 2 , V_13 + V_11 * 0x10 + V_32 ) ;
if ( V_10 -> V_33 ) {
F_6 ( ( 1 << V_11 ) | 1 << ( V_11 + 16 ) |
F_8 ( V_13 + V_41 ) ,
V_13 + V_41 ) ;
}
}
static void F_9 ( struct V_9 * V_10 ,
int V_11 , int V_12 , void T_1 * V_13 )
{
F_5 ( V_10 -> V_24 , V_13 + V_37 + V_11 * 4 ) ;
F_5 ( V_11 | ( V_12 << V_38 ) |
( V_10 -> V_15 << V_39 ) ,
V_13 + V_11 * 0x10 + V_19 ) ;
F_5 ( V_10 -> V_20 , V_13 + V_11 * 0x10 + V_21 ) ;
F_5 ( V_10 -> V_22 , V_13 + V_11 * 0x10 + V_23 ) ;
F_5 ( F_8 ( V_13 + V_40 ) |
( 1 << V_11 ) , V_13 + V_40 ) ;
F_6 ( V_10 -> V_31 >> 2 , V_13 + V_11 * 0x10 + V_32 ) ;
if ( V_10 -> V_33 ) {
F_6 ( ( 1 << V_11 ) | 1 << ( V_11 + 16 ) |
F_8 ( V_13 + V_42 ) ,
V_13 + V_42 ) ;
}
}
static void F_10 ( struct V_1 * V_6 )
{
struct V_5 * V_43 = F_3 ( & V_6 -> V_4 ) ;
int V_11 = V_6 -> V_4 . V_8 ;
struct V_9 * V_10 = NULL ;
void T_1 * V_13 ;
V_13 = V_43 -> V_13 ;
V_10 = F_11 ( & V_6 -> V_44 , struct V_9 ,
V_45 ) ;
F_12 ( & V_10 -> V_45 , & V_6 -> V_46 ) ;
if ( V_43 -> type == V_47 )
V_11 = 0 ;
V_43 -> V_48 ( V_10 , V_11 , V_6 -> V_49 , V_13 ) ;
if ( V_10 -> V_33 )
V_6 -> V_50 = V_6 -> V_51 = 0 ;
}
static T_2 F_13 ( int V_52 , void * V_53 )
{
struct V_5 * V_43 = V_53 ;
struct V_1 * V_6 ;
struct V_9 * V_10 = NULL ;
T_3 V_54 ;
bool V_14 ;
int V_55 ;
void T_1 * V_56 ;
switch ( V_43 -> type ) {
case V_57 :
case V_58 :
V_54 = F_14 ( V_43 -> V_13 + V_59 ) ;
V_56 = V_43 -> V_13 + V_59 ;
while ( ( V_55 = F_15 ( V_54 ) - 1 ) >= 0 ) {
V_54 &= ~ ( 1 << V_55 ) ;
F_5 ( 1 << V_55 , V_56 ) ;
V_6 = & V_43 -> V_7 [ V_55 ] ;
F_16 ( & V_6 -> V_60 ) ;
V_10 = F_11 ( & V_6 -> V_46 ,
struct V_9 , V_45 ) ;
if ( ! V_10 -> V_33 ) {
F_17 ( & V_6 -> V_46 ,
& V_6 -> V_61 ) ;
F_18 ( & V_10 -> V_62 ) ;
if ( ! F_19 ( & V_6 -> V_44 ) )
F_10 ( V_6 ) ;
} else
V_6 -> V_50 ++ ;
F_20 ( & V_6 -> V_60 ) ;
}
break;
case V_47 :
V_54 = F_14 ( V_43 -> V_13 + V_63 ) ;
V_56 = V_43 -> V_13 + V_63 ;
F_5 ( V_64 , V_56 ) ;
V_6 = & V_43 -> V_7 [ 0 ] ;
F_16 ( & V_6 -> V_60 ) ;
V_10 = F_11 ( & V_6 -> V_46 ,
struct V_9 , V_45 ) ;
if ( ! V_10 -> V_33 ) {
V_14 = V_10 -> V_14 ;
if ( ( V_14 && ( V_54 & V_27 ) ) ||
( ! V_14 &&
( V_54 & V_28 ) ) ) {
F_17 ( & V_6 -> V_46 ,
& V_6 -> V_61 ) ;
F_18 ( & V_10 -> V_62 ) ;
if ( ! F_19 ( & V_6 -> V_44 ) )
F_10 ( V_6 ) ;
}
} else if ( V_10 -> V_33 && ( V_54 &
V_29 ) )
V_6 -> V_50 ++ ;
F_20 ( & V_6 -> V_60 ) ;
break;
default:
break;
}
F_21 ( & V_43 -> V_65 ) ;
return V_66 ;
}
static void F_22 ( struct V_5 * V_43 )
{
T_4 V_67 = 0 ;
struct V_1 * V_6 ;
struct V_9 * V_10 ;
struct V_68 * V_62 ;
unsigned long V_69 ;
unsigned long V_50 ;
F_23 ( V_70 ) ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_43 -> V_72 . V_73 ; V_71 ++ ) {
V_6 = & V_43 -> V_7 [ V_71 ] ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
if ( ! F_19 ( & V_6 -> V_61 ) ) {
F_17 ( & V_6 -> V_61 , & V_70 ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
F_26 (sdesc, &list, node) {
V_62 = & V_10 -> V_62 ;
if ( V_62 -> V_74 )
V_62 -> V_74 ( V_62 -> V_75 ) ;
V_67 = V_62 -> V_76 ;
F_27 ( V_62 ) ;
}
F_24 ( & V_6 -> V_60 , V_69 ) ;
F_17 ( & V_70 , & V_6 -> free ) ;
V_6 -> V_4 . V_77 = V_67 ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
} else {
if ( F_19 ( & V_6 -> V_46 ) ) {
F_25 ( & V_6 -> V_60 , V_69 ) ;
continue;
}
V_10 = F_11 ( & V_6 -> V_46 ,
struct V_9 , V_45 ) ;
V_50 = V_6 -> V_50 ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
V_62 = & V_10 -> V_62 ;
while ( V_50 != V_6 -> V_51 ) {
if ( V_62 -> V_74 )
V_62 -> V_74 ( V_62 -> V_75 ) ;
V_6 -> V_51 ++ ;
}
}
}
}
static void F_28 ( unsigned long V_53 )
{
struct V_5 * V_43 = ( void * ) V_53 ;
F_22 ( V_43 ) ;
}
static T_4 F_29 ( struct V_68 * V_78 )
{
struct V_1 * V_6 = F_1 ( V_78 -> V_4 ) ;
struct V_9 * V_10 ;
unsigned long V_69 ;
T_4 V_76 ;
V_10 = F_2 ( V_78 , struct V_9 , V_62 ) ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
F_12 ( & V_10 -> V_45 , & V_6 -> V_44 ) ;
V_76 = F_30 ( V_78 ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
return V_76 ;
}
static int F_31 ( struct V_2 * V_4 ,
struct V_79 * V_80 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_69 ;
if ( ( V_80 -> V_81 != V_82 ) ||
( V_80 -> V_83 != V_82 ) )
return - V_84 ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
V_6 -> V_49 = ( V_80 -> V_85 == 4 ? 1 : 0 ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_43 = F_3 ( & V_6 -> V_4 ) ;
int V_11 = V_6 -> V_4 . V_8 ;
unsigned long V_69 ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
switch ( V_43 -> type ) {
case V_58 :
F_5 ( 1 << V_11 , V_43 -> V_13 + V_86 ) ;
F_5 ( ( 1 << V_11 ) | 1 << ( V_11 + 16 ) ,
V_43 -> V_13 +
V_87 ) ;
F_5 ( 1 << V_11 , V_43 -> V_13 + V_88 ) ;
break;
case V_47 :
F_5 ( 0 , V_43 -> V_13 + V_30 ) ;
F_5 ( 0 , V_43 -> V_13 + V_34 ) ;
F_5 ( 0 , V_43 -> V_13 + V_89 ) ;
break;
case V_57 :
F_5 ( F_8 ( V_43 -> V_13 + V_40 ) &
~ ( 1 << V_11 ) , V_43 -> V_13 + V_40 ) ;
F_5 ( F_8 ( V_43 -> V_13 +
V_42 ) &
~ ( ( 1 << V_11 ) | 1 << ( V_11 + 16 ) ) ,
V_43 -> V_13 + V_42 ) ;
F_5 ( 1 << V_11 , V_43 -> V_13 + V_88 ) ;
break;
default:
break;
}
F_17 ( & V_6 -> V_46 , & V_6 -> free ) ;
F_17 ( & V_6 -> V_44 , & V_6 -> free ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_43 = F_3 ( & V_6 -> V_4 ) ;
int V_11 = V_6 -> V_4 . V_8 ;
unsigned long V_69 ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
switch ( V_43 -> type ) {
case V_58 :
F_5 ( ( 1 << V_11 ) | 1 << ( V_11 + 16 ) ,
V_43 -> V_13 +
V_87 ) ;
break;
case V_47 :
F_5 ( 0 , V_43 -> V_13 + V_34 ) ;
break;
case V_57 :
F_5 ( F_8 ( V_43 -> V_13 +
V_42 ) &
~ ( ( 1 << V_11 ) | 1 << ( V_11 + 16 ) ) ,
V_43 -> V_13 + V_42 ) ;
break;
default:
break;
}
F_25 ( & V_6 -> V_60 , V_69 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_43 = F_3 ( & V_6 -> V_4 ) ;
int V_11 = V_6 -> V_4 . V_8 ;
unsigned long V_69 ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
switch ( V_43 -> type ) {
case V_58 :
F_5 ( ( 1 << V_11 ) | 1 << ( V_11 + 16 ) ,
V_43 -> V_13 + V_41 ) ;
break;
case V_47 :
F_5 ( 0x10001 ,
V_43 -> V_13 + V_34 ) ;
break;
case V_57 :
F_5 ( F_8 ( V_43 -> V_13 +
V_42 ) |
( ( 1 << V_11 ) | 1 << ( V_11 + 16 ) ) ,
V_43 -> V_13 + V_42 ) ;
break;
default:
break;
}
F_25 ( & V_6 -> V_60 , V_69 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_4 )
{
struct V_5 * V_43 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_9 * V_10 ;
unsigned long V_69 ;
F_23 ( V_90 ) ;
int V_71 ;
F_36 ( V_43 -> V_72 . V_91 ) ;
for ( V_71 = 0 ; V_71 < V_92 ; V_71 ++ ) {
V_10 = F_37 ( sizeof( * V_10 ) , V_93 ) ;
if ( ! V_10 ) {
F_38 ( V_43 -> V_72 . V_91 , L_1
L_2 , V_71 ) ;
break;
}
F_39 ( & V_10 -> V_62 , V_4 ) ;
V_10 -> V_62 . V_69 = V_94 ;
V_10 -> V_62 . V_95 = F_29 ;
F_40 ( & V_10 -> V_45 , & V_90 ) ;
}
if ( V_71 == 0 )
return - V_96 ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
F_17 ( & V_90 , & V_6 -> free ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
return V_71 ;
}
static void F_41 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_43 = F_3 ( V_4 ) ;
struct V_9 * V_10 , * V_97 ;
unsigned long V_69 ;
F_23 ( V_90 ) ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
F_42 ( ! F_19 ( & V_6 -> V_98 ) ) ;
F_42 ( ! F_19 ( & V_6 -> V_44 ) ) ;
F_42 ( ! F_19 ( & V_6 -> V_46 ) ) ;
F_42 ( ! F_19 ( & V_6 -> V_61 ) ) ;
F_17 ( & V_6 -> free , & V_90 ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
F_43 (sdesc, tmp, &descs, node)
F_44 ( V_10 ) ;
F_45 ( V_43 -> V_72 . V_91 ) ;
}
static void F_46 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_69 ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
if ( F_19 ( & V_6 -> V_46 ) && ! F_19 ( & V_6 -> V_44 ) )
F_10 ( V_6 ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
}
static enum V_99
F_47 ( struct V_2 * V_4 , T_4 V_76 ,
struct V_100 * V_101 )
{
struct V_5 * V_43 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_69 ;
enum V_99 V_102 ;
struct V_9 * V_10 ;
int V_11 = V_6 -> V_4 . V_8 ;
unsigned long V_103 ;
unsigned long V_104 ;
unsigned long V_105 ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
if ( F_19 ( & V_6 -> V_46 ) ) {
V_102 = F_48 ( V_4 , V_76 , V_101 ) ;
F_49 ( V_101 , 0 ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
return V_102 ;
}
V_10 = F_11 ( & V_6 -> V_46 , struct V_9 , V_45 ) ;
if ( V_10 -> V_33 )
V_104 = ( V_10 -> V_20 + 1 ) * ( V_10 -> V_22 + 1 ) *
( V_10 -> V_24 * V_106 ) ;
else
V_104 = V_10 -> V_20 * V_106 ;
V_102 = F_48 ( V_4 , V_76 , V_101 ) ;
if ( V_43 -> type == V_47 )
V_11 = 0 ;
if ( V_43 -> type == V_47 ) {
V_103 = F_8 ( V_43 -> V_13 + V_107 ) ;
} else {
V_103 = F_8 (
V_43 -> V_13 + V_11 * 0x10 + V_32 ) << 2 ;
}
V_105 = V_104 - ( V_103 - V_10 -> V_31 ) ;
F_49 ( V_101 , V_105 ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
return V_102 ;
}
static struct V_68 * F_50 (
struct V_2 * V_4 , struct V_108 * V_109 ,
unsigned long V_69 )
{
struct V_5 * V_43 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_9 * V_10 = NULL ;
unsigned long V_110 ;
int V_102 ;
if ( ( V_109 -> V_15 != V_111 ) && ( V_109 -> V_15 != V_112 ) ) {
V_102 = - V_84 ;
goto V_113;
}
F_24 ( & V_6 -> V_60 , V_110 ) ;
if ( ! F_19 ( & V_6 -> free ) ) {
V_10 = F_11 ( & V_6 -> free , struct V_9 ,
V_45 ) ;
F_51 ( & V_10 -> V_45 ) ;
}
F_25 ( & V_6 -> V_60 , V_110 ) ;
if ( ! V_10 ) {
F_22 ( V_43 ) ;
V_102 = 0 ;
goto V_114;
}
F_24 ( & V_6 -> V_60 , V_110 ) ;
if ( ( V_109 -> V_115 == 1 ) && ( V_109 -> V_116 > 0 ) ) {
V_10 -> V_33 = 0 ;
V_10 -> V_20 = V_109 -> V_117 [ 0 ] . V_118 / V_106 ;
V_10 -> V_24 = ( V_109 -> V_117 [ 0 ] . V_118 + V_109 -> V_117 [ 0 ] . V_119 ) /
V_106 ;
V_10 -> V_22 = V_109 -> V_116 - 1 ;
if ( V_109 -> V_15 == V_111 ) {
V_10 -> V_31 = V_109 -> V_120 ;
V_10 -> V_15 = 1 ;
} else {
V_10 -> V_31 = V_109 -> V_121 ;
V_10 -> V_15 = 0 ;
}
F_40 ( & V_10 -> V_45 , & V_6 -> V_98 ) ;
} else {
F_52 ( L_3 ) ;
V_102 = - V_84 ;
goto V_122;
}
F_25 ( & V_6 -> V_60 , V_110 ) ;
return & V_10 -> V_62 ;
V_122:
F_25 ( & V_6 -> V_60 , V_110 ) ;
V_114:
V_113:
return F_53 ( V_102 ) ;
}
static struct V_68 *
F_54 ( struct V_2 * V_4 , T_5 V_31 ,
T_6 V_123 , T_6 V_124 ,
enum V_125 V_126 , unsigned long V_69 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_9 * V_10 = NULL ;
unsigned long V_110 ;
if ( V_123 != 2 * V_124 )
return F_53 ( - V_84 ) ;
F_24 ( & V_6 -> V_60 , V_110 ) ;
if ( ! F_19 ( & V_6 -> free ) ) {
V_10 = F_11 ( & V_6 -> free , struct V_9 ,
V_45 ) ;
F_51 ( & V_10 -> V_45 ) ;
}
F_25 ( & V_6 -> V_60 , V_110 ) ;
if ( ! V_10 )
return NULL ;
F_24 ( & V_6 -> V_60 , V_110 ) ;
V_10 -> V_31 = V_31 ;
V_10 -> V_33 = 1 ;
V_10 -> V_20 = 0 ;
V_10 -> V_22 = V_123 / V_106 - 1 ;
V_10 -> V_24 = 1 ;
F_40 ( & V_10 -> V_45 , & V_6 -> V_98 ) ;
F_25 ( & V_6 -> V_60 , V_110 ) ;
return & V_10 -> V_62 ;
}
bool F_55 ( struct V_2 * V_4 , void * V_8 )
{
unsigned int V_127 = ( unsigned int ) V_8 ;
if ( V_127 == V_4 -> V_8 +
V_4 -> V_128 -> V_129 * V_130 )
return true ;
return false ;
}
static struct V_2 * F_56 ( struct V_131 * V_132 ,
struct V_133 * V_134 )
{
struct V_5 * V_43 = V_134 -> V_135 ;
unsigned int V_136 = V_132 -> args [ 0 ] ;
if ( V_136 >= V_130 )
return NULL ;
return F_57 ( & V_43 -> V_7 [ V_136 ] . V_4 ) ;
}
static int F_58 ( struct V_137 * V_138 )
{
struct V_139 * V_140 = V_138 -> V_91 . V_141 ;
struct V_128 * V_91 = & V_138 -> V_91 ;
struct V_142 * V_72 ;
struct V_5 * V_43 ;
struct V_1 * V_6 ;
struct V_143 * V_53 ;
struct V_144 V_145 ;
T_7 V_146 , V_147 ;
T_3 V_148 ;
int V_102 , V_71 ;
V_43 = F_59 ( V_91 , sizeof( * V_43 ) , V_93 ) ;
if ( ! V_43 ) {
F_60 ( V_91 , L_4 ) ;
return - V_96 ;
}
V_53 = (struct V_143 * )
( F_61 ( V_138 -> V_91 . V_149 -> V_150 ,
& V_138 -> V_91 ) -> V_53 ) ;
V_43 -> V_48 = V_53 -> V_151 ;
V_43 -> type = V_53 -> type ;
if ( F_62 ( V_140 , L_5 , & V_148 ) ) {
F_60 ( V_91 , L_6 ) ;
return - V_152 ;
}
V_43 -> V_52 = F_63 ( V_140 , 0 ) ;
if ( V_43 -> V_52 == V_153 ) {
F_60 ( V_91 , L_7 ) ;
return - V_84 ;
}
V_43 -> V_154 = F_64 ( V_91 , NULL ) ;
if ( F_65 ( V_43 -> V_154 ) ) {
F_60 ( V_91 , L_8 ) ;
return F_66 ( V_43 -> V_154 ) ;
}
V_102 = F_67 ( V_140 , 0 , & V_145 ) ;
if ( V_102 ) {
F_60 ( V_91 , L_9 ) ;
goto V_155;
}
V_146 = V_145 . V_156 ;
V_147 = F_68 ( & V_145 ) ;
V_43 -> V_13 = F_69 ( V_91 , V_146 , V_147 ) ;
if ( ! V_43 -> V_13 ) {
F_60 ( V_91 , L_10 ) ;
V_102 = - V_96 ;
goto V_155;
}
V_102 = F_70 ( V_43 -> V_52 , & F_13 , 0 , V_157 , V_43 ) ;
if ( V_102 ) {
F_60 ( V_91 , L_11 ) ;
V_102 = - V_84 ;
goto V_155;
}
V_72 = & V_43 -> V_72 ;
V_72 -> V_91 = V_91 ;
V_72 -> V_158 = F_35 ;
V_72 -> V_159 = F_41 ;
V_72 -> V_160 = F_46 ;
V_72 -> V_161 = F_31 ;
V_72 -> V_162 = F_33 ;
V_72 -> V_163 = F_34 ;
V_72 -> V_164 = F_32 ;
V_72 -> V_165 = F_47 ;
V_72 -> V_166 = F_50 ;
V_72 -> V_167 = F_54 ;
V_72 -> V_168 = V_169 ;
V_72 -> V_170 = V_169 ;
V_72 -> V_171 = F_71 ( V_112 ) | F_71 ( V_111 ) ;
F_72 ( & V_72 -> V_7 ) ;
F_73 ( V_172 , V_72 -> V_173 ) ;
F_73 ( V_174 , V_72 -> V_173 ) ;
F_73 ( V_175 , V_72 -> V_173 ) ;
F_73 ( V_176 , V_72 -> V_173 ) ;
for ( V_71 = 0 ; V_71 < V_130 ; V_71 ++ ) {
V_6 = & V_43 -> V_7 [ V_71 ] ;
V_6 -> V_4 . V_128 = V_72 ;
F_74 ( & V_6 -> V_4 ) ;
F_72 ( & V_6 -> free ) ;
F_72 ( & V_6 -> V_98 ) ;
F_72 ( & V_6 -> V_44 ) ;
F_72 ( & V_6 -> V_46 ) ;
F_72 ( & V_6 -> V_61 ) ;
F_75 ( & V_6 -> V_60 ) ;
F_40 ( & V_6 -> V_4 . V_139 , & V_72 -> V_7 ) ;
}
F_76 ( & V_43 -> V_65 , F_28 , ( unsigned long ) V_43 ) ;
F_77 ( V_91 , V_43 ) ;
V_102 = F_78 ( V_72 ) ;
if ( V_102 )
goto V_177;
V_102 = F_79 ( V_140 , F_56 , V_43 ) ;
if ( V_102 ) {
F_60 ( V_91 , L_12 ) ;
goto V_178;
}
F_80 ( & V_138 -> V_91 ) ;
F_81 ( V_91 , L_13 ) ;
return 0 ;
V_178:
F_82 ( V_72 ) ;
V_177:
V_177 ( V_43 -> V_52 , V_43 ) ;
V_155:
F_83 ( V_43 -> V_52 ) ;
return V_102 ;
}
static int F_84 ( struct V_137 * V_138 )
{
struct V_128 * V_91 = & V_138 -> V_91 ;
struct V_5 * V_43 = F_85 ( V_91 ) ;
F_86 ( V_138 -> V_91 . V_141 ) ;
F_82 ( & V_43 -> V_72 ) ;
V_177 ( V_43 -> V_52 , V_43 ) ;
F_83 ( V_43 -> V_52 ) ;
F_87 ( & V_138 -> V_91 ) ;
if ( ! F_88 ( & V_138 -> V_91 ) )
F_89 ( & V_138 -> V_91 ) ;
return 0 ;
}
static int F_89 ( struct V_128 * V_91 )
{
struct V_5 * V_43 = F_85 ( V_91 ) ;
F_90 ( V_43 -> V_154 ) ;
return 0 ;
}
static int F_91 ( struct V_128 * V_91 )
{
struct V_5 * V_43 = F_85 ( V_91 ) ;
int V_102 ;
V_102 = F_92 ( V_43 -> V_154 ) ;
if ( V_102 < 0 ) {
F_60 ( V_91 , L_14 , V_102 ) ;
return V_102 ;
}
return 0 ;
}
static int F_93 ( struct V_128 * V_91 )
{
struct V_5 * V_43 = F_85 ( V_91 ) ;
struct V_179 * V_180 = & V_43 -> V_181 ;
struct V_9 * V_10 ;
struct V_1 * V_6 ;
int V_55 ;
int V_102 ;
int V_182 ;
T_3 V_183 ;
if ( F_88 ( V_91 ) ) {
V_102 = F_91 ( V_91 ) ;
if ( V_102 < 0 )
return V_102 ;
}
if ( V_43 -> type == V_47 ) {
V_182 = 1 ;
V_183 = V_30 ;
} else {
V_182 = V_130 ;
V_183 = V_40 ;
}
for ( V_55 = 0 ; V_55 < V_182 ; V_55 ++ ) {
V_6 = & V_43 -> V_7 [ V_55 ] ;
if ( F_19 ( & V_6 -> V_46 ) )
continue;
V_10 = F_11 ( & V_6 -> V_46 ,
struct V_9 ,
V_45 ) ;
V_180 -> V_184 [ V_55 ] = F_8 ( V_43 -> V_13 +
V_55 * 0x10 + V_19 ) ;
}
V_180 -> V_185 = F_8 ( V_43 -> V_13 + V_183 ) ;
F_89 ( V_91 ) ;
return 0 ;
}
static int F_94 ( struct V_128 * V_91 )
{
struct V_5 * V_43 = F_85 ( V_91 ) ;
struct V_179 * V_180 = & V_43 -> V_181 ;
struct V_9 * V_10 ;
struct V_1 * V_6 ;
int V_55 ;
int V_102 ;
int V_182 ;
T_3 V_183 ;
T_3 V_186 ;
V_102 = F_91 ( V_91 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( V_43 -> type == V_47 ) {
V_182 = 1 ;
V_183 = V_30 ;
V_186 = V_25 ;
} else {
V_182 = V_130 ;
V_183 = V_40 ;
V_186 = V_37 ;
}
F_5 ( V_180 -> V_185 , V_43 -> V_13 + V_183 ) ;
for ( V_55 = 0 ; V_55 < V_182 ; V_55 ++ ) {
V_6 = & V_43 -> V_7 [ V_55 ] ;
if ( F_19 ( & V_6 -> V_46 ) )
continue;
V_10 = F_11 ( & V_6 -> V_46 ,
struct V_9 ,
V_45 ) ;
F_5 ( V_10 -> V_24 ,
V_43 -> V_13 + V_186 + V_55 * 4 ) ;
F_5 ( V_10 -> V_20 ,
V_43 -> V_13 + V_55 * 0x10 + V_21 ) ;
F_5 ( V_10 -> V_22 ,
V_43 -> V_13 + V_55 * 0x10 + V_23 ) ;
F_5 ( V_180 -> V_184 [ V_55 ] ,
V_43 -> V_13 + V_55 * 0x10 + V_19 ) ;
if ( V_43 -> type == V_47 ) {
F_5 ( V_10 -> V_31 ,
V_43 -> V_13 + V_32 ) ;
} else {
F_5 ( V_10 -> V_31 >> 2 ,
V_43 -> V_13 + V_55 * 0x10 + V_32 ) ;
}
}
if ( F_88 ( V_91 ) )
F_89 ( V_91 ) ;
return 0 ;
}
static T_8 int F_95 ( void )
{
return F_96 ( & V_187 ) ;
}
static void T_9 F_97 ( void )
{
F_98 ( & V_187 ) ;
}
