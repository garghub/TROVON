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
V_4 = F_63 ( F_3 ( V_2 ) , F_4 ( V_2 ) ) ;
if ( V_4 )
F_56 ( F_6 ( V_2 ) ,
L_17 , V_4 ) ;
}
static inline void F_27 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_64 ( F_3 ( V_2 ) , F_4 ( V_2 ) ) ;
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
if ( V_4 ) {
V_2 -> V_122 = 0 ;
F_5 ( F_6 ( V_2 ) , L_22 \
L_23 , V_4 ) ;
}
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
V_30 -> V_70 = F_31 ( V_71 ) ;
F_45 ( V_2 , V_30 ) ;
V_2 -> V_75 . V_50 = V_30 ;
V_30 -> V_48 -> V_49 = 0 ;
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
if ( V_4 == V_53 )
return 0 ;
if ( V_4 == V_46 ) {
F_89 ( F_6 ( V_2 ) , L_26 , V_30 ) ;
return 0 ;
}
if ( V_2 -> V_117 ) {
unsigned int V_45 ;
T_6 V_135 ;
V_135 = * ( T_6 * ) ( V_30 -> V_58 -> V_64 ) & V_136 ;
for ( V_45 = 0 ; V_45 < V_137 ; V_45 ++ ) {
if ( V_2 -> V_120 [ V_45 ] . V_138 == V_135 ) {
V_15 = V_2 -> V_15 [ V_45 ] ;
break;
}
}
if ( V_137 <= V_45 ) {
F_14 ( L_27 , V_5 , V_135 ) ;
goto V_139;
}
} else
V_15 = V_2 -> V_15 [ V_16 ] ;
if ( ( V_4 == V_78 ) ||
( V_4 == V_79 ) ||
( V_4 == V_80 ) ) {
F_5 ( F_6 ( V_2 ) , L_28 ,
V_4 ) ;
V_15 -> V_81 . V_140 ++ ;
goto V_139;
}
if ( V_4 == V_141 ) {
F_5 ( F_6 ( V_2 ) , L_29 ) ;
goto V_139;
}
if ( V_4 != V_142 ) {
F_89 ( F_6 ( V_2 ) , L_30 ,
V_4 ) ;
goto V_139;
}
F_82 ( V_30 , V_2 , V_15 ) ;
V_139:
V_134 =
F_29 ( V_30 -> V_34 ) &
V_143 ;
V_30 -> V_49 = 0 ;
F_30 ( V_30 , V_46 ) ;
F_37 ( V_2 , V_30 ) ;
V_42 -> V_51 = V_30 ;
V_42 -> V_50 = V_30 -> V_38 ;
V_30 -> V_48 -> V_49 = F_31 ( V_30 -> V_37 ) ;
if ( V_134 )
F_19 ( V_2 ) ;
return 1 ;
}
static int F_90 ( struct V_144 * V_26 , int V_145 )
{
struct V_1 * V_2 = F_91 ( V_26 , struct V_1 , V_26 ) ;
int V_146 = 0 ;
while ( V_146 < V_145 ) {
if ( ! F_88 ( V_2 ) )
break;
V_146 ++ ;
}
if ( V_146 < V_145 ) {
F_92 ( V_26 ) ;
F_7 ( V_2 ) ;
}
return V_146 ;
}
int F_93 ( struct V_10 * V_15 , int V_147 )
{
if ( ( V_147 < V_148 ) ||
( V_147 > V_56 ) ) {
return - V_149 ;
}
V_15 -> V_150 = V_147 ;
return 0 ;
}
static T_7 F_94 ( int V_151 , void * V_152 )
{
unsigned long V_92 ;
struct V_1 * V_2 = V_152 ;
T_1 V_4 ;
V_4 = V_2 -> V_153 ;
if ( ! V_4 )
return V_154 ;
V_4 &= V_2 -> V_6 ;
if ( V_4 & V_7 ) {
F_8 ( V_2 ) ;
F_95 ( & V_2 -> V_26 ) ;
}
if ( V_4 & V_155 ) {
F_80 ( & V_2 -> V_124 , V_92 ) ;
V_2 -> V_122 = 0 ;
F_51 ( V_2 , 0 ) ;
F_77 ( V_2 , V_2 -> V_75 . V_51 ) ;
F_81 ( & V_2 -> V_124 , V_92 ) ;
}
if ( V_4 & V_156 )
F_9 ( V_2 , 1 ) ;
#ifdef F_96
if ( V_4 & ( V_27 |
V_28 ) )
F_97 ( V_2 -> V_15 [ V_73 ] , V_4 ) ;
#endif
return V_157 ;
}
void F_98 ( struct V_10 * V_15 )
{
struct V_1 * V_2 = F_54 ( V_15 ) ;
F_1 ( V_2 , 0 ) ;
F_94 ( V_15 -> V_151 , V_15 ) ;
F_1 ( V_2 , V_2 -> V_6 ) ;
}
int F_99 ( struct V_10 * V_15 )
{
struct V_1 * V_2 = F_54 ( V_15 ) ;
F_89 ( F_6 ( V_2 ) , L_31 , V_5 , V_15 ) ;
F_15 ( V_2 ) ;
F_100 ( V_15 ) ;
F_9 ( V_2 , 1 ) ;
F_89 ( F_6 ( V_2 ) , L_32 , V_5 ) ;
return 0 ;
}
void F_101 ( struct V_10 * V_15 ,
struct V_158 * V_159 )
{
strncpy ( V_159 -> V_160 , V_161 , sizeof( V_159 -> V_160 ) - 1 ) ;
strncpy ( V_159 -> V_162 , V_163 , sizeof( V_159 -> V_162 ) - 1 ) ;
}
static int F_102 ( struct V_10 * V_15 ,
struct V_164 * V_165 )
{
struct V_1 * V_2 = F_54 ( V_15 ) ;
F_9 ( V_2 , 0 ) ;
if ( V_2 -> V_14 & V_166 )
V_165 -> V_167 = V_168 ;
else
V_165 -> V_167 = V_169 ;
switch ( V_2 -> V_14 & V_170 ) {
case V_171 :
F_103 ( V_165 , V_172 ) ;
break;
case V_173 :
F_103 ( V_165 , V_174 ) ;
break;
case V_175 :
F_103 ( V_165 , V_176 ) ;
break;
default:
F_14 ( L_33 , V_5 ) ;
F_103 ( V_165 , V_172 ) ;
break;
}
V_165 -> V_177 = V_178 | V_179 |
V_180 | V_181 |
V_182 | V_183 |
V_184 ;
V_165 -> V_185 = V_165 -> V_177 ;
if ( V_2 -> V_23 & V_186 ) {
V_165 -> V_187 = V_188 ;
} else {
V_165 -> V_187 = V_189 ;
V_165 -> V_185 &= ~ V_190 ;
}
V_165 -> V_191 = V_192 ;
return 0 ;
}
static int F_104 ( struct V_10 * V_15 ,
struct V_164 * V_165 )
{
struct V_1 * V_2 = F_54 ( V_15 ) ;
T_1 V_18 ;
int V_67 ;
if ( V_165 -> V_187 == V_188 ) {
V_18 = V_186 ;
} else {
switch ( V_165 -> V_193 ) {
case V_172 :
V_18 = V_171 ;
break;
case V_174 :
V_18 = V_173 ;
break;
case V_176 :
V_18 = V_175 ;
break;
default:
return - V_149 ;
}
if ( V_165 -> V_167 == V_168 )
V_18 |= V_166 ;
else if ( V_165 -> V_193 == V_176 ) {
F_14 ( L_34 ) ;
return - V_149 ;
}
}
V_67 = F_13 ( V_2 , V_18 ) ;
if ( V_67 )
return V_67 ;
return 0 ;
}
static void F_105 ( struct V_10 * V_15 ,
struct V_194 * V_195 )
{
if ( 0 <= F_106 ( 2 , 2 , 0 ) )
V_195 -> V_177 = V_196 ;
else
V_195 -> V_177 = 0 ;
V_195 -> V_197 = F_107 () ? V_195 -> V_177 : 0 ;
memset ( & V_195 -> V_198 , 0 , sizeof( V_195 -> V_198 ) ) ;
}
static int F_108 ( struct V_10 * V_15 ,
struct V_194 * V_195 )
{
int V_4 ;
struct V_1 * V_2 ;
T_1 V_19 , V_9 ;
if ( F_106 ( 2 , 2 , 0 ) < 0 ||
! F_109 ( V_199 ) )
return - V_200 ;
if ( V_195 -> V_197 & ~ V_196 )
return - V_149 ;
V_2 = F_54 ( V_15 ) ;
if ( V_195 -> V_197 & V_196 ) {
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_201 ,
V_202 ,
0 , V_203 ,
& V_19 , & V_9 ) ;
if ( V_4 ) {
F_14 ( L_35 , V_5 ,
V_4 ) ;
V_4 = - V_204 ;
goto V_205;
}
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_201 ,
V_206 ,
0 , V_207 ,
& V_19 , & V_9 ) ;
if ( ! V_4 )
F_110 ( 1 ) ;
else {
F_14 ( L_36 ,
V_5 , V_4 ) ;
V_4 = - V_204 ;
}
} else {
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_201 ,
V_202 ,
0 , V_208 ,
& V_19 , & V_9 ) ;
if ( V_4 ) {
F_14 ( L_37 , V_5 ,
V_4 ) ;
V_4 = - V_204 ;
goto V_205;
}
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_201 ,
V_209 ,
0 , V_207 ,
& V_19 , & V_9 ) ;
if ( ! V_4 )
F_110 ( 0 ) ;
else {
F_14 ( L_38 ,
V_5 , V_4 ) ;
V_4 = - V_204 ;
}
}
V_205:
return V_4 ;
}
static void F_111 ( struct V_210 * V_211 )
{
struct V_1 * V_2 =
F_91 ( V_211 , struct V_1 , V_212 ) ;
struct V_10 * V_15 = V_2 -> V_15 [ V_16 ] ;
F_5 ( F_6 ( V_2 ) , L_39 , V_5 ) ;
if ( ! ( V_15 -> V_92 & V_213 ) )
goto V_86;
F_112 ( V_15 ) ;
F_65 ( V_15 ) ;
F_99 ( V_15 ) ;
F_113 ( V_15 ) ;
V_86:
F_114 ( & V_2 -> V_214 ) ;
}
void F_115 ( struct V_10 * V_15 )
{
struct V_1 * V_2 ;
V_2 = F_54 ( V_15 ) ;
F_116 ( & V_2 -> V_214 ) ;
if ( V_15 -> V_92 & V_213 )
F_117 ( & V_2 -> V_212 ) ;
else
F_114 ( & V_2 -> V_214 ) ;
}
static void T_2 F_118 ( struct V_10 * V_15 ,
struct V_144 * V_26 )
{
V_15 -> V_215 = V_216 ;
F_119 ( V_15 , V_26 ,
F_90 , V_217 ) ;
V_15 -> V_218 = & V_219 ;
V_15 -> V_220 = & V_221 ;
}
int T_2 F_120 ( struct V_10 * V_15 ,
struct V_1 * V_2 )
{
int V_4 ;
T_1 V_19 , V_9 ;
V_15 -> V_222 = V_223 | V_128 ;
V_15 -> V_127 = V_223 ;
if ( V_224 )
V_15 -> V_127 |= V_128 ;
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_225 ,
0 , 0 , 0 , & V_19 , & V_9 ) ;
V_19 <<= 16 ;
if ( V_4 || ! F_121 ( ( V_226 * ) & V_19 ) ) {
F_5 ( F_6 ( V_2 ) ,
L_40 ,
V_5 , V_4 ) ;
return - V_149 ;
}
memcpy ( V_15 -> V_227 , & V_19 , V_95 ) ;
if ( V_2 -> V_117 ) {
V_15 -> V_228 += V_111 ;
V_15 -> V_127 |= V_229 ;
}
V_4 = F_122 ( V_15 ) ;
if ( V_4 ) {
F_56 ( F_6 ( V_2 ) , L_41 ,
V_5 , V_15 -> V_230 , V_4 ) ;
return V_4 ;
}
F_5 ( F_6 ( V_2 ) , L_42 ,
V_15 -> V_230 , V_15 -> V_227 ) ;
return 0 ;
}
static struct V_1 * T_2 F_123 ( struct V_10 * * V_15 )
{
struct V_1 * V_2 ;
struct V_231 * V_191 ;
void * V_89 ;
T_8 V_232 ;
F_124 ( F_125 ( struct V_1 , V_153 ) % 8 ) ;
F_124 ( F_125 ( struct V_1 , V_30 ) % 32 ) ;
V_232 =
sizeof( struct V_1 ) +
sizeof( struct V_33 ) * V_233 +
sizeof( struct V_33 ) * V_31 +
V_234 - 1 ;
V_89 = F_126 ( V_232 , V_235 ) ;
if ( ! V_89 )
return NULL ;
V_2 = F_127 ( V_89 , V_234 ) ;
V_2 -> V_236 = V_89 ;
* V_15 = F_128 ( sizeof( struct V_231 ) ) ;
if ( ! V_15 ) {
F_129 ( V_2 -> V_236 ) ;
return NULL ;
}
V_191 = F_130 ( * V_15 ) ;
V_191 -> V_15 = * V_15 ;
V_191 -> V_2 = V_2 ;
V_191 -> type = V_16 ;
V_2 -> V_15 [ V_16 ] = * V_15 ;
F_131 ( & V_2 -> V_212 , F_111 ) ;
F_132 ( & V_2 -> V_237 ) ;
F_133 ( & V_2 -> V_214 , 0 ) ;
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
int V_138 ;
} V_238 [ 2 ] = {
[ V_16 ] = {
. V_121 = V_13 ,
. V_138 = V_239
} ,
[ V_73 ] = {
. V_121 = V_240 ,
. V_138 = V_241
}
} ;
for ( V_45 = 0 ; V_45 < F_136 ( V_238 ) ; V_45 ++ ) {
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_242 ,
V_238 [ V_45 ] . V_121 ,
0 , 0 , & V_19 , & V_9 ) ;
if ( V_4 || ! V_19 ) {
if ( V_4 != V_243 )
F_89 ( F_6 ( V_2 ) ,
L_43 ,
V_238 [ V_45 ] . V_121 , V_4 ) ;
V_2 -> V_120 [ V_45 ] . V_121 = 0 ;
V_2 -> V_120 [ V_45 ] . V_138 = 0 ;
continue;
}
V_2 -> V_120 [ V_45 ] . V_121 = ( T_6 ) V_19 ;
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_242 ,
V_238 [ V_45 ] . V_138 ,
0 , 0 , & V_19 , & V_9 ) ;
if ( V_4 || ! V_19 ) {
if ( V_4 != V_243 )
F_5 ( F_6 ( V_2 ) ,
L_44 ,
V_238 [ V_45 ] . V_138 , V_4 ) ;
V_2 -> V_120 [ V_45 ] . V_121 = 0 ;
V_2 -> V_120 [ V_45 ] . V_138 = 0 ;
continue;
}
V_2 -> V_120 [ V_45 ] . V_138 = ( T_6 ) V_19 ;
F_89 ( F_6 ( V_2 ) , L_45 ,
V_45 , V_2 -> V_120 [ V_45 ] . V_121 , V_2 -> V_120 [ V_45 ] . V_138 ) ;
}
if ( V_2 -> V_120 [ V_16 ] . V_121 ) {
F_46 ( ! V_2 -> V_120 [ V_73 ] . V_121 ) ;
V_2 -> V_117 = 1 ;
} else
V_2 -> V_117 = 0 ;
if ( F_106 ( 1 , 6 , 0 ) < 0 ) {
V_2 -> V_120 [ V_73 ] . V_121 = 0 ;
V_2 -> V_120 [ V_73 ] . V_138 = 0 ;
}
F_5 ( F_6 ( V_2 ) , L_46 ,
V_2 -> V_117 ? L_47 : L_48 ) ;
}
static int T_2 F_137 ( struct V_244 * V_77 )
{
struct V_1 * V_2 ;
struct V_10 * V_15 ;
int V_123 ;
F_16 ( L_3 , V_5 ) ;
F_138 () ;
V_123 = F_139 ( V_77 ) ;
if ( V_123 ) {
F_89 ( & V_77 -> V_245 , L_49 ,
V_5 ) ;
goto V_246;
}
V_123 = F_140 ( V_77 -> V_247 ) ;
if ( V_123 ) {
F_89 ( & V_77 -> V_245 , L_50 ,
V_5 , V_123 ) ;
F_46 ( L_51 ) ;
goto V_248;
}
V_2 = F_123 ( & V_15 ) ;
if ( ! V_2 ) {
F_5 ( & V_77 -> V_245 , L_52 ,
V_5 ) ;
V_123 = - V_52 ;
goto V_249;
}
F_141 ( V_77 , V_2 ) ;
V_2 -> V_77 = V_77 ;
F_135 ( V_2 ) ;
V_2 -> V_23 = V_186 ;
V_123 = F_142 ( F_3 ( V_2 ) ,
F_4 ( V_2 ) ,
F_143 ( F_144 ( & V_2 -> V_153 ) ) ,
0 ) ;
if ( V_123 ) {
F_89 ( & V_77 -> V_245 ,
L_53 ,
V_5 , F_145 ( V_123 ) ) ;
V_123 = - V_204 ;
goto V_250;
}
V_123 = F_146 ( V_77 , V_251 ,
& V_2 -> V_151 ) ;
if ( V_123 ) {
F_5 ( F_6 ( V_2 ) ,
L_54 ,
V_5 , V_123 ) ;
V_123 = - V_200 ;
goto V_252;
}
V_123 = F_147 ( V_2 -> V_151 , F_94 ,
V_253 , V_15 -> V_230 , V_2 ) ;
if ( V_123 ) {
F_5 ( F_6 ( V_2 ) , L_55 ,
V_5 , V_123 ) ;
goto V_254;
}
V_2 -> V_6 = V_7 | V_155 |
V_156 ;
if ( F_35 ( V_2 , & V_2 -> V_75 ,
V_2 -> V_30 , V_31 ) )
goto V_255;
if ( F_35 ( V_2 , & V_2 -> V_29 ,
V_2 -> V_30 + V_31 ,
V_233 ) )
goto V_256;
V_2 -> V_257 = V_2 -> V_75 . V_50 ;
V_2 -> V_68 = V_2 -> V_29 . V_50 ;
F_89 ( F_6 ( V_2 ) , L_56 ,
V_2 -> V_68 , V_2 -> V_257 , sizeof( struct V_33 ) ,
V_233 ) ;
if ( F_44 ( V_2 ) )
goto V_258;
F_148 ( & V_2 -> V_124 ) ;
V_2 -> V_122 = 0 ;
V_15 -> V_151 = V_2 -> V_151 ;
F_149 ( V_15 , & V_2 -> V_77 -> V_245 ) ;
F_118 ( V_15 , & V_2 -> V_26 ) ;
V_123 = F_120 ( V_15 , V_2 ) ;
if ( V_123 ) {
F_89 ( & V_77 -> V_245 , L_57 ,
V_5 , V_123 ) ;
goto V_259;
}
#ifdef F_96
if ( F_150 ( V_2 ) ) {
F_89 ( & V_77 -> V_245 , L_58 , V_5 ) ;
goto V_259;
}
#endif
F_16 ( L_5 , V_5 ) ;
return 0 ;
V_259:
V_258:
F_33 ( V_2 , V_2 -> V_29 . V_50 ) ;
V_256:
F_33 ( V_2 , V_2 -> V_75 . V_50 ) ;
V_255:
F_151 ( V_2 -> V_151 , V_2 ) ;
V_15 -> V_151 = V_260 ;
V_254:
F_152 ( V_77 , V_2 -> V_151 ) ;
V_252:
F_142 ( F_3 ( V_2 ) ,
F_3 ( V_2 ) ,
0 , 0 ) ;
V_250:
F_141 ( V_77 , NULL ) ;
F_129 ( F_54 ( V_15 ) -> V_236 ) ;
F_153 ( V_15 ) ;
V_249:
F_154 ( V_77 -> V_247 ) ;
V_248:
F_155 ( V_77 ) ;
V_246:
return V_123 ;
}
static int F_156 ( struct V_244 * V_77 )
{
struct V_1 * V_2 = F_157 ( V_77 ) ;
struct V_10 * V_261 ;
F_16 ( L_3 , V_5 ) ;
F_13 ( V_2 , V_186 ) ;
#ifdef F_96
F_158 ( V_2 ) ;
#endif
F_1 ( V_2 , 0 ) ;
F_25 ( V_2 ) ;
F_27 ( V_2 ) ;
F_51 ( V_2 , 1 ) ;
F_42 ( V_2 ) ;
F_33 ( V_2 , V_2 -> V_257 ) ;
F_33 ( V_2 , V_2 -> V_68 ) ;
V_261 = V_2 -> V_15 [ V_16 ] ;
F_151 ( V_2 -> V_151 , V_2 ) ;
V_261 -> V_151 = V_260 ;
F_152 ( V_2 -> V_77 , V_2 -> V_151 ) ;
F_159 ( V_2 -> V_237 ,
F_160 ( & V_2 -> V_214 ) == 0 ) ;
F_142 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
0 , 0 ) ;
F_161 ( V_261 ) ;
F_129 ( F_54 ( V_261 ) -> V_236 ) ;
F_153 ( V_261 ) ;
F_141 ( V_77 , NULL ) ;
F_154 ( V_77 -> V_247 ) ;
F_155 ( V_77 ) ;
F_16 ( L_5 , V_5 ) ;
return 0 ;
}
static int T_9 F_162 ( void )
{
return F_163 ( V_262 )
? F_164 ( & V_263 )
: - V_264 ;
}
static void T_10 F_165 ( void )
{
F_166 ( & V_263 ) ;
}
