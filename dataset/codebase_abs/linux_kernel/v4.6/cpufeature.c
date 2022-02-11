static int F_1 ( const void * V_1 , const void * V_2 )
{
return ( int ) ( unsigned long ) V_1 - ( int ) ( ( const struct V_3 * ) V_2 ) -> V_4 ;
}
static struct V_3 * F_2 ( T_1 V_4 )
{
return bsearch ( ( const void * ) ( unsigned long ) V_4 ,
V_5 ,
F_3 ( V_5 ) ,
sizeof( V_5 [ 0 ] ) ,
F_1 ) ;
}
static T_2 F_4 ( struct V_6 * V_7 , T_3 V_8 , T_3 V_9 )
{
T_2 V_10 = F_5 ( V_7 ) ;
V_8 &= ~ V_10 ;
V_8 |= ( V_9 << V_7 -> V_11 ) & V_10 ;
return V_8 ;
}
static T_3 F_6 ( struct V_6 * V_7 , T_3 V_12 , T_3 V_13 )
{
T_3 V_14 = 0 ;
switch ( V_7 -> type ) {
case V_15 :
V_14 = V_7 -> V_16 ;
break;
case V_17 :
V_14 = V_12 < V_13 ? V_12 : V_13 ;
break;
case V_18 :
V_14 = V_12 > V_13 ? V_12 : V_13 ;
break;
default:
F_7 () ;
}
return V_14 ;
}
static int T_4 F_8 ( const void * V_19 , const void * V_20 )
{
return ( ( const struct V_3 * ) V_19 ) -> V_4 -
( ( const struct V_3 * ) V_20 ) -> V_4 ;
}
static void T_4 F_9 ( void * V_19 , void * V_20 , int V_21 )
{
struct V_3 V_22 = * (struct V_3 * ) V_19 ;
* (struct V_3 * ) V_19 = * (struct V_3 * ) V_20 ;
* (struct V_3 * ) V_20 = V_22 ;
}
static void T_4 F_10 ( void )
{
F_11 ( V_5 ,
F_3 ( V_5 ) ,
sizeof( V_5 [ 0 ] ) ,
F_8 ,
F_9 ) ;
}
static void T_4 F_12 ( T_1 V_23 , T_2 V_12 )
{
T_2 V_24 = 0 ;
T_2 V_25 = ~ 0x0ULL ;
struct V_6 * V_7 ;
struct V_3 * V_8 = F_2 ( V_23 ) ;
F_13 ( ! V_8 ) ;
for ( V_7 = V_8 -> V_26 ; V_7 -> V_27 ; V_7 ++ ) {
T_3 V_28 = F_14 ( V_7 , V_12 ) ;
V_24 = F_4 ( V_7 , V_24 , V_28 ) ;
if ( ! V_7 -> V_29 )
V_25 &= ~ F_5 ( V_7 ) ;
}
V_8 -> V_30 = V_24 ;
V_8 -> V_25 = V_25 ;
}
void T_4 F_15 ( struct V_31 * V_32 )
{
F_10 () ;
F_12 ( V_33 , V_32 -> V_34 ) ;
F_12 ( V_35 , V_32 -> V_36 ) ;
F_12 ( V_37 , V_32 -> V_38 ) ;
F_12 ( V_39 , V_32 -> V_40 ) ;
F_12 ( V_41 , V_32 -> V_42 ) ;
F_12 ( V_43 , V_32 -> V_44 ) ;
F_12 ( V_45 , V_32 -> V_46 ) ;
F_12 ( V_47 , V_32 -> V_48 ) ;
F_12 ( V_49 , V_32 -> V_50 ) ;
F_12 ( V_51 , V_32 -> V_52 ) ;
F_12 ( V_53 , V_32 -> V_54 ) ;
F_12 ( V_55 , V_32 -> V_56 ) ;
F_12 ( V_57 , V_32 -> V_58 ) ;
F_12 ( V_59 , V_32 -> V_60 ) ;
F_12 ( V_61 , V_32 -> V_62 ) ;
F_12 ( V_63 , V_32 -> V_64 ) ;
F_12 ( V_65 , V_32 -> V_66 ) ;
F_12 ( V_67 , V_32 -> V_68 ) ;
F_12 ( V_69 , V_32 -> V_70 ) ;
F_12 ( V_71 , V_32 -> V_72 ) ;
F_12 ( V_73 , V_32 -> V_74 ) ;
F_12 ( V_75 , V_32 -> V_76 ) ;
F_12 ( V_77 , V_32 -> V_78 ) ;
F_12 ( V_79 , V_32 -> V_80 ) ;
F_12 ( V_81 , V_32 -> V_82 ) ;
F_12 ( V_83 , V_32 -> V_84 ) ;
F_12 ( V_85 , V_32 -> V_86 ) ;
F_12 ( V_87 , V_32 -> V_88 ) ;
}
static void F_16 ( struct V_3 * V_8 , T_2 V_12 )
{
struct V_6 * V_7 ;
for ( V_7 = V_8 -> V_26 ; V_7 -> V_27 ; V_7 ++ ) {
T_3 V_89 = F_14 ( V_7 , V_8 -> V_30 ) ;
T_3 V_28 = F_14 ( V_7 , V_12 ) ;
if ( V_89 == V_28 )
continue;
V_28 = F_6 ( V_7 , V_28 , V_89 ) ;
V_8 -> V_30 = F_4 ( V_7 , V_8 -> V_30 , V_28 ) ;
}
}
static int F_17 ( T_1 V_4 , int V_90 , T_2 V_24 , T_2 V_91 )
{
struct V_3 * V_2 = F_2 ( V_4 ) ;
F_13 ( ! V_2 ) ;
F_16 ( V_2 , V_24 ) ;
if ( ( V_91 & V_2 -> V_25 ) == ( V_24 & V_2 -> V_25 ) )
return 0 ;
F_18 ( L_1 ,
V_2 -> V_92 , V_91 , V_90 , V_24 ) ;
return 1 ;
}
void F_19 ( int V_90 ,
struct V_31 * V_32 ,
struct V_31 * V_91 )
{
int V_93 = 0 ;
V_93 |= F_17 ( V_33 , V_90 ,
V_32 -> V_34 , V_91 -> V_34 ) ;
V_93 |= F_17 ( V_35 , V_90 ,
V_32 -> V_36 , V_91 -> V_36 ) ;
V_93 |= F_17 ( V_37 , V_90 ,
V_32 -> V_38 , V_91 -> V_38 ) ;
V_93 |= F_17 ( V_39 , V_90 ,
V_32 -> V_40 , V_91 -> V_40 ) ;
V_93 |= F_17 ( V_41 , V_90 ,
V_32 -> V_42 , V_91 -> V_42 ) ;
V_93 |= F_17 ( V_43 , V_90 ,
V_32 -> V_44 , V_91 -> V_44 ) ;
V_93 |= F_17 ( V_45 , V_90 ,
V_32 -> V_46 , V_91 -> V_46 ) ;
V_93 |= F_17 ( V_47 , V_90 ,
V_32 -> V_48 , V_91 -> V_48 ) ;
V_93 |= F_17 ( V_49 , V_90 ,
V_32 -> V_50 , V_91 -> V_50 ) ;
V_93 |= F_17 ( V_51 , V_90 ,
V_32 -> V_52 , V_91 -> V_52 ) ;
V_93 |= F_17 ( V_53 , V_90 ,
V_32 -> V_54 , V_91 -> V_54 ) ;
V_93 |= F_17 ( V_55 , V_90 ,
V_32 -> V_56 , V_91 -> V_56 ) ;
V_93 |= F_17 ( V_57 , V_90 ,
V_32 -> V_58 , V_91 -> V_58 ) ;
V_93 |= F_17 ( V_59 , V_90 ,
V_32 -> V_60 , V_91 -> V_60 ) ;
V_93 |= F_17 ( V_61 , V_90 ,
V_32 -> V_62 , V_91 -> V_62 ) ;
V_93 |= F_17 ( V_63 , V_90 ,
V_32 -> V_64 , V_91 -> V_64 ) ;
V_93 |= F_17 ( V_65 , V_90 ,
V_32 -> V_66 , V_91 -> V_66 ) ;
V_93 |= F_17 ( V_67 , V_90 ,
V_32 -> V_68 , V_91 -> V_68 ) ;
V_93 |= F_17 ( V_69 , V_90 ,
V_32 -> V_70 , V_91 -> V_70 ) ;
V_93 |= F_17 ( V_71 , V_90 ,
V_32 -> V_72 , V_91 -> V_72 ) ;
V_93 |= F_17 ( V_73 , V_90 ,
V_32 -> V_74 , V_91 -> V_74 ) ;
V_93 |= F_17 ( V_75 , V_90 ,
V_32 -> V_76 , V_91 -> V_76 ) ;
V_93 |= F_17 ( V_77 , V_90 ,
V_32 -> V_78 , V_91 -> V_78 ) ;
V_93 |= F_17 ( V_79 , V_90 ,
V_32 -> V_80 , V_91 -> V_80 ) ;
V_93 |= F_17 ( V_81 , V_90 ,
V_32 -> V_82 , V_91 -> V_82 ) ;
V_93 |= F_17 ( V_83 , V_90 ,
V_32 -> V_84 , V_91 -> V_84 ) ;
V_93 |= F_17 ( V_85 , V_90 ,
V_32 -> V_86 , V_91 -> V_86 ) ;
V_93 |= F_17 ( V_87 , V_90 ,
V_32 -> V_88 , V_91 -> V_88 ) ;
F_20 ( V_93 , V_94 ,
L_2 ) ;
}
T_2 F_21 ( T_1 V_1 )
{
struct V_3 * V_2 = F_2 ( V_1 ) ;
F_13 ( ! V_2 ) ;
return V_2 -> V_30 ;
}
static bool
F_22 ( T_2 V_8 , const struct V_95 * V_96 )
{
int V_24 = F_23 ( V_8 , V_96 -> V_97 , V_96 -> V_98 ) ;
return V_24 >= V_96 -> V_99 ;
}
static bool
F_24 ( const struct V_95 * V_96 )
{
T_2 V_24 ;
V_24 = F_21 ( V_96 -> V_23 ) ;
return F_22 ( V_24 , V_96 ) ;
}
static bool F_25 ( const struct V_95 * V_96 )
{
bool V_100 ;
if ( ! F_24 ( V_96 ) )
return false ;
V_100 = F_26 () ;
if ( ! V_100 )
F_27 ( L_3 ,
V_96 -> V_101 ) ;
return V_100 ;
}
static bool F_28 ( const struct V_95 * V_96 )
{
T_1 V_102 = F_29 () ;
T_1 V_103 , V_104 ;
V_103 = 0 ;
V_104 = ( 1 << V_105 ) | V_106 ;
return F_30 ( V_102 , V_107 , V_103 , V_104 ) ;
}
static bool F_31 ( const struct V_95 * V_96 )
{
return F_32 () ;
}
static void T_4 F_33 ( const struct V_95 * V_108 )
{
switch ( V_108 -> V_109 ) {
case V_110 :
V_111 |= V_108 -> V_112 ;
break;
#ifdef F_34
case V_113 :
V_114 |= ( T_1 ) V_108 -> V_112 ;
break;
case V_115 :
V_116 |= ( T_1 ) V_108 -> V_112 ;
break;
#endif
default:
F_35 ( 1 ) ;
break;
}
}
static bool T_5 F_36 ( const struct V_95 * V_108 )
{
bool V_117 ;
switch ( V_108 -> V_109 ) {
case V_110 :
V_117 = ( V_111 & V_108 -> V_112 ) != 0 ;
break;
#ifdef F_34
case V_113 :
V_117 = ( V_114 & ( T_1 ) V_108 -> V_112 ) != 0 ;
break;
case V_115 :
V_117 = ( V_116 & ( T_1 ) V_108 -> V_112 ) != 0 ;
break;
#endif
default:
F_35 ( 1 ) ;
V_117 = false ;
}
return V_117 ;
}
static void T_4 F_37 ( void )
{
int V_118 ;
const struct V_95 * V_119 = V_120 ;
for ( V_118 = 0 ; V_119 [ V_118 ] . V_121 ; V_118 ++ )
if ( V_119 [ V_118 ] . V_121 ( & V_119 [ V_118 ] ) )
F_33 ( & V_119 [ V_118 ] ) ;
}
void F_38 ( const struct V_95 * V_122 ,
const char * V_32 )
{
int V_118 ;
for ( V_118 = 0 ; V_122 [ V_118 ] . V_121 ; V_118 ++ ) {
if ( ! V_122 [ V_118 ] . V_121 ( & V_122 [ V_118 ] ) )
continue;
if ( ! F_39 ( V_122 [ V_118 ] . V_123 ) && V_122 [ V_118 ] . V_101 )
F_40 ( L_4 , V_32 , V_122 [ V_118 ] . V_101 ) ;
F_41 ( V_122 [ V_118 ] . V_123 ) ;
}
}
static void T_4
F_42 ( const struct V_95 * V_122 )
{
int V_118 ;
for ( V_118 = 0 ; V_122 [ V_118 ] . V_121 ; V_118 ++ )
if ( V_122 [ V_118 ] . V_124 && F_39 ( V_122 [ V_118 ] . V_123 ) )
F_43 ( V_122 [ V_118 ] . V_124 , NULL , true ) ;
}
static inline void F_44 ( void )
{
V_125 = true ;
}
static T_2 F_45 ( T_1 V_4 )
{
switch ( V_4 ) {
case V_79 : return F_46 ( V_126 ) ;
case V_81 : return F_46 ( V_127 ) ;
case V_57 : return F_46 ( V_128 ) ;
case V_71 : return F_46 ( V_129 ) ;
case V_73 : return F_46 ( V_130 ) ;
case V_75 : return F_46 ( V_131 ) ;
case V_77 : return F_46 ( V_132 ) ;
case V_59 : return F_46 ( V_133 ) ;
case V_61 : return F_46 ( V_134 ) ;
case V_63 : return F_46 ( V_135 ) ;
case V_65 : return F_46 ( V_136 ) ;
case V_67 : return F_46 ( V_137 ) ;
case V_69 : return F_46 ( V_137 ) ;
case V_83 : return F_46 ( V_138 ) ;
case V_85 : return F_46 ( V_139 ) ;
case V_87 : return F_46 ( V_140 ) ;
case V_53 : return F_46 ( V_141 ) ;
case V_55 : return F_46 ( V_141 ) ;
case V_39 : return F_46 ( V_142 ) ;
case V_41 : return F_46 ( V_142 ) ;
case V_47 : return F_46 ( V_143 ) ;
case V_49 : return F_46 ( V_144 ) ;
case V_51 : return F_46 ( V_145 ) ;
case V_43 : return F_46 ( V_146 ) ;
case V_45 : return F_46 ( V_147 ) ;
case V_37 : return F_46 ( V_148 ) ;
case V_33 : return F_46 ( V_149 ) ;
case V_35 : return F_46 ( V_150 ) ;
default:
F_7 () ;
return 0 ;
}
}
static void F_47 ( void )
{
F_48 () ;
}
void F_49 ( void )
{
int V_118 ;
const struct V_95 * V_122 ;
F_47 () ;
if ( ! V_125 )
return;
V_122 = V_151 ;
for ( V_118 = 0 ; V_122 [ V_118 ] . V_121 ; V_118 ++ ) {
if ( ! F_39 ( V_122 [ V_118 ] . V_123 ) || ! V_122 [ V_118 ] . V_23 )
continue;
if ( ! F_22 ( F_45 ( V_122 [ V_118 ] . V_23 ) , & V_122 [ V_118 ] ) ) {
F_50 ( L_5 ,
F_51 () , V_122 [ V_118 ] . V_101 ) ;
F_52 () ;
}
if ( V_122 [ V_118 ] . V_124 )
V_122 [ V_118 ] . V_124 ( NULL ) ;
}
for ( V_118 = 0 , V_122 = V_120 ; V_122 [ V_118 ] . V_121 ; V_118 ++ ) {
if ( ! F_36 ( & V_122 [ V_118 ] ) )
continue;
if ( ! F_22 ( F_45 ( V_122 [ V_118 ] . V_23 ) , & V_122 [ V_118 ] ) ) {
F_50 ( L_6 ,
F_51 () , V_122 [ V_118 ] . V_101 ) ;
F_52 () ;
}
}
}
static void T_4 F_53 ( void )
{
F_38 ( V_151 , L_7 ) ;
F_42 ( V_151 ) ;
}
void T_4 F_54 ( void )
{
T_1 V_152 ;
int V_153 ;
F_53 () ;
F_37 () ;
F_44 () ;
V_152 = F_55 () ;
V_153 = F_56 () ;
if ( ! V_152 )
F_18 ( L_8 ,
V_153 ) ;
if ( V_154 < V_153 )
F_18 ( L_9 ,
V_154 , V_153 ) ;
}
static bool T_5
F_57 ( const struct V_95 * V_96 )
{
return ( F_39 ( V_155 ) && ! F_39 ( V_156 ) ) ;
}
