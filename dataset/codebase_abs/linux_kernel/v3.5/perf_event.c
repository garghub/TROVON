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
static const struct V_1 * F_4 ( int V_6 )
{
return & V_7 [ V_6 ] ;
}
static const struct V_1 * F_5 ( int V_6 )
{
return & V_8 [ V_6 ] ;
}
static const struct V_1 * F_6 ( int V_6 )
{
return & V_9 [ V_6 ] ;
}
static T_2 F_7 ( T_2 V_6 , int V_10 )
{
if ( V_10 == V_11 )
V_6 <<= V_12 -> V_13 ;
else
V_6 <<= V_12 -> V_14 ;
return V_6 ;
}
static T_2 F_8 ( int V_10 )
{
return F_7 ( V_12 -> V_15 , V_10 ) ;
}
static T_2 F_9 ( int V_10 )
{
return F_7 ( V_10 == V_11 ?
V_12 -> V_16 :
V_12 -> V_17 , V_10 ) ;
}
static inline void F_10 ( struct V_18 * V_19 , struct V_20 * V_21 , int V_10 )
{
T_2 V_5 , V_22 = F_8 ( V_10 ) ;
V_5 = V_19 -> V_23 ;
V_5 &= ~ V_22 ;
V_5 |= V_21 -> V_24 ;
V_19 -> V_23 = V_5 ;
V_25 -> V_26 ( V_19 -> V_23 ) ;
}
static inline void F_11 ( struct V_18 * V_19 , struct V_20 * V_21 , int V_10 )
{
T_2 V_22 = F_8 ( V_10 ) ;
T_2 V_27 = F_9 ( V_10 ) ;
T_2 V_5 ;
V_5 = V_19 -> V_23 ;
V_5 &= ~ V_22 ;
V_5 |= V_27 ;
V_19 -> V_23 = V_5 ;
V_25 -> V_26 ( V_19 -> V_23 ) ;
}
static T_3 F_12 ( int V_10 )
{
T_2 V_5 ;
F_13 ( V_5 ) ;
if ( V_10 == V_11 )
V_5 >>= 32 ;
return V_5 & 0xffffffff ;
}
static void F_14 ( int V_10 , T_2 V_5 )
{
T_2 V_28 , V_22 , V_29 ;
V_28 = 0 ;
if ( V_10 == V_11 )
V_28 = 32 ;
V_22 = ( ( T_2 ) 0xffffffff ) << V_28 ;
V_5 <<= V_28 ;
F_13 ( V_29 ) ;
V_29 &= ~ V_22 ;
V_29 |= V_5 ;
F_15 ( V_29 ) ;
}
static T_2 F_16 ( struct V_30 * V_31 ,
struct V_20 * V_21 , int V_10 )
{
int V_28 = 64 - 32 ;
T_2 V_32 , V_33 ;
T_4 V_34 ;
V_35:
V_32 = F_17 ( & V_21 -> V_36 ) ;
V_33 = F_12 ( V_10 ) ;
if ( F_18 ( & V_21 -> V_36 , V_32 ,
V_33 ) != V_32 )
goto V_35;
V_34 = ( V_33 << V_28 ) - ( V_32 << V_28 ) ;
V_34 >>= V_28 ;
F_19 ( V_34 , & V_31 -> V_37 ) ;
F_20 ( V_34 , & V_21 -> V_38 ) ;
return V_33 ;
}
static int F_21 ( struct V_30 * V_31 ,
struct V_20 * V_21 , int V_10 )
{
T_4 V_39 = F_17 ( & V_21 -> V_38 ) ;
T_4 V_40 = V_21 -> V_41 ;
int V_42 = 0 ;
if ( F_22 ( V_39 <= - V_40 ) ) {
V_39 = V_40 ;
F_23 ( & V_21 -> V_38 , V_39 ) ;
V_21 -> V_43 = V_40 ;
V_42 = 1 ;
}
if ( F_22 ( V_39 <= 0 ) ) {
V_39 += V_40 ;
F_23 ( & V_21 -> V_38 , V_39 ) ;
V_21 -> V_43 = V_40 ;
V_42 = 1 ;
}
if ( V_39 > V_44 )
V_39 = V_44 ;
F_23 ( & V_21 -> V_36 , ( T_2 ) - V_39 ) ;
F_14 ( V_10 , ( T_2 ) ( - V_39 ) & 0xffffffff ) ;
F_24 ( V_31 ) ;
return V_42 ;
}
static T_2 F_25 ( struct V_18 * V_19 , T_2 V_23 )
{
int V_45 ;
if ( ! V_19 -> V_46 )
goto V_47;
for ( V_45 = 0 ; V_45 < V_19 -> V_48 ; V_45 ++ ) {
struct V_30 * V_49 = V_19 -> V_31 [ V_45 ] ;
if ( V_19 -> V_50 [ V_45 ] != V_51 &&
V_19 -> V_50 [ V_45 ] != V_49 -> V_52 . V_10 ) {
F_16 ( V_49 , & V_49 -> V_52 ,
V_19 -> V_50 [ V_45 ] ) ;
V_19 -> V_50 [ V_45 ] = V_51 ;
}
}
for ( V_45 = 0 ; V_45 < V_19 -> V_48 ; V_45 ++ ) {
struct V_30 * V_49 = V_19 -> V_31 [ V_45 ] ;
struct V_20 * V_21 = & V_49 -> V_52 ;
int V_10 = V_21 -> V_10 ;
T_2 V_53 ;
if ( V_19 -> V_50 [ V_45 ] != V_51 )
continue;
F_21 ( V_49 , V_21 , V_10 ) ;
V_19 -> V_50 [ V_45 ] = V_10 ;
V_53 = F_3 ( V_19 -> V_54 [ V_45 ] ) ;
V_23 &= ~ F_8 ( V_10 ) ;
if ( V_21 -> V_55 & V_56 )
V_23 |= F_9 ( V_10 ) ;
else
V_23 |= F_7 ( V_53 , V_10 ) ;
}
V_47:
return V_23 ;
}
static void F_26 ( struct V_57 * V_57 )
{
struct V_18 * V_19 = & F_27 ( V_18 ) ;
T_2 V_23 ;
if ( V_19 -> V_58 )
return;
V_19 -> V_58 = 1 ;
F_28 () ;
V_23 = V_19 -> V_23 ;
if ( ! V_19 -> V_48 ) {
V_23 = 0 ;
} else {
V_23 = F_25 ( V_19 , V_23 ) ;
V_19 -> V_23 = V_23 | V_19 -> V_31 [ 0 ] -> V_52 . V_59 ;
}
V_25 -> V_26 ( V_19 -> V_23 ) ;
}
static void F_29 ( struct V_57 * V_57 )
{
struct V_18 * V_19 = & F_27 ( V_18 ) ;
T_2 V_5 ;
if ( ! V_19 -> V_58 )
return;
V_19 -> V_58 = 0 ;
V_19 -> V_46 = 0 ;
V_5 = V_19 -> V_23 ;
V_5 &= ~ ( V_60 | V_61 |
V_12 -> V_62 | V_12 -> V_63 ) ;
V_19 -> V_23 = V_5 ;
V_25 -> V_26 ( V_19 -> V_23 ) ;
}
static int F_30 ( struct V_18 * V_19 ,
struct V_30 * V_31 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_19 -> V_48 ; V_45 ++ ) {
if ( V_19 -> V_31 [ V_45 ] == V_31 )
break;
}
F_31 ( V_45 == V_19 -> V_48 ) ;
return V_19 -> V_50 [ V_45 ] ;
}
static void F_32 ( struct V_30 * V_31 , int V_64 )
{
struct V_18 * V_19 = & F_27 ( V_18 ) ;
int V_10 = F_30 ( V_19 , V_31 ) ;
if ( V_64 & V_65 ) {
F_33 ( ! ( V_31 -> V_52 . V_55 & V_66 ) ) ;
F_21 ( V_31 , & V_31 -> V_52 , V_10 ) ;
}
V_31 -> V_52 . V_55 = 0 ;
F_10 ( V_19 , & V_31 -> V_52 , V_10 ) ;
}
static void F_34 ( struct V_30 * V_31 , int V_64 )
{
struct V_18 * V_19 = & F_27 ( V_18 ) ;
int V_10 = F_30 ( V_19 , V_31 ) ;
if ( ! ( V_31 -> V_52 . V_55 & V_56 ) ) {
F_11 ( V_19 , & V_31 -> V_52 , V_10 ) ;
V_31 -> V_52 . V_55 |= V_56 ;
}
if ( ! ( V_31 -> V_52 . V_55 & V_66 ) && ( V_64 & V_67 ) ) {
F_16 ( V_31 , & V_31 -> V_52 , V_10 ) ;
V_31 -> V_52 . V_55 |= V_66 ;
}
}
static void F_35 ( struct V_30 * V_31 , int V_68 )
{
struct V_18 * V_19 = & F_27 ( V_18 ) ;
unsigned long V_64 ;
int V_45 ;
F_36 ( V_64 ) ;
F_37 ( V_31 -> V_57 ) ;
for ( V_45 = 0 ; V_45 < V_19 -> V_48 ; V_45 ++ ) {
if ( V_31 == V_19 -> V_31 [ V_45 ] ) {
F_34 ( V_31 , V_67 ) ;
while ( ++ V_45 < V_19 -> V_48 ) {
V_19 -> V_31 [ V_45 - 1 ] = V_19 -> V_31 [ V_45 ] ;
V_19 -> V_54 [ V_45 - 1 ] = V_19 -> V_54 [ V_45 ] ;
V_19 -> V_50 [ V_45 - 1 ] =
V_19 -> V_50 [ V_45 ] ;
}
F_24 ( V_31 ) ;
V_19 -> V_48 -- ;
break;
}
}
F_38 ( V_31 -> V_57 ) ;
F_39 ( V_64 ) ;
}
static void F_40 ( struct V_30 * V_31 )
{
struct V_18 * V_19 = & F_27 ( V_18 ) ;
int V_10 = F_30 ( V_19 , V_31 ) ;
struct V_20 * V_21 = & V_31 -> V_52 ;
F_16 ( V_31 , V_21 , V_10 ) ;
}
static void F_41 ( void * V_69 )
{
struct V_18 * V_19 = & F_27 ( V_18 ) ;
F_42 ( NULL ) ;
V_19 -> V_23 = V_25 -> V_70 () ;
}
void F_43 ( void )
{
if ( F_44 ( & V_71 ) )
return;
F_45 ( & V_72 ) ;
if ( F_46 ( & V_71 ) == 0 ) {
if ( F_46 ( & V_73 ) > 0 ) {
F_47 ( F_41 , NULL , 1 ) ;
F_31 ( F_46 ( & V_73 ) != 0 ) ;
}
F_48 ( & V_71 ) ;
}
F_49 ( & V_72 ) ;
}
void F_50 ( void )
{
if ( F_51 ( & V_71 , & V_72 ) ) {
if ( F_46 ( & V_73 ) == 0 )
F_47 ( V_74 , NULL , 1 ) ;
F_49 ( & V_72 ) ;
}
}
static const struct V_1 * F_52 ( T_2 V_24 )
{
unsigned int V_75 , V_76 , V_77 ;
const struct V_1 * V_2 ;
if ( ! V_12 -> V_78 )
return F_53 ( - V_79 ) ;
V_75 = ( V_24 >> 0 ) & 0xff ;
if ( V_75 >= V_80 )
return F_53 ( - V_81 ) ;
V_76 = ( V_24 >> 8 ) & 0xff ;
if ( V_76 >= V_82 )
return F_53 ( - V_81 ) ;
V_77 = ( V_24 >> 16 ) & 0xff ;
if ( V_77 >= V_83 )
return F_53 ( - V_81 ) ;
V_2 = & ( ( * V_12 -> V_78 ) [ V_75 ] [ V_76 ] [ V_77 ] ) ;
if ( V_2 -> V_3 == V_84 )
return F_53 ( - V_79 ) ;
if ( V_2 -> V_3 == V_85 )
return F_53 ( - V_81 ) ;
return V_2 ;
}
static void F_54 ( struct V_30 * V_31 )
{
F_50 () ;
}
static int F_55 ( struct V_30 * * V_86 ,
unsigned long * V_54 , int V_87 )
{
T_1 V_88 = 0 , V_89 = 0 ;
int V_90 = 0 ;
if ( ! V_87 )
return 0 ;
if ( V_87 > V_91 )
return - 1 ;
V_88 = F_2 ( V_54 [ 0 ] ) ;
if ( V_87 == 1 ) {
if ( V_88 & V_92 )
V_90 = 1 ;
goto V_93;
}
F_31 ( V_87 != 2 ) ;
V_89 = F_2 ( V_54 [ 1 ] ) ;
if ( V_88 == ( V_94 | V_92 ) &&
V_89 == ( V_94 | V_92 ) )
goto V_93;
if ( ( V_88 == V_94 || V_88 == V_92 ) &&
V_89 == ( V_94 | V_92 ) ) {
if ( V_88 & V_92 )
V_90 = 1 ;
goto V_93;
}
if ( ( V_89 == V_94 || V_89 == V_92 ) &&
V_88 == ( V_94 | V_92 ) ) {
if ( V_89 & V_94 )
V_90 = 1 ;
goto V_93;
}
if ( ( V_88 == V_94 && V_89 == V_92 ) ||
( V_88 == V_92 && V_89 == V_94 ) ) {
if ( V_88 & V_92 )
V_90 = 1 ;
goto V_93;
}
return - 1 ;
V_93:
V_86 [ 0 ] -> V_52 . V_10 = V_90 ;
if ( V_87 == 2 )
V_86 [ 1 ] -> V_52 . V_10 = V_90 ^ 1 ;
return 0 ;
}
static int F_56 ( struct V_30 * * V_86 , int V_95 , int V_96 )
{
int V_97 = 0 , V_98 = 0 , V_99 = 0 ;
struct V_30 * V_31 ;
int V_45 , V_100 , V_101 ;
V_100 = V_95 + V_96 ;
if ( V_100 <= 1 )
return 0 ;
V_101 = 1 ;
for ( V_45 = 0 ; V_45 < V_100 ; V_45 ++ ) {
V_31 = V_86 [ V_45 ] ;
if ( V_101 ) {
V_97 = V_31 -> V_102 . V_103 ;
V_98 = V_31 -> V_102 . V_104 ;
V_99 = V_31 -> V_102 . V_105 ;
V_101 = 0 ;
} else if ( V_31 -> V_102 . V_103 != V_97 ||
V_31 -> V_102 . V_104 != V_98 ||
V_31 -> V_102 . V_105 != V_99 ) {
return - V_106 ;
}
}
return 0 ;
}
static int F_57 ( struct V_30 * V_107 , int V_108 ,
struct V_30 * V_86 [] , unsigned long * V_54 ,
int * V_50 )
{
struct V_30 * V_31 ;
int V_100 = 0 ;
if ( ! F_58 ( V_107 ) ) {
if ( V_100 >= V_108 )
return - 1 ;
V_86 [ V_100 ] = V_107 ;
V_54 [ V_100 ] = V_107 -> V_52 . V_109 ;
V_50 [ V_100 ++ ] = V_51 ;
}
F_59 (event, &group->sibling_list, group_entry) {
if ( ! F_58 ( V_31 ) &&
V_31 -> V_55 != V_110 ) {
if ( V_100 >= V_108 )
return - 1 ;
V_86 [ V_100 ] = V_31 ;
V_54 [ V_100 ] = V_31 -> V_52 . V_109 ;
V_50 [ V_100 ++ ] = V_51 ;
}
}
return V_100 ;
}
static int F_60 ( struct V_30 * V_31 , int V_111 )
{
struct V_18 * V_19 = & F_27 ( V_18 ) ;
int V_112 , V_42 = - V_106 ;
unsigned long V_64 ;
F_36 ( V_64 ) ;
F_37 ( V_31 -> V_57 ) ;
V_112 = V_19 -> V_48 ;
if ( V_112 >= V_91 )
goto V_47;
V_19 -> V_31 [ V_112 ] = V_31 ;
V_19 -> V_54 [ V_112 ] = V_31 -> V_52 . V_109 ;
V_19 -> V_50 [ V_112 ] = V_51 ;
V_31 -> V_52 . V_55 = V_66 ;
if ( ! ( V_111 & V_113 ) )
V_31 -> V_52 . V_55 |= V_56 ;
if ( V_19 -> V_114 & V_115 )
goto V_116;
if ( F_56 ( V_19 -> V_31 , V_112 , 1 ) )
goto V_47;
if ( F_55 ( V_19 -> V_31 , V_19 -> V_54 , V_112 + 1 ) )
goto V_47;
V_116:
V_19 -> V_48 ++ ;
V_19 -> V_46 ++ ;
V_42 = 0 ;
V_47:
F_38 ( V_31 -> V_57 ) ;
F_39 ( V_64 ) ;
return V_42 ;
}
static int F_61 ( struct V_30 * V_31 )
{
struct V_117 * V_102 = & V_31 -> V_102 ;
struct V_30 * V_86 [ V_91 ] ;
struct V_20 * V_21 = & V_31 -> V_52 ;
unsigned long V_54 [ V_91 ] ;
int V_118 [ V_91 ] ;
const struct V_1 * V_2 ;
int V_100 ;
if ( F_46 ( & V_73 ) < 0 )
return - V_119 ;
if ( F_62 ( V_31 ) )
return - V_120 ;
switch ( V_102 -> type ) {
case V_121 :
if ( V_102 -> V_24 >= V_12 -> V_122 )
return - V_81 ;
V_2 = V_12 -> V_123 ( V_102 -> V_24 ) ;
break;
case V_124 :
V_2 = F_52 ( V_102 -> V_24 ) ;
if ( F_63 ( V_2 ) )
return F_64 ( V_2 ) ;
break;
case V_125 :
V_2 = NULL ;
break;
default:
return - V_79 ;
}
if ( V_2 ) {
V_21 -> V_109 = F_1 ( V_2 ) ;
} else {
V_21 -> V_109 = V_102 -> V_24 ;
}
V_21 -> V_59 = V_12 -> V_63 ;
if ( ! V_102 -> V_103 )
V_21 -> V_59 |= V_60 ;
if ( ! V_102 -> V_104 )
V_21 -> V_59 |= V_61 ;
if ( ! V_102 -> V_105 )
V_21 -> V_59 |= V_12 -> V_62 ;
V_100 = 0 ;
if ( V_31 -> V_126 != V_31 ) {
V_100 = F_57 ( V_31 -> V_126 ,
V_91 - 1 ,
V_86 , V_54 , V_118 ) ;
if ( V_100 < 0 )
return - V_81 ;
}
V_54 [ V_100 ] = V_21 -> V_109 ;
V_86 [ V_100 ] = V_31 ;
if ( F_56 ( V_86 , V_100 , 1 ) )
return - V_81 ;
if ( F_55 ( V_86 , V_54 , V_100 + 1 ) )
return - V_81 ;
V_21 -> V_10 = V_51 ;
F_43 () ;
V_31 -> V_127 = F_54 ;
if ( ! V_21 -> V_41 ) {
V_21 -> V_41 = V_44 ;
V_21 -> V_43 = V_21 -> V_41 ;
F_23 ( & V_21 -> V_38 , V_21 -> V_41 ) ;
}
return 0 ;
}
static void F_65 ( struct V_57 * V_57 )
{
struct V_18 * V_128 = & F_27 ( V_18 ) ;
F_37 ( V_57 ) ;
V_128 -> V_114 |= V_115 ;
}
static void F_66 ( struct V_57 * V_57 )
{
struct V_18 * V_128 = & F_27 ( V_18 ) ;
V_128 -> V_114 &= ~ V_115 ;
F_38 ( V_57 ) ;
}
static int F_67 ( struct V_57 * V_57 )
{
struct V_18 * V_19 = & F_27 ( V_18 ) ;
int V_100 ;
if ( ! V_12 )
return - V_81 ;
V_19 = & F_27 ( V_18 ) ;
V_100 = V_19 -> V_48 ;
if ( F_56 ( V_19 -> V_31 , 0 , V_100 ) )
return - V_81 ;
if ( F_55 ( V_19 -> V_31 , V_19 -> V_54 , V_100 ) )
return - V_106 ;
V_19 -> V_114 &= ~ V_115 ;
F_38 ( V_57 ) ;
return 0 ;
}
void F_68 ( void )
{
unsigned long V_64 ;
T_2 V_23 , V_29 ;
int V_129 ;
if ( ! V_12 )
return;
F_36 ( V_64 ) ;
V_129 = F_69 () ;
V_23 = V_25 -> V_70 () ;
F_13 ( V_29 ) ;
F_70 ( L_1 ) ;
F_70 ( L_2 ,
V_129 , V_23 , V_29 ) ;
F_39 ( V_64 ) ;
}
static int T_5 F_71 ( struct V_130 * V_131 ,
unsigned long V_132 , void * V_133 )
{
struct V_134 * args = V_133 ;
struct V_135 V_136 ;
struct V_18 * V_19 ;
struct V_137 * V_138 ;
int V_45 ;
if ( ! F_46 ( & V_71 ) )
return V_139 ;
switch ( V_132 ) {
case V_140 :
break;
default:
return V_139 ;
}
V_138 = args -> V_138 ;
V_19 = & F_27 ( V_18 ) ;
if ( V_12 -> V_63 )
V_25 -> V_26 ( V_19 -> V_23 ) ;
for ( V_45 = 0 ; V_45 < V_19 -> V_48 ; V_45 ++ ) {
struct V_30 * V_31 = V_19 -> V_31 [ V_45 ] ;
int V_10 = V_19 -> V_50 [ V_45 ] ;
struct V_20 * V_21 ;
T_2 V_5 ;
V_21 = & V_31 -> V_52 ;
V_5 = F_16 ( V_31 , V_21 , V_10 ) ;
if ( V_5 & ( 1ULL << 31 ) )
continue;
F_72 ( & V_136 , 0 , V_21 -> V_43 ) ;
if ( ! F_21 ( V_31 , V_21 , V_10 ) )
continue;
if ( F_73 ( V_31 , & V_136 , V_138 ) )
F_34 ( V_31 , 0 ) ;
}
return V_141 ;
}
static bool T_6 F_74 ( void )
{
if ( ! strcmp ( V_142 , L_3 ) ||
! strcmp ( V_142 , L_4 ) ||
! strcmp ( V_142 , L_5 ) ||
! strcmp ( V_142 , L_6 ) ) {
V_12 = & V_143 ;
return true ;
}
if ( ! strcmp ( V_142 , L_7 ) ) {
V_12 = & V_144 ;
return true ;
}
if ( ! strcmp ( V_142 , L_8 ) ||
! strcmp ( V_142 , L_9 ) ) {
V_12 = & V_145 ;
return true ;
}
return false ;
}
int T_6 F_75 ( void )
{
F_70 ( L_10 ) ;
if ( ! F_74 () ) {
F_76 ( L_11 , V_142 ) ;
return 0 ;
}
F_76 ( L_12 , V_142 ) ;
F_77 ( & V_57 , L_13 , V_125 ) ;
F_78 ( & V_146 ) ;
return 0 ;
}
void F_79 ( struct V_147 * V_148 ,
struct V_137 * V_138 )
{
unsigned long V_149 , V_150 ;
#ifdef F_80
int V_151 = 0 ;
#endif
F_81 () ;
F_82 ( V_148 , V_138 -> V_152 ) ;
V_149 = V_138 -> V_153 [ V_154 ] ;
V_150 = V_149 + V_155 ;
do {
struct V_156 * V_157 ;
struct V_137 * V_138 ;
unsigned long V_158 ;
if ( ! F_83 ( F_84 () , V_150 ) )
break;
V_157 = (struct V_156 * ) V_150 ;
V_138 = (struct V_137 * ) ( V_157 + 1 ) ;
if ( F_85 ( F_84 () , V_138 ) ) {
if ( F_86 ( V_138 ) )
break;
V_158 = V_138 -> V_152 ;
V_150 = V_138 -> V_153 [ V_154 ] + V_155 ;
} else {
V_158 = V_157 -> V_159 ;
V_150 = ( unsigned long ) V_157 -> V_150 + V_155 ;
}
F_82 ( V_148 , V_158 ) ;
#ifdef F_80
if ( ( V_158 + 8UL ) == ( unsigned long ) & V_160 ) {
int V_161 = V_162 -> V_163 ;
if ( V_162 -> V_164 && V_161 >= V_151 ) {
V_158 = V_162 -> V_164 [ V_161 - V_151 ] . V_42 ;
F_82 ( V_148 , V_158 ) ;
V_151 ++ ;
}
}
#endif
} while ( V_148 -> V_165 < V_166 );
}
static void F_87 ( struct V_147 * V_148 ,
struct V_137 * V_138 )
{
unsigned long V_167 ;
F_82 ( V_148 , V_138 -> V_152 ) ;
V_167 = V_138 -> V_153 [ V_154 ] + V_155 ;
do {
struct V_156 * V_168 , V_157 ;
unsigned long V_158 ;
V_168 = (struct V_156 * ) V_167 ;
if ( F_88 ( & V_157 , V_168 , sizeof( V_157 ) ) )
break;
V_158 = V_157 . V_159 ;
V_167 = ( unsigned long ) V_157 . V_150 + V_155 ;
F_82 ( V_148 , V_158 ) ;
} while ( V_148 -> V_165 < V_166 );
}
static void F_89 ( struct V_147 * V_148 ,
struct V_137 * V_138 )
{
unsigned long V_167 ;
F_82 ( V_148 , V_138 -> V_152 ) ;
V_167 = V_138 -> V_153 [ V_154 ] & 0xffffffffUL ;
do {
struct V_169 * V_168 , V_157 ;
unsigned long V_158 ;
V_168 = (struct V_169 * ) V_167 ;
if ( F_88 ( & V_157 , V_168 , sizeof( V_157 ) ) )
break;
V_158 = V_157 . V_159 ;
V_167 = ( unsigned long ) V_157 . V_150 ;
F_82 ( V_148 , V_158 ) ;
} while ( V_148 -> V_165 < V_166 );
}
void
F_90 ( struct V_147 * V_148 , struct V_137 * V_138 )
{
F_91 () ;
if ( F_92 ( V_170 ) )
F_89 ( V_148 , V_138 ) ;
else
F_87 ( V_148 , V_138 ) ;
}
