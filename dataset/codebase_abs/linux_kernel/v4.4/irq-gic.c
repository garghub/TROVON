static void F_1 ( void )
{
F_2 ( F_3 ( V_1 ) ,
V_2 ,
L_1 ) ;
}
static void T_1 * F_4 ( union V_3 * V_4 )
{
return F_5 ( * V_4 -> V_5 ) ;
}
static void T_1 * F_6 ( union V_3 * V_4 )
{
return V_4 -> V_6 ;
}
static inline void T_1 * F_7 ( struct V_7 * V_8 )
{
return V_8 -> V_9 ( & V_8 -> V_10 ) ;
}
static inline void T_1 * F_8 ( struct V_7 * V_8 )
{
return V_8 -> V_9 ( & V_8 -> V_11 ) ;
}
static inline void T_1 * F_9 ( struct V_12 * V_13 )
{
struct V_7 * V_14 = F_10 ( V_13 ) ;
return F_7 ( V_14 ) ;
}
static inline void T_1 * F_11 ( struct V_12 * V_13 )
{
struct V_7 * V_14 = F_10 ( V_13 ) ;
return F_8 ( V_14 ) ;
}
static inline unsigned int F_12 ( struct V_12 * V_13 )
{
return V_13 -> V_15 ;
}
static inline bool F_13 ( struct V_12 * V_13 )
{
void * V_8 = F_14 ( V_13 ) ;
return V_8 != NULL ;
}
static void F_15 ( struct V_12 * V_13 , T_2 V_16 )
{
T_2 V_17 = 1 << ( F_12 ( V_13 ) % 32 ) ;
F_16 ( V_17 , F_9 ( V_13 ) + V_16 + ( F_12 ( V_13 ) / 32 ) * 4 ) ;
}
static int F_17 ( struct V_12 * V_13 , T_2 V_16 )
{
T_2 V_17 = 1 << ( F_12 ( V_13 ) % 32 ) ;
return ! ! ( F_18 ( F_9 ( V_13 ) + V_16 + ( F_12 ( V_13 ) / 32 ) * 4 ) & V_17 ) ;
}
static void F_19 ( struct V_12 * V_13 )
{
F_15 ( V_13 , V_18 ) ;
}
static void F_20 ( struct V_12 * V_13 )
{
F_19 ( V_13 ) ;
if ( F_21 ( V_13 ) )
F_15 ( V_13 , V_19 ) ;
}
static void F_22 ( struct V_12 * V_13 )
{
F_15 ( V_13 , V_20 ) ;
}
static void F_23 ( struct V_12 * V_13 )
{
F_16 ( F_12 ( V_13 ) , F_11 ( V_13 ) + V_21 ) ;
}
static void F_24 ( struct V_12 * V_13 )
{
if ( F_21 ( V_13 ) )
return;
F_16 ( F_12 ( V_13 ) , F_11 ( V_13 ) + V_22 ) ;
}
static int F_25 ( struct V_12 * V_13 ,
enum V_23 V_24 , bool V_25 )
{
T_2 V_26 ;
switch ( V_24 ) {
case V_27 :
V_26 = V_25 ? V_28 : V_29 ;
break;
case V_30 :
V_26 = V_25 ? V_31 : V_19 ;
break;
case V_32 :
V_26 = V_25 ? V_18 : V_20 ;
break;
default:
return - V_33 ;
}
F_15 ( V_13 , V_26 ) ;
return 0 ;
}
static int F_26 ( struct V_12 * V_13 ,
enum V_23 V_24 , bool * V_25 )
{
switch ( V_24 ) {
case V_27 :
* V_25 = F_17 ( V_13 , V_28 ) ;
break;
case V_30 :
* V_25 = F_17 ( V_13 , V_31 ) ;
break;
case V_32 :
* V_25 = ! F_17 ( V_13 , V_20 ) ;
break;
default:
return - V_33 ;
}
return 0 ;
}
static int F_27 ( struct V_12 * V_13 , unsigned int type )
{
void T_1 * V_4 = F_9 ( V_13 ) ;
unsigned int V_34 = F_12 ( V_13 ) ;
if ( V_34 < 16 )
return - V_33 ;
if ( V_34 >= 32 && type != V_35 &&
type != V_36 )
return - V_33 ;
return F_28 ( V_34 , type , V_4 , NULL ) ;
}
static int F_29 ( struct V_12 * V_13 , void * V_37 )
{
if ( F_13 ( V_13 ) )
return - V_33 ;
if ( V_37 )
F_30 ( V_13 ) ;
else
F_31 ( V_13 ) ;
return 0 ;
}
static int F_32 ( struct V_12 * V_13 , const struct V_38 * V_39 ,
bool V_40 )
{
void T_1 * V_26 = F_9 ( V_13 ) + V_41 + ( F_12 ( V_13 ) & ~ 3 ) ;
unsigned int V_42 , V_43 = ( F_12 ( V_13 ) % 4 ) * 8 ;
T_2 V_25 , V_17 , V_44 ;
unsigned long V_45 ;
if ( ! V_40 )
V_42 = F_33 ( V_39 , V_46 ) ;
else
V_42 = F_34 ( V_39 ) ;
if ( V_42 >= V_47 || V_42 >= V_48 )
return - V_33 ;
F_35 ( & V_49 , V_45 ) ;
V_17 = 0xff << V_43 ;
V_44 = V_50 [ V_42 ] << V_43 ;
V_25 = F_18 ( V_26 ) & ~ V_17 ;
F_16 ( V_25 | V_44 , V_26 ) ;
F_36 ( & V_49 , V_45 ) ;
return V_51 ;
}
static void T_3 F_37 ( struct V_52 * V_53 )
{
T_2 V_54 , V_55 ;
struct V_7 * V_56 = & V_14 [ 0 ] ;
void T_1 * V_11 = F_8 ( V_56 ) ;
do {
V_54 = F_18 ( V_11 + V_57 ) ;
V_55 = V_54 & V_58 ;
if ( F_38 ( V_55 > 15 && V_55 < 1021 ) ) {
if ( F_39 ( & V_59 ) )
F_16 ( V_54 , V_11 + V_21 ) ;
F_40 ( V_56 -> V_60 , V_55 , V_53 ) ;
continue;
}
if ( V_55 < 16 ) {
F_16 ( V_54 , V_11 + V_21 ) ;
if ( F_39 ( & V_59 ) )
F_16 ( V_54 , V_11 + V_22 ) ;
#ifdef F_41
F_42 ( V_55 , V_53 ) ;
#endif
continue;
}
break;
} while ( 1 );
}
static void F_43 ( struct V_61 * V_62 )
{
struct V_7 * V_63 = F_44 ( V_62 ) ;
struct V_64 * V_65 = F_45 ( V_62 ) ;
unsigned int V_66 , F_12 ;
unsigned long V_67 ;
F_46 ( V_65 , V_62 ) ;
F_47 ( & V_49 ) ;
V_67 = F_18 ( F_8 ( V_63 ) + V_57 ) ;
F_48 ( & V_49 ) ;
F_12 = ( V_67 & V_58 ) ;
if ( F_12 == V_68 )
goto V_69;
V_66 = F_49 ( V_63 -> V_60 , F_12 ) ;
if ( F_50 ( F_12 < 32 || F_12 > 1020 ) )
F_51 ( V_62 ) ;
else
F_52 ( V_66 ) ;
V_69:
F_53 ( V_65 , V_62 ) ;
}
void T_4 F_54 ( unsigned int V_70 , unsigned int V_71 )
{
if ( V_70 >= V_72 )
F_55 () ;
F_56 ( V_71 , F_43 ,
& V_14 [ V_70 ] ) ;
}
static T_5 F_57 ( struct V_7 * V_56 )
{
void T_1 * V_4 = F_7 ( V_56 ) ;
T_2 V_17 , V_73 ;
for ( V_73 = V_17 = 0 ; V_73 < 32 ; V_73 += 4 ) {
V_17 = F_18 ( V_4 + V_41 + V_73 ) ;
V_17 |= V_17 >> 16 ;
V_17 |= V_17 >> 8 ;
if ( V_17 )
break;
}
if ( ! V_17 && F_58 () > 1 )
F_59 ( L_2 ) ;
return V_17 ;
}
static void F_60 ( struct V_7 * V_56 )
{
void T_1 * V_11 = F_8 ( V_56 ) ;
T_2 V_74 = 0 ;
T_2 V_75 = 0 ;
if ( F_39 ( & V_59 ) )
V_75 = V_76 ;
V_74 = F_61 ( V_11 + V_77 ) ;
V_74 &= V_78 ;
F_16 ( V_74 | V_75 | V_79 , V_11 + V_77 ) ;
}
static void T_4 F_62 ( struct V_7 * V_56 )
{
unsigned int V_73 ;
T_2 V_38 ;
unsigned int V_80 = V_56 -> V_80 ;
void T_1 * V_4 = F_7 ( V_56 ) ;
F_16 ( V_81 , V_4 + V_82 ) ;
V_38 = F_57 ( V_56 ) ;
V_38 |= V_38 << 8 ;
V_38 |= V_38 << 16 ;
for ( V_73 = 32 ; V_73 < V_80 ; V_73 += 4 )
F_16 ( V_38 , V_4 + V_41 + V_73 * 4 / 4 ) ;
F_63 ( V_4 , V_80 , NULL ) ;
F_16 ( V_83 , V_4 + V_82 ) ;
}
static void F_64 ( struct V_7 * V_56 )
{
void T_1 * V_10 = F_7 ( V_56 ) ;
void T_1 * V_4 = F_8 ( V_56 ) ;
unsigned int V_84 , V_42 = F_65 () ;
int V_73 ;
if ( V_56 == & V_14 [ 0 ] ) {
F_66 ( V_42 >= V_47 ) ;
V_84 = F_57 ( V_56 ) ;
V_50 [ V_42 ] = V_84 ;
for ( V_73 = 0 ; V_73 < V_47 ; V_73 ++ )
if ( V_73 != V_42 )
V_50 [ V_73 ] &= ~ V_84 ;
}
F_67 ( V_10 , NULL ) ;
F_16 ( V_85 , V_4 + V_86 ) ;
F_60 ( V_56 ) ;
}
int F_68 ( unsigned int V_70 )
{
void T_1 * V_11 ;
T_2 V_25 = 0 ;
if ( V_70 >= V_72 )
return - V_33 ;
V_11 = F_8 ( & V_14 [ V_70 ] ) ;
V_25 = F_61 ( V_11 + V_77 ) ;
V_25 &= ~ V_79 ;
F_16 ( V_25 , V_11 + V_77 ) ;
return 0 ;
}
static void F_69 ( unsigned int V_70 )
{
unsigned int V_80 ;
void T_1 * V_10 ;
int V_73 ;
if ( V_70 >= V_72 )
F_55 () ;
V_80 = V_14 [ V_70 ] . V_80 ;
V_10 = F_7 ( & V_14 [ V_70 ] ) ;
if ( ! V_10 )
return;
for ( V_73 = 0 ; V_73 < F_70 ( V_80 , 16 ) ; V_73 ++ )
V_14 [ V_70 ] . V_87 [ V_73 ] =
F_18 ( V_10 + V_88 + V_73 * 4 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( V_80 , 4 ) ; V_73 ++ )
V_14 [ V_70 ] . V_89 [ V_73 ] =
F_18 ( V_10 + V_41 + V_73 * 4 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( V_80 , 32 ) ; V_73 ++ )
V_14 [ V_70 ] . V_90 [ V_73 ] =
F_18 ( V_10 + V_20 + V_73 * 4 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( V_80 , 32 ) ; V_73 ++ )
V_14 [ V_70 ] . V_91 [ V_73 ] =
F_18 ( V_10 + V_31 + V_73 * 4 ) ;
}
static void F_71 ( unsigned int V_70 )
{
unsigned int V_80 ;
unsigned int V_73 ;
void T_1 * V_10 ;
if ( V_70 >= V_72 )
F_55 () ;
V_80 = V_14 [ V_70 ] . V_80 ;
V_10 = F_7 ( & V_14 [ V_70 ] ) ;
if ( ! V_10 )
return;
F_16 ( V_81 , V_10 + V_82 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( V_80 , 16 ) ; V_73 ++ )
F_16 ( V_14 [ V_70 ] . V_87 [ V_73 ] ,
V_10 + V_88 + V_73 * 4 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( V_80 , 4 ) ; V_73 ++ )
F_16 ( V_92 ,
V_10 + V_93 + V_73 * 4 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( V_80 , 4 ) ; V_73 ++ )
F_16 ( V_14 [ V_70 ] . V_89 [ V_73 ] ,
V_10 + V_41 + V_73 * 4 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( V_80 , 32 ) ; V_73 ++ ) {
F_16 ( V_94 ,
V_10 + V_18 + V_73 * 4 ) ;
F_16 ( V_14 [ V_70 ] . V_90 [ V_73 ] ,
V_10 + V_20 + V_73 * 4 ) ;
}
for ( V_73 = 0 ; V_73 < F_70 ( V_80 , 32 ) ; V_73 ++ ) {
F_16 ( V_94 ,
V_10 + V_19 + V_73 * 4 ) ;
F_16 ( V_14 [ V_70 ] . V_91 [ V_73 ] ,
V_10 + V_31 + V_73 * 4 ) ;
}
F_16 ( V_83 , V_10 + V_82 ) ;
}
static void F_72 ( unsigned int V_70 )
{
int V_73 ;
T_2 * V_95 ;
void T_1 * V_10 ;
void T_1 * V_11 ;
if ( V_70 >= V_72 )
F_55 () ;
V_10 = F_7 ( & V_14 [ V_70 ] ) ;
V_11 = F_8 ( & V_14 [ V_70 ] ) ;
if ( ! V_10 || ! V_11 )
return;
V_95 = F_73 ( V_14 [ V_70 ] . V_96 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( 32 , 32 ) ; V_73 ++ )
V_95 [ V_73 ] = F_18 ( V_10 + V_20 + V_73 * 4 ) ;
V_95 = F_73 ( V_14 [ V_70 ] . V_97 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( 32 , 32 ) ; V_73 ++ )
V_95 [ V_73 ] = F_18 ( V_10 + V_31 + V_73 * 4 ) ;
V_95 = F_73 ( V_14 [ V_70 ] . V_98 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( 32 , 16 ) ; V_73 ++ )
V_95 [ V_73 ] = F_18 ( V_10 + V_88 + V_73 * 4 ) ;
}
static void F_74 ( unsigned int V_70 )
{
int V_73 ;
T_2 * V_95 ;
void T_1 * V_10 ;
void T_1 * V_11 ;
if ( V_70 >= V_72 )
F_55 () ;
V_10 = F_7 ( & V_14 [ V_70 ] ) ;
V_11 = F_8 ( & V_14 [ V_70 ] ) ;
if ( ! V_10 || ! V_11 )
return;
V_95 = F_73 ( V_14 [ V_70 ] . V_96 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( 32 , 32 ) ; V_73 ++ ) {
F_16 ( V_94 ,
V_10 + V_18 + V_73 * 4 ) ;
F_16 ( V_95 [ V_73 ] , V_10 + V_20 + V_73 * 4 ) ;
}
V_95 = F_73 ( V_14 [ V_70 ] . V_97 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( 32 , 32 ) ; V_73 ++ ) {
F_16 ( V_94 ,
V_10 + V_19 + V_73 * 4 ) ;
F_16 ( V_95 [ V_73 ] , V_10 + V_31 + V_73 * 4 ) ;
}
V_95 = F_73 ( V_14 [ V_70 ] . V_98 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( 32 , 16 ) ; V_73 ++ )
F_16 ( V_95 [ V_73 ] , V_10 + V_88 + V_73 * 4 ) ;
for ( V_73 = 0 ; V_73 < F_70 ( 32 , 4 ) ; V_73 ++ )
F_16 ( V_92 ,
V_10 + V_93 + V_73 * 4 ) ;
F_16 ( V_85 , V_11 + V_86 ) ;
F_60 ( & V_14 [ V_70 ] ) ;
}
static int F_75 ( struct V_99 * V_100 , unsigned long V_101 , void * V_102 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
#ifdef F_76
if ( ! V_14 [ V_73 ] . V_9 )
continue;
#endif
switch ( V_101 ) {
case V_103 :
F_72 ( V_73 ) ;
break;
case V_104 :
case V_105 :
F_74 ( V_73 ) ;
break;
case V_106 :
F_69 ( V_73 ) ;
break;
case V_107 :
case V_108 :
F_71 ( V_73 ) ;
break;
}
}
return V_109 ;
}
static void T_4 F_77 ( struct V_7 * V_56 )
{
V_56 -> V_96 = F_78 ( F_70 ( 32 , 32 ) * 4 ,
sizeof( T_2 ) ) ;
F_66 ( ! V_56 -> V_96 ) ;
V_56 -> V_97 = F_78 ( F_70 ( 32 , 32 ) * 4 ,
sizeof( T_2 ) ) ;
F_66 ( ! V_56 -> V_97 ) ;
V_56 -> V_98 = F_78 ( F_70 ( 32 , 16 ) * 4 ,
sizeof( T_2 ) ) ;
F_66 ( ! V_56 -> V_98 ) ;
if ( V_56 == & V_14 [ 0 ] )
F_79 ( & V_110 ) ;
}
static void T_4 F_77 ( struct V_7 * V_56 )
{
}
static void F_80 ( const struct V_38 * V_17 , unsigned int V_71 )
{
int V_42 ;
unsigned long V_45 , V_111 = 0 ;
F_35 ( & V_49 , V_45 ) ;
F_81 (cpu, mask)
V_111 |= V_50 [ V_42 ] ;
F_82 ( V_112 ) ;
F_16 ( V_111 << 16 | V_71 , F_7 ( & V_14 [ 0 ] ) + V_113 ) ;
F_36 ( & V_49 , V_45 ) ;
}
void F_83 ( unsigned int V_114 , unsigned int V_71 )
{
F_66 ( V_114 >= V_47 ) ;
V_114 = 1 << V_114 ;
F_16 ( ( V_114 << 16 ) | V_71 , F_7 ( & V_14 [ 0 ] ) + V_113 ) ;
}
int F_84 ( unsigned int V_42 )
{
unsigned int V_115 ;
if ( V_42 >= V_47 )
return - 1 ;
V_115 = V_50 [ V_42 ] ;
if ( V_115 & ( V_115 - 1 ) )
return - 1 ;
return F_85 ( V_115 ) ;
}
void F_86 ( unsigned int V_116 )
{
unsigned int V_117 , V_80 , V_70 = 0 ;
void T_1 * V_10 ;
int V_73 , V_118 , V_42 = F_65 () ;
T_2 V_25 , V_119 , V_120 ;
if ( V_70 >= V_72 )
F_55 () ;
V_10 = F_7 ( & V_14 [ V_70 ] ) ;
if ( ! V_10 )
return;
V_80 = V_14 [ V_70 ] . V_80 ;
V_117 = F_85 ( V_50 [ V_42 ] ) ;
V_119 = 0x01010101 << V_117 ;
V_118 = ( V_117 - V_116 ) & 31 ;
F_47 ( & V_49 ) ;
V_50 [ V_42 ] = 1 << V_116 ;
for ( V_73 = 8 ; V_73 < F_70 ( V_80 , 4 ) ; V_73 ++ ) {
V_25 = F_18 ( V_10 + V_41 + V_73 * 4 ) ;
V_120 = V_25 & V_119 ;
if ( V_120 ) {
V_25 &= ~ V_120 ;
V_25 |= F_87 ( V_120 , V_118 ) ;
F_16 ( V_25 , V_10 + V_41 + V_73 * 4 ) ;
}
}
F_48 ( & V_49 ) ;
for ( V_73 = 0 ; V_73 < 16 ; V_73 += 4 ) {
int V_121 ;
V_25 = F_18 ( V_10 + V_122 + V_73 ) ;
if ( ! V_25 )
continue;
F_16 ( V_25 , V_10 + V_123 + V_73 ) ;
for ( V_121 = V_73 ; V_121 < V_73 + 4 ; V_121 ++ ) {
if ( V_25 & 0xff )
F_16 ( ( 1 << ( V_116 + 16 ) ) | V_121 ,
V_10 + V_113 ) ;
V_25 >>= 8 ;
}
}
}
unsigned long F_88 ( void )
{
if ( ! V_124 )
return 0 ;
return V_124 + V_113 ;
}
void T_4 F_89 ( struct V_125 * V_126 )
{
struct V_127 V_128 ;
if ( F_90 ( V_126 , 0 , & V_128 ) == 0 ) {
V_124 = V_128 . V_129 ;
F_91 ( L_3 , V_124 ) ;
}
}
static int F_92 ( struct V_130 * V_13 , unsigned int V_71 ,
T_6 V_131 )
{
struct V_64 * V_65 = & V_132 ;
if ( F_39 ( & V_59 ) ) {
if ( V_13 -> V_133 == ( void * ) & V_14 [ 0 ] )
V_65 = & V_134 ;
}
if ( V_131 < 32 ) {
F_93 ( V_71 ) ;
F_94 ( V_13 , V_71 , V_131 , V_65 , V_13 -> V_133 ,
V_135 , NULL , NULL ) ;
F_95 ( V_71 , V_136 ) ;
} else {
F_94 ( V_13 , V_71 , V_131 , V_65 , V_13 -> V_133 ,
V_137 , NULL , NULL ) ;
F_96 ( V_71 ) ;
}
return 0 ;
}
static void F_97 ( struct V_130 * V_13 , unsigned int V_71 )
{
}
static int F_98 ( struct V_130 * V_13 ,
struct V_138 * V_139 ,
unsigned long * V_15 ,
unsigned int * type )
{
if ( F_99 ( V_139 -> V_140 ) ) {
if ( V_139 -> V_141 < 3 )
return - V_33 ;
* V_15 = V_139 -> V_142 [ 1 ] + 16 ;
if ( ! V_139 -> V_142 [ 0 ] )
* V_15 += 16 ;
* type = V_139 -> V_142 [ 2 ] & V_143 ;
return 0 ;
}
if ( V_139 -> V_140 -> type == V_144 ) {
if( V_139 -> V_141 != 2 )
return - V_33 ;
* V_15 = V_139 -> V_142 [ 0 ] ;
* type = V_139 -> V_142 [ 1 ] ;
return 0 ;
}
return - V_33 ;
}
static int F_100 ( struct V_99 * V_145 , unsigned long V_146 ,
void * V_147 )
{
if ( V_146 == V_148 || V_146 == V_149 )
F_64 ( & V_14 [ 0 ] ) ;
return V_109 ;
}
static int F_101 ( struct V_130 * V_60 , unsigned int V_150 ,
unsigned int V_151 , void * V_152 )
{
int V_73 , V_153 ;
T_6 V_15 ;
unsigned int type = V_154 ;
struct V_138 * V_139 = V_152 ;
V_153 = F_98 ( V_60 , V_139 , & V_15 , & type ) ;
if ( V_153 )
return V_153 ;
for ( V_73 = 0 ; V_73 < V_151 ; V_73 ++ )
F_92 ( V_60 , V_150 + V_73 , V_15 + V_73 ) ;
return 0 ;
}
static void T_4 F_102 ( unsigned int V_70 , int V_155 ,
void T_1 * V_10 , void T_1 * V_11 ,
T_2 V_156 , struct V_157 * V_158 )
{
T_6 V_159 ;
struct V_7 * V_56 ;
int V_80 , V_160 , V_73 ;
F_66 ( V_70 >= V_72 ) ;
F_1 () ;
V_56 = & V_14 [ V_70 ] ;
#ifdef F_76
if ( V_156 ) {
unsigned int V_42 ;
V_56 -> V_10 . V_5 = F_103 (void __iomem *) ;
V_56 -> V_11 . V_5 = F_103 (void __iomem *) ;
if ( F_104 ( ! V_56 -> V_10 . V_5 ||
! V_56 -> V_11 . V_5 ) ) {
F_105 ( V_56 -> V_10 . V_5 ) ;
F_105 ( V_56 -> V_11 . V_5 ) ;
return;
}
F_106 (cpu) {
T_2 V_161 = F_107 ( V_42 ) ;
T_2 V_162 = F_108 ( V_161 , 0 ) ;
unsigned long V_16 = V_156 * V_162 ;
* F_109 ( V_56 -> V_10 . V_5 , V_42 ) = V_10 + V_16 ;
* F_109 ( V_56 -> V_11 . V_5 , V_42 ) = V_11 + V_16 ;
}
F_110 ( V_56 , F_4 ) ;
} else
#endif
{
F_111 ( V_156 ,
L_4 ,
V_156 ) ;
V_56 -> V_10 . V_6 = V_10 ;
V_56 -> V_11 . V_6 = V_11 ;
F_110 ( V_56 , F_6 ) ;
}
V_80 = F_18 ( F_7 ( V_56 ) + V_163 ) & 0x1f ;
V_80 = ( V_80 + 1 ) * 32 ;
if ( V_80 > 1020 )
V_80 = 1020 ;
V_56 -> V_80 = V_80 ;
if ( V_158 ) {
V_56 -> V_60 = F_112 ( V_158 , V_80 ,
& V_164 ,
V_56 ) ;
} else {
if ( V_70 == 0 && ( V_155 & 31 ) > 0 ) {
V_159 = 16 ;
if ( V_155 != - 1 )
V_155 = ( V_155 & ~ 31 ) + 16 ;
} else {
V_159 = 32 ;
}
V_80 -= V_159 ;
V_160 = F_113 ( V_155 , 16 , V_80 ,
F_114 () ) ;
if ( F_115 ( V_160 ) ) {
F_111 ( 1 , L_5 ,
V_155 ) ;
V_160 = V_155 ;
}
V_56 -> V_60 = F_116 ( NULL , V_80 , V_160 ,
V_159 , & V_165 , V_56 ) ;
}
if ( F_104 ( ! V_56 -> V_60 ) )
return;
if ( V_70 == 0 ) {
for ( V_73 = 0 ; V_73 < V_47 ; V_73 ++ )
V_50 [ V_73 ] = 0xff ;
#ifdef F_41
F_117 ( F_80 ) ;
F_118 ( & V_166 ) ;
#endif
F_119 ( F_37 ) ;
if ( F_39 ( & V_59 ) )
F_91 ( L_6 ) ;
}
F_62 ( V_56 ) ;
F_64 ( V_56 ) ;
F_77 ( V_56 ) ;
}
void T_4 F_120 ( unsigned int V_70 , int V_155 ,
void T_1 * V_10 , void T_1 * V_11 )
{
F_121 ( & V_59 ) ;
F_102 ( V_70 , V_155 , V_10 , V_11 , 0 , NULL ) ;
}
static bool F_122 ( struct V_125 * V_126 , void T_1 * * V_4 )
{
struct V_127 V_167 ;
F_90 ( V_126 , 1 , & V_167 ) ;
if ( ! F_123 () )
return false ;
if ( F_124 ( & V_167 ) < V_168 )
return false ;
if ( F_124 ( & V_167 ) == V_169 ) {
T_2 V_170 , V_171 ;
V_170 = F_18 ( * V_4 + V_172 ) ;
V_171 = F_18 ( * V_4 + V_172 + 0xf000 ) ;
if ( ( V_170 & 0xffff0fff ) != 0x0202043B ||
V_170 != V_171 )
return false ;
* V_4 += 0xf000 ;
V_167 . V_129 += 0xf000 ;
F_125 ( L_7 ,
& V_167 . V_129 ) ;
}
return true ;
}
static int T_4
F_126 ( struct V_125 * V_126 , struct V_125 * V_173 )
{
void T_1 * V_11 ;
void T_1 * V_10 ;
T_2 V_156 ;
int V_71 ;
if ( F_104 ( ! V_126 ) )
return - V_174 ;
V_10 = F_127 ( V_126 , 0 ) ;
F_111 ( ! V_10 , L_8 ) ;
V_11 = F_127 ( V_126 , 1 ) ;
F_111 ( ! V_11 , L_9 ) ;
if ( V_175 == 0 && ! F_122 ( V_126 , & V_11 ) )
F_121 ( & V_59 ) ;
if ( F_128 ( V_126 , L_10 , & V_156 ) )
V_156 = 0 ;
F_102 ( V_175 , - 1 , V_10 , V_11 , V_156 ,
& V_126 -> V_140 ) ;
if ( ! V_175 )
F_89 ( V_126 ) ;
if ( V_173 ) {
V_71 = F_129 ( V_126 , 0 ) ;
F_54 ( V_175 , V_71 ) ;
}
if ( F_130 ( V_176 ) )
F_131 ( V_126 , V_14 [ V_175 ] . V_60 ) ;
V_175 ++ ;
return 0 ;
}
static int T_4
F_132 ( struct V_177 * V_178 ,
const unsigned long V_179 )
{
struct V_180 * V_181 ;
T_7 F_11 ;
static int V_182 ;
V_181 = (struct V_180 * ) V_178 ;
if ( F_133 ( V_181 , V_179 ) )
return - V_33 ;
F_11 = V_181 -> V_183 ;
if ( V_182 && F_11 != V_184 )
return - V_33 ;
V_184 = F_11 ;
V_182 = 1 ;
return 0 ;
}
static int T_4 F_134 ( struct V_177 * V_178 ,
const unsigned long V_179 )
{
return 0 ;
}
static bool T_4 F_135 ( void )
{
return F_136 ( V_185 ,
F_134 , 0 ) > 0 ;
}
static bool T_4 F_137 ( struct V_177 * V_178 ,
struct V_186 * V_187 )
{
struct V_188 * V_189 ;
V_189 = (struct V_188 * ) V_178 ;
return ( V_189 -> V_190 == V_187 -> V_191 &&
( V_189 -> V_190 != V_192 ||
! F_135 () ) ) ;
}
static int T_4 F_138 ( struct V_177 * V_178 ,
const unsigned long V_179 )
{
struct V_188 * V_189 ;
void T_1 * V_11 , * V_10 ;
struct V_157 * V_193 ;
int V_194 ;
V_194 = F_136 ( V_195 ,
F_132 , 0 ) ;
if ( V_194 <= 0 ) {
F_139 ( L_11 ) ;
return - V_33 ;
}
V_11 = F_140 ( V_184 , V_196 ) ;
if ( ! V_11 ) {
F_139 ( L_12 ) ;
return - V_197 ;
}
V_189 = (struct V_188 * ) V_178 ;
V_10 = F_140 ( V_189 -> V_183 , V_198 ) ;
if ( ! V_10 ) {
F_139 ( L_13 ) ;
F_141 ( V_11 ) ;
return - V_197 ;
}
if ( ! F_123 () )
F_121 ( & V_59 ) ;
V_193 = F_142 ( V_10 ) ;
if ( ! V_193 ) {
F_139 ( L_14 ) ;
F_141 ( V_11 ) ;
F_141 ( V_10 ) ;
return - V_197 ;
}
F_102 ( 0 , - 1 , V_10 , V_11 , 0 , V_193 ) ;
F_143 ( V_199 , V_193 ) ;
return 0 ;
}
