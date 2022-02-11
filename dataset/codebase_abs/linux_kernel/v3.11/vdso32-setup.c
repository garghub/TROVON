static int T_1 F_1 ( char * V_1 )
{
V_2 = F_2 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static T_1 void F_3 ( T_2 * V_3 ,
unsigned V_4 , unsigned V_5 )
{
T_3 * V_6 = ( void * ) V_3 + V_4 ;
unsigned V_7 = V_5 / sizeof( * V_6 ) ;
unsigned V_8 ;
for( V_8 = 0 ; V_8 < V_7 ; V_8 ++ , V_6 ++ ) {
if ( V_6 -> V_9 == V_10 ||
V_6 -> V_9 == V_11 )
continue;
if ( V_6 -> V_9 > V_12 ) {
F_4 ( V_13 L_1 ,
V_6 -> V_9 ) ;
continue;
}
switch( F_5 ( V_6 -> V_14 ) ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
V_6 -> V_19 += V_20 ;
}
}
}
static T_1 void F_6 ( T_2 * V_3 , unsigned V_4 )
{
T_4 * V_21 = ( void * ) V_3 + V_4 ;
for(; V_21 -> V_22 != V_23 ; V_21 ++ )
switch( V_21 -> V_22 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 ... V_38 :
V_21 -> V_39 . V_40 += V_20 ;
break;
case V_41 ... V_42 - 1 :
case V_43 ... V_44 - 1 :
if ( V_21 -> V_22 >= V_41 &&
( V_21 -> V_22 & 1 ) == 0 )
V_21 -> V_39 . V_40 += V_20 ;
break;
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 ... V_51 :
break;
case V_42 ... V_43 - 1 :
case V_44 ... V_50 - 1 :
default:
if ( V_21 -> V_22 > V_41 )
F_4 ( V_13 L_2 ,
V_21 -> V_22 ) ;
break;
}
}
static T_1 void F_7 ( T_2 * V_3 )
{
T_5 * V_52 ;
T_6 * V_53 ;
int V_8 ;
F_8 ( memcmp ( V_3 -> V_54 , V_55 , V_56 ) != 0 ||
! F_9 ( V_3 ) ||
V_3 -> V_57 != V_58 ) ;
V_3 -> V_59 += V_20 ;
V_52 = ( void * ) V_3 + V_3 -> V_60 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_61 ; V_8 ++ ) {
V_52 [ V_8 ] . V_62 += V_20 ;
if ( V_52 [ V_8 ] . V_63 == V_64 )
F_6 ( V_3 , V_52 [ V_8 ] . V_65 ) ;
}
V_53 = ( void * ) V_3 + V_3 -> V_66 ;
for( V_8 = 0 ; V_8 < V_3 -> V_67 ; V_8 ++ ) {
if ( ! ( V_53 [ V_8 ] . V_68 & V_69 ) )
continue;
V_53 [ V_8 ] . V_70 += V_20 ;
if ( V_53 [ V_8 ] . V_71 == V_72 ||
V_53 [ V_8 ] . V_71 == V_73 )
F_3 ( V_3 , V_53 [ V_8 ] . V_74 ,
V_53 [ V_8 ] . V_75 ) ;
}
}
void F_10 ( void )
{
F_11 ( V_76 , ( V_77 ) V_78 ) ;
F_11 ( V_79 , 0ULL ) ;
F_11 ( V_80 , ( V_77 ) V_81 ) ;
F_12 ( V_82 , V_83 ) ;
}
static inline void F_13 ( int V_84 )
{
}
void F_14 ( void )
{
int V_85 = F_15 () ;
struct V_86 * V_87 = & F_16 ( V_88 , V_85 ) ;
if ( ! F_17 ( V_89 ) ) {
F_18 () ;
return;
}
V_87 -> V_90 . V_91 = V_78 ;
V_87 -> V_90 . V_92 = sizeof( struct V_86 ) + ( unsigned long ) V_87 ;
F_19 ( V_76 , V_78 , 0 ) ;
F_19 ( V_79 , V_87 -> V_90 . V_92 , 0 ) ;
F_19 ( V_80 , ( unsigned long ) V_81 , 0 ) ;
F_18 () ;
}
static int T_1 F_20 ( void )
{
V_93 . V_94 = NULL ;
V_93 . V_95 = V_96 ;
V_93 . V_97 = V_98 ;
V_93 . V_99 = V_100 | V_101 | V_102 | V_103 ;
V_93 . V_104 = V_105 ;
return 0 ;
}
static void F_13 ( int V_84 )
{
static int V_106 ;
if ( V_84 == V_106 )
return;
V_106 = V_84 ;
F_21 ( V_107 , F_22 ( V_108 [ 0 ] ) << V_109 ,
V_84 ? V_110 : V_111 ) ;
F_23 () ;
}
int T_1 F_24 ( void )
{
void * V_112 = ( void * ) F_25 ( V_113 ) ;
const void * V_114 ;
T_7 V_115 ;
V_108 [ 0 ] = F_26 ( V_112 ) ;
#ifdef F_27
F_20 () ;
#endif
if ( F_28 () ) {
V_114 = & V_116 ;
V_115 = & V_117 - & V_116 ;
} else if ( F_29 () ) {
V_114 = & V_118 ;
V_115 = & V_119 - & V_118 ;
} else {
V_114 = & V_120 ;
V_115 = & V_121 - & V_120 ;
}
memcpy ( V_112 , V_114 , V_115 ) ;
F_7 ( V_112 ) ;
return 0 ;
}
int F_30 ( struct V_122 * V_123 , int V_124 )
{
struct V_125 * V_126 = V_127 -> V_126 ;
unsigned long V_128 ;
int V_129 = 0 ;
bool V_130 ;
#ifdef F_31
if ( F_32 ( V_131 ) )
return F_33 ( V_123 , V_124 ) ;
#endif
if ( V_2 == V_132 )
return 0 ;
F_34 ( & V_126 -> V_133 ) ;
V_130 = ( V_2 == V_134 ) ;
F_13 ( V_130 ) ;
if ( V_130 )
V_128 = V_135 ;
else {
V_128 = F_35 ( NULL , 0 , V_136 , 0 , 0 ) ;
if ( F_36 ( V_128 ) ) {
V_129 = V_128 ;
goto V_137;
}
}
V_127 -> V_126 -> V_138 . V_139 = ( void * ) V_128 ;
if ( V_140 || ! V_130 ) {
V_129 = F_37 ( V_126 , V_128 , V_136 ,
V_100 | V_102 |
V_101 | V_141 | V_103 ,
V_108 ) ;
if ( V_129 )
goto V_137;
}
F_38 () -> V_142 =
F_39 ( V_128 , V_143 ) ;
V_137:
if ( V_129 )
V_127 -> V_126 -> V_138 . V_139 = NULL ;
F_40 ( & V_126 -> V_133 ) ;
return V_129 ;
}
static T_1 int F_41 ( void )
{
F_42 ( V_144 ) ;
return 0 ;
}
const char * F_43 ( struct V_145 * V_146 )
{
if ( V_146 -> V_94 && V_146 -> V_95 == ( long ) V_146 -> V_94 -> V_138 . V_139 )
return L_3 ;
return NULL ;
}
struct V_145 * F_44 ( struct V_125 * V_126 )
{
if ( V_126 && V_126 -> V_138 . V_139 == ( void * ) V_135 )
return & V_93 ;
return NULL ;
}
int F_45 ( struct V_125 * V_126 , unsigned long V_128 )
{
const struct V_145 * V_146 = F_44 ( V_126 ) ;
return V_146 && V_128 >= V_146 -> V_95 && V_128 < V_146 -> V_97 ;
}
int F_46 ( unsigned long V_128 )
{
return 0 ;
}
