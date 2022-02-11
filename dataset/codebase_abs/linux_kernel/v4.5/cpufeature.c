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
}
static void F_16 ( struct V_3 * V_8 , T_2 V_12 )
{
struct V_6 * V_7 ;
for ( V_7 = V_8 -> V_26 ; V_7 -> V_27 ; V_7 ++ ) {
T_3 V_87 = F_14 ( V_7 , V_8 -> V_30 ) ;
T_3 V_28 = F_14 ( V_7 , V_12 ) ;
if ( V_87 == V_28 )
continue;
V_28 = F_6 ( V_7 , V_28 , V_87 ) ;
V_8 -> V_30 = F_4 ( V_7 , V_8 -> V_30 , V_28 ) ;
}
}
static int F_17 ( T_1 V_4 , int V_88 , T_2 V_24 , T_2 V_89 )
{
struct V_3 * V_2 = F_2 ( V_4 ) ;
F_13 ( ! V_2 ) ;
F_16 ( V_2 , V_24 ) ;
if ( ( V_89 & V_2 -> V_25 ) == ( V_24 & V_2 -> V_25 ) )
return 0 ;
F_18 ( L_1 ,
V_2 -> V_90 , V_89 , V_88 , V_24 ) ;
return 1 ;
}
void F_19 ( int V_88 ,
struct V_31 * V_32 ,
struct V_31 * V_89 )
{
int V_91 = 0 ;
V_91 |= F_17 ( V_33 , V_88 ,
V_32 -> V_34 , V_89 -> V_34 ) ;
V_91 |= F_17 ( V_35 , V_88 ,
V_32 -> V_36 , V_89 -> V_36 ) ;
V_91 |= F_17 ( V_37 , V_88 ,
V_32 -> V_38 , V_89 -> V_38 ) ;
V_91 |= F_17 ( V_39 , V_88 ,
V_32 -> V_40 , V_89 -> V_40 ) ;
V_91 |= F_17 ( V_41 , V_88 ,
V_32 -> V_42 , V_89 -> V_42 ) ;
V_91 |= F_17 ( V_43 , V_88 ,
V_32 -> V_44 , V_89 -> V_44 ) ;
V_91 |= F_17 ( V_45 , V_88 ,
V_32 -> V_46 , V_89 -> V_46 ) ;
V_91 |= F_17 ( V_47 , V_88 ,
V_32 -> V_48 , V_89 -> V_48 ) ;
V_91 |= F_17 ( V_49 , V_88 ,
V_32 -> V_50 , V_89 -> V_50 ) ;
V_91 |= F_17 ( V_51 , V_88 ,
V_32 -> V_52 , V_89 -> V_52 ) ;
V_91 |= F_17 ( V_53 , V_88 ,
V_32 -> V_54 , V_89 -> V_54 ) ;
V_91 |= F_17 ( V_55 , V_88 ,
V_32 -> V_56 , V_89 -> V_56 ) ;
V_91 |= F_17 ( V_57 , V_88 ,
V_32 -> V_58 , V_89 -> V_58 ) ;
V_91 |= F_17 ( V_59 , V_88 ,
V_32 -> V_60 , V_89 -> V_60 ) ;
V_91 |= F_17 ( V_61 , V_88 ,
V_32 -> V_62 , V_89 -> V_62 ) ;
V_91 |= F_17 ( V_63 , V_88 ,
V_32 -> V_64 , V_89 -> V_64 ) ;
V_91 |= F_17 ( V_65 , V_88 ,
V_32 -> V_66 , V_89 -> V_66 ) ;
V_91 |= F_17 ( V_67 , V_88 ,
V_32 -> V_68 , V_89 -> V_68 ) ;
V_91 |= F_17 ( V_69 , V_88 ,
V_32 -> V_70 , V_89 -> V_70 ) ;
V_91 |= F_17 ( V_71 , V_88 ,
V_32 -> V_72 , V_89 -> V_72 ) ;
V_91 |= F_17 ( V_73 , V_88 ,
V_32 -> V_74 , V_89 -> V_74 ) ;
V_91 |= F_17 ( V_75 , V_88 ,
V_32 -> V_76 , V_89 -> V_76 ) ;
V_91 |= F_17 ( V_77 , V_88 ,
V_32 -> V_78 , V_89 -> V_78 ) ;
V_91 |= F_17 ( V_79 , V_88 ,
V_32 -> V_80 , V_89 -> V_80 ) ;
V_91 |= F_17 ( V_81 , V_88 ,
V_32 -> V_82 , V_89 -> V_82 ) ;
V_91 |= F_17 ( V_83 , V_88 ,
V_32 -> V_84 , V_89 -> V_84 ) ;
V_91 |= F_17 ( V_85 , V_88 ,
V_32 -> V_86 , V_89 -> V_86 ) ;
F_20 ( V_91 , V_92 ,
L_2 ) ;
}
T_2 F_21 ( T_1 V_1 )
{
struct V_3 * V_2 = F_2 ( V_1 ) ;
F_13 ( ! V_2 ) ;
return V_2 -> V_30 ;
}
static bool
F_22 ( T_2 V_8 , const struct V_93 * V_94 )
{
int V_24 = F_23 ( V_8 , V_94 -> V_95 ) ;
return V_24 >= V_94 -> V_96 ;
}
static bool
F_24 ( const struct V_93 * V_94 )
{
T_2 V_24 ;
V_24 = F_21 ( V_94 -> V_23 ) ;
return F_22 ( V_24 , V_94 ) ;
}
static bool F_25 ( const struct V_93 * V_94 )
{
bool V_97 ;
if ( ! F_24 ( V_94 ) )
return false ;
V_97 = F_26 () ;
if ( ! V_97 )
F_27 ( L_3 ,
V_94 -> V_98 ) ;
return V_97 ;
}
static void T_4 F_28 ( const struct V_93 * V_99 )
{
switch ( V_99 -> V_100 ) {
case V_101 :
V_102 |= V_99 -> V_103 ;
break;
#ifdef F_29
case V_104 :
V_105 |= ( T_1 ) V_99 -> V_103 ;
break;
case V_106 :
V_107 |= ( T_1 ) V_99 -> V_103 ;
break;
#endif
default:
F_30 ( 1 ) ;
break;
}
}
static bool T_5 F_31 ( const struct V_93 * V_99 )
{
bool V_108 ;
switch ( V_99 -> V_100 ) {
case V_101 :
V_108 = ( V_102 & V_99 -> V_103 ) != 0 ;
break;
#ifdef F_29
case V_104 :
V_108 = ( V_105 & ( T_1 ) V_99 -> V_103 ) != 0 ;
break;
case V_106 :
V_108 = ( V_107 & ( T_1 ) V_99 -> V_103 ) != 0 ;
break;
#endif
default:
F_30 ( 1 ) ;
V_108 = false ;
}
return V_108 ;
}
static void T_4 F_32 ( void )
{
int V_109 ;
const struct V_93 * V_110 = V_111 ;
for ( V_109 = 0 ; V_110 [ V_109 ] . V_98 ; V_109 ++ )
if ( V_110 [ V_109 ] . F_33 ( & V_110 [ V_109 ] ) )
F_28 ( & V_110 [ V_109 ] ) ;
}
void F_34 ( const struct V_93 * V_112 ,
const char * V_32 )
{
int V_109 ;
for ( V_109 = 0 ; V_112 [ V_109 ] . V_98 ; V_109 ++ ) {
if ( ! V_112 [ V_109 ] . F_33 ( & V_112 [ V_109 ] ) )
continue;
if ( ! F_35 ( V_112 [ V_109 ] . V_113 ) )
F_36 ( L_4 , V_32 , V_112 [ V_109 ] . V_98 ) ;
F_37 ( V_112 [ V_109 ] . V_113 ) ;
}
}
static void T_4
F_38 ( const struct V_93 * V_112 )
{
int V_109 ;
for ( V_109 = 0 ; V_112 [ V_109 ] . V_98 ; V_109 ++ )
if ( V_112 [ V_109 ] . V_114 && F_35 ( V_112 [ V_109 ] . V_113 ) )
F_39 ( V_112 [ V_109 ] . V_114 , NULL , true ) ;
}
static inline void F_40 ( void )
{
V_115 = true ;
}
static T_2 F_41 ( T_1 V_4 )
{
switch ( V_4 ) {
case V_77 : return ( T_2 ) F_42 ( V_116 ) ;
case V_79 : return ( T_2 ) F_42 ( V_117 ) ;
case V_55 : return ( T_2 ) F_42 ( V_118 ) ;
case V_69 : return ( T_2 ) F_42 ( V_119 ) ;
case V_71 : return ( T_2 ) F_42 ( V_120 ) ;
case V_73 : return ( T_2 ) F_42 ( V_121 ) ;
case V_75 : return ( T_2 ) F_42 ( V_122 ) ;
case V_57 : return ( T_2 ) F_42 ( V_123 ) ;
case V_59 : return ( T_2 ) F_42 ( V_124 ) ;
case V_61 : return ( T_2 ) F_42 ( V_125 ) ;
case V_63 : return ( T_2 ) F_42 ( V_126 ) ;
case V_65 : return ( T_2 ) F_42 ( V_127 ) ;
case V_67 : return ( T_2 ) F_42 ( V_127 ) ;
case V_81 : return ( T_2 ) F_42 ( V_128 ) ;
case V_83 : return ( T_2 ) F_42 ( V_129 ) ;
case V_85 : return ( T_2 ) F_42 ( V_130 ) ;
case V_51 : return ( T_2 ) F_42 ( V_131 ) ;
case V_53 : return ( T_2 ) F_42 ( V_131 ) ;
case V_39 : return ( T_2 ) F_42 ( V_132 ) ;
case V_41 : return ( T_2 ) F_42 ( V_132 ) ;
case V_47 : return ( T_2 ) F_42 ( V_133 ) ;
case V_49 : return ( T_2 ) F_42 ( V_134 ) ;
case V_43 : return ( T_2 ) F_42 ( V_135 ) ;
case V_45 : return ( T_2 ) F_42 ( V_136 ) ;
case V_37 : return ( T_2 ) F_42 ( V_137 ) ;
case V_33 : return ( T_2 ) F_42 ( V_138 ) ;
case V_35 : return ( T_2 ) F_42 ( V_139 ) ;
default:
F_7 () ;
return 0 ;
}
}
static void F_43 ( char * V_140 ,
const struct V_93 * V_99 )
{
int V_88 = F_44 () ;
F_45 ( L_5 , V_88 , V_140 , V_99 -> V_98 ) ;
F_46 ( V_88 , 0 ) ;
if ( V_141 [ V_88 ] && V_141 [ V_88 ] -> V_142 )
V_141 [ V_88 ] -> V_142 ( V_88 ) ;
asm(
"1: wfe\n"
" wfi\n"
" b 1b");
}
void F_47 ( void )
{
int V_109 ;
const struct V_93 * V_112 ;
if ( ! V_115 )
return;
V_112 = V_143 ;
for ( V_109 = 0 ; V_112 [ V_109 ] . V_98 ; V_109 ++ ) {
if ( ! F_35 ( V_112 [ V_109 ] . V_113 ) || ! V_112 [ V_109 ] . V_23 )
continue;
if ( ! F_22 ( F_41 ( V_112 [ V_109 ] . V_23 ) , & V_112 [ V_109 ] ) )
F_43 ( L_6 , & V_112 [ V_109 ] ) ;
if ( V_112 [ V_109 ] . V_114 )
V_112 [ V_109 ] . V_114 ( NULL ) ;
}
for ( V_109 = 0 , V_112 = V_111 ; V_112 [ V_109 ] . V_98 ; V_109 ++ ) {
if ( ! F_31 ( & V_112 [ V_109 ] ) )
continue;
if ( ! F_22 ( F_41 ( V_112 [ V_109 ] . V_23 ) , & V_112 [ V_109 ] ) )
F_43 ( L_7 , & V_112 [ V_109 ] ) ;
}
}
static inline void F_40 ( void )
{
}
static void T_4 F_48 ( void )
{
F_34 ( V_143 , L_8 ) ;
F_38 ( V_143 ) ;
}
void T_4 F_49 ( void )
{
T_1 V_144 ;
int V_145 ;
F_48 () ;
F_32 () ;
F_40 () ;
V_144 = F_50 () ;
V_145 = F_51 () ;
if ( ! V_144 )
F_18 ( L_9 ,
V_145 ) ;
if ( V_146 < V_145 )
F_18 ( L_10 ,
V_146 , V_145 ) ;
}
