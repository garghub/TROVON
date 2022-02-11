static inline unsigned int F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 = 0 ;
if ( V_1 -> V_3 & V_4 )
V_2 = F_2 () ;
return V_2 ;
}
static inline T_1 F_3 ( enum V_5 type ,
struct V_6 * V_7 ,
unsigned int V_8 )
{
switch( type ) {
#ifdef F_4
case V_9 :
return F_5 ( V_7 -> V_10 , V_8 ) ;
#endif
case V_11 :
return F_6 ( V_7 -> V_12 + ( V_8 >> 2 ) ) ;
case V_13 :
default:
return F_7 ( V_7 -> V_12 + ( V_8 >> 2 ) ) ;
}
}
static inline void F_8 ( enum V_5 type ,
struct V_6 * V_7 ,
unsigned int V_8 , T_1 V_14 )
{
switch( type ) {
#ifdef F_4
case V_9 :
F_9 ( V_7 -> V_10 , V_8 , V_14 ) ;
break;
#endif
case V_11 :
F_10 ( V_7 -> V_12 + ( V_8 >> 2 ) , V_14 ) ;
break;
case V_13 :
default:
F_11 ( V_7 -> V_12 + ( V_8 >> 2 ) , V_14 ) ;
break;
}
}
static inline T_1 F_12 ( struct V_1 * V_1 , unsigned int V_15 )
{
enum V_5 type = V_1 -> V_16 ;
unsigned int V_17 = F_13 ( V_18 ) +
( V_15 * F_13 ( V_19 ) ) ;
if ( ( V_1 -> V_3 & V_20 ) && type == V_13 )
type = V_11 ;
return F_3 ( type , & V_1 -> V_21 , V_17 ) ;
}
static inline void F_14 ( struct V_1 * V_1 , unsigned int V_15 , T_1 V_14 )
{
unsigned int V_17 = F_13 ( V_18 ) +
( V_15 * F_13 ( V_19 ) ) ;
F_8 ( V_1 -> V_16 , & V_1 -> V_21 , V_17 , V_14 ) ;
}
static inline T_1 F_15 ( struct V_1 * V_1 , unsigned int V_22 )
{
unsigned int V_17 = F_13 ( V_23 ) +
( ( V_22 & 3 ) * F_13 ( V_24 ) ) ;
if ( V_22 >= 4 )
V_17 += 0x1000 / 4 ;
return F_3 ( V_1 -> V_16 , & V_1 -> V_25 , V_17 ) ;
}
static inline void F_16 ( struct V_1 * V_1 , unsigned int V_22 , T_1 V_14 )
{
unsigned int V_17 = F_13 ( V_23 ) +
( ( V_22 & 3 ) * F_13 ( V_24 ) ) ;
if ( V_22 >= 4 )
V_17 += 0x1000 / 4 ;
F_8 ( V_1 -> V_16 , & V_1 -> V_25 , V_17 , V_14 ) ;
}
static inline T_1 F_17 ( struct V_1 * V_1 , unsigned int V_8 )
{
unsigned int V_2 = F_1 ( V_1 ) ;
return F_3 ( V_1 -> V_16 , & V_1 -> V_26 [ V_2 ] , V_8 ) ;
}
static inline void F_18 ( struct V_1 * V_1 , unsigned int V_8 , T_1 V_14 )
{
unsigned int V_2 = F_1 ( V_1 ) ;
F_8 ( V_1 -> V_16 , & V_1 -> V_26 [ V_2 ] , V_8 , V_14 ) ;
}
static inline T_1 F_19 ( struct V_1 * V_1 , unsigned int V_27 , unsigned int V_8 )
{
unsigned int V_28 = V_27 >> V_1 -> V_29 ;
unsigned int V_30 = V_27 & V_1 -> V_31 ;
unsigned int V_32 ;
V_32 = F_3 ( V_1 -> V_16 , & V_1 -> V_33 [ V_28 ] ,
V_8 + ( V_30 * F_13 ( V_34 ) ) ) ;
#ifdef F_20
if ( V_8 == 0 )
V_32 = ( V_32 & ( V_35 | V_36 ) ) |
V_1 -> V_37 [ V_27 ] ;
#endif
return V_32 ;
}
static inline void F_21 ( struct V_1 * V_1 , unsigned int V_27 ,
unsigned int V_8 , T_1 V_14 )
{
unsigned int V_28 = V_27 >> V_1 -> V_29 ;
unsigned int V_30 = V_27 & V_1 -> V_31 ;
F_8 ( V_1 -> V_16 , & V_1 -> V_33 [ V_28 ] ,
V_8 + ( V_30 * F_13 ( V_34 ) ) , V_14 ) ;
#ifdef F_20
if ( V_8 == 0 )
V_1 -> V_37 [ V_27 ] =
V_14 & ~ ( V_35 | V_36 ) ;
#endif
}
static void F_22 ( struct V_1 * V_1 , T_2 V_38 ,
struct V_6 * V_7 , unsigned int V_17 ,
unsigned int V_39 )
{
V_7 -> V_12 = F_23 ( V_38 + V_17 , V_39 ) ;
F_24 ( V_7 -> V_12 == NULL ) ;
}
static void F_25 ( struct V_1 * V_1 , struct V_40 * V_41 ,
struct V_6 * V_7 ,
unsigned int V_17 , unsigned int V_39 )
{
const T_1 * V_42 ;
V_42 = F_26 ( V_41 , L_1 , NULL ) ;
V_7 -> V_10 = F_27 ( V_41 , * V_42 + V_17 , V_39 ) ;
F_24 ( ! F_28 ( V_7 -> V_10 ) ) ;
}
static inline void F_29 ( struct V_1 * V_1 , struct V_40 * V_41 ,
T_2 V_38 , struct V_6 * V_7 ,
unsigned int V_17 , unsigned int V_39 )
{
if ( V_1 -> V_3 & V_43 )
F_25 ( V_1 , V_41 , V_7 , V_17 , V_39 ) ;
else
F_22 ( V_1 , V_38 , V_7 , V_17 , V_39 ) ;
}
static void T_3 F_30 ( struct V_1 * V_1 )
{
T_1 V_44 ;
F_31 ( V_1 -> V_21 , F_13 ( V_18 ) , V_35 ) ;
V_44 = F_32 ( V_1 -> V_21 , F_13 ( V_18 ) ) ;
if ( V_44 == F_33 ( V_35 ) ) {
F_34 ( V_45 L_2 ) ;
V_1 -> V_3 |= V_20 ;
}
}
static inline int F_35 ( struct V_1 * V_1 , unsigned int V_46 )
{
if ( V_46 >= 128 || ! V_1 -> V_47 )
return 0 ;
return V_1 -> V_47 [ V_46 ] . V_12 != NULL ;
}
static inline void F_36 ( struct V_1 * V_1 , unsigned int V_46 )
{
struct V_48 * V_49 = & V_1 -> V_47 [ V_46 ] ;
if ( V_49 -> V_50 ) {
unsigned int V_51 = ( V_49 -> V_52 >> 3 ) & ~ 3 ;
unsigned int V_53 = 1U << ( V_49 -> V_52 & 0x1f ) ;
F_37 ( V_53 , V_49 -> V_50 + V_51 ) ;
} else {
F_38 ( & V_1 -> V_54 ) ;
F_39 ( 0x11 + 2 * V_49 -> V_52 , V_49 -> V_12 + 2 ) ;
F_37 ( V_49 -> V_55 , V_49 -> V_12 + 4 ) ;
F_40 ( & V_1 -> V_54 ) ;
}
}
static void F_41 ( struct V_1 * V_1 , unsigned int V_46 ,
bool V_56 )
{
struct V_48 * V_49 = & V_1 -> V_47 [ V_46 ] ;
unsigned long V_3 ;
T_1 V_57 ;
if ( V_49 -> V_12 == NULL )
return;
F_42 ( L_3 ,
V_46 , V_49 -> V_52 ) ;
F_43 ( & V_1 -> V_54 , V_3 ) ;
F_39 ( 0x10 + 2 * V_49 -> V_52 , V_49 -> V_12 + 2 ) ;
V_57 = F_44 ( V_49 -> V_12 + 4 ) ;
V_57 &= ~ ( 0x23U ) ;
if ( V_56 )
V_57 |= 0x22 ;
F_37 ( V_57 , V_49 -> V_12 + 4 ) ;
F_45 ( & V_1 -> V_54 , V_3 ) ;
#ifdef F_46
V_1 -> V_58 [ V_46 ] . V_59 = V_57 | 1 ;
#endif
}
static void F_47 ( struct V_1 * V_1 , unsigned int V_46 )
{
struct V_48 * V_49 = & V_1 -> V_47 [ V_46 ] ;
unsigned long V_3 ;
T_1 V_57 ;
if ( V_49 -> V_12 == NULL )
return;
F_42 ( L_4 , V_46 ) ;
F_43 ( & V_1 -> V_54 , V_3 ) ;
F_39 ( 0x10 + 2 * V_49 -> V_52 , V_49 -> V_12 + 2 ) ;
V_57 = F_44 ( V_49 -> V_12 + 4 ) ;
V_57 |= 1 ;
F_37 ( V_57 , V_49 -> V_12 + 4 ) ;
F_45 ( & V_1 -> V_54 , V_3 ) ;
#ifdef F_46
V_1 -> V_58 [ V_46 ] . V_59 = V_57 & ~ 1 ;
#endif
}
static void T_3 F_48 ( struct V_1 * V_1 , T_4 T_5 * V_60 ,
unsigned int V_61 )
{
T_4 T_5 * V_12 ;
T_4 V_62 , V_3 ;
T_6 V_63 = 0 ;
for ( V_62 = F_49 ( V_60 + V_64 ) ; V_62 != 0 ;
V_62 = F_49 ( V_60 + V_62 + V_65 ) ) {
T_4 V_66 = F_49 ( V_60 + V_62 + V_67 ) ;
if ( V_66 == V_68 ) {
V_66 = F_49 ( V_60 + V_62 + 3 ) ;
if ( ( V_66 & V_69 ) == V_70 )
break;
}
}
if ( V_62 == 0 )
return;
V_12 = V_60 + V_62 ;
V_3 = F_49 ( V_12 + V_71 ) ;
if ( ! ( V_3 & V_72 ) ) {
V_63 = F_44 ( V_12 + V_73 ) & V_74 ;
V_63 = V_63 | ( ( T_6 ) F_44 ( V_12 + V_75 ) << 32 ) ;
}
F_34 ( V_76 L_5 ,
F_50 ( V_61 ) , F_51 ( V_61 ) ,
V_3 & V_77 ? L_6 : L_7 , V_63 ) ;
if ( ! ( V_3 & V_77 ) )
F_39 ( V_3 | V_77 , V_12 + V_71 ) ;
}
static void T_3 F_48 ( struct V_1 * V_1 , T_4 T_5 * V_60 ,
unsigned int V_61 )
{
return;
}
static void T_3 F_52 ( struct V_1 * V_1 , T_4 T_5 * V_60 ,
unsigned int V_61 , T_1 V_78 )
{
int V_79 , V_80 , V_81 ;
T_4 T_5 * V_12 ;
T_1 V_57 ;
T_4 V_62 ;
for ( V_62 = F_49 ( V_60 + V_64 ) ; V_62 != 0 ;
V_62 = F_49 ( V_60 + V_62 + V_65 ) ) {
T_4 V_66 = F_49 ( V_60 + V_62 + V_67 ) ;
if ( V_66 == V_68 ) {
V_66 = F_49 ( V_60 + V_62 + 3 ) ;
if ( ( V_66 & V_69 ) == V_82 )
break;
}
}
if ( V_62 == 0 )
return;
V_12 = V_60 + V_62 ;
F_39 ( 0x01 , V_12 + 2 ) ;
V_81 = ( F_44 ( V_12 + 4 ) >> 16 ) & 0xff ;
F_34 ( V_45 L_8
L_9 ,
V_61 >> 3 , V_61 & 0x7 , V_62 , V_78 & 0xffff , V_78 >> 16 , V_81 + 1 ) ;
for ( V_79 = 0 ; V_79 <= V_81 ; V_79 ++ ) {
F_39 ( 0x10 + 2 * V_79 , V_12 + 2 ) ;
V_57 = F_44 ( V_12 + 4 ) ;
V_80 = ( V_57 >> 16 ) & 0xff ;
F_42 ( L_10 , V_79 , V_80 , V_57 ) ;
V_57 |= 0x1 ;
F_37 ( V_57 , V_12 + 4 ) ;
V_1 -> V_47 [ V_80 ] . V_52 = V_79 ;
V_1 -> V_47 [ V_80 ] . V_12 = V_12 ;
if ( ( V_78 & 0xffff ) == 0x106b )
V_1 -> V_47 [ V_80 ] . V_50 = V_60 + 0x60 ;
else
V_1 -> V_47 [ V_80 ] . V_50 = NULL ;
F_39 ( 0x11 + 2 * V_79 , V_12 + 2 ) ;
V_1 -> V_47 [ V_80 ] . V_55 = F_44 ( V_12 + 4 ) | 0x80000000 ;
}
}
static void T_3 F_53 ( struct V_1 * V_1 )
{
unsigned int V_61 ;
T_4 T_5 * V_83 ;
F_34 ( V_45 L_11 ) ;
V_1 -> V_47 = F_54 ( 128 * sizeof( * V_1 -> V_47 ) , V_84 ) ;
F_24 ( V_1 -> V_47 == NULL ) ;
F_55 ( & V_1 -> V_54 ) ;
V_83 = F_23 ( 0xf2000000 , 0x10000 ) ;
F_24 ( V_83 == NULL ) ;
for ( V_61 = 0 ; V_61 < 0x100 ; V_61 ++ ) {
T_4 T_5 * V_60 = V_83 + ( V_61 << 8 ) ;
T_4 V_85 = F_49 ( V_60 + V_86 ) ;
T_1 V_87 = F_44 ( V_60 + V_88 ) ;
T_7 V_89 ;
F_42 ( L_12 , V_61 , V_87 ) ;
if ( V_87 == 0xffffffff || V_87 == 0x00000000 ||
V_87 == 0x0000ffff || V_87 == 0xffff0000 )
goto V_90;
V_89 = F_56 ( V_60 + V_91 ) ;
if ( ! ( V_89 & V_92 ) )
goto V_90;
F_52 ( V_1 , V_60 , V_61 , V_87 ) ;
F_48 ( V_1 , V_60 , V_61 ) ;
V_90:
if ( F_51 ( V_61 ) == 0 && ( V_85 & 0x80 ) == 0 )
V_61 += 7 ;
}
}
static inline int F_35 ( struct V_1 * V_1 , unsigned int V_46 )
{
return 0 ;
}
static void T_3 F_53 ( struct V_1 * V_1 )
{
}
static int F_57 ( const struct V_93 * V_53 )
{
int V_94 ;
if ( F_58 ( V_53 , V_95 ) ) {
static int V_96 = 0 ;
static F_59 ( V_97 ) ;
unsigned long V_3 ;
V_98:
F_43 ( & V_97 , V_3 ) ;
V_96 = F_60 ( V_96 , V_99 ) ;
if ( V_96 >= V_100 )
V_96 = F_61 ( V_99 ) ;
V_94 = V_96 ;
F_45 ( & V_97 , V_3 ) ;
} else {
V_94 = F_62 ( V_53 , V_99 ) ;
if ( V_94 >= V_100 )
goto V_98;
}
return F_63 ( V_94 ) ;
}
static int F_57 ( const struct V_93 * V_53 )
{
return F_2 () ;
}
static struct V_1 * F_64 ( unsigned int V_80 )
{
if ( V_80 < V_101 )
return NULL ;
return F_65 ( V_80 ) ;
}
static unsigned int F_66 ( struct V_1 * V_1 , unsigned int V_80 )
{
unsigned int V_102 = F_67 ( V_80 ) ;
return ( V_102 >= V_1 -> V_103 [ 0 ] && V_102 <= V_1 -> V_103 [ 3 ] ) ;
}
static unsigned int F_68 ( struct V_1 * V_1 , unsigned int V_80 )
{
unsigned int V_102 = F_67 ( V_80 ) ;
return ( V_102 >= V_1 -> V_104 [ 0 ] && V_102 <= V_1 -> V_104 [ 7 ] ) ;
}
static inline T_1 F_69 ( T_1 V_93 )
{
int V_79 ;
T_1 V_53 = 0 ;
for ( V_79 = 0 ; V_79 < F_70 ( 32 , V_105 ) ; ++ V_79 , V_93 >>= 1 )
V_53 |= ( V_93 & 1 ) << F_63 ( V_79 ) ;
return V_53 ;
}
static inline struct V_1 * F_71 ( struct V_106 * V_107 )
{
return F_72 ( V_107 ) ;
}
static inline struct V_1 * F_73 ( unsigned int V_80 )
{
return F_65 ( V_80 ) ;
}
static inline struct V_1 * F_74 ( struct V_106 * V_107 )
{
return F_72 ( V_107 ) ;
}
static inline void F_75 ( struct V_1 * V_1 )
{
F_76 ( F_13 ( V_108 ) , 0 ) ;
( void ) F_77 ( F_13 ( V_109 ) ) ;
}
void F_78 ( struct V_106 * V_107 )
{
unsigned int V_110 = 100000 ;
struct V_1 * V_1 = F_74 ( V_107 ) ;
unsigned int V_102 = F_79 ( V_107 ) ;
F_42 ( L_13 , V_1 , V_1 -> V_111 , V_107 -> V_80 , V_102 ) ;
F_80 ( V_102 , F_13 ( V_112 ) ,
F_81 ( V_102 , F_13 ( V_112 ) ) &
~ V_35 ) ;
do {
if ( ! V_110 -- ) {
F_34 ( V_113 L_14 ,
V_114 , V_102 ) ;
break;
}
} while( F_81 ( V_102 , F_13 ( V_112 ) ) & V_35 );
}
void F_82 ( struct V_106 * V_107 )
{
unsigned int V_110 = 100000 ;
struct V_1 * V_1 = F_74 ( V_107 ) ;
unsigned int V_102 = F_79 ( V_107 ) ;
F_42 ( L_15 , V_1 -> V_111 , V_107 -> V_80 , V_102 ) ;
F_80 ( V_102 , F_13 ( V_112 ) ,
F_81 ( V_102 , F_13 ( V_112 ) ) |
V_35 ) ;
do {
if ( ! V_110 -- ) {
F_34 ( V_113 L_14 ,
V_114 , V_102 ) ;
break;
}
} while( ! ( F_81 ( V_102 , F_13 ( V_112 ) ) & V_35 ) );
}
void F_83 ( struct V_106 * V_107 )
{
struct V_1 * V_1 = F_74 ( V_107 ) ;
#ifdef F_84
F_42 ( L_16 , V_1 -> V_111 , V_107 -> V_80 ) ;
#endif
F_75 ( V_1 ) ;
}
static void F_85 ( struct V_106 * V_107 )
{
struct V_1 * V_1 = F_74 ( V_107 ) ;
unsigned int V_102 = F_79 ( V_107 ) ;
F_78 ( V_107 ) ;
if ( F_86 ( V_107 ) )
F_36 ( V_1 , V_102 ) ;
}
static unsigned int F_87 ( struct V_106 * V_107 )
{
struct V_1 * V_1 = F_74 ( V_107 ) ;
unsigned int V_102 = F_79 ( V_107 ) ;
F_78 ( V_107 ) ;
F_41 ( V_1 , V_102 , F_86 ( V_107 ) ) ;
return 0 ;
}
static void F_88 ( struct V_106 * V_107 )
{
struct V_1 * V_1 = F_74 ( V_107 ) ;
unsigned int V_102 = F_79 ( V_107 ) ;
F_47 ( V_1 , V_102 ) ;
F_82 ( V_107 ) ;
}
static void F_89 ( struct V_106 * V_107 )
{
struct V_1 * V_1 = F_74 ( V_107 ) ;
unsigned int V_102 = F_79 ( V_107 ) ;
#ifdef F_84
F_42 ( L_16 , V_1 -> V_111 , V_107 -> V_80 ) ;
#endif
if ( F_86 ( V_107 ) )
F_36 ( V_1 , V_102 ) ;
F_75 ( V_1 ) ;
}
static void F_90 ( struct V_106 * V_107 )
{
struct V_1 * V_1 = F_71 ( V_107 ) ;
unsigned int V_102 = F_67 ( V_107 -> V_80 ) - V_1 -> V_103 [ 0 ] ;
F_42 ( L_17 , V_1 -> V_111 , V_107 -> V_80 , V_102 ) ;
F_91 ( V_102 , F_92 ( V_102 ) & ~ V_35 ) ;
}
static void F_93 ( struct V_106 * V_107 )
{
}
static void F_94 ( struct V_106 * V_107 )
{
struct V_1 * V_1 = F_71 ( V_107 ) ;
F_75 ( V_1 ) ;
}
static void F_95 ( struct V_106 * V_107 )
{
struct V_1 * V_1 = F_74 ( V_107 ) ;
unsigned int V_102 = F_67 ( V_107 -> V_80 ) - V_1 -> V_104 [ 0 ] ;
F_42 ( L_18 , V_1 -> V_111 , V_80 , V_102 ) ;
F_96 ( V_102 , F_97 ( V_102 ) & ~ V_35 ) ;
F_97 ( V_102 ) ;
}
static void F_98 ( struct V_106 * V_107 )
{
struct V_1 * V_1 = F_74 ( V_107 ) ;
unsigned int V_102 = F_67 ( V_107 -> V_80 ) - V_1 -> V_104 [ 0 ] ;
F_96 ( V_102 , F_97 ( V_102 ) | V_35 ) ;
F_97 ( V_102 ) ;
}
int F_99 ( struct V_106 * V_107 , const struct V_93 * V_93 ,
bool V_115 )
{
struct V_1 * V_1 = F_74 ( V_107 ) ;
unsigned int V_102 = F_79 ( V_107 ) ;
if ( V_1 -> V_3 & V_116 ) {
int V_94 = F_57 ( V_93 ) ;
F_80 ( V_102 , F_13 ( V_117 ) , 1 << V_94 ) ;
} else {
T_1 V_53 = F_100 ( V_93 ) [ 0 ] ;
V_53 &= F_100 ( V_99 ) [ 0 ] ;
F_80 ( V_102 , F_13 ( V_117 ) ,
F_69 ( V_53 ) ) ;
}
return 0 ;
}
static unsigned int F_101 ( struct V_1 * V_1 , unsigned int type )
{
switch( type & V_118 ) {
case V_119 :
return F_13 ( V_120 ) |
F_13 ( V_121 ) ;
case V_122 :
case V_123 :
return F_13 ( V_120 ) |
F_13 ( V_124 ) ;
case V_125 :
return F_13 ( V_126 ) |
F_13 ( V_121 ) ;
case V_127 :
default:
return F_13 ( V_126 ) |
F_13 ( V_124 ) ;
}
}
int F_102 ( struct V_106 * V_107 , unsigned int V_128 )
{
struct V_1 * V_1 = F_74 ( V_107 ) ;
unsigned int V_102 = F_79 ( V_107 ) ;
unsigned int V_129 , V_130 , V_131 ;
F_42 ( L_19 ,
V_1 , V_107 -> V_80 , V_102 , V_128 ) ;
if ( V_102 >= V_1 -> V_132 )
return - V_133 ;
if ( V_128 == V_134 )
if ( V_1 -> V_135 && V_102 < V_1 -> V_136 )
V_128 = V_1 -> V_135 [ V_102 ] ;
if ( V_128 == V_134 )
V_128 = V_127 ;
F_103 ( V_107 , V_128 ) ;
if ( F_35 ( V_1 , V_102 ) )
V_129 = V_137 |
V_138 ;
else
V_129 = F_101 ( V_1 , V_128 ) ;
V_130 = F_81 ( V_102 , F_13 ( V_112 ) ) ;
V_131 = V_130 & ~ ( F_13 ( V_139 ) |
F_13 ( V_140 ) ) ;
V_131 |= V_129 ;
if ( V_130 != V_131 )
F_80 ( V_102 , F_13 ( V_112 ) , V_131 ) ;
return V_141 ; ;
}
void F_104 ( unsigned int V_142 , unsigned int V_143 )
{
struct V_1 * V_1 = F_73 ( V_142 ) ;
unsigned int V_102 = F_67 ( V_142 ) ;
unsigned int V_129 ;
F_42 ( L_20 ,
V_1 , V_142 , V_102 , V_143 ) ;
if ( V_102 >= V_1 -> V_132 )
return;
V_129 = F_81 ( V_102 , F_13 ( V_112 ) ) ;
V_129 = V_129 & ~ F_13 ( V_144 ) ;
V_129 |= V_143 ;
F_80 ( V_102 , F_13 ( V_112 ) , V_129 ) ;
}
void F_105 ( unsigned int V_142 , unsigned int V_94 )
{
struct V_1 * V_1 = F_73 ( V_142 ) ;
unsigned int V_102 = F_67 ( V_142 ) ;
F_42 ( L_21 ,
V_1 , V_142 , V_102 , V_94 ) ;
if ( V_102 >= V_1 -> V_132 )
return;
F_80 ( V_102 , F_13 ( V_117 ) , 1 << V_94 ) ;
}
static int F_106 ( struct V_145 * V_146 , struct V_40 * V_41 )
{
return V_146 -> V_147 == NULL || V_146 -> V_147 == V_41 ;
}
static int F_107 ( struct V_145 * V_146 , unsigned int V_142 ,
T_8 V_148 )
{
struct V_1 * V_1 = V_146 -> V_149 ;
struct V_150 * V_151 ;
F_42 ( L_22 , V_142 , V_148 ) ;
if ( V_148 == V_1 -> V_152 )
return - V_133 ;
if ( V_1 -> V_153 && F_108 ( V_148 , V_1 -> V_153 ) )
return - V_133 ;
#ifdef F_109
else if ( V_148 >= V_1 -> V_103 [ 0 ] ) {
F_110 ( ! ( V_1 -> V_3 & V_4 ) ) ;
F_42 ( L_23 ) ;
F_111 ( V_142 , V_1 ) ;
F_112 ( V_142 , & V_1 -> V_154 ,
V_155 ) ;
return 0 ;
}
#endif
if ( V_148 >= V_1 -> V_104 [ 0 ] && V_148 <= V_1 -> V_104 [ 7 ] ) {
F_110 ( ! ( V_1 -> V_3 & V_4 ) ) ;
F_42 ( L_24 ) ;
F_111 ( V_142 , V_1 ) ;
F_112 ( V_142 , & V_1 -> V_156 ,
V_157 ) ;
return 0 ;
}
if ( V_148 >= V_1 -> V_132 )
return - V_133 ;
F_113 ( V_1 , V_148 ) ;
V_151 = & V_1 -> V_158 ;
#ifdef F_114
if ( F_35 ( V_1 , V_148 ) )
V_151 = & V_1 -> V_159 ;
#endif
F_42 ( L_25 , V_151 ) ;
F_111 ( V_142 , V_1 ) ;
F_112 ( V_142 , V_151 , V_157 ) ;
F_115 ( V_142 , V_134 ) ;
if ( ! F_66 ( V_1 , V_148 ) && ( V_1 -> V_3 & V_160 ) ) {
F_104 ( V_142 , V_148 ) ;
F_105 ( V_142 , F_1 ( V_1 ) ) ;
F_116 ( V_142 , 8 ) ;
}
return 0 ;
}
static int F_117 ( struct V_145 * V_146 , struct V_40 * V_161 ,
const T_1 * V_162 , unsigned int V_163 ,
T_8 * V_164 , unsigned int * V_165 )
{
struct V_1 * V_1 = V_146 -> V_149 ;
static unsigned char V_166 [ 4 ] = {
V_119 ,
V_127 ,
V_125 ,
V_122 ,
} ;
* V_164 = V_162 [ 0 ] ;
if ( V_163 >= 4 && ( V_1 -> V_3 & V_167 ) ) {
switch ( V_162 [ 2 ] ) {
case 0 :
case 1 :
break;
case 2 :
if ( V_162 [ 0 ] >= F_118 ( V_1 -> V_103 ) )
return - V_133 ;
* V_164 = V_1 -> V_103 [ V_162 [ 0 ] ] ;
break;
case 3 :
if ( V_162 [ 0 ] >= F_118 ( V_1 -> V_104 ) )
return - V_133 ;
* V_164 = V_1 -> V_104 [ V_162 [ 0 ] ] ;
break;
default:
F_119 ( L_26 ,
V_114 , V_162 [ 2 ] ) ;
return - V_133 ;
}
* V_165 = V_166 [ V_162 [ 1 ] & 3 ] ;
} else if ( V_163 > 1 ) {
T_1 V_53 = 0x3 ;
if ( F_120 ( V_168 ) )
V_53 = 0x1 ;
* V_165 = V_166 [ V_162 [ 1 ] & V_53 ] ;
} else
* V_165 = V_134 ;
F_42 ( L_27 ,
V_163 , V_162 [ 0 ] , V_162 [ 1 ] , * V_164 , * V_165 ) ;
return 0 ;
}
static int F_121 ( struct V_40 * V_41 )
{
return V_41 && F_26 ( V_41 , L_28 , NULL ) ;
}
struct V_1 * T_3 F_122 ( struct V_40 * V_41 ,
T_2 V_38 ,
unsigned int V_3 ,
unsigned int V_169 ,
unsigned int V_132 ,
const char * V_111 )
{
struct V_1 * V_1 ;
T_1 V_170 ;
const char * V_171 ;
int V_79 ;
int V_172 ;
T_6 V_173 = V_38 ;
V_1 = F_54 ( sizeof( struct V_1 ) , V_84 ) ;
if ( V_1 == NULL )
return NULL ;
V_1 -> V_111 = V_111 ;
V_1 -> V_158 = V_174 ;
V_1 -> V_158 . V_111 = V_111 ;
if ( V_3 & V_4 )
V_1 -> V_158 . V_175 = F_99 ;
#ifdef F_114
V_1 -> V_159 = V_176 ;
V_1 -> V_159 . V_111 = V_111 ;
if ( V_3 & V_4 )
V_1 -> V_159 . V_175 = F_99 ;
#endif
#ifdef F_109
V_1 -> V_154 = V_177 ;
V_1 -> V_154 . V_111 = V_111 ;
#endif
V_1 -> V_156 = V_178 ;
V_1 -> V_156 . V_111 = V_111 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_169 = V_169 ;
V_1 -> V_132 = V_132 ;
V_1 -> V_179 = 0 ;
if ( V_3 & V_180 )
V_172 = 2047 ;
else
V_172 = 255 ;
V_1 -> V_104 [ 0 ] = V_172 - 12 ;
V_1 -> V_104 [ 1 ] = V_172 - 11 ;
V_1 -> V_104 [ 2 ] = V_172 - 10 ;
V_1 -> V_104 [ 3 ] = V_172 - 9 ;
V_1 -> V_104 [ 4 ] = V_172 - 8 ;
V_1 -> V_104 [ 5 ] = V_172 - 7 ;
V_1 -> V_104 [ 6 ] = V_172 - 6 ;
V_1 -> V_104 [ 7 ] = V_172 - 5 ;
V_1 -> V_103 [ 0 ] = V_172 - 4 ;
V_1 -> V_103 [ 1 ] = V_172 - 3 ;
V_1 -> V_103 [ 2 ] = V_172 - 2 ;
V_1 -> V_103 [ 3 ] = V_172 - 1 ;
V_1 -> V_152 = V_172 ;
if ( V_41 && F_26 ( V_41 , L_29 , NULL ) != NULL )
V_1 -> V_3 |= V_181 ;
if ( V_41 && F_123 ( V_41 , L_30 ) )
V_1 -> V_3 |= V_167 ;
if ( V_41 ) {
int V_182 ;
unsigned int V_183 , V_184 ;
const T_1 * V_185 =
F_26 ( V_41 , L_31 , & V_182 ) ;
if ( V_185 ) {
V_182 /= 4 ;
V_183 = V_172 + 1 ;
V_184 = F_124 ( V_183 ) * sizeof( unsigned long ) ;
V_1 -> V_153 = F_54 ( V_184 , V_84 ) ;
F_24 ( V_1 -> V_153 == NULL ) ;
for ( V_79 = 0 ; V_79 < V_182 ; V_79 ++ ) {
if ( V_185 [ V_79 ] > V_172 )
continue;
F_125 ( V_185 [ V_79 ] , V_1 -> V_153 ) ;
}
}
}
#ifdef F_126
V_1 -> V_186 = V_187 [ F_127 ( V_3 ) ] ;
#endif
V_1 -> V_16 = ( V_3 & V_181 ) ?
V_11 : V_13 ;
F_24 ( V_173 == 0 && V_41 == NULL ) ;
if ( V_173 == 0 && F_26 ( V_41 , L_1 , NULL ) != NULL ) {
#ifdef F_4
V_1 -> V_3 |= V_43 ;
V_1 -> V_16 = V_9 ;
#else
F_128 () ;
#endif
}
if ( V_173 == 0 && ! ( V_1 -> V_3 & V_43 ) ) {
const T_1 * V_8 = F_26 ( V_41 , L_32 , NULL ) ;
F_24 ( V_8 == NULL ) ;
V_173 = F_129 ( V_41 , V_8 ) ;
F_24 ( V_173 == V_188 ) ;
}
F_29 ( V_1 , V_41 , V_173 , & V_1 -> V_21 , F_13 ( V_189 ) , 0x1000 ) ;
F_29 ( V_1 , V_41 , V_173 , & V_1 -> V_25 , F_13 ( V_190 ) , 0x1000 ) ;
if ( F_121 ( V_41 ) )
V_1 -> V_3 |= V_160 ;
if ( ( V_3 & V_191 ) && ! ( V_1 -> V_3 & V_160 ) ) {
F_34 ( V_76 L_33 ) ;
F_31 ( V_1 -> V_21 , F_13 ( V_192 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_192 ) )
| V_193 ) ;
while( F_32 ( V_1 -> V_21 , F_13 ( V_192 ) )
& V_193 )
F_130 () ;
}
if ( V_3 & V_194 )
F_31 ( V_1 -> V_21 , F_13 ( V_192 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_192 ) )
| V_195 ) ;
if ( V_3 & V_196 )
F_31 ( V_1 -> V_21 , F_13 ( V_192 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_192 ) )
| V_197 ) ;
V_170 = F_32 ( V_1 -> V_21 , F_13 ( V_198 ) ) ;
V_1 -> V_199 = ( ( V_170 & V_200 )
>> V_201 ) + 1 ;
if ( V_169 == 0 ) {
if ( V_3 & V_202 )
V_1 -> V_179 = V_1 -> V_132 ;
else
V_1 -> V_179 =
( ( V_170 & V_203 )
>> V_204 ) + 1 ;
}
for ( V_79 = 0 ; V_79 < V_1 -> V_199 ; V_79 ++ ) {
F_29 ( V_1 , V_41 , V_173 , & V_1 -> V_26 [ V_79 ] ,
F_13 ( V_205 ) + V_79 * F_13 ( V_206 ) ,
0x1000 ) ;
}
if ( V_1 -> V_169 == 0 ) {
V_1 -> V_169 = V_1 -> V_179 ;
F_29 ( V_1 , V_41 , V_173 , & V_1 -> V_33 [ 0 ] ,
F_13 ( V_207 ) , F_13 ( V_34 ) * V_1 -> V_169 ) ;
}
V_1 -> V_29 = 1 + F_131 ( V_1 -> V_169 - 1 ) ;
V_1 -> V_31 = ( 1 << V_1 -> V_29 ) - 1 ;
V_1 -> V_208 = F_132 ( V_41 , V_209 ,
V_169 ? V_169 : V_1 -> V_179 ,
& V_210 ,
V_3 & V_180 ? 2048 : 256 ) ;
if ( V_1 -> V_208 == NULL )
return NULL ;
V_1 -> V_208 -> V_149 = V_1 ;
switch ( V_170 & V_211 ) {
case 1 :
V_171 = L_34 ;
break;
case 2 :
V_171 = L_35 ;
break;
case 3 :
V_171 = L_36 ;
break;
default:
V_171 = L_37 ;
break;
}
F_34 ( V_45 L_38
L_39 ,
V_111 , V_171 , ( unsigned long long ) V_173 , V_1 -> V_199 ) ;
F_34 ( V_45 L_40 ,
V_1 -> V_169 , V_1 -> V_29 , V_1 -> V_31 ) ;
V_1 -> V_90 = V_212 ;
V_212 = V_1 ;
if ( V_3 & V_4 ) {
V_213 = V_1 ;
F_133 ( V_1 -> V_208 ) ;
}
return V_1 ;
}
void T_3 F_134 ( struct V_1 * V_1 , unsigned int V_214 ,
T_2 V_173 )
{
unsigned int V_215 = V_214 * V_1 -> V_169 ;
F_24 ( V_214 >= V_216 ) ;
F_29 ( V_1 , V_1 -> V_208 -> V_147 ,
V_173 , & V_1 -> V_33 [ V_214 ] , 0 ,
F_13 ( V_34 ) * V_1 -> V_169 ) ;
if ( ( V_215 + V_1 -> V_169 ) > V_1 -> V_179 )
V_1 -> V_179 = V_215 + V_1 -> V_169 ;
}
void T_3 F_135 ( struct V_1 * V_1 , T_4 * V_135 , int V_217 )
{
V_1 -> V_135 = V_135 ;
V_1 -> V_136 = V_217 ;
}
void T_3 F_136 ( struct V_1 * V_1 )
{
int V_79 ;
int V_2 ;
F_24 ( V_1 -> V_179 == 0 ) ;
F_34 ( V_45 L_41 , V_1 -> V_179 ) ;
F_76 ( F_13 ( V_218 ) , 0xf ) ;
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ ) {
F_31 ( V_1 -> V_25 ,
V_79 * F_13 ( V_24 ) +
F_13 ( V_219 ) ,
1 << F_2 () ) ;
F_31 ( V_1 -> V_25 ,
V_79 * F_13 ( V_24 ) +
F_13 ( V_23 ) ,
V_35 |
( 9 << V_220 ) |
( V_1 -> V_104 [ 0 ] + V_79 ) ) ;
}
F_30 ( V_1 ) ;
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ ) {
F_91 ( V_79 ,
V_35 |
( 10 << V_220 ) |
( V_1 -> V_103 [ 0 ] + V_79 ) ) ;
}
if ( V_1 -> V_132 == 0 )
V_1 -> V_132 = V_1 -> V_179 ;
F_42 ( L_42 , V_1 -> V_3 ) ;
if ( ( V_1 -> V_3 & V_221 ) && ( V_1 -> V_3 & V_4 ) ) {
F_53 ( V_1 ) ;
F_137 ( V_1 ) ;
}
F_138 ( V_1 ) ;
V_2 = F_1 ( V_1 ) ;
if ( ! ( V_1 -> V_3 & V_160 ) ) {
for ( V_79 = 0 ; V_79 < V_1 -> V_179 ; V_79 ++ ) {
T_1 V_129 = V_35 | V_79 |
( 8 << V_220 ) ;
if ( V_1 -> V_153 && F_108 ( V_79 , V_1 -> V_153 ) )
continue;
F_80 ( V_79 , F_13 ( V_112 ) , V_129 ) ;
F_80 ( V_79 , F_13 ( V_117 ) , 1 << V_2 ) ;
}
}
F_31 ( V_1 -> V_21 , F_13 ( V_222 ) , V_1 -> V_152 ) ;
if ( ! ( V_1 -> V_3 & V_223 ) )
F_31 ( V_1 -> V_21 , F_13 ( V_192 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_192 ) )
| V_224 ) ;
if ( V_1 -> V_3 & V_225 )
F_31 ( V_1 -> V_21 , F_13 ( V_192 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_192 ) )
| V_226 ) ;
F_76 ( F_13 ( V_218 ) , 0 ) ;
#ifdef F_46
V_1 -> V_58 = F_139 ( V_1 -> V_179 * sizeof( * V_1 -> V_58 ) ,
V_84 ) ;
F_24 ( V_1 -> V_58 == NULL ) ;
#endif
}
void T_3 F_140 ( struct V_1 * V_1 , T_1 V_227 )
{
T_1 V_228 ;
V_228 = F_32 ( V_1 -> V_21 , V_229 ) ;
V_228 &= ~ V_230 ;
V_228 |= F_141 ( V_227 ) ;
F_31 ( V_1 -> V_21 , V_229 , V_228 ) ;
}
void T_3 F_142 ( struct V_1 * V_1 , int V_231 )
{
unsigned long V_3 ;
T_1 V_228 ;
F_43 ( & V_232 , V_3 ) ;
V_228 = F_32 ( V_1 -> V_21 , V_229 ) ;
if ( V_231 )
V_228 |= V_233 ;
else
V_228 &= ~ V_233 ;
F_31 ( V_1 -> V_21 , V_229 , V_228 ) ;
F_45 ( & V_232 , V_3 ) ;
}
void F_116 ( unsigned int V_80 , unsigned int V_234 )
{
struct V_1 * V_1 = F_64 ( V_80 ) ;
unsigned int V_102 = F_67 ( V_80 ) ;
unsigned long V_3 ;
T_1 V_8 ;
if ( ! V_1 )
return;
F_43 ( & V_232 , V_3 ) ;
if ( F_66 ( V_1 , V_80 ) ) {
V_8 = F_92 ( V_102 - V_1 -> V_103 [ 0 ] ) &
~ V_235 ;
F_91 ( V_102 - V_1 -> V_103 [ 0 ] ,
V_8 | ( V_234 << V_220 ) ) ;
} else if ( F_68 ( V_1 , V_80 ) ) {
V_8 = F_97 ( V_102 - V_1 -> V_104 [ 0 ] ) &
~ V_235 ;
F_96 ( V_102 - V_1 -> V_104 [ 0 ] ,
V_8 | ( V_234 << V_220 ) ) ;
} else {
V_8 = F_81 ( V_102 , F_13 ( V_112 ) )
& ~ V_235 ;
F_80 ( V_102 , F_13 ( V_112 ) ,
V_8 | ( V_234 << V_220 ) ) ;
}
F_45 ( & V_232 , V_3 ) ;
}
void F_143 ( void )
{
#ifdef F_109
struct V_1 * V_1 = V_213 ;
unsigned long V_3 ;
T_1 V_236 = 1 << F_2 () ;
unsigned int V_79 ;
F_24 ( V_1 == NULL ) ;
F_42 ( L_43 , V_1 -> V_111 , F_2 () ) ;
F_43 ( & V_232 , V_3 ) ;
if ( V_237 ) {
for ( V_79 = 0 ; V_79 < V_1 -> V_179 ; V_79 ++ )
F_80 ( V_79 , F_13 ( V_117 ) ,
F_81 ( V_79 , F_13 ( V_117 ) ) | V_236 ) ;
}
F_76 ( F_13 ( V_218 ) , 0 ) ;
F_45 ( & V_232 , V_3 ) ;
#endif
}
int F_144 ( void )
{
struct V_1 * V_1 = V_213 ;
return F_77 ( F_13 ( V_218 ) ) ;
}
void F_145 ( int V_238 )
{
struct V_1 * V_1 = V_213 ;
V_238 &= V_239 ;
F_76 ( F_13 ( V_218 ) , V_238 ) ;
}
void F_146 ( int V_240 )
{
struct V_1 * V_1 = V_213 ;
unsigned long V_3 ;
T_1 V_236 = 1 << F_2 () ;
unsigned int V_79 ;
F_24 ( V_1 == NULL ) ;
F_42 ( L_44 , V_1 -> V_111 , F_2 () ) ;
F_43 ( & V_232 , V_3 ) ;
for ( V_79 = 0 ; V_79 < V_1 -> V_179 ; V_79 ++ )
F_80 ( V_79 , F_13 ( V_117 ) ,
F_81 ( V_79 , F_13 ( V_117 ) ) & ~ V_236 ) ;
F_76 ( F_13 ( V_218 ) , 0xf ) ;
F_75 ( V_1 ) ;
F_45 ( & V_232 , V_3 ) ;
}
static unsigned int F_147 ( struct V_1 * V_1 , int V_8 )
{
T_1 V_102 ;
V_102 = F_77 ( V_8 ) & F_13 ( V_144 ) ;
#ifdef F_148
F_42 ( L_45 , V_1 -> V_111 , V_8 , V_102 ) ;
#endif
if ( F_149 ( V_102 == V_1 -> V_152 ) ) {
if ( V_1 -> V_3 & V_241 )
F_75 ( V_1 ) ;
return V_242 ;
}
if ( F_149 ( V_1 -> V_153 && F_108 ( V_102 , V_1 -> V_153 ) ) ) {
F_150 ( V_243 L_46 ,
V_1 -> V_111 , ( int ) V_102 ) ;
F_75 ( V_1 ) ;
return V_242 ;
}
return F_151 ( V_1 -> V_208 , V_102 ) ;
}
unsigned int F_152 ( struct V_1 * V_1 )
{
return F_147 ( V_1 , F_13 ( V_244 ) ) ;
}
unsigned int F_153 ( void )
{
struct V_1 * V_1 = V_213 ;
F_24 ( V_1 == NULL ) ;
return F_152 ( V_1 ) ;
}
unsigned int F_154 ( void )
{
#ifdef F_155
struct V_1 * V_1 = V_213 ;
T_1 V_102 ;
F_24 ( V_1 == NULL ) ;
V_102 = F_156 ( V_245 ) ;
if ( F_149 ( V_102 == V_1 -> V_152 ) ) {
if ( V_1 -> V_3 & V_241 )
F_75 ( V_1 ) ;
return V_242 ;
}
if ( F_149 ( V_1 -> V_153 && F_108 ( V_102 , V_1 -> V_153 ) ) ) {
F_150 ( V_243 L_46 ,
V_1 -> V_111 , ( int ) V_102 ) ;
return V_242 ;
}
return F_151 ( V_1 -> V_208 , V_102 ) ;
#else
return V_242 ;
#endif
}
unsigned int F_157 ( void )
{
struct V_1 * V_1 = V_213 ;
F_24 ( V_1 == NULL ) ;
return F_147 ( V_1 , F_13 ( V_246 ) ) ;
}
void F_158 ( void )
{
struct V_1 * V_1 = V_213 ;
int V_79 ;
F_24 ( V_1 == NULL ) ;
F_34 ( V_45 L_47 ) ;
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ ) {
unsigned int V_247 = F_159 ( V_1 -> V_208 ,
V_1 -> V_103 [ 0 ] + V_79 ) ;
if ( V_247 == V_242 ) {
F_34 ( V_113 L_48 , V_248 [ V_79 ] ) ;
continue;
}
F_160 ( V_247 , V_79 ) ;
}
}
void F_161 ( int V_2 , int V_249 )
{
struct V_1 * V_1 = V_213 ;
T_1 V_250 ;
F_24 ( V_1 == NULL ) ;
if ( ( unsigned int ) V_249 > 3 ) {
F_34 ( L_49 ,
F_162 () , V_249 ) ;
return;
}
#ifdef F_163
F_42 ( L_50 , V_1 -> V_111 , V_249 ) ;
#endif
V_250 = 1 << F_63 ( V_2 ) ;
F_76 ( F_13 ( V_251 ) +
V_249 * F_13 ( V_252 ) , V_250 ) ;
}
int T_3 F_164 ( void )
{
int V_253 ;
F_42 ( L_51 ) ;
V_253 = F_165 ( V_254 ) ;
F_42 ( L_52 , V_253 ) ;
if ( V_253 > 1 )
F_158 () ;
return V_253 ;
}
void T_9 F_166 ( int V_2 )
{
F_143 () ;
}
void F_167 ( int V_2 )
{
struct V_1 * V_1 = V_213 ;
T_1 V_255 ;
int V_94 = F_63 ( V_2 ) ;
V_255 = F_32 ( V_1 -> V_21 , F_13 ( V_256 ) ) ;
V_255 |= ( 1 << V_94 ) ;
F_31 ( V_1 -> V_21 , F_13 ( V_256 ) , V_255 ) ;
F_32 ( V_1 -> V_21 , F_13 ( V_256 ) ) ;
V_255 &= ~ ( 1 << V_94 ) ;
F_31 ( V_1 -> V_21 , F_13 ( V_256 ) , V_255 ) ;
F_32 ( V_1 -> V_21 , F_13 ( V_256 ) ) ;
}
static void F_168 ( struct V_1 * V_1 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_1 -> V_179 ; V_79 ++ ) {
V_1 -> V_58 [ V_79 ] . V_257 =
F_81 ( V_79 , F_13 ( V_112 ) ) ;
V_1 -> V_58 [ V_79 ] . V_258 =
F_81 ( V_79 , F_13 ( V_117 ) ) ;
}
}
static int F_169 ( void )
{
struct V_1 * V_1 = V_212 ;
while ( V_1 ) {
F_168 ( V_1 ) ;
V_1 = V_1 -> V_90 ;
}
return 0 ;
}
static void F_170 ( struct V_1 * V_1 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_1 -> V_179 ; V_79 ++ ) {
F_80 ( V_79 , F_13 ( V_112 ) ,
V_1 -> V_58 [ V_79 ] . V_257 ) ;
F_80 ( V_79 , F_13 ( V_117 ) ,
V_1 -> V_58 [ V_79 ] . V_258 ) ;
#ifdef F_114
if ( V_1 -> V_47 ) {
struct V_48 * V_49 = & V_1 -> V_47 [ V_79 ] ;
if ( V_49 -> V_12 ) {
if ( ( V_1 -> V_58 [ V_79 ] . V_59 & 1 ) == 0 )
continue;
F_39 ( 0x10 + 2 * V_49 -> V_52 , V_49 -> V_12 + 2 ) ;
F_37 ( V_1 -> V_58 [ V_79 ] . V_59 & ~ 1 ,
V_49 -> V_12 + 4 ) ;
}
}
#endif
}
}
static void F_171 ( void )
{
struct V_1 * V_1 = V_212 ;
while ( V_1 ) {
F_170 ( V_1 ) ;
V_1 = V_1 -> V_90 ;
}
}
static int F_172 ( void )
{
F_173 ( & V_259 ) ;
return 0 ;
}
