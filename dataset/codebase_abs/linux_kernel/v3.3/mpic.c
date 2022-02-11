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
static void F_25 ( struct V_1 * V_1 , struct V_6 * V_7 ,
unsigned int V_17 , unsigned int V_39 )
{
T_2 V_38 = F_26 ( V_1 -> V_40 , 0 ) ;
V_7 -> V_10 = F_27 ( V_1 -> V_40 , V_38 + V_17 , V_39 ) ;
F_24 ( ! F_28 ( V_7 -> V_10 ) ) ;
}
static inline void F_29 ( struct V_1 * V_1 ,
T_2 V_38 , struct V_6 * V_7 ,
unsigned int V_17 , unsigned int V_39 )
{
if ( V_1 -> V_3 & V_41 )
F_25 ( V_1 , V_7 , V_17 , V_39 ) ;
else
F_22 ( V_1 , V_38 , V_7 , V_17 , V_39 ) ;
}
static void T_3 F_30 ( struct V_1 * V_1 )
{
T_1 V_42 ;
F_31 ( V_1 -> V_21 , F_13 ( V_18 ) , V_35 ) ;
V_42 = F_32 ( V_1 -> V_21 , F_13 ( V_18 ) ) ;
if ( V_42 == F_33 ( V_35 ) ) {
F_34 ( V_43 L_1 ) ;
V_1 -> V_3 |= V_20 ;
}
}
static inline int F_35 ( struct V_1 * V_1 , unsigned int V_44 )
{
if ( V_44 >= 128 || ! V_1 -> V_45 )
return 0 ;
return V_1 -> V_45 [ V_44 ] . V_12 != NULL ;
}
static inline void F_36 ( struct V_1 * V_1 , unsigned int V_44 )
{
struct V_46 * V_47 = & V_1 -> V_45 [ V_44 ] ;
if ( V_47 -> V_48 ) {
unsigned int V_49 = ( V_47 -> V_50 >> 3 ) & ~ 3 ;
unsigned int V_51 = 1U << ( V_47 -> V_50 & 0x1f ) ;
F_37 ( V_51 , V_47 -> V_48 + V_49 ) ;
} else {
F_38 ( & V_1 -> V_52 ) ;
F_39 ( 0x11 + 2 * V_47 -> V_50 , V_47 -> V_12 + 2 ) ;
F_37 ( V_47 -> V_53 , V_47 -> V_12 + 4 ) ;
F_40 ( & V_1 -> V_52 ) ;
}
}
static void F_41 ( struct V_1 * V_1 , unsigned int V_44 ,
bool V_54 )
{
struct V_46 * V_47 = & V_1 -> V_45 [ V_44 ] ;
unsigned long V_3 ;
T_1 V_55 ;
if ( V_47 -> V_12 == NULL )
return;
F_42 ( L_2 ,
V_44 , V_47 -> V_50 ) ;
F_43 ( & V_1 -> V_52 , V_3 ) ;
F_39 ( 0x10 + 2 * V_47 -> V_50 , V_47 -> V_12 + 2 ) ;
V_55 = F_44 ( V_47 -> V_12 + 4 ) ;
V_55 &= ~ ( 0x23U ) ;
if ( V_54 )
V_55 |= 0x22 ;
F_37 ( V_55 , V_47 -> V_12 + 4 ) ;
F_45 ( & V_1 -> V_52 , V_3 ) ;
#ifdef F_46
V_1 -> V_56 [ V_44 ] . V_57 = V_55 | 1 ;
#endif
}
static void F_47 ( struct V_1 * V_1 , unsigned int V_44 )
{
struct V_46 * V_47 = & V_1 -> V_45 [ V_44 ] ;
unsigned long V_3 ;
T_1 V_55 ;
if ( V_47 -> V_12 == NULL )
return;
F_42 ( L_3 , V_44 ) ;
F_43 ( & V_1 -> V_52 , V_3 ) ;
F_39 ( 0x10 + 2 * V_47 -> V_50 , V_47 -> V_12 + 2 ) ;
V_55 = F_44 ( V_47 -> V_12 + 4 ) ;
V_55 |= 1 ;
F_37 ( V_55 , V_47 -> V_12 + 4 ) ;
F_45 ( & V_1 -> V_52 , V_3 ) ;
#ifdef F_46
V_1 -> V_56 [ V_44 ] . V_57 = V_55 & ~ 1 ;
#endif
}
static void T_3 F_48 ( struct V_1 * V_1 , T_4 T_5 * V_58 ,
unsigned int V_59 )
{
T_4 T_5 * V_12 ;
T_4 V_60 , V_3 ;
T_6 V_61 = 0 ;
for ( V_60 = F_49 ( V_58 + V_62 ) ; V_60 != 0 ;
V_60 = F_49 ( V_58 + V_60 + V_63 ) ) {
T_4 V_64 = F_49 ( V_58 + V_60 + V_65 ) ;
if ( V_64 == V_66 ) {
V_64 = F_49 ( V_58 + V_60 + 3 ) ;
if ( ( V_64 & V_67 ) == V_68 )
break;
}
}
if ( V_60 == 0 )
return;
V_12 = V_58 + V_60 ;
V_3 = F_49 ( V_12 + V_69 ) ;
if ( ! ( V_3 & V_70 ) ) {
V_61 = F_44 ( V_12 + V_71 ) & V_72 ;
V_61 = V_61 | ( ( T_6 ) F_44 ( V_12 + V_73 ) << 32 ) ;
}
F_34 ( V_74 L_4 ,
F_50 ( V_59 ) , F_51 ( V_59 ) ,
V_3 & V_75 ? L_5 : L_6 , V_61 ) ;
if ( ! ( V_3 & V_75 ) )
F_39 ( V_3 | V_75 , V_12 + V_69 ) ;
}
static void T_3 F_48 ( struct V_1 * V_1 , T_4 T_5 * V_58 ,
unsigned int V_59 )
{
return;
}
static void T_3 F_52 ( struct V_1 * V_1 , T_4 T_5 * V_58 ,
unsigned int V_59 , T_1 V_76 )
{
int V_77 , V_78 , V_79 ;
T_4 T_5 * V_12 ;
T_1 V_55 ;
T_4 V_60 ;
for ( V_60 = F_49 ( V_58 + V_62 ) ; V_60 != 0 ;
V_60 = F_49 ( V_58 + V_60 + V_63 ) ) {
T_4 V_64 = F_49 ( V_58 + V_60 + V_65 ) ;
if ( V_64 == V_66 ) {
V_64 = F_49 ( V_58 + V_60 + 3 ) ;
if ( ( V_64 & V_67 ) == V_80 )
break;
}
}
if ( V_60 == 0 )
return;
V_12 = V_58 + V_60 ;
F_39 ( 0x01 , V_12 + 2 ) ;
V_79 = ( F_44 ( V_12 + 4 ) >> 16 ) & 0xff ;
F_34 ( V_43 L_7
L_8 ,
V_59 >> 3 , V_59 & 0x7 , V_60 , V_76 & 0xffff , V_76 >> 16 , V_79 + 1 ) ;
for ( V_77 = 0 ; V_77 <= V_79 ; V_77 ++ ) {
F_39 ( 0x10 + 2 * V_77 , V_12 + 2 ) ;
V_55 = F_44 ( V_12 + 4 ) ;
V_78 = ( V_55 >> 16 ) & 0xff ;
F_42 ( L_9 , V_77 , V_78 , V_55 ) ;
V_55 |= 0x1 ;
F_37 ( V_55 , V_12 + 4 ) ;
V_1 -> V_45 [ V_78 ] . V_50 = V_77 ;
V_1 -> V_45 [ V_78 ] . V_12 = V_12 ;
if ( ( V_76 & 0xffff ) == 0x106b )
V_1 -> V_45 [ V_78 ] . V_48 = V_58 + 0x60 ;
else
V_1 -> V_45 [ V_78 ] . V_48 = NULL ;
F_39 ( 0x11 + 2 * V_77 , V_12 + 2 ) ;
V_1 -> V_45 [ V_78 ] . V_53 = F_44 ( V_12 + 4 ) | 0x80000000 ;
}
}
static void T_3 F_53 ( struct V_1 * V_1 )
{
unsigned int V_59 ;
T_4 T_5 * V_81 ;
F_34 ( V_43 L_10 ) ;
V_1 -> V_45 = F_54 ( 128 * sizeof( * V_1 -> V_45 ) , V_82 ) ;
F_24 ( V_1 -> V_45 == NULL ) ;
F_55 ( & V_1 -> V_52 ) ;
V_81 = F_23 ( 0xf2000000 , 0x10000 ) ;
F_24 ( V_81 == NULL ) ;
for ( V_59 = 0 ; V_59 < 0x100 ; V_59 ++ ) {
T_4 T_5 * V_58 = V_81 + ( V_59 << 8 ) ;
T_4 V_83 = F_49 ( V_58 + V_84 ) ;
T_1 V_85 = F_44 ( V_58 + V_86 ) ;
T_7 V_87 ;
F_42 ( L_11 , V_59 , V_85 ) ;
if ( V_85 == 0xffffffff || V_85 == 0x00000000 ||
V_85 == 0x0000ffff || V_85 == 0xffff0000 )
goto V_88;
V_87 = F_56 ( V_58 + V_89 ) ;
if ( ! ( V_87 & V_90 ) )
goto V_88;
F_52 ( V_1 , V_58 , V_59 , V_85 ) ;
F_48 ( V_1 , V_58 , V_59 ) ;
V_88:
if ( F_51 ( V_59 ) == 0 && ( V_83 & 0x80 ) == 0 )
V_59 += 7 ;
}
}
static inline int F_35 ( struct V_1 * V_1 , unsigned int V_44 )
{
return 0 ;
}
static void T_3 F_53 ( struct V_1 * V_1 )
{
}
static struct V_1 * F_57 ( unsigned int V_78 )
{
if ( V_78 < V_91 )
return NULL ;
return F_58 ( V_78 ) ;
}
static unsigned int F_59 ( struct V_1 * V_1 , unsigned int V_78 )
{
unsigned int V_92 = F_60 ( V_78 ) ;
return ( V_92 >= V_1 -> V_93 [ 0 ] && V_92 <= V_1 -> V_93 [ 3 ] ) ;
}
static unsigned int F_61 ( struct V_1 * V_1 , unsigned int V_78 )
{
unsigned int V_92 = F_60 ( V_78 ) ;
return ( V_92 >= V_1 -> V_94 [ 0 ] && V_92 <= V_1 -> V_94 [ 7 ] ) ;
}
static inline T_1 F_62 ( T_1 V_95 )
{
int V_77 ;
T_1 V_51 = 0 ;
for ( V_77 = 0 ; V_77 < F_63 ( 32 , V_96 ) ; ++ V_77 , V_95 >>= 1 )
V_51 |= ( V_95 & 1 ) << F_64 ( V_77 ) ;
return V_51 ;
}
static inline struct V_1 * F_65 ( struct V_97 * V_98 )
{
return F_66 ( V_98 ) ;
}
static inline struct V_1 * F_67 ( unsigned int V_78 )
{
return F_58 ( V_78 ) ;
}
static inline struct V_1 * F_68 ( struct V_97 * V_98 )
{
return F_66 ( V_98 ) ;
}
static inline void F_69 ( struct V_1 * V_1 )
{
F_70 ( F_13 ( V_99 ) , 0 ) ;
( void ) F_71 ( F_13 ( V_100 ) ) ;
}
void F_72 ( struct V_97 * V_98 )
{
unsigned int V_101 = 100000 ;
struct V_1 * V_1 = F_68 ( V_98 ) ;
unsigned int V_92 = F_73 ( V_98 ) ;
F_42 ( L_12 , V_1 , V_1 -> V_102 , V_98 -> V_78 , V_92 ) ;
F_74 ( V_92 , F_13 ( V_103 ) ,
F_75 ( V_92 , F_13 ( V_103 ) ) &
~ V_35 ) ;
do {
if ( ! V_101 -- ) {
F_34 ( V_104 L_13 ,
V_105 , V_92 ) ;
break;
}
} while( F_75 ( V_92 , F_13 ( V_103 ) ) & V_35 );
}
void F_76 ( struct V_97 * V_98 )
{
unsigned int V_101 = 100000 ;
struct V_1 * V_1 = F_68 ( V_98 ) ;
unsigned int V_92 = F_73 ( V_98 ) ;
F_42 ( L_14 , V_1 -> V_102 , V_98 -> V_78 , V_92 ) ;
F_74 ( V_92 , F_13 ( V_103 ) ,
F_75 ( V_92 , F_13 ( V_103 ) ) |
V_35 ) ;
do {
if ( ! V_101 -- ) {
F_34 ( V_104 L_13 ,
V_105 , V_92 ) ;
break;
}
} while( ! ( F_75 ( V_92 , F_13 ( V_103 ) ) & V_35 ) );
}
void F_77 ( struct V_97 * V_98 )
{
struct V_1 * V_1 = F_68 ( V_98 ) ;
#ifdef F_78
F_42 ( L_15 , V_1 -> V_102 , V_98 -> V_78 ) ;
#endif
F_69 ( V_1 ) ;
}
static void F_79 ( struct V_97 * V_98 )
{
struct V_1 * V_1 = F_68 ( V_98 ) ;
unsigned int V_92 = F_73 ( V_98 ) ;
F_72 ( V_98 ) ;
if ( F_80 ( V_98 ) )
F_36 ( V_1 , V_92 ) ;
}
static unsigned int F_81 ( struct V_97 * V_98 )
{
struct V_1 * V_1 = F_68 ( V_98 ) ;
unsigned int V_92 = F_73 ( V_98 ) ;
F_72 ( V_98 ) ;
F_41 ( V_1 , V_92 , F_80 ( V_98 ) ) ;
return 0 ;
}
static void F_82 ( struct V_97 * V_98 )
{
struct V_1 * V_1 = F_68 ( V_98 ) ;
unsigned int V_92 = F_73 ( V_98 ) ;
F_47 ( V_1 , V_92 ) ;
F_76 ( V_98 ) ;
}
static void F_83 ( struct V_97 * V_98 )
{
struct V_1 * V_1 = F_68 ( V_98 ) ;
unsigned int V_92 = F_73 ( V_98 ) ;
#ifdef F_78
F_42 ( L_15 , V_1 -> V_102 , V_98 -> V_78 ) ;
#endif
if ( F_80 ( V_98 ) )
F_36 ( V_1 , V_92 ) ;
F_69 ( V_1 ) ;
}
static void F_84 ( struct V_97 * V_98 )
{
struct V_1 * V_1 = F_65 ( V_98 ) ;
unsigned int V_92 = F_60 ( V_98 -> V_78 ) - V_1 -> V_93 [ 0 ] ;
F_42 ( L_16 , V_1 -> V_102 , V_98 -> V_78 , V_92 ) ;
F_85 ( V_92 , F_86 ( V_92 ) & ~ V_35 ) ;
}
static void F_87 ( struct V_97 * V_98 )
{
}
static void F_88 ( struct V_97 * V_98 )
{
struct V_1 * V_1 = F_65 ( V_98 ) ;
F_69 ( V_1 ) ;
}
static void F_89 ( struct V_97 * V_98 )
{
struct V_1 * V_1 = F_68 ( V_98 ) ;
unsigned int V_92 = F_60 ( V_98 -> V_78 ) - V_1 -> V_94 [ 0 ] ;
F_42 ( L_17 , V_1 -> V_102 , V_98 -> V_78 , V_92 ) ;
F_90 ( V_92 , F_91 ( V_92 ) & ~ V_35 ) ;
F_91 ( V_92 ) ;
}
static void F_92 ( struct V_97 * V_98 )
{
struct V_1 * V_1 = F_68 ( V_98 ) ;
unsigned int V_92 = F_60 ( V_98 -> V_78 ) - V_1 -> V_94 [ 0 ] ;
F_90 ( V_92 , F_91 ( V_92 ) | V_35 ) ;
F_91 ( V_92 ) ;
}
int F_93 ( struct V_97 * V_98 , const struct V_95 * V_95 ,
bool V_106 )
{
struct V_1 * V_1 = F_68 ( V_98 ) ;
unsigned int V_92 = F_73 ( V_98 ) ;
if ( V_1 -> V_3 & V_107 ) {
int V_108 = F_94 ( V_95 ) ;
F_74 ( V_92 , F_13 ( V_109 ) , 1 << V_108 ) ;
} else {
T_1 V_51 = F_95 ( V_95 ) [ 0 ] ;
V_51 &= F_95 ( V_110 ) [ 0 ] ;
F_74 ( V_92 , F_13 ( V_109 ) ,
F_62 ( V_51 ) ) ;
}
return 0 ;
}
static unsigned int F_96 ( struct V_1 * V_1 , unsigned int type )
{
switch( type & V_111 ) {
case V_112 :
return F_13 ( V_113 ) |
F_13 ( V_114 ) ;
case V_115 :
case V_116 :
return F_13 ( V_113 ) |
F_13 ( V_117 ) ;
case V_118 :
return F_13 ( V_119 ) |
F_13 ( V_114 ) ;
case V_120 :
default:
return F_13 ( V_119 ) |
F_13 ( V_117 ) ;
}
}
int F_97 ( struct V_97 * V_98 , unsigned int V_121 )
{
struct V_1 * V_1 = F_68 ( V_98 ) ;
unsigned int V_92 = F_73 ( V_98 ) ;
unsigned int V_122 , V_123 , V_124 ;
F_42 ( L_18 ,
V_1 , V_98 -> V_78 , V_92 , V_121 ) ;
if ( V_92 >= V_1 -> V_125 )
return - V_126 ;
if ( V_121 == V_127 )
if ( V_1 -> V_128 && V_92 < V_1 -> V_129 )
V_121 = V_1 -> V_128 [ V_92 ] ;
if ( V_121 == V_127 )
V_121 = V_120 ;
F_98 ( V_98 , V_121 ) ;
if ( F_35 ( V_1 , V_92 ) )
V_122 = V_130 |
V_131 ;
else
V_122 = F_96 ( V_1 , V_121 ) ;
V_123 = F_75 ( V_92 , F_13 ( V_103 ) ) ;
V_124 = V_123 & ~ ( F_13 ( V_132 ) |
F_13 ( V_133 ) ) ;
V_124 |= V_122 ;
if ( V_123 != V_124 )
F_74 ( V_92 , F_13 ( V_103 ) , V_124 ) ;
return V_134 ;
}
void F_99 ( unsigned int V_135 , unsigned int V_136 )
{
struct V_1 * V_1 = F_67 ( V_135 ) ;
unsigned int V_92 = F_60 ( V_135 ) ;
unsigned int V_122 ;
F_42 ( L_19 ,
V_1 , V_135 , V_92 , V_136 ) ;
if ( V_92 >= V_1 -> V_125 )
return;
V_122 = F_75 ( V_92 , F_13 ( V_103 ) ) ;
V_122 = V_122 & ~ F_13 ( V_137 ) ;
V_122 |= V_136 ;
F_74 ( V_92 , F_13 ( V_103 ) , V_122 ) ;
}
void F_100 ( unsigned int V_135 , unsigned int V_108 )
{
struct V_1 * V_1 = F_67 ( V_135 ) ;
unsigned int V_92 = F_60 ( V_135 ) ;
F_42 ( L_20 ,
V_1 , V_135 , V_92 , V_108 ) ;
if ( V_92 >= V_1 -> V_125 )
return;
F_74 ( V_92 , F_13 ( V_109 ) , 1 << V_108 ) ;
}
static int F_101 ( struct V_138 * V_139 , struct V_140 * V_40 )
{
return V_139 -> V_141 == NULL || V_139 -> V_141 == V_40 ;
}
static int F_102 ( struct V_138 * V_139 , unsigned int V_135 ,
T_8 V_142 )
{
struct V_1 * V_1 = V_139 -> V_143 ;
struct V_144 * V_145 ;
F_42 ( L_21 , V_135 , V_142 ) ;
if ( V_142 == V_1 -> V_146 )
return - V_126 ;
if ( V_1 -> V_147 && F_103 ( V_142 , V_1 -> V_147 ) )
return - V_126 ;
#ifdef F_104
else if ( V_142 >= V_1 -> V_93 [ 0 ] ) {
F_105 ( V_1 -> V_3 & V_4 ) ;
F_42 ( L_22 ) ;
F_106 ( V_135 , V_1 ) ;
F_107 ( V_135 , & V_1 -> V_148 ,
V_149 ) ;
return 0 ;
}
#endif
if ( V_142 >= V_1 -> V_94 [ 0 ] && V_142 <= V_1 -> V_94 [ 7 ] ) {
F_105 ( V_1 -> V_3 & V_4 ) ;
F_42 ( L_23 ) ;
F_106 ( V_135 , V_1 ) ;
F_107 ( V_135 , & V_1 -> V_150 ,
V_151 ) ;
return 0 ;
}
if ( V_142 >= V_1 -> V_125 )
return - V_126 ;
F_108 ( V_1 , V_142 ) ;
V_145 = & V_1 -> V_152 ;
#ifdef F_109
if ( F_35 ( V_1 , V_142 ) )
V_145 = & V_1 -> V_153 ;
#endif
F_42 ( L_24 , V_145 ) ;
F_106 ( V_135 , V_1 ) ;
F_107 ( V_135 , V_145 , V_151 ) ;
F_110 ( V_135 , V_127 ) ;
if ( ! F_59 ( V_1 , V_142 ) && ( V_1 -> V_3 & V_154 ) ) {
F_99 ( V_135 , V_142 ) ;
F_100 ( V_135 , F_1 ( V_1 ) ) ;
F_111 ( V_135 , 8 ) ;
}
return 0 ;
}
static int F_112 ( struct V_138 * V_139 , struct V_140 * V_155 ,
const T_1 * V_156 , unsigned int V_157 ,
T_8 * V_158 , unsigned int * V_159 )
{
struct V_1 * V_1 = V_139 -> V_143 ;
static unsigned char V_160 [ 4 ] = {
V_112 ,
V_120 ,
V_118 ,
V_115 ,
} ;
* V_158 = V_156 [ 0 ] ;
if ( V_157 >= 4 && ( V_1 -> V_3 & V_161 ) ) {
switch ( V_156 [ 2 ] ) {
case 0 :
case 1 :
break;
case 2 :
if ( V_156 [ 0 ] >= F_113 ( V_1 -> V_93 ) )
return - V_126 ;
* V_158 = V_1 -> V_93 [ V_156 [ 0 ] ] ;
break;
case 3 :
if ( V_156 [ 0 ] >= F_113 ( V_1 -> V_94 ) )
return - V_126 ;
* V_158 = V_1 -> V_94 [ V_156 [ 0 ] ] ;
break;
default:
F_114 ( L_25 ,
V_105 , V_156 [ 2 ] ) ;
return - V_126 ;
}
* V_159 = V_160 [ V_156 [ 1 ] & 3 ] ;
} else if ( V_157 > 1 ) {
T_1 V_51 = 0x3 ;
if ( F_115 ( V_162 ) )
V_51 = 0x1 ;
* V_159 = V_160 [ V_156 [ 1 ] & V_51 ] ;
} else
* V_159 = V_127 ;
F_42 ( L_26 ,
V_157 , V_156 [ 0 ] , V_156 [ 1 ] , * V_158 , * V_159 ) ;
return 0 ;
}
static void F_116 ( unsigned int V_78 , struct V_163 * V_164 )
{
struct V_144 * V_145 = F_117 ( V_164 ) ;
struct V_1 * V_1 = F_118 ( V_164 ) ;
unsigned int V_135 ;
F_24 ( ! ( V_1 -> V_3 & V_4 ) ) ;
V_135 = F_119 ( V_1 ) ;
if ( V_135 != V_165 )
F_120 ( V_135 ) ;
V_145 -> V_166 ( & V_164 -> V_97 ) ;
}
struct V_1 * T_3 F_121 ( struct V_140 * V_40 ,
T_2 V_38 ,
unsigned int V_3 ,
unsigned int V_167 ,
unsigned int V_125 ,
const char * V_102 )
{
int V_77 , V_168 , V_169 ;
struct V_1 * V_1 ;
T_1 V_170 ;
const char * V_171 ;
const T_1 * V_172 ;
static const struct V_173 T_9 V_174 [] = {
{ . type = L_27 , } ,
{ . V_175 = L_27 , } ,
{} ,
} ;
if ( V_40 ) {
V_40 = F_122 ( V_40 ) ;
} else {
V_40 = F_123 ( NULL , V_174 ) ;
if ( ! V_40 )
return NULL ;
}
if ( ! V_38 ) {
if ( F_124 ( V_40 , L_28 , NULL ) ) {
V_3 |= V_41 ;
} else {
struct V_176 V_42 ;
if ( F_125 ( V_40 , 0 , & V_42 ) )
goto V_177;
V_38 = V_42 . V_178 ;
}
}
V_1 = F_54 ( sizeof( struct V_1 ) , V_82 ) ;
if ( V_1 == NULL )
goto V_177;
V_1 -> V_102 = V_102 ;
V_1 -> V_40 = V_40 ;
V_1 -> V_179 = V_38 ;
V_1 -> V_152 = V_180 ;
V_1 -> V_152 . V_102 = V_102 ;
if ( ! ( V_3 & V_4 ) )
V_1 -> V_152 . V_181 = F_93 ;
#ifdef F_109
V_1 -> V_153 = V_182 ;
V_1 -> V_153 . V_102 = V_102 ;
if ( ! ( V_3 & V_4 ) )
V_1 -> V_153 . V_181 = F_93 ;
#endif
#ifdef F_104
V_1 -> V_148 = V_183 ;
V_1 -> V_148 . V_102 = V_102 ;
#endif
V_1 -> V_150 = V_184 ;
V_1 -> V_150 . V_102 = V_102 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_167 = V_167 ;
V_1 -> V_125 = V_125 ;
V_1 -> V_185 = 0 ;
if ( V_3 & V_186 )
V_169 = 2047 ;
else
V_169 = 255 ;
V_1 -> V_94 [ 0 ] = V_169 - 12 ;
V_1 -> V_94 [ 1 ] = V_169 - 11 ;
V_1 -> V_94 [ 2 ] = V_169 - 10 ;
V_1 -> V_94 [ 3 ] = V_169 - 9 ;
V_1 -> V_94 [ 4 ] = V_169 - 8 ;
V_1 -> V_94 [ 5 ] = V_169 - 7 ;
V_1 -> V_94 [ 6 ] = V_169 - 6 ;
V_1 -> V_94 [ 7 ] = V_169 - 5 ;
V_1 -> V_93 [ 0 ] = V_169 - 4 ;
V_1 -> V_93 [ 1 ] = V_169 - 3 ;
V_1 -> V_93 [ 2 ] = V_169 - 2 ;
V_1 -> V_93 [ 3 ] = V_169 - 1 ;
V_1 -> V_146 = V_169 ;
if ( F_124 ( V_1 -> V_40 , L_29 , NULL ) != NULL )
V_1 -> V_3 |= V_187 ;
if ( F_126 ( V_1 -> V_40 , L_30 ) )
V_1 -> V_3 |= V_161 ;
V_172 = F_124 ( V_1 -> V_40 , L_31 , & V_168 ) ;
if ( V_172 ) {
unsigned int V_188 = F_127 ( V_169 + 1 ) ;
V_1 -> V_147 = F_54 ( V_188 * sizeof( long ) , V_82 ) ;
F_24 ( V_1 -> V_147 == NULL ) ;
for ( V_77 = 0 ; V_77 < V_168 / sizeof( T_1 ) ; V_77 ++ ) {
if ( V_172 [ V_77 ] > V_169 )
continue;
F_128 ( V_172 [ V_77 ] , V_1 -> V_147 ) ;
}
}
#ifdef F_129
V_1 -> V_189 = V_190 [ F_130 ( V_3 ) ] ;
#endif
if ( V_3 & V_187 )
V_1 -> V_16 = V_11 ;
else
V_1 -> V_16 = V_13 ;
#ifdef F_4
if ( V_3 & V_41 )
V_1 -> V_16 = V_9 ;
#else
F_24 ( V_3 & V_41 ) ;
#endif
F_29 ( V_1 , V_1 -> V_179 , & V_1 -> V_21 , F_13 ( V_191 ) , 0x1000 ) ;
F_29 ( V_1 , V_1 -> V_179 , & V_1 -> V_25 , F_13 ( V_192 ) , 0x1000 ) ;
if ( F_124 ( V_1 -> V_40 , L_32 , NULL ) )
V_1 -> V_3 |= V_154 ;
if ( ( V_3 & V_193 ) && ! ( V_1 -> V_3 & V_154 ) ) {
F_34 ( V_74 L_33 ) ;
F_31 ( V_1 -> V_21 , F_13 ( V_194 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_194 ) )
| V_195 ) ;
while( F_32 ( V_1 -> V_21 , F_13 ( V_194 ) )
& V_195 )
F_131 () ;
}
if ( V_3 & V_196 )
F_31 ( V_1 -> V_21 , F_13 ( V_194 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_194 ) )
| V_197 ) ;
if ( V_3 & V_198 )
F_31 ( V_1 -> V_21 , F_13 ( V_194 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_194 ) )
| V_199 ) ;
V_170 = F_32 ( V_1 -> V_21 , F_13 ( V_200 ) ) ;
if ( V_167 == 0 ) {
if ( V_3 & V_201 )
V_1 -> V_185 = V_1 -> V_125 ;
else
V_1 -> V_185 =
( ( V_170 & V_202 )
>> V_203 ) + 1 ;
}
F_24 ( F_132 () > V_204 ) ;
F_133 (i) {
unsigned int V_2 = F_64 ( V_77 ) ;
F_29 ( V_1 , V_1 -> V_179 , & V_1 -> V_26 [ V_2 ] ,
F_13 ( V_205 ) + V_2 * F_13 ( V_206 ) ,
0x1000 ) ;
}
if ( V_1 -> V_167 == 0 ) {
V_1 -> V_167 = V_1 -> V_185 ;
F_29 ( V_1 , V_1 -> V_179 , & V_1 -> V_33 [ 0 ] ,
F_13 ( V_207 ) , F_13 ( V_34 ) * V_1 -> V_167 ) ;
}
V_1 -> V_29 = 1 + F_134 ( V_1 -> V_167 - 1 ) ;
V_1 -> V_31 = ( 1 << V_1 -> V_29 ) - 1 ;
V_1 -> V_208 = F_135 ( V_1 -> V_40 , V_209 ,
V_167 ? V_167 : V_1 -> V_185 ,
& V_210 ,
V_3 & V_186 ? 2048 : 256 ) ;
if ( V_1 -> V_208 == NULL )
return NULL ;
V_1 -> V_208 -> V_143 = V_1 ;
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
F_34 ( V_43 L_38
L_39 ,
V_102 , V_171 , ( unsigned long long ) V_1 -> V_179 , F_132 () ) ;
F_34 ( V_43 L_40 ,
V_1 -> V_167 , V_1 -> V_29 , V_1 -> V_31 ) ;
V_1 -> V_88 = V_212 ;
V_212 = V_1 ;
if ( ! ( V_3 & V_4 ) ) {
V_213 = V_1 ;
F_136 ( V_1 -> V_208 ) ;
}
return V_1 ;
V_177:
F_137 ( V_40 ) ;
return NULL ;
}
void T_3 F_138 ( struct V_1 * V_1 , unsigned int V_214 ,
T_2 V_179 )
{
unsigned int V_215 = V_214 * V_1 -> V_167 ;
F_24 ( V_214 >= V_216 ) ;
F_29 ( V_1 ,
V_179 , & V_1 -> V_33 [ V_214 ] , 0 ,
F_13 ( V_34 ) * V_1 -> V_167 ) ;
if ( ( V_215 + V_1 -> V_167 ) > V_1 -> V_185 )
V_1 -> V_185 = V_215 + V_1 -> V_167 ;
}
void T_3 F_139 ( struct V_1 * V_1 , T_4 * V_128 , int V_217 )
{
V_1 -> V_128 = V_128 ;
V_1 -> V_129 = V_217 ;
}
void T_3 F_140 ( struct V_1 * V_1 )
{
int V_77 , V_2 ;
F_24 ( V_1 -> V_185 == 0 ) ;
F_34 ( V_43 L_41 , V_1 -> V_185 ) ;
F_70 ( F_13 ( V_218 ) , 0xf ) ;
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ ) {
F_31 ( V_1 -> V_25 ,
V_77 * F_13 ( V_24 ) +
F_13 ( V_219 ) ,
1 << F_2 () ) ;
F_31 ( V_1 -> V_25 ,
V_77 * F_13 ( V_24 ) +
F_13 ( V_23 ) ,
V_35 |
( 9 << V_220 ) |
( V_1 -> V_94 [ 0 ] + V_77 ) ) ;
}
F_30 ( V_1 ) ;
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ ) {
F_85 ( V_77 ,
V_35 |
( 10 << V_220 ) |
( V_1 -> V_93 [ 0 ] + V_77 ) ) ;
}
if ( V_1 -> V_125 == 0 )
V_1 -> V_125 = V_1 -> V_185 ;
F_42 ( L_42 , V_1 -> V_3 ) ;
if ( ( V_1 -> V_3 & V_221 ) && ! ( V_1 -> V_3 & V_4 ) ) {
F_53 ( V_1 ) ;
F_141 ( V_1 ) ;
}
F_142 ( V_1 ) ;
V_2 = F_1 ( V_1 ) ;
if ( ! ( V_1 -> V_3 & V_154 ) ) {
for ( V_77 = 0 ; V_77 < V_1 -> V_185 ; V_77 ++ ) {
T_1 V_122 = V_35 | V_77 |
( 8 << V_220 ) ;
if ( V_1 -> V_147 && F_103 ( V_77 , V_1 -> V_147 ) )
continue;
F_74 ( V_77 , F_13 ( V_103 ) , V_122 ) ;
F_74 ( V_77 , F_13 ( V_109 ) , 1 << V_2 ) ;
}
}
F_31 ( V_1 -> V_21 , F_13 ( V_222 ) , V_1 -> V_146 ) ;
if ( ! ( V_1 -> V_3 & V_223 ) )
F_31 ( V_1 -> V_21 , F_13 ( V_194 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_194 ) )
| V_224 ) ;
if ( V_1 -> V_3 & V_225 )
F_31 ( V_1 -> V_21 , F_13 ( V_194 ) ,
F_32 ( V_1 -> V_21 , F_13 ( V_194 ) )
| V_226 ) ;
F_70 ( F_13 ( V_218 ) , 0 ) ;
#ifdef F_46
V_1 -> V_56 = F_143 ( V_1 -> V_185 * sizeof( * V_1 -> V_56 ) ,
V_82 ) ;
F_24 ( V_1 -> V_56 == NULL ) ;
#endif
if ( V_1 -> V_3 & V_4 ) {
int V_135 = F_144 ( V_1 -> V_40 , 0 ) ;
if ( V_135 != V_165 ) {
F_34 ( V_43 L_43 ,
V_1 -> V_40 -> V_227 , V_135 ) ;
F_145 ( V_135 , V_1 ) ;
F_146 ( V_135 , & F_116 ) ;
}
}
}
void T_3 F_147 ( struct V_1 * V_1 , T_1 V_228 )
{
T_1 V_229 ;
V_229 = F_32 ( V_1 -> V_21 , V_230 ) ;
V_229 &= ~ V_231 ;
V_229 |= F_148 ( V_228 ) ;
F_31 ( V_1 -> V_21 , V_230 , V_229 ) ;
}
void T_3 F_149 ( struct V_1 * V_1 , int V_232 )
{
unsigned long V_3 ;
T_1 V_229 ;
F_43 ( & V_233 , V_3 ) ;
V_229 = F_32 ( V_1 -> V_21 , V_230 ) ;
if ( V_232 )
V_229 |= V_234 ;
else
V_229 &= ~ V_234 ;
F_31 ( V_1 -> V_21 , V_230 , V_229 ) ;
F_45 ( & V_233 , V_3 ) ;
}
void F_111 ( unsigned int V_78 , unsigned int V_235 )
{
struct V_1 * V_1 = F_57 ( V_78 ) ;
unsigned int V_92 = F_60 ( V_78 ) ;
unsigned long V_3 ;
T_1 V_8 ;
if ( ! V_1 )
return;
F_43 ( & V_233 , V_3 ) ;
if ( F_59 ( V_1 , V_78 ) ) {
V_8 = F_86 ( V_92 - V_1 -> V_93 [ 0 ] ) &
~ V_236 ;
F_85 ( V_92 - V_1 -> V_93 [ 0 ] ,
V_8 | ( V_235 << V_220 ) ) ;
} else if ( F_61 ( V_1 , V_78 ) ) {
V_8 = F_91 ( V_92 - V_1 -> V_94 [ 0 ] ) &
~ V_236 ;
F_90 ( V_92 - V_1 -> V_94 [ 0 ] ,
V_8 | ( V_235 << V_220 ) ) ;
} else {
V_8 = F_75 ( V_92 , F_13 ( V_103 ) )
& ~ V_236 ;
F_74 ( V_92 , F_13 ( V_103 ) ,
V_8 | ( V_235 << V_220 ) ) ;
}
F_45 ( & V_233 , V_3 ) ;
}
void F_150 ( void )
{
#ifdef F_104
struct V_1 * V_1 = V_213 ;
unsigned long V_3 ;
T_1 V_237 = 1 << F_2 () ;
unsigned int V_77 ;
F_24 ( V_1 == NULL ) ;
F_42 ( L_44 , V_1 -> V_102 , F_2 () ) ;
F_43 ( & V_233 , V_3 ) ;
if ( V_238 ) {
for ( V_77 = 0 ; V_77 < V_1 -> V_185 ; V_77 ++ )
F_74 ( V_77 , F_13 ( V_109 ) ,
F_75 ( V_77 , F_13 ( V_109 ) ) | V_237 ) ;
}
F_70 ( F_13 ( V_218 ) , 0 ) ;
F_45 ( & V_233 , V_3 ) ;
#endif
}
int F_151 ( void )
{
struct V_1 * V_1 = V_213 ;
return F_71 ( F_13 ( V_218 ) ) ;
}
void F_152 ( int V_239 )
{
struct V_1 * V_1 = V_213 ;
V_239 &= V_240 ;
F_70 ( F_13 ( V_218 ) , V_239 ) ;
}
void F_153 ( int V_241 )
{
struct V_1 * V_1 = V_213 ;
unsigned long V_3 ;
T_1 V_237 = 1 << F_2 () ;
unsigned int V_77 ;
F_24 ( V_1 == NULL ) ;
F_42 ( L_45 , V_1 -> V_102 , F_2 () ) ;
F_43 ( & V_233 , V_3 ) ;
for ( V_77 = 0 ; V_77 < V_1 -> V_185 ; V_77 ++ )
F_74 ( V_77 , F_13 ( V_109 ) ,
F_75 ( V_77 , F_13 ( V_109 ) ) & ~ V_237 ) ;
F_70 ( F_13 ( V_218 ) , 0xf ) ;
F_69 ( V_1 ) ;
F_45 ( & V_233 , V_3 ) ;
}
static unsigned int F_154 ( struct V_1 * V_1 , int V_8 )
{
T_1 V_92 ;
V_92 = F_71 ( V_8 ) & F_13 ( V_137 ) ;
#ifdef F_155
F_42 ( L_46 , V_1 -> V_102 , V_8 , V_92 ) ;
#endif
if ( F_156 ( V_92 == V_1 -> V_146 ) ) {
if ( V_1 -> V_3 & V_242 )
F_69 ( V_1 ) ;
return V_165 ;
}
if ( F_156 ( V_1 -> V_147 && F_103 ( V_92 , V_1 -> V_147 ) ) ) {
F_157 ( V_243 L_47 ,
V_1 -> V_102 , ( int ) V_92 ) ;
F_69 ( V_1 ) ;
return V_165 ;
}
return F_158 ( V_1 -> V_208 , V_92 ) ;
}
unsigned int F_119 ( struct V_1 * V_1 )
{
return F_154 ( V_1 , F_13 ( V_244 ) ) ;
}
unsigned int F_159 ( void )
{
struct V_1 * V_1 = V_213 ;
F_24 ( V_1 == NULL ) ;
return F_119 ( V_1 ) ;
}
unsigned int F_160 ( void )
{
#ifdef F_161
struct V_1 * V_1 = V_213 ;
T_1 V_92 ;
F_24 ( V_1 == NULL ) ;
V_92 = F_162 ( V_245 ) ;
if ( F_156 ( V_92 == V_1 -> V_146 ) ) {
if ( V_1 -> V_3 & V_242 )
F_69 ( V_1 ) ;
return V_165 ;
}
if ( F_156 ( V_1 -> V_147 && F_103 ( V_92 , V_1 -> V_147 ) ) ) {
F_157 ( V_243 L_47 ,
V_1 -> V_102 , ( int ) V_92 ) ;
return V_165 ;
}
return F_158 ( V_1 -> V_208 , V_92 ) ;
#else
return V_165 ;
#endif
}
unsigned int F_163 ( void )
{
struct V_1 * V_1 = V_213 ;
F_24 ( V_1 == NULL ) ;
return F_154 ( V_1 , F_13 ( V_246 ) ) ;
}
void F_164 ( void )
{
struct V_1 * V_1 = V_213 ;
int V_77 ;
F_24 ( V_1 == NULL ) ;
F_34 ( V_43 L_48 ) ;
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ ) {
unsigned int V_247 = F_165 ( V_1 -> V_208 ,
V_1 -> V_93 [ 0 ] + V_77 ) ;
if ( V_247 == V_165 ) {
F_34 ( V_104 L_49 , V_248 [ V_77 ] ) ;
continue;
}
F_166 ( V_247 , V_77 ) ;
}
}
void F_167 ( int V_2 , int V_249 )
{
struct V_1 * V_1 = V_213 ;
T_1 V_250 ;
F_24 ( V_1 == NULL ) ;
if ( ( unsigned int ) V_249 > 3 ) {
F_34 ( L_50 ,
F_168 () , V_249 ) ;
return;
}
#ifdef F_169
F_42 ( L_51 , V_1 -> V_102 , V_249 ) ;
#endif
V_250 = 1 << F_64 ( V_2 ) ;
F_70 ( F_13 ( V_251 ) +
V_249 * F_13 ( V_252 ) , V_250 ) ;
}
int T_3 F_170 ( void )
{
int V_253 ;
F_42 ( L_52 ) ;
V_253 = F_171 ( V_254 ) ;
F_42 ( L_53 , V_253 ) ;
if ( V_253 > 1 )
F_164 () ;
return V_253 ;
}
void T_10 F_172 ( int V_2 )
{
F_150 () ;
}
void F_173 ( int V_2 )
{
struct V_1 * V_1 = V_213 ;
T_1 V_255 ;
int V_108 = F_64 ( V_2 ) ;
int V_77 ;
V_255 = F_32 ( V_1 -> V_21 , F_13 ( V_256 ) ) ;
V_255 |= ( 1 << V_108 ) ;
F_31 ( V_1 -> V_21 , F_13 ( V_256 ) , V_255 ) ;
F_32 ( V_1 -> V_21 , F_13 ( V_256 ) ) ;
V_255 &= ~ ( 1 << V_108 ) ;
F_31 ( V_1 -> V_21 , F_13 ( V_256 ) , V_255 ) ;
F_32 ( V_1 -> V_21 , F_13 ( V_256 ) ) ;
if ( V_1 -> V_3 & V_161 ) {
for ( V_77 = 0 ; V_77 < 15 ; V_77 ++ ) {
F_8 ( V_1 -> V_16 , & V_1 -> V_26 [ V_108 ] ,
V_257 , 0 ) ;
}
}
}
static void F_174 ( struct V_1 * V_1 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_1 -> V_185 ; V_77 ++ ) {
V_1 -> V_56 [ V_77 ] . V_258 =
F_75 ( V_77 , F_13 ( V_103 ) ) ;
V_1 -> V_56 [ V_77 ] . V_259 =
F_75 ( V_77 , F_13 ( V_109 ) ) ;
}
}
static int F_175 ( void )
{
struct V_1 * V_1 = V_212 ;
while ( V_1 ) {
F_174 ( V_1 ) ;
V_1 = V_1 -> V_88 ;
}
return 0 ;
}
static void F_176 ( struct V_1 * V_1 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_1 -> V_185 ; V_77 ++ ) {
F_74 ( V_77 , F_13 ( V_103 ) ,
V_1 -> V_56 [ V_77 ] . V_258 ) ;
F_74 ( V_77 , F_13 ( V_109 ) ,
V_1 -> V_56 [ V_77 ] . V_259 ) ;
#ifdef F_109
if ( V_1 -> V_45 ) {
struct V_46 * V_47 = & V_1 -> V_45 [ V_77 ] ;
if ( V_47 -> V_12 ) {
if ( ( V_1 -> V_56 [ V_77 ] . V_57 & 1 ) == 0 )
continue;
F_39 ( 0x10 + 2 * V_47 -> V_50 , V_47 -> V_12 + 2 ) ;
F_37 ( V_1 -> V_56 [ V_77 ] . V_57 & ~ 1 ,
V_47 -> V_12 + 4 ) ;
}
}
#endif
}
}
static void F_177 ( void )
{
struct V_1 * V_1 = V_212 ;
while ( V_1 ) {
F_176 ( V_1 ) ;
V_1 = V_1 -> V_88 ;
}
}
static int F_178 ( void )
{
F_179 ( & V_260 ) ;
return 0 ;
}
