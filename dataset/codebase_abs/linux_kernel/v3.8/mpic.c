static inline unsigned int F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 = 0 ;
if ( ! ( V_1 -> V_3 & V_4 ) )
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
static inline unsigned int F_15 ( struct V_1 * V_1 , unsigned int V_22 )
{
return ( V_22 >> 2 ) * V_23 +
( V_22 & 3 ) * F_13 ( V_24 ) ;
}
static inline T_1 F_16 ( struct V_1 * V_1 , unsigned int V_22 )
{
unsigned int V_17 = F_15 ( V_1 , V_22 ) +
F_13 ( V_25 ) ;
return F_3 ( V_1 -> V_16 , & V_1 -> V_26 , V_17 ) ;
}
static inline void F_17 ( struct V_1 * V_1 , unsigned int V_22 , T_1 V_14 )
{
unsigned int V_17 = F_15 ( V_1 , V_22 ) +
F_13 ( V_25 ) ;
F_8 ( V_1 -> V_16 , & V_1 -> V_26 , V_17 , V_14 ) ;
}
static inline T_1 F_18 ( struct V_1 * V_1 , unsigned int V_8 )
{
unsigned int V_2 = F_1 ( V_1 ) ;
return F_3 ( V_1 -> V_16 , & V_1 -> V_27 [ V_2 ] , V_8 ) ;
}
static inline void F_19 ( struct V_1 * V_1 , unsigned int V_8 , T_1 V_14 )
{
unsigned int V_2 = F_1 ( V_1 ) ;
F_8 ( V_1 -> V_16 , & V_1 -> V_27 [ V_2 ] , V_8 , V_14 ) ;
}
static inline T_1 F_20 ( struct V_1 * V_1 , unsigned int V_28 , unsigned int V_8 )
{
unsigned int V_29 = V_28 >> V_1 -> V_30 ;
unsigned int V_31 = V_28 & V_1 -> V_32 ;
unsigned int V_33 ;
V_33 = F_3 ( V_1 -> V_16 , & V_1 -> V_34 [ V_29 ] ,
V_8 + ( V_31 * F_13 ( V_35 ) ) ) ;
#ifdef F_21
if ( V_8 == 0 )
V_33 = ( V_33 & ( V_36 | V_37 ) ) |
V_1 -> V_38 [ V_28 ] ;
#endif
return V_33 ;
}
static inline void F_22 ( struct V_1 * V_1 , unsigned int V_28 ,
unsigned int V_8 , T_1 V_14 )
{
unsigned int V_29 = V_28 >> V_1 -> V_30 ;
unsigned int V_31 = V_28 & V_1 -> V_32 ;
F_8 ( V_1 -> V_16 , & V_1 -> V_34 [ V_29 ] ,
V_8 + ( V_31 * F_13 ( V_35 ) ) , V_14 ) ;
#ifdef F_21
if ( V_8 == 0 )
V_1 -> V_38 [ V_28 ] =
V_14 & ~ ( V_36 | V_37 ) ;
#endif
}
static void F_23 ( struct V_1 * V_1 , T_2 V_39 ,
struct V_6 * V_7 , unsigned int V_17 ,
unsigned int V_40 )
{
V_7 -> V_12 = F_24 ( V_39 + V_17 , V_40 ) ;
F_25 ( V_7 -> V_12 == NULL ) ;
}
static void F_26 ( struct V_1 * V_1 , struct V_6 * V_7 ,
unsigned int V_17 , unsigned int V_40 )
{
T_2 V_39 = F_27 ( V_1 -> V_41 , 0 ) ;
V_7 -> V_10 = F_28 ( V_1 -> V_41 , V_39 + V_17 , V_40 ) ;
F_25 ( ! F_29 ( V_7 -> V_10 ) ) ;
}
static inline void F_30 ( struct V_1 * V_1 ,
T_2 V_39 , struct V_6 * V_7 ,
unsigned int V_17 , unsigned int V_40 )
{
if ( V_1 -> V_3 & V_42 )
F_26 ( V_1 , V_7 , V_17 , V_40 ) ;
else
F_23 ( V_1 , V_39 , V_7 , V_17 , V_40 ) ;
}
static void T_3 F_31 ( struct V_1 * V_1 )
{
T_1 V_43 ;
F_32 ( V_1 -> V_21 , F_13 ( V_18 ) , V_36 ) ;
V_43 = F_33 ( V_1 -> V_21 , F_13 ( V_18 ) ) ;
if ( V_43 == F_34 ( V_36 ) ) {
F_35 ( V_44 L_1 ) ;
V_1 -> V_3 |= V_20 ;
}
}
static inline int F_36 ( struct V_1 * V_1 , unsigned int V_45 )
{
if ( V_45 >= 128 || ! V_1 -> V_46 )
return 0 ;
return V_1 -> V_46 [ V_45 ] . V_12 != NULL ;
}
static inline void F_37 ( struct V_1 * V_1 , unsigned int V_45 )
{
struct V_47 * V_48 = & V_1 -> V_46 [ V_45 ] ;
if ( V_48 -> V_49 ) {
unsigned int V_50 = ( V_48 -> V_51 >> 3 ) & ~ 3 ;
unsigned int V_52 = 1U << ( V_48 -> V_51 & 0x1f ) ;
F_38 ( V_52 , V_48 -> V_49 + V_50 ) ;
} else {
F_39 ( & V_1 -> V_53 ) ;
F_40 ( 0x11 + 2 * V_48 -> V_51 , V_48 -> V_12 + 2 ) ;
F_38 ( V_48 -> V_54 , V_48 -> V_12 + 4 ) ;
F_41 ( & V_1 -> V_53 ) ;
}
}
static void F_42 ( struct V_1 * V_1 , unsigned int V_45 ,
bool V_55 )
{
struct V_47 * V_48 = & V_1 -> V_46 [ V_45 ] ;
unsigned long V_3 ;
T_1 V_56 ;
if ( V_48 -> V_12 == NULL )
return;
F_43 ( L_2 ,
V_45 , V_48 -> V_51 ) ;
F_44 ( & V_1 -> V_53 , V_3 ) ;
F_40 ( 0x10 + 2 * V_48 -> V_51 , V_48 -> V_12 + 2 ) ;
V_56 = F_45 ( V_48 -> V_12 + 4 ) ;
V_56 &= ~ ( 0x23U ) ;
if ( V_55 )
V_56 |= 0x22 ;
F_38 ( V_56 , V_48 -> V_12 + 4 ) ;
F_46 ( & V_1 -> V_53 , V_3 ) ;
#ifdef F_47
V_1 -> V_57 [ V_45 ] . V_58 = V_56 | 1 ;
#endif
}
static void F_48 ( struct V_1 * V_1 , unsigned int V_45 )
{
struct V_47 * V_48 = & V_1 -> V_46 [ V_45 ] ;
unsigned long V_3 ;
T_1 V_56 ;
if ( V_48 -> V_12 == NULL )
return;
F_43 ( L_3 , V_45 ) ;
F_44 ( & V_1 -> V_53 , V_3 ) ;
F_40 ( 0x10 + 2 * V_48 -> V_51 , V_48 -> V_12 + 2 ) ;
V_56 = F_45 ( V_48 -> V_12 + 4 ) ;
V_56 |= 1 ;
F_38 ( V_56 , V_48 -> V_12 + 4 ) ;
F_46 ( & V_1 -> V_53 , V_3 ) ;
#ifdef F_47
V_1 -> V_57 [ V_45 ] . V_58 = V_56 & ~ 1 ;
#endif
}
static void T_3 F_49 ( struct V_1 * V_1 , T_4 T_5 * V_59 ,
unsigned int V_60 )
{
T_4 T_5 * V_12 ;
T_4 V_61 , V_3 ;
T_6 V_62 = 0 ;
for ( V_61 = F_50 ( V_59 + V_63 ) ; V_61 != 0 ;
V_61 = F_50 ( V_59 + V_61 + V_64 ) ) {
T_4 V_65 = F_50 ( V_59 + V_61 + V_66 ) ;
if ( V_65 == V_67 ) {
V_65 = F_50 ( V_59 + V_61 + 3 ) ;
if ( ( V_65 & V_68 ) == V_69 )
break;
}
}
if ( V_61 == 0 )
return;
V_12 = V_59 + V_61 ;
V_3 = F_50 ( V_12 + V_70 ) ;
if ( ! ( V_3 & V_71 ) ) {
V_62 = F_45 ( V_12 + V_72 ) & V_73 ;
V_62 = V_62 | ( ( T_6 ) F_45 ( V_12 + V_74 ) << 32 ) ;
}
F_35 ( V_75 L_4 ,
F_51 ( V_60 ) , F_52 ( V_60 ) ,
V_3 & V_76 ? L_5 : L_6 , V_62 ) ;
if ( ! ( V_3 & V_76 ) )
F_40 ( V_3 | V_76 , V_12 + V_70 ) ;
}
static void T_3 F_49 ( struct V_1 * V_1 , T_4 T_5 * V_59 ,
unsigned int V_60 )
{
return;
}
static void T_3 F_53 ( struct V_1 * V_1 , T_4 T_5 * V_59 ,
unsigned int V_60 , T_1 V_77 )
{
int V_78 , V_79 , V_80 ;
T_4 T_5 * V_12 ;
T_1 V_56 ;
T_4 V_61 ;
for ( V_61 = F_50 ( V_59 + V_63 ) ; V_61 != 0 ;
V_61 = F_50 ( V_59 + V_61 + V_64 ) ) {
T_4 V_65 = F_50 ( V_59 + V_61 + V_66 ) ;
if ( V_65 == V_67 ) {
V_65 = F_50 ( V_59 + V_61 + 3 ) ;
if ( ( V_65 & V_68 ) == V_81 )
break;
}
}
if ( V_61 == 0 )
return;
V_12 = V_59 + V_61 ;
F_40 ( 0x01 , V_12 + 2 ) ;
V_80 = ( F_45 ( V_12 + 4 ) >> 16 ) & 0xff ;
F_35 ( V_44 L_7
L_8 ,
V_60 >> 3 , V_60 & 0x7 , V_61 , V_77 & 0xffff , V_77 >> 16 , V_80 + 1 ) ;
for ( V_78 = 0 ; V_78 <= V_80 ; V_78 ++ ) {
F_40 ( 0x10 + 2 * V_78 , V_12 + 2 ) ;
V_56 = F_45 ( V_12 + 4 ) ;
V_79 = ( V_56 >> 16 ) & 0xff ;
F_43 ( L_9 , V_78 , V_79 , V_56 ) ;
V_56 |= 0x1 ;
F_38 ( V_56 , V_12 + 4 ) ;
V_1 -> V_46 [ V_79 ] . V_51 = V_78 ;
V_1 -> V_46 [ V_79 ] . V_12 = V_12 ;
if ( ( V_77 & 0xffff ) == 0x106b )
V_1 -> V_46 [ V_79 ] . V_49 = V_59 + 0x60 ;
else
V_1 -> V_46 [ V_79 ] . V_49 = NULL ;
F_40 ( 0x11 + 2 * V_78 , V_12 + 2 ) ;
V_1 -> V_46 [ V_79 ] . V_54 = F_45 ( V_12 + 4 ) | 0x80000000 ;
}
}
static void T_3 F_54 ( struct V_1 * V_1 )
{
unsigned int V_60 ;
T_4 T_5 * V_82 ;
F_35 ( V_44 L_10 ) ;
V_1 -> V_46 = F_55 ( 128 * sizeof( * V_1 -> V_46 ) , V_83 ) ;
F_25 ( V_1 -> V_46 == NULL ) ;
F_56 ( & V_1 -> V_53 ) ;
V_82 = F_24 ( 0xf2000000 , 0x10000 ) ;
F_25 ( V_82 == NULL ) ;
for ( V_60 = 0 ; V_60 < 0x100 ; V_60 ++ ) {
T_4 T_5 * V_59 = V_82 + ( V_60 << 8 ) ;
T_4 V_84 = F_50 ( V_59 + V_85 ) ;
T_1 V_86 = F_45 ( V_59 + V_87 ) ;
T_7 V_88 ;
F_43 ( L_11 , V_60 , V_86 ) ;
if ( V_86 == 0xffffffff || V_86 == 0x00000000 ||
V_86 == 0x0000ffff || V_86 == 0xffff0000 )
goto V_89;
V_88 = F_57 ( V_59 + V_90 ) ;
if ( ! ( V_88 & V_91 ) )
goto V_89;
F_53 ( V_1 , V_59 , V_60 , V_86 ) ;
F_49 ( V_1 , V_59 , V_60 ) ;
V_89:
if ( F_52 ( V_60 ) == 0 && ( V_84 & 0x80 ) == 0 )
V_60 += 7 ;
}
}
static inline int F_36 ( struct V_1 * V_1 , unsigned int V_45 )
{
return 0 ;
}
static void T_3 F_54 ( struct V_1 * V_1 )
{
}
static struct V_1 * F_58 ( unsigned int V_79 )
{
if ( V_79 < V_92 )
return NULL ;
return F_59 ( V_79 ) ;
}
static unsigned int F_60 ( struct V_1 * V_1 , unsigned int V_93 )
{
return ( V_93 >= V_1 -> V_94 [ 0 ] && V_93 <= V_1 -> V_94 [ 3 ] ) ;
}
static unsigned int F_61 ( struct V_1 * V_1 , unsigned int V_93 )
{
return ( V_93 >= V_1 -> V_95 [ 0 ] && V_93 <= V_1 -> V_95 [ 7 ] ) ;
}
static inline T_1 F_62 ( T_1 V_96 )
{
int V_78 ;
T_1 V_52 = 0 ;
for ( V_78 = 0 ; V_78 < F_63 ( 32 , V_97 ) ; ++ V_78 , V_96 >>= 1 )
V_52 |= ( V_96 & 1 ) << F_64 ( V_78 ) ;
return V_52 ;
}
static inline struct V_1 * F_65 ( struct V_98 * V_99 )
{
return F_66 ( V_99 ) ;
}
static inline struct V_1 * F_67 ( unsigned int V_79 )
{
return F_59 ( V_79 ) ;
}
static inline struct V_1 * F_68 ( struct V_98 * V_99 )
{
return F_66 ( V_99 ) ;
}
static inline void F_69 ( struct V_1 * V_1 )
{
F_70 ( F_13 ( V_100 ) , 0 ) ;
( void ) F_71 ( F_13 ( V_101 ) ) ;
}
void F_72 ( struct V_98 * V_99 )
{
unsigned int V_102 = 100000 ;
struct V_1 * V_1 = F_68 ( V_99 ) ;
unsigned int V_93 = F_73 ( V_99 ) ;
F_43 ( L_12 , V_1 , V_1 -> V_103 , V_99 -> V_79 , V_93 ) ;
F_74 ( V_93 , F_13 ( V_104 ) ,
F_75 ( V_93 , F_13 ( V_104 ) ) &
~ V_36 ) ;
do {
if ( ! V_102 -- ) {
F_35 ( V_105 L_13 ,
V_106 , V_93 ) ;
break;
}
} while( F_75 ( V_93 , F_13 ( V_104 ) ) & V_36 );
}
void F_76 ( struct V_98 * V_99 )
{
unsigned int V_102 = 100000 ;
struct V_1 * V_1 = F_68 ( V_99 ) ;
unsigned int V_93 = F_73 ( V_99 ) ;
F_43 ( L_14 , V_1 -> V_103 , V_99 -> V_79 , V_93 ) ;
F_74 ( V_93 , F_13 ( V_104 ) ,
F_75 ( V_93 , F_13 ( V_104 ) ) |
V_36 ) ;
do {
if ( ! V_102 -- ) {
F_35 ( V_105 L_13 ,
V_106 , V_93 ) ;
break;
}
} while( ! ( F_75 ( V_93 , F_13 ( V_104 ) ) & V_36 ) );
}
void F_77 ( struct V_98 * V_99 )
{
struct V_1 * V_1 = F_68 ( V_99 ) ;
#ifdef F_78
F_43 ( L_15 , V_1 -> V_103 , V_99 -> V_79 ) ;
#endif
F_69 ( V_1 ) ;
}
static void F_79 ( struct V_98 * V_99 )
{
struct V_1 * V_1 = F_68 ( V_99 ) ;
unsigned int V_93 = F_73 ( V_99 ) ;
F_72 ( V_99 ) ;
if ( F_80 ( V_99 ) )
F_37 ( V_1 , V_93 ) ;
}
static unsigned int F_81 ( struct V_98 * V_99 )
{
struct V_1 * V_1 = F_68 ( V_99 ) ;
unsigned int V_93 = F_73 ( V_99 ) ;
F_72 ( V_99 ) ;
F_42 ( V_1 , V_93 , F_80 ( V_99 ) ) ;
return 0 ;
}
static void F_82 ( struct V_98 * V_99 )
{
struct V_1 * V_1 = F_68 ( V_99 ) ;
unsigned int V_93 = F_73 ( V_99 ) ;
F_48 ( V_1 , V_93 ) ;
F_76 ( V_99 ) ;
}
static void F_83 ( struct V_98 * V_99 )
{
struct V_1 * V_1 = F_68 ( V_99 ) ;
unsigned int V_93 = F_73 ( V_99 ) ;
#ifdef F_78
F_43 ( L_15 , V_1 -> V_103 , V_99 -> V_79 ) ;
#endif
if ( F_80 ( V_99 ) )
F_37 ( V_1 , V_93 ) ;
F_69 ( V_1 ) ;
}
static void F_84 ( struct V_98 * V_99 )
{
struct V_1 * V_1 = F_65 ( V_99 ) ;
unsigned int V_93 = F_85 ( V_99 -> V_79 ) - V_1 -> V_94 [ 0 ] ;
F_43 ( L_16 , V_1 -> V_103 , V_99 -> V_79 , V_93 ) ;
F_86 ( V_93 , F_87 ( V_93 ) & ~ V_36 ) ;
}
static void F_88 ( struct V_98 * V_99 )
{
}
static void F_89 ( struct V_98 * V_99 )
{
struct V_1 * V_1 = F_65 ( V_99 ) ;
F_69 ( V_1 ) ;
}
static void F_90 ( struct V_98 * V_99 )
{
struct V_1 * V_1 = F_68 ( V_99 ) ;
unsigned int V_93 = F_85 ( V_99 -> V_79 ) - V_1 -> V_95 [ 0 ] ;
F_43 ( L_17 , V_1 -> V_103 , V_99 -> V_79 , V_93 ) ;
F_91 ( V_93 , F_92 ( V_93 ) & ~ V_36 ) ;
F_92 ( V_93 ) ;
}
static void F_93 ( struct V_98 * V_99 )
{
struct V_1 * V_1 = F_68 ( V_99 ) ;
unsigned int V_93 = F_85 ( V_99 -> V_79 ) - V_1 -> V_95 [ 0 ] ;
F_91 ( V_93 , F_92 ( V_93 ) | V_36 ) ;
F_92 ( V_93 ) ;
}
int F_94 ( struct V_98 * V_99 , const struct V_96 * V_96 ,
bool V_107 )
{
struct V_1 * V_1 = F_68 ( V_99 ) ;
unsigned int V_93 = F_73 ( V_99 ) ;
if ( V_1 -> V_3 & V_108 ) {
int V_109 = F_95 ( V_96 ) ;
F_74 ( V_93 , F_13 ( V_110 ) , 1 << V_109 ) ;
} else {
T_1 V_52 = F_96 ( V_96 ) [ 0 ] ;
V_52 &= F_96 ( V_111 ) [ 0 ] ;
F_74 ( V_93 , F_13 ( V_110 ) ,
F_62 ( V_52 ) ) ;
}
return 0 ;
}
static unsigned int F_97 ( struct V_1 * V_1 , unsigned int type )
{
switch( type & V_112 ) {
case V_113 :
return F_13 ( V_114 ) |
F_13 ( V_115 ) ;
case V_116 :
case V_117 :
return F_13 ( V_114 ) |
F_13 ( V_118 ) ;
case V_119 :
return F_13 ( V_120 ) |
F_13 ( V_115 ) ;
case V_121 :
default:
return F_13 ( V_120 ) |
F_13 ( V_118 ) ;
}
}
int F_98 ( struct V_98 * V_99 , unsigned int V_122 )
{
struct V_1 * V_1 = F_68 ( V_99 ) ;
unsigned int V_93 = F_73 ( V_99 ) ;
unsigned int V_123 , V_124 , V_125 ;
F_43 ( L_18 ,
V_1 , V_99 -> V_79 , V_93 , V_122 ) ;
if ( V_93 >= V_1 -> V_126 )
return - V_127 ;
V_124 = F_75 ( V_93 , F_13 ( V_104 ) ) ;
if ( V_122 == V_128 )
V_122 = V_129 ;
if ( V_122 == V_129 ) {
switch( V_124 & ( F_13 ( V_130 ) |
F_13 ( V_131 ) ) ) {
case F_13 ( V_114 ) |
F_13 ( V_115 ) :
V_122 = V_113 ;
break;
case F_13 ( V_114 ) |
F_13 ( V_118 ) :
V_122 = V_116 ;
break;
case F_13 ( V_120 ) |
F_13 ( V_115 ) :
V_122 = V_119 ;
break;
case F_13 ( V_120 ) |
F_13 ( V_118 ) :
V_122 = V_121 ;
break;
}
}
F_99 ( V_99 , V_122 ) ;
if ( F_36 ( V_1 , V_93 ) )
V_123 = V_132 |
V_133 ;
else
V_123 = F_97 ( V_1 , V_122 ) ;
V_125 = V_124 & ~ ( F_13 ( V_130 ) |
F_13 ( V_131 ) ) ;
V_125 |= V_123 ;
if ( V_124 != V_125 )
F_74 ( V_93 , F_13 ( V_104 ) , V_125 ) ;
return V_134 ;
}
void F_100 ( unsigned int V_135 , unsigned int V_136 )
{
struct V_1 * V_1 = F_67 ( V_135 ) ;
unsigned int V_93 = F_85 ( V_135 ) ;
unsigned int V_123 ;
F_43 ( L_19 ,
V_1 , V_135 , V_93 , V_136 ) ;
if ( V_93 >= V_1 -> V_126 )
return;
V_123 = F_75 ( V_93 , F_13 ( V_104 ) ) ;
V_123 = V_123 & ~ F_13 ( V_137 ) ;
V_123 |= V_136 ;
F_74 ( V_93 , F_13 ( V_104 ) , V_123 ) ;
}
void F_101 ( unsigned int V_135 , unsigned int V_109 )
{
struct V_1 * V_1 = F_67 ( V_135 ) ;
unsigned int V_93 = F_85 ( V_135 ) ;
F_43 ( L_20 ,
V_1 , V_135 , V_93 , V_109 ) ;
if ( V_93 >= V_1 -> V_126 )
return;
F_74 ( V_93 , F_13 ( V_110 ) , 1 << V_109 ) ;
}
static int F_102 ( struct V_138 * V_139 , struct V_140 * V_41 )
{
return V_139 -> V_141 == NULL || V_139 -> V_141 == V_41 ;
}
static int F_103 ( struct V_138 * V_139 , unsigned int V_135 ,
T_8 V_142 )
{
struct V_1 * V_1 = V_139 -> V_143 ;
struct V_144 * V_145 ;
F_43 ( L_21 , V_135 , V_142 ) ;
if ( V_142 == V_1 -> V_146 )
return - V_127 ;
if ( V_1 -> V_147 && F_104 ( V_142 , V_1 -> V_147 ) )
return - V_127 ;
#ifdef F_105
else if ( V_142 >= V_1 -> V_94 [ 0 ] ) {
F_106 ( V_1 -> V_3 & V_4 ) ;
F_43 ( L_22 ) ;
F_107 ( V_135 , V_1 ) ;
F_108 ( V_135 , & V_1 -> V_148 ,
V_149 ) ;
return 0 ;
}
#endif
if ( V_142 >= V_1 -> V_95 [ 0 ] && V_142 <= V_1 -> V_95 [ 7 ] ) {
F_106 ( V_1 -> V_3 & V_4 ) ;
F_43 ( L_23 ) ;
F_107 ( V_135 , V_1 ) ;
F_108 ( V_135 , & V_1 -> V_150 ,
V_151 ) ;
return 0 ;
}
if ( F_109 ( V_1 , V_135 , V_142 ) )
return 0 ;
if ( V_142 >= V_1 -> V_126 )
return - V_127 ;
F_110 ( V_1 , V_142 ) ;
V_145 = & V_1 -> V_152 ;
#ifdef F_111
if ( F_36 ( V_1 , V_142 ) )
V_145 = & V_1 -> V_153 ;
#endif
F_43 ( L_24 , V_145 ) ;
F_107 ( V_135 , V_1 ) ;
F_108 ( V_135 , V_145 , V_151 ) ;
F_112 ( V_135 , V_129 ) ;
if ( ! F_60 ( V_1 , V_142 ) && ( V_1 -> V_3 & V_154 ) ) {
F_100 ( V_135 , V_142 ) ;
F_101 ( V_135 , F_1 ( V_1 ) ) ;
F_113 ( V_135 , 8 ) ;
}
return 0 ;
}
static int F_114 ( struct V_138 * V_139 , struct V_140 * V_155 ,
const T_1 * V_156 , unsigned int V_157 ,
T_8 * V_158 , unsigned int * V_159 )
{
struct V_1 * V_1 = V_139 -> V_143 ;
static unsigned char V_160 [ 4 ] = {
V_113 ,
V_121 ,
V_119 ,
V_116 ,
} ;
* V_158 = V_156 [ 0 ] ;
if ( V_157 >= 4 && ( V_1 -> V_3 & V_161 ) ) {
switch ( V_156 [ 2 ] ) {
case 0 :
break;
case 1 :
if ( ! ( V_1 -> V_3 & V_162 ) )
break;
if ( V_156 [ 3 ] >= F_115 ( V_1 -> V_163 ) )
return - V_127 ;
* V_158 = V_1 -> V_163 [ V_156 [ 3 ] ] ;
break;
case 2 :
if ( V_156 [ 0 ] >= F_115 ( V_1 -> V_94 ) )
return - V_127 ;
* V_158 = V_1 -> V_94 [ V_156 [ 0 ] ] ;
break;
case 3 :
if ( V_156 [ 0 ] >= F_115 ( V_1 -> V_95 ) )
return - V_127 ;
* V_158 = V_1 -> V_95 [ V_156 [ 0 ] ] ;
break;
default:
F_116 ( L_25 ,
V_106 , V_156 [ 2 ] ) ;
return - V_127 ;
}
* V_159 = V_160 [ V_156 [ 1 ] & 3 ] ;
} else if ( V_157 > 1 ) {
T_1 V_52 = 0x3 ;
if ( F_117 ( V_164 ) )
V_52 = 0x1 ;
* V_159 = V_160 [ V_156 [ 1 ] & V_52 ] ;
} else
* V_159 = V_128 ;
F_43 ( L_26 ,
V_157 , V_156 [ 0 ] , V_156 [ 1 ] , * V_158 , * V_159 ) ;
return 0 ;
}
static void F_118 ( unsigned int V_79 , struct V_165 * V_166 )
{
struct V_144 * V_145 = F_119 ( V_166 ) ;
struct V_1 * V_1 = F_120 ( V_166 ) ;
unsigned int V_135 ;
F_25 ( ! ( V_1 -> V_3 & V_4 ) ) ;
V_135 = F_121 ( V_1 ) ;
if ( V_135 )
F_122 ( V_135 ) ;
V_145 -> V_167 ( & V_166 -> V_98 ) ;
}
struct V_1 * T_3 F_123 ( struct V_140 * V_41 ,
T_2 V_39 ,
unsigned int V_3 ,
unsigned int V_168 ,
unsigned int V_169 ,
const char * V_103 )
{
int V_78 , V_170 , V_171 ;
struct V_1 * V_1 ;
T_1 V_172 ;
const char * V_173 ;
const T_1 * V_174 ;
T_1 V_175 ;
static const struct V_176 T_9 V_177 [] = {
{ . type = L_27 , } ,
{ . V_178 = L_27 , } ,
{} ,
} ;
if ( V_41 ) {
V_41 = F_124 ( V_41 ) ;
} else {
V_41 = F_125 ( NULL , V_177 ) ;
if ( ! V_41 )
return NULL ;
}
if ( ! V_39 ) {
if ( F_126 ( V_41 , L_28 , NULL ) ) {
V_3 |= V_42 ;
} else {
struct V_179 V_43 ;
if ( F_127 ( V_41 , 0 , & V_43 ) )
goto V_180;
V_39 = V_43 . V_181 ;
}
}
if ( F_126 ( V_41 , L_29 , NULL ) )
V_3 |= V_182 ;
if ( F_126 ( V_41 , L_30 , NULL ) )
V_3 |= V_154 ;
if ( F_126 ( V_41 , L_31 , NULL ) )
V_3 |= V_108 ;
if ( F_128 ( V_41 , L_32 ) )
V_3 |= V_161 | V_183 ;
V_1 = F_55 ( sizeof( struct V_1 ) , V_83 ) ;
if ( V_1 == NULL )
goto V_180;
V_1 -> V_103 = V_103 ;
V_1 -> V_41 = V_41 ;
V_1 -> V_184 = V_39 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_152 = V_185 ;
V_1 -> V_152 . V_103 = V_103 ;
if ( ! ( V_1 -> V_3 & V_4 ) )
V_1 -> V_152 . V_186 = F_94 ;
#ifdef F_111
V_1 -> V_153 = V_187 ;
V_1 -> V_153 . V_103 = V_103 ;
if ( ! ( V_1 -> V_3 & V_4 ) )
V_1 -> V_153 . V_186 = F_94 ;
#endif
#ifdef F_105
V_1 -> V_148 = V_188 ;
V_1 -> V_148 . V_103 = V_103 ;
#endif
V_1 -> V_150 = V_189 ;
V_1 -> V_150 . V_103 = V_103 ;
V_1 -> V_126 = 0 ;
if ( V_1 -> V_3 & V_183 )
V_171 = 2047 ;
else
V_171 = 255 ;
V_1 -> V_95 [ 0 ] = V_171 - 12 ;
V_1 -> V_95 [ 1 ] = V_171 - 11 ;
V_1 -> V_95 [ 2 ] = V_171 - 10 ;
V_1 -> V_95 [ 3 ] = V_171 - 9 ;
V_1 -> V_95 [ 4 ] = V_171 - 8 ;
V_1 -> V_95 [ 5 ] = V_171 - 7 ;
V_1 -> V_95 [ 6 ] = V_171 - 6 ;
V_1 -> V_95 [ 7 ] = V_171 - 5 ;
V_1 -> V_94 [ 0 ] = V_171 - 4 ;
V_1 -> V_94 [ 1 ] = V_171 - 3 ;
V_1 -> V_94 [ 2 ] = V_171 - 2 ;
V_1 -> V_94 [ 3 ] = V_171 - 1 ;
V_1 -> V_146 = V_171 ;
V_174 = F_126 ( V_1 -> V_41 , L_33 , & V_170 ) ;
if ( V_174 ) {
unsigned int V_190 = F_129 ( V_171 + 1 ) ;
V_1 -> V_147 = F_55 ( V_190 * sizeof( long ) , V_83 ) ;
F_25 ( V_1 -> V_147 == NULL ) ;
for ( V_78 = 0 ; V_78 < V_170 / sizeof( T_1 ) ; V_78 ++ ) {
if ( V_174 [ V_78 ] > V_171 )
continue;
F_130 ( V_174 [ V_78 ] , V_1 -> V_147 ) ;
}
}
#ifdef F_131
V_1 -> V_191 = V_192 [ F_132 ( V_1 -> V_3 ) ] ;
#endif
if ( V_1 -> V_3 & V_182 )
V_1 -> V_16 = V_11 ;
else
V_1 -> V_16 = V_13 ;
#ifdef F_4
if ( V_1 -> V_3 & V_42 )
V_1 -> V_16 = V_9 ;
#else
F_25 ( V_1 -> V_3 & V_42 ) ;
#endif
F_30 ( V_1 , V_1 -> V_184 , & V_1 -> V_21 , F_13 ( V_193 ) , 0x1000 ) ;
F_30 ( V_1 , V_1 -> V_184 , & V_1 -> V_26 , F_13 ( V_194 ) , 0x1000 ) ;
if ( V_1 -> V_3 & V_161 ) {
T_1 V_195 , V_196 ;
int V_197 ;
F_30 ( V_1 , V_1 -> V_184 , & V_1 -> V_198 ,
V_199 , 0x1000 ) ;
V_195 = F_3 ( V_1 -> V_16 , & V_1 -> V_198 ,
V_200 ) ;
V_196 = V_195 & V_201 ;
if ( V_196 >= 0x401 ) {
V_197 = F_133 ( V_1 , V_171 - 12 ) ;
if ( V_197 )
return NULL ;
}
}
if ( ! ( V_1 -> V_3 & V_154 ) ) {
F_35 ( V_75 L_34 ) ;
F_32 ( V_1 -> V_21 , F_13 ( V_202 ) ,
F_33 ( V_1 -> V_21 , F_13 ( V_202 ) )
| V_203 ) ;
while( F_33 ( V_1 -> V_21 , F_13 ( V_202 ) )
& V_203 )
F_134 () ;
}
if ( V_1 -> V_3 & V_204 )
F_32 ( V_1 -> V_21 , F_13 ( V_202 ) ,
F_33 ( V_1 -> V_21 , F_13 ( V_202 ) )
| V_205 ) ;
if ( V_1 -> V_3 & V_206 )
F_32 ( V_1 -> V_21 , F_13 ( V_202 ) ,
F_33 ( V_1 -> V_21 , F_13 ( V_202 ) )
| V_207 ) ;
F_25 ( F_135 () > V_208 ) ;
F_136 (i) {
unsigned int V_2 = F_64 ( V_78 ) ;
F_30 ( V_1 , V_1 -> V_184 , & V_1 -> V_27 [ V_2 ] ,
F_13 ( V_209 ) + V_2 * F_13 ( V_210 ) ,
0x1000 ) ;
}
V_172 = F_33 ( V_1 -> V_21 , F_13 ( V_211 ) ) ;
V_175 = ( V_172 & V_212 )
>> V_213 ;
if ( V_168 )
V_175 = V_168 * V_214 - 1 ;
F_137 ( V_1 -> V_41 , L_35 , & V_175 ) ;
if ( V_169 )
V_175 = V_169 - 1 ;
if ( ! V_168 ) {
V_168 = V_175 + 1 ;
V_1 -> V_126 = V_168 ;
F_30 ( V_1 , V_1 -> V_184 , & V_1 -> V_34 [ 0 ] ,
F_13 ( V_215 ) ,
F_13 ( V_35 ) * V_168 ) ;
}
V_1 -> V_168 = V_168 ;
V_1 -> V_30 = 1 + F_138 ( V_1 -> V_168 - 1 ) ;
V_1 -> V_32 = ( 1 << V_1 -> V_30 ) - 1 ;
V_1 -> V_216 = F_139 ( V_1 -> V_41 ,
V_171 ,
& V_217 , V_1 ) ;
if ( V_1 -> V_216 == NULL )
return NULL ;
switch ( V_172 & V_218 ) {
case 1 :
V_173 = L_36 ;
break;
case 2 :
V_173 = L_37 ;
break;
case 3 :
V_173 = L_38 ;
break;
default:
V_173 = L_39 ;
break;
}
F_35 ( V_44 L_40
L_41 ,
V_103 , V_173 , ( unsigned long long ) V_1 -> V_184 , F_135 () ) ;
F_35 ( V_44 L_42 ,
V_1 -> V_168 , V_1 -> V_30 , V_1 -> V_32 ) ;
V_1 -> V_89 = V_219 ;
V_219 = V_1 ;
if ( ! ( V_1 -> V_3 & V_4 ) ) {
V_220 = V_1 ;
F_140 ( V_1 -> V_216 ) ;
}
return V_1 ;
V_180:
F_141 ( V_41 ) ;
return NULL ;
}
void T_3 F_142 ( struct V_1 * V_1 , unsigned int V_221 ,
T_2 V_184 )
{
unsigned int V_222 = V_221 * V_1 -> V_168 ;
F_25 ( V_221 >= V_214 ) ;
F_30 ( V_1 ,
V_184 , & V_1 -> V_34 [ V_221 ] , 0 ,
F_13 ( V_35 ) * V_1 -> V_168 ) ;
if ( ( V_222 + V_1 -> V_168 ) > V_1 -> V_126 )
V_1 -> V_126 = V_222 + V_1 -> V_168 ;
}
void T_3 F_143 ( struct V_1 * V_1 )
{
int V_78 , V_2 ;
int V_223 = 4 ;
F_25 ( V_1 -> V_126 == 0 ) ;
F_35 ( V_44 L_43 , V_1 -> V_126 ) ;
F_70 ( F_13 ( V_224 ) , 0xf ) ;
if ( V_1 -> V_3 & V_161 ) {
T_1 V_195 = F_3 ( V_1 -> V_16 , & V_1 -> V_198 ,
V_200 ) ;
T_1 V_196 = V_195 & V_201 ;
if ( V_196 >= 0x0301 )
V_223 = 8 ;
}
if ( V_1 -> V_3 & V_162 )
F_144 ( V_1 , V_225 ) ;
for ( V_78 = 0 ; V_78 < V_223 ; V_78 ++ ) {
unsigned int V_17 = F_15 ( V_1 , V_78 ) ;
F_32 ( V_1 -> V_26 ,
V_17 + F_13 ( V_226 ) ,
1 << F_2 () ) ;
F_32 ( V_1 -> V_26 ,
V_17 + F_13 ( V_25 ) ,
V_36 |
( 9 << V_227 ) |
( V_1 -> V_95 [ 0 ] + V_78 ) ) ;
}
F_31 ( V_1 ) ;
for ( V_78 = 0 ; V_78 < 4 ; V_78 ++ ) {
F_86 ( V_78 ,
V_36 |
( 10 << V_227 ) |
( V_1 -> V_94 [ 0 ] + V_78 ) ) ;
}
F_43 ( L_44 , V_1 -> V_3 ) ;
if ( ( V_1 -> V_3 & V_228 ) && ! ( V_1 -> V_3 & V_4 ) ) {
F_54 ( V_1 ) ;
F_145 ( V_1 ) ;
}
F_146 ( V_1 ) ;
V_2 = F_1 ( V_1 ) ;
if ( ! ( V_1 -> V_3 & V_154 ) ) {
for ( V_78 = 0 ; V_78 < V_1 -> V_126 ; V_78 ++ ) {
T_1 V_123 = V_36 | V_78 |
( 8 << V_227 ) ;
if ( V_1 -> V_147 && F_104 ( V_78 , V_1 -> V_147 ) )
continue;
F_74 ( V_78 , F_13 ( V_104 ) , V_123 ) ;
F_74 ( V_78 , F_13 ( V_110 ) , 1 << V_2 ) ;
}
}
F_32 ( V_1 -> V_21 , F_13 ( V_229 ) , V_1 -> V_146 ) ;
if ( ! ( V_1 -> V_3 & V_230 ) )
F_32 ( V_1 -> V_21 , F_13 ( V_202 ) ,
F_33 ( V_1 -> V_21 , F_13 ( V_202 ) )
| V_231 ) ;
if ( V_1 -> V_3 & V_232 )
F_32 ( V_1 -> V_21 , F_13 ( V_202 ) ,
F_33 ( V_1 -> V_21 , F_13 ( V_202 ) )
| V_233 ) ;
F_70 ( F_13 ( V_224 ) , 0 ) ;
#ifdef F_47
V_1 -> V_57 = F_147 ( V_1 -> V_126 * sizeof( * V_1 -> V_57 ) ,
V_83 ) ;
F_25 ( V_1 -> V_57 == NULL ) ;
#endif
if ( V_1 -> V_3 & V_4 ) {
int V_135 = F_148 ( V_1 -> V_41 , 0 ) ;
if ( V_135 != V_234 ) {
F_35 ( V_44 L_45 ,
V_1 -> V_41 -> V_235 , V_135 ) ;
F_149 ( V_135 , V_1 ) ;
F_150 ( V_135 , & F_118 ) ;
}
}
}
void T_3 F_151 ( struct V_1 * V_1 , T_1 V_236 )
{
T_1 V_237 ;
V_237 = F_33 ( V_1 -> V_21 , V_238 ) ;
V_237 &= ~ V_239 ;
V_237 |= F_152 ( V_236 ) ;
F_32 ( V_1 -> V_21 , V_238 , V_237 ) ;
}
void T_3 F_153 ( struct V_1 * V_1 , int V_240 )
{
unsigned long V_3 ;
T_1 V_237 ;
F_44 ( & V_241 , V_3 ) ;
V_237 = F_33 ( V_1 -> V_21 , V_238 ) ;
if ( V_240 )
V_237 |= V_242 ;
else
V_237 &= ~ V_242 ;
F_32 ( V_1 -> V_21 , V_238 , V_237 ) ;
F_46 ( & V_241 , V_3 ) ;
}
void F_113 ( unsigned int V_79 , unsigned int V_243 )
{
struct V_1 * V_1 = F_58 ( V_79 ) ;
unsigned int V_93 = F_85 ( V_79 ) ;
unsigned long V_3 ;
T_1 V_8 ;
if ( ! V_1 )
return;
F_44 ( & V_241 , V_3 ) ;
if ( F_60 ( V_1 , V_93 ) ) {
V_8 = F_87 ( V_93 - V_1 -> V_94 [ 0 ] ) &
~ V_244 ;
F_86 ( V_93 - V_1 -> V_94 [ 0 ] ,
V_8 | ( V_243 << V_227 ) ) ;
} else if ( F_61 ( V_1 , V_93 ) ) {
V_8 = F_92 ( V_93 - V_1 -> V_95 [ 0 ] ) &
~ V_244 ;
F_91 ( V_93 - V_1 -> V_95 [ 0 ] ,
V_8 | ( V_243 << V_227 ) ) ;
} else {
V_8 = F_75 ( V_93 , F_13 ( V_104 ) )
& ~ V_244 ;
F_74 ( V_93 , F_13 ( V_104 ) ,
V_8 | ( V_243 << V_227 ) ) ;
}
F_46 ( & V_241 , V_3 ) ;
}
void F_154 ( void )
{
#ifdef F_105
struct V_1 * V_1 = V_220 ;
unsigned long V_3 ;
T_1 V_245 = 1 << F_2 () ;
unsigned int V_78 ;
F_25 ( V_1 == NULL ) ;
F_43 ( L_46 , V_1 -> V_103 , F_2 () ) ;
F_44 ( & V_241 , V_3 ) ;
if ( V_246 ) {
for ( V_78 = 0 ; V_78 < V_1 -> V_126 ; V_78 ++ )
F_74 ( V_78 , F_13 ( V_110 ) ,
F_75 ( V_78 , F_13 ( V_110 ) ) | V_245 ) ;
}
F_70 ( F_13 ( V_224 ) , 0 ) ;
F_46 ( & V_241 , V_3 ) ;
#endif
}
int F_155 ( void )
{
struct V_1 * V_1 = V_220 ;
return F_71 ( F_13 ( V_224 ) ) ;
}
void F_156 ( int V_247 )
{
struct V_1 * V_1 = V_220 ;
V_247 &= V_248 ;
F_70 ( F_13 ( V_224 ) , V_247 ) ;
}
void F_157 ( int V_249 )
{
struct V_1 * V_1 = V_220 ;
unsigned long V_3 ;
T_1 V_245 = 1 << F_2 () ;
unsigned int V_78 ;
F_25 ( V_1 == NULL ) ;
F_43 ( L_47 , V_1 -> V_103 , F_2 () ) ;
F_44 ( & V_241 , V_3 ) ;
for ( V_78 = 0 ; V_78 < V_1 -> V_126 ; V_78 ++ )
F_74 ( V_78 , F_13 ( V_110 ) ,
F_75 ( V_78 , F_13 ( V_110 ) ) & ~ V_245 ) ;
F_70 ( F_13 ( V_224 ) , 0xf ) ;
F_69 ( V_1 ) ;
F_46 ( & V_241 , V_3 ) ;
}
static unsigned int F_158 ( struct V_1 * V_1 , int V_8 )
{
T_1 V_93 ;
V_93 = F_71 ( V_8 ) & F_13 ( V_137 ) ;
#ifdef F_159
F_43 ( L_48 , V_1 -> V_103 , V_8 , V_93 ) ;
#endif
if ( F_160 ( V_93 == V_1 -> V_146 ) ) {
if ( V_1 -> V_3 & V_250 )
F_69 ( V_1 ) ;
return V_234 ;
}
if ( F_160 ( V_1 -> V_147 && F_104 ( V_93 , V_1 -> V_147 ) ) ) {
F_161 ( V_251 L_49 ,
V_1 -> V_103 , ( int ) V_93 ) ;
F_69 ( V_1 ) ;
return V_234 ;
}
return F_162 ( V_1 -> V_216 , V_93 ) ;
}
unsigned int F_121 ( struct V_1 * V_1 )
{
return F_158 ( V_1 , F_13 ( V_252 ) ) ;
}
unsigned int F_163 ( void )
{
struct V_1 * V_1 = V_220 ;
F_25 ( V_1 == NULL ) ;
return F_121 ( V_1 ) ;
}
unsigned int F_164 ( void )
{
#ifdef F_165
struct V_1 * V_1 = V_220 ;
T_1 V_93 ;
F_25 ( V_1 == NULL ) ;
V_93 = F_166 ( V_253 ) ;
if ( F_160 ( V_93 == V_1 -> V_146 ) ) {
if ( V_1 -> V_3 & V_250 )
F_69 ( V_1 ) ;
return V_234 ;
}
if ( F_160 ( V_1 -> V_147 && F_104 ( V_93 , V_1 -> V_147 ) ) ) {
F_161 ( V_251 L_49 ,
V_1 -> V_103 , ( int ) V_93 ) ;
return V_234 ;
}
return F_162 ( V_1 -> V_216 , V_93 ) ;
#else
return V_234 ;
#endif
}
unsigned int F_167 ( void )
{
struct V_1 * V_1 = V_220 ;
F_25 ( V_1 == NULL ) ;
return F_158 ( V_1 , F_13 ( V_254 ) ) ;
}
void F_168 ( void )
{
struct V_1 * V_1 = V_220 ;
int V_78 ;
F_25 ( V_1 == NULL ) ;
F_35 ( V_44 L_50 ) ;
for ( V_78 = 0 ; V_78 < 4 ; V_78 ++ ) {
unsigned int V_255 = F_169 ( V_1 -> V_216 ,
V_1 -> V_94 [ 0 ] + V_78 ) ;
if ( V_255 == V_234 ) {
F_35 ( V_105 L_51 , V_256 [ V_78 ] ) ;
continue;
}
F_170 ( V_255 , V_78 ) ;
}
}
void F_171 ( int V_2 , int V_257 )
{
struct V_1 * V_1 = V_220 ;
T_1 V_258 ;
F_25 ( V_1 == NULL ) ;
if ( ( unsigned int ) V_257 > 3 ) {
F_35 ( L_52 ,
F_172 () , V_257 ) ;
return;
}
#ifdef F_173
F_43 ( L_53 , V_1 -> V_103 , V_257 ) ;
#endif
V_258 = 1 << F_64 ( V_2 ) ;
F_70 ( F_13 ( V_259 ) +
V_257 * F_13 ( V_260 ) , V_258 ) ;
}
int T_3 F_174 ( void )
{
int V_261 ;
F_43 ( L_54 ) ;
V_261 = F_175 ( V_262 ) ;
F_43 ( L_55 , V_261 ) ;
if ( V_261 > 1 )
F_168 () ;
return V_261 ;
}
void F_176 ( int V_2 )
{
F_154 () ;
}
void F_177 ( int V_2 )
{
struct V_1 * V_1 = V_220 ;
T_1 V_263 ;
int V_109 = F_64 ( V_2 ) ;
int V_78 ;
V_263 = F_33 ( V_1 -> V_21 , F_13 ( V_264 ) ) ;
V_263 |= ( 1 << V_109 ) ;
F_32 ( V_1 -> V_21 , F_13 ( V_264 ) , V_263 ) ;
F_33 ( V_1 -> V_21 , F_13 ( V_264 ) ) ;
V_263 &= ~ ( 1 << V_109 ) ;
F_32 ( V_1 -> V_21 , F_13 ( V_264 ) , V_263 ) ;
F_33 ( V_1 -> V_21 , F_13 ( V_264 ) ) ;
if ( V_1 -> V_3 & V_161 ) {
for ( V_78 = 0 ; V_78 < 15 ; V_78 ++ ) {
F_8 ( V_1 -> V_16 , & V_1 -> V_27 [ V_109 ] ,
V_265 , 0 ) ;
}
}
}
static void F_178 ( struct V_1 * V_1 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_1 -> V_126 ; V_78 ++ ) {
V_1 -> V_57 [ V_78 ] . V_266 =
F_75 ( V_78 , F_13 ( V_104 ) ) ;
V_1 -> V_57 [ V_78 ] . V_267 =
F_75 ( V_78 , F_13 ( V_110 ) ) ;
}
}
static int F_179 ( void )
{
struct V_1 * V_1 = V_219 ;
while ( V_1 ) {
F_178 ( V_1 ) ;
V_1 = V_1 -> V_89 ;
}
return 0 ;
}
static void F_180 ( struct V_1 * V_1 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_1 -> V_126 ; V_78 ++ ) {
F_74 ( V_78 , F_13 ( V_104 ) ,
V_1 -> V_57 [ V_78 ] . V_266 ) ;
F_74 ( V_78 , F_13 ( V_110 ) ,
V_1 -> V_57 [ V_78 ] . V_267 ) ;
#ifdef F_111
if ( V_1 -> V_46 ) {
struct V_47 * V_48 = & V_1 -> V_46 [ V_78 ] ;
if ( V_48 -> V_12 ) {
if ( ( V_1 -> V_57 [ V_78 ] . V_58 & 1 ) == 0 )
continue;
F_40 ( 0x10 + 2 * V_48 -> V_51 , V_48 -> V_12 + 2 ) ;
F_38 ( V_1 -> V_57 [ V_78 ] . V_58 & ~ 1 ,
V_48 -> V_12 + 4 ) ;
}
}
#endif
}
}
static void F_181 ( void )
{
struct V_1 * V_1 = V_219 ;
while ( V_1 ) {
F_180 ( V_1 ) ;
V_1 = V_1 -> V_89 ;
}
}
static int F_182 ( void )
{
F_183 ( & V_268 ) ;
return 0 ;
}
