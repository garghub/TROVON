int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_3 , 0 ) ;
if ( V_4 )
F_5 ( F_6 ( V_2 ) ,
L_1 , V_5 , V_4 ) ;
return V_4 ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_6 |= V_7 ;
F_1 ( V_2 , V_2 -> V_6 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_6 &= ~ V_7 ;
F_1 ( V_2 , V_2 -> V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
int V_8 )
{
T_1 V_9 ;
struct V_10 * V_11 ;
F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_12 ,
V_13 , 0 , 0 ,
& V_2 -> V_14 , & V_9 ) ;
if ( V_8 ) {
V_11 = V_2 -> V_15 [ V_16 ] ;
if ( V_2 -> V_14 & V_17 )
F_11 ( V_11 ) ;
else
F_12 ( V_11 ) ;
}
}
static int F_13 ( struct V_1 * V_2 , int V_18 )
{
int V_4 ;
T_1 V_19 , V_9 ;
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_20 ,
V_21 , V_18 , 0 , & V_19 , & V_9 ) ;
if ( V_4 ) {
F_14 ( L_2 , V_5 ,
V_4 ) ;
return - V_22 ;
}
V_2 -> V_23 = V_18 ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( L_3 , V_5 ) ;
F_17 ( & V_2 -> V_24 ) ;
if ( F_18 ( & V_2 -> V_25 ) == 1 ) {
F_16 ( L_4 , V_5 ) ;
F_1 ( V_2 , V_2 -> V_6 ) ;
F_19 ( V_2 ) ;
F_20 ( & V_2 -> V_26 ) ;
}
F_21 ( & V_2 -> V_24 ) ;
F_16 ( L_5 , V_5 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_16 ( L_3 , V_5 ) ;
F_17 ( & V_2 -> V_24 ) ;
if ( F_23 ( & V_2 -> V_25 ) == 0 ) {
F_16 ( L_4 , V_5 ) ;
F_24 ( & V_2 -> V_26 ) ;
V_3 = V_2 -> V_6 & ( V_27 |
V_28 ) ;
F_1 ( V_2 , V_3 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 , & V_2 -> V_29 ,
V_2 -> V_30 + V_31 ) ;
F_27 ( V_2 ) ;
}
F_21 ( & V_2 -> V_24 ) ;
F_16 ( L_5 , V_5 ) ;
}
static enum V_32
F_28 ( struct V_33 * V_30 )
{
return F_29 ( V_30 -> V_34 ) & V_35 ;
}
static void F_30 ( struct V_33 * V_30 ,
enum V_32 V_4 )
{
V_30 -> V_34 = F_31 ( V_4 |
( F_29 ( V_30 -> V_34 ) &
~ V_35 ) ) ;
F_32 () ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_33 * V_36 )
{
struct V_33 * V_30 ;
for ( V_30 = V_36 ; V_30 && V_30 -> V_37 ; V_30 = V_30 -> V_38 ) {
F_34 ( F_6 ( V_2 ) , V_30 -> V_37 ,
V_39 , V_40 ) ;
V_30 -> V_37 = 0 ;
}
}
static int T_2 F_35 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_33 * V_43 ,
int V_44 )
{
int V_45 ;
struct V_33 * V_30 ;
V_30 = V_43 ;
memset ( V_30 , 0 , sizeof( * V_30 ) * V_44 ) ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ , V_30 ++ ) {
F_30 ( V_30 , V_46 ) ;
V_30 -> V_37 =
F_36 ( F_6 ( V_2 ) , V_30 ,
V_39 ,
V_40 ) ;
if ( ! V_30 -> V_37 )
goto V_47;
V_30 -> V_38 = V_30 + 1 ;
V_30 -> V_48 = V_30 - 1 ;
}
( V_30 - 1 ) -> V_38 = V_43 ;
V_43 -> V_48 = ( V_30 - 1 ) ;
V_30 = V_43 ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ , V_30 ++ ) {
V_30 -> V_49 = F_31 ( V_30 -> V_38 -> V_37 ) ;
}
V_42 -> V_50 = V_43 ;
V_42 -> V_51 = V_43 ;
( V_30 - 1 ) -> V_49 = 0 ;
return 0 ;
V_47:
for ( V_45 -- , V_30 -- ; 0 <= V_45 ; V_45 -- , V_30 -- )
if ( V_30 -> V_37 )
F_34 ( F_6 ( V_2 ) , V_30 -> V_37 ,
V_39 ,
V_40 ) ;
return - V_52 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_33 * V_43 )
{
struct V_33 * V_30 ;
for ( V_30 = V_43 ; V_43 != V_30 -> V_38 ; V_30 ++ ) {
F_30 ( V_30 , V_53 ) ;
V_30 -> V_49 = F_31 ( V_30 -> V_38 -> V_37 ) ;
}
V_42 -> V_50 = V_43 ;
V_42 -> V_51 = ( V_30 - 1 ) ;
( V_30 - 1 ) -> V_49 = 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_33 * V_30 )
{
int V_54 ;
unsigned int V_55 ;
if ( F_28 ( V_30 ) != V_46 )
F_5 ( F_6 ( V_2 ) , L_6 , V_5 ) ;
V_55 = F_38 ( V_56 , V_57 ) ;
V_30 -> V_58 = F_39 ( V_55 + V_57 - 1 ) ;
if ( ! V_30 -> V_58 ) {
V_30 -> V_59 = 0 ;
F_5 ( F_6 ( V_2 ) ,
L_7 , V_5 ) ;
return - V_52 ;
}
V_30 -> V_60 = F_31 ( V_55 ) ;
V_30 -> V_34 = 0 ;
V_30 -> V_61 = 0 ;
V_30 -> V_62 = 0 ;
V_30 -> V_63 = 0 ;
V_54 = ( ( unsigned long ) V_30 -> V_58 -> V_64 ) &
( V_57 - 1 ) ;
if ( V_54 )
F_40 ( V_30 -> V_58 , V_57 - V_54 ) ;
V_30 -> V_59 = F_31 ( F_36 ( F_6 ( V_2 ) ,
V_30 -> V_58 -> V_64 ,
V_56 ,
V_65 ) ) ;
if ( ! V_30 -> V_59 ) {
F_41 ( V_30 -> V_58 ) ;
V_30 -> V_58 = NULL ;
F_5 ( F_6 ( V_2 ) ,
L_8 , V_5 ) ;
F_30 ( V_30 , V_46 ) ;
return - V_52 ;
} else {
F_30 ( V_30 , V_53 ) ;
return 0 ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_33 * V_30 = V_2 -> V_29 . V_50 ;
do {
if ( V_30 -> V_58 ) {
F_34 ( F_6 ( V_2 ) ,
F_29 ( V_30 -> V_59 ) ,
V_30 -> V_58 -> V_66 ,
V_65 ) ;
V_30 -> V_59 = 0 ;
F_41 ( V_30 -> V_58 ) ;
V_30 -> V_58 = NULL ;
F_30 ( V_30 ,
V_46 ) ;
}
V_30 = V_30 -> V_38 ;
} while ( V_30 != V_2 -> V_29 . V_50 );
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_33 * V_30 = V_2 -> V_29 . V_50 ;
int V_67 ;
do {
if ( ! V_30 -> V_58 ) {
V_67 = F_37 ( V_2 , V_30 ) ;
if ( V_67 )
goto rewind;
}
V_30 = V_30 -> V_38 ;
} while ( V_30 != V_2 -> V_29 . V_50 );
return 0 ;
rewind:
F_42 ( V_2 ) ;
return V_67 ;
}
static int T_2 F_44 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
int V_67 ;
V_42 = & V_2 -> V_29 ;
V_67 = F_43 ( V_2 ) ;
V_42 -> V_51 = V_2 -> V_68 -> V_48 ;
return V_67 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_33 * V_30 )
{
struct V_69 * V_58 = V_30 -> V_58 ;
F_46 ( ! ( F_29 ( V_30 -> V_70 ) & V_71 ) ) ;
F_34 ( F_6 ( V_2 ) , F_29 ( V_30 -> V_59 ) , V_58 -> V_66 ,
V_72 ) ;
F_41 ( V_58 ) ;
V_30 -> V_59 = 0 ;
V_30 -> V_60 = 0 ;
V_30 -> V_49 = 0 ;
V_30 -> V_61 = 0 ;
V_30 -> V_62 = 0 ;
V_30 -> V_70 = 0 ;
V_30 -> V_63 = 0 ;
V_30 -> V_58 = NULL ;
F_30 ( V_30 , V_46 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_15 [ V_16 ] ) ;
if ( V_2 -> V_15 [ V_73 ] )
F_48 ( V_2 -> V_15 [ V_73 ] ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 -> V_15 [ V_16 ] ) ;
if ( V_2 -> V_15 [ V_73 ] )
F_50 ( V_2 -> V_15 [ V_73 ] ) ;
}
static void F_51 ( struct V_1 * V_2 , int V_74 )
{
struct V_41 * V_75 ;
enum V_32 V_4 ;
struct V_10 * V_15 ;
int V_76 = 0 ;
for ( V_75 = & V_2 -> V_75 ;
V_75 -> V_50 != V_75 -> V_51 && V_75 -> V_51 ;
V_75 -> V_51 = V_75 -> V_51 -> V_38 ) {
V_4 = F_28 ( V_75 -> V_51 ) ;
V_15 = V_75 -> V_51 -> V_58 -> V_77 ;
switch ( V_4 ) {
case V_78 :
case V_79 :
case V_80 :
if ( F_52 () )
F_5 ( F_6 ( V_2 ) ,
L_9 \
L_10 ,
V_5 , V_4 ) ;
V_15 -> V_81 . V_82 ++ ;
break;
case V_83 :
if ( V_75 -> V_51 -> V_58 ) {
V_15 -> V_81 . V_84 ++ ;
V_15 -> V_81 . V_85 +=
V_75 -> V_51 -> V_58 -> V_66 ;
}
break;
case V_53 :
default:
if ( ! V_74 )
goto V_86;
}
F_45 ( V_2 , V_75 -> V_51 ) ;
V_76 ++ ;
}
V_86:
if ( ! V_74 && V_76 )
F_49 ( V_2 ) ;
}
void F_53 ( struct V_10 * V_15 )
{
struct V_1 * V_2 = F_54 ( V_15 ) ;
struct V_87 * V_88 ;
unsigned int V_45 ;
T_3 * V_89 ;
T_1 V_90 ;
int V_4 ;
V_4 = F_55 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
0 , 1 ) ;
if ( V_4 )
F_56 ( F_6 ( V_2 ) ,
L_11 ,
V_4 ) ;
V_4 = F_57 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_91 , 0 ) ;
if ( V_4 )
F_56 ( F_6 ( V_2 ) ,
L_12 ,
V_4 ) ;
if ( ( V_15 -> V_92 & V_93 ) ||
( F_58 ( V_15 ) > V_94 ) ) {
V_4 = F_57 ( F_3 ( V_2 ) ,
F_4 ( V_2 ) ,
0 , 1 ) ;
if ( V_4 )
F_56 ( F_6 ( V_2 ) ,
L_12 ,
V_4 ) ;
return;
}
F_59 (ha, netdev) {
V_90 = 0 ;
V_89 = V_88 -> V_90 ;
for ( V_45 = 0 ; V_45 < V_95 ; V_45 ++ ) {
V_90 <<= 8 ;
V_90 |= * V_89 ++ ;
}
V_4 = F_57 ( F_3 ( V_2 ) ,
F_4 ( V_2 ) ,
V_90 , 0 ) ;
if ( V_4 )
F_56 ( F_6 ( V_2 ) ,
L_12 ,
V_4 ) ;
}
}
static inline void F_19 ( struct V_1 * V_2 )
{
int V_4 ;
#ifdef F_60
if ( F_28 ( V_2 -> V_29 . V_50 ) !=
V_53 ) {
F_61 ( V_96 L_13 , V_5 ,
F_29 ( V_2 -> V_29 . V_50 -> V_34 ) ) ;
F_61 ( V_96 L_14 , V_5 ,
F_29 ( V_2 -> V_29 . V_50 -> V_49 ) ) ;
F_61 ( V_96 L_15 , V_5 ,
V_2 -> V_29 . V_50 ) ;
}
#endif
V_4 = F_62 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_2 -> V_29 . V_50 -> V_37 , 0 ) ;
if ( V_4 )
F_5 ( F_6 ( V_2 ) ,
L_16 , V_4 ) ;
}
static inline void F_25 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_63 ( F_3 ( V_2 ) , F_4 ( V_2 ) , 0 ) ;
if ( V_4 )
F_56 ( F_6 ( V_2 ) ,
L_17 , V_4 ) ;
}
static inline void F_27 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_64 ( F_3 ( V_2 ) , F_4 ( V_2 ) , 0 ) ;
if ( V_4 )
F_56 ( F_6 ( V_2 ) ,
L_18 , V_4 ) ;
}
int F_65 ( struct V_10 * V_15 )
{
struct V_1 * V_2 ;
F_16 ( L_19 , V_5 ) ;
F_48 ( V_15 ) ;
F_12 ( V_15 ) ;
V_2 = F_54 ( V_15 ) ;
F_22 ( V_2 ) ;
F_16 ( L_5 , V_5 ) ;
return 0 ;
}
static struct V_33 *
F_66 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_75 . V_50 )
return NULL ;
if ( V_2 -> V_75 . V_51 != V_2 -> V_75 . V_50 -> V_38 &&
F_28 ( V_2 -> V_75 . V_50 ) ==
V_46 )
return V_2 -> V_75 . V_50 ;
else
return NULL ;
}
static void F_67 ( struct V_33 * V_30 ,
struct V_69 * V_58 )
{
if ( V_58 -> V_97 != V_98 )
V_30 -> V_34 =
F_31 ( V_99 |
V_100 ) ;
else {
if ( V_58 -> V_101 == F_68 ( V_102 ) ) {
if ( F_69 ( V_58 ) -> V_101 == V_103 )
V_30 -> V_34 =
F_31 ( V_104 |
V_100 ) ;
else if ( F_69 ( V_58 ) -> V_101 == V_105 )
V_30 -> V_34 =
F_31 ( V_106 |
V_100 ) ;
else
V_30 -> V_34 =
F_31 ( V_99 |
V_100 ) ;
}
}
}
static inline struct V_69 * F_70 ( struct V_69 * V_58 ,
unsigned short V_107 )
{
struct V_108 * V_109 ;
static unsigned int V_110 ;
if ( F_71 ( V_58 ) < V_111 ) {
struct V_69 * V_112 = V_58 ;
F_16 ( L_20 , V_5 , F_71 ( V_58 ) , V_110 ) ;
V_58 = F_72 ( V_112 , V_111 ) ;
if ( ! V_58 )
return NULL ;
F_41 ( V_112 ) ;
}
V_109 = (struct V_108 * ) F_73 ( V_58 , V_111 ) ;
memmove ( V_58 -> V_64 , V_58 -> V_64 + V_111 , 2 * V_95 ) ;
V_109 -> V_113 = F_74 ( V_114 ) ;
V_109 -> V_115 = F_68 ( V_107 ) ;
return V_58 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_33 * V_30 ,
struct V_69 * V_58 )
{
T_4 V_116 ;
if ( V_2 -> V_117 ) {
struct V_69 * V_118 ;
enum V_119 type ;
type = F_76 ( V_58 -> V_77 ) -> type ;
V_118 = F_70 ( V_58 ,
V_2 -> V_120 [ type ] . V_121 ) ;
if ( ! V_118 )
return - V_52 ;
V_58 = V_118 ;
}
V_116 = F_36 ( F_6 ( V_2 ) , V_58 -> V_64 , V_58 -> V_66 , V_72 ) ;
if ( ! V_116 ) {
F_56 ( F_6 ( V_2 ) ,
L_21 ,
V_58 -> V_64 , V_58 -> V_66 ) ;
return - V_52 ;
}
V_30 -> V_59 = F_31 ( V_116 ) ;
V_30 -> V_60 = F_31 ( V_58 -> V_66 ) ;
V_30 -> V_58 = V_58 ;
V_30 -> V_70 = 0 ;
V_30 -> V_49 = 0 ;
F_67 ( V_30 , V_58 ) ;
V_2 -> V_75 . V_50 = V_30 -> V_38 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_33 * V_30 )
{
int V_4 = 0 ;
if ( V_2 -> V_122 )
return 0 ;
if ( F_28 ( V_30 ) == V_53 ) {
V_2 -> V_122 = 1 ;
V_4 = F_78 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_30 -> V_37 , 0 ) ;
if ( V_4 )
F_5 ( F_6 ( V_2 ) , L_22 \
L_23 , V_4 ) ;
}
return V_4 ;
}
int F_79 ( struct V_69 * V_58 , struct V_10 * V_15 )
{
struct V_1 * V_2 = F_54 ( V_15 ) ;
struct V_33 * V_30 ;
int V_123 ;
unsigned long V_92 ;
F_80 ( & V_2 -> V_124 , V_92 ) ;
F_51 ( V_2 , 0 ) ;
V_30 = F_66 ( V_2 ) ;
if ( ! V_30 ) {
F_47 ( V_2 ) ;
F_81 ( & V_2 -> V_124 , V_92 ) ;
return V_125 ;
}
V_123 = F_75 ( V_2 , V_30 , V_58 ) ;
if ( V_123 ) {
V_15 -> V_81 . V_82 ++ ;
F_41 ( V_58 ) ;
F_81 ( & V_2 -> V_124 , V_92 ) ;
return V_126 ;
}
V_30 -> V_48 -> V_49 = F_31 ( V_30 -> V_37 ) ;
F_32 () ;
if ( F_77 ( V_2 , V_30 ) ) {
V_15 -> V_81 . V_82 ++ ;
F_45 ( V_2 , V_30 ) ;
F_45 ( V_2 , V_30 -> V_38 ) ;
V_2 -> V_75 . V_51 = V_30 -> V_38 -> V_38 ;
F_5 ( F_6 ( V_2 ) , L_24 , V_5 ) ;
}
F_81 ( & V_2 -> V_124 , V_92 ) ;
return V_126 ;
}
static void F_82 ( struct V_33 * V_30 ,
struct V_1 * V_2 ,
struct V_10 * V_15 )
{
struct V_69 * V_58 = V_30 -> V_58 ;
T_5 V_70 , V_63 ;
V_70 = F_29 ( V_30 -> V_70 ) ;
V_63 = F_29 ( V_30 -> V_63 ) ;
F_34 ( F_6 ( V_2 ) , F_29 ( V_30 -> V_59 ) ,
V_56 ,
V_65 ) ;
F_83 ( V_58 , F_29 ( V_30 -> V_62 ) ?
F_29 ( V_30 -> V_62 ) :
F_29 ( V_30 -> V_61 ) ) ;
if ( ! V_30 -> V_62 )
F_5 ( F_6 ( V_2 ) , L_25 ,
F_29 ( V_30 -> V_61 ) ,
F_29 ( V_30 -> V_60 ) ,
F_29 ( V_30 -> V_34 ) ) ;
V_30 -> V_58 = NULL ;
F_84 ( V_58 , 2 ) ;
V_58 -> V_101 = F_85 ( V_58 , V_15 ) ;
if ( V_15 -> V_127 & V_128 ) {
if ( ( V_70 & V_129 ) &&
( ! ( V_63 & V_130 ) ) )
V_58 -> V_97 = V_131 ;
else
F_86 ( V_58 ) ;
} else
F_86 ( V_58 ) ;
V_15 -> V_81 . V_132 ++ ;
V_15 -> V_81 . V_133 += V_58 -> V_66 ;
F_87 ( V_58 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
enum V_32 V_4 ;
struct V_41 * V_42 = & V_2 -> V_29 ;
struct V_33 * V_30 = V_42 -> V_50 ;
struct V_10 * V_15 = NULL ;
int V_134 ;
V_4 = F_28 ( V_30 ) ;
V_134 =
F_29 ( V_30 -> V_34 ) &
V_135 ;
if ( V_4 == V_53 )
return 0 ;
if ( V_4 == V_46 ) {
F_89 ( F_6 ( V_2 ) , L_26 , V_30 ) ;
return 0 ;
}
if ( V_2 -> V_117 ) {
unsigned int V_45 ;
T_6 V_136 ;
V_136 = * ( T_6 * ) ( V_30 -> V_58 -> V_64 ) & V_137 ;
for ( V_45 = 0 ; V_45 < V_138 ; V_45 ++ ) {
if ( V_2 -> V_120 [ V_45 ] . V_139 == V_136 ) {
V_15 = V_2 -> V_15 [ V_45 ] ;
break;
}
} ;
if ( V_138 <= V_45 ) {
F_14 ( L_27 , V_5 , V_136 ) ;
goto V_140;
}
} else
V_15 = V_2 -> V_15 [ V_16 ] ;
if ( ( V_4 == V_78 ) ||
( V_4 == V_79 ) ||
( V_4 == V_80 ) ) {
F_5 ( F_6 ( V_2 ) , L_28 ,
V_4 ) ;
V_15 -> V_81 . V_141 ++ ;
goto V_140;
}
if ( V_4 == V_142 ) {
F_5 ( F_6 ( V_2 ) , L_29 ) ;
goto V_140;
}
if ( V_4 != V_143 ) {
F_89 ( F_6 ( V_2 ) , L_30 ,
V_4 ) ;
goto V_140;
}
F_82 ( V_30 , V_2 , V_15 ) ;
V_140:
V_30 -> V_49 = 0 ;
F_30 ( V_30 , V_46 ) ;
F_37 ( V_2 , V_30 ) ;
V_42 -> V_51 = V_30 ;
V_42 -> V_50 = V_30 -> V_38 ;
V_30 -> V_48 -> V_49 = F_31 ( V_30 -> V_37 ) ;
if ( V_134 ) {
V_2 -> V_144 = 1 ;
F_89 ( F_6 ( V_2 ) , L_31 ) ;
}
return 1 ;
}
static int F_90 ( struct V_145 * V_26 , int V_146 )
{
struct V_1 * V_2 = F_91 ( V_26 , struct V_1 , V_26 ) ;
int V_147 = 0 ;
while ( V_147 < V_146 ) {
if ( ! F_88 ( V_2 ) )
break;
V_147 ++ ;
}
if ( V_147 < V_146 ) {
F_92 ( V_26 ) ;
F_7 ( V_2 ) ;
}
return V_147 ;
}
int F_93 ( struct V_10 * V_15 , int V_148 )
{
if ( ( V_148 < V_149 ) ||
( V_148 > V_56 ) ) {
return - V_150 ;
}
V_15 -> V_151 = V_148 ;
return 0 ;
}
static T_7 F_94 ( int V_152 , void * V_153 )
{
unsigned long V_92 ;
struct V_1 * V_2 = V_153 ;
T_1 V_4 ;
V_4 = V_2 -> V_154 ;
if ( ! V_4 )
return V_155 ;
V_4 &= V_2 -> V_6 ;
if ( V_2 -> V_144 ) {
V_2 -> V_144 = 0 ;
F_19 ( V_2 ) ;
}
if ( V_4 & V_7 ) {
F_8 ( V_2 ) ;
F_95 ( & V_2 -> V_26 ) ;
}
if ( V_4 & V_156 ) {
F_80 ( & V_2 -> V_124 , V_92 ) ;
V_2 -> V_122 = 0 ;
F_51 ( V_2 , 0 ) ;
F_77 ( V_2 , V_2 -> V_75 . V_51 ) ;
F_81 ( & V_2 -> V_124 , V_92 ) ;
}
if ( V_4 & V_157 )
F_9 ( V_2 , 1 ) ;
#ifdef F_96
if ( V_4 & ( V_27 |
V_28 ) )
F_97 ( V_2 -> V_15 [ V_73 ] , V_4 ) ;
#endif
return V_158 ;
}
void F_98 ( struct V_10 * V_15 )
{
struct V_1 * V_2 = F_54 ( V_15 ) ;
F_1 ( V_2 , 0 ) ;
F_94 ( V_15 -> V_152 , V_15 ) ;
F_1 ( V_2 , V_2 -> V_6 ) ;
}
int F_99 ( struct V_10 * V_15 )
{
struct V_1 * V_2 = F_54 ( V_15 ) ;
F_89 ( F_6 ( V_2 ) , L_32 , V_5 , V_15 ) ;
F_15 ( V_2 ) ;
F_100 ( V_15 ) ;
F_9 ( V_2 , 1 ) ;
F_89 ( F_6 ( V_2 ) , L_33 , V_5 ) ;
return 0 ;
}
void F_101 ( struct V_10 * V_15 ,
struct V_159 * V_160 )
{
strncpy ( V_160 -> V_161 , V_162 , sizeof( V_160 -> V_161 ) - 1 ) ;
strncpy ( V_160 -> V_163 , V_164 , sizeof( V_160 -> V_163 ) - 1 ) ;
}
static int F_102 ( struct V_10 * V_15 ,
struct V_165 * V_166 )
{
struct V_1 * V_2 = F_54 ( V_15 ) ;
F_9 ( V_2 , 0 ) ;
if ( V_2 -> V_14 & V_167 )
V_166 -> V_168 = V_169 ;
else
V_166 -> V_168 = V_170 ;
switch ( V_2 -> V_14 & V_171 ) {
case V_172 :
F_103 ( V_166 , V_173 ) ;
break;
case V_174 :
F_103 ( V_166 , V_175 ) ;
break;
case V_176 :
F_103 ( V_166 , V_177 ) ;
break;
default:
F_14 ( L_34 , V_5 ) ;
F_103 ( V_166 , V_173 ) ;
break;
}
V_166 -> V_178 = V_179 | V_180 |
V_181 | V_182 |
V_183 | V_184 |
V_185 ;
V_166 -> V_186 = V_166 -> V_178 ;
if ( V_2 -> V_23 & V_187 ) {
V_166 -> V_188 = V_189 ;
} else {
V_166 -> V_188 = V_190 ;
V_166 -> V_186 &= ~ V_191 ;
}
V_166 -> V_192 = V_193 ;
return 0 ;
}
static int F_104 ( struct V_10 * V_15 ,
struct V_165 * V_166 )
{
struct V_1 * V_2 = F_54 ( V_15 ) ;
T_1 V_18 ;
int V_67 ;
if ( V_166 -> V_188 == V_189 ) {
V_18 = V_187 ;
} else {
switch ( V_166 -> V_194 ) {
case V_173 :
V_18 = V_172 ;
break;
case V_175 :
V_18 = V_174 ;
break;
case V_177 :
V_18 = V_176 ;
break;
default:
return - V_150 ;
}
if ( V_166 -> V_168 == V_169 )
V_18 |= V_167 ;
else if ( V_166 -> V_194 == V_177 ) {
F_14 ( L_35 ) ;
return - V_150 ;
}
}
V_67 = F_13 ( V_2 , V_18 ) ;
if ( V_67 )
return V_67 ;
return 0 ;
}
static void F_105 ( struct V_10 * V_15 ,
struct V_195 * V_196 )
{
if ( 0 <= F_106 ( 2 , 2 , 0 ) )
V_196 -> V_178 = V_197 ;
else
V_196 -> V_178 = 0 ;
V_196 -> V_198 = F_107 () ? V_196 -> V_178 : 0 ;
memset ( & V_196 -> V_199 , 0 , sizeof( V_196 -> V_199 ) ) ;
}
static int F_108 ( struct V_10 * V_15 ,
struct V_195 * V_196 )
{
int V_4 ;
struct V_1 * V_2 ;
T_1 V_19 , V_9 ;
if ( F_106 ( 2 , 2 , 0 ) < 0 ||
! F_109 ( V_200 ) )
return - V_201 ;
if ( V_196 -> V_198 & ~ V_197 )
return - V_150 ;
V_2 = F_54 ( V_15 ) ;
if ( V_196 -> V_198 & V_197 ) {
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_202 ,
V_203 ,
0 , V_204 ,
& V_19 , & V_9 ) ;
if ( V_4 ) {
F_14 ( L_36 , V_5 ,
V_4 ) ;
V_4 = - V_205 ;
goto V_206;
}
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_202 ,
V_207 ,
0 , V_208 ,
& V_19 , & V_9 ) ;
if ( ! V_4 )
F_110 ( 1 ) ;
else {
F_14 ( L_37 ,
V_5 , V_4 ) ;
V_4 = - V_205 ;
}
} else {
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_202 ,
V_203 ,
0 , V_209 ,
& V_19 , & V_9 ) ;
if ( V_4 ) {
F_14 ( L_38 , V_5 ,
V_4 ) ;
V_4 = - V_205 ;
goto V_206;
}
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_202 ,
V_210 ,
0 , V_208 ,
& V_19 , & V_9 ) ;
if ( ! V_4 )
F_110 ( 0 ) ;
else {
F_14 ( L_39 ,
V_5 , V_4 ) ;
V_4 = - V_205 ;
}
}
V_206:
return V_4 ;
}
static void F_111 ( struct V_211 * V_212 )
{
struct V_1 * V_2 =
F_91 ( V_212 , struct V_1 , V_213 ) ;
struct V_10 * V_15 = V_2 -> V_15 [ V_16 ] ;
F_5 ( F_6 ( V_2 ) , L_40 , V_5 ) ;
if ( ! ( V_15 -> V_92 & V_214 ) )
goto V_86;
F_112 ( V_15 ) ;
F_65 ( V_15 ) ;
F_99 ( V_15 ) ;
F_113 ( V_15 ) ;
V_86:
F_114 ( & V_2 -> V_215 ) ;
}
void F_115 ( struct V_10 * V_15 )
{
struct V_1 * V_2 ;
V_2 = F_54 ( V_15 ) ;
F_116 ( & V_2 -> V_215 ) ;
if ( V_15 -> V_92 & V_214 )
F_117 ( & V_2 -> V_213 ) ;
else
F_114 ( & V_2 -> V_215 ) ;
}
static void T_2 F_118 ( struct V_10 * V_15 ,
struct V_145 * V_26 )
{
V_15 -> V_216 = V_217 ;
F_119 ( V_15 , V_26 ,
F_90 , V_218 ) ;
V_15 -> V_219 = & V_220 ;
V_15 -> V_221 = & V_222 ;
}
int T_2 F_120 ( struct V_10 * V_15 ,
struct V_1 * V_2 )
{
int V_4 ;
T_1 V_19 , V_9 ;
V_15 -> V_223 = V_224 | V_128 ;
V_15 -> V_127 = V_224 ;
if ( V_225 )
V_15 -> V_127 |= V_128 ;
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_226 ,
0 , 0 , 0 , & V_19 , & V_9 ) ;
V_19 <<= 16 ;
if ( V_4 || ! F_121 ( ( V_227 * ) & V_19 ) ) {
F_5 ( F_6 ( V_2 ) ,
L_41 ,
V_5 , V_4 ) ;
return - V_150 ;
}
memcpy ( V_15 -> V_228 , & V_19 , V_95 ) ;
if ( V_2 -> V_117 ) {
V_15 -> V_229 += V_111 ;
V_15 -> V_127 |= V_230 ;
}
V_4 = F_122 ( V_15 ) ;
if ( V_4 ) {
F_56 ( F_6 ( V_2 ) , L_42 ,
V_5 , V_15 -> V_231 , V_4 ) ;
return V_4 ;
}
F_5 ( F_6 ( V_2 ) , L_43 ,
V_15 -> V_231 , V_15 -> V_228 ) ;
return 0 ;
}
static struct V_1 * T_2 F_123 ( struct V_10 * * V_15 )
{
struct V_1 * V_2 ;
struct V_232 * V_192 ;
void * V_89 ;
T_8 V_233 ;
F_124 ( F_125 ( struct V_1 , V_154 ) % 8 ) ;
F_124 ( F_125 ( struct V_1 , V_30 ) % 32 ) ;
V_233 =
sizeof( struct V_1 ) +
sizeof( struct V_33 ) * V_234 +
sizeof( struct V_33 ) * V_31 +
V_235 - 1 ;
V_89 = F_126 ( V_233 , V_236 ) ;
if ( ! V_89 )
return NULL ;
V_2 = F_127 ( V_89 , V_235 ) ;
V_2 -> V_237 = V_89 ;
* V_15 = F_128 ( sizeof( struct V_232 ) ) ;
if ( ! V_15 ) {
F_129 ( V_2 -> V_237 ) ;
return NULL ;
}
V_192 = F_130 ( * V_15 ) ;
V_192 -> V_15 = * V_15 ;
V_192 -> V_2 = V_2 ;
V_192 -> type = V_16 ;
V_2 -> V_15 [ V_16 ] = * V_15 ;
F_131 ( & V_2 -> V_213 , F_111 ) ;
F_132 ( & V_2 -> V_238 ) ;
F_133 ( & V_2 -> V_215 , 0 ) ;
F_134 ( & V_2 -> V_24 ) ;
F_133 ( & V_2 -> V_25 , 0 ) ;
return V_2 ;
}
static void T_2 F_135 ( struct V_1 * V_2 )
{
T_1 V_19 , V_9 ;
int V_4 ;
unsigned int V_45 ;
struct {
int V_121 ;
int V_139 ;
} V_239 [ 2 ] = {
[ V_16 ] = {
. V_121 = V_13 ,
. V_139 = V_240
} ,
[ V_73 ] = {
. V_121 = V_241 ,
. V_139 = V_242
}
} ;
for ( V_45 = 0 ; V_45 < F_136 ( V_239 ) ; V_45 ++ ) {
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_243 ,
V_239 [ V_45 ] . V_121 ,
0 , 0 , & V_19 , & V_9 ) ;
if ( V_4 || ! V_19 ) {
if ( V_4 != V_244 )
F_89 ( F_6 ( V_2 ) ,
L_44 ,
V_239 [ V_45 ] . V_121 , V_4 ) ;
V_2 -> V_120 [ V_45 ] . V_121 = 0 ;
V_2 -> V_120 [ V_45 ] . V_139 = 0 ;
continue;
}
V_2 -> V_120 [ V_45 ] . V_121 = ( T_6 ) V_19 ;
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_243 ,
V_239 [ V_45 ] . V_139 ,
0 , 0 , & V_19 , & V_9 ) ;
if ( V_4 || ! V_19 ) {
if ( V_4 != V_244 )
F_5 ( F_6 ( V_2 ) ,
L_45 ,
V_239 [ V_45 ] . V_139 , V_4 ) ;
V_2 -> V_120 [ V_45 ] . V_121 = 0 ;
V_2 -> V_120 [ V_45 ] . V_139 = 0 ;
continue;
}
V_2 -> V_120 [ V_45 ] . V_139 = ( T_6 ) V_19 ;
F_89 ( F_6 ( V_2 ) , L_46 ,
V_45 , V_2 -> V_120 [ V_45 ] . V_121 , V_2 -> V_120 [ V_45 ] . V_139 ) ;
}
if ( V_2 -> V_120 [ V_16 ] . V_121 ) {
F_46 ( ! V_2 -> V_120 [ V_73 ] . V_121 ) ;
V_2 -> V_117 = 1 ;
} else
V_2 -> V_117 = 0 ;
if ( F_106 ( 1 , 6 , 0 ) < 0 ) {
V_2 -> V_120 [ V_73 ] . V_121 = 0 ;
V_2 -> V_120 [ V_73 ] . V_139 = 0 ;
}
F_5 ( F_6 ( V_2 ) , L_47 ,
V_2 -> V_117 ? L_48 : L_49 ) ;
}
static int T_2 F_137 ( struct V_245 * V_77 )
{
struct V_1 * V_2 ;
struct V_10 * V_15 ;
int V_123 ;
F_16 ( L_3 , V_5 ) ;
V_123 = F_138 ( V_77 ) ;
if ( V_123 ) {
F_89 ( & V_77 -> V_246 , L_50 ,
V_5 ) ;
goto V_247;
}
V_123 = F_139 ( V_77 -> V_248 ) ;
if ( V_123 ) {
F_89 ( & V_77 -> V_246 , L_51 ,
V_5 , V_123 ) ;
F_46 ( L_52 ) ;
goto V_249;
}
V_2 = F_123 ( & V_15 ) ;
if ( ! V_2 ) {
F_5 ( & V_77 -> V_246 , L_53 ,
V_5 ) ;
V_123 = - V_52 ;
goto V_250;
}
F_140 ( V_77 , V_2 ) ;
V_2 -> V_77 = V_77 ;
F_135 ( V_2 ) ;
V_2 -> V_23 = V_187 ;
V_123 = F_141 ( F_3 ( V_2 ) ,
F_4 ( V_2 ) ,
F_142 ( F_143 ( & V_2 -> V_154 ) ) ,
0 ) ;
if ( V_123 ) {
F_89 ( & V_77 -> V_246 ,
L_54 ,
V_5 , F_144 ( V_123 ) ) ;
V_123 = - V_205 ;
goto V_251;
}
V_123 = F_145 ( V_77 , V_252 ,
& V_2 -> V_152 ) ;
if ( V_123 ) {
F_5 ( F_6 ( V_2 ) ,
L_55 ,
V_5 , V_123 ) ;
V_123 = - V_201 ;
goto V_253;
}
V_123 = F_146 ( V_2 -> V_152 , F_94 ,
V_254 , V_15 -> V_231 , V_2 ) ;
if ( V_123 ) {
F_5 ( F_6 ( V_2 ) , L_56 ,
V_5 , V_123 ) ;
goto V_255;
}
V_2 -> V_6 = V_7 | V_156 |
V_157 ;
if ( F_35 ( V_2 , & V_2 -> V_75 ,
V_2 -> V_30 , V_31 ) )
goto V_256;
if ( F_35 ( V_2 , & V_2 -> V_29 ,
V_2 -> V_30 + V_31 ,
V_234 ) )
goto V_257;
V_2 -> V_258 = V_2 -> V_75 . V_50 ;
V_2 -> V_68 = V_2 -> V_29 . V_50 ;
F_89 ( F_6 ( V_2 ) , L_57 ,
V_2 -> V_68 , V_2 -> V_258 , sizeof( struct V_33 ) ,
V_234 ) ;
if ( F_44 ( V_2 ) )
goto V_259;
F_147 ( & V_2 -> V_124 ) ;
V_2 -> V_122 = 0 ;
V_15 -> V_152 = V_2 -> V_152 ;
F_148 ( V_15 , & V_2 -> V_77 -> V_246 ) ;
F_118 ( V_15 , & V_2 -> V_26 ) ;
V_123 = F_120 ( V_15 , V_2 ) ;
if ( V_123 ) {
F_89 ( & V_77 -> V_246 , L_58 ,
V_5 , V_123 ) ;
goto V_260;
}
#ifdef F_96
if ( F_149 ( V_2 ) ) {
F_89 ( & V_77 -> V_246 , L_59 , V_5 ) ;
goto V_260;
}
#endif
F_16 ( L_5 , V_5 ) ;
return 0 ;
V_260:
V_259:
F_33 ( V_2 , V_2 -> V_29 . V_50 ) ;
V_257:
F_33 ( V_2 , V_2 -> V_75 . V_50 ) ;
V_256:
F_150 ( V_2 -> V_152 , V_2 ) ;
V_15 -> V_152 = V_261 ;
V_255:
F_151 ( V_77 , V_2 -> V_152 ) ;
V_253:
F_141 ( F_3 ( V_2 ) ,
F_3 ( V_2 ) ,
0 , 0 ) ;
V_251:
F_140 ( V_77 , NULL ) ;
F_129 ( F_54 ( V_15 ) -> V_237 ) ;
F_152 ( V_15 ) ;
V_250:
F_153 ( V_77 -> V_248 ) ;
V_249:
F_154 ( V_77 ) ;
V_247:
return V_123 ;
}
static int F_155 ( struct V_245 * V_77 )
{
struct V_1 * V_2 = F_156 ( V_77 ) ;
struct V_10 * V_262 ;
F_16 ( L_3 , V_5 ) ;
F_13 ( V_2 , V_187 ) ;
#ifdef F_96
F_157 ( V_2 ) ;
#endif
F_1 ( V_2 , 0 ) ;
F_25 ( V_2 ) ;
F_27 ( V_2 ) ;
F_51 ( V_2 , 1 ) ;
F_42 ( V_2 ) ;
F_33 ( V_2 , V_2 -> V_258 ) ;
F_33 ( V_2 , V_2 -> V_68 ) ;
V_262 = V_2 -> V_15 [ V_16 ] ;
F_150 ( V_2 -> V_152 , V_2 ) ;
V_262 -> V_152 = V_261 ;
F_151 ( V_2 -> V_77 , V_2 -> V_152 ) ;
F_158 ( V_2 -> V_238 ,
F_159 ( & V_2 -> V_215 ) == 0 ) ;
F_141 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
0 , 0 ) ;
F_160 ( V_262 ) ;
F_129 ( F_54 ( V_262 ) -> V_237 ) ;
F_152 ( V_262 ) ;
F_140 ( V_77 , NULL ) ;
F_153 ( V_77 -> V_248 ) ;
F_154 ( V_77 ) ;
F_16 ( L_5 , V_5 ) ;
return 0 ;
}
static int T_9 F_161 ( void )
{
return F_162 ( V_263 )
? F_163 ( & V_264 )
: - V_265 ;
}
static void T_10 F_164 ( void )
{
F_165 ( & V_264 ) ;
}
