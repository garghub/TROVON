static inline struct V_1 * V_1 ( const struct V_2 * V_3 )
{
F_1 ( V_3 , sizeof( struct V_1 ) ) ;
return (struct V_1 * ) F_2 ( V_3 ) -> V_4 ;
}
static T_1 F_3 ( const struct V_2 * V_3 , T_1 V_5 )
{
return V_1 ( V_3 ) -> V_6 [ V_5 ] ;
}
static T_1 F_4 ( T_1 V_7 , T_1 V_8 )
{
T_1 V_9 = V_7 + V_8 ;
return F_5 ( T_1 , V_9 , V_10 ) ;
}
static T_1 F_6 ( T_1 V_7 , T_1 V_8 )
{
return V_7 > V_8 ? V_7 - V_8 : 0 ;
}
static void F_7 ( T_1 V_11 , T_1 V_5 , struct V_12 * V_13 )
{
int V_14 ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_5 ] . V_17 [ 0 ] [ 0 ] ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
T_1 V_19 = V_11 & V_20 ;
V_11 >>= V_21 ;
if ( V_16 [ V_19 ] . V_22 < 0xFFFF )
V_16 [ V_19 ] . V_22 ++ ;
V_16 += V_23 ;
}
}
static void F_8 ( const struct V_2 * V_3 , struct V_12 * V_13 )
{
T_1 V_11 ;
V_11 = F_3 ( V_3 , 0 ) ;
if ( V_11 )
F_7 ( V_11 , 0 , V_13 ) ;
V_11 = F_3 ( V_3 , 1 ) ;
if ( V_11 )
F_7 ( V_11 , 1 , V_13 ) ;
}
static void F_9 ( T_1 V_11 , T_1 V_5 ,
struct V_12 * V_13 )
{
int V_14 ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_5 ] . V_17 [ 0 ] [ 0 ] ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
T_1 V_19 = V_11 & V_20 ;
V_11 >>= V_21 ;
if ( V_16 [ V_19 ] . V_22 > 0 )
V_16 [ V_19 ] . V_22 -- ;
V_16 += V_23 ;
}
}
static void F_10 ( const struct V_2 * V_3 , struct V_12 * V_13 )
{
T_1 V_11 ;
V_11 = F_3 ( V_3 , 0 ) ;
if ( V_11 )
F_9 ( V_11 , 0 , V_13 ) ;
V_11 = F_3 ( V_3 , 1 ) ;
if ( V_11 )
F_9 ( V_11 , 1 , V_13 ) ;
}
static void F_11 ( struct V_15 * V_16 , struct V_12 * V_13 )
{
V_16 -> V_24 = F_6 ( V_16 -> V_24 , V_13 -> V_25 ) ;
}
static void F_12 ( struct V_15 * V_16 , struct V_12 * V_13 )
{
V_16 -> V_24 = F_4 ( V_16 -> V_24 , V_13 -> V_26 ) ;
}
static void F_13 ( struct V_12 * V_13 )
{
memset ( & V_13 -> V_17 , 0 , sizeof( V_13 -> V_17 ) ) ;
}
static T_1 F_14 ( T_1 * V_27 , T_1 * V_28 , const struct V_12 * V_13 )
{
int V_14 ;
T_1 V_22 = 0 , V_29 = 0 , V_30 = 0 ;
const struct V_15 * V_16 = & V_13 -> V_17 [ V_13 -> V_5 ] . V_17 [ 0 ] [ 0 ] ;
for ( V_14 = 0 ; V_14 < V_18 * V_23 ; V_14 ++ ) {
if ( V_22 < V_16 -> V_22 )
V_22 = V_16 -> V_22 ;
V_30 += V_16 -> V_24 ;
if ( V_29 < V_16 -> V_24 )
V_29 = V_16 -> V_24 ;
V_16 ++ ;
}
* V_27 = V_29 ;
* V_28 = V_30 / ( V_18 * V_23 ) ;
return V_22 ;
}
static void F_15 ( T_1 V_5 , struct V_12 * V_13 )
{
V_13 -> V_17 [ V_5 ] . V_31 = F_16 () ;
}
static void F_17 ( struct V_12 * V_13 )
{
F_15 ( V_13 -> V_5 , V_13 ) ;
V_13 -> V_5 ^= 1 ;
V_13 -> V_32 = false ;
}
static bool F_18 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
if ( V_13 -> V_33 == 0 || V_13 -> V_34 == 0 )
return true ;
if ( V_13 -> V_35 < 1 ) {
unsigned long V_36 = F_19 ( 10UL * V_37 , V_38 - V_13 -> V_39 ) ;
V_13 -> V_35 = ( V_36 * V_13 -> V_33 ) / V_37 ;
if ( V_13 -> V_35 > V_13 -> V_34 )
V_13 -> V_35 = V_13 -> V_34 ;
V_13 -> V_39 = V_38 ;
if ( V_13 -> V_35 < 1 )
return true ;
}
V_13 -> V_35 -- ;
return false ;
}
static bool F_20 ( struct V_2 * V_3 , struct V_40 * V_41 ,
int * V_42 , T_1 * V_43 )
{
struct V_44 V_9 ;
int V_45 ;
V_45 = F_21 ( V_3 , V_41 , & V_9 ) ;
if ( V_45 >= 0 ) {
#ifdef F_22
switch ( V_45 ) {
case V_46 :
case V_47 :
* V_42 = V_48 | V_49 ;
case V_50 :
return false ;
}
#endif
* V_43 = F_23 ( V_9 . V_51 ) ;
return true ;
}
return false ;
}
static int F_24 ( struct V_2 * V_3 , struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_52 * V_54 = V_13 -> V_55 ;
struct V_40 * V_41 ;
int V_14 ;
T_1 V_56 = ~ 0 ;
T_1 V_57 = ~ 0 ;
T_1 V_58 , V_5 , V_43 , V_11 ;
int V_59 = V_48 | V_60 ;
struct V_61 V_62 ;
if ( F_26 ( V_53 -> V_13 . V_22 >= V_13 -> V_63 ) ) {
F_27 ( V_53 ) ;
V_13 -> V_64 . V_65 ++ ;
goto V_66;
}
if ( V_13 -> V_67 > 0 ) {
unsigned long V_63 = V_13 -> V_68 + V_13 -> V_67 ;
if ( F_26 ( F_28 ( V_38 , V_63 ) ) ) {
F_17 ( V_13 ) ;
V_13 -> V_68 = V_38 ;
} else if ( F_26 ( ! V_13 -> V_32 && V_13 -> V_69 > 0 &&
F_28 ( V_38 , V_63 - V_13 -> V_69 ) ) ) {
V_13 -> V_32 = true ;
}
}
V_41 = F_29 ( V_13 -> V_70 ) ;
if ( V_41 ) {
if ( ! F_20 ( V_3 , V_41 , & V_59 , & V_43 ) )
goto V_71;
V_62 . V_72 = V_43 ;
V_62 . V_73 = 0 ;
V_62 . V_74 = 0 ;
} else {
F_30 ( V_3 , & V_62 ) ;
}
V_5 = V_13 -> V_5 ;
V_11 = F_31 ( ( V_75 T_1 ) V_62 . V_73 ,
( V_75 T_1 ) V_62 . V_72 ,
( V_75 T_1 ) V_62 . V_74 ,
V_13 -> V_17 [ V_5 ] . V_31 ) ;
if ( ! V_11 )
V_11 = 1 ;
V_1 ( V_3 ) -> V_6 [ V_5 ] = V_11 ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
T_1 V_19 = V_11 & V_20 ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_5 ] . V_17 [ V_14 ] [ V_19 ] ;
V_11 >>= V_21 ;
if ( V_16 -> V_22 == 0 )
F_11 ( V_16 , V_13 ) ;
else if ( V_16 -> V_22 >= V_13 -> V_76 )
F_12 ( V_16 , V_13 ) ;
if ( V_57 > V_16 -> V_22 )
V_57 = V_16 -> V_22 ;
if ( V_56 > V_16 -> V_24 )
V_56 = V_16 -> V_24 ;
}
V_5 ^= 1 ;
V_1 ( V_3 ) -> V_6 [ V_5 ] = 0 ;
if ( F_26 ( V_57 >= V_13 -> V_77 ) ) {
F_27 ( V_53 ) ;
V_13 -> V_64 . V_78 ++ ;
goto V_66;
}
if ( F_26 ( V_56 >= V_10 ) ) {
if ( V_13 -> V_32 ) {
V_11 = F_31 ( ( V_75 T_1 ) V_62 . V_73 ,
( V_75 T_1 ) V_62 . V_72 ,
( V_75 T_1 ) V_62 . V_74 ,
V_13 -> V_17 [ V_5 ] . V_31 ) ;
if ( ! V_11 )
V_11 = 1 ;
V_1 ( V_3 ) -> V_6 [ V_5 ] = V_11 ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
T_1 V_19 = V_11 & V_20 ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_5 ] . V_17 [ V_14 ] [ V_19 ] ;
V_11 >>= V_21 ;
if ( V_16 -> V_22 == 0 )
F_11 ( V_16 , V_13 ) ;
else if ( V_16 -> V_22 >= V_13 -> V_76 )
F_12 ( V_16 , V_13 ) ;
}
}
if ( F_18 ( V_3 , V_13 ) ) {
F_27 ( V_53 ) ;
V_13 -> V_64 . V_79 ++ ;
goto V_66;
}
goto V_80;
}
V_58 = F_16 () & V_10 ;
if ( F_26 ( V_58 < V_56 ) ) {
if ( F_26 ( V_56 > V_10 / 2 ) ) {
if ( V_58 < ( V_56 - V_10 / 2 ) * 2 ) {
V_13 -> V_64 . V_81 ++ ;
goto V_66;
}
}
if ( F_32 ( V_3 ) ) {
V_13 -> V_64 . V_82 ++ ;
} else {
V_13 -> V_64 . V_81 ++ ;
goto V_66;
}
}
V_80:
V_59 = F_33 ( V_3 , V_54 ) ;
if ( F_34 ( V_59 == V_48 ) ) {
V_53 -> V_13 . V_22 ++ ;
F_8 ( V_3 , V_13 ) ;
} else if ( F_35 ( V_59 ) ) {
V_13 -> V_64 . V_83 ++ ;
F_36 ( V_53 ) ;
}
return V_59 ;
V_66:
F_37 ( V_3 , V_53 ) ;
return V_84 ;
V_71:
if ( V_59 & V_60 )
F_36 ( V_53 ) ;
F_38 ( V_3 ) ;
return V_59 ;
}
static struct V_2 * F_39 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_52 * V_54 = V_13 -> V_55 ;
struct V_2 * V_3 ;
V_3 = V_54 -> V_85 ( V_13 -> V_55 ) ;
if ( V_3 ) {
F_40 ( V_53 , V_3 ) ;
V_53 -> V_13 . V_22 -- ;
F_10 ( V_3 , V_13 ) ;
}
return V_3 ;
}
static struct V_2 * F_41 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_52 * V_54 = V_13 -> V_55 ;
return V_54 -> V_86 -> V_87 ( V_54 ) ;
}
static void F_42 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
F_43 ( V_13 -> V_55 ) ;
V_53 -> V_13 . V_22 = 0 ;
V_13 -> V_5 = 0 ;
V_13 -> V_32 = false ;
F_13 ( V_13 ) ;
F_15 ( 0 , V_13 ) ;
}
static void F_44 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
F_45 ( & V_13 -> V_70 ) ;
F_46 ( V_13 -> V_55 ) ;
}
static int F_47 ( struct V_52 * V_53 , struct V_88 * V_89 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_52 * V_54 ;
struct V_88 * V_90 [ V_91 + 1 ] ;
const struct V_92 * V_93 = & V_94 ;
T_1 V_63 ;
int V_95 ;
if ( V_89 ) {
V_95 = F_48 ( V_90 , V_91 , V_89 , V_96 ) ;
if ( V_95 < 0 )
return - V_97 ;
if ( V_90 [ V_98 ] == NULL )
return - V_97 ;
V_93 = F_49 ( V_90 [ V_98 ] ) ;
}
V_63 = V_93 -> V_63 ;
if ( V_63 == 0 )
V_63 = F_50 ( T_1 , F_51 ( V_53 ) -> V_99 , 1 ) ;
V_54 = F_52 ( V_53 , & V_100 , V_63 ) ;
if ( F_53 ( V_54 ) )
return F_54 ( V_54 ) ;
F_55 ( V_53 ) ;
F_56 ( V_13 -> V_55 , V_13 -> V_55 -> V_13 . V_22 ) ;
F_46 ( V_13 -> V_55 ) ;
V_13 -> V_55 = V_54 ;
V_13 -> V_67 = F_57 ( V_93 -> V_67 ) ;
V_13 -> V_69 = F_57 ( V_93 -> V_69 ) ;
V_13 -> V_68 = V_38 ;
V_13 -> V_63 = V_63 ;
V_13 -> V_26 = V_93 -> V_26 ;
V_13 -> V_25 = V_93 -> V_25 ;
V_13 -> V_77 = V_93 -> V_77 ;
V_13 -> V_76 = V_93 -> V_76 ;
V_13 -> V_33 = V_93 -> V_33 ;
V_13 -> V_34 = V_93 -> V_34 ;
V_13 -> V_35 = V_93 -> V_34 ;
V_13 -> V_39 = V_38 ;
V_13 -> V_5 = 0 ;
V_13 -> V_32 = false ;
F_13 ( V_13 ) ;
F_15 ( 0 , V_13 ) ;
F_15 ( 1 , V_13 ) ;
F_58 ( V_53 ) ;
return 0 ;
}
static int F_59 ( struct V_52 * V_53 , struct V_88 * V_89 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
V_13 -> V_55 = & V_101 ;
return F_47 ( V_53 , V_89 ) ;
}
static int F_60 ( struct V_52 * V_53 , struct V_2 * V_3 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_88 * V_102 ;
struct V_92 V_89 = {
. V_67 = F_61 ( V_13 -> V_67 ) ,
. V_69 = F_61 ( V_13 -> V_69 ) ,
. V_63 = V_13 -> V_63 ,
. V_77 = V_13 -> V_77 ,
. V_76 = V_13 -> V_76 ,
. V_26 = V_13 -> V_26 ,
. V_25 = V_13 -> V_25 ,
. V_33 = V_13 -> V_33 ,
. V_34 = V_13 -> V_34 ,
} ;
V_53 -> V_103 . V_104 = V_13 -> V_55 -> V_103 . V_104 ;
V_102 = F_62 ( V_3 , V_105 ) ;
if ( V_102 == NULL )
goto V_106;
if ( F_63 ( V_3 , V_98 , sizeof( V_89 ) , & V_89 ) )
goto V_106;
return F_64 ( V_3 , V_102 ) ;
V_106:
F_65 ( V_3 , V_102 ) ;
return - V_107 ;
}
static int F_66 ( struct V_52 * V_53 , struct V_108 * V_109 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_110 V_111 = {
. V_81 = V_13 -> V_64 . V_81 ,
. V_79 = V_13 -> V_64 . V_79 ,
. V_78 = V_13 -> V_64 . V_78 ,
. V_65 = V_13 -> V_64 . V_65 ,
. V_83 = V_13 -> V_64 . V_83 ,
. V_82 = V_13 -> V_64 . V_82 ,
} ;
V_111 . V_112 = F_14 ( & V_111 . V_113 , & V_111 . V_114 , V_13 ) ;
return F_67 ( V_109 , & V_111 , sizeof( V_111 ) ) ;
}
static int F_68 ( struct V_52 * V_53 , unsigned long V_115 ,
struct V_2 * V_3 , struct V_116 * V_117 )
{
return - V_118 ;
}
static int F_69 ( struct V_52 * V_53 , unsigned long V_119 , struct V_52 * V_120 ,
struct V_52 * * V_121 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
if ( V_120 == NULL )
V_120 = & V_101 ;
F_55 ( V_53 ) ;
* V_121 = V_13 -> V_55 ;
V_13 -> V_55 = V_120 ;
F_56 ( * V_121 , ( * V_121 ) -> V_13 . V_22 ) ;
F_43 ( * V_121 ) ;
F_58 ( V_53 ) ;
return 0 ;
}
static struct V_52 * F_70 ( struct V_52 * V_53 , unsigned long V_119 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
return V_13 -> V_55 ;
}
static unsigned long F_71 ( struct V_52 * V_53 , T_1 V_51 )
{
return 1 ;
}
static void F_72 ( struct V_52 * V_53 , unsigned long V_119 )
{
}
static int F_73 ( struct V_52 * V_53 , T_1 V_51 , T_1 V_122 ,
struct V_88 * * V_123 , unsigned long * V_119 )
{
return - V_118 ;
}
static int F_74 ( struct V_52 * V_53 , unsigned long V_115 )
{
return - V_118 ;
}
static void F_75 ( struct V_52 * V_53 , struct V_124 * V_125 )
{
if ( ! V_125 -> V_126 ) {
if ( V_125 -> V_127 >= V_125 -> V_128 )
if ( V_125 -> V_129 ( V_53 , 1 , V_125 ) < 0 ) {
V_125 -> V_126 = 1 ;
return;
}
V_125 -> V_127 ++ ;
}
}
static struct V_40 T_2 * * F_76 ( struct V_52 * V_53 ,
unsigned long V_115 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
if ( V_115 )
return NULL ;
return & V_13 -> V_70 ;
}
static unsigned long F_77 ( struct V_52 * V_53 , unsigned long V_130 ,
T_1 V_51 )
{
return 0 ;
}
static int T_3 F_78 ( void )
{
return F_79 ( & V_131 ) ;
}
static void T_4 F_80 ( void )
{
F_81 ( & V_131 ) ;
}
