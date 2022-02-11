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
V_7 -> V_21 ( V_6 , V_22 ) ;
V_7 -> V_13 ( V_6 , V_5 & 0xffffffff ) ;
V_7 -> V_21 ( V_6 , V_19 ) ;
}
static void F_12 ( int V_6 , T_2 V_5 )
{
T_2 V_19 ;
V_19 = V_7 -> V_20 ( V_6 ) ;
V_19 &= ~ ( V_23 | V_24 ) ;
V_7 -> V_13 ( V_6 , V_5 & 0xffffffff ) ;
V_7 -> V_21 ( V_6 , V_19 ) ;
}
static T_2 F_13 ( T_2 V_14 , int V_6 )
{
if ( V_6 == V_9 )
V_14 <<= V_25 -> V_26 ;
else
V_14 <<= V_25 -> V_27 ;
return V_14 ;
}
static T_2 F_14 ( int V_6 )
{
return F_13 ( V_25 -> V_28 , V_6 ) ;
}
static T_2 F_15 ( int V_6 )
{
return F_13 ( V_6 == V_9 ?
V_25 -> V_29 :
V_25 -> V_30 , V_6 ) ;
}
static inline void F_16 ( struct V_31 * V_32 , struct V_33 * V_34 , int V_6 )
{
T_2 V_35 , V_5 , V_11 = F_14 ( V_6 ) ;
int V_36 = 0 ;
if ( V_25 -> V_37 > 1 )
V_36 = V_6 ;
V_35 = F_3 ( V_32 -> V_38 [ V_6 ] ) ;
V_5 = V_32 -> V_19 [ V_36 ] ;
V_5 &= ~ V_11 ;
V_5 |= F_13 ( V_35 , V_6 ) ;
V_32 -> V_19 [ V_36 ] = V_5 ;
V_7 -> V_21 ( V_36 , V_32 -> V_19 [ V_36 ] ) ;
}
static inline void F_17 ( struct V_31 * V_32 , struct V_33 * V_34 , int V_6 )
{
T_2 V_11 = F_14 ( V_6 ) ;
T_2 V_39 = F_15 ( V_6 ) ;
int V_36 = 0 ;
T_2 V_5 ;
if ( V_25 -> V_37 > 1 )
V_36 = V_6 ;
V_5 = V_32 -> V_19 [ V_36 ] ;
V_5 &= ~ V_11 ;
V_5 |= V_39 ;
V_32 -> V_19 [ V_36 ] = V_5 ;
V_7 -> V_21 ( V_36 , V_32 -> V_19 [ V_36 ] ) ;
}
static T_2 F_18 ( struct V_40 * V_41 ,
struct V_33 * V_34 , int V_6 )
{
int V_10 = 64 - 32 ;
T_2 V_42 , V_43 ;
T_4 V_44 ;
V_45:
V_42 = F_19 ( & V_34 -> V_46 ) ;
V_43 = V_25 -> V_47 ( V_6 ) ;
if ( F_20 ( & V_34 -> V_46 , V_42 ,
V_43 ) != V_42 )
goto V_45;
V_44 = ( V_43 << V_10 ) - ( V_42 << V_10 ) ;
V_44 >>= V_10 ;
F_21 ( V_44 , & V_41 -> V_48 ) ;
F_22 ( V_44 , & V_34 -> V_49 ) ;
return V_43 ;
}
static int F_23 ( struct V_40 * V_41 ,
struct V_33 * V_34 , int V_6 )
{
T_4 V_50 = F_19 ( & V_34 -> V_49 ) ;
T_4 V_51 = V_34 -> V_52 ;
int V_53 = 0 ;
if ( F_24 ( V_50 <= - V_51 ) ) {
V_50 = V_51 ;
F_25 ( & V_34 -> V_49 , V_50 ) ;
V_34 -> V_54 = V_51 ;
V_53 = 1 ;
}
if ( F_24 ( V_50 <= 0 ) ) {
V_50 += V_51 ;
F_25 ( & V_34 -> V_49 , V_50 ) ;
V_34 -> V_54 = V_51 ;
V_53 = 1 ;
}
if ( V_50 > V_55 )
V_50 = V_55 ;
F_25 ( & V_34 -> V_46 , ( T_2 ) - V_50 ) ;
V_25 -> V_56 ( V_6 , ( T_2 ) ( - V_50 ) & 0xffffffff ) ;
F_26 ( V_41 ) ;
return V_53 ;
}
static void F_27 ( struct V_31 * V_32 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_32 -> V_58 ; V_57 ++ ) {
struct V_40 * V_59 = V_32 -> V_41 [ V_57 ] ;
if ( V_32 -> V_60 [ V_57 ] != V_61 &&
V_32 -> V_60 [ V_57 ] != V_59 -> V_62 . V_6 ) {
F_18 ( V_59 , & V_59 -> V_62 ,
V_32 -> V_60 [ V_57 ] ) ;
V_32 -> V_60 [ V_57 ] = V_61 ;
}
}
}
static void F_28 ( struct V_31 * V_32 )
{
int V_57 ;
if ( ! V_32 -> V_63 )
goto V_64;
for ( V_57 = 0 ; V_57 < V_32 -> V_58 ; V_57 ++ ) {
struct V_40 * V_59 = V_32 -> V_41 [ V_57 ] ;
struct V_33 * V_34 = & V_59 -> V_62 ;
int V_6 = V_34 -> V_6 ;
T_2 V_35 ;
if ( V_32 -> V_60 [ V_57 ] != V_61 )
continue;
F_23 ( V_59 , V_34 , V_6 ) ;
V_32 -> V_60 [ V_57 ] = V_6 ;
V_35 = F_3 ( V_32 -> V_38 [ V_57 ] ) ;
V_32 -> V_19 [ 0 ] &= ~ F_14 ( V_6 ) ;
if ( V_34 -> V_65 & V_66 )
V_32 -> V_19 [ 0 ] |= F_15 ( V_6 ) ;
else
V_32 -> V_19 [ 0 ] |= F_13 ( V_35 , V_6 ) ;
}
V_64:
V_32 -> V_19 [ 0 ] |= V_32 -> V_41 [ 0 ] -> V_62 . V_67 ;
}
static void F_29 ( struct V_31 * V_32 )
{
int V_57 ;
if ( ! V_32 -> V_63 )
goto V_64;
for ( V_57 = 0 ; V_57 < V_32 -> V_58 ; V_57 ++ ) {
struct V_40 * V_59 = V_32 -> V_41 [ V_57 ] ;
struct V_33 * V_34 = & V_59 -> V_62 ;
int V_6 = V_34 -> V_6 ;
if ( V_32 -> V_60 [ V_57 ] != V_61 )
continue;
V_32 -> V_60 [ V_57 ] = V_6 ;
F_30 ( V_59 , V_68 ) ;
}
V_64:
for ( V_57 = 0 ; V_57 < V_32 -> V_58 ; V_57 ++ ) {
struct V_40 * V_59 = V_32 -> V_41 [ V_57 ] ;
int V_6 = V_59 -> V_62 . V_6 ;
V_32 -> V_19 [ V_6 ] |= V_59 -> V_62 . V_67 ;
}
}
static void F_31 ( struct V_31 * V_32 )
{
if ( V_32 -> V_63 )
F_27 ( V_32 ) ;
if ( V_25 -> V_37 == 1 ) {
F_28 ( V_32 ) ;
} else {
F_29 ( V_32 ) ;
}
}
static void F_32 ( struct V_69 * V_69 )
{
struct V_31 * V_32 = F_33 ( & V_31 ) ;
int V_57 ;
if ( V_32 -> V_70 )
return;
V_32 -> V_70 = 1 ;
F_34 () ;
if ( V_32 -> V_58 )
F_31 ( V_32 ) ;
for ( V_57 = 0 ; V_57 < V_25 -> V_37 ; V_57 ++ )
V_7 -> V_21 ( V_57 , V_32 -> V_19 [ V_57 ] ) ;
}
static void F_35 ( struct V_69 * V_69 )
{
struct V_31 * V_32 = F_33 ( & V_31 ) ;
int V_57 ;
if ( ! V_32 -> V_70 )
return;
V_32 -> V_70 = 0 ;
V_32 -> V_63 = 0 ;
for ( V_57 = 0 ; V_57 < V_25 -> V_37 ; V_57 ++ ) {
T_2 V_5 = V_32 -> V_19 [ V_57 ] ;
V_5 &= ~ ( V_25 -> V_71 | V_25 -> V_72 |
V_25 -> V_73 | V_25 -> V_74 ) ;
V_32 -> V_19 [ V_57 ] = V_5 ;
V_7 -> V_21 ( V_57 , V_32 -> V_19 [ V_57 ] ) ;
}
}
static int F_36 ( struct V_31 * V_32 ,
struct V_40 * V_41 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_32 -> V_58 ; V_57 ++ ) {
if ( V_32 -> V_41 [ V_57 ] == V_41 )
break;
}
F_37 ( V_57 == V_32 -> V_58 ) ;
return V_32 -> V_60 [ V_57 ] ;
}
static void F_30 ( struct V_40 * V_41 , int V_75 )
{
struct V_31 * V_32 = F_33 ( & V_31 ) ;
int V_6 = F_36 ( V_32 , V_41 ) ;
if ( V_75 & V_68 ) {
F_38 ( ! ( V_41 -> V_62 . V_65 & V_76 ) ) ;
F_23 ( V_41 , & V_41 -> V_62 , V_6 ) ;
}
V_41 -> V_62 . V_65 = 0 ;
F_16 ( V_32 , & V_41 -> V_62 , V_6 ) ;
}
static void F_39 ( struct V_40 * V_41 , int V_75 )
{
struct V_31 * V_32 = F_33 ( & V_31 ) ;
int V_6 = F_36 ( V_32 , V_41 ) ;
if ( ! ( V_41 -> V_62 . V_65 & V_66 ) ) {
F_17 ( V_32 , & V_41 -> V_62 , V_6 ) ;
V_41 -> V_62 . V_65 |= V_66 ;
}
if ( ! ( V_41 -> V_62 . V_65 & V_76 ) && ( V_75 & V_77 ) ) {
F_18 ( V_41 , & V_41 -> V_62 , V_6 ) ;
V_41 -> V_62 . V_65 |= V_76 ;
}
}
static void F_40 ( struct V_40 * V_41 , int V_78 )
{
struct V_31 * V_32 = F_33 ( & V_31 ) ;
unsigned long V_75 ;
int V_57 ;
F_41 ( V_75 ) ;
for ( V_57 = 0 ; V_57 < V_32 -> V_58 ; V_57 ++ ) {
if ( V_41 == V_32 -> V_41 [ V_57 ] ) {
F_39 ( V_41 , V_77 ) ;
while ( ++ V_57 < V_32 -> V_58 ) {
V_32 -> V_41 [ V_57 - 1 ] = V_32 -> V_41 [ V_57 ] ;
V_32 -> V_38 [ V_57 - 1 ] = V_32 -> V_38 [ V_57 ] ;
V_32 -> V_60 [ V_57 - 1 ] =
V_32 -> V_60 [ V_57 ] ;
}
F_26 ( V_41 ) ;
V_32 -> V_58 -- ;
break;
}
}
F_42 ( V_75 ) ;
}
static void F_43 ( struct V_40 * V_41 )
{
struct V_31 * V_32 = F_33 ( & V_31 ) ;
int V_6 = F_36 ( V_32 , V_41 ) ;
struct V_33 * V_34 = & V_41 -> V_62 ;
F_18 ( V_41 , V_34 , V_6 ) ;
}
static void F_44 ( void * V_79 )
{
struct V_31 * V_32 = F_33 ( & V_31 ) ;
int V_57 ;
F_45 ( NULL ) ;
for ( V_57 = 0 ; V_57 < V_25 -> V_37 ; V_57 ++ )
V_32 -> V_19 [ V_57 ] = V_7 -> V_20 ( V_57 ) ;
}
static void F_46 ( void )
{
if ( F_47 ( & V_80 ) )
return;
F_48 ( & V_81 ) ;
if ( F_49 ( & V_80 ) == 0 ) {
if ( F_49 ( & V_82 ) > 0 ) {
F_50 ( F_44 , NULL , 1 ) ;
F_37 ( F_49 ( & V_82 ) != 0 ) ;
}
F_51 ( & V_80 ) ;
}
F_52 ( & V_81 ) ;
}
static void F_53 ( void )
{
if ( F_54 ( & V_80 , & V_81 ) ) {
if ( F_49 ( & V_82 ) == 0 )
F_50 ( V_83 , NULL , 1 ) ;
F_52 ( & V_81 ) ;
}
}
static const struct V_1 * F_55 ( T_2 V_84 )
{
unsigned int V_85 , V_86 , V_87 ;
const struct V_1 * V_2 ;
if ( ! V_25 -> V_88 )
return F_56 ( - V_89 ) ;
V_85 = ( V_84 >> 0 ) & 0xff ;
if ( V_85 >= V_90 )
return F_56 ( - V_91 ) ;
V_86 = ( V_84 >> 8 ) & 0xff ;
if ( V_86 >= V_92 )
return F_56 ( - V_91 ) ;
V_87 = ( V_84 >> 16 ) & 0xff ;
if ( V_87 >= V_93 )
return F_56 ( - V_91 ) ;
V_2 = & ( ( * V_25 -> V_88 ) [ V_85 ] [ V_86 ] [ V_87 ] ) ;
if ( V_2 -> V_3 == V_94 )
return F_56 ( - V_89 ) ;
if ( V_2 -> V_3 == V_95 )
return F_56 ( - V_91 ) ;
return V_2 ;
}
static void F_57 ( struct V_40 * V_41 )
{
F_53 () ;
}
static int F_58 ( struct V_40 * * V_96 ,
unsigned long * V_38 , int V_97 )
{
T_1 V_98 = 0 , V_99 = 0 ;
int V_100 = 0 ;
if ( ! V_97 )
return 0 ;
if ( V_97 > V_25 -> V_101 )
return - 1 ;
if ( ! ( V_25 -> V_75 & V_102 ) ) {
int V_57 ;
for ( V_57 = 0 ; V_57 < V_97 ; V_57 ++ )
V_96 [ V_57 ] -> V_62 . V_6 = V_57 ;
return 0 ;
}
V_98 = F_2 ( V_38 [ 0 ] ) ;
if ( V_97 == 1 ) {
if ( V_98 & V_103 )
V_100 = 1 ;
goto V_104;
}
F_37 ( V_97 != 2 ) ;
V_99 = F_2 ( V_38 [ 1 ] ) ;
if ( V_98 == ( V_105 | V_103 ) &&
V_99 == ( V_105 | V_103 ) )
goto V_104;
if ( ( V_98 == V_105 || V_98 == V_103 ) &&
V_99 == ( V_105 | V_103 ) ) {
if ( V_98 & V_103 )
V_100 = 1 ;
goto V_104;
}
if ( ( V_99 == V_105 || V_99 == V_103 ) &&
V_98 == ( V_105 | V_103 ) ) {
if ( V_99 & V_105 )
V_100 = 1 ;
goto V_104;
}
if ( ( V_98 == V_105 && V_99 == V_103 ) ||
( V_98 == V_103 && V_99 == V_105 ) ) {
if ( V_98 & V_103 )
V_100 = 1 ;
goto V_104;
}
return - 1 ;
V_104:
V_96 [ 0 ] -> V_62 . V_6 = V_100 ;
if ( V_97 == 2 )
V_96 [ 1 ] -> V_62 . V_6 = V_100 ^ 1 ;
return 0 ;
}
static int F_59 ( struct V_40 * * V_96 , int V_106 , int V_107 )
{
int V_108 = 0 , V_109 = 0 , V_110 = 0 ;
struct V_40 * V_41 ;
int V_57 , V_111 , V_112 ;
if ( ! ( V_25 -> V_75 & V_113 ) )
return 0 ;
V_111 = V_106 + V_107 ;
if ( V_111 <= 1 )
return 0 ;
V_112 = 1 ;
for ( V_57 = 0 ; V_57 < V_111 ; V_57 ++ ) {
V_41 = V_96 [ V_57 ] ;
if ( V_112 ) {
V_108 = V_41 -> V_114 . V_115 ;
V_109 = V_41 -> V_114 . V_116 ;
V_110 = V_41 -> V_114 . V_117 ;
V_112 = 0 ;
} else if ( V_41 -> V_114 . V_115 != V_108 ||
V_41 -> V_114 . V_116 != V_109 ||
V_41 -> V_114 . V_117 != V_110 ) {
return - V_118 ;
}
}
return 0 ;
}
static int F_60 ( struct V_40 * V_119 , int V_120 ,
struct V_40 * V_96 [] , unsigned long * V_38 ,
int * V_60 )
{
struct V_40 * V_41 ;
int V_111 = 0 ;
if ( ! F_61 ( V_119 ) ) {
if ( V_111 >= V_120 )
return - 1 ;
V_96 [ V_111 ] = V_119 ;
V_38 [ V_111 ] = V_119 -> V_62 . V_121 ;
V_60 [ V_111 ++ ] = V_61 ;
}
F_62 (event, &group->sibling_list, group_entry) {
if ( ! F_61 ( V_41 ) &&
V_41 -> V_65 != V_122 ) {
if ( V_111 >= V_120 )
return - 1 ;
V_96 [ V_111 ] = V_41 ;
V_38 [ V_111 ] = V_41 -> V_62 . V_121 ;
V_60 [ V_111 ++ ] = V_61 ;
}
}
return V_111 ;
}
static int F_63 ( struct V_40 * V_41 , int V_123 )
{
struct V_31 * V_32 = F_33 ( & V_31 ) ;
int V_124 , V_53 = - V_118 ;
unsigned long V_75 ;
F_41 ( V_75 ) ;
V_124 = V_32 -> V_58 ;
if ( V_124 >= V_25 -> V_101 )
goto V_64;
V_32 -> V_41 [ V_124 ] = V_41 ;
V_32 -> V_38 [ V_124 ] = V_41 -> V_62 . V_121 ;
V_32 -> V_60 [ V_124 ] = V_61 ;
V_41 -> V_62 . V_65 = V_76 ;
if ( ! ( V_123 & V_125 ) )
V_41 -> V_62 . V_65 |= V_66 ;
if ( V_32 -> V_126 & V_127 )
goto V_128;
if ( F_59 ( V_32 -> V_41 , V_124 , 1 ) )
goto V_64;
if ( F_58 ( V_32 -> V_41 , V_32 -> V_38 , V_124 + 1 ) )
goto V_64;
V_128:
V_32 -> V_58 ++ ;
V_32 -> V_63 ++ ;
V_53 = 0 ;
V_64:
F_42 ( V_75 ) ;
return V_53 ;
}
static int F_64 ( struct V_40 * V_41 )
{
struct V_129 * V_114 = & V_41 -> V_114 ;
struct V_40 * V_96 [ V_130 ] ;
struct V_33 * V_34 = & V_41 -> V_62 ;
unsigned long V_38 [ V_130 ] ;
int V_131 [ V_130 ] ;
const struct V_1 * V_2 ;
int V_111 ;
if ( F_49 ( & V_82 ) < 0 )
return - V_132 ;
if ( F_65 ( V_41 ) )
return - V_133 ;
switch ( V_114 -> type ) {
case V_134 :
if ( V_114 -> V_84 >= V_25 -> V_135 )
return - V_91 ;
V_2 = V_25 -> V_136 ( V_114 -> V_84 ) ;
break;
case V_137 :
V_2 = F_55 ( V_114 -> V_84 ) ;
if ( F_66 ( V_2 ) )
return F_67 ( V_2 ) ;
break;
case V_138 :
V_2 = NULL ;
break;
default:
return - V_89 ;
}
if ( V_2 ) {
V_34 -> V_121 = F_1 ( V_2 ) ;
} else {
V_34 -> V_121 = V_114 -> V_84 ;
}
V_34 -> V_67 = V_25 -> V_74 ;
if ( ! V_114 -> V_115 )
V_34 -> V_67 |= V_25 -> V_71 ;
if ( ! V_114 -> V_116 )
V_34 -> V_67 |= V_25 -> V_72 ;
if ( ! V_114 -> V_117 )
V_34 -> V_67 |= V_25 -> V_73 ;
V_111 = 0 ;
if ( V_41 -> V_139 != V_41 ) {
V_111 = F_60 ( V_41 -> V_139 ,
V_25 -> V_101 - 1 ,
V_96 , V_38 , V_131 ) ;
if ( V_111 < 0 )
return - V_91 ;
}
V_38 [ V_111 ] = V_34 -> V_121 ;
V_96 [ V_111 ] = V_41 ;
if ( F_59 ( V_96 , V_111 , 1 ) )
return - V_91 ;
if ( F_58 ( V_96 , V_38 , V_111 + 1 ) )
return - V_91 ;
V_34 -> V_6 = V_61 ;
F_46 () ;
V_41 -> V_140 = F_57 ;
if ( ! V_34 -> V_52 ) {
V_34 -> V_52 = V_55 ;
V_34 -> V_54 = V_34 -> V_52 ;
F_25 ( & V_34 -> V_49 , V_34 -> V_52 ) ;
}
return 0 ;
}
static void F_68 ( struct V_69 * V_69 )
{
struct V_31 * V_141 = F_33 ( & V_31 ) ;
F_69 ( V_69 ) ;
V_141 -> V_126 |= V_127 ;
}
static void F_70 ( struct V_69 * V_69 )
{
struct V_31 * V_141 = F_33 ( & V_31 ) ;
V_141 -> V_126 &= ~ V_127 ;
F_71 ( V_69 ) ;
}
static int F_72 ( struct V_69 * V_69 )
{
struct V_31 * V_32 = F_33 ( & V_31 ) ;
int V_111 ;
if ( ! V_25 )
return - V_91 ;
V_32 = F_33 ( & V_31 ) ;
V_111 = V_32 -> V_58 ;
if ( F_59 ( V_32 -> V_41 , 0 , V_111 ) )
return - V_91 ;
if ( F_58 ( V_32 -> V_41 , V_32 -> V_38 , V_111 ) )
return - V_118 ;
V_32 -> V_126 &= ~ V_127 ;
F_71 ( V_69 ) ;
return 0 ;
}
void F_73 ( void )
{
unsigned long V_75 ;
int V_142 , V_57 ;
if ( ! V_25 )
return;
F_41 ( V_75 ) ;
V_142 = F_74 () ;
F_75 ( L_1 ) ;
for ( V_57 = 0 ; V_57 < V_25 -> V_37 ; V_57 ++ )
F_75 ( L_2 ,
V_142 , V_57 , V_7 -> V_20 ( V_57 ) ) ;
for ( V_57 = 0 ; V_57 < V_25 -> V_143 ; V_57 ++ )
F_75 ( L_3 ,
V_142 , V_57 , V_7 -> V_8 ( V_57 ) ) ;
F_42 ( V_75 ) ;
}
static int T_5 F_76 ( struct V_144 * V_145 ,
unsigned long V_146 , void * V_147 )
{
struct V_148 * args = V_147 ;
struct V_149 V_150 ;
struct V_31 * V_32 ;
struct V_151 * V_152 ;
int V_57 ;
if ( ! F_49 ( & V_80 ) )
return V_153 ;
switch ( V_146 ) {
case V_154 :
break;
default:
return V_153 ;
}
V_152 = args -> V_152 ;
V_32 = F_33 ( & V_31 ) ;
if ( V_25 -> V_74 &&
V_25 -> V_37 == 1 )
V_7 -> V_21 ( 0 , V_32 -> V_19 [ 0 ] ) ;
for ( V_57 = 0 ; V_57 < V_32 -> V_58 ; V_57 ++ ) {
struct V_40 * V_41 = V_32 -> V_41 [ V_57 ] ;
int V_6 = V_32 -> V_60 [ V_57 ] ;
struct V_33 * V_34 ;
T_2 V_5 ;
if ( V_25 -> V_74 &&
V_25 -> V_37 > 1 )
V_7 -> V_21 ( V_6 , V_32 -> V_19 [ V_6 ] ) ;
V_34 = & V_41 -> V_62 ;
V_5 = F_18 ( V_41 , V_34 , V_6 ) ;
if ( V_5 & ( 1ULL << 31 ) )
continue;
F_77 ( & V_150 , 0 , V_34 -> V_54 ) ;
if ( ! F_23 ( V_41 , V_34 , V_6 ) )
continue;
if ( F_78 ( V_41 , & V_150 , V_152 ) )
F_39 ( V_41 , 0 ) ;
}
return V_155 ;
}
static bool T_6 F_79 ( void )
{
if ( ! strcmp ( V_156 , L_4 ) ||
! strcmp ( V_156 , L_5 ) ||
! strcmp ( V_156 , L_6 ) ||
! strcmp ( V_156 , L_7 ) ) {
V_25 = & V_157 ;
return true ;
}
if ( ! strcmp ( V_156 , L_8 ) ) {
V_25 = & V_158 ;
return true ;
}
if ( ! strcmp ( V_156 , L_9 ) ||
! strcmp ( V_156 , L_10 ) ) {
V_25 = & V_159 ;
return true ;
}
if ( ! strcmp ( V_156 , L_11 ) ||
! strcmp ( V_156 , L_12 ) ) {
V_25 = & V_160 ;
return true ;
}
if ( ! strcmp ( V_156 , L_13 ) ) {
V_25 = & V_161 ;
return true ;
}
return false ;
}
static int T_6 F_80 ( void )
{
int V_162 ;
F_75 ( L_14 ) ;
V_162 = F_81 () ;
if ( V_162 || ! F_79 () ) {
F_82 ( L_15 , V_156 ) ;
return 0 ;
}
F_82 ( L_16 , V_156 ) ;
F_83 ( & V_69 , L_17 , V_138 ) ;
F_84 ( & V_163 ) ;
return 0 ;
}
void F_85 ( struct V_164 * V_165 ,
struct V_151 * V_152 )
{
unsigned long V_166 , V_167 ;
#ifdef F_86
int V_168 = 0 ;
#endif
F_87 () ;
F_88 ( V_165 , V_152 -> V_169 ) ;
V_166 = V_152 -> V_170 [ V_171 ] ;
V_167 = V_166 + V_172 ;
do {
struct V_173 * V_174 ;
struct V_151 * V_152 ;
unsigned long V_175 ;
if ( ! F_89 ( F_90 () , V_167 ) )
break;
V_174 = (struct V_173 * ) V_167 ;
V_152 = (struct V_151 * ) ( V_174 + 1 ) ;
if ( F_91 ( F_90 () , V_152 ) ) {
if ( F_92 ( V_152 ) )
break;
V_175 = V_152 -> V_169 ;
V_167 = V_152 -> V_170 [ V_171 ] + V_172 ;
} else {
V_175 = V_174 -> V_176 ;
V_167 = ( unsigned long ) V_174 -> V_167 + V_172 ;
}
F_88 ( V_165 , V_175 ) ;
#ifdef F_86
if ( ( V_175 + 8UL ) == ( unsigned long ) & V_177 ) {
int V_178 = V_179 -> V_180 ;
if ( V_179 -> V_181 && V_178 >= V_168 ) {
V_175 = V_179 -> V_181 [ V_178 - V_168 ] . V_53 ;
F_88 ( V_165 , V_175 ) ;
V_168 ++ ;
}
}
#endif
} while ( V_165 -> V_182 < V_183 );
}
static void F_93 ( struct V_164 * V_165 ,
struct V_151 * V_152 )
{
unsigned long V_184 ;
V_184 = V_152 -> V_170 [ V_171 ] + V_172 ;
do {
struct V_173 T_7 * V_185 ;
struct V_173 V_174 ;
unsigned long V_175 ;
V_185 = (struct V_173 T_7 * ) V_184 ;
if ( F_94 ( & V_174 , V_185 , sizeof( V_174 ) ) )
break;
V_175 = V_174 . V_176 ;
V_184 = ( unsigned long ) V_174 . V_167 + V_172 ;
F_88 ( V_165 , V_175 ) ;
} while ( V_165 -> V_182 < V_183 );
}
static void F_95 ( struct V_164 * V_165 ,
struct V_151 * V_152 )
{
unsigned long V_184 ;
V_184 = V_152 -> V_170 [ V_171 ] & 0xffffffffUL ;
do {
unsigned long V_175 ;
if ( F_96 ( V_184 ) ) {
struct V_173 T_7 * V_185 ;
struct V_173 V_174 ;
V_184 += V_172 ;
V_185 = (struct V_173 T_7 * ) V_184 ;
if ( F_94 ( & V_174 , V_185 , sizeof( V_174 ) ) )
break;
V_175 = V_174 . V_176 & 0xffffffff ;
V_184 = ( ( unsigned long ) V_174 . V_167 ) & 0xffffffff ;
} else {
struct V_186 T_7 * V_185 ;
struct V_186 V_174 ;
V_185 = (struct V_186 T_7 * ) V_184 ;
if ( F_94 ( & V_174 , V_185 , sizeof( V_174 ) ) )
break;
V_175 = V_174 . V_176 ;
V_184 = ( unsigned long ) V_174 . V_167 ;
}
F_88 ( V_165 , V_175 ) ;
} while ( V_165 -> V_182 < V_183 );
}
void
F_97 ( struct V_164 * V_165 , struct V_151 * V_152 )
{
F_88 ( V_165 , V_152 -> V_169 ) ;
if ( ! V_179 -> V_187 )
return;
F_98 () ;
if ( F_99 ( V_188 ) )
F_95 ( V_165 , V_152 ) ;
else
F_93 ( V_165 , V_152 ) ;
}
