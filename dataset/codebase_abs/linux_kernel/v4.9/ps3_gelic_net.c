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
static void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_6 |= V_7 ;
F_1 ( V_2 , V_2 -> V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 )
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
static enum V_18
F_13 ( struct V_19 * V_20 )
{
return F_14 ( V_20 -> V_21 ) & V_22 ;
}
static int F_15 ( struct V_1 * V_2 , int V_23 )
{
int V_4 ;
T_1 V_24 , V_9 ;
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_25 ,
V_26 , V_23 , 0 , & V_24 , & V_9 ) ;
if ( V_4 ) {
F_16 ( L_2 , V_5 ,
V_4 ) ;
return - V_27 ;
}
V_2 -> V_28 = V_23 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_18 ( F_3 ( V_2 ) , F_4 ( V_2 ) ) ;
if ( V_4 )
F_19 ( F_6 ( V_2 ) ,
L_3 , V_4 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_4 ;
#ifdef F_21
if ( F_13 ( V_2 -> V_29 . V_30 ) !=
V_31 ) {
F_22 ( V_32 L_4 , V_5 ,
F_14 ( V_2 -> V_29 . V_30 -> V_21 ) ) ;
F_22 ( V_32 L_5 , V_5 ,
F_14 ( V_2 -> V_29 . V_30 -> V_33 ) ) ;
F_22 ( V_32 L_6 , V_5 ,
V_2 -> V_29 . V_30 ) ;
}
#endif
V_4 = F_23 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_2 -> V_29 . V_30 -> V_34 , 0 ) ;
if ( V_4 )
F_5 ( F_6 ( V_2 ) ,
L_7 , V_4 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_25 ( F_3 ( V_2 ) , F_4 ( V_2 ) ) ;
if ( V_4 )
F_19 ( F_6 ( V_2 ) ,
L_8 , V_4 ) ;
}
static void F_26 ( struct V_19 * V_20 ,
enum V_18 V_4 )
{
V_20 -> V_21 = F_27 ( V_4 |
( F_14 ( V_20 -> V_21 ) &
~ V_22 ) ) ;
F_28 () ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_19 * V_37 )
{
struct V_19 * V_20 ;
for ( V_20 = V_37 ; V_37 != V_20 -> V_38 ; V_20 ++ ) {
F_26 ( V_20 , V_31 ) ;
V_20 -> V_33 = F_27 ( V_20 -> V_38 -> V_34 ) ;
}
V_36 -> V_30 = V_37 ;
V_36 -> V_39 = ( V_20 - 1 ) ;
( V_20 - 1 ) -> V_33 = 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_31 ( L_9 , V_5 ) ;
F_32 ( & V_2 -> V_40 ) ;
if ( F_33 ( & V_2 -> V_41 ) == 1 ) {
F_31 ( L_10 , V_5 ) ;
F_1 ( V_2 , V_2 -> V_6 ) ;
F_20 ( V_2 ) ;
F_34 ( & V_2 -> V_42 ) ;
}
F_35 ( & V_2 -> V_40 ) ;
F_31 ( L_11 , V_5 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_31 ( L_9 , V_5 ) ;
F_32 ( & V_2 -> V_40 ) ;
if ( F_37 ( & V_2 -> V_41 ) == 0 ) {
F_31 ( L_10 , V_5 ) ;
F_38 ( & V_2 -> V_42 ) ;
V_3 = V_2 -> V_6 & ( V_43 |
V_44 ) ;
F_1 ( V_2 , V_3 ) ;
F_24 ( V_2 ) ;
F_29 ( V_2 , & V_2 -> V_29 ,
V_2 -> V_20 + V_45 ) ;
F_17 ( V_2 ) ;
}
F_35 ( & V_2 -> V_40 ) ;
F_31 ( L_11 , V_5 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_19 * V_46 )
{
struct V_19 * V_20 ;
for ( V_20 = V_46 ; V_20 && V_20 -> V_34 ; V_20 = V_20 -> V_38 ) {
F_40 ( F_6 ( V_2 ) , V_20 -> V_34 ,
V_47 , V_48 ) ;
V_20 -> V_34 = 0 ;
}
}
static int F_41 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_19 * V_37 , int V_49 )
{
int V_50 ;
struct V_19 * V_20 ;
V_20 = V_37 ;
memset ( V_20 , 0 , sizeof( * V_20 ) * V_49 ) ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ , V_20 ++ ) {
F_26 ( V_20 , V_51 ) ;
V_20 -> V_34 =
F_42 ( F_6 ( V_2 ) , V_20 ,
V_47 ,
V_48 ) ;
if ( ! V_20 -> V_34 )
goto V_52;
V_20 -> V_38 = V_20 + 1 ;
V_20 -> V_53 = V_20 - 1 ;
}
( V_20 - 1 ) -> V_38 = V_37 ;
V_37 -> V_53 = ( V_20 - 1 ) ;
V_20 = V_37 ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ , V_20 ++ ) {
V_20 -> V_33 = F_27 ( V_20 -> V_38 -> V_34 ) ;
}
V_36 -> V_30 = V_37 ;
V_36 -> V_39 = V_37 ;
( V_20 - 1 ) -> V_33 = 0 ;
return 0 ;
V_52:
for ( V_50 -- , V_20 -- ; 0 <= V_50 ; V_50 -- , V_20 -- )
if ( V_20 -> V_34 )
F_40 ( F_6 ( V_2 ) , V_20 -> V_34 ,
V_47 ,
V_48 ) ;
return - V_54 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
int V_55 ;
unsigned int V_56 ;
if ( F_13 ( V_20 ) != V_51 )
F_5 ( F_6 ( V_2 ) , L_12 , V_5 ) ;
V_56 = F_44 ( V_57 , V_58 ) ;
V_20 -> V_59 = F_45 ( V_56 + V_58 - 1 ) ;
if ( ! V_20 -> V_59 ) {
V_20 -> V_60 = 0 ;
F_5 ( F_6 ( V_2 ) ,
L_13 , V_5 ) ;
return - V_54 ;
}
V_20 -> V_61 = F_27 ( V_56 ) ;
V_20 -> V_21 = 0 ;
V_20 -> V_62 = 0 ;
V_20 -> V_63 = 0 ;
V_20 -> V_64 = 0 ;
V_55 = ( ( unsigned long ) V_20 -> V_59 -> V_65 ) &
( V_58 - 1 ) ;
if ( V_55 )
F_46 ( V_20 -> V_59 , V_58 - V_55 ) ;
V_20 -> V_60 = F_27 ( F_42 ( F_6 ( V_2 ) ,
V_20 -> V_59 -> V_65 ,
V_57 ,
V_66 ) ) ;
if ( ! V_20 -> V_60 ) {
F_47 ( V_20 -> V_59 ) ;
V_20 -> V_59 = NULL ;
F_5 ( F_6 ( V_2 ) ,
L_14 , V_5 ) ;
F_26 ( V_20 , V_51 ) ;
return - V_54 ;
} else {
F_26 ( V_20 , V_31 ) ;
return 0 ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_29 . V_30 ;
do {
if ( V_20 -> V_59 ) {
F_40 ( F_6 ( V_2 ) ,
F_14 ( V_20 -> V_60 ) ,
V_20 -> V_59 -> V_67 ,
V_66 ) ;
V_20 -> V_60 = 0 ;
F_47 ( V_20 -> V_59 ) ;
V_20 -> V_59 = NULL ;
F_26 ( V_20 ,
V_51 ) ;
}
V_20 = V_20 -> V_38 ;
} while ( V_20 != V_2 -> V_29 . V_30 );
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_29 . V_30 ;
int V_68 ;
do {
if ( ! V_20 -> V_59 ) {
V_68 = F_43 ( V_2 , V_20 ) ;
if ( V_68 )
goto rewind;
}
V_20 = V_20 -> V_38 ;
} while ( V_20 != V_2 -> V_29 . V_30 );
return 0 ;
rewind:
F_48 ( V_2 ) ;
return V_68 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
int V_68 ;
V_36 = & V_2 -> V_29 ;
V_68 = F_49 ( V_2 ) ;
V_36 -> V_39 = V_2 -> V_69 -> V_53 ;
return V_68 ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_70 * V_59 = V_20 -> V_59 ;
F_52 ( ! ( F_14 ( V_20 -> V_71 ) & V_72 ) ) ;
F_40 ( F_6 ( V_2 ) , F_14 ( V_20 -> V_60 ) , V_59 -> V_67 ,
V_73 ) ;
F_47 ( V_59 ) ;
V_20 -> V_60 = 0 ;
V_20 -> V_61 = 0 ;
V_20 -> V_33 = 0 ;
V_20 -> V_62 = 0 ;
V_20 -> V_63 = 0 ;
V_20 -> V_71 = 0 ;
V_20 -> V_64 = 0 ;
V_20 -> V_59 = NULL ;
F_26 ( V_20 , V_51 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_54 ( V_2 -> V_15 [ V_16 ] ) ;
if ( V_2 -> V_15 [ V_74 ] )
F_54 ( V_2 -> V_15 [ V_74 ] ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_56 ( V_2 -> V_15 [ V_16 ] ) ;
if ( V_2 -> V_15 [ V_74 ] )
F_56 ( V_2 -> V_15 [ V_74 ] ) ;
}
static void F_57 ( struct V_1 * V_2 , int V_75 )
{
struct V_35 * V_76 ;
enum V_18 V_4 ;
struct V_10 * V_15 ;
int V_77 = 0 ;
for ( V_76 = & V_2 -> V_76 ;
V_76 -> V_30 != V_76 -> V_39 && V_76 -> V_39 ;
V_76 -> V_39 = V_76 -> V_39 -> V_38 ) {
V_4 = F_13 ( V_76 -> V_39 ) ;
V_15 = V_76 -> V_39 -> V_59 -> V_78 ;
switch ( V_4 ) {
case V_79 :
case V_80 :
case V_81 :
if ( F_58 () )
F_5 ( F_6 ( V_2 ) ,
L_15 \
L_16 ,
V_5 , V_4 ) ;
V_15 -> V_82 . V_83 ++ ;
break;
case V_84 :
if ( V_76 -> V_39 -> V_59 ) {
V_15 -> V_82 . V_85 ++ ;
V_15 -> V_82 . V_86 +=
V_76 -> V_39 -> V_59 -> V_67 ;
}
break;
case V_31 :
default:
if ( ! V_75 )
goto V_87;
}
F_51 ( V_2 , V_76 -> V_39 ) ;
V_77 ++ ;
}
V_87:
if ( ! V_75 && V_77 )
F_55 ( V_2 ) ;
}
void F_59 ( struct V_10 * V_15 )
{
struct V_1 * V_2 = F_60 ( V_15 ) ;
struct V_88 * V_89 ;
unsigned int V_50 ;
T_2 * V_90 ;
T_1 V_91 ;
int V_4 ;
V_4 = F_61 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
0 , 1 ) ;
if ( V_4 )
F_19 ( F_6 ( V_2 ) ,
L_17 ,
V_4 ) ;
V_4 = F_62 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_92 , 0 ) ;
if ( V_4 )
F_19 ( F_6 ( V_2 ) ,
L_18 ,
V_4 ) ;
if ( ( V_15 -> V_93 & V_94 ) ||
( F_63 ( V_15 ) > V_95 ) ) {
V_4 = F_62 ( F_3 ( V_2 ) ,
F_4 ( V_2 ) ,
0 , 1 ) ;
if ( V_4 )
F_19 ( F_6 ( V_2 ) ,
L_18 ,
V_4 ) ;
return;
}
F_64 (ha, netdev) {
V_91 = 0 ;
V_90 = V_89 -> V_91 ;
for ( V_50 = 0 ; V_50 < V_96 ; V_50 ++ ) {
V_91 <<= 8 ;
V_91 |= * V_90 ++ ;
}
V_4 = F_62 ( F_3 ( V_2 ) ,
F_4 ( V_2 ) ,
V_91 , 0 ) ;
if ( V_4 )
F_19 ( F_6 ( V_2 ) ,
L_18 ,
V_4 ) ;
}
}
int F_65 ( struct V_10 * V_15 )
{
struct V_1 * V_2 ;
F_31 ( L_19 , V_5 ) ;
F_54 ( V_15 ) ;
F_12 ( V_15 ) ;
V_2 = F_60 ( V_15 ) ;
F_36 ( V_2 ) ;
F_31 ( L_11 , V_5 ) ;
return 0 ;
}
static struct V_19 *
F_66 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_76 . V_30 )
return NULL ;
if ( V_2 -> V_76 . V_39 != V_2 -> V_76 . V_30 -> V_38 &&
F_13 ( V_2 -> V_76 . V_30 ) ==
V_51 )
return V_2 -> V_76 . V_30 ;
else
return NULL ;
}
static void F_67 ( struct V_19 * V_20 ,
struct V_70 * V_59 )
{
if ( V_59 -> V_97 != V_98 )
V_20 -> V_21 =
F_27 ( V_99 |
V_100 ) ;
else {
if ( V_59 -> V_101 == F_68 ( V_102 ) ) {
if ( F_69 ( V_59 ) -> V_101 == V_103 )
V_20 -> V_21 =
F_27 ( V_104 |
V_100 ) ;
else if ( F_69 ( V_59 ) -> V_101 == V_105 )
V_20 -> V_21 =
F_27 ( V_106 |
V_100 ) ;
else
V_20 -> V_21 =
F_27 ( V_99 |
V_100 ) ;
}
}
}
static struct V_70 * F_70 ( struct V_70 * V_59 ,
unsigned short V_107 )
{
struct V_108 * V_109 ;
static unsigned int V_110 ;
if ( F_71 ( V_59 ) < V_111 ) {
struct V_70 * V_112 = V_59 ;
F_31 ( L_20 , V_5 , F_71 ( V_59 ) , V_110 ) ;
V_59 = F_72 ( V_112 , V_111 ) ;
if ( ! V_59 )
return NULL ;
F_47 ( V_112 ) ;
}
V_109 = (struct V_108 * ) F_73 ( V_59 , V_111 ) ;
memmove ( V_59 -> V_65 , V_59 -> V_65 + V_111 , 2 * V_96 ) ;
V_109 -> V_113 = F_74 ( V_114 ) ;
V_109 -> V_115 = F_68 ( V_107 ) ;
return V_59 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_70 * V_59 )
{
T_3 V_116 ;
if ( V_2 -> V_117 ) {
struct V_70 * V_118 ;
enum V_119 type ;
type = F_76 ( V_59 -> V_78 ) -> type ;
V_118 = F_70 ( V_59 ,
V_2 -> V_120 [ type ] . V_121 ) ;
if ( ! V_118 )
return - V_54 ;
V_59 = V_118 ;
}
V_116 = F_42 ( F_6 ( V_2 ) , V_59 -> V_65 , V_59 -> V_67 , V_73 ) ;
if ( ! V_116 ) {
F_19 ( F_6 ( V_2 ) ,
L_21 ,
V_59 -> V_65 , V_59 -> V_67 ) ;
return - V_54 ;
}
V_20 -> V_60 = F_27 ( V_116 ) ;
V_20 -> V_61 = F_27 ( V_59 -> V_67 ) ;
V_20 -> V_59 = V_59 ;
V_20 -> V_71 = 0 ;
V_20 -> V_33 = 0 ;
F_67 ( V_20 , V_59 ) ;
V_2 -> V_76 . V_30 = V_20 -> V_38 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
int V_4 = 0 ;
if ( V_2 -> V_122 )
return 0 ;
if ( F_13 ( V_20 ) == V_31 ) {
V_2 -> V_122 = 1 ;
V_4 = F_78 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_20 -> V_34 , 0 ) ;
if ( V_4 ) {
V_2 -> V_122 = 0 ;
F_5 ( F_6 ( V_2 ) , L_22 \
L_23 , V_4 ) ;
}
}
return V_4 ;
}
int F_79 ( struct V_70 * V_59 , struct V_10 * V_15 )
{
struct V_1 * V_2 = F_60 ( V_15 ) ;
struct V_19 * V_20 ;
int V_123 ;
unsigned long V_93 ;
F_80 ( & V_2 -> V_124 , V_93 ) ;
F_57 ( V_2 , 0 ) ;
V_20 = F_66 ( V_2 ) ;
if ( ! V_20 ) {
F_53 ( V_2 ) ;
F_81 ( & V_2 -> V_124 , V_93 ) ;
return V_125 ;
}
V_123 = F_75 ( V_2 , V_20 , V_59 ) ;
if ( V_123 ) {
V_15 -> V_82 . V_83 ++ ;
F_47 ( V_59 ) ;
F_81 ( & V_2 -> V_124 , V_93 ) ;
return V_126 ;
}
V_20 -> V_53 -> V_33 = F_27 ( V_20 -> V_34 ) ;
F_28 () ;
if ( F_77 ( V_2 , V_20 ) ) {
V_15 -> V_82 . V_83 ++ ;
V_20 -> V_71 = F_27 ( V_72 ) ;
F_51 ( V_2 , V_20 ) ;
V_2 -> V_76 . V_30 = V_20 ;
V_20 -> V_53 -> V_33 = 0 ;
F_5 ( F_6 ( V_2 ) , L_24 , V_5 ) ;
}
F_81 ( & V_2 -> V_124 , V_93 ) ;
return V_126 ;
}
static void F_82 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
struct V_10 * V_15 )
{
struct V_70 * V_59 = V_20 -> V_59 ;
T_4 V_71 , V_64 ;
V_71 = F_14 ( V_20 -> V_71 ) ;
V_64 = F_14 ( V_20 -> V_64 ) ;
F_40 ( F_6 ( V_2 ) , F_14 ( V_20 -> V_60 ) ,
V_57 ,
V_66 ) ;
F_83 ( V_59 , F_14 ( V_20 -> V_63 ) ?
F_14 ( V_20 -> V_63 ) :
F_14 ( V_20 -> V_62 ) ) ;
if ( ! V_20 -> V_63 )
F_5 ( F_6 ( V_2 ) , L_25 ,
F_14 ( V_20 -> V_62 ) ,
F_14 ( V_20 -> V_61 ) ,
F_14 ( V_20 -> V_21 ) ) ;
V_20 -> V_59 = NULL ;
F_84 ( V_59 , 2 ) ;
V_59 -> V_101 = F_85 ( V_59 , V_15 ) ;
if ( V_15 -> V_127 & V_128 ) {
if ( ( V_71 & V_129 ) &&
( ! ( V_64 & V_130 ) ) )
V_59 -> V_97 = V_131 ;
else
F_86 ( V_59 ) ;
} else
F_86 ( V_59 ) ;
V_15 -> V_82 . V_132 ++ ;
V_15 -> V_82 . V_133 += V_59 -> V_67 ;
F_87 ( V_59 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
enum V_18 V_4 ;
struct V_35 * V_36 = & V_2 -> V_29 ;
struct V_19 * V_20 = V_36 -> V_30 ;
struct V_10 * V_15 = NULL ;
int V_134 ;
V_4 = F_13 ( V_20 ) ;
if ( V_4 == V_31 )
return 0 ;
if ( V_4 == V_51 ) {
F_89 ( F_6 ( V_2 ) , L_26 , V_20 ) ;
return 0 ;
}
if ( V_2 -> V_117 ) {
unsigned int V_50 ;
T_5 V_135 ;
V_135 = * ( T_5 * ) ( V_20 -> V_59 -> V_65 ) & V_136 ;
for ( V_50 = 0 ; V_50 < V_137 ; V_50 ++ ) {
if ( V_2 -> V_120 [ V_50 ] . V_138 == V_135 ) {
V_15 = V_2 -> V_15 [ V_50 ] ;
break;
}
}
if ( V_137 <= V_50 ) {
F_16 ( L_27 , V_5 , V_135 ) ;
goto V_139;
}
} else
V_15 = V_2 -> V_15 [ V_16 ] ;
if ( ( V_4 == V_79 ) ||
( V_4 == V_80 ) ||
( V_4 == V_81 ) ) {
F_5 ( F_6 ( V_2 ) , L_28 ,
V_4 ) ;
V_15 -> V_82 . V_140 ++ ;
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
F_82 ( V_20 , V_2 , V_15 ) ;
V_139:
V_134 =
F_14 ( V_20 -> V_21 ) &
V_143 ;
V_20 -> V_33 = 0 ;
F_26 ( V_20 , V_51 ) ;
F_43 ( V_2 , V_20 ) ;
V_36 -> V_39 = V_20 ;
V_36 -> V_30 = V_20 -> V_38 ;
V_20 -> V_53 -> V_33 = F_27 ( V_20 -> V_34 ) ;
if ( V_134 )
F_20 ( V_2 ) ;
return 1 ;
}
static int F_90 ( struct V_144 * V_42 , int V_145 )
{
struct V_1 * V_2 = F_91 ( V_42 , struct V_1 , V_42 ) ;
int V_146 = 0 ;
while ( V_146 < V_145 ) {
if ( ! F_88 ( V_2 ) )
break;
V_146 ++ ;
}
if ( V_146 < V_145 ) {
F_92 ( V_42 ) ;
F_7 ( V_2 ) ;
}
return V_146 ;
}
int F_93 ( struct V_10 * V_15 , int V_147 )
{
if ( ( V_147 < V_148 ) ||
( V_147 > V_57 ) ) {
return - V_149 ;
}
V_15 -> V_150 = V_147 ;
return 0 ;
}
static T_6 F_94 ( int V_151 , void * V_152 )
{
unsigned long V_93 ;
struct V_1 * V_2 = V_152 ;
T_1 V_4 ;
V_4 = V_2 -> V_153 ;
if ( ! V_4 )
return V_154 ;
V_4 &= V_2 -> V_6 ;
if ( V_4 & V_7 ) {
F_8 ( V_2 ) ;
F_95 ( & V_2 -> V_42 ) ;
}
if ( V_4 & V_155 ) {
F_80 ( & V_2 -> V_124 , V_93 ) ;
V_2 -> V_122 = 0 ;
F_57 ( V_2 , 0 ) ;
F_77 ( V_2 , V_2 -> V_76 . V_39 ) ;
F_81 ( & V_2 -> V_124 , V_93 ) ;
}
if ( V_4 & V_156 )
F_9 ( V_2 , 1 ) ;
#ifdef F_96
if ( V_4 & ( V_43 |
V_44 ) )
F_97 ( V_2 -> V_15 [ V_74 ] , V_4 ) ;
#endif
return V_157 ;
}
void F_98 ( struct V_10 * V_15 )
{
struct V_1 * V_2 = F_60 ( V_15 ) ;
F_1 ( V_2 , 0 ) ;
F_94 ( V_15 -> V_151 , V_15 ) ;
F_1 ( V_2 , V_2 -> V_6 ) ;
}
int F_99 ( struct V_10 * V_15 )
{
struct V_1 * V_2 = F_60 ( V_15 ) ;
F_89 ( F_6 ( V_2 ) , L_31 , V_5 , V_15 ) ;
F_30 ( V_2 ) ;
F_100 ( V_15 ) ;
F_9 ( V_2 , 1 ) ;
F_89 ( F_6 ( V_2 ) , L_32 , V_5 ) ;
return 0 ;
}
void F_101 ( struct V_10 * V_15 ,
struct V_158 * V_159 )
{
F_102 ( V_159 -> V_160 , V_161 , sizeof( V_159 -> V_160 ) ) ;
F_102 ( V_159 -> V_162 , V_163 , sizeof( V_159 -> V_162 ) ) ;
}
static int F_103 ( struct V_10 * V_15 ,
struct V_164 * V_165 )
{
struct V_1 * V_2 = F_60 ( V_15 ) ;
F_9 ( V_2 , 0 ) ;
if ( V_2 -> V_14 & V_166 )
V_165 -> V_167 = V_168 ;
else
V_165 -> V_167 = V_169 ;
switch ( V_2 -> V_14 & V_170 ) {
case V_171 :
F_104 ( V_165 , V_172 ) ;
break;
case V_173 :
F_104 ( V_165 , V_174 ) ;
break;
case V_175 :
F_104 ( V_165 , V_176 ) ;
break;
default:
F_16 ( L_33 , V_5 ) ;
F_104 ( V_165 , V_172 ) ;
break;
}
V_165 -> V_177 = V_178 | V_179 |
V_180 | V_181 |
V_182 | V_183 |
V_184 ;
V_165 -> V_185 = V_165 -> V_177 ;
if ( V_2 -> V_28 & V_186 ) {
V_165 -> V_187 = V_188 ;
} else {
V_165 -> V_187 = V_189 ;
V_165 -> V_185 &= ~ V_190 ;
}
V_165 -> V_191 = V_192 ;
return 0 ;
}
static int F_105 ( struct V_10 * V_15 ,
struct V_164 * V_165 )
{
struct V_1 * V_2 = F_60 ( V_15 ) ;
T_1 V_23 ;
int V_68 ;
if ( V_165 -> V_187 == V_188 ) {
V_23 = V_186 ;
} else {
switch ( V_165 -> V_193 ) {
case V_172 :
V_23 = V_171 ;
break;
case V_174 :
V_23 = V_173 ;
break;
case V_176 :
V_23 = V_175 ;
break;
default:
return - V_149 ;
}
if ( V_165 -> V_167 == V_168 )
V_23 |= V_166 ;
else if ( V_165 -> V_193 == V_176 ) {
F_16 ( L_34 ) ;
return - V_149 ;
}
}
V_68 = F_15 ( V_2 , V_23 ) ;
if ( V_68 )
return V_68 ;
return 0 ;
}
static void F_106 ( struct V_10 * V_15 ,
struct V_194 * V_195 )
{
if ( 0 <= F_107 ( 2 , 2 , 0 ) )
V_195 -> V_177 = V_196 ;
else
V_195 -> V_177 = 0 ;
V_195 -> V_197 = F_108 () ? V_195 -> V_177 : 0 ;
memset ( & V_195 -> V_198 , 0 , sizeof( V_195 -> V_198 ) ) ;
}
static int F_109 ( struct V_10 * V_15 ,
struct V_194 * V_195 )
{
int V_4 ;
struct V_1 * V_2 ;
T_1 V_24 , V_9 ;
if ( F_107 ( 2 , 2 , 0 ) < 0 ||
! F_110 ( V_199 ) )
return - V_200 ;
if ( V_195 -> V_197 & ~ V_196 )
return - V_149 ;
V_2 = F_60 ( V_15 ) ;
if ( V_195 -> V_197 & V_196 ) {
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_201 ,
V_202 ,
0 , V_203 ,
& V_24 , & V_9 ) ;
if ( V_4 ) {
F_16 ( L_35 , V_5 ,
V_4 ) ;
V_4 = - V_204 ;
goto V_205;
}
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_201 ,
V_206 ,
0 , V_207 ,
& V_24 , & V_9 ) ;
if ( ! V_4 )
F_111 ( 1 ) ;
else {
F_16 ( L_36 ,
V_5 , V_4 ) ;
V_4 = - V_204 ;
}
} else {
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_201 ,
V_202 ,
0 , V_208 ,
& V_24 , & V_9 ) ;
if ( V_4 ) {
F_16 ( L_37 , V_5 ,
V_4 ) ;
V_4 = - V_204 ;
goto V_205;
}
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_201 ,
V_209 ,
0 , V_207 ,
& V_24 , & V_9 ) ;
if ( ! V_4 )
F_111 ( 0 ) ;
else {
F_16 ( L_38 ,
V_5 , V_4 ) ;
V_4 = - V_204 ;
}
}
V_205:
return V_4 ;
}
static void F_112 ( struct V_210 * V_211 )
{
struct V_1 * V_2 =
F_91 ( V_211 , struct V_1 , V_212 ) ;
struct V_10 * V_15 = V_2 -> V_15 [ V_16 ] ;
F_5 ( F_6 ( V_2 ) , L_39 , V_5 ) ;
if ( ! ( V_15 -> V_93 & V_213 ) )
goto V_87;
F_113 ( V_15 ) ;
F_65 ( V_15 ) ;
F_99 ( V_15 ) ;
F_114 ( V_15 ) ;
V_87:
F_115 ( & V_2 -> V_214 ) ;
}
void F_116 ( struct V_10 * V_15 )
{
struct V_1 * V_2 ;
V_2 = F_60 ( V_15 ) ;
F_117 ( & V_2 -> V_214 ) ;
if ( V_15 -> V_93 & V_213 )
F_118 ( & V_2 -> V_212 ) ;
else
F_115 ( & V_2 -> V_214 ) ;
}
static void F_119 ( struct V_10 * V_15 ,
struct V_144 * V_42 )
{
V_15 -> V_215 = V_216 ;
F_120 ( V_15 , V_42 , F_90 , V_217 ) ;
V_15 -> V_218 = & V_219 ;
V_15 -> V_220 = & V_221 ;
}
int F_121 ( struct V_10 * V_15 , struct V_1 * V_2 )
{
int V_4 ;
T_1 V_24 , V_9 ;
V_15 -> V_222 = V_223 | V_128 ;
V_15 -> V_127 = V_223 ;
if ( V_224 )
V_15 -> V_127 |= V_128 ;
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_225 ,
0 , 0 , 0 , & V_24 , & V_9 ) ;
V_24 <<= 16 ;
if ( V_4 || ! F_122 ( ( V_226 * ) & V_24 ) ) {
F_5 ( F_6 ( V_2 ) ,
L_40 ,
V_5 , V_4 ) ;
return - V_149 ;
}
memcpy ( V_15 -> V_227 , & V_24 , V_96 ) ;
if ( V_2 -> V_117 ) {
V_15 -> V_228 += V_111 ;
V_15 -> V_127 |= V_229 ;
}
V_4 = F_123 ( V_15 ) ;
if ( V_4 ) {
F_19 ( F_6 ( V_2 ) , L_41 ,
V_5 , V_15 -> V_230 , V_4 ) ;
return V_4 ;
}
F_5 ( F_6 ( V_2 ) , L_42 ,
V_15 -> V_230 , V_15 -> V_227 ) ;
return 0 ;
}
static struct V_1 * F_124 ( struct V_10 * * V_15 )
{
struct V_1 * V_2 ;
struct V_231 * V_191 ;
void * V_90 ;
T_7 V_232 ;
F_125 ( F_126 ( struct V_1 , V_153 ) % 8 ) ;
F_125 ( F_126 ( struct V_1 , V_20 ) % 32 ) ;
V_232 =
sizeof( struct V_1 ) +
sizeof( struct V_19 ) * V_233 +
sizeof( struct V_19 ) * V_45 +
V_234 - 1 ;
V_90 = F_127 ( V_232 , V_235 ) ;
if ( ! V_90 )
return NULL ;
V_2 = F_128 ( V_90 , V_234 ) ;
V_2 -> V_236 = V_90 ;
* V_15 = F_129 ( sizeof( struct V_231 ) ) ;
if ( ! * V_15 ) {
F_130 ( V_2 -> V_236 ) ;
return NULL ;
}
V_191 = F_131 ( * V_15 ) ;
V_191 -> V_15 = * V_15 ;
V_191 -> V_2 = V_2 ;
V_191 -> type = V_16 ;
V_2 -> V_15 [ V_16 ] = * V_15 ;
F_132 ( & V_2 -> V_212 , F_112 ) ;
F_133 ( & V_2 -> V_237 ) ;
F_134 ( & V_2 -> V_214 , 0 ) ;
F_135 ( & V_2 -> V_40 ) ;
F_134 ( & V_2 -> V_41 , 0 ) ;
return V_2 ;
}
static void F_136 ( struct V_1 * V_2 )
{
T_1 V_24 , V_9 ;
int V_4 ;
unsigned int V_50 ;
struct {
int V_121 ;
int V_138 ;
} V_238 [ 2 ] = {
[ V_16 ] = {
. V_121 = V_13 ,
. V_138 = V_239
} ,
[ V_74 ] = {
. V_121 = V_240 ,
. V_138 = V_241
}
} ;
for ( V_50 = 0 ; V_50 < F_137 ( V_238 ) ; V_50 ++ ) {
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_242 ,
V_238 [ V_50 ] . V_121 ,
0 , 0 , & V_24 , & V_9 ) ;
if ( V_4 || ! V_24 ) {
if ( V_4 != V_243 )
F_89 ( F_6 ( V_2 ) ,
L_43 ,
V_238 [ V_50 ] . V_121 , V_4 ) ;
V_2 -> V_120 [ V_50 ] . V_121 = 0 ;
V_2 -> V_120 [ V_50 ] . V_138 = 0 ;
continue;
}
V_2 -> V_120 [ V_50 ] . V_121 = ( T_5 ) V_24 ;
V_4 = F_10 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
V_242 ,
V_238 [ V_50 ] . V_138 ,
0 , 0 , & V_24 , & V_9 ) ;
if ( V_4 || ! V_24 ) {
if ( V_4 != V_243 )
F_5 ( F_6 ( V_2 ) ,
L_44 ,
V_238 [ V_50 ] . V_138 , V_4 ) ;
V_2 -> V_120 [ V_50 ] . V_121 = 0 ;
V_2 -> V_120 [ V_50 ] . V_138 = 0 ;
continue;
}
V_2 -> V_120 [ V_50 ] . V_138 = ( T_5 ) V_24 ;
F_89 ( F_6 ( V_2 ) , L_45 ,
V_50 , V_2 -> V_120 [ V_50 ] . V_121 , V_2 -> V_120 [ V_50 ] . V_138 ) ;
}
if ( V_2 -> V_120 [ V_16 ] . V_121 ) {
F_52 ( ! V_2 -> V_120 [ V_74 ] . V_121 ) ;
V_2 -> V_117 = 1 ;
} else
V_2 -> V_117 = 0 ;
if ( F_107 ( 1 , 6 , 0 ) < 0 ) {
V_2 -> V_120 [ V_74 ] . V_121 = 0 ;
V_2 -> V_120 [ V_74 ] . V_138 = 0 ;
}
F_5 ( F_6 ( V_2 ) , L_46 ,
V_2 -> V_117 ? L_47 : L_48 ) ;
}
static int F_138 ( struct V_244 * V_78 )
{
struct V_1 * V_2 ;
struct V_10 * V_15 ;
int V_123 ;
F_31 ( L_9 , V_5 ) ;
F_139 () ;
V_123 = F_140 ( V_78 ) ;
if ( V_123 ) {
F_89 ( & V_78 -> V_245 , L_49 ,
V_5 ) ;
goto V_246;
}
V_123 = F_141 ( V_78 -> V_247 ) ;
if ( V_123 ) {
F_89 ( & V_78 -> V_245 , L_50 ,
V_5 , V_123 ) ;
F_52 ( L_51 ) ;
goto V_248;
}
V_2 = F_124 ( & V_15 ) ;
if ( ! V_2 ) {
F_5 ( & V_78 -> V_245 , L_52 ,
V_5 ) ;
V_123 = - V_54 ;
goto V_249;
}
F_142 ( V_78 , V_2 ) ;
V_2 -> V_78 = V_78 ;
F_136 ( V_2 ) ;
V_2 -> V_28 = V_186 ;
V_123 = F_143 ( F_3 ( V_2 ) ,
F_4 ( V_2 ) ,
F_144 ( F_145 ( & V_2 -> V_153 ) ) ,
0 ) ;
if ( V_123 ) {
F_89 ( & V_78 -> V_245 ,
L_53 ,
V_5 , F_146 ( V_123 ) ) ;
V_123 = - V_204 ;
goto V_250;
}
V_123 = F_147 ( V_78 , V_251 ,
& V_2 -> V_151 ) ;
if ( V_123 ) {
F_5 ( F_6 ( V_2 ) ,
L_54 ,
V_5 , V_123 ) ;
V_123 = - V_200 ;
goto V_252;
}
V_123 = F_148 ( V_2 -> V_151 , F_94 ,
0 , V_15 -> V_230 , V_2 ) ;
if ( V_123 ) {
F_5 ( F_6 ( V_2 ) , L_55 ,
V_5 , V_123 ) ;
goto V_253;
}
V_2 -> V_6 = V_7 | V_155 |
V_156 ;
V_123 = F_41 ( V_2 , & V_2 -> V_76 ,
V_2 -> V_20 , V_45 ) ;
if ( V_123 )
goto V_254;
V_123 = F_41 ( V_2 , & V_2 -> V_29 ,
V_2 -> V_20 + V_45 ,
V_233 ) ;
if ( V_123 )
goto V_255;
V_2 -> V_256 = V_2 -> V_76 . V_30 ;
V_2 -> V_69 = V_2 -> V_29 . V_30 ;
F_89 ( F_6 ( V_2 ) , L_56 ,
V_2 -> V_69 , V_2 -> V_256 , sizeof( struct V_19 ) ,
V_233 ) ;
V_123 = F_50 ( V_2 ) ;
if ( V_123 )
goto V_257;
F_149 ( & V_2 -> V_124 ) ;
V_2 -> V_122 = 0 ;
V_15 -> V_151 = V_2 -> V_151 ;
F_150 ( V_15 , & V_2 -> V_78 -> V_245 ) ;
F_119 ( V_15 , & V_2 -> V_42 ) ;
V_123 = F_121 ( V_15 , V_2 ) ;
if ( V_123 ) {
F_89 ( & V_78 -> V_245 , L_57 ,
V_5 , V_123 ) ;
goto V_258;
}
#ifdef F_96
V_123 = F_151 ( V_2 ) ;
if ( V_123 ) {
F_89 ( & V_78 -> V_245 , L_58 , V_5 ) ;
goto V_258;
}
#endif
F_31 ( L_11 , V_5 ) ;
return 0 ;
V_258:
V_257:
F_39 ( V_2 , V_2 -> V_29 . V_30 ) ;
V_255:
F_39 ( V_2 , V_2 -> V_76 . V_30 ) ;
V_254:
F_152 ( V_2 -> V_151 , V_2 ) ;
V_15 -> V_151 = 0 ;
V_253:
F_153 ( V_78 , V_2 -> V_151 ) ;
V_252:
F_143 ( F_3 ( V_2 ) ,
F_3 ( V_2 ) ,
0 , 0 ) ;
V_250:
F_142 ( V_78 , NULL ) ;
F_130 ( F_60 ( V_15 ) -> V_236 ) ;
F_154 ( V_15 ) ;
V_249:
F_155 ( V_78 -> V_247 ) ;
V_248:
F_156 ( V_78 ) ;
V_246:
return V_123 ;
}
static int F_157 ( struct V_244 * V_78 )
{
struct V_1 * V_2 = F_158 ( V_78 ) ;
struct V_10 * V_259 ;
F_31 ( L_9 , V_5 ) ;
F_15 ( V_2 , V_186 ) ;
#ifdef F_96
F_159 ( V_2 ) ;
#endif
F_1 ( V_2 , 0 ) ;
F_24 ( V_2 ) ;
F_17 ( V_2 ) ;
F_57 ( V_2 , 1 ) ;
F_48 ( V_2 ) ;
F_39 ( V_2 , V_2 -> V_256 ) ;
F_39 ( V_2 , V_2 -> V_69 ) ;
V_259 = V_2 -> V_15 [ V_16 ] ;
F_152 ( V_2 -> V_151 , V_2 ) ;
V_259 -> V_151 = 0 ;
F_153 ( V_2 -> V_78 , V_2 -> V_151 ) ;
F_160 ( V_2 -> V_237 ,
F_161 ( & V_2 -> V_214 ) == 0 ) ;
F_143 ( F_3 ( V_2 ) , F_4 ( V_2 ) ,
0 , 0 ) ;
F_162 ( V_259 ) ;
F_130 ( F_60 ( V_259 ) -> V_236 ) ;
F_154 ( V_259 ) ;
F_142 ( V_78 , NULL ) ;
F_155 ( V_78 -> V_247 ) ;
F_156 ( V_78 ) ;
F_31 ( L_11 , V_5 ) ;
return 0 ;
}
static int T_8 F_163 ( void )
{
return F_164 ( V_260 )
? F_165 ( & V_261 )
: - V_262 ;
}
static void T_9 F_166 ( void )
{
F_167 ( & V_261 ) ;
}
