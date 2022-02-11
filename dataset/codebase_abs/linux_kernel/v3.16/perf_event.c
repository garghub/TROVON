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
static T_2 F_12 ( T_2 V_14 , int V_6 )
{
if ( V_6 == V_9 )
V_14 <<= V_23 -> V_24 ;
else
V_14 <<= V_23 -> V_25 ;
return V_14 ;
}
static T_2 F_13 ( int V_6 )
{
return F_12 ( V_23 -> V_26 , V_6 ) ;
}
static T_2 F_14 ( int V_6 )
{
return F_12 ( V_6 == V_9 ?
V_23 -> V_27 :
V_23 -> V_28 , V_6 ) ;
}
static inline void F_15 ( struct V_29 * V_30 , struct V_31 * V_32 , int V_6 )
{
T_2 V_33 , V_5 , V_11 = F_13 ( V_6 ) ;
int V_34 = 0 ;
if ( V_23 -> V_35 > 1 )
V_34 = V_6 ;
V_33 = F_3 ( V_30 -> V_36 [ V_6 ] ) ;
V_5 = V_30 -> V_19 [ V_34 ] ;
V_5 &= ~ V_11 ;
V_5 |= F_12 ( V_33 , V_6 ) ;
V_30 -> V_19 [ V_34 ] = V_5 ;
V_7 -> V_21 ( V_34 , V_30 -> V_19 [ V_34 ] ) ;
}
static inline void F_16 ( struct V_29 * V_30 , struct V_31 * V_32 , int V_6 )
{
T_2 V_11 = F_13 ( V_6 ) ;
T_2 V_37 = F_14 ( V_6 ) ;
int V_34 = 0 ;
T_2 V_5 ;
if ( V_23 -> V_35 > 1 )
V_34 = V_6 ;
V_5 = V_30 -> V_19 [ V_34 ] ;
V_5 &= ~ V_11 ;
V_5 |= V_37 ;
V_30 -> V_19 [ V_34 ] = V_5 ;
V_7 -> V_21 ( V_34 , V_30 -> V_19 [ V_34 ] ) ;
}
static T_2 F_17 ( struct V_38 * V_39 ,
struct V_31 * V_32 , int V_6 )
{
int V_10 = 64 - 32 ;
T_2 V_40 , V_41 ;
T_4 V_42 ;
V_43:
V_40 = F_18 ( & V_32 -> V_44 ) ;
V_41 = V_23 -> V_45 ( V_6 ) ;
if ( F_19 ( & V_32 -> V_44 , V_40 ,
V_41 ) != V_40 )
goto V_43;
V_42 = ( V_41 << V_10 ) - ( V_40 << V_10 ) ;
V_42 >>= V_10 ;
F_20 ( V_42 , & V_39 -> V_46 ) ;
F_21 ( V_42 , & V_32 -> V_47 ) ;
return V_41 ;
}
static int F_22 ( struct V_38 * V_39 ,
struct V_31 * V_32 , int V_6 )
{
T_4 V_48 = F_18 ( & V_32 -> V_47 ) ;
T_4 V_49 = V_32 -> V_50 ;
int V_51 = 0 ;
if ( F_23 ( V_48 <= - V_49 ) ) {
V_48 = V_49 ;
F_24 ( & V_32 -> V_47 , V_48 ) ;
V_32 -> V_52 = V_49 ;
V_51 = 1 ;
}
if ( F_23 ( V_48 <= 0 ) ) {
V_48 += V_49 ;
F_24 ( & V_32 -> V_47 , V_48 ) ;
V_32 -> V_52 = V_49 ;
V_51 = 1 ;
}
if ( V_48 > V_53 )
V_48 = V_53 ;
F_24 ( & V_32 -> V_44 , ( T_2 ) - V_48 ) ;
V_23 -> V_54 ( V_6 , ( T_2 ) ( - V_48 ) & 0xffffffff ) ;
F_25 ( V_39 ) ;
return V_51 ;
}
static void F_26 ( struct V_29 * V_30 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_30 -> V_56 ; V_55 ++ ) {
struct V_38 * V_57 = V_30 -> V_39 [ V_55 ] ;
if ( V_30 -> V_58 [ V_55 ] != V_59 &&
V_30 -> V_58 [ V_55 ] != V_57 -> V_60 . V_6 ) {
F_17 ( V_57 , & V_57 -> V_60 ,
V_30 -> V_58 [ V_55 ] ) ;
V_30 -> V_58 [ V_55 ] = V_59 ;
}
}
}
static void F_27 ( struct V_29 * V_30 )
{
int V_55 ;
if ( ! V_30 -> V_61 )
goto V_62;
for ( V_55 = 0 ; V_55 < V_30 -> V_56 ; V_55 ++ ) {
struct V_38 * V_57 = V_30 -> V_39 [ V_55 ] ;
struct V_31 * V_32 = & V_57 -> V_60 ;
int V_6 = V_32 -> V_6 ;
T_2 V_33 ;
if ( V_30 -> V_58 [ V_55 ] != V_59 )
continue;
F_22 ( V_57 , V_32 , V_6 ) ;
V_30 -> V_58 [ V_55 ] = V_6 ;
V_33 = F_3 ( V_30 -> V_36 [ V_55 ] ) ;
V_30 -> V_19 [ 0 ] &= ~ F_13 ( V_6 ) ;
if ( V_32 -> V_63 & V_64 )
V_30 -> V_19 [ 0 ] |= F_14 ( V_6 ) ;
else
V_30 -> V_19 [ 0 ] |= F_12 ( V_33 , V_6 ) ;
}
V_62:
V_30 -> V_19 [ 0 ] |= V_30 -> V_39 [ 0 ] -> V_60 . V_65 ;
}
static void F_28 ( struct V_29 * V_30 )
{
int V_55 ;
if ( ! V_30 -> V_61 )
goto V_62;
for ( V_55 = 0 ; V_55 < V_30 -> V_56 ; V_55 ++ ) {
struct V_38 * V_57 = V_30 -> V_39 [ V_55 ] ;
struct V_31 * V_32 = & V_57 -> V_60 ;
int V_6 = V_32 -> V_6 ;
T_2 V_33 ;
if ( V_30 -> V_58 [ V_55 ] != V_59 )
continue;
F_22 ( V_57 , V_32 , V_6 ) ;
V_30 -> V_58 [ V_55 ] = V_6 ;
V_33 = F_3 ( V_30 -> V_36 [ V_55 ] ) ;
V_30 -> V_19 [ V_6 ] &= ~ F_13 ( V_6 ) ;
if ( V_32 -> V_63 & V_64 )
V_30 -> V_19 [ V_6 ] |= F_14 ( V_6 ) ;
else
V_30 -> V_19 [ V_6 ] |= F_12 ( V_33 , V_6 ) ;
}
V_62:
for ( V_55 = 0 ; V_55 < V_30 -> V_56 ; V_55 ++ ) {
struct V_38 * V_57 = V_30 -> V_39 [ V_55 ] ;
int V_6 = V_57 -> V_60 . V_6 ;
V_30 -> V_19 [ V_6 ] |= V_57 -> V_60 . V_65 ;
}
}
static void F_29 ( struct V_29 * V_30 )
{
if ( V_30 -> V_61 )
F_26 ( V_30 ) ;
if ( V_23 -> V_35 == 1 ) {
F_27 ( V_30 ) ;
} else {
F_28 ( V_30 ) ;
}
}
static void F_30 ( struct V_66 * V_66 )
{
struct V_29 * V_30 = & F_31 ( V_29 ) ;
int V_55 ;
if ( V_30 -> V_67 )
return;
V_30 -> V_67 = 1 ;
F_32 () ;
if ( V_30 -> V_56 )
F_29 ( V_30 ) ;
for ( V_55 = 0 ; V_55 < V_23 -> V_35 ; V_55 ++ )
V_7 -> V_21 ( V_55 , V_30 -> V_19 [ V_55 ] ) ;
}
static void F_33 ( struct V_66 * V_66 )
{
struct V_29 * V_30 = & F_31 ( V_29 ) ;
int V_55 ;
if ( ! V_30 -> V_67 )
return;
V_30 -> V_67 = 0 ;
V_30 -> V_61 = 0 ;
for ( V_55 = 0 ; V_55 < V_23 -> V_35 ; V_55 ++ ) {
T_2 V_5 = V_30 -> V_19 [ V_55 ] ;
V_5 &= ~ ( V_23 -> V_68 | V_23 -> V_69 |
V_23 -> V_70 | V_23 -> V_71 ) ;
V_30 -> V_19 [ V_55 ] = V_5 ;
V_7 -> V_21 ( V_55 , V_30 -> V_19 [ V_55 ] ) ;
}
}
static int F_34 ( struct V_29 * V_30 ,
struct V_38 * V_39 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_30 -> V_56 ; V_55 ++ ) {
if ( V_30 -> V_39 [ V_55 ] == V_39 )
break;
}
F_35 ( V_55 == V_30 -> V_56 ) ;
return V_30 -> V_58 [ V_55 ] ;
}
static void F_36 ( struct V_38 * V_39 , int V_72 )
{
struct V_29 * V_30 = & F_31 ( V_29 ) ;
int V_6 = F_34 ( V_30 , V_39 ) ;
if ( V_72 & V_73 ) {
F_37 ( ! ( V_39 -> V_60 . V_63 & V_74 ) ) ;
F_22 ( V_39 , & V_39 -> V_60 , V_6 ) ;
}
V_39 -> V_60 . V_63 = 0 ;
F_15 ( V_30 , & V_39 -> V_60 , V_6 ) ;
}
static void F_38 ( struct V_38 * V_39 , int V_72 )
{
struct V_29 * V_30 = & F_31 ( V_29 ) ;
int V_6 = F_34 ( V_30 , V_39 ) ;
if ( ! ( V_39 -> V_60 . V_63 & V_64 ) ) {
F_16 ( V_30 , & V_39 -> V_60 , V_6 ) ;
V_39 -> V_60 . V_63 |= V_64 ;
}
if ( ! ( V_39 -> V_60 . V_63 & V_74 ) && ( V_72 & V_75 ) ) {
F_17 ( V_39 , & V_39 -> V_60 , V_6 ) ;
V_39 -> V_60 . V_63 |= V_74 ;
}
}
static void F_39 ( struct V_38 * V_39 , int V_76 )
{
struct V_29 * V_30 = & F_31 ( V_29 ) ;
unsigned long V_72 ;
int V_55 ;
F_40 ( V_72 ) ;
F_41 ( V_39 -> V_66 ) ;
for ( V_55 = 0 ; V_55 < V_30 -> V_56 ; V_55 ++ ) {
if ( V_39 == V_30 -> V_39 [ V_55 ] ) {
F_38 ( V_39 , V_75 ) ;
while ( ++ V_55 < V_30 -> V_56 ) {
V_30 -> V_39 [ V_55 - 1 ] = V_30 -> V_39 [ V_55 ] ;
V_30 -> V_36 [ V_55 - 1 ] = V_30 -> V_36 [ V_55 ] ;
V_30 -> V_58 [ V_55 - 1 ] =
V_30 -> V_58 [ V_55 ] ;
}
F_25 ( V_39 ) ;
V_30 -> V_56 -- ;
break;
}
}
F_42 ( V_39 -> V_66 ) ;
F_43 ( V_72 ) ;
}
static void F_44 ( struct V_38 * V_39 )
{
struct V_29 * V_30 = & F_31 ( V_29 ) ;
int V_6 = F_34 ( V_30 , V_39 ) ;
struct V_31 * V_32 = & V_39 -> V_60 ;
F_17 ( V_39 , V_32 , V_6 ) ;
}
static void F_45 ( void * V_77 )
{
struct V_29 * V_30 = & F_31 ( V_29 ) ;
int V_55 ;
F_46 ( NULL ) ;
for ( V_55 = 0 ; V_55 < V_23 -> V_35 ; V_55 ++ )
V_30 -> V_19 [ V_55 ] = V_7 -> V_20 ( V_55 ) ;
}
static void F_47 ( void )
{
if ( F_48 ( & V_78 ) )
return;
F_49 ( & V_79 ) ;
if ( F_50 ( & V_78 ) == 0 ) {
if ( F_50 ( & V_80 ) > 0 ) {
F_51 ( F_45 , NULL , 1 ) ;
F_35 ( F_50 ( & V_80 ) != 0 ) ;
}
F_52 ( & V_78 ) ;
}
F_53 ( & V_79 ) ;
}
static void F_54 ( void )
{
if ( F_55 ( & V_78 , & V_79 ) ) {
if ( F_50 ( & V_80 ) == 0 )
F_51 ( V_81 , NULL , 1 ) ;
F_53 ( & V_79 ) ;
}
}
static const struct V_1 * F_56 ( T_2 V_82 )
{
unsigned int V_83 , V_84 , V_85 ;
const struct V_1 * V_2 ;
if ( ! V_23 -> V_86 )
return F_57 ( - V_87 ) ;
V_83 = ( V_82 >> 0 ) & 0xff ;
if ( V_83 >= V_88 )
return F_57 ( - V_89 ) ;
V_84 = ( V_82 >> 8 ) & 0xff ;
if ( V_84 >= V_90 )
return F_57 ( - V_89 ) ;
V_85 = ( V_82 >> 16 ) & 0xff ;
if ( V_85 >= V_91 )
return F_57 ( - V_89 ) ;
V_2 = & ( ( * V_23 -> V_86 ) [ V_83 ] [ V_84 ] [ V_85 ] ) ;
if ( V_2 -> V_3 == V_92 )
return F_57 ( - V_87 ) ;
if ( V_2 -> V_3 == V_93 )
return F_57 ( - V_89 ) ;
return V_2 ;
}
static void F_58 ( struct V_38 * V_39 )
{
F_54 () ;
}
static int F_59 ( struct V_38 * * V_94 ,
unsigned long * V_36 , int V_95 )
{
T_1 V_96 = 0 , V_97 = 0 ;
int V_98 = 0 ;
if ( ! V_95 )
return 0 ;
if ( V_95 > V_23 -> V_99 )
return - 1 ;
if ( ! ( V_23 -> V_72 & V_100 ) ) {
int V_55 ;
for ( V_55 = 0 ; V_55 < V_95 ; V_55 ++ )
V_94 [ V_55 ] -> V_60 . V_6 = V_55 ;
return 0 ;
}
V_96 = F_2 ( V_36 [ 0 ] ) ;
if ( V_95 == 1 ) {
if ( V_96 & V_101 )
V_98 = 1 ;
goto V_102;
}
F_35 ( V_95 != 2 ) ;
V_97 = F_2 ( V_36 [ 1 ] ) ;
if ( V_96 == ( V_103 | V_101 ) &&
V_97 == ( V_103 | V_101 ) )
goto V_102;
if ( ( V_96 == V_103 || V_96 == V_101 ) &&
V_97 == ( V_103 | V_101 ) ) {
if ( V_96 & V_101 )
V_98 = 1 ;
goto V_102;
}
if ( ( V_97 == V_103 || V_97 == V_101 ) &&
V_96 == ( V_103 | V_101 ) ) {
if ( V_97 & V_103 )
V_98 = 1 ;
goto V_102;
}
if ( ( V_96 == V_103 && V_97 == V_101 ) ||
( V_96 == V_101 && V_97 == V_103 ) ) {
if ( V_96 & V_101 )
V_98 = 1 ;
goto V_102;
}
return - 1 ;
V_102:
V_94 [ 0 ] -> V_60 . V_6 = V_98 ;
if ( V_95 == 2 )
V_94 [ 1 ] -> V_60 . V_6 = V_98 ^ 1 ;
return 0 ;
}
static int F_60 ( struct V_38 * * V_94 , int V_104 , int V_105 )
{
int V_106 = 0 , V_107 = 0 , V_108 = 0 ;
struct V_38 * V_39 ;
int V_55 , V_109 , V_110 ;
if ( ! ( V_23 -> V_72 & V_111 ) )
return 0 ;
V_109 = V_104 + V_105 ;
if ( V_109 <= 1 )
return 0 ;
V_110 = 1 ;
for ( V_55 = 0 ; V_55 < V_109 ; V_55 ++ ) {
V_39 = V_94 [ V_55 ] ;
if ( V_110 ) {
V_106 = V_39 -> V_112 . V_113 ;
V_107 = V_39 -> V_112 . V_114 ;
V_108 = V_39 -> V_112 . V_115 ;
V_110 = 0 ;
} else if ( V_39 -> V_112 . V_113 != V_106 ||
V_39 -> V_112 . V_114 != V_107 ||
V_39 -> V_112 . V_115 != V_108 ) {
return - V_116 ;
}
}
return 0 ;
}
static int F_61 ( struct V_38 * V_117 , int V_118 ,
struct V_38 * V_94 [] , unsigned long * V_36 ,
int * V_58 )
{
struct V_38 * V_39 ;
int V_109 = 0 ;
if ( ! F_62 ( V_117 ) ) {
if ( V_109 >= V_118 )
return - 1 ;
V_94 [ V_109 ] = V_117 ;
V_36 [ V_109 ] = V_117 -> V_60 . V_119 ;
V_58 [ V_109 ++ ] = V_59 ;
}
F_63 (event, &group->sibling_list, group_entry) {
if ( ! F_62 ( V_39 ) &&
V_39 -> V_63 != V_120 ) {
if ( V_109 >= V_118 )
return - 1 ;
V_94 [ V_109 ] = V_39 ;
V_36 [ V_109 ] = V_39 -> V_60 . V_119 ;
V_58 [ V_109 ++ ] = V_59 ;
}
}
return V_109 ;
}
static int F_64 ( struct V_38 * V_39 , int V_121 )
{
struct V_29 * V_30 = & F_31 ( V_29 ) ;
int V_122 , V_51 = - V_116 ;
unsigned long V_72 ;
F_40 ( V_72 ) ;
F_41 ( V_39 -> V_66 ) ;
V_122 = V_30 -> V_56 ;
if ( V_122 >= V_23 -> V_99 )
goto V_62;
V_30 -> V_39 [ V_122 ] = V_39 ;
V_30 -> V_36 [ V_122 ] = V_39 -> V_60 . V_119 ;
V_30 -> V_58 [ V_122 ] = V_59 ;
V_39 -> V_60 . V_63 = V_74 ;
if ( ! ( V_121 & V_123 ) )
V_39 -> V_60 . V_63 |= V_64 ;
if ( V_30 -> V_124 & V_125 )
goto V_126;
if ( F_60 ( V_30 -> V_39 , V_122 , 1 ) )
goto V_62;
if ( F_59 ( V_30 -> V_39 , V_30 -> V_36 , V_122 + 1 ) )
goto V_62;
V_126:
V_30 -> V_56 ++ ;
V_30 -> V_61 ++ ;
V_51 = 0 ;
V_62:
F_42 ( V_39 -> V_66 ) ;
F_43 ( V_72 ) ;
return V_51 ;
}
static int F_65 ( struct V_38 * V_39 )
{
struct V_127 * V_112 = & V_39 -> V_112 ;
struct V_38 * V_94 [ V_128 ] ;
struct V_31 * V_32 = & V_39 -> V_60 ;
unsigned long V_36 [ V_128 ] ;
int V_129 [ V_128 ] ;
const struct V_1 * V_2 ;
int V_109 ;
if ( F_50 ( & V_80 ) < 0 )
return - V_130 ;
if ( F_66 ( V_39 ) )
return - V_131 ;
switch ( V_112 -> type ) {
case V_132 :
if ( V_112 -> V_82 >= V_23 -> V_133 )
return - V_89 ;
V_2 = V_23 -> V_134 ( V_112 -> V_82 ) ;
break;
case V_135 :
V_2 = F_56 ( V_112 -> V_82 ) ;
if ( F_67 ( V_2 ) )
return F_68 ( V_2 ) ;
break;
case V_136 :
V_2 = NULL ;
break;
default:
return - V_87 ;
}
if ( V_2 ) {
V_32 -> V_119 = F_1 ( V_2 ) ;
} else {
V_32 -> V_119 = V_112 -> V_82 ;
}
V_32 -> V_65 = V_23 -> V_71 ;
if ( ! V_112 -> V_113 )
V_32 -> V_65 |= V_23 -> V_68 ;
if ( ! V_112 -> V_114 )
V_32 -> V_65 |= V_23 -> V_69 ;
if ( ! V_112 -> V_115 )
V_32 -> V_65 |= V_23 -> V_70 ;
V_109 = 0 ;
if ( V_39 -> V_137 != V_39 ) {
V_109 = F_61 ( V_39 -> V_137 ,
V_23 -> V_99 - 1 ,
V_94 , V_36 , V_129 ) ;
if ( V_109 < 0 )
return - V_89 ;
}
V_36 [ V_109 ] = V_32 -> V_119 ;
V_94 [ V_109 ] = V_39 ;
if ( F_60 ( V_94 , V_109 , 1 ) )
return - V_89 ;
if ( F_59 ( V_94 , V_36 , V_109 + 1 ) )
return - V_89 ;
V_32 -> V_6 = V_59 ;
F_47 () ;
V_39 -> V_138 = F_58 ;
if ( ! V_32 -> V_50 ) {
V_32 -> V_50 = V_53 ;
V_32 -> V_52 = V_32 -> V_50 ;
F_24 ( & V_32 -> V_47 , V_32 -> V_50 ) ;
}
return 0 ;
}
static void F_69 ( struct V_66 * V_66 )
{
struct V_29 * V_139 = & F_31 ( V_29 ) ;
F_41 ( V_66 ) ;
V_139 -> V_124 |= V_125 ;
}
static void F_70 ( struct V_66 * V_66 )
{
struct V_29 * V_139 = & F_31 ( V_29 ) ;
V_139 -> V_124 &= ~ V_125 ;
F_42 ( V_66 ) ;
}
static int F_71 ( struct V_66 * V_66 )
{
struct V_29 * V_30 = & F_31 ( V_29 ) ;
int V_109 ;
if ( ! V_23 )
return - V_89 ;
V_30 = & F_31 ( V_29 ) ;
V_109 = V_30 -> V_56 ;
if ( F_60 ( V_30 -> V_39 , 0 , V_109 ) )
return - V_89 ;
if ( F_59 ( V_30 -> V_39 , V_30 -> V_36 , V_109 ) )
return - V_116 ;
V_30 -> V_124 &= ~ V_125 ;
F_42 ( V_66 ) ;
return 0 ;
}
void F_72 ( void )
{
unsigned long V_72 ;
int V_140 , V_55 ;
if ( ! V_23 )
return;
F_40 ( V_72 ) ;
V_140 = F_73 () ;
F_74 ( L_1 ) ;
for ( V_55 = 0 ; V_55 < V_23 -> V_35 ; V_55 ++ )
F_74 ( L_2 ,
V_140 , V_55 , V_7 -> V_20 ( V_55 ) ) ;
for ( V_55 = 0 ; V_55 < V_23 -> V_141 ; V_55 ++ )
F_74 ( L_3 ,
V_140 , V_55 , V_7 -> V_8 ( V_55 ) ) ;
F_43 ( V_72 ) ;
}
static int T_5 F_75 ( struct V_142 * V_143 ,
unsigned long V_144 , void * V_145 )
{
struct V_146 * args = V_145 ;
struct V_147 V_148 ;
struct V_29 * V_30 ;
struct V_149 * V_150 ;
int V_55 ;
if ( ! F_50 ( & V_78 ) )
return V_151 ;
switch ( V_144 ) {
case V_152 :
break;
default:
return V_151 ;
}
V_150 = args -> V_150 ;
V_30 = & F_31 ( V_29 ) ;
if ( V_23 -> V_71 &&
V_23 -> V_35 == 1 )
V_7 -> V_21 ( 0 , V_30 -> V_19 [ 0 ] ) ;
for ( V_55 = 0 ; V_55 < V_30 -> V_56 ; V_55 ++ ) {
struct V_38 * V_39 = V_30 -> V_39 [ V_55 ] ;
int V_6 = V_30 -> V_58 [ V_55 ] ;
struct V_31 * V_32 ;
T_2 V_5 ;
if ( V_23 -> V_71 &&
V_23 -> V_35 > 1 )
V_7 -> V_21 ( V_6 , V_30 -> V_19 [ V_6 ] ) ;
V_32 = & V_39 -> V_60 ;
V_5 = F_17 ( V_39 , V_32 , V_6 ) ;
if ( V_5 & ( 1ULL << 31 ) )
continue;
F_76 ( & V_148 , 0 , V_32 -> V_52 ) ;
if ( ! F_22 ( V_39 , V_32 , V_6 ) )
continue;
if ( F_77 ( V_39 , & V_148 , V_150 ) )
F_38 ( V_39 , 0 ) ;
}
return V_153 ;
}
static bool T_6 F_78 ( void )
{
if ( ! strcmp ( V_154 , L_4 ) ||
! strcmp ( V_154 , L_5 ) ||
! strcmp ( V_154 , L_6 ) ||
! strcmp ( V_154 , L_7 ) ) {
V_23 = & V_155 ;
return true ;
}
if ( ! strcmp ( V_154 , L_8 ) ) {
V_23 = & V_156 ;
return true ;
}
if ( ! strcmp ( V_154 , L_9 ) ||
! strcmp ( V_154 , L_10 ) ) {
V_23 = & V_157 ;
return true ;
}
if ( ! strcmp ( V_154 , L_11 ) ) {
V_23 = & V_158 ;
return true ;
}
return false ;
}
static int T_6 F_79 ( void )
{
F_74 ( L_12 ) ;
if ( ! F_78 () ) {
F_80 ( L_13 , V_154 ) ;
return 0 ;
}
F_80 ( L_14 , V_154 ) ;
F_81 ( & V_66 , L_15 , V_136 ) ;
F_82 ( & V_159 ) ;
return 0 ;
}
void F_83 ( struct V_160 * V_161 ,
struct V_149 * V_150 )
{
unsigned long V_162 , V_163 ;
#ifdef F_84
int V_164 = 0 ;
#endif
F_85 () ;
F_86 ( V_161 , V_150 -> V_165 ) ;
V_162 = V_150 -> V_166 [ V_167 ] ;
V_163 = V_162 + V_168 ;
do {
struct V_169 * V_170 ;
struct V_149 * V_150 ;
unsigned long V_171 ;
if ( ! F_87 ( F_88 () , V_163 ) )
break;
V_170 = (struct V_169 * ) V_163 ;
V_150 = (struct V_149 * ) ( V_170 + 1 ) ;
if ( F_89 ( F_88 () , V_150 ) ) {
if ( F_90 ( V_150 ) )
break;
V_171 = V_150 -> V_165 ;
V_163 = V_150 -> V_166 [ V_167 ] + V_168 ;
} else {
V_171 = V_170 -> V_172 ;
V_163 = ( unsigned long ) V_170 -> V_163 + V_168 ;
}
F_86 ( V_161 , V_171 ) ;
#ifdef F_84
if ( ( V_171 + 8UL ) == ( unsigned long ) & V_173 ) {
int V_174 = V_175 -> V_176 ;
if ( V_175 -> V_177 && V_174 >= V_164 ) {
V_171 = V_175 -> V_177 [ V_174 - V_164 ] . V_51 ;
F_86 ( V_161 , V_171 ) ;
V_164 ++ ;
}
}
#endif
} while ( V_161 -> V_178 < V_179 );
}
static void F_91 ( struct V_160 * V_161 ,
struct V_149 * V_150 )
{
unsigned long V_180 ;
V_180 = V_150 -> V_166 [ V_167 ] + V_168 ;
do {
struct V_169 T_7 * V_181 ;
struct V_169 V_170 ;
unsigned long V_171 ;
V_181 = (struct V_169 T_7 * ) V_180 ;
if ( F_92 ( & V_170 , V_181 , sizeof( V_170 ) ) )
break;
V_171 = V_170 . V_172 ;
V_180 = ( unsigned long ) V_170 . V_163 + V_168 ;
F_86 ( V_161 , V_171 ) ;
} while ( V_161 -> V_178 < V_179 );
}
static void F_93 ( struct V_160 * V_161 ,
struct V_149 * V_150 )
{
unsigned long V_180 ;
V_180 = V_150 -> V_166 [ V_167 ] & 0xffffffffUL ;
do {
unsigned long V_171 ;
if ( F_94 ( V_180 ) ) {
struct V_169 T_7 * V_181 ;
struct V_169 V_170 ;
V_180 += V_168 ;
V_181 = (struct V_169 T_7 * ) V_180 ;
if ( F_92 ( & V_170 , V_181 , sizeof( V_170 ) ) )
break;
V_171 = V_170 . V_172 & 0xffffffff ;
V_180 = ( ( unsigned long ) V_170 . V_163 ) & 0xffffffff ;
} else {
struct V_182 T_7 * V_181 ;
struct V_182 V_170 ;
V_181 = (struct V_182 T_7 * ) V_180 ;
if ( F_92 ( & V_170 , V_181 , sizeof( V_170 ) ) )
break;
V_171 = V_170 . V_172 ;
V_180 = ( unsigned long ) V_170 . V_163 ;
}
F_86 ( V_161 , V_171 ) ;
} while ( V_161 -> V_178 < V_179 );
}
void
F_95 ( struct V_160 * V_161 , struct V_149 * V_150 )
{
F_86 ( V_161 , V_150 -> V_165 ) ;
if ( ! V_175 -> V_183 )
return;
F_96 () ;
if ( F_97 ( V_184 ) )
F_93 ( V_161 , V_150 ) ;
else
F_91 ( V_161 , V_150 ) ;
}
