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
F_27 ( V_62 , NULL ) ;
V_67 = V_62 -> V_74 ;
F_28 ( V_62 ) ;
}
F_24 ( & V_6 -> V_60 , V_69 ) ;
F_17 ( & V_70 , & V_6 -> free ) ;
V_6 -> V_4 . V_75 = V_67 ;
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
F_27 ( V_62 , NULL ) ;
V_6 -> V_51 ++ ;
}
}
}
}
static void F_29 ( unsigned long V_53 )
{
struct V_5 * V_43 = ( void * ) V_53 ;
F_22 ( V_43 ) ;
}
static T_4 F_30 ( struct V_68 * V_76 )
{
struct V_1 * V_6 = F_1 ( V_76 -> V_4 ) ;
struct V_9 * V_10 ;
unsigned long V_69 ;
T_4 V_74 ;
V_10 = F_2 ( V_76 , struct V_9 , V_62 ) ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
F_12 ( & V_10 -> V_45 , & V_6 -> V_44 ) ;
V_74 = F_31 ( V_76 ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
return V_74 ;
}
static int F_32 ( struct V_2 * V_4 ,
struct V_77 * V_78 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_69 ;
if ( ( V_78 -> V_79 != V_80 ) ||
( V_78 -> V_81 != V_80 ) )
return - V_82 ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
V_6 -> V_49 = ( V_78 -> V_83 == 4 ? 1 : 0 ) ;
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
F_5 ( 1 << V_11 , V_43 -> V_13 + V_84 ) ;
F_5 ( 1 << V_11 , V_43 -> V_13 + V_59 ) ;
F_5 ( ( 1 << V_11 ) | 1 << ( V_11 + 16 ) ,
V_43 -> V_13 +
V_85 ) ;
F_5 ( 1 << V_11 , V_43 -> V_13 + V_86 ) ;
break;
case V_47 :
F_5 ( 0 , V_43 -> V_13 + V_30 ) ;
F_5 ( V_64 ,
V_43 -> V_13 + V_63 ) ;
F_5 ( 0 , V_43 -> V_13 + V_34 ) ;
F_5 ( 0 , V_43 -> V_13 + V_87 ) ;
break;
case V_57 :
F_5 ( F_8 ( V_43 -> V_13 + V_40 ) &
~ ( 1 << V_11 ) , V_43 -> V_13 + V_40 ) ;
F_5 ( F_8 ( V_43 -> V_13 +
V_42 ) &
~ ( ( 1 << V_11 ) | 1 << ( V_11 + 16 ) ) ,
V_43 -> V_13 + V_42 ) ;
F_5 ( 1 << V_11 , V_43 -> V_13 + V_86 ) ;
break;
default:
break;
}
F_17 ( & V_6 -> V_46 , & V_6 -> free ) ;
F_17 ( & V_6 -> V_44 , & V_6 -> free ) ;
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
V_43 -> V_13 +
V_85 ) ;
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
static int F_35 ( struct V_2 * V_4 )
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
static int F_36 ( struct V_2 * V_4 )
{
struct V_5 * V_43 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_9 * V_10 ;
unsigned long V_69 ;
F_23 ( V_88 ) ;
int V_71 ;
F_37 ( V_43 -> V_72 . V_89 ) ;
for ( V_71 = 0 ; V_71 < V_90 ; V_71 ++ ) {
V_10 = F_38 ( sizeof( * V_10 ) , V_91 ) ;
if ( ! V_10 ) {
F_39 ( V_43 -> V_72 . V_89 , L_1
L_2 , V_71 ) ;
break;
}
F_40 ( & V_10 -> V_62 , V_4 ) ;
V_10 -> V_62 . V_69 = V_92 ;
V_10 -> V_62 . V_93 = F_30 ;
F_41 ( & V_10 -> V_45 , & V_88 ) ;
}
if ( V_71 == 0 )
return - V_94 ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
F_17 ( & V_88 , & V_6 -> free ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
return V_71 ;
}
static void F_42 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_43 = F_3 ( V_4 ) ;
struct V_9 * V_10 , * V_95 ;
unsigned long V_69 ;
F_23 ( V_88 ) ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
F_43 ( ! F_19 ( & V_6 -> V_96 ) ) ;
F_43 ( ! F_19 ( & V_6 -> V_44 ) ) ;
F_43 ( ! F_19 ( & V_6 -> V_46 ) ) ;
F_43 ( ! F_19 ( & V_6 -> V_61 ) ) ;
F_17 ( & V_6 -> free , & V_88 ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
F_44 (sdesc, tmp, &descs, node)
F_45 ( V_10 ) ;
F_46 ( V_43 -> V_72 . V_89 ) ;
}
static void F_47 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_69 ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
if ( F_19 ( & V_6 -> V_46 ) && ! F_19 ( & V_6 -> V_44 ) )
F_10 ( V_6 ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
}
static enum V_97
F_48 ( struct V_2 * V_4 , T_4 V_74 ,
struct V_98 * V_99 )
{
struct V_5 * V_43 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_69 ;
enum V_97 V_100 ;
struct V_9 * V_10 ;
int V_11 = V_6 -> V_4 . V_8 ;
unsigned long V_101 ;
unsigned long V_102 ;
unsigned long V_103 ;
F_24 ( & V_6 -> V_60 , V_69 ) ;
if ( F_19 ( & V_6 -> V_46 ) ) {
V_100 = F_49 ( V_4 , V_74 , V_99 ) ;
F_50 ( V_99 , 0 ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
return V_100 ;
}
V_10 = F_11 ( & V_6 -> V_46 , struct V_9 , V_45 ) ;
if ( V_10 -> V_33 )
V_102 = ( V_10 -> V_20 + 1 ) * ( V_10 -> V_22 + 1 ) *
( V_10 -> V_24 * V_104 ) ;
else
V_102 = V_10 -> V_20 * V_104 ;
V_100 = F_49 ( V_4 , V_74 , V_99 ) ;
if ( V_43 -> type == V_47 )
V_11 = 0 ;
if ( V_43 -> type == V_47 ) {
V_101 = F_8 ( V_43 -> V_13 + V_105 ) ;
} else {
V_101 = F_8 (
V_43 -> V_13 + V_11 * 0x10 + V_32 ) << 2 ;
}
V_103 = V_102 - ( V_101 - V_10 -> V_31 ) ;
F_50 ( V_99 , V_103 ) ;
F_25 ( & V_6 -> V_60 , V_69 ) ;
return V_100 ;
}
static struct V_68 * F_51 (
struct V_2 * V_4 , struct V_106 * V_107 ,
unsigned long V_69 )
{
struct V_5 * V_43 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_9 * V_10 = NULL ;
unsigned long V_108 ;
int V_100 ;
if ( ( V_107 -> V_15 != V_109 ) && ( V_107 -> V_15 != V_110 ) ) {
V_100 = - V_82 ;
goto V_111;
}
F_24 ( & V_6 -> V_60 , V_108 ) ;
if ( ! F_19 ( & V_6 -> free ) ) {
V_10 = F_11 ( & V_6 -> free , struct V_9 ,
V_45 ) ;
F_52 ( & V_10 -> V_45 ) ;
}
F_25 ( & V_6 -> V_60 , V_108 ) ;
if ( ! V_10 ) {
F_22 ( V_43 ) ;
V_100 = 0 ;
goto V_112;
}
F_24 ( & V_6 -> V_60 , V_108 ) ;
if ( ( V_107 -> V_113 == 1 ) && ( V_107 -> V_114 > 0 ) ) {
V_10 -> V_33 = 0 ;
V_10 -> V_20 = V_107 -> V_115 [ 0 ] . V_116 / V_104 ;
V_10 -> V_24 = ( V_107 -> V_115 [ 0 ] . V_116 + V_107 -> V_115 [ 0 ] . V_117 ) /
V_104 ;
V_10 -> V_22 = V_107 -> V_114 - 1 ;
if ( V_107 -> V_15 == V_109 ) {
V_10 -> V_31 = V_107 -> V_118 ;
V_10 -> V_15 = 1 ;
} else {
V_10 -> V_31 = V_107 -> V_119 ;
V_10 -> V_15 = 0 ;
}
F_41 ( & V_10 -> V_45 , & V_6 -> V_96 ) ;
} else {
F_53 ( L_3 ) ;
V_100 = - V_82 ;
goto V_120;
}
F_25 ( & V_6 -> V_60 , V_108 ) ;
return & V_10 -> V_62 ;
V_120:
F_25 ( & V_6 -> V_60 , V_108 ) ;
V_112:
V_111:
return F_54 ( V_100 ) ;
}
static struct V_68 *
F_55 ( struct V_2 * V_4 , T_5 V_31 ,
T_6 V_121 , T_6 V_122 ,
enum V_123 V_124 , unsigned long V_69 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_9 * V_10 = NULL ;
unsigned long V_108 ;
if ( V_121 != 2 * V_122 )
return F_54 ( - V_82 ) ;
F_24 ( & V_6 -> V_60 , V_108 ) ;
if ( ! F_19 ( & V_6 -> free ) ) {
V_10 = F_11 ( & V_6 -> free , struct V_9 ,
V_45 ) ;
F_52 ( & V_10 -> V_45 ) ;
}
F_25 ( & V_6 -> V_60 , V_108 ) ;
if ( ! V_10 )
return NULL ;
F_24 ( & V_6 -> V_60 , V_108 ) ;
V_10 -> V_31 = V_31 ;
V_10 -> V_33 = 1 ;
V_10 -> V_20 = 0 ;
V_10 -> V_22 = V_121 / V_104 - 1 ;
V_10 -> V_24 = 1 ;
F_41 ( & V_10 -> V_45 , & V_6 -> V_96 ) ;
F_25 ( & V_6 -> V_60 , V_108 ) ;
return & V_10 -> V_62 ;
}
bool F_56 ( struct V_2 * V_4 , void * V_8 )
{
unsigned int V_125 = ( unsigned int ) V_8 ;
if ( V_125 == V_4 -> V_8 +
V_4 -> V_126 -> V_127 * V_128 )
return true ;
return false ;
}
static struct V_2 * F_57 ( struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_5 * V_43 = V_132 -> V_133 ;
unsigned int V_134 = V_130 -> args [ 0 ] ;
if ( V_134 >= V_128 )
return NULL ;
return F_58 ( & V_43 -> V_7 [ V_134 ] . V_4 ) ;
}
static int F_59 ( struct V_135 * V_136 )
{
struct V_137 * V_138 = V_136 -> V_89 . V_139 ;
struct V_126 * V_89 = & V_136 -> V_89 ;
struct V_140 * V_72 ;
struct V_5 * V_43 ;
struct V_1 * V_6 ;
struct V_141 * V_53 ;
struct V_142 V_143 ;
T_7 V_144 , V_145 ;
T_3 V_146 ;
int V_100 , V_71 ;
V_43 = F_60 ( V_89 , sizeof( * V_43 ) , V_91 ) ;
if ( ! V_43 )
return - V_94 ;
V_53 = (struct V_141 * )
( F_61 ( V_136 -> V_89 . V_147 -> V_148 ,
& V_136 -> V_89 ) -> V_53 ) ;
V_43 -> V_48 = V_53 -> V_149 ;
V_43 -> type = V_53 -> type ;
if ( F_62 ( V_138 , L_4 , & V_146 ) ) {
F_63 ( V_89 , L_5 ) ;
return - V_150 ;
}
V_43 -> V_52 = F_64 ( V_138 , 0 ) ;
if ( ! V_43 -> V_52 ) {
F_63 ( V_89 , L_6 ) ;
return - V_82 ;
}
V_43 -> V_151 = F_65 ( V_89 , NULL ) ;
if ( F_66 ( V_43 -> V_151 ) ) {
F_63 ( V_89 , L_7 ) ;
return F_67 ( V_43 -> V_151 ) ;
}
V_100 = F_68 ( V_138 , 0 , & V_143 ) ;
if ( V_100 ) {
F_63 ( V_89 , L_8 ) ;
goto V_152;
}
V_144 = V_143 . V_153 ;
V_145 = F_69 ( & V_143 ) ;
V_43 -> V_13 = F_70 ( V_89 , V_144 , V_145 ) ;
if ( ! V_43 -> V_13 ) {
F_63 ( V_89 , L_9 ) ;
V_100 = - V_94 ;
goto V_152;
}
V_100 = F_71 ( V_43 -> V_52 , & F_13 , 0 , V_154 , V_43 ) ;
if ( V_100 ) {
F_63 ( V_89 , L_10 ) ;
V_100 = - V_82 ;
goto V_152;
}
V_72 = & V_43 -> V_72 ;
V_72 -> V_89 = V_89 ;
V_72 -> V_155 = F_36 ;
V_72 -> V_156 = F_42 ;
V_72 -> V_157 = F_47 ;
V_72 -> V_158 = F_32 ;
V_72 -> V_159 = F_34 ;
V_72 -> V_160 = F_35 ;
V_72 -> V_161 = F_33 ;
V_72 -> V_162 = F_48 ;
V_72 -> V_163 = F_51 ;
V_72 -> V_164 = F_55 ;
V_72 -> V_165 = V_166 ;
V_72 -> V_167 = V_166 ;
V_72 -> V_168 = F_72 ( V_110 ) | F_72 ( V_109 ) ;
F_73 ( & V_72 -> V_7 ) ;
F_74 ( V_169 , V_72 -> V_170 ) ;
F_74 ( V_171 , V_72 -> V_170 ) ;
F_74 ( V_172 , V_72 -> V_170 ) ;
F_74 ( V_173 , V_72 -> V_170 ) ;
for ( V_71 = 0 ; V_71 < V_128 ; V_71 ++ ) {
V_6 = & V_43 -> V_7 [ V_71 ] ;
V_6 -> V_4 . V_126 = V_72 ;
F_75 ( & V_6 -> V_4 ) ;
F_73 ( & V_6 -> free ) ;
F_73 ( & V_6 -> V_96 ) ;
F_73 ( & V_6 -> V_44 ) ;
F_73 ( & V_6 -> V_46 ) ;
F_73 ( & V_6 -> V_61 ) ;
F_76 ( & V_6 -> V_60 ) ;
F_41 ( & V_6 -> V_4 . V_137 , & V_72 -> V_7 ) ;
}
F_77 ( & V_43 -> V_65 , F_29 , ( unsigned long ) V_43 ) ;
F_78 ( V_89 , V_43 ) ;
V_100 = F_79 ( V_72 ) ;
if ( V_100 )
goto V_174;
V_100 = F_80 ( V_138 , F_57 , V_43 ) ;
if ( V_100 ) {
F_63 ( V_89 , L_11 ) ;
goto V_175;
}
F_81 ( & V_136 -> V_89 ) ;
F_82 ( V_89 , L_12 ) ;
return 0 ;
V_175:
F_83 ( V_72 ) ;
V_174:
V_174 ( V_43 -> V_52 , V_43 ) ;
V_152:
F_84 ( V_43 -> V_52 ) ;
return V_100 ;
}
static int F_85 ( struct V_135 * V_136 )
{
struct V_126 * V_89 = & V_136 -> V_89 ;
struct V_5 * V_43 = F_86 ( V_89 ) ;
F_87 ( V_136 -> V_89 . V_139 ) ;
F_83 ( & V_43 -> V_72 ) ;
V_174 ( V_43 -> V_52 , V_43 ) ;
F_88 ( & V_43 -> V_65 ) ;
F_84 ( V_43 -> V_52 ) ;
F_89 ( & V_136 -> V_89 ) ;
if ( ! F_90 ( & V_136 -> V_89 ) )
F_91 ( & V_136 -> V_89 ) ;
return 0 ;
}
static int T_8 F_91 ( struct V_126 * V_89 )
{
struct V_5 * V_43 = F_86 ( V_89 ) ;
F_92 ( V_43 -> V_151 ) ;
return 0 ;
}
static int T_8 F_93 ( struct V_126 * V_89 )
{
struct V_5 * V_43 = F_86 ( V_89 ) ;
int V_100 ;
V_100 = F_94 ( V_43 -> V_151 ) ;
if ( V_100 < 0 ) {
F_63 ( V_89 , L_13 , V_100 ) ;
return V_100 ;
}
return 0 ;
}
static int T_8 F_95 ( struct V_126 * V_89 )
{
struct V_5 * V_43 = F_86 ( V_89 ) ;
struct V_176 * V_177 = & V_43 -> V_178 ;
struct V_9 * V_10 ;
struct V_1 * V_6 ;
int V_55 ;
int V_100 ;
int V_179 ;
T_3 V_180 ;
if ( F_90 ( V_89 ) ) {
V_100 = F_93 ( V_89 ) ;
if ( V_100 < 0 )
return V_100 ;
}
if ( V_43 -> type == V_47 ) {
V_179 = 1 ;
V_180 = V_30 ;
} else {
V_179 = V_128 ;
V_180 = V_40 ;
}
for ( V_55 = 0 ; V_55 < V_179 ; V_55 ++ ) {
V_6 = & V_43 -> V_7 [ V_55 ] ;
if ( F_19 ( & V_6 -> V_46 ) )
continue;
V_10 = F_11 ( & V_6 -> V_46 ,
struct V_9 ,
V_45 ) ;
V_177 -> V_181 [ V_55 ] = F_8 ( V_43 -> V_13 +
V_55 * 0x10 + V_19 ) ;
}
V_177 -> V_182 = F_8 ( V_43 -> V_13 + V_180 ) ;
F_91 ( V_89 ) ;
return 0 ;
}
static int T_8 F_96 ( struct V_126 * V_89 )
{
struct V_5 * V_43 = F_86 ( V_89 ) ;
struct V_176 * V_177 = & V_43 -> V_178 ;
struct V_9 * V_10 ;
struct V_1 * V_6 ;
int V_55 ;
int V_100 ;
int V_179 ;
T_3 V_180 ;
T_3 V_183 ;
V_100 = F_93 ( V_89 ) ;
if ( V_100 < 0 )
return V_100 ;
if ( V_43 -> type == V_47 ) {
V_179 = 1 ;
V_180 = V_30 ;
V_183 = V_25 ;
} else {
V_179 = V_128 ;
V_180 = V_40 ;
V_183 = V_37 ;
}
F_5 ( V_177 -> V_182 , V_43 -> V_13 + V_180 ) ;
for ( V_55 = 0 ; V_55 < V_179 ; V_55 ++ ) {
V_6 = & V_43 -> V_7 [ V_55 ] ;
if ( F_19 ( & V_6 -> V_46 ) )
continue;
V_10 = F_11 ( & V_6 -> V_46 ,
struct V_9 ,
V_45 ) ;
F_5 ( V_10 -> V_24 ,
V_43 -> V_13 + V_183 + V_55 * 4 ) ;
F_5 ( V_10 -> V_20 ,
V_43 -> V_13 + V_55 * 0x10 + V_21 ) ;
F_5 ( V_10 -> V_22 ,
V_43 -> V_13 + V_55 * 0x10 + V_23 ) ;
F_5 ( V_177 -> V_181 [ V_55 ] ,
V_43 -> V_13 + V_55 * 0x10 + V_19 ) ;
if ( V_43 -> type == V_47 ) {
F_5 ( V_10 -> V_31 ,
V_43 -> V_13 + V_32 ) ;
} else {
F_5 ( V_10 -> V_31 >> 2 ,
V_43 -> V_13 + V_55 * 0x10 + V_32 ) ;
}
}
if ( F_90 ( V_89 ) )
F_91 ( V_89 ) ;
return 0 ;
}
static T_9 int F_97 ( void )
{
return F_98 ( & V_184 ) ;
}
static void T_10 F_99 ( void )
{
F_100 ( & V_184 ) ;
}
