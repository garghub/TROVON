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
static struct V_1 * F_57 ( unsigned int V_80 )
{
if ( V_80 < V_93 )
return NULL ;
return F_58 ( V_80 ) ;
}
static unsigned int F_59 ( struct V_1 * V_1 , unsigned int V_80 )
{
unsigned int V_94 = F_60 ( V_80 ) ;
return ( V_94 >= V_1 -> V_95 [ 0 ] && V_94 <= V_1 -> V_95 [ 3 ] ) ;
}
static unsigned int F_61 ( struct V_1 * V_1 , unsigned int V_80 )
{
unsigned int V_94 = F_60 ( V_80 ) ;
return ( V_94 >= V_1 -> V_96 [ 0 ] && V_94 <= V_1 -> V_96 [ 7 ] ) ;
}
static inline T_1 F_62 ( T_1 V_97 )
{
int V_79 ;
T_1 V_53 = 0 ;
for ( V_79 = 0 ; V_79 < F_63 ( 32 , V_98 ) ; ++ V_79 , V_97 >>= 1 )
V_53 |= ( V_97 & 1 ) << F_64 ( V_79 ) ;
return V_53 ;
}
static inline struct V_1 * F_65 ( struct V_99 * V_100 )
{
return F_66 ( V_100 ) ;
}
static inline struct V_1 * F_67 ( unsigned int V_80 )
{
return F_58 ( V_80 ) ;
}
static inline struct V_1 * F_68 ( struct V_99 * V_100 )
{
return F_66 ( V_100 ) ;
}
static inline void F_69 ( struct V_1 * V_1 )
{
F_70 ( F_13 ( V_101 ) , 0 ) ;
( void ) F_71 ( F_13 ( V_102 ) ) ;
}
void F_72 ( struct V_99 * V_100 )
{
unsigned int V_103 = 100000 ;
struct V_1 * V_1 = F_68 ( V_100 ) ;
unsigned int V_94 = F_73 ( V_100 ) ;
F_42 ( L_13 , V_1 , V_1 -> V_104 , V_100 -> V_80 , V_94 ) ;
F_74 ( V_94 , F_13 ( V_105 ) ,
F_75 ( V_94 , F_13 ( V_105 ) ) &
~ V_35 ) ;
do {
if ( ! V_103 -- ) {
F_34 ( V_106 L_14 ,
V_107 , V_94 ) ;
break;
}
} while( F_75 ( V_94 , F_13 ( V_105 ) ) & V_35 );
}
void F_76 ( struct V_99 * V_100 )
{
unsigned int V_103 = 100000 ;
struct V_1 * V_1 = F_68 ( V_100 ) ;
unsigned int V_94 = F_73 ( V_100 ) ;
F_42 ( L_15 , V_1 -> V_104 , V_100 -> V_80 , V_94 ) ;
F_74 ( V_94 , F_13 ( V_105 ) ,
F_75 ( V_94 , F_13 ( V_105 ) ) |
V_35 ) ;
do {
if ( ! V_103 -- ) {
F_34 ( V_106 L_14 ,
V_107 , V_94 ) ;
break;
}
} while( ! ( F_75 ( V_94 , F_13 ( V_105 ) ) & V_35 ) );
}
void F_77 ( struct V_99 * V_100 )
{
struct V_1 * V_1 = F_68 ( V_100 ) ;
#ifdef F_78
F_42 ( L_16 , V_1 -> V_104 , V_100 -> V_80 ) ;
#endif
F_69 ( V_1 ) ;
}
static void F_79 ( struct V_99 * V_100 )
{
struct V_1 * V_1 = F_68 ( V_100 ) ;
unsigned int V_94 = F_73 ( V_100 ) ;
F_72 ( V_100 ) ;
if ( F_80 ( V_100 ) )
F_36 ( V_1 , V_94 ) ;
}
static unsigned int F_81 ( struct V_99 * V_100 )
{
struct V_1 * V_1 = F_68 ( V_100 ) ;
unsigned int V_94 = F_73 ( V_100 ) ;
F_72 ( V_100 ) ;
F_41 ( V_1 , V_94 , F_80 ( V_100 ) ) ;
return 0 ;
}
static void F_82 ( struct V_99 * V_100 )
{
struct V_1 * V_1 = F_68 ( V_100 ) ;
unsigned int V_94 = F_73 ( V_100 ) ;
F_47 ( V_1 , V_94 ) ;
F_76 ( V_100 ) ;
}
static void F_83 ( struct V_99 * V_100 )
{
struct V_1 * V_1 = F_68 ( V_100 ) ;
unsigned int V_94 = F_73 ( V_100 ) ;
#ifdef F_78
F_42 ( L_16 , V_1 -> V_104 , V_100 -> V_80 ) ;
#endif
if ( F_80 ( V_100 ) )
F_36 ( V_1 , V_94 ) ;
F_69 ( V_1 ) ;
}
static void F_84 ( struct V_99 * V_100 )
{
struct V_1 * V_1 = F_65 ( V_100 ) ;
unsigned int V_94 = F_60 ( V_100 -> V_80 ) - V_1 -> V_95 [ 0 ] ;
F_42 ( L_17 , V_1 -> V_104 , V_100 -> V_80 , V_94 ) ;
F_85 ( V_94 , F_86 ( V_94 ) & ~ V_35 ) ;
}
static void F_87 ( struct V_99 * V_100 )
{
}
static void F_88 ( struct V_99 * V_100 )
{
struct V_1 * V_1 = F_65 ( V_100 ) ;
F_69 ( V_1 ) ;
}
static void F_89 ( struct V_99 * V_100 )
{
struct V_1 * V_1 = F_68 ( V_100 ) ;
unsigned int V_94 = F_60 ( V_100 -> V_80 ) - V_1 -> V_96 [ 0 ] ;
F_42 ( L_18 , V_1 -> V_104 , V_100 -> V_80 , V_94 ) ;
F_90 ( V_94 , F_91 ( V_94 ) & ~ V_35 ) ;
F_91 ( V_94 ) ;
}
static void F_92 ( struct V_99 * V_100 )
{
struct V_1 * V_1 = F_68 ( V_100 ) ;
unsigned int V_94 = F_60 ( V_100 -> V_80 ) - V_1 -> V_96 [ 0 ] ;
F_90 ( V_94 , F_91 ( V_94 ) | V_35 ) ;
F_91 ( V_94 ) ;
}
int F_93 ( struct V_99 * V_100 , const struct V_97 * V_97 ,
bool V_108 )
{
struct V_1 * V_1 = F_68 ( V_100 ) ;
unsigned int V_94 = F_73 ( V_100 ) ;
if ( V_1 -> V_3 & V_109 ) {
int V_110 = F_94 ( V_97 ) ;
F_74 ( V_94 , F_13 ( V_111 ) , 1 << V_110 ) ;
} else {
T_1 V_53 = F_95 ( V_97 ) [ 0 ] ;
V_53 &= F_95 ( V_112 ) [ 0 ] ;
F_74 ( V_94 , F_13 ( V_111 ) ,
F_62 ( V_53 ) ) ;
}
return 0 ;
}
static unsigned int F_96 ( struct V_1 * V_1 , unsigned int type )
{
switch( type & V_113 ) {
case V_114 :
return F_13 ( V_115 ) |
F_13 ( V_116 ) ;
case V_117 :
case V_118 :
return F_13 ( V_115 ) |
F_13 ( V_119 ) ;
case V_120 :
return F_13 ( V_121 ) |
F_13 ( V_116 ) ;
case V_122 :
default:
return F_13 ( V_121 ) |
F_13 ( V_119 ) ;
}
}
int F_97 ( struct V_99 * V_100 , unsigned int V_123 )
{
struct V_1 * V_1 = F_68 ( V_100 ) ;
unsigned int V_94 = F_73 ( V_100 ) ;
unsigned int V_124 , V_125 , V_126 ;
F_42 ( L_19 ,
V_1 , V_100 -> V_80 , V_94 , V_123 ) ;
if ( V_94 >= V_1 -> V_127 )
return - V_128 ;
if ( V_123 == V_129 )
if ( V_1 -> V_130 && V_94 < V_1 -> V_131 )
V_123 = V_1 -> V_130 [ V_94 ] ;
if ( V_123 == V_129 )
V_123 = V_122 ;
F_98 ( V_100 , V_123 ) ;
if ( F_35 ( V_1 , V_94 ) )
V_124 = V_132 |
V_133 ;
else
V_124 = F_96 ( V_1 , V_123 ) ;
V_125 = F_75 ( V_94 , F_13 ( V_105 ) ) ;
V_126 = V_125 & ~ ( F_13 ( V_134 ) |
F_13 ( V_135 ) ) ;
V_126 |= V_124 ;
if ( V_125 != V_126 )
F_74 ( V_94 , F_13 ( V_105 ) , V_126 ) ;
return V_136 ; ;
}
void F_99 ( unsigned int V_137 , unsigned int V_138 )
{
struct V_1 * V_1 = F_67 ( V_137 ) ;
unsigned int V_94 = F_60 ( V_137 ) ;
unsigned int V_124 ;
F_42 ( L_20 ,
V_1 , V_137 , V_94 , V_138 ) ;
if ( V_94 >= V_1 -> V_127 )
return;
V_124 = F_75 ( V_94 , F_13 ( V_105 ) ) ;
V_124 = V_124 & ~ F_13 ( V_139 ) ;
V_124 |= V_138 ;
F_74 ( V_94 , F_13 ( V_105 ) , V_124 ) ;
}
void F_100 ( unsigned int V_137 , unsigned int V_110 )
{
struct V_1 * V_1 = F_67 ( V_137 ) ;
unsigned int V_94 = F_60 ( V_137 ) ;
F_42 ( L_21 ,
V_1 , V_137 , V_94 , V_110 ) ;
if ( V_94 >= V_1 -> V_127 )
return;
F_74 ( V_94 , F_13 ( V_111 ) , 1 << V_110 ) ;
}
static int F_101 ( struct V_140 * V_141 , struct V_40 * V_41 )
{
return V_141 -> V_142 == NULL || V_141 -> V_142 == V_41 ;
}
static int F_102 ( struct V_140 * V_141 , unsigned int V_137 ,
T_8 V_143 )
{
struct V_1 * V_1 = V_141 -> V_144 ;
struct V_145 * V_146 ;
F_42 ( L_22 , V_137 , V_143 ) ;
if ( V_143 == V_1 -> V_147 )
return - V_128 ;
if ( V_1 -> V_148 && F_103 ( V_143 , V_1 -> V_148 ) )
return - V_128 ;
#ifdef F_104
else if ( V_143 >= V_1 -> V_95 [ 0 ] ) {
F_105 ( ! ( V_1 -> V_3 & V_4 ) ) ;
F_42 ( L_23 ) ;
F_106 ( V_137 , V_1 ) ;
F_107 ( V_137 , & V_1 -> V_149 ,
V_150 ) ;
return 0 ;
}
#endif
if ( V_143 >= V_1 -> V_96 [ 0 ] && V_143 <= V_1 -> V_96 [ 7 ] ) {
F_105 ( ! ( V_1 -> V_3 & V_4 ) ) ;
F_42 ( L_24 ) ;
F_106 ( V_137 , V_1 ) ;
F_107 ( V_137 , & V_1 -> V_151 ,
V_152 ) ;
return 0 ;
}
if ( V_143 >= V_1 -> V_127 )
return - V_128 ;
F_108 ( V_1 , V_143 ) ;
V_146 = & V_1 -> V_153 ;
#ifdef F_109
if ( F_35 ( V_1 , V_143 ) )
V_146 = & V_1 -> V_154 ;
#endif
F_42 ( L_25 , V_146 ) ;
F_106 ( V_137 , V_1 ) ;
F_107 ( V_137 , V_146 , V_152 ) ;
F_110 ( V_137 , V_129 ) ;
if ( ! F_59 ( V_1 , V_143 ) && ( V_1 -> V_3 & V_155 ) ) {
F_99 ( V_137 , V_143 ) ;
F_100 ( V_137 , F_1 ( V_1 ) ) ;
F_111 ( V_137 , 8 ) ;
}
return 0 ;
}
static int F_112 ( struct V_140 * V_141 , struct V_40 * V_156 ,
const T_1 * V_157 , unsigned int V_158 ,
T_8 * V_159 , unsigned int * V_160 )
{
struct V_1 * V_1 = V_141 -> V_144 ;
static unsigned char V_161 [ 4 ] = {
V_114 ,
V_122 ,
V_120 ,
V_117 ,
} ;
* V_159 = V_157 [ 0 ] ;
if ( V_158 >= 4 && ( V_1 -> V_3 & V_162 ) ) {
switch ( V_157 [ 2 ] ) {
case 0 :
case 1 :
break;
case 2 :
if ( V_157 [ 0 ] >= F_113 ( V_1 -> V_95 ) )
return - V_128 ;
* V_159 = V_1 -> V_95 [ V_157 [ 0 ] ] ;
break;
case 3 :
if ( V_157 [ 0 ] >= F_113 ( V_1 -> V_96 ) )
return - V_128 ;
* V_159 = V_1 -> V_96 [ V_157 [ 0 ] ] ;
break;
default:
F_114 ( L_26 ,
V_107 , V_157 [ 2 ] ) ;
return - V_128 ;
}
* V_160 = V_161 [ V_157 [ 1 ] & 3 ] ;
} else if ( V_158 > 1 ) {
T_1 V_53 = 0x3 ;
if ( F_115 ( V_163 ) )
V_53 = 0x1 ;
* V_160 = V_161 [ V_157 [ 1 ] & V_53 ] ;
} else
* V_160 = V_129 ;
F_42 ( L_27 ,
V_158 , V_157 [ 0 ] , V_157 [ 1 ] , * V_159 , * V_160 ) ;
return 0 ;
}
static int F_116 ( struct V_40 * V_41 )
{
return V_41 && F_26 ( V_41 , L_28 , NULL ) ;
}
struct V_1 * T_3 F_117 ( struct V_40 * V_41 ,
T_2 V_38 ,
unsigned int V_3 ,
unsigned int V_164 ,
unsigned int V_127 ,
const char * V_104 )
{
struct V_1 * V_1 ;
T_1 V_165 ;
const char * V_166 ;
int V_79 ;
int V_167 ;
T_6 V_168 = V_38 ;
V_1 = F_54 ( sizeof( struct V_1 ) , V_84 ) ;
if ( V_1 == NULL )
return NULL ;
V_1 -> V_104 = V_104 ;
V_1 -> V_153 = V_169 ;
V_1 -> V_153 . V_104 = V_104 ;
if ( V_3 & V_4 )
V_1 -> V_153 . V_170 = F_93 ;
#ifdef F_109
V_1 -> V_154 = V_171 ;
V_1 -> V_154 . V_104 = V_104 ;
if ( V_3 & V_4 )
V_1 -> V_154 . V_170 = F_93 ;
#endif
#ifdef F_104
V_1 -> V_149 = V_172 ;
V_1 -> V_149 . V_104 = V_104 ;
#endif
V_1 -> V_151 = V_173 ;
V_1 -> V_151 . V_104 = V_104 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_164 = V_164 ;
V_1 -> V_127 = V_127 ;
V_1 -> V_174 = 0 ;
if ( V_3 & V_175 )
V_167 = 2047 ;
else
V_167 = 255 ;
V_1 -> V_96 [ 0 ] = V_167 - 12 ;
V_1 -> V_96 [ 1 ] = V_167 - 11 ;
V_1 -> V_96 [ 2 ] = V_167 - 10 ;
V_1 -> V_96 [ 3 ] = V_167 - 9 ;
V_1 -> V_96 [ 4 ] = V_167 - 8 ;
V_1 -> V_96 [ 5 ] = V_167 - 7 ;
V_1 -> V_96 [ 6 ] = V_167 - 6 ;
V_1 -> V_96 [ 7 ] = V_167 - 5 ;
V_1 -> V_95 [ 0 ] = V_167 - 4 ;
V_1 -> V_95 [ 1 ] = V_167 - 3 ;
V_1 -> V_95 [ 2 ] = V_167 - 2 ;
V_1 -> V_95 [ 3 ] = V_167 - 1 ;
V_1 -> V_147 = V_167 ;
if ( V_41 && F_26 ( V_41 , L_29 , NULL ) != NULL )
V_1 -> V_3 |= V_176 ;
if ( V_41 && F_118 ( V_41 , L_30 ) )
V_1 -> V_3 |= V_162 ;
if ( V_41 ) {
int V_177 ;
unsigned int V_178 , V_179 ;
const T_1 * V_180 =
F_26 ( V_41 , L_31 , & V_177 ) ;
if ( V_180 ) {
V_177 /= 4 ;
V_178 = V_167 + 1 ;
V_179 = F_119 ( V_178 ) * sizeof( unsigned long ) ;
V_1 -> V_148 = F_54 ( V_179 , V_84 ) ;
F_24 ( V_1 -> V_148 == NULL ) ;
for ( V_79 = 0 ; V_79 < V_177 ; V_79 ++ ) {
if ( V_180 [ V_79 ] > V_167 )
continue;
F_120 ( V_180 [ V_79 ] , V_1 -> V_148 ) ;
}
}
}
#ifdef F_121
V_1 -> V_181 = V_182 [ F_122 ( V_3 ) ] ;
#endif
V_1 -> V_16 = ( V_3 & V_176 ) ?
V_11 : V_13 ;
F_24 ( V_168 == 0 && V_41 == NULL ) ;
if ( V_168 == 0 && F_26 ( V_41 , L_1 , NULL ) != NULL ) {
#ifdef F_4
V_1 -> V_3 |= V_43 ;
V_1 -> V_16 = V_9 ;
#else
F_123 () ;
#endif
}
if ( V_168 == 0 && ! ( V_1 -> V_3 & V_43 ) ) {
const T_1 * V_8 = F_26 ( V_41 , L_32 , NULL ) ;
F_24 ( V_8 == NULL ) ;
V_168 = F_124 ( V_41 , V_8 ) ;
F_24 ( V_168 == V_183 ) ;
}
F_29 ( V_1 , V_41 , V_168 , & V_1 -> V_21 , F_13 ( V_184 ) , 0x1000 ) ;
F_29 ( V_1 , V_41 , V_168 , & V_1 -> V_25 , F_13 ( V_185 ) , 0x1000 ) ;
if ( F_116 ( V_41 ) )
V_1 -> V_3 |= V_155 ;
if ( ( V_3 & V_186 ) && ! ( V_1 -> V_3 & V_155 ) ) {
F_34 ( V_76 L_33 ) ;
F_31 ( V_1 -> V_21 , F_13 ( V_187 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_187 ) )
| V_188 ) ;
while( F_32 ( V_1 -> V_21 , F_13 ( V_187 ) )
& V_188 )
F_125 () ;
}
if ( V_3 & V_189 )
F_31 ( V_1 -> V_21 , F_13 ( V_187 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_187 ) )
| V_190 ) ;
if ( V_3 & V_191 )
F_31 ( V_1 -> V_21 , F_13 ( V_187 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_187 ) )
| V_192 ) ;
V_165 = F_32 ( V_1 -> V_21 , F_13 ( V_193 ) ) ;
if ( V_164 == 0 ) {
if ( V_3 & V_194 )
V_1 -> V_174 = V_1 -> V_127 ;
else
V_1 -> V_174 =
( ( V_165 & V_195 )
>> V_196 ) + 1 ;
}
F_24 ( F_126 () > V_197 ) ;
F_127 (i) {
unsigned int V_2 = F_64 ( V_79 ) ;
F_29 ( V_1 , V_41 , V_168 , & V_1 -> V_26 [ V_2 ] ,
F_13 ( V_198 ) + V_2 * F_13 ( V_199 ) ,
0x1000 ) ;
}
if ( V_1 -> V_164 == 0 ) {
V_1 -> V_164 = V_1 -> V_174 ;
F_29 ( V_1 , V_41 , V_168 , & V_1 -> V_33 [ 0 ] ,
F_13 ( V_200 ) , F_13 ( V_34 ) * V_1 -> V_164 ) ;
}
V_1 -> V_29 = 1 + F_128 ( V_1 -> V_164 - 1 ) ;
V_1 -> V_31 = ( 1 << V_1 -> V_29 ) - 1 ;
V_1 -> V_201 = F_129 ( V_41 , V_202 ,
V_164 ? V_164 : V_1 -> V_174 ,
& V_203 ,
V_3 & V_175 ? 2048 : 256 ) ;
if ( V_1 -> V_201 == NULL )
return NULL ;
V_1 -> V_201 -> V_144 = V_1 ;
switch ( V_165 & V_204 ) {
case 1 :
V_166 = L_34 ;
break;
case 2 :
V_166 = L_35 ;
break;
case 3 :
V_166 = L_36 ;
break;
default:
V_166 = L_37 ;
break;
}
F_34 ( V_45 L_38
L_39 ,
V_104 , V_166 , ( unsigned long long ) V_168 , F_126 () ) ;
F_34 ( V_45 L_40 ,
V_1 -> V_164 , V_1 -> V_29 , V_1 -> V_31 ) ;
V_1 -> V_90 = V_205 ;
V_205 = V_1 ;
if ( V_3 & V_4 ) {
V_206 = V_1 ;
F_130 ( V_1 -> V_201 ) ;
}
return V_1 ;
}
void T_3 F_131 ( struct V_1 * V_1 , unsigned int V_207 ,
T_2 V_168 )
{
unsigned int V_208 = V_207 * V_1 -> V_164 ;
F_24 ( V_207 >= V_209 ) ;
F_29 ( V_1 , V_1 -> V_201 -> V_142 ,
V_168 , & V_1 -> V_33 [ V_207 ] , 0 ,
F_13 ( V_34 ) * V_1 -> V_164 ) ;
if ( ( V_208 + V_1 -> V_164 ) > V_1 -> V_174 )
V_1 -> V_174 = V_208 + V_1 -> V_164 ;
}
void T_3 F_132 ( struct V_1 * V_1 , T_4 * V_130 , int V_210 )
{
V_1 -> V_130 = V_130 ;
V_1 -> V_131 = V_210 ;
}
void T_3 F_133 ( struct V_1 * V_1 )
{
int V_79 ;
int V_2 ;
F_24 ( V_1 -> V_174 == 0 ) ;
F_34 ( V_45 L_41 , V_1 -> V_174 ) ;
F_70 ( F_13 ( V_211 ) , 0xf ) ;
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ ) {
F_31 ( V_1 -> V_25 ,
V_79 * F_13 ( V_24 ) +
F_13 ( V_212 ) ,
1 << F_2 () ) ;
F_31 ( V_1 -> V_25 ,
V_79 * F_13 ( V_24 ) +
F_13 ( V_23 ) ,
V_35 |
( 9 << V_213 ) |
( V_1 -> V_96 [ 0 ] + V_79 ) ) ;
}
F_30 ( V_1 ) ;
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ ) {
F_85 ( V_79 ,
V_35 |
( 10 << V_213 ) |
( V_1 -> V_95 [ 0 ] + V_79 ) ) ;
}
if ( V_1 -> V_127 == 0 )
V_1 -> V_127 = V_1 -> V_174 ;
F_42 ( L_42 , V_1 -> V_3 ) ;
if ( ( V_1 -> V_3 & V_214 ) && ( V_1 -> V_3 & V_4 ) ) {
F_53 ( V_1 ) ;
F_134 ( V_1 ) ;
}
F_135 ( V_1 ) ;
V_2 = F_1 ( V_1 ) ;
if ( ! ( V_1 -> V_3 & V_155 ) ) {
for ( V_79 = 0 ; V_79 < V_1 -> V_174 ; V_79 ++ ) {
T_1 V_124 = V_35 | V_79 |
( 8 << V_213 ) ;
if ( V_1 -> V_148 && F_103 ( V_79 , V_1 -> V_148 ) )
continue;
F_74 ( V_79 , F_13 ( V_105 ) , V_124 ) ;
F_74 ( V_79 , F_13 ( V_111 ) , 1 << V_2 ) ;
}
}
F_31 ( V_1 -> V_21 , F_13 ( V_215 ) , V_1 -> V_147 ) ;
if ( ! ( V_1 -> V_3 & V_216 ) )
F_31 ( V_1 -> V_21 , F_13 ( V_187 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_187 ) )
| V_217 ) ;
if ( V_1 -> V_3 & V_218 )
F_31 ( V_1 -> V_21 , F_13 ( V_187 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_187 ) )
| V_219 ) ;
F_70 ( F_13 ( V_211 ) , 0 ) ;
#ifdef F_46
V_1 -> V_58 = F_136 ( V_1 -> V_174 * sizeof( * V_1 -> V_58 ) ,
V_84 ) ;
F_24 ( V_1 -> V_58 == NULL ) ;
#endif
}
void T_3 F_137 ( struct V_1 * V_1 , T_1 V_220 )
{
T_1 V_221 ;
V_221 = F_32 ( V_1 -> V_21 , V_222 ) ;
V_221 &= ~ V_223 ;
V_221 |= F_138 ( V_220 ) ;
F_31 ( V_1 -> V_21 , V_222 , V_221 ) ;
}
void T_3 F_139 ( struct V_1 * V_1 , int V_224 )
{
unsigned long V_3 ;
T_1 V_221 ;
F_43 ( & V_225 , V_3 ) ;
V_221 = F_32 ( V_1 -> V_21 , V_222 ) ;
if ( V_224 )
V_221 |= V_226 ;
else
V_221 &= ~ V_226 ;
F_31 ( V_1 -> V_21 , V_222 , V_221 ) ;
F_45 ( & V_225 , V_3 ) ;
}
void F_111 ( unsigned int V_80 , unsigned int V_227 )
{
struct V_1 * V_1 = F_57 ( V_80 ) ;
unsigned int V_94 = F_60 ( V_80 ) ;
unsigned long V_3 ;
T_1 V_8 ;
if ( ! V_1 )
return;
F_43 ( & V_225 , V_3 ) ;
if ( F_59 ( V_1 , V_80 ) ) {
V_8 = F_86 ( V_94 - V_1 -> V_95 [ 0 ] ) &
~ V_228 ;
F_85 ( V_94 - V_1 -> V_95 [ 0 ] ,
V_8 | ( V_227 << V_213 ) ) ;
} else if ( F_61 ( V_1 , V_80 ) ) {
V_8 = F_91 ( V_94 - V_1 -> V_96 [ 0 ] ) &
~ V_228 ;
F_90 ( V_94 - V_1 -> V_96 [ 0 ] ,
V_8 | ( V_227 << V_213 ) ) ;
} else {
V_8 = F_75 ( V_94 , F_13 ( V_105 ) )
& ~ V_228 ;
F_74 ( V_94 , F_13 ( V_105 ) ,
V_8 | ( V_227 << V_213 ) ) ;
}
F_45 ( & V_225 , V_3 ) ;
}
void F_140 ( void )
{
#ifdef F_104
struct V_1 * V_1 = V_206 ;
unsigned long V_3 ;
T_1 V_229 = 1 << F_2 () ;
unsigned int V_79 ;
F_24 ( V_1 == NULL ) ;
F_42 ( L_43 , V_1 -> V_104 , F_2 () ) ;
F_43 ( & V_225 , V_3 ) ;
if ( V_230 ) {
for ( V_79 = 0 ; V_79 < V_1 -> V_174 ; V_79 ++ )
F_74 ( V_79 , F_13 ( V_111 ) ,
F_75 ( V_79 , F_13 ( V_111 ) ) | V_229 ) ;
}
F_70 ( F_13 ( V_211 ) , 0 ) ;
F_45 ( & V_225 , V_3 ) ;
#endif
}
int F_141 ( void )
{
struct V_1 * V_1 = V_206 ;
return F_71 ( F_13 ( V_211 ) ) ;
}
void F_142 ( int V_231 )
{
struct V_1 * V_1 = V_206 ;
V_231 &= V_232 ;
F_70 ( F_13 ( V_211 ) , V_231 ) ;
}
void F_143 ( int V_233 )
{
struct V_1 * V_1 = V_206 ;
unsigned long V_3 ;
T_1 V_229 = 1 << F_2 () ;
unsigned int V_79 ;
F_24 ( V_1 == NULL ) ;
F_42 ( L_44 , V_1 -> V_104 , F_2 () ) ;
F_43 ( & V_225 , V_3 ) ;
for ( V_79 = 0 ; V_79 < V_1 -> V_174 ; V_79 ++ )
F_74 ( V_79 , F_13 ( V_111 ) ,
F_75 ( V_79 , F_13 ( V_111 ) ) & ~ V_229 ) ;
F_70 ( F_13 ( V_211 ) , 0xf ) ;
F_69 ( V_1 ) ;
F_45 ( & V_225 , V_3 ) ;
}
static unsigned int F_144 ( struct V_1 * V_1 , int V_8 )
{
T_1 V_94 ;
V_94 = F_71 ( V_8 ) & F_13 ( V_139 ) ;
#ifdef F_145
F_42 ( L_45 , V_1 -> V_104 , V_8 , V_94 ) ;
#endif
if ( F_146 ( V_94 == V_1 -> V_147 ) ) {
if ( V_1 -> V_3 & V_234 )
F_69 ( V_1 ) ;
return V_235 ;
}
if ( F_146 ( V_1 -> V_148 && F_103 ( V_94 , V_1 -> V_148 ) ) ) {
F_147 ( V_236 L_46 ,
V_1 -> V_104 , ( int ) V_94 ) ;
F_69 ( V_1 ) ;
return V_235 ;
}
return F_148 ( V_1 -> V_201 , V_94 ) ;
}
unsigned int F_149 ( struct V_1 * V_1 )
{
return F_144 ( V_1 , F_13 ( V_237 ) ) ;
}
unsigned int F_150 ( void )
{
struct V_1 * V_1 = V_206 ;
F_24 ( V_1 == NULL ) ;
return F_149 ( V_1 ) ;
}
unsigned int F_151 ( void )
{
#ifdef F_152
struct V_1 * V_1 = V_206 ;
T_1 V_94 ;
F_24 ( V_1 == NULL ) ;
V_94 = F_153 ( V_238 ) ;
if ( F_146 ( V_94 == V_1 -> V_147 ) ) {
if ( V_1 -> V_3 & V_234 )
F_69 ( V_1 ) ;
return V_235 ;
}
if ( F_146 ( V_1 -> V_148 && F_103 ( V_94 , V_1 -> V_148 ) ) ) {
F_147 ( V_236 L_46 ,
V_1 -> V_104 , ( int ) V_94 ) ;
return V_235 ;
}
return F_148 ( V_1 -> V_201 , V_94 ) ;
#else
return V_235 ;
#endif
}
unsigned int F_154 ( void )
{
struct V_1 * V_1 = V_206 ;
F_24 ( V_1 == NULL ) ;
return F_144 ( V_1 , F_13 ( V_239 ) ) ;
}
void F_155 ( void )
{
struct V_1 * V_1 = V_206 ;
int V_79 ;
F_24 ( V_1 == NULL ) ;
F_34 ( V_45 L_47 ) ;
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ ) {
unsigned int V_240 = F_156 ( V_1 -> V_201 ,
V_1 -> V_95 [ 0 ] + V_79 ) ;
if ( V_240 == V_235 ) {
F_34 ( V_106 L_48 , V_241 [ V_79 ] ) ;
continue;
}
F_157 ( V_240 , V_79 ) ;
}
}
void F_158 ( int V_2 , int V_242 )
{
struct V_1 * V_1 = V_206 ;
T_1 V_243 ;
F_24 ( V_1 == NULL ) ;
if ( ( unsigned int ) V_242 > 3 ) {
F_34 ( L_49 ,
F_159 () , V_242 ) ;
return;
}
#ifdef F_160
F_42 ( L_50 , V_1 -> V_104 , V_242 ) ;
#endif
V_243 = 1 << F_64 ( V_2 ) ;
F_70 ( F_13 ( V_244 ) +
V_242 * F_13 ( V_245 ) , V_243 ) ;
}
int T_3 F_161 ( void )
{
int V_246 ;
F_42 ( L_51 ) ;
V_246 = F_162 ( V_247 ) ;
F_42 ( L_52 , V_246 ) ;
if ( V_246 > 1 )
F_155 () ;
return V_246 ;
}
void T_9 F_163 ( int V_2 )
{
F_140 () ;
}
void F_164 ( int V_2 )
{
struct V_1 * V_1 = V_206 ;
T_1 V_248 ;
int V_110 = F_64 ( V_2 ) ;
int V_79 ;
V_248 = F_32 ( V_1 -> V_21 , F_13 ( V_249 ) ) ;
V_248 |= ( 1 << V_110 ) ;
F_31 ( V_1 -> V_21 , F_13 ( V_249 ) , V_248 ) ;
F_32 ( V_1 -> V_21 , F_13 ( V_249 ) ) ;
V_248 &= ~ ( 1 << V_110 ) ;
F_31 ( V_1 -> V_21 , F_13 ( V_249 ) , V_248 ) ;
F_32 ( V_1 -> V_21 , F_13 ( V_249 ) ) ;
if ( V_1 -> V_3 & V_162 ) {
for ( V_79 = 0 ; V_79 < 15 ; V_79 ++ ) {
F_8 ( V_1 -> V_16 , & V_1 -> V_26 [ V_110 ] ,
V_250 , 0 ) ;
}
}
}
static void F_165 ( struct V_1 * V_1 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_1 -> V_174 ; V_79 ++ ) {
V_1 -> V_58 [ V_79 ] . V_251 =
F_75 ( V_79 , F_13 ( V_105 ) ) ;
V_1 -> V_58 [ V_79 ] . V_252 =
F_75 ( V_79 , F_13 ( V_111 ) ) ;
}
}
static int F_166 ( void )
{
struct V_1 * V_1 = V_205 ;
while ( V_1 ) {
F_165 ( V_1 ) ;
V_1 = V_1 -> V_90 ;
}
return 0 ;
}
static void F_167 ( struct V_1 * V_1 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_1 -> V_174 ; V_79 ++ ) {
F_74 ( V_79 , F_13 ( V_105 ) ,
V_1 -> V_58 [ V_79 ] . V_251 ) ;
F_74 ( V_79 , F_13 ( V_111 ) ,
V_1 -> V_58 [ V_79 ] . V_252 ) ;
#ifdef F_109
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
static void F_168 ( void )
{
struct V_1 * V_1 = V_205 ;
while ( V_1 ) {
F_167 ( V_1 ) ;
V_1 = V_1 -> V_90 ;
}
}
static int F_169 ( void )
{
F_170 ( & V_253 ) ;
return 0 ;
}
