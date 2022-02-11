static unsigned long F_1 ( const struct V_1 * V_2 )
{
return ( ( unsigned long ) V_2 -> V_3 << 16 ) | V_2 -> V_4 ;
}
static T_1 F_2 ( unsigned long V_5 )
{
return V_5 & 0xff ;
}
static T_2 F_3 ( unsigned long V_5 )
{
return V_5 >> 16 ;
}
static T_3 F_4 ( int V_6 )
{
T_2 V_5 ;
V_5 = V_7 -> V_8 ( 0 ) ;
if ( V_6 == V_9 )
V_5 >>= 32 ;
return V_5 & 0xffffffff ;
}
static void F_5 ( int V_6 , T_2 V_5 )
{
T_2 V_10 , V_11 , V_12 ;
V_10 = 0 ;
if ( V_6 == V_9 )
V_10 = 32 ;
V_11 = ( ( T_2 ) 0xffffffff ) << V_10 ;
V_5 <<= V_10 ;
V_12 = V_7 -> V_8 ( 0 ) ;
V_12 &= ~ V_11 ;
V_12 |= V_5 ;
V_7 -> V_13 ( 0 , V_12 ) ;
}
static const struct V_1 * F_6 ( int V_14 )
{
return & V_15 [ V_14 ] ;
}
static const struct V_1 * F_7 ( int V_14 )
{
return & V_16 [ V_14 ] ;
}
static const struct V_1 * F_8 ( int V_14 )
{
return & V_17 [ V_14 ] ;
}
static const struct V_1 * F_9 ( int V_14 )
{
return & V_18 [ V_14 ] ;
}
static T_3 F_10 ( int V_6 )
{
T_2 V_5 = V_7 -> V_8 ( V_6 ) ;
return V_5 & 0xffffffff ;
}
static void F_11 ( int V_6 , T_2 V_5 )
{
T_2 V_19 ;
V_19 = V_7 -> V_20 ( V_6 ) ;
V_19 &= ~ ( V_21 | V_22 ) ;
V_7 -> V_13 ( V_6 , V_5 & 0xffffffff ) ;
V_7 -> V_23 ( V_6 , V_19 ) ;
}
static T_2 F_12 ( T_2 V_14 , int V_6 )
{
if ( V_6 == V_9 )
V_14 <<= V_24 -> V_25 ;
else
V_14 <<= V_24 -> V_26 ;
return V_14 ;
}
static T_2 F_13 ( int V_6 )
{
return F_12 ( V_24 -> V_27 , V_6 ) ;
}
static T_2 F_14 ( int V_6 )
{
return F_12 ( V_6 == V_9 ?
V_24 -> V_28 :
V_24 -> V_29 , V_6 ) ;
}
static inline void F_15 ( struct V_30 * V_31 , struct V_32 * V_33 , int V_6 )
{
T_2 V_34 , V_5 , V_11 = F_13 ( V_6 ) ;
int V_35 = 0 ;
if ( V_24 -> V_36 > 1 )
V_35 = V_6 ;
V_34 = F_3 ( V_31 -> V_37 [ V_6 ] ) ;
V_5 = V_31 -> V_19 [ V_35 ] ;
V_5 &= ~ V_11 ;
V_5 |= F_12 ( V_34 , V_6 ) ;
V_31 -> V_19 [ V_35 ] = V_5 ;
V_7 -> V_23 ( V_35 , V_31 -> V_19 [ V_35 ] ) ;
}
static inline void F_16 ( struct V_30 * V_31 , struct V_32 * V_33 , int V_6 )
{
T_2 V_11 = F_13 ( V_6 ) ;
T_2 V_38 = F_14 ( V_6 ) ;
int V_35 = 0 ;
T_2 V_5 ;
if ( V_24 -> V_36 > 1 )
V_35 = V_6 ;
V_5 = V_31 -> V_19 [ V_35 ] ;
V_5 &= ~ V_11 ;
V_5 |= V_38 ;
V_31 -> V_19 [ V_35 ] = V_5 ;
V_7 -> V_23 ( V_35 , V_31 -> V_19 [ V_35 ] ) ;
}
static T_2 F_17 ( struct V_39 * V_40 ,
struct V_32 * V_33 , int V_6 )
{
int V_10 = 64 - 32 ;
T_2 V_41 , V_42 ;
T_4 V_43 ;
V_44:
V_41 = F_18 ( & V_33 -> V_45 ) ;
V_42 = V_24 -> V_46 ( V_6 ) ;
if ( F_19 ( & V_33 -> V_45 , V_41 ,
V_42 ) != V_41 )
goto V_44;
V_43 = ( V_42 << V_10 ) - ( V_41 << V_10 ) ;
V_43 >>= V_10 ;
F_20 ( V_43 , & V_40 -> V_47 ) ;
F_21 ( V_43 , & V_33 -> V_48 ) ;
return V_42 ;
}
static int F_22 ( struct V_39 * V_40 ,
struct V_32 * V_33 , int V_6 )
{
T_4 V_49 = F_18 ( & V_33 -> V_48 ) ;
T_4 V_50 = V_33 -> V_51 ;
int V_52 = 0 ;
if ( F_23 ( V_49 <= - V_50 ) ) {
V_49 = V_50 ;
F_24 ( & V_33 -> V_48 , V_49 ) ;
V_33 -> V_53 = V_50 ;
V_52 = 1 ;
}
if ( F_23 ( V_49 <= 0 ) ) {
V_49 += V_50 ;
F_24 ( & V_33 -> V_48 , V_49 ) ;
V_33 -> V_53 = V_50 ;
V_52 = 1 ;
}
if ( V_49 > V_54 )
V_49 = V_54 ;
F_24 ( & V_33 -> V_45 , ( T_2 ) - V_49 ) ;
V_24 -> V_55 ( V_6 , ( T_2 ) ( - V_49 ) & 0xffffffff ) ;
F_25 ( V_40 ) ;
return V_52 ;
}
static void F_26 ( struct V_30 * V_31 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_31 -> V_57 ; V_56 ++ ) {
struct V_39 * V_58 = V_31 -> V_40 [ V_56 ] ;
if ( V_31 -> V_59 [ V_56 ] != V_60 &&
V_31 -> V_59 [ V_56 ] != V_58 -> V_61 . V_6 ) {
F_17 ( V_58 , & V_58 -> V_61 ,
V_31 -> V_59 [ V_56 ] ) ;
V_31 -> V_59 [ V_56 ] = V_60 ;
}
}
}
static void F_27 ( struct V_30 * V_31 )
{
int V_56 ;
if ( ! V_31 -> V_62 )
goto V_63;
for ( V_56 = 0 ; V_56 < V_31 -> V_57 ; V_56 ++ ) {
struct V_39 * V_58 = V_31 -> V_40 [ V_56 ] ;
struct V_32 * V_33 = & V_58 -> V_61 ;
int V_6 = V_33 -> V_6 ;
T_2 V_34 ;
if ( V_31 -> V_59 [ V_56 ] != V_60 )
continue;
F_22 ( V_58 , V_33 , V_6 ) ;
V_31 -> V_59 [ V_56 ] = V_6 ;
V_34 = F_3 ( V_31 -> V_37 [ V_56 ] ) ;
V_31 -> V_19 [ 0 ] &= ~ F_13 ( V_6 ) ;
if ( V_33 -> V_64 & V_65 )
V_31 -> V_19 [ 0 ] |= F_14 ( V_6 ) ;
else
V_31 -> V_19 [ 0 ] |= F_12 ( V_34 , V_6 ) ;
}
V_63:
V_31 -> V_19 [ 0 ] |= V_31 -> V_40 [ 0 ] -> V_61 . V_66 ;
}
static void F_28 ( struct V_30 * V_31 )
{
int V_56 ;
if ( ! V_31 -> V_62 )
goto V_63;
for ( V_56 = 0 ; V_56 < V_31 -> V_57 ; V_56 ++ ) {
struct V_39 * V_58 = V_31 -> V_40 [ V_56 ] ;
struct V_32 * V_33 = & V_58 -> V_61 ;
int V_6 = V_33 -> V_6 ;
if ( V_31 -> V_59 [ V_56 ] != V_60 )
continue;
V_31 -> V_59 [ V_56 ] = V_6 ;
F_29 ( V_58 , V_67 ) ;
}
V_63:
for ( V_56 = 0 ; V_56 < V_31 -> V_57 ; V_56 ++ ) {
struct V_39 * V_58 = V_31 -> V_40 [ V_56 ] ;
int V_6 = V_58 -> V_61 . V_6 ;
V_31 -> V_19 [ V_6 ] |= V_58 -> V_61 . V_66 ;
}
}
static void F_30 ( struct V_30 * V_31 )
{
if ( V_31 -> V_62 )
F_26 ( V_31 ) ;
if ( V_24 -> V_36 == 1 ) {
F_27 ( V_31 ) ;
} else {
F_28 ( V_31 ) ;
}
}
static void F_31 ( struct V_68 * V_68 )
{
struct V_30 * V_31 = F_32 ( & V_30 ) ;
int V_56 ;
if ( V_31 -> V_69 )
return;
V_31 -> V_69 = 1 ;
F_33 () ;
if ( V_31 -> V_57 )
F_30 ( V_31 ) ;
for ( V_56 = 0 ; V_56 < V_24 -> V_36 ; V_56 ++ )
V_7 -> V_23 ( V_56 , V_31 -> V_19 [ V_56 ] ) ;
}
static void F_34 ( struct V_68 * V_68 )
{
struct V_30 * V_31 = F_32 ( & V_30 ) ;
int V_56 ;
if ( ! V_31 -> V_69 )
return;
V_31 -> V_69 = 0 ;
V_31 -> V_62 = 0 ;
for ( V_56 = 0 ; V_56 < V_24 -> V_36 ; V_56 ++ ) {
T_2 V_5 = V_31 -> V_19 [ V_56 ] ;
V_5 &= ~ ( V_24 -> V_70 | V_24 -> V_71 |
V_24 -> V_72 | V_24 -> V_73 ) ;
V_31 -> V_19 [ V_56 ] = V_5 ;
V_7 -> V_23 ( V_56 , V_31 -> V_19 [ V_56 ] ) ;
}
}
static int F_35 ( struct V_30 * V_31 ,
struct V_39 * V_40 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_31 -> V_57 ; V_56 ++ ) {
if ( V_31 -> V_40 [ V_56 ] == V_40 )
break;
}
F_36 ( V_56 == V_31 -> V_57 ) ;
return V_31 -> V_59 [ V_56 ] ;
}
static void F_29 ( struct V_39 * V_40 , int V_74 )
{
struct V_30 * V_31 = F_32 ( & V_30 ) ;
int V_6 = F_35 ( V_31 , V_40 ) ;
if ( V_74 & V_67 ) {
F_37 ( ! ( V_40 -> V_61 . V_64 & V_75 ) ) ;
F_22 ( V_40 , & V_40 -> V_61 , V_6 ) ;
}
V_40 -> V_61 . V_64 = 0 ;
F_15 ( V_31 , & V_40 -> V_61 , V_6 ) ;
}
static void F_38 ( struct V_39 * V_40 , int V_74 )
{
struct V_30 * V_31 = F_32 ( & V_30 ) ;
int V_6 = F_35 ( V_31 , V_40 ) ;
if ( ! ( V_40 -> V_61 . V_64 & V_65 ) ) {
F_16 ( V_31 , & V_40 -> V_61 , V_6 ) ;
V_40 -> V_61 . V_64 |= V_65 ;
}
if ( ! ( V_40 -> V_61 . V_64 & V_75 ) && ( V_74 & V_76 ) ) {
F_17 ( V_40 , & V_40 -> V_61 , V_6 ) ;
V_40 -> V_61 . V_64 |= V_75 ;
}
}
static void F_39 ( struct V_39 * V_40 , int V_77 )
{
struct V_30 * V_31 = F_32 ( & V_30 ) ;
unsigned long V_74 ;
int V_56 ;
F_40 ( V_74 ) ;
for ( V_56 = 0 ; V_56 < V_31 -> V_57 ; V_56 ++ ) {
if ( V_40 == V_31 -> V_40 [ V_56 ] ) {
F_38 ( V_40 , V_76 ) ;
while ( ++ V_56 < V_31 -> V_57 ) {
V_31 -> V_40 [ V_56 - 1 ] = V_31 -> V_40 [ V_56 ] ;
V_31 -> V_37 [ V_56 - 1 ] = V_31 -> V_37 [ V_56 ] ;
V_31 -> V_59 [ V_56 - 1 ] =
V_31 -> V_59 [ V_56 ] ;
}
F_25 ( V_40 ) ;
V_31 -> V_57 -- ;
break;
}
}
F_41 ( V_74 ) ;
}
static void F_42 ( struct V_39 * V_40 )
{
struct V_30 * V_31 = F_32 ( & V_30 ) ;
int V_6 = F_35 ( V_31 , V_40 ) ;
struct V_32 * V_33 = & V_40 -> V_61 ;
F_17 ( V_40 , V_33 , V_6 ) ;
}
static void F_43 ( void * V_78 )
{
struct V_30 * V_31 = F_32 ( & V_30 ) ;
int V_56 ;
F_44 ( NULL ) ;
for ( V_56 = 0 ; V_56 < V_24 -> V_36 ; V_56 ++ )
V_31 -> V_19 [ V_56 ] = V_7 -> V_20 ( V_56 ) ;
}
static void F_45 ( void )
{
if ( F_46 ( & V_79 ) )
return;
F_47 ( & V_80 ) ;
if ( F_48 ( & V_79 ) == 0 ) {
if ( F_48 ( & V_81 ) > 0 ) {
F_49 ( F_43 , NULL , 1 ) ;
F_36 ( F_48 ( & V_81 ) != 0 ) ;
}
F_50 ( & V_79 ) ;
}
F_51 ( & V_80 ) ;
}
static void F_52 ( void )
{
if ( F_53 ( & V_79 , & V_80 ) ) {
if ( F_48 ( & V_81 ) == 0 )
F_49 ( V_82 , NULL , 1 ) ;
F_51 ( & V_80 ) ;
}
}
static const struct V_1 * F_54 ( T_2 V_83 )
{
unsigned int V_84 , V_85 , V_86 ;
const struct V_1 * V_2 ;
if ( ! V_24 -> V_87 )
return F_55 ( - V_88 ) ;
V_84 = ( V_83 >> 0 ) & 0xff ;
if ( V_84 >= V_89 )
return F_55 ( - V_90 ) ;
V_85 = ( V_83 >> 8 ) & 0xff ;
if ( V_85 >= V_91 )
return F_55 ( - V_90 ) ;
V_86 = ( V_83 >> 16 ) & 0xff ;
if ( V_86 >= V_92 )
return F_55 ( - V_90 ) ;
V_2 = & ( ( * V_24 -> V_87 ) [ V_84 ] [ V_85 ] [ V_86 ] ) ;
if ( V_2 -> V_3 == V_93 )
return F_55 ( - V_88 ) ;
if ( V_2 -> V_3 == V_94 )
return F_55 ( - V_90 ) ;
return V_2 ;
}
static void F_56 ( struct V_39 * V_40 )
{
F_52 () ;
}
static int F_57 ( struct V_39 * * V_95 ,
unsigned long * V_37 , int V_96 )
{
T_1 V_97 = 0 , V_98 = 0 ;
int V_99 = 0 ;
if ( ! V_96 )
return 0 ;
if ( V_96 > V_24 -> V_100 )
return - 1 ;
if ( ! ( V_24 -> V_74 & V_101 ) ) {
int V_56 ;
for ( V_56 = 0 ; V_56 < V_96 ; V_56 ++ )
V_95 [ V_56 ] -> V_61 . V_6 = V_56 ;
return 0 ;
}
V_97 = F_2 ( V_37 [ 0 ] ) ;
if ( V_96 == 1 ) {
if ( V_97 & V_102 )
V_99 = 1 ;
goto V_103;
}
F_36 ( V_96 != 2 ) ;
V_98 = F_2 ( V_37 [ 1 ] ) ;
if ( V_97 == ( V_104 | V_102 ) &&
V_98 == ( V_104 | V_102 ) )
goto V_103;
if ( ( V_97 == V_104 || V_97 == V_102 ) &&
V_98 == ( V_104 | V_102 ) ) {
if ( V_97 & V_102 )
V_99 = 1 ;
goto V_103;
}
if ( ( V_98 == V_104 || V_98 == V_102 ) &&
V_97 == ( V_104 | V_102 ) ) {
if ( V_98 & V_104 )
V_99 = 1 ;
goto V_103;
}
if ( ( V_97 == V_104 && V_98 == V_102 ) ||
( V_97 == V_102 && V_98 == V_104 ) ) {
if ( V_97 & V_102 )
V_99 = 1 ;
goto V_103;
}
return - 1 ;
V_103:
V_95 [ 0 ] -> V_61 . V_6 = V_99 ;
if ( V_96 == 2 )
V_95 [ 1 ] -> V_61 . V_6 = V_99 ^ 1 ;
return 0 ;
}
static int F_58 ( struct V_39 * * V_95 , int V_105 , int V_106 )
{
int V_107 = 0 , V_108 = 0 , V_109 = 0 ;
struct V_39 * V_40 ;
int V_56 , V_110 , V_111 ;
if ( ! ( V_24 -> V_74 & V_112 ) )
return 0 ;
V_110 = V_105 + V_106 ;
if ( V_110 <= 1 )
return 0 ;
V_111 = 1 ;
for ( V_56 = 0 ; V_56 < V_110 ; V_56 ++ ) {
V_40 = V_95 [ V_56 ] ;
if ( V_111 ) {
V_107 = V_40 -> V_113 . V_114 ;
V_108 = V_40 -> V_113 . V_115 ;
V_109 = V_40 -> V_113 . V_116 ;
V_111 = 0 ;
} else if ( V_40 -> V_113 . V_114 != V_107 ||
V_40 -> V_113 . V_115 != V_108 ||
V_40 -> V_113 . V_116 != V_109 ) {
return - V_117 ;
}
}
return 0 ;
}
static int F_59 ( struct V_39 * V_118 , int V_119 ,
struct V_39 * V_95 [] , unsigned long * V_37 ,
int * V_59 )
{
struct V_39 * V_40 ;
int V_110 = 0 ;
if ( ! F_60 ( V_118 ) ) {
if ( V_110 >= V_119 )
return - 1 ;
V_95 [ V_110 ] = V_118 ;
V_37 [ V_110 ] = V_118 -> V_61 . V_120 ;
V_59 [ V_110 ++ ] = V_60 ;
}
F_61 (event, &group->sibling_list, group_entry) {
if ( ! F_60 ( V_40 ) &&
V_40 -> V_64 != V_121 ) {
if ( V_110 >= V_119 )
return - 1 ;
V_95 [ V_110 ] = V_40 ;
V_37 [ V_110 ] = V_40 -> V_61 . V_120 ;
V_59 [ V_110 ++ ] = V_60 ;
}
}
return V_110 ;
}
static int F_62 ( struct V_39 * V_40 , int V_122 )
{
struct V_30 * V_31 = F_32 ( & V_30 ) ;
int V_123 , V_52 = - V_117 ;
unsigned long V_74 ;
F_40 ( V_74 ) ;
V_123 = V_31 -> V_57 ;
if ( V_123 >= V_24 -> V_100 )
goto V_63;
V_31 -> V_40 [ V_123 ] = V_40 ;
V_31 -> V_37 [ V_123 ] = V_40 -> V_61 . V_120 ;
V_31 -> V_59 [ V_123 ] = V_60 ;
V_40 -> V_61 . V_64 = V_75 ;
if ( ! ( V_122 & V_124 ) )
V_40 -> V_61 . V_64 |= V_65 ;
if ( V_31 -> V_125 & V_126 )
goto V_127;
if ( F_58 ( V_31 -> V_40 , V_123 , 1 ) )
goto V_63;
if ( F_57 ( V_31 -> V_40 , V_31 -> V_37 , V_123 + 1 ) )
goto V_63;
V_127:
V_31 -> V_57 ++ ;
V_31 -> V_62 ++ ;
V_52 = 0 ;
V_63:
F_41 ( V_74 ) ;
return V_52 ;
}
static int F_63 ( struct V_39 * V_40 )
{
struct V_128 * V_113 = & V_40 -> V_113 ;
struct V_39 * V_95 [ V_129 ] ;
struct V_32 * V_33 = & V_40 -> V_61 ;
unsigned long V_37 [ V_129 ] ;
int V_130 [ V_129 ] ;
const struct V_1 * V_2 ;
int V_110 ;
if ( F_48 ( & V_81 ) < 0 )
return - V_131 ;
if ( F_64 ( V_40 ) )
return - V_132 ;
switch ( V_113 -> type ) {
case V_133 :
if ( V_113 -> V_83 >= V_24 -> V_134 )
return - V_90 ;
V_2 = V_24 -> V_135 ( V_113 -> V_83 ) ;
break;
case V_136 :
V_2 = F_54 ( V_113 -> V_83 ) ;
if ( F_65 ( V_2 ) )
return F_66 ( V_2 ) ;
break;
case V_137 :
V_2 = NULL ;
break;
default:
return - V_88 ;
}
if ( V_2 ) {
V_33 -> V_120 = F_1 ( V_2 ) ;
} else {
V_33 -> V_120 = V_113 -> V_83 ;
}
V_33 -> V_66 = V_24 -> V_73 ;
if ( ! V_113 -> V_114 )
V_33 -> V_66 |= V_24 -> V_70 ;
if ( ! V_113 -> V_115 )
V_33 -> V_66 |= V_24 -> V_71 ;
if ( ! V_113 -> V_116 )
V_33 -> V_66 |= V_24 -> V_72 ;
V_110 = 0 ;
if ( V_40 -> V_138 != V_40 ) {
V_110 = F_59 ( V_40 -> V_138 ,
V_24 -> V_100 - 1 ,
V_95 , V_37 , V_130 ) ;
if ( V_110 < 0 )
return - V_90 ;
}
V_37 [ V_110 ] = V_33 -> V_120 ;
V_95 [ V_110 ] = V_40 ;
if ( F_58 ( V_95 , V_110 , 1 ) )
return - V_90 ;
if ( F_57 ( V_95 , V_37 , V_110 + 1 ) )
return - V_90 ;
V_33 -> V_6 = V_60 ;
F_45 () ;
V_40 -> V_139 = F_56 ;
if ( ! V_33 -> V_51 ) {
V_33 -> V_51 = V_54 ;
V_33 -> V_53 = V_33 -> V_51 ;
F_24 ( & V_33 -> V_48 , V_33 -> V_51 ) ;
}
return 0 ;
}
static void F_67 ( struct V_68 * V_68 )
{
struct V_30 * V_140 = F_32 ( & V_30 ) ;
F_68 ( V_68 ) ;
V_140 -> V_125 |= V_126 ;
}
static void F_69 ( struct V_68 * V_68 )
{
struct V_30 * V_140 = F_32 ( & V_30 ) ;
V_140 -> V_125 &= ~ V_126 ;
F_70 ( V_68 ) ;
}
static int F_71 ( struct V_68 * V_68 )
{
struct V_30 * V_31 = F_32 ( & V_30 ) ;
int V_110 ;
if ( ! V_24 )
return - V_90 ;
V_31 = F_32 ( & V_30 ) ;
V_110 = V_31 -> V_57 ;
if ( F_58 ( V_31 -> V_40 , 0 , V_110 ) )
return - V_90 ;
if ( F_57 ( V_31 -> V_40 , V_31 -> V_37 , V_110 ) )
return - V_117 ;
V_31 -> V_125 &= ~ V_126 ;
F_70 ( V_68 ) ;
return 0 ;
}
void F_72 ( void )
{
unsigned long V_74 ;
int V_141 , V_56 ;
if ( ! V_24 )
return;
F_40 ( V_74 ) ;
V_141 = F_73 () ;
F_74 ( L_1 ) ;
for ( V_56 = 0 ; V_56 < V_24 -> V_36 ; V_56 ++ )
F_74 ( L_2 ,
V_141 , V_56 , V_7 -> V_20 ( V_56 ) ) ;
for ( V_56 = 0 ; V_56 < V_24 -> V_142 ; V_56 ++ )
F_74 ( L_3 ,
V_141 , V_56 , V_7 -> V_8 ( V_56 ) ) ;
F_41 ( V_74 ) ;
}
static int T_5 F_75 ( struct V_143 * V_144 ,
unsigned long V_145 , void * V_146 )
{
struct V_147 * args = V_146 ;
struct V_148 V_149 ;
struct V_30 * V_31 ;
struct V_150 * V_151 ;
int V_56 ;
if ( ! F_48 ( & V_79 ) )
return V_152 ;
switch ( V_145 ) {
case V_153 :
break;
default:
return V_152 ;
}
V_151 = args -> V_151 ;
V_31 = F_32 ( & V_30 ) ;
if ( V_24 -> V_73 &&
V_24 -> V_36 == 1 )
V_7 -> V_23 ( 0 , V_31 -> V_19 [ 0 ] ) ;
for ( V_56 = 0 ; V_56 < V_31 -> V_57 ; V_56 ++ ) {
struct V_39 * V_40 = V_31 -> V_40 [ V_56 ] ;
int V_6 = V_31 -> V_59 [ V_56 ] ;
struct V_32 * V_33 ;
T_2 V_5 ;
if ( V_24 -> V_73 &&
V_24 -> V_36 > 1 )
V_7 -> V_23 ( V_6 , V_31 -> V_19 [ V_6 ] ) ;
V_33 = & V_40 -> V_61 ;
V_5 = F_17 ( V_40 , V_33 , V_6 ) ;
if ( V_5 & ( 1ULL << 31 ) )
continue;
F_76 ( & V_149 , 0 , V_33 -> V_53 ) ;
if ( ! F_22 ( V_40 , V_33 , V_6 ) )
continue;
if ( F_77 ( V_40 , & V_149 , V_151 ) )
F_38 ( V_40 , 0 ) ;
}
return V_154 ;
}
static bool T_6 F_78 ( void )
{
if ( ! strcmp ( V_155 , L_4 ) ||
! strcmp ( V_155 , L_5 ) ||
! strcmp ( V_155 , L_6 ) ||
! strcmp ( V_155 , L_7 ) ) {
V_24 = & V_156 ;
return true ;
}
if ( ! strcmp ( V_155 , L_8 ) ) {
V_24 = & V_157 ;
return true ;
}
if ( ! strcmp ( V_155 , L_9 ) ||
! strcmp ( V_155 , L_10 ) ) {
V_24 = & V_158 ;
return true ;
}
if ( ! strcmp ( V_155 , L_11 ) ||
! strcmp ( V_155 , L_12 ) ) {
V_24 = & V_159 ;
return true ;
}
if ( ! strcmp ( V_155 , L_13 ) ) {
V_24 = & V_160 ;
return true ;
}
return false ;
}
static int T_6 F_79 ( void )
{
int V_161 ;
F_74 ( L_14 ) ;
V_161 = F_80 () ;
if ( V_161 || ! F_78 () ) {
F_81 ( L_15 , V_155 ) ;
return 0 ;
}
F_81 ( L_16 , V_155 ) ;
F_82 ( & V_68 , L_17 , V_137 ) ;
F_83 ( & V_162 ) ;
return 0 ;
}
void F_84 ( struct V_163 * V_164 ,
struct V_150 * V_151 )
{
unsigned long V_165 , V_166 ;
#ifdef F_85
int V_167 = 0 ;
#endif
F_86 () ;
F_87 ( V_164 , V_151 -> V_168 ) ;
V_165 = V_151 -> V_169 [ V_170 ] ;
V_166 = V_165 + V_171 ;
do {
struct V_172 * V_173 ;
struct V_150 * V_151 ;
unsigned long V_174 ;
if ( ! F_88 ( F_89 () , V_166 ) )
break;
V_173 = (struct V_172 * ) V_166 ;
V_151 = (struct V_150 * ) ( V_173 + 1 ) ;
if ( F_90 ( F_89 () , V_151 ) ) {
if ( F_91 ( V_151 ) )
break;
V_174 = V_151 -> V_168 ;
V_166 = V_151 -> V_169 [ V_170 ] + V_171 ;
} else {
V_174 = V_173 -> V_175 ;
V_166 = ( unsigned long ) V_173 -> V_166 + V_171 ;
}
F_87 ( V_164 , V_174 ) ;
#ifdef F_85
if ( ( V_174 + 8UL ) == ( unsigned long ) & V_176 ) {
int V_177 = V_178 -> V_179 ;
if ( V_178 -> V_180 && V_177 >= V_167 ) {
V_174 = V_178 -> V_180 [ V_177 - V_167 ] . V_52 ;
F_87 ( V_164 , V_174 ) ;
V_167 ++ ;
}
}
#endif
} while ( V_164 -> V_181 < V_182 );
}
static void F_92 ( struct V_163 * V_164 ,
struct V_150 * V_151 )
{
unsigned long V_183 ;
V_183 = V_151 -> V_169 [ V_170 ] + V_171 ;
do {
struct V_172 T_7 * V_184 ;
struct V_172 V_173 ;
unsigned long V_174 ;
V_184 = (struct V_172 T_7 * ) V_183 ;
if ( F_93 ( & V_173 , V_184 , sizeof( V_173 ) ) )
break;
V_174 = V_173 . V_175 ;
V_183 = ( unsigned long ) V_173 . V_166 + V_171 ;
F_87 ( V_164 , V_174 ) ;
} while ( V_164 -> V_181 < V_182 );
}
static void F_94 ( struct V_163 * V_164 ,
struct V_150 * V_151 )
{
unsigned long V_183 ;
V_183 = V_151 -> V_169 [ V_170 ] & 0xffffffffUL ;
do {
unsigned long V_174 ;
if ( F_95 ( V_183 ) ) {
struct V_172 T_7 * V_184 ;
struct V_172 V_173 ;
V_183 += V_171 ;
V_184 = (struct V_172 T_7 * ) V_183 ;
if ( F_93 ( & V_173 , V_184 , sizeof( V_173 ) ) )
break;
V_174 = V_173 . V_175 & 0xffffffff ;
V_183 = ( ( unsigned long ) V_173 . V_166 ) & 0xffffffff ;
} else {
struct V_185 T_7 * V_184 ;
struct V_185 V_173 ;
V_184 = (struct V_185 T_7 * ) V_183 ;
if ( F_93 ( & V_173 , V_184 , sizeof( V_173 ) ) )
break;
V_174 = V_173 . V_175 ;
V_183 = ( unsigned long ) V_173 . V_166 ;
}
F_87 ( V_164 , V_174 ) ;
} while ( V_164 -> V_181 < V_182 );
}
void
F_96 ( struct V_163 * V_164 , struct V_150 * V_151 )
{
F_87 ( V_164 , V_151 -> V_168 ) ;
if ( ! V_178 -> V_186 )
return;
F_97 () ;
if ( F_98 ( V_187 ) )
F_94 ( V_164 , V_151 ) ;
else
F_92 ( V_164 , V_151 ) ;
}
